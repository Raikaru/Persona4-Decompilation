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
            entry_symbol = build.ELF_TARGET.get(
                "entry_symbol", f"func_{build.parse_int(build.ELF_TARGET['entry']):08x}"
            )
            args = [
                "-nostdlib", "-nodeadstrip", "-m", entry_symbol,
                "-o", str(output / "slus21782.elf"), str(output / "slus21782.lcf"),
                "first.o", "second object.o",
            ]
            self.assertEqual(
                (output / "slus21782.rsp").read_text(encoding="utf-8"),
                subprocess.list2cmdline(args),
            )
            sh.assert_called_once_with(["mwldps2.exe", f"@{output / 'slus21782.rsp'}"])


class ObjectLayoutTests(unittest.TestCase):
    """One `. = addr; obj (.text.<func>)` per function places each function
    individually, so any inter-function gap is expressible and zero-filled.
    Only overlong bodies, non-contiguous windows (a foreign function between
    two of this object's own), and two functions sharing one section are
    genuinely impossible.
    """

    def test_single_function_object_may_be_shorter_than_its_window(self) -> None:
        # The LCF places this function directly, so trailing padding is harmless.
        self.assertTrue(build.object_layout_is_placeable([(0x1000, 0x20, 0x14, 1)]))

    def test_exactly_filled_functions_are_placeable(self) -> None:
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x20, 1), (0x1020, 0x30, 0x30, 2)])
        )

    def test_trailing_padding_on_the_last_function_is_allowed(self) -> None:
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x20, 1), (0x1020, 0x30, 0x24, 2)])
        )

    def test_short_function_is_placeable_when_gap_is_a_power_of_two(self) -> None:
        """The 0x2769b8 case: 100 bytes into a 112-byte window, next addr 16-aligned.

        The second function is placed at 0x1070 directly and the linker
        zero-fills the 12 bytes before it; no source change is needed.
        """
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x70, 0x64, 1), (0x1070, 0x70, 0x70, 2)])
        )

    def test_gap_no_alignment_can_express_is_now_placeable(self) -> None:
        """A 12-byte pad in front of a merely 4-aligned address used to be
        unreachable: alignment cannot manufacture an arbitrary gap, so the
        object-level `. = start; obj (.text)` scheme rejected it. Per-function
        placement puts the second function exactly on 0x106C and the linker
        zero-fills the pad.
        """
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x6C, 0x60, 1), (0x106C, 0x10, 0x10, 2)])
        )

    def test_overlong_function_is_rejected(self) -> None:
        self.assertFalse(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x28, 1), (0x1020, 0x30, 0x30, 2)])
        )

    def test_non_contiguous_windows_are_rejected(self) -> None:
        """A window start between two of this object's functions belongs to a
        foreign function; the code-carving step would drop its bytes from the
        splat asm without any object emitting them."""
        self.assertFalse(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x20, 1), (0x1040, 0x30, 0x30, 2)])
        )

    def test_sections_emitted_out_of_address_order_are_placeable(self) -> None:
        """Per-function placement is by name, so the object's section order no
        longer constrains the layout."""
        self.assertTrue(
            build.object_layout_is_placeable([(0x1000, 0x20, 0x20, 2), (0x1020, 0x30, 0x30, 1)])
        )

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

    def test_renames_section_and_grows_shstrtab(self) -> None:
        import struct as _struct

        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "unit.o"
            path.write_bytes(self._two_function_object())
            build.rename_text_sections(path, {"foo": 0x1000})
            obj = build.V.ObjectFile(path)
        self.assertEqual(obj.sections[1]["name"], ".text.foo")
        self.assertEqual(obj.sections[1]["addralign"], 1)
        # The table spans from its original offset to the end of the file, so
        # the appended names are inside its data.
        self.assertEqual(obj.sections[4]["size"], len(obj.data) - obj.sections[4]["offset"])
        blob = obj.data[obj.sections[4]["offset"]:obj.sections[4]["offset"] + obj.sections[4]["size"]]
        self.assertIn(b".text.foo\0", blob)
        self.assertEqual(len(obj.function("foo")[0]), 8)

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


class MissingDefinitionTests(unittest.TestCase):
    def test_defines_only_referenced_unexported_known_symbols(self) -> None:
        definitions = {"already_defined": 0x1000}
        build.complete_missing_definitions(
            definitions,
            unresolved={"already_defined", "exported", "missing", "unknown"},
            exported={"exported"},
            addresses={
                "already_defined": 0x1000,
                "exported": 0x2000,
                "missing": 0x3000,
            },
        )
        self.assertEqual(
            definitions,
            {
                "already_defined": 0x1000,
                "missing": 0x3000,
            },
        )


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
            self.assertFalse([a for a in invocations[0] if a.startswith("-D")])
            self.assertEqual(output.read_bytes(), b"linked-object")
            self.assertEqual(second.stats["link"], {"hits": 1, "misses": 0})


if __name__ == "__main__":
    unittest.main()
