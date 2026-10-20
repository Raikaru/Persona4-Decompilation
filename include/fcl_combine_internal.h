#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"

/* Resource and position precede depth; integer order keeps its EE register. */
void fclSpriteCreate(s16 index, FclVec2 position, f32 depth, s32 order);

void fclCombineDrawListRow(u8 *task, s8 row, FclVec2 position, s16 resource,
                   s16 delay, s8 mode);

/* Selection colors return a packed word; opacity is an unsigned byte. */
s32 fclCombineApplySlotState(u8 *task, s8 slot, s8 selected, u8 opacity);
void fclCombineFlashSlot(u8 *task, s8 slot);

/* Advance the combination-grid fade before entering the next state. */
void fclCombineAdvanceGridFade(u8 *task, u8 nextState, s8 mode);

/* Incoming selectors are narrowed at their individual consumers. */
void fclCombineSelectSlotEntry(u8 *task, s8 slot, s8 firstSelectedSlot, s64 secondSelectedSlot, s64 skipRoster);
void fclCombineDrawStageTiles(u8 *owner, s16 duration, s8 mode);

/* Combine-screen placements take their screen positions by value (one
   eight-byte register each), not as packed s64 bits. */
void fclCombineDrawSlotFields(u8 *task, FclVec2 position, s16 delay, s8 mode, s32 alternateSprites,
                              s32 narrowLayout, s32 variant);
void fclCombineDrawSlotLabels(u8 *task, FclVec2 position, s16 delay, s8 mode);
void fclCombineSlidePanelColumn(u8 *task, s32 slot, FclVec2 shownPosition, FclVec2 hiddenPosition, s32 mode,
                   s32 useHiddenPosition);
void fclCombineStartMove(u8 *task, FclVec2 start, FclVec2 end, s16 duration,
                   s16 delay);

u8 *fclCombineSlotRecord(u8 *task, s8 slotIndex);
s32 fclCombineGetWorkAlt(u8 *task);

/* This forwarding routine consumes the same signed resource indices. */
void fclCombineSlideInSlotSprites(u8 *task, s16 firstResource, s16 secondResource);

/* Ten-byte command record, shared by the menu builder and row renderer. */
typedef struct FclCombineRow {
    s16 state0;
    s16 state1;
    s16 id;
    s16 x;
    s16 y;
} FclCombineRow;

/* Canonical 0x314-byte menu allocation from fclCombineMenuCreate, reached through
   the combine task's work pointer at +0x38. The root state is f0 (6 previews).
   Unions preserve the integer/pointer handle uses and phase-specific scratch
   interpretations observed in the menu, resource setup, and draw consumers.
   The nine command rows start at +0xC4; child arrays start at +0x21C/+0x258. */
typedef struct FclCombineWork {
    s8 f0;
    u8 f1;
    u8 pad2[0x2];
    s32 spritePool;
    u8 pad8[0x5];
    s8 fD;
    s16 unkE;
    s32 unk10;
    union { s32 signedValue; u32 value; } unk14;
    u8 pad18[2];
    s8 fusionCount;              /* +0x1A: 2/3 for pair/triple; 4..7 for other material modes */
    u8 pad1B;
    union { s16 signedValue; u16 value; } outcome;
    s8 outcomeCount;
    s8 stageKind;
    union { s32 mesWindow; struct { s8 unk20; s8 unk21; u8 pad22[2]; }; };
    union { s32 raster; struct { union { s16 signedValue; u16 value; } unk24; s8 unk26; s8 unk27; }; };
    s32 texture;
    s32 spriteList;
    s32 *cardTable;
    u8 pad34[0x10];
    s8 rowCount;
    s8 refreshRequested;
    u8 pad46[0x6A];
    s8 unkB0;
    s8 unkB1;
    s8 fB2;
    s8 slotCursor;               /* +0xB3: three-slot menu selection */
    s8 commandCursor;
    s8 commandCount;
    s8 actionKind;
    s8 actionCount;
    s16 selectedIds[6];          /* +0xB8: resource IDs, followed by nine ten-byte rows */
    FclCombineRow commandRows[9]; /* +0xC4: row ID at +0xC8 */
    s16 f11E;
    s16 windowRow;
    s8 f122;
    s8 headerSelection;
    union { f32 rowSpacing; s32 unk124; }; /* +0x124: cursor-indicator row displacement */
    s8 f128;
    s8 f129;
    u8 pad12A[6];
    s8 claimSlot;
    u8 pad131[7];
    s8 choiceFlags;
    s8 choiceCount;
    s8 redrawRequested;
    u8 pad13B;
    s8 unk13C;
    s8 unk13D;
    s8 unk13E;
    s8 rewardIndex;
    u8 pad140[4];
    u8 unk144;
    u8 pad145[3];
    union { u8 *f148; union { s32 handle; u8 *task; } drawTask; };
    u8 pad14C[8];
    s32 rowTasks[12];
    s32 f184;
    union { s32 f188; union { s32 handle; u8 *task; } ballTask; };
    u8 pad18C[0x90];
    union { u8 *ballTasks[12]; s32 ballTaskHandles[12]; }; /* +0x21C */
    union { struct KwlnTask *unk24C; s32 spritePoolTask; };
    union { struct KwlnTask *unk250; u8 *bustupTask; };
    union { s32 handle; u8 *task; } detailTask;
    u8 *clipTasks[12];           /* +0x258: row clips, also addressed as two per column */
    u8 pad288[4];
    union { u8 *f28C; union { s32 handle; u8 *task; } headerTask; };
    union { u8 *f290; union { s32 handle; u8 *task; } arrowTask; };
    s8 cursorStates[2];
    u8 pad296[2];
    FclVec2 cursorPosition;
    u8 pad2A0[4];
    u8 *levelUpTask;
    u8 *skillReplaceTask;
    s32 topBorderTask;
    s32 bottomBorderTask;
    s32 middleBorderTask;
    u8 pad2B8[4];
    union { s32 f2BC; u8 *messageTask; };
    u8 pad2C0[4];
    s8 detailFlags[2][5];
    u8 pad2CE[4];
    s8 calendarMonth;
    s8 calendarDay;
    s8 ruleIndices[2];
    s8 detailSide;
    u8 pad2D7;
    s16 f2D8;
    s8 outcomeIds[5];
    s8 outcomeIdCount;
    u8 pad2E0[0x19];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
    s32 eventTask;
    s32 cardEffectTask;
    s32 cardSpriteTask;
    u8 f30C[5];
    u8 pad311[3];
} FclCombineWork;

/* Global combine task handle; its work block is at +0x38. */
extern s32 iGpffffb598;

static inline FclCombineWork *fclCombineWork(void)
{
    return *(FclCombineWork **)(iGpffffb598 + 0x38);
}

#endif
