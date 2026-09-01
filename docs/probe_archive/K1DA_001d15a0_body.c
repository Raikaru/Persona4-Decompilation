/* object 240B, retail window 224B, normalized_diff 185; differing offsets 0x0,0x4,0x8,0x9,0xA,0xB,0x10,0x12,0x13,0x14,0x16,0x17,0x18,0x1A,0x1B,0x1C; object exceeds window, so reconstruction rather than polish. Corrected declarations: func_0022ead0(void), func_001d1310(u16 *), D_00607E50[]. Ruled out direct field accesses, loop spelling, and named locals within the 20-minute budget. */
s64 func_001d15a0(void) {
    u16 sp1A;
    u16 sp1C;
    u16 sp18;
    s32 var_8;
    s64 var_9;
    u8 *temp_3;

    if (func_0022ead0() == 1) {
        return -1;
    }
    func_001d1310(&sp18);
    var_8 = 0;
loop_8:
    if ((u32)(var_8 & 0xFFFF) >= 0x19U) {
        var_9 = 0x18;
    } else {
        var_9 = var_8 & 0xFFFF;
        temp_3 = (u8 *)((s32)&D_00607E50 + (var_9 * 0xE0));
        if (((s32)*(u16 *)(temp_3 + 0xD8) >= (s32)sp18) &&
            ((s32)*(u16 *)(temp_3 + 0xDA) >= (s32)sp1A) &&
            ((s32)*(u16 *)(temp_3 + 0xDC) >= (s32)sp1C)) {
        } else {
            var_8 = (var_8 + 1) & 0xFFFF;
            goto loop_8;
        }
    }
    return (s64)(var_9 << 0x30) >> 0x30;
}
