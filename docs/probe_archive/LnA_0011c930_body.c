/* object 448B; retail window 448B; normalized_diff 5 (relocation-masked);
   differing offsets 0x130, 0x138, 0x154, 0x158, 0x15C. Offset 0x06C is
   the real placeable R_MIPS_GPREL16 relocation for iGpffff8094 and is masked
   by fndiff. All six COP1 accumulator operations (adda.s/madd.s) reproduce
   byte-for-byte. The remaining ordinary residual is MWCC's $v1 result
   coloring where retail uses $a0 for mfc1/andi/or/sb. Probed and ruled out:
   raw staging and declaration orders, guard polarities and comparison forms,
   ternary/goto/shared-tail forms, direct stores, signedness and explicit byte
   casts, opt_common_subs, opt_loop_invariants, opt_rebuildconditionals,
   optimization_level, schedule, and no-branch alternatives. Retained
   opt_propagation off because it fixes the retail prologue load order but not
   this output-color residual. */
void func_0011c930(u8 *arg0)
{
    s32 n; s32 a; s32 b; s16 raw; f32 diff; f32 f_abs; f32 acc; f32 ratio; f32 lo; f32 hi; f32 base; f32 delta;
    raw = *(s16 *)(arg0 + 0x514); lo = *(f32 *)(arg0 + 0x450); ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f; else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a; acc = f_abs + ratio * diff;
    if (2147483648.0f > acc) { n = (s32)acc; n &= 0xFF; } else { n = (s32)(acc - 2147483648.0f); n |= 0x80000000; n &= 0xFF; }
    *(u8 *)(arg0 + 0x44E) = (u8)n;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) { *(s32 *)(arg0 + 0x534) &= ~0x800; *(s32 *)(arg0 + 0x534) &= ~0x2000; *(s8 *)(arg0 + 0x88) = -1; }
}
