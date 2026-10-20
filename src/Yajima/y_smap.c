#include "byte_address_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit y_smap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "member_access.h"
#include "fcl_draw_types.h"
#include "g_data_internal.h"
#include "h_cdvd.h"
#include "kwln_task_internal.h"
#include "primitive_queue_internal.h"
#include "sdk_ot_node.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "Kosaka/k_fldFilter_internal.h"
#include "rw_camera_internal.h"
#include "scene_resource_internal.h"
extern void (*D_00887304[])(s32, void *);

extern void (*D_00887300[])(s32 state, s32 value);

extern void (*jtbl_008873EC[])(void *);

extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 D_00764640;   /* gp-relative, -0x4AB0 */
extern s32 D_00764644;   /* gp-relative, -0x4AAC */
extern s32 D_00764648;   /* gp-relative, -0x4AA8 */
extern s32 D_0076464C;   /* gp-relative, -0x4AA4 */
extern s32 D_00764650;   /* gp-relative, -0x4AA0 */
extern s16 *D_00764658;  /* gp-relative, -0x4A98 */
extern u8 D_00763928;    /* gp-relative, -0x57C8 */

extern u8 D_0063EF60[];
extern u8 D_0063EF70[];
extern u8 D_0063EF90[];
extern char D_0063EFB0[];
extern u8 D_0063EFC8[];
extern u8 D_00794C90[];
extern char D_0063F0F0[];

extern u8 *kwlnGetCamera(void);
extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
extern void memset(void *dst, s32 value, u32 size);
extern char D_0063EFD8[];
extern void RpSkyRenderStateSet(s32 a, s32 b);
extern s32 sprintf(void *dst, const char *fmt, s32 value);
extern u8 *func_003ef6d0(void);
extern s32 *func_003ef650(u8 *a, void *b);
extern char D_0063EFF0[];
extern char D_0063F010[];
extern char D_0063F030[];
extern char D_0063F050[];
extern char D_0063F070[];
extern char D_0063F090[];
extern char D_0063F0B0[];
extern char D_0063F0D0[];
extern f32 D_008872F8[];
extern u8 D_00794D50[];
extern void smapDrawPanel(s32, u8 *);
extern void smapSetRenderStates(void);
extern void chkmemAllocSiteTag(void *file, s32 line);


