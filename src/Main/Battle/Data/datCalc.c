#include "type.h"
#include "include_asm.h"


extern u32 RpRandom(void);
extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_00635938[];

extern u32 func_003b7060(void);
extern u32 func_0023e130(u8 *arg0);

extern void memset(void *arg0, s32 arg1, s32 arg2);

typedef struct DatUnit
{
    u16 flags;         // 0x00
    u16 id;            // 0x02
    u16 id2;           // 0x04
    u8 level;          // 0x06
    u16 hp;            // 0x08
    u16 sp;            // 0x0a
    u32 bad;           // 0x0c
    s8 aiTactic;       // 0x10
    u8 unkData1[0x28];
} DatUnit;

extern u16 func_00231f80(DatUnit* unit);
extern u32 func_001053b0(s16 arg0);
extern s32 func_00232730(u8 *arg0, s32 arg1);
extern u16 func_00232950(u8 *arg0, s32 arg1);

extern u16 func_00232290(DatUnit* unit);

extern s32 func_00106600(s16 arg);

/* gp - 0x4C48 = 0x007690f0 - 0x4c48 = 0x007644a8 */
extern u8 *iGpffffb3b8;
/* gp - 0x4C40 = 0x007690f0 - 0x4c40 = 0x007644b0 */
extern u8 *iGpffffb3c0;

extern u8 *func_00106820(s16 arg0);

/* Old-style declaration: the retail call site at func_00232aa0 passes arg0 raw (no 64-bit extension). */
u16 func_00243920();

extern u16 func_00104dc0(s16 character);
extern void func_001056e0(s16 character, s16 value);
extern u16 func_00104e30(s16 character);
extern void func_00105730(s16 character, s16 value);
extern void func_00105d50(s16 character, u32 mask);

extern u8 *func_001094e0(u16 arg0);
extern u16 *func_0010a900(u16 arg0);
extern s32 func_00109390(s32 arg0);
extern u32 func_00105ed0(void);
extern u8 *func_00105510(s32 arg0);
extern u8 func_00232c70(u8 *arg0, s32 arg1);
/* Defined below in this file; used before its definition. */
extern u16 func_002439c0(u8 *arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern u16 func_001069d0(s16 arg0);
extern u16 func_00106a30(s16 arg0);
extern u32 func_001069a0(s16 arg0);

extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
extern s32 func_00238940(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern s32 func_00235520(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern u32 func_002397d0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5);
extern u32 func_00106330(s32 arg0);
extern s32 func_00109980(s32 arg0, s32 arg1);
extern s64 func_00233570(u8 *arg0, s32 arg1, s64 arg2);
/* func_00241de0 passes a 5th arg (arg4) that func_00241bc0 ignores. */
extern s32 func_00241bc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00244f60(u32 arg0, u16 *arg1, u16 *arg2, u16 arg3, s32 arg4);
extern u16 func_00247cb0(s64 arg0);
extern u16 func_00107ac0(s32 arg0);
/* Defined below in this file; used at line 184, before its definition. */
extern u8 *func_0023e140(u8 *arg0);

extern u8 *iGpffffb3b4;

extern u8 *iGpffffb408;
extern f32 iGpffff8110;

extern s32 func_0010a9b0(s32 arg0);

extern u8 *iGpffffb3c4;
extern u8 *iGpffffb448;
extern u8 *iGpffffb44c;
extern u8 *iGpffffb3cc;

extern void func_00233370(u8 *arg0, u8 arg1, s32 arg2);
extern void func_00233490(u8 *arg0, u8 arg1, s8 arg2);

extern u8 func_00232b40(u8 *arg0, s32 arg1);
extern u8 func_00109bf0(u16 arg0, s32 arg1);
extern s32 func_00106940(s16 arg0);
extern s32 func_00106970(s16 arg0);
extern u32 func_0023d9b0(u8 *arg0, s32 arg1);
extern s32 func_0023d8e0(u8 *arg0, u16 arg1);
extern s8 func_002332a0(u8 *arg0, s32 arg1);
extern u16 func_001068b0(s16 arg0);
extern u16 func_001068e0(s16 arg0);
extern u8 func_00106910(s16 arg0);
extern u16 func_00105460(s16 arg0);

static inline u32 PTDatCalcOffsetAdd(u32 offset, u32 base) { return offset + base; }


// FUN_00231D70
u32 func_00231d70(u32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_00635938, 0x17);
    }
    return RpRandom() % arg0;
}



// FUN_00231DC0
void func_00231dc0(u8 *arg0, s16 arg1)
{
    memset(arg0, 0, 0x30);
    *(s16 *)(arg0 + 2) = arg1;
    *(s8 *)(arg0 + 6) = 1;
    *(s16 *)(arg0 + 8) = 1;
    *(s16 *)(arg0 + 0xA) = 1;
    *(s16 *)(arg0 + 4) = arg1;
    *(s8 *)(arg0 + 0x10) = 0;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300410 (verified MATCH there). */


// FUN_00231E20
s32 func_00231e20(u8 *arg0)
{
    s32 level;

    if (*(u16 *)arg0 & 4 || *(u16 *)(arg0 + 2) == 1) {
        level = *(u8 *)(arg0 + 6);
    } else {
        level = (s32)func_0010a900(*(u16 *)(arg0 + 2));
        if (level == 0) {
            func_0046d730(D_00635938, 0x58);
        }
        level = func_00109390(level) & 0xFF;
    }
    if ((s32)(u8)level <= 0) {
        func_0046d730(D_00635938, 0x5C);
    }
    return level;
}

// FUN_00231EF0
void func_00231ef0(u8 *arg0, u8 arg1)
{
    if (arg1 > 99 && !(*(u16 *)arg0 & 4))
    {
        arg1 = 0x63;
    }
    arg0[6] = arg1;
}

/* MATCHED 2026-08-08: func_00231f80 is byte-exact (nd 0, object 784B /
   window 784B). A raw s32 temp with explicit masks at its uses, a named
   GP-base/index helper, #pragma opt_common_subs off, and
   #pragma opt_propagation off reproduce the retail saved-register lifetimes,
   table-address load order, and the slti $at clamp guard. */
// FUN_00231F80
/* measured: opt_common_subs/opt_propagation plus PTDatCalcOffsetAdd force retail index-first GP addressing; nested guard preserves slti $at branch form. */
#pragma opt_common_subs off
#pragma opt_propagation off
u16 func_00231f80(DatUnit *unit)
{
    s32 temp_16;
    s32 var_18;
    s32 var_3;
    u16 var_2;
    u8 *base;

    var_18 = 0;
    temp_16 = unit->id;
    if ((unit->flags & 4) != 0) {
        if ((temp_16 & 0xFFFF) >= 0x150) {
            func_0046d730(D_00635938, 0xBF);
        }
        base = iGpffffb3c4;
        var_2 = *(u16 *)((u8 *)PTDatCalcOffsetAdd((u32)((temp_16 & 0xFFFF) * 0x3C), (u32)base) + 4);
    } else {
        if ((temp_16 & 0xFFFF) >= 0xB) {
            func_0046d730(D_00635938, 0xC2);
        }
        var_2 = (u16)func_001053b0((s16)temp_16);
    }
    temp_16 = var_2 & 0xFFFF;
    if (func_00232730((u8 *)unit, 0x1F0) != 0) {
        var_18 += (temp_16 * 0xA) / 100;
    }
    if (func_00232730((u8 *)unit, 0x1F1) != 0) {
        var_18 += (temp_16 * 0x14) / 100;
    }
    if (func_00232730((u8 *)unit, 0x1F2) != 0) {
        var_18 += (temp_16 * 0x1E) / 100;
    }
    if (func_00232730((u8 *)unit, 0x22D) != 0) {
        var_18 += (temp_16 * 0x32) / 100;
    }
    if (func_00232730((u8 *)unit, 0x20C) != 0) {
        var_18 += temp_16;
    }
    if (func_00232730((u8 *)unit, 0x20D) != 0) {
        var_18 -= (temp_16 * 0x32) / 100;
    }
    var_18 += (func_00232950((u8 *)unit, 0x1A) & 0xFFFF) * 0xA;
    var_18 += (func_00232950((u8 *)unit, 0x1B) & 0xFFFF) * 0x14;
    var_18 += (func_00232950((u8 *)unit, 0x1C) & 0xFFFF) * 0x1E;
    var_18 += (func_00232950((u8 *)unit, 0x1D) & 0xFFFF) * 0x28;
    var_18 += (func_00232950((u8 *)unit, 0x1E) & 0xFFFF) * 0x32;
    var_3 = temp_16 + (var_18 + ((func_00232950((u8 *)unit, 0x5B) & 0xFFFF) * 0x64));
    if ((unit->flags & 4) == 0) {
        if (var_3 > 0x3E7) {
            var_3 = 0x3E7;
        }
    }
    return var_3 & 0xFFFF;
}
/* measured: close opt_propagation scope after 00231f80. */
#pragma opt_propagation on
/* measured: close opt_common_subs scope after 00231f80. */
#pragma opt_common_subs on


/* MATCHED 2026-08-08: func_00232290 is byte-exact (nd 0, object 784B /
   window 784B) using the same raw-s32/index-order/clamp template as
   func_00231f80, with its stat offsets and percentage constants substituted. */
// FUN_00232290
/* measured: sibling of exact 00231f80 template; raw s32 temp, integer GP-base addition, and direct clamp spelling preserve retail. */
#pragma opt_common_subs off
#pragma opt_propagation off
u16 func_00232290(DatUnit *unit)
{
    s32 temp_16;
    s32 var_18;
    s32 var_3;
    u16 var_2;
    u8 *base;

    var_18 = 0;
    temp_16 = unit->id;
    if ((unit->flags & 4) != 0) {
        if ((temp_16 & 0xFFFF) >= 0x150) {
            func_0046d730(D_00635938, 0xD9);
        }
        base = iGpffffb3c4;
        var_2 = *(u16 *)((u8 *)PTDatCalcOffsetAdd((u32)((temp_16 & 0xFFFF) * 0x3C), (u32)base) + 6);
    } else {
        if ((temp_16 & 0xFFFF) >= 0xB) {
            func_0046d730(D_00635938, 0xDC);
        }
        var_2 = (u16)func_00105460((s16)temp_16);
    }
    temp_16 = var_2 & 0xFFFF;
    if (func_00232730((u8 *)unit, 0x1F3) != 0) {
        var_18 += (temp_16 * 0xA) / 100;
    }
    if (func_00232730((u8 *)unit, 0x1F4) != 0) {
        var_18 += (temp_16 * 0x14) / 100;
    }
    if (func_00232730((u8 *)unit, 0x1F5) != 0) {
        var_18 += (temp_16 * 0x1E) / 100;
    }
    if (func_00232730((u8 *)unit, 0x22E) != 0) {
        var_18 += (temp_16 * 0x32) / 100;
    }
    if (func_00232730((u8 *)unit, 0x20C) != 0) {
        var_18 -= (temp_16 * 0x32) / 100;
    }
    if (func_00232730((u8 *)unit, 0x20D) != 0) {
        var_18 += temp_16;
    }
    var_18 += (func_00232950((u8 *)unit, 0x1F) & 0xFFFF) * 0xA;
    var_18 += (func_00232950((u8 *)unit, 0x20) & 0xFFFF) * 0x14;
    var_18 += (func_00232950((u8 *)unit, 0x21) & 0xFFFF) * 0x1E;
    var_18 += (func_00232950((u8 *)unit, 0x22) & 0xFFFF) * 0x28;
    var_18 += (func_00232950((u8 *)unit, 0x23) & 0xFFFF) * 0x32;
    var_3 = temp_16 + (var_18 + ((func_00232950((u8 *)unit, 0x8A) & 0xFFFF) * 0x64));
    if ((unit->flags & 4) == 0) {
        if (var_3 > 0x3E7) {
            var_3 = 0x3E7;
        }
    }
    return var_3 & 0xFFFF;
}
/* measured: close opt_propagation scope after 00232290. */
#pragma opt_propagation on
/* measured: close opt_common_subs scope after 00232290. */
#pragma opt_common_subs on
// FUN_002325A0
s32 func_002325a0(DatUnit* unit, s32 hpDelta)
{
    s32 maxHp;
    s32 newHp;

    newHp = unit->hp + hpDelta;
    if (newHp < 0) {
        newHp = 0;
    }
    maxHp = func_00231f80(unit) & 0xFFFF;
    if (maxHp < newHp) {
        newHp = maxHp;
    }
    unit->hp = (u16)newHp;
    return newHp & 0xFFFF;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300480 (verified MATCH there). */

// FUN_00232610
s32 func_00232610(DatUnit* unit, s32 spDelta)
{
    s32 maxSp;
    s32 newSp;

    newSp = unit->sp + spDelta;
    if (newSp < 0) {
        newSp = 0;
    }
    maxSp = func_00232290(unit) & 0xFFFF;
    if (maxSp < newSp) {
        newSp = maxSp;
    }
    unit->sp = (u16)newSp;
    return newSp & 0xFFFF;
}




/* Shared skill search, including the equipment fallback. */
static inline s32 PTDatCalcHasSkill(u8 *unit, s32 requestedSkill)
{
    s32 skill;
    s32 count;
    s32 index;
    u8 *base;
    s32 result;
    s32 limit;

    count = func_0023e130(unit) & 0xFFFF;
    base = func_0023e140(unit);
    index = 0;
    skill = requestedSkill & 0xFFFF;
    limit = count & 0xFFFF;
    while ((index & 0xFFFF) < limit) {
        if (skill == *(u16 *)(base + ((u16)index * 2))) {
            return 1;
        }
        index = (index + 1) & 0xFFFF;
    }
    if (!(*(u16 *)unit & 4)) {
        result = (s32)((u32)(u16)func_00106cd0(*(s16 *)(unit + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (skill == func_001069a0((s16)result)) {
                return 1;
            }
        }
    }
    return 0;
}

// FUN_00232730
s32 func_00232730(u8 *arg0, s32 arg1)
{
    return PTDatCalcHasSkill(arg0, arg1);
}

// FUN_00232830
s32 func_00232830(u16 *arg0, s64 arg1)
{
    if (*arg0 & 4) {
        return 0;
    }
    return (func_00106600((s16)arg1) & 0xFF) > 0;
}




// FUN_00232880
u16 func_00232880(u16 arg0, u16 arg1)
{
    u16 count;
    s16 id;
    u16 val;

    if ((arg0 & 0xFFFF) >= 0xB) {
        func_0046d730(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)arg0;
    val = (u16)arg1;
    if ((func_001069d0(func_00106cd0(id, 0)) & 0xFFFF) == val) {
        count++;
    }
    if ((func_001069d0(func_00106cd0(id, 1)) & 0xFFFF) == val) {
        count++;
    }
    return count;
}

// FUN_00232950
u16 func_00232950(u8 *arg0, s32 arg1)
{
    u16 count;
    s16 id;
    u16 id16;
    u16 val;

    if (*(u16 *)arg0 & 4) {
        return 0;
    }
    id16 = *(u16 *)(arg0 + 2);
    if (id16 >= 0xB) {
        func_0046d730(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)id16;
    val = (u16)arg1;
    if ((func_001069d0(func_00106cd0(id, 0)) & 0xFFFF) == val) {
        count++;
    }
    if ((func_001069d0(func_00106cd0(id, 1)) & 0xFFFF) == val) {
        count++;
    }
    return count;
}

// FUN_00232A40
s32 func_00232a40(s32 arg0)
{
    s32 id;
    u8 *base;

    id = arg0 & 0xFFFF;
    if (id >= 0x1B8) {
        return 0;
    } else {
        base = iGpffffb3b8 + id * 0x28;
        if (base[0] & 2) {
            return 0;
        }
        return (base[1] & 1) != 0;
    }
}

// FUN_00232AA0
s32 func_00232aa0(s32 arg0)
{
    u16 id16;

    if ((arg0 & 0xFFFF) <= 0x300 || (arg0 & 0xFFFF) >= 0x400) {
        return 0;
    } else {
        id16 = func_00243920(arg0) & 0xFFFF;
        if (id16 == 0) {
            return 0;
        }
        if (id16 >= 0x1B8) {
            return 0;
        }
        return (iGpffffb3b8[id16 * 0x28 + 1] & 2) != 0;
    }
}

/* measured: daddiu return constants ARE reachable â€” u8 var_2 with
   `var_2 = 1;` / `var_2 = 0x63;` emits daddiu (s32 never does), the
   (s32)((u32)arg1 & 0xFFFF) guard gives bltz, and `temp_3 > 0x63` the
   slti-$at form; tail fully matches. Best nd 5: residual is the
   table-index load-sinking floor â€” retail lw's the iGpffffb3c4 base
   into $a0 BEFORE the *0x3C mul chain and masks the index last; mwcc
   b210 sinks the lw after the mul (index-first, base-first, base-local
   spellings all tried). */
/* measured: recipe-A re-test 2026-08-03. The bltz guard works unchanged
   (`(s32)((u32)arg1 & 0xFFFF)` keeps the single bare bltz; offsets 28-44
   byte-match). New finding: the table index needs TWO separate andi's in
   retail (one before the >=0x150/>=0xB error tests, one before the *0x3C
   mul chain); spelling the tests `(u16)temp_16` and the mul
   `(temp_16 & 0xFFFF)` defeats mwcc's mask CSE (a bare double `& 0xFFFF`
   collapses to one in-place `andi $s0`). Also fixed the wrong extern:
   func_00109980 is `s32 (s32, s32)` per datPersona.c (u16 param forced a
   bogus pre-call andi). Tail fully matches (daddiu 1/0x63, slti-$at form).
   Residual, best nd 9: the table-index load-sinking floor -- retail lw's
   the iGpffffb3c4 base into $a0 BEFORE the *0x3C mul chain and adds arg1's
   mask last; mwcc b210 sinks the lw after the mul (index-first, base-first,
   base-local, draft-tree spellings all tried). */
/* measured 2026-08-03 (re-test): nd 9 confirmed with the s32-temp_16
   combo (test `(u16)temp_16`, index `(temp_16 & 0xFFFF)`, arg1-index
   `(u16)arg1` keep the three andis separate; u16 temp_16 collapses the
   cast into the AND node and hoists one mask into s1, nd 72). Tail fully
   matches: bltz guard, daddiu 1/0x63, slti-$at form, func_00109980 call.
   Residual is the same load-sinking floor as func_0023e3e0's case 0:
   retail lw's the iGpffffb3c4 base into $a0 BEFORE the *0x3C andi-chain
   and masks arg1 last; mwcc b210 sinks the lw after the chain into $v0.
   Tried: inline, base-local (`u8 *base = iGpffffb3c4;`), elem-pointer
   local, chain-first/base-first addition order -- all nd 9. */
/* measured this pass: the load-sinking half IS the same defect func_0023e3e0
   solved, and `#pragma opt_propagation off` plus nested PTDatCalcOffsetAdd calls
   (offset-first for both the *0x3C chain and the arg1 mask) is the recipe that
   worked there. It could not be applied here because the recorded nd-9 body is
   not reconstructable from this note: a fresh reconstruction of the guards and
   tail lands at nd 68 (74 with the pragma), so the combo has not actually been
   tested against the good body. Whoever holds a body at nd 9 should try it --
   do NOT re-derive from scratch. */
/* measured: widened temp to s32 and cast each u16 use, keeping the unmasked
   source live while scratch andi values feed the guards/index; removed the
   named check and kept the direct bound comparison. normalized_diff 0,
   object 296B/304B. Committed at nd 0. */
// FUN_00232B40
u8 func_00232b40(u8 *arg0, s32 arg1)
{
    s32 temp;
    u8 value;
    u32 index;
    u8 *base;

    if ((s32)(arg1 & 0xFFFF) < 0 || (s32)(arg1 & 0xFFFF) >= 5)
        func_0046d730(D_00635938, 0x2F0);
    temp = *(u16 *)(arg0 + 2);
    if ((*(u16 *)arg0 & 4) != 0) {
        if ((u16)temp >= 0x150)
            func_0046d730(D_00635938, 0x2F7);
        base = (u8 *)iGpffffb3c4;
        index = (u32)(u16)temp * 0x3C;
        base = (u8 *)(index + (u32)base);
        base = (u8 *)(((u32)arg1 & 0xFFFF) + (u32)base);
        value = *(u8 *)(base + 8);
    } else {
        if ((u16)temp >= 0xB)
            func_0046d730(D_00635938, 0x2FA);
        value = (u8)func_00109980(temp, arg1);
    }
    if ((s32)value > 0)
        goto clamp_value;
    value = 1;
    goto done_value;
clamp_value:
    if (value > 0x63)
        value = 0x63;
done_value:
    return value;
}

/* measured: archived candidate re-tested at nd 2; return-width and guard probes did not improve it. */
/* measured: the two clamp constants are `daddiu $v0,$zero,K` because the
   value is a u8 (narrow-unsigned rule) and the function returns u8, which
   keeps it in $v0; `v >>= 1` on the u8 avoids the extra re-mask a spelled-out
   `(u32)v >> 1` adds; `<= 0x63` before the goto gives the slti $at form. */
// FUN_00232C70
u8 func_00232c70(u8 *arg0, s32 arg1)
{
    u8 v;
    s32 temp_3;
    u8 flag;

    if (((s32)(arg1 & 0xFFFF) < 0) || ((arg1 & 0xFFFF) >= 5)) {
        func_0046d730(D_00635938, 0x313);
    }
    if ((*(u16 *)arg0 & 4) != 0) {
        v = (u32)func_00232b40(arg0, arg1);
        v &= 0xFF;
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x31A);
        }
        v = (u32)func_00109bf0(*(u16 *)(arg0 + 2), arg1);
        v &= 0xFF;
    }
    flag = (*(s32 *)(arg0 + 0xC) & 0x80) != 0;
    if (!flag) {
        goto no_shift;
    }
    v >>= 1;
no_shift:
    temp_3 = (u32)v & 0xFF;
    if (temp_3 > 0) {
        goto clamp_value;
    }
    v = 1;
    goto done_value;
clamp_value:
    if (temp_3 <= 0x63) {
        goto done_value;
    }
    v = 0x63;
done_value:
    return v;
}

// FUN_00232D80
#pragma push
/* measured: 1304B/1312B, eight zero-tail bytes and 24 resolved relocations;
   loop-invariant hoisting preserves the retail six-search preheaders. */
#pragma opt_loop_invariants on
s32 func_00232d80(u8 *arg0)
{
    s32 result;
    result = 0;
    if (PTDatCalcHasSkill(arg0, 0x1F9) != 0) {
        result |= 0x1;
    }
    if (PTDatCalcHasSkill(arg0, 0x1FA) != 0) {
        result |= 0x2;
    }
    if (PTDatCalcHasSkill(arg0, 0x1FB) != 0) {
        result |= 0x4;
    }
    if (PTDatCalcHasSkill(arg0, 0x1FC) != 0) {
        result |= 0x8;
    }
    if (PTDatCalcHasSkill(arg0, 0x1FD) != 0) {
        result |= 0x10;
    }
    if (PTDatCalcHasSkill(arg0, 0x1FE) != 0) {
        result |= 0x20;
    }
    return result;
}
#pragma pop

// FUN_002332A0
s8 func_002332a0(u8 *arg0, s32 arg1)
{
    s8 value;
    u8 index;
    u16 offset;

    if ((s32)(arg1 & 0xff) >= 0x18) {
        func_0046d730(D_00635938, 0x40F);
    }
    index = arg1;
    offset = index >> 1;
    if (index & 1) {
        value = *(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 0x1c) >> 4;
    }
    else {
        value = *(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 0x1c) & 0xf;
    }
    if (7 < value) {
        value = (s8)(value - 0xf);
    }
    return value;
}

// FUN_00233370
void func_00233370(u8 *arg0, u8 arg1, s32 arg2)
{
    s32 temp_16;
    s32 temp_4;
    s8 temp_19;
    s32 var_17;

    var_17 = arg2;
    temp_16 = arg1 & 0xFF;
    if (temp_16 >= 0x18) {
        func_0046d730(D_00635938, 0x441);
    }
    temp_19 = (s8)var_17;
    if (temp_19 > 7 || temp_19 < -7) {
        func_0046d730(D_00635938, 0x442);
    }
    temp_4 = (temp_16 >> 1) & 0xFFFF;
    if (temp_19 < 0) {
        var_17 = (s8)(temp_19 + 0xF);
    }
    if (temp_16 & 1) {
        u8 *temp_5 = (u8 *)((temp_4 & 0xFFFF) + (s32)arg0);
        temp_5[0x1C] = (u8)((temp_5[0x1C] & 0xF) | (((s8)var_17 & 0xF) << 4));
        return;
    }
    {
        u8 *temp_5 = (u8 *)((temp_4 & 0xFFFF) + (s32)arg0);
        temp_5[0x1C] = (u8)((temp_5[0x1C] & 0xF0) | ((s8)var_17 & 0xF));
    }
}

// FUN_00233490
void func_00233490(u8 *arg0, u8 arg1, s8 arg2)
{
    u8 *b;
    u16 idx;
    u8 old;

    if (arg1 >= 0x18) {
        func_0046d730(D_00635938, 0x45E);
    }
    if (arg2 < 0) {
        func_0046d730(D_00635938, 0x45F);
    }
    idx = ((s32)arg1 >> 1) & 0xFFFF;
    b = arg0;
    if (arg1 & 1) {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF) | ((arg2 & 0xF) << 4));
    } else {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF0) | (arg2 & 0xF));
    }
}

