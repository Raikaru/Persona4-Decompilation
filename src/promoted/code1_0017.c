#include "include_asm.h"
#include "type.h"
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
extern void func_0015a630();
extern void func_00174c20();
extern s32 func_0015f660();
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern s32 func_00102980(void);
extern void func_00145080(void);
extern void func_00260510(void);
extern void *func_0043f9c8(void *dst, s32 value, s32 size);
extern s32 func_00110e80(void);
extern u8 *func_00155280(void);
extern s32 func_00156170(s32 arg0);
extern s32 func_00156180(s32 arg0);
extern s32 func_00106330(s32 arg0);
extern s32 func_0016fd00(void);
extern s32 func_00162510(u16 arg0, u16 arg1);
extern u32 func_003b7060(void);
extern s32 func_0015a160(void);
extern s32 func_00161630(u16 a, u16 b, u16 c, s32 d);
extern void func_00182310(s32 arg0);
extern void func_0018e030(s32 arg0, s32 arg1);
extern s32 func_0029da90(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00452490(s32 arg0);
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);
extern s32 func_00170f60(u8 *arg0, s32 arg1);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern s32 func_0014a160(void);
extern s32 func_0015a100(void);
extern s32 func_0015a130(void);
extern void func_0015a7c0(s32 arg0);
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005F18C0[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
extern void func_0018a000(s32 arg0, s32 arg1);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_002af3e0(s32 arg0, s32 arg1);
extern void func_002afb70(s32 arg0, s32 arg1);
extern s32 func_0012d000(s32 arg0, s32 arg1);
extern void func_00106390(s32 arg0, s32 arg1);
s32 func_0017c930(u8 *arg0);
void func_0017cc90(u8 *arg0);
void func_0017d240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern s32 func_0017cd60(u8 *arg0);
extern void func_0044ea90(const void *msg, s32 id);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c, void (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_0025ecd0(f32 farg0, f32 farg1, f32 farg2,
                         s32 arg0, s32 arg1, s32 arg2, void *arg3,
                         s32 arg4, s16 arg5, s16 arg6,
                         f32 farg3, f32 farg4, f32 farg5, u8 *arg7);
extern f32 func_0044b7b0(f32 arg0);
extern u8 *func_0046a770(char *arg0);
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];

extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00168ec0(void *arg0, void *arg1, void *arg2);
extern void func_0029cf50(s32 arg0);
extern s32 func_00110fc0(void);
extern s32 func_00174680(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0018ced0(void);
extern void func_0018c7e0(void);
extern s32 func_00159f70(s32 arg0);
extern s32 func_00155290(void);
extern s32 func_0014ec50(s32 arg0, s32 arg1);
extern s32 func_0029d050(void);
extern void func_0029dfe0(s32 arg0, s32 arg1);
extern s32 func_00452490(s32 arg0);

extern s32 func_0029cc00(s32 arg0);
extern s64 func_00105ee0(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 *func_00457120(void);
extern u8 *func_0047a2f0(void *arg0);
extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
extern void func_003e0380(f32 *arg0);
extern void func_003e03e0(void *arg0, f32 *arg1);
extern void func_003e05d0(void *arg0);
extern void func_004789c0(void *arg0);
extern void func_0047a320(void *arg0);
extern s32 func_00179fc0(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         s32 arg4, u8 *arg5, f32 arg6, f32 arg7);
extern S_00178590 *func_00174c00(void);
extern void func_003e40b0(void *arg0, void *arg1);
extern void func_003e42a0(void *dst, void *src, u8 *arg2);
extern u8 D_007EFA00[];
extern void func_00442088(void *dst, const void *src);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 arg0, void *arg1);
extern void func_0014def0(s32 arg0, s32 arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern s32 D_005F1930[];
extern s32 D_005F1934[];
extern void func_002bd410(void);
extern void func_002bd3c0(void);

extern u8 *D_007643D0;
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffba48;
extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003cbc60(s32 arg0, u8 *arg1);
extern void func_003e8440(u8 *arg0);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void func_003ef080(u8 *arg0, s32 arg1);
extern void func_003ef3a0(u8 *arg0);
extern void func_003efd20(u8 *arg0, s32 arg1);
extern s32 func_00457190(void);

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);



/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */

// FUN_00170120
s32 func_00170120(s32 arg0)
{
    u8 *temp_2;
    u8 *temp_4;

    func_0016fd00();
    if (arg0 != 1)
        return 1;
    temp_2 = iGpffff9db0;
    if (func_00162510(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4)) == 1)
        return (func_003b7060() % 3U) + 6;
    temp_4 = iGpffff9db0;
    if ((*(s32 *)(temp_4 + 0) == 0x44) &&
        (*(s32 *)(temp_4 + 4) == 1))
        return (func_003b7060() % 3U) + 6;
    if (func_0015a160() != 0)
        return 1;
    return (func_003b7060() % 3U) + 6;
}

// FUN_00170960
s32 func_00170960(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(func_00155280() + 0x18) != 0) && (D_008C024E[0] & 0x800)) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_001709C0
s32 func_001709c0(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_00182310(1);
        func_002bd410();
        func_002bd3c0();
        temp_2 = func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        func_0045af60(0, 0, 0, 3);
        temp_2 = func_00155280();
        func_0018a000(*(s32 *)(temp_2 + 0x30), 1);
        temp_2 = func_00155280();
        func_002af3e0(*(s32 *)(temp_2 + 0x18), 1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x820) {
            func_00182310(0);
            temp_2 = func_00155280();
            func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
            temp_2 = func_00155280();
            func_0018a000(*(s32 *)(temp_2 + 0x30), 0);
            temp_2 = func_00155280();
            func_002af3e0(*(s32 *)(temp_2 + 0x18), 0);
            func_0045af60(0, 0, 0, 4);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00170B50
s32 func_00170b50(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (func_00106330(0x37) == 1) {
        return 0;
    }
    if (D_008C024E[0] & 0x10) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170BC0
s32 func_00170bc0(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (*(s32 *)(func_00155280() + 0x30) != 0)
            func_0018a000(*(s32 *)(func_00155280() + 0x30), 1);
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)(func_00155280() + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0012d000((s32)arg0, 1);
        if (*(s32 *)(func_00155280() + 0x18) != 0)
            func_002afb70(*(s32 *)(func_00155280() + 0x18), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            if (*(s32 *)(func_00155280() + 0x30) != 0)
                func_0018a000(*(s32 *)(func_00155280() + 0x30), 0);
            if (func_00106330(0x1401) != 0) {
                func_0015a7c0(func_0015a160());
                func_00106390(0x1401, 0);
                temp_17 = func_0015a100();
                func_0029db50(0xF, temp_17, func_0015a130(), 5);
                *(s32 *)(temp_16 + 4) = 3;
            } else {
                if (*(s32 *)(func_00155280() + 0x18) != 0)
                    func_002afb70(*(s32 *)(func_00155280() + 0x18), 0);
                func_00182310(0);
                func_0018e030(*(s32 *)(func_00155280() + 0x1C), 0);
                *(s32 *)(temp_16 + 0x10) = 0;
                *(s32 *)(temp_16 + 4) += 1;
            }
        }
        break;
    case 2:
        return 0;
    case 3:
        break;
    default:
        break;
    }
    return 1;
}

// FUN_00170E10
s32 func_00170e10(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (D_008C024E[0] & 0x80) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170E50
s32 func_00170e50(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        temp_2 = func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0029da90(0xF, iGpffffb284, 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) == 1)
            break;
        temp_2 = func_00155280();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
        func_00182310(0);
        *(s32 *)(temp_16 + 4) += 1;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00170F60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00170f60);

// FUN_001711B0
s32 func_001711b0(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (func_00170f60(D_007EF9B0, 0) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00171280
s32 func_00171280(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (func_0014a160() == 1)
            func_0015a7c0(func_0015a160());
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)(func_00155280() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 0);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)(func_00155280() + 0x1C), 0);
            func_00182310(0);
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_001713E0
s32 func_001713e0(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((func_0014a200() == 0) && (func_0014a270() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (func_00170f60(D_007EF9B0, 1) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_001714B0
s32 func_001714b0(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (func_0014a160() == 1)
            func_0015a7c0(func_0015a160());
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)(func_00155280() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (func_00452490(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)(func_00155280() + 0x1C), 0);
            func_00182310(0);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00175F70
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00175f70);

// FUN_001761D0
s32 func_001761d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40) == 1;
}

// FUN_001761F0
s32 func_001761f0(void)
{
    func_00110e80();
    return 1;
}
// FUN_00176220
s32 func_00176220(void)
{
    if (func_0029d020() > 3) {
        func_0029cf50(func_00110f00());
        return 1;
    }
    func_0029cf50(0);
    return 0;
}

// FUN_00176280
void func_00176280(void)
{
    func_0015f660();
}

// FUN_001762A0
s32 func_001762a0(void)
{
    if (func_0018ced0() == 0) {
        func_0018c7e0();
    }
    return 1;
}
// FUN_001762E0
s32 func_001762e0(void)
{
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00110fc0();
    return 1;
}
// FUN_00176320
s32 func_00176320(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_001029a0(0x19, NULL, 0, 0);
    return 1;
}

// FUN_00176370
s32 func_00176370(void) {
    s32 sp1C;

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_0043f9c8(&sp1C, 0, 4);
    sp1C = func_0029cc00(0);
    func_001029a0(0xC, &sp1C, 4, 2);
    return 1;
}

// FUN_001763F0
s32 func_001763f0(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_001029a0(0xD, NULL, 0, 2);
    return 1;
}

// FUN_00176450
s32 func_00176450(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_0043f9c8(sp10, 0, 0x1C);
    sp10[0] = (s16)func_0029cc00(0);
    sp10[1] = (s16)func_0029cc00(1);
    sp10[2] = (s16)func_0029cc00(2);
    sp10[4] = (s16)func_0029cc00(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_00176500
s32 func_00176500(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    *(s16 *)(iGpffff9db0 + 0x10) = -1;
    func_0043f9c8(sp10, 0, 0x1C);
    sp10[0] = (s16)func_0029cc00(0);
    sp10[1] = (s16)func_0029cc00(1);
    sp10[2] = (s16)func_0029cc00(2);
    sp10[4] = (s16)func_0029cc00(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_001765C0
s32 func_001765c0(void)
{
    s32 sp30[7];
    s32 temp_17;
    s32 temp_3;
    s32 var_16;


    var_16 = 0;
    temp_17 = func_0029d020();
    if (func_0015f660() == 0) {
        iGpffffb304 = func_0029d020();
        return 0;
    }
    if ((temp_17 == 0) || ((temp_17 - 1) == iGpffffb304))
        iGpffffb300 = 0;
    sp30[3] = func_0029cc00(0);
    sp30[4] = func_0029cc00(1);
    sp30[5] = func_0029cc00(2);
    temp_3 = iGpffffb300;
    if (temp_3 == 3) {
        func_001029a0(0xA, sp30, 0x1C, 2);
    } else if (temp_3 > 0xA) {
        if (func_00102980() == -1) {
            iGpffffb300 = 0;
            var_16 = 1;
        } else {
            var_16 = 0;
        }
    }
    iGpffffb300 += 1;
    return var_16;
}
// FUN_001766E0
s32 func_001766e0(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    sp18[0] = func_0029cc00(0);
    sp18[1] = 0xFFFF;
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176770
s32 func_00176770(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    func_00260510();
    sp18[0] = func_0029cc00(0);
    sp18[1] = func_0029cc00(1);
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176810
s32 func_00176810(void)
{
    func_00159f70(func_0029cc00(0));
    return 1;
}
// FUN_00176850
s32 func_00176850(void)
{
    func_0015a630();
    return 1;
}

// FUN_00176880
s32 func_00176880(void)
{
    func_0029cf50(func_0015a160());
    return 1;
}
// FUN_001768B0
s32 func_001768b0(void)
{
    func_0029cf50(func_00155290());
    return 1;
}
// FUN_001768E0
s32 func_001768e0(void)
{
    s32 temp_4_2;
    s32 temp_4;
    s32 var_5;
    s32 var_18;
    u16 temp_19;
    s32 var_17;
    u16 var_16;
    s32 var_3;

    var_17 = func_0029cc00(0);
    var_16 = 0;
    if (var_17 != 0) {
        var_18 = 0;
        goto loop_8_cond;
loop_8_body:
        var_5 = 0;
        temp_4 = (s32)((u8 *)D_007EF9B0 + (var_18 * 0x750));
        if (*(s32 *)(temp_4 + 0x48) != 0) {
            if (*(s32 *)(temp_4 + 0x54) != 0)
                var_5 = 1;
        }
        var_5 = (var_5 != 0);
        if ((var_5 != 1) ||
            (temp_19 = *(u16 *)(temp_4 + 0x728),
             temp_19 != (s16)func_00105ee0(var_17 - 1))) {
            var_18 += 1;
            goto loop_8_cond;
        }
        goto loop_8_found;
loop_8_cond:
        if (var_18 < 4)
            goto loop_8_body;
loop_8_found:
        ;
        if (var_18 >= 4) {
            func_0029cf50(0);
            return 1;
        }
        var_17 = var_18;
    }
block_12:
    var_3 = 0;
    temp_4_2 = var_17 * 0x750;
    if ((*(s32 *)((u8 *)D_007EF9F8 + temp_4_2) != 0) &&
        (*(s32 *)((u8 *)D_007EFA04 + temp_4_2) != 0))
        var_3 = 1;
    var_3 = (var_3 != 0);
    if (var_3 == 1)
        var_16 = **(u16 **)((u8 *)D_007EFA04 + temp_4_2);
    func_0029cf50(var_16 & 0xFFFF);
    return 1;
}
// FUN_00176A50
s32 func_00176a50(void)
{
    u8 *node;
    s32 count;

    node = (u8 *)func_001452b0(3);
    count = 0;
    while (node != NULL) {
        count += 1;
        node = *(u8 **)(node + 0x138);
    }
    func_0029cf50(count);
    return 1;
}

// FUN_00176AB0
s32 func_00176ab0(void)
{
    s32 temp_16;
    s32 var_3;
    s32 var_4;
    u16 temp_3;
    u8 *var_2;

    temp_16 = func_0029cc00(0);
    var_2 = func_001452b0(3);
    var_4 = 0;
    var_3 = 0;
    goto loop_3_cond;
loop_3_body:
    if (temp_16 == var_3)
        goto loop_3_done;
    var_3 += 1;
    var_2 = *(u8 **)(var_2 + 0x138);
loop_3_cond:
    if (var_2 != NULL)
        goto loop_3_body;
loop_3_done:
    if (var_2 != NULL) {
        temp_3 = *(u16 *)(*(u8 **)(var_2 + 0x164) + 0xD6);
        var_4 = (temp_3 / 50) + 1;
        if ((s32)temp_3 > 0x1F4)
            var_4 = 0;
    }
    func_0029cf50(var_4);
    return 1;
}
// FUN_00176B60
s32 func_00176b60(void) {
    s32 v;

    v = 0;
    if (*(s32 *)func_00155280() != 0) {
        v = func_00156170(*(s32 *)func_00155280()) & 0xFFFF;
    }
    func_0029cf50(v);
    return 1;
}

// FUN_00176BC0
s32 func_00176bc0(void) {
    s32 v;

    v = 0;
    if (*(s32 *)func_00155280() != 0) {
        v = func_00156180(*(s32 *)func_00155280()) & 0xFFFF;
    }
    func_0029cf50(v);
    return 1;
}

// FUN_00178560
s32 func_00178560(void)
{
    func_00174c20();
    return 1;
}

// FUN_00178590
s32 func_00178590(void) {
    Vec3_00178590 sp50;
    Vec3_00178590 sp40;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    S_00178590 *temp_2;
    s32 var_17;
    u8 *temp_2_2;

    var_17 = 1;
    temp_2 = func_00174c00();
    if (temp_2 != NULL) {
        temp_2_2 = func_0047a2f0(temp_2->field_144);
        sp40 = *(Vec3_00178590 *)(temp_2_2 + 0x20);
        temp_f20 = *(f32 *)(func_0047a2f0(temp_2->field_144) + 0x30);
        sp50.x = temp_f20 - *(f32 *)(func_0047a2f0(*(u8 **)D_007EFA00) + 0x30);
        temp_f20_2 = *(f32 *)(func_0047a2f0(temp_2->field_144) + 0x34);
        sp50.y = temp_f20_2 - *(f32 *)(func_0047a2f0(*(u8 **)D_007EFA00) + 0x34);
        temp_f20_3 = *(f32 *)(func_0047a2f0(temp_2->field_144) + 0x38);
        sp50.z = temp_f20_3 - *(f32 *)(func_0047a2f0(*(u8 **)D_007EFA00) + 0x38);
        func_003e40b0(&sp50, &sp50);
        func_003e40b0(&sp40, &sp40);
        if ((sp50.x * sp40.x + sp50.y * sp40.y + sp50.z * sp40.z) < 0.0f) {
            var_17 = 1;
        } else {
            var_17 = 3;
        }
    }
    func_0029cf50(var_17);
    return 1;
}

// FUN_001786F0
s32 func_001786f0(void)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = func_0029d040();
    temp_2 = func_0029d050();
    if (temp_2 == 0) {
        func_0029dfe0(*(s32 *)(temp_16 + 0x148), func_0014ec50(0, 1));
        return 0;
    }
    if (func_00452490(temp_2) == 1) {
        return 0;
    }
    func_0029dfe0(*(s32 *)(temp_16 + 0x148), 0);
    return 1;
}

// FUN_00178790
s32 func_00178790(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_2 = func_00174680(*(s32 *)(func_00155280() + 8), temp_17 & 0xFFFF,
                           temp_16 & 0xFFFF);
    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 0x80000000) {
        func_0029cf50(1);
    } else if (temp_2 & 0x40000000) {
        func_0029cf50(2);
    } else {
        func_0029cf50(0);
    }
    return 1;
}

/* measured: best plain-C body is 108B in the 112B retail window (112B),
   normalized_diff 4; the sole residual bytes at offset 56 are retail
   `andi $a3,$s1,0xffff` versus candidate `move $a3,$s1`. The file-scope
   func_00161630 declaration remains (u16, u16, u16, s32) for matching
   func_00164570. Probed a block-scope fourth-parameter u16 prototype at
   the function top, after locals, in an inner block, unnamed, and with
   explicit narrowed locals/casts: each moved the mask before the two lhu
   loads (nd 10); mixed third s32/fourth u16 gave nd 6. O1, schedule off,
   and function-pointer casts did not improve it. Best body remains archived
   at build/D178_00178870_body.c; committed form is bare INCLUDE_ASM. */


/* object 108B, retail window 112B, normalized_diff 4; sole differing bytes are at offsets 56-59: retail emits `andi $a3,$s1,0xffff`, while the candidate emits `move $a3,$s1`. The file-scope func_00161630 declaration remains (u16, u16, u16, s32) because it keeps verified MATCH caller func_00164570 matching. Probed the untried block-scope fourth-parameter u16 prototype at function-top, after locals, and in an inner block (with named/unnamed forms): each produced nd 10 by hoisting the a3 mask before the two lhu loads. Mixed third s32/fourth u16 produced nd 6. Explicit narrowed locals/casts, O1, schedule off, and function-pointer casts did not improve the residual. Best plain-C body; no volatile, inline asm, or M2C_ tokens. */
// FUN_00178870 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00178870);
// FUN_001788E0
s32 func_001788e0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_002bd240(1);
    func_002bd270(*(s32 *)(func_0029d040() + 0x124));
    func_002bd280(temp_17, temp_16, 0, 0);
    return 1;
}



// FUN_001789D0
s32 func_001789d0(void)
{
    func_002bd410();
    func_002bd3c0();
    return 1;
}
// FUN_00178A00
s32 func_00178a00(void)
{
    func_0029cf50(*(u16 *)(D_007643D0 + 0xC));
    return 1;
}
// FUN_00178A30
s32 func_00178a30(void)
{
    u16 temp_3_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(D_007643D0 + 0x160);
    if (*(s32 *)(temp_3 + 8) != 0) {
        func_0029cf50(4);
    } else {
        temp_3_2 = *(u16 *)(temp_3 + 2);
        if ((s32)temp_3_2 >= 0x500) {
            func_0029cf50(3);
        } else if ((s32)temp_3_2 >= 0x400) {
            func_0029cf50(2);
        } else if ((s32)temp_3_2 >= 0x300) {
            func_0029cf50(1);
        } else {
            func_0029cf50(0);
        }
    }
    return 1;
}
// FUN_00178AF0
s32 func_00178af0(void)
{
    func_0029cf50((*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 7) & 1) != 0);
    return 1;
}
/* measured: plain C body is object 64B in a 64B window; only the retail
   GP load versus zero-argument materialisation order remains (nd 6).
   Committed at nd 6. */
// FUN_00178B30
s32 func_00178b30(void)
{
  s32 value;
  s32 result;
  u8 *state = D_007643D0;
  if (value && value) {}
  result = 0;
  value = *(s32 *)(*(u8 **)(state + 0x160) + 8);
  if (value)
    result = value;
  func_0029cf50(result);
  return 1;
}
// FUN_00178B70
s32 func_00178b70(void)
{
    func_0029cf50(*(u16 *)(*(u8 **)(D_007643D0 + 0x160) + 2));
    return 1;
}
// FUN_00178BA0
s32 func_00178ba0(void)
{
    func_0029cf50((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 6));
    return 1;
}
// FUN_00178BD0
s32 func_00178bd0(void)
{
    func_0029cf50((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 4));
    return 1;
}
// FUN_00178C00
/* Returns the stored constant: retail materializes the 1 in $v0 and stores
   from there, which only happens when it is also the return value. */
s32 func_00178c00(void)
{
    *(s32 *)(D_007643D0 + 8) = 1;
    D_007643D0 = 0;
    return 1;
}



/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0, so these stay here with their two group siblings until the
   real TU is split out. They were canonical windows with no marker, i.e.
   invisible to the verifier and supplied to the link as retail bytes. */

// FUN_00179FC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00179fc0);
// FUN_0017A700
/* measured: opt_propagation off preserves the second-branch descriptor
   pointer materialisation and grouped float-load order; object matches
   the 464-byte retail window. */
#pragma opt_propagation off
void func_0017a700(u8 *arg0, u8 *arg1)
{
    struct
    {
        f32 values[6];
        s32 type;
    } sp40;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f0;
    f32 *temp_3;
    u8 *temp_17;
    u8 *temp_2;

    temp_17 = func_001452b0(0xC);
    sp40.type = 4;
    temp_f20 = *(f32 *)(arg1 + 0x18);
    sp40.values[0] = temp_f20 +
                     *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x30);
    sp40.values[1] = temp_f20 +
                     *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x34);
    sp40.values[2] = temp_f20 +
                     *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x38);
    sp40.values[3] =
        *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x30) - temp_f20;
    sp40.values[4] =
        *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x34) - temp_f20;
    sp40.values[5] =
        *(f32 *)(func_0047a2f0(*(u8 **)(arg1 + 0x10)) + 0x38) - temp_f20;
    if (temp_17 != NULL) {
        if ((*(s32 *)(*(u8 **)(temp_17 + 0x1A0)) & 1) != 0) {
            func_00179fc0(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          0,
                          &sp40,
                          0,
                          *(u8 **)(arg1 + 0x4C),
                          1.0f,
                          *(f32 *)(arg1 + 0x18) / 2.0f);
        } else {
            sp40.type = 3;
            temp_2 = func_0047a2f0(*(u8 **)(arg1 + 0x10));
            temp_3 = sp40.values;
            temp_f2 = *(f32 *)(temp_2 + 0x30);
            temp_f1 = *(f32 *)(temp_2 + 0x34);
            temp_f0 = *(f32 *)(temp_2 + 0x38);
            sp40.values[0] = temp_f2;
            sp40.values[1] = temp_f1;
            sp40.values[2] = temp_f0;
            temp_f1 = *(f32 *)(arg1 + 0x18);
            sp40.values[3] = temp_f1;
            func_00179fc0(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          1,
                          temp_3,
                          0,
                          *(u8 **)(arg1 + 0x4C),
                          1.0f,
                          temp_f1 / 2.0f);
        }
        if (iGpffffba48 == 1)
            D_00887300[0](0xE, 1);
    }
}
#pragma opt_propagation on
// FUN_0017A8D0
void func_0017a8d0(u8 *arg0, u8 *arg1)
{
    u8 stack[0x6C];
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s8 *var_3;
    s32 var_2;
    s32 var_4_2;
    u8 *var_6;
    s32 var_5;
    u8 *temp_2_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *var_2_2;
    u8 *var_6_2;
    u8 *var_5_2;
    s32 var_4;

    var_3 = (s8 *)(stack + 0x60);
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    var_2_2 = func_0047a2f0(*(u8 **)(arg1 + 0x10));
    var_6 = arg1 + 0x80;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_2_2 + 0);
        temp_3 = *(s32 *)(var_2_2 + 4);
        var_2_2 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    var_6_2 = arg1 + 0x80;
    var_5_2 = stack;
    var_4 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4 -= 1;
        *(s32 *)(var_5_2 + 0) = temp_3_2;
        *(s32 *)(var_5_2 + 4) = temp_2;
        var_5_2 += 8;
    } while (var_4 > 0);
    if (!(*(f32 *)(arg1 + 0xCC) <= *(f32 *)(arg1 + 0xD4))) {
        *(s32 *)(stack + 0x50) = 0x3F800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0xBF800000;
        temp_f0 = *(f32 *)(arg1 + 0xC8);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x38);
        *(f32 *)(stack + 0x38) = temp_f1 - temp_f0;
    } else {
        *(s32 *)(stack + 0x50) = 0xBF800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0x3F800000;
        temp_f0 = *(f32 *)(arg1 + 0xC0);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x30);
        *(f32 *)(stack + 0x30) = temp_f1 - temp_f0;
    }
    var_4_2 = 0;
    goto loop_11_cond;
