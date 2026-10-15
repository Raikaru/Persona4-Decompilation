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
extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
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








#pragma optimization_level 1
#pragma schedule off
#pragma schedule on
#pragma optimization_level 2

#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma pop









/* measured: opt_rebuildconditionals off is scoped to func_00149ea0. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for func_00149ea0. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a000. */
#pragma opt_rebuildconditionals off

#pragma opt_loop_invariants on
/* measured: closes loop-invariant constants probe for func_0014a000. */
#pragma opt_loop_invariants off
/* measured: closes opt_rebuildconditionals for func_0014a000. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a160. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for func_0014a160. */
#pragma opt_rebuildconditionals on

/* measured: opt_rebuildconditionals off is scoped to func_0014a190. */
#pragma opt_rebuildconditionals off

/* measured: closes opt_rebuildconditionals for func_0014a190. */
#pragma opt_rebuildconditionals on




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
