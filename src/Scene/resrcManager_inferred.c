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



extern u8 *resrcMngFindResById(u8 *arg0, u16 arg1);
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
extern u8 D_005EF840[];
extern u8 D_005EF858[];
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

extern void func_004b1250(void *object, f32 *position);

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


extern s32 D_007642F0;



extern u8 *PrimAllocQueueNode(void);
extern void func_00460ac0(void *arg0, u8 *arg1);


extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void resrcMngSetDrawEnabled(s32 arg0, s32 arg1);
extern void MT_Scene_ScaleResColors(u32 *resource, const f32 *color);
extern void func_00457140(u8 red, u8 green, u8 blue, u8 alpha);
extern s8 *func_00457160(void);
extern void FldFilterSetPrimary(s32 arg0, s32 arg1);

extern void FldFilterSetSecondary(s32 arg0, s32 arg1);

extern void FldFilterSetTertiary(s32 arg0, s32 arg1);

extern void FldFilterSetIntensity(s32 arg0, s32 arg1);
extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void memset(void *arg0, s32 arg1, s32 arg2);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 00147530-0014a000 */

/* measured: O1 probe for 00146630 register allocation and short tail. */
/* measured: schedule-off probe for 46630 branch delay slots. */
/* measured: closes schedule-off probe for 46630. */
// FUN_00147530
u8 *resrcMngFindResById(u8 *arg0, u16 arg1) {
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
u32 resrcMngGetTotalResInList(u8 *resLists, u8 resType)
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
u8 *resrcMngGetTableEntry(s32 arg0) {
    return D_005EFAA0 + arg0 * 0x10;
}

/* measured probe: opt_propagation off for 00147640 float ordering. */
/* measured: resrcMngRenderCameraFog MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00147640
void resrcMngRenderCameraFog(u8 *arg0, u8 *arg1) {
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
    temp_2 = K_Clump_GetLightA();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = K_Clump_GetLightB();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(K_Clump_GetLightB() + 4) + 0x10;
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
    temp_16 = (s32)K_Clump_GetWorld();
    func_003cbf30(temp_16, K_Clump_GetLightC());
    if (resrcMngGetColorValue() != NULL) {
        temp_16_2 = K_Clump_GetLightA();
        func_003c38b0(temp_16_2, resrcMngGetColorValue());
        temp_16_3 = K_Clump_GetLightB();
        func_003c38b0(temp_16_3, resrcMngGetColorTarget());
        temp_16_4 = K_Clump_GetLightB();
        func_003e9cb0(*(s32 *)(temp_16_4 + 4), resrcMngGetTransform(), 0);
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
// FUN_00147830
void resrcMngRenderCamera(u8 *arg0, u8 *arg1) {
    u8 *temp_16;

    func_003e8110(((u8 *)(u32)func_00457120()));
    temp_16 = K_Clump_GetWorld();
    func_003cbe80(temp_16, K_Clump_GetLightC());
    if (resrcMngGetColorValue() != NULL) {
        func_003c38b0(K_Clump_GetLightA(), arg1);
        func_003c38b0(K_Clump_GetLightB(), arg1 + 0x10);
        func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x20, 0);
    }
    func_003e8120(((u8 *)(u32)func_00457120()));
}

/* measured probe: opt_propagation off for 00147910 float and vtable order. */
// FUN_00147910
void resrcMngRenderCameraFade(u8 *arg0, u8 *arg1) {
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
    temp_2 = K_Clump_GetLightA();
    temp_f3 = *(f32 *)(temp_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2 + 0x24);
    *(f32 *)(arg1 + 0) = temp_f3;
    *(f32 *)(arg1 + 4) = temp_f2;
    *(f32 *)(arg1 + 8) = temp_f1;
    *(f32 *)(arg1 + 0xC) = temp_f0;
    temp_2_2 = K_Clump_GetLightB();
    temp_f3 = *(f32 *)(temp_2_2 + 0x18);
    temp_f2 = *(f32 *)(temp_2_2 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_2 + 0x20);
    temp_f0 = *(f32 *)(temp_2_2 + 0x24);
    *(f32 *)(arg1 + 0x10) = temp_f3;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x18) = temp_f1;
    *(f32 *)(arg1 + 0x1C) = temp_f0;
    var_6 = *(u8 **)(K_Clump_GetLightB() + 4) + 0x10;
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
    temp_2_4 = K_Clump_GetLightC();
    temp_f3 = *(f32 *)(temp_2_4 + 0x18);
    temp_f2 = *(f32 *)(temp_2_4 + 0x1C);
    temp_f1 = *(f32 *)(temp_2_4 + 0x20);
    temp_f0 = *(f32 *)(temp_2_4 + 0x24);
    *(f32 *)(arg1 + 0x60) = temp_f3;
    *(f32 *)(arg1 + 0x64) = temp_f2;
    *(f32 *)(arg1 + 0x68) = temp_f1;
    *(f32 *)(arg1 + 0x6C) = temp_f0;
    var_6_2 = *(u8 **)(K_Clump_GetLightC() + 4) + 0x10;
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
// FUN_00147AE0
void resrcMngRenderCameraPair(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(K_Clump_GetLightA(), arg1);
    func_003c38b0(K_Clump_GetLightC(), arg1 + 0x60);
    func_003c38b0(K_Clump_GetLightB(), arg1 + 0x10);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), arg1 + 0x70, 0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x20, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}

