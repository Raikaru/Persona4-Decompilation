/* Consolidated Persona 4 source units. */
/* Original translation unit evtScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern void func_00106390();
extern void (*jtbl_008873EC[])(void *ptr);

typedef int (*code)(...);
extern code DAT_008873ec_abs[];


#pragma alias DAT_008873ec_abs DAT_008873ec

extern void func_0044ea90(const void *file, s32 line);
extern void func_0046d730(const void *file, u32 line);
extern u8 D_0063CF80[];
extern u8 D_0063CF90[];
extern u8 D_0063CFA0[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u16 D_008C024E[];
extern u8 D_00795E60[];
extern s32 func_00451fc0(s32, u8 *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern void *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern s32 func_00452080(void *task);
extern u8 *func_00452380(s8 *name);
extern s32 func_00452490(void *target);
extern void func_00146630(u32);
extern u16 func_00145780(u16, s32, s32);
extern void func_00269c20(s32, s32);
extern u16 *func_00145270(s32);
extern s32 func_004782b0(u32 arg0);
extern u8 *func_0047a250(s32);
extern void func_00286ff0(u8 *, s32, u16 *);
extern s32 func_00285af0();
extern u8 *func_00285480();
extern u8 *func_00285b80();
extern s32 func_0029cc00();
extern s32 func_0029d020(void);
extern s32 func_00478140(u16, u16, s32);
extern s32 func_00286350();
extern s32 func_002909a0(void *arg0);
extern void func_00279d40(s32 arg0);
extern u8 *func_00279030(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                         s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 *func_002736d0(u8 **arg0, s32 arg1);
extern s32 func_002738d0(u8 *arg0);
extern void func_00272a10(u8 *arg0, f32 fparg0, f32 fparg1);
extern void func_00272ba0(u8 *arg0, s32 arg1);

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v0,$v0,$s0`; every callsite spelling (p+scaled,
   scaled+p, a named s32 local) is canonicalized back to base-first. Expand it at
   the use rather than through a local, so nothing stays live across a call. */
static inline u32 evtSlot(u32 offset, u32 base)
{
    return offset + base;
}
extern void func_00273170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00271b70(u8 *arg0);
extern f32 func_0044b7b0(f32 fparg0);
/* INCLUDE_ASM fallback below; address taken by func_00298550. */
extern s32 func_00298370(void);
/* INCLUDE_ASM fallback below; address stored by func_00298b80. */
extern void func_00298990(s32 arg0, s32 arg1);

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

/* measured: retail materializes func_00285b80's args as `lw $a1,4($s0)` then
   `move $a0,$v0` (load before the call-result move); mwcc b210 always emits
   the move first, then the load (nd 4, single word, both nested-call and
   explicit-temp spellings). Argument-evaluation-order floor. */
