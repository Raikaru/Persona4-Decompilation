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
extern void func_00355070(u8 *arg0, u8 *arg1);
extern void func_003550d0(u8 *arg0, Float2_0014 *arg1, Float2_0014 *arg2);
extern void func_003552d0(u8 *arg0, Float2_0014 arg1);
extern void func_00355300(u8 *arg0, s32 arg1);
extern void func_00355370(u8 *arg0, u8 *arg1);



extern void func_0046d280(void *node);
extern void func_00452080(s32 arg0);
extern void MT_Scene_DestroyRes(u16 resTypeId);
extern void resrcMngDestroy(u8 *arg0);
extern u8 *resrcMngGetListHead(u8 *arg0, s32 arg1);
extern void func_0015cc40(void);
extern void func_0015cf10(void);
extern void func_00160180(void);
extern void func_003e1a70(void);
extern void func_00451b70(void);
extern void func_0014eed0(s32 arg0, s32 arg1);
extern void func_0014efc0(s32 arg0, s32 arg1);
extern s32 func_0014f310(s32 arg0, s32 arg1);
extern s32 func_0026df80(void);
extern u8 *resrcMngCreateRes(s32 arg0, s32 arg1);
extern u8 *func_00147530(u8 *arg0, u16 arg1);
extern void func_0015f720(u8 *arg0, const u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern u8 *func_003e0f80(void);
extern void memcpy(void *dest, const void *src, s32 size);
extern void func_00147430();
extern void func_00151f80(void *arg0);
extern void func_00268b20(void *arg0);
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
extern void func_0046d730(const void *arg0, s32 arg1);
extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void func_004b1150(s32 arg0);
extern s32 func_004782b0(s32 arg0);
extern void func_004787e0(s32 arg0);
extern s32 func_00104c70(s32 arg0);
extern u8 D_007EF9B0[];
extern void func_003c38b0(void *arg0, void *arg1);
extern void func_003e8110(void *arg0);
extern void func_003e8120(void *arg0);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);
extern u8 *func_00457190(void);
extern void func_003cbe80(void *arg0, void *arg1);
extern u8 *func_00149ca0(void);
extern u8 D_007E8020[];
extern void *mdlGetMatrix(void *model);
extern f32 RwV3dLength(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern s32 func_0014c240(void *arg0, void *arg1, f32 fparg0, f32 fparg1);

extern s32 func_0014a230(s32 arg0, s32 arg1);
extern s32 func_0014a2a0(s32 arg0, s32 arg1);
extern void func_00440b68();
extern s32 func_00153a60(s32 arg0);
extern s32 resrcMngCreate(void);
extern s32 MT_Scene_CreateResLightChar(s32 arg0);
extern void func_0014ad90(void);
extern s32 MT_Scene_CreateResLightNpc(s32 arg0);
extern void func_0014b1e0(void);
extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern s32 func_003cbf30(s32 arg0, void *arg1);
extern u8 *func_00149ce0(void);
extern u8 *func_00149d20(void);
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
extern void func_00145080(void);
extern u8 * iGpffff9db0;
extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 func_004b1130(s32 arg0);
extern void func_004b1170(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_004b1250(void *object, f32 *position);
extern s32 func_001684a0(s32 arg0, s32 arg1, s32 arg2, f32 fparg0);
extern void func_004b13d0(s32 arg0, f32 arg1);

extern s32 D_007642E4;
extern u8 D_005EFB10[];
extern s32 func_00148280(u8 *task);
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



extern u8 *func_00460990(void);
extern void func_00460ac0(void *arg0, u8 *arg1);
extern void func_0014d290(u8 *arg0, u8 *arg1);

extern s32 func_0034c210(void);
extern void func_0013fb50(u8 *arg0);
extern s32 func_0013ff80(u8 *arg0);
extern s32 func_00142340(u8 *arg0);
extern void func_001422b0(u8 *arg0);
extern void func_00142230(u8 *arg0);
extern s32 func_0034bb20(s32 arg0);
extern void func_0034bd60(s32 arg0);
extern void func_00353fb0(void);
extern void func_00353fe0(void);
extern s32 func_00354030(void);
extern void func_00355190(u8 *arg0, s32 arg1);
extern void func_003671d0(void *arg0);
extern void func_003672d0(void *arg0, s16 pcId);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void func_00142d80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void func_0014a000(s32 arg0, s32 arg1);
extern void func_001538a0(u32 *resource, const f32 *color);
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
extern u8 *func_00155280(void);
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void func_0034f5d0(u8 *arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void func_0044ea90(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern s32 func_0014e2a0(u8 *arg0);
extern void func_0014e540(u8 *arg0);
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
 * the corner sprite; b210 does not propagate it into the func_0034f320
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
extern void func_0034f1e0(void);
extern void func_0034c270(Float2_0014 work, s32 arg1, s32 arg2, f32 fparg0);
extern f32 func_0034f720(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2);
extern void func_0034f2e0(void *work, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern void func_0034f320(u8 *work, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void func_0034f9d0(Float2_0014 work, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
extern void func_00355410(u8 *work, u8 arg1);
extern void func_00354ba0(void *work);
extern void func_00367210(CampDisplayWords position, f32 depth, s32 alpha, s16 *label);
extern s32 func_00104c70(s32 work);
extern u32 func_0010d6d0(s16 work);
extern s32 func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
extern void func_001423c0(s64 work, f32 fparg0, s32 arg1, u8 *arg2, s32 arg3);
extern void func_001424b0(Float2_0014 pos, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3);


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





// FUN_001453A0
s32 func_001453a0(u16 arg0)
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
        func_0046d730(D_005EF858, 0x1DE);
    }
    return temp_16;
}
// FUN_00145480
s32 func_00145480(u16 arg0) {
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
s32 func_00145510(u16 arg0, void *arg1) {
    return func_00145540(arg0, 0, arg1);
}



// FUN_00145540
s32 func_00145540(u16 arg0, u16 arg1, void *arg2) {
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
    func_0047a180((RwMatrix *)arg2, (const RwV3d *)sp50, 0);
    RwMatrixUpdate((u8 *)mdlGetMatrix(*(void **)(temp_2 + 0x164)));
    temp_2_2 = func_001684a0(0, temp_16 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x220) = temp_2_2;
    *(void **)(temp_2 + 0x224) = FldShadow_CreateCaster((u8 *)temp_2_2, shadowId, arg1);
    return temp_16;
}
// FUN_00145690
s32 func_00145690(u16 arg0, s32 arg1) {
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
    func_0047a180((RwMatrix *)arg1, (const RwV3d *)sp30, 0);
    return temp_17;
}
// FUN_00145780
s32 func_00145780(u16 arg0, u16 arg1, s32 arg2) {
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
    temp_2_2 = func_001684a0(0, temp_17 & 0xFFFF, 0, 60.0f);
    *(s32 *)(temp_2 + 0x228) = temp_2_2;
    *(void **)(temp_2 + 0x230) = FldShadow_CreateCaster((u8 *)temp_2_2, shadowId, arg1);
    return temp_17;
}
// FUN_001459B0
s32 func_001459b0(u16 arg0, s32 arg1, s8 arg2) {
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
    func_004b13d0(*(s32 *)(temp_2 + 0x144), 1.5f);
    return temp_16;
}
// FUN_00145AC0
s32 func_00145ac0(u16 arg0, s32 arg1) {
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
s32 func_00145ba0(u16 arg0, s32 arg1) {
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
s32 func_00145c80(u16 arg0, s32 arg1) {
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
s32 func_00145d60(u16 arg0, f32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, FieldRgba8 arg2) {
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
    func_0015f720(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145E90
s32 func_00145e90(u16 arg0, f32 *arg1, f32 fparg0, f32 fparg1, f32 fparg2, FieldRgba8 arg2) {
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
    func_0015f720(temp_2 + 0x15C, (const u8 *)arg1, fparg0, fparg1, fparg2);
    *(s32 *)(temp_2 + 0x28) = *(s32 *)(temp_2 + 0x28) | 8;
    return temp_17;
}
// FUN_00145FC0
s32 func_00145fc0(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_00146080(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_00146140(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_00146200(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_001462c0(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_00146380(u16 arg0, f32 *arg1, f32 fparg0) {
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
s32 func_00146440(u16 arg0, s32 arg1, f32 fparg0, u8 *arg2, u8 *arg3, u8 *arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6) {
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
#pragma optimization_level 1
/* measured: schedule-off probe for 46630 branch delay slots. */
#pragma schedule off
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
        resourceRecord = (ResrcRecord *)func_00147530(resourceOwner, resTypeId);
    }
    if (resourceRecord != NULL) {
        resourceKind = RESRC_GET_TYPE(resourceRecord->resTypeId);
        switch (resourceKind) {
        case RESRC_TYPE_MODELCHAR:
            handle164 = resourceRecord->modelHandle164;
            func_00452080(resourceRecord->handle220);
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
                func_004787e0((s32)handle228);
                resourceRecord->handle228 = NULL;
            }
            func_00440b68(&D_005EF890, handle164);
            break;
        case RESRC_TYPE_MODELUNK:
            handle158 = resourceRecord->modelHandle158;
            func_004787e0((s32)handle158);
            resourceRecord->modelHandle158 = NULL;
            func_00440b68(&D_005EF890, handle158);
            break;
        case RESRC_TYPE_MODELNPC:
            slotValue = (s32)resourceRecord->modelHandle164;
            handle228Case3 = resourceRecord->handle228;
            if (handle228Case3 != NULL) {
                func_00452080((s32)handle228Case3);
                resourceRecord->handle228 = NULL;
            }
            resourceRecord->handle230 = 0;
            resourceRecord->handle294 = 0;
            handle22C = resourceRecord->handle22C;
            if (handle22C != NULL) {
                func_004787e0((s32)handle22C);
                resourceRecord->handle22C = NULL;
            }
            func_004787e0((s32)slotValue);
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
                func_00452080((s32)handle290);
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
                func_00268b20(handle144Case6);
                resourceRecord->slotHandle[1] = NULL;
                func_00440b68(&D_005EF8B0, resourceRecord);
            }
            break;
        case RESRC_TYPE_MODELFLD:
            handle144 = resourceRecord->slotHandle[1];
            func_004787e0((s32)handle144);
            resourceRecord->slotHandle[1] = NULL;
            handle16C = resourceRecord->handle16C;
            if (handle16C != NULL) {
                func_004787e0((s32)handle16C);
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
                func_00151f80((void *)value1A0);
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
        func_00147430(resourceOwner, resourceRecord);
    }
}
/* measured: closes schedule-off probe for 46630. */
#pragma schedule on
#pragma optimization_level 2
/* Updates the supplied position, rotation and scale vectors before applying
   the resource-specific model or effect transform. NULL inputs retain the
   corresponding resource vector. Native b210 -O2: 1100/1104 bytes, with
   four 12-byte initializer vectors and a four-byte zero suffix.
   See Resource_transform_00146a10_20260922_worker1.md. */
// FUN_00146A10
void func_00146a10(u8 *resource, u8 *position, u8 *rotation, u8 *scaleInput)
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
            func_0047a1a0((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            func_0047a1a0((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            func_0047a1a0((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            func_0047a180((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        case 2:
            modelHandle = *(s32 *)(resource + 0x158);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            func_0047a1a0((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            func_0047a1a0((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            func_0047a1a0((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            func_0047a180((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        case 3:
            modelHandle = *(s32 *)(resource + 0x164);
            if (modelHandle == 0) {
                func_00440b68(D_005EF9D0);
                return;
            }
            func_0047a1a0((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            func_0047a1a0((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            func_0047a1a0((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            func_0047a180((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
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
            func_0047a1a0((void *)(u32)modelHandle, &axisY, *(f32 *)(resource + 0x14), 0);
            func_0047a1a0((void *)(u32)modelHandle, &axisX, *(f32 *)(resource + 0x10), 1);
            func_0047a1a0((void *)(u32)modelHandle, &axisZ, *(f32 *)(resource + 0x18), 1);
            mdlScale((Model *)(u32)modelHandle, &scale, 2);
            func_0047a180((RwMatrix *)(u32)modelHandle, (const RwV3d *)(resource + 4), 2);
            return;
        }
    }
}
// FUN_00147530
u8 *func_00147530(u8 *arg0, u16 arg1) {
    s32 temp_3;
    s32 temp_5;
    u8 *var_2;

    temp_5 = arg1;
    temp_3 = ((temp_5 & 0xFFC00) >> 0xA) & 0xFF;
    if (temp_3 == 0) {
        return NULL;
    }
    if (temp_3 >= 0x16) {
        return NULL;
    }
    var_2 = *(u8 **)(arg0 + temp_3 * 4);
    while (var_2 != NULL) {
        if (*(u16 *)var_2 == temp_5) {
            return var_2;
        }
        var_2 = *(u8 **)(var_2 + 0x138);
    }
    return NULL;
}
// FUN_001475C0
/* Ported from P3FES resrcMngGetTotalResInList: P4 uses a 0x16-entry list
   table and the list link remains at offset 0x138. */
u32 func_001475c0(u8 *resLists, u8 resType)
{
    u32 total;
    u8 *currRes;

    total = 0;
    if (resType >= 0x16) {
        return total;
    }
    currRes = *(u8 **)(resLists + resType * 4);
    while (currRes != NULL) {
        total++;
        currRes = *(u8 **)(currRes + 0x138);
    }
    return total;
}

// FUN_00147620
u8 *func_00147620(s32 arg0) {
    return D_005EFAA0 + arg0 * 0x10;
}
/* measured probe: opt_propagation off for 00147640 float ordering. */
#pragma opt_propagation off
// FUN_00147640
void func_00147640(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_16;
    s32 temp_2_3;
    s32 temp_3;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *var_6;
    u8 *var_5;
    s32 var_4;
    void (**base)(u32, u32);

    func_003e8110(((u8 *)(u32)func_00457120()));
    temp_2 = func_004571a0();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = func_004571b0();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(func_004571b0() + 4) + 0x10;
    var_5 = arg1 + 0x20;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)(var_6 + 0);
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)(var_5 + 0) = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    temp_16 = (s32)func_00457190();
    func_003cbf30(temp_16, func_004571c0());
    if (func_00149ca0() != NULL) {
        temp_16_2 = func_004571a0();
        func_003c38b0(temp_16_2, func_00149ca0());
        temp_16_3 = func_004571b0();
        func_003c38b0(temp_16_3, func_00149ce0());
        temp_16_4 = func_004571b0();
        func_003e9cb0(*(s32 *)(temp_16_4 + 4), func_00149d20(), 0);
    }
    func_003e8120(((u8 *)(u32)func_00457120()));
    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0xE, 1);
        base[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        base[0](0x10, 1);
    }
}
/* measured probe: restore opt_propagation after 00147640. */
#pragma opt_propagation on
// FUN_00147830
void func_00147830(u8 *arg0, u8 *arg1) {
    u8 *temp_16;

    func_003e8110(((u8 *)(u32)func_00457120()));
    temp_16 = func_00457190();
    func_003cbe80(temp_16, func_004571c0());
    if (func_00149ca0() != NULL) {
        func_003c38b0(func_004571a0(), arg1);
        func_003c38b0(func_004571b0(), arg1 + 0x10);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x20, 0);
    }
    func_003e8120(((u8 *)(u32)func_00457120()));
}
/* measured probe: opt_propagation off for 00147910 float and vtable order. */
#pragma opt_propagation off
// FUN_00147910
void func_00147910(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_3;
    s32 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *var_6;
    u8 *var_5;
    s32 var_4;
    u8 *var_6_2;
    u8 *var_5_2;
    s32 var_4_2;
    void (**base)(u32, u32);

    func_003e8110(((u8 *)(u32)func_00457120()));
    temp_2 = func_004571a0();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = func_004571b0();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(func_004571b0() + 4) + 0x10;
    var_5 = arg1 + 0x20;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)(var_6 + 0);
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)(var_5 + 0) = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    temp_2_4 = func_004571c0();
    temp_f3 = *(f32 *)(temp_2_4 + 0x18);
    temp_f2 = *(f32 *)(temp_2_4 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_4 + 0x20);
    temp_f0 = *(f32 *)(temp_2_4 + 0x24);
    *(f32 *)(arg1 + 0x60) = temp_f3;
    *(f32 *)(arg1 + 0x64) = temp_f2;
    *(f32 *)(arg1 + 0x68) = temp_f1;
    *(f32 *)(arg1 + 0x6C) = temp_f0;
    var_6_2 = *(u8 **)(func_004571c0() + 4) + 0x10;
    var_5_2 = arg1 + 0x70;
    var_4_2 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2_5 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4_2 -= 1;
        *(s32 *)(var_5_2 + 0) = temp_3_2;
        *(s32 *)(var_5_2 + 4) = temp_2_5;
        var_5_2 += 8;
    } while (var_4_2 > 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
    if (iGpffffba48 == 1) {
        base = D_00887300;
        base[0](0xE, 1);
        base[0](0xF,
                iGpffffba54 |
                ((iGpffffba50 << 8) |
                 ((iGpffffba58 << 0x18) |
                  (iGpffffba4c << 0x10))));
        base[0](0x10, 1);
    }
    D_00887300[0](0x14, 2);
}
/* measured probe: restore opt_propagation after 00147910. */
#pragma opt_propagation on
// FUN_00147AE0
void func_00147ae0(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(func_004571a0(), arg1);
    func_003c38b0(func_004571c0(), arg1 + 0x60);
    func_003c38b0(func_004571b0(), arg1 + 0x10);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x70, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x20, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}
// FUN_00147BB0
void func_00147bb0(u8 *arg0, u8 *arg1) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = MT_Scene_GetResListHead(4);
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(func_004571a0(), temp_16 + 0x140);
    func_003c38b0(func_004571c0(), temp_16 + 0x150);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), temp_16 + 0x160, 0);
    temp_3 = *(s32 *)(arg1 + 0x28);
    if (temp_3 & 0x80000000) {
        func_003c38b0(func_004571a0(), arg1 + 0x168);
        func_003c38b0(func_004571c0(), arg1 + 0x178);
        func_003c38b0(func_004571b0(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x190, 0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    } else if (temp_3 & 0x40000000) {
        func_003c38b0(func_004571b0(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    } else {
        func_003c38b0(func_004571b0(), temp_16 + 0x1A0);
        func_003e9cb0(*(s32 *)(func_004571b0() + 4), temp_16 + 0x1B0, 0);
    }
    func_003e8120(((u8 *)(u32)func_00457120()));
}
// FUN_00147D80
void func_00147d80(void) {
    u8 *temp_16;

    temp_16 = MT_Scene_GetResListHead(5);
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(func_004571a0(), temp_16 + 0x140);
    func_003c38b0(func_004571c0(), temp_16 + 0x150);
    func_003c38b0(func_004571b0(), temp_16 + 0x1A0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), temp_16 + 0x160, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), temp_16 + 0x1B0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}
// FUN_00147E60
void func_00147e60(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(func_004571a0(), arg1 + 0x168);
    func_003c38b0(func_004571c0(), arg1 + 0x178);
    func_003c38b0(func_004571b0(), arg1 + 0x1D0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x190, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1E0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}
// FUN_00147F30
void func_00147f30(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(func_004571a0(), arg1 + 0x15C);
    func_003c38b0(func_004571c0(), arg1 + 0x16C);
    func_003c38b0(func_004571b0(), arg1 + 0x1C0);
    func_003e9cb0(*(s32 *)(func_004571c0() + 4), arg1 + 0x180, 0);
    func_003e9cb0(*(s32 *)(func_004571b0() + 4), arg1 + 0x1D0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}
/* measured probe: opt_propagation off preserves 00148000 vector coloring. */
#pragma opt_propagation off
// FUN_00148000
s32 func_00148000(const void *left, const void *right) {
    u8 *const *arg0 = (u8 *const *)left;
    u8 *const *arg1 = (u8 *const *)right;
    struct Frame {
        f32 v40[3];
        u8 pad4C[4];
        f32 v50[3];
        u8 pad5C[4];
        f32 v60[3];
        u8 pad6C[4];
    } frame;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;

    temp_2 = ((u8 *)(u32)func_00457120());
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f2 = *(f32 *)(temp_2 + 0x30);
    temp_f1 = *(f32 *)(temp_2 + 0x34);
    temp_f0 = *(f32 *)(temp_2 + 0x38);
    frame.v40[0] = temp_f2;
    frame.v40[1] = temp_f1;
    frame.v40[2] = temp_f0;
    temp_17 = *arg0;
    temp_16 = *arg1;
    frame.v60[0] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x30) - frame.v40[0];
    temp_f21 = frame.v40[1];
    frame.v60[1] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x34) - temp_f21;
    temp_f20 = frame.v40[2];
    frame.v60[2] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x38) - temp_f20;
    frame.v50[0] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x30) - frame.v40[0];
    frame.v50[1] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x34) - temp_f21;
    frame.v50[2] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x38) - temp_f20;
    temp_f20 = RwV3dLength(frame.v60);
    return (s32)(temp_f20 - RwV3dLength(frame.v50));
}
/* measured: closes opt_propagation off for func_00148000. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves 00148140 vector coloring. */
#pragma opt_propagation off
// FUN_00148140
s32 func_00148140(const void *left, const void *right) {
    u8 *const *arg0 = (u8 *const *)left;
    u8 *const *arg1 = (u8 *const *)right;
    struct Frame {
        f32 v40[3];
        u8 pad4C[4];
        f32 v50[3];
        u8 pad5C[4];
        f32 v60[3];
        u8 pad6C[4];
    } frame;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;

    temp_2 = ((u8 *)(u32)func_00457120());
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f2 = *(f32 *)(temp_2 + 0x30);
    temp_f1 = *(f32 *)(temp_2 + 0x34);
    temp_f0 = *(f32 *)(temp_2 + 0x38);
    frame.v40[0] = temp_f2;
    frame.v40[1] = temp_f1;
    frame.v40[2] = temp_f0;
    temp_17 = *arg0;
    temp_16 = *arg1;
    frame.v60[0] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x30) - frame.v40[0];
    temp_f21 = frame.v40[1];
    frame.v60[1] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x34) - temp_f21;
    temp_f20 = frame.v40[2];
    frame.v60[2] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_17 + 0x164)) + 0x38) - temp_f20;
    frame.v50[0] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x30) - frame.v40[0];
    frame.v50[1] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x34) - temp_f21;
    frame.v50[2] = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(temp_16 + 0x164)) + 0x38) - temp_f20;
    temp_f20 = RwV3dLength(frame.v60);
    return (s32)(temp_f20 - RwV3dLength(frame.v50));
}
/* measured: closes opt_propagation off for func_00148140. */
#pragma opt_propagation on
/* Recovered render passes preserve callback-time resource reloads and
   complete position-vector copies. The two tail k-loops share
   function-scope `k`/`j` (declared k first) under `opt_lifetimes on`, so
   IRO_SplitLifetimes numbers each loop's counters after the hoisted
   `&arrB[k]` temporaries. The first tail loop walks its attachments through
   `cur = (u8 *)ent`; that copy keeps `ent = &arrB[k]` a declared local, which
   is retail's $s4. See docs/probe_archive/RenderQueue_00148280_worker1_20261005.md. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// FUN_00148280
s32 func_00148280(u8 *unusedTask) {
    /* Retail returns zero at 001495E8, 00148318. */
    extern void func_00152930(u8 *arg0, u8 *arg1);
    extern void func_00152bb0(u8 *arg0, u8 *arg1);
    extern void func_00152cd0(u8 *arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, void *arg1);
    extern s32 func_00462df0(u8 *arg0);
    extern u32 func_00462e80(const u32 *state);
    extern void func_00479100(void *queue, u8 *model);
    extern void *mdlGetColor(void *model);
    extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
    extern void func_004b11d0(void *arg0, void *arg1);
    extern void qsort(void *base, size_t count, size_t size,
                      s32 (*compare)(const void *, const void *));
    extern s32 func_0014a160(void);
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
    u8 **ent;
    u8 *arrA[64];
    u8 *arrB[64];
    RwV3d pos;
    u8 *l12;
    u8 *l10;
    u8 *l11;
    u8 *l1;
    u8 *l3;
    u8 *l2;
    s32 flag;
    s32 flag2;
    s32 flag3;
    u32 n1;
    s32 n2;
    u8 *tmp;
    u8 *ex;
    s32 t;
    s32 i;
    s32 k;
    s32 j;
    u8 *cur;

    l12 = MT_Scene_GetResListHead(0xC);
    l10 = MT_Scene_GetResListHead(0xA);
    l11 = MT_Scene_GetResListHead(0xB);
    l1 = MT_Scene_GetResListHead(1);
    l3 = MT_Scene_GetResListHead(3);
    l2 = MT_Scene_GetResListHead(2);
    flag = 0;
    if (D_007642E4 == 1) {
        return 0;
    }
    if (*(s32 *)iGpffff9db0 >= 0xC8) {
        flag = 1;
    }
    while (l11 != NULL) {
        if (*(s32 *)(l11 + 0x28) & 2) {
            func_004b1210(D_005DC7D0, *(void **)(l11 + 0x144));
        }
        l11 = *(u8 **)(l11 + 0x138);
    }
    while (l12 != NULL) {
        if (*(s32 *)(l12 + 0x28) & 2) {
            func_00152930(D_00793EE0, *(u8 **)(l12 + 0x1A0));
            if (flag != 0) {
                func_00152bb0(D_00793F70, *(u8 **)(l12 + 0x1A0));
                func_00152cd0(D_00793F70, *(u8 **)(l12 + 0x1A0));
            } else {
                func_00152bb0(D_00794390, *(u8 **)(l12 + 0x1A0));
                func_00152cd0(D_00794390, *(u8 **)(l12 + 0x1A0));
            }
        }
        l12 = *(u8 **)(l12 + 0x138);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147640;
    *(u8 **)(tmp + 0x10) = D_007D22A0;
    if (flag != 0) {
        func_00460ac0(D_00793F40, tmp);
    } else {
        func_00460ac0(D_00794360, tmp);
    }
    while (l10 != NULL) {
        t = *(s32 *)(l10 + 0x28);
        if (t & 2) {
            if (t & 0x02000000) {
                func_00479100(D_007942D0, *(u8 **)(l10 + 0x144));
            } else if (t & 0x01000000) {
                func_00479100(D_007947E0, *(u8 **)(l10 + 0x144));
            } else if (func_00462e80(*(const u32 **)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    func_00479100(D_00793F10, *(u8 **)(l10 + 0x144));
                } else {
                    func_00479100(D_00794300, *(u8 **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00794300, ex);
                }
            } else if (func_00462df0(*(u8 **)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    func_00479100(D_00793F40, *(u8 **)(l10 + 0x144));
                } else {
                    func_00479100(D_00794360, *(u8 **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00794360, ex);
                }
            } else {
                func_00479100(D_00793EE0, *(u8 **)(l10 + 0x144));
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    func_00479100(D_00793EE0, ex);
                }
            }
        }
        l10 = *(u8 **)(l10 + 0x138);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147830;
    *(u8 **)(tmp + 0x10) = D_007D22A0;
    if (flag != 0) {
        func_00460ac0(D_00793F40, tmp);
    } else {
        func_00460ac0(D_00794360, tmp);
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147910;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    memset(arrA, 0, 0x100);
    n1 = 0;
    while (l1 != NULL) {
        if (n1 >= 0x40) {
            func_0046d730(D_005EFB00, 0x264);
        }
        arrA[n1] = l1;
        l1 = *(u8 **)(l1 + 0x138);
        n1 += 1;
    }
    if (*(s32 *)(iGpffff9db0 + 0x14) == 1) {
        qsort(arrA, n1, 4, func_00148000);
    }
    flag2 = 0;
    for (i = (s32)(n1 - 1); i >= 0; i--) {
        u8 **pp = &arrA[i];
        s32 flags = *(s32 *)(*pp + 0x28);

        if (flags & 2) {
            if (flags & 0x04000000) {
                flag2 = 1;
            } else {
                s32 j;

                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147bb0;
                *(u8 **)(tmp + 0x10) = *pp;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                if (func_0014a160() == 1 && (*(u16 *)*pp & 0x3FF) >= 100) {
                    func_00479100(D_007943F0, *(u8 **)(*pp + 0x164));
                } else {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*pp + 0x164));
                }
                if (*(u8 **)(*pp + 0x228) != NULL && (*(s32 *)(*pp + 0x28) & 0x20000000)) {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*pp + 0x228));
                }
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = *pp;
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(*pp + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(void **)(*pp + j * 4 + 0x140), (f32 *)&pos);
                        func_004b11d0(D_005DC824, *(void **)(*pp + j * 4 + 0x140));
                    }
                }
            }
        }
    }
    if (flag2 == 1) {
        u8 *obj = MT_Scene_GetResListHead(1);

        while (obj != NULL) {
            if (!(*(s32 *)(obj + 0x28) & 0x04000000)) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147910;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147bb0;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), *(u8 **)(obj + 0x164));
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147ae0;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (l3 != NULL) {
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_00147d80;
        *(u8 **)(tmp + 0x10) = NULL;
        func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    }
    memset(arrB, 0, 0x100);
    n2 = 0;
    while (l3 != NULL) {
        if (*(u8 *)((u8 *)mdlGetColor(*(void **)(l3 + 0x164)) + 3) < 0xFF) {
            arrB[n2] = l3;
            n2 += 1;
            l3 = *(u8 **)(l3 + 0x138);
        } else {
            s32 flags = *(s32 *)(l3 + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                s32 j;

                func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l3 + 0x164));
                if (*(u8 **)(l3 + 0x22C) != NULL && (*(s32 *)(l3 + 0x28) & 0x20000000)) {
                    func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l3 + 0x22C));
                }
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(l3 + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(l3 + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(l3 + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(void **)(l3 + j * 4 + 0x140), (f32 *)&pos);
                        func_004b11d0(D_005DC824, *(void **)(l3 + j * 4 + 0x140));
                    }
                }
            }
            l3 = *(u8 **)(l3 + 0x138);
        }
    }
    {
        u8 *obj = MT_Scene_GetResListHead(3);

        while (obj != NULL) {
            if (*(u8 *)((u8 *)mdlGetColor(*(void **)(obj + 0x164)) + 3) < 0xFF) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                s32 flags = *(s32 *)(obj + 0x28);

                if ((flags & 0x10000000) && (flags & 2)) {
                    tmp = func_00460990();
                    *(void **)(tmp + 8) = (void *)func_00147e60;
                    *(u8 **)(tmp + 0x10) = obj;
                    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                    if (*(s32 *)(obj + 0x28) & 0x80000000) {
                        s32 j;

                        func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(obj + 0x164));
                        if (*(u8 **)(obj + 0x22C) != NULL && (*(s32 *)(obj + 0x28) & 0x20000000)) {
                            func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(obj + 0x22C));
                        }
                        for (j = 0; j < 2; j++) {
                            if (*(s32 *)(obj + j * 4 + 0x140) != 0) {
                                if (func_0047a6d0(*(void **)(obj + 0x164), 2, &pos) == 0) {
                                    pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(obj + 0x164)) + 0x30);
                                    pos.y += 175.0f;
                                }
                                func_004b1250(*(void **)(obj + j * 4 + 0x140), (f32 *)&pos);
                                func_004b11d0(D_005DC824, *(void **)(obj + j * 4 + 0x140));
                            }
                        }
                    }
                }
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    flag3 = 0;
    while (l2 != NULL) {
        s32 flags = *(s32 *)(l2 + 0x28);

        if (flags & 2) {
            if (flags & 0x04000000) {
                flag3 = 1;
                continue;
            }
            if (flags & 0x10000) {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l2 + 0x158));
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0(D_007945A0, tmp);
                func_00479100(D_007945A0, *(u8 **)(l2 + 0x158));
            }
        }
        l2 = *(u8 **)(l2 + 0x138);
    }
    if (flag3 == 1) {
        u8 *obj = MT_Scene_GetResListHead(2);

        while (obj != NULL) {
            if (!(*(s32 *)(obj + 0x28) & 0x04000000)) {
                obj = *(u8 **)(obj + 0x138);
            } else {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147910;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147f30;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                func_00479100((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), *(u8 **)(obj + 0x158));
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147ae0;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (*(s32 *)(iGpffff9db0 + 0x18) == 1) {
        qsort(arrB, n2, 4, func_00148140);
    }
    if (n2 != 0) {
        tmp = func_00460990();
        *(void **)(tmp + 8) = (void *)func_00147d80;
        *(u8 **)(tmp + 0x10) = NULL;
        func_00460ac0(D_007945D0, tmp);
    }
    {
        for (k = n2 - 1; k >= 0; k--) {
            s32 flags;

            ent = &arrB[k];
            flags = *(s32 *)(*ent + 0x28);
            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                func_00479100(D_007945D0, *(u8 **)(*ent + 0x164));
                cur = (u8 *)ent;
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = *(u8 **)cur;
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(*(u8 **)cur + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(void **)(*(u8 **)cur + j * 4 + 0x140), (f32 *)&pos);
                    }
                }
            }
        }
    }    {
        for (k = n2 - 1; k >= 0; k--) {
            s32 flags = *(s32 *)(arrB[k] + 0x28);

            if ((flags & 0x10000000) && (flags & 2) && (flags & 0x80000000)) {
                tmp = func_00460990();
                *(void **)(tmp + 8) = (void *)func_00147e60;
                *(u8 **)(tmp + 0x10) = arrB[k];
                func_00460ac0(D_007945D0, tmp);
                func_00479100(D_007945D0, *(u8 **)(arrB[k] + 0x164));
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = arrB[k];
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (func_0047a6d0(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(arrB[k] + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(void **)(arrB[k] + j * 4 + 0x140), (f32 *)&pos);
                    }
                }
            }
        }
    }
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = func_00460990();
    *(void **)(tmp + 8) = (void *)func_00147ae0;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    return 0;
}
#pragma pop
/* The incoming parent is forwarded to the task allocator, which attaches
   the new task when it is non-null. The constructor remains 96/96 bytes. */
// FUN_00149620
u8 *func_00149620(u8 *ctx) {
    u8 *o;

    o = func_00451fc0((void *)(ctx), (const void *)(D_005EFB10), 0xC7, 0, 0, func_00148280, 0, (u8 *)(NULL));
    FldShadow_SpawnCasterTask(o);
    return o;
}

// FUN_00149680
void func_00149680(s32 arg0) {
    D_007642E4 = arg0;
}



// FUN_00149690
void func_00149690(s32 arg0) {
    if (arg0 == 0) {
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
void func_001496c0(void *value) {
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
        func_001538a0(*(u32 **)(resource + 0x1A0), (const f32 *)factors);
        resource = *(u8 **)(resource + 0x138);
    }
    if ((*(f32 *)(factors + 0) <= 0.0f && *(f32 *)(factors + 4) <= 0.0f && *(f32 *)(factors + 8) <= 0.0f) || *(f32 *)(factors + 0xC) <= 0.0f) {
        func_0014a000(0, 1);
    } else {
        func_0014a000(1, 1);
    }
    colorBytes = (u8 *)func_00457160();
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
    func_00457140(red & 0xFF, green & 0xFF, blue & 0xFF, alpha & 0xFF);
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
u8 *func_00149ca0(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x140;
}
// FUN_00149CE0
u8 *func_00149ce0(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x150;
}
// FUN_00149D20
u8 *func_00149d20(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x160;
}
// FUN_00149D60
void func_00149d60(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    func_00153b20(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149DB0
void func_00149db0(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    func_00153b60(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E00
void func_00149e00(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    func_00153b90(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E50
void func_00149e50(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    func_00153bd0(*(s32 *)(D_00762EA0 + 32), arg0);
}

/* measured: opt_rebuildconditionals off is scoped to func_00149ea0. */
#pragma opt_rebuildconditionals off

// FUN_00149EA0
void func_00149ea0(void)
{
    extern f32 fGpffff8198;
    extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    s32 stack[3];
    f32 temp_f0;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *var_17;
    u8 *var_18;
    u8 *var_16;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        var_17 = NULL;
    } else {
        var_17 = temp_2 + 0x140;
    }
    temp_2_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2_2 == NULL) {
        var_18 = NULL;
    } else {
        var_18 = temp_2_2 + 0x150;
    }
    temp_2_3 = MT_Scene_GetResListHead(0xC);
    if (temp_2_3 == NULL) {
        var_16 = NULL;
    } else {
        var_16 = temp_2_3 + 0x160;
    }
    temp_f0 = fGpffff8198;
    *(f32 *)(var_17 + 0) = temp_f0;
    *(f32 *)(var_17 + 4) = temp_f0;
    *(f32 *)(var_17 + 8) = temp_f0;
    *(s32 *)(var_17 + 0xC) = 0;
    *(s32 *)(var_18 + 0) = 0x3F000000;
    *(s32 *)(var_18 + 4) = 0x3F000000;
    *(s32 *)(var_18 + 8) = 0x3F000000;
    *(s32 *)(var_18 + 0xC) = 0;
    *(s32 *)(var_16 + 0x28) = 0x3F800000;
    *(s32 *)(var_16 + 0x14) = 0x3F800000;
    *(s32 *)(var_16 + 0) = 0x3F800000;
    *(s32 *)(var_16 + 0x10) = 0;
    *(s32 *)(var_16 + 8) = 0;
    *(s32 *)(var_16 + 4) = 0;
    *(s32 *)(var_16 + 0x24) = 0;
    *(s32 *)(var_16 + 0x20) = 0;
    *(s32 *)(var_16 + 0x18) = 0;
    *(s32 *)(var_16 + 0x38) = 0;
    *(s32 *)(var_16 + 0x34) = 0;
    *(s32 *)(var_16 + 0x30) = 0;
    *(s32 *)(var_16 + 0xC) = *(s32 *)(var_16 + 0xC) | 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    RwMatrixRotate(var_16, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    RwMatrixRotate(var_16, &stack[0], 2, -45.0f);
}
/* measured: closes opt_rebuildconditionals for func_00149ea0. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a000. */
#pragma opt_rebuildconditionals off

/* measured: loop-invariant constants probe for func_0014a000. */
#pragma opt_loop_invariants on
// FUN_0014A000
void func_0014a000(s32 arg0, s32 arg1)
{
    u8 *var_16;
    u8 *var_6;
    s32 one;
    s32 mask;
    var_16 = MT_Scene_GetResListHead(0xC);
    var_6 = MT_Scene_GetResListHead(0xA);
    one = 1;
    mask = -3;
    goto loop_5_test;
loop_5_body:
    if (arg0 == one) {
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) | 2;
    } else {
        *(s32 *)(var_16 + 0x28) = *(s32 *)(var_16 + 0x28) & mask;
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_5_test:
    if (var_16 != NULL) {
        goto loop_5_body;
    }
    if (arg1 != one) {
        goto done;
    }
    goto loop_12_test;
loop_12_body:
    if (arg0 == one) {
        *(s32 *)(var_6 + 0x28) = *(s32 *)(var_6 + 0x28) | 2;
    } else {
        *(s32 *)(var_6 + 0x28) = *(s32 *)(var_6 + 0x28) & mask;
    }
    var_6 = *(u8 **)(var_6 + 0x138);
loop_12_test:
    if (var_6 != NULL) {
        goto loop_12_body;
    }
done:
    ;
}
/* measured: closes loop-invariant constants probe for func_0014a000. */
#pragma opt_loop_invariants off
/* measured: closes opt_rebuildconditionals for func_0014a000. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a160. */
#pragma opt_rebuildconditionals off

// FUN_0014A160
s32 func_0014a160(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    return func_0014a190(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
/* measured: closes opt_rebuildconditionals for func_0014a160. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a190. */
#pragma opt_rebuildconditionals off

// FUN_0014A190
s32 func_0014a190(s32 arg0, s32 arg1) {
    if (func_0014a230(arg0, arg1) == 1) {
        return 1;
    }
    return func_0014a2a0(arg0, arg1) == 1;
}
/* measured: closes opt_rebuildconditionals for func_0014a190. */
#pragma opt_rebuildconditionals on

// FUN_0014A200
s32 func_0014a200(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    return func_0014a230(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
// FUN_0014A230
s32 func_0014a230(s32 arg0, s32 arg1) {
    s32 result;

    arg0 &= 0xFFFF;
    if (arg0 < 0x28) {
        goto false_0014a230;
    }
    if (arg0 >= 0x3C) {
        goto false_0014a230;
    }
    if ((arg1 & 0xFFFF) != 0) {
        goto false_0014a230;
    }
    result = 1;
    goto done_0014a230;
false_0014a230:
    result = 0;
done_0014a230:
    return result;
}
// FUN_0014A270
s32 func_0014a270(void) {
    u8 *temp_2;

    temp_2 = iGpffff9db0;
    return func_0014a2a0(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4));
}
// FUN_0014A2A0
s32 func_0014a2a0(s32 arg0, s32 arg1) {
    s32 result;

    arg0 &= 0xFFFF;
    if (arg0 < 0x3C) {
        goto false_0014a2a0;
    }
    if (arg0 >= 0x50) {
        goto false_0014a2a0;
    }
    result = 1;
    goto done_0014a2a0;
false_0014a2a0:
    result = 0;
done_0014a2a0:
    return result;
}
// FUN_0014A2F0
void func_0014a2f0(s32 arg0)
{
    *(s32 *)(iGpffff9db0 + 0x18) = arg0;
}

// FUN_0014B1E0
void func_0014b1e0(void) {
    extern f32 fGpffff8198;
    extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    s32 stack[3];
    f32 temp_f0;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *var_16;
    u8 *var_17;
    u8 *var_18;
    u8 *var_19;
    u8 *var_20;

    temp_2 = MT_Scene_GetResListHead(5);
    if (temp_2 != NULL) {
        var_20 = temp_2 + 0x140;
    } else {
        var_20 = NULL;
    }
    temp_2_2 = MT_Scene_GetResListHead(5);
    if (temp_2_2 != NULL) {
        var_19 = temp_2_2 + 0x150;
    } else {
        var_19 = NULL;
    }
    temp_2_3 = MT_Scene_GetResListHead(5);
    if (temp_2_3 != NULL) {
        var_17 = temp_2_3 + 0x160;
    } else {
        var_17 = NULL;
    }
    temp_2_4 = MT_Scene_GetResListHead(5);
    if (temp_2_4 != NULL) {
        var_18 = temp_2_4 + 0x1A0;
    } else {
        var_18 = NULL;
    }
    temp_2_5 = MT_Scene_GetResListHead(5);
    if (temp_2_5 != NULL) {
        var_16 = temp_2_5 + 0x1B0;
    } else {
        var_16 = NULL;
    }
    temp_f0 = fGpffff8198;
    *(f32 *)(var_20 + 0) = temp_f0;
    *(f32 *)(var_20 + 4) = temp_f0;
    *(f32 *)(var_20 + 8) = temp_f0;
    *(s32 *)(var_20 + 0xC) = 0;
    *(s32 *)(var_19 + 0) = 0x3F000000;
    *(s32 *)(var_19 + 4) = 0x3F000000;
    *(s32 *)(var_19 + 8) = 0x3F000000;
    *(s32 *)(var_19 + 0xC) = 0;
    *(s32 *)(var_18 + 0) = 0;
    *(s32 *)(var_18 + 4) = 0;
    *(s32 *)(var_18 + 8) = 0;
    *(s32 *)(var_18 + 0xC) = 0;
    *(s32 *)(var_17 + 0x28) = 0x3F800000;
    *(s32 *)(var_17 + 0x14) = 0x3F800000;
    *(s32 *)(var_17 + 0) = 0x3F800000;
    *(s32 *)(var_17 + 0x10) = 0;
    *(s32 *)(var_17 + 8) = 0;
    *(s32 *)(var_17 + 4) = 0;
    *(s32 *)(var_17 + 0x24) = 0;
    *(s32 *)(var_17 + 0x20) = 0;
    *(s32 *)(var_17 + 0x18) = 0;
    *(s32 *)(var_17 + 0x38) = 0;
    *(s32 *)(var_17 + 0x34) = 0;
    *(s32 *)(var_17 + 0x30) = 0;
    *(s32 *)(var_17 + 0xC) |= 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    RwMatrixRotate(var_17, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    RwMatrixRotate(var_17, &stack[0], 2, -45.0f);
    *(s32 *)(var_16 + 0x28) = 0x3F800000;
    *(s32 *)(var_16 + 0x14) = 0x3F800000;
    *(s32 *)(var_16 + 0) = 0x3F800000;
    *(s32 *)(var_16 + 0x10) = 0;
    *(s32 *)(var_16 + 8) = 0;
    *(s32 *)(var_16 + 4) = 0;
    *(s32 *)(var_16 + 0x24) = 0;
    *(s32 *)(var_16 + 0x20) = 0;
    *(s32 *)(var_16 + 0x18) = 0;
    *(s32 *)(var_16 + 0x38) = 0;
    *(s32 *)(var_16 + 0x34) = 0;
    *(s32 *)(var_16 + 0x30) = 0;
    *(s32 *)(var_16 + 0xC) |= 0x20003;
    stack[0] = 0;
    stack[1] = 0x3F800000;
    stack[2] = 0;
    RwMatrixRotate(var_16, &stack[0], 2, -180.0f);
    stack[0] = 0x3F800000;
    stack[1] = 0;
    stack[2] = 0;
    RwMatrixRotate(var_16, &stack[0], 2, -45.0f);
}
// FUN_0014B450
s32 func_0014b450(void) {
    s32 var_3;
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0x14);
    var_3 = 0;
    if (temp_2 != NULL) {
        var_3 = *(s32 *)(temp_2 + 0x148);
    }
    return var_3;
}
// FUN_0014B490
s32 func_0014b490(void) {
    s32 var_3;
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0x14);
    var_3 = 0;
    if (temp_2 != NULL) {
        var_3 = *(s32 *)(temp_2 + 0x14C);
    }
    return var_3;
}
// FUN_0014B4D0
f32 func_0014b4d0(void) {
    f32 var_f0;
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0x14);
    var_f0 = 0.0f;
    if (temp_2 != NULL) {
        var_f0 = *(f32 *)(temp_2 + 0x144);
    }
    return var_f0;
}
// FUN_0014B510
u16 func_0014b510(s32 arg0)
{
    s32 var_17;
    s32 temp_16;
    u8 *var_2;

    var_17 = 0;
    temp_16 = arg0 & 0xFFFF;
    var_2 = MT_Scene_GetResListHead(temp_16);
    while (var_2 != NULL) {
        if ((*(u16 *)var_2 & 0x3FF) == var_17) {
            var_17 += 1;
            var_2 = MT_Scene_GetResListHead(temp_16);
        } else {
            var_2 = *(u8 **)(var_2 + 0x138);
        }
    }
    return var_17 & 0xFFFF;
}

// FUN_0014B590
f32 func_0014b590(f32 fparg0) {
    s32 integer;
    f32 result;

    integer = (s32)fparg0;
    result = (f32)integer;
    if (!((fparg0 - result) < 0.5f)) {
        result = (f32)(integer + 1);
    }
    return result;
}
// FUN_0014B780
s32 func_0014b780(u8 *arg0) {
    s32 temp_2;
    s32 temp_3;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)p;
    switch (temp_3) {
    case 0:
        if (func_004782b0(*(s32 *)(p + 8)) != 0) {
            *(s32 *)p = *(s32 *)p + 1;
        }
        goto done;
    case 1:
        temp_2 = *(s32 *)(p + 4) - 1;
        *(s32 *)(p + 4) = temp_2;
        if (temp_2 > 0) {
            goto done;
        }
        *(s32 *)p = *(s32 *)p + 1;
    case 2:
        func_004787e0(*(s32 *)(p + 8));
        return -1;
    default:
    done:
        return 0;
    }
}
// FUN_0014B840
void func_0014b840(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014BD90
s32 func_0014bd90(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) == 1;
}
/* 416/416 bytes; eight resolved relocations, no tail or overrun.
 * D_005EFB98 is one 12-byte (0,1,0) vector, not separate XY/Z objects.
 * Its aggregate copy preserves the grouped retail load/store schedule.
 * The predicate and subsequent height checks share the live triangle. */
// FUN_0014BE50
u16 func_0014be50(u8 *arg0, u8 **arg1) {
    f32 *triangle[3];
    RwV3d normal;
    f32 pointY;
    f32 secondPointY;
    f32 surfaceY;
    f32 secondSurfaceY;
    u16 selectedId;
    u8 *surface;

    selectedId = 0xFFFF;
    surface = (u8 *)(MT_Scene_GetResListHead(0xD));
    if (func_0014a200() == 1) {
        return 0xFFFFU;
    }
    while (surface != NULL) {
        normal = D_005EFB98;
        triangle[0] = (f32 *)(surface + 0x15C);
        triangle[1] = (f32 *)(surface + 0x168);
        triangle[2] = (f32 *)(surface + 0x174);
        if ((K_FldFrame_IsPointInTriangle((f32 *)arg0, triangle, (f32 *)&normal) == 1) &&
            (surfaceY = triangle[0][1],
             pointY = *(f32 *)(arg0 + 4),
             (pointY < (100.0f + surfaceY))) &&
            !(pointY <= (surfaceY - 100.0f))) {
            selectedId = *(u16 *)surface;
            *arg1 = surface;
            goto done;
        }
        triangle[0] = (f32 *)(surface + 0x168);
        triangle[1] = (f32 *)(surface + 0x174);
        triangle[2] = (f32 *)(surface + 0x180);
        if ((K_FldFrame_IsPointInTriangle((f32 *)arg0, triangle, (f32 *)&normal) == 1) &&
            (secondSurfaceY = triangle[0][1],
             secondPointY = *(f32 *)(arg0 + 4),
             (secondPointY < (100.0f + secondSurfaceY))) &&
            !(secondPointY <= (secondSurfaceY - 100.0f))) {
            selectedId = *(u16 *)surface;
            *arg1 = surface;
            goto done;
        }
        surface = *(u8 **)(surface + 0x138);
    }
done:
    return selectedId;
}
// FUN_0014C540
u8 *func_0014c540(u8 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    RwV3d vec_x;
    RwV3d vec_y;
    f32 best;
    u8 *result;
    s32 i;
    u8 **saved_entry;
    u8 **entry;
    u8 *arg;
    u8 *temp_2;
    u8 *temp_2_2;
    struct C540Stack {
        RwV3d v80;
        RwV3d v8c;
        u8 pad98[8];
        RwV3d hitPoint;
        u8 padAC[4];
        f32 diffB0[3];
    } stack;
    extern s32 K_FldEvent_IsPosWithinFov(u8 *arg0, u8 *arg1, f32 fparg0);
    extern f32 fGpffff82b4;
    extern u8 *D_007E8020_abs[];

    arg = arg0;
    result = NULL;
    best = fGpffff82b4;
    i = 0;
    goto loop_test_0014c540;
loop_body_0014c540:
    saved_entry = (u8 **)(D_007E8020 + (i * 4));
    if (*saved_entry != 0) {
        if (K_FldEvent_IsPosWithinFov((u8 *)mdlGetMatrix(*(void **)(arg + 0x50)),
                          (u8 *)mdlGetMatrix(*(void **)(*saved_entry + 0x50)) + 0x30,
                          fparg1) != 0) {
            entry = D_007E8020_abs + (u32)i;
            temp_f23 = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x30);
            stack.diffB0[0] = temp_f23 -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(arg + 0x50)) + 0x30);
            temp_f23_2 = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x34);
            stack.diffB0[1] = temp_f23_2 -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(arg + 0x50)) + 0x34);
            temp_f23_3 = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x38);
            stack.diffB0[2] = temp_f23_3 -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(arg + 0x50)) + 0x38);
            temp_2 = (u8 *)mdlGetMatrix(*(void **)(arg + 0x50));
            vec_x = *(RwV3d *)(temp_2 + 0x30);
            stack.v80 = vec_x;
            temp_2_2 = (u8 *)mdlGetMatrix(*(void **)(*entry + 0x50));
            vec_y = *(RwV3d *)(temp_2_2 + 0x30);
            stack.v8c = vec_y;
            stack.v80.y += 100.0f;
            stack.v8c.y += 100.0f;
            if (func_0016b540(&stack.v80, &stack.hitPoint) == 0) {
                temp_f0 = RwV3dLength(stack.diffB0);
                if ((temp_f0 < fparg0) && (temp_f0 < best)) {
                    result = *saved_entry;
                    best = temp_f0;
                }
            }
        }
    }
    i += 1;
loop_test_0014c540:
    if (i < 8) {
        goto loop_body_0014c540;
    }
    return result;
}
/* measured probe: optimization_level 1 on c780. */
#pragma optimization_level 1
// FUN_0014C780
s32 func_0014c780(void) {
    s32 index;
    s32 count;
    s32 sum;
    s32 hit;
    s32 valid;
    u8 *entry;

    sum = 0;
    index = 0;
    count = 0;
    goto loop_test_0014c780;
loop_body_0014c780:
    hit = 0;
    entry = D_007EF9B0 + (index * 0x750);
    if ((*(s32 *)(entry + 0x48) != 0) &&
        (*(s32 *)(entry + 0x54) != 0)) {
        hit = 1;
    }
    valid = hit != 0;
    if (valid == (hit = 1)) {
        if (index == 0) {
            sum += func_00104c70(hit) & 0xFF;
        } else {
            sum += *(s32 *)(entry + 0x1C0);
        }
        count += 1;
    }
    index += 1;
loop_test_0014c780:
    if (index < 4) {
        goto loop_body_0014c780;
    }
    return sum / count;
}
/* measured: restore optimization_level 2 after func_0014c780. */
#pragma optimization_level 2
// FUN_0014C850
s32 *func_0014c850(u8 *arg0, f32 fparg0, f32 fparg1) {
    u8 *temp_18;
    u8 *temp_19;
    s32 var_16;
    u8 *temp_2;

    var_16 = 0;
    goto loop_test_0014c850;
loop_body_0014c850:
    if (*(s32 *)temp_18 != 0) {
        if (func_0014c240((u8 *)mdlGetMatrix(*(void **)(arg0 + 0x50)),
                          temp_18 + 0x150, fparg1, fparg0) != 0) {
            return *(s32 **)temp_19;
        }
    }
    var_16 += 1;
loop_test_0014c850:
    temp_2 = D_007E8020 + (var_16 * 4);
    temp_19 = temp_2 + 0x20;
    temp_18 = *(u8 **)temp_19;
    if (temp_18 != NULL) {
        goto loop_body_0014c850;
    }
    return NULL;
}
// FUN_0014C920
void func_0014c920(void) {
    iGpffffb1f8 = 0;
    iGpffffb1fc = 0;
    memset(&D_007D24B0, 0, 0x30);
}
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
/* measured: byte-exact (354/354 instructions, 0 differing words).  The three
   occupancy scans are block-scoped so each `clear` flag lives where retail
   keeps it ($v0 reusing the test's 1, $s6 across the list walk's calls, $t2).
   The grid is a u16 row array: `D_007D24B0[y + 1]` folds to the symbol+2
   base retail uses for the final mark.  The mark's bits are `(u16)(1U << x)`
   so they are not CSE'd with the signed occupancy test's `1 << x`.
   opt_loop_invariants hoists 600.0f/1200.0f, x+1/y+1 and the table bases. */
#pragma opt_loop_invariants on
// FUN_0014C960
s32 func_0014c960(s32 *arg0, s32 *arg1)
{
    s32 y;
    s32 x;
    s32 rowOffset;
    u16 *row;
    s32 cellOffset;

    for (y = iGpffffb1fc; y < 0x18; y++) {
        x = iGpffffb1f8;
        rowOffset = y << 8;
        row = &D_007D24B0[y];
        for (; x < 0x10; x++) {
            cellOffset = x << 4;
            if (*(func_00155280() + rowOffset + cellOffset + 0x54) != 1) {
                continue;
            }
            if (*(func_00155280() + rowOffset + cellOffset + 0x58) != 9 &&
                *(func_00155280() + rowOffset + cellOffset + 0x58) != 11 &&
                *(func_00155280() + rowOffset + cellOffset + 0x58) != 13) {
                continue;
            }
            if ((*(func_00155280() + rowOffset + cellOffset + 0x55) & 0xF0) != 0x20) {
                continue;
            }
            if (((1 << x) & row[0]) != 0) {
                continue;
            }
            {
                s32 i;
                s32 clear;
                u8 *entry;
                s32 cellX;
                s32 cellY;

                clear = 1;
                for (i = 0; i < 8; i++) {
                    entry = D_007E80A0 + i * 0x168;
                    if (*(s32 *)entry != 0) {
                        cellX = (s32)((600.0f + *(f32 *)(entry + 0x150)) / 1200.0f);
                        cellY = (s32)((600.0f + *(f32 *)(entry + 0x158)) / 1200.0f);
                        if (FLD_GRID_HITS(cellX, cellY, x, y)) {
                            fldGridMark(x, y);
                            clear = 0;
                            break;
                        }
                    }
                }
                if (clear == 0) {
                    continue;
                }
            }
            {
                s32 clear;
                u8 *obj;
                s32 cellX;
                s32 cellY;

                clear = 1;
                for (obj = MT_Scene_GetResListHead(3); obj != NULL; obj = *(u8 **)(obj + 0x138)) {
                    cellX = (s32)((600.0f + *(f32 *)((u8 *)mdlGetMatrix(*(void **)(obj + 0x164)) + 0x30)) / 1200.0f);
                    cellY = (s32)((600.0f + *(f32 *)((u8 *)mdlGetMatrix(*(void **)(obj + 0x164)) + 0x38)) / 1200.0f);
                    if (FLD_GRID_HITS(cellX, cellY, x, y)) {
                        fldGridMark(x, y);
                        clear = 0;
                        break;
                    }
                }
                if (clear == 0) {
                    continue;
                }
            }
            {
                s32 clear;
                s32 i;
                u8 *entry;
                s32 cellX;
                s32 cellY;

                clear = 1;
                for (i = 0; i < 15; i++) {
                    entry = D_007E8C00 + i * 0x750;
                    if (*(s32 *)(entry + 0x48) != 0) {
                        cellX = (s32)((600.0f + *(f32 *)(entry + 0x19C)) / 1200.0f);
                        cellY = (s32)((600.0f + *(f32 *)(entry + 0x1A4)) / 1200.0f);
                        if (FLD_GRID_HITS(cellX, cellY, x, y)) {
                            fldGridMark(x, y);
                            clear = 0;
                            break;
                        }
                    }
                }
                if (clear == 0) {
                    continue;
                }
            }
            *arg0 = x;
            *arg1 = y;
            fldGridMark(x, y);
            iGpffffb1fc = y;
            iGpffffb1f8 = x;
            return 1;
        }
        iGpffffb1f8 = 0;
    }
    return 0;
}
#pragma pop
/* measured probe: opt_loop_invariants on hoists the 600.0f/1200.0f constants. */
#pragma opt_loop_invariants on
// FUN_0014CEF0
u8 *func_0014cef0(s32 arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_16;
    s32 temp_17;
    u8 *var_2;

    var_2 = MT_Scene_GetResListHead(0xF);
    goto loop_test_0014cef0;
loop_body_0014cef0:
    temp_f0 = (600.0f + *(f32 *)(var_2 + 0x140)) / 1200.0f;
    temp_f0_2 = (600.0f + *(f32 *)(var_2 + 0x148)) / 1200.0f;
    temp_16 = (s32)temp_f0;
    temp_17 = (s32)temp_f0_2;
    if (((temp_16 == arg0) && (temp_17 == arg1)) ||
        ((temp_16 == (arg0 + 1)) && (temp_17 == arg1)) ||
        ((temp_16 == arg0) && (temp_17 == (arg1 + 1))) ||
        ((temp_16 == (arg0 + 1)) && (temp_17 == (arg1 + 1)))) {
        return var_2;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
loop_test_0014cef0:
    if (var_2 != NULL) {
        goto loop_body_0014cef0;
    }
    return NULL;
}
/* measured: restore opt_loop_invariants off after func_0014cef0. */
#pragma opt_loop_invariants off
// FUN_0014CFD0
s32 func_0014cfd0(u8 *arg0)
{
    s32 temp_21;
    s32 temp_20;
    u16 temp_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;
    s32 temp_19_2;
    s32 temp_16_2;
    s32 temp_3;
    u8 *var_19;
    extern u8 *func_00155280(void);
    {
        f32 temp_f2;

        temp_f2 = 600.0f;
        temp_f2 += *(f32 *)(arg0 + 0);
        var_18 = (s32)(temp_f2 / 1200.0f);
    }
    var_17 = (s32)((600.0f + *(f32 *)(arg0 + 8)) / 1200.0f);
    temp_16 = var_17 << 8;
    temp_21 = var_18 << 4;
    temp_19 = *(u16 *)(func_00155280() + temp_16 + temp_21 + 0x56);
    if ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 9) &&
        (*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 0xB) &&
        (*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x58) != 0xD)) {
        return 0;
    }
    if ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x55) & 0x20) == 0) {
        return 0;
    }
    temp_20 = temp_19;
    if ((temp_20 == *(u16 *)(func_00155280() + temp_16 + temp_21 + 0x46)) &&
        ((*(u8 *)(func_00155280() + temp_16 + temp_21 + 0x45) & 0x20) != 0)) {
        var_18 -= 1;
    }
    temp_19_2 = var_18 * 0x10;
    if ((temp_20 == *(u16 *)(func_00155280() + temp_16 + temp_19_2 - 0xAA)) &&
        ((*(u8 *)(func_00155280() + temp_16 + temp_19_2 - 0xAB) & 0x20) != 0)) {
        var_17 -= 1;
    }
    var_19 = MT_Scene_GetResListHead(3);
    goto loop_test_0014cfd0;
loop_body_0014cfd0:
    temp_16_2 = (s32)((600.0f +
                       *(f32 *)((u8 *)mdlGetMatrix(*(void **)(var_19 + 0x164)) + 0x30)) /
                      1200.0f);
    temp_3 = (s32)((600.0f +
                    *(f32 *)((u8 *)mdlGetMatrix(*(void **)(var_19 + 0x164)) + 0x38)) /
                   1200.0f);
    if (((temp_16_2 == var_18) && (temp_3 == var_17)) ||
        ((temp_16_2 == (var_18 + 1)) && (temp_3 == var_17)) ||
        ((temp_16_2 == var_18) && (temp_3 == (var_17 + 1))) ||
        ((temp_16_2 == (var_18 + 1)) && (temp_3 == (var_17 + 1)))) {
        return 1;
    }
    var_19 = *(u8 **)(var_19 + 0x138);
loop_test_0014cfd0:
    if (var_19 != NULL) {
        goto loop_body_0014cfd0;
    }
    return 0;
}
// FUN_0014D290
void func_0014d290(u8 *arg0, u8 *arg1)
{
    extern void func_003bb5b0(u8 *arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4);
    extern s32 func_003bb330(u8 *arg0);
    extern void func_003bb3a0(u8 *arg0, s32 arg1, void *arg2);
    extern void primLine3D(void *arg0, void *arg1, void *arg2, s32 arg3);
    extern void primSphereLine3D(u8 *position, f32 size, u8 *color, s32 setStates);
    extern f32 D_005EFBB8[];
    extern u8 D_005EFBBC[];
    extern u8 D_005EFBBD[];
    extern u8 D_005EFBBE[];
    extern u8 D_005EFBBF[];
    extern u8 D_005EFBC0[];
    extern u8 D_005EFBC1[];
    extern u8 D_005EFBC2[];
    extern u8 D_005EFBC3[];
    f32 sp40[3];
    f32 sp30[3];
    P4Bytes0014 sp4C;
    s32 var_16;
    s32 var_16_2;
    s32 temp_3;
    f32 temp_f0;
    f32 temp_f1;

    var_16 = 0;
    while (var_16 < *(s32 *)(arg1 + 4)) {
        temp_3 = *(s32 *)(arg1 + 4);
        func_003bb5b0(*(u8 **)(arg1 + 0xC), 0xA, sp40, 0,
                      (1.0f / (f32)temp_3) * (f32)var_16);
        temp_f0 = (f32)*(s32 *)(arg1 + 4);
        temp_f1 = p4_0014_recip(temp_f0);
        func_003bb5b0(*(u8 **)(arg1 + 0xC), 0xA, sp30, 0,
                      temp_f1 * (f32)(var_16 + 1));
        primLine3D(sp40, sp30, arg1 + 8, 1);
        var_16 += 1;
    }
    var_16_2 = 0;
    while (var_16_2 < func_003bb330(*(u8 **)(arg1 + 0xC))) {
        if (var_16_2 == 1) {
            *(f32 *)&sp4C = D_005EFBB8[0];
        } else if (var_16_2 == (func_003bb330(*(u8 **)(arg1 + 0xC))) - 2) {
            sp4C = *(P4Bytes0014 *)D_005EFBBC;
        } else {
            sp4C = *(P4Bytes0014 *)D_005EFBC0;
        }
        func_003bb3a0(*(u8 **)(arg1 + 0xC), var_16_2, sp40);
        primSphereLine3D((u8 *)sp40, 5.0f, (u8 *)&sp4C, 1);
        var_16_2 += 1;
    }
}
// FUN_0014D470
s32 func_0014d470(u8 *arg0)
{
    u8 *work;
    u8 *obj;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = func_00460990();
    *(void **)(obj + 8) = func_0014d290;
    *(void **)(obj + 0x10) = work;
    func_00460ac0(*(void **)(work + 0x110), obj);
    return 0;
}

