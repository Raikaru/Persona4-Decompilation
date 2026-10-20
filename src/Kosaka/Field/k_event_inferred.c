#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "sdktask.h"
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
    u8 unk40[8];
    u8 unk48[8];
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
extern s32 datCalcGetLevelById(s32 );
extern u8 D_007EF9B0[];
extern u8 D_007E8020[];
extern void *mdlGetMatrix(void *model);
extern f32 RwV3dLength(f32 *);
extern s32 FldEvent_HasLineOfSight(void *, void *, f32 , f32 );

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern void (*D_00887300[])(u32 , u32 );
extern s32 (*D_00887310[])(s32 , void *, s32 );
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
extern void sdkSpriteDrawSized(u8 *, f32 , f32 , f32 ,
                          u8 , u8 , u8 , u8 , u16 ,
                          u16 , s16 , f32 , s16 );
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



extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, u8 *);
extern void FldEventDrawMarker(u8 *, u8 *);


extern u8 *MT_Scene_GetResListHead(s32 );



extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 *MT_Scene_GetFrameState(void);
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void memset(void *, s32 , s32 );
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
extern s32 datCalcGetLevelById(s32 unitId);


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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0014.c; members 0014c540-0014d4e0 */

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
/* Find the closest actor inside the distance/FOV limits with an unobstructed raised sight line. */
/* Raw fixed-offset access retained: the equivalent typed-field rewrite changed b210 code generation in whole-file verification. */
// FUN_0014C540
u8 *FldEvent_FindNearestVisibleActor(u8 *actor, f32 maxDistance, f32 fieldOfView) {
    f32 distance;
    f32 candidateX;
    f32 candidateY;
    f32 candidateZ;
    RwV3d selfPosition;
    RwV3d candidatePosition;
    f32 best;
    u8 *result;
    s32 i;
    u8 **savedEntry;
    u8 **entry;
    u8 *sourceActor;
    u8 *selfMatrix;
    u8 *candidateMatrix;
    struct C540Stack {
        RwV3d v80;
        RwV3d v8c;
        u8 pad98[8];
        RwV3d hitPoint;
        u8 padAC[4];
        f32 diffB0[3];
    } stack;
    extern s32 K_FldEvent_IsPosWithinFov(u8 *actor, u8 *, f32 maxDistance);
    extern f32 fGpffff82b4;
    extern u8 *D_007E8020_abs[];

    sourceActor = actor;
    result = NULL;
    best = fGpffff82b4;
    i = 0;
    goto loop_test_0014c540;
loop_body_0014c540:
    savedEntry = (u8 **)(D_007E8020 + (i * 4));
    if (*savedEntry != 0) {
        if (K_FldEvent_IsPosWithinFov((u8 *)mdlGetMatrix(*(void **)(sourceActor + 0x50)),
                          (u8 *)mdlGetMatrix(*(void **)(*savedEntry + 0x50)) + 0x30,
                          fieldOfView) != 0) {
            entry = D_007E8020_abs + (u32)i;
            candidateX = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x30);
            stack.diffB0[0] = candidateX -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(sourceActor + 0x50)) + 0x30);
            candidateY = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x34);
            stack.diffB0[1] = candidateY -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(sourceActor + 0x50)) + 0x34);
            candidateZ = *(f32 *)((u8 *)mdlGetMatrix(*(void **)(*entry + 0x50)) + 0x38);
            stack.diffB0[2] = candidateZ -
                              *(f32 *)((u8 *)mdlGetMatrix(*(void **)(sourceActor + 0x50)) + 0x38);
            selfMatrix = (u8 *)mdlGetMatrix(*(void **)(sourceActor + 0x50));
            selfPosition = *(RwV3d *)(selfMatrix + 0x30);
            stack.v80 = selfPosition;
            candidateMatrix = (u8 *)mdlGetMatrix(*(void **)(*entry + 0x50));
            candidatePosition = *(RwV3d *)(candidateMatrix + 0x30);
            stack.v8c = candidatePosition;
            stack.v80.y += 100.0f;
            stack.v8c.y += 100.0f;
            if (FldFrame_RaycastSelectedWorld(&stack.v80, &stack.hitPoint) == 0) {
                distance = RwV3dLength(stack.diffB0);
                if ((distance < maxDistance) && (distance < best)) {
                    result = *savedEntry;
                    best = distance;
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
/* The actor level at +0x1C0 is outside the recovered FldEventActor field set; its full record meaning remains unresolved. */
// FUN_0014C780
s32 FldEvent_AverageEntryValue(void) {
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
    if (((s32)((FldEventActor *)entry)->unit != 0) &&
        ((s32)((FldEventActor *)entry)->active != 0)) {
        hit = 1;
    }
    valid = hit != 0;
    if (valid == (hit = 1)) {
        if (index == 0) {
            sum += datCalcGetLevelById(hit) & 0xFF;
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

/* measured: restore optimization_level 2 after FldEvent_AverageEntryValue. */
/* Return the first region actor that passes the sight-line query. */
// FUN_0014C850
s32 *FldEvent_FindFirstRegionActor(u8 *actor, f32 distance, f32 fieldOfView) {
    u8 *candidate;
    u8 *entrySlot;
    s32 entryIndex;
    u8 *tableEntry;

    entryIndex = 0;
    goto loop_test_0014c850;
loop_body_0014c850:
    if (*(s32 *)candidate != 0) {
        if (FldEvent_HasLineOfSight((u8 *)mdlGetMatrix((void *)((FldEventActor *)actor)->model),
                          candidate + 0x150, fieldOfView, distance) != 0) {
            return *(s32 **)entrySlot;
        }
    }
    entryIndex += 1;
loop_test_0014c850:
    tableEntry = D_007E8020 + (entryIndex * 4);
    entrySlot = tableEntry + 0x20;
    candidate = *(u8 **)entrySlot;
    if (candidate != NULL) {
        goto loop_body_0014c850;
    }
    return NULL;
}

/* Reset the occupancy mask and resume coordinates for the next free-cell search. */
// FUN_0014C920
void FldEvent_BeginGridScan(void) {
    iGpffffb1f8 = 0;
    iGpffffb1fc = 0;
    memset(&D_007D24B0, 0, 0x30);
}

#pragma push
/* measured: byte-exact (354/354 instructions, 0 differing words).  The three
   occupancy scans are block-scoped so each `clear` flag lives where retail
   keeps it ($v0 reusing the test's 1, $s6 across the list walk's calls, $t2).
   The grid is a u16 row array: `D_007D24B0[y + 1]` folds to the symbol+2
   base retail uses for the final mark.  The mark's bits are `(u16)(1U << x)`
   so they are not CSE'd with the signed occupancy test's `1 << x`.
   opt_loop_invariants hoists 600.0f/1200.0f, x+1/y+1 and the table bases. */
/* measured: FldEvent_NextGridCell MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Mixed actor/resource cursors retain partial layouts: +0x150 placement and +0x164 model fields are not part of one shared actor type. */
// FUN_0014C960
s32 FldEvent_NextGridCell(s32 *columnOut, s32 *rowOut)
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
            if (*(MT_Scene_GetFrameState() + rowOffset + cellOffset + 0x54) != 1) {
                continue;
            }
            if (*(MT_Scene_GetFrameState() + rowOffset + cellOffset + 0x58) != 9 &&
                *(MT_Scene_GetFrameState() + rowOffset + cellOffset + 0x58) != 11 &&
                *(MT_Scene_GetFrameState() + rowOffset + cellOffset + 0x58) != 13) {
                continue;
            }
            if ((*(MT_Scene_GetFrameState() + rowOffset + cellOffset + 0x55) & 0xF0) != 0x20) {
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
            *columnOut = x;
            *rowOut = y;
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
/* measured: FldEvent_GetGridCellEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Find a resource whose rounded grid position overlaps the requested two-by-two cell. */
/* The type-15 resource placement/list record has no recovered complete layout; +0x140/+0x148 are its X/Z coordinates. */
// FUN_0014CEF0
u8 *FldEvent_GetGridCellEntry(s32 column, s32 row) {
    f32 normalizedX;
    f32 normalizedZ;
    s32 cellX;
    s32 cellZ;
    u8 *entry;

    entry = MT_Scene_GetResListHead(0xF);
    goto loop_test_0014cef0;
loop_body_0014cef0:
    normalizedX = (600.0f + *(f32 *)(entry + 0x140)) / 1200.0f;
    normalizedZ = (600.0f + *(f32 *)(entry + 0x148)) / 1200.0f;
    cellX = (s32)normalizedX;
    cellZ = (s32)normalizedZ;
    if (((cellX == column) && (cellZ == row)) ||
        ((cellX == (column + 1)) && (cellZ == row)) ||
        ((cellX == column) && (cellZ == (row + 1))) ||
        ((cellX == (column + 1)) && (cellZ == (row + 1)))) {
        return entry;
    }
    entry = *(u8 **)(entry + 0x138);
loop_test_0014cef0:
    if (entry != NULL) {
        goto loop_body_0014cef0;
    }
    return NULL;
}

/* measured: restore opt_loop_invariants off after FldEvent_GetGridCellEntry. */
/* Resolve the containing cell and test whether a placed model overlaps its two-by-two footprint. */
/* The neighbor probes deliberately address cells before the current cursor; resource placement records still have only partial layouts. */
// FUN_0014CFD0
s32 FldEvent_IsCellOccupied(u8 *position)
{
    s32 columnOffset;
    s32 resourceId;
    u16 cellResourceId;
    s32 cellX;
    s32 cellZ;
    s32 rowOffset;
    s32 adjustedColumnOffset;
    s32 objectX;
    s32 objectZ;
    u8 *entry;
    extern u8 *MT_Scene_GetFrameState(void);
    {
        f32 centeredX;

        centeredX = 600.0f;
        centeredX += *(f32 *)(position + 0);
        cellX = (s32)(centeredX / 1200.0f);
    }
    cellZ = (s32)((600.0f + *(f32 *)(position + 8)) / 1200.0f);
    rowOffset = cellZ << 8;
    columnOffset = cellX << 4;
    cellResourceId = *(u16 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x56);
    if ((*(u8 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x58) != 9) &&
        (*(u8 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x58) != 0xB) &&
        (*(u8 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x58) != 0xD)) {
        return 0;
    }
    if ((*(u8 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x55) & 0x20) == 0) {
        return 0;
    }
    resourceId = cellResourceId;
    if ((resourceId == *(u16 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x46)) &&
        ((*(u8 *)(MT_Scene_GetFrameState() + rowOffset + columnOffset + 0x45) & 0x20) != 0)) {
        cellX -= 1;
    }
    adjustedColumnOffset = cellX * 0x10;
    if ((resourceId == *(u16 *)(MT_Scene_GetFrameState() + rowOffset + adjustedColumnOffset - 0xAA)) &&
        ((*(u8 *)(MT_Scene_GetFrameState() + rowOffset + adjustedColumnOffset - 0xAB) & 0x20) != 0)) {
        cellZ -= 1;
    }
    entry = MT_Scene_GetResListHead(3);
    goto loop_test_0014cfd0;
loop_body_0014cfd0:
    objectX = (s32)((600.0f +
                       *(f32 *)((u8 *)mdlGetMatrix(*(void **)(entry + 0x164)) + 0x30)) /
                      1200.0f);
    objectZ = (s32)((600.0f +
                    *(f32 *)((u8 *)mdlGetMatrix(*(void **)(entry + 0x164)) + 0x38)) /
                   1200.0f);
    if (((objectX == cellX) && (objectZ == cellZ)) ||
        ((objectX == (cellX + 1)) && (objectZ == cellZ)) ||
        ((objectX == cellX) && (objectZ == (cellZ + 1))) ||
        ((objectX == (cellX + 1)) && (objectZ == (cellZ + 1)))) {
        return 1;
    }
    entry = *(u8 **)(entry + 0x138);
loop_test_0014cfd0:
    if (entry != NULL) {
        goto loop_body_0014cfd0;
    }
    return 0;
}

/* Draw the sampled curve segments and color-coded control points for a queued marker. */
/* The marker record has sampled-count/color/curve fields at +4/+8/+0xC; its allocation and remaining record layout are unresolved. */
// FUN_0014D290
void FldEventDrawMarker(u8 *queueNode, u8 *curve)
{
    extern void func_003bb5b0(u8 *queueNode, s32 curve, void *, s32 , f32 );
    extern s32 func_003bb330(u8 *queueNode);
    extern void func_003bb3a0(u8 *queueNode, s32 curve, void *);
    extern void primLine3D(void *queueNode, void *curve, void *, s32 );
    extern void primSphereLine3D(u8 *center, f32 radius, u8 *color, s32 preserveState);
    extern f32 D_005EFBB8[];
    extern u8 D_005EFBBC[];
    extern u8 D_005EFBBD[];
    extern u8 D_005EFBBE[];
    extern u8 D_005EFBBF[];
    extern u8 D_005EFBC0[];
    extern u8 D_005EFBC1[];
    extern u8 D_005EFBC2[];
    extern u8 D_005EFBC3[];
    f32 segmentStart[3];
    f32 segmentEnd[3];
    P4Bytes0014 pointColor;
    s32 segmentIndex;
    s32 pointIndex;
    s32 segmentCount;
    f32 segmentCountFloat;
    f32 inverseSegmentCount;

    segmentIndex = 0;
    while (segmentIndex < *(s32 *)(curve + 4)) {
        segmentCount = *(s32 *)(curve + 4);
        func_003bb5b0(*(u8 **)(curve + 0xC), 0xA, segmentStart, 0,
                      (1.0f / (f32)segmentCount) * (f32)segmentIndex);
        segmentCountFloat = (f32)*(s32 *)(curve + 4);
        inverseSegmentCount = p4_0014_recip(segmentCountFloat);
        func_003bb5b0(*(u8 **)(curve + 0xC), 0xA, segmentEnd, 0,
                      inverseSegmentCount * (f32)(segmentIndex + 1));
        primLine3D(segmentStart, segmentEnd, curve + 8, 1);
        segmentIndex += 1;
    }
    pointIndex = 0;
    while (pointIndex < func_003bb330(*(u8 **)(curve + 0xC))) {
        if (pointIndex == 1) {
            *(f32 *)&pointColor = D_005EFBB8[0];
        } else if (pointIndex == (func_003bb330(*(u8 **)(curve + 0xC))) - 2) {
            pointColor = *(P4Bytes0014 *)D_005EFBBC;
        } else {
            pointColor = *(P4Bytes0014 *)D_005EFBC0;
        }
        func_003bb3a0(*(u8 **)(curve + 0xC), pointIndex, segmentStart);
        primSphereLine3D((u8 *)segmentStart, 5.0f, (u8 *)&pointColor, 1);
        pointIndex += 1;
    }
}

/* Queue a marker callback only while its work record is enabled. */
/* Queue-node callback/user-data fields are +8/+0x10; the marker owner's +0x110 queue layout is not yet recovered. */
// FUN_0014D470
s32 FldEventQueueDraw(u8 *task)
{
    u8 *work;
    u8 *obj;

    work = ((SdkTask *)task)->work;
    if (*(s32 *)work == 0) {
        return 0;
    }
    obj = PrimAllocQueueNode();
    *(void **)(obj + 8) = FldEventDrawMarker;
    *(void **)(obj + 0x10) = work;
    PrimAppendNode(*(void **)(work + 0x110), obj);
    return 0;
}

/* Release the task-owned drawing work. */
// FUN_0014D4E0
void KDraw_GroupTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

