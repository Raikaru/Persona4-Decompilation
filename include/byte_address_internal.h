#ifndef BYTE_ADDRESS_INTERNAL_H
#define BYTE_ADDRESS_INTERNAL_H

#include "type.h"

/* measured: plain base + offset reverses addu operands in datCloneEntryBlock,
 * scrStartScriptTask and the radar menu callers. Keeping the integer offset
 * first preserves their retail operand order; callers supply typed strides or
 * MEMBER_OFFSET for object members, never an unexplained member displacement. */
static inline u8 *byteAddressAdd(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}

#endif
