#include "include_asm.h"
#include "type.h"

/* Encounter-selection helpers (Kosaka unit).
 *
 * gp-relative globals (GP base 0x007690F0, see config/symbol_data_addrs.txt):
 *   iGpffffb41c (gp-0x4BE4 = 0x0076450C) -- pointer to the 10-byte encounter
 *       table entries (u16 id at +0, u8 flags/rates at +2/+3/+4, u16 at +6)
 *   iGpffffb418 (gp-0x4BE8 = 0x00764508) -- pointer to the 0xF8-stride
 *       per-encounter sub-table (two 0x78 halves, selected by the bool flag)
 *   iGpffffb424 (gp-0x4BDC = 0x00764514) -- pointer to the 0x15C-stride
 *       encounter-record table used by func_00161c80
 */

extern s32 func_0014a230();
extern s32 func_0014a2a0();
extern s32 func_0015a740();
extern s64 func_001060b0();
extern s32 func_001060c0();
extern s64 func_00110960();
extern s32 func_00106330();
extern u32 func_003b7060();
extern void func_0046d730();
extern u8 *iGpffffb41c;
extern u8 *iGpffffb418;
extern u8 *iGpffffb424;
extern u8 D_005F1260[];
extern u8 D_005F12C8[];
extern u8 D_007E80A0[];

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v0,$v0,$a0`; a base local or an m2c chain+base
   callsite spelling is canonicalized back to base-first. Expanded at the use so
   nothing stays live across the guard calls. */
static inline u32 encSlot(u32 offset, u32 base)
{
    return offset + base;
}

/* This "load-sinking + addu-flip floor" needed BOTH levers at once, which is why
   the four spellings listed before (plain expr, base local, m2c chain+base,
   fully split statements) all stalled at nd 8: `#pragma opt_propagation off`
   brings the single-use gp base load ahead of the index chain, and the `encSlot`
   helper holds the offset-first addu. Either alone leaves the other wrong.
   The same pair matches the identically shaped FUN_00161B10 below. */
// FUN_00161A70
/* measured: forces the single-use gp base load ahead of the index chain. */
#pragma opt_propagation off
s32 func_00161a70(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    u8 *base;

    result = 0;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        base = iGpffffb41c;
        result = *(u8 *)((u8 *)encSlot((arg2 & 0xFFFF) * 10, (u32)base) + 2);
    }
    return result;
}
/* measured: restores the file default after the function above. */
#pragma opt_propagation on

// FUN_00161B10
/* measured: same recipe as FUN_00161A70 -- the pragma forces the single-use gp
   base load ahead of the index chain. */
#pragma opt_propagation off
s32 func_00161b10(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    u8 *base;

    result = 0;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        base = iGpffffb41c;
        result = *(u8 *)((u8 *)encSlot((arg2 & 0xFFFF) * 10, (u32)base) + 4);
    }
    return result;
}
/* measured: restores the file default after the function above. */
#pragma opt_propagation on

// FUN_001619B0
/* measured: same pair of levers as FUN_00161A70 -- the pragma brings the gp base
   load ahead of the index chain, the helper holds the offset-first addu. */
#pragma opt_propagation off
s32 func_001619b0(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    s32 idx;
    s32 v;
    u8 *base;

    result = 0;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        base = iGpffffb41c;
        idx = arg2 & 0xFFFF;
        result = *(u8 *)((u8 *)encSlot(idx * 10, (u32)base) + 3);
        v = func_0015a740(idx) & 0xFF;
        if (v < 0xFF) {
            result = v;
        }
    }
    return result;
}
/* measured: restores the file default after the function above. */
#pragma opt_propagation on

/* The encounter tables and the constants 1/-1 are loop invariants that retail
   hoists ahead of both loops. */
/* measured: opt_loop_invariants on does that hoisting (and sign-extends the
   s16 id once into $t2); without it the bases are rematerialised per iteration
   (nd 45). `id == *(u16 *)(q + 2)` keeps retail's bne operand order. */
