#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

#include "fcl_draw_types.h"

/* Resource and position precede depth; integer order keeps its EE register. */
void func_002b6c30(s64 resource, FclVec2 position, f32 depth, s32 order);

void func_002b2970(u8 *out, f32 x, f32 y);

void func_003147e0(u8 *task, s8 slot, FclVec2 position, s16 resource,
                   s32 order, s32 mode);

/* Selection colors return a packed word; opacity is an unsigned byte. */
s32 func_0031ddf0(u8 *task, s8 slot, s8 selected, u8 alpha);
void func_0031e320(u8 *task, s8 slot);

/* Advance the combination-grid fade before entering the next state. */
void func_003212e0(u8 *task, u8 next_state, s8 mode);

/* Incoming selectors are narrowed at their individual consumers. */
void func_0031d630(u8 *task, s8 slot, s8 first, s64 second, s64 entry_mode);

u8 *func_0034ae50(u8 *task, s8 slot);
s32 func_0034b810(u8 *task);

#endif
