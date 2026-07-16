from __future__ import annotations

import importlib.util
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
                build.compile_c(config, source, output, first, 0x00100000)
                output.unlink()
                second = build.BC.ObjectCache(root / "build" / "cache" / "c", root)
                build.compile_c(config, source, output, second, 0x00100000)

            self.assertEqual(len(invocations), 1)
            self.assertIn("-DP4_UNIT_00100000", invocations[0])
            self.assertEqual(output.read_bytes(), b"linked-object")
            self.assertEqual(second.stats["link"], {"hits": 1, "misses": 0})


if __name__ == "__main__":
    unittest.main()
