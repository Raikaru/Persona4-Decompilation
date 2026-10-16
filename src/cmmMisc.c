/* Original translation unit cmmMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"

extern u32 RpRandom(void);


extern void func_00440b68(const char *fmt, const char *file, s32 line);
extern void *func_00454a60(const char *path, s32 flags);
extern void H_Cdvd_ReadSync(void *handle);
extern u8 *func_00455ea0(u8 *handle, s32 index, s32 *out);
extern void kAssertFail(void *file, s32 line);
extern void func_0046d700(const char *file, s32 line, char *fmt, s32 value);
extern s32 datGetDateIndex(void);
extern u32 datGetFlag(s32 flag);
extern void func_00106390(s32 id, s32 flag);
extern u32 func_001064f0(s32 idx);
extern s32 func_00106550(s32 id, s32 value);
extern s32 func_00106600(s16 idx);
extern s32 cmmCommunityTestMarked(s32 idx);
extern s32 cmmCommunityTestReversed(s32 idx);
extern void cmmCommunitySetReversed(s32 idx);
extern s32 cmmCommunityTestBroken(s32 idx);
extern s32 cmmCommunityCanRankUp(s32 idx);
extern s32 cmmCommunityFindRecord(s32 idx);
extern s32 calGetWeekdayOfDay(s32 a);
extern s32 calIsCurrentMonthDay(s32 a, s32 b, s32 c);
extern s32 calIsDayInRange(s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 cmmCommunityCounterpart(s64 idx); /* lint: allow H011 -- measured: s64 parameter keeps the retail key move; see cmmCommunityCounterpart note at the call site */
extern s32 func_00107ac0(s32 idx);
extern s32 cmmCommunityTestRecordFlags(s32 idx, s32 arg1);
extern u16 cmmCommunityGetTableHead(void);
extern s32 datPersonaRosterSlotRank(s32 idx);
extern s64 cmmCommunityArcana(s32 idx);
extern s32 cmmCommunityHasRecord(u16 idx);
extern u8 datPersonaGetArcana(u16 idx);
extern s32 datPersonaRosterSlotId(s32 idx);
extern s32 datPersonaCountValidMembers(void);
extern void calSplitDayOfYear(s32 seed, s32 *month, s32 *day);
extern s32 calDayOfYearFromMonthDay(s32 a, s32 b);
extern s32 calHasDayEntry(s32 idx);
extern s32 cmmDateTableFindIndex();
extern u16 cmmCommunityCategory(s32 arg0);
extern s32 cmmReversedAtRank(s32 arg0);
extern void datEntryDrawGatedByFlag39(s32 a, s32 b, s32 c, s32 d);
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
    s32 sp3C;
    s32 i;
    void *handle;

    func_00440b68(&D_007636F0, D_006359D0, 0x3F);
    H_Cdvd_ReadSync(handle = func_00454a60(D_006359E0, 1));
    for (i = 0; i < 0x1C; i++) {
        D_00881480[i] = func_00455ea0(handle, i, &sp3C);
    }
}

