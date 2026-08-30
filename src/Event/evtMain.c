#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtMain.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u32 DAT_007645D8;
void func_00285260(void);
void func_002871a0();
u8 *func_00145270(s32 arg0);
extern void func_0046d730(const void *file, u32 line);
extern void *func_00457120(void);
extern u8 *func_00457130(void);
void func_003e8180(void *, float);
void func_003e81c0(void *, float);
extern u8 D_0063C3B0[];
void func_0043f9c8(void *dst, s32 c, s32 n);
s32 func_00286350(void);
extern s32 D_008821E0[];
void func_0028ad90(u8 *arg0, s32 arg1);
void func_0028b440(int, int);
void func_0028b5d0(int);
void func_0026bf20(void);
void func_00452080(s32 handle);
s32 func_00452490(s32 handle);
s32 func_00186640();
extern u8 D_0063C3C0[];
extern u8 D_0063C3E0[];
s32 func_00298130();
u64 func_00298190(s16 param_1, int param_2);
void func_00459880();
void func_0045a3e0();
void func_004599a0();
void func_004598e0();
void func_0045aac0();
s32 func_002981f0();
s32 func_00298220();
extern u8 D_0063C5F0[];
extern u8 D_0063C610[];
extern s32 (**D_00882204[])(s32, s32, s32, u8 *, u8 *);
extern u8 D_0063C420[];
void func_00287360();
void func_00287bf0();
void func_0028c370();
void func_00288020();
void func_00287d90();
void func_0028f4f0();
void func_00293270();
void func_004577d0(void *arg0, f32 arg1);
void func_0028be70();
void func_0028b230(int param_1);
void func_002e0dd0();
void func_0028d0a0();
void func_00290b00();
void func_00291900();
void func_002919e0();
void func_00290fa0();
void func_00286e90();
void func_00290470();
void func_0028f3a0(s32 arg0, s32 *arg1, s32 arg2);
s32 func_0028d390();
s32 func_0028dc30();
void func_00291470();
void func_00291220();
s32 func_00291360();
void func_002913d0();
void func_00146e60();
void func_00268f20();
void func_00269340();
u32 func_00269620(u32 param_1, u8 param_2, u32 param_3, u32 param_4);
void func_004b13d0(s32 arg0, f32 arg1);
extern u8 D_0063C558[];
extern u8 D_0063C568[];
extern s32 D_008821E4[];
extern s32 D_008821E8[];
extern s32 D_008821EC[];
extern s32 D_008821F0[];
extern s32 D_008821F4[];
extern u8 D_0063C580[];
s32 func_0028bef0();
s32 func_002909b0();
s32 func_00290e50();
void func_0026bf70(s32 arg0);
void func_00269740(s32 arg0);
void func_00269690(s32 arg0, s32 arg1, f32 arg2);
void func_002690b0(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10);
extern u8 D_0063C540[];
s32 func_00479ca0(s32 res, s32 arg1);
f32 func_00479f60(void *param_1, s32 param_2);
u32 func_002699d0(u32 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 fparg0);
void func_00269820(void *res, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
void func_00269bd0(void *resource, s32 enabled);
void func_0014a2f0(s32 arg0);
s32 func_002852a0(s32 arg0, s32 arg1);
s32 func_00285330(void);
extern void func_00440b68(char *fmt, ...);
extern char D_0063C628[];
extern void *DAT_008873EC[];
s32 func_00286430(u8 *arg0);
u32 func_00145260(void);
u8 *func_001452b0(s32 arg0);
void func_00268c20();
void func_00161460(u8, u8, u8);
void func_00161500(u8);
extern void func_0044ea90(void *msg, s32 id);
extern char D_00748340[];
extern void *D_008873F4[];
extern void (*jtbl_008873EC[])(void *ptr);
void func_00286d80(u32 *, u32 *);
s32 func_002853f0(s32 arg0);
extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_0045af60(int, int, int, int);
extern u8 D_0063C5C0[];
void func_00442088();
s32 func_0028f770(s32 arg0);
void func_0028f800();
void func_0026d810();
void func_0026d780(u16 arg0, s16 arg1);
extern u32 DAT_00764B38;
extern u8 DAT_00764B3C;
extern u8 DAT_00764B40;
extern u8 DAT_00764B44;
extern f32 D_00764B5C;
void func_0028bfb0(u32 node, s32 param_1, s32 *a, s32 *b);
u32 func_002909a0(u32 *object);
s32 func_00290de0(u32 *object);
s32 func_00122720(void);
extern u32 DAT_00713890;
extern void func_00113480(s16 a, s16 b, s16 c, s16 d);
void func_00113500(void);
extern void func_00269c20(u16, int);

/* measured: retail dispatches the 20-case switch (arg0->{0} 0..0x39) via a
   jump table (range-check then sll/addu/lw/jr); mwcc b210 emits an if-chain
   (addiu $v1,0x35 / beq chain) for this sparse case set, and separately
   allocates saved registers arg0=$s4/arg1=$s3/arg2=$s2 with locals var_16=$s0
   and r=$s1 where mwcc rotates to arg0=$s0/arg1=$s1/arg2=$s4, var_16=$s3,
   r=$s2. Tried the complete m2c switch body + 1 declaration order; nd 324
   (obj 1424B vs window 1248B). Jump-table-density + saved-register floor. */
// FUN_00286780
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00286780);

// FUN_00286C60
void func_00286c60(u8 *arg0, u8 *arg1) {
    u32 t48;
    u32 t40;

    if (*(u32 *)(arg1 + 0x50) == 0) {
        *(u32 *)(arg0 + 0x68) = *(u32 *)(arg1 + 0x4C);
    } else {
        *(u32 *)(*(u32 *)(arg1 + 0x50) + 0x4C) = *(u32 *)(arg1 + 0x4C);
    }
    if (*(u32 *)(arg1 + 0x4C) == 0) {
        *(u32 *)(arg0 + 0x6C) = *(u32 *)(arg1 + 0x50);
    } else {
        *(u32 *)(*(u32 *)(arg1 + 0x4C) + 0x50) = *(u32 *)(arg1 + 0x50);
    }
    *(u32 *)(arg1 + 0x50) = 0;
    *(u32 *)(arg1 + 0x4C) = 0;
    *(u32 *)(arg0 + 0x64) -= 1;
    t48 = *(u32 *)(arg1 + 0x48);
    if (t48 != 0) {
        if (*(u32 *)arg0 != 0x12) {
            jtbl_008873EC[0]((void *)t48);
            func_002852a0(9, 0);
        }
        *(u32 *)(arg1 + 0x48) = 0;
    }
    t40 = *(u32 *)(arg1 + 0x40);
    if (t40 != 0) {
        jtbl_008873EC[0]((void *)t40);
        func_002852a0(0xA, -0x130);
        *(u32 *)(arg1 + 0x40) = 0;
    }
    jtbl_008873EC[0](arg1);
    func_002852a0(8, -0x54);
}

