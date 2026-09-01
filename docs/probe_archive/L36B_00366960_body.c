/*
 * Closest plain-C reconstruction probe for func_00366960.
 *
 * Retained as an archive after structural and declaration-order probes. The
 * candidate reached object/window 784/784 bytes but normalized_diff 159;
 * remaining differences are saved-register allocation and s128 quadword
 * materialization, so the source fallback remains INCLUDE_ASM.
 */
void func_00366960(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                   f32 fparg0, s16 arg_sp0, s32 *arg_sp8, s32 arg_sp10)
{
    typedef signed __int128 s128;
    typedef union {
        P4Pair raw;
        PairF32 f;
    } PointBits;
    PointBits points[4];
    u8 colors[4][4];
    struct {
        f32 x;
        f32 y;
        f32 z;
    } scratch;
    s128 quad_d0;
    s128 quad_c0;
    s128 quad_b0;
    u8 *p;
    s32 n;
    s32 i;
    u32 packed;
    extern void func_003e4320(void *, void *, void *);
    extern void func_0045e6a0(void *, void *, f32, s32, s32, s32,
                              s16, s16, f32, f32, f32, void *);
    extern void func_0045e8e0(void *, void *, f32, s32, s32, s32,
                              s16, s16, f32, f32, f32, void *);
    extern void func_0045eb20(void *, void *, f32, s32, s32, s32,
                              s16, s16, f32, f32, f32, void *);
    extern s64 iGpffffabe8;

    p = (u8 *)points;
    n = 0x20;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    points[1].f.x = (f32)arg2;
    points[2].f.x = (f32)arg2;
    points[2].f.y = (f32)arg3;
    points[3].f.y = (f32)arg3;
    i = 0;
    packed = ((u32)arg4 << 8) | (u32)arg5;
    quad_d0 = (s128)(packed >> 8);
    quad_c0 = (s128)(packed & 0xFF);
    quad_b0 = 0;
    while ((u32)i < 4U) {
        colors[i][0] = (u8)(packed >> 24);
        colors[i][1] = (u8)(packed >> 16);
        colors[i][2] = (u8)quad_d0;
        colors[i][3] = (u8)quad_c0;
        scratch.x = points[i].f.x - (f32)arg7;
        scratch.y = points[i].f.y - (f32)arg_sp0;
        scratch.z = 0;
        func_003e4320(&scratch, &scratch, arg_sp8);
        points[i].f.x = scratch.x + (f32)arg0;
        points[i].f.y = scratch.y + (f32)arg1;
        i++;
    }
    if (arg_sp10 != 0) {
        if (arg5 == 0xFF) {
            func_0045eb20(colors, points, fparg0, 4, 5, arg6,
                          0, 0, 0.0f, 1.0f, 1.0f, (void *)arg_sp10);
        } else {
            func_0045e8e0(colors, points, fparg0, 4, 5, arg6,
                          0, 0, 0.0f, 1.0f, 1.0f, (void *)arg_sp10);
        }
        return;
    }
    if (arg5 == 0xFF) {
        iGpffffabe8 |= 0x80;
        func_0045e6a0(colors, points, fparg0, 4, 5, arg6,
                      0, 0, 0.0f, 1.0f, 1.0f, (void *)arg_sp10);
        iGpffffabe8 &= ~0x80;
    } else {
        func_0045e6a0(colors, points, fparg0, 4, 5, arg6,
                      0, 0, 0.0f, 1.0f, 1.0f, (void *)arg_sp10);
    }
}
