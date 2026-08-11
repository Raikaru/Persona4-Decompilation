#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void (*D_008873ec[])(s32);

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern s32 func_0010b6f0(void);
extern s32 func_0010b5b0(void);
extern s32 func_0010ac10(u16 arg0);
extern u8 *func_00109220(u16 arg0);
extern void func_002bad10(s32 arg0);
extern void func_002bbd20(s32 arg0, void *arg1);
extern void func_0010b010(u16 arg0);
extern s32 func_00376590(u8 *arg0, s32 arg1);
extern void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void func_00389cb0(u8 *arg0);
extern void func_0038d020(u8 *arg0);
extern void func_003889b0(s32 arg0, u8 *arg1);
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *func_00451fc0(s32 arg0, const void *arg1, s32 arg2,
                         s32 arg3, s32 arg4, s32 (*arg5)(u8 *),
                         void (*arg6)(u8 *), u8 *arg7);
extern void func_00388d10(u8 *arg0);
extern void func_003874c0(void);
extern s32 func_00388b40(u8 *arg0);
extern void func_00388ba0(u8 *arg0);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0046d730(u8 *arg0, s32 arg1);
extern void func_0034f1e0(void);
extern void func_0038acd0(u8 *arg0);
extern void func_0038bab0(u8 *arg0);
extern void func_0038c100(u8 *arg0);
extern void func_0038c770(u8 *arg0);
extern void func_0038cab0(u8 *arg0);
extern u8 D_0064F0E0[];
extern f32 D_0064EEF0[];
extern void func_00389370();
extern void func_00389640();
extern void func_00389e10();
extern void func_0038a940();
extern void func_0038b1c0();
extern void func_0034f460(s32 arg0, f32 arg1, s32 arg2, f32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, s32 arg7);
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

// FUN_00380980
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00380980);
// FUN_00380BD0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00380bd0);
// FUN_00380D80
s32 func_00380d80(u8 *arg0, s32 arg1)
{
    u16 count2;
    u16 count1;

    count1 = func_0010b6f0();
    count2 = func_0010b5b0();
    if (func_0010ac10(arg1) != 0) {
        func_002bad10(2);
        return 6;
    }
    if (count1 == count2) {
        func_0043f9c8(arg0 + 0x18, 0, 0x7C);
        func_002bbd20(0, func_00109220(arg1));
        func_002bad10(3);
        return 7;
    }
    func_0010b010(arg1);
    func_002bbd20(0, func_00109220(arg1));
    func_002bad10(1);
    return 5;
}
// FUN_00383C00
s32 func_00383c00(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14) != 0;
}
// FUN_00383C20
u32 func_00383c20(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 4;
    return *(u32 *)(p + 0x14);
}
// FUN_00383C40
void func_00383c40(u8 *arg0)
{
    u8 *base;
    s32 value;
    u8 colors[4];

    base = *(u8 **)arg0;
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    switch (*(s32 *)(base + 0x1F2FC)) {
    case 0:
    case 1:
    case 2:
        value = func_00376590(base, 0);
        break;
    case 3:
        value = *(u16 *)(base + 0x1F1D4);
        break;
    default:
        func_0046d730(D_0064EEB0, 0x103);
        break;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    func_00377930(base, value, 0, colors, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
// FUN_00383D70
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00383d70);
// FUN_00383F80
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00383f80);
// FUN_00384CC0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00384cc0);
// FUN_00385380
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385380);
// FUN_00385970
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00385970);
// FUN_00386C00
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00386c00);
// FUN_003874C0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_003874c0);
// FUN_00387750
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387750);
// FUN_00387E70
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00387e70);
// FUN_003889B0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_003889b0);
// FUN_00388B40
s32 func_00388b40(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    func_00460ac0(D_00795E30, p + 0x50);
    *(s32 *)(p + 0x80) = 0;
    *(s32 *)(p + 0x84) = 0;
    func_00460ac0(D_00795EF0, p + 0x80);
    return 0;
}
// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}



