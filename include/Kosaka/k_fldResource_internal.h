#ifndef K_FLDRESOURCE_INTERNAL_H
#define K_FLDRESOURCE_INTERNAL_H

#include "rw_object_internal.h"
#include "rw_camera_internal.h"
#include "rw_frame_internal.h"

/* SDK balight.h prefix used by the field resource loader. */
struct RwRGBAReal {
    f32 red, green, blue, alpha;
};
struct RpLight {
    RwObject object;
    u8 pad08[0x0C];
    f32 radius;
    struct RwRGBAReal color;
};

/* SDK bastream.h memory-stream cursor and backing storage. */
struct RwStream {
    s32 type;
    s32 accessType;
    s32 position;
    struct {
        u32 position;
        u32 size;
        u8 *data;
    } memory;
};

typedef struct {
    u16 type;
    u16 flags;
    u16 id;
    u16 pad06;
    s32 frame;
    s32 model;
    s32 effect;
    union { s32 file; u8 *filePtr; };
} FldResourceEntry;

/* Object flags select worlds/clumps and draw variants; entries have 0x18-byte stride. */
typedef struct {
    u32 flags;
    s16 majorId;
    s16 minorId;
    union { s32 primaryObject; struct RpWorld *primaryWorld; };
    union { s32 primaryDrawObject; u8 *primaryDrawObjectPtr; };
    s32 alternateObject;
    s32 secondaryObject;
    u32 clumpCount;
    s32 clumps[32];
    union { s32 drawObjects[32]; void *drawObjectPointers[32]; };
    u32 entryCount;
    FldResourceEntry entries[96];
    s32 animation;
    union { RwV3d scale; struct { s32 scaleXBits, scaleYBits, scaleZBits; }; }; /* 0xA24 */
    RwV3d clumpScale; /* 0xA30: environment scale */
    s32 hbnFile;
    union { s32 hbnData; u8 *hbnDataPtr; };
    u8 *loadWork;
    s32 fbnFile;
    union { u8 *fbnData; s32 fbnDataWord; };
    struct RwRGBAReal savedAmbientColor;
    struct RwRGBAReal savedDirectionalColor;
    u8 savedLightMatrix[0x40];
} FldResource;

#endif
