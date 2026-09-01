/* object 520B / window 528B / normalized_diff 0; differing offsets: none after relocation normalization (raw relocation sites: +0xC0, +0xE4, +0xEC); ruled out: large-offset addressing, u16 narrowing mask, stale COP1-floor assumption; plain C reproduced the retail adda.s/madd.s chain at +0xFC/+0x100; final candidate MATCH. */
void func_00383d70(u8 *arg0)
{
    extern f32 func_0044b7b0(f32 fparg0);
    extern f32 iGpffff81e0;
    extern f32 fGpffff8198;
    extern f32 fGpffff809c;
    u8 *state;
    u8 *base;
    u8 *flags;
    s32 value;
    s32 i;
    u8 colors[4];
    f32 alpha;

    state = arg0 + 0x28;
    base = *(u8 **)arg0;
    flags = base + 0x1F1D0;
    if ((*(u16 *)flags & 2) != 0 ||
        (*(u16 *)flags & 4) != 0) {
        return;
    }
    if (*(s32 *)(state + 0x14) <= 0) {
        return;
    }
    value = (*(u16 *)state + 1) % 30;
    *(u16 *)state = value;
    colors[0] = 0;
    colors[1] = 70;
    colors[2] = 120;
    alpha = 255.0f *
        (fGpffff8198 * func_0044b7b0((iGpffff81e0 *
                                     (f32)*(u16 *)state) / 30.0f) +
         fGpffff809c + 0.0f);
    colors[3] = (u8)alpha;
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    for (i = 0; i < *(s32 *)(state + 0x14); i++) {
        func_00377930(base, *(s32 *)(state + i * 4 + 4), 0,
                      colors, 0);
    }
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
