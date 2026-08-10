#include "include_asm.h"
#include "type.h"
static inline s32 p4_001da5f0_xor(s32 left, s32 right)
{
    return left ^ right;
}
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern s64 func_0023a6b0(s32 arg0, s64 arg1);
extern u16 func_00231f80(u8 *arg0);
extern u16 func_00232290(u8 *arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 func_002428f0(u8 *arg0, s32 arg1);
extern s32 func_00231e20(u8 *arg0);
extern s32 func_00232710();
extern s32 func_002340c0(s32 arg0, s32 arg1);
extern void func_001d6de0(s32 arg0, s32 arg1);
extern s32 func_001d6360(u8 *arg0);
extern void func_001d42e0(s32 arg0);
extern void func_00485b20(s32 arg0);
extern void func_004787e0(s32 arg0);
extern void func_001d6880(u8 *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_001d3e00(s32 arg0);
extern void func_001d6910(u8 *arg0);
extern void func_001d75d0(u8 *arg0);
extern void func_00454bd0(u8 *arg0);
extern u32 iGpffffb3b8;
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);

extern void func_00195850(u8 *arg0, f32 *arg1);
extern s32 func_0047a6d0();
extern void func_004789c0(u8 *arg0);
extern void func_0047a320(u8 *arg0);
extern void func_003dcb40(f32 *arg0, f32 *arg1, s32 arg2, u8 *arg3);
extern void func_001d44a0(f32 arg0, f32 arg1, f32 *arg2, s32 *arg3, u8 *arg4, u8 *arg5);
extern f32 func_00196040(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, s32 arg4, s32 arg5);
extern void func_00194ee0(u8 *arg0, f32 *arg1);
extern void func_00195b60(u8 *arg0, s32 arg1, u8 *arg2);
extern u8 *func_0019eda0(u8 *arg0, s32 arg1);
extern void func_003e40b0(f32 *arg0, f32 *arg1);
extern void func_0044ea90(u8 *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern s8 func_00231d70(s32 arg0);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern void func_0048a250(u8 *arg0);
extern void func_003dc740(void *arg0, void *arg1, s32 arg2, f32 arg3);


extern void func_001d9b60(u8 *arg0);
extern u8 *func_00457120(void);
extern void func_003e8110(u8 *arg0);
extern void func_003e8120(u8 *arg0);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)(...);

extern int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6);
extern s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);



extern s32 func_001da230(u8 *arg0, s16 arg1);

extern s32 func_001d9740(u8 *arg0, s32 arg1);

extern s32 func_001d97b0(u8 *arg0, s32 arg1);
extern void func_001da270(void);
extern void func_001da2b0(void);
extern void func_001da2f0(void);
extern s32 func_001da5f0(u8 *arg0, s32 arg1);
extern s64 func_0023d8e0(s32 arg0, u16 arg1);
extern s32 func_00122640(s32 arg0, s32 arg1);

extern void func_001d7bb0(void);
extern void *func_00194470();

extern s32 func_001d7b30(u16 *arg0);

