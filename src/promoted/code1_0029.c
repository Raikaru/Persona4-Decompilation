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



// FUN_00291B30
s32 func_00291b30(s32 arg0, u16 *arg1) {
    return (s32)(func_00291a60(*arg1) == 0);
}



// FUN_00298130
s32 func_00298130(s32 arg0, s32 arg1, s32 arg2) {
    char sp20[0x20];

    func_00442088(sp20, D_0063CB30, arg1);
    func_0045aeb0((s16)arg2, sp20);
    return 0;
}

// FUN_00298220
s32 func_00298220(s64 arg0) {
    func_0045a8d0((s16) arg0, 0);
    return 0;
}



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

// FUN_00299800
s32 func_00299800(void) {
    s32 a;
    s32 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_0045af60(1, 0, (s16)a, (s16)b);
    return 1;
}

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
