#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldEnvironment.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00161460(s32 arg0, s32 arg1, s32 arg2);
extern void func_00161500(s32 arg0);

extern s16 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s64 arg0, s32 arg1);
extern s32 func_00154720(u16 arg0, u16 arg1, s64 arg2);
extern s32 func_00106330(s32 arg0);
extern u8 *func_0015a0c0(void);

extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_005EFE50[];
extern char D_005EFE68[];
extern s32 func_00153a00(u8 *task);
extern void func_00153a30(u8 *task);


extern s32 func_0014eec0(void);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442088();
extern s32 func_00454570(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern char D_005EFE78[];
extern char D_005EFED0[];
extern char D_005EFE90[];
extern s32 func_0014a2a0();
extern u8 *iGpffff9db0;
extern char iGpffff9e18;
extern char iGpffff9e20;
extern s32 func_004553c0(u8 *arg0);
extern u8 *func_00455f70(void *arg0, void *arg1);
extern void func_0043f810(void *arg0, void *arg1, u32 arg2);
extern void func_0043f9c8(void *arg0, s32 arg1, u32 arg2);
extern u8 *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 *func_00155280(void);
extern void func_0016e590();
extern void func_0016e9f0(s32 arg0, void *arg1);
extern void func_0016ea20(s32 arg0, f32 arg1);
extern void func_0016ea30(s32 arg0, f32 arg1);
extern void func_0016eaa0(s32 arg0, s32 arg1, void *arg2);
extern u8 *func_0016eaf0(s32 arg0);
extern void func_0016eb00(s32 arg0);
extern void func_0046d700(const char *arg0, s32 arg1, void *arg2, void *arg3);
extern void func_00454bd0(u8 *arg0);
extern char D_005EFEF0[];

typedef struct CmrVec3 {
    f32 x;
    f32 y;
    f32 z;
} CmrVec3;



// FUN_00153A60
s32 func_00153a60(s32 arg0) {
    u8 *p;
    s32 result;

    func_0044ea90(&D_005EFE50[0], 0x58);
    p = D_008873F4[0](1, 0x14, 0x40000);
    if (p == NULL) {
        return 0;
    }
    result = (s32)func_00451fc0((void *)(arg0), (const void *)(&D_005EFE68[0]), 0xF, 0, 0, func_00153a00, func_00153a30, (u8 *)(p));
    *(s32 *)(p + 0x8) = 1;
    *(s32 *)(p + 0xC) = 0xC8;
    return result;
}

// FUN_00153B20
void func_00153b20(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(s32 *)(p + 0x4) = arg1;
    func_00161460(arg1, *(s32 *)(p + 0x8), *(s32 *)(p + 0x10));
}
// FUN_00153B60
void func_00153b60(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 8) = arg1;
    func_00161460(*(s32 *)(work + 4), arg1, *(s32 *)(work + 0x10));
}



// FUN_00153B90
void func_00153b90(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0x10) = arg1;
    func_00161460(*(s32 *)(work + 4), *(s32 *)(work + 8), arg1);
}

// FUN_00153BD0
void func_00153bd0(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0xC) = arg1;
    func_00161500(arg1);
}

// FUN_00153C00
s32 func_00153c00(s32 arg0) {
    char spA0[0x80];
    char sp20[0x80];
    s32 g;

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        func_00442830(&spA0, D_005EFE78);
        if (func_0014a2a0(*(u16 *)iGpffff9db0, arg0 & 0xFFFF) != 0) {
            func_00442088(&sp20, D_005EFE90, *(s32 *)iGpffff9db0 - 0x14, arg0);
        } else {
            func_00442088(&sp20, D_005EFE90, *(s32 *)iGpffff9db0, arg0);
        }
        g = *(s32 *)iGpffff9db0;
        if ((g >= 0x33) && (g < 0x3B)) {
            func_00442088(&sp20, D_005EFE90, g - 0x1E, 0);
        }
        if (func_00454570(&sp20) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x1A1);
        return (s32)func_00454a60(&sp20, 0);
    }
    return 1;
}

