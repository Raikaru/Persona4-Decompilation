/* Candidate reconstruction for func_0026fd90; lverify JGE1 MISMATCH (object 584/window 608, nd 366). Tried: compute third decode before func_002746a0, then second decode. Result: prologue and saved-register assignment drifted badly (frame 0x60, s0 for first value, s3 for arg1, no s4/s2). */
// FUN_0026FD90
#pragma push
/* measured: opt_common_subs off forces func_0026fd90 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fd90 decode scheduling. */
#pragma opt_propagation off
s32 func_0026fd90(s32 arg0, u8 *arg1)
{
    s32 temp_2;
    s32 temp_18;
    s32 temp_19;
    u8 var_16;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_4b;
    u8 *temp_3;
    s8 sp6A;
    s8 sp69;
    s8 sp68;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_2 = (u16)(s16)((var_2 << 8) | (u8)temp_4);

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (temp_3[4] - 1) & 0xFF;
    temp_3_6 = temp_3[5];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_6 - 1) & 0xFF;
    }
    var_2_3 &= 0xFF;
    temp_18 = (u16)(s16)((var_2_3 << 8) | (u8)temp_4);

    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (temp_3[2] - 1) & 0xFF;
    temp_3_4b = temp_3[3];
    if ((u8)temp_3_4b == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_4b - 1) & 0xFF;
    }
    var_2_2 &= 0xFF;
    temp_19 = (u16)(s16)((var_2_2 << 8) | (u8)temp_4);

    if ((temp_2 & 0xFFFF) != -1) {
        var_16 = *(u8 *)(arg1 + 0xD);
        *(u8 *)(arg1 + 0xD) = temp_2;
    }
    if (temp_19 & 0xFFFF) {
        temp_19 = temp_18 & 0xFFFF;
        switch (func_0026e360(temp_19)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
        case 0xB:
            var_2_4 = 1;
            break;
        default:
            var_2_4 = 0;
            break;
        }
        if (var_2_4 != 0) {
            *(u8 *)(arg1 + 0xD) = 4;
        }
        sp68 = -0x7D;
        sp69 = (s8)(func_0026e360(temp_19) + 0xC7);
        sp6A = 0;
        func_00273f70(arg1);
        func_00273cc0(&sp68, arg1);
    }
    func_00273f70(arg1);
    func_00273cc0((u8 *)func_001067f0((s16)temp_18), arg1);
    *(u8 *)(arg1 + 0xD) = var_16;
    return 0;
}
/* measured: closing opt_propagation off for func_0026fd90. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026fd90. */
#pragma opt_common_subs on
#pragma pop
/* measured: opt_common_subs off forces func_0026fff0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fff0 decode scheduling. */
#pragma opt_propagation off
