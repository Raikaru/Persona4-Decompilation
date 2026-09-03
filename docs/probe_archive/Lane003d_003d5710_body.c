/* Lane003d archive: func_003d5710
 * object 60B / window 64B / best normalized_diff 6
 * differing offsets (reloc-masked): 4, 8, 12, 48, 52, 56-60 (trailing)
 * retail:  addiu $sp,-0x20; move $v0,$zero; sd $ra,0x10($sp); sq $s0,0($sp);
 *          addiu $s0,$v0,0x14; lw $v0,($a0); lw $v0,0x28($v0); jalr $v0;
 *          nop; addu $v0,$s0,$v0; ld $ra,0x10($sp); lq $s0,0($sp); jr $ra;
 *          addiu $sp,0x20; nop; nop
 * object:  addiu $sp,-0x20; sd $ra,0x10($sp); sq $s0,0($sp); move $v0,$zero;
 *          addiu $s0,$v0,0x14; lw $v0,($a0); lw $v0,0x28($v0); jalr $v0;
 *          nop; addu $v0,$s0,$v0; ld $ra,0x10($sp); lq $s0,0($sp);
 *          addiu $sp,0x20; jr $ra; nop
 * Residual: prologue and epilogue scheduling. Retail keeps the v0=zero setup
 * in the addiu $sp delay slot and fills the jr delay slot with the sp restore;
 * MWCC b210 (,-p) puts the sd $ra / sq $s0 as the earliest prologue instructions
 * and emits the addiu $sp before the jr. Adding #pragma schedule on fixes the
 * prologue/epilogue but moves addiu $s0 into the jalr delay slot and renames
 * the zero temporary to $v1, resulting in a larger 13-word residual.
 * Levers tried:
 *   - inline return expression, with/without u8** cast
 *   - explicit `s32 add = 0x14` and `s32 res` locals
 *   - explicit `s32 zero = 0` to reproduce the move/addiu s0 pattern
 *   - #pragma opt_propagation off (required to keep `add` as a real saved local)
 *   - #pragma schedule on/off
 *   - #pragma no_branch_likely on/off
 * Best: opt_propagation off, schedule off; remaining 6 words are scheduling.
 * Restored to bare INCLUDE_ASM.
 */
/* measured: opt_propagation off only; schedule off keeps addiu s0 before the jalr. */
#pragma opt_propagation off
// FUN_003D5710 NONMATCHING
s32 func_003d5710(u8 **arg0) {
    s32 zero = 0;
    s32 add = zero + 0x14;
    s32 (*fp)(void) = (s32 (*)(void))*(s32 *)(*arg0 + 0x28);
    s32 res = fp();
    return add + res;
}
/* measured: closes opt_propagation around func_003d5710. */
#pragma opt_propagation on