// FUN_0014D4E0
void func_0014d4e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}







// FUN_0014DCD0
void func_0014dcd0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44) = arg1;
}

// FUN_0014DCE0
void func_0014dce0(u8 *arg0, u8 *arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(Rgba8_0014 *)(p + 0x48) = *(Rgba8_0014 *)arg1;
}
// FUN_0014DD10
void func_0014dd10(u8 *arg0, u8 *arg1) {
    f32 sp20[4];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(SVec3 *)(temp_16 + 0x30) = *(SVec3 *)arg1;
    RwEngineGetMatrixTolerances(&sp20[0]);
    RwMatrixOptimize(temp_16, &sp20[0]);
    RwMatrixUpdate(temp_16);
}



/* measured probe: opt_propagation off preserves 0014dd80 vtable and float stores. */
#pragma opt_propagation off
// FUN_0014DD80
void func_0014dd80(u8 *arg0, u8 *arg1) {
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 0);
    base[0](7, 2);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](2, 3);
    base[0](0xC, 1);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    if (*(s32 **)(arg1 + 0x100) != NULL) {
        *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x108);
        *(f32 *)(arg1 + 0x14) = *(f32 *)(arg1 + 0x10C);
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x110);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x10C);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x108);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x114);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x110);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x114);
        base[0](1, *(u32 *)(*(s32 **)(arg1 + 0x100)));
        return;
    }
    base[0](1, 0);
}
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
/* Matched.  The near Z is RwIm2DGetNearScreenZ(), a member of RenderWare's
   ourGlobals reached through the RwGlobals/RwDevice prefix above: read
   twice around the camera call it keeps its address in $s5 without the
   volatile pointer the old floor used.  The colour loop's counter and
   vertex pointer are block-scoped, which is what puts the index in $a1
   instead of $v0, and the four bytes convert as (f32)(u32) so MWCC emits
   its own bltz/srl/or/cvt/add.s sequence.  No pragma. */
