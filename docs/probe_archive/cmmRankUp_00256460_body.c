/* cmmRankUp.c: func_00256460 best attempt (not MATCHed)
 * object 608B, window 624B, differing words 126 (reloc-masked)
 * Residual differs in: color-compute FP register allocation and second-loop
 *   pointer/one register allocation (retail uses $s5 for pointer, $s0 for one;
 *   mwcc uses $a0 for pointer, $s5 for one). Final 16 bytes of nops missing.
 * Levers tried:
 *   - s32 arg4 + s16 arg5/arg6 + s32 arg7 vs s64 arg5/arg6 (latter worse)
 *   - u32 packed vs s32 packed, pointer copy loop vs pairs[i] copy
 *   - compute e before d, compute d before e, inline value2/value3 schedule
 *   - s64/s32 func_0045e6a0 prototypes and call spellings
 *   - #pragma opt_propagation off/on (worse: 140 diffs, shifted function)
 */
void func_00256460(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s16 arg5, s16 arg6, s32 arg7,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4) {
    typedef struct { u8 r; u8 g; u8 b; u8 a; } RGBA;
    typedef union { struct { f32 x; f32 y; } f; struct { u32 w0; u32 w1; } w; s64 align; } Pair;
    typedef struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work;
    Work work;
    Pair *src;
    Pair *dst;
    s32 count;
    u32 w0;
    u32 w1;
    u32 packed;
    u32 packed2;
    u32 packed3;
    u32 packed4;
    u32 i;
    f32 value2;
    f32 value3;
    s32 one;
    s32 c0, c1, c2, c3;
    s32 b0, b1, b2, b3;
    s32 d0, d1, d2, d3;
    s32 e0, e1, e2, e3;
    Pair *pairp;
    u8 *p;

    src = (Pair *)D_00636390;
    dst = work.pairs;
    count = 0x10;
    do {
        w0 = src->w.w0;
        w1 = src->w.w1;
        src++;
        count--;
        dst->w.w0 = w0;
        dst->w.w1 = w1;
        dst++;
    } while (count > 0);

    i = 0;
    packed = arg0 << 8;
    b0 = (packed >> 24) & 0xFF;
    b1 = (packed >> 16) & 0xFF;
    b2 = arg0 & 0xFF;
    b3 = packed & 0xFF;
    value2 = ((f32)arg2 * 255.0f) / 255.0f;
    value3 = ((f32)arg3 * 255.0f) / 255.0f;
    packed2 = packed | arg1;
    c0 = (packed2 >> 24) & 0xFF;
    c1 = (packed2 >> 16) & 0xFF;
    c2 = (packed2 >> 8) & 0xFF;
    c3 = packed2 & 0xFF;
    one = 1;
    packed3 = packed | (s32)value3;
    d0 = (packed3 >> 24) & 0xFF;
    d1 = (packed3 >> 16) & 0xFF;
    d2 = (packed3 >> 8) & 0xFF;
    d3 = packed3 & 0xFF;
    packed4 = packed | (s32)value2;
    e0 = (packed4 >> 24) & 0xFF;
    e1 = (packed4 >> 16) & 0xFF;
    e2 = (packed4 >> 8) & 0xFF;
    e3 = packed4 & 0xFF;

    while (i < 0x10U) {
        pairp = work.pairs + i;
        pairp->f.x += fparg0;
        pairp->f.y += fparg1;
        p = (u8 *)&work.rgba[i];
        if (i == 0 || i == one || (u32)(i - 0xE) < 2U) {
            p[0] = b0; p[1] = b1; p[2] = b2; p[3] = b3;
        } else if ((u32)(i - 6) < 4U) {
            p[0] = e0; p[1] = e1; p[2] = e2; p[3] = e3;
        } else if ((u32)(i - 0xA) < 4U) {
            p[0] = d0; p[1] = d1; p[2] = d2; p[3] = d3;
        } else {
            p[0] = c0; p[1] = c1; p[2] = c2; p[3] = c3;
        }
        i++;
    }

    func_0045e6a0(work.rgba, work.pairs, fparg2, 0x10, 4,
                  arg4, arg5, arg6, 0.0f, fparg3, fparg4);
}
