#include "include_asm.h"
#include "type.h"
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
extern void func_0015a630();
extern void func_00174c20();
extern s32 func_0015f660();
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern s32 func_00102980(void);
extern void func_00145080(void);
extern void func_00260510(void);
extern void *func_0043f9c8(void *dst, s32 value, s32 size);
extern s32 func_00110e80(void);
extern u8 *func_00155280(void);
extern s32 func_00156170(s32 arg0);
extern s32 func_00156180(s32 arg0);
extern s32 func_00106330(s32 arg0);
extern s32 func_0015a160(void);
extern s32 func_00161630(u16 a, u16 b, u16 c, u16 d);
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern u8 D_005F18C0[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
s32 func_0017c930(u8 *arg0);
void func_0017cc90(u8 *arg0);
void func_0017d240(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                    s32 arg4, s32 arg5, s32 arg6,
                    f32 arg7, f32 arg8, f32 arg9);
extern void func_0017cd60(u8 *arg0);
extern void func_0044ea90(const void *msg, s32 id);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c, void (*init)(u8 *), void (*close)(u8 *), u8 *buf);

extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern void func_0029cf50(s32 arg0);
extern s32 func_00110fc0(void);
extern s32 func_00174680(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0018ced0(void);
extern void func_0018c7e0(void);
extern s32 func_00159f70(s32 arg0);
extern s32 func_00155290(void);
extern s32 func_0014ec50(s32 arg0, s32 arg1);
extern s32 func_0029d050(void);
extern void func_0029dfe0(s32 arg0, s32 arg1);
extern s32 func_00452490(s32 arg0);

extern s32 func_0029cc00(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 *func_00457120(void);
extern u8 *func_0047a2f0(void *arg0);
extern void func_003e42a0(void *dst, void *src, u8 *arg2);
extern u8 D_007EFA00[];
extern s32 D_005F1930[];
extern s32 D_005F1934[];
extern void func_002bd410(void);
extern void func_002bd3c0(void);

extern u8 *D_007643D0;
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffba48;
extern void func_003f6440(s32 arg0, s32 arg1);

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);



/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */

// FUN_00170120
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00170120);

// FUN_00170960
s32 func_00170960(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(func_00155280() + 0x18) != 0) && (D_008C024E[0] & 0x800)) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_001709C0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001709c0);

// FUN_00170B50
s32 func_00170b50(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (func_00106330(0x37) == 1) {
        return 0;
    }
    if (D_008C024E[0] & 0x10) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170BC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00170bc0);

// FUN_00170E10
s32 func_00170e10(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (D_008C024E[0] & 0x80) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170E50
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00170e50);

// FUN_00170F60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00170f60);

// FUN_001711B0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001711b0);

// FUN_00171280
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00171280);

// FUN_001713E0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001713e0);

// FUN_001714B0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001714b0);

// FUN_00175F70
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00175f70);

// FUN_001761D0
s32 func_001761d0(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40) == 1;
}

// FUN_001761F0
s32 func_001761f0(void)
{
    func_00110e80();
    return 1;
}
// FUN_00176220
s32 func_00176220(void)
{
    if (func_0029d020() > 3) {
        func_0029cf50(func_00110f00());
        return 1;
    }
    func_0029cf50(0);
    return 0;
}

// FUN_00176280
void func_00176280(void)
{
    func_0015f660();
}

// FUN_001762A0
s32 func_001762a0(void)
{
    if (func_0018ced0() == 0) {
        func_0018c7e0();
    }
    return 1;
}
// FUN_001762E0
s32 func_001762e0(void)
{
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00110fc0();
    return 1;
}
// FUN_00176320
s32 func_00176320(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_001029a0(0x19, NULL, 0, 0);
    return 1;
}

// FUN_00176370
s32 func_00176370(void) {
    s32 sp1C;

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_0043f9c8(&sp1C, 0, 4);
    sp1C = func_0029cc00(0);
    func_001029a0(0xC, &sp1C, 4, 2);
    return 1;
}

// FUN_001763F0
s32 func_001763f0(void) {
    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_001029a0(0xD, NULL, 0, 2);
    return 1;
}

