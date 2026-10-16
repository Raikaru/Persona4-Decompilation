#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

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

#endif
