/* Fresh remeasurement: object 464 bytes, retail window 464 bytes, normalized_diff 152; differing offsets begin 48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,140,148,152,160,164,168,180,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,332,336,344,348,352,356,360,364,368,372,380,384,388. Current residual is a broad register/addressing/control-flow mismatch across both table-search loops; archive's nd56 is stale in the current declaration environment. Exact-size, no object oversize condition; restored INCLUDE_ASM fallback. */
void func_00313b50(u8 *arg0)
{
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern void func_002e7920(s32 *arg0, s32 *arg1);
    extern void func_00313d20(u8 *arg0, u8 arg1, u8 arg2, s32 arg3);
    s32 sp4C;
    s32 sp48;
    s32 temp_18;
    s32 temp_7;
    s32 temp_8;
    s64 var_2;
    s64 var_2_2;
    s64 var_9;
    s64 var_9_2;
    s8 temp_4;
    s8 temp_4_2;
    u8 temp_18_2;
    u8 *temp_16;
    u8 *temp_5;
    u8 *temp_5_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_18 = func_002e78e0() & 0xFF;
    temp_8 = func_002e78a0() & 0xFF;
    var_9 = 0;
    temp_7 = temp_18 & 0xFF;
loop_1:
    var_9 = (s64)(s8)(var_9 + 1);
    temp_5 = (u8 *)D_006432B0 + (var_9 * 0x1C);
    temp_4 = *(s8 *)temp_5;
    if (temp_4 == -1 && *(s8 *)(temp_5 + 1) == -1) {
        var_2 = -1;
    } else if (temp_4 == temp_8 && *(s8 *)(temp_5 + 1) == temp_7) {
        var_2 = (s64)(s8)var_9;
    } else {
        goto loop_1;
    }
    *(s8 *)(temp_16 + 0x2D4) = (s8)var_2;
    temp_18_2 = func_002e78a0();
    func_00313d20(arg0, temp_18_2, func_002e78e0(), 0);
    sp4C = func_002e78a0() & 0xFF;
    sp48 = (func_002e78e0() & 0xFF) + 1;
    func_002e7920(&sp4C, &sp48);
    var_9_2 = 0;
loop_8:
    var_9_2 = (s64)(s8)(var_9_2 + 1);
    temp_5_2 = (u8 *)D_006432B0 + (var_9_2 * 0x1C);
    temp_4_2 = *(s8 *)temp_5_2;
    if (temp_4_2 == -1 && *(s8 *)(temp_5_2 + 1) == -1) {
        var_2_2 = -1;
    } else if (temp_4_2 == (u8)sp4C && *(s8 *)(temp_5_2 + 1) == (u8)sp48) {
        var_2_2 = (s64)(s8)var_9_2;
    } else {
        goto loop_8;
    }
    *(s8 *)(temp_16 + 0x2D5) = (s8)var_2_2;
    func_00313d20(arg0, (u8)sp4C, (u8)sp48, 1);
    *(s8 *)(temp_16 + 0x2D2) = (s8)sp4C;
    *(s8 *)(temp_16 + 0x2D3) = (s8)sp48;
    *(s8 *)(temp_16 + 0x2D6) = 0;
}
