/* Closest candidate archive; reverted because lverify normalized_diff was 22 (object 952B, window 960B). */
void func_001b5970(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;
    s16 var_16_2;
    u8 *temp_5;
    u8 *var_16;
    u8 *var_16_3;
    u8 *var_18;

    if (*(u16 *)(D_0076449C + 0x1C) == 1) {
        if (func_00106330(0x38) != 0) var_2 = 5; else var_2 = 8;
        temp_2 = func_0010a900(var_2 & 0xFFFF);
        temp_17 = ~func_0010ce10(temp_2, 0x10E) != 0;
        temp_16 = ~func_0010ce10(temp_2, 0x10F) != 0;
        var_18 = *(u8 **)(D_0076449C + 0x178);
        goto loop_16_check;
loop_16:
        if ((*(s32 *)(var_18 + 0xA64) != 0) &&
            (func_002428f0(*(s32 *)(var_18 + 0xA64), 0) == 0)) {
            if (func_00232730(*(s32 *)(var_18 + 0xA64), 0x224) != 0) {
                func_00231f20(*(s32 *)(var_18 + 0xA64), func_00231f80(*(s32 *)(var_18 + 0xA64)));
                func_00231f50(*(s32 *)(var_18 + 0xA64), func_00232290(*(s32 *)(var_18 + 0xA64)));
            } else if (func_00232730(*(s32 *)(var_18 + 0xA64), 0x223) != 0) {
                func_002325a0(*(s32 *)(var_18 + 0xA64), ((func_00231f80(*(s32 *)(var_18 + 0xA64)) & 0xFFFF) * 0x64) / 1250);
                func_00232610(*(s32 *)(var_18 + 0xA64), ((func_00232290(*(s32 *)(var_18 + 0xA64)) & 0xFFFF) * 0x64) / 1250);
            }
            if (temp_17 != 0) func_002325a0(*(s32 *)(var_18 + 0xA64), ((func_00231f80(*(s32 *)(var_18 + 0xA64)) & 0xFFFF) * 0x64) / 2000);
            if (temp_16 != 0) func_00232610(*(s32 *)(var_18 + 0xA64), ((func_00232290(*(s32 *)(var_18 + 0xA64)) & 0xFFFF) * 0x64) / 2000);
        }
        var_18 = *(u8 **)(var_18 + 0xA6C);
loop_16_check:
        if (var_18 != NULL) goto loop_16;
    }
    func_001bdd60();
    func_002038c0(*(s32 *)(D_0076449C + 0xDD4));
    var_16 = *(u8 **)(D_0076449C + 0x178);
    goto loop_21_check;
loop_21:
    temp_4_2 = *(s32 *)(var_16 + 0xA64);
    if (temp_4_2 != 0) func_002339d0(temp_4_2);
    var_16 = *(u8 **)(var_16 + 0xA6C);
loop_21_check:
    if (var_16 != NULL) goto loop_21;
    if (func_00106330(0x3D) == 0) {
        for (var_16_2 = 1; (u16)var_16_2 < 0xB; ++var_16_2)
            *(s8 *)(func_00105510(var_16_2) + 0x10) = 0;
    }
    var_16_3 = *(u8 **)(D_0076449C + 0x174);
    goto loop_30_check;
loop_30:
    if (*(u16 *)(var_16_3 + 0xC) != 0x24) func_001b0800(var_16_3, 0x24);
    var_16_3 = *(u8 **)(var_16_3 + 0x450);
loop_30_check:
    if (var_16_3 != NULL) goto loop_30;
    func_00193d30();
    temp_5 = D_0076449C;
    if ((*(s32 *)(temp_5 + 0x10) & 0x20000000) &&
        func_002428f0(*(s32 *)(*(u8 **)(*(u8 **)(temp_5 + 0x170) + 0x30) + 0xA64), 0) != 0) {
        func_00231f20(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 1);
        func_002326f0(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0x80000);
    }
    temp_4_3 = *(s32 *)(D_0076449C + 0xDD4);
    if (temp_4_3 != 0) {
        func_00452080((KwlnTask *)temp_4_3);
        *(s32 *)(D_0076449C + 0xDD4) = 0;
    }
}