// FUN_00147BB0
void resrcMngRenderAttached(u8 *arg0, u8 *arg1) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = MT_Scene_GetResListHead(4);
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(K_Clump_GetLightA(), temp_16 + 0x140);
    func_003c38b0(K_Clump_GetLightC(), temp_16 + 0x150);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), temp_16 + 0x160, 0);
    temp_3 = *(s32 *)(arg1 + 0x28);
    if (temp_3 & 0x80000000) {
        func_003c38b0(K_Clump_GetLightA(), arg1 + 0x168);
        func_003c38b0(K_Clump_GetLightC(), arg1 + 0x178);
        func_003c38b0(K_Clump_GetLightB(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), arg1 + 0x190, 0);
        func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x1E0, 0);
    } else if (temp_3 & 0x40000000) {
        func_003c38b0(K_Clump_GetLightB(), arg1 + 0x1D0);
        func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x1E0, 0);
    } else {
        func_003c38b0(K_Clump_GetLightB(), temp_16 + 0x1A0);
        func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), temp_16 + 0x1B0, 0);
    }
    func_003e8120(((u8 *)(u32)func_00457120()));
}

// FUN_00147D80
void resrcMngRenderCameraSlots(void) {
    u8 *temp_16;

    temp_16 = MT_Scene_GetResListHead(5);
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(K_Clump_GetLightA(), temp_16 + 0x140);
    func_003c38b0(K_Clump_GetLightC(), temp_16 + 0x150);
    func_003c38b0(K_Clump_GetLightB(), temp_16 + 0x1A0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), temp_16 + 0x160, 0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), temp_16 + 0x1B0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}

// FUN_00147E60
void resrcMngRenderAttachedPair(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(K_Clump_GetLightA(), arg1 + 0x168);
    func_003c38b0(K_Clump_GetLightC(), arg1 + 0x178);
    func_003c38b0(K_Clump_GetLightB(), arg1 + 0x1D0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), arg1 + 0x190, 0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x1E0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}

// FUN_00147F30
void resrcMngRenderAttachedAlt(u8 *arg0, u8 *arg1) {
    func_003e8110(((u8 *)(u32)func_00457120()));
    func_003c38b0(K_Clump_GetLightA(), arg1 + 0x15C);
    func_003c38b0(K_Clump_GetLightC(), arg1 + 0x16C);
    func_003c38b0(K_Clump_GetLightB(), arg1 + 0x1C0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightC() + 4), arg1 + 0x180, 0);
    func_003e9cb0(*(s32 *)(K_Clump_GetLightB() + 4), arg1 + 0x1D0, 0);
    func_003e8120(((u8 *)(u32)func_00457120()));
}

