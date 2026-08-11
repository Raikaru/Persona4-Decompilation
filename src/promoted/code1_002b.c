#include "include_asm.h"
#include "type.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_002baa50(void);
extern void func_002baa90(s32 *arg0);
extern void func_002bb7c0(s32 arg0);
extern void func_002bd440(void);

extern void func_002bb9e0(u8 *arg0, s32 arg1);


extern void func_002bcc60(u8 *arg0);
extern s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void func_0046d730(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern char D_007488E8[];
extern void func_0045a9a0(s32 arg0, s32 arg1);

extern s32 clndGetMoonPhase(void);

extern u32 func_00106a90(s16 arg0);
extern u8 *D_00882F40[];
extern void func_00278450(s32 arg0);
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s8 func_002bacb0(void);
extern s32 iGpffffb57c;
extern s32 *func_002bbf70();
extern s32 func_002bb0e0(void);
extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_00279350(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern s32 func_00106880(void);
extern s32 func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00145080(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00276e70(s32 arg0, s8 arg1);
extern void func_00277250(s32 arg0);
extern void func_00277ad0(s32 arg0, s32 arg1);
extern s32 func_00276e10();
extern s32 func_00276fb0(s32 arg0);
extern s32 func_00277070(s32 arg0);
extern void func_00277be0(s32 arg0, s32 arg1);
extern void func_00277fd0(s32 arg0, s32 arg1);
extern u32 func_002786c0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bbdd0(s32 arg0);
extern void func_002bbe90(s64 arg0, s32 arg1);
extern u32 func_002e7a60(void);
extern void func_00364320(s64 arg0, s32 arg1, s32 arg2, f32 arg3);
extern u8 *func_002e2170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00442088();
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 arg0);
extern s32 func_0046aea0(void *arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_0046b0d0(void *arg0);
extern void func_002e2240(void *arg0, void *arg1, void *arg2);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b7b0(f32 arg0);
extern s32 func_00106850(void);
extern s32 func_00106ac0(s64 arg0);
extern s64 func_00106af0(s64 arg0);
extern s32 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_002be100(s32 arg0);
extern void func_00144c90(s32 arg0, s32 arg1);
extern s32 func_00144f60(void);
extern s32 func_0015f660(void);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern s32 func_002cb6a0(s32 arg0);
extern void func_002caa00(s32 arg0, s32 arg1);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s32 func_00452380(void *arg0);
extern u8 *func_00457120(void);
extern s32 func_0014b450(void);
extern f32 func_0014b4d0(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern u8 D_0063F3B0[];



// FUN_002B2940
s32 func_002b2940(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}
// FUN_002B2950
void func_002b2950(s32 arg0)
{
    iGpffffb55c = arg0;
}
// FUN_002B2960
s32 func_002b2960(void)
{
    return iGpffffb55c;
}
// FUN_002B2970
void func_002b2970(u8 *arg0, f32 arg1, f32 arg2)
{
    struct Float2 {
        f32 x;
        f32 y;
    } val;

    val.x = arg1;
    val.y = arg2;
    *(struct Float2 *)arg0 = val;
}
// FUN_002B29A0
void func_002b29a0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Float3 {
        f32 x;
        f32 y;
        f32 z;
    } val;

    val.x = arg1;
    val.y = arg2;
    val.z = arg3;
    *(struct Float3 *)arg0 = val;
}
// FUN_002B29E0
void func_002b29e0(u8 *arg0, f32 arg1, f32 arg2)
{
    struct Float2Int2 {
        f32 x;
        f32 y;
        s32 z;
        s32 w;
    } val;

    val.z = (s32)arg1;
    val.w = (s32)arg2;
    *(struct Float2Int2 *)arg0 = val;
}
// FUN_002B2A30
s32 func_002b2a30(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 result;

    result = arg3 & 0xFF;
    result = p4_pack_or(result, (arg2 & 0xFF) << 8);
    result = p4_pack_or((arg1 & 0xFF) << 16, result);
    result = p4_pack_or((arg0 & 0xFF) << 24, result);
    return result;
}
// FUN_002B2A60
void func_002b2a60(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    struct Byte4 {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } val;

    val.b0 = (u8)arg1;
    val.b1 = (u8)arg2;
    val.b2 = (u8)arg3;
    val.b3 = (u8)arg4;
    *(struct Byte4 *)arg0 = val;
}
// FUN_002B2AA0
f32 func_002b2aa0(s64 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f0;
    f32 temp_f2;
    s64 temp_3;

    temp_f20 = fparg0;
    temp_f21 = fparg1;
    if (fparg2 == fparg3) {
        return temp_f21;
    }
    temp_3 = (s8)arg0;
    switch (temp_3) {
    case 0:
        return temp_f20 + ((fparg2 * (temp_f21 - temp_f20)) / fparg3);
    case 1:
        temp_f0 = func_0044b7b0(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f20 + temp_f2 * temp_f0;
    case 2:
        temp_f0 = func_0044b610(p4_mul_left(fparg2, iGpffff82fc / (2.0f * fparg3)));
        temp_f2 = temp_f21 - temp_f20;
        return temp_f21 - temp_f2 * temp_f0;
    default:
        return -1.0f;
    }
}
// FUN_002B2BD0
void func_002b2bd0(f32 *arg0, s64 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    struct Vec2 {
        f32 x;
        f32 y;
    } sp;

    if ((s8)arg1 == 0) {
        sp.x = fparg0 / 2.0f;
        sp.y = fparg1 / 2.0f;
    } else if ((s8)arg1 == 1) {
        sp.x = (fparg2 / 2.0f) + ((fparg0 - fparg2) / 2.0f);
        sp.y = (fparg3 / 2.0f) + ((fparg1 - fparg3) / 2.0f);
    } else if ((s8)arg1 == 2) {
        sp.x = (fparg0 / 2.0f) - (fparg2 / 2.0f);
        sp.y = (fparg1 / 2.0f) - (fparg3 / 2.0f);
    }
    *(struct Vec2 *)arg0 = sp;
}
// FUN_002B2CB0
s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 + arg1;
    }
    {
        s32 var = arg0 + arg1;
        s32 bound;
        if (arg2 < var) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D00
s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    if (arg4 == 0) {
        return arg0 - arg1;
    }
    {
        s32 var = arg0 - arg1;
        s32 bound;
        if (var < arg2) {
            bound = (arg4 == 1) ? arg2 : arg3;
            var = bound;
        }
        return var;
    }
}



// FUN_002B2D50
s16 func_002b2d50(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 temp_2_2;
    s32 temp_2;
    s32 temp_3;
    s32 temp_6;
    s32 var_2;

    temp_6 = arg2;
    if (temp_6 == 0) {
        return 0;
    }
    temp_3 = arg4;
    temp_2_2 = arg0 + temp_3;
    if (temp_2_2 < 0) {
        return 0;
    }
    if (temp_6 < temp_2_2) {
        return arg3 - 1;
    }
    if (temp_3 > 0) {
        return (s16)func_002b3110(arg1 + temp_3, arg3 - 2, temp_6);
    }
    if (temp_3 < 0) {
        temp_2 = arg1;
        if (temp_2 == 0) {
            var_2 = temp_2 - 1;
            if (var_2 < 0) {
                var_2 = 0;
            }
            return (s16)var_2;
        }
        return (s16)func_002b3140(temp_2 + temp_3, 1, temp_6);
    }
    return arg1;
}
/* measured: explicit branch-shape candidate is 276B in the 288B retail window with normalized_diff 7; parked at the measured floor. Committed at nd 7. */
// FUN_002B2E70 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2e70);
/* measured: explicit-goto candidate is 180B in the 192B retail window with normalized_diff 1; parked at the measured floor. Committed at nd 1. */
// FUN_002B2F90 NONMATCHING
#ifdef NON_MATCHING
void func_002b2f90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4, s16 *arg5)
{
    s32 temp_3;
    s32 var_10;
    s32 var_6;

    if (arg2 == 0) {
        *arg4 = 0;
        *arg5 = 0;
        goto exit;
    }
    temp_3 = arg0 - arg1;
    if (temp_3 == 0) {
        arg0 = 0;
        arg1 = 0;
        goto done;
    }
    var_10 = 0;
    var_6 = (s8)arg3;
    goto loop_test;
loop_body:
    temp_3 = (s16)(arg0 - arg1) - 1;
    if (temp_3 < 0) {
        temp_3 = 0;
    }
    if (temp_3 == 0) {
        arg0 -= 1;
        if (arg0 >= 0) {
            goto first_clamp_done;
        }
        arg0 = 0;
first_clamp_done:
        goto done;
    }
    arg0 -= 1;
    if (arg0 < 0) {
        arg0 = 0;
    }
    var_10 += 1;
loop_test:
    if (var_10 < var_6) {
        goto loop_body;
    }
done:
    *arg4 = arg0;
    *arg5 = arg1;
exit:
    ;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b2f90);
#endif
/* measured: explicit-goto candidate is 184B in the 192B retail window with normalized_diff 1; parked at the measured floor. Committed at nd 1. */
// FUN_002B3050 NONMATCHING
#ifdef NON_MATCHING
void func_002b3050(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4, s16 *arg5, s16 *arg6)
{
    s32 var_3;
    s32 var_8;

    if (arg2 != 0)
        goto nonzero;
    var_3 = arg4 & 0xFF;
    *arg5 = var_3;
    *arg6 = var_3;
    goto done;

nonzero:
    if ((arg0 - arg1) != 0)
        goto setup;
    arg0 = arg4 & 0xFF;
    arg1 = arg0;
    goto store;

setup:
    var_8 = 0;
    arg2 = (s8)arg3;
    goto loop_test;

loop_body:
    var_3 = (s16)(arg0 - arg1) - 1;
    if (var_3 < 0)
        var_3 = 0;
    if (var_3 != 0)
        goto decrement;
    arg0 -= 1;
    if (arg0 < 0)
        arg0 = 0;
    goto store;

decrement:
    arg0 -= 1;
    if (arg0 < 0)
        arg0 = 0;
    var_8 += 1;

loop_test:
    if (var_8 < arg2)
        goto loop_body;

store:
    *arg5 = arg0;
    *arg6 = arg1;

done:
    return;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3050);
#endif

/* measured: opt_rebuildconditionals off probe for min/max */
#pragma opt_rebuildconditionals off
// FUN_002B3110
s32 func_002b3110(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 < arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
// FUN_002B3140
s32 func_002b3140(s32 arg0, s32 arg1)
{
    s32 result;

    if (arg0 > arg1)
        goto choose;
    result = arg1;
    goto done;
choose:
    result = arg0;
done:
    return result;
}
/* measured: close opt_rebuildconditionals after min/max */
#pragma opt_rebuildconditionals on
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
#pragma opt_loop_invariants on
// FUN_002B3170
s32 func_002b3170(s32 arg0)
{
    s32 result;

    result = 0;
    do {
        arg0 /= 10;
        result++;
    } while (arg0 != 0);
    return result;
}
/* measured: close opt_loop_invariants after 3170. */
#pragma opt_loop_invariants off
// FUN_002B31A0
void func_002b31a0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 second;
    struct Vec3 result;

    first = *(struct Vec3 *)arg1;
    second = *(struct Vec3 *)arg2;
    result.x = first.x - second.x;
    result.y = first.y - second.y;
    result.z = first.z - second.z;
    *(struct Vec3 *)arg0 = result;
}
// FUN_002B3230
s32 func_002b3230(s16 *arg0, s16 *arg1) {
    s16 b;
    u32 x;
    u32 y;

    b = *arg1;
    x = func_00106a90(*arg0);
    y = func_00106a90(b);
    if (x < y) {
        return 1;
    }
    return -(s32)(y < x);
}

// FUN_002B32A0
s32 func_002b32a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 var;

    var = arg3;
    if (arg0 >= arg1) {
        return arg1;
    }
    if (arg2 == 0) {
        var = 0;
    }
    return var;
}
// FUN_002B32D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b32d0);
// FUN_002B3520
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3520);
// FUN_002B3720
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b3720);
// FUN_002B3960
void func_002b3960(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B5100
void func_002b5100(u8 *arg0, s8 arg1)
{
    if (arg0 != NULL) {
        *(s8 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
    }
}
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
#pragma opt_propagation off
// FUN_002B5120
void func_002b5120(s32 arg0, u8 *arg1)
{
    void (**base)(s32 arg0, s32 arg1);
    s8 temp_5;

    base = D_00887300;
    base[0](6, 1);
    base[0](7, 2);
    base[0](8, 1);
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
    if (*(s8 *)(arg1 + 0x184) == 1) {
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        temp_5 = *(s8 *)(arg1 + 0x18C);
        switch (temp_5) {
        case 1:
            func_003f6440(2, 0x48);
            func_003f6440(3, 0x71801);
            return;
        case 2:
            func_003f6440(2, 0x42);
            func_003f6440(3, 0x71801);
            break;
        }
    }
}
/* measured: restores opt_propagation after func_002b5120. */
#pragma opt_propagation on
// FUN_002B52A0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002b52a0);
// FUN_002B5C60
void func_002b5c60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_002BA080
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba080);
// FUN_002BA5D0
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba5d0);
// FUN_002BA970
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002ba970);
// FUN_002BAA20
void func_002baa20(void)
{
    func_002baa90(D_00882F60);
    func_002baa50();
}
// FUN_002BAA50
void func_002baa50(void)
{
    s32 i;
    u8 **t;

    i = 0;
    t = D_00882F40;
    while (i < 5) {
        t[i] = NULL;
        i++;
    }
}
// FUN_002BAB80
s64 func_002bab80(void *arg0)
{
    s32 **temp_18;
    s32 *temp_2;
    s64 temp_16;
    s32 temp_4;
    s64 var_2;
    extern s32 func_002774d0(s32 arg0);
    extern s32 func_002bbf80(s32 *arg0, s32 arg1);
    extern void func_0044ea90(const void *arg0, s32 arg1);

    temp_16 = func_002bacb0();
    if (temp_16 == -1) {
        return -1;
    }
    func_0044ea90(&D_0063F2A0, 0x90);
    temp_2 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
    {
        s32 **temp_5;

        temp_5 = (s32 **)&D_00882F40[(s8)temp_16];
        *temp_5 = temp_2;
        if (temp_2 != NULL) {
            temp_2[0] = -1;
            *(s8 *)(temp_2 + 1) = 0;
            *(s8 *)((u8 *)temp_2 + 5) = 0;
            *(s32 *)(temp_2 + 2) = -1;
            *(s8 *)((u8 *)temp_2 + 0xC) = 1;
            *(s8 *)((u8 *)temp_2 + 0xD) = 1;
        }
        temp_4 = (s32)temp_16;
        (&D_00764670)[(s8)temp_4] = -1;
        var_2 = -1;
        if (**temp_5 < 0) {
            temp_18 = (s32 **)&D_00882F40[(s8)temp_4];
            **temp_18 = func_002774d0((s32)arg0);
            func_002bbf80(*temp_18, 0);
            var_2 = temp_16;
        }
    }
    return var_2;
}
// FUN_002BACB0
s8 func_002bacb0(void) {
    s32 i = 0;
    u8 **t = D_00882F40;

    while (i < 5) {
        if (t[i] == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002BAD10
s32 func_002bad10(s32 arg0)
{
    s32 *temp_2;
    s32 temp_4;

    temp_2 = func_002bbf70();
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = temp_2[0];
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 0);
    func_00278170(temp_2[0], 0x200000);
    func_002778c0(temp_2[0], arg0, 0);
    func_00277010(temp_2[0], -1);
    *(s8 *)((u8 *)temp_2 + 4) = 1;
    return 1;
}
// FUN_002BADC0
s32 func_002badc0(s64 arg0, s32 arg1)
{
    s32 temp_4;
    u8 **temp_17;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_4 = *(s32 *)*temp_17;
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 0);
    func_00278170(*(s32 *)*temp_17, 0x200000);
    func_002778c0(*(s32 *)*temp_17, arg1, 0);
    func_00277010(*(s32 *)*temp_17, -1);
    *(s8 *)(*temp_17 + 4) = 1;
    return 1;
}
// FUN_002BAE80
s32 func_002bae80(s64 arg0, s32 arg1)
{
    s32 temp_4;
    u8 **temp_17;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_4 = *(s32 *)*temp_17;
    if (temp_4 < 0) {
        return 0;
    }
    func_00278610(temp_4, 1);
    func_00278170(*(s32 *)*temp_17, 0x200000);
    func_002778c0(*(s32 *)*temp_17, arg1, 0);
    func_00277010(*(s32 *)*temp_17, -1);
    *(s8 *)(*temp_17 + 4) = 1;
    return 1;
}
// FUN_002BAF40
s32 func_002baf40(s32 arg0) {
    s32 *p;

    p = func_002bbf70();
    if (p == NULL) {
        return 0;
    }
    if (*p < 0) {
        return 0;
    }
    p[2] = arg0;
    *((s8 *)p + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}
// FUN_002BAFC0
s32 func_002bafc0(s64 arg0, s32 arg1)
{
    u8 **temp_16;
    u8 *temp_3;

    temp_16 = &D_00882F40[(s8)arg0];
    temp_3 = *temp_16;
    if (temp_3 == NULL) {
        return 0;
    }
    if (*(s32 *)temp_3 < 0) {
        return 0;
    }
    *(s32 *)(temp_3 + 8) = arg1;
    *(s8 *)(*temp_16 + 0xD) = func_002bb0e0();
    iGpffffb578 = 0;
    return 1;
}
// FUN_002BB180
s8 func_002bb180(s64 arg0)
{
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return -1;
    }
    return *(s8 *)(p + 0xD);
}
// FUN_002BB420
s32 func_002bb420(s64 arg0)
{
    s32 temp_4;
    u8 **temp_17;
    u8 *temp_2;

    temp_17 = &D_00882F40[(s8)arg0];
    temp_2 = *temp_17;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)temp_2;
    if (temp_4 < 0) {
        return 0;
    }
    func_00276e70(temp_4, 0);
    func_00277250(*(s32 *)*temp_17);
    func_00277ad0(*(s32 *)*temp_17, 0);
    func_002bbe90(arg0, 1);
    *(s8 *)(*temp_17 + 4) = 0;
    return 1;
}
// FUN_002BB4E0
s32 func_002bb4e0(void) {
    s32 *temp_2;
    s32 temp_4;

    temp_2 = (s32 *)(func_002bbf70());
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = (s32)(*(s32 *)((u8 *)(temp_2) + 0));
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)((u8 *)(temp_2) + 0) = -1;
        *(s8 *)((u8 *)(temp_2) + 4) = 0;
        *(s8 *)((u8 *)(temp_2) + 5) = 0;
    }
    func_002e0dd0();
    return 1;
}

