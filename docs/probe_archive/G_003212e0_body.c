/* object 1520B / window 1472B / normalized_diff 329 (lane G array-body attempt); differing offsets: frame-top colour-slot layout, byte-copy lbu/sb ordering, var_16 widening, u8 arg1 sb conversion, u_long128 spC0/spB0 sq widening, float-to-u8 wrap guard arms; classification: slot-layout + byte-copy scheduling + signed-narrowing + aggregate-pointer widening floors; levers tried: u8[4] colour arrays, u8 individual locals (collapse to scrambled 6-byte frame-top), (s64)(s16) cast for var_16, u8 and s8 parameter variants, float wrap guard with explicit 2^31 branch; not probed: FclByte4 group locals, different u_long128 cast sequences, peephole/schedule pragma combinations. */
void func_003212e0(u8 *arg0, u8 arg1, s8 arg2) {
    u8 spD7;
    u8 spD8[4];
    u8 spDC[4];
    u8 spE0[4];
    u8 spE4[4];
    u8 spE8[4];
    u8 spEC[4];
    u_long128 spC0;
    u_long128 spB0;
    f32 temp_f0;
    f32 f20;
    f32 f15;
    s32 temp_7;
    s32 var_3;
    s64 var_16;
    s16 i;
    s16 j;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_21_3;
    u8 *cell2;
    s32 temp_22;

    spD7 = arg1;
    temp_18 = *(u8 **)(arg0 + 0x38);
    var_16 = (s64)(s16)(((u16)func_0010b5b0() - 1) + (((u16)func_0010b5b0() - 1) * 0xC));
    func_0010b5b0();
    func_0010b5b0();
    func_002b2a60(spE0, 0, 0, 0x99, 0xFF);
    spEC[0] = spE0[0];
    spEC[1] = spE0[1];
    spEC[2] = spE0[2];
    spEC[3] = spE0[3];
    func_002b2a60(spDC, 0x49, 0x72, 0xFF, 0xFF);
    spE8[0] = spDC[0];
    spE8[1] = spDC[1];
    spE8[2] = spDC[2];
    spE8[3] = spDC[3];
    func_002b2a60(spD8, 0x49, 0x72, 0xFF, 0xFF);
    spE4[0] = spD8[0];
    spE4[1] = spD8[1];
    spE4[2] = spD8[2];
    spE4[3] = spD8[3];
    if (arg2 == 1) {
        func_002b2a60(spE8, 0, 0, 0x99, 0xFF);
        func_002b2a60(spEC, 0x49, 0x72, 0xFF, 0xFF);
        func_002b2a60(spE4, 0x49, 0x72, 0xFF, 0xFF);
        var_16 = 0;
    }
    spC0 = (u_long128)(temp_18 + (s32)var_16);
    for (i = 0; (s16)i < (s32)(u16)func_0010b5b0(); i = (s16)(i + 1)) {
        j = 0;
        temp_22 = (s32)i * 0xC;
        spB0 = (u_long128)(temp_18 + temp_22);
        temp_17 = temp_18 + ((s32)i * 4);
        for (; (s16)j < (s32)(u16)func_0010b5b0(); j = (s16)(j + 1)) {
            temp_2 = (u8 *)spB0 + (s32)j;
            if (*(s8 *)(temp_2 + 0x18C) == 0) {
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j) & 0x200) >> 9) == 0) {
                    func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j), *(s32 *)spE8, *(s32 *)spEC, 0, 2, 1);
                    if (*(s8 *)(func_002e4870(0) + temp_22 + (s32)j + 0x14) > 0) {
                        func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j), *(s32 *)spE8, *(s32 *)spE4, 0, 2, 1);
                        cell2 = func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j);
                        func_002b82d0(cell2, *(u8 *)(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j) + 0x5E), 0xCC, 0, 2, 1);
                    }
                    *(s8 *)(temp_2 + 0x18C) = 1;
                }
            } else if ((*(s8 *)((u8 *)spC0 + 0x18C) == 1) && ((s32)var_16 == (j + temp_22))) {
                temp_21_3 = temp_18 + ((u16)func_0010b5b0() * 4);
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_21_3 + 0x150), (s64)(s8)((u16)func_0010b5b0() - 1)) & 0x200) >> 9) == 0) {
                    *(u8 *)(temp_18 + 1) = spD7;
                    if (*(s8 *)(temp_18 + 0x128) == -1) {
                        *(s16 *)(temp_18 + 0x11E) = 0;
                    }
                }
            }
        }
        f20 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)(i + 0x21C)) + 0x42);
        f15 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)(i + 0x21C)) + 0x40);
        temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, f20, f15);
        if (temp_f0 >= 2147483648.0f) {
            var_3 = ((s32)(temp_f0 - 2147483648.0f) | 0x80000000) & 0xFF;
        } else {
            var_3 = (s32)temp_f0 & 0xFF;
        }
        temp_7 = var_3 & 0xFF;
        if (*(s16 *)((u8 *)temp_18 + 0x11E) == i) {
            var_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
        } else {
            var_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
        }
        if ((s16)i < *(s32 *)((u8 *)func_002e4870(0) + 8)) {
            f20 = (f32)(s32)((s16)i * 0x17 + 0x80);
            func_00275820(113.0f, f20, 43.0f, var_3, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)((u8 *)func_002e48a0(0, i) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
        }
    }
}