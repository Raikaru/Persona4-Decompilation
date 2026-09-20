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
extern s32 func_0010a900(u16 arg0);
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
extern s32 func_00235520(s32 arg0, u8 *arg1, u8 *arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7);
extern u32 func_002397d0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5);
extern u32 func_00106330(s32 arg0);
extern s32 func_00109980(s32 arg0, s32 arg1);
extern s64 func_00233570(u8 *arg0, s32 arg1, s64 arg2);
/* func_00241de0 passes a 5th arg (arg4) that func_00241bc0 ignores. */
extern s32 func_00241bc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00244f60(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
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
extern u8 func_00109bf0(u8 *arg0, s32 arg1);
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
        level = func_0010a900(*(u16 *)(arg0 + 2));
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

/* measured: daddiu return constants ARE reachable — u8 var_2 with
   `var_2 = 1;` / `var_2 = 0x63;` emits daddiu (s32 never does), the
   (s32)((u32)arg1 & 0xFFFF) guard gives bltz, and `temp_3 > 0x63` the
   slti-$at form; tail fully matches. Best nd 5: residual is the
   table-index load-sinking floor — retail lw's the iGpffffb3c4 base
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
        v = (u32)func_00109bf0((u8 *)(u32)*(u16 *)(arg0 + 2), arg1);
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
 * The unused third parameter is passed by each of those callers. */
#pragma push
#pragma opt_propagation off
f32 func_00233bc0(u8 *arg0, s32 arg1, s32 arg2)
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
/* measured 00235520 (owner, 2026-09-20): 22 u16 triple-cast sites all wrap integer */
/* (4 u16 loads/helpers at 1690/1691/1698/1699, 18 s16 loads at 2283-2719); no float-to-int, */
/* so u32 is neutral (probed 1690 triple to u32: 2784->2784 words, 12844B unchanged). */
/* deficit_scan on compilable body (10 phantom 3rd args removed per retail 2-arg jal, */
/* (DatUnit*) casts, local externs for 0023d6e0/00106a00): retail 3044 vs object 3211 */
/* (+5.5% OUTSIDE, deficit -167, 2784 reloc-masked words, obj 12844B/window 12176B). */
/* Three retail-only runs all CROSS, no ABSENT: 39 at 0x235610-0x2356ac (paired 2, nearby */
/* 2), 103 at 0x23587c-0x235a18 (paired 3, nearby 18), 49 at 0x236c98-0x236d5c (paired 1, */
/* nearby 3); object is not short, so missing-code work is wrong. Production stays ASM. */
// FUN_00235520 NONMATCHING
#ifdef SKIP_ASM
s32 func_00235520(s32 arg0, u8 *arg1, u8 *arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7) {
    extern f32 func_00233bc0(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 func_0023d6e0(s16 arg0);
    extern u16 func_00106a00(s16 arg0);
    extern f32 fGpffff82c0;
    extern f32 fGpffff82cc;
    extern f32 iGpffff8170;
    extern f32 fGpffff811c;
    extern f32 fGpffff809c;
    u16 spEE;
    u16 spEC;
    u16 spEA;
    s32 spE4;
    u8 spE3;
    u16 spD0;
    s32 spC0;
    f32 var_16;
    f32 var_16_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f1_8;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f20_4;
    f32 var_f21;
    f32 var_f22;
    f32 var_f23;
    f32 var_f24;
    s16 temp_18_10;
    s16 temp_18_16;
    s16 temp_18_17;
    s16 temp_18_23;
    s16 temp_18_24;
    s16 temp_18_2;
    s16 temp_18_3;
    s16 temp_18_9;
    s16 temp_21_12;
    s16 temp_21_13;
    s16 temp_21_17;
    s16 temp_21_18;
    s16 temp_21_2;
    s16 temp_21_3;
    s16 temp_21_7;
    s16 temp_21_8;
    s16 var_23;
    s32 temp_16_9;
    s32 temp_19;
    s32 temp_21_10;
    s32 temp_21_11;
    s32 temp_21_15;
    s32 temp_21_16;
    s32 temp_21_20;
    s32 temp_21_21;
    s32 temp_21_22;
    s32 temp_21_5;
    s32 temp_21_6;
    s32 temp_23;
    s32 temp_2_11;
    s32 temp_2_13;
    s32 temp_2_15;
    s32 temp_2_17;
    s32 temp_2_19;
    s32 temp_2_21;
    s32 temp_2_23;
    s32 temp_2_25;
    s32 temp_2_26;
    s32 temp_2_27;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_9;
    s32 temp_30;
    s32 temp_3_2;
    s32 var_19;
    s32 var_20;
    s32 var_2;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_19;
    s32 var_2_20;
    s32 var_2_21;
    s32 var_2_22;
    s32 var_2_23;
    s32 var_2_24;
    s32 var_2_25;
    s32 var_2_26;
    s32 var_2_27;
    s32 var_2_28;
    s32 var_2_29;
    s32 var_2_2;
    s32 var_2_30;
    s32 var_2_31;
    s32 var_2_32;
    s32 var_2_33;
    s32 var_2_34;
    s32 var_2_35;
    s32 var_2_36;
    s32 var_2_37;
    s32 var_2_38;
    s32 var_2_39;
    s32 var_2_3;
    s32 var_2_40;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    s32 var_6;
    s32 var_6_10;
    s32 var_6_2;
    s32 var_6_3;
    s32 var_6_4;
    s32 var_6_5;
    s32 var_6_6;
    s32 var_6_7;
    s32 var_6_8;
    s32 var_6_9;
    s64 temp_16_2;
    s64 temp_16_4;
    s64 temp_16_6;
    s64 temp_16_8;
    s64 temp_18;
    s64 temp_18_11;
    s64 temp_18_13;
    s64 temp_18_15;
    s64 temp_18_18;
    s64 temp_18_20;
    s64 temp_18_22;
    s64 temp_18_25;
    s64 temp_18_27;
    s64 temp_18_29;
    s64 temp_18_4;
    s64 temp_18_6;
    s64 temp_18_8;
    s64 temp_20;
    s64 temp_21;
    s64 temp_21_14;
    s64 temp_21_19;
    s64 temp_21_24;
    s64 temp_21_26;
    s64 temp_21_28;
    s64 temp_21_30;
    s64 temp_21_32;
    s64 temp_21_34;
    s64 temp_21_4;
    s64 temp_21_9;
    s32 temp_2_10;
    s32 temp_2_12;
    s32 temp_2_14;
    s32 temp_2_16;
    s32 temp_2_18;
    s32 temp_2_20;
    s32 temp_2_22;
    s32 temp_2_24;
    s32 temp_2_28;
    s32 temp_2_8;
    s64 temp_4;
    s64 temp_4_2;
    s64 var_21;
    u16 temp_16;
    u16 temp_16_3;
    u16 temp_16_5;
    u16 temp_16_7;
    u16 temp_18_12;
    u16 temp_18_14;
    u16 temp_18_19;
    u16 temp_18_21;
    u16 temp_18_26;
    u16 temp_18_28;
    u16 temp_18_5;
    u16 temp_18_7;
    u16 temp_21_23;
    u16 temp_21_25;
    u16 temp_21_27;
    u16 temp_21_29;
    u16 temp_21_31;
    u16 temp_21_33;
    u16 var_30;
    u32 temp_22;
    u8 temp_2_4;
    u8 temp_3;
    u8 temp_3_3;
    u8 var_22;
    u8 *temp_2;
    u8 *temp_2_2;

    var_21 = 0;
    var_22 = 0;
    var_23 = 0;
    spEE = arg3;
    spEC = arg4;
    spEA = arg5;
    spE4 = arg6;
    spE3 = arg7;
    temp_19 = arg0 & 0xFFFF;
    if ((temp_19 < 0) || (temp_19 >= 0x240)) {
        func_0046d730(D_00635938, 0x711);
    }
    if (temp_19 >= 0x1B8) {
        func_0046d730(D_00635938, 0x712);
    }
    var_f24 = 1.0f;
    var_f23 = 1.0f;
    var_f22 = 1.0f;
    var_f21 = 1.0f;
    var_20 = 0;
    var_19 = 0;
    var_30 = 0;
    spD0 = 0;
    spC0 = 1;
    if (spE3 != 2) {
        if (spE3 != spC0) {
            func_0046d730(D_00635938, 0x731);
        } else {
            temp_2 = (u8 *)(((arg0 & 0xFFFF) * 0x28) + (s32)iGpffffb3b8);
            var_23 = (s16)((s16)((s16)((*(s16 *)((u8 *)(temp_2) + (0x12))))));
            var_22 = (u8)((u8)((u8)((*(u8 *)((u8 *)(temp_2) + (0x11))))));
            var_21 = 0;
            var_30 = (u16)((u16)((u16)((*(u16 *)((u8 *)(arg2) + (8))))));
            spD0 = (u16)((u16)((u16)(func_00231f80((DatUnit *)arg2))));
        }
    } else {
        temp_2_2 = (u8 *)(((arg0 & 0xFFFF) * 0x28) + (s32)iGpffffb3b8);
        var_23 = (s16)((s16)((s16)((*(s16 *)((u8 *)(temp_2_2) + (0x16))))));
        var_22 = (u8)((u8)((u8)((*(u8 *)((u8 *)(temp_2_2) + (0x14))))));
        var_21 = 0;
        var_30 = (u16)((u16)((u16)((*(u16 *)((u8 *)(arg2) + (0xA))))));
            spD0 = (u16)((u16)((u16)(func_00232290((DatUnit *)arg2))));
    }
    temp_22 = var_22 & 0xFFFF;
    switch (temp_22) {                              /* switch 1 */
    case 5:                                         /* switch 1 */
        var_20 = ((s64) ((s64) var_23 << 0x30) >> 0x30) + ((s64) (var_21 << 0x30) >> 0x30);
        break;
    case 15:                                        /* switch 1 */
        temp_20 = (s64) ((s64) var_23 << 0x30) >> 0x30;
        if (temp_20 == 0) {
            func_0046d730(D_00635938, 0x17);
        }
        var_20 = (s32)((s32)((func_003b7060() % (u32) temp_20) + ((s64) (var_21 << 0x30) >> 0x30)));
        break;
    case 9:                                         /* switch 1 */
        var_20 = ((s32) ((var_30 & 0xFFFF) * ((s64) ((s64) var_23 << 0x30) >> 0x30)) / 100) + ((s64) (var_21 << 0x30) >> 0x30);
        if (var_20 <= 0) {
            var_20 = 1;
        }
        break;
    case 11:                                        /* switch 1 */
        var_20 = ((s32) (spD0 * ((s64) ((s64) var_23 << 0x30) >> 0x30)) / 100) + ((s64) (var_21 << 0x30) >> 0x30);
        if (var_20 <= 0) {
            var_20 = 1;
        }
        break;
    case 2:                                         /* switch 1 */
        temp_3 = (u8)((u8)((u8)((*(u8 *)((u8 *)((((arg0 & 0xFFFF) * 0x28) + (s32)iGpffffb3b8)) + (2))))));
        switch (temp_3) {                           /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            var_20 = (s32)((s32)((s32)(func_00244f60(1, arg1, arg2, arg0, spE3))));
            break;
        /* switch 2 */
            var_20 = (s32)((s32)((s32)(func_00244f60(3, arg1, arg2, arg0, spE3))));
            break;
        default:                                    /* switch 2 */
            func_0046d730(D_00635938, 0x75E);
            break;
        }
        var_20 += (s64) (var_21 << 0x30) >> 0x30;
        if (var_20 <= 0) {
            var_20 = 1;
        }
        spC0 = 0;
        break;
    case 7:                                         /* switch 1 */
        var_20 = ((s64) (var_21 << 0x30) >> 0x30) + 0x32;
        if (var_20 <= 0) {
            var_20 = 1;
        }
        spC0 = 0;
        break;
    case 4:                                         /* switch 1 */
    case 13:                                        /* switch 1 */
        var_19 = ((s64) ((s64) var_23 << 0x30) >> 0x30) + ((s64) (var_21 << 0x30) >> 0x30);
        if (temp_22 == 0xD) {
            temp_2_3 = var_30 & 0xFFFF;
            if (temp_2_3 < var_19) {
                var_19 = temp_2_3;
            }
        }
        break;
    case 8:                                         /* switch 1 */
        temp_4 = (s64) ((s64) var_23 << 0x30) >> 0x30;
        var_19 = ((s32) ((var_30 & 0xFFFF) * temp_4) / 100) + ((s64) (var_21 << 0x30) >> 0x30);
        if ((var_19 <= 0) && (temp_4 > 0)) {
            var_19 = 1;
        }
        break;
    case 10:                                        /* switch 1 */
        temp_4_2 = (s64) ((s64) var_23 << 0x30) >> 0x30;
        var_19 = ((s32) (spD0 * temp_4_2) / 100) + ((s64) (var_21 << 0x30) >> 0x30);
        if ((var_19 <= 0) && (temp_4_2 > 0)) {
            var_19 = 1;
        }
        break;
    /* switch 1 */
    case 12:                                        /* switch 1 */
    case 14:                                        /* switch 1 */
        temp_2_4 = (u8)((u8)((u8)((*(u8 *)((u8 *)((((arg0 & 0xFFFF) * 0x28) + (s32)iGpffffb3b8)) + (2))))));
        switch (temp_2_4) {                         /* switch 3; irregular */
        /* switch 3 */
            var_19 = (s32)((s32)((s32)(func_00244f60(1, arg1, arg2, arg0, spE3))));
            break;
        /* switch 3 */
            var_19 = (s32)((s32)((s32)(func_00244f60(2, arg1, arg2, arg0, spE3))));
            break;
        /* switch 3 */
            func_0046d730(D_00635938, 0x7A7);
            break;
        }
        var_19 += (s64) (var_21 << 0x30) >> 0x30;
        if ((temp_22 != 0xD) && (temp_22 != 0xC)) {

        } else {
            temp_2_5 = var_30 & 0xFFFF;
            if (temp_2_5 < var_19) {
                var_19 = temp_2_5;
            }
        }
        if ((temp_22 == 0xE) && ((s32) spEE >= 2)) {
            var_19 = var_19 / (s32) spEE;
        }
        if (var_19 <= 0) {
            var_19 = 1;
        }
        spC0 = 0;
        break;
    case 6:                                         /* switch 1 */
        var_19 = ((s64) (var_21 << 0x30) >> 0x30) + 0x32;
        if (var_19 <= 0) {
            var_19 = 1;
        }
        spC0 = 0;
        break;
    case 3:                                         /* switch 1 */
        temp_3_2 = ((s64) ((s64) var_23 << 0x30) >> 0x30) + ((s64) (var_21 << 0x30) >> 0x30);
        temp_2_6 = var_30 & 0xFFFF;
        if (temp_3_2 < temp_2_6) {
            var_19 = temp_2_6 - temp_3_2;
        }
        break;
    case 16:                                        /* switch 1 */
        var_19 = (s32)((s32)((s32)(func_00244f60(9, arg1, arg2, arg0, spE3) + ((s64) (var_21 << 0x30) >> 0x30))));
        if (var_19 <= 0) {
            var_19 = 1;
        }
        spC0 = 0;
        break;
    /* switch 1 */
        func_0046d730(D_00635938, 0x7DE);
        break;
    }
    if ((spC0 == 0) && (var_19 > 0) && !(spE4 & 1)) {
        temp_21 = (s64)((s64)((s64) (func_0023d8e0(arg1, arg0) << 0x30) >> 0x30));
        temp_30 = (s32)((s32)(func_0023d6e0(temp_21)));
        temp_23 = (arg0 & 0xFFFF) * 0x28;
        temp_3_3 = (u8)((u8)((u8)((*(u8 *)((u8 *)((temp_23 + (s32)iGpffffb3b8)) + (2))))));
        switch (temp_3_3) {                         /* switch 4; irregular */
        case 1:                                     /* switch 4 */
            if (temp_22 != 0x10) {
                var_f24 = func_00233bc0(arg1, 0, arg0);
            }
            var_f23 = func_00233bc0(arg2, 3, arg0);
            if (temp_22 != 0x10) {
                (*(s32 *)((u8 *)(arg1) + (0x18))) = (s32)((s32)((s32) ((*(s32 *)((u8 *)(arg1) + (0x18))) | 0x40000)));
            }
            break;
        case 2:                                     /* switch 4 */
            if (temp_22 != 0x10) {
                var_f24 = func_00233bc0(arg1, 1, arg0);
            }
            var_f23 = func_00233bc0(arg2, 3, arg0);
            if (temp_22 != 0x10) {
                (*(s32 *)((u8 *)(arg1) + (0x18))) = (s32)((s32)((s32) ((*(s32 *)((u8 *)(arg1) + (0x18))) | 0x80000)));
            }
            break;
        default:                                    /* switch 4 */
            func_0046d730(D_00635938, 0x803);
            break;
        }
        temp_18 = (s64) (temp_21 << 0x30) >> 0x30;
        switch (temp_18) {                          /* switch 5; irregular */
        case 1:                                     /* switch 5 */
            var_f20 = 1.0f;
            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                var_2 = 0;
            } else {
                temp_21_2 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                if (temp_21_2 >= 0xB) {
                    func_0046d730(D_00635938, 0x291);
                }
                var_2 = (s32)((s32)(func_001069d0(func_00106cd0(temp_21_2, 2)) & 0xFFFF));
            }
            if ((var_2 & 0xFFFF) == 0xBD) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_f1 = 0.0f;
                } else {
                    temp_21_3 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                    if (temp_21_3 >= 0xB) {
                        func_0046d730(D_00635938, 0x2A7);
                    }
                    temp_21_4 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_21_3, 2)) << 0x30) >> 0x30));
                    if ((temp_21_4 < 0) || (temp_21_4 >= 0x65)) {
                        func_0046d730(D_00635938, 0x2AB);
                    }
                    var_f1 = (f32) temp_21_4 / 100.0f;
                }
                var_f20 = 1.0f * (1.0f + var_f1);
            }
            temp_21_5 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_7 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6 = 0;