// FUN_002BB550
s32 func_002bb550(s64 arg0)
{
    s32 temp_4;
    u8 **temp_16;
    u8 *temp_2;

    temp_16 = D_00882F40 + (s8)arg0;
    temp_2 = *temp_16;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0);
    if (temp_4 >= 0) {
        func_002777f0(temp_4);
        *(s32 *)(*temp_16 + 0) = -1;
        *(s8 *)(*temp_16 + 4) = 0;
        *(s8 *)(*temp_16 + 5) = 0;
        jtbl_008873EC[0](*temp_16);
        *temp_16 = NULL;
    }
    func_002e0dd0();
    return 1;
}
// FUN_002BB680
s32 func_002bb680(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p == NULL) {
        return 0;
    }
    if (*(s32 *)p < 0) {
        return 0;
    }
    if (*(s8 *)(p + 5) != 0) {
        if (*(s8 *)(p + 4) == 2) {
            return 0;
        }
    }
    return *(s8 *)(p + 4);
}

// FUN_002BB7C0
void func_002bb7c0(s32 arg0)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    s32 temp_4;
    s8 temp_5;
    Item *temp_2;

    temp_2 = (Item *)func_002bbf70();
    if ((temp_2 != NULL) && (temp_4 = temp_2->id, temp_4 >= 0)) {
        temp_5 = temp_2->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (func_00276e10(temp_4, temp_5) < 0) {
                temp_2->status = 2;
                break;
            }
            break;
        case 2:
        {
            s32 *temp_2_2;
            s32 *temp_2_3;
            s32 temp_4_2;
            s32 var_3;
            s32 var_3_2;

            if (temp_2->next >= 0) {
                if (iGpffffb578 == 1) {
                    func_002786c0(temp_4, 6, 1);
                }
                func_00277fd0(temp_2->id, temp_2->fieldC);
                func_00277be0(temp_2->id, temp_2->next);
                temp_2->next = -1;
            }
            if (temp_2->flag == 0) {
                temp_2_2 = func_002bbf70();
                if (temp_2_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_2 = temp_2_2[0];
                    if (temp_4_2 < 0) {
                        var_3 = 0;
                    } else if (func_00276fb0(temp_4_2) < 0) {
                        var_3 = 0;
                    } else {
                        temp_2_3 = func_002bbf70();
                        if (temp_2_3 == NULL) {
                            var_3_2 = -1;
                        } else {
                            temp_4_2 = temp_2_3[0];
                            if (temp_4_2 < 0) {
                                var_3_2 = -1;
                            } else {
                                var_3_2 = func_00277070(temp_4_2);
                            }
                        }
                        *((s8 *)temp_2_2 + 0xD) = var_3_2;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_2->status = 3;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            Item *temp_2_4;

            temp_2_4 = (Item *)func_002bbf70();
            if (temp_2_4 != NULL) {
                temp_4 = temp_2_4->id;
                if (temp_4 >= 0) {
                    func_00276e70(temp_4, 0);
                    if (arg0 != 0) {
                        func_00277250(temp_2_4->id);
                    }
                    func_00277ad0(temp_2_4->id, 0);
                    func_002bbdd0(1);
                    temp_2_4->status = 0;
                }
            }
            break;
        }
        }
    }
}
// FUN_002BB9E0
void func_002bb9e0(u8 *arg0, s32 arg1)
{
    typedef struct {
        s32 id;
        s8 status;
        s8 flag;
        u8 pad6[2];
        s32 next;
        s8 fieldC;
        s8 result;
    } Item;
    extern void func_002bbe90();
    s32 temp_4;
    s32 saved_arg1;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_3;
    s64 temp_18;
    s8 temp_5;
    s32 var_4;
    s32 var_4_2;
    Item **temp_16;
    Item **temp_16_2;
    Item **temp_17;
    Item **temp_5_2;
    Item *temp_2;
    Item *temp_2_2;
    Item *temp_3;
    Item *temp_3_2;
    Item *temp_4_2;
    Item *temp_6;
    saved_arg1 = arg1;
    temp_18 = (s8)arg0;
    temp_17 = &((Item **)D_00882F40)[(s8)temp_18];
    temp_6 = *temp_17;
    if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
        temp_5 = temp_6->status;
        switch (temp_5) {
        case 0:
            return;
        case 1:
            if (func_00276e10(temp_4, temp_5, temp_6) < 0) {
                (*temp_17)->status = 2;
                return;
            }
            break;
        case 2:
            if (temp_6->next >= 0) {
                if (iGpffffb578 == 1) {
                    func_002786c0(temp_4, 6, 1);
                }
                temp_16 = &((Item **)D_00882F40)[(s8)arg0];
                temp_2 = *temp_16;
                func_00277fd0(temp_2->id, temp_2->fieldC);
                temp_2_2 = *temp_16;
                func_00277be0(temp_2_2->id, temp_2_2->next);
                (*temp_16)->next = -1;
            }
            temp_4_2 = *temp_17;
            if (temp_4_2->flag == 0) {
                if (temp_4_2 == NULL) {
                    var_3 = 0;
                } else {
                    temp_4_3 = temp_4_2->id;
                    if (temp_4_3 < 0) {
                        var_3 = 0;
                    } else if (func_00276fb0(temp_4_3) < 0) {
                        var_3 = 0;
                    } else {
                        temp_3 = *temp_17;
                        if (temp_3 == NULL) {
                            var_4 = -1;
                        } else {
                            temp_4_4 = temp_3->id;
                            if (temp_4_4 < 0) {
                                var_4 = -1;
                            } else {
                                var_4 = func_00277070(temp_4_4);
                            }
                        }
                        (*temp_17)->result = var_4;
                        var_3 = 1;
                    }
                }
                if (var_3 == 0) {
                    temp_5_2 = &((Item **)D_00882F40)[(s8)arg0];
                    (*temp_5_2)->status = 3;
                    temp_3_2 = *temp_5_2;
                    if (temp_3_2 == NULL) {
                        var_4_2 = -1;
                    } else {
                        temp_4_5 = temp_3_2->id;
                        if (temp_4_5 < 0) {
                            var_4_2 = -1;
                        } else {
                            var_4_2 = func_00277070(temp_4_5);
                        }
                    }
                    (&iGpffffb580)[(s8)temp_18] = var_4_2;
                    return;
                }
            }
            break;
        case 3:
            if ((temp_6 != NULL) && (temp_4 = temp_6->id, temp_4 >= 0)) {
                func_00276e70(temp_4, 0);
                if (saved_arg1 != 0) {
                    func_00277250((*temp_17)->id);
                }
                temp_16_2 = &((Item **)D_00882F40)[(s8)arg0];
                func_00277ad0((*temp_16_2)->id, 0);
                func_002bbe90(arg0, 1);
                (*temp_16_2)->status = 0;
            }
            break;
        }
    }
}
// FUN_002BBCC0
void func_002bbcc0(void)
{
    func_002bb7c0(1);
}
// FUN_002BBCF0
void func_002bbcf0(u8 *arg0) {
    func_002bb9e0(arg0, 1);
}



