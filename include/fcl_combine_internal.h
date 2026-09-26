#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

#include "fcl_draw_types.h"

/* Resource and position precede depth; integer order keeps its EE register. */
void func_002b6c30(s64 resource, FclVec2 position, f32 depth, s32 order);

void func_003147e0(u8 *task, s8 slot, FclVec2 position, s16 resource,
                   s16 argument, s8 mode);

/* Selection colors return a packed word; opacity is an unsigned byte. */
s32 func_0031ddf0(u8 *task, s8 slot, s8 selected, u8 alpha);
void func_0031e320(u8 *task, s8 slot);

/* Advance the combination-grid fade before entering the next state. */
void func_003212e0(u8 *task, u8 next_state, s8 mode);

/* Incoming selectors are narrowed at their individual consumers. */
void func_0031d630(u8 *task, s8 slot, s8 first, s64 second, s64 entry_mode);

/* Combine-screen placements take their screen positions by value (one
   eight-byte register each), not as packed s64 bits. */
void func_0031e5b0(u8 *task, FclVec2 position, s32 delay, s8 mode, s32 arg4,
                   s32 arg5, s32 variant);
void func_0031fa20(u8 *task, FclVec2 position, s32 delay, s8 mode);
void func_0032c660(u8 *task, s32 slot, FclVec2 start, FclVec2 end, s32 arg4,
                   s32 arg5);
void func_0033e540(u8 *task, FclVec2 start, FclVec2 end, s16 duration,
                   s16 arg4);

u8 *func_0034ae50(u8 *task, s8 slot);
s32 func_0034b810(u8 *task);

#endif
