#ifndef PRIMITIVE_QUEUE_INTERNAL_H
#define PRIMITIVE_QUEUE_INTERNAL_H

#include "type.h"

/* PrimAllocQueueNode callers install a draw callback at +8 and its payload
 * at +0x10 before PrimAppendNode links the packet. Other fields are opaque. */
typedef struct PrimQueueNode {
    u8 pad00[8];
    void *callback;
    u8 pad0C[4];
    union { s32 handle; u8 *data; } argument;
} PrimQueueNode;

#endif
