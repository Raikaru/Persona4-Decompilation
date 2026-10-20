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




/* Camp display: grid, labels, radar and corner sprites.
 * The radar callees are declared here with u8 opacity parameters (H011):
 * retail narrows each radar alpha with its unsigned conversion and passes
 * it without another mask, while the matched definitions in this file keep
 * s32 because their own bodies use the full word.
 * `sprite` is one function-scope variable for the 0x1834 label sprite and
 * the corner sprite; b210 does not propagate it into the sdkSpriteDrawSized
 * call, so the label pointer is loaded before the stack argument. */
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






/* measured: closes the scoped optimization-level-1 probe. */


#pragma push
#pragma pop



#pragma push
#pragma pop

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 00147530-0014a000 */

/* measured: O1 probe for 00146630 register allocation and short tail. */
/* measured: schedule-off probe for 46630 branch delay slots. */
/* measured: closes schedule-off probe for 46630. */
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
        if (*(u16 *)resource == packedId) {
            return resource;
        }
        resource = *(u8 * *)&((SceneUpdateResource *)resource)->next;
    }
    return NULL;
}

// FUN_001475C0
/* Ported from P3FES resrcMngGetTotalResInList: P4 uses a 0x16-entry list
   table and the list link remains at offset 0x138. */
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
        currRes = *(u8 * *)&((SceneUpdateResource *)currRes)->next;
    }
    return total;
}

// FUN_00147620
u8 *resrcMngGetTableEntry(s32 curveKind) {
    return D_005EFAA0 + curveKind * 0x10;
}

/* measured probe: opt_propagation off for 00147640 float ordering. */
/* measured: resrcMngRenderCameraFog MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
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

/* measured probe: restore opt_propagation after 00147640. */
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

/* measured probe: opt_propagation off for 00147910 float and vtable order. */
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

/* measured probe: restore opt_propagation after 00147910. */
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

// FUN_00147BB0
/* Select character lighting from global or per-resource colors according to the upper flag bits. */
void resrcMngRenderAttached(u8 *unusedQueue, u8 *resource) {
    s32 flags;
    u8 *lightResource;

    lightResource = MT_Scene_GetResListHead(4);
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), lightResource + 0x140);
    func_003c38b0(K_Clump_GetLightC(), lightResource + 0x150);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, lightResource + 0x160, 0);
    flags = *(s32 *)&((SceneUpdateResource *)resource)->flags;
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

// FUN_00147D80
/* Install the type-5 NPC lighting resource colors and matrices. */
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

// FUN_00147E60
/* Install the NPC resource-specific primary, tertiary and secondary lighting. */
void resrcMngRenderAttachedPair(u8 *unusedQueue, u8 *resource) {
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), resource + 0x168);
    func_003c38b0(K_Clump_GetLightC(), resource + 0x178);
    func_003c38b0(K_Clump_GetLightB(), resource + 0x1D0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, resource + 0x190, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1E0, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

// FUN_00147F30
/* Install the object-model resource lighting, whose tail precedes the character tail by twelve bytes. */
void resrcMngRenderAttachedAlt(u8 *unusedQueue, u8 *resource) {
    func_003e8110(((u8 *)(u32)kwlnGetCamera()));
    func_003c38b0(K_Clump_GetLightA(), resource + 0x15C);
    func_003c38b0(K_Clump_GetLightC(), resource + 0x16C);
    func_003c38b0(K_Clump_GetLightB(), resource + 0x1C0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightC())->frame, resource + 0x180, 0);
    func_003e9cb0(((SceneRenderLight *)K_Clump_GetLightB())->frame, resource + 0x1D0, 0);
    func_003e8120(((u8 *)(u32)kwlnGetCamera()));
}

/* measured probe: opt_propagation off preserves 00148000 vector coloring. */
// FUN_00148000
/* Compare character-model distances from the camera using a truncated signed difference. */
/* Compare character-model distances from the camera using a truncated signed difference. Keep resource-member byte accesses: the typed rewrite retained member addresses across callbacks and exceeded the retail window; scene_resource_internal.h records the proven layout. */
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
    frame.leftDelta[0] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.x - frame.cameraPosition[0];
    cameraY = frame.cameraPosition[1];
    frame.leftDelta[1] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.y - cameraY;
    distanceOrCameraZ = frame.cameraPosition[2];
    frame.leftDelta[2] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.z - distanceOrCameraZ;
    frame.rightDelta[0] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.x - frame.cameraPosition[0];
    frame.rightDelta[1] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.y - cameraY;
    frame.rightDelta[2] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.z - distanceOrCameraZ;
    distanceOrCameraZ = RwV3dLength(frame.leftDelta);
    return (s32)(distanceOrCameraZ - RwV3dLength(frame.rightDelta));
}

