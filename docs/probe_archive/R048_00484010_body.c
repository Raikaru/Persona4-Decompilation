/* object 420B/window 432B, normalized_diff 226; differing offsets 88,104,112-168,176-264,268-296,304-352,364-424; classification: undersized by 12B despite exact 160B frame and saved s8-s0 prologue; block-scope callee declarations corrected for func_003c22f0/func_003c2150/func_003c2290/func_003c42b0/func_00483a00; ruled out optimization_level 1, aggregate return/local alias probes; live body restored to INCLUDE_ASM. */
u8 *func_00484010(u8 *arg0)
{
    /* measured: O1 probe for the retail nine-register frame. */
    #pragma optimization_level 1
    u8 *temp_22;
    s32 temp_3;
    s32 temp_5;
    s32 var_16;
    s32 var_16_2;
    s32 var_20;
    s32 var_3;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_23;
    u8 *var_17;
    u8 *var_4;
    u8 *var_5;
    u8 *temp_6;
    void func_003c22f0(u8 *arg0);
    s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2);
    u8 *func_003c2290(u8 *arg0, s32 arg1);
    u8 *func_003c42b0(u8 **arg0, u8 *arg1);
    u8 *func_00483a00(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

    temp_23 = func_00483a00(
        *(u16 *)(arg0 + 0x48),
        *(u16 *)(arg0 + 8),
        *(u16 *)(arg0 + 0xA),
        *(s32 *)(arg0 + 4));
    temp_22 = *(u8 **)(temp_23 + 0x54);
    temp_19 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 0x18);
    temp_18 = *(u8 **)(*(u8 **)(temp_23 + 0x10) + 0x18);
    var_16 = 0;
    while (var_16 < *(s16 *)(arg0 + 0x48)) {
        temp_3 = var_16 * 4;
        temp_5 = *(s32 *)(*(u8 **)(temp_22 + temp_3));
        if (temp_5 != 0) {
            func_003c42b0(
                (u8 **)(temp_22 + temp_3),
                (u8 *)temp_5);
        }
        var_16 += 1;
    }
    func_003c2290(temp_19, 1);
    var_5 = *(u8 **)(temp_19 + 0x2C);
    var_4 = *(u8 **)(temp_18 + 0x2C);
    var_17 = var_4;
    var_3 = 0;
    while (var_3 < *(s16 *)(arg0 + 0x4C)) {
        *(u16 *)var_4 = *(u16 *)var_5;
        *(u16 *)(var_4 + 2) = *(u16 *)(var_5 + 2);
        *(u16 *)(var_4 + 4) = *(u16 *)(var_5 + 4);
        var_5 += 8;
        var_4 += 8;
        var_3 += 1;
    }
    var_20 = 0;
    while (var_20 < *(s16 *)(arg0 + 0x48)) {
        temp_6 = (u8 *)(temp_22 + var_20 * 4);
        var_16_2 = 0;
        while (var_16_2 < *(s16 *)(arg0 + 0xA)) {
            func_003c2150(temp_18, var_17,
                          *(s32 *)temp_6);
            var_17 += 8;
            var_16_2 += 1;
        }
        var_20 += 1;
    }
    func_003c22f0(temp_19);
    return temp_23;
    /* measured: closes O1 probe for the retail nine-register frame. */
    #pragma optimization_level 2
}
