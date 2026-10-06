#ifndef BTL_FORMATION_INTERNAL_H
#define BTL_FORMATION_INTERNAL_H

#include "type.h"

struct BtlPacket;

/* Return the formation packet for the caller's UID/dependency attachment. */
struct BtlPacket *func_001d1eb0(u32 source, u32 target, f32 distance, u16 mode);

/* Format the low halfword of the value into the caller's resource-path buffer. */
void func_001d69f0(u32 value, char *destination);

#endif
