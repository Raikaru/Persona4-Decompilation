/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(u8 *);
extern u16 *D_00764658;

s32 func_00452380(void *arg0);
extern u8 D_0063E918[];
void func_00452080(s32 arg0);

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00451fc0(void *a, void *b, s32 c, s32 d, s32 e, void *f, void *g, void *h);
extern s32 func_002aa890(u8 *arg0);
extern void func_002aa450(void);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern s32 func_002abf70(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_003f6690(s32 arg0, s32 *arg1);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025f3f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         void *arg4, s32 arg5, f32 farg0, f32 farg1,
                         f32 farg2);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *arg0, void *arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern void func_002a1ef0(u8 *arg0);
extern f32 fGpffff8204;
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern void func_0029fbb0(u8 *arg0, s32 arg1);
extern s32 func_002a2ca0(u8 *arg0);
extern s32 iGpffffb530;
extern void func_002baac0(void *arg0);
extern void func_002bad10(s32 arg0);
extern void func_002baf40(s32 arg0);
extern void func_002bb050(s32 arg0);
extern s32 func_002bb0e0(void);
extern void func_002bb4e0(void);
extern s32 func_002bb600(void);
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 func_002bb700(void);
extern void func_002bbcc0(void);
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;
extern s32 func_00274ed0(f32 arg0, f32 arg1, f32 arg2, s32 arg3,
                         s32 arg4, s32 arg5, void *arg6, s32 arg7,
                         s32 arg8);
extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002bdb50(s32 arg0, s8 arg1);
extern void func_002bdea0(void);
extern s32 func_002e7510(s32 arg0);
extern void func_00308f40(void);
extern s32 func_003493b0(u8 *arg0);
extern s32 func_00452490(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct P4_002aa450_Pair {
    s64 bits;
    f32 value;
} P4_002aa450_Pair;
typedef struct P4_002aa450_Work {
    u8 matrix[0x40];
    P4_002aa450_Pair pair4;
    P4_002aa450_Pair pair3;
    P4_002aa450_Pair pair2;
    P4_002aa450_Pair pair1;
    P4_002aa450_Pair pair0;
} P4_002aa450_Work;
static inline f32 p4_002aa450_mul(f32 left, f32 right) {
    return left * right;
}
extern void func_00366960(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                          f32 farg0, s16 arg_sp0, s32 *arg_sp8, s32 arg_sp10);
extern void func_003e0870(void *arg0, void *arg1, f32 farg0, s32 arg2);
extern void func_003e0a90(void *arg0, void *arg1, s32 arg2);
extern void func_003e4320(void *arg0, void *arg1, void *arg2);
extern f32 fGpffff855c;
extern u8 D_0063EDF0[];
extern u8 D_0063EDF8[];
extern u8 D_0063EE00[];
extern u8 D_0063EE08[];
extern u8 D_0063EE10[];
extern u8 D_0063EE18[];
extern u8 D_0063EE20[];
extern u8 D_0063EE28[];
extern u8 D_0063EE30[];
extern u8 D_0063EE38[];
extern u8 D_00882F28[];
extern u8 D_00882F2C[];
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;
extern void func_0010d490(u8 *arg0, u8 *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void func_00122640(s32 arg0, s32 arg1);
extern void func_0029ebf0(u8 *arg0, s32 arg1);
extern s32 func_0029f070(u8 *arg0);
extern void func_002a12e0(u8 *arg0, s32 arg1);
extern s32 func_00442c30(void *arg0, void *arg1, s32 arg2);



// FUN_002A02F0
void func_002a02f0(u8 *arg0, s32 arg1) {
    u8 *temp_4;
    s32 i;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if ((arg1 == 0) && (*(s32 *)(temp_4 + 0x14) != 1)) {
        for (i = 0; i < 6; i++) {
            *(s16 *)(temp_4 + (i * 4) + 0x1C38) = 0;
        }
    }
    func_0029fbb0(arg0, 0);
    func_0029fbb0(arg0, 1);
    func_0029fbb0(arg0, 2);
    func_0029fbb0(arg0, 4);
    func_0029fbb0(arg0, 5);
}
// FUN_002A03B0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a03b0);
// FUN_002A12E0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a12e0);
// FUN_002A1A10
s32 func_002a1a10(u8 *arg0) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_16 + 0x10);
    switch (temp_3) {
    case 0:
        iGpffffb52c = 0;
        func_002bb4e0();
        func_002baac0(D_0063E630);
        func_002bad10(1);
        func_002baf40(0);
        func_002bb050(0);
        *(s32 *)(temp_16 + 0x10) = 1;
        goto done;
    case 1:
        if (func_002bb600() != 0) {
            func_002bbcc0();
            if (func_002bb700() == 0) {
                iGpffffb52c = func_002bb0e0();
            }
        } else {
            *(s32 *)(temp_16 + 0x10) = 2;
        }
        goto done;
    case 2:
        func_002bb4e0();
        *(s32 *)(temp_16 + 0x10) = 0;
        return iGpffffb52c;
    default:
        goto done;
    }
done:
    return -1;
}
/* measured: disabling common-subexpression propagation prevents the repeated
   tween target from being held in a saved register across calls. */