// FUN_002BBD80
void func_002bbd80(s32 arg0) {
    u8 *p;

    p = D_00882F40[(s8)arg0];
    if (p != NULL) {
        func_00278450(*(s32 *)p);
    }
}

// FUN_002BC0B0
void func_002bc0b0(u32 arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    f32 f0;
    f32 f1;
    f32 f2;
    func_002bc0e0(f0, f1, f2, arg0, arg1, arg2, 1, arg3, arg4);
}



// FUN_002BC0E0
 s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    extern u8 func_00106600(s16 arg0);
    extern u32 func_00106880(s16 arg0);
    extern s64 func_00106b80(s64 arg0);
    extern s32 func_00278e90(s32 arg0);
    extern s32 func_002791f0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    extern s32 func_00279470(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);
    extern s32 D_0063F2F0[];
    extern s32 D_0063F310[];
    extern s32 D_0063F2C0[];
    s32 spC0[6];
    s32 sp90[9];
    s32 *src;
    s32 *dst;
    u32 temp_22;
    s32 *src2;
    s32 *dst2;
    s32 loop;
    s32 loop2;
    s32 temp_1;
    s32 temp_2;
    s32 temp_index;
    s32 temp_item_index;
    s32 temp_item;
    s32 temp_level;
    u32 temp_index_2;
    s32 temp_count;

    src = D_0063F2F0;
    dst = spC0;
    loop = 3;
    do {
        temp_1 = src[0];
        temp_2 = src[1];
        src += 2;
        loop -= 1;
        dst[0] = temp_1;
        dst[1] = temp_2;
        dst += 2;
    } while (loop > 0);
    src2 = D_0063F310;
    dst2 = sp90;
    loop2 = 9;
    do {
        temp_1 = *src2;
        src2 += 1;
        loop2 -= 1;
        *dst2 = temp_1;
        dst2 += 1;
    } while (loop2 > 0);
    switch (arg4) {
    case 0:
        if (arg5 >= 0x400) {
            temp_index = 5;
        } else {
            temp_index = (s32)func_00106880((s16)arg5);
        }
        temp_item_index = spC0[temp_index];
        arg5 = (s16)func_00106b80((s16)arg5);
        goto block_23;
    case 1:
        temp_index_2 = arg5 & 0xFFFF;
        temp_item_index = spC0[func_00106880((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)func_00278e90(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_level = arg5 >> 16;
        if ((u32)func_00278e90(D_0063F2C0[0]) < (u32)temp_level) {
            return 0;
        }
        func_00279470(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], temp_level);
        return 0;
    case 2:
        temp_index_2 = func_00106600((s16)arg5) & 0xFF;
        temp_item_index = spC0[func_00106880((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)func_00278e90(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_22 = func_00278e90(D_0063F2C0[0]);
        if (temp_22 < (u32)(func_00106600((s16)arg5) & 0xFF)) {
            return 0;
        }
        func_00279470(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], func_00106600((s16)arg5) & 0xFF);
        return 0;
    default:
        temp_item_index = sp90[arg4];
        goto block_23;
    }
block_23:
    temp_item = D_0063F2B0[temp_item_index];
    if ((u32)func_00278e90(temp_item) < (u32)arg5) {
        return 0;
    }
    func_002791f0(fparg0, fparg1, fparg2,
                  arg0, arg1, arg2, arg3, temp_item, arg5);
    return 0;
}
// FUN_002BC4B0
void func_002bc4b0(s64 arg0, s32 arg1, s32 arg2, f32 fparg0, s32 arg3, s32 arg4, s32 arg5)
{
    extern u32 func_00106850();
    extern s64 func_00106b80();
    extern void func_002791f0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    u32 temp_2;

    temp_2 = func_00106850();
    switch (temp_2) {
    case 0:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[0],
                      (s16)func_00106b80(arg0));
        return;
    case 1:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[1],
                      (s16)func_00106b80(arg0));
        return;
    case 2:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[2],
                      (s16)func_00106b80(arg0));
        return;
    case 3:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[4],
                      (s16)func_00106b80(arg0));
        return;
    case 4:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[5],
                      (s16)func_00106b80(arg0));
        return;
    case 5:
        func_002791f0((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[7],
                      (s16)func_00106b80(arg0));
    default:
        return;
    }
}
// FUN_002BC7A0
void func_002bc7a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_002791f0(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0);
}

