from __future__ import annotations

import contextlib
import importlib.util
import io
import json
import os
import tempfile
import unittest
from pathlib import Path
from unittest import mock

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
        self.assertEqual(next(f.severity for f in findings if f.code == "H001"), "warn")

    def test_silent_on_hardware_mmio_address(self) -> None:
        findings = lint_text("""void func_00100000(void)
{
    *(volatile u32 *)0x1F801000 = 1;
}
""")
        self.assertNotIn("H001", codes(findings))

    def test_scalar_hardware_value_does_not_establish_mmio_context(self) -> None:
        self.assertIn("H001", codes(lint_text("volatile int x = 0x10000000;\n")))

    def test_silent_on_volatile_inside_comment(self) -> None:
        findings = lint_text("""/* volatile on purpose, but this is only a comment */
void func_00100000(void) { }
""")
        self.assertNotIn("H001", codes(findings))


class PragmaAdvisoryTests(unittest.TestCase):
    def test_nonstandard_optimization_and_steering_are_advisory(self) -> None:
        for form in ("optimization_level 4", "schedule off", "opt_common_subs off",
                     "opt_loop_invariants on"):
            with self.subTest(pragma=form):
                findings = lint_text(f"#pragma {form}\nvoid f(void) {{ }}\n")
                self.assertEqual([(f.code, f.severity) for f in findings], [("H003", "warn")])

    def test_ordinary_optimization_setting_is_clean(self) -> None:
        self.assertEqual(lint_text("#pragma optimization_level 2\nvoid f(void) { }\n"), [])
    def test_annotation_does_not_cross_other_function_markers(self) -> None:
        text = ('// measured: schedule off was needed for the first function.\n'
                '// FUN_00100000\n'
                'INCLUDE_ASM("asm/nonmatchings/x", func_00100000);\n'
                '// FUN_00100010\n'
                '#pragma schedule off\n'
                'void func_00100010(void) { }\n')
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

    def test_pure_compiler_memory_barrier_is_legitimate(self) -> None:
        findings = lint_text('void f(void) { asm volatile ("" ::: "memory"); }\n')
        self.assertNotIn("H002", codes(findings))
        self.assertNotIn("H009", codes(findings))

    def test_memory_clobber_does_not_legitimize_operand_barrier(self) -> None:
        findings = lint_text(r'void f(void) { asm ("\n\t" : "+r"(x) :: "memory"); }')
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
        # Privileged whole-function bodies are legitimate hardware operations.
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
        for marker in ("// FUN_00123", "// FUN_", "// FUN_001234567", "// FUN_00123456junk"):
            with self.subTest(marker=marker):
                findings = lint_text(f"{marker}\nvoid func_00100000(void) {{ }}\n")
                self.assertIn("M001", codes(findings))

    def test_silent_on_well_formed_marker(self) -> None:
        for suffix in (" MATCH size=32", ". Describe this function."):
            with self.subTest(suffix=suffix):
                findings = lint_text(f"// FUN_00123456{suffix}\nvoid func_00123456(void) {{ }}\n")
                self.assertNotIn("M001", codes(findings))

    def test_fires_on_duplicate_address_in_one_file(self) -> None:
        findings = lint_text("""// FUN_00123456
void func_00123456(void) { }
// FUN_00123456
void func_00123457(void) { }
""")
        self.assertEqual(codes(findings), ["M001"])


