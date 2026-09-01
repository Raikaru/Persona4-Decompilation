/* func_0011c780; object 428B; retail window 432B; best normalized_diff 6 (fndiff differing words, including relocation-owned word); visible differing offsets 0x130, 0x138, 0x154, 0x158, 0x15C; relocation-owned GPREL offset 0x06C (iGpffff8094). Best candidate uses #pragma opt_propagation off, which fixes the retail lh/lwc1 prologue order; no pragma was retained after fallback. Confirmed explicitly: plain C reproduces all six retail COP1 accumulator-chain ops (adda.s/madd.s) byte-for-byte; the chain itself is not the floor. Hex-Rays and Ghidra agree on the clamp/interpolation, two FMA chains, byte interpolation, 0x4F000000 conversion guard, and final flag clear. Ruled out: direct duplicated stores, ternary/shared-mask variants, signed/unsigned/char output locals, declaration permutations and first-use reorderings, raw-first and inline conversion forms, pointer aliases, integer-parameter aliases, register-qualified parameters, four-argument ABI declarations, comparison polarity/spelling variants, no-op liveness reservations, union guard constant, opt_common_subs, opt_rebuildconditionals, schedule, no_branch_likely, and optimization_level 1 probes.
void func_0011c780(u8 *arg0)
{
    f32 diff;
    f32 f_abs;
    f32 acc;
    f32 ratio;
    f32 lo;
    f32 hi;
    f32 base;
    f32 delta;
    s32 n;
    s32 a;
    s32 b;
    s16 raw;
    raw = *(s16 *)(arg0 + 0x514);
    lo = *(f32 *)(arg0 + 0x450);
    ratio = (f32)raw;
    if (ratio < lo) ratio = 0.0f;
    else { hi = *(f32 *)(arg0 + 0x454); if (ratio > hi) ratio = 1.0f; else ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo))); }
    base = *(f32 *)(arg0 + 0x434); delta = *(f32 *)(arg0 + 0x43C) - base; *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438); delta = *(f32 *)(arg0 + 0x440) - base; *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C); b = *(u8 *)(arg0 + 0x44D); diff = (f32)(b - a); f_abs = (f32)(u32)a;
    acc = f_abs + ratio * diff;
    if (2147483648.0f > acc) n = (s32)acc & 0xFF; else n = ((s32)(acc - 2147483648.0f) | 0x80000000) & 0xFF;
    *(u8 *)(arg0 + 0x44E) = n;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) *(s32 *)(arg0 + 0x534) &= ~0x1000;
}