// Kind record: returns the 100-byte kind record for index arg0 (table D_00881480), asserting the index is in range. Callers test its +4 flags and read its +8 sprite width base.
// FUN_002467B0
u8 *cmmKindRecord(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// Name record: returns the 64-byte name record for id arg0 (table D_00881484), asserting the id is in range. Callers read it as a display string or record.
// FUN_00246830
u8 *cmmNameRecord(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_00881484[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        kAssertFail(D_006359D0, 0x54);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// Text record: returns the 64-byte text record for id arg0 (table D_008814DC), asserting the id is in range. Callers read it as a display string.
// FUN_002468A0
u8 *cmmTextRecord(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814DC[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        kAssertFail(D_006359D0, 0x5C);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

/* MATCHED (wave 14): `#pragma opt_propagation off` (measured: nd 9 -> 2,
   forces the single-use D_0088149C load into $a1 before the mul chain) + a
   hoisted `s32 base` local + the cmmMiscAddOff inline helper (measured:
   nd 2 -> 1, fixes the `addu $v0,$v0,$a1` mul-first operand order). Retail
   loads the global into $a1 FIRST, then the x24 chain, then `addu $v0,$v0,$a1`. */
// Rank name record: 24-byte record from chunk 7 (D_0088149C) for rank index arg0.
// FUN_00246910
#pragma opt_propagation off
u8 *cmmRankNameRecord(s16 arg0) {
    s32 base = D_0088149C[0];
    s32 mul = (s16)arg0 * 24;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// Detail record: 20-byte record from chunk 8 (D_008814A0) for detail index arg0.
// FUN_00246940
/* MATCHED (wave 14): same recipe as cmmRankNameRecord — `#pragma opt_propagation
   off` (measured: nd 9 -> 1, forces the single-use D_008814A0 load into $a1
   before the x20 chain) + hoisted `s32 base` local + cmmMiscAddOff helper
   (fixes the `addu $v0,$v0,$a1` operand order). Final residual is a benign
   reloc-masked word. */
#pragma opt_propagation off
u8 *cmmDetailRecord(s16 arg0) {
    s32 base = D_008814A0[0];
    s32 mul = (s16)arg0 * 20;
    return (u8 *)(cmmMiscAddOff(mul, base) + 8);
}
#pragma opt_propagation on
// Aux table: returns the chunk 9 table header (D_008814A4) with no record stride. Callers pass it to func_002bc010.
// FUN_00246970
s32 cmmAuxTable(void) {
    return D_008814A4[0];
}

// Rank string: returns the address of the string for kind arg0 and level arg1 in chunk 10 (D_008814A8), with 65-byte kind and 13-byte level strides.
// FUN_00246980
s32 cmmRankStringAt(s16 arg0, s16 arg1) {
    s32 base = D_008814A8[0] + 8;

    if (arg0 >= 5) {
        kAssertFail(D_006359D0, 0xBC);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xBD, &D_007636F8, arg1);
    }
    return base + arg0 * 0x41 + (arg1 - 1) * 0xD;
}

/* MATCHED (wave 14): lever-3 static inline helper `cmmMiscAddOff(offset, base)`
   carrying the addu operand order through its parameters fixed the two
   transposed `addu` residuals (nd 4 -> 0). The `index` local + first helper
   call fixed the first addu; the second call `cmmMiscAddOff(arg1*2, mid)`
   fixed the second. Original residual was `addu $v0,$v1,$v0` vs retail
   `addu $v0,$v0,$v1` (fresh sll result in rs). */
// Rank threshold: returns the s16 threshold from chunk 11 (D_008814AC) for category arg0 at level arg1. g_data.c uses it for rank thresholds.
// FUN_00246A50
s32 cmmRankThreshold(s16 arg0, s16 arg1) {
    s32 base = D_008814AC[0] + 8;
    s32 index;
    s32 mid;

    if (arg0 >= 5) {
        kAssertFail(D_006359D0, 0xC8);
    }
    if ((arg1 <= 0) || (arg1 > 5)) {
        func_0046d700(D_006359D0, 0xC9, &D_007636F8, arg1);
    }
    index = arg0 * 8;
    mid = cmmMiscAddOff(index, base);
    return *(s16 *)(cmmMiscAddOff(arg1 * 2, mid) - 2);
}
// Label record: 64-byte label record from chunk 12 (D_008814B0) for id arg0. cmmPersonaDetailShow copies it as a display string.
// FUN_00246B10
u8 *cmmLabelRecord(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814B0[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        kAssertFail(D_006359D0, 0xD1);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// Earn-scale table: returns the chunk 14 header (D_008814B8) at its record area. cmmCommunity earn scaling reads its f32 multipliers and counts from it.
// FUN_00246B80
s32 cmmEarnScaleTable(void) {
    return D_008814B8[0] + 8;
}

// Entry value record: 24-byte record from chunk 15 (D_008814BC) for entry arg0. cmmCommunityEntryValue reads its value from this record.
// FUN_00246BA0
u8 *cmmEntryValueRecord(s32 arg0) {
    u8 *temp_16 = D_008814BC[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0xEE);
    }
    off = (u16)arg0 * 24;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// Slot name record: 64-byte name record from chunk 17 (D_008814C4) for community slot arg0. Read by the group-slot text in code1_0027.c.
// FUN_00246C20
u8 *cmmSlotNameRecord(u32 arg0) {
    u32 temp_16;
    u8 *temp_17;

    temp_17 = D_008814C4[0];
    temp_16 = arg0 & 0xFFFF;
    if (temp_16 >= *(u32 *)(temp_17 + 4)) {
        kAssertFail(D_006359D0, 0x104);
    }
    return (u8 *)((temp_16 << 6) + (u32)temp_17 + 8);
}

// Item description text record: 64-byte text record from chunk 21 (D_008814D4), or NULL when id arg0 is out of range. Read through the item record's text slots 0x12/0x22.
// FUN_00246C90
u8 *cmmItemDescRecordOrNull(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D4[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D4[0] + 8);
}

// Item info record: 72-byte item record from chunk 24 (D_008814E0) for id arg0. cmmItemInfoShow reads its name, value, and text fields.
// FUN_00246CD0
u8 *cmmItemInfoRecord(s32 arg0) {
    u8 *temp_16 = D_008814E0[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x13B);
    }
    off = (u16)arg0 * 72;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// Item extra text record: 64-byte text record from chunk 22 (D_008814D8), or NULL when id arg0 is out of range. Read through the item record's text slots 0x10/0x20.
// FUN_00246D50
u8 *cmmItemExtraRecordOrNull(u32 arg0) {
    if (arg0 >= *(u32 *)(D_008814D8[0] + 4)) {
        return NULL;
    }
    return (u8 *)((arg0 << 6) + (u32)D_008814D8[0] + 8);
}

// Persona record: 66-byte record from chunk 25 (D_008814E4) for id arg0. The persona row sits at +0x40.
// FUN_00246D90
u8 *cmmPersonaRecord(s32 arg0) {
    u8 *temp_16 = D_008814E4[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x15B);
    }
    off = (u16)arg0 * 66;
    return (u8 *)(off + (u32)temp_16 + 8);
}

// Month profile: 72-byte month profile from chunk 26 (D_008814E8) for index arg0, offset by -0x40 (see CmmMonthProfile in cmmScript.c).
// FUN_00246E10
s32 cmmMonthProfileRecord(s32 arg0) {
    s32 temp_16;
    s32 temp_2;
    s32 off;

    temp_16 = D_008814E8[0];
    temp_2 = arg0 & 0xFFFF;
    if ((temp_2 <= 0) || (temp_2 > 0xC)) {
        kAssertFail(D_006359D0, 0x163);
    }
    off = (u16)arg0 * 72;
    return off + (u32)temp_16 - 0x40;
}

// Fishing entry: 14-byte fishing record from chunk 27 (D_008814EC) for index arg0, asserting the index is at most 5.
// FUN_00246E90
u8 *cmmFishingEntryRecord(s32 arg0) {
    u8 *temp_16 = (u8 *)D_008814EC[0];
    s32 off;

    if (((s32)(arg0 & 0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)) {
        kAssertFail(D_006359D0, 0x16B);
    }
    off = (u16)arg0 * 14;
    return (u8 *)(off + (u32)temp_16 + 8);
}
// Condition check: scans the 8-byte condition table (chunk 13, D_008814B4) and returns 1 when an entry for id arg0 is met. Kind 0 tests calIsCurrentMonthDay, kind 1 tests calGetWeekdayOfDay.
// FUN_00246F10
s32 cmmConditionMet(s32 arg0) {
    u16 temp_2;
    u16 temp_3;
    u8 *var_19 = D_008814B4[0] + 8;
    s32 temp_17 = *(s32 *)(D_008814B4[0] + 4);
    s32 var_18 = 0;
    s32 a0 = arg0 & 0xFFFF;

    while (var_18 < temp_17) {
        temp_2 = *(u16 *)var_19;
        if (temp_2 == 0 || temp_2 == a0) {
            temp_3 = *(u16 *)(var_19 + 4);
            switch (temp_3) {
            case 0:
                if (calIsCurrentMonthDay((s16)datGetDateIndex(), var_19[6], var_19[7]) != 0) {
                    return 1;
                }
                break;
            case 1:
                if (*(u16 *)(var_19 + 6) == calGetWeekdayOfDay((s16)datGetDateIndex())) {
                    return 1;
                }
                break;
            }
        }
        var_19 += 8;
        var_18++;
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
    s32 temp_16;
    u32 *temp_17;
    u32 *temp_17_2;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 temp_18;

    for (var_19 = 1; var_19 < 0x1F; var_19++) {
        if (cmmCommunityCanRankUp(var_19 & 0xFFFF) != 0) {
            temp_18 = var_19 & 0xFFFF;
            if (temp_18 == 0) {
                kAssertFail(D_006359D0, 0x1B3);
            }
            if (datGetFlag(temp_18 + 0x5BF) != 0) {
                if ((temp_18 == 0xA) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 9) && (datGetFlag(0x34) == 0)) {
                    var_2 = 0;
                } else if ((temp_18 == 3) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 6) && (datGetFlag(0x615) == 0)) {
                    var_2 = 0;
                } else {
                    var_2 = 1;
                }
            } else {
                var_2 = 0;
            }
            if ((var_2 != 0) && (cmmCommunityTestReversed(var_19 & 0xFFFF) == 0) && (cmmCommunityTestBroken(var_19 & 0xFFFF) == 0) && (cmmCommunityHasTierBit(var_19 & 0xFFFF, func_00107ac0(var_19 & 0xFFFF) & 0xFF) == 0)) {
                temp_17 = (u32 *)D_00881480[0];
                if ((u32)temp_18 >= temp_17[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                temp_16 = (var_19 & 0xFFFF) * 0x64;
                var_2_2 = (*(s32 *)((u32)temp_16 + (u32)temp_17 + 0xC) & 0x10) != 0;
                if (var_2_2 != 0) {
                    var_2_2 = cmmHasPendingUnlock() == 1;
                }
                if (var_2_2 == 0) {
                    temp_17_2 = (u32 *)D_00881480[0];
                    if ((u32)temp_18 >= temp_17_2[1]) {
                        kAssertFail(D_006359D0, 0x4C);
                    }
                    if ((*(s32 *)((u32)temp_16 + (u32)temp_17_2 + 0xC) & 2) && (cmmCommunityTestMarked(var_19 & 0xFFFF) == 0) && (cmmConditionMet(var_19 & 0xFFFF) == 0)) {
                        return var_19 & 0xFFFF;
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
    s32 temp_16;
    u32 *temp_17;
    u32 *temp_17_2;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 temp_18;

    for (var_19 = 1; var_19 < 0x1F; var_19++) {
        if (cmmCommunityCanRankUp(var_19 & 0xFFFF) != 0) {
            temp_18 = var_19 & 0xFFFF;
            if (temp_18 == 0) {
                kAssertFail(D_006359D0, 0x1B3);
            }
            if (datGetFlag(temp_18 + 0x5BF) != 0) {
                if ((temp_18 == 0xA) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 9) && (datGetFlag(0x34) == 0)) {
                    var_2 = 0;
                } else if ((temp_18 == 3) && ((func_00107ac0(var_19 & 0xFFFF) & 0xFFFF) == 6) && (datGetFlag(0x615) == 0)) {
                    var_2 = 0;
                } else {
                    var_2 = 1;
                }
            } else {
                var_2 = 0;
            }
            if ((var_2 != 0) && (cmmCommunityTestReversed(var_19 & 0xFFFF) == 0) && (cmmCommunityTestBroken(var_19 & 0xFFFF) == 0) && (cmmCommunityHasTierBit(var_19 & 0xFFFF, func_00107ac0(var_19 & 0xFFFF) & 0xFF) != 0)) {
                temp_17 = (u32 *)D_00881480[0];
                if ((u32)temp_18 >= temp_17[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                temp_16 = (var_19 & 0xFFFF) * 0x64;
                var_2_2 = (*(s32 *)((u32)temp_16 + (u32)temp_17 + 0xC) & 0x10) != 0;
                if (var_2_2 != 0) {
                    var_2_2 = cmmHasPendingUnlock() == 1;
                }
                if (var_2_2 == 0) {
                    temp_17_2 = (u32 *)D_00881480[0];
                    if ((u32)temp_18 >= temp_17_2[1]) {
                        kAssertFail(D_006359D0, 0x4C);
                    }
                    if ((*(s32 *)((u32)temp_16 + (u32)temp_17_2 + 0xC) & 2) && (cmmCommunityTestMarked(var_19 & 0xFFFF) == 0) && (cmmConditionMet(var_19 & 0xFFFF) == 0)) {
                        return var_19 & 0xFFFF;
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
   best=$s2/bestId=$s1/se=$s0/i=$s3; `target=(s16)arg0` sign-extends once
   before the loop; `i=1` is set before the empty-init for. */
// Top community of arcana: returns the community id whose arcana (cmmCommunityArcana) equals arg0 and whose rank is highest, or 0 when none matches. Event callers pass the class from the Fcl slot table.
// FUN_00247770
#pragma opt_common_subs off
s16 cmmTopCommunityOfArcana(s32 arg0) {
    s32 i;
    s32 largest;
    s32 result;
    s32 target;

    largest = 0;
    result = 0;
    i = 1;
    target = (s16)arg0;
    for (; i < 0x1F; i++) {
        if (target == (s8)cmmCommunityArcana(i & 0xFFFF)) {
            s32 v = func_00107ac0(i & 0xFFFF) & 0xFFFF;
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
   $s3=i/$s4=v; `target=(s8)func_00248760(arg0&0xFFFF)` sign-extends once. */
// Top persona of arcana: returns the roster persona whose arcana matches the arcana of community arg0 and whose rank is highest, or 0 when none matches.
// FUN_00247820
#pragma opt_common_subs off
s16 cmmTopPersonaOfArcana(s32 arg0) {
    s32 target;
    s32 i;
    s32 largest;
    s32 result;
    s32 v;
    s32 w;

    largest = 0;
    result = 0;
    target = (s8)cmmCommunityArcana(arg0 & 0xFFFF);
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
// Arcana candidate: for arcana arg0 and level threshold arg1, lists the personas at or below the threshold plus the nearest one above it, sorted by level. arg2 of -1 returns the count; otherwise the arg2-th entry, or 0.
// FUN_00247900
s32 cmmArcanaCandidateAt(s32 arg0, s32 arg1, s32 arg2) {
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

    target = (s8)cmmCommunityArcana(arg0);
    nextLevel = 0;
    nextId = 0;
    list = 0;
    count = 0;
    capacity = 0;
    if (arg2 != -1) {
        capacity = cmmArcanaCandidateAt(arg0, arg1, -1);
        chkmemAllocSiteTag(D_006359D0, 0x23A);
        list = (s32 *)D_008873F4[0](1, capacity * 4, 0x40000);
    }
    id = 1;
    threshold = arg1 & 0xFF;
    for (; id < 0x100; id++) {
        if (target == (datPersonaGetArcana(id & 0xFFFF) & 0xFF)) {
            blocked = 1;
            base = (s32)iGpffffb3d4;
            offset = id * 14;
            flags = *(u16 *)((u32)base + offset);
            if (!(flags & 0x10) && !(flags & 8)) {
                blocked = 0;
            }
            if (blocked == 0 && (!(flags & 0x40) || ((func_00107ac0(arg0) & 0xFFFF) == 10))) {
                level = *(u8 *)((u32)iGpffffb3d4 + offset + 3);
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
                if (*(u8 *)((u32)base + leftId * 14 + 3) > *(u8 *)((u32)base + rightId * 14 + 3)) {
                    *left = rightId;
                    *right = leftId;
                }
            }
        }
        if (arg2 < count) {
            count = list[arg2];
        } else {
            count = 0;
        }
        jtbl_008873EC[0](list);
    }
    return count;
}

// Roster has arcana: returns 1 when any valid roster persona has arcana arg0, else 0.
// FUN_00247C20
s32 cmmRosterHasArcana(s16 arg0) {
    s32 i = 0;
    s32 key = (s32)arg0;

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
// Community for arcana: maps arcana arg0 (2 to 8) to its community id, using the alternate id when the primary community has no record. Returns 0 when neither has one.
// FUN_00247CB0
u16 cmmCommunityForArcana(s64 arg0) {
    u16 var_16;
    s64 temp_2;

    var_16 = 0;
    temp_2 = (s64) (arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        var_16 = 7;
        break;
    case 3:
        var_16 = 0xB;
        if (cmmCommunityHasRecord(0xB) == 0) {
            var_16 = 0xC;
        }
        break;
    case 4:
        var_16 = 5;
        if (cmmCommunityHasRecord(5) == 0) {
            var_16 = 6;
        }
        break;
    case 5:
        var_16 = 3;
        if (cmmCommunityHasRecord(3) == 0) {
            var_16 = 4;
        }
        break;
    case 6:
        var_16 = 0xA;
        break;
    case 7:
        var_16 = 0xE;
        if (cmmCommunityHasRecord(0xE) == 0) {
            var_16 = 0xF;
        }
        break;
    case 8:
        var_16 = 0x18;
        break;
    }
    if (cmmCommunityHasRecord(var_16) == 0) {
        var_16 = 0;
    }
    return var_16;
}
/* Find the first enabled entry with the requested low-16 category.
   measured: use a cast for the bounds check and a mask for the address and
   category call, avoiding a cached masked counter across calls. Reuse the
   existing address-order helper. Exact 228B instructions plus 12B zero tail;
   retain the caller's s32 ABI and pass the index omitted by IDA explicitly. */
// Find community of category: returns the first community that has a record, flag 4 in its kind record, and category arg0 (cmmCommunityCategory). Returns 0 when none matches.
// FUN_00247DD0
s32 cmmFindCommunityOfCategory(s32 arg0)
{
    s32 i;
    u32 target;
    u8 *base;
    s32 offset;

    i = 0;
    target = (u16)arg0;
    while (i < 31) {
        base = D_00881480[0];
        if ((u32)(u16)i >= *(u32 *)(base + 4)) {
            kAssertFail(D_006359D0, 0x4C);
        }
        offset = (i & 0xFFFF) * 100;
        if (*(u32 *)(cmmMiscAddOff(offset, (s32)base) + 12) & 4) {
            if (target == (u16)cmmCommunityCategory(i & 0xFFFF) &&
                cmmCommunityHasRecord((u16)i) != 0) {
                return (u16)i;
            }
        }
        i++;
    }
    return 0;
}

// Date listed: returns 1 when the (month, day) pair for the date seed arg0 is in the D_00881498 pair list, else 0. The positive counterpart of cmmDateNotListed.
// FUN_00247EC0
s32 cmmDateListed(s32 seed) {
    u8 *p = D_00881498[0] + 8;
    s32 a, b;
    s32 a0, b0;
    s32 i;
    s32 count;

    calSplitDayOfYear(seed, &a, &b);
    count = *(s32 *)(D_00881498[0] + 4);
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
// Date not listed: returns 1 when the (month, day) pair for the date seed arg0 is absent from the D_00881498 pair list, else 0. Script callers use it as a date-availability gate.
// FUN_00247F60
#pragma opt_loop_invariants on
s32 cmmDateNotListed(s32 arg0) {
    u8 *p;
    s32 key1;
    s32 key2;
    s32 count;
    s32 i;
    s32 found;

    if (calHasDayEntry(arg0) == 0) {
        return 0;
    }
    p = D_00881498[0] + 8;
    calSplitDayOfYear(arg0, &key1, &key2);
    count = *(s32 *)(D_00881498[0] + 4);
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
// Next unlisted date: returns the next date seed after arg0 (below 0x16D) whose (month, day) pair is not in the D_00881498 list and whose date is valid. Returns 0 when there is none.
// FUN_00248040
s32 cmmNextUnlistedDate(s32 arg0) {
    s32 var_16 = arg0 + 1;
    s32 var_2;
    goto body;
incr:
    var_16 += 1;
    if (var_16 < 0x16D) {
        goto body;
    }
    return 0;
body:
    if (calHasDayEntry(var_16) == 0) {
        var_2 = 0;
    } else if (cmmDateListed(var_16) != 0) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return var_16;
    }
    goto incr;
}
/* measured: retail booleanizes the match chain (ret in $v0, fail block out
   of line) with 8 saved regs; mwcc b210 inlines the fail skips and balloons
   to 10 saved registers (best nd 30 without the ret booleanize, 82 with).
   Register-pressure + if-chain-layout floor. */
// Nth eligible community: returns the id of the arg0-th community in the D_00881490 table for (arg1, arg2) whose rank is inside its bounds, is not rank 10, is not flagged 3, and is not the table head. Returns 0 when there is no such entry.
// FUN_002480E0
u16 cmmNthEligibleCommunity(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_22;
    s32 temp_3;
    u8 *var_18;
    s32 var_17;
    s32 var_2;
    u16 temp_23;
    s32 var_16;

    var_18 = D_00881490[0] + 8;
    temp_22 = *(s32 *)(D_00881490[0] + 4);
    var_16 = 0;
    var_17 = 0;
    goto loop_15;
body_15:
    if ((var_18[0] == arg1) && (var_18[1] == arg2)) {
        temp_3 = (s32)(func_00107ac0(*(u16 *)(var_18 + 2)) & 0xFFFF);
        if ((temp_3 >= (s32)*(u16 *)(var_18 + 4)) &&
            (temp_3 <= (s32)*(u16 *)(var_18 + 6)) &&
            ((func_00107ac0(*(u16 *)(var_18 + 2)) & 0xFFFF) != 0xA) &&
            (cmmCommunityTestRecordFlags(*(u16 *)(var_18 + 2), 3) == 0) &&
            ((temp_23 = *(u16 *)(var_18 + 2)), (temp_23 != (cmmCommunityGetTableHead() & 0xFFFF)))) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
        if (var_2 != 0) {
            if (var_16 == arg0) {
                return *(u16 *)(var_18 + 2);
            }
            var_16 += 1;
            goto block_14;
        }
        goto block_14;
    }
block_14:
    var_18 += 8;
    var_17 += 1;
loop_15:
    if (var_17 < temp_22) {
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
    s32 temp_17;
    s32 var_20;
    s32 var_3;
    u32 temp_18;
    u32 *temp_16;
    u32 *temp_16_2;
    u8 *temp_2;

    var_20 = 1;
    while (var_20 < 0x1F) {
        if ((cmmCommunityHasRecord(var_20 & 0xFFFF) != 0) && (cmmCommunityTestRecordFlags(var_20 & 0xFFFF, 3) == 0)) {
            temp_2 = (u8 *)cmmCommunityFindRecord(var_20 & 0xFFFF);
            if (temp_2 == NULL) {
                var_3 = 0;
                goto block_13;
            }
            temp_16 = (u32 *)D_00881480[0];
            temp_18 = var_20 & 0xFFFF;
            if (temp_18 >= temp_16[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            temp_17 = (var_20 & 0xFFFF) * 0x64;
            if (*(u16 *)((u32)temp_17 + (u32)temp_16 + 0x12) != 0) {
                *(u16 *)(temp_2 + 0xA) = *(u16 *)(temp_2 + 0xA) + 1;
                temp_16_2 = (u32 *)D_00881480[0];
                if (temp_18 >= temp_16_2[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                if (*(u16 *)(temp_2 + 0xA) >= *(u16 *)((u32)temp_17 + (u32)temp_16_2 + 0x12)) {
                    var_3 = 1;
                } else {
                    goto block_12;
                }
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            var_3 = 0;
block_13:
            if (var_3 != 0) {
                cmmCommunitySetReversed(var_20 & 0xFFFF);
            }
        }
        var_20 += 1;
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
// Advance reverse progress: for each rank-10 community (other than arg0) with a record and no flag band 3, adds its paired value from the D_00881494 pair table to its progress counter (+0xA). When the progress reaches the kind record's threshold (+0x12), sets REVERSED through cmmCommunitySetReversed.
// FUN_002483C0
#pragma push
/* measured: opt_propagation off + saved regs $s6=temp_20, $s5=var_20 counter(1),
   $s4=temp_17, $s3=temp_18 mask, $s2=temp_19 masked arg, $s1=temp_2, $s0=temp_16;
   per-use u16 call_idx=(u16)var_20 conversions preserve andi immediates and remove $s7 constant. */
#pragma opt_propagation off
void cmmAdvanceReverseProgress(u16 arg0) {
    s32 temp_20;
    s32 var_20;
    s32 temp_17;
    u32 temp_19;
    u8 *temp_2;
    u32 *temp_16;
    u32 *temp_16_2;
    s32 var_3;
    u16 call_idx;

    var_20 = 1;
    temp_19 = arg0;
    while (var_20 < 0x1F) {
        if (temp_19 == var_20) {
            goto block_15;
        }
        if (cmmCommunityHasRecord((u16)var_20) == 0) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (((u16)func_00107ac0(call_idx)) != 0xA) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (cmmReversedAtRank(call_idx) == 0) {
            goto block_15;
        }
        call_idx = (u16)var_20;
        if (cmmCommunityTestRecordFlags(call_idx, 3) != 0) {
            goto block_15;
        }
        {
            u8 *p;
            s32 count;
            s32 i;
            s32 temp_18;

            temp_16 = (u32 *)D_00881494[0];
            p = (u8 *)temp_16 + 8;
            count = *(s32 *)(temp_16 + 1);
            i = 0;
            temp_18 = (u16)var_20;
            while (i < count) {
                if (*(u16 *)p == temp_18) {
                    if (*(u16 *)(p + 2) == temp_19) {
                        temp_17 = *(s32 *)(p + 4);
                        goto block_14;
                    }
                }
                p += 8;
                i += 1;
            }
            temp_17 = 0;
block_14:
            call_idx = (u16)var_20;
            temp_2 = (u8 *)cmmCommunityFindRecord(call_idx);
            if (temp_2 == NULL) {
                var_3 = 0;
                goto block_13;
            }
            temp_16 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            call_idx = (u16)var_20;
            temp_20 = call_idx * 0x64;
            if (*(u16 *)((u32)temp_20 + (u32)temp_16 + 0x12) == 0) {
                goto block_12;
            }
            *(u16 *)(temp_2 + 0xA) += temp_17 & 0xFFFF;
            temp_16_2 = (u32 *)D_00881480[0];
            if (temp_18 >= temp_16_2[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            if (*(u16 *)(temp_2 + 0xA) >= *(u16 *)((u32)temp_20 + (u32)temp_16_2 + 0x12)) {
                var_3 = 1;
            } else {
                goto block_12;
            }
            goto block_13;
block_12:
            var_3 = 0;
block_13:
            if (var_3 != 0) {
                call_idx = (u16)var_20;
                cmmCommunitySetReversed(call_idx);
            }
        }
block_15:
        var_20 += 1;
    }
}
/* measured: restore pragma state after func_002483c0. */
#pragma pop

/* measured: #pragma opt_loop_invariants on/off scoped around this function:
   retail hoists arg1&0xFFFF and var_4&0xFFFF into $s1/$s6 before the loop;
   without the pragma mwcc b210 re-masks inside the loop (nd 43 -> 2). s32
   arg1 (not u16) is also required so the ladder calls pass the raw register
   instead of a CSE'd mask. */
// Message-stream entry: returns the chunk 3 record (D_0088148C) for kind arg0 and community id arg1. When arg0 is 0 it derives the state code from cmmCommunityHasRecord and cmmCommunityCanRankUp (1, 2, 3, or 6). cmmMsgStreamStart stores the record as the stream source.
// FUN_002485E0
#pragma opt_loop_invariants on
u8 *cmmMsgStreamEntry(s32 arg0, s32 arg1) {
    s32 var_4 = arg0;
    s32 var_2;
    s32 temp_18;
    s32 var_20;
    s32 temp_4;
    u8 temp_16;
    u8 *var_19;

    if (!(var_4 & 0xFFFF)) {
        /* cmmCommunityHasRecord is narrow at the 00247270-family sites for retail's
           andi, but 002485e0 passes arg1 whole as s32, so override it here. */
        extern s32 cmmCommunityHasRecord(s32 idx);
        if (cmmCommunityHasRecord(arg1) == 0) {
            var_2 = 3;
        } else if (cmmCommunityCanRankUp(arg1) != 0) {
            if ((func_00107ac0(arg1) & 0xFFFF) == 9) {
                var_2 = 6;
            } else {
                var_2 = 2;
            }
        } else {
            var_2 = 1;
        }
        var_4 = var_2 & 0xFFFF;
    }
    var_19 = (u8 *)(D_0088148C[0] + 8);
    temp_18 = *(u32 *)(D_0088148C[0] + 4);
    var_20 = 0;
    while (var_20 < temp_18) {
        if ((*(u16 *)var_19 == (arg1 & 0xFFFF)) && (*(u8 *)(var_19 + 2) == (var_4 & 0xFFFF)) && ((temp_16 = *(u8 *)(var_19 + 3), temp_16 == 0) || ((temp_16 != 0) && (temp_16 == (func_00107ac0(arg1) & 0xFFFF)))) && ((temp_4 = *(u32 *)(var_19 + 0xC), temp_4 == 0) || (datGetFlag(temp_4) != 0))) {
            return var_19;
        }
        var_19 += 0x10;
        var_20 += 1;
    }
    return NULL;
}
#pragma opt_loop_invariants off
// Community arcana: returns the arcana byte at +0x10 of community arg0's kind record (chunk 0), asserting the id is in range.
// FUN_00248760
s64 cmmCommunityArcana(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    return *(s8 *)(off + (u32)temp_16 + 0x10);
}

// Community event value: returns the s8 value for slot arg1 (0 to 7) of community arg0's record array (stride 8, value at +0x28) when the slot's gate at +0x24 is zero or its datGetFlag is set. Returns 0 otherwise.
// FUN_002487E0
s8 cmmCommunityEventValue(s32 arg0, s8 arg1) {
    u8 *base;
    s32 off;
    s32 elem;
    s32 idx;
    s32 p;
    u8 *q;
    s32 v;

    if (arg1 >= 8) {
        kAssertFail(D_006359D0, 0x3A3);
    }
    base = D_00881480[0];
    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(base + 4)) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    elem = off + (s32)base + 8;
    if (elem != 0) {
        idx = arg1 * 8;
        p = idx + elem;
        q = (u8 *)(p + 0x28);
        if (*(u32 *)(p + 0x28) != 0) {
            v = *(u32 *)(p + 0x24);
            if ((v == 0) || (datGetFlag(v) != 0)) {
                return *(s8 *)q;
            }
        }
    }
    return 0;
}
// Community tier bit: returns 1 when bit (arg1 - 1) is set in the u16 at +0xC of community arg0's kind record. arg1 must be 1 to 9.
// FUN_002488E0
s32 cmmCommunityHasTierBit(s32 arg0, s32 arg1) {
    s32 temp_3;
    s32 var_4;
    u8 *temp_16 = D_00881480[0];
    u8 *temp_2;
    s32 off;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        var_4 = *(u16 *)(temp_2 + 0xC);
    } else {
        var_4 = 0;
    }
    temp_3 = arg1 & 0xFF;
    if ((temp_3 == 0) || (temp_3 >= 0xA)) {
        return 0;
    }
    return (var_4 & (1 << (temp_3 - 1))) != 0;
}
// Community category: returns the u16 at +0xE of community arg0's kind record (chunk 0), asserting the id is in range.
// FUN_002489C0
u16 cmmCommunityCategory(s32 arg0) {
    u8 *temp_16 = D_00881480[0];
    s32 off;
    u8 *temp_2;

    if ((u32)(arg0 & 0xFFFF) >= *(u32 *)(temp_16 + 4)) {
        kAssertFail(D_006359D0, 0x4C);
    }
    off = (u16)arg0 * 100;
    temp_2 = (u8 *)(off + (u32)temp_16 + 8);
    if (temp_2 != NULL) {
        return *(u16 *)(temp_2 + 0xE);
    }
    return 0;
}

/* measured: retail keeps arg0 raw in $s3, masks once into $s1 (temp_17)
   and re-masks into $v1 for the 100-multiply; mwcc b210 CSEs the mask into
   one register (best nd 37) in every spelling tried ((u16) vs & 0xFFFF vs
   temp_17 = arg0). Mask-CSE floor (same family as FUN_00247DD0). */
// Reversed at rank: returns 1 when community arg0 has a record, the REVERSED bit in its kind record (chunk 0), and a level byte at or above its rank from func_00107ac0; else 0.
// FUN_00248A60
/* measured: opt_common_subs off preserves the raw parameter call and per-use table masks. */
#pragma opt_common_subs off
s32 cmmReversedAtRank(s32 arg0) {
    s32 temp_16;
    u32 temp_17;
    u8 temp_16_2;
    u32 *temp_18;
    u32 *temp_18_2;

    /* Retail reuses raw arg0 for this unprototyped call; keep that a0 value. */
    extern s32 cmmCommunityHasRecord();
    if (cmmCommunityHasRecord() == 0) {
        return 0;
    }
    temp_18 = (u32 *)D_00881480[0];
    temp_17 = arg0 & 0xFFFF;
    if (temp_17 >= temp_18[1]) {
        kAssertFail(D_006359D0, 0x4C);
    }
    temp_16 = (arg0 & 0xFFFF) * 0x64;
    if (*(s32 *)((u32)temp_16 + (u32)temp_18 + 0xC) & 1) {
        temp_18_2 = (u32 *)D_00881480[0];
        if (temp_17 >= temp_18_2[1]) {
            kAssertFail(D_006359D0, 0x4C);
        }
        temp_16_2 = *(u8 *)((u32)temp_16 + (u32)temp_18_2 + 0x11);
        if ((s32)temp_16_2 >= (func_00107ac0(arg0) & 0xFFFF)) {
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
    s32 temp_20;
    s32 temp_2;
    s32 var_18;
    s32 var_17;
    s32 var_16;
    s32 var_2;
    u32 temp_21;
    u8 temp_19_3;
    u32 *temp_19;
    u32 *temp_19_2;

    var_17 = -1;
    var_16 = 0;
    var_18 = 0;
    while (var_18 < 0x1F) {
        if (cmmCommunityHasRecord(var_18 & 0xFFFF) == 0) {
            var_2 = 0;
        } else {
            temp_19 = (u32 *)D_00881480[0];
            temp_21 = var_18 & 0xFFFF;
            if (temp_21 >= temp_19[1]) {
                kAssertFail(D_006359D0, 0x4C);
            }
            temp_20 = (var_18 & 0xFFFF) * 0x64;
            if (*(s32 *)((u32)temp_20 + (u32)temp_19 + 0xC) & 1) {
                temp_19_2 = (u32 *)D_00881480[0];
                if (temp_21 >= temp_19_2[1]) {
                    kAssertFail(D_006359D0, 0x4C);
                }
                temp_19_3 = *(u8 *)((u32)temp_20 + (u32)temp_19_2 + 0x11);
                if ((s32)temp_19_3 >= (func_00107ac0(var_18 & 0xFFFF) & 0xFFFF)) {
                    var_2 = 1;
                } else {
                    goto block_10;
                }
            } else {
block_10:
                var_2 = 0;
            }
        }
        if (var_2 != 0) {
            temp_2 = func_00107ac0(var_18 & 0xFFFF) & 0xFFFF;
            if (var_17 < temp_2) {
                var_17 = temp_2;
                var_16 = var_18;
            }
        }
        var_18 += 1;
    }
    return var_16 & 0xFFFF;
}
/* measured: opt_common_subs on restores the file baseline after func_00248b80. */
#pragma opt_common_subs on

/* measured: retail hoists the 0xFFFF0000 mask constant into $v1 before the
   loop and keeps the loop count in $t0; without #pragma opt_loop_invariants
   mwcc b210 rematerializes lui per iteration (nd 16). Declarations must be
   count/var_10/var_9/temp_7 order for the $t0/$t1/$t2 allocation. */
// Table lookup value: scans the 12-byte entries at D_008814C0 for the key (arg0 high half, arg1 low half, arg2 at +4) and returns the value at +8, or -1.
// FUN_00248D00
#pragma opt_loop_invariants on
s32 cmmTableLookupValue(s32 arg0, s32 arg1, s32 arg2) {
    s32 count;
    u8 *var_10;
    s32 var_9;
    s32 temp_7;

    var_10 = D_008814C0[0] + 8;
    count = *(s32 *)(D_008814C0[0] + 4);
    var_9 = 0;
    while (var_9 < count) {
        temp_7 = *(s32 *)var_10;
        if ((((u32)(temp_7 & 0xFFFF0000) >> 0x10) == arg0) && ((temp_7 & 0xFFFF) == arg1) && (*(u16 *)(var_10 + 4) == arg2)) {
            return *(s32 *)(var_10 + 8);
        }
        var_10 += 0xC;
        var_9 += 1;
    }
    return -1;
}
#pragma opt_loop_invariants off

/* measured: widening the declaration of cmmCommunityCounterpart to s64 is correct:
   the callee truncates internally without sign-extending on entry. This lets
   the caller pass the already-masked key in $s1, reproducing the retail move
   and the complete -0x40 frame/s0-s2 prologue. With propagation disabled,
   this body is MATCH at nd 0 (object 148B/window 160B). */
// Resolve counterpart: returns the counterpart of community arg0 when arg0 has no record and its counterpart does; otherwise returns arg0.
// FUN_00248D80
/* measured: opt_propagation off preserves retail's raw/key lifetimes. */
#pragma opt_propagation off
s64 cmmResolveCounterpart(s64 arg0)
{
    s64 raw;
    s64 key;
    s64 raw_low;

    raw = arg0;
    key = raw & 0xFFFF;
    if (cmmCommunityHasRecord(key) == 0) {
        raw_low = (s16)raw;
        key = (s16)cmmCommunityCounterpart(key);
        if ((raw_low != key) && (cmmCommunityHasRecord((u16)key) != 0)) {
            return key;
        }
    }
    return raw;
}
/* measured: close the scoped propagation probe explicitly. */
#pragma opt_propagation on



// Table lookup flagged: scans the 12-byte entries at D_008814C8 for the key (arg0 high half, arg1 low half, arg2 or 0xFFFF) and returns the u16 at +0xA when its 0x8000 bit is set. Returns -1 otherwise.
// FUN_00248E20
s32 cmmTableLookupFlagged(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *var_18;
    s32 var_17;
    u16 temp_2;

    var_18 = D_008814C8[0] + 8;
    temp_16 = *(s32 *)(D_008814C8[0] + 4);
    var_17 = 0;
    while (var_17 < temp_16) {
        temp_4 = *(s32 *)var_18;
        if (temp_4 == 0 || datGetFlag(temp_4) != 0) {
            temp_3 = *(s32 *)(var_18 + 4);
            if (((u32)(temp_3 & 0xFFFF0000) >> 0x10) == arg0 && (temp_3 & 0xFFFF) == arg1 && (*(u16 *)(var_18 + 8) == 0xFFFF || *(u16 *)(var_18 + 8) == arg2)) {
                temp_2 = *(u16 *)(var_18 + 0xA);
                if (temp_2 & 0x8000) {
                    return temp_2;
                }
            }
        }
        var_18 += 0xC;
        var_17++;
    }
    return -1;
}
// FUN_00248F20
s32 func_00248f20(s32 arg0, s32 arg1) {
    u8 *temp_19 = (u8 *)(D_008814CC[0] + 8);
    s16 temp_17 = (s16)arg0;
    s32 temp_16;

    if (temp_17 >= 5) {
        kAssertFail(D_006359D0, 0x11B);
    }
    temp_16 = temp_17 * 8;
    if (arg1 <= *(s16 *)(temp_19 + temp_16)) {
        return 0;
    }
    temp_19 = (u8 *)(D_008814CC[0] + 8);
    if (temp_17 >= 5) {
        kAssertFail(D_006359D0, 0x11B);
    }
    if (arg1 <= *(s16 *)(temp_16 + (u32)temp_19 + 2)) {
        return 1;
    }
    return 2;
}

// Date table find index: returns the index of the ordinary record whose month and day (calSplitDayOfYear of the seed) match, or -1 when none does.
// FUN_00249010
s32 cmmDateTableFindIndex(s32 seed) {
    u8 *base = D_008814D0[0];
    u8 *p = base + 8;
    s32 count = *(s32 *)(base + 4);
    s32 a, b;
    s32 a0, b0;
    s32 i;

    calSplitDayOfYear(seed, &a, &b);
    i = 0;
    a0 = a;
    b0 = b;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
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
    s32 sp4C;
    s32 sp48;
    u8 *temp_17;
    u8 *p;
    s32 count;
    s32 a0;
    s32 b0;
    s32 i;
    s32 k;

    temp_17 = D_008814D0[0] + 8;
    p = temp_17;
    count = *(s32 *)(D_008814D0[0] + 4);
    calSplitDayOfYear(seed, &sp4C, &sp48);
    i = 0;
    a0 = sp4C;
    b0 = sp48;
    while (i < count) {
        if ((p[0] == a0) && (p[1] == b0)) {
            k = i;
            goto found;
        }
        p += 0x24;
        i++;
    }
    k = -1;
found:
    if (k != -1) {
        return temp_17 + k * 0x24;
    }
    return NULL;
}

// Date table find special record: returns the special record (slot from func_001064F0 at 0x6D) when flag 0xA61 is set and arg0 has reached its threshold, else NULL.
// FUN_00249180
u8 *cmmDateTableFindSpecialRecord(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    u8 *temp_17 = D_008814D0[0] + 8;

    calSplitDayOfYear(arg0, &sp3C, &sp38);
    if (datGetFlag(0xA61) != 0) {
        temp_17 += func_001064f0(0x6D) * 0x24;
        if (arg0 >= calDayOfYearFromMonthDay(temp_17[2], temp_17[3])) {
            return temp_17;
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
// Date table has special record: returns 1 when the special record for date arg0 is unlocked (flag 0xA61 and its threshold), else 0.
// FUN_002492B0
s32 cmmDateTableHasSpecialRecord(u32 arg0) {
    s32 sp3C;
    s32 sp38;
    u8 *p;
    u8 *t;

    p = D_008814D0[0] + 8;
    calSplitDayOfYear(arg0, &sp3C, &sp38);
    if (datGetFlag(0xA61) == 0) {
        goto null_p;
    }
    p += func_001064f0(0x6D) * 0x24;
    if (arg0 < calDayOfYearFromMonthDay(p[2], p[3])) {
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
// Date table read column: returns the 32-bit value at +12 of column arg2 (0 or 1) of the record selected for date arg1; special selects the special record, otherwise the ordinary record. Returns 0 when no record is selected.
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
        record += func_001064f0(0x6D) * 36;
        if ((u32)date < calDayOfYearFromMonthDay(record[2], record[3])) goto null_record;
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
    return *(s32 *)(cmmMiscAddOff(column * 16, (s32)selected) + 12);
}
/* Unsigned address addition preserves the retail operand order without
   changing the signed counter-delta arithmetic. */
static inline u32 cmmMiscAddAddress(u32 offset, u32 base)
{
    return offset + base;
}

// Date table apply column: selects the record for date (special record when flag 0xA61 allows it), then applies the column's two counter deltas clamped at 99 through func_00106620; asserts column is 0 or 1.
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
    record = base + func_001064f0(0x6D) * 36;
    if ((u32)date < (u32)calDayOfYearFromMonthDay(record[2], record[3])) goto null_record;
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
        value = func_00106600((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, *(s16 *)(cmmMiscAddAddress((u32)offset, (u32)selected) + 6));
        if (value > 99) value = 99;
        func_00106620((s32)*(s16 *)key, value & 0xFF);
    }
    key = (u16 *)(cmmMiscAddAddress((u32)offset, (u32)selected) + 8);
    id = *key;
    if (id != 0) {
        offset = (u32)column << 4;
        value = func_00106600((s16)id) & 0xFF;
        value = cmmMiscAddOff(value, *(s16 *)(cmmMiscAddOff(offset, (s32)selected) + 10));
        if (value > 99) value = 99;
        func_00106620((s32)*(s16 *)key, value & 0xFF);
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
   stops b210 forwarding `v = arg0` so the zero test reads the saved $s1 copy the
   way retail does, instead of testing $a0 directly.

   Residual: the two parameter saves are emitted in register order ($s0 then $s1)
   where retail emits them in parameter order (arg0 to $s1 first), and one
   commutative `addu` has its operands transposed. Measured and rejected:
   `arg1 + func_001064f0(0x57)`, seeding `n = arg1` at the top, seeding it just
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
// Date table add count: selects counter slot arg0 (0 = the next free slot), adds arg1 through cmmAddCountFirst, and at 4 completes the slot by setting flag 0x9AF+slot and clearing the counter.
// FUN_00249670
/* measured: opt_propagation off is required for the parked nd4 body. */
#pragma opt_propagation off
s32 cmmDateTableAddCount(s32 arg0, s32 arg1)
{
    s32 n;

    if (arg0 == 0) {
        arg0 = func_001064f0(0x58);
        if (arg0 == 0) {
            kAssertFail(D_006359D0, 0x4C8);
        }
    }
    func_00106550(0x58, arg0);
    if (!(func_00106600((s16)(arg0 + 0x4EA)) & 0xFF)) {
        kAssertFail(D_006359D0, 0x4CC);
    }
    n = cmmAddCountFirst(func_001064f0(0x57), arg1);
    if (n >= 4) {
        n = 0;
        func_00106390(arg0 + 0x9AF, 1);
        func_00106550(0x58, 0);
    }
    func_00106550(0x57, n);
    return n;
}
/* measured: opt_propagation scope closes at the file baseline. */
#pragma opt_propagation on
// Date table find nth match: counts the 20 records of D_008814E0 whose date matches arg0 (0 = any) and whose status matches arg1 (0-3); returns the 1-based index of the record at count arg2, or 0 when none.
// FUN_00249770
s32 cmmDateTableFindNthMatch(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_16;
    s32 var_20;
    s32 off;
    u8 *temp_20;
    u8 *p;
    s32 var_21;

    var_21 = 0;
    var_16 = 0;
    while (var_16 < 0x14) {
        temp_20 = D_008814E0[0];
        if ((u32)((var_16 + 1) & 0xFFFF) >= *(u32 *)(temp_20 + 4)) {
            kAssertFail(D_006359D0, 0x13B);
        }
        off = (u16)(var_16 + 1) * 72;
        p = (u8 *)(off + (u32)temp_20 + 8);
        var_20 = 0;
        if (arg0 == 0 || arg0 == *(s32 *)p) {
            var_20 += 1;
        }
        switch (arg1) {
        case 0:
            if (datGetFlag(var_16 + 0x9B0) != 0) {
                var_20 += 1;
            }
            break;
        case 1:
            if (((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) && (datGetFlag(var_16 + 0x9B0) == 0)) {
                var_20 += 1;
            }
            break;
        case 2:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) > 0) {
                var_20 += 1;
            }
            break;
        case 3:
            if ((func_00106600((s16)(var_16 + 0x4EB)) & 0xFF) == 0) {
                var_20 += 1;
            }
            break;
        }
        if (var_20 == 2) {
            if (var_21 == arg2) {
                return var_16 + 1;
            }
            var_21 += 1;
        }
        var_16++;
    }
    return 0;
}

/* measured: the retail range guard is now byte-exact -- `((s32)(arg0 &
   0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)` reproduces `andi; bltz; slti $at,6`
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
  s16 base_value;
  unsigned int random_value;
  u32 bits;
  f32 random_float;
  f32 scale;
  if ((((s32) (index & 0xFFFF)) < 0) || ((index & 0xFFFF) > 5))
  {
    kAssertFail(D_006359D0, 0x16B);
  }
  offset = ((u16) index) * 14;
  record = (u8 *) ((offset + ((u32) base)) + 8);
  base_value = *((s16 *) ((offset + ((u32) base)) + 8));
  random_value = RpRandom();
  if (random_value >= 0)
  {
    random_float = (f32) random_value;
  }
  else
  {
    bits = (u32) random_value;
    random_float = (f32) ((s32) ((bits >> 1) | (bits & 1)));
    random_float = random_float + random_float;
  }
  scale = random_float;
  scale = scale / 2147483648.0f;
  return (s32) (((f32) base_value) + (((f32) (*((s16 *) (record + 2)))) * scale));
}

/* The retail range guard tests the MASKED index twice and lowers the upper
   bound through the $at assembler temp: `andi $v0,$s1,0xffff; bltz $v0;
   slti $at,$v0,6`. Spelling the bound as `> 5` rather than `>= 6` is what
   puts the slti result in $at (see docs/matching.md); re-masking in both
   halves of the || is what makes bltz test the masked value. Same shape as
   FUN_00246E90. */
// Date table run effect: runs the effect recorded in roll entry arg0 (D_008814EC) through datEntryDrawGatedByFlag39.
// FUN_00249A60
void cmmDateTableRunEffect(s32 arg0) {
    u8 *temp_16 = (u8 *)D_008814EC[0];
    s32 off;
    s16 v;
    s32 a;

    if (((s32)(arg0 & 0xFFFF) < 0) || ((arg0 & 0xFFFF) > 5)) {
        kAssertFail(D_006359D0, 0x16B);
    }
    off = (u16)arg0 * 14;
    v = *(s16 *)(off + (u32)temp_16 + 0xE);
    a = (s16)(v >> 8);
    datEntryDrawGatedByFlag39(a, (s16)((((v >> 1) & 0xFF) << 1) | (v & 1)), a, 0);
}