/* measured: closes opt_propagation off for resrcMngCompareDistanceArrA. */
/* measured: opt_propagation off preserves 00148140 vector coloring. */
// FUN_00148140
/* Compare NPC-model distances from the camera using a truncated signed difference. */
/* Compare NPC-model distances from the camera using a truncated signed difference. Keep resource-member byte accesses: the typed rewrite retained member addresses across callbacks and exceeded the retail window; scene_resource_internal.h records the proven layout. */
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
    frame.leftDelta[0] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.x - frame.cameraPosition[0];
    cameraY = frame.cameraPosition[1];
    frame.leftDelta[1] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.y - cameraY;
    distanceOrCameraZ = frame.cameraPosition[2];
    frame.leftDelta[2] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(leftResource + 0x164)))->pos.z - distanceOrCameraZ;
    frame.rightDelta[0] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.x - frame.cameraPosition[0];
    frame.rightDelta[1] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.y - cameraY;
    frame.rightDelta[2] = ((struct RwMatrix *)mdlGetMatrix(*(void **)(rightResource + 0x164)))->pos.z - distanceOrCameraZ;
    distanceOrCameraZ = RwV3dLength(frame.leftDelta);
    return (s32)(distanceOrCameraZ - RwV3dLength(frame.rightDelta));
}

/* measured: closes opt_propagation off for resrcMngCompareDistanceArrB. */
/* measured: resrcMngRenderTask, resrcMngSetDrawEnabled MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* Recovered render passes preserve callback-time resource reloads and
   complete position-vector copies. The two tail k-loops share
   function-scope `k`/`j` (declared k first) under `opt_lifetimes on`, so
   IRO_SplitLifetimes numbers each loop's counters after the hoisted
   `&arrB[k]` temporaries. The first tail loop walks its attachments through
   `cur = (u8 *)ent`; that copy keeps `ent = &arrB[k]` a declared local, which
   is retail's $s4. See docs/probe_archive/RenderQueue_00148280_worker1_20261005.md. */