extern void PrimAppendNode(void *list, void *node);
extern void func_00440b68();
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern s32 hMaestroDecodeIsReady(s32 state);
extern s32 sdkSpriteRequestLoad(const u8 *name);
extern void sdkSpriteFreeNode(void *node);
extern void kAssertFail(void *file, s32 line);
extern s32 filerEnqueueRequest(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern s32 filerTakeCompletedRequest(s32, s32 *, s32);
extern s32 smapLoadStep(u8 *task);
extern s32 smapUpdateOverlay(u8 *task);
extern void smapDestroyOverlay(u8 *task);
extern void smapResetVisibility(u8 *task);
extern void FldFrameTask_GetPosition(u8 *destination, u8 *task);
extern s32 FldFrameTask_GetTileX(u8 *task);
extern s32 FldFrameTask_GetTileZ(u8 *task);

/* Field-object slots advance by 0x168; k_fldUnit stores their placement position at +0x150. */
typedef struct SMapTarget {
    s32 active;
    u8 pad04[0x14C];
    RwV3d position;
    u8 pad15C[0xC];
} SMapTarget;

typedef char SMapTargetSize[sizeof(SMapTarget) == 0x168 ? 1 : -1];
typedef RwV3d YVec3f;
typedef FclVec2 YVec2f;
typedef struct YRGBA { u8 a, b, c, d; } YRGBA;
/* Two vec2 values arrive as packed 64-bit copies, then only their Y coordinates change. */
typedef struct SMapPanelPositions {
    union { s64 bits; YVec2f position; } points[2];
} SMapPanelPositions;
/* The loader allocates 0x0C bytes; smapCreateSymbols allocates the separate
 * 0x768-byte map work below. Keep the two state machines distinct. */
typedef struct SMapLoadWork {
    union { struct HCdvd *pointer; s32 handle; } directory;
    s8 phase;
    u8 pad05[3];
    s32 file;
} SMapLoadWork;

typedef struct SMapItem {
    u8 pad00[8];
    f32 x, y;
    u8 alphaSubtract;
    u8 pad11[0xF];
    u16 scaleX, scaleY; /* SDK sprite sample: unsigned Q12; zero means unity. */
} SMapItem;

typedef struct SMapWork {
    void *self;
    s8 phase;
    u8 pad05[3];
    YVec3f origin;
    u8 pad14[0xC];
    u8 cellSize;
    u8 pad21[3];
    SMapItem *corners[4];
    union {
        struct {
            SMapItem *leftStrip[6];
            SMapItem *middleStrip[6];
            SMapItem *rightStrip[6];
        };
        SMapItem *strips[3][6];
    };
    SMapItem *ends[2];
    u8 drawNode[0x30];
    s32 renderState;
    s8 mode;
    u8 padB9[3];
    u8 *frames[4];
    u8 *playerMarker;
    u8 *pointMarkers[2];
    u8 *actorMarkers[15];
    u8 *targetMarkers[8];
    u8 pad134[0x14];
    u8 *cells[24][16];
    u8 *labels[2];
    u8 pad750[0x14];
    s16 transitionFrame, labelFrame;
} SMapWork;

/* smapCreateOverlay owns four 0x40-byte vertices after the rectangle header. */
typedef struct SMapRectangle {
    void *self;
    YVec2f position;
    f32 width, height;
    YRGBA color;
    f32 depth, reciprocalDepth;
    FldFilterVertex vertices[4];
} SMapRectangle;

typedef char SMapWorkSize[(sizeof(SMapWork) == 0x768) ? 1 : -1];
typedef char SMapRectangleSize[(sizeof(SMapRectangle) == 0x120) ? 1 : -1];

/* smapDrawCell callees */
extern s32 fclPackRgba(u8, u8, u8, u8);
extern void fclAnchorOffset(f32 *, s64, f32, f32, f32, f32);
extern u8 *MT_Scene_GetFrameState(void);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void smapDrawQuad(u8 *task, YVec2f position, f32 width, f32 height, f32 depth, u8 origin, f32 scale, s32 color, s8 orientation, s32 layer);
extern u8 D_00794DB0[];
extern u8 D_00794CF0[];
extern u8 D_0076465C;   /* gp-relative, -0x4A94 */
extern u8 D_00764660;   /* gp-relative, -0x4A90 */

/* smapDrawPanel callees */
extern f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
extern void sdkSpriteDraw(u8 *, s32);
extern void mapSymbolMarkerSetVariant(u8 *, u8);
extern u8 *fclGetWorkPointer(u8 *);
extern s64 iGpffffa840;  /* gp-relative, -0x57C0 */
extern s64 iGpffffa848;  /* gp-relative, -0x57B8 */
extern f32 iGpffff84f8;
extern f32 iGpffff84f4;  /* gp-relative, -0x7B0C */
/* Map update and symbol-task providers. */
extern u8 *D_007EFA04[];
extern u8 D_007E8C00[];
extern u8 D_00794C30[];
extern u8 D_00794E10[];
extern u8 *PrimAllocQueueNode(void);
extern void smapUpdateItems(u8 *);
extern s32 fclAddClamped(s32, s32, s32, s32, s8);
extern s32 fclSpriteHasDisplayFlags(u8 *);
extern void fclSpriteSetRecordFlag(u8 *, u32, s8);
extern s32 mapSymbolEntityCreate(s32, s32);
extern void smapRevealCell(u8, u8);
extern void fclVec3Subtract(u8 *, u8 *, u8 *);
extern s32 kwlnTaskIsLinked(void *);
extern void smapSetPosition(u8 *, YVec2f);
extern void smapSetVisible(u8 *, s8);
extern void smapClearSelection(u8 *);
extern int smapWorldToColumn(YVec3f);
extern int smapWorldToRow(YVec3f);
/* smapRefreshCells callees */
extern u8 D_007E80A0[];
extern s32 D_00764654;
extern void mapSymbolMarkerSetHighlight(u8 *);
extern void mapSymbolTargetSetState(u8 *, s8);
extern void fclFadeRectSetControl(u8 *, s8);
extern void mapSymbolPointSetState(u8 *, s8);
extern void fclSpriteStartPositionTask(u8 *, YVec2f, YVec2f, u32, u32, s16);
extern void fclSpriteStartAlphaTask(u8 *, u8, u8, u8, s32, s16);
extern void fclSpriteActivateTask(u8 *, YVec2f, u32, f32);
extern f32 sdkSpriteScaledHeight(u8 *);
extern void smapSetActive(u8 *, s8);
extern void smapSetCellMode(u8 *, s8);






/* Request the minimap sprite banks and directory, then wait for the map resource file to finish loading. */
// FUN_002AC400
s32 smapLoadStep(u8 *task) {
    u8 *work = ((KwlnTask *)task)->work;
    SMapLoadWork *load = (SMapLoadWork *)work;
    s32 loaded;

    switch ((s8)((SMapLoadWork *)work)->phase) {
    case 0:
        D_00764640 = sdkSpriteRequestLoad(D_0063EF70);
        if (D_00764640 == 0) {
            kAssertFail(D_0063EF60, 0x93);
        }
        D_00764644 = sdkSpriteRequestLoad(D_0063EF90);
        if (D_00764644 == 0) {
            kAssertFail(D_0063EF60, 0x95);
        }
        load->phase += 1;
        break;
    case 1:
        if (hMaestroDecodeIsReady(D_00764640) != 0 && hMaestroDecodeIsReady(D_00764644) != 0) {
            load->phase += 1;
        }
        break;
    case 2:
        func_00440b68(&D_00763928, D_0063EF60, 0xA0);
        ((SMapLoadWork *)work)->directory.handle = (s32)H_Cdvd_AcquireDirectory((u8 *)D_0063EFB0, 0);
        load->phase += 1;
        break;
    case 3:
        if (H_Cdvd_IsFileLoaded(((SMapLoadWork *)work)->directory.pointer) != 0) {
            ((SMapLoadWork *)work)->file = filerEnqueueRequest(0, D_0063EFB0, 0, 0, 0, 0, 0, 0, 0, 0);
            load->phase += 1;
        }
        break;
    case 4:
        D_00764648 = filerTakeCompletedRequest(((SMapLoadWork *)work)->file, &loaded, 0);
        if (loaded != 0) {
            load->file = 0;
            H_Cdvd_Destroy(((SMapLoadWork *)work)->directory.pointer);
            return -1;
        }
        break;
    }
    return 0;
}

// Intent: clears the smap visibility mask. Note: smapCreate also passes this function as the task's second callback (the destroy slot), so it runs at teardown and allocates a fresh mask. The retail behaviour is kept; the name follows the body.
// FUN_002AC600
void smapResetVisibility(u8 *task) {
    s16 rowIndex;

    chkmemAllocSiteTag(D_0063EF60, 0x44);
    D_00764658 = (s16 *)D_008873F4[0](1, 0x30, 0x40000);
    rowIndex = 0;
    while (rowIndex < 0x18) {
        D_00764658[rowIndex] = 0;
        rowIndex++;
    }
    jtbl_008873EC[0](((KwlnTask *)task)->work);
    D_00764650 = 0;
}

/* Allocate the minimap resource-loader work and register its task. */
// FUN_002AC6B0
void smapCreate(void) {
    u8 *work;

    chkmemAllocSiteTag(D_0063EF60, 0xD5);
    work = D_008873F4[0](1, 0xC, 0x40000);
    D_00764650 = (s32)(s32)kwlnTaskCreate((const void *)(D_0063EFC8), 0xF, 0, 0, smapLoadStep, smapResetVisibility, (u8 *)(work));
    ((SMapLoadWork *)work)->phase = 0;
}

// FUN_002AC740
s32 smapGetSpriteHandle(void) {
    return D_00764644;
}

/* Reveal the current minimap cell, connected walls, or the matching room footprint.
 * measured: fnalign 327 -> 315 -> 313 edits with typed cell/scan views and offset-first row addresses.
 * measured: fnalign 313 -> 311 edits with an offset-first reveal-row pointer helper.
 * measured: fnalign 311 -> 310 -> 309 edits with per-search signed step locals.
 * measured: fnalign 309 -> 303 edits; the kind-9/10 reveal bit remasks the byte coordinate, as retail.
 * measured: fnalign 303 -> 294 edits; per-phase coordinate masks recover additional retail rematerializations.
 * opt_loop_invariants on retains the retail loop hoists; coordinate CSE and spill allocation remain.
 * fnalign 294 -> 291: two more coordinate sites remask the u8 parameter (retail andi at each use).
 * fnalign 291 -> 290: the search calls read the parameters directly, so b210 hoists the x snapshot
 * (frame 0x160; retail 0x190 also spills the hoisted y and the row result).
 * measured (d7d2f766, reverted for fnalign): per-phase u16/u32/int coordinate conversions recover
 * more retail remasks and frame 0x190 (structural diff 50 -> 32), but fnalign 397; the spill set differed.
 * A native capture now shows that post-colour CSE can replace a fresh row mask with the entry row.
 * Thus the move into retail stack + 0x180 does not, by itself, establish a separate source-level copy.
 * 2026-10-13: the shared masks are frontend CSE shadows (compiler locals r170/r171 holding (s32)arg0/arg1
 * at codegen entry). opt_common_subs off reproduces retail's entry exactly (raw a0/a1 in s4/s3, remask
 * at each use) but also drops the backend's per-call constant sharing (move t0,a2) that retail keeps
 * (465). Micro tests: the shadow survives every cast/mask spelling, s32 parameters, local u8 copies,
 * parameter reassignment on another path and 1200-block functions; no other opt_ pragma moves 290.
 * The allocator's remat predicate (0x0049bb20) clones only constants/LA, so retail's per-use andi are
 * separate source conversions the frontend CSE (candidate test 0x004d06a0) never merged.
 * Dual micro (build/micro_src/pp_*.c): no single opt_ pragma removes the mask shadow while keeping
 * the backend's call-constant sharing; stores, calls and every mask/cast/parameter-type spelling
 * leave the shadow in place (mk_*.c). Only asm store statements kill frontend-CSE availability.
 * measured: fnalign 290 -> 217, frame 0x190; shared room phase and reused working coordinates.
 * measured: fnalign 217 -> 212; keep the rectangle's halfword row snapshot distinct from the final call.
 * measured: fnalign 212 -> 208; the rectangle's visibility-row byte offset is a word, not a halfword.
 * measured: fnalign 208 -> 198; distinct original-row stride restores the rectangle row (frame 0x1A0).
 * measured: fnalign 198 -> 154, frame 0x190; give the rectangle its own halfword column and column limit.
 * measured: fnalign 154 -> 146; form vertical footprint addresses directly from the signed-byte anchor.
 * measured: fnalign 146 -> 142; likewise form the horizontal cell address and reveal bit from the anchor.
 * measured: fnalign 142 -> 115; kinds 13/14 use a single-case early-return guard, not a switch.
 * measured: fnalign 115 -> 112; reveal the current cell before preparing the cached neighbor-row offset.
 * measured: fnalign 112 -> 110; the three-cell reveal copies an unsigned halfword row, not a row offset.
 * measured: fnalign 110 -> 106; reuse the offset-first pointer helper for the two following reveal rows.
 * measured: fnalign 106 -> 96; separate room preparation from reveal and retain caller-owned search snapshots.
 * measured: fnalign 96 -> 89; prepare a word-sized vertical reveal mask before the kind guard.
 * measured: fnalign 89 -> 81; the rectangle query uses a signed halfword column, distinct from its first snapshot.
 * measured: fnalign 81 -> 79; prepare the horizontal map/visibility offsets at the phase entrance.
 * measured: fnalign 79 -> 73; each square-scan row likewise prepares its map and visibility byte offsets.
 * measured: fnalign 73 -> 45; preserve the later scans' signed column snapshots and model-derived coordinate/counter order.
 * measured: fnalign 45 -> 43; apply the rectangle's current-cell row offset before its column offset.
 * measured: fnalign 43 -> 39; enclosing case exits replace redundant returns and restore threaded helper branches.
 * measured: fnalign 39 -> 0, frame 0x190; caller-owned three-cell preparation preserves the unsigned offset web.
 */
/* Reuse the field subsystem's 0x10-byte cells at frame + 0x54. */

/* Do not cache the map provider: every retail field access calls it again. */
#define SMAP_GRID_MAP_VIEW(address) (&((FldFrame *)(address))->cells[0][0])
#define SMAP_GRID_SCAN_AT(rowOffset, columnOffset) \
    SMAP_GRID_MAP_VIEW((u8 *)((rowOffset) + (u32)MT_Scene_GetFrameState()) + (columnOffset))
#define SMAP_GRID_OFFSET_AT(offset) \
    SMAP_GRID_MAP_VIEW((offset) + (u32)MT_Scene_GetFrameState())
#define SMAP_GRID_CELL_AT(rowOffset, columnOffset) \
    (&((FldFrame *)(MT_Scene_GetFrameState() + (rowOffset) + (columnOffset)))->cells[0][0])
#define SMAP_GRID_NEIGHBOR_AT(rowOffset, columnOffset, cellOffset) \
    (SMAP_GRID_CELL_AT(rowOffset, columnOffset) + (cellOffset))



#pragma push
/* measured: fnalign 0 with the retail loop-invariant row/column preheaders. */
#pragma opt_loop_invariants on
/* Scan matching room cells and retain their anchor coordinates for reveal. */
static inline s32 smapPrepareRoomReveal(u8 column, u8 row, s32 extent,
                                      s32 cellRowOffset, s32 cellColumnOffset,
                                      s32 *rowSnapshot, s32 *columnSnapshot,
                                      s32 *anchorColumn, s32 *anchorRow) {
    extern s32 fclSubClamped(s32, s32, s32, s32, s8);
    s32 rowCounter;
    s32 rowStep;
    s32 columnCounter;
    s32 columnStep;
    s32 cellOffset;
    s32 candidateRow;
    s32 candidateColumn;
    s32 candidateRowOffset;
    s32 candidateColumnOffset;
    u8 kind;

    rowCounter = 0;
    *rowSnapshot = row;
    *columnSnapshot = column;
    cellOffset = cellRowOffset + cellColumnOffset;
    while ((rowStep = (s16)rowCounter) < extent) {
        candidateRow = (s8)fclSubClamped(*rowSnapshot, rowStep, 1, 0x18, 1);
        columnCounter = 0;
        candidateRowOffset = candidateRow << 8;
        while ((columnStep = (s16)columnCounter) < extent) {
            candidateColumn = (s8)fclSubClamped(*columnSnapshot, columnStep, 1, 0x10, 1);
            candidateColumnOffset = candidateColumn * 0x10;
            if ((SMAP_GRID_SCAN_AT(candidateRowOffset, candidateColumnOffset)->flags & 0xF) == 1) {
                kind = SMAP_GRID_SCAN_AT(candidateRowOffset, candidateColumnOffset)->type;
                if (kind == SMAP_GRID_OFFSET_AT(cellOffset)->type) {
                    *anchorColumn = (s8)(s64)candidateColumn;
                    *anchorRow = (s8)(s64)candidateRow;
                    break;
                }
            }
            columnCounter = (s16)(columnCounter + 1);
        }
        rowCounter = (s16)(rowCounter + 1);
    }
    return cellOffset;
}

/* Reveal matching room cells along the room orientation from its anchor. */
static inline void smapRevealRoomFootprint(u8 column, u8 row, s32 extent,
                                         s32 cellRowOffset, s32 cellColumnOffset,
                                         s32 cellOffset, s32 savedColumn,
                                         const s32 *anchorColumn, const s32 *anchorRow) {
    u8 orientation;

    orientation = SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->kind;
    switch (orientation) {
    case 0:
    case 2: {
        s32 step;
        s32 rowDelta;
        u16 revealColumn;
        u32 revealMask;
        u8 revealKind;
        u16 *visibility;

        step = 0;
        revealColumn = column;
        while ((rowDelta = (s16)step) < extent) {
            revealKind = SMAP_GRID_SCAN_AT(revealColumn * 0x10, ((s8)*anchorRow + rowDelta) << 8)->type;
            revealMask = (1 << savedColumn) & 0xFFFF & 0xFFFF;
            if (revealKind == SMAP_GRID_OFFSET_AT(cellOffset)->type) {
                visibility = (u16 *)((u8 *)byteAddressAdd((s8)*anchorRow * 2, (u8 *)D_00764658) + rowDelta * 2);
                *visibility |= revealMask;
            }
            step = (s16)(step + 1);
        }
        return;
    }
    case 1:
    case 3: {
        s32 step;
        s32 columnDelta;
        u16 revealRow;
        s32 mapRowOffset;
        s32 firstColumn;
        s32 revealRowOffset;
        u8 revealKind;
        u16 *visibility;

        step = 0;
        revealRow = row;
        mapRowOffset = revealRow << 8;
        firstColumn = (s8)*anchorColumn;
        revealRowOffset = revealRow * 2;
        while ((columnDelta = (s16)step) < extent) {
            revealKind = SMAP_GRID_SCAN_AT(mapRowOffset, (firstColumn + columnDelta) * 0x10)->type;
            if (revealKind == SMAP_GRID_OFFSET_AT(cellOffset)->type) {
                visibility = (u16 *)(revealRowOffset + (u32)D_00764658);
                *visibility |= (1 << (firstColumn + columnDelta)) & 0xFFFF;
            }
            step = (s16)(step + 1);
        }
        return;
    }
    }
}

/* Visibility-row casts retain the measured offset-first bitmap address trees; these are packed halfword rows, not object fields. */
// FUN_002AC750
/* measured: literal and named room-scan extent; best baseline residual 3044 differing bytes. */
void smapRevealCell(u8 column, u8 row) {
    extern s32 fclSubClamped(s32, s32, s32, s32, s8);
    extern s64 smapCellKind(u8);
    s32 savedRoomRow3;
    s32 savedRoomColumn3;
    s32 savedRoomRow2;
    s32 savedRoomColumn2;
    s32 currentCellOffset2;
    u32 currentCellOffset3;
    s32 scanRow9;
    s32 scanColumnStep9;
    s32 scanRowCounter9;
    s32 cellColumnOffset;
    s32 cellRowOffset;
    u32 rowValue;
    s32 visibilityRowOffset2;
    s32 rectangleRowOffset;
    s32 diagonalColumnOffset;
    s32 rowSnapshot;
    s32 neighborColumnOffset;
    s32 diagonalRowOffset;
    s32 columnSnapshot;
    s32 probeColumnOffset;
    s32 rowOffsetSnapshot;
    s32 probeRowOffset;
    s32 rectangleRowLimit;
    s32 scanColumnOffset9;
    s32 scanColumnOffset11;
    s32 scanColumnOffset13;
    u16 rectangleRow;
    u16 longRoomRow;
    s32 adjacentColumnMask;
    u16 verticalColumn;
    s32 adjacentVerticalMask;
    s32 adjacentDiagonalMask;
    s32 horizontalRowOffset;
    s32 verticalRowOffset;
    s32 diagonalVisibilityOffset;
    s32 horizontalMask;
    s32 verticalMask;
    s32 diagonalMask;
    s32 scanFirstColumn9;
    s32 scanFirstColumn11Value;
    s32 scanFirstColumn11;
    s32 scanFirstColumn13Value;
    s32 scanFirstColumn13;
    s32 probeRow;
    s32 scanRow11;
    s32 scanRow13;
    s32 scanColumnStep11;
    s32 scanColumnStep13;
    s32 diagonalRow;
    s32 diagonalColumn;
    s32 probeColumn;
    s32 passageClass;
    s32 horizontalColumn;
    s32 scanRowCounter11;
    s32 scanRowCounter13;
    s32 scanColumnCounter9;
    s32 scanColumnCounter11;
    s32 scanColumnCounter13;
    /* Shared by the exclusive room-search and square-scan phases.
     * Retail leaves both coordinates stale if a search finds no anchor. */
    s32 workingRow;
    /* Shared anchor column for the two room-search extents. */
    s32 columnReference;
    s32 scanRowValue11;
    s32 scanRowValue13;
    u16 *areaVisibility11;
    u16 *areaVisibility13;
    u16 *rightOpenRow;
    u16 *rightRow;
    u16 *rectangleVisibility;
    u16 *areaVisibility9;
    u16 *alternateVisibility;
    u16 *simpleVisibility;
    u16 *horizontalVisibility;
    u16 *adjacentHorizontalVisibility;
    u16 *verticalVisibility;
    u16 *adjacentVerticalVisibility;
    u16 *diagonalVisibility;
    u16 *adjacentDiagonalVisibility;
    u16 *roomVisibility9;
    u16 *upperOpenRow;
    u16 *longRoomVisibility;
    u16 *passageVisibility;
    u16 *specialVisibility;
    u16 *upperRow;
    u16 *lowerOpenRow;
    u16 *lowerRow;
    u16 *leftOpenRow;
    u16 *leftRow;
    u8 diagonalKind;
    u8 horizontalKind;
    u8 verticalKind;
    u8 expandedKind;
    u8 initialKind;
    u8 leftKind;
    u8 *nextHorizontalRow;
    u8 *nextHorizontalRowAdjacent;
    u8 *nextVerticalRow;
    u8 *nextVerticalRowAdjacent;
    u8 *diagonalNextRow;
    u8 *diagonalNextRowAdjacent;
    u8 *longRoomSecondRow;
    u8 *longRoomThirdRow;

    rowValue = row;
    cellRowOffset = rowValue * 0x100;
    cellColumnOffset = ((u32)column) * 0x10;
    if ((s32) SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->type < 7) {
        initialKind = SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->type;
        if (initialKind == 2) {
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 1) {
                if ((SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags & 0xF) == 1) {
                    columnSnapshot = (s32)column;
                    ((u16 *)D_00764658)[rowValue] |= ((1 << columnSnapshot) & 0xFFFF);
                    visibilityRowOffset2 = rowValue * 2;
                    rowSnapshot = (s32)row;
                    rowOffsetSnapshot = rowSnapshot << 8;
                    if ((SMAP_GRID_NEIGHBOR_AT(rowOffsetSnapshot, cellColumnOffset, -16)->type == 2) && (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->exits & 1)) {
                        if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 1) {
                            if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 0x10) {
                                upperOpenRow = (u16 *)((u8 *)D_00764658 + (((rowSnapshot - 1) & 0xFF) * 2));
                                *upperOpenRow |= ((1 << columnSnapshot) & 0xFFFF) & 0xFFFF;
                            }
                        } else {
                            upperRow = (u16 *)((u8 *)D_00764658 + (((rowSnapshot - 1) & 0xFF) * 2));
                            *upperRow |= ((1 << columnSnapshot) & 0xFFFF) & 0xFFFF;
                        }
                    }
                    if ((SMAP_GRID_NEIGHBOR_AT(rowOffsetSnapshot, cellColumnOffset, 16)->type == 2) && (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->exits & 4)) {
                        if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 4) {
                            if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 0x40) {
                                lowerOpenRow = (u16 *)((u8 *)D_00764658 + (((rowSnapshot + 1) & 0xFF) * 2));
                                *lowerOpenRow |= ((1 << columnSnapshot) & 0xFFFF) & 0xFFFF;
                            }
                        } else {
                            lowerRow = (u16 *)((u8 *)D_00764658 + (((rowSnapshot + 1) & 0xFF) * 2));
                            *lowerRow |= ((1 << columnSnapshot) & 0xFFFF) & 0xFFFF;
                        }
                    }
                    neighborColumnOffset = columnSnapshot * 0x10;
                    if ((SMAP_GRID_NEIGHBOR_AT(cellRowOffset, neighborColumnOffset, 1)->type == 2) && (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->exits & 8)) {
                        if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 8) {
                            if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 0x80) {
                                rightOpenRow = (u16 *)((u8 *)D_00764658 + visibilityRowOffset2);
                                *rightOpenRow |= (1 << ((columnSnapshot + 1) & 0xFF)) & 0xFFFF;
                            }
                        } else {
                            rightRow = (u16 *)((u8 *)D_00764658 + visibilityRowOffset2);
                            *rightRow |= (1 << ((columnSnapshot + 1) & 0xFF)) & 0xFFFF;
                        }
                    }
                    leftKind = SMAP_GRID_NEIGHBOR_AT(cellRowOffset, neighborColumnOffset, -1)->type;
                    if ((leftKind == 2) && (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->exits & 2)) {
                        if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 2) {
                            if (SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->unk0B & 0x20) {
                                leftOpenRow = (u16 *)((u8 *)D_00764658 + visibilityRowOffset2);
                                *leftOpenRow |= (1 << ((columnSnapshot - 1) & 0xFF)) & 0xFFFF;
                            }
                        } else {
                            leftRow = (u16 *)((u8 *)D_00764658 + visibilityRowOffset2);
                            *leftRow |= (1 << ((columnSnapshot - 1) & 0xFF)) & 0xFFFF;
                        }
                    }
                } else {
                    currentCellOffset2 = smapPrepareRoomReveal(column, row, 2, cellRowOffset, cellColumnOffset, &savedRoomRow2, &savedRoomColumn2, &columnReference, &workingRow);
                    smapRevealRoomFootprint(column, row, 2, cellRowOffset, cellColumnOffset, currentCellOffset2, savedRoomColumn2, &columnReference, &workingRow);
                }
            } else if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 2) {
                alternateVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *alternateVisibility |= (1 << (column & 0xFF)) & 0xFFFF;
            }
        } else {
            simpleVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
            *simpleVisibility |= (1 << (column & 0xFF)) & 0xFFFF;
        }
    } else if ((s32) SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->type < 9) {
        u16 rectangleColumn = column;
        s32 rectangleColumnLimit;
        s16 rectangleProbeColumn;
        s32 rectangleColumnOffset;

        rectangleVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
        *rectangleVisibility |= (1 << rectangleColumn) & 0xFFFF;
        rectangleColumnLimit = rectangleColumn + 2;
        probeColumn = ((s8)(fclSubClamped(rectangleColumn, 1, 1, rectangleColumnLimit, 1)));
        rectangleRowOffset = rowValue << 8;
        probeColumnOffset = probeColumn * 0x10;
        horizontalKind = SMAP_GRID_CELL_AT(rectangleRowOffset, probeColumnOffset)->type;
        if ((horizontalKind == SMAP_GRID_CELL_AT(rectangleRowOffset, cellColumnOffset)->type) && ((SMAP_GRID_CELL_AT(cellRowOffset, probeColumnOffset)->flags & 0xF) == 1)) {
            horizontalColumn = ((s8)(probeColumn));
            horizontalMask = (1 << horizontalColumn) & 0xFFFF;
            horizontalRowOffset = ((s32)row) * 2;
            horizontalVisibility = (u16 *)((u8 *)D_00764658 + horizontalRowOffset);
            *horizontalVisibility |= horizontalMask;
            adjacentColumnMask = (1 << (horizontalColumn + 1)) & 0xFFFF;
            adjacentHorizontalVisibility = (u16 *)((u8 *)D_00764658 + horizontalRowOffset);
            *adjacentHorizontalVisibility |= adjacentColumnMask;
            nextHorizontalRow = (u8 *)(horizontalRowOffset + (u32)D_00764658);
            (((u16 *)nextHorizontalRow)[1]) = (u16) ((((u16 *)nextHorizontalRow)[1]) | horizontalMask);
            nextHorizontalRowAdjacent = (u8 *)(horizontalRowOffset + (u32)D_00764658);
            (((u16 *)nextHorizontalRowAdjacent)[1]) = (u16) ((((u16 *)nextHorizontalRowAdjacent)[1]) | adjacentColumnMask);
            return;
        }
        rectangleRow = row;
        rectangleRowLimit = rectangleRow + 2;
        probeRow = ((s8)(fclSubClamped(rectangleRow, 1, 1, rectangleRowLimit, 1)));
        rectangleProbeColumn = column;
        rectangleColumnOffset = rectangleProbeColumn * 0x10;
        probeRowOffset = probeRow << 8;
        verticalKind = SMAP_GRID_CELL_AT(probeRowOffset, rectangleColumnOffset)->type;
        if ((verticalKind == SMAP_GRID_CELL_AT(cellRowOffset, rectangleColumnOffset)->type) && ((SMAP_GRID_CELL_AT(probeRowOffset, cellColumnOffset)->flags & 0xF) == 1)) {
            verticalColumn = column & 0xFF;
            verticalMask = (1 << verticalColumn) & 0xFFFF;
            verticalRowOffset = ((s8)(probeRow)) * 2;
            verticalVisibility = (u16 *)((u8 *)D_00764658 + verticalRowOffset);
            *verticalVisibility |= verticalMask;
            adjacentVerticalMask = (1 << (verticalColumn + 1)) & 0xFFFF;
            adjacentVerticalVisibility = (u16 *)((u8 *)D_00764658 + verticalRowOffset);
            *adjacentVerticalVisibility |= adjacentVerticalMask;
            nextVerticalRow = (u8 *)(verticalRowOffset + (u32)D_00764658);
            (((u16 *)nextVerticalRow)[1]) = (u16) ((((u16 *)nextVerticalRow)[1]) | verticalMask);
            nextVerticalRowAdjacent = (u8 *)(verticalRowOffset + (u32)D_00764658);
            (((u16 *)nextVerticalRowAdjacent)[1]) = (u16) ((((u16 *)nextVerticalRowAdjacent)[1]) | adjacentVerticalMask);
            return;
        }
        diagonalColumn = ((s8)(fclSubClamped((column & 0xFF), 1, 1, rectangleColumnLimit, 1)));
        diagonalRow = ((s8)(fclSubClamped((row & 0xFF), 1, 1, rectangleRowLimit, 1)));
        diagonalRowOffset = diagonalRow << 8;
        diagonalColumnOffset = ((s8)(diagonalColumn)) * 0x10;
        diagonalKind = SMAP_GRID_CELL_AT(diagonalRowOffset, diagonalColumnOffset)->type;
        if ((diagonalKind == SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->type) && ((SMAP_GRID_CELL_AT(diagonalRowOffset, diagonalColumnOffset)->flags & 0xF) == 1)) {
            diagonalMask = (1 << (((s8)(diagonalColumn)))) & 0xFFFF;
            diagonalVisibilityOffset = ((s8)(diagonalRow)) * 2;
            diagonalVisibility = (u16 *)((u8 *)D_00764658 + diagonalVisibilityOffset);
            *diagonalVisibility |= diagonalMask;
            adjacentDiagonalMask = (1 << ((((s8)(diagonalColumn))) + 1)) & 0xFFFF;
            adjacentDiagonalVisibility = (u16 *)((u8 *)D_00764658 + diagonalVisibilityOffset);
            *adjacentDiagonalVisibility |= adjacentDiagonalMask;
            diagonalNextRow = (u8 *)(diagonalVisibilityOffset + (u32)D_00764658);
            (((u16 *)diagonalNextRow)[1]) = (u16) ((((u16 *)diagonalNextRow)[1]) | diagonalMask);
            diagonalNextRowAdjacent = (u8 *)(diagonalVisibilityOffset + (u32)D_00764658);
            (((u16 *)diagonalNextRowAdjacent)[1]) = (u16) ((((u16 *)diagonalNextRowAdjacent)[1]) | adjacentDiagonalMask);
        }
    } else {
        expandedKind = SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->type;
        switch (expandedKind) {                         /* switch 2 */
        case 9:                                     /* switch 2 */
        case 10:                                    /* switch 2 */
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 1) {
                roomVisibility9 = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *roomVisibility9 |= (1 << (column & 0xFF)) & 0xFFFF;
                return;
            }
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 2) {
                areaVisibility9 = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *areaVisibility9 |= (1 << ((s32)column)) & 0xFFFF;
                scanFirstColumn9 = ((s8)(fclSubClamped(((s32)column), 1, 0, 0, 1)));
                workingRow = ((s8)(fclSubClamped(rowValue, 1, 0, 0, 1)));
                scanRowCounter9 = 0;
                while (((s16)(scanRowCounter9)) < 3) {
                    s32 mapRowOffset;
                    s32 visibilityRowOffset;
                    scanColumnCounter9 = 0;
                    scanRow9 = ((s8)(workingRow));
                    mapRowOffset = scanRow9 << 8;
                    visibilityRowOffset = scanRow9 * 2;
                    while ((scanColumnStep9 = ((s16)(scanColumnCounter9))) < 3) {
                        scanColumnOffset9 = fclAddClamped((((s8)(scanFirstColumn9))), scanColumnStep9, 0x10, 0, 1) * 0x10;
                        if (((s8)(smapCellKind(SMAP_GRID_SCAN_AT(mapRowOffset, scanColumnOffset9)->flags))) == 2) {
                            *((u16 *)(visibilityRowOffset + (u32)D_00764658)) |= (1 << fclAddClamped((((s8)(scanFirstColumn9))), scanColumnStep9, 0x10, 0, 1)) & 0xFFFF;
                        }
                        scanColumnCounter9 = ((s16)((scanColumnCounter9 + 1)));
                    }
                    workingRow = ((s8)(fclAddClamped(scanRow9, 1, 0x18, 0, 1)));
                    scanRowCounter9 = ((s16)((scanRowCounter9 + 1)));
                }
                return;
            }
            break;
        case 11:                                    /* switch 2 */
        case 12:                                    /* switch 2 */
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 1) {
                if ((SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags & 0xF) == 1) {
                    longRoomVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                    *longRoomVisibility |= ((1 << ((s32)column)) & 0xFFFF);
                    longRoomRow = row;
                    longRoomSecondRow = byteAddressAdd(longRoomRow * 2, (u8 *)D_00764658);
                    (((u16 *)longRoomSecondRow)[1]) = (u16) ((((u16 *)longRoomSecondRow)[1]) | ((1 << ((s32)column)) & 0xFFFF));
                    longRoomThirdRow = byteAddressAdd(longRoomRow * 2, (u8 *)D_00764658);
                    (((u16 *)longRoomThirdRow)[2]) = (u16) ((((u16 *)longRoomThirdRow)[2]) | ((1 << ((s32)column)) & 0xFFFF));
                    return;
                }
                /* This unsigned offset spans the caller's search and the shared reveal phase. */
                {
                    s32 rowCounter;
                    s32 rowStep;
                    s32 columnCounter;
                    s32 columnStep;
                    s32 candidateRow;
                    s32 candidateColumn;
                    s32 candidateRowOffset;
                    s32 candidateColumnOffset;
                    u8 kind;

                    rowCounter = 0;
                    savedRoomRow3 = row;
                    savedRoomColumn3 = column;
                    currentCellOffset3 = cellRowOffset + cellColumnOffset;
                    while ((rowStep = (s16)rowCounter) < 3) {
                        candidateRow = (s8)fclSubClamped(savedRoomRow3, rowStep, 1, 0x18, 1);
                        columnCounter = 0;
                        candidateRowOffset = candidateRow << 8;
                        while ((columnStep = (s16)columnCounter) < 3) {
                            candidateColumn = (s8)fclSubClamped(savedRoomColumn3, columnStep, 1, 0x10, 1);
                            candidateColumnOffset = candidateColumn * 0x10;
                            if ((SMAP_GRID_SCAN_AT(candidateRowOffset, candidateColumnOffset)->flags & 0xF) == 1) {
                                kind = SMAP_GRID_SCAN_AT(candidateRowOffset, candidateColumnOffset)->type;
                                if (kind == SMAP_GRID_OFFSET_AT(currentCellOffset3)->type) {
                                    columnReference = (s8)(s64)candidateColumn;
                                    workingRow = (s8)(s64)candidateRow;
                                    break;
                                }
                            }
                            columnCounter = (s16)(columnCounter + 1);
                        }
                        rowCounter = (s16)(rowCounter + 1);
                    }
                }
                smapRevealRoomFootprint(column, row, 3, cellRowOffset, cellColumnOffset, currentCellOffset3, savedRoomColumn3, &columnReference, &workingRow);
            } else if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 2) {
                areaVisibility11 = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *areaVisibility11 |= (1 << ((s32)column)) & 0xFFFF;
                scanFirstColumn11Value = ((s8)(fclSubClamped(((s32)column), 1, 0, 0, 1)));
                scanRowValue11 = ((s8)(fclSubClamped(rowValue, 1, 0, 0, 1)));
                scanRowCounter11 = 0;
                scanFirstColumn11 = (s8)scanFirstColumn11Value;
                while (((s16)(scanRowCounter11)) < 3) {
                    s32 mapRowOffset;
                    s32 visibilityRowOffset;
                    scanColumnCounter11 = 0;
                    scanRow11 = ((s8)(scanRowValue11));
                    mapRowOffset = scanRow11 << 8;
                    visibilityRowOffset = scanRow11 * 2;
                    while ((scanColumnStep11 = ((s16)(scanColumnCounter11))) < 3) {
                        scanColumnOffset11 = fclAddClamped(scanFirstColumn11, scanColumnStep11, 0x10, 0, 1) * 0x10;
                        if (((s8)(smapCellKind(SMAP_GRID_SCAN_AT(mapRowOffset, scanColumnOffset11)->flags))) == 2) {
                            *((u16 *)(visibilityRowOffset + (u32)D_00764658)) |= (1 << fclAddClamped(scanFirstColumn11, scanColumnStep11, 0x10, 0, 1)) & 0xFFFF;
                        }
                        scanColumnCounter11 = ((s16)((scanColumnCounter11 + 1)));
                    }
                    scanRowValue11 = ((s8)(fclAddClamped(scanRow11, 1, 0x18, 0, 1)));
                    scanRowCounter11 = ((s16)((scanRowCounter11 + 1)));
                }
                return;
            }
            break;
        case 13:                                    /* switch 2 */
        case 14:                                    /* switch 2 */
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 1) {
                passageVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *passageVisibility |= (1 << (column & 0xFF)) & 0xFFFF;
                return;
            }
            passageClass = ((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags)));
            if (passageClass == 3) {
                specialVisibility = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *specialVisibility |= (1 << (column & 0xFF)) & 0xFFFF;
                return;
            }
            if (((s8)(smapCellKind(SMAP_GRID_CELL_AT(cellRowOffset, cellColumnOffset)->flags))) == 2) {
                areaVisibility13 = (u16 *)((u8 *)D_00764658 + (rowValue * 2));
                *areaVisibility13 |= (1 << ((s32)column)) & 0xFFFF;
                scanFirstColumn13Value = ((s8)(fclSubClamped(((s32)column), 1, 0, 0, 1)));
                scanRowValue13 = ((s8)(fclSubClamped(rowValue, 1, 0, 0, 1)));
                scanRowCounter13 = 0;
                scanFirstColumn13 = (s8)scanFirstColumn13Value;
                while (((s16)(scanRowCounter13)) < 3) {
                    s32 mapRowOffset;
                    s32 visibilityRowOffset;
                    scanColumnCounter13 = 0;
                    scanRow13 = ((s8)(scanRowValue13));
                    mapRowOffset = scanRow13 << 8;
                    visibilityRowOffset = scanRow13 * 2;
                    while ((scanColumnStep13 = ((s16)(scanColumnCounter13))) < 3) {
                        scanColumnOffset13 = fclAddClamped(scanFirstColumn13, scanColumnStep13, 0x10, 0, 1) * 0x10;
                        if (((s8)(smapCellKind(SMAP_GRID_SCAN_AT(mapRowOffset, scanColumnOffset13)->flags))) == 2) {
                            *((u16 *)(visibilityRowOffset + (u32)D_00764658)) |= (1 << fclAddClamped(scanFirstColumn13, scanColumnStep13, 0x10, 0, 1)) & 0xFFFF;
                        }
                        scanColumnCounter13 = ((s16)((scanColumnCounter13 + 1)));
                    }
                    scanRowValue13 = ((s8)(fclAddClamped(scanRow13, 1, 0x18, 0, 1)));
                    scanRowCounter13 = ((s16)((scanRowCounter13 + 1)));
                }
            }
            break;
        default:
            break;
        }
    }
}
#pragma pop
#undef SMAP_GRID_MAP_VIEW
#undef SMAP_GRID_SCAN_AT
#undef SMAP_GRID_OFFSET_AT
#undef SMAP_GRID_CELL_AT
#undef SMAP_GRID_NEIGHBOR_AT
// FUN_002ADCF0
s64 smapCellKind(u8 cellFlags) {
    return (s64)(s8)((cellFlags & 0xFF) >> 4);
}



