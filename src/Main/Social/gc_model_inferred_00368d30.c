#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
#include "rw_types_internal.h"
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
typedef struct {
    f32 x;
    f32 y;
} PairF32;
typedef union {
    s64 raw;
    PairF32 f;
} PairBits;
typedef struct PersonaWork PersonaWork;






extern f32 iGpffff84a4;
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

extern f32 cosf(f32 arg0);
static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
extern void sflDataInitPanel(void);
extern void pscLightInitQuad(u8 *arg0);
extern f32 fGpffff8390;
extern f32 fGpffff8394;
extern u16 D_008C024E[];
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0;
    f32 u;
    f32 v;
    f32 w;
    f32 pad1;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 pad2[4];
} P4Vertex66C70;
typedef struct {
    s32 matrix[16];
    P4Vertex66C70 vertices[4];
    s32 config[8];
    u8 local[0x30];
} P4DrawFrame66C70;
typedef void (*P4RenderState66C70)(s32 state, s32 value);
extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src,
                           const struct RwMatrixTag *matrix);
extern f32 sinf(f32 arg0);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0036; members 00368d30-00368e80 */

extern void pscModelBuildTileVertices(u8 *arg0, u8 *arg1);
/* 780/784 bytes; nine resolved relocations; four zero alignment bytes.
 * Keep the angle and shared scale local to each primitive call. */
#pragma push
#pragma pop
/* measured: opt_common_subs off keeps the raw alpha argument in $s1 and re-masks it at each of
   its two uses (color entry, 0xFF - alpha at the sprite call) as retail does; with CSE on b210
   masks once into $s0 (nd 78). */
/* measured: nd 9 -> 0. opt_loop_invariants on hoists the digit loop's 16.0f and 10
   ahead of the entry branch. Alpha: `n = arg1 & 0xFF; arg1 = 0xFF - n;` through the
   loop counter's register puts the andi before the li (fresh local or one expression: nd 3). */
/* measured: closes the loop-invariant bracket; the file default is off. */
// Intent: Initialises a shuffle-card panel model in mode 3: its sub-panel, light quad, corner positions, colours and timing constants [inferred]
// FUN_00368D30
void pscModelInitPanel(u8 *arg0)
{
    RwV3d p1;
    RwV3d p2;
    RwV3d p3;
    RwV3d p4;
    u8 color;

    sflDataInitPanel();
    *(s32 *)(arg0 + 4) = 3;
    pscLightInitQuad(arg0 + 0xE0);
    p1.x = 3.0f;
    p1.y = fGpffff8390;
    p1.z = 0.0f;
    *(RwV3d *)(arg0 + 0x170) = p1;
    p2.x = -3.0f;
    p2.y = p1.y;
    p2.z = 0.0f;
    *(RwV3d *)(arg0 + 0x194) = p2;
    p3.x = -3.0f;
    p3.y = fGpffff8394;
    p3.z = 0.0f;
    *(RwV3d *)(arg0 + 0x1B8) = p3;
    p4.x = 3.0f;
    p4.y = p3.y;
    p4.z = 0.0f;
    *(RwV3d *)(arg0 + 0x1DC) = p4;
    color = 0xFF;
    *(u8 *)(arg0 + 0x17C) = color;
    *(u8 *)(arg0 + 0x17D) = color;
    *(u8 *)(arg0 + 0x17E) = color;
    *(u8 *)(arg0 + 0x17F) = color;
    *(u8 *)(arg0 + 0x1A0) = color;
    *(u8 *)(arg0 + 0x1A1) = color;
    *(u8 *)(arg0 + 0x1A2) = color;
    *(u8 *)(arg0 + 0x1A3) = color;
    *(u8 *)(arg0 + 0x1C4) = color;
    *(u8 *)(arg0 + 0x1C5) = color;
    *(u8 *)(arg0 + 0x1C6) = color;
    *(u8 *)(arg0 + 0x1C7) = color;
    *(u8 *)(arg0 + 0x1E8) = color;
    *(u8 *)(arg0 + 0x1E9) = color;
    *(u8 *)(arg0 + 0x1EA) = color;
    *(u8 *)(arg0 + 0x1EB) = color;
    *(u32 *)(arg0 + 0x18C) = 0x3F7E0000;
    *(u32 *)(arg0 + 0x1B0) = 0;
    *(u32 *)(arg0 + 0x1D4) = 0;
    *(u32 *)(arg0 + 0x1F8) = 0x3F7E0000;
    *(u32 *)(arg0 + 0x190) = 0x3C000000;
    *(u32 *)(arg0 + 0x1B4) = 0x3C000000;
    *(u32 *)(arg0 + 0x1D8) = 0x3F230000;
    *(u32 *)(arg0 + 0x1FC) = 0x3F230000;
}