// FUN_00286D80
void func_00286d80(u32 *param_1, u32 *param_2) {
    u32 *node = (u32 *)param_2[0x13];
    if (node == 0) {
        param_2[0x13] = (u32)param_1;
        param_2[0x14] = (u32)param_1;
        param_1[0x24] = 0;
        param_1[0x25] = 0;
    } else {
        while (node != 0) {
            if (func_002853f0(param_1[0]) < func_002853f0(node[0])) {
                if (node[0x25] == 0) {
                    param_2[0x13] = (u32)param_1;
                    node[0x25] = (u32)param_1;
                    param_1[0x25] = 0;
                    param_1[0x24] = (u32)node;
                } else {
                    *(u32 *)(node[0x25] + 0x90) = (u32)param_1;
                    param_1[0x25] = node[0x25];
                    param_1[0x24] = (u32)node;
                    node[0x25] = (u32)param_1;
                }
                goto tail;
            }
            node = (u32 *)node[0x24];
        }
    tail:
        if (node == 0) {
            *(u32 *)(param_2[0x14] + 0x90) = (u32)param_1;
            param_1[0x25] = param_2[0x14];
            param_1[0x24] = 0;
            param_2[0x14] = (u32)param_1;
        }
    }
    param_2[0x12] += 1;
}

// FUN_00286E90
void func_00286e90(int param_1, int param_2) {
    if (*(u32 *)(param_1 + 0x94) == 0) {
        *(u32 *)(param_2 + 0x4C) = *(u32 *)(param_1 + 0x90);
    } else {
        *(u32 *)(*(u32 *)(param_1 + 0x94) + 0x90) = *(u32 *)(param_1 + 0x90);
    }
    if (*(u32 *)(param_1 + 0x90) == 0) {
        *(u32 *)(param_2 + 0x50) = *(u32 *)(param_1 + 0x94);
    } else {
        *(u32 *)(*(u32 *)(param_1 + 0x90) + 0x94) = *(u32 *)(param_1 + 0x94);
    }
    *(u32 *)(param_1 + 0x94) = 0;
    *(u32 *)(param_1 + 0x90) = 0;
    *(u32 *)(param_2 + 0x48) -= 1;
}

// FUN_00286F00
void *func_00286f00(int param_1, int param_2) {
    void *r;
    func_0044ea90(D_00748340, 0x52);
    r = ((void *(*)(int, int, int))D_008873F4[0])(1, 0x98, 0x40000);
    func_002852a0(7, 0x98);
    if (r == 0) {
        return NULL;
    }
    func_0043f9c8(r, 0, 0x98);
    *(u32 *)((u8 *)r + 0) = param_1;
    *(u32 *)((u8 *)r + 8) = -1;
    *(u16 *)((u8 *)r + 0xC) = 0;
    *(u32 *)((u8 *)r + 0x60) = 0;
    switch (param_1) {
    case 0x30:
        *(s8 *)((u8 *)r + 0x1E) = -1;
        break;
    }
    func_00286d80((u32 *)r, (u32 *)param_2);
    return r;
}

// FUN_00286FF0
void func_00286ff0(int param_1, int param_2, int param_3) {
    u8 *r;
    if (param_1 != 0) {
        *(u16 *)(param_1 + 0xC) = param_2;
        r = func_00145270(*(u16 *)(param_1 + 0xC));
        if (r != 0) {
            *(u32 *)(param_1 + 0x54) = *(u32 *)(r + 0x28);
        } else {
            *(u32 *)(param_1 + 0x54) = 0;
        }
        *(u32 *)(param_1 + 0x34) = param_3;
    }
}

// FUN_00287060
void *func_00287060(s32 arg0, u8 *arg1, u16 arg2, s32 arg3) {
    s32 *r;
    u8 *t;

    func_0044ea90(D_00748340, 0x52);
    r = ((void *(*)(int, int, int))D_008873F4[0])(1, 0x98, 0x40000);
    func_002852a0(7, 0x98);
    if (r == NULL) {
        r = NULL;
    } else {
        func_0043f9c8(r, 0, 0x98);
        *(s32 *)((u8 *)r + 0) = arg0;
        *(s32 *)((u8 *)r + 8) = -1;
        *(s16 *)((u8 *)r + 0xC) = 0;
        *(s32 *)((u8 *)r + 0x60) = 0;
        switch (arg0) {
        case 0x30:
            *(s8 *)((u8 *)r + 0x1E) = -1;
            break;
        }
        func_00286d80((u32 *)r, (u32 *)arg1);
    }
    if ((r != NULL) && (r != NULL)) {
        *(u16 *)((u8 *)r + 0xC) = arg2;
        t = func_00145270(*(u16 *)((u8 *)r + 0xC));
        if (t != NULL) {
            *(s32 *)((u8 *)r + 0x54) = *(s32 *)(t + 0x28);
        } else {
            *(s32 *)((u8 *)r + 0x54) = 0;
        }
        *(s32 *)((u8 *)r + 0x34) = arg3;
    }
    return r;
}

/* measured: without opt_loop_invariants, MWCC rematerializes the 0x21 loop
 * constant inside the loop body after the entry jump; retail hoists it to the
 * preheader before the jump (same pattern as func_00287ad0). */
#pragma opt_loop_invariants on
// FUN_002871A0
void func_002871a0(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 *node;
    u8 *node2;
    u8 *node3;
    s32 i16;

    if (func_00145260() != 0) {
        node = *(u8 **)(arg2 + 0x4C);
        while (node != NULL) {
            if (*(u32 *)node == 1 || *(u32 *)node == 0x30) {
                if (*(u16 *)(node + 0xC) != 0) {
                    if (*(u32 *)(node + 0x60) == 1) {
                        func_00268c20(*(u16 *)(node + 0xC), 0);
                    } else if (arg0 == 0) {
                        func_00268c20(*(u16 *)(node + 0xC), 1);
                    } else {
                        func_00268c20(*(u16 *)(node + 0xC), 0);
                    }
                }
            }
            node = *(u8 **)(node + 0x90);
        }
        i16 = 1;
        node2 = *(u8 **)(arg2 + 0x4C);
        while (node2 != NULL) {
            if (*(u32 *)node2 == 0x21) {
                if (*(u32 *)(node2 + 0x60) != 0) {
                    i16 = 0;
                }
                break;
            }
            node2 = *(u8 **)(node2 + 0x90);
        }
        node3 = func_001452b0(7);
        while (node3 != NULL) {
            if (i16 != 0 && arg0 == 0) {
                func_00268c20(*(u16 *)node3, 1);
            } else {
                func_00268c20(*(u16 *)node3, 0);
            }
            node3 = *(u8 **)(node3 + 0x138);
        }
    }
}
/* measured: see annotation above (func_002871a0). */
#pragma opt_loop_invariants off