// FUN_00388BD0
u8 *func_00388bd0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064EEB0, 0x63F);
    work = D_008873F4[0](1, 0xB0, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064EEB0, 0x640);
    }
    temp = func_00451fc0(arg0, D_0064ECA0, 0x13, 0, 0,
                         (s32 (*)(u8 *))func_00388b40,
                         (void (*)(u8 *))func_00388ba0, work);
    if (temp == NULL) {
        func_0046d730(D_0064EEB0, 0x64A);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0043f9c8(work + 0x50, 0, 0x30);
    func_0043f9c8(work + 0x80, 0, 0x30);
    *(void **)(work + 0x58) = (void *)func_003874c0;
    *(void **)(work + 0x60) = (void *)work;
    *(void **)(work + 0x88) = (void *)func_003889b0;
    *(void **)(work + 0x90) = (void *)work;
    func_00388d10(temp);
    return temp;
}
// FUN_00388D10
void func_00388d10(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = 0;
}
// FUN_00388D20
void func_00388d20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x4;
}

// FUN_00388D40
void func_00388d40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFFB;
}

// FUN_00388D60
void func_00388d60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 6);
    *(u16 *)(p + 0x4C) |= 2;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388DE0
s32 func_00388de0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388E00
void func_00388e00(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x2;
}

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}



// FUN_00388E40
void func_00388e40(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 0x18);
    *(u16 *)(p + 0x4C) |= 1;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388EC0
s32 func_00388ec0(u8 *arg0)
{
    return (*(u16 *)(*(u8 **)(arg0 + 0x38) + 4) & 1) != 0;
}
// FUN_00388EE0
void func_00388ee0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x4;
}

// FUN_00388F00
void func_00388f00(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0xA) = 0;
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 0x10;
}
// FUN_00388F20
void func_00388f20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x10;
}

// FUN_00388F40
void func_00388f40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFEF;
}

// FUN_00388F60
void func_00388f60(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x20, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x20);
}

// FUN_00388FB0
void func_00388fb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) | 0x2;
}

// FUN_00388FD0
void func_00388fd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x24, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x40);
}

// FUN_00389020
void func_00389020(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) | 0x4;
}

// FUN_00389040
void func_00389040(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x28, 0, 0x18);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x80);
}

// FUN_00389090
void func_00389090(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = *(s32 *)(p + 0x3C);

    *(s32 *)(p + 0x3C) = n + 1;
    slot = (s32 *)((u32)(n << 2) + (u32)slot);
    slot[1] = arg1;
    if (*(s32 *)(p + 0x3C) > 4) {
        func_0046d730(D_0064EEB0, 0x745);
    }
  }

// FUN_003890F0
void func_003890f0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFF7F;
}

// FUN_00389110
void func_00389110(u8 *arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_3 + 0x1E) = 0;
    *(u16 *)(temp_3 + 0x4C) = (u16) (*(u16 *)(temp_3 + 0x4C) | 8);
    func_0045af60(1, 5, 5, 0);
}

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}



// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}



// FUN_003891B0
void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 0x40) = 0;
    *(u8 *)(p + 0x42) = arg1;
    *(u8 *)(p + 0x43) = arg2;
    *(u8 *)(p + 0x44) = arg3;
    *(u16 *)(p + 0x4C) = *(u16 *)(p + 0x4C) | 0x100;
}
// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}



// FUN_00389200
void func_00389200(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_16 = (u8 *)(temp_17 + 0x46);
    func_0043f9c8(temp_16, 0, 6);
    *(s8 *)(temp_16 + 2) = arg1;
    *(s8 *)(temp_16 + 3) = arg2;
    *(s8 *)(temp_16 + 4) = arg3;
    *(u16 *)(temp_17 + 0x4C) = (u16) (*(u16 *)(temp_17 + 0x4C) | 0x200);
}

