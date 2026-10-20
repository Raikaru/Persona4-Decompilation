#ifndef EVT_EFFECT_INTERNAL_H
#define EVT_EFFECT_INTERNAL_H
#include "type.h"

/* evtEffectTableCreate allocates 0x190 bytes. Eight 0x2C-byte records occupy
 * +0x10..+0x16F; the sixteen resource-id slots follow at +0x170. */
typedef struct EvtEffectEntry {
    s32 kind;
    u8 filename[0x20];
    s32 lookupResult;
    u8 *request;
} EvtEffectEntry;
typedef struct EvtEffectTable {
    s32 state;
    s32 count;
    s32 nextIndex;
    s32 pendingRequest;
    EvtEffectEntry entries[8];
    u16 slots[16];
} EvtEffectTable;
#endif
