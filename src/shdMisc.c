/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "shd_misc_internal.h"
#include "mdl_effect_internal.h"


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

u32 datGetMoney(void);
s32 resourceFindByName(char *name);
void kAssertFail(char *, s32);
void sdkSpriteDrawOnceAux(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y, u8 alphaSubtract, u8 fade,
                  f32 z, s32 setStates);
void RpSkyRenderStateSet(s32 param, s32 value);
void mdlEffectEmitMaskedTagPair(void);
void mdlEffectEmitTagPair(void);
s32 kwlnGetCamera(void);
f32 cosf(f32 fparg0);
f32 sinf(f32 fparg0);
s32 shdFormatGroupedNumber(char *out, s32 value);

/* Measured: Vec2f-by-value, explicit digit-pointer lifetime and separate alpha
 * extraction reproduce 660 executable bytes and 18 resolved relocations.
 * The remaining 12 bytes are zero function-alignment padding. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// Intent: Draw a number in sprite digits; a value of zero or less shows the player's money [inferred]
// FUN_00364320
void shdDrawNumberText(Vec2f pos, f32 z, s32 color, s32 num)
{
    char tmp[64];
    s32 ch;
    s32 i;
    s32 alpha;
    char *p;

    if (color & 0xFF) {
        if (num <= 0) {
            num = datGetMoney();
        }
        shdFormatGroupedNumber(tmp, num);
        if (iGpffffb5a8 == 0) {
            s32 temp = resourceFindByName(D_005E5810);
            iGpffffb5a8 = temp;
            if (temp == 0) {
                kAssertFail(D_0064E2F8, 0x31);
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
        sdkSpriteDrawOnceAux(0, iGpffffb5a8, 0x19, pos.x, pos.y, 0, alpha, z, 0);
        pos.x += 36.0f;
        for (i = 0; (p = tmp + i, ch = *p) != 0; i++) {
            switch (ch) {
            case '.':
                sdkSpriteDrawOnceAux(0, iGpffffb5a8, 0x18, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
                pos.x += 8.0f;
                break;
            default:
                sdkSpriteDrawOnceAux(0, iGpffffb5a8, ch - 0x22, pos.x, pos.y + 20.0f, 0, alpha, z, 0);
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
// Intent: Format a number as decimal text with a '.' every three digits and return the digit count [inferred]
// FUN_003645C0
s32 shdFormatGroupedNumber(char *out, s32 value)
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
// Intent: Draw a four-vertex colour quad from its corner floats and colour [inferred]
// FUN_00364680
void shdDrawColourQuad(f32 depth, s32 color, f32 x, f32 y, f32 maskX, f32 maskY, f32 width, f32 height, u8 *texture, s32 drawMask, s32 blendMode)
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
    q = 1.0f / ((MdlEffectCamera *)(u8 *)kwlnGetCamera())->nearPlane;
    if (texture == NULL) {
        kAssertFail(D_0064E2F8, 153);
    }
    alpha = (u8)(((u32)color & 0xFF000000) >> 24);
    red = (u8)(((u32)color & 0x00FF0000) >> 16);
    green = (u8)(((u32)color & 0x0000FF00) >> 8);
    blue = color & 0xFF;
    flag = (blue ^ 0xFF) != 0;
    if (flag) {
        flag = drawMask != 0;
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
    renderState[0](1, *(u32 *)texture);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    if (flag) {
        verts[0].x = maskX;
        verts[0].y = maskY;
        verts[1].x = maskX + width;
        verts[1].y = maskY;
        verts[2].x = maskX + width;
        verts[2].y = maskY + height;
        verts[3].x = maskX;
        verts[3].y = maskY + height;
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
    verts[0].x = x;
    verts[0].y = y;
    verts[1].x = x + width;
    verts[1].y = y;
    verts[2].x = x + width;
    verts[2].y = y + height;
    verts[3].x = x;
    verts[3].y = y + height;
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
    mdlEffectEmitTagPair();
    renderState[0](1, 0);
    switch (blendMode) {
    case 0:
        RpSkyRenderStateSet(2, 0x54);
        break;
    case 1:
        RpSkyRenderStateSet(2, 0x58);
        break;
    default:
        kAssertFail(D_0064E2F8, 265);
        break;
    }
    if (flag) {
        RpSkyRenderStateSet(3, 0x35801);
    } else {
        RpSkyRenderStateSet(3, 0x31801);
    }
    verts[0].x = x;
    verts[0].y = y;
    verts[1].x = x + width;
    verts[1].y = y;
    verts[2].x = x;
    verts[2].y = y + height;
    verts[3].x = x + width;
    verts[3].y = y + height;
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

// Intent: Set bit 0x80 of the shared draw flags, marking the blend pass on [inferred]
// FUN_00364C50
void shdEnableBlendFlag(void) {
    iGpffffabe8 |= 0x80;
}

// Intent: Clear bit 0x80 of the shared draw flags, marking the blend pass off [inferred]
// FUN_00364C70
void shdDisableBlendFlag(void) {
    iGpffffabe8 &= ~0x80;
}

/* measured: Vec2f-by-value and scalar geometry snapshots reproduce the
   retail argument spill, FP lifetimes and load-all/store-all schedule.
   All 796 executable bytes and 21 resolved relocations match; the remaining
   four bytes are unreachable function-alignment padding. */
