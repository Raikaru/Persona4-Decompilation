/* archive: candidate object 0 (M2C compile-error candidate; normalized_diff unavailable); retail window 2176 bytes; normalized_diff unavailable because candidate does not compile. Conversion casts: int->float sites 0x148, 0x208, 0x250, 0x620: `(f32)(u32)value` at each. Ruled out: COP1 accumulator chain (`adda.s`/`madd.s`) plus COP2/VU packet operations; documented floor. */
void func_0048c4e0(u8 *arg0) {
    M2C_UNK s2;
    M2C_UNK s4;
    s32 sp13C;
    f32 sp138;
    f32 sp134;                                      /* compiler-managed */
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    s128 sp110;
    u128 sp100;
    s128 spF0;
    s128 spE0;
    s128 spD0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f21;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f28_3;
    f32 temp_f28_4;
    f32 var_16;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    s32 temp_21;
    s32 temp_21_2;
    s32 temp_30;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_6;
    s32 temp_6;
    s32 temp_f0_6;
    s32 var_22;
    s32 var_3;
    s32 var_5;
    u32 var_23;
    u8 *temp_18;
    u8 *temp_21_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_4;
    u8 *temp_5;
    u8 *var_19;
    u8 *var_20;
    u8 *var_7;

    sp100 = (u128) M2C_FIELD(arg0, s32 *, 4);
    spF0 = (s128) M2C_FIELD(arg0, s32 *, 0xC);
    var_20 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x18));
    var_19 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x1C));
    temp_18 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x20));
    temp_30 = (s32)(M2C_FIELD(temp_18, s32 *, 0xB8));
    if (temp_30 != 0) {
        temp_3 = (s32)(M2C_FIELD(temp_18, s32 *, 0x20));
        spE0 = (s128) temp_3;
        spD0 = (s128) M2C_FIELD(temp_18, u8 *, 0x9C);
        temp_f27 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0xDC));
        temp_f26 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0xD8));
        sp13C = 0;
        if ((temp_3 != 0) && (M2C_FIELD(arg0, s32 *, 0x10) >= temp_3)) {
            var_22 = 0;
            var_16 = 0.0f;
        } else if ((M2C_FIELD(arg0, s32 *, 0x10) == 0) && (M2C_FIELD(temp_18, u8 *, 0xBD) != 0)) {
            var_22 = 1;
            if (!(M2C_FIELD(temp_18, f32 *, 0x28) <= 0.0f)) {
                temp_f1 = (f32)(s32)((M2C_FIELD(saved_reg_gp, f32 *, -0x7F84) - M2C_FIELD(temp_18, f32 *, 0x28)) * func_004bd0b0(0));
                temp_3_2 = (s32)(M2C_FIELD(arg0, s32 *, 4));
                if (temp_3_2 >= 0) {
                    var_f0 = (f32) temp_3_2;
                } else {
                    var_f0 = 2.0f * (f32) (((u32) temp_3_2 >> 1) | (temp_3_2 & 1));
                }
                var_16 = var_f0 * temp_f1;
            } else {
                var_16 = (f32)(s32)(M2C_BITWISE(f32, M2C_FIELD(arg0, s32 *, 4)));
            }
        } else {
            var_22 = 0;
            if (!(M2C_FIELD(temp_18, f32 *, 0x28) <= 0.0f)) {
                func_004bd0b0(0);
                if (M2C_FIELD(temp_18, s32 *, 0x24) >= 0) {

                }
                M2C_ERROR(/* unknown instruction: adda.s $f0, $f1 */);
                M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f2, $f3 */);
            } else {
                temp_3_3 = (s32)(M2C_FIELD(temp_18, s32 *, 0x24));
                if (temp_3_3 >= 0) {
                    var_f1 = (f32) temp_3_3;
                } else {
                    var_f1 = 2.0f * (f32) (((u32) temp_3_3 >> 1) | (temp_3_3 & 1));
                }
                M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x14) + var_f1);
            }
            temp_f1_2 = (f32)(s32)(M2C_FIELD(arg0, f32 *, 0x14));
            temp_f0 = fabsf(temp_f1_2);
            var_16 = temp_f0;
            M2C_FIELD(arg0, f32 *, 0x14) = (f32) (temp_f1_2 - (f32) temp_f0);
        }
        var_23 = 0;
        temp_f21 = (f32)(s32)(M2C_FIELD(saved_reg_gp, f32 *, -0x7F80));
loop_61:
        if (var_23 < sp100) {
            if (M2C_FIELD(var_20, s32 *, 0x10) >= temp_30) {
                if (spE0 != 0) {
                    var_3 = -2;
                } else {
                    var_3 = -1;
                }
                M2C_FIELD(var_20, s32 *, 0x10) = var_3;
                temp_3_4 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x20));
                temp_6 = (s32)(M2C_FIELD(temp_3_4, s32 *, 0xC0) * M2C_FIELD(temp_3_4, s32 *, 0xC4));
                if (temp_6 != 0) {
                    temp_5 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x18));
                    var_7 = (u8 *)(temp_5 + ((M2C_FIELD(arg0, s32 *, 4) + (((u32) (var_20 - temp_5) >> 5) * temp_6)) << 5));
                    var_5 = 0;
