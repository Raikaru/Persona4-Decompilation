#ifndef SDK_TASK_REGISTRATION_H
#define SDK_TASK_REGISTRATION_H
#include "type.h"
typedef struct KwlnTask KwlnTask;
typedef s32 (*SdkTaskUpdate)(u8 *task);
typedef void (*SdkTaskDestroy)(u8 *task);
void *kwlnTaskCreate(const void *name, s32 priority, s32 delay, s32 freeDelay,
                   SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work);
void *kwlnTaskCreateChild(void *parent, const void *name, s32 priority, s32 delay,
                   s32 freeDelay, SdkTaskUpdate update, SdkTaskDestroy destroy,
                   u8 *work);
#endif