/* measured probe: opt_propagation off preserves 00148000 vector coloring. */
// FUN_00148000
s32 resrcMngCompareDistanceArrA(const void *left, const void *right) {
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

/* measured: closes opt_propagation off for resrcMngCompareDistanceArrA. */
/* measured: opt_propagation off preserves 00148140 vector coloring. */
// FUN_00148140
s32 resrcMngCompareDistanceArrB(const void *left, const void *right) {
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
s32 resrcMngRenderTask(u8 *unusedTask) {
    /* Retail returns zero at 001495E8, 00148318. */
    extern void FldResource_QueueDrawCallbacks(u8 *arg0, u8 *arg1);
    extern void FldResource_QueueDrawCallbacksPrimary(u8 *arg0, u8 *arg1);
    extern void FldResource_QueueDrawCallbacksSecondary(u8 *arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, void *arg1);
    extern s32 func_00462df0(u8 *arg0);
    extern u32 K_Clump_StateFlagIsSet(const u32 *state);
    extern void mdlQueueModelForDraw(void *queue, u8 *model);
    extern void *mdlGetColor(void *model);
    extern s32 mdlComputeIndexedAttachMatrix(void *arg0, s32 arg1, void *arg2);
    extern void func_004b11d0(void *arg0, void *arg1);
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
            FldResource_QueueDrawCallbacks(D_00793EE0, *(u8 **)(l12 + 0x1A0));
            if (flag != 0) {
                FldResource_QueueDrawCallbacksPrimary(D_00793F70, *(u8 **)(l12 + 0x1A0));
                FldResource_QueueDrawCallbacksSecondary(D_00793F70, *(u8 **)(l12 + 0x1A0));
            } else {
                FldResource_QueueDrawCallbacksPrimary(D_00794390, *(u8 **)(l12 + 0x1A0));
                FldResource_QueueDrawCallbacksSecondary(D_00794390, *(u8 **)(l12 + 0x1A0));
            }
        }
        l12 = *(u8 **)(l12 + 0x138);
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFog;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFog;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFog;
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
                mdlQueueModelForDraw(D_007942D0, *(u8 **)(l10 + 0x144));
            } else if (t & 0x01000000) {
                mdlQueueModelForDraw(D_007947E0, *(u8 **)(l10 + 0x144));
            } else if (K_Clump_StateFlagIsSet(*(const u32 **)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    mdlQueueModelForDraw(D_00793F10, *(u8 **)(l10 + 0x144));
                } else {
                    mdlQueueModelForDraw(D_00794300, *(u8 **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794300, ex);
                }
            } else if (func_00462df0(*(u8 **)(*(u8 **)(l10 + 0x144) + 0xE0)) == 1) {
                if (flag != 0) {
                    mdlQueueModelForDraw(D_00793F40, *(u8 **)(l10 + 0x144));
                } else {
                    mdlQueueModelForDraw(D_00794360, *(u8 **)(l10 + 0x144));
                }
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00794360, ex);
                }
            } else {
                mdlQueueModelForDraw(D_00793EE0, *(u8 **)(l10 + 0x144));
                ex = *(u8 **)(l10 + 0x16C);
                if (ex != NULL && (*(s32 *)(l10 + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw(D_00793EE0, ex);
                }
            }
        }
        l10 = *(u8 **)(l10 + 0x138);
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCamera;
    *(u8 **)(tmp + 0x10) = D_007D2400;
    func_00460ac0(D_00793EE0, tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCamera;
    *(u8 **)(tmp + 0x10) = D_007D2350;
    if (flag != 0) {
        func_00460ac0(D_00793F10, tmp);
    } else {
        func_00460ac0(D_00794300, tmp);
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCamera;
    *(u8 **)(tmp + 0x10) = D_007D22A0;
    if (flag != 0) {
        func_00460ac0(D_00793F40, tmp);
    } else {
        func_00460ac0(D_00794360, tmp);
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFade;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFade;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFade;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    memset(arrA, 0, 0x100);
    n1 = 0;
    while (l1 != NULL) {
        if (n1 >= 0x40) {
            kAssertFail(D_005EFB00, 0x264);
        }
        arrA[n1] = l1;
        l1 = *(u8 **)(l1 + 0x138);
        n1 += 1;
    }
    if (*(s32 *)(iGpffff9db0 + 0x14) == 1) {
        qsort(arrA, n1, 4, resrcMngCompareDistanceArrA);
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

                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttached;
                *(u8 **)(tmp + 0x10) = *pp;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                if (FldMap_IsCurrentInEitherBand() == 1 && (*(u16 *)*pp & 0x3FF) >= 100) {
                    mdlQueueModelForDraw(D_007943F0, *(u8 **)(*pp + 0x164));
                } else {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*pp + 0x164));
                }
                if (*(u8 **)(*pp + 0x228) != NULL && (*(s32 *)(*pp + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(*pp + 0x228));
                }
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = *pp;
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
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
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFade;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttached;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                mdlQueueModelForDraw((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), *(u8 **)(obj + 0x164));
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderCameraPair;
                *(u8 **)(tmp + 0x10) = D_007D2090;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x22C) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (l3 != NULL) {
        tmp = PrimAllocQueueNode();
        *(void **)(tmp + 8) = (void *)resrcMngRenderCameraSlots;
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

                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l3 + 0x164));
                if (*(u8 **)(l3 + 0x22C) != NULL && (*(s32 *)(l3 + 0x28) & 0x20000000)) {
                    mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l3 + 0x22C));
                }
                for (j = 0; j < 2; j++) {
                    if (*(s32 *)(l3 + j * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(l3 + 0x164), 2, &pos) == 0) {
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
                    tmp = PrimAllocQueueNode();
                    *(void **)(tmp + 8) = (void *)resrcMngRenderAttachedPair;
                    *(u8 **)(tmp + 0x10) = obj;
                    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                    if (*(s32 *)(obj + 0x28) & 0x80000000) {
                        s32 j;

                        mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(obj + 0x164));
                        if (*(u8 **)(obj + 0x22C) != NULL && (*(s32 *)(obj + 0x28) & 0x20000000)) {
                            mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(obj + 0x22C));
                        }
                        for (j = 0; j < 2; j++) {
                            if (*(s32 *)(obj + j * 4 + 0x140) != 0) {
                                if (mdlComputeIndexedAttachMatrix(*(void **)(obj + 0x164), 2, &pos) == 0) {
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
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttachedAlt;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
                mdlQueueModelForDraw((void *)(D_00793E80 + iGpffff9dd0 * 0x30), *(u8 **)(l2 + 0x158));
            } else {
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttachedAlt;
                *(u8 **)(tmp + 0x10) = l2;
                func_00460ac0(D_007945A0, tmp);
                mdlQueueModelForDraw(D_007945A0, *(u8 **)(l2 + 0x158));
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
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderCameraFade;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttachedAlt;
                *(u8 **)(tmp + 0x10) = obj;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                mdlQueueModelForDraw((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), *(u8 **)(obj + 0x158));
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderCameraPair;
                *(u8 **)(tmp + 0x10) = D_007D1F30;
                func_00460ac0((void *)(D_00793E80 + *(s32 *)(obj + 0x210) * 0x30), tmp);
                obj = *(u8 **)(obj + 0x138);
            }
        }
    }
    if (*(s32 *)(iGpffff9db0 + 0x18) == 1) {
        qsort(arrB, n2, 4, resrcMngCompareDistanceArrB);
    }
    if (n2 != 0) {
        tmp = PrimAllocQueueNode();
        *(void **)(tmp + 8) = (void *)resrcMngRenderCameraSlots;
        *(u8 **)(tmp + 0x10) = NULL;
        func_00460ac0(D_007945D0, tmp);
    }
    {
        for (k = n2 - 1; k >= 0; k--) {
            s32 flags;

            ent = &arrB[k];
            flags = *(s32 *)(*ent + 0x28);
            if ((flags & 0x10000000) && (flags & 2) && !(flags & 0x80000000)) {
                mdlQueueModelForDraw(D_007945D0, *(u8 **)(*ent + 0x164));
                cur = (u8 *)ent;
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = *(u8 **)cur;
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
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
                tmp = PrimAllocQueueNode();
                *(void **)(tmp + 8) = (void *)resrcMngRenderAttachedPair;
                *(u8 **)(tmp + 0x10) = arrB[k];
                func_00460ac0(D_007945D0, tmp);
                mdlQueueModelForDraw(D_007945D0, *(u8 **)(arrB[k] + 0x164));
                for (j = 0; j < 2; j++) {
                    u8 *attachmentOwner = arrB[k];
                    if (*(s32 *)(attachmentOwner + j * 4 + 0x140) != 0) {
                        if (mdlComputeIndexedAttachMatrix(*(void **)(attachmentOwner + 0x164), 2, &pos) == 0) {
                            pos = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(arrB[k] + 0x164)) + 0x30);
                            pos.y += 175.0f;
                        }
                        func_004b1250(*(void **)(arrB[k] + j * 4 + 0x140), (f32 *)&pos);
                    }
                }
            }
        }
    }
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraPair;
    *(u8 **)(tmp + 0x10) = D_007D21F0;
    func_00460ac0((void *)(D_00793E80 + iGpffff9dd0 * 0x30), tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraPair;
    *(u8 **)(tmp + 0x10) = D_007D2140;
    func_00460ac0(D_007945D0, tmp);
    tmp = PrimAllocQueueNode();
    *(void **)(tmp + 8) = (void *)resrcMngRenderCameraPair;
    *(u8 **)(tmp + 0x10) = D_007D1FE0;
    func_00460ac0(D_007945A0, tmp);
    return 0;
}

