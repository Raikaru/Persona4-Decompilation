#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "primitive_queue_internal.h"
#include "scene_task_internal.h"
#include "scene_render_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "mdl_file_internal.h"
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


extern u8 *resrcMngFindResById(u8 *manager, u16 resourceId);
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
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern u8 D_007EF9B0[];
extern void func_003c38b0(void *, void *);
extern void func_003e8110(void *camera);
extern void func_003e8120(void *camera);
extern void func_003e9cb0(s32 frame, void *transform, s32 combine);
extern s32 kwlnGetCamera(void);
extern u8 *K_Clump_GetLightA(void);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);
extern u8 *K_Clump_GetWorld(void);
extern void func_003cbe80(void *, void *);
extern u8 *resrcMngGetColorValue(void);
extern u8 D_007E8020[];
extern void *mdlGetMatrix(void *model);
extern f32 RwV3dLength(f32 *);
extern u8 *func_003e9700(s32);

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern s32 func_003cbf30(s32, void *);
extern u8 *resrcMngGetColorTarget(void);
extern u8 *resrcMngGetTransform(void);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
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
extern u8 * iGpffff9db0;
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern void mdlEffectSetChildPositionVec(void *object, f32 *position);

extern s32 D_007642E4;
extern u8 D_005EFB10[];
extern s32 resrcMngRenderTask(u8 *unusedTask);
extern void FldShadow_SpawnCasterTask(u8 *parentTask);


typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;


extern s32 D_007642F0;


extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, u8 *node);


extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern void resrcMngSetDrawEnabled(s32 enabled, s32 includeFieldModels);
extern void MT_Scene_ScaleResColors(u32 *resource, const f32 *color);
extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
extern s8 *kwlnGetColorBytes(void);
extern void FldFilterSetPrimary(s32 task, s32 value);

extern void FldFilterSetSecondary(s32 task, s32 value);

extern void FldFilterSetTertiary(s32 task, s32 value);

extern void FldFilterSetIntensity(s32 task, s32 value);
extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void memset(void *, s32, s32);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern u8 D_005EF7C0[];
extern u8 iGpffff9db8;
extern u8 iGpffff9dc0;
extern u8 iGpffff9dc8;
extern RwV3d D_005EFB98;


/* Camp display: grid, labels, radar and corner sprites. Radar callees take u8 opacity because
 * retail passes the narrowed alpha without masking it again. */
#pragma push
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


#pragma pop


#pragma push
#pragma pop


#pragma push
#pragma pop

/* Look up a resource by its packed ID, walking the manager's list for the type encoded in the ID.
 * Return NULL if the type is out of range or no match is found. */
// FUN_00147530
/* Validate the packed type, then search its linked resource list for the complete type/id. */
u8 *resrcMngFindResById(u8 *manager, u16 resourceId) {
    s32 resourceType;
    s32 packedId;
    u8 *resource;

    packedId = resourceId;
    resourceType = ((packedId & 0xFFC00) >> 0xA) & 0xFF;
    if (resourceType == 0) {
        return NULL;
    }
    if (resourceType >= 0x16) {
        return NULL;
    }
    resource = ((u8 **)manager)[resourceType];
    while (resource != NULL) {
        if (((ResrcHeader *)resource)->id == packedId) {
            return resource;
        }
        resource = *(u8 * *)&((ResrcHeader *)resource)->next;
    }
    return NULL;
}

/* Count the resources in a valid per-type linked list; out-of-range types return zero. */
// FUN_001475C0
/* Matches P3FES resrcMngGetTotalResInList; P4 has 0x16 list heads and the list link stays at offset
 * 0x138. */
u32 resrcMngGetTotalResInList(u8 *resLists, u8 resType)
{
    u32 total;
    u8 *currRes;

    total = 0;
    if (resType >= 0x16) {
        return total;
    }
    currRes = ((u8 **)resLists)[resType];
    while (currRes != NULL) {
        total++;
        currRes = *(u8 * *)&((ResrcHeader *)currRes)->next;
    }
    return total;
}

// FUN_00147620
u8 *resrcMngGetTableEntry(s32 curveKind) {
    return D_005EFAA0 + curveKind * 0x10;
}

/* measured: copy propagation must be off to keep retail's float load ordering in
 * resrcMngRenderCameraFog. */
#pragma opt_propagation off
/* Begin the camera update, save the colors of lights A and B and light B's frame matrix into
 * savedState, attach light C to the world, and apply the override light colors and transform if one
 * is set. Then end the camera update and enable fog render states when fog is on. */