#pragma opt_common_subs off
/* measured: disabling propagation preserves the retail call-site materialization. */
#pragma opt_propagation off
// FUN_002A1B20
s32 func_002a1b20(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x178));
        func_002a27c0((s32)(temp_16 + 0x178), 0, 0, 0, 0, fGpffff8204, 0, 10, 20);
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x178);
    if (func_002a2c70(temp_16 + 0x178) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}
/* measured: closes opt_propagation around func_002a1b20. */
#pragma opt_propagation on
/* measured: closes opt_common_subs around func_002a1b20. */
#pragma opt_common_subs on
/* measured: common-subexpression suppression preserves repeated target addresses. */
#pragma opt_common_subs off
/* measured: propagation suppression preserves retail call-site materialization. */
#pragma opt_propagation off
// FUN_002A1BD0
s32 func_002a1bd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x210));
        {
            s32 target;
            s32 value;

            target = (s32)(temp_16 + 0x210);
            value = 18;
            func_002a27c0(target, value, 249, value, 219, fGpffff8204, 0, 0, 10);
        }
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x210);
    if (func_002a2c70(temp_16 + 0x210) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}
/* measured: closes propagation suppression around func_002a1bd0. */
#pragma opt_propagation on
/* measured: closes common-subexpression suppression around func_002a1bd0. */
#pragma opt_common_subs on
/* measured: no_branch_likely preserves retail's ordinary loop branches. */
#pragma no_branch_likely on
/* measured: opt_common_subs off preserves retail per-use index arithmetic. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves retail's global counter loads. */
#pragma opt_propagation off
// FUN_002A1C80
s32 func_002a1c80(u8 *arg0) {
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_17_3;
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_19;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        iGpffffb530 = 0;
        *(s32 *)(temp_16 + 8) = 1;
    }
    if ((iGpffffb530 < 6) && ((*(s32 *)(temp_16 + 0x18) % 6) == 0)) {
        var_17 = 0;
        while (var_17 < 4) {
            temp_18 = temp_16 + ((iGpffffb530 + (var_17 * 6)) * 0x98) + 0x340;
            func_002a2780((s32)temp_18);
            func_002a27c0((s32)temp_18, 0, 0, 0, 0, fGpffff8204, 0, 0, 6);
            var_17++;
        }
        func_002a27c0((s32)(temp_16 + (iGpffffb530 * 0x98) + 0x1180),
                      0, -2, 0, 0, fGpffff8204, 0, 0, 12);
        iGpffffb530++;
    }
    var_17_2 = 0;
    while (var_17_2 < 24) {
        temp_18_2 = temp_16 + (var_17_2 * 0x98) + 0x340;
        if (func_002a2ca0(temp_18_2) == 0) {
            func_002a2980(temp_18_2);
        }
        var_17_2++;
    }
    var_18 = 0;
    var_17_3 = 0;
    while (var_17_3 < 6) {
        if (func_002a2ca0(temp_16 + (var_17_3 * 0x98) + 0x1180) == 0) {
            temp_19 = temp_16 + (var_17_3 * 0x98) + 0x1180;
            func_002a2980(temp_19);
            if (func_002a2c70(temp_19) == 0) {
                var_18++;
            }
        }
        var_17_3++;
    }
    if (var_18 == 6) {
        *(s32 *)(temp_16 + 8) = 0;
        *(s32 *)(temp_16 + 0x18) = 0;
        return 1;
    }
    *(s32 *)(temp_16 + 0x18) += 1;
    return 0;
}
/* measured: closes opt_propagation around func_002a1c80. */
#pragma opt_propagation on
/* measured: closes opt_common_subs around func_002a1c80. */
#pragma opt_common_subs on
/* measured: closes no_branch_likely around func_002a1c80. */
#pragma no_branch_likely off
// FUN_002A1F20
s32 func_002a1f20(u8 *arg0) {
    u8 *temp_2;

    if (*(s32 *)(*(u8 **)(arg0 + 0x38) + 4) != 3) {
        temp_2 = func_00460990();
        *(void (**)(u8 *))(temp_2 + 8) = func_002a1ef0;
        *(u8 **)(temp_2 + 0x10) = arg0;
        func_00460ac0(D_00795E60, temp_2);
        goto success;
    }
    return -1;
success:
    return 0;
}
/* measured: opt_loop_invariants on hoists the case-zero store constant into the
   preheader, matching retail's li $v1 before the loop-entry branch. */