/* measured: fully relocated 784B / 784B match, with no tail gap.
   Keep the standalone signed-byte promotion at the getter branch merge:
   it preserves retail scratch-register lifetimes before the signed decode. */
// FUN_00233570
s64 func_00233570(u8 *arg0, s32 arg1, s64 arg2)
{
    s32 index;
    u8 byteIndex;
    s32 halfIndex;
    u16 offset;
    s32 odd;
    s32 value;
    s32 current;
    s16 result;
    s8 packed;
    s8 checked;
    u8 *ptr;

    index = arg1 & 0xff;
    if (index >= 24) {
        func_0046d730(D_00635938, 1142);
    }
    result = 0;
    if (index < 16) {
        if (index >= 24) {
            func_0046d730(D_00635938, 1039);
        }
        byteIndex = arg1;
        halfIndex = byteIndex >> 1;
        offset = halfIndex;
        odd = byteIndex & 1;
        if (odd) {
            value = (s8)(*(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 28) >> 4);
        } else {
            value = (s8)(*(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 28) & 15);
        }
        value = (s8)value;
        if (value > 7) {
            value = (s8)(value - 15);
        }
        current = (s8)value;
        if ((s8)arg2 == 0) {
            return (s8)current;
        }
        result = current + (s8)arg2;
        if (result > 1) {
            result = 1;
        } else if (result < -1) {
            result = -1;
        }
        packed = result;
        if (index >= 24) {
            func_0046d730(D_00635938, 1089);
        }
        checked = packed;
        if (checked > 7 || checked < -7) {
            func_0046d730(D_00635938, 1090);
        }
        offset = halfIndex;
        if (checked < 0) {
            packed = (s8)(checked + 15);
        }
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[28] = (ptr[28] & 15) | ((packed & 15) << 4);
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[28] = (ptr[28] & 240) | (packed & 15);
        }
        if (result == 0) {
            *(s32 *)(arg0 + 20) &= ~(1 << index);
        } else {
            *(s32 *)(arg0 + 20) |= 1 << index;
        }
        if (index >= 24) {
            func_0046d730(D_00635938, 1118);
        }
        offset = halfIndex;
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[36] &= 15;
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)arg0);
            ptr[36] &= 240;
        }
    } else {
        *(s32 *)(arg0 + 20) |= 1 << index;
    }
    return (s8)result;
}

// FUN_00233880
void func_00233880(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_3;
    s32 temp_3_2;
    u8 *ptr;

    temp_18 = arg1 & 0xFF;
    if (temp_18 >= 0x18) {
        func_0046d730(D_00635938, 0x4A2);
    }
    if (temp_18 < 0x10) {
        if (temp_18 >= 0x18) {
            func_0046d730(D_00635938, 0x441);
        }
        temp_17 = temp_18 >> 1;
        temp_3 = temp_17 & 0xFFFF;
        temp_16 = temp_18 & 1;
        if (temp_16 != 0) {
            ptr = (u8 *)((temp_3 & 0xFFFF) + (s32)arg0);
            ptr[0x1C] = (u8)(ptr[0x1C] & 0xF);
        } else {
            ptr = (u8 *)((temp_3 & 0xFFFF) + (s32)arg0);
            ptr[0x1C] = (u8)(ptr[0x1C] & 0xF0);
        }
        if (temp_18 >= 0x18) {
            func_0046d730(D_00635938, 0x45E);
        }
        temp_3_2 = (u16)temp_17;
        if (temp_16 != 0) {
            ptr = (u8 *)((temp_3_2 & 0xFFFF) + (s32)arg0);
            ptr[0x24] = (u8)(ptr[0x24] & 0xF);
        } else {
            ptr = (u8 *)((temp_3_2 & 0xFFFF) + (s32)arg0);
            ptr[0x24] = (u8)(ptr[0x24] & 0xF0);
        }
    }
    *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) & ~(1 << temp_18);
}

// FUN_002339D0
void func_002339d0(u8 *arg0)
{
    u32 i;
    s32 i8;

    for (i = 0; i < 0x18; i++) {
        i8 = i & 0xFF;
        if (i8 >= 0x18) {
            func_0046d730(D_00635938, 0x4A2);
        }
        if (i8 < 0x10) {
            func_00233370(arg0, i, 0);
            func_00233490(arg0, i, 0);
        }
        *(s32 *)(arg0 + 0x14) &= ~(1 << i8);
    }
}

// FUN_00233A90
s8 func_00233a90(u8 *arg0, s32 arg1)
{
    s8 nibble;
    u8 result;
    u8 index;
    u16 offset;
    s32 uVar3;

    uVar3 = arg1 & 0xff;
    if (uVar3 >= 0x18) {
        func_0046d730(D_00635938, 0x4C1);
    }
    if (uVar3 < 0x10) {
        if (uVar3 >= 0x18) {
            func_0046d730(D_00635938, 0x40F);
        }
        index = arg1;
        offset = index >> 1;
        if (index & 1) {
            nibble = *(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 0x1c) >> 4;
        }
        else {
            nibble = *(u8 *)(PTDatCalcOffsetAdd(offset, (u32)arg0) + 0x1c) & 0xf;
        }
        if (7 < nibble) {
            nibble = (s8)(nibble - 0xf);
        }
        return nibble;
    }
    result = (*(u32 *)(arg0 + 0x14) & 1 << uVar3) != 0;
    return result;
}

// FUN_00233BC0
/* The low-byte status index must be below 24. Retail diagnoses that
 * contract twice; all six executable callers pass constants 0..4.
 * Their third argument is an unused u16 skill ID; preserving that contract
 * avoids caller-side widening before the matching hit and damage routines. */
#pragma push
#pragma opt_propagation off
f32 func_00233bc0(u8 *arg0, s32 arg1, u16 arg2)
{
    s32 index;
    u8 active;
    s32 enemyFlag;
    u32 enemy;
    s16 enemyPredicate;
    f32 multiplier;
    f32 percentage;
    s32 value;
    u8 *table;
    s32 status;

    index = arg1 & 0xFF;
    if (index >= 24) {
        func_0046d730(D_00635938, 1265);
    }
    if (index >= 24) {
        func_0046d730(D_00635938, 1217);
    }
    status = (s8)(index < 16 ? func_002332a0(arg0, arg1) :
        (s8)(active = (*(u32 *)(arg0 + 20) & (1U << index)) != 0));
    if (status < -1 || status > 1) {
        func_0046d730(D_00635938, 1269);
    }
    enemyFlag = (*(u16 *)arg0 & 4);
    enemyPredicate = enemyFlag != 0;
    enemy = (u16)enemyPredicate;
    multiplier = 1.0f;
    switch (index) {
    case 0:
        table = iGpffffb408;
        value = *(u8 *)(PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)) + 1U);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        active = (*(u32 *)(arg0 + 20) & 0x40000U) != 0;
        if ((s8)active > 0) {
            multiplier = multiplier * 2.5f;
        }
        if (enemyFlag == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 1:
        table = iGpffffb408;
        value = *(u8 *)(PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)) + 1U);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        active = (*(u32 *)(arg0 + 20) & 0x80000U) != 0;
        if ((s8)active > 0) {
            multiplier = multiplier * 2.5f;
        }
        if (enemyFlag == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 2:
        table = iGpffffb408;
        value = *(u8 *)(PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table) + 7U - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 3:
        table = iGpffffb408;
        value = *(u8 *)(PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table) + 1U - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 4:
        table = iGpffffb408;
        value = *(u8 *)(PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)) + 7U);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 18:
        if (status > 0) {
            multiplier = 2.5f;
        }
        break;
    case 19:
        if (status > 0) {
            multiplier = 2.5f;
        }
        break;
    }
    return multiplier;
}

#pragma pop

/* measured: func_002340c0 matches retail's 1904-byte window (1900-byte
   emitted body plus the retail zero-padding tail). The 0x30000 branch uses
   goto-labelled shared return blocks, and each s64 flag normalization is
   explicitly re-booleanized after dsra32 to preserve retail's sltu sequence. */
// FUN_002340C0
s32 func_002340c0(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    s64 var_2;

    if (arg1 == 0) {
        return 0;
    }
    if (arg1 & 1) {
        return func_002332a0(arg0, 0) > 0;
    }
    if (arg1 & 2) {
        return func_002332a0(arg0, 0) < 0;
    }
    if (arg1 & 4) {
        return func_002332a0(arg0, 1) > 0;
    }
    if (arg1 & 8) {
        return func_002332a0(arg0, 1) < 0;
    }
    if (arg1 & 0x10) {
        return func_002332a0(arg0, 2) > 0;
    }
    if (arg1 & 0x20) {
        return func_002332a0(arg0, 2) < 0;
    }
    if (arg1 & 0x40) {
        return func_002332a0(arg0, 3) > 0;
    }
    if (arg1 & 0x80) {
        return func_002332a0(arg0, 3) < 0;
    }
    if (arg1 & 0x100) {
        return func_002332a0(arg0, 4) > 0;
    }
    if (arg1 & 0x200) {
        return func_002332a0(arg0, 4) < 0;
    }
    if (arg1 & 0x400) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x40000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (arg1 & 0x800) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x80000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (arg1 & 0x4000) {
        return func_002332a0(arg0, 5) != 0;
    }
    if (arg1 & 0x8000) {
        return func_002332a0(arg0, 6) != 0;
    }
    if (arg1 == 0x30000) {
        goto case_30000;
    }
    if (arg1 & 0x10000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x10000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (arg1 & 0x20000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x20000) != 0) << 0x38) >> 0x38) != 0;
    }
    goto rest_30000;
case_30000:
    temp_3 = *(s32 *)(arg0 + 0x14);
    var_2 = (s64)((temp_3 & 0x10000) != 0);
    var_2 = (s64)(var_2 << 0x38) >> 0x38;
    var_2 = var_2 != 0;
    if (var_2 == 0) {
        var_2 = (s64)((temp_3 & 0x20000) != 0);
        var_2 = (s64)(var_2 << 0x38) >> 0x38;
        var_2 = var_2 != 0;
    }
    return var_2 != 0;
rest_30000:
    if (arg1 & 0x40000) {
        return func_002332a0(arg0, 8) != 0;
    }
    if (arg1 & 0x80000) {
        return func_002332a0(arg0, 9) != 0;
    }
    if (arg1 & 0x100000) {
        return func_002332a0(arg0, 0xA) != 0;
    }
    if (arg1 & 0x200000) {
        return func_002332a0(arg0, 0xB) != 0;
    }
    if (arg1 & 0x400000) {
        return func_002332a0(arg0, 7) != 0;
    }
    if (arg1 & 0x800000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x100000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (arg1 & 0x04000000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x800000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (arg1 & 0x08000000) {
        return func_002332a0(arg0, 0xC) != 0;
    }
    if (arg1 & 0x10000000) {
        return func_002332a0(arg0, 0xD) != 0;
    }
    if (arg1 & 0x20000000) {
        return func_002332a0(arg0, 0xE) != 0;
    }
    if (arg1 & 0x40000000) {
        return func_002332a0(arg0, 0xF) != 0;
    }
    if (arg1 & 0x1000) {
        if (func_002332a0(arg0, 0) <= 0) {
            if (func_002332a0(arg0, 1) <= 0) {
                if (func_002332a0(arg0, 2) <= 0) {
                    if (func_002332a0(arg0, 3) <= 0) {
                        if (func_002332a0(arg0, 4) > 0) {
                            goto return_zero_1000;
                        }
                        goto return_one_1000;
                    }
                    goto return_zero_1000;
                }
                goto return_zero_1000;
            }
            goto return_zero_1000;
        }
        goto return_zero_1000;
    }
    goto check_2000;
return_zero_1000:
    return 0;
return_one_1000:
    return 1;
check_2000:
    if (arg1 & 0x2000) {
        if (func_002332a0(arg0, 0) >= 0) {
            if (func_002332a0(arg0, 1) >= 0) {
                if (func_002332a0(arg0, 2) >= 0) {
                    if (func_002332a0(arg0, 3) >= 0) {
                        if (func_002332a0(arg0, 4) < 0) {
                            goto return_zero_2000;
                        }
                        goto return_one_2000;
                    }
                    goto return_zero_2000;
                }
                goto return_zero_2000;
            }
            goto return_zero_2000;
        }
        goto return_zero_2000;
    }
    goto check_01000000;
return_zero_2000:
    return 0;
return_one_2000:
    return 1;
check_01000000:
    if (arg1 & 0x01000000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x10000) != 0) << 0x38) >> 0x38) == 0;
    }
    if (arg1 & 0x02000000) {
        return (((s64)((*(s32 *)(arg0 + 0x14) & 0x20000) != 0) << 0x38) >> 0x38) == 0;
    }
    func_0046d730(D_00635938, 0x5DE);
    return 0;
}

