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

    def test_redundant_level_2_is_only_a_warning(self) -> None:
        findings = lint_text("#pragma optimization_level 2\nvoid func_00100000(void) { }\n")
        self.assertEqual(codes(findings), ["H003W"])
        self.assertEqual(findings[0].severity, "warn")

    def test_onboarded_asm_stubs_do_not_hide_an_annotation(self) -> None:
        """A pragma's waiver comes from the annotation above its enclosing marker.

        Onboarding unscanned windows inserts runs of INCLUDE_ASM between an
        existing annotation and the marker it was written for. Those lines are
        other functions' whole bodies, not intervening code, so they must not push
        the annotation out of the waiver window -- otherwise every onboarding batch
        breaks H003 on pragmas nobody touched.
        """
        stubs = "".join(
            f'// FUN_0010{i:04X}\nINCLUDE_ASM("asm/nonmatchings/x", func_0010{i:04x});\n\n'
            for i in range(1, 9))
        text = ("// measured: schedule off is load-bearing for func_00100000.\n"
                + stubs
                + "// FUN_00100000\n"
                + "#pragma schedule off\n"
                + "void func_00100000(void) { }\n")
        self.assertNotIn("H003", codes(lint_text(text)))

    def test_a_run_of_plain_code_still_hides_an_annotation(self) -> None:
        """The skip is specific to INCLUDE_ASM; real code must still break the scan."""
        filler = "".join(f"static int pad{i};\n" for i in range(1, 9))
        text = ("// measured: schedule off is load-bearing for func_00100000.\n"
                + filler
                + "// FUN_00100000\n"
                + "#pragma schedule off\n"
                + "void func_00100000(void) { }\n")
        self.assertIn("H003", codes(lint_text(text)))


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


class AsmBarrierTests(unittest.TestCase):
    """H002: an empty asm template emits nothing."""

    def test_fires_on_empty_template_with_operand(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    asm ("" : "+r"(width));
}
""")
        self.assertIn("H002", codes(findings))
        self.assertNotIn("H009", codes(findings))

    def test_fires_on_volatile_empty_template_with_memory_clobber(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    asm volatile ("" ::: "memory");
}
""")
        self.assertIn("H002", codes(findings))

    def test_fires_on_whitespace_only_template(self) -> None:
        # raw string: the C source must contain a real \n\t escape sequence.
        findings = lint_text(r"""void func_00100000(void)
{
    asm ("\n\t" ::: "memory");
}
""")
        self.assertIn("H002", codes(findings))

    def test_silent_on_template_with_a_real_instruction(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    asm ("sync");
}
""")
        self.assertNotIn("H002", codes(findings))
        self.assertNotIn("H009", codes(findings))

    def test_silent_when_asm_only_appears_in_a_comment(self) -> None:
        findings = lint_text("""/* asm ("" : "+r"(x)) would be cheating, but this is a comment */
