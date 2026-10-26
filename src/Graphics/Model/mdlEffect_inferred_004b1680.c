#include "member_access.h"
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
extern void memcpy(void *sourceBytes, void *sequenceId, s32 firstValue);

/* func_004bd628, func_004bd640, func_004bd658, func_004bd670, func_004bd688 and func_004bd6a0 are
 * framed tail-jump wrappers that plain C cannot emit. */


extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void kAssertFail(void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 sourceBytes, u32 sequenceId);
extern void memset(void *sourceBytes, s32 sequenceId, s32 firstValue);
extern void GeometryBlockSetTextureFromHandle(u8 *block, u16 *handle);
extern s32 mdlEffectCreateTrackInstance(u16 *source);
extern s32 TnSlotObject(u16 slotIndex);
extern void func_003c42b0(s32 sourceBytes, s32 sequenceId);
extern s32 TlpCreate(u16 *desc);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Store the sequence request arguments, clear its phase and mark the sequence active. */
// FUN_004B1680
void mdlEffectSetSequenceRequest(s32 sequence, s16 sequenceId, s32 firstValue, s32 secondValue)
{
    D_00922DA0[0] = sequence;
    D_00922DA4[0] = sequenceId;
    D_00922DA8[0] = firstValue;
    D_00922DAC[0] = secondValue;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}

/* Allocate a 0xB0-byte screen sprite, copy its parameters and bind geometry and optional texture animation. */
// FUN_004B16C0
void *mdlEffectCreateScreenSprite(void *opaqueSource) {
    u8 *sourceBytes = opaqueSource;
    u16 *geometry;
    u16 *textureSource;
    u16 sourceKind;
    u8 *instance;
    u8 *parameters;
    u8 *colors;

    chkmemAllocSiteTag(&iGpffffb118, 0x1A);
    instance = (u8 *)jtbl_008873E8[0](0xB0, 0x40000);
    if (instance == NULL) {
        kAssertFail(&iGpffffb118, 0x1B);
    }
    memset(instance, 0, 0xB0);
    ((MdlEffectScreenSprite *)instance)->packedColor = -1;
    if (sourceBytes == NULL) {
        return instance;
    }
    ((MdlEffectScreenSprite *)instance)->id = ((EffSourceDescriptor *)sourceBytes)->id;
    parameters = mdlEffectResolveRelPtrA(sourceBytes);
    if (parameters == NULL) {
        kAssertFail(&iGpffffb118, 0x2C);
    }
    memcpy(instance + 0xC, parameters, 0x98);
    geometry = (u16 *)GeometryCreateTableGrid(1, 2, 4, D_00713408, 0x4C);
    MEMBER(u16 *, instance, MdlEffectScreenSprite, geometry) = geometry;
    *geometry = *geometry & 0xFFFB;
    colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)MEMBER(u8 *, instance, MdlEffectScreenSprite, geometry))->atomic)->geometry;
    colors = (u8 *)((RpGeometry *)colors)->colors;
    ((s32 *)colors)[0] = -1;
    ((s32 *)colors)[1] = -1;
    ((s32 *)colors)[2] = -1;
    ((s32 *)colors)[3] = -1;
    textureSource = mdlEffectResolveRelPtrB(sourceBytes);
    if (textureSource != NULL) {
        sourceKind = ((EffSourceDescriptor *)sourceBytes)->kind;
        switch (sourceKind) {
        case 1:
            GeometryBlockSetTextureFromHandle(((MdlEffectScreenSprite *)instance)->geometry, textureSource);
            break;
        case 2:
            ((MdlEffectScreenSprite *)instance)->tracks = mdlEffectCreateTrackInstance(textureSource);
            break;
        case 4:
            func_003c42b0((s32)((EffGeometryBlock *)((MdlEffectScreenSprite *)instance)->geometry)->material,
                          TnSlotObject(*textureSource));
            break;
        case 7:
            ((MdlEffectScreenSprite *)instance)->tlp = TlpCreate(textureSource);
            break;
        default:
            kAssertFail(&iGpffffb118, 0x5C);
            break;
        }
    }
    return instance;
}