// FUN_00147640
/* Save primary/secondary lighting and install field lighting plus the configured fog render states. */
void resrcMngRenderCameraFog(u8 *unusedQueue, u8 *savedState) {
    f32 alpha;
    f32 blue;
    f32 green;
    f32 red;
    s32 world;
    s32 secondWord;
    s32 firstWord;
    u8 *primaryLight;
    u8 *secondaryLight;
    u8 *secondaryFrameOwner;
    u8 *primary;
    u8 *secondary;
    u8 *sourceWords;
    u8 *outputWords;
    s32 remainingPairs;
    void (**renderStates)(u32, u32);

    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    primary = K_Clump_GetLightA();
    red = ((SceneRenderLight *)primary)->color[0];
    green = ((SceneRenderLight *)primary)->color[1];
    blue = ((SceneRenderLight *)primary)->color[2];
    alpha = ((SceneRenderLight *)primary)->color[3];
    ((SceneLightingState *)savedState)->primary[0] = red;
    ((SceneLightingState *)savedState)->primary[1] = green;
    ((SceneLightingState *)savedState)->primary[2] = blue;
    ((SceneLightingState *)savedState)->primary[3] = alpha;
    secondary = K_Clump_GetLightB();
    red = ((SceneRenderLight *)secondary)->color[0];
    green = ((SceneRenderLight *)secondary)->color[1];
    blue = ((SceneRenderLight *)secondary)->color[2];
    alpha = ((SceneRenderLight *)secondary)->color[3];
    ((SceneLightingState *)savedState)->secondary[0] = red;
    ((SceneLightingState *)savedState)->secondary[1] = green;
    ((SceneLightingState *)savedState)->secondary[2] = blue;
    ((SceneLightingState *)savedState)->secondary[3] = alpha;
    sourceWords = (u8 *)((SceneRenderLight *)K_Clump_GetLightB())->frame + 0x10;
    outputWords = savedState + 0x20;
    remainingPairs = 8;
    do {
        firstWord = ((s32 *)sourceWords)[0];
        secondWord = ((s32 *)sourceWords)[1];
        sourceWords += 8;
        remainingPairs -= 1;
        ((s32 *)outputWords)[0] = firstWord;
        ((s32 *)outputWords)[1] = secondWord;
        outputWords += 8;
    } while (remainingPairs > 0);
    world = (s32)K_Clump_GetWorld();
    func_003cbf30(world, K_Clump_GetLightC());
    if (resrcMngGetColorValue() != NULL) {
        primaryLight = K_Clump_GetLightA();
        func_003c38b0(primaryLight, resrcMngGetColorValue());
        secondaryLight = K_Clump_GetLightB();
        func_003c38b0(secondaryLight, resrcMngGetColorTarget());
        secondaryFrameOwner = K_Clump_GetLightB();
        func_003e9cb0(((SceneRenderLight *)secondaryFrameOwner)->frame, resrcMngGetTransform(), 0);
    }
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
    if (iGpffffba48 == 1) {
        renderStates = D_00887300;
        renderStates[0](0xE, 1);
        renderStates[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        renderStates[0](0x10, 1);
    }
}

/* Begin the camera update, detach light C from the world, and if a color override was active,
 * restore lights A and B and light B's frame from savedState before ending the camera update. */
// FUN_00147830
/* Restore saved primary/secondary lighting after the field-light pass. */
void resrcMngRenderCamera(u8 *unusedQueue, u8 *savedState) {
    u8 *world;

    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    world = K_Clump_GetWorld();
    func_003cbe80(world, K_Clump_GetLightC());
    if (resrcMngGetColorValue() != NULL) {
        func_003c38b0(K_Clump_GetLightA(), savedState);
        func_003c38b0(K_Clump_GetLightB(), savedState + 0x10);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, savedState + 0x20, 0);
    }
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Save the colours of the three clump lights and the frame data of lights B and C into savedState,
 * then set the camera fade render states when a fade is active. */
// FUN_00147910
/* Save all three light colors and both matrices, then configure fog and the fade draw pass. */
void resrcMngRenderCameraFade(u8 *unusedQueue, u8 *savedState) {
    f32 alpha;
    f32 blue;
    f32 green;
    f32 red;
    s32 secondWord;
    s32 secondTertiaryWord;
    s32 firstWord;
    s32 firstTertiaryWord;
    u8 *primary;
    u8 *secondary;
    u8 *tertiary;
    u8 *sourceWords;
    u8 *outputWords;
    s32 remainingPairs;
    u8 *tertiarySourceWords;
    u8 *tertiaryOutputWords;
    s32 tertiaryRemainingPairs;
    void (**renderStates)(u32, u32);

    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    primary = K_Clump_GetLightA();
    red = ((SceneRenderLight *)primary)->color[0];
    green = ((SceneRenderLight *)primary)->color[1];
    blue = ((SceneRenderLight *)primary)->color[2];
    alpha = ((SceneRenderLight *)primary)->color[3];
    ((SceneLightingState *)savedState)->primary[0] = red;
    ((SceneLightingState *)savedState)->primary[1] = green;
    ((SceneLightingState *)savedState)->primary[2] = blue;
    ((SceneLightingState *)savedState)->primary[3] = alpha;
    secondary = K_Clump_GetLightB();
    red = ((SceneRenderLight *)secondary)->color[0];
    green = ((SceneRenderLight *)secondary)->color[1];
    blue = ((SceneRenderLight *)secondary)->color[2];
    alpha = ((SceneRenderLight *)secondary)->color[3];
    ((SceneLightingState *)savedState)->secondary[0] = red;
    ((SceneLightingState *)savedState)->secondary[1] = green;
    ((SceneLightingState *)savedState)->secondary[2] = blue;
    ((SceneLightingState *)savedState)->secondary[3] = alpha;
    sourceWords = (u8 *)((SceneRenderLight *)K_Clump_GetLightB())->frame + 0x10;
    outputWords = savedState + 0x20;
    remainingPairs = 8;
    do {
        firstWord = ((s32 *)sourceWords)[0];
        secondWord = ((s32 *)sourceWords)[1];
        sourceWords += 8;
        remainingPairs -= 1;
        ((s32 *)outputWords)[0] = firstWord;
        ((s32 *)outputWords)[1] = secondWord;
        outputWords += 8;
    } while (remainingPairs > 0);
    tertiary = K_Clump_GetLightC();
    red = ((SceneRenderLight *)tertiary)->color[0];
    green = ((SceneRenderLight *)tertiary)->color[1];
    blue = ((SceneRenderLight *)tertiary)->color[2];
    alpha = ((SceneRenderLight *)tertiary)->color[3];
    ((SceneLightingState *)savedState)->tertiary[0] = red;
    ((SceneLightingState *)savedState)->tertiary[1] = green;
    ((SceneLightingState *)savedState)->tertiary[2] = blue;
    ((SceneLightingState *)savedState)->tertiary[3] = alpha;
    tertiarySourceWords = (u8 *)((SceneRenderLight *)K_Clump_GetLightC())->frame + 0x10;
    tertiaryOutputWords = savedState + 0x70;
    tertiaryRemainingPairs = 8;
    do {
        firstTertiaryWord = ((s32 *)tertiarySourceWords)[0];
        secondTertiaryWord = ((s32 *)tertiarySourceWords)[1];
        tertiarySourceWords += 8;
        tertiaryRemainingPairs -= 1;
        ((s32 *)tertiaryOutputWords)[0] = firstTertiaryWord;
        ((s32 *)tertiaryOutputWords)[1] = secondTertiaryWord;
        tertiaryOutputWords += 8;
    } while (tertiaryRemainingPairs > 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
    if (iGpffffba48 == 1) {
        renderStates = D_00887300;
        renderStates[0](0xE, 1);
        renderStates[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        renderStates[0](0x10, 1);
    }
    D_00887300[0](0x14, 2);
}

/* Save the state of the three clump lights and the frames of lights B and C into savedState while
 * the camera is bound. */
// FUN_00147AE0
/* Restore all three light colors and both saved light matrices. */
void resrcMngRenderCameraPair(u8 *unusedQueue, u8 *savedState) {
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), savedState);
    func_003c38b0(K_Clump_GetLightC(), savedState + 0x60);
    func_003c38b0(K_Clump_GetLightB(), savedState + 0x10);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, savedState + 0x70, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, savedState + 0x20, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Install character lighting, selecting global or per-resource colors from the upper resource flags. */
// FUN_00147BB0
void resrcMngRenderAttached(u8 *unusedQueue, u8 *resource) {
    s32 flags;
    u8 *lightResource;

    lightResource = MT_Scene_GetResListHead(4);
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), lightResource + 0x140);
    func_003c38b0(K_Clump_GetLightC(), lightResource + 0x150);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, lightResource + 0x160, 0);
    flags = *(s32 *)&((ResrcHeader *)resource)->flags;
    if (flags & 0x80000000) {
        func_003c38b0(K_Clump_GetLightA(), resource + 0x168);
        func_003c38b0(K_Clump_GetLightC(), resource + 0x178);
        func_003c38b0(K_Clump_GetLightB(), resource + 0x1D0);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, resource + 0x190, 0);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1E0, 0);
    } else if (flags & 0x40000000) {
        func_003c38b0(K_Clump_GetLightB(), resource + 0x1D0);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1E0, 0);
    } else {
        func_003c38b0(K_Clump_GetLightB(), lightResource + 0x1A0);
        func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, lightResource + 0x1B0, 0);
    }
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Install the type-5 NPC lighting colors and both light-frame matrices. */
// FUN_00147D80
void resrcMngRenderCameraSlots(void) {
    u8 *lightResource;

    lightResource = MT_Scene_GetResListHead(5);
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), lightResource + 0x140);
    func_003c38b0(K_Clump_GetLightC(), lightResource + 0x150);
    func_003c38b0(K_Clump_GetLightB(), lightResource + 0x1A0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, lightResource + 0x160, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, lightResource + 0x1B0, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Install the NPC resource-specific primary, tertiary and secondary colors and light matrices. */
// FUN_00147E60
void resrcMngRenderAttachedPair(u8 *unusedQueue, u8 *resource) {
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), resource + 0x168);
    func_003c38b0(K_Clump_GetLightC(), resource + 0x178);
    func_003c38b0(K_Clump_GetLightB(), resource + 0x1D0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, resource + 0x190, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1E0, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Install object-model lighting from its shorter kind-specific resource tail. */
// FUN_00147F30
void resrcMngRenderAttachedAlt(u8 *unusedQueue, u8 *resource) {
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), resource + 0x15C);
    func_003c38b0(K_Clump_GetLightC(), resource + 0x16C);
    func_003c38b0(K_Clump_GetLightB(), resource + 0x1C0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, resource + 0x180, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1D0, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* Compare character-model camera distances, truncating their floating-point difference to a signed
 * integer. */
// FUN_00148000
s32 resrcMngCompareDistanceArrA(const void *left, const void *right) {
    u8 *const *leftEntry = (u8 *const *)left;
    u8 *const *rightEntry = (u8 *const *)right;
    struct Frame {
        f32 cameraPosition[3];
        u8 pad4C[4];
        f32 rightDelta[3];
        u8 pad5C[4];
        f32 leftDelta[3];
        u8 pad6C[4];
    } frame;
    f32 cameraY;
    f32 distanceOrCameraZ;
    f32 x;
    f32 y;
    f32 z;
    u8 *rightResource;
    u8 *leftResource;
    u8 *cameraOrMatrix;
    ResrcRecord *leftRecord;
    ResrcRecord *rightRecord;

    cameraOrMatrix = ((u8 *)(u32)kwlnGetCamera());
    cameraOrMatrix = func_003e9700(((SceneRenderObject *)cameraOrMatrix)->frame);
    x = ((struct RwMatrix *)cameraOrMatrix)->pos.x;
    y = ((struct RwMatrix *)cameraOrMatrix)->pos.y;
    z = ((struct RwMatrix *)cameraOrMatrix)->pos.z;
    frame.cameraPosition[0] = x;
    frame.cameraPosition[1] = y;
    frame.cameraPosition[2] = z;
    leftResource = *leftEntry;
    rightResource = *rightEntry;
    leftRecord = (ResrcRecord *)leftResource;
    rightRecord = (ResrcRecord *)rightResource;
    frame.leftDelta[0] = ((struct RwMatrix *)mdlGetMatrix(((ResrcRecord *)leftResource)->modelHandle164))->pos.x - frame.cameraPosition[0];
    cameraY = frame.cameraPosition[1];
    frame.leftDelta[1] = ((struct RwMatrix *)mdlGetMatrix(leftRecord->modelHandle164))->pos.y - cameraY;
    distanceOrCameraZ = frame.cameraPosition[2];
    frame.leftDelta[2] = ((struct RwMatrix *)mdlGetMatrix(leftRecord->modelHandle164))->pos.z - distanceOrCameraZ;
    frame.rightDelta[0] = ((struct RwMatrix *)mdlGetMatrix(((ResrcRecord *)rightResource)->modelHandle164))->pos.x - frame.cameraPosition[0];
    frame.rightDelta[1] = ((struct RwMatrix *)mdlGetMatrix(rightRecord->modelHandle164))->pos.y - cameraY;
    frame.rightDelta[2] = ((struct RwMatrix *)mdlGetMatrix(rightRecord->modelHandle164))->pos.z - distanceOrCameraZ;
    distanceOrCameraZ = RwV3dLength(frame.leftDelta);
    return (s32)(distanceOrCameraZ - RwV3dLength(frame.rightDelta));
}

/* Compare two resource records by their models' distance from the camera, returning the difference
 * truncated to an integer. */
// FUN_00148140
s32 resrcMngCompareDistanceArrB(const void *left, const void *right) {
    u8 *const *leftEntry = (u8 *const *)left;
    u8 *const *rightEntry = (u8 *const *)right;
    struct Frame {
        f32 cameraPosition[3];
        u8 pad4C[4];
        f32 rightDelta[3];
        u8 pad5C[4];
        f32 leftDelta[3];
        u8 pad6C[4];
    } frame;
    f32 cameraY;
    f32 distanceOrCameraZ;
    f32 x;
    f32 y;
    f32 z;
    u8 *rightResource;
    u8 *leftResource;
    u8 *cameraOrMatrix;
    ResrcRecord *leftRecord;
    ResrcRecord *rightRecord;

    cameraOrMatrix = ((u8 *)(u32)kwlnGetCamera());
    cameraOrMatrix = func_003e9700(((SceneRenderObject *)cameraOrMatrix)->frame);
    x = ((struct RwMatrix *)cameraOrMatrix)->pos.x;
    y = ((struct RwMatrix *)cameraOrMatrix)->pos.y;
    z = ((struct RwMatrix *)cameraOrMatrix)->pos.z;
    frame.cameraPosition[0] = x;
    frame.cameraPosition[1] = y;
    frame.cameraPosition[2] = z;
    leftResource = *leftEntry;
    rightResource = *rightEntry;
    leftRecord = (ResrcRecord *)leftResource;
    rightRecord = (ResrcRecord *)rightResource;
    frame.leftDelta[0] = ((struct RwMatrix *)mdlGetMatrix(((ResrcRecord *)leftResource)->modelHandle164))->pos.x - frame.cameraPosition[0];
    cameraY = frame.cameraPosition[1];
    frame.leftDelta[1] = ((struct RwMatrix *)mdlGetMatrix(leftRecord->modelHandle164))->pos.y - cameraY;
    distanceOrCameraZ = frame.cameraPosition[2];
    frame.leftDelta[2] = ((struct RwMatrix *)mdlGetMatrix(leftRecord->modelHandle164))->pos.z - distanceOrCameraZ;
    frame.rightDelta[0] = ((struct RwMatrix *)mdlGetMatrix(((ResrcRecord *)rightResource)->modelHandle164))->pos.x - frame.cameraPosition[0];
    frame.rightDelta[1] = ((struct RwMatrix *)mdlGetMatrix(rightRecord->modelHandle164))->pos.y - cameraY;
    frame.rightDelta[2] = ((struct RwMatrix *)mdlGetMatrix(rightRecord->modelHandle164))->pos.z - distanceOrCameraZ;
    distanceOrCameraZ = RwV3dLength(frame.leftDelta);
    return (s32)(distanceOrCameraZ - RwV3dLength(frame.rightDelta));
}

/* measured: resrcMngRenderTask and resrcMngSetDrawEnabled need constant propagation back on to
 * match retail code generation. */
#pragma opt_propagation on
/* Render passes reload resources after each callback and copy whole position vectors. Both tail
 * loops share function-scope k and j, matching retail's counter registers. */
#pragma push
/* measured: retail's render task needs loop-invariant hoisting enabled here. */
#pragma opt_loop_invariants on
/* measured: retail's register lifetimes in the render-pass loops need this setting. */
#pragma opt_lifetimes on
/* Queue kind-specific model and lighting passes, sorting characters and translucent NPCs when enabled. */
// FUN_00148280
s32 resrcMngRenderTask(u8 *unusedTask) {
    /* Retail returns zero at 001495E8, 00148318. */
    extern void FldResource_QueueDrawCallbacks(u8 *list, u8 *resource);
    extern void FldResource_QueueDrawCallbacksPrimary(u8 *list, u8 *resource);
    extern void FldResource_QueueDrawCallbacksSecondary(u8 *list, u8 *resource);
    extern void mdlEffectAdvanceAndFlushWithTable(void *table, void *effect);
    extern s32 hMaestroListSetHasEntries(u8 *listSet);
    extern u32 K_Clump_StateFlagIsSet(const u32 *state);
    extern void mdlQueueModelForDraw(void *queue, u8 *model);
    extern void *mdlGetColor(void *model);
    extern s32 mdlComputeIndexedAttachMatrix(void *model, s32 index, void *destination);
    extern void mdlEffectFlushWithTable(void *table, void *effect);
    extern void qsort(void *base, size_t count, size_t size,
                      s32 (*compare)(const void *, const void *));
    extern s32 FldMap_IsCurrentInEitherBand(void);
    extern u8 D_005DC7D0[];
    extern u8 D_005DC824[];
    extern u8 D_005EFB00[];
    extern u8 D_00793E80[];
    extern u8 D_00793EE0[];
    extern u8 D_00793F10[];
    extern u8 D_00793F40[];
    extern u8 D_00793F70[];
    extern u8 D_007942D0[];
    extern u8 D_00794300[];
    extern u8 D_00794360[];
    extern u8 D_00794390[];
    extern u8 D_007943F0[];
    extern u8 D_007945A0[];
    extern u8 D_007945D0[];
    extern u8 D_007947E0[];
    extern u8 D_007D1F30[];
    extern u8 D_007D1FE0[];
    extern u8 D_007D2090[];
    extern u8 D_007D2140[];
    extern u8 D_007D21F0[];
    extern u8 D_007D22A0[];
    extern u8 D_007D2350[];
    extern u8 D_007D2400[];
    u8 **sortedEntry;
    /* Byte cursors are kept alongside typed locals so member addresses are not held across
     * callbacks. */
    ResrcRecord *fieldRecord, *fieldModelRecord, *npcRecord, *resourceRecord;
    u8 *characters[64];
    u8 *translucentNpcs[64];
    RwV3d pos;
    u8 *fieldResources;
    u8 *fieldModels;
    u8 *effectResources;
    u8 *characterResources;
    u8 *npcResources;
    u8 *objectResources;
    s32 alternateQueues;
    s32 hasCharacterDrawSet;
    s32 hasObjectDrawSet;
    u32 characterCount;
    s32 translucentCount;
    u8 *queueNode;
    u8 *attachedModel;
    s32 resourceFlags;
    s32 characterIndex;
    s32 sortedIndex;
    s32 attachmentIndex;
    u8 *entryCursor;

    fieldResources = MT_Scene_GetResListHead(0xC);
    fieldRecord = (ResrcRecord *)fieldResources;
    fieldModels = MT_Scene_GetResListHead(0xA);
    fieldModelRecord = (ResrcRecord *)fieldModels;
    effectResources = MT_Scene_GetResListHead(0xB);
    characterResources = MT_Scene_GetResListHead(1);
    npcResources = MT_Scene_GetResListHead(3);
    npcRecord = (ResrcRecord *)npcResources;
    objectResources = MT_Scene_GetResListHead(2);
    alternateQueues = 0;
    if (D_007642E4 == 1) {
        return 0;
    }
    if (((SceneContext *)iGpffff9db0)->majorId >= 0xC8) {
        alternateQueues = 1;
    }
    while (effectResources != NULL) {
        if ((s32)((ResrcRecord *)(effectResources))->flags & 2) {
            mdlEffectAdvanceAndFlushWithTable(D_005DC7D0, ((ResrcRecord *)(effectResources))->slotHandle[1]);
        }
        effectResources = (u8 *)((ResrcRecord *)(effectResources))->next;
    }
    while (fieldResources != NULL) {
        if ((s32)((ResrcRecord *)(fieldResources))->flags & 2) {
            FldResource_QueueDrawCallbacks(D_00793EE0, (u8 *)((ResrcRecord *)(fieldResources))->handle1A0);
            if (alternateQueues != 0) {
                FldResource_QueueDrawCallbacksPrimary(D_00793F70, (u8 *)fieldRecord->handle1A0);
                FldResource_QueueDrawCallbacksSecondary(D_00793F70, (u8 *)fieldRecord->handle1A0);
            } else {
                FldResource_QueueDrawCallbacksPrimary(D_00794390, (u8 *)fieldRecord->handle1A0);
                FldResource_QueueDrawCallbacksSecondary(D_00794390, (u8 *)fieldRecord->handle1A0);
            }
        }
        fieldResources = (u8 *)((ResrcRecord *)(fieldResources))->next;
        fieldRecord = (ResrcRecord *)fieldResources;
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFog;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2400;
    PrimAppendNode(D_00793EE0, queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFog;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2350;
    if (alternateQueues != 0) {
        PrimAppendNode(D_00793F10, queueNode);
    } else {
        PrimAppendNode(D_00794300, queueNode);
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFog;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D22A0;
    if (alternateQueues != 0) {
        PrimAppendNode(D_00793F40, queueNode);
    } else {
        PrimAppendNode(D_00794360, queueNode);
    }
    while (fieldModels != NULL) {
        resourceFlags = (s32)((ResrcRecord *)(fieldModels))->flags;
        if (resourceFlags & 2) {
            if (resourceFlags & 0x02000000) {
                mdlQueueModelForDraw(D_007942D0, (u8 *)((ResrcRecord *)(fieldModels))->slotHandle[1]);
            } else if (resourceFlags & 0x01000000) {
                mdlQueueModelForDraw(D_007947E0, (u8 *)((ResrcRecord *)(fieldModels))->slotHandle[1]);
            } else if (K_Clump_StateFlagIsSet((const u32 *)((MdlFileModel *)((u8 *)((ResrcRecord *)(fieldModels))->slotHandle[1]))->drawBuckets) == 1) {
                if (alternateQueues != 0) {
                    mdlQueueModelForDraw(D_00793F10, (u8 *)fieldModelRecord->slotHandle[1]);
                } else {
                    mdlQueueModelForDraw(D_00794300, (u8 *)fieldModelRecord->slotHandle[1]);
                }
                attachedModel = (u8 *)((ResrcRecord *)(fieldModels))->handle16C;
                if (attachedModel != NULL && ((s32)fieldModelRecord->flags & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794300, attachedModel);
                }
            } else if (hMaestroListSetHasEntries((u8 *)((MdlFileModel *)((u8 *)fieldModelRecord->slotHandle[1]))->drawBuckets) == 1) {
                if (alternateQueues != 0) {
                    mdlQueueModelForDraw(D_00793F40, (u8 *)fieldModelRecord->slotHandle[1]);
                } else {
                    mdlQueueModelForDraw(D_00794360, (u8 *)fieldModelRecord->slotHandle[1]);
                }
                attachedModel = (u8 *)((ResrcRecord *)(fieldModels))->handle16C;
                if (attachedModel != NULL && ((s32)fieldModelRecord->flags & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794360, attachedModel);
                }
            } else {
                mdlQueueModelForDraw(D_00793EE0, (u8 *)fieldModelRecord->slotHandle[1]);
                attachedModel = (u8 *)((ResrcRecord *)(fieldModels))->handle16C;
                if (attachedModel != NULL && ((s32)fieldModelRecord->flags & 0x20000000)) {
                    mdlQueueModelForDraw(D_00793EE0, attachedModel);
                }
            }
        }
        fieldModels = (u8 *)((ResrcRecord *)(fieldModels))->next;
        fieldModelRecord = (ResrcRecord *)fieldModels;
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCamera;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2400;
    PrimAppendNode(D_00793EE0, queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCamera;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2350;
    if (alternateQueues != 0) {
        PrimAppendNode(D_00793F10, queueNode);
    } else {
        PrimAppendNode(D_00794300, queueNode);
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCamera;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D22A0;
    if (alternateQueues != 0) {
        PrimAppendNode(D_00793F40, queueNode);
    } else {
        PrimAppendNode(D_00794360, queueNode);
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D21F0;
    PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2140;
    PrimAppendNode(D_007945D0, queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D1FE0;
    PrimAppendNode(D_007945A0, queueNode);
    memset(characters, 0, 0x100);
    characterCount = 0;
    while (characterResources != NULL) {
        if (characterCount >= 0x40) {
            kAssertFail(D_005EFB00, 0x264);
        }
        characters[characterCount] = characterResources;
        characterResources = (u8 *)((ResrcRecord *)(characterResources))->next;
        characterCount += 1;
    }
    if (((SceneContext *)iGpffff9db0)->sortCharacters == 1) {
        qsort(characters, characterCount, 4, resrcMngCompareDistanceArrA);
    }
    hasCharacterDrawSet = 0;
    for (characterIndex = (s32)(characterCount - 1); characterIndex >= 0; characterIndex--) {
        u8 **characterEntry = &characters[characterIndex];
        s32 flags = (s32)((ResrcRecord *)(*characterEntry))->flags;

        if (flags & 2) {
            if (flags & 0x04000000) {
                hasCharacterDrawSet = 1;
            } else {
                s32 attachmentIndex;

                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttached;
                ((PrimQueueNode *)queueNode)->argument.data = *characterEntry;
                PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
                if (FldMap_IsCurrentInEitherBand() == 1 && (*(u16 *)*characterEntry & 0x3FF) >= 100) {
                    mdlQueueModelForDraw(D_007943F0, (u8 *)((ResrcRecord *)(*characterEntry))->modelHandle164);
                } else {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)((ResrcRecord *)(*characterEntry))->modelHandle164);
                }
                if ((u8 *)((ResrcRecord *)(*characterEntry))->handle228 != NULL && ((s32)((ResrcRecord *)(*characterEntry))->flags & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)((ResrcRecord *)(*characterEntry))->handle228);
                }
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = *characterEntry;
                    if (((ResrcRecord *)(attachmentOwner))->slotHandleValue[attachmentIndex] != 0) {
                        if (mdlComputeIndexedAttachMatrix(((ResrcRecord *)(attachmentOwner))->modelHandle164, 2, &pos) == 0) {
                            pos = ((struct RwMatrix *)((u8 *)mdlGetMatrix(((ResrcRecord *)(*characterEntry))->modelHandle164)))->pos;
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(((ResrcRecord *)(*characterEntry))->slotHandle[attachmentIndex], (f32 *)&pos);
                        mdlEffectFlushWithTable(D_005DC824, ((ResrcRecord *)(*characterEntry))->slotHandle[attachmentIndex]);
                    }
                }
            }
        }
    }
    if (hasCharacterDrawSet == 1) {
        u8 *resource = MT_Scene_GetResListHead(1);
        resourceRecord = (ResrcRecord *)resource;

        while (resource != NULL) {
            if (!((s32)((ResrcRecord *)(resource))->flags & 0x04000000)) {
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D2090;
                PrimAppendNode((void *)(D_00793E80 + ((ResrcRecord *)(resource))->characterDrawSet * 0x30), queueNode);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttached;
                ((PrimQueueNode *)queueNode)->argument.data = resource;
                PrimAppendNode((void *)(D_00793E80 + resourceRecord->characterDrawSet * 0x30), queueNode);
                mdlQueueModelForDraw((void *)(D_00793E80 + resourceRecord->characterDrawSet * 0x30), (u8 *)((ResrcRecord *)(resource))->modelHandle164);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D2090;
                PrimAppendNode((void *)(D_00793E80 + resourceRecord->characterDrawSet * 0x30), queueNode);
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            }
        }
    }
    if (npcResources != NULL) {
        queueNode = PrimAllocQueueNode();
        ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraSlots;
        ((PrimQueueNode *)queueNode)->argument.data = NULL;
        PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
    }
    memset(translucentNpcs, 0, 0x100);
    translucentCount = 0;
    while (npcResources != NULL) {
        if (((RwRGBA *)((u8 *)mdlGetColor(((ResrcRecord *)(npcResources))->modelHandle164)))->alpha < 0xFF) {
            translucentNpcs[translucentCount] = npcResources;
            translucentCount += 1;
            npcResources = (u8 *)((ResrcRecord *)(npcResources))->next;
            npcRecord = (ResrcRecord *)npcResources;
        } else {
            s32 flags = (s32)((ResrcRecord *)(npcResources))->flags;

            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                s32 attachmentIndex;

                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)npcRecord->modelHandle164);
                if ((u8 *)((ResrcRecord *)(npcResources))->handle22C != NULL && ((s32)npcRecord->flags & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)((ResrcRecord *)(npcResources))->handle22C);
                }
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    if (((ResrcRecord *)(npcResources))->slotHandleValue[attachmentIndex] != 0) {
                        if (mdlComputeIndexedAttachMatrix(npcRecord->modelHandle164, 2, &pos) == 0) {
                            pos = ((struct RwMatrix *)((u8 *)mdlGetMatrix(npcRecord->modelHandle164)))->pos;
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(((ResrcRecord *)(npcResources))[0].slotHandle[attachmentIndex], (f32 *)&pos);
                        mdlEffectFlushWithTable(D_005DC824, ((ResrcRecord *)(npcResources))[0].slotHandle[attachmentIndex]);
                    }
                }
            }
            npcResources = (u8 *)((ResrcRecord *)(npcResources))->next;
            npcRecord = (ResrcRecord *)npcResources;
        }
    }
    {
        u8 *resource = MT_Scene_GetResListHead(3);
        resourceRecord = (ResrcRecord *)resource;

        while (resource != NULL) {
            if (((RwRGBA *)((u8 *)mdlGetColor(((ResrcRecord *)(resource))->modelHandle164)))->alpha < 0xFF) {
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            } else {
                s32 flags = (s32)((ResrcRecord *)(resource))->flags;

                if ((flags & 0x10000000) && (flags & 2)) {
                    queueNode = PrimAllocQueueNode();
                    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedPair;
                    ((PrimQueueNode *)queueNode)->argument.data = resource;
                    PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
                    if ((s32)resourceRecord->flags & 0x80000000) {
                        s32 attachmentIndex;

                        mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)resourceRecord->modelHandle164);
                        if ((u8 *)((ResrcRecord *)(resource))->handle22C != NULL && ((s32)resourceRecord->flags & 0x20000000)) {
                            mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)((ResrcRecord *)(resource))->handle22C);
                        }
                        for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                            if (((ResrcRecord *)(resource))->slotHandleValue[attachmentIndex] != 0) {
                                if (mdlComputeIndexedAttachMatrix(resourceRecord->modelHandle164, 2, &pos) == 0) {
                                    pos = ((struct RwMatrix *)((u8 *)mdlGetMatrix(resourceRecord->modelHandle164)))->pos;
                                    pos.y += 175.0f;
                                }
                                mdlEffectSetChildPositionVec(((ResrcRecord *)(resource))->slotHandle[attachmentIndex], (f32 *)&pos);
                                mdlEffectFlushWithTable(D_005DC824, ((ResrcRecord *)(resource))->slotHandle[attachmentIndex]);
                            }
                        }
                    }
                }
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            }
        }
    }
    hasObjectDrawSet = 0;
    while (objectResources != NULL) {
        s32 flags = (s32)((ResrcRecord *)(objectResources))->flags;

        if (flags & 2) {
            if (flags & 0x04000000) {
                hasObjectDrawSet = 1;
                continue;
            }
            if (flags & 0x10000) {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedAlt;
                ((PrimQueueNode *)queueNode)->argument.data = objectResources;
                PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), (u8 *)((ResrcRecord *)(objectResources))->modelHandle158);
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedAlt;
                ((PrimQueueNode *)queueNode)->argument.data = objectResources;
                PrimAppendNode(D_007945A0, queueNode);
                mdlQueueModelForDraw(D_007945A0, (u8 *)((ResrcRecord *)(objectResources))->modelHandle158);
            }
        }
        objectResources = (u8 *)((ResrcRecord *)(objectResources))->next;
    }
    if (hasObjectDrawSet == 1) {
        u8 *resource = MT_Scene_GetResListHead(2);
        resourceRecord = (ResrcRecord *)resource;

        while (resource != NULL) {
            if (!((s32)((ResrcRecord *)(resource))->flags & 0x04000000)) {
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D1F30;
                PrimAppendNode((void *)(D_00793E80 + ((ResrcRecord *)(resource))->objectDrawSet * 0x30), queueNode);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedAlt;
                ((PrimQueueNode *)queueNode)->argument.data = resource;
                PrimAppendNode((void *)(D_00793E80 + resourceRecord->objectDrawSet * 0x30), queueNode);
                mdlQueueModelForDraw((void *)(D_00793E80 + resourceRecord->objectDrawSet * 0x30), (u8 *)((ResrcRecord *)(resource))->modelHandle158);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D1F30;
                PrimAppendNode((void *)(D_00793E80 + resourceRecord->objectDrawSet * 0x30), queueNode);
                resource = (u8 *)((ResrcRecord *)(resource))->next;
                resourceRecord = (ResrcRecord *)resource;
            }
        }
    }
    if (((SceneContext *)iGpffff9db0)->sortNpcs == 1) {
        qsort(translucentNpcs, translucentCount, 4, resrcMngCompareDistanceArrB);
    }
    if (translucentCount != 0) {
        queueNode = PrimAllocQueueNode();
        ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraSlots;
        ((PrimQueueNode *)queueNode)->argument.data = NULL;
        PrimAppendNode(D_007945D0, queueNode);
    }
    {
        for (sortedIndex = translucentCount - 1; sortedIndex >= 0; sortedIndex--) {
            s32 flags;

            sortedEntry = &translucentNpcs[sortedIndex];
            flags = (s32)((ResrcRecord *)(*sortedEntry))->flags;
            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                mdlQueueModelForDraw(D_007945D0, (u8 *)((ResrcRecord *)(*sortedEntry))->modelHandle164);
                entryCursor = (u8 *)sortedEntry;
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = *(u8 **)entryCursor;
                    if (((ResrcRecord *)(attachmentOwner))->slotHandleValue[attachmentIndex] != 0) {
                        if (mdlComputeIndexedAttachMatrix(((ResrcRecord *)(attachmentOwner))->modelHandle164, 2, &pos) == 0) {
                            pos = ((struct RwMatrix *)((u8 *)mdlGetMatrix(((ResrcRecord *)(*(u8 **)entryCursor))->modelHandle164)))->pos;
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(((ResrcRecord *)(*(u8 **)entryCursor))->slotHandle[attachmentIndex], (f32 *)&pos);
                    }
                }
            }
        }
    }    {
        for (sortedIndex = translucentCount - 1; sortedIndex >= 0; sortedIndex--) {
            s32 flags = (s32)((ResrcRecord *)(translucentNpcs[sortedIndex]))->flags;

            if ((flags & 0x10000000) && (flags & 2) && (flags & 0x80000000)) {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedPair;
                ((PrimQueueNode *)queueNode)->argument.data = translucentNpcs[sortedIndex];
                PrimAppendNode(D_007945D0, queueNode);
                mdlQueueModelForDraw(D_007945D0, (u8 *)((ResrcRecord *)(translucentNpcs[sortedIndex]))->modelHandle164);
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = translucentNpcs[sortedIndex];
                    if (((ResrcRecord *)(attachmentOwner))->slotHandleValue[attachmentIndex] != 0) {
                        if (mdlComputeIndexedAttachMatrix(((ResrcRecord *)(attachmentOwner))->modelHandle164, 2, &pos) == 0) {
                            pos = ((struct RwMatrix *)((u8 *)mdlGetMatrix(((ResrcRecord *)(translucentNpcs[sortedIndex]))->modelHandle164)))->pos;
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(((ResrcRecord *)(translucentNpcs[sortedIndex]))->slotHandle[attachmentIndex], (f32 *)&pos);
                    }
                }
            }
        }
    }
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D21F0;
    PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D2140;
    PrimAppendNode(D_007945D0, queueNode);
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
    ((PrimQueueNode *)queueNode)->argument.data = D_007D1FE0;
    PrimAppendNode(D_007945A0, queueNode);
    return 0;
}

