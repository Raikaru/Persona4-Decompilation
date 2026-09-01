/* object 912B / window 912B / normalized_diff 0; differing offsets: none (ASM baseline); classification: COP1 accumulator-chain floor; ruled out: retail adda.s/madd.s interpolation chains in all three flag branches, which plain MWCC C cannot emit; no source probing per floor policy. */
void func_0038a940(u8 *arg0)
{
    extern f32 func_00373cb0(s32, f32, f32, f32, f32);
    extern f32 func_0044b7b0(f32);
    extern void func_0038a480(u8 *arg0);
    u8 *state = arg0 + 0x168;
    u8 *work = state + 4;
    u16 flags = *(u16 *)state;
    f32 t;

    if (flags & 1) {
        /* Retail's four target coordinates and final blend use adda.s/madd.s. */
        *(f32 *)(work + 0x10) = 317.0f;
        *(f32 *)(work + 0x14) = 212.0f;
        *(f32 *)(work + 0x18) = 0.0f;
        *(f32 *)(work + 0x1C) = 1.0f;
        *(f32 *)(work + 4) += 144.0f - *(f32 *)(work + 4);
        *(f32 *)(work + 8) += 165.0f - *(f32 *)(work + 8);
        *(f32 *)(work + 0xC) = -*(f32 *)(work + 0xC);
    } else if (flags & 2) {
        t = func_00373cb0(2, (f32)(u16)*(u16 *)(work), 0.0f, 5.0f, 0.0f);
        *(f32 *)(work + 0x10) = 317.0f;
        *(f32 *)(work + 0x14) = 212.0f + 60.0f * t;
        *(f32 *)(work + 0x18) = 0.0f;
        *(f32 *)(work + 0x1C) = 1.0f;
        *(f32 *)(work + 4) = 65.0f + 12.0f * t;
        *(f32 *)(work + 8) = 165.0f + 60.0f * t;
        if (++*(u16 *)(work) >= 5) {
            *(u16 *)state &= 0xFFFD;
            *(u16 *)work = 0;
        }
    } else {
        if (++*(u16 *)work >= 300) {
            *(u16 *)work = 0;
        }
        t = func_0044b7b0((f32)(u16)*(u16 *)work / 150.0f);
        *(f32 *)(work + 0x1C) = t;
        *(f32 *)(work + 0xC) = 15.0f * func_0044b7b0((f32)(u16)*(u16 *)work / 300.0f);
    }
    func_0038a480(work);
}
