/* Lane003d archive: func_003d59a0
 * object 48B / window 48B / best normalized_diff 6
 * differing offsets (reloc-masked): 4, 8, 12, 16, 20, 28
 * retail:  addiu $sp,-0x10; sd $ra,(sp); lw $v1,0x24($a0); lw $v0,0x2c($a0);
 *          mult $a2,$v1,$v0; addiu $a0,$a0,0x4c; jal func_0043f810;
 *          addiu $a1,$a1,0x4c; ld $ra,(sp); li $v0,1; jr $ra; addiu $sp,0x10
 * object:  addiu $sp,-0x10; addiu $a1,$a1,0x4c; sd $ra,(sp); lw $v1,...; lw $v0,...;
 *          mult $a2,$v1,$v0; jal ...; addiu $a0,$a0,0x4c; ...
 * Residual: call-argument setup order before JAL. Retail computes arg0+0x4c
 * before the jal and puts arg1+0x4c in the jal delay slot; MWCC b210 (,-p)
 * consistently hoists the arg1 addiu to the prologue area and puts arg0+0x4c
 * in the jal delay slot. Levers tried:
 *   - plain C with/without u8* dst/u8* src/s32 size locals
 *   - #pragma schedule on/off
 *   - #pragma peephole off/on
 *   - #pragma opt_propagation off/on
 *   - casting first/second call args to s32 / block-scope s32 prototype
 *   - explicit `arg1 = arg1 + 0x4c` statement
 * None reproduced the retail arg0-before-jal / arg1-in-delay-slot order.
 * Restored to bare INCLUDE_ASM.
 */
/* measured: schedule on moves the pointer addiu instructions into the jal and jr delay slots. */
#pragma schedule on
// FUN_003D59A0 NONMATCHING
s32 func_003d59a0(u8 *arg0, u8 *arg1) {
    func_0043f810(arg0 + 0x4c, arg1 + 0x4c, *(s32 *)(arg0 + 0x24) * *(s32 *)(arg0 + 0x2c));
    return 1;
}
/* measured: closes schedule around func_003d59a0. */
#pragma schedule off