#pragma pop
/* The incoming parent is forwarded to the task allocator, which attaches the new task when it is
 * non-null. */
// FUN_00149620
u8 *resrcMngSpawnRenderTask(u8 *parentTask) {
    u8 *task;

    task = kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005EFB10), 0xC7, 0, 0, resrcMngRenderTask, 0, (u8 *)(NULL));
    FldShadow_SpawnCasterTask(task);
    return task;
}

// FUN_00149680
void resrcMngSetRenderSuppressed(s32 suppressed) {
    D_007642E4 = suppressed;
}

/* Choose the normal or alternate resource draw queues (indices 15 and 29). */
// FUN_00149690
void resrcMngSelectDrawSet(s32 alternate) {
    if (alternate == 0) {
        iGpffff9dd0 = 0xF;
        return;
    }
    iGpffff9dd0 = 0x1D;
}

/* Applies the four color factors to scene resources, camera clear color and fog color, clamping
 * unsigned channel products at 255. */
// FUN_001496C0
void resrcMngApplyColorFactors(void *value) {
    const u8 *factors;
    /* Measured: this typed local keeps the original call-crossing factor address lifetime. */
    RadarColorReal *colorFactors;
    ResrcRecord *resourceRecord;
    u8 *resource;
    u32 fogColor;
    u8 *colorBytes;
    P4Bytes0014 color;
    f32 redFactor;
    f32 greenFactor;
    f32 blueFactor;
    f32 alphaFactor;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u32 fogRed;
    u32 fogGreen;
    u32 fogBlue;
    u32 fogAlpha;
    factors = (const u8 *)value;
    colorFactors = (RadarColorReal *)factors;
    resource = MT_Scene_GetResListHead(0xC);
    resourceRecord = (ResrcRecord *)resource;
    while (resource != NULL) {
        MT_Scene_ScaleResColors((u32 *)((ResrcRecord *)(resource))->handle1A0, (const f32 *)factors);
        resource = (u8 *)((ResrcRecord *)(resource))->next;
        resourceRecord = (ResrcRecord *)resource;
    }
    if ((((RadarColorReal *)factors)->r <= 0.0f && ((RadarColorReal *)factors)->g <= 0.0f && ((RadarColorReal *)factors)->b <= 0.0f) || ((RadarColorReal *)(factors))[0].a <= 0.0f) {
        resrcMngSetDrawEnabled(0, 1);
    } else {
        resrcMngSetDrawEnabled(1, 1);
    }
    colorBytes = (u8 *)kwlnGetColorBytes();
    color = *(const P4Bytes0014 *)colorBytes;
    fogColor = iGpffffba64 | (((u32)iGpffffba60 << 8) | (((u32)iGpffffba68 << 0x18) | ((u32)iGpffffba5c << 0x10)));
    redFactor = (f32)color.b0;
    red = (u32)(redFactor * ((RadarColorReal *)factors)->r);
    greenFactor = (f32)color.b1;
    green = (u32)(greenFactor * ((RadarColorReal *)factors)->g);
    blueFactor = (f32)color.b2;
    blue = (u32)(blueFactor * ((RadarColorReal *)factors)->b);
    alphaFactor = (f32)color.b3;
    alpha = (u32)(alphaFactor * ((RadarColorReal *)factors)->a);
    if (alpha > 0xFF) { alpha = 0xFF; }
    if (blue > 0xFF) { blue = 0xFF; }
    if (green > 0xFF) { green = 0xFF; }
    if (red > 0xFF) { red = 0xFF; }
    kwlnSetColorRgba(red & 0xFF, green & 0xFF, blue & 0xFF, alpha & 0xFF);
    fogRed = (fogColor >> 0x10) & 0xFF;
    redFactor = (f32)fogRed;
    fogRed = (u32)(redFactor * ((RadarColorReal *)factors)->r);
    fogGreen = (fogColor >> 8) & 0xFF;
    greenFactor = (f32)fogGreen;
    fogGreen = (u32)(greenFactor * colorFactors->g);
    fogBlue = fogColor & 0xFF;
    blueFactor = (f32)fogBlue;
    fogBlue = (u32)(blueFactor * colorFactors->b);
    fogAlpha = (fogColor >> 0x18) & 0xFF;
    alphaFactor = (f32)fogAlpha;
    fogAlpha = (u32)(alphaFactor * colorFactors->a);
    if (fogRed > 0xFF) { fogRed = 0xFF; }
    iGpffffba4c = (u8)fogRed;
    if (fogGreen > 0xFF) { fogGreen = 0xFF; }
    iGpffffba50 = (u8)fogGreen;
    if (fogBlue > 0xFF) { fogBlue = 0xFF; }
    iGpffffba54 = (u8)fogBlue;
    if (fogAlpha > 0xFF) { fogAlpha = 0xFF; }
    iGpffffba58 = (u8)fogAlpha;
}

