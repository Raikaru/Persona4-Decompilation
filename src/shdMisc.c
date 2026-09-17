/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "shd_misc_internal.h"


/* gp - 0x5418 = 0x00763CD8, accessed as a 64-bit word (ld/sd). */
extern s64 iGpffffabe8;

/* gp - 0x4A58 = 0x00764698. */
extern s32 iGpffffb5a8;

extern f32 D_0064E310[];
extern f32 D_0064E314[];
extern f32 D_0064E318[];
extern f32 D_0064E31C[];
extern f32 D_008872F8[];
extern f32 iGpffff8094;
extern f32 iGpffff81e0;
extern f32 iGpffff83d4;
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 (*D_00887310[])(s32, void *, s32);

extern char D_005E5810[];
extern char D_0064E2F8[];

u32 func_00105ed0(void);
s32 func_0046a770(char *param);
void func_0046d730(char *, s32);
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3,
                  f32 z, s32 arg4);
void func_003f6440(s32 param, s32 value);
void func_00489f80(void);
void func_0048a000(void);
u8 *func_00457120(void);
f32 func_0044b610(f32 fparg0);
f32 func_0044b7b0(f32 fparg0);
s32 func_003645c0(char *arg0, s32 rem);

/* Measured: Vec2f-by-value, explicit digit-pointer lifetime and separate alpha
 * extraction reproduce 660 executable bytes and 18 resolved relocations.
 * The remaining 12 bytes are zero function-alignment padding. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00364320
void func_00364320(Vec2f pos, f32 z, s32 color, s32 num)
{
    char tmp[64];
    s32 ch;
    s32 i;
    s32 alpha;
    char *p;

    if (color & 0xFF) {
        if (num <= 0) {
            num = func_00105ed0();
        }
        func_003645c0(tmp, num);
        if (iGpffffb5a8 == 0) {
            s32 temp = func_0046a770(D_005E5810);
            iGpffffb5a8 = temp;
            if (temp == 0) {
                func_0046d730(D_0064E2F8, 0x31);
            }
        }
        {
            void (**base)(u32, u32) = D_00887300;
            base[0](6, 1);
            base[0](7, 2);
            base[0](8, 1);
            base[0](9, 2);
            base[0](0xC, 1);
            base[0](0xB, 6);
            base[0](0xA, 5);
            base[0](2, 4);
            base[0](0xE, 0);
        }
        alpha = color & 0xFF;
        alpha = 0xFF - alpha;
        func_0046d3b0(0, iGpffffb5a8, 0x19, pos.x, pos.y, 0, alpha, z, 0);
        pos.x += 36.0f;
        for (i = 0; (p = tmp + i, ch = *p) != 0; i++) {
            switch (ch) {
            case '.':
                func_0046d3b0(0, iGpffffb5a8, 0x18, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 8.0f;
                break;
            default:
                func_0046d3b0(0, iGpffffb5a8, ch - 0x22, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 19.0f;
                break;
            }
        }
    }
}
#pragma pop


/* Matched.  Formats a decimal with a '.' every three digits and returns the
   digit count, which is what keeps the index in $v0.  opt_loop_invariants
   on is load-bearing: it hoists the four constants into the preheader
   (without it the function measures 59 words); the named constant locals
   the earlier body carried were not. */
#pragma push
#pragma opt_loop_invariants on
// FUN_003645C0
s32 func_003645c0(char *out, s32 value)
{
    char tmp[16];
    s32 i;
    s32 cnt;
    s32 j;
    s32 next;

    i = 0;
    cnt = 0;
    do {
        tmp[i] = (char)((value % 10) + '0');
        i++;
        value = value / 10;
        if (value > 0 && cnt == 2) {
            tmp[i] = '.';
            i++;
        }
        cnt = (cnt + 1) % 3;
    } while (value > 0);
    j = 0;
    while (j < i) {
        next = j + 1;
        out[j] = tmp[i - next];
        j = next;
    }
    out[j] = 0;
    return i;
}
#pragma pop




/* measured: multi-issue floor. Retail 1488B; mwcc-compiled candidate 1840B
   (352B over) via 4x0x10 struct-array + separate struct-field stores. The
   D_00887300/D_00887310 base-hoist recipes and the D_0064E2F8 array decl
   match retail exactly; the bltz color-byte pattern needs the `f = f + f`
   doubling (retail add.s f0,f0,f0) not `2.0f *` (mul.s). Remaining issues:
   f26/f25 float-register swap (sub.s/div.s), arg-prologue int-vs-float move
   order, arg3 switch test order (retail tests ==1 then ==0), and the third
   D_00887310 call's base-hoist timing. Tried 1 spelling (struct array). */
