#include "include_asm.h"
#include "type.h"
extern s32 iGpffff9ef8;
extern s32 iGpffff9f08;

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);
extern u8 *func_00145270(u16 arg0);
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007E8C00[];
extern void func_00442830(void *arg0, const char *arg1);
extern s32 func_00442088(char *buf, const char *fmt, ...);
extern s32 func_00454570(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 iGpffffb2e8;
extern s32 iGpffffb2e4;
extern s32 iGpffffb2e0;
extern u8 D_007E8BE0[];
extern u8 D_007E8BE8[];
extern u8 D_007E8BF8[];
extern u8 D_007E80A0[];
extern u8 D_007E8060[];
extern u8 D_007E8020[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern void (*D_00887300[])(u32, u32);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_0044ea90(const void *msg, s32 line);
extern void *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern void func_00456150(void *arg0);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_00454bd0(void *arg0);
extern u8 *func_00457120();
extern void func_003e9d50(u8 *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_00457630(u8 *arg0, void *arg1, void *arg2, s32 arg3);
extern u8 D_005F16C8[];
extern u8 D_005F16D0[];
extern void func_001604a0(u8 *arg0);
extern s32 func_004553c0(u8 *arg0);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern u8 *func_0047a2f0();
extern void func_00478e70(s32 arg0);
extern s32 iGpffff9f00;
extern void func_003e99a0(void *arg0);
extern void func_003e9390(void *arg0);
extern void func_003e9830(s32 arg0, s32 arg1);
extern void func_003e0f40(s32 arg0);
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;

typedef struct E9F0Vec3
{
    f32 x;
    f32 y;
    f32 z;
} E9F0Vec3;
typedef struct E8E0Frame
{
    s64 sp30;
    f32 sp38;
    u8 pad3c[4];
    u8 sp40[12];
    u8 pad4c[4];
    E9F0Vec3 sp50;
} E8E0Frame;
extern s32 func_003e0380(E9F0Vec3 *arg0);
extern void func_003e03e0(u8 *arg0, E9F0Vec3 *arg1);
extern void func_003e05d0(u8 *arg0);



// FUN_00160440
void func_00160440(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x1854) != 0) {
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x1854));
        *(s32 *)((u8 *)func_00155280() + 0x1854) = 0;
    }
}



// FUN_001604A0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001604a0);
// FUN_001605A0
void func_001605a0(void)
{
    u8 *temp_2;

    if (iGpffffb2b0 == NULL) {
        func_0044ea90(D_005F11E8, 0xEE);
        iGpffffb2b0 = (u8 *)D_008873F4[0](1, 0x12400, 0x40000);
    }
    func_00440b68((char *)&iGpffff9f00, D_005F11E8, 0xF4);
    temp_2 = func_00454a60(D_005F1200, 0);
    func_00456150(temp_2);
    func_0043f810(iGpffffb2b0, *(void **)(temp_2 + 0x110), 0x12400);
    func_00454bd0(temp_2);
    func_001604a0(func_00457120());
}
/* measured: retail hoists the D_00887300 base into a saved local across
   five indirect calls; opt_propagation off preserves that address materialization. */
// FUN_00160680
#pragma opt_propagation off
void func_00160680(void)
{
    s32 temp_5;
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 0);
    base[0](8, 0);
    base[0](7, 2);
    base[0](1, 0);
    base[0](0xC, 1);
    base[0](0xE, 0);
    func_003f6440(3, 0x71801);
    temp_5 = *(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124);
    switch (temp_5) {
    case 0:
        func_003f6440(2, 0x44);
        break;
    case 1:
        func_003f6440(2, 0x48);
        break;
    case 2:
        func_003f6440(2, 0x42);
        break;
    case 3:
        func_003f6440(2, 6);
        break;
    }
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_001607E0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001607e0);
// FUN_00160880
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00160880);
// FUN_001614D0
s32 func_001614d0(void)
{
    return *(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124);
}
// FUN_00161500
void func_00161500(s32 arg0)
{
    iGpffff9ef8 = arg0;
}

/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the 0x750 stride and exact table bases (nd 14 -> 0).
   Committed at nd 0. */

