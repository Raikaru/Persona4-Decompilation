#include "type.h"

extern void func_00106390(s32 arg0, s32 arg1);

extern s64 func_0029cc00(s32 arg0);
extern u8 *func_00105510(s16 arg0);
extern void func_00243ec0(u8 *arg0, s16 arg1);
extern s64 func_00243e90(u8 *arg0);
extern void func_0029cf50(s32 arg0);

extern u8 *D_0076449C;

extern f32 func_0047a080(s32 arg0, s32 arg1);

extern void func_0019d990(u8 *arg0, s32 arg1);
extern void func_0014b0c0(s32 arg0, s32 arg1);

extern u8 *func_0019d210(s32 arg0);
extern void func_0019ea60(u8 *arg0, u16 arg1);



// FUN_00192B20
void func_00192b20(void) {
    s32 i;

    for (i = 0x15C0; i <= 0x15FF; i++) {
        func_00106390(i, 0);
    }
    func_00106390(0x1435, 0);
    func_00106390(0x1438, 0);
}



// FUN_00193630
s32 func_00193630(void) {
    s64 temp_17;
    s64 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00243ec0(func_00105510((s16)temp_17), (s16)temp_16);
    return 1;
}



// FUN_001936A0
s32 func_001936a0(void) {
    func_0029cf50((s16)func_00243e90(func_00105510((s16)func_0029cc00(0))));
    return 1;
}



// FUN_00193730
void func_00193730(void) {
    *(s32 *)(D_0076449C + 0xC) |= 0x4000;
}



// FUN_00199830
s64 func_00199830(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x98) & 2) {
        return (s64)(s16)(s32)func_0047a080(*(s32 *)(arg0 + 0xA00), 0);
    }
    return 0;
}



// FUN_0019D040
void func_0019d040(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) &= ~0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 1);
        *(s32 *)(arg0 + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(arg0 + 0x9C) |= 2;
}



// FUN_0019D0C0
void func_0019d0c0(u8 *arg0) {
    *(s32 *)(arg0 + 0x9C) |= 0x1000;
    func_0019d990(arg0, 5);
    if (*(u16 *)(arg0 + 0x9FE) != 0) {
        func_0014b0c0(*(u16 *)(arg0 + 0x9FE), 0);
    }
    *(s32 *)(arg0 + 0x9C) &= ~2;
}



// FUN_0019EF30
void func_0019ef30(u8 *arg0, u16 arg1) {
    if (*(u8 **)(arg0 + 0xA0C) == NULL) {
        *(u8 **)(arg0 + 0xA0C) = func_0019d210(2);
    }
    func_0019ea60(*(u8 **)(arg0 + 0xA0C), arg1);
}
