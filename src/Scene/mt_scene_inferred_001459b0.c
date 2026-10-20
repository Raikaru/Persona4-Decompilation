#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "scene_resource_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw/plcore/barenderstate.h"
#include "scene_task_internal.h"

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



extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern void MT_Scene_DestroyRes(u16 resTypeId);
extern u8 *resrcMngCreateRes(s32 resManager, s32 resTypeId);
extern u8 *resrcMngFindResById(u8 *manager, u16 resourceId);
extern void Vpad_BuildRotatedQuad(u8 *vertices, const u8 *translation, f32 fparg0, f32 fparg1, f32 fparg2);
extern u8 *func_003e0f80(void);
extern void memcpy(void *dest, const void *src, s32 size);
extern void resrcMngDestroyRes();
extern void FldResource_Destroy(void *resource);
extern void MT_Scene_SpawnIconTask(void *effectHandle);
extern void func_003bbb60(s32);
extern void func_003e0f40(s32);
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
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void mdlEffectDestroy(s32 model);
extern void mdlDestroyModelObject(s32 model);
extern u8 D_007EF9B0[];
extern u8 D_007E8020[];

extern void func_00440b68();
extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
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
extern void sdkSpriteDrawSized(u8 *sprite, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 mdlEffectCreateFromResource(s32 resource);
extern void mdlEffectSetChildPositionVec(void *object, f32 *position);
extern void mdlEffectSetUniformScale(s32 effect, f32 scale);

extern s32 D_007642E4;
extern u8 D_005EFB10[];




typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;


extern s32 D_007642F0;








extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001459b0-00146a10 */

// FUN_001459B0
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
/* ResrcRecord effect slots 140/144 remain raw: typed members grew the matched body from 272 to 284 bytes across effect calls. */
s32 MT_Scene_CreateObjectRes(u16 resourceId, s32 model, s8 drawMode) {
    f32 initialPosition[3];
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x1800) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (model == 0) {
        func_00440b68(&D_005EF870);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)(resource + 0x144) = mdlEffectCreateFromResource(model);
    *(s8 *)(resource + 0x140) = drawMode;
    initialPosition[0] = 100.0f;
    initialPosition[1] = 0.0f;
    initialPosition[2] = 0.0f;
    mdlEffectSetChildPositionVec(*(void **)(resource + 0x144), initialPosition);
    mdlEffectSetUniformScale(*(s32 *)(resource + 0x144), 1.5f);
    return resourceTypeId;
}

// FUN_00145AC0
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreateModelFldRes(u16 resourceId, s32 model) {
    s8 zeroPosition[0xC];
    s32 resourceTypeId;
    s32 manager;
    s8 *clear;
    s32 remainingBytes;
    u8 *resource;

    clear = zeroPosition;
    remainingBytes = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            remainingBytes--;
        } while (remainingBytes != 0);
    }
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x2800) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (model == 0) {
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)&((ResrcRecord *)resource)->slotHandle[1] = model;
    *(s32 *)&((SceneUpdateResource *)resource)->flags = *(s32 *)&((SceneUpdateResource *)resource)->flags | 8;
    return resourceTypeId;
}

// FUN_00145BA0
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreateRes11(u16 resourceId, s32 model) {
    s8 zeroPosition[0xC];
    s32 resourceTypeId;
    s32 manager;
    s8 *clear;
    s32 remainingBytes;
    u8 *resource;

    clear = zeroPosition;
    remainingBytes = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            remainingBytes--;
        } while (remainingBytes != 0);
    }
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x2C00) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (model == 0) {
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)&((ResrcRecord *)resource)->slotHandle[1] = model;
    *(s32 *)&((SceneUpdateResource *)resource)->flags = *(s32 *)&((SceneUpdateResource *)resource)->flags | 8;
    return resourceTypeId;
}