// FUN_00161510
s32 func_00161510(void)
{
    char sp90[0x80];
    char sp10[0x80];

    func_00442830(sp90, D_005F1218);
    func_00442088(sp10, D_005F1230);
    if (func_00454570(sp10) == 0) {
        return 0;
    }
    func_00440b68((char *)&iGpffff9f08, D_005F1248, 0x69);
    return (s32)func_00454a60(sp10, 0);
}

/* measured: opt_propagation off probe for retail field-load order in func_001615a0 */
#pragma opt_propagation off
// FUN_001615A0
s32 func_001615a0(u8 *arg0)
{
    void *src;
    u32 size;

    if (arg0 == NULL) {
        return 1;
    }
    if (func_004553c0(arg0) == 0) {
        return 0;
    }
    iGpffffb2c8 = D_007E7B20;
    size = *(u32 *)(arg0 + 0x118);
    src = *(void **)(((u8 *)arg0 + size) - size + 0x110);
    func_0043f810(iGpffffb2c8, src, size);
    iGpffffb2cc = iGpffffb2c8 + 0x300;
    func_00454bd0(arg0);
    return 1;
}
/* measured: opt_propagation on closes the func_001615a0 load-order probe */
#pragma opt_propagation on
// FUN_00162120
void func_00162120(void)
{
    func_0043f9c8(D_007F16F0, 0, 0x20);
    func_0043f9c8(D_007EF9B0, 0, 0x1D40);
    func_0043f9c8(D_007E8C00, 0, 0x6DB0);
    iGpffffb2e8 = 0;
    func_0043f9c8(D_007E8BE0, 0, 0x20);
    *(s32 *)D_007E8BE8 = -1;
    *(s32 *)D_007E8BF8 = -1;
    func_0043f9c8(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    iGpffffb2e0 = 0;
    func_0043f9c8(D_007E8060, 0, 0x40);
    func_0043f9c8(D_007E8020, 0, 0x40);
}

// FUN_00162200
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00162200);
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
// FUN_001622D0
#pragma opt_loop_invariants on
void func_001622d0(void) {
    s32 i = 0;
    s32 one = 1;
    s32 stride = 0x750;

    while (i < 4) {
        *(s32 *)(D_007EF9B0 + i * stride + 0x44) = one;
        *(s32 *)(D_007F16F0 + i * 8 + 4) = 0;
        *(s16 *)(D_007F16F0 + i * 8) = 0;
        *(s16 *)(D_007F16F0 + i * 8 + 2) = 0;
        i++;
    }
}
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
#pragma opt_loop_invariants off

// FUN_00162330
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *func_00162330(void) {
    u8 *r = NULL;
    s32 i = 0;
    u8 *e;

    while (i < 4) {
        e = D_007EF9B0 + i * 0x750;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_00162390
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *func_00162390(void) {
    u8 *r = NULL;
    s32 i = 0;
    s32 stride = 0x750;
    u8 *e;

    while (i < 0xF) {
        e = D_007E8C00 + i * stride;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
/* measured: closes the loop-invariant scope at the file baseline. */
#pragma opt_loop_invariants off

// FUN_001623F0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001623f0);
// FUN_00162510
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00162510);
// FUN_00162680
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00162680);
// FUN_00167F00
s32 func_00167f00(u8 *arg0)
{
    s32 temp_3;
    s32 temp_4_2;
    u16 temp_4;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0xC) == 0) {
        temp_4 = *(u16 *)(temp_16 + 4);
        temp_3 = (temp_4 & 0xFFC00) >> 0xA;
        switch (temp_3) {
        case 1:
            temp_2 = func_00145270(temp_4);
            *(s32 *)(temp_16 + 8) = *(s32 *)(temp_2 + 0x164);
            *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_2 + 0x228);
            break;
        case 3:
            temp_2_2 = func_00145270(temp_4);
            if ((*(s32 *)(temp_2_2 + 0x28) & 0x10000000) != 0) {
                *(s32 *)(temp_16 + 8) = *(s32 *)(temp_2_2 + 0x164);
                *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_2_2 + 0x22C);
            }
            break;
        }
    }
    temp_4_2 = *(s32 *)(temp_16 + 8);
    if ((temp_4_2 != 0) &&
        (*(s32 *)(temp_16 + 0xC) != 0) &&
        (((*(u16 *)(temp_16 + 4) & 0xFFC00) >> 0xA) == 3)) {
        temp_17 = (u8 *)func_0047a2f0(temp_4_2);
        temp_2_3 = (u8 *)func_0047a2f0(*(s32 *)(temp_16 + 0xC));
        *(E9F0Vec3 *)(temp_2_3 + 0x30) =
            *(E9F0Vec3 *)(temp_17 + 0x30);
        func_00478e70(*(s32 *)(temp_16 + 0xC));
    }
    return 0;
}
// FUN_00168030
void func_00168030(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00168060
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00168060);
// FUN_00168470
void func_00168470(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_001684A0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001684a0);
// FUN_00168730
void func_00168730(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) | arg1;
}
// FUN_00168750
void func_00168750(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) & ~arg1;
}
// FUN_00168770
f32 func_00168770(u8 *arg0)
{
    return *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x24);
}
// FUN_00168780
void func_00168780(u8 *arg0, f32 fparg0) {
    u8 *temp_5;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(f32 *)(temp_5 + 0x24) = fparg0;
    if (fparg0 == 0.0f) {
        *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) | 0x10000000);
        return;
    }
    *(s32 *)(temp_5 + 4) = (s32) (*(s32 *)(temp_5 + 4) & 0xEFFFFFFF);
}

