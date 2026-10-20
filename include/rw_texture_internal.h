#ifndef RW_TEXTURE_INTERNAL_H
#define RW_TEXTURE_INTERNAL_H

#include "type.h"
#include "rw_raster_internal.h"

/* RenderWare SDK layout from rw/core/batextur.h; scalar-only like rw_raster_internal.h. */
typedef struct RwTexture {
    RwRaster *raster;
    void *dict;
    struct { void *next; void *prev; } lInDictionary;
    char name[32];
    char mask[32];
    u32 filterAddressing; /* 0x50: low byte is filtering, next byte addressing */
    s32 refCount;
} RwTexture;

#endif
