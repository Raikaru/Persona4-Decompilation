#include "include_asm.h"
#include "type.h"
extern void func_0015a630();
extern void func_00174c20();
extern s32 func_0015f660();
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern void func_00260510(void);
extern void *func_0043f9c8(void *dst, s32 value, s32 size);
extern u8 *func_00155280(void);
extern s32 func_00156170(s32 arg0);
extern s32 func_00156180(s32 arg0);
extern s32 func_0015a160(void);
extern s32 func_00161630(u16 a, u16 b, u16 c, u16 d);
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern u8 D_005F18C0[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_005F1910[];
s32 func_0017c930(u8 *arg0);
void func_0017cc90(u8 *arg0);
extern void func_0044ea90(const void *msg, s32 id);
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c, void (*init)(u8 *), void (*close)(u8 *), u8 *buf);

extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern void func_0029cf50(s32 arg0);

extern s32 func_0029cc00(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern u8 *D_007643D0;

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

// FUN_00176850
s32 func_00176850(void)
{
    func_0015a630();
    return 1;
}

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

/* measured: nd 10. Retail materialises the two halfword loads into $a0/$a1
   before narrowing the cached scene index into $a3; b210 emits the narrowing
   first. Hoisting the narrowed value into a local ahead of the call and
   declaring func_00161630's third and fourth parameters u16 so the mask is
   implicit both leave it at nd 10 - argument-materialisation order that the
   callee's prototype does not reach. Committed at nd 10. */
// FUN_00178870 NONMATCHING
#ifdef NON_MATCHING
s32 func_00178870(void) {
    s32 a = func_0029cc00(0);
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

