/* Source unit: src/Battle/btlMain_001b5e60.c */
#include "include_asm.h"
#include "type.h"

typedef struct BtlMain BtlMain;
struct BtlMain
{
    u8 _pad00[0xc];
    u32 flags;
};

extern u32 D_00764580;
extern u32 func_00193c70(void);
extern u32 func_001f6290(void);
extern void func_001f75b0(void);

typedef int (*code)(...);
typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x68];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_001b7520(float* param_1);
extern f32 fGpffff81f4; /* P4 gp -0x7e0c */
u32 func_001b7b30(void* work);
typedef struct BtlMainColorWork BtlMainColorWork;
extern u32 func_001b7e70(BtlMainColorWork* param_1); /* retail update target */
u32 func_001b87e0(void* work);
typedef struct BtlMainLerpWork BtlMainLerpWork;
extern u8 func_001b93c0(BtlMainLerpWork* param_1);
u32 func_001b96e0(void* work);
u32 func_001b99f0(void* work);
u32 func_001b9e50(void* work);

extern u32 func_003bb4a0(); /* old-style, matches donor call shape */

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RwV4d RwV4d;
struct RwV4d
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
extern void func_001ba790(f32* out, f32* first, f32* second, f32 weight);
extern f32 fGpffff80c0; /* P4 gp -0x7f40 */
extern f32 fGpffff80c8; /* P4 gp -0x7f38 */

extern f32 fGpffff8434; /* P4 gp -0x7bcc */

extern void func_001bb8c0(u8* param_2, f32* param_3, f32 param_1);
extern void func_001bb790(u8* param_2, f32* param_3, f32 param_1);
extern void func_003bb5b0(void* curve, s32 mode, f32 time, RwV3d* dst, void* aux);
extern void func_001bb9b0(u8* param_2, f32* param_3, f32 param_1);
extern f32 fGpffff8438; /* P4 gp -0x7bc8 */



// FUN_001B5E60
u32 btlMainUpdateStateExit(void* work)
{
    BtlMain* btl;

    if (func_00193c70() == 0 && func_001f6290() == 0)
    {
        func_001f75b0();
        btl = *(BtlMain**)((u8*)&D_00764580 - 0xe4);
        btl->flags &= ~1;
    }

    return 0;
}



// FUN_001B7880
BtlPacket* func_001b7880(u32 param_1, u32 param_2, u32 param_3)
{
    float *color;
    int packet;
    union { u32 value; u8 bytes[4]; } packed;

    packet = (int)func_00194470(0x600, 0x68);
    *(code **)(packet + 0x6c) = (code *)func_001b7520;
    color = *(float **)(packet + 0x78);
    packed.value = param_1;
    color[0] = fGpffff81f4 * (float)packed.bytes[0];
    color[1] = fGpffff81f4 * (float)packed.bytes[1];
    color[2] = fGpffff81f4 * (float)packed.bytes[2];
    color[3] = fGpffff81f4 * (float)packed.bytes[3];
    packed.value = param_2;
    color[4] = fGpffff81f4 * (float)packed.bytes[0];
    color[5] = fGpffff81f4 * (float)packed.bytes[1];
    color[6] = fGpffff81f4 * (float)packed.bytes[2];
    color[7] = fGpffff81f4 * (float)packed.bytes[3];
    *(u32*)((u8*)color + 0x60) = param_3;
    return (BtlPacket*)packet;
}



// FUN_001B7B30
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b7b30);
// FUN_001B7E20
void func_001b7e20(u32 value)
{
    BtlPacket* packet;

    packet = func_00194470(0x601, 0x28);
    packet->updateFunc = func_001b7b30;
    *(u32*)((u8*)packet->workData + 0x20) = value;
}



// FUN_001B7E70
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b7e70);
// FUN_001B83F0
BtlPacket* func_001b83f0(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5)
{
    float *pfVar1;
    int iVar2;
    union { u32 value; u8 bytes[4]; } packed;

    iVar2 = (int)func_00194470(0x602, 0x6c);
    *(code **)(iVar2 + 0x6c) = (code *)func_001b7e70;
    pfVar1 = *(float **)(iVar2 + 0x78);

    packed.value = param_1;
    pfVar1[0] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[1] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[2] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[3] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = param_2;
    pfVar1[8] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[9] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[10] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[0xb] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = param_3;
    pfVar1[0x10] = fGpffff81f4 * (float)packed.bytes[0];
    pfVar1[0x11] = fGpffff81f4 * (float)packed.bytes[1];
    pfVar1[0x12] = fGpffff81f4 * (float)packed.bytes[2];
    pfVar1[0x13] = fGpffff81f4 * (float)packed.bytes[3];

    *(u32 *)((u8 *)pfVar1 + 0x60) = param_4;
    *(u16 *)(pfVar1 + 0x1a) = param_5;
    return (BtlPacket*)iVar2;
}



// FUN_001B87E0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b87e0);
// FUN_001B9360
void func_001b9360(s32 arg, s16 mode)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x603, 0x5c);
    packet->updateFunc = func_001b87e0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0x50) = arg;
    *(s16*)(work + 0x58) = mode;
}