// FUN_00234830
void func_00234830(u8 *arg0, s32 arg1, s64 arg2)
{
    if (arg1 != 0) {
        if (arg1 & 1) {
            func_00233570(arg0, 0, arg2);
        }
        if (arg1 & 2) {
            func_00233570(arg0, 0, (s64)(s8)-(s8)arg2);
        }
        if (arg1 & 4) {
            func_00233570(arg0, 1, arg2);
        }
        if (arg1 & 8) {
            func_00233570(arg0, 1, (s64)(s8)-(s8)arg2);
        }
        if (arg1 & 0x10) {
            func_00233570(arg0, 2, arg2);
        }
        if (arg1 & 0x20) {
            func_00233570(arg0, 2, (s64)(s8)-(s8)arg2);
        }
        if (arg1 & 0x40) {
            func_00233570(arg0, 3, arg2);
        }
        if (arg1 & 0x80) {
            func_00233570(arg0, 3, (s64)(s8)-(s8)arg2);
        }
        if (arg1 & 0x100) {
            func_00233570(arg0, 4, arg2);
        }
        if (arg1 & 0x200) {
            func_00233570(arg0, 4, (s64)(s8)-(s8)arg2);
        }
        if (arg1 & 0x400) {
            func_00233570(arg0, 0x12, arg2);
        }
        if (arg1 & 0x800) {
            func_00233570(arg0, 0x13, arg2);
        }
        if (arg1 & 0x1000) {
            if ((s8)func_002332a0(arg0, 0) > 0) {
                func_00233370(arg0, 0, 0);
                func_00233490(arg0, 0, 0);
                *(s32 *)(arg0 + 0x14) &= ~1;
            }
            if ((s8)func_002332a0(arg0, 1) > 0) {
                func_00233370(arg0, 1, 0);
                func_00233490(arg0, 1, 0);
                *(s32 *)(arg0 + 0x14) &= ~2;
            }
            if ((s8)func_002332a0(arg0, 2) > 0) {
                func_00233370(arg0, 2, 0);
                func_00233490(arg0, 2, 0);
                *(s32 *)(arg0 + 0x14) &= ~4;
            }
            if ((s8)func_002332a0(arg0, 3) > 0) {
                func_00233370(arg0, 3, 0);
                func_00233490(arg0, 3, 0);
                *(s32 *)(arg0 + 0x14) &= ~8;
            }
            if ((s8)func_002332a0(arg0, 4) > 0) {
                func_00233370(arg0, 4, 0);
                func_00233490(arg0, 4, 0);
                *(s32 *)(arg0 + 0x14) &= ~0x10;
            }
        }
        if (arg1 & 0x2000) {
            if ((s8)func_002332a0(arg0, 0) < 0) {
                func_00233370(arg0, 0, 0);
                func_00233490(arg0, 0, 0);
                *(s32 *)(arg0 + 0x14) &= ~1;
            }
            if ((s8)func_002332a0(arg0, 1) < 0) {
                func_00233370(arg0, 1, 0);
                func_00233490(arg0, 1, 0);
                *(s32 *)(arg0 + 0x14) &= ~2;
            }
            if ((s8)func_002332a0(arg0, 2) < 0) {
                func_00233370(arg0, 2, 0);
                func_00233490(arg0, 2, 0);
                *(s32 *)(arg0 + 0x14) &= ~4;
            }
            if ((s8)func_002332a0(arg0, 3) < 0) {
                func_00233370(arg0, 3, 0);
                func_00233490(arg0, 3, 0);
                *(s32 *)(arg0 + 0x14) &= ~8;
            }
            if ((s8)func_002332a0(arg0, 4) < 0) {
                func_00233370(arg0, 4, 0);
                func_00233490(arg0, 4, 0);
                *(s32 *)(arg0 + 0x14) &= ~0x10;
            }
        }
        if (arg1 & 0x4000) {
            func_00233570(arg0, 5, arg2);
        }
        if (arg1 & 0x8000) {
            func_00233570(arg0, 6, arg2);
        }
        if (arg1 & 0x10000) {
            func_00233570(arg0, 0x10, arg2);
        }
        if (arg1 & 0x20000) {
            func_00233570(arg0, 0x11, arg2);
        }
        if (arg1 & 0x40000) {
            func_00233570(arg0, 8, arg2);
        }
        if (arg1 & 0x80000) {
            func_00233570(arg0, 9, arg2);
        }
        if (arg1 & 0x100000) {
            func_00233570(arg0, 0xA, arg2);
        }
        if (arg1 & 0x200000) {
            func_00233570(arg0, 0xB, arg2);
        }
        if (arg1 & 0x400000) {
            func_00233570(arg0, 7, arg2);
        }
        if (arg1 & 0x800000) {
            func_00233570(arg0, 0x14, arg2);
        }
        if (arg1 & 0x04000000) {
            func_00233570(arg0, 0x17, arg2);
        }
        if (arg1 & 0x08000000) {
            func_00233570(arg0, 0xC, arg2);
        }
        if (arg1 & 0x10000000) {
            func_00233570(arg0, 0xD, arg2);
        }
        if (arg1 & 0x20000000) {
            func_00233570(arg0, 0xE, arg2);
        }
        if (arg1 & 0x40000000) {
            func_00233570(arg0, 0xF, arg2);
        }
        if (arg1 & 0x01000000) {
            *(s32 *)(arg0 + 0x14) &= 0xFFFEFFFF;
        }
        if (arg1 & 0x02000000) {
            *(s32 *)(arg0 + 0x14) &= 0xFFFDFFFF;
        }
    }
}

// FUN_00235020
void func_00235020(u8 *arg0)
{
    u32 i;
    s32 i8;
    u32 mask;

    mask = *(s32 *)(arg0 + 0x18);
    if (mask != 0) {
        for (i = 0; i < 0x18; i++) {
            if (mask & (1 << i)) {
                i8 = i & 0xFF;
                if (i8 >= 0x18) {
                    func_0046d730(D_00635938, 0x4A2);
                }
                if (i8 < 0x10) {
                    func_00233370(arg0, i, 0);
                    func_00233490(arg0, i, 0);
                }
                *(s32 *)(arg0 + 0x14) &= ~(1 << i8);
            }
        }
        *(s32 *)(arg0 + 0x18) = 0;
    }
}

static inline s8 P4CalcLevel(u8 *unit, u8 index)
{
    u16 offset;
    /* Preserve the signed-byte getter conversion at the branch merge. */
    s32 level;
    if ((s32)index >= 24)
        func_0046d730(D_00635938, 0x42A);
    offset = index >> 1;
    if (index & 1)
        level = (s8)(*(u8 *)(unit + offset + 0x24) >> 4);
    else
        level = (s8)(*(u8 *)(unit + offset + 0x24) & 15);
    return (s8)level;
}

static inline void P4CalcSetLevel(u8 *unit, u8 index, s8 level)
{
    u16 offset;
    u8 *ptr;
    if ((s32)index >= 24)
        func_0046d730(D_00635938, 0x45E);
    if (level < 0)
        func_0046d730(D_00635938, 0x45F);
    offset = index >> 1;
    if (index & 1) {
        ptr = unit + offset;
        ptr[0x24] = (ptr[0x24] & 15) | ((level & 15) << 4);
    } else {
        ptr = unit + offset;
        ptr[0x24] = (ptr[0x24] & 240) | (level & 15);
    }
}

/* measured: 524B/528B, only one zero-tail word. Signed-byte boundaries and
   per-branch setter addresses preserve the saved offset and retail merges. */
