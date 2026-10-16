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



extern u8 *resrcMngCreateRes(s32 arg0, s32 arg1);
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
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 FldFrameTask_Spawn(s32 arg0, s32 arg1, s32 arg2, f32 fparg0);

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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 001453a0-00145780 */

// FUN_001453A0
s32 MT_Scene_CreateRes08(u16 arg0)
{
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x2000) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(D_005EF820);
        return 0;
    }
    temp_3 = (u16)temp_16;
    if (((temp_3 & 0xFFC00) >> 10) != 8) {
        func_00440b68(D_005EF840);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        kAssertFail(D_005EF858, 0x1DE);
    }
    return temp_16;
}

// FUN_00145480
s32 MT_Scene_CreateRes07(u16 arg0) {
    s32 temp_16;
    s32 temp_4;
    u8 *temp_2;

    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x1C00) & 0xFFFF;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x140) = 0x420C0000;
    return temp_16;
}

// FUN_00145510
s32 MT_Scene_CreateModelCharRes(u16 arg0, void *arg1) {
    return MT_Scene_CreateModelCharShadowRes(arg0, 0, arg1);
}

// FUN_00145540
s32 MT_Scene_CreateModelCharShadowRes(u16 arg0, u16 arg1, void *arg2) {
    s8 sp50[0xC];
    s32 temp_16;
    u16 shadowId;
    s32 temp_2_2;
    s32 temp_4;
    s8 *var_3;
    s32 var_2;
    u8 *temp_2;

    var_3 = sp50;
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_16 = ((arg0 & 0xFFFF & 0x3FF) | 0x400) & 0xFFFF;
    shadowId = temp_16;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_16);
    if (temp_2 == NULL) {
        return 0;
    }
    *(void **)(temp_2 + 0x164) = arg2;
    mdlTranslateMatrix((RwMatrix *)arg2, (const RwV3d *)sp50, 0);
    RwMatrixUpdate((u8 *)mdlGetMatrix(*(void **)(temp_2 + 0x164)));
    temp_2_2 = FldFrameTask_Spawn(0, temp_16 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x220) = temp_2_2;
    *(void **)(temp_2 + 0x224) = FldShadow_CreateCaster((u8 *)temp_2_2, shadowId, arg1);
    return temp_16;
}

// FUN_00145690
s32 MT_Scene_CreateModelUnkRes(u16 arg0, s32 arg1) {
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
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0x800) & 0xFFFF;
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
    *(s32 *)(temp_2 + 0x158) = arg1;
    mdlTranslateMatrix((RwMatrix *)arg1, (const RwV3d *)sp30, 0);
    return temp_17;
}

// FUN_00145780
s32 MT_Scene_CreateModelNpcShadowRes(u16 arg0, u16 arg1, s32 arg2) {
    s8 sp[0xC];
    s32 temp_17;
    u16 shadowId;
    s32 temp_2_2;
    s32 temp_4;
    s8 *clear;
    s32 var_2;
    u8 *temp_2;

    clear = sp;
    var_2 = 0xC;
    if (clear != NULL) {
        do {
            *clear = 0;
            clear++;
            var_2--;
        } while (var_2 != 0);
    }
    temp_17 = ((arg0 & 0xFFFF & 0x3FF) | 0xC00) & 0xFFFF;
    shadowId = temp_17;
    temp_4 = *(s32 *)(iGpffff9db0 + 8);
    if (temp_4 == 0) {
        func_00440b68(&D_005EF820);
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    temp_2 = resrcMngCreateRes(temp_4, temp_17);
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 0x10000000;
    *(s32 *)(temp_2 + 0x164) = arg2;
    temp_2_2 = FldFrameTask_Spawn(0, temp_17 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x228) = temp_2_2;
    *(void **)(temp_2 + 0x230) = FldShadow_CreateCaster((u8 *)temp_2_2, shadowId, arg1);
    return temp_17;
}

