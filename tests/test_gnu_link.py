"""GNU backend regressions; fixtures never require a proprietary compiler."""
from __future__ import annotations

from dataclasses import replace
import json
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest
from unittest import mock

from test_build import build
from test_elf_text_runs import fixture
from elf_text_runs import (ABS, ALLOC, EXEC, FUNC, GLOBAL, OBJECT, PROGBITS, REL, STRTAB,
                           SYMTAB, Elf32, Section, SplitError, Symbol, serialize,
                           validate_whole_object)

G = build.G


def owner_for(placements, bases, raw):
    elf = Elf32(raw)
    return {"src": build.REPO / "src/fixture.c", "text_run_count": 2,
            "ranges": [(p.address, p.address + p.window) for p in placements],
            "funcs": [{"name": p.name, "addr": p.address} for p in placements],
            "sections": {elf.sections[index].name: (address, elf.sections[index].size)
                         for index, address in bases.items()}}


class WholeObjectTests(unittest.TestCase):
    def test_gapped_literal_stays_local_with_original_bytes_and_relocations(self):
        raw, placements, bases = fixture(literal_kind=8)
        before = Elf32(raw)
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "owner.o"
            path.write_bytes(raw)
            owner = owner_for(placements, bases, raw)
            objects, entries = build.prepare_link_objects(path, owner, "gnu")
            after = Elf32(path.read_bytes())
            self.assertEqual(objects, [path])
            self.assertEqual(owner["private_bridges"], [])
            self.assertEqual([address for address, _, section in entries if section.startswith(".text.")],
                             [0x100000, 0x100020, 0x100060])
        self.assertEqual(before.symbols, after.symbols)
        self.assertEqual(before.flags, after.flags)
        for index, section in enumerate(before.sections):
            if index == before.shstrtab:
                continue
            self.assertEqual(section.data, after.sections[index].data)
            self.assertEqual((section.type, section.flags, section.link, section.info),
                             (after.sections[index].type, after.sections[index].flags,
                              after.sections[index].link, after.sections[index].info))

    def test_whole_validation_retains_structural_and_relocation_rejections(self):
        raw, placements, _ = fixture(literal_kind=8)
        validate_whole_object(raw, placements)
        with self.assertRaisesRegex(SplitError, "Unowned emitted text"):
            validate_whole_object(raw, placements[:-1])
        with self.assertRaisesRegex(SplitError, "overlong"):
            validate_whole_object(raw, [replace(placements[0], window=4), *placements[1:]])
        bad, places, _ = fixture(literal_kind=9)
        with self.assertRaisesRegex(SplitError, "Unsupported native MIPS relocation 9"):
            validate_whole_object(bad, places)

    def test_gap_eligibility_preserves_mixed_owners_and_function_origins(self):
        raw, placements, _ = fixture(literal_kind=8)
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            source = root / "src/fixture.c"
            source.write_text("/* fixture */\n")
            path = root / "fixture.o"
            path.write_bytes(raw)
            obj = build.V.ObjectFile(path)
            markers = [{"name": p.name, "addr": p.address, "stub": False,
                        "nonmatching": False, "asm": False} for p in placements]
            retail = mock.Mock()
            body_by_address = {p.address: obj.function(p.name)[0].ljust(p.window, b"\0") for p in placements}
            retail.bytes_at.side_effect = lambda address, window: body_by_address[address][:window]
            for backend, origins, expected in (
                    ("gnu", ("main", "main", "main"), 1),
                    ("gnu", ("renderware", "renderware", "renderware"), 0),
                    ("gnu", ("main", "renderware", "main"), 1),
                    ("mwld", ("main", "main", "main"), 0),
                    ("mwld", ("main", "renderware", "main"), 0)):
                by_address = {p.address: origin for p, origin in zip(placements, origins)}
                with self.subTest(backend=backend, origins=origins), \
                        mock.patch.object(build, "REPO", root), \
                        mock.patch.object(build, "is_pure_sdk_source", return_value=False), \
                        mock.patch.object(build.V, "is_gcc_unit", return_value=False), \
                        mock.patch.object(build.V, "scan_markers", return_value=markers), \
                        mock.patch.object(build.V, "RetailElf", return_value=retail), \
                        mock.patch.object(build.V, "code_origin", side_effect=lambda source, address: by_address[address]), \
                        mock.patch.object(build, "compile_eligibility", return_value=obj), \
                        mock.patch.object(build, "plan_data_sections", return_value=(True, {})) as planner:
                    rows = build.eligible_c_objects({"retail_elf": "fixture", "linker_backend": backend},
                        set(), [0x100000, 0x100020, 0x100030, 0x100060, 0x100070], 0x109000, None)
                    self.assertEqual(len(rows), expected)
                    if expected:
                        planner.assert_called_once()
                        self.assertTrue(planner.call_args.kwargs["independent_literals"])
                        records = build.linked_function_records(rows, by_address)
                        self.assertEqual({int(row["address"], 16): row["origin"] for row in records},
                                         by_address)