// FUN_00176450
s32 func_00176450(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    func_0043f9c8(sp10, 0, 0x1C);
    sp10[0] = (s16)func_0029cc00(0);
    sp10[1] = (s16)func_0029cc00(1);
    sp10[2] = (s16)func_0029cc00(2);
    sp10[4] = (s16)func_0029cc00(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_00176500
s32 func_00176500(void)
{
    s16 sp10[14];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    *(s16 *)(iGpffff9db0 + 0x10) = -1;
    func_0043f9c8(sp10, 0, 0x1C);
    sp10[0] = (s16)func_0029cc00(0);
    sp10[1] = (s16)func_0029cc00(1);
    sp10[2] = (s16)func_0029cc00(2);
    sp10[4] = (s16)func_0029cc00(3);
    func_001029a0(9, sp10, 0x1C, 2);
    return 1;
}
// FUN_001765C0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001765c0);
// FUN_001766E0
s32 func_001766e0(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    func_00260510();
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    sp18[0] = func_0029cc00(0);
    sp18[1] = 0xFFFF;
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176770
s32 func_00176770(void)
{
    s32 sp18[2];

    if (func_0015f660() == 0) {
        return 0;
    }
    if (func_00102980() != 0xB) {
        func_00145080();
    }
    func_00260510();
    sp18[0] = func_0029cc00(0);
    sp18[1] = func_0029cc00(1);
    func_001029a0(0xB, sp18, 8, 4);
    return 1;
}
// FUN_00176810
s32 func_00176810(void)
{
    func_00159f70(func_0029cc00(0));
    return 1;
}
// FUN_00176850
s32 func_00176850(void)
{
    func_0015a630();
    return 1;
}

// FUN_00176880
s32 func_00176880(void)
{
    func_0029cf50(func_0015a160());
    return 1;
}
// FUN_001768B0
s32 func_001768b0(void)
{
    func_0029cf50(func_00155290());
    return 1;
}
// FUN_001768E0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_001768e0);
// FUN_00176A50
s32 func_00176a50(void)
{
    u8 *node;
    s32 count;

    node = (u8 *)func_001452b0(3);
    count = 0;
    while (node != NULL) {
        count += 1;
        node = *(u8 **)(node + 0x138);
    }
    func_0029cf50(count);
    return 1;
}

// FUN_00176AB0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00176ab0);
// FUN_00176B60
s32 func_00176b60(void) {
    s32 v;

    v = 0;
    if (*(s32 *)func_00155280() != 0) {
        v = func_00156170(*(s32 *)func_00155280()) & 0xFFFF;
    }
    func_0029cf50(v);
    return 1;
}

// FUN_00176BC0
s32 func_00176bc0(void) {
    s32 v;

    v = 0;
    if (*(s32 *)func_00155280() != 0) {
        v = func_00156180(*(s32 *)func_00155280()) & 0xFFFF;
    }
    func_0029cf50(v);
    return 1;
}

// FUN_00178560
s32 func_00178560(void)
{
    func_00174c20();
    return 1;
}

// FUN_00178590
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00178590);

// FUN_001786F0
s32 func_001786f0(void)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = func_0029d040();
    temp_2 = func_0029d050();
    if (temp_2 == 0) {
        func_0029dfe0(*(s32 *)(temp_16 + 0x148), func_0014ec50(0, 1));
        return 0;
    }
    if (func_00452490(temp_2) == 1) {
        return 0;
    }
    func_0029dfe0(*(s32 *)(temp_16 + 0x148), 0);
    return 1;
}

// FUN_00178790
s32 func_00178790(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_2 = func_00174680(*(s32 *)(func_00155280() + 8), temp_17 & 0xFFFF,
                           temp_16 & 0xFFFF);
    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 0x80000000) {
        func_0029cf50(1);
    } else if (temp_2 & 0x40000000) {
        func_0029cf50(2);
    } else {
        func_0029cf50(0);
    }
    return 1;
}

