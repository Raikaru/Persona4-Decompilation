#ifndef MESSAGE_WINDOW_INTERNAL_H
#define MESSAGE_WINDOW_INTERNAL_H

#include "type.h"

/* Eight 0x18-byte entries are cleared before queuing a window exit effect.
 * EntryStep advances elapsed; the calendar exit adds frameOffset to it. */
typedef struct MsgProcWindowEntry {
    s32 flags; /* bit 0: active */
    s32 kind;
    f32 frameOffset;
    s32 unk0C;
    s32 elapsed;
    s32 unk14;
} MsgProcWindowEntry;

typedef char MsgProcWindowEntrySize[sizeof(MsgProcWindowEntry) == 0x18 ? 1 : -1];

#endif
