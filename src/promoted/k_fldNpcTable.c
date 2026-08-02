#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldNpcTable.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);
extern s32 func_0014eec0(void);
extern void func_00442830(void *arg0, const char *arg1);
extern s32 func_00442088(char *buf, const char *fmt, ...);
extern s32 func_00454570(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern u8 *gMtScene;
extern char D_00762F20;
extern char D_005F0790[];
extern char D_005F07A0[];
extern char D_005F07C0[];
extern char D_005F07D0[];
extern char D_005F07F0[];
extern char D_005F0810[];
extern char D_005F0830[];
extern char D_005F0850[];
extern s32 func_004553c0(u8 *arg0);
extern void func_0044ea90(void *arg0, s32 arg1);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_00454bd0(void *arg0);
extern void *(*D_008873F4[])(s32, s32, s32);
extern s32 D_00764384;
extern s32 D_00764388;
extern s32 D_0076438C;
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern s32 func_001060b0(void);
extern s32 func_001060c0(void);
extern void func_001104d0(s16 year, s32 *month, s32 *day);
extern s32 func_00106330(s32 id);
extern s32 func_0014bdb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// FUN_0015C750
s32 func_0015c750(void)
{
    char sp90[0x80];
    char sp10[0x80];
    u8 *scene;

    if (func_0014eec0() != 0) {
        goto ret1;
    }
    func_00442830(sp90, D_005F0790);
    scene = gMtScene;
    func_00442088(sp10, D_005F07A0, *(s32 *)scene, *(s32 *)(scene + 4));
    if (func_00454570(sp10) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x68);
    return (s32)func_00454a60(sp10, 0);
ret1:
    return 1;
}


// FUN_0015C800
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015c800);

// FUN_0015CA30
void *func_0015ca30(void)
{
    s32 sp6C;
    s32 sp68;
    u16 *work = *(u16 **)(func_00155280() + 0x18F0);
    u16 *end;
    s32 s3;
    s32 s2;
    s32 s1;
    s32 i;

    if (work == 0) {
        return 0;
    }
    end = work + (*(s32 *)(func_00155280() + 0x18EC) - 1) * 0x10;
    s3 = 3;
    s2 = 0x1F;
    s1 = 5;
    func_001104d0((s16)func_001060b0(), &sp6C, &sp68);
    i = 0;
    while (i < *(u32 *)(func_00155280() + 0x18EC)) {
        if (func_0014bdb0(end[0], end[1], s3, s2) != 1) {
            goto update;
        }
        if (end[0] == sp6C && end[1] == sp68) {
            if ((func_001060c0() & 0xFF) < end[2]) {
                goto next;
            }
        }
        if (s3 == sp6C && s2 == sp68) {
            if ((func_001060c0() & 0xFF) > s1) {
                goto next;
            }
        }
        if (*(s32 *)((u8 *)end + 8) == -1) {
            break;
        }
        if (func_00106330(*(s32 *)((u8 *)end + 8)) == 1) {
            break;
        }
    update:
        s3 = end[0];
        s2 = end[1];
        s1 = end[2];
    next:
        i++;
        end -= 0x10;
    }
    if (i >= *(u32 *)(func_00155280() + 0x18EC)) {
        end = 0;
    }
    return end;
}




// FUN_0015CBE0
/* measured: without opt_loop_invariants on the loop's invariant table base is
   rematerialized in the body (nd 6); with it the address hoists to the
   preheader like retail (nd 1, the last word being all-zero padding tail). */
#pragma opt_loop_invariants on
u16 *func_0015cbe0(s32 arg0)
{
    u16 *work = *(u16 **)(func_00155280() + 0x18F4);
    s32 count = 0;

    for (;;) {
        if (count == arg0) {
            break;
        }
        if (*work == 0xFFFF) {
            count += 1;
        }
        work += 0x10;
    }
    return work;
}
/* measured: see annotation above (func_0015cbe0). */
#pragma opt_loop_invariants off








// FUN_0015CC40
void func_0015cc40(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18E8) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18E8));
        *(s32 *)((u8 *)func_00155280() + 0x18E8) = 0;
        *(s32 *)((u8 *)func_00155280() + 0x18EC) = 0;
        *(s32 *)((u8 *)func_00155280() + 0x18F0) = 0;
        *(s32 *)((u8 *)func_00155280() + 0x18F4) = 0;
    }
}