// FUN_001687D0
s32 func_001687d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40);
}

// FUN_001687E0
s32 func_001687e0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44);
}

// FUN_001687F0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_001687f0);
// FUN_00168890
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00168890);
// FUN_00168AE0
void func_00168ae0(u8 *arg0, u8 *arg1)
{
    E9F0Vec3 sp30;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(temp_16 + 0x10);
    if (temp_4 != 0) {
        temp_2 = (u8 *)func_0047a2f0(temp_4);
        *(E9F0Vec3 *)(temp_2 + 0x30) =
            *(E9F0Vec3 *)(arg1 + 0x00);
        func_003e0380(&sp30);
        func_003e03e0(
            (u8 *)func_0047a2f0(*(s32 *)(temp_16 + 0x10)),
            &sp30);
        func_003e05d0(
            (u8 *)func_0047a2f0(*(s32 *)(temp_16 + 0x10)));
        *(s32 *)(temp_16 + 0x40) =
            (s32)((600.0f +
                   *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x10)) +
                            0x30)) /
                  1200.0f);
        *(s32 *)(temp_16 + 0x44) =
            (s32)((600.0f +
                   *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x10)) +
                            0x38)) /
                  1200.0f);
    }
}
// FUN_00168C00
void func_00168c00(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_16 + 0x40) =
        (s32)((600.0f + *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x10)) + 0x30)) /
              1200.0f);
    *(s32 *)(temp_16 + 0x44) =
        (s32)((600.0f + *(f32 *)(func_0047a2f0(*(s32 *)(temp_16 + 0x10)) + 0x38)) /
              1200.0f);
}
// FUN_00168CB0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00168cb0);
// FUN_00168DE0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00168de0);
// FUN_00168EC0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_00168ec0);
// FUN_0016B8A0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016b8a0);
// FUN_0016BDD0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016bdd0);
// FUN_0016E210
void func_0016e210(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(*(u8 **)(func_00457120() + 4) + 4) != 0) {
        func_003e99a0(*(void **)(func_00457120() + 4));
    }
    if (*(s32 *)(*(u8 **)(temp_16 + 0xC) + 4) != 0) {
        func_003e99a0(*(void **)(temp_16 + 0xC));
    }
    func_003e9390(*(void **)(temp_16 + 0xC));
    func_003e9830(*(s32 *)(temp_16 + 0x10), *(s32 *)(func_00457120() + 4));
    func_003e0f40(*(s32 *)(temp_16 + 0x2BC));
    func_003e0f40(*(s32 *)(temp_16 + 0x2C0));
    func_003e0f40(*(s32 *)(temp_16 + 0x2C4));
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}
// FUN_0016E2E0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016e2e0);
// FUN_0016E540
void func_0016e540(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) | arg1;
}
// FUN_0016E560
void func_0016e560(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) & ~arg1;
}
// FUN_0016E580
s32 func_0016e580(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x8);
}

