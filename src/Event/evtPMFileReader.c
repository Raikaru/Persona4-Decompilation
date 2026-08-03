#include "include_asm.h"
/* Persona 4 USA decompilation - evtPMFileReader.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern s32 func_00452490();
extern s32 *func_00452560();
extern u8 D_0063C970[];
extern void func_0044ea90(u8 *file, s32 line);
extern void func_002852a0(s32 arg0, s32 arg1);
extern void func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_00748340[];
extern u8 D_0063CAA0[];
extern s32 func_002938c0(void);
extern void func_00293d30(void);
extern void func_00106390(s32 a, s32 b);
extern void func_00454bd0(s32 a);
extern void func_00440b68(char *fmt, ...);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0063C9B0[];
extern u8 D_0063C9D0[];
extern u8 D_0063CA00[];
extern u8 D_0063CA20[];
extern u8 D_0063CA50[];
extern u8 D_0063CA70[];

/* measured: nd 126. The two else-branch flag checks (case 2: `if (p->flag == 1)`
   and case 4) emit `lw; addiu $v0,1; bne` in b210, but retail emits
   `lw; xori $v0,$v0,1; sltiu $v0,$v0,1; beqz` (the boolean-then-test form).
   Every spelling probed (==1 / !=1 / struct field / pointer cast / named local /
   u8/u16/u32 types / switch on flag) folds to `beq`/`bne`, never the xori/sltiu
   pair; the 4-byte residual from this floor propagates to every branch target
   in the else-branch (nd 126). Same family as cmpConfig func_0035cb00's
   documented sltu/xori booleanization floor. INCLUDE_ASM restored. */
// FUN_002938C0
INCLUDE_ASM("asm/nonmatchings/evtPMFileReader", func_002938c0);

// FUN_00293D30
void func_00293d30(void) {
    s32 *p;
    u16 h18;

    p = func_00452560();
    h18 = *(u16 *)(p + 0x18 / 4);
    if ((s32)h18 > 0) {
        func_00106390(h18, 0);
    }
    if (p[0x1C / 4] != 0) {
        func_00454bd0(p[0x1C / 4]);
        p[0x1C / 4] = 0;
        func_00440b68((char *)D_0063C9B0);
    }
    if (p[0x28 / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x28 / 4]);
        func_002852a0(4, 0);
        p[0x28 / 4] = 0;
        func_00440b68((char *)D_0063C9D0);
    }
    if (p[0x20 / 4] != 0) {
        func_00454bd0(p[0x20 / 4]);
        p[0x20 / 4] = 0;
        func_00440b68((char *)D_0063CA00);
    }
    if (p[0x2C / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x2C / 4]);
        func_002852a0(5, 0);
        p[0x2C / 4] = 0;
        func_00440b68((char *)D_0063CA20);
    }
    if (p[0x24 / 4] != 0) {
        func_00454bd0(p[0x24 / 4]);
        p[0x24 / 4] = 0;
        func_00440b68((char *)D_0063CA50);
    }
    if (p[0x30 / 4] != 0) {
        jtbl_008873EC[0]((void *)p[0x30 / 4]);
        func_002852a0(6, 0);
        p[0x30 / 4] = 0;
        func_00440b68((char *)D_0063CA70);
    }
    jtbl_008873EC[0](p);
    func_002852a0(1, -0x40);
}

// FUN_00293ED0
void func_00293ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_20;

    func_0044ea90(D_00748340, 0x52);
    temp_20 = (s32 *)D_008873F4[0](1, 0x40, 0x40000);
    func_002852a0(1, 0x40);
    func_0043f9c8(temp_20, 0, 0x40);
    temp_20[0xC / 4] = arg0;
    temp_20[0x10 / 4] = arg1;
    temp_20[0x14 / 4] = arg2;
    temp_20[0x4 / 4] = arg3;
    temp_20[0x8 / 4] = 0;
    func_00451de0(D_0063CAA0, 0xF, 1, 1, func_002938c0, func_00293d30, temp_20);
}

// FUN_00293FC0
s32 func_00293fc0(s32 arg0) {
    if (func_00452490(arg0) == 0) {
        func_0046d730(D_0063C970, 0x123);
    }
    if (func_00452560(arg0)[0] == 7) {
        return 1;
    }
    return 0;
}

// FUN_00294040
void func_00294040(s32 arg0) {
    if (func_00452490(arg0) == 0) {
        func_0046d730(D_0063C970, 0x131);
    }
    func_00452560(arg0);
}

// FUN_002940A0
s32 func_002940a0(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    u8 sp70[0x114];
    u8 *base = sp70;
    s32 *temp_2;
    s32 i;
    s32 count;
    u8 *elem;
    u8 *p;

    func_0043f9c8(base, 0, 0x114);
    if (func_00452490(arg0) == 0) {
        func_0046d730((char *)D_0063C970, 0x123);
    }
    if (func_00452560(arg0)[0] != 7) {
        if (func_00452490(arg0) == 0) {
            func_0046d730((char *)D_0063C970, 0x123);
        }
        if (func_00452560(arg0)[0] != 7) {
            func_0046d730((char *)D_0063C970, 0x143);
        }
        return 0;
    }
    temp_2 = func_00452560(arg0);
    *(u32 *)(base + 0x80) = (u32)temp_2[0x38 / 4];
    if (temp_2[0x38 / 4] != 0) {
        *(u32 *)(base + 0x84) = (u32)(temp_2[0x38 / 4] + 0x20);
    } else {
        *(u32 *)(base + 0x84) = 0;
    }
    i = 0;
    count = *(u32 *)(*(u32 *)(base + 0x80) + 0x10);
    for (; i < count; i++) {
        elem = *(u8 **)(base + 0x84);
        elem = (u8 *)((u32)elem + i * 16);
        switch (*(u32 *)elem) {
        case 0:
            p = (u8 *)(temp_2[0x38 / 4] + *(u32 *)(elem + 0xC));
            *(u32 *)(base + 0x90) = (u32)p;
            *arg1 = *(u32 *)(p + 0x10);
            *arg2 = *(u32 *)(*(u32 *)(base + 0x90) + 0x14);
            *arg3 = *(u8 *)(*(u32 *)(base + 0x90) + 0x1A);
            *arg4 = *(s16 *)(*(u32 *)(base + 0x90) + 0x1C);
            return 1;
        default:
            break;
        }
    }
    return 0;
}

