#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - cldDayChange.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern u8 iGpffffa6c8;
extern u8 D_006376B0[];
extern u8 D_006376C0[];
extern u8 D_006376D0[];
extern u8 D_00638EF0[];
extern u8 *func_00452560();
extern u8 *func_00460990();
extern void func_00460ac0(void *, void *);
extern u8 *func_00452560();
extern void func_0046b0d0(void *);
void func_0046d730(const void *file, s32 line);
void func_0044ea90(const void *msg, s32 id);

s32 func_0045a8d0();
s32 func_004598e0();
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
s32 func_00263460(u8 *task);
void func_00264d10(u8 *task);
void func_00266690(s32 arg0, s32 arg1);
s32 func_00264ec0(u8 *arg0);
void func_00266890(s32 arg0, u8 *arg1);
void func_002668f0(u8 *arg0);
void func_00364c50(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   u8 *arg4, s32 arg5, s32 arg6);
void func_00364c70(void);
void func_0045dfd0(void *arg0, void *arg1, f32 fparg0, s32 arg2, s32 arg3,
                   s32 arg4);
extern f32 iGpffff84a4;
extern f32 iGpffff84a4;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
void func_00266050(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3);
void func_00265110(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, u32 arg3,
                   s32 arg4);
void func_00265f40(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3,
                   u8 *arg4, s32 arg5, f32 fparg1, f32 fparg2);
s32 sprintf(char *buf, const char *fmt, ...);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_0046aea0(const char *name);
s32 func_0046a750(s32 param);
extern s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
extern u8 D_006376F0[];
void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);


// FUN_00264D90
void func_00264d90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    if (arg3 == 0) {
        func_0046d730(&D_006376B0, 0x451);
    }
    func_0044ea90(&D_006376B0, 0x452);
    p = D_008873F4[0](1, 0x24, 0x40000);
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 8) = arg3;
    *(s32 *)(p + 0xC) = arg1;
    *(s32 *)(p + 0x10) = arg2;
    *(s32 *)(p + 0x18) = arg1;
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_006376C0), 0x10, 0, 0, func_00263460, func_00264d10, (u8 *)(p));
}

// FUN_00264E70
void func_00264e70(void)
{
    func_00440b68(&iGpffffa6c8, D_006376B0, 0x464);
    H_Cdvd_ReadSync(func_00454a60(D_006376D0, 1));
}

// FUN_00264EC0
s32 func_00264ec0(u8 *arg0) {
    s32 *p;
    u8 buf[0x4C];
    u32 tmp;
    u8 *s;

    p = (s32 *)func_00452560();
    switch (p[0]) {
    case 0:
        p[0] = 1;
        /* fallthrough */
    case 1:
        if (p[1] & 1) {
            p[1] &= ~1;
            p[0] = 4;
            p[1] |= 4;
            p[4] = p[5];
            p[5] = 0;
        }
        break;
    case 2:
        if (p[2] != 0) {
            func_0046b0d0((void *)p[2]);
            p[2] = 0;
            p[1] &= ~4;
        }
        sprintf((char *)buf, (const char *)D_006376F0, p[4]);
        s = func_00455f70(buf, &tmp);
        if (s == 0) {
            p[2] = (s32)func_0046aea0((const char *)buf);
            p[0] = 3;
        } else {
            p[2] = (s32)func_0046af60((u32)s);
            p[0] = 3;
        }
        break;
    case 3:
        if (func_0046a750(p[2]) != 0) {
            p[0] = 4;
            p[1] |= 4;
        }
        break;
    case 4:
        p[0] = 5;
        p[6] = 0;
        /* fallthrough */
    case 5:
        p[6]++;
        if (p[6] >= 7) {
            p[0] = 6;
            p[6] = 0;
        }
        break;
    case 6:
        p[0] = 7;
        p[6] = 0;
        /* fallthrough */
    case 7:
        if ((p[1] & 2) || (p[1] & 1)) {
            p[1] &= ~2;
            p[0] = 8;
            p[6] = 0;
        }
        break;
    case 8:
        p[0] = 9;
        p[6] = 0;
        /* fallthrough */
    case 9:
        p[6]++;
        if (p[6] >= 10) {
            p[0] = 10;
            p[6] = 0;
        }
        break;
    case 10:
        p[0] = 1;
        break;
    }
    func_00266890((s32)arg0, (u8 *)p[3]);
    return 0;
}

