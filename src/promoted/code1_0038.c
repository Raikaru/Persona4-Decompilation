#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void (*D_008873ec[])(s32);

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

s32 datGetFlag(u32 arg0);

extern u8 *D_007246AC;
void func_00389180(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_0064EEB0[];
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0046d730(u8 *arg0, s32 arg1);



// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}



// FUN_00388D20
void func_00388d20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x4;
}

// FUN_00388D40
void func_00388d40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFFB;
}

// FUN_00388D60
void func_00388d60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 6);
    *(u16 *)(p + 0x4C) |= 2;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388E00
void func_00388e00(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x2;
}

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}



// FUN_00388E40
void func_00388e40(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_0043f9c8(p + 4, 0, 0x18);
    *(u16 *)(p + 0x4C) |= 1;
    func_00389180(arg0);
    func_0045af60(1, 3, 5, 0xD);
}

// FUN_00388EE0
void func_00388ee0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4) | 0x4;
}

// FUN_00388F20
void func_00388f20(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) | 0x10;
}

// FUN_00388F40
void func_00388f40(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFFEF;
}

// FUN_00388F60
void func_00388f60(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x20, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x20);
}

// FUN_00388FB0
void func_00388fb0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x20) | 0x2;
}

// FUN_00388FD0
void func_00388fd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x24, 0, 4);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x40);
}

// FUN_00389020
void func_00389020(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x24) | 0x4;
}

// FUN_00389040
void func_00389040(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x28, 0, 0x18);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x80);
}

/* measured: nd 1. Two shapes were load-bearing here and are worth keeping:
   advancing the slot pointer (`slot += n; slot[1] = ...`) instead of indexing
   `slot[n + 1]` is what stops b210 folding the 0x28 sub-object offset into the
   store displacement (nd 54 -> nd 3), and spelling the overflow guard `> 4`
   rather than `>= 5` is what makes it compare through $at like retail
   (nd 3 -> nd 1). The one remaining word is the commutative addu: retail
   `addu $v1,$v1,$a2`, b210 `addu $v1,$a2,$v1`. A static inline helper taking
   (offset, base) - the usual cure for that - wrecks the allocation here
   (nd 20) in all four call shapes probed. Committed at nd 1. */
// FUN_00389090 NONMATCHING
#ifdef NON_MATCHING
void func_00389090(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = *(s32 *)(p + 0x3C);

    *(s32 *)(p + 0x3C) = n + 1;
    slot = n + slot;
    slot[1] = arg1;
    if (*(s32 *)(p + 0x3C) > 4) {
        func_0046d730(D_0064EEB0, 0x745);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0038", func_00389090);
#endif

// FUN_003890F0
void func_003890f0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFF7F;
}

// FUN_00389110
void func_00389110(u8 *arg0) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s16 *)(temp_3 + 0x1E) = 0;
    *(u16 *)(temp_3 + 0x4C) = (u16) (*(u16 *)(temp_3 + 0x4C) | 8);
    func_0045af60(1, 5, 5, 0);
}

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}



// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}



// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}



// FUN_00389200
void func_00389200(u8 *arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_16;
    u8 *temp_17;

    temp_17 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_16 = (u8 *)(temp_17 + 0x46);
    func_0043f9c8(temp_16, 0, 6);
    *(s8 *)(temp_16 + 2) = arg1;
    *(s8 *)(temp_16 + 3) = arg2;
    *(s8 *)(temp_16 + 4) = arg3;
    *(u16 *)(temp_17 + 0x4C) = (u16) (*(u16 *)(temp_17 + 0x4C) | 0x200);
}

// FUN_003892C0
void func_003892c0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0xFDFF;
}

// FUN_003892E0
void func_003892e0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x46, 0, 6);
    *(u16 *)(temp_16 + 0x4C) = (u16) (*(u16 *)(temp_16 + 0x4C) | 0x400);
}

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}



// FUN_00389350
void func_00389350(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4A) | 0x2;
}

// FUN_0038CE30
s32 func_0038ce30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 0xC) = 0;
    func_00460ac0(D_00794990, p + 8);
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    func_00460ac0(D_00794E40, p + 0x38);
    return 0;
}

// FUN_0038CE90
void func_0038ce90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0038D160
void func_0038d160(u8 *arg0) {
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    temp_17 = (u8 *)(temp_16 + 0x1A4);
    func_0043f9c8(temp_17, 0, 6);
    *(u16 *)(temp_17 + 4) = (u16) *(u16 *)((u8 *)(*(u8 **)(temp_16 + 0)) + 0x1F1D8);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 2);
}

// FUN_0038D1D0
void func_0038d1d0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1A6) | 0x2;
}

// FUN_0038D2A0
void func_0038d2a0(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x168) | 0x1;
}

// FUN_0038D2C0
void func_0038d2c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)(*(u8 **)(arg0 + 0x38));
    func_0043f9c8(temp_16 + 0x1B4, 0, 4);
    *(u16 *)(temp_16 + 4) = (u16) (*(u16 *)(temp_16 + 4) | 0x20);
}

// FUN_0038D310
void func_0038d310(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) = *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x1B6) | 0x2;
}

// FUN_0038D660
s32 func_0038d660(u8 *arg0) {
    s32 *temp_16;

    temp_16 = (s32 *)(*(s32 **)(arg0 + 0x38));
    func_00374910(*temp_16);
    func_0038d9f0(arg0);
    func_0038d330(temp_16);
    return 0;
}

// FUN_0038DD60
void func_0038dd60(void)
{
}

// FUN_0038DD70
void func_0038dd70(void)
{
}

// FUN_0038DD80
void func_0038dd80(void)
{
}

// FUN_0038DD90
void func_0038dd90(u8 *arg0) {
    s32 i;

    *(s32 *)arg0 = 0;
    arg0[0x122C] = 0xFF;
    arg0[0x122D] = 0xFF;
    arg0[0x122E] = 0xFF;
    arg0[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)(arg0 + i * 0x90 + 4) = 0;
    }
    iGpffffb5b0 = arg0;
}

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !datGetFlag(0x1472);
}



// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}


// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on


// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off
