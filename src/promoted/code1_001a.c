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
u8 *btlCameraCreateSetStatePacket(void *arg0, s32 arg1);



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



// FUN_001A2C10
void func_001a2c10(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001d7f10(arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}



// FUN_001A3DE0
s32 func_001a3de0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x420);
}

// FUN_001A4390
void func_001a4390(void)
{
}

// FUN_001A47F0
void func_001a47f0(void)
{
}

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

// FUN_001A7710
void func_001a7710(void)
{
}

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



// FUN_001AC6A0
void func_001ac6a0(u8 *arg0) {
    if ((*(s32 (**)(void))(arg0 + 0x440))() == 0) {
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x43C));
    }
}