// FUN_00364680
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364680);

// FUN_00364C50
void func_00364c50(void) {
    iGpffffabe8 |= 0x80;
}

// FUN_00364C70
void func_00364c70(void) {
    iGpffffabe8 &= ~0x80;
}

/* measured: Vec2f-by-value and scalar geometry snapshots reproduce the
   retail argument spill, FP lifetimes and load-all/store-all schedule.
   All 796 executable bytes and 21 resolved relocations match; the remaining
   four bytes are unreachable function-alignment padding. */
// FUN_00364C90
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_00364c90(Vec2f position, f32 depth, s32 color,
                   f32 width, f32 height, f32 angle, s32 mode) {
    f32 vertices[4][16];
    f32 geometry[4];
    f32 far_depth;
    f32 sine;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 cosine;
    s32 red, green, blue, alpha;
    s32 i;
    f32 x, y;
    f32 *vertex;

    origin_x = position.x;
    origin_y = position.y;
    {
        f32 first = D_0064E310[0];
        f32 second = D_0064E314[0];
        f32 third = D_0064E318[0];
        f32 fourth = D_0064E31C[0];
        geometry[0] = first;
        geometry[1] = second;
        geometry[2] = third;
        geometry[3] = fourth;
    }
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    far_depth = D_008872F8[0];
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);
    red = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    green = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    blue = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    alpha = color & 0xFF;
    for (i = 0; i < 4; i++) {
        x = width * geometry[(i + 1) % 4];
        y = height * geometry[i];
        vertex = vertices[i];
        vertex[0] = (0.0f + origin_x) + x * cosine - y * sine;
        vertex[1] = (0.0f + origin_y) + x * sine + y * cosine;
        vertex[2] = far_depth - depth;
        vertex[8] = (f32)(u32)red;
        vertex[9] = (f32)(u32)green;
        vertex[10] = (f32)(u32)blue;
        vertex[11] = (f32)(u32)alpha;
        vertex[6] = reciprocal;
    }
    D_00887300[0](1, 0);
    if (mode != 0 && alpha == 255) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, vertices, 4);
    if (mode != 0 && alpha == 255) {
        iGpffffabe8 &= ~0x80;
    }
}
#pragma opt_loop_invariants off
#pragma opt_propagation on



/* measured: clean-C probe was object 1488B over a 2080B window (nd 495).
   Retail's vertex path contains COP1 accumulator adda/msub/madd sequences;
   the archived plain-C probe is not byte-exact and remains uncommitted. */
// FUN_00364FB0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364fb0);

/* measured: Vec2f-by-value preserves the exact 752-byte body and 14 relocations.
   The canonical declaration is shared with the panel transition caller. */
/* measured: the four byte->float conversions are plain `(f32)(u32)x` (mwcc emits the
   bltz / srl-andi-or / mtc1 / cvt / add.s idiom itself with retail's $v1 destination;
   spelling it out by hand colours $v0). The angle is `iGpffff8094 * (f32)var_20`
   in one expression so the GP constant is the first mul.s operand. */
// FUN_003657D0
void func_003657d0(Vec2f arg0, f32 fparg0, s32 arg1, f32 fparg1, f32 fparg2, s32 arg2) {
    f32 vertices[4][16];
    f32 sine;
    f32 cosine;
    f32 temp_f23;
    f32 origin_x;
    f32 origin_y;
    f32 temp_f20;
    f32 temp_f27;
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 var_20;
    u8 *temp_2;

    origin_y = arg0.y;
    origin_x = arg0.x;
    temp_f23 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f20 = D_008872F8[0];
    temp_19 = (s32)(u8)(((u32)arg1 & 0xFF000000) >> 24);
    temp_18 = (s32)(u8)(((u32)arg1 & 0x00FF0000) >> 16);
    temp_17 = (s32)(u8)(((u32)arg1 & 0x0000FF00) >> 8);
    temp_16 = arg1 & 0xFF;
    var_20 = 0;
    temp_f20 -= fparg0;
    while (var_20 < 4) {
        temp_f27 = iGpffff8094 * (f32)var_20;
        temp_f27 += fparg2;
        sine = func_0044b7b0(temp_f27);
        cosine = func_0044b610(temp_f27);
        temp_2 = (u8 *)&vertices[var_20][0];
        *(f32 *)(temp_2 + 0) = origin_x + fparg1 * sine;
        *(f32 *)(temp_2 + 4) = origin_y + fparg1 * cosine;
        *(f32 *)(temp_2 + 8) = temp_f20;
        *(f32 *)(temp_2 + 0x20) = (f32)(u32)temp_19;
        *(f32 *)(temp_2 + 0x24) = (f32)(u32)temp_18;
        *(f32 *)(temp_2 + 0x28) = (f32)(u32)temp_17;
        *(f32 *)(temp_2 + 0x2C) = (f32)(u32)temp_16;
        *(f32 *)(temp_2 + 0x18) = temp_f23;
        var_20 += 1;
    }
    D_00887300[0](1, 0);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, &vertices[0], 4);
    if ((arg2 != 0) && ((temp_16 & 0xFF) == 0xFF)) {
        iGpffffabe8 &= ~0x80;
    }
}