// FUN_00235110
void func_00235110(u8 *unit)
{
    s32 checked;
    u32 index;
    s8 active;
    s8 level;
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            func_0046d730(D_00635938, 0x4C1);
        if (checked < 16)
            active = func_002332a0(unit, index % 256U);
        else {
            u8 result = (*(u32 *)(unit + 0x14) & (1U << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel(unit, index);
        if (active != 0 && level < 15)
            P4CalcSetLevel(unit, index, level + 1);
    }
}

#pragma push
/* measured: b210 owner profile, 504B/512B, no differing emitted words;
   hoist the signed threshold comparison out of the loop. */
#pragma opt_loop_invariants on
// FUN_00235320
s64 func_00235320(u8 *unit)
{
    s32 checked;
    s8 threshold;
    u32 index;
    s8 active;
    s8 level;
    threshold = 3;
    if (*(u16 *)unit & 4) {
        if (*(u16 *)(unit + 2) >= 0x150)
            func_0046d730(D_00635938, 0x6D8);
        if (*(u16 *)(iGpffffb3c4 + *(u16 *)(unit + 2) * 0x3C) & 0x1000)
            threshold *= 2;
    }
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            func_0046d730(D_00635938, 0x4C1);
        if (checked < 16)
            /* Keep the independently narrowed getter argument. */
            active = func_002332a0(unit, index % 256U);
        else {
            u8 result = (*(u32 *)(unit + 0x14) & (1 << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel(unit, index);
        if (active != 0 && level >= threshold)
            return (s8)index;
    }
    return -1;
}
#pragma pop
/* Equipment queries shared by damage, hit and critical calculations. */
static inline u16 DCHitEquipmentCount(u8 *unit, s32 property)
{
    if (*(u16 *)unit & 4) {
        return 0;
    }
    return func_00232880(*(u16 *)(unit + 2), property);
}

static inline s32 DC411HasEquipmentProperty(u8 *unit, s32 property)
{
    u16 character;

    if (*(u16 *)unit & 4) {
        return 0;
    }
    character = *(u16 *)(unit + 2);
    if ((s32)character >= 0xB) {
        func_0046d730(D_00635938, 0x23B);
    }
    if ((func_001069d0(func_00106cd0((s16)character, 0)) & 0xFFFF) == property) {
        return 1;
    }
    if ((func_001069d0(func_00106cd0((s16)character, 1)) & 0xFFFF) == property) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_loop_invariants on
static inline u16 DCDamageAccessoryProperty(u8 *unit)
{
    s16 character;
    if (*(u16 *)unit & 4) {
        return 0;
    }
    character = *(s16 *)(unit + 2);
    if (character >= 11) {
        func_0046d730(D_00635938, 0x291);
    }
    return func_001069d0(func_00106cd0(character, 2)) & 0xFFFF;
}

static inline f32 DCDamageAccessoryFraction(u8 *unit)
{
    extern u16 func_00106a00(s16 item);
    s16 character;
    s32 percent;
    if (*(u16 *)unit & 4) {
        return 0.0f;
    }
    character = *(s16 *)(unit + 2);
    if (character >= 11) {
        func_0046d730(D_00635938, 0x2A7);
    }
    percent = (s16)func_00106a00(func_00106cd0(character, 2));
    if (percent < 0 || percent > 100) {
        func_0046d730(D_00635938, 0x2AB);
    }
    return (f32)percent / 100.0f;
}

static inline s32 DCDamageAddBonus(s32 base, s16 bonus)
{
    return base + bonus;
}

static inline u8 DCDamageSkillKind(u16 skill)
{
    u8 *table = iGpffffb3b8;
    return table[(u32)skill * 0x28 + 2];
}

/* measured: b210 emits all 12176 retail bytes, with all code
 * relocations resolved, and the 17-entry effect table at 00747bc0. The native
 * identifier-list formals keep the caller's promoted integer interface.
 * Unsigned channel dispatch preserves independent signed call conversions;
 * declaring result values after the work value preserves their lifetimes.
 * See docs/probe_archive/DC_worker2_20260920_damage_recovery.md. */
// FUN_00235520
s32 func_00235520(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
u16 arg0;
u8 *arg1;
u8 *arg2;
u16 arg3;
u16 arg4;
u16 arg5;
s32 arg6;
u8 arg7;
{
    extern s32 func_0023d6e0(s16 element);
    extern f32 iGpffff8170;
    extern f32 fGpffff82c0;
    extern f32 fGpffff82c4;
    extern f32 fGpffff82c8;
    extern f32 fGpffff80bc;
    extern f32 fGpffff82cc;
    extern f32 fGpffff811c;
    extern f32 fGpffff809c;
    s32 checkedSkill;
    f32 attack;
    f32 defense;
    f32 status;
    f32 passive;
    f32 elemental;
    u16 current;
    u16 maximum;
    s32 fixed;
    s16 power;
    u16 effect;
    s16 bonus;
    s32 rawElement;
    s32 element;
    s32 elementMask;
    s32 offset;
    s32 work;
    s32 healing;
    s32 damage;
    u32 targetStatus;
    u8 *record;

    checkedSkill = (u16)arg0;
    if (checkedSkill < 0 || checkedSkill >= 0x240) {
        func_0046d730(D_00635938, 0x711);
    }
    if (checkedSkill >= 0x1B8) {
        func_0046d730(D_00635938, 0x712);
    }
    attack = 1.0f;
    defense = 1.0f;
    status = 1.0f;
    passive = 1.0f;
    healing = 0;
    damage = 0;
    current = 0;
    maximum = 0;
    fixed = 1;
    switch ((u32)arg7) {
    case 1:
        record = (u8 *)PTDatCalcOffsetAdd(((u32)arg0 % 0x10000U) * 0x28, (u32)iGpffffb3b8);
        power = *(s16 *)(record + 0x12);
        effect = record[0x11];
        bonus = 0;
        current = *(u16 *)(arg2 + 8);
        maximum = func_00231f80((DatUnit *)arg2);
        break;
    case 2:
        record = (u8 *)PTDatCalcOffsetAdd(((u32)arg0 % 0x10000U) * 0x28, (u32)iGpffffb3b8);
        power = *(s16 *)(record + 0x16);
        effect = record[0x14];
        bonus = 0;
        current = *(u16 *)(arg2 + 10);
        maximum = func_00232290((DatUnit *)arg2);
        break;
    default:
        func_0046d730(D_00635938, 0x731);
        break;
    }
    switch (effect) {
    case 0:
        break;
    case 5:
        healing = power + bonus;
        break;
    case 15:
        healing = power;
        if (healing == 0) {
            func_0046d730(D_00635938, 0x17);
        }
        healing = DCDamageAddBonus((s32)(func_003b7060() % healing), bonus);
        break;
    case 9:
        healing = DCDamageAddBonus((s32)(current * power / 100), bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 11:
        healing = DCDamageAddBonus((s32)(maximum * power / 100), bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 2:
        switch (DCDamageSkillKind(arg0)) {
        case 1:
            healing = func_00244f60(1, (u16 *)arg1, (u16 *)arg2, arg0, arg7);
            break;
        case 2:
            healing = func_00244f60(3, (u16 *)arg1, (u16 *)arg2, arg0, arg7);
            break;
        default:
            func_0046d730(D_00635938, 0x75E);
            break;
        }
        healing += bonus;
        if (healing <= 0) {
            healing = 1;
        }
        fixed = 0;
        break;
    case 7:
        healing = 50;
        healing += bonus;
        if (healing <= 0) {
            healing = 1;
        }
        fixed = 0;
        break;
    case 4:
    case 13:
        damage = power + bonus;
        if (effect == 13 && current < damage) {
            damage = current;
        }
        break;
    case 8:
        damage = DCDamageAddBonus((s32)(current * power / 100), bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 10:
        damage = DCDamageAddBonus((s32)(maximum * power / 100), bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 1:
    case 12:
    case 14:
        switch (DCDamageSkillKind(arg0)) {
        case 1:
            damage = func_00244f60(1, (u16 *)arg1, (u16 *)arg2, arg0, arg7);
            break;
        case 2:
            damage = func_00244f60(2, (u16 *)arg1, (u16 *)arg2, arg0, arg7);
            break;
        default:
            func_0046d730(D_00635938, 0x7A7);
            break;
        }
        damage += bonus;
        switch (effect) {
        case 12:
        case 13:
            if (current < damage) {
                damage = current;
            }
            break;
        }
        if (effect == 14 && arg3 > 1) {
            damage /= arg3;
        }
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    case 6:
        damage = 50;
        damage += bonus;
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    case 3:
        if (power + bonus < current) {
            damage = current - (power + bonus);
        }
        break;
    case 16:
        damage = DCDamageAddBonus((s32)func_00244f60(9, (u16 *)arg1, (u16 *)arg2, arg0, arg7), bonus);
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    default:
        func_0046d730(D_00635938, 0x7DE);
        break;
    }
    if (fixed == 0 && damage > 0 && !(arg6 & 1)) {
        rawElement = (s16)func_0023d8e0(arg1, arg0);
        elementMask = func_0023d6e0(rawElement);
        offset = ((u32)arg0 % 0x10000U) * 0x28;
        switch (iGpffffb3b8[offset + 2]) {
        case 1:
            if (effect != 16) {
                attack = func_00233bc0(arg1, 0, arg0);
            }
            defense = func_00233bc0(arg2, 3, arg0);
            if (effect != 16) {
                *(u32 *)(arg1 + 0x18) |= 0x40000;
            }
            break;
        case 2:
            if (effect != 16) {
                attack = func_00233bc0(arg1, 1, arg0);
            }
            defense = func_00233bc0(arg2, 3, arg0);
            if (effect != 16) {
                *(u32 *)(arg1 + 0x18) |= 0x80000;
            }
            break;
        default:
            func_0046d730(D_00635938, 0x803);
            break;
        }
        element = (s16)rawElement;
        switch (element) {
        case 1:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty(arg1) & 0xFFFF) == 0xBD) {
                elemental *= 1.0f + DCDamageAccessoryFraction(arg1);
            }
            if (PTDatCalcHasSkill(arg1, 0x1E7) || (DCHitEquipmentCount(arg1, 0x44) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill(arg1, 0x1E8)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (func_00106330(0x1435)) {
                if (func_00106330(0x15C5)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 2:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty(arg1) & 0xFFFF) == 0xBE) {
                elemental *= 1.0f + DCDamageAccessoryFraction(arg1);
            }
            if (PTDatCalcHasSkill(arg1, 0x1E9) || (DCHitEquipmentCount(arg1, 0x45) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill(arg1, 0x1EA)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (func_00106330(0x1435)) {
                if (func_00106330(0x15C6)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 3:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty(arg1) & 0xFFFF) == 0xC0) {
                elemental *= 1.0f + DCDamageAccessoryFraction(arg1);
            }
            if (PTDatCalcHasSkill(arg1, 0x1EB) || (DCHitEquipmentCount(arg1, 0x46) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill(arg1, 0x1EC)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (func_00106330(0x1435)) {
                if (func_00106330(0x15C8)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 4:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty(arg1) & 0xFFFF) == 0xBF) {
                elemental *= 1.0f + DCDamageAccessoryFraction(arg1);
            }
            if (PTDatCalcHasSkill(arg1, 0x1ED) || (DCHitEquipmentCount(arg1, 0x47) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill(arg1, 0x1EE)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (func_00106330(0x1435)) {
                if (func_00106330(0x15C7)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        }
        if (PTDatCalcHasSkill(arg2, 0x209)) {
            passive *= 0.5f;
        }
        if (func_00106330(0x1011)) {
            if (*(u16 *)arg1 & 4) {
                attack *= 1.5f;
            }
        } else if (func_00106330(0x1010) && (*(u16 *)arg1 & 4)) {
            attack *= iGpffff8170;
        }
        if (arg5 == 2) {
            if (!(*(u16 *)arg1 & 4)) {
                attack *= fGpffff82c8;
            } else {
                attack *= fGpffff80bc;
            }
        }
        if (func_00243e30((u16 *)arg2)) {
            defense *= fGpffff82cc;
        }
        targetStatus = *(u32 *)(arg2 + 0xC);
        if ((u8)((targetStatus & 0x100000) != 0)) {
            status *= 1.25f;
        }
        if ((elementMask & 2) && (u8)((*(u32 *)(arg1 + 0xC) & 0x20) != 0)) {
            status *= 0.5f;
        }
        if ((u8)((*(u32 *)(arg1 + 0xC) & 2) != 0)) {
            status *= 2.0f;
        }
        if ((u8)((targetStatus & 0x40) != 0)) {
            status *= 1.5f;
        } else if ((u8)((targetStatus & 2) != 0)) {
            status *= 2.0f;
        }
        if (*(u16 *)arg1 & 4) {
            if (*(u16 *)(arg1 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0x8C0);
            }
            if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg1 + 2) * 0x3C) & 0x20) {
                attack *= 0.75f;
            }
        }
        switch (iGpffffb3b8[offset + 0x24]) {
        case 3:
            if ((u8)((*(u32 *)(arg2 + 0xC) & 0x100000) != 0)) {
                attack *= 2.0f;
            }
            break;
        }
        if (!(*(u16 *)arg2 & 4)) {
            switch (element) {
            case 0:
                if (DC411HasEquipmentProperty(arg2, 0x5F)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x60)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x61)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
            case 2:
            case 3:
            case 4:
                if (DC411HasEquipmentProperty(arg2, 0x6E)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x6F)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x70)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
                if ((DCDamageAccessoryProperty(arg2) & 0xFFFF) == 0xC1) {
                    attack *= 1.0f - DCDamageAccessoryFraction(arg2);
                }
                if (DC411HasEquipmentProperty(arg2, 0x62)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x63)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x64)) {
                    attack *= fGpffff809c;
                }
                break;
            case 2:
                if ((DCDamageAccessoryProperty(arg2) & 0xFFFF) == 0xC2) {
                    attack *= 1.0f - DCDamageAccessoryFraction(arg2);
                }
                if (DC411HasEquipmentProperty(arg2, 0x65)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x66)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x67)) {
                    attack *= fGpffff809c;
                }
                break;
            case 3:
                if ((DCDamageAccessoryProperty(arg2) & 0xFFFF) == 0xC4) {
                    attack *= 1.0f - DCDamageAccessoryFraction(arg2);
                }
                if (DC411HasEquipmentProperty(arg2, 0x6B)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x6C)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x6D)) {
                    attack *= fGpffff809c;
                }
                break;
            case 4:
                if ((DCDamageAccessoryProperty(arg2) & 0xFFFF) == 0xC3) {
                    attack *= 1.0f - DCDamageAccessoryFraction(arg2);
                }
                if (DC411HasEquipmentProperty(arg2, 0x68)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(arg2, 0x69)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(arg2, 0x6A)) {
                    attack *= fGpffff809c;
                }
                break;
            }
        }
        work = (s32)(passive * (status * (defense * ((f32)damage * attack))));
        if (arg5 == 16) {
            damage = 500;
        } else {
            if (work > 31000) {
                work = 31000;
            } else if (work <= 0) {
                work = 1;
            }
            damage = (u32)(work * (func_003b7060() % 11U + 95U)) / 100U;
        }
        if (damage <= 0) {
            damage = 1;
        }
    }
    if (fixed == 0 && healing > 0 && !(arg6 & 1)) {
        if (PTDatCalcHasSkill(arg1, 0x20E)) {
            passive *= 1.5f;
        }
        work = (s32)(passive * (status * (defense * ((f32)healing * attack))));
        if (work > 31000) {
            work = 31000;
        } else if (work <= 0) {
            work = 1;
        }
        healing = (u32)(work * (func_003b7060() % 11U + 95U)) / 100U;
        if (healing <= 0) {
            healing = 1;
        }
    }
    if (arg4 == 0x400 && damage > 0) {
        healing = damage;
        damage = 0;
    }
    switch (arg4) {
    case 0x100:
    case 2:
    case 4:
        healing = 0;
        damage = 0;
        break;
    }
    if (damage > 0) {
        healing = -damage;
    }
    return healing;
}
#pragma pop


// FUN_002384B0
s32 func_002384b0(s32 arg0, u8 *arg1, s32 arg2)
{
    /* measured: retail compiled this caller against the s32-returning
       prototype other units use (see datScript.c), so the u8 return of
       func_00232c70 is not re-masked here; a block-scope declaration
       reproduces that split inside the merged unit. */
    extern u32 func_00232c70(u8 *arg0, s32 arg1);
    f32 var_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f21;
    f32 var_f20;
    s32 temp;
    u32 temp_2;
    s32 temp_2_2;
    u32 temp_2_3;
    s32 temp_2_5;
    u32 temp_2_6;
    u16 temp_2_7;
    u16 temp_4;
    u16 temp_4_2;
    u32 temp_hi;
    u8 var_16;
    u8 var_18;
    u8 *temp_2_4;

    if (iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x24] != 6) {
        return 0;
    }
    if (arg1 != (u8 *)arg2) {
        func_0046d730(D_00635938, 0x9F9);
    }
    if (!(*(u16 *)arg1 & 4)) {
        temp_2 = func_00105ed0();
        var_f1 = (f32)temp_2;
        var_f21 = var_f1 / 20.0f;
        if ((*(u16 *)arg1 & 4) || (temp_4 = *(u16 *)(arg1 + 2), temp_4 == 1)) {
            var_16 = *(u8 *)(arg1 + 6);
        } else {
            temp_2_2 = (s32)func_0010a900(temp_4);
            if (temp_2_2 == 0) {
                func_0046d730(D_00635938, 0x58);
            }
            var_16 = func_00109390(temp_2_2);
        }
        if ((var_16 & 0xFF) <= 0) {
            func_0046d730(D_00635938, 0x5C);
        }
        var_f1_2 = (f32)var_16;
        var_f20 = 4.0f + (var_f1_2 / 5.0f);
        temp_2_3 = func_00232c70(arg1, 4);
        var_f0 = (f32)temp_2_3;
        var_f20 = var_f21 / (var_f0 / var_f20);
    } else {
        temp_2_4 = func_00105510(1);
        if ((*(u16 *)temp_2_4 & 4) || (temp_4_2 = *(u16 *)(temp_2_4 + 2), temp_4_2 == 1)) {
            var_18 = *(u8 *)(temp_2_4 + 6);
        } else {
            temp_2_5 = (s32)func_0010a900(temp_4_2);
            if (temp_2_5 == 0) {
                func_0046d730(D_00635938, 0x58);
            }
            var_18 = func_00109390(temp_2_5);
        }
        if ((var_18 & 0xFF) <= 0) {
            func_0046d730(D_00635938, 0x5C);
        }
        var_f1_3 = (f32)var_18;
        var_f20 = 4.0f + (var_f1_3 / 5.0f);
        temp_2_6 = func_00232c70(temp_2_4, 4);
        var_f0_2 = (f32)temp_2_6;
        var_f20 = var_f0_2 / var_f20;
        var_f0_3 = (f32)func_002439c0(arg1);
        var_f20 = var_f20 * var_f0_3;
    }
    temp_hi = func_003b7060() % 21U;
    var_f0_4 = (f32)temp_hi;
    var_2 = var_f20 * (((100.0f + var_f0_4) - 10.0f) / 100.0f);
    temp = (s32)var_2;
    if (temp == 0) {
        temp = 1;
    }
    if (*(u16 *)arg1 & 4) {
        return temp;
    }
    return -temp;
}

/* C89 promotes the u16 body parameter to the explicit s32 interface above.
 * Conversion belongs to this callee; the five dynamic callers pass the full
 * word. Unsigned table indexing keeps its mask distinct from validation.
 * measured: b210 -O2, 3728/3728 bytes, with both real u16 query consumers.
 * The bounded choices array and skill/equipment scans preserve P4 status bits. */
// FUN_00238940
#pragma push
#pragma opt_loop_invariants on
s32 func_00238940(skillId, source, target, options)
u16 skillId;
u8 *source;
u8 *target;
s32 options;
{
    u16 choices[24];
    s32 offset;
    u8 *entry;
    u8 mode;
    u8 kind;
    u32 statuses;
    s32 success;
    s32 index;
    s32 count;
    u32 choiceCount;
    s32 resistance;
    u32 percentage;
    f32 multiplier;
    f32 percent;
    f32 chance;
    s32 death;
    s32 rate;
    s32 element;
    u8 active;
    s16 message;
    extern s32 func_00243e30(u16 *unit);
    extern s32 func_0023d740(s32 skill, s32 mask);

    if ((skillId & 0xFFFF) >= 0x240) {
        func_0046d730(D_00635938, 0xA30);
    }
    offset = (u32)(u16)skillId * 0x28;
    entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
    if (entry[0x24] == 13) {
        return 0x80000;
    }
    multiplier = 1.0f;
    success = 0;
    statuses = *(u32 *)(entry + 0x1C) & 0xFFFFFFU;
    if (entry[0x18] == 3) {
        count = 0;
        index = 0;
        while ((index & 0xFFFF) < 24) {
            if (statuses & (1U << (index & 0xFFFF))) {
                choices[count & 0xFFFF] = index;
                count = (count + 1) & 0xFFFF;
            }
            index = (index + 1) & 0xFFFF;
        }
        choiceCount = count & 0xFFFF;
        if (choiceCount == 0) {
            func_0046d730(D_00635938, 0x17);
        }
        statuses = 1U << choices[func_003b7060() % choiceCount];
    }
    if (statuses != 0 &&
        ((entry = iGpffffb3b8, mode = *(u8 *)PTDatCalcOffsetAdd((u32)entry + 0x18U, (u32)offset), mode == 1) || mode == 3)) {
        switch (entry[offset + 0x24]) {
        case 14: {
            if ((u8)(target[0xC] != 0)) {
                goto return_status_0;
            }
            goto return_zero_0;
return_status_0:
            return (s32)statuses;
return_zero_0:
            return 0;
        }
        default:
            break;
        }
        if (func_00243e30((u16 *)target)) {
            return 0;
        }
        kind = iGpffffb3b8[offset + 0x24];
        switch (kind) {
        case 1:
            if ((u8)((*(u32 *)(target + 0xC) & 4) != 0)) {
                return (s32)statuses;
            }
            break;
        case 7:
            if (*(u16 *)target & 0x1000) {
                statuses = 0;
            }
            return (s32)statuses;
        case 8:
            switch (*(u16 *)target & 0x1000) {
            case 0:
                statuses = 0;
                break;
            default:
                break;
            }
            return (s32)statuses;
        case 9:
            if ((u8)((*(u32 *)(target + 0xC) & 1) != 0)) {
                goto return_status_1;
            }
            goto return_zero_1;
return_status_1:
            return (s32)statuses;
return_zero_1:
            return 0;
        default:
            break;
        }
        resistance = func_0023a6b0(target, (s16)func_0023d740((s16)skillId, (s32)statuses));
        if (resistance & 0x27000000) {
            return 0;
        }
        if (statuses & 0x100000) {
            if ((u8)((*(u32 *)(target + 0xC) & 0x100000) != 0)) {
                return 0;
            }
            if (*(u16 *)target & 8) {
                return 0;
            }
        }
        percentage = resistance & 0xFFFF;
        percent = (f32)percentage;
        multiplier = multiplier * (percent / 100.0f);
        if (!(options & 1)) {
            death = statuses & 0x80000;
            if (death == 0 && func_002332a0(target, 7) > 0) {
                multiplier *= 2.0f;
            }
            element = (s16)func_0023d8e0(source, skillId);
            switch (element) {
            case 9:
                if (PTDatCalcHasSkill(source, 0x217)) multiplier *= 1.25f;
                break;
            case 8:
                if (PTDatCalcHasSkill(source, 0x216)) multiplier *= 1.25f;
                break;
            case 10:
                if (PTDatCalcHasSkill(source, 0x21A)) multiplier *= 1.25f;
                break;
            case 6:
                if (PTDatCalcHasSkill(source, 0x21F)) multiplier *= 1.25f;
                break;
            case 7:
                if (PTDatCalcHasSkill(source, 0x220)) multiplier *= 1.25f;
                break;
            case 13:
                if (PTDatCalcHasSkill(source, 0x218)) multiplier *= 1.25f;
                break;
            case 15:
                if (PTDatCalcHasSkill(source, 0x219)) multiplier *= 1.25f;
                break;
            case 11:
                if (PTDatCalcHasSkill(source, 0x21B)) multiplier *= 1.25f;
                break;
            case 14:
                if (PTDatCalcHasSkill(source, 0x21D)) multiplier *= 1.25f;
                break;
            }
            if (death == 0 && PTDatCalcHasSkill(source, 0x21E)) {
                multiplier *= 1.25f;
            }
        }
    }
    if (statuses == 0) {
        return 0;
    }
    if ((s32)iGpffffb3b8[offset + 0x19] >= 100) {
        success = 1;
    } else {
        chance = (f32)func_00244f60(10, (u16 *)(source), (u16 *)(target), skillId, (s32)statuses);
        chance = chance * multiplier;
        rate = (s32)chance;
        if (rate > 99) {
            rate = 99;
        } else if (rate < 0) {
            rate = 0;
        }
        if ((s32)(func_003b7060() % 100U) < rate) {
            success = 1;
        }
    }
    if (success != 0 && (statuses & 0x80000) != 0 &&
        (s8)(active = (*(u32 *)(target + 0x14) & 0x800000) != 0) > 0) {
        statuses &= ~0x80000U;
        if (*(u16 *)target & 4) {
            message = 0x79;
        } else {
            message = 0x78;
        }
        *(s16 *)(target + 0x2C) = message;
        *(u32 *)(target + 0x18) |= 0x800000;
    }
    switch (success) {
    case 0:
        statuses = 0;
        break;
    default:
        break;
    }
    return (s32)statuses;
}
#pragma pop
// FUN_002397D0
u32 func_002397d0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s16 temp_17;
    s32 temp_2;
    s32 var_2_2;
    u8 temp_3;
    u32 var_2;
    s32 off;
    u8 *temp_4;

    if ((u16)arg0 >= 0x1B8) {
        func_0046d730(D_00635938, 0xB1D);
    }
    off = (arg0 & 0xFFFF) * 0x28;
    temp_4 = (u8 *)(off + (s32)iGpffffb3b8);
    if (temp_4[0x24] == 0xD) {
        return 0x80000U;
    }
    if ((arg3 & 0xFFFF) != 1) {
        return 0U;
    }
    temp_3 = temp_4[0x18];
    if ((temp_3 != 1) && (temp_3 != 3)) {
        if ((func_0023df70(arg0) != 0) &&
            (((u64)((s64)(*(s32 *)(arg2 + 0xC)) << 0x2C) >> 0x2C) == 0)) {
            if (*(u16 *)arg1 & 4) {
                var_2_2 = 0;
            } else {
                temp_17 = *(s16 *)(arg1 + 2);
                if (temp_17 >= 0xB) {
                    func_0046d730(D_00635938, 0x291);
                }
                var_2_2 = func_001069d0(func_00106cd0(temp_17, 0)) & 0xFFFF;
            }
            temp_2 = var_2_2 & 0xFFFF;
            switch (temp_2) {
            case 0x24:
                return func_00238940(0x190, arg1, arg2, arg5);
            case 0x25:
                return func_00238940(0x191, arg1, arg2, arg5);
            case 0x26:
                return func_00238940(0x192, arg1, arg2, arg5);
            case 0x27:
                return func_00238940(0x193, arg1, arg2, arg5);
            case 0x28:
                return func_00238940(0x194, arg1, arg2, arg5);
            case 0x29:
                return func_00238940(0x195, arg1, arg2, arg5);
            case 0x2A:
                return func_00238940(0x196, arg1, arg2, arg5);
            case 0x2B:
                return func_00238940(0x197, arg1, arg2, arg5);
            case 0x2C:
                return func_00238940(0x198, arg1, arg2, arg5);
            case 0x2D:
                return func_00238940(0x199, arg1, arg2, arg5);
            case 0x2E:
                return func_00238940(0x19A, arg1, arg2, arg5);
            case 0x2F:
                return func_00238940(0x19B, arg1, arg2, arg5);
            case 0x30:
                return func_00238940(0x19C, arg1, arg2, arg5);
            case 0x31:
                return func_00238940(0x19D, arg1, arg2, arg5);
            case 0x32:
                return func_00238940(0x19E, arg1, arg2, arg5);
            case 0x33:
                return func_00238940(0x19F, arg1, arg2, arg5);
            case 0x34:
                return func_00238940(0x1A0, arg1, arg2, arg5);
            case 0x35:
                return func_00238940(0x1A1, arg1, arg2, arg5);
            case 0x36:
                return func_00238940(0x1A2, arg1, arg2, arg5);
            case 0x37:
                return func_00238940(0x1A3, arg1, arg2, arg5);
            case 0x38:
                return func_00238940(0x1A4, arg1, arg2, arg5);
            case 0x39:
                return func_00238940(0x1A5, arg1, arg2, arg5);
            case 0x3A:
                return func_00238940(0x1A6, arg1, arg2, arg5);
            case 0x3B:
                return func_00238940(0x1A7, arg1, arg2, arg5);
            case 0x5C:
                return func_00238940(0x1A8, arg1, arg2, arg5);
            case 0x5D:
                return func_00238940(0x1A9, arg1, arg2, arg5);
            case 0x5E:
                return func_00238940(0x1AA, arg1, arg2, arg5);
            }
            goto zero;
        }
zero:
        var_2 = 0;
    } else {
        var_2 = func_00238940(arg0, arg1, arg2, arg5);
        if ((((u64)((s64)(*(s32 *)(arg2 + 0xC)) << 0x2C) >> 0x2C) != 0) && !(var_2 & 0x180000)) {
            var_2 = 0;
        }
    }
    return var_2;
}

// FUN_00239E40
s32 func_00239e40(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5)
{
    u8 *temp_4;
    s32 off;

    if ((u16)arg0 >= 0x1B8) {
        func_0046d730(D_00635938, 0xB94);
    }
    if ((arg3 & 0xFFFF) != 1) {
        return 0;
    }
    off = (arg0 & 0xFFFF) * 0x28;
    temp_4 = (u8 *)(off + (s32)iGpffffb3b8);
    if (temp_4[0x18] != 2) {
        return 0;
    }
    if ((s32)temp_4[0x19] < 0x64) {
        func_0046d730(D_00635938, 0xB9F);
    }
    return func_00238940(arg0, arg1, arg2, arg5);
}

// FUN_00239F50
s32 func_00239f50(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
    s32 temp_17;
    u32 temp_21;
    s32 result;

    if (arg1 != NULL && arg2 != NULL) {
        temp_17 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 1);
        arg3 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 2);
        temp_21 = func_002397d0(arg0, arg1, arg2, 1, 1, 0);
        if ((u16)arg0 >= 0x1B8) {
            func_0046d730(D_00635938, 0xB94);
        }
        if (iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x18] != 2) {
            result = 0;
        } else {
            if ((s32)iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                func_0046d730(D_00635938, 0xB9F);
            }
            result = func_00238940(arg0, arg1, arg2, 0);
        }
        if (temp_17 == 0 && arg3 == 0 && temp_21 == 0 && result == 0) {
            return 0;
        }
        if ((((u64)temp_21 << 0x2C) >> 0x2C) != 0) {
            *(u32 *)(arg2 + 0xC) = (*(u32 *)(arg2 + 0xC) & 0xFFF00000) | (temp_21 & 0xFFFFF);
        }
        *(u32 *)(arg2 + 0xC) |= temp_21 & 0xFFF00000;
        *(u32 *)(arg2 + 0xC) &= ~result;
        if (arg3 != 0) {
            arg3 = (u32)*(u16 *)(arg2 + 0xA) + (u32)arg3;
            if (arg3 < 0) {
                arg3 = 0;
            }
            result = func_00232290((DatUnit *)arg2) & 0xFFFF;
            if (result < arg3) {
                arg3 = result;
            }
            *(u16 *)(arg2 + 0xA) = arg3;
        }
        if (temp_17 != 0) {
            arg3 = *(u16 *)(arg2 + 0x8) + temp_17;
            if (arg3 < 0) {
                arg3 = 0;
            }
            result = func_00231f80((DatUnit *)arg2) & 0xFFFF;
            if (result < arg3) {
                arg3 = result;
            }
            *(u16 *)(arg2 + 0x8) = arg3;
            if (*(u16 *)(arg2 + 0x8) == 0) {
                *(u32 *)(arg2 + 0xC) = (*(u32 *)(arg2 + 0xC) & 0xFFF00000) | 0x80000;
            }
        }
    }
    return 1;
}





// FUN_0023A1E0
s32 func_0023a1e0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3)
{
    s32 temp_21;
    s32 temp_19;
    s32 temp_22;
    s32 flags;
    s32 result;
    s32 status;
    s32 high;
    u32 hit;
    u16 temp_17;
    u16 temp_17_2;

    flags = 0;
    if (arg1 != NULL && arg2 != NULL) {
        temp_21 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 1);
        temp_19 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 2);
        temp_22 = func_002397d0(arg0, arg1, arg2, 1, 1, 0);
        if ((u16)arg0 >= 0x1B8) {
            func_0046d730(D_00635938, 0xB94);
        }
        if (iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x18] != 2) {
            result = 0;
        } else {
            if ((s32)iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                func_0046d730(D_00635938, 0xB9F);
            }
            result = func_00238940(arg0, arg1, arg2, 0);
        }
        *(s32 *)(arg1 + 0x18) = 0;
        *(s32 *)(arg2 + 0x18) = 0;
        status = *(s32 *)(arg2 + 0xC);
        high = ((status & 0x80000) != 0);
        if (temp_21 == 0 && temp_19 == 0 && temp_22 == 0 && result == 0) {
            flags |= 0xFFFF;
        }
        if (result == 0) {
            goto check_status;
        }
        hit = ((status & result) != 0);
        if (hit != 0) {
            goto return_zero_status;
        }
        flags |= 4;
        goto check_result_high;
