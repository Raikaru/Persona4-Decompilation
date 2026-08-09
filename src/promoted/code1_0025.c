#include "include_asm.h"
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 *func_00452560();
extern void func_0025f230(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_004ab680(s32 arg0);
extern void func_004ab140(s32 arg0);
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

s32 func_001060c0(void);
s8 func_00110960(s16 arg0, s32 arg1);
float func_0029cd50(s32 arg0);
s16 func_00105010(s16 arg0, float arg1);
s16 func_00104f10(s16 arg0);
void func_0010a840(u16 arg0, u16 arg1, s8 arg2);
void func_00106620(s16 arg0, s32 arg1);
s16 func_00105ee0(s32 arg0);
void func_00106000(s32 arg0, s32 arg1);
s16 func_00106cd0(s16 arg0, s16 arg1);
void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
s32 func_00452490(s32 arg0);
void func_00120f20(s32 arg0);
void func_002aa300(s32 arg0, s32 arg1);
s32 func_002aa3f0(void);
extern s32 func_00481450(void);
extern void func_00481440(s32 arg0);
extern void func_004ab8a0(s32 arg0);
extern void func_004ab360(s32 arg0);
extern void func_0046b380(void *arg0, s32 arg1);
extern void func_0046d280(void *arg0);
extern s32 func_0025ecd0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, s32 arg5, s32 arg6, void *arg7,
                         f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                         f32 farg4, f32 farg5);



// FUN_00250AD0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_00250ad0);
// FUN_00251570
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_00251570);
// FUN_002516F0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_002516f0);
// FUN_00251850
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_00251850);
// FUN_002518D0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_002518d0);
// FUN_002519E0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_002519e0);
// FUN_00251CE0
void func_00251ce0(void)
{
    void *t;

    t = func_00452560();
    func_0025f230(*(s32 *)((u8 *)t + 0x10));
    (*jtbl_008873EC)(t);
}
// FUN_00251D30
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_00251d30);
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



// FUN_0025C420
s32 func_0025c420(void) {
    func_0029cf50(func_001060c0() & 0xFF);
    return 1;
}
// FUN_0025C450
s32 func_0025c450(void) {
    s16 temp_16;

    temp_16 = func_001060b0();
    func_0029cf50((s32)func_00110960(temp_16, func_001060c0() & 0xFF));
    return 1;
}

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
s32 func_0025cdd0(void) {
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    func_0029cf50((s32)func_00105010((s16)temp_16, func_0029cd50(1)));
    return 1;
}

// FUN_0025CE40
s32 func_0025ce40(void) {
    func_0029cf50((s32)func_00104f10((s16)func_0029cc00(0)));
    return 1;
}

/* measured: preserving the raw third-call result in s32 before masking the first two arguments reproduces retail's setup order; exact match nd 0 (obj 112B/window 112B). */
// FUN_0025CE90
s32 func_0025ce90(void) {
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_18 = func_0029cc00(2);
    func_0010a840(temp_17 & 0xFFFF, temp_16 & 0xFFFF, (s8)temp_18);
    return 1;
}

// FUN_0025CF00
s32 func_0025cf00(void) {
    s32 temp_16;
    s32 temp_17;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_00109d80(temp_17 & 0xFFFF, temp_16 & 0xFFFF, func_0029cc00(2));
    return 1;
}

// FUN_0025CF70
s32 func_0025cf70(void) {
    s32 temp_16;
    s32 temp_17;

    temp_16 = func_0029cc00(0);
    temp_17 = func_0029cc00(1);
    func_0029cf50(func_00109bf0(temp_16 & 0xFFFF, temp_17 & 0xFFFF) & 0xFF);
    return 1;
}



// FUN_0025D000
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d000);
// FUN_0025D090
s32 func_0025d090(void) {
    if (func_0029d020() == 0) {
        func_001029a0(0x1C, 0, 0, 0);
        goto block_4;
    }
    if (func_002a2710() == 0) {
        return 1;
    }
block_4:
    return 0;
}

// FUN_0025D150
s32 func_0025d150(void) {
    s16 temp_16;

    temp_16 = func_0029cc00(0);
    func_00106620(temp_16, func_0029cc00(1) & 0xFF);
    return 1;
}

