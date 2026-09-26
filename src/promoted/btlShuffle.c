/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"


extern void func_003753f0(u8 *arg0);

extern void func_003757f0(u8 *arg0);

extern u16 *func_00452560();

extern s32 func_00452380(void *arg0);

extern u32 func_00231d70(u32 max);

extern void func_0046d730(const void *file, s32 line);

extern u8 D_0064E5D0[];

extern u8 D_0064E610[];

extern u8 D_0064E790[];

extern void func_0044ea90(const void *file, s32 line);

extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern void memset(void *dst, s32 value, s32 size);



extern void func_0036d860(u8 *arg0, s32 arg1);

extern void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_0036f410(u8 *arg0, u8 *arg1);

extern u8 D_0064E7A0[];

extern s32 func_0036e140(u8 *task);

extern void func_0036e600(u8 *task);

extern u16 func_00104dc0(s16 character);

extern void func_001056e0(s16 character, s16 value);

extern u32 func_00105610(s16 param);

extern s32 datGetPartyId();

extern u16 func_00104e30(s16 character);

extern u32 func_00104d50(s16 character);

extern void func_00105730(s16 character, s16 value);

extern u8 D_0064E5F0[];

extern u8 D_0064E5F1[];

extern u32 RpRandom();

extern s32 func_0010b5b0();

extern s32 func_0010b510();

extern s32 func_0010abd0();

extern s32 func_0010aa80();

extern u8 *func_0010ace0();

extern s32 datPersonaGetLevel();

extern void func_0010ad80();

extern u8 *func_0010b010(u16 personaId);

extern u8 *iGpffffb3c0;

extern u8 *iGpffffb3f0;
extern u8 *iGpffffb3e0;
extern u8 *iGpffffb3ec;
extern u16 *datPersonaGetSkills(int persona);
extern s32 func_0010cd70(u8 *arg0, s32 arg1, u16 arg2);

extern s32 D_0064E7B0[];

extern u16 D_0064E7B4[];

extern u16 D_0064E7B6[];

extern s32 D_0064E7B8[];

extern void func_00106550(s32 arg0, u32 arg1);

extern s32 datGetFlag(s32 id);

extern void func_00106390(s32 a, s32 b);

extern void func_0036d940(u8 *arg0);

extern void func_00374610(u8 *arg0);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 D_0064E780[];

extern u8 D_0064E650[];

extern u8 D_0064E670[];

extern u8 D_0064E6A0[];
extern u16 func_0010b6f0(void);
extern u8 func_00109920(u8 *arg0, u16 arg1);
extern u8 func_001099f0(u8 *arg0, u16 arg1);
extern s32 func_0010a780(u8 *arg0, u16 arg1, s8 arg2);
extern u8 D_00793E80[];

extern s32 iGpffffa9c0;

extern void func_00460ac0(u8 *arg0, u8 *arg1);

extern void func_003741f0(u8 *arg0);

extern s32 func_003742b0(u8 *arg0);

extern void func_003740b0(u8 *arg0, u8 *arg1);

extern s32 func_0036d960(void);

extern void func_00374960(u8 *arg0);

extern void func_00374730(u8 *arg0);

extern s32 func_00213a80(void);

extern s32 func_00379b70(u8 *arg0);

extern u8 func_002baac0(u8 *message);

extern void func_002bad10(s32 arg0);

extern void func_002bb7c0(s32 arg0);

extern s32 func_002bb600(void);

extern void func_002bb1e0(s32 arg0);

extern void func_002bb4e0(void);

extern void func_003798d0(u8 *arg0, s32 arg1);

extern s32 func_00379920(u8 *arg0);