/* measured: re-tested wave 4 (nd 4, unchanged) — call 1 arg setup is the
   only diff: retail materialises addiu $a0,$0,0xE before the addiu
   $a1,$a1,0xB4; mwcc b210 emits the arithmetic arg first (call 2 (0xE,0)
   already matches). Tried old-style () fn-ptr local, dual s32 temps,
   s32 arg1 typing, cached fn-ptr — all nd 4. Matched sibling
   func_002add60 emits const-first because its 2nd arg is a load.
   Argument-scheduling floor. */
// FUN_002ADD10
void smapSetPrimitiveState(s32 unused, u8 *work) {
    D_00887304[0](0xE, work + 0xB4);
    D_00887300[0](0xE, 0);
}

// FUN_002ADD60
void smapSetStateValue(u8 *unused, u8 *work) {
    D_00887300[0](0xE, ((SMapWork *)work)->renderState);
}



/* Map cells occupy 0x10 bytes in rows of 0x100 bytes. Read from the
 * complete map allocation so a neighboring cell can cross a logical row.
 * Signed neighbor offsets preserve integer promotion before +/- 1; ordinary
 * byte coordinates use unsigned offsets. Both stay in the same byte domain.
 */
#define SMAP_FIELD_CELL(row, column, offset) \
    (&((FldFrame *)MT_Scene_GetFrameState())->cells[(row)][(column) + ((offset) - 0x54) / 0x10])

