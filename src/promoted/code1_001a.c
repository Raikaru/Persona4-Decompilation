#include "include_asm.h"
#include "type.h"

void btlActionSetState(u8 *arg0, u16 arg1);

void func_001eb3b0(void *arg0);
void func_001d7f10(void *arg0, void *arg1, s32 arg2, s32 arg3);
void func_001d8cb0(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void func_001a03b0(s64 *arg0);
void func_001dbf20(void *arg0, s32 arg1);
u8 *func_001d3700(s32 arg0, s32 arg1);
void func_00194590(u8 *arg0, s32 arg1);
extern u8 *D_0076449C;
extern u8 *func_0019b6a0(s32 arg0);
u8 *btlCameraCreateSetStatePacket(void *arg0, s32 arg1);



// FUN_001A0140
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0140);
// FUN_001A0290
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0290);
// FUN_001A03B0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a03b0);
// FUN_001A05F0
s32 func_001a05f0(u8 *arg0) {
    u16 temp_5;
    u8 *temp_3;

    temp_5 = *(u16 *)(arg0 + 0x1A);
    if (temp_5 & 1) {
        goto cont1;
    }
    return 0;
cont1:
    temp_3 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C);
    if (temp_5 & 0x10) {
        goto cont2;
    }
    return 0;
cont2:
    return (*(s32 *)(temp_3 + 0x98) & 2) != 0;
}



// FUN_001A0640
void func_001a0640(void)
{
}

// FUN_001A0650
void func_001a0650(void)
{
}

// FUN_001A0660
void func_001a0660(void)
{
}

// FUN_001A0670
void func_001a0670(u8 *arg0) {
    s32 temp_5;

    temp_5 = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C);
    if (temp_5 & 0x10) {
        *(s16 *)(arg0 + 0x430) = 1;
        btlActionSetState(arg0, 0x18);
        return;
    }
    if (temp_5 & 1) {
        btlActionSetState(arg0, 0x23);
    }
}



// FUN_001A06D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a06d0);
// FUN_001A0B00
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0b00);
// FUN_001A0F40
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0f40);
// FUN_001A1450
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1450);
// FUN_001A17D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a17d0);
// FUN_001A1C80
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1c80);
// FUN_001A1EA0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1ea0);
// FUN_001A24A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a24a0);
// FUN_001A24B0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a24b0);
// FUN_001A2AD0
void func_001a2ad0(u8 *arg0) {
    func_001eb3b0(arg0 + 0x38);
    if ((*(s32 *)(D_0076449C + 0xC) & 0x1000) == 0) {
        return;
    }
    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return;
    }
    if (*(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return;
    }
    func_001b0800(arg0, 9);
}

// FUN_001A2B50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a2b50);
// FUN_001A2C10
void func_001a2c10(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001d7f10(arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}



// FUN_001A2C70
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a2c70);
// FUN_001A2D70
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a2d70);
// FUN_001A31A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a31a0);
// FUN_001A31E0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a31e0);
// FUN_001A3840
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3840);
// FUN_001A3D50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3d50);
// FUN_001A3DE0
s32 func_001a3de0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x420);
}

// FUN_001A3DF0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3df0);
// FUN_001A3F90
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3f90);
// FUN_001A4390
void func_001a4390(void)
{
}

// FUN_001A43A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a43a0);
// FUN_001A47F0
void func_001a47f0(void)
{
}

// FUN_001A4800
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4800);
// FUN_001A4C80
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4c80);
// FUN_001A55A0
void func_001a55a0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



// FUN_001A5650
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a5650);
// FUN_001A58E0
void func_001a58e0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



// FUN_001A5990
void func_001a5990(void)
{
}

// FUN_001A59A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a59a0);
// FUN_001A7710
void func_001a7710(void)
{
}

// FUN_001A7720
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a7720);
// FUN_001ABBB0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001abbb0);
// FUN_001AC500
void func_001ac500(s64 *arg0) {
    u8 *temp_2;
    u8 *temp_2_2;

    func_001a03b0(arg0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001dbf20(arg0, 0);
    func_001a03b0(arg0);
    temp_2 = func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = btlCameraCreateSetStatePacket(arg0, 0x2C);
    *(s64 *)(temp_2_2 + 0x60) = *arg0;
    func_00194590(temp_2_2, 0);
    *(u16 *)((u8 *)arg0 + 0x18) |= 2;
}



// FUN_001AC5B0
void func_001ac5b0(s64 *arg0) {
    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x800) == 0)) {
        *(u16 *)((u8 *)(arg0) + 0x18) = (u16) (*(u16 *)((u8 *)(arg0) + 0x18) | 0x100);
        func_001b0800(arg0, 0xFU);
    }
}

// FUN_001AC620
void func_001ac620(void) {
    u8 *p = *(u8 **)(D_0076449C + 0x174);
    u8 *o;

    while (p != NULL) {
        if (func_001a05f0(p) != 0) {
            o = func_0019b6a0(*(s32 *)(*(u8 **)(p + 0x30) + 0xA0C));
            *(s64 *)(o + 0x60) = *(s64 *)p;
            func_00194590(o, 1);
        }
        p = *(u8 **)(p + 0x450);
    }
}

// FUN_001AC6A0
void func_001ac6a0(u8 *arg0) {
    if ((*(s32 (**)(void))(arg0 + 0x440))() == 0) {
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x43C));
    }
}

// FUN_001AC6F0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ac6f0);
// FUN_001AC700
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ac700);
// FUN_001ACB10
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acb10);
// FUN_001ACBB0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acbb0);
// FUN_001ACF40
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acf40);
// FUN_001ACF50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acf50);
// FUN_001AD280
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad280);
// FUN_001AD3E0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad3e0);
// FUN_001AD540
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad540);
// FUN_001AD550
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad550);
// FUN_001ADB80
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001adb80);
// FUN_001ADE10
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ade10);
// FUN_001ADEA0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001adea0);
// FUN_001AE3C0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae3c0);
// FUN_001AE3D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae3d0);
// FUN_001AE800
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae800);
// FUN_001AEC20
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001aec20);
// FUN_001AED50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001aed50);
// FUN_001AF9D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001af9d0);
// FUN_001AF9E0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001af9e0);
// FUN_001AFA50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001afa50);
// FUN_001AFB50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001afb50);