def reversed_literal_fixture():
    """Two native local pools whose recovered addresses reverse object order."""
    code = struct.pack('<4I', 0xc7800000, 0xc7810000, 0x03e00008, 0)
    sections = [Section('', 0, align=0), Section('.symtab', SYMTAB),
                Section('.strtab', STRTAB), Section('.shstrtab', STRTAB),
                Section('.text', PROGBITS, ALLOC | EXEC, data=code, size=16, align=16),
                Section('.lit4', PROGBITS, ALLOC, data=struct.pack('<f', 1.0), size=4, align=4),
                Section('.lit4', PROGBITS, ALLOC, data=struct.pack('<f', 2.0), size=4, align=4),
                Section('.rel.text', REL, data=struct.pack('<4I', 0, (1 << 8) | 8,
                        4, (2 << 8) | 8), size=16, link=1, info=4, align=4, entsize=8)]
    symbols = [Symbol('', 0, 0, 0, 0, 0), Symbol('one', 0, 4, OBJECT, 0, 5),
               Symbol('two', 0, 4, OBJECT, 0, 6), Symbol('load_literals', 0, 16, GLOBAL << 4 | FUNC, 0, 4)]
    raw = serialize(b'\x7fELF\x01\x01\x01' + b'\0' * 9, 0x20924001,
                    sections, symbols, 1, 2, 3)
    memory = {0x100000: struct.pack('<4I', 0xc780f004, 0xc781f000, 0x03e00008, 0),
              0x1004: struct.pack('<f', 1.0), 0x1000: struct.pack('<f', 2.0)}
    retail = mock.Mock()
    retail.bytes_at.side_effect = lambda address, size: memory.get(address, bytes(size))[:size]
    return raw, retail


class LiteralPlacementTests(unittest.TestCase):
    def test_reverse_order_pools_are_placed_without_changing_local_references(self):
        raw, retail = reversed_literal_fixture()
        markers = [{'name': 'load_literals', 'addr': 0x100000}]
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / 'owner.o'
            path.write_bytes(raw)
            obj = build.V.ObjectFile(path)
            self.assertEqual(build.plan_data_sections(obj, markers, retail, 0x2000, set()), (False, {}))
            ok, sections = build.plan_data_sections(obj, markers, retail, 0x2000, set(),
                                                   independent_literals=True)
            self.assertTrue(ok)
            self.assertEqual(sections, {'.lit4.p4_5': (0x1004, 4), '.lit4.p4_6': (0x1000, 4)})
            owner = {'src': build.REPO / 'src/fixture.c', 'text_run_count': 1,
                     'ranges': [(0x100000, 0x100010)], 'funcs': markers, 'sections': sections}
            objects, entries = build.prepare_link_objects(path, owner, 'gnu')
            self.assertEqual(objects, [path])
            self.assertEqual(sorted((address, name) for address, _, name in entries),
                             [(0x1000, '.lit4.p4_6'), (0x1004, '.lit4.p4_5'),
                              (0x100000, '.text.load_literals')])
            before, after = Elf32(raw), Elf32(path.read_bytes())
            self.assertEqual(before.symbols, after.symbols)
            for index, section in enumerate(before.sections):
                if index == before.shstrtab:
                    continue
                self.assertEqual(section.data, after.sections[index].data)
                self.assertEqual((section.flags, section.type, section.link, section.info),
                                 (after.sections[index].flags, after.sections[index].type,
                                  after.sections[index].link, after.sections[index].info))
            self.assertEqual([after.sections[i].align for i in (5, 6)], [4, 4])

    def test_individual_literal_placement_still_rejects_wrong_payload(self):
        raw, retail = reversed_literal_fixture()
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / 'wrong.o'
            path.write_bytes(raw)
            obj = build.V.ObjectFile(path)
            changed = bytearray(raw)
            changed[obj.sections[5]['offset']] ^= 1
            path.write_bytes(changed)
            self.assertEqual(build.plan_data_sections(build.V.ObjectFile(path),
                [{'name': 'load_literals', 'addr': 0x100000}], retail, 0x2000, set(),
                independent_literals=True), (False, {}))

    def test_literal_plan_cannot_select_a_different_section_after_compilation(self):
        raw, _retail = reversed_literal_fixture()
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / 'wrong-index.o'
            path.write_bytes(raw)
            owner = {'src': build.REPO / 'src/fixture.c', 'text_run_count': 1,
                     'ranges': [(0x100000, 0x100010)],
                     'funcs': [{'name': 'load_literals', 'addr': 0x100000}],
                     'sections': {'.lit4.p4_4': (0x1000, 16)}}
            with self.assertRaisesRegex(ValueError, 'Literal section layout changed'):
                build.prepare_link_objects(path, owner, 'gnu')


