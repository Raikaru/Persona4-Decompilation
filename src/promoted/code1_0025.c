#include "include_asm.h"
#include "type.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
s32 func_00452380(void *arg0);
extern s32 *func_00452560();
extern void func_0025f230(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_004ab680(s32 arg0);
extern void func_004ab140(s32 arg0);
extern s32 D_006367C0[];
extern void func_0045aeb0(s32 arg0, const char *arg1);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_00250ad0(s32 *arg0, u8 *arg1);
extern s32 func_0010a900(s32 arg0);
extern void func_0010cfa0(void *arg0, u16 arg1, s32 arg2);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern u32 func_00105ed0(void);
extern void func_00105fa0(s32 arg0);
extern s32 func_00120e20(s32 arg0, s32 arg1);
extern s32 func_00120ee0(s32 arg0);
extern void func_00120f00(s32 arg0);
extern void func_00120f40(s32 arg0, s64 arg1);
extern s32 iGpffffb480;

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
extern void func_0046b380(u8 *arg0, s32 arg1);
extern void func_0046d280(void *arg0);
extern u8 *func_0046d200(u32 arg0, u32 arg1);
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_0025ec10(s32 arg0, u8 *arg1);
extern void func_0025ec50(s32 arg0, u8 *arg1);
extern s32 func_0025ecd0(f32 farg0, f32 farg1, f32 farg2,
                         s32 arg0, s32 arg1, s32 arg2, void *arg3,
                         s32 arg4, s16 arg5, s16 arg6, f32 farg3,
                         f32 farg4, f32 farg5, void *arg7);
s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2,
                  s32 arg0, s32 arg1, s32 arg2, void *arg3,
                  s32 arg4, s32 arg5, s32 arg6,
                  f32 farg3, f32 farg4, f32 farg5);
