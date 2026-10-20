#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
#include "rw_types_internal.h"
#include "psc_model_internal.h"
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
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y,
                          u8 alphaSubtract, u8 red, u8 green, u8 blue,
                          f32 z, s32 setStates);
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
extern f32 iGpffff8040;
extern f32 fGpffff8198;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0036; members 0036b630-0036b630 */

extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
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
#pragma pop
// Intent: Copies a 3-vector into the panel's stored vector, which the tile builder reads [inferred]
// FUN_0036B630
void pscModelCopyVector(u8 *mesh, RwV3d *lightPosition)
{
    *(RwV3d *)&((PscTileMesh *)mesh)->lightPosition = *lightPosition;
}