loop_11_body:
    temp_3_3 = *(u8 **)(arg1 + 0x10) + (var_4_2 * 0xC);
    *(u8 *)(temp_3_3 + 0x28C) &= ~1;
    var_4_2 += 1;
loop_11_cond:
    if (var_4_2 < 5)
        goto loop_11_body;
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 4;
    func_0047a1e0(*(u8 **)(arg1 + 0x10), stack + 0x50, 2);
    temp_2_2 = func_0047a2f0(*(u8 **)(arg1 + 0x10));
    temp_f1 = *(f32 *)(stack + 0x30);
    temp_f0 = *(f32 *)(stack + 0x34);
    temp_f2 = *(f32 *)(stack + 0x38);
    *(f32 *)(temp_2_2 + 0x30) = temp_f1;
    *(f32 *)(temp_2_2 + 0x34) = temp_f0;
    *(f32 *)(temp_2_2 + 0x38) = temp_f2;
    func_003e0380((f32 *)(stack + 0x40));
    func_003e03e0(func_0047a2f0(*(u8 **)(arg1 + 0x10)),
                  (f32 *)(stack + 0x40));
    func_003e05d0(func_0047a2f0(*(u8 **)(arg1 + 0x10)));
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 0x40;
    func_004789c0(*(u8 **)(arg1 + 0x10));
    func_0047a320(*(u8 **)(arg1 + 0x10));
}
// FUN_0017AAE0
void func_0017aae0(u8 *arg0, u8 *arg1)
{
    u8 *var_5;
    s32 temp_3;
    s32 temp_4_2;
    s32 var_6;
    s32 var_5_2;
    u8 *temp_4;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *var_2;

    temp_4 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4 + 0xD8) &= ~0x40;
    D_00887300[0](0x14, 2);
    var_2 = func_0047a2f0(*(u8 **)(arg1 + 0x10));
    var_5 = arg1 + 0x80;
    var_5_2 = 8;
    do {
        temp_4_2 = *(s32 *)var_5;
        temp_3 = *(s32 *)(var_5 + 4);
        var_5 += 8;
        var_5_2 -= 1;
        *(s32 *)var_2 = temp_4_2;
        *(s32 *)(var_2 + 4) = temp_3;
        var_2 += 8;
    } while (var_5_2 > 0);
    temp_4_3 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4_3 + 0xD8) &= ~4;
    func_004789c0(*(u8 **)(arg1 + 0x10));
    func_0047a320(*(u8 **)(arg1 + 0x10));
    var_5_2 = 0;
    goto loop_4_cond;