void func_00100000(void) { }
""")
        self.assertNotIn("H002", codes(findings))


class InlineAsmTests(unittest.TestCase):
    """H009: inline asm forcing codegen for ordinary computation."""

    def test_fires_on_fpu_arithmetic_template(self) -> None:
        # The exact k_vpad.c shape: adjacent string literals, \n\t separators.
        findings = lint_text(r"""void func_00100000(f32 a, f32 b)
{
    __asm__ volatile (
        "add.s $f2, %2, %3\n\t"
        "mtc1 $zero, $f1\n\t"
        "lw $v0, 0(%1)\n\t"
        :
        : "r"(a), "r"(b)
    );
}
""")
        self.assertIn("H009", codes(findings))
        self.assertNotIn("H002", codes(findings))

    def test_fires_on_load_shift_template(self) -> None:
        findings = lint_text(r"""void func_00100000(void)
{
    __asm__ volatile ("lw %1, 4(%2)\n\tsll %0, %3, 3"
                      : "=r"(offset), "=r"(request)
                      : "r"(work), "r"(i)
                      : "memory");
}
""")
        self.assertIn("H009", codes(findings))

    def test_fires_on_single_line_plain_asm(self) -> None:
        findings = lint_text("""void func_00100000(f32 a, f32 b)
{
    asm ("mul.s $f2, %0, %1" : : "f"(a), "f"(b));
}
""")
        self.assertIn("H009", codes(findings))

    def test_silent_on_privileged_sync_ei(self) -> None:
        findings = lint_text(r"""void func_00100000(void)
{
    __asm__ volatile (
        ".set noreorder\n"
        "sync\n"
        "ei\n"
        ".set reorder"
        :
        :
        : "memory"
    );
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_syscall_trampoline(self) -> None:
        findings = lint_text(r"""void func_00100000(void)
{
    asm volatile (
        "addiu $v1, $zero, 0x41\n"
        "syscall"
    );
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_cop2_moves(self) -> None:
        findings = lint_text(r"""void func_00100000(void)
{
    asm volatile (
        "qmtc2 $v0, $vf1\n"
        "qmfc2 $v1, $vf2"
    );
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_vu_ops(self) -> None:
        findings = lint_text(r"""void func_00100000(void)
{
    asm volatile (
        "vmul.xyzw vf2, vf10, vf11\n"
        "vopmula.xyz ACC, vf10, vf11\n"
        "vadd.xyzw vf10, vf10, vf12"
    );
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_cop2_statement_with_gpr_plumbing(self) -> None:
        # mdlEffect.c shape: addiu address setup feeding lqc2/sqc2 is part
        # of the COP2 idiom, not ordinary computation.
        findings = lint_text(r"""void func_00100000(void)
{
    asm volatile (
        "addiu $v1, $sp, 0x40\n"
        "lqc2 $vf11, 0x0($v1)\n"
        "sqc2 $vf10, 0x0($a2)"
    );
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_qmfc2_statement_with_extract_plumbing(self) -> None:
        # effMisc.c shape: pextuw/sq unwrap a qmfc2 result; the statement is
        # a VU0 extraction idiom.
        findings = lint_text(r"""void func_00100000(void)
{
    asm volatile (
        "qmfc2.ni $5, $vf0\n"
        "pextuw $4, $0, $5\n"
        "sq $4, 32(%0)"
        :
        : "r" (matrix)
        : "$4", "$5", "memory"
    );
}
""")
        self.assertNotIn("H009", codes(findings))


    def test_silent_on_whole_function_asm_body(self) -> None:
        # rw/rwcore_grouped.c shape: asm-qualified function definition with
        # raw retail bytes is not an asm statement and is not policed here.
        findings = lint_text("""// FUN_004222B0
asm u32 QueryIntrContext(void)
{
    .set noreorder
    mfc0 $v0, $12
}
""")
        self.assertNotIn("H009", codes(findings))
        self.assertNotIn("H002", codes(findings))

    def test_silent_when_asm_only_appears_in_a_comment(self) -> None:
        findings = lint_text("""/* asm ("add.s $f2, %0, %1") quoted in prose, not real */
void func_00100000(void) { }
""")
        self.assertNotIn("H009", codes(findings))


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
        findings = lint_text("""void func_00123456(void)
{
    // lint: allow H003
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

    def test_measured_above_site_suppresses_h002(self) -> None:
        findings = lint_text("""void func_00463740(void)
{
    // measured: removing this barrier loses FUN_00463740 (nd10).
    asm ("" : "+r"(width));
}
""")
        self.assertNotIn("H002", codes(findings))

    def test_lint_allow_suppresses_h009(self) -> None:
        findings = lint_text("""void func_00123456(f32 a, f32 b)
{
    // lint: allow H009
    asm ("add.s $f2, %0, %1" : : "f"(a), "f"(b));
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_lint_allow_other_code_leaves_h009_firing(self) -> None:
        findings = lint_text("""void func_00123456(f32 a, f32 b)
{
    // lint: allow H002
    asm ("add.s $f2, %0, %1" : : "f"(a), "f"(b));
}
""")
        self.assertIn("H009", codes(findings))

    def test_measured_above_enclosing_marker_suppresses_h009(self) -> None:
        findings = lint_text(r"""// measured nd 5: the lw/sll pair is load-bearing here.
// FUN_004B5800
void func_004b5800(void)
{
    asm ("lw %0, 4(%1)\n\tsll %2, %3, 3" : : "r"(a), "r"(b), "r"(c), "r"(d));
}
""")
        self.assertNotIn("H009", codes(findings))


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
                for path in (Path(directory) / "src", generated / "candidate.c"):
                    out = io.StringIO()
                    with contextlib.redirect_stdout(out):
                        self.assertEqual(lint.main([str(path), "--include-third-party"]), 0)
                    self.assertNotIn("candidate.c", out.getvalue())
                    self.assertNotIn("[H003]", out.getvalue())
            finally:
                lint.ROOT = old_root


class ThirdPartyScopeTests(unittest.TestCase):
    """Default runs are first-party-only; third-party middleware (rw/, cri/,
    sce/, C runtime) is linted only with --include-third-party and never
    drives the exit code."""

    def _write_tree(self, root: Path) -> None:
        third = root / "src" / "rw"
        third.mkdir(parents=True)
        (third / "rwcore.c").write_text(
            "#pragma optimization_level 3\nvoid rwcore(void) { }\n", encoding="utf-8")
        first = root / "src" / "Battle"
        first.mkdir(parents=True)
        (first / "btlMain.c").write_text(
            "#pragma schedule off\nvoid btlMain(void) { }\n", encoding="utf-8")

    def test_default_mode_excludes_third_party_path(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                root = Path(directory)
                self._write_tree(root)
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    self.assertEqual(lint.main([str(root / "src")]), 1)
                text = out.getvalue()
                self.assertIn("[H003]", text)
                self.assertIn("btlMain.c", text)   # first-party finding reported
                self.assertNotIn("rwcore.c", text)  # third-party finding absent
            finally:
                lint.ROOT = old_root

    def test_include_third_party_includes_it(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                root = Path(directory)
                self._write_tree(root)
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    # First-party error is still present, so the run still fails.
                    self.assertEqual(lint.main(["--include-third-party", str(root / "src")]), 1)
                text = out.getvalue()
                self.assertIn("btlMain.c", text)
                self.assertIn("rwcore.c", text)     # now visible on request
            finally:
                lint.ROOT = old_root

    def test_exit_code_ignores_third_party_errors_in_default_mode(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                root = Path(directory)
                third = root / "src" / "rw"
                third.mkdir(parents=True)
                (third / "rwcore.c").write_text(
                    "#pragma optimization_level 3\nvoid rwcore(void) { }\n", encoding="utf-8")
                clean = root / "src" / "game.c"
                clean.write_text("void game(void) { }\n", encoding="utf-8")
                with contextlib.redirect_stdout(io.StringIO()):
                    self.assertEqual(lint.main([str(root / "src")]), 0)
                # Even with --include-third-party the exit code stays
                # first-party-driven: middleware errors are reported, not fatal.
                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    self.assertEqual(lint.main(["--include-third-party", str(root / "src")]), 0)
                self.assertIn("rwcore.c", out.getvalue())
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

                out = io.StringIO()
                with contextlib.redirect_stdout(out):
                    self.assertEqual(lint.main([str(warn)]), 0)   # warnings do not fail
                self.assertIn("[H007]", out.getvalue())

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




class WholeFunctionAsmTests(unittest.TestCase):
    """H009 for MWCC's `asm void f(void) { ... }` form.

    A body of `.word` literals copied from the retail bytes matches
    byte-for-byte by construction, so nothing else in the campaign can tell it
    from a real result. m2c emits exactly that shape for functions it cannot
    lift.
    """

    def test_fires_on_a_word_blob_of_ordinary_instructions(self) -> None:
        findings = lint_text("""// FUN_003C54A0
asm void func_003c54a0(void)
{
    .set noreorder
    .word 0x3C020003 /* lui */
    .word 0x8C4273E8 /* lw */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}
""")
        self.assertIn("H009", codes(findings))

    def test_silent_on_a_syscall_trampoline(self) -> None:
        # No C expression exists for `syscall`, and MWCC's assembler rejects
        # the mnemonic, so the .word form is the honest representation.
        findings = lint_text("""// FUN_004213C0
asm void func_004213c0(void)
{
    .set noreorder
    .word 0x24030000 /* addiu $v1, $zero, 0 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_a_cop2_blob(self) -> None:
        findings = lint_text("""// FUN_00100000
asm void func_00100000(void)
{
    .word 0x4A000000 /* COP2 */
    .word 0x03E00008
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_silent_on_ordinary_c(self) -> None:
        findings = lint_text("""// FUN_00100000
s32 func_00100000(s32 arg0)
{
    return arg0 + 1;
}
""")
        self.assertNotIn("H009", codes(findings))

    def test_fires_on_mnemonic_form_without_word_directives(self) -> None:
        findings = lint_text("""// FUN_00100000
asm void func_00100000(void)
{
    lw $v0, 0x40($a0)
    jr $ra
    nop
}
""")
        self.assertIn("H009", codes(findings))

    def test_fires_when_a_lone_privileged_op_fronts_a_bulk_transcription(self) -> None:
        # Regression: presence of any hardware op used to whitelist the whole
        # body, so a 130-word transcription of `_start` -- register clears
        # wrapped around a real syscall/ei/sync.p -- linted clean and scored
        # MATCH by construction. The exemption is proportional now.
        clears = "\n".join("    .word 0x%08X" % (0x70001428 + i * 8)
                           for i in range(130))
        findings = lint_text("""// FUN_00100008
asm void func_00100008(void)
{
    .set noat
    syscall
    sync.p
    ei
%s
}
""" % clears)
        self.assertIn("H009", codes(findings))


    def test_word_decoder_separates_hardware_from_computation(self) -> None:
        self.assertTrue(lint._word_is_hardware(0x0000000C))    # syscall
        self.assertTrue(lint._word_is_hardware(0x40026000))    # mfc0
        self.assertTrue(lint._word_is_hardware(0x4A000000))    # COP2
        self.assertFalse(lint._word_is_hardware(0x24030000))   # addiu
        self.assertFalse(lint._word_is_hardware(0x8C420040))   # lw
        self.assertFalse(lint._word_is_hardware(0x46000000))   # COP1 float



class NonMatchingBlockTests(unittest.TestCase):
    """`#ifdef NON_MATCHING` holds preserved reference C that never compiles.

    Skipping it must not blind the linter to the `#else` arm, which DOES build,
    or to anything after the `#endif`.
    """

    BODY = (
        "// FUN_00100010 NONMATCHING\n"
        "#ifdef NON_MATCHING\n"
        "s32 func_00100010(void)\n"
        "{\n"
        "    s32 unused;\n"
        "    unused = compute();\n"
        "    return 0;\n"
        "}\n"
        "#else\n"
        'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
        "#endif\n"
    )

    def test_dead_store_in_reference_block_is_not_reported(self) -> None:
        self.assertNotIn("H007", codes(lint_text(self.BODY)))
        active = self.BODY.replace("#ifdef NON_MATCHING", "#if 1")
        self.assertIn("H007", codes(lint_text(active)))

    def test_violation_in_the_else_arm_is_still_reported(self) -> None:
        """The #else arm is what actually compiles, so it stays linted."""
        text = self.BODY.replace(
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);',
            "#pragma optimization_level 3\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);',
        )
        self.assertIn("H003", codes(lint_text(text)))

    def test_violation_after_the_endif_is_still_reported(self) -> None:
        text = self.BODY + (
            "\n// FUN_00100020\n"
            "void func_00100020(void)\n"
            "{\n"
            "    register s32 pinned;\n"
            "    pinned = 1;\n"
            "    use(pinned);\n"
            "}\n"
        )
        self.assertIn("H008", codes(lint_text(text)))

    def test_nested_ifdef_inside_the_block_does_not_leak(self) -> None:
        """A nested #if must not end the skip early at its own #endif."""
        text = (
            "// FUN_00100010 NONMATCHING\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n"
            "{\n"
            "#if 1\n"
            "    compute();\n"
            "#endif\n"
            "    s32 unused;\n"
            "    unused = compute();\n"
            "    return 0;\n"
            "}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
            "\n// FUN_00100020\n"
            "void func_00100020(void)\n"
            "{\n"
            "    register s32 pinned;\n"
            "    pinned = 1;\n"
            "    use(pinned);\n"
            "}\n"
        )
        found = codes(lint_text(text))
        self.assertNotIn("H007", found)
        self.assertIn("H008", found, "the function after #endif must still be linted")
        active = text.replace("#ifdef NON_MATCHING", "#if 1")
        self.assertIn("H007", codes(lint_text(active)))


if __name__ == "__main__":
    unittest.main()
