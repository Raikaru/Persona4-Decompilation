#ifndef NM_MESSAGE_RECORD_H
#define NM_MESSAGE_RECORD_H

#include "type.h"

/* nmMesWindowAcquire allocates 0x10 bytes. Init, step, and slot accessors
 * establish the handle, opening/closing state, pause flag, pending record,
 * cursor and latched animation result. Bytes 6-7 and E-F are untouched. */
typedef struct NmMesWindowRecord {
    s32 handle;
    s8 state;
    s8 paused;
    u8 pad06[2];
    s32 pendingRecord;
    s8 cursor;
    s8 result;
    u8 pad0E[2];
} NmMesWindowRecord;

typedef char NmMesWindowRecordSize[sizeof(NmMesWindowRecord) == 0x10 ? 1 : -1];

#endif
