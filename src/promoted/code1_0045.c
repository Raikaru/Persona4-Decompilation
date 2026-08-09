#include "include_asm.h"
#include "type.h"
extern s32 iGpffffac74;
extern s32 iGpffffad88;
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern s32 func_004535b0(void);
extern u8 D_00711738[];
extern void func_004244c8(u8 *arg0);
extern void func_00426f80(s32 arg0);
extern void func_00428f08(void *arg0, s32 arg1);
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern s32 iGpffffba74;
extern s32 iGpffffba78;
extern s32 iGpffffba7c;

extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];



// FUN_00450490
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450490);
// FUN_00450630
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450630);
// FUN_00450A50
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450a50);
// FUN_00450DD0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450dd0);
// FUN_00450E80
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450e80);
// FUN_004526A0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004526a0);
// FUN_004526E0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004526e0);
// FUN_004526F0
void func_004526f0(u8* arg0, s32 arg1)
{
    (*D_008873FC)(arg1, arg0);
}



// FUN_00452730
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452730);
// FUN_00452760
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452760);
// FUN_00452870
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452870);
// FUN_00452CE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452ce0);
// FUN_00452DB0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452db0);
// FUN_004530B0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004530b0);
// FUN_00453250
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00453250);
// FUN_00453310
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00453310);
// FUN_004533D0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004533d0);
// FUN_004534F0
void func_004534f0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (func_004535b0() == 0) {
        return;
    }
    iGpffffba34 = arg0;
    iGpffffba30 = 0;
    iGpffffba2c = arg2;
    iGpffffba28 = arg3;
    iGpffffba20 = arg1;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}

// FUN_004535B0
s32 func_004535b0(void)
{
    return iGpffffac74;
}

// FUN_004543D0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004543d0);
// FUN_00454460
/* The three exits are laid out with explicit gotos because retail places the
   `return 0` block and the `return 1` block out of line, in that order, after
   the main body. The natural nested-if / result-variable spellings all merge
   them into one epilogue and come out two words short (nd 24). */
s32 func_00454460(u8 *arg0) {
    s32 v;
    s32 t;

    v = *(s32 *)(arg0 + 0x28);
    if (v <= 0) {
        goto zero;
    }
    t = v - *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = t;
    if (t >= 0) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = 0;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 0;
one:
    return 1;
}

// FUN_004544B0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004544b0);
// FUN_004556B0
s32 func_004556b0(u8* arg0, u32 arg1)
{
    if (arg1 < *(u32*)(arg0 + 4)) {
        return (s32)(*(u8**)(arg0 + 0x58) + arg1 * 0x110);
    }
    return 0;
}



// FUN_00456530
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456530);
// FUN_004566C0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004566c0);
// FUN_00456840
void func_00456840(u8 *arg0) {
    func_004244c8(D_00711738);
    *(s32 *)(arg0 + 0x38) = 1;
    func_00426f80(*(s32 *)(arg0 + 0x74));
    func_00428f08(&iGpffffad88, 0);
}

// FUN_00456C30
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456c30);
// FUN_00456C60
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456c60);
// FUN_00456E40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456e40);
// FUN_00457120
s32 func_00457120(void)
{
    return iGpffffba80;
}

// FUN_00457130
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457130);
// FUN_00457140
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457140);
// FUN_00457160
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457160);
// FUN_00457170
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457170);
// FUN_00457190
s32 func_00457190(void)
{
    return iGpffffba70;
}

// FUN_004571A0
s32 func_004571a0(void)
{
    return iGpffffba74;
}

// FUN_004571B0
s32 func_004571b0(void)
{
    return iGpffffba78;
}

// FUN_004571C0
s32 func_004571c0(void)
{
    return iGpffffba7c;
}

// FUN_00457630
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457630);
// FUN_004585C0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004585c0);
// FUN_004586F0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004586f0);
// FUN_004587D0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004587d0);
// FUN_00458C40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458c40);
// FUN_00458C80
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458c80);
// FUN_00458CB0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458cb0);
// FUN_00458CE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458ce0);
// FUN_00458F00
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458f00);
// FUN_00458F40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458f40);
// FUN_00458F70
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458f70);
// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}



// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}

// FUN_0045B430
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045b430);
// FUN_0045C870
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045c870);
// FUN_0045CE40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ce40);
// FUN_0045D370
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d370);
// FUN_0045D6E0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d6e0);
// FUN_0045D890
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d890);
// FUN_0045ED60
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ed60);
// FUN_0045EE00
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ee00);
// FUN_0045FBE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045fbe0);