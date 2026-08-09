/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);

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
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aaa80);
// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}



// FUN_002AAAC0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aaac0);
// FUN_002AABF0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aabf0);
// FUN_002ABF70
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002abf70);
// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002AC2A0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002ac2a0);
// FUN_002AC360
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002ac360);
// FUN_002AC3B0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002ac3b0);
// FUN_002AC3C0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002ac3c0);