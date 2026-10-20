#ifndef PRIMITIVE_QUEUE_INTERNAL_H
#define PRIMITIVE_QUEUE_INTERNAL_H

#include "type.h"

/* PrimAllocQueueNode callers install a draw callback at +8 and its payload
 * at +0x10. Field draw commands also install the closing callback at +0x0C. */
typedef struct PrimQueueNode {
    u8 pad00[8];
    void *callback;
    void *endCallback;
    union { s32 handle; u8 *data; } argument;
} PrimQueueNode;

/* The world/clump queue constructors return commands with a second context. */
typedef struct PrimQueueDrawNode {
    PrimQueueNode begin;
    union { s32 handle; u8 *data; } endArgument; /* 0x14 */
} PrimQueueDrawNode;

#endif
