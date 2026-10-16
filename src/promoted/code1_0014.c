#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw/plcore/barenderstate.h"

/* RenderWare sky2/rwcore.h:5683-5747. The compact GS state values are
   carried as pointers; the same entry point also accepts real pointers. */
typedef s32 RwBool;
typedef enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF
} RpSkyRenderState;
extern RwBool RpSkyRenderStateSet(RpSkyRenderState state, void *value);


/* Device callback signatures and the PS2 vertex layout follow badevice.h
   and sky2/rwplcore.h. The owning packet contains seven complete vertices. */
typedef enum RwPrimitiveType {
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST,
    rwPRIMTYPEPOLYLINE,
    rwPRIMTYPETRILIST,
    rwPRIMTYPETRISTRIP,
    rwPRIMTYPETRIFAN,
    rwPRIMTYPEPOINTLIST,
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RadarPrimitive;
typedef struct RwRGBAReal { f32 r, g, b, a; } RadarColorReal;
typedef struct RwSky2DVertexFields {
    RwV3d scrVertex;
    f32 camVertex_z;
    f32 u, v, recipZ, pad1;
    RadarColorReal color;
    RwV3d objNormal;
    f32 pad2;
} RadarVertexFields;
typedef union RwSky2DVertexAlignmentOverlay {
    RadarVertexFields els;
    unsigned __int128 qWords[4];
} RadarVertexOverlay;
typedef struct RwSky2DVertex { RadarVertexOverlay u; } RadarVertex;
typedef s32 (*RadarRenderStateSet)(RwRenderState state, void *value);
typedef s32 (*RadarRenderPrimitive)(RadarPrimitive kind, RadarVertex *vertices, s32 count);

extern RadarRenderStateSet D_00887300_abs[];
extern RadarRenderPrimitive D_00887310_abs[];

typedef struct RwMatrix RwMatrix;

typedef struct {
    f32 x;
    f32 y;
} Float2_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0[3];
    f32 scale;
    f32 pad1;
    u32 color[4];
    u32 pad2[4];
} Quad_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[0x14];
    u32 color[3];
    f32 scale;
    u8 pad1[0x10];
} Packet_0014;
typedef struct {
    u8 pad[0x40];
    u8 arg0[8];
    u8 arg1[8];
    Packet_0014 packet[4];
} Frame_0014;

extern u8 D_005EDA20[];
extern u8 D_005EDEA0[];
extern u8 D_005EE320[];
extern u8 D_005EE7A0[];
extern u8 D_005EEC20[];
extern u8 D_005EF0A0[];
extern u8 D_005EF530[];
extern u8 D_005EF540[];
extern u8 D_005EF548[];
extern u8 D_005EF6C8[];
extern f32 fGpffff8110;
extern void datScreenWipeSetTarget(u8 *arg0, u8 *arg1);
extern void datScreenWipeInit(u8 *arg0, Float2_0014 *arg1, Float2_0014 *arg2);
extern void datScreenWipeSetOffset(u8 *arg0, Float2_0014 arg1);
extern void datScreenWipeSetColor(u8 *arg0, s32 arg1);
extern void datScreenWipeSetScale(u8 *arg0, u8 *arg1);



extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void MT_Scene_DestroyRes(u16 resTypeId);
extern void resrcMngDestroy(u8 *arg0);
extern u8 *resrcMngGetListHead(u8 *arg0, s32 arg1);
extern void NpcTable_ReleaseSceneTable(void);
extern void NpcTable_ReleaseSecondaryTable(void);
extern void func_00160180(void);
extern void func_003e1a70(void);
extern void kwlnTaskDumpAll(void);
extern void FldResource_OpenPrimaryFile(s32 arg0, s32 arg1);
extern void FldResource_QueueFieldResources(s32 arg0, s32 arg1);
extern s32 FldResource_StepPartLoad(s32 arg0, s32 arg1);
extern s32 MT_SceneManager_Create(void);
extern u8 *resrcMngCreateRes(s32 arg0, s32 arg1);
extern u8 *resrcMngFindResById(u8 *arg0, u16 arg1);
extern void Vpad_BuildRotatedQuad(u8 *arg0, const u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern u8 *func_003e0f80(void);
extern void memcpy(void *dest, const void *src, s32 size);
extern void resrcMngDestroyRes();
extern void FldResource_Destroy(void *arg0);
extern void MT_Scene_SpawnIconTask(void *arg0);
extern void func_003bbb60(s32 arg0);
extern void func_003e0f40(s32 arg0);
extern u8 D_005EF890[];
extern u8 D_005EF8B0[];
extern u8 D_005EF8D0[];
extern u8 D_005EF8F0[];
extern u8 D_005EF910[];
extern u8 D_005EF930[];
extern u8 D_005EF950[];
extern u8 D_005EF970[];
extern u8 D_005EF820[];
extern u8 D_005EF870[];
extern void kAssertFail(const void *arg0, s32 arg1);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void func_004b1150(s32 arg0);
extern s32 mdlPrepareModel(s32 arg0);
extern void mdlDestroyModelObject(s32 arg0);
extern s32 datCalcGetLevelById(s32 arg0);
extern u8 D_007EF9B0[];
extern void func_003c38b0(void *arg0, void *arg1);
extern void func_003e8110(void *arg0);
extern void func_003e8120(void *arg0);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern u8 *K_Clump_GetLightA(void);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);
extern u8 *K_Clump_GetWorld(void);
extern void func_003cbe80(void *arg0, void *arg1);
extern u8 *resrcMngGetColorValue(void);
extern u8 D_007E8020[];
extern void *mdlGetMatrix(void *model);
extern f32 RwV3dLength(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern s32 FldEvent_HasLineOfSight(void *arg0, void *arg1, f32 fparg0, f32 fparg1);

extern s32 FldMap_IsInBandA(s32 arg0, s32 arg1);
extern s32 FldMap_IsInBandB(s32 arg0, s32 arg1);
extern void func_00440b68();
extern s32 func_00153a60(s32 arg0);
extern s32 resrcMngCreate(void);
extern s32 MT_Scene_CreateResLightChar(s32 arg0);
extern void SceneDraw_InitResList4(void);
extern s32 MT_Scene_CreateResLightNpc(s32 arg0);
extern void SceneDraw_InitResList5(void);
extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern s32 func_003cbf30(s32 arg0, void *arg1);
extern u8 *resrcMngGetColorTarget(void);
extern u8 *resrcMngGetTransform(void);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
extern void func_00364c50(void);
extern void func_00364c70(void);
extern u16 D_008C024E[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 iGpffffba5c;
extern u8 iGpffffba60;
extern u8 iGpffffba64;
extern u8 iGpffffba68;
extern void fieldSceneUnload(void);
extern u8 * iGpffff9db0;
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 func_004b1130(s32 arg0);
extern void func_004b1170(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_004b1250(void *object, f32 *position);
extern s32 FldFrameTask_Spawn(s32 arg0, s32 arg1, s32 arg2, f32 fparg0);
extern void func_004b13d0(s32 arg0, f32 arg1);

extern s32 D_007642E4;
extern u8 D_005EFB10[];
extern s32 resrcMngRenderTask(u8 *task);
extern void FldShadow_SpawnCasterTask(u8 *arg0);


static inline u8 *p4_e740_add(s32 offset, u8 *base) {
    return (u8 *)(offset + (u32)base);
}
static inline f32 p4_0014_recip(f32 value)
{
    return 1.0f / value;
}
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;



extern u8 *PrimAllocQueueNode(void);
extern void func_00460ac0(void *arg0, u8 *arg1);
extern void func_0014d290(u8 *arg0, u8 *arg1);

extern s32 func_0034c210(void);
extern void func_0013fb50(u8 *arg0);
extern s32 func_0013ff80(u8 *arg0);
extern s32 radarEntriesReady(u8 *arg0);
extern void radarDestroy(u8 *arg0);
extern void radarLoadSlotCoords(u8 *arg0);
extern s32 func_0034bb20(s32 arg0);
extern void func_0034bd60(s32 arg0);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datScreenWipeSetTextureId(u8 *arg0, s32 arg1);
extern void sflDataResetPersonaState(void *arg0);
extern void sflDataLoadPersonaState(void *arg0, s16 pcId);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void radarDrawEdge(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void resrcMngSetDrawEnabled(s32 arg0, s32 arg1);
extern void MT_Scene_ScaleResColors(u32 *resource, const f32 *color);
extern void func_00457140(u8 red, u8 green, u8 blue, u8 alpha);
extern s8 *func_00457160(void);
extern void func_00153b20(s32 arg0, s32 arg1);

extern void func_00153b60(s32 arg0, s32 arg1);

extern void func_00153b90(s32 arg0, s32 arg1);

extern void func_00153bd0(s32 arg0, s32 arg1);
extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 *MT_Scene_GetFrameState(void);
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void datCommunityEntryStep(u8 *arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern s32 FldRc_FileLoadStep(u8 *arg0);
extern void FldRc_FileLoadDestroy(u8 *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern s32 func_001441e0(u8 *arg0);
extern void func_00144ac0(u8 *arg0);
extern void strcpy(void *arg0, const char *arg1);
extern void sprintf(void *arg0, const char *arg1, ...);
extern void strcat(void *arg0, const void *arg1);
extern s32 H_Cdvd_FileExists(void *arg0);
extern u8 D_005EF7C0[];
extern u8 iGpffff9db8;
extern u8 iGpffff9dc0;
extern u8 iGpffff9dc8;
extern s32 K_FldFrame_IsPointInTriangle(f32 *arg0, f32 **arg1, f32 *arg2);
extern RwV3d D_005EFB98;
static inline u8 *p4_00141cf0_add(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}



/* Camp display: grid, labels, radar and corner sprites.
 * The radar callees are declared here with u8 opacity parameters (H011):
 * retail narrows each radar alpha with its unsigned conversion and passes
 * it without another mask, while the matched definitions in this file keep
 * s32 because their own bodies use the full word.
 * `sprite` is one function-scope variable for the 0x1834 label sprite and
 * the corner sprite; b210 does not propagate it into the sdkSpriteDrawSized
 * call, so the label pointer is loaded before the stack argument. */
#pragma push
#pragma opt_loop_invariants on
typedef struct { s32 lo, hi; } CampDisplayWords;
typedef union {
    Float2_0014 xy;
    CampDisplayWords words;
    s64 bits;
} CampDisplayPosition;
typedef struct {
    u8 r, g, b, a;
} CampDisplayRgba;

typedef union {
    CampDisplayRgba rgba;
    u8 bytes[4];
    s32 packed;
} CampDisplayColor;

extern f32 fGpffff854c;

extern u8 D_005EF520[];
extern u8 D_005EF670[];
extern u8 D_005EF6A0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern f32 D_008872F8[];
extern void sdkRenderStateSetDefault(void);
extern void func_0034c270(Float2_0014 work, s32 arg1, s32 arg2, f32 fparg0);
extern f32 cmpGridCellFade(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2);
extern void sdkSpriteDrawAt(void *work, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void sdkSpriteDrawSized(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void sdkSpriteDrawFooter(Float2_0014 work, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
extern void datScreenWipeSetAlpha(u8 *work, u8 arg1);
extern void datScreenWipeDraw(void *work);
extern void sflDataDrawEntry(CampDisplayWords position, f32 depth, s32 alpha, s16 *label);
extern s32 datCalcGetLevelById(s32 work);
extern u32 func_0010d6d0(s16 work);
extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
extern void radarDrawNumber(s64 work, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3);
extern void radarDrawText(Float2_0014 pos, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3);


#pragma pop
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off






#pragma optimization_level 1
/* measured: closes the scoped optimization-level-1 probe. */
#pragma optimization_level 2


#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation on



#pragma push
#pragma opt_lifetimes on
#pragma pop








#pragma optimization_level 1
#pragma schedule off
#pragma schedule on
#pragma optimization_level 2

#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma pop









/* measured: opt_rebuildconditionals off is scoped to resrcMngResetRenderSlots. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for resrcMngResetRenderSlots. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to resrcMngSetDrawEnabled. */
#pragma opt_rebuildconditionals off

#pragma opt_loop_invariants on
/* measured: closes loop-invariant constants probe for resrcMngSetDrawEnabled. */
#pragma opt_loop_invariants off
/* measured: closes opt_rebuildconditionals for resrcMngSetDrawEnabled. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to FldMap_IsCurrentInEitherBand. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for FldMap_IsCurrentInEitherBand. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to FldMap_IsInEitherBand. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for FldMap_IsInEitherBand. */
#pragma opt_rebuildconditionals on




#pragma optimization_level 1
#pragma optimization_level 2
static inline void fldGridMark(s32 x, s32 y)
{
    D_007D24B0[y] |= (u16)(1U << x);
    D_007D24B0[y] |= (u16)(1U << (x + 1));
    D_007D24B0[y + 1] |= (u16)(1U << x);
    D_007D24B0[y + 1] |= (u16)(1U << (x + 1));
}

#define FLD_GRID_HITS(cellX, cellY, x, y)                                                                \
    (((cellX) == (x) && (cellY) == (y)) || ((cellX) == (x) + 1 && (cellY) == (y)) ||                      \
     ((cellX) == (x) && (cellY) == (y) + 1) || ((cellX) == (x) + 1 && (cellY) == (y) + 1))

#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off












#pragma opt_propagation off
/* measured probe: restore opt_propagation after 0014dd80. */
#pragma opt_propagation on
typedef struct {
    f32 gammaCorrection;
    void *fpSystem;
    f32 zBufferNear;
    f32 zBufferFar;
} RwDeviceHead_0014;
typedef struct {
    void *curCamera;
    void *curWorld;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
    RwDeviceHead_0014 dOpenDevice;
} RwGlobalsHead_0014;
extern u32 ourGlobals[];
#define RwIm2DGetNearScreenZ() \
    (((RwGlobalsHead_0014 *)ourGlobals)->dOpenDevice.zBufferNear)
#pragma optimization_level 1
#pragma optimization_level 2
/* 712/720 bytes; ten resolved relocations; eight zero alignment bytes.
 * Inline predicates preserve reveal ordering and the frame-41 transition. */
#pragma push
#pragma opt_rebuildlogicals off
#pragma opt_loop_invariants on
static inline void fieldTransitionScaleVector(SVec3 *destination, SVec3 *source, f32 scale)
{
    destination->x = source->x * scale;
    destination->y = source->y * scale;
    destination->z = source->z * scale;
}
static inline s32 fieldTransitionChildReady(u8 *child)
{
    if (child == NULL) return 1;
    if (**(s32 **)(child + 0x38) > 0) return 1;
    return 0;
}
static inline u32 fieldTransitionEntryActive(u32 index)
{
    s32 active = 0;
    u8 *entry = D_007EF9B0 + index * 0x750;
    if (*(s32 *)(entry + 0x48) != 0 && *(u8 **)(entry + 0x54) != NULL) active = 1;
    return active != 0;
}
extern void func_00122520(s32 enabled, s32 mode);
extern void H_Fade_SetCustomColor(s32 red, s32 green, s32 blue);
extern void RwV3dNormalize(f32 *destination, f32 *source);
extern u8 iGpffff9dd8[8];

#pragma pop

