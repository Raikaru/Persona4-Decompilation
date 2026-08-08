#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

void func_00483810();

extern u8 D_00713480[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];

extern char D_00713CE0[];


extern void (*jtbl_008873EC[])();

// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_00484510
void func_00484510(void)
{
}

// FUN_00484520
void func_00484520(void)
{
}

// FUN_00484530
s32 func_00484530(void)
{
    return 0;
}

// FUN_00484540
void func_00484540(void)
{
}

// FUN_00484550
void func_00484550(void)
{
}

// FUN_00484560
s32 func_00484560(void)
{
    return 1;
}

// FUN_00484790
void func_00484790(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        *(u8 **)(arg0 + 0x18) = NULL;
    }
}

// FUN_004847E0
void func_004847e0(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u8 **)(arg0 + 0x28) = NULL;
    }
}

// FUN_00484970
void func_00484970(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_0071349C + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_00484A40
void func_00484a40(u8 *arg0, void *arg1) {
    void (*fn)(s32, void *) = *(void (**)(s32, void *))(D_007134A0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

// FUN_00484A90
void func_00484a90(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_007134A8 + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_00484AE0
void func_00484ae0(u8 *arg0, s32 arg1) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

/* measured: retail uses VU0 zero stores, then a D_00713CE0 lq/sq aggregate copy and scalar tail stores. The C reconstruction with propagation off reproduces the 128-byte object except temporary-register colours at the 0x2C scalar and quad copy (normalized_diff 6); direct and struct aggregate spellings, declaration orders, signatures, optimizer, schedule, and branch pragmas were probed. Committed at nd 6. */
// FUN_00484B30 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe */
#pragma opt_propagation off
void func_00484b30(u8 *arg0)
{
    u_long128 quad;
    u_long128 *quadSrc;
    func_0043f9c8(arg0, 0, 0x80);
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(arg0) : "memory");
    *(s32 *)(arg0 + 0x44) = 0x40A00000;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(arg0) : "memory");
    quadSrc = (u_long128 *)D_00713CE0;
    quad = *quadSrc;
    *(u_long128 *)(arg0 + 0x20) = quad;
    *(s32 *)(arg0 + 0x60) = 0x3F800000;
    *(s32 *)(arg0 + 0x74) = 0x3F800000;
    *(s32 *)(arg0 + 0x64) = -1;
    *(s32 *)(arg0 + 0x68) = 0x80;
}
/* measured: probe */
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484b30);
#endif

// FUN_00485FE0
void func_00485fe0(u8 *arg0) {
    u8 *n = *(u8 **)(arg0 + 0x8C);
    u8 *o;
    void (*fn)(s32);

    while (n != NULL) {
        o = *(u8 **)(n + 0x90);
        fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(o + 4) << 6) + 0x1C);
        if (fn != NULL) {
            fn(*(s32 *)(o + 8));
        }
        n = *(u8 **)(n + 0xAC);
    }
    *(s32 *)(arg0 + 0x84) = 0;
}

// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}
