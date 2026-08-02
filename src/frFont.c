#include "type.h"
#include "include_asm.h"

extern void func_002716b0_typed(s32 arg0, u64 arg1, u8 *arg2);
#pragma alias func_002716b0_typed func_002716b0

typedef int (*code)(...);
extern u32 DAT_00881630_abs[];
extern code DAT_008873ec_abs[];
extern u32 DAT_00881750_abs[];
extern u32 DAT_00881754_abs[];
extern u32 DAT_00881758_abs[];
extern u32 DAT_0088175c_abs[];
extern u8 DAT_00881760_abs[];

extern s16 D_00763810;

extern void func_00273140(void *param_1, u32 param_2);

extern u32 D_00764598;
extern int func_00273170(void *param_1, u32 param_2, u32 param_3);

extern u32 D_007637F8;
extern u32 D_00764594;
extern s32 D_007645A0;
extern void func_0046d730(const void *file, u32 line);
extern char D_0063BAE8[];
extern void func_00275c00(void);
extern u32 DAT_00881528_abs[];
#pragma alias DAT_00881528_abs DAT_00881528
extern u32 DAT_0088152C_abs[];
#pragma alias DAT_0088152C_abs DAT_0088152C
extern u32 DAT_0088179C_abs[];
#pragma alias DAT_0088179C_abs DAT_0088179C
extern u32 func_00271bd0(int param_1);
extern u32 func_00272cb0(int param_1);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern int func_0045af90(int param_1);
extern void func_002baa20(void);
extern int func_002e0d60(void);
extern void func_002bcd20(void);
extern void func_002e17f0(void);
extern void func_002715c0(void);
extern void func_002713b0(int param_1, int param_2);
extern s8 func_002746e0(void *param_1, int param_2);
extern void func_002746b0(u32 param_1);
extern void func_002745c0(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                         u32 param_5, u32 param_6, u32 param_7, u32 param_8,
                         u32 param_9);
extern u32 D_00763840;
extern u32 D_00763848;
extern u32 D_00763838;
extern int func_002724d0(void *param_1, int param_2, int param_3, int param_4,
                        int param_5);
extern u32 DAT_008817A0_abs[];
#pragma alias DAT_008817A0_abs DAT_008817A0
extern u32 DAT_00881510_abs[];
#pragma alias DAT_00881510_abs DAT_00881510
extern u32 DAT_00881514_abs[];
#pragma alias DAT_00881514_abs DAT_00881514
extern u32 DAT_00881764_abs[];
#pragma alias DAT_00881764_abs DAT_00881764
extern u32 DAT_00881768_abs[];
#pragma alias DAT_00881768_abs DAT_00881768
extern void func_0026e170(int param_1);
extern void func_00275bd0(void);
extern void func_00271a40(void);
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern void func_00454bd0();
extern void func_00440b68();
extern char D_0063BBB0[];
extern char D_0063BBF0[];
extern char D_0063BB40[];
extern char D_0063BB80[];

typedef struct FrFontGlyph {
    u8 unknown_00[0xc];
    int advance;
    u8 unknown_10[0x18];
    struct FrFontGlyph *next;
} FrFontGlyph;

typedef struct FrFontNode {
    u8 unknown_00[3];
    s8 line_height;
    u8 unknown_04[0x18];
    FrFontGlyph *glyphs;
    u8 unknown_20[4];
    struct FrFontNode *next;
    u8 unknown_28[0x18];
    int enabled;
} FrFontNode;
typedef struct FrFontSlot4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 object;
} FrFontSlot4;

typedef struct FrFontManagerData4 {
    FrFontSlot4 slots[9];
    u8 unknown_120[0x60];
    u32 *allocations[9];
} FrFontManagerData4;

#pragma alias gFrFontManagerData_abs DAT_00881630
extern FrFontManagerData4 gFrFontManagerData_abs[];

extern u32 DAT_00881634_abs[];



// FUN_00270FB0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00270fb0);

