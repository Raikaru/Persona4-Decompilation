/* object 840B / window 832B / differing words (reloc-masked): 135. */
/* Best measured body: temporary indexed-row pointer plus opt_propagation off. */
/* Residuals include the 0xA0 frame, saved-FPR shift, and indexed-address/register drift. */
#pragma opt_propagation off
void func_00363200(u8* arg0, s64 arg1) {
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
    u8* base;
    u8* obj;

    base = arg0;
    temp_16 = (s16)arg1 * 0x28;
    obj = (u8*)(temp_16 + base);
    temp_21 = *(s16*)(obj + 0x34);
    temp_20 = *(s32*)(base + 0xC);
    temp_19 = *(s32*)(obj + 0x2C);
    if (*(s32*)(obj + 0x30) != 0) {
        if (temp_20 == 0) {
            func_0046d730(&D_0064E290, 0x108);
        }
        if (temp_19 == 0) {
            func_0046d730(&D_0064E290, 0x109);
        }
        xy = *(Vec2f*)(temp_16 + base + 0x20);
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
#pragma opt_propagation on
