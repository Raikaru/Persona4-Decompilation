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
extern u8 D_0063FC80[];
extern u8 D_0063FC90[];
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern void func_0044ea90(const void *arg0, u32 arg1);
extern s32 func_00451fc0(s32 arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4,
                         void (*arg5)(u8 *), void (*arg6)(u8 *), u8 *arg7);
extern s32 func_002b5c90(s32 arg0, u64 arg1);
extern void func_002b29e0(void *arg0, f32 arg1, f32 arg2);
extern void func_002b5db0(s32 arg0, s64 arg1, void *arg2);
extern void func_002b2a60(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_002b5e30(s32 arg0, u32 arg1);
extern void func_0045aac0(s16 arg0, s32 arg1, s32 arg2);
extern s32 func_00106ac0(s16 arg0);
extern s64 func_00106af0(s16 arg0);
extern s32 func_00106b20(s16 arg0);
extern s32 func_00106b50(s16 arg0);

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



/* measured: retain pair loads before stores and retail's written load order. */
#pragma push
#pragma opt_propagation off
// FUN_002E0700
void func_002e0700(u8 *arg0, s64 arg1, f32 fparg0, f32 fparg1,
                   s32 arg2, s32 arg3, s64 arg4)
{
    f2 pos;
    f2 out1;
    f2 out2;
    f2 draw1;
    f2 draw2;
    f32 out1_x;
    f32 out1_y;
    f32 out2_x;
    f32 out2_y;
    f32 pos_x;
    f32 pos_y;
    u8 *handle;
    u8 *temp;
    extern u8 *func_0046d200(u32 arg0, s16 arg1);
    extern f32 func_0046b2f0(u8 *arg0);
    u8 *base;
    extern void func_0046d280(u8 *arg0);
    extern void func_002b8300(u8 *arg0,
                              f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                              s8 arg1, s32 arg2, s32 arg3);
    extern void func_002b82d0();
    temp = *(u8 **)(arg0 + 0x38);
    pos_x = *(f32 *)(temp + 0x2C);
    pos_y = *(f32 *)(temp + 0x30);
    pos.x = pos_x;
    pos.y = pos_y;
    if ((s8)arg4 == 1) {
        handle = func_0046d200(*(u32 *)(temp + 0xF4), (s16)arg1);
        func_002b2970((s64 *)&out1, pos.x,
                      pos.y - (func_0046b2f0(handle) / 2.0f));
        out1_x = out1.x;
        out1_y = out1.y;
        draw1.x = out1_x;
        draw1.y = out1_y;
        arg3 = (s16)arg3;
        func_002b8270(*(u8 **)(arg0 + 0x38) + 4, pos, draw1, 0, arg2,
                       arg3);
        func_0046d280(handle);
        func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, 0, 0xFF, 0, arg2, arg3);
    } else {
        handle = func_0046d200(*(u32 *)(temp + 0xF4), (s16)arg1);
        func_002b2970((s64 *)&out2, pos.x,
                      pos.y + (func_0046b2f0(handle) / 2.0f));
        out2_x = out2.x;
        out2_y = out2.y;
        draw2.x = out2_x;
        draw2.y = out2_y;
        arg3 = (s16)arg3;
        func_002b8270(*(u8 **)(arg0 + 0x38) + 4, pos, draw2, 0, arg2,
                       arg3);
        func_0046d280(handle);
        func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, 0xFF, 0, 0, 0,
                       (s16)((s32)arg3 + arg2));
    }
    base = *(u8 **)(arg0 + 0x38);
    func_002b8300(base + 4, 1.0f, 1.0f, fparg0, fparg1, 0, arg2, arg3);
}
#pragma pop
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