loop_4_body:
    temp_4_4 = *(u8 **)(arg1 + 0x10) + (var_5_2 * 0xC);
    *(u8 *)(temp_4_4 + 0x28C) |= 1;
    var_5_2 += 1;
loop_4_cond:
    if (var_5_2 < 5)
        goto loop_4_body;
}
// FUN_0017ABD0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
#pragma opt_propagation off
void func_0017abd0(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);
    u8 *temp_4;

    base = D_00887300;
    base[0](7, 2);
    base[0](6, 1);
    base[0](8, 0);
    if (iGpffffba48 == 1) {
        base[0](0xE, 1);
    }
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    temp_4 = *(u8 **)(*(u8 **)(arg1 + 0x50) + 4);
    (*(void (**)(u8 *))(temp_4 + 0x48))(temp_4);
    if (iGpffffba48 == 1) {
        base[0](0xE, 1);
    }
}
/* measured: closing opt_propagation bracket for func_0017abd0. */
#pragma opt_propagation on
// FUN_0017ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017acc0);
// FUN_0017B350
void func_0017b350(u8 *arg0)
{
    u8 *temp_19;
    s32 temp_18;
    s32 temp_4;
    u16 temp_3;
    u8 *temp_16;
    u8 *temp_4_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(u16 *)(temp_16 + 0xA);
    switch (temp_3) {
    case 1:
        func_003cbc60(func_00457190(), *(u8 **)(temp_16 + 0x44));
        temp_19 = *(u8 **)(temp_16 + 0x44);
        if (temp_19 != NULL) {
            temp_18 = *(s32 *)(temp_19 + 4);
            if (temp_18 != 0) {
                func_003efd20(temp_19, 0);
                func_003e9390(temp_18);
            }
            temp_4 = *(s32 *)(temp_19 + 0x64);
            if (temp_4 != 0) {
                *(s32 *)(temp_19 + 0x64) = 0;
                func_003ec330(temp_4);
            }
            if (*(s32 *)(temp_19 + 0x60) != 0)
                *(s32 *)(temp_19 + 0x60) = 0;
            func_003e8440(temp_19);
        }
        func_0040fcd0(*(s32 *)(temp_16 + 0x40), 0);
        func_003ec330(*(s32 *)(temp_16 + 0x40));
        func_003ef080(*(u8 **)(temp_16 + 0x3C), 0);
        func_003ef3a0(*(u8 **)(temp_16 + 0x3C));
        temp_4_2 = *(u8 **)(temp_16 + 0x4C);
        if (temp_4_2 != NULL)
            jtbl_008873EC[0](temp_4_2);
    case 4:
    case 3:
        break;
    }
    if (*(u8 **)(temp_16 + 0x50) != NULL) {
        if (*(s32 *)(*(u8 **)(temp_16 + 0x50) + 8) != 0)
            func_003c4220(*(s32 *)(*(u8 **)(temp_16 + 0x50) + 8));
        if (*(u8 **)(*(u8 **)(temp_16 + 0x50) + 4) != NULL) {
            func_003e9390(*(s32 *)(*(u8 **)(*(u8 **)(temp_16 + 0x50) + 4) + 4));
            func_003c02e0(*(u8 **)(*(u8 **)(temp_16 + 0x50) + 4));
        }
        jtbl_008873EC[0](*(u8 **)(temp_16 + 0x50));
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0017B510
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b510);

// FUN_0017B990
void func_0017b990(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b9a0);

// FUN_0017BB50
void func_0017bb50(u8 *arg0, u8 *arg1)
{
    *(s32 *)(arg1 + 0x3C) = func_004571b0()[2];
    func_004571b0()[2] = 0;
    func_004571b0();
    *(s32 *)(arg1 + 0x38) = func_004571c0()[2];
    func_004571c0()[2] = 0;
    func_004571c0();
    *(s32 *)(arg1 + 0x34) = func_004571a0()[2];
    func_004571a0()[2] = 0;
    func_004571a0();
}



// FUN_0017BBE0
void func_0017bbe0(u8 *arg0, u8 *arg1)
{
    u8 temp_16;

    temp_16 = arg1[0x3C];
    func_004571b0()[2] = temp_16;
    func_004571b0();
    temp_16 = arg1[0x38];
    func_004571c0()[2] = temp_16;
    func_004571c0();
    temp_16 = arg1[0x34];
    func_004571a0()[2] = temp_16;
    func_004571a0();
}

// FUN_0017BC60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017bc60);

// FUN_0017C010
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c010);

