#include "include_asm.h"
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
s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                  s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
s32 func_0045a8d0();
s32 func_004598e0();
extern void *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);
void func_00263460(void);
void func_00264d10(void);
void func_00266690(s32 arg0, s32 arg1);
s32 func_00264ec0(u8 *arg0);
void func_00266890(s32 arg0, u8 *arg1);
void func_002668f0(u8 *arg0);
void func_00364c50(void);
void func_00364c70(void);
void func_0045dfd0(void *arg0, void *arg1, f32 fparg0, s32 arg2, s32 arg3,
                   s32 arg4);
extern f32 iGpffff84a4;
extern f32 iGpffff8570;
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
s32 func_0046af60(u8 *arg0);
s32 func_0046a750(s32 param);
extern void func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, s32, s32);
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
    func_00451fc0(arg0, D_006376C0, 0x10, 0, 0, (s32 (*)(u8 *))func_00263460,
                  (void (*)(u8 *))func_00264d10, p);
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
            p[2] = func_0046af60(s);
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
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x1E), (f32)(arg1 + 0x62), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 5:
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x23), (f32)(arg1 + 0x98), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 6:
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA), (f32)(arg1 + 0xCC), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 7:
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x90), (f32)(arg1 + 0xCF), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 8:
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x2), (f32)(arg1 + 0x95), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 9:
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xA2), (f32)(arg1 + 0xC1), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 10:
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0xB3), (f32)(arg1 + 0xD9), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 11:
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x7F), (f32)(arg1 + 0xC9), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 12:
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 - 0xC), (f32)(arg1 + 0xCA), fparg0, 0x4C4C4C,
                          arg2, 0x12, 0, arg4, 1);
            return;
        case 1:
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x99), (f32)(arg1 + 0xB7), fparg0, 0x4C4C4C,
                          arg2, 0x11, 0, arg4, 1);
            return;
        case 2:
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x93), (f32)(arg1 + 0x90), fparg0, 0x4C4C4C,
                          arg2, 0x11, 0, arg4, 1);
            return;
        case 3:
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C,
                          arg2, 0xB, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C,
                          arg2, 0xC, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C,
                          arg2, 0x10, 0, arg4, 1);
            func_0025f3f0((f32)(arg0 + 0x25), (f32)(arg1 + 0x92), fparg0, 0x4C4C4C,
                          arg2, 0x11, 0, arg4, 1);
            break;
        }
    }
}

/* discarded C candidate measured nd 166 (object 276 / window 272); retail's
   large stack-backed vertex/color buffers and loop register schedule remain
   non-byte-exact. */
/* Measured nd 166 (object 276 / window 272), well above the ~25 parking
   threshold; this full-size candidate preserves the recovered vertex/color
   loop for future reduction. Committed at nd 166. */
// FUN_00265F40
INCLUDE_ASM("asm/nonmatchings/cldDayChange", func_00265f40);

/* No real C body was produced for this 1600-byte window. The nd 7 result came
   from an 8-byte empty stub and is a size-deficit artifact, not a near miss. */
// FUN_00266050
INCLUDE_ASM("asm/nonmatchings/cldDayChange", func_00266050);


/* discarded C candidate measured nd 53 (object 504 / window 512); retail's
   p[4] load scheduling and constant register choices remain non-byte-exact. */
/* Measured nd 53 (object 504 / window 512), above the ~25 parking threshold;
   this full-size candidate preserves the recovered state-machine arithmetic.
   Committed at nd 53. */
// FUN_00266690
INCLUDE_ASM("asm/nonmatchings/cldDayChange", func_00266690);

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
    r = func_00451fc0(arg0, D_00638EF0, 0xF, 0, 0, func_00264ec0, func_002668f0,
                      p);
    func_0045a8d0(3, 0);
    func_004598e0(0xA);
    return r;
}