// FUN_0016E590
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016e590);
// FUN_0016E8C0
u8 *func_0016e8c0(u8 *arg0)
{
    return *(u8 **)(*(u8 **)(arg0 + 0x38) + 0xC) + 0x40;
}
/* measured: opt_propagation off preserves the retail early a1 pointer
   materialization in func_0016e8e0. */
#pragma opt_propagation off
// FUN_0016E8E0
void func_0016e8e0(u8 *arg0, f32 fparg0)
{
    E8E0Frame sp;
    void *temp_2;
    s64 temp_5;
    f32 temp_f0;
    f32 temp_f1;
    u8 *var_3;
    s32 temp_4;
    s32 var_2;
    u8 *temp_16;

    temp_4 = *(s32 *)(*(u8 **)(arg0 + 0x38) + 8);
    if (temp_4 == 0) {
        goto process;
    }
    if (temp_4 == 6) {
        goto process;
    }
    if (temp_4 != 7) {
        goto done;
    }
process:
    temp_16 = *(u8 **)(func_00457120(temp_4) + 4);
    sp.sp50 = *(E9F0Vec3 *)(temp_16 + 0x40);
    var_3 = &sp.sp40[0];
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    temp_2 = &sp.sp30;
    temp_5 = *(s64 *)D_005F16C8;
    temp_f0 = *(f32 *)D_005F16D0;
    sp.sp30 = temp_5;
    sp.sp38 = temp_f0;
    temp_f1 = fparg0;
    func_003e9d50(temp_16, temp_2, temp_f1, 2);
    sp.sp50 = *(E9F0Vec3 *)(temp_16 + 0x40);
    func_00457630(func_00457120(), &sp.sp50, &sp.sp40[0], 0);
done:
    ;
}
/* measured: closes opt_propagation off for func_0016e8e0. */
#pragma opt_propagation on
// FUN_0016E9F0
void func_0016e9f0(u8 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    *(E9F0Vec3 *)(temp_3 + 0x14) = *(E9F0Vec3 *)(arg1 + 0x00);
}



// FUN_0016EA20
void func_0016ea20(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x20) = arg1;
}
// FUN_0016EA30
void func_0016ea30(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x24) = arg1;
}
// FUN_0016EA40
void func_0016ea40(u8 *arg0, u16 arg1)
{
    u8 *temp_16;
    s32 type;

    temp_16 = *(u8 **)(arg0 + 0x38);
    type = (arg1 & 0xFFC00) >> 10;
    if (type == 1)
        *(u8 **)(temp_16 + 0x288) = func_00145270(arg1);
}

// FUN_0016EAA0
/* The scaled offset is named in an s32 local and the base added TO it so the
   final addu comes out `index + base` as retail has it; folding the multiply
   into the pointer expression emits `base + index` (nd 1). The three floats
   are one E9F0Vec3 assignment because retail loads all three before storing
   any. */
void func_0016eaa0(u8 *arg0, s32 arg1, E9F0Vec3 *arg2) {
    u8 *base;
    s32 i;
    s32 off;

    base = *(u8 **)(arg0 + 0x38);
    i = (s8)arg1;
    base[i + 0xE8] = 1;
    off = i * 12;
    *(E9F0Vec3 *)(off + (s32)base + 0x108) = *arg2;
}

// FUN_0016EAF0
s32 func_0016eaf0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x2BC);
}

// FUN_0016EB00
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016eb00);
// FUN_0016EC90
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016ec90);
// FUN_0016EE00
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016ee00);
// FUN_0016F100
void func_0016f100(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

// FUN_0016F130
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f130);
// FUN_0016F3B0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f3b0);
// FUN_0016F630
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f630);
// FUN_0016F750
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f750);
// FUN_0016F8B0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f8b0);
// FUN_0016FD00
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016fd00);
// FUN_0016FE80
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016fe80);
// FUN_0016FFD0
INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016ffd0);