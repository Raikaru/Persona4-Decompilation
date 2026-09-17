/*
 * Probe archive for func_00164880 (0x00164880, 1728B window, src/promoted/k_fldUnit.c).
 * Best measured candidate: local/p4_00164880/best_push.c (w5d lineage).
 *   probe_variants: 313 differing words (reloc-masked) vs L003b baseline 370.
 *   fnalign: 422 emitted instrs vs 431 retail (9 short), 124 edits + 4 reloc-only.
 *   object_size 1688B vs 1728B window (40B short, no zero-tail claim).
 *   relocations 45/45, 0 unresolved; all resolve to retail symbols/addends
 *     (001452b0 x5, 0015a160, 0014a200, 00164f40 x4, D_007EF9B0 x6 pairs,
 *      0047a2f0 x9, 003e4180 x5, 0014cfd0 x2, D_007E8C00 x2 pairs,
 *      0014a270, 003b7060); HI/LO addends 0x0000 match retail.
 *   compiler/context: MWCCPS2 3.0.1 b210 at -O2 (k_fldUnit in no
 *     compiler/speed/gcc unit list); scoped opt_common_subs/propagation off.
 * Wins vs L003b (370 words / 353 instrs):
 *   - genuine 3-float aggregates (Frame v70/v80/v90/vA0 with 4B pads) restore
 *     all 12 vector stores; sibling code1_0014 Frame pattern copied
 *     (v40/v50/v60 + temp_f21/f20 reloads for y/z, x reloaded from stack).
 *   - frame 0xB0 and sd/sq/swc1 save set now byte-identical in shape
 *     (s0-s3 + f20-f24); float arg back in $f23 (was $f21).
 *   - block-scope `extern u32 func_003b7060(void)` removes dsll32/dsra32 and
 *     restores retail divu/mfhi (file-scope u64 forced 64-bit modulo).
 *   - opt_common_subs/propagation off rematerialises the per-iteration
 *     D_007EF9B0 slot mult (was CSE into one); slot+0x50 pointer temp
 *     restores retail lw 0x50(base) then lw (ptr) split.
 *   - grouped tx/ty/tz loads restore retail lwc1 f2/f1/f0 triple.
 *   - store/index/reload order (index init before y/z reload) + reverse
 *     var_16-last declaration close the arg1/best s0/s1 swap and part of
 *     the index s1/s2 swap (w3e 321, w4a 316, w5b 313).
 * Walls (bounded, measured; production stays ASM):
 *   - sltu $v0,$zero,$a0 + beqz for the 0x48/0x54 flag (3 sites) vs
 *     candidate beqz $a0: swept 7 cond shapes (flag!=0, ==1, >0, 0<flag,
 *     (u32)flag!=0, (u32)flag>0U, ==0) and 4 decl types (s32/u32/int/
 *     unsigned) in isolated loop probes -- all emit beqz; sibling W47
 *     001679d0 floor (ready=0/if&&/ready=1/if!=0) hits the same retail sltu.
 *   - outer/inner entry `b' vs `sltiu+beqz' and `sltiu+bnez' vs `b':
 *     for-loop and goto-check rewrites of the 4-loop regress (w5a 334,
 *     w5c 331 vs w4a 316); count-loop goto-check is neutral in words
 *     (313) but improves edits 155->124 (w5d).
 *   - 3-nop count-loop alignment pad, mfhi s0 vs s2, and remaining
 *     s1/s2 outer/index rotation: declaration permutations of
 *     var_16/var_17/var_18/var_19/var_2 (4 orders, best reverse 321) and
 *     index-after-pointers moves (w4a 316) plateau; further permutation
 *     without a new type/CFG fact is not justified.
 *   - branch-target deltas throughout are secondary to the above
 *     instruction-count deltas.
 * Semantic gate (active-C target, not fallback):
 *   - ABI: (s32 unused, u32 count, f32 minDist) matches retail
 *     (a0 clobbered, a1 in s1, f12 in f23) and the three callers in
 *     func_00164570 (0xBB8/0x1770/var_f20 thresholds); first param stays
 *     declared but unused as retail proves.
 *   - providers: 001452b0(s32)->u8*, 0015a160()->s32, 0014a200/0014a270()->s32,
 *     00164f40()->s32 (iGpffffb2e8), 003b7060()->u32 (block-scope shadow;
 *     file-scope u64 would force 64-bit %), 0014cfd0(u8*)->s32, 003e4180(f32[3])
 *     ->f32, 0047a2f0(s32)->u8*; D_007EF9B0/D_007E8C00 are 0x750-stride
 *     tables (0x48/0x54 flags, 0x50 model ptr, 0x1AC unit ptr).
 *   - no UB/volatile/asm/padding; vector extents preserved via Frame;
 *     short-circuit && preserved; mutation-sensitive loads not hoisted
 *     across 0047a2f0/003e4180.
 * Ghidra/IDA headstarts for code1_0016 contain no 00164880 body (only
 * 001604a0/00160880/00162680/0016b8a0/0016bdd0/0016e2e0/0016e590/0016f3b0/
 * 0016f8b0); M2C P4_UNIT_00164880 (237 lines, src/generated/code1_0016.c)
 * and L003b were the prior hypotheses. Re-measured, not trusted blindly.
 * The live source was left on INCLUDE_ASM after this archive.
 */
