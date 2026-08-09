#include "include_asm.h"
#include "type.h"
extern s32 func_00246480(void);
extern f32 func_00245030(s32 arg0, s32 arg1);
extern void func_00246450(s32 arg0);
extern void func_0044ea90(void *file, s32 line);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern void func_00452080(s32 arg0);
extern s32 func_00452380(void *path);
extern void func_0046d730(void *file, s32 line);
extern u8 D_006359B0[];
extern u8 D_006359C0[];
extern s32 func_001075d0(s32 arg0);
extern s32 func_001077f0(s32 arg0);
extern s32 func_00108e10(void);
extern s32 func_00107ac0(s32 arg0);
extern s32 func_00108950(s32 arg0);
extern s32 func_0029cc00(s32 arg0);
extern void func_0029cf50(s32 arg0);
extern s32 func_001087e0(s32 arg0);
extern s32 func_00107c80(s32 arg0);
extern s32 func_00107ce0(s32 arg0);
extern s32 func_00107dc0(s32 arg0);
extern s32 func_00107ea0(s32 arg0);
extern s32 func_00107f00(s32 arg0);
extern s32 func_00107fe0(s32 arg0);
extern s32 func_00108290(s32 arg0, s32 arg1);
extern s32 func_00108590(s32 arg0, s32 arg1, s32 arg2);
extern s64 func_001060b0(void);
extern s32 func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);
extern s32 func_002480e0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00248040(s32 arg0);
extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern s32 func_00108ed0(s32 arg0);
extern s32 func_00108ee0(void);
extern s32 func_00247f60(s32 arg0);

extern void func_00243ed0(void);
extern f32 D_00761260;
extern f32 fGpffff811c;
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

// FUN_00244110
INCLUDE_ASM("asm/nonmatchings/code1_0024", func_00244110);
// FUN_00244540
INCLUDE_ASM("asm/nonmatchings/code1_0024", func_00244540);
// FUN_002447C0
void func_002447c0(void)
{
    f32 temp_f20;
    f32 temp_f21;

    if (func_00246480() != 0) {
        temp_f20 = func_00245030(0x13, 0);
        temp_f20 += func_00245030(0x1A, 0);
    } else {
        temp_f21 = func_00245030(0x1A, 0);
        temp_f20 = D_00761260 * temp_f21 + func_00245030(0x13, 0);
    }
    func_00246450((s32)temp_f20);
}
// FUN_00244870
INCLUDE_ASM("asm/nonmatchings/code1_0024", func_00244870);
// FUN_002449C0
void func_002449c0(void)
{
    f32 temp_f20;
    f32 temp_f0;

    if (func_00246480() != 0) {
        temp_f20 = (50.0f + func_00245030(0xD, 4)) /
                   (50.0f + func_00245030(0xE, 4));
        temp_f0 = func_00245030(0x14, 0);
        temp_f0 *= temp_f20;
    } else {
        temp_f20 = (50.0f + func_00245030(0xD, 4)) /
                   (50.0f + func_00245030(0xE, 4));
        temp_f0 = fGpffff811c * mul_f32_ordered(func_00245030(0x14, 0), temp_f20);
    }
    func_00246450((s32)temp_f0);
}
// FUN_00244AD0
void func_00244ad0(void)
{
    func_00246480();
    func_00246450(func_00245030(0x15, 0));
}
// FUN_00244B10
void func_00244b10(void)
{
    f32 temp_f21;
    f32 temp_f20;

    temp_f20 = 100.0f + func_00245030(0xD, 3);
    temp_f21 = temp_f20 / (100.0f + func_00245030(0xE, 3));
    temp_f20 = 100.0f + func_00245030(0xD, 4);
    temp_f20 = 75.0f * (temp_f21 * (temp_f20 / (100.0f + func_00245030(0xE, 4))));
    temp_f20 += 5.0f * func_00245030(0x22, 0);
    func_00246450((s32)temp_f20);
}
// FUN_00244C10
void func_00244c10(void)
{
    f32 temp_f20;

    temp_f20 = 3.0f * (func_00245030(1, 0) - 1.0f) + 2.0f;
    temp_f20 *= func_00245030(0x10, 0);
    if (temp_f20 > 0.0f) {
        temp_f20 = 50.0f * (func_00245030(0xD, 4) / temp_f20);
    } else {
        temp_f20 = 1.0f;
    }
    func_00246450((s32)temp_f20);
}
// FUN_00244CF0
INCLUDE_ASM("asm/nonmatchings/code1_0024", func_00244cf0);
// FUN_00244E20
INCLUDE_ASM("asm/nonmatchings/code1_0024", func_00244e20);
// FUN_00246550
s32 func_00246550(void)
{
    func_00243ed0();
    return 1;
}
// FUN_00246580
s32 func_00246580(void)
{
    return 0;
}
// FUN_00246590
void func_00246590(void)
{
}
// FUN_002465A0
void func_002465a0(void)
{
    func_0044ea90(D_00635990, 0xD1);
    func_00451de0(D_006359A0, 0xF, 0, 0, (void *)func_00246580,
                  (void *)func_00246590, D_008873F4[0](1, 8, 0x40000));
}
// FUN_00246620
void func_00246620(void)
{
    func_002465a0();
}
// FUN_00246640
s32 func_00246640(void)
{
    return func_00452380(D_006359B0) != 0;
}
// FUN_00246670
void func_00246670(void)
{
    s32 temp_2;

    temp_2 = func_00452380(D_006359B0);
    if (temp_2 == 0) {
        func_0046d730(D_006359C0, 0x3D);
    }
    func_00452080(temp_2);
}
// FUN_002466D0
void func_002466d0(void)
{
}
// FUN_002466E0
void func_002466e0(void)
{
}
// FUN_002466F0
void func_002466f0(void)
{
}
/* measured: optimization_level 1 preserves the saved task id across the guard. */
#pragma optimization_level 1
// FUN_00249B10
s32 func_00249b10(void)
{
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    if (temp_16 == 0) {
        temp_16 = func_00108e10() & 0xFFFF;
    }
    if (func_001077f0(temp_16 & 0xFFFF) == 0) {
        func_001075d0(temp_16 & 0xFFFF);
    }
    return 1;
}
/* measured: closes optimization_level 1 around func_00249b10. */
#pragma optimization_level 2
// FUN_00249B80
s32 func_00249b80(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    func_0029cf50(func_001077f0(var_2 & 0xFFFF));
    return 1;
}
// FUN_00249BE0
s32 func_00249be0(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    func_0029cf50(func_00107ac0(var_2 & 0xFFFF) & 0xFFFF);
    return 1;
}
// FUN_00249C40
s32 func_00249c40(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    func_00108950(var_2 & 0xFFFF);
    return 1;
}
// FUN_00249C90
s32 func_00249c90(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    if (func_001087e0(var_2 & 0xFFFF) != 0) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}
// FUN_00249D00
s32 func_00249d00(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    if (var_17 == 0) {
        var_17 = func_00108e10() & 0xFFFF;
    }
    func_00108290(var_17 & 0xFFFF, temp_16 & 0xFFFF);
    return 1;
}
// FUN_00249D70
s32 func_00249d70(void)
{
    s32 temp_16;
    s32 temp_17;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00108590(temp_17 & 0xFFFF, temp_16 & 0xFFFF, func_0029cc00(2));
    return 1;
}
// FUN_00249DE0
s32 func_00249de0(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    if (func_00107c80(var_2 & 0xFFFF) != 0) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}
// FUN_00249E50
s32 func_00249e50(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    if (var_17 == 0) {
        var_17 = func_00108e10() & 0xFFFF;
    }
    if (temp_16 != 0) {
        func_00107ce0(var_17 & 0xFFFF);
    } else {
        func_00107dc0(var_17 & 0xFFFF);
    }
    return 1;
}
// FUN_00249EE0
s32 func_00249ee0(void)
{
    s32 var_2;

    var_2 = func_0029cc00(0);
    if (var_2 == 0) {
        var_2 = func_00108e10() & 0xFFFF;
    }
    if (func_00107ea0(var_2 & 0xFFFF) != 0) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}