#pragma opt_loop_invariants on
// FUN_002A1FA0
s32 func_002a1fa0(u8 *arg0) {

    u8 colors[4];
    s128 sp40;
    f32 *sp40_ptr;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 var_17;
    s32 var_17_2;
    s32 var_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    sp40_ptr = (f32 *)&sp40;
    sp40 = D_0063E8D0;
    if (iGpffffb540 == 0) {
        return 0;
    }
    colors[0] = 0;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    func_0045d6e0(colors, sp40_ptr, 0.0f, 1);
    temp_5 = *(s32 *)(temp_16 + 4);
    switch (temp_5) {
    case 0:
        func_00122640(1, 1);
        var_4 = 0;
        for (; var_4 < 6; var_4++) {
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C38) = 3;
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C3A) = 0;
        }
        *(s32 *)(temp_16 + 0) = 0;
        *(s32 *)(temp_16 + 0x14) = 0;
        *(s32 *)(temp_16 + 4) = 1;
        goto block_39;
    case 1:
        temp_2_2 = *(s32 *)(temp_16 + 0xC);
        if ((temp_2_2 < 3) && (D_0063E8C0[temp_2_2](arg0, temp_5) == 1)) {
            *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_16 + 0xC) + 1;
        }
        func_002a12e0(arg0, *(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 0xC) >= 3) {
            *(s32 *)(temp_16 + 0xC) = 0;
            *(s32 *)(temp_16 + 8) = 0;
            *(s32 *)(temp_16 + 0x18) = 0;
            *(s32 *)(temp_16 + 0x14) = 1;
            *(s32 *)(temp_16 + 4) = 2;
            *(s32 *)(temp_16 + 0x1C34) = 0;
            func_0029ebf0(arg0, 0);
        }
        goto block_39;
    case 2:
        temp_2_3 = *(s32 *)(temp_16 + 0x14);
        if (temp_2_3 == 1) {
            func_0029f070(arg0);
            temp_3 = *(s32 *)(temp_16 + 0x14);
            if ((temp_3 != 2) && (temp_3 == 3)) {
                *(s32 *)(temp_16 + 8) = 0;
                *(s32 *)(temp_16 + 0x10) = 0;
            }
            goto block_37;
        }
        if (temp_2_3 == 3) {
            if (*(s32 *)(temp_16 + 8) == 0) {
                temp_2_4 = func_002a1a10(arg0);
                if (temp_2_4 == 0) {
                    var_17 = 0xE;
                    goto loop_25_cond;
loop_25_body:
                    *(s8 *)(D_00882EF0 + var_17) = 0;
                    *(s8 *)(D_00882EF0 + var_17 + 1) = 0;
                    var_17 -= 2;
                    if (var_17 < 0) {
                        goto loop_28_init;
                    }
loop_25_cond:
                    if (func_00442c30(&iGpffffa7e8,
                                      D_00882EF0 + var_17, 2) == 0) {
                        goto loop_25_body;
                    }
loop_28_init:
                    var_17_2 = 0xE;
                    goto loop_28_cond;
loop_28_body:
                    *(s8 *)(D_00882ED0 + var_17_2) = 0;
                    *(s8 *)(D_00882ED0 + var_17_2 + 1) = 0;
                    var_17_2 -= 2;
                    if (var_17_2 < 0) {
                        goto clear_done;
                    }
loop_28_cond:
                    if (func_00442c30(&iGpffffa7e8,
                                      D_00882ED0 + var_17_2, 2) == 0) {
                        goto loop_28_body;
                    }
clear_done:
                    func_0010d490(D_00882EF0, D_00882ED0);
                    *(s32 *)(temp_16 + 0x18) = 0;
                    *(s32 *)(temp_16 + 8) = 1;
                } else if (temp_2_4 == 1) {
                    *(s32 *)(temp_16 + 0x14) = 1;
                }
                goto block_37;
            }
            if (*(s32 *)(temp_16 + 0x18) == 0) {
                func_00122520(1, 0x1E);
            }
            temp_3_2 = *(s32 *)(temp_16 + 0x18);
            if (temp_3_2 >= 0x1E) {
                *(s32 *)(temp_16 + 0x18) = 0;
                *(s32 *)(temp_16 + 4) = 3;
                goto block_39;
            }
            *(s32 *)(temp_16 + 0x18) = temp_3_2 + 1;
        }