class PragmaBalanceTests(unittest.TestCase):
    def test_on_off_are_settings_not_a_stack(self) -> None:
        findings = lint_text("#pragma schedule on\n#pragma schedule off\n#pragma schedule off\n")
        self.assertNotIn("P001", codes(findings))

    def test_balanced_push_pop(self) -> None:
        self.assertNotIn("P001", codes(lint_text("#pragma push\n#pragma push\n#pragma pop\n#pragma pop\n")))

    def test_unclosed_push(self) -> None:
        self.assertIn("P001", codes(lint_text("#pragma push\n")))

    def test_pop_before_push_is_not_cancelled_by_later_push(self) -> None:
        findings = lint_text("#pragma pop\n#pragma push\n")
        self.assertEqual([f.line for f in findings if f.code == "P001"], [1, 2])


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

    def test_measured_comment_does_not_suppress_h002(self) -> None:
        findings = lint_text("""void func_00463740(void)
{
    // measured: removing this barrier loses FUN_00463740 (nd10).
    asm ("" : "+r"(width));
}
""")
        self.assertIn("H002", codes(findings))

    def test_lint_allow_suppresses_h009(self) -> None:
        findings = lint_text("""void func_00123456(f32 a, f32 b)
{
    // lint: allow H009 -- unsupported hardware wrapper
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

    def test_measured_above_marker_does_not_suppress_h009(self) -> None:
        findings = lint_text(r"""// measured nd 5: the lw/sll pair is load-bearing here.
// FUN_004B5800
void func_004b5800(void)
{
    asm ("lw %0, 4(%1)\n\tsll %2, %3, 3" : : "r"(a), "r"(b), "r"(c), "r"(d));
}
""")
        self.assertIn("H009", codes(findings))


class ExclusionTests(unittest.TestCase):
    def test_generated_directory_is_always_excluded(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            old_root = lint.ROOT
            lint.ROOT = Path(directory)
            try:
                generated = Path(directory) / "src" / "generated"
                generated.mkdir(parents=True)
                (generated / "candidate.c").write_text(
                    'void f(void) { asm ("addu $v0, $a0, $a1"); }\n', encoding="utf-8")
                (Path(directory) / "src" / "real.c").write_text(
                    "void f(void) { }\n", encoding="utf-8")
                for path in (Path(directory) / "src", generated / "candidate.c"):
                    out = io.StringIO()
                    with contextlib.redirect_stdout(out):
                        self.assertEqual(lint.main([str(path), "--include-third-party"]), 0)
                    self.assertNotIn("candidate.c", out.getvalue())
                    self.assertNotIn("[H009]", out.getvalue())
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
            'void rwcore(void) { asm ("addu $v0, $a0, $a1"); }\n', encoding="utf-8")
        first = root / "src" / "Battle"
        first.mkdir(parents=True)
        (first / "btlMain.c").write_text(
            'void btlMain(void) { asm ("addu $v0, $a0, $a1"); }\n', encoding="utf-8")

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
                self.assertIn("[H009]", text)
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
                    'void rwcore(void) { asm ("addu $v0, $a0, $a1"); }\n', encoding="utf-8")
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
                err.write_text("// FUN_bad\nvoid f(void) { }\n", encoding="utf-8")
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
                self.assertIn("[M001]", out.getvalue())

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
            '    asm ("addu $v0, $a0, $a1");\n'
            "}\n"
        )
        self.assertIn("H009", codes(lint_text(text)))

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
            '    asm ("addu $v0, $a0, $a1");\n'
            "}\n"
        )
        found = codes(lint_text(text))
        self.assertNotIn("H007", found)
        self.assertIn("H009", found, "the function after #endif must still be linted")
        active = text.replace("#ifdef NON_MATCHING", "#if 1")
        self.assertIn("H007", codes(lint_text(active)))


class AssemblyParsingTests(unittest.TestCase):
    def forms(self, body):
        yield 'void f(void) { asm (' + json.dumps(body) + '); }\n'
        yield 'asm void f(void) {\n' + body + '\n}\n'

    def test_same_line_labels_do_not_hide_computation(self) -> None:
        for source in self.forms("entry: addu $v0, $a0, $a1"):
            with self.subTest(source=source):
                self.assertIn("H009", codes(lint_text(source)))

    def test_encoded_instructions_obey_hardware_policy_in_both_forms(self) -> None:
        for body, prohibited in (("entry: .word 0x8C420040", True),
                                 ("entry: .word 0x0000000C", False)):
            for source in self.forms(body):
                with self.subTest(source=source):
                    self.assertEqual("H009" in codes(lint_text(source)), prohibited)

    def test_hardware_plumbing_is_bounded_in_both_forms(self) -> None:
        bodies = (
            ("sync\n" + "addu $v0, $a0, $a1\n" * 16, False),
            ("sync\n" + "addu $v0, $a0, $a1\n" * 17, True),
            ("sync\n" * 3 + "addu $v0, $a0, $a1\n" * 24, False),
            ("sync\n" * 3 + "addu $v0, $a0, $a1\n" * 25, True),
        )
        for body, prohibited in bodies:
            for source in self.forms(body):
                with self.subTest(source=source):
                    self.assertEqual("H009" in codes(lint_text(source)), prohibited)

    def test_comments_between_string_fragments_are_not_template_boundaries(self) -> None:
        findings = lint_text(r'''void f(void) {
    asm (/* start */ "" /* continue */ "addu $v0, $a0, $a1");
}''')
        self.assertIn("H009", codes(findings))
        self.assertNotIn("H002", codes(findings))

    def test_commented_template_barrier_is_still_detected(self) -> None:
        self.assertIn("H002", codes(lint_text(
            'void f(void) { asm (/* template */ "" /* operands */ : "+r"(x)); }')))


    def test_unparsed_templates_are_not_silently_accepted(self) -> None:
        self.assertIn("H009", codes(lint_text("void f(void) { asm (ASM_TEMPLATE); }")))
        for source in self.forms(".word UNKNOWN_ENCODING"):
            with self.subTest(source=source):
                self.assertIn("H009", codes(lint_text(source)))


class WaiverBoundaryTests(unittest.TestCase):
    def test_measured_comment_can_waive_dead_store_advisory(self) -> None:
        findings = lint_text("void f(void) {\nint x;\n"
                             "// measured: retail retains the dead store\nx = 5;\n}\n")
        self.assertNotIn("H007", codes(findings))

    def test_integrity_waivers_require_specific_rule_and_nonempty_reason(self) -> None:
        for annotation in ("// lint: allow H009", "// lint: allow H009 --",
                           "// lint: allow H009:", "// lint: allow H002 -- justified"):
            with self.subTest(annotation=annotation):
                source = 'void f(void) {\n' + annotation + '\nasm ("addu $v0, $a0, $a1");\n}'
                self.assertIn("H009", codes(lint_text(source)))

    def test_reasoned_integrity_waiver_allows_allocation_barrier(self) -> None:
        findings = lint_text('void f(void) {\n// lint: allow H002: documented exception\n'
                             'asm ("" : "+r"(x));\n}')
        self.assertNotIn("H002", codes(findings))

    def test_string_contents_cannot_supply_waivers(self) -> None:
        findings = lint_text('void f(void) {\n'
                             'const char *s = "// lint: allow H009 -- exception";\n'
                             'asm ("addu $v0, $a0, $a1");\n}')
        self.assertIn("H009", codes(findings))
        findings = lint_text('volatile const char *label = "measured";\n')
        self.assertIn("H001", codes(findings))

    def test_waivers_do_not_cross_unmarked_function_boundaries(self) -> None:
        findings = lint_text('void first(void) {\n// measured: evidence for first\n}\n'
                             'void second(void) {\nvolatile int x;\nuse(&x);\n}\n')
        self.assertIn("H001", codes(findings))

    def test_comment_after_string_is_recognized_lexically(self) -> None:
        findings = lint_text('void f(void) {\nconst char *s = "text"; // lint: allow H009 -- exception\n'
                             'asm ("addu $v0, $a0, $a1");\n}')
        self.assertNotIn("H009", codes(findings))

    def test_marker_waiver_ends_at_assembly_fallback(self) -> None:
        findings = lint_text('// lint: allow H009 -- hardware fallback exception\n'
                             '// FUN_00100000\n'
                             'INCLUDE_ASM("asm/nonmatchings/x", func_00100000);\n'
                             'void second(void) { asm("addu $v0, $a0, $a1"); }\n')
        self.assertIn("H009", codes(findings))


class PreprocessorRegressionTests(unittest.TestCase):
    def test_elif_restores_active_analysis(self) -> None:
        findings = lint_text('#ifdef NON_MATCHING\n#pragma schedule off\n'
                             '#elif defined(OTHER_MODE)\n#pragma optimization_level 4\n'
                             '#else\n#pragma opt_common_subs off\n#endif\n')
        self.assertEqual([f.line for f in findings if f.code == "H003"], [4, 6])

    def test_nonmatching_macro_prefix_is_not_reference_code(self) -> None:
        self.assertIn("H003", codes(lint_text(
            "#ifdef NON_MATCHING_EXTRA\n#pragma schedule off\n#endif\n")))

    def test_commented_directives_do_not_change_reference_state(self) -> None:
        findings = lint_text('/*\n#ifdef NON_MATCHING\n*/\n#pragma schedule off\n')
        self.assertEqual([f.line for f in findings if f.code == "H003"], [4])

    def test_continued_comments_preserve_physical_line_numbers(self) -> None:
        findings = lint_text('// continued \\\n#pragma schedule off\n#pragma optimization_level 4\n')
        self.assertEqual([f.line for f in findings if f.code == "H003"], [3])
        findings = lint_text('// continued \\\n#ifdef NON_MATCHING\n#pragma schedule off\n')
        self.assertEqual([f.line for f in findings if f.code == "H003"], [3])

    def test_inactive_pragmas_neither_leak_nor_cancel_active_stack(self) -> None:
        findings = lint_text('#ifdef NON_MATCHING\n#pragma push\n#pragma schedule off\n#endif\n')
        self.assertEqual(findings, [])
        findings = lint_text('#pragma push\n#ifdef NON_MATCHING\n#pragma pop\n#endif\n')
        self.assertEqual([f.line for f in findings if f.code == "P001"], [1])


class ScanFailureTests(unittest.TestCase):
    def test_missing_input_remains_fatal_under_filters_and_json(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            missing = Path(directory) / "missing.c"
            report = Path(directory) / "report.json"
            for options in ([], ["--select", "H001", "--errors-only"], ["--json", str(report)]):
                with self.subTest(options=options):
                    out, err = io.StringIO(), io.StringIO()
                    with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
                        status = lint.main([str(missing), *options])
                    self.assertNotEqual(status, 0)
                    self.assertIn("missing.c", out.getvalue() + err.getvalue())
                    if "--json" in options:
                        self.assertTrue(json.loads(report.read_text())["scan_errors"])

    def test_unreadable_requested_file_is_visible_and_fatal(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "unreadable.c"
            path.write_text("void f(void) {}\n", encoding="utf-8")
            original = Path.read_bytes

            def read_bytes(candidate):
                if candidate.resolve() == path.resolve():
                    raise PermissionError("fixture access denied")
                return original(candidate)

            out, err = io.StringIO(), io.StringIO()
            with mock.patch.object(Path, "read_bytes", read_bytes):
                with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
                    status = lint.main([str(path), "--select", "H001", "--errors-only"])
            self.assertNotEqual(status, 0)
            self.assertIn("unreadable.c", out.getvalue() + err.getvalue())

    def test_relative_paths_keep_third_party_ownership(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / "src" / "rw" / "candidate.c"
            path.parent.mkdir(parents=True)
            path.write_text("// FUN_bad\nvoid f(void) {}\n", encoding="utf-8")
            old_root, old_cwd = lint.ROOT, Path.cwd()
            lint.ROOT = root
            try:
                os.chdir(root / "src")
                for spelling in (str(path), "rw/candidate.c", "../src/rw/candidate.c"):
                    with self.subTest(path=spelling):
                        out = io.StringIO()
                        with contextlib.redirect_stdout(out):
                            self.assertEqual(lint.main([spelling]), 0)
                        self.assertNotIn("[M001]", out.getvalue())
                        out = io.StringIO()
                        with contextlib.redirect_stdout(out):
                            self.assertEqual(lint.main([spelling, "--include-third-party"]), 0)
                        self.assertIn("[M001]", out.getvalue())
            finally:
                os.chdir(old_cwd)
                lint.ROOT = old_root


if __name__ == "__main__":
    unittest.main()
