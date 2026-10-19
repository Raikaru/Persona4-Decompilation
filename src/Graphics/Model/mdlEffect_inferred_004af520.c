#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern u8 *mdlEffectCreateGridForRecord(u8 *instance);
extern u8 D_0071413C[];
extern void PrimAppendNode();
extern void ObjectParticleUpdateRecords();
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];



extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 instance, s32 value, s32 count, s32 flags,
                          void *data, s32 options);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004af520-004af580 */

extern s32 mdlEffectProjectBillboardQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildRectQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildOffsetQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildDirectRectQuad(u8 *instance, u8 *value);
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: close loop-invariant hoisting after mdlEffectCreateGridForRecord. */
#pragma push
#pragma tailcall off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
/* measured: loop-invariant conversion preloads for func_004a7e30. */
/* measured: close the loop-invariant bracket after func_004a7e30. */
/* measured: loop-invariant conversion preloads for func_004a8250. */
/* measured: close loop-invariant conversion scope for func_004a8250. */
/* measured: loop-invariant conversion preloads for func_004a8440. */
/* measured: close loop-invariant conversion scope for func_004a8440. */
/* measured: loop-invariant conversion preloads for func_004a86c0. */
/* measured: close loop-invariant conversion scope for func_004a86c0. */
/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
#pragma pop
// Clears the node at +0x64 of the record at +0x58 and appends it to the table that TnGetOffset1C selects from the inner kind at +0x54.
// FUN_004AF520
void ObjectParticleAppendNode(u8 *instance) {
    u8 *emitter;
    u8 *inner;
    emitter = ((ObjectParticleInstance *)instance)->list;
    if (emitter != NULL) {
        inner = ((MdlEffectEmitter *)emitter)->parameters;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x64) = 0;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x68) = 0;
        PrimAppendNode(TnGetOffset1C(((EffTrackPathParameters *)inner)->unk54), instance + 0x64);
    }
}

// Runs ObjectParticleUpdateRecords, then clears and appends the node at +0x64 of the record at +0x58, as ObjectParticleAppendNode does.
// FUN_004AF580
void ObjectParticleUpdateAndAppendNode(u8 *instance) {
    u8 *emitter;
    u8 *inner;
    ObjectParticleUpdateRecords();
    emitter = ((ObjectParticleInstance *)instance)->list;
    if (emitter != NULL) {
        inner = ((MdlEffectEmitter *)emitter)->parameters;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x64) = 0;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x68) = 0;
        PrimAppendNode(TnGetOffset1C(((EffTrackPathParameters *)inner)->unk54), instance + 0x64);
    }
}