/* Update actor markers, reveal the player cell and connected neighbors, and position nearby minimap tiles. */
// FUN_002ADD90
s32 smapUpdateEntities(u8 *taskObject)
{
    SMapWork *map;
    YVec2f scale;
    YVec3f pos;
    YVec3f positionSnapshot;
    YVec3f horizontalOffset;
    YVec3f verticalOffset;
    u8 *work;
    u8 *task;
    s32 tileY;
    s32 tileX;
    u8 y;
    s32 unitIndex;
    u8 x;

    work = ((KwlnTask *)taskObject)->work;
    map = (SMapWork *)work;
    /* Kind-specific scene tail; the embedded shared character prefix ends at 0x168. */
    FldFrameTask_GetPosition((u8 *)&positionSnapshot, (u8 *)((ResrcRecord *)D_007EFA04[0])->handle220);
    /* The provider writes all three floats; measured: an address-source copy matches, direct struct assignment does not. */
    pos = *(YVec3f *)&positionSnapshot;
    task = PrimAllocQueueNode();
    ((PrimQueueNode *)task)->callback = smapSetPrimitiveState;
    ((PrimQueueNode *)task)->argument.data = work;
    PrimAppendNode(D_00794C30, task);
    task = PrimAllocQueueNode();
    ((PrimQueueNode *)task)->callback = smapSetStateValue;
    ((PrimQueueNode *)task)->argument.data = work;
    PrimAppendNode(D_00794E10, task);
    /* measured: direct, typed-local and array member forms change retail instructions. */
    switch ((s8)MEMBER(u8, work, SMapWork, phase)) {
    case 0:
        smapUpdateItems(taskObject);
        (((SMapWork *)work)->phase)++;
        break;
    case 2:
        ((SMapWork *)work)->labelFrame = fclAddClamped(map->labelFrame, 1, 5, 0, 1);
        if ((s8)fclSpriteHasDisplayFlags(((SMapWork *)work)->labels[0]) == 0) {
            fclSpriteSetRecordFlag(map->labels[0], 0, 1);
        }
        if ((s8)fclSpriteHasDisplayFlags(((SMapWork *)work)->labels[1]) == 0) {
            fclSpriteSetRecordFlag(map->labels[1], 0, 1);
        }
        /* fall through */
    case 5:
        ((SMapWork *)work)->transitionFrame = fclAddClamped(map->transitionFrame, 1, 10, 0, 1);
        /* fall through */
    case 1:
        ((SMapWork *)work)->mode = 0;
        for (unitIndex = 0; unitIndex < 15; unitIndex++) {
            s32 live = 0;
            u8 *unit = D_007E8C00 + unitIndex * 0x750;

            if ((((FldEventActor *)unit)->unit != 0) && (((FldEventActor *)unit)->active != 0)) {
                live = 1;
            }
            if ((u8)(live != 0) == 1) {
                u8 **slot = &((SMapWork *)work)->actorMarkers[unitIndex];

                if (*slot == NULL) {
                    *slot = (u8 *)mapSymbolEntityCreate((s32)taskObject, (s8)unitIndex);
                }
            }
        }
        x = smapWorldToColumn(pos);
        y = smapWorldToRow(pos);
        smapRevealCell(x, y);
        if (SMAP_FIELD_CELL((u32)y, (s32)x, 0x64)->occupied == 1 && (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->exits & 8)) {
            if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 8) {
                if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 0x80) {
                    smapRevealCell((u8)(x + 1), y);
                }
            } else {
                smapRevealCell((u8)(x + 1), y);
            }
        }
        if (SMAP_FIELD_CELL((u32)y, (s32)x, 0x44)->occupied == 1 && (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->exits & 2)) {
            if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 2) {
                if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 0x20) {
                    smapRevealCell((u8)(x - 1), y);
                }
            } else {
                smapRevealCell((u8)(x - 1), y);
            }
        }
        if (SMAP_FIELD_CELL((s32)y, (u32)x, -0xAC)->occupied == 1 && (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->exits & 1)) {
            if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 1) {
                if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 0x10) {
                    smapRevealCell(x, (u8)(y - 1));
                }
            } else {
                smapRevealCell(x, (u8)(y - 1));
            }
        }
        if (SMAP_FIELD_CELL((s32)y, (u32)x, 0x154)->occupied == 1 && (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->exits & 4)) {
            if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 4) {
                if (SMAP_FIELD_CELL((u32)y, (u32)x, 0x54)->unk0B & 0x40) {
                    smapRevealCell(x, (u8)(y + 1));
                }
            } else {
                smapRevealCell(x, (u8)(y + 1));
            }
        }
        fclVec3Subtract((u8 *)&horizontalOffset, work + 8, (u8 *)&pos);
        scale.x = (s32)(horizontalOffset.x / 66.666664f);
        fclVec3Subtract((u8 *)&verticalOffset, work + 8, (u8 *)&pos);
        scale.y = (s32)(verticalOffset.z / 66.666664f);
        for (tileX = 0; tileX < 13; tileX++) {
            for (tileY = 0; tileY < 13; tileY++) {
                /* Kind-specific scene tail; the embedded shared character prefix ends at 0x168. */
                s16 tx = tileX + (FldFrameTask_GetTileX((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220) - 6);
                /* Kind-specific scene tail; the embedded shared character prefix ends at 0x168. */
                s16 ty = tileY + (FldFrameTask_GetTileZ((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220) - 6);

                if ((tx > 0) && (ty > 0) && (tx < 16) && (ty < 24)) {
                    u8 **tile = &((SMapWork *)work)->cells[ty][tx];

                    if (kwlnTaskIsLinked(*tile) == 1) {
                        u16 mask = (1 << tx) & 0xFFFF;
                        if (((mask & ((u16 *)D_00764658)[ty]) >> tx) == 1) {
                            smapSetVisible(*tile, 1);
                        }
                        smapSetPosition(*tile, scale);
                    }
                }
            }
        }
        smapClearSelection(taskObject);
        break;
    case 3:
        ((SMapWork *)work)->labelFrame = fclAddClamped(map->labelFrame, 1, 5, 0, 1);
        /* fall through */
    case 6:
        ((SMapWork *)work)->transitionFrame = fclAddClamped(map->transitionFrame, 1, 5, 0, 1);
        /* fall through */
    case 4:
        smapClearSelection(taskObject);
        break;
    case 7:
        return -1;
    }
    return 0;
}

#undef SMAP_FIELD_CELL
/* Free the frame and strip sprites and release the map task work. */
// FUN_002AE520
void smapFreeSprites(u8 *task) {
    KwlnTask *owner = (KwlnTask *)task;
    u8 *work;
    s16 spriteIndex;

    work = ((KwlnTask *)task)->work;
    spriteIndex = 0;
    while (spriteIndex < 4) {
        sdkSpriteFreeNode(((SMapWork *)work)->corners[spriteIndex]);
        spriteIndex++;
    }
    spriteIndex = 0;
    while (spriteIndex < 6) {
        sdkSpriteFreeNode(((SMapWork *)work)->leftStrip[spriteIndex]);
        sdkSpriteFreeNode(((SMapWork *)work)->middleStrip[spriteIndex]);
        sdkSpriteFreeNode(((SMapWork *)work)->rightStrip[spriteIndex]);
        spriteIndex++;
    }
    sdkSpriteFreeNode(((SMapWork *)work)->ends[0]);
    sdkSpriteFreeNode(((SMapWork *)work)->ends[1]);
    jtbl_008873EC[0](owner->work);
}

/* Each map query remains independent. The native row address and byte
 * column/field offsets refer to the complete allocation, while neighbor
 * tables contain signed byte pairs for each orientation.
 */
#define SMAP_SCAN_CELL(rowOffset, column) \
    (&((FldFrame *)((u8 *)((rowOffset) + (u32)MT_Scene_GetFrameState()) + (u32)(column) * 0x10))->cells[0][0])
/* Four orientation pairs per tile portion; subsequent portions begin eight bytes later. */
typedef struct SMapNeighbor { s8 offset[2]; } SMapNeighbor;
#define SMAP_NEIGHBOR_OFFSET(table, direction, field) \
    (((SMapNeighbor *)(table))[(direction) + (field) / 2].offset[(field) & 1])

#pragma push
/* Retain each selected offset table and issue screen constants at their uses. */
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* Build tiles and marker children for the map, actor slots, scene points and active targets. */
// FUN_002AE630
/* measured: existing typed map alias and separate pullout probe; best baseline residual 1828 differing bytes. */
u8 *smapCreateSymbols(u8 *parent)
{
    SMapWork *map;
    extern s8 D_0063EEE0[];
    extern s8 D_0063EF00[];
    extern s8 D_0063EF20[];
    extern s8 D_0063EF40[];
    extern u8 *smapBuildTiles(u8 *, u8, u8, u8, u8, u8, u8, u8);
    extern u8 *smapCreateOverlay(u8 *, YVec2f, f32, f32, u32);
    extern void smapCellToWorld(void *, u32, u32);
    extern f32 smapPositionOffsetX(f32, YVec3f *);
    extern f32 smapPositionOffsetZ(f32, YVec3f *);
    extern s32 mapSymbolMarkerCreate(s32);
    extern s32 mapSymbolPointCreate(s32, s32, YVec3f *);
    extern s32 mapSymbolTargetCreate(s32, YVec2f, s32);
    extern s32 fclSpriteCreateDrawTask(s32, s16, s32);
    extern void *mdlGetMatrix(void *);
    extern u8 *MT_Scene_GetResListHead(s32);
    u8 *task;
    u8 *work;
    s32 originX;
    s32 originY;
    YVec2f foePosition;
    YVec3f origin;
    YVec2f framePosition1;
    YVec2f framePosition2;
    YVec2f framePosition3;
    YVec2f framePosition4;
    union { FclDrawColor color; u32 packed; } frameColor1;
    union { FclDrawColor color; u32 packed; } frameColor2;
    union { FclDrawColor color; u32 packed; } frameColor3;
    union { FclDrawColor color; u32 packed; } frameColor4;
    s32 rowIndex;
    s32 columnIndex;
    s32 unitIndex;
    u8 *sceneNode;
    s32 nodeIndex;
    u8 *nodeMatrix;

    chkmemAllocSiteTag(D_0063EF60, 0x389);
    work = D_008873F4[0](1, 0x768, 0x40000);
    map = (SMapWork *)work;
    task = kwlnTaskCreateChild(parent, D_0063EFD8, 0xF, 0, 0,
                        smapUpdateEntities, smapFreeSprites, work);
    ((SMapWork *)work)->self = work;
    ((SMapWork *)work)->phase = 0;
    /* Kind-specific scene tail; the embedded shared character prefix ends at 0x168. */
    originX = FldFrameTask_GetTileX((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220) & 0xFF;
    /* Kind-specific scene tail; the embedded shared character prefix ends at 0x168. */
    originY = FldFrameTask_GetTileZ((u8 *)((ResrcRecord *)D_007EFA04[0])->handle220) & 0xFF;
    smapCellToWorld(&origin, (u32)originX, (u32)originY);
    ((SMapWork *)work)->origin = origin;
    D_00764660 = (u8)smapWorldToColumn(((SMapWork *)work)->origin);
    D_0076465C = (u8)smapWorldToRow(map->origin);
    ((SMapWork *)work)->cellSize = 0x12;
    for (rowIndex = 0; rowIndex < 0x18; rowIndex++) {
        u8 *taskRow;
        s32 mapRowOffset;
        columnIndex = 0;
        mapRowOffset = rowIndex << 8;
        taskRow = work + (rowIndex << 6);
        for (; columnIndex < 0x10; columnIndex++) {
            if (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->occupied != 0 &&
                (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->flags & 0xF) == 1) {
                if (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type >= 9) {
                    switch (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type) {
                    case 9:
                    case 10: {
                        const s8 *orientation;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        orientation = D_0063EEE0 + (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind) * 2;
                        offsetX = orientation[0];
                        orientation = D_0063EEE0 + (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind) * 2;
                        offsetY = orientation[1];
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 1, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        orientation = D_0063EEE0 + (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind) * 2;
                        offsetX = orientation[8];
                        orientation = D_0063EEE0 + (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind) * 2;
                        offsetY = orientation[9];
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 2, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    case 11:
                    case 12: {
                        const s8 *neighborTable = D_0063EF00;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 1, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 2, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    case 13:
                    case 14: {
                        const s8 *neighborTable = D_0063EF20;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 1, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 2, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 0x10);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 0x11);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 3, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        break;
                    }
                    }
                } else {
                    if (SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type == 2) {
                        const s8 *neighborTable = D_0063EF40;
                        s8 offsetX;
                        s32 offsetY;
                        s32 tileColumn;
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 0);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 1);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 1, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                        offsetX = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 8);
                        offsetY = SMAP_NEIGHBOR_OFFSET(neighborTable, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind, 9);
                        tileColumn = columnIndex + (s32)offsetX;
                        ((SMapWork *)((u32)taskRow + (s32)offsetY * 0x40))->cells[0][tileColumn] =
                            smapBuildTiles(task, (tileColumn & 0xFF), ((rowIndex + (s32)offsetY) & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 2, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                    } else {
                        ((SMapWork *)taskRow)->cells[0][columnIndex] =
                            smapBuildTiles(task, (columnIndex & 0xFF), (rowIndex & 0xFF),
                                SMAP_SCAN_CELL(mapRowOffset, columnIndex)->type, 1, SMAP_SCAN_CELL(mapRowOffset, columnIndex)->kind,
                                (u8)columnIndex, (u8)rowIndex);
                    }
                }
            }
        }
    }
    framePosition1 = fclMakeVec2(17.0f, 150.0f);
    frameColor1.color = fclMakeDrawColor(0x80, 0x80, 0x80, 0);
    ((SMapWork *)work)->frames[0] = smapCreateOverlay(task, framePosition1, 240.0f, 120.0f, frameColor1.packed);
    framePosition2 = fclMakeVec2(148.0f, 249.0f);
    frameColor2.color = fclMakeDrawColor(0x80, 0, 0, 0);
    ((SMapWork *)work)->frames[1] = smapCreateOverlay(task, framePosition2, 150.0f, 231.0f, frameColor2.packed);
    framePosition3 = fclMakeVec2(0.0f, 395.0f);
    frameColor3.color = fclMakeDrawColor(0, 0x80, 0, 0);
    ((SMapWork *)work)->frames[2] = smapCreateOverlay(task, framePosition3, 151.0f, 121.0f, frameColor3.packed);
    framePosition4 = fclMakeVec2(0.0f, 150.0f);
    frameColor4.color = fclMakeDrawColor(0, 0, 0x80, 0);
    ((SMapWork *)work)->frames[3] = smapCreateOverlay(task, framePosition4, 23.0f, 395.0f, frameColor4.packed);
    ((SMapWork *)work)->playerMarker = (u8 *)(mapSymbolMarkerCreate((s32)task));
    for (unitIndex = 0; unitIndex < 0xF; unitIndex++) {
        s32 unitPresent;
        u8 *entry;
        unitPresent = 0;
        entry = D_007E8C00 + unitIndex * 0x750;
        if (((FldEventActor *)entry)->unit != 0 && ((FldEventActor *)entry)->active != 0) {
            unitPresent = 1;
        }
        if ((u32)(unitPresent != 0) == 1) {
            ((SMapWork *)work)->actorMarkers[unitIndex] = (u8 *)(mapSymbolEntityCreate((s32)task, (s8)unitIndex));
        }
    }
    {
        u8 *sprite;
        YVec3f *enemyPosition;
        s32 enemyIndex;
        sprite = sdkSpriteNewNode(D_00764644, 0x12);
        for (enemyIndex = 0; enemyIndex < 8; enemyIndex++) {
            u8 *entry;
            entry = D_007E80A0 + enemyIndex * 0x168;
            if (((SMapTarget *)entry)->active != 0) {
                f32 screenX;
                f32 screenY;
                f32 relativeX;
                f32 relativeY;
                enemyPosition = &((SMapTarget *)entry)->position;
                screenX = (f32)smapWorldToColumn(*(RwV3d *)enemyPosition) * 18.0f + 172.0f;
                relativeX = smapPositionOffsetX(18.0f, enemyPosition);
                foePosition.x = (screenX - relativeX) - 2.0f;
                screenY = (f32)smapWorldToRow(*(RwV3d *)enemyPosition) * 18.0f + 9.0f;
                relativeY = smapPositionOffsetZ(18.0f, enemyPosition);
                foePosition.y = (screenY - relativeY) - 2.0f;
                ((SMapWork *)work)->targetMarkers[enemyIndex] = (u8 *)(mapSymbolTargetCreate((s32)task, foePosition, (enemyIndex & 0xFF)));
            }
        }
        sdkSpriteFreeNode(sprite);
    }
    ((SMapWork *)work)->labels[0] = (u8 *)(fclSpriteCreateDrawTask((s32)task, 0xC, D_00764644));
    ((SMapWork *)work)->labels[1] = (u8 *)(fclSpriteCreateDrawTask((s32)task, 0xD, D_00764644));
    sceneNode = MT_Scene_GetResListHead(3);
    nodeIndex = 0;
    ((SMapWork *)work)->pointMarkers[1] = (u8 *)(0);
    ((SMapWork *)work)->pointMarkers[0] = (u8 *)(0);
    while (sceneNode != NULL) {
        nodeMatrix = mdlGetMatrix(((SceneCharacterUpdate *)sceneNode)->model);
        ((SMapWork *)work)->pointMarkers[nodeIndex] = (u8 *)(mapSymbolPointCreate((s32)task, (s8)nodeIndex, (YVec3f *)(nodeMatrix + 0x30)));
        nodeIndex++;
        sceneNode = (u8 *)((ResrcHeader *)sceneNode)->next;
    }
    return task;
}