return_zero_status:
        return 0;
check_result_high:
        if ((result & 0x80000) == 0) {
            goto check_status;
        }
        if ((flags & 4) == 0) {
            goto check_status;
        }
        goto return_flags_status;
return_flags_status:
        return flags;
check_status:
        if (high == 0) {
            if (temp_19 > 0) {
                temp_17 = *(u16 *)(arg2 + 0xA);
                if ((s32)(func_00232290((DatUnit *)arg2) & 0xFFFF) > (s32)temp_17) {
                    goto return_zero_sp;
                }
                flags |= 2;
                goto check_hp;
return_zero_sp:
                return 0;
            }
check_hp:
            if (temp_21 > 0) {
                temp_17_2 = *(u16 *)(arg2 + 0x8);
                if ((s32)(func_00231f80((DatUnit *)arg2) & 0xFFFF) > (s32)temp_17_2) {
                    goto return_zero_hp;
                }
                flags |= 1;
                goto done;
return_zero_hp:
                return 0;
            }
            goto done;
        }
        return 0xFFFF;
    }
done:
    return flags;
}

// FUN_0023A490
s32 func_0023a490(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 *arg4, s32 *arg5, s32 *arg6)
{
    s32 var_2;

    if (arg1 != NULL && arg2 != NULL) {
        if (arg4 != NULL) {
            *arg4 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 1);
        }
        if (arg5 != NULL) {
            *arg5 = func_00235520(arg0, arg1, arg2, 1, 1, 1, arg3, 2);
        }
        if (arg6 != NULL) {
            if ((u16)arg0 >= 0x1B8) {
                func_0046d730(D_00635938, 0xB94);
            }
            if (iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x18] != 2) {
                var_2 = 0;
            } else {
                if ((s32)iGpffffb3b8[(arg0 & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                    func_0046d730(D_00635938, 0xB9F);
                }
                var_2 = func_00238940(arg0, arg1, arg2, 0);
            }
            *arg6 = var_2;
        }
        *(s32 *)(arg1 + 0x18) = 0;
        *(s32 *)(arg2 + 0x18) = 0;
        return 1;
    }
    return 0;
}

// FUN_0023A620
s32 func_0023a620(s32 arg0, u16 arg1)
{
    s32 temp_3 = arg1 & 0xFFFF;
    s32 var_2 = ((u32)(temp_3 & 0xFF00) << 0x10) | ((temp_3 & 0xFFFF00FF) * 5);
    if (!(var_2 & 0xFFFF)) {
        if (var_2 & 0x08000000) {
            var_2 |= 0x7D;
        } else if (var_2 & 0x27000000) {
            var_2 |= 0x64;
        } else if (var_2 & 0x10000000) {
            var_2 |= 0x32;
        }
    }
    return var_2;
}
/* Base persona resistance and unit-type query. */
extern u8 *iGpffffb3c8;
extern u32 func_00109870(u16 arg0, s32 arg1);
extern s32 func_00243e30(u16 *arg0);

#pragma push
#pragma opt_loop_invariants on
// FUN_0023A6B0
s32 func_0023a6b0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 found;
    u32 val;
    u32 acc;
    s32 hasFlag;
    s32 b1;
    s32 b4;
    u16 raw;
    u32 high;
    u32 low;

    acc = 0;
    b4 = 0;
    b1 = 0;
    hasFlag = 0;
    temp_16 = (s16)arg1;
    switch (temp_16) {
    case -1:
        return 0;
    case 0x10:
    case 0x11:
    case 0x12:
        return 100;
    }
    if (arg0 == 0) {
        func_0046d730(D_00635938, 0xCC1);
    }
    if (temp_16 >= 0x13 || temp_16 < 0) {
        func_0046d730(D_00635938, 0xCC2);
    }
    if ((*(u16 *)arg0 & 4) == 0) {
        val = func_00109870(*(u16 *)(arg0 + 2), arg1 & 0xFFFF);
    } else {
        if (*(u16 *)(arg0 + 4) >= 0x150) {
            func_0046d730(D_00635938, 0xCCD);
        }
        raw = *(u16 *)(iGpffffb3c8 + *(u16 *)(arg0 + 4) * 0x20 + temp_16 * 2);
        high = (u32)(raw & 0xFF00) << 16;
        low = (raw & 0xFFFF00FF) * 5;
        val = high | low;
        if ((val & 0xFFFF) == 0) {
            if ((val & 0x8000000) != 0) {
                val |= 0x7D;
            } else if ((val & 0x27000000) != 0) {
                val |= 100;
            } else if ((val & 0x10000000) != 0) {
                val |= 0x32;
            }
        }
    }
    if (func_00243e30((u16 *)arg0) != 0) {
        hasFlag = 1;
    }
    switch (temp_16) {
    case 0:
        found = PTDatCalcHasSkill(arg0, 0x1B8);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1B9);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1BA);
        if (found != 0) {
            acc |= 0x2000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1BB);
        if (found != 0) {
            acc |= 0x4000000;
        }
        break;
    }
    switch (temp_16) {
    case 1:
        found = PTDatCalcHasSkill(arg0, 0x1BC);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1BD);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1BE);
        if (found != 0) {
            acc |= 0x2000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1BF);
        if (found != 0) {
            acc |= 0x4000000;
        }
        if (func_002332a0(arg0, 8) > 0) {
            b1 = 1;
        }
        if (func_002332a0(arg0, 0xC) > 0) {
            b4 = 1;
        }
        break;
    case 2:
        found = PTDatCalcHasSkill(arg0, 0x1C0);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C1);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C2);
        if (found != 0) {
            acc |= 0x2000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C3);
        if (found != 0) {
            acc |= 0x4000000;
        }
        if (func_002332a0(arg0, 9) > 0) {
            b1 = 1;
        }
        if (func_002332a0(arg0, 0xD) > 0) {
            b4 = 1;
        }
        break;
    case 3:
        found = PTDatCalcHasSkill(arg0, 0x1C4);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C5);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C6);
        if (found != 0) {
            acc |= 0x2000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C7);
        if (found != 0) {
            acc |= 0x4000000;
        }
        if (func_002332a0(arg0, 11) > 0) {
            b1 = 1;
        }
        if (func_002332a0(arg0, 0xE) > 0) {
            b4 = 1;
        }
        break;
    case 4:
        found = PTDatCalcHasSkill(arg0, 0x1C8);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1C9);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1CA);
        if (found != 0) {
            acc |= 0x2000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1CB);
        if (found != 0) {
            acc |= 0x4000000;
        }
        if (func_002332a0(arg0, 10) > 0) {
            b1 = 1;
        }
        if (func_002332a0(arg0, 0xF) > 0) {
            b4 = 1;
        }
        break;
    case 6:
        found = PTDatCalcHasSkill(arg0, 0x1CC);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1CD);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1CE);
        if (found != 0) {
            acc |= 0x2000000;
        }
        break;
    case 7:
        found = PTDatCalcHasSkill(arg0, 0x1CF);
        if (found != 0) {
            acc |= 0x10000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1D0);
        if (found != 0) {
            acc |= 0x1000000;
        }
        found = PTDatCalcHasSkill(arg0, 0x1D1);
        if (found != 0) {
            acc |= 0x2000000;
        }
        break;
    case 9:
        found = PTDatCalcHasSkill(arg0, 0x225);
        if (found != 0) {
            goto acc_9_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x4C);
        if (found == 0) {
            goto skp_9_b;
        }
acc_9_b:
        acc |= 0x10000000;
skp_9_b:
        found = PTDatCalcHasSkill(arg0, 0x1D7);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 8:
        found = PTDatCalcHasSkill(arg0, 0x226);
        if (found != 0) {
            goto acc_8_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x4B);
        if (found == 0) {
            goto skp_8_b;
        }
acc_8_b:
        acc |= 0x10000000;
skp_8_b:
        found = PTDatCalcHasSkill(arg0, 0x1D2);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 10:
        found = PTDatCalcHasSkill(arg0, 0x227);
        if (found != 0) {
            goto acc_10_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x4D);
        if (found == 0) {
            goto skp_10_b;
        }
acc_10_b:
        acc |= 0x10000000;
skp_10_b:
        found = PTDatCalcHasSkill(arg0, 0x1D5);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 13:
        found = PTDatCalcHasSkill(arg0, 0x228);
        if (found != 0) {
            goto acc_13_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x50);
        if (found == 0) {
            goto skp_13_b;
        }
acc_13_b:
        acc |= 0x10000000;
skp_13_b:
        found = PTDatCalcHasSkill(arg0, 0x1D3);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 15:
        found = PTDatCalcHasSkill(arg0, 0x22C);
        if (found != 0) {
            goto acc_15_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x52);
        if (found == 0) {
            goto skp_15_b;
        }
acc_15_b:
        acc |= 0x10000000;
skp_15_b:
        found = PTDatCalcHasSkill(arg0, 0x1D4);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 11:
        found = PTDatCalcHasSkill(arg0, 0x22A);
        if (found != 0) {
            goto acc_11_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x4E);
        if (found == 0) {
            goto skp_11_b;
        }
acc_11_b:
        acc |= 0x10000000;
skp_11_b:
        found = PTDatCalcHasSkill(arg0, 0x1D6);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 14:
        found = PTDatCalcHasSkill(arg0, 0x229);
        if (found != 0) {
            goto acc_14_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x51);
        if (found == 0) {
            goto skp_14_b;
        }
acc_14_b:
        acc |= 0x10000000;
skp_14_b:
        found = PTDatCalcHasSkill(arg0, 0x1D9);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 12:
        found = PTDatCalcHasSkill(arg0, 0x22B);
        if (found != 0) {
            goto acc_12_b;
        }
        found = DC411HasEquipmentProperty(arg0, 0x4F);
        if (found == 0) {
            goto skp_12_b;
        }
acc_12_b:
        acc |= 0x10000000;
skp_12_b:
        found = PTDatCalcHasSkill(arg0, 0x1D8);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 0:
        break;
    case 5:
        break;
    }
    switch (temp_16) {
    case 8:
    case 10:
    case 0xF:
    case 0xB:
    case 0xE:
        found = PTDatCalcHasSkill(arg0, 0x1DA);
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    }
    if (temp_16 != 5) {
        found = PTDatCalcHasSkill(arg0, 0x1DB);
        if (found != 0) {
            acc |= 0x1000000;
        }
    }
    if (hasFlag == 1 && (val & 0x8000000) != 0) {
        val = (val & 0xF7FF0000) | 100;
    }
    if (acc != 0) {
        if ((acc & 0x10000000) != 0 && (val & 0x7000000) == 0) {
            val = (((val & 0xF7FFFFFF) | 0x10000000) & 0xFFFF0000) | 0x32;
        }
        if ((acc & 0x1000000) != 0 && (val & 0x6000000) == 0) {
            val = (((val & 0xE7FFFFFF) | 0x1000000) & 0xFFFF0000) | 0x64;
        }
        if ((acc & 0x2000000) != 0 && (val & 0x4000000) == 0) {
            val = (((val & 0xE6FFFFFF) | 0x2000000) & 0xFFFF0000) | 0x64;
        }
        if ((acc & 0x4000000) != 0) {
            val = (((val & 0xE4FFFFFF) | 0x4000000) & 0xFFFF0000) | 0x64;
        }
    }
    if (b1 != 0 && (val & 0x17000000) != 0) {
        val = (val & 0xE8FF0000) | 100;
    }
    if (b4 != 0 && ((val & 0x8000000) != 0 || (val & 0xFF000000) == 0)) {
        val = (((val & 0xFFFFFF) | 0x10000000) & 0xFFFF0000) | 0x32;
    }
    return (s32)val;
}
#pragma pop

// FUN_0023D6E0
s32 func_0023d6e0(s16 arg0)
{
    if (arg0 >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    return 1 << (arg0 + 1);
}




// FUN_0023D740
s32 func_0023d740(s32 arg0, s32 arg1)
{
    s32 var_16;

    if ((s16)arg0 != -1) {
        var_16 = (s16)func_0023d8e0(NULL, arg0 & 0xFFFF);
        if (var_16 == 6) {
            return 6;
        }
    }
    switch (arg1) {
    case 0x2:
        var_16 = 0xB;
        break;
    case 0x4:
        var_16 = 0xA;
        break;
    case 0x8:
        var_16 = 0xF;
        break;
    case 0x10:
        var_16 = 8;
        break;
    case 0x1:
        var_16 = 0xC;
        break;
    case 0x20:
        var_16 = 9;
        break;
    case 0x40:
        var_16 = 0xD;
        break;
    case 0x80:
        var_16 = 0xE;
        break;
    case 0x100:
        var_16 = 5;
        break;
    case 0x80000:
        var_16 = 7;
        break;
    case 0x100000:
        var_16 = 5;
        break;
    default:
        func_0046d730(D_00635938, 0xE82);
        break;
    }
    return var_16;
}

// FUN_0023D8E0
s32 func_0023d8e0(u8 *arg0, u16 arg1)
{
    s32 v;

    if (arg0 != 0 && (arg1 & 0xFFFF) < 0x1B8 &&
        (iGpffffb3b8[(arg1 & 0xFFFF) * 0x28] & 2)) {
        if (*(u16 *)arg0 & 4) {
            v = iGpffffb3c4[*(u16 *)(arg0 + 2) * 0x3C + 0x38];
        } else {
            v = (s16)func_00106a30((s16)((u16)func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        v = (s8)iGpffffb3b4[(arg1 & 0xFFFF) * 2];
    }
    return v;
}
/* measured: 992B / 992B, 24 resolved relocations, no instruction differences.
   The ordered optimizer scopes and materialized offsets/loop operands retain
   the fresh 16-bit masks and retail register ordering. The equipment guard
   tests a zero-extended value; percentage products wrap to 32 bits before
   signed division, while cost reduction remains an unsigned shift. */
// FUN_0023D9B0
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants on
#pragma opt_propagation off
u32 func_0023d9b0(u8 *arg0, s32 arg1)
{
    s32 offset;
    u32 result;
    u16 count;
    u16 index;
    u16 maximum;
    u8 *table;
    s32 product;
    s32 equipment;
    s32 hit;
    s32 entry;
    s32 reduction;
    s32 limit;
    u32 field_offset;

    if ((s32)(u16)arg1 >= 0x1B8) {
        func_0046d730(D_00635938, 0xEB4);
    }
    result = 0;
    offset = (u16)arg1 * 0x28;
    switch (*(u8 *)(offset + (u32)iGpffffb3b8 + 3)) {
    case 1:
        if (*(u16 *)arg0 & 4) {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xEBE);
            }
            return 0;
        }
        maximum = func_00231f80((DatUnit *)arg0);
        field_offset = (u16)arg1 * 0x28;
        table = (u8 *)(field_offset + (u32)iGpffffb3b8);
        product = (s32)((u32)maximum * *(u16 *)(table + 4));
        result = product / 100 + *(u16 *)(table + 6);
        count = (u16)func_0023e130(arg0);
        table = func_0023e140(arg0);
        index = 0;
        limit = count;
        reduction = 0x20B;
        while (index < limit) {
            entry = *(u16 *)(table + index * 2);
            if (entry == reduction) {
                hit = 1;
                goto hp_reduction;
            }
            index++;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            equipment = (u16)func_00106cd0(*(s16 *)(arg0 + 2), 2);
            if (equipment >= 0) {
                if (func_001069a0((s16)equipment) == 0x20B) {
                    hit = 1;
                    goto hp_reduction;
                }
            }
        }
        hit = 0;
    hp_reduction:
        if (hit != 0) result >>= 1;
        if (result == 0) result = 1;
        break;
    case 2:
        if (*(u16 *)arg0 & 4) {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xED7);
            }
            if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 2) {
                return 0;
            }
        }
        table = iGpffffb3b8;
        if ((*(u8 *)(table + offset) & 0x10) == 0) {
            field_offset = (u16)arg1 * 0x28;
            table = (u8 *)(field_offset + (u32)table);
            result = *(u16 *)(table + 4) + *(u16 *)(table + 6);
        } else {
            maximum = func_00232290((DatUnit *)arg0);
            field_offset = (u16)arg1 * 0x28;
            table = (u8 *)(field_offset + (u32)iGpffffb3b8);
            product = (s32)((u32)maximum * *(u16 *)(table + 4));
            result = product / 100 + *(u16 *)(table + 6);
        }
        if (result == 0) break;
        count = (u16)func_0023e130(arg0);
        table = func_0023e140(arg0);
        index = 0;
        limit = count;
        reduction = 0x20A;
        while (index < limit) {
            entry = *(u16 *)(table + index * 2);
            if (entry == reduction) {
                hit = 1;
                goto sp_reduction;
            }
            index++;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            equipment = (u16)func_00106cd0(*(s16 *)(arg0 + 2), 2);
            if (equipment >= 0) {
                if (func_001069a0((s16)equipment) == 0x20A) {
                    hit = 1;
                    goto sp_reduction;
                }
            }
        }
        hit = 0;
    sp_reduction:
        if (hit != 0) result >>= 1;
        if (result == 0) result = 1;
        break;
    }
    return result;
}
#pragma pop
// FUN_0023DD90
u16 func_0023dd90(u8 *arg0, s32 arg1)
{
    u8 *base = iGpffffb3b8 + 3;
    return *(u8 *)(base + (arg1 & 0xFFFF) * 0x28);
}