// FUN_00145C80
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreateFldRes(u16 resourceId, s32 model) {
    s8 zeroPosition[0xC];
    s32 resourceTypeId;
    s32 manager;
    s8 *clear;
    s32 remainingBytes;
    u8 *resource;

    clear = zeroPosition;
    remainingBytes = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            remainingBytes--;
        } while (remainingBytes != 0);
    }
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x3000) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (model == 0) {
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    ((ResrcRecord *)resource)->handle1A0 = model;
    *(s32 *)&((SceneUpdateResource *)resource)->flags = *(s32 *)&((SceneUpdateResource *)resource)->flags | 8;
    return resourceTypeId;
}

// FUN_00145D60
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreateFldHitLight(u16 resourceId, f32 *position, f32 width, f32 height, f32 angle, FieldRgba8 rgba) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;
    Rgba8_0014 color;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x3400) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((SceneQuadResource *)resource)->center = point;
    ((SceneQuadResource *)resource)->width = width;
    ((SceneQuadResource *)resource)->height = height;
    ((SceneQuadResource *)resource)->angle = angle;
    color = rgba;
    *(Rgba8_0014 *)&((SceneQuadResource *)resource)->color = color;
    Vpad_BuildRotatedQuad(resource + 0x15C, (const u8 *)position, width, height, angle);
    *(s32 *)&((SceneUpdateResource *)resource)->flags = *(s32 *)&((SceneUpdateResource *)resource)->flags | 8;
    return resourceTypeId;
}

// FUN_00145E90
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreateRes21Light(u16 resourceId, f32 *position, f32 width, f32 height, f32 angle, FieldRgba8 rgba) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;
    Rgba8_0014 color;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x5400) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((SceneQuadResource *)resource)->center = point;
    ((SceneQuadResource *)resource)->width = width;
    ((SceneQuadResource *)resource)->height = height;
    ((SceneQuadResource *)resource)->angle = angle;
    color = rgba;
    *(Rgba8_0014 *)&((SceneQuadResource *)resource)->color = color;
    Vpad_BuildRotatedQuad(resource + 0x15C, (const u8 *)position, width, height, angle);
    *(s32 *)&((SceneUpdateResource *)resource)->flags = *(s32 *)&((SceneUpdateResource *)resource)->flags | 8;
    return resourceTypeId;
}

// FUN_00145FC0
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes14(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x3800) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_00146080
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes15(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x3C00) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_00146140
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes16(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x4000) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_00146200
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes17(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x4400) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_001462C0
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes18(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x4800) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_00146380
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
s32 MT_Scene_CreatePointRes19(u16 resourceId, f32 *position, f32 radius) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x4C00) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    point = *(SVec3 *)position;
    *(SVec3 *)&((ScenePointResource *)resource)->point = point;
    ((ScenePointResource *)resource)->radius = radius;
    *(s32 *)&((SceneUpdateResource *)resource)->flags |= 8;
    return resourceTypeId;
}

