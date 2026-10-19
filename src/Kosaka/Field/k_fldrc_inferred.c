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
extern void mdlEffectDestroy(s32 arg0);
extern u8 D_007EF9B0[];
extern s32 kwlnGetCamera(void);
extern u8 D_007E8020[];
extern u8 *func_003e9700(s32 arg0);

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

extern s32 mdlEffectCreateFromResource(s32 arg0);
extern void mdlEffectStart(s32 arg0);
extern s32 mdlEffectClone(s32 arg0);
extern void func_004b1250(void *object, f32 *position);

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

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;








extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern s32 FldRc_FileLoadStep(u8 *arg0);
extern void FldRc_FileLoadDestroy(u8 *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern void strcpy(void *arg0, const char *arg1);
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









#pragma push
#pragma pop









/* measured: opt_rebuildconditionals off is scoped to resrcMngResetRenderSlots. */

/* measured: closes opt_rebuildconditionals for resrcMngResetRenderSlots. */

/* measured: opt_rebuildconditionals off is scoped to resrcMngSetDrawEnabled. */

/* measured: closes loop-invariant constants probe for resrcMngSetDrawEnabled. */
/* measured: closes opt_rebuildconditionals for resrcMngSetDrawEnabled. */

/* measured: opt_rebuildconditionals off is scoped to FldMap_IsCurrentInEitherBand. */

/* measured: closes opt_rebuildconditionals for FldMap_IsCurrentInEitherBand. */

/* measured: opt_rebuildconditionals off is scoped to FldMap_IsInEitherBand. */

/* measured: closes opt_rebuildconditionals for FldMap_IsInEitherBand. */

/* Source unit: src/promoted/code1_0014.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 0014dcd0-0014eec0 */

extern s32 FldEvent_AverageEntryValue(void);
extern u8 *FldEvent_GetGridCellEntry(s32 arg0, s32 arg1);
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
extern void fadeBeginTransition(s32 enabled, s32 mode);
extern void H_Fade_SetCustomColor(s32 red, s32 green, s32 blue);
extern void RwV3dNormalize(f32 *destination, f32 *source);
extern u8 iGpffff9dd8[8];
/* measured probe: optimization_level 1 on c780. */
/* measured: restore optimization_level 2 after FldEvent_AverageEntryValue. */
#pragma push
/* measured: byte-exact (354/354 instructions, 0 differing words).  The three
   occupancy scans are block-scoped so each `clear` flag lives where retail
   keeps it ($v0 reusing the test's 1, $s6 across the list walk's calls, $t2).
   The grid is a u16 row array: `D_007D24B0[y + 1]` folds to the symbol+2
   base retail uses for the final mark.  The mark's bits are `(u16)(1U << x)`
   so they are not CSE'd with the signed occupancy test's `1 << x`.
   opt_loop_invariants hoists 600.0f/1200.0f, x+1/y+1 and the table bases. */
#pragma pop
/* measured probe: opt_loop_invariants on hoists the 600.0f/1200.0f constants. */
/* measured: restore opt_loop_invariants off after FldEvent_GetGridCellEntry. */
// FUN_0014DCD0
void FldRc_SetAxesTargeted(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44) = arg1;
}

// FUN_0014DCE0
void FldRc_SetAxesColor(u8 *arg0, u8 *arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(Rgba8_0014 *)(p + 0x48) = *(Rgba8_0014 *)arg1;
}

// FUN_0014DD10
void FldRc_SetAxesPosition(u8 *arg0, u8 *arg1) {
    f32 sp20[4];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(SVec3 *)(temp_16 + 0x30) = *(SVec3 *)arg1;
    RwEngineGetMatrixTolerances(&sp20[0]);
    RwMatrixOptimize(temp_16, &sp20[0]);
    RwMatrixUpdate(temp_16);
}