// FUN_001B93C0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b93c0);
// FUN_001B9560
BtlPacket* func_001b9560(u32 param_1, u32 param_2)
{
    float *color;
    u32 packed;
    int packet;
    packet = (int)func_00194470(0x604, 0x28);
    *(code **)(packet + 0x6c) = (code *)func_001b93c0;
    color = *(float **)(packet + 0x78);
    packed = param_1;
    color[0] = fGpffff81f4 * (float)((u8*)&packed)[0];
    color[1] = fGpffff81f4 * (float)((u8*)&packed)[1];
    color[2] = fGpffff81f4 * (float)((u8*)&packed)[2];
    color[3] = fGpffff81f4 * (float)((u8*)&packed)[3];
    *(u32*)((u8*)color + 0x20) = param_2;
    return (BtlPacket*)packet;
}



// FUN_001B96E0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b96e0);
// FUN_001B99A0
void func_001b99a0(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x605, 0x18);
    packet->updateFunc = func_001b96e0;
    *(s32*)((u8*)packet->workData + 0x10) = arg;
}



// FUN_001B99F0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b99f0);
// FUN_001B9DE0
void func_001b9de0(s32 arg1, s16 arg2, s32 arg3)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x606, 0x10);
    packet->updateFunc = func_001b99f0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = arg1;
    *(s32*)(work + 4) = arg3;
    *(s16*)(work + 0xc) = arg2;
    *(s32*)(work + 8) = 0;
}



// FUN_001B9E50
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001b9e50);
// FUN_001BA090
void func_001ba090(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x607, 8);
    packet->updateFunc = func_001b9e50;
    *(s32*)packet->workData = arg;
}



// FUN_001BA9E0
u32 func_001ba9e0(u16 *param_1, f32 *param_2, f32 *param_3)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    if (param_1[0x3b] >= 4)
    {
        return 0;
    }
    index = param_1[0x3c];
    if (param_2 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 4);
        value2 = param_2[0];
        value3 = param_2[1];
        value1 = param_2[2];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value1;
        if ((*param_1 & 1) == 0)
        {
            func_003bb4a0(*(u32*)(param_1 + 0x4c), index, param_2);
        }
    }
    if (param_3 != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)param_1;
        entry = (f32*)(address + 0x10);
        value2 = param_3[0];
        value3 = param_3[1];
        value4 = param_3[2];
        value1 = param_3[3];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value4;
        entry[3] = value1;
    }
    index++;
    if (index >= 4)
    {
        index = 0;
    }
    param_1[0x3c] = index;
    param_1[0x3b]++;
    return 1;
}



// FUN_001BAB00
void func_001bab00(u16 *param_1, f32 *param_2)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    *param_1 = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }
}



// FUN_001BAC20
void func_001bac20(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4)
{
    u16 index;
    u16 index0;
    u16 index1;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 work[7];

    *param_1 = param_4;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    *(u32*)((u8*)param_1 + 0x80) = 0;
    *(u32*)((u8*)param_1 + 0x7c) = 0;
    if (param_1[0x3b] < 4)
    {
        index0 = param_1[0x3c];
        if (param_2 != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_2[0];
            value3 = param_2[1];
            value1 = param_2[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index0, param_2);
            }
        }
        source = param_2 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index0++;
        if (index0 >= 4)
        {
            index0 = 0;
        }
        param_1[0x3c] = index0;
        param_1[0x3b]++;
    }

    func_001ba790(work, param_2, param_3, fGpffff80c0);
    if (param_1[0x3b] < 4)
    {
        index1 = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index1, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index1++;
        if (index1 >= 4)
        {
            index1 = 0;
        }
        param_1[0x3c] = index1;
        param_1[0x3b]++;
    }

    func_001ba790(work, param_2, param_3, fGpffff80c8);
    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (work != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }

    if (param_1[0x3b] < 4)
    {
        index = param_1[0x3c];
        if (param_3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 4);
            value2 = param_3[0];
            value3 = param_3[1];
            value1 = param_3[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*param_1 & 1) == 0)
            {
                func_003bb4a0(*(u32*)((u8*)param_1 + 0x98), index, param_3);
            }
        }
        source = param_3 + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)param_1;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        param_1[0x3c] = index;
        param_1[0x3b]++;
    }
}



// FUN_001BAFF0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001baff0);
// FUN_001BB3D0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001bb3d0);
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_001BB790 NONMATCHING
#ifdef NON_MATCHING
extern f32 D_00881430;
extern f32 D_00881434;
extern f32 D_00881438;
void func_001bb790(u8 *arg0, f32 *arg1, f32 fparg0)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 temp_f5;
    u16 index;
    s32 i;
    u8 *p;

    f3 = 1.0f - fparg0;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = fparg0 * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = fparg0 * fparg0;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = fparg0 * f1;
    index = *(u16 *)(arg0 + 0x74);
    arg1[0] = D_00881430;
    arg1[1] = D_00881434;
    arg1[2] = D_00881438;
    i = 0;
    while ((i & 0xFFFF) < 4) {
        temp_f5 = weights[i & 0xFFFF];
        p = (u8 *)((index & 0xFFFF) * 0x1C) + (u32)arg0;
        arg1[0] += *(f32 *)(p + 4) * temp_f5;
        arg1[1] += *(f32 *)(p + 8) * temp_f5;
        arg1[2] += *(f32 *)(p + 0xC) * temp_f5;
        index = (u16)((index + 1) & 0xFFFF);
        if ((s32)index >= 4) {
            index = 0;
        }
        i = (i + 1) & 0xFFFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001bb790);
