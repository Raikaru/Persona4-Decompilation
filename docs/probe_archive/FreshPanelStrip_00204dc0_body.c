/* Fresh rotated panel strip candidate: func_00204dc0.
 * Owner src/promoted/code1_0020.c. PRODUCTION REMAINS ASM.
 * Initial source856/944 bytes,nd660,18 object relocations. Preferred scoped
 * opt_propagation off source864/944 bytes,nd628,18 relocations:76 executable bytes
 * remain uncovered,plus four retail alignment bytes. Adding loop-invariant
 * optimization ties; disabling common subexpressions as well produces1216/nd1005.
 * No exact-match or behavioral-smoke claim is made for this candidate.
 * 
 * Actual inputs are index in a0,extend flag in a1,and four floats in f12..f15:
 * positionX,positionY,depth,angle. Index is sign-truncated to16 bits at use.
 * Four actual64-byte immediate vertex records form the first opaque27-gray strip;
 * the optional extension rewrites XY and colors while retaining depth/reciprocal
 * from the first pass, including any mutations made by the drawing callbacks.
 * Texture is disabled before geometry. Preserve the first draw's00364C50/00364C70
 * bracket and optional render-state8 enable/disable pair. Repeated zero terms,
 * FP accumulation and coordinate sharing do not yet reproduce retail code.
 * No invented inputs,synthetic stack padding,inline assembly or register binding
 * is used. Declarations below supplement the current owner; existing production
 * callers remain unchanged.
 */

extern f32 fGpffff836c;
extern void func_00364c50(void);
extern void func_00364c70(void);

// FUN_00204DC0
#pragma push
#pragma opt_propagation off
void func_00204dc0(s32 index, f32 x, f32 y, f32 depth, f32 angle, s32 extend)
{
    f32 vertices[4][16];
    f32 reciprocal;
    f32 cosine;
    f32 sine;
    f32 width;
    f32 halfWidth;
    D_00887300[0](1, 0);
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    depth = D_008872F8[0] - depth;
    angle = fGpffff836c * angle;
    cosine = func_0044b610(angle);
    sine = func_0044b7b0(angle);
    width = 86.0f;
    x = 97.0f + x;
    y += (0.0f + 312.0f) + 15.0f * (f32)((s16)index - 3);
    halfWidth = width + 64.0f;
    vertices[0][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - 8.0f * sine;
    vertices[0][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + 8.0f * cosine;
    vertices[0][2] = depth;
    vertices[1][0] = (x + (0.0f - halfWidth) * cosine) - 8.0f * sine;
    vertices[1][1] = (y + (0.0f - halfWidth) * sine) + 8.0f * cosine;
    vertices[1][2] = depth;
    vertices[3][0] = (x + (0.0f - halfWidth) * cosine) - -8.0f * sine;
    vertices[3][1] = (y + (0.0f - halfWidth) * sine) + -8.0f * cosine;
    vertices[3][2] = depth;
    vertices[2][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - -8.0f * sine;
    vertices[2][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + -8.0f * cosine;
    vertices[2][2] = depth;
    vertices[0][8] = 27.0f;
    vertices[0][9] = 27.0f;
    vertices[0][10] = 27.0f;
    vertices[0][11] = 255.0f;
    vertices[1][8] = 27.0f;
    vertices[1][9] = 27.0f;
    vertices[1][10] = 27.0f;
    vertices[1][11] = 255.0f;
    vertices[2][8] = 27.0f;
    vertices[2][9] = 27.0f;
    vertices[2][10] = 27.0f;
    vertices[2][11] = 255.0f;
    vertices[3][8] = 27.0f;
    vertices[3][9] = 27.0f;
    vertices[3][10] = 27.0f;
    vertices[3][11] = 255.0f;
    vertices[0][6] = reciprocal;
    vertices[1][6] = reciprocal;
    vertices[2][6] = reciprocal;
    vertices[3][6] = reciprocal;
    func_00364c50();
    D_00887310[0](4, vertices, 4);
    func_00364c70();
    if (extend != 0) {
        D_00887300[0](8, 1);
        vertices[0][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - 0.0f * sine;
        vertices[0][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + 0.0f * cosine;
        vertices[1][0] = (0.0f + (x + (0.0f - halfWidth) * cosine)) - 0.0f * sine;
        vertices[1][1] = (0.0f + (y + (0.0f - halfWidth) * sine)) + 0.0f * cosine;
        vertices[3][0] = (x + (0.0f - halfWidth) * cosine) - -800.0f * sine;
        vertices[3][1] = (y + (0.0f - halfWidth) * sine) + -800.0f * cosine;
        vertices[2][0] = ((0.0f + x) + (0.0f + halfWidth) * cosine) - -800.0f * sine;
        vertices[2][1] = ((0.0f + y) + (0.0f + halfWidth) * sine) + -800.0f * cosine;
        vertices[0][8] = 27.0f;
        vertices[0][9] = 27.0f;
        vertices[0][10] = 27.0f;
        vertices[0][11] = 0.0f;
        vertices[1][8] = 27.0f;
        vertices[1][9] = 27.0f;
        vertices[1][10] = 27.0f;
        vertices[1][11] = 0.0f;
        vertices[2][8] = 27.0f;
        vertices[2][9] = 27.0f;
        vertices[2][10] = 27.0f;
        vertices[2][11] = 0.0f;
        vertices[3][8] = 27.0f;
        vertices[3][9] = 27.0f;
        vertices[3][10] = 27.0f;
        vertices[3][11] = 0.0f;
        D_00887310[0](4, vertices, 4);
        D_00887300[0](8, 0);
    }
}

#pragma pop
