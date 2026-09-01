/* Archive: object_size 1044, window 1056; honest cast body normalized_diff 16 (differing byte offsets 856-857, 876-877, 892-893, 908-909, 924-925, 940-941, 952-953, 964-965); four int-to-float sites use (f32)(u32)temp_19, (f32)(u32)temp_18, (f32)(u32)temp_17, (f32)(u32)temp_16 for retail lbu loads at offsets 0,1,2,3; corrected block-scope extern f32 prototypes for func_0044b610(f32), func_0044b7b0(f32), and fabsf(f32); measured opt_loop_invariants on/off bracket; p4_add_f32 inline reaches normalized_diff 0 but is rejected as codegen scaffolding, so it is not restored in the live source. */
// FUN_004A7E30 (archived matching probe; helper calls below are scaffolding-only)
s32 func_004a7e30(u8 *arg0, u8 *arg1)
{
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern f32 fabsf(f32 arg0);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    s32 temp_6;
    s32 temp_5;
    s32 temp_4;
    s32 temp_3;
    u32 var_8;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u8 *temp_7;

    if (*(f32 *)(arg0 + 0x18) > 640.0f ||
        *(f32 *)(arg0 + 0x1C) > 448.0f ||
        *(f32 *)(arg0 + 0x20) < 0.0f ||
        *(f32 *)(arg0 + 0x24) < 0.0f) {
        return 0;
    }
    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f5 = D_008872F8[0];
    var_8 = 0;
    goto loop_004a7e30_check;
loop_004a7e30_body:
    temp_7 = arg1 + (var_8 << 6);
    *(f32 *)(temp_7 + 0x18) = temp_f6;
    *(f32 *)(temp_7 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_7 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_7 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_7 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_7 + 8) = temp_f5;
    var_8 += 1;
loop_004a7e30_check:
    if (var_8 < 4U) {
        goto loop_004a7e30_body;
    }
    temp_f26 = *(f32 *)(arg0 + 0x10) / D_00922D94[0];
    temp_f25 = *(f32 *)(arg0 + 0x14) / D_00922D98[0];
    temp_f6 = *(f32 *)(arg0 + 0x0C);
    temp_f5 = *(f32 *)(arg0 + 0x18);
    temp_f4 = temp_f5 / D_00922D94[0];
    temp_f3 = *(f32 *)(arg0 + 0x1C) / D_00922D98[0];
    temp_f2 = *(f32 *)(arg0 + 0x20) / D_00922D94[0];
    temp_f1 = *(f32 *)(arg0 + 0x24) / D_00922D98[0];
    temp_f0 = temp_f4 - temp_f26;
    temp_f24 = temp_f6 * temp_f0;
    temp_f0 = temp_f3 - temp_f25;
    temp_f23 = temp_f6 * temp_f0;
    temp_f0 = temp_f2 - temp_f26;
    temp_f22 = temp_f6 * temp_f0;
    temp_f0 = temp_f1 - temp_f25;
    temp_f21 = temp_f6 * temp_f0;
    temp_f0 = temp_f24 - temp_f22;
    temp_f3 = fabsf(temp_f0);
    temp_f0 = temp_f23 - temp_f21;
    temp_f2 = fabsf(temp_f0);
    if (!(temp_f3 > 0.0f &&
          temp_f2 > 0.0f &&
          temp_f3 < 7.0f &&
          temp_f2 < 7.0f)) {
        return 0;
    }
    *(f32 *)(arg1 + 0) = temp_f5;
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    if (*(f32 *)(arg0 + 8) == 0.0f) {
        temp_f3 = temp_f24 + temp_f26;
        temp_f2 = temp_f22 + temp_f26;
        temp_f1 = temp_f23 + temp_f25;
        temp_f0 = temp_f21 + temp_f25;
        *(f32 *)(arg1 + 0x10) = temp_f3;
        *(f32 *)(arg1 + 0x14) = temp_f1;
        *(f32 *)(arg1 + 0x50) = temp_f3;
        *(f32 *)(arg1 + 0x54) = temp_f0;
        *(f32 *)(arg1 + 0x90) = temp_f2;
        *(f32 *)(arg1 + 0x94) = temp_f0;
        *(f32 *)(arg1 + 0xD0) = temp_f2;
        *(f32 *)(arg1 + 0xD4) = temp_f1;
    } else {
        temp_f20 = func_0044b610(*(f32 *)(arg0 + 8));
        temp_f0_2 = func_0044b7b0(*(f32 *)(arg0 + 8));
        temp_f6 = temp_f23 * temp_f0_2;
        temp_f3 = temp_f24 * temp_f20;
        temp_f1 = temp_f3 - temp_f6;
        temp_f1 = p4_add_f32(temp_f26, temp_f1);
        *(f32 *)(arg1 + 0x10) = temp_f1;
        temp_f5 = temp_f23 * temp_f20;
        temp_f2 = temp_f24 * temp_f0_2;
        temp_f1 = temp_f2 + temp_f5;
        temp_f1 = p4_add_f32(temp_f25, temp_f1);
        *(f32 *)(arg1 + 0x14) = temp_f1;
        temp_f4 = temp_f21 * temp_f0_2;
        temp_f1 = temp_f3 - temp_f4;
        temp_f1 = p4_add_f32(temp_f26, temp_f1);
        *(f32 *)(arg1 + 0x50) = temp_f1;
        temp_f3 = temp_f21 * temp_f20;
        temp_f1 = temp_f2 + temp_f3;
        temp_f1 = p4_add_f32(temp_f25, temp_f1);
        *(f32 *)(arg1 + 0x54) = temp_f1;
        temp_f2 = temp_f22 * temp_f20;
        temp_f1 = temp_f2 - temp_f4;
        temp_f1 = p4_add_f32(temp_f26, temp_f1);
        *(f32 *)(arg1 + 0x90) = temp_f1;
        temp_f1 = temp_f22 * temp_f0_2;
        temp_f0 = temp_f1 + temp_f3;
        temp_f0 = p4_add_f32(temp_f25, temp_f0);
        *(f32 *)(arg1 + 0x94) = temp_f0;
        temp_f0 = temp_f2 - temp_f6;
        temp_f0 = p4_add_f32(temp_f26, temp_f0);
        *(f32 *)(arg1 + 0xD0) = temp_f0;
        temp_f0 = temp_f1 + temp_f5;
        temp_f0 = p4_add_f32(temp_f25, temp_f0);
        *(f32 *)(arg1 + 0xD4) = temp_f0;
    }
    return 1;
}
/* measured: loop-invariant conversion preloads for func_004a7e30. */
#pragma opt_loop_invariants on
/* measured: close loop-invariant conversion scope for func_004a7e30. */
#pragma opt_loop_invariants off
