from __future__ import annotations

import copy
import importlib.util
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("p4_gap_objdiff", REPO / "tools" / "gen_objdiff.py")
assert SPEC is not None and SPEC.loader is not None
gen = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(gen)

RECONCILE_SPEC = importlib.util.spec_from_file_location(
    "p4_gap_reconcile", REPO / "tools" / "reconcile_function_boundaries.py"
)
assert RECONCILE_SPEC is not None and RECONCILE_SPEC.loader is not None
reconcile = importlib.util.module_from_spec(RECONCILE_SPEC)
RECONCILE_SPEC.loader.exec_module(reconcile)

sys.path.insert(0, str(REPO / "tools" / "mwccgap"))
from mwccgap import mwccgap as gap  # noqa: E402
from mwccgap.elf import Elf, RelocationRecord, STT_SECTION, Symbol  # noqa: E402

FLAGS = 0x20924001


def _compiled_stub(name: str, size: int) -> bytes:
    obj = Elf(gen.build_elf_object(bytes(size), [], gap.FUNCTION_PREFIX + name, FLAGS))
    # The destination text section must differ from the assembler's section 1.
    prefix = copy.copy(obj.sections[0])
    prefix.name = ".data"
    prefix.sh_name = obj.add_sh_symbol(prefix.name)
    prefix.sh_type = 1
    prefix.sh_flags = 3
    prefix.sh_addralign = 4
    prefix.data = bytes(4)
    prefix.sh_size = len(prefix.data)
    for symbol in obj.symtab.symbols:
        if symbol.st_shndx:
            symbol.st_shndx += 1
    for section in obj.sections:
        if section.sh_link:
            section.sh_link += 1
        if isinstance(section, RelocationRecord):
            section.sh_info += 1
    obj.sections.insert(1, prefix)
    obj.symtab_index += 1
    obj.e_shstrndx += 1
    obj.e_shnum += 1
    return obj.pack()


class SectionRelocationTests(unittest.TestCase):
    def test_section_addends_link_without_exporting_or_requiring_target_labels(self) -> None:
        name = "func_fixture"
        code = struct.pack("<8I", 0x0C000004, 0x08000005, 0x18, 0x0C000000, 0, 0, 0, 0)
        relocations = [
            {"offset": 0, "r_type": 4, "symbol": name},
            {"offset": 4, "r_type": 4, "symbol": name},
            {"offset": 8, "r_type": 2, "symbol": name},
            {"offset": 12, "r_type": 4, "symbol": "external_call"},
        ]
        assembled = Elf(gen.build_elf_object(code, relocations, name, FLAGS))
        text_index = assembled.sections.index(assembled.get_functions()[0])
        section_symbol = Symbol(0, 0, 0, STT_SECTION, 0, text_index)
        section_index = assembled.add_symbol(section_symbol, force=True)
        local = Symbol(0, 0x10, 0, 0, 0, text_index)
        local.name = ".Lkept"
        assembled.add_symbol(local, force=True)
        # There is deliberately no named label at either 0x14 or 0x18.
        external_index, _ = assembled.symtab.get_symbol_by_name("external_call")
        for record in assembled.get_relocations():
            for relocation in record.relocations:
                relocation.symbol_index = external_index if relocation.r_offset == 12 else section_index

        precompiled = gen.build_elf_object(b"", [], "already_c", FLAGS)
        compiled = _compiled_stub(name, len(code))
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source, output = root / "owner.c", root / "owner.o"
            source.write_text("/* compiler input fixture */\n")
            with (
                mock.patch.object(gap, "Compiler") as compiler,
                mock.patch.object(gap, "Assembler") as assembler,
                mock.patch.object(gap.Preprocessor, "preprocess_c_file", return_value=([""], [(root / (name + ".s"), 0)])),
            ):
                compiler.return_value.compile_file.side_effect = [precompiled, compiled]
                assembler.return_value.assemble_file.return_value = assembled.pack()
                gap.process_c_file(source, output)
            linked = Elf(output.read_bytes())

        text = linked.get_functions()[0]
        text_index = linked.sections.index(text)
        base, external_address = 0x00120000, 0x00140000
        destinations = {}
        for record in linked.get_relocations():
            for relocation in record.relocations:
                symbol = linked.symtab.symbols[relocation.symbol_index]
                if symbol.st_shndx == text_index:
                    address = base + symbol.st_value
                elif symbol.name == "external_call" and symbol.st_shndx == 0:
                    address = external_address
                else:
                    self.fail(f"Unresolved relocated address: {symbol.name!r}")
                word = struct.unpack_from("<I", text.data, relocation.r_offset)[0]
                addend = (word & 0x03FFFFFF) << 2 if relocation.reloc_type == 4 else word
                destinations[relocation.r_offset] = address + addend
        self.assertEqual(destinations, {0: base + 0x10, 4: base + 0x14, 8: base + 0x18, 12: external_address})
        self.assertFalse(any(symbol.name == ".Lkept" and symbol.bind != 0 for symbol in linked.symtab.symbols))


class SourceInventoryTests(unittest.TestCase):
    def test_compilation_keeps_canonical_source_inventory_stable(self) -> None:
        name = "func_00120000"
        precompiled = gen.build_elf_object(b"", [], "already_c", FLAGS)
        code = struct.pack("<2I", 0x03E00008, 0)
        compiled = _compiled_stub(name, len(code))
        assembled = gen.build_elf_object(code, [], name, FLAGS)
        for encoding in (None, "utf-8"):
            with self.subTest(encoding=encoding), tempfile.TemporaryDirectory() as directory:
                root = Path(directory)
                source = root / "src" / "owner.c"
                source.parent.mkdir()
                source.write_text(
                    '// FUN_00120000\nINCLUDE_ASM("asm", func_00120000);\n',
                    encoding="utf-8",
                )
                objects = iter((precompiled, compiled))

                def compile_while_inventory_is_read(_source: Path) -> bytes:
                    owners = {
                        address: [path for path, _marker in entries]
                        for address, entries in reconcile.source_markers().items()
                    }
                    self.assertEqual(owners, {0x120000: [Path("src/owner.c")]})
                    return next(objects)

                with (
                    mock.patch.object(reconcile, "REPO", root),
                    mock.patch.object(gap, "Compiler") as compiler,
                    mock.patch.object(gap, "Assembler") as assembler,
                    mock.patch.object(
                        gap.Preprocessor,
                        "preprocess_c_file",
                        return_value=(
                            ["// FUN_00120000", "void func_00120000(void) {}"],
                            [(root / (name + ".s"), 0)],
                        ),
                    ),
                ):
                    compiler.return_value.compile_file.side_effect = compile_while_inventory_is_read
                    assembler.return_value.assemble_file.return_value = assembled
                    gap.process_c_file(source, root / "owner.o", c_file_encoding=encoding)


if __name__ == "__main__":
    unittest.main()
