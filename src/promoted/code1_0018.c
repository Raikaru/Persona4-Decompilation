#include "include_asm.h"
#include "type.h"
extern void func_0048a000();
extern void func_00185370();

extern void (*jtbl_008873EC[])(void *);

extern s32 D_0076428C;

void func_0018e780(s32 arg0);



extern void func_003e0f40(s32 arg0);
extern s32 func_00457a90(u8 *arg0, u8 *arg1);
extern void func_003c42b0(u8 *arg0, s32 arg1);
extern u8 D_005F5438[];
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 a, u8 *b);
extern void func_003f6800(s32 a, f32 fp);
extern u8 D_005F5360[];

// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_001852F0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001852f0);

// FUN_00185370
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185370);

// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

// FUN_00185830
void func_00185830(void)
{
    func_0048a000();
}

// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
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

// FUN_0018BAD0
void func_0018bad0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018BED0
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018bed0);

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

// FUN_0018C700
void func_0018c700(f32 fp0) {
    s32 a;
    s32 b;

    a = func_003ef6d0();
    b = func_003ef650(a, D_005F5360);
    func_003f6800(b, fp0);
}

// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
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