#pragma opt_loop_invariants on
// FUN_00161BB0
s32 func_00161bb0(s16 id) {
    s32 result;
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;

    result = 0;
    for (i = 0; ((s16 *)D_005F1260)[i] != -1; i++) {
        if (((s16 *)D_005F1260)[i] == id) {
            for (j = 0; j < 8; j++) {
                p = D_007E80A0 + j * 0x168;
                if (*(s32 *)(p + 0) != 0) {
                    q = *(u8 **)(p + 0x160);
                    if (q != NULL && *(s32 *)(p + 8) != 1 && id == *(u16 *)(q + 2)) {
                        result = 1;
                        break;
                    }
                }
            }
        }
    }
    return result;
}
/* measured: closes the hoisting scope after func_00161bb0. */
#pragma opt_loop_invariants off
/* Model floor (896B window; obj ~860B). Best probe nd 195.
   WINS: flat (A==0x28||A==0x3c)&&call==0 branch chain, arg0/arg1
   identifier swap (s1/s3 homes), 1.0f init, trunc idiom, (s32)
   modulo compares, blez >0 test, direct t0 (no extra move).
   WALLS: s2 shared-temp squatter (blocks arg3/i12 coalesce),
   result-init single-word (retail ori+andi), +16 layout shift,
   temp-reg names, GPREL/absolute display phantoms (relocs ok).
*/
// FUN_00161630 NONMATCHING
#ifdef NON_MATCHING
u32 func_00161630(u32 arg1, u32 arg0, u32 arg2, u32 arg3)
{
    u32 result;
    f32 f;
    u16 u2;
    s16 st;
    s8 c;
    u32 u13;
    u32 u11;
    s32 i16;
    s32 i17;
    s32 i12;
    s32 i6;
    s32 i;
    s32 sum;
    u32 m;
    u32 acc;
    u8 b;
    s32 i15;
    u8 *q;
    s32 ret28;

    u32 t = 0xFFFF;
    result = t & 0xFFFF;
    f = 1.0f;
    if ((func_0014a230() == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
        u2 = *(u16 *)(iGpffffb41c + ((arg2 & 0xFFFF) * 10));
        st = (s16)func_001060b0();
        c = (s8)func_00110960(st, func_001060c0() & 0xFF);
        u13 = (c == 1);
        if (func_00106330(0x1411) == 1) {
            f = 100.0f;
        }
        if (((arg0 & 0xFFFF) == 0x28) || ((arg0 & 0xFFFF) == 0x3C)) {
            if ((arg0 & 0xFFFF) != 0x28) {
                ret28 = func_00106330(0xC0F);
            }
            if (ret28 == 0) {
                f = 0.0f;
            }
        }
        i16 = u2 * 0xF8;
        u11 = *(u8 *)(iGpffffb418 + i16 + u13);
        if (func_00106330(0x1410) == 0) {
            if ((arg3 & 0xFFFF) > 0) {
                u11 += (s32)f * *(u8 *)(iGpffffb418 + i16 + u13 + 2);
            }
            if ((arg3 & 0xFFFF) >= 2) {
                u11 += *(u8 *)(iGpffffb418 + i16 + u13 + 4);
            }
        }
        if (u11 == 0) {
            func_0046d730(D_005F12C8, 0x69);
        }
        m = func_003b7060() % u11;
        b = *(u8 *)(iGpffffb418 + i16 + u13);
        if ((s32)m < (s32)b) {
            i17 = 1;
            i12 = 0;
            i6 = 0x14;
        } else if ((s32)m < (s32)(b + (s32)f * *(u8 *)(iGpffffb418 + i16 + u13 + 2))) {
            i17 = 2;
            i12 = 0x14;
            i6 = 0x19;
        } else {
            i17 = 4;
            i12 = 0x19;
            i6 = 0x1E;
        }
        sum = 0;
        i15 = u13 * 0x78;
        q = iGpffffb418 + i16 + i15;
        for (i = i12; i < i6; i++) {
            if (*(s16 *)(q + i * 4 + 8) != 0) {
                sum += *(u16 *)(q + i * 4 + 10);
            }
        }
        if (sum == 0) {
            return 0xFFFFFFFF;
        }
        m = func_003b7060() % sum;
        acc = 0;
        for (; i12 < i6; i12++) {
            acc += *(u16 *)(iGpffffb418 + i16 + i15 + i12 * 4 + 10);
            if ((s32)m < (s32)acc) {
                result = *(u16 *)(iGpffffb418 + i16 + i15 + i12 * 4 + 8);
                break;
            }
        }
        return (i17 << 16) | (result & 0xFFFF);
    }
    return 0xFFFFFFFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161630);
#endif

/* measured: no real C body was produced for this 1184B retail window; no
   candidate nd was retained. */
// FUN_00161C80
INCLUDE_ASM("asm/nonmatchings/k_encount", func_00161c80);
