/* object 156B, window 160B, normalized_diff 20; differing offsets 0x44,0x48,0x4C,0x50,0x54,0x60,0x70 (reloc-masked). Corrected classification: retail 0x44-0x54 is the literal-5 store sequence `li $a0,5; move $v1,$s2; lui $v0,2; addu $v0,$v1,$v0; sw $a0,-0x295c($v0)`, not one call's argument set; 0x60 is the second-call `addu $a0,$s2,$at`, and 0x70 is the final-store `move $a0,$s2`. Candidate emits `li $v1,5; lui $v0,2; addu $v0,$s2,$v0; sw $v1,-0x295c($v0)`, recomputes the base for the second call, and emits `addu $a0,$s0,$s1` for the final base. Newly ruled out: full named store/value/base staging and call-argument locals (either optimized back to nd20 or shrink to 128/152B), all declaration permutations tested, opt_propagation off, schedule off (leaked to siblings and reverted), plus prior direct p+ second-call/final-store forms, integer-domain address locals, duplicated-base locals, named constant/value locals, pointer staging locals, declaration-order swaps, and retail-operand-order recomputation; no conversion sites/casts required. */
void func_00375f00(u8 *arg0, s32 arg1) {
    s32 idx;
    u8 *p;
    idx = arg1 * 0xE8;
    p = (u8 *)((u32)arg0 + (u32)idx);
    func_00370410(p + 0x1D6AC);
    *(s32 *)(p + 0x1D6A4) = 5;
    func_00370a80((u8 *)idx + (u32)arg0 + 0x1D70C);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A8) = 3;
}
