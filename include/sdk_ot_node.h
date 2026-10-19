#ifndef SDK_OT_NODE_H
#define SDK_OT_NODE_H

#include "type.h"

/* All ordering-table constructors allocate and clear this 0x30-byte node.
 * Commands reuse the primitive/vertices/count payload words for state data. */
typedef struct OtPrimitiveNode OtPrimitiveNode;
struct OtPrimitiveNode {
    OtPrimitiveNode *next;
    OtPrimitiveNode *tail;
    void (*callback)(void *, void *);
    void (*endCallback)(void *, void *);
    void *callbackData;
    void *endCallbackData;
    u16 command;
    u16 reserved1A;
    s32 primitive;
    void *vertices;
    s32 count;
    u32 reserved28[2];
};
typedef char OtPrimitiveNodeSize[(sizeof(OtPrimitiveNode) == 0x30) ? 1 : -1];

#endif
