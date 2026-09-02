/* Archived probe for func_002a73c0.
 * Compiler: MWCCPS2 (retail prologue uses sq $s3/$s2/$s1/$s0; not ee-gcc).
 * Lane: NoC_73c0_baseline
 * Measured object 780B / retail window 848B / normalized_diff 473
 *   (fndiff: 177 differing words).
 * Residual: saved-register rotation and copy-loop/index coloring (retail
 *   arg2->$s0, arg1->$s1, arg2[4]->$s2, v->$s3; candidate arg2->$s1,
 *   arg1->$s2, arg2[4]->$s0), plus mid-body scheduling differences.
 * One hand-expanded conversion at .L002A765C:
 *   result = (s32)(u32)temp + 30;
 *   (later stored as s16). To be replaced with plain store-width cast.
 */
s32 func_002a73c0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    s32 sp80[8];
    s32 sp60[8];
    s32 *dst;
    s32 *src;
    s32 count;
    s32 index;
    s32 total;
    s32 rand;
    s32 result;
    s32 saved_index;
    s16 frame;
    s16 next;
    f32 alpha;
    f32 f1;
    f32 f2;
    f32 f16;
    f32 delta;
    f32 randf;
    f32 temp;
    f32 saved_f8;
    f32 saved_fc;
    u8 *q;

    dst = sp80;
    src = D_0063EDB0;
    count = 4;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        count--;
        dst += 2;
    } while (count > 0);
    dst = sp60;
    src = D_0063EDD0;
    count = 4;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        count--;
        dst += 2;
    } while (count > 0);
    frame = *(s16 *)(arg2 + 0x12);
    if (frame > 0) {
        frame--;
        *(s16 *)(arg2 + 0x12) = frame;
        return 0;
    }
    alpha = (f32)(arg3 * 0xFF) / 255.0f;
    index = *(s32 *)(arg2 + 4);
    total = sp60[index];
    frame = *(s16 *)(arg2 + 0x10);
    f1 = (f32)frame;
    f2 = f1 / (f32)total;
    if (frame < 0x1E) {
        alpha = (f1 / 30.0f) * alpha;
    } else if ((total - 0x1E) < frame) {
        alpha = alpha * ((f32)(total - frame) / 30.0f);
    }
    f16 = 2.0f * (f32)sp60[index + 0x20];
    delta = 512.0f * (f1 / (f32)total);
    func_002a66d0(
        *(f32 *)(arg2 + 8) - delta,
        *(f32 *)(arg2 + 0xC) + delta,
        0.0f,
        D_00761184 * f16,
        f16,
        0xFFF267,
        (s32)alpha,
        1);
    next = frame + 1;
    *(s16 *)(arg2 + 0x10) = next;
    index = *(s32 *)(arg2 + 4);
    total = sp60[index];
    if ((s64)(s64)next >= (s64)total) {
        *(s16 *)(arg2 + 0x10) = 0;
        return 1;
    }
    if (next == (total >> 2) * 3) {
        rand = func_003b7060((s32)next);
        randf = (f32)(u32)rand;
        temp = 10.0f * (randf / 2147483648.0f);
        result = (s32)(u32)temp + 30;
        saved_index = *(s32 *)(arg2 + 4);
        saved_f8 = *(f32 *)(arg2 + 8);
        saved_fc = *(f32 *)(arg2 + 0xC);
        q = (u8 *)func_002a7330(arg1);
        if (q != NULL) {
            *(s32 *)(q + 4) = saved_index;
            *(f32 *)(q + 8) = saved_f8;
            *(f32 *)(q + 0xC) = saved_fc;
            *(s16 *)(q + 0x12) = (s16)result;
        }
    }
    return 0;
}
