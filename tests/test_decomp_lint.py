from __future__ import annotations

import contextlib
import importlib.util
import io
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]

SPEC = importlib.util.spec_from_file_location("p4_decomp_lint", REPO / "tools" / "decomp_lint.py")
assert SPEC is not None and SPEC.loader is not None
lint = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(lint)


def codes(findings):
    return sorted(f.code for f in findings)


def lint_text(text: str, name: str = "unit.c"):
    """Lint a crafted source string in a temp file; return the findings."""
    with tempfile.TemporaryDirectory() as directory:
        path = Path(directory) / name
        path.write_text(text, encoding="utf-8")
        src = lint.Source(path, path.read_bytes())
        return lint.lint_source(src)


class VolatileTests(unittest.TestCase):
    def test_fires_on_non_hardware_volatile(self) -> None:
        findings = lint_text("""// FUN_00100000
void func_00100000(void)
{
    volatile int x;
    x = 1;
}
""")
        self.assertIn("H001", codes(findings))

    def test_silent_on_hardware_mmio_address(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    *(volatile u32 *)0x1F801000 = 1;
}
""")
        self.assertNotIn("H001", codes(findings))

    def test_silent_on_volatile_inside_comment(self) -> None:
        findings = lint_text("""/* volatile on purpose, but this is only a comment */
void func_00100000(void) { }
""")
        self.assertNotIn("H001", codes(findings))


class BannedPragmaTests(unittest.TestCase):
    FORMS = (
        "optimization_level 0",
        "optimization_level 1",
        "optimization_level 3",
        "schedule off",
        "opt_common_subs off",
        "opt_loop_invariants on",
        "opt_loop_invariants off",
    )

    def test_fires_on_every_banned_form(self) -> None:
        for form in self.FORMS:
            with self.subTest(pragma=form):
                findings = lint_text(f"#pragma {form}\nvoid func_00100000(void) {{ }}\n")
                self.assertIn("H003", codes(findings))
                self.assertNotIn("H003W", codes(findings))

    def test_silent_on_baseline_optimization_level_2(self) -> None:
        findings = lint_text("#pragma optimization_level 2\nvoid func_00100000(void) { }\n")
        self.assertNotIn("H003", codes(findings))

    def test_redundant_level_2_is_only_a_warning(self) -> None:
        findings = lint_text("#pragma optimization_level 2\nvoid func_00100000(void) { }\n")
        self.assertEqual(codes(findings), ["H003W"])


class DeadStoreTests(unittest.TestCase):
    def test_fires_on_assigned_never_read_local(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    int x;
    x = 5;
}
""")
        self.assertIn("H007", codes(findings))

    def test_silent_when_local_is_read_later(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    int x;
    x = 5;
    return x;
}
""")
        self.assertNotIn("H007", codes(findings))

    def test_silent_when_local_is_never_assigned(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    int x;
    return 0;
}
""")
        self.assertNotIn("H007", codes(findings))


class RegisterLocalTests(unittest.TestCase):
    def test_fires_on_register_local(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    register int x;
    x = 1;
}
""")
        self.assertIn("H008", codes(findings))

    def test_silent_on_plain_local(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    int x;
    x = 1;
}
""")
        self.assertNotIn("H008", codes(findings))


class MarkerHygieneTests(unittest.TestCase):
    def test_fires_on_malformed_address(self) -> None:
        for marker in ("// FUN_00123", "// FUN_", "// FUN_001234567"):
            with self.subTest(marker=marker):
                findings = lint_text(f"{marker}\nvoid func_00100000(void) {{ }}\n")
                self.assertIn("M001", codes(findings))

    def test_silent_on_well_formed_marker(self) -> None:
        findings = lint_text("""// FUN_00123456
void func_00123456(void) { }
""")
        self.assertNotIn("M001", codes(findings))

    def test_fires_on_duplicate_address_in_one_file(self) -> None:
        findings = lint_text("""// FUN_00123456
void func_00123456(void) { }
// FUN_00123456
void func_00123457(void) { }
""")
        self.assertEqual(codes(findings), ["M001"])

    def test_fires_when_guard_disagrees_with_marker(self) -> None:
        findings = lint_text("""#if defined(P4_UNIT_00100000)
// FUN_00100010
void func_00100010(void) { }
#endif /* P4_UNIT_00100000 */
""")
        self.assertEqual(codes(findings), ["M001"])

    def test_silent_when_guard_agrees_with_marker(self) -> None:
        findings = lint_text("""#if defined(P4_UNIT_00100000)
// FUN_00100000
void func_00100000(void) { }
#endif /* P4_UNIT_00100000 */
""")
        self.assertNotIn("M001", codes(findings))


