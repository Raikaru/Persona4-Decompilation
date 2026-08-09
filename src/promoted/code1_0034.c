#include "include_asm.h"
#include "type.h"
extern void func_0034c4a0();
extern void (*D_00887300[])(s32, s32);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_0046b380(u8 *arg0, s32 arg1);
extern void func_0046d730(const void *file, s32 line);
extern char D_0064B310[];

extern void (*jtbl_008873EC[])(void *);

void func_0034bea0();
void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern s32 D_00882FC0[];
extern s32 D_00882FC4[];
extern s32 D_00884670[];
extern s32 D_00884684[];
extern u16 iGpffffb5a4;
extern u8 *func_0046d200(s32 arg0, s32 arg1);
extern void func_0046d280(u8 *arg0);

// struct passed by value to func_0034b820 (64-bit: two floats in $a1-$a2)
typedef struct {
    f32 x;
    f32 y;
} Svec2f_0034b820;

// struct passed by value to func_0034b820 (32-bit: four bytes in $a3)
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} S4b_0034b820;

void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   s8 arg1, s8 arg2, s8 arg3, s64 arg4, s64 arg5,
                   s32 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);

void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   s8 arg2, s8 arg3, s8 arg4, s64 arg5, s64 arg6, s32 arg7,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8);




// FUN_00349340
s32 func_00349340(void)
{
    s8 buf[0xC];
    s8 *p;
    s32 count;

    p = buf;
    count = 0xC;
    if (p != NULL)
    {
        do
        {
            *p = 0;
            p += 1;
            count -= 1;
        } while (count != 0);
    }
    return 0;
}
// FUN_00349380
void func_00349380(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0034A630
s32 func_0034a630(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// FUN_0034A640
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034a640);
// FUN_0034A820
void func_0034a820(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 4) = 0;
    *(u8 *)(p + 5) = 1;
}
// FUN_0034A840
void func_0034a840(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s32 *)(temp_16 + 0xE4) = 0;
    *(s32 *)(temp_16 + 0xE0) = 0;
    func_003e8130(func_00457120(), temp_16 + 0xE0);
}

// FUN_0034A890
void func_0034a890(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 6) = 1;
}
// FUN_0034A8B0
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034a8b0);
// FUN_0034AC00
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034ac00);
// FUN_0034AD40
void func_0034ad40(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0034B810
s32 func_0034b810(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// FUN_0034B820
void func_0034b820(u8 *arg0, Svec2f_0034b820 v, s16 s, S4b_0034b820 b, f32 fparg0)
{
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(Svec2f_0034b820 *)(obj + 0xE38) = v;
    *(f32 *)(obj + 0xE14) = fparg0;
    *(s16 *)(obj + 0x0) = s;
    *(u8 *)(obj + 0xE6E) = b.b3;
    *(u8 *)(obj + 0xE85) = b.b0;
    *(u8 *)(obj + 0xE86) = b.b1;
    *(u8 *)(obj + 0xE87) = b.b2;
    *(s16 *)(obj + 0xE10) |= 1;
}

// FUN_0034B880
void func_0034b880(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 0xE6C) = arg1;
    *(u8 *)(p + 0xE6D) = arg2;
    *(u8 *)(p + 0xE6E) = arg1;
    *(s16 *)(p + 0xE6A) = 0;
    *(s16 *)(p + 0xE68) = arg4;
    *(s16 *)(p + 0xE70) = arg5;
    *(u8 *)(p + 0xE72) = arg3;
    *(s16 *)(p + 0xE10) |= 4;
}
// FUN_0034B8C0
void func_0034b8c0(void)
{
}

// FUN_0034B8D0
s32 func_0034b8d0(void)
{
    if ((D_00884684[0] != 0) && (D_00884670[0] != 0)) {
        func_0034bea0();
        D_00882FC0[0] = 0;
        D_00882FC4[0] = 0;
        func_00460ac0(D_00793E80 + iGpffffb5a4 * 0x30, (u8 *)D_00882FC0);
    }
    return 0;
}

// FUN_0034B950
void func_0034b950(void)
{
    func_0034c4a0();
}

/* measured: opt_propagation off caches the D_00887300 base in $s0. */
// FUN_0034EDC0
#pragma opt_propagation off
void func_0034edc0(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](7, 2);
    base[0](6, 0);
    base[0](8, 0);
    base[0](1, 0);
    base[0](0xE, 0);
    base[0](0xA, 5);
    base[0](0xB, 7);
    base[0](0xC, 1);
}
/* measured: close opt_propagation bracket for func_0034edc0. */
#pragma opt_propagation on
// FUN_0034EE90
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034ee90);
// FUN_0034F0D0
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034f0d0);
// FUN_0034F1E0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
#pragma opt_propagation off
void func_0034f1e0(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 0);
    base[0](7, 2);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](0xB, 6);
    base[0](0xA, 5);
    base[0](2, 4);
    base[0](0xE, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
/* measured: closing opt_propagation bracket for func_0034f1e0. */
#pragma opt_propagation on
// FUN_0034F2E0
void func_0034f2e0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, f32 fparg0,
                   f32 fparg1) {
    func_0034f320(arg0, fparg0, fparg1, 0.0f, arg1, arg2, arg3, arg4,
                  0x1000, 0x1000, 0, 0.0f, 0);
}



