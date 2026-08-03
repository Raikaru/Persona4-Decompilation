#include "type.h"
#include "include_asm.h"


extern u32 RpRandom(void);
extern void func_0046d730(u8 *arg0, s32 arg1);
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

extern u32 func_00232290(DatUnit* unit);

extern s32 func_00106600(s16 arg);

/* gp - 0x4C48 = 0x007690f0 - 0x4c48 = 0x007644a8 */
extern u8 *iGpffffb3b8;
/* gp - 0x4C40 = 0x007690f0 - 0x4c40 = 0x007644b0 */
extern u8 *iGpffffb3c0;

extern u8 *func_00106820(s16 arg0);

/* Old-style declaration: the retail call site at func_00232aa0 passes arg0 raw (no 64-bit extension). */
u16 func_00243920();

extern u32 func_00104dc0();
extern u32 func_001056e0();
extern u32 func_00104e30();
extern u32 func_00105730();
extern u32 func_00105d50();

extern u8 *func_001094e0(u16 arg0);
extern s32 func_0010a900(u16 arg0);
extern s32 func_00109390(s32 arg0);
extern u32 func_00105ed0(void);
extern u8 *func_00105510(s32 arg0);
extern u32 func_00232c70(u8 *arg0, s32 arg1);
/* Defined below in this file; used before its definition. */
extern u16 func_002439c0(u8 *arg0);
extern u32 func_00106cd0(s16 arg0, s32 arg1);
extern u32 func_001069d0(u32 arg0);
extern s32 func_00106a30(s16 arg0);
extern u32 func_001069a0(s16 arg0);

extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
extern s32 func_00238940(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern s32 func_00235520(s32 arg0, u8 *arg1, u8 *arg2, u16 arg3, u16 arg4, u16 arg5, s32 arg6, u8 arg7);
extern u32 func_002397d0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5);
extern u32 func_00106330(s32 arg0);
extern s32 func_00109980(s32 arg0, s32 arg1);
extern s64 func_00233570(u8 *arg0, s32 arg1, s64 arg2);
extern s32 func_00241bc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 func_00244f60(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
extern u16 func_00247cb0(s16 arg0);
extern u16 func_00107ac0(u16 arg0);
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
extern u32 func_00109bf0(u32 arg0, s32 arg1);
extern s32 func_00106940(s16 arg0);
extern s32 func_00106970(s16 arg0);
extern u32 func_0023d9b0(u8 *arg0, s32 arg1);
extern s32 func_0023d8e0(u8 *arg0, s32 arg1);
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

/* measured: mwcc hoists the 0xFFFF mask constant into a saved register
   (ori $s1, $zero, 0xffff) and masks temp_16 at its definition instead of
   loading lhu raw into $s0 like retail; frame 0x50 vs 0x40, obj over
   window. Tried s32 temp_16, (u16) cast at definition, (u16) cast at
   uses; all nd 157-178. */
// FUN_00231F80
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00231f80);

/* measured: load-sinking floor in the table-index block; retail loads the
   iGpffffb3c4 base (lw $a0,-0x4c3c($gp)) BEFORE the mask/mul chain while
   mwcc sinks the lw after the *0x3C mul regardless of statement order
   (inline, base-local, index-first all tried; nd 6). Everything else now
   matches: mask-at-def was broken by mixing (u16) cast (asserts) with
   & 0xFFFF (index) spellings, and the clamp needs `var_3 > 0x3E7` to get
   the slti-$at form. */
// FUN_00232290
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232290);
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