/* Return the first field resource primary color, or NULL when the list is empty. */
// FUN_00149CA0
u8 *resrcMngGetColorValue(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)((SceneEnvironmentResource *)resource)->colorValue;
}

/* Return the first field resource secondary color, or NULL when the list is empty. */
// FUN_00149CE0
u8 *resrcMngGetColorTarget(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)((SceneEnvironmentResource *)resource)->colorTarget;
}

/* Return the first field resource light transform, or NULL when the list is empty. */
// FUN_00149D20
u8 *resrcMngGetTransform(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)&((SceneEnvironmentResource *)resource)->transform;
}

/* Forward the primary value through the active scene environment handle. */
// FUN_00149D60
void resrcMngSetEnvPrimary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetPrimary(((SceneContext *)D_00762EA0)->environment, value);
}

/* Forward the secondary value through the active scene environment handle. */
// FUN_00149DB0
void resrcMngSetEnvSecondary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetSecondary(((SceneContext *)D_00762EA0)->environment, value);
}

/* Forward the tertiary value through the active scene environment handle. */
// FUN_00149E00
void resrcMngSetEnvTertiary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetTertiary(((SceneContext *)D_00762EA0)->environment, value);
}

/* Forward the intensity value through the active scene environment handle. */
// FUN_00149E50
void resrcMngSetEnvIntensity(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetIntensity(((SceneContext *)D_00762EA0)->environment, value);
}