// FUN_00271310
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271310);
// FUN_00271380
void func_00271380(s32 arg0, u8 *arg1)
{
    func_002716b0_typed(arg0, 0, arg1);
}


#pragma alias DAT_00881630_abs DAT_00881630
#pragma alias DAT_008873ec_abs DAT_008873ec


// FUN_002713B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002713b0);

// FUN_002715C0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002715c0);
// FUN_002716B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002716b0);
// FUN_00271820
void func_00271820(u32 param_1)
{
    DAT_008873ec_abs[0](DAT_00881630_abs[(param_1 & 0xff) * 8]);
}


#pragma alias DAT_00881750_abs DAT_00881750
#pragma alias DAT_00881754_abs DAT_00881754
#pragma alias DAT_00881758_abs DAT_00881758
#pragma alias DAT_0088175c_abs DAT_0088175c
#pragma alias DAT_00881760_abs DAT_00881760

// func_0026e120 and func_00271310 are intentionally left undeclared
// (implicit old-style calls, as in the P3 donor FUN_003b0030); a typed
// prototype would force an int->pointer cast mwcc rejects, and the P3
// retail form is the implicit call.


// FUN_00271860
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271860);

// FUN_00271A40
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271a40);
// FUN_00271B70
int func_00271b70(int param_1)
{
    char cVar1;
    int uVar2;

    cVar1 = (char)func_00272cb0(param_1);
    if (cVar1 != '\0') {
        uVar2 = param_1;
    } else {
        uVar2 = func_00271bd0(param_1);
    }
    return uVar2;
}
// FUN_00271BD0
u32 func_00271bd0(int param_1)
{
    int iVar4;
    int iVar1;
    int next_list;
    int iVar2;
    u32 *puVar3;

    if (param_1 == 0) {
        return param_1;
    }

    while (param_1 != 0) {
        iVar4 = *(int *)(param_1 + 0x1c);

        while (iVar4 != 0) {
            iVar1 = *(int *)(iVar4 + 0x28);

            if (*(int *)(iVar4 + 0x20) == 0) {
                *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) =
                    *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) + -1;
                iVar2 = *(int *)(iVar4 + 0x1c);

                if ((iVar2 != 0) && (*(u16 *)(iVar2 + 4) == 0)) {
                    puVar3 = *(u32 **)(iVar2 + 0xc);

                    if (puVar3 != (u32 *)0x0) {
                        *puVar3 = *puVar3 & 0xfffffffe;
                        puVar3[4] = 0;
                    }

                    func_00271310(*(u32 *)(iVar2 + 8));
                    DAT_00881750_abs[0] = DAT_00881750_abs[0] + -1;
                }
            }

            func_0026e120(iVar4, DAT_0088175c_abs[0]);
            iVar4 = iVar1;
            DAT_00881754_abs[0] = DAT_00881754_abs[0] + -1;
        }

        next_list = *(int *)(param_1 + 0x24);
        func_0026e120(param_1, *(u32 *)DAT_00881760_abs);
        param_1 = next_list;
        DAT_00881758_abs[0] = DAT_00881758_abs[0] + -1;
    }

    return 0;
}



// FUN_00271D10
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271d10);

// FUN_00271F50
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271f50);

// FUN_00272170
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272170);

// FUN_00272390
int func_00272390(short *param_1)
{
    u16 *puVar3;
    u16 sVar1;
    int iVar2;
    int iVar3;

    puVar3 = *(u16 **)((int)param_1 + 0x24);
    iVar2 = 0;
    if (*(u8 *)((int)param_1 + 0x15) == 0) {
        goto LAB_002723B0;
    }
    if (*(u8 *)((int)param_1 + 0x15) != 1) {
        goto LAB_002724C4;
    }
LAB_002723B0:
    if (puVar3 == (u16 *)0x0) {
        goto LAB_002724C4;
    }
    sVar1 = *(u16 *)param_1;
    switch (sVar1) {
    case 0x61:
    case 0x65:
    case 0x6f:
    case 0x75:
    case 0x80c1:
    case 0x80c5:
    case 0x80cf:
    case 0x80d5:
        goto LAB_00272424;
    default:
        goto LAB_002724C4;
    }
LAB_00272424:
    sVar1 = *puVar3;
    if (sVar1 == 0x54) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x80b4) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x59) {
        goto LAB_00272458;
    }
    if (sVar1 == 0x80b9) {
        goto LAB_00272458;
    }
    goto LAB_00272484;
