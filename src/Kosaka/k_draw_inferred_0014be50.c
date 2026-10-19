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

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 0014be50-0014be50 */

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
/* 416/416 bytes; eight resolved relocations, no tail or overrun.
 * D_005EFB98 is one 12-byte (0,1,0) vector, not separate XY/Z objects.
 * Its aggregate copy preserves the grouped retail load/store schedule.
 * The predicate and subsequent height checks share the live triangle. */
/* Test both triangles of each surface within a 100-unit vertical band; return the first hit or FFFF. */
// FUN_0014BE50
u16 FldFrame_PickSurfaceAtPoint(u8 *point, u8 **selectedSurface) {
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
    if (FldMap_IsCurrentInBandA() == 1) {
        return 0xFFFFU;
    }
    while (surface != NULL) {
        normal = D_005EFB98;
        triangle[0] = (f32 *)(surface + 0x15C);
        triangle[1] = (f32 *)(surface + 0x168);
        triangle[2] = (f32 *)(surface + 0x174);
        if ((K_FldFrame_IsPointInTriangle((f32 *)point, triangle, (f32 *)&normal) == 1) &&
            (surfaceY = triangle[0][1],
             pointY = ((RwV3d *)point)->y,
             (pointY < (100.0f + surfaceY))) &&
            !(pointY <= (surfaceY - 100.0f))) {
            selectedId = ((ResrcRecord *)surface)->resTypeId;
            *selectedSurface = surface;
            goto done;
        }
        triangle[0] = (f32 *)(surface + 0x168);
        triangle[1] = (f32 *)(surface + 0x174);
        triangle[2] = (f32 *)(surface + 0x180);
        if ((K_FldFrame_IsPointInTriangle((f32 *)point, triangle, (f32 *)&normal) == 1) &&
            (secondSurfaceY = triangle[0][1],
             secondPointY = ((RwV3d *)point)->y,
             (secondPointY < (100.0f + secondSurfaceY))) &&
            !(secondPointY <= (secondSurfaceY - 100.0f))) {
            selectedId = ((ResrcRecord *)surface)->resTypeId;
            *selectedSurface = surface;
            goto done;
        }
        surface = (u8 *)((ResrcRecord *)surface)->next;
    }
done:
    return selectedId;
}

