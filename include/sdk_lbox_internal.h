#ifndef SDK_LBOX_INTERNAL_H
#define SDK_LBOX_INTERNAL_H

#include "sdk_task_registration.h"

typedef void (*KWindowEntryCallback)(void* value);
typedef struct KWindowEntryDescriptor
{
    const char* name;
    s32 type;
    const char* text;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    KWindowEntryCallback callback;
} KWindowEntryDescriptor;

KwlnTask* sdkLboxCreate(KwlnTask* parent, u32 width, u32 height);
s32 sdkLboxCreateEx(u8* parent, s32 x, s32 y, s32 mode);
void sdkLboxAddDescriptors(KwlnTask* task, const KWindowEntryDescriptor* descriptors, u32 count);
s32* sdkLboxGetValuePtr(KwlnTask* task, u32 id);
void sdkLboxSetState(u8* task, s32 state);
void sdkLboxSetSelection(u8* task, s32 selection);
void sdkLboxSetVisibleRows(u8* task, s32 visibleRows);
s32 sdkLboxGetSelectedId(u8* task);

#endif
