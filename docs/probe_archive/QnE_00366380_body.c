/*
 * Best plain-C reconstruction probe for func_00366380 (lane QnE).
 *
 * Object: 752B; retail window: 752B; normalized_diff: 172 words.
 * Differing offsets (word byte offsets): 8-380, 392-732.
 * Exact/relocation-masked words remain at prologue 0-4, selected loop/body
 * words 384-388 and 396-400, and epilogue 736-748.
 *
 * Ruled out: volatile, inline assembly, whole-function asm, intrinsics,
 * text permuter, constant/string-pool substitutions, and unmeasured pragmas.
 * The only data/function references are the real D_0064E320 table,
 * iGpffffabe8 global, and renderer functions func_0045e6a0/e8e0/eb20.
 * COP1 accumulator chain: reproduced from ordinary C arithmetic; no COP1
 * intrinsic or asm was used. Candidate was not closed because the remaining
 * register colouring, copy-loop shape, and control-flow schedule differ.
 */

void func_00366380(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                   f32 farg0, f32 farg1, f32 fparg2, f32 fparg3,
                   s16 arg_sp0, s32 arg_sp8)
{
    typedef union {
        P4Pair raw;
        PairF32 f;
    } PointBits;
    PointBits points[18];
    u8 colors[18][4];
    register s32 i;
    s64 dx;
    s64 dy;
    u32 packed;
    f32 x;
    f32 y;
    extern P4Pair D_0064E320[];
    extern void func_0045e6a0(void *, void *, s32, s32, s32, s64, s64, s64);
    extern void func_0045e8e0(void *, void *, s32, s32, s32, s64, s64, s64);
    extern void func_0045eb20(void *, void *, s32, s32, s32, s64, s64, s64);
    extern s64 iGpffffabe8;
    for (i = 0; i < 18; i++) {
        points[i].raw.lo = D_0064E320[i].lo;
        points[i].raw.hi = D_0064E320[i].hi;
    }
    x = (f32)(arg2 - 10) * fparg2;
    y = (f32)(arg3 - 10) * fparg3;
    points[0].f.x = 5.0f + x * 0.5f;
    points[0].f.y = 5.0f + y * 0.5f;

    points[5].f.x = x + 5.0f;
    points[7].f.x = x + 7.0f;
    points[9].f.x = x + 9.0f;
    points[11].f.x = x + 10.0f;
    points[12].f.x = points[11].f.x;
    points[13].f.x = x + 5.0f;
    points[14].f.x = y + 5.0f;
    points[15].f.x = y + 7.0f;
    points[16].f.x = x + 7.0f;
    points[17].f.x = y + 9.0f;

    dx = (s64)(s16)(s32)((f32)arg7 - points[0].f.x);
    dy = (s64)(s16)(s32)((f32)arg_sp0 - points[0].f.y);
    packed = ((u32)arg4 << 8) | (u32)arg5;
    for (i = 0; i < 18; i++) {
        points[i].f.x += (f32)arg0;
        points[i].f.y += (f32)arg1;
        colors[i][0] = (u8)(packed >> 24);
        colors[i][1] = (u8)(packed >> 16);
        colors[i][2] = (u8)(packed >> 8);
        colors[i][3] = (u8)packed;
    }
    if (arg_sp8 != 0) {
        if (arg5 == 0xFF) {
            func_0045eb20(colors, points, 18, 5, arg6, dx, dy, arg_sp8);
        } else {
            func_0045e8e0(colors, points, 18, 5, arg6, dx, dy, arg_sp8);
        }
        return;
    }
    if (arg5 == 0xFF) {
        iGpffffabe8 |= 0x80;
        func_0045e6a0(colors, points, 18, 5, arg6, dx, dy, dx);
        iGpffffabe8 &= ~0x80;
    } else {
        func_0045e6a0(colors, points, 18, 5, arg6, dx, dy, dx);
    }
}