/* measured: nd 8. Keeping the cached scene index as u16 moves its narrowing
   into $s1 immediately after func_0029cc00; retail keeps the raw value in
   $s1 and narrows it into $a3 after the two halfword loads. Best measured
   body: object 108B in a 112B window. Negative evidence: func_0029cc00 is declared
   and defined s32 in code1_0017.c and src/Script/scrTraceCode.c. Raw s32 plus
   & 0xFFFF at each use, explicit (u16) casts, separate raw assignment, and the
   fourth-argument and all-wide func_00161630 prototypes all measured nd 10 or worse.
   Committed at nd 8. */

// FUN_00178870 NONMATCHING
#ifdef NON_MATCHING
s32 func_00178870(void) {
    u16 a = (u16)func_0029cc00(0);
    u8 *p = iGpffff9db0;
    s32 b = func_0015a160();

    func_0029cf50(func_00161630(*(u16 *)p, *(u16 *)(p + 4), b, a) & 0xFFFF);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00178870);
#endif

// FUN_001788E0
s32 func_001788e0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_002bd240(1);
    func_002bd270(*(s32 *)(func_0029d040() + 0x124));
    func_002bd280(temp_17, temp_16, 0, 0);
    return 1;
}



// FUN_001789D0
s32 func_001789d0(void)
{
    func_002bd410();
    func_002bd3c0();
    return 1;
}
// FUN_00178A00
s32 func_00178a00(void)
{
    func_0029cf50(*(u16 *)(D_007643D0 + 0xC));
    return 1;
}
// FUN_00178A30
s32 func_00178a30(void)
{
    u16 temp_3_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(D_007643D0 + 0x160);
    if (*(s32 *)(temp_3 + 8) != 0) {
        func_0029cf50(4);
    } else {
        temp_3_2 = *(u16 *)(temp_3 + 2);
        if ((s32)temp_3_2 >= 0x500) {
            func_0029cf50(3);
        } else if ((s32)temp_3_2 >= 0x400) {
            func_0029cf50(2);
        } else if ((s32)temp_3_2 >= 0x300) {
            func_0029cf50(1);
        } else {
            func_0029cf50(0);
        }
    }
    return 1;
}
// FUN_00178AF0
s32 func_00178af0(void)
{
    func_0029cf50((*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 7) & 1) != 0);
    return 1;
}
/* measured: only the independent GP load/zero-argument scheduling pair remains (nd 10).
   Measured in isolation at nd 10; nd_audit compiles the whole file with NON_MATCHING defined, which activates every preserved body at once and shifts this one. Committed at nd 6. */
// FUN_00178B30 NONMATCHING
#ifdef NON_MATCHING
s32 func_00178b30(void)
{
    s32 temp;
    s32 result;

    result = 0;
    temp = *(s32 *)(*(u8 **)(D_007643D0 + 0x160) + 8);
    if (temp != 0) {
        result = temp;
    }
    func_0029cf50(result);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00178b30);
#endif
// FUN_00178B70
s32 func_00178b70(void)
{
    func_0029cf50(*(u16 *)(*(u8 **)(D_007643D0 + 0x160) + 2));
    return 1;
}
// FUN_00178BA0
s32 func_00178ba0(void)
{
    func_0029cf50((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 6));
    return 1;
}
// FUN_00178BD0
s32 func_00178bd0(void)
{
    func_0029cf50((u16)*(u8 *)(*(u8 **)(D_007643D0 + 0x160) + 4));
    return 1;
}
// FUN_00178C00
/* Returns the stored constant: retail materializes the 1 in $v0 and stores
   from there, which only happens when it is also the return value. */
s32 func_00178c00(void)
{
    *(s32 *)(D_007643D0 + 8) = 1;
    D_007643D0 = 0;
    return 1;
}



/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0, so these stay here with their two group siblings until the
   real TU is split out. They were canonical windows with no marker, i.e.
   invisible to the verifier and supplied to the link as retail bytes. */

