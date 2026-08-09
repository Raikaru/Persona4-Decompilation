/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "type.h"
extern void func_004b15d0();

s32 func_00291a60(u16 arg0);

s32 func_0045a8d0(s64 arg0, s32 arg1);

s32 func_0029cc00(s32 arg0);
extern s32 func_00452490(s32 arg0);
extern void func_00442088(char *buf, const char *fmt, s32 value);
extern void func_0045aeb0(s16 arg0, char *buf);
extern void func_001228a0(s32 arg0, s32 arg1, s32 arg2);
extern char D_0063CB30[];
extern char D_0063D050[];
extern void func_00452080(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
void func_004b1590(s32 arg0, s16 arg1);
s32 func_0045a3e0(s16 arg0, s32 arg1);
s32 func_00459880(void);
s32 func_004598e0(s16 arg0);

s32 func_00104ce0(s16 arg0);
void func_0029cf50(s32 arg0);

s32 func_00104dc0(s16 arg0);

s32 func_00104d50(s16 arg0);
extern void func_001056e0(s16 arg0, s16 arg1);
extern s64 func_0029cc00_s64(s32 arg0);



// FUN_00291530
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00291530);
// FUN_002915F0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002915f0);
// FUN_00291790
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00291790);
// FUN_00291810
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00291810);
// FUN_00291980
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00291980);
// FUN_002919E0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002919e0);
// FUN_00291A60
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00291a60);
// FUN_00291B30
s32 func_00291b30(s32 arg0, u16 *arg1) {
    return (s32)(func_00291a60(*arg1) == 0);
}



// FUN_00293710
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00293710);
// FUN_00294280
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00294280);
// FUN_002962F0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002962f0);
// FUN_00296600
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296600);
// FUN_00296720
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296720);
// FUN_00296850
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00296850);
// FUN_00298130
s32 func_00298130(s32 arg0, s32 arg1, s32 arg2) {
    char sp20[0x20];

    func_00442088(sp20, D_0063CB30, arg1);
    func_0045aeb0((s16)arg2, sp20);
    return 0;
}

// FUN_002981F0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002981f0);
// FUN_00298220
s32 func_00298220(s64 arg0) {
    func_0045a8d0((s16) arg0, 0);
    return 0;
}



// FUN_00298250
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00298250);
// FUN_00298340
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00298340);
// FUN_00298D30
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00298d30);
// FUN_00298D70
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00298d70);
// FUN_00299560
s32 func_00299560(void) {
    s32 v;

    v = func_0029cc00(0);
    if (func_00452490(v) == 0) {
        return 1;
    }
    func_00452080(v);
    return 1;
}

// FUN_002996E0
s32 func_002996e0(void) {
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_004b1590(temp_16, func_0029cc00(1));
    return 1;
}



// FUN_00299740
s32 func_00299740(void)
{
    func_004b15d0();
    return 1;
}

// FUN_00299770
s32 func_00299770(void) {
    s32 a;
    s32 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0045af60(0, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_002997D0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002997d0);
// FUN_00299800
s32 func_00299800(void) {
    s32 a;
    s32 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0045af60(1, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_00299860
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299860);
// FUN_00299890
s32 func_00299890(void) {
    func_0045a3e0(func_0029cc00(0), 1);
    return 1;
}



// FUN_002998D0
s32 func_002998d0(void) {
    s32 temp_2;

    temp_2 = func_0029cc00(0);
    if (temp_2 == 0) {
        func_00459880();
    } else {
        func_004598e0(temp_2);
    }
    return 1;
}



// FUN_00299920
s32 func_00299920(void) {
    char sp10[0x20];
    s32 v;

    v = func_0029cc00(0);
    func_00442088(sp10, D_0063D050, v);
    func_0045aeb0(2, sp10);
    return 1;
}

// FUN_00299970
s32 func_00299970(void) {
    s32 v;

    v = func_0029cc00(0);
    if (v == 0) {
        func_0045a9a0(2, 0);
    } else {
        func_0045aac0(2, 0, v);
    }
    return 1;
}

// FUN_002999D0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_002999d0);
// FUN_00299A10
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299a10);
// FUN_00299A50
s32 func_00299a50(void) {
    s32 a;
    s32 b;
    s32 c;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    c = func_0029cc00(2);
    func_001228a0(a & 0xFF, b & 0xFF, c & 0xFF);
    return 1;
}

// FUN_00299AC0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299ac0);
// FUN_00299B70
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299b70);
// FUN_00299C20
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299c20);
// FUN_00299C60
s32 func_00299c60(void) {
    func_0029cf50(func_00104ce0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}



// FUN_00299CB0
s32 func_00299cb0(void) {
    func_0029cf50(func_00104dc0(func_0029cc00(0)) & 0xFFFF);
    return 1;
}



// FUN_00299D00
s32 func_00299d00(void)
{
    s64 temp_16;
    s64 temp_17;

    temp_16 = func_0029cc00_s64(0);
    temp_17 = func_0029cc00_s64(1);
    func_001056e0((s16)temp_16, (s16)temp_17);
    return 1;
}

// FUN_00299D60
s32 func_00299d60(void) {
    func_0029cf50(func_00104d50(func_0029cc00(0)) & 0xFFFF);
    return 1;
}

// FUN_00299DB0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299db0);
// FUN_00299E00
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299e00);
// FUN_00299E60
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299e60);
// FUN_00299EA0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_00299ea0);
// FUN_0029A020
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029a020);
// FUN_0029D010
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029d010);
// FUN_0029D020
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029d020);
// FUN_0029D030
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029d030);
// FUN_0029D040
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029d040);
// FUN_0029D050
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029d050);
// FUN_0029E960
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e960);
// FUN_0029E970
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e970);
// FUN_0029E980
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e980);
// FUN_0029E990
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e990);
// FUN_0029E9A0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e9a0);
// FUN_0029E9B0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e9b0);
// FUN_0029E9E0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029e9e0);
// FUN_0029EBF0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029ebf0);
// FUN_0029ECB0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029ecb0);
// FUN_0029EF90
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029ef90);
// FUN_0029F070
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029f070);
// FUN_0029F790
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029f790);
// FUN_0029FBB0
INCLUDE_ASM("asm/nonmatchings/code1_0029", func_0029fbb0);