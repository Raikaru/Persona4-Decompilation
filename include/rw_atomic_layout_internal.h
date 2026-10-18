#ifndef RW_ATOMIC_LAYOUT_INTERNAL_H
#define RW_ATOMIC_LAYOUT_INTERNAL_H

#include "type.h"
#include "rw_atomic_internal.h"

struct RpGeometry;

/* RpAtomic from rw/world/baclump.h, with opaque spans for fields not used by
 * these clients. The frame is RwObjectHasFrame.object.parent at offset four;
 * geometry and renderCallBack retain their SDK offsets and pointer types. */
struct RpAtomic
{
    u8 pad00[4];
    struct RwFrame *frame;
    u8 pad08[0x10];
    struct RpGeometry *geometry;
    u8 pad1C[0x2C];
    struct RpAtomic *(*renderCallBack)(struct RpAtomic *atomic);
};

#endif
