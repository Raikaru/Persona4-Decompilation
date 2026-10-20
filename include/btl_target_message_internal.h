#ifndef BTL_TARGET_MESSAGE_INTERNAL_H
#define BTL_TARGET_MESSAGE_INTERNAL_H

#include "type.h"

/* Loaded message directories have twelve-byte rows. The first byte gates
 * encounter-suppressed messages; the word at +4 is relative to the directory. */
typedef struct BtlTargetMessageEntry {
    u8 restricted;
    u8 pad01[3];
    s32 offset;
    u32 unk08;
} BtlTargetMessageEntry;

typedef char BtlTargetMessageEntrySizeCheck[sizeof(BtlTargetMessageEntry) == 12 ? 1 : -1];

#endif