// FUN_00287310
void func_00287310(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x5D4) == 1) {
        func_002871a0(0, *(u8 **)(arg0 + 0x14), arg0);
        return;
    }
    func_002871a0(1, *(u8 **)(arg0 + 0x14), arg0);
}

/* measured: clean-C register and source-order variants retained a saved-
   register/argument-rotation residual; stopped at the confirmed compiler
   floor after the permitted attempts. */
// FUN_00287360
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287360);

// FUN_00287AD0
/* measured: without opt_loop_invariants, MWCC rematerializes the 0x22 loop
 * constant inside the loop body; retail hoists it to the preheader. */
#pragma opt_loop_invariants on
void func_00287ad0(int param_1, int param_2) {
    s32 a = 0;
    s32 b = 0;
    u32 node = *(u32 *)(param_2 + 0x4C);
    while (node != 0) {
        if (*(u32 *)node == 0x22) {
            break;
        }
        node = *(u32 *)(node + 0x90);
    }
    if (node != 0) {
        func_0028bfb0(node, param_1, &a, &b);
        if (a != 0 && *(u16 *)a == param_1) {
            switch (*(s8 *)(a + 0x10)) {
            case 0:
                if (func_002909a0((u32 *)(param_2 + 0x678)) != 0 && func_00290de0((u32 *)(param_2 + 0x678)) == 0) {
                    *(u32 *)param_2 |= 0x20;
                    func_00440b68((char *)&DAT_00713890);
                }
                break;
            case 1:
                if (func_00122720() != 0) {
                    *(u32 *)param_2 |= 0x2000;
                }
                break;
            }
        }
    }
}
/* measured: see annotation above (func_00287ad0). */
#pragma opt_loop_invariants off

// FUN_00287CC0
u8 *func_00287cc0(u32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *node;
    u8 *found;
    s32 best;

    found = NULL;
    best = -1;
    node = *(u8 **)(arg1 + 0x68);
    while (node != NULL) {
        if ((s32)*(u16 *)node <= arg2) {
            if (*(s8 *)(node + 0x22) == 0) {
                s32 t = *(s8 *)(node + 0x14);
                if ((best < (s32)*(u16 *)node) && (*(s8 *)(node + 0x10) == 2) && (t == arg3) && (func_00286430(node) == 1)) {
                    best = (s32)*(u16 *)node;
                    found = node;
                }
            }
        }
        node = *(u8 **)(node + 0x4C);
    }
    return found;
}

/* measured: retail keeps the 4th arg in $30 ($fp) and v23 in $23; mwcc b210
   always gives $30 to the v23 local first and spills arg3 to the stack
   (+0x10 frame, sw $a3, 0xcc($sp)), cascading into every branch. Tried 4- and
   5-param signatures and 3 local declaration orders; all nd 121. Saved-
   register allocation floor (locals beat late params). */
/* measured: unmodified m2c candidate from src/generated, installed as a permuter seed; not a verified body. */
/* measured: corrected all five target callee declarations in the archived
   candidate; object_size 672 exceeds the 656-byte retail window and
   normalized_diff is 399, so this is reconstruction-gated rather than a
   polish near-miss. */
