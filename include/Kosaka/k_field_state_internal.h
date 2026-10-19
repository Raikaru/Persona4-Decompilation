#ifndef K_FIELD_STATE_INTERNAL_H
#define K_FIELD_STATE_INTERNAL_H

#include "type.h"

struct ResrcRecord;

/* MT_Scene_GetFrameState consumers access these three scheduler handles. */
typedef struct FldSceneTasks {
    s32 root;
    s32 camera;
    s32 event;
} FldSceneTasks;

/* Field party lookup advances slots by 0x750 and compares the member at +0x728.
 * Only the active/resource members used by that lookup are identified here. */
typedef struct FldPartySlot {
    u8 pad00[0x48];
    s32 active;
    u8 pad4C[8];
    struct ResrcRecord *resource;
    u8 pad58[0x158];
    s32 chaser; /* +0x1B0: passed to FldAI_ChaserDisable by placement */
    u8 pad1B4[0x574];
    u16 memberId;
    u8 pad72A[0x26];
} FldPartySlot;
typedef char FldPartySlotSize[sizeof(FldPartySlot) == 0x750 ? 1 : -1];

#endif