extern s64 func_00248760(u16 arg0);
extern s32 func_0025ef20(u8 *arg0);
extern s32 func_0025f110(s32 arg0);
extern s32 func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
extern s32 func_0035af60(s32 arg0);
extern s32 func_00251f00(s32 arg0, s32 *arg1);
extern void func_00251fc0(s32 arg0, s32 arg1);
extern void func_00252050(s32 arg0, s32 arg1, s32 arg2);
extern void func_002519b0(s32 *arg0);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b7b0(f32 arg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045dfd0(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






// FUN_00250AD0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_00250ad0);
// FUN_00251570
u8 *func_00251570(s32 arg0, s32 arg1) {
    u8 *ptr;
    s32 i;

    if (arg1 != 0) {
        goto select_second;
    }
    ptr = (u8 *)(arg0 + 0x780);
    i = 0;
    goto first_test;
first_body:
    if ((*(u32 *)ptr & 1) == 0) {
        func_0043f9c8(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
first_test:
    if (i >= 0xC) {
        goto done;
    }
    goto first_body;
select_second:
    if ((u32)(arg1 - 1) >= 2U) {
        goto select_third;
    }
    ptr = (u8 *)(arg0 + 0x900);
    i = 0;
    goto second_test;
second_body:
    if ((*(u32 *)ptr & 1) == 0) {
        func_0043f9c8(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
second_test:
    if (i >= 4) {
        goto done;
    }
    goto second_body;
select_third:
    if (arg1 != 3) {
        goto done;
    }
    ptr = (u8 *)(arg0 + 0x980);
    i = 0;
    goto third_test;
third_body:
    if ((*(u32 *)ptr & 1) == 0) {
        func_0043f9c8(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
third_test:
    if (i < 3) {
        goto third_body;
    }
done:
    return NULL;
}
// FUN_002516F0
void func_002516f0(u8 *arg0, u8 *arg1) {
    s32 var_17;
    s32 *var_18_2;
    s32 *var_18_3;
    s32 var_17_2;
    s32 var_17_3;
    s32 *var_18;

    var_18 = (s32 *)(arg0 + 0x780);
    var_17 = 0;
    goto loop_5_test;
loop_5_body:
    if ((*var_18 & 1) && (func_00250ad0(var_18, arg1) != 0)) {
        *var_18 &= ~1;
    }
    var_18 = (s32 *)((u8 *)var_18 + 0x20);
    var_17 += 1;
loop_5_test:
    if (var_17 < 0xC) {
        goto loop_5_body;
    }
    var_18_2 = (s32 *)(arg0 + 0x900);
    var_17_2 = 0;
    goto loop_11_test;
loop_11_body:
    if ((*var_18_2 & 1) && (func_00250ad0(var_18_2, arg1) != 0)) {
        *var_18_2 &= ~1;
    }
    var_18_2 = (s32 *)((u8 *)var_18_2 + 0x20);
    var_17_2 += 1;
loop_11_test:
    if (var_17_2 < 4) {
        goto loop_11_body;
    }
    var_18_3 = (s32 *)(arg0 + 0x980);
    var_17_3 = 0;
    goto loop_17_test;
loop_17_body:
    if ((*var_18_3 & 1) && (func_00250ad0(var_18_3, arg1) != 0)) {
        *var_18_3 &= ~1;
    }
    var_18_3 = (s32 *)((u8 *)var_18_3 + 0x20);
    var_17_3 += 1;
loop_17_test:
    if (var_17_3 < 3) {
        goto loop_17_body;
    }
}
// FUN_00251850
void func_00251850(u8 *arg0) {
    s32 var_7;
    u8 *var_6;
    u8 *var_6_2;
    s32 temp_4;
    s32 temp_5;
    s32 var_5;

    var_6 = arg0 + 0x780;
    var_7 = 0;
    goto loop_test;
loop_4:
    temp_5 = *(s32 *)var_6;
    if (temp_5 & 1) {
        *(s32 *)var_6 = temp_5 | 8;
    }
    var_6 += 0x20;
    var_7 += 1;
loop_test:
    if (var_7 < 0xC) {
        goto loop_4;
    }
    var_6_2 = arg0 + 0x900;
    var_5 = 0;
    goto loop_9_test;
loop_9:
    temp_4 = *(s32 *)var_6_2;
    if (temp_4 & 1) {
        *(s32 *)var_6_2 = temp_4 | 8;
    }
    var_6_2 += 0x20;
    var_5 += 1;
loop_9_test:
    if (var_5 < 4) {
        goto loop_9;
    }
}
// FUN_002518D0
void func_002518d0(s32 arg0) {
    if ((arg0 > 0) && (arg0 < 10)) {
        func_0045aeb0(2, D_00635C00);
        return;
    }
    if (arg0 == 10) {
        func_0045aeb0(2, D_00635C00);
        return;
    }
    if (arg0 == 0) {
        func_0045aeb0(2, D_00635C20);
        return;
    }
    if (arg0 == 11) {
        func_0045aeb0(2, D_00635C40);
        return;
    }
    if (arg0 == 12) {
        func_0045aeb0(2, D_00635C60);
    }
}
// FUN_002519E0
/* Candidate reconstructed from retail dispatch and generated source. */
s32 func_002519e0(s32 arg0) {
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 *temp_2;
    u8 *temp_2_3;

    temp_2 = func_00452560();
    switch (*temp_2) {
    case 0:
        temp_2[4] = func_0025ef20(D_00635BF0);
        temp_2[0] = 2;
        temp_2[5] = func_0035adc0(arg0, func_00248760((u16)temp_2[1]), 0);
        temp_2[6] = func_0035adc0(arg0, -1, 0);
        temp_2[7] = func_00251f00(arg0, temp_2);
        goto block_15;
    case 1:
        return -1;
    case 2:
        if (func_0025f110(temp_2[4]) == 0) {
            goto block_15;
        }
        if (func_0035af60(temp_2[5]) == 0) {
            goto block_15;
        }
        if (func_0035af60(temp_2[6]) == 0) {
            goto block_15;
        }
        temp_2[0] = 3;
        func_00252050(temp_2[7], 0, 4);
        func_00252050(temp_2[7], 0, 5);
        func_00252050(temp_2[7], 0, 6);
        func_00252050(temp_2[7], 0, 7);
        func_00252050(temp_2[7], 0, 8);
        func_00252050(temp_2[7], 0, 9);
        func_00252050(temp_2[7], 0, 0);
        func_00252050(temp_2[7], 0, 1);
        func_00252050(temp_2[7], 0, 2);
        func_00252050(temp_2[7], 0, 3);
        func_00252050(temp_2[7], 2, 0);
        func_00252050(temp_2[7], 1, 0);
        goto block_15;
    case 3:
        temp_2_4 = temp_2[3] + 1;
        temp_2[3] = temp_2_4;
        if (temp_2_4 < 0x1E) {
            goto block_15;
        }
        temp_2[3] = 0;
        temp_2[0] = 4;
        func_00251fc0(temp_2[7], 1);
        goto block_15;
    case 4:
        temp_2_5 = temp_2[3] + 1;
        temp_2[3] = temp_2_5;
        if (temp_2_5 <= 0x1E) {
            goto block_15;
        }
        if ((D_008C024E[0] & 0x40) == 0) {
            goto block_15;
        }
        func_00251fc0(temp_2[7], 0);
        temp_2[3] = 0;
        temp_2[0] = 5;
        goto block_15;
    case 5:
        temp_2_6 = temp_2[3] + 1;
        temp_2[3] = temp_2_6;
        if (temp_2_6 < 0x28) {
            goto block_15;
        }
        temp_2[0] = 1;
        goto block_15;
    default:
        goto block_15;
    }
block_15:
    temp_2_3 = func_00460990();
    *(void **)(temp_2_3 + 8) = (void *)func_002519b0;
    *(s32 *)(temp_2_3 + 0x10) = arg0;
    func_00460ac0(D_007963D0, temp_2_3);
    return 0;
}
// FUN_00251CE0
void func_00251ce0(void)
{
    void *t;

    t = func_00452560();
    func_0025f230(*(s32 *)((u8 *)t + 0x10));
    (*jtbl_008873EC)(t);
}
// FUN_00251D30
u8 *func_00251d30(u8 *arg0) {
    s32 var_3;
    u8 *var_4;

    var_3 = 0;
    var_4 = arg0;
    goto loop_test;
loop_body:
    if ((*(s32 *)var_4 & 1) == 0) {
        return var_4;
    }
    var_4 += 0x78;
    var_3 += 1;
loop_test:
    if (var_3 < 0x10) {
        goto loop_body;
    }
    return NULL;
}
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
s32 func_0025d000(void) {
    s32 temp_16;
    s32 var_4;
    temp_16 = func_00105ed0();

    var_4 = temp_16 + func_0029cc00(0);
    if (var_4 <= 0x0098967F) {
        goto block_1;
    }
    var_4 = 0x0098967FU;
block_1:
    if (var_4 < 0) {
        var_4 = 0;
    }
    func_00105fa0(var_4);
    func_0029cf50(func_00105ed0());
    return 1;
}
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

/* measured probe: opt_propagation off tests d1b0 saved-register colouring. */
#pragma opt_propagation off
// FUN_0025D1B0
s32 func_0025d1b0(void) {
    s32 var_17;
    s64 temp_16;
    s32 var_18;
    s32 var_16;

    var_16 = 0;
    var_18 = 0;
    goto loop_4_test;
loop_4:
    temp_16 = func_00105ee0(var_18);
    if ((s32)temp_16 == func_0029cc00(0)) {
        var_16 = 1;
    }
    var_18 += 1;
loop_4_test:
    if (var_18 < 3) {
        goto loop_4;
    }
    if (var_16 != 0) {
        goto block_4;
    }
    var_17 = 0;
    goto loop_10_test;
loop_10:
    if ((s64)func_00105ee0(var_17) == 0) {
        func_00106000(var_17, (s32)(s64)(s16)func_0029cc00(0));
        var_16 = 1;
        goto block_4;
    }
    var_17 += 1;
loop_10_test:
    if (var_17 < 3) {
        goto loop_10;
    }
block_4:
    if (var_16 == 0) {
        func_00106000(2, (s32)(s64)(s16)func_0029cc00(0));
    }
    return 1;
}
/* measured probe: restore opt_propagation after d1b0. */
#pragma opt_propagation on
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
s32 func_0025d580(void) {
    u8 sp30[0x30];
    s16 sp60[18];
    s16 *var_6;
    s16 *var_5;
    u16 temp_18;
    s16 temp_2;
    s16 temp_3;
    s32 temp_2_2;
    s32 temp_16;
    s32 var_4;
    temp_16 = func_0029cc00(0) & 0xFFFF;
    var_6 = D_00636A40;
    var_5 = (s16 *)sp30;
    var_4 = 9;
    do {
        temp_3 = *var_6;
        temp_2 = *(var_6 + 1);
        var_6 += 2;
        var_4 -= 1;
        *var_5 = temp_3;
        *(var_5 + 1) = temp_2;
        var_5 += 2;
    } while (var_4 > 0);
    temp_18 = (u16)temp_16;
    if (temp_18 == 1) {
        return 1;
    }
    temp_2_2 = func_0010a900(temp_16);
    func_0010cfa0(
        sp60,
        *(u16 *)((u8 *)sp30 + ((temp_16 & 0xFFFF) * 4) + 2),
        temp_2_2);
    func_0043f810((void *)temp_2_2, sp60, 0x30);
    return 1;
}

// FUN_0025D650
s32 func_0025d650(void) {
    struct {
        f32 f0;
        f32 f1;
        s32 pad;
        s16 h0;
        s16 h1;
    } local;
    s32 temp_16;
    s32 temp_17;

    local.f0 = (f32)func_0029cc00(0);
    local.f1 = (f32)func_0029cc00(1);
    temp_17 = func_0029cc00(2);
    temp_16 = func_0029cc00(3);
    if (func_0029d020() == 0) {
        local.h0 = (s16)temp_17;
        local.h1 = (s16)temp_16;
        iGpffffb480 = func_00120e20(0, *(s32 *)&local.h0);
        goto block_4;
    }
    if (func_00120ee0(iGpffffb480) != 0) {
        func_00120f00(iGpffffb480);
        func_00120f40(iGpffffb480, *(s64 *)&local.f0);
        func_0029cf50(iGpffffb480);
        iGpffffb480 = 0;
        return 1;
    }
block_4:
    return 0;
}
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
void func_0025d850(f32 farg0, f32 farg1, f32 farg2, s32 arg0) {
    struct {
        u8 spB0[0x100];
        f32 sp1B0[0x7C];
    } local;
    s32 var_19;
    f32 *var_18;
    u8 *var_17;
    u8 temp_16;
    u8 temp_21;
    u8 temp_22;
    u8 temp_23;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f25;
    f32 temp_f2;
    f32 temp_f2_2;

    var_18 = local.sp1B0;
    var_17 = local.spB0;
    var_19 = 0;
    temp_16 = (u8)((u32)arg0 >> 0x18);
    temp_21 = (u8)((u32)arg0 >> 0x10);
    temp_22 = (u8)((u32)arg0 >> 8);
    temp_23 = (u8)arg0;
    goto loop_test;
loop_body:
    temp_f20 = 12.0f * (f32)var_19;
    temp_f25 = fGpffff8200 * temp_f20;
    temp_f24 = func_0044b7b0(temp_f25);
    temp_f2 = 8.5f * func_0044b610(temp_f25);
    var_18[0] = p4_0025_mul_add(8.5f, temp_f24, farg0 + temp_f2);
    var_18[1] = p4_0025_add(
        p4_0025_mul_add(8.5f, -temp_f24, farg1), temp_f2);
    temp_f24_2 = fGpffff8200 * (6.0f + temp_f20);
    temp_f20_2 = func_0044b7b0(temp_f24_2);
    temp_f2_2 = 7.0f * func_0044b610(temp_f24_2);
    var_18[2] = p4_0025_mul_add(7.0f, temp_f20_2, farg0 + temp_f2_2);
    var_18[3] = p4_0025_add(
        p4_0025_mul_add(7.0f, -temp_f20_2, farg1), temp_f2_2);
    var_18 += 4;
    var_17[0] = temp_16;
    var_17[1] = temp_21;
    var_17[2] = temp_22;
    var_17[3] = temp_23;
    var_17[4] = temp_16;
    var_17[5] = temp_21;
    var_17[6] = temp_22;
    var_17[7] = temp_23;
    var_17 += 8;
    var_19 += 1;
loop_test:
    if (var_19 < 0x1E) {
        goto loop_body;
    }
    var_18[0] = local.sp1B0[0];
    var_18[1] = local.sp1B0[1];
    var_18[2] = local.sp1B0[2];
    var_18[3] = local.sp1B0[3];
    var_17[0] = (u8)((u32)arg0 >> 0x18);
    var_17[1] = (u8)((u32)arg0 >> 0x10);
    var_17[2] = (u8)((u32)arg0 >> 8);
    var_17[3] = (u8)arg0;
    var_17[4] = (u8)((u32)arg0 >> 0x18);
    var_17[5] = (u8)((u32)arg0 >> 0x10);
    var_17[6] = (u8)((u32)arg0 >> 8);
    var_17[7] = (u8)arg0;
    func_00364c50();
    func_0045dfd0(local.spB0, local.sp1B0, farg2, 0x3E, 4, 1);
    local.spB0[0] = 0xDC;
    local.spB0[1] = 0xDC;
    local.spB0[2] = 0xDC;
    local.spB0[3] = 0xFF;
    temp_f0 = 180.0f;
    func_0045ee00((s32)farg0, (s32)farg1, local.spB0, 8, temp_f0, farg2, 1);
    func_00364c70();
}
// FUN_0025E9E0
void func_0025e9e0(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4,
                   f32 farg0, f32 farg1, f32 farg2) {
    func_0025ea20(farg0, farg1, farg2, arg0, arg1, arg2, arg3, arg4,
                  0, 0, 0.0f, 1.0f, 1.0f);
}
/* measured: best plain-C body object 484B/window 496B, normalized_diff 10; residual offsets 0xE0,0xE8,0x104,0x108,0x10C,0x13C,0x144,0x160,0x164,0x168 (plus three zero-padding tail words). Corrected callee declarations: func_0046d200(u32,u32), func_0046b380(u8*,s32), func_00460ac0(u8*,u8*); func_0046d280 remains caller-specific void* because retail passes $a0 despite its verified void definition. Conversion destination/register probes did not improve nd 10; archived at build/L25_0025ea20_body.c. */
// FUN_0025EA20
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ea20);
/* measured: best plain-C body object 588B/window 592B, normalized_diff 10; residual offsets 0x104,0x10C,0x128,0x12C,0x130,0x160,0x168,0x184,0x188,0x18C (plus one zero-padding tail word). Corrected callee declarations: func_0046d200(u32,u32), func_0046b380(u8*,s32), func_00460ac0(u8*,u8*); func_0046d280 remains caller-specific void* because retail passes $a0 despite its verified void definition. Conversion destination/register probes did not improve nd 10; archived at build/L25_0025ecd0_body.c. */
// FUN_0025ECD0
INCLUDE_ASM("asm/nonmatchings/code1_0025", func_0025ecd0);
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
    func_0025ecd0(farg0, farg1, farg2, arg0, arg1, arg2, (void *)arg3, arg4,
                  0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
/* measured: plain C reproduces the complete 0x24C-byte body and 0xC0-byte frame; only the two float-to-u16 conversions retain the MWCCPS2 $v0/$v1 colouring floor (normalized_diff 10, object 588B versus 592B window). Parked because nd <= 25. Committed at nd 10. */
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