// FUN_00146440
/* Initialize the selected resource kind and return its packed type/id, or zero on allocation failure. */
/* SceneCaptureCameraResource documents this tail; typed members changed b210 matrix-copy lifetimes (234 differing bytes). */
s32 MT_Scene_CreateCameraRes(u16 resourceId, s32 cameraKind, f32 cameraValue, u8 *firstMatrixInput, u8 *secondMatrixInput, u8 *position, f32 nearValue, f32 farValue, s32 parameters, s32 data) {
    s32 resourceTypeId;
    s32 secondWord;
    s32 secondMatrixWord;
    s32 firstWord;
    s32 firstMatrixWord;
    s32 manager;
    u8 *resource;
    u8 *secondMatrix;
    u8 *firstMatrix;
    u8 *outputWords;
    u8 *secondOutputWords;
    s32 remainingPairs;
    s32 secondRemainingPairs;
    SVec3 point;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x5000) & 0xFFFF;
    firstMatrix = firstMatrixInput;
    secondMatrix = secondMatrixInput;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)(resource + 0x140) = cameraKind;
    *(f32 *)(resource + 0x144) = cameraValue;
    *(u8 **)(resource + 0x148) = func_003e0f80();
    if (firstMatrix != NULL) {
        outputWords = *(u8 **)(resource + 0x148);
        remainingPairs = 8;
        do {
            firstWord = *(s32 *)(firstMatrix + 0);
            secondWord = *(s32 *)(firstMatrix + 4);
            firstMatrix += 8;
            remainingPairs -= 1;
            *(s32 *)(outputWords + 0) = firstWord;
            *(s32 *)(outputWords + 4) = secondWord;
            outputWords += 8;
        } while (remainingPairs > 0);
    }
    *(u8 **)(resource + 0x14C) = func_003e0f80();
    if (secondMatrix != NULL) {
        secondOutputWords = *(u8 **)(resource + 0x14C);
        secondRemainingPairs = 8;
        do {
            firstMatrixWord = *(s32 *)(secondMatrix + 0);
            secondMatrixWord = *(s32 *)(secondMatrix + 4);
            secondMatrix += 8;
            secondRemainingPairs -= 1;
            *(s32 *)(secondOutputWords + 0) = firstMatrixWord;
            *(s32 *)(secondOutputWords + 4) = secondMatrixWord;
            secondOutputWords += 8;
        } while (secondRemainingPairs > 0);
    }
    if (position != NULL) {
        point = *(SVec3 *)position;
        *(SVec3 *)(resource + 0x150) = point;
    }
    *(f32 *)(resource + 0x15C) = nearValue;
    *(f32 *)(resource + 0x160) = farValue;
    if (parameters != 0) {
        memcpy(resource + 0x164, (const void *)parameters, 0x20);
    }
    if (data != 0) {
        memcpy(resource + 0x184, (const void *)data, 0x180);
    }
    *(s32 *)(resource + 0x28) = *(s32 *)(resource + 0x28) | 8;
    return resourceTypeId;
}

