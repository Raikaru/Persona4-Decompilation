#ifndef BTL_PACKET_CALLBACK_INTERNAL_H
#define BTL_PACKET_CALLBACK_INTERNAL_H

#include "type.h"

/* Update callbacks return the scheduler's completion/status word. */
typedef s32 (*BtlPacketCallback)(void *data);
typedef struct BtlPacketCallbackWork {
    BtlPacketCallback callback;
    void *data;
} BtlPacketCallbackWork;

s32 btlPacketCallbackRun(BtlPacketCallbackWork *work);

#endif