// FUN_00232730
s32 func_00232730(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_18;
    s32 var_5;
    u8 *base;
    s32 result;
    s32 limit;

    temp_18 = func_0023e130(arg0) & 0xFFFF;
    base = func_0023e140(arg0);
    var_5 = 0;
    temp_16 = arg1 & 0xFFFF;
    limit = temp_18 & 0xFFFF;
    while ((var_5 & 0xFFFF) < limit) {
        if (temp_16 == *(u16 *)(base + ((u16)var_5 * 2))) {
            return 1;
        }
        var_5 = (var_5 + 1) & 0xFFFF;
    }
    if (!(*(u16 *)arg0 & 4)) {
        result = (s32)((u32)func_00106cd0(*(s16 *)(arg0 + 2), 2) & 0xFFFF);
        if (result >= 0) {
            if (temp_16 == func_001069a0((s16)result)) {
                return 1;
            }
        }
    }
    return 0;
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
u16 func_00232880(s32 arg0, s32 arg1)
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
// FUN_00232B40
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232b40);

/* measured: retail guard `andi $v0,$s0,0xFFFF; bltz $v0` tests the MASKED value and
   keeps the dead bltz; mwcc b210 deletes `(arg1&0xFFFF)<0` (proves non-negative) and
   emits `bltz $s0` on the raw arg1 (tried masked-m, raw-arg1, s16 m, tip mask-order:
   all nd >= 25). The `& 0x80` branch materializes a boolean `sltu $v1,$zero,$v1`
   retail keeps (mine folds to beqz, even stored as a flag), and the `return 1` /
   `0x63` consts load as `daddiu` retail-wide (mine `addiu`). Floor family: dead
   masked-sign bltz + boolean-materialization + u8-const-daddiu. */
// FUN_00232C70
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232c70);

/* measured: recipe-A-family re-test 2026-08-03. The u16-table shape now
   matches retail byte-for-byte outside the loop preheader (u16 loads, the
   2-arg func_00106cd0 call, dsll32/dsra32 (s16) arg, goto-done tail with
   the 0-def after the calls and the bltz guard). Residual is the
   loop-register rotation floor: retail hoists the compare constant
   (0x1F9..0x1FE) pre-loop in $a0 with limit in $a1 and counter in $a2;
   mwcc b210 always puts the counter in $v1, limit in $a2 and
   rematerializes the constant in the body. Measured: natural-while nd ~90,
   opt_loop_invariants on nd 80 (hoists the constant but keeps counter
   $v1/limit $a2/constant $a1), named constant locals nd 92 (assignment
   sunk into the body), while(1)-break draft shape nd 302. The matched
   twins func_00232730/func_00242360 allocate their 2-value loops to
   $a1/$a0, so a third loop value shifts mwcc's pool to $v1/$a2/$a1; no
   declaration order fixes it. */
// FUN_00232D80
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00232d80);

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

/* measured: full logic in the right order but saved-register rotation
   never stabilises: retail colors arg1=$s1/temp_18=$s2 and reuses $s1
   for temp_17 (sra) and $s0 for temp_16, while mwcc b210 swaps
   arg1/temp_18 (nd from the first move), keeps temp_17 in temps and
   saves the masked values, and with separate mask vars (temp_2/
   temp_3_3/temp_2_3) pushes temp_22 to $s7 (frame 0x90) and hoists
   ori $0xffff. Tried m2c decl order, (u8)arg1 mask split, single-p
   variants; best obj 756B. s8/s16 dsll32/dsra32 dance otherwise
   matches. */
// FUN_00233570
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233570);

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

/* measured: recipe A applied across all 6 case bodies -- s32 temp_3 from
   the raw lbu keeps the single bltz, the (u32) cast makes the shift srl,
   `(f32)(s32)` on the OR result kills the duplicated-arm guard, doubling
   is `var_f1 = var_f1 + var_f1` (add.s, not mul.s), and the per-case
   mtc1/cvt.s.w/div.s/2.5f/0.75f/iGpffff8110 sequences compile in retail
   shape. Also measured: arg1 must be s32 (an s16 param emits a spurious
   dsll32/dsra32 at the save), and the second 0x4F5 error test needs
   `temp_16 > 1` (not >= 2) for the slti-$at+bnez form. Best nd 290; the
   residuals are five independent register/scheduling artifacts: the
   call-path `(s64)(s32)func_002332a0(...)` emits an extra dsll32/dsra32-
   by-24 pair where retail extends only at the merge (var_2 s64; a s32
   var_2 rotates the saved registers and drops the call), the merge pair
   splits as dsll32 $v0/dsra32 $s0 instead of retail's dsll32 $s0, the
   else-path mask chain rotates (sllv/and dest), `(temp_2 != 0) & 0xFFFF`
   folds the assignment andi, and the doubled-path OR lands in $v1 vs
   retail $a0. */
