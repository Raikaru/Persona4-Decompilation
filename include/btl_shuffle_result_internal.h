#ifndef BTL_SHUFFLE_RESULT_INTERNAL_H
#define BTL_SHUFFLE_RESULT_INTERNAL_H

#include "btl_shuffle_state_internal.h"
#include "kwln_task_internal.h"

/* Result child work is allocated as 0x94 bytes; the 0x7C-byte payload is reused by its phases. */
typedef struct BtlShuffleResultWork {
    u8 *context;
    u16 flags, frames;
    s32 phase, cardKind;
    u16 personaId;
    u8 bonusKind, pad13;
    s32 result;
    u8 state[0x7C];
} BtlShuffleResultWork;

/* Replacement-persona menu payload at work + 0x18. */
typedef struct BtlShuffleResultRoster {
    s32 phase, row, scroll, count, unk10, mode;
    u8 *display;
    u8 persona[0x30];
    u8 *slots[12];
} BtlShuffleResultRoster;

/* Special-result menu payload is cleared as twelve bytes by the preceding phase. */
typedef struct BtlShuffleResultMenu {
    s32 phase;
    u16 frames;
    u8 pad06[2];
    s32 result;
} BtlShuffleResultMenu;

/* sdkListStateConfigure writes selection outputs at 0x24 and 0x28. */
typedef struct BtlShuffleResultCursor {
    u8 pad00[0x24];
    s32 row, scroll;
    u8 pad2C[4];
} BtlShuffleResultCursor;

#endif