#pragma pop
/* The incoming parent is forwarded to the task allocator, which attaches
   the new task when it is non-null. The constructor remains 96/96 bytes. */
// FUN_00149620
u8 *resrcMngSpawnRenderTask(u8 *ctx) {
    u8 *o;

    o = kwlnTaskCreateChild((void *)(ctx), (const void *)(D_005EFB10), 0xC7, 0, 0, resrcMngRenderTask, 0, (u8 *)(NULL));
    FldShadow_SpawnCasterTask(o);
    return o;
}

// FUN_00149680
void resrcMngSetRenderSuppressed(s32 arg0) {
    D_007642E4 = arg0;
}

// FUN_00149690
void resrcMngSelectDrawSet(s32 arg0) {
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
u8 *resrcMngGetColorValue(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x140;
}

// FUN_00149CE0
u8 *resrcMngGetColorTarget(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x150;
}

// FUN_00149D20
u8 *resrcMngGetTransform(void) {
    u8 *temp_2;

    temp_2 = MT_Scene_GetResListHead(0xC);
    if (temp_2 == NULL) {
        return NULL;
    }
    return temp_2 + 0x160;
}

// FUN_00149D60
void resrcMngSetEnvPrimary(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetPrimary(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149DB0
void resrcMngSetEnvSecondary(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetSecondary(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E00
void resrcMngSetEnvTertiary(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetTertiary(*(s32 *)(D_00762EA0 + 32), arg0);
}

// FUN_00149E50
void resrcMngSetEnvIntensity(s32 arg0)
{
    MT_Scene_GetResListHead(12);
    FldFilterSetIntensity(*(s32 *)(D_00762EA0 + 32), arg0);
}

/* measured: opt_rebuildconditionals off is scoped to resrcMngResetRenderSlots. */
// FUN_00149EA0
void resrcMngResetRenderSlots(void)
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

/* measured: closes opt_rebuildconditionals for resrcMngResetRenderSlots. */
/* measured: opt_rebuildconditionals off is scoped to resrcMngSetDrawEnabled. */
/* measured: loop-invariant constants probe for resrcMngSetDrawEnabled. */
/* measured: resrcMngSetDrawEnabled MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0014A000
void resrcMngSetDrawEnabled(s32 arg0, s32 arg1)
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

