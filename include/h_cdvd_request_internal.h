#ifndef H_CDVD_REQUEST_INTERNAL_H
#define H_CDVD_REQUEST_INTERNAL_H

#include "type.h"

/* Loaded archive requests expose their payload at 0x110 and byte size at
 * 0x118 to FldStepCopyLoadedFile and the model sound copy consumer. The
 * consumers use both signed and unsigned size loads; preserve each width. */
typedef struct HCdvdRequest {
    u8 pad00[0x110];
    void *data;
    u8 pad114[4];
    union {
        u32 size;
        s32 signedSize;
    };
} HCdvdRequest;

#endif