loop_107:
            if ((var_6 & 0xFFFF) >= (temp_21_5 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_8 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_8 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_8))) == (s32)((s32)(0x1E7)))) {
                    var_2_2 = 1;
                } else {
                    var_2_2 = 0;
                }
            } else if (*((u8 *)(temp_2_7 + ((var_6 & 0xFFFF) * 2))) == 0x1E7) {
                var_2_2 = 1;
            } else {
                var_6 = (var_6 + 1) & 0xFFFF;
                goto loop_107;
            }
            if (var_2_2 == 0) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_2_3 = 0;
                } else {
                    var_2_3 = (s32)((s32)((s32)(func_00232880((s64) (u16) (*(s16 *)((u8 *)(arg1) + (2))), 0x44))));
                }
                if (var_2_3 & 0xFFFF) {
                    goto block_118;
                }
            } else {
block_118:
                var_f20 *= 1.25f;
            }
            temp_21_6 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_9 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_2 = 0;
loop_123:
            if ((var_6_2 & 0xFFFF) >= (temp_21_6 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_10 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_10 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_10))) == (s32)((s32)(0x1E8)))) {
                    var_2_4 = 1;
                } else {
                    var_2_4 = 0;
                }
            } else if (*((u8 *)(temp_2_9 + ((var_6_2 & 0xFFFF) * 2))) == 0x1E8) {
                var_2_4 = 1;
            } else {
                var_6_2 = (var_6_2 + 1) & 0xFFFF;
                goto loop_123;
            }
            if (var_2_4 != 0) {
                var_f20 *= 1.5f;
            }
            if (!(var_f20 <= 1.875f)) {
                var_f20 = 1.875f;
            }
            var_f21 = 1.0f * var_f20;
            if ((s32)((s32)(func_00106330(0x1435))) != (s32)((s32)(0))) {
                if ((s32)((s32)(func_00106330(0x15C5))) != (s32)((s32)(0))) {
                    var_f21 *= 2.0f;
                } else {
                    var_f21 *= (f32)(s32)(0.05f);
                }
            }
            break;
        case 2:                                     /* switch 5 */
            var_f20_2 = 1.0f;
            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                var_2_5 = 0;
            } else {
                temp_21_7 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                if (temp_21_7 >= 0xB) {
                    func_0046d730(D_00635938, 0x291);
                }
                var_2_5 = (s32)((s32)(func_001069d0(func_00106cd0(temp_21_7, 2)) & 0xFFFF));
            }
            if ((var_2_5 & 0xFFFF) == 0xBE) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_f1_2 = 0.0f;
                } else {
                    temp_21_8 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                    if (temp_21_8 >= 0xB) {
                        func_0046d730(D_00635938, 0x2A7);
                    }
                    temp_21_9 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_21_8, 2)) << 0x30) >> 0x30));
                    if ((temp_21_9 < 0) || (temp_21_9 >= 0x65)) {
                        func_0046d730(D_00635938, 0x2AB);
                    }
                    var_f1_2 = (f32) temp_21_9 / 100.0f;
                }
                var_f20_2 = 1.0f * (1.0f + var_f1_2);
            }
            temp_21_10 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_11 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_3 = 0;
loop_156:
            if ((var_6_3 & 0xFFFF) >= (temp_21_10 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_12 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_12 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_12))) == (s32)((s32)(0x1E9)))) {
                    var_2_6 = 1;
                } else {
                    var_2_6 = 0;
                }
            } else if (*((u8 *)(temp_2_11 + ((var_6_3 & 0xFFFF) * 2))) == 0x1E9) {
                var_2_6 = 1;
            } else {
                var_6_3 = (var_6_3 + 1) & 0xFFFF;
                goto loop_156;
            }
            if (var_2_6 == 0) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_2_7 = 0;
                } else {
                    var_2_7 = (s32)((s32)((s32)(func_00232880((s64) (u16) (*(s16 *)((u8 *)(arg1) + (2))), 0x45))));
                }
                if (var_2_7 & 0xFFFF) {
                    goto block_167;
                }
            } else {
block_167:
                var_f20_2 *= 1.25f;
            }
            temp_21_11 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_13 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_4 = 0;
loop_172:
            if ((var_6_4 & 0xFFFF) >= (temp_21_11 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_14 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_14 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_14))) == (s32)((s32)(0x1EA)))) {
                    var_2_8 = 1;
                } else {
                    var_2_8 = 0;
                }
            } else if (*((u8 *)(temp_2_13 + ((var_6_4 & 0xFFFF) * 2))) == 0x1EA) {
                var_2_8 = 1;
            } else {
                var_6_4 = (var_6_4 + 1) & 0xFFFF;
                goto loop_172;
            }
            if (var_2_8 != 0) {
                var_f20_2 *= 1.5f;
            }
            if (!(var_f20_2 <= 1.875f)) {
                var_f20_2 = 1.875f;
            }
            var_f21 = 1.0f * var_f20_2;
            if ((s32)((s32)(func_00106330(0x1435))) != (s32)((s32)(0))) {
                if ((s32)((s32)(func_00106330(0x15C6))) != (s32)((s32)(0))) {
                    var_f21 *= 2.0f;
                } else {
                    var_f21 *= (f32)(s32)(0.05f);
                }
            }
            break;
        case 3:                                     /* switch 5 */
            var_f20_3 = 1.0f;
            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                var_2_9 = 0;
            } else {
                temp_21_12 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                if (temp_21_12 >= 0xB) {
                    func_0046d730(D_00635938, 0x291);
                }
                var_2_9 = (s32)((s32)(func_001069d0(func_00106cd0(temp_21_12, 2)) & 0xFFFF));
            }
            if ((var_2_9 & 0xFFFF) == 0xC0) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_f1_3 = 0.0f;
                } else {
                    temp_21_13 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                    if (temp_21_13 >= 0xB) {
                        func_0046d730(D_00635938, 0x2A7);
                    }
                    temp_21_14 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_21_13, 2)) << 0x30) >> 0x30));
                    if ((temp_21_14 < 0) || (temp_21_14 >= 0x65)) {
                        func_0046d730(D_00635938, 0x2AB);
                    }
                    var_f1_3 = (f32) temp_21_14 / 100.0f;
                }
                var_f20_3 = 1.0f * (1.0f + var_f1_3);
            }
            temp_21_15 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_15 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_5 = 0;
loop_205:
            if ((var_6_5 & 0xFFFF) >= (temp_21_15 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_16 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_16 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_16))) == (s32)((s32)(0x1EB)))) {
                    var_2_10 = 1;
                } else {
                    var_2_10 = 0;
                }
            } else if (*((u8 *)(temp_2_15 + ((var_6_5 & 0xFFFF) * 2))) == 0x1EB) {
                var_2_10 = 1;
            } else {
                var_6_5 = (var_6_5 + 1) & 0xFFFF;
                goto loop_205;
            }
            if (var_2_10 == 0) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_2_11 = 0;
                } else {
                    var_2_11 = (s32)((s32)((s32)(func_00232880((s64) (u16) (*(s16 *)((u8 *)(arg1) + (2))), 0x46))));
                }
                if (var_2_11 & 0xFFFF) {
                    goto block_216;
                }
            } else {
block_216:
                var_f20_3 *= 1.25f;
            }
            temp_21_16 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_17 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_6 = 0;
loop_221:
            if ((var_6_6 & 0xFFFF) >= (temp_21_16 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_18 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_18 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_18))) == (s32)((s32)(0x1EC)))) {
                    var_2_12 = 1;
                } else {
                    var_2_12 = 0;
                }
            } else if (*((u8 *)(temp_2_17 + ((var_6_6 & 0xFFFF) * 2))) == 0x1EC) {
                var_2_12 = 1;
            } else {
                var_6_6 = (var_6_6 + 1) & 0xFFFF;
                goto loop_221;
            }
            if (var_2_12 != 0) {
                var_f20_3 *= 1.5f;
            }
            if (!(var_f20_3 <= 1.875f)) {
                var_f20_3 = 1.875f;
            }
            var_f21 = 1.0f * var_f20_3;
            if ((s32)((s32)(func_00106330(0x1435))) != (s32)((s32)(0))) {
                if ((s32)((s32)(func_00106330(0x15C8))) != (s32)((s32)(0))) {
                    var_f21 *= 2.0f;
                } else {
                    var_f21 *= (f32)(s32)(0.05f);
                }
            }
            break;
        case 4:                                     /* switch 5 */
            var_f20_4 = 1.0f;
            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                var_2_13 = 0;
            } else {
                temp_21_17 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                if (temp_21_17 >= 0xB) {
                    func_0046d730(D_00635938, 0x291);
                }
                var_2_13 = (s32)((s32)(func_001069d0(func_00106cd0(temp_21_17, 2)) & 0xFFFF));
            }
            if ((var_2_13 & 0xFFFF) == 0xBF) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_f1_4 = 0.0f;
                } else {
                    temp_21_18 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg1) + (2))))));
                    if (temp_21_18 >= 0xB) {
                        func_0046d730(D_00635938, 0x2A7);
                    }
                    temp_21_19 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_21_18, 2)) << 0x30) >> 0x30));
                    if ((temp_21_19 < 0) || (temp_21_19 >= 0x65)) {
                        func_0046d730(D_00635938, 0x2AB);
                    }
                    var_f1_4 = (f32) temp_21_19 / 100.0f;
                }
                var_f20_4 = 1.0f * (1.0f + var_f1_4);
            }
            temp_21_20 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_19 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_7 = 0;
loop_254:
            if ((var_6_7 & 0xFFFF) >= (temp_21_20 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_20 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_20 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_20))) == (s32)((s32)(0x1ED)))) {
                    var_2_14 = 1;
                } else {
                    var_2_14 = 0;
                }
            } else if (*((u8 *)(temp_2_19 + ((var_6_7 & 0xFFFF) * 2))) == 0x1ED) {
                var_2_14 = 1;
            } else {
                var_6_7 = (var_6_7 + 1) & 0xFFFF;
                goto loop_254;
            }
            if (var_2_14 == 0) {
                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                    var_2_15 = 0;
                } else {
                    var_2_15 = (s32)((s32)((s32)(func_00232880((s64) (u16) (*(s16 *)((u8 *)(arg1) + (2))), 0x47))));
                }
                if (var_2_15 & 0xFFFF) {
                    goto block_265;
                }
            } else {
block_265:
                var_f20_4 *= 1.25f;
            }
            temp_21_21 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
            temp_2_21 = (s32)((s32)((s32)(func_0023e140(arg1))));
            var_6_8 = 0;
loop_270:
            if ((var_6_8 & 0xFFFF) >= (temp_21_21 & 0xFFFF)) {
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_22 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_22 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_22))) == (s32)((s32)(0x1EE)))) {
                    var_2_16 = 1;
                } else {
                    var_2_16 = 0;
                }
            } else if (*((u8 *)(temp_2_21 + ((var_6_8 & 0xFFFF) * 2))) == 0x1EE) {
                var_2_16 = 1;
            } else {
                var_6_8 = (var_6_8 + 1) & 0xFFFF;
                goto loop_270;
            }
            if (var_2_16 != 0) {
                var_f20_4 *= 1.5f;
            }
            if (!(var_f20_4 <= 1.875f)) {
                var_f20_4 = 1.875f;
            }
            var_f21 = 1.0f * var_f20_4;
            if ((s32)((s32)(func_00106330(0x1435))) != (s32)((s32)(0))) {
                if ((s32)((s32)(func_00106330(0x15C7))) != (s32)((s32)(0))) {
                    var_f21 *= 2.0f;
                } else {
                    var_f21 *= (f32)(s32)(0.05f);
                }
            }
            break;
        }
        temp_21_22 = (s32)((s32)((s32)(func_0023e130(arg2) & 0xFFFF)));
        temp_2_23 = (s32)((s32)((s32)(func_0023e140(arg2))));
        var_6_9 = 0;
