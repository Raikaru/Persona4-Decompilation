#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);
typedef struct {
    f32 x;
    f32 y;
} f2;
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} u4;
extern void func_002b8270(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);
extern void func_00452080(s32 handle);
extern u8 *iGpffffb588;
extern u8 *iGpffffb590;
extern u8 *func_002e1db0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00105ed0();
extern s32 func_002e1230();
extern void func_0025ecd0(f32 arg0, f32 arg1, f32 arg2,
                           s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                           s32 arg7, s32 arg8, s32 arg9, f32 arg10,
                           f32 arg11, f32 arg12, u8 *arg13);
extern s32 func_0046a770(const void *arg0);
extern u8 D_0063FB50[];
extern u8 D_0063FAA0[];
extern u8 D_0063FB90[];
extern void func_00110810(s64 arg0, u8 arg1);
extern s32 func_00110830();
extern s32 func_002bdff0();

void func_002b82d0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5);


void func_002b8340(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);

void func_002e2a10(s32 arg0, s32 arg1, s8 arg2, s32 arg3);

void func_002e3560(u8 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4);

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);

s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00105fa0(s32 arg0);
extern u8 D_0063F560[];
extern void func_002b2970(s64 *out, f32 x, f32 y);



// FUN_002E04E0
s32 func_002e04e0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}
// FUN_002E04F0
void func_002e04f0(u8 *arg0, u32 arg1, s8 arg2) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    if (arg2 == 0) {
        *(s16 *)(base + 4) |= (s16)((1 << (arg1 & 0xffff)) & 0xffff);
        return;
    }
    if (arg2 == 1) {
        *(s16 *)(base + 4) &= (s16)((1 << (arg1 & 0xffff)) ^ 0xffff);
        return;
    }
}
// FUN_002E0570
s64 func_002e0570(u8 *arg0, s32 arg1)
{
    s16 flags;

    flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 4);
    return (s8)((flags & ((1 << (arg1 & 0xFFFF)) & 0xFFFF)) >> (arg1 & 0xFFFF));
}



// FUN_002E05A0
s32 func_002e05a0(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x4);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

// FUN_002E0620
void func_002e0620(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    func_002b8270(*(u8 **)(arg0 + 0x38) + 4, p1, p2, arg3, arg4, arg5);
}
// FUN_002E0660
void func_002e0660(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s64 arg5)
{
    func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}



