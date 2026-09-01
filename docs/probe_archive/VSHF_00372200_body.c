/* object 416B; retail window 416B; normalized_diff 32; differing offsets 0xE0,0xF0,0xF4,0xF8,0xFC,0x100,0x104,0x108,0x10C,0x110,0x114,0x118,0x11C,0x120,0x124,0x128,0x12C,0x130,0x134,0x138,0x13C,0x140,0x144,0x148,0x14C,0x150,0x154,0x158,0x15C,0x164,0x174,0x180; ruled out: typed ShuffleCalcUnit pointer, u16/u32 value locals, direct versus compound increment, duration reload/hoist, factor and interpolation temporary orders, declaration-order FP probes, optimization-level and propagation pragmas; both int-to-float conversion sites are exact, residual is FP register/schedule coloring and tail expression order. */
s32 func_00372200(u8 *arg0) {
    f32 t;
    f32 t2;
    f32 d0;
    f32 d1;
    f32 d2;

    d2 = *(f32 *)(arg0 + 4);
    t = (f32)(u16)*(u16 *)(arg0 + 0);
    if (!(t < d2)) {
        return 1;
    }
    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        func_0046d730(&D_0064E9C0, 0x22F);
    }
    t = (f32)(u16)(*(u16 *)(arg0 + 0) += 1);
    t = t + 0.0f;
    d2 = *(f32 *)(arg0 + 4);
    t = t / d2;
    t2 = t - (2.0f * t) * t;
    d0 = *(f32 *)(arg0 + 0x30) * t2;
    d1 = *(f32 *)(arg0 + 0x34) * t2;
    d2 = *(f32 *)(arg0 + 0x38) * t2;
    *(f32 *)(arg0 + 0xC) = (*(f32 *)(arg0 + 0x24) - *(f32 *)(arg0 + 0x18)) * t + *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 0x10) = (*(f32 *)(arg0 + 0x28) - *(f32 *)(arg0 + 0x1C)) * t + *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x14) = (*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x20)) * t + *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg0 + 0xC) += d0;
    *(f32 *)(arg0 + 0x10) += d1;
    *(f32 *)(arg0 + 0x14) += d2;
    return 0;
}