// FUN_00249F50
s32 func_00249f50(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    if (var_17 == 0) {
        var_17 = func_00108e10() & 0xFFFF;
    }
    if (temp_16 != 0) {
        func_00107f00(var_17 & 0xFFFF);
    } else {
        func_00107fe0(var_17 & 0xFFFF);
    }
    return 1;
}
// FUN_00249FE0
s32 func_00249fe0(void)
{
    s32 sp2C;
    s32 sp28;
    s32 temp_16;
    temp_16 = func_0029cc00(0);
    func_001104d0((s16)func_001060b0(), &sp2C, &sp28);
    func_0029cf50(func_002480e0(temp_16, sp2C, sp28));
    return 1;
}
// FUN_0024A060
s32 func_0024a060(void)
{
    s32 var_4;

    var_4 = func_0029cc00(0) & 0xFFFF;
    if (var_4 == 0) {
        var_4 = func_00108e10() & 0xFFFF;
    }
    func_00108ed0(var_4);
    return 1;
}
// FUN_0024A0E0
s32 func_0024a0e0(void)
{
    s32 var_4;

    var_4 = (func_00108ee0() & 0xFFFF) != 0;
    if (var_4 != 0) {
        var_4 = func_00247f60((s16)func_001060b0()) != 0;
    }
    func_0029cf50(var_4);
    return 1;
}
// FUN_0024A140
s32 func_0024a140(void)
{
    s32 temp_17;
    s32 var_16;
    temp_17 = func_00248040((s16)func_001060b0());
    var_16 = 0;
    if (temp_17 == ((s16)func_001060b0() + 1)) {
        var_16 = 1;
    } else if (func_00110580(temp_17) == 0) {
        var_16 = 2;
    } else if (func_00110d30(temp_17) != 0) {
        var_16 = 3;
    }
    func_0029cf50(var_16);
    return 1;
}