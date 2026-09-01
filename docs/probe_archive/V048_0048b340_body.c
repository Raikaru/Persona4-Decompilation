/* archive: candidate object 0 (M2C compile-error candidate; normalized_diff unavailable); retail window 1696 bytes; normalized_diff unavailable because candidate does not compile. Conversion casts: int->float sites 0x48, 0x98, 0x194, 0x500: `(f32)(u32)value` at each; float->unsigned site 0x20C: `(u32)float_expression`. Ruled out: COP1 accumulator chain (`adda.s`/`madd.s`) and multiple COP2/VU packets; no plain-C closure attempted. */
void func_0048b340(u8 *arg0, u8 *arg1) {
    M2C_UNK s0;
    M2C_UNK s1;
    s32 sp14C;
    s32 sp148;
    s32 sp144;
    s32 sp140;
    s32 sp13C;
    s32 sp138;
    s128 sp120;
    s128 sp110;
    s128 sp100;
    s128 spF0;
    M2C_UNK spE0;
    M2C_UNK spD0;
    u128 spC0;
    f32 temp_f1;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f21;
    f32 var_f21_2;
    f32 var_f23;
    s32 temp_18;
    s32 temp_20;
    s32 temp_2_2;
    s32 temp_30;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_6;
    s32 var_3;
    u32 temp_19;
    u32 temp_23;
    u32 temp_2;
    u32 var_19_2;
    u32 var_22;
    u32 var_5;
    u32 var_8;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_7;
    u8 *var_17;
    u8 *var_17_2;
    u8 *var_17_3;
    u8 *var_17_4;
    u8 *var_19;

    temp_3 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x20));
    temp_20 = (s32)((s32)(M2C_FIELD(temp_3, s32 *, 0xC4)));
    temp_23 = (u32)((u32)(M2C_FIELD(temp_3, u32 *, 0xC0)));
    temp_19 = temp_23 * temp_20;
    if (temp_19 != 0) {
        temp_18 = (s32)((s32)(M2C_FIELD(arg1, s32 *, 0x10)));
        temp_6 = (s32)((s32)(M2C_FIELD(arg0, s32 *, 0x18)));
        temp_16 = (u8 *)(temp_6 + ((M2C_FIELD(arg0, s32 *, 4) + (((u32) (arg1 - temp_6) >> 5) * temp_19)) << 5));
        if (temp_18 == 0) {
            func_0043f810(temp_16, (u8 *)0x20);
            var_17 = (u8 *)(temp_16);
            var_5 = 0;
loop_4:
            if (var_5 < temp_19) {
                M2C_FIELD(var_17, s32 *, 0x10) = -1;
                var_17 += 0x20;
                var_5 += 1;
                goto loop_4;
            }
            return;
        }
        M2C_FIELD(temp_16, s32 *, 0x10) = (s32) (temp_18 - 1);
        if ((s32) temp_19 >= 0) {
            var_f0 = (f32) temp_19;
        } else {
            var_f0 = 2.0f * (f32)(s32)((temp_19 >> 1) | (temp_19 & 1));
        }
        var_f23 = 0.0f;
        temp_2 = (u32)((u32) M2C_FIELD(arg1, u32 *, 0x14) >> 0x18);
        if ((s32) temp_2 >= 0) {
            var_f21 = (f32) temp_2;
        } else {
            var_f21 = 2.0f * (f32)(s32)((temp_2 >> 1) | (temp_2 & 1));
        }
        spC0 = temp_19 - temp_20;
        var_19 = (u8 *)(((s32)(temp_16) + (temp_19 << 5)) - 0x20);
        temp_30 = temp_20 << 5;
        var_17_2 = (u8 *)((s32)(var_19) - temp_30);
        var_22 = 0;
loop_17:
        if (var_22 < spC0) {
            func_0043f810(var_19, var_17_2, 0x20);
            temp_f1 = var_f21 * var_f23;
            if (!(temp_f1 >= 2.1474836e9f)) {
                var_3 = 0x4F000000;
            } else {
                var_3 = M2C_BITWISE(s32, (temp_f1 - 2.1474836e9f)) | 0x80000000;
            }
            M2C_FIELD(var_19, s32 *, 0x14) = (s32)((s32) (((u64) ((s64) M2C_FIELD(var_17_2, s32 *, 0x14) << 0x28) >> 0x28) | (var_3 << 0x18)));
            var_f23 += 1.0f / var_f0;
            var_19 -= 0x20;
            var_17_2 -= 0x20;
            var_22 += 1;
            goto loop_17;
        }
        func_0043f810(temp_16, arg1, 0x20);
        M2C_FIELD(temp_16, s32 *, 0x10) = -1;
        if ((temp_20 == 1) || (temp_23 < 2U)) {
            return;
        }
        if ((temp_18 >= 2) && (temp_23 >= 3U)) {
            temp_4 = (u8 *)((temp_20 << 6) + (s32)(temp_16));
            if (M2C_FIELD(temp_4, s32 *, 0x10) >= 0) {
                spF0 = (s128)((s128)(s32)(M2C_FIELD(temp_4, s128 *, 0)));
                temp_4_2 = (u8 *)((s32)(temp_16) + (temp_20 << 5));
                sp100 = (s128)((s128)(s32)(M2C_FIELD(temp_4_2, s128 *, 0)));
                sp110 = (s128)((s128)(s32)(M2C_FIELD(temp_16, s128 *, 0)));
                sp120 = (s128)((s128)(s32)(M2C_FIELD(temp_16, s128 *, 0)));
                var_17_3 = (u8 *)((s32)(temp_4_2) - 0x20);
                var_f21_2 = 0.0f;
                temp_2_2 = temp_20 + 1;
                if (temp_2_2 >= 0) {
                    var_f0_2 = (f32) temp_2_2;
                } else {
                    var_f0_2 = 2.0f * (f32)(s32)(((u32) temp_2_2 >> 1) | (temp_2_2 & 1));
                }
                sp14C = (s32)((s32)(M2C_FIELD(temp_16, s32 *, 0x14)));
                M2C_ERROR(/* unknown instruction: pextlb $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: pextlh $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf10 */);
                M2C_ERROR(/* unknown instruction: vitof0.xyzw $vf10, $vf10 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf11, $vf10 */);
                sp148 = (s32)((s32)(M2C_FIELD(temp_4_2, s32 *, 0x14)));
                M2C_ERROR(/* unknown instruction: pextlb $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: pextlh $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf10 */);
                M2C_ERROR(/* unknown instruction: vitof0.xyzw $vf10, $vf10 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($v1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf11, $vf11, $vf10 */);
                M2C_ERROR(/* unknown instruction: vaddw.xyz $vf10, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vmulx.w $vf10, $vf0, $vf0x */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmul.xyzw $vf10, $vf10, $vf11 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($v1) */);
                var_19_2 = 0;
loop_29:
                if (var_19_2 < (u32) (temp_20 - 1)) {
                    var_f21_2 += 1.0f / var_f0_2;
                    func_0048a810(M2C_BITWISE(f32, (s32)(s64)(s32)&spF0), var_f21_2);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($s1) */);
                    M2C_ERROR(/* unknown instruction: adda.s $f0, $f20 */);
                    M2C_FIELD(var_17_3, f32 *, 0x18) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f1, $f26, $f21 */);
                    M2C_ERROR(/* unknown instruction: adda.s $f0, $f25 */);
                    M2C_FIELD(var_17_3, f32 *, 0x1C) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f24, $f21 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($a0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($v1) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf10, $vf10, $vf11 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($a0) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vftoi0.xyzw $vf10, $vf10 */);
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf10 */);
                    M2C_ERROR(/* unknown instruction: ppach $v1, $zero, $v1 */);
                    temp_3_2 = M2C_ERROR(/* unknown instruction: ppacb $v1, $zero, $v1 */);
                    sp144 = temp_3_2;
                    M2C_FIELD(var_17_3, s32 *, 0x14) = temp_3_2;
                    M2C_FIELD(var_17_3, s32 *, 0x10) = temp_18;
                    var_17_3 -= 0x20;
                    var_19_2 += 1;
                    goto loop_29;
                }
            }
        } else if (temp_18 > 0) {
            temp_7 = (u8 *)(temp_30 + (s32)(temp_16));
            if (M2C_FIELD(temp_7, s32 *, 0x10) >= 0) {
                var_17_4 = (u8 *)((s32)(temp_7) - 0x20);
                if ((temp_20 + 1) >= 0) {

                }
                sp140 = (s32)((s32)(M2C_FIELD(temp_16, s32 *, 0x14)));
                M2C_ERROR(/* unknown instruction: pextlb $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: pextlh $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf10 */);
                M2C_ERROR(/* unknown instruction: vitof0.xyzw $vf10, $vf10 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf11, $vf10 */);
                sp13C = (s32)((s32)(M2C_FIELD(temp_7, s32 *, 0x14)));
                M2C_ERROR(/* unknown instruction: pextlb $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: pextlh $v0, $zero, $v0 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf10 */);
                M2C_ERROR(/* unknown instruction: vitof0.xyzw $vf10, $vf10 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($a2) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf11, $vf11, $vf10 */);
                M2C_ERROR(/* unknown instruction: vaddw.xyz $vf10, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vmulx.w $vf10, $vf0, $vf0x */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                M2C_ERROR(/* unknown instruction: vmul.xyzw $vf10, $vf10, $vf11 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($a1) */);
                var_8 = 0;
loop_38:
                if (var_8 < (u32) (temp_20 - 1)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($a3) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($s0) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vsubx.w $vf3, $vf0, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf11, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyzw $vf10, $vf10, $vf3w */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($s1) */);
                    M2C_ERROR(/* unknown instruction: adda.s $f1, $f5 */);
                    M2C_FIELD(var_17_4, f32 *, 0x18) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f4, $f6 */);
                    M2C_ERROR(/* unknown instruction: adda.s $f1, $f3 */);
                    M2C_FIELD(var_17_4, f32 *, 0x1C) = (f32) M2C_ERROR(/* unknown instruction: madd.s $f0, $f2, $f6 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf10, ($a2) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf11, ($a1) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf10, $vf10, $vf11 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf10, ($a2) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a5, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf10, $vf10, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vftoi0.xyzw $vf10, $vf10 */);
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf10 */);
                    M2C_ERROR(/* unknown instruction: ppach $v1, $zero, $v1 */);
                    temp_3_3 = M2C_ERROR(/* unknown instruction: ppacb $v1, $zero, $v1 */);
                    sp138 = temp_3_3;
                    M2C_FIELD(var_17_4, s32 *, 0x14) = temp_3_3;
                    M2C_FIELD(var_17_4, s32 *, 0x10) = temp_18;
                    var_17_4 -= 0x20;
                    var_8 += 1;
                    goto loop_38;
                }
            }
        }
    }
}
