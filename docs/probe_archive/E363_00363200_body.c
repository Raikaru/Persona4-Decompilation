/* object 828 / window 832 / normalized_diff 561; differing offsets: 0x030, 0x031, 0x032, 0x034, 0x038, 0x039, 0x03C, 0x03E, 0x040, 0x042, 0x044, 0x045, 0x046, 0x048, 0x049, 0x04A */
/* Corrected and verified declarations: func_00104e30(s16), func_00104ce0(s16), func_0046d730(void *, s32), func_00104d50(s16), func_00363080(f32, f32, f32), func_0034f460(s32, s32, s8, s8, s8, s64, f32, f32). func_00104dc0(s16) was already correct. */
/* Probed indexed-address helper, cached pointer/integer locals, aggregate copy forms, declaration order, float locals, common-subexpression pragmas, and draw-call argument widths; no exact match. */

void func_00363200(u8 *arg0, s64 arg1) {
    Vec2f xy;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    s16 temp_21;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_17;
    s32 temp_18;
    s32 temp_20;
    s32 temp_19;
    s32 temp_21_2;
    u8 *base;

    base = arg0;
    temp_16 = (s16)arg1 * 0x28;
    temp_21 = *(s16 *)(temp_16 + base + 0x34);
    temp_20 = *(s32 *)(base + 0xC);
    temp_19 = *(s32 *)(temp_16 + base + 0x2C);
    if (*(s32 *)(temp_16 + base + 0x30) != 0) {
        if (temp_20 == 0) {
            func_0046d730(&D_0064E290, 0x108);
        }
        if (temp_19 == 0) {
            func_0046d730(&D_0064E290, 0x109);
        }
        xy = *(Vec2f *)(temp_16 + base + 0x20);
        temp_18 = func_00104ce0(temp_21) & 0xFFFF;
        temp_17 = func_00104dc0(temp_21) & 0xFFFF;
        temp_16_2 = func_00104d50(temp_21) & 0xFFFF;
        temp_21_2 = func_00104e30(temp_21) & 0xFFFF;
        func_0034f460(temp_19, 0, 0xFF, 0xFF, 0xFF, 0xFF, xy.x, xy.y);
        func_0034f460(temp_20, 0, 0xFF, 0xFF, 0xFF, 0xFF,
                      8.0f + xy.x, 31.0f + xy.y);
        if (temp_18 >= 0) {
            temp_f22 = (f32)temp_18;
        } else {
            temp_f22 = (f32)(s32)(((u32)temp_18 >> 1) | (temp_18 & 1));
            temp_f22 += temp_f22;
        }
        if (temp_17 >= 0) {
            temp_f20 = (f32)temp_17;
        } else {
            temp_f20 = (f32)(s32)(((u32)temp_17 >> 1) | (temp_17 & 1));
            temp_f20 += temp_f20;
        }
        temp_f22 = temp_f22 / temp_f20;
        temp_f20 = 35.0f + xy.y;
        temp_f21 = 13.0f + xy.x;
        func_0034f460(temp_20, 1, 0xFF, 0xFF, 0xFF, 0xFF,
                      temp_f21, temp_f20);
        func_00363080(temp_f21, temp_f20, temp_f22);
        temp_f20 = 39.0f + xy.y;
        func_0034f460(temp_20, 2, 0xFF, 0xFF, 0xFF, 0xFF,
                      temp_f21, temp_f20);
        if (temp_16_2 >= 0) {
            temp_f22 = (f32)temp_16_2;
        } else {
            temp_f22 = (f32)(s32)(((u32)temp_16_2 >> 1) | (temp_16_2 & 1));
            temp_f22 += temp_f22;
        }
        func_00363080(
            temp_f21,
            temp_f20,
            temp_f22 / ((temp_21_2 >= 0)
                            ? (f32)temp_21_2
                            : 2.0f * (f32)(s32)(((u32)temp_21_2 >> 1) |
                                               (temp_21_2 & 1))));
    }
}
