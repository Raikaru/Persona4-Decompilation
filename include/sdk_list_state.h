#ifndef SDK_LIST_STATE_H
#define SDK_LIST_STATE_H

#include "type.h"

/* The initializer clears exactly 0x2C bytes; setters establish each field. */
typedef struct SdkListState {
    s32 flags;
    u16 primaryForward;
    u16 primaryBack;
    u16 primaryRepeatForward;
    u16 primaryRepeatBack;
    u16 secondaryForward;
    u16 secondaryBack;
    u16 secondaryRepeatForward;
    u16 secondaryRepeatBack;
    s32 visibleRows;
    s32 reservedRows;
    s32 unk1C;
    s32 itemCount;
    s32 cursor;
    s32 scroll;
} SdkListState;

#endif
