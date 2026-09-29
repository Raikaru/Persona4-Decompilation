"""Real ELF regression cases for independently addressed native zero storage."""
from __future__ import annotations

from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build
import gnu_link
from elf_text_runs import Section, Symbol, serialize


def words(*values):
    return struct.pack("<" + "I" * len(values), *values)


def fixture(directory, *, high=0x101040, low=0x101000, materialized=False,
            missing_reference=False, wrong_retail=False, short_retail=False,
            collision=False, outgoing_relocation=False, flags=0x10000003,
            alignment=4, overlap_data=False):
    """Two globals are referenced in reverse address order with a real gap."""
    body = words(0x3C040000, 0x24840000, 0x3C050000, 0x24A50000, 0x03E00008, 0)
    sections = [
        Section("", 0, align=0),
        Section(".symtab", 2, align=4, entsize=16, link=2),
        Section(".strtab", 3),
        Section(".shstrtab", 3),
        Section(".text", 1, 6, data=body, size=len(body), align=4),
        Section(".sbss", 1 if materialized else 8, flags,
                data=bytes(4) if materialized else b"", size=4, align=alignment),
        Section(".sbss", 1 if materialized else 8, flags,
                data=bytes(8) if materialized else b"", size=8, align=4),
    ]
    symbols = [Symbol("", 0, 0, 0, 0, 0),
               Symbol("high", 0, 4, 1, 0, 5),
               Symbol("low", 0, 8, 1, 0, 6),
               Symbol("unit", 0, len(body), 0x12, 0, 4)]
    references = [(0, 1, 5), (4, 1, 6)]
    if not missing_reference:
        references.extend([(8, 2, 5), (12, 2, 6)])
    rels = b"".join(words(offset, (symbol << 8) | kind) for offset, symbol, kind in references)
    sections.append(Section(".rel.text", 9, data=rels, size=len(rels),
                            align=4, entsize=8, link=1, info=4))
    if collision:
        sections.append(Section(".sbss.p4_5", 1))
    if outgoing_relocation:
        sections.append(Section(".rel.sbss", 9, data=words(0, (3 << 8) | 2),
                                size=8, align=4, entsize=8, link=1, info=5))
    if overlap_data:
        # An initialized variable cannot occupy an independently placed global.
        index = len(sections)
        sections.append(Section(".sdata", 1, 3, data=bytes(4), size=4, align=4))
        symbols.append(Symbol("overlap", 0, 4, 0x11, 0, index))
    raw = serialize(b"\x7fELF\x01\x01\x01" + bytes(9), 0x20924001,
                    sections, symbols, 1, 2, 3)
    path = Path(directory) / "unit.o"
    path.write_bytes(raw)
    obj = build.V.ObjectFile(path)
    actual = words(0x3C040000 | ((high + 0x8000) >> 16), 0x24840000 | (high & 0xFFFF),
                   0x3C050000 | ((low + 0x8000) >> 16), 0x24A50000 | (low & 0xFFFF),
                   0x03E00008, 0)
    memory = {0x100000: actual, high: b"\x01\0\0\0" if wrong_retail else bytes(4), low: bytes(8)}
    if short_retail:
        memory[high] = bytes(3)
    retail = mock.Mock()
    retail.bytes_at.side_effect = lambda address, size: memory[address][:size]
    return path, obj, [{"name": "unit", "addr": 0x100000}], retail


class IndependentBssTests(unittest.TestCase):
    def test_separate_native_globals_keep_their_addresses_and_leave_the_gap(self):
        with tempfile.TemporaryDirectory() as temporary:
            _path, obj, real, retail = fixture(temporary)
            self.assertEqual(build.plan_data_sections(obj, real, retail, 0, set()), (False, {}))
            self.assertEqual(build.plan_data_sections(obj, real, retail, 0, set(),
                                                      independent_literals=True), (False, {}))
            self.assertEqual(build.plan_data_sections(obj, real, retail, 0, set(), independent_bss=True),
                             (True, {".sbss.p4_5": (0x101040, 4), ".sbss.p4_6": (0x101000, 8)}))

    def test_unknown_nonzero_overlapping_or_relocated_storage_is_rejected(self):
        cases = [
            {"missing_reference": True}, {"wrong_retail": True}, {"short_retail": True},
            {"collision": True}, {"outgoing_relocation": True}, {"high": 0x101004},
            {"high": 0x101041}, {"flags": 2}, {"flags": 7}, {"alignment": 3},
            {"materialized": True},
        ]
        with tempfile.TemporaryDirectory() as temporary:
            for options in cases:
                with self.subTest(options=options):
                    _path, obj, real, retail = fixture(temporary, **options)
                    self.assertIsNone(build.independent_zero_storage(
                        obj, [obj.sh[5], obj.sh[6]], build.recover_section_bases(obj, real, retail, 0), retail))

    def test_overlap_with_a_different_storage_class_is_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            _path, obj, real, retail = fixture(temporary, overlap_data=True)
            bases = build.recover_section_bases(obj, real, retail, 0)
            bases[len(obj.sh) - 1] = 0x101040
            with mock.patch.object(build, "recover_section_bases", return_value=bases):
                self.assertEqual(build.plan_data_sections(obj, real, retail, 0, set(), independent_bss=True),
                                 (False, {}))

    def test_native_link_preparation_preserves_symbols_relocations_and_all_allocated_data(self):
        with tempfile.TemporaryDirectory() as temporary:
            path, obj, real, _retail = fixture(temporary, materialized=True)
            before_relocations = obj.function("unit")[1]
            owner = {"ranges": [(0x100000, 0x100020)], "funcs": real, "text_run_count": 1,
                     "sections": {".sbss.p4_5": (0x101040, 4), ".sbss.p4_6": (0x101000, 8)}}
            objects, entries = build.prepare_link_objects(path, owner, "gnu")
            after = build.V.ObjectFile(path)
            self.assertEqual(after.function("unit")[1], before_relocations)
            self.assertEqual(after.symbols, obj.symbols)
            self.assertEqual([(after.sh[i]["name"], after.sh[i]["size"], after.sh[i]["addralign"])
                              for i in (5, 6)], [(".sbss.p4_5", 4, 4), (".sbss.p4_6", 8, 4)])
            plan = gnu_link.validate_inputs(entries, objects, 0x100000, 0x2000)
            self.assertEqual(plan.functions, [("unit", 0x100000, 24)])
            self.assertFalse(plan.shared_literals)
            self.assertEqual(len(entries), 3)

    def test_link_preparation_rejects_storage_changed_after_proof(self):
        with tempfile.TemporaryDirectory() as temporary:
            for variant in ("nonzero", "nobits", "relocated"):
                with self.subTest(variant=variant):
                    path, obj, real, _retail = fixture(temporary, materialized=variant != "nobits",
                                                      outgoing_relocation=variant == "relocated")
                    if variant == "nonzero":
                        changed = bytearray(path.read_bytes())
                        changed[obj.sh[5]["offset"]] = 1
                        path.write_bytes(changed)
                    owner = {"ranges": [(0x100000, 0x100020)], "funcs": real,
                             "sections": {".sbss.p4_5": (0x101040, 4), ".sbss.p4_6": (0x101000, 8)}}
                    with self.assertRaisesRegex(ValueError, "shape changed"):
                        build.prepare_link_objects(path, owner, "gnu")


if __name__ == "__main__":
    unittest.main()
