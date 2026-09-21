from __future__ import annotations

import os
from pathlib import Path
import subprocess
import shutil
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import eegcc_shim as shim


class BinutilsDiscoveryTests(unittest.TestCase):
    def test_unconfigured_tools_use_existing_native_or_wsl_discovery(self) -> None:
        tool = shim.assembler_tools.Tool(("wsl", "--", "mipsel-linux-gnu-as"), wsl=True)
        with patch.dict(os.environ, {}, clear=True), \
                patch.object(shim.assembler_tools, "find_gnu_tool", return_value=tool) as discover:
            result = shim._binutils_tool({}, "as_path", "p4_as", "mipsel-linux-gnu-as", "P4_AS")
        self.assertIs(result, tool)
        discover.assert_called_once_with("mipsel-linux-gnu-as", "P4_AS")

    def test_explicit_executable_path_keeps_spaces(self) -> None:
        path = "C:/Program Files/binutils/as.exe"
        with patch.dict(os.environ, {}, clear=True):
            tool = shim._binutils_tool({"as_path": path}, "as_path", "p4_as", "as", "P4_AS")
        self.assertEqual(tool.argv, (path,))
        self.assertFalse(tool.wsl)

    def test_environment_command_overrides_configured_path(self) -> None:
        tool = shim.assembler_tools.Tool(("wsl", "--", "as"), wsl=True)
        with patch.dict(os.environ, {"P4_AS": "wsl -- as"}), \
                patch.object(shim.assembler_tools, "find_gnu_tool", return_value=tool) as discover:
            actual = shim._binutils_tool({"as_path": "old-as"}, "as_path", "p4_as", "as", "P4_AS")
        self.assertIs(actual, tool)
        discover.assert_called_once_with("as", "P4_AS")

    def test_metadata_strip_translates_wsl_object_path_and_keeps_real_data(self) -> None:
        obj = Path("C:/project with spaces/out.o")
        tool = shim.assembler_tools.Tool(("wsl", "--", "objcopy"), wsl=True)
        with patch.object(shim, "_empty_sections", return_value={".text", ".bss"}), \
                patch.object(shim.assembler_tools, "_wslpath", return_value="/mnt/c/project with spaces/out.o"), \
                patch.object(shim.assembler_tools.subprocess, "run", return_value=subprocess.CompletedProcess([], 0, b"")) as run:
            shim._strip_gcc_metadata(tool, obj)
        argv = run.call_args.args[0]
        self.assertEqual(argv[:3], ["wsl", "--", "objcopy"])
        self.assertEqual(argv[-1], "/mnt/c/project with spaces/out.o")
        self.assertIn("--remove-section=.text", argv)
        self.assertIn("--remove-section=.bss", argv)
        self.assertNotIn("--remove-section=.data", argv)


class HeaderStagingTests(unittest.TestCase):
    def test_relative_vendor_include_keeps_its_parent_directories(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory) / "repo"
            include = root / "include/cri/cri/mwlib/ee"
            include.mkdir(parents=True)
            header = include / "lib/libadxe/format.h"
            header.parent.mkdir(parents=True)
            header.write_text("typedef int VendorInt;\n", encoding="utf-8")
            work = Path(directory) / "work"
            with patch.object(shim, "REPO", root):
                staged = shim._stage_includes(["include", "include/cri/cri/mwlib/ee"], work)
            self.assertEqual(staged, ["project/include", "project/include/cri/cri/mwlib/ee"])
            via_relative = work / staged[1] / "../../../cri/mwlib/ee/lib/libadxe/format.h"
            self.assertEqual(via_relative.read_bytes(), header.read_bytes())

    def test_header_search_order_is_preserved(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory) / "repo"
            for name in ("include/vendor A", "include/vendor B"):
                (root / name).mkdir(parents=True)
                (root / name / "types.h").write_text(name, encoding="utf-8")
            with patch.object(shim, "REPO", root):
                staged = shim._stage_includes(["include/vendor B", "include/vendor A"], Path(directory) / "work")
            self.assertEqual(staged, ["project/include/vendor B", "project/include/vendor A"])