// FUN_0036E140
s32 func_0036e140(u8 *unusedTask)
{
    u8 *work = (u8 *)func_00452560();
    s32 i;
    u16 flags;
    u16 cnt;

    for (i = 0; i < 2; i++) {
        u8 *p = work + i * 0x30;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x10) = 0;
        func_00460ac0((u8 *)D_00793E80 + *(s32 *)((u8 *)&iGpffffa9c0 + i * 4) * 0x30, p + 0xC);
    }
    switch (*(s32 *)(work + 8)) {
    case 0:
        *(s32 *)(work + 8) = 1;
        break;
    case 1:
        flags = *(u16 *)work;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0) {
                goto case2_body;
            }
        }
        if ((flags & 4) == 0) {
            break;
        }
        if (((flags & 0x10) == 0) && ((flags & 0x80) == 0)) {
            func_003741f0(work + 0x70);
            *(u16 *)work |= 0x80;
        }
        if (((*(u16 *)work) & 0x80) != 0) {
            if (func_003742b0(work + 0x70) != 0) {
                *(u16 *)work |= 0x10;
                *(u16 *)work &= (u16)~0x80;
            }
        }
        flags = *(u16 *)work;
        if (((flags & 0x20) == 0) && ((flags & 0x40) == 0) && ((flags & 0x10) != 0)) {
            func_003740b0(work + 0x70, work + 0x1F2C0);
            *(u16 *)work |= 0x40;
        }
        if (((*(u16 *)work) & 0x40) != 0) {
            if (func_0036d960() != 0) {
                *(u16 *)work |= 0x20;
                *(u16 *)work &= (u16)~0x40;
            }
        }
        flags = *(u16 *)work;
        if (((flags & 0x10) != 0) && ((flags & 0x20) != 0)) {
            *(u16 *)work = flags | 8;
            *(u16 *)work &= (u16)~4;
        }
        break;
    case 2:
case2_body:
        func_00374960(work + 0x70);
        *(s32 *)(work + 8) = 3;
        /* fallthrough */
    case 3:
        func_00374730(work + 0x70);
        *(u16 *)work |= 2;
        if (datGetFlag(0x1430) == 0) {
            *(s32 *)(work + 4) = 0;
            *(s32 *)(work + 8) = 7;
            break;
        }
        *(s32 *)(work + 8) = 4;
        /* fallthrough */
    case 4:
        if (((*(u16 *)work) & 0x100) == 0) {
            if (func_00213a80() != 0) {
                break;
            }
            *(u16 *)work |= 0x100;
        }
        if (func_00379b70(work + 0x70) != 0) {
            *(u16 *)work &= (u16)~1;
            *(s32 *)(work + 8) = 6;
        }
        break;
    case 5:
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0xA) {
            break;
        }
        return -1;
    case 6:
        break;
    case 7:
        if (func_00213a80() != 0) {
            break;
        }
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        *(u16 *)(work + 2) = 0;
        func_002baac0((u8 *)(*(s32 *)(work + 0x1F354)));
        func_002bad10(0);
        *(s32 *)(work + 8) = 8;
        /* fallthrough */
    case 8:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            {
                s32 t = *(s32 *)(work + 4) + 1;
                *(s32 *)(work + 4) = t;
                if (t < 4) {
                    func_002bad10(*(s32 *)(work + 4));
                } else {
                    func_002bb4e0();
                    func_003798d0(work + 0x70, 0);
                    *(s32 *)(work + 8) = 9;
                }
            }
        }
        break;
    case 9:
        if (func_00379920(work + 0x70) == 0) {
            break;
        }
        cnt = ++*(u16 *)(work + 2);
        if ((cnt & 0xFFFF) < 0x1E) {
            break;
        }
        *(s32 *)(work + 8) = 4;
        break;
    default:
        func_0046d730(D_0064E790, 0x178);
        break;
    }
    return 0;
}

// FUN_0036E580
void func_0036e580(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003753f0((u8 *)arg1 + 0x70);
    }
}



// FUN_0036E5C0
void func_0036e5c0(u8 *arg0, u16 *arg1)
{
    if (*arg1 & 2) {
        func_003757f0((u8 *)arg1 + 0x70);
    }
}

// FUN_0036E600
void func_0036e600(u8 *unusedTask)
{
    u8 *work = (u8 *)func_00452560();

    if (datGetFlag(0x1430) == 0) {
        func_00106390(0x1430, 1);
    }
    func_0036d940(work + 0x1F384);
    func_00374610(work + 0x70);
    jtbl_008873EC[0](work);
}

