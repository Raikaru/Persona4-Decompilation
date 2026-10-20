#include "member_access.h"
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
extern PolygonWindColor iGpffffbb64;
extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
extern u8 D_0071413C[];
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern void kAssertFail(u8 *file, s32 line);
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



extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void memset(void *dst, s32 value, u32 size);
extern void func_003c22f0();
extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a6c00-004a6c00 */

/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: testing loop-invariant hoisting for the retail preheader. */
/* measured: removal, named-integer for, and do/while probes mismatch (11-word removal residual from the -1 preheader). */
#pragma opt_loop_invariants on
// Creates a grid-backed object from the 0x40-byte record at parameters, copied to +0x18: allocates the 0x5C object, builds a multi-part grid geometry at +0x58, and sets 0x34 sixteen-byte slots of its table to -1.
// FUN_004A6C00
u8 *mdlEffectCreateGridForRecord(u8 *parameters)
{
    u16 *model;
    u16 *createdGeometry;
    u16 *geometryWord;
    u32 colorGroup;
    u8 *geometry;
    u8 *instance;
    u8 *colors;

    chkmemAllocSiteTag(D_00714350, 0x78);
    instance = (u8 *)jtbl_008873E8[0](0x5C, 0x40000);
    if (instance == NULL) {
        kAssertFail(D_00714350, 0x79);
    }
    memset(instance, 0, 0x5C);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(instance) : "memory");
    memcpy(instance + 0x18, parameters, 0x40);
    createdGeometry = GeometryCreateTableGridMultiPart(0xD, 4, 2, 4, D_00713408, 0x4C);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    MEMBER(u16 *, instance, MdlEffectGridInstance, geometry) = createdGeometry;
    *createdGeometry = *createdGeometry & 0xFFFE;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    geometryWord = MEMBER(u16 *, instance, MdlEffectGridInstance, geometry);
    *geometryWord = *geometryWord & 0xFFFB;
    RpGeometryLock(
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        ((RpAtomic *)((EffGeometryBlock *)MEMBER(u8 *, instance, MdlEffectGridInstance, geometry))->atomic)->geometry, 8);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    colors = (u8 *)((RpGeometry *)(u8 *)((RpAtomic *)((EffGeometryBlock *)MEMBER(u8 *, instance, MdlEffectGridInstance, geometry))->atomic)->geometry)->colors;
    geometryWord = (u16 *)(s32)-1;
    colorGroup = 0;
    goto loop_004a6c00_check;
loop_004a6c00_body:
    ((s32 *)colors)[0] = (s32)geometryWord;
    ((s32 *)colors)[1] = (s32)geometryWord;
    ((s32 *)colors)[2] = (s32)geometryWord;
    ((s32 *)colors)[3] = (s32)geometryWord;
    colors += 0x10;
    colorGroup += 1;
loop_004a6c00_check:
    if (colorGroup < 0x34U) {
        goto loop_004a6c00_body;
    }
    model = (u16 *)((MdlEffectGridInstance *)instance)->geometry;
    geometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)(u8 *)model)->atomic)->geometry;
    func_003c22f0(geometry, colors);
    if ((*model & 4) != 0) {
        ((RpGeometry *)geometry)->lockedSinceLastInst = ((RpGeometry *)geometry)->lockedSinceLastInst | 1;
    }
    return instance;
}