/* measured: loop-invariant sentinel loads are hoisted to retail preheaders */
#pragma opt_loop_invariants on
// FUN_002E7010
s32 func_002e7010(u8 *arg0, s16 arg1)
{
    u8 v2;
    s16 i;
    s16 v4;
    s16 v5;
    s16 v7;
    s16 j;
    s16 v9;
    u8 v10;
    s16 k;
    s16 minus_one;
    s16 temp[0x30];

    v2 = 0;
    minus_one = -1;
    for (i = 0; i < 0x30; i++) {
        temp[i] = minus_one;
    }
    minus_one = -1;
    for (v4 = 0, v5 = arg1; v4 < *(s16 *)(arg0 + 0x60); v4++) {
        if (v5 == *(s16 *)(arg0 + v4 * 2)) {
            *(s16 *)(arg0 + v4 * 2) = minus_one;
        }
    }
    for (j = 0; j < *(s16 *)(arg0 + 0x60); j++) {
        v9 = *(s16 *)(arg0 + j * 2);
        if (v9 != minus_one) {
            temp[v2++] = v9;
        }
    }
    v10 = 0;
    minus_one = -1;
    for (k = (s16)0; *(s16 *)(arg0 + 0x60) > k; k++) {
        if (temp[k] != minus_one) {
            *(s16 *)(arg0 + v10++ * 2) = temp[k];
        }
    }
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) - 1;
    return 1;
}
/* measured: scoped loop-invariant optimization for func_002e7010 */
#pragma opt_loop_invariants off
// FUN_002E7190
void func_002e7190(void) {
    ((void (*)(void))jtbl_008873EC[0])();
}
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
s32 func_002e7510(s32 arg0)
{
    s32 result;
    u8 *work;
    u8 color[24];
    s64 vec60;
    s64 vec58;
    s32 color_value;
    s32 i;
    extern void func_00110810(s32, u8);

    func_0044ea90(D_0063FC80, 0x11A);
    work = D_008873F4[0](1, 0x18, 0x40000);
    result = func_00451fc0(arg0, (char *)D_0063FC90, 0xF, 0, 0,
                           (void (*)(u8 *))func_002e72c0,
                           func_002e74e0, work);
    iGpffffb590 = NULL;
    func_002b2970(&vec60, 0, 0);
    iGpffffb590 = (u8 *)func_002b5c90(result, *(u64 *)&vec60);
    func_002b2970(&vec58, 0, 0);
    func_002b29e0(color, 640.0f, 448.0f);
    func_002b5db0((s32)iGpffffb590, vec58, color);
    func_002b2a60(&color_value, 0, 0, 0, 0xFF);
    func_002b5e30((s32)iGpffffb590, color_value);
    *work = 1;
    func_0045aac0(3, 0, 0x1E);

    for (i = 0; i < 0x2FF; i++) {
        if (((func_00106b20((s16)i) & 0xFFF00) >> 8) == 0 &&
            ((func_00106b50((s16)i) & 0xFFF00) >> 8) == 0) {
            func_00110810(i, (func_00110830(i) & 0xFF) | 4);
        } else if ((func_00106b20((s16)i) & 0xFF) == 0 &&
                   (func_00106b50((s16)i) & 0xFF) == 0) {
            func_00110810(i, (func_00110830(i) & 0xFF) | 4);
        }
    }
    for (i = 0x300; i < 0x3FF; i++) {
        if ((func_002be100(func_00106ac0((s16)i) & 0xFF) & 0xFF) <
            (func_002be100(4) & 0xFF)) {
            func_00110810(i, (func_00110830(i) & 0xFF) | 4);
        } else if ((func_002be100(func_00106ac0((s16)i) & 0xFF) & 0xFF) ==
                   (func_002be100(4) & 0xFF) &&
                   (s8)func_00106af0((s16)i) < 2) {
            func_00110810(i, (func_00110830(i) & 0xFF) | 4);
        }
    }
    return result;
}
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
void func_002e7920(s32 *arg0, s32 *arg1)
{
    s32 func_001104a0(s32 arg0);
    s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
    s32 *out0;
    u8 count;
    s32 *out1;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;

    out0 = arg0;
    count = 0;
    out1 = arg1;

    func_001104d0(func_001060b0(), (s32 *)&sp60, (s32 *)&sp64);
    count = *(u8 *)&sp64;
    func_001104d0(func_001060b0(), (s32 *)&sp68, (s32 *)&sp6C);
    if (func_001104a0(*(u8 *)&sp68) < (count + 1)) {
        func_001104d0(func_001060b0(), &sp58, &sp5C);
        *out0 = func_002b2cb0(*(u8 *)&sp58, 1, 0xC, 1, 2);
        *out1 = 1;
        return;
    }
    func_001104d0(func_001060b0(), &sp50, &sp54);
    *out0 = *(u8 *)&sp50;
    func_001104d0(func_001060b0(), &sp48, &sp4C);
    *out1 = *(u8 *)&sp4C + 1;
}
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

#define P4_002E7AC0_DRAW() \
    do { \
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(105) + 0x10), 0) == 1) { \
            func_00275820(*(f32 *)(func_002b6150(105) + 0x38) + 52.0f, 41.0f, 88.0f, \
                          func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0, 1, \
                          func_0010d6d0(1), 0, 0, D_00794E70, 24); \
        } \
    } while (0)
