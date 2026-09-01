/* object 704B / window 704B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s chains at +0x1A8/+0x1B0/+0x1C8/+0x1D0/+0x1E8/+0x1F0, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_0038cab0(u8 *arg0)
{
    struct State {
        u16 counter;
        u16 pad;
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } *state;
    u8 *base;
    u16 mode;
    f32 inv_scale;
    f32 t;
    f32 delta;
    f32 x0;
    f32 x1;
    f32 z0;
    f32 z1;
    u8 work[4][5 * sizeof(f32)];
    s32 i;

    state = (struct State *)(arg0 + 0x1A0);
    base = *(u8 **)arg0 + 0x1F1D0;
    mode = *(u16 *)(base + 4);
    if (mode >= 3) {
        mode = 2;
    }
    inv_scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if (state->counter < 10) {
        state->counter++;
        t = (f32)(u16)state->counter;
        state->x = 107.0f * t / 10.0f;
    } else if (state->w == 0.0f) {
        *(u16 *)(arg0 + 4) &= 0xFFF7;
    }
    state->x += 0.25f * (107.0f * (f32)mode + 207.0f - state->x);
    state->y += inv_scale * (state->w - state->y);
    x0 = state->z - state->y / 2.0f;
    x1 = state->z + state->y / 2.0f;
    z0 = state->x - x0;
    z1 = state->x + x0;
    for (i = 0; i < 4; i++) {
        *(f32 *)(work[i] + 0) = i == 0 ? x0 : x1;
        *(f32 *)(work[i] + 4) = i == 2 ? z0 : z1;
        *(f32 *)(work[i] + 8) = *(f32 *)0x008872F8;
        *(u32 *)(work[i] + 12) = 0x437F0000;
        *(f32 *)(work[i] + 16) = inv_scale;
    }
    D_00887300(1, 0);
    func_00364c50();
    D_00887310(4, work[0], 4);
    func_00364c70();
}
