from __future__ import annotations

import importlib.util
import json
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "extract_nonmatching_asm.py"
SPEC = importlib.util.spec_from_file_location("p4_extract_asm", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
tool = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(tool)

CODE1 = REPO / "asm" / "code1.s"
RETAIL_ELF = REPO / "orig" / "SLUS_217.82"

# A real canonical function used for the integration tests: 720-byte window,
# sliced from asm/code1.s, exercising .L labels, hi/lo pairs and jal relocs.
REAL_ADDR = 0x00202890
REAL_WINDOW = 720


def gnu_as_available() -> bool:
    """True when the project's GNU assembler (possibly via WSL) is reachable.

    Must never raise: this is evaluated at import time by @skipUnless
    decorators, so an exception here turns the whole module into a collection
    ERROR instead of a skip. On a Linux CI runner with no cross-assembler there
    is no `wsl` binary at all, and probing for it raises FileNotFoundError
    rather than the SystemExit find_gnu_tool uses for "not installed".
    """
    try:
        tool.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
        return True
    except (SystemExit, OSError):
        return False


def load_retail() -> "tool.V.RetailElf":
    import verify as V  # module is already importable via tool's sys.path

    cfg = V.load_config()
    target = V._read_json(V.TARGET)
    windows = V._read_json(V.FUNCTION_WINDOWS)
    return V.RetailElf(cfg["retail_elf"], target, windows["sha1"])


def real_slice_lines() -> list[str]:
    """The splat slice for REAL_ADDR from asm/code1.s, exactly as the tool slices."""
    index = tool.build_splat_index(REPO / "asm", {REAL_ADDR})
    path, glabel_lineno = index[REAL_ADDR]
    end = tool.next_glabel_lineno(path, glabel_lineno)
    assert end is not None
    return tool.slice_function(path, glabel_lineno, end)


class PlaceholderAccountingTests(unittest.TestCase):
    """The .s line count must match the mwccgap preprocessor's nop counting."""

    def test_counted_lines_are_instructions_only(self) -> None:
        lines = [
            ".section .text\n",
            ".set noat\n",
            ".set noreorder\n",
            "glabel func_00123456\n",
            "    /* 0 00123456 27BDFFA0 */  addiu      $29, $29, -0x60\n",
            "  .L00123458:\n",
            "    /* 8 0012345E 03E00008 */  jr         $31\n",
            ".word 0x00000000\n",
            "endlabel func_00123456\n",
            "nonmatching func_00123460, 0x10\n",
            "/* Handwritten function */\n",
            "\n",
            "# a comment\n",
            ".size func_00123456, 0x10\n",
        ]
        # instructions + .word only: addiu, jr, .word -> 3 counted lines
        self.assertEqual(tool.count_placeholder_words(lines), 3)


    def test_placeholder_parity_with_mwccgap_preprocessor(self) -> None:
        """count_placeholder_words agrees with mwccgap's own nop counting."""
        mwccgap_dir = REPO / "tools" / "mwccgap"
        if not (mwccgap_dir / "mwccgap" / "preprocessor.py").is_file():
            self.skipTest("mwccgap not vendored")
        sys.path.insert(0, str(mwccgap_dir))
        try:
            from mwccgap.preprocessor import Preprocessor  # type: ignore
        finally:
            sys.path.remove(str(mwccgap_dir))
        sample = (
            ".section .text\n"
            ".set noat\n"
            ".set noreorder\n"
            "glabel func_00123456\n"
            "    /* 0 00123456 27BDFFA0 */  addiu      $29, $29, -0x60\n"
            "    /* 4 0012345A 0C000000; */ jal        func_00452560\n"
            "  .L00123458:\n"
            "    /* 8 0012345E 03E00008 */  jr         $31\n"
            ".word 0x0C000000; .reloc .-4, R_MIPS_26, func_00452560\n"
            "endlabel func_00123456\n"
            "nonmatching func_00123460, 0x10\n"
            "/* Handwritten function */\n"
            "\n"
            ".size func_00123456, 0x10\n"
        )
        from io import StringIO

        c_lines, _ = Preprocessor.preprocess_s_file("func_00123456", StringIO(sample))
        nops_needed = len(c_lines) - 2  # drop "asm void ... {" and "}"
        self.assertEqual(
            nops_needed, tool.count_placeholder_words(sample.splitlines(keepends=True))
        )


class SliceWindowDecisionTests(unittest.TestCase):
    """A slice short of (or longer than) its window is rejected, not padded."""

    def test_full_slice_matches_window(self) -> None:
        if not CODE1.is_file():
            self.skipTest("asm/code1.s not present")
        self.assertTrue(tool.slice_matches_window(real_slice_lines(), REAL_WINDOW))

    def test_short_slice_is_rejected(self) -> None:
        if not CODE1.is_file():
            self.skipTest("asm/code1.s not present")
        raw = real_slice_lines()
        index = next(i for i, line in enumerate(raw)
                     if line.lstrip().startswith("/*") and tool.VRAM_RE.search(line))
        truncated = raw[:index] + raw[index + 1:]
        self.assertEqual(tool.count_placeholder_words(tool.clean_slice(truncated)) * 4, REAL_WINDOW - 4)
        self.assertFalse(tool.slice_matches_window(truncated, REAL_WINDOW))

    def test_long_slice_is_rejected(self) -> None:
        if not CODE1.is_file():
            self.skipTest("asm/code1.s not present")
        raw = real_slice_lines()
        extra = ["    /* 2D0 00202B60 00000000 */  nop\n"]
        self.assertFalse(tool.slice_matches_window(raw + extra, REAL_WINDOW))

    def test_short_slice_falls_back_to_synthesis(self) -> None:
        """A short slice is rejected in favour of a full-window synthesis.

        Rejected, not padded: padding a short slice would hide splat's
        disagreement with the canonical window behind a byte-count fix while
        the instruction stream could still be wrong.  Synthesis decodes the
        whole window from the retail ELF, so the emitted file is byte-exact
        for every word by construction.
        """
        if not (CODE1.is_file() and RETAIL_ELF.is_file()):
            self.skipTest("repo asm/retail not present")
        if not gnu_as_available():
            self.skipTest("GNU assembler not available")
        retail = load_retail()
        with tempfile.TemporaryDirectory(prefix="p4-test-asm-") as tmpdir:
            # Fake splat output that labels the function but splits it after
            # two instructions (8 bytes) instead of the 720-byte window.
            fake = Path(tmpdir) / "fake.s"
            fake.write_text(
                f"glabel func_{REAL_ADDR:08x}\n"
                f"    /* 0 {REAL_ADDR:08X} 27BDFFA0 */  addiu      $29, $29, -0x60\n"
                f"    /* 4 {REAL_ADDR + 4:08X} 03E00008 */  jr         $31\n"
                f"glabel func_{REAL_ADDR + 8:08x}\n",
                encoding="utf-8")
            index = tool.build_splat_index(Path(tmpdir), {REAL_ADDR},
                                           names=("fake.s",))
            macro_lines = (REPO / "asm" / "macro.inc").read_bytes().decode(
                "ascii").splitlines(keepends=True)
            asm_tool = tool.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
            kind, lines = tool.extract_function(
                REAL_ADDR, REAL_WINDOW, retail, {}, index, asm_tool,
                macro_lines, REPO / "asm", Path(tmpdir))
        self.assertEqual(kind, "synthesised")
        self.assertEqual(
            tool.count_placeholder_words(lines) * 4, REAL_WINDOW,
            "the fallback must still cover the full canonical window",
        )
        self.assertTrue(any(".word 0x" in line for line in lines))


class SynthesiseTests(unittest.TestCase):
    def test_jal_to_canonical_function_gets_reloc_annotation(self) -> None:
        # word 0: addiu $29, $29, -0x20; word 1: jal func_00106330;
        # word 2: nop; word 3: jr $31 (not a JAL, so it stays literal).
        raw = struct.pack("<IIII", 0x27BDFFE0, 0x0C0418CC, 0x00000000, 0x03E00008)
        windows = {"00106330": 8}
        lines = tool.synthesise(0x00123456, 16, raw, windows)
        self.assertEqual(len(lines), 5)  # glabel + 4 words
        self.assertEqual(lines[1].strip(), ".word 0x27BDFFE0")
        self.assertEqual(lines[2].strip(), ".word 0x0C000000; .reloc .-4, R_MIPS_26, func_00106330")
        self.assertEqual(lines[4].strip(), ".word 0x03E00008")

    def test_jal_to_non_window_target_stays_literal(self) -> None:
        # jal to 0x7FFFFFC (not in the window map) must not get a relocation:
        # an unresolvable symbol would break the link.
        raw = struct.pack("<II", 0x0C000000 | ((0x7FFFFFC >> 2) & 0x3FFFFFF), 0x00000000)
        lines = tool.synthesise(0x00123456, 8, raw, {})
        self.assertNotIn(".reloc", lines[1])
        self.assertEqual(lines[1].strip(), ".word 0x0DFFFFFF")

    def test_placeholder_of_synthesised_file_is_window(self) -> None:
        raw = b"\x00" * 64
        lines = tool.HEADER_LINES + tool.synthesise(0x00123456, 64, raw, {})
        self.assertEqual(tool.count_placeholder_words(lines) * 4, 64)


class ReportAndGroupingTests(unittest.TestCase):
    def test_report_jobs_read_nonmatching_entries(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4-test-report-") as tmpdir:
            report = Path(tmpdir) / "report.json"
            report.write_text(json.dumps({"results": [
                {"status": "NONMATCHING", "addr": "00202890", "window": 720,
                 "file": "src\\Battle\\btlPanel.c"},
                {"status": "MATCH", "addr": "00100008", "window": 528,
                 "file": "src\\crt0.c"},
                {"status": "NONMATCHING", "addr": "0052c870", "window": 64,
                 "file": "src/promoted/code1_0052.c"},
            ]}), encoding="utf-8")
            jobs = tool.report_jobs(report)
        self.assertEqual([job["addr"] for job in jobs], [0x00202890, 0x0052C870])
        self.assertEqual(jobs[0]["group"], "btlPanel")
        self.assertEqual(jobs[1]["group"], "code1_0052")

    def test_include_asm_line_format(self) -> None:
        # The second argument is deliberately UNQUOTED: mwccgap's regex and
        # verify.py's INCLUDE_MARKER_RE both parse it as a bare identifier.
        self.assertEqual(
            tool.include_asm_line("btlPanel", 0x00202890),
            'INCLUDE_ASM("asm/nonmatchings/btlPanel", func_00202890)',
        )

    def test_find_owner_file_scans_markers(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4-test-src-") as tmpdir:
            src = Path(tmpdir)
            (src / "Battle").mkdir()
            (src / "Battle" / "btlPanel.c").write_text(
                "// FUN_00202890 NONMATCHING\nvoid func_00202890(void) {}\n",
                encoding="utf-8",
            )
            (src / "unrelated.c").write_text("int x;\n", encoding="utf-8")
            owner = tool.find_owner_file(0x00202890, src)
            self.assertIsNotNone(owner)
            assert owner is not None
            self.assertEqual(owner.name, "btlPanel.c")
            self.assertIsNone(tool.find_owner_file(0x00100008, src))


@unittest.skipUnless(CODE1.is_file() and RETAIL_ELF.is_file(),
                     "repo asm/retail files not present")
@unittest.skipUnless(gnu_as_available(), "GNU assembler not available")
class EndToEndTests(unittest.TestCase):
    """Real extraction: assembled .text == window, bytes == retail (masked)."""

    def _extract(self, addr: int, window: int, out_dir: Path,
                 index: dict | None = None) -> tuple[str, list[str]]:
        retail = load_retail()
        macro_lines = (REPO / "asm" / "macro.inc").read_bytes().decode(
            "ascii").splitlines(keepends=True)
        asm_tool = tool.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
        if index is None:
            index = tool.build_splat_index(REPO / "asm", {addr})
        return tool.extract_function(
            addr, window, retail, {}, index, asm_tool, macro_lines,
            REPO / "asm", out_dir)

    def test_sliced_file_assembles_to_window_and_matches_retail(self) -> None:
        import verify as V

        retail = load_retail()
        load_vaddr, load_offset, load_filesz = retail.segs[0]
        blob = retail.data[load_offset:load_offset + load_filesz]
        with tempfile.TemporaryDirectory(prefix="p4-test-e2e-") as tmpdir:
            kind, lines = self._extract(REAL_ADDR, REAL_WINDOW, Path(tmpdir))
            self.assertEqual(kind, "sliced")
            self.assertEqual(
                tool.count_placeholder_words(lines) * 4, REAL_WINDOW,
                "byte count vs window size for the written file",
            )
            # Assemble macro.inc + content the way mwccgap's Assembler does
            # and verify the .text is exactly the window and matches retail.
            obj = Path(tmpdir) / "check.o"
            ok, log, body, relocs = tool.assemble_with_repair(
                lines, tool.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS"),
                (REPO / "asm" / "macro.inc").read_bytes().decode("ascii").splitlines(keepends=True),
                REPO / "asm", blob, REAL_ADDR - load_vaddr, REAL_ADDR, obj)
            self.assertTrue(ok, log)
            self.assertEqual(len(body), REAL_WINDOW)
            difference, first = V.compare(body, relocs, retail.bytes_at(REAL_ADDR, REAL_WINDOW))
            self.assertEqual(difference, 0, f"masked diffs at {first[:16]}")
            self.assertTrue(any(".reloc" in line or "%hi" in line for line in lines),
                            "a relocatable slice keeps symbol references")

    def test_wrong_window_is_rejected_and_nothing_written(self) -> None:
        """A malformed window is rejected before creating assembler output."""
        with tempfile.TemporaryDirectory(prefix="p4-test-neg-") as tmpdir:
            # A window that is not a multiple of 4 fails the placeholder gate
            # for both slice and synthesis before any assembly happens.
            with self.assertRaises(tool.ExtractionFailure):
                self._extract(REAL_ADDR, REAL_WINDOW - 1, Path(tmpdir))
            self.assertEqual(list(Path(tmpdir).iterdir()), [])


@unittest.skipUnless(CODE1.is_file() and RETAIL_ELF.is_file(),
                     "repo asm/retail files not present")
@unittest.skipUnless(gnu_as_available(), "GNU assembler not available")
class CliTests(unittest.TestCase):
    def test_corrupt_report_window_is_refused(self) -> None:
        """Negative control at the CLI level: a wrong window in the report
        must be refused up front, not silently turned into a truncated .s."""
        with tempfile.TemporaryDirectory(prefix="p4-test-corrupt-") as tmpdir:
            report = Path(tmpdir) / "report.json"
            report.write_text(json.dumps({"results": [
                {"status": "NONMATCHING", "addr": "00202890",
                 "window": REAL_WINDOW - 4, "file": "src/Battle/btlPanel.c"},
            ]}), encoding="utf-8")
            out = Path(tmpdir) / "out"
            proc = subprocess.run(
                [sys.executable, str(MODULE_PATH), "--all-nonmatching",
                 "--report", str(report), "--out-dir", str(out)],
                cwd=REPO, capture_output=True, text=True)
            self.assertNotEqual(proc.returncode, 0)
            self.assertIn("canonical map says", proc.stderr)
            self.assertFalse((out / "btlPanel" / "func_00202890.s").exists())
        # Restore: the canonical window extracts cleanly.
        with tempfile.TemporaryDirectory(prefix="p4-test-restore2-") as tmpdir:
            report = Path(tmpdir) / "report.json"
            report.write_text(json.dumps({"results": [
                {"status": "NONMATCHING", "addr": "00202890",
                 "window": REAL_WINDOW, "file": "src/Battle/btlPanel.c"},
            ]}), encoding="utf-8")
            out = Path(tmpdir) / "out"
            proc = subprocess.run(
                [sys.executable, str(MODULE_PATH), "--all-nonmatching",
                 "--report", str(report), "--out-dir", str(out)],
                cwd=REPO, capture_output=True, text=True)
            self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
            self.assertTrue((out / "btlPanel" / "func_00202890.s").is_file())

    def test_cli_idempotent_and_check_mode(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4-test-cli-") as tmpdir:
            out = Path(tmpdir) / "out"
            base = [sys.executable, str(MODULE_PATH), "00202890",
                    "--out-dir", str(out)]
            # --check on a fresh tree reports would-write and exits nonzero.
            check = subprocess.run(
                base + ["--check"], cwd=REPO, capture_output=True, text=True)
            self.assertEqual(check.returncode, 1, check.stdout + check.stderr)
            self.assertFalse((out / "btlPanel" / "func_00202890.s").exists())
            first = subprocess.run(base, cwd=REPO, capture_output=True, text=True)
            self.assertEqual(first.returncode, 0, first.stdout + first.stderr)
            generated = out / "btlPanel" / "func_00202890.s"
            before = generated.read_bytes()
            import os
            os.utime(generated, (1_000_000_000, 1_000_000_000))
            timestamp = generated.stat().st_mtime_ns
            # A second generation writes nothing and --check then exits 0.
            second = subprocess.run(base, cwd=REPO, capture_output=True, text=True)
            self.assertEqual(second.returncode, 0)
            self.assertEqual(generated.read_bytes(), before)
            self.assertEqual(generated.stat().st_mtime_ns, timestamp)
            check2 = subprocess.run(
                base + ["--check"], cwd=REPO, capture_output=True, text=True)
            self.assertEqual(check2.returncode, 0)
            self.assertEqual(generated.read_bytes(), before)
            self.assertEqual(generated.stat().st_mtime_ns, timestamp)
            self.assertIn('INCLUDE_ASM("asm/nonmatchings/btlPanel", '
                          'func_00202890)', check2.stdout)


if __name__ == "__main__":
    unittest.main()
