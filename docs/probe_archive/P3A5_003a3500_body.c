/* object_size=360 window=368 normalized_diff=80 differing_offsets=0x0-0x1c,0x34-0x3c repeated per block; classification=register-allocation/statement-order residual with 8-byte shortfall; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register floor; block-scope declarations corrected: D_00752D24..D_00752D40 as u8[] absolute DATA arrays; no callees; schedule-on, optimization_level-1, split-product temporary, split-global temporary, mask local, and declaration-order probes did not close; see build/P3A5_3500_globals.json and fndiff output. */
s32 func_003a3500(s32 arg0, s32 arg1)
{
    extern u8 D_00752D24[];
    extern u8 D_00752D28[];
    extern u8 D_00752D2C[];
    extern u8 D_00752D30[];
    extern u8 D_00752D34[];
    extern u8 D_00752D38[];
    extern u8 D_00752D3C[];
    extern u8 D_00752D40[];
    s32 var_2;

    var_2 = 0;
    if (arg1 & 1) {
        var_2 = ((arg0 * 0x10) + 0xF) & ~0xF;
    }
    if (arg1 & 8) {
        var_2 += ((arg0 * *(s32 *)D_00752D24) + 0xF) & ~0xF;
    }
    if (arg1 & 0x10) {
        var_2 += ((arg0 * *(s32 *)D_00752D28) + 0xF) & ~0xF;
    }
    if (arg1 & 4) {
        var_2 += ((arg0 * *(s32 *)D_00752D2C) + 0x4F) & ~0xF;
    }
    if (arg1 & 2) {
        var_2 += ((arg0 * *(s32 *)D_00752D30) + 0x4F) & ~0xF;
    }
    if (arg1 & 0x40) {
        var_2 += ((arg0 * *(s32 *)D_00752D34) + 0xF) & ~0xF;
    }
    if (arg1 & 0x20) {
        var_2 += ((arg0 * *(s32 *)D_00752D38) + 0xF) & ~0xF;
    }
    if (arg1 & 0x80) {
        var_2 += ((arg0 * *(s32 *)D_00752D3C) + 0xF) & ~0xF;
    }
    if (arg1 & 0x100) {
        var_2 += ((arg0 * *(s32 *)D_00752D40) + 0xF) & ~0xF;
    }
    return var_2;
}