// FUN_001D01C0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d01c0);
// FUN_001D1310
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1310);
/* measured: opt_propagation off probe for func_001d14b0 loop masks. */
#pragma opt_propagation off
// FUN_001D14B0
s32 func_001d14b0(u8 *arg0)
{
    s32 index;
    u16 masked_index;
    u16 test_index;
    u8 *table;
    u8 *entry;

    index = 0;
    table = D_00607E50;
    goto test;
loop:
    masked_index = (u16)index;
    entry = table + (masked_index * 0xE0);
    if (*(u16 *)(arg0 + 0) > *(u16 *)(entry + 0xD8)) {
        goto next;
    }
    if (*(u16 *)(arg0 + 2) > *(u16 *)(entry + 0xDA)) {
        goto next;
    }
    if (*(u16 *)(arg0 + 4) > *(u16 *)(entry + 0xDC)) {
        goto next;
    }
    return index;
next:
    index = (index + 1) & 0xFFFF;
test:
    test_index = (u16)index;
    if (test_index < 0x19U) {
        goto loop;
    }
    return 0x18;
}
/* measured: close opt_propagation after func_001d14b0 probe. */
#pragma opt_propagation on
// FUN_001D1540
void func_001d1540(u8 *arg0, s32 arg1, s32 arg2) {
    u8 temp_4;

    temp_4 = *(u8 *)(arg0 + 0xA2);
    switch (temp_4) {
    case 0:
        ((s32 *)(iGpffffb3ac + 0xA74))[(u16)arg1] = arg2;
        return;
    case 1:
        ((s32 *)(iGpffffb3ac + 0xA84))[(u16)arg1] = arg2;
        return;
    }
}
// FUN_001D15A0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d15a0);
// FUN_001D1680
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1680);
// FUN_001D1CC0
s32 func_001d1cc0(u8 *arg0)
{
    struct Frame {
        f32 value40;
        f32 pad44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
    } frame;
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_4;
    u8 *bounds;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f3;

    temp_17 = *(u8 **)(arg0 + 0);
    temp_16 = *(u8 **)(arg0 + 4);
    func_00195b60(temp_16, (s32)temp_17, (u8 *)&frame.value40);
    frame.value60 = *(f32 *)(temp_17 + 4) - frame.value40;
    frame.value64 = 0.0f;
    frame.value68 = *(f32 *)(temp_17 + 0xC) - frame.value48;
    func_003e40b0(&frame.value60, &frame.value60);
    if ((frame.value60 == 0.0f) && (frame.value68 == 0.0f)) {
        return 1;
    }
    bounds = func_0019eda0(temp_16, 0xA);
    temp_f3 = (f32)*(s16 *)(bounds + 4);
    temp_f2 = *(f32 *)(temp_16 + 0x2C);
    temp_f1 = *(f32 *)(arg0 + 8);
    temp_f1 -= temp_f3 * temp_f2;
    temp_f3 = frame.value60 * temp_f1;
    frame.value60 = temp_f3;
    temp_f2 = frame.value64 * temp_f1;
    frame.value64 = temp_f2;
    temp_f1_2 = frame.value68 * temp_f1;
    frame.value68 = temp_f1_2;
    if ((*(u16 *)(arg0 + 0xC) & 1) != 0) {
        frame.value50 = *(f32 *)(temp_17 + 4) + frame.value60;
        frame.value54 = *(f32 *)(temp_17 + 8) + frame.value64;
        frame.value58 = *(f32 *)(temp_17 + 0xC) + frame.value68;
        func_00194ee0(temp_17, &frame.value50);
        temp_4 = *(u8 **)(temp_17 + 0xA0C);
        if (temp_4 != NULL) {
            frame.value50 = *(f32 *)(temp_4 + 4) + frame.value60;
            frame.value54 = *(f32 *)(temp_4 + 8) + frame.value64;
            frame.value58 = *(f32 *)(temp_4 + 0xC) + frame.value68;
            func_00194ee0(temp_4, &frame.value50);
        }
    }
    if ((*(u16 *)(arg0 + 0xC) & 2) != 0) {
        frame.value50 = *(f32 *)(temp_16 + 4) + frame.value60;
        frame.value54 = *(f32 *)(temp_16 + 8) + frame.value64;
        frame.value58 = *(f32 *)(temp_16 + 0xC) + frame.value68;
        func_00194ee0(temp_16, &frame.value50);
    }
    return 1;
}
// FUN_001D41B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d41b0);
/* measured: in-file body recheck is object 732B/window 736B with
   normalized_diff 43, over the park threshold; body archived at
   build/WS19_001d44a0_nd43.c and restored to INCLUDE_ASM. */