// FUN_0017C270
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c270);

// FUN_0017C670
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c670);




// FUN_0017C930
s32 func_0017c930(u8 *arg0)
{
    extern u8 *func_001452b0(s32);
    extern s32 func_0014a160(void);
    extern s32 func_001623f0(void);
    extern u8 *func_00460990(void);
    extern void func_00460a80(void *, s32);
    extern void func_00460ac0(void *, void *);
    extern void func_004623a0(void *);
    extern void func_00479100(void *, void *);
    extern void func_0017bb50(u8 *, u8 *);
    extern void func_0017bbe0(u8 *);
    extern void func_0017bc60(u8 *, u8 *);
    extern void func_0017c010(u8 *);
    extern void func_0017c270(u8 *, u8 *);
    extern void func_0017c670(u8 *);
    u8 *list1;
    u8 *list3;
    u8 *state;
    s32 state_value;
    s32 i;
    u8 *work;
    u8 *p;

    state = *(u8 **)(arg0 + 0x38);
    list1 = func_001452b0(1);
    list3 = func_001452b0(3);
    state_value = *(s32 *)state;
    switch (state_value) {
    case 0:
        *(s32 *)state = state_value + 1;
        break;
    case 1: {
        func_00460a80(state + 4, 1);
        work = func_00460990();
        *(void **)(work + 8) = (void *)func_0017bb50;
        *(u8 **)(work + 0x10) = state;
        func_00460ac0(state + 4, work);
        while (list1 != NULL) {
            if ((*(s32 *)(list1 + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(list1 + 0x224) + 0x38) + 0xA) == 1) {
                work = func_00460990();
                *(void **)(work + 8) = (void *)func_0017bc60;
                *(u8 **)(work + 0x10) = list1;
                func_00460ac0(state + 4, work);
                if (*(s32 *)(*(u8 **)(*(u8 **)(list1 + 0x224) + 0x38)) > 0) {
                    if (func_0014a160() == 1 || func_001623f0() == 1) {
                        i = 0;
                        while (i < 5) {
                            p = *(u8 **)(list1 + 0x164) + i * 0xC;
                            *(u8 *)(p + 0x28C) = *(u8 *)(p + 0x28C) & 0xFE;
                            i += 1;
                        }
                    }
                    *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) | 4;
                    func_00479100(state + 4, *(u8 **)(list1 + 0x164));
                    *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) & ~4;
                    if (func_0014a160() == 1 || func_001623f0() == 1) {
                        i = 0;
                        while (i < 5) {
                            p = *(u8 **)(list1 + 0x164) + i * 0xC;
                            *(u8 *)(p + 0x28C) = *(u8 *)(p + 0x28C) | 1;
                            i += 1;
                        }
                    }
                }
                work = func_00460990();
                *(void **)(work + 0xC) = (void *)func_0017c010;
                *(u8 **)(work + 0x14) = list1;
                func_00460ac0(state + 4, work);
            }
            list1 = *(u8 **)(list1 + 0x138);
        }
        while (list3 != NULL) {
            if ((*(s32 *)(list3 + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(list3 + 0x230) + 0x38) + 0xA) == 1) {
                work = func_00460990();
                *(void **)(work + 8) = (void *)func_0017c270;
                *(u8 **)(work + 0x10) = list1;
                func_00460ac0(state + 4, work);
                if (*(s32 *)(*(u8 **)(*(u8 **)(list3 + 0x230) + 0x38)) > 0) {
                    func_00479100(state + 4, *(u8 **)(list3 + 0x164));
                }
                work = func_00460990();
                *(void **)(work + 0xC) = (void *)func_0017c670;
                *(u8 **)(work + 0x14) = list1;
                func_00460ac0(state + 4, work);
            }
            list3 = *(u8 **)(list3 + 0x138);
        }
        work = func_00460990();
        *(void **)(work + 0xC) = (void *)func_0017bbe0;
        *(u8 **)(work + 0x14) = state;
        func_00460ac0(state + 4, work);
        func_004623a0(state + 4);
        break;
    }
    case 2:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_0017CC90