// FUN_0014DEF0
void func_0014def0(u8 *arg0, u8 *arg1,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, u8 *arg2, s32 arg3,
                   f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                   f32 arg_sp0)
{
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    f32 z;
    f32 inverse;
    f32 right;
    f32 bottom;
    u8 *entry;

    z = RwIm2DGetNearScreenZ() - fparg2;
    if (fparg2 == 0.0f) {
        z = RwIm2DGetNearScreenZ() - *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
    }
    inverse = 1.0f / z;
    switch (arg4) {
    case 0:
        *(f32 *)(arg1 + 0) = fparg0;
        *(f32 *)(arg1 + 4) = fparg1;
        *(f32 *)(arg1 + 8) = z;
        right = fparg0 + fparg3;
        *(f32 *)(arg1 + 0x40) = right;
        *(f32 *)(arg1 + 0x44) = fparg1;
        *(f32 *)(arg1 + 0x48) = z;
        *(f32 *)(arg1 + 0x80) = fparg0;
        bottom = fparg1 + fparg4;
        *(f32 *)(arg1 + 0x84) = bottom;
        *(f32 *)(arg1 + 0x88) = z;
        *(f32 *)(arg1 + 0xC0) = right;
        *(f32 *)(arg1 + 0xC4) = bottom;
        *(f32 *)(arg1 + 0xC8) = z;
        break;
    case 1:
        *(f32 *)(arg1 + 0x40) = fparg0;
        *(f32 *)(arg1 + 0x44) = fparg1;
        *(f32 *)(arg1 + 0x48) = z;
        right = fparg0 + fparg3;
        *(f32 *)(arg1 + 0xC0) = right;
        *(f32 *)(arg1 + 0xC4) = fparg1;
        *(f32 *)(arg1 + 0xC8) = z;
        *(f32 *)(arg1 + 0) = fparg0;
        bottom = fparg1 + fparg4;
        *(f32 *)(arg1 + 4) = bottom;
        *(f32 *)(arg1 + 8) = z;
        *(f32 *)(arg1 + 0x80) = right;
        *(f32 *)(arg1 + 0x84) = bottom;
        *(f32 *)(arg1 + 0x88) = z;
        break;
    case 2:
        *(f32 *)(arg1 + 0xC0) = fparg0;
        *(f32 *)(arg1 + 0xC4) = fparg1;
        *(f32 *)(arg1 + 0xC8) = z;
        right = fparg0 + fparg3;
        *(f32 *)(arg1 + 0x80) = right;
        *(f32 *)(arg1 + 0x84) = fparg1;
        *(f32 *)(arg1 + 0x88) = z;
        *(f32 *)(arg1 + 0x40) = fparg0;
        bottom = fparg1 + fparg4;
        *(f32 *)(arg1 + 0x44) = bottom;
        *(f32 *)(arg1 + 0x48) = z;
        *(f32 *)(arg1 + 0) = right;
        *(f32 *)(arg1 + 4) = bottom;
        *(f32 *)(arg1 + 8) = z;
        break;
    case 3:
        *(f32 *)(arg1 + 0x80) = fparg0;
        *(f32 *)(arg1 + 0x84) = fparg1;
        *(f32 *)(arg1 + 0x88) = z;
        right = fparg0 + fparg3;
        *(f32 *)(arg1 + 0) = right;
        *(f32 *)(arg1 + 4) = fparg1;
        *(f32 *)(arg1 + 8) = z;
        *(f32 *)(arg1 + 0xC0) = fparg0;
        bottom = fparg1 + fparg4;
        *(f32 *)(arg1 + 0xC4) = bottom;
        *(f32 *)(arg1 + 0xC8) = z;
        *(f32 *)(arg1 + 0x40) = right;
        *(f32 *)(arg1 + 0x44) = bottom;
        *(f32 *)(arg1 + 0x48) = z;
        break;
    }
    *(f32 *)(arg1 + 0x18) = inverse;
    *(f32 *)(arg1 + 0x58) = inverse;
    *(f32 *)(arg1 + 0x98) = inverse;
    *(f32 *)(arg1 + 0xD8) = inverse;
    {
        s32 i;
        u8 *vertex;

        for (i = 0; i < 4; i++) {
            vertex = arg1 + (i << 6);
            *(f32 *)(vertex + 0x20) = (f32)(u32)arg2[0];
            *(f32 *)(vertex + 0x24) = (f32)(u32)arg2[1];
            *(f32 *)(vertex + 0x28) = (f32)(u32)arg2[2];
            *(f32 *)(vertex + 0x2C) = (f32)(u32)arg2[3];
        }
    }
    *(s32 *)(arg1 + 0x100) = arg3;
    *(f32 *)(arg1 + 0x104) = inverse;
    *(f32 *)(arg1 + 0x108) = fparg5;
    *(f32 *)(arg1 + 0x10C) = fparg6;
    *(f32 *)(arg1 + 0x110) = fparg7;
    *(f32 *)(arg1 + 0x114) = arg_sp0;
    *(s32 *)(arg1 + 0x118) = arg4;
    entry = func_00461390(arg0, 4, arg1, 4);
    *(void **)(entry + 8) = (void *)func_0014dd80;
    *(u8 **)(entry + 0x10) = arg1;
}
// FUN_0014E2A0
s32 func_0014e2a0(u8 *arg0) {
    extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
    extern s32 func_00455f70(u8 *arg0, s32 *arg1);
    extern void H_Cdvd_Destroy(u8 *arg0);

    extern void func_004b11d0();
    extern void func_004b1150();
    extern u8 D_005DC7D0[];
    s32 sp5C;
    u8 *temp_18;
    s32 temp_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_19;
    u8 *temp_2;
    u8 *temp_5;
    s32 *temp_10;
    s32 *temp_11;

    temp_18 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_18 + 0);
    switch (temp_3) {
    case 0:
        if (*(s32 *)(temp_18 + 0xC) == 0) {
            if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_18 + 4)) != 0) {
                temp_2 = *(u8 **)(temp_18 + 4);
                if (temp_2 != NULL) {
                    *(s32 *)(temp_18 + 0x14) =
                        func_004b1130(*(s32 *)(temp_2 + 0x110));
                    H_Cdvd_Destroy(*(u8 **)(temp_18 + 4));
                    *(u8 **)(temp_18 + 4) = NULL;
                }
                goto block_10;
            }
        } else {
            *(s32 *)(temp_18 + 0x14) =
                func_004b1130(func_00455f70(temp_18 + 0xBC, &sp5C));
block_10:
            *(s32 *)(temp_18 + 0) = *(s32 *)(temp_18 + 0) + 1;
        }
    case 1:
        goto block_31;
    case 2:
        temp_4 = *(s32 *)(temp_18 + 0x10);
        if ((temp_4 == 0) && (*(s32 *)(temp_18 + 0x20) == 0)) {
            *(s32 *)(temp_18 + 0) = 1;
        } else {
            if ((temp_4 == 1) &&
                (*(s32 *)(temp_18 + 0x74) != 1) &&
                (*(s32 *)(temp_18 + 0x98) != 1)) {
                if ((u32)*(u32 *)(temp_18 + 0x18) <
                    (u32)*(u32 *)(temp_18 + 8)) {
                    func_004b1190(*(u8 **)(temp_18 + 0x14));
                    func_004b11d0(
                        (s32)&D_005DC7D0 +
                        (*(u16 *)(temp_18 + 0x1C) * 0x54),
                        *(s32 *)(temp_18 + 0x14));
                    *(u32 *)(temp_18 + 0x18) =
                        *(u32 *)(temp_18 + 0x18) + 1;
                } else {
                    *(s32 *)(temp_18 + 0x10) = 0;
                }
            }
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_5 = temp_18 + (var_19 * 4);
            if ((*(s32 *)(temp_5 + 0x78) != 1) &&
                (*(s32 *)(temp_5 + 0x9C) != 1)) {
                temp_10 = (s32 *)(temp_5 + 0x24);
                temp_4_2 = *(s32 *)(temp_5 + 0x24);
                if (temp_4_2 != 0) {
                    temp_11 = (s32 *)(temp_5 + 0x44);
                    if ((u32)*(u32 *)(temp_5 + 0x44) <
                        (u32)*(u32 *)(temp_18 + 8)) {
                        func_004b1190((u8 *)temp_4_2);
                        func_004b11d0(
                            (s32)&D_005DC7D0 +
                            (*(u16 *)(temp_18 + var_19 * 2 + 0x64) *
                             0x54),
                            *temp_10);
                        *temp_11 = *temp_11 + 1;
                    } else {
                        func_004b1150(temp_4_2);
                        *temp_10 = 0;
                        *(s32 *)(temp_18 + 0x20) =
                            *(s32 *)(temp_18 + 0x20) - 1;
                    }
                }
            }
            var_19 += 1;
loop_test:
            while (var_19 < 8) {
                goto loop_body;
            }
            goto block_31;
        }
        goto block_31;
    case 3:
        return -1;
    default:
