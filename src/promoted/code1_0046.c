#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb034;
extern s32 iGpffffbaf8;
extern s32 iGpffffbab4;
extern s32 iGpffffbab0;
extern s32 D_008E4B30[];
extern s32 D_008E4B34[];
extern s32 D_008E4B38[];
extern u8 D_008E4800[];
extern void func_0043a978(void);
extern void func_004316a8(s32 arg0);
extern s32 func_00431928(void *a, u8 *b);

extern u8 *(*D_008873F8[])(...);
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])(...);
extern void func_00452730(s32 arg0);

extern void (*jtbl_008873EC[])(...);

extern s32 D_00724BEC;
extern s32 D_00724BF0;

extern void func_0046ab90(u8 *arg0);
extern u8 *D_00724C08;

extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;
extern void func_00451de0(u8 *name, s32 prio, s32 a2, s32 a3, void *entry, s32 a5, s32 a6);
extern void func_004633f0(void);
extern void func_00468ff0(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00460ac0(char *name, u8 *task);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern s32 func_004426e8(char *a, char *b);
extern s32 uGpffffb230;
extern s32 D_00724BC8;
extern s32 func_0042ba70(void);
extern void func_0042ba20(void);
extern void func_004216e0(s32 handle, s32 *out);
extern void func_00421770(s32 handle);
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern void (*D_00887300[])(s32 arg0, s32 arg1);



// FUN_004601C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004601c0);
// FUN_004604D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004604d0);
// FUN_00460910
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00460910);
// FUN_00460990
u8 *func_00460990(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B88, 0x41002);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_004609F0
u8 *func_004609f0(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B8C, 0x41003);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_00460A50
void func_00460a50(s32 arg0)
{
    jtbl_008873FC[0](D_00724B8C, arg0);
}



// FUN_00460A80
void func_00460a80(s32 arg0, s32 arg1)
{
    memset((void *)arg0, 0, arg1 * 0x30);
    func_00452730(D_00724B88);
}



// FUN_004614B0
void func_004614b0(void) {
    void (**tbl)(s32, s32) = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
}

// FUN_00461530
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461530);
// FUN_00461560
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461560);
// FUN_00461A40
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461a40);
// FUN_00461BE0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461be0);
// FUN_00462230
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00462230);
// FUN_004623A0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004623a0);
// FUN_00462BF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00462bf0);
// FUN_00462DF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00462df0);
// FUN_004633C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004633c0);
// FUN_004633F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004633f0);
// FUN_00463520
void func_00463520(void) {
    func_00451de0(D_00712670, 0x12C, 0, 0, (void *)func_004633f0, 0, 0);
}

// FUN_00463930
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00463930);
// FUN_004645E0
void func_004645e0(void) {
    func_0043a978();
    func_004316a8(0);
    D_008E4B30[0] = 2;
    D_008E4B34[0] = 2;
    D_008E4B38[0] = 0;
    iGpffffbab4 = func_00431928(D_008E4B30, D_008E4800);
    iGpffffbab0 = 0;
}

// FUN_00464670
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00464670);
// FUN_00466280
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00466280);
// FUN_00466600
void func_00466600(void) {
    s32 sp20[12];
    s32 r;

    r = func_0042ba70();
    if (uGpffffb230 != 0) {
        func_004216e0(D_00724BC8, sp20);
        if (sp20[0] == 0xC) {
            goto call;
        }
        if (sp20[0] != 8) {
            goto skip;
        }
call:
        func_00421770(D_00724BC8);
    }
skip:
    if (r == 0) {
        func_0042ba20();
    }
}

// FUN_004667D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004667d0);
// FUN_004669D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004669d0);
// FUN_004673C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004673c0);
// FUN_00467880
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467880);
// FUN_00467BD0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467bd0);
// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}



// FUN_004680F0
s32 func_004680f0(u8 *arg0, s8 *arg1) {
    u8 *temp_6;

    temp_6 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *arg1 = 0;
    if (*(s16 *)(temp_6 + 0x80F80) == 3) {
        if (*(s32 *)(temp_6 + 0x80F88) != 0) {
            func_00442830(arg1, temp_6 + 0x80F90, temp_6);
        }
        return 1;
    }
    return 0;
}

// FUN_00468A10
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468a10);
// FUN_00468D10
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468d10);
// FUN_00468FA0
s32 func_00468fa0(u8 *arg0) {
    u8 *ctx;
    u8 *task;

    ctx = *(u8 **)(arg0 + 0x38);
    task = func_00460990();
    *(void **)(task + 8) = (void *)func_00468ff0;
    *(u8 **)(task + 0x10) = ctx;
    func_00460ac0(*(char **)(ctx + 0x218), task);
    return 0;
}

// FUN_00468FF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468ff0);
// FUN_0046A020
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a020);
// FUN_0046A110
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a110);
// FUN_0046A1E0
s32 func_0046a1e0(void)
{
    return iGpffffb034;
}

// FUN_0046A1F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a1f0);
// FUN_0046A2C0
s32 func_0046a2c0(void)
{
    return iGpffffbaf8;
}

// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}



// FUN_0046A2E0
void func_0046a2e0(u8 *arg0, s32 arg1) {
    u32 i;

    D_00724C04 = arg0;
    D_00724C00 = arg0 + arg1;
    D_00724BFC = 0x1F4;
    i = 0;
    while (i < D_00724BFC) {
        *(s32 *)(arg0 + i * 8) = 0;
        *(s32 *)(arg0 + i * 8 + 4) = 0;
        i++;
    }
    D_00724BF8 = 0;
    D_00724BF4 = 0;
}

// FUN_0046A340
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a340);
// FUN_0046A430
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a430);
// FUN_0046A770
/* The list walk is written with an explicit goto loop: retail tests the
   cursor at the TOP of the loop and both early exits are out of line, which
   the natural `while (p != NULL)` form does not reproduce (nd 57). */
u8 *func_0046a770(char *arg0) {
    u8 *p;

    p = D_00724C08;
loop:
    if (p == NULL) {
        return NULL;
    }
    if (func_004426e8((char *)(p + 2), arg0) == 0) {
        return p;
    }
    p = *(u8 **)(p + 0x238);
    goto loop;
}

// FUN_0046A7F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a7f0);
// FUN_0046AB40
void func_0046ab40(void)
{
    u8 *var_16 = D_00724C08;

loop_1:
    if (var_16 != NULL) {
        func_0046ab90(var_16);
        var_16 = *(u8 **)(var_16 + 0x238);
        goto loop_1;
    }
}



// FUN_0046D6B0
void func_0046d6b0(s32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}

// FUN_0046D700
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d700);
// FUN_0046D730
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d730);
// FUN_0046D740
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d740);
// FUN_0046D750
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d750);
// FUN_0046E7F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046e7f0);
// FUN_0046E850
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046e850);
// FUN_0046EA10
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ea10);
// FUN_0046EA50
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ea50);
// FUN_0046EA60
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ea60);
// FUN_0046EC70
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ec70);
// FUN_0046F2B0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046f2b0);