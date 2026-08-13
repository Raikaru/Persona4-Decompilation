#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline s32 code1_0018_shift4(s32 value)
{
    return value << 4;
}
static inline s32 code1_0018_add2(s32 first, s32 second)
{
    return first + second;
}
extern void func_0048a000();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_001852f0(void);
extern void func_003a2760(s32 arg0);
extern void func_003e9390(s32 arg0);
extern void func_003c21e0();
extern void func_004787e0(s32 arg0);
extern void func_003f3eb0(s32 arg0, s32 arg1);
extern void func_00185370();
extern void func_00183b80(u8 *arg0);

extern u8 *(*jtbl_008873EC[])(u8 *);

extern s32 D_0076428C;
extern s32 iGpffffb27c;
extern u64 iGpffffb8c8;
extern s32 iGpffffb278;
extern s32 func_0029d2e0(void);
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline s32 code1_0018_get_b278(void)
{
    return iGpffffb278;
}
extern s32 func_00452490(s32 arg0);

void func_0018e780(s32 arg0);



extern void func_003e0f40(s32 arg0);
extern s32 func_00457a90(u8 *arg0, u8 *arg1);
extern void func_003c42b0(u8 *arg0, s32 arg1);
extern u8 D_005F5438[];
extern u8 *func_00155280(void);
extern void func_0014e8f0(s32 a, s32 b, s32 c);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 a, u8 *b);
extern void func_003f6800(s32 a, f32 fp);
extern u8 D_005F5360[];
extern u8 iGpffffb310;
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern s32 func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 size, s32 align, s32 flags);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern u8 *func_00457120(void);
extern f32 fGpffff8218;
extern void func_00479940(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_0018a200(u8 *arg0);
extern s32 func_0015a560(void);
extern u8 D_005F54D8[];
extern s32 func_00189940(u8 *arg0);
extern void func_0018a010(s32 arg0);
extern u8 D_005F54E8[];
extern s32 func_0018dde0(u8 *arg0);
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern void func_00182bc0(u8 *arg0);
extern s32 func_00451fc0(u8 *window, const void *data, s32 prio, s32 arg3,
                         s32 arg4, void (*init)(u8 *), void (*close)(u8 *),
                         u8 *work);
extern void func_00185850(u8 *arg0);
extern void func_00186610(u8 *arg0);
extern void func_0018e810(u8 *arg0);
extern void func_0018ef20(u8 *arg0);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 func_003bfae0();
extern u8 *func_00457120(void);
extern s32 func_003e8200(u8 *arg0, s32 arg1);
extern void func_003f68a0(s32 arg0, s32 arg1);
extern u8 D_007E8C00[];
extern void func_003bff30(u8 *arg0, u8 *(*cb)(u8 *, s32), s32 *result);

/* measured: loop-invariant hoisting keeps the retail stride/base preheader for
   the 0x750 slot scan. */
#pragma opt_loop_invariants on
// FUN_00182310
void func_00182310(s32 arg0)
{
    s32 i;
    s32 one;
    s32 stride;
    s32 hit;
    u8 *p;
    u8 *temp;

    i = 0;
    one = 1;
    stride = 0x750;
    while (i < 0xF) {
        hit = 0;
        p = D_007E8C00 + i * stride;
        if (*(s32 *)(p + 0x48) != 0 && *(s32 *)(p + 0x54) != 0) {
            hit = one;
        }
        hit = hit != 0;
        if (hit != 0) {
            temp = *(u8 **)(p + 0x1B0);
            if (temp != NULL) {
                *(s32 *)(*(u8 **)(temp + 0x38) + 4) = arg0;
            }
        }
        i += 1;
    }
}
/* measured: close loop-invariant hoisting around the slot scan. */
#pragma opt_loop_invariants off
// FUN_00182390
void func_00182390(void)
{
    func_0043f9c8(&iGpffffb310, 0, 4);
}
// FUN_001823C0
u8 *func_001823c0(void)
{
    return &iGpffffb310;
}
// FUN_001823D0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001823d0);
/* measured probe: opt_propagation off tests caching the repeated render callback base. */
#pragma opt_propagation off
// FUN_00182B40
void func_00182b40(void)
{
    void (**fn)(s32, s32);

    fn = D_00887300;
    fn[0](7, 2);
    fn[0](6, 1);
    fn[0](8, 0);
    fn[0](0xC, 1);
}
/* measured probe: restore opt_propagation after func_00182b40. */
#pragma opt_propagation on
// FUN_00182BC0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00182bc0);
/* measured: propagation off preserves the cached jtbl_008873EC base for
   the post-loop callback sequence. */
// FUN_001837F0
#pragma opt_propagation off
void func_001837f0(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    u8 *(**base)(u8 *);

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_17 = 0;
    while (var_17 < *(s32 *)(temp_16 + 0x40)) {
        jtbl_008873EC[0](*(u8 **)(*(u8 **)(temp_16 + 0x5C) + var_17 * 0x10 + 0xC));
        var_17 += 1;
    }
    base = jtbl_008873EC;
    base[0](*(u8 **)(temp_16 + 0x5C));
    base[0](*(u8 **)(temp_16 + 0x38));
    func_003a2760(*(s32 *)(temp_16 + 8));
    func_003e9390(*(s32 *)(temp_16 + 0xC));
    if (*(s32 *)(temp_16 + 0x10) != 0) {
        func_003e0f40(*(s32 *)(temp_16 + 0x10));
    }
    base[0](*(u8 **)(arg0 + 0x38));
}
/* measured: closing the single-function callback-base bracket. */
#pragma opt_propagation on
// FUN_001838D0
void func_001838d0(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    func_0044ea90(&D_005F1D80, 0x17B);
    temp_2 = D_008873F4[0](1, 0x78, 0x40000);
    func_00451fc0(arg0, &iGpffff9f60, 0xF, 0, 0, func_00182bc0,
                  func_001837f0, temp_2);
    *(s32 *)(temp_2 + 0x28) = arg1;
    *(f32 *)(temp_2 + 0x18) = fparg0;
    *(f32 *)(temp_2 + 0x14) = fparg1;
    *(f32 *)(temp_2 + 0x1C) = fparg2;
    *(f32 *)(temp_2 + 0x20) = fparg3;
    *(s32 *)(temp_2 + 0x24) = arg2;
    *(s32 *)(temp_2 + 0x2C) = arg3;
    *(s32 *)(temp_2 + 0x30) = arg4;
}
// FUN_001839E0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001839e0);
 
// FUN_00183B80
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00183b80);
// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00185150
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185150);
/* measured: VU0 MMI builtins and O1 reproduce the target's pcpyld/sq packet. */
#pragma enable_vu0_registers on
/* measured: bind MMI packet registers as in retail. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 preserves the target's packet construction order. */
#pragma optimization_level 1
// FUN_001852F0
void func_001852f0(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb27c;
    *packet = packed;
    c = 0x4C;
    b = iGpffffb8c8 | 0xFF00000000000000ULL;
    packed = _pcpyld(c, b);
    packet[1] = packed;
    iGpffffb27c += 0x20;
}
/* measured: restore the file's O2 baseline after the target. */
#pragma optimization_level 2
/* measured: stop binding MMI packet registers after the target. */
#pragma vu0_mmi_reg_binding off
/* measured: stop VU0 register mode after the target. */
#pragma enable_vu0_registers off