block_31:
        return 0;
    }
}
// FUN_0014E540
void func_0014e540(u8 *arg0) {
    s32 i;
    u8 *p;
    s32 temp_4;

    p = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 8; i++) {
        temp_4 = *(s32 *)(p + i * 4 + 0x24);
        if (temp_4 != 0) {
            func_004b1150(temp_4);
        }
    }
    temp_4 = *(s32 *)(p + 0x14);
    if (temp_4 != 0) {
        func_004b1150(temp_4);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0014E5E0
s32 func_0014e5e0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&iGpffff9de0, 0xC2);
    temp_2 = D_008873F4[0](1, 0xFC, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_17 = (s32)func_00451fc0((void *)(arg0), (const void *)(&D_005EFC18), 0xF, 0, 0, func_0014e2a0, func_0014e540, (u8 *)(temp_2));
    if (arg3 == 0) {
        func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
        *(s32 *)(temp_2 + 4) = (s32)func_00454a60(arg1, 0);
    } else {
        *(s32 *)(temp_2 + 4) = arg3;
        *(s32 *)(temp_2 + 0xC) = 1;
    }
    *(s32 *)(temp_2 + 8) = arg2;
    strcpy(temp_2 + 0xBC, (const char *)arg1);
    return temp_17;
}
// FUN_0014E710
s32 func_0014e710(u8 *arg0) {
    if (arg0 == NULL) {
        return 1;
    }
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) >= 1;
}
/* measured probe: optimization level 1 register allocation for func_0014e740. */
#pragma optimization_level 1
// FUN_0014E740
s32 func_0014e740(u8 *arg0, f32 *arg1) {
    s32 temp_20;
    s32 temp_4;
    u8 *temp_19;
    s32 temp_2;
    s32 temp_3;
    s32 var_17;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_17 = -1;
    if (*(s32 *)(temp_16 + 0x10) == 1) {
        var_17 = 0;
        goto loop_test_4;
loop_body_4:
        if (*(s32 *)(temp_16 + (var_17 * 4) + 0x24) == 0) {
            goto loop_done_4;
        }
        var_17 += 1;
loop_test_4:
        if (var_17 < 8) {
            goto loop_body_4;
        }
loop_done_4:
        if (var_17 >= 8) {
            func_0046d730(&iGpffff9de0, 0x100);
        }
        temp_20 = var_17 * 4;
        temp_19 = p4_e740_add(temp_20, temp_16) + 0x24;
        temp_2 = func_004b11b0(*(s32 *)(temp_16 + 0x14));
        *(s32 *)temp_19 = temp_2;
        func_004b1250((void *)temp_2, arg1);
        *(s32 *)(p4_e740_add(temp_20, temp_16) + 0x44) = 0;
        temp_3 = 1;
        *(s16 *)(p4_e740_add(var_17 * 2, temp_16) + 0x64) = temp_3;
        *(s32 *)(temp_16 + 0x20) = *(s32 *)(temp_16 + 0x20) + 1;
    } else {
        func_004b1170(*(s32 *)(temp_16 + 0x14));
        func_004b1250(*(void **)(temp_16 + 0x14), arg1);
        *(s32 *)(temp_16 + 0x18) = 0;
        temp_4 = 1;
        *(s32 *)(temp_16 + 0x10) = temp_4;
        *(s16 *)(temp_16 + 0x1C) = temp_4;
    }
    *(s32 *)temp_16 = 2;
    return var_17;
}
/* measured probe: restore optimization level 2 after func_0014e740. */
#pragma optimization_level 2
// FUN_0014E880
void func_0014e880(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 >= 0) {
        if (*(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x24) != 0) {
            *(s16 *)(p4_00141cf0_add((u32)(arg1 * 2), temp_4) + 0x64) = arg2;
        }
    } else {
        *(s16 *)(temp_4 + 0x1C) = arg2;
    }
}
// FUN_0014E8C0
s32 func_0014e8c0(u8 *arg0, s32 arg1) {
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 >= 0) {
        return *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_3) + 0x44);
    }
    return *(s32 *)(temp_3 + 0x18);
}
// FUN_0014E8F0
void func_0014e8f0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == -1) {
        *(s32 *)(temp_4 + 0x74) = arg2;
        return;
    }
    *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x78) = arg2;
}
// FUN_0014E920
void func_0014e920(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == -1) {
        *(s32 *)(temp_4 + 0x98) = arg2;
        return;
    }
    *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x9C) = arg2;
}
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

