/* Whole-file translation unit: src/Event/Fcl/y_fclShop.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"

extern char D_0063F3C8[];
extern char D_0063F3E0[];
extern char D_0063F550[];
extern s32 D_0063F520[];
extern char iGpffffa870;
extern u8 *(*D_008873F4[])(s32, s32, s32);

s32 func_002ca830(s32);
s32 func_002be100(s32);
s32 func_00106ac0(s16);
s64 func_00106af0(s16);
s32 func_00106b20(s16);
s32 func_00106b50(s16);
u8 func_00110830(s32);
void func_00110810(s32, u8);
s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_0044ea90(const void *, u32);
void func_0045aac0(s16, s32, s32);
void func_00440b68();
s32 func_00454a60();
void func_00456150();
s32 func_00455f70();
void func_002bc010();
void func_00104a60();
void func_002bd8e0(u8 *);
void func_002bdb10(u8 *);

// FUN_002BDB50
s32 func_002bdb50(s32 arg0, s8 arg1)
{
    u8 *temp_2;
    s32 temp_17;
    s16 i;

    func_0044ea90(D_0063F3C8, 0xB0);
    temp_2 = D_008873F4[0](1, 0x1840, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0063F3E0, 0xF, 0, 0, func_002bd8e0,
                           func_002bdb10, temp_2);
    temp_2[0] = 1;
    temp_2[1] = 0;
    if (arg1 == 1) {
        temp_2[0] = 0x19;
        temp_2[0] = 3;
        temp_2[1] = 1;
    }
    *(s32 *)(temp_2 + 4) = func_002ca830(arg0);
    *(s16 *)(temp_2 + 0x18) = 0;
    *(s16 *)(temp_2 + 0x24) = 0;
    *(s16 *)(temp_2 + 0x26) = 0;
    *(s16 *)(temp_2 + 0x2A) = 0;
    *(s32 *)(temp_2 + 0x10) = 0x41000000;
    *(s32 *)(temp_2 + 0x14) = 0x41200000;
    *(s16 *)(temp_2 + 0x18) = 0;
    *(s32 *)(temp_2 + 0x1C) = 0x41000000;
    *(s32 *)(temp_2 + 0x20) = 0x41200000;
    *(s16 *)(temp_2 + 0x24) = 0;
    func_0045aac0(3, 0, 0x1E);
    for (i = 0; i < 0x2FF; i++) {
        if (((func_00106b20(i) & 0xFFF00) >> 8) == 0 &&
            ((func_00106b50(i) & 0xFFF00) >> 8) == 0) {
            func_00110810(i, func_00110830(i) | 4);
        } else if (!(func_00106b20(i) & 0xFF) && !(func_00106b50(i) & 0xFF)) {
            func_00110810(i, func_00110830(i) | 4);
        }
    }
    for (i = 0x300; i < 0x3FF; i++) {
        if ((func_002be100(func_00106ac0(i) & 0xFF) & 0xFF) <
            (func_002be100(4) & 0xFF)) {
            func_00110810(i, func_00110830(i) | 4);
        } else if ((func_002be100(func_00106ac0(i) & 0xFF) & 0xFF) ==
                   (func_002be100(4) & 0xFF) && (s8)func_00106af0(i) < 2) {
            func_00110810(i, func_00110830(i) | 4);
        }
    }
    return temp_17;
}

// FUN_002BDEA0
void func_002bdea0(void)
{
    s32 i;

    for (i = 0; i < 0x3FF; i++) {
        u8 t;

        t = func_00110830(i);
        if (t & 2) {
            func_00110810(i, 0);
            func_00110810(i, 4);
        }
    }
}

// FUN_002BDF20
void func_002bdf20(void)
{
    s32 items[9];
    s32 out;
    s32 *src;
    s32 *dst;
    s32 count;
    s32 i;
    s32 temp;

    src = D_0063F520;
    dst = items;
    count = 9;
    do {
        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    func_00440b68(&iGpffffa870, D_0063F3C8, 0x179);
    func_00456150(func_00454a60(D_0063F550, 1));
    for (i = 0; i < 9; i++) {
        func_002bc010(i, func_00455f70(items[i], &out));
    }
    func_00104a60();
}