// FUN_001D44A0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d44a0);
// FUN_001D4780
void func_001d4780(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    s32 temp_2;
    f32 var_f20;
    f32 temp_f21;
    u8 *temp_s0;

    temp_s0 = arg2 + 8;
    temp_2 = *(u16 *)(arg2 + 0xC);
    if (temp_2 == 0) {
        var_f20 = *(f32 *)(arg0 + 0x30) * *(f32 *)(arg1 + 0x2C);
    } else {
        var_f20 = (f32)temp_2;
    }
    temp_f21 = 0.5f * (*(f32 *)(arg0 + 0x2C) * *(f32 *)(arg1 + 0x2C));
    frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
    frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
    frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
    func_003dcb40(&frame.value50, &frame.value60, 1, arg0 + 0x40);
    frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
    frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
    frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
    func_001d44a0(var_f20, temp_f21, &frame.value70, (s32 *)(arg0 + 0x40), temp_s0, arg3);
}
// FUN_001D48B0
void func_001d48b0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value30;
        f32 value34;
        f32 value38;
        f32 pad3C;
        f32 value40;
        f32 value44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
    } frame;
    u16 temp_2;
    u8 *temp_16;

    temp_16 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        func_00195850(arg1, &frame.value50);
    } else {
        temp_2 = *(u16 *)(temp_16 + 4);
        if (func_0047a6d0(*(u8 **)(arg1 + 0xA00), temp_2, &frame.value50) == 0) {
            frame.value40 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value44 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value48 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            func_003dcb40(&frame.value30, &frame.value40, 1, arg0 + 0x40);
            frame.value50 = frame.value30 + *(f32 *)(arg0 + 0x34);
            frame.value54 = frame.value34 + *(f32 *)(arg0 + 0x38);
            frame.value58 = frame.value38 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value50;
    *(f32 *)(arg3 + 4) = frame.value54;
    *(f32 *)(arg3 + 8) = frame.value58;
}
// FUN_001D49C0
void func_001d49c0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        func_00195850(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x29C);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        func_004789c0(var_19);
        func_0047a320(var_19);
        if (func_0047a6d0(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            func_003dcb40(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value70;
    *(f32 *)(arg3 + 4) = frame.value74;
    *(f32 *)(arg3 + 8) = frame.value78;
}
// FUN_001D4B00
void func_001d4b00(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *temp_2;
    u8 *var_19;
    u8 *temp_s2;

    temp_s2 = (u8 *)(arg2 + 8);
    if ((*(s32 *)(arg1 + 0x98) & 2) == 0) {
        func_00195850(arg1, &frame.value70);
    } else {
        temp_2 = *(u8 **)(arg1 + 0xA00);
        var_19 = *(u8 **)(temp_2 + 0x290);
        if (var_19 == NULL) {
            var_19 = temp_2;
        }
        func_004789c0(var_19);
        func_0047a320(var_19);
        if (func_0047a6d0(var_19, *(u16 *)(temp_s2 + 4), &frame.value70) == 0) {
            frame.value60 = *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x50);
            frame.value64 = *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x50);
            frame.value68 = *(f32 *)(arg0 + 0x28) * *(f32 *)(arg0 + 0x50);
            func_003dcb40(&frame.value50, &frame.value60, 1, arg0 + 0x40);
            frame.value70 = frame.value50 + *(f32 *)(arg0 + 0x34);
            frame.value74 = frame.value54 + *(f32 *)(arg0 + 0x38);
            frame.value78 = frame.value58 + *(f32 *)(arg0 + 0x3C);
        }
    }
    *(f32 *)(arg3 + 0) = frame.value70;
    *(f32 *)(arg3 + 4) = frame.value74;
    *(f32 *)(arg3 + 8) = frame.value78;
}
// FUN_001D4C40
void func_001d4c40(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        f32 value40;
        f32 pad44;
        f32 pad48;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 temp;
    u8 *temp16;

    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(3, 0, (u8 *)&frame.value40, (u8 *)&frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, &frame.value40, &frame.zero0, temp16, arg3);
}
// FUN_001D4CF0
void func_001d4cf0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        f32 value40;
        f32 pad44;
        f32 pad48;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(mode & 0xFFFF, 0, (u8 *)&frame.value40, (u8 *)&frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, &frame.value40, &frame.zero0, temp16, arg3);
}
// FUN_001D4DC0
void func_001d4dc0(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        f32 value40;
        f32 pad44;
        f32 pad48;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *temp16;

    if (*(u8 *)(arg1 + 0xA2) == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    temp16 = (u8 *)(arg2 + 8);
    base = func_00196040(mode & 0xFFFF, 0, (u8 *)&frame.value40, (u8 *)&frame.value4C, 0, 0);
    temp = *(u16 *)(temp16 + 4);
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    func_001d44a0(value, 0.5f * frame.value4C, &frame.value40, &frame.zero0, temp16, arg3);
}
// FUN_001D4E90
void func_001d4e90(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    *(s32 *)((u8 *)arg3 + 0) = 0;
    *(s32 *)((u8 *)arg3 + 4) = 0;
    *(s32 *)((u8 *)arg3 + 8) = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}

// FUN_001D4EB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4eb0);
// FUN_001D5130
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5130);
// FUN_001D53E0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d53e0);
// FUN_001D5990
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5990);
// FUN_001D5AC0
void func_001d5ac0(void) {
    func_003e8110(func_00457120());
    func_003e9cb0(*(s32 *)(func_00457120() + 4), D_008813B0, 0);
    func_003e8120(func_00457120());
}