LAB_00272458:
    iVar2 = 3;
    iVar3 = D_007645A0;
    if (iVar3 <= 0) {
        goto LAB_00272484;
    }
    iVar3 = iVar3 * 3;
    iVar2 = iVar3 >> 7;
    if (iVar3 < 0) {
        iVar2 = iVar3 + 0x7f >> 7;
    }
LAB_00272484:
    if (sVar1 == 0x56) {
        goto LAB_0027249C;
    }
    if (sVar1 != 0x80b6) {
        goto LAB_002724C4;
    }
LAB_0027249C:
    iVar2 = 2;
    iVar3 = D_007645A0;
    if (iVar3 <= 0) {
        goto LAB_002724C4;
    }
    iVar3 = iVar3 * 2;
    iVar2 = iVar3 >> 7;
    if (iVar3 < 0) {
        iVar2 = iVar3 + 0x7f >> 7;
    }
LAB_002724C4:
    return iVar2;
}

// FUN_002724D0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002724d0);

// FUN_00272730
void func_00272730(int param_1, u8 param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x69B);
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
        *(u8 *)(param_1 + 2) = param_2;
    }
}

// FUN_002727A0
void func_002727a0(u32 param_1, u16 param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6A7);
    }
    *(u16 *)param_1 = param_2;
}

// FUN_002727F0
void func_002727f0(FrFontNode *node)
{
    FrFontNode *iter;

    node->enabled = 1;
    iter = node;
    if (node == NULL) {
        func_0046d730(D_0063BAE8, 0x69B);
    }
    for (; iter != NULL; iter = iter->next) {
        iter->unknown_00[2] = 0xff;
    }
}

// FUN_00272860
void func_00272860(int param_1, int param_2)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(u8 *)(param_1 + 3) = param_2;
    *(u32 *)(param_1 + 0xc) = func_002738d0(param_1);
}

// FUN_002728C0
void func_002728c0(int param_1, u8 param_2)
{
    int iVar1;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x6F2);
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
        for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0;
             iVar1 = *(int *)(iVar1 + 0x28)) {
            *(u8 *)(iVar1 + 0x15) = param_2;
        }
    }
}

// FUN_00272950
void func_00272950(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x708);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    iVar2 = param_2 - *(int *)(param_1 + 4);
    iVar1 = param_3 - *(int *)(param_1 + 8);
    while (param_1 != 0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
        param_1 = *(int *)(param_1 + 0x28);
    }
}

// FUN_00272A10
void func_00272a10(int param_1, float param_2, float param_3)
{
    int iVar1;
    int iVar2;

    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x71F);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    iVar2 = (int)(16.0f * param_2) - *(int *)(param_1 + 4);
    iVar1 = (int)(8.0f * param_3) - *(int *)(param_1 + 8);
    while (param_1 != 0) {
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;
        param_1 = *(int *)(param_1 + 0x28);
    }
}

// FUN_00272B00
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272b00);

// FUN_00272B34
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272b34);

// FUN_00272B50
void func_00272b50(int param_1, u8 param_2, u8 param_3)
{
    int key = param_2;
    FrFontGlyph *glyph;

    while (param_1 != 0) {
        glyph = *(FrFontGlyph **)(param_1 + 0x1c);
        while (glyph != NULL) {
            if (glyph->unknown_10[4] == key) {
                glyph->unknown_10[4] = param_3;
            }
            glyph = glyph->next;
        }
        param_1 = *(int *)(param_1 + 0x24);
    }
}

