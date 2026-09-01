// object 456/window 448/normalized_diff 319
void func_003a8180(u8 *arg0, u8 **arg1)
{
    s32 **var_4;
    s32 *temp_2;
    s32 temp_2_2;
    s32 var_2;
    s32 var_4_2;
    s32 var_6;
    s32 var_6_2;
    s64 var_16_2;
    u8 *temp_17;
    u8 *temp_2_3;
    u8 *temp_5;
    u8 *var_16;
    u8 *var_4_3;
    u8 *var_5;

    var_16 = D_008872E0 + 0x20;
    temp_17 = *(u8 **)(arg0 + 8);
    temp_5 = *(u8 **)(temp_17 + 0x18);
    *(u8 **)(arg0 + 0xC) = *(u8 **)(temp_5 + 0x54);
    var_4 = (s32 **)(temp_5 + iGpffffb730);
    temp_2 = *var_4;
    var_6 = 0;
    if ((temp_2 != NULL) &&
        (*(u16 *)(*(u8 **)(temp_5 + 0x54) + 4) == *temp_2)) {
        var_6 = 1;
    }
    if (var_6 != 0) {
    } else {
        var_4 = func_003ce050(
            var_4, *(u16 *)(*(u8 **)(temp_5 + 0x54) + 4), var_6);
    }
    *(s32 **)(arg0 + 0x10) = *var_4;
    var_4_2 = 8;
    *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) & ~1;
    var_5 = *arg1;
    do {
        var_4_2 -= 1;
        temp_2_2 = *(s32 *)(var_16 + 4);
        *(s32 *)(var_5 + 0) = *(s32 *)(var_16 + 0);
        var_16 += 8;
        *(s32 *)(var_5 + 4) = temp_2_2;
        var_5 += 8;
    } while (var_4_2 > 0);
    var_16_2 = 2;
    temp_2_3 = func_003bfae0(temp_17);
    var_6_2 = 5;
    var_4_3 = D_008872E0 + iGpffffb934 + 0x60;
    if (6 != 0) {
loop_10:
        var_2 = 1;
        if (((*(f32 *)(temp_2_3 + 4) * *(f32 *)(var_4_3 + 4)) +
             (*(f32 *)(temp_2_3 + 0) * *(f32 *)(var_4_3 + 0)) +
             (*(f32 *)(temp_2_3 + 8) * *(f32 *)(var_4_3 + 8)) -
             *(f32 *)(var_4_3 + 0xC)) <= -*(f32 *)(temp_2_3 + 0xC)) {
            var_2 = 0;
        }
        if ((var_2 ^ 1) == 0) {
            var_16_2 = 1;
        } else {
            var_4_3 += 0x14;
            var_6_2 -= 1;
            if (var_6_2 != 0) {
                goto loop_10;
            }
        }
    }
    *(s8 *)(arg0 + 0x29) = 4;
    *(u8 *)(arg0 + 0x28) = iGpffffb984;
    if ((s32)var_16_2 != 2) {
        *(u8 *)(arg0 + 0x28) = *(u8 *)(arg0 + 0x28) | 2;
    }
    *(s8 *)(arg0 + 0x2A) = 1;
}