// FUN_0023DDC0
s32 func_0023ddc0(u8 *arg0, s32 arg1)
{
    s32 var_17;
    s32 idx;
    u32 v;

    var_17 = 0;
    if ((u16)arg1 >= 0x240) {
        func_0046d730(D_00635938, 0xF1A);
    }
    idx = (arg1 & 0xFFFF) * 0x28;
    if (iGpffffb3b8[idx + 0x11] == 0x10) {
        return 0;
    }
    if ((s32)((*(s32 *)(arg0 + 0xC) & 8) != 0) != 0) {
        return 4;
    }
    v = func_0023d9b0(arg0, arg1);
    switch (iGpffffb3b8[idx + 3]) {
    case 1:
        if (!(iGpffffb3b8[idx] & 1)) {
            if (*(u16 *)(arg0 + 8) > v) {
            } else {
                var_17 = 1;
            }
        } else {
            if (*(u16 *)(arg0 + 8) < v) {
                var_17 = 1;
            }
        }
        break;
    case 2:
        if (*(u16 *)(arg0 + 0xA) < v) {
            var_17 = 2;
        }
        break;
    }
    return var_17;
}

// FUN_0023DF70
s32 func_0023df70(s32 arg0)
{
    u8 *base;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        func_0046d730(D_00635938, 0xF5E);
    }
    base = iGpffffb3b8 + (u16)arg0 * 0x28;
    return (base[0] & 2) != 0;
}

// FUN_0023DFE0
s32 func_0023dfe0(u8 *unit)
{
    return 0;
}

// FUN_0023DFF0
#pragma push
/* measured: 320B/320B, nd 0. Unsigned remainders preserve distinct masks
   through CSE; hoisting and selected-before-index match retail registers. */
#pragma opt_loop_invariants on
#pragma opt_common_subs on
s32 func_0023dff0(u8 *arg0)
{
    u16 choices[16];
    s32 count;
    u16 *table;
    u32 selected;
    s32 index;
    s32 valid;
    u16 value;
    u32 n;

    count = func_0023e130(arg0) & 0xFFFF;
    table = (u16 *)func_0023e140(arg0);
    selected = 0;
    index = 0;
    while ((index & 0xFFFF) < (s32)((u32)count % 0x10000U) &&
           (u32)(selected & 0xFFFF) < 16U) {
        value = table[(u32)index % 0x10000U];
        switch (value) {
        case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5:
            valid = 1;
            break;
        default:
            valid = 0;
            break;
        }
        if (valid) {
            choices[(u32)selected % 0x10000U] = value;
            selected = (selected + 1) & 0xFFFF;
        }
        index = (index + 1) & 0xFFFF;
    }
    n = (u32)selected % 0x10000U;
    if (n == 0)
        return 0;
    if (n == 0)
        func_0046d730(D_00635938, 0x17);
    return choices[func_003b7060() % n];
}
#pragma pop


// FUN_0023E140
u8 *func_0023e140(u8 *arg0)
{
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        return func_001094e0(*(u16 *)(arg0 + 2));
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0xFA8);
    }
    return iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0xE;
}

// FUN_0023E1F0
u8 func_0023e1f0(u8 *arg0)
{
    u8 *base;
    if (*(u16 *)(arg0 + 0) & 4) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFBB);
    }
    base = iGpffffb3c0 + 0x14A;
    return *(u8 *)(base + *(u16 *)(arg0 + 2) * 0x14C);
}




// FUN_0023E270
u16 func_0023e270(u8 *arg0)
{
    if (*(u16 *)arg0 & 4) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFCE);
    }
    return (u16)func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF;
}

// FUN_0023E2F0
s32 func_0023e2f0(u8 *arg0, s32 arg1)
{
    u8 *b;
    u16 v;
    s32 idx;

    if (*(u16 *)arg0 & 4) {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFE2);
        }
        idx = *(u16 *)(arg0 + 2) * 0xE8;
        b = (u8 *)iGpffffb3cc;
        return b[idx + 0x1A];
    }
    if (*(u16 *)(arg0 + 2) >= 0xB) {
        func_0046d730(D_00635938, 0xFE6);
    }
    v = (u16)arg1;
    if (v & 6) {
        idx = *(u16 *)(arg0 + 2) * 0x14C;
        b = (u8 *)iGpffffb3c0;
        return b[idx + 0x18];
    }
    return 1;
}

/* MATCHED 2026-08-03 (wave 14): the goto-form shared zero block + array
   spelling for the lbu case + `#pragma opt_propagation off` + the index-first
   PTDatCalcOffsetAdd helper on the case-0 lhu path together reproduced
   retail's early iGpffffb3c4 base load. Was a documented load-sinking floor
   (nd 7); now matches byte-for-byte. */
// FUN_0023E3E0
/* measured: opt_propagation off + index-first inline helper force the
   single-use iGpffffb3c4 base lw before the *0x3C chain (peer-verified). */
#pragma opt_propagation off
u16 func_0023e3e0(u16 *arg0, s32 arg1)
{
    u16 ret;
    if (arg0[0] & 0x4) {
        u16 field0 = arg0[1];
        if (field0 >= 0x150) {
            func_0046d730(D_00635938, 0x1002);
        }
        switch (arg1 & 0xFF) {
        case 0:
            return *(u16 *)(PTDatCalcOffsetAdd((field0 & 0xFFFF) * 0x3C, (u32)iGpffffb3c4) + 0x3A);
        case 1:
            return iGpffffb3c4[(field0 & 0xFFFF) * 0x3C + 0x39];
        case 2:
            return *(u8 *)(iGpffffb3b8 + 0x25);
        default:
            func_0046d730(D_00635938, 0x100D);
            goto zero;
        }
    }
    else {
        u16 field1;
        u32 r;
        field1 = arg0[1];
        if (field1 >= 0xB) {
            func_0046d730(D_00635938, 0x1011);
        }
        r = (u16)func_00106cd0((s16)field1, 0) & 0xFFFF;
        switch (arg1 & 0xFF) {
        case 0:
            return func_001068b0((s16)r);
        case 1:
            return func_001068e0((s16)r);
        case 2:
            return func_00106910((s16)r) & 0xFF;
        default:
            func_0046d730(D_00635938, 0x101C);
            goto zero;
        }
    }
zero:
    return 0;
}
/* measured: close opt_propagation scope after func_0023e3e0. */
#pragma opt_propagation on
// FUN_0023E5B0
s32 func_0023e5b0(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    u16 id;
    s32 v;

    if (*(u16 *)arg0 & 4) {
        temp_3 = arg1 & 0xFF;
        switch (temp_3) {
        case 0:
            return 0xA;
        case 1:
            return 0xA;
        default:
            func_0046d730(D_00635938, 0x1039);
            goto ret0;
        }
    } else {
        id = *(u16 *)(arg0 + 2);
        if ((s32)id >= 0xB) {
            func_0046d730(D_00635938, 0x103D);
        }
        v = (u16)func_00106cd0((s16)id, 1) & 0xFFFF;
        temp_3 = arg1 & 0xFF;
        switch (temp_3) {
        case 0:
            return func_00106970((s16)v);
        case 1:
            return func_00106940((s16)v);
        default:
            func_0046d730(D_00635938, 0x1046);
            goto ret0;
        }
    }
ret0:
    return 0;
}

/* Fixed eight-slot skill search shared by hit and critical checks. */
#pragma push
#pragma opt_loop_invariants on
static inline u8 *DC411SkillTable(u8 *arg0)
{
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        return func_001094e0(*(u16 *)(arg0 + 2));
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0xFA8);
    }
    return iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0xE;
}

static inline s32 DC411HasFixedSkill(u8 *unit, s32 requestedSkill)
{
    s32 skill;
    s32 index;
    u8 *table;
    s32 equipment;

    table = DC411SkillTable(unit);
    index = 0;
    skill = requestedSkill & 0xFFFF;
    while ((index & 0xFFFF) < 8) {
        if (skill == *(u16 *)(table + (u16)index * 2)) {
            return 1;
        }
        index = (index + 1) & 0xFFFF;
    }
    if (!(*(u16 *)unit & 4)) {
        equipment = (u32)(u16)func_00106cd0(*(s16 *)(unit + 2), 2);
        if (equipment >= 0) {
            if (skill == func_001069a0((s16)equipment)) {
                return 1;
            }
        }
    }
    return 0;
}

/* C89 promotes the u16 skill formal to the existing s32 call interface.
 * Native byte/halfword conversions retain the retail flag and element checks.
 * Cases 1 and 14 share an early result exit; counter and evade causes share
 * one lifetime. measured: 10920 code bytes plus 8 zero alignment bytes.
 * See docs/probe_archive/DC_worker2_20260920_hit_recovery.md. */
s32 func_0023e6f0(u8 *, u8 *, s32, s32);
// FUN_0023E6F0
s32 func_0023e6f0(arg0, arg1, arg2, arg3)
u8 *arg0;
u8 *arg1;
u16 arg2;
s32 arg3;
{
    extern f32 iGpffff8170;
    extern f32 fGpffff80cc;
    s32 result;
    s32 checkedSkill;
    s32 skill;
    s32 offset;
    u16 targetFlags;
    u8 active;
    u16 enemyElement;
    s32 element;
    s32 elementMask;
    s32 counterRate;
    s32 rawElement;
    s32 resistance;
    f32 defenseRate;
    f32 attackRate;
    f32 evadeMultiplier;
    f32 hitMultiplier;
    s32 equipmentBonus;
    s16 evadeCause;
    s32 baseRate;

    checkedSkill = arg2 & 0xFFFF;
    if (checkedSkill >= 0x1B8) {
        func_0046d730(D_00635938, 0x105E);
    }
    targetFlags = *(u16 *)arg1;
    if (((*(u16 *)arg0 & 4) != (targetFlags & 4)) &&
        (s8)(active = (*(u32 *)(arg0 + 0x14) & 0x100000) != 0) > 0) {
        *(s16 *)(arg1 + 0x2C) = 0xB2;
        return 4;
    }
    skill = (u32)arg2 % 0x10000U;
    offset = skill * 0x28;
    switch (iGpffffb3b8[offset + 0x24]) {
    case 1:
        if ((u8)((*(u32 *)(arg1 + 0xC) & 4) != 0)) {
            result = 1;
            goto finish;
        } else {
            return 4;
        }
    case 7:
        return (targetFlags & 0x1000) ? 4 : 1;
    case 8:
        return (targetFlags & 0x1000) ? 1 : 4;
    case 9:
        if (func_00243e30((u16 *)arg1) != 0) {
            return 0x100;
        }
        break;
    case 12:
        if (func_00242800(arg1, 6) & 0x08000000) {
            return 1;
        }
        return (func_00242800(arg1, 7) & 0x08000000) ? 1 : 4;
    case 14:
        if ((u8)(*(u8 *)(arg1 + 0xC) != 0)) {
            result = 1;
            goto finish;
        } else {
            return 4;
        }
    }
    if (arg0 != NULL && checkedSkill < 0x1B8 &&
        (iGpffffb3b8[offset] & 2)) {
        if (*(u16 *)arg0 & 4) {
            enemyElement = *(u8 *)(PTDatCalcOffsetAdd(
                *(u16 *)(arg0 + 2) * 0x3C, (u32)iGpffffb3c4) + 0x38);
            rawElement = (s16)enemyElement;
        } else {
            rawElement = (s16)func_00106a30(
                (s16)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 0));
        }
    } else {
        rawElement = *(s8 *)(iGpffffb3b4 + skill * 2);
    }
    element = (s16)rawElement;
    if (element >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    elementMask = 1 << (element + 1);
    if (!(elementMask & 0xE0001)) {
        if (elementMask & 2) {
            if ((s8)(active = (*(u32 *)(arg1 + 0x14) & 0x10000) != 0) > 0) {
                *(u32 *)(arg1 + 0x18) |= 0x10000;
                return 0x200;
            }
            if (!(arg3 & 2) && !(iGpffffb3b8[offset] & 0x40)) {
                counterRate = 0;
                if (DC411HasFixedSkill(arg1, 0x1F8) ||
                    (DCHitEquipmentCount(arg1, 0x4A) & 0xFFFF)) {
                    counterRate = 20;
                    evadeCause = 0x11F8;
                } else {
                    if (DC411HasFixedSkill(arg1, 0x1F7) ||
                        (DCHitEquipmentCount(arg1, 0x49) & 0xFFFF)) {
                        counterRate = 15;
                        evadeCause = 0x11F7;
                    } else {
                        if (DC411HasFixedSkill(arg1, 0x1F6) ||
                            (DCHitEquipmentCount(arg1, 0x48) & 0xFFFF)) {
                            counterRate = 10;
                            evadeCause = 0x11F6;
                        }
                    }
                }
                counterRate = (s16)counterRate;
                if (counterRate != 0 &&
                    (s32)(func_003b7060() % 100U) < counterRate) {
                    *(s16 *)(arg1 + 0x2C) = evadeCause;
                    return 0x200;
                }
            }
        } else if (!(elementMask & 0x40) &&
            (s8)(active = (*(u32 *)(arg1 + 0x14) & 0x20000) != 0) > 0) {
            *(u32 *)(arg1 + 0x18) |= 0x20000;
            return 0x200;
        }
        resistance = func_00242800(arg1, rawElement);
        if (resistance & 0x02000000) {
            return 0x200;
        }
        if (resistance & 0x04000000) {
            return 0x400;
        }
        if (resistance & 0x01000000) {
            return 0x100;
        }
    }
    if (iGpffffb3b8[offset + 0xE] == 0) {
        return 4;
    }
    if ((u8)((*(u32 *)(arg1 + 0xC) & 0x100000) != 0)) {
        return 1;
    }
    if (func_00243e30((u16 *)arg1) != 0) {
        return 1;
    }
    if (iGpffffb3b8[offset + 0xE] >= 100) {
        return 1;
    }
    if (*(u16 *)arg1 & 0x40) {
        return 1;
    }
    switch (*(u32 *)(arg1 + 0xC) & 0xFFFFF) {
    case 1:
        return 1;
    }
    attackRate = func_00233bc0(arg0, 4, arg2);
    defenseRate = func_00233bc0(arg1, 2, arg2);
    evadeMultiplier = 1.0f;
    hitMultiplier = 1.0f;
    equipmentBonus = 0;
    evadeCause = 0;
    if (!(arg3 & 2)) {
        switch (element) {
        case 0:
            if (DC411HasFixedSkill(arg1, 0x1DD)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DD;
            } else if (DC411HasFixedSkill(arg1, 0x1DC)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DC;
            }
            break;
        case 1:
            if (DC411HasFixedSkill(arg1, 0x1DF)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DF;
            } else if (DC411HasFixedSkill(arg1, 0x1DE)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DE;
            }
            break;
        case 2:
            if (DC411HasFixedSkill(arg1, 0x1E1)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E1;
            } else if (DC411HasFixedSkill(arg1, 0x1E0)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E0;
            }
            break;
        case 4:
            if (DC411HasFixedSkill(arg1, 0x1E3)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E3;
            } else if (DC411HasFixedSkill(arg1, 0x1E2)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E2;
            }
            break;
        case 3:
            if (DC411HasFixedSkill(arg1, 0x1E5)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E5;
            } else if (DC411HasFixedSkill(arg1, 0x1E4)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E4;
            }
            break;
        }
        if (evadeMultiplier == 1.0f && (elementMask & 0x3C)) {
            if (DC411HasFixedSkill(arg1, 0x1E6)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E6;
            }
        }
        if (DC411HasFixedSkill(arg1, 0x209)) {
            return 1;
        }
        if (DC411HasFixedSkill(arg1, 0x208)) {
            evadeMultiplier *= 0.5f;
        }
    }
    baseRate = func_00244f60(4, (u16 *)arg0, (u16 *)arg1, arg2, 0);
    if (!(*(u16 *)arg1 & 4)) {
        switch (element) {
        case 0:
            if (DC411HasEquipmentProperty(arg1, 0x74)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x75)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x76)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1: case 2: case 3: case 4:
            if (DC411HasEquipmentProperty(arg1, 0x83)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x84)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x85)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1:
            if (DC411HasEquipmentProperty(arg1, 0x77)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x78)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x79)) {
                equipmentBonus += 20;
            }
            break;
        case 2:
            if (DC411HasEquipmentProperty(arg1, 0x7A)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x7B)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x7C)) {
                equipmentBonus += 20;
            }
            break;
        case 3:
            if (DC411HasEquipmentProperty(arg1, 0x80)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x81)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x82)) {
                equipmentBonus += 20;
            }
            break;
        case 4:
            if (DC411HasEquipmentProperty(arg1, 0x7D)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(arg1, 0x7E)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(arg1, 0x7F)) {
                equipmentBonus += 20;
            }
            break;
        }
    }
    baseRate = (s32)(evadeMultiplier * (hitMultiplier *
        (defenseRate * ((f32)baseRate * attackRate)))) - equipmentBonus;
    if (baseRate > 99) {
        baseRate = 99;
    } else if (baseRate < 50) {
        baseRate = 50;
    }
    if ((s32)(func_003b7060() % 100U) >= baseRate) {
        *(s16 *)(arg1 + 0x2C) = evadeCause;
        return 4;
    }
    return 1;
