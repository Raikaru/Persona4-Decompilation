#include "byte_address_internal.h"
#include "include_asm.h"
#include "type.h"

/* Unit settings: propagation disabled and loop-invariant motion enabled. */
#pragma opt_propagation off
/* measured: retail compiles this unit with propagation off and loop-invariant motion on. */
#pragma opt_loop_invariants on

/* Encounter-selection helpers. iGpffffb41c points to 10-byte encounter entries, iGpffffb418 to the
 * 0xF8-stride sub-table, iGpffffb424 to the 0x15C-stride record table. */

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

/* measured: the remaining byteAddressAdd calls keep retail's offset-first add operand order. */

/* Return encounter-entry flags only when the field and room belong to a supported encounter band.
 * Matching needs both opt_propagation off and byteAddressAdd, as in FUN_00161B10. */
// FUN_00161A70
/* The separate base local makes the single-use gp table load happen before the index arithmetic. */
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
/* measured: like FUN_00161A70, retail loads the gp table base before the index math and adds the
 * offset first. */
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

/* measured: retail hoists the encounter table bases and the -1 constant out of both loops; the id
 * == *(u16 *)(q + 2) order keeps retail's compare order. Searches live encounter slots for an
 * identifier. */
/* Return 1 if the identifier appears in the tracked identifier table and is held by an enabled,
 * non-finished encounter slot. */
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
/* Pick an encounter for the field and room from the weighted tables, first rolling for normal,
 * special or rare, then rolling a weighted entry. Return -1 if the room is outside the encounter
 * bands or no entry has weight. */
// FUN_00161630
/* Choose a category, then draw an encounter from its weighted entries; categories occupy entries
 * [0,20), [20,25), and [25,30). Returns the encounter ID in the low halfword and category bits
 * above it. */
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

/* Pick a random encounter record from the room's encounter table, weighted by each record's weight.
 * Records are skipped if their item is already held, if the encounter is active or already in an
 * active slot, or if the record doesn't fit the requested mode. */
// FUN_00161C80
/* Pick a weighted record (0x1D records of 0xC bytes), skipping held items, active encounters, and
 * records whose byte-7 bit 0 excludes the mode; sum weights, then draw. */
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
    /* measured: retail allocates the draw loop's locals in their own block, declared id first and
     * counter last. */
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