loop_288:
        if ((var_6_9 & 0xFFFF) >= (temp_21_22 & 0xFFFF)) {
            if (!((*(u16 *)((u8 *)(arg2) + (0))) & 4) && (temp_2_24 = func_00106cd0((*(s16 *)((u8 *)(arg2) + (2))), 2) & 0xFFFF, (temp_2_24 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_24))) == (s32)((s32)(0x209)))) {
                var_2_17 = 1;
            } else {
                var_2_17 = 0;
            }
        } else if (*((u8 *)(temp_2_23 + ((var_6_9 & 0xFFFF) * 2))) == 0x209) {
            var_2_17 = 1;
        } else {
            var_6_9 = (var_6_9 + 1) & 0xFFFF;
            goto loop_288;
        }
        if (var_2_17 != 0) {
            var_f21 *= 0.5f;
        }
        if ((s32)((s32)(func_00106330(0x1011))) != (s32)((s32)(0))) {
            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                var_f24 *= 1.5f;
            }
        } else if (((s32)((s32)(func_00106330(0x1010))) != (s32)((s32)(0))) && ((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
            var_f24 *= (f32)(s32)(iGpffff8170);
        }
        if (spEA == 2) {
            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                var_f24 *= (f32)(s32)(1.6f);
            } else {
                var_f24 *= (f32)(s32)(1.3f);
            }
        }
        if ((s32)((s32)(func_00243e30(arg2))) != (s32)((s32)(0))) {
            var_f23 *= (f32)(s32)(fGpffff82cc);
        }
        temp_2_25 = (s32)((s32)((s32)((*(s32 *)((u8 *)(arg2) + (0xC))))));
        if (temp_2_25 & 0x100000) {
            var_f22 = 1.0f * 1.25f;
        }
        if ((temp_30 & 2) && ((*(s32 *)((u8 *)(arg1) + (0xC))) & 0x20)) {
            var_f22 *= 0.5f;
        }
        if ((*(s32 *)((u8 *)(arg1) + (0xC))) & 2) {
            var_f22 *= 2.0f;
        }
        if (temp_2_25 & 0x40) {
            var_f22 *= 1.5f;
        } else if (temp_2_25 & 2) {
            var_f22 *= 2.0f;
        }
        if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
            if ((s32)((s32)((s32) (u16) (*(s16 *)((u8 *)(arg1) + (2))))) >= (s32)((s32)(0x150))) {
                func_0046d730(D_00635938, 0x8C0);
            }
            if (*((u8 *)((s32)iGpffffb3c4 + ((u16) (*(s16 *)((u8 *)(arg1) + (2))) * 0x3C))) & 0x20) {
                var_f24 *= 0.75f;
            }
        }
        if ((*(u8 *)((u8 *)((temp_23 + (s32)iGpffffb3b8)) + (0x24))) != 3) {

        } else if ((*(s32 *)((u8 *)(arg2) + (0xC))) & 0x100000) {
            var_f24 *= 2.0f;
        }
        temp_2_26 = (s32)((s32)((s32)((*(u16 *)((u8 *)(arg2) + (0))) & 4)));
        if (temp_2_26 == 0) {
            if (temp_18 != 0) {

            } else {
                if (temp_2_26 != 0) {
                    var_2_18 = 0;
                } else {
                    temp_21_23 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_23 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_24 = (s64) ((s64) temp_21_23 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_24, 0)) & 0xFFFF))) == (s32)((s32)(0x5F))) {
                        var_2_18 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_24, 1)) & 0xFFFF))) == (s32)((s32)(0x5F))) {
                        var_2_18 = 1;
                    } else {
                        var_2_18 = 0;
                    }
                }
                if (var_2_18 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_19 = 0;
                } else {
                    temp_21_25 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_25 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_26 = (s64) ((s64) temp_21_25 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_26, 0)) & 0xFFFF))) == (s32)((s32)(0x60))) {
                        var_2_19 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_26, 1)) & 0xFFFF))) == (s32)((s32)(0x60))) {
                        var_2_19 = 1;
                    } else {
                        var_2_19 = 0;
                    }
                }
                if (var_2_19 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_20 = 0;
                } else {
                    temp_21_27 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_27 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_28 = (s64) ((s64) temp_21_27 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_28, 0)) & 0xFFFF))) == (s32)((s32)(0x61))) {
                        var_2_20 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_28, 1)) & 0xFFFF))) == (s32)((s32)(0x61))) {
                        var_2_20 = 1;
                    } else {
                        var_2_20 = 0;
                    }
                }
                if (var_2_20 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
            }
            if ((temp_18 != 4) && (temp_18 != 3) && (temp_18 != 2) && (temp_18 != 1)) {

            } else {
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_21 = 0;
                } else {
                    temp_21_29 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_29 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_30 = (s64) ((s64) temp_21_29 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_30, 0)) & 0xFFFF))) == (s32)((s32)(0x6E))) {
                        var_2_21 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_30, 1)) & 0xFFFF))) == (s32)((s32)(0x6E))) {
                        var_2_21 = 1;
                    } else {
                        var_2_21 = 0;
                    }
                }
                if (var_2_21 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_22 = 0;
                } else {
                    temp_21_31 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_31 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_32 = (s64) ((s64) temp_21_31 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_32, 0)) & 0xFFFF))) == (s32)((s32)(0x6F))) {
                        var_2_22 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_32, 1)) & 0xFFFF))) == (s32)((s32)(0x6F))) {
                        var_2_22 = 1;
                    } else {
                        var_2_22 = 0;
                    }
                }
                if (var_2_22 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_23 = 0;
                } else {
                    temp_21_33 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_21_33 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_21_34 = (s64) ((s64) temp_21_33 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_34, 0)) & 0xFFFF))) == (s32)((s32)(0x70))) {
                        var_2_23 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_21_34, 1)) & 0xFFFF))) == (s32)((s32)(0x70))) {
                        var_2_23 = 1;
                    } else {
                        var_2_23 = 0;
                    }
                }
                if (var_2_23 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
            }
            switch (temp_18) {                      /* switch 6; irregular */
            case 1:                                 /* switch 6 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_24 = 0;
                } else {
                    temp_18_2 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                    if (temp_18_2 >= 0xB) {
                        func_0046d730(D_00635938, 0x291);
                    }
                    var_2_24 = (s32)((s32)(func_001069d0(func_00106cd0(temp_18_2, 2)) & 0xFFFF));
                }
                if ((var_2_24 & 0xFFFF) == 0xC1) {
                    if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                        var_f1_5 = 0.0f;
                    } else {
                        temp_18_3 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                        if (temp_18_3 >= 0xB) {
                            func_0046d730(D_00635938, 0x2A7);
                        }
                        temp_18_4 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_18_3, 2)) << 0x30) >> 0x30));
                        if ((temp_18_4 < 0) || (temp_18_4 >= 0x65)) {
                            func_0046d730(D_00635938, 0x2AB);
                        }
                        var_f1_5 = (f32) temp_18_4 / 100.0f;
                    }
                    var_f24 *= 1.0f - var_f1_5;
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_25 = 0;
                } else {
                    temp_18_5 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_5 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_6 = (s64) ((s64) temp_18_5 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_6, 0)) & 0xFFFF))) == (s32)((s32)(0x62))) {
                        var_2_25 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_6, 1)) & 0xFFFF))) == (s32)((s32)(0x62))) {
                        var_2_25 = 1;
                    } else {
                        var_2_25 = 0;
                    }
                }
                if (var_2_25 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_26 = 0;
                } else {
                    temp_18_7 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_7 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_8 = (s64) ((s64) temp_18_7 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_8, 0)) & 0xFFFF))) == (s32)((s32)(0x63))) {
                        var_2_26 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_8, 1)) & 0xFFFF))) == (s32)((s32)(0x63))) {
                        var_2_26 = 1;
                    } else {
                        var_2_26 = 0;
                    }
                }
                if (var_2_26 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_27 = 0;
                } else {
                    temp_16 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_16 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_16_2 = (s64) ((s64) temp_16 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_2, 0)) & 0xFFFF))) == (s32)((s32)(0x64))) {
                        var_2_27 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_2, 1)) & 0xFFFF))) == (s32)((s32)(0x64))) {
                        var_2_27 = 1;
                    } else {
                        var_2_27 = 0;
                    }
                }
                if (var_2_27 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
                break;
            case 2:                                 /* switch 6 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_28 = 0;
                } else {
                    temp_18_9 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                    if (temp_18_9 >= 0xB) {
                        func_0046d730(D_00635938, 0x291);
                    }
                    var_2_28 = (s32)((s32)(func_001069d0(func_00106cd0(temp_18_9, 2)) & 0xFFFF));
                }
                if ((var_2_28 & 0xFFFF) == 0xC2) {
                    if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                        var_f1_6 = 0.0f;
                    } else {
                        temp_18_10 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                        if (temp_18_10 >= 0xB) {
                            func_0046d730(D_00635938, 0x2A7);
                        }
                        temp_18_11 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_18_10, 2)) << 0x30) >> 0x30));
                        if ((temp_18_11 < 0) || (temp_18_11 >= 0x65)) {
                            func_0046d730(D_00635938, 0x2AB);
                        }
                        var_f1_6 = (f32) temp_18_11 / 100.0f;
                    }
                    var_f24 *= 1.0f - var_f1_6;
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_29 = 0;
                } else {
                    temp_18_12 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_12 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_13 = (s64) ((s64) temp_18_12 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_13, 0)) & 0xFFFF))) == (s32)((s32)(0x65))) {
                        var_2_29 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_13, 1)) & 0xFFFF))) == (s32)((s32)(0x65))) {
                        var_2_29 = 1;
                    } else {
                        var_2_29 = 0;
                    }
                }
                if (var_2_29 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_30 = 0;
                } else {
                    temp_18_14 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_14 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_15 = (s64) ((s64) temp_18_14 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_15, 0)) & 0xFFFF))) == (s32)((s32)(0x66))) {
                        var_2_30 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_15, 1)) & 0xFFFF))) == (s32)((s32)(0x66))) {
                        var_2_30 = 1;
                    } else {
                        var_2_30 = 0;
                    }
                }
                if (var_2_30 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_31 = 0;
                } else {
                    temp_16_3 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_16_3 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_16_4 = (s64) ((s64) temp_16_3 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_4, 0)) & 0xFFFF))) == (s32)((s32)(0x67))) {
                        var_2_31 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_4, 1)) & 0xFFFF))) == (s32)((s32)(0x67))) {
                        var_2_31 = 1;
                    } else {
                        var_2_31 = 0;
                    }
                }
                if (var_2_31 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
                break;
            case 3:                                 /* switch 6 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_32 = 0;
                } else {
                    temp_18_16 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                    if (temp_18_16 >= 0xB) {
                        func_0046d730(D_00635938, 0x291);
                    }
                    var_2_32 = (s32)((s32)(func_001069d0(func_00106cd0(temp_18_16, 2)) & 0xFFFF));
                }
                if ((var_2_32 & 0xFFFF) == 0xC4) {
                    if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                        var_f1_7 = 0.0f;
                    } else {
                        temp_18_17 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                        if (temp_18_17 >= 0xB) {
                            func_0046d730(D_00635938, 0x2A7);
                        }
                        temp_18_18 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_18_17, 2)) << 0x30) >> 0x30));
                        if ((temp_18_18 < 0) || (temp_18_18 >= 0x65)) {
                            func_0046d730(D_00635938, 0x2AB);
                        }
                        var_f1_7 = (f32) temp_18_18 / 100.0f;
                    }
                    var_f24 *= 1.0f - var_f1_7;
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_33 = 0;
                } else {
                    temp_18_19 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_19 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_20 = (s64) ((s64) temp_18_19 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_20, 0)) & 0xFFFF))) == (s32)((s32)(0x6B))) {
                        var_2_33 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_20, 1)) & 0xFFFF))) == (s32)((s32)(0x6B))) {
                        var_2_33 = 1;
                    } else {
                        var_2_33 = 0;
                    }
                }
                if (var_2_33 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_34 = 0;
                } else {
                    temp_18_21 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_21 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_22 = (s64) ((s64) temp_18_21 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_22, 0)) & 0xFFFF))) == (s32)((s32)(0x6C))) {
                        var_2_34 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_22, 1)) & 0xFFFF))) == (s32)((s32)(0x6C))) {
                        var_2_34 = 1;
                    } else {
                        var_2_34 = 0;
                    }
                }
                if (var_2_34 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_35 = 0;
                } else {
                    temp_16_5 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_16_5 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_16_6 = (s64) ((s64) temp_16_5 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_6, 0)) & 0xFFFF))) == (s32)((s32)(0x6D))) {
                        var_2_35 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_6, 1)) & 0xFFFF))) == (s32)((s32)(0x6D))) {
                        var_2_35 = 1;
                    } else {
                        var_2_35 = 0;
                    }
                }
                if (var_2_35 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
                break;
            case 4:                                 /* switch 6 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_36 = 0;
                } else {
                    temp_18_23 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                    if (temp_18_23 >= 0xB) {
                        func_0046d730(D_00635938, 0x291);
                    }
                    var_2_36 = (s32)((s32)(func_001069d0(func_00106cd0(temp_18_23, 2)) & 0xFFFF));
                }
                if ((var_2_36 & 0xFFFF) == 0xC3) {
                    if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                        var_f1_8 = 0.0f;
                    } else {
                        temp_18_24 = (s16)((s16)((s16)((*(s16 *)((u8 *)(arg2) + (2))))));
                        if (temp_18_24 >= 0xB) {
                            func_0046d730(D_00635938, 0x2A7);
                        }
                        temp_18_25 = (s64)((s64)((s64) (func_00106a00(func_00106cd0(temp_18_24, 2)) << 0x30) >> 0x30));
                        if ((temp_18_25 < 0) || (temp_18_25 >= 0x65)) {
                            func_0046d730(D_00635938, 0x2AB);
                        }
                        var_f1_8 = (f32) temp_18_25 / 100.0f;
                    }
                    var_f24 *= 1.0f - var_f1_8;
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_37 = 0;
                } else {
                    temp_18_26 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_26 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_27 = (s64) ((s64) temp_18_26 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_27, 0)) & 0xFFFF))) == (s32)((s32)(0x68))) {
                        var_2_37 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_27, 1)) & 0xFFFF))) == (s32)((s32)(0x68))) {
                        var_2_37 = 1;
                    } else {
                        var_2_37 = 0;
                    }
                }
                if (var_2_37 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff82c0);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_38 = 0;
                } else {
                    temp_18_28 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_18_28 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_18_29 = (s64) ((s64) temp_18_28 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_29, 0)) & 0xFFFF))) == (s32)((s32)(0x69))) {
                        var_2_38 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_18_29, 1)) & 0xFFFF))) == (s32)((s32)(0x69))) {
                        var_2_38 = 1;
                    } else {
                        var_2_38 = 0;
                    }
                }
                if (var_2_38 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff811c);
                }
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                    var_2_39 = 0;
                } else {
                    temp_16_7 = (u16)((u16)((u16) (*(s16 *)((u8 *)(arg2) + (2)))));
                    if ((s32) temp_16_7 >= 0xB) {
                        func_0046d730(D_00635938, 0x23B);
                    }
                    temp_16_8 = (s64) ((s64) temp_16_7 << 0x30) >> 0x30;
                    if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_8, 0)) & 0xFFFF))) == (s32)((s32)(0x6A))) {
                        var_2_39 = 1;
                    } else if ((s32)((s32)((func_001069d0(func_00106cd0((s16) temp_16_8, 1)) & 0xFFFF))) == (s32)((s32)(0x6A))) {
                        var_2_39 = 1;
                    } else {
                        var_2_39 = 0;
                    }
                }
                if (var_2_39 != 0) {
                    var_f24 *= (f32)(s32)(fGpffff809c);
                }
                break;
            }
        }
        var_16 = var_f21 * (var_f22 * (var_f23 * ((f32) var_19 * var_f24)));
        if (spEA == 0x10) {
            var_19 = 0x1F4;
        } else {
            if ((s32)( var_16) >= 0x7919) {
                var_16 = 4.344e-41f;
            } else if ((s32)( var_16) <= 0) {
                var_16 = 1e-45f;
            }
            var_19 = (s32)((s32)((s32) ((u32) ((s32)( var_16) * ((func_003b7060() % 11U) + 0x5F)) / 100U)));
        }
        if (var_19 <= 0) {
            var_19 = 1;
        }
    }
    if ((spC0 == 0) && (var_20 > 0) && !(spE4 & 1)) {
        temp_16_9 = (s32)((s32)((s32)(func_0023e130(arg1) & 0xFFFF)));
        temp_2_27 = (s32)((s32)((s32)(func_0023e140(arg1))));
        var_6_10 = 0;
loop_615:
        if ((var_6_10 & 0xFFFF) >= (temp_16_9 & 0xFFFF)) {
            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_28 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_28 >= 0)) && ((s32)((s32)(func_001069a0((s16)temp_2_28))) == (s32)((s32)(0x20E)))) {
                var_2_40 = 1;
            } else {
                var_2_40 = 0;
            }
        } else if (*((u8 *)(temp_2_27 + ((var_6_10 & 0xFFFF) * 2))) == 0x20E) {
            var_2_40 = 1;
        } else {
            var_6_10 = (var_6_10 + 1) & 0xFFFF;
            goto loop_615;
        }
        if (var_2_40 != 0) {
            var_f21 *= 1.5f;
        }
        var_16_2 = var_f21 * (var_f22 * (var_f23 * ((f32) var_20 * var_f24)));
        if ((s32)( var_16_2) >= 0x7919) {
            var_16_2 = 4.344e-41f;
        } else if ((s32)( var_16_2) <= 0) {
            var_16_2 = 1e-45f;
        }
        var_20 = (s32)((s32)((s32) ((u32) ((s32)( var_16_2) * ((func_003b7060() % 11U) + 0x5F)) / 100U)));
        if (var_20 <= 0) {
            var_20 = 1;
        }
    }
    if ((spEC == 0x400) && (var_19 > 0)) {
        var_20 = var_19;
        var_19 = 0;
    }
    if ((spEC != 4) && (spEC != 2) && (spEC != 0x100)) {

    } else {
        var_20 = 0;
        var_19 = 0;
    }
    if (var_19 > 0) {
        var_20 = -var_19;
    }
    return var_20;
}
#else
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235520);
#endif

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
            temp_2_2 = func_0010a900(temp_4);
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
            temp_2_5 = func_0010a900(temp_4_2);
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

/* measured: fndiff 765 words (reloc-masked), fnalign 579 edits (plus 10 reloc-only), obj 909 instrs / retail 931 instrs (window 3728B, -22, -2.4% inside 3% gate). Recipe in order on top of /tmp/final_238940_body.c (s64 fresh 844 words / 652 edits at 971/932): s32 clean 844->801 / 652->605; scoped loopinv 801->784 / 605->585; head split (u16)arg0 vs (arg0&0xFFFF) 784->769 / 585->580 (both-u16 784 tie via CSE to one, reuse temp_16 784->792 +8 rejected); shared vs fresh tie 801/605 no-pragma and 783/575 vs 784/585 with loopinv (fresh neutral here, unlike 242990 172->68); u16 skill loads 768->765 for 0x216-0x220 (u8 never equals, always false); pick u16 keeps lhu vs lh (tie); s16 var21/var5/temp3/var6s all tie/worse (765 tie, 767 +2). Frame 0xB0 vs retail 0xD0 (arr sp+0x90 vs sp+0xA0) and 7 vs 9 saves ($s7 limits, $23) still shift tail, as prior nd-792 note. m2c s64 WRONG (arg0 s32 per andi/slti 0x240 + sll2/addu/sll3 stride, s32 return per matched callers) preserved; 06cd0 2-arg, u16 pickbuf[0x18], integer clamp [0,99] preserved. Banked as guarded floor. 2026-09-19: 909/931 hides 27-pure delete retail[141:168] vs 37-pure insert object[805:842] (switch-1 7/8/9 early tails vs late) plus 11-pure ==0xE else; net -22 inside gate. Reorder switch-1 to 9,7,8,1 gives 579->544 edits with 765->775 words; flatten ==0xE early gives 544->526 with 775 words; fresh 10 counters gives 579->589 with 765 tie words; drop (u8) casts gives 579->551 with 765->781 words. Words floor holds at 765; frame 0xD0 matches here (prior 0xB0 stale). */
/* measured 00238940 (owner, 2026-09-19): the pick loop is a `do { } while`, not a
   top-tested loop.  m2c wrote it as `loop_9: temp_3 = var_6 & 0xFFFF; if (temp_3 < 0x18)
   { ...; goto loop_9; }`, which emits a test at the TOP of every iteration; retail has no
   top test at all - its only compare is at the bottom, `addiu $v0, $a2, 1; andi; andi;
   slti $v0, $v1, 0x18; bnez $v0, .-14`.  Rewriting it as a `do { } while ((var_6 & 0xFFFF)
   < 0x18)` removes the `slti $at, $v0, 0x18; beqz $at` guard and takes the count 909 -> 908
   against retail 931.  Edits stay 579: the loop shape is right now but the body inside it
   still differs, so this is banked for the structure, not for a score.
   Width was measured on top and is NOT banked, for a reason worth recording: the object
   sign-extends through `dsll32 $a2, $v0, 0x10; dsra32 $a2, $a2, 0x10` where retail just
   masks with `andi`, and declaring `var_6` as `u16` or `s32` removes that - 579 -> **574**
   edits - but it also drops the count to 903, which is -3.01% and OUTSIDE the +-3% band
   (903.07 lower bound).  Five edits is not worth leaving the gate, and no score measured
   outside it is comparable anyway (7y).  `u16 var_6` plus `u16 var_5` together is worse
   again at 580.  The object is 22 instructions SHORT of retail; find those first, then the
   width narrowing becomes free. */
// FUN_00238940 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_loop_invariants on
s32 func_00238940(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    u16 pickbuf[0x18];
    f32 var_16;
    f32 var_f1;
    f32 var_f20;
    s16 var_2_11;
    s16 var_6;
    s32 temp_16;
    s32 temp_22;
    s32 temp_23s;
    s32 temp_2;
    s32 temp_2_10;
    s32 temp_2_12;
    s32 temp_2_14;
    s32 temp_2_16;
    s32 temp_2_18;
    s32 temp_2_20;
    s32 temp_2_22;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_2_6;
    s32 temp_2_8;
    s32 temp_3;
    s32 temp_4_2;
    s32 var_21;
    s32 var_2s;
    s32 var_5;
    s32 var_6s;
    s32 temp_2_11;
    s32 temp_2_13;
    s32 temp_2_15;
    s32 temp_2_17;
    s32 temp_2_19;
    s32 temp_2_21;
    s32 temp_2_23;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_2_7;
    s32 temp_2_9;
    u32 temp_17;
    u64 var_17;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 *temp_4;

    if ((arg0 & 0xFFFF) >= 0x240) {
        func_0046d730(&D_00635938, 0xA30);
    }
    temp_16 = (u16)arg0 * 0x28;
    temp_4 = (u8 *)(temp_16 + (s32)iGpffffb3b8);
    if ((*(u8 *)((u8 *)(temp_4) + (0x24))) == 0xD) {
        return 0x80000U;
    }
    var_f20 = 1.0f;
    var_21 = 0;
    var_17 = (u64) ((s64) (*(s32 *)((u8 *)(temp_4) + (0x1C))) << 0x28) >> 0x28;
    if ((*(u8 *)((u8 *)(temp_4) + (0x18))) == 3) {
        var_5 = 0;
        var_6 = 0;
        do {
            temp_3 = var_6 & 0xFFFF;
            if (var_17 & (1 << temp_3)) {
                pickbuf[(var_5 & 0xFFFF)] = var_6;
                var_5 = (var_5 + 1) & 0xFFFF;
            }
            var_6 = (var_6 + 1) & 0xFFFF;
        } while ((var_6 & 0xFFFF) < 0x18);
        temp_17 = var_5 & 0xFFFF;
        if (temp_17 == 0) {
            func_0046d730(&D_00635938, 0x17);
        }
        var_17 = (u64)(s32)(1 << pickbuf[func_003b7060() % temp_17]);
    }
    if ((var_17 != 0) && ((temp_4_2 = (s32)iGpffffb3b8, temp_3_2 = *((u8 *)(temp_4_2 + 0x18 + temp_16)), (temp_3_2 == 1)) || (temp_3_2 == 3))) {
        if ((*(u8 *)((u8 *)((temp_16 + temp_4_2)) + (0x24))) != 0xE) {
            if (func_00243e30(arg2) != 0) {
                return 0U;
            }
            temp_3_3 = (u8)((*(u8 *)((u8 *)((temp_16 + (s32)iGpffffb3b8)) + (0x24))));
            switch (temp_3_3) {                     /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                if ((*(s32 *)((u8 *)(arg2) + (0xC))) & 4) {
                    return (u8) var_17;
                }
            default:                                /* switch 1 */
                temp_2 = (s32)(func_0023a6b0(arg2, (s32)func_0023d740(arg0, (u8) var_17)));
                if (temp_2 & 0x27000000) {
                    return 0U;
                }
                if (var_17 & 0x100000) {
                    if ((*(s32 *)((u8 *)(arg2) + (0xC))) & 0x100000) {
                        return 0U;
                    }
                    if ((*(u16 *)((u8 *)(arg2) + (0))) & 8) {
                        return 0U;
                    }
                    goto block_47;
                }
block_47:
                temp_2_2 = temp_2 & 0xFFFF;
                if (temp_2_2 >= 0) {
                    var_f1 = (f32) temp_2_2;
                } else {
                    var_f1 = 2.0f * (f32) (((u32) temp_2_2 >> 1) | (temp_2_2 & 1));
                }
                var_f20 = 1.0f * (var_f1 / 100.0f);
                if (!(arg3 & 1)) {
                    temp_22 = var_17 & 0x80000;
                    if ((temp_22 == 0) && (((s32)func_002332a0(arg2, 7)) > 0)) {
                        var_f20 *= 2.0f;
                    }
                    temp_2_3 = (s32)func_0023d8e0(arg1, arg0);
                    switch (temp_2_3) {             /* switch 2 */
                    case 9:                         /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_4 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_60:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_5 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_5 >= 0)) && (func_001069a0((s16)temp_2_5) == 0x217)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_4 + (u16)var_6s * 2) == 0x217) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_60;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 8:                         /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_6 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_72:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_7 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_7 >= 0)) && (func_001069a0((s16)temp_2_7) == 0x216)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_6 + (u16)var_6s * 2) == 0x216) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_72;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 10:                        /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_8 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_84:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_9 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_9 >= 0)) && (func_001069a0((s16)temp_2_9) == 0x21A)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_8 + (u16)var_6s * 2) == 0x21A) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_84;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 6:                         /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_10 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_96:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_11 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_11 >= 0)) && (func_001069a0((s16)temp_2_11) == 0x21F)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_10 + (u16)var_6s * 2) == 0x21F) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_96;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 7:                         /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_12 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_108:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_13 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_13 >= 0)) && (func_001069a0((s16)temp_2_13) == 0x220)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_12 + (u16)var_6s * 2) == 0x220) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_108;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 13:                        /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_14 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_120:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_15 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_15 >= 0)) && (func_001069a0((s16)temp_2_15) == 0x218)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_14 + (u16)var_6s * 2) == 0x218) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_120;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 15:                        /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_16 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_132:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_17 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_17 >= 0)) && (func_001069a0((s16)temp_2_17) == 0x219)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_16 + (u16)var_6s * 2) == 0x219) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_132;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 11:                        /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_18 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_144:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_19 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_19 >= 0)) && (func_001069a0((s16)temp_2_19) == 0x21B)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_18 + (u16)var_6s * 2) == 0x21B) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_144;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    case 14:                        /* switch 2 */
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_20 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_156:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_21 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_21 >= 0)) && (func_001069a0((s16)temp_2_21) == 0x21D)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_20 + (u16)var_6s * 2) == 0x21D) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_156;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                        break;
                    }
                    if (temp_22 == 0) {
                        temp_23s = (s32)(func_0023e130(arg1) & 0xFFFF);
                        temp_2_22 = (s32)(func_0023e140(arg1));
                        var_6s = 0;
loop_169:
                        if ((var_6s & 0xFFFF) >= (temp_23s & 0xFFFF)) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_23 = func_00106cd0((*(s16 *)((u8 *)(arg1) + (2))),  2) & 0xFFFF, (temp_2_23 >= 0)) && (func_001069a0((s16)temp_2_23) == 0x21E)) {
                                var_2s = 1;
                            } else {
                                var_2s = 0;
                            }
                        } else if (*(u16 *)(temp_2_22 + (u16)var_6s * 2) == 0x21E) {
                            var_2s = 1;
                        } else {
                            var_6s = (var_6s + 1) & 0xFFFF;
                            goto loop_169;
                        }
                        if (var_2s != 0) {
                            var_f20 *= 1.25f;
                        }
                    }
                }
                goto block_177;
            case 7:                                 /* switch 1 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 0x1000) {
                    var_17 = 0;
                }
                return (u8) var_17;
            case 8:                                 /* switch 1 */
                if ((*(u16 *)((u8 *)(arg2) + (0))) & 0x1000) {

                } else {
                    var_17 = 0;
                }
                return (u8) var_17;
            case 9:                                 /* switch 1 */
                if ((*(s32 *)((u8 *)(arg2) + (0xC))) & 1) {
                    return (u8) var_17;
                }
                return 0U;
            }
        } else {
            if ((u8) (*(s32 *)((u8 *)(arg2) + (0xC))) != 0) {
                return (u8) var_17;
            }
            return 0U;
        }
    } else {
block_177:
        if (var_17 == 0) {
            return 0U;
        }
        if ((s32) (*(u8 *)((u8 *)((temp_16 + (s32)iGpffffb3b8)) + (0x19))) >= 0x64) {
            var_21 = 1;
        } else {
            var_16 = (f32) func_00244f60(0xA, arg1, arg2, arg0, (u8) var_17) * var_f20;
            if (((s32)(var_16)) >= 0x64) {
                var_16 = 0x63;
            } else if (((s32)(var_16)) < 0) {
                var_16 = 0;
            }
            if ((s32) (func_003b7060() % 100U) < ((s32)(var_16))) {
                var_21 = 1;
            }
        }
        if ((var_21 != 0) && (var_17 & 0x80000) && (((s64) ((((*(s32 *)((u8 *)(arg2) + (0x14))) & 0x800000) != 0) << 0x38) >> 0x38) > 0)) {
            var_17 &= 0xFFF7FFFF;
            if ((*(u16 *)((u8 *)(arg2) + (0))) & 4) {
                var_2_11 = 0x79;
            } else {
                var_2_11 = 0x78;
            }
            (*(s16 *)((u8 *)(arg2) + (0x2C))) = var_2_11;
            (*(s32 *)((u8 *)(arg2) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0x18))) | 0x800000);
        }
        if (var_21 != 0) {

        } else {
            var_17 = 0;
        }
        return (u8) var_17;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00238940);
