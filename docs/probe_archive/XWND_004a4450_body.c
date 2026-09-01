/* measured: object 824 bytes versus 832-byte retail window; normalized_diff 321; first differing offsets 45, 56, 66, 90, 102, 105, 106, 110, 113, 114, 128, 129, 134, 138, 162, 178; int-to-float sites rewritten as (f32)(u32)var_9 and (f32)(u32)temp_10 from both srl/andi/or/mtc1/cvt.s.w paths; float-to-unsigned alpha rewritten as (u32)temp_f0; final func_003c22f0 tail reconstructed. Ruled out hand-written sign-fixup branches and the original void-pointer function prototype. */
void func_004a4450(u8 *arg0, u8 *arg1)
{
    f32 temp_f8;
    f32 temp_f7;
    f32 temp_f6;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    s32 temp_10;
    s32 temp_8;
    s32 temp_7;
    s32 temp_6;
    s32 temp_5;
    s32 temp_4;
    s32 var_10;
    u32 temp_23;
    u32 var_20;
    u32 var_9;
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_3;
    u8 *var_17;
    u8 *var_19;
    u8 *temp_20;
    u8 *temp_21;
    u8 *temp_22;

    temp_23 = *(u32 *)(arg1 + 0x38);
    if (temp_23 != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF8);
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        temp_18 = *(u8 **)(temp_3 + 0x30);
        var_19 = temp_18;
        temp_16 = *(u8 **)(temp_3 + 0x34);
        var_17 = temp_16;
        temp_f2 = 3.0f;
        temp_f8 = *(f32 *)(arg1 + 0x90) / temp_f2;
        temp_8 = *(s32 *)(arg1 + 0x8C);
        temp_f1 = (f32)temp_8;
        temp_7 = (s32)(*(f32 *)(arg1 + 0x78) * temp_f1);
        temp_6 = (s32)(*(f32 *)(arg1 + 0x7C) * temp_f1);
        temp_5 = temp_8 + 1;
        temp_4 = temp_5 * 4;
        temp_10 = temp_8 - temp_6;
        temp_f7 = 2.0f * temp_f8;
        temp_f6 = 3.0f * temp_f8;
        temp_f2 = 255.0f;
        temp_f1 = (f32)temp_10;
        var_9 = 0;
        while (var_9 < (u32)temp_5) {
            if (var_9 < (u32)temp_7) {
                var_f0 = (f32)(u32)var_9;
                var_f0_2 = var_f0 / (f32)temp_7;
            } else if ((u32)temp_6 < var_9) {
                temp_10 = temp_8 - var_9;
                var_f0_3 = (f32)(u32)temp_10;
                var_f0_2 = var_f0_3 / temp_f1;
            } else {
                var_f0_2 = 1.0f;
            }
            *(s32 *)var_19 = 0xFFFFFF;
            temp_f0 = temp_f2 * var_f0_2;
            var_10 = (u32)temp_f0;
            *(s32 *)(var_19 + 4) = (var_10 << 24) | 0xFFFFFF;
            *(u8 *)(var_19 + 8) = *(u8 *)(var_19 + 4);
            *(u8 *)(var_19 + 9) = *(u8 *)(var_19 + 5);
            *(u8 *)(var_19 + 0xA) = *(u8 *)(var_19 + 6);
            *(u8 *)(var_19 + 0xB) = *(u8 *)(var_19 + 7);
            *(s32 *)(var_19 + 0xC) = 0xFFFFFF;
            var_19 += 0x10;
            *(s32 *)var_17 = 0;
            *(f32 *)(var_17 + 8) = temp_f8;
            *(f32 *)(var_17 + 0x10) = temp_f7;
            *(f32 *)(var_17 + 0x18) = temp_f6;
            var_17 += 0x20;
            var_9 += 1;
        }
        var_20 = 1;
        temp_6 = temp_4 * 4;
        temp_7 = temp_4 * 8;
        while (var_20 < temp_23) {
            func_0043f810(var_19, temp_18, (void *)(u32)temp_6);
            var_19 += temp_6;
            func_0043f810(var_17, temp_16, (void *)(u32)temp_7);
            var_17 += temp_7;
            var_20 += 1;
        }
    }
        temp_20 = *(u8 **)(arg0 + 4);
        temp_21 = *(u8 **)(temp_20 + 0x10);
        temp_22 = *(u8 **)(temp_21 + 0x18);
        func_003c22f0(temp_22);
        if (*(u16 *)temp_20 & 4) {
            *(u16 *)(temp_22 + 0xC) = *(u16 *)(temp_22 + 0xC) | 1;
        }
}