// Intent: Draw a rotated rectangle of the given width and height; alpha 255 in mode 1 uses the blend flag [inferred]
// FUN_00364C90
#pragma opt_propagation off
#pragma opt_loop_invariants on
void shdDrawRotatedRect(Vec2f position, f32 depth, s32 color,
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
    reciprocal = 1.0f / ((MdlEffectCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
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

// Intent: Draw a wedge from a centre point and an angle; arg3 selects the far-column layout [inferred]
// FUN_00364FB0
void shdDrawWedge(Vec2f position, f32 depth, s32 color, f32 angle, s32 blend, s32 farColumn) {
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
    reciprocal = 1.0f / ((MdlEffectCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
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
    if (farColumn != 0) {
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
    if (blend != 0) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](4, vertices, 4);
    if (blend != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
/* measured: Vec2f-by-value preserves the exact 752-byte body and 14 relocations.
   The canonical declaration is shared with the panel transition caller. */
/* measured: the four byte->float conversions are plain `(f32)(u32)x` (mwcc emits the
   bltz / srl-andi-or / mtc1 / cvt / add.s idiom itself with retail's $v1 destination;
   spelling it out by hand colours $v0). The angle is `iGpffff8094 * (f32)vertexIndex`
   in one expression so the GP constant is the first mul.s operand. */
// Intent: Draw a rotating quad: four points on a circle around the origin, spaced by a fixed angle step [inferred]
// FUN_003657D0
void shdDrawRotatingQuad(Vec2f position, f32 depth, s32 color, f32 radius, f32 initialAngle, s32 blend) {
    f32 vertices[4][16];
    f32 sine;
    f32 cosine;
    f32 reciprocalDepth;
    f32 origin_x;
    f32 origin_y;
    f32 vertexDepth;
    f32 angle;
    s32 alpha;
    s32 blue;
    s32 green;
    s32 red;
    s32 vertexIndex;
    u8 *vertex;

    origin_y = position.y;
    origin_x = position.x;
    reciprocalDepth = 1.0f / ((MdlEffectCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
    vertexDepth = D_008872F8[0];
    red = (s32)(u8)(((u32)color & 0xFF000000) >> 24);
    green = (s32)(u8)(((u32)color & 0x00FF0000) >> 16);
    blue = (s32)(u8)(((u32)color & 0x0000FF00) >> 8);
    alpha = color & 0xFF;
    vertexIndex = 0;
    vertexDepth -= depth;
    while (vertexIndex < 4) {
        angle = iGpffff8094 * (f32)vertexIndex;
        angle += initialAngle;
        sine = sinf(angle);
        cosine = cosf(angle);
        vertex = (u8 *)&vertices[vertexIndex][0];
        ((ShdQuadVertex *)vertex)->x = origin_x + radius * sine;
        ((ShdQuadVertex *)vertex)->y = origin_y + radius * cosine;
        ((ShdQuadVertex *)vertex)->z = vertexDepth;
        ((ShdQuadVertex *)vertex)->r = (f32)(u32)red;
        ((ShdQuadVertex *)vertex)->g = (f32)(u32)green;
        ((ShdQuadVertex *)vertex)->b = (f32)(u32)blue;
        ((ShdQuadVertex *)vertex)->a = (f32)(u32)alpha;
        ((ShdQuadVertex *)vertex)->q = reciprocalDepth;
        vertexIndex += 1;
    }
    D_00887300[0](1, 0);
    if ((blend != 0) && ((alpha & 0xFF) == 0xFF)) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](5, &vertices[0], 4);
    if ((blend != 0) && ((alpha & 0xFF) == 0xFF)) {
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
// Intent: Draw a ten-vertex rectangle outline rotated by the angle [inferred]
// FUN_00365AC0
void shdDrawRectOutline(Vec2f position, f32 depth, s32 color, f32 angle, f32 width, f32 height, s32 mode) {
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
    camera = ((u8 *)(u32)kwlnGetCamera());
    reciprocalDepth = 1.0f / ((MdlEffectCamera *)camera)->nearPlane;
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
        kAssertFail(D_0064E2F8, 571);
    }
    return count;
}

// Intent: Draw a radial fan of up to 100 segments from the centre colour to the edge colour [inferred]
/* measured: the packed-position byte read matches; using position.y changes instructions. */
// FUN_00365F00
void shdDrawRadialFan(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
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
    reciprocal = 1.0f / ((MdlEffectCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
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
