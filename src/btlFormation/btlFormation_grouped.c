/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
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
u32 btlCond_MORE(s32 param_1);
extern void func_001d6880(void* param_1);
extern void func_001d3e00(u32 param_1);
extern u8* DAT_0076449c;
extern void (*jtbl_008873EC[])(void* ptr);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void func_0044ea90(const void* msg, s32 id);
extern void func_0043f9c8(void* dst, s32 value, u32 size);
extern void func_001d42e0(u8* arg0);
extern void func_001d40d0(u8* arg0);
extern u8* func_001d41b0(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00485b20(u32 arg0);
extern void func_004787e0(u32 arg0);

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

// FUN_001D6F20
u8* func_001d6f20(s32 arg0)
{
    u8* temp_2;
    u8* temp_2_2;
    u8* temp_2_3;
    u32 table;

    func_0044ea90(D_00609558, 0x48);
    table = (u32)jtbl_008873E8;
    temp_2 = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x18, 0x40000);
    *(s32*)(temp_2 + 4) = arg0;
    *(s16*)(temp_2 + 0x10) = -1;
    *(s8*)(temp_2 + 0) = 0;
    *(s32*)(temp_2 + 0x14) = -1;
    *(s32*)(temp_2 + 0xC) = 0;
    func_0044ea90(D_00609558, 0x51);
    temp_2_2 = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x24, 0x40000);
    func_0043f9c8(temp_2_2, 0, 0x24);
    *(s32*)(temp_2_2 + 4) = -1;
    *(s8*)(temp_2_2 + 8) = 0x14;
    *(s32*)(temp_2_2 + 0xC) = 0;
    *(u16*)(temp_2_2 + 0) = 0x200;
    *(s32*)(temp_2_2 + 0x1C) = 0;
    temp_2_3 = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    if (temp_2_3 != 0)
    {
        *(u8**)(temp_2_3 + 0x1C) = temp_2_2;
        *(u8**)(temp_2_2 + 0x20) = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    }
    else
    {
        *(u8**)(temp_2_2 + 0x20) = 0;
    }
    *(u8**)((u8*)DAT_0076449c + 0x1B8) = temp_2_2;
    *(u8**)(temp_2 + 8) = temp_2_2;
    return temp_2;
}
// FUN_001D7040
void func_001d7040(u8* arg0)
{
    u8* temp_16;
    u8* temp_3;
    u8* temp_3_2;
    u32 temp_4;
    u32 table;

    temp_16 = *(u8**)(arg0 + 8);
    func_001d6880(temp_16);
    temp_3 = *(u8**)(temp_16 + 0x20);
    if (temp_3 != 0)
    {
        *(u8**)(temp_3 + 0x1C) = *(u8**)(temp_16 + 0x1C);
    }
    temp_3_2 = *(u8**)(temp_16 + 0x1C);
    if (temp_3_2 != 0)
    {
        *(u8**)(temp_3_2 + 0x20) = *(u8**)(temp_16 + 0x20);
    }
    else
    {
        *(u8**)((u8*)DAT_0076449c + 0x1B8) = *(u8**)(temp_16 + 0x20);
    }
    table = (u32)jtbl_008873EC;
    ((void (**)(void*))table)[0](temp_16);
    temp_4 = *(u32*)(arg0 + 0xC);
    if (temp_4 != 0)
    {
        func_001d3e00(temp_4);
        *(u32*)(arg0 + 0xC) = 0;
    }
    ((void (**)(void*))table)[0](arg0);
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

/* measured: live MATCH, object 372B/window 384B, normalized_diff 0; integer-domain global base plus source-driven addu operand order. */
// FUN_001D7140
void func_001d7140(u8* arg0)
{
    s16 temp_4_5;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_6;
    u8* temp_17;
    u8* temp_4_7;
    s32 temp_4_6;
    u8* temp_4_8;
    s32 temp_4_9;

    if ((*(u32*)((u8*)DAT_0076449c + 0xC) & 0x40000) != 0)
    {
        if ((*arg0 & 1) != 0)
        {
            temp_17 = *(u8**)(arg0 + 8);
            temp_4 = *(s32*)(temp_17 + 0x10);
            if (temp_4 != 0)
            {
                func_001d42e0((u8*)temp_4);
                *(s32*)(temp_17 + 0x10) = 0;
            }
            temp_4_2 = *(s32*)(temp_17 + 0x14);
            if (temp_4_2 != 0)
            {
                func_00485b20((u32)temp_4_2);
                *(s32*)(temp_17 + 0x14) = 0;
            }
            temp_4_3 = *(s32*)(temp_17 + 0x18);
            if (temp_4_3 != 0)
            {
                func_004787e0((u32)temp_4_3);
                *(s32*)(temp_17 + 0x18) = 0;
            }
            *(s32*)(temp_17 + 4) = -1;
            *(s8*)(temp_17 + 8) = 0x14;
            *(s32*)(temp_17 + 0xC) = 0;
            *(u16*)(temp_17 + 0) = 0x200;
            temp_4_4 = *(s32*)(arg0 + 0xC);
            if (temp_4_4 != 0)
            {
                func_001d3e00((u32)temp_4_4);
                *(s32*)(arg0 + 0xC) = 0;
            }
            temp_4_5 = *(s16*)(arg0 + 0x10);
            if (temp_4_5 != -1)
            {
                temp_4 = (s32)DAT_0076449c;
                temp_4_9 = temp_4_5 * 4;
                temp_4_6 = *(s32*)((u8*)(temp_4_9 + temp_4 + 0xD04));
                *(s32*)(arg0 + 0xC) = temp_4_6;
                func_001d40d0((u8*)temp_4_6);
                temp_6 = *(s32*)(arg0 + 4);
                *(s32*)(*(u8**)(arg0 + 8) + 0x10) =
                    (s32)func_001d41b0(*(u8**)(arg0 + 0xC), 1, temp_6, temp_6, 0);
            }
            *arg0 &= (u8)~1;
        }
        if (*(s16*)(arg0 + 0x10) != -1)
        {
            temp_4_7 = *(u8**)(arg0 + 8);
            *(u16*)temp_4_7 |= 0x30;
            *(s32*)(*(u8**)(arg0 + 8) + 4) = *(s32*)(arg0 + 0x14);
            return;
        }
        temp_4_8 = *(u8**)(arg0 + 8);
        *(u16*)temp_4_8 &= (u16)~0x30;
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
u32 btlCond_MORE(s32 param_1)
{
    return *(u8*)(param_1 + 0x28) > 0;
}