// FUN_00265110
void func_00265110(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, u32 arg3,
                   s32 arg4) {
    if (arg4 != 0) {
        switch (arg3) {
        case 4:
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 5:
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 6:
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 7:
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 8:
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 9:
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 10:
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 11:
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 12:
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C, arg2, 0x12, 0, (u8 *)(arg4), 1);
            return;
        case 1:
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C, arg2, 0x11, 0, (u8 *)(arg4), 1);
            return;
        case 2:
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C, arg2, 0x11, 0, (u8 *)(arg4), 1);
            return;
        case 3:
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C, arg2, 0xB, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C, arg2, 0xC, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C, arg2, 0x10, 0, (u8 *)(arg4), 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C, arg2, 0x11, 0, (u8 *)(arg4), 1);
            break;
        }
    }
}

typedef struct { f32 x, y; } DayChangePoint;

/* measured: loop-invariant probe for integer-to-float hoisting in 00265f40. */
#pragma opt_loop_invariants on
// FUN_00265F40
void func_00265f40(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3,
                   u8 *arg4, s32 arg5, f32 fparg1, f32 fparg2)
{
    DayChangePoint vertices[0x100];
    u8 colors[0x400];
    u32 color;
    s32 i;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;

    color = (arg2 << 8) | arg3;
    i = 0;
    c0 = (u8)(color >> 24);
    c1 = (u8)(color >> 16);
    c2 = (u8)(color >> 8);
    c3 = (u8)color;
    while (i < arg5) {
        vertices[i].x = (f32)arg0 +
                        fparg1 * ((DayChangePoint *)arg4)[i].x;
        vertices[i].y = (f32)arg1 +
                        fparg2 * ((DayChangePoint *)arg4)[i].y;
        colors[i * 4 + 0] = c0;
        colors[i * 4 + 1] = c1;
        colors[i * 4 + 2] = c2;
        colors[i * 4 + 3] = c3;
        i += 1;
    }
    func_00364c50(arg0, arg1, c3, c2, arg4, c1, c0);
    func_0045dfd0(colors, vertices, fparg0, arg5, 4, 1);
    func_00364c70();
}
/* measured: closes loop-invariant probe for func_00265f40. */
#pragma opt_loop_invariants off

/* Native b210 O2: 1600/1600 bytes and 41 fully resolved code relocations.
 * The eleven local point-array initializers produce retail's two-word copy
 * loops. All eleven constant arrays and the thirteen-entry dispatch table
 * are independently exact. Keep the float third in this function and its
 * drawing helper's coherent declarations and calls.
 * See docs/probe_archive/Day_change_00266050_20260924.md. */
