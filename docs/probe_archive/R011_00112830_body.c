/* object 2096/window 2192/normalized_diff 1636; undersized by 96 bytes; classification: declaration/frame/stack-layout; ruled out: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, sd-saved-register ABI floor; retail saved s8-s0 (9), f20-f22 and frame 0x120, candidate frame 0x140. differing offsets: 0,56,57,58,59,60,61,62,63,65,66,70,72,73,74,75 */
void func_00112830(s64, f32, u8, u8 *, s32);
    void func_001130c0(s64, f32, u8, u8 *, s32);
    extern f32 D_005E4790[];
    extern f32 D_005E4794[];
    extern f32 D_005E479C[];
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 iGpffffb1dc;
    extern u8 iGpffffb1d4;
    extern u8 iGpffffb1e4;

    temp16 = func_0046a770(D_005E5830);
    temp19 = func_0046a770(D_005E5850);
    if (temp16 == 0) {
        func_0046d730(&iGpffffb1dc, 0x93);
    }
    if (temp19 == 0) {
        func_0046d730(&iGpffffb1dc, 0x94);
    }
    if (*(u16 *)(arg2 + 0x14) != 0) {
        func_00112610(arg0, fparg0, arg1, arg2, temp16, temp19);
        *(f32 *)&arg0 = *(f32 *)&arg0 + 45.0f;
    }
    if (*(s32 *)(arg2 + 0xC) != 0) {
        temp19 = arg1 & 0xFF;
        temp_2 = (s32)func_001067f0(*(s16 *)arg2);
        func_00275020(
            *(f32 *)&arg0,
            *(f32 *)((u8 *)&arg0 + 4),
            fparg0,
            temp19 | ~0xFF,
            *(s8 *)(&iGpffffb1d4 + *(s16 *)(arg2 + 0x16)),
            1,
            (u8 *)temp_2,
            0,
            -1);
    }
    if (*(s32 *)(arg2 + 0x10) != 0) {
        xy.values[0] = *(f32 *)&arg0 +
                       D_005E4790[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 9.0f;
        temp_1 += *(f32 *)((u8 *)&arg0 + 4);
        xy.values[1] = temp_1;
        func_00112830(xy.whole, fparg0, arg1, arg2, temp16);
    }
    if (*(s16 *)(arg2 + 2) != -1) {
        xy.values[0] = *(f32 *)&arg0 +
                       D_005E4794[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 12.0f;
        temp_1 += *(f32 *)((u8 *)&arg0 + 4);
        xy.values[1] = temp_1;
        func_001130c0(xy.whole, fparg0, arg1, arg2, temp16);
    }
    if (*(s32 *)(arg2 + 8) != -1) {
        xy.values[0] = *(f32 *)&arg0 +
                       D_005E479C[*(s16 *)(arg2 + 0x18) * 4];
        xy.values[1] = *(f32 *)((u8 *)&arg0 + 4);
        temp16 = ((arg1 & 0xFF) * 0xFF) / 255U;
        func_00442088(buf, &iGpffffb1e4,
                      func_00106a90(*(s16 *)arg2));
        func_00274ed0(
            (f32)(s32)xy.values[0],
            (f32)(s32)xy.values[1],
            fparg0,
            temp16 | ~0xFF,
            *(s8 *)(&iGpffffb1d4 + *(s16 *)(arg2 + 0x16)),
            0,
            (void *)buf,
            0,
            0);
    }
}
// FUN_001125D0
void func_001125d0(u8 *arg0) {
    s32 temp_1;
    s32 temp_m1;

    temp_1 = 1;
    *(s16 *)(arg0 + 0) = temp_1;
    temp_m1 = -1;
    *(s16 *)(arg0 + 2) = temp_m1;
    *(s16 *)(arg0 + 6) = temp_m1;
    *(s32 *)(arg0 + 8) = temp_m1;
    *(s32 *)(arg0 + 0xC) = temp_1;
    *(s32 *)(arg0 + 0x10) = 0;
    temp_m1 = 3;
    *(s16 *)(arg0 + 0x14) = temp_m1;
    *(s16 *)(arg0 + 0x18) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
// FUN_00112610
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112610);
// FUN_00112830
void func_00112830(s64 arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    u8 *table;
    s32 current;
    s32 mode_a;
    s32 mode_b;
    u8 color_b;
    u8 color_g;
    s32 alpha;
    f32 x;
    f32 y;
    s32 kind;
    s32 value;
    s32 digit;
    s32 i;
    s64 positions[9];
    u8 colors[4];
    void func_0046d4c0(s32, s32, s32, u8, f32, f32,
                       u8, u8, u8, f32, s32);
    extern u8 D_005E4750[];

    positions[0] = arg0;
    table = D_005E4750 + (*(s16 *)(arg2 + 0x16) * 4);
    colors[0] = table[0];
    colors[1] = table[1];
    colors[2] = table[2];
    colors[3] = table[3];
    colors[3] = (u8)arg1;
    kind = func_00106c80(*(s16 *)arg2);
    switch (kind) {
    case 0:
        value = func_001068b0(*(s16 *)arg2) & 0xFFFF;
        positions[8] = positions[0];
        if (value / 100 != 0) {
            x = 30.0f + *(f32 *)&positions[8];
        } else {
            x = 22.0f + *(f32 *)&positions[8];
        }
        y = *(f32 *)((u8 *)&positions[8] + 4);
        current = value;
        color_b = colors[2];
        color_g = colors[1];
        alpha = 0xFF - colors[3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, (u8)alpha, x, y,
                          colors[0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_001068b0(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[7] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_a = 40;
                } else if (current < value) {
                    mode_a = 41;
                }
                y = *(f32 *)((u8 *)&positions[7] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_a, (u8)alpha,
                              *(f32 *)&positions[7], y,
                              colors[0], color_g, color_b, fparg0, 0);
            }
        }
        *(f32 *)&positions[0] += 42.0f;
        value = func_001068e0(*(s16 *)arg2) & 0xFFFF;
        positions[6] = positions[0];
        if (value / 100 != 0) {
            x = 30.0f + *(f32 *)&positions[6];
        } else {
            x = 22.0f + *(f32 *)&positions[6];
        }
        y = *(f32 *)((u8 *)&positions[6] + 4);
        current = value;
        color_b = colors[2];
        color_g = colors[1];
        alpha = 0xFF - colors[3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, (u8)alpha, x, y,
                          colors[0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_001068e0(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[5] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_b = 40;
                } else if (current < value) {
                    mode_b = 41;
                }
                y = *(f32 *)((u8 *)&positions[5] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_b, (u8)alpha,
                              *(f32 *)&positions[5], y,
                              colors[0], color_g, color_b, fparg0, 0);
            }
        }
        break;
    case 1:
        value = func_00106940(*(s16 *)arg2) & 0xFFFF;
        positions[4] = positions[0];
        if (value / 100 != 0) {
            x = 30.0f + *(f32 *)&positions[4];
        } else {
            x = 22.0f + *(f32 *)&positions[4];
        }
        y = *(f32 *)((u8 *)&positions[4] + 4);
        current = value;
        color_b = colors[2];
        color_g = colors[1];
        alpha = 0xFF - colors[3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, (u8)alpha, x, y,
                          colors[0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_00106940(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[3] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_a = 40;
                } else if (current < value) {
                    mode_a = 41;
                }
                y = *(f32 *)((u8 *)&positions[3] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_a, (u8)alpha,
                              *(f32 *)&positions[3], y,
                              colors[0], color_g, color_b, fparg0, 0);
            }
        }
        *(f32 *)&positions[0] += 42.0f;
        value = func_00106970(*(s16 *)arg2) & 0xFFFF;
        positions[2] = positions[0];
        if (value / 100 != 0) {
            x = 30.0f + *(f32 *)&positions[2];
        } else {
            x = 22.0f + *(f32 *)&positions[2];
        }
        y = *(f32 *)((u8 *)&positions[2] + 4);
        current = value;
        color_b = colors[2];
        color_g = colors[1];
        alpha = 0xFF - colors[3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, (u8)alpha, x, y,
                          colors[0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_00106970(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[1] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_b = 40;
                } else if (current < value) {
                    mode_b = 41;
                }
                y = *(f32 *)((u8 *)&positions[1] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_b, (u8)alpha,
                              *(f32 *)&positions[1], y,
                              colors[0], color_g, color_b, fparg0, 0);
            }
        }
        break;
    case 2:
        *(f32 *)&positions[0] += 35.0f;
        *(f32 *)((u8 *)&positions[0] + 4) += 4.0f;
        current = 0;
        color_b = colors[2];
        color_g = colors[1];
        alpha = 0xFF - (arg1 & 0xFF);
        for (i = 0; i < 4; i++) {
            func_0046d4c0(0, arg3, 60, (u8)alpha,
                          *(f32 *)&positions[0],
                          *(f32 *)((u8 *)&positions[0] + 4),
                          colors[0], color_g, color_b, fparg0, 0);
            *(f32 *)&positions[0] += 34.0f;
            current++;
        }
        break;
    }
}
