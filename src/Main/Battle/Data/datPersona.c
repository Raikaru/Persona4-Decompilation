/* Original translation unit datPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0023a620(s32 arg0, s32 arg1);
extern char D_005E4318[];
extern s16 D_00797F88[];
extern s16 D_00797F8C[];
extern s16 D_0079819C;
extern u8 D_00796E50[];
extern u8 D_007973A0[];
extern u8 D_00797F8E[];
extern s32 D_0079B40C[];
extern u8 *DAT_007644c8;
extern u8 *DAT_007644c4;
extern u8 *DAT_007644cc;
extern u8 *DAT_007644d4;

extern s32 func_0010be20(u32 arg0);
extern void func_0010fde0(u8 *arg0);
void func_0010cad0(); /* old-style: callers pass args raw */

extern u16 *func_0010ace0(s16 arg0);
extern s32 func_0010b5b0(void);
extern void func_0023a620(s32 arg0, s32 arg1);

s8 func_00109d20(u8 *arg0, s32 arg1);
s8 func_00109dd0(u8 *arg0, s32 arg1);
s8 func_00109e30(u8 *arg0, s32 arg1);

extern u8 *func_0010b060(); /* old-style: b010 jals with no arg setup */

u16 *func_0010a900(); /* old-style: every retail caller jals with no arg setup */

// FUN_001092F0
u16 func_001092f0(u32 arg0)
{
    return *(u16 *)(arg0 + 2);
}

// FUN_00109300
u16 func_00109300(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3E);
    }
    return *(u16 *)((u8 *)p + 2);
}

// FUN_00109360
u16 func_00109360(void)
{
    return *(u16 *)((u8 *)func_0010a900() + 2);
}

// FUN_001093A0
u8 func_001093a0(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x5F);
    }
    return *(u8 *)((u8 *)p + 4);
}

// FUN_00109470
u16 func_00109470(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0xF1);
    }
    return *p;
}

// FUN_00109510
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109510);

// FUN_001097C0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_001097c0);

// FUN_00109870
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109870);

// FUN_00109920
u8 func_00109920(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    return arg0[(u16)arg1 + 0x1C];
}

// FUN_00109980
s32 func_00109980(s32 arg0, s32 arg1)
{
    u16 *p = func_0010a900(arg0);
    u8 *base = (u8 *)p;
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    return base[(u16)arg1 + 0x1C];
}

// FUN_001099F0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_001099f0);

// FUN_00109AD0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109ad0);

// FUN_00109BF0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109bf0);

// FUN_00109D20
s8 func_00109d20(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x268);
    }
    return (s8)arg0[(u16)arg1 + 0x21];
}

// FUN_00109DD0
s8 func_00109dd0(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x299);
    }
    return (s8)arg0[(u16)arg1 + 0x26];
}

// FUN_00109E30
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109e30);

// FUN_0010A780
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010a780);

// FUN_0010A840
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010a840);

// FUN_0010A900
u16 *func_0010a900(s32 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v == 1) {
        p = func_0010ace0(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            func_0046d730(D_005E4318, 0x3A5);
        }
        p = (u16 *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54);
    }
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3A9);
    }
    return p;
}

// FUN_0010A9B0
s32 func_0010a9b0(s32 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v != 1) {
        return 0;
    }
    if (v == 1) {
        p = func_0010ace0(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            func_0046d730(D_005E4318, 0x3A5);
        }
        p = (u16 *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54);
    }
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3A9);
    }
    return (*(u16 *)p & 4) != 0;
}

// FUN_0010AA80
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010aa80);

// FUN_0010AB30
s32 func_0010ab30(void)
{
    s32 i = 0;

    while ((u16)i < (u16)func_0010b5b0()) {
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
            return (s16)i;
        }
        i = (i + 1) & 0xFFFF;
    }
    return -1;
}

// FUN_0010ABD0
s32 func_0010abd0(s16 arg0)
{
    return (*(u16 *)((u8 *)D_00797F8C + (s32)arg0 * 0x30) & 1) != 0;
}

// FUN_0010AC10
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010ac10);