// FUN_00179FC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00179fc0);
// FUN_0017A700
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017a700);
// FUN_0017A8D0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017a8d0);
// FUN_0017AAE0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017aae0);
// FUN_0017ABD0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
#pragma opt_propagation off
void func_0017abd0(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);
    u8 *temp_4;

    base = D_00887300;
    base[0](7, 2);
    base[0](6, 1);
    base[0](8, 0);
    if (iGpffffba48 == 1) {
        base[0](0xE, 1);
    }
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    temp_4 = *(u8 **)(*(u8 **)(arg1 + 0x50) + 4);
    (*(void (**)(u8 *))(temp_4 + 0x48))(temp_4);
    if (iGpffffba48 == 1) {
        base[0](0xE, 1);
    }
}
/* measured: closing opt_propagation bracket for func_0017abd0. */
#pragma opt_propagation on
// FUN_0017ACC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017acc0);
// FUN_0017B350
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b350);
// FUN_0017B510
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b510);

// FUN_0017B990
void func_0017b990(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b9a0);

// FUN_0017BB50
void func_0017bb50(u8 *arg0, u8 *arg1)
{
    *(s32 *)(arg1 + 0x3C) = func_004571b0()[2];
    func_004571b0()[2] = 0;
    func_004571b0();
    *(s32 *)(arg1 + 0x38) = func_004571c0()[2];
    func_004571c0()[2] = 0;
    func_004571c0();
    *(s32 *)(arg1 + 0x34) = func_004571a0()[2];
    func_004571a0()[2] = 0;
    func_004571a0();
}



// FUN_0017BBE0
void func_0017bbe0(u8 *arg0, u8 *arg1)
{
    u8 temp_16;

    temp_16 = arg1[0x3C];
    func_004571b0()[2] = temp_16;
    func_004571b0();
    temp_16 = arg1[0x38];
    func_004571c0()[2] = temp_16;
    func_004571c0();
    temp_16 = arg1[0x34];
    func_004571a0()[2] = temp_16;
    func_004571a0();
}

// FUN_0017BC60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017bc60);

// FUN_0017C010
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c010);

// FUN_0017C270
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c270);

// FUN_0017C670
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c670);




// FUN_0017C930
s32 func_0017c930(u8 *arg0)
{
    extern u8 *func_001452b0(s32);
    extern s32 func_0014a160(void);
    extern s32 func_001623f0(void);
    extern u8 *func_00460990(void);
    extern void func_00460a80(void *, s32);
    extern void func_00460ac0(void *, void *);
    extern void func_004623a0(void *);
    extern void func_00479100(void *, void *);
    extern void func_0017bb50(u8 *, u8 *);
    extern void func_0017bbe0(u8 *);
    extern void func_0017bc60(u8 *, u8 *);
    extern void func_0017c010(u8 *);
    extern void func_0017c270(u8 *, u8 *);
    extern void func_0017c670(u8 *);
    u8 *list1;
    u8 *list3;
    u8 *state;
    s32 state_value;
    s32 i;
    u8 *work;
    u8 *p;

    state = *(u8 **)(arg0 + 0x38);
    list1 = func_001452b0(1);
    list3 = func_001452b0(3);
    state_value = *(s32 *)state;
    switch (state_value) {
    case 0:
        *(s32 *)state = state_value + 1;
        break;
    case 1: {
        func_00460a80(state + 4, 1);
        work = func_00460990();
        *(void **)(work + 8) = (void *)func_0017bb50;
        *(u8 **)(work + 0x10) = state;
        func_00460ac0(state + 4, work);
        while (list1 != NULL) {
            if ((*(s32 *)(list1 + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(list1 + 0x224) + 0x38) + 0xA) == 1) {
                work = func_00460990();
                *(void **)(work + 8) = (void *)func_0017bc60;
                *(u8 **)(work + 0x10) = list1;
                func_00460ac0(state + 4, work);
                if (*(s32 *)(*(u8 **)(*(u8 **)(list1 + 0x224) + 0x38)) > 0) {
                    if (func_0014a160() == 1 || func_001623f0() == 1) {
                        i = 0;
                        while (i < 5) {
                            p = *(u8 **)(list1 + 0x164) + i * 0xC;
                            *(u8 *)(p + 0x28C) = *(u8 *)(p + 0x28C) & 0xFE;
                            i += 1;
                        }
                    }
                    *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) | 4;
                    func_00479100(state + 4, *(u8 **)(list1 + 0x164));
                    *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(list1 + 0x164) + 0xD8) & ~4;
                    if (func_0014a160() == 1 || func_001623f0() == 1) {
                        i = 0;
                        while (i < 5) {
                            p = *(u8 **)(list1 + 0x164) + i * 0xC;
                            *(u8 *)(p + 0x28C) = *(u8 *)(p + 0x28C) | 1;
                            i += 1;
                        }
                    }
                }
                work = func_00460990();
                *(void **)(work + 0xC) = (void *)func_0017c010;
                *(u8 **)(work + 0x14) = list1;
                func_00460ac0(state + 4, work);
            }
            list1 = *(u8 **)(list1 + 0x138);
        }
        while (list3 != NULL) {
            if ((*(s32 *)(list3 + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(list3 + 0x230) + 0x38) + 0xA) == 1) {
                work = func_00460990();
                *(void **)(work + 8) = (void *)func_0017c270;
                *(u8 **)(work + 0x10) = list1;
                func_00460ac0(state + 4, work);
                if (*(s32 *)(*(u8 **)(*(u8 **)(list3 + 0x230) + 0x38)) > 0) {
                    func_00479100(state + 4, *(u8 **)(list3 + 0x164));
                }
                work = func_00460990();
                *(void **)(work + 0xC) = (void *)func_0017c670;
                *(u8 **)(work + 0x14) = list1;
                func_00460ac0(state + 4, work);
            }
            list3 = *(u8 **)(list3 + 0x138);
        }
        work = func_00460990();
        *(void **)(work + 0xC) = (void *)func_0017bbe0;
        *(u8 **)(work + 0x14) = state;
        func_00460ac0(state + 4, work);
        func_004623a0(state + 4);
        break;
    }
    case 2:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_0017CC90