/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
#pragma opt_rebuildconditionals off
// FUN_00389280
s32 func_00389280(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 flags;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x46);
    flags = *(u16 *)(p + 0x4C);
    if (!(flags & 0x200)) {
        return 1;
    }
    return *field >= 0x23;
}
/* measured: restore conditional rebuilding after this function. */
#pragma opt_rebuildconditionals on
// FUN_003892C0
void func_003892c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFDFF;
}

// FUN_003892E0
void func_003892e0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x46, 0, 6);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x400);
}

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}



// FUN_00389350
void func_00389350(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) | 0x2;
}

// FUN_00389370
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389370);
// FUN_00389640
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389640);
// FUN_00389CB0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389cb0);
// FUN_00389E10
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389e10);
// FUN_0038A3E0
void func_0038a3e0(u8 *arg0)
{
    u8 *temp_16;

    arg0 += 0x168;
    temp_16 = (u8 *)add_offset_first_0038(4, (u32)arg0);
    func_0043f9c8(arg0, 0, 0x28);
    *(s16 *)temp_16 = 0;
    *(f32 *)(temp_16 + 0x10) = (f32)0x13D;
    *(s32 *)(temp_16 + 0x14) = 0x43880000;
    *(s32 *)(temp_16 + 0x18) = 0x3F800000;
    *(s32 *)(temp_16 + 0x1C) = 0x3E800000;
    *(s32 *)(temp_16 + 4) = 0x43330000;
    *(s32 *)(temp_16 + 8) = 0x43610000;
    *(u8 *)(temp_16 + 0x20) = 0xD7;
    *(u8 *)(temp_16 + 0x21) = 0x84;
    *(u8 *)(temp_16 + 0x22) = 0x15;
    *(u8 *)(temp_16 + 0x23) = 0xFF;
}
// FUN_0038A480
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038a480);
// FUN_0038A940
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038a940);
// FUN_0038ACD0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038acd0);
// FUN_0038B1C0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038b1c0);
// measured: preserve retail argument materialization order
#pragma opt_propagation off
// FUN_0038B490
void func_0038b490(s32 arg0, u8 **arg1)
{
    s32 temp_16;
    func_0034f1e0();
    func_00389370(arg1);
    func_00389640(arg1);
    temp_16 = *(s32 *)(*arg1 + 0x1F2B4);
    func_0034f460(temp_16, 0.0f, 0, 0.0f, 0xDA, 0x8C, 0x17, 0xC0);
    func_00389e10(arg1);
    func_0038a940(arg1);
    func_0038b1c0(arg1);
}
// measured: restore propagation default
#pragma opt_propagation on
// FUN_0038B530
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038b530);
// FUN_0038BAB0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038bab0);
// FUN_0038C100
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038c100);
// FUN_0038C770
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038c770);
// FUN_0038CAB0
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038cab0);
// FUN_0038CD70
void func_0038cd70(u8 *arg0, u8 *arg1)
{
    u8 *p;

    p = arg1;
    func_0034f1e0();
    if (*(u16 *)(p + 4) & 0x20) {
        func_0038acd0(p);
    }
    if (*(u16 *)(p + 4) & 1) {
        func_0038bab0(p);
    }
    if (*(u16 *)(p + 4) & 2) {
        func_0038c100(p);
    }
    if (*(u16 *)(p + 4) & 4) {
        func_0038c770(p);
    }
    if (*(u16 *)(p + 4) & 8) {
        func_0038cab0(p);
    }
}
// FUN_0038CE30
s32 func_0038ce30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    func_00460ac0(D_00794990, p + 8);
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    func_00460ac0(D_00794E40, p + 0x38);
    return 0;
}