#endif
// FUN_001BB8C0
void func_001bb8c0(u8* param_2, f32* param_3, f32 param_1)
{
    u16 currentIndex;
    u16 nextIndex;
    u32 currentAddress;
    u32 nextAddress;
    f32 currentX;
    f32 currentY;
    f32 currentZ;
    f32 nextX;
    f32 nextY;
    f32 nextZ;
    f32 blend;
    f32 period;
    currentIndex = *(u16*)(param_2 + 0x74);
    period = fGpffff8434;
    while (param_1 >= period)
    {
        currentIndex++;
        param_1 -= period;
    }
    param_1 /= period;
    if (currentIndex >= 4)
    {
        currentIndex &= 3;
    }
    nextIndex = currentIndex + 1;
    if (nextIndex >= 4)
    {
        nextIndex &= 3;
    }
    blend = 1.0f - param_1;
    currentAddress = (u32)currentIndex * 0x1c;
    currentAddress = currentAddress + (u32)param_2;
    currentY = *(f32*)(currentAddress + 8);
    currentY = currentY * blend;
    currentZ = *(f32*)(currentAddress + 0xc);
    currentZ = currentZ * blend;
    nextAddress = (u32)nextIndex * 0x1c;
    nextAddress = nextAddress + (u32)param_2;
    nextY = *(f32*)(nextAddress + 8);
    nextY = nextY * param_1;
    nextZ = *(f32*)(nextAddress + 0xc);
    nextZ = nextZ * param_1;
    currentX = *(f32*)(currentAddress + 4);
    nextX = *(f32*)(nextAddress + 4);
    param_3[0] = currentX * blend + nextX * param_1;
    param_3[1] = currentY + nextY;
    param_3[2] = currentZ + nextZ;
}



// FUN_001BB9B0
INCLUDE_ASM("asm/nonmatchings/btlMain", func_001bb9b0);
// FUN_001BBC40
u32 func_001bbc40(u8* param_1, f32* param_2, f32* param_3)
{
    void* curve;
    u16 frame;
    u16 index;
    u8* entry;
    frame = *(u16*)(param_1 + 0x76);
    if (0 < frame)
    {
        goto has_frame;
    }
    return 0;
has_frame:
    if (frame < 2)
    {
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV3d *)param_2 = *(RwV3d *)(entry + 4);
        index = *(u16*)(param_1 + 0x74);
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)param_1;
        *(RwV4d *)param_3 = *(RwV4d *)(entry + 0x10);
        return 0;
    }
    if (frame < 4)
    {
        func_001bb8c0(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else if ((*(u16*)param_1 & 1) != 0)
    {
        func_001bb790(param_1, param_2, *(f32*)(param_1 + 0x7c));
    }
    else
    {
        curve = *(void* *)(param_1 + 0x98);
        func_003bb5b0((void*)curve, 0xa,
                     *(f32*)(param_1 + 0x7c),
                     (RwV3d *)param_2, ((void*)0));
    }
    func_001bb9b0(param_1, param_3, *(f32*)(param_1 + 0x7c));
    return 1;
}



// FUN_001BBD80
u32 func_001bbd80(u8* param_2, f32 param_1)
{
    u16 frame;
    u16 counter;
    u32 result;
    f32 value;
    frame = *(u16*)(param_2 + 0x76);
    if (frame < 2)
    {
        *(u32*)(param_2 + 0x7c) = 0;
        return 0;
    }
    value = *(f32*)(param_2 + 0x7c) + param_1;
    if (frame < 3)
    {
        if (!(value < fGpffff8434))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 1;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 1;
        }
    }
    else if (frame < 4)
    {
        if (!(value < fGpffff80c8))
        {
            value = 0.0f;
            *(u16*)(param_2 + 0x76) = frame - 2;
            *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 2;
        }
    }
    else if (!(value < fGpffff8438))
    {
        value = value - 1.0f;
        *(u16*)(param_2 + 0x76) = frame - 3;
        *(u16*)(param_2 + 0x74) = *(u16*)(param_2 + 0x74) + 3;
    }
    counter = *(u16*)(param_2 + 0x74);
    if (counter >= 4)
    {
        *(u16*)(param_2 + 0x74) = counter & 3;
    }
    *(f32*)(param_2 + 0x7c) = value;
    result = 1;
    return result;
}



// FUN_001BBEF0
void func_001bbef0(u8* work, f32 value)
{
    *(f32*)(work + 0x84) = (value * 2.0f * 60.0f) / 2.0f;
    *(u32*)(work + 0x94) = 0x3f000000;
    *(u16*)work = *(u16*)work & 0xfff5;
    *(u16*)work = *(u16*)work | 4;
}
