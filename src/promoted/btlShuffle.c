/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
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

extern void func_0043f9c8(void *dst, s32 value, s32 size);

extern s32 func_00451fc0(u8 *arg0, const void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);

extern void func_0036d860(u8 *arg0, s32 arg1);

extern void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_0036f410(u8 *arg0, u8 *arg1);

extern u8 D_0064E7A0[];

extern s32 func_0036e140(void);

extern void func_0036e600(void);

extern u16 func_00104dc0(s16 character);

extern void func_001056e0(s16 character, s16 value);

extern u32 func_00105610(s16 param);

extern s32 func_00105ee0();

extern u16 func_00104e30(s16 character);

extern u32 func_00104d50(s16 character);

extern void func_00105730(s16 character, s16 value);

extern u8 D_0064E5F0[];

extern u8 D_0064E5F1[];

extern u32 func_003b7060();

extern s32 func_0010b5b0();

extern s32 func_0010b510();

extern s32 func_0010abd0();

extern s32 func_0010aa80();

extern u8 *func_0010ace0();

extern s32 func_00109390();

extern void func_0010ad80();

extern u8 *func_0010b010(u16 personaId);

extern u8 *iGpffffb3c0;

extern u8 *iGpffffb3f0;
extern u8 *iGpffffb3e0;
extern u8 *iGpffffb3ec;
extern s32 func_001094d0(u32 arg0);
extern void func_0010cd70(u8 *arg0, s32 arg1, s32 arg2);

extern s32 D_0064E7B0[];

extern u16 D_0064E7B4[];

extern u16 D_0064E7B6[];

extern s32 D_0064E7B8[];

extern void func_00106550(s32 arg0, u32 arg1);

extern s32 func_00106330(s32 id);

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

extern void func_002baac0(s32 arg0);

extern void func_002bad10(s32 arg0);

extern void func_002bb7c0(s32 arg0);

extern s32 func_002bb600(void);

extern void func_002bb1e0(s32 arg0);

extern void func_002bb4e0(void);

extern void func_003798d0(u8 *arg0, s32 arg1);

extern s32 func_00379920(u8 *arg0);



