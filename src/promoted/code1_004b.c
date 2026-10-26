#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
#include "rw_raster_internal.h"
#include "rw_camera_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);
extern void mdlEffectDestroyWithNodes(u8 *effect);
extern void func_00485fe0();
extern void mdlEffectCommitTreeFrame(u8 *effect);
extern void func_00486400();
extern s32 func_00486060(u8 *);
extern void func_004860f0();
extern void func_00486180();

extern void DistortParticleProjectRecords();
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern void mdlEffectApplyShakeEnvelope(u8 *record, s32 elapsed);
extern void mdlEffectResetSequenceFrame(void);
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern u_long128 mdlEffectStoreQuadA(s32 instance, u32 *quadData);
extern u_long128 mdlEffectStoreQuadB(s32 instance, u32 *quadData);
extern void EffEmitterApplyScale(u16 *emitter, f32 scale);
extern void TnSetTableBase(void *table);
extern void mdlEffectFlushTreeFrame(void *effect);
extern void mdlEffectAdvanceAndDrawChildren(void *instance);
extern void func_004861f0(void *, f32 *);
extern void mdlEffectUpdateScreenSprite(u8 *instance);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;
extern void LineNovaUpdateCameraQuads(void);
extern void func_003efd20(u8 *, s32);
extern void func_003e9390(s32);
extern void func_003ec330(s32);
extern void RpSkyTexCacheRasterLock(s32, s32);
extern void func_003e8440(u8 *);
extern u8 *GeometryCloneBlock(s32 source);
extern void memcpy(void *, void *, s32);
extern void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source);
extern s32 mdlEffectShareTrackInstance(s32 source);
extern void mdlEffectReleaseTrackInstance(s32 instance);
extern void TlpRelease(s32 work);
extern s32 TlpAddRef(s32 work);

/* func_004bd628 through func_004bd6a0 are framed tail jumps that plain C cannot reproduce. */

extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern void mdlEffectGetPositionVec(u8 *object, u32 *output);
extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void initVariables(u8 *);
extern void func_00486330(u8 *, void *);
extern void effMiscEulerToQuatVU(f32 angleX, f32 angleY, f32 angleZ);
extern f32 iGpffff836c;
extern void mdlEffectGetOrientationVec(u8 *object, u32 *output);
extern void mdlEffectBuildBasisRows(void *output, void *orientation);
extern void effMiscMatrixToQuatVU(f32 *matrix);
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 arg0, u32 arg1);
extern void memset(void *, s32, s32);
extern void GeometryBlockSetTextureFromHandle(u8 *block, u16 *handle);
extern s32 mdlEffectCreateTrackInstance(u16 *source);
extern s32 TnSlotObject(u16 slotIndex);
extern void func_003c42b0(s32, s32);
extern s32 TlpCreate(u16 *desc);
extern void func_003e8110(u8 *camera);
extern s32 func_003e8120(u8 *camera);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern u8 *RpSkyGetDisplayBufferRaster(void);
extern u8 D_008872FC_abs[]; /* screen-space depth for immediate-mode vertices */
extern BtlShuffleRenderStateSet D_00887300[]; /* active render-state dispatch */
extern BtlShuffleRenderPrimitive D_00887310_abs[]; /* immediate-mode primitive dispatch */

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

extern void DistortParticleProjectRecords();

extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);

extern u32 mdlEffectGetPackedColorWord(void *object);

typedef signed __int128 s128;

extern void *mdlEffectCreateScreenSprite(void *opaqueSource);

/* Screen-space sibling of EffSpriteUpdate: packs the colour, then projects the four corners through
 * the camera depth range onto the 640x448 screen. */
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

/* Same 0x40-byte work allocation constructed by effCrossfade.c. */
typedef struct CrossfadeWork {
    u8 state;
    u8 pad01;
    u16 frameLimit;
    u16 frame;
    u8 pad06[2];
    s32 raster;
    u8 *camera;
    s32 nodeNext;
    s32 nodePrevious;
    void *advance;
    u8 pad1C[4];
    struct CrossfadeWork *owner;
    u8 pad24[0x1C];
} CrossfadeWork;

/* measured: propagation off keeps the cached D_00887300 base and the retail stack frame. */
// FUN_004B2780
/* measured: propagation off keeps the camera and callback-base values live the way retail does. */
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
    CrossfadeWork *work = (CrossfadeWork *)object;

    if (func_003e8120(((CrossfadeWork *)object)->camera) == 0) {
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
    reciprocalFarPlane = 1.0f / ((RwCamera *)(work->camera))->farPlane;
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
    func_003e8110(work->camera);
    return 1;
}
#pragma opt_propagation on

typedef signed __int128 s128;

typedef signed __int128 s128;

extern u8 *AfPackBindResource();
extern u8 *AfPackCreateInstance();
extern void AfPackStartSections();
extern void AfPackListAppend();

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

/* ACSFDR_Create requires 0x44 bytes; ACSFDR_FadeVol clears elapsedTicks
 * and ACSFDR_Process increments it once per active processing call. */
typedef struct AcsFader {
    u8 pad00[8];
    s32 elapsedTicks;
    u8 pad0C[0x44 - 0x0C];
} AcsFader;

/* Return the active-call counter, including the fade's start and end waits. */
// FUN_004BD750
/* measured: schedule on fills the return delay slot with the load, as retail does. */
#pragma schedule on
s32 acsfdrGetElapsedTicks(u8 *fader) {
    return ((AcsFader *)fader)->elapsedTicks;
}
/* measured: restores the unit setting after func_004bd750. */
#pragma schedule off
