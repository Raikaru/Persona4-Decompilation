#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultFriendPsLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0046d730(u8 *arg0, s32 arg1);

extern u8 *func_00452560(s32 arg0);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern s32 func_00452380(u8 *arg0);
extern s32 func_00117780(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_0011d100(s32 arg0, void *arg1);
extern void func_0011bb90(s32 arg0);
extern void func_00117580(s32 arg0, s32 arg1);
extern u16 *func_0010a900(u16 arg0);
extern s32 datGetFlag(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
extern s32 func_00455ea0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0011f410(s32 a0, s32 a1, u8 *a2, s32 a3, s32 a4, void *a5);
extern u32 func_00231d70(u32 max);
extern void func_001f86d0(void);
extern void func_001f9a50(u16 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void func_001f8690(u16 arg0);
extern void func_002bb4e0(void);
extern s32 func_0011f560(s32 arg0);
extern void func_0011f580(s32 arg0);
extern s32 func_0021de60(void);
extern u8 D_00795F20[];
extern u8 D_005E4810[];
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_00629720[];



// FUN_002238F0
s32 func_002238f0(s64 arg0)
{
    s64 temp_2;

    temp_2 = (s64)(arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        return 0xE2;
    case 3:
        return 0x16C;
    case 4:
        return 0x1F3;
    case 6:
        return 0x27A;
    case 7:
        return 0x301;
    case 8:
        return 0x387;
    default:
        func_0046d730(D_00629720, 0x2C);
        return 0;
    }
}

/* 2026-09-28: 180 -> 53 differing words (332/332 instructions, frame 0xA0 exact).  What moved it, in order:
   the record index is read through `r + 56` at every use instead of cached in a local (the retail loop reloads
   it after each call and store; 179 -> 123 together with the loop shapes), the two id/flag loops are the
   bottom-tested `while`/`for (k = 0; k < 32 && (sid = ...) != 0; k++)` with a `switch (sid)` (retail's
   beq 0x113 / beq 0x112 / b chain), `case 3` is `if (f(..) == 0) break;` falling into `case 4`, the counter is
   `++*(u16 *)(r + 64) >= 45` (sh before andi, one register), the id read in the call and in the `== 5` test is
   written integer-first `(u8 *)(idx * 2) + (u32)base + 0x69A` (retail `addu v0,v0,s2`), the `s16` cast of the
   second `func_00231d70` result was dropped, and `(s32)` copies of the parameter are a first local
   `arg0 = (s32)sdkTaskBytes` (it then takes $s0 as retail; declared last it does not).
   What is left is one colour swap: r takes $s2 and base $s3 where retail has r $s3 and base $s2, plus the
   reloc words.  Declaration order of q/r/base/e/k/sid (every permutation tried), a CSE'd `(e + 96)` in place
   of the named base (92), and every scoped pragma (opt_lifetimes, propagation, common_subs, loop_invariants,
   dead_assignments, dead_code, strength_reduction, rebuildconditionals) leave the 53.  Body at
   docs/probe_archive/BRF2_002239a0_body.c is the older 179-word shape. */
// FUN_002239A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_002239a0(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    // Retail frame 0xA0 (160B); zw[2] + sp[11] give 52B locals + saves = 0xA0.
    // Retail registers: arg0 s0, e/k s1, base s2, r s3, q s4.
    // Switch gives 8-entry jtbl_007477B0 (0-7); 0->1, 2->3->4, 5->6 fallthroughs.
    // zw[1] = 0x41980000 (19.0f); the zw[0]/zw[1] stores are both real.
    // The task record's index (r + 56) is never cached: retail re-reads it after every call and store.
    // D_008C as [0] array (sibling idiom); scalar gives GP-relative wall (now reloc-only).
    // 452560(s32) matches sdkTask.c provider; void omits incoming $a0 (semantic gate).
    // q is only assigned inside the search loop and read after it (not provably set if r + 56 starts > 4).
    // Final id via lh (s16) for 2238f0 s64; earlier ids via lhu (u16).
    u8 *q;
    u8 *r;
    u8 *base;
    u8 *e;
    u32 st;
    s32 v;
    s32 k;
    u16 id;
    u32 sid;
    s32 sp[11];
    s32 zw[2];

    r = func_00452560(arg0);
    e = *(u8 **)(r + 60);
    *(s32 *)(r + 8) = 0;
    *(s32 *)(r + 12) = 0;
    func_00460ac0(D_00795F20, r + 8);
    st = *(u32 *)(r + 4);
    switch (st) {
    case 0:
        *(s32 *)(r + 56) = 0;
        v = func_00452380(D_005E4810);
        *(s32 *)(r + 68) = v;
        if (v == 0) {
            v = func_00117780(0, 15, 4, 5, 0);
            *(s32 *)(r + 68) = v;
            if (v == 0) {
                func_0046d730(D_00629720, 116);
            }
            zw[0] = 0;
            zw[1] = 0x41980000;
            func_0011d100(*(s32 *)(r + 68), zw);
            func_0011bb90(*(s32 *)(r + 68));
        }
        func_00117580(*(s32 *)(r + 68), 174);
        *(u32 *)(r + 4) = 2;
        /* fallthrough */
    case 1:
        base = e + 96;
        while (*(s32 *)(r + 56) < 4) {
            id = *(u16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A);
            if (id != 0) {
                q = (u8 *)func_0010a900(id);
                v = *(s32 *)(base + *(s32 *)(r + 56) * 4 + 0x6A4);
                *(s32 *)(q + 8) = *(s32 *)(q + 8) + v;
                if ((s32)*(u8 *)(base + *(s32 *)(r + 56) * 136 + 0x6B4) > 0) {
                    break;
                }
            }
            *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
        }
        if (*(s32 *)(r + 56) != 4) {
            for (k = 0; k < 32 && (sid = *(u16 *)(base + *(s32 *)(r + 56) * 136 + k * 2 + 0x6B6)) != 0; k++) {
                switch (sid) {
                case 0x112:
                    if (datGetFlag(0x1012) != 0) {
                        func_0046d730(D_00629720, 158);
                    }
                    func_00106390(0x1012, 1);
                    break;
                case 0x113:
                    if (datGetFlag(0x1013) != 0) {
                        func_0046d730(D_00629720, 163);
                    }
                    func_00106390(0x1013, 1);
                    break;
                }
            }
            func_0011b480(*(u8 **)(r + 68), *(u16 *)((u8 *)(*(s32 *)(r + 56) * 2) + (u32)base + 0x69A), (u32)q, 0);
            sp[0] = 27;
            sp[1] = 25;
            sp[2] = 6;
            sp[3] = 9;
            sp[4] = 10;
            sp[5] = 26;
            sp[6] = 13;
            sp[7] = 14;
            sp[8] = -1;
            sp[9] = -1;
            sp[10] = -1;
            {
                s32 a = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 0, 0);
                s32 b = func_00455ea0(*(s32 *)(*(u8 **)(r + 60) + 2356), 1, 0);
                *(s32 *)(r + 72) = func_0011f410(arg0, *(s32 *)(r + 68), base + *(s32 *)(r + 56) * 136 + 0x6B4, a, b, sp);
            }
            if (*(s16 *)((u8 *)(*(s32 *)(r + 56) * 2) + (u32)base + 0x69A) == 5) {
                s16 t = (s16)(func_00231d70(3) + 468);
                func_001f86d0();
                func_001f9a50((u16)t, 3);
            } else {
                s32 stmp = func_002238f0(*(s16 *)((u8 *)(*(s32 *)(r + 56) * 2) + (u32)base + 0x69A)) + 125;
                s16 u = (s16)(stmp + func_00231d70(3));
                func_001f9a90();
                func_001f8690((u16)u);
            }
            *(u16 *)r = *(u16 *)r | 2;
            *(u32 *)(r + 4) = 2;
        } else {
            *(u16 *)r = *(u16 *)r & 0xFFFE;
            *(u32 *)(r + 4) = 7;
            func_002bb4e0();
        }
        break;
    case 2:
        *(u32 *)(r + 4) = 3;
        /* fallthrough */
    case 3:
        if (func_0011f560(*(s32 *)(r + 72)) == 0) {
            break;
        }
        func_0011f580(*(s32 *)(r + 72));
        *(u32 *)(r + 4) = 4;
        *(u16 *)(r + 64) = 0;
        /* fallthrough */
    case 4:
        if ((++*(u16 *)(r + 64) >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (*(u16 *)(r + 64) >= 4))) {
            *(u32 *)(r + 4) = 1;
            *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
        }
        break;
    case 5:
        if (func_0021de60() != 0) {
            *(u32 *)(r + 4) = 6;
            /* fallthrough */
        case 6:
            *(u16 *)r = *(u16 *)r & 0xFFFD;
            return -1;
        }
        break;
    case 7:
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlResultFriendPsLvUp", func_002239a0);
#endif
