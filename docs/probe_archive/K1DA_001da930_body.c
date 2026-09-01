/* object 196B, retail window 192B, normalized_diff 105; differing offsets 0x16,0x1A,0x26,0x2A,0x35,0x3E,0x40-0x46,0x48-0x4A; ruled out declaration-corrected callee widths, named locals, loop spelling, and direct pointer arithmetic. Object exceeds window; archive without further probing. */
s32 func_001da930(u8 *arg0) {
    s32 temp_16;
    s32 temp_17_2;
    s32 var_18;
    u16 temp_4;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x30);
    temp_16 = (s32)(func_0023e130(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF);
    temp_17_2 = (s32)func_0023e140(*(u8 **)(temp_17 + 0xA64));
    var_18 = 0;
loop_6:
    if ((var_18 & 0xFFFF) >= (temp_16 & 0xFFFF)) {
        return 0;
    }
    temp_4 = *(u16 *)(temp_17_2 + ((var_18 & 0xFFFF) * 2));
    if ((temp_4 != 0) && ((s32)temp_4 < 0x1B8) && (func_0023df20(temp_4) != 0)) {
        return 1;
    }
    var_18 = (var_18 + 1) & 0xFFFF;
    goto loop_6;
}
