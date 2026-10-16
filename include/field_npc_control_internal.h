#ifndef FIELD_NPC_CONTROL_INTERNAL_H
#define FIELD_NPC_CONTROL_INTERNAL_H
#include "type.h"

/* Field npc control task work, the 0x58-byte block at task+0x38 (allocated in
 * FldNpcControlTaskCreate). Only the fields used by name in the create,
 * destroy and ready paths are typed. FldNpcControlUpdate indexes the same
 * block by word and keeps its raw accesses; its fields are not named here. */
typedef struct FldNpcControlWork {
    u32 state;             /* 0x00: update step; FldNpcControlReady reports state >= 4 */
    u8 unk04[0x04];
    u32 hidden;            /* 0x08: 1 suppresses the update */
    s32 actor;             /* 0x0C: actor argument passed to FldNpcControlTaskCreate */
    u8 unk10[0x04];
    s32 handle;            /* 0x14: handle released by func_003e0f40 on destroy */
    u8 unk18[0x30];
    f32 cameraHeight;      /* 0x48: camera height copied at create */
    u8 unk4C[0x0C];
} FldNpcControlWork;

#endif
