/* object 764B/window 768B, normalized_diff 24 (re-measured); differing offsets begin 448-468 and classify as register/materialisation order around the second func_0025ecd0 call: retail preloads 1000.0f before the slti/branch and uses $at, while candidate delays f14 and uses $v0. A named f32 temp_f14 assignment before the guard did not move code (nd 24). Existing plain-C body is preserved verbatim below; source is restored to INCLUDE_ASM at cutoff. */
// FUN_0017CD60
s32 func_0017cd60(u8 *arg0)
{
    u8 *temp_16;
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f1;
    s32 var_3;
    u16 temp_2;
    f32 temp_f12;
    f32 temp_f13;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 0) {
        return 0;
    }
    switch (*(s32 *)temp_16) {
    case 0:
        *(s32 *)(temp_16 + 8) = (s32)func_0046a770(D_005E5850);
        *(u16 *)(temp_16 + 0xC) = 320;
        *(u16 *)(temp_16 + 0xE) = 240;
        *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
        goto done;
    case 1:
        temp_2 = *(u16 *)(temp_16 + 0x10);
        var_f1 = (f32)(u16)temp_2;
        temp_f20 = func_0044b7b0((iGpffff82fc * var_f1) / 15.0f);
        temp_f21 = 1.0f - temp_f20;
        func_0025ecd0((f32)(*(u16 *)(temp_16 + 0xC) + 10),
                      (f32)(*(u16 *)(temp_16 + 0xE) + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(*(u32 *)(temp_16 + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        var_3 = (s32)(128.0f * temp_f20) + 0x80;
        temp_f12 = (f32)(*(u16 *)(temp_16 + 0xC) + 0x6E);
        temp_f13 = (f32)(*(u16 *)(temp_16 + 0xE) + 0x22);
        if (var_3 >= 0x100) {
            var_3 = 0xFF;
        }
        func_0025ecd0(temp_f12, temp_f13, 1000.0f,
                      0xFFFFFF, var_3 & 0xFF, 0xC6, (void *)(*(u32 *)(temp_16 + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        func_0025ecd0((f32)(*(u16 *)(temp_16 + 0xC) + 0x6E),
                      (f32)(*(u16 *)(temp_16 + 0xE) + 0xF +
                            (s32)(3.0f * temp_f21)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(*(u32 *)(temp_16 + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        temp_2 = *(u16 *)(temp_16 + 0x10) + 1;
        *(u16 *)(temp_16 + 0x10) = temp_2;
        if (*(u16 *)(temp_16 + 0x10) >= 0x10) {
            *(u16 *)(temp_16 + 0x10) = 0;
        }
loop_ready:
        goto done;
    case 2:
        return -1;
    default:
        goto done;
    }
done:
    return 0;
}
