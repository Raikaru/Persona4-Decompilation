#include "include_asm.h"
#include "type.h"
extern void func_0048a000();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003c21e0();
extern void func_004787e0(s32 arg0);
extern void func_00185370();

extern void (*jtbl_008873EC[])(void *);

extern s32 D_0076428C;

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

// FUN_00182310
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00182310);
// FUN_00182390
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00182390);
// FUN_001823C0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001823c0);
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
// FUN_001837F0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001837f0);
// FUN_001838D0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001838d0);
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
// FUN_001852F0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001852f0);

// FUN_00185370
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185370);

// FUN_001853E0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001853e0);
// FUN_001854F0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001854f0);
// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

// FUN_00185620
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185620);
// FUN_00185730
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185730);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00186640);
// FUN_00189600
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189600);
// FUN_00189870
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189870);
// FUN_00189940
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189940);
// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189EC0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00189ec0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018a170);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bb20);
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
// FUN_0018BDD0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bdd0);
// FUN_0018BEA0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bea0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018c6c0);
// FUN_0018C700
void func_0018c700(f32 fp0) {
    s32 a;
    s32 b;

    a = func_003ef6d0();
    b = func_003ef650(a, D_005F5360);
    func_003f6800(b, fp0);
}

// FUN_0018C750
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018c750);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018df60);
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
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018ef20);
// FUN_0018EF50
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018ef50);
// FUN_0018EFE0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018efe0);
// FUN_0018F390
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f390);
// FUN_0018F7B0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f7b0);
// FUN_0018F8A0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f8a0);
// FUN_0018F950
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f950);