void func_0017cc90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0017CCC0
s32 func_0017ccc0(u8 *arg0) {
    u8 *buf;

    func_0044ea90(D_005F18C0, 0x8E5);
    buf = D_008873F4[0](1, 0x40, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    return func_00451fc0(arg0, D_005F1910, 8, 0, 0, (void (*)(u8 *))func_0017c930, func_0017cc90, buf);
}


// FUN_0017CD60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017cd60);
// FUN_0017D060
void func_0017d060(u8 *arg0)
{
}
// FUN_0017D070
void func_0017d070(u8 *arg0)
{
    func_0043f9c8(D_007F1740, 0, 0x20);
    func_00451fc0(arg0, D_005F1950, 0x12, 0, 0, func_0017cd60, func_0017d060, D_007F1740);
}
// FUN_0017D0F0
void func_0017d0f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017D100
void func_0017d100(u8 *arg0)
{
    F2_0017 sp30;
    f32 temp_f1;
    s32 temp_17;
    s32 temp_4;
    s32 var_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = (s32)(func_00457120() + 0x20);
    func_003e42a0(&sp30, func_0047a2f0(*(u8 **)D_007EFA00) + 0x30, (u8 *)temp_17);
    temp_f1 = 640.0f * (sp30.first / sp30.second);
    if (temp_f1 <= 100.0f) {
        var_3 = 0;
    } else if (temp_f1 < 540.0f) {
        var_3 = 1;
    } else {
        var_3 = 2;
    }
    temp_4 = var_3 * 8;
    *(s16 *)(temp_16 + 0xC) = *(s32 *)((u8 *)D_005F1930 + temp_4);
    *(s16 *)(temp_16 + 0xE) = *(s32 *)((u8 *)D_005F1934 + temp_4);
}
// FUN_0017D1F0
void func_0017d1f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   f32 arg5, f32 arg6, f32 arg7)
{
    s32 temp_3;

    temp_3 = arg2 * 8;
    func_0017d240(arg0, arg1, arg2, arg3,
                  *(s32 *)(D_005F1A60 + temp_3) + 1,
                  *(s32 *)(D_005F1A64 + temp_3) + 1,
                  arg4, arg5, arg6, arg7);
}
// FUN_0017D240
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017d240);