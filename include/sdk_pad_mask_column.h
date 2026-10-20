#ifndef SDK_PAD_MASK_COLUMN_H
#define SDK_PAD_MASK_COLUMN_H

#include "sdk_pad_record.h"

/* Linker interior aliases address individual halfword columns of the pad
 * records. Each row starts at that mask and runs to the same mask in the
 * next 0x4A-byte record, rather than at the record's mode field. */
typedef struct SdkPadMaskColumn {
    u16 mask;
    u8 followingBytes[sizeof(SdkPadRecord) - sizeof(u16)];
} SdkPadMaskColumn;
typedef char SdkPadMaskColumnSizeCheck[sizeof(SdkPadMaskColumn) == sizeof(SdkPadRecord) ? 1 : -1];

#endif