#pragma push
/* measured: resrcMngRenderTask MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: resrcMngRenderTask MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// FUN_00148280
/* Queue the resource-kind-specific draw passes and sorted translucent resources. Keep resource-member byte accesses: the typed rewrite retained member addresses across callbacks and exceeded the retail window; scene_resource_internal.h records the proven layout. */
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
    fieldModels = MT_Scene_GetResListHead(0xA);
    effectResources = MT_Scene_GetResListHead(0xB);
    characterResources = MT_Scene_GetResListHead(1);
    npcResources = MT_Scene_GetResListHead(3);
    objectResources = MT_Scene_GetResListHead(2);
    alternateQueues = 0;
    if (D_007642E4 == 1) {
        return 0;
    }
    if (*(s32 *)iGpffff9db0 >= 0xC8) {
        alternateQueues = 1;
    }
    while (effectResources != NULL) {
        if (*(s32 *)(effectResources + 0x28) & 2) {
            mdlEffectAdvanceAndFlushWithTable(D_005DC7D0, *(void **)(effectResources + 0x144));
        }
        effectResources = *(u8 **)(effectResources + 0x138);
    }
    while (fieldResources != NULL) {
        if (*(s32 *)(fieldResources + 0x28) & 2) {
            FldResource_QueueDrawCallbacks(D_00793EE0, *(u8 **)(fieldResources + 0x1A0));
            if (alternateQueues != 0) {
                FldResource_QueueDrawCallbacksPrimary(D_00793F70, *(u8 **)(fieldResources + 0x1A0));
                FldResource_QueueDrawCallbacksSecondary(D_00793F70, *(u8 **)(fieldResources + 0x1A0));
            } else {
                FldResource_QueueDrawCallbacksPrimary(D_00794390, *(u8 **)(fieldResources + 0x1A0));
                FldResource_QueueDrawCallbacksSecondary(D_00794390, *(u8 **)(fieldResources + 0x1A0));
            }
        }
        fieldResources = *(u8 **)(fieldResources + 0x138);
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
        resourceFlags = *(s32 *)(fieldModels + 0x28);
        if (resourceFlags & 2) {
            if (resourceFlags & 0x02000000) {
                mdlQueueModelForDraw(D_007942D0, *(u8 **)(fieldModels + 0x144));
            } else if (resourceFlags & 0x01000000) {
                mdlQueueModelForDraw(D_007947E0, *(u8 **)(fieldModels + 0x144));
            } else if (K_Clump_StateFlagIsSet(*(const u32 **)(*(u8 **)(fieldModels + 0x144) + 0xE0)) == 1) {
                if (alternateQueues != 0) {
                    mdlQueueModelForDraw(D_00793F10, *(u8 **)(fieldModels + 0x144));
                } else {
                    mdlQueueModelForDraw(D_00794300, *(u8 **)(fieldModels + 0x144));
                }
                attachedModel = *(u8 **)(fieldModels + 0x16C);
                if (attachedModel != NULL && (*(s32 *)(fieldModels + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794300, attachedModel);
                }
            } else if (hMaestroListSetHasEntries(*(u8 **)(*(u8 **)(fieldModels + 0x144) + 0xE0)) == 1) {
                if (alternateQueues != 0) {
                    mdlQueueModelForDraw(D_00793F40, *(u8 **)(fieldModels + 0x144));
                } else {
                    mdlQueueModelForDraw(D_00794360, *(u8 **)(fieldModels + 0x144));
                }
                attachedModel = *(u8 **)(fieldModels + 0x16C);
                if (attachedModel != NULL && (*(s32 *)(fieldModels + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794360, attachedModel);
                }
            } else {
                mdlQueueModelForDraw(D_00793EE0, *(u8 **)(fieldModels + 0x144));
                attachedModel = *(u8 **)(fieldModels + 0x16C);
                if (attachedModel != NULL && (*(s32 *)(fieldModels + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00793EE0, attachedModel);
                }
            }
        }
        fieldModels = *(u8 **)(fieldModels + 0x138);
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
        characterResources = *(u8 **)(characterResources + 0x138);
        characterCount += 1;
    }
    if (*(s32 *)(iGpffff9db0 + 0x14) == 1) {
        qsort(characters, characterCount, 4, resrcMngCompareDistanceArrA);
    }
    hasCharacterDrawSet = 0;
    for (characterIndex = (s32)(characterCount - 1); characterIndex >= 0; characterIndex--) {
        u8 **characterEntry = &characters[characterIndex];
        s32 flags = *(s32 *)(*characterEntry + 0x28);

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
                    mdlQueueModelForDraw(D_007943F0, *(u8 **)(*characterEntry + 0x164));
                } else {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*characterEntry + 0x164));
                }
                if (*(u8 **)(*characterEntry + 0x228) != NULL && (*(s32 *)(*characterEntry + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*characterEntry + 0x228));
                }
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = *characterEntry;
                    if (*(s32 *)(attachmentOwner + attachmentIndex * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(*characterEntry + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(*(void **)(*characterEntry + attachmentIndex * 4 + 0x140), (f32 *)&pos);
                        mdlEffectFlushWithTable(D_005DC824, *(void **)(*characterEntry + attachmentIndex * 4 + 0x140));
                    }
                }
            }
        }
    }
    if (hasCharacterDrawSet == 1) {
        u8 *resource = MT_Scene_GetResListHead(1);

        while (resource != NULL) {
            if (!(*(s32 *)(resource + 0x28) & 0x04000000)) {
                resource = *(u8 **)(resource + 0x138);
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D2090;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x22C) * 0x30), queueNode);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttached;
                ((PrimQueueNode *)queueNode)->argument.data = resource;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x22C) * 0x30), queueNode);
                mdlQueueModelForDraw((void *)(D_00793E80 + *(s32 *)(resource + 0x22C) * 0x30), *(u8 **)(resource + 0x164));
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D2090;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x22C) * 0x30), queueNode);
                resource = *(u8 **)(resource + 0x138);
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
        if (*(u8 *)((u8 *)mdlGetColor(*(void **)(npcResources + 0x164)) + 3) < 0xFF) {
            translucentNpcs[translucentCount] = npcResources;
            translucentCount += 1;
            npcResources = *(u8 **)(npcResources + 0x138);
        } else {
            s32 flags = *(s32 *)(npcResources + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                s32 attachmentIndex;

                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(npcResources + 0x164));
                if (*(u8 **)(npcResources + 0x22C) != NULL && (*(s32 *)(npcResources + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(npcResources + 0x22C));
                }
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    if (*(s32 *)(npcResources + attachmentIndex * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(npcResources + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(npcResources + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(*(void **)(npcResources + attachmentIndex * 4 + 0x140), (f32 *)&pos);
                        mdlEffectFlushWithTable(D_005DC824, *(void **)(npcResources + attachmentIndex * 4 + 0x140));
                    }
                }
            }
            npcResources = *(u8 **)(npcResources + 0x138);
        }
    }
    {
        u8 *resource = MT_Scene_GetResListHead(3);

        while (resource != NULL) {
            if (*(u8 *)((u8 *)mdlGetColor(*(void **)(resource + 0x164)) + 3) < 0xFF) {
                resource = *(u8 **)(resource + 0x138);
            } else {
                s32 flags = *(s32 *)(resource + 0x28);

                if ((flags & 0x10000000) && (flags & 2)) {
                    queueNode = PrimAllocQueueNode();
                    ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedPair;
                    ((PrimQueueNode *)queueNode)->argument.data = resource;
                    PrimAppendNode((void *)(D_00793E80 + iGpffff9dd0 * 0x30), queueNode);
                    if (*(s32 *)(resource + 0x28) & 0x80000000) {
                        s32 attachmentIndex;

                        mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(resource + 0x164));
                        if (*(u8 **)(resource + 0x22C) != NULL && (*(s32 *)(resource + 0x28) & 0x20000000)) {
                            mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(resource + 0x22C));
                        }
                        for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                            if (*(s32 *)(resource + attachmentIndex * 4 + 0x140) != 0) {
                                if (mdlComputeIndexedAttachMatrix(*(void **)(resource + 0x164), 2, &pos) == 0) {
                                    pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(resource + 0x164)) + 0x30);
                                    pos.y += 175.0f;
                                }
                                mdlEffectSetChildPositionVec(*(void **)(resource + attachmentIndex * 4 + 0x140), (f32 *)&pos);
                                mdlEffectFlushWithTable(D_005DC824, *(void **)(resource + attachmentIndex * 4 + 0x140));
                            }
                        }
                    }
                }
                resource = *(u8 **)(resource + 0x138);
            }
        }
    }
    hasObjectDrawSet = 0;
    while (objectResources != NULL) {
        s32 flags = *(s32 *)(objectResources + 0x28);

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
                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(objectResources + 0x158));
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedAlt;
                ((PrimQueueNode *)queueNode)->argument.data = objectResources;
                PrimAppendNode(D_007945A0, queueNode);
                mdlQueueModelForDraw(D_007945A0, *(u8 **)(objectResources + 0x158));
            }
        }
        objectResources = *(u8 **)(objectResources + 0x138);
    }
    if (hasObjectDrawSet == 1) {
        u8 *resource = MT_Scene_GetResListHead(2);

        while (resource != NULL) {
            if (!(*(s32 *)(resource + 0x28) & 0x04000000)) {
                resource = *(u8 **)(resource + 0x138);
            } else {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraFade;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D1F30;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x210) * 0x30), queueNode);
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedAlt;
                ((PrimQueueNode *)queueNode)->argument.data = resource;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x210) * 0x30), queueNode);
                mdlQueueModelForDraw((void *)(D_00793E80 + *(s32 *)(resource + 0x210) * 0x30), *(u8 **)(resource + 0x158));
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderCameraPair;
                ((PrimQueueNode *)queueNode)->argument.data = D_007D1F30;
                PrimAppendNode((void *)(D_00793E80 + *(s32 *)(resource + 0x210) * 0x30), queueNode);
                resource = *(u8 **)(resource + 0x138);
            }
        }
    }
    if (*(s32 *)(iGpffff9db0 + 0x18) == 1) {
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
            flags = *(s32 *)(*sortedEntry + 0x28);
            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                mdlQueueModelForDraw(D_007945D0, *(u8 **)(*sortedEntry + 0x164));
                entryCursor = (u8 *)sortedEntry;
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = *(u8 **)entryCursor;
                    if (*(s32 *)(attachmentOwner + attachmentIndex * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(*(u8 **)entryCursor + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(*(void **)(*(u8 **)entryCursor + attachmentIndex * 4 + 0x140), (f32 *)&pos);
                    }
                }
            }
        }
    }    {
        for (sortedIndex = translucentCount - 1; sortedIndex >= 0; sortedIndex--) {
            s32 flags = *(s32 *)(translucentNpcs[sortedIndex] + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && (flags & 0x80000000)) {
                queueNode = PrimAllocQueueNode();
                ((PrimQueueNode *)queueNode)->callback = (void *)resrcMngRenderAttachedPair;
                ((PrimQueueNode *)queueNode)->argument.data = translucentNpcs[sortedIndex];
                PrimAppendNode(D_007945D0, queueNode);
                mdlQueueModelForDraw(D_007945D0, *(u8 **)(translucentNpcs[sortedIndex] + 0x164));
                for (attachmentIndex = 0; attachmentIndex < 2; attachmentIndex++) {
                    u8 *attachmentOwner = translucentNpcs[sortedIndex];
                    if (*(s32 *)(attachmentOwner + attachmentIndex * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(translucentNpcs[sortedIndex] + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        mdlEffectSetChildPositionVec(*(void **)(translucentNpcs[sortedIndex] + attachmentIndex * 4 + 0x140), (f32 *)&pos);
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
/* The incoming parent is forwarded to the task allocator, which attaches
   the new task when it is non-null. The constructor remains 96/96 bytes. */
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

// FUN_00149690
/* Select normal or alternate draw queues (indices 15 and 29). */
void resrcMngSelectDrawSet(s32 alternate) {
    if (alternate == 0) {
        iGpffff9dd0 = 0xF;
        return;
    }
    iGpffff9dd0 = 0x1D;
}

/* Applies the four color factors to scene resources, camera clear color
   and fog color. Keep the four-byte color snapshot and unsigned
   float conversions before each upper clamp. Native b210 -O2:
   1504/1504 bytes, all relocations exact, no padding or inline asm.
   See Retained_color_and_sphere_20260922_worker6.md. */
// FUN_001496C0
/* Queue the resource-kind-specific draw passes and sorted translucent resources. Keep resource-member byte accesses: the typed rewrite retained member addresses across callbacks and exceeded the retail window; scene_resource_internal.h records the proven layout. */
/* Color factors retain byte-addressed loads: array/typed access grew b210 code from 1504 to 1528 bytes by changing call-crossing address lifetimes. Resource offsets are documented in scene_resource_internal.h. */
void resrcMngApplyColorFactors(void *value) {
    const u8 *factors;
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
    resource = MT_Scene_GetResListHead(0xC);
    while (resource != NULL) {
        MT_Scene_ScaleResColors(*(u32 **)(resource + 0x1A0), (const f32 *)factors);
        resource = *(u8 **)(resource + 0x138);
    }
    if ((*(f32 *)(factors + 0) <= 0.0f && *(f32 *)(factors + 4) <= 0.0f && *(f32 *)(factors + 8) <= 0.0f) || *(f32 *)(factors + 0xC) <= 0.0f) {
        resrcMngSetDrawEnabled(0, 1);
    } else {
        resrcMngSetDrawEnabled(1, 1);
    }
    colorBytes = (u8 *)kwlnGetColorBytes();
    color = *(const P4Bytes0014 *)colorBytes;
    fogColor = iGpffffba64 | (((u32)iGpffffba60 << 8) | (((u32)iGpffffba68 << 0x18) | ((u32)iGpffffba5c << 0x10)));
    redFactor = (f32)color.b0;
    red = (u32)(redFactor * *(f32 *)(factors + 0));
    greenFactor = (f32)color.b1;
    green = (u32)(greenFactor * *(f32 *)(factors + 4));
    blueFactor = (f32)color.b2;
    blue = (u32)(blueFactor * *(f32 *)(factors + 8));
    alphaFactor = (f32)color.b3;
    alpha = (u32)(alphaFactor * *(f32 *)(factors + 0xC));
    if (alpha > 0xFF) { alpha = 0xFF; }
    if (blue > 0xFF) { blue = 0xFF; }
    if (green > 0xFF) { green = 0xFF; }
    if (red > 0xFF) { red = 0xFF; }
    kwlnSetColorRgba(red & 0xFF, green & 0xFF, blue & 0xFF, alpha & 0xFF);
    fogRed = (fogColor >> 0x10) & 0xFF;
    redFactor = (f32)fogRed;
    fogRed = (u32)(redFactor * *(f32 *)(factors + 0));
    fogGreen = (fogColor >> 8) & 0xFF;
    greenFactor = (f32)fogGreen;
    fogGreen = (u32)(greenFactor * *(f32 *)(factors + 4));
    fogBlue = fogColor & 0xFF;
    blueFactor = (f32)fogBlue;
    fogBlue = (u32)(blueFactor * *(f32 *)(factors + 8));
    fogAlpha = (fogColor >> 0x18) & 0xFF;
    alphaFactor = (f32)fogAlpha;
    fogAlpha = (u32)(alphaFactor * *(f32 *)(factors + 0xC));
    if (fogRed > 0xFF) { fogRed = 0xFF; }
    iGpffffba4c = (u8)fogRed;
    if (fogGreen > 0xFF) { fogGreen = 0xFF; }
    iGpffffba50 = (u8)fogGreen;
    if (fogBlue > 0xFF) { fogBlue = 0xFF; }
    iGpffffba54 = (u8)fogBlue;
    if (fogAlpha > 0xFF) { fogAlpha = 0xFF; }
    iGpffffba58 = (u8)fogAlpha;
}

// FUN_00149CA0
u8 *resrcMngGetColorValue(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)((SceneEnvironmentResource *)resource)->colorValue;
}

// FUN_00149CE0
u8 *resrcMngGetColorTarget(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)((SceneEnvironmentResource *)resource)->colorTarget;
}

// FUN_00149D20
u8 *resrcMngGetTransform(void) {
    u8 *resource;

    resource = MT_Scene_GetResListHead(0xC);
    if (resource == NULL) {
        return NULL;
    }
    return (u8 *)&((SceneEnvironmentResource *)resource)->transform;
}

// FUN_00149D60
/* Forward the primary environment value through the active scene environment handle. */
void resrcMngSetEnvPrimary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetPrimary(((SceneContext *)D_00762EA0)->environment, value);
}

// FUN_00149DB0
/* Forward the secondary environment value through the active scene environment handle. */
void resrcMngSetEnvSecondary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetSecondary(((SceneContext *)D_00762EA0)->environment, value);
}

// FUN_00149E00
/* Forward the tertiary environment value through the active scene environment handle. */
void resrcMngSetEnvTertiary(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetTertiary(((SceneContext *)D_00762EA0)->environment, value);
}

// FUN_00149E50
/* Forward the environment intensity through the active scene environment handle. */
void resrcMngSetEnvIntensity(s32 value)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetIntensity(((SceneContext *)D_00762EA0)->environment, value);
}

/* measured: opt_rebuildconditionals off is scoped to resrcMngResetRenderSlots. */
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

/* measured: closes opt_rebuildconditionals for resrcMngResetRenderSlots. */
/* measured: opt_rebuildconditionals off is scoped to resrcMngSetDrawEnabled. */
/* measured: loop-invariant constants probe for resrcMngSetDrawEnabled. */
/* measured: resrcMngSetDrawEnabled MATCH -> MISMATCH without this pragma. */
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
        *(s32 *)&((SceneUpdateResource *)fieldResource)->flags = *(s32 *)&((SceneUpdateResource *)fieldResource)->flags | 2;
    } else {
        *(s32 *)&((SceneUpdateResource *)fieldResource)->flags = *(s32 *)&((SceneUpdateResource *)fieldResource)->flags & mask;
    }
    fieldResource = *(u8 * *)&((SceneUpdateResource *)fieldResource)->next;
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
        *(s32 *)&((SceneUpdateResource *)fieldModel)->flags = *(s32 *)&((SceneUpdateResource *)fieldModel)->flags | 2;
    } else {
        *(s32 *)&((SceneUpdateResource *)fieldModel)->flags = *(s32 *)&((SceneUpdateResource *)fieldModel)->flags & mask;
    }
    fieldModel = *(u8 * *)&((SceneUpdateResource *)fieldModel)->next;
loop_12_test:
    if (fieldModel != NULL) {
        goto loop_12_body;
    }
done:
    ;
}

