#ifndef EVT_EFFECT_INTERNAL_H
#define EVT_EFFECT_INTERNAL_H
#include "type.h"

/* evtEffectTableCreate allocates 0x190 bytes. The live count drives iteration,
 * but mtMisc slot accesses fix sixteen resource IDs at +0x170, leaving capacity
 * for eight 0x2C-byte entries at +0x10; this is not a flexible-tail allocation. */
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

typedef char EvtEffectEntrySizeCheck[sizeof(EvtEffectEntry) == 0x2C ? 1 : -1];
typedef char EvtEffectTableSlotsOffsetCheck[(u32)&((EvtEffectTable *)0)->slots == 0x170 ? 1 : -1];
typedef char EvtEffectTableSizeCheck[sizeof(EvtEffectTable) == 0x190 ? 1 : -1];
#endif