// FUN_00272BA0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272ba0);

// FUN_00272BD4
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272bd4);

// FUN_00272BF0
int func_00272bf0(int param_1)
{
    if (param_1 == 0) {
        func_0046d730(D_0063BAE8, 0x77B);
    }
    while (*(int *)(param_1 + 0x24) != 0) {
        param_1 = *(int *)(param_1 + 0x24);
    }
    return param_1;
}
// FUN_00272C60
u16 func_00272c60(s16 param_1)
{
    u16 uVar1;

    uVar1 = D_00763810;
    D_00763810 = D_00763810 | param_1;
    return uVar1;
}



// FUN_00272C80
u16 func_00272c80(u16 param_1)
{
    u16 uVar1;
    long mask;

    uVar1 = D_00763810;
    mask = (s16)~param_1;
    D_00763810 = D_00763810 & mask;
    return uVar1;
}


// Ported from P3FES FUN_003b0ec0 (verified MATCH there). Retail hoists the
// loop-invariant mask/type constants here; removing opt_loop_invariants
// measured nd102 at 136B instead of nd1 at 140B (P3 donor annotation).

// FUN_00272CB0
#pragma push
#pragma opt_loop_invariants on

u32 func_00272cb0(int list)
{
    u32 result = 0;
    u32 mask = ~0xff;
    u32 changed = 1;
    u32 type = 2;

    while (list != 0) {
        int node = *(int *)(list + 0x1c);

        while (node != 0) {
            if (*(u8 *)(node + 0x16) == type) {
                u32 word = *(u32 *)(node + 0x10);
                u32 fade = word & 0xff;
                u32 merged;

                if (fade != 0) {
                    fade -= 8;
                    if ((s32)fade < 0) {
                        fade = 0;
                    }
                    merged = word & mask;
                    merged |= fade;
                    *(u32 *)(node + 0x10) = merged;
                    *(u32 *)(node + 8) += 0x10;
                    result = changed;
                }
            }
            node = *(int *)(node + 0x28);
        }
        list = *(int *)(list + 0x24);
    }
    return result;
}
#pragma opt_loop_invariants off
#pragma pop



// FUN_00272D40
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272d40);
// FUN_00272E10
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272e10);
// FUN_00273110
void func_00273110(s32 arg0)
{
    func_00273140((void *)arg0, 0);
}



// FUN_00273140
void func_00273140(void *param_1, u32 param_2)
{
    func_00273170(param_1, param_2, D_00764598);
}



// FUN_00273170
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273170);

// FUN_002734B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002734b0);

// FUN_00273610
u32 func_00273610(void)
{
    DAT_0088179C_abs[0] = func_00271bd0(DAT_0088179C_abs[0]);
    func_00275c00();
    return 0;
}
// FUN_00273650
int func_00273650(int param_1, int param_2, int param_3)
{
    if (param_1 != 0)
    {
        goto checkParam2;
    }
    return param_2;

checkParam2:
    if (param_2 != 0)
    {
        goto body;
    }
    return param_1;

body:
    *(u32*)(param_1 + 0x28) = *(u32*)(param_2 + 0x2c);
    *(int*)(*(int*)(param_2 + 0x2c) + 0x24) = param_1;
    *(u32*)(param_2 + 0x2c) = *(u32*)(param_1 + 0x2c);

    if (param_3 == 1)
    {
        *(int*)(param_2 + 4) = *(int*)(param_1 + 4) + *(int*)(param_1 + 0xc) * 0x10;
        *(u32*)(param_2 + 8) = *(u32*)(param_1 + 8);
    }

    return param_2;
}



// FUN_002736D0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002736d0);

// FUN_002738A0
void func_002738a0(u64 param_1)
{
    func_002716b0_typed(8, param_1, 0);
}



// FUN_002738D0
int func_002738d0(FrFontNode *node)
{
    int total = 0;
    FrFontGlyph *glyph;

    for (glyph = node->glyphs; glyph != NULL; glyph = glyph->next) {
        total += glyph->advance;
        total += node->line_height;
    }
    return total;
}


