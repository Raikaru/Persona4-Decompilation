#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb1b4;

extern s32 D_005E45E0[];

extern u8 D_0079B6D8[];

extern s8 D_005E3A00[];

s32 func_0029e970(void);
void func_0029e980(s32);

void func_00106390(s32, s32);

extern s32 uGpffffb1bc;
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 iGpffffb1b8;
extern void (*jtbl_008873EC[])(u8 *);
extern u8 *func_0010d7c0(s32 a, s32 *b, s32 c);
extern u8 D_007BBF00[];
extern void func_0043f810(void *dst, void *src, s32 n);
extern s16 D_00797B7A[];



// FUN_00110460
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110460);
// FUN_001104A0
s32 func_001104a0(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}



// FUN_001104D0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001104d0);
// FUN_00110580
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110580);
// FUN_001105B0
s32 func_001105b0(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_001104d0(arg0, &sp1C, &sp18);
    sp18 = (sp18 - 1) / 7;
    return sp18 + 1;
}

/* The month index is walked in the PARAMETER, not a fresh local: retail keeps
   it in $a0 for the whole loop, and any separate `cur` local rotates the three
   live values through $a3/$a2/$a0 instead (identical instruction sequence,
   11 differing words). */
// FUN_00110600
s32 func_00110600(s32 arg0, s32 arg1) {
    s32 sum = 0;
    s32 next;

    if (arg0 != 4) {
        arg0 = arg0 - 1;
        if (arg0 == 0) {
            arg0 = 12;
        }
        do {
            next = arg0 - 1;
            sum = sum + D_005E45E0[next % 12];
            if (arg0 == 4) {
                break;
            }
            arg0 = next;
            if (next == 0) {
                arg0 = 12;
            }
        } while (1);
    }
    return sum + (arg1 - 1);
}

// FUN_00110680
s32 func_00110680(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    s32 sp38;

    func_001104d0(D_00797B7A[0], &sp3C, &sp38);
    if (sp3C == arg1 && sp38 == arg2) {
        return 1;
    }
    return 0;
}

// FUN_001106F0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001106f0);
// FUN_00110810
void func_00110810(s32 arg0, s8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}



// FUN_00110850
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110850);
// FUN_00110960
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110960);
// FUN_00110A60
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110a60);
// FUN_00110C50
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110c50);
// FUN_00110D30
s32 func_00110d30(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}



// FUN_00110D60
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110d60);
// FUN_00110E70
void func_00110e70(s32 arg0)
{
    iGpffffb1b4 = arg0;
}

// FUN_00110E80
void func_00110e80(void) {
    s32 sp3C;
    u8 *p;
    s32 n;

    p = func_0010d7c0(0, &sp3C, 1);
    n = sp3C;
    func_0043f810(D_007BBF00, p, n);
    iGpffffb1b8 = n;
    jtbl_008873EC[0](p);
    iGpffffb1b4 = 1;
}

// FUN_00110F00
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110f00);
// FUN_00110FC0
void func_00110fc0(void) {
    func_00260560();
    func_00122520(1, 1);
    func_001029a0(0x1B, 0, 0, 8);
}

// FUN_00111010
void func_00111010(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}



// FUN_00111050
void func_00111050(s32 arg0)
{
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
    if (arg0 != 0) {
        uGpffffb1bc = 0;
    }
}

// FUN_001110E0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001110e0);
// FUN_00111160
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00111160);
// FUN_00111200
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00111200);
// FUN_00111290
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00111290);
// FUN_001113B0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001113b0);
// FUN_00111BC0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00111bc0);
// FUN_00112300
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112300);
// FUN_001125D0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001125d0);
// FUN_00112610
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112610);
// FUN_00112830
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112830);
// FUN_001130C0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001130c0);
// FUN_00113280
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113280);
// FUN_00113480
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113480);
// FUN_00113500
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113500);
// FUN_00113520
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113520);
// FUN_00113610
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113610);
// FUN_00113730
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113730);
// FUN_00113750
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113750);
// FUN_00113790
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113790);
// FUN_00113800
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113800);
// FUN_00115830
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00115830);
// FUN_0011FCF0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fcf0);
// FUN_0011FD10
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fd10);
// FUN_0011FD30
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fd30);
// FUN_0011FD50
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fd50);
// FUN_0011FDF0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fdf0);