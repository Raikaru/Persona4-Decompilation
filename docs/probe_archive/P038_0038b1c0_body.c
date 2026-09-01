/* object 720B / window 720B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s interpolation chain in each loop iteration, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_0038b1c0(u8 *arg0)
{
    extern void func_0034f460(s32, s32, s32, s32, s32, s32, s32, f32);
    extern f32 func_00373cb0(s32, f32, f32, f32, f32);
    extern void func_003f6440(s32, s32);
    extern s32 D_0064EFB0[];
    u8 *base;
    u8 *entry;
    s32 palette;
    s32 i;
    u16 tick;
    f32 alpha;
    s32 red;
    s32 green;
    s32 blue;

    base = *(u8 **)arg0;
    palette = *(s32 *)(base + 0x1F2AC);
    tick = *(u16 *)(arg0 + 0x164);
    if (tick < 30) {
        *(u16 *)(arg0 + 0x164) = ++tick;
    }
    for (i = 0; i < 11; i++) {
        entry = (u8 *)D_0064EFB0 + i * 0x14;
        if (tick < *(s32 *)(entry + 8)) {
            alpha = 0.0f;
        } else if (tick < *(s32 *)(entry + 0xC)) {
            alpha = func_00373cb0(1, (f32)*(s32 *)(entry + 8),
                                  (f32)tick, (f32)*(s32 *)(entry + 8),
                                  (f32)*(s32 *)(entry + 0xC));
        } else {
            alpha = 1.0f;
        }
        if (i == 5) {
            func_003f6440(3, 0x71801);
            func_003f6440(2, 0x48);
        }
        if (i < 5) {
            red = 0xFF;
            green = 0xBE;
            blue = 0x5A;
            alpha = 206.0f * alpha;
        } else {
            red = 0x2B;
            green = 0x26;
            blue = 0x1E;
            alpha = 255.0f * alpha;
        }
        /* Retail's fourth value is produced by adda.s/madd.s; this archival
           expression intentionally does not attempt to model that codegen. */
        func_0034f460(palette, *(s32 *)(entry + 0x10), red, green, blue,
                      (s32)alpha, 0, *(f32 *)(entry + 4));
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
