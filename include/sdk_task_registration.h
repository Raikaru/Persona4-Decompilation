#ifndef SDK_TASK_REGISTRATION_H
#define SDK_TASK_REGISTRATION_H
#include "type.h"
typedef struct KwlnTask KwlnTask;
typedef s32 (*SdkTaskUpdate)(u8 *task);
typedef void (*SdkTaskDestroy)(u8 *task);
void *func_00451de0(const void *name, s32 priority, s32 delay, s32 freeDelay,
                   SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work);
void *func_00451fc0(void *parent, const void *name, s32 priority, s32 delay,
                   s32 freeDelay, SdkTaskUpdate update, SdkTaskDestroy destroy,
                   u8 *work);
#endif
