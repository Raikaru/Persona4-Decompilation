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
extern void kAssertFail(u8 *sourceBytes, s32 value);
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



extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void memset(void *dst, s32 value, u32 size);
extern u16 *GeometryCreateTableGridMultiPart(s32 sourceBytes, s32 value, s32 count, s32 flags,
                          void *data, s32 options);
extern void func_003c42b0(void *sourceBytes, s32 value);
extern s32 TnSlotObject(u16 sourceBytes);
extern s32 mdlEffectCreateTrackInstance(u16 *sourceBytes);
extern s32 TlpCreate(u16 *sourceBytes);
extern void GeometryBlockSetTextureFromHandle(u8 *sourceBytes, u16 *value);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a5bb0-004a5bb0 */

/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
// Allocates and zero-initialises a 0xD4-byte instance with -1 at +0x24 and 1.0 at +0x20. A NULL source returns that blank instance; otherwise it builds a geometry table, copies the 0x98-byte record from the resolved source, and dispatches on the kind at +0x1C.
// FUN_004A5BB0
void *mdlEffectCreateInstance(void *source)
{
    u8 *sourceBytes = (u8 *)source;
    u16 *textureSource;
    u16 sourceKind;
    u8 *instance;
    u8 *geometry;
    u8 *parameters;
    u8 *colors;

    chkmemAllocSiteTag(D_007141A0, 0x1C);
    instance = (u8 *)jtbl_008873E8[0](0xD4, 0x40000);
    if (instance == NULL) {
        kAssertFail(D_007141A0, 0x1D);
    }
    memset(instance, 0, 0xD4);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(instance) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(instance) : "memory");
    ((MdlEffectAnimatedSprite *)instance)->packedColor = -1;
    ((MdlEffectAnimatedSprite *)instance)->scale = 1.0f;
    if (sourceBytes == NULL) {
        return instance;
    }
    geometry = GeometryCreateTableGrid(1, 2, 4, D_00713408, 0x4C);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    *(u8 **)(instance + 0xC8) = geometry;
    colors = (u8 *)((RpGeometry *)(u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry)->colors;
    ((s32 *)colors)[0] = -1;
    ((s32 *)colors)[1] = -1;
    ((s32 *)colors)[2] = -1;
    ((s32 *)colors)[3] = -1;
    ((MdlEffectAnimatedSprite *)instance)->id = ((EffSourceDescriptor *)sourceBytes)->id;
    parameters = mdlEffectResolveRelPtrA(sourceBytes);
    if (parameters == NULL) {
        kAssertFail(D_007141A0, 0x47);
    }
    memcpy(instance + 0x30, parameters, 0x98);
    textureSource = mdlEffectResolveRelPtrB(sourceBytes);
    if (textureSource != NULL) {
        sourceKind = ((EffSourceDescriptor *)sourceBytes)->kind;
        switch (sourceKind) {
        case 1:
            GeometryBlockSetTextureFromHandle(((MdlEffectAnimatedSprite *)instance)->geometry, textureSource);
            break;
        case 2:
            ((MdlEffectAnimatedSprite *)instance)->tracks = mdlEffectCreateTrackInstance(textureSource);
            break;
        case 4:
            func_003c42b0(
                /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
                ((EffGeometryBlock *)*(u8 **)(instance + 0xC8))->material,
                TnSlotObject(*textureSource));
            break;
        case 7:
            ((MdlEffectAnimatedSprite *)instance)->tlp = TlpCreate(textureSource);
            break;
        default:
            kAssertFail(D_007141A0, 0x5D);
            break;
        }
    }
    return instance;
}

