#ifndef K_FLDSTEP_INTERNAL_H
#define K_FLDSTEP_INTERNAL_H

#include "type.h"

/* FldStepEntry consumers use the numbered file and environment-state bytes.
 * The remainder of the packed step table record has not been recovered. */
typedef struct FldStepRecord {
    u8 unk00[0xC];
    u8 fileId;
    u8 environmentState;
} FldStepRecord;

#endif