/* measured 2026-08-03 (re-test): ported the m2c draft with recipe A
   (s32 temp_3 from the raw lbu keeps the single bltz; (u32) cast for srl;
   (f32)(s32) on the OR result; var_f1 + var_f1 doubling; arg1 s32;
   temp_16 > 1 for the slti-$at 0x4F5 form) -> nd 276, confirming the
   earlier 290. Residuals unchanged (five independent register/scheduling
   artifacts): the call-path s8->s64 extension emits an extra
   dsll32/dsra32 pair where retail extends only at the merge, the merge
   pair splits as dsll32 $v0/dsra32 $s0 vs retail's dsll32 $s0, the
   else-path mask chain rotates, (temp_2 != 0) & 0xFFFF folds the
   assignment andi, and the doubled-path OR lands in $v1 vs retail $a0.
   func_0010a9b0 is 1-arg (retail preps only $4); iGpffffb408/-0x4BF8
   base; iGpffff8110/-0x7EF0 float. */
// FUN_00233BC0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00233bc0);

/* measured: nd 805 with a full C body, object 1880B against a 1904B window.
   Wave 7 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a floor: re-attempt from the m2c draft with the
   wave's recipes before treating any of it as settled. */
// FUN_002340C0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002340c0);

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

/* measured: retail emits a merge-point s8 re-truncation for the skill value
   (paths leave $v1, .L002351A8 truncates into $s5) and re-derives
   temp_17&0xFFFF from a saved temp_17; mwcc shares the path truncation and
   saves the masked temp instead. Tried (u8) call args, s32 temp + post-if
   assignment, pointer locals; best nd 93 (allocation cascade). */
// FUN_00235110
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235110);

/* measured: retail emits the full s8 ext/sll/ext dance for `var_17 = (s8)(var_17*2)`
   (var_17 init 3) but mwcc b210 constant-folds it to `addiu 6` via SSA const-prop
   (the s8->s32 conversion only materializes when the value is live across the
   loop, e.g. the ext17 hoist). Tried literal/variable forms, s8/u16/s32
   typings, and v17-temp materialization; all fold. Rest of the function
   (u16 temp_18 vs cross-call mask CSE, merge-point (s8) casts, sltu
   booleanize) now matches; nd 92 from the fold ripple. */
// FUN_00235320
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235320);

// FUN_00235520
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00235520);

// FUN_002384B0
s32 func_002384b0(s32 arg0, u8 *arg1, s32 arg2)
{
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

    if (iGpffffb448[(arg0 & 0xFFFF) * 0x28 + 0x24] != 6) {
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

/* measured: nd 792 after 1 full attempt. Head logic (0xA30 assert,
   0x80000 early return, the 24-bit var_17 bitmask, the bit-scan loop
   with the sp+0xA0 s16 array, the temp_3_2 1/3 gate, the 0xE-vs-switch
   split, the case 1/7/8/9 returns, the 47-block with the
   d740/a6b0/0x27000000/0x100000 checks) compiles in retail shape, but
   the s16 arr[0x18] local lands the frame at 0xB0 vs retail 0xD0 (arr
   at sp+0x90 instead of sp+0xA0) and mwcc saves 7 registers vs
   retail's 9 ($s7 for the case-loop limits, $23) — every later
   instruction shifts. The 9 jtbl cases each need their own temp_23/
   temp_4 pair; temp_4 is reused as the 0xE-check pointer here, which
   corrupts the case bodies. */
// FUN_00238940
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00238940);

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
    temp_4 = (u8 *)(off + (s32)iGpffffb448);
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

/* measured: 5 words off — mwcc emits `addu $a0,$v0,$v1` (base-first) and
   `or $v1,$a0,$v1` where retail has index-first addu and the high mask in
   $a0. uVar6 one-statement (lw-first) vs two-statement (register $v1)
   forms, s32-cast add, and swapped operand orders all probed; the shift-pair
   extraction condition also DSE-eliminates the whole low-bits store, so
   `(var_21 & 0xFFFFF) != 0` is required. */
// FUN_00239F50
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00239f50);

