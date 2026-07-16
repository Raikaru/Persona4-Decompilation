/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u32 func_001d4120(void* formation);
u32 func_001d4190(void* formation, u32 index);
void func_001d6ee0(void** units);
void func_001d7100(u8* packet, s16 value);
void func_001d72c0(void* packet, u32 value);
u32 func_001d8bc0(void* formation);
u32 func_001dc680(void* object);
u32 func_001deeb0(void* object);
u32 func_001d43f0(s32 param_1);
void func_001d4490(s32 param_1, u32 param_2);
s16 func_001d7130(s32 param_1);
void func_001d8be0(s32 param_1, u64* param_2);
void func_001d8bf0(s32 param_1, s32 param_2);
u32 func_001da9f0(s32 param_1);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

// FUN_001D4120
u32 func_001d4120(void* formation)
{
    return (*(u16*)((u8*)formation + 0x630) & 2) != 0;
}

// FUN_001D4190
u32 func_001d4190(void* formation, u32 index)
{
    u32 offset;

    offset = (index & 0xFFFF) * 0x314;
    return *(u32*)(offset + (u32)formation + 0xC);
}

// FUN_001D6EE0
void func_001d6ee0(void** units)
{
    u32 index;

    for (index = 0; index < 0x30; index++)
    {
        *(u16*)units[index] &= ~0x200;
    }
}

// FUN_001D7100
void func_001d7100(u8* packet, s16 value)
{
    if (*(s16*)(packet + 0x10) != value)
    {
        *packet |= 1;
        *(s16*)(packet + 0x10) = value;
    }
}

// FUN_001D72C0
void func_001d72c0(void* packet, u32 value)
{
    *(u32*)((u8*)packet + 0x14) = (value & 0xFF000000) | 0xFFFFFF;
}

// FUN_001D8BC0
u32 func_001d8bc0(void* formation)
{
    return *(u32*)((u8*)formation + (*(u16*)((u8*)formation + 0x3A) * 4));
}

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

// FUN_001D43F0
u32 func_001d43f0(s32 param_1)
{
    u16 flags = 0;
    u32 result = 0;

    if (*(s32*)(param_1 + 8) != 0)
    {
        result |= 0x80;
    }
    if (*(s32*)(param_1 + 0xc) != 0)
    {
        result |= 1;
    }
    flags = *(u16*)(param_1 + 4);
    if ((flags & 0x400) != 0)
    {
        result |= 2;
    }
    if ((flags & 0x100) != 0)
    {
        result |= 4;
    }
    if ((flags & 4) != 0)
    {
        result |= 0x10;
    }
    if ((flags & 2) != 0)
    {
        result |= 8;
    }
    if ((*(u16*)(param_1 + 6) & 2) != 0)
    {
        result |= 0x20;
    }
    if ((*(u16*)(param_1 + 6) & 4) != 0)
    {
        result |= 0x40;
    }
    return result;
}

/* Source unit: src/btlFormation/btlFormation_001d4490.c (1 function markers) */

// FUN_001D4490
void func_001d4490(s32 param_1, u32 param_2)
{
    *(u32*)(param_1 + 0x634) = param_2;
}

/* Source unit: src/btlFormation/btlFormation_001d7130.c (1 function markers) */

// FUN_001D7130
s16 func_001d7130(s32 param_1)
{
    return *(s16*)(param_1 + 0x10);
}

/* Source unit: src/btlFormation/btlFormation_001d8be0.c (1 function markers) */

// FUN_001D8BE0
void func_001d8be0(s32 param_1, u64* param_2)
{
    *(u64*)(param_1 + 0x30) = *param_2;
}

/* Source unit: src/btlFormation/btlFormation_001d8bf0.c (1 function markers) */

// FUN_001D8BF0
void func_001d8bf0(s32 param_1, s32 param_2)
{
    *(u64*)(param_1 + 0x30) = *(u64*)(param_2 + 0x30);
}

/* Source unit: src/btlFormation/btlFormation_001da9f0.c (1 function markers) */

// FUN_001DA9F0
u32 func_001da9f0(s32 param_1)
{
    return *(u8*)(param_1 + 0x28) > 0;
}
