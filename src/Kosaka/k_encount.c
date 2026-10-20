#include "byte_address_internal.h"
#include "include_asm.h"
#include "type.h"

/* Unit settings: propagation disabled and loop-invariant motion enabled. */
#pragma opt_propagation off
/* measured: these unit settings retain all six owner MATCHes. */
#pragma opt_loop_invariants on

/* Encounter-selection helpers (Kosaka unit).
 *
 * gp-relative globals (GP base 0x007690F0, see config/symbol_data_addrs.txt):
 *   iGpffffb41c (gp-0x4BE4 = 0x0076450C) -- pointer to the 10-byte encounter
 *       table entries (u16 id at +0, u8 flags/rates at +2/+3/+4, u16 at +6)
 *   iGpffffb418 (gp-0x4BE8 = 0x00764508) -- pointer to the 0xF8-stride
 *       per-encounter sub-table (two 0x78 halves, selected by the bool flag)
 *   iGpffffb424 (gp-0x4BDC = 0x00764514) -- pointer to the 0x15C-stride
 *       encounter-record table used by Encount_FindRecord
 */

extern s32 FldMap_IsInBandA(s32 fieldId, s32 roomId);
extern s32 FldMap_IsInBandB(s32 fieldId, s32 roomId);
extern s32 FldStepBandValue();
extern s32 datItemCount(s16 itemId);
extern s16 datGetDateIndex(void);
extern u8 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 day, u32 phase);
extern u32 datGetFlag(s32 bit);
extern u32 RpRandom(void);
extern void kAssertFail(void *file, s32 line);
extern u8 *iGpffffb41c;
extern u8 *iGpffffb418;
extern u8 *iGpffffb424;
extern u8 D_005F1260[];
extern u8 D_005F12C8[];
extern u8 D_007E80A0[];

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

/* The record block is 29 twelve-byte weighted records. */
typedef struct EncRecord {
    u16 weight, id;
    u8 pad04[3];
    u8 flags;
    u8 pad08[4];
} EncRecord;
typedef struct EncActiveSlot {
    s32 enabled;
    u8 pad04[4];
    s32 state;
    u8 pad0C[0x154];
    EncRecord *record;
    u8 pad164[4];
} EncActiveSlot;
typedef struct EncWeightedEntry { u16 id, weight; } EncWeightedEntry;
typedef struct EncWeightedTable {
    u8 normalRates[2], specialRates[2], rareRates[2], pad06[2];
    EncWeightedEntry entries[2][30];
} EncWeightedTable;

/* measured: the retained byteAddressAdd calls keep retail's offset-first
 * addu operands; the other eight former helper calls use plain sums. */

/* This "load-sinking + addu-flip floor" needed BOTH levers at once, which is why
   the four spellings listed before (plain expr, base local, m2c chain+base,
   fully split statements) all stalled at nd 8: `#pragma opt_propagation off`
   brings the single-use gp base load ahead of the index chain, and `byteAddressAdd`
   helper holds the offset-first addu. Either alone leaves the other wrong.
   The same pair matches the identically shaped FUN_00161B10 below. */
/* Return encounter-entry flags only when the field and room belong to a supported encounter band. */
// FUN_00161A70
/* measured: forces the single-use gp base load ahead of the index chain. */
/* measured: baseline removal differs in 16 bytes; typed encounter table indexing; name encounter table entry before load also differ. */
s32 Encount_GetEntryFlags(s32 field, s32 room, s32 entryIndex) {
    s32 result;
    u8 *base;

    result = 0;
    if ((FldMap_IsInBandA(field, room) == 1) || (FldMap_IsInBandB(field, room) == 1)) {
        base = iGpffffb41c;
        result = ((EncEntry *)((u32)byteAddressAdd((entryIndex & 0xFFFF) * 10, (u8 *)((u32)base))))->rate2;
    }
    return result;
}

/* Return the entry's rate4 value for supported field and room encounter bands. */
// FUN_00161B10
/* measured: same recipe as FUN_00161A70 -- the pragma forces the single-use gp
   base load ahead of the index chain. */
/* measured: baseline removal differs in 16 bytes; typed encounter table indexing; name encounter table entry before load also differ. */
s32 Encount_GetEntryRate(s32 field, s32 room, s32 entryIndex) {
    s32 result;
    u8 *base;

    result = 0;
    if ((FldMap_IsInBandA(field, room) == 1) || (FldMap_IsInBandB(field, room) == 1)) {
        base = iGpffffb41c;
        result = ((EncEntry *)((u32)byteAddressAdd((entryIndex & 0xFFFF) * 10, (u8 *)((u32)base))))->rate4;
    }
    return result;
}

