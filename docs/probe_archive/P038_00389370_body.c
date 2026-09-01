/* object 720B / window 720B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s interpolation chain in the colour calculation, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_00389370(u8 *arg0)
{
    extern void func_0034f4a0(s32, s32, s32, s32, s32, s32, s32, s32,
                              f32, f32, f32, f32, s32, s32);
    extern f32 func_0044b610(f32);
    extern f32 D_0064EAB8;
    u8 *state;
    s32 palette;
    u16 tick;
    s32 phase;
    f32 t;
    f32 value0;
    f32 value1;
    s32 color0;
    s32 color1;

    state = arg0 + 0x68;
    palette = *(s32 *)(*(u8 **)arg0 + 0x1F2B0);
    tick = *(u16 *)state + 1;
    *(u16 *)state = tick;
    if (tick >= 0x320) {
        *(u16 *)state = 0;
    }
    phase = *(u16 *)state % 100;
    if (phase < 50) {
        t = (f32)(u16)phase;
        value0 = 1.0f - func_0044b610(D_0064EAB8 * (t / 50.0f));
    } else {
        t = (f32)(u16)(phase - 50);
        value0 = func_0044b610(D_0064EAB8 * (t / 50.0f));
    }
    if (value0 < 0.0f) {
        value0 = 0.0f;
    }
    /* Retail computes the following two interpolation values through
       adda.s/madd.s accumulator chains; this plain-C expression is archival
       only and is intentionally not probed. */
    value1 = value0;
    color0 = (s32)(4096.0f * value1);
    color1 = (s32)(4096.0f * value1);
    func_0034f4a0(palette, 0, 0xFF, 0xFF, 0xFF, 0xFF, color0, color1,
                  320.0f - 127.0f * value1, 224.0f - 127.0f * value1,
                  0.0f, 0.0f, 0, 0);
}
