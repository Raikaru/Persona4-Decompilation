from __future__ import annotations

import importlib.util
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest import mock

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "build.py"
SPEC = importlib.util.spec_from_file_location("p4_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(build)


class LinkResponseFileTests(unittest.TestCase):
    def test_link_uses_response_file_for_object_list(self) -> None:
        """Objects go through an @response file, sorted and de-duplicated.

        The link command line exceeds the Windows argument limit, so the object
        list must be written to slus21782.rsp and passed as @file instead.
        """
        entries = [
            (0x2000, Path("second object.o"), ".text"),
            (0x1000, Path("first.o"), ".text"),
            (0x3000, Path("first.o"), ".text"),
        ]
        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary)
            with mock.patch.object(build, "BUILD", output), mock.patch.object(build, "sh") as sh:
                build.link({"ld_exe": "mwldps2.exe"}, entries)
            sh.assert_called_once()
            command = sh.call_args.args[0]
            self.assertEqual(len(command), 2)
            self.assertEqual(command[0], "mwldps2.exe")
            self.assertTrue(command[1].startswith("@"))
            response = Path(command[1][1:]).read_text(encoding="utf-8")
            self.assertTrue(response.endswith(' first.o "second object.o"'))
            self.assertEqual(response.count("first.o"), 1)
            self.assertEqual(response.count("second object.o"), 1)


class ObjectLayoutTests(unittest.TestCase):
    """One `. = addr; obj (.text.<func>)` per function places each function
    individually, so any inter-function gap is expressible and zero-filled.
    Overlong bodies, overlapping windows and shared text sections are rejected.
    Non-contiguous windows require validated, separate contiguous-run objects.
    """

    def test_gap_no_alignment_can_express_is_now_placeable(self) -> None:
        """A 12-byte pad in front of a merely 4-aligned address used to be
        unreachable: alignment cannot manufacture an arbitrary gap, so the
        object-level `. = start; obj (.text)` scheme rejected it. Per-function
        placement puts the second function exactly on 0x106C and the linker
        zero-fills the pad.
        """
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x6C, 0x60, 2), (0x106C, 0x10, 0x8, 1)])
        )

    def test_overlong_function_is_rejected(self) -> None:
        self.assertFalse(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x28, 1), (0x1020, 0x30, 0x30, 2)])
        )

    def test_non_contiguous_windows_are_placeable_through_separate_runs(self) -> None:
        """Foreign windows remain outside the separate contiguous text runs."""
        rows = [(0x1000, 0x20, 0x20, 1), (0x1040, 0x30, 0x30, 2)]
        self.assertTrue(build.object_layout_is_placeable(rows))
        self.assertEqual(build.text_runs(rows), [[rows[0]], [rows[1]]])

    def test_two_functions_sharing_a_section_are_rejected(self) -> None:
        """rename_text_sections gives a whole .text section one name; two
        functions in one section cannot be split apart."""
        self.assertFalse(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x20, 1), (0x1020, 0x30, 0x30, 1)])
        )