/* Return the entry's rate3 value unless FldStepBandValue supplies a byte override. */
// FUN_001619B0
/* measured: same pair of levers as FUN_00161A70 -- the pragma brings the gp base
   load ahead of the index chain, the helper holds the offset-first addu. */
/* measured: baseline removal differs in 16 bytes; typed encounter table indexing; name encounter table entry before load also differ. */
s32 Encount_GetEntryRateOrOverride(s32 field, s32 room, s32 entryIndex) {
    s32 result;
    s32 idx;
    s32 v;
    u8 *base;

    result = 0;
    if ((FldMap_IsInBandA(field, room) == 1) || (FldMap_IsInBandB(field, room) == 1)) {
        base = iGpffffb41c;
        idx = entryIndex & 0xFFFF;
        result = ((EncEntry *)((u32)byteAddressAdd(idx * 10, (u8 *)((u32)base))))->rate3;
        v = FldStepBandValue(idx) & 0xFF;
        if (v < 0xFF) {
            result = v;
        }
    }
    return result;
}

/* The encounter tables and the constants 1/-1 are loop invariants that retail
   hoists ahead of both loops. */
/* measured: opt_loop_invariants on does that hoisting (and sign-extends the
   s16 id once into $t2); without it the bases are rematerialised per iteration
   (nd 45). `id == *(u16 *)(q + 2)` keeps retail's bne operand order. */
/* measured: baseline removal differs in 137 bytes; typed active-slot array indexing; cache identifier table base outside loop also differ. */
/* Search live encounter slots for an identifier in the tracked identifier table. */
// FUN_00161BB0
s32 Encount_IsEncounterActive(s16 id) {
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
                if (((EncActiveSlot *)p)->enabled != 0) {
                    q = (u8 *)((EncActiveSlot *)p)->record;
                    if (q != NULL && ((EncActiveSlot *)p)->state != 1 && id == ((EncRecord *)q)->id) {
                        result = 1;
                        break;
                    }
                }
            }
        }
    }
    return result;
}
/* Typed table aliases retain the two normal-rate load address orders under b210. */
// FUN_00161630
/* Choose a category, then draw an encounter from its weighted entries.
 * The three categories occupy entries [0,20), [20,25), and [25,30).
 * Return the encounter ID in the low halfword and the category bits above it.
 * Measured b210 -O2: 888/896 bytes, 19 resolved relocations, eight zero bytes.
 * Retained propagation preserves address lifetimes; the unsigned table-index
 * expression keeps the threshold lookup distinct from the cached signed offset. */
s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level)
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
    EncWeightedTable *weighted;

    selected = 0xFFFF;
    multiplier = 1.0f;
    if (FldMap_IsInBandA(field, room) == 1 || FldMap_IsInBandB(field, room) == 1) {
        tableId = ((EncEntry *)iGpffffb41c)[(u16)encounter].id;
    } else {
        return -1;
    }
    day = (s16)datGetDateIndex();
    alternate = (s8)calGetDayEntryByPhase(day, datGetTimeSlot() & 0xFF) == 1;
    if (datGetFlag(0x1411) == 1) {
        multiplier = 100.0f;
    }
    field = (u16)field;
    if ((field == 0x28 || field == 0x3C) && datGetFlag(0xC0F) == 0) {
        multiplier = 0.0f;
    }
    tableOffset = tableId * 0xF8;
    weighted = (EncWeightedTable *)(iGpffffb418 + tableOffset);
    total = weighted->normalRates[alternate];
    if (datGetFlag(0x1410) == 0) {
        s32 available = (s32)(u16)level;
        if (available > 0) {
            total += (s32)multiplier *
                ((EncWeightedTable *)((u8 *)((alternate) + (((tableOffset) + ((u32)iGpffffb418))))))->specialRates[0];
        }
        if (available >= 2) {
            total += ((EncWeightedTable *)((u8 *)((alternate) + (((tableOffset) + ((u32)iGpffffb418))))))->rareRates[0];
        }
    }
    if (total == 0) {
        kAssertFail(D_005F12C8, 0x69);
    }
    draw = (s32)(RpRandom() % (u32)total);
    tables = iGpffffb418;
    table = tables + tableOffset;
    weighted = (EncWeightedTable *)table;
    normalRate = weighted->normalRates[alternate];
    if (draw < normalRate) {
        kind = 1;
        first = 0;
        last = 20;
    } else if (draw < normalRate + (s32)multiplier *
        ((EncWeightedTable *)((u8 *)((alternate) + (((u32)byteAddressAdd((u32)tableId * 0xF8, (u8 *)((u32)tables)))))))->specialRates[0]) {
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
        if (((EncWeightedTable *)entry)->entries[0][0].id != 0) {
            sum += ((EncWeightedTable *)entry)->entries[0][0].weight;
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
        cumulative += ((EncWeightedTable *)(entries + offset))->entries[0][0].weight;
        if (draw < cumulative) {
            selected = ((EncWeightedTable *)((u8 *)((offset) + (((alternateOffset) + (((tableOffset) + ((u32)tables)))))
)))->entries[0][0].id;
            break;
        }
    }
    return (kind << 16) | selected;
}