// FUN_00298370
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298370);
// FUN_00298510
void func_00298510(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_00298550
s32 func_00298550(void)
{
    s32 v0;
    s32 v1;
    u16 id;
    u8 *p;
    u8 *work;

    v0 = func_0029cc00(0);
    v1 = func_0029cc00(1);
    if (func_0029d020() == 0) {
        id = (u16)(((v0 + 0x384) & 0x3FF) | 0xC00);
        if (func_00145270(id) != 0) {
            p = (u8 *)func_00145270(id);
            if (*(u16 *)(*(s32 *)(p + 0x164) + 0xD4) == 5 &&
                *(u16 *)(*(s32 *)(p + 0x164) + 0xD6) == v1) {
                func_00269c20(id, 1);
                return 1;
            }
        }
        func_0044ea90(D_0063CF80, 0x4F);
        work = D_008873F4[0](1, 8, 0x40000);
        *(s32 *)(work + 0) = func_00478140(5, v1 & 0xFFFF, 0);
        *(s32 *)(work + 4) = v0;
        if (*(s32 *)(work + 0) == 0) {
            func_0046d730(D_0063CF80, 0x52);
        }
        func_00451fc0(0, D_0063CF90, 0xF, 0, 0, (void (*)(u8 *))func_00298370,
                      (void (*)(u8 *))func_00298510, work);
    } else {
        if (func_00452490(func_00452380((s8 *)D_0063CF90)) != 0) {
            goto done;
        }
        return 1;
    }
done:
    return 0;
}
/* The addu operand order this note called an allocator floor is fixed by the
   `evtSlot` helper above, expanded at the use. The note was right that a named
   s32 local and every p+scaled / scaled+p callsite spelling get canonicalized
   back to base-first; only carrying the operands through a helper's parameters
   holds the order, and expanding it per use keeps nothing live across a call. */
// FUN_00298700
s32 func_00298700(void) {
    s32 slot;
    s32 value;
    s32 kind;
    u8 *p;

    slot = func_0029cc00(0);
    value = func_0029cc00(1);
    if (slot >= 5) {
        return 1;
    }
    kind = func_00286350();
    if (kind == 0) {
        return 1;
    }
    p = (u8 *)func_00452560(kind);
    if (func_002909a0(p + 0x678) == 0) {
        return 1;
    }
    *(s32 *)((u8 *)evtSlot(slot * 4, (u32)p) + 0x698) = value;
    return 1;
}

// FUN_002987D0
void func_002987d0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    u8 *node;
    s32 sum;
    u8 *p;
    u8 *spAC;

    func_00279d40(arg5);
    spAC = (u8 *)func_00279030((arg0 << 8) | arg1, fparg0, fparg1, fparg2,
                               arg2, arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        p = (u8 *)func_002736d0(&spAC, arg7);
        if (p == NULL) {
            p = spAC;
            spAC = NULL;
        }
        node = p;
        sum = 0;
        while (node != NULL) {
            sum += func_002738d0(node);
            node = *(u8 **)(node + 0x24);
        }
        func_00272a10(p, fparg0 - (f32)sum / 2.0f, fparg1);
        func_00272ba0(p, arg1 | ~0xFF);
        if (spAC != NULL) {
            func_00273170(p, 1, 0);
        }
        func_00271b70(p);
        if (spAC != NULL) {
            func_00271b70(spAC);
        }
    }
}
/* measured: retail computes `addiu;mtc1;cvt.s.w` for (f32)(diff-0x10E) BEFORE
   loading the ratio constant, then `mul/div/add.s`; mwcc b210 always hoists
   the shared ratio lwc1 ahead of the cvt chain (nd 7-8, one 5-word cluster;
   tried inline, t-local, p-local, and t*ratio orderings — every spelling
   keeps the hoist or flips mul.s operands). Load-scheduling floor. */
// FUN_00298990
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298990);
// FUN_00298B80
s32 func_00298b80(s32 arg0)
{
    u8 *base;
    u8 *p;

    base = (u8 *)func_00452560();
    *(s32 *)(base + 4) += 1;
    if (D_008C024E[0] & 0x9FF) {
        func_00106390(0x1211, 1);
    }
    p = (u8 *)func_00460990();
    *(void **)(p + 8) = (void *)func_00298990;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_00795E60, p);
    return 0;
}
// FUN_00298C10
void func_00298c10(void) {
    u8 *p = (u8 *)func_00452560();

    func_00106390(0x1211, 0);
    jtbl_008873EC[0](p);
}

// FUN_00298C60
s32 func_00298c60(void)
{
    s32 task;
    s32 v0;
    u8 *work;

    func_00106390(0x1211, 0);
    task = (s32)func_00452380((s8 *)D_0063CFA0);
    if (task != 0) {
        func_00452080((void *)task);
    }
    v0 = func_00285af0();
    func_0044ea90(D_0063CF80, 0xF6);
    func_00451fc0(v0, D_0063CFA0, 0xF, 0, 0, (void (*)(u8 *))func_00298b80,
                  (void (*)(u8 *))func_00298c10, D_008873F4[0](1, 8, 0x40000));
    return 1;
}
