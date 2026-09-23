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
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
void func_00266050(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0);
void func_00265110(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, u32 arg3,
                   s32 arg4);
void func_00265f40(s32 arg0, s32 arg1, u32 arg2, s32 arg3, u8 *arg4,
                   f32 fparg0, s32 arg5, f32 fparg1, f32 fparg2);
s32 func_00442088(char *buf, const char *fmt, ...);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_0046aea0(const char *name);
s32 func_0046a750(s32 param);
extern s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
extern u8 D_006376F0[];
extern u8 D_00637710[];
extern u8 D_00637850[];
extern u8 D_00637A40[];
extern u8 D_00637D00[];
extern u8 D_00637EB0[];
extern u8 D_00638170[];
extern u8 D_006384C0[];
extern u8 D_00638590[];
extern u8 D_006388C0[];
extern u8 D_00638BB0[];
extern u8 D_00638CE0[];
void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);

/* 8-byte element copied by func_00266050's setup loops. */
typedef struct { s32 v[2]; } Pair;

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
    func_00456150(func_00454a60(D_006376D0, 1));
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
        func_00442088((char *)buf, (const char *)D_006376F0, p[4]);
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

/* measured: loop-invariant probe for integer-to-float hoisting in 00265f40. */
#pragma opt_loop_invariants on
// FUN_00265F40
void func_00265f40(s32 arg0, s32 arg1, u32 arg2, s32 arg3, u8 *arg4,
                   f32 fparg0, s32 arg5, f32 fparg1, f32 fparg2)
{
    typedef struct {
        f32 x;
        f32 y;
    } Vec2;
    Vec2 vertices[0x100];
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
                        fparg1 * ((Vec2 *)arg4)[i].x;
        vertices[i].y = (f32)arg1 +
                        fparg2 * ((Vec2 *)arg4)[i].y;
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

/* No real C body was produced for this 1600-byte window. The nd 7 result came
   from an 8-byte empty stub and is a size-deficit artifact, not a near miss. */
/* measured: candidate object 400 instrs/retail 400 instrs (1600B/1600B exact), probe reloc-masked 332 words (guard below, NON_MATCHING so production stays ASM; fnalign 207 edits). Eleven Pair copies (0x28/0x3D/0x58/0x35/0x57/0x6A/0x19/0x66/0x5D/0x26/0x41) plus 13-entry jtbl_00747FE0 dispatch (case0->tail) with 00265f40 calls and 0045d6e0 tail. Table-dispatch shape copies MATCHed 00265110 conventions. Banked as floor. */
/* re-measured 00266050: `python3 -E -s tools/measure_guarded.py src/cldDayChange.c func_00266050`
   reports 332 differing words today.  The figures in the note above are
   from earlier bodies and no longer describe what is banked here; they
   are kept only as history.  Flagged by `tools/floorboard.py --audit`. */
// FUN_00266050 NONMATCHING
#ifdef NON_MATCHING
void func_00266050(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0)
{
    Pair b0[0x28];
    Pair b1[0x3D];
    Pair b2[0x58];
    Pair b3[0x35];
    Pair b4[0x57];
    Pair b5[0x6A];
    Pair b6[0x19];
    Pair b7[0x66];
    Pair b8[0x5D];
    Pair b9[0x26];
    Pair b10[0x41];
    Pair *src;
    Pair *dst;
    s32 n;
    u32 col;
    u32 c6;
    u8 tail[4];
    s32 stack[4];

    src = (Pair *)D_00637710; dst = b0; n = 0x28;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00637850; dst = b1; n = 0x3D;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00637A40; dst = b2; n = 0x58;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00637D00; dst = b3; n = 0x35;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00637EB0; dst = b4; n = 0x57;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00638170; dst = b5; n = 0x6A;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_006384C0; dst = b6; n = 0x19;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00638590; dst = b7; n = 0x66;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_006388C0; dst = b8; n = 0x5D;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00638BB0; dst = b9; n = 0x26;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    src = (Pair *)D_00638CE0; dst = b10; n = 0x41;
    do { *dst = *src; src++; dst++; n--; } while (n > 0);
    col = ((u32)(arg2 & 0xFF)) | 0x23232300;
    if ((u32)arg3 >= 0xD) {
        goto tail;
    }
    c6 = col >> 8;
    switch (arg3) {
    case 0:
        break;
    case 1:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b0, fparg0, 0x28, 1.0f, 1.0f);
        break;
    case 2:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b1, fparg0, 0x3D, 1.0f, 1.0f);
        break;
    case 3:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b2, fparg0, 0x58, 1.0f, 1.0f);
        break;
    case 4:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b3, fparg0, 0x35, 1.0f, 1.0f);
        break;
    case 5:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b4, fparg0, 0x57, 1.0f, 1.0f);
        break;
    case 6:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b5, fparg0, 0x6A, 1.0f, 1.0f);
        break;
    case 7:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b6, fparg0, 0x19, 1.0f, 1.0f);
        break;
    case 8:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b7, fparg0, 0x66, 1.0f, 1.0f);
        break;
    case 9:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b8, fparg0, 0x5D, 1.0f, 1.0f);
        break;
    case 10:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b9, fparg0, 0x26, 1.0f, 1.0f);
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b10, fparg0, 0x41, 1.0f, 1.0f);
        break;
    case 11:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b9, fparg0, 0x26, 1.0f, 1.0f);
        func_00265f40(arg0 + 0x88, arg1, c6, 0xFF, (u8 *)b9, fparg0, 0x26, 1.0f, 1.0f);
        break;
    case 12:
        func_00265f40(arg0, arg1, c6, 0xFF, (u8 *)b9, fparg0, 0x26, 1.0f, 1.0f);
        func_00265f40(arg0 + 0x45, arg1 + 6, c6, 0xFF, (u8 *)b0, fparg0, 0x3D, 1.0f, 1.0f);
        break;
    default:
        break;
    }
