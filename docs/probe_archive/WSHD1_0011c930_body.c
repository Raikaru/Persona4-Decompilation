/* object 448B; retail window 448B; normalized_diff 23; differing offsets 20,24,28,32,108 (relocation-owned iGpffff8094),240,244,252,256,304,312,340,344,348.
   Probed expanded m2c body, nested high-bound load/test, guard polarities,
   constant-left comparison, masks, declaration orders, ratio-first FMA,
   OR/compound/reused-local forms, pragma wrappers, signedness variants, and
   direct absolute-value expression. */
void func_0011c930(u8 *arg0)
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
    u32 c;
    s32 v;

    ratio = (f32)(s16)*(s16 *)(arg0 + 0x514);
    lo = *(f32 *)(arg0 + 0x450);
    if (ratio < lo) {
        ratio = 0.0f;
    } else {
        hi = *(f32 *)(arg0 + 0x454);
        if (ratio > hi) {
            ratio = 1.0f;
        } else {
            ratio = func_0044b7b0(iGpffff8094 * ((ratio - lo) / (hi - lo)));
        }
    }
    base = *(f32 *)(arg0 + 0x434);
    delta = *(f32 *)(arg0 + 0x43C) - base;
    *(f32 *)(arg0 + 0x444) = base + ratio * delta;
    base = *(f32 *)(arg0 + 0x438);
    delta = *(f32 *)(arg0 + 0x440) - base;
    *(f32 *)(arg0 + 0x448) = base + ratio * delta;
    a = *(u8 *)(arg0 + 0x44C);
    b = *(u8 *)(arg0 + 0x44D);
    diff = (f32)(b - a);
    c = (u32)a;
    if (a >= 0) {
        f_abs = (f32)a;
    } else {
        v = (s32)((c >> 1) | (c & 1));
        f_abs = (f32)v;
        f_abs = f_abs + f_abs;
    }
    acc = f_abs + ratio * diff;
    if (2147483648.0f > acc) {
        n = (s32)acc & 0xFF;
    } else {
        n = ((s32)(acc - 2147483648.0f) | 0x80000000) & 0xFF;
    }
    *(u8 *)(arg0 + 0x44E) = n;
    if (!((f32)(s16)*(s16 *)(arg0 + 0x514) <= 5.0f)) {
        *(s32 *)(arg0 + 0x534) &= ~0x800;
        *(s32 *)(arg0 + 0x534) &= ~0x2000;
        *(s8 *)(arg0 + 0x88) = -1;
    }
}
