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

extern s32 func_0014a230(s32 field, s32 room);
extern s32 func_0014a2a0(s32 field, s32 room);
extern s32 func_0015a740();
extern s32 func_00106600(s16 id);
extern s16 func_001060b0(void);
extern u8 func_001060c0(void);
extern s64 func_00110960(s32 day, u32 time);
extern u32 datGetFlag(s32 bit);
extern u32 RpRandom(void);
extern void func_0046d730(void *file, s32 line);
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
    if ((func_0014a230(arg0, arg1) == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
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
    if ((func_0014a230(arg0, arg1) == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
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
    if ((func_0014a230(arg0, arg1) == 1) || (func_0014a2a0(arg0, arg1) == 1)) {
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
// FUN_00161630
/* Choose a category, then draw an encounter from its weighted entries.
 * The three categories occupy entries [0,20), [20,25), and [25,30).
 * Return the encounter ID in the low halfword and the category bits above it.
 * Measured b210 -O2: 888/896 bytes, 19 resolved relocations, eight zero bytes.
 * Retained propagation preserves address lifetimes; the unsigned table-index
 * expression keeps the threshold lookup distinct from the cached signed offset. */
#pragma push
#pragma opt_propagation off
s32 func_00161630(s32 field, s32 room, s32 encounter, s32 level)
{
    u16 selected;
    f32 multiplier;
    u16 tableId;
    s32 day;
    s32 alternate;
    s32 tableOffset;
    s32 total;
    s32 kind;
    s32 first;
    s32 last;
    s32 sum;
    s32 index;
    s32 alternateOffset;
    s32 draw;
    s32 cumulative;
    s32 normalRate;
    u8 *tables;
    u8 *table;
    u8 *entries;

    selected = 0xFFFF;
    multiplier = 1.0f;
    if (func_0014a230(field, room) == 1 || func_0014a2a0(field, room) == 1) {
        tableId = *(u16 *)(iGpffffb41c + (u16)encounter * 10);
    } else {
        return -1;
    }
    day = (s16)func_001060b0();
    alternate = (s8)func_00110960(day, func_001060c0() & 0xFF) == 1;
    if (datGetFlag(0x1411) == 1) {
        multiplier = 100.0f;
    }
    field = (u16)field;
    if ((field == 0x28 || field == 0x3C) && datGetFlag(0xC0F) == 0) {
        multiplier = 0.0f;
    }
    tableOffset = tableId * 0xF8;
    total = *(u8 *)(iGpffffb418 + tableOffset + alternate);
    if (datGetFlag(0x1410) == 0) {
        s32 available = (s32)(u16)level;
        if (available > 0) {
            total += (s32)multiplier *
                *(u8 *)((u8 *)encSlot(alternate, encSlot(tableOffset, (u32)iGpffffb418)) + 2);
        }
        if (available >= 2) {
            total += *(u8 *)((u8 *)encSlot(alternate, encSlot(tableOffset, (u32)iGpffffb418)) + 4);
        }
    }
    if (total == 0) {
        func_0046d730(D_005F12C8, 0x69);
    }
    draw = (s32)(RpRandom() % (u32)total);
    tables = iGpffffb418;
    table = tables + tableOffset;
    normalRate = *(u8 *)(table + alternate);
    if (draw < normalRate) {
        kind = 1;
        first = 0;
        last = 20;
    } else if (draw < normalRate + (s32)multiplier *
        *(u8 *)((u8 *)encSlot(alternate, encSlot((u32)tableId * 0xF8, (u32)tables)) + 2)) {
        kind = 2;
        first = 20;
        last = 25;
    } else {
        kind = 4;
        first = 25;
        last = 30;
    }
    sum = 0;
    index = first;
    alternateOffset = alternate * 0x78;
    entries = table + alternateOffset;
    for (; index < last; index++) {
        u8 *entry = entries + index * 4;
        if (*(u16 *)(entry + 8) != 0) {
            sum += *(u16 *)(entry + 10);
        }
    }
    if (sum == 0) {
        return -1;
    }
    draw = (s32)(RpRandom() % (u32)sum);
    cumulative = 0;
    tables = iGpffffb418;
    entries = tables + tableOffset + alternateOffset;
    for (; first < last; first++) {
        s32 offset = first * 4;
        cumulative += *(u16 *)(entries + offset + 10);
        if (draw < cumulative) {
            selected = *(u16 *)((u8 *)encSlot(offset,
                encSlot(alternateOffset, encSlot(tableOffset, (u32)tables))) + 8);
            break;
        }
    }
    return (kind << 16) | selected;
}

#pragma pop
/* 10-byte entry of the iGpffffb41c encounter table; `table` selects the
   0x15C-byte record block in iGpffffb424. */
typedef struct EncEntry {
    u16 id;
    u8 rate2;
    u8 rate3;
    u8 rate4;
    u8 pad5;
    u16 table;
    u16 pad8;
} EncEntry;

// FUN_00161C80
/* Pick a weighted record (0x1D records of 0xC bytes) from the block of the
   given encounter. A record is skipped when its id is in the D_005F1260 list
   with a nonzero func_00106600 count, or when func_00161bb0 or the D_007E80A0
   slot scan finds it already present; bit 0 of byte 7 selects which modes
   count it. The first pass sums the weights, the second draws against it. */
/* measured: opt_loop_invariants on hoists the D_005F1260/D_007E80A0 bases and
   the constants ahead of both loops, as retail does. */
#pragma push
#pragma opt_loop_invariants on
u8 *func_00161c80(s32 field, s32 room, u16 index, u16 mode)
{
    u8 *base;
    u8 *found;
    s32 i;
    s32 total;
    s32 acc;
    s32 rnd;

    found = NULL;
    if ((func_0014a230(field, room) == 1) || (func_0014a2a0(field, room) == 1)) {
        EncEntry *entry = (EncEntry *)iGpffffb41c;
        base = iGpffffb424 + entry[index].table * 0x15C;
    } else {
        return NULL;
    }
    if (index == 0) {
        return NULL;
    }
    i = 0;
    total = 0;
    for (; i < 0x1D; i++) {
        u8 *rec = base + i * 0xC;
        s16 *pid = (s16 *)(rec + 2);
        if (*(u16 *)(rec + 2) != 0) {
            s16 id = *(u16 *)(rec + 2);
            s32 hit = 0;
            s32 j;
            for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                if (id == ((s16 *)D_005F1260)[j] && (func_00106600(id) & 0xFF) > 0) {
                    hit = 1;
                    break;
                }
            }
            if (hit == 0 && func_00161bb0(*pid) == 0) {
                s16 fieldId = *pid;
                s32 present = 0;
                s32 k;
                for (k = 0; k < 8; k++) {
                    u8 *p = D_007E80A0 + k * 0x168;
                    if (*(s32 *)(p + 0) != 0) {
                        u8 *q = *(u8 **)(p + 0x160);
                        if (q != NULL && *(s32 *)(p + 8) != 1 && fieldId == *(u16 *)(q + 2)) {
                            present = 1;
                            break;
                        }
                    }
                }
                if (present == 0) {
                    if (*(u8 *)(rec + 7) & 1) {
                        if (mode == 1 || mode == 2) {
                            total += *(u16 *)(rec + 0);
                        }
                    } else if (mode == 0 || mode == 2) {
                        total += *(u16 *)(rec + 0);
                    }
                }
            }
        }
    }
    if (total == 0) {
        func_0046d730(D_005F12C8, 0x166);
    }
    rnd = RpRandom() % total;
    /* measured: the draw loop's locals live in their own block, id first and
       the counter last; that ranks the counter in $s0 and the id in $s4 as
       retail does (other orders leave the two swapped). */
    {
        s16 id;
        s16 *pid;
        s32 j;
        u8 *rec;
        s32 hit;
        s32 n;

        n = 0;
        acc = 0;
        for (; n < 0x1D; n++) {
            rec = base + n * 0xC;
            pid = (s16 *)(rec + 2);
            if (*(u16 *)(rec + 2) != 0) {
                id = *(u16 *)(rec + 2);
                hit = 0;
                for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                    if (id == ((s16 *)D_005F1260)[j] && (func_00106600(id) & 0xFF) > 0) {
                        hit = 1;
                        break;
                    }
                }
                if (hit == 0 && func_00161bb0(*pid) == 0) {
                    s16 fieldId = *pid;
                    s32 present = 0;
                    s32 k;
                    for (k = 0; k < 8; k++) {
                        u8 *p = D_007E80A0 + k * 0x168;
                        if (*(s32 *)(p + 0) != 0) {
                            u8 *q = *(u8 **)(p + 0x160);
                            if (q != NULL && *(s32 *)(p + 8) != 1 && fieldId == *(u16 *)(q + 2)) {
                                present = 1;
                                break;
                            }
                        }
                    }
                    if (present == 0) {
                        if (*(u8 *)(rec + 7) & 1) {
                            if (mode == 1 || mode == 2) {
                                acc += *(u16 *)(rec + 0);
                            }
                        } else if (mode == 0 || mode == 2) {
                            acc += *(u16 *)(rec + 0);
                        }
                        if (rnd < acc) {
                            found = rec;
                            break;
                        }
                    }
                }
            }
        }
    }
    return found;
}
#pragma pop