// FUN_0015CCC0
s32 func_0015ccc0(void)
{
    char sp90[0x80];
    char sp10[0x80];
    u8 *scene;

    if (func_0014eec0() != 0) {
        goto ret1;
    }
    func_00442830(sp90, D_005F0790);
    scene = gMtScene;
    func_00442088(sp10, D_005F07F0, *(s32 *)scene, *(s32 *)(scene + 4));
    if (func_00454570(sp10) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x140);
    return (s32)func_00454a60(sp10, 0);
ret1:
    return 1;
}


// FUN_0015CD70
INCLUDE_ASM("asm/nonmatchings/k_fldNpcTable", func_0015cd70);

// FUN_0015CF10
void func_0015cf10(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18E0) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18E0));
        *(s32 *)((u8 *)func_00155280() + 0x18E0) = 0;
    }
}


// FUN_0015CF70
s32 func_0015cf70(void)
{
    char sp90[0x80];
    char sp10[0x80];

    func_00442830(sp90, D_005F0790);
    func_00442088(sp10, D_005F0830);
    if (func_00454570(sp10) == 0) {
        return 0;
    }
    func_00440b68(&D_00762F20, D_005F07C0, 0x1A2);
    return (s32)func_00454a60(sp10, 0);
}


// FUN_0015D000
/* measured: without opt_loop_invariants on, mwcc rematerializes the loop's
   invariant base inside the body (nd 6); with it it hoists to the preheader
   like retail (nd 0). */
#pragma opt_loop_invariants on
s32 func_0015d000(u8 *arg0)
{
    s32 handle;
    s32 count;
    u16 *work;
    s32 i;

    if (arg0 == 0) {
        return 1;
    }
    if (func_004553c0(arg0) == 0) {
        return 0;
    }
    func_0044ea90(D_005F07C0, 0x1B3);
    handle = (s32)D_008873F4[0](1, *(u32 *)(arg0 + 0x118), 0x40000);
    D_00764384 = handle;
    func_0043f810((void *)handle, *(void **)(arg0 + 0x110), *(s32 *)(arg0 + 0x118));
    count = *(u32 *)(arg0 + 0x118) / 0x84;
    D_0076438C = count;
    work = (u16 *)D_00764384;
    i = 0;
    while (i < count) {
        if (*work == 0xFFFF) {
            D_00764388 += 1;
        }
        i++;
        work = (u16 *)((u8 *)work + 0x84);
    }
    func_00454bd0(arg0);
    return 1;
}
/* measured: see annotation above (func_0015d000). */
#pragma opt_loop_invariants off


// FUN_0015D100
void func_0015d100(u8 *arg0, s32 arg1)
{
    char spB0[0x80];
    char sp30[0x80];

    func_00442830(spB0, D_005F0790);
    func_00442088(sp30, D_005F0850, arg1);
    if (func_00454570(sp30) != 0) {
        func_00440b68(&D_00762F20, D_005F07C0, 0x1DF);
        *(s32 *)(arg0 + 0xC) = (s32)func_00454a60(sp30, 1);
    }
}


// FUN_0015D1A0
s32 func_0015d1a0(u8 *arg0)
{
    s32 size;

    if (*(s32 *)(arg0 + 0xC) == 0) {
        return 1;
    }
    if (func_004553c0(*(u8 **)(arg0 + 0xC)) == 0) {
        goto ret0;
    }
    func_0044ea90(D_005F07C0, 0x1F6);
    size = *(u32 *)(*(u8 **)(arg0 + 0xC) + 0x118);
    *(s32 *)(arg0 + 0x14) = (s32)D_008873F4[0](1, size, 0x40000);
    *(s32 *)(arg0 + 0x18) = *(s32 *)(*(u8 **)(arg0 + 0xC) + 0x118);
    func_0043f810(*(void **)(arg0 + 0x14), *(void **)(*(u8 **)(arg0 + 0xC) + 0x110), *(s32 *)(*(u8 **)(arg0 + 0xC) + 0x118));
    func_00454bd0(*(u8 **)(arg0 + 0xC));
    *(s32 *)(arg0 + 0xC) = 0;
    return 1;
ret0:
    return 0;
}