// FUN_0036E690
s32 func_0036e690(u8 *arg0, u8 *arg1)
{
    u8 *work;
    s32 handle;
    s32 tmp;

    func_0044ea90(D_0064E7A0, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0x21ABC, 0x40000);
    memset(work, 0, 0x21ABC);
    handle = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0064E780), 0x12, 0, 0, func_0036e140, func_0036e600, (u8 *)(work));
    tmp = (s32)func_00452560(arg0);
    *(s32 *)(work + 8) = 0;
    *(s32 *)(work + 0x6C) = tmp;
    *(s32 *)(work + 0x14) = (s32)(void *)func_0036e580;
    *(s32 *)(work + 0x1C) = (s32)work;
    *(s32 *)(work + 0x44) = (s32)(void *)func_0036e5c0;
    *(s32 *)(work + 0x4C) = (s32)work;
    func_0036d860(work + 0x1F384, 0);
    func_00373e10(work + 0x70, handle, *(s32 *)(arg1 + 0xC),
                  *(s32 *)(arg1 + 0x10), *(s32 *)(arg1 + 0x14));
    func_0036f410(work + 0x1F2C0, arg1);
    return handle;
}

// FUN_0036E7E0
void func_0036e7e0(void)
{
    u16 *work = func_00452560();

    *work |= 1;
}

// FUN_0036E810
void func_0036e810(void)
{
    u16 *work = func_00452560();

    work[1] = 0;
    *(u32 *)(work + 4) = 5;
}

// FUN_0036E840
u32 func_0036e840(void)
{
    return func_00452560()[0] & 1;
}

// FUN_0036E870
void func_0036e870(void)
{
    u16 *work = func_00452560();

    *work |= 4;
}

// FUN_0036E8A0
u32 func_0036e8a0(void)
{
    return (func_00452560()[0] & 4) != 0;
}

// FUN_0036E8D0
s32 func_0036e8d0(void)
{
    return func_00452380(D_0064E780) != 0;
}

// FUN_0036E900
void *func_0036e900(void *arg0)
{
    return *(void **)(*(u32 *)((u8 *)arg0 + 0x38) + 0x6C);
}

// FUN_0036E910
void *func_0036e910(void *arg0)
{
    return (u8 *)*(void **)((u8 *)arg0 + 0x38) + 0x70;
}

// FUN_0036E920
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * table base (lui/addiu/addu) inside the loop instead of hoisting it (nd 21);
 * with it the preheader hoist matches retail. */
#pragma opt_loop_invariants on
s32 func_0036e920(u8 arg0)
{
    s32 x = arg0 & 0xFF;
    s32 q;
    s32 sum;
    s32 i;
    s32 r;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    r = func_00231d70(0x64);
    sum = 0;
    for (i = 0; i < 5; i++) {
        sum += D_0064E610[q * 5 + i];
        if (r < sum) {
            break;
        }
    }
    if (i >= 5) {
        func_0046d730(D_0064E790, 0x26C);
    }
    return i;
}
/* measured: see annotation above (func_0036e920). */
#pragma opt_loop_invariants off

// FUN_0036EA00
s32 func_0036ea00(s32 arg0, u8 arg1)
{
    s32 x = arg1 & 0xFF;
    s32 q;
    s32 lo;
    s32 hi;
    s32 result;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    lo = D_0064E5F0[q * 2];
    hi = D_0064E5F1[q * 2];
    if (hi == lo) {
        return hi;
    }
    result = lo + func_00231d70((u32)(hi - lo + 1));
    switch (arg0) {
    case 0:
        break;
    case 1:
        if (result < 4) {
            result = 4;
            break;
        }
        if (result & 1) {
            result += 1;
        }
        break;
    case 2:
        if (result < 5) {
            result = 3;
            break;
        }
        result = 6;
        break;
    case 3:
        if (result > 6) {
            result = 6;
        }
        break;
    case 4:
        break;
    default:
        break;
    }
    return result;
}
// FUN_0036EB50
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * table base (lui/addiu/addu) inside the loop instead of hoisting it (nd 21);
 * with it the preheader hoist matches retail. */
