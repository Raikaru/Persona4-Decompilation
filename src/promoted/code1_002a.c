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
extern void func_002aa450(u8 *arg0);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_002abf70(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
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
extern s32 func_002bb700(void);
extern void func_002bbcc0(void);
extern s32 iGpffffb52c;
extern u8 D_0063E630[];



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
// FUN_002A1FA0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a1fa0);
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
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aa450);
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
// FUN_002AABF0
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002aabf0);
// FUN_002ABF70
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002abf70);
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