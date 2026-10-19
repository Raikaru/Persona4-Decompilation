#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
#include "rw_raster_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 kwlnGetCamera(void);
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);
extern void mdlEffectDestroyWithNodes(u8 *model);
extern void func_00485fe0();
extern void mdlEffectCommitTreeFrame(u8 *object);
extern void func_00486400();
extern s32 func_00486060(u8 *);
extern void func_004860f0();
extern void func_00486180();

extern void DistortParticleProjectRecords();
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern void mdlEffectApplyShakeEnvelope(u8 *arg0, s32 arg1);
extern void mdlEffectResetSequenceFrame(void);
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
extern void EffEmitterApplyScale(u16 *emitter, f32 scale);
extern void TnSetTableBase(void *arg0);
extern void mdlEffectFlushTreeFrame(void *arg0);
extern void mdlEffectAdvanceAndDrawChildren(void *arg0);
extern void func_004861f0(void *arg0, f32 *arg1);
extern void mdlEffectUpdateScreenSprite(u8 *arg0);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;
extern void LineNovaUpdateCameraQuads(void);
extern void func_003efd20(u8 *arg0, s32 arg1);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void RpSkyTexCacheRasterLock(s32 arg0, s32 arg1);
extern void func_003e8440(u8 *arg0);
extern u8 *GeometryCloneBlock(s32 arg0);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern void mdlEffectScreenSpriteCopyResource(u8 *arg0, u8 *arg1);
extern s32 mdlEffectShareTrackInstance(s32 arg0);
extern void mdlEffectReleaseTrackInstance(s32 arg0);
extern void TlpRelease(s32 arg0);
extern s32 TlpAddRef(s32 arg0);

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */

extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern void mdlEffectGetPositionVec(u8 *arg0, u32 *arg1);
extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *arg0, s32 arg1);
extern void initVariables(u8 *arg0);
extern void func_00486330(u8 *arg0, void *arg1);
extern void effMiscEulerToQuatVU(f32 arg0, f32 arg1, f32 arg2);
extern f32 iGpffff836c;
extern void mdlEffectGetOrientationVec(u8 *arg0, u32 *arg1);
extern void mdlEffectBuildBasisRows(void *arg0, void *arg1);
extern void effMiscMatrixToQuatVU(f32 *arg0);
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void GeometryBlockSetTextureFromHandle(u8 *arg0, u16 *arg1);
extern s32 mdlEffectCreateTrackInstance(u16 *arg0);
extern s32 TnSlotObject(u16 arg0);
extern void func_003c42b0(s32 arg0, s32 arg1);
extern s32 TlpCreate(u16 *arg0);
extern void func_003e8110(u8 *arg0);
extern s32 func_003e8120(u8 *arg0);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern u8 *RpSkyGetDisplayBufferRaster(void);
extern u8 D_008872FC_abs[]; /* screen-space depth for immediate-mode vertices */
extern BtlShuffleRenderStateSet D_00887300[]; /* active render-state dispatch */
extern BtlShuffleRenderPrimitive D_00887310_abs[]; /* immediate-mode primitive dispatch */

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

extern void DistortParticleProjectRecords();

extern void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1);

extern u32 mdlEffectGetPackedColorWord(void *object);

typedef signed __int128 s128;

extern void *mdlEffectCreateScreenSprite(void *opaqueSource);

/* Screen-space sprite update, the EffSpriteUpdate sibling. It shares the COP2
 * colour pack (the asm writes the packed frame slot, retail reloads it) and
 * the frame-info struct, then projects the four corners through the camera's
 * depth range onto the 640x448 screen. */
typedef struct EffScreenSpriteFrame {
    f32 rect[4];
    u32 size[2];
    u16 corner[8];
} EffScreenSpriteFrame;

typedef struct EffScreenSpriteRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} EffScreenSpriteRGBA;

#pragma push
#pragma opt_loop_invariants on
#pragma pop
/* measured: opt_propagation off retains the cached D_00887300 base and retail frame. */
// Kept here so this multi-run bucket stays link-eligible (has_first_party); see tools/build.py eligible_c_objects.
/* Capture the display raster into the crossfade camera's 512x256 target.
 * Returns zero if camera begin-update fails, otherwise submits an opaque
 * triangle strip with UVs scaled from the 640x448 display and returns one. */
/* Camera accesses retain byte offsets: the proven CrossfadeWork.camera at +0xC
 * (effCrossfade.c) and SDK farPlane at +0x84 caused MWCC to cache the camera
 * member address, add an instruction, and swap saved registers when typed. */
