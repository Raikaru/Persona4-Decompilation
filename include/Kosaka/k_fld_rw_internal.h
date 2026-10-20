#ifndef K_FLD_RW_INTERNAL_H
#define K_FLD_RW_INTERNAL_H

#include "rw_types_internal.h"

/* SDK member layouts from batype.h, bamatrix.h, baframe.h, bacamera.h,
 * balight.h and bastream.h. Only RwObject and RwMatrixTag are complete;
 * the other declarations stop after the fields consumed by field code. */
typedef struct RwObject {
    u8 type, subType, flags, privateFlags;
    void *parent;
} RwObject;

struct RwMatrixTag {
    union { RwV3d right; struct { s32 rightXBits, rightYBits, rightZBits; }; };
    u32 flags;
    union { RwV3d up; struct { s32 upXBits, upYBits, upZBits; }; };
    u32 pad1;
    union { RwV3d at; struct { s32 atXBits, atYBits, atZBits; }; };
    u32 pad2;
    union { RwV3d pos; struct { s32 posXBits, posYBits, posZBits; }; };
    u32 pad3;
};

struct RwFrame {
    RwObject object;
    u8 inDirtyListLink[8];
    struct RwMatrixTag modelling;
    struct RwMatrixTag ltm;
};

struct RwCamera {
    RwObject object;
    u8 pad08[0x78];
    f32 nearPlane; /* 0x80 */
};

struct RwRGBAReal {
    f32 red, green, blue, alpha;
};

struct RpLight {
    RwObject object;
    u8 pad08[0x0C];
    f32 radius;
    struct RwRGBAReal color; /* 0x18 */
};

struct RwStream {
    s32 type;
    s32 accessType;
    s32 position;
    struct {
        u32 position; /* 0x0C: memory-stream cursor, not the generic position */
        u32 size;
        u8 *data;
    } memory;
};

typedef char FldRwObjectSize[sizeof(RwObject) == 8 ? 1 : -1];
typedef char FldRwMatrixSize[sizeof(struct RwMatrixTag) == 0x40 ? 1 : -1];

#endif
