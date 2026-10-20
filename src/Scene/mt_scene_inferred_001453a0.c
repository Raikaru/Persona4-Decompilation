#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw/plcore/barenderstate.h"
#include "scene_task_internal.h"
#include "scene_resource_internal.h"
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



extern u8 *resrcMngCreateRes(s32 resManager, s32 resTypeId);
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
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern u8 D_007EF9B0[];
extern u8 D_007E8020[];
extern void *mdlGetMatrix(void *model);

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
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 FldFrameTask_Spawn(s32, s32, s32, f32 fparg0);

extern s32 D_007642E4;
extern u8 D_005EFB10[];




typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;

extern s32 RwMatrixUpdate();

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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001453a0-00145780 */

/* Create the packed resource and initialize its model, camera or shadow handles. */
// FUN_001453A0
s32 MT_Scene_CreateRes08(u16 resourceId)
{
    s32 resourceTypeId;
    s32 packedId;
    s32 manager;
    u8 *resource;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x2000) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(D_005EF820);
        return 0;
    }
    packedId = (u16)resourceTypeId;
    if (((packedId & 0xFFC00) >> 10) != 8) {
        func_00440b68(D_005EF840);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    if (resource == NULL) {
        kAssertFail(D_005EF858, 0x1DE);
    }
    return resourceTypeId;
}

/* Create the packed resource and initialize its model, camera or shadow handles. */
// FUN_00145480
s32 MT_Scene_CreateRes07(u16 resourceId) {
    s32 resourceTypeId;
    s32 manager;
    u8 *resource;

    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x1C00) & 0xFFFF;
    manager = ((SceneContext *)iGpffff9db0)->manager.handle;
    if (manager == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    resource = resrcMngCreateRes(manager, resourceTypeId);
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)&((ResrcRecord *)resource)->slotHandle[0] = 0x420C0000;
    return resourceTypeId;
}

/* Create the packed resource and initialize its model, camera or shadow handles. */
// FUN_00145510
s32 MT_Scene_CreateModelCharRes(u16 resourceId, void *model) {
    return MT_Scene_CreateModelCharShadowRes(resourceId, 0, model);
}

/* Create the packed resource and initialize its model, camera or shadow handles. */
/* measured: only the model reload needs MEMBER; access-site, typed-local and array forms grow this body from 336 to 344 bytes. */
// FUN_00145540
s32 MT_Scene_CreateModelCharShadowRes(u16 resourceId, u16 shadowModelId, void *model) {
    s8 zeroPosition[0xC];
    s32 resourceTypeId;
    u16 shadowId;
    s32 frameTask;
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
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x400) & 0xFFFF;
    shadowId = resourceTypeId;
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
    *(void **)&((ResrcRecord *)resource)->modelHandle164 = model;
    mdlTranslateMatrix((RwMatrix *)model, (const RwV3d *)zeroPosition, 0);
    RwMatrixUpdate((u8 *)mdlGetMatrix(MEMBER(void *, resource, ResrcRecord, modelHandle164)));
    frameTask = FldFrameTask_Spawn(0, resourceTypeId & 0xFFFF, 0, 60.0f);
    *(s32 *)&((ResrcRecord *)resource)->handle220 = frameTask;
    *(void **)&((ResrcRecord *)resource)->handle224 = FldShadow_CreateCaster((u8 *)frameTask, shadowId, shadowModelId);
    return resourceTypeId;
}

/* Create the packed resource and initialize its model, camera or shadow handles. */
// FUN_00145690
s32 MT_Scene_CreateModelUnkRes(u16 resourceId, s32 model) {
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
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0x800) & 0xFFFF;
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
    *(s32 *)&((ResrcRecord *)resource)->modelHandle158 = model;
    mdlTranslateMatrix((RwMatrix *)model, (const RwV3d *)zeroPosition, 0);
    return resourceTypeId;
}

/* Create the packed resource and initialize its model, camera or shadow handles. */
// FUN_00145780
s32 MT_Scene_CreateModelNpcShadowRes(u16 resourceId, u16 shadowModelId, s32 model) {
    s8 zeroPosition[0xC];
    s32 resourceTypeId;
    u16 shadowId;
    s32 frameTask;
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
    resourceTypeId = ((resourceId & 0xFFFF & 0x3FF) | 0xC00) & 0xFFFF;
    shadowId = resourceTypeId;
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
    *(s32 *)&((ResrcHeader *)resource)->flags = *(s32 *)&((ResrcHeader *)resource)->flags | 0x10000000;
    *(s32 *)&((ResrcRecord *)resource)->modelHandle164 = model;
    frameTask = FldFrameTask_Spawn(0, resourceTypeId & 0xFFFF, 0, 60.0f);
    *(s32 *)&((ResrcRecord *)resource)->handle228 = frameTask;
    *(void * *)&((ResrcRecord *)resource)->handle230 = FldShadow_CreateCaster((u8 *)frameTask, shadowId, shadowModelId);
    return resourceTypeId;
}