// FUN_00149EA0
/* Reset field lighting colors and rotate the default light transform around Y then X. */
void resrcMngResetRenderSlots(void)
{
    extern f32 fGpffff8198;
    extern void RwMatrixRotate(void *, void *, s32, f32 fparg0);
    s32 axisWords[3];
    f32 primaryValue;
    u8 *primaryResource;
    u8 *secondaryResource;
    u8 *matrixResource;
    u8 *primaryColor;
    u8 *secondaryColor;
    u8 *matrix;

    primaryResource = MT_Scene_GetResListHead(0xC);
    if (primaryResource == NULL) {
        primaryColor = NULL;
    } else {
        primaryColor = (u8 *)((SceneEnvironmentResource *)primaryResource)->colorValue;
    }
    secondaryResource = MT_Scene_GetResListHead(0xC);
    if (secondaryResource == NULL) {
        secondaryColor = NULL;
    } else {
        secondaryColor = (u8 *)((SceneEnvironmentResource *)secondaryResource)->colorTarget;
    }
    matrixResource = MT_Scene_GetResListHead(0xC);
    if (matrixResource == NULL) {
        matrix = NULL;
    } else {
        matrix = (u8 *)&((SceneEnvironmentResource *)matrixResource)->transform;
    }
    primaryValue = fGpffff8198;
    ((SceneLightingState *)primaryColor)->primary[0] = primaryValue;
    ((SceneLightingState *)primaryColor)->primary[1] = primaryValue;
    ((SceneLightingState *)primaryColor)->primary[2] = primaryValue;
    *(s32 *)&((SceneLightingState *)primaryColor)->primary[3] = 0;
    *(s32 *)&((SceneLightingState *)secondaryColor)->primary[0] = 0x3F000000;
    *(s32 *)&((SceneLightingState *)secondaryColor)->primary[1] = 0x3F000000;
    *(s32 *)&((SceneLightingState *)secondaryColor)->primary[2] = 0x3F000000;
    *(s32 *)&((SceneLightingState *)secondaryColor)->primary[3] = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->at.z = 0x3F800000;
    *(s32 *)&((struct RwMatrix *)matrix)->up.y = 0x3F800000;
    *(s32 *)&((struct RwMatrix *)matrix)->right.x = 0x3F800000;
    *(s32 *)&((struct RwMatrix *)matrix)->up.x = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->right.z = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->right.y = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->at.y = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->at.x = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->up.z = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->pos.z = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->pos.y = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->pos.x = 0;
    *(s32 *)&((struct RwMatrix *)matrix)->flags = *(s32 *)&((struct RwMatrix *)matrix)->flags | 0x20003;
    axisWords[0] = 0;
    axisWords[1] = 0x3F800000;
    axisWords[2] = 0;
    RwMatrixRotate(matrix, &axisWords[0], 2, -180.0f);
    axisWords[0] = 0x3F800000;
    axisWords[1] = 0;
    axisWords[2] = 0;
    RwMatrixRotate(matrix, &axisWords[0], 2, -45.0f);
}