block_37:
        func_002a03b0(arg0);
        goto block_39;
    case 3:
        return -1;
    default:
        goto block_39;
    }
block_39:
    return 0;
}
/* measured: closes opt_loop_invariants around func_002a1fa0. */
#pragma opt_loop_invariants off
// FUN_002A2310
void func_002a2310(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_002A2710
s32 func_002a2710(void) {
    return (s32)(func_00452380(D_0063E918) != 0);
}



// FUN_002A2740
void func_002a2740(void) {
    s32 temp_2;

    if ((temp_2 = func_00452380(D_0063E918)) != 0) {
        func_00452080(temp_2);
    }
}



// FUN_002A2E10
void func_002a2e10(f32 f0, f32 f1, f32 f2, s32 arg0, s32 arg1,
                   s8 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 value;

    value = arg2[arg3];
    if (value == 0) {
        value = 10;
    }
    func_0025f3f0(arg0, arg1, value, 0, (void *)arg5, 1, f0, f1, f2);
}
// FUN_002AA3F0
s32 func_002aa3f0(void) {
    s32 r;

    if (func_00452380(&D_00763918) == 0) {
        r = (D_00764634 != 0) ? 1 : 2;
    } else {
        r = 0;
    }
    return r;
}

// FUN_002AA450
void func_002aa450(void) {
    s64 bits;
    s32 *state;
    u8 *source;
    P4_002aa450_Work work;
    f32 phase;
    f32 offset;
    f32 ratio;
    f32 angle;
    f32 value;
    f32 scale;
    f32 color_x;
    f32 color_y;
    s32 color_value;
    s32 temp;

    state = (s32 *)D_00882F20;
    bits = *(s64 *)D_0063EDF0;
    value = *(f32 *)D_0063EDF8;
    work.pair0.bits = bits;
    work.pair0.value = value;
    bits = *(s64 *)D_0063EE00;
    value = *(f32 *)D_0063EE08;
    work.pair1.bits = bits;
    work.pair1.value = value;
    bits = *(s64 *)D_0063EE10;
    value = *(f32 *)D_0063EE18;
    work.pair2.bits = bits;
    work.pair2.value = value;
    bits = *(s64 *)D_0063EE20;
    value = *(f32 *)D_0063EE28;
    work.pair3.bits = bits;
    work.pair3.value = value;
    source = D_0063EE30;
    bits = *(s64 *)source;
    source = D_0063EE38;
    value = *(f32 *)source;
    work.pair4.bits = bits;
    work.pair4.value = value;
    ratio = (f32)(*(s32 *)D_00882F2C) / 5.0f;
    bits = *(s32 *)D_00882F28;
    temp = (s32)bits + 1;
    *(s32 *)D_00882F28 = temp;
    if (temp >= 0x3C) {
        state[2] = 0;
    }
    phase = (f32)state[2] / 60.0f;
    scale = 10.0f;
    offset = 1.0f - ratio;
    offset = p4_002aa450_mul(scale, offset);
    offset = -80.0f - offset;
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e4320(&work.pair3, &work.pair3, work.matrix);
    angle = 360.0f * phase;
    func_003e0870(work.matrix, &work.pair3, angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    color_x = (f32)0x1A3;
    color_y = (f32)0x242;
    color_value = 397;
    func_00366960((s32)color_y, (s32)color_x, 0x18, 0x1F, 0xFF00, 0xFF, 1, 0,
                  0.0f, 0, (s32 *)&work.matrix, 0);
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e0870(work.matrix, &work.pair3, 120.0f + angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0x18, 0x1F, 0xFFFF00, 0xFF, 1, 0,
                  0.0f, 0, (s32 *)&work.matrix, 0);
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e0870(work.matrix, &work.pair3, 240.0f + angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0x18, 0x1F, 0xFF0000, 0xFF, 1, 0,
                  0.0f, 0, (s32 *)&work.matrix, 0);
    func_003e0870(work.matrix, &work.pair1, fGpffff855c, 0);
    func_003e0870(work.matrix, &work.pair2, 357.0f * phase + 3.0f, 2);
    ((f32 *)&work.pair4)[0] *= ratio;
    ((f32 *)&work.pair4)[1] *= ratio;
    ((f32 *)&work.pair4)[2] *= ratio;
    func_003e0a90(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)(color_value - ratio * 2.0f), 0x22, 0x2C,
                  0xE6E6E6, 0xFF, 1, 0x11, 0.0f, 0x16,
                  (s32 *)&work.matrix, 0);
}
// FUN_002AA890
s32 func_002aa890(u8 *arg0) {
    s32 *state;
    u8 *temp_2;

    state = D_00882F20;
    switch (state[1]) {
    case 0:
        state[1] = 1;
    case 1:
        if ((state[0] & 1) != 0) {
            state[1] = 3;
        }
        break;
    case 3:
        state[1] = 4;
        state[2] = 0;
        state[0] |= 2;
    case 4:
        if ((state[0] & 1) == 0) {
            state[0] |= 4;
        }
        if ((state[0] & 2) != 0) {
            if (state[3] < 5) {
                state[3]++;
            } else {
                state[0] &= ~2;
            }
        } else if ((state[0] & 4) != 0) {
            if (state[3] > 0) {
                state[3]--;
            } else {
                state[0] &= ~4;
                state[1] = 1;
            }
        }
        temp_2 = func_00460990();
        *(void **)(temp_2 + 8) = (void *)func_002aa450;
        *(u8 **)(temp_2 + 0x10) = arg0;
        func_00460ac0(D_007966A0, temp_2);
        break;
    }
    return 0;
}
// FUN_002AAA00
void func_002aaa00(void)
{
}

// FUN_002AAA10
void func_002aaa10(void) {
    func_0043f9c8(D_00882F20, 0, 0x10);
    func_00451fc0(NULL, D_0063EE40, 0xF, 0, 0, (void *)func_002aa890, (void *)func_002aaa00, NULL);
}

// FUN_002AAA80
void func_002aaa80(void) {
    D_00882F20[0] |= 1;
}
// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}


/* measured: opt_propagation off keeps the D_00887300 base in $s0 and
   reloads the dispatch target before each call, as in retail. */
#pragma opt_propagation off
// FUN_002AAAC0
void func_002aaac0(void) {
    void (**base)(s32 arg0, s32 arg1);

    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    func_003f6440(3, 0x50003);
    func_003f6440(2, 0x44);
    base[0](1, 0);
}
/* measured: closes the opt_propagation bracket for func_002aaac0. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves the cached dispatch base and retail call-site order. */
#pragma opt_propagation off
// FUN_002AABF0
void func_002aabf0(void *arg0, u8 *arg1) {
    P4_002aabf0_Work work;
    u8 *ptr;
    void (**base)(s32 arg0, s32 arg1);
    f32 temp_f20;
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    u8 temp_6;
    u8 temp_7;
    u8 temp_8;
    u8 temp_9;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    ptr = arg1;
    temp_6 = ptr[0x14];
    temp_7 = ptr[0x15];
    temp_8 = ptr[0x16];
    temp_9 = ptr[0x17];
    work.colors[0] = temp_6;
    work.colors[1] = temp_7;
    work.colors[2] = temp_8;
    work.colors[3] = temp_9;
    temp_f3 = *(f32 *)(ptr + 0);
    temp_f2 = *(f32 *)(ptr + 4);
    temp_f1 = *(f32 *)(ptr + 8);
    temp_f0 = *(f32 *)(ptr + 0xC);
    work.values[0] = temp_f3;
    work.values[1] = temp_f2;
    work.values[2] = temp_f1;
    work.values[3] = temp_f0;
    temp_f20 = *(f32 *)(ptr + 0x10);
    temp_19 = *(s32 *)(ptr + 0x18);
    temp_18 = temp_19 & 0x100;
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    temp_17 = temp_19 & 0x200;
    if (temp_17 != 0) {
        func_003f6690(2, &work.sp84);
    }
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    func_003f6440(3, 0x50003);
    func_003f6440(2, 0x44);
    base[0](1, 0);
    if (temp_18 != 0) {
        func_003f6440(3, work.sp88);
    }
    if (temp_17 != 0) {
        func_003f6440(2, work.sp84);
    }
    if (temp_19 & 1) {
        base[0](6, 1);
    }
    if (temp_19 & 2) {
        base[0](8, 1);
    }
    if (temp_19 & 4) {
        func_003f6440(3, 0x5000D);
    }
    if (temp_19 & 8) {
        func_003f6440(2, 0x54);
    }
    if (temp_19 & 0x20) {
        func_003f6440(2, 0x58);
    }
    temp_17_2 = temp_19 & 0x40;
    if (temp_17_2 != 0) {
        func_00364c50();
    }
    temp_16 = temp_19 & 0x10;
    if (temp_16 != 0) {
        func_00489f80();
    }
    func_0045d6e0(work.colors, work.values, temp_f20, 0);
    if (temp_16 != 0) {
        func_0048a000();
    }
    if (temp_17_2 != 0) {
        func_00364c70();
    }
    jtbl_008873EC[0](ptr);
}
/* measured: closes opt_propagation around func_002aabf0. */
#pragma opt_propagation on
// FUN_002ABF70
s32 func_002abf70(u8 *arg0) {
    s32 temp_3;
    s8 temp_4;
    u8 *temp_16;
    void *temp_17;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s8 *)(temp_16 + 0);
    switch (temp_4) {
    case 0:
    case 1:
    case 2:
    case 3:
        *(s8 *)(temp_16 + 0) = temp_4 + 1;
        break;
    case 4:
        temp_f0 = 100.0f;
        temp_f1 = 156.0f;
        temp_f2 = 1.0f;
        temp_17 = (void *)*(s32 *)(D_0063EEA0 +
                                   (*(s32 *)(temp_16 + 0x6C0) * 4));
        func_00274ed0(temp_f0, temp_f1, temp_f2,
                      -1, 0, 0, temp_17, 0, 0);
        if (D_008C027A[0] & 0x8000) {
            *(s32 *)(temp_16 + 0x6C0) =
                func_002b2cb0(*(s32 *)(temp_16 + 0x6C0), 1, 3, 0, 1);
        } else if (D_008C027A[0] & 0x2000) {
            *(s32 *)(temp_16 + 0x6C0) =
                func_002b2d00(*(s32 *)(temp_16 + 0x6C0), 1, 0, 3, 1);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            temp_3 = *(s32 *)(temp_16 + 0x6C0);
            switch (temp_3) {
            case 0:
                *(s32 *)(temp_16 + 0x6C8) = func_002bdb50((s32)arg0, 0);
                break;
            case 1:
                *(s32 *)(temp_16 + 0x6C8) = func_002e7510((s32)arg0);
                break;
            case 2:
                iGpffffb54c = 0;
                *(s32 *)(temp_16 + 0x6C8) = func_00311260(arg0);
                break;
            case 3:
                *(s32 *)(temp_16 + 0x6C8) = func_003493b0(arg0);
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x10) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            switch (*(s32 *)(temp_16 + 0x6C0)) {
            case 2:
                iGpffffb54c = 1;
                *(s32 *)(temp_16 + 0x6C8) = func_00311260(arg0);
                break;
            default:
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x80) {
            func_0045af60(0, 0, 0, 0xA);
        }
        break;
    case 5:
        if (iGpffffb54c == 1) {
            temp_f0 = 20.0f;
            temp_f2 = 1.0f;
            temp_f1 = temp_f0;
            func_00274ed0(temp_f0, temp_f1, temp_f2,
                          (s32)0x808080FF, 0, 2,
                          (void *)D_0063EEB0, 0, 0);
        }
        if (func_00452490(*(s32 *)(temp_16 + 0x6C8)) == 0) {
            *(s8 *)(temp_16 + 0) = 0;
            func_002bdea0();
            func_00308f40();
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002AC2A0
void func_002ac2a0(void) {
    u8 *p;

    func_0044ea90(D_0063EEC0, 0x4B9);
    p = D_008873F4[0](1, 0x4D78, 0x40000);
    func_00451de0(D_0063EED0, 0xF, 0, 0,
                  (void *)func_002abf70, (void *)func_002ac270, p);
    *(u8 *)(p + 0) = 0;
    *(s32 *)(p + 0x6B4) = 0x3F800000;
    *(s16 *)(p + 0x6B8) = 0x1F;
    *(s16 *)(p + 0x6BA) = 0;
    *(s8 *)(p + 0x6BC) = 1;
    *(s8 *)(p + 0x6BD) = 1;
    *(s32 *)(p + 0x6C0) = 0;
}
// FUN_002AC360
void func_002ac360(void) {
    s16 i;

    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
}
// FUN_002AC3B0
u32 func_002ac3b0(void) {
    return (u32)D_00764658;
}
// FUN_002AC3C0
s64 func_002ac3c0(s32 arg0, s32 arg1) {
    s32 temp;

    temp = arg0 & 0xff;
    return (s8)(((1 << temp) & 0xffff & D_00764658[arg1 & 0xff]) >> temp);
}