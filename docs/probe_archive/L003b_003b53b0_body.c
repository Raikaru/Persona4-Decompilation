/* Closest clean-C candidate for func_003b53b0; reverted because lverify normalized_diff remained 414. */
// FUN_003B53B0
#pragma schedule on
void func_003b53b0(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4, f32 fparg1, f32 fparg2) {
    typedef signed __int128 s128;
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    s128 spC0;
    s128 spB0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 temp_f10;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f13;
    f32 var_f14;
    s32 temp_18;
    s32 var_22;
    u8 **var_20;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_3;
    u8 *var_19;
    u8 *var_21;
    u8 *var_4;
    u8 *var_5;
    u8 *var_6;
    u8 *ctx;

    var_4 = arg0;
    var_5 = arg1;
    var_6 = arg2;
    var_f13 = fparg1;
    var_f14 = fparg2;
    ctx = arg4;
    var_22 = 0;
    temp_17 = var_5;
    temp_16 = var_6;
    var_21 = *(u8 **)(ctx + 4);
    var_20 = *(u8 ***)(ctx + 0x34);
    var_19 = *(u8 **)var_4;
    temp_18 = *(s32 *)(var_4 + 4);
    spC0 = *(s32 *)(ctx + 8);
    temp_f22 = 0.5f * *(f32 *)(ctx + 0x70);
    spB0 = *(s32 *)(ctx + 0x38);
    temp_f21 = 0.5f * *(f32 *)(ctx + 0x74);
    if (arg3 > 0) {
        do {
            temp_f20 = func_0044b7b0(*(f32 *)var_20);
            temp_f0 = func_0044b610(*(f32 *)var_20);
            var_22 += 1;
            var_6 = var_19 + temp_18;
            var_4 = (u8 *)(var_22 < arg3);
            temp_f10 = (temp_f0 * *(f32 *)temp_17) -
                (temp_f20 * *(f32 *)temp_16);
            var_20 = (u8 **)((u8 *)var_20 + (s32)spB0);
            temp_3 = var_6 + temp_18;
            var_5 = temp_3 + temp_18;
            temp_f9 = (temp_f0 * *(f32 *)(temp_17 + 4)) -
                (temp_f20 * *(f32 *)(temp_16 + 4));
            temp_f8 = (temp_f0 * *(f32 *)(temp_17 + 8)) -
                (temp_f20 * *(f32 *)(temp_16 + 8));
            temp_f3 = temp_f20 * *(f32 *)temp_17;
            temp_f1 = temp_f20 * *(f32 *)(temp_17 + 4);
            temp_f7 = temp_f20 * *(f32 *)(temp_17 + 8);
            temp_f6 = (*(f32 *)(ctx + 0x68) * temp_f10) +
                (*(f32 *)(ctx + 0x6C) * temp_f3);
            temp_f5 = (*(f32 *)(ctx + 0x68) * temp_f9) +
                (*(f32 *)(ctx + 0x6C) * temp_f1);
            temp_f4 = (*(f32 *)(ctx + 0x68) * temp_f8) +
                (*(f32 *)(ctx + 0x6C) * temp_f7);
            var_f14 = temp_f10 * temp_f22;
            var_f13 = temp_f3 * temp_f21;
            temp_f2 = temp_f8 * temp_f22;
            temp_f3 = temp_f9 * temp_f22;
            temp_f1 = temp_f1 * temp_f21;
            temp_f0 = temp_f7 * temp_f21;
            temp_f9 = -var_f14;
            *(f32 *)(var_19 + 0) = *(f32 *)(var_21 + 0) + temp_f6 + (temp_f9 - var_f13);
            temp_f8 = -temp_f3;
            *(f32 *)(var_19 + 4) = *(f32 *)(var_21 + 4) + temp_f5 + (temp_f8 - temp_f1);
            temp_f7 = -temp_f2;
            *(f32 *)(var_19 + 8) = *(f32 *)(var_21 + 8) + temp_f4 + (temp_f7 - temp_f0);
            var_19 = var_5;
            *(f32 *)(var_6 + 0) = *(f32 *)(var_21 + 0) + temp_f6 + (var_f14 - var_f13);
            *(f32 *)(var_6 + 4) = *(f32 *)(var_21 + 4) + temp_f5 + (temp_f3 - temp_f1);
            *(f32 *)(var_6 + 8) = *(f32 *)(var_21 + 8) + temp_f4 + (temp_f2 - temp_f0);
            *(f32 *)(temp_3 + 0) = *(f32 *)(var_21 + 0) + temp_f6 + (var_f14 + var_f13);
            *(f32 *)(temp_3 + 4) = *(f32 *)(var_21 + 4) + temp_f5 + (temp_f3 + temp_f1);
            *(f32 *)(temp_3 + 8) = *(f32 *)(var_21 + 8) + temp_f4 + (temp_f2 + temp_f0);
            *(f32 *)(var_5 + 0) = *(f32 *)(var_21 + 0) + temp_f6 + (temp_f9 + var_f13);
            *(f32 *)(var_5 + 4) = *(f32 *)(var_21 + 4) + temp_f5 + (temp_f8 + temp_f1);
            *(f32 *)(var_5 + 8) = *(f32 *)(var_21 + 8) + temp_f4 + (temp_f7 + temp_f0);
            var_21 = (u8 *)((u8 *)var_21 + (s32)spC0);
        } while (var_4 != NULL);
    }
}
#pragma schedule off