// FUN_0025D1B0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d1b0);
// FUN_0025D2D0
s32 func_0025d2d0(void) {
    s16 temp_16;
    s32 var_17;

    var_17 = 0;
    while (var_17 < 3) {
        temp_16 = func_00105ee0(var_17);
        if (temp_16 == func_0029cc00(0)) {
            func_00106000(var_17, 0);
        }
        var_17++;
    }
    return 1;
}

// FUN_0025D350
s32 func_0025d350(void) {
    s16 temp_16;
    s16 temp_5;

    temp_16 = func_0029cc00(0);
    temp_5 = func_0029cc00(1);
    func_0029cf50((s32)func_00106cd0(temp_16, temp_5));
    return 1;
}

// FUN_0025D3C0
s32 func_0025d3c0(void) {
    s16 a;
    s16 b;

    a = func_0029cc00(0);
    b = func_0029cc00(1);
    func_00106d40(a, b, (s16)func_0029cc00(2));
    return 1;
}

// FUN_0025D440
s32 func_0025d440(void) {
    s32 temp_2;

    if (func_0029d020() == 0) {
        func_002aa300(0, 1);
        goto block_4;
    }
    temp_2 = func_002aa3f0();
    if (temp_2 != 0) {
        func_0029cf50(temp_2);
        return 1;
    }
block_4:
    return 0;
}

// FUN_0025D4B0
s32 func_0025d4b0(void) {
    s32 temp_2;

    if (func_0029d020() == 0) {
        func_002aa300(0, 0);
    } else {
        temp_2 = func_002aa3f0();
        if (temp_2 != 0) {
            func_0029cf50(temp_2);
            return 1;
        }
    }
    return 0;
}

// FUN_0025D520
s32 func_0025d520(void)
{
    return 1;
}

// FUN_0025D530
s32 func_0025d530(void)
{
    func_0029cf50((s16)func_00105ee0(func_0029cc00(0)));
    return 1;
}

/* measured: explicit else placement reproduces retail's out-of-line return-one
   block. Object 120B/window 128B; normalized_diff 0, with the remaining eight
   bytes being retail zero padding. */

// FUN_0025D580
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d580);

// FUN_0025D650
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d650);
// FUN_0025D760
s32 func_0025d760(void) {
    s32 temp_16;

    temp_16 = func_0029cc00(0);
    if (func_0029d020() == 0) {
        if (func_00452490(temp_16) != 0) {
            func_00120f20(temp_16);
        }
    } else {
        return 1;
    }
    return 0;
}

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

// FUN_0025D850
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025d850);
// FUN_0025E9E0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025e9e0);
// FUN_0025EA20
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ea20);
// FUN_0025EC10
void func_0025ec10(s32 arg0, u8 *arg1) {
    func_0046b380(arg1, 1);
    func_0046d280(arg1);
}
// FUN_0025EC50
void func_0025ec50(s32 arg0, u8 *arg1) {
    func_0046b380(arg1, 0);
    func_0046d280(arg1);
}
// FUN_0025EC90
void func_0025ec90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   void *arg5, f32 farg0, f32 farg1, f32 farg2) {
    func_0025ecd0(arg0, arg1, arg2, arg3, arg4, 0, 0, arg5,
                  farg0, farg1, farg2, 0.0f, 1.0f, 1.0f);
}
// FUN_0025ECD0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ecd0);
// FUN_0025F960
s32 func_0025f960(void) {
    s32 var_17;
    s32 *p;
    s32 temp_3;

    p = func_00452560();
    if (p[4] != 0) {
        var_17 = func_00481450();
        func_00481440(p[4]);
    }
    temp_3 = p[0];
    switch (temp_3) {
    case 0:
        func_004ab8a0(p[1]);
        p[2] = p[2] + 1;
        break;
    case 1:
        func_004ab360(p[1]);
        p[2] = p[2] + 1;
        break;
    }
    if (p[4] != 0) {
        func_00481440(var_17);
    }
    return 0;
}
// FUN_0025FA30
void func_0025fa30(void)
{
    s32 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560();
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        func_004ab680(temp_2[1]);
        break;
    case 1:
        func_004ab140(temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}
// FUN_0025FF60
s32 func_0025ff60(void)
{
    s32 *p;
    p = func_00452560();
    return p[0];
}