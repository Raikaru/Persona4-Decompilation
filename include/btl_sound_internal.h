#ifndef BTL_SOUND_INTERNAL_H
#define BTL_SOUND_INTERNAL_H

#include "btl_effect_internal.h"
#include "btl_action_internal.h"

/* Embedded playback state at battle + 0xA44; ResetPlaybackState clears 0x2C bytes. */
typedef struct BtlSoundPlayback {
    u8 pad00[8];
    u16 channel, flags, phase;
    u8 pad0E[2];
    s32 handle;
    s32 currentId;
    s16 currentChannel;
    u8 pad1A[2];
    s32 pendingId;
    s16 pendingChannel;
    u8 pad22[2];
    s32 unk24;
    s16 unk28, unk2A;
} BtlSoundPlayback;

/* Six-byte channel-cache rows: a pair of signed selectors and a three-tick expiry. */
typedef struct BtlSoundChannel {
    s16 cue, variant;
    s8 frame;
    u8 pad05;
} BtlSoundChannel;

typedef struct BtlSoundQueue {
    u16 channel;
    s8 frame;
    u8 pad03;
    BtlSoundChannel channels[16];
} BtlSoundQueue;

typedef struct BtlSoundCueWork { u16 channel, cue, variant; } BtlSoundCueWork;
typedef struct BtlSoundLoadWork { u32 unk00; u16 bank, phase; } BtlSoundLoadWork;
typedef struct BtlSoundStreamWork { u16 channel, pad02; char *name; } BtlSoundStreamWork;

/* D_00624B22 names the secondary halfword of the four-byte rows at D_00624B20. */
typedef struct BtlSoundPersonaVoice { s16 primary, secondary; } BtlSoundPersonaVoice;

/* Three encounter callbacks/argument words at battle + 0xB40. Their ABI is retained at each caller. */
typedef struct BtlSoundEncounterSequence { s32 start, update, argument; } BtlSoundEncounterSequence;

/* Skill rows advance by 0x28. Only the selection bytes and effect-mask word are understood here. */
typedef struct BtlSoundSkill {
    u8 flags;
    u8 pad01[8];
    u8 targetGroup, targetMode;
    u8 pad0B;
    u16 targetFlags;
    u8 pad0E[0x12];
    s32 effectFlags;
    u8 condition;
    u8 pad25[3];
} BtlSoundSkill;

/* Cut-in name state at battle + 0xB7C; kind five substitutes a task for the effect. */
typedef struct BtlSoundNameState {
    u16 kind;
    u8 pad02[2];
    s32 effect;
    u8 *handle;
    s32 task;
} BtlSoundNameState;

/* The status handlers all index twenty-four byte counters at action + 0x3F6. */
typedef struct BtlSoundStatusTurns { u8 turns[24]; } BtlSoundStatusTurns;

/* Only the leading flags are consumed here; enemy rows advance by 0x3C. */
typedef struct BtlSoundEnemyStatusRow { u16 flags; u8 pad02[0x3A]; } BtlSoundEnemyStatusRow;

/* The encounter record selects a 0x18-byte music rule through its halfword at eight. */
typedef struct BtlSoundEncounterRecord { u8 pad00[8]; u16 trackRule; } BtlSoundEncounterRecord;
/* Boss setup reads bit 0x20 of the same 0x18-byte rule's leading flags. */
typedef struct BtlSoundTrackRule { s32 flags; u8 pad04[0x12]; u16 selector; } BtlSoundTrackRule;

#endif