// FUN_001D5B20
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5b20);
// FUN_001D6300
void func_001d6300(u8 *arg0) {
    u8 *temp_3;

    *(s32 *)(arg0 + 0x1C) = 0;
    func_001d40d0(*(u8 **)(arg0 + 0));
    temp_3 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_3 + 0xA0) = (u16) (*(u16 *)(temp_3 + 0xA0) + 1);
    *(s32 *)(arg0 + 0x18) = func_001d6ce0(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA08));
}

// FUN_001D6360
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6360);
// FUN_001D6570
void func_001d6570(u8 *arg0)
{
    func_001d6de0(*(s32 *)(*(u8 **)(arg0 + 4) + 0xA08), *(s32 *)(arg0 + 0x18));
    func_001d3e00(*(s32 *)arg0);
    *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) =
        *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) - 1;
}

// FUN_001D65D0
void func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)func_00194470(0x302, 0x28);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void (**)(u8 *))(packet + 0x68) = func_001d6300;
    *(s32 (**)(u8 *))(packet + 0x6C) = func_001d6360;
    *(void (**)(u8 *))(packet + 0x70) = func_001d6570;
    work = *(u8 **)(packet + 0x78);
    *(s32 *)(work + 0) = arg0;
    *(s32 *)(work + 4) = arg1;
    *(s32 *)(work + 8) = arg2;
    *(s64 *)(work + 0x10) = arg3;
    *(s32 *)(work + 0x20) = arg4;
}
// FUN_001D6680
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6680);
// FUN_001D6910
void func_001d6910(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x10) != 0) {
        func_001d42e0(*(s32 *)(arg0 + 0x10));
        *(s32 *)(arg0 + 0x10) = 0;
    }
    if (*(s32 *)(arg0 + 0x14) != 0) {
        func_00485b20(*(s32 *)(arg0 + 0x14));
        *(s32 *)(arg0 + 0x14) = 0;
    }
    if (*(s32 *)(arg0 + 0x18) != 0) {
        func_004787e0(*(s32 *)(arg0 + 0x18));
        *(s32 *)(arg0 + 0x18) = 0;
    }
    *(s32 *)(arg0 + 4) = -1;
    *(u8 *)(arg0 + 8) = 0x14;
    *(s32 *)(arg0 + 0xC) = 0;
    *(u16 *)(arg0 + 0) = 0x200;
    if (*(u8 **)(arg0 + 0x20) != NULL) {
        *(u8 **)(*(u8 **)(arg0 + 0x20) + 0x1C) = *(u8 **)(arg0 + 0x1C);
    }
    if (*(u8 **)(arg0 + 0x1C) != NULL) {
        *(u8 **)(*(u8 **)(arg0 + 0x1C) + 0x20) = *(u8 **)(arg0 + 0x20);
    } else {
        *(u8 **)(iGpffffb3ac + 0x1B8) = *(u8 **)(arg0 + 0x20);
    }
    (*jtbl_008873EC)(arg0);
}
// FUN_001D6A60
void func_001d6a60(void)
{
}

// FUN_001D6A70
void func_001d6a70(void)
{
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x1B8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x20);
        func_001d6910(var_4);
        var_4 = temp_16;
    }
    func_001d75d0(var_4);
}

