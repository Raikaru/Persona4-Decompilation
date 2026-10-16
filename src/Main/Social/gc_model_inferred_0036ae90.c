#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
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






extern u8 *func_00457120(void);
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

static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
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
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

/* Source unit: src/promoted/code1_0036.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0036.c; members 0036ae90-0036ae90 */

struct PanelMatrix;
struct PanelTransform;
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
/* measured: retail hoists the 0.5f loop constants out of the corner loops. */
#pragma push
#pragma pop
/* measured: nd 87 -> 0. opt_loop_invariants on hoists the stackE0.y/.z loads
   out of the grid loops after `outer = 0`, as retail does. */
#pragma push
/* measured: func_0036ae90 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0036AE90
void func_0036ae90(u8 *arg0, u8 *arg1) {
    extern u8 *func_003e9700(u8 *frame);
    extern struct RwMatrixTag *func_003e0f80(void);
    extern void pscBuildModelMatrix(struct PanelMatrix *output,
                              const struct PanelTransform *transform);
    extern RwV3d *func_003e42a0(RwV3d *out, const RwV3d *in,
                                const struct RwMatrixTag *matrix);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern struct RwMatrixTag *RwMatrixRotate(struct RwMatrixTag *matrix,
                                              const RwV3d *axis, f32 angle,
                                              s32 combineOp);
    extern void func_003e0f40(struct RwMatrixTag *matrix);
    extern RwV3d D_0064E490;
    extern RwV3d D_0064E4A0;
    extern RwV3d D_0064E4B0;
    extern RwV3d D_0064E4C0;
    RwV3d stack130;
    RwV3d stack120;
    RwV3d stack110;
    RwV3d stack100;
    RwV3d stackF0;
    RwV3d stackE0;
    RwV3d stackD0;
    RwV3d stackC0;
    RwV3d stackB0;
    s32 inner;
    s32 outer;
    s32 limit;
    s32 even;
    u8 *dst;
    u8 *mtx;
    u8 *view;
    u8 *rgba;
    struct RwMatrixTag *cam;
    f32 dot;
    f32 fx;
    f32 dot2;
    f32 pow6;
    f32 dot3;
    f32 clamped;
    f32 combined;
    u8 abyte;
    u8 shade;
    f32 af;
    f32 scaled;

    stack130 = D_0064E490;
    view = func_00457120();
    mtx = func_003e9700(*(u8 **)(view + 4)) + 0x30;
    stackD0 = D_0064E4A0;
    stackC0 = D_0064E4B0;
    stackB0 = D_0064E4C0;
    cam = func_003e0f80();
    pscBuildModelMatrix((struct PanelMatrix *)cam,
                  (const struct PanelTransform *)arg1);
    func_003e4320(&stackD0, &stackD0, cam);
    stackE0 = *(RwV3d *)(arg0 + 0x994);
    if (*(u8 **)(arg1 + 0x38) != NULL) {
        func_003e42a0(&stack100, (RwV3d *)(arg1 + 0x20),
                      (struct RwMatrixTag *)func_003e9700(*(u8 **)(arg1 + 0x38)));
    } else {
        stack100 = *(RwV3d *)(arg1 + 0x20);
    }
    dot = stackD0.x * (*(f32 *)mtx - stack100.x) + stackD0.y * (*(f32 *)(mtx + 4) - stack100.y) + stackD0.z * (*(f32 *)(mtx + 8) - stack100.z);
    *(s32 *)arg0 &= ~1;
    if (dot < 0.0f) {
        RwMatrixRotate(cam, &stackC0, 180.0f, 1);
        *(s32 *)arg0 |= 1;
    }
    rgba = arg1 + 0x40;
    stack100.x = 0.0f;
    stack100.y = 0.0f;
    stack100.z = 100.0f;
    func_003e42a0(&stack100, &stack100, cam);
    func_003e4320(&stackB0, &stack130, cam);
    RwV3dNormalize(&stackB0, &stackB0);
    {
        dst = arg0 + 4;
        for (outer = 0; outer < 9; outer++) {
            even = ~outer & 1;
            if (even != 0) {
                limit = 8;
            } else {
                limit = 7;
            }
            for (inner = 0; inner < limit; inner++, dst += 0x24) {
                if (even != 0) {
                    if (inner == 0) {
                        fx = 0.0f;
                    } else if (inner == limit - 1) {
                        fx = 6.0f;
                    } else {
                        fx = 0.5f + (f32)(inner - 1);
                    }
                } else {
                    fx = (f32)inner;
                }
                stack100.x = fx - 3.0f;
                stack100.y = 7.68f * ((f32)outer / 8.0f - 0.5f);
                stack100.z = 0.0f;
                func_003e42a0(&stackF0, &stack100, cam);
                stack110.x = stackF0.x - *(f32 *)mtx;
                stack110.y = stackF0.y - *(f32 *)(mtx + 4);
                stack110.z = stackF0.z - *(f32 *)(mtx + 8);
                RwV3dNormalize(&stack110, &stack110);
                stack120.x = stackF0.x - stackE0.x;
                stack120.y = stackF0.y - stackE0.y;
                stack120.z = stackF0.z - stackE0.z;
                RwV3dNormalize(&stack120, &stack120);
                dot2 = stack110.x * stack130.x + stack110.y * stack130.y + stack110.z * stack130.z;
                {
                    f32 t2 = stack130.x * dot2;
                    f32 t3 = stack130.y * dot2;
                    f32 t1 = stack130.z * dot2;
                    f32 u1 = t1 + (t1 - stack110.z);
                    f32 u2 = t2 + (t2 - stack110.x);
                    f32 u3 = t3 + (t3 - stack110.y);
                    f32 v1 = stack120.x * u2 + stack120.y * u3 + stack120.z * u1;
                    if (v1 <= 0.0f) {
                        pow6 = 0.0f;
                    } else {
                        pow6 = v1 * v1 * v1 * v1 * v1 * v1;
                    }
                }
                stack120.x = stackE0.x - stackF0.x;
                stack120.y = stackE0.y - stackF0.y;
                stack120.z = stackE0.z - stackF0.z;
                RwV3dNormalize(&stack120, &stack120);
                dot3 = stack120.x * stackB0.x + stack120.y * stackB0.y + stack120.z * stackB0.z;
                if (dot3 <= 0.0f) {
                    clamped = 0.0f;
                } else {
                    clamped = dot3;
                }
                combined = pow6 * *(f32 *)(arg0 + 0x9A0) + clamped * *(f32 *)(arg0 + 0x9A4);
                if (!(combined <= 1.0f)) {
                    combined = 1.0f;
                }
                abyte = rgba[3];
                af = (f32)(u32)abyte;
                scaled = af * combined;
                shade = scaled;
                dst[0xC] = shade;
                dst[0xD] = shade;
                dst[0xE] = shade;
                dst[0xF] = shade;
            }
        }
    }
    func_003e0f40(cam);
}