finish:
    return result;
}
#pragma pop


/* measured 002411a0: configured b210 emits 2588/2592B with all 70 relocations
 * resolved exactly and four retail zero tail bytes. Declaring idx after lvl
 * restores the initial index/element register assignment. The repeated searches,
 * native conversions and conversion-before-bonus order preserve retail behavior.
 * opt_loop_invariants on scopes the searches; opt_common_subs on scopes the main
 * body. All 79 siblings and allocated data are unchanged.
 * The fifth argument is passed by func_001f14f0 and unused by retail.
 * See docs/probe_archive/DC_worker3_20260920_recoveries.md. */
#pragma push
#pragma opt_loop_invariants on

/* The skill is interpreted as u16 inside this C89 definition; its promoted
 * s32 interface preserves the existing callers. measured: 2588/2592 bytes
 * with func_00244f60's real u16 skill parameter; the suffix is zero alignment. */
s32 func_002411a0(u8 *, u8 *, s32, s32, s32);
// FUN_002411A0
#pragma opt_common_subs on
s32 func_002411a0(arg0, arg1, arg2, arg3, arg4)
u8 *arg0;
u8 *arg1;
u16 arg2;
s32 arg3;
s32 arg4;
{
    s32 tmp22;
    s32 lvl;
    s32 idx;
    s32 bits;
    u16 element;
    u16 enemyElement;
    s32 res;
    s32 base;
    s32 thresh;
    f32 f20;
    u8 *entry;
    u16 id16;
    s32 bonus;
    s32 scaled;
    s32 total;

    tmp22 = arg2 & 0xFFFF;
    if (tmp22 >= 0x1B8) {
        func_0046d730(D_00635938, 0x122E);
    }
    switch (arg3 & 0xFFFF) {
    case 0x200:
    case 0x400:
    case 0x100:
    case 2:
    case 4:
        return 1;
    }
    if ((arg0 != 0) && (tmp22 < 0x1B8) && ((iGpffffb3b8[(idx = (u32)arg2 % 0x10000U) * 0x28] & 2) != 0)) {
        if ((*(u16 *)arg0 & 4) != 0) {
            id16 = *(u16 *)(arg0 + 2);
            enemyElement = iGpffffb3c4[id16 * 0x3C + 0x38];
            lvl = (s16)enemyElement;
        } else {
            element = func_00106cd0(*(s16 *)(arg0 + 2), 0);
            lvl = (s16)func_00106a30((s16)element);
        }
    } else {
        idx = (u32)arg2 % 0x10000U;
        lvl = *(s8 *)(iGpffffb3b4 + idx * 2);
    }
    bits = (s16)lvl;
    if (bits >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    bits = 1U << (bits + 1);
    if ((bits & 0xE0001) != 0) {
        return 1;
    }
    res = func_00242800(arg1, lvl);
    if (((bits & 2) == 0) && (((bits & 0x40) == 0) || (iGpffffb3b8[idx * 0x28 + 2] != 1))) {
        if (res & 0x08000000) {
            return 4;
        }
        return 1;
    }
    idx *= 0x28;
    entry = iGpffffb3b8;
    if (entry[idx + 0x25] == 0) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((*(u16 *)arg1 & 0x80) != 0) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((*(u16 *)arg0 & 4) == (*(u16 *)arg1 & 4)) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((res & 0x08000000) != 0) {
        return 4;
    }
    if (func_00243e30((u16 *)arg1) != 0) {
        return 1;
    }
    base = 0;
    thresh = 0;
    f20 = 1.0f;
    entry = iGpffffb3b8;
    if (entry[idx + 0x25] == 0x64) {
        base = 0x64;
        thresh = 0x64;
    }
    switch (entry[idx + 2]) {
    case 1:
        if (base == 0) {
            base = func_00244f60(5, (u16 *)(arg0), (u16 *)(arg1), arg2, 0);
        }
        if (DC411HasFixedSkill(arg1, 0x206)) {
            f20 = f20 * 0.5f;
        }
        if (DC411HasFixedSkill(arg0, 0x207)) {
            f20 = f20 * 2.0f;
        }
        scaled = (s32)((f32)base * f20);
        bonus = 0;
        if (tmp22 >= 0x1B8) {
            func_0046d730(D_00635938, 0xF5E);
        }
        if ((u8)((iGpffffb3b8[idx] & 2) != 0)) {
            if (DC411HasEquipmentProperty(arg0, 0x3C)) {
                bonus += 5;
            }
            if (DC411HasEquipmentProperty(arg0, 0x3D)) {
                bonus += 10;
            }
            if (DC411HasEquipmentProperty(arg0, 0x3E)) {
                bonus += 15;
            }
        }
        if (func_002332a0(arg0, 5) > 0) {
            bonus += 7;
        }
        if (func_002332a0(arg0, 6) > 0) {
            bonus += 15;
        }
        total = scaled + bonus;
        if (total > 0x64) {
            total = 0x64;
        } else if (total < 0) {
            total = 0;
        }
        if ((s32)(func_003b7060() % 100) < thresh) {
            return 2;
        }
        if ((s32)(func_003b7060() % 100) < 0) {
            return 2;
        }
        if ((s32)(func_003b7060() % 100) < total) {
            return 2;
        }
        break;
    case 2:
        break;
    default:
        func_0046d730(D_00635938, 0x12EF);
        break;
    }
    return 1;
}
#pragma pop

/* measured: 4 attempts, best nd 58. Nearly everything now matches: the
   u32-typed flag1 gives retail's sltu booleanization, `(s32)(u16)arg2`
   defeats the mask CSE (raw arg2 stays in $s2, temp_6 in $a2),
   `(u32)temp_4 + temp_5` defeats the commutative cross-block CSE so the
   &2 check re-adds $a0+$a1 as retail, the entry reads are one addu into
   $v1, the 1 constant lands in $a3, and the return-1 tail (addiu $v1,1
   before addiu $v0,1, sllv, 0xE0001 mask) matches. Residual: the three
   path values each need ONE dsll32/dsra32-by-16 pair in retail (lbu+pair,
   jal+pair, lb with the pair only at the merge). `(s16)` casts fold into
   the merge's (s16) extension (no path pairs); the s64-shift spelling
   `(s32)((s64)x << 0x30) >> 0x30` keeps the path pairs but adds a
   dsll32/dsra32-by-0 truncation pair per path (6 extra words, nd 58). The
   merge itself ((s16)var_2_2 into $s0) matches.
   Wave 14 re-test: fresh reconstruction with the note's spellings (u32
   flag1, (s32)(u16)arg2, (s16) v) gave nd 83 (obj 504B vs window 544B,
   frame 0x50 vs 0x60 â€” 4 rst saved vs 5, branch targets shifted); the
   exact hand-adapted body was not recovered. The 5th arg (arg4) is passed
   by func_00241de0 but unused in the body (prologue never saves it).
   s16-extension-pair floor, corroborated. */
// FUN_00241BC0
#pragma push
/* measured: opt_propagation off keeps arg2 raw in $s2 and the masked u16 in $s0;
   per-use u16 casts for other masks avoid the 0xffff constant cache. */
#pragma opt_propagation off
s32 func_00241bc0(arg0, arg1, arg2, arg3, arg4)
u8 *arg0;
u8 *arg1;
s32 arg2;
s32 arg3;
s32 arg4;
{
    u16 idx;
    u32 offset;
    u8 *base;
    u8 *entry;
    u32 flag1;
    s16 value;

    idx = (u16)arg2;
    if (idx >= 0x1B8) {
        func_0046d730(D_00635938, 0x1305);
    }
    flag1 = *(u32 *)(arg1 + 0xC);
    if (((u32)((flag1 & 0x100000) != 0) != 0)) {
        return 0;
    }
    if ((u16)arg3 != 1) {
        return 0;
    }
    if ((*(u16 *)arg1 & 8)) {
        return 0;
    }
    offset = (u32)(u16)arg2 * 0x28;
    base = iGpffffb3b8;
    entry = (u8 *)(offset + (u32)base);
    if (entry[0x11] == 0 && (entry[0x18] != 1 || ((*(u32 *)(entry + 0x1C) & 0x80000) == 0))) {
        return 0;
    }
    if (arg0 != 0 && idx < 0x1B8 && ((*(u8 *)(base + offset) & 2))) {
        if ((*(u16 *)arg0 & 4)) {
            s32 partyOffset;
            u8 *partyPtr;

            partyOffset = (s32)(*(u16 *)(arg0 + 2) * 0x3C);
            partyPtr = (u8 *)(partyOffset + (s32)iGpffffb3c4);
            value = (s16)partyPtr[0x38];
        } else {
            value = (s16)func_00106a30((s16)((u16)func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        value = *(s8 *)(iGpffffb3b4 + (u32)(u16)arg2 * 2);
    }
    if (value >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    if (((1 << (value + 1)) & 0xE0001) == 0) {
        goto one;
    }
    return 0;
one:
    return 1;
}
#pragma pop
// FUN_00241DE0
s32 func_00241de0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *entry;
    u32 offset;
    if (!((arg2 & 0xFFFF) < 0x1B8)) {
        func_0046d730(D_00635938, 0x1333);
    }
    if (func_00241bc0(arg0, arg1, arg2, arg3, arg4) == 0) {
        return 0;
    }
    entry = (u8 *)iGpffffb3b8;
    offset = (u16)arg2 * 0x28;
    entry = (u8 *)((u32)offset + (u32)entry);
    switch (*(u8 *)(entry + 0x24)) {
    case 9:
    case 10:
        return 1;
    }
    if ((arg4 & 0xFFFF) == 2 || (arg4 & 0xFFFF) == 4) {
        return 1;
    }
    return 0;
}

// FUN_00241F00
s32 func_00241f00(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3)
{
    u16 temp_3;
    u8 var_2;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 var_2_2;
    u16 var_16;
    s32 temp_4;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    u16 temp_17;

    if ((u16)arg2 >= 0x1B8) {
        func_0046d730(D_00635938, 0x1360);
    }
    if (!(iGpffffb3b8[(arg2 & 0xFFFF) * 0x28] & 2)) {
        return 0;
    }
    if ((s32)((*(s32 *)(arg1 + 0xC) & 0x100000) != 0) != 0) {
        return 0;
    }
    temp_3 = *(u16 *)arg0;
    if (temp_3 & 0x10) {
        return 0;
    }
    if (!(temp_3 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x1371);
        }
        if (*(u16 *)arg0 & 4) {
            var_2 = 0;
        } else {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFBB);
            }
            var_2 = iGpffffb3c0[*(u16 *)(arg0 + 2) * 0x14C + 0x14A];
        }
        temp_3_2 = var_2 & 0xFF;
        if (temp_3_2 == 3 || temp_3_2 == 5) {
            return 0;
        }
    }
    temp_3_3 = arg3 & 0xFFFF;
    if (temp_3_3 != 4 && temp_3_3 != 2) {
        return 0;
    }
    if (*(u16 *)arg0 & 4) {
        var_2_2 = 0x64;
    } else {
        var_2_2 = 5;
    }
    var_16 = var_2_2 & 0xFFFF;
    if (*(u16 *)arg0 & 4) {
        var_2_3 = 0;
    } else {
        temp_17 = *(u16 *)(arg0 + 2);
        if ((s32)temp_17 >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)temp_17, 0)) & 0xFFFF) == 0x71) {
            var_2_3 = 1;
        } else if ((func_001069d0(func_00106cd0((s16)temp_17, 1)) & 0xFFFF) == 0x71) {
            var_2_3 = 1;
        } else {
            var_2_3 = 0;
        }
    }
    if (var_2_3 != 0) {
        var_16 = 0x50;
    }
    if (*(u16 *)arg0 & 4) {
        var_2_4 = 0;
    } else {
        temp_17 = *(u16 *)(arg0 + 2);
        if ((s32)temp_17 >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)temp_17, 0)) & 0xFFFF) == 0x72) {
            var_2_4 = 1;
        } else if ((func_001069d0(func_00106cd0((s16)temp_17, 1)) & 0xFFFF) == 0x72) {
            var_2_4 = 1;
        } else {
            var_2_4 = 0;
        }
    }
    if (var_2_4 != 0) {
        var_16 = 0x32;
    }
    if (*(u16 *)arg0 & 4) {
        var_2_5 = 0;
    } else {
        temp_17 = *(u16 *)(arg0 + 2);
        if ((s32)temp_17 >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)temp_17, 0)) & 0xFFFF) == 0x73) {
            var_2_5 = 1;
        } else if ((func_001069d0(func_00106cd0((s16)temp_17, 1)) & 0xFFFF) == 0x73) {
            var_2_5 = 1;
        } else {
            var_2_5 = 0;
        }
    }
    if (var_2_5 != 0) {
        var_16 = 0;
    }
    if ((s32)(func_003b7060() % 100) < (s32)(var_16 & 0xFFFF)) {
        return 1;
    }
    return 0;
}

// FUN_00242360
/* measured: loop-invariant 0x21C compare constant must be hoisted into
   the preheader (retail addiu $a0,$zero,0x21c before the loop's initial
   branch); mwcc b210 rematerialises it in the body without the pragma. */
#pragma opt_loop_invariants on
s32 func_00242360(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f1;
    s32 temp_16;
    s32 temp_16_2;
    u32 temp_2_2;
    s32 temp_3;
    s32 var_2_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_5;
    s32 temp_2;
    u32 flag1;
    u32 flag2;
    u32 flag3;
    u8 *var_2;
    u16 var_17;

    flag1 = (*(s32 *)(arg1 + 0xC) & 1) != 0;
    if (flag1) {
        return 0;
    }
    if ((arg3 & 0xFFFF) != 1) {
        return 0;
    }
    temp_16 = arg2 & 0xFFFF;
    if (temp_16 >= 0x1B8) {
        func_0046d730(D_00635938, 0x13B6);
    }
    temp_2 = func_0023a6b0(arg1, 0xC);
    if (temp_2 & 0x27000000) {
        return 0;
    }
    var_17 = 0;
    flag2 = (*(s32 *)(arg1 + 0xC) & 0x100000) != 0;
    if (flag2) {
        if (temp_16 >= 0x1B8) {
            func_0046d730(D_00635938, 0xF5E);
        }
        flag3 = (iGpffffb3b8[(u16)arg2 * 0x28] & 2) != 0;
        if (flag3) {
            var_17 = 0x32;
        }
        temp_3 = arg4 & 0xFFFF;
        if (temp_3 == 2 || temp_3 == 4) {
            var_17 = 0x64;
        }
    } else {
        var_17 = iGpffffb3b8[(u16)arg2 * 0x28 + 0x26];
        if ((s32)var_17 > 0) {
            temp_2_2 = temp_2 & 0xFFFF;
            var_f1 = (f32)temp_2_2;
            var_f1 = var_f1 / 100.0f;
            var_f0 = (f32)var_17;
            temp_f1 = var_f0 * var_f1;
            var_17 = (u16)temp_f1;
            if (!(*(u16 *)arg0 & 4)) {
                if (*(u16 *)(arg0 + 2) >= 0xB) {
                    func_0046d730(D_00635938, 0xFA5);
                }
                var_2 = func_001094e0(*(u16 *)(arg0 + 2));
            } else {
                if (*(u16 *)(arg0 + 2) >= 0x150) {
                    func_0046d730(D_00635938, 0xFA8);
                }
                var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
            }
            var_5 = 0;
            while ((var_5 & 0xFFFF) < 8) {
                if (*(u16 *)(var_2 + (u16)var_5 * 2) == 0x21C) {
                    var_2_2 = 1;
                    goto done;
                }
                var_5 = (var_5 + 1) & 0xFFFF;
            }
            if (!(*(u16 *)arg0 & 4) && (temp_2_2 = (u16)func_00106cd0((s16)*(u16 *)(arg0 + 2), 2) & 0xFFFF, (s32)temp_2_2 >= 0) &&
                (func_001069a0((s16)temp_2_2) == 0x21C)) {
                var_2_2 = 1;
            } else {
                var_2_2 = 0;
            }
done:
            if (var_2_2 != 0) {
                var_f0_2 = (f32)var_17;
                temp_f1_2 = 1.25f * var_f0_2;
                var_17 = (u16)temp_f1_2;
            }
        }
    }
    temp_16_2 = var_17 & 0xFFFF;
    if (temp_16_2 == 0) {
        return 0;
    }
    if (temp_16_2 >= 0x64 || (s32)(func_003b7060() % 100U & 0xFFFF) < temp_16_2) {
        return 1;
    }
    return 0;
}
/* Closes the measured opt_loop_invariants scope opened for func_00242360 above.
   It must stay scoped: leaving it on regresses the neighbouring functions. */
#pragma opt_loop_invariants off

