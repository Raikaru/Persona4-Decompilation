/* object 512B / window 512B / normalized_diff 268 / differing offsets 78,79,88,110,125,134,136,137,138,139,140,141,142,144,145,146 / classification large structural/register near-miss; exact frame and saved-register count, declarations corrected at function scope, no confirmed compiler floor. */
s32 func_001db160(u8 *arg0, s32 arg1) {
    extern s32 func_0023d8e0(u8 *arg0, s32 arg1);
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern void func_0046d730(void *file, s32 line);
    extern s32 func_00232730(u8 *arg0, s32 arg1);
    extern s32 func_0023ddc0(u8 *arg0, s32 arg1);
    s32 temp_16;
    s32 temp_22;
    s32 var_19;
    s32 var_2;
    u16 *temp_16_2;
    u16 temp_18;
    u16 temp_5;
    u8 *temp_16_3;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x30);
    if ((s16)func_0023d8e0(*(u8 **)(temp_17 + 0xA64), 0) == arg1)
        return 1;
    temp_16 = (s32)(func_0023e130(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF);
    temp_22 = (s32)func_0023e140(*(u8 **)(temp_17 + 0xA64));
    var_19 = 0;
loop_21:
    if ((var_19 & 0xFFFF) >= (temp_16 & 0xFFFF))
        return 0;
    temp_16_2 = (u16 *)(temp_22 + ((var_19 & 0xFFFF) * 2));
    temp_5 = *temp_16_2;
    if ((temp_5 != 0) && ((s32)temp_5 < 0x1B8) &&
        ((s16)func_0023d8e0(*(u8 **)(temp_17 + 0xA64), temp_5) == arg1)) {
        temp_18 = *temp_16_2;
        if ((s32)temp_18 >= 0x240)
            func_0046d730(D_006095E0, 0x45F);
        temp_16_3 = *(u8 **)(arg0 + 0x30);
        if ((s32)temp_18 < 0x1B8) {
            if (func_00232710((u32)*(u8 **)(temp_16_3 + 0xA64), 0x80008) != 0)
                var_2 = 0;
            else if (func_00232730(*(u8 **)(temp_16_3 + 0xA64), temp_18) == 0)
                var_2 = 0;
            else if (func_0023ddc0(*(u8 **)(temp_16_3 + 0xA64), temp_18) != 0)
                var_2 = 0;
            else
                var_2 = 1;
        } else if (func_00232730(*(u8 **)(temp_16_3 + 0xA64), temp_18) == 0)
            var_2 = 0;
        else
            var_2 = 1;
        if (var_2 != 0)
            return 1;
    }
    var_19 = (var_19 + 1) & 0xFFFF;
    goto loop_21;
}