// FUN_0034F320
void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   s8 arg1, s8 arg2, s8 arg3, s64 arg4, s64 arg5,
                   s32 arg6, s16 arg7, f32 fparg3, s16 arg_sp0)
{
    u8 temp;

    if (arg0 == NULL)
        func_0046d730(D_0064B310, 0x6C);
    temp = arg4 & 0xFF;
    if ((temp == 0) || ((arg5 & 0xFFFF) == 0) ||
        ((arg6 & 0xFFFF) == 0))
        return;
    *(f32 *)(arg0 + 8) = fparg0;
    *(f32 *)(arg0 + 0xC) = fparg1;
    *(s8 *)(arg0 + 0x28) = arg1;
    *(s8 *)(arg0 + 0x29) = arg2;
    *(s8 *)(arg0 + 0x2A) = arg3;
    *(s8 *)(arg0 + 0x10) = 0;
    *(s8 *)(arg0 + 0x11) = 0xFF - temp;
    *(f32 *)(arg0 + 0x24) = fparg2;
    *(s16 *)(arg0 + 0x20) = arg5;
    *(s16 *)(arg0 + 0x22) = arg6;
    *(s16 *)(arg0 + 0x1C) = arg7;
    *(s16 *)(arg0 + 0x1E) = arg_sp0;
    *(f32 *)(arg0 + 0x18) = fparg3;
    func_0046b380(arg0, 0);
}
// FUN_0034F460
void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   f32 fparg0, f32 fparg1) {
    func_0034f4a0(arg0, arg1, fparg0, fparg1, 0.0f, arg2, arg3, arg4, arg5,
                  0x1000, 0x1000, 0.0f, 0, 0);
}

// FUN_0034F4A0
void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   s8 arg2, s8 arg3, s8 arg4, s64 arg5, s64 arg6, s32 arg7,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8)
{
    u8 *temp_2;

    if (arg0 == 0)
        func_0046d730(D_0064B310, 0x94);
    temp_2 = func_0046d200(arg0, arg1);
    func_0034f320(temp_2, fparg0, fparg1, fparg2, arg2, arg3, arg4,
                  arg5, arg6, arg7, arg_sp0, fparg3, arg_sp8);
    func_0046d280(temp_2);
}
// FUN_0034F5D0
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034f5d0);
// FUN_0034F720
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034f720);
// FUN_0034F8F0
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034f8f0);
// FUN_0034F9D0
INCLUDE_ASM("asm/nonmatchings/code1_0034", func_0034f9d0);