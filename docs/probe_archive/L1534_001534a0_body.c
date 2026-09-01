/* func_001534a0 archive: object 768B / retail window 800B / normalized_diff 164. Differing word offsets are recorded in build/L1534_probe_fndiff.txt (first 0x2C; 164 total). INT-to-float site: arg2 uses plain (f32)(u32)arg2; retail sequence is bltz/mtc1/cvt.s.w or srl/andi/or/mtc1/cvt.s.w/add.s. Corrected block-scope func_00152e50 declaration to (s8 *,s8 *,f32). Pointer/global forms, declaration orders, loop/switch shapes, and direct-vs-aliased locals were ruled out; retain fallback. */
s8 *func_001534a0(u8 *arg0, s8 *arg1, s32 arg2) {
    extern void func_00152e50(s8 *arg0, s8 *arg1, f32 arg2);
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_2_7;
    u8 *temp_7;
    u8 *temp_8;
    u8 *var_5;
    u8 *var_6;
    u8 *temp_2;
    u8 *second_arg;
    u16 temp_3_3;
    u32 var_16;
    u32 var_19;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_4;

    second_arg = (u8 *)arg1;
    temp_f1 = 90.0f;
    temp_f0 = (f32)(u32)arg2;
    temp_f20 = temp_f1 * temp_f0;
    if (*(s32 *)(arg0 + 0) & 1) {
        return NULL;
    }
    func_0044ea90(&D_005EFC80, 0xA2A);
    temp_2 = D_008873F4[0](1, 0xAB0, 0x40000);
    *(s32 *)(temp_2 + 0) = *(s32 *)(arg0 + 0) | 2;
    *(s16 *)(temp_2 + 4) = *(s16 *)(arg0 + 4);
    *(s16 *)(temp_2 + 6) = *(s16 *)(arg0 + 6);
    temp_4 = *(s32 *)(arg0 + 8);
    if (temp_4 != 0) {
        temp_2_2 = func_003c0520(temp_4);
        *(s32 *)(temp_2 + 8) = temp_2_2;
        *(s32 *)(temp_2 + 0xC) = func_00462ae0((void *)(u32)temp_2_2);
    }
    temp_4_2 = *(s32 *)(arg0 + 0x10);
    if (temp_4_2 != 0) {
        *(s32 *)(temp_2 + 0x10) = func_003c0520(temp_4_2);
    }
    temp_4_3 = *(s32 *)(arg0 + 0x14);
    if (temp_4_3 != 0) {
        *(s32 *)(temp_2 + 0x14) = func_003c0520(temp_4_3);
    }
    *(u32 *)(temp_2 + 0x18) = *(u32 *)(arg0 + 0x18);
    var_16 = 0;
    while (var_16 < *(u32 *)(arg0 + 0x18)) {
        temp_3 = var_16 * 4;
        temp_4_4 = *(s32 *)(arg0 + temp_3 + 0x1C);
        if (temp_4_4 != 0) {
            temp_18 = (u8 *)temp_2 + temp_3;
            temp_2_3 = func_003c0520(temp_4_4);
            *(s32 *)(temp_18 + 0x1C) = temp_2_3;
            *(s32 *)(temp_18 + 0x9C) = func_00462ae0((void *)(u32)temp_2_3);
        }
        var_16 += 1;
    }
    *(u32 *)(temp_2 + 0x11C) = *(u32 *)(arg0 + 0x11C);
    var_19 = 0;
    while (var_19 < *(u32 *)(arg0 + 0x11C)) {
        temp_2_4 = var_19 * 0x18;
        temp_8 = arg0 + temp_2_4;
        temp_7 = temp_8 + 0x120;
        temp_18_2 = (u8 *)temp_2 + temp_2_4;
        var_5 = temp_18_2 + 0x120;
        var_4 = 3;
        var_6 = temp_7;
        while (var_4 > 0) {
            temp_3_2 = *(s32 *)(var_6 + 0);
            temp_2_5 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_4 -= 1;
            *(s32 *)(var_5 + 0) = temp_3_2;
            *(s32 *)(var_5 + 4) = temp_2_5;
            var_5 += 8;
        }
        temp_3_3 = *(u16 *)(temp_8 + 0x120);
        if (temp_3_3 == 0 || temp_3_3 == 2) {
            temp_2_6 = var_19 * 0x18;
            temp_17 = arg0 + temp_2_6;
            temp_2_7 = (u8 *)temp_2 + temp_2_6;
            *(s32 *)(temp_2_7 + 0x12C) = func_00478750(*(s32 *)(temp_17 + 0x12C));
            func_0047a1c0((void *)(u32)*(s32 *)(temp_2_7 + 0x12C), *(u8 **)(temp_17 + 0x128), 0);
            if (*(u16 *)(temp_17 + 0x122) & 2) {
                *(u16 *)(temp_18_2 + 0x122) |= 2;
            }
        } else if (temp_3_3 == 1) {
            *(s32 *)(temp_18_2 + 0x130) = func_004b11b0(*(s32 *)(temp_8 + 0x130));
        }
        var_19 += 1;
    }
    *(f32 *)(temp_2 + 0xA24) = *(f32 *)(arg0 + 0xA24);
    *(f32 *)(temp_2 + 0xA28) = *(f32 *)(arg0 + 0xA28);
    *(f32 *)(temp_2 + 0xA2C) = *(f32 *)(arg0 + 0xA2C);
    func_00153300((s8 *)temp_2, temp_f20);
    func_00152e50((s8 *)temp_2, (s8 *)second_arg, temp_f20);
    return (s8 *)temp_2;
}