#pragma opt_loop_invariants on
s32 func_0036eb50(s32 arg0, u8 arg1)
{
    s32 x = arg1 & 0xFF;
    s32 q;
    s32 limit;
    s32 i;
    s32 sum;

    if (x == 0) {
        x = 1;
    } else if (x > 0x63) {
        x = 0x63;
    }
    q = (x - 1) / 10;
    limit = func_00231d70(0x64);
    sum = 0;
    i = 0;
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        if (datGetFlag(0x1431) != 0) {
            while (i < 3) {
                sum += D_0064E650[q * 3 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 3) {
                func_0046d730(D_0064E790, 0x2CF);
            }
        }
        break;
    case 3:
        if (datGetFlag(0x1432) != 0) {
            while (i < 4) {
                sum += D_0064E670[q * 4 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 4) {
                func_0046d730(D_0064E790, 0x2DB);
            }
        }
        break;
    case 4:
        if (datGetFlag(0x1433) != 0) {
            while (i < 3) {
                sum += D_0064E6A0[q * 3 + i];
                if (limit < sum) {
                    break;
                }
                i++;
            }
            if (i >= 3) {
                func_0046d730(D_0064E790, 0x2E7);
            }
        }
        break;
    }
    return i;
}
/* measured: see annotation above (func_0036eb50). */
#pragma opt_loop_invariants off

// FUN_0036EDA0
s32 func_0036eda0(s32 arg0)
{
    s32 i;
    s32 v = arg0 - 3;
    s32 r;
    u8 *tbl;

    if (v < 0) {
        v = 0;
    } else if ((u32)v >= 6) {
        v = 5;
    }
    r = func_00231d70(0x64);
    i = 3;
    tbl = D_0064E5D0 + v * 4;
    for (; i > 0; i--) {
        if (tbl[i] > r) {
            break;
        }
    }
    if (i < 0) {
        func_0046d730(D_0064E790, 0x307);
    }
    return i + 1;
}

/* Floor (measured 2026-09-18): probe_variants honest 292 words, obj 1448B / window 1456B */
/* (362 vs 363 retail instrs, 0.3% short, banks per 3% rule); fnalign 295 edits +2 reloc-only, */
/* frame 0x6D0 vs retail 0x6F0. Quadword + dead-block floor: retail spills hi/lo and two */
/* shuffle rands to s128 slots with sq/lq (no 128-bit C type reaches them; 16B copies lower to */
/* ld/sd, members scalar-replace), and the B draw arm sits behind an unconditional `b` that b210 */
/* deletes. Spill victims arg1/nA immobile across declaration orders. Re-measured commands: */
/* python3 tools/probe_variants.py src/promoted/btlShuffle.c func_0036ee60 --candidate honest=docs/probe_archive/BtlShuffle_0036EE60_body.c */
/* python3 -E -s tools/fnalign.py src/promoted/btlShuffle.c func_0036ee60 --candidate docs/probe_archive/BtlShuffle_0036EE60_body.c */
/* python3 tools/measure_guarded.py src/promoted/btlShuffle.c func_0036ee60 (after install). */
/* Prior archive note (2026-09-16, same 292/1448/1456/362-vs-363) retained at */
/* docs/probe_archive/BtlShuffle_0036EE60_body.c; this floor is that body, banked. */
extern s32 func_00104c70(s32 arg0);
extern u8 D_0064E76F[];
extern u8 *iGpffffb3d4;

/* Round-2 rewrite from retail (2026-09-26): fnalign 90 edits (364/364 instrs),
 * see docs/probe_archive/Campaign_g2r2_20260926.md.  Levers: u8 callee
 * parameters (func_0036e920/ea00/eb50 mask their own argument), the always-false
 * `rand < rate` (rate 0) arm keeps retail's dead listB draw block, lists declared
 * C/B/A for retail's stack order, opt_loop_invariants on hoists the sign-extended
 * hi/lo/cap into sq-spilled temporaries.  Residual: callee-saved colouring and
 * which draw-loop value is spilled (retail spills cIdx, this spills nDraw). */
// FUN_0036EE60 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_0036ee60(u8 *arg0, s16 arg1, s32 arg2)
{
    s16 listC[256];
    s16 listB[256];
    s16 listA[256];
    s16 lvl;
    s16 hi;
    s16 cap;
    s16 lo;
    s16 mlvl;
    u16 nA;
    u16 nB;
    s32 i;
    u16 nC;
    s32 aCount;
    s32 bCount;
    s32 cCount;
    s32 total;
    s32 k;
    u16 r1;
    u16 r2;
    s16 tmp;
    s32 nDraw;
    u16 aIdx;
    u16 bIdx;
    u16 cIdx;
    s32 e;
    s16 item;
    u32 rate = 0;

    lvl = func_00104c70(1) & 0xFF;
    if (lvl > 0 && (u32)lvl < 10) {
        hi = D_0064E76F[lvl];
        lo = 1;
    } else if (lvl >= arg1) {
        hi = arg1 - 5;
        lo = arg1 - 10;
    } else {
        hi = lvl - 5;
        lo = lvl - 10;
    }
    cap = lvl + 3;
    if (cap > 99) {
        cap = 99;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    nC = 0;
    nB = 0;
    nA = 0;
    for (i = 0; i < 256; i++) {
        u8 *rec = iGpffffb3d4 + i * 14;

        if ((*(u16 *)rec & 0xDB) != 0) {
            continue;
        }
        mlvl = rec[3];
        if (mlvl > cap) {
            continue;
        }
        if (lvl < mlvl || (mlvl <= hi && mlvl >= lo)) {
            if ((s16)func_0010aa80((s16)i) != -1) {
                listA[nA++] = i;
            } else if (lvl < mlvl) {
                listB[nB++] = i;
            } else {
                listC[nC++] = i;
            }
        }
    }
    bCount = nB;
    cCount = nC;
    aCount = nA;
    total = aCount + (cCount + bCount);
    if (total == 0) {
        return 0;
    }
    if (cCount > 1) {
        for (k = 0; k < cCount; k++) {
            r1 = func_00231d70(cCount);
            r2 = func_00231d70(cCount);
            if (r1 != r2) {
                tmp = listC[r1];
                listC[r1] = listC[r2];
                listC[r2] = tmp;
            }
        }
    }
    if (bCount > 1) {
        for (k = 0; k < bCount; k++) {
            r1 = func_00231d70(nB);
            r2 = func_00231d70(nB);
            if (r1 != r2) {
                tmp = listB[r1];
                listB[r1] = listB[r2];
                listB[r2] = tmp;
            }
        }
    }
    if (aCount > 1) {
        for (k = 0; k < aCount; k++) {
            r1 = func_00231d70(nA);
            r2 = func_00231d70(nA);
            if (r1 != r2) {
                tmp = listA[r1];
                listA[r1] = listA[r2];
                listA[r2] = tmp;
            }
        }
    }
    *(s32 *)(arg0 + 0x10) = func_0036e920(arg1);
    *(s32 *)(arg0 + 0x14) = func_0036eb50(*(s32 *)(arg0 + 0x10), arg1);
    *(s32 *)(arg0 + 0xC) = func_0036ea00(*(s32 *)(arg0 + 0x10), arg1);
    nDraw = func_0036eda0(*(s32 *)(arg0 + 0xC));
    if (total < nDraw) {
        nDraw = total;
    }
    bIdx = 0;
    cIdx = 0;
    aIdx = 0;
    e = 0;
    for (i = 0; i < nDraw; i++) {
        if (func_00231d70(100) < rate && bIdx < bCount) {
            item = listB[bIdx++];
        } else if (cIdx < cCount) {
            item = listC[cIdx++];
        } else if (aIdx < aCount) {
            item = listA[aIdx++];
        } else {
            continue;
        }
        ((s16 *)arg0)[e] = item;
        e++;
    }
    if (e == 0) {
        return 0;
    }
    *(s32 *)(arg0 + 8) = e;
    if (aIdx == e && func_00231d70(100) >= 20) {
        return 0;
    }
    return 1;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036ee60);
#endif

typedef struct {
    f32 a;
    f32 b;
} ShuffleCard2;

// FUN_0036F410
void func_0036f410(u8 *arg0, u8 *arg1)
{
    s32 i;
    u32 v;
    s32 idx;
    f32 f;
    ShuffleCard2 tmp;

    for (i = 0; i < *(s32 *)(arg1 + 0xC); i++) {
        if (i < *(s32 *)(arg1 + 8)) {
            *(s32 *)(arg0 + i * 8) = 0;
            *(u16 *)(arg0 + i * 8 + 4) = *(u16 *)(arg1 + i * 2);
            *(u16 *)(arg0 + i * 8 + 6) = 0;
        } else {
            v = RpRandom() & 0xFFF;
            f = (f32)v;
            if (100.0f * (f / 4096.0f) < 30.0f) {
                *(s32 *)(arg0 + i * 8) = 3;
            } else {
                *(s32 *)(arg0 + i * 8) = 2;
            }
            *(u16 *)(arg0 + i * 8 + 4) = 0;
            *(u16 *)(arg0 + i * 8 + 6) = 0;
        }
    }
    for (i = *(s32 *)(arg1 + 0xC) - 1; i > 0; i--) {
        v = RpRandom() & 0xFFF;
        f = (f32)v / 4096.0f;
        idx = (s32)((f32)i * f);
        tmp = ((ShuffleCard2 *)arg0)[i];
        ((ShuffleCard2 *)arg0)[i] = ((ShuffleCard2 *)arg0)[idx];
        ((ShuffleCard2 *)arg0)[idx] = tmp;
    }
}
// FUN_0036F620
void func_0036f620(u8 *arg0)
{
    *(u32 *)(arg0 + 0xC) = 0;
    *(u32 *)(arg0 + 0x10) = 0;
    *(u32 *)(arg0 + 0x38) = 0;
    *(u16 *)(arg0 + 8) |= 4;
}

// FUN_0036F640
s32 func_0036f640(s32 arg0, s32 *arg1)
{
    u32 idx;
    u16 a;
    u16 b;
    u32 result;
    u32 idx2;
    u8 *p;
    s32 (*fn)(s32, s32 *);

    memset(arg1, 0, 0xC);
    if (datGetFlag(0x1403) != 0) {
        a = 0;
        b = 0;
        for (idx = 0; idx < 0x2C; idx++) {
            p = (u8 *)D_0064E7B0 + idx * 12;
            if (datGetFlag(*(s32 *)p) != 0) {
                a = *(u16 *)((u8 *)D_0064E7B4 + idx * 12);
                b = *(u16 *)((u8 *)D_0064E7B6 + idx * 12);
                func_00106390(*(s32 *)p, 0);
                break;
            }
        }
        result = (u32)b | ((u32)a << 16);
        func_00106390(0x1403, 0);
    } else {
        result = 0;
    }
    for (idx2 = 0; idx2 < 0x2C; idx2++) {
        p = (u8 *)D_0064E7B0 + idx2 * 12;
        if (arg0 == (s32)(*(u16 *)(p + 6) | (*(u16 *)(p + 4) << 16))) {
            fn = (s32 (*)(s32, s32 *))*(s32 *)((u8 *)D_0064E7B8 + idx2 * 12);
            if (fn == NULL) {
                *arg1 = 1;
                func_00106390(*(s32 *)p, 1);
                func_00106390(0x1403, 1);
            } else {
                *arg1 = fn(arg0, arg1);
                func_00106390(*(s32 *)p, 0);
                func_00106390(0x1403, 0);
            }
            func_00106550(0x10, 0);
            break;
        }
        if (idx2 == 0x2C) {
            func_0046d730(D_0064E790, 0x4A1);
        }
    }
    return result;
}
/* Round-2 rewrite from retail (2026-09-26): fnalign 22 edits (212/212 instrs).
 * Levers: separate block-scoped k per branch (46 -> 24), byte-offset table reads,
 * u32 candidate slots written through u16 halves, `m = 0; tbl = ...` before the
 * loop.  Residual: first-loop $s0/$s1 swap (count vs (s16)i), else-branch
 * $t3/$t4 swap, and retail's unfolded addiu 0x72/0x70 candidate reads. */
// FUN_0036F880 NONMATCHING
#ifdef NON_MATCHING
s32 func_0036f880(s32 arg0, u8 *arg1)
{
    u8 *list[12];
    u32 cand[8];
    s32 flag = arg0 & 0xFFFF;
    s32 count = (u16)func_0010b5b0();
    u8 *p;
    u16 *skills;
    u16 i;
    u16 n;
    u16 j;
    u16 nc;
    u16 m;
    u16 r;
    u8 *tbl;
    u16 first;
    u16 second;

    n = 0;
    if (count > 12) {
        func_0046d730(D_0064E790, 1207);
    }
    for (i = 0; i < count; i++) {
        if (func_0010abd0((s16)i) != 0) {
            list[n] = func_0010ace0((s16)i);
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    p = list[func_00231d70(n)];
    skills = datPersonaGetSkills((int)p);
    nc = 0;
    m = 0;
    tbl = iGpffffb3ec;
    for (; m < 8; m++) {
        if (skills[m] == 0) {
            continue;
        }
        j = 0;
        if (flag != 0) {
            u16 k;

            for (; skills[m] != *(u16 *)(tbl + j * 4) && *(u16 *)(tbl + j * 4) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4 + 2)) {
                    break;
                }
            }
            if (k >= 8) {
                ((u16 *)&cand[nc])[0] = *(u16 *)(tbl + j * 4);
                ((u16 *)&cand[nc])[1] = *(u16 *)(tbl + j * 4 + 2);
                nc++;
            }
        } else {
            u16 k;

            for (j = 0; skills[m] != *(u16 *)(tbl + j * 4 + 2) && *(u16 *)(tbl + j * 4 + 2) != 0; j++) {
            }
            if (*(u16 *)(tbl + j * 4 + 2) == 0) {
                continue;
            }
            for (k = 0; k < 8; k++) {
                if (skills[k] != 0 && skills[k] == *(u16 *)(tbl + j * 4)) {
                    break;
                }
            }
            if (k >= 8) {
                ((u16 *)&cand[nc])[0] = *(u16 *)(tbl + j * 4 + 2);
                ((u16 *)&cand[nc])[1] = *(u16 *)(tbl + j * 4);
                nc++;
            }
        }
    }
    if (nc == 0) {
        return 0;
    }
    r = func_00231d70(nc);
    second = ((u16 *)&cand[r])[1];
    first = ((u16 *)&cand[r])[0];
    func_0010cd70(p, (s16)first, second);
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 2);
    *(u16 *)(arg1 + 8) = first;
    *(u16 *)(arg1 + 6) = second;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036f880);
#endif


/* matched: s32 `s` and flag temporaries preserve retail's callee-saved
 * coloring ($s2/$s1) while u16 r and i use $s0/$s3. The explicit s16
 * conversion for the func_00105610 argument and re-conversion of r in the
 * flagged branch reproduce retail's sign-extension schedule. */
// FUN_0036FBE0
s32 func_0036fbe0(s32 arg0)
{
    s16 s;
    u16 i;
    u16 r;
    s32 flag = arg0 & 0xFFFF;

    if (flag != 0) {
        func_001056e0(1, (s16)func_00104dc0(1));
    } else {
        func_001056e0(1, 1);
    }
    i = 0;
    for (; i < 4; i++) {
        r = (u16)datGetPartyId(i);
        if (r != 0) {
            s = (s16)r;
            if (func_00105610(s) == 0) {
                if (flag != 0) {
                    func_001056e0((s16)r, (s16)func_00104dc0((s16)r));
                } else {
                    func_001056e0(s, 1);
                }
            }
        }
    }
    return 1;
}
// FUN_0036FD00
s32 func_0036fd00(s32 arg0, u8 *arg1)
{
    s32 flag = arg0 & 0xFFFF;
    s32 count = (u16)func_0010b5b0();
    u8 *p;
    u8 *best = NULL;
    u16 i;
    u16 min = 0x64;
    u16 bestFlag = 0;
    u16 t;

    for (i = 0; i < count; i++) {
        if (i == (s16)func_0010b510()) {
            continue;
        }
        if (func_0010abd0((s16)i) == 0) {
            continue;
        }
        p = func_0010ace0((s16)i);
        if (flag != 0) {
            t = *(u16 *)((u8 *)iGpffffb3f0 + *(u16 *)(p + 2) * 4 + 2);
        } else {
            t = *(u16 *)((u8 *)iGpffffb3f0 + *(u16 *)(p + 2) * 4);
        }
        if (t != 0 && (s16)func_0010aa80((s16)t) == -1 && (datPersonaGetLevel(p) & 0xFF) < min) {
            best = p;
            min = datPersonaGetLevel(p) & 0xFF;
            bestFlag = t & 0xFFFF;
        }
    }
    if (best == NULL) {
        return 0;
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(best + 2);
    *(s16 *)(arg1 + 8) = bestFlag;
    func_0010ad80(*(u16 *)(best + 2));
    func_0010b010(bestFlag);
    return 1;
}

// FUN_0036FED0
s32 func_0036fed0(s32 arg0)
{
    u16 flag = (u16)arg0;
    u16 i;
    u16 r;

    if (flag != 0) {
        func_00105730(1, (s16)func_00104e30(1));
    } else {
        func_00105730(1, (s16)((u32)((u16)func_00104d50(1)) >> 1));
    }
    for (i = 0; i < 4; i++) {
        r = (u16)datGetPartyId(i);
        if (r != 0 && func_00105610((s16)r) == 0) {
            if (flag != 0) {
                func_00105730((s16)r, (s16)func_00104e30((s16)r));
            } else {
                func_00105730((s16)r, (s16)((u32)((u16)func_00104d50((s16)r)) >> 1));
            }
        }
    }
    return 1;
}

/* matched: u16 sel reproduces the lui/and/srl/andi dispatch; u16 kind with */
/* narrow callee prototypes yields retail's daddiu constants with no extra */
/* masking; s32 flag + (flag & 0xFFFF) keeps the redundant andi; s16 v/t give */
/* the dsll32/dsra32 schedule, sum = t+v with (sum > 0x63) and (t <= v) fix the */
/* slti/slt $at coloring. */
// FUN_00370020
s32 func_00370020(s32 arg0, u8 *arg1)
{
    s32 flag = arg0 & 0xFFFF;
    u16 sel = (u16)((u32)(arg0 & 0xFFFF0000) >> 16);
    u8 *p;
    u16 kind;
    s16 v;
    s16 t;

    switch (sel) {
    case 8:
        kind = 3;
        break;
    case 9:
        kind = 0;
        break;
    case 11:
        kind = 4;
        break;
    case 12:
        kind = 1;
        break;
    case 13:
        kind = 2;
        break;
    default:
        func_0046d730(D_0064E790, 0x5D6);
        break;
    }
    p = func_0010ace0((s16)func_00231d70(func_0010b6f0() & 0xFFFF));
    if (p == NULL) {
        func_0046d730(D_0064E790, 0x5DC);
    }
    if ((flag & 0xFFFF) != 0) {
        s32 sum;
        v = (s16)(func_00231d70(3) + 1);
        t = (s16)(func_001099f0(p, kind) & 0xFF);
        if (t >= 0x63) {
            return 0;
        }
        sum = t + v;
        if (sum > 0x63) {
            v = 0x63 - t;
        }
        func_0010a780(p, kind, (s8)v);
    } else {
        v = (s16)(func_00231d70(1) + 1);
        t = (s16)(func_00109920(p, kind) & 0xFF);
        if (t < 2) {
            return 0;
        }
        if (t <= v) {
            v = t - 1;
        }
        func_0010a780(p, kind, (s8)(-v));
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(p + 2);
    *(u16 *)(arg1 + 8) = (u16)v;
    return 1;
}
