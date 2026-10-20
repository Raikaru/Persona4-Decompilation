#ifndef K_CLUMP_DRAW_INTERNAL_H
#define K_CLUMP_DRAW_INTERNAL_H

#include "type.h"
#include "rw_atomic_layout_internal.h"
#include "sdk_ot_node.h"

/* Material-group draw passes follow next at +0x24, render atomic at +0,
 * and temporarily disable vertex alpha when disableVertexAlpha is one. */
typedef struct KClumpDrawEntry {
    struct RpAtomic *atomic;
    s32 disableVertexAlpha;
    u8 pad08[0xC];
    f32 unk14;
    u8 pad18[0xC];
    struct KClumpDrawEntry *next;
} KClumpDrawEntry;

typedef struct KClumpDrawBuckets {
    KClumpDrawEntry *heads[11];
} KClumpDrawBuckets;

#endif