/* measured: retail hoists loop-invariant constants out of the resource list loops in
 * resrcMngSetDrawEnabled. */
#pragma opt_loop_invariants on
// FUN_0014A000
/* Set the draw-active bit on field resources and optionally field-model resources. */
void resrcMngSetDrawEnabled(s32 enabled, s32 includeFieldModels)
{
    u8 *fieldResource;
    u8 *fieldModel;
    s32 one;
    s32 mask;
    fieldResource = MT_Scene_GetResListHead(0xC);
    fieldModel = MT_Scene_GetResListHead(0xA);
    one = 1;
    mask = -3;
    goto loop_5_test;
loop_5_body:
    if (enabled == one) {
        *(s32 *)&((ResrcHeader *)fieldResource)->flags = *(s32 *)&((ResrcHeader *)fieldResource)->flags | 2;
    } else {
        *(s32 *)&((ResrcHeader *)fieldResource)->flags = *(s32 *)&((ResrcHeader *)fieldResource)->flags & mask;
    }
    fieldResource = *(u8 * *)&((ResrcHeader *)fieldResource)->next;
loop_5_test:
    if (fieldResource != NULL) {
        goto loop_5_body;
    }
    if (includeFieldModels != one) {
        goto done;
    }
    goto loop_12_test;
loop_12_body:
    if (enabled == one) {
        *(s32 *)&((ResrcHeader *)fieldModel)->flags = *(s32 *)&((ResrcHeader *)fieldModel)->flags | 2;
    } else {
        *(s32 *)&((ResrcHeader *)fieldModel)->flags = *(s32 *)&((ResrcHeader *)fieldModel)->flags & mask;
    }
    fieldModel = *(u8 * *)&((ResrcHeader *)fieldModel)->next;
loop_12_test:
    if (fieldModel != NULL) {
        goto loop_12_body;
    }
done:
    ;
}

