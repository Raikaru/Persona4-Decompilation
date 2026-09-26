/* func_00385380 (src/promoted/code1_0038.c) 2026-09-25 rewrite from the retail
   listing: 378/378 instructions, fnalign 13 edits + 9 reloc-only (gp loads).
   The guarded draft measured 194 edits at 366/377.  Splice with
   `tools/fnalign.py src/promoted/code1_0038.c func_00385380 --candidate <this>`.
   The COP1 chains are ordinary C: `k * grow + (a - b * t)` gives retail's
   adda.s / msuba.s / madd.s, and `221.0f + w * cos - h * sin` /
   `235.0f + h * cos + w * sin` give the adda/madda/msub|madd tails.
   Levers: the gp constant multiply written first (`fGpffff8308 * grow`) so
   it loads before the third call; separate grow/blend locals per phase (13 vs
   14); `u8 alpha` declared before the resource local ($s1/$s2); `++*counter`
   in the final test (retail keeps the incremented value in $v1).
   Residual: FP colouring only.  Retail gives the first call's result
   (`start`) $f21 and the gp-constant/blend group $f20; this body gives start
   $f20 and the blend group $f21, which also swaps delta/halfWidth.  Inert:
   every declaration order of the six phase locals tried (30 permutations plus
   start first/last/after blend), a named delta in phase 1 (14), one blend
   local with separate grow locals (15), opt_lifetimes (13).  Worse:
   opt_propagation off (89), opt_common_subs off (81). */
void func_00385380(u8 *arg0)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    typedef struct { f32 x; f32 y; } Vec2f_5380;
    extern void func_00364c90(Vec2f_5380 pos, f32 depth, s32 color, f32 width, f32 height, f32 angle, s32 mode);
    extern f32 sinf(f32 fparg0);
    extern f32 cosf(f32 fparg0);
    extern f32 fGpffff8308;
    extern f32 fGpffff82cc;
    extern f32 fGpffff80bc;
    extern f32 fGpffff83c8;
    u8 alpha;
    u16 *counter = (u16 *)(arg0 + 0x1E);
    s32 resource = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    Vec2f_5380 point;
    f32 start;
    f32 grow;
    f32 blend;
    f32 delta;
    f32 grow2;
    f32 blend2;
    f32 inv;
    f32 halfWidth;
    f32 halfHeight;
    f32 s;
    f32 c;
    u16 scaleX;
    u16 scaleY;
    u16 next;

    start = func_00373cb0((f32)*counter, 14.0f, 18.0f, 2);
    grow = func_00373cb0((f32)*counter, 5.0f, 6.0f, 1);
    blend = fGpffff8308 * grow + (fGpffff80bc - fGpffff82cc * func_00373cb0((f32)*counter, 0.0f, 5.0f, 1));
    point.x = 318.0f;
    point.y = 231.0f;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    func_00364c90(point, 0.0f, 0x71BA00FF, 270.0f * (blend - start), 45.0f * blend, fGpffff83c8, 0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);

    grow2 = func_00373cb0((f32)*counter, 5.0f, 6.0f, 1);
    blend2 = fGpffff8308 * grow2 + (fGpffff80bc - fGpffff82cc * func_00373cb0((f32)*counter, 2.0f, 5.0f, 1));
    delta = blend2 - start;
    alpha = 255.0f * func_00373cb0((f32)*counter, 2.0f, 5.0f, 1);
    inv = 1.0f - delta;
    halfWidth = (190.0f * inv) / 2.0f;
    s = sinf(fGpffff83c8);
    halfHeight = (39.0f * inv) / 2.0f;
    point.x = 221.0f + halfWidth * cosf(fGpffff83c8) - halfHeight * s;
    s = sinf(fGpffff83c8);
    point.y = 2.0f + (235.0f + ((39.0f * (1.0f - blend2)) / 2.0f) * cosf(fGpffff83c8) + halfWidth * s);
    scaleX = 4096.0f * delta;
    scaleY = 4096.0f * blend2;
    func_0034f4a0(resource, 0x12, point.x, point.y, 0.0f, 0, 0, 0, alpha, scaleX, scaleY, -15.0f, 0, 0);
    if (++*counter >= 0x12) {
        *(u16 *)(arg0 + 0x4C) &= ~8;
    }
}
