/* Archived candidate for func_002a73c0.
 * Compiler: MWCCPS2 (retail prologue uses sq $s3/$s2/$s1/$s0; not ee-gcc).
 * Measured object 780B / retail window 848B / normalized_diff 177.
 * Differing word offsets: 32,36,40,44,48,52,56,60,64,68,72,76,84,92,96,100,104,108,112,116,120,124,128,136,144,160,168,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,280,284,292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,368,372,376,380,384,388,392,396,400,404,412,416,420,424,428,432,436,440,444,448,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,524,528,532,536,544,548,552,556,560,564,568,572,576,580,584,588,592,596,600,604,608,612,616,620,624,628,632,636,640,644,648,652,656,660,664,668,672,676,680,684,688,692,696,700,712,716,720,724,728,732,736,740,744,748,752,756,760,764,768,772,776,784,788,792,796,800,804,808,812,816,820,824,828,832,836.
 * Conversion sites rewritten:
 *   .L002A7470 sll/subu -> mtc1/cvt.s.w: signed s32 arg3*0xFF, (f32)(arg3 * 0xFF).
 *   post-.L002A7470 lh frame -> mtc1/cvt.s.w: signed s16, (f32)frame.
 *   post-.L002A7470 lw total -> mtc1/cvt.s.w: signed s32, (f32)total.
 *   .L002A755C stack word -> cvt.s.w: signed s32 sp60[index+0x20], (f32)sp60[index + 0x20].
 *   .L002A7640 rand s32 unsigned-int-to-float idiom: (f32)(u32)rand.
 *   .L002A765C trunc/mfc1/or float-to-unsigned idiom: (s32)(u32)temp + 30.
 * Corrected func_002a66d0 call to the verified MATCH file-scope signature
 * (five f32 parameters followed by three s32 parameters).
 * Ruled out before archive: wrong local helper prototype, partial conversion rewrites,
 * hand-written unsigned conversion fixups, and saved-register/index/address-shape
 * variants represented by the candidate bodies in KernelMc_73c0_candidates*.json.
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
