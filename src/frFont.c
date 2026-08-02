#include "type.h"
#include "include_asm.h"

extern void func_002716b0(s32 arg0, u64 arg1, u8 *arg2);

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
extern u32 DAT_00881634_abs[];



// FUN_00270FB0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00270fb0);

// FUN_00271310
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271310);
// FUN_00271380
void func_00271380(s32 arg0, u8 *arg1)
{
    func_002716b0(arg0, 0, arg1);
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
INCLUDE_ASM("asm/nonmatchings/frFont", func_00271b70);
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
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272390);

// FUN_002724D0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002724d0);

// FUN_00272730
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272730);

// FUN_002727A0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002727a0);

// FUN_002727F0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002727f0);

// FUN_00272860
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272860);

// FUN_002728C0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002728c0);

// FUN_00272950
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272950);

// FUN_00272A10
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272a10);

// FUN_00272B00
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272b00);

// FUN_00272B34
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272b34);

// FUN_00272B50
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272b50);

// FUN_00272BA0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272ba0);

// FUN_00272BD4
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272bd4);

// FUN_00272BF0
INCLUDE_ASM("asm/nonmatchings/frFont", func_00272bf0);
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
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273610);
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
    func_002716b0(8, param_1, 0);
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
INCLUDE_ASM("asm/nonmatchings/frFont", func_00273970);

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
INCLUDE_ASM("asm/nonmatchings/frFont", func_002745c0);

// FUN_00274640
INCLUDE_ASM("asm/nonmatchings/frFont", func_00274640);

// FUN_00274660
INCLUDE_ASM("asm/nonmatchings/frFont", func_00274660);

// FUN_002746A0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002746a0);

// FUN_002746B0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002746b0);

// FUN_002746E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002746e0);

// FUN_002748E0
INCLUDE_ASM("asm/nonmatchings/frFont", func_002748e0);

// FUN_00274970
INCLUDE_ASM("asm/nonmatchings/frFont", func_00274970);