/* measured: enable_vu0_registers + vu0_mmi_reg_binding with optimization_level 1
   reproduces the sibling 112-byte pcpyld/sq skeleton; direct _pcpyld on separate
   u64 pairs gives the retail register order and reload. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: optimization_level 1 is required with the VU0 pragmas above;
   at -O2 the packet stores are reordered and the pcpyld pairs are folded. */
#pragma optimization_level 1
// FUN_00185370
void func_00185370(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c, d;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb27c;
    *packet = packed;
    c = 0x4C;
    d = iGpffffb8c8;
    packed = _pcpyld(c, d);
    packet[1] = packed;
    iGpffffb27c += 0x20;
}
/* measured: closes the cluster pcpyld pragma scope and restores the file's -O2
   baseline. */
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001853E0
#pragma opt_propagation off
void func_001853e0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C0);
    base[0](1, *value);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001854F0
#pragma opt_propagation off
void func_001854f0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 1);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C4);
    base[0](1, *value);
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_00185620
#pragma opt_propagation off
void func_00185620(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    base[0](1, *(s32 *)(arg1 + 0x88C8));
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: retail hoists the D_00887300 base across nine indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00185730
#pragma opt_propagation off
void func_00185730(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    base[0](1, 0);
    func_00489f80();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185830
void func_00185830(void)
{
    func_0048a000();
}

// FUN_00185850
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185850);
// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00186640
void func_00186640(u8 *arg0)
{
    func_0044ea90(&D_005F1DF8, 0x299);
    func_00451fc0(arg0, &D_005F1E08, 0xF, 0, 0, func_00185850,
                  func_00186610, D_008873F4[0](1, 0x88D0, 0x40000));
}
// FUN_00189600
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189600);
/* measured: retail hoists the D_00887300 base across seven indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00189870
#pragma opt_propagation off
void func_00189870(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 1);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    base[0](1, 0);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00189940
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189940);
// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189EC0
void func_00189ec0(void)
{
    u8 *temp_16;
    u8 *temp_2;
    s32 var_16;
    if (*(s32 *)((u8 *)func_00155280() + 0x30) == 0) {
        temp_16 = *(u8 **)func_00155280();
        func_0044ea90(&D_005F5320, 0x17C);
        temp_2 = D_008873F4[0](1, 0x230, 0x40000);
        if (temp_2 == NULL) {
            var_16 = 0;
        } else {
            var_16 = func_00451fc0(temp_16, &D_005F5330, 0xF, 0, 0,
                                   (void (*)(u8 *))func_00189940,
                                   (void (*)(u8 *))func_00189e90, temp_2);
        }
        *(s32 *)((u8 *)func_00155280() + 0x30) = var_16;
        func_0018a010(-1);
    }
}
// FUN_00189FA0
s32 func_00189fa0(void) {
    if (*(s32 *)((u8 *)(func_00155280()) + 0x30) == 0) {
        return 0;
    }
    func_00452080(*(s32 *)((u8 *)(func_00155280()) + 0x30));
    *(s32 *)((u8 *)(func_00155280()) + 0x30) = 0;
    return 1;
}

// FUN_0018A000
void func_0018a000(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4) = arg1;
}

// FUN_0018A010
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018a010);
// FUN_0018A170
s32 func_0018a170(s32 arg0, s32 *arg1)
{
    u8 *temp_16;

    func_003bfae0();
    temp_16 = func_00457120();
    if (func_003e8200(temp_16, func_003bfae0(arg0)) != 0) {
        *arg1 = 1;
        return 0;
    }
    return arg0;
}
// FUN_0018A200
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018a200);
// FUN_0018BAD0
void func_0018bad0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018BB20
s32 func_0018bb20(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&D_005F5340, 0x2E6);
    temp_2 = D_008873F4[0](1, 0x58, 0x40000);
    if (temp_2 == NULL)
        return 0;
    temp_17 = func_00451fc0((u8 *)arg0, &D_005F5350, 0xF, 0, 0,
                            func_0018a200, func_0018bad0, temp_2);
    *(s32 *)(temp_2 + 0xC) = arg1;
    *(f32 *)(temp_2 + 0x48) = *(f32 *)(func_00457120() + 0x80);
    return temp_17;
}
// FUN_0018BBF0
s32 func_0018bbf0(u8 *arg0)
{
    u32 value;

    if (arg0 == NULL) {
        return 1;
    }
    value = *(u32 *)(*(u8 **)(arg0 + 0x38));
    return value >= 4;
}
// FUN_0018BC20
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bc20);
/* measured: optimization_level 1 preserves the retail FPU accumulator order. */
#pragma optimization_level 1
// FUN_0018BDD0
void func_0018bdd0(u8 *arg0)
{
    u8 *temp_16;
    u8 *target;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    f32 value30;
    f32 value34;
    f32 value38;
    s32 zero;
    s32 one;

    temp_16 = *(u8 **)(arg0 + 0x38);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) + guard38 * guard44 <
        fGpffff8218) {
        value30 = *(f32 *)(temp_16 + 0x30);
        value34 = *(f32 *)(temp_16 + 0x34);
        value38 = *(f32 *)(temp_16 + 0x38);
        *(f32 *)(temp_16 + 0x3C) = value30;
        *(f32 *)(temp_16 + 0x40) = value34;
        *(f32 *)(temp_16 + 0x44) = value38;
        target = *(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        one = 1;
        func_00479940(target, zero, one, 4, one);
        *(s32 *)temp_16 = 6;
        return;
    }
    func_00479940(*(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164),
                  0, 0, 8, 1);
    *(s32 *)temp_16 = 4;
}
/* measured: close optimization_level 1 FPU accumulator probe. */
#pragma optimization_level 2
/* measured: opt_propagation off probe preserves retail's handle-load/result
   initialization order for the state predicate. */