// FUN_00242800
s32 func_00242800(u8 *arg0, s32 arg1)
{
    s16 id;
    s32 x;

    id = (s16)arg1;
    if (id == -1) {
        return 0;
    }
    if (id >= 0x13) {
        func_0046d730(D_00635938, 0x13FD);
    }
    if (id >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    x = 1 << (id + 1);
    if (x & 1) {
        return 0;
    }
    if (x & 0xE0000) {
        return 0x64;
    }
    return func_0023a6b0(arg0, arg1);
}

/* measured: fndiff 1 word (reloc-masked), fnalign 2 edits (plus 43 reloc-only), obj 813 instrs / retail 813 instrs (window 3264B, 12B under, 0.4% inside 3% gate). Baseline 172 edits / 750 words at 812/812; all-fresh counters 172->68 edits; loopinv 68->20; head temp_16 reuse 20->14; s16 value 14->3 edits / 558->2 words; tail (u16) mask 2->1 word / 3->2 edits. Free pragmas: loopinv 752, unroll/sched tie 750, commonsubs 578 words but 207 edits (rejected for edits). Subscript P[i] neutral 172; reuse temp_16 alone 246 edits (rejected). Decl swaps tie 172; fresh-first 159. All 8 skill-search loops match (while+goto-done, (u16)var_5 masks, fresh counters per loop, loopinv hoist); 0x231/0x232 early returns, 0x20/0x800/0x400 guards, 6/7 dispatch with 0x340/0x3C-0x38 checks, 0x211/0x221 + 0x212/0x222 with 50% random, 0x210/0x20F tail and 47cb0/107ac0 >=9 all in retail shape. Remaining: single addu $v0,$v1,$v0 vs $v0,$v0,$v1 orientation (commutative, source-invariant across both orders, floor) + lw addend masked as reloc-only. Supersedes prior nd-170 layout floor. */
/* MATCHED 2026-09-19.  The single differing word at 0x00242CEC - retail
   `addu $v0, $v1, $v0` against b210's `addu $v0, $v0, $v1` - was not a compiler floor.
   Routing the monster-attribute load through the file's existing `PTDatCalcOffsetAdd`
   helper fixes the operand order: the parameter boundary forces the offset to be the
   first addend, which is what retail emits.  Ten spellings had been measured without
   the helper and all tied at one differing word, which is what produced the incorrect
   floor claim in the earlier note.  The three sibling sites in this function already
   used the helper; this was the one that did not. */
// FUN_00242990
#pragma opt_loop_invariants on
s32 func_00242990(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_2;
    s32 found;
    u8 *var_2;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_5_8;
    s32 var_5_9;
    s16 value;
    s32 tmp;
    s32 var_17;

    var_17 = -1;
    temp_16 = arg1 & 0xFFFF;
    if ((temp_16 < 0x1B8) && (iGpffffb3b8[temp_16 * 0x28 + 0x24] == 0xD)) {
        return -1;
    }
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        var_2 = func_001094e0(*(u16 *)(arg0 + 2));
    } else {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFA8);
        }
        var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
    }
    var_5_2 = 0;
    while ((var_5_2 & 0xFFFF) < 8) {
        if (*(u16 *)(var_2 + (u16)var_5_2 * 2) == 0x231) {
            found = 1;
            goto done1;
        }
        var_5_2 = (var_5_2 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (temp_2 >= 0) {
            if (func_001069a0((s16)temp_2) == 0x231) {
                found = 1;
                goto done1;
            }
        }
    }
    found = 0;
done1:
    if (found != 0) {
        return 0x231;
    }
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        var_2 = func_001094e0(*(u16 *)(arg0 + 2));
    } else {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFA8);
        }
        var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
    }
    var_5_3 = 0;
    while ((var_5_3 & 0xFFFF) < 8) {
        if (*(u16 *)(var_2 + (u16)var_5_3 * 2) == 0x232) {
            found = 1;
            goto done2;
        }
        var_5_3 = (var_5_3 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (temp_2 >= 0) {
            if (func_001069a0((s16)temp_2) == 0x232) {
                found = 1;
                goto done2;
            }
        }
    }
    found = 0;
done2:
    if (found != 0) {
        return 0x232;
    }
    if (*(u16 *)arg0 & 0x20) {
        return 0;
    }
    if ((arg0 != 0) && (temp_16 < 0x1B8) && ((iGpffffb3b8[(u16)arg1 * 0x28] & 2) != 0)) {
        if (*(u16 *)arg0 & 4) {
            value = *(u8 *)((u8 *)PTDatCalcOffsetAdd(*(u16 *)(arg0 + 2) * 0x3C, (u32)iGpffffb3c4) + 0x38);
        } else {
            value = (s16)func_00106a30((s16)((u16)func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        value = *(s8 *)(iGpffffb3b4 + (u32)(u16)arg1 * 2);
    }
    if ((s16)value == 6) {
        if (*(u16 *)arg0 & 4) {
            tmp = 0;
        } else {
            tmp = (func_00106600(0x340) & 0xFF) > 0;
        }
        if (tmp != 0) {
            var_17 = 0x154;
        }
        if (!(*(u16 *)arg0 & 4)) {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFA5);
            }
            var_2 = func_001094e0(*(u16 *)(arg0 + 2));
        } else {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xFA8);
            }
            var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
        }
        var_5_4 = 0;
        while ((var_5_4 & 0xFFFF) < 8) {
            if (*(u16 *)(var_2 + (u16)var_5_4 * 2) == 0x211) {
                found = 1;
                goto done3;
            }
            var_5_4 = (var_5_4 + 1) & 0xFFFF;
        }
        if (!(*(u16 *)arg0 & 4)) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x211) {
                    found = 1;
                    goto done3;
                }
            }
        }
        found = 0;
done3:
        if ((found != 0) && ((s32)(func_003b7060() % 100U) < 0x32)) {
            var_17 = 0x211;
        }
        if (!(*(u16 *)arg0 & 4)) {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFA5);
            }
            var_2 = func_001094e0(*(u16 *)(arg0 + 2));
        } else {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xFA8);
            }
            var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
        }
        var_5_5 = 0;
        while ((var_5_5 & 0xFFFF) < 8) {
            if (*(u16 *)(var_2 + (u16)var_5_5 * 2) == 0x221) {
                found = 1;
                goto done4;
            }
            var_5_5 = (var_5_5 + 1) & 0xFFFF;
        }
        if (!(*(u16 *)arg0 & 4)) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x221) {
                    found = 1;
                    goto done4;
                }
            }
        }
        found = 0;
done4:
        if (found != 0) {
            var_17 = 0x221;
        }
    } else if ((s16)value == 7) {
        if (*(u16 *)arg0 & 4) {
            tmp = 0;
        } else {
            tmp = (func_00106600(0x340) & 0xFF) > 0;
        }
        if (tmp != 0) {
            var_17 = 0x154;
        }
        if (!(*(u16 *)arg0 & 4)) {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFA5);
            }
            var_2 = func_001094e0(*(u16 *)(arg0 + 2));
        } else {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xFA8);
            }
            var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
        }
        var_5_6 = 0;
        while ((var_5_6 & 0xFFFF) < 8) {
            if (*(u16 *)(var_2 + (u16)var_5_6 * 2) == 0x212) {
                found = 1;
                goto done5;
            }
            var_5_6 = (var_5_6 + 1) & 0xFFFF;
        }
        if (!(*(u16 *)arg0 & 4)) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x212) {
                    found = 1;
                    goto done5;
                }
            }
        }
        found = 0;
done5:
        if ((found != 0) && ((s32)(func_003b7060() % 100U) < 0x32)) {
            var_17 = 0x212;
        }
        if (!(*(u16 *)arg0 & 4)) {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFA5);
            }
            var_2 = func_001094e0(*(u16 *)(arg0 + 2));
        } else {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xFA8);
            }
            var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
        }
        var_5_7 = 0;
        while ((var_5_7 & 0xFFFF) < 8) {
            if (*(u16 *)(var_2 + (u16)var_5_7 * 2) == 0x222) {
                found = 1;
                goto done6;
            }
            var_5_7 = (var_5_7 + 1) & 0xFFFF;
        }
        if (!(*(u16 *)arg0 & 4)) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x222) {
                    found = 1;
                    goto done6;
                }
            }
        }
        found = 0;
done6:
        if (found != 0) {
            var_17 = 0x222;
        }
    }
    if ((s16)var_17 != -1) {
        goto tail;
    }
    if (!(*(u16 *)arg0 & 0x800)) {
        if (!(*(u16 *)arg0 & 4)) {
            if (*(u16 *)(arg0 + 2) >= 0xB) {
                func_0046d730(D_00635938, 0xFA5);
            }
            var_2 = func_001094e0(*(u16 *)(arg0 + 2));
        } else {
            if (*(u16 *)(arg0 + 2) >= 0x150) {
                func_0046d730(D_00635938, 0xFA8);
            }
            var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
        }
        var_5_8 = 0;
        while ((var_5_8 & 0xFFFF) < 8) {
            if (*(u16 *)(var_2 + (u16)var_5_8 * 2) == 0x210) {
                found = 1;
                goto done7;
            }
            var_5_8 = (var_5_8 + 1) & 0xFFFF;
        }
        if (!(*(u16 *)arg0 & 4)) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x210) {
                    found = 1;
                    goto done7;
                }
            }
        }
        found = 0;
done7:
        if (found != 0) {
            var_17 = 0x210;
            goto tail;
        }
    }
    if (*(u16 *)arg0 & 0x400) {
        goto tail;
    }
    if (!(*(u16 *)arg0 & 4)) {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0xFA5);
        }
        var_2 = func_001094e0(*(u16 *)(arg0 + 2));
    } else {
        if (*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0xFA8);
        }
        var_2 = *(u16 *)(arg0 + 2) * 0x3C + iGpffffb3c4 + 0xE;
    }
    var_5_9 = 0;
    while ((var_5_9 & 0xFFFF) < 8) {
        if (*(u16 *)(var_2 + (u16)var_5_9 * 2) == 0x20F) {
            found = 1;
            goto done8;
        }
        var_5_9 = (var_5_9 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (temp_2 >= 0) {
            if (func_001069a0((s16)temp_2) == 0x20F) {
                found = 1;
                goto done8;
            }
        }
    }
    found = 0;
done8:
    if (found != 0) {
        var_17 = 0x20F;
    }
tail:
    if (((s16)var_17 == -1) && (!(*(u16 *)arg0 & 4)) && (*(u16 *)(arg0 + 2) != 1) && (!(*(u16 *)arg0 & 0x400))) {
        if ((s32)(func_00107ac0((u16)(func_00247cb0((s16)*(u16 *)(arg0 + 2)) & 0xFFFF)) & 0xFFFF) >= 9) {
            var_17 = 0x20F;
        }
    }
    return var_17;
}
#pragma opt_loop_invariants off

// FUN_00243650
u8 func_00243650(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 temp_2;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_5;
    u32 temp_17;
    u8 temp_16;
    u8 temp_17_2;
    u8 var_2;
    u8 *temp_3;

    if ((u16)arg1 >= 0x1B8) {
        func_0046d730(D_00635938, 0x14C5);
    }
    temp_3 = iGpffffb3b8 + (arg1 & 0xFFFF) * 0x28;
    if (*(u8 *)temp_3 & 2) {
        temp_2 = (s32)(*(u16 *)arg0 & 4);
        if (temp_2 == 0) {
            if (temp_2 != 0) {
                if (*(u16 *)(arg0 + 2) >= 0x150) {
                    func_0046d730(D_00635938, 0xFE2);
                }
                temp_4 = *(u16 *)(arg0 + 2) * 0xE8;
                temp_5 = (s32)iGpffffb3cc;
                var_2 = *(u8 *)(temp_4 + temp_5 + 0x1A);
            } else {
                if (*(u16 *)(arg0 + 2) >= 0xB) {
                    func_0046d730(D_00635938, 0xFE6);
                }
                if ((u16)arg2 & 6) {
                    temp_4 = *(u16 *)(arg0 + 2) * 0x14C;
                    temp_5 = (s32)iGpffffb3c0;
                    var_2 = *(u8 *)(temp_4 + temp_5 + 0x18);
                } else {
                    var_2 = 1;
                }
            }
            return var_2;
        }
        return 1;
    }
    temp_16 = *(u8 *)(temp_3 + 0xF);
    temp_17_2 = *(u8 *)(temp_3 + 0x10);
    if ((s32)temp_16 <= 0 || (temp_17_2 & 0xFF) <= 0) {
        func_0046d730(D_00635938, 0x14D3);
    }
    temp_3_2 = temp_17_2 & 0xFF;
    if ((s32)temp_16 >= temp_3_2) {
        return temp_16;
    }
    temp_17 = (temp_3_2 - temp_16) + 1;
    if (temp_17 == 0) {
        func_0046d730(D_00635938, 0x17);
    }
    temp_2 = temp_16 & 0xFF;
    return (u8)(temp_2 + func_003b7060() % temp_17);
}

// FUN_00243840
u8 *func_00243840(s32 arg0)
{
    if ((arg0 & 0xFFFF) >= 0x240) {
        func_0046d730(D_00635938, 0x14E4);
    }
    return iGpffffb448 + (u16)arg0 * 0x13;
}

// FUN_002438B0
u8 *func_002438b0(s32 arg0)
{
    if ((arg0 & 0xFF) >= 0x20) {
        func_0046d730(D_00635938, 0x14F2);
    }
    return iGpffffb44c + (u8)arg0 * 0x15;
}

// FUN_00243920
u16 func_00243920(s64 arg0)
{
    return *(u16 *)((u8 *)func_00106820((s16)arg0) + 0x24);
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_0030c490 (verified MATCH there). */


// FUN_00243950
u16 func_00243950(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x1515);
    }
    return *(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0x1E);
}

// FUN_002439C0
u16 func_002439c0(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x152A);
    }
    return *(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C + 0x20);
}

/* Measured: 688/688 bytes and 16 fully resolved relocations.
 * Loop guards mask promoted counters independently of narrowed indexing;
 * the weighted random choice retains its unsigned-halfword boundary. */
// FUN_00243A30
u16 func_00243a30(u8 *arg0, s32 *arg1)
{
    u8 *entry;
    u16 result;
    s32 total;
    s32 count;
    s32 second_total;
    s32 i;
    u16 value;
    u8 *slot;
    u16 *field;

    if (!(*(u16 *)arg0 & 4)) {
        func_0046d730(D_00635938, 0x153F);
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x1540);
    }
    entry = iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C;
    result = 0;
    if (arg1 != 0) {
        *arg1 = 0;
    }
    if (*(u16 *)(entry + 0x34) != 0) {
        value = *(u16 *)(entry + 0x32);
        if (value != 0 && func_00106330(value) != 0 &&
            (s32)((func_003b7060() % 100U) & 0xFF) < (s32)*(u8 *)(entry + 0x36)) {
            result = *(u16 *)(entry + 0x34);
            if (arg1 != 0) {
                *arg1 = 1;
            }
        }
    }
    if (result == 0) {
        total = 0;
        i = 0;
        while ((i & 0xFFFF) < 4) {
            slot = entry + (u16)i * 4;
            value = *(u16 *)(slot + 0x22);
            if (value != 0 &&
                (value < 0x400 || value >= 0x500 ||
                 func_00106330(0x600 - value) == 0)) {
                total = (total + *(u8 *)(slot + 0x24)) & 0xFFFF;
            }
            i = (i + 1) & 0xFFFF;
        }
        count = total & 0xFFFF;
        if (count > 0 &&
            (s32)((func_003b7060() % 200U) & 0xFFFF) < count) {
            if (count == 0) {
                func_0046d730(D_00635938, 0x17);
            }
            total = (u16)(func_003b7060() % (u32)count);
            second_total = 0;
            i = 0;
            while ((i & 0xFFFF) < 4) {
                slot = entry + (u16)i * 4;
                field = (u16 *)(slot + 0x22);
                value = *field;
                if (value != 0 &&
                    (value < 0x400 || value >= 0x500 ||
                     func_00106330(0x600 - value) == 0)) {
                    second_total =
                        (second_total + *(u8 *)(slot + 0x24)) & 0xFFFF;
                    if (total < second_total) {
                        result = *field;
                        goto done;
                    }
                }
                i = (i + 1) & 0xFFFF;
            }
        }
    }
done:
    return result;
}

// FUN_00243CE0
s32 func_00243ce0(u8 *arg0)
{
    if (!(*(u16 *)arg0 & 4)) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x15C5);
    }
    if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 4) {
        return 1;
    }
    return 0;
}

// FUN_00243D80
s32 func_00243d80(u8 *arg0)
{
    s16 *b;

    if (!(*(u16 *)arg0 & 4)) {
        return 0;
    }
    if (*(u16 *)(arg0 + 2) >= 0x150) {
        func_0046d730(D_00635938, 0x15D2);
    }
    b = (s16 *)iGpffffb3cc;
    if (b[*(u16 *)(arg0 + 2) * 0x74 + 0xC] & 0x80) {
        return 1;
    }
    return 0;
}

// FUN_00243E30
s32 func_00243e30(u16 *arg0)
{
    return (s32)((*arg0 & 0x200) != 0);
}

// FUN_00243E50
void func_00243e50(u16 *arg0)
{
    *arg0 |= 0x200;
}

// FUN_00243E70
void func_00243e70(u16 *arg0)
{
    *arg0 &= 0xFDFF;
}

// FUN_00243E90
s32 func_00243e90(u8 *arg0)
{
    if (*(u16 *)(arg0 + 2) == 1) {
        return 4;
    }
    return *(s8 *)(arg0 + 0x10);
}

// FUN_00243EC0
void func_00243ec0(u8 *arg0, s8 arg1)
{
    arg0[0x10] = (u8)arg1;
}

// FUN_00243F20
void func_00243f20(u16 characterId)
{
    s16 id;
    s16 value;

    id = (s16)characterId;
    value = (s16)func_00104dc0(id);
    func_001056e0(id, value);
    value = (s16)func_00104e30(id);
    func_00105730(id, value);
    func_00105d50(id, -1);
}

/* measured: full body matches byte-for-byte (nd 0, no fndiff ! rows) but
   verify.py reports SIZE_MISMATCH: the window (368B, per
   tools/slus21782_functions.json) extends to 0x244110 and contains the
   unmarked nullsub at 0x244100 (jr $ra; nop; nop; nop), so the retail
   tail beyond my 352B object is nonzero. Fixed 2026-08-03: the src
   marker for the stub below IS a window boundary (per the
   p3-window-nullsub-discovery Case A procedure), so splitting the
   nullsub out in this file shrinks the window to 352B and this MATCHes. */
// FUN_00243FA0
s32 func_00243fa0(s32 arg0, s32 arg1)
{
    u16 var_17;
    s32 temp_19;
    s32 temp_3;
    s32 var_16;
    u32 temp_2;

    temp_19 = arg0 & 0xFFFF;
    if ((s32)((u32)arg0 & 0xFFFF) < 0 || temp_19 >= 0x240) {
        func_0046d730(D_00635938, 0x165A);
    }
    if (temp_19 >= 0x1B8) {
        func_0046d730(D_00635938, 0x165B);
    }
    temp_3 = arg1 & 0xFF;
    switch (temp_3) {
    case 1:
        var_17 = iGpffffb3b8[(u16)arg0 * 0x28 + 0x11];
        break;
    case 2:
        var_17 = iGpffffb3b8[(u16)arg0 * 0x28 + 0x14];
        break;
    default:
        func_0046d730(D_00635938, 0x1666);
        break;
    }
    var_16 = 1;
    temp_2 = (u16)var_17 & 0xFFFF;
    switch (temp_2) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 15:
        break;
    case 1:
    case 2:
    case 6:
    case 7:
    case 12:
    case 14:
    case 16:
        var_16 = 0;
        break;
    default:
        func_0046d730(D_00635938, 0x1682);
        break;
    }
    return var_16;
}
// FUN_00244100
void func_00244100(void)
{
}
