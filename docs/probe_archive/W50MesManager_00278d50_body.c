/* W50MesManager func_00278d50 best honest plain-C body (not closed).
 *
 * Measured with MWCCPS2 b210 through tools/verify.py:
 *   object_size=84B; retail_window=80B; normalized_diff=58.
 * tools/fndiff.py reports 19 differing words after relocation masking;
 * verify.py first_diffs (byte offsets) =
 *   0,4,8,9,10,11,12,13,14,15,16,18,19,20,22,23.
 * fndiff differing word offsets =
 *   0,4,8,12,16,20,24,28,32,36,44,52,56,60,64,68,72,76,80.
 * The relocation-owned call word at offset 48 is equal after masking.
 * Retail uses frame -0x10 and keeps arg0 in $t3 across func_00278c60;
 * the natural candidate uses frame -0x20 and spills arg0 in $s0 across the
 * call, accounting for the 4-byte prologue difference and the short tail.
 *
 * Probes A-P retained normalized_diff=58 for the target across inline versus
 * local pointer/address forms, register declaration, legal local optimization
 * pragmas (opt_propagation, opt_common_subs, opt_loop_invariants,
 * optimization_level, schedule, optimize_for_size, cse_hard_reg_gpr,
 * cse_hard_reg_special, opt_pointer_analysis), and equivalent local forms.
 * Pointer-to-integer parameter probes and restrict syntax were rejected by
 * MWCC; the loop-invariants probe also affected a subsequent function and was
 * not retained. No inline asm, volatile, intrinsic, or pragma steering is
 * required or used by this body.
 */
void func_00278d50(u8 *arg0)
{
    u8 *base;

    if (*(u8 *)(arg0 + 0x1C) == 0) {
        base = arg0 + 0x20;
        func_00278c60((int *)base, (int)base, arg0 + *(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x14));
        *(u8 *)(arg0 + 0x1C) = 1;
    }
}