// FUN_0014E950
s32 func_0014e950(u8 *task)
{
    SVec3 direction;
    SVec3 position;
    u8 color[8];
    u8 *work;
    s32 state;
    u32 i;

    work = *(u8 **)(task + 0x38);
    state = *(s32 *)work;
    switch (state) {
        case 0:
        {
            u8 *child = *(u8 **)(work + 0xC);
            if (fieldTransitionChildReady(child)) {
                s32 *source = (s32 *)func_003e9700(*(s32 *)(((u8 *)(u32)func_00457120()) + 4));
                s32 *destination = (s32 *)(work + 0x10);
                s32 count = 8;
                do {
                    s32 first = source[0];
                    s32 second = source[1];
                    source += 2;
                    count--;
                    destination[0] = first;
                    destination[1] = second;
                    destination += 2;
                } while (count > 0);
                direction = *(SVec3 *)(work + 0x30);
                RwV3dNormalize(&direction.x, &direction.x);
                fieldTransitionScaleVector(&direction, &direction, 700.0f);
                position = *(SVec3 *)(work + 0x40);
                position.x += direction.x;
                position.y += direction.y;
                position.z += direction.z;
                func_0014e740(*(u8 **)(work + 0xC), &position.x);
                func_0045af60(1, 0xB, 3, 4);
                *(s32 *)(work + 8) = 0;
                ++*(s32 *)work;
            }
            break;
        }
        case 1:
        {
            s32 frame = *(s32 *)(work + 8);
            if (frame < 84) {
                if (frame > 40) {
                    for (i = 0; i < 4; i++) {
                        if (fieldTransitionEntryActive(i)) {
                            u8 *entry = D_007EF9B0 + i * 0x750;
                            u8 *object = *(u8 **)(entry + 0x54);
                            *(u32 *)(object + 0x28) &= ~2U;
                        }
                    }
                    if (*(s32 *)(work + 4) == 1) {
                        s8 *source = (s8 *)iGpffff9dd8;
                        s8 *destination = (s8 *)color;
                        s32 count = 4;
                        do {
                            s8 first = source[0];
                            s8 second = source[1];
                            source += 2;
                            count--;
                            destination[0] = first;
                            destination[1] = second;
                            destination += 2;
                        } while (count > 0);
                        func_00122520(1, 1);
                        H_Fade_SetCustomColor(color[0], color[1], color[2]);
                        ++*(s32 *)work;
                    }
                }
                ++*(s32 *)(work + 8);
            } else {
                *(s32 *)work = state + 1;
            }
            break;
        }
        case 2:
            return -1;
    }
    return 0;
}
#pragma pop
// FUN_0014EC20
void func_0014ec20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EC50
s32 func_0014ec50(u8 *arg0, s32 arg1) {
    extern s32 func_0014e950(u8 *arg0);
    extern s32 func_00454a60(const void *arg0, s32 arg1);
    extern u8 D_005EFC40[];
    u8 **allocator_table;
    u8 *temp_2_2;
    s32 result;
    u8 *temp_2;
    u8 *header;
    func_0044ea90(&iGpffff9de0, 0x2DF);
    allocator_table = (u8 **)D_008873F4;
    temp_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0x50, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    header = D_005EFC28;
    result = (s32)func_00451fc0((void *)(arg0), (const void *)(header), 0xF, 0, 0, func_0014e950, func_0014ec20, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 4) = arg1;
    if (arg1 == 0) {
        func_0044ea90(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)func_00451fc0((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, func_0014e2a0, func_0014e540, (u8 *)(temp_2_2));
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = func_00454a60(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x53;
            strcpy(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    } else if (arg1 == 1) {
        func_0044ea90(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)func_00451fc0((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, func_0014e2a0, func_0014e540, (u8 *)(temp_2_2));
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = func_00454a60(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x32;
            strcpy(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    }
    return result;
}
// FUN_0014EEC0
s32 func_0014eec0(void) {
    return D_007642F0;
}
