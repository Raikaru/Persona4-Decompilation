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
void RpSkyRenderStateSet(s32 param, s32 value);
void func_00489f80(void);
void func_0048a000(void);
s32 func_00457120(void);
f32 cosf(f32 fparg0);
f32 sinf(f32 fparg0);
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




typedef struct ShdQuadVertex {
    f32 x;
    f32 y;
    f32 z;
    f32 unknown0C;
    f32 u;
    f32 v;
    f32 q;
    f32 unknown1C;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 unknown30[4];
} ShdQuadVertex;

#pragma push
/* measured: byte-exact (372/372 instructions, 0 differing words, 1488-byte
   window).  opt_loop_invariants hoists the 255.0f bit pattern and the
   unsigned-conversion pieces out of the three vertex loops.  Each loop owns
   its counter in a block scope; a function-scope `i` takes $v0 ahead of the
   hoisted invariants and costs 55 edits.  The render-state and draw tables
   go through `(void *)`-cast locals, which keeps retail's $s0/$s6 bases
   (the direct `D_00887300[0]` spelling is folded to lui/lw at every call).
   The colour channels are s32, which gives retail's $s5-$s2 colouring. */
#pragma opt_loop_invariants on
// FUN_00364680
void func_00364680(f32 depth, s32 color, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, u8 *ptr, s32 arg2, s32 arg3)
{
    ShdQuadVertex verts[4];
    f32 z;
    f32 q;
    s32 alpha;
    s32 red;
    s32 green;
    s32 blue;
    s32 flag;
    void (**renderState)(u32 state, u32 value);
    s32 (**draw)(s32, void *, s32);

    z = D_008872F8[0] - depth;
    q = 1.0f / *(f32 *)((u8 *)func_00457120() + 0x80);
    if (ptr == NULL) {
        func_0046d730(D_0064E2F8, 153);
    }
    alpha = (u8)(((u32)color & 0xFF000000) >> 24);
    red = (u8)(((u32)color & 0x00FF0000) >> 16);
    green = (u8)(((u32)color & 0x0000FF00) >> 8);
    blue = color & 0xFF;
    flag = (blue ^ 0xFF) != 0;
    if (flag) {
        flag = arg2 != 0;
    }
    verts[0].z = z;
    verts[1].z = z;
    verts[2].z = z;
    verts[3].z = z;
    verts[0].q = q;
    verts[1].q = q;
    verts[2].q = q;
    verts[3].q = q;
    verts[0].u = 0.0f;
    verts[0].v = 0.0f;
    verts[1].u = 1.0f;
    verts[1].v = 0.0f;
    verts[2].u = 1.0f;
    verts[2].v = 1.0f;
    verts[3].u = 0.0f;
    verts[3].v = 1.0f;
    renderState = (void *)D_00887300;
    renderState[0](7, 2);
    renderState[0](6, 0);
    renderState[0](8, 0);
    renderState[0](0xE, 0);
    renderState[0](9, 2);
    renderState[0](0xC, 1);
    renderState[0](1, *(u32 *)ptr);
    RpSkyRenderStateSet(2, 0x44);
    func_00489f80();
    if (flag) {
        verts[0].x = fparg3;
        verts[0].y = fparg4;
        verts[1].x = fparg3 + fparg5;
        verts[1].y = fparg4;
        verts[2].x = fparg3 + fparg5;
        verts[2].y = fparg4 + fparg6;
        verts[3].x = fparg3;
        verts[3].y = fparg4 + fparg6;
        {
            s32 i;

            for (i = 0; i < 4; i++) {
                verts[i].r = 255.0f;
                verts[i].g = 255.0f;
                verts[i].b = 255.0f;
                verts[i].a = 255.0f;
            }
        }
        RpSkyRenderStateSet(3, 0x31801);
        D_00887310[0](5, verts, 4);
    }
    verts[0].x = fparg1;
    verts[0].y = fparg2;
    verts[1].x = fparg1 + fparg5;
    verts[1].y = fparg2;
    verts[2].x = fparg1 + fparg5;
    verts[2].y = fparg2 + fparg6;
    verts[3].x = fparg1;
    verts[3].y = fparg2 + fparg6;
    {
        s32 i;

        for (i = 0; i < 4; i++) {
            verts[i].r = 255.0f;
            verts[i].g = 255.0f;
            verts[i].b = 255.0f;
            verts[i].a = (f32)(u32)blue;
        }
    }
    if (flag) {
        RpSkyRenderStateSet(3, 0x35801);
    } else {
        RpSkyRenderStateSet(3, 0x31801);
    }
    draw = (void *)D_00887310;
    draw[0](5, verts, 4);
    func_0048a000();
    renderState[0](1, 0);
    switch (arg3) {
    case 0:
        RpSkyRenderStateSet(2, 0x54);
        break;
    case 1:
        RpSkyRenderStateSet(2, 0x58);
        break;
    default:
        func_0046d730(D_0064E2F8, 265);
        break;
    }
    if (flag) {
        RpSkyRenderStateSet(3, 0x35801);
    } else {
        RpSkyRenderStateSet(3, 0x31801);
    }
    verts[0].x = fparg1;
    verts[0].y = fparg2;
    verts[1].x = fparg1 + fparg5;
    verts[1].y = fparg2;
    verts[2].x = fparg1;
    verts[2].y = fparg2 + fparg6;
    verts[3].x = fparg1 + fparg5;
    verts[3].y = fparg2 + fparg6;
    {
        s32 i;

        for (i = 0; i < 4; i++) {
            verts[i].r = (f32)(u32)alpha;
            verts[i].g = (f32)(u32)red;
            verts[i].b = (f32)(u32)green;
            verts[i].a = (f32)(u32)blue;
        }
    }
    draw[0](4, verts, 4);
}
#pragma pop

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
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    far_depth = D_008872F8[0];
    sine = sinf(angle);
    cosine = cosf(angle);
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