// FUN_002E0690
void func_002e0690(u8 *arg0, s8 arg1, s16 arg2, s64 arg3, f32 fparg0, f32 fparg1)
{
    extern void func_002b8300(u8 *arg0, s8 arg1, s16 arg2, s16 arg3,
                              f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
    func_002b8300(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3,
                  fparg0, fparg1, fparg0, fparg1);
}
// FUN_002E06D0
void func_002e06d0(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    extern void func_002b8300(u8 *arg0, s8 arg1, s16 arg2, s16 arg3);
    func_002b8300(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}



/* measured: corrected declarations and best plain-C body archived in build/WR04_wave_code1_002e_func_002e0700.c; residual obj 572B / window 576B / normalized_diff 309. */
// FUN_002E0700
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e0700);
// FUN_002E0940
void func_002e0940(u8 *arg0, s8 arg1, s16 arg2, s64 arg3)
{
    func_002b8340(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3);
}



/* measured: replacing the two scalar result stores with a two-f32 aggregate
   copy preserves retail's grouped output loads and store-source registers. */

// FUN_002E0970
void func_002e0970(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s64 arg5)
{
    extern void func_002b8370(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s16 arg5);
    func_002b8370(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}

// FUN_002E09B0
void func_002e09b0(u8 *arg0, f32 fparg0, s16 arg1)
{
    u8 *temp = *(u8 **)(arg0 + 0x38);
    s16 flags = *(s16 *)(temp + 4);
    *(s16 *)(temp + 4) = flags | 0x80;
    *(s16 *)(temp + 0xF0) = 0;
    *(f32 *)(temp + 0xEC) = fparg0;
    *(s16 *)(temp + 0xF2) = arg1;
}
// FUN_002E09E0
void func_002e09e0(u8 *arg0, s32 arg1, f32 fparg0) {
    struct Out2 { f32 x; f32 y; };
    u8 *temp_6 = *(u8 **)(arg0 + 0x38);
    f32 *entry = (f32 *)(D_0063F560 + *(s16 *)(temp_6 + 0xF8) * 8);
    u8 *temp_16;
    struct Out2 out;
    *(s16 *)(temp_6 + 4) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = fparg0;
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002b2970((s64 *)&out, entry[0], entry[1]);
    *(struct Out2 *)(temp_16 + 0x2C) = out;
}

// FUN_002E0A60
void func_002e0a60(u8 *arg0, s32 arg1, f32 fparg0)
{
    struct Out2 {
        f32 x;
        f32 y;
    };
    u8 *temp_6;
    u8 *temp_3;
    struct Out2 out;
    u8 *temp_17;
    u8 *temp_4;
    u8 *temp_3_2;

    temp_6 = *(u8 **)(arg0 + 0x38);
    temp_3 = D_0063F560 + *(s16 *)(temp_6 + 0xF8) * 8;
    *(s16 *)(temp_6 + 4) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = fparg0;
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
    temp_17 = *(u8 **)(arg0 + 0x38);
    func_002b2970((s64 *)&out, *(f32 *)temp_3, *(f32 *)(temp_3 + 4));
    *(struct Out2 *)(temp_17 + 0x2C) = out;
    temp_4 = *(u8 **)(arg0 + 0x38);
    *(u8 *)(temp_4 + 0x62) = 0xFF;
    temp_4 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_4 + 0xA0) = 0x3F800000;
    *(s32 *)(temp_4 + 0x94) = 0x3F800000;
    temp_3_2 = *(u8 **)(arg0 + 0x38);
    *(s8 *)(temp_3_2 + 0xCF) = 0;
    *(s8 *)(temp_3_2 + 0xA7) = 0;
    *(s8 *)(temp_3_2 + 0x67) = 0;
    *(s8 *)(temp_3_2 + 0x3B) = 0;
}
// FUN_002E0B20
void func_002e0b20(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, s32 arg3,
                   s32 arg4, u8 *arg5)
{
    func_0025ecd0(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF,
                  func_0046a770(D_0063FB50), arg4, 0, 0, 0.0f, 1.0f, 1.0f,
                  arg5);
}
// FUN_002E0BE0
void func_002e0be0(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, s32 arg3,
                   s32 arg4, u8 *arg5)
{
    func_0025ecd0(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF,
                  func_0046a770(D_0063FAA0), arg4, 0, 0, 0.0f, 1.0f, 1.0f,
                  arg5);
}
// FUN_002E0CA0
void func_002e0ca0(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, s32 arg3,
                   s32 arg4, u8 *arg5)
{
    func_0025ecd0(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF,
                  func_0046a770(D_0063FB90), arg4, 0, 0, 0.0f, 1.0f, 1.0f,
                  arg5);
}
// FUN_002E0D60
s32 func_002e0d60(void)
{
    u8 *temp = func_002e1db0(0x30, 0, 0, 0);
    iGpffffb588 = temp;
    return *(s32 *)(temp + 0x24);
}
// FUN_002E0DA0
s64 func_002e0da0(void)
{
    return (s64)(func_002e1230() != 0) << 0x30 >> 0x30;
}
// FUN_002E1CD0
s32 func_002e1cd0(void)
{
    return 0;
}

// FUN_002E1CE0
s32 func_002e1ce0(void)
{
    return 0;
}

// FUN_002E1CF0
s32 func_002e1cf0(void)
{
    return 0;
}

// FUN_002E23B0
s32 func_002e23b0(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e2a10(*(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}



// FUN_002E2410
s32 func_002e2410(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    func_002e3560(arg0, *(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}



// FUN_002E2470
void func_002e2470(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* measured: retail normalises the (s16) search value once in the loop
   preheader; plain -O2 re-narrows it inside the body (nd 69 at 132 bytes
   against a 128-byte window). With the hoist it is byte-exact. */
// FUN_002E6F90
#pragma opt_loop_invariants on
s32 func_002e6f90(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s16 val = (s16)arg1;
    s16 n = *(s16 *)(arg0 + 0x60);

    while ((s16)i < n) {
        if (*(s16 *)(arg0 + (s16)i * 2) == val) {
            return 0;
        }
        i = (s16)(i + 1);
    }
    *(s16 *)(arg0 + n * 2) = arg1;
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) + 1;
    return 1;
}
/* measured: hoist (s16)arg1 normalization out of loop */
#pragma opt_loop_invariants off

// FUN_002E7010
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7010);
// FUN_002E7190
void func_002e7190(void) {
    ((void (*)(void))jtbl_008873EC[0])();
}
/* measured: plain C reaches nd 5 with object 248/256; the only residual is
   MWCC's daddiu-vs-addiu loop increment and the resulting saved-register
   source. No inline assembly. Committed at nd 3. */
// FUN_002E71C0
s32 func_002e71c0(void)
{
    s32 var_17;
    s64 var_16;
    s16 temp_18;

    var_16 = 0;
    var_17 = 0x300;
    goto loop_test;
loop_body:
    if (func_002bdff0(var_17) == 1)
    {
        if ((func_00110830(temp_18) & 0xFF) == 0)
        {
            var_16 = (s16)var_17;
            func_00110810(var_16, (func_00110830(var_16) & 0xFF) | 1);
            var_16 = 1;
        }
        else if (((u8)func_00110830(temp_18)) & 1)
        {
            var_16 = 1;
        }
    }
    var_17 = (s16)(var_17 + 1);
loop_test:
    temp_18 = (s16)var_17;
    if (temp_18 < 0x3FF)
    {
        goto loop_body;
    }
    return ((s64)(var_16 << 0x38) >> 0x38) == 1;
}
/* measured: corrected callee declarations; variadic call casts preserve retail's
   extra ignored arguments to the one-parameter routines. */
// FUN_002E72C0
s32 func_002e72c0(u8 *arg0)
{
    s32 func_00144c90(s32 arg0, s32 arg1);
    s32 func_00122520(s32 arg0, s32 arg1);
    s32 func_00122640(s32 arg0, s32 arg1);
    s32 func_00122720(void);
    s32 func_00144f60(void);
    void func_00145080(void);
    s32 func_0014b450(void);
    f32 func_0014b4d0(void);
    s32 func_0015f660(void);
    s32 func_0033be40(u8 *arg0);
    u8 *func_003e9cb0(u8 *arg0, ...);
    s32 func_00452380(s8 *arg0);
    u8 *func_00457120(void);
    void func_004577d0(void *arg0, f32 arg1);
    s32 func_0045a3e0(s16 arg0, ...);
    extern s8 D_0063FC68[];
    s8 state;
    u8 *work;
    u8 *temp_17;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s8 *)work;
    switch (state) {
    case 1:
        func_00144c90(8, 6);
        *(s8 *)work = 2;
        /* fallthrough */
    case 2:
        if ((func_00144f60() != 0) && (func_0015f660() != 0)) {
            temp_17 = func_00457120();
            func_004577d0(temp_17, func_0014b4d0());
            temp_17 = func_00457120();
            func_003e9cb0(*(u8 **)(temp_17 + 4), func_0014b450(), 0);
            *(s8 *)work = 3;
            func_0045a3e0((s16)0x15, 1);
        }
        goto block_24;
    case 3:
        func_00122640(1, 0);
        *(s8 *)work = 4;
        /* fallthrough */
    case 4:
        if (func_00122720() != 0) {
            if (*(s32 *)(work + 4) != 0) {
                *(s32 *)(work + 4) = 0;
            }
            *(s32 *)(work + 4) = func_0033be40(arg0);
            *(s8 *)work = 0x22;
        }
        goto block_24;
    case 5:
        func_00122520(1, 0);
        *(s8 *)work = 6;
        /* fallthrough */
    case 6:
        if (func_00122720() != 0) {
            func_00145080();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 34:
        if (func_00452380(D_0063FC68) == 0) {
            func_00145080();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 35:
        return -1;
    default:
block_24:
        return 0;
    }
}
// FUN_002E74E0
void func_002e74e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002E7510
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7510);
// FUN_002E7870
void func_002e7870(void) {
    u8 *g = iGpffffb590;

    if (g != NULL) {
        func_00452080((s32)g);
        iGpffffb590 = NULL;
    }
}
// FUN_002E78A0
u8 func_002e78a0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp18;
}



// FUN_002E78E0
u8 func_002e78e0(void)
{
    s32 sp1C;
    s32 sp18;

    func_001104d0(func_001060b0(), &sp18, &sp1C);
    return sp1C;
}



// FUN_002E7920
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7920);
// FUN_002E7A60
void func_002e7a60(void)
{
    func_00105ed0();
}

// FUN_002E7A80
void func_002e7a80(s32 arg0)
{
    func_00105fa0(func_002b2cb0(arg0, 0, 0x98967F, 0, 1));
}

// FUN_002E7AC0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e7ac0);
// FUN_002E82B0
INCLUDE_ASM("asm/nonmatchings/code1_002e", func_002e82b0);