#pragma opt_propagation off
// FUN_0018BEA0
s32 func_0018bea0(u8 *arg0)
{
    u8 *p;
    s32 r;
    s32 v;

    p = *(u8 **)(arg0 + 0x38);
    r = 0;
    v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    return r;
}
/* measured: opt_propagation on closes the state-predicate probe. */
#pragma opt_propagation on
// FUN_0018BED0
void func_0018bed0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s32 *)(func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34) == 0) {
        return;
    }
    func_0014e8f0(*(s32 *)(func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34),
                  *(s32 *)(p + 0x54), arg1);
}

// FUN_0018BF50
s32 func_0018bf50(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 r = 0;
    s32 v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    if (*(u16 *)(*(u8 **)(p + 0xC) + 0x220) == 3) {
        if (*(s32 *)(p + 0x24) > 0) {
            r = 1;
        }
    }
    return r;
}

// FUN_0018C610
u8 *func_0018c610(u8 *arg0, s32 *arg1) {
    if (func_00457a90(arg0, D_005F5438) != 0) {
        arg1[0] = 1;
        func_003c42b0(arg0, arg1[1]);
    }
    return arg0;
}

// FUN_0018C680
u8 *func_0018c680(u8 *arg0, s32 arg1)
{
    func_003c21e0(*(s32 *)(arg0 + 0x18), func_0018c610, arg1);
    return arg0;
}
// FUN_0018C6C0
s32 func_0018c6c0(u8 *arg0, s32 arg1)
{
    s32 sp[2];

    sp[0] = 0;
    sp[1] = arg1;
    func_003bff30(arg0, func_0018c680, sp);
    return sp[0];
}
// FUN_0018C700
void func_0018c700(f32 fp0) {
    s32 a;
    s32 b;

    a = func_003ef6d0();
    b = func_003ef650(a, D_005F5360);
    func_003f6800(b, fp0);
}

