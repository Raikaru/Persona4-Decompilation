#ifndef KWLN_TASK_INTERNAL_H
#define KWLN_TASK_INTERNAL_H

#include "sdk_task_registration.h"

/* Same scheduler object as src/Kernel/sdkTask.c. Callbacks receive the
 * allocation supplied to kwlnTaskCreate[Child] through work at offset 0x38. */
struct KwlnTask
{
    u8 unk0[0x18];
    s32 nameSum;
    u32 flags;
    u8 unk20[4];
    u32 unk24;
    u32 unk28;
    u16 unk2C;
    u16 unk2E;
    SdkTaskUpdate unk30;
    SdkTaskDestroy unk34;
    u8 *work;
    struct KwlnTask *listNext;
    struct KwlnTask *listPrev;
    struct KwlnTask *listPrev2;
    struct KwlnTask *parent;
    struct KwlnTask *childList;
    struct KwlnTask *next;
};

#endif
