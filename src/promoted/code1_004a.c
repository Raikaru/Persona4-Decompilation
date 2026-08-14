#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern void func_004a5fc0(u8 *arg0);
extern u8 *func_004a6c00(u8 *arg0);
extern u8 *func_004a5630(u16 arg0, u8 *arg1);
extern u8 D_0071413C[];
extern void func_00492dd0();
extern void func_00492e10();
extern void func_00492e30();
extern s32 func_004814d0(u16 arg0);
extern void func_004ad030();
extern void func_004adb50();
extern void func_004ade80(u8 *arg0);
extern void func_00460ac0();
extern void func_004aec80();
extern void func_004787e0();

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern s32 D_00724C78;
extern s32 D_00724C7C;
extern u8 D_00714350[];
extern void func_0046d730(u8 *arg0, s32 arg1);
extern s32 func_003e9320(void);
extern u8 *func_00457120(void);
extern void func_003e9830(s32 arg0, s32 arg1);
extern f32 D_00922D80[];
extern u8 *func_00401b80(void);
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);

extern void func_004a7c00(u8 *arg0, s32 arg1);

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);

extern void func_0044ea90(const void *msg, s32 id);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_003f6690(s32 param, void *out);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u8 D_00714368[];
extern void func_0048a070(s64 arg);
extern void func_0048a0e0(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern u8 *func_00484490();
extern f32 D_008872F8[];
 
extern void func_0045f0b0(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void func_0045fa00(f32 *arg0, s32 arg1, f32 arg2);
extern s32 func_0047a510(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00485870(s32 arg0);
extern f32 func_004bd0b0(u32 arg0);
extern u32 func_004bd050(u32 arg0);
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_003c22f0(u8 *arg0, u8 *arg1);
extern u16 *func_00483c40(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern void func_003c2290(void *arg0, s32 arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern u8 *func_00482f70(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern void func_004a5ef0(u8 *arg0, u8 *arg1);
extern u8 *func_00483270(s32 arg0);
extern s32 func_00481300(u16 arg0);
extern s32 func_00481d80(u16 *arg0);
extern s32 func_00482800(u16 *arg0);
extern void func_00483970(u8 *arg0, u16 *arg1);
extern u16 *func_004844d0(u8 *arg0);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void func_004829c0(s32 arg0);
extern s32 func_00482a70(s32 arg0);
extern void func_0047a2a0(void *arg0);
extern s32 func_00479ca0(void *arg0, s32 arg1);
extern void func_00479940(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478eb0(void *arg0, void (*arg1)(void), void *arg2);
extern void func_004abe60(void);
extern u8 D_0071401C[];
extern u8 D_00714014[];


extern u8 *func_004a1660(u16 arg0, s32 arg1);

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern s32 func_00477c40(s32 arg0, u16 arg1, s32 arg2);
extern u8 *func_00477f10(s32 arg0, u16 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_00485fe0(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(u8 *arg0);




// FUN_004A18E0
void func_004a18e0(u8 *arg0) {
    (*(void (**)(u8 *))(D_00714018 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(*(u8 **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
// FUN_004A1950
u8 *func_004a1950(u8 *arg0) {
    s32 index;
    s32 stride;
    u8 *result;
    s32 temp;

    index = *(s32 *)(arg0 + 0x38);
    if (*(s32 *)(D_0071401C + (index * 0x1C)) == 0) {
        temp = *(s32 *)(arg0 + 0x40);
        index = (u16)index;
        result = func_004a1660((u16)index, temp);
        stride = (u16)index * 0x1C;
        *(s32 *)(result + 0x3C) =
            (*(s32 (**)(s32, s32))(D_00714014 + stride))(temp, 0);
        (*(void (**)(u8 *))(D_00714010 + stride))(result);
    } else {
        result = func_004a1660((u16)index, *(s32 *)(arg0 + 0x40));
        *(s32 *)(result + 0x3C) =
            (*(s32 (**)(u8 *))(D_0071401C + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
        (*(void (**)(u8 *))(D_00714010 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(result);
    }
    return result;
}
// FUN_004A1AA0
void func_004a1aa0(u8 *arg0) {
    (*(void (**)(void))(D_00714010 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}
// FUN_004A1AF0
void func_004a1af0(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
}
// FUN_004A1B50
void func_004a1b50(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}
// FUN_004A1BA0
void func_004a1ba0(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(u8 *))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}
// FUN_004A1C30
u_long128 func_004a1c30(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A1C40
u_long128 func_004a1c40(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A1C50
void func_004a1c50(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}
// FUN_004A1C60
void func_004a1c60(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}
// FUN_004A1C80
void func_004a1c80(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}
/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
#pragma opt_loop_invariants on
// FUN_004A1CA0
void func_004a1ca0(u8 *arg0)
{
    u8 *p5;
    u8 *p7;
    u32 count;
    u32 i;
    u8 *p11;
    u8 *p13;

    p5 = *(u8 **)(arg0 + 0x3C);
    p7 = *(u8 **)p5;
    count = *(u32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    i = 0;
    while (i < count) {
        p11 = *(u8 **)(p5 + 4);
        if (iGpffffbb64.c3 != 0xFF) {
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)p7 = -1;
        i++;
        p7 += 0x30;
    }
}
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
#pragma opt_loop_invariants off
// FUN_004A1D70 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a1d70);
// FUN_004A22C0
void func_004a22c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A35F0
void func_004a35f0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A49C0
void func_004a49c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A58B0
void func_004a58b0(u8 *arg0)
{
    (*(void (**)(u8 *))(D_00714138 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    jtbl_008873EC[0](arg0);
}

// FUN_004A5910
u8 *func_004a5910(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = func_004a5630(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
    *(s32 *)(temp_16 + 0x3C) =
        (*(s32 (**)(u8 *))(D_0071413C + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    (*(void (**)(u8 *))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(temp_16);
    return temp_16;
}
// FUN_004A59B0
void func_004a59b0(u8 *arg0)
{
    (*(void (**)(void))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}

// FUN_004A5A00
void func_004a5a00(u8 *arg0)
{
    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}

// FUN_004A5A60
void func_004a5a60(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}

// FUN_004A5AB0
void func_004a5ab0(u8 *arg0)
{
    s32 temp_3;

    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    temp_3 = *(s32 *)(arg0 + 0x34) + 1;
    *(s32 *)(arg0 + 0x34) = temp_3;
    if (temp_3 > 0) {
        (*(void (**)(u8 *))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}
// FUN_004A5B40
u_long128 func_004a5b40(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A5B50
u_long128 func_004a5b50(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A5B60
void func_004a5b60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x30) = arg1;
}

/* measured: the jump table must be called through the pointer -- `jtbl_x(a)` is
   an implicit function call to the table SYMBOL, which links and runs wrong. */

// FUN_004A5B70
void func_004a5b70(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}

// FUN_004A5B90
void func_004a5b90(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}

// FUN_004A5BB0
u8 *func_004a5bb0(u8 *arg0)
{
    u16 *temp_2_4;
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_3;

    func_0044ea90(D_007141A0, 0x1C);
    temp_2 = (u8 *)jtbl_008873E8[0](0xD4, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_007141A0, 0x1D);
    }
    func_0043f9c8(temp_2, 0, 0xD4);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(temp_2) : "memory");
    *(s32 *)(temp_2 + 0x24) = -1;
    *(f32 *)(temp_2 + 0x20) = 1.0f;
    if (arg0 == NULL) {
        return temp_2;
    }
    temp_2_2 = func_00482f70(1, 2, 4, D_00713408, 0x4C);
    *(u8 **)(temp_2 + 0xC8) = temp_2_2;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2_2 + 0x10) + 0x18) + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    *(s32 *)(temp_2 + 0x28) = *(u16 *)(arg0 + 0xC);
    temp_2_3 = func_00484490(arg0);
    if (temp_2_3 == NULL) {
        func_0046d730(D_007141A0, 0x47);
    }
    func_0043f810(temp_2 + 0x30, temp_2_3, 0x98);
    temp_2_4 = func_004844d0(arg0);
    if (temp_2_4 != NULL) {
        temp_4 = *(u16 *)(arg0 + 0x1C);
        switch (temp_4) {
        case 1:
            func_00483970(*(u8 **)(temp_2 + 0xC8), temp_2_4);
            break;
        case 2:
            *(s32 *)(temp_2 + 0xD0) = func_00481d80(temp_2_4);
            break;
        case 4:
            func_003c42b0(
                *(u8 **)(*(u8 **)(temp_2 + 0xC8) + 0x14),
                func_00481300(*temp_2_4));
            break;
        case 7:
            *(s32 *)(temp_2 + 0xCC) = func_00482800(temp_2_4);
            break;
        default:
            func_0046d730(D_007141A0, 0x5D);
            break;
        }
    }
    return temp_2;
}

// FUN_004A5DE0
void func_004a5de0(u8 *arg0) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = (s32)(*(s32 *)((u8 *)(arg0) + 0xCC));
    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    temp_4_2 = (s32)(*(s32 *)((u8 *)(arg0) + 0xD0));
    if (temp_4_2 != 0) {
        func_00481ee0(temp_4_2);
    }
    func_004833f0(*(s32 *)((u8 *)(arg0) + 0xC8));
    (*jtbl_008873EC)(arg0);
}

// FUN_004A5E50
u8 *func_004a5e50(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_3;

    temp_16 = func_004a5bb0(NULL);
    temp_2 = func_00483270(*(s32 *)(arg0 + 0xC8));
    *(u8 **)(temp_16 + 0xC8) = temp_2;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x10) + 0x18) + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    func_0043f810(temp_16 + 0x30, arg0 + 0x30, 0x98);
    func_004a5ef0(temp_16, arg0);
    return temp_16;
}
// FUN_004A5EF0
void func_004a5ef0(u8 *arg0, u8 *arg1)
{
    s32 temp_4;
    s32 temp_4_2;

    if (*(s32 *)(arg1 + 0xD0) != 0) {
        temp_4 = *(s32 *)(arg0 + 0xD0);
        if (temp_4 != 0) {
            func_00481ee0(temp_4);
        }
        *(s32 *)(arg0 + 0xD0) = func_00481e30(*(s32 *)(arg1 + 0xD0));
        return;
    }
    if (*(s32 *)(arg1 + 0xCC) != 0) {
        temp_4_2 = *(s32 *)(arg0 + 0xCC);
        if (temp_4_2 != 0) {
            func_004829c0(temp_4_2);
        }
        *(s32 *)(arg0 + 0xCC) = func_00482a70(*(s32 *)(arg1 + 0xCC));
    }
}
// FUN_004A5F90
void func_004a5f90(u8 *arg0)
{
    *(s32 *)(arg0 + 0x2C) = 0;
}

// FUN_004A5FA0
void func_004a5fa0(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
}
// FUN_004A5FC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5fc0);
// FUN_004A6B90
void func_004a6b90(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
    func_004a5fc0(arg0);
}
// FUN_004A6BC0
u_long128 func_004a6bc0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004A6BD0
u_long128 func_004a6bd0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004A6BE0
void func_004a6be0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004A6BF0
void func_004a6bf0(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}
/* measured: testing loop-invariant hoisting for the retail preheader. */
#pragma opt_loop_invariants on
// FUN_004A6C00
u8 *func_004a6c00(u8 *arg0)
{
    u16 *temp_18;
    u16 *temp_2_2;
    u16 *temp_3;
    u32 var_4;
    u8 *temp_17;
    u8 *temp_2;
    u8 *var_5;

    func_0044ea90(D_00714350, 0x78);
    temp_2 = (u8 *)jtbl_008873E8[0](0x5C, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00714350, 0x79);
    }
    func_0043f9c8(temp_2, 0, 0x5C);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2) : "memory");
    func_0043f810(temp_2 + 0x18, arg0, 0x40);
    temp_2_2 = func_00483c40(0xD, 4, 2, 4, D_00713408, 0x4C);
    *(u16 **)(temp_2 + 0x58) = temp_2_2;
    *temp_2_2 = *temp_2_2 & 0xFFFE;
    temp_3 = *(u16 **)(temp_2 + 0x58);
    *temp_3 = *temp_3 & 0xFFFB;
    func_003c2290(
        *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x58) + 0x10) + 0x18), 8);
    var_5 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x58) + 0x10) + 0x18) + 0x30);
    temp_3 = (u16 *)(s32)-1;
    var_4 = 0;
    goto loop_004a6c00_check;
loop_004a6c00_body:
    *(s32 *)(var_5 + 0) = (s32)temp_3;
    *(s32 *)(var_5 + 4) = (s32)temp_3;
    *(s32 *)(var_5 + 8) = (s32)temp_3;
    *(s32 *)(var_5 + 0xC) = (s32)temp_3;
    var_5 += 0x10;
    var_4 += 1;
loop_004a6c00_check:
    if (var_4 < 0x34U) {
        goto loop_004a6c00_body;
    }
    temp_18 = *(u16 **)(temp_2 + 0x58);
    temp_17 = *(u8 **)(*(u8 **)((u8 *)temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17, var_5);
    if ((*temp_18 & 4) != 0) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    return temp_2;
}
/* measured: close loop-invariant hoisting after func_004a6c00. */
#pragma opt_loop_invariants off
// FUN_004A6D90
void func_004a6d90(void) {
    u8 *temp;
    temp = func_00484490();
    func_004a6c00(temp);
}
// FUN_004A6DC0
void func_004a6dc0(u8 *arg0)
{
    func_004841c0(*(s32 *)(arg0 + 0x58));
    jtbl_008873EC[0](arg0);
}

// FUN_004A6E10
void func_004a6e10(u8 *arg0) {
    func_004a6c00(arg0 + 0x18);
}
// FUN_004A6E40
void func_004a6e40(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

// FUN_004A77B0
void func_004a77b0(void) {
    if (D_00724C70 != 0) {
        func_0046d730(D_00714350, 0x1E9);
    }
    D_00724C58 = 0;
    D_00724C5C = 0;
    D_00724C60 = 0;
    D_00724C64 = 0;
    D_00724C78 = 0;
    D_00724C7C = 0;
    D_00724C70 = func_003e9320();
    func_003e9830(D_00724C70, *(s32 *)(func_00457120() + 4));
}

// FUN_004A7830
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7830);
// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}



// FUN_004A7A90
void *func_004a7a90(void)
{
    u8 *src;
    void *dst;

    src = func_00484490();
    func_0044ea90(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    func_0043f810((u8 *)dst + 4, src, 0x10);
    return dst;
}

// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}



// FUN_004A7B70
void *func_004a7b70(void *arg0)
{
    u8 *src;
    void *dst;

    src = (u8 *)arg0;
    func_0044ea90(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    func_0043f810((u8 *)dst + 4, src + 4, 0x10);
    return dst;
}

// FUN_004A7BF0
void func_004a7bf0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x0) = 0;
}

// FUN_004A7C00
void func_004a7c00(u8 *arg0, s32 arg1)
{
    f32 temp_f1;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f3;
    s32 temp_6;
    s32 temp_7;
    s32 temp_3_2;
    u32 temp_4;
    s32 temp_3;

    temp_4 = arg1;
    temp_7 = *(s32 *)(arg0 + 0);
    var_f3 = 1.0f;
    if (temp_7 < (s32)temp_4) {
        if (temp_7 != 0) {
            return;
        }
    }
    if (temp_7 > 0) {
        temp_3 = *(u32 *)(arg0 + 8);
        if ((u32)temp_4 < temp_3) {
            temp_f1 = (f32)(s32)temp_4;
            var_f0 = (f32)(u32)temp_3;
            var_f3 = temp_f1 / var_f0;
        } else {
            temp_6 = *(s32 *)(arg0 + 0xC);
            if ((u32)(temp_7 - temp_6) < (u32)temp_4) {
                if (temp_6 != 0) {
                    temp_3 = temp_7 - (s32)temp_4;
                    temp_f1 = (f32)temp_3;
                    var_f0_2 = (f32)(u32)temp_6;
                    var_f3 = temp_f1 / var_f0_2;
                } else {
                    var_f3 = 0.0f;
                }
            }
        }
    }
    temp_3_2 = *(u16 *)(arg0 + 4);
    var_f0_3 = (f32)(u16)temp_3_2;
    temp_f1 = 10.0f * var_f0_3;
    fGpffffbb74 = temp_f1;
    fGpffffbb70 = (f32)((4.0f * temp_f1) / 10.0f);
    iGpffffb10c = var_f3;
    iGpffffbb68 = 1;
}
// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004A7DE0
void func_004a7de0(void) {
}



// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004A7E30 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7e30);
// FUN_004A8250
/* measured: loop-invariant conversion preloads for func_004a8250. */
#pragma opt_loop_invariants on
void func_004a8250(u8 *arg0, u8 *arg1)
{
    f32 temp_f6;
    f32 temp_f5;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 var_9;
    u8 *temp_8;

    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a8250_check;
loop_004a8250_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a8250_check:
    if (var_9 < 4U) {
        goto loop_004a8250_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    *(s32 *)(arg1 + 0x10) = 0;
    *(s32 *)(arg1 + 0x14) = 0;
    *(s32 *)(arg1 + 0x50) = 0;
    *(s32 *)(arg1 + 0x54) = 0x3F800000;
    *(s32 *)(arg1 + 0x90) = 0x3F800000;
    *(s32 *)(arg1 + 0x94) = 0x3F800000;
    *(s32 *)(arg1 + 0xD0) = 0x3F800000;
    *(s32 *)(arg1 + 0xD4) = 0;
}
/* measured: close loop-invariant conversion scope for func_004a8250. */
#pragma opt_loop_invariants off
// FUN_004A8440
/* measured: loop-invariant conversion preloads for func_004a8440. */
#pragma opt_loop_invariants on
void func_004a8440(u8 *arg0, u8 *arg1)
{
    extern f32 fGpffff8090;
    extern f32 func_0044b7b0(f32 arg0);
    extern f32 func_0044b610(f32 arg0);
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    u32 var_9;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 temp_21;
    u8 *temp_8;

    temp_18 = *(u8 *)(arg0 + 0);
    temp_17 = *(u8 *)(arg0 + 1);
    temp_16 = *(u8 *)(arg0 + 2);
    temp_21 = *(u8 *)(arg0 + 3);
    temp_f22 = fGpffff8090 * *(f32 *)(arg0 + 8);
    temp_f20 = *(f32 *)(arg0 + 0xC);
    temp_f21 = temp_f20 * func_0044b7b0(temp_f22);
    temp_f20 = temp_f20 * func_0044b610(temp_f22);
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a8440_check;
loop_004a8440_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_21;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a8440_check:
    if (var_9 < 4U) {
        goto loop_004a8440_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0x1C);
    temp_f4 = (*(f32 *)(arg0 + 0x18) + temp_f21) / D_00922D94[0];
    temp_f2 = (*(f32 *)(arg0 + 0x1C) + temp_f20) / D_00922D98[0];
    temp_f1 = (*(f32 *)(arg0 + 0x20) + temp_f21) / D_00922D94[0];
    temp_f0 = (*(f32 *)(arg0 + 0x24) + temp_f20) / D_00922D98[0];
    *(f32 *)(arg1 + 0x10) = temp_f4;
    *(f32 *)(arg1 + 0x14) = temp_f2;
    *(f32 *)(arg1 + 0x50) = temp_f4;
    *(f32 *)(arg1 + 0x54) = temp_f0;
    *(f32 *)(arg1 + 0x90) = temp_f1;
    *(f32 *)(arg1 + 0x94) = temp_f0;
    *(f32 *)(arg1 + 0xD0) = temp_f1;
    *(f32 *)(arg1 + 0xD4) = temp_f2;
}
/* measured: close loop-invariant conversion scope for func_004a8440. */
#pragma opt_loop_invariants off
// FUN_004A86C0
/* measured: loop-invariant conversion preloads for func_004a86c0. */
#pragma opt_loop_invariants on
void func_004a86c0(u8 *arg0, u8 *arg1)
{
    f32 temp_f6;
    f32 temp_f5;
    u32 temp_19;
    u32 temp_18;
    u32 temp_17;
    u32 temp_16;
    u32 var_9;
    u8 *temp_8;

    temp_19 = *(u8 *)(arg0 + 0);
    temp_18 = *(u8 *)(arg0 + 1);
    temp_17 = *(u8 *)(arg0 + 2);
    temp_16 = *(u8 *)(arg0 + 3);
    temp_f6 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f5 = D_008872F8[0];
    var_9 = 0;
    goto loop_004a86c0_check;
loop_004a86c0_body:
    temp_8 = arg1 + (var_9 << 6);
    *(f32 *)(temp_8 + 0x18) = temp_f6;
    *(f32 *)(temp_8 + 0x20) = (f32)(u32)temp_19;
    *(f32 *)(temp_8 + 0x24) = (f32)(u32)temp_18;
    *(f32 *)(temp_8 + 0x28) = (f32)(u32)temp_17;
    *(f32 *)(temp_8 + 0x2C) = (f32)(u32)temp_16;
    *(f32 *)(temp_8 + 8) = temp_f5;
    var_9 += 1;
loop_004a86c0_check:
    if (var_9 < 4U) {
        goto loop_004a86c0_body;
    }
    *(f32 *)(arg1 + 0) = *(f32 *)(arg0 + 8);
    *(f32 *)(arg1 + 4) = *(f32 *)(arg0 + 0xC);
    *(f32 *)(arg1 + 0x40) = *(f32 *)(arg0 + 8);
    *(f32 *)(arg1 + 0x44) = *(f32 *)(arg0 + 0x14);
    *(f32 *)(arg1 + 0x80) = *(f32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x84) = *(f32 *)(arg0 + 0x14);
    *(f32 *)(arg1 + 0xC0) = *(f32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0xC4) = *(f32 *)(arg0 + 0xC);
}
/* measured: close loop-invariant conversion scope for func_004a86c0. */
#pragma opt_loop_invariants off
// FUN_004A8890
void func_004a8890(u8 *arg0, s32 *arg1) {
    s32 sp24C;
    s32 sp248;
    u8 sp140[0xFC];
    u8 sp40[0x100];
    s32 *temp_16;
    u8 *temp_18;
    u8 *temp_3;
    void (**setState)(u32, u32);
    void (**sendPacket)(s32, void *, s32, void *, s32);

    temp_16 = arg1;
    func_003f6690(2, &sp24C);
    func_003f6690(3, &sp248);
    setState = (void (**)(u32, u32))D_00887300;
    (*setState)((u32)1, *(u32 *)temp_16);
    func_00489f80();
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x31001);
    func_004a8250(arg0 + 4, sp140);
    sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
    (*sendPacket)(3, sp140, 4, D_00714368, 6);
    func_0048a000();
    func_003f6440(2, sp24C | 0x10);
    if (func_004a7e30(arg0 + 4, sp40) != 0) {
        (*setState)(1, D_00922D90[0]);
        func_003f6440(3, 0x31001);
        func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
        (*sendPacket)(3, sp40, 4, D_00714368, 6);
        func_0048a0e0();
    }
    (*setState)(1, 0);
    func_003f6440(3, sp248);
    func_003f6440(2, sp24C);
}
// FUN_004A8A50
void func_004a8a50(u8 *arg0, u8 *arg1)
{
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    u8 *temp_16;

    *(u32 *)arg1 = func_004bd050(0) % (u32)(*(s32 *)(arg0 + 4) + 1);
    *(f32 *)(arg1 + 4) = fGpffff80f4;
    temp_16 = arg1 + 8;
    *(s32 *)(arg1 + 0x10) = *(s32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(s32 *)(arg1 + 0xC) = *(s32 *)(arg0 + 0xC);
    temp_f20 = 0.5f * (f32)*(s32 *)(arg0 + 0x28);
    temp_f21 = *(f32 *)(arg0 + 0x24);
    temp_f22 = *(f32 *)(arg0 + 0x1C) +
               temp_f21 * (2.0f * (func_004bd0b0(0) - 0.5f));
    temp_f1 = *(f32 *)(arg0 + 0x20) +
              temp_f21 * (2.0f * (func_004bd0b0(0) - 0.5f));
    *(f32 *)(temp_16 + 0x14) = temp_f22;
    *(f32 *)(temp_16 + 0x18) = temp_f1;
    *(f32 *)(temp_16 + 0x1C) = temp_f22 - temp_f20;
    *(f32 *)(temp_16 + 0x20) = temp_f1 - temp_f20;
    *(f32 *)(temp_16 + 0x24) = temp_f22 + temp_f20;
    *(f32 *)(temp_16 + 0x28) = temp_f1 + temp_f20;
}
// FUN_004ABB60
void func_004abb60(void)
{
    u8 *temp_2;

    temp_2 = func_00401b80();
    *(u8 **)&D_00922D90[0] = temp_2;
    D_00922D94[0] = (f32)*(s32 *)(temp_2 + 0xC);
    D_00922D98[0] = (f32)*(s32 *)(temp_2 + 0x10);
}

// FUN_004ABBB0
void func_004abbb0(u8 *arg0)
{
    func_0047a2a0(arg0);
    if (func_00479ca0(arg0, 0) != 0) {
        func_00479940(arg0, 0, 0, 0, 0);
        func_0047a0e0(arg0, 0, 1.0f);
    }
    *(s32 *)(arg0 + 0xD8) &= ~2;
    func_00478eb0(arg0, func_004abe60, arg0);
}
// FUN_004ABC50
u8 *func_004abc50(u8 *arg0, s32 arg1)
{
    u8 *temp_2;

    goto loop_004abc50_check;
loop_004abc50_body:
    iGpffffbb90 += 1;
loop_004abc50_check:
    if (func_00477c40(6, iGpffffbb90, 0) != 0) {
        goto loop_004abc50_body;
    }
    temp_2 = func_00477f10(6, iGpffffbb90, arg0, arg1, 1);
    func_0047a2a0(temp_2);
    if (func_00479ca0(temp_2, 0) != 0) {
        func_00479940(temp_2, 0, 0, 0, 0);
        func_0047a0e0(temp_2, 0, 1.0f);
    }
    *(s32 *)(temp_2 + 0xD8) &= ~2;
    func_00478eb0(temp_2, func_004abe60, temp_2);
    iGpffffbb90 += 1;
    return temp_2;
}
// FUN_004ABD60
void func_004abd60(void)
{
    func_004787e0();
}

// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}

// FUN_004ACB80
void func_004acb80(u8 *arg0)
{
    extern f32 func_0047a080(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 temp_3;
    u32 temp_3_2;
    u32 temp_4;

    temp_f0 = func_0047a080(*(s32 *)(arg0 + 0xB4), 0);
    temp_4 = (u32)temp_f0 + 1;
    temp_3 = *(u32 *)(arg0 + 0x9C);
    if (temp_3 >= temp_4 || temp_3 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= temp_4) {
                func_00479e60(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= temp_4) {
            temp_3_2 = *(u32 *)(arg0 + 0x74);
            if (temp_4 < temp_3_2) {
                func_00479e60(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_3_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
}
// FUN_004ACCC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004accc0);
// FUN_004AD030
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ad030);
// FUN_004AD240
void func_004ad240(u8 *arg0) {
    func_004ad030(func_004814d0(*(u16 *)(arg0 + 0x38)), arg0);
}
// FUN_004AD280
void func_004ad280(u8 *arg0)
{
    extern f32 func_0047a080(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 var_3;
    u32 temp_2;
    u32 temp_2_2;

    temp_f0 = func_0047a080(*(s32 *)(arg0 + 0xB4), 0);
    var_3 = (u32)temp_f0 + 1;
    temp_2 = *(u32 *)(arg0 + 0x9C);
    if (temp_2 >= var_3 || temp_2 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= var_3) {
                func_00479e60(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= var_3) {
            temp_2_2 = *(u32 *)(arg0 + 0x74);
            if (var_3 < temp_2_2) {
                func_00479e60(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_2_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
    func_004ad030(func_004814d0(*(u16 *)(arg0 + 0x38)), arg0);
}
// FUN_004AD3E0
void func_004ad3e0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x0) = arg1[0];
    *(f32 *)(arg0 + 0x4) = arg1[1];
}
// FUN_004AD400
void func_004ad400(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0xC) = arg1;
}
// FUN_004AD410
s32 func_004ad410(u8 *arg0) {
    u8 *p;
    s32 result;
    p = *(u8 **)(arg0 + 0xB4);
    if (p != NULL) {
        result = (*(u8 *)(p + 0xEE) ^ 1U) < 1U;
    } else {
        result = 1;
    }
    return result;
}
// FUN_004AD440
s32 func_004ad440(u8 *arg0) {
    return *(u8 *)(arg0 + 0xB8) != 0;
}
// FUN_004AD450
void func_004ad450(u8 *arg0) {
    *(u8 *)(arg0 + 0xB8) = 0;
}
// FUN_004ADAB0
void func_004adab0(u8 *arg0)
{
    s32 *var_18;
    u32 temp_16;
    u32 var_17;

    if (*(s32 *)(arg0 + 0x9C) != 0) {
        temp_16 = *(u32 *)(arg0 + 0x28);
        var_18 = *(s32 **)(arg0 + 0x98);
        var_17 = 0;
        goto loop_004adab0_check;
loop_004adab0_body:
        func_00485fe0(*var_18);
        var_18++;
        var_17 += 1;
loop_004adab0_check:
        if (var_17 < temp_16) {
            goto loop_004adab0_body;
        }
    }
    func_00479e60((u8 *)*(s32 *)(arg0 + 0xA0), 0, 0.0f);
    *(s32 *)(arg0 + 0x2C) = 0;
}
// FUN_004ADB50
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004adb50);
// FUN_004ADE80
void func_004ade80(u8 *arg0)
{
    u8 frame[0x50];
    s32 *var_16_2;
    s32 temp_4;
    u32 temp_18;
    u32 var_16;
    u32 var_17;

    if (*(s32 *)(arg0 + 0x9C) == 0) {
        *(u8 *)(frame + 0x4C) = 0xFF;
        *(u8 *)(frame + 0x4D) = 0xFF;
        *(u8 *)(frame + 0x4E) = 0;
        *(u8 *)(frame + 0x4F) = 0xFF;
        var_16 = 0;
        goto loop_004ade80_a_check;
loop_004ade80_a_body:
        if (func_0047a510(*(u8 **)(arg0 + 0xA0), var_16, frame) != 0) {
            func_0045f0b0((f32 *)(frame + 0x30), frame + 0x4C, 1, 4.0f);
            func_0045fa00((f32 *)frame, 1, 30.0f);
        }
        var_16 += 1;
loop_004ade80_a_check:
        if (var_16 < (u32)*(u32 *)(arg0 + 0x28)) {
            goto loop_004ade80_a_body;
        }
        return;
    }
    temp_4 = *(s32 *)(arg0 + 0x90);
    temp_18 = *(u32 *)(arg0 + 0x28);
    var_16_2 = *(s32 **)(arg0 + 0x98);
    if ((*(s32 *)(arg0 + 0x2C) < temp_4) || (temp_4 == 0)) {
        var_17 = 0;
        goto loop_004ade80_b_check;
loop_004ade80_b_body:
        func_00485870(*var_16_2);
        var_16_2++;
        var_17 += 1;
loop_004ade80_b_check:
        if (var_17 < temp_18) {
            goto loop_004ade80_b_body;
        }
    }
}
// FUN_004ADFA0
void func_004adfa0(u8 *arg0) {
    func_004adb50();
    func_004ade80(arg0);
}
// FUN_004ADFE0
u_long128 func_004adfe0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}
// FUN_004ADFF0
u_long128 func_004adff0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}
// FUN_004AE000
void func_004ae000(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}
// FUN_004AE010
void func_004ae010(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}
// FUN_004AE0A0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004ae0a0);
/* The two $gp loads inside the COP2 blocks below are written as literal
   displacements (-0x7e0c) rather than as a relocation against fGpffff81f4.
   That is deliberate. With no GPREL16 relocation the verifier does NOT mask
   the immediate, so it is compared directly against retail and is proven
   equal; the symbolic form assembles to a different sequence (measured nd 4).
   WIAudit reports these two offsets as missing GPREL16 -- expected, not a bug. */
// FUN_004AE2F0
void func_004ae2f0(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 temp_hi;
    s32 temp_lo;
    s32 quotient;
    s32 remainder;
    f32 temp_f1;

    temp_lo = *(s32 *)(arg0 + 0x38) / 6;
    if (temp_lo > 0) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf12, $vf10\n"
            ".set reorder\n"
            :
            :
            : "$vf12", "memory");
        quotient = arg2 / temp_lo;
        remainder = arg2 % temp_lo;
        temp_f1 = (f32)remainder / (f32)temp_lo;
        temp_hi = (*(s8 *)(arg1 + 0x14) + quotient) % 6;
        spC = ((s32 *)p4_add_u32(((temp_hi + 1) % 6) * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lwc1 $f0, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 $2, $f0\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&spC)
            : "$2", "$vf2", "$vf11", "memory");
        sp8 = ((s32 *)p4_add_u32(temp_hi * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $3, $f0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&sp8)
            : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile(
            ".set noreorder\n"
            "mfc1 $3, %0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 $3, %1\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            "vmove.xyzw $vf11, $vf12\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "f"(1.0f - temp_f1), "f"(temp_f1)
            : "$3", "$vf2", "$vf10", "$vf11", "$vf12", "memory");
    } else {
        sp4 = ((s32 *)p4_add_u32(*(s8 *)(arg1 + 0x14) * 4, (u32)arg0))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $3, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "r"(&sp4)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
    }
}
// FUN_004AF520
void func_004af520(u8 *arg0) {
    u8 *temp;
    u8 *inner;
    temp = *(u8 **)(arg0 + 0x58);
    if (temp != NULL) {
        inner = *(u8 **)(temp + 0x20);
        *(s32 *)(arg0 + 0x64) = 0;
        *(s32 *)(arg0 + 0x68) = 0;
        func_00460ac0(func_00481460(*(u16 *)(inner + 0x54)), arg0 + 0x64);
    }
}
// FUN_004AF580
void func_004af580(u8 *arg0) {
    u8 *temp;
    u8 *inner;
    func_004aec80();
    temp = *(u8 **)(arg0 + 0x58);
    if (temp != NULL) {
        inner = *(u8 **)(temp + 0x20);
        *(s32 *)(arg0 + 0x64) = 0;
        *(s32 *)(arg0 + 0x68) = 0;
        func_00460ac0(func_00481460(*(u16 *)(inner + 0x54)), arg0 + 0x64);
    }
}
// FUN_004AF5E0
void func_004af5e0(u8 *arg0) {
    func_00492dd0(*(u8 **)(arg0 + 0x58));
}
// FUN_004AF610
void func_004af610(u8 *arg0) {
    func_00492e10(*(u8 **)(arg0 + 0x58));
}
// FUN_004AF640
void func_004af640(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x4) = arg1;
}
// FUN_004AF650
void func_004af650(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x8) = arg1;
    func_00492e30(*(u8 **)(arg0 + 0x58));
}