#pragma pop

#undef SMAP_NEIGHBOR_OFFSET
#undef SMAP_SCAN_CELL
/* Value initialization preserves the constructor's temporary before the label
   position is reused. Loop invariants hoist the final grid row's coordinates. */
/* Switch between scrolling and fixed-map presentation, animating labels and resetting tile visibility. */
// FUN_002AF3E0
#pragma push
#pragma opt_loop_invariants on
/* Access-site marker/cell fields retain the original byte cursors and measured index conversions. */
/* measured: access-site fields and typed map alias; best baseline residual 1353 differing bytes. */
void smapRefreshCells(u8 *task, s8 mode)
{
    u8 *work = ((KwlnTask *)task)->work;
    s16 markerIndex;
    s16 visibleRow;
    s16 column;
    s16 row;

    mapSymbolMarkerSetHighlight(((SMapWork *)work)->playerMarker);
    for (markerIndex = 0; markerIndex < 15; markerIndex++) {
        s32 valid = 0;
        u8 *entry = D_007E8C00 + markerIndex * 0x750;
        if (((FldEventActor *)entry)->unit != 0 && ((FldEventActor *)entry)->active != 0)
            valid = 1;
        if ((u8)(valid != 0) == 1)
            mapSymbolTargetSetState(((SMapWork *)work)->actorMarkers[markerIndex], mode);
    }
    for (markerIndex = 0; markerIndex < 8; markerIndex++) {
        if (((SMapTarget *)(D_007E80A0 + markerIndex * 0x168))->active != 0)
            fclFadeRectSetControl(((SMapWork *)work)->targetMarkers[markerIndex], mode);
    }
    for (markerIndex = 0; markerIndex < 2; markerIndex++) {
        u8 *task = ((SMapWork *)work)->pointMarkers[markerIndex];
        if (task != NULL)
            mapSymbolPointSetState(task, mode);
    }
    D_00764654 = 0;
    ((SMapWork *)work)->transitionFrame = 0;
    ((SMapWork *)work)->labelFrame = 0;
    for (row = 0; row < 24; row++) {
        for (column = 0; column < 16; column++) {
            if (kwlnTaskIsLinked(((SMapWork *)work)->cells[row][column]) == 1) {
                smapSetCellMode(((SMapWork *)work)->cells[row][column], mode);
                smapSetActive(((SMapWork *)work)->cells[row][column], 0);
            }
        }
    }
    if (mode == 0) {
        u8 *resource;
        ((SMapWork *)work)->phase = 2;
        ((SMapWork *)work)->mode = 0;
        {
            YVec2f pos = fclMakeVec2(15.0f, 406.0f);
            resource = sdkSpriteNewNode(D_00764644, 12);
            fclSpriteStartRevealScaleTask(((SMapWork *)work)->labels[0], 1.0f, 1.0f, 1.0f, 0.1f, 0, 3, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartPositionTask(MEMBER(u8 *, work, SMapWork, labels[0]), pos,
                fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartAlphaTask(MEMBER(u8 *, work, SMapWork, labels[0]), 255, 0, 0, 0, 3);
            sdkSpriteFreeNode(resource);
            pos = fclMakeVec2(104.0f, 406.0f);
            resource = sdkSpriteNewNode(D_00764644, 13);
            fclSpriteStartRevealScaleTask(((SMapWork *)work)->labels[1], 1.0f, 1.0f, 1.0f, 0.1f, 0, 3, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartPositionTask(MEMBER(u8 *, work, SMapWork, labels[1]), pos,
                fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(resource) / 2.0f), 0, 3, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartAlphaTask(MEMBER(u8 *, work, SMapWork, labels[1]), 255, 0, 0, 0, 3);
            sdkSpriteFreeNode(resource);
        }
    } else {
        u8 *resource;
        ((SMapWork *)work)->phase = 3;
        ((SMapWork *)work)->mode = 1;
        {
            YVec2f pos = fclMakeVec2(15.0f, 406.0f);
            resource = sdkSpriteNewNode(D_00764644, 12);
            fclSpriteActivateTask(((SMapWork *)work)->labels[0], pos, 0x4D, 60008);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartRevealScaleTask(MEMBER(u8 *, work, SMapWork, labels[0]), 1.0f, 1.0f, 0.1f, 1.0f, 0, 5, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartPositionTask(MEMBER(u8 *, work, SMapWork, labels[0]),
                fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(resource) / 2.0f), pos, 0, 5, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartAlphaTask(MEMBER(u8 *, work, SMapWork, labels[0]), 0, 255, 0, 0, 0);
            sdkSpriteFreeNode(resource);
            pos = fclMakeVec2(104.0f, 406.0f);
            resource = sdkSpriteNewNode(D_00764644, 13);
            fclSpriteActivateTask(((SMapWork *)work)->labels[1], pos, 0x4D, 60008);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartRevealScaleTask(MEMBER(u8 *, work, SMapWork, labels[1]), 1.0f, 1.0f, 0.1f, 1.0f, 0, 5, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartPositionTask(MEMBER(u8 *, work, SMapWork, labels[1]),
                fclMakeVec2(pos.x, pos.y + sdkSpriteScaledHeight(resource) / 2.0f), pos, 0, 5, 0);
            /* measured: direct, typed-local and array member forms change retail instructions. */
            fclSpriteStartAlphaTask(MEMBER(u8 *, work, SMapWork, labels[1]), 0, 255, 0, 0, 0);
            sdkSpriteFreeNode(resource);
        }
        for (visibleRow = 0; visibleRow < 24; visibleRow++) {
            for (column = 0; column < 16; column++) {
                u8 **slot = &((SMapWork *)work)->cells[visibleRow][column];
                if (kwlnTaskIsLinked(*slot) == 1) {
                    if ((((u16)(1 << column) & ((u16 *)D_00764658)[visibleRow]) >> column) == 1)
                        smapSetVisible(*slot, 1);
                    smapSetPosition(*slot, fclMakeVec2(18.0f * visibleRow, 18.0f * column));
                }
            }
        }
    }
}
#pragma pop

/* Select the ten-frame opening or five-frame closing phase and restart its transition counter. */
// FUN_002AFB70
void smapSetPhase(u8 *task, s8 mode) {
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (mode == 0) {
        ((SMapWork *)work)->phase = 5;
    } else if (mode == 1) {
        ((SMapWork *)work)->phase = 6;
    }
    ((SMapWork *)work)->transitionFrame = 0;
}



/* The cell constructor allocates 0x160 bytes. The renderer owns the
 * position, visibility and icon fields below; the four queued vertices
 * occupy the existing 0x100-byte region beginning at 0x40. */
typedef struct SMapCell {
    void *self;
    u8 type;
    s8 variant;
    u8 reserved06[2];
    YVec2f position;
    YVec2f offset;
    u8 origin;
    u8 reserved19[3];
    f32 textureBounds[4];
    f32 width;
    f32 height;
    f32 scale;
    f32 reciprocalZ;
    u8 reserved3C[4];
    FldFilterVertex renderVertices[4];
    u8 column;
    u8 row;
    s8 orientation;
    s8 visible;
    s8 mode;
    u8 reserved145[7];
    s8 hasIcon;
    u8 reserved14D[3];
    YVec2f iconOffset;
    s8 visibilityColumnOffset;
    s8 visibilityRowOffset;
    s8 pendingDraw;
    u8 reserved15B[5];
} SMapCell;
typedef char SMapCellStorageSize[(sizeof(SMapCell) == 0x160) ? 1 : -1];

/* Draw a visible map cell and its optional icon in scrolling or fixed mode.
 * The scrolling draw request is consumed after rendering. Native b210 -O2:
 * 1624/1632 bytes with all 28 relocations resolved and eight zero tail bytes.
 * See docs/probe_archive/Small_map_cell_002afbc0_20260924.md. */
// FUN_002AFBC0
s32 smapDrawCell(u8 *taskObject) {
    u8 *task;
    SMapCell *cell;
    s32 color;
    s32 visibilityRow;
    s32 visibilityColumn;
    YVec2f origin[2];
    s32 showIcon;
    task = taskObject;
    cell = (SMapCell *)((KwlnTask *)taskObject)->work;
    color = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
    fclAnchorOffset((f32 *)&origin[0], 0, 126.0f, 126.0f, 21.0f, 22.0f);
    origin[1] = origin[0];
    if (D_0076464C == 0) {
        return 0;
    }
    if (datGetFlag(0x1417) != 0) {
        return 0;
    }
    if (cell->mode == 0) {
        if (datGetFlag(0x1416) == 0) {
            if (cell->visible == 0) {
                return 0;
            }
        }
        if (cell->pendingDraw == 0) {
            return 0;
        }
        cell->position.x = 7.0f + 18.0f * (f32)(u32)cell->column + origin[1].x - (f32)(D_00764660 * 18) + 15.0f + cell->offset.x - 10.0f;
        cell->position.y = 227.0f + 18.0f * (f32)(u32)cell->row + origin[1].y - (f32)(D_0076465C * 18) + 15.0f + cell->offset.y + 16.0f;
        if (cell->hasIcon == 1) {
            visibilityRow = ((((FldFrame *)MT_Scene_GetFrameState())->cellPick[1] + cell->visibilityRowOffset) & 0xFF);
            visibilityColumn = ((((FldFrame *)MT_Scene_GetFrameState())->cellPick[0] + cell->visibilityColumnOffset) & 0xFF);
            if (datGetFlag(0x1416) == 0) {
                showIcon = (s8)(((1 << (visibilityColumn & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[visibilityRow & 0xFF]) >> (visibilityColumn & 0xFF));
            } else {
                showIcon = 1;
            }
            if ((s8)showIcon == 1) {
                sdkSpriteDrawQueued(cell->position.x + cell->iconOffset.x, cell->position.y + cell->iconOffset.y, 60007.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (void *)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
        smapDrawQuad(task, cell->position, cell->width, cell->height, 60008.0f, cell->origin, cell->scale, color, cell->orientation, 0x50);
        cell->pendingDraw = 0;
    } else if (cell->mode == 1) {
        if (datGetFlag(0x1416) == 0) {
            if (cell->visible == 0) {
                return 0;
            }
        }
        cell->position.x = 172.0f + 18.0f * (f32)(u32)cell->column;
        cell->position.y = 9.0f + 18.0f * (f32)(u32)cell->row;
        if (cell->hasIcon == 1) {
            visibilityRow = ((((FldFrame *)MT_Scene_GetFrameState())->cellPick[1] + cell->visibilityRowOffset) & 0xFF);
            visibilityColumn = ((((FldFrame *)MT_Scene_GetFrameState())->cellPick[0] + cell->visibilityColumnOffset) & 0xFF);
            if (datGetFlag(0x1416) == 0) {
                showIcon = (s8)(((1 << (visibilityColumn & 0xFF)) & 0xFFFF & ((u16 *)D_00764658)[visibilityRow & 0xFF]) >> (visibilityColumn & 0xFF));
            } else {
                showIcon = 1;
            }
            if ((s8)showIcon == 1) {
                sdkSpriteDrawQueued(cell->position.x + cell->iconOffset.x, cell->position.y + cell->iconOffset.y, 60007.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0x13, (void *)D_00764644, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
        smapDrawQuad(task, cell->position, cell->width, cell->height, 60008.0f, cell->origin, cell->scale, color, cell->orientation, 0x4C);
    }
    return 0;
}

// FUN_002B0220
void smapTaskDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}


#pragma push


/* func_002b0250: `arg3 == -1` is a u8 compared with -1 (retail keeps the never-true test). The 9..14
   dispatch is a real switch inside `if (arg3 >= 9)`; 7..8, 2 and the default arm are the if/else chain
   that follows. arg4 is u8 (andi, not a sign extension). opt_loop_invariants on hoists the per-row
   (arg7 + i) << 8 out of the tile scan's inner loop as retail does (measured: 8 -> 3 differing words;
   writing `j = 0` before the row offset, as retail emits it, then gives 0). */
/* Create a tile from its cell type and variant; cache texture bounds and optional room-icon offsets. */
// FUN_002B0250
#pragma push
#pragma opt_loop_invariants on
/* measured: byte arguments and named anchor-coordinate snapshots; best baseline residual 6 differing bytes. */
u8 *smapBuildTiles(u8 *parent, u8 column, u8 row, u8 cellType, u8 variant, u8 origin, u8 anchorColumn, u8 anchorRow) {
    SMapCell *tile;
    u8 anchor[8];
    u8 *task;
    u8 *cell;
    s16 rowStep;
    s16 columnStep;
    s32 rowOfs;
    s8 kind;
    u8 *map;
    fclAnchorOffset((f32 *)anchor, 0, 126.0f, 126.0f, 21.0f, 22.0f);
    if (cellType == -1) {
        return NULL;
    }
    chkmemAllocSiteTag(D_0063EF60, 0x5C4);
    cell = D_008873F4[0](1, 0x160, 0x40000);
    tile = (SMapCell *)cell;
    task = (u8 *)(s32)kwlnTaskCreateChild((void *)((s32)parent), (const void *)(D_0063EFD8), 0xF, 0, 0, smapDrawCell, smapTaskDestroy, cell);
    ((SMapCell *)cell)->self = cell;
    ((SMapCell *)cell)->type = cellType;
    ((SMapCell *)cell)->variant = variant;
    ((SMapCell *)cell)->origin = origin;
    ((SMapCell *)cell)->scale = 1.0f;
    ((SMapCell *)cell)->column = column;
    ((SMapCell *)cell)->row = row;
    ((SMapCell *)cell)->orientation = 0;
    ((SMapCell *)cell)->visible = 0;
    ((SMapCell *)cell)->mode = 0;
    ((SMapCell *)cell)->offset.y = 0.0f;
    ((SMapCell *)cell)->offset.x = 0.0f;
    if (cellType >= 9) {
        switch (cellType) {
        case 9:
        case 10:
            if (variant == 1) {
                ((SMapCell *)cell)->textureBounds[3] = 0.03125f;
                ((SMapCell *)cell)->textureBounds[2] = 0.03125f;
                ((SMapCell *)cell)->textureBounds[1] = 0.59375f;
                ((SMapCell *)cell)->textureBounds[0] = 0.59375f;
                ((SMapCell *)cell)->height = 19.0f;
                ((SMapCell *)cell)->width = 19.0f;
            } else if (variant == 2) {
                ((SMapCell *)cell)->textureBounds[2] = 0.296875f;
                ((SMapCell *)cell)->textureBounds[3] = 0.015625f;
                ((SMapCell *)cell)->textureBounds[0] = tile->textureBounds[2] + 0.578125f;
                ((SMapCell *)cell)->textureBounds[1] = ((SMapCell *)cell)->textureBounds[3] + 0.578125f;
                ((SMapCell *)cell)->height = 37.0f;
                ((SMapCell *)cell)->width = 37.0f;
            }
            break;
        case 11:
        case 12:
            if (variant == 1) {
                ((SMapCell *)cell)->textureBounds[3] = 0.015625f;
                ((SMapCell *)cell)->textureBounds[2] = 0.015625f;
                ((SMapCell *)cell)->textureBounds[0] = 0.296875f;
                ((SMapCell *)cell)->textureBounds[1] = 0.859375f;
                ((SMapCell *)cell)->width = 19.0f;
                ((SMapCell *)cell)->height = 55.0f;
                tile->orientation = 1;
            } else if (variant == 2) {
                ((SMapCell *)cell)->textureBounds[2] = 0.296875f;
                ((SMapCell *)cell)->textureBounds[3] = 0.015625f;
                ((SMapCell *)cell)->textureBounds[0] = tile->textureBounds[2] + 0.578125f;
                ((SMapCell *)cell)->textureBounds[1] = ((SMapCell *)cell)->textureBounds[3] + 0.578125f;
                ((SMapCell *)cell)->height = 37.0f;
                ((SMapCell *)cell)->width = 37.0f;
            }
            break;
        case 13:
        case 14:
            if (variant == 1 || variant == 3) {
                ((SMapCell *)cell)->textureBounds[3] = 0.03125f;
                ((SMapCell *)cell)->textureBounds[2] = 0.03125f;
                ((SMapCell *)cell)->textureBounds[1] = 0.59375f;
                ((SMapCell *)cell)->textureBounds[0] = 0.59375f;
                ((SMapCell *)cell)->height = 19.0f;
                ((SMapCell *)cell)->width = 19.0f;
            } else if (variant == 2) {
                ((SMapCell *)cell)->textureBounds[2] = 0.296875f;
                ((SMapCell *)cell)->textureBounds[3] = 0.296875f;
                ((SMapCell *)cell)->textureBounds[0] = 0.859375f;
                ((SMapCell *)cell)->textureBounds[1] = 0.859375f;
                ((SMapCell *)cell)->height = 37.0f;
                ((SMapCell *)cell)->width = 37.0f;
            }
            break;
        }
    } else if (cellType >= 7) {
        ((SMapCell *)cell)->textureBounds[2] = 0.015625f;
        ((SMapCell *)cell)->textureBounds[3] = 0.015625f;
        ((SMapCell *)cell)->textureBounds[1] = 0.578125f;
        ((SMapCell *)cell)->textureBounds[0] = 0.578125f;
        ((SMapCell *)cell)->height = 37.0f;
        ((SMapCell *)cell)->width = 37.0f;
    } else if (cellType == 2) {
        if (variant == 1) {
            ((SMapCell *)cell)->textureBounds[2] = 0.015625f;
            ((SMapCell *)cell)->textureBounds[3] = 0.015625f;
            ((SMapCell *)cell)->textureBounds[0] = 0.578125f;
            ((SMapCell *)cell)->textureBounds[1] = 0.578125f;
            ((SMapCell *)cell)->width = 37.0f;
            ((SMapCell *)cell)->height = 37.0f;
            if (origin == 2 || origin == 1) {
                tile->orientation = 2;
            }
        } else if (variant == 2) {
            ((SMapCell *)cell)->textureBounds[3] = 0.296875f;
            ((SMapCell *)cell)->textureBounds[2] = 0.296875f;
            ((SMapCell *)cell)->textureBounds[1] = 0.578125f;
            ((SMapCell *)cell)->textureBounds[0] = 0.578125f;
            ((SMapCell *)cell)->height = 19.0f;
            ((SMapCell *)cell)->width = 19.0f;
        }
    } else {
        ((SMapCell *)cell)->textureBounds[2] = 0.03125f;
        ((SMapCell *)cell)->textureBounds[3] = 0.03125f;
        ((SMapCell *)cell)->textureBounds[1] = 0.59375f;
        ((SMapCell *)cell)->textureBounds[0] = 0.59375f;
        ((SMapCell *)cell)->height = 19.0f;
        ((SMapCell *)cell)->width = 19.0f;
    }
    ((SMapCell *)cell)->hasIcon = 0;
    if (variant == 2 && anchorColumn == ((FldFrame *)MT_Scene_GetFrameState())->cellPick[0] && anchorRow == ((FldFrame *)MT_Scene_GetFrameState())->cellPick[1]) {
        for (rowStep = 0; rowStep < 2; rowStep++) {
            columnStep = 0;
            rowOfs = (anchorRow + rowStep) << 8;
            for (; columnStep < 2; columnStep++) {
                map = MT_Scene_GetFrameState();
                kind = ((FldFrameCell *)(rowOfs + (u32)map + (anchorColumn + columnStep) * 0x10 + MEMBER_OFFSET(FldFrame, cells)))->flags >> 4;
                if (kind == 2) {
                    ((SMapCell *)cell)->iconOffset.x = 9.0f;
                    ((SMapCell *)cell)->iconOffset.y = 9.0f;
                    ((SMapCell *)cell)->visibilityColumnOffset = (u8)columnStep;
                    ((SMapCell *)cell)->visibilityRowOffset = (u8)rowStep;
                    tile->hasIcon = 1;
                    return task;
                }
            }
        }
    }
    return task;
}
#pragma pop

/* Set cell texture coordinates and bind the texture selected by its type and variant. */
// FUN_002B07A0
void smapDrawLabel(u8 *unused, u8 *cell) {
    SMapCell *tile = (SMapCell *)cell;
    u8 *renderStates;
    u8 textureName[0x80];
    u8 cellType;

    renderStates = (u8 *)D_00887300;
    ((void (**)(s32, s32))renderStates)[0](6, 1);
    ((void (**)(s32, s32))renderStates)[0](7, 2);
    ((void (**)(s32, s32))renderStates)[0](8, 1);
    ((void (**)(s32, s32))renderStates)[0](9, 2);
    ((void (**)(s32, s32))renderStates)[0](0xC, 1);
    ((void (**)(s32, s32))renderStates)[0](2, 3);
    ((void (**)(s32, s32))renderStates)[0](0xB, 6);
    ((void (**)(s32, s32))renderStates)[0](0xA, 5);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    if ((u8)((SMapCell *)cell)->variant == 3) {
        ((SMapCell *)cell)->renderVertices[0].u = ((SMapCell *)cell)->textureBounds[2];
        ((SMapCell *)cell)->renderVertices[0].v = ((SMapCell *)cell)->textureBounds[1];
        ((SMapCell *)cell)->renderVertices[1].u = ((SMapCell *)cell)->textureBounds[2];
        ((SMapCell *)cell)->renderVertices[1].v = ((SMapCell *)cell)->textureBounds[3];
        ((SMapCell *)cell)->renderVertices[2].u = ((SMapCell *)cell)->textureBounds[0];
        ((SMapCell *)cell)->renderVertices[2].v = ((SMapCell *)cell)->textureBounds[1];
        ((SMapCell *)cell)->renderVertices[3].u = ((SMapCell *)cell)->textureBounds[0];
        ((SMapCell *)cell)->renderVertices[3].v = ((SMapCell *)cell)->textureBounds[3];
    } else {
        ((SMapCell *)cell)->renderVertices[0].u = ((SMapCell *)cell)->textureBounds[2];
        ((SMapCell *)cell)->renderVertices[0].v = ((SMapCell *)cell)->textureBounds[3];
        ((SMapCell *)cell)->renderVertices[1].u = ((SMapCell *)cell)->textureBounds[0];
        ((SMapCell *)cell)->renderVertices[1].v = ((SMapCell *)cell)->textureBounds[3];
        ((SMapCell *)cell)->renderVertices[2].u = ((SMapCell *)cell)->textureBounds[2];
        ((SMapCell *)cell)->renderVertices[2].v = ((SMapCell *)cell)->textureBounds[1];
        ((SMapCell *)cell)->renderVertices[3].u = ((SMapCell *)cell)->textureBounds[0];
        ((SMapCell *)cell)->renderVertices[3].v = ((SMapCell *)cell)->textureBounds[1];
    }
    cellType = ((SMapCell *)cell)->type;
    if (cellType >= 9) {
        if ((u8)tile->variant == 1) {
            switch (cellType) {
            case 9:
            case 10:
                sprintf(textureName, D_0063EFF0, cellType);
                break;
            case 11:
            case 12:
                sprintf(textureName, D_0063F010, cellType);
                break;
            case 13:
            case 14:
                sprintf(textureName, D_0063EFF0, cellType);
                break;
            }
        /* measured: direct, typed-local and array member forms change retail instructions. */
        } else if (MEMBER(u8, cell, SMapCell, variant) == 3) {
            sprintf(textureName, D_0063EFF0, cellType);
        } else {
            switch (cellType) {
            case 9:
            case 10:
                sprintf(textureName, D_0063F030, cellType);
                break;
            case 11:
            case 12:
                sprintf(textureName, D_0063F050, cellType);
                break;
            case 13:
            case 14:
                sprintf(textureName, D_0063F070, cellType);
                break;
            }
        }
    } else if (cellType == 2) {
        if ((u8)tile->variant == 1) {
            sprintf(textureName, D_0063F090, cellType);
        } else {
            sprintf(textureName, D_0063F0B0, cellType);
        }
    } else {
        sprintf(textureName, D_0063F0D0, cellType);
    }
    ((void (**)(s32, s32))renderStates)[0](1, *(s32 *)func_003ef650(func_003ef6d0(), textureName));
}

extern u8 D_00793E80[];

#pragma push
#pragma opt_loop_invariants on
/* Four map-cell corners are stored as complete X/Y/Z vectors, then copied
 * into the existing 0x40-byte screen-vertex records. Unsigned color conversion
 * and the render-device depth field preserve the original invariant placement.
 * Native b210 -O2: 1412/1424 bytes; all relocations and twelve zero tail bytes.
 * See docs/probe_archive/Map_shape_002b0b10_20260924.md. */
// FUN_002B0B10
/* measured: direct and named render-device depth source; best baseline residual 349 differing bytes. */
void smapDrawQuad(u8 *task, YVec2f position, f32 width, f32 height, f32 depth, u8 origin, f32 scale, s32 color, s8 orientation, s32 layer) {
    YVec3f corners[4];
    typedef struct SMapRenderDevice {
        f32 gamma;
        s32 (*system)(s32, void *, void *, s32);
        f32 nearDepth;
        f32 farDepth;
        s32 (*setState)(s32, void *);
        s32 (*getState)(s32, void *);
        u32 renderCallbacks[8];
    } SMapRenderDevice;
    extern SMapRenderDevice D_008872F0;
    f32 reciprocalZ;
    f32 scaledWidth;
    f32 scaledHeight;
    f32 baseY;
    u8 *cell;
    s32 cornerMode;
    cell = ((KwlnTask *)task)->work;
    reciprocalZ = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    ((SMapCell *)cell)->reciprocalZ = reciprocalZ;
    scaledWidth = width * scale;
    scaledHeight = height * scale;
    cornerMode = origin & 0xFF;
    baseY = position.y;
    switch (cornerMode) {
    case 0:
        corners[0].x = position.x;
        corners[0].y = 0.0f;
        corners[0].z = baseY;
        corners[1].x = position.x + scaledWidth;
        corners[1].y = 0.0f;
        corners[1].z = baseY;
        corners[2].x = position.x;
        corners[2].y = 0.0f;
        corners[2].z = baseY + scaledHeight;
        corners[3].x = position.x + scaledWidth;
        corners[3].y = 0.0f;
        corners[3].z = baseY + scaledHeight;
        break;
    case 1: {
        s32 v = orientation;
        if (v == 0) {
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY + scaledHeight;
            corners[3].x = position.x + scaledWidth;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
        } else if (v == 1) {
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledWidth;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY;
            corners[2].x = position.x + scaledHeight;
            corners[2].y = 0.0f;
            corners[2].z = baseY + scaledWidth;
            corners[3].x = position.x + scaledHeight;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
        } else if (v == 2) {
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY - 18.0f;
            corners[3].x = (position.x + scaledWidth);
            corners[3].y = 0.0f;
            corners[3].z = baseY - 18.0f;
            corners[0].x = position.x;
            corners[0].y = 0.0f;
            corners[0].z = (baseY + scaledHeight) - 18.0f;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = (baseY + scaledHeight) - 18.0f;
        }
        break;
    }
    case 2: {
        s32 v = orientation;
        if (v == 0) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        } else if (v == 1) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = position.x + scaledWidth;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        } else if (v == 2) {
            corners[3].x = position.x - 18.0f;
            corners[3].y = 0.0f;
            corners[3].z = baseY;
            corners[2].x = (position.x + scaledWidth) - 18.0f;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x - 18.0f;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
            corners[0].x = (position.x + scaledWidth) - 18.0f;
            corners[0].y = 0.0f;
            corners[0].z = baseY + scaledHeight;
        }
        break;
    }
    case 3: {
        s32 v = orientation;
        if (v == 0) {
            corners[2].x = position.x;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[0].x = position.x + scaledWidth;
            corners[0].y = 0.0f;
            corners[0].z = baseY;
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY + scaledHeight;
            corners[1].x = position.x + scaledWidth;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledHeight;
        } else if (v == 1) {
            corners[3].x = position.x;
            corners[3].y = 0.0f;
            corners[3].z = baseY + scaledWidth;
            corners[2].x = position.x;
            corners[2].y = 0.0f;
            corners[2].z = baseY;
            corners[1].x = position.x + scaledHeight;
            corners[1].y = 0.0f;
            corners[1].z = baseY + scaledWidth;
            corners[0].x = position.x + scaledHeight;
            corners[0].y = 0.0f;
            corners[0].z = baseY;
        }
        break;
    }
    }
    {
        u32 red;
        u32 green;
        u32 blue;
        u32 alpha;
        s32 i;
        red = ((u32)(color & 0xFF000000) >> 24) & 0xFF;
        green = ((u32)(color & 0xFF0000) >> 16) & 0xFF;
        blue = ((u32)(color & 0xFF00) >> 8) & 0xFF;
        alpha = color & 0xFF;
        i = 0;
        while (i < 4) {
            u8 *record = cell + (i << 6);
            YVec3f *point;
            ((FldFilterVertex *)(record + 0x40))->z = D_008872F0.nearDepth - depth;
            ((FldFilterVertex *)(record + 0x40))->reciprocalDepth = reciprocalZ;
            ((FldFilterVertex *)(record + 0x40))->red = (f32)red;
            ((FldFilterVertex *)(record + 0x40))->green = (f32)green;
            ((FldFilterVertex *)(record + 0x40))->blue = (f32)blue;
            ((FldFilterVertex *)(record + 0x40))->alpha = (f32)alpha;
            point = &corners[i];
            ((FldFilterVertex *)(record + 0x40))->x = point->x;
            ((FldFilterVertex *)(record + 0x40))->y = point->z;
            i++;
        }
    }
    {
        u8 *packet = (u8 *)PrimQueueDrawPrimitive((u8 *)&D_00793E80 + ((s16)layer * 0x30), 4, cell + 0x40, 4);
        ((PrimQueueNode *)packet)->callback = smapDrawLabel;
        ((PrimQueueNode *)packet)->argument.data = cell;
    }
}
#pragma pop


/* Store the cell scroll offset and request one draw in scrolling-map mode. */
// FUN_002B10A0
void smapSetPosition(u8 *task, YVec2f offset) {
    u8 *cell = ((KwlnTask *)task)->work;

    ((SMapCell *)cell)->offset = offset;
    ((SMapCell *)cell)->pendingDraw = 1;
}

// FUN_002B10D0
void smapSetActive(u8 *task, s8 pendingDraw) {
    ((SMapCell *)((KwlnTask *)task)->work)->pendingDraw = pendingDraw;
}

// Intent: sets the visibility flag (+0x143) of a smap symbol; a tile is shown when its mask bit in D_00764658 is set.
// FUN_002B10E0
void smapSetVisible(u8 *task, s8 visible) {
    ((SMapCell *)((KwlnTask *)task)->work)->visible = visible;
}

// FUN_002B10F0
void smapSetCellMode(u8 *task, s8 mode) {
    ((SMapCell *)((KwlnTask *)task)->work)->mode = mode;
}
// FUN_002B1100
void smapCellToWorld(void *output,u32 column,u32 row)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 1200.0f * (float)column;
  vector.z = 1200.0f * (float)row;
  *(YVec3f *)output = vector;
}

#pragma pop


#pragma push


/* Return-width audit: retail callers of func_002b11c0 and func_002b1210
   consume the result directly with andi, sb, or mtc1 and emit no
   dsll32/dsra32 sign-extension pair. Keep both returns wide (int): changing
   either to s8 introduces the pair and regresses the caller by two words.
   A missing pair means a callee return was declared too wide; an extra pair
   means it was declared too narrow. */
// FUN_002B11C0
int smapWorldToColumn(RwV3d position)

{
  return (int)((position.x + 600.0f) / 1200.0f);
}

#pragma pop


#pragma push


// FUN_002B1210
int smapWorldToRow(RwV3d position)

{
  return (int)((position.z + 600.0f) / 1200.0f);
}

#pragma pop

/* measured: re-tested wave 4 (nd 11, was recorded nd 1). The lwc1-copy
   shape is the u8 buf[0xC] + `v2 = *(YVec3f *)buf` spelling (local-to-local
   struct copies compile to ld/sd, pointer/buf-source copies to lwc1 x3);
   with that copy the mul.s $f1,$f2,$f0 (const-in-fs) MATCHES retail — the
   old note's "mul canonicalization floor" is wrong. The residual is the
   p-load: retail lwc1 0x40($sp) sits after sub.s $f1,$f1,$f0, mwcc b210
   hoists it into the post-cvt nop slot (obj 188B vs window 192B), which
   also rotates the two subs (sub.s $f0,$f1,$f0 / sub.s $f3,$f3,$f0 vs
   retail $f1/$f0). Tried 6 orderings (q-before-p, k-split, x-local,
   reversed decls, buf-indexed read, computed ptr) — all nd 11-38.
   Load-hoist/schedule floor. */
/* Convert the player position within a 1200-unit grid column to a centered map-pixel offset. */
// FUN_002B1260
f32 smapPlayerOffsetX(u8 *task, f32 cellSize) {
    YVec3f position;
    u8 positionBuffer[0xC];
    f32 column, relativeX, scale;

    FldFrameTask_GetPosition(positionBuffer, task);
    position = *(YVec3f *)positionBuffer;
    column = (s32)FldFrameTask_GetTileX(task);
    relativeX = column * 1200.0f;
    relativeX -= 600.0f;
    relativeX = position.x - relativeX;
    scale = cellSize / 1200.0f;
    return cellSize / 2.0f - relativeX * scale;
}

/* measured: re-tested wave 4 (nd 11, was recorded nd 1) — same result as
   func_002b1260: u8 buf[0xC] + `v2 = *(YVec3f *)buf` reproduces the lwc1
   copy and the mul.s $f1,$f2,$f0 (const-in-fs) matches retail; the residual
   is mwcc b210 hoisting the p-load (lwc1 0x48($sp)) into the FP-latency
   nop (obj 188B vs window 192B) with the two sub.s registers rotated
   ($f0/$f3 vs retail $f1/$f0). Self-referential t = t*1200.0f sinks the
   load to mid-chain but flips const to $f4/result $f2 (nd 10); const-first
   and named-m variants stay nd 11. Load-hoist/schedule floor, same as
   func_002b1260. */
/* Convert the player position within a 1200-unit grid row to a centered map-pixel offset. */
// FUN_002B1320
f32 smapPlayerOffsetZ(u8 *task, f32 cellSize) {
    YVec3f position;
    u8 positionBuffer[0xC];
    f32 row, relativeZ, scale;

    FldFrameTask_GetPosition(positionBuffer, task);
    position = *(YVec3f *)positionBuffer;
    row = (s32)FldFrameTask_GetTileZ(task);
    relativeZ = row * 1200.0f;
    relativeZ -= 600.0f;
    relativeZ = position.z - relativeZ;
    scale = cellSize / 1200.0f;
    return cellSize / 2.0f - relativeZ * scale;
}
/* Convert a world X coordinate within its grid cell to a centered map-pixel offset. */
// FUN_002B13E0
f32 smapPositionOffsetX(f32 cellSize, YVec3f *position) {
    YVec3f positionCopy, cellPosition;
    f32 column, relativeX, scale;

    positionCopy = *position;
    cellPosition = positionCopy;
    column = (s32)((cellPosition.x + 600.0f) / 1200.0f);
    relativeX = positionCopy.x - (column * 1200.0f - 600.0f);
    scale = cellSize / 1200.0f;
    return cellSize / 2.0f - relativeX * scale;
}

/* Convert a world Z coordinate within its grid cell to a centered map-pixel offset. */
// FUN_002B1480
f32 smapPositionOffsetZ(f32 cellSize, YVec3f *position) {
    YVec3f offsetPosition, cellPosition, positionCopy;
    f32 row, relativeZ, scale;

    positionCopy = *position;
    offsetPosition = positionCopy;
    cellPosition = positionCopy;
    row = (s32)((cellPosition.z + 600.0f) / 1200.0f);
    relativeZ = offsetPosition.z - (row * 1200.0f - 600.0f);
    scale = cellSize / 1200.0f;
    return cellSize / 2.0f - relativeZ * scale;
}

/* MATCH: 3356B of the 3360B retail window, including resolved relocations and
   owned data. The final sprite loop uses a size_t slot index beside its signed
   16-bit counter; these separate conversions reproduce retail's index lifetime.
   The float->byte guards are plain casts here (`(u8)t4n`, `(u16)sa`; b210 emits the
   c.le.s/or 0x80000000 unsigned conversion itself), the fill/clear loops are ordinary `for` loops with the
   entry branch to the test (not do-while), the 255.0f-t and 4096.0f*a results go to fresh locals (t3n/t4n/sa:
   reusing t3/t4/a picks different $f registers and mul operand order), a is declared before b (retail $f21/$f20),
   `i1 = 0` and `k = 0` are written before the value they precede in retail (`i1 = 0; t4n = ...`), and the two
   ld/sd prologue copies write sp+8 from iGpffffa840 then sp+0 from iGpffffa848.
   opt_loop_invariants on hoists the guard compare/lui out of the loops. */
/* Animate the map frame and strip sprites between scrolling and fixed-map panel layouts. */
// FUN_002B1520
#pragma push
#pragma opt_loop_invariants on
/* measured: access-site fields and existing typed map alias; best baseline residual 2089 differing bytes. */
void smapDrawPanel(s32 unused, u8 *work) {
    SMapWork *map = (SMapWork *)work;
    u32 renderStates;
    u8 panelPositions[0x10];
    f32 scale;
    f32 frameWidth;
    f32 frameBottom;
    f32 fixedScale;
    s16 fadeStrip;
    s16 fadeSprite;
    s16 drawStrip;
    s16 drawSprite;
    s16 revealStrip;
    s16 revealSprite;
    s16 fixedStrip;
    s16 fixedSprite;
    s16 cornerIndex;
    (void)unused;
    scale = 1.0f;
    ((SMapPanelPositions *)panelPositions)->points[1].bits = iGpffffa840;
    ((SMapPanelPositions *)panelPositions)->points[0].bits = iGpffffa848;
    frameWidth = 120.0f;
    frameBottom = (f32)395;
    renderStates = (u32)D_00887300;
    ((void (*)(s32, s32))*(u32 *)renderStates)(6, 1);
    ((void (*)(s32, s32))*(u32 *)renderStates)(7, 2);
    ((void (*)(s32, s32))*(u32 *)renderStates)(8, 1);
    ((void (*)(s32, s32))*(u32 *)renderStates)(9, 2);
    ((void (*)(s32, s32))*(u32 *)renderStates)(0xC, 1);
    ((void (*)(s32, s32))*(u32 *)renderStates)(0xB, 6);
    ((void (*)(s32, s32))*(u32 *)renderStates)(0xA, 5);
    ((void (*)(s32, s32))*(u32 *)renderStates)(2, 4);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
    switch ((s8)((SMapWork *)work)->phase) {
    case 0:
    case 1:
        break;
    case 2: {
        f32 t1;
        f32 t2;
        f32 t3;
        f32 t4;
        f32 t3n;
        f32 t4n;
        u8 bv;
        t1 = fclEaseInterpolate(0, 179.0f, 312.0f, (f32)((SMapWork *)work)->transitionFrame, 10.0f);
        t2 = fclEaseInterpolate(0, (f32)443, 312.0f, (f32)map->transitionFrame, 10.0f);
        t3 = fclEaseInterpolate(0, 255.0f, 0.0f, (f32)map->transitionFrame, 10.0f);
        t4 = fclEaseInterpolate(0, 255.0f, 0.0f, (f32)((SMapWork *)work)->labelFrame, 5.0f);
        ((SMapItem *)(((SMapWork *)work)->ends[0]))->x = t1;
        ((SMapItem *)(((SMapWork *)work)->ends[1]))->x = t2;
        t3n = 255.0f - t3;
        bv = (u8)t3n;
        ((SMapItem *)((u8 *)map->ends[1]))->alphaSubtract = bv;
        ((SMapItem *)((u8 *)map->ends[0]))->alphaSubtract = bv;
        fadeStrip = 0;
        t4n = 255.0f - t4;
        for (; fadeStrip < 3; fadeStrip++) {
            for (fadeSprite = 0; fadeSprite < 6; fadeSprite++) {
                u8 vv;
                vv = (u8)t4n;
                ((SMapItem *)(((SMapWork *)work)->strips[(s32)fadeStrip][(s32)fadeSprite]))->alphaSubtract = vv;
            }
        }
        sdkSpriteDraw((u8 *)map->ends[0], 0);
        sdkSpriteDraw((u8 *)map->ends[1], 0);
        for (drawStrip = 0; drawStrip < 3; drawStrip++) {
            for (drawSprite = 0; drawSprite < 6; drawSprite++) {
                sdkSpriteDraw((u8 *)((SMapWork *)work)->strips[(s32)drawStrip][(s32)drawSprite], 0);
            }
        }
        ((SMapPanelPositions *)panelPositions)->points[1].position.y = fclEaseInterpolate(0, (f32)327, 264.0f, (f32)map->transitionFrame, 10.0f);
        ((SMapPanelPositions *)panelPositions)->points[0].position.y = fclEaseInterpolate(0, (f32)327, (f32)341, (f32)map->transitionFrame, 10.0f);
        scale = fclEaseInterpolate(0, iGpffff84f4, 1.0f, (f32)map->transitionFrame, 10.0f);
        frameWidth = fclEaseInterpolate(0, 183.0f, 120.0f, (f32)map->transitionFrame, 10.0f);
        frameBottom = fclEaseInterpolate(0, 332.0f, (f32)395, (f32)map->transitionFrame, 10.0f);
        break;
    }
    case 3: {
        f32 t1;
        f32 t2;
        f32 t3;
        f32 t4;
        f32 t3n;
        f32 t4n;
        u8 bv;
        t1 = fclEaseInterpolate(0, 312.0f, 179.0f, (f32)((SMapWork *)work)->transitionFrame, 5.0f);
        t2 = fclEaseInterpolate(0, 312.0f, (f32)443, (f32)map->transitionFrame, 5.0f);
        t3 = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)map->transitionFrame, 5.0f);
        t4 = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((SMapWork *)work)->labelFrame, 5.0f);
        ((SMapItem *)(((SMapWork *)work)->ends[0]))->x = t1;
        ((SMapItem *)(((SMapWork *)work)->ends[1]))->x = t2;
        t3n = 255.0f - t3;
        bv = (u8)t3n;
        ((SMapItem *)((u8 *)map->ends[1]))->alphaSubtract = bv;
        ((SMapItem *)((u8 *)map->ends[0]))->alphaSubtract = bv;
        revealStrip = 0;
        t4n = 255.0f - t4;
        for (; revealStrip < 3; revealStrip++) {
            for (revealSprite = 0; revealSprite < 6; revealSprite++) {
                u8 vv;
                vv = (u8)t4n;
                ((SMapItem *)(((SMapWork *)work)->strips[(s32)revealStrip][(s32)revealSprite]))->alphaSubtract = vv;
            }
        }
        ((SMapPanelPositions *)panelPositions)->points[1].position.y = fclEaseInterpolate(0, 264.0f, (f32)327, (f32)map->transitionFrame, 5.0f);
        ((SMapPanelPositions *)panelPositions)->points[0].position.y = fclEaseInterpolate(0, (f32)341, (f32)327, (f32)map->transitionFrame, 5.0f);
        scale = fclEaseInterpolate(0, 1.0f, iGpffff84f4, (f32)map->transitionFrame, 5.0f);
        frameWidth = fclEaseInterpolate(0, 120.0f, 183.0f, (f32)map->transitionFrame, 5.0f);
        frameBottom = fclEaseInterpolate(0, (f32)395, 332.0f, (f32)map->transitionFrame, 5.0f);
        /* fallthrough */
    }
    case 4:
        sdkSpriteDraw((u8 *)((SMapWork *)work)->ends[0], 0);
        sdkSpriteDraw((u8 *)((SMapWork *)work)->ends[1], 0);
        for (fixedStrip = 0; fixedStrip < 3; fixedStrip++) {
            for (fixedSprite = 0; fixedSprite < 6; fixedSprite++) {
                sdkSpriteDraw((u8 *)((SMapWork *)work)->strips[(s32)fixedStrip][(s32)fixedSprite], 0);
            }
        }
        break;
    case 5:
        ((SMapPanelPositions *)panelPositions)->points[1].position.y = fclEaseInterpolate(0, (f32)327, 264.0f, (f32)((SMapWork *)work)->transitionFrame, 10.0f);
        ((SMapPanelPositions *)panelPositions)->points[0].position.y = fclEaseInterpolate(0, (f32)327, (f32)341, (f32)map->transitionFrame, 10.0f);
        scale = fclEaseInterpolate(0, iGpffff84f4, 1.0f, (f32)map->transitionFrame, 10.0f);
        frameWidth = fclEaseInterpolate(0, 183.0f, 120.0f, (f32)map->transitionFrame, 10.0f);
        frameBottom = fclEaseInterpolate(0, 332.0f, (f32)395, (f32)map->transitionFrame, 10.0f);
        mapSymbolMarkerSetVariant(((SMapWork *)work)->playerMarker, 0);
        break;
    case 6:
        ((SMapPanelPositions *)panelPositions)->points[1].position.y = fclEaseInterpolate(0, 264.0f, (f32)327, (f32)((SMapWork *)work)->transitionFrame, 5.0f);
        ((SMapPanelPositions *)panelPositions)->points[0].position.y = fclEaseInterpolate(0, (f32)341, (f32)327, (f32)map->transitionFrame, 5.0f);
        scale = fclEaseInterpolate(0, 1.0f, iGpffff84f4, (f32)map->transitionFrame, 5.0f);
        frameWidth = fclEaseInterpolate(0, 120.0f, 183.0f, (f32)map->transitionFrame, 5.0f);
        frameBottom = fclEaseInterpolate(0, (f32)395, 332.0f, (f32)map->transitionFrame, 5.0f);
        mapSymbolMarkerSetVariant(((SMapWork *)work)->playerMarker, 1);
        break;
    default:
        break;
    }
    if (scale > iGpffff84f4) {
        ((SMapItem *)(((SMapWork *)work)->corners[1]))->y = ((SMapPanelPositions *)panelPositions)->points[1].position.y;
        /* measured: direct, typed-local and array member forms change retail instructions. */
        ((SMapItem *)(((SMapWork *)work)->corners[0]))->y = MEMBER(f32, panelPositions, SMapPanelPositions, points[1].position.y);
        ((SMapItem *)(((SMapWork *)work)->corners[3]))->y = ((SMapPanelPositions *)panelPositions)->points[0].position.y;
        /* measured: direct, typed-local and array member forms change retail instructions. */
        ((SMapItem *)(((SMapWork *)work)->corners[2]))->y = MEMBER(f32, panelPositions, SMapPanelPositions, points[0].position.y);
        cornerIndex = 0;
        fixedScale = scale * 4096.0f;
        for (; cornerIndex < 4; cornerIndex++) {
            size_t slotIndex = cornerIndex;
            u8 **pp = (u8 **)&((SMapWork *)work)->corners[slotIndex];
            u16 ww;
            ww = (u16)fixedScale;
            ((SMapItem *)(*pp))->scaleY = ww;
            sdkSpriteDraw(*pp, 0);
        }
    }
    ((SMapRectangle *)fclGetWorkPointer(((SMapWork *)work)->frames[0]))->height = frameWidth;
    ((SMapRectangle *)fclGetWorkPointer(((SMapWork *)work)->frames[2]))->position.y = frameBottom;
}
#pragma opt_loop_invariants off
#pragma pop

/* Clear the embedded ordering-table node's next/tail links before appending it again. */
// FUN_002B2240
void smapClearSelection(u8 *task) {
    u8 *work = ((KwlnTask *)task)->work;

    if (D_0076464C != 0) {
        ((OtPrimitiveNode *)((SMapWork *)work)->drawNode)->next = NULL;
        ((OtPrimitiveNode *)(work + 0x84))->tail = NULL;
        PrimAppendNode(&D_00794C90[0], work + 0x84);
    }
}

/* measured: object 620B/window 624B, normalized_diff 0. Levers: (1) the
   slot pointer is `p = &q->b[j]` (struct-member address), which makes the
   compiler redo the s16 sign-extension at the loop head instead of reusing
   the tail's copy; (2) `opt_loop_invariants on` hoists the two loop-3 float
   constants into `$a0`/`$v1` and fixes loop 1's commutative `addu`; (3) the
   unfused `add.s $f20,$f0,$f1` is `y = t; z = -99.0f + y;` - the copy stops
   b210 fusing `c + a*b` into `adda.s`/`madd.s`, and the fresh name `z`
   gives the constant-first operand order (a self-update `y = -99.0f + y`
   is variable-first). Prior archive: build/WBYList_y_smap_2290_candidate.c
   (nd 409). */
/* measured: opt_loop_invariants on hoists the loop-3 float constants into
   $a0/$v1 and fixes loop 1 addu operand order (nd 18 -> 0 with it). */
/* Allocate the map corner, strip and end sprites and initialize their queued panel draw node. */
// FUN_002B2290
#pragma opt_loop_invariants on
/* measured: literal and named end-sprite coordinate constants; best baseline residual 46 differing bytes. */
void smapUpdateItems(u8 *task)
{
    s16 cornerIndex;
    SMapWork *work;
    s16 stripIndex;
    SMapItem **spriteSlot;
    s16 endIndex;
    f32 rowCoordinate;
    f32 rowOffset;
    f32 screenY;

    work = (SMapWork *)((KwlnTask *)task)->work;
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        /* sdkSpr consumes the resource handle as an unsigned storage word. */
        work->corners[cornerIndex] = (SMapItem *)sdkSpriteNewNode(*(u32 *)&D_00764644, cornerIndex + 3);
    }
    work->corners[0]->x = 17.0f;
    work->corners[0]->y = 264.0f;
    work->corners[1]->x = 94.0f;
    work->corners[1]->y = 264.0f;
    work->corners[2]->x = 17.0f;
    work->corners[2]->y = 341.0f;
    work->corners[3]->x = 94.0f;
    work->corners[3]->y = 341.0f;
    for (stripIndex = 0; stripIndex < 6; stripIndex++) {
        spriteSlot = &work->leftStrip[stripIndex];
        *spriteSlot = (SMapItem *)sdkSpriteNewNode(D_00764644, 8);
        (*spriteSlot)->x = 190.0f;
        rowOffset = 108.0f * (f32)stripIndex;
        rowCoordinate = rowOffset;
        screenY = -99.0f + rowCoordinate;
        (*spriteSlot)->y = screenY;
        spriteSlot = &work->middleStrip[stripIndex];
        *spriteSlot = (SMapItem *)sdkSpriteNewNode(D_00764644, 8);
        (*spriteSlot)->x = 298.0f;
        (*spriteSlot)->y = screenY;
        spriteSlot = &work->rightStrip[stripIndex];
        *spriteSlot = (SMapItem *)sdkSpriteNewNode(D_00764644, 9);
        (*spriteSlot)->x = 406.0f;
        (*spriteSlot)->y = screenY;
    }
    work->ends[0] = (SMapItem *)sdkSpriteNewNode(D_00764644, 0xA);
    work->ends[1] = (SMapItem *)sdkSpriteNewNode(D_00764644, 0xB);
    for (endIndex = 0; endIndex < 2; endIndex++) {
        work->ends[endIndex]->x = 312.0f;
        work->ends[endIndex]->y = -10.0f;
    }
    memset(work->drawNode, 0, 0x30);
    ((PrimQueueNode *)work->drawNode)->callback = smapDrawPanel;
    ((PrimQueueNode *)work->drawNode)->argument.data = (u8 *)work;
}
/* measured: closes the loop-invariant bracket; the file default is off. */
#pragma opt_loop_invariants off

/* Install the blend, depth and texture states used by queued map rectangles. */
// FUN_002B2500
void smapSetRenderStates(void) {
    u8 *fp = (u8 *)D_00887300;

    ((void (**)(s32, s32))fp)[0](6, 1);
    ((void (**)(s32, s32))fp)[0](7, 2);
    ((void (**)(s32, s32))fp)[0](8, 1);
    ((void (**)(s32, s32))fp)[0](9, 2);
    ((void (**)(s32, s32))fp)[0](0xC, 1);
    ((void (**)(s32, s32))fp)[0](0xB, 6);
    ((void (**)(s32, s32))fp)[0](0xA, 5);
    ((void (**)(s32, s32))fp)[0](1, 0);
}

/* measured: four unsigned-byte-to-float sites use plain `(f32)(u32)` casts;
   spelling the compiler's sign-fixup by hand left the candidate at nd 45.
   The final body is object 552B/window 560B and verifier MATCH (normalized
   diff 0). `opt_loop_invariants on`, `schedule off`, and `opt_propagation off`
   keep the global base hoist, loop reload, and retail load order. */
// measured: probe loop invariant placement for the target's global load.
// measured: isolate the target's optimizer probes from following siblings.
#pragma push
#pragma opt_loop_invariants on
// measured: probe scheduler-off load ordering.
#pragma schedule off
// measured: probe propagation-off load ordering.
#pragma opt_propagation off
/* Populate four colored rectangle vertices and queue a draw with the map render-state callback. */
// FUN_002B25D0
/* measured: explicit depth-source pointer and propagation bisection; best baseline residual 69 differing bytes. */
s32 smapUpdateOverlay(u8 *task) {
    f32 reciprocalDepth;
    f32 nearDepth;
    f32 depth;
    s32 vertexIndex;
    u8 *work;
    u8 *drawNode;
    u8 *vertex;

    work = ((KwlnTask *)task)->work;
    reciprocalDepth = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    ((SMapRectangle *)work)->reciprocalDepth = reciprocalDepth;
    if (D_0076464C == 0) {
        return 0;
    }
    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
        vertex = work + (vertexIndex << 6);
        nearDepth = *(f32 *)D_008872F8;
        depth = ((SMapRectangle *)work)->depth;
        ((FldFilterVertex *)(vertex + 0x20))->z = nearDepth - depth;
        ((FldFilterVertex *)(vertex + 0x20))->reciprocalDepth = reciprocalDepth;
        ((FldFilterVertex *)(vertex + 0x20))->red =
            (f32)(u32)((SMapRectangle *)work)->color.a;
        ((FldFilterVertex *)(vertex + 0x20))->green =
            (f32)(u32)((SMapRectangle *)work)->color.b;
        ((FldFilterVertex *)(vertex + 0x20))->blue =
            (f32)(u32)((SMapRectangle *)work)->color.c;
        ((FldFilterVertex *)(vertex + 0x20))->alpha =
            (f32)(u32)((SMapRectangle *)work)->color.d;
    }
    ((SMapRectangle *)work)->vertices[0].x = ((SMapRectangle *)work)->position.x;
    ((SMapRectangle *)work)->vertices[0].y = ((SMapRectangle *)work)->position.y;
    ((SMapRectangle *)work)->vertices[1].x =
        ((SMapRectangle *)work)->position.x + ((SMapRectangle *)work)->width;
    ((SMapRectangle *)work)->vertices[1].y = ((SMapRectangle *)work)->position.y;
    ((SMapRectangle *)work)->vertices[2].x = ((SMapRectangle *)work)->position.x;
    ((SMapRectangle *)work)->vertices[2].y =
        ((SMapRectangle *)work)->position.y + ((SMapRectangle *)work)->height;
    ((SMapRectangle *)work)->vertices[3].x =
        ((SMapRectangle *)work)->position.x + ((SMapRectangle *)work)->width;
    ((SMapRectangle *)work)->vertices[3].y =
        ((SMapRectangle *)work)->position.y + ((SMapRectangle *)work)->height;
    drawNode = PrimQueueDrawPrimitive(D_00794D50, 4, work + 0x20, 4);
    ((PrimQueueNode *)drawNode)->callback = smapSetRenderStates;
    ((PrimQueueNode *)drawNode)->argument.data = work;
    return 0;
}
// measured: restore the file optimizer state after the target.
#pragma pop

// FUN_002B2800
void smapDestroyOverlay(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
/* The returned task owns the rectangle work. Retail retains this pointer in
   v0 through the work initialization: 260B/272B, twelve resolved references
   exact, and every sibling body, reference and owned data section preserved.
   Proof: build/cos20814/worker3-ui/rectangle_relocation_proof.json. */
/* Allocate a rectangle work block and register it as a child map-overlay task. */
// FUN_002B2830
u8 *smapCreateOverlay(u8 *parent, YVec2f position, f32 width, f32 height, u32 color) {
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_0063EF60, 0x97A);
    work = D_008873F4[0](1, 0x120, 0x40000);
    task = kwlnTaskCreateChild((void *)((s32)parent), (const void *)(D_0063F0F0), 0xF, 0, 0, smapUpdateOverlay, smapDestroyOverlay, (u8 *)(work));
    ((SMapRectangle *)work)->self = work;
    ((SMapRectangle *)work)->position = position;
    ((SMapRectangle *)work)->width = width;
    ((SMapRectangle *)work)->height = height;
    ((SMapRectangle *)work)->color = *(YRGBA *)&color;
    ((SMapRectangle *)work)->depth = 60000.0f;
    return task;
}
