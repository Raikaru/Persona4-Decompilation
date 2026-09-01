/* object_size=640 window=656 normalized_diff=334; differing instruction offsets (first_diffs words): 26,30,33,37,38,42,50,101,105,110,113,114,118,120,130,144. Callees: func_00110a60 measured as s8 func_00110a60(s32,s32); declarations corrected block-scope. Levers ruled out: prior old-style s64 callee declaration, corrected s8 prototype, explicit sign-extension/goto loop shape from prior candidate; residual remained 334, so archive per high-residual stop. */
void func_00313d20(u8 *arg0, u8 arg1, u8 arg2, s64 arg3)
{
    extern s8 func_00110a60(s32 arg0, s32 arg1);
    extern u8 D_00643D00[];
    u8 *temp_16;
    s32 temp_4_5;
    s32 temp_6;
    s32 temp_19;
    s64 temp_11;
    s64 temp_4_2;
    s64 var_18;
    s64 var_17;
    s64 var_4;
    s64 var_6;
    s64 var_8;
    s8 temp_11_3;
    s8 temp_4;
    s8 temp_4_4;
    u8 *temp_11_2;
    u8 *temp_4_3;
    u8 *temp_5;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_8;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_18 = -1;
    temp_19 = (s8)arg3;
    temp_4 = *(s8 *)((u8 *)(temp_19 + temp_16) + 0x2D4);
    if (temp_4 == -1) {
        temp_7 = D_00643D00 +
            ((s8)func_00110a60(arg1 & 0xFF, arg2 & 0xFF) * 0x14);
        var_8 = 0;
        temp_6 = temp_19 * 5;
        temp_8 = (u8 *)(temp_16 + temp_6);
        goto loop_6_check;
loop_6_body:
        temp_4_2 = (s64)(s16)var_8;
        *(s8 *)(temp_8 + temp_4_2 + 0x2C4) = 0;
        temp_4_3 = temp_7 + temp_4_2 * 4;
        if (*(s8 *)temp_4_3 != 0) {
            temp_4_4 = *(s8 *)(temp_4_3 + 1);
            if ((s64)(s16)var_18 < (s64)temp_4_4) {
                var_17 = (s64)(s8)var_8;
                var_18 = (s64)(s16)temp_4_4;
            }
        }
        var_8 = (s64)(s16)(var_8 + 1);
loop_6_check:
        if ((s16)var_8 < 5) {
            goto loop_6_body;
        }
        if ((s64)(s16)var_18 != -1) {
            *(s8 *)(temp_8 + (s64)(s8)var_17 + 0x2C4) = 1;
        }
    } else {
        temp_6 = (temp_4 * 8 - temp_4) * 4;
        temp_5 = (u8 *)D_006432B0 + temp_6;
        temp_8 = (u8 *)(temp_19 * 2 + temp_16);
        *(s16 *)(temp_8 + 0x2C0) = 0;
        var_4 = 0;
        goto loop_13_check;
loop_13_body:
        if (*(s8 *)(temp_5 + 2) != 0) {
            *(s16 *)(temp_8 + 0x2C0) =
                (s16)(*(s16 *)(temp_8 + 0x2C0) + 1);
        }
        var_4 = (s64)(s16)(var_4 + 1);
loop_13_check:
        if ((s16)var_4 < 3) {
            goto loop_13_body;
        }
        var_6 = 0;
        temp_4_5 = (s32)((s8)arg3) * 5;
        temp_8 = (u8 *)(temp_16 + temp_4_5);
        goto loop_21_check;
loop_21_body:
        temp_11 = (s64)(s16)var_6;
        temp_7_2 = temp_8 + temp_11;
        *(s8 *)(temp_7_2 + 0x2C4) = 0;
        temp_11_2 = temp_5 + temp_11 * 4;
        if (*(s8 *)(temp_11_2 + 8) != 0) {
            *(s16 *)(temp_8 + 0x2C0) =
                (s16)(*(s16 *)(temp_8 + 0x2C0) + 1);
            temp_11_3 = *(s8 *)(temp_11_2 + 9);
            if (temp_11_3 == 0x64) {
                *(s8 *)(temp_7_2 + 0x2C4) = 1;
            } else if ((s64)(s16)var_18 < (s64)temp_11_3) {
                var_17 = (s64)(s8)var_6;
                var_18 = (s64)(s16)temp_11_3;
            }
        }
        var_6 = (s64)(s16)(var_6 + 1);
loop_21_check:
        if ((s16)var_6 < 5) {
            goto loop_21_body;
        }
        if ((s64)(s16)var_18 != -1) {
            *(s8 *)(temp_8 + (s64)(s8)var_17 + 0x2C4) = 1;
        }
    }
}