/* measured: retail hoists the 0.5f loop constants out of the corner loops. */
#pragma push
/* measured: func_00368e80 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: Advances a panel's animation timer and phase values for its mode, then rebuilds its tile vertices [inferred]
// FUN_00368E80
void pscModelStepAnimation(u8 *arg0)
{
    extern f32 D_007612D0;
    extern f32 fGpffff838c;
    extern void pscModelBuildTileVertices(u8 *arg0, u8 *arg1);
    u8 *base;
    s32 mode;
    f32 ftmp;
    f32 frac3;
    f32 frac16;
    f32 frac4;
    f32 frac2;
    f32 t;
    f32 u;
    f32 acc;
    f32 divv;
    f32 f0v;
    f32 f1v;
    f32 angle;
    f32 c03;
    s32 i;
    s32 j;
    s32 k;
    f32 stack[8];

    base = arg0;
    *(f32 *)(base + 0x3C) += iGpffff8040;
    mode = *(s32 *)(base + 4);
    switch (mode) {
    case 0:
    ftmp = *(f32 *)(base + 0x3C) / 3.0f;
    frac3 = ftmp - (f32)(s32)ftmp;
    *(f32 *)(base + 0x2B8) = frac3;
    *(f32 *)(base + 0x2DC) = frac3;
    *(f32 *)(base + 0x300) = 1.0f + frac3;
    *(f32 *)(base + 0x324) = 1.0f + frac3;
    ftmp = *(f32 *)(base + 0x3C) / 16.0f;
    frac16 = ftmp - (f32)(s32)ftmp;
    *(f32 *)(base + 0x348) = frac16;
    *(f32 *)(base + 0x36C) = frac16;
    *(f32 *)(base + 0x390) = 1.0f + frac16;
    *(f32 *)(base + 0x3B4) = 1.0f + frac16;
    ftmp = *(f32 *)(base + 0x3C) / 4.0f;
    frac4 = ftmp - (f32)(s32)ftmp;
    if (frac4 < 0.5f) {
        c03 = fGpffff8198;
        *(f32 *)(base + 0x5FC) = c03 + ((c03 * frac4) / 0.5f);
    } else {
        t = (frac4 - 0.5f) / 0.5f;
        u = 1.0f - t;
        c03 = fGpffff8198;
        acc = c03 + c03 * u;
        *(f32 *)(base + 0x5FC) = acc;
    }
    ftmp = *(f32 *)(base + 0x3C) / 2.0f;
    frac2 = ftmp - (f32)(s32)ftmp;
    if (frac2 < 0.5f) {
        *(f32 *)(base + 0x5F8) = (0.5f * frac2) / 0.5f;
    } else {
        *(f32 *)(base + 0x5F8) = 0.5f * (1.0f - ((frac2 - 0.5f) / 0.5f));
    }
    acc = 100.0f + 20.0f * frac2;
    divv = acc / 100.0f;
    f1v = 0.5f + (0.38671875f / divv);
    *(f32 *)(base + 0x4F4) = f1v;
    f0v = 0.5f - (0.38671875f / divv);
    *(f32 *)(base + 0x518) = f0v;
    *(f32 *)(base + 0x53C) = f0v;
    *(f32 *)(base + 0x560) = f1v;
    f0v = 0.5f - (0.41015625f / divv);
    *(f32 *)(base + 0x4F8) = f0v;
    *(f32 *)(base + 0x51C) = f0v;
    f0v = 0.5f + (0.41015625f / divv);
    *(f32 *)(base + 0x540) = f0v;
    *(f32 *)(base + 0x564) = f0v;
        break;
    case 1:
    ftmp = *(f32 *)(base + 0x3C) / 2.0f;
    frac2 = ftmp - (f32)(s32)ftmp;
    if (frac2 < 0.5f) {
        *(f32 *)(base + 0x32C) = (fGpffff838c * frac2) / 0.5f;
    } else {
        t = (frac2 - 0.5f) / 0.5f;
        u = 1.0f - t;
        *(f32 *)(base + 0x32C) = fGpffff838c * u;
    }
    acc = 70.0f + 20.0f * frac2;
    divv = acc / 100.0f;
    f1v = 0.5f + (0.38671875f / divv);
    *(f32 *)(base + 0x2B4) = f1v;
    f0v = 0.5f - (0.38671875f / divv);
    *(f32 *)(base + 0x2D8) = f0v;
    *(f32 *)(base + 0x2FC) = f0v;
    *(f32 *)(base + 0x320) = f1v;
    f0v = 0.5f - (0.41015625f / divv);
    *(f32 *)(base + 0x2B8) = f0v;
    *(f32 *)(base + 0x2DC) = f0v;
    f0v = 0.5f + (0.41015625f / divv);
    *(f32 *)(base + 0x300) = f0v;
    *(f32 *)(base + 0x324) = f0v;
        break;
    }
    if (((*(s32 *)base) & 2) != 0) {
        switch (*(s32 *)(base + 4)) {
        case 0: {
            f32 *pa;
            f32 *pb;
            f32 y;
            f32 x;
            f32 nx;
            f32 ny;
            stack[0] = 1.0f;
            stack[1] = 1.0f;
            stack[2] = 0.0f;
            stack[3] = 1.0f;
            stack[4] = 0.0f;
            stack[5] = 0.0f;
            stack[6] = 1.0f;
            stack[7] = 0.0f;
            angle = D_007612D0 * (*(f32 *)(base + 0x3C) / 4.0f);
            for (i = 0; i < 4; i++) {
                pa = &stack[i * 2];
                pa[0] -= 0.5f;
                pa[1] -= 0.5f;
            }
            for (j = 0; j < 4; j++) {
                pa = &stack[j * 2];
                pb = pa + 1;
                y = pb[0];
                x = pa[0];
                nx = x * cosf(angle) - y * sinf(angle);
                ny = x * sinf(angle) + y * cosf(angle);
                pa[0] = nx;
                pb[0] = ny;
            }
            for (k = 0; k < 4; k++) {
                pa = &stack[k * 2];
                pa[0] += 0.5f;
                pa[1] += 0.5f;
            }
            *(f32 *)(base + 0x584) = stack[0];
            *(f32 *)(base + 0x588) = stack[1];
            *(f32 *)(base + 0x5A8) = stack[2];
            *(f32 *)(base + 0x5AC) = stack[3];
            *(f32 *)(base + 0x5CC) = stack[4];
            *(f32 *)(base + 0x5D0) = stack[5];
            *(f32 *)(base + 0x5F0) = stack[6];
            *(f32 *)(base + 0x5F4) = stack[7];
            break;
        }
        }
    }
    if (((*(s32 *)base) & 1) != 0) {
        *(s32 *)(base + 0x44) += 0x10000;
        switch (*(s32 *)(base + 0x48)) {
        case 0:
            if ((u32)*(s32 *)(base + 0x44) >= 0x1E0000U) {
                *(s32 *)base &= ~1;
            }
            break;
        case 1:
            break;
        }
    }
    if (((*(s32 *)base) & 8) != 0) {
        pscModelBuildTileVertices(*(u8 **)(base + 0xDC), base);
    }
}