@unittest.skipUnless(shutil.which("mipsel-linux-gnu-as"), "native R5900 assembler is not installed")
class AssemblyAbiTests(unittest.TestCase):
    def test_ee_doubleword_saves_remain_single_instructions(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "saved.s"
            obj = Path(directory) / "saved.o"
            source.write_text(
                '.text\n.set noreorder\n.global saved\n.type saved,@function\nsaved:\n'
                'sd $16,0($29)\nld $16,0($29)\njr $31\nnop\n.size saved,.-saved\n',
                encoding="utf-8")
            tool = shim.assembler_tools.Tool((shutil.which("mipsel-linux-gnu-as"),))
            result = shim.assembler_tools._run_tool(tool, [*shim.ASSEMBLER_FLAGS, source, "-o", obj])
            self.assertEqual(result.returncode, 0, result.stdout.decode("utf-8", errors="replace"))
            import verify
            body, relocations = verify.ObjectFile(obj).function("saved")
            self.assertEqual(body, bytes.fromhex("0000b0ff0000b0df0800e00300000000"))
            self.assertEqual(relocations, [])

    def test_large_word_add_does_not_become_a_doubleword_add(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "add.s"
            obj = source.with_suffix(".o")
            source.write_text(
                '.text\n.set noreorder\n.global add_word\n.type add_word,@function\nadd_word:\n'
                'addu $4,$4,1879048192\njr $31\nnop\n.size add_word,.-add_word\n', encoding="utf-8")
            shim._rewrite_eabi_pseudos(source)
            tool = shim.assembler_tools.Tool((shutil.which("mipsel-linux-gnu-as"),))
            result = shim.assembler_tools._run_tool(tool, [*shim.ASSEMBLER_FLAGS, source, "-o", obj])
            self.assertEqual(result.returncode, 0, result.stdout.decode("utf-8", errors="replace"))
            import verify
            body, _ = verify.ObjectFile(obj).function("add_word")
            self.assertEqual(body[:8], bytes.fromhex("0070013c21202400"))

    def test_indexed_symbol_addresses_use_word_adds_and_restore_gpr_width(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "address.s"
            obj = source.with_suffix(".o")
            source.write_text(
                '.text\n.set noreorder\n.global address\n.type address,@function\naddress:\n'
                'la $4,1879048192($4)\nlw $3,symbol($4)\nsd $16,0($29)\n'
                'jr $31\nnop\n.size address,.-address\n', encoding="utf-8")
            shim._rewrite_eabi_pseudos(source)
            tool = shim.assembler_tools.Tool((shutil.which("mipsel-linux-gnu-as"),))
            result = shim.assembler_tools._run_tool(tool, [*shim.ASSEMBLER_FLAGS, source, "-o", obj])
            self.assertEqual(result.returncode, 0, result.stdout.decode("utf-8", errors="replace"))
            import verify
            body, relocations = verify.ObjectFile(obj).function("address")
            self.assertEqual(body[:24], bytes.fromhex("0070013c212024000000033c211864000000638c0000b0ff"))
            self.assertEqual([r["r_type"] for r in relocations], [5, 6])


class CompilerPseudoTests(unittest.TestCase):
    def test_real_register_adds_and_small_immediates_remain_unchanged(self) -> None:
        text = "\taddu $4,$1,$4\n\taddu $4,$4,16\n\taddiu $4,$4,-16\n"
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "source.s"
            source.write_text(text, encoding="utf-8")
            shim._rewrite_eabi_pseudos(source)
            self.assertEqual(source.read_text(), text)

    def test_legacy_float_forms_restore_the_surrounding_isa(self) -> None:
        text = "\tcvt.w.s $f1,$f0\n\tli.d $2,3.2767e4\n\tpadduw $1,$0,$0\n"
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "source.s"
            source.write_text(text, encoding="utf-8")
            shim._rewrite_eabi_pseudos(source)
            fixed = source.read_text()
            self.assertEqual(fixed.count(".set push"), 2)
            self.assertEqual(fixed.count(".set pop"), 2)
            self.assertTrue(fixed.endswith("\t.set pop\n\tpadduw $1,$0,$0\n"))


if __name__ == "__main__":
    unittest.main()