#endif

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
s32 func_0023a620(s32 arg0, s32 arg1)
{
    s32 temp_3 = arg1 & 0xFFFF;
    s32 var_2 = ((temp_3 & 0xFF00) << 0x10) | ((temp_3 & 0xFFFF00FF) * 5);
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
/* measured: forward declarations for func_0023a6b0 (iGpffffb3c8 table, u32-returning func_00109870 whose $v0 retail preserves, and same-TU func_00243e30 defined below). Placed here so earlier implicit uses are unaffected. */
extern u8 *iGpffffb3c8;
extern u32 func_00109870(s32 arg0, s32 arg1);
extern s32 func_00243e30(u16 *arg0);




/* measured: guarded floor for func_0023a6b0 (retail 12336B window, 3084 instrs). Candidate object 12312B/3078 instrs (-24B/-6, -0.2% inside 3% gate 2991-3177); fndiff 2615 words (reloc-masked), fnalign 2131 edits (+15 reloc-only). Switch 0-15 with empty 0/5 for retail sltiu 0x10 bound (jtbl_00747C40 16 entries; 0,5 share default 0x23D330); 44 fresh s32 counters with while+goto-done, (u16)ctr*2 indexing, (s32)((u32)(u16)00106cd0&0xFFFF)+bltz and (s16)temp_2 dsll32/dsra32 fallback per matched 00242990; s32-only (no s64); val via u32 00109870 ($v0 preserved) else iGpffffb3c8 table with (raw&0xFF00)<<16|(raw&0xFFFF00FF)*5 and (val&0xFFFF)==0 guard per 0023a620. Production stays ASM. */
/* measured 2026-09-19 (0023a6b0 tail pass, sibling 00238940 untouched): fnalign 2131 -> 1079 edits (+15 -> +23 reloc-only), object 3078 -> 3070 instrs vs retail 3080 (-0.3%, inside 3% gate). tail_classify structure 237 -> 215, register 115 -> 100. Banked, in order on top of the old floor body: (1) 00109870 2nd arg temp_16 -> (arg1 & 0xFFFF) reproduces retail andi $a1,$s3,0xFFFF and the raw/extended $s3/$s0 coloring, -95 edits +1 instr; (2) 16x t0-mediated 001069d0(t0) -> nested 001069d0(00106cd0(...)) for retail move $a0,$v0 (micro-proven: s16 call result forwarded needs no extend), -24 edits -16 instrs, dead s16 t0 dropped (neutral); (3) 8x found==0/else-acc flattened onto one shared acc|=0x10000000 (bnez-to-OR, found=0-goto-chk shape per retail 13C2D0-39C), -60 edits -8 instrs; (4) switch cases 8-15 reordered to retail layout 9,8,10,13,11,15,14,12 (jtbl_00747C40: 8->C20C, 9->BF98, 10->C480, 11->CBDC, 12->D0C4, 13->C6F4, 14->CE50, 15->C968; value<->body mapping verified per-address, call census 44/44/44/60/16 exact), -824 edits count-neutral, kills the SequenceMatcher phantom deletes; (5) tail val-merges factored (((val&M)|ACC)&0xFFFF0000)|C per retail ori/and/or/lui/and/ori chains (micro-proven mask-reuse of guard lui), hasFlag!=0 -> ==1 for retail bne-1, -49 edits +15 instrs. Tail C verified semantically identical to retail throughout (A1 guard 0x7000000, A1/A2/B4 factored forms all net-equal). Recorded negatives (not banked): (s16)temp_2 -> temp_2 neutral (s16 params force the extend anyway); head || split into 3 ifs +6 edits +11 instrs (duplicated 100-epilogues), goto-shared-return -1 edit +7 instrs (reject: terrible ratio, uglifies); opt_loop_invariants on byte-identical hunks (inert here, unlike 00232d80); s16 sid/t0-holder for idu extend-once: micro-exact locally, +195 whole-function either way (live-range pressure across the 44 counters, floor). Residual is the 3-value loop-register rotation floor (counter/limit/const $a2/$a1/$a0 vs $a1/remat, same idiom 00232d80 measured unfixable), the idu extend-hoist floor above, the head ||-range fold, branch-cascade displacements, and ~320 SequenceMatcher phantom edits over the near-identical case bodies (zone multiset differs by ~10 instrs only). Production stays ASM. */
/* measured 0023a6b0 (owner, 2026-09-19): fnalign **1079 -> 805 edits**, count
   3070 -> 3070 against retail 3080, by putting the switch arms in the order the
   JUMP TABLE uses rather than ascending case order.  The layout is read out of the
   retail ELF - the `sltiu` bound gives the entry count, each 4-byte entry gives an
   arm address, and sorting the case values by arm address is the order retail
   emitted them in; entries sharing the most common address are the default.
   Ascending order is what a lowered if-CHAIN wants.  A jump table already encodes
   its own order and the source has to agree with it.  Swept over every first-party
   floor with a table: 20 were already in layout order, 5 improved (274, 88, 50, 37
   and 7 edits) and 13 got worse, so it is measured per function like every other
   spelling. */
/* measured 0023a6b0 (owner, 2026-09-20): fnalign 805 -> 188 edits (plus 25 reloc-only unchanged), object 3070 vs retail 3080 (-0.3% inside 3% gate), via scoped #pragma opt_loop_invariants on. tail_classify structure 226 -> 50, register 105 -> 104. The pragma hoists the per-loop cnt&0xFFFF (andi $a1,$s5) and needle (addiu $a0) out of all 44 search loops, fixing the 5v6/4v2/2v3 length mismatches; deficit_scan unchanged deficit 10 (move +16 beq +5 nop +4 b +3, retail-only runs at 0x23a704, 0x23a734, 0x23a7a0) so the remainder is register coloring (s5/s6, s6/s7, val $s3/$a0, dsll+move vs dsll-direct) plus early range-vs-discrete and lhu scheduler phantom - wall, stop. Sibling 00238940 untouched, table_order already in layout order. */
#pragma push
#pragma opt_loop_invariants on
// FUN_0023A6B0 NONMATCHING
#ifdef SKIP_ASM
s32 func_0023a6b0(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_2;
    s32 found;
    u8 *base;
    s32 cnt;
    s32 ctr_00;
    s32 ctr_01;
    s32 ctr_02;
    s32 ctr_03;
    s32 ctr_04;
    s32 ctr_05;
    s32 ctr_06;
    s32 ctr_07;
    s32 ctr_08;
    s32 ctr_09;
    s32 ctr_10;
    s32 ctr_11;
    s32 ctr_12;
    s32 ctr_13;
    s32 ctr_14;
    s32 ctr_15;
    s32 ctr_16;
    s32 ctr_17;
    s32 ctr_18;
    s32 ctr_19;
    s32 ctr_20;
    s32 ctr_21;
    s32 ctr_22;
    s32 ctr_23;
    s32 ctr_24;
    s32 ctr_25;
    s32 ctr_26;
    s32 ctr_27;
    s32 ctr_28;
    s32 ctr_29;
    s32 ctr_30;
    s32 ctr_31;
    s32 ctr_32;
    s32 ctr_33;
    s32 ctr_34;
    s32 ctr_35;
    s32 ctr_36;
    s32 ctr_37;
    s32 ctr_38;
    s32 ctr_39;
    s32 ctr_40;
    s32 ctr_41;
    s32 ctr_42;
    s32 ctr_43;
    u32 val;
    u32 acc;
    s32 hasFlag;
    s32 b1;
    s32 b4;
    u16 raw;
    u32 high;
    u32 low;
    s32 idu;

    acc = 0;
    hasFlag = 0;
    b1 = 0;
    b4 = 0;
    temp_16 = (s16)arg1;
    if (temp_16 == 0x12 || temp_16 == 0x11 || temp_16 == 0x10) {
        return 100;
    }
    if (temp_16 == -1) {
        return 0;
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
        high = (raw & 0xFF00) << 16;
        low = (raw & 0xFFFF00FF) * 5;
        val = high | low;
        if ((val & 0xFFFF) == 0) {
            if ((high & 0x8000000) != 0) {
                val |= 0x7D;
            } else if ((high & 0x27000000) != 0) {
                val |= 100;
            } else if ((high & 0x10000000) != 0) {
                val |= 0x32;
            }
        }
    }
    if (func_00243e30((u16 *)arg0) != 0) {
        hasFlag = 1;
    }
    if (temp_16 == 0) {
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_00 = 0;
        while ((ctr_00 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_00 * 2) == 0x1B8) {
                found = 1;
                goto done_p0;
            }
            ctr_00 = (ctr_00 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1B8) {
                    found = 1;
                    goto done_p0;
                }
            }
        }
        found = 0;
done_p0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_01 = 0;
        while ((ctr_01 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_01 * 2) == 0x1B9) {
                found = 1;
                goto done_p1;
            }
            ctr_01 = (ctr_01 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1B9) {
                    found = 1;
                    goto done_p1;
                }
            }
        }
        found = 0;