class PragmaBalanceTests(unittest.TestCase):
    def test_fires_on_unmatched_off(self) -> None:
        findings = lint_text("#pragma schedule off\nvoid func_00100000(void) { }\n")
        self.assertIn("P001", codes(findings))

    def test_fires_on_unmatched_on(self) -> None:
        findings = lint_text("#pragma schedule on\nvoid func_00100000(void) { }\n")
        self.assertEqual(codes(findings), ["P001"])

    def test_silent_on_balanced_pair(self) -> None:
        findings = lint_text("""#pragma schedule on
#pragma schedule off
void func_00100000(void) { }
""")
        self.assertNotIn("P001", codes(findings))


class WaiverTests(unittest.TestCase):
    def test_measured_comment_above_site_suppresses(self) -> None:
        findings = lint_text("""// measured: removing this loses FUN_00123456.
#pragma schedule off
void func_00123456(void) { }
""")
        self.assertNotIn("H003", codes(findings))

    def test_lint_allow_suppresses_specific_code(self) -> None:
        findings = lint_text("""// lint: allow H003
#pragma schedule off
void func_00123456(void) { }
""")
        self.assertNotIn("H003", codes(findings))

    def test_lint_allow_other_code_leaves_volatile_firing(self) -> None:
        findings = lint_text("""// lint: allow H003
void func_00123456(void)
{
    volatile int x;
    x = 1;
}
""")
        self.assertIn("H001", codes(findings))

    def test_measured_above_enclosing_marker_suppresses_function_site(self) -> None:
        findings = lint_text("""// measured nd 28: volatile is load-bearing here.
// FUN_00123456
void func_00123456(void)
{
    volatile int x;
    x = 1;
}
""")
        self.assertNotIn("H001", codes(findings))

    def test_waiver_must_be_a_comment_not_code(self) -> None:
        findings = lint_text("""int measured = 0;
#pragma schedule off
void func_00123456(void) { }
""")
        self.assertIn("H003", codes(findings))


class ExclusionTests(unittest.TestCase):
    def test_generated_directory_is_always_excluded(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                generated = Path(directory) / "src" / "generated"
                generated.mkdir(parents=True)
                (generated / "candidate.c").write_text(
                    "#pragma optimization_level 3\nvoid f(void) { }\n", encoding="utf-8")
                (Path(directory) / "src" / "real.c").write_text(
                    "void f(void) { }\n", encoding="utf-8")
                files = lint.gather([Path(directory) / "src"], list(lint.DEFAULT_EXCLUDES))
                self.assertEqual([f.name for f in files], ["real.c"])
            finally:
                lint.ROOT = old_root


class CliTests(unittest.TestCase):
    def test_exit_codes_and_errors_only(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                root = Path(directory)
                err = root / "err.c"
                err.write_text("#pragma schedule off\nvoid f(void) { }\n", encoding="utf-8")
                warn = root / "warn.c"
                warn.write_text("""void f(void)
{
    int x;
    x = 5;
}
""", encoding="utf-8")
                clean = root / "clean.c"
                clean.write_text("void f(void) { }\n", encoding="utf-8")

                # Plain mode lists everything; exit 1 iff an error remains.
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    self.assertEqual(lint.main([str(err)]), 1)
                self.assertIn("[H003]", out.getvalue())

                with contextlib.redirect_stdout(io.StringIO()):
                    self.assertEqual(lint.main([str(warn)]), 0)   # warnings do not fail

                with contextlib.redirect_stdout(io.StringIO()):
                    self.assertEqual(lint.main([str(clean)]), 0)

                # --errors-only hides warnings and still fails on errors.
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    self.assertEqual(lint.main(["--errors-only", str(warn)]), 0)
                self.assertNotIn("H007", out.getvalue())

                with contextlib.redirect_stdout(io.StringIO()):
                    self.assertEqual(lint.main(["--errors-only", str(err)]), 1)
            finally:
                lint.ROOT = old_root


if __name__ == "__main__":
    unittest.main()
