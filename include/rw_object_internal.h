#ifndef RW_OBJECT_INTERNAL_H
#define RW_OBJECT_INTERNAL_H

#include "type.h"

/* SDK RwObject and RwObjectHasFrame prefixes (batype.h/batypehf.h). */
typedef struct RwObject {
    u8 type, subType, flags, privateFlags;
    void *parent;
} RwObject;

typedef struct RwObjectHasFrame {
    RwObject object;
    u8 pad08[0xC];
} RwObjectHasFrame;

#endif