class ConfigurationAndScriptTests(unittest.TestCase):
    def test_backend_default_config_and_environment_are_explicit(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "tools").mkdir()
            with mock.patch.object(build, "REPO", root), mock.patch.dict(build.os.environ, {}, clear=True):
                self.assertEqual(build.cfg()["linker_backend"], "mwld")
                (root / "tools/build_config.json").write_text(json.dumps({"linker_backend": "gnu"}))
                self.assertEqual(build.cfg()["linker_backend"], "gnu")
                with mock.patch.dict(build.os.environ, {"P4_LINKER_BACKEND": "mwld"}):
                    self.assertEqual(build.cfg()["linker_backend"], "mwld")
                with mock.patch.dict(build.os.environ, {"P4_LINKER_BACKEND": "unknown"}):
                    with self.assertRaisesRegex(SystemExit, "must be mwld or gnu"):
                        build.cfg()

    def test_repository_default_selects_gnu_without_local_configuration(self):
        committed = json.loads((build.REPO / "tools/build_config.json").read_text())
        self.assertEqual(committed["linker_backend"], "gnu")
        self.assertIsNone(committed["mwcc"])
        self.assertIsNone(committed["ld_exe"])

    def test_script_uses_section_offsets_and_fallback_definitions(self):
        path = Path("owner with spaces.o").resolve()
        script = G.render_script([(0x100020, path, ".text.second"), (0x100000, path, ".text.first")],
            {path: "/mnt/c/project/owner with spaces.o"}, 0x100000, 0x100, "first", 0x7690f0,
            {"first": 0x100000, "external": 0x101000})
        self.assertIn("PROVIDE(first = 0x00100000);", script)
        self.assertIn("_gp = 0x007690f0;", script)
        self.assertIn(". = 0x20;", script)
        self.assertNotIn(". = 0x100020;", script)
        self.assertEqual(script.count('"/mnt/c/project/owner with spaces.o"'), 2)
        self.assertIn("ASSERT(SIZEOF(.image)", script)

    def test_wsl_maps_one_common_path_using_the_selected_distribution(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            paths = [root / "objects/one.o", root / "objects/two with spaces.o", root / "build/link.rsp"]
            tool = build.A.Tool(("wsl", "-d", "SelectedDistro", "--", "mipsel-linux-gnu-ld"), True)
            result = subprocess.CompletedProcess([], 0, "/mnt/c/project\n")
            with mock.patch.object(G.subprocess, "run", return_value=result) as run:
                mapped = G.map_paths(tool, paths)
            run.assert_called_once()
            self.assertEqual(run.call_args.args[0][:4], ["wsl", "-d", "SelectedDistro", "--"])
            self.assertEqual(mapped[paths[1].resolve()], "/mnt/c/project/objects/two with spaces.o")
            self.assertEqual(mapped[paths[2].resolve()], "/mnt/c/project/build/link.rsp")

    def test_response_quoting_preserves_spaces_quotes_and_backslashes(self):
        self.assertEqual(G.quote('a b"c\\d'), '"a b\\"c\\\\d"')
        with self.assertRaises(ValueError):
            G.quote("first\nsecond")

    def test_link_keeps_large_input_list_in_one_response_file(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            objects = [root / (f"unit {index:03d} " + "x" * 150 + ".o") for index in range(80)]
            entries = [(0x100000 + index * 16, path, ".text.fn") for index, path in enumerate(objects)]
            with mock.patch.object(G, "validate_inputs", return_value=G.InputPlan([], {"fn", "native_data"})), \
                    mock.patch.object(G, "validate_output"), \
                    mock.patch.object(G.subprocess, "run", return_value=subprocess.CompletedProcess([], 0, "")) as run:
                G.link(build.A.Tool(("mipsel-linux-gnu-ld",)), entries, objects, root,
                       0x100000, 0x1000, "fn", 0x100000, 0x7690f0,
                       {"fn": 0x100000, "native_data": 0x100008, "fallback": 0x100010})
            command = run.call_args.args[0]
            self.assertEqual(len(command), 2)
            self.assertEqual(command[0], "mipsel-linux-gnu-ld")
            self.assertTrue(command[1].startswith("@"))
            response = Path(command[1][1:]).read_text()
            self.assertGreater(len(response), 8192)
            self.assertEqual(response.count(G.quote(objects[0].as_posix())), 1)
            script = (root / "slus21782.ld").read_text()
            self.assertNotIn("PROVIDE(fn =", script)
            self.assertNotIn("PROVIDE(native_data =", script)
            self.assertIn("PROVIDE(fallback =", script)

    def test_unplaced_or_overlapping_allocations_fail_before_linking(self):
        raw, placements, bases = fixture(literal_kind=8)
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "owner.o"
            path.write_bytes(raw)
            objects, entries = build.prepare_link_objects(path, owner_for(placements, bases, raw), "gnu")
            self.assertEqual(len(G.validate_inputs(entries, objects, 0x100000, 0x2000).functions), 3)
            with self.assertRaisesRegex(ValueError, "Unplaced allocated"):
                G.validate_inputs(entries[:-1], objects, 0x100000, 0x2000)
            with self.assertRaisesRegex(ValueError, "overlapping|Duplicate"):
                G.validate_inputs(entries + entries[:1], objects, 0x100000, 0x2000)


def executable_fixture() -> bytes:
    sections = [Section("", 0, align=0), Section(".symtab", SYMTAB),
                Section(".strtab", STRTAB), Section(".shstrtab", STRTAB),
                Section(".image", PROGBITS, ALLOC | EXEC, addr=0x100000, data=b"\0" * 8, size=8)]
    symbols = [Symbol("", 0, 0, 0, 0, 0), Symbol("first", 0x100000, 8, GLOBAL << 4 | FUNC, 0, 4),
               Symbol("_gp", 0x7690f0, 0, GLOBAL << 4, 0, ABS)]
    raw = bytearray(serialize(b"\x7fELF\x01\x01\x01" + b"\0" * 9, 0x20924001, sections, symbols, 1, 2, 3))
    shoff = struct.unpack_from("<I", raw, 32)[0]
    image_offset = struct.unpack_from("<I", raw, shoff + 4 * 40 + 16)[0]
    struct.pack_into("<H", raw, 16, 2)
    struct.pack_into("<II", raw, 24, 0x100000, len(raw))
    struct.pack_into("<HH", raw, 42, 32, 1)
    raw.extend(struct.pack("<8I", 1, image_offset, 0x100000, 0x100000, 8, 8, 7, 1))
    return bytes(raw)


class OutputContractTests(unittest.TestCase):
    def test_output_contract_accepts_one_exact_span_and_real_definition(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "linked.elf"
            path.write_bytes(executable_fixture())
            G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f0, [("first", 0x100000, 8)])
            with self.assertRaisesRegex(ValueError, "GP"):
                G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f4, [])
            with self.assertRaisesRegex(ValueError, "real function"):
                G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f0, [("missing", 0x100000, 8)])

    def test_extra_load_segment_is_rejected(self):
        raw = bytearray(executable_fixture())
        struct.pack_into("<H", raw, 44, 2)
        raw.extend(struct.pack("<8I", 1, 0, 0x200000, 0x200000, 0, 0, 6, 1))
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "extra-load.elf"
            path.write_bytes(raw)
            with self.assertRaisesRegex(ValueError, "exactly the target load span"):
                G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f0, [])

    def test_absolute_alias_cannot_replace_a_real_source_definition(self):
        raw = bytearray(executable_fixture())
        shoff = struct.unpack_from("<I", raw, 32)[0]
        symtab_offset = struct.unpack_from("<I", raw, shoff + 40 + 16)[0]
        struct.pack_into("<H", raw, symtab_offset + 16 + 14, ABS)
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "shadowed.elf"
            path.write_bytes(raw)
            with self.assertRaisesRegex(ValueError, "real function definitions"):
                G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f0, [("first", 0x100000, 8)])


