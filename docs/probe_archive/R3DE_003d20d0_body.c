/* object 364B / window 368B / normalized_diff 211 / differing offsets 0,46,50,54,58,62,68,... / classification undersized-by-window near miss (frame 0x40 vs retail 0x50); retail saves s0-s2, candidate saves s0-s2; old-style callees and 64-bit mode probe; schedule/O-level probes ruled out; restored to ASM. */
void func_003d20d0(u8 *arg0, s32 *arg1) {
    extern void func_003d2010();
    extern void func_003e05f0();
    extern u8 iGpffffb474;
    u8 *base;
    u8 *temp_5;
    u8 *temp_6;
    s32 temp_7;
    s64 mode;
    u8 value;

    base = *(u8 **)(arg0 + 8);
    func_003d2010(base, arg0);
    *(s32 *)(arg0 + 0x14) = 0x7FFF8;
    temp_5 = *(u8 **)(base + 4);
    temp_6 = *(u8 **)D_008872E0 + 0x20;
    if (temp_5 != NULL) {
        func_003e05f0(*arg1, temp_5, temp_6);
    } else {
        *arg1 = (s32)temp_6;
    }
    mode = 1;
    if (*(s32 *)base & 4)
        mode = 2;
    temp_7 = *(s32 *)(arg0 + 0xC);
    if ((temp_7 & 1) != 1) {
        if ((temp_7 & 0xFF) && ((temp_7 & 2) != 2)) {
            if ((temp_7 & 0x10) != 0x10) {
                if ((temp_7 & 8) == 8) {
                    *(s8 *)(arg0 + 0x29) = 2;
                    value = iGpffffb474 | 0x10;
                } else {
                    *(s8 *)(arg0 + 0x29) = 1;
                    value = iGpffffb474 | 0x14;
                }
            } else {
                *(s8 *)(arg0 + 0x29) = 4;
                value = iGpffffb474;
            }
        } else {
            *(s8 *)(arg0 + 0x29) = 3;
            value = iGpffffb474 | 4;
        }
    } else {
        *(s8 *)(arg0 + 0x29) = 4;
        value = iGpffffb474;
    }
    *(u8 *)(arg0 + 0x28) = value;
    if (((s64)(mode << 32) >> 32) != 2)
        *(u8 *)(arg0 + 0x28) = *(u8 *)(arg0 + 0x28) | 2;
    *(s8 *)(arg0 + 0x2A) = 1;
}