// FUN_0010ACE0
u16 *func_0010ace0(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x3FE);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
        return NULL;
    }
    return (u16 *)((u8 *)D_007973A0 + v * 0x30 + 0xBEC);
}

// FUN_0010AD80
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010ad80);

// FUN_0010AE30
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010ae30);

// FUN_0010B010
u8 *func_0010b010(void)
{
    u8 *p = func_0010b060();
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x43A);
    }
    return p;
}

// FUN_0010B060
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b060);

// FUN_0010B190
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b190);

// FUN_0010B300
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b300);

// FUN_0010B3B0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b3b0);

// FUN_0010B460
u16 func_0010b460(void)
{
    s32 v = D_00797F88[0];
    s32 off;

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x491);
    }
    off = v * 0x30;
    if ((*(u16 *)((u8 *)D_00797F8C + off) & 1) == 0) {
        func_0046d730(D_005E4318, 0x492);
    }
    return *(u16 *)((u8 *)D_00797F8E + off);
}

// FUN_0010B510
s32 func_0010b510(void)
{
    s32 v = D_00797F88[0];

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x49C);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
        func_0046d730(D_005E4318, 0x49D);
    }
    return v;
}

// FUN_0010B5B0
s32 func_0010b5b0(void)
{
    s32 v = D_0079B40C[0];
    if (v & 4) {
        return 0xC;
    }
    if (v & 2) {
        return 0xA;
    }
    if (v & 1) {
        return 8;
    }
    return 6;
}

// FUN_0010B610
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b610);

// FUN_0010B6F0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b6f0);

// FUN_0010B7C0
void func_0010b7c0(void)
{
    func_0043f9c8((void *)D_00797F8C, 0, 0x240);
}

// FUN_0010B7F0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b7f0);

// FUN_0010B9A0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b9a0);

// FUN_0010BD90
void func_0010bd90(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v == 1) {
        D_00797F88[0] = -1;
        func_0043f9c8((void *)D_00797F8C, 0, 0x240);
    } else {
        func_0043f9c8((void *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54), 0, 0x30);
    }
}

// FUN_0010BE20
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010be20);

// FUN_0010BE60
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010be60);

// FUN_0010C5A0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010c5a0);

// FUN_0010C750
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010c750);

// FUN_0010C980
void func_0010c980(u8 *arg0, s32 arg1)
{
    if (arg1 < 0) {
        func_0046d730(D_005E4318, 0x689);
    }
    *(s32 *)(arg0 + 8) += arg1;
}

// FUN_0010C9E0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010c9e0);

// FUN_0010CAD0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010cad0);

// FUN_0010CC20
s32 func_0010cc20(u8 *arg0, u32 arg1)
{
    s32 i;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x6E0);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) == 0) {
            *(u16 *)(arg0 + i * 2 + 0xC) = (u16)arg1;
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_0010CCC0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010ccc0);

// FUN_0010CD70
void func_0010cd70(u8 *arg0, s32 arg1, u32 arg2)
{
    if (arg0 == NULL || (s16)arg1 == 0 || (arg2 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x6FE);
    }
    {
        s32 r = func_0010ce10(arg0, (u16)arg1);
        if (r != -1) {
            s32 off = r * 2;
            *(u16 *)(off + (s32)arg0 + 0xC) = (u16)arg2;
        }
    }
}

// FUN_0010CE10
s32 func_0010ce10(u8 *arg0, u32 arg1)
{
    s32 i;
    u32 key;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x70A);
    }
    i = 0;
    key = arg1 & 0xFFFF;
    while (i < 8) {
        u16 v = *(u16 *)(arg0 + i * 2 + 0xC);
        if (v == key) {
            return i;
        }
        i++;
    }
    return -1;
}

// FUN_0010CEB0
s32 func_0010ceb0(u8 *arg0)
{
    s32 count = 0;
    s32 i;

    if (arg0 == NULL) {
        func_0046d730(D_005E4318, 0x717);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) != 0) {
            count++;
        }
        i++;
    }
    return count;
}

// FUN_0010CF40
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010cf40);

// FUN_0010CFA0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010cfa0);

// FUN_0010D150
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010d150);

