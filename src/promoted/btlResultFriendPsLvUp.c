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
extern u8 *func_0010a900(u16 arg0);
extern s32 func_00106330(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern void func_0011b480(s32 a0, u16 a1, u8 *a2, s32 a3);
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

/* Floor: 179 differing words, object 1328B over a 1328-byte window with
   332 of 332 instructions and 134 edits.  A switch dispatch measures 250,
   a base-plus-zw shape 186 with the frame exact, and staging the scratch
   as s32 gives 179; removing the index goes back to 248 and reloading to
   242.  Residual is a saved-register colour permutation between $s2 and
   $s3 plus scheduling - `sh` before `andi`, the load order, and the addu
   orientation - over a single dead float store.  Body at
   docs/probe_archive/BRF2_002239a0_body.c.
   The two declaration fixes above are part of this measurement:
   func_00452560 takes an s32 (per its provider in sdkTask.c) and the two
   D_008C024x pad words are arrays, matching the sibling unit. */
/* measured: candidate object 1328B/window 1328B, verify normalized_diff 490, probe reloc-masked 179 words (guard below, NON_MATCHING so production stays ASM; fnalign 332/332 instrs, 134 edits +12 reloc-only). Earliest hunk is s2/s3 colour permute (retail r in s3/base in s2 vs object r in s2/base in s1) plus bnez/beqz polarity flip at loop head; declaration-order perms neutral. Frame exact 0xA0 via zw[2]+sp[11]. Banked as floor. */
// FUN_002239A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_002239a0(s32 arg0)
{
    // Retail frame 0xA0 (160B); zw[2] + sp[11] give 52B locals + saves = 0xA0.
    // Register map: r in s3, base in s2, e/k in s1, q in s4, arg0 in s0.
    // Switch gives 8-entry jtbl_007477B0 (0-7); 0->1, 2->3->4, 5->6 fallthroughs.
    // base = e + 96 kept live across case 1 for 0x69A/0x6A4/0x6B4/0x6B6 forms.
    // idx in s3 across 10a900 call; reload-after-call variant measured worse (179->242).
    // sp[11] with three trailing -1 (0x60-0x88); 10-word variant shortens frame to 0x90.
    // zw[1] = 0x41980000 (19.0f); single-store residual is dead-store elimination.
    // stmp as s32 (no shifts) vs s16 (shifts); s32 saves 12 words (191->179).
    // D_008C as [0] array (sibling idiom); scalar gives GP-relative wall (now reloc-only).
    // 452560(s32) matches sdkTask.c provider; void omits incoming $a0 (semantic gate).
    // q only used when idx != 4 (success path), so no UB on early id==0 exit.
    // Final id via lh (s16) for 2238f0 s64; earlier ids via lhu (u16).
    // Case 4: retail sh-then-andi vs object andi-then-sh scheduling wall.
    u8 *r;
    u8 *e;
    u8 *base;
    u32 st;
    u8 *q;
    s32 v;
    s32 k;
    u16 id;
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
            s32 idx = *(s32 *)(r + 56);
            id = *(u16 *)(base + idx * 2 + 0x69A);
            if (id == 0) {
                *(s32 *)(r + 56) = idx + 1;
                continue;
            }
            q = func_0010a900(id);
            *(s32 *)(q + 8) = *(s32 *)(base + idx * 4 + 0x6A4) + *(s32 *)(q + 8);
            if ((s32)*(u8 *)(base + idx * 136 + 0x6B4) <= 0) {
                *(s32 *)(r + 56) = idx + 1;
                continue;
            }
            break;
        }
        if (*(s32 *)(r + 56) != 4) {
            k = 0;
            while (k < 32) {
                u16 sid = *(u16 *)(base + *(s32 *)(r + 56) * 136 + k * 2 + 0x6B6);
                if (sid == 0) {
                    break;
                }
                if (sid == 0x112) {
                    if (func_00106330(0x1012) != 0) {
                        func_0046d730(D_00629720, 158);
                    }
                    func_00106390(0x1012, 1);
                } else if (sid == 0x113) {
                    if (func_00106330(0x1013) != 0) {
                        func_0046d730(D_00629720, 163);
                    }
                    func_00106390(0x1013, 1);
                }
                k++;
            }
            func_0011b480(*(s32 *)(r + 68), *(u16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A), q, 0);
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
            if (*(s16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A) == 5) {
                s16 t = (s16)(func_00231d70(3) + 468);
                func_001f86d0();
                func_001f9a50((u16)t, 3);
            } else {
                s32 stmp = func_002238f0(*(s16 *)(base + *(s32 *)(r + 56) * 2 + 0x69A)) + 125;
                s16 u = (s16)(stmp + (s16)func_00231d70(3));
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
        if (func_0011f560(*(s32 *)(r + 72)) != 0) {
            func_0011f580(*(s32 *)(r + 72));
            *(u32 *)(r + 4) = 4;
            *(u16 *)(r + 64) = 0;
        }
        /* fallthrough */
    case 4:
        {
            u16 t = *(u16 *)(r + 64) + 1;
            *(u16 *)(r + 64) = t;
            if ((t >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (*(u16 *)(r + 64) >= 4))) {
                *(u32 *)(r + 4) = 1;
                *(s32 *)(r + 56) = *(s32 *)(r + 56) + 1;
            }
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
