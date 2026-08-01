/* Source unit: src/h_snd_00459790.c */
#include "type.h"

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

extern void func_0045c130(s16 param1, s16 param2);
extern void func_0045c210(s16 param1, s16 param2, void* data0, u32 data0Size,
                          void* data1, u32 data1Size, void* data2, u32 data2Size);
extern s32 func_0045c390(s16 param1);

extern u8 func_0045a3e0(s16 id, s32 unused);

#define HSND_SLOT_COUNT 6

static HsndSlotWork sSlotWork[HSND_SLOT_COUNT];
extern u8 sSlotWork_alt[];

#define HSND_CHANNEL_STARTING 1



// FUN_00459790
void func_00459790(HsndSlotWork* slot)
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
                func_0045c130(slot->param1, slot->param2);
            }
            else
            {
                func_0045c210(slot->param1, slot->param2, slot->data0, slot->data3,
                               slot->data1, slot->data4, slot->data2, slot->data5);
            }
            slot->state = 3;
            break;

        case 3:
            if (func_0045c390(slot->param1) != 0)
            {
                slot->completed = 1;
                slot->state = 1;
            }
            break;

        default:
            break;
    }
}



// FUN_004599A0
u8 func_004599A0(s16 id, s16 unused)
{
    func_0045a3e0(id, 1);
    return 1;
}

#pragma alias sSlotWork_alt sSlotWork


// FUN_0045A890
u32 func_0045a890(s32 slotIndex)
{
    s16 index;

    index = slotIndex;
    return sSlotWork[index].state == HSND_CHANNEL_STARTING;
}