tail:
    tail[0] = 0;
    tail[1] = 0;
    tail[2] = 0;
    tail[3] = (u8)(0xFF - (arg2 & 0xFF));
    stack[0] = arg0;
    stack[1] = arg1;
    stack[2] = 0x100;
    stack[3] = 0xF5;
    func_0045d6e0(tail, stack, 0.0f, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/cldDayChange", func_00266050);
#endif


/* measured: the hidden fifth float argument of func_00266050 is 0.0f, not
   336.0f -- retail's `mtc1 $zero,$f12` is that argument, and the same register
   is the `adda.s` seed of the 336 + 128*sin chain. The angle scale is
   iGpffff84a4 (pi/2, retail gp-0x7b5c), not iGpffff8570: relocation masking
   hid that substitution and the full link caught it. The switch table sits
   at 0x748020, after func_00266050's table (0x747FE0), so that INCLUDE_ASM
   fallback carries its own jump table in .rodata to keep the unit's rodata
   concatenation byte-exact. */
// FUN_00266690
void func_00266690(s32 arg0, s32 arg1)
{
    extern void func_00266050(s32, s32, s32, s32, f32);
    extern void func_00265110(s32, s32, f32, s32, u32, s32);
    extern f32 func_0044b610(f32);
    extern f32 func_0044b7b0(f32);
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
        value = 336.0f + 128.0f * func_0044b610(iGpffff84a4 * ratio);
        func_00266050((s32)value, 0, alpha, *(s32 *)(p + 0x10), 0.0f);
        func_00265110(0x150, 0, 0.0f, alpha, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 2:
    case 3:
        func_00266050(0x150, 0, 0xFF, *(s32 *)(p + 0x10), 0.0f);
        func_00265110(0x150, 0, 0.0f, 0xFF, *(u32 *)(p + 0x10),
                      *(s32 *)(p + 0x1C));
        break;
    case 4:
    case 5:
        ratio = (f32)*(s32 *)(p + 0x18) / 10.0f;
        alpha = (s32)(255.0f * (1.0f - ratio));
        value = 336.0f - 192.0f * func_0044b7b0(iGpffff84a4 * ratio);
        func_00266050((s32)value, 0, alpha, *(s32 *)(p + 0x10), 0.0f);
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