done_p1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_02 = 0;
        while ((ctr_02 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_02 * 2) == 0x1BA) {
                found = 1;
                goto done_p2;
            }
            ctr_02 = (ctr_02 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BA) {
                    found = 1;
                    goto done_p2;
                }
            }
        }
        found = 0;
done_p2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_03 = 0;
        while ((ctr_03 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_03 * 2) == 0x1BB) {
                found = 1;
                goto done_p3;
            }
            ctr_03 = (ctr_03 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BB) {
                    found = 1;
                    goto done_p3;
                }
            }
        }
        found = 0;
done_p3:
        if (found != 0) {
            acc |= 0x4000000;
        }
    }
    switch (temp_16) {
    case 1:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_04 = 0;
        while ((ctr_04 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_04 * 2) == 0x1BC) {
                found = 1;
                goto done_1_0;
            }
            ctr_04 = (ctr_04 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BC) {
                    found = 1;
                    goto done_1_0;
                }
            }
        }
        found = 0;
done_1_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_05 = 0;
        while ((ctr_05 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_05 * 2) == 0x1BD) {
                found = 1;
                goto done_1_1;
            }
            ctr_05 = (ctr_05 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BD) {
                    found = 1;
                    goto done_1_1;
                }
            }
        }
        found = 0;
done_1_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_06 = 0;
        while ((ctr_06 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_06 * 2) == 0x1BE) {
                found = 1;
                goto done_1_2;
            }
            ctr_06 = (ctr_06 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BE) {
                    found = 1;
                    goto done_1_2;
                }
            }
        }
        found = 0;
done_1_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_07 = 0;
        while ((ctr_07 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_07 * 2) == 0x1BF) {
                found = 1;
                goto done_1_3;
            }
            ctr_07 = (ctr_07 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1BF) {
                    found = 1;
                    goto done_1_3;
                }
            }
        }
        found = 0;
done_1_3:
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
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_08 = 0;
        while ((ctr_08 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_08 * 2) == 0x1C0) {
                found = 1;
                goto done_2_0;
            }
            ctr_08 = (ctr_08 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C0) {
                    found = 1;
                    goto done_2_0;
                }
            }
        }
        found = 0;
done_2_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_09 = 0;
        while ((ctr_09 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_09 * 2) == 0x1C1) {
                found = 1;
                goto done_2_1;
            }
            ctr_09 = (ctr_09 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C1) {
                    found = 1;
                    goto done_2_1;
                }
            }
        }
        found = 0;
done_2_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_10 = 0;
        while ((ctr_10 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_10 * 2) == 0x1C2) {
                found = 1;
                goto done_2_2;
            }
            ctr_10 = (ctr_10 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C2) {
                    found = 1;
                    goto done_2_2;
                }
            }
        }
        found = 0;
done_2_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_11 = 0;
        while ((ctr_11 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_11 * 2) == 0x1C3) {
                found = 1;
                goto done_2_3;
            }
            ctr_11 = (ctr_11 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C3) {
                    found = 1;
                    goto done_2_3;
                }
            }
        }
        found = 0;
done_2_3:
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
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_12 = 0;
        while ((ctr_12 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_12 * 2) == 0x1C4) {
                found = 1;
                goto done_3_0;
            }
            ctr_12 = (ctr_12 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C4) {
                    found = 1;
                    goto done_3_0;
                }
            }
        }
        found = 0;
done_3_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_13 = 0;
        while ((ctr_13 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_13 * 2) == 0x1C5) {
                found = 1;
                goto done_3_1;
            }
            ctr_13 = (ctr_13 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C5) {
                    found = 1;
                    goto done_3_1;
                }
            }
        }
        found = 0;
done_3_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_14 = 0;
        while ((ctr_14 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_14 * 2) == 0x1C6) {
                found = 1;
                goto done_3_2;
            }
            ctr_14 = (ctr_14 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C6) {
                    found = 1;
                    goto done_3_2;
                }
            }
        }
        found = 0;
done_3_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_15 = 0;
        while ((ctr_15 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_15 * 2) == 0x1C7) {
                found = 1;
                goto done_3_3;
            }
            ctr_15 = (ctr_15 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C7) {
                    found = 1;
                    goto done_3_3;
                }
            }
        }
        found = 0;
done_3_3:
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
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_16 = 0;
        while ((ctr_16 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_16 * 2) == 0x1C8) {
                found = 1;
                goto done_4_0;
            }
            ctr_16 = (ctr_16 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C8) {
                    found = 1;
                    goto done_4_0;
                }
            }
        }
        found = 0;
done_4_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_17 = 0;
        while ((ctr_17 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_17 * 2) == 0x1C9) {
                found = 1;
                goto done_4_1;
            }
            ctr_17 = (ctr_17 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1C9) {
                    found = 1;
                    goto done_4_1;
                }
            }
        }
        found = 0;
done_4_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_18 = 0;
        while ((ctr_18 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_18 * 2) == 0x1CA) {
                found = 1;
                goto done_4_2;
            }
            ctr_18 = (ctr_18 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CA) {
                    found = 1;
                    goto done_4_2;
                }
            }
        }
        found = 0;
done_4_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_19 = 0;
        while ((ctr_19 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_19 * 2) == 0x1CB) {
                found = 1;
                goto done_4_3;
            }
            ctr_19 = (ctr_19 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CB) {
                    found = 1;
                    goto done_4_3;
                }
            }
        }
        found = 0;
done_4_3:
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
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_20 = 0;
        while ((ctr_20 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_20 * 2) == 0x1CC) {
                found = 1;
                goto done_6_0;
            }
            ctr_20 = (ctr_20 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CC) {
                    found = 1;
                    goto done_6_0;
                }
            }
        }
        found = 0;
done_6_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_21 = 0;
        while ((ctr_21 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_21 * 2) == 0x1CD) {
                found = 1;
                goto done_6_1;
            }
            ctr_21 = (ctr_21 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CD) {
                    found = 1;
                    goto done_6_1;
                }
            }
        }
        found = 0;