// FUN_00266050
void func_00266050(s32 x, s32 y, f32 depth, s32 opacity, s32 month)
{
    extern f32 iGpffff8570;
    DayChangePoint outline1[0x28] = {
        {56.0f, 86.0f}, {59.0f, 90.0f}, {55.0f, 75.0f},
        {62.0f, 90.0f}, {53.0f, 69.0f}, {84.0f, 79.0f},
        {53.0f, 63.0f}, {95.0f, 73.0f}, {55.0f, 59.0f},
        {101.0f, 70.0f}, {84.0f, 46.0f}, {109.0f, 66.0f},
        {108.0f, 33.0f}, {117.0f, 62.0f}, {134.0f, 18.0f},
        {118.0f, 68.0f}, {147.0f, 18.0f}, {118.0f, 76.0f},
        {158.0f, 15.0f}, {118.0f, 85.0f}, {163.0f, 16.0f},
        {118.0f, 111.0f}, {165.0f, 19.0f}, {118.0f, 120.0f},
        {165.0f, 40.0f}, {118.0f, 151.0f}, {163.0f, 91.0f},
        {118.0f, 183.0f}, {163.0f, 166.0f}, {116.0f, 233.0f},
        {164.0f, 189.0f}, {118.0f, 236.0f}, {164.0f, 198.0f},
        {127.0f, 236.0f}, {165.0f, 212.0f}, {140.0f, 235.0f},
        {165.0f, 219.0f}, {155.0f, 236.0f}, {165.0f, 233.0f},
        {162.0f, 236.0f},
    };
    DayChangePoint outline2[0x3D] = {
        {62.0f, 85.0f}, {65.0f, 85.0f}, {59.0f, 73.0f},
        {70.0f, 77.0f}, {52.0f, 58.0f}, {75.0f, 67.0f},
        {52.0f, 50.0f}, {83.0f, 57.0f}, {60.0f, 39.0f},
        {96.0f, 48.0f}, {70.0f, 31.0f}, {105.0f, 44.0f},
        {83.0f, 23.0f}, {116.0f, 41.0f}, {102.0f, 16.0f},
        {124.0f, 41.0f}, {118.0f, 13.0f}, {130.0f, 41.0f},
        {143.0f, 13.0f}, {138.0f, 44.0f}, {170.0f, 19.0f},
        {146.0f, 48.0f}, {189.0f, 30.0f}, {152.0f, 54.0f},
        {199.0f, 40.0f}, {157.0f, 63.0f}, {205.0f, 53.0f},
        {159.0f, 72.0f}, {209.0f, 70.0f}, {158.0f, 86.0f},
        {209.0f, 85.0f}, {154.0f, 98.0f}, {205.0f, 102.0f},
        {149.0f, 108.0f}, {199.0f, 114.0f}, {141.0f, 120.0f},
        {185.0f, 131.0f}, {132.0f, 132.0f}, {164.0f, 151.0f},
        {112.0f, 153.0f}, {138.0f, 171.0f}, {99.0f, 166.0f},
        {120.0f, 184.0f}, {73.0f, 189.0f}, {115.0f, 188.0f},
        {49.0f, 209.0f}, {107.0f, 195.0f}, {46.0f, 215.0f},
        {113.0f, 195.0f}, {46.0f, 231.0f}, {121.0f, 195.0f},
        {49.0f, 235.0f}, {167.0f, 195.0f}, {206.0f, 235.0f},
        {188.0f, 193.0f}, {210.0f, 230.0f}, {206.0f, 191.0f},
        {211.0f, 216.0f}, {212.0f, 192.0f}, {214.0f, 202.0f},
        {214.0f, 196.0f},
    };
    DayChangePoint outline3[0x58] = {
        {59.0f, 75.0f}, {64.0f, 76.0f}, {57.0f, 69.0f},
        {77.0f, 59.0f}, {56.0f, 56.0f}, {81.0f, 56.0f},
        {54.0f, 49.0f}, {84.0f, 53.0f}, {55.0f, 39.0f},
        {93.0f, 48.0f}, {66.0f, 29.0f}, {100.0f, 45.0f},
        {82.0f, 21.0f}, {112.0f, 42.0f}, {98.0f, 16.0f},
        {122.0f, 41.0f}, {117.0f, 13.0f}, {133.0f, 42.0f},
        {143.0f, 13.0f}, {142.0f, 46.0f}, {169.0f, 18.0f},
        {149.0f, 51.0f}, {186.0f, 27.0f}, {153.0f, 57.0f},
        {197.0f, 39.0f}, {155.0f, 61.0f}, {203.0f, 53.0f},
        {155.0f, 72.0f}, {204.0f, 66.0f}, {152.0f, 80.0f},
        {203.0f, 79.0f}, {149.0f, 86.0f}, {199.0f, 91.0f},
        {143.0f, 93.0f}, {191.0f, 102.0f}, {133.0f, 100.0f},
        {182.0f, 109.0f}, {121.0f, 104.0f}, {176.0f, 113.0f},
        {95.0f, 104.0f}, {180.0f, 115.0f}, {93.0f, 106.0f},
        {186.0f, 118.0f}, {93.0f, 131.0f}, {191.0f, 121.0f},
        {94.0f, 133.0f}, {199.0f, 127.0f}, {127.0f, 133.0f},
        {205.0f, 134.0f}, {142.0f, 137.0f}, {208.0f, 138.0f},
        {154.0f, 143.0f}, {213.0f, 148.0f}, {161.0f, 150.0f},
        {216.0f, 160.0f}, {167.0f, 162.0f}, {216.0f, 175.0f},
        {167.0f, 170.0f}, {213.0f, 190.0f}, {164.0f, 180.0f},
        {208.0f, 202.0f}, {158.0f, 191.0f}, {196.0f, 216.0f},
        {150.0f, 199.0f}, {182.0f, 226.0f}, {139.0f, 205.0f},
        {168.0f, 232.0f}, {130.0f, 208.0f}, {152.0f, 236.0f},
        {117.0f, 211.0f}, {130.0f, 239.0f}, {99.0f, 211.0f},
        {97.0f, 239.0f}, {86.0f, 207.0f}, {74.0f, 234.0f},
        {69.0f, 198.0f}, {55.0f, 226.0f}, {65.0f, 195.0f},
        {44.0f, 218.0f}, {63.0f, 193.0f}, {43.0f, 214.0f},
        {59.0f, 188.0f}, {44.0f, 205.0f}, {57.0f, 183.0f},
        {47.0f, 194.0f}, {54.0f, 179.0f}, {47.0f, 182.0f},
        {49.0f, 179.0f},
    };
    DayChangePoint outline4[0x35] = {
        {142.0f, 201.0f}, {142.0f, 163.0f}, {53.0f, 202.0f},
        {125.0f, 163.0f}, {34.0f, 202.0f}, {99.0f, 163.0f},
        {32.0f, 199.0f}, {88.0f, 163.0f}, {32.0f, 179.0f},
        {80.0f, 162.0f}, {33.0f, 176.0f}, {144.0f, 73.0f},
        {146.0f, 23.0f}, {143.0f, 98.0f}, {151.0f, 18.0f},
        {143.0f, 113.0f}, {163.0f, 18.0f}, {143.0f, 125.0f},
        {174.0f, 15.0f}, {143.0f, 133.0f}, {180.0f, 15.0f},
        {142.0f, 150.0f}, {182.0f, 20.0f}, {142.0f, 162.0f},
        {183.0f, 58.0f}, {142.0f, 167.0f}, {183.0f, 162.0f},
        {142.0f, 173.0f}, {212.0f, 161.0f}, {142.0f, 176.0f},
        {218.0f, 161.0f}, {141.0f, 179.0f}, {220.0f, 164.0f},
        {142.0f, 182.0f}, {221.0f, 172.0f}, {142.0f, 186.0f},
        {220.0f, 199.0f}, {142.0f, 188.0f}, {217.0f, 202.0f},
        {142.0f, 190.0f}, {208.0f, 202.0f}, {142.0f, 195.0f},
        {184.0f, 201.0f}, {142.0f, 208.0f}, {184.0f, 233.0f},
        {142.0f, 215.0f}, {181.0f, 236.0f}, {142.0f, 223.0f},
        {170.0f, 235.0f}, {142.0f, 226.0f}, {155.0f, 235.0f},
        {142.0f, 231.0f}, {145.0f, 236.0f},
    };
    DayChangePoint outline5[0x57] = {
        {200.0f, 13.0f}, {202.0f, 15.0f}, {197.0f, 13.0f},
        {202.0f, 27.0f}, {163.0f, 16.0f}, {200.0f, 35.0f},
        {126.0f, 18.0f}, {198.0f, 43.0f}, {73.0f, 18.0f},
        {197.0f, 53.0f}, {69.0f, 22.0f}, {193.0f, 57.0f},
        {68.0f, 30.0f}, {95.0f, 57.0f}, {67.0f, 42.0f},
        {93.0f, 58.0f}, {65.0f, 62.0f}, {88.0f, 92.0f},
        {60.0f, 101.0f}, {87.0f, 99.0f}, {57.0f, 120.0f},
        {99.0f, 96.0f}, {57.0f, 127.0f}, {113.0f, 94.0f},
        {58.0f, 131.0f}, {125.0f, 93.0f}, {63.0f, 134.0f},
        {139.0f, 93.0f}, {68.0f, 134.0f}, {155.0f, 95.0f},
        {81.0f, 128.0f}, {167.0f, 98.0f}, {92.0f, 125.0f},
        {175.0f, 101.0f}, {106.0f, 122.0f}, {183.0f, 105.0f},
        {123.0f, 122.0f}, {189.0f, 109.0f}, {133.0f, 124.0f},
        {197.0f, 116.0f}, {145.0f, 128.0f}, {202.0f, 121.0f},
        {157.0f, 137.0f}, {210.0f, 135.0f}, {162.0f, 145.0f},
        {208.0f, 130.0f}, {165.0f, 152.0f}, {212.0f, 140.0f},
        {165.0f, 166.0f}, {215.0f, 153.0f}, {165.0f, 167.0f},
        {215.0f, 174.0f}, {163.0f, 177.0f}, {213.0f, 184.0f},
        {158.0f, 187.0f}, {211.0f, 191.0f}, {148.0f, 198.0f},
        {208.0f, 197.0f}, {139.0f, 203.0f}, {202.0f, 208.0f},
        {129.0f, 207.0f}, {196.0f, 214.0f}, {118.0f, 210.0f},
        {185.0f, 223.0f}, {101.0f, 210.0f}, {175.0f, 228.0f},
        {93.0f, 208.0f}, {162.0f, 233.0f}, {84.0f, 205.0f},
        {147.0f, 237.0f}, {74.0f, 200.0f}, {134.0f, 239.0f},
        {66.0f, 194.0f}, {120.0f, 240.0f}, {56.0f, 184.0f},
        {104.0f, 240.0f}, {53.0f, 184.0f}, {91.0f, 238.0f},
        {51.0f, 186.0f}, {74.0f, 234.0f}, {50.0f, 195.0f},
        {61.0f, 229.0f}, {50.0f, 203.0f}, {51.0f, 224.0f},
        {47.0f, 210.0f}, {47.0f, 220.0f}, {46.0f, 215.0f},
    };
    DayChangePoint outline6[0x6A] = {
        {190.0f, 16.0f}, {186.0f, 13.0f}, {190.0f, 32.0f},
        {163.0f, 13.0f}, {193.0f, 41.0f}, {145.0f, 13.0f},
        {192.0f, 47.0f}, {135.0f, 14.0f}, {190.0f, 50.0f},
        {129.0f, 15.0f}, {186.0f, 50.0f}, {124.0f, 16.0f},
        {167.0f, 42.0f}, {114.0f, 19.0f}, {153.0f, 39.0f},
        {106.0f, 22.0f}, {137.0f, 39.0f}, {97.0f, 26.0f},
        {126.0f, 43.0f}, {89.0f, 31.0f}, {118.0f, 48.0f},
        {80.0f, 37.0f}, {111.0f, 54.0f}, {71.0f, 47.0f},
        {104.0f, 62.0f}, {63.0f, 57.0f}, {97.0f, 74.0f},
        {56.0f, 69.0f}, {93.0f, 84.0f}, {51.0f, 79.0f},
        {89.0f, 98.0f}, {47.0f, 91.0f}, {87.0f, 107.0f},
        {44.0f, 103.0f}, {111.0f, 121.0f}, {42.0f, 115.0f},
        {104.0f, 126.0f}, {41.0f, 124.0f}, {100.0f, 130.0f},
        {40.0f, 144.0f}, {94.0f, 140.0f}, {42.0f, 164.0f},
        {91.0f, 152.0f}, {46.0f, 180.0f}, {89.0f, 166.0f},
        {51.0f, 193.0f}, {90.0f, 178.0f}, {57.0f, 203.0f},
        {93.0f, 188.0f}, {64.0f, 213.0f}, {97.0f, 195.0f},
        {73.0f, 221.0f}, {105.0f, 204.0f}, {83.0f, 228.0f},
        {113.0f, 210.0f}, {93.0f, 233.0f}, {120.0f, 212.0f},
        {102.0f, 236.0f}, {126.0f, 214.0f}, {111.0f, 238.0f},
        {138.0f, 214.0f}, {118.0f, 239.0f}, {144.0f, 212.0f},
        {132.0f, 240.0f}, {151.0f, 209.0f}, {155.0f, 238.0f},
        {159.0f, 201.0f}, {172.0f, 233.0f}, {166.0f, 187.0f},
        {187.0f, 225.0f}, {168.0f, 179.0f}, {203.0f, 211.0f},
        {169.0f, 161.0f}, {212.0f, 197.0f}, {168.0f, 151.0f},
        {218.0f, 181.0f}, {166.0f, 143.0f}, {220.0f, 167.0f},
        {163.0f, 136.0f}, {220.0f, 156.0f}, {161.0f, 131.0f},
        {217.0f, 138.0f}, {158.0f, 127.0f}, {212.0f, 125.0f},
        {155.0f, 124.0f}, {204.0f, 112.0f}, {149.0f, 120.0f},
        {193.0f, 102.0f}, {144.0f, 118.0f}, {179.0f, 95.0f},
        {140.0f, 117.0f}, {167.0f, 91.0f}, {138.0f, 116.0f},
        {148.0f, 88.0f}, {133.0f, 116.0f}, {134.0f, 88.0f},
        {129.0f, 116.0f}, {126.0f, 89.0f}, {123.0f, 116.0f},
        {112.0f, 93.0f}, {115.0f, 119.0f}, {101.0f, 98.0f},
        {110.0f, 121.0f}, {94.0f, 103.0f}, {108.0f, 123.0f},
        {88.0f, 107.0f},
    };
    DayChangePoint outline7[0x19] = {
        {48.0f, 60.0f}, {51.0f, 64.0f}, {49.0f, 40.0f},
        {56.0f, 64.0f}, {48.0f, 28.0f}, {73.0f, 62.0f},
        {49.0f, 20.0f}, {88.0f, 61.0f}, {52.0f, 17.0f},
        {121.0f, 60.0f}, {213.0f, 18.0f}, {149.0f, 60.0f},
        {217.0f, 23.0f}, {159.0f, 60.0f}, {217.0f, 39.0f},
        {168.0f, 60.0f}, {215.0f, 46.0f}, {58.0f, 221.0f},
        {93.0f, 232.0f}, {56.0f, 226.0f}, {91.0f, 236.0f},
        {56.0f, 232.0f}, {75.0f, 235.0f}, {58.0f, 235.0f},
        {64.0f, 236.0f},
    };
    DayChangePoint outline8[0x66] = {
        {77.0f, 121.0f}, {146.0f, 102.0f}, {65.0f, 112.0f},
        {125.0f, 95.0f}, {62.0f, 109.0f}, {108.0f, 87.0f},
        {58.0f, 105.0f}, {97.0f, 80.0f}, {49.0f, 88.0f},
        {91.0f, 73.0f}, {47.0f, 76.0f}, {88.0f, 66.0f},
        {47.0f, 67.0f}, {88.0f, 60.0f}, {50.0f, 53.0f},
        {93.0f, 52.0f}, {57.0f, 41.0f}, {98.0f, 47.0f},
        {69.0f, 30.0f}, {104.0f, 43.0f}, {80.0f, 23.0f},
        {116.0f, 39.0f}, {93.0f, 18.0f}, {124.0f, 38.0f},
        {110.0f, 14.0f}, {133.0f, 38.0f}, {119.0f, 13.0f},
        {148.0f, 41.0f}, {143.0f, 13.0f}, {152.0f, 43.0f},
        {168.0f, 18.0f}, {158.0f, 47.0f}, {180.0f, 23.0f},
        {162.0f, 52.0f}, {196.0f, 35.0f}, {167.0f, 63.0f},
        {204.0f, 46.0f}, {167.0f, 76.0f}, {209.0f, 62.0f},
        {163.0f, 87.0f}, {209.0f, 78.0f}, {157.0f, 94.0f},
        {207.0f, 87.0f}, {153.0f, 98.0f}, {201.0f, 98.0f},
        {141.0f, 104.0f}, {193.0f, 106.0f}, {133.0f, 106.0f},
        {177.0f, 116.0f}, {74.0f, 121.0f}, {104.0f, 134.0f},
        {60.0f, 129.0f}, {92.0f, 141.0f}, {49.0f, 140.0f},
        {84.0f, 152.0f}, {43.0f, 148.0f}, {79.0f, 166.0f},
        {37.0f, 163.0f}, {79.0f, 177.0f}, {36.0f, 173.0f},
        {83.0f, 188.0f}, {36.0f, 181.0f}, {90.0f, 197.0f},
        {38.0f, 193.0f}, {97.0f, 204.0f}, {43.0f, 205.0f},
        {102.0f, 207.0f}, {48.0f, 212.0f}, {107.0f, 209.0f},
        {63.0f, 225.0f}, {114.0f, 211.0f}, {80.0f, 233.0f},
        {121.0f, 212.0f}, {104.0f, 238.0f}, {133.0f, 212.0f},
        {128.0f, 239.0f}, {153.0f, 208.0f}, {145.0f, 239.0f},
        {159.0f, 205.0f}, {167.0f, 235.0f}, {167.0f, 199.0f},
        {187.0f, 227.0f}, {174.0f, 187.0f}, {203.0f, 216.0f},
        {175.0f, 183.0f}, {211.0f, 206.0f}, {175.0f, 176.0f},
        {217.0f, 194.0f}, {172.0f, 171.0f}, {220.0f, 181.0f},
        {170.0f, 168.0f}, {220.0f, 163.0f}, {167.0f, 164.0f},
        {215.0f, 149.0f}, {161.0f, 159.0f}, {208.0f, 139.0f},
        {154.0f, 154.0f}, {198.0f, 129.0f}, {140.0f, 146.0f},
        {182.0f, 119.0f}, {104.0f, 132.0f}, {172.0f, 113.0f},
    };
    DayChangePoint outline9[0x5D] = {
        {171.0f, 144.0f}, {168.0f, 98.0f}, {162.0f, 150.0f},
        {164.0f, 109.0f}, {155.0f, 154.0f}, {159.0f, 118.0f},
        {148.0f, 157.0f}, {151.0f, 125.0f}, {136.0f, 160.0f},
        {133.0f, 133.0f}, {118.0f, 162.0f}, {119.0f, 133.0f},
        {103.0f, 161.0f}, {108.0f, 129.0f}, {88.0f, 158.0f},
        {101.0f, 123.0f}, {73.0f, 152.0f}, {96.0f, 118.0f},
        {59.0f, 142.0f}, {91.0f, 108.0f}, {51.0f, 133.0f},
        {88.0f, 92.0f}, {42.0f, 113.0f}, {88.0f, 77.0f},
        {39.0f, 95.0f}, {91.0f, 65.0f}, {39.0f, 86.0f},
        {95.0f, 54.0f}, {42.0f, 68.0f}, {100.0f, 48.0f},
        {49.0f, 52.0f}, {108.0f, 42.0f}, {58.0f, 40.0f},
        {119.0f, 38.0f}, {70.0f, 29.0f}, {126.0f, 38.0f},
        {84.0f, 21.0f}, {135.0f, 38.0f}, {98.0f, 16.0f},
        {143.0f, 41.0f}, {115.0f, 13.0f}, {148.0f, 43.0f},
        {139.0f, 13.0f}, {157.0f, 53.0f}, {160.0f, 17.0f},
        {159.0f, 57.0f}, {176.0f, 24.0f}, {162.0f, 64.0f},
        {188.0f, 33.0f}, {162.0f, 64.0f}, {200.0f, 46.0f},
        {164.0f, 71.0f}, {210.0f, 65.0f}, {167.0f, 84.0f},
        {216.0f, 86.0f}, {169.0f, 107.0f}, {218.0f, 105.0f},
        {170.0f, 127.0f}, {218.0f, 127.0f}, {169.0f, 151.0f},
        {215.0f, 149.0f}, {164.0f, 169.0f}, {211.0f, 164.0f},
        {161.0f, 176.0f}, {206.0f, 176.0f}, {156.0f, 184.0f},
        {200.0f, 187.0f}, {150.0f, 191.0f}, {191.0f, 199.0f},
        {144.0f, 196.0f}, {180.0f, 210.0f}, {135.0f, 202.0f},
        {168.0f, 219.0f}, {127.0f, 205.0f}, {152.0f, 227.0f},
        {120.0f, 207.0f}, {136.0f, 233.0f}, {109.0f, 209.0f},
        {118.0f, 237.0f}, {100.0f, 209.0f}, {100.0f, 239.0f},
        {93.0f, 209.0f}, {77.0f, 239.0f}, {83.0f, 207.0f},
        {59.0f, 237.0f}, {73.0f, 205.0f}, {56.0f, 234.0f},
        {67.0f, 203.0f}, {56.0f, 219.0f}, {60.0f, 200.0f},
        {53.0f, 209.0f}, {55.0f, 200.0f}, {53.0f, 203.0f},
    };
    DayChangePoint outline10[0x26] = {
        {9.0f, 88.0f}, {13.0f, 88.0f}, {7.0f, 84.0f},
        {18.0f, 85.0f}, {7.0f, 74.0f}, {24.0f, 81.0f},
        {5.0f, 69.0f}, {30.0f, 77.0f}, {5.0f, 61.0f},
        {35.0f, 74.0f}, {8.0f, 57.0f}, {38.0f, 72.0f},
        {23.0f, 49.0f}, {41.0f, 70.0f}, {33.0f, 43.0f},
        {44.0f, 68.0f}, {43.0f, 36.0f}, {49.0f, 65.0f},
        {61.0f, 23.0f}, {49.0f, 71.0f}, {67.0f, 23.0f},
        {49.0f, 75.0f}, {80.0f, 20.0f}, {49.0f, 80.0f},
        {85.0f, 20.0f}, {49.0f, 86.0f}, {87.0f, 23.0f},
        {49.0f, 94.0f}, {86.0f, 144.0f}, {47.0f, 219.0f},
        {87.0f, 198.0f}, {47.0f, 236.0f}, {88.0f, 228.0f},
        {50.0f, 240.0f}, {88.0f, 234.0f}, {75.0f, 239.0f},
        {87.0f, 238.0f}, {84.0f, 240.0f},
    };
    DayChangePoint outline11[0x41] = {
        {173.0f, 20.0f}, {174.0f, 45.0f}, {187.0f, 20.0f},
        {184.0f, 45.0f}, {207.0f, 26.0f}, {195.0f, 51.0f},
        {222.0f, 37.0f}, {203.0f, 61.0f}, {233.0f, 52.0f},
        {208.0f, 77.0f}, {241.0f, 69.0f}, {210.0f, 92.0f},
        {245.0f, 83.0f}, {211.0f, 107.0f}, {249.0f, 107.0f},
        {212.0f, 121.0f}, {250.0f, 120.0f}, {212.0f, 146.0f},
        {250.0f, 145.0f}, {210.0f, 177.0f}, {247.0f, 171.0f},
        {204.0f, 198.0f}, {241.0f, 194.0f}, {201.0f, 204.0f},
        {232.0f, 212.0f}, {196.0f, 209.0f}, {221.0f, 225.0f},
        {184.0f, 215.0f}, {207.0f, 234.0f}, {179.0f, 215.0f},
        {191.0f, 239.0f}, {173.0f, 215.0f}, {167.0f, 239.0f},
        {161.0f, 209.0f}, {150.0f, 234.0f}, {157.0f, 205.0f},
        {137.0f, 226.0f}, {153.0f, 198.0f}, {127.0f, 215.0f},
        {148.0f, 181.0f}, {116.0f, 194.0f}, {146.0f, 161.0f},
        {111.0f, 175.0f}, {145.0f, 147.0f}, {108.0f, 157.0f},
        {145.0f, 135.0f}, {107.0f, 143.0f}, {145.0f, 121.0f},
        {107.0f, 121.0f}, {146.0f, 104.0f}, {109.0f, 100.0f},
        {147.0f, 91.0f}, {113.0f, 79.0f}, {149.0f, 77.0f},
        {118.0f, 64.0f}, {154.0f, 61.0f}, {124.0f, 52.0f},
        {158.0f, 55.0f}, {131.0f, 42.0f}, {161.0f, 52.0f},
        {143.0f, 31.0f}, {165.0f, 49.0f}, {153.0f, 25.0f},
        {174.0f, 45.0f}, {173.0f, 20.0f},
    };
    u32 packedColor;
    u8 shade[4];
    union { s32 coordinates[4]; f32 transport[4]; } rectangle;

    packedColor = ((u32)(opacity & 0xFF)) | 0x23232300;
    switch (month) {
    case 0:
        break;
    case 1:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline1, 0x28, 1.0f, 1.0f);
        break;
    case 2:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline2, 0x3D, 1.0f, 1.0f);
        break;
    case 3:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline3, 0x58, 1.0f, 1.0f);
        break;
    case 4:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline4, 0x35, 1.0f, 1.0f);
        break;
    case 5:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline5, 0x57, 1.0f, 1.0f);
        break;
    case 6:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline6, 0x6A, 1.0f, 1.0f);
        break;
    case 7:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline7, 0x19, 1.0f, 1.0f);
        break;
    case 8:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline8, 0x66, 1.0f, 1.0f);
        break;
    case 9:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline9, 0x5D, 1.0f, 1.0f);
        break;
    case 10:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline10, 0x26, 1.0f, 1.0f);
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline11, 0x41, 1.0f, 1.0f);
        break;
    case 11:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline10, 0x26, 1.0f, 1.0f);
        func_00265f40(x + 0x88, y, depth, packedColor >> 8, 0xFF, (u8 *)outline10, 0x26, 1.0f, 1.0f);
        break;
    case 12:
        func_00265f40(x, y, depth, packedColor >> 8, 0xFF, (u8 *)outline10, 0x26, 1.0f, 1.0f);
        func_00265f40(x + 0x45, y + 6, depth, packedColor >> 8, 0xFF, (u8 *)outline2, 0x3D, iGpffff8570, 1.0f);
        break;
    default:
        break;
    }
    shade[0] = 0;
    shade[1] = 0;
    shade[2] = 0;
    shade[3] = (u8)(0xFFU - (u32)opacity);
    rectangle.coordinates[0] = x;
    rectangle.coordinates[1] = y;
    rectangle.coordinates[2] = 0x100;
    rectangle.coordinates[3] = 0xF5;
    func_0045d6e0(shade, rectangle.transport, 0.0f, 1);
}