// FUN_002BC7F0
void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_00279350(arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0, &D_00793E80[arg5 * 0x30]);
}

// FUN_002BC860
void func_002bc860(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    func_002791f0(arg0, arg1, arg2, 1, D_0063F2C8[0], arg3);
}
// FUN_002BC890
INCLUDE_ASM("asm/nonmatchings/code1_002b", func_002bc890);
// FUN_002BC9E0
s32 func_002bc9e0(u8 *arg0)
{
    u8 sp40[0x20];
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_4_3;
    s32 var_17;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_4_2;
    u8 *var_16;

    if (arg0 == NULL) {
        func_0046d730(&D_0063F2A0, 0x558);
    }
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 0x18) + 4);
    if (temp_18 != NULL) {
        temp_17 = *(u8 **)(temp_18 + 0x14);
        temp_4 = *(s32 *)(temp_17 + 8);
        if (temp_4 == 0) {
            if (*(s32 *)(temp_17 + 4) == 0) {
                func_00442088(sp40, &D_0063F340);
            } else if ((func_00110d60((s16)func_001060b0()) & 1) != 0) {
                func_00442088(sp40, &D_0063F360, *(s32 *)(temp_17 + 4));
            } else {
                func_00442088(sp40, &D_0063F380, *(s32 *)(temp_17 + 4));
            }
            *(s32 *)(temp_17 + 8) = func_0046aea0(sp40);
        } else if (func_0046a750(temp_4) != 0) {
            *(s32 *)(temp_17 + 0) = *(s32 *)(temp_17 + 0) | 2;
            temp_4_2 = *(u8 **)(arg0 + 0x18);
            func_002e2240(temp_4_2, temp_4_2 + 4, temp_18);
        }
    }
    var_16 = arg0 + 0x1C;
    var_17 = 0;
    goto loop_19;
