/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
u32 func_001d10d0(void* camera);
void func_00195850(u8* arg0, f32* arg1);
void func_001bcd40(u8* arg0, u8* arg1, f32* arg2, s32 arg3, f32 arg4);
extern s32 func_004bd050(s32 arg0);
extern u8 D_005FE1D0[];
extern u32 func_00231d70(s32 arg0);

/* Source unit: src/Battle/btlCamera_001be8d0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001BE8D0
void btlCameraSetDefaultDistanceA(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d05b0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D05B0
void btlCameraSetDefaultDistanceB(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d0670.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D05E0
void func_001d05e0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0xC1,
                          0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)));
        }
    }
}
// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d10d0.c */

// FUN_001D06A0
void func_001d06a0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0xC1,
                          0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)));
        }
    }
}
// FUN_001D0730
u8 *func_001d0730(s32 arg0, s32 arg1)
{
    if (arg1 != 0) {
        return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + 2) * 0x34));
    }
    return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + (func_004bd050(0) & 1)) * 0x34));
}
// FUN_001D07E0
INCLUDE_ASM("asm/nonmatchings/btlCamera_grouped", func_001d07e0);
// FUN_001D10D0
u32 func_001d10d0(void* camera)
{
    return (*(u16*)((u8*)camera + 0xE) & 1) != 0;
}

/* Source unit: src/Battle/btlCamera_001d12e0.c */

void FUN_0043f9c8(void* memory, s32 value, u32 size);

// FUN_001D10F0
void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    s32 flags;

    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(u8 **)(arg0 + 0x10) = arg3;
    *(s16 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xA) = -1;
    *(s16 *)(arg0 + 0xC) = 0;
    *(u16 *)(arg0 + 0xE) |= 1;
    *(u16 *)(arg0 + 0xE) &= 0xFFFD;
    flags = arg4 & 0xFFFF;
    if ((flags & 1) && !(arg3[1] & 1) && (func_00231d70(0x64) >= 0x32U)) {
        *(u16 *)(arg0 + 0xE) |= 2;
    }
    if (flags & 2) {
        *(u16 *)(arg0 + 0xE) |= 4;
    }
    if (flags & 4) {
        *(u16 *)(arg0 + 0xE) |= 8;
    }
    if (flags & 8) {
        *(u16 *)(arg0 + 0xE) |= 0x10;
    }
    if (flags & 0x10) {
        *(u16 *)(arg0 + 0xE) |= 0x20;
    }
}
// FUN_001D1200
INCLUDE_ASM("asm/nonmatchings/btlCamera_grouped", func_001d1200);
// FUN_001D12E0
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}
