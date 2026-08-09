#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern s32 func_00106330(s32 arg0);
extern s32 func_00273970(u8 *arg0);
extern void func_0026d810();
extern s32 func_00451fc0(s32 arg0, void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void (*arg5)(void), void (*arg6)(void),
                         s32 arg7);
extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 func_0026db60(void);
extern void func_0026dc30(void);
extern s32 func_0026dee0(void);
extern u8 *func_001452b0(s32 arg0);
extern void func_0026dd60(u8 *arg0);
extern void func_0026d440(void);
extern void func_0026a020(u8 *arg0);
extern void func_0026c310(u8 *arg0);
extern void func_004b11d0(void *arg0, s32 arg1);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern void func_0043f9c8(void *arg0, void *arg1, s32 arg2);
extern u8 D_0088152F[];
extern u8 D_00881530[];
static inline u32 *func_0026e010_add_offset(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}

extern u8 *func_00452560();
extern s32 func_00452490();

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(void);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void func_004b1150(u8 *arg0);

extern char D_00637348[];
extern s32 func_00452380(void *arg0);
extern void func_00452080(s32 arg0);
extern void func_0025f430(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          u8 *arg4, s32 arg5, s32 arg6, s32 arg7,
                          f32 arg8, f32 arg9, f32 arg10, f32 arg11,
                          f32 arg12, f32 arg13);
extern void func_00263cb0(s32 arg0);
extern void func_00274660();
extern s32 func_002746a0(void);
extern s64 func_0010d660(s32 arg0);
extern s64 func_0010d6d0(s32 arg0);
extern void func_00442088();
extern u8 iGpffffa734;

// FUN_00260510
void func_00260510(void)
{
    s32 temp_2;
    u8 *temp_2_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        temp_2_2 = func_00452560(temp_2);
        *(s32 *)(temp_2_2 + 8) |= 1;
    }
}
// FUN_00260560
void func_00260560(void)
{
    s32 temp_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        func_00452080(temp_2);
    }
}
/* measured: plain C reproduces the callback ABI and body; b210 schedules the
   independent halfword loads before the zero/pointer call setup (normalized_diff
   17, object 88B, retail window 96B). Parked because nd <= 25. */
// Committed at nd 17.
// FUN_002605A0 NONMATCHING
#ifdef NON_MATCHING
void func_002605a0(s32 arg0, s32 arg1, s8 *arg2, s32 arg3, s32 arg4,
                   u8 *arg5, f32 fparg0, f32 fparg1, f32 fparg2)
{
    s8 temp_7;
    s32 temp_8;
    u8 *temp_9;
    s16 temp_10;
    s16 temp_11;

    temp_7 = *(s8 *)(arg2 + arg3);
    if (temp_7 != 0xA) {
        temp_8 = 0;
        temp_9 = *(u8 **)(arg5 + 0x10);
        temp_10 = *(s16 *)(arg5 + 0);
        temp_11 = *(s16 *)(arg5 + 2);
        func_0025f430(arg0, arg1, temp_8, temp_7, temp_9, 1,
                      temp_10, temp_11, fparg0, fparg1, fparg2,
                      *(f32 *)(arg5 + 4), *(f32 *)(arg5 + 8),
                      *(f32 *)(arg5 + 0xC));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_002605a0);
#endif
// FUN_00260600
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260600);
// FUN_00260E60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260e60);
// FUN_00261560
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00261560);
// FUN_00262DE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00262de0);
// FUN_00263220
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263220);
// FUN_00263460
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263460);
// FUN_00263730
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263730);
// FUN_00263CB0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263cb0);
// FUN_00264CB0
void func_00264cb0(s32 arg0, s32 arg1)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32))(temp_2 + 8) = func_00263cb0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0((u8 *)arg1, temp_2);
}
// FUN_00264D10
void func_00264d10(void)
{
    s32 temp_4;
    u8 *temp_2;

    temp_2 = func_00452560();
    if (func_00452490((u8 *)*(s32 *)(temp_2 + 0x14)) != 0) {
        func_00452080(*(s32 *)(temp_2 + 0x14));
    }
    temp_4 = *(s32 *)(temp_2 + 4);
    if (temp_4 != 0) {
        func_0025f230((void *)temp_4);
    }
    (*jtbl_008873EC)(temp_2);
}
// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266A90
void func_00266a90(u8 *arg0) {
    u8 *p;

    if (func_00452490(arg0) != 0) {
        p = func_00452560(arg0);
        *(s32 *)(p + 4) |= 2;
    }
}