done_6_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_22 = 0;
        while ((ctr_22 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_22 * 2) == 0x1CE) {
                found = 1;
                goto done_6_2;
            }
            ctr_22 = (ctr_22 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CE) {
                    found = 1;
                    goto done_6_2;
                }
            }
        }
        found = 0;
done_6_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        break;
    case 7:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_23 = 0;
        while ((ctr_23 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_23 * 2) == 0x1CF) {
                found = 1;
                goto done_7_0;
            }
            ctr_23 = (ctr_23 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1CF) {
                    found = 1;
                    goto done_7_0;
                }
            }
        }
        found = 0;
done_7_0:
        if (found != 0) {
            acc |= 0x10000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_24 = 0;
        while ((ctr_24 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_24 * 2) == 0x1D0) {
                found = 1;
                goto done_7_1;
            }
            ctr_24 = (ctr_24 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D0) {
                    found = 1;
                    goto done_7_1;
                }
            }
        }
        found = 0;
done_7_1:
        if (found != 0) {
            acc |= 0x1000000;
        }
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_25 = 0;
        while ((ctr_25 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_25 * 2) == 0x1D1) {
                found = 1;
                goto done_7_2;
            }
            ctr_25 = (ctr_25 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D1) {
                    found = 1;
                    goto done_7_2;
                }
            }
        }
        found = 0;
done_7_2:
        if (found != 0) {
            acc |= 0x2000000;
        }
        break;
    case 9:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_28 = 0;
        while ((ctr_28 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_28 * 2) == 0x225) {
                found = 1;
                goto done_9_a;
            }
            ctr_28 = (ctr_28 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x225) {
                    found = 1;
                    goto done_9_a;
                }
            }
        }
        found = 0;
done_9_a:
        if (found != 0) {
            goto acc_9_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_9_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x4C) {
            found = 1;
            goto chk_9_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x4C) {
            found = 1;
            goto chk_9_b;
        }
        found = 0;
chk_9_b:
        if (found == 0) {
            goto skp_9_b;
        }
acc_9_b:
        acc |= 0x10000000;
skp_9_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_29 = 0;
        while ((ctr_29 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_29 * 2) == 0x1D7) {
                found = 1;
                goto done_9_c;
            }
            ctr_29 = (ctr_29 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D7) {
                    found = 1;
                    goto done_9_c;
                }
            }
        }
        found = 0;
done_9_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 8:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_26 = 0;
        while ((ctr_26 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_26 * 2) == 0x226) {
                found = 1;
                goto done_8_a;
            }
            ctr_26 = (ctr_26 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x226) {
                    found = 1;
                    goto done_8_a;
                }
            }
        }
        found = 0;
done_8_a:
        if (found != 0) {
            goto acc_8_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_8_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x4B) {
            found = 1;
            goto chk_8_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x4B) {
            found = 1;
            goto chk_8_b;
        }
        found = 0;
chk_8_b:
        if (found == 0) {
            goto skp_8_b;
        }
acc_8_b:
        acc |= 0x10000000;
skp_8_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_27 = 0;
        while ((ctr_27 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_27 * 2) == 0x1D2) {
                found = 1;
                goto done_8_c;
            }
            ctr_27 = (ctr_27 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D2) {
                    found = 1;
                    goto done_8_c;
                }
            }
        }
        found = 0;
done_8_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 10:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_30 = 0;
        while ((ctr_30 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_30 * 2) == 0x227) {
                found = 1;
                goto done_10_a;
            }
            ctr_30 = (ctr_30 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x227) {
                    found = 1;
                    goto done_10_a;
                }
            }
        }
        found = 0;
done_10_a:
        if (found != 0) {
            goto acc_10_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_10_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x4D) {
            found = 1;
            goto chk_10_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x4D) {
            found = 1;
            goto chk_10_b;
        }
        found = 0;
chk_10_b:
        if (found == 0) {
            goto skp_10_b;
        }
acc_10_b:
        acc |= 0x10000000;
skp_10_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_31 = 0;
        while ((ctr_31 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_31 * 2) == 0x1D5) {
                found = 1;
                goto done_10_c;
            }
            ctr_31 = (ctr_31 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D5) {
                    found = 1;
                    goto done_10_c;
                }
            }
        }
        found = 0;
done_10_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 13:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_36 = 0;
        while ((ctr_36 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_36 * 2) == 0x228) {
                found = 1;
                goto done_13_a;
            }
            ctr_36 = (ctr_36 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x228) {
                    found = 1;
                    goto done_13_a;
                }
            }
        }
        found = 0;
done_13_a:
        if (found != 0) {
            goto acc_13_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_13_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x50) {
            found = 1;
            goto chk_13_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x50) {
            found = 1;
            goto chk_13_b;
        }
        found = 0;
chk_13_b:
        if (found == 0) {
            goto skp_13_b;
        }
acc_13_b:
        acc |= 0x10000000;
skp_13_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_37 = 0;
        while ((ctr_37 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_37 * 2) == 0x1D3) {
                found = 1;
                goto done_13_c;
            }
            ctr_37 = (ctr_37 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D3) {
                    found = 1;
                    goto done_13_c;
                }
            }
        }
        found = 0;
done_13_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 15:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_40 = 0;
        while ((ctr_40 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_40 * 2) == 0x22C) {
                found = 1;
                goto done_15_a;
            }
            ctr_40 = (ctr_40 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x22C) {
                    found = 1;
                    goto done_15_a;
                }
            }
        }
        found = 0;
done_15_a:
        if (found != 0) {
            goto acc_15_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_15_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x52) {
            found = 1;
            goto chk_15_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x52) {
            found = 1;
            goto chk_15_b;
        }
        found = 0;
chk_15_b:
        if (found == 0) {
            goto skp_15_b;
        }
acc_15_b:
        acc |= 0x10000000;
skp_15_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_41 = 0;
        while ((ctr_41 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_41 * 2) == 0x1D4) {
                found = 1;
                goto done_15_c;
            }
            ctr_41 = (ctr_41 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D4) {
                    found = 1;
                    goto done_15_c;
                }
            }
        }
        found = 0;
done_15_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 11:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_32 = 0;
        while ((ctr_32 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_32 * 2) == 0x22A) {
                found = 1;
                goto done_11_a;
            }
            ctr_32 = (ctr_32 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x22A) {
                    found = 1;
                    goto done_11_a;
                }
            }
        }
        found = 0;
done_11_a:
        if (found != 0) {
            goto acc_11_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_11_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x4E) {
            found = 1;
            goto chk_11_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x4E) {
            found = 1;
            goto chk_11_b;
        }
        found = 0;
chk_11_b:
        if (found == 0) {
            goto skp_11_b;
        }
acc_11_b:
        acc |= 0x10000000;
skp_11_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_33 = 0;
        while ((ctr_33 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_33 * 2) == 0x1D6) {
                found = 1;
                goto done_11_c;
            }
            ctr_33 = (ctr_33 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D6) {
                    found = 1;
                    goto done_11_c;
                }
            }
        }
        found = 0;
done_11_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 14:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_38 = 0;
        while ((ctr_38 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_38 * 2) == 0x229) {
                found = 1;
                goto done_14_a;
            }
            ctr_38 = (ctr_38 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x229) {
                    found = 1;
                    goto done_14_a;
                }
            }
        }
        found = 0;
done_14_a:
        if (found != 0) {
            goto acc_14_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_14_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x51) {
            found = 1;
            goto chk_14_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x51) {
            found = 1;
            goto chk_14_b;
        }
        found = 0;
chk_14_b:
        if (found == 0) {
            goto skp_14_b;
        }
acc_14_b:
        acc |= 0x10000000;
skp_14_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_39 = 0;
        while ((ctr_39 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_39 * 2) == 0x1D9) {
                found = 1;
                goto done_14_c;
            }
            ctr_39 = (ctr_39 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D9) {
                    found = 1;
                    goto done_14_c;
                }
            }
        }
        found = 0;
done_14_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 12:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_34 = 0;
        while ((ctr_34 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_34 * 2) == 0x22B) {
                found = 1;
                goto done_12_a;
            }
            ctr_34 = (ctr_34 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x22B) {
                    found = 1;
                    goto done_12_a;
                }
            }
        }
        found = 0;
done_12_a:
        if (found != 0) {
            goto acc_12_b;
        }
        if ((*(u16 *)arg0 & 4) != 0) {
            found = 0;
            goto chk_12_b;
        }
        idu = *(u16 *)(arg0 + 2);
        if (idu >= 0xB) {
            func_0046d730(D_00635938, 0x23B);
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 0)) & 0xFFFF) == 0x4F) {
            found = 1;
            goto chk_12_b;
        }
        if ((func_001069d0(func_00106cd0((s16)idu, 1)) & 0xFFFF) == 0x4F) {
            found = 1;
            goto chk_12_b;
        }
        found = 0;
chk_12_b:
        if (found == 0) {
            goto skp_12_b;
        }
acc_12_b:
        acc |= 0x10000000;
skp_12_b:
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_35 = 0;
        while ((ctr_35 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_35 * 2) == 0x1D8) {
                found = 1;
                goto done_12_c;
            }
            ctr_35 = (ctr_35 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1D8) {
                    found = 1;
                    goto done_12_c;
                }
            }
        }
        found = 0;
done_12_c:
        if (found != 0) {
            acc |= 0x1000000;
        }
        break;
    case 0:
        break;
    case 5:
        break;
    }
    if (temp_16 == 0xE || temp_16 == 0xB || temp_16 == 0xF || temp_16 == 10 || temp_16 == 8) {
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_42 = 0;
        while ((ctr_42 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_42 * 2) == 0x1DA) {
                found = 1;
                goto done_1da;
            }
            ctr_42 = (ctr_42 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1DA) {
                    found = 1;
                    goto done_1da;
                }
            }
        }
        found = 0;
done_1da:
        if (found != 0) {
            acc |= 0x1000000;
        }
    }
    if (temp_16 != 5) {
        cnt = func_0023e130(arg0) & 0xFFFF;
        base = func_0023e140(arg0);
        ctr_43 = 0;
        while ((ctr_43 & 0xFFFF) < (cnt & 0xFFFF)) {
            if (*(u16 *)(base + (u16)ctr_43 * 2) == 0x1DB) {
                found = 1;
                goto done_1db;
            }
            ctr_43 = (ctr_43 + 1) & 0xFFFF;
        }
        if ((*(u16 *)arg0 & 4) == 0) {
            temp_2 = (s32)((u32)(u16)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
            if (temp_2 >= 0) {
                if (func_001069a0((s16)temp_2) == 0x1DB) {
                    found = 1;
                    goto done_1db;
                }
            }
        }
        found = 0;
done_1db:
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
#else
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a6b0);
#endif
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
u8 func_0023dd90(u8 *arg0, s32 arg1)
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

/* Cold 0023e6f0 (2732 instrs, frame -0xC0 s17-s23/s30): no probe_archive */
/* entry; m2c fails on K&R header s32 func_00241bc0(arg0,...) in context */
/* (not jtbl; no jr except return, switches via if-chains). romwright 1272 */
/* lines (u32 ret, long/u64/u64/u32 4 args) needs ?-at-line-start (keep */
/* ternary), sbyte->s8, FUN_00635938->D_00635938, header to file signature, */
/* temp_v7/temp_v9 int-vs-pointer splits (reused temps hold int at one site */
/* (func return/random) and pointer (table entry+iGp+off) at another; split */
/* to int + u8* with non-overlapping live ranges, same count). Read floor */
/* 00238940 idioms first: s32 clean, (u16)arg0 head split, u16 skill loads */
/* 0x216-0x220, s16 counters (s32 vs s16 was 207 structural here this week), */
/* table-walk field-by-field at fixed offsets, s16 fields. Front-load s16 */
/* counters, counted fors, s32 clean. Not banked: count outside band. */
// FUN_0023E6F0 NONMATCHING
#ifdef SKIP_ASM
s32 func_0023e6f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    extern f32 func_00233bc0(u8 *arg0, s32 arg1, s32 arg2);
    extern f32 iGpffff8170;
    extern f32 fGpffff80cc;
    s32 spBC;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f20;
    s16 var_20;
    s16 var_20_2;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_22;
    s32 temp_2_19;
    s32 temp_30;
    s32 var_17;
    s32 var_19;
    s32 var_2;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_19;
    s32 var_2_20;
    s32 var_2_21;
    s32 var_2_22;
    s32 var_2_23;
    s32 var_2_24;
    s32 var_2_25;
    s32 var_2_26;
    s32 var_2_27;
    s32 var_2_28;
    s32 var_2_29;
    s32 var_2_2;
    s32 var_2_30;
    s32 var_2_31;
    s32 var_2_32;
    s32 var_2_33;
    s32 var_2_34;
    s32 var_2_35;
    s32 var_2_36;
    s32 var_2_37;
    s32 var_2_38;
    s32 var_2_39;
    s32 var_2_3;
    s32 var_2_40;
    s32 var_2_41;
    s32 var_2_42;
    s32 var_2_43;
    s32 var_2_44;
    s32 var_2_45;
    s32 var_2_46;
    s32 var_2_47;
    s32 var_2_48;
    s32 var_2_49;
    s32 var_2_4;
    s32 var_2_50;
    s32 var_2_51;
    s32 var_2_52;
    s32 var_2_53;
    s32 var_2_54;
    s32 var_2_55;
    s32 var_2_56;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    s32 var_5;
    s32 var_5_10;
    s32 var_5_11;
    s32 var_5_12;
    s32 var_5_13;
    s32 var_5_14;
    s32 var_5_15;
    s32 var_5_16;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_5_8;
    s32 var_5_9;
    s64 temp_18_10;
    s64 temp_18_12;
    s64 temp_18_14;
    s64 temp_18_16;
    s64 temp_18_18;
    s64 temp_18_20;
    s64 temp_18_22;
    s64 temp_18_24;
    s64 temp_18_26;
    s64 temp_18_2;
    s64 temp_18_4;
    s64 temp_18_6;
    s64 temp_18_8;
    s64 temp_21_10;
    s64 temp_21_12;
    s64 temp_21_2;
    s64 temp_21_4;
    s64 temp_21_6;
    s64 temp_21_8;
    s64 temp_22_2;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_12;
    s32 temp_2_13;
    s32 temp_2_14;
    s32 temp_2_15;
    s32 temp_2_16;
    s32 temp_2_17;
    s32 temp_2_18;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s64 var_22;
    s64 var_23;
    u16 temp_18_11;
    u16 temp_18_13;
    u16 temp_18_15;
    u16 temp_18_17;
    u16 temp_18_19;
    u16 temp_18_21;
    u16 temp_18_23;
    u16 temp_18_25;
    u16 temp_18_3;
    u16 temp_18_5;
    u16 temp_18_7;
    u16 temp_18_9;
    u16 temp_21;
    u16 temp_21_11;
    u16 temp_21_3;
    u16 temp_21_5;
    u16 temp_21_7;
    u16 temp_21_9;
    u16 temp_2;
    u8 temp_4;

    spBC = arg3;
    temp_22 = arg2 & 0xFFFF;
    if (temp_22 >= 0x1B8) {
        func_0046d730(D_00635938, 0x105E);
    }
    temp_2 = (u16)((*(u16 *)((u8 *)(arg1) + (0))));
    if ((((*(u16 *)((u8 *)(arg0) + (0))) & 4) != (temp_2 & 4)) && (((s64) ((((*(s32 *)((u8 *)(arg0) + (0x14))) & 0x100000) != 0) << 0x38) >> 0x38) > 0)) {
        (*(s16 *)((u8 *)(arg1) + (0x2C))) = 0xB2;
        return 4;
    }
    temp_18 = arg2 & 0xFFFF;
    temp_19 = temp_18 * 0x28;
    temp_4 = (u8)(iGpffffb3b8[temp_19 + 0x24]);
    switch (temp_4) {                               /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        if ((*(s32 *)((u8 *)(arg1) + (0xC))) & 4) {
            return 1;
        }
        return 4;
    case 7:                                         /* switch 1 */
        if (temp_2 & 0x1000) {
            var_2 = 4;
        } else {
            var_2 = 1;
        }
        return var_2;
    case 8:                                         /* switch 1 */
        if (temp_2 & 0x1000) {
            var_2_2 = 1;
        } else {
            var_2_2 = 4;
        }
        return var_2_2;
    case 9:                                         /* switch 1 */
        if (func_00243e30(arg1) != 0) {
            return 0x100;
        }
    default:                                        /* switch 1 */
        if ((arg0 != NULL) && (temp_22 < 0x1B8) && (iGpffffb3b8[temp_19] & 2)) {
            if ((*(u16 *)((u8 *)(arg0) + (0))) & 4) {
                var_23 = (s64) ((s64) (*(u8 *)((u8 *)((((*(u16 *)((u8 *)(arg0) + (2))) * 0x3C) + (s32)iGpffffb3c4)) + (0x38))) << 0x30) >> 0x30;
            } else {
                var_23 = (s64) (func_00106a30((s64) ((func_00106cd0((s16) (*(u16 *)((u8 *)(arg0) + (2))), 0) & 0xFFFF) << 0x30) >> 0x30) << 0x30) >> 0x30;
            }
        } else {
            var_23 = (s64) *((u8 *)((s32)iGpffffb3b4 + (temp_18 * 2)));
        }
        temp_18_2 = (s64) (var_23 << 0x30) >> 0x30;
        if (temp_18_2 >= 0x13) {
            func_0046d730(D_00635938, 0xE47);
        }
        temp_30 = 1 << (temp_18_2 + 1);
        if (!(temp_30 & 0xE0001)) {
            if (temp_30 & 2) {
                if (((s64) ((((*(s32 *)((u8 *)(arg1) + (0x14))) & 0x10000) != 0) << 0x38) >> 0x38) > 0) {
                    (*(s32 *)((u8 *)(arg1) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg1) + (0x18))) | 0x10000);
                    return 0x200;
                }
                if (!(spBC & 2) && !(iGpffffb3b8[temp_19] & 0x40)) {
                    var_22 = 0;
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_4 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_4 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5 = 0;
loop_60:
                    if ((var_5 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_2 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_2 >= 0)) && (func_001069a0((s16)temp_2_2) == 0x1F8)) {
                            var_2_5 = 1;
                        } else {
                            var_2_5 = 0;
                        }
                    } else if (*((u8 *)(var_2_4 + ((var_5 & 0xFFFF) * 2))) == 0x1F8) {
                        var_2_5 = 1;
                    } else {
                        var_5 = (var_5 + 1) & 0xFFFF;
                        goto loop_60;
                    }
                    if (var_2_5 == 0) {
                        if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                            var_2_6 = 0;
                        } else {
                            var_2_6 = (s32)(func_00232880((*(u16 *)((u8 *)(arg1) + (2))), 0x4A));
                        }
                        if (var_2_6 & 0xFFFF) {
                            goto block_71;
                        }
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_7 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_7 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_2 = 0;
loop_83:
                        if ((var_5_2 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_3 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_3 >= 0)) && (func_001069a0((s16)temp_2_3) == 0x1F7)) {
                                var_2_8 = 1;
                            } else {
                                var_2_8 = 0;
                            }
                        } else if (*((u8 *)(var_2_7 + ((var_5_2 & 0xFFFF) * 2))) == 0x1F7) {
                            var_2_8 = 1;
                        } else {
                            var_5_2 = (var_5_2 + 1) & 0xFFFF;
                            goto loop_83;
                        }
                        if (var_2_8 == 0) {
                            if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                                var_2_9 = 0;
                            } else {
                                var_2_9 = (s32)(func_00232880((*(u16 *)((u8 *)(arg1) + (2))), 0x49));
                            }
                            if (var_2_9 & 0xFFFF) {
                                goto block_94;
                            }
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                                if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                    func_0046d730(D_00635938, 0xFA5);
                                }
                                var_2_10 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                            } else {
                                if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                    func_0046d730(D_00635938, 0xFA8);
                                }
                                var_2_10 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                            }
                            var_5_3 = 0;
