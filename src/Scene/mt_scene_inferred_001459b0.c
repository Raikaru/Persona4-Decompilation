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



extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void MT_Scene_DestroyRes(u16 resTypeId);
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
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void func_004b1150(s32 arg0);
extern void mdlDestroyModelObject(s32 arg0);
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
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 func_004b1130(s32 arg0);
extern void func_004b1250(void *object, f32 *position);
extern void mdlEffectSetUniformScale(s32 arg0, f32 arg1);

extern s32 D_007642E4;
extern u8 D_005EFB10[];


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
s32 MT_Scene_CreateObjectRes(u16 arg0, s32 arg1, s8 arg2) {
    f32 sp[3];
    s32 temp_16;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x1800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        func_00440b68(&D_005EF870);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = func_004b1130(arg1);
    *(s8 *)(temp_2 + 0x140) = arg2;
    sp[0] = 100.0f;
    sp[1] = 0.0f;
    sp[2] = 0.0f;
    func_004b1250(*(void **)(temp_2 + 0x144), sp);
    mdlEffectSetUniformScale(*(s32 *)(temp_2 + 0x144), 1.5f);
    return temp_16;
}

// FUN_00145AC0
s32 MT_Scene_CreateModelFldRes(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x2800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}

// FUN_00145BA0
s32 MT_Scene_CreateRes11(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x2C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x144) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}

// FUN_00145C80
s32 MT_Scene_CreateFldRes(u16 arg0, s32 arg1) {
    s8 sp30[0xC];
    s32 temp_17;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp30;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x1A0) = arg1;
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}

// FUN_00145D60
s32 MT_Scene_CreateFldHitLight(u16 arg0, f32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, FieldRgba8 arg2) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;
    Rgba8_0014 color;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x144) = point;
    *(f32 *)(temp_2 + 0x150) = fparg0;
    *(f32 *)(temp_2 + 0x154) = fparg1;
    *(f32 *)(temp_2 + 0x158) = fparg2;
    color = arg2;
    *(Rgba8_0014 *)(temp_2 + 0x140) = color;
    Vpad_BuildRotatedQuad(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}

// FUN_00145E90
s32 MT_Scene_CreateRes21Light(u16 arg0, f32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, FieldRgba8 arg2) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;
    Rgba8_0014 color;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x5400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x144) = point;
    *(f32 *)(temp_2 + 0x150) = fparg0;
    *(f32 *)(temp_2 + 0x154) = fparg1;
    *(f32 *)(temp_2 + 0x158) = fparg2;
    color = arg2;
    *(Rgba8_0014 *)(temp_2 + 0x140) = color;
    Vpad_BuildRotatedQuad(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}

// FUN_00145FC0
s32 MT_Scene_CreatePointRes14(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_00146080
s32 MT_Scene_CreatePointRes15(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x3C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_00146140
s32 MT_Scene_CreatePointRes16(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_00146200
s32 MT_Scene_CreatePointRes17(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4400) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_001462C0
s32 MT_Scene_CreatePointRes18(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4800) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_00146380
s32 MT_Scene_CreatePointRes19(u16 arg0, f32 *arg1, f32 fparg0) {
    s32 temp_17;
    s32 temp_4;
    u8 *temp_2;
    SVec3 point;

    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x4C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    point = *(SVec3 *)arg1;
    *(SVec3 *)(temp_2 + 0x140) = point;
    *(f32 *)(temp_2 + 0x14C) = fparg0;
    *(s32 *)(temp_2 + 0x28) |= 8;
    return temp_17;
}

// FUN_00146440
s32 MT_Scene_CreateCameraRes(u16 arg0, s32 arg1, f32 fparg0, u8 *arg2, u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6) {
    s32 temp_22;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    u8 *temp_2;
    u8 *var_19;
    u8 *var_20;
    u8 *var_5;
    u8 *var_5_2;
    s32 var_4;
    s32 var_4_2;
    SVec3 point;

    temp_22 = ((arg0 & 0xFFFF & 0x3FF) | 0x5000) & 0xFFFF;
    var_20 = arg2;
    var_19 = arg3;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_22);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x140) = arg1;
    *(f32 *)(temp_2 + 0x144) = fparg0;
    *(u8 **)(temp_2 + 0x148) = func_003e0f80();
    if (var_20 != NULL) {
        var_5 = *(u8 **)(temp_2 + 0x148);
        var_4 = 8;
        do {
            temp_3 = *(s32 *)(var_20 + 0);
            temp_2_2 = *(s32 *)(var_20 + 4);
            var_20 += 8;
            var_4 -= 1;
            *(s32 *)(var_5 + 0) = temp_3;
            *(s32 *)(var_5 + 4) = temp_2_2;
            var_5 += 8;
        } while (var_4 > 0);
    }
    *(u8 **)(temp_2 + 0x14C) = func_003e0f80();
    if (var_19 != NULL) {
        var_5_2 = *(u8 **)(temp_2 + 0x14C);
        var_4_2 = 8;
        do {
            temp_3_2 = *(s32 *)(var_19 + 0);
            temp_2_3 = *(s32 *)(var_19 + 4);
            var_19 += 8;
            var_4_2 -= 1;
            *(s32 *)(var_5_2 + 0) = temp_3_2;
            *(s32 *)(var_5_2 + 4) = temp_2_3;
            var_5_2 += 8;
        } while (var_4_2 > 0);
    }
    if (arg4 != NULL) {
        point = *(SVec3 *)arg4;
        *(SVec3 *)(temp_2 + 0x150) = point;
    }
    *(f32 *)(temp_2 + 0x15C) = fparg1;
    *(f32 *)(temp_2 + 0x160) = fparg2;
    if (arg5 != 0) {
        memcpy(temp_2 + 0x164, (const void *)arg5, 0x20);
    }
    if (arg6 != 0) {
        memcpy(temp_2 + 0x184, (const void *)arg6, 0x180);
    }
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_22;
}

/* measured: O1 probe for 00146630 register allocation and short tail. */
/* measured: schedule-off probe for 46630 branch delay slots. */
// FUN_00146630
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

    resourceOwner = *(u8 **)(iGpffff9db0 + 8);
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
                slotAddr = (u8 *)resourceRecord + slotValue * 4;
                slotHandleAddr = (void **)(slotAddr + 0x140);
                slotHandle = *slotHandleAddr;
                if (slotHandle != NULL) {
                    func_004b1150((s32)slotHandle);
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
                slotAddrB = (u8 *)resourceRecord + slotIndex * 4;
                slotHandleAddr = (void **)(slotAddrB + 0x140);
                slotHandleB = *slotHandleAddr;
                if (slotHandleB != NULL) {
                    func_004b1150((s32)slotHandleB);
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
                func_004b1150((s32)handle144Case11);
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
void MT_Scene_ApplyResTransform(u8 *resource, u8 *position, u8 *rotation, u8 *scaleInput)
{
    extern u8 D_005EF9D0[];
    extern u8 D_005EF9F0[];
    typedef struct Model Model;
    extern void mdlScale(Model *model, const RwV3d *scale, s32 combineOp);
    extern void func_004b12e0(s32 effect, u8 *matrix);
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
            func_004b12e0(*(s32 *)(resource + 0x144), (u8 *)effectMatrix);
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