// FUN_002E7AC0
s32 func_002e7ac0(u8 *arg0)
{
    void func_002e90d0(u8 *arg0);
    u8 *func_002b6150(s16 arg0);
    s16 func_002b6970(s16 arg0, s16 arg1);
    s32 func_002b2a30(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u32 func_0010d6d0(s16 arg0);
    int func_00275820(f32 x, f32 y, f32 scale, int color, int chr, int id,
                      u32 str, int flags, int unused, void *param, int out);
    void func_00314740(u8 *arg0, s8 arg1);
    void func_002ed430(u8 *arg0);
    void func_002f0f00(u8 *arg0);
    void func_002f6cf0(u8 *arg0);
    void func_002f9d90(u8 *arg0);
    void func_002fbea0(u8 *arg0);
    void func_00302770(u8 *arg0);
    void func_00304580(u8 *arg0);
    void func_003097e0(u8 *arg0);
    void func_0030b060(u8 *arg0);
    void func_0030b7b0(u8 *arg0);
    void func_0030c3c0(u8 *arg0);
    void func_0030f650(u8 *arg0);
    extern u8 D_00794E70[];
    u8 *work;
    u8 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(u8 *)work;
    if (state == 0xD8) {
        goto done;
    }
    if (state == 0x0B) {
        goto return_minus_one;
    }
    if (state == 0x0E) {
        goto case_0e;
    }
    if (state == 0x0D) {
        goto case_0d;
    }
    if (state == 0x0A) {
        goto case_0a;
    }
    if (state == 0x09) {
        goto case_09;
    }
    if (state == 0x0C) {
        goto case_0c;
    }
    if (state == 0x10) {
        goto case_10;
    }
    if (state == 0x0F) {
        goto case_10;
    }
    if (state == 0x08) {
        goto case_08;
    }
    if (state == 0x07) {
        goto case_07;
    }
    if (state == 0x06) {
        goto case_06;
    }
    if (state == 0x05) {
        goto case_05;
    }
    if (state == 0x04) {
        goto case_04;
    }
    if (state == 0x03) {
        goto case_03;
    }
    if (state == 0x02) {
        goto case_02;
    }
    if (state == 0x01) {
        goto case_01;
    }
    switch (state) {
    case 0:
        func_002e90d0(arg0);
        break;
    default:
        break;
    }
    goto done;

case_01:
    P4_002E7AC0_DRAW();
    func_00314740(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 2;
    func_002ed430(arg0);
    goto done;
case_02:
    P4_002E7AC0_DRAW();
    func_00314740(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 3;
    func_002f0f00(arg0);
    goto done;
case_03:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 4;
    func_00314740(*(u8 **)(work + 0x148), 0);
    func_002f6cf0(arg0);
    goto done;
case_04:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 5;
    func_00314740(*(u8 **)(work + 0x148), 0);
    func_002f6cf0(arg0);
    goto done;
case_05:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 6;
    func_00314740(*(u8 **)(work + 0x148), 0);
    func_002f6cf0(arg0);
    goto done;
case_06:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 7;
    func_00314740(*(u8 **)(work + 0x148), 0);
    func_002f9d90(arg0);
    goto done;
case_07:
    func_00302770(arg0);
    goto done;
case_08:
    P4_002E7AC0_DRAW();
    func_00304580(arg0);
    goto done;
case_10:
    func_00314740(*(u8 **)(work + 0x148), 1);
    func_002fbea0(arg0);
    goto done;
case_0c:
    func_0030c3c0(arg0);
    goto done;
case_09:
    func_0030b060(arg0);
    goto done;
case_0a:
    func_0030b7b0(arg0);
    goto done;
case_0d:
    func_003097e0(arg0);
    goto done;
case_0e:
    func_0030f650(arg0);
    goto done;
return_minus_one:
    return -1;
done:
    return 0;
}
#undef P4_002E7AC0_DRAW
// FUN_002E82B0
void func_002e82b0(u8 *arg0)
{
    s32 func_0010b5b0(void);
    s8 func_002e4820(s8 arg0);
    s32 func_00452080(struct KwlnTask *arg0);
    s16 i;
    s64 j;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while (i < 15) {
        func_002e4820((s8)i);
        i++;
    }
    i = 0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(work + ((s16)j * 4) + 0x154) != 0) {
        func_00452080(*(struct KwlnTask **)(work + ((s16)j * 4) + 0x154));
    }
    i++;
loop_7_test:
    j = (s16)i;
    if ((s16)j < (u16)func_0010b5b0()) {
        goto loop_7_body;
    }
    i = 0;
    while (i < 2) {
        if (*(s32 *)(work + (i * 4) + 0x184) != 0) {
            func_00452080(*(struct KwlnTask **)(work + (i * 4) + 0x184));
        }
        i++;
    }
    if (*(s32 *)(work + 0x24C) != 0) {
        func_00452080(*(struct KwlnTask **)(work + 0x24C));
    }
    if (*(s32 *)(work + 0x250) != 0) {
        func_00452080(*(struct KwlnTask **)(work + 0x250));
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
