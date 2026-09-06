/*
 * Re-certified: object 584B / retail window 592B; raw fndiff 7 words,
 * comprising five executable FPR differences and two absent zero-tail
 * words. Normalized comparison differs by five bytes.
 * Executable offsets: 0x160, 0x168, 0x16C, 0x17C, 0x21C.
 * The identity constant uses f3 rather than f1; sqrt uses f1 rather than
 * f2. The 2.0f constant instructions already match.
 * Root-local, root-literal and in-place-root forms are byte-identical.
 * A literal or separately named identity constant also leaves seven words.
 * Earlier index widths, diagonal-address forms and split/unsplit root
 * multiplication did not close the floor. Preserve arithmetic association.
 * Current TU supplies the plain-C multiply helper but not add; the
 * necessary plain-C inline add is retained here for standalone replay.
 */
static inline f32 code1_0048_add(f32 left, f32 right) {
    return left + right;
}

void func_0048a980(f32 *arg0)
{
    extern f32 sqrtf(f32 arg0);
    f32 sp[4];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f5;
    f32 temp_f2_3;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_3;
    s32 temp_5;
    s32 temp_6;
    s32 temp_7;
    s32 temp_8;
    u8 var_6;
    s32 var_3;
    u8 *temp_5_2;
    u8 *temp_7_2;
    u8 *temp_9;
    u8 next2;
    s32 temp_10;

    temp_f3 = arg0[5];
    temp_f2 = arg0[0];
    temp_f4 = arg0[10];
    temp_f1 = 1.0f;
    temp_f0 = temp_f2 + temp_f3;
    temp_f0 = code1_0048_add(temp_f4, temp_f0);
    temp_f0 = code1_0048_add(temp_f1, temp_f0);
    if (!(temp_f0 < temp_f1)) {
        temp_f2_2 = 2.0f * sqrtf(temp_f0);
        sp[3] = -(temp_f2_2 / 4.0f);
        sp[0] = (arg0[6] - arg0[9]) / temp_f2_2;
        sp[1] = (arg0[8] - arg0[2]) / temp_f2_2;
        sp[2] = (arg0[1] - arg0[4]) / temp_f2_2;
    } else {
        var_3 = (temp_f2 > temp_f3) ? 1 : 0;
        var_6 = (var_3 ^ 1) & 0xFF;
        if (!(temp_f4 <= *(f32 *)((u8 *)arg0 + (var_6 * 0x10) +
                                  (var_6 * 4)))) {
            var_6 = 2;
        }
        temp_7 = var_6 & 0xFF;
        temp_5 = ((s32)(temp_7 + 1) % 3) & 0xFF;
        temp_10 = (s32)(temp_5 + 1) % 3;
        next2 = temp_10 & 0xFF;
        temp_3 = temp_5 * 4;
        temp_9 = (u8 *)arg0 + (temp_5 * 0x10);
        temp_f1 = *(f32 *)(temp_9 + temp_3);
        temp_8 = temp_7 * 4;
        temp_7_2 = (u8 *)arg0 + (temp_7 * 0x10);
        temp_f0 = *(f32 *)(temp_7_2 + temp_8);
        temp_f1 = temp_f0 - temp_f1;
        temp_6 = next2 * 4;
        temp_5_2 = (u8 *)arg0 + (next2 * 0x10);
        temp_f0 = *(f32 *)(temp_5_2 + temp_6);
        temp_f0 = temp_f1 - temp_f0;
        temp_f1 = 1.0f;
        temp_f0 = code1_0048_add(temp_f1, temp_f0);
        temp_f2_3 = sqrtf(temp_f0);
        temp_f0 = 2.0f;
        temp_f2_3 = code1_0048_mul(temp_f0, temp_f2_3);
        if (temp_f2_3 != 0.0f) {
            *(f32 *)((u8 *)sp + temp_8) = temp_f2_3 / 4.0f;
            *(f32 *)((u8 *)sp + temp_3) =
                (*(f32 *)(temp_7_2 + temp_3) + *(f32 *)(temp_9 + temp_8)) /
                temp_f2_3;
            *(f32 *)((u8 *)sp + temp_6) =
                (*(f32 *)(temp_7_2 + temp_6) + *(f32 *)(temp_5_2 + temp_8)) /
                temp_f2_3;
            sp[3] = -((*(f32 *)(temp_9 + temp_6) -
                       *(f32 *)(temp_5_2 + temp_3)) /
                      temp_f2_3);
        } else {
            *(f32 *)((u8 *)sp + temp_8) = temp_f1;
            *(f32 *)((u8 *)sp + temp_3) = 0.0f;
            *(f32 *)((u8 *)sp + temp_6) = 0.0f;
            sp[3] = 0.0f;
        }
    }
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp) : "$vf10", "memory");
}
