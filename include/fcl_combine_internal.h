#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"

/* Resource and position precede depth; integer order keeps its EE register. */
void fclSpriteCreate(s16 resource, FclVec2 position, f32 depth, s32 order);

void fclCombineDrawListRow(u8 *task, s8 slot, FclVec2 position, s16 resource,
                   s16 argument, s8 mode);

/* Selection colors return a packed word; opacity is an unsigned byte. */
s32 fclCombineApplySlotState(u8 *task, s8 slot, s8 selected, u8 alpha);
void fclCombineFlashSlot(u8 *task, s8 slot);

/* Advance the combination-grid fade before entering the next state. */
void fclCombineAdvanceGridFade(u8 *task, u8 next_state, s8 mode);

/* Incoming selectors are narrowed at their individual consumers. */
void fclCombineSelectSlotEntry(u8 *task, s8 slot, s8 first, s64 second, s64 entry_mode);
void fclCombineDrawStageTiles(u8 *task, s16 delay, s8 mode);

/* Combine-screen placements take their screen positions by value (one
   eight-byte register each), not as packed s64 bits. */
void fclCombineDrawSlotFields(u8 *task, FclVec2 position, s16 delay, s8 mode, s32 alternateSprites,
                              s32 narrowLayout, s32 variant);
void fclCombineDrawSlotLabels(u8 *task, FclVec2 position, s16 delay, s8 mode);
void fclCombineSlidePanelColumn(u8 *task, s32 slot, FclVec2 shownPosition, FclVec2 hiddenPosition, s32 mode,
                   s32 useHiddenPosition);
void fclCombineStartMove(u8 *task, FclVec2 start, FclVec2 end, s16 duration,
                   s16 delay);

u8 *fclCombineSlotRecord(u8 *task, s8 slot);
s32 fclCombineGetWorkAlt(u8 *task);

/* This forwarding routine consumes the same signed resource indices. */
void fclCombineSlideInSlotSprites(u8 *task, s16 firstResource, s16 secondResource);

/* Combine work block: the combine task's work at +0x38. Offsets not named by a
   consumer are padding. f0 is the state byte (6 is the menu preview state). */
typedef struct FclCombineWork {
    s8 f0;
    u8 f1;
    u8 pad2[0x2];
    s32 spritePool;
    u8 pad8[0x5];
    s8 fD;
    u8 padE[0xC];
    s8 fusionCount;              /* +0x1A: 2/3 for pair/triple; 4..7 for other material modes */
    u8 pad1B[5];
    s32 mesWindow;
    s32 raster;
    s32 texture;
    s32 spriteList;
    s32 *cardTable;
    u8 pad34[0x10];
    s8 rowCount;
    s8 refreshRequested;
    u8 pad46[0x6C];
    s8 fB2;
    s8 slotCursor;               /* +0xB3: three-slot menu selection */
    s8 commandCursor;
    s8 commandCount;
    s8 actionKind;
    s8 actionCount;
    s16 selectedIds[6];          /* +0xB8: resource IDs, followed by nine ten-byte rows */
    struct {
        s16 state0;
        s16 state1;
        s16 id;
        s16 x;
        s16 y;
    } commandRows[9];            /* +0xC4: row ID at +0xC8 */
    s16 f11E;
    s16 windowRow;
    s8 f122;
    s8 headerSelection;
    f32 rowSpacing;              /* +0x124: cursor-indicator row displacement */
    s8 f128;
    s8 f129;
    u8 pad12A[0xE];
    s8 choiceFlags;
    s8 choiceCount;
    s8 redrawRequested;
    u8 pad13B[0xD];
    u8 *f148;
    u8 pad14C[0x3C];
    s32 f188;
    u8 pad18C[0x90];
    u8 *ballTasks[12];            /* +0x21C: per-row ball draw tasks */
    struct KwlnTask *unk24C;      /* optional child tasks destroyed with the menu */
    struct KwlnTask *unk250;
    u8 pad254[4];
    u8 *clipTasks[12];           /* +0x258: row clips, also addressed as two per column */
    u8 pad288[4];
    u8 *f28C;
    u8 *f290;
    s8 cursorStates[2];
    u8 pad296[2];
    FclVec2 cursorPosition;
    u8 pad2A0[0x1C];
    s32 f2BC;
    u8 pad2C0[4];
    s8 detailFlags[2][5];
    u8 pad2CE[4];
    s8 calendarMonth;
    s8 calendarDay;
    s8 ruleIndices[2];
    s8 detailSide;
    u8 pad2D7[0x22];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineWork;

/* Global combine task handle; its work block is at +0x38. */
extern s32 iGpffffb598;

static inline FclCombineWork *fclCombineWork(void)
{
    return *(FclCombineWork **)(iGpffffb598 + 0x38);
}

#endif
