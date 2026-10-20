/* Original translation unit cmmMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "cmm_internal.h"
#include "datPersona_internal.h"


/* cmm.bin chunks have an eight-byte header and fixed-stride records. */
typedef struct CmmChunkHeader { u32 unk00; u32 count; } CmmChunkHeader;
/* The candidate table has fourteen-byte rows: flags at 0 and level at 3. */
typedef struct CmmPersonaCandidateRecord { u16 flags; u8 unk02, level; u8 pad04[10]; } CmmPersonaCandidateRecord;
typedef struct CmmConditionRecord {
    u16 communityId; u16 unk02; u16 kind;
    union { u16 weekday; struct { u8 month, day; } date; } value;
} CmmConditionRecord;
typedef struct CmmEligibleRecord {
    u8 month, day; u16 communityId; u16 minRank, maxRank;
} CmmEligibleRecord;
typedef struct CmmReversePair { u16 communityId, otherId; s32 increment; } CmmReversePair;
typedef struct CmmMessageEntry {
    u16 communityId; u8 kind, rank; u8 pad04[8]; u32 flagBit;
} CmmMessageEntry;
typedef struct CmmLookupValue { s32 key; u16 kind; u8 pad06[2]; s32 value; } CmmLookupValue;
typedef struct CmmFlaggedValue { s32 flagBit, key; u16 kind, value; } CmmFlaggedValue;
typedef struct CmmDateRange { s16 threshold[2]; u8 pad04[4]; } CmmDateRange;
typedef struct CmmDateColumn { u16 itemFirst; s16 deltaFirst; u16 itemSecond; s16 deltaSecond; s32 value; u8 pad0C[4]; } CmmDateColumn;
typedef struct CmmDateRecord { u8 month, day, specialMonth, specialDay; CmmDateColumn columns[2]; } CmmDateRecord;
typedef struct CmmFishingRecord { s16 base, span; u8 pad04[2]; s16 effect; u8 pad08[6]; } CmmFishingRecord;

extern u32 RpRandom(void);


extern void func_00440b68(const char *fmt, const char *file, s32 line);
extern void *H_Cdvd_AcquireDirectory(const char *path, s32 flags);
extern void H_Cdvd_ReadSync(void *cdvd);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern void kAssertFail(void *file, s32 line);
extern void kAssertFailMsg(const char *file, s32 line, char *fmt, s32 value);
extern s32 datGetDateIndex(void);
extern u32 datGetFlag(s32 bit);
extern void datSetFlag(s32 flagId, s32 enabled);
extern u32 datGetScriptValue(s32 index);
extern s32 datSetScriptValue(s32 index, s32 value);
extern s32 datItemCount(s16 itemId);
extern s32 cmmCommunityTestMarked(s32 communityId);
extern s32 cmmCommunityTestReversed(s32 communityId);
extern void cmmCommunitySetReversed(s32 communityId);
extern s32 cmmCommunityTestBroken(s32 communityId);
extern s32 cmmCommunityCanRankUp(s32 communityId);
extern s32 cmmCommunityFindRecord(s32 value);
extern s32 calGetWeekdayOfDay(s32 dateIndex);
extern s32 calIsCurrentMonthDay(s32 unused, s32 month, s32 day);
extern s32 calIsDayInRange(s32 dateIndex, s32 startMonth, s32 startDay, s32 endMonth, s32 endDay);
extern s32 cmmCommunityCounterpart(s64 communityId); /* lint: allow H011 -- measured: s64 parameter keeps the retail key move; see cmmCommunityCounterpart note at the call site */
extern s32 cmmCommunityRecordValue(s32 communityId);
extern s32 cmmCommunityTestRecordFlags(s32 communityId, s32 mask);
extern u16 cmmCommunityGetTableHead(void);
extern s64 cmmCommunityArcana(s32 communityId);
extern s32 cmmCommunityHasRecord(u16 communityId);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
extern s32 calDayOfYearFromMonthDay(s32 month, s32 day);
extern s32 calHasDayEntry(s32 day);
extern s32 cmmDateTableFindIndex();
extern u16 cmmCommunityCategory(s32 communityId);
extern s32 cmmReversedAtRank(s32 communityId);
extern void datEntryDrawGatedByFlag39(s32 port, s32 sequence, s32 duration, s32 flags);
extern void chkmemAllocSiteTag(void *, s32);

extern char D_006359D0[];
extern char D_006359E0[];
extern char D_007636F0;
extern char D_007636F8;
extern u8 *D_00881480[];
extern u8 *D_00881484[];
extern u8 *D_0088148C[];
extern s32 D_0088149C[];
extern s32 D_008814A0[];
extern s32 D_008814A4[];
extern s32 D_008814A8[];
extern s32 D_008814AC[];
extern u8 *D_008814B0[];
extern u8 *D_008814B4[];
extern s32 D_008814B8[];
extern u8 *D_008814BC[];
extern u8 *D_008814C4[];
extern u8 *D_008814D4[];
extern u8 *D_008814D8[];
extern u8 *D_008814DC[];
extern u8 *D_008814E0[];
extern u8 *D_008814E4[];
extern s32 D_008814E8[];
extern s32 D_008814EC[];
extern u8 *D_00881490[];
extern u8 *D_00881494[];
extern u8 *D_00881498[];
extern u8 *D_008814C0[];
extern u8 *D_008814C8[];
extern s32 D_008814CC[];
extern u8 *D_008814D0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);

/* gp - 0x4C2C = 0x007644C4: runtime-loaded 14-byte record table. */
static u8 *iGpffffb3d4;

static inline s32 cmmMiscAddOff(s32 offset, s32 base) {
    return offset + base;
}

static inline s32 cmmMiscOr(s32 left, s32 right) {
    return left | right;
}


// Loads the cmm.bin event file (retail path string at D_006359E0) and fills D_00881480[0..0x1B] with its 28 chunks. Called once from the kwln table init.
// FUN_00246700
void cmmLoadTables(void) {
    s32 entrySize;
    s32 i;
    void *handle;

    func_00440b68(&D_007636F0, D_006359D0, 0x3F);
    H_Cdvd_ReadSync(handle = H_Cdvd_AcquireDirectory(D_006359E0, 1));
    for (i = 0; i < 0x1C; i++) {
        D_00881480[i] = H_Cdvd_GetArchiveEntry(handle, i, &entrySize);
    }
}

// Kind record: returns the 100-byte kind record for index value (table D_00881480), asserting the index is in range. Callers test its +4 flags and read its +8 sprite width base.
// FUN_002467B0
u8 *cmmKindRecord(s32 kindId) {
    u8 *table = D_00881480[0];
    s32 off;

    if ((u32)(kindId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)kindId * 100;
    return (u8 *)(off + (u32)table + 8);
}

// Name record: returns the 64-byte name record for id value (table D_00881484), asserting the id is in range. Callers read it as a display string or record.
// FUN_00246830
u8 *cmmNameRecord(u32 nameId) {
    u32 index;
    u8 *table;

    table = D_00881484[0];
    index = nameId & 0xFFFF;
    if (index >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x54);
    }
    return (u8 *)((index << 6) + (u32)table + 8);
}

// Text record: returns the 64-byte text record for id value (table D_008814DC), asserting the id is in range. Callers read it as a display string.
// FUN_002468A0
u8 *cmmTextRecord(u32 textId) {
    u32 index;
    u8 *table;

    table = D_008814DC[0];
    index = textId & 0xFFFF;
    if (index >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x5C);
    }
    return (u8 *)((index << 6) + (u32)table + 8);
}

/* MATCHED (wave 14): `#pragma opt_propagation off` (measured: nd 9 -> 2,
   forces the single-use D_0088149C load into $a1 before the mul chain) + a
   hoisted `s32 base` local + the cmmMiscAddOff inline helper (measured:
   nd 2 -> 1, fixes the `addu $v0,$v0,$a1` mul-first operand order). Retail
   loads the global into $a1 FIRST, then the x24 chain, then `addu $v0,$v0,$a1`. */
