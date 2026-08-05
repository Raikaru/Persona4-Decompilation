#include "include_asm.h"
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 D_006367C0[];

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);
void func_0029cf50(s32 arg0);
s32 func_00110580(s64 arg0);

s32 func_0029cc00(s32 arg0);
s16 func_00110600(s32 arg0, s32 arg1);
void func_00106300(s64 arg0);
void func_00106310(s32 arg0);
void func_00106320(s32 arg0);
s32 func_001106f0(s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_0026bc10(s32 arg0, s32 arg1);
s32 func_00109bf0(s32 arg0, s32 arg1);

s32 func_0029d020(void);
void func_001227d0(void);
s32 func_001227f0(void);



// FUN_0025C310
void func_0025c310(void) {
    func_00452380(D_006367C0);
}



// FUN_0025C340
s32 func_0025c340(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    func_001104d0(func_001060b0(), &sp1C, &sp18);
    func_0029cf50(sp1C);
    return 1;
}



// FUN_0025C390
s32 func_0025c390(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    func_001104d0(func_001060b0(), &sp1C, &sp18);
    func_0029cf50(sp18);
    return 1;
}



// FUN_0025C3E0
s32 func_0025c3e0(void) {
    func_0029cf50(func_00110580(func_001060b0()));
    return 1;
}



// FUN_0025C450
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025c450);

// FUN_0025C4B0
s32 func_0025c4b0(void) {
    s32 sp3C;
    s32 sp38;
    s32 temp_16;
    s32 temp_17;

    sp3C = 0;
    sp38 = 0;
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_001104d0(func_001060b0(), &sp3C, &sp38);
    if ((sp3C == temp_17) && (sp38 == temp_16)) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}



// FUN_0025C560
s32 func_0025c560(void) {
    s32 temp_18;
    s32 temp_17;
    s32 temp_16;

    temp_18 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    temp_16 = func_0029cc00(2);
    func_00106300(func_00110600(temp_18, temp_17));
    func_00106310(temp_16 & 0xFF);
    func_00106320(1);
    return 1;
}



// FUN_0025C600
s32 func_0025c600(void) {
    s32 temp_19;
    s32 temp_18;
    s32 temp_17;
    s32 temp_16;

    temp_19 = func_0029cc00(0);
    temp_18 = func_0029cc00(1);
    temp_17 = func_0029cc00(2);
    temp_16 = func_0029cc00(3);
    if (func_001106f0(func_001060b0(), temp_19, temp_18, temp_17, temp_16) == 1) {
        func_0029cf50(1);
    } else {
        func_0029cf50(0);
    }
    return 1;
}



// FUN_0025C730
s32 func_0025c730(void) {
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0026bc10(((temp_16 & 0x3FF) | 0xC00) & 0xFFFF, temp_17 & 0xFF);
    return 1;
}



// FUN_0025CDD0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025cdd0);

// FUN_0025CE40
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ce40);

// FUN_0025CE90
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ce90);

// FUN_0025CF00
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025cf00);

// FUN_0025CF70
s32 func_0025cf70(void) {
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0029cf50(func_00109bf0(temp_16 & 0xFFFF, temp_17 & 0xFFFF) & 0xFF);
    return 1;
}



// FUN_0025D090
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d090);

// FUN_0025D150
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d150);

// FUN_0025D2D0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d2d0);

// FUN_0025D350
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d350);

// FUN_0025D3C0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d3c0);

// FUN_0025D440
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d440);

// FUN_0025D4B0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d4b0);

// FUN_0025D520
s32 func_0025d520(void)
{
    return 1;
}

// FUN_0025D530
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d530);

// FUN_0025D760
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d760);

/* `x > 0xA` here, not the equivalent `x >= 0xB`: b210 compiles `>= K` by
   materialising the comparison into $v0, and `> K-1` by branching through the
   assembler temp as retail does (slti $at,$v0,0xB / bnez $at). Identical
   semantics, different branch form - this was the whole nd-2 residual. Found by
   permute_ast (MATCH at 113 compiles) and reduced with permute_min; the winner
   had rewritten the constant as `> (0xB & 0xFFFF) - 1`, which is the same thing.
   Un-chaining the && and negating the inner test do NOT help - both stay nd 2. */
// FUN_0025D7E0
s32 func_0025d7e0(void) {
    if (func_0029d020() == 0xA) {
        func_001227d0();
        goto block_5;
    }
    if ((func_0029d020() > 0xA) && (func_001227f0() != 0)) {
        return 1;
    }
block_5:
    return 0;
}