def shared_literal_fixture(number, literal=b'\x0a\xd7\x23\x3c', kind=8, opcode=49, binding=0):
    code = struct.pack('<4I', (opcode << 26) | (28 << 21), 0, 0x03e00008, 0)
    name = 'load' + str(number)
    sections = [Section('', 0, align=0), Section('.symtab', SYMTAB), Section('.strtab', STRTAB),
                Section('.shstrtab', STRTAB),
                Section('.text.' + name, PROGBITS, ALLOC | EXEC, data=code, size=16, align=4),
                Section('.lit4', PROGBITS, 0x10000003, data=literal, size=4, align=4),
                Section('.rel.text', REL, data=struct.pack('<2I', 0, (1 << 8) | kind),
                        size=8, link=1, info=4, align=4, entsize=8)]
    symbols = [Symbol('', 0, 0, 0, 0, 0), Symbol('constant', 0, 4, binding << 4 | OBJECT, 0, 5),
               Symbol(name, 0, 16, GLOBAL << 4 | FUNC, 0, 4)]
    raw = serialize(b'\x7fELF\x01\x01\x01' + bytes(9), 0x20924001, sections, symbols, 1, 2, 3)
    return raw


class SharedLiteralTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name).resolve()
        self.objects = [self.root / f'owner{i}.o' for i in range(2)]
        for index, path in enumerate(self.objects):
            path.write_bytes(shared_literal_fixture(index))
        self.entries = [(0x100000, self.objects[0], '.text.load0'),
                        (0x100020, self.objects[1], '.text.load1'),
                        (0x100100, self.objects[0], '.lit4'),
                        (0x100100, self.objects[1], '.lit4')]

    def test_identical_shared_read_constants_keep_two_real_local_definitions(self):
        plan = G.validate_inputs(self.entries, self.objects, 0x100000, 0x104)
        self.assertEqual(len(plan.shared_literals), 1)
        self.assertEqual(plan.literal_symbols, [('constant', 0x100100, 4)] * 2)
        before = {path: path.read_bytes() for path in self.objects}
        entries, objects, pools = G.prepare_literal_inputs(self.entries, self.objects, plan.shared_literals, self.root)
        for original, prepared in zip(self.objects, objects):
            self.assertEqual(original.read_bytes(), before[original])
            a, b = Elf32(before[original]), Elf32(prepared.read_bytes())
            self.assertEqual(a.flags, b.flags)
            self.assertEqual(a.symbols, b.symbols)
            for index, section in enumerate(a.sections):
                expected = replace(section, flags=section.flags | 0x10, entsize=4) if index == 5 else section
                self.assertEqual(expected, b.sections[index])
        script = G.render_script(entries, {p: p.as_posix() for p in objects}, 0x100000, 0x104,
                                 'load0', 0x108000, {}, pools)
        self.assertIn('ASSERT(SIZEOF(.shared_literal_0) == 4', script)
        self.assertEqual(script.count('(".lit4")'), 2)
        self.assertNotIn('PROVIDE(constant', script)

    def test_different_addresses_do_not_merge_even_when_the_bytes_agree(self):
        entries = self.entries[:-1] + [(0x100104, self.objects[1], '.lit4')]
        plan = G.validate_inputs(entries, self.objects, 0x100000, 0x108)
        self.assertEqual(plan.shared_literals, [])

    def test_conflicting_bytes_partial_overlaps_stores_and_escaped_addresses_fail(self):
        cases = [dict(literal=b'\0\0\x80\x3f'), dict(kind=7), dict(opcode=57), dict(binding=1)]
        for values in cases:
            with self.subTest(values=values):
                self.objects[1].write_bytes(shared_literal_fixture(1, **values))
                with self.assertRaisesRegex(ValueError, 'overlapping'):
                    G.validate_inputs(self.entries, self.objects, 0x100000, 0x108)
        self.objects[1].write_bytes(shared_literal_fixture(1))
        with self.assertRaisesRegex(ValueError, 'overlapping'):
            G.validate_inputs(self.entries[:-1] + [(0x100102, self.objects[1], '.lit4')],
                              self.objects, 0x100000, 0x108)
        with self.assertRaisesRegex(ValueError, 'Duplicate'):
            G.validate_inputs(self.entries + self.entries[-1:], self.objects, 0x100000, 0x108)

    def test_output_requires_every_original_local_constant(self):
        path = self.root / 'linked.elf'
        path.write_bytes(executable_fixture())
        with self.assertRaisesRegex(ValueError, 'local literal definitions'):
            G.validate_output(path, 0x100000, 8, 0x100000, 0x7690f0, [], [('constant', 0x100004, 4)])


if __name__ == "__main__":
    unittest.main()
