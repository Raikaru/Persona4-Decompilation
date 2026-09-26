#ifndef FCL_BOUNDS_PACKET_H
#define FCL_BOUNDS_PACKET_H

#include "fcl_draw_types.h"

/* Bounds records are four-byte aligned, including their byte-copy view.
 * The prefix has no numeric value: the retail constructor leaves eight
 * bytes of stack residue before the two initialized signed dimensions.
 * Copies use only this unsigned-character representation, never float or
 * integer expressions for those unspecified bytes.
 */
typedef struct {
    u8 data[16];
} __attribute__((aligned(4))) FclBoundsBytes;

typedef union {
    struct {
        u8 reserved[8];
        s32 width;
        s32 height;
    } dimensions;
    FclBoundsBytes representation;
} FclBoundsPacket;

/* Returned by value; the sixteen-byte records are passed by value too
   (through a caller-side copy whose address travels in the argument). */
FclBoundsPacket func_002b29e0(f32 width, f32 height);
void func_002b5db0(u8 *task, FclVec2 position, FclBoundsPacket bounds);
void func_002b5ef0(u8 *task, FclVec2 start, FclVec2 end,
                   FclBoundsPacket startBounds, FclBoundsPacket endBounds,
                   u32 duration);
void func_002b5fd0(u8 *task, FclVec2 start, FclVec2 end,
                   FclBoundsPacket startBounds, FclBoundsPacket endBounds,
                   u32 duration, s16 mode);

#endif