// FUN_00266AE0
s32 func_00266ae0(s32 arg0)
{
    u8 *temp_2;
    s32 temp_4;

    if (func_00452490() != 0) {
        temp_2 = func_00452560(arg0);
        temp_4 = *(s32 *)(temp_2 + 4);
        if ((temp_4 & 1) && !(temp_4 & 4)) {
            return 0;
        }
        if (*(s32 *)temp_2 == 1) {
            return 1;
        }
        return 0;
    }
    return 1;
}
// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}



// FUN_00266BA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266ba0);
// FUN_00266CC0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266cc0);
// FUN_002674B0
void func_002674b0(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266cc0;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_00267510
void func_00267510(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0025f230((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00267570
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267570);
// FUN_00267670
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267670);
/* measured: optimization_level 1 and the right-associated first two terms produce the retail FPU chain; exact match nd 0 (obj 88B/window 96B). */
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
#pragma optimization_level 1
// FUN_002677A0
f32 func_002677a0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}
/* measured: closes the optimization_level bracket (nd 0). */
#pragma optimization_level 2

// FUN_00267800
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267800);
// FUN_00267B20
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267b20);
// FUN_00268A70
s32 func_00268a70(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_16 - 1;
    *(s32 *)temp_16 = temp_2;
    if (temp_2 < 0) {
        func_004b1150((u8 *)*(s32 *)(temp_16 + 4));
        *(s32 *)(temp_16 + 4) = 0;
        return -1;
    }
    return 0;
}

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

// FUN_0026CEF0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026cef0);
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 1
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
#pragma opt_propagation off
// FUN_0026DB60
s32 func_0026db60(void)
{
    s32 var_17;
    u8 *var_16;
    s32 temp_4;
    s32 temp_3;
    u8 *var_2;
    func_0026d440();
    var_17 = 1;
    goto outer_test;
outer_body:
    var_16 = func_001452b0(var_17);
    goto inner_test;
inner_body:
    func_0026a020(var_16);
    var_16 = *(u8 **)(var_16 + 0x138);
inner_test:
    if (var_16 != NULL) {
        goto inner_body;
    }
    var_17 += 1;
outer_test:
    if (var_17 < 0x16) {
        goto outer_body;
    }
    var_2 = func_001452b0(7);
    temp_3 = 1;
    goto second_test;
second_body:
    temp_4 = *(s32 *)(var_2 + 0x148);
    if (temp_4 == temp_3) {
        func_0026c310(var_2);
        goto second_exit;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
second_test:
    if (var_2 != NULL) {
        goto second_body;
    }
second_exit:
    return 0;
}
/* measured: closes opt_propagation off probe for func_0026db60. */
#pragma opt_propagation on
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 2
// FUN_0026DC30
void func_0026dc30(void)
{
    func_0026d810();
}

// FUN_0026DC50
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026dc50);
// FUN_0026DD60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026dd60);
// FUN_0026DEE0
s32 func_0026dee0(void)
{
    s32 temp_5;
    s8 temp_3;
    u8 *var_16;

    var_16 = func_001452b0(6);
    func_0026dd60(var_16);
    goto loop_test;
loop_body:
    if (*(s32 *)(var_16 + 0x28) & 2) {
        temp_5 = *(s32 *)(var_16 + 0x144);
        if (temp_5 != 0) {
            temp_3 = *(s8 *)(var_16 + 0x140);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                func_004b11d0(D_005DC824, temp_5);
                break;
            }
        }
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_test:
    if (var_16 != NULL) {
        goto loop_body;
    }
    return 0;
}
// FUN_0026DF80
s32 func_0026df80(void)
{
    s32 temp_2;

    temp_2 = func_00451fc0(0, D_0063B5A0, 0x10, 0, 0,
                           (void (*)(void))func_0026db60, func_0026dc30, 0);
    func_00451fc0(temp_2, D_0063B5C0, 0x10, 0, 0,
                  (void (*)(void))func_0026dee0, NULL, 0);
    return temp_2;
}
/* measured: jtbl_008873E8 array addressing fixes the retail absolute
   lui/lw. Local aliases, pointer-width casts, declaration-order, and goto
   loop spellings all retain the 0x50 frame and nd 20 (object 204B/window
   208B); the remaining register/scheduling rows are parked. Committed at
   nd 20. */
