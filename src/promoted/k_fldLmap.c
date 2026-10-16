#include "mt_scene_internal.h"
#include "field_transition_internal.h"
/* Original translation unit k_fldLmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

extern void (*jtbl_008873EC[])(void *);
typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void kAssertFail(u8 *file, s32 line);
extern void func_00440b68();
extern void sprintf(u8 *dst, u8 *src);
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void H_Cdvd_Destroy(u8 *ptr);
extern s32 H_Cdvd_IsFileLoaded(u8 *ptr);
extern s32 func_00455f70(u8 *param, s32 *out);
extern s32 func_0046a750(s32 param);
extern void sdkSpriteRelease(void *ptr);

extern void func_003e0f40(u8 *param);
extern void fieldSceneUnload();
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern u8 *PrimAllocQueueNode();
extern void func_00460ac0(void *param, u8 *work);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 RwV3dNormalize(f32 *param, f32 *out);
extern u8 *mdlGetMatrix(s32 param);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 *func_00457120();
extern void K_ClumpLookAtBasis(u8 *param, u8 *src, u8 *dst, s32 mode);
extern f32 sinf(f32 param);
extern f32 cosf(f32 param);
extern s64 datGetDateIndex();
extern s32 datGetTimeSlot();
extern s64 calGetDayEntryByPhase(s64 param, s32 param2);
extern s32 datGetFlag(s32 id);
extern u8 *func_003e0f80();
extern void fieldSceneLoad(s32 a, s32 b);
extern void func_00144ed0(s64 param);
extern s32 fieldSceneLoadStep();
extern u8 *MT_Scene_GetCameraResFirst();
extern f32 MT_Scene_GetCameraFov();
extern s32 sndRequestAreaTrack();
extern void sndPlayAreaCue();
extern void func_00122640(s32 a, s32 b);
extern s32 fadeStatus();
extern void func_00122520(s32 a, s32 b);
extern s32 kwlnTaskIsLinked(u8 *param);
extern u8 *func_0029db50(s32 a, s32 b, s32 c, s32 d);
extern void func_003e9cb0(s32 param, u8 *src, s32 mode);
extern void K_View_SetFov(u8 *param, f32 value);
extern void func_00189600(u8 *param, s32 a, s32 b, f32 value);
void FldLmapSkyState71009(void);
void FldLmapSkyState7100D(void);
extern u8 D_005F1EF8[];
extern u8 D_005F1FB8[];
extern u8 D_005F1FA8[];
extern u8 D_005F1FD0[];
extern u8 D_005F1FF0[];
extern u8 D_005F1E40[];
extern u8 D_005F1E60[];
extern u8 D_005F1E80[];
extern u8 D_005F1EA0[];
extern u8 D_005F1EC0[];
extern u8 D_005F1EE0[];
extern u8 D_005F1F10[];
extern u8 D_005F1F30[];
extern u8 D_005F1F50[];
extern u8 D_005F1F70[];
extern u8 D_005F1F90[];
extern u8 D_005F2010[];
extern u8 D_005F2030[];
extern u8 D_005F2050[];
extern u8 D_005F2070[];
extern u8 D_005F2090[];
extern s32 FldLmapScrollUpdate(u8 *arg0);
extern s32 FldLmapMarkerUpdate(u8 *arg0);
extern s32 FldLmapPathUpdate(u8 *arg0);
extern u8 D_005F2180[];
extern f32 D_005F20B0[];
extern f32 D_005F20B4[];
extern f32 D_005F20B8[];
extern f32 D_005F20BC[];
extern f32 D_005F20C0[];
extern f32 D_005F20C4[];
extern f32 D_005F2130[];
extern f32 D_005F2134[];
extern f32 D_005F2138[];
extern f32 D_005F213C[];
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern f32 D_005F1E20[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u8 D_00795E60[];
extern char iGpffff9f68;
extern char iGpffff9f70;
extern f32 iGpffff84a4;
extern f32 iGpffff8538;
void FldLmapDrawCornerMarks(u8 *arg0, u8 *arg1);
void FldLmapDrawSlotRow(u8 *arg0, u8 *arg1);
void FldLmapDrawSlotMarker(u8 *arg0, u8 *arg1, s32 arg2);
void FldLmapDrawSlotPair(u8 *arg0, u8 *arg1, s32 arg2);
void FldLmapDrawSlotIcon(u8 *arg0, u8 *arg1, s32 arg2);
void FldLmapDrawPanel(u8 *arg0, u8 *arg1, s32 arg2);
u8 *FldLmapMarkerTaskCreate(u8 *arg0, s32 arg1, u8 *arg2);
void FldLmapMarkerSetTarget(u8 *arg0, s32 arg1, f32 fparg0);
u8 *FldLmapPathTaskCreate(u8 *arg0);
void func_00189600(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0);






#pragma opt_loop_invariants on
/* measured: see annotation above. */
#pragma opt_loop_invariants off

extern s32 FldLmapUpdate(u8 *arg0);

typedef struct FldLmapMatrix {
    s32 words[16];
} FldLmapMatrix;

#pragma push
#pragma opt_loop_invariants on
#pragma pop

















#pragma opt_loop_invariants on
/* measured: see annotation above. */
#pragma opt_loop_invariants off




static inline f32 mulFp(f32 left, f32 right) { return left * right; }