/* measured: retail places each `return 0` OUT OF LINE (bnez to it) and
   re-masks the lhu'd sp/hp with andi at the compare; mwcc inlines the
   return-0 (beqz skip) and eliminates the redundant mask via u16 range
   tracking. sltu booleanize fixed via value-context; slt form fixed via
   (s32) casts; block placement and the andi remain, nd ~28. */
// FUN_0023A1E0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a1e0);

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




// FUN_0023A6B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023a6b0);

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
s32 func_0023d8e0(u8 *arg0, s32 arg1)
{
    s32 v;

    if (arg0 != 0 && (arg1 & 0xFFFF) < 0x1B8 &&
        (iGpffffb3b8[(arg1 & 0xFFFF) * 0x28] & 2)) {
        if (*(u16 *)arg0 & 4) {
            v = iGpffffb3c4[*(u16 *)(arg0 + 2) * 0x3C + 0x38];
        } else {
            v = (s16)func_00106a30((s16)(func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        v = (s8)iGpffffb3b4[(arg1 & 0xFFFF) * 2];
    }
    return v;
}
/* measured 2026-08-03: full C body rebuilt from retail; frame -0x50,
   saved regs s0=temp_16/s1=var_17/s2=arg1/s3=arg0, switch dispatch,
   error calls, found-tail (srl + clamp to 1), case-2 lhu read and
   if/else polarity all match. Best nd 132: mwcc b210 CSEs the
   (u16)arg1 mask across the error call into s1 no matter the spelling
   ((u16)arg1, (s32)(u16)arg1, (u16)(arg1 & 0xFFFF) all fold/CSE) while
   retail re-masks fresh at every site (test, temp_16, case-1 chain,
   case-2 else, case-2 mult = five separate andis); a 3rd distinct
   spelling (u32)arg1 % 0x10000U bloats the object 24B. Also: the loop
   compare constant 0x20B/0x20A is hoisted pre-loop into $a0 by retail
   but materialized per-iteration by b210 (== form booleanizes to
   xori/sltiu; != continue and goto-inc forms give nd 183-185), and
   var_17 must be u32 for the srl shift while the /100 division stays
   signed (s32 temps). */
// FUN_0023D9B0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023d9b0);
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
s32 func_0023dfe0(void)
{
    return 0;
}

/* measured: loop-invariant hoisting fixed via opt_loop_invariants, but mwcc
   allocates var_4/var_3/temp_8 to $t1/$t2/$a1 where retail uses $a0/$v1/$t0
   (systematic rotation; probe batch of 4 spelling variants all nd 61). */
// FUN_0023DFF0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023dff0);

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
    return func_00106cd0(*(s16 *)(arg0 + 2), 0) & 0xFFFF;
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

/* measured: case 0's lhu path compiles mul-before-base-lw while retail
   hoists the iGpffffb3c4 load above the *0x3C (sibling lbu case 1 matches);
   tried inline, offset-local, and pointer-cast spellings, nd 7. */
/* measured 2026-08-03: full C body rebuilt; nd 7, only residual is the
   case-0 lhu block. Everything else matches byte-for-byte (frame, both
   switch dispatches (tests 2/1/0 desc, bodies asc), error calls, the
   (s16) dsll32/dsra32 args, case-1 lbu with retail's hoisted base lw,
   case-2, the shared return-0). Case 0 is a scheduler floor: retail
   hoists the iGpffffb3c4 base lw above the *0x3C andi-chain into $a0;
   mwcc b210 sinks it after the chain into $v0 regardless of spelling
   (inline cast, &arr[u8], (u16) double cast, u16*-element index,
   chain-first addition order, pointer local: all nd 7, &arr[u8] nd 83).
   The sibling lbu case 1 hoists fine; only the lhu case does not. */
// FUN_0023E3E0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e3e0);

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
        v = func_00106cd0((s16)id, 1) & 0xFFFF;
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

// FUN_0023E6F0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_0023e6f0);

/* measured: saved-register rotation on (arg2, temp_22) — retail colors
   arg2=$s2/temp_22=$s6, mwcc b210 always colors arg2=$s6/temp_22=$s2
   (first move on) regardless of declaration order, type (s32/u16), or
   the || vs switch dispatch form, cascading into every later register
   (nd 521). Structure otherwise verified: switch-dispatch (declared
   0x200,0x400,0x100,2,4 reversed-test order) matches, the two loops,
   the flag/0x3C-0x3E checks, the f20 dance, the shared ret1 via
   goto-label all compile in retail shape. */
// FUN_002411A0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_002411a0);

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
   merge itself ((s16)var_2_2 into $s0) matches. */
// FUN_00241BC0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00241bc0);

/* measured: match reached nd 7 (of 64). All branch/return layout and the switch
   (case 9/0xA in ascending declaration -> reversed test order) match exactly. The
   only residual is the iGpffffb3b8 base-pointer load ORDER: retail loads it FIRST
   into $a0 (lw $a0,-0x4c48($gp)) then computes the 0x28 stride index; mwcc b210
   sinks the load to its use (loads last into $v0). Tried inline, hoisted base
   local (frame grew to 0x70, nd 70), idx local, struct-field, decl-order swap:
   all nd 7. Load-sinking floor family. */
// FUN_00241DE0
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00241de0);

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
        flag3 = (iGpffffb448[(u16)arg2 * 0x28] & 2) != 0;
        if (flag3) {
            var_17 = 0x32;
        }
        temp_3 = arg4 & 0xFFFF;
        if (temp_3 == 2 || temp_3 == 4) {
            var_17 = 0x64;
        }
    } else {
        var_17 = iGpffffb448[(u16)arg2 * 0x28 + 0x26];
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
            if (!(*(u16 *)arg0 & 4) && (temp_2_2 = func_00106cd0((s16)*(u16 *)(arg0 + 2), 2) & 0xFFFF, (s32)temp_2_2 >= 0) &&
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

/* measured: nd 170 after 4 attempts. All 8 skill-search loops match
   (while+goto-done form, opt_loop_invariants hoist, (u16)var_5 body
   masks), the 0x231/0x232/0x210/0x20F/0x211-0x222 dispatch and the
   func_00106600/0x3C-0x3E checks compile in retail shape, but the
   0x210/0x20F block section lays out ~0x90 earlier (block_161 and the
   &4-else goto target shifts, branch targets differ) and the
   return-0x231/-1 early returns share the final move block instead of
   retail's per-site moves. The (s16)var_17==-1 tests, 47cb0/107ac0 tail
   and index-first addu need the off-local form. */
// FUN_00242990
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00242990);

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

/* measured: saved-register allocation; retail uses 7 saved regs incl. a
   loop pointer hoisted to $s6 (addiu $22,$16,0x22 across the 0x106330
   call) while mwcc reuses arg0's slot for var_21 and re-derives the
   pointer, frame 0x70 vs 0x80, nd 156. Tried separate loop vars, top-level
   pointer locals, m2c declaration order. */
// FUN_00243A30
INCLUDE_ASM("asm/nonmatchings/datCalc", func_00243a30);

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
s8 func_00243e90(u8 *arg0)
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
        goto err1682;
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
    err1682:
        func_0046d730(D_00635938, 0x1682);
        break;
    }
    return var_16;
}
// FUN_00244100
void func_00244100(void)
{
}
