/* object 812 / window 832 / normalized_diff 548; first differing offsets: 0x30, 0x31, 0x32, 0x34, 0x38, 0x39, 0x3C, 0x3E, 0x40, 0x42, 0x44, 0x45, 0x46, 0x48, 0x49, 0x4A */
/* Retail int-to-float sites: temp_18 -> (f32)(u32)temp_18; temp_17 -> (f32)(u32)temp_17; temp_16_2 -> (f32)(u32)temp_16_2; temp_21_2 -> (f32)(u32)temp_21_2. */
/* Corrected declarations in source: func_00104e30(s16), func_00104ce0(s16), func_0046d730(void *, s32), func_00104d50(s16), func_00363080(f32, f32, f32) as defined in this TU. Ruled out: hand-written sign fixups, alternate pointer/index locals, aggregate xy spill forms, declaration-order variants, integer-domain base address, split base/pointer locals, and measured optimization_level 1. */

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
    u8* base = arg0;

    temp_16 = (s16)arg1 * 0x28;
    temp_21 = *(s16*)(temp_16 + base + 0x34);
    temp_20 = *(s32*)(base + 0xC);
    temp_19 = *(s32*)(temp_16 + base + 0x2C);
    if (*(s32*)(temp_16 + base + 0x30) != 0) {
        if (temp_20 == 0) {
            func_0046d730(D_0064E290, 0x108);
        }
        if (temp_19 == 0) {
            func_0046d730(D_0064E290, 0x109);
        }
        xy = *(Vec2f*)(temp_16 + base + 0x20);
        temp_18 = func_00104ce0(temp_21) & 0xFFFF;
        temp_17 = func_00104dc0(temp_21) & 0xFFFF;
        temp_16_2 = func_00104d50(temp_21) & 0xFFFF;
        temp_21_2 = func_00104e30(temp_21) & 0xFFFF;
        func_0034f460(temp_19, 0, 0xFF, 0xFF, 0xFF, 0xFF, xy.x, xy.y);
        func_0034f460(temp_20, 0, 0xFF, 0xFF, 0xFF, 0xFF,
                      8.0f + xy.x, 31.0f + xy.y);
        temp_f22 = (f32)(u32)temp_18;
        temp_f20 = (f32)(u32)temp_17;
        temp_f22 = temp_f22 / temp_f20;
        temp_f20 = 35.0f + xy.y;
        temp_f21 = 13.0f + xy.x;
        func_0034f460(temp_20, 1, 0xFF, 0xFF, 0xFF, 0xFF,
                      temp_f21, temp_f20);
        func_00363080(temp_f21, temp_f20, temp_f22);
        temp_f20 = 39.0f + xy.y;
        func_0034f460(temp_20, 2, 0xFF, 0xFF, 0xFF, 0xFF,
                      temp_f21, temp_f20);
        temp_f22 = (f32)(u32)temp_16_2;
        func_00363080(temp_f21, temp_f20,
                      temp_f22 / (f32)(u32)temp_21_2);
    }
}
