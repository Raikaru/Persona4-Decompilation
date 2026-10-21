#include "type.h"
#include "sdk_snd_internal.h"

typedef struct HsndSlotWork
{
    s16 state;               /* 0x00 */
    s16 param2;              /* 0x02 */
    s16 param1;              /* 0x04 */
    s16 pad6;                /* 0x06 */
    u32 completed;           /* 0x08 */
    s16 callbackMode;        /* 0x0C */
    s16 padE;                /* 0x0E */
    void* data0;             /* 0x10 */
    void* data1;             /* 0x14 */
    void* data2;             /* 0x18 */
    u32 data3;               /* 0x1C */
    u32 data4;               /* 0x20 */
    u32 data5;               /* 0x24 */
} HsndSlotWork;

extern void sdkSndLoadDecodeFiles(s16 index, s16 fileIndex);
extern s32 sdkSndIsDecodeSlotReady(s16 index);

extern u8 sdkSndPlayCue(s16 id, s32 unused);

#define HSND_SLOT_COUNT 6

static HsndSlotWork sSlotWork[HSND_SLOT_COUNT];
extern u8 sSlotWork_alt[];

#define HSND_CHANNEL_STARTING 1


/* Advances one sound slot: start playback (state 2), then wait for it to finish (state 3). */
// FUN_00459790
void hsndSlotUpdate(HsndSlotWork* slot)
{
    switch (slot->state)
    {
        case 0:
            slot->state = 1;
            break;

        case 1:
            break;

        case 2:
            if (slot->callbackMode == 0)
            {
                sdkSndLoadDecodeFiles(slot->param1, slot->param2);
            }
            else
            {
                sdkSndLoadDecodeBuffers(slot->param1, slot->param2, slot->data0, slot->data3,
                               slot->data1, slot->data4, slot->data2, slot->data5);
            }
            slot->state = 3;
            break;

        case 3:
            if (sdkSndIsDecodeSlotReady(slot->param1) != 0)
            {
                slot->completed = 1;
                slot->state = 1;
            }
            break;

        default:
            break;
    }
}


/* Queues sound id for playback through the sound manager; always reports success. */
// FUN_004599A0
u8 hsndQueueSound(s16 id, s16 unused)
{
    sdkSndPlayCue(id, 1);
    return 1;
}


/* Reports whether the slot is in the starting state (HSND_CHANNEL_STARTING). */
// FUN_0045A890
u32 hsndSlotIsStarting(s32 slotIndex)
{
    s16 index;

    index = slotIndex;
    return sSlotWork[index].state == HSND_CHANNEL_STARTING;
}
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
extern void (*D_008873FC[])(s32 param, u8* arg);
extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
/* Return channel three's requested track identifier, or minus one when its request is inactive. */
// FUN_0045B400
s16 hsndGetCurrentTrack(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}


