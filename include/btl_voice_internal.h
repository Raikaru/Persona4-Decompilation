#ifndef BTL_VOICE_INTERNAL_H
#define BTL_VOICE_INTERNAL_H

#include "btl_action_internal.h"

/* btlVoiceResetPlaybackState clears this 0x14-byte block at battle + 0xB2C.
 * Both buffers are freed by btlVoiceFreePlaybackBuffers. */
typedef struct BtlVoicePlayback {
    u16 unk00;
    u16 flags;                 /* 0x02: bit 0 enables action voices */
    u16 bank;                  /* 0x04: initially 3 */
    u8 pad06[2];
    void *buffer;              /* 0x08 */
    u16 idFlags;               /* 0x0C: bit 0 completes an ID request */
    u16 idBank;                /* 0x0E: 4 or 5, selected by packet 0xA03 */
    void *idBuffer;            /* 0x10 */
} BtlVoicePlayback;

/* The 0x18-byte work allocated by btlVoiceCreatePacket (packet 0xA01). */
typedef struct BtlVoicePacketWork {
    BtlAction *action;
    u16 callbackIndex;
    u8 pad06[2];
    s32 argument;
    s32 extraArgument;
    u16 flags;                 /* 0x10: bit 0 leaves the model's talk state alone */
    u8 pad12[2];
    s32 started;
} BtlVoicePacketWork;

/* Packet 0xA03 allocates 0x0C bytes; the leading two words are also used by
 * the wait packet created in btlSound.c. */
typedef struct BtlVoiceIdWork {
    s32 result;
    s32 state;
    u16 voiceId;
    u8 pad0A[2];
} BtlVoiceIdWork;

typedef char BtlVoicePlaybackSizeCheck[sizeof(BtlVoicePlayback) == 0x14 ? 1 : -1];
typedef char BtlVoicePacketWorkSizeCheck[sizeof(BtlVoicePacketWork) == 0x18 ? 1 : -1];
typedef char BtlVoiceIdWorkSizeCheck[sizeof(BtlVoiceIdWork) == 0x0C ? 1 : -1];

#endif
