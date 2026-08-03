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

extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);

extern void func_0036d860(u8 *arg0, s32 arg1);

extern void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_0036f410(u8 *arg0, u8 *arg1);

extern u8 D_0064E7A0[];

extern s32 func_0036e140(void);

extern void func_0036e600(void);

extern u32 func_00104dc0();

extern u32 func_001056e0();

extern s32 func_00105610(s16 param);

extern s32 func_00105ee0();

extern s32 func_00104e30();

extern s32 func_00104d50();

extern void func_00105730();

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

extern void func_0010b010();

extern u8 *iGpffffb3c0;

extern u8 *iGpffffb3f0;

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



/* measured: 10-state fallthrough switch machine; jump table jtbl_00752920
 * decoded entry-by-entry (state 0->1f0, 1->200, 2->350, 3->364, 4->3ac,
 * 5->408, 6->558, 7->430, 8->488, 9->504) and the case bodies + first loop
 * reproduce retail's structure (obj 1072B vs 1088B). Residual nd 158:
 * (1) iGpffffa9c0 as an array gives absolute lui/addiu where retail uses the
 * GP-relative addiu $gp,-0x5640 (scalar &iGpffffa9c0 form was worse, nd 197);
 * (2) the for-loop's i++ is scheduled as a separate instruction while retail
 * puts addiu $s1,1 in the jal delay slot, shifting the whole object by 4 bytes;
 * (3) the u16/s32 counter increments and the shared-return block land in
 * different registers/offsets. Loop-scheduling + gp-relative-array floor. */
// FUN_0036E140
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036e140);

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

/* measured: shuffle-state-machine; the three s16 lists (sp+0xF0/0x2F0/0x4F0)
 * and four s128 locals (spD0/spC0/spB0/spA0) reproduce the m2c logic but the
 * frame comes out 0x30 short (0x6C0 vs retail 0x6F0) and the object 96B short
 * (obj 1360B vs 1456B): retail stores 32-bit values directly into the s128
 * slots with sq (no widening pair), while b210 emits a dsll32/dsrl32 widening
 * pair before each sq -- the documented quadword write-side floor. Frame and
 * every s128 store/load sit at the wrong offset. Quadword-store floor. */
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
/* measured: body logic and u16 loop counters (andi masking + dsll32/dsra32
 * sign-extension) reproduce retail's structure (obj 816B vs window 864B);
 * residual nd ~191 is register allocation: mwcc b210 keeps arg0 flag in $s6
 * (frame 0xD0) where retail uses $s5 (frame 0xC0), pushing the slots array to
 * sp+0xA0 vs retail's 0x90 and rotating the loop registers. Named flag, all
 * counter types, and declaration orders tried; the extra live value across the
 * inner loop never coaders into $s0-$s5. Saved-register-count floor. */
// FUN_0036F880
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036f880);

/* measured: retail keeps u16 r in $s0, flag in $s1, s16 s in $s2, u16 counter
 * in $s3, and re-sign-extends r inside the if(arg0) branch while reusing the
 * hoisted s in the else branch. mwcc b210 always colors flag=$s0, counter=$s1,
 * s=$s2, r=$s3 and instead re-materializes (s16)r from the CSE'd s in the
 * ELSE branch (if-branch uses the CSE temp directly), giving nd 37. Tried
 * s32/u16 param, every declaration order (r,flag,s,i permutations), s/s2
 * separate locals, inline (s16)r in both branches, mirrored branch args, and
 * pre-branch s2 assignment: all plateau at nd 37 or regress to 60. Saved-
 * register coloring + branch re-materialization scheduling floor. */
// FUN_0036FBE0
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_0036fbe0);
// FUN_0036FD00
s32 func_0036fd00(s32 arg0, u8 *arg1)
{
    s32 flag = arg0 & 0xFFFF;
    s32 count = (u16)func_0010b5b0();
    u8 *p;
    u8 *best = NULL;
    u16 i;
    u16 min = 0x64;
    s32 bestFlag = 0;
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

/* measured: main body logic and switch dispatch (u32)(arg0 & 0xFFFF0000)>>16
 * reproduce retail's lui/and/srl + beq chain; register coloring for p/v17/v16
 * matches ($s2/$s1/$s0). Residual nd 132: retail sign-extends v16 with a
 * dsll32/dsra32 pair at each use (s16 and s32 declarations both fail) and loads
 * the v17 switch constants with daddiu (s32/s64 declarations both emit addiu).
 * Re-extension + daddiu-constant scheduling floor. */
// FUN_00370020
INCLUDE_ASM("asm/nonmatchings/btlShuffle", func_00370020);