loop_20:
    temp_3 = *(s32 *)var_16;
    if (temp_3 & 4) {
        temp_4_3 = *(s32 *)(var_16 + 8);
        if (temp_4_3 != 0) {
            if (func_0046a750(temp_4_3) != 0) {
                temp_3_2 = *(s32 *)var_16 & ~4;
                *(s32 *)var_16 = temp_3_2;
                *(s32 *)var_16 = temp_3_2 & ~2;
                func_0046b0d0(*(void **)(var_16 + 8));
                *(s32 *)(var_16 + 8) = 0;
            }
        } else {
            temp_3_3 = temp_3 & ~4;
            *(s32 *)var_16 = temp_3_3;
            *(s32 *)var_16 = temp_3_3 & ~2;
        }
    }
    var_16 += 0xC;
    var_17 += 1;
loop_19:
    if (var_17 < 0xB) {
        goto loop_20;
    }
    return 0;
}
// FUN_002BCBC0
s32 func_002bcbc0(s32 arg0, s32 arg1)
{
    u8 *temp_3;

    if (arg0 == 0) {
        func_0046d730(D_0063F2A0, 0x58F);
    }
    if (arg1 < 0) {
        goto error;
    }
    if (arg1 <= 0xB) {
        goto done;
    }
error:
    func_0046d730(D_0063F2A0, 0x590);
done:
    temp_3 = (u8 *)(arg0 + arg1 * 0xC);
    *(s32 *)(temp_3 + 0x1C) |= 4;
    return 0;
}
// FUN_002BD280
s32 func_002bd280(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    s32 temp_20;
    u8 *temp_21;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;

    temp_21 = (u8 *)iGpffffb57c;
    if (*(s32 *)(temp_21 + 0xC) == 0) {
        func_0046d730(&D_0063F2A0, 0x668);
    }
    temp_20 = *(s32 *)(temp_21 + 0xC);
    temp_4 = *(u8 **)(temp_21 + 0);
    temp_2 = func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0x30);
    temp_3 = *(u8 **)(temp_2 + 0x14);
    *(u8 **)(temp_3 + 0) = temp_2;
    *(s32 *)(temp_3 + 0x2C) = arg0;
    *(s32 *)(temp_3 + 0x20) = arg1;
    *(s32 *)(temp_3 + 0x24) = arg2;
    *(s32 *)(temp_3 + 0x28) = temp_20;
    *(s16 *)(temp_3 + 0xE) = arg3;
    return 0;
}
// FUN_002BD3E0
void func_002bd3e0(void) {
    func_002bcc60(D_0072466C);
}