// FUN_00164880
s32 func_0014cfd0(u8 *arg0);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
u8 *func_00164880(s32 unused, u32 arg1, f32 arg2)
{
    struct Frame {
        f32 v70[3];
        u8 pad7C[4];
        f32 v80[3];
        u8 pad8C[4];
        f32 v90[3];
        u8 pad9C[4];
        f32 vA0[3];
        u8 padAC[4];
    } frame;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 var_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 tx;
    f32 ty;
    f32 tz;
    s32 var_16_3;
    s32 var_18_2;
    s32 var_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    u32 temp_16;
    u32 var_16_2;
    u32 var_17_3;
    u32 var_17_4;
    u32 var_18_3;
    u8 *temp_17;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *var_2;
    u8 *var_19;
    u8 *var_18;
    u8 *var_17;
    u32 var_17_2;
    u8 *var_16;
    extern u32 func_003b7060(void);

    func_001452b0(0xF);
    var_16 = NULL;
    func_0015a160();
    var_f22 = 1.1754944e-38f;
    if (func_0014a200() == 1) {
        if (func_00164f40() < (s32)arg1) {
            var_18 = func_001452b0(0xF);
loop_44:
            if (var_18 == NULL) goto block_71;
            tx = *(f32 *)(var_18 + 0x140);
            ty = *(f32 *)(var_18 + 0x144);
            tz = *(f32 *)(var_18 + 0x148);
            frame.vA0[0] = tx;
            frame.vA0[1] = ty;
            frame.vA0[2] = tz;
            var_17_2 = 0;
            temp_f21 = frame.vA0[1];
            temp_f20 = frame.vA0[2];
loop_10:
            if (var_17_2 < 4U) {
                var_4 = 0;
                temp_3 = D_007EF9B0 + var_17_2 * 0x750;
                if (*(s32 *)(temp_3 + 0x48) != 0 && *(s32 *)(temp_3 + 0x54) != 0) var_4 = 1;
                if (var_4 != 0) {
                    temp_2 = D_007EF9B0 + var_17_2 * 0x750;
                    {
                        u8 *slot50 = temp_2 + 0x50;
                        temp_2_2 = func_0047a2f0(*(s32 *)(temp_2 + 0x50));
                        frame.v90[0] = frame.vA0[0] - *(f32 *)(temp_2_2 + 0x30);
                        temp_2_3 = func_0047a2f0(*(s32 *)slot50);
                        frame.v90[1] = temp_f21 - *(f32 *)(temp_2_3 + 0x34);
                        temp_2_4 = func_0047a2f0(*(s32 *)slot50);
                        frame.v90[2] = temp_f20 - *(f32 *)(temp_2_4 + 0x38);
                    }
                    if (func_003e4180(frame.v90) < 3000.0f) goto loop_12;
                }
                var_17_2 += 1;
                goto loop_10;
            }
loop_12:
            if (var_17_2 < 4U) {
                var_18 = *(u8 **)(var_18 + 0x138);
                goto loop_44;
            }
            if (func_00164f40() == 0) {
loop_14:
                var_16_2 = 0;
                var_18_2 = 0;
                var_2 = func_001452b0(0xF);
                goto loop_16_check;
loop_16_body:
                    var_16_2 += 1;
                    var_2 = *(u8 **)(var_2 + 0x138);
loop_16_check:
                if (var_2 != NULL) goto loop_16_body;
                temp_16 = func_003b7060() % var_16_2;
                var_17 = func_001452b0(0xF);
                var_3 = 0;
loop_19:
                if (var_3 < (s32)temp_16) {
                    var_17 = *(u8 **)(var_17 + 0x138);
                    var_3 += 1;
                    goto loop_19;
                }
                var_16_3 = 0;
loop_27:
                if (var_16_3 < 4) {
                    var_4_2 = 0;
                    temp_3_2 = D_007EF9B0 + var_16_3 * 0x750;
                    if (*(s32 *)(temp_3_2 + 0x48) != 0 && *(s32 *)(temp_3_2 + 0x54) != 0) var_4_2 = 1;
                    if (var_4_2 != 0) {
                        temp_2_2 = D_007EF9B0 + var_16_3 * 0x750;
                        {
                            u8 *slot50 = temp_2_2 + 0x50;
                            temp_2_3 = func_0047a2f0(*(s32 *)(temp_2_2 + 0x50));
                            frame.v90[0] = *(f32 *)(var_17 + 0x140) - *(f32 *)(temp_2_3 + 0x30);
                            temp_2_4 = func_0047a2f0(*(s32 *)slot50);
                            frame.v90[1] = *(f32 *)(var_17 + 0x144) - *(f32 *)(temp_2_4 + 0x34);
                            temp_2_5 = func_0047a2f0(*(s32 *)slot50);
                            frame.v90[2] = *(f32 *)(var_17 + 0x148) - *(f32 *)(temp_2_5 + 0x38);
                        }
                        if (func_003e4180(frame.v90) < 3000.0f) goto loop_28;
                    }
                    var_16_3 += 1;
                    goto loop_27;
                }
loop_28:
                if (var_16_3 < 4) var_18_2 = 1;
                if (func_0014cfd0(var_17 + 0x140) == 1) goto loop_14;
                if (var_18_2 == 1) goto loop_14;
                return var_17;
            }
            if (func_0014cfd0(var_18 + 0x140) == 1) {
                var_18 = *(u8 **)(var_18 + 0x138);
                goto loop_44;
            }
            temp_f24 = var_f22;
            temp_19 = var_16;
            var_17_3 = 0;
loop_42:
            if (var_17_3 < 0xFU) {
                temp_3_3 = D_007E8C00 + var_17_3 * 0x750;
                if (*(s32 *)(temp_3_3 + 0x48) != 0) {
                    temp_2_3 = *(u8 **)(temp_3_3 + 0x1AC);
                    frame.v90[0] = frame.vA0[0] - *(f32 *)(temp_2_3 + 0x140);
                    frame.v90[1] = temp_f21 - *(f32 *)(temp_2_3 + 0x144);
                    frame.v90[2] = temp_f20 - *(f32 *)(temp_2_3 + 0x148);
                    temp_f0 = func_003e4180(frame.v90);
                    if (temp_f0 > var_f22) { var_f22 = temp_f0; var_16 = var_18; }
                    if (temp_f0 < arg2) { var_f22 = temp_f24; var_16 = temp_19; goto block_41; }
                }
block_41:
                var_17_3 += 1;
                goto loop_42;
            }
            var_18 = *(u8 **)(var_18 + 0x138);
            goto loop_44;
        }
    }
    if (func_0014a270() == 1 && func_00164f40() < (s32)arg1) {
        var_19 = func_001452b0(0xF);
loop_70:
        if (var_19 == NULL) goto block_71;
        tx = *(f32 *)(var_19 + 0x140);
        ty = *(f32 *)(var_19 + 0x144);
        tz = *(f32 *)(var_19 + 0x148);
        frame.v80[0] = tx;
        frame.v80[1] = ty;
        frame.v80[2] = tz;
        var_17_4 = 0;
        temp_f21 = frame.v80[1];
        temp_f20 = frame.v80[2];
loop_56:
        if (var_17_4 < 4U) {
            var_4_3 = 0;
            temp_3_4 = D_007EF9B0 + var_17_4 * 0x750;
            if (*(s32 *)(temp_3_4 + 0x48) != 0 && *(s32 *)(temp_3_4 + 0x54) != 0) var_4_3 = 1;
            if (var_4_3 != 0) {
                temp_2_4 = D_007EF9B0 + var_17_4 * 0x750;
                {
                    u8 *slot50 = temp_2_4 + 0x50;
                    temp_2_5 = func_0047a2f0(*(s32 *)(temp_2_4 + 0x50));
                    frame.v70[0] = frame.v80[0] - *(f32 *)(temp_2_5 + 0x30);
                    temp_2_3 = func_0047a2f0(*(s32 *)slot50);
                    frame.v70[1] = temp_f21 - *(f32 *)(temp_2_3 + 0x34);
                    temp_2_2 = func_0047a2f0(*(s32 *)slot50);
                    frame.v70[2] = temp_f20 - *(f32 *)(temp_2_2 + 0x38);
                }
                if (func_003e4180(frame.v70) < 3000.0f) goto loop_58;
            }
            var_17_4 += 1;
            goto loop_56;
        }
loop_58:
        if (var_17_4 < 4U) {
            var_19 = *(u8 **)(var_19 + 0x138);
            goto loop_70;
        }
        if (func_00164f40() == 0) return var_19;
        temp_f24_2 = var_f22;
        temp_17 = var_16;
        var_18_3 = 0;
loop_68:
        if (var_18_3 < 0xFU) {
            temp_3_5 = D_007E8C00 + var_18_3 * 0x750;
            if (*(s32 *)(temp_3_5 + 0x48) != 0) {
                temp_2_5 = *(u8 **)(temp_3_5 + 0x1AC);
                frame.v70[0] = frame.v80[0] - *(f32 *)(temp_2_5 + 0x140);
                frame.v70[1] = temp_f21 - *(f32 *)(temp_2_5 + 0x144);
                frame.v70[2] = temp_f20 - *(f32 *)(temp_2_5 + 0x148);
                temp_f0_2 = func_003e4180(frame.v70);
                if (temp_f0_2 > var_f22) { var_f22 = temp_f0_2; var_16 = var_19; }
                if (temp_f0_2 < arg2) { var_f22 = temp_f24_2; var_16 = temp_17; goto block_67; }
            }
block_67:
            var_18_3 += 1;
            goto loop_68;
        }
        var_19 = *(u8 **)(var_19 + 0x138);
        goto loop_70;
    }
block_71:
    return var_16;
}
#pragma pop