// FUN_00161C80
/* Pick a weighted record (0x1D records of 0xC bytes) from the block of the
   given encounter. A record is skipped when its id is in the D_005F1260 list
   with a nonzero datItemCount count, or when Encount_IsEncounterActive or the D_007E80A0
   slot scan finds it already present; bit 0 of byte 7 selects which modes
   count it. The first pass sums the weights, the second draws against it. */
/* measured: opt_loop_invariants on hoists the D_005F1260/D_007E80A0 bases and
   the constants ahead of both loops, as retail does. */
/* measured: baseline removal differs in 749 bytes; typed record array indexing; cache active-slot and identifier table bases also differ. */
u8 *Encount_FindRecord(s32 field, s32 room, u16 index, u16 mode)
{
    u8 *base;
    u8 *found;
    s32 i;
    s32 total;
    s32 acc;
    s32 rnd;

    found = NULL;
    if ((FldMap_IsInBandA(field, room) == 1) || (FldMap_IsInBandB(field, room) == 1)) {
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
        if (((EncRecord *)rec)->id != 0) {
            s16 id = ((EncRecord *)rec)->id;
            s32 hit = 0;
            s32 j;
            for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                if (id == ((s16 *)D_005F1260)[j] && (datItemCount(id) & 0xFF) > 0) {
                    hit = 1;
                    break;
                }
            }
            if (hit == 0 && Encount_IsEncounterActive(*pid) == 0) {
                s16 fieldId = *pid;
                s32 present = 0;
                s32 k;
                for (k = 0; k < 8; k++) {
                    u8 *p = D_007E80A0 + k * 0x168;
                    if (((EncActiveSlot *)p)->enabled != 0) {
                        u8 *q = (u8 *)((EncActiveSlot *)p)->record;
                        if (q != NULL && ((EncActiveSlot *)p)->state != 1 && fieldId == ((EncRecord *)q)->id) {
                            present = 1;
                            break;
                        }
                    }
                }
                if (present == 0) {
                    if (((EncRecord *)rec)->flags & 1) {
                        if (mode == 1 || mode == 2) {
                            total += ((EncRecord *)rec)->weight;
                        }
                    } else if (mode == 0 || mode == 2) {
                        total += ((EncRecord *)rec)->weight;
                    }
                }
            }
        }
    }
    if (total == 0) {
        kAssertFail(D_005F12C8, 0x166);
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
            if (((EncRecord *)rec)->id != 0) {
                id = ((EncRecord *)rec)->id;
                hit = 0;
                for (j = 0; ((s16 *)D_005F1260)[j] != -1; j++) {
                    if (id == ((s16 *)D_005F1260)[j] && (datItemCount(id) & 0xFF) > 0) {
                        hit = 1;
                        break;
                    }
                }
                if (hit == 0 && Encount_IsEncounterActive(*pid) == 0) {
                    s16 fieldId = *pid;
                    s32 present = 0;
                    s32 k;
                    for (k = 0; k < 8; k++) {
                        u8 *p = D_007E80A0 + k * 0x168;
                        if (((EncActiveSlot *)p)->enabled != 0) {
                            u8 *q = (u8 *)((EncActiveSlot *)p)->record;
                            if (q != NULL && ((EncActiveSlot *)p)->state != 1 && fieldId == ((EncRecord *)q)->id) {
                                present = 1;
                                break;
                            }
                        }
                    }
                    if (present == 0) {
                        if (((EncRecord *)rec)->flags & 1) {
                            if (mode == 1 || mode == 2) {
                                acc += ((EncRecord *)rec)->weight;
                            }
                        } else if (mode == 0 || mode == 2) {
                            acc += ((EncRecord *)rec)->weight;
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