// FUN_0036E140
s32 func_0036e140(void)
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
        if (func_00106330(0x1430) == 0) {
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
        func_002baac0(*(s32 *)(work + 0x1F354));
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
void func_0036e600(void)
{
    u8 *work = (u8 *)func_00452560();

    if (func_00106330(0x1430) == 0) {
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
    func_0043f9c8(work, 0, 0x21ABC);
    handle = func_00451fc0(arg0, D_0064E780, 0x12, 0, 0, (void *)func_0036e140,
                           (void *)func_0036e600, work);
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
s32 func_0036e920(u32 arg0)
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
s32 func_0036ea00(s32 arg0, s32 arg1)
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
s32 func_0036eb50(s32 arg0, s32 arg1)
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
        if (func_00106330(0x1431) != 0) {
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
        if (func_00106330(0x1432) != 0) {
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
        if (func_00106330(0x1433) != 0) {
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

/* measured: honest shuffle-state-machine (three s16[256] lists, s16/u16 temps,
 * B/C/A draw arms, shared emit tail) probes nd 292 at obj 1448B vs window
 * 1456B (frame 0x6D0 vs retail 0x6F0): retail spills hi/lo and two shuffle
 * rands to s128 slots with sq/lq, but b210 has no 128-bit C type (__int128 is
 * rejected; 16B struct copies lower to ld/sd; members scalar-replace), and
 * retail's B draw arm (F2F0-F318) sits behind an unconditional `b` while b210
 * deletes goto-skipped blocks -- both micro-measured. Spill victims are
 * immobile too (arg1/nA spill in every declaration order tried). Best body at
 * docs/probe_archive/BtlShuffle_0036EE60_body.c. Quadword + dead-block floor. */
// FUN_0036EE60
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036ee60);

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
            v = func_003b7060() & 0xFFF;
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
        v = func_003b7060() & 0xFFF;
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

    func_0043f9c8(arg1, 0, 0xC);
    if (func_00106330(0x1403) != 0) {
        a = 0;
        b = 0;
        for (idx = 0; idx < 0x2C; idx++) {
            p = (u8 *)D_0064E7B0 + idx * 12;
            if (func_00106330(*(s32 *)p) != 0) {
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
/* measured: prototype s32/u8* + frame 0xC0/CFG from retail; MATCH neighbours */
/* (fbe0/fd00/f640) give u16 counters + s32-masked flag + (s16) extends. */
/* Baseline probe nd 139 / fnalign 144 edits, obj 213 instrs (852B) vs window */
/* 216 (864B, 1.4% under). Levers: inclusive bounds (lim>12/a<=7/e<=7/e>7) */
/* fix slti $at -> $v0 (1 row, nd 134/edits 143); idx-based trailing halves */
/* (sp+112/114 -> h2+idx*4+0/2, correct addr) nd 133/edits 142; redundant */
/* sw+or+sw kept (halfword sh+sh +22 worse); s32 flag +10 worse; unsigned */
/* (<8U/==0-><1U) neutral. Walls: s-rotation ($s5 raw vs masked, $s2/$s3 vs */
/* $s0), frame 0xB0 vs 0xC0 (16B tighter, no spill padding), inner while-1-break */
/* vs beq+bnez. Saved-register + quadword floor; production stays ASM. */
// FUN_0036F880 NONMATCHING
#ifdef NON_MATCHING
s32 func_0036f880(s32 arg0, u8 *arg1)
{
    u32 w1[8];
    u32 h2[8];
    u16 lim;
    u16 cnt;
    u16 i;
    s16 v;
    u8 *pick;
    u32 t2;
    u8 *tbl;
    u16 s5v;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    u16 sA;
    u16 sB;

    lim = func_0010b5b0() & 0xFFFF;
    cnt = 0;
    if (lim > 12) {
        func_0046d730(D_0064E790, 1207);
    }
    i = 0;
    while (((i & 0xFFFF)) < lim) {
        v = (s16)i;
        if (func_0010abd0(v) != 0) {
            w1[cnt] = (u32)func_0010ace0(v);
            cnt = (cnt + 1) & 0xFFFF;
        }
        i = (i + 1) & 0xFFFF;
    }
    if ((cnt & 0xFFFF) == 0) {
        return 0;
    }
    pick = (u8 *)w1[func_00231d70(cnt)];
    t2 = func_001094d0((u32)pick);
    a = 0;
    b = 0;
    tbl = iGpffffb3ec;
    s5v = arg0 & 0xFFFF;
    while (((a & 0xFFFF)) <= 7) {
        {
            u16 cv = *(u16 *)(t2 + (a & 0xFFFF) * 2);
            if (cv != 0) {
                c = 0;
                if (s5v != 0) {
                    while (1) {
                        d = *(u16 *)(tbl + (c & 0xFFFF) * 4);
                        if (d == cv) {
                            break;
                        }
                        if (d == 0) {
                            break;
                        }
                        c = (c + 1) & 0xFFFF;
                    }
                    if (d != 0) {
                        e = 0;
                        while (((e & 0xFFFF)) <= 7) {
                            f = *(u16 *)(t2 + (e & 0xFFFF) * 2);
                            if (f == 0 || f == *(u16 *)(tbl + (c & 0xFFFF) * 4 + 2)) {
                                break;
                            }
                            e = (e + 1) & 0xFFFF;
                        }
                        if (((e & 0xFFFF)) > 7) {
                            h2[b] = d;
                            h2[b] = (h2[b] & 0xFFFF) | ((u32)*(u16 *)(tbl + (c & 0xFFFF) * 4 + 2) << 16);
                            b = (b + 1) & 0xFFFF;
                        }
                    }
                } else {
                    while (1) {
                        d = *(u16 *)(tbl + (c & 0xFFFF) * 4 + 2);
                        if (d == cv) {
                            break;
                        }
                        if (d == 0) {
                            break;
                        }
                        c = (c + 1) & 0xFFFF;
                    }
                    if (d != 0) {
                        e = 0;
                        while (((e & 0xFFFF)) <= 7) {
                            f = *(u16 *)(t2 + (e & 0xFFFF) * 2);
                            if (f == 0 || f == *(u16 *)(tbl + (c & 0xFFFF) * 4)) {
                                break;
                            }
                            e = (e + 1) & 0xFFFF;
                        }
                        if (((e & 0xFFFF)) > 7) {
                            h2[b] = d;
                            h2[b] = (h2[b] & 0xFFFF) | ((u32)*(u16 *)(tbl + (c & 0xFFFF) * 4) << 16);
                            b = (b + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        a = (a + 1) & 0xFFFF;
    }
    if ((b & 0xFFFF) == 0) {
        return 0;
    }
    {
        u32 idx = func_00231d70(b) & 0xFFFF;
        sA = *(u16 *)((u8 *)h2 + idx * 4 + 2);
        sB = *(u16 *)((u8 *)h2 + idx * 4);
        func_0010cd70(pick, (s16)sB, sA);
    }
    *(u16 *)(arg1 + 4) = *(u16 *)(pick + 2);
    *(u16 *)(arg1 + 8) = sB;
    *(u16 *)(arg1 + 6) = sA;
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
        r = (u16)func_00105ee0(i);
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
        if (t != 0 && (s16)func_0010aa80((s16)t) == -1 && (func_00109390(p) & 0xFF) < min) {
            best = p;
            min = func_00109390(p) & 0xFF;
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
        r = (u16)func_00105ee0(i);
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