/* The far-column store retains the origin load, and the separate Y
 * accumulation preserves the fused rotation before its offset add. */
static inline void shdFarX(f32 *out, const f32 *origin,
                           f32 offset, f32 length, f32 sine)
{
    *out = (0.0f + (*origin + offset)) - length * sine;
}

// FUN_00364FB0
void func_00364fb0(Vec2f position, f32 depth, s32 color, f32 angle, s32 arg2, s32 arg3) {
    f32 vertices[4][16];
    f32 sine;
    f32 far_depth;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 cosine;
    f32 far_y;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;

    origin_x = position.x;
    origin_y = position.y;
    far_depth = D_008872F8[0] - depth;
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    sine = sinf(angle);
    cosine = cosf(angle);
    red = (s32)(u8)(((u32)color >> 24) & 0xFF);
    green = (s32)(u8)(((u32)color >> 16) & 0xFF);
    blue = (s32)(u8)(((u32)color >> 8) & 0xFF);
    alpha = color & 0xFF;
    vertices[0][0] = origin_x;
    vertices[0][1] = origin_y;
    vertices[0][2] = far_depth - depth;
    vertices[0][8] = (f32)(u32)red;
    vertices[0][9] = (f32)(u32)green;
    vertices[0][10] = (f32)(u32)blue;
    vertices[0][11] = (f32)(u32)alpha;
    vertices[0][6] = reciprocal;
    vertices[1][0] = origin_x + 71.0f * cosine;
    vertices[1][1] = origin_y + 71.0f * sine;
    vertices[1][2] = far_depth - depth;
    vertices[1][8] = (f32)(u32)red;
    vertices[1][9] = (f32)(u32)green;
    vertices[1][10] = (f32)(u32)blue;
    vertices[1][11] = (f32)(u32)alpha;
    vertices[1][6] = reciprocal;
    if (arg3 != 0) {
        vertices[2][0] = (0.0f + origin_x) - 402.0f * sine;
        vertices[2][1] = (0.0f + origin_y) + 402.0f * cosine;
        vertices[2][2] = far_depth - depth;
        vertices[2][8] = (f32)(u32)red;
        vertices[2][9] = (f32)(u32)green;
        vertices[2][10] = (f32)(u32)blue;
        vertices[2][11] = (f32)(u32)alpha;
        vertices[2][6] = reciprocal;
        shdFarX(&vertices[3][0], &origin_x, 71.0f * cosine, 473, sine);
        far_y = (0.0f + origin_y) + 473 * cosine;
        far_y += 71.0f * sine;
        vertices[3][1] = far_y;
        vertices[3][2] = far_depth - depth;
        vertices[3][8] = (f32)(u32)red;
        vertices[3][9] = (f32)(u32)green;
        vertices[3][10] = (f32)(u32)blue;
        vertices[3][11] = (f32)(u32)alpha;
        vertices[3][6] = reciprocal;
    } else {
        vertices[2][0] = (0.0f + origin_x) - 473 * sine;
        vertices[2][1] = (0.0f + origin_y) + 473 * cosine;
        vertices[2][2] = far_depth - depth;
        vertices[2][8] = (f32)(u32)red;
        vertices[2][9] = (f32)(u32)green;
        vertices[2][10] = (f32)(u32)blue;
        vertices[2][11] = (f32)(u32)alpha;
        vertices[2][6] = reciprocal;
        shdFarX(&vertices[3][0], &origin_x, 71.0f * cosine, 402.0f, sine);
        far_y = (0.0f + origin_y) + 402.0f * cosine;
        far_y += 71.0f * sine;
        vertices[3][1] = far_y;
        vertices[3][2] = far_depth - depth;
        vertices[3][8] = (f32)(u32)red;
        vertices[3][9] = (f32)(u32)green;
        vertices[3][10] = (f32)(u32)blue;
        vertices[3][11] = (f32)(u32)alpha;
        vertices[3][6] = reciprocal;
    }
    if (arg2 != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, vertices, 4);
    if (arg2 != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
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
    temp_f23 = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
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
        sine = sinf(temp_f27);
        cosine = cosf(temp_f27);
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


/* Keep the signed axis components and geometry parameters live across
 * their actual operations; the native 1088-byte window is exact. */
#pragma push
#pragma opt_loop_invariants on
static inline f32 outlineSignedExtent(s32 sign, f32 extent)
{
    return (f32)sign * extent;
}
static inline f32 outlineExtent(s32 isTip, s32 half, f32 width, f32 height)
{
    return width * (f32)half + height * (f32)isTip;
}
static inline f32 outlineAxis(s32 phase, f32 width, f32 height)
{
    s32 isTip = (phase % 4) == 1;
    s32 half = ((phase + 1) % 4) / 2;
    f32 extent = outlineExtent(isTip, half, width, height);
    return outlineSignedExtent(phase < 4 ? 1 : -1, extent);
}
// FUN_00365AC0
void func_00365ac0(Vec2f position, f32 depth, s32 color, f32 angle, f32 width, f32 height, s32 mode) {
    f32 output[160];
    f32 vertexDepth;
    f32 reciprocalDepth;
    f32 rotationA;
    f32 originX;
    f32 originY;
    f32 rotationB;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 i;
    u8 *camera;
    originY = position.y;
    originX = position.x;
    width = width * iGpffff83d4;
    vertexDepth = D_008872F8[0] - depth;
    camera = ((u8 *)(u32)func_00457120());
    reciprocalDepth = 1.0f / *(f32 *)(camera + 0x80);
    red = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    green = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    blue = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    alpha = color & 0xFF;
    rotationA = sinf(angle);
    rotationB = cosf(angle);
    i = 0;
    for (; i < 10; i++) {
        s32 mod8a = i % 8;
        s32 mod8b = (i + 6) % 8;
        f32 X = outlineAxis(mod8a, width, height);
        f32 Y = outlineAxis(mod8b, width, height);
        f32 *row;
        row = &output[i * 16];
        row[0] = originX + X * rotationB - Y * rotationA;
        row[1] = originY + Y * rotationB + X * rotationA;
        row[2] = vertexDepth;
        row[6] = reciprocalDepth;
        row[8] = (f32)(u32)red;
        row[9] = (f32)(u32)green;
        row[10] = (f32)(u32)blue;
        row[11] = (f32)(u32)alpha;
    }
    D_00887300[0](1, 0);
    if (mode != 0 && (alpha & 0xFF) == 0xFF) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, output, 10);
    if (mode != 0 && (alpha & 0xFF) == 0xFF) {
        iGpffffabe8 &= ~0x80;
    }
}
#pragma pop

/* The checked low-halfword count and full-width angle divisor have separate
 * lifetimes. Inline validation and alpha/blue/green/red snapshots reproduce
 * 1148 executable bytes and 17 resolved relocations; four zero bytes align
 * the next function. */
static inline s32 radialCheckedSegmentCount(u32 segments)
{
    s32 count = (s32)(segments & 0xFFFF);
    if (count <= 0 || count > 100) {
        func_0046d730(D_0064E2F8, 571);
    }
    return count;
}

// FUN_00365F00
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
    reciprocal = 1.0f / *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    num_segments = radialCheckedSegmentCount(segments);
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
        sine = sinf(current_angle);
        vertex[1][0] = (0.0f + origin_x) + xscale * (radius * sine);
        cosine = cosf(current_angle);
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
