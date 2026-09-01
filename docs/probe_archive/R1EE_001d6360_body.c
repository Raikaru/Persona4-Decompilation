/* object 508B, window 528B, normalized_diff 155; differing offsets begin 0x30,0x3A,0x3E,0x54,0x5E,0x64,0x8D,0x9E; classification=undersized near-miss with correct 64-byte frame and three saved registers but packet/index register colouring and return-branch layout residuals; ruled_out=movz/movn, COP1 accumulator MAC, standalone MMI H009, framed tail-jump, sd-saved-register floor, COP2/VU0. Retail prologue maps packet to $s0 and index to $s1; candidate maps packet to $s1 and index to $s0 despite declaration swap. */
s32 func_001d6360(u8 *arg0)
{
    extern s32 func_00193b70(s64 arg0, s64 arg1);
    extern s32 func_001d4120(s32 arg0);
    extern s32 func_001d4140(s32 arg0, s32 arg1);
    extern s32 func_001d41b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    s32 index;
    u8 *packet;
    s32 count;
    s32 value;
    s64 key;
    if (func_001d4120(*(s32 *)(arg0 + 0)) == 0)
        return 0;
    packet = *(u8 **)(arg0 + 0x18);
    if ((*(s32 *)(packet + 4) & 0xFF000000) == 0)
        return 1;
    if ((*(u16 *)(packet + 0) & 0x40) == 0) {
        if ((*(s32 *)(arg0 + 0x20) & 0x4000) == 0)
            index = func_001d4140(*(s32 *)(arg0 + 0), 0) * 2;
        else
            index = *(s32 *)(arg0 + 0x1C) + 1;
        count = *(s32 *)(arg0 + 8);
        if ((count != 0 && *(s32 *)(arg0 + 0x1C) >= count * 2 - 13) ||
            ((key = *(s64 *)(arg0 + 0x10)) != 0 &&
             func_00193b70(key, (s64)0x3FFFFFFFFFFFFFFF) == 0) ||
            (index != 0 && *(s32 *)(arg0 + 0x1C) >= index)) {
            if ((*(s32 *)(arg0 + 0x20) & 0x2000) != 0)
                *(s8 *)(packet + 8) = 7;
            *(u16 *)(packet + 0) |= 0x100;
        } else {
            value = *(s32 *)(arg0 + 0x1C);
            if (value == 0) {
                *(s32 *)(packet + 0x10) =
                    func_001d41b0(*(s32 *)(arg0 + 0), 0, *(s32 *)(arg0 + 4),
                                  *(s32 *)(arg0 + 4), *(s32 *)(arg0 + 0x20));
            } else if (value == 2) {
                if ((*(s32 *)(arg0 + 0x20) & 0x10000) == 0) {
                    *(u16 *)(packet + 0) |= 0xB0;
                    *(s32 *)(packet + 4) =
                        (s32)(((s64)*(s32 *)(packet + 4) << 0x28) >> 0x28);
                } else {
                    *(u16 *)(packet + 0) |= 0x30;
                    *(s32 *)(packet + 4) = -1;
                }
            }
            *(s32 *)(arg0 + 0x1C) = value + 2;
        }
    }
    return 0;
}