// FUN_0026E010 NONMATCHING
#ifdef NON_MATCHING
void func_0026e010(s32 arg0, s32 arg1)
{
    s32 local_arg0;
    s32 local_arg1;
    u32 *result;
    u32 *sp4C;
    u32 *next;
    u32 var_3;
    u32 *cursor;

    local_arg0 = arg0;
    local_arg1 = arg1;
    func_0044ea90(D_0063B5D8, 0x36);
    result = (u32 *)jtbl_008873E8[0](((local_arg0 + 8) * (local_arg1 + 1)) + 4,
                                    0x40000);
    sp4C = result;
    func_0043f810(result, &sp4C, 4);
    cursor = result + 1;
    var_3 = 0;
    goto loop_test;
loop_body:
    *cursor = (u32)var_3;
    next = func_0026e010_add_offset(local_arg0, cursor);
    *(cursor + 1) = (u32)next;
    cursor = next;
    var_3 += 1;
loop_test:
    if ((s32)var_3 < local_arg1) {
        goto loop_body;
    }
    *cursor = (u32)local_arg1;
    *(cursor + 1) = (u32)(result + 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e010);
#endif
// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

/* measured: opt_propagation off probe for func_0026e4c0 field-load order. */
#pragma opt_propagation off
// FUN_0026E4C0
s32 func_0026e4c0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xD) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off probe for func_0026e4c0. */
#pragma opt_propagation on
// FUN_0026E560
s32 func_0026e560(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off forces func_0026e590 field-load order. */
#pragma opt_propagation off
// FUN_0026E590
s32 func_0026e590(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xC) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e590. */
#pragma opt_propagation on
/* measured: opt_propagation off forces func_0026e630 field-load order. */
#pragma opt_propagation off
// FUN_0026E630
s32 func_0026e630(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e630. */
#pragma opt_propagation on
// FUN_0026E6D0
s32 func_0026e6d0(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off preserves field-load order for func_0026e700. */
#pragma opt_propagation off
// FUN_0026E700
s32 func_0026e700(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s16 *)(arg1 + 0x1E) = (s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e700. */
#pragma opt_propagation on
/* measured: opt_common_subs off forces func_0026e7f0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves field-load order for func_0026e7f0. */
#pragma opt_propagation off
// FUN_0026E7F0
s32 func_0026e7f0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    s32 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_5;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_5 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() == 0) {
        goto success;
    }
    if (func_002746a0() != 1) {
        return 0;
    }
success:
    *(s32 *)arg1 = temp_4 << 4;
    *(s32 *)(arg1 + 4) = temp_5 << 3;
    return 0;
}
/* measured: closing opt_common_subs off for func_0026e7f0. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026e7f0. */
#pragma opt_propagation on
// FUN_0026E910
s32 func_0026e910(void)
{
    func_00274660(1, 1);
    return 1;
}
/* measured: opt_propagation off preserves decode and field-store order for func_0026e940. */
#pragma opt_propagation off
// FUN_0026E940
s32 func_0026e940(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    func_00274660(0x20, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e940. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ea50. */
#pragma opt_propagation off
// FUN_0026EA50
s32 func_0026ea50(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    s32 temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (func_00106330(0x3B) == 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (iGpffffa730 != 0) {
        goto direct_store;
    }
    temp_6 = func_00273970(*(u8 **)(arg1 + 0x14));
    temp_7 = temp_6 << 4;
    temp_6 = temp_7 - temp_6;
    temp_7 = temp_6 << 2;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = temp_7;
    goto after_store;
direct_store:
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
after_store:
    iGpffffa730 = -1;
    iGpffffb4bc = 1;
    func_00274660(0x10, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026ea50. */
#pragma opt_propagation on
// FUN_0026EBA0
s32 func_0026eba0(void)
{
    func_00274660(1, 1);
    func_00274660(2, 1);
    return 1;
}
/* measured: explicit loop labels and a persistent base reproduce the complete scan body at object 288B/window 288B with normalized_diff 17; register allocation remains in the loop decode and terminator compare, so this candidate is parked under NON_MATCHING. Committed at nd 17. */
// FUN_0026EBE0 NONMATCHING
#ifdef NON_MATCHING
/* measured: opt_propagation off probe preserves target scan preheader ordering. */
#pragma opt_propagation off
s32 func_0026ebe0(s32 arg0, u8 *arg1)
{
    s32 temp_3;
    s32 var_16;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    u8 *temp_3_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_16 = 0;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_6 = 0xF0;
    temp_3_7 = 0xA;
    goto scan_loop;
decode:
    if ((temp_3_2 & 0xF0) == temp_3_6) {
        var_16 += (((temp_3_2 & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)temp_3_2 < 0x80U) {
        goto scan_loop;
    }
    var_16 += 1;
    goto scan_loop;
scan_loop:
    temp_3 = var_16;
    var_16 += 1;
    temp_3_2 = *(s8 *)(temp_3_3 + temp_3);
    if (temp_3_2 != temp_3_7) {
        goto decode;
    }
    func_0043f9c8(&D_00881530, 0, 0x80);
    func_0043f810(&D_00881530,
                  (void *)(*(s32 *)(arg1 + 0x10) + *(s32 *)(arg1 + 0x18)),
                  var_16);
    *((u8 *)((s32)&D_0088152F + var_16)) = 0;
    func_00274660(4, 1);
    *(s32 *)(arg1 + 0x18) = *(s32 *)(arg1 + 0x18) + var_16;
    return 0;
}
/* measured: closing opt_propagation off for func_0026ebe0. */
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ebe0);
#endif
// FUN_0026ED00
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ed00);
// FUN_0026EE00
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ee00);
// FUN_0026EF00
s32 func_0026ef00(s32 arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    *(s8 *)(arg1 + 0xF) = 0x14;
    *(s16 *)(arg1 + 0x1E) = 0x20;
    iGpffffb4bc = 0;
    return 0;
}
// FUN_0026EF60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ef60);
// FUN_0026F0A0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f0a0);
// FUN_0026F1E0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f1e0);
// FUN_0026F2C0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f2c0);
/* measured: optimization_level 0 probe for the retail redundant return branch. */
#pragma optimization_level 0
// FUN_0026F5A0
s32 func_0026f5a0(void)
{
    if (func_002746a0() != 2) {
        return 0;
    }
    return 0;
}
/* measured: closes optimization_level 0 around func_0026f5a0. */
#pragma optimization_level 2
// FUN_0026F5E0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f5e0);
// FUN_0026F860
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f860);
// FUN_0026FBA0
s32 func_0026fba0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088(&sp20, &iGpffffa734, func_0010d660(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    return 0;
}
// FUN_0026FC20
s32 func_0026fc20(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088(&sp20, &iGpffffa734, func_0010d6d0(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    return 0;
}
// FUN_0026FCA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fca0);
// FUN_0026FD90
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fd90);
// FUN_0026FFF0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fff0);