/* measured: MATCH 0 via tools/probe_variants.py src/promoted/k_fldEnvironment.c func_00153d60 (fnalign retail 592/object 592 exact, 0 edits; probe 21->7 via opt_loop_invariants on, 7->4 via P-index 0x10001 loop ((u8 **)P)[i+10] for lw-before-sll, 4->0 via P-index 0x68/0x78 loops ((s32 *)P)[i+26/30]; five follow-up rounds R1 index ties except hoisted-row 257 fail, R2 decl-orders tie plus hoisted-count/P 535 fail, R3 pragmas loop_invariants 7 win vs unroll/schedule tie, R4 index-under-pragma 4 win, R5 68/78 P-index 0 MATCH). De-noised m2c 347 plus rw 363 plus types 3-vs-2 into file idiom. Production live. */
// FUN_00153D60
#pragma push
#pragma opt_loop_invariants on
s32 func_00153d60(u8 *arg0, s32 arg1)
{
    extern u8 *func_001452b0(s32 arg0);
    extern void func_00149d60(s32 arg0);
    extern void func_00149db0(s32 arg0);
    extern void func_00149e00(s32 arg0);
    extern void func_00149e50(s32 arg0);
    extern u8 *func_00149ca0(void);
    extern u8 *func_00149ce0(void);
    extern u8 *func_00149d20(void);
    extern void func_001537c0(u8 *arg0, u8 *arg1);
    extern s32 func_001838d0(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_00185150(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s32 arg6, u8 *arg7);
    extern void func_0018c700(f32 arg0);
    extern void func_0018c750(f32 arg0);
    extern u8 *func_003e8180(u8 *arg0, f32 arg1);
    extern u8 *func_003e81c0(u8 *arg0, f32 arg1);
    extern void func_00452080(void *arg0);
    extern void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
    extern void func_00457170(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
    extern void func_00458f40(void *arg0, void *arg1);
    extern void *func_0047a310(s32 arg0);
    extern char D_005EFEB0[];
    extern s32 iGpffffba48;
    extern u8 iGpffffba4c;
    extern u8 iGpffffba50;
    extern u8 iGpffffba54;
    extern u8 iGpffffba58;
    extern u8 iGpffffba5c;
    extern u8 iGpffffba60;
    extern u8 iGpffffba64;
    extern u8 iGpffffba68;
    extern f32 iGpffffba6c;
    typedef struct { f32 x; f32 y; f32 z; f32 w; } F4;
    char spAC[4];
    char sp60[0x4C];
    u8 *data;
    u8 *tmp4;
    u8 *tmp5;
    f32 fsave;

    if (arg0 == NULL) {
        return 1;
    }
    if ((func_0014eec0() == 0) && (func_004553c0(arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        data = *(u8 **)(arg0 + 0x110);
    } else {
        func_00442088(&sp60, D_005EFEB0, *(s32 *)iGpffff9db0, arg1);
        if (func_0014a2a0(*(u16 *)iGpffff9db0, arg1 & 0xFFFF) != 0) {
            func_00442088(&sp60, D_005EFEB0, *(s32 *)iGpffff9db0 - 0x14, arg1);
        }
        {
            s32 g = *(s32 *)iGpffff9db0;
            if ((g >= 0x33) && (g < 0x3B)) {
                func_00442088(&sp60, D_005EFEB0, g - 0x1E, 0);
            }
        }
        data = func_00455f70(&sp60, &spAC);
        if (data == NULL) {
            return 1;
        }
        if (data == NULL) {
            func_0046d700(D_005EFE50, 0x1E3, &iGpffff9e20, &sp60);
        }
    }
    tmp4 = func_001452b0(4);
    tmp5 = func_001452b0(5);
    func_00149d60(*(u8 *)(data + 8));
    func_00149db0(*(u8 *)(data + 9));
    func_00149e00(*(u8 *)(data + 0xA));
    func_00149e50(*(u8 *)(data + 0xB));
    if (*(u8 *)(data + 0xF) == 1) {
        iGpffffba48 = 1;
    } else {
        iGpffffba48 = 0;
    }
    iGpffffba4c = *(u8 *)(data + 0xC);
    iGpffffba50 = *(u8 *)(data + 0xD);
    iGpffffba54 = *(u8 *)(data + 0xE);
    iGpffffba58 = 0;
    iGpffffba5c = *(u8 *)(data + 0xC);
    iGpffffba60 = *(u8 *)(data + 0xD);
    iGpffffba64 = *(u8 *)(data + 0xE);
    iGpffffba68 = 0;
    func_00457140(*(u8 *)(data + 0xC), *(u8 *)(data + 0xD), *(u8 *)(data + 0xE), 0);
    func_00457170(*(u8 *)(data + 0xC), *(u8 *)(data + 0xD), *(u8 *)(data + 0xE), 0);
    func_003e81c0(func_00457120(), *(f32 *)(data + 0x14));
    fsave = *(f32 *)(data + 0x10);
    *(f32 *)(func_00457120() + 0x88) = fsave;
    func_00457120();
    if ((u32)*(s32 *)(data + 4) > 0x10003U) {
        if (*(f32 *)(data + 0x18) > 1.0f) {
            func_003e8180(func_00457120(), *(f32 *)(data + 0x18));
        }
        if (*(f32 *)(data + 0x18) == 50.0f) {
            func_003e8180(func_00457120(), 100.0f);
        }
        if (*(u8 *)(data + 0x1FF) == 0xFF) {
            func_00457140(*(u8 *)(data + 0x1FC), *(u8 *)(data + 0x1FD), *(u8 *)(data + 0x1FE), 0);
            func_00457170(*(u8 *)(data + 0x1FC), *(u8 *)(data + 0x1FD), *(u8 *)(data + 0x1FE), 0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10004U) {
        iGpffffba6c = *(f32 *)(data + 0x200);
    } else {
        iGpffffba6c = *(f32 *)(data + 0x14);
    }
    {
        u8 *dst = func_00149ca0();
        *(F4 *)dst = *(F4 *)(data + 0x1C);
    }
    {
        u8 *dst = func_00149ce0();
        *(F4 *)dst = *(F4 *)(data + 0x2C);
    }
    {
        u8 *dst = func_00149d20();
        s32 *src = (s32 *)(data + 0x40);
        s32 count = 8;
        s32 first;
        s32 second;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)dst = first;
            *(s32 *)(dst + 4) = second;
            dst += 8;
        } while (count > 0);
    }
    if (tmp5 != NULL) {
        *(F4 *)(tmp5 + 0x140) = *(F4 *)(data + 0x80);
        *(F4 *)(tmp5 + 0x150) = *(F4 *)(data + 0x90);
        {
            s32 *src = (s32 *)(data + 0xA0);
            u8 *dst = tmp5 + 0x160;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        *(F4 *)(tmp5 + 0x1A0) = *(F4 *)(data + 0xE0);
        {
            s32 *src = (s32 *)(data + 0xF0);
            u8 *dst = tmp5 + 0x1B0;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        if ((u32)*(s32 *)(data + 4) > 0x10002U) {
            *(CmrVec3 *)(tmp5 + 0x1F0) = *(CmrVec3 *)(data + 0x1F0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10000U) {
        s32 i;
        for (i = 0; i < *(s32 *)(iGpffff9db0 + 0x24); i++) {
            *(CmrVec3 *)(((u8 **)iGpffff9db0)[i + 10] + 0xA24) = *(CmrVec3 *)(data + 0x130);
            func_001537c0(((u8 **)iGpffff9db0)[i + 10], ((u8 **)iGpffff9db0)[i + 10] + 0xA24);
        }
    }
    if (((u32)*(s32 *)(data + 4) > 0x10001U) && (tmp4 != NULL)) {
        *(F4 *)(tmp4 + 0x140) = *(F4 *)(data + 0x13C);
        *(F4 *)(tmp4 + 0x150) = *(F4 *)(data + 0x14C);
        {
            s32 *src = (s32 *)(data + 0x160);
            u8 *dst = tmp4 + 0x160;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        *(F4 *)(tmp4 + 0x1A0) = *(F4 *)(data + 0x1A0);
        {
            s32 *src = (s32 *)(data + 0x1B0);
            u8 *dst = tmp4 + 0x1B0;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        if ((u32)*(s32 *)(data + 4) > 0x10002U) {
            *(CmrVec3 *)(tmp4 + 0x1F0) = *(CmrVec3 *)(data + 0x1F0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10002U) {
        u8 *tmp1 = func_001452b0(1);
        u8 *tmp3 = func_001452b0(3);
        s32 i;
        for (i = 0; i < *(s32 *)(iGpffff9db0 + 0x24); i++) {
            u8 *base = *(u8 **)(iGpffff9db0 + i * 4 + 0x28);
            *(CmrVec3 *)(base + 0xA30) = *(CmrVec3 *)(data + 0x1F0);
        }
        while (tmp1 != NULL) {
            func_00458f40(func_0047a310(*(s32 *)(tmp1 + 0x164)), data + 0x1F0);
            tmp1 = *(u8 **)(tmp1 + 0x138);
        }
        while (tmp3 != NULL) {
            if ((*(u32 *)(tmp3 + 0x28) & 0x10000000) != 0) {
                func_00458f40(func_0047a310(*(s32 *)(tmp3 + 0x164)), data + 0x1F0);
            }
            tmp3 = *(u8 **)(tmp3 + 0x138);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10005U) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (((s32 *)iGpffff9db0)[i + 26] != 0) {
                func_00452080((void *)((s32 *)iGpffff9db0)[i + 26]);
                ((s32 *)iGpffff9db0)[i + 26] = 0;
            }
            {
                u8 *p = data + i * 0x24;
                if (*(s32 *)(p + 0x204) != 0) {
                    ((s32 *)iGpffff9db0)[i + 26] = func_001838d0(0, *(s32 *)(p + 0x208), *(f32 *)(p + 0x20C), *(f32 *)(p + 0x210), *(f32 *)(p + 0x214), *(f32 *)(p + 0x218), *(s32 *)(p + 0x21C), *(s32 *)(p + 0x220), *(s32 *)(p + 0x224));
                }
            }
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10006U) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (((s32 *)iGpffff9db0)[i + 30] != 0) {
                func_00452080((void *)((s32 *)iGpffff9db0)[i + 30]);
                ((s32 *)iGpffff9db0)[i + 30] = 0;
            }
            {
                u8 *p = data + i * 0x38;
                if (*(s32 *)(p + 0x294) != 0) {
                    ((s32 *)iGpffff9db0)[i + 30] = func_00185150(0, *(s32 *)(p + 0x298), *(f32 *)(p + 0x29C), *(f32 *)(p + 0x2A0), *(f32 *)(p + 0x2A4), *(s16 *)(p + 0x2A8), *(s16 *)(p + 0x2AA), *(s16 *)(p + 0x2AC), *(s16 *)(p + 0x2AE), *(s32 *)(p + 0x2B0), p + 0x2B4);
                }
            }
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10007U) {
        func_0018c700(*(f32 *)(data + 0x374));
        func_0018c750(*(f32 *)(data + 0x378));
    }
    if (func_0014eec0() == 0) {
        func_00454bd0(arg0);
    }
    return 1;
}

#pragma pop


// FUN_001546A0
void func_001546a0(u16 arg0, u16 arg1)
{
    func_00154720(arg0, arg1, func_00110960(func_001060b0(), func_001060c0() & 0xFF));
}

/* measured: block-3 func_0015a0c0 handling. Retail places the non-NULL load
   OUT OF LINE (bnez $v0, load; b return; load: lbu; move; b return) spanning
   8 instructions; the plain if/else and empty-if+else both compile the load
   inline (beqz skip; lbu inline), shrinking the block by 8B and shifting the
   switch dispatch + every later branch target by one word (nd 142). switch
   form over the boolean adds a jump table (nd 196). Return type is s32
   (retail does move $v0,$sN, no dsll32/dsra32 truncation; m2c's s16 is wrong).
   var_18=$s2, var_19=$s3 (declare var_18 second). Case 5 of the jtbl_00746C20
   switch goes straight to block_42 (own empty case needed). */
/* measured: discarded positive-branch candidate object 980B/window 1008B, normalized_diff 232; restored to bare INCLUDE_ASM. */
/* Floor: 177 differing words, from a first reconstruction of the m2c draft.
   What it took: the state and the working value are 32-bit locals and the
   returns carry no `(s16)` cast - each cast cost a dsll32/dsra32 pair that
   retail does not have - and the arg2 case labels are written in the order
   that makes the compare chain come out reversed, which is retail's.
   A variant that moves the shared `common` block to the end of the switch
   instead of the `default:` position scores 186 words but only 42 edit
   instructions against 154 here, so its block layout is much closer to
   retail's; the remaining difference there is a handful of un-inverted
   branch pairs (retail keeps `beqz far` plus `b near` where this build
   emits one inverted branch), which opt_rebuildconditionals,
   no_branch_likely, schedule, propagation and dead-assignment do not
   move. */
/* measured this session: fresh probe 177wd / fnalign 193 edits (was 154 stale) confirms floor; slti inclusive (value>=3&&<9 -> >2&&<=8 fixes slti $at,$s3,3 dest to $at, tie 177wd; second $at already matches); short-by-N hunt checked (251 vs 250, 1 short, but shortfall is switch common-block layout per top-down fnalign, not trailing dead-arm chain). Banked. */
/* measured 00154720 (owner, 2026-09-19): fnalign **193 -> 105 edits**, count
   250 -> 248 against retail 251, by putting the switch arms in the order the
   JUMP TABLE uses rather than ascending case order.  The layout is read out of the
   retail ELF - the `sltiu` bound gives the entry count, each 4-byte entry gives an
   arm address, and sorting the case values by arm address is the order retail
   emitted them in; entries sharing the most common address are the default.
   Ascending order is what a lowered if-CHAIN wants.  A jump table already encodes
   its own order and the source has to agree with it.  Swept over every first-party
   floor with a table: 20 were already in layout order, 5 improved (274, 88, 50, 37
   and 7 edits) and 13 got worse, so it is measured per function like every other
   spelling. */
/* measured 00154720 (owner, 2026-09-19): fnalign **105 -> 101 edits**, count
   248 -> 249 against retail 251, by putting one switch's arms in REVERSED
   order.  Case order is EMISSION order and the right one is whatever retail emitted:
   a chain converted to a switch wants ascending, a jump table wants the table's own
   layout, and a `beq` chain with no table can want the reverse of the source order.
   All three orderings were measured on every switch in this body and this is the
   only one that improved it; swept across the 167 first-party floors carrying a
   switch, just four responded at all. */
// FUN_00154720 NONMATCHING
#ifdef NON_MATCHING
s32 func_00154720(u16 arg0, u16 arg1, s64 arg2)
{
    extern s32 func_001060c0(void);
    extern s32 func_00106330(s32 id);
    extern s32 func_0014a160(void);
    extern u8 *func_0015a0c0(void);
    s32 value;
    s32 hour;
    s32 result;
    s32 state;
    s32 kind;
    s32 weather;
    u8 *entry;

    state = arg1;
    value = state;
    weather = func_001060c0() & 0xFF;
    kind = arg0;
    if (kind == 0x1C && state == 2) {
        if (func_00106330(0xF52) == 1) {
            result = 3;
        } else {
            result = 2;
        }
        return result;
    }
    if (kind >= 0x14 && kind < 0x28) {
        return state;
    }
    if ((kind < 0x14 || kind >= 0x28) && func_0014a160() == 1) {
        entry = func_0015a0c0();
        if (entry != NULL) {
            value = *(u8 *)(entry + 0xD);
        }
        return value;
    }
    switch (kind) {
    case 4:
        return state;
    case 7:
        if (state != 1) {
            value = 2;
        }
        goto common;
    case 8:
        if (state == 2) {
            value = 1;
        }
        if ((s32)value > 2 && (s32)value <= 8) {
            return value;
        }
        goto common;
    case 9:
        if (state != 1 && state != 4) {
            return state;
        }
        goto common;
    case 13:
        if (state != 8) {
            return state;
        }
        goto common;
    case 10:
        if (state == 4) {
            value = 3;
        }
        goto common;
    case 11:
        if (state == 2) {
            return state;
        }
        goto common;
    case 12:
        if (state == 4) {
            return state;
        }
        goto common;
    case 14:
    case 15:
    case 16:
        return state;
    case 17:
        if (state == 2) {
            value = 1;
        }
        goto common;
    default:
    case 6:
        if ((s32)state < 6) {
            value = 1;
        }
common:
        if (func_00106330(0x8A) == 1 &&
            (((kind != 7 || state != 2) && (kind != 7 || state != 3)) ||
             (weather & 0xFF) != 5)) {
            switch (arg2) {
            case 2:
            case 0:
                value += 0x320;
                break;
            case 4:
            case 3:
            case 1:
                value += 0x384;
                break;
            }
        } else {
            switch (arg2) {
            case 4:
            case 3:
            case 1:
                hour = weather & 0xFF;
                if (hour < 5) {
                    value += 0x258;
                } else if (hour == 5) {
                    value += 0x2BC;
                }
                break;
            case 2:
                hour = weather & 0xFF;
                if (hour < 5) {
                    value += 0x190;
                } else if (hour == 5) {
                    value += 0x1F4;
                }
                break;
            case 0:
                hour = weather & 0xFF;
                switch (hour) {
                case 4:
                    value += 0x64;
                    break;
                case 5:
                    value += 0xC8;
                    break;
                }
                break;
            }
        }
        return value;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00154720);
#endif

// FUN_00154B10
s32 func_00154b10(void) {
    char sp90[0x80];
    char sp10[0x80];

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        func_00442830(&sp90, D_005EFE78);
        func_00442088(&sp10, D_005EFED0, *(s32 *)(iGpffff9db0 + 0), *(s32 *)(iGpffff9db0 + 4));
        if (func_00454570(&sp10) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x571);
        return (s32)func_00454a60(&sp10, 0);
    }
    return 1;
}

/* measured: func_00154be0 (nd 110, obj 1188B vs window 1168B). Frame -0xF0
   correct once spA0=0x4C@0xA0, spEC=0x4@0xEC (declared spEC first). Residuals:
   (1) copy-loop source ptr colored $a2 instead of retail $a1 -- register alloc;
   (2) the 3-float store at var_16+0x54..0x5C to arg5 needs ONE struct assignment
   (retail loads $f2,$f1,$f0 then stores all three; per-field statements
   interleave) -- brief lever 5;
   (3) the 0x10001/0x10002 guards must be written `x < 0x10001` (sltu $at +
   bnez) not `x >= 0x10001` -- brief lever 2 comparison form;
   (4) 20 extra bytes of body code. The double `if (var_16==NULL){return 1}
   if(var_16==NULL){func_0046d700...}` mirrors retail's dead func_0046d700 block.
   func_003e9cb0 first arg is a pointer loaded from [4] (cast to void*). */
// FUN_00154BE0
s32 func_00154be0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, s32 *arg4,
                  u8 *arg5, f32 *arg6, f32 *arg7, s32 *arg_sp0, s32 *arg_sp8)
{
    char spEC[4];
    char spA0[0x4C];
    u8 *data;

    if (arg0 == 0) {
        return 1;
    }
    if ((func_0014eec0() == 0) && (func_004553c0(arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        data = *(u8 **)(arg0 + 0x110);
    } else {
        func_00442088(&spA0, D_005EFEF0,
                      *(s32 *)iGpffff9db0, *(s32 *)(iGpffff9db0 + 4));
        data = func_00455f70(&spA0, &spEC);
        if (data == 0) {
            return 1;
        }
        if (data == 0) {
            func_0046d700(D_005EFE50, 0x5A1, &iGpffff9e20, &spA0);
        }
    }
    if (arg1 != 0) {
        s32 *src;
        s32 count;
        s32 first;
        s32 second;

        src = (s32 *)(data + 0x10);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)arg1 = first;
            *(s32 *)(arg1 + 4) = second;
            arg1 += 8;
        } while (count > 0);
        *arg3 = *(f32 *)(data + 8);
        *arg4 = *(u16 *)(data + 0x50);
        *(CmrVec3 *)arg5 = *(CmrVec3 *)(data + 0x54);
        *arg6 = *(f32 *)(data + 0x60);
        *arg7 = *(f32 *)(data + 0x64);
        if (*(u32 *)(data + 4) > 0x10000U) {
            func_0043f810(arg_sp0, data + 0x68, 0x20);
            func_0043f810(arg_sp8, data + 0x88, 0x180);
        } else {
            func_0043f9c8(arg_sp0, 0, 0x20);
            func_0043f9c8(arg_sp8, 0, 0x180);
        }
        if (*(u32 *)(data + 4) > 0x10001U) {
            src = (s32 *)(data + 0x210);
            count = 8;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)arg2 = first;
                *(s32 *)(arg2 + 4) = second;
                arg2 += 8;
            } while (count > 0);
        } else {
            *(f32 *)(arg2 + 0x28) = 1.0f;
            *(f32 *)(arg2 + 0x14) = 1.0f;
            *(f32 *)(arg2 + 0) = 1.0f;
            *(f32 *)(arg2 + 0x10) = 0.0f;
            *(f32 *)(arg2 + 8) = 0.0f;
            *(f32 *)(arg2 + 4) = 0.0f;
            *(f32 *)(arg2 + 0x24) = 0.0f;
            *(f32 *)(arg2 + 0x20) = 0.0f;
            *(f32 *)(arg2 + 0x18) = 0.0f;
            *(f32 *)(arg2 + 0x38) = 0.0f;
            *(f32 *)(arg2 + 0x34) = 0.0f;
            *(f32 *)(arg2 + 0x30) = 0.0f;
            *(s32 *)(arg2 + 0xC) |= 0x20003;
        }
    } else {
        s32 i;
        s16 id;
        s32 *src;
        s32 count;
        u8 *dst;
        s32 first;
        s32 second;

        func_004577d0(func_00457120(), *(f32 *)(data + 8));
        func_003e9cb0((void *)*(s32 *)(func_00457120() + 4),
                      data + 0x10, 0);
        func_0016e590(func_00155280()[1], *(u16 *)(data + 0x50));
        func_0016e9f0(func_00155280()[1], data + 0x54);
        func_0016ea20(func_00155280()[1], *(f32 *)(data + 0x60));
        func_0016ea30(func_00155280()[1], *(f32 *)(data + 0x64));
        for (i = 0; i < 0x20; i++) {
            id = *(s8 *)(data + 0x68 + i);
            if (id <= -1) {
                goto CMR_loop_skip;
            }
            func_0016eaa0(func_00155280()[1], id,
                          data + i * 0xC + 0x88);
CMR_loop_skip:
            ;
        }
        if ((u32)*(s32 *)(data + 4) < 0x10002U) {
            *(f32 *)(arg2 + 0x28) = 1.0f;
            *(f32 *)(arg2 + 0x14) = 1.0f;
            *(f32 *)(arg2 + 0) = 1.0f;
            *(f32 *)(arg2 + 0x10) = 0.0f;
            *(f32 *)(arg2 + 8) = 0.0f;
            *(f32 *)(arg2 + 4) = 0.0f;
            *(f32 *)(arg2 + 0x24) = 0.0f;
            *(f32 *)(arg2 + 0x20) = 0.0f;
            *(f32 *)(arg2 + 0x18) = 0.0f;
            *(f32 *)(arg2 + 0x38) = 0.0f;
            *(f32 *)(arg2 + 0x34) = 0.0f;
            *(f32 *)(arg2 + 0x30) = 0.0f;
            *(s32 *)(arg2 + 0xC) |= 0x20003;
        }
        dst = func_0016eaf0(func_00155280()[1]);
        src = (s32 *)(data + 0x210);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)dst = first;
            *(s32 *)(dst + 4) = second;
            dst += 8;
        } while (count > 0);
        func_0016eb00(func_00155280()[1]);
    }
    if (func_0014eec0() == 0) {
        func_00454bd0(arg0);
    }
    return 1;
}