/* object 200B, window 192B, normalized_diff 102; fndiff differing offsets 0x0C,0x2A,0x2C,0x34-0x4C,0x50-0xC4; casts written: explicit (u32) subtraction and integer-domain pointer addition; levers ruled out: schedule-on (188B/41 differing words), no_branch_likely-on, opt_rebuildconditionals-off, and baseline typed body. Compiler check: frameless (no callee-saved register save; no sq/sd diagnostic), located before the documented ee-gcc transition and treated as MWCC candidate. */
u8 *func_00414b50(u8 *arg0, u8 **arg1, u32 arg2)
{
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *temp_7;
    u8 *temp_3_2;
    u8 *var_2;
    f32 temp_f1;
    f32 temp_f0;
    s32 temp_6;
    u8 *temp_3;
    u32 temp_2;
    u8 *temp_2_3;

    temp_2 = (u32)arg1[0] - arg2;
    if (temp_2 < 0x100U) {
        temp_6 = *(s32 *)(arg0 + 0x14);
        temp_3 = *(u8 **)(arg0 + 0xC);
        if ((u8 *)arg1 != temp_3 + ((temp_6 - 1) * 8)) {
            temp_2_2 = temp_3 + (temp_6 * 8);
            temp_7 = arg1[1];
            temp_f1 = *(f32 *)(temp_2_2 - 8);
            temp_f0 = *(f32 *)(temp_2_2 - 4);
            *(f32 *)arg1 = temp_f1;
            *(f32 *)(arg1 + 1) = temp_f0;
            *(u8 **)(temp_7 + 0xC) = (u8 *)arg1;
        }
        var_2 = arg1[1] + 0x20;
        *(s32 *)(arg0 + 0x14) -= 1;
    } else {
        temp_7 = arg1[1];
        temp_4 = (u8 *)(arg2 + (u32)temp_7);
        *(s32 *)(temp_4 + 0x28) = temp_2 - 0x20;
        temp_3_2 = temp_4 + 0x20;
        *(u8 **)(temp_4 + 0x20) = temp_7;
        *(u8 **)(temp_4 + 0x24) = *(u8 **)(temp_7 + 4);
        *(u8 **)(temp_4 + 0x2C) = (u8 *)arg1;
        *(u32 *)(temp_7 + 8) = arg2;
        *(u8 **)(temp_7 + 4) = temp_3_2;
        temp_2_3 = *(u8 **)(temp_4 + 0x24);
        if (temp_2_3 != NULL) {
            *(u8 **)temp_2_3 = temp_3_2;
        }
        arg1[1] = temp_3_2;
        var_2 = temp_7 + 0x20;
        arg1[0] = *(u8 **)(temp_3_2 + 8);
    }
    *(u8 **)(arg1[1] + 0xC) = 0;
    return var_2;
}