// FUN_00287D90 NONMATCHING
#ifdef NON_MATCHING
void func_00287d90(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3, s32 arg4) {
    u32 func_00269820(u16 *, s32, s64, s64, s32, s32, f32);
    u8 *func_00287cc0(u32, u8 *, s32, s32);
    s32 func_00479ca0(void *, s32);
    f32 func_00479f60(void *, s32);
    s32 spB0;
    s32 spA0;
    f32 var_9;
    f32 var_f12;
    f32 var_f12_2;
    s16 temp_2_2;
    s16 temp_2_3;
    s16 temp_2_4;
    s32 temp_4;
    s32 var_17;
    s32 var_18;
    s32 var_22;
    s32 var_3;
    s8 temp_23;
    u8 *temp_2;

    var_18 = 0;
    temp_4 = (s32)(*(u16 *)arg1 & 0xFFC00) >> 0xA;
    if (temp_4 == 1) {
        var_18 = *(s32 *)(arg1 + 0x164);
    } else if (temp_4 == 3) {
        var_18 = *(s32 *)(arg1 + 0x164);
    }
    if ((var_18 != 0) && (func_00479ca0((void *)var_18, 0) != 0)) {
        var_17 = 0;
loop_31:
        if (var_17 < 4) {
            if (func_00479ca0((void *)var_18, var_17 & 0xFFFF) != 0) {
                temp_2 = func_00287cc0((u32)arg3, (u8 *)arg2, arg0, var_17);
                if (temp_2 != NULL) {
                    if (*(s8 *)(temp_2 + 0x16) == 0) {
                        var_3 = 1;
                        var_22 = 1;
                    } else {
                        var_3 = 0;
                        var_22 = 0;
                    }
                    temp_23 = *(s8 *)(temp_2 + 0x22);
                    if (var_3 == 0) {
                        func_00479f60((void *)var_18, var_17 & 0xFFFF);
                    }
                    if (*(u16 *)temp_2 == arg0) {
                        if (temp_23 == 0) {
                            spB0 = *(s8 *)(temp_2 + 0x15);
                            spA0 = *(s8 *)(temp_2 + 0x17);
                        }
                        temp_2_2 = *(s16 *)(temp_2 + 0x20);
                        if (temp_2_2 > 0) {
                            var_9 = (f32)temp_2_2;
                        } else {
                            var_9 = 0.0f;
                        }
                        temp_2_3 = *(s16 *)(temp_2 + 0x28);
                        if (temp_2_3 < 0) {
                            var_f12 = 0.0f;
                        } else {
                            var_f12 = (f32)temp_2_3 / 100.0f;
                        }
                        func_00269820((u16 *)arg1, var_17, spB0, spA0, var_22, var_9, var_f12);
                        if (*(s8 *)(temp_2 + 0x23) == 1) {
                            if (temp_23 == 0) {
                                temp_2_4 = *(s16 *)(temp_2 + 0x2A);
                                if (temp_2_4 <= 0) {
                                    var_f12_2 = 1.0f;
                                } else {
                                    var_f12_2 = (f32)temp_2_4 / 100.0f;
                                }
                                func_002699d0((u32 *)arg1, var_17, *(s8 *)(temp_2 + 0x24), *(s16 *)(temp_2 + 0x26), *(s8 *)(temp_2 + 0x25) == 0, 0, var_f12_2);
                                goto block_29;
                            }
                        } else {
block_29:
                            *(u8 **)(arg2 + (var_17 * 4) + 0x70) = temp_2;
                        }
                    }
                }
            }
            var_17 += 1;
            goto loop_31;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00287d90);
#endif

/* measured: retail holds the inner-loop linked-list walk in $a2 (p) and the
   found-node in $v1 (first loop) / $a0 (second loop); mwcc b210 always puts
   p in $a0 and found in $a2. Tried 3 declaration orders, separate node/node2
   locals (gets register allocation right: arg0=$s1, arg1=$s0, node=$s2) and
   inline-"use p directly" structure; all nd 17 with this residual. Temp-
   register allocation floor (not a saved-register issue). */
/* Recovered from the m2c draft via tools/draft_probe.py (nd 26 as generated).
   The whole residual was loop SHAPE: m2c writes every loop as
   `if (cond) { body; goto top; }`, which b210 compiles as a top-test loop with an
   unconditional back-branch, where retail rotates - an entry `b` to the test plus a
   conditional back-branch at the bottom. Turning the two OUTER goto-chains into
   `while` took nd 26 -> 10, and the two inner ones (with `break` on the hit, keeping
   the trailing if/else exactly as m2c emitted it) closed it. Converting all four at
   once while also collapsing that if/else scores nd 127 at 300B, so keep the
   surrounding structure and change only the loop form. */
// FUN_00288020
void func_00288020(s32 arg0, u8 *arg1) {
    u8 *temp_2;
    u8 *var_18;
    u8 *var_18_2;
    u8 *var_3;
    u8 *var_4;
    u8 *var_6;
    u8 *var_6_2;

    temp_2 = (u8 *)func_00145260();
    if (temp_2 != NULL) {
        var_18 = *(u8 **)(temp_2 + 4);
        while (var_18 != NULL) {
            var_3 = NULL;
            var_6 = *(u8 **)(arg1 + 0x4C);
            while (var_6 != NULL) {
                if (*(s32 *)(var_6 + 0x34) == (s32) var_18) {
                    var_3 = var_6;
                    break;
                }
                var_6 = *(u8 **)(var_6 + 0x90);
            }
            if (var_3 == NULL) {
                var_18 = *(u8 **)(var_18 + 0x138);
            } else {
                func_00287d90(arg0, var_18, (s32) var_6, arg1, 0);
                var_18 = *(u8 **)(var_18 + 0x138);
            }
        }
        var_18_2 = (u8 *)func_001452b0(3);
        while (var_18_2 != NULL) {
            var_4 = NULL;
            var_6_2 = *(u8 **)(arg1 + 0x4C);
            while (var_6_2 != NULL) {
                if (*(s32 *)(var_6_2 + 0x34) == (s32) var_18_2) {
                    var_4 = var_6_2;
                    break;
                }
                var_6_2 = *(u8 **)(var_6_2 + 0x90);
            }
            if (var_4 == NULL) {
                var_18_2 = *(u8 **)(var_18_2 + 0x138);
            } else {
                func_00287d90(arg0, var_18_2, (s32) var_6_2, arg1, 0);
                var_18_2 = *(u8 **)(var_18_2 + 0x138);
            }
        }
    }
}
/* measured: clean-C scratch-struct, source-order, explicit-branch, and
   materialized-flag variants matched the prologue and case-0 prefix but
   retained inner-dispatch/compiler residuals; stopped after the permitted
   compiler-floor attempts. */
// FUN_00288170
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288170);

/* measured: retail materializes func_00268f20/00269340/00269690/002690b0
   arguments in the order arg3,arg1,arg2,arg4 (lhu 2 first, lb 0x30 last);
   mwcc b210 always emits L-to-R (lhu 0xc first, addiu last), and for the
   second func_00269690 it moves $a1 before loading $f12 where retail loads
   $f12 first. Tried old-style and full real prototypes (u8 arg forces lbu
   where retail uses lb); all nd 20. Argument-materialization scheduling
   floor. */
/* measured: corrected all six target callee declarations in the archived
   candidate; object_size 1252 exceeds the 1072-byte retail window and
   normalized_diff is 886, so this is reconstruction-gated rather than a
   polish near-miss. */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
u8 *func_00145270(s32);                  /* extern */
// FUN_00288AF0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00288af0(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    void func_00146e60(u64, u64, u64);
    s32 func_00268f20(u32, void *, u32, u8);
    s32 func_002690b0(u32, u8 *, u8 *, f32, f32, f32, f32, f32, f32, s32, s8);
    s32 func_00269340(u32, void *, u32, u8);
    s32 func_00269690(u32, f32, s32);
    void func_0026bf70(u32);
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f12;
    f32 var_f13;
    s8 temp_3;
    u8 *temp_2;

    switch (arg0) {                                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        if (D_008821E0[0] != 1) {
            return 0;
        }
        if (arg1 == M2C_FIELD(arg2, s32 *, 0xC)) {
            func_0026bf70(0x1E58);
            func_00146e60((u64)M2C_FIELD(arg3, u16 *, 0xC), (u64)(arg3 + 0x38), (u64)(arg3 + 0x44));
            func_00269740(M2C_FIELD(arg3, u16 *, 0xC));
            temp_2 = (u8 *)(func_00145270(0x1E58U));
            if (temp_2 != NULL) {
                M2C_FIELD(temp_2, f32 *, 0x140) = (f32) M2C_FIELD(arg2, f32 *, 0x750);
            }
        }
        return 1;
    case 1:                                         /* switch 1 */
        return 1;
    case 2:                                         /* switch 1 */
        if (M2C_FIELD(arg4, u16 *, 0) == arg1) {
            if ((u8 *)((u8 *)(func_00145270(M2C_FIELD(arg3, u16 *, 0xC)))) == NULL) {
                return 1;
            }
            M2C_FIELD(arg3, s32 *, 0x60) = (s32) M2C_FIELD(arg4, u8 *, 0x34);
            temp_3 = (s8)(M2C_FIELD(arg4, s8 *, 0x12));
            switch (temp_3) {                       /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                func_0026bf70(0x1E58);
                sp70 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x18));
                sp74 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x1C));
                sp78 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x20));
                sp60 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x24));
                sp64 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x28));
                sp68 = (f32)(s32)(M2C_FIELD(arg4, f32 *, 0x14));
                func_00268f20(M2C_FIELD(arg3, u16 *, 0xC), &sp70, M2C_FIELD(arg4, u16 *, 2), M2C_FIELD(arg4, s8 *, 0x30));
                func_00269340(M2C_FIELD(arg3, u16 *, 0xC), &sp60, (s16) M2C_FIELD(arg4, u16 *, 2), (u8) M2C_FIELD(arg4, s8 *, 0x30));
                func_00269690(M2C_FIELD(arg3, u16 *, 0xC), M2C_FIELD(arg4, u16 *, 2), M2C_FIELD(arg4, f32 *, 0x2C));
                func_00440b68((char *)&D_0063C540, (s32) M2C_FIELD(arg4, u16 *, 2));
                break;
            case 1:                                 /* switch 2 */
                func_0026bf70(0x1E58);
                sp50 = (f32) (s16) M2C_FIELD(arg4, f32 *, 0x14) / 16.0f;
                sp54 = (f32) M2C_FIELD(arg4, s16 *, 0x16) / 16.0f;
                sp58 = (f32) (s16) M2C_FIELD(arg4, f32 *, 0x18) / 16.0f;
                var_f12 = (f32) M2C_FIELD(arg4, s16 *, 0x1A) / 16.0f;
                sp40 = (f32) (s16) M2C_FIELD(arg4, f32 *, 0x1C) / 16.0f;
                sp44 = (f32) M2C_FIELD(arg4, s16 *, 0x1E) / 16.0f;
                sp48 = (f32) (s16) M2C_FIELD(arg4, f32 *, 0x20) / 16.0f;
                var_f13 = (f32) M2C_FIELD(arg4, s16 *, 0x22) / 16.0f;
                if ((s8) M2C_FIELD(arg4, u8 *, 0x34) != 0) {
                    temp_f1 = var_f13 - var_f12;
                    if ((temp_f1 <= 180.0f) && !(temp_f1 < 0.0f)) {
                        var_f12 += 360.0f;
                    } else if (!(temp_f1 < -180.0f) && (temp_f1 <= 0.0f)) {
                        var_f12 -= 360.0f;
                    }
                } else {
                    temp_f1_2 = var_f13 - var_f12;
                    if (!(temp_f1_2 <= 180.0f)) {
                        var_f13 -= 360.0f;
                    } else if (temp_f1_2 < -180.0f) {
                        var_f13 += 360.0f;
                    }
                }
                func_002690b0(M2C_FIELD(arg3, u16 *, 0xC), (u8 *)&sp50, (u8 *)&sp40, M2C_FIELD(arg4, u16 *, 2), M2C_FIELD(arg4, s8 *, 0x30), var_f12, var_f13, (f32) M2C_FIELD(arg4, s16 *, 0x26), (f32) M2C_FIELD(arg4, s16 *, 0x2A), (f32) (s16) M2C_FIELD(arg4, f32 *, 0x24), (f32) (s16) M2C_FIELD(arg4, f32 *, 0x28));
                func_00269690(M2C_FIELD(arg3, u16 *, 0xC), 0U, M2C_FIELD(arg4, f32 *, 0x2C));
                break;
            }
            return 1;
        }
    default:                                        /* switch 1 */
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/evtMain", func_00288af0);
#endif
// FUN_00288F20
s32 func_00288f20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    s32 v8;
    s32 v6;
    s32 v7;
    s32 v9;
    f32 f12;
    u8 *t;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            t = func_00145270(*(u16 *)(arg4 + 0x12));
            if (t == 0) {
                return 1;
            }
            if (*(u16 *)arg4 == arg1) {
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    if (*(s8 *)(arg4 + 0x14) == 0) {
                        func_00269bd0(t, 1);
                    } else {
                        func_00269bd0(t, 0);
                    }
                    break;
                case 1:
                    v6 = *(s8 *)(arg4 + 0x14);
                    v8 = 0;
                    v9 = *(s16 *)(arg4 + 0x18);
                    v7 = *(s16 *)(arg4 + 0x16);
                    if (*(s8 *)(arg4 + 0x15) == 0) {
                        v8 = 1;
                    }
                    if (*(s16 *)(arg4 + 0x1A) < 0) {
                        f12 = 1.0f;
                    } else {
                        f12 = (f32)*(s16 *)(arg4 + 0x1A) / 100.0f;
                    }
                    func_00269820(t, 0, v6, v7, v8, v9, f12);
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}
// FUN_002890B0
s32 func_002890b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    u16 t;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            t = *(u16 *)(arg4 + 0x12);
            if (func_00145270(t) == 0) {
                return 1;
            }
            if (*(u16 *)arg4 == arg1) {
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    if (*(s8 *)(arg4 + 0x14) == 0) {
                        func_00269c20(t, 1);
                    } else {
                        func_00269c20(t, 0);
                    }
                    break;
                default:
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}

