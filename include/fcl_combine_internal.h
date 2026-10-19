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
void fclCombineDrawSlotFields(u8 *task, FclVec2 position, s16 delay, s8 mode, s32 arg4,
                              s32 arg5, s32 variant);
void fclCombineDrawSlotLabels(u8 *task, FclVec2 position, s16 delay, s8 mode);
void fclCombineSlidePanelColumn(u8 *task, s32 slot, FclVec2 shownPosition, FclVec2 hiddenPosition, s32 mode,
                   s32 useHiddenPosition);
void fclCombineStartMove(u8 *task, FclVec2 start, FclVec2 end, s16 duration,
                   s16 arg4);

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
    u8 padB3[0x6B];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    u8 *f148;
    u8 pad14C[0x3C];
    s32 f188;
    u8 pad18C[0xC0];
    struct KwlnTask *unk24C;      /* optional child tasks destroyed with the menu */
    struct KwlnTask *unk250;
    u8 pad254[0x38];
    u8 *f28C;
    u8 *f290;
    u8 pad294[0x28];
    s32 f2BC;
    u8 pad2C0[0x39];
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