// FUN_0038CE90
void func_0038ce90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0038CEC0
u8 *func_0038cec0(s32 arg0)
{
    u8 *work;
    u8 *temp;

    func_0044ea90(D_0064F0E0, 0x59D);
    work = D_008873F4[0](1, 0x1B8, 0x40000);
    if (work == NULL) {
        func_0046d730(D_0064F0E0, 0x59E);
    }
    temp = func_00451fc0(arg0, D_0064EED0, 0x13, 0, 0,
                         func_0038ce30, func_0038ce90, work);
    if (temp == NULL) {
        func_0046d730(D_0064F0E0, 0x5A8);
    }
    *(s32 *)work = func_0036e910(arg0);
    func_0038a3e0(work);
    func_00389cb0(work);
    func_0043f9c8(work + 8, 0, 0x30);
    *(void **)(work + 0x10) = (void *)func_0038b490;
    *(u8 **)(work + 0x18) = work;
    func_0043f9c8(work + 0x38, 0, 0x30);
    *(void **)(work + 0x40) = (void *)func_0038cd70;
    *(u8 **)(work + 0x48) = work;
    func_0038d020(temp);
    return temp;
}
// FUN_0038D020
void func_0038d020(u8 *arg0)
{
    u8 *p;
    u16 *field;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    field = (u16 *)(p + 0x168);
    *(u16 *)(p + 4) = 0;
    value = *field;
    if (value & 1) {
        *field = value & 0xFFFE;
        *field = *field | 2;
        field[2] = 0;
    }
}
// FUN_0038D060
void func_0038d060(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u16 *)(p + 4) = *(u16 *)(p + 4) | 1;
    func_0043f9c8(p + 0x190, 0, 0x10);
}
// FUN_0038D0A0
void func_0038d0a0(u8 *arg0)
{
    u8 *p;
    u16 value;

    p = *(u8 **)(arg0 + 0x38);
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 0x20;
    value = *(u16 *)(p + 0x194);
    *(u16 *)(p + 0x194) = value | 4;
}
// FUN_0038D0D0
void func_0038d0d0(u8 *arg0, s32 arg1)
{
    s32 temp_3_2;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;

    temp_3 = *(u8 **)(arg0 + 0x38);
    temp_4 = temp_3 + 0x190;
    temp_3_2 = *(s32 *)(temp_3 + 0x198);
    if (temp_3_2 != arg1) {
        *(s32 *)(temp_4 + 0xC) = temp_3_2;
        *(s32 *)(temp_4 + 8) = arg1;
        *(s16 *)temp_4 = 0;
        *(s16 *)(temp_4 + 2) = 0;
        *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) & 0xFFF7;
        switch (arg1) {
        case 1:
        case 3:
        case 4:
            var_3 = 1;
            break;
        default:
            var_3 = 0;
            break;
        }
        if (var_3 != 0) {
            *(u16 *)(temp_4 + 4) = *(u16 *)(temp_4 + 4) | 2;
        }
    }
}
// FUN_0038D160
void func_0038d160(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_17 = (u8 *)(temp_16 + 0x1A4);
    func_0043f9c8(temp_17, 0, 6);
    *(u16 *)(temp_17 + 4) = (u16) *(u16 *)((u8 *)(*(u8 **)(temp_16 + 0)) + 0x1F1D8);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 2);
}

// FUN_0038D1D0
void func_0038d1d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) | 0x2;
}

// FUN_0038D1F0
void func_0038d1f0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    temp_16 = temp_17 + 0x1A0;
    if (*(s32 *)(*(u8 **)temp_17 + 0x1F2FC) != 4) {
        func_0046d730(D_0064F0E0, 0x641);
    }
    *(u16 *)(temp_17 + 4) = *(u16 *)(temp_17 + 4) | 8;
    *(s32 *)(temp_16 + 4) = 0x434F0000;
    *(s32 *)(temp_16 + 8) = 0;
    *(s32 *)(temp_16 + 0x10) = 0x42C40000;
    *(s16 *)temp_16 = 0;
}
// FUN_0038D280
void func_0038d280(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(s32 *)(p + 0x1B0) = 0;
    *(u16 *)(p + 0x1A0) = 0;
}
// FUN_0038D2A0
void func_0038d2a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) | 0x1;
}