void func_0017cc90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0017CCC0
s32 func_0017ccc0(u8 *arg0) {
    u8 *buf;

    func_0044ea90(D_005F18C0, 0x8E5);
    buf = D_008873F4[0](1, 0x40, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    return func_00451fc0(arg0, D_005F1910, 8, 0, 0, (void (*)(u8 *))func_0017c930, func_0017cc90, buf);
}


// FUN_0017CD60 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017cd60);
// FUN_0017D060
void func_0017d060(u8 *arg0)
{
}
// FUN_0017D070
void func_0017d070(u8 *arg0)
{
    func_0043f9c8(D_007F1740, 0, 0x20);
    func_00451fc0(arg0, D_005F1950, 0x12, 0, 0, (void (*)(u8 *))func_0017cd60, func_0017d060, D_007F1740);
}
// FUN_0017D0F0
void func_0017d0f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017D100
void func_0017d100(u8 *arg0)
{
    F2_0017 sp30;
    f32 temp_f1;
    s32 temp_17;
    s32 temp_4;
    s32 var_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = (s32)(func_00457120() + 0x20);
    func_003e42a0(&sp30, func_0047a2f0(*(u8 **)D_007EFA00) + 0x30, (u8 *)temp_17);
    temp_f1 = 640.0f * (sp30.first / sp30.second);
    if (temp_f1 <= 100.0f) {
        var_3 = 0;
    } else if (temp_f1 < 540.0f) {
        var_3 = 1;
    } else {
        var_3 = 2;
    }
    temp_4 = var_3 * 8;
    *(s16 *)(temp_16 + 0xC) = *(s32 *)((u8 *)D_005F1930 + temp_4);
    *(s16 *)(temp_16 + 0xE) = *(s32 *)((u8 *)D_005F1934 + temp_4);
}
// FUN_0017D1F0
void func_0017d1f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   f32 arg5, f32 arg6, f32 arg7)
{
    s32 temp_3;

    temp_3 = arg2 * 8;
    func_0017d240(arg0, arg1, arg2, arg3,
                  *(s32 *)(D_005F1A60 + temp_3) + 1,
                  *(s32 *)(D_005F1A64 + temp_3) + 1, arg4,
                  arg5, arg6, arg7);
}
/* measured: optimization_level 1 is required for func_0017d240 codegen. */
#pragma optimization_level 1
// FUN_0017D240
void func_0017d240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9)
{
    struct {
        u8 data[0x10];
        u8 tail[0x10];
    } spA0;
    s32 local_0;
    u32 local_1;
    s32 local_2;
    s32 local_6;
    s32 local_5;
    s32 local_4;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21 = (f32)arg4;
    f32 temp_f20 = (f32)arg5;
    f32 *temp_9;
    s32 temp_2;
    s32 temp_1;
    s32 temp_18;
    local_0 = arg0;
    local_1 = arg1;
    local_2 = arg2;
    temp_f24 = arg7;
    temp_f23 = arg8;
    temp_f22 = arg9;
    local_6 = arg4;
    local_5 = arg5;
    local_4 = arg6;
    if (arg3 == 0) {
        func_00442088(spA0.data, D_005F1AE0);
    } else {
        func_00442088(spA0.data, D_005F1B00);
    }
    temp_18 = local_2 * 0x10;
    temp_f21 = (f32)local_6;
    temp_f20 = (f32)local_5;
    temp_1 = func_003ef6d0();
    temp_2 = func_003ef650(temp_1, spA0.data);
    func_0014def0(local_0, local_1,
                  temp_f24, temp_f23, temp_f22, temp_f21, temp_f20,
                  (void *)&iGpffff9f54, temp_2,
                  *(f32 *)(temp_9 = (f32 *)(D_005F1970 + temp_18)),
                  *(f32 *)(D_005F1974 + temp_18),
                  *(f32 *)(D_005F1978 + temp_18),
                  local_4, temp_9,
                  *(f32 *)(D_005F197C + temp_18));
}
/* measured: restore optimization_level 2 after func_0017d240. */
#pragma optimization_level 2