loop_106:
                            if ((var_5_3 & 0xFFFF) >= 8) {
                                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_4 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_4 >= 0)) && (func_001069a0((s16)temp_2_4) == 0x1F6)) {
                                    var_2_11 = 1;
                                } else {
                                    var_2_11 = 0;
                                }
                            } else if (*((u8 *)(var_2_10 + ((var_5_3 & 0xFFFF) * 2))) == 0x1F6) {
                                var_2_11 = 1;
                            } else {
                                var_5_3 = (var_5_3 + 1) & 0xFFFF;
                                goto loop_106;
                            }
                            if (var_2_11 == 0) {
                                if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                                    var_2_12 = 0;
                                } else {
                                    var_2_12 = (s32)(func_00232880((*(u16 *)((u8 *)(arg1) + (2))), 0x48));
                                }
                                if (var_2_12 & 0xFFFF) {
                                    goto block_117;
                                }
                            } else {
block_117:
                                var_22 = 0xA;
                                var_20 = 0x11F6;
                            }
                        } else {
block_94:
                            var_22 = 0xF;
                            var_20 = 0x11F7;
                        }
                    } else {
block_71:
                        var_22 = 0x14;
                        var_20 = 0x11F8;
                    }
                    temp_22_2 = (s64) (var_22 << 0x30) >> 0x30;
                    if ((temp_22_2 != 0) && ((s32) (func_003b7060() % 100U) < temp_22_2)) {
                        (*(s16 *)((u8 *)(arg1) + (0x2C))) = var_20;
                        return 0x200;
                    }
                    goto block_124;
                }
                goto block_124;
            }
            if (!(temp_30 & 0x40) && (((s64) ((((*(s32 *)((u8 *)(arg1) + (0x14))) & 0x20000) != 0) << 0x38) >> 0x38) > 0)) {
                (*(s32 *)((u8 *)(arg1) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg1) + (0x18))) | 0x20000);
                return 0x200;
            }
block_124:
            temp_2_5 = (s64)(s32)(func_00242800(arg1, var_23));
            if (temp_2_5 & 0x02000000) {
                return 0x200;
            }
            if (temp_2_5 & 0x04000000) {
                return 0x400;
            }
            if (temp_2_5 & 0x01000000) {
                return 0x100;
            }
            goto block_130;
        }
block_130:
        if (iGpffffb3b8[temp_19 + 0xE] == 0) {
            return 4;
        }
        if ((*(s32 *)((u8 *)(arg1) + (0xC))) & 0x100000) {
            return 1;
        }
        if (func_00243e30(arg1) != 0) {
            return 1;
        }
        if ((s32) iGpffffb3b8[temp_19 + 0xE] >= 0x64) {
            return 1;
        }
        if ((*(u16 *)((u8 *)(arg1) + (0))) & 0x40) {
            return 1;
        }
        if (((u64) ((s64) (*(s32 *)((u8 *)(arg1) + (0xC))) << 0x2C) >> 0x2C) != 1) {
            temp_f21 = func_00233bc0(arg0, 4, arg2);
            temp_f22 = func_00233bc0(arg1, 2, arg2);
            var_f20 = 1.0f;
            var_19 = 0;
            var_20_2 = 0;
            if (!(spBC & 2)) {
                switch (temp_18_2) {                /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_13 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_13 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_4 = 0;
loop_161:
                    if ((var_5_4 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_6 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_6 >= 0)) && (func_001069a0((s16)temp_2_6) == 0x1DD)) {
                            var_2_14 = 1;
                        } else {
                            var_2_14 = 0;
                        }
                    } else if (*((u8 *)(var_2_13 + ((var_5_4 & 0xFFFF) * 2))) == 0x1DD) {
                        var_2_14 = 1;
                    } else {
                        var_5_4 = (var_5_4 + 1) & 0xFFFF;
                        goto loop_161;
                    }
                    if (var_2_14 != 0) {
                        var_f20 *= iGpffff8170;
                        var_20_2 = 0x11DD;
                    } else {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_15 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_15 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_5 = 0;
loop_180:
                        if ((var_5_5 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_7 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_7 >= 0)) && (func_001069a0((s16)temp_2_7) == 0x1DC)) {
                                var_2_16 = 1;
                            } else {
                                var_2_16 = 0;
                            }
                        } else if (*((u8 *)(var_2_15 + ((var_5_5 & 0xFFFF) * 2))) == 0x1DC) {
                            var_2_16 = 1;
                        } else {
                            var_5_5 = (var_5_5 + 1) & 0xFFFF;
                            goto loop_180;
                        }
                        if (var_2_16 != 0) {
                            var_f20 *= fGpffff80cc;
                            var_20_2 = 0x11DC;
                        }
                    }
                    break;
                case 1:                             /* switch 2 */
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_17 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_17 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_6 = 0;
loop_199:
                    if ((var_5_6 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_8 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_8 >= 0)) && (func_001069a0((s16)temp_2_8) == 0x1DF)) {
                            var_2_18 = 1;
                        } else {
                            var_2_18 = 0;
                        }
                    } else if (*((u8 *)(var_2_17 + ((var_5_6 & 0xFFFF) * 2))) == 0x1DF) {
                        var_2_18 = 1;
                    } else {
                        var_5_6 = (var_5_6 + 1) & 0xFFFF;
                        goto loop_199;
                    }
                    if (var_2_18 != 0) {
                        var_f20 *= iGpffff8170;
                        var_20_2 = 0x11DF;
                    } else {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_19 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_19 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_7 = 0;
loop_218:
                        if ((var_5_7 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_9 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_9 >= 0)) && (func_001069a0((s16)temp_2_9) == 0x1DE)) {
                                var_2_20 = 1;
                            } else {
                                var_2_20 = 0;
                            }
                        } else if (*((u8 *)(var_2_19 + ((var_5_7 & 0xFFFF) * 2))) == 0x1DE) {
                            var_2_20 = 1;
                        } else {
                            var_5_7 = (var_5_7 + 1) & 0xFFFF;
                            goto loop_218;
                        }
                        if (var_2_20 != 0) {
                            var_f20 *= fGpffff80cc;
                            var_20_2 = 0x11DE;
                        }
                    }
                    break;
                case 2:                             /* switch 2 */
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_21 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_21 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_8 = 0;
loop_237:
                    if ((var_5_8 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_10 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_10 >= 0)) && (func_001069a0((s16)temp_2_10) == 0x1E1)) {
                            var_2_22 = 1;
                        } else {
                            var_2_22 = 0;
                        }
                    } else if (*((u8 *)(var_2_21 + ((var_5_8 & 0xFFFF) * 2))) == 0x1E1) {
                        var_2_22 = 1;
                    } else {
                        var_5_8 = (var_5_8 + 1) & 0xFFFF;
                        goto loop_237;
                    }
                    if (var_2_22 != 0) {
                        var_f20 *= iGpffff8170;
                        var_20_2 = 0x11E1;
                    } else {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_23 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_23 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_9 = 0;
loop_256:
                        if ((var_5_9 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_11 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_11 >= 0)) && (func_001069a0((s16)temp_2_11) == 0x1E0)) {
                                var_2_24 = 1;
                            } else {
                                var_2_24 = 0;
                            }
                        } else if (*((u8 *)(var_2_23 + ((var_5_9 & 0xFFFF) * 2))) == 0x1E0) {
                            var_2_24 = 1;
                        } else {
                            var_5_9 = (var_5_9 + 1) & 0xFFFF;
                            goto loop_256;
                        }
                        if (var_2_24 != 0) {
                            var_f20 *= fGpffff80cc;
                            var_20_2 = 0x11E0;
                        }
                    }
                    break;
                case 4:                             /* switch 2 */
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_25 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_25 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_10 = 0;
loop_275:
                    if ((var_5_10 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_12 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_12 >= 0)) && (func_001069a0((s16)temp_2_12) == 0x1E3)) {
                            var_2_26 = 1;
                        } else {
                            var_2_26 = 0;
                        }
                    } else if (*((u8 *)(var_2_25 + ((var_5_10 & 0xFFFF) * 2))) == 0x1E3) {
                        var_2_26 = 1;
                    } else {
                        var_5_10 = (var_5_10 + 1) & 0xFFFF;
                        goto loop_275;
                    }
                    if (var_2_26 != 0) {
                        var_f20 *= iGpffff8170;
                        var_20_2 = 0x11E3;
                    } else {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_27 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_27 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_11 = 0;
loop_294:
                        if ((var_5_11 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_13 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_13 >= 0)) && (func_001069a0((s16)temp_2_13) == 0x1E2)) {
                                var_2_28 = 1;
                            } else {
                                var_2_28 = 0;
                            }
                        } else if (*((u8 *)(var_2_27 + ((var_5_11 & 0xFFFF) * 2))) == 0x1E2) {
                            var_2_28 = 1;
                        } else {
                            var_5_11 = (var_5_11 + 1) & 0xFFFF;
                            goto loop_294;
                        }
                        if (var_2_28 != 0) {
                            var_f20 *= fGpffff80cc;
                            var_20_2 = 0x11E2;
                        }
                    }
                    break;
                case 3:                             /* switch 2 */
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_29 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_29 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_12 = 0;
loop_313:
                    if ((var_5_12 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_14 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_14 >= 0)) && (func_001069a0((s16)temp_2_14) == 0x1E5)) {
                            var_2_30 = 1;
                        } else {
                            var_2_30 = 0;
                        }
                    } else if (*((u8 *)(var_2_29 + ((var_5_12 & 0xFFFF) * 2))) == 0x1E5) {
                        var_2_30 = 1;
                    } else {
                        var_5_12 = (var_5_12 + 1) & 0xFFFF;
                        goto loop_313;
                    }
                    if (var_2_30 != 0) {
                        var_f20 *= iGpffff8170;
                        var_20_2 = 0x11E5;
                    } else {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                                func_0046d730(D_00635938, 0xFA5);
                            }
                            var_2_31 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                        } else {
                            if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                                func_0046d730(D_00635938, 0xFA8);
                            }
                            var_2_31 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                        }
                        var_5_13 = 0;
