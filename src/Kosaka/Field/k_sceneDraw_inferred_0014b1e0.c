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
extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;


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





extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void resrcMngSetDrawEnabled(s32 arg0, s32 arg1);



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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 0014b1e0-0014b590 */

/* measured: O1 probe for 00146630 register allocation and short tail. */
/* measured: schedule-off probe for 46630 branch delay slots. */
/* measured: closes schedule-off probe for 46630. */
/* measured probe: opt_propagation off for 00147640 float ordering. */
/* measured probe: restore opt_propagation after 00147640. */
/* measured probe: opt_propagation off for 00147910 float and vtable order. */
/* measured probe: restore opt_propagation after 00147910. */
/* measured probe: opt_propagation off preserves 00148000 vector coloring. */
/* measured: closes opt_propagation off for resrcMngCompareDistanceArrA. */
/* measured: opt_propagation off preserves 00148140 vector coloring. */
/* measured: closes opt_propagation off for resrcMngCompareDistanceArrB. */
/* Recovered render passes preserve callback-time resource reloads and
   complete position-vector copies. The two tail k-loops share
   function-scope `k`/`j` (declared k first) under `opt_lifetimes on`, so
   IRO_SplitLifetimes numbers each loop's counters after the hoisted
   `&arrB[k]` temporaries. The first tail loop walks its attachments through
   `cur = (u8 *)ent`; that copy keeps `ent = &arrB[k]` a declared local, which
   is retail's $s4. See docs/probe_archive/RenderQueue_00148280_worker1_20261005.md. */
#pragma push
#pragma pop
/* measured: opt_rebuildconditionals off is scoped to resrcMngResetRenderSlots. */
/* measured: closes opt_rebuildconditionals for resrcMngResetRenderSlots. */
/* measured: opt_rebuildconditionals off is scoped to resrcMngSetDrawEnabled. */
/* measured: loop-invariant constants probe for resrcMngSetDrawEnabled. */
/* measured: closes loop-invariant constants probe for resrcMngSetDrawEnabled. */
/* measured: closes opt_rebuildconditionals for resrcMngSetDrawEnabled. */
/* measured: opt_rebuildconditionals off is scoped to FldMap_IsCurrentInEitherBand. */
/* measured: closes opt_rebuildconditionals for FldMap_IsCurrentInEitherBand. */
/* measured: opt_rebuildconditionals off is scoped to FldMap_IsInEitherBand. */
/* measured: closes opt_rebuildconditionals for FldMap_IsInEitherBand. */
// FUN_0014B1E0
void SceneDraw_InitResList5(void) {
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
s32 MT_Scene_GetCameraResFirst(void) {
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
s32 MT_Scene_GetCameraResSecond(void) {
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
f32 MT_Scene_GetCameraFov(void) {
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
u16 MT_Scene_FindFreeResId(s32 arg0)
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
f32 KDraw_RoundYawDeg(f32 fparg0) {
    s32 integer;
    f32 result;

    integer = (s32)fparg0;
    result = (f32)integer;
    if (!((fparg0 - result) < 0.5f)) {
        result = (f32)(integer + 1);
    }
    return result;
}