/* measured: O1 probe for 00146630 register allocation and short tail. */
/* measured: schedule-off probe for 46630 branch delay slots. */
// FUN_00146630
/* Release the resource-kind-specific owned handles before unlinking and freeing the record. */
void MT_Scene_DestroyRes(u16 resTypeId) {
    s32 slotValue;
    s32 resourceKind;
    s32 value1A0;
    s32 value288;
    s32 value360;
    s32 slotIndex;
    u8 *resourceOwner;
    u8 *handle164;
    u8 *handle158;
    u8 *handle144;
    u8 *slotAddr;
    u8 *slotAddrB;
    u8 *slotHandle;
    u8 *handle16C;
    u8 *handle144Case11;
    u8 *handle228;
    u8 *handle228Case3;
    u8 *handle22C;
    u8 *slotHandleB;
    u8 *handle290;
    u8 *handle144Case6;
    void **slotHandleAddr;
    ResrcRecord *resourceRecord;

    resourceOwner = *(u8 * *)&((SceneContext *)iGpffff9db0)->manager.handle;
    if (resourceOwner == NULL) {
        func_00440b68(&D_005EF820);
        return;
    }
    if (resourceOwner == NULL) {
        resourceRecord = NULL;
    } else {
        resourceRecord = (ResrcRecord *)resrcMngFindResById(resourceOwner, resTypeId);
    }
    if (resourceRecord != NULL) {
        resourceKind = RESRC_GET_TYPE(resourceRecord->resTypeId);
        switch (resourceKind) {
        case RESRC_TYPE_MODELCHAR:
            handle164 = resourceRecord->modelHandle164;
            kwlnTaskDestroyWithHierarchy(resourceRecord->handle220);
            resourceRecord->handle220 = 0;
            resourceRecord->handle224 = 0;
            resourceRecord->modelHandle164 = NULL;
            slotValue = 0;
            while (slotValue < 2) {
                slotAddr = (u8 *)&resourceRecord->slotHandle[slotValue];
                slotHandleAddr = (void **)slotAddr;
                slotHandle = *slotHandleAddr;
                if (slotHandle != NULL) {
                    mdlEffectDestroy((s32)slotHandle);
                    *slotHandleAddr = NULL;
                }
                slotValue += 1;
            }
            handle228 = resourceRecord->handle228;
            if (handle228 != NULL) {
                mdlDestroyModelObject((s32)handle228);
                resourceRecord->handle228 = NULL;
            }
            func_00440b68(&D_005EF890, handle164);
            break;
        case RESRC_TYPE_MODELUNK:
            handle158 = resourceRecord->modelHandle158;
            mdlDestroyModelObject((s32)handle158);
            resourceRecord->modelHandle158 = NULL;
            func_00440b68(&D_005EF890, handle158);
            break;
        case RESRC_TYPE_MODELNPC:
            slotValue = (s32)resourceRecord->modelHandle164;
            handle228Case3 = resourceRecord->handle228;
            if (handle228Case3 != NULL) {
                kwlnTaskDestroyWithHierarchy((s32)handle228Case3);
                resourceRecord->handle228 = NULL;
            }
            resourceRecord->handle230 = 0;
            resourceRecord->handle294 = 0;
            handle22C = resourceRecord->handle22C;
            if (handle22C != NULL) {
                mdlDestroyModelObject((s32)handle22C);
                resourceRecord->handle22C = NULL;
            }
            mdlDestroyModelObject((s32)slotValue);
            resourceRecord->modelHandle164 = NULL;
            slotIndex = 0;
            while (slotIndex < 2) {
                slotAddrB = (u8 *)&resourceRecord->slotHandle[slotIndex];
                slotHandleAddr = (void **)slotAddrB;
                slotHandleB = *slotHandleAddr;
                if (slotHandleB != NULL) {
                    mdlEffectDestroy((s32)slotHandleB);
                    *slotHandleAddr = NULL;
                }
                slotIndex += 1;
            }
            value288 = resourceRecord->handle288;
            if (value288 != 0) {
                jtbl_008873EC[0]((u8 *)value288);
            }
            handle290 = resourceRecord->handle290;
            if (handle290 != NULL) {
                kwlnTaskDestroyWithHierarchy((s32)handle290);
            }
            value360 = resourceRecord->handle360;
            if (value360 != 0) {
                func_003bbb60(value360);
            }
            func_00440b68(&D_005EF890, (u8 *)slotValue);
            break;
        case RESRC_TYPE_06:
            handle144Case6 = resourceRecord->slotHandle[1];
            if (handle144Case6 != NULL) {
                MT_Scene_SpawnIconTask(handle144Case6);
                resourceRecord->slotHandle[1] = NULL;
                func_00440b68(&D_005EF8B0, resourceRecord);
            }
            break;
        case RESRC_TYPE_MODELFLD:
            handle144 = resourceRecord->slotHandle[1];
            mdlDestroyModelObject((s32)handle144);
            resourceRecord->slotHandle[1] = NULL;
            handle16C = resourceRecord->handle16C;
            if (handle16C != NULL) {
                mdlDestroyModelObject((s32)handle16C);
                resourceRecord->handle16C = NULL;
            }
            func_00440b68(&D_005EF8D0, handle144);
            break;
        case RESRC_TYPE_11:
            handle144Case11 = resourceRecord->slotHandle[1];
            if (handle144Case11 != NULL) {
                mdlEffectDestroy((s32)handle144Case11);
                resourceRecord->slotHandle[1] = NULL;
                func_00440b68(&D_005EF8F0, resourceRecord);
            }
            break;
        case RESRC_TYPE_FLD:
            value1A0 = resourceRecord->handle1A0;
            if (value1A0 != 0) {
                FldResource_Destroy((void *)value1A0);
                resourceRecord->handle1A0 = 0;
                func_00440b68(&D_005EF910, resourceRecord);
            }
            break;
        case RESRC_TYPE_FLDHIT:
        case RESRC_TYPE_21:
            func_00440b68(&D_005EF930, resourceRecord);
            break;
        case RESRC_TYPE_14:
        case RESRC_TYPE_15:
        case RESRC_TYPE_16:
            func_00440b68(&D_005EF950, resourceRecord);
            break;
        case RESRC_TYPE_20:
            func_003e0f40(resourceRecord->cameraRes[0]);
            func_003e0f40(resourceRecord->cameraRes[1]);
            func_00440b68(&D_005EF970, resourceRecord);
            break;
        case RESRC_TYPE_LIGHTCHAR:
        case RESRC_TYPE_LIGHTNPC:
        case RESRC_TYPE_07:
        case RESRC_TYPE_08:
        case RESRC_TYPE_09:
        case RESRC_TYPE_17:
        case RESRC_TYPE_18:
        case RESRC_TYPE_19:
            ;
        }
        resrcMngDestroyRes(resourceOwner, resourceRecord);
    }
}

/* measured: closes schedule-off probe for 46630. */
/* Updates the supplied position, rotation and scale vectors before applying
   the resource-specific model or effect transform. NULL inputs retain the
   corresponding resource vector. Native b210 -O2: 1100/1104 bytes, with
   four 12-byte initializer vectors and a four-byte zero suffix.
   See Resource_transform_00146a10_20260922_worker1.md. */
// FUN_00146A10
/* SceneUpdateResource and ResrcRecord prove these offsets; typed aggregate/handle accesses changed 216 bytes of the matched b210 transform body. */
void MT_Scene_ApplyResTransform(u8 *resource, u8 *position, u8 *rotation, u8 *scaleInput)
{
    extern u8 D_005EF9D0[];
    extern u8 D_005EF9F0[];
    typedef struct Model Model;
    extern void mdlScale(Model *model, const RwV3d *scale, s32 combineOp);
    extern void mdlEffectSetMatrixPose(s32 effect, u8 *matrix);
    RwV3d axisY = {0.0f, 1.0f, 0.0f};
    RwV3d axisX = {1.0f, 0.0f, 0.0f};
    RwV3d axisZ = {0.0f, 0.0f, 1.0f};
    RwV3d scale = {2.0f, 2.0f, 2.0f};
    u32 effectMatrix[16];
    u32 transformMatrix[16];
    s32 modelHandle;
    s32 resourceType;
    u32 *sourceWords;
    u32 *outputWords;
    s32 remainingPairs;
    u32 first;
    u32 second;

    if (resource != 0) {
        if (position != 0) {
            *(RwV3d *)(resource + 4) = *(const RwV3d *)position;
        }
        if (rotation != 0) {
            *(RwV3d *)(resource + 16) = *(const RwV3d *)rotation;
        }
        if (scaleInput != 0) {
            *(RwV3d *)(resource + 28) = *(const RwV3d *)scaleInput;
        }
        scale = *(const RwV3d *)(resource + 28);
        resourceType = (*(u16 *)resource & 0xFFC00) >> 10;
        switch (resourceType) {
        case 1:
            modelHandle = *(s32 *)(resource + 0x164);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            mdlRotateMatrix((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            mdlTranslateMatrix((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        case 2:
            modelHandle = *(s32 *)(resource + 0x158);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            mdlRotateMatrix((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            mdlTranslateMatrix((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        case 3:
            modelHandle = *(s32 *)(resource + 0x164);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            mdlRotateMatrix((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            mdlTranslateMatrix((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        case 6:
            if (*(s32 *)(resource + 0x144) == 0) {
                func_00440b68(D_005EF9F0);
                return;
            }
            MT_Scene_BuildResMatrix(transformMatrix, resource + 4, (u32 *)(resource + 16));
            sourceWords = transformMatrix;
            outputWords = effectMatrix;
            remainingPairs = 8;
            do {
                first = sourceWords[0];
                second = sourceWords[1];
                sourceWords = sourceWords + 2;
                remainingPairs = remainingPairs - 1;
                outputWords[0] = first;
                outputWords[1] = second;
                outputWords = outputWords + 2;
            } while (remainingPairs > 0);
            mdlEffectSetMatrixPose(*(s32 *)(resource + 0x144), (u8 *)effectMatrix);
            return;
        case 10:
            modelHandle = *(s32 *)(resource + 0x144);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            mdlRotateMatrix((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            mdlRotateMatrix((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            mdlTranslateMatrix((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        }
    }
}

