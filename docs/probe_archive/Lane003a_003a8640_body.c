/* Attempted reconstruction; restored to INCLUDE_ASM because scoped lverify remained MISMATCH (object 496B/window 512B, nd 340 with branch pragma; baseline nd 309). */
s32 func_003a8640(u8 *arg0, u8 *arg1, u8 *arg2, u32 arg3)
{
    s32 temp_2_2;
    s32 temp_3;
    s32 var_16;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *temp_6;

    temp_4 = *(u8 **)(arg1 + 0x4C);
    var_16 = arg3;
    if (*(s32 *)(temp_4 + 0xE0) == 1) {
        temp_3 = *(s32 *)(temp_4 + 0xE4);
        if (temp_3 < *(s32 *)(temp_4 + 0xE8)) {
            var_2 = temp_3 + 1;
        } else {
            var_2 = 0;
        }
        temp_3_2 = (var_2 * 4) + temp_4;
        *(s32 *)(temp_3_2 + 0xEC) =
            *(s32 *)(temp_3_2 + 0xEC) | var_16;
        temp_2 = (*(s32 *)(temp_4 + 0xE4) * 4) + temp_4;
        temp_2_2 = *(s32 *)(temp_2 + 0xEC);
        if (temp_2_2 != 0) {
            *(s32 *)(temp_2 + 0xEC) = 0;
            var_16 |= temp_2_2;
        }
    }
    if (var_16 != 0) {
        if ((var_16 & 0x10000000) != 0) {
            func_003a2bb0(arg1);
        }
        if (((var_16 & 0x80000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 0x80000) != 0)) {
            func_0043f810(*(void **)(arg1 + 0x3C), arg1 + 0x90, 0x10);
        }
        if (((var_16 & 0x100000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 0x100000) != 0)) {
            func_0043f810(*(void **)(arg1 + 0x44), arg1 + 0x90, 0x20);
        }
        if (((var_16 & 0x2000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 0x40042) == 0)) {
            temp_6 = *(u8 **)(arg1 + 0x24);
            *(u8 *)(temp_6 + 0) = *(u8 *)(arg1 + 0x7C);
            *(u8 *)(temp_6 + 1) = *(u8 *)(arg1 + 0x7D);
            *(u8 *)(temp_6 + 2) = *(u8 *)(arg1 + 0x7E);
            *(u8 *)(temp_6 + 3) = *(u8 *)(arg1 + 0x7F);
        }
        if (((var_16 & 0x40000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 0x40000) != 0)) {
            func_0043f810(*(void **)(arg1 + 0x2C), arg1 + 0x80, 0x10);
        }
        if (((var_16 & 0x20000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 0x20000) != 0)) {
            temp_2_3 = *(u8 **)(arg1 + 0x34);
            *(f32 *)(temp_2_3 + 0) = *(f32 *)(arg1 + 0x78);
            *(f32 *)(temp_2_3 + 4) = *(f32 *)(arg1 + 0x78);
        }
        if (((var_16 & 0x4000) != 0) &&
            ((*(s32 *)(arg1 + 0x58) & 4) == 0)) {
            temp_2_4 = *(u8 **)(arg1 + 0x1C);
            *(f32 *)(temp_2_4 + 0) = *(f32 *)(arg1 + 0x70);
            *(f32 *)(temp_2_4 + 4) = *(f32 *)(arg1 + 0x74);
        }
    }
    return 1;
}