// FUN_004B2780
#pragma opt_propagation off
s32 effCrossfadeCaptureDisplay(u8 *object) {
    BtlShuffleSkyVertex vertices[4];
    f32 textureWidth;
    f32 textureHeight;
    f32 reciprocalFarPlane;
    f32 screenDepth;
    BtlShuffleRenderStateSet *renderState;
    u8 *textureRaster;
    u8 *displayRaster;

    if (func_003e8120(*(u8 **)(object + 0xC)) == 0) {
        return 0;
    }
    displayRaster = RpSkyGetDisplayBufferRaster();
    textureRaster = displayRaster;
    textureWidth = 640.0f / (f32)((RwRaster *)displayRaster)->width;
    textureHeight = 448.0f / (f32)((RwRaster *)displayRaster)->height;
    /* Retain the platform-specific packed Sky2 render-state values for capture. */
    RpSkyRenderStateSet(2, (void *)0x2024);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    renderState = D_00887300;
    renderState[0](rwRENDERSTATEFOGENABLE, (void *)0);
    renderState[0](rwRENDERSTATEZTESTENABLE, (void *)0);
    renderState[0](rwRENDERSTATEZWRITEENABLE, (void *)0);
    renderState[0](rwRENDERSTATETEXTUREFILTER, (void *)2);
    renderState[0](rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
    renderState[0](rwRENDERSTATETEXTURERASTER, (void *)(u32)textureRaster);
    renderState[0](rwRENDERSTATETEXTUREADDRESSU, (void *)3);
    renderState[0](rwRENDERSTATETEXTUREADDRESSV, (void *)3);
    screenDepth = *(f32 *)D_008872FC_abs;
    reciprocalFarPlane = 1.0f / *(f32 *)(*(u8 **)(object + 0xC) + 0x84);
    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[0].u.els.scrVertex.z = screenDepth;
    vertices[0].u.els.color.r = 255.0f;
    vertices[0].u.els.color.g = 255.0f;
    vertices[0].u.els.color.b = 255.0f;
    vertices[0].u.els.color.a = 255.0f;
    vertices[0].u.els.recipZ = reciprocalFarPlane;
    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.scrVertex.x = 0.0f;
    vertices[1].u.els.scrVertex.y = 256.0f;
    vertices[1].u.els.scrVertex.z = screenDepth;
    vertices[1].u.els.color.r = 255.0f;
    vertices[1].u.els.color.g = 255.0f;
    vertices[1].u.els.color.b = 255.0f;
    vertices[1].u.els.color.a = 255.0f;
    vertices[1].u.els.recipZ = reciprocalFarPlane;
    vertices[1].u.els.u = 0.0f;
    vertices[1].u.els.v = textureHeight;
    vertices[2].u.els.scrVertex.x = 512.0f;
    vertices[2].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.z = screenDepth;
    vertices[2].u.els.color.r = 255.0f;
    vertices[2].u.els.color.g = 255.0f;
    vertices[2].u.els.color.b = 255.0f;
    vertices[2].u.els.color.a = 255.0f;
    vertices[2].u.els.recipZ = reciprocalFarPlane;
    vertices[2].u.els.u = textureWidth;
    vertices[2].u.els.v = 0.0f;
    vertices[3].u.els.scrVertex.x = 512.0f;
    vertices[3].u.els.scrVertex.y = 256.0f;
    vertices[3].u.els.scrVertex.z = screenDepth;
    vertices[3].u.els.color.r = 255.0f;
    vertices[3].u.els.color.g = 255.0f;
    vertices[3].u.els.color.b = 255.0f;
    vertices[3].u.els.color.a = 255.0f;
    vertices[3].u.els.recipZ = reciprocalFarPlane;
    vertices[3].u.els.u = textureWidth;
    vertices[3].u.els.v = textureHeight;
    D_00887310_abs[0](rwPRIMTYPETRISTRIP, vertices, 4);
    renderState[0](rwRENDERSTATETEXTURERASTER, (void *)0);
    func_003e8110(*(u8 **)(object + 0xC));
    return 1;
}
#pragma opt_propagation on
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma pop

typedef signed __int128 s128;

typedef signed __int128 s128;

extern u8 *AfPackBindResource();
extern u8 *AfPackCreateInstance();
extern void AfPackStartSections();
extern void AfPackListAppend();

#pragma opt_propagation off
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
} Code1_004bBccf0Temp;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Code1_004bBddVec4;
// Archived C body: build/WBHygiene_func_004bd6b8_archive.txt; no current park body remains.
// FUN_004BD6B8
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd6b8);

// FUN_004BD720
INCLUDE_ASM("asm/nonmatchings/code1_004b", func_004bd720);
// FUN_004BD750
/* measured: schedule on fills func_004bd750's retail jr delay-slot load. */
#pragma schedule on
s32 func_004bd750(u8 *arg0) {
    return *(s32 *)(arg0 + 8);
}
/* measured: close the schedule bracket around func_004bd750. */
#pragma schedule off