class RenameTextSectionsTests(unittest.TestCase):
    """rename_text_sections rewrites .shstrtab and the section headers so each
    function's .text section gets a unique name and align 1."""

    @staticmethod
    def _two_function_object() -> bytes:
        """Minimal ELF32 REL: .text (idx 1), .symtab (idx 2), .strtab (idx 3),
        .shstrtab (idx 4); one global STT_FUNC symbol `foo` of size 8 in .text.
        """
        import struct as _struct

        text = b"\x01\x02\x03\x04\x05\x06\x07\x08"
        strtab = b"\0foo\0"
        shstrtab = b"\0.text\0.symtab\0.strtab\0.shstrtab\0"
        symtab = b"\0" * 16 + _struct.pack("<IIIBBH", 1, 0, 8, 0x12, 0, 1)
        text_off = 52
        strtab_off = text_off + len(text)
        shstrtab_off = strtab_off + len(strtab)
        symtab_off = shstrtab_off + len(shstrtab)
        shoff = symtab_off + len(symtab)
        headers = [
            (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),                     # null
            (1, 1, 0, 0, text_off, len(text), 0, 0, 16, 0),     # .text
            (7, 2, 0, 0, symtab_off, len(symtab), 3, 1, 4, 16),  # .symtab
            (15, 3, 0, 0, strtab_off, len(strtab), 0, 0, 1, 0),  # .strtab
            (23, 3, 0, 0, shstrtab_off, len(shstrtab), 0, 0, 1, 0),  # .shstrtab
        ]
        header = _struct.pack(
            "<16sHHIIIIIHHHHHH",
            b"\x7fELF" + bytes([1, 1, 1]) + b"\0" * 9, 1, 8, 1, 0, 0,
            shoff, 0, 52, 0, 0, 40, len(headers), 4,
        )
        return header + text + strtab + shstrtab + symtab + b"".join(
            _struct.pack("<IIIIIIIIII", *h) for h in headers
        )

    def test_renamed_function_remains_readable_with_identical_bytes(self) -> None:

        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "unit.o"
            path.write_bytes(self._two_function_object())
            build.rename_text_sections(path, {"foo": 0x1000})
            obj = build.V.ObjectFile(path)
        self.assertEqual(obj.sections[1]["name"], ".text.foo")
        self.assertEqual(obj.sections[1]["addralign"], 1)
        self.assertEqual(obj.function("foo")[0], b"\x01\x02\x03\x04\x05\x06\x07\x08")

    def test_unlisted_symbols_leave_the_object_untouched(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "unit.o"
            original = self._two_function_object()
            path.write_bytes(original)
            build.rename_text_sections(path, {"bar": 0x2000})
            self.assertEqual(path.read_bytes(), original)


class SectionLayoutTests(unittest.TestCase):
    def test_alignment_uses_absolute_addresses(self) -> None:
        sections = [
            {"idx": 5, "size": 12, "addralign": 8},
            {"idx": 7, "size": 9, "addralign": 8},
            {"idx": 8, "size": 16, "addralign": 16},
        ]
        recovered = {5: 0x005F1878, 7: 0x005F1888, 8: 0x005F18A0}
        self.assertEqual(
            build.recover_concatenated_layout(sections, recovered),
            (0x005F1878, [0, 16, 40], 56),
        )

    def test_rejects_inconsistent_recovered_addresses(self) -> None:
        sections = [
            {"idx": 1, "size": 8, "addralign": 8},
            {"idx": 2, "size": 8, "addralign": 16},
        ]
        self.assertIsNone(
            build.recover_concatenated_layout(
                sections,
                {1: 0x1008, 2: 0x1011},
            )
        )

    def test_local_jump_table_does_not_carve_the_following_retail_string(self) -> None:
        obj = mock.Mock(
            data=bytes(48),
            sh=[{"idx": 7, "name": ".rodata", "type": 1, "size": 48,
                 "offset": 0, "addralign": 16}],
            symbols=[{"name": "", "shndx": 7, "value": 0, "size": 0}],
        )
        obj.function.return_value = (
            (0x3C030000).to_bytes(4, "little") + (0x8C630000).to_bytes(4, "little"),
            [
                {"offset": 0, "r_type": 5, "symbol": "",
                 "target_section": 7, "target_value": 0},
                {"offset": 4, "r_type": 6, "symbol": "",
                 "target_section": 7, "target_value": 0},
            ],
        )
        retail = mock.Mock()
        retail.bytes_at.return_value = (
            (0x3C030076).to_bytes(4, "little") +
            (0x8C63ABA0).to_bytes(4, "little")
        )
        with mock.patch.object(
            build, "section_relocs",
            return_value=[(offset, 2, "") for offset in range(0, 40, 4)],
        ):
            self.assertEqual(
                build.plan_data_sections(
                    obj, [{"name": "host", "addr": 0x004E3FB0}], retail, 0, set()
                ),
                (True, {".rodata": (0x0075ABA0, 40)}),
            )

    def test_lcf_places_unaligned_functions_at_exact_addresses(self) -> None:
        entries = [
            (0x004C1000, Path("first.o"), ".text"),
            (0x004C1008, Path("second.o"), ".text"),
        ]
        self.assertEqual(
            build.lcf_placements(entries),
            [
                "        . = 0x004c1000;",
                "        first.o (.text)",
                "        . = 0x004c1008;",
                "        second.o (.text)",
            ],
        )


class LiteralRelocationTests(unittest.TestCase):
    def test_literal_immediate_does_not_hide_instruction_changes(self) -> None:
        relocations = [{"offset": 0, "r_type": 8}]
        retail = bytes.fromhex("248481c7")
        self.assertEqual(
            build.V.compare(bytes.fromhex("000081c7"), relocations, retail),
            (0, []),
        )
        self.assertEqual(
            build.V.compare(bytes.fromhex("000082cb"), relocations, retail),
            (2, [2, 3]),
        )

    def test_literal_pool_requires_consistent_placement_and_exact_data(self) -> None:
        pool = bytes.fromhex("0ad7233c0ad7a33c")
        obj = mock.Mock(
            data=pool,
            sh=[{"idx": 1, "name": ".lit4", "type": 1, "size": 8,
                 "offset": 0, "addralign": 4}],
            symbols=[
                {"name": "first", "shndx": 1, "value": 0},
                {"name": "second", "shndx": 1, "value": 4},
            ],
        )
        obj.function.return_value = (
            bytes.fromhex("000081c7000082c7"),
            [
                {"offset": 0, "r_type": 8, "symbol": "first"},
                {"offset": 4, "r_type": 8, "symbol": "second"},
            ],
        )
        retail = mock.Mock()
        memory = {0x100000: bytes.fromhex("00f181c704f182c7"), 0x4100: pool}
        retail.bytes_at.side_effect = lambda address, size: memory[address][:size]
        functions = [{"name": "load_literals", "addr": 0x100000}]
        self.assertEqual(
            build.plan_data_sections(obj, functions, retail, 0x5000, set()),
            (True, {".lit4": (0x4100, 8)}),
        )
        obj.data = bytes([pool[0] ^ 1]) + pool[1:]
        self.assertEqual(
            build.plan_data_sections(obj, functions, retail, 0x5000, set()),
            (False, {}),
        )


class IndependentRodataTests(unittest.TestCase):
    @staticmethod
    def _fixture(*, high_base=0x4040, low_base=0x4000, wrong_word=False,
                 missing_low_base=False, collision=False, ambiguous_local=False,
                 unsupported_reloc=False, duplicate_reloc=False, missing_reloc=False):
        import struct

        data = bytearray(64)
        struct.pack_into("<II", data, 0, 4, 12)   # local_target + nonzero addends
        struct.pack_into("<II", data, 8, 0, 8)    # ext_target + addends
        high_second = 0 if duplicate_reloc else 4
        high_type = 5 if unsupported_reloc else 2
        struct.pack_into("<II", data, 16, 0, (1 << 8) | high_type)
        struct.pack_into("<II", data, 24, high_second, (1 << 8) | 2)
        struct.pack_into("<II", data, 32, 0, (2 << 8) | 2)
        struct.pack_into("<II", data, 40, 4, (2 << 8) | 2)

        empty = lambda index: {"idx": index, "name": "", "type": 0, "flags": 0,
                               "size": 0, "offset": 0, "addralign": 1,
                               "entsize": 0, "info": 0, "link": 0}
        sh = [empty(index) for index in range(9)]
        sh[1] = {**empty(1), "name": ".symtab", "type": 2}
        sh[2] = {**empty(2), "name": ".text", "type": 1, "flags": 6,
                 "addralign": 16}
        sh[3] = {**empty(3), "name": ".rodata", "type": 1, "flags": 2,
                 "size": 8, "offset": 0, "addralign": 16}
        sh[4] = {**empty(4), "name": ".rel.rodata", "type": 9,
                 "size": 8 if missing_reloc else 16,
                 "offset": 16, "addralign": 4, "entsize": 8, "info": 3, "link": 1}
        if collision:
            sh[5] = {**empty(5), "name": ".rodata.p4_3", "type": 1}
        sh[7] = {**empty(7), "name": ".rodata", "type": 1, "flags": 2,
                 "size": 8, "offset": 8, "addralign": 16}
        sh[8] = {**empty(8), "name": ".rel.rodata.2", "type": 9, "size": 16,
                 "offset": 32, "addralign": 4, "entsize": 8, "info": 7, "link": 1}

        null = {"name": "", "shndx": 0, "value": 0, "size": 0, "info": 0}
        local_target = {"name": "local_target", "shndx": 2, "value": 0,
                        "size": 4, "info": 0x12}
        external_target = {"name": "ext_target", "shndx": 0, "value": 0,
                           "size": 0, "info": 0x10}
        table_high = {"name": "@high", "shndx": 3, "value": 0, "size": 8, "info": 1}
        table_low = {"name": "@low", "shndx": 7, "value": 0, "size": 8, "info": 1}
        obj = mock.Mock()
        obj.data = bytes(data)
        obj.sh = sh
        obj.sections = sh
        obj.symtabs = {1: [null, local_target, external_target]}
        obj.symbols = [null, local_target, external_target, table_high, table_low]

        def reference(symbol, base):
            body = struct.pack("<II", 0, 0)
            relocations = [
                {"offset": 0, "r_type": 5, "symbol": symbol},
                {"offset": 4, "r_type": 6, "symbol": symbol},
            ]
            retail_body = struct.pack("<II", (base >> 16) & 0xFFFF, base & 0xFFFF)
            return body, relocations, retail_body

        high_body, high_relocs, retail_high_ref = reference("@high", high_base)
        low_body, low_relocs, retail_low_ref = reference("@low", low_base)
        if missing_low_base:
            low_relocs = []
            retail_low_ref = low_body
        functions = {
            "ref_high": (high_body, high_relocs),
            "ref_low": (low_body, low_relocs),
            "local_target": (b"", []),
        }
        obj.function.side_effect = lambda name: functions[name]
        real = [
            {"name": "ref_high", "addr": 0x1000},
            {"name": "ref_low", "addr": 0x1100},
            {"name": "local_target", "addr": 0x1200},
        ]
        if ambiguous_local:
            real.append({"name": "local_target", "addr": 0x1300})
        high_payload = struct.pack("<II", 0x1204, 0x120C)
        if wrong_word:
            high_payload = struct.pack("<II", 0x1204, 0x1210)
        memory = {
            0x1000: retail_high_ref,
            0x1100: retail_low_ref,
            0x1200: b"",
            0x1300: b"",
            high_base: high_payload,
            low_base: struct.pack("<II", 0x2200, 0x2208),
        }
        retail = mock.Mock()
        retail.bytes_at.side_effect = lambda address, size: memory[address][:size]
        return obj, real, retail

    def test_gapped_reversed_rodata_tables_are_independently_proven(self) -> None:
        obj, real, retail = self._fixture()
        self.assertEqual(
            build.plan_data_sections(obj, real, retail, 0x5000, {"ext_target"}),
            (False, {}),
        )
        self.assertEqual(
            build.plan_data_sections(obj, real, retail, 0x5000, {"ext_target"},
                                     independent_literals=True),
            (False, {}),
        )
        self.assertEqual(
            build.plan_data_sections(
                obj, real, retail, 0x5000, {"ext_target"}, independent_rodata=True,
                symbol_addresses={"ext_target": 0x2200}),
            (True, {".rodata.p4_3": (0x4040, 8), ".rodata.p4_7": (0x4000, 8)}),
        )

    def test_independent_rodata_rejects_unproven_or_conflicting_tables(self) -> None:
        cases = [
            ("wrong word", {"wrong_word": True}, {"ext_target": 0x2200}),
            ("unknown external", {}, {}),
            ("rename collision", {"collision": True}, {"ext_target": 0x2200}),
            ("overlap", {"high_base": 0x4000, "low_base": 0x4000}, {"ext_target": 0x2200}),
            ("ambiguous local", {"ambiguous_local": True}, {"ext_target": 0x2200}),
            ("conflicting local map", {}, {"ext_target": 0x2200, "local_target": 0x1300}),
            ("unsupported relocation", {"unsupported_reloc": True}, {"ext_target": 0x2200}),
            ("duplicate relocation", {"duplicate_reloc": True}, {"ext_target": 0x2200}),
            ("missing relocation", {"missing_reloc": True}, {"ext_target": 0x2200}),
        ]
        for label, fixture_options, addresses in cases:
            with self.subTest(label=label):
                obj, real, retail = self._fixture(**fixture_options)
                self.assertEqual(
                    build.plan_data_sections(
                        obj, real, retail, 0x5000, set(addresses), independent_rodata=True,
                        symbol_addresses=addresses),
                    (False, {}),
                )

        obj, real, retail = self._fixture(missing_low_base=True)
        with mock.patch.object(build, "recover_concatenated_layout", return_value=None):
            self.assertEqual(
                build.plan_data_sections(
                    obj, real, retail, 0x5000, {"ext_target"}, independent_rodata=True,
                    symbol_addresses={"ext_target": 0x2200}),
                (False, {}),
            )

    def test_prepare_link_objects_only_renames_validated_rodata_shape(self) -> None:
        obj, _real, _retail = self._fixture()
        owner = {"ranges": [], "funcs": [], "sections": {".rodata.p4_3": (0x4040, 8)},
                 "text_run_count": 1}
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "unit.o"
            path.write_bytes(b"native")
            renamed = []
            with (
                mock.patch.object(build, "rename_text_sections"),
                mock.patch.object(build, "rename_sections",
                                  side_effect=lambda _path, names, **_kwargs: renamed.append(names)),
                mock.patch.object(build.V, "ObjectFile", return_value=obj),
            ):
                objects, entries = build.prepare_link_objects(path, owner, "gnu")
        self.assertEqual(objects, [path])
        self.assertEqual(entries, [(0x4040, path, ".rodata.p4_3")])
        self.assertEqual(renamed, [{3: ".rodata.p4_3"}])

        obj.sh[4]["type"] = 4
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "unit.o"
            path.write_bytes(b"native")
            with (
                mock.patch.object(build, "rename_text_sections"),
                mock.patch.object(build, "rename_sections"),
                mock.patch.object(build.V, "ObjectFile", return_value=obj),
            ):
                with self.assertRaisesRegex(ValueError, "shape changed"):
                    build.prepare_link_objects(path, owner, "gnu")


class MissingDefinitionTests(unittest.TestCase):
    def test_audited_fallback_relocation_resolves_after_c_name_migration(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir()
            (root / "config" / "symbol_addrs.txt").write_text(
                "btlLevelFromExp = 0x001059E0; // type:func\n"
            )
            with mock.patch.object(build, "REPO", root):
                addresses = build.load_symbol_addr_map()
            definitions = {}
            build.complete_missing_definitions(
                definitions,
                unresolved={"func_001059e0"},
                exported={"btlLevelFromExp"},
                addresses=addresses,
            )
            self.assertEqual(definitions, {"func_001059e0": 0x001059E0})

    def test_defines_only_referenced_unexported_known_symbols(self) -> None:
        definitions = {"already_defined": 0x1000}
        build.complete_missing_definitions(
            definitions,
            unresolved={"already_defined", "exported", "missing", "unknown"},
            exported={"exported"},
            addresses={
                "already_defined": 0x9000,
                "exported": 0x2000,
                "missing": 0x3000,
                "not_referenced": 0x4000,
            },
        )
        self.assertEqual(
            definitions,
            {
                "already_defined": 0x1000,
                "missing": 0x3000,
            },
        )

    def test_only_external_bindings_satisfy_references_from_other_objects(self) -> None:
        import struct
        from gen_objdiff import build_elf_object

        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "helper.o"
            for binding in (0, 1, 2):  # STB_LOCAL, STB_GLOBAL, STB_WEAK
                with self.subTest(binding=binding):
                    data = bytearray(build_elf_object(
                        b"\x08\x00\xe0\x03\0\0\0\0", [], "helper", 0))
                    path.write_bytes(data)
                    obj = build.V.ObjectFile(path)
                    table = next(s for s in obj.sh if s["name"] == ".symtab")
                    index = next(i for i, s in enumerate(obj.symbols) if s["name"] == "helper")
                    data[table["offset"] + index * 16 + 12] = (binding << 4) | 2
                    shoff = struct.unpack_from("<I", data, 32)[0]
                    struct.pack_into("<I", data, shoff + table["idx"] * 40 + 28,
                                     2 if binding == 0 else 1)
                    path.write_bytes(data)
                    definitions = {}
                    build.complete_missing_definitions(
                        definitions, {"helper"}, build.c_object_exports(path),
                        {"helper": 0x1000})
                    self.assertEqual(definitions, {"helper": 0x1000} if binding == 0 else {})


class SourceAliasTests(unittest.TestCase):
    def test_source_name_resolves_to_existing_numeric_fallback(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir()
            (root / "src/generated").mkdir(parents=True)
            (root / "config/symbol_addrs.txt").write_text(
                "func_00100000 = 0x00100000; // type:func\n")
            (root / "src/provider.c").write_text(
                "// FUN_00100000\nvoid NamedProvider(void) {}\n")
            (root / "src/generated/stale.c").write_text(
                "// FUN_00200000\nvoid NamedProvider(void) {}\n")
            with mock.patch.object(build, "REPO", root):
                addresses = build.load_symbol_addr_map()
                self.assertEqual(build.source_marker_names(), {"NamedProvider"})
            self.assertEqual(addresses,
                {"func_00100000": 0x100000, "NamedProvider": 0x100000})
            definitions = {}
            build.complete_missing_definitions(definitions,
                {"NamedProvider", "UnknownProvider"}, {"func_00100000"}, addresses)
            self.assertEqual(definitions, {"NamedProvider": 0x100000})
            definitions = {}
            build.complete_missing_definitions(definitions,
                {"NamedProvider"}, {"NamedProvider"}, addresses)
            self.assertEqual(definitions, {})

    def test_source_alias_cannot_override_a_conflicting_configured_address(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir()
            (root / "src").mkdir()
            (root / "config/symbol_addrs.txt").write_text(
                "NamedProvider = 0x00200000; // type:func\n")
            (root / "src/provider.c").write_text(
                "// FUN_00100000\nvoid NamedProvider(void) {}\n")
            with mock.patch.object(build, "REPO", root):
                with self.assertRaisesRegex(ValueError, "disagreement for NamedProvider"):
                    build.load_symbol_addr_map()

    def test_ambiguous_source_name_is_not_given_an_arbitrary_address(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/first.c").write_text(
                "// FUN_00100000\nvoid NamedProvider(void) {}\n")
            (root / "src/second.c").write_text(
                "// FUN_00200000\nvoid NamedProvider(void) {}\n")
            with mock.patch.object(build, "REPO", root):
                self.assertEqual(build.source_marker_names(), {"NamedProvider"})
                self.assertEqual(build.source_marker_addresses(), {})
                self.assertEqual(build.load_symbol_addr_map(), {})
            definitions = {}
            build.complete_missing_definitions(definitions, {"NamedProvider"}, set(), {})
            self.assertEqual(definitions, {})


class CompileCacheIntegrationTests(unittest.TestCase):
    def test_link_compile_is_restored_without_running_mwccgap(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "unit.c"
            output = root / "build" / "obj" / "unit.o"
            compiler = root / "mwcc.exe"
            assembler = root / "as.exe"
            objcopy = root / "objcopy.exe"
            macro = root / "asm" / "macro.inc"
            for path, content in (
                (source, b"int unit(void) { return 1; }\\n"),
                (compiler, b"mwcc"),
                (assembler, b"assembler"),
                (objcopy, b"objcopy"),
                (macro, b".macro dummy\\n.endm\\n"),
            ):
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(content)
            config = {
                "mwcc": str(compiler),
                "cflags": ["-O2"],
                "compile_flags": ["-O2", "-Iinclude"],
            }
            invocations = []

            def fake_sh(command, **_kwargs):
                invocations.append(command)
                Path(command[3]).write_bytes(b"linked-object")
                return ""

            patches = (
                mock.patch.object(build, "REPO", root),
                mock.patch.object(build, "ASM", root / "asm"),
                mock.patch.object(build, "AS_TOOL", build.A.Tool((str(assembler),))),
                mock.patch.object(build, "OBJCOPY_TOOL", build.A.Tool((str(objcopy),))),
                mock.patch.object(build, "CACHE_TOOL_VERSIONS", {"assembler": "v1", "objcopy": "v1"}),
                mock.patch.object(build, "sh", fake_sh),
                mock.patch.object(build, "progbitsify", lambda _path: None),
            )
            with patches[0], patches[1], patches[2], patches[3], patches[4], patches[5], patches[6]:
                first = build.BC.ObjectCache(root / "build" / "cache" / "c", root)
                build.compile_c(config, source, output, first)
                output.unlink()
                second = build.BC.ObjectCache(root / "build" / "cache" / "c", root)
                build.compile_c(config, source, output, second)

            self.assertEqual(len(invocations), 1)
            self.assertEqual(output.read_bytes(), b"linked-object")


class SonySdkLinkingTests(unittest.TestCase):
    """Sony SDK code is linked as retail-backed black-box objects."""

    def test_pure_sdk_source_exclusion(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            cpath = Path(temporary) / "pure_sdk.c"
            cpath.write_text("// FUN_004213c0\nvoid RFU000_FullReset(void) {}\n")
            self.assertTrue(build.is_pure_sdk_source(cpath))

            mixed_path = Path(temporary) / "mixed.c"
            mixed_path.write_text(
                "// FUN_004213c0\nvoid RFU000_FullReset(void) {}\n"
                "// FUN_001014b0\nvoid game_func(void) {}\n"
            )
            self.assertFalse(build.is_pure_sdk_source(mixed_path))


class CarvedCodeBuildTests(unittest.TestCase):
    @staticmethod
    def _instruction(address: int) -> str:
        return f"    /* {address - 0x1000:06X} {address:08X} 00000000 */ nop\n"

    def test_carves_interval_union_across_partial_blocks_and_boundaries(self) -> None:
        """Overlapping/nested ranges carve their union while gaps and exact end
        boundaries remain in the same chunk indices defined by range starts.

        The zero-length range at 0x1038 does not carve its address, but it still
        advances the chunk index, preserving the existing placement convention.
        """
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            asm_dir = root / "asm"
            obj_dir = root / "obj"
            asm_dir.mkdir()
            obj_dir.mkdir()
            image = root / "image.bin"
            image.write_bytes(b"\0" * 0x100)
            source = asm_dir / "code_probe.s"
            source.write_text(
                ".section .text\n"
                ".set noreorder\n"
                "nonmatching probe\n"
                "glabel probe\n"
                + self._instruction(0x100C)
                + "leaked_label:\n"
                + self._instruction(0x1010)
                + self._instruction(0x101C)
                + self._instruction(0x102F)
                + "gap_label:\n"
                + self._instruction(0x1030)
                + self._instruction(0x1038)
                + self._instruction(0x103C)
                + self._instruction(0x1040)
                + self._instruction(0x104F)
                + self._instruction(0x1050)
                + "endlabel probe\n"
            )
            owner = {
                "ranges": [
                    (0x1010, 0x1014),       # nested, duplicate start
                    (0x1010, 0x1020),
                    (0x1018, 0x1030),       # overlapping continuation
                    (0x1038, 0x1038),       # zero length
                    (0x1040, 0x1050),
                ]
            }
            assembled = {}

            def fake_assemble(path, obj, *_args, **_kwargs):
                lines = path.read_text().splitlines(keepends=True)
                assembled[path.name] = "".join(lines)
                obj.write_bytes(b"object")
                return True, "", lines

            entries = []
            with (
                mock.patch.object(build, "ASM", asm_dir),
                mock.patch.object(build, "OBJ", obj_dir),
                mock.patch.object(build, "IMAGE", image),
                mock.patch.object(build, "VRAM", 0x1000),
                mock.patch.object(build.V, "code_origin", return_value="main"),
                mock.patch.object(build, "build_sony_sdk_objects", return_value=[]),
                mock.patch.object(build.A, "assemble", side_effect=fake_assemble),
                mock.patch.object(build, "patch_align1"),
            ):
                result = build.build_code_carved({}, "code_probe", 0, 0x100, [owner], entries, {})

            self.assertEqual(result, [])
            self.assertEqual([address for address, _obj, _section in entries],
                             [0x100C, 0x1030, 0x1038, 0x1050])
            self.assertEqual(sorted(assembled),
                             ["code_probe_0.s", "code_probe_3.s", "code_probe_4.s", "code_probe_5.s"])
            retained = []
            for text in assembled.values():
                retained.extend(int(match.group(1), 16) for match in build.BYTES_RE.finditer(text))
            self.assertEqual(sorted(retained), [0x100C, 0x1030, 0x1038, 0x103C, 0x1050])
            self.assertNotIn("leaked_label:", "".join(assembled.values()))
            self.assertIn("gap_label:", assembled["code_probe_3.s"])
            self.assertIn("endlabel probe", assembled["code_probe_5.s"])

    def test_sdk_overlap_with_c_range_is_still_rejected(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            asm_dir = root / "asm"
            asm_dir.mkdir()
            (asm_dir / "code_probe.s").write_text(
                "nonmatching probe\n" + self._instruction(0x1010)
            )
            sdk_objects = [{"start": 0x1018, "end": 0x1028, "funcs": []}]
            owner = {"ranges": [(0x1010, 0x1020)]}
            with (
                mock.patch.object(build, "ASM", asm_dir),
                mock.patch.object(build, "VRAM", 0x1000),
                mock.patch.object(build.V, "code_origin", return_value="main"),
                mock.patch.object(build, "build_sony_sdk_objects", return_value=sdk_objects),
            ):
                with self.assertRaisesRegex(ValueError, "overlaps a linked C object"):
                    build.build_code_carved({}, "code_probe", 0, 0x100, [owner], [], {})

if __name__ == "__main__":
    unittest.main()