loop_30:
                    if (var_5 < temp_6) {
                        M2C_FIELD(var_7, s32 *, 0x10) = -1;
                        var_7 += 0x20;
                        var_5 += 1;
                        goto loop_30;
                    }
                }
            }
            temp_21 = (s32)(M2C_FIELD(var_20, s32 *, 0x10));
            if (temp_21 != -2) {
                if (temp_21 == -1) {
                    if (M2C_BITWISE(s32, var_16) != 0) {
                        temp_f0_2 = 2.0f * (func_004bd0b0(0) - 0.5f);
                        sp130 = temp_f0_2;
                        temp_f0_3 = 2.0f * (func_004bd0b0(0) - 0.5f);
                        sp134 = temp_f0_3;
                        temp_f0_4 = 2.0f * (func_004bd0b0(0) - 0.5f);
                        sp138 = temp_f0_4;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($v0) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf10, $vf10 */);
                        M2C_ERROR(/* unknown instruction: vmulax.w $acc, $vf0, $vf2x */);
                        M2C_ERROR(/* unknown instruction: vmadday.w $acc, $vf0, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.w $vf2, $vf0, $vf2z */);
                        M2C_ERROR(/* unknown instruction: vrsqrt $q, $vf0w, $vf2w */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vmulq.xyz $vf10, $vf10, $q */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($v0) */);
                        M2C_FIELD(var_19, f32 *, 0) = temp_f0_2;
                        M2C_FIELD(var_19, f32 *, 4) = temp_f0_3;
                        M2C_FIELD(var_19, f32 *, 8) = temp_f0_4;
                        temp_f28 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0xD4));
                        func_004bd0b0(0);
                        M2C_ERROR(/* unknown instruction: adda.s $f1, $f2 */);
                        M2C_FIELD(var_19, f32 *, 0xC) = fabsf(M2C_FIELD(temp_18, f32 *, 0xD0) * M2C_ERROR(/* unknown instruction: madd.s $f1, $f28, $f0 */));
                        temp_f28_2 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0xCC));
                        func_004bd0b0(0);
                        M2C_ERROR(/* unknown instruction: adda.s $f1, $f2 */);
                        temp_f0_5 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0xC8) * M2C_ERROR(/* unknown instruction: madd.s $f1, $f28, $f0 */));
                        sp120 = temp_f0_5;
                        sp124 = temp_f0_5;
                        sp128 = temp_f0_5;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($v0) */);
                        if (M2C_FIELD(temp_18, f32 *, 0xD0) < 0.0f) {
                            M2C_ERROR(/* unknown instruction: vsub.xyz $vf10, $vf0, $vf10 */);
                        }
                        if (spF0 & 1) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
                            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf10, $vf10, $vf11 */);
                        } else {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v0) */);
                            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf10, $vf10, $vf11 */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s2) */);
                            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf10, $vf10, $vf11 */);
                        }
                        M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($s4) */);
                        temp_f28_3 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0x6C));
                        func_004bd0b0(0);
                        M2C_ERROR(/* unknown instruction: adda.s $f1, $f2 */);
                        M2C_FIELD(var_19, f32 *, 0x10) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f28, $f0 */);
                        temp_21_2 = spD0 & 0xFF;
                        if (temp_21_2 != 2) {
                            temp_f28_4 = (f32)(s32)(M2C_FIELD(temp_18, f32 *, 0x98));
                            func_004bd0b0(0);
                            M2C_ERROR(/* unknown instruction: adda.s $f1, $f2 */);
                            M2C_FIELD(var_19, f32 *, 0x18) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f28, $f0 */);
                            if (temp_21_2 == 1) {
                                M2C_FIELD(var_19, f32 *, 0x14) = (f32) (temp_f21 * func_004bd0b0(0));
                                if (func_004bd050(0) & 1) {
                                    M2C_FIELD(var_19, f32 *, 0x18) = (f32) (M2C_FIELD(var_19, f32 *, 0x18) * -1.0f);
                                }
                            } else {
                                M2C_FIELD(var_19, f32 *, 0x14) = 0.0f;
                            }
                        } else {
                            M2C_FIELD(var_19, f32 *, 0x14) = 0.0f;
                            M2C_FIELD(var_19, f32 *, 0x18) = 1.0f;
                        }
                        M2C_FIELD(var_20, s32 *, 0x10) = 0;
                        sp110 = (s128)(s32)(M2C_FIELD(var_20, s128 *, 0));
                        if (var_22 != 0) {
                            if ((s32) (func_004bd050(0) % (u32) temp_30) >= 0) {

                            }
                            M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s4) */);
                            M2C_ERROR(/* unknown instruction: mula.s $f0, $f3 */);
                            var_f1_2 = M2C_ERROR(/* unknown instruction: madd.s $f1, $f25, $f0 */);
                            if (var_f1_2 < 0.0f) {
                                var_f1_2 = 0.0f;
                            }
                            sp130 = (f32)(s32)(var_f1_2 * M2C_FIELD(var_19, f32 *, 0));
                            sp134 = (f32)(s32)(var_f1_2 * M2C_FIELD(var_19, f32 *, 4));
                            sp138 = (f32)(s32)(var_f1_2 * M2C_FIELD(var_19, f32 *, 8));
                            M2C_ERROR(/* unknown instruction: adda.s $f0, $f2 */);
                            temp_f0_6 = M2C_ERROR(/* unknown instruction: msub.s $f0, $f25, $f1 */);
                            sp134 = temp_f0_6;
                            M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($v0) */);
                            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf10, $vf10, $vf11 */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($s4) */);
                            M2C_FIELD(var_20, s32 *, 0x10) = temp_f0_6;
                        }
                        func_0048b220(var_20, temp_18, M2C_FIELD(var_20, s32 *, 0x10), &sp110);
                        M2C_FIELD(var_20, f32 *, 0x18) = (f32) (M2C_FIELD(var_20, f32 *, 0x18) * M2C_FIELD(var_19, f32 *, 0x10));
                        M2C_FIELD(var_20, f32 *, 0x1C) = (f32) (M2C_FIELD(var_20, f32 *, 0x1C) * M2C_FIELD(var_19, f32 *, 0x18));
                        M2C_FIELD(var_20, f32 *, 0x1C) = (f32) (M2C_FIELD(var_20, f32 *, 0x1C) + M2C_FIELD(var_19, f32 *, 0x14));
                        if (var_22 != 0) {
                            temp_3_5 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x20));
                            temp_3_6 = (s32)(M2C_FIELD(temp_3_5, s32 *, 0xC0) * M2C_FIELD(temp_3_5, s32 *, 0xC4));
                            if (temp_3_6 != 0) {
                                temp_4 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x18));
                                temp_21_3 = (u8 *)(temp_4 + ((M2C_FIELD(arg0, s32 *, 4) + (((u32) (var_20 - temp_4) >> 5) * temp_3_6)) << 5));
                                func_0043f810(temp_21_3, var_20, 0x20);
                                M2C_FIELD(temp_21_3, s32 *, 0x10) = -1;
                            }
                            M2C_FIELD(var_20, s32 *, 0x10) = (s32) (M2C_FIELD(var_20, s32 *, 0x10) + 1);
                        }
                        var_16 = M2C_BITWISE(f32, (M2C_BITWISE(s32, var_16) - 1));
                    }
                } else {
                    sp110 = (s128)(s32)(M2C_FIELD(var_20, s128 *, 0));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s4) */);
                    M2C_ERROR(/* unknown instruction: adda.s $f0, $f1 */);
                    var_f1_3 = M2C_ERROR(/* unknown instruction: madd.s $f1, $f26, $f2 */);
                    if (var_f1_3 < 0.0f) {
                        var_f1_3 = 0.0f;
                    }
                    sp130 = (f32)(s32)(var_f1_3 * M2C_FIELD(var_19, f32 *, 0));
                    sp134 = (f32)(s32)(var_f1_3 * M2C_FIELD(var_19, f32 *, 4));
                    sp138 = (f32)(s32)(var_f1_3 * M2C_FIELD(var_19, f32 *, 8));
                    M2C_ERROR(/* unknown instruction: adda.s $f0, $f2 */);
                    sp134 = M2C_ERROR(/* unknown instruction: msub.s $f0, $f27, $f1 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($v0) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf10, $vf10, $vf11 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($s4) */);
                    func_0048b220(var_20, temp_18, temp_21, &sp110);
                    M2C_FIELD(var_20, f32 *, 0x18) = (f32) (M2C_FIELD(var_20, f32 *, 0x18) * M2C_FIELD(var_19, f32 *, 0x10));
                    M2C_FIELD(var_20, f32 *, 0x1C) = (f32) (M2C_FIELD(var_20, f32 *, 0x1C) * M2C_FIELD(var_19, f32 *, 0x18));
                    M2C_FIELD(var_20, f32 *, 0x1C) = (f32) (M2C_FIELD(var_20, f32 *, 0x1C) + M2C_FIELD(var_19, f32 *, 0x14));
                    func_0048b340(arg0, var_20);
                    M2C_FIELD(var_20, s32 *, 0x10) = (s32) (temp_21 + 1);
                }
            }
            var_23 += 1;
            var_19 += 0x1C;
            var_20 += 0x20;
            goto loop_61;
        }
    }
}
