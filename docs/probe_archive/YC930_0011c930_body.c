// FUN_0011C930
void func_0011c930(u8 *arg0)
{
    #pragma optimization_level 1
    /* measured: nd 9 prologue/output colouring probe */
    f32 diff; f32 f_abs; f32 acc; f32 ratio; f32 lo; f32 hi; f32 base; f32 delta; s32 n; s32 a; s32 b;
    ratio = (f32)(s16)*(s16 *)(arg0 + 0x514); lo = *(f32 *)(arg0 + 0x450);
    if (ratio < lo) ratio = 0.0f; else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a; acc = f_abs + ratio * diff;
    if (2147483648.0f > acc) n = (s32)acc & 0xFF; else n = ((s32)(acc - 2147483648.0f) | 0x80000000) & 0xFF;
    *(u8 *)(arg0 + 0x44E) = n;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) { *(s32 *)(arg0 + 0x534) &= ~0x800; *(s32 *)(arg0 + 0x534) &= ~0x2000; *(s8 *)(arg0 + 0x88) = -1; }
}
