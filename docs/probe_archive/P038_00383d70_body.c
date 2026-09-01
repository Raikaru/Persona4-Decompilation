/* object 528B / window 528B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s COP1 accumulator chain at +0xBC/+0xC0, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00383d70(u8 *arg0)
{
    u8 *state;
    u8 *base;
    u16 value;
    s32 i;
    u8 colors[4];
    f32 alpha;

    state = arg0 + 0x28;
    base = *(u8 **)arg0;
    if ((*(u16 *)(base + 0x1F1D0) & 2) != 0 ||
        (*(u16 *)(base + 0x1F1D0) & 4) != 0) {
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
    alpha = 255.0f * func_0044b7b0((f32)(u16)value / 30.0f);
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
