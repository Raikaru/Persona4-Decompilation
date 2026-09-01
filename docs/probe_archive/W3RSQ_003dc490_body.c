/* corrected sqrtf quaternion candidate: object 124B / window 128B / current normalized_diff 64 after remeasurement. Residual is custom retail COP1 sqrt instruction c1 0x500C4 versus MWCC sqrt.s plus broad FPU evaluation-order/register differences; no inline asm used. */
#pragma schedule on
u8 *func_003dc490(u8 *arg0, u8 *arg1) {
    f32 diff;
    f32 root;
    f32 scale;
    extern f32 sqrtf(f32);

    diff = *(f32 *)(arg1 + 0x18) - *(f32 *)(arg1 + 0x24);
    root = sqrtf(1.0f + (*(f32 *)(arg1 + 0x0) - (*(f32 *)(arg1 + 0x14) + *(f32 *)(arg1 + 0x28))));
    *(f32 *)(arg0 + 0x0) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0xC) = scale * diff;
    *(f32 *)(arg0 + 0x4) = scale * (*(f32 *)(arg1 + 0x4) + *(f32 *)(arg1 + 0x10));
    *(f32 *)(arg0 + 0x8) = scale * (*(f32 *)(arg1 + 0x8) + *(f32 *)(arg1 + 0x20));
    return arg0;
}
#pragma schedule off