// Rank name record: 24-byte record from chunk 7 (D_0088149C) for rank index value.
// FUN_00246910
#pragma opt_propagation off
u8 *cmmRankNameRecord(s16 value) {
    s32 base = D_0088149C[0];
    s32 mul = (s16)value * 24;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// Detail record: 20-byte record from chunk 8 (D_008814A0) for detail index value.
// FUN_00246940
/* MATCHED (wave 14): same recipe as cmmRankNameRecord — `#pragma opt_propagation
   off` (measured: nd 9 -> 1, forces the single-use D_008814A0 load into $a1
   before the x20 chain) + hoisted `s32 base` local + cmmMiscAddOff helper
   (fixes the `addu $v0,$v0,$a1` operand order). Final residual is a benign
   reloc-masked word. */
#pragma opt_propagation off
u8 *cmmDetailRecord(s16 value) {
    s32 base = D_008814A0[0];
    s32 mul = (s16)value * 20;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// Aux table: returns the chunk 9 table header (D_008814A4) with no record stride. Callers pass it as the message to nmMesWindowInstallHandle.
// FUN_00246970
s32 cmmAuxTable(void) {
    return D_008814A4[0];
}

// Rank string: returns the address of the string for kind value and level option in chunk 10 (D_008814A8), with 65-byte kind and 13-byte level strides.
// FUN_00246980
s32 cmmRankStringAt(s16 value, s16 option) {
    s32 base = D_008814A8[0] + 8;

    if (value >= 5) {
        kAssertFail(D_006359D0, 0xBC);
    }
    if ((option <= 0) || (option > 5)) {
        kAssertFailMsg(D_006359D0, 0xBD, &D_007636F8, option);
    }
    return base + value * 0x41 + (option - 1) * 0xD;
}

/* MATCHED (wave 14): lever-3 static inline helper `cmmMiscAddOff(offset, base)`
   carrying the addu operand order through its parameters fixed the two
   transposed `addu` residuals (nd 4 -> 0). The `index` local + first helper
   call fixed the first addu; the second call `cmmMiscAddOff(option*2, mid)`
   fixed the second. Original residual was `addu $v0,$v1,$v0` vs retail
   `addu $v0,$v0,$v1` (fresh sll result in rs). */
// Rank threshold: returns the s16 threshold from chunk 11 (D_008814AC) for category value at level option. g_data.c uses it for rank thresholds.
// FUN_00246A50
s32 cmmRankThreshold(s16 value, s16 option) {
    s32 base = D_008814AC[0] + 8;
    s32 index;
    s32 mid;

    if (value >= 5) {
        kAssertFail(D_006359D0, 0xC8);
    }
    if ((option <= 0) || (option > 5)) {
        kAssertFailMsg(D_006359D0, 0xC9, &D_007636F8, option);
    }
    index = value * 8;
    mid = cmmMiscAddOff(index, base);
    /* Serialized halfwords retain the measured two-stage address-add order described above. */
    return *(s16 *)(cmmMiscAddOff(option * 2, mid) - 2);
}
// Label record: 64-byte label record from chunk 12 (D_008814B0) for id value. cmmPersonaDetailShow copies it as a display string.
// FUN_00246B10
u8 *cmmLabelRecord(u32 labelId) {
    u32 index;
    u8 *table;

    table = D_008814B0[0];
    index = labelId & 0xFFFF;
    if (index >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0xD1);
    }
    return (u8 *)((index << 6) + (u32)table + 8);
}

// Earn-scale table: returns the chunk 14 header (D_008814B8) at its record area. cmmCommunity earn scaling reads its f32 multipliers and counts from it.
// FUN_00246B80
CmmEarnScale *cmmEarnScaleTable(void) {
    return (CmmEarnScale *)(D_008814B8[0] + 8);
}

// Entry value record: 24-byte record from chunk 15 (D_008814BC) for entry value. cmmCommunityEntryValue reads its value from this record.
// FUN_00246BA0
u8 *cmmEntryValueRecord(s32 entryId) {
    u8 *table = D_008814BC[0];
    s32 off;

    if ((u32)(entryId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0xEE);
    }
    off = (u16)entryId * 24;
    return (u8 *)(off + (u32)table + 8);
}

// Slot name record: 64-byte name record from chunk 17 (D_008814C4) for community slot value. Read by the group-slot text in code1_0027.c.
// FUN_00246C20
u8 *cmmSlotNameRecord(u32 slotId) {
    u32 index;
    u8 *table;

    table = D_008814C4[0];
    index = slotId & 0xFFFF;
    if (index >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x104);
    }
    return (u8 *)((index << 6) + (u32)table + 8);
}

// Item description text record: 64-byte text record from chunk 21 (D_008814D4), or NULL when id value is out of range. Read through the item record's text slots 0x12/0x22.
// FUN_00246C90
u8 *cmmItemDescRecordOrNull(u32 value) {
    if (value >= ((CmmChunkHeader *)D_008814D4[0])->count) {
        return NULL;
    }
    return (u8 *)((value << 6) + (u32)D_008814D4[0] + 8);
}

// Item info record: 72-byte item record from chunk 24 (D_008814E0) for id value. cmmItemInfoShow reads its name, value, and text fields.
// FUN_00246CD0
u8 *cmmItemInfoRecord(s32 itemId) {
    u8 *table = D_008814E0[0];
    s32 off;

    if ((u32)(itemId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x13B);
    }
    off = (u16)itemId * 72;
    return (u8 *)(off + (u32)table + 8);
}

// Item extra text record: 64-byte text record from chunk 22 (D_008814D8), or NULL when id value is out of range. Read through the item record's text slots 0x10/0x20.
// FUN_00246D50
u8 *cmmItemExtraRecordOrNull(u32 value) {
    if (value >= ((CmmChunkHeader *)D_008814D8[0])->count) {
        return NULL;
    }
    return (u8 *)((value << 6) + (u32)D_008814D8[0] + 8);
}

// Persona record: 66-byte record from chunk 25 (D_008814E4) for id value. The persona row sits at +0x40.
// FUN_00246D90
u8 *cmmPersonaRecord(s32 personaId) {
    u8 *table = D_008814E4[0];
    s32 off;

    if ((u32)(personaId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x15B);
    }
    off = (u16)personaId * 66;
    return (u8 *)(off + (u32)table + 8);
}

// Month profile: 72-byte month profile from chunk 26 (D_008814E8) for index value, offset by -0x40 (see CmmMonthProfile in cmmScript.c).
// FUN_00246E10
s32 cmmMonthProfileRecord(s32 monthId) {
    s32 table;
    s32 month;
    s32 off;

    table = D_008814E8[0];
    month = monthId & 0xFFFF;
    if ((month <= 0) || (month > 0xC)) {
        kAssertFail(D_006359D0, 0x163);
    }
    off = (u16)monthId * 72;
    return off + (u32)table - 0x40;
}

// Fishing entry: 14-byte fishing record from chunk 27 (D_008814EC) for index value, asserting the index is at most 5.
// FUN_00246E90
u8 *cmmFishingEntryRecord(s32 entryId) {
    u8 *table = (u8 *)D_008814EC[0];
    s32 off;

    if (((s32)(entryId & 0xFFFF) < 0) || ((entryId & 0xFFFF) > 5)) {
        kAssertFail(D_006359D0, 0x16B);
    }
    off = (u16)entryId * 14;
    return (u8 *)(off + (u32)table + 8);
}
// Condition check: scans the 8-byte condition table (chunk 13, D_008814B4) and returns 1 when an entry for id value is met. Kind 0 tests calIsCurrentMonthDay, kind 1 tests calGetWeekdayOfDay.
// FUN_00246F10
s32 cmmConditionMet(s32 requestedId) {
    u16 communityId;
    u16 conditionKind;
    u8 *entry = D_008814B4[0] + 8;
    s32 count = (s32)((CmmChunkHeader *)D_008814B4[0])->count;
    s32 index = 0;
    s32 targetId = requestedId & 0xFFFF;

    while (index < count) {
        communityId = ((CmmConditionRecord *)entry)->communityId;
        if (communityId == 0 || communityId == targetId) {
            conditionKind = ((CmmConditionRecord *)entry)->kind;
            switch (conditionKind) {
            case 0:
                if (calIsCurrentMonthDay((s16)datGetDateIndex(), ((CmmConditionRecord *)entry)->value.date.month, ((CmmConditionRecord *)entry)->value.date.day) != 0) {
                    return 1;
                }
                break;
            case 1:
                if (((CmmConditionRecord *)entry)->value.weekday == calGetWeekdayOfDay((s16)datGetDateIndex())) {
                    return 1;
                }
                break;
            }
        }
        entry += 8;
        index++;
    }
    return 0;
}
// Has pending unlock: returns 1 when unlock flag 0x11 is still unset and the event check calIsDayInRange passes for the current community; else 0.
// FUN_00247020
s32 cmmHasPendingUnlock(void) {
    if ((datGetFlag(0x11) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 4, 0x12, 4, 0x1D) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x12) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 5, 0x12, 6, 4) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x13) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 6, 0x18, 7, 9) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x14) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 7, 0x1B, 8, 0xC) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x15) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 9, 0x10, 0xA, 5) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x16) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 0xB, 6, 0xB, 0x14) != 0)) {
        return 1;
    }
    if ((datGetFlag(0x17) == 0) && (calIsDayInRange((s16)datGetDateIndex(), 0xC, 8, 0xC, 0x18) != 0)) {
        return 1;
    }
    return 0;
}
/* Family map (measured): the six related masked-counter/table walkers are
   FUN_00247270 (0x280/640), FUN_002474F0 (0x280/640), FUN_00247DD0
   (0xF0/240), FUN_00248240 (0x180/384), FUN_00248A60 (0x120/288), and
   FUN_00248B80 (0x180/384). Related FUN_002483C0 is 0x220/544. The
   00247270 C body had exact CFG and measured nd 67 at object 636/640;
   residuals were mask-CSE at the nested call/tail. The opt_common_subs-off
   probe measured nd 207 at object 648/640 from duplicated pointer loads, so
   no pragma or body was retained. */
