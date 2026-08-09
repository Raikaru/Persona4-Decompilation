/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);
extern u16 *D_00764658;

s32 func_00452380(void *arg0);
extern u8 D_0063E918[];
void func_00452080(s32 arg0);

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00451fc0(void *a, void *b, s32 c, s32 d, s32 e, void *f, void *g, void *h);
extern void func_002aa890(void);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_002abf70(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);



// FUN_002A02F0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a02f0);
// FUN_002A03B0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a03b0);
// FUN_002A12E0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a12e0);
// FUN_002A1A10
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1a10);
// FUN_002A1B20
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1b20);
// FUN_002A1BD0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1bd0);
// FUN_002A1C80
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1c80);
// FUN_002A1F20
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1f20);
// FUN_002A1FA0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1fa0);
// FUN_002A2310
void func_002a2310(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_002A2710
s32 func_002a2710(void) {
    return (s32)(func_00452380(D_0063E918) != 0);
}



// FUN_002A2740
void func_002a2740(void) {
    s32 temp_2;

    if ((temp_2 = func_00452380(D_0063E918)) != 0) {
        func_00452080(temp_2);
    }
}



// FUN_002A2E10
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a2e10);
// FUN_002AA3F0
s32 func_002aa3f0(void) {
    s32 r;

    if (func_00452380(&D_00763918) == 0) {
        r = (D_00764634 != 0) ? 1 : 2;
    } else {
        r = 0;
    }
    return r;
}

// FUN_002AA450
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aa450);
// FUN_002AA890
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aa890);
// FUN_002AAA00
void func_002aaa00(void)
{
}

// FUN_002AAA10
void func_002aaa10(void) {
    func_0043f9c8(D_00882F20, 0, 0x10);
    func_00451fc0(NULL, D_0063EE40, 0xF, 0, 0, (void *)func_002aa890, (void *)func_002aaa00, NULL);
}

// FUN_002AAA80
void func_002aaa80(void) {
    D_00882F20[0] |= 1;
}
// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}


/* measured: opt_propagation off keeps the D_00887300 base in $s0 and
   reloads the dispatch target before each call, as in retail. */
#pragma opt_propagation off
// FUN_002AAAC0
void func_002aaac0(void) {
    void (**base)(s32 arg0, s32 arg1);

    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    func_003f6440(3, 0x50003);
    func_003f6440(2, 0x44);
    base[0](1, 0);
}
/* measured: closes the opt_propagation bracket for func_002aaac0. */
#pragma opt_propagation on
// FUN_002AABF0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aabf0);
// FUN_002ABF70
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002abf70);
// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002AC2A0
void func_002ac2a0(void) {
    u8 *p;

    func_0044ea90(D_0063EEC0, 0x4B9);
    p = D_008873F4[0](1, 0x4D78, 0x40000);
    func_00451de0(D_0063EED0, 0xF, 0, 0,
                  (void *)func_002abf70, (void *)func_002ac270, p);
    *(u8 *)(p + 0) = 0;
    *(s32 *)(p + 0x6B4) = 0x3F800000;
    *(s16 *)(p + 0x6B8) = 0x1F;
    *(s16 *)(p + 0x6BA) = 0;
    *(s8 *)(p + 0x6BC) = 1;
    *(s8 *)(p + 0x6BD) = 1;
    *(s32 *)(p + 0x6C0) = 0;
}
// FUN_002AC360
void func_002ac360(void) {
    s16 i;

    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
}
// FUN_002AC3B0
u32 func_002ac3b0(void) {
    return (u32)D_00764658;
}
// FUN_002AC3C0
s64 func_002ac3c0(s32 arg0, s32 arg1) {
    s32 temp;

    temp = arg0 & 0xff;
    return (s8)(((1 << temp) & 0xffff & D_00764658[arg1 & 0xff]) >> temp);
}