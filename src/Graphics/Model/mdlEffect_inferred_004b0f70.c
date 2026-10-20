#include "mdl_effect_drawable_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern void DistortParticleProjectRecords();
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *instance, s32 value);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 instance, u32 value);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Source unit: src/promoted/code1_004b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004b.c; members 004b0f70-004b1030 */

// Projects the distort records with flag 0: the sky hook is not called, and the flag is passed to DistortParticleDrawSky.
// FUN_004B0F70
void DistortParticleProjectRecordsNoSky(void *object) {
    DistortParticleProjectRecords(object, 0);
}

// Projects the distort records with flag 1: calls the hook at D_00887300 with 1 first, and passes the flag to DistortParticleDrawSky.
// FUN_004B0FA0
void DistortParticleProjectRecordsSky(void *object) {
    DistortParticleProjectRecords(object, 1);
}

// Clears the node at +0x6C of the record at +0x5C and appends it to the table that TnGetOffset1C selects from the inner kind at +0x54.
// FUN_004B0FD0
void DistortParticleAppendNode(u8 *instance)
{
    u8 *node;
    u8 *inner;

    node = ((DistortParticleInstance *)instance)->list;
    if (node != NULL) {
        inner = ((MdlEffectEmitter *)node)->parameters;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x6C) = 0;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x70) = 0;
        PrimAppendNode(TnGetOffset1C(((EffTrackPathParameters *)inner)->unk54), instance + 0x6C);
    }
}

// Runs DistortParticleUpdateRecords, then clears and appends the node at +0x6C of the record at +0x5C, as DistortParticleAppendNode does.
// FUN_004B1030
void DistortParticleUpdateAndAppendNode(u8 *instance)
{
    u8 *node;
    u8 *inner;

    DistortParticleUpdateRecords();
    node = ((DistortParticleInstance *)instance)->list;
    if (node != NULL) {
        inner = ((MdlEffectEmitter *)node)->parameters;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x6C) = 0;
        /* Only zeroing is established for these embedded queue-link words; the shared owner keeps the node prefix opaque. */
        *(s32 *)(instance + 0x70) = 0;
        PrimAppendNode(TnGetOffset1C(((EffTrackPathParameters *)inner)->unk54), instance + 0x6C);
    }
}