// FUN_001D6AD0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6ad0);
// FUN_001D6C10
void func_001d6c10(u8 *arg0)
{
    u32 i;
    u8 *entry;
    u8 *next;
    u8 *prev;

    i = 0;
    while (i < 0x30U) {
        entry = *(u8 **)(arg0 + (i * 4));
        func_001d6880(entry);
        next = *(u8 **)(entry + 0x20);
        if (next != NULL) {
            *(u8 **)(next + 0x1C) = *(u8 **)(entry + 0x1C);
        }
        prev = *(u8 **)(entry + 0x1C);
        if (prev != NULL) {
            *(u8 **)(prev + 0x20) = *(u8 **)(entry + 0x20);
        } else {
            *(u8 **)(iGpffffb3ac + 0x1B8) = *(u8 **)(entry + 0x20);
        }
        (*jtbl_008873EC)(entry);
        i++;
    }
    (*jtbl_008873EC)(arg0);
}
// FUN_001D72E0
s32 func_001d72e0(s32 arg0)
{
    if (arg0 == 0) {
        return -1;
    }
    switch (arg0) {
    case 2:
        return 0x12;
    case 4:
        return 0x13;
    case 8:
        return 0x14;
    case 0x10:
        return 0x15;
    case 1:
        return 0x16;
    case 0x20:
        return 0x17;
    case 0x40:
        return 0x18;
    case 0x80:
        return 0x19;
    case 0x100:
        return 0x1A;
    case 0x80000:
    case 0x100000:
    default:
        return -1;
    }
}
/* measured: exhaustive switch labels reproduce the retail dispatch and code blocks; object 452B/window 464B, normalized_diff 4. The four default GP loads and stores retain a b210 register-colouring residual. Candidate parked. */
// Committed at nd 4.
// FUN_001D7400 NONMATCHING
#ifdef NON_MATCHING
void func_001d7400(s32 arg0, u8 *arg1)
{
    u8 temp_0;
    u8 temp_1;
    u8 temp_2;
    u8 temp_3;

    *(u8 *)(arg1 + 3) = 0xFF;
    switch (arg0) {
    case 2:
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xB2;
        *(u8 *)(arg1 + 2) = 0x9E;
        break;
    case 4:
        *(u8 *)(arg1 + 0) = 0xB2;
        *(u8 *)(arg1 + 1) = 0xA8;
        *(u8 *)(arg1 + 2) = 0xFF;
        break;
    case 8:
        *(u8 *)(arg1 + 0) = 0xB2;
        *(u8 *)(arg1 + 1) = 0xFF;
        *(u8 *)(arg1 + 2) = 0xB2;
        break;
    case 0x10:
        *(u8 *)(arg1 + 0) = 0xEE;
        *(u8 *)(arg1 + 1) = 0x9B;
        *(u8 *)(arg1 + 2) = 0xDA;
        break;
    case 1:
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0x94;
        *(u8 *)(arg1 + 2) = 0x76;
        break;
    case 0x20:
        *(u8 *)(arg1 + 0) = 0xBC;
        *(u8 *)(arg1 + 1) = 0xA8;
        *(u8 *)(arg1 + 2) = 0xFF;
        break;
    case 0x40:
        *(u8 *)(arg1 + 0) = 0x9E;
        *(u8 *)(arg1 + 1) = 0xE4;
        *(u8 *)(arg1 + 2) = 0xE1;
        break;
    case 0x80:
        *(u8 *)(arg1 + 0) = 0xCD;
        *(u8 *)(arg1 + 1) = 0xB9;
        *(u8 *)(arg1 + 2) = 0xD7;
        break;
    case 0x100:
        *(u8 *)(arg1 + 0) = 0x94;
        *(u8 *)(arg1 + 1) = 0x10;
        *(u8 *)(arg1 + 2) = 0x26;
        break;
    case 0x100000:
    case 0x80000:
    default:
        temp_0 = iGpffffa4d8;
        temp_1 = iGpffffa4d9;
        temp_2 = iGpffffa4da;
        temp_3 = iGpffffa4db;
        *(u8 *)(arg1 + 0) = temp_0;
        *(u8 *)(arg1 + 1) = temp_1;
        *(u8 *)(arg1 + 2) = temp_2;
        *(u8 *)(arg1 + 3) = temp_3;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7400);
#endif
// FUN_001D75D0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d75d0);
// FUN_001D7700
void func_001d7700(void)
{
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffffb3ac;
    if ((*(s32 *)(temp_5 + 0x14) & 0x4000000) == 0) {
        temp_4 = *(u8 **)(temp_5 + 0xDC4);
        if (temp_4 != NULL) {
            func_00454bd0(temp_4);
        }
        *(u8 **)(iGpffffb3ac + 0xDC4) = NULL;
        return;
    }
    *(u8 **)(temp_5 + 0xDC4) = NULL;
}

// FUN_001D7A60
s32 func_001d7a60(u8 *arg0) {
    func_00122520(1, *(u16 *)(arg0 + 4));
    func_001228a0(*(u8 *)(arg0 + 0), *(u8 *)(arg0 + 1), *(u8 *)(arg0 + 2));
    return 1;
}

// FUN_001D7B30
s32 func_001d7b30(u16 *arg0) {
    func_00122640(1, *arg0);
    return 1;
}
// FUN_001D7B60
void func_001d7b60(u16 param_1)
{
  int iVar1 = 0;

  iVar1 = (int)func_00194470(0x30B, 2);
  *(code *)(iVar1 + 0x6c) = (code)func_001d7b30;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return;
}

// FUN_001D7BF0
void func_001d7bf0(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0x309, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d7bb0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
}
// FUN_001D7C60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7c60);
// FUN_001D7F10
u8 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3)
{
    u32 effect;
    s32 offset;
    u32 bVar4;
    if (arg1 != NULL) {
        offset = (arg2 & 0xFFFF) * 0x28;
        effect = *(u8 *)((u8 *)p4_001d7f10_add(
            offset, (s32)iGpffffb3b8) + 9);
        bVar4 = *(u8 *)((u8 *)(u32)iGpffffb3b8 + offset + 0xA);
        if (arg3 != 0) {
            arg3 = (u8)effect;
            if (((arg3 & 1) != 0) && ((arg3 & 2) == 0)) {
                effect = (u8)(effect & 0xFE);
                effect = (u8)(effect | 2);
            } else if (((arg3 & 2) != 0) && ((arg3 & 1) == 0)) {
                effect = (u8)(effect & 0xFD);
                effect = (u8)(effect | 1);
            }
            if (((u8)bVar4 & 1) != 0) {
                bVar4 = (u8)(bVar4 & 0xFE);
                bVar4 = (u8)(bVar4 | 2);
            }
        }
        func_001d7c60(arg0, arg1, effect, bVar4,
                      *(u16 *)((u8 *)p4_001d7f10_add(
                          (s32)offset, (s32)iGpffffb3b8) + 0xC));
    }
    arg0 = (u8 *)(u32)iGpffffb3b8;
    return (arg0 + (arg2 & 0xFFFF) * 0x28)[8];
}
// FUN_001D8010
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8010);
// FUN_001D8C00
u8 *func_001d8c00(u8 *arg0)
{
    u16 flags;
    u8 *data;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            data = *(u8 **)(*(u8 **)(unit + 0x30) + 0xA64);
            if ((data == NULL || func_002428f0(data, 0) == 0) &&
                *(s64 *)unit == *(s64 *)(arg0 + 0x30)) {
                return unit;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return NULL;
}
/* measured: whole translation unit with -DNON_MATCHING: object 312B/window 320B, normalized_diff 158.
   The earlier figure of 18 predates later declaration-environment changes in this file. */
// Committed at nd 158.
// FUN_001D8CB0
#ifdef NON_MATCHING
s32 func_001d8cb0(u8 *arg0, u8 *arg1)
{
    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern f32 func_001ec250(f32 *arg0, f32 *arg1);
    struct Vec4 {
        f32 x;
        f32 y;
        f32 z;
        f32 pad;
    };
    struct Vec4 sp60;
    struct Vec4 sp50;
    f32 temp_f0;
    f32 var_f20;
    s32 first;
    s32 index;
    u64 key;
    u16 count;
    s32 key_index;

    *(u16 *)(arg1 + 0x3A) = 0;
    key = *(u64 *)(arg1 + 0x30);
    if (key == 0)
        goto no_key;
    key_index = 0;
    count = *(u16 *)(arg1 + 0x38);
    goto key_test;
key_loop:
    if (key != *(u64 *)(u8 *)(u32)*(u32 *)(arg1 + ((key_index & 0xFFFF) * 4)))
        goto key_next;
    *(u16 *)(arg1 + 0x3A) = (u16)key_index;
    return 1;
key_next:
    key_index = (key_index + 1) & 0xFFFF;
key_test:
    if ((u16)key_index < count)
        goto key_loop;
no_key:
    if (arg0 == NULL)
        goto return_one;
    first = 1;
    func_001958f0((u8 *)(u32)*(u32 *)(arg0 + 0x30), &sp60.x);
    index = 0;
    goto distance_test;
distance_loop:
    func_001958f0(
        (u8 *)(u32)*(u32 *)((u8 *)(u32)*(u32 *)(arg1 + ((index & 0xFFFF) * 4)) + 0x30),
        &sp50.x);
    temp_f0 = func_001ec250(&sp60.x, &sp50.x);
    if ((temp_f0 < var_f20) || (first != 0)) {
        *(u16 *)(arg1 + 0x3A) = (u16)index;
        var_f20 = temp_f0;
        first = 0;
    }
    index = (index + 1) & 0xFFFF;
distance_test:
    if ((u16)index < *(u16 *)(arg1 + 0x38))
        goto distance_loop;
return_one:
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8cb0);
#endif
// FUN_001D8E50
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8e50);
// FUN_001D9280
u8 *func_001d9280(s32 arg0, s32 arg1, s32 arg2) {
    s32 work_flags;
    u8 *unit;
    u8 *work;
    u16 flags;
    u32 mask;
    u32 filter;
    s32 id;

    work_flags = arg2;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    mask = (u16)arg1;
    filter = work_flags & 0x80000;
    id = (u16)arg0;
    goto next_branch;
loop:
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(work + 0xA2))) != 0) {
                if (filter != 0) {
                    if (func_002428f0(*(u8 **)(work + 0xA64), 0) != 0) {
                        goto next;
                    }
                }
                if (func_00232710(*(u8 **)(work + 0xA64), work_flags) != 0) {
                    goto next;
                }
                if (*(u16 *)(work + 0xA4) == id) {
                    return unit;
                }
            }
        }
    }