/* At the -O2 file baseline this function is normalized_diff 2: retail reads
   `mfc1 $a1` and `or $a1,$a1,$v1` where -O2 colours both one register lower.
   The bracket is closed back to the -O2 baseline immediately below the body.
   measured: optimization_level 1 for this function alone, plus materialising
   the 2147483648.0f constant into a named local AFTER the func_003ef650 call
   rather than inline, gives object 136B/window 144B, normalized_diff 0. */
#pragma optimization_level 1
// FUN_0018C750
void func_0018c750(f32 fparg0)
{
    s32 temp_2;
    s32 var_5;
    f32 constant;

    temp_2 = func_003ef650(func_003ef6d0(), D_005F5360);
    constant = 2147483648.0f;
    if (constant <= fparg0) {
        goto positive;
    }
    var_5 = (s32)fparg0;
    goto done;
positive:
    var_5 = (s32)(fparg0 - constant);
    var_5 |= (s32)0x80000000;
done:
    func_003f68a0(temp_2, var_5);
}
/* measured: restore optimization level after func_0018c750. */
#pragma optimization_level 2
// FUN_0018C7E0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018c7e0);
// FUN_0018CED0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018ced0);
// FUN_0018DDE0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018dde0);
// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0018DF60
s32 func_0018df60(s32 arg0)
{
    s32 temp_2;
    u8 *temp_2_2;

    if (func_0015a560() == 0)
        return 0;
    func_0044ea90(&D_005F54D8, 0x91);
    temp_2_2 = D_008873F4[0](1, 0x14, 0x40000);
    if (temp_2_2 == NULL)
        return 0;
    temp_2 = func_00451fc0((u8 *)arg0, &D_005F54E8, 0xF, 0, 0,
                           (void (*)(u8 *))func_0018dde0, func_0018df30, temp_2_2);
    *(s32 *)(temp_2_2 + 8) = 0x1E;
    return temp_2;
}
// FUN_0018E030
void func_0018e030(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}



// FUN_0018E450
s32 func_0018e450(u8 *arg0)
{
    s32 *p;
    s32 state;

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
        func_0018e780(0);
        *p += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}

// FUN_0018E4D0
void func_0018e4d0(u8 *arg0)
{
    s32 value;

    value = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (value != 0) {
        func_004787e0(value);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
// FUN_0018E810
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018e810);
// FUN_0018EF20
void func_0018ef20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0018EF50
void func_0018ef50(s32 arg0)
{
    func_0044ea90(&D_005F57B0, 0x101);
    func_00451fc0((u8 *)arg0, &D_005F57C0, 0xF, 0, 0, func_0018e810,
                  func_0018ef20, D_008873F4[0](1, 0x1B440, 0x40000));
}
// FUN_0018EFE0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018efe0);
// FUN_0018F390
void func_0018f390(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0018F7B0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f7b0);
// FUN_0018F8A0
void func_0018f8a0(u8 *arg0, u16 arg1, u16 arg2)
{
    s32 var_9;
    s32 var_8;
    u8 *temp_5;
    u8 *temp_6;
    u8 *temp_7;
    u8 *field;

    temp_7 = (u8 *)code1_0018_add2(
        code1_0018_shift4(arg1 & 0xFFFF),
        ((arg2 & 0xFFFF) << 8) + (s32)arg0);
    if (temp_7[0x2C] != 0 && (temp_7[0x2D] & 0xF) != 0) {
        var_9 = 0;
        while (var_9 < (s32)temp_7[0x33]) {
            var_8 = 0;
            temp_6 = temp_7 + (var_9 << 8);
            while (var_8 < (s32)temp_7[0x32]) {
                temp_5 = temp_6 + var_8 * 0x10;
                field = temp_5 + 0x2C;
                if (*field != 0) {
                    *field = 0;
                    temp_5[0x2D] = 0;
                }
                var_8 += 1;
            }
            var_9 += 1;
        }
    }
}
// FUN_0018F950
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f950);
