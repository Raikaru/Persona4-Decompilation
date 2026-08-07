#include "include_asm.h"
#include "type.h"
extern void func_0034c4a0();

extern void (*jtbl_008873EC[])(void *);

void func_0034bea0();
void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern s32 D_00882FC0[];
extern s32 D_00882FC4[];
extern s32 D_00884670[];
extern s32 D_00884684[];
extern u16 iGpffffb5a4;

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

void func_0034f320(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, s16 arg5,
                   s16 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0);

void func_0034f4a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   s64 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8);



// FUN_00349380
void func_00349380(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0034A630
s32 func_0034a630(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// FUN_0034A840
void func_0034a840(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s32 *)(temp_16 + 0xE4) = 0;
    *(s32 *)(temp_16 + 0xE0) = 0;
    func_003e8130(func_00457120(), temp_16 + 0xE0);
}

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

// FUN_0034F2E0
void func_0034f2e0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s64 arg4, f32 fparg0,
                   f32 fparg1) {
    func_0034f320(arg0, arg1, arg2, arg3, arg4, 0x1000, 0x1000, 0, fparg0,
                  fparg1, 0.0f, 0.0f, 0);
}



// FUN_0034F460
void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s64 arg5,
                   f32 fparg0, f32 fparg1) {
    func_0034f4a0(arg0, arg1, arg2, arg3, arg4, arg5, 0x1000, 0x1000, fparg0,
                  fparg1, 0.0f, 0.0f, 0, 0);
}
