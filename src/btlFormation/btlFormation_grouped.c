/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
u32 btlFormationGetCount(void* formation);
u32 btlFormationGetEntry(void* formation, u32 index);
void btlUnitResourceClearFlag(void** units);
void btlPacketSetValue(u8* packet, s16 value);
void btlPacketSetTag(void* packet, u32 value);
u32 btlFormationCurrentEntry(void* formation);
u32 func_001dc680(void* object);
u32 func_001deeb0(void* object);
u32 btlFormationGetFlags(s32 param_1);
void btlFormationSetSlot(s32 param_1, u32 param_2);
s16 btlPacketGetValue(s32 param_1);
void btlFormationEntrySetSelected(s32 param_1, u64* param_2);
void btlFormationEntryCopySelected(s32 param_1, s32 param_2);
u32 btlCond_MORE(s32 param_1);
extern void btlEffectResetEntry(void* param_1);
extern void btlFormationSetPlacement(u32 param_1);
extern u8* DAT_0076449c;
extern void (*jtbl_008873EC[])(void* ptr);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void chkmemAllocSiteTag(const void* msg, s32 id);
extern void memset(void* dst, s32 value, u32 size);
extern void btlFormationResetState(u8* arg0);
extern void btlFormationCopyDefault(u8* arg0);
extern u8* btlFormationAllocEntry(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void mdlEffectDestroyWithNodes(u32 arg0);
extern void mdlDestroyModelObject(u32 arg0);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */





// FUN_001DC680
u32 func_001dc680(void* object)
{
    *(void**)((u8*)object + 0x38) = object;
    *(u16*)((u8*)object + 0x6A) = 1;
    return 1;
}

// FUN_001DEEB0
u32 func_001deeb0(void* object)
{
    if (*(u8*)((u8*)object + 0x30) != 0)
    {
        return 1;
    }
    return (*(u32*)((u8*)object + 0x4C) != 0);
}

/* Source unit: src/btlFormation/btlFormation_001d43f0.c (1 function markers) */

/* Source unit: src/btlFormation/btlFormation_001d4490.c (1 function markers) */

/* Source unit: src/btlFormation/btlFormation_001d7130.c (1 function markers) */


/* Source unit: src/btlFormation/btlFormation_001d8be0.c (1 function markers) */


/* Source unit: src/btlFormation/btlFormation_001d8bf0.c (1 function markers) */


/* Source unit: src/btlFormation/btlFormation_001da9f0.c (1 function markers) */

