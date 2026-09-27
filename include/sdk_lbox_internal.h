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

KwlnTask* func_00470250(KwlnTask* parent, u32 width, u32 height);
s32 func_00470280(u8* parent, s32 width, s32 height, s32 mode);
void func_00470810(KwlnTask* task, const KWindowEntryDescriptor* descriptors, u32 count);
s32* func_00470bd0(KwlnTask* task, u32 id);
void func_004703c0(u8* task, s32 state);
void func_004703d0(u8* task, s32 enabled);
void func_00470430(u8* task, s32 visibleRows);
s32 func_00470e20(u8* task);

#endif