// FUN_002BD410
void func_002bd410(void)
{
    func_0045a9a0(1, 0);
    func_002bd440();
}
// FUN_002BD7B0
s32 func_002bd7b0(void)
{
    u8 *p;
    s32 temp_2;

    p = (u8 *)D_00882F60;
    if (p != NULL) {
        *(s32 *)(p + 0) = -1;
        *(s8 *)(p + 4) = 0;
        *(s8 *)(p + 5) = 0;
        *(s32 *)(p + 8) = -1;
        *(s8 *)(p + 0xC) = 1;
        *(s8 *)(p + 0xD) = 1;
    }
    if (*(s32 *)(p + 0) < 0) {
        temp_2 = func_002774d0();
        *(s32 *)(p + 0) = temp_2;
        func_00278610(temp_2, 1);
        return 1;
    }
    return 0;
}
// FUN_002BD840
s32 func_002bd840(s32 arg0)
{
    u8 *p;

    p = (u8 *)D_00882F60;
    if (*(s32 *)(p + 0) < 0) {
        return 0;
    }
    func_00278610(*(s32 *)(p + 0), 1);
    func_00278170(*(s32 *)(p + 0), 0x200000);
    func_002778c0(*(s32 *)(p + 0), arg0, 0);
    *(s8 *)(p + 4) = 1;
    func_00277010(*(s32 *)(p + 0), -1);
    return 1;
}
// FUN_002BD8E0
s32 func_002bd8e0(u8 *arg0)
{
    s8 temp_3;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s8 *)(temp_16 + 0);
    switch (temp_3) {
    case 1:
        func_00144c90(8, 4);
        *(s8 *)(temp_16 + 0) = 2;
    case 2:
        if ((func_00144f60() != 0) && (func_0015f660() != 0)) {
            if (func_002cb6a0(*(s32 *)(temp_16 + 4)) == 0) {
                return 0;
            }
            func_0045a3e0(0x15, 1);
            temp_17 = func_00457120();
            func_004577d0(temp_17, func_0014b4d0());
            temp_17_2 = func_00457120();
            func_003e9cb0(*(s32 *)(temp_17_2 + 4), (void *)func_0014b450(), 0);
            *(s8 *)(temp_16 + 0) = 3;
        }
        goto block_26;
    case 3:
        func_00122640(1, 0);
        *(s8 *)(temp_16 + 0) = 4;
    case 4:
        if (func_00122720() != 0) {
            func_002caa00(*(s32 *)(temp_16 + 4), 0xD);
            *(s8 *)(temp_16 + 0) = 7;
        }
        goto block_26;
    case 5:
        func_00122520(1, 0);
        *(s8 *)(temp_16 + 0) = 6;
    case 6:
        if (func_00122720() != 0) {
            *(s8 *)(temp_16 + 0) = 0x11;
        }
        goto block_26;
    case 7:
        if (func_00452380(&D_0063F3B0) == 0) {
            *(s8 *)(temp_16 + 0) = 5;
        }
        goto block_26;
    case 17:
        return -1;
    case 35:
        return -1;
    default:
    block_26:
        return 0;
    }
}
// FUN_002BDB10
void func_002bdb10(u8 *arg0)
{
    func_00145080();
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_002BDFF0
s32 func_002bdff0(s64 arg0)
{
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;

    if (func_00106850() != 3) {
        goto false_result;
    }
    temp_16 = func_002be100(func_00106ac0(arg0) & 0xFF) & 0xFF;
    if (temp_16 < (func_002be100(func_002e78a0()) & 0xFF)) {
        return 1;
    }
    temp_16_2 = func_002be100(func_00106ac0(arg0) & 0xFF) & 0xFF;
    if (temp_16_2 != (func_002be100(func_002e78a0()) & 0xFF)) {
        goto false_result;
    }
    temp_16_3 = (s8)func_00106af0(arg0);
    if (temp_16_3 <= (func_002e78e0() & 0xFF)) {
        return 1;
    }
false_result:
    return 0;
}
// FUN_002BE100
s32 func_002be100(s32 arg0) {
    s32 i = 0;
    s32 key = arg0 & 0xFF;
    s8 *t = D_007488F8;

    while ((i & 0xFF) < 0xC) {
        if (key == t[i & 0xFF]) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
    return 0;
}

// FUN_002BE160
s32 func_002be160(u8 *arg0, s32 arg1) {
    s32 n = arg1 & 0xFFFF;
    if (n == 0) {
        return 1;
    }
    return (clndGetMoonPhase() & 0xFF) >= n;
}

// FUN_002BE1B0
void func_002be1b0(void)
{
    func_002be1e0(func_00106880());
}
// FUN_002BE1E0
s32 func_002be1e0(s32 arg0)
{
    if (arg0 & 1) {
        return 0;
    }
    if (arg0 & 2) {
        return 1;
    }
    if (arg0 & 4) {
        return 2;
    }
    if (arg0 & 8) {
        return 3;
    }
    if (arg0 & 0x10) {
        return 4;
    }
    if (arg0 & 0x20) {
        return 5;
    }
    if (arg0 & 0x40) {
        return 6;
    }
    if (arg0 & 0x80) {
        return 7;
    }
    if (arg0 & 0x100) {
        return 8;
    }
    if (arg0 & 0x200) {
        return 9;
    }
    if (arg0 & 0x400) {
        return 0xA;
    }
    if (arg0 & 0x800) {
        return 0xB;
    }
    if (arg0 & 0x1000) {
        return 0xC;
    }
    if (arg0 & 0x2000) {
        return 0xD;
    }
    if (arg0 & 0x4000) {
        return 0xE;
    }
    if (arg0 & 0x8000) {
        return 0xF;
    }
    if (arg0 & 0x10000) {
        return 0x10;
    }
    if (arg0 & 0x20000) {
        return 0x11;
    }
    if (arg0 & 0x40000) {
        return 0x12;
    }
    return 0;
}
// FUN_002BE3C0
void func_002be3c0(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7100D);
}
// FUN_002BE4A0
void func_002be4a0(void)
{
    s64 sp18;

    func_002b2970((u8 *)&sp18,
                  580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()),
                  15.0f);
    func_00364320(sp18, 0xFF, func_002e7a60(), 1.0f);
}