// FUN_002891D0
s32 func_002891d0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    f32 sp70[3];
    f32 sp60[3];
    f32 sp50[3];
    f32 sp40[3];
    s32 t;
    s32 v16;
    s32 v17;
    u8 *p;

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(u32 *)(arg2 + 0xC)) {
            func_00291470(*(u32 *)(arg2 + 0x5D0));
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            if (*(u16 *)arg4 == arg1) {
                v16 = *(s8 *)(arg4 + 0x11);
                switch (*(s8 *)(arg4 + 0x10)) {
                case 0:
                    func_00291220(*(u32 *)(arg2 + 0x5D0), v16, *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13) != 0);
                    t = func_00291360(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF;
                    if (t != 0) {
                        sp70[0] = *(f32 *)(arg4 + 0x14);
                        sp70[1] = *(f32 *)(arg4 + 0x18);
                        sp70[2] = *(f32 *)(arg4 + 0x1C);
                        sp60[0] = *(f32 *)(arg4 + 0x20);
                        sp60[1] = *(f32 *)(arg4 + 0x24);
                        sp60[2] = *(f32 *)(arg4 + 0x28);
                        func_00146e60(t, sp70, sp60);
                        func_00440b68((char *)D_0063C558);
                    }
                    break;
                case 1:
                    v16 = func_00291360(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF;
                    if (v16 != 0) {
                        sp50[0] = *(f32 *)(arg4 + 0x14);
                        sp50[1] = *(f32 *)(arg4 + 0x18);
                        sp50[2] = *(f32 *)(arg4 + 0x1C);
                        sp40[0] = *(f32 *)(arg4 + 0x20);
                        sp40[1] = *(f32 *)(arg4 + 0x24);
                        sp40[2] = *(f32 *)(arg4 + 0x28);
                        v17 = *(s16 *)(arg4 + 0x12);
                        func_00268f20(v16, sp50, v17, 0);
                        func_00269340(v16, sp40, v17, 0);
                        func_00440b68((char *)D_0063C568);
                    }
                    break;
                case 2:
                    func_002913d0(*(u32 *)(arg2 + 0x5D0), v16);
                    break;
                case 3:
                    func_00269620(func_00291360(*(u32 *)(arg2 + 0x5D0), v16) & 0xFFFF, *(u8 *)(arg4 + 0x12), *(s16 *)(arg4 + 0x14), 0);
                    break;
                case 4:
                    p = func_00145270(func_00291360(*(u32 *)(arg2 + 0x5D0), v16));
                    if (p != NULL) {
                        func_004b13d0(*(u32 *)(p + 0x144), (f32)*(s16 *)(arg4 + 0x34) / 100.0f);
                    }
                    break;
                }
            }
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: retail hoists all five D_008821E4..F4 loads to the top of case 1
   (separate lui per global, in arg order) and in case 2 emits the mask test
   as bne-to-body with the return inline plus dsll32/dsra32 before the sh.
   mwcc b210 CSEs the shared lui base, evaluates the case-1 globals lazily in
   condition order, and schedules the sign-extension ahead of the store.
   Tried a-e locals and inline m2c forms; nd >= 100. Load-hoist + scheduling
   floor. */
// FUN_002894B0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_002894b0);
// FUN_00289780
s32 func_00289780(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 sp30[0x100];

    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            s32 t41;
            *(u32 *)arg2 |= 0x80000;
            t41 = *(s16 *)(arg4 + 0x14) + 0x41;
            func_00442088(sp30, D_0063C5C0, *(u32 *)(arg2 + 0x78C), *(u32 *)(arg2 + 0x790), t41);
            if (*(u32 *)(arg2 + 0x760) == 0) {
                *(u32 *)(arg2 + 0x760) = func_0028f770(func_00286350());
            }
            if (*(u32 *)(arg2 + 0x760) == 0) {
                func_0046d730(D_0063C3B0, 0xCE7);
            }
            func_0028f800(*(u32 *)(arg2 + 0x760), 0xF, sp30, *(s16 *)(arg4 + 0x16));
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: retail reuses arg2's dead register ($s1) for p2 with the addu
   operand order rs=$v0 (scaled), and routes the default case's return through
   the shared addiu block; mwcc b210 always gives p2 the earlier-freed $s2,
   emits addu rs=$s1, and reuses the dispatch's $v0=1 by branching the default
   straight to the epilogue. Tried goto-ret, b-local vs inline expression, and
   4 declaration orders; all nd 8. Register-reuse + branch-target floor. */
/* measured: retail reuses arg2's dead register for the case-2 slot pointer and keeps the dispatcher result in a separate saved register; mwcc b210 assigns the slot and argument registers differently in the final call sequence. Tried declaration orders and parameter reuse; all closed at nd 8. Committed at nd 8. */
// FUN_002898B0
s32 func_002898b0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 result;
    s32 t;
    u8 *slot;
    s32 offset;

    t = func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(s32 *)(arg2 + 0xC)) {
            arg1 = 0;
            while (arg1 < 3U) {
                slot = arg2 + arg1 * 4 + 0x6D0;
                if (*(s32 *)slot != 0) {
                    func_00452080(*(s32 *)slot);
                }
                *(s32 *)slot = 0;
                arg1 += 1;
            }
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            offset = (*(u8 *)(arg4 + 0x12) >> 4) * 4;
            slot = (u8 *)((u32)offset + (u32)arg2 + 0x6D0);
            if (*(s32 *)slot != 0) {
                func_00452080(*(s32 *)slot);
                *(s32 *)slot = 0;
            }
            switch (*(u8 *)(arg4 + 0x12) & 0xF) {
            case 0:
                result = *(s32 *)slot;
                if (result != 0) {
                    func_00452080(result);
                    result = 0;
                }
                break;
            case 1:
                result = func_0028d390(t, 1, arg4);
                break;
            case 2:
                result = func_0028d390(t, 2, arg4);
                break;
            case 3:
                result = func_0028dc30(t, 1, arg4);
                break;
            case 4:
                result = func_0028dc30(t, 2, arg4);
                break;
            case 5:
                result = func_0028dc30(t, 3, arg4);
                break;
            case 6:
                result = func_0028dc30(t, 5, arg4);
                break;
            }
            *(s32 *)slot = result;
        }
    default:
        return 1;
    }
}
// FUN_00289B10
s32 func_00289b10(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u8 sp60[0x14];
    s32 t;

    t = func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            break;
        }
        if (arg1 == *(u32 *)(arg2 + 0xC)) {
            func_0028b440((s32)arg2, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 != arg1) {
            goto ret;
        }
        func_0043f9c8(sp60, 0, 0x14);
        if (*(u8 *)(arg4 + 0x10) != 0) {
            *(u32 *)sp60 |= 1;
        }
        *(u32 *)(sp60 + 4) = (*(u8 *)(arg4 + 0x14) << 16) | (*(u8 *)(arg4 + 0x15) << 8) | *(u8 *)(arg4 + 0x16);
        *(u32 *)(sp60 + 8) = (*(u8 *)(arg4 + 0x18) << 16) | (*(u8 *)(arg4 + 0x19) << 8) | *(u8 *)(arg4 + 0x1A);
        *(f32 *)(sp60 + 0xC) = *(f32 *)(arg4 + 0x1C);
        *(f32 *)(sp60 + 0x10) = *(f32 *)(arg4 + 0x20);
        func_0028f3a0(t, (s32 *)sp60, *(u16 *)(arg4 + 2));
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289C90
s32 func_00289c90(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_00161460(((u8 *)param_5)[0x10], ((u8 *)param_5)[0x11], ((u8 *)param_5)[0x13]);
        func_00161500(((u8 *)param_5)[0x12]);
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289D70
s32 func_00289d70(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 t;

    t = func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 != arg1) {
            goto ret;
        }
        if (*(u8 *)(arg4 + 0x10) != 0) {
            if (*(u32 *)(arg2 + 0x768) != 0 && func_00452490(*(u32 *)(arg2 + 0x768)) != 0) {
                func_00452080(*(u32 *)(arg2 + 0x768));
            }
            *(u32 *)(arg2 + 0x768) = func_00186640(t);
        } else {
            if (*(u32 *)(arg2 + 0x768) != 0 && func_00452490(*(u32 *)(arg2 + 0x768)) != 0) {
                func_00452080(*(u32 *)(arg2 + 0x768));
            }
            *(u32 *)(arg2 + 0x768) = 0;
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289EC0
s32 func_00289ec0(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 1:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        func_003e8180(func_00457120(), *(float *)((u8 *)param_5 + 0x10));
        func_003e81c0(func_00457120(), *(float *)((u8 *)param_5 + 0x14));
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_00289FB0
s32 func_00289fb0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s8 temp_3;
    u32 t;

    func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if ((*(u16 *)arg4 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1)) {
            func_00440b68((char *)D_0063C3C0, arg1);
            temp_3 = *(s8 *)(arg4 + 0x12);
            switch (temp_3) {
            case 0:
                func_00298130(*(u32 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x10), 2);
                func_00440b68((char *)D_0063C3E0, *(s16 *)(arg4 + 0x10));
                break;
            case 1:
                func_00298190(2, *(s16 *)(arg4 + 0x10));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}
// FUN_0028A100
s32 func_0028a100(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s8 temp_3;
    u32 t;

    func_00286350();
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((*(u32 *)arg2 & 0x80000000) && (arg4 == NULL) && (arg1 == 0)) {
            func_0045aac0(3, 0, 0);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        if ((*(u16 *)arg4 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1)) {
            func_00440b68((char *)D_0063C5F0, arg1);
            temp_3 = *(s8 *)(arg4 + 0x12);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                func_002981f0(*(u32 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x10), 3);
                func_00440b68((char *)D_0063C610, *(s16 *)(arg4 + 0x10));
                break;
            case 2:
                func_00298220(3, *(s16 *)(arg4 + 0x10));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

// FUN_0028A2A0
s32 func_0028a2a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)arg4 == arg1) {
            switch (*(s8 *)(arg4 + 0x10)) {
            case 0:
                func_0045af60(1, *(s8 *)(arg4 + 0x11), *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13));
                break;
            case 1:
                func_0045af60(0, *(s8 *)(arg4 + 0x11), *(s8 *)(arg4 + 0x12), *(s8 *)(arg4 + 0x13));
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

// FUN_0028A3B0
s32 func_0028a3b0(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    u16 temp_3;
    s16 temp_3_2;
    u32 t;

    func_00286350();
    switch (arg0) {
    case 0:
        if (D_008821E0[0] != 2) {
            return 0;
        }
        if ((*(u32 *)arg2 & 0x80000000) && (arg4 == NULL) && (arg1 == 0)) {
            func_00459880(2);
        }
        return 1;
    case 1:
        return 1;
    case 2:
        temp_3 = *(u16 *)arg4;
        if ((temp_3 == arg1) && (t = ((*(u32 *)arg2 & 0x10) != 0), t != 1) && (arg1 == temp_3)) {
            temp_3_2 = *(s16 *)(arg4 + 0x10);
            switch (temp_3_2) {
            case 0:
                func_0045a3e0(*(s16 *)(arg4 + 0x12), 1);
                break;
            case 1:
                func_004599a0(*(s16 *)(arg2 + 0x78C), *(s16 *)(arg4 + 0x12));
                break;
            case 2:
                func_004598e0(0x78, 1);
                break;
            case 3:
                func_00459880(2, 1);
                break;
            default:
                func_0046d730(D_0063C3B0, 0xE4C);
                break;
            }
            return 1;
        }
    default:
        return 1;
    }
}

/* measured: nested switch for D_008821E0[0] plus the no-argument
   func_0026d810 call preserves retail's live $a0 value. nd 0, object 320B,
   window 320B. */
// FUN_0028A560
s32 func_0028a560(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, u8 *arg4) {
    u16 temp_3;
    u16 temp_4;

    func_00286350();
    switch (arg0) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        temp_3 = *(u16 *)(arg4 + 2);
        if (((temp_3 == 0) && (arg1 == *(u16 *)arg4)) ||
            ((temp_3 > 0) && ((arg1 < (s32)*(u16 *)arg4) == 0) &&
             (arg1 < (*(u16 *)arg4 + temp_3)))) {
            if ((temp_3 == 0) && (*(s16 *)(arg4 + 0x10) == 0)) {
                *arg2 &= ~2;
                func_0026d810();
            } else if (arg1 == *(u16 *)arg4) {
                *arg2 |= 2;
                temp_4 = *(u16 *)(arg4 + 2);
                func_0026d780(temp_4, *(s16 *)(arg4 + 0x10));
            }
        }
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A6A0
s32 func_0028a6a0(int param_1, int param_2, int param_3, int param_4, u16 *param_5) {
    s16 v18;
    s8 t;
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 2:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        if (*(u16 *)param_5 != param_2) {
            goto ret;
        }
        t = *(s8 *)((u8 *)param_5 + 0x10);
        if (t == 0) {
            v18 = *(s16 *)((u8 *)param_5 + 0x18);
            if (v18 == 0) {
                func_00113480(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), *(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x1A));
            } else {
                func_00113480(*(s16 *)((u8 *)param_5 + 0x14), *(s16 *)((u8 *)param_5 + 0x16), v18, *(s16 *)((u8 *)param_5 + 0x1A));
            }
        } else if (t == 1) {
            func_00113500();
        }
        return 1;
    default:
    ret:
        return 1;
    }
}

// FUN_0028A7C0
s32 func_0028a7c0(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A850
s32 func_0028a850(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A8E0
s32 func_0028a8e0(s32 param_1) {
    func_00286350();
    switch (param_1) {
    case 0:
        switch (D_008821E0[0]) {
        default:
            return 0;
        case 3:
            return 1;
        }
    case 1:
        return 1;
    case 2:
        return 1;
    default:
        return 1;
    }
}

// FUN_0028A970
s32 func_0028a970(s32 arg0, s32 arg1, u8 *arg2) {
    u32 n;
    s32 t;
    u8 *node;

    if (arg2 == NULL) {
        func_0046d730(D_0063C3B0, 0xEDD);
    }
    n = *(u32 *)arg2;
    if (n >= 0x3A) {
        t = 0;
    } else if (D_00882204[0][n] == 0) {
        t = 0;
    } else {
        t = 1;
    }
    if (t != 0) {
        if (D_00882204[0][n](0, arg0, arg1, arg2, 0) != 0) {
            node = *(u8 **)(arg2 + 0x68);
            while (node != NULL) {
                if (func_00286430(node) != 0) {
                    D_00882204[0][*(u32 *)arg2](2, arg0, arg1, arg2, node);
                }
                node = *(u8 **)(node + 0x4C);
            }
            D_00882204[0][*(u32 *)arg2](1, arg0, arg1, arg2, 0);
        }
    }
}

/* measured: retail assigns saved registers arg0=$s1, arg1=$s0, node=$s2,
   node3=$s3, node2=$s4 (params low, locals high); mwcc b210 always emits
   the mirror image (params $s4/$s3, locals $s0-$s2) regardless of local
   declaration order (5 orders probed), extra unused params (3-5 probed),
   or the slt register ($v0 vs $at). Instruction stream is identical; pure
   saved-register rotation. nd 48. */
// FUN_0028AAF0
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028aaf0);

void func_00286c60();

/* measured: retail keeps the inner while-loop's entry stub (b .L0028AF54 at
   .L0028AF40, the outer back-edge targets it, two nops after the test lw).
   mwcc b210 always folds the stub away by retargeting the outer back-edge
   straight at the inner test (lw $v0 vs $a1), shifting every later branch.
   Tried assignment-in-condition while, plain while + reload, for loops, and
   single-statement bodies; all nd 35. Branch-to-branch layout floor. */
// FUN_0028AD90
INCLUDE_ASM("asm/nonmatchings/evtMain", func_0028ad90);

// FUN_0028AFE0
u8 *func_0028afe0(void) {
    u32 sp30[15];
    s32 v;
    s32 t;
    u8 *p;
    u32 *src;
    u32 *dst;
    u32 tmp;
    s32 i;

    func_0044ea90(D_00748340, 0x52);
    p = ((u8 *(*)(s32, s32, s32))D_008873F4[0])(1, 0x7B0, 0x40000);
    func_002852a0(0, 0x7B0);
    func_0043f9c8(p, 0, 0x7B0);
    func_0028b230((s32)p);
    src = (u32 *)(p + 0x76C);
    dst = sp30;
    i = 15;
    do {
        tmp = *src;
        src++;
        i--;
        *dst = tmp;
        dst++;
    } while (i > 0);
    v = *(u32 *)p;
    func_0043f9c8(p, 0, 0x7B0);
    src = sp30;
    dst = (u32 *)(p + 0x76C);
    i = 15;
    do {
        tmp = *src;
        src++;
        i--;
        *dst = tmp;
        dst++;
    } while (i > 0);
    *(u32 *)p = v;
    func_00285260();
    *(u32 *)p |= 1;
    *(u32 *)(p + 8) = 0x21C;
    *(u32 *)(p + 0x10) = *(u32 *)(p + 8) - 1;
    if (*(u32 *)p & 0x80000000) {
        *(u32 *)(p + 0x54) = 1;
    }
    func_004577d0(func_00457120(), 35.0f);
    func_0014a2f0(1);
    func_0028be70(p, 0);
    return p;
}

// FUN_0028B160
void func_0028ad90();
void func_0028b160(int param_1) {
    u32 f77c;
    func_0028ad90();
    func_0028b440(param_1, 0);    func_0028b5d0(param_1);
    func_0026bf20();
    if ((*(u32 *)param_1 & 0x40000000) == 0) {
        f77c = *(u32 *)(param_1 + 0x77C);
        if (f77c != 0) {
            func_00452080(f77c);
            *(u32 *)(param_1 + 0x77C) = 0;
        }
    }
    func_0014a2f0(0);
    ((void (*)(int))DAT_008873EC[0])(param_1);
    func_002852a0(0, -0x7B0);
    func_00285330();
    func_00440b68(D_0063C628);
}

// FUN_0028B230
void func_0028b230(int param_1) {
    *(u32 *)(param_1 + 0x774) = 0;
    func_00285260();
}

// FUN_0028B260
u32 func_0028b260(void) { return DAT_007645D8 != 0; }

// FUN_0028B2A0
void *func_0028b2a0(int param_1, int param_2) {
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        func_0046d730(D_0063C3B0, 0x10B7);
    }
    return (void *)(param_1 + param_2 * 20 + 0x68);
}

// FUN_0028B320
void func_0028b320(s32 arg0, s32 arg1) {
    u8 *p;

    if (arg0 == 0) {
        func_0046d730(D_0063C3B0, 0x10B6);
    }
    if (arg1 >= 2) {
        func_0046d730(D_0063C3B0, 0x10B7);
    }
    p = (u8 *)(arg0 + arg1 * 20 + 0x68);
    func_0043f9c8(p, 0, 0x14);
    if (DAT_00764B38 != 0) {
        *(u32 *)p |= 1;
    }
    *(u32 *)(p + 4) = (DAT_00764B3C << 16) | (DAT_00764B40 << 8) | DAT_00764B44;
    *(u32 *)(p + 8) = (*func_00457130() << 16) | (func_00457130()[1] << 8) | func_00457130()[2];
    *(f32 *)(p + 0xC) = *(f32 *)((u8 *)func_00457120() + 0x88);
    *(f32 *)(p + 0x10) = D_00764B5C;
}

// FUN_0028B440
void func_0028b440(int param_1, int param_2) {
    int p;
    f32 v;
    void *cam;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x10B6);
    }
    if (param_2 >= 2) {
        func_0046d730(D_0063C3B0, 0x10B7);
    }
    p = param_1 + param_2 * 20 + 0x68;
    if (*(u32 *)p & 1) {
        DAT_00764B38 = 1;
    } else {
        DAT_00764B38 = 0;
    }
    DAT_00764B3C = (u8)(*(u32 *)(p + 4) >> 16);
    DAT_00764B40 = (u8)(*(u32 *)(p + 4) >> 8);
    DAT_00764B44 = (u8)*(u32 *)(p + 4);
    func_00457140((*(u32 *)(p + 8) >> 16) & 0xFF, (*(u32 *)(p + 8) >> 8) & 0xFF, *(u32 *)(p + 8) & 0xFF, 0);
    v = *(f32 *)(p + 0xC);
    cam = func_00457120();
    *(f32 *)((u8 *)cam + 0x88) = v;
    cam = func_00457120();
    D_00764B5C = *(f32 *)(p + 0x10);
}

// FUN_0028B550
void func_0028b550(int param_1) {
    f32 *p;
    void *cam;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    func_0043f9c8(p, 0, 8);
    cam = func_00457120();
    p[0] = *(f32 *)((u8 *)cam + 0x80);
    cam = func_00457120();
    p[1] = *(f32 *)((u8 *)cam + 0x84);
}

// FUN_0028B5D0
void func_0028b5d0(int param_1) {
    f32 *p;
    if (param_1 == 0) {
        func_0046d730(D_0063C3B0, 0x110D);
    }
    p = (f32 *)(param_1 + 0x98);
    func_003e8180(func_00457120(), p[0]);
    func_003e81c0(func_00457120(), p[1]);
}