#pragma alias DAT_00881634_abs DAT_00881634


// FUN_00273910
u16 func_00273910(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x10);
}


#pragma alias DAT_00881634_abs DAT_00881634


// FUN_00273940
u16 func_00273940(u32 param_1)
{
    u32 **base = (u32 **)DAT_00881634_abs;
    u32 *entry = base[(param_1 & 0xff) * 8];
    return *(u16 *)((u8 *)entry + 0x12);
}


// func_002745c0 is intentionally left undeclared (implicit old-style call,
// as in the P3 donor): a typed u8 prototype makes mwcc emit andi
// zero-extensions the retail never has.

// FUN_00273970
int func_00273970(int node)
{
    int result = 0;
    int child;

    if (node == 0) {
        return result;
    }
    node = *(int *)(node + 0x2c);
    while (node != 0) {
        child = *(int *)(node + 0x28);
        node = *(int *)(node + 8);
        while (child != 0) {
            if (*(int *)(child + 8) != node) {
                break;
            }
            child = *(int *)(child + 0x28);
        }
        result++;
        node = child;
    }
    return result;
}

// FUN_002739E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002739e0);

// FUN_00273CC0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273cc0);

// FUN_00273F70
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273f70);
// FUN_002740B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002740b0);
// FUN_00274570
void func_00274570(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                   u32 param_5, u32 param_6, u32 param_7, u32 param_8)
{
    func_002745c0(param_1, param_2, 0, param_3, param_4, param_5, param_6, param_7, param_8);
}

// FUN_002745C0
void func_002745c0(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                   u32 param_5, u32 param_6, u32 param_7, u32 param_8,
                   u32 param_9)
{
    struct {
        u32 f00;
        u32 f04;
        u32 f08;
        u8 f0c;
        u8 f0d;
        u8 f0e;
        u8 f0f;
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;

    data.f00 = param_1;
    data.f04 = param_2;
    data.f08 = param_3 << 4;
    data.f0c = param_4;
    data.f0d = param_5;
    data.f0e = param_6;
    data.f0f = param_7;
    data.f10 = param_8;
    data.f14 = param_9;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    func_002746b0(0);
    func_002740b0(&data);
}

// FUN_00274640
void func_00274640(void)
{
    D_007637F8 = 0;
}

// FUN_00274660
void func_00274660(u32 param_1, int param_2)
{
    if (param_2 != 0) {
        D_007637F8 |= param_1;
    } else {
        D_007637F8 &= ~param_1;
    }
}

// FUN_002746A0
u32 func_002746a0(void)
{
    return D_00764594;
}

// FUN_002746B0
void func_002746b0(u32 param_1)
{
    D_00764594 = param_1;
}

// FUN_002746E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002746e0);

// FUN_002748E0
s8 func_002748e0(int param_1, int param_2, int param_3)
{
    struct {
        u8 f00[0x10];
        u32 f10;
        u32 f14;
        u32 f18;
        u8 f1c;
        u8 f1d;
        u16 f1e;
    } data;
    u32 old;
    s8 result;

    func_0043f9c8(&data, 0, 0x20);
    data.f10 = param_1;
    data.f18 = 0;
    data.f1c = 1;
    data.f1d = 1;
    data.f1e = 0x20;
    old = D_00764594;
    D_00764594 = param_2;
    result = func_002746e0(&data, param_3);
    D_00764594 = old;
    return result;
}

// FUN_00274970
void func_00274970(void)
{
    int v;

    func_002baa20();
    v = func_002e0d60();
    *(int *)v = func_00451de0(&D_00763840, 0xC8, 0, 0, func_002e17f0, 0, 0);
    func_002713b0(0x100, 0x100);
    func_00451de0(&D_00763848, 0, 0, 0, func_00273610, func_002715c0, 0);
    func_002bcd20();
}