loop_332:
                        if ((var_5_13 & 0xFFFF) >= 8) {
                            if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_15 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_15 >= 0)) && (func_001069a0((s16)temp_2_15) == 0x1E4)) {
                                var_2_32 = 1;
                            } else {
                                var_2_32 = 0;
                            }
                        } else if (*((u8 *)(var_2_31 + ((var_5_13 & 0xFFFF) * 2))) == 0x1E4) {
                            var_2_32 = 1;
                        } else {
                            var_5_13 = (var_5_13 + 1) & 0xFFFF;
                            goto loop_332;
                        }
                        if (var_2_32 != 0) {
                            var_f20 *= fGpffff80cc;
                            var_20_2 = 0x11E4;
                        }
                    }
                    break;
                }
                if ((var_f20 == 1.0f) && (temp_30 & 0x3C)) {
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                            func_0046d730(D_00635938, 0xFA5);
                        }
                        var_2_33 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                    } else {
                        if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                            func_0046d730(D_00635938, 0xFA8);
                        }
                        var_2_33 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                    }
                    var_5_14 = 0;
loop_353:
                    if ((var_5_14 & 0xFFFF) >= 8) {
                        if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_16 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_16 >= 0)) && (func_001069a0((s16)temp_2_16) == 0x1E6)) {
                            var_2_34 = 1;
                        } else {
                            var_2_34 = 0;
                        }
                    } else if (*((u8 *)(var_2_33 + ((var_5_14 & 0xFFFF) * 2))) == 0x1E6) {
                        var_2_34 = 1;
                    } else {
                        var_5_14 = (var_5_14 + 1) & 0xFFFF;
                        goto loop_353;
                    }
                    if (var_2_34 != 0) {
                        var_f20 *= fGpffff80cc;
                        var_20_2 = 0x11E6;
                    }
                }
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                    if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                        func_0046d730(D_00635938, 0xFA5);
                    }
                    var_2_35 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                } else {
                    if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                        func_0046d730(D_00635938, 0xFA8);
                    }
                    var_2_35 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                }
                var_5_15 = 0;
loop_372:
                if ((var_5_15 & 0xFFFF) >= 8) {
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_17 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_17 >= 0)) && (func_001069a0((s16)temp_2_17) == 0x209)) {
                        var_2_36 = 1;
                    } else {
                        var_2_36 = 0;
                    }
                } else if (*((u8 *)(var_2_35 + ((var_5_15 & 0xFFFF) * 2))) == 0x209) {
                    var_2_36 = 1;
                } else {
                    var_5_15 = (var_5_15 + 1) & 0xFFFF;
                    goto loop_372;
                }
                if (var_2_36 != 0) {
                    return 1;
                }
                if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4)) {
                    if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0xB) {
                        func_0046d730(D_00635938, 0xFA5);
                    }
                    var_2_37 = (s32)(func_001094e0((*(u16 *)((u8 *)(arg1) + (2)))));
                } else {
                    if ((s32) (*(u16 *)((u8 *)(arg1) + (2))) >= 0x150) {
                        func_0046d730(D_00635938, 0xFA8);
                    }
                    var_2_37 = (s32)((s32)iGpffffb3c4 + ((*(u16 *)((u8 *)(arg1) + (2))) * 0x3C) + 0xE);
                }
                var_5_16 = 0;
loop_391:
                if ((var_5_16 & 0xFFFF) >= 8) {
                    if (!((*(u16 *)((u8 *)(arg1) + (0))) & 4) && (temp_2_18 = func_00106cd0((s16) (*(u16 *)((u8 *)(arg1) + (2))), 2) & 0xFFFF, (temp_2_18 >= 0)) && (func_001069a0((s16)temp_2_18) == 0x208)) {
                        var_2_38 = 1;
                    } else {
                        var_2_38 = 0;
                    }
                } else if (*((u8 *)(var_2_37 + ((var_5_16 & 0xFFFF) * 2))) == 0x208) {
                    var_2_38 = 1;
                } else {
                    var_5_16 = (var_5_16 + 1) & 0xFFFF;
                    goto loop_391;
                }
                if (var_2_38 != 0) {
                    var_f20 *= 0.5f;
                }
                goto block_399;
            }
block_399:
            temp_17 = (s32)(func_00244f60(4, arg0, arg1, arg2, 0));
            temp_2_19 = (s32)((*(u16 *)((u8 *)(arg1) + (0))) & 4);
            if (temp_2_19 == 0) {
                if (temp_18_2 != 0) {

                } else {
                    if (temp_2_19 != 0) {
                        var_2_39 = 0;
                    } else {
                        temp_21 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_2 = (s64) ((s64) temp_21 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_2, 0)) & 0xFFFF) == 0x74) {
                            var_2_39 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_2, 1)) & 0xFFFF) == 0x74) {
                            var_2_39 = 1;
                        } else {
                            var_2_39 = 0;
                        }
                    }
                    if (var_2_39 != 0) {
                        var_19 = 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_40 = 0;
                    } else {
                        temp_21_3 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21_3 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_4 = (s64) ((s64) temp_21_3 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_4, 0)) & 0xFFFF) == 0x75) {
                            var_2_40 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_4, 1)) & 0xFFFF) == 0x75) {
                            var_2_40 = 1;
                        } else {
                            var_2_40 = 0;
                        }
                    }
                    if (var_2_40 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_41 = 0;
                    } else {
                        temp_21_5 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21_5 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_6 = (s64) ((s64) temp_21_5 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_6, 0)) & 0xFFFF) == 0x76) {
                            var_2_41 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_6, 1)) & 0xFFFF) == 0x76) {
                            var_2_41 = 1;
                        } else {
                            var_2_41 = 0;
                        }
                    }
                    if (var_2_41 != 0) {
                        var_19 += 0x14;
                    }
                }
                if ((temp_18_2 != 4) && (temp_18_2 != 3) && (temp_18_2 != 2) && (temp_18_2 != 1)) {

                } else {
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_42 = 0;
                    } else {
                        temp_21_7 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21_7 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_8 = (s64) ((s64) temp_21_7 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_8, 0)) & 0xFFFF) == 0x83) {
                            var_2_42 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_8, 1)) & 0xFFFF) == 0x83) {
                            var_2_42 = 1;
                        } else {
                            var_2_42 = 0;
                        }
                    }
                    if (var_2_42 != 0) {
                        var_19 += 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_43 = 0;
                    } else {
                        temp_21_9 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21_9 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_10 = (s64) ((s64) temp_21_9 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_10, 0)) & 0xFFFF) == 0x84) {
                            var_2_43 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_10, 1)) & 0xFFFF) == 0x84) {
                            var_2_43 = 1;
                        } else {
                            var_2_43 = 0;
                        }
                    }
                    if (var_2_43 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_44 = 0;
                    } else {
                        temp_21_11 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_21_11 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_21_12 = (s64) ((s64) temp_21_11 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_21_12, 0)) & 0xFFFF) == 0x85) {
                            var_2_44 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_21_12, 1)) & 0xFFFF) == 0x85) {
                            var_2_44 = 1;
                        } else {
                            var_2_44 = 0;
                        }
                    }
                    if (var_2_44 != 0) {
                        var_19 += 0x14;
                    }
                }
                switch (temp_18_2) {                /* switch 3; irregular */
                case 1:                             /* switch 3 */
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_45 = 0;
                    } else {
                        temp_18_3 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_3 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_4 = (s64) ((s64) temp_18_3 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_4, 0)) & 0xFFFF) == 0x77) {
                            var_2_45 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_4, 1)) & 0xFFFF) == 0x77) {
                            var_2_45 = 1;
                        } else {
                            var_2_45 = 0;
                        }
                    }
                    if (var_2_45 != 0) {
                        var_19 += 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_46 = 0;
                    } else {
                        temp_18_5 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_5 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_6 = (s64) ((s64) temp_18_5 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_6, 0)) & 0xFFFF) == 0x78) {
                            var_2_46 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_6, 1)) & 0xFFFF) == 0x78) {
                            var_2_46 = 1;
                        } else {
                            var_2_46 = 0;
                        }
                    }
                    if (var_2_46 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_47 = 0;
                    } else {
                        temp_18_7 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_7 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_8 = (s64) ((s64) temp_18_7 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_8, 0)) & 0xFFFF) == 0x79) {
                            var_2_47 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_8, 1)) & 0xFFFF) == 0x79) {
                            var_2_47 = 1;
                        } else {
                            var_2_47 = 0;
                        }
                    }
                    if (var_2_47 != 0) {
                        var_19 += 0x14;
                    }
                    break;
                case 2:                             /* switch 3 */
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_48 = 0;
                    } else {
                        temp_18_9 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_9 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_10 = (s64) ((s64) temp_18_9 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_10, 0)) & 0xFFFF) == 0x7A) {
                            var_2_48 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_10, 1)) & 0xFFFF) == 0x7A) {
                            var_2_48 = 1;
                        } else {
                            var_2_48 = 0;
                        }
                    }
                    if (var_2_48 != 0) {
                        var_19 += 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_49 = 0;
                    } else {
                        temp_18_11 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_11 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_12 = (s64) ((s64) temp_18_11 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_12, 0)) & 0xFFFF) == 0x7B) {
                            var_2_49 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_12, 1)) & 0xFFFF) == 0x7B) {
                            var_2_49 = 1;
                        } else {
                            var_2_49 = 0;
                        }
                    }
                    if (var_2_49 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_50 = 0;
                    } else {
                        temp_18_13 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_13 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_14 = (s64) ((s64) temp_18_13 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_14, 0)) & 0xFFFF) == 0x7C) {
                            var_2_50 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_14, 1)) & 0xFFFF) == 0x7C) {
                            var_2_50 = 1;
                        } else {
                            var_2_50 = 0;
                        }
                    }
                    if (var_2_50 != 0) {
                        var_19 += 0x14;
                    }
                    break;
                case 3:                             /* switch 3 */
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_51 = 0;
                    } else {
                        temp_18_15 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_15 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_16 = (s64) ((s64) temp_18_15 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_16, 0)) & 0xFFFF) == 0x80) {
                            var_2_51 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_16, 1)) & 0xFFFF) == 0x80) {
                            var_2_51 = 1;
                        } else {
                            var_2_51 = 0;
                        }
                    }
                    if (var_2_51 != 0) {
                        var_19 += 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_52 = 0;
                    } else {
                        temp_18_17 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_17 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_18 = (s64) ((s64) temp_18_17 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_18, 0)) & 0xFFFF) == 0x81) {
                            var_2_52 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_18, 1)) & 0xFFFF) == 0x81) {
                            var_2_52 = 1;
                        } else {
                            var_2_52 = 0;
                        }
                    }
                    if (var_2_52 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_53 = 0;
                    } else {
                        temp_18_19 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_19 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_20 = (s64) ((s64) temp_18_19 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_20, 0)) & 0xFFFF) == 0x82) {
                            var_2_53 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_20, 1)) & 0xFFFF) == 0x82) {
                            var_2_53 = 1;
                        } else {
                            var_2_53 = 0;
                        }
                    }
                    if (var_2_53 != 0) {
                        var_19 += 0x14;
                    }
                    break;
                case 4:                             /* switch 3 */
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_54 = 0;
                    } else {
                        temp_18_21 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_21 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_22 = (s64) ((s64) temp_18_21 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_22, 0)) & 0xFFFF) == 0x7D) {
                            var_2_54 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_22, 1)) & 0xFFFF) == 0x7D) {
                            var_2_54 = 1;
                        } else {
                            var_2_54 = 0;
                        }
                    }
                    if (var_2_54 != 0) {
                        var_19 += 0xA;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_55 = 0;
                    } else {
                        temp_18_23 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_23 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_24 = (s64) ((s64) temp_18_23 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_24, 0)) & 0xFFFF) == 0x7E) {
                            var_2_55 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_24, 1)) & 0xFFFF) == 0x7E) {
                            var_2_55 = 1;
                        } else {
                            var_2_55 = 0;
                        }
                    }
                    if (var_2_55 != 0) {
                        var_19 += 0xF;
                    }
                    if ((*(u16 *)((u8 *)(arg1) + (0))) & 4) {
                        var_2_56 = 0;
                    } else {
                        temp_18_25 = (u16)((*(u16 *)((u8 *)(arg1) + (2))));
                        if ((s32) temp_18_25 >= 0xB) {
                            func_0046d730(D_00635938, 0x23B);
                        }
                        temp_18_26 = (s64) ((s64) temp_18_25 << 0x30) >> 0x30;
                        if ((func_001069d0(func_00106cd0((s16) temp_18_26, 0)) & 0xFFFF) == 0x7F) {
                            var_2_56 = 1;
                        } else if ((func_001069d0(func_00106cd0((s16) temp_18_26, 1)) & 0xFFFF) == 0x7F) {
                            var_2_56 = 1;
                        } else {
                            var_2_56 = 0;
                        }
                    }
                    if (var_2_56 != 0) {
                        var_19 += 0x14;
                    }
                    break;
                }
            }
            var_17 = (s32)( (var_f20 * (1.0f * (temp_f22 * ((f32) temp_17 * temp_f21))))) - var_19;
            if (var_17 >= 0x64) {
                var_17 = 0x63;
            } else if (var_17 < 0x32) {
                var_17 = 0x32;
            }
            if ((s32) (func_003b7060() % 100U) >= var_17) {
                (*(s16 *)((u8 *)(arg1) + (0x2C))) = var_20_2;
                return 4;
            }
            return 1;
        }
        return 1;
    case 12:                                        /* switch 1 */
        if (func_00242800(arg1, 6) & 0x08000000) {
            return 1;
        }
        if (func_00242800(arg1, 7) & 0x08000000) {
            var_2_3 = 1;
        } else {
            var_2_3 = 4;
        }
        return var_2_3;
    case 14:                                        /* switch 1 */
        if ((u8) (*(s32 *)((u8 *)(arg1) + (0xC))) != 0) {
            return 1;
        }
        return 4;
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e6f0);
#endif

/* measured 002411a0: configured b210 gives 16 differing words, including after
 * resolving all 70 relocations, at 2588/2592B (four zero tail bytes). The prior
 * guarded draft is 473 words at 2584B. Restoring the actual repeated searches,
 * native conversion boundaries and conversion-before-bonus order removes the
 * extra saved-register pressure. opt_loop_invariants on scopes the searches;
 * opt_common_subs on scopes the main body. The initial index/element register
 * assignment still differs. All 79 siblings and allocated data are unchanged.
 * The fifth argument is passed by func_001f14f0 and unused by retail.
 * See docs/probe_archive/DC_worker7_20260920_recovery_floors.md. */
// FUN_002411A0 NONMATCHING
#ifdef SKIP_ASM
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

#pragma opt_common_subs on
s32 func_002411a0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 idx;
    s32 tmp22;
    s32 lvl;
    s32 bits;
    u16 element;
    u16 enemyElement;
    s32 res;
    s32 base;
    s32 thresh;
    f32 f20;
    u8 *entry;
    u8 kind;
    u16 id16;
    s16 id;
    u8 *tab;
    u16 i;
    s32 found;
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
            base = func_00244f60(5, arg0, arg1, arg2, 0);
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
#else
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002411a0);
#endif

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
   frame 0x50 vs 0x60 — 4 rst saved vs 5, branch targets shifted); the
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
