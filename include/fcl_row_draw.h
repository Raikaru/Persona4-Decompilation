#ifndef FCL_ROW_DRAW_H
#define FCL_ROW_DRAW_H

#include "fcl_color.h"
#include "fcl_draw_types.h"

/* The EE row transition consumes native position and color packets. The
   depth float follows the color: the callee prologue moves $f12 between the
   color and order spills, and callers evaluate depth before the order cast. */
void fclSpriteStartShowHide(s16 index, FclVec2 position, s16 spriteId,
                   FclDrawColor color, f32 depth, s16 order, s8 hidden,
                   s16 showDuration, s16 hideDuration,
                   s16 startDelay, u32 resource);

void fclCombineCreateSlotIcons(u8 *task, s8 mode);
void fclCombineDrawStageTiles(u8 *owner, s16 duration, s8 mode);

#endif