/* The day renderer's depth is 0.0f. Retail also uses this register as
 * the accumulator seed in the 336 + 128*sin interpolation. The angle scale
 * here is iGpffff84a4 (pi/2); the renderer's separate case-12 horizontal
 * scale is iGpffff8570. This callback's native switch table remains at
 * 0x748020, following the renderer's native table at 0x747FE0. */
// FUN_00266690
void func_00266690(s32 arg0, s32 arg1)
{
    extern void func_00266050(s32, s32, f32, s32, s32);
    extern void func_00265110(s32, s32, f32, s32, u32, s32);
    extern f32 cosf(f32);
    extern f32 sinf(f32);
    extern f32 iGpffff84a4;
    u8 *p;
    s32 state;
    s32 alpha;
    f32 ratio;
    f32 value;

    p = func_00452560(arg1);
    state = *(s32 *)(p + 0) - 4;
    switch (state) {
    case 0:
    case 1:
        ratio = (f32)*(s32 *)(p + 0x18) / 7.0f;
        alpha = (s32)(255.0f * ratio);
        value = 336.0f + 128.0f * cosf(iGpffff84a4 * ratio);
        func_00266050((s32)value, 0, 0.0f, alpha, *(s32 *)(p + 0x10));
        func_00265110(0x150, 0, 0.0f, alpha, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 2:
    case 3:
        func_00266050(0x150, 0, 0.0f, 0xFF, *(s32 *)(p + 0x10));
        func_00265110(0x150, 0, 0.0f, 0xFF, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 4:
    case 5:
        ratio = (f32)*(s32 *)(p + 0x18) / 10.0f;
        alpha = (s32)(255.0f * (1.0f - ratio));
        value = 336.0f - 192.0f * sinf(iGpffff84a4 * ratio);
        func_00266050((s32)value, 0, 0.0f, alpha, *(s32 *)(p + 0x10));
        func_00265110(0x150, 0, 0.0f, alpha, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    }
}

// FUN_00266890
void func_00266890(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266690;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_002668F0
void func_002668f0(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_0046b0d0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00266950
s32 func_00266950(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 r;

    if (arg2 == 0) {
        func_0046d730(&D_006376B0, 0x692);
    }
    func_0044ea90(&D_006376B0, 0x693);
    p = D_008873F4[0](1, 0x24, 0x40000);
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 0xC) = arg2;
    *(s32 *)(p + 0x1C) = arg1;
    r = (s32)func_00451fc0((void *)(arg0), (const void *)(D_00638EF0), 0xF, 0, 0, func_00264ec0, func_002668f0, (u8 *)(p));
    func_0045a8d0(3, 0);
    func_004598e0(0xA);
    return r;
}