// FUN_00365AC0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365ac0);

/* measured (mwcc b210 -O2): guarded body compiles to 1148B over the 1152B
   window with 17 independently resolved relocations, normalized diff 25.
   `python3 tools/probe_variants.py src/shdMisc.c func_00365f00
   --candidate base=/var/tmp/cand_00365f00.c` reproduces 25; replay with
   `python3 tools/measure_guarded.py src/shdMisc.c func_00365f00`.
   All 25 differing words are one five-register color/count rotation:
   generated edge_a=$s3 edge_b=$s2 edge_g=$s6 edge_r=$s7 count=$fp against
   retail edge_a=$s2 edge_b=$s6 edge_g=$s7 edge_r=$fp count=$s3; every other
   word including frame, spills, FP schedule and relocations is identical.
   Ten declaration/type spellings tie at 25 (edge swap, count-first,
   count-after-edge, reversed edges, edge_a-last, i-last, u16 count,
   edge/center interleave, init-at-declaration, u32 count mask), so the
   rotation is a saved-register coloring floor, not an ordering oversight.
   Complete source and probe evidence:
   docs/probe_archive/RadialProvider_00365f00_body.c. Production stays ASM. */
// FUN_00365F00 NONMATCHING
#ifdef NON_MATCHING
void func_00365f00(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
                   f32 radius, f32 angle, u32 segments, f32 xscale, f32 yscale,
                   s32 mode) {
    f32 vertices[102][16];
    f32 (*vertex)[16];
    f32 sine;
    f32 cosine;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 far_depth;
    f32 current_angle;
    s32 i;
    s32 edge_a;
    s32 edge_b;
    s32 edge_g;
    s32 edge_r;
    s32 center_a;
    s32 center_b;
    s32 center_g;
    s32 num_segments;
    edge_a = ((u8 *)&edgeColor)[3];
    edge_b = ((u8 *)&edgeColor)[2];
    edge_g = ((u8 *)&edgeColor)[1];
    edge_r = ((u8 *)&edgeColor)[0];
    center_a = ((u8 *)&centerColor)[3];
    center_b = ((u8 *)&centerColor)[2];
    center_g = ((u8 *)&centerColor)[1];
    origin_y = *(f32 *)((u8 *)&position + 4);
    origin_x = position.x;
    far_depth = D_008872F8[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    num_segments = (s32)(segments & 0xFFFF);
    if (num_segments <= 0 || num_segments > 100) {
        func_0046d730(D_0064E2F8, 571);
    }
    vertices[0][0] = position.x;
    vertices[0][1] = origin_y;
    far_depth -= depth;
    vertices[0][2] = far_depth;
    vertices[0][8] = (f32)(u32)((u8 *)&centerColor)[0];
    vertices[0][9] = (f32)(u32)center_g;
    vertices[0][10] = (f32)(u32)center_b;
    vertices[0][11] = (f32)(u32)center_a;
    for (i = 0; i <= num_segments; i++) {
        current_angle = angle + (iGpffff81e0 * (f32)i) / (f32)segments;
        vertex = &vertices[i];
        sine = func_0044b7b0(current_angle);
        vertex[1][0] = (0.0f + origin_x) + xscale * (radius * sine);
        cosine = func_0044b610(current_angle);
        vertex[1][1] = (0.0f + origin_y) + yscale * (radius * cosine);
        vertex[1][2] = far_depth;
        vertex[1][8] = (f32)(u32)edge_r;
        vertex[1][9] = (f32)(u32)edge_g;
        vertex[1][10] = (f32)(u32)edge_b;
        vertex[1][11] = (f32)(u32)edge_a;
        vertex[0][6] = reciprocal;
    }
    D_00887300[0](1, 0);
    if (mode != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, vertices, num_segments + 2);
    if (mode != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);
#endif