// Find fresh reverse candidate: like cmmFindReverseCandidate, but the candidate must fail cmmCommunityHasTierBit(id, 1..9) for the scan tier. Returns the first match, or 0.
// FUN_00247270
/* measured: opt_common_subs off restores retail per-use masks while preserving the shared base pointer. */
#pragma opt_common_subs off
s32 cmmFindFreshReverseCandidate(void) {
    s32 kindOffset;
    u32 *table;
    u32 *flagsTable;
    s32 communityId;
    s32 enabled;
    s32 blocked;
    s32 kindId;

    for (communityId = 1; communityId < 0x1F; communityId++) {
        if (cmmCommunityCanRankUp(communityId & 0xFFFF) != 0) {
            kindId = communityId & 0xFFFF;
            if (kindId == 0) {
                kAssertFail(D_006359D0, 0x1B3);
            }
            if (datGetFlag(kindId + 0x5BF) != 0) {
                if ((kindId == 0xA) && ((cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF) == 9) && (datGetFlag(0x34) == 0)) {
                    enabled = 0;
                } else if ((kindId == 3) && ((cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF) == 6) && (datGetFlag(0x615) == 0)) {
                    enabled = 0;
                } else {
                    enabled = 1;
                }
            } else {
                enabled = 0;
            }
            if ((enabled != 0) && (cmmCommunityTestReversed(communityId & 0xFFFF) == 0) && (cmmCommunityTestBroken(communityId & 0xFFFF) == 0) && (cmmCommunityHasTierBit(communityId & 0xFFFF, cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFF) == 0)) {
                table = (u32 *)D_00881480[0];
                if ((u32)kindId >= table[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                kindOffset = (communityId & 0xFFFF) * 0x64;
                blocked = ((s32)((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->flags & 0x10) != 0;
                if (blocked != 0) {
                    blocked = cmmHasPendingUnlock() == 1;
                }
                if (blocked == 0) {
                    flagsTable = (u32 *)D_00881480[0];
                    if ((u32)kindId >= flagsTable[1]) {
                        kAssertFail(D_006359D0, 0x4C);
                    }
                    if (((s32)((CmmKindRecord *)((u32)kindOffset + (u32)flagsTable + 8))->flags & 2) && (cmmCommunityTestMarked(communityId & 0xFFFF) == 0) && (cmmConditionMet(communityId & 0xFFFF) == 0)) {
                        return communityId & 0xFFFF;
                    }
                }
            }
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_00247270. */
#pragma opt_common_subs on

/* measured: retail re-issues the var_19&0xFFFF mask into $a0 at every call
   site (10+ times) while keeping temp_18 ($s2) for the idx checks; mwcc b210
   CSEs the call-arg masks into $s2 and emits move $a0, $s2 instead of andi
   (nd 33, all diffs from this one pattern; u32 vs s32 temp_18 unchanged).
   Mask-CSE floor (same family as FUN_00247DD0/FUN_00248A60). */
// Find reverse candidate: returns the first rank-up-ready community that is not reversed or broken, passes cmmCommunityHasTierBit for the scan tier, has its kind flags, and passes the marked and condition checks; 0 when none qualifies. The pair with cmmFindFreshReverseCandidate.
// FUN_002474F0
/* measured: opt_common_subs off restores retail per-use masks while preserving the shared base pointer. */
#pragma opt_common_subs off
s32 cmmFindReverseCandidate(void) {
    s32 kindOffset;
    u32 *table;
    u32 *flagsTable;
    s32 communityId;
    s32 enabled;
    s32 blocked;
    s32 kindId;

    for (communityId = 1; communityId < 0x1F; communityId++) {
        if (cmmCommunityCanRankUp(communityId & 0xFFFF) != 0) {
            kindId = communityId & 0xFFFF;
            if (kindId == 0) {
                kAssertFail(D_006359D0, 0x1B3);
            }
            if (datGetFlag(kindId + 0x5BF) != 0) {
                if ((kindId == 0xA) && ((cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF) == 9) && (datGetFlag(0x34) == 0)) {
                    enabled = 0;
                } else if ((kindId == 3) && ((cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF) == 6) && (datGetFlag(0x615) == 0)) {
                    enabled = 0;
                } else {
                    enabled = 1;
                }
            } else {
                enabled = 0;
            }
            if ((enabled != 0) && (cmmCommunityTestReversed(communityId & 0xFFFF) == 0) && (cmmCommunityTestBroken(communityId & 0xFFFF) == 0) && (cmmCommunityHasTierBit(communityId & 0xFFFF, cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFF) != 0)) {
                table = (u32 *)D_00881480[0];
                if ((u32)kindId >= table[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                kindOffset = (communityId & 0xFFFF) * 0x64;
                blocked = ((s32)((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->flags & 0x10) != 0;
                if (blocked != 0) {
                    blocked = cmmHasPendingUnlock() == 1;
                }
                if (blocked == 0) {
                    flagsTable = (u32 *)D_00881480[0];
                    if ((u32)kindId >= flagsTable[1]) {
                        kAssertFail(D_006359D0, 0x4C);
                    }
                    if (((s32)((CmmKindRecord *)((u32)kindOffset + (u32)flagsTable + 8))->flags & 2) && (cmmCommunityTestMarked(communityId & 0xFFFF) == 0) && (cmmConditionMet(communityId & 0xFFFF) == 0)) {
                        return communityId & 0xFFFF;
                    }
                }
            }
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_002474f0. */
#pragma opt_common_subs on
/* MATCHED (measured): lever-2 re-masked loop counter. `#pragma opt_common_subs
   off` (measured) stops mwcc b210 from CSE-ing `i & 0xFFFF` into a saved reg
   so retail's `andi $a0,$i` is re-emitted at each call site; `i` MUST be
   declared FIRST (measured: nd 12 -> 0) so the allocator picks
   best=$s2/bestId=$s1/se=$s0/i=$s3; `target=(s16)value` sign-extends once
   before the loop; `i=1` is set before the empty-init for. */
// Top community of arcana: returns the community id whose arcana (cmmCommunityArcana) equals value and whose rank is highest, or 0 when none matches. Event callers pass the class from the Fcl slot table.
// FUN_00247770
#pragma opt_common_subs off
s16 cmmTopCommunityOfArcana(s32 value) {
    s32 i;
    s32 largest;
    s32 result;
    s32 target;

    largest = 0;
    result = 0;
    i = 1;
    target = (s16)value;
    for (; i < 0x1F; i++) {
        if (target == (s8)cmmCommunityArcana(i & 0xFFFF)) {
            s32 v = cmmCommunityRecordValue(i & 0xFFFF) & 0xFFFF;
            if (largest < v) {
                largest = v;
                result = i;
            }
        }
    }
    return result;
}
#pragma opt_common_subs on
/* MATCHED (measured): `#pragma opt_common_subs off` stops mwcc b210 from
   CSE-ing `i & 0xFFFF` into a saved reg so retail's `andi $a0,$i` is
   re-emitted at each call site; declaration order target/i/largest/result
   (measured: nd 8 -> 0) yields retail's $s0=target/$s1=result/$s2=largest/
   $s3=i/$s4=v; `target=(s8)func_00248760(value&0xFFFF)` sign-extends once. */
// Top persona of arcana: returns the roster persona whose arcana matches the arcana of community value and whose rank is highest, or 0 when none matches.
// FUN_00247820
#pragma opt_common_subs off
s16 cmmTopPersonaOfArcana(s32 value) {
    s32 target;
    s32 i;
    s32 largest;
    s32 result;
    s32 v;
    s32 w;

    largest = 0;
    result = 0;
    target = (s8)cmmCommunityArcana(value & 0xFFFF);
    for (i = 0; i < (datPersonaCountValidMembers() & 0xFFFF); i++) {
        v = datPersonaRosterSlotId(i & 0xFFFF) & 0xFFFF;
        if (target == (datPersonaGetArcana(v) & 0xFF)) {
            w = datPersonaRosterSlotRank(i & 0xFFFF) & 0xFF;
            if (largest < w) {
                largest = w;
                result = v;
            }
        }
    }
    return (s16)result;
}
#pragma opt_common_subs on
/* measured: 796 executable bytes match all 20 resolved relocations; the
   800-byte retail window ends with one unreachable alignment word.
   Ordinary s32 target/threshold lifetimes reproduce both sq/lq spills. */
// Arcana candidate: for arcana value and level threshold option, lists the personas at or below the threshold plus the nearest one above it, sorted by level. selection of -1 returns the count; otherwise the selection-th entry, or 0.
// FUN_00247900
s32 cmmArcanaCandidateAt(s32 value, s32 option, s32 selection) {
    s32 target;
    s32 threshold;
    s32 *left;
    s32 *right;
    s32 offset;
    s32 leftId;
    s32 rightId;
    s32 base;
    s32 id;
    s32 *list;
    s32 count;
    s32 capacity;
    s32 nextLevel;
    s32 nextId;
    s32 j;
    s32 i;
    s32 blocked;
    u16 flags;
    u8 level;

    target = (s8)cmmCommunityArcana(value);
    nextLevel = 0;
    nextId = 0;
    list = 0;
    count = 0;
    capacity = 0;
    if (selection != -1) {
        capacity = cmmArcanaCandidateAt(value, option, -1);
        chkmemAllocSiteTag(D_006359D0, 0x23A);
        list = (s32 *)D_008873F4[0](1, capacity * 4, 0x40000);
    }
    id = 1;
    threshold = option & 0xFF;
    for (; id < 0x100; id++) {
        if (target == (datPersonaGetArcana(id & 0xFFFF) & 0xFF)) {
            blocked = 1;
            base = (s32)iGpffffb3d4;
            offset = id * 14;
            flags = ((CmmPersonaCandidateRecord *)((u32)base + offset))->flags;
            if (!(flags & 0x10) && !(flags & 8)) {
                blocked = 0;
            }
            if (blocked == 0 && (!(flags & 0x40) || ((cmmCommunityRecordValue(value) & 0xFFFF) == 10))) {
                level = ((CmmPersonaCandidateRecord *)((u32)iGpffffb3d4 + offset))->level;
                if (level <= threshold) {
                    if (list != 0) {
                        if (count >= capacity) {
                            kAssertFail(D_006359D0, 0x24A);
                        }
                        list[count] = id;
                    }
                    count++;
                } else if (nextLevel == 0 || level < nextLevel) {
                    nextLevel = level;
                    nextId = id;
                }
            }
        }
    }
    if (nextId != 0) {
        if (list != 0) {
            if (count >= capacity) {
                kAssertFail(D_006359D0, 0x25A);
            }
            list[count] = nextId;
        }
        count++;
    }
    if (list != 0) {
        for (i = 0; i < count; i++) {
            j = i + 1;
            left = &list[i];
            for (; j < count; j++) {
                base = (s32)iGpffffb3d4;
                right = &list[j];
                rightId = *right;
                leftId = *left;
                if (((CmmPersonaCandidateRecord *)((u32)base + leftId * 14))->level > ((CmmPersonaCandidateRecord *)((u32)base + rightId * 14))->level) {
                    *left = rightId;
                    *right = leftId;
                }
            }
        }
        if (selection < count) {
            count = list[selection];
        } else {
            count = 0;
        }
        jtbl_008873EC[0](list);
    }
    return count;
}

// Roster has arcana: returns 1 when any valid roster persona has arcana value, else 0.
// FUN_00247C20
s32 cmmRosterHasArcana(s16 value) {
    s32 i = 0;
    s32 key = (s32)value;

    while (i < (datPersonaCountValidMembers() & 0xFFFF)) {
        if (key == (datPersonaGetArcana(datPersonaRosterSlotId(i & 0xFFFF) & 0xFFFF) & 0xFF)) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* measured: retail loads each case constant with daddiu ($s0, $zero, imm)
   and re-materializes it for the call arg (addiu $a0, $zero, imm), while mwcc
   b210 emits addiu for the variable and CSEs the constant into a move (nd 16)
   in every spelling tried (s32/s16/s64/u32 vars, L-suffix constants, arg-from-
   var). 64-bit-constant-load floor. */
/* nd 0/288 (object 284B in a 288B window). The existing u16 local and
   matching u16 parameter declaration for cmmCommunityHasRecord reproduce every
   instruction; changing this function's return type from s32 to u16 removes
   the redundant `andi $v0,$s0,0xffff` at the epilogue, leaving retail's
   `move $v0,$s0`. Guard spelling probes (`n >= 4` versus `n > 3`) were
   measured separately on cmmDateTableAddCount; the base spelling was retained.
   Committed at nd 0. */
// Community for arcana: maps arcana value (2 to 8) to its community id, using the alternate id when the primary community has no record. Returns 0 when neither has one.
// FUN_00247CB0
u16 cmmCommunityForArcana(s64 arcanaValue) {
    u16 communityId;
    s64 arcana;

    communityId = 0;
    arcana = (s64) (arcanaValue << 0x30) >> 0x30;
    switch (arcana) {
    case 2:
        communityId = 7;
        break;
    case 3:
        communityId = 0xB;
        if (cmmCommunityHasRecord(0xB) == 0) {
            communityId = 0xC;
        }
        break;
    case 4:
        communityId = 5;
        if (cmmCommunityHasRecord(5) == 0) {
            communityId = 6;
        }
        break;
    case 5:
        communityId = 3;
        if (cmmCommunityHasRecord(3) == 0) {
            communityId = 4;
        }
        break;
    case 6:
        communityId = 0xA;
        break;
    case 7:
        communityId = 0xE;
        if (cmmCommunityHasRecord(0xE) == 0) {
            communityId = 0xF;
        }
        break;
    case 8:
        communityId = 0x18;
        break;
    }
    if (cmmCommunityHasRecord(communityId) == 0) {
        communityId = 0;
    }
    return communityId;
}
/* Find the first enabled entry with the requested low-16 category.
   measured: use a cast for the bounds check and a mask for the address and
   category call, avoiding a cached masked counter across calls. Reuse the
   existing address-order helper. Exact 228B instructions plus 12B zero tail;
   retain the caller's s32 ABI and pass the index omitted by IDA explicitly. */
// Find community of category: returns the first community that has a record, flag 4 in its kind record, and category value (cmmCommunityCategory). Returns 0 when none matches.
// FUN_00247DD0
s32 cmmFindCommunityOfCategory(s32 value)
{
    s32 i;
    u32 target;
    u8 *base;
    s32 offset;

    i = 0;
    target = (u16)value;
    while (i < 31) {
        base = D_00881480[0];
        if ((u32)(u16)i >= ((CmmChunkHeader *)base)->count) {
            kAssertFail(D_006359D0, 0x4C);
        }
        offset = (i & 0xFFFF) * 100;
        if (((CmmKindRecord *)(cmmMiscAddOff(offset, (s32)base) + 8))->flags & 4) {
            if (target == (u16)cmmCommunityCategory(i & 0xFFFF) &&
                cmmCommunityHasRecord((u16)i) != 0) {
                return (u16)i;
            }
        }
        i++;
    }
    return 0;
}

// Date listed: returns 1 when the (month, day) pair for the date seed value is in the D_00881498 pair list, else 0. The positive counterpart of cmmDateNotListed.
// FUN_00247EC0
s32 cmmDateListed(s32 seed) {
    u8 *p = D_00881498[0] + 8;
    s32 a, b;
    s32 a0, b0;
    s32 i;
    s32 count;

    calSplitDayOfYear(seed, &a, &b);
    count = (s32)((CmmChunkHeader *)D_00881498[0])->count;
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            return 1;
        }
        p += 2;
        i++;
    }
    return 0;
}

/* MATCHED (measured): `#pragma opt_loop_invariants on` (nd 53 -> 9) hoists
   the sp3C/sp38 outputs and count into registers before the loop. The
   goto-sentinel spelling is required: `found` is set to 1 inside the loop
   (match) with `goto done`, and `found = 0` sits on the loop-exit path —
   this puts the sentinel in $v0 and yields retail's shared `beqz $v0 ->
   RET1` check. The inverted guard `if (found != 0) return 0; return 1;`
   (measured: nd 9 -> 0) matches retail's branch polarity. */
// Date not listed: returns 1 when the (month, day) pair for the date seed value is absent from the D_00881498 pair list, else 0. Script callers use it as a date-availability gate.
// FUN_00247F60
#pragma opt_loop_invariants on
s32 cmmDateNotListed(s32 value) {
    u8 *p;
    s32 key1;
    s32 key2;
    s32 count;
    s32 i;
    s32 found;

    if (calHasDayEntry(value) == 0) {
        return 0;
    }
    p = D_00881498[0] + 8;
    calSplitDayOfYear(value, &key1, &key2);
    count = (s32)((CmmChunkHeader *)D_00881498[0])->count;
    for (i = 0; i < count; i++) {
        if (p[0] == key1 && p[1] == key2) {
            found = 1;
            goto done;
        }
        p += 2;
    }
    found = 0;
done:
    if (found != 0) {
        return 0;
    }
    return 1;
}
#pragma opt_loop_invariants off
// Next unlisted date: returns the next date seed after value (below 0x16D) whose (month, day) pair is not in the D_00881498 list and whose date is valid. Returns 0 when there is none.
// FUN_00248040
s32 cmmNextUnlistedDate(s32 startDate) {
    s32 date = startDate + 1;
    s32 eligible;
    goto body;
incr:
    date += 1;
    if (date < 0x16D) {
        goto body;
    }
    return 0;
body:
    if (calHasDayEntry(date) == 0) {
        eligible = 0;
    } else if (cmmDateListed(date) != 0) {
        eligible = 0;
    } else {
        eligible = 1;
    }
    if (eligible != 0) {
        return date;
    }
    goto incr;
}
/* measured: retail booleanizes the match chain (ret in $v0, fail block out
   of line) with 8 saved regs; mwcc b210 inlines the fail skips and balloons
   to 10 saved registers (best nd 30 without the ret booleanize, 82 with).
   Register-pressure + if-chain-layout floor. */
// Nth eligible community: returns the id of the value-th community in the D_00881490 table for (option, selection) whose rank is inside its bounds, is not rank 10, is not flagged 3, and is not the table head. Returns 0 when there is no such entry.
// FUN_002480E0
u16 cmmNthEligibleCommunity(s32 requestedIndex, s32 month, s32 day) {
    s32 count;
    s32 rank;
    CmmEligibleRecord *entry;
    s32 index;
    s32 eligible;
    u16 communityId;
    s32 matchIndex;

    entry = (CmmEligibleRecord *)(D_00881490[0] + 8);
    count = (s32)((CmmChunkHeader *)D_00881490[0])->count;
    matchIndex = 0;
    index = 0;
    goto loop_15;
body_15:
    if ((entry->month == month) && (entry->day == day)) {
        rank = (s32)(cmmCommunityRecordValue(entry->communityId) & 0xFFFF);
        if ((rank >= (s32)entry->minRank) &&
            (rank <= (s32)entry->maxRank) &&
            ((cmmCommunityRecordValue(entry->communityId) & 0xFFFF) != 0xA) &&
            (cmmCommunityTestRecordFlags(entry->communityId, 3) == 0) &&
            ((communityId = entry->communityId), (communityId != (cmmCommunityGetTableHead() & 0xFFFF)))) {
            eligible = 1;
        } else {
            eligible = 0;
        }
        if (eligible != 0) {
            if (matchIndex == requestedIndex) {
                return entry->communityId;
            }
            matchIndex += 1;
            goto block_14;
        }
        goto block_14;
    }
block_14:
    entry++;
    index += 1;
loop_15:
    if (index < count) {
        goto body_15;
    }
    return 0U;
}
/* measured (wave 14 retest — nd 73 reproduced exactly; no match): draft-based
   reconstruction `while (var_20 < 0x1F) { if (cmmCommunityHasRecord(var_20&0xFFFF)
   && cmmCommunityTestRecordFlags(var_20&0xFFFF,3)==0) { temp_2 = cmmCommunityFindRecord(...); ...
   *0x64 ladder, D_00881480 bounds, +0x12 flags, cmmCommunitySetReversed } }` scores
   nd 73 — mwcc b210 CSEs var_20&0xFFFF into a saved register ($s3) at loop
   top and emits move $a0,$s3 per call, retail re-issues andi per site.
   Mixed `(u16)`/`& 0xFFFF` spellings regress to nd 90 (normalised away).
   Mask-CSE floor (same family as FUN_002483C0/FUN_00248B80). */
// Tick reverse progress: for each community with a record and no flag band 3, adds 1 to its progress counter (+0xA) when its kind record's threshold (+0x12) is set. Sets REVERSED once the counter reaches the threshold. Called from cldScheduler.c.
// FUN_00248240
/* measured: opt_common_subs off restores retail per-use masks while preserving the two table bases. */
#pragma opt_common_subs off
void cmmTickReverseProgress(void) {
    s32 kindOffset;
    s32 communityId;
    s32 thresholdReached;
    u32 kindId;
    u32 *table;
    u32 *thresholdTable;
    CmmCommunityRecord *record;

    communityId = 1;
    while (communityId < 0x1F) {
        if ((cmmCommunityHasRecord(communityId & 0xFFFF) != 0) && (cmmCommunityTestRecordFlags(communityId & 0xFFFF, 3) == 0)) {
            record = (CmmCommunityRecord *)cmmCommunityFindRecord(communityId & 0xFFFF);
            if (record == NULL) {
                thresholdReached = 0;
                goto block_13;
            }
            table = (u32 *)D_00881480[0];
            kindId = communityId & 0xFFFF;
            if (kindId >= table[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            kindOffset = (communityId & 0xFFFF) * 0x64;
            if (((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->reverseThreshold != 0) {
                record->reverseProgress = record->reverseProgress + 1;
                thresholdTable = (u32 *)D_00881480[0];
                if (kindId >= thresholdTable[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                if (record->reverseProgress >= ((CmmKindRecord *)((u32)kindOffset + (u32)thresholdTable + 8))->reverseThreshold) {
                    thresholdReached = 1;
                } else {
                    goto block_12;
                }
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            thresholdReached = 0;
block_13:
            if (thresholdReached != 0) {
                cmmCommunitySetReversed(communityId & 0xFFFF);
            }
        }
        communityId += 1;
    }
}
/* measured: opt_common_subs on restores the file baseline after func_00248240. */
#pragma opt_common_subs on
/* measured (wave 14 retest — nd 119 with a fresh draft-based reconstruction,
   no match): loop of cmmCommunityHasRecord/func_00107ac0==0xA/func_00248a60/
   cmmCommunityTestRecordFlags guards, the D_00881494 two-u16 table scan into var_20,
   cmmCommunityFindRecord (real signature s32(s32) — the m2c's 2nd arg is a leftover
   $5 the callee ignores), +0x12 flags and cmmCommunitySetReversed — mask-CSE
   dominates (mwcc drills var_21&0xFFFF into a saved register; nd 30+ per the
   earlier note's better spelling). Same family as FUN_00248240/FUN_00248B80.
   func_00248a60 extern added as s32(s32). */
/* measured: corrected target callees to func_00248a60(s32), cmmCommunityTestRecordFlags(s32,s32),
   kAssertFail(void *,s32), cmmCommunitySetReversed(s32), and
   cmmCommunityHasRecord(s32); active seed measured 552B vs 544B retail window,
   normalized_diff 109 (oversized reconstruction); archived without further probes. */
// Advance reverse progress: for each rank-10 community (other than value) with a record and no flag band 3, adds its paired value from the D_00881494 pair table to its progress counter (+0xA). When the progress reaches the kind record's threshold (+0x12), sets REVERSED through cmmCommunitySetReversed.
// FUN_002483C0
#pragma push
/* measured: opt_propagation off + saved regs $s6=temp_20, $s5=var_20 counter(1),
   $s4=temp_17, $s3=temp_18 mask, $s2=temp_19 masked arg, $s1=temp_2, $s0=temp_16;
   per-use u16 call_idx=(u16)var_20 conversions preserve andi immediates and remove $s7 constant. */
#pragma opt_propagation off
void cmmAdvanceReverseProgress(u16 excludedCommunity) {
    s32 kindOffset;
    s32 communityId;
    s32 increment;
    u32 excludedId;
    CmmCommunityRecord *record;
    u32 *table;
    u32 *thresholdTable;
    s32 thresholdReached;
    u16 callId;

    communityId = 1;
    excludedId = excludedCommunity;
    while (communityId < 0x1F) {
        if (excludedId == communityId) {
            goto block_15;
        }
        if (cmmCommunityHasRecord((u16)communityId) == 0) {
            goto block_15;
        }
        callId = (u16)communityId;
        if (((u16)cmmCommunityRecordValue(callId)) != 0xA) {
            goto block_15;
        }
        callId = (u16)communityId;
        if (cmmReversedAtRank(callId) == 0) {
            goto block_15;
        }
        callId = (u16)communityId;
        if (cmmCommunityTestRecordFlags(callId, 3) != 0) {
            goto block_15;
        }
        {
            u8 *p;
            s32 count;
            s32 i;
            s32 kindId;

            table = (u32 *)D_00881494[0];
            p = (u8 *)table + 8;
            count = (s32)((CmmChunkHeader *)table)->count;
            i = 0;
            kindId = (u16)communityId;
            while (i < count) {
                if (((CmmReversePair *)p)->communityId == kindId) {
                    if (((CmmReversePair *)p)->otherId == excludedId) {
                        increment = ((CmmReversePair *)p)->increment;
                        goto block_14;
                    }
                }
                p += 8;
                i += 1;
            }
            increment = 0;
block_14:
            callId = (u16)communityId;
            record = (CmmCommunityRecord *)cmmCommunityFindRecord(callId);
            if (record == NULL) {
                thresholdReached = 0;
                goto block_13;
            }
            table = (u32 *)D_00881480[0];
            if (kindId >= table[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            callId = (u16)communityId;
            kindOffset = callId * 0x64;
            if (((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->reverseThreshold == 0) {
                goto block_12;
            }
            record->reverseProgress += increment & 0xFFFF;
            thresholdTable = (u32 *)D_00881480[0];
            if (kindId >= thresholdTable[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            if (record->reverseProgress >= ((CmmKindRecord *)((u32)kindOffset + (u32)thresholdTable + 8))->reverseThreshold) {
                thresholdReached = 1;
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            thresholdReached = 0;
block_13:
            if (thresholdReached != 0) {
                callId = (u16)communityId;
                cmmCommunitySetReversed(callId);
            }
        }
block_15:
        communityId += 1;
    }
}
/* measured: restore pragma state after func_002483c0. */
#pragma pop

/* measured: #pragma opt_loop_invariants on/off scoped around this function:
   retail hoists option&0xFFFF and var_4&0xFFFF into $s1/$s6 before the loop;
   without the pragma mwcc b210 re-masks inside the loop (nd 43 -> 2). s32
   option (not u16) is also required so the ladder calls pass the raw register
   instead of a CSE'd mask. */
// Message-stream entry: returns the chunk 3 record (D_0088148C) for kind value and community id option. When value is 0 it derives the state code from cmmCommunityHasRecord and cmmCommunityCanRankUp (1, 2, 3, or 6). cmmMsgStreamStart stores the record as the stream source.
// FUN_002485E0
#pragma opt_loop_invariants on
u8 *cmmMsgStreamEntry(s32 requestedKind, s32 communityId) {
    s32 kind = requestedKind;
    s32 selectedKind;
    s32 count;
    s32 index;
    s32 flagBit;
    u8 rank;
    u8 *entry;

    if (!(kind & 0xFFFF)) {
        /* cmmCommunityHasRecord is narrow at the 00247270-family sites for retail's
           andi, but 002485e0 passes communityId whole as s32, so override it here. */
        extern s32 cmmCommunityHasRecord(s32 communityId);
        if (cmmCommunityHasRecord(communityId) == 0) {
            selectedKind = 3;
        } else if (cmmCommunityCanRankUp(communityId) != 0) {
            if ((cmmCommunityRecordValue(communityId) & 0xFFFF) == 9) {
                selectedKind = 6;
            } else {
                selectedKind = 2;
            }
        } else {
            selectedKind = 1;
        }
        kind = selectedKind & 0xFFFF;
    }
    entry = (u8 *)(D_0088148C[0] + 8);
    count = ((CmmChunkHeader *)D_0088148C[0])->count;
    index = 0;
    while (index < count) {
        if ((((CmmMessageEntry *)entry)->communityId == (communityId & 0xFFFF)) && (((CmmMessageEntry *)entry)->kind == (kind & 0xFFFF)) && ((rank = ((CmmMessageEntry *)entry)->rank, rank == 0) || ((rank != 0) && (rank == (cmmCommunityRecordValue(communityId) & 0xFFFF)))) && ((flagBit = ((CmmMessageEntry *)entry)->flagBit, flagBit == 0) || (datGetFlag(flagBit) != 0))) {
            return entry;
        }
        entry += 0x10;
        index += 1;
    }
    return NULL;
}
#pragma opt_loop_invariants off
// Community arcana: returns the arcana byte at +0x10 of community value's kind record (chunk 0), asserting the id is in range.
// FUN_00248760
s64 cmmCommunityArcana(s32 communityId) {
    u8 *table = D_00881480[0];
    s32 off;

    if ((u32)(communityId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)communityId * 100;
    return ((CmmKindRecord *)(off + (u32)table + 8))->arcana;
}

// Community event value: returns the s8 value for slot option (0 to 7) of community value's record array (stride 8, value at +0x28) when the slot's gate at +0x24 is zero or its datGetFlag is set. Returns 0 otherwise.
// FUN_002487E0
s8 cmmCommunityEventValue(s32 value, s8 option) {
    u8 *base;
    s32 off;
    s32 elem;
    s32 idx;
    s32 p;
    u8 *q;
    s32 v;

    if (option >= 8) {
        kAssertFail(D_006359D0, 0x3A3);
    }
    base = D_00881480[0];
    if ((u32)(value & 0xFFFF) >= ((CmmChunkHeader *)base)->count) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)value * 100;
    elem = off + (s32)base + 8;
    if (elem != 0) {
        idx = option * 8;
        p = idx + elem;
        q = (u8 *)(p + 0x28);
        /* Eight-byte event slots: gate at +0x24, value at +0x28; a typed slot changes MWCC scheduling (nd 60). */
        if (*(u32 *)(p + 0x28) != 0) {
            v = *(u32 *)(p + 0x24);
            if ((v == 0) || (datGetFlag(v) != 0)) {
                return *(s8 *)q;
            }
        }
    }
    return 0;
}
// Community tier bit: returns 1 when bit (option - 1) is set in the u16 at +0xC of community value's kind record. option must be 1 to 9.
// FUN_002488E0
s32 cmmCommunityHasTierBit(s32 communityId, s32 requestedTier) {
    s32 tier;
    s32 tierBits;
    u8 *table = D_00881480[0];
    u8 *record;
    s32 off;

    if ((u32)(communityId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)communityId * 100;
    record = (u8 *)(off + (u32)table + 8);
    if (record != NULL) {
        tierBits = ((CmmKindRecord *)record)->tierBits;
    } else {
        tierBits = 0;
    }
    tier = requestedTier & 0xFF;
    if ((tier == 0) || (tier >= 0xA)) {
        return 0;
    }
    return (tierBits & (1 << (tier - 1))) != 0;
}
// Community category: returns the u16 at +0xE of community value's kind record (chunk 0), asserting the id is in range.
// FUN_002489C0
u16 cmmCommunityCategory(s32 communityId) {
    u8 *table = D_00881480[0];
    s32 off;
    u8 *record;

    if ((u32)(communityId & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)communityId * 100;
    record = (u8 *)(off + (u32)table + 8);
    if (record != NULL) {
        return ((CmmKindRecord *)record)->category;
    }
    return 0;
}

/* measured: retail keeps value raw in $s3, masks once into $s1 (temp_17)
   and re-masks into $v1 for the 100-multiply; mwcc b210 CSEs the mask into
   one register (best nd 37) in every spelling tried ((u16) vs & 0xFFFF vs
   temp_17 = value). Mask-CSE floor (same family as FUN_00247DD0). */
// Reversed at rank: returns 1 when community value has a record, the REVERSED bit in its kind record (chunk 0), and a level byte at or above its rank from cmmCommunityRecordValue; else 0.
// FUN_00248A60
/* measured: opt_common_subs off preserves the raw parameter call and per-use table masks. */
#pragma opt_common_subs off
s32 cmmReversedAtRank(s32 communityId) {
    s32 kindOffset;
    u32 kindId;
    u8 level;
    u32 *table;
    u32 *levelTable;

    /* Retail reuses raw communityId for this unprototyped call; keep that a0 value. */
    extern s32 cmmCommunityHasRecord();
    if (cmmCommunityHasRecord() == 0) {
        return 0;
    }
    table = (u32 *)D_00881480[0];
    kindId = communityId & 0xFFFF;
    if (kindId >= table[1]) {
        kAssertFail(D_006359D0, 0x4C);
    }
    kindOffset = (communityId & 0xFFFF) * 0x64;
    if ((s32)((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->flags & 1) {
        levelTable = (u32 *)D_00881480[0];
        if (kindId >= levelTable[1]) {
            kAssertFail(D_006359D0, 0x4C);
        }
        level = ((CmmKindRecord *)((u32)kindOffset + (u32)levelTable + 8))->reverseRankLimit;
        if ((s32)level >= (cmmCommunityRecordValue(communityId) & 0xFFFF)) {
            return 1;
        }
    }
    return 0;
}
/* measured: opt_common_subs on restores the file baseline after func_00248a60. */
#pragma opt_common_subs on
/* measured: retail re-issues var_18&0xFFFF into $a0 at every call site
   (3 sites) while keeping temp_21 in $s5 for the bounds checks (6 saved
   regs); mwcc b210 CSEs the mask into a saved register $s0 at loop top and
   emits move $a0,$s0 per call (nd 75; tried & 0xFFFF / (u16) mixes at all
   sites, temp_21 u32 vs s32). Mask-CSE floor (same family as
   FUN_002474F0/FUN_002483C0/FUN_00248A60). */
// Top reversed community: returns the id with the highest rank among communities that are reversed and whose level meets their rank (see cmmReversedAtRank), or 0 when none qualifies.
// FUN_00248B80
/* measured: opt_common_subs off restores retail per-use masks while preserving both table bases. */
#pragma opt_common_subs off
s32 cmmTopReversedCommunity(void) {
    s32 kindOffset;
    s32 rank;
    s32 communityId;
    s32 highestRank;
    s32 result;
    s32 eligible;
    u32 kindId;
    u8 level;
    u32 *table;
    u32 *levelTable;

    highestRank = -1;
    result = 0;
    communityId = 0;
    while (communityId < 0x1F) {
        if (cmmCommunityHasRecord(communityId & 0xFFFF) == 0) {
            eligible = 0;
        } else {
            table = (u32 *)D_00881480[0];
            kindId = communityId & 0xFFFF;
            if (kindId >= table[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            kindOffset = (communityId & 0xFFFF) * 0x64;
            if ((s32)((CmmKindRecord *)((u32)kindOffset + (u32)table + 8))->flags & 1) {
                levelTable = (u32 *)D_00881480[0];
                if (kindId >= levelTable[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                level = ((CmmKindRecord *)((u32)kindOffset + (u32)levelTable + 8))->reverseRankLimit;
                if ((s32)level >= (cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF)) {
                    eligible = 1;
                } else {
                    goto block_10;
                }
            } else {
block_10:
                eligible = 0;
            }
        }
        if (eligible != 0) {
            rank = cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF;
            if (highestRank < rank) {
                highestRank = rank;
                result = communityId;
            }
        }
        communityId += 1;
    }
    return result & 0xFFFF;
}
/* measured: opt_common_subs on restores the file baseline after func_00248b80. */
#pragma opt_common_subs on

/* measured: retail hoists the 0xFFFF0000 mask constant into $v1 before the
   loop and keeps the loop count in $t0; without #pragma opt_loop_invariants
   mwcc b210 rematerializes lui per iteration (nd 16). Declarations must be
   count/var_10/var_9/temp_7 order for the $t0/$t1/$t2 allocation. */
// Table lookup value: scans the 12-byte entries at D_008814C0 for the key (value high half, option low half, selection at +4) and returns the value at +8, or -1.
// FUN_00248D00
#pragma opt_loop_invariants on
s32 cmmTableLookupValue(s32 keyHigh, s32 keyLow, s32 kind) {
    s32 count;
    u8 *entry;
    s32 index;
    s32 key;

    entry = D_008814C0[0] + 8;
    count = (s32)((CmmChunkHeader *)D_008814C0[0])->count;
    index = 0;
    while (index < count) {
        key = ((CmmLookupValue *)entry)->key;
        if ((((u32)(key & 0xFFFF0000) >> 0x10) == keyHigh) && ((key & 0xFFFF) == keyLow) && (((CmmLookupValue *)entry)->kind == kind)) {
            return ((CmmLookupValue *)entry)->value;
        }
        entry += 0xC;
        index += 1;
    }
    return -1;
}
#pragma opt_loop_invariants off

/* measured: widening the declaration of cmmCommunityCounterpart to s64 is correct:
   the callee truncates internally without sign-extending on entry. This lets
   the caller pass the already-masked key in $s1, reproducing the retail move
   and the complete -0x40 frame/s0-s2 prologue. With propagation disabled,
   this body is MATCH at nd 0 (object 148B/window 160B). */
// Resolve counterpart: returns the counterpart of community value when value has no record and its counterpart does; otherwise returns value.
// FUN_00248D80
/* measured: opt_propagation off preserves retail's raw/key lifetimes. */
#pragma opt_propagation off
s64 cmmResolveCounterpart(s64 value)
{
    s64 raw;
    s64 key;
    s64 rawLow;

    raw = value;
    key = raw & 0xFFFF;
    if (cmmCommunityHasRecord(key) == 0) {
        rawLow = (s16)raw;
        key = (s16)cmmCommunityCounterpart(key);
        if ((rawLow != key) && (cmmCommunityHasRecord((u16)key) != 0)) {
            return key;
        }
    }
    return raw;
}
/* measured: close the scoped propagation probe explicitly. */
#pragma opt_propagation on



// Table lookup flagged: scans the 12-byte entries at D_008814C8 for the key (value high half, option low half, selection or 0xFFFF) and returns the u16 at +0xA when its 0x8000 bit is set. Returns -1 otherwise.
// FUN_00248E20
s32 cmmTableLookupFlagged(s32 keyHigh, s32 keyLow, s32 kind) {
    s32 count;
    s32 key;
    s32 flagBit;
    u8 *entry;
    s32 index;
    u16 value;

    entry = D_008814C8[0] + 8;
    count = (s32)((CmmChunkHeader *)D_008814C8[0])->count;
    index = 0;
    while (index < count) {
        flagBit = ((CmmFlaggedValue *)entry)->flagBit;
        if (flagBit == 0 || datGetFlag(flagBit) != 0) {
            key = ((CmmFlaggedValue *)entry)->key;
            if (((u32)(key & 0xFFFF0000) >> 0x10) == keyHigh && (key & 0xFFFF) == keyLow && (((CmmFlaggedValue *)entry)->kind == 0xFFFF || ((CmmFlaggedValue *)entry)->kind == kind)) {
                value = ((CmmFlaggedValue *)entry)->value;
                if (value & 0x8000) {
                    return value;
                }
            }
        }
        entry += 0xC;
        index++;
    }
    return -1;
}
// Returns 0 when option is at or below the first threshold of date-table entry value, 1 when it is at or below the second, else 2 [inferred].
// FUN_00248F20
s32 cmmDateTableRangeKind(s32 entryId, s32 value) {
    u8 *table = (u8 *)(D_008814CC[0] + 8);
    s16 index = (s16)entryId;
    s32 offset;

    if (index >= 5) {
        kAssertFail(D_006359D0, 0x11B);
    }
    offset = index * 8;
    if (value <= ((CmmDateRange *)(table + offset))->threshold[0]) {
        return 0;
    }
    table = (u8 *)(D_008814CC[0] + 8);
    if (index >= 5) {
        kAssertFail(D_006359D0, 0x11B);
    }
    if (value <= ((CmmDateRange *)(offset + (u32)table))->threshold[1]) {
        return 1;
    }
    return 2;
}

// Date table find index: returns the index of the ordinary record whose month and day (calSplitDayOfYear of the seed) match, or -1 when none does.
// FUN_00249010
s32 cmmDateTableFindIndex(s32 seed) {
    u8 *base = D_008814D0[0];
    u8 *p = base + 8;
    s32 count = (s32)((CmmChunkHeader *)base)->count;
    s32 a, b;
    s32 a0, b0;
    s32 i;

    calSplitDayOfYear(seed, &a, &b);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((((CmmDateRecord *)p)->month == a0) && (((CmmDateRecord *)p)->day == b0)) {
            return i;
        }
        p += 0x24;
        i++;
    }
    return -1;
}

/* measured: the hit path copies the index (`k = i; goto found;`) and the exhausted path sets
   `k = -1` - the copy keeps retail's bne / b-to-found pair; `if (k != -1) return entry; return NULL;`
   places the NULL return out of line as retail. */
// Date table find record: returns the ordinary record for the date seed, or NULL when none matches.
// FUN_002490B0
u8 *cmmDateTableFindRecord(s32 seed) {
    s32 month;
    s32 day;
    u8 *records;
    u8 *p;
    s32 count;
    s32 a0;
    s32 b0;
    s32 i;
    s32 k;

    records = D_008814D0[0] + 8;
    p = records;
    count = (s32)((CmmChunkHeader *)D_008814D0[0])->count;
    calSplitDayOfYear(seed, &month, &day);
    i = 0;
    a0 = month;
    b0 = day;
    while (i < count) {
        if ((((CmmDateRecord *)p)->month == a0) && (((CmmDateRecord *)p)->day == b0)) {
            k = i;
            goto found;
        }
        p += 0x24;
        i++;
    }
    k = -1;
found:
    if (k != -1) {
        return records + k * 0x24;
    }
    return NULL;
}

// Date table find special record: returns the special record (slot from func_001064F0 at 0x6D) when flag 0xA61 is set and value has reached its threshold, else NULL.
// FUN_00249180
u8 *cmmDateTableFindSpecialRecord(u32 date) {
    s32 month;
    s32 day;
    u8 *record = D_008814D0[0] + 8;

    calSplitDayOfYear(date, &month, &day);
    if (datGetFlag(0xA61) != 0) {
        record += datGetScriptValue(0x6D) * 0x24;
        if (date >= calDayOfYearFromMonthDay(((CmmDateRecord *)record)->specialMonth, ((CmmDateRecord *)record)->specialDay)) {
            return record;
        }
    }
    return NULL;
}
// Date table has entry: returns 1 when cmmDateTableFindIndex finds an ordinary entry for the seed. The seed local is never assigned in this body; the matched code passes the argument register through as-is.
// FUN_00249230
s32 cmmDateTableHasEntry(void) {
    s32 seed;
    u8 *base8 = D_008814D0[0] + 8;
    s32 idx = cmmDateTableFindIndex(seed);
    u8 *p;

    if (idx != -1) {
        p = base8 + idx * 0x24;
    } else {
        p = NULL;
    }
    if (p == NULL) {
        return 0;
    }
    return 1;
}

/* measured: both failure paths reach one `p = NULL; t = p;` block (a goto target) and the success
   path copies `t = p` before the join - the copy keeps retail's b-over-null trampoline; the return
   is `if (t == NULL) return 0; return 1;` (retail bnez / move v0,zero / li 1 tail). */
// Date table has special record: returns 1 when the special record for date value is unlocked (flag 0xA61 and its threshold), else 0.
// FUN_002492B0
s32 cmmDateTableHasSpecialRecord(u32 date) {
    s32 month;
    s32 day;
    u8 *p;
    u8 *t;

    p = D_008814D0[0] + 8;
    calSplitDayOfYear(date, &month, &day);
    if (datGetFlag(0xA61) == 0) {
        goto null_p;
    }
    p += datGetScriptValue(0x6D) * 0x24;
    if (date < calDayOfYearFromMonthDay(((CmmDateRecord *)p)->specialMonth, ((CmmDateRecord *)p)->specialDay)) {
        goto null_p;
    }
    t = p;
    goto join;
null_p:
    p = NULL;
    t = p;
join:
    if (t == NULL) {
        return 0;
    }
    return 1;
}
/* Select an ordinary or special calendar record, then read column 0 or 1.
   measured: the neighboring shared-NULL join/copy pattern retains retail's
   branch trampolines; cmmMiscAddOff preserves the final address operand order.
   Exact 328B instructions plus 8B zero tail; caller-facing s32 ABI unchanged. */
// Date table read column: returns the 32-bit value at +12 of column selection (0 or 1) of the record selected for date option; special selects the special record, otherwise the ordinary record. Returns 0 when no record is selected.
// FUN_00249370
s32 cmmDateTableReadColumn(s32 special, s32 date, s32 column)
{
    s32 month;
    s32 day;
    u8 *record;
    u8 *selected;
    s32 index;

    if (special == 0) {
        record = D_008814D0[0] + 8;
        index = cmmDateTableFindIndex(date);
        if (index != -1) {
            record += index * 36;
        } else {
            record = NULL;
        }
        selected = record;
    } else {
        record = D_008814D0[0] + 8;
        calSplitDayOfYear(date, &month, &day);
        if (datGetFlag(0xA61) == 0) goto null_record;
        record += datGetScriptValue(0x6D) * 36;
        if ((u32)date < calDayOfYearFromMonthDay(((CmmDateRecord *)record)->specialMonth, ((CmmDateRecord *)record)->specialDay)) goto null_record;
        selected = record;
        goto selected_record;
null_record:
        record = NULL;
        selected = record;
    }
selected_record:
    if (column != 0 && column != 1) {
        kAssertFail(D_006359D0, 0x4A0);
    }
    if (selected == NULL) return 0;
    return ((CmmDateColumn *)(cmmMiscAddOff(column * 16, (s32)selected) + 4))->value;
}
/* Unsigned address addition preserves the retail operand order without
   changing the signed counter-delta arithmetic. */
static inline u32 cmmMiscAddAddress(u32 offset, u32 base)
{
    return offset + base;
}

// Date table apply column: selects the record for date (special record when flag 0xA61 allows it), then applies the column's two counter deltas clamped at 99 through datItemSetCount; asserts column is 0 or 1.
// FUN_002494C0
s32 cmmDateTableApplyColumnDelta(s32 date, s32 column)
{
    s32 month;
    s32 day;
    u8 *base;
    u8 *record;
    u8 *selected;
    u16 *key;
    s32 value;
    s32 offset;
    u16 id;

    base = D_008814D0[0] + 8;
    calSplitDayOfYear(date, &month, &day);
    if (datGetFlag(0xA61) == 0) goto null_record;
    record = base + datGetScriptValue(0x6D) * 36;
    if ((u32)date < (u32)calDayOfYearFromMonthDay(((CmmDateRecord *)record)->specialMonth, ((CmmDateRecord *)record)->specialDay)) goto null_record;
    selected = record;
    goto selected_record;
null_record:
    record = NULL;
    selected = record;
selected_record:
    if (column != 0 && column != 1) kAssertFail(D_006359D0, 0x4AB);
    if (selected == NULL) kAssertFail(D_006359D0, 0x4AC);
    offset = column * 16;
    key = (u16 *)(cmmMiscAddOff(offset, (s32)selected) + 4);
    id = *key;
    if (id != 0) {
        value = datItemCount((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, ((CmmDateColumn *)(cmmMiscAddAddress((u32)offset, (u32)selected) + 4))->deltaFirst);
        if (value > 99) value = 99;
        datItemSetCount((s32)*(s16 *)key, value & 0xFF);
    }
    key = (u16 *)(cmmMiscAddAddress((u32)offset, (u32)selected) + 8);
    id = *key;
    if (id != 0) {
        offset = (u32)column << 4;
        value = datItemCount((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, ((CmmDateColumn *)(cmmMiscAddOff(offset, (s32)selected) + 4))->deltaSecond);
        if (value > 99) value = 99;
        datItemSetCount((s32)*(s16 *)key, value & 0xFF);
    }
    return 1;
}
/* measured: nd 4 (obj 252B vs window 256B, so THREE real words) from 14.
   Reconstructed from the m2c draft in src/generated/code1_0024.c, which gave the
   control flow directly; the `(s64)((x + 0x4EA) << 0x30) >> 0x30` it prints is
   just `(s16)(v + 0x4EA)`.

   Two levers. Declaring `v` before `n` fixes a whole-function $s0/$s1 mirror
   (14 -> 5) -- m2c's own var_16/var_17 numbering is the hint, var_17 is `v` and
   retail colours it $s1. Then `#pragma opt_propagation off` (measured: 5 -> 4)
   stops b210 forwarding `v = value` so the zero test reads the saved $s1 copy the
   way retail does, instead of testing $a0 directly.

   Residual: the two parameter saves are emitted in register order ($s0 then $s1)
   where retail emits them in parameter order (value to $s1 first), and one
   commutative `addu` has its operands transposed. Measured and rejected:
   `option + func_001064f0(0x57)`, seeding `n = option` at the top, seeding it just
   before the add, and opt_common_subs off (5). Nine spellings.
   Parameter-save order floor. */
static inline s32 cmmAddCountFirst(s32 count, s32 delta) { return count + delta; }

/* nd 6 -> 4. The `+` here is a commutative operand-order row: retail emits
   addu $s0,$v0,$s0 (call result first) and b210 emits addu $s0,$s0,$v0. Writing it
   at the callsite does not move it; the operands have to travel through an inline
   helper's parameter list, and the helper MUST sit above the // FUN_ marker - a
   definition between the marker and the function body breaks the name parse and the
   function silently vanishes from the verify report.
   Remaining 2 words are the prologue parameter saves: retail emits move $s1,$a0
   then move $s0,$a1, b210 the other way round. Measured unmoved by declaration
   order (nd 15), by reversing the helper parameters, and by opt_lifetimes,
   reg_class_allocs, opt_scalarizeliveranges, opt_serializeassignments,
   opt_repositioncode, opt_movepostops, opt_prelinearize, opt_dead_assignments,
   opt_marknonregtemps, opt_optimizenonregaccess and no_branch_likely.
   Committed at nd 4. */
/* measured: parked body committed at nd 4. */
/* measured: parked body committed at nd 4. */
// Date table add count: selects counter slot value (0 = the next free slot), adds option through cmmAddCountFirst, and at 4 completes the slot by setting flag 0x9AF+slot and clearing the counter.
// FUN_00249670
/* measured: opt_propagation off is required for the parked nd4 body. */
#pragma opt_propagation off
s32 cmmDateTableAddCount(s32 value, s32 option)
{
    s32 n;

    if (value == 0) {
        value = datGetScriptValue(0x58);
        if (value == 0) {
            kAssertFail(D_006359D0, 0x4C8);
        }
    }
    datSetScriptValue(0x58, value);
    if (!(datItemCount((s16)(value + 0x4EA)) & 0xFF)) {
        kAssertFail(D_006359D0, 0x4CC);
    }
    n = cmmAddCountFirst(datGetScriptValue(0x57), option);
    if (n >= 4) {
        n = 0;
        datSetFlag(value + 0x9AF, 1);
        datSetScriptValue(0x58, 0);
    }
    datSetScriptValue(0x57, n);
    return n;
}
/* measured: opt_propagation scope closes at the file baseline. */
#pragma opt_propagation on
// Date table find nth match: counts the 20 records of D_008814E0 whose date matches value (0 = any) and whose status matches option (0-3); returns the 1-based index of the record at count selection, or 0 when none.
// FUN_00249770
s32 cmmDateTableFindNthMatch(s32 date, s32 status, s32 requestedIndex) {
    s32 index;
    s32 passedChecks;
    s32 off;
    u8 *table;
    u8 *p;
    s32 matchIndex;

    matchIndex = 0;
    index = 0;
    while (index < 0x14) {
        table = D_008814E0[0];
        if ((u32)((index + 1) & 0xFFFF) >= ((CmmChunkHeader *)table)->count) {
            kAssertFail(D_006359D0, 0x13B);
        }
        off = (u16)(index + 1) * 72;
        p = (u8 *)(off + (u32)table + 8);
        passedChecks = 0;
        if (date == 0 || date == *(s32 *)p) {
            passedChecks += 1;
        }
        switch (status) {
        case 0:
            if (datGetFlag(index + 0x9B0) != 0) {
                passedChecks += 1;
            }
            break;
        case 1:
            if (((datItemCount((s16)(index + 0x4EB)) & 0xFF) > 0) && (datGetFlag(index + 0x9B0) == 0)) {
                passedChecks += 1;
            }
            break;
        case 2:
            if ((datItemCount((s16)(index + 0x4EB)) & 0xFF) > 0) {
                passedChecks += 1;
            }
            break;
        case 3:
            if ((datItemCount((s16)(index + 0x4EB)) & 0xFF) == 0) {
                passedChecks += 1;
            }
            break;
        }
        if (passedChecks == 2) {
            if (matchIndex == requestedIndex) {
                return index + 1;
            }
            matchIndex += 1;
        }
        index++;
    }
    return 0;
}

/* measured: the retail range guard is now byte-exact -- `((s32)(value &
   0xFFFF) < 0) || ((value & 0xFFFF) > 5)` reproduces `andi; bltz; slti $at,6`
   (nd 34 -> 21), so the "dead-comparison" half of the old note is solved.
   Recipe A half-scaler (s32 z; u32 c; fz = (f32)(s32)((c>>1)|(c&1));
   fz = fz + fz) and retail's `if (z >= 0) direct else half-scaler` layout
   keep everything through the join correct. Residual 9 words, all FPU:
   (1) the or folds into $v0 (rd = rt) where retail keeps $v1 (rd = rs) and
   the following cvt lands in $f0 with add.s $f1,$f0,$f0 instead of retail's
   cvt into $f1 and add.s $f1,$f1,$f1; (2) mwcc sinks the div.s below the
   lh/cvt of the second operand, so w and t swap FP registers and the
   madd.s operands transpose. Twelve spellings measured (inline / cmmMiscOr
   helper / named or-temp x named-t / inline-div / named-w / parenthesised
   product) all give exactly nd 21. FPU allocation + scheduling floor.
   Committed at nd 21. */
// Date table roll value: returns the entry's base value plus a random fraction of its span (D_008814EC roll table); asserts index is 0-5.
// FUN_00249960
s32 cmmDateTableRollValue(s32 index)
{
  u8 *base = (u8 *) D_008814EC[0];
  s32 offset;
  u8 *record;
  s16 baseValue;
  unsigned int randomValue;
  u32 bits;
  f32 randomFloat;
  f32 scale;
  if ((((s32) (index & 0xFFFF)) < 0) || ((index & 0xFFFF) > 5))
  {
    kAssertFail(D_006359D0, 0x16B);
  }
  offset = ((u16) index) * 14;
  record = (u8 *) ((offset + ((u32) base)) + 8);
  baseValue = ((CmmFishingRecord *)(offset + (u32)base + 8))->base;
  randomValue = RpRandom();
  if (randomValue >= 0)
  {
    randomFloat = (f32) randomValue;
  }
  else
  {
    bits = (u32) randomValue;
    randomFloat = (f32) ((s32) ((bits >> 1) | (bits & 1)));
    randomFloat = randomFloat + randomFloat;
  }
  scale = randomFloat;
  scale = scale / 2147483648.0f;
  return (s32) (((f32) baseValue) + (((f32) ((CmmFishingRecord *)record)->span) * scale));
}

/* The retail range guard tests the MASKED index twice and lowers the upper
   bound through the $at assembler temp: `andi $v0,$s1,0xffff; bltz $v0;
   slti $at,$v0,6`. Spelling the bound as `> 5` rather than `>= 6` is what
   puts the slti result in $at (see docs/matching.md); re-masking in both
   halves of the || is what makes bltz test the masked value. Same shape as
   FUN_00246E90. */
// Date table run effect: runs the effect recorded in roll entry value (D_008814EC) through datEntryDrawGatedByFlag39.
// FUN_00249A60
void cmmDateTableRunEffect(s32 entryId) {
    u8 *table = (u8 *)D_008814EC[0];
    s32 off;
    s16 v;
    s32 a;

    if (((s32)(entryId & 0xFFFF) < 0) || ((entryId & 0xFFFF) > 5)) {
        kAssertFail(D_006359D0, 0x16B);
    }
    off = (u16)entryId * 14;
    v = ((CmmFishingRecord *)(off + (u32)table + 8))->effect;
    a = (s16)(v >> 8);
    datEntryDrawGatedByFlag39(a, (s16)((((v >> 1) & 0xFF) << 1) | (v & 1)), a, 0);
}