/* measured probe: opt_propagation off preserves FldRc_DrawScreenQuad vtable and float stores. */
/* measured: FldRc_DrawScreenQuad MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0014DD80
void FldRc_DrawScreenQuad(u8 *arg0, u8 *arg1) {
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
/* Matched.  The near Z is RwIm2DGetNearScreenZ(), a member of RenderWare's
   ourGlobals reached through the RwGlobals/RwDevice prefix above: read
   twice around the camera call it keeps its address in $s5 without the
   volatile pointer the old floor used.  The colour loop's counter and
   vertex pointer are block-scoped, which is what puts the index in $a1
   instead of $v0, and the four bytes convert as (f32)(u32) so MWCC emits
   its own bltz/srl/or/cvt/add.s sequence.  No pragma. */
// FUN_0014DEF0
void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, u8 *arg2, s32 arg3,
                   f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                   f32 arg_sp0)
{
    extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
    f32 z;
    f32 inverse;
    f32 right;
    f32 bottom;
    u8 *entry;

    z = RwIm2DGetNearScreenZ() - fparg2;
    if (fparg2 == 0.0f) {
        z = RwIm2DGetNearScreenZ() - *(f32 *)(((u8 *)(u32)kwlnGetCamera()) + 0x80);
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
    entry = PrimQueueDrawPrimitive(arg0, 4, arg1, 4);
    *(void **)(entry + 8) = (void *)FldRc_DrawScreenQuad;
    *(u8 **)(entry + 0x10) = arg1;
}

// FUN_0014E2A0
s32 FldRc_FileLoadStep(u8 *arg0) {
    extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
    extern s32 H_Cdvd_LookupRequest(u8 *arg0, s32 *arg1);
    extern void H_Cdvd_Destroy(u8 *arg0);

    extern void func_004b11d0();
    extern void mdlEffectDestroy();
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
                        mdlEffectCreateFromResource(*(s32 *)(temp_2 + 0x110));
                    H_Cdvd_Destroy(*(u8 **)(temp_18 + 4));
                    *(u8 **)(temp_18 + 4) = NULL;
                }
                goto block_10;
            }
        } else {
            *(s32 *)(temp_18 + 0x14) =
                mdlEffectCreateFromResource(H_Cdvd_LookupRequest(temp_18 + 0xBC, &sp5C));
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
                        mdlEffectDestroy(temp_4_2);
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
void FldRc_FileLoadDestroy(u8 *arg0) {
    s32 i;
    u8 *p;
    s32 temp_4;

    p = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 8; i++) {
        temp_4 = *(s32 *)(p + i * 4 + 0x24);
        if (temp_4 != 0) {
            mdlEffectDestroy(temp_4);
        }
    }
    temp_4 = *(s32 *)(p + 0x14);
    if (temp_4 != 0) {
        mdlEffectDestroy(temp_4);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014E5E0
s32 FldRc_CreateFileLoadTask(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_17;
    u8 *temp_2;

    chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
    temp_2 = D_008873F4[0](1, 0xFC, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_17 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(temp_2));
    if (arg3 == 0) {
        func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
        *(s32 *)(temp_2 + 4) = (s32)H_Cdvd_AcquireDirectory(arg1, 0);
    } else {
        *(s32 *)(temp_2 + 4) = arg3;
        *(s32 *)(temp_2 + 0xC) = 1;
    }
    *(s32 *)(temp_2 + 8) = arg2;
    strcpy(temp_2 + 0xBC, (const char *)arg1);
    return temp_17;
}

// FUN_0014E710
s32 FldRc_FileLoadIsReady(u8 *arg0) {
    if (arg0 == NULL) {
        return 1;
    }
    return *(s32 *)(*(u8 **)(arg0 + 0x38)) >= 1;
}

/* measured probe: optimization level 1 register allocation for FldRc_RequestPositionSlot. */
/* measured: FldRc_RequestPositionSlot MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_0014E740
s32 FldRc_RequestPositionSlot(u8 *arg0, f32 *arg1) {
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
            kAssertFail(&iGpffff9de0, 0x100);
        }
        temp_20 = var_17 * 4;
        temp_19 = p4_e740_add(temp_20, temp_16) + 0x24;
        temp_2 = mdlEffectClone(*(s32 *)(temp_16 + 0x14));
        *(s32 *)temp_19 = temp_2;
        func_004b1250((void *)temp_2, arg1);
        *(s32 *)(p4_e740_add(temp_20, temp_16) + 0x44) = 0;
        temp_3 = 1;
        *(s16 *)(p4_e740_add(var_17 * 2, temp_16) + 0x64) = temp_3;
        *(s32 *)(temp_16 + 0x20) = *(s32 *)(temp_16 + 0x20) + 1;
    } else {
        mdlEffectStart(*(s32 *)(temp_16 + 0x14));
        func_004b1250(*(void **)(temp_16 + 0x14), arg1);
        *(s32 *)(temp_16 + 0x18) = 0;
        temp_4 = 1;
        *(s32 *)(temp_16 + 0x10) = temp_4;
        *(s16 *)(temp_16 + 0x1C) = temp_4;
    }
    *(s32 *)temp_16 = 2;
    return var_17;
}

/* measured probe: restore optimization level 2 after FldRc_RequestPositionSlot. */
/* measured: FldRc_TransitionStep, FldRc_CreateTransitionTask MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_0014E880
void FldRc_SetPositionSlotPriority(u8 *arg0, s32 arg1, s16 arg2) {
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
s32 FldRc_GetPositionSlotCount(u8 *arg0, s32 arg1) {
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 >= 0) {
        return *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_3) + 0x44);
    }
    return *(s32 *)(temp_3 + 0x18);
}

// FUN_0014E8F0
void FldRc_SetPositionSlotLock(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == -1) {
        *(s32 *)(temp_4 + 0x74) = arg2;
        return;
    }
    *(s32 *)(p4_00141cf0_add((u32)(arg1 * 4), temp_4) + 0x78) = arg2;
}

// FUN_0014E920
void FldRc_SetPositionSlotVisibility(u8 *arg0, s32 arg1, s32 arg2) {
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
/* measured: FldRc_TransitionStep MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0014E950
s32 FldRc_TransitionStep(u8 *task)
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
                s32 *source = (s32 *)func_003e9700(*(s32 *)(((u8 *)(u32)kwlnGetCamera()) + 4));
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
                FldRc_RequestPositionSlot(*(u8 **)(work + 0xC), &position.x);
                sdkSndStartStream(1, 0xB, 3, 4);
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
                        fadeBeginTransition(1, 1);
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
void FldRc_TransitionDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EC50
s32 FldRc_CreateTransitionTask(u8 *arg0, s32 arg1) {
    extern s32 FldRc_TransitionStep(u8 *arg0);
    extern s32 H_Cdvd_AcquireDirectory(const void *arg0, s32 arg1);
    extern u8 D_005EFC40[];
    u8 **allocator_table;
    u8 *temp_2_2;
    s32 result;
    u8 *temp_2;
    u8 *header;
    chkmemAllocSiteTag(&iGpffff9de0, 0x2DF);
    allocator_table = (u8 **)D_008873F4;
    temp_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0x50, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    header = D_005EFC28;
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(header), 0xF, 0, 0, FldRc_TransitionStep, FldRc_TransitionDestroy, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 4) = arg1;
    if (arg1 == 0) {
        chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)kwlnTaskCreateChild((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(temp_2_2));
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = H_Cdvd_AcquireDirectory(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x53;
            strcpy(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    } else if (arg1 == 1) {
        chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
        temp_2_2 = ((u8 *(*)(s32, s32, s32))allocator_table[0])(1, 0xFC, 0x40000);
        if (temp_2_2 == NULL) {
            arg1 = 0;
        } else {
            arg1 = (s32)kwlnTaskCreateChild((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(temp_2_2));
            func_00440b68(&iGpffff9de8, &iGpffff9de0, 0xD0);
            *(s32 *)(temp_2_2 + 4) = H_Cdvd_AcquireDirectory(&D_005EFC40, 0);
            *(s32 *)(temp_2_2 + 8) = 0x32;
            strcpy(temp_2_2 + 0xBC, (const char *)&D_005EFC40);
        }
        *(s32 *)(temp_2 + 0xC) = arg1;
    }
    return result;
}

// FUN_0014EEC0
s32 FldRc_GetLoadSource(void) {
    return D_007642F0;
}