// FUN_0038D2C0
void func_0038d2c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x1B4, 0, 4);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 0x20);
}

// FUN_0038D310
void func_0038d310(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) | 0x2;
}

// FUN_0038D330
void func_0038d330(s32 *raw_arg0)
{
    extern void func_004b1150(s32 arg0, u8 *arg1);
    extern void func_004b1210(void *arg0, s32 arg1);
    extern u8 D_005DC824[];
    extern u8 D_005DC974[];
    extern u8 D_005DC9C8[];
    u8 *arg0;
    u8 *temp_5;
    s32 temp_4;

    arg0 = (u8 *)raw_arg0;
    if (*(u16 *)(arg0 + 4) & 1) {
        temp_5 = (u8 *)(arg0 + 8);
        if (++*(u16 *)(arg0 + 8) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0xC);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0xC) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFE;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 2) {
        temp_5 = (u8 *)(arg0 + 0x10);
        if (++*(u16 *)(arg0 + 0x10) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x14);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x14) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFD;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 4) {
        temp_5 = (u8 *)(arg0 + 0x18);
        if (++*(u16 *)(arg0 + 0x18) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x1C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x1C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFFB;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 8) {
        temp_5 = (u8 *)(arg0 + 0x20);
        if (++*(u16 *)(arg0 + 0x20) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x24);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x24) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFF7;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x10) {
        temp_5 = (u8 *)(arg0 + 0x28);
        if (++*(u16 *)(arg0 + 0x28) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x2C);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x2C) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFEF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x20) {
        temp_5 = (u8 *)(arg0 + 0x30);
        if (++*(u16 *)(arg0 + 0x30) >= 0x5A) {
            temp_4 = *(s32 *)(arg0 + 0x34);
            if (temp_4 != 0) {
                func_004b1150(temp_4, temp_5);
                *(s32 *)(arg0 + 0x34) = 0;
            }
            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) & 0xFFDF;
        } else {
            func_004b1210(D_005DC974, *(s32 *)(temp_5 + 4));
        }
    }
    if (*(u16 *)(arg0 + 4) & 0x40) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x3C));
    }
    if (*(u16 *)(arg0 + 4) & 0x80) {
        func_004b1210(D_005DC9C8, *(s32 *)(arg0 + 0x44));
    }
    if (*(u16 *)(arg0 + 4) & 0x100) {
        func_004b1210(D_005DC824, *(s32 *)(arg0 + 0x4C));
    }
}
// FUN_0038D660
s32 func_0038d660(u8 *arg0) {
    s32 *temp_16;

    temp_16 = (s32 *)(*(s32 **)(arg0 + 0x38));
    func_00374910(*temp_16);
    func_0038d9f0(arg0);
    func_0038d330(temp_16);
    return 0;
}

// FUN_0038DD60
void func_0038dd60(void)
{
}

// FUN_0038DD70
void func_0038dd70(void)
{
}

// FUN_0038DD80
void func_0038dd80(void)
{
}

// FUN_0038DD90
void func_0038dd90(u8 *arg0) {
    s32 i;

    *(s32 *)arg0 = 0;
    arg0[0x122C] = 0xFF;
    arg0[0x122D] = 0xFF;
    arg0[0x122E] = 0xFF;
    arg0[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)(arg0 + i * 0x90 + 4) = 0;
    }
    iGpffffb5b0 = arg0;
}

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !datGetFlag(0x1472);
}



// FUN_0038F400
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038f400);
// FUN_0038F590
void func_0038f590(void)
{
    ((void (*)(...))D_008873ec[0])();
}
// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}


// FUN_0038F990
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038f990);
// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on
// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off

// FUN_0038FB50
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fb50);
// FUN_0038FD30
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fd30);
// FUN_0038FE90
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_0038fe90);