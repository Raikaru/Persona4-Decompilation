#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_resource_internal.h"
#include "Kosaka/k_sceneDraw_lighting.h"
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
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern u8 D_007EF9B0[];
extern u8 D_007E8020[];

extern void SceneDraw_InitResList5(void);
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
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;


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


extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern void resrcMngSetDrawEnabled(s32 enabled, s32 includeFieldModels);


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


/* Camp display: grid, labels, radar and corner sprites. Radar callees take u8 alpha because retail
 * passes it unmasked; one shared sprite variable serves both the 0x1834 label and corner sprite. */
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

/* measured: the two tail loops share function-scope k and j under opt_lifetimes on, and ent =
 * &arrB[k] stays a declared local, as in retail. */
#pragma push
#pragma pop
/* Integer accesses to float members below preserve the original IEEE-754 word stores. Initialize
 * the NPC-light resource colors, tint and pair of rotated direction matrices. */
// FUN_0014B1E0
void SceneDraw_InitResList5(void) {
    extern f32 fGpffff8198;
    extern void RwMatrixRotate(void *, void *, s32, f32 fparg0);
    s32 rotationAxisBits[3];
    f32 firstIntensity;
    u8 *firstColorResource;
    u8 *secondColorResource;
    u8 *firstMatrixResource;
    u8 *tintResource;
    u8 *secondMatrixResource;
    u8 *secondMatrix;
    u8 *firstMatrix;
    u8 *tint;
    u8 *secondColor;
    u8 *firstColor;

    firstColorResource = MT_Scene_GetResListHead(5);
    if (firstColorResource != NULL) {
        firstColor = (u8 *)&((FldSceneLighting *)firstColorResource)->light.firstColor;
    } else {
        firstColor = NULL;
    }
    secondColorResource = MT_Scene_GetResListHead(5);
    if (secondColorResource != NULL) {
        secondColor = (u8 *)&((FldSceneLighting *)secondColorResource)->light.secondColor;
    } else {
        secondColor = NULL;
    }
    firstMatrixResource = MT_Scene_GetResListHead(5);
    if (firstMatrixResource != NULL) {
        firstMatrix = (u8 *)&((FldSceneLighting *)firstMatrixResource)->light.matrix;
    } else {
        firstMatrix = NULL;
    }
    tintResource = MT_Scene_GetResListHead(5);
    if (tintResource != NULL) {
        tint = (u8 *)&((FldSceneLighting *)tintResource)->tint;
    } else {
        tint = NULL;
    }
    secondMatrixResource = MT_Scene_GetResListHead(5);
    if (secondMatrixResource != NULL) {
        secondMatrix = (u8 *)&((FldSceneLighting *)secondMatrixResource)->secondMatrix;
    } else {
        secondMatrix = NULL;
    }
    firstIntensity = fGpffff8198;
    ((SceneLightVector *)firstColor)->x = firstIntensity;
    ((SceneLightVector *)firstColor)->y = firstIntensity;
    ((SceneLightVector *)firstColor)->z = firstIntensity;
    *(s32 *)&((SceneLightVector *)firstColor)->w = 0;
    *(s32 *)&((SceneLightVector *)secondColor)->x = 0x3F000000;
    *(s32 *)&((SceneLightVector *)secondColor)->y = 0x3F000000;
    *(s32 *)&((SceneLightVector *)secondColor)->z = 0x3F000000;
    *(s32 *)&((SceneLightVector *)secondColor)->w = 0;
    *(s32 *)&((SceneLightVector *)tint)->x = 0;
    *(s32 *)&((SceneLightVector *)tint)->y = 0;
    *(s32 *)&((SceneLightVector *)tint)->z = 0;
    *(s32 *)&((SceneLightVector *)tint)->w = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.z = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.y = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.x = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->flags |= 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = 0x3F800000;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = 0x3F800000;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -45.0f);
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.z = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.y = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.x = 0x3F800000;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->flags |= 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = 0x3F800000;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = 0x3F800000;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -45.0f);
}

/* Return the first capture-camera matrix handle, or zero when the resource is absent. */
// FUN_0014B450
s32 MT_Scene_GetCameraResFirst(void) {
    s32 matrix;
    u8 *resource;

    resource = MT_Scene_GetResListHead(0x14);
    matrix = 0;
    if (resource != NULL) {
        matrix = ((ResrcRecord *)resource)->cameraRes[0];
    }
    return matrix;
}

/* Return the second capture-camera matrix handle, or zero when the resource is absent. */
// FUN_0014B490
s32 MT_Scene_GetCameraResSecond(void) {
    s32 matrix;
    u8 *resource;

    resource = MT_Scene_GetResListHead(0x14);
    matrix = 0;
    if (resource != NULL) {
        matrix = ((ResrcRecord *)resource)->cameraRes[1];
    }
    return matrix;
}

/* Return the capture-camera field of view, or zero when the resource is absent. */
// FUN_0014B4D0
f32 MT_Scene_GetCameraFov(void) {
    f32 fieldOfView;
    u8 *resource;

    resource = MT_Scene_GetResListHead(0x14);
    fieldOfView = 0.0f;
    if (resource != NULL) {
        fieldOfView = ((SceneCaptureCameraResource *)resource)->value;
    }
    return fieldOfView;
}

/* Find the lowest unused ten-bit ID by restarting the list scan after every collision. */
// FUN_0014B510
u16 MT_Scene_FindFreeResId(s32 resourceType)
{
    s32 freeId;
    s32 type;
    u8 *resource;

    freeId = 0;
    type = resourceType & 0xFFFF;
    resource = MT_Scene_GetResListHead(type);
    while (resource != NULL) {
        if ((*(u16 *)resource & 0x3FF) == freeId) {
            freeId += 1;
            resource = MT_Scene_GetResListHead(type);
        } else {
            resource = (u8 *)((ResrcRecord *)resource)->next;
        }
    }
    return freeId & 0xFFFF;
}

/* Round upward when the truncated fractional part is at least one half. */
// FUN_0014B590
f32 KDraw_RoundYawDeg(f32 angle) {
    s32 integer;
    f32 result;

    integer = (s32)angle;
    result = (f32)integer;
    if (!((angle - result) < 0.5f)) {
        result = (f32)(integer + 1);
    }
    return result;
}

