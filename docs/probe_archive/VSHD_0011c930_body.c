/* object 448B; retail window 448B; normalized_diff 13; differing offsets 0x10, 0x14, 0x132, 0x13A, 0x155, 0x15A, 0x15E; exact cast applied at unsigned byte-to-float site: (f32)(u32)a; signed halfword ratio remains (f32)(s16)*(s16 *)(arg0 + 0x514); residual is the intentionally source-ordered lo load versus halfword-conversion pair, relocation-owned GPREL, and output register coloring; parameter audit: retail uses only $a0 (arg0), with no hidden arguments or mixed-class parameter order; ruled out hand-written conversion, guard polarity, masks, direct output stores, explicit halfword staging (no codegen change), integer declaration reorder, and pragma wrappers. */
void func_0011c930(u8 *arg0)
{
    f32 diff; f32 f_abs; f32 acc; f32 ratio; f32 lo; f32 hi; f32 base; f32 delta; s32 n; s32 a; s32 b;
    lo = *(f32 *)(arg0 + 0x450); ratio = (f32)(s16)*(s16 *)(arg0 + 0x514);
    if (ratio < lo) ratio = 0.0f; else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a; acc = f_abs + ratio * diff;
    if (2147483648.0f > acc) n = (s32)acc & 0xFF; else n = ((s32)(acc - 2147483648.0f) | 0x80000000) & 0xFF;
    *(u8 *)(arg0 + 0x44E) = n;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) { *(s32 *)(arg0 + 0x534) &= ~0x800; *(s32 *)(arg0 + 0x534) &= ~0x2000; *(s8 *)(arg0 + 0x88) = -1; }
}