next:
    unit = *(u8 **)(unit + 0x450);
next_branch:
    if (unit != NULL) {
        goto loop;
    }
    return NULL;
}
// FUN_001D9390
int func_001d9390(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 (*arg5)(u8 *, s32), u8 **arg6) {
    struct Frame {
        u8 *entries[14];
        u16 count;
    } frame;
    u8 *unit;
    s32 index;
    s32 matches;
    u8 *work;
    u16 flags;

    func_001d7c60((u8 *)arg0, (u8 *)&frame.entries[0], arg3, 0, 0);
    matches = 0;
    index = 0;
    goto test;
loop:
    unit = frame.entries[(u16)index];
    flags = *(u16 *)(unit + 0x1A);
    if ((flags & 1) != 0) {
        if ((flags & 8) != 0) {
            work = *(u8 **)(unit + 0x30);
            if (func_00232710(*(u8 **)(work + 0xA64), arg2) == 0) {
                if (arg5(unit, arg1) != arg4) {
                    if (arg6 != NULL) {
                        arg6[(u16)matches] = unit;
                    }
                    matches = (matches + 1) & 0xFFFF;
                }
            }
        }
    }
    index = (index + 1) & 0xFFFF;
test:
    if ((u16)index < frame.count) {
        goto loop;
    }
    return matches;
}
// FUN_001D94D0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d94d0);
// FUN_001D9740
s32 func_001d9740(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D97B0
s32 func_001d97b0(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return !((u32)uVar1 * 100 < (uVar2 & 0xFFFF) * arg1);
}

// FUN_001D9820
s32 func_001d9820(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 0xA);
    uVar2 = func_00232290(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D9890
void func_001d9890(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001d9740);
}

// FUN_001D98E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001d98e0(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001d9740);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D9940
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001d9940(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001d97b0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D99A0
s32 func_001d99a0(u8 *arg0, u32 arg1)
{
    return (u32)(func_00231e20(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) & 0xFF) >= arg1;
}
// FUN_001D9B60
void func_001d9b60(u8 *arg0) {
    func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
}
// FUN_001D9B90
void func_001d9b90(u8 *arg0, u32 arg1)
{
    u32 mask;

    mask = (1 << *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        func_001d94d0((int)arg0, arg1, mask, 0, 0, (code)func_001d9b60);
    } else {
        func_001d94d0((int)arg0, arg1, mask, 0x80000, 0, (code)func_001d9b60);
    }
}

/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
// FUN_001D9C00
#pragma opt_rebuildconditionals off
void func_001d9c00(u8 *arg0, u32 arg1)
{
    u32 shift;
    u32 temp_3;

    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero_1;
        shift = 1;
        goto done_1;
    nonzero_1:
        shift = 0;
    done_1:
        ;
    }
    temp_3 = shift & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        func_001d94d0((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0, 0, (code)func_001d9b60);
    } else {
        func_001d94d0((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0x80000, 0, (code)func_001d9b60);
    }
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9CA0
s32 func_001d9ca0(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 mode;
    s32 mask;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    mode = 1;
    goto done;
nonzero:
    mode = 0;
done:
    ;
    mask = (1 << (mode & 0xFFFF)) & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(temp + 0xA2))) != 0 &&
                func_002428f0(*(u8 **)(temp + 0xA64), 0) == 0 &&
                func_00232710(*(s32 *)(temp + 0xA64), arg1) == 0) {
                break;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    if (unit != NULL)
        goto found;
    return 1;
found:
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9ca0. */
#pragma opt_rebuildconditionals on
// FUN_001D9DB0
s32 func_001d9db0(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    func_00232710(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    *(u16 *)(temp + 0xA4) == arg1) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9E80
s32 func_001d9e80(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                func_00232710(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                *(u16 *)(temp + 0xA4) == arg1) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9e80. */
#pragma opt_rebuildconditionals on
// FUN_001D9F60
s32 func_001d9f60(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    func_00232710(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    func_002340c0(*(s32 *)(temp + 0xA64), arg1) != 0) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DA040
s32 func_001da040(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                func_00232710(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                func_002340c0(*(s32 *)(temp + 0xA64), arg1) != 0) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001da040. */
#pragma opt_rebuildconditionals on
// FUN_001DA130
s32 func_001da130(u8 *arg0) {
    s32 r;

    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180010) != 0) {
        r = 0;
    } else {
        r = (*(s32 *)(iGpffffb414 + *(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18) & 1) != 0;
    }
    return r;
}

// FUN_001DA1A0
s32 func_001da1a0(void)
{
    return 0;
}

// FUN_001DA1B0
s32 func_001da1b0(u8 *arg0)
{
    u8 genus;

    if (*(s32 *)(arg0 + 0x20) > 0)
        return 0;
    genus = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (genus) {
    case 0:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 1;
    case 1:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 2;
    default:
        return 0;
    }
}

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x02000000) != 0);
}



// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x04000000) != 0);
}



// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x01000000) != 0);
}



// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x08000000) != 0);
}



// FUN_001DA330
void func_001da330(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001da230);
}

// FUN_001DA380
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001da380(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da230);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

// FUN_001DA430
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001da430(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da270);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA490
void func_001da490(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001da2b0);
}
// FUN_001DA4E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001da4e0(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da2b0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA540
void func_001da540(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001da2f0);
}
// FUN_001DA590
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001da590(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da2f0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA5F0
s32 func_001da5f0(u8 *arg0, s32 arg1)
{
    return p4_001da5f0_xor((s16)func_0023d8e0(
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
        *(u16 *)(arg0 + 0x7E)), arg1) < 1U;
}
// FUN_001DA640
void func_001da640(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001da5f0);
}
// FUN_001DA690
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001da690(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da5f0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA930
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da930);
// FUN_001DAA00
void func_001daa00(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)func_001da230);
}
// FUN_001DAA50
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001daa50(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)func_001da230);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAAB0
void func_001daab0(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)func_001da270);
}
// FUN_001DAB00
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001dab00(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)func_001da270);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAB60
void func_001dab60(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)func_001da2b0);
}
// FUN_001DABB0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001dabb0(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)func_001da2b0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAC10
void func_001dac10(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)func_001da2f0);
}
// FUN_001DAC60
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void func_001dac60(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)func_001da2f0);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DACE0
s32 func_001dace0(u8 *arg0, s32 arg1)
{
    extern u16 func_00231ed0(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    temp_18 = (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            func_002428f0(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += func_00231ed0(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += func_00231f80(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Opening state measured: opt_rebuildconditionals off is required for this mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DAE00
s32 func_001dae00(u8 *arg0, s32 arg1)
{
    extern u16 func_00231ed0(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        temp_18 = 1;
        goto done;
    nonzero:
        temp_18 = 0;
    done:
        ;
    }
    temp_18 = (1 << (temp_18 & 0xFFFF)) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            func_002428f0(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += func_00231ed0(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += func_00231f80(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Closing state measured: restore opt_rebuildconditionals on after this function. */
#pragma opt_rebuildconditionals on