#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "g_data_internal.h"
#include "datUnit_internal.h"
#include "h_cdvd.h"
#include "datPersona_internal.h"
#include "rw_camera_internal.h"
#include "h_cdvd_request_internal.h"
#include "member_access.h"
#include "byte_address_internal.h"

/* Interior columns of the party slots retain the linker's own address anchors. */
typedef struct DatPartyCategories {
    s16 points[8];
    u8 pad10[0x78];
} DatPartyCategories;
typedef struct DatPartyTail {
    s16 value;
    u8 pad02[0x86];
} DatPartyTail;
typedef struct DatPartyEquipment {
    s16 items[3];
    u8 pad06[0x82];
} DatPartyEquipment;
/* Offsets are pinned by the flag, script-value and collection accessors. */
typedef struct DatSaveState {
    u8 pad00[0x3E2C];
    u32 flags[0xB0];
    u32 scriptValues[0x80];
    u8 pad42EC[0x64C];
    u32 collection[0x55];
} DatSaveState;
/* Save sections follow the fixed 0x34-byte image header. */
typedef struct DatSaveImage {
    u8 header[0x34];
    u8 sections[];
} DatSaveImage;

typedef struct DatScoreRecord {
    u8 pad00[6];
    u16 value;
    u8 pad08[8];
} DatScoreRecord;

typedef struct DatFieldState {
    s32 mode;
    s32 submode;
} DatFieldState;
extern u8 D_007973A0[];

extern s16 D_00797F88[];

extern u32 D_0079B68C[];

typedef struct DatGlobal {
    u8 padding[0x3c6c];
    u32 flags[0xB0];
    u8 padding2[0x204];
    s16 partyIds[1];
} DatGlobal;

extern DatGlobal D_00797560;

extern s16 D_00797B7A[];

extern u8 D_00797B7C[];

extern s32 D_00797B80[];

extern u16 D_0079B6A4[];

extern u8 D_0079B6A8[];

extern u8 D_0079757A[];

extern u32 D_005E2200[];

extern u8 D_0079BF00[];

#include "g_data_entry_internal.h"

extern GDataEntry* D_007242A0;
extern GDataEntry* iGpffffb1ac;

extern u8 D_007981CC[];

extern u8 D_0079BE2C[];

extern s32 datCalcIsSkillAvailable(s32 skillId);
extern s32 datCalcThresholdTrigger(u8* unit, s32 skillId);

extern void datPersonaSetRosterMode(s32 rosterMode);

extern void btlUnitRecordResetSaveTable(void* context);

extern s16 D_007973F4[];

extern u32 D_0079BCD8[];

extern u32 D_005E4480[];

extern s32 D_005DD6E0[];

extern s32 D_005DD6DC[];

extern s16 datRankForPoints(s16 category, s16 points);

extern s32 cmmRankThreshold(s16 value, s16 option);

extern void chkmemAllocSiteTag(void* file, s32 line);

extern void func_00440b68(char *fmt, ...);

extern u32 D_0079B1CC[];

extern char iGpffff9b18;

extern u8* iGpffffb3d4; /* gp -0x4C2C */

extern u16 (*iGpffffb3e4)[311]; /* gp -0x4C1C */

extern u8* iGpffffb3dc; /* gp -0x4C24 */

extern u8 D_005E4298[];

extern u8 D_005E42B0[];

extern void* (*jtbl_008873E8[])(u32 size, u32 align);

extern u32 D_00764298;

extern u16 cmmCommunityValueForArcana(u8 arcana);

extern void memcpy(void*, void*, u32);

extern s32 datCalcGetLevel(DatUnit* unit);
extern u32 datCalcGetHp(void* unit);
extern u32 datCalcGetSp(void* unit);
struct DatUnit;
extern u16 datCalcMaxHp(struct DatUnit* unit);
extern u16 datCalcMaxSp(struct DatUnit* unit);
extern u32 datCalcGetBadStatusNoDown(void* unit);
extern void datCalcInitUnit(void* unit, s16 id);
extern void datCalcSetBadStatus(DatUnit *unit, u32 badStatus);
extern u32 datCalcClearBadStatus(int unit, u32 badStatus);
extern u32 datCalcIsDead(int unit, s32 hpDelta);

extern u8 D_007973C4[];
extern u8 D_00796E50[];
extern u8 D_00796D4C[];
extern u8 D_00796D4E[];
extern DatPartyTail D_00796D84[];
extern DatPartyEquipment D_00796D8C[];
extern DatPartyCategories D_00796D74[];
extern u8 D_00796D54[];
extern s16 D_00797574[];
extern u8 D_007973CA[];
extern u16 D_007973CC[];
extern u16 D_007973CE[];
extern u32 D_00797400[];
extern u16 D_00797404[];
extern s8 D_007973D4[];
extern u32 D_0079B48C[];
extern u8* DAT_007644A8;

extern u32 D_005E4540[];

extern u32 D_005E4570[];

extern u8 D_00796D96[];

extern u8 D_005DD844[];

extern u8 D_005DD846[];

extern u8 D_00797410[];

extern u8 D_00797F8E[];

extern u8* DAT_007644D0;

extern u16 datCalcThresholdKind(u8* unusedUnit, s32 skillId);

extern f32 RwV3dNormalize(f32* a, f32* b);

extern u8* kwlnGetCamera(void);

extern u8* func_003e9700(s32 a0);

extern void* func_003e4320(void* out, const void* in, const void* matrix);

extern char D_005E45C0[];

extern u32 D_0079B67C[];

extern u32 iGpffffb19c; /* gp -0x4E64 */

extern char iGpffff9b10; /* gp -0x64F0 */

extern u8 iGpffff9bb0; /* gp -0x6450 */

extern void sprintf(void* dst, void* fmt, void* value, void* extra);

extern void H_Cdvd_ReadSync(u8* cdvd);

extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);

extern void datSetFlag(s32 flagId, s32 enabled);

extern u32 calGetWeekdayOfDay(s32 dateIndex);

extern s32 calHasDayEntry(s32 day);

extern void datSaveRestoreSection(s32 unusedVersion, u32 tag, u32 length, u8* data);

extern s32 datCalcSkillEffectFlags(s32 skillId, u8* source, u8* target, s32 options);

extern u32 datCalcSkillCost(u8* unit, s32 skillId);

extern s16 D_00797B84[];

extern u8 D_00797B86[];

typedef int (*code)();
extern code DAT_008873ec_abs[];

extern char D_005e4308[];
extern char D_005E4318[];
extern long kwlnTaskGetTaskByName(void* name);
extern void kwlnTaskDestroyWithHierarchy(long task);

extern void FUN_0046d730(const char* file, s32 line);

#define K_ASSERT(condition, line) do { if (!(condition)) { FUN_0046d730(__FILE__, (line)); } } while (0)

extern u8* DAT_007644c4;

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
    u16 skills[8];
    u8 naturalStats[5];
    u8 bonusStats[5];
} PersonaWork;

/* Entry lists use 32-byte and 16-byte records; the loader fixes up both pointers. */
typedef struct DatEntryBlock {
    u32 largeCount;
    u32 smallCount;
    union {
        void *largeRecords;
        u32 largeAddress;
    };
    union {
        void *smallRecords;
        u32 smallAddress;
    };
} DatEntryBlock;

/* Four-byte skill records are shared by the 0x46- and 0x26E-byte tables. */
typedef struct DatSkillRecord {
    u8 flags;
    s8 kind;
    u16 skill;
} DatSkillRecord;

typedef struct DatPersonaMetadata {
    u16 flags;
    u8 pad02[0xC];
} DatPersonaMetadata;

typedef struct DatPersonaFlags {
    u16 flags;
    u8 pad02[0x56];
} DatPersonaFlags;


extern u32 datPersonaGetExp(int persona);

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern void datBuildPersonaDisplayName(void);
extern u8 DAT_007973a0[0x24];


// Copies one entry from the loaded table, with its record lists, into a new heap block and returns
// it.
// FUN_00104900
void* datCloneEntryBlock(s32 entryIndex)
{
    u8* copy;
    u32 size;
    u32 entryOffset;
    DatEntryBlock* block;

    chkmemAllocSiteTag(D_005E4298, 0xB8);
    entryOffset = (entryIndex & 0xFFFF) * sizeof(DatEntryBlock);
    size = ((DatEntryBlock*)((u8*)iGpffffb1ac + entryOffset))->largeCount * 32 + 0x10 + ((DatEntryBlock*)((u8*)iGpffffb1ac + entryOffset))->smallCount * 16;
    copy = jtbl_008873E8[0](size, 0x40000);
    block = (DatEntryBlock*)copy;
    memcpy(copy, (u8*)iGpffffb1ac + entryOffset, 0x10);
    block->largeRecords = (void*)((u32)copy + 0x10);
    block->smallRecords = (void*)((u32)((DatEntryBlock*)copy)->largeRecords + block->largeCount * 32);
    memcpy(block->largeRecords, ((DatEntryBlock*)byteAddressAdd(entryOffset, (u8*)iGpffffb1ac))->largeRecords, block->largeCount * 32);
    memcpy(block->smallRecords, ((DatEntryBlock*)byteAddressAdd(entryOffset, (u8*)iGpffffb1ac))->smallRecords, block->smallCount * 16);
    return copy;
}

/* Assert a nonnull heap block before releasing it through the allocator table. */
// FUN_00104A00
void datFreeBlock(s32 block)
{
    K_ASSERT(block != 0, 0xC2);
    DAT_008873ec_abs[0](block);
}

// Reads the g_data entry table from disc and builds the in-memory copy.
// FUN_00104A60
/* Counts and addresses share the on-disc header; integer address members preserve arithmetic load order. */
void datLoadEntryTable(void)
{
    u8* obj;
    u8* src;
    u32 size;
    u8* dst;
    DatEntryBlock* sourceBlocks;

    func_00440b68(&iGpffff9b10, D_005E4298, 0xCD);
    obj = H_Cdvd_AcquireDirectory(D_005E42B0, 0);
    H_Cdvd_ReadSync(obj);
    src = ((HCdvdRequest*)obj)->data;
    sourceBlocks = (DatEntryBlock*)src;
    size = (sourceBlocks[0].largeCount + sourceBlocks[1].largeCount) * 32 + 0x20 + (sourceBlocks[0].smallCount + sourceBlocks[1].smallCount) * 16;
    chkmemAllocSiteTag(D_005E4298, 0xD2);
    iGpffffb1ac = (GDataEntry*)jtbl_008873E8[0](size, 0x40000);
    ((DatEntryBlock*)iGpffffb1ac)[0].largeCount = sourceBlocks[0].largeCount;
    ((DatEntryBlock*)iGpffffb1ac)[0].smallCount = sourceBlocks[0].smallCount;
    ((DatEntryBlock*)iGpffffb1ac)[0].largeRecords = (void*)((u32)iGpffffb1ac + 0x20);
    ((DatEntryBlock*)iGpffffb1ac)[0].smallAddress = ((DatEntryBlock*)iGpffffb1ac)[0].largeAddress + ((DatEntryBlock*)iGpffffb1ac)[0].largeCount * 32;
    dst = src + 0x20;
    memcpy(((DatEntryBlock*)iGpffffb1ac)[0].largeRecords, dst, ((DatEntryBlock*)iGpffffb1ac)[0].largeCount * 32);
    dst = dst + ((DatEntryBlock*)iGpffffb1ac)[0].largeCount * 32;
    memcpy(((DatEntryBlock*)iGpffffb1ac)[0].smallRecords, dst, ((DatEntryBlock*)iGpffffb1ac)[0].smallCount * 16);
    ((DatEntryBlock*)iGpffffb1ac)[1].largeCount = sourceBlocks[1].largeCount;
    ((DatEntryBlock*)iGpffffb1ac)[1].smallCount = sourceBlocks[1].smallCount;
    ((DatEntryBlock*)iGpffffb1ac)[1].largeAddress = ((DatEntryBlock*)iGpffffb1ac)[0].smallAddress + ((DatEntryBlock*)iGpffffb1ac)[0].smallCount * 16;
    ((DatEntryBlock*)iGpffffb1ac)[1].smallAddress = ((DatEntryBlock*)iGpffffb1ac)[1].largeAddress + ((DatEntryBlock*)iGpffffb1ac)[1].largeCount * 32;
    dst = dst + ((DatEntryBlock*)iGpffffb1ac)[0].smallCount * 16;
    memcpy(((DatEntryBlock*)iGpffffb1ac)[1].largeRecords, dst, ((DatEntryBlock*)iGpffffb1ac)[1].largeCount * 32);
    memcpy(((DatEntryBlock*)iGpffffb1ac)[1].smallRecords, dst + ((DatEntryBlock*)iGpffffb1ac)[1].largeCount * 32, ((DatEntryBlock*)iGpffffb1ac)[1].smallCount * 16);
    H_Cdvd_Destroy((struct HCdvd *)obj);
}

// Points the entry table at the built-in copy D_0079BF00; init calls it when the disc load fails.
// FUN_00104C50
void datEntryTableUseBuiltin(void)
{
    D_007242A0 = (GDataEntry*)((u32)&D_0079BF00[0] + 0x10);
}

/* Return the reader's level; normalize the selector's signed low word at entry. */
// FUN_00104C70
s32 datCalcGetLevelById(s32 unitId)
{
    s16 unit = (s16)unitId;

    if (unit == 1)
    {
        return datCalcGetLevel((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcGetLevel(&((DatPartySlot *)D_00796E50)[unit - 2].character.unit);
    }
}

/* Return the HP of the unit with the given id, using the protagonist's unit for id 1 and the party
 * slot unit otherwise. */
// FUN_00104CE0
u32 datCalcGetHpById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcGetHp((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcGetHp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
}

/* Read current SP from the protagonist record or the indexed party character. */
// FUN_00104D50
u32 datCalcGetSpById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcGetSp((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcGetSp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
}

/* Character selectors are signed halfwords. */
// FUN_00104DC0
u16 datCalcMaxHpById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcMaxHp((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcMaxHp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
}

/* Compute maximum SP for the protagonist record or the indexed party character. */
// FUN_00104E30
u16 datCalcMaxSpById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcMaxSp((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcMaxSp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
}

/* Read category points from the protagonist or the party record selected by unit id. */
// FUN_00104EA0
/* D_00796D74 is a linker interior alias addressing the category halfwords inside 0x88-byte party
 * slots. */
s16 datGetCategoryValueById(s16 unitId, s16 category)
{
    if (unitId == 1)
    {
        return D_007973F4[category];
    }
    else
    {
        return D_00796D74[unitId].points[category];
    }
}

// FUN_00104F10
s16 datCategoryRank(s16 category)
{
    return datRankForPoints(category, D_007973F4[category]);
}

/* Accumulate five category thresholds; return the first rank whose cumulative threshold exceeds points. */
// FUN_00104F50
s16 datRankForPoints(s16 category, s16 points)
{
    s32 sum = 0;
    s32 i = 0;
    s32 limit = points;

    while (i < 5)
    {
        sum = (s16)(sum + cmmRankThreshold(category, (s16)(i + 1)));
        if (sum > limit)
        {
            break;
        }
        i++;
    }
    if (i >= 5)
    {
        return 5;
    }
    else
    {
        return (s16)(i + 1);
    }
}

/* Signed-short wrapping is done explicitly in s32 temporaries; the greater-than comparison follows
 * retail. */
#pragma push
/* measured: retail keeps the short progress stages separate, which constant propagation would
 * merge. */
#pragma opt_propagation off
/* Compute a category's rank progress from its accumulated points and the rank thresholds, then
 * scale it as a percentage of scale. */
// FUN_00105010
s16 datCategoryRankProgress(s16 category, f32 scale)
{
    s32 remaining;
    s32 threshold;
    s32 level;
    s16 baseProgress;
    s16 partialProgress;
    s16 progress;

    remaining = D_007973F4[category];
    threshold = 0;
    level = 0;
    while (level < 5)
    {
        threshold = (s16)cmmRankThreshold(category, (s16)(level + 1));
        if (threshold > (s16)remaining)
        {
            break;
        }
        remaining = (s16)(remaining - threshold);
        level++;
    }
    if (level >= 5)
    {
        level = 4;
    }
    baseProgress = (s16)(100 * (level + 1));
    partialProgress = (s16)(s32)((f32)(100 * (s16)remaining) / (f32)threshold);
    progress = (s16)(baseProgress + partialProgress);
    return (s16)(s32)(100.0f * ((f32)(100 * progress) / scale));
}
#pragma pop

/* Store category points in the protagonist or indexed party character record. */
// FUN_001051A0
/* D_00796D74 is a linker interior alias addressing the category halfwords inside 0x88-byte party
 * slots. */
void datSetCategoryValueById(s16 unitId, s16 category, s16 points)
{
    if (unitId == 1)
    {
        D_007973F4[category] = points;
    }
    else
    {
        D_00796D74[unitId].points[category] = points;
    }
}

/* Read experience directly for the protagonist, otherwise require a persona record. */
// FUN_00105210
u32 datPersonaGetExpById(s16 unitId)
{
    if (unitId == 1)
    {
        return D_00797400[0];
    }
    else
    {
        PersonaWork* persona = (PersonaWork *)datPersonaGetRecord(unitId);

        K_ASSERT(persona != 0, 0x1B8);
        return datPersonaGetExp((int)persona);
    }
}

/* Read the selected protagonist roster persona id or the fixed party persona id. */
// FUN_00105290
u16 datGetPersonaIdByUnit(s16 unitId)
{
    if (unitId == 1)
    {
        s32 v = D_00797F88[0];

        K_ASSERT(v < 0xC, 0x1C3);
        return ((DatPersonaRecord*)((u8*)D_00797F8E + v * 0x30 - 2))->id;
    }
    else
    {
        return ((DatPersonaRecord*)((u8*)D_00796D96 + (s32)unitId * 0x88 - 2))->id;
    }
}

/* measured: loop invariants on hoists the gGlobalWork base out of both copy loops. Matches P3FES
 * func_00177410. */

#pragma opt_loop_invariants on
extern u8 DAT_00796de0[];
extern u8 DAT_00796e00[];
extern u8 DAT_00796e20[];
extern u8 DAT_007973a0[];
extern u8 DAT_007973b2[];
extern u32 DAT_00762ca0;


// FUN_00105330
/* Returns the active roster index and ignores its character selector. */
s32 datGetActiveRosterIndex(s32 character)
{
    return D_00797F88[0];
}


/* Apply the bad-status reader to the selected protagonist or party character. */
// FUN_00105340
u32 datCalcGetBadStatusNoDownById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcGetBadStatusNoDown((DatUnit *)D_007973C4);
    }
    else
    {
        return datCalcGetBadStatusNoDown(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
}

/* Both level-table lookups byte-mask the selected level after the branch join. */
// FUN_001053B0
u16 datGetLevelTableFirstValue(s16 unitId)
{
    s32 r;

    if (unitId == 1)
    {
        r = datCalcGetLevel((DatUnit *)D_007973C4);
    }
    else
    {
        r = datCalcGetLevel(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    return ((u16(*)[22])D_005DD844)[r & 0xFF][unitId * 2];
}

/* Looks up the second halfword of the unit-specific level-table pair using the current level. */
// FUN_00105460
u16 datGetLevelTableSecondValue(s16 unitId)
{
    s32 r;

    if (unitId == 1)
    {
        r = datCalcGetLevel((DatUnit *)D_007973C4);
    }
    else
    {
        r = datCalcGetLevel(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    return ((u16(*)[22])D_005DD846)[r & 0xFF][unitId * 2];
}

/* Resolve unit 1 to the protagonist record and units 2..10 to the 0x88-stride party slots. */
// FUN_00105510
u8* datUnitGetRecord(s16 unitId)
{
    if (unitId == 1)
    {
        return (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(unitId < 0xB, 0x234);
        return (u8 *)&((DatPartySlot *)D_00796E50)[unitId - 2].character;
    }
}

/* Initialize the selected character record with the same signed unit selector. */
// FUN_001055A0
void datCalcInitUnitById(s16 unitId)
{
    if (unitId == 1)
    {
        datCalcInitUnit((DatUnit *)D_007973C4, unitId);
    }
    else
    {
        datCalcInitUnit(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit, unitId);
    }
}
/* Test the selected character for death without applying an HP delta. */
// FUN_00105610
u32 datCalcIsDeadById(s16 unitId)
{
    if (unitId == 1)
    {
        return datCalcIsDead((int)(DatUnit *)D_007973C4, 0);
    }
    else
    {
        return datCalcIsDead((int)(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit), 0);
    }
}

/* Stores the byte at DatUnit.level for unit 1 and asserts for other units. */
// FUN_00105690
void datSetHeroLevel(s16 unitId, u8 value)
{
    if (unitId == 1)
    {
        D_007973CA[0] = value;
    }
    else
    {
        K_ASSERT(0, 0x260);
    }
}

// Stores a unit's current HP in the hero slot or its 0x88-byte party slot, the same slot
// datClampUnitHpSp writes.
// FUN_001056E0
void datSetUnitHp(s16 unitId, s16 hp)
{
    if (unitId == 1)
    {
        D_007973CC[0] = hp;
    }
    else
    {
        ((DatUnit*)((u8*)D_00796D4C + (s32)unitId * 0x88 - 8))->hp = hp;
    }
}

// Stores a unit's current SP in the hero slot or its 0x88-byte party slot, the same slot
// datClampUnitHpSp writes.
// FUN_00105730
void datSetUnitSp(s16 unitId, s16 sp)
{
    if (unitId == 1)
    {
        D_007973CE[0] = sp;
    }
    else
    {
        ((DatUnit*)((u8*)D_00796D4E + (s32)unitId * 0x88 - 10))->sp = sp;
    }
}

// Clamps a unit's current HP and SP to its max HP and max SP, writing the max back when the current
// value is larger.
// FUN_00105780
void datClampUnitHpSp(s16 unitId)
{
    u32 r;
    u16 v1;
    u16 v2;

    if (unitId == 1)
    {
        r = datCalcGetHp((DatUnit *)D_007973C4);
    }
    else
    {
        r = datCalcGetHp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    v1 = (u16)r;
    if (unitId == 1)
    {
        v2 = datCalcMaxHp((DatUnit *)D_007973C4);
    }
    else
    {
        v2 = datCalcMaxHp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (unitId == 1)
        {
            D_007973CC[0] = t;
        }
        else
        {
            ((DatUnit*)((u8*)D_00796D4C + (s32)unitId * 0x88 - 8))->hp = t;
        }
    }
    if (unitId == 1)
    {
        r = datCalcGetSp((DatUnit *)D_007973C4);
    }
    else
    {
        r = datCalcGetSp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    v1 = (u16)r;
    if (unitId == 1)
    {
        v2 = datCalcMaxSp((DatUnit *)D_007973C4);
    }
    else
    {
        v2 = datCalcMaxSp(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit);
    }
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (unitId == 1)
        {
            D_007973CE[0] = t;
        }
        else
        {
            ((DatUnit*)((u8*)D_00796D4E + (s32)unitId * 0x88 - 10))->sp = t;
        }
    }
}

/* Store protagonist experience; non-protagonist selectors trigger the retail assertion. */
// FUN_00105990
void datSetHeroExp(s16 unitId, u32 experience)
{
    if (unitId == 1)
    {
        D_00797400[0] = experience;
    }
    else
    {
        K_ASSERT(0, 0x297);
    }
}

/* Return how much experience the protagonist (unit 1) or the given persona still needs to reach the
 * next level. Return 0 if it is already at the level cap. */
// FUN_00105A50
s32 datGetExperienceToNextLevel(s16 unitId)
{
    extern void kAssertFail(const char *file, s32 line);
    s32 value;
    s32 value3;
    u8 j;
    u8 index;
    u8 i;
    u8 index2;
    if (unitId == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = (PersonaWork *)datPersonaGetRecord((u16)unitId);
        if (persona == 0)
            kAssertFail((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetExp((int)persona);
    }
    index = 0;
    i = 0;
    j = 0;
    goto first_test;
first_body:
    if (value < D_005DD6E0[j]) {
        index = i;
        goto first_done;
    }
    i++;
    j++;
first_test:
    if (j < 0x63)
        goto first_body;
    index = 0x63;
first_done:
    if ((index & 0xFF) == 0x63)
        return 0;
    if (unitId == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = (PersonaWork *)datPersonaGetRecord((u16)unitId);
        if (persona == 0)
            kAssertFail((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetExp((int)persona);
    }
    index2 = 0;
    i = 0;
    j = 0;
    goto second_test;
second_body:
    if (value < D_005DD6E0[j]) {
        index2 = i;
        goto second_done;
    }
    i++;
    j++;
second_test:
    if (j < 0x63)
        goto second_body;
    index2 = 0x63;
second_done:
    value3 = D_005DD6DC[((index2 & 0xFF) + 1) & 0xFF];
    if (unitId == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = (PersonaWork *)datPersonaGetRecord((u16)unitId);
        if (persona == 0)
            kAssertFail((const char *)D_005E4298, 0x1B8);
        value = datPersonaGetExp((int)persona);
    }
    return (s32)((u32)value3 - (u32)value);
}

/* Store the trailing character halfword, selecting protagonist or party storage. */
// FUN_00105C90
/* D_00796D84 is a linker interior alias pointing at the tail halfword inside each 0x88-byte party
 * slot. */
void datSetUnitRecordTailValue(s16 unitId, s16 value)
{
    if (unitId == 1)
    {
        D_00797404[0] = value;
    }
    else
    {
        D_00796D84[unitId].value = value;
    }
}

/* Forward the full incoming status mask to the selected unit. */
// FUN_00105CE0
void datCalcSetBadStatusById(s16 unitId, u32 badStatus)
{
    if (unitId == 1)
    {
        datCalcSetBadStatus((DatUnit *)D_007973C4, badStatus);
    }
    else
    {
        datCalcSetBadStatus(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit, badStatus);
    }
}

/* Clear the requested status mask in the selected character record. */
// FUN_00105D50
void datCalcClearBadStatusById(s16 unitId, u32 mask)
{
    if (unitId == 1)
    {
        datCalcClearBadStatus((int)(DatUnit *)D_007973C4, mask);
    }
    else
    {
        datCalcClearBadStatus((int)(&((DatPartySlot *)D_00796E50)[unitId - 2].character.unit), mask);
    }
}

/* Store an equipment ID in the selected character's equipment slot. */
// FUN_00105DC0
/* D_00796D8C is a linker interior alias pointing at the three equipment halfwords inside each
 * 0x88-byte party slot. */
void datSetEquippedItemByUnit(s16 unitId, s16 slotIndex, s16 itemId)
{
    if (unitId == 1)
    {
        D_00797574[slotIndex] = itemId;
    }
    else
    {
        D_00796D8C[unitId].items[slotIndex] = itemId;
    }
}

/* Check the five available tactics and store the selected character's tactic. */
// FUN_00105E30
void datSetUnitAiTactic(s16 unitId, s16 value)
{
    K_ASSERT(value < 5, 0x322);
    if (unitId == 1)
    {
        D_007973D4[0] = value;
    }
    else
    {
        ((DatUnit*)((u8*)D_00796D54 + (s32)unitId * 0x88 - 16))->aiTactic = value;
    }
}

// FUN_00105ED0
u32 datGetMoney(void)
{
    return D_0079B68C[0];
}


// FUN_00105EE0
s16 datGetPartyId(s32 idx)
{
    return D_00797560.partyIds[idx];
}


/* Return the signed tactic byte from the selected character record. */
// FUN_00105F00
s16 datGetUnitAiTactic(s16 unitId)
{
    if (unitId == 1)
    {
        return D_007973D4[0];
    }
    else
    {
        return ((DatUnit*)((u8*)D_00796D54 + (s32)unitId * 0x88 - 16))->aiTactic;
    }
}

/* Reads the persona arcana byte and resolves its community value. */
// FUN_00105F50
s8 datGetPersonaArcanaCommunityValue(u16 personaId)
{
    u8* table = DAT_007644c4;
    u16 id = personaId;

    return (s8)cmmCommunityValueForArcana(table[id * 0xE + 2]);
}

/* Store money after asserting it does not exceed the 9,999,999 cap. */
// FUN_00105FA0
void datSetMoney(u32 amount)
{
    if (amount > 0x98967F)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = amount;
}

// FUN_00106000
void datSetPartyId(s32 idx, s16 pcId)
{
    D_00797560.partyIds[idx] = pcId;
}


/* Add a signed amount to money and clamp the result to 0..9,999,999. */
// FUN_00106020
s32 datAddMoney(s32 delta)
{
    s32 value = delta + D_0079B68C[0];

    if (value > 0x98967F)
    {
        value = 0x98967F;
    }
    else if (value < 0)
    {
        value = 0;
    }

    if ((u32)value > 0x98967Fu)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = value;
    return value;
}
// FUN_001060B0
s16 datGetDateIndex(void)
{
    return D_00797B7A[0];
}


// FUN_001060C0
u8 datGetTimeSlot(void)
{
    return D_00797B7C[0];
}


// FUN_001060D0
s16 datGetPendingDateIndex(void)
{
    return D_00797B84[0];
}


// FUN_001060E0
u8 datGetPendingTimeSlot(void)
{
    return D_00797B86[0];
}


// FUN_001060F0
s32 datGetPendingFlag(void)
{
    return D_00797B80[0];
}

/* Store the date and refresh the weekday, calendar-entry and related day flags. */
// FUN_00106100
void datSetDateIndex(s16 date)
{
    u32 weekday;

    datSetFlag(0xAD0, 0);
    datSetFlag(0xAD7, 0);
    datSetFlag(0xAD1, 0);
    datSetFlag(0xAD2, 0);
    datSetFlag(0xAD3, 0);
    datSetFlag(0xAD4, 0);
    datSetFlag(0xAD5, 0);
    datSetFlag(0xAD6, 0);
    datSetFlag(0xAD8, 0);
    datSetFlag(0xAD9, 0);
    datSetFlag(0xADA, 0);
    datSetFlag(0xADB, 0);
    D_00797B7A[0] = date;
    weekday = calGetWeekdayOfDay(date);
    switch (weekday)
    {
    case 0:
        datSetFlag(0xAD7, 1);
        break;
    case 1:
        datSetFlag(0xAD1, 1);
        break;
    case 2:
        datSetFlag(0xAD2, 1);
        break;
    case 3:
        datSetFlag(0xAD3, 1);
        break;
    case 4:
        datSetFlag(0xAD4, 1);
        break;
    case 5:
        datSetFlag(0xAD5, 1);
        break;
    case 6:
        datSetFlag(0xAD6, 1);
        break;
    }
    if (calHasDayEntry(D_00797B7A[0]) != 0)
    {
        datSetFlag(0xAD0, 1);
    }
}

// FUN_001062F0
void datSetTimeSlot(u8 timeSlot)
{
    D_00797B7C[0] = timeSlot;
}

// FUN_00106300
void datSetPendingDateIndex(s16 date)
{
    D_00797B84[0] = date;
}

// FUN_00106310
void datSetPendingTimeSlot(u8 timeSlot)
{
    D_00797B86[0] = timeSlot;
}

// FUN_00106320
void datSetPendingFlag(u32 flags)
{
    D_00797B80[0] = flags;
}

/* Test one flag in the 0x1600-bit global bitmap using a word index and bit mask. */
// FUN_00106330
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (D_00797560.flags[idx] & (1U << mask)) != 0;
}


/* Set or clear one checked global flag; flag 0x1576 also emits a diagnostic. */
// FUN_00106390
void datSetFlag(s32 flagId, s32 enabled)
{
    s32 idx;
    s32 bit;

    if ((flagId < 0) || (flagId >= 0x1600))
    {
        FUN_0046d730(__FILE__, 0x471);
    }
    if (flagId == 0x1576)
    {
        func_00440b68(&iGpffff9b18);
    }
    idx = flagId / 32;
    bit = 1 << (flagId % 32);
    if (enabled != 0)
    {
        D_0079B1CC[idx] |= bit;
    }
    else
    {
        D_0079B1CC[idx] &= ~bit;
    }
}

/* Clear all 176 words of persistent game flags. */
// FUN_00106480
/* Linker interior alias: the flag words start at DAT_007973a0 + 0x3E2C. */
void datClearFlags(void)
{
    s32 i = 0;

    while (i < 0xB0)
    {
        ((DatSaveState *)DAT_007973a0)->flags[i] = 0;
        i = i + 1;
    }
}

// FUN_001064C0
void datPersonaClearRosterMode(void)
{
    datPersonaSetRosterMode(0);
}

/* Checks an index below 0x80 and reads its global script-value word. */
// FUN_001064F0
u32 datGetScriptValue(s32 index)
{
    K_ASSERT(index < 0x80, 0x4AE);
    return D_0079B48C[index];
}

/* Checks an index below 0x80 and writes its global script-value word. */
// FUN_00106550
void datSetScriptValue(s32 index, u32 value)
{
    K_ASSERT(index < 0x80, 0x4B9);
    D_0079B48C[index] = value;
}

/* Clear the first 127 script-value words, leaving the final word untouched. */
// FUN_001065C0
/* Retail clears only 127 of the script-value words. */
void datClearScriptValues(void)
{
    s32 i = 0;

    while (i < 0x7F)
    {
        ((DatSaveState *)DAT_007973a0)->scriptValues[i] = 0;
        i = i + 1;
    }
}

// Returns an item's stack count; datItemSetCount writes the same table.
// FUN_00106600
s32 datItemCount(s16 itemId)
{
    return D_0079757A[itemId];
}

// Sets an item's stack count, clamped to 99.
// FUN_00106620
/* Inventory and metadata queries share the signed halfword item ID. */
void datItemSetCount(s16 itemId, s32 count)
{
    s16 id;
    u8 *p;
    s32 value;
    s32 x;
    s32 bit;
    s32 idx;

    value = count & 0xFF;
    if (value > 0x63)
    {
        value = 0x63;
    }
    id = (s16)itemId;
    p = (u8 *)D_0079757A + id;
    *p = value;
    if (datEntryGetKind(itemId) == 4)
    {
        if (*p != 0)
        {
            x = id - 0x200;
            if ((x < 0) || (x >= 0x1600))
            {
                FUN_0046d730((const char *)D_005E4298, 0x471);
            }
            if (x == 0x1576)
            {
                func_00440b68(&iGpffff9b18);
            }
            x = (s16)itemId - 0x200;
            bit = 1 << (x % 32);
            idx = x / 32;
            D_0079B1CC[idx] |= bit;
        }
        else
        {
            s32 bit2;
            s32 idx2;

            x = id - 0x200;
            if ((x < 0) || (x >= 0x1600))
            {
                FUN_0046d730((const char *)D_005E4298, 0x471);
            }
            if (x == 0x1576)
            {
                func_00440b68(&iGpffff9b18);
            }
            x = (s16)itemId - 0x200;
            bit2 = 1 << (x % 32);
            idx2 = x / 32;
            D_0079B1CC[idx2] &= ~bit2;
        }
    }
}

// FUN_001067F0
u32 datGetItemNameId(s16 itemId)
{
    return D_005E2200[itemId];
}

// FUN_00106820
GDataEntry* datEntryAt(s16 itemId)
{
    return (GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68);
}

// FUN_00106850
/* Reads the first word of the 68-byte item entry. */
u32 datEntryGetKind(s16 itemId)
{
    return D_007242A0[(s16)itemId].kind;
}

// FUN_00106880
u32 datEntryGetFlags(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->flags;
}

// FUN_001068B0
u16 datEntryGetPrimaryValue(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->primaryValue;
}

// FUN_001068E0
u16 datEntryGetSecondaryValue(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->secondaryValue;
}

// FUN_00106910
u8 datEntryGetPropertyByte(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->property;
}

// FUN_00106940
u16 datEntryGetMiddleBandValue(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->middleBandValue;
}

// FUN_00106970
u16 datEntryGetLastBandValue(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->lastBandValue;
}

// Returns the skill ID an item grants; datCalcSkillCost and PTDatCalcHasSkill compare it with skill
// IDs.
// FUN_001069A0
u32 datItemGrantedSkill(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->grantedSkill;
}

// Returns the item value.
// FUN_001069D0
u16 datItemValue(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->value;
}

// Returns the accessory's damage percent, used by DCDamageAccessoryFraction.
// FUN_00106A00
u16 datItemAccessoryPercent(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->accessoryPercent;
}

// Returns the item's element, read by datCalcSkillElement and datCalcHitResult for the equipped
// item.
// FUN_00106A30
u16 datItemElement(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->element;
}

// Returns the category bitmask that y_list.c tests against its filter.
// FUN_00106A60
u32 datEntryCategoryMask(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->categoryMask;
}

// Returns the item's price; fclItemShopDiscountedPrice subtracts the discount from it.
// FUN_00106A90
u32 datItemPrice(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->price;
}

// Returns the calendar month an item becomes available, compared against fclCalendarMonth.
// FUN_00106AC0
s8 datItemAvailableMonth(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->availableMonth;
}

// Returns the calendar day an item becomes available, paired with datItemAvailableMonth.
// FUN_00106AF0
s8 datItemAvailableDay(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->availableDay;
}

// Returns the first moon-phase gate word: bits 8..19 are the phase key, the low byte is the second
// fclMoonPhaseAtLeast argument.
// FUN_00106B20
u32 datItemMoonGateFirst(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->firstMoonGate;
}

// Returns the second moon-phase gate word, laid out like datItemMoonGateFirst.
// FUN_00106B50
u32 datItemMoonGateSecond(s16 itemId)
{
    return ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->secondMoonGate;
}

/* Maps a signed item id (0x000..0x5FF) to its index within its 0x100-entry bank. */
// FUN_00106B80
s64 datItemBankOffset(s16 encodedItemId)
{
    s16 itemId;

    itemId = (s16)encodedItemId;
    if (itemId < 0x100) {
        return itemId;
    }
    if (itemId < 0x200) {
        return (s16)(itemId - 0x100);
    }
    if (itemId < 0x300) {
        return (s16)(itemId - 0x200);
    }
    if (itemId < 0x400) {
        return (s16)(itemId - 0x300);
    }
    if (itemId < 0x500) {
        return (s16)(itemId - 0x400);
    }
    return (s16)(itemId - 0x500);
}


// Matches P3FES comuTimerSequence. kwlnTaskGetWork is deliberately undeclared (implicit call, as in
// P3FES) because a typed prototype adds zero-extensions retail lacks.

/* measured: masking flags in a separate statement keeps retail's early categoryMask load. Tests bit
 * (flagIndex + 4) of a g_data entry's categoryMask; used by the equipment screen and new-game
 * script. */
// FUN_00106C30
s32 datEntryHasFlag(s16 itemId, s16 flagIndex)
{
    u32 flags;

    flags = ((GDataEntry*)((u8*)D_007242A0 + (s32)itemId * 68))->categoryMask;
    flags &= 1 << ((s32)flagIndex + 4);
    return flags != 0;
}
#pragma opt_propagation on

/* Classify item ids into the below-0x100, below-0x200 and remaining comparison bands. */
// FUN_00106C80
s32 datIdBand(s16 itemId)
{
    if (itemId < 0x100)
    {
        return 0;
    }
    if (itemId < 0x200)
    {
        return 1;
    }
    return 2;
}

/* Read an equipment slot from the protagonist or selected party character. */
// FUN_00106CD0
/* D_00796D8C is a linker interior alias pointing at the three equipment halfwords inside each
 * 0x88-byte party slot. */
s16 datGetEquippedItemByUnit(s16 unitId, s16 slotIndex)
{
    if (unitId == 1)
    {
        return D_00797574[slotIndex];
    }
    else
    {
        return D_00796D8C[unitId].items[slotIndex];
    }
}

/* Assign the selected character's equipment slot without validating the item ID. */
// FUN_00106D40
/* D_00796D8C is a linker interior alias pointing at the three equipment halfwords inside each
 * 0x88-byte party slot. */
void datAssignEquippedItem(s16 unitId, s16 slotIndex, s16 itemId)
{
    if (unitId == 1)
    {
        D_00797574[slotIndex] = itemId;
    }
    else
    {
        D_00796D8C[unitId].items[slotIndex] = itemId;
    }
}

// Destroy callback of the community task; frees the task's work block.
// FUN_00108CB0
void datFreeTaskWork(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork(unusedTask);
    DAT_008873ec_abs[0](work);
}


/* Destroy the named task hierarchy when the scheduler lookup succeeds. */
// FUN_00108D80
void datDestroyTaskByName(void)
{
  long handle;

  if ((handle = kwlnTaskGetTaskByName(D_005e4308)) == 0) {
    return;
  }
  kwlnTaskDestroyWithHierarchy(handle);
  return;
}


// FUN_001090F0
void datResetTotalBtl(void)
{
    *(u32*)&D_00797560 = 0;
}


/* Sums the value field of the 21 sixteen-byte score records and returns the total divided by 210;
 * the (f32)(u32) cast gives retail's unsigned-to-float conversion. */
// FUN_00109190
f32 datGetAverageRecordScore(void) {
    f32 sum;
    u8 *p;
    s32 i;

    sum = 0.0f;
    p = &D_007973A0[0x70];
    for (i = 0; i < 21; i++) {
        sum += (f32)(u32)((DatScoreRecord*)p)->value;
        p += 16;
    }
    return sum / 210.0f;
}


// FUN_00109390
u8 datPersonaGetLevel(int persona)
{
    return ((DatPersonaRecord*)persona)->level;
}


/* Resolve the unit's persona record before reading its level byte. */
// FUN_00109400
u8 datPersonaGetLevelByPcId(u16 pcId)
{
    PersonaWork* persona = (PersonaWork *)datPersonaGetRecord(pcId);
    return persona->level;
}


// Returns the persona's current exp; callers use it as the base for next-level and remaining-exp
// figures.
// FUN_00109430
u32 datPersonaGetExp(int persona)
{
    return (u32)((DatPersonaRecord*)persona)->exp;
}


// FUN_00109440
u32 datPersonaGetExpToNextLevel(PersonaWork* persona)
{
    return datPersonaGetExpForLevel(persona, (u16)(persona->level + 1));
}


// FUN_001094D0
u16 *datPersonaGetSkills(DatPersonaRecord *persona)
{
    return persona->skills;
}


/* Resolve the unit's persona record and return its eight-skill array. */
// FUN_001094E0
u16* datPersonaGetSkillsByPcId(u16 pcId)
{
    PersonaWork* persona = (PersonaWork *)datPersonaGetRecord(pcId);

    return persona->skills;
}


/* Add a signed byte delta to one bonus stat in the resolved persona record. */
// FUN_00109D80
void datPersonaAddToBonusStatByPcId(u16 pcId, u16 statId, s8 amount)
{
    PersonaWork* persona = (PersonaWork *)datPersonaGetRecord(pcId);

    persona->bonusStats[statId] += amount;
}


/* Reject level 99, otherwise compare experience against the next-level threshold. */
// FUN_0010C6F0
s32 datPersonaCanLevelUp(PersonaWork* persona)
{
    if (persona->level >= 99) {
        return 0;
    }
    return datPersonaGetExpForLevel(persona, persona->level + 1) <= persona->nextExp;
}


/* Append kind-one, unflagged skill records to the output skill list. */
static inline void datCollectValidSkills(u8* skillData, u16* skills,
                                         s32* validSkills, s32 skillLimit)
{
    s32 skillIdx;

    for (skillIdx = 0; skillIdx < skillLimit; skillIdx++)
    {
        if (((DatSkillRecord *)skillData)[skillIdx].flags == 0 &&
            ((DatSkillRecord *)skillData)[skillIdx].kind == 1)
        {
            skills[*validSkills] = ((DatSkillRecord*)skillData)[skillIdx].skill;
            (*validSkills)++;
        }
    }
}

/* Collect active kind-1 skills from the special 32-entry table or the ordinary 16-entry table. */
// FUN_0010D360
void datPersonaCollectSkills(u16 personaId, u16* skills, s32* skillCount)
{
    u8* skillData;
    s32 validSkills;

    validSkills = 0;
    if (personaId >= 0xc0 && personaId <= 0xd7)
    {
        skillData = (u8*)iGpffffb3e4 + (personaId - 0xc0) * 0x26e + 4;
        datCollectValidSkills(skillData, skills, &validSkills, 0x20);
    }
    else
    {
        skillData = (u8*)iGpffffb3dc + (u32)personaId * 0x46 + 6;
        datCollectValidSkills(skillData, skills, &validSkills, 0x10);
    }

    *skillCount = validSkills;
}

// FUN_0010D480
/* Retail no-op called during battle-unit setup; no state changes occur here. */
void datBattleUnitLoadCompleteNoop(void)
{
}

// FUN_0010D490
/* Copies two at-most-18-byte name parts and rebuilds the display-name buffers. */
void datSetHeroNameParts(u8* firstName, u8* lastName)
{
    s32 index;
    s8 value;

    FUN_0043f9c8(DAT_007973a0, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = ((s8*)firstName)[index];
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = ((s8*)lastName)[index];
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index + 0x12] = value;
    }

    datBuildPersonaDisplayName();
}
/* measured: invariant hoisting is needed only for datSetHeroNameParts and is switched back off
 * here. */
#pragma opt_loop_invariants off


/* Clear the name buffers, copy in the two stored name parts, and format them into the combined
 * display name string. */
// FUN_0010D560
void datBuildPersonaDisplayName(void)
{
    FUN_0043f9c8(DAT_00796de0, 0, 0x12);
    FUN_0043f9c8(DAT_00796e00, 0, 0x12);
    FUN_0043f9c8(DAT_00796e20, 0, 0x24);
    memcpy(DAT_00796de0, DAT_007973a0, 0x12);
    memcpy(DAT_00796e00, DAT_007973b2, 0x12);
    sprintf(DAT_00796e20, &DAT_00762ca0, DAT_00796e00, DAT_00796de0);
}

/* Return the rebuilt protagonist display name for unit 1, otherwise the static name-table entry. */
// FUN_0010D620
u32 datPersonaDisplayName(s16 unitId)
{
    if (unitId == 1)
    {
        return (u32)DAT_00796e20;
    }
    else
    {
        return D_005E4480[unitId];
    }
}

// Returns name part 0 for a persona id: id 1 is the hero's buffer, ids below 11 use the part-0
// table, others the display-name table.
// FUN_0010D660
u32 datPersonaNamePart0(s16 unitId)
{
    if (unitId == 1)
    {
        return (u32)DAT_00796de0;
    }
    if (unitId < 0xB)
    {
        return D_005E4540[unitId];
    }
    return D_005E4480[unitId];
}

// Returns name part 1 for a persona id, using the same lookup as datPersonaNamePart0 over the
// part-1 table.
// FUN_0010D6D0
u32 datPersonaNamePart1(s16 unitId)
{
    if (unitId == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (unitId < 0xB)
    {
        return D_005E4570[unitId];
    }
    return D_005E4480[unitId];
}

// Same body as datPersonaNamePart1, kept at its own address.
// FUN_0010D740
u32 datPersonaNamePart1Alt(s16 unitId)
{
    if (unitId == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (unitId < 0xB)
    {
        return D_005E4570[unitId];
    }
    return D_005E4480[unitId];
}

// FUN_0010D7B0
/* Retail no-op called from kernel initialization; no state changes occur here. */
void datKernelInitNoop(void)
{
}

extern u8 D_0079740C[];
extern u8 D_00797564[];
extern u8 D_00797B87[];
extern u8 D_00797F8C[];
extern u8 D_0079B690[];
extern u8 D_0079B698[];
extern u8 D_0079B69C[];
extern u8 D_0079B6A0[];
extern u8 D_0079B6D8[];
extern u8 D_0079BEF4[];
extern u8 D_007BBF00[];
extern s32 iGpffffb1b4;
extern s32 iGpffffb1b8;
extern u8 *FldStepTable(void);
extern s32 FldStepTableSize(void);

/* The metadata layout leaves one tail-padding byte, which retail includes in the character-wise
 * summary checksum. */
extern u8 *iGpffff9db0;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 FldStepIndex(void);
extern u32 datGetClearedWord(void);
extern u32 D_0079B3CC[];
extern char D_005E45A0[];
typedef struct DatSaveMetadata {
    s16 date;
    u16 period;
    u32 elapsed;
    u8 level;
    u8 difficulty;
    u8 cleared;
} DatSaveMetadata;
typedef struct DatSaveSummary {
    DatSaveMetadata metadata;
    s8 names[2][18];
    u8 mode;
    u8 submode;
    u16 checksum;
} DatSaveSummary;
typedef char DatSaveMetadataSize[(sizeof(DatSaveMetadata) == 12) ? 1 : -1];
typedef char DatSaveSummarySize[(sizeof(DatSaveSummary) == 52) ? 1 : -1];

#pragma push
/* measured: retail hoists loop invariants here; updating total directly also avoids the propagation
 * override. */
#pragma opt_loop_invariants on
// FUN_0010D7C0
u8 *datSaveBuildImage(s32 version, s32 *outSize, s32 compact)
{
    u8 checksum;
    s32 tag;
    s32 length;
    DatSaveSummary summary;
    u8 *buffer;
    u8 *records;
    u8 *cursor;
    u8 *unit;
    s32 total;
    u32 nameIndex;
    u32 surnameIndex;
    u32 unitIndex;
    u32 checksumIndex;
    u8 threshold;
    u8 level;
    u8 sum;
    u32 summaryIndex;
    u8 resultLevel;
    s32 experience;
    u8 *summaryBytes;

    *(s32 *)D_0079B698 = ((DatFieldState*)iGpffff9db0)->mode;
    *(s32 *)D_0079B69C = ((DatFieldState*)iGpffff9db0)->submode;
    *(s32 *)D_0079B6A0 = FldStepIndex();
    chkmemAllocSiteTag(D_005E4298, 0x721);
    buffer = D_008873F4[0](1, 0x2A000, 0x40000);
    tag = 0;
    total = 0;
    memcpy(buffer, &version, 4);
    summary.metadata.elapsed = iGpffffb19c;
    D_0079B67C[0] = iGpffffb19c;
    summary.metadata.date = D_00797B7A[0];
    summary.metadata.period = D_00797B7C[0];
    for (nameIndex = 0; nameIndex < 18; nameIndex++)
        summary.names[0][nameIndex] = ((s8 *)D_007973A0)[nameIndex];
    for (surnameIndex = 0; surnameIndex < 18; surnameIndex++)
        summary.names[1][surnameIndex] = *((s8 *)D_007973A0 + surnameIndex + 18);
    summary.mode = ((DatFieldState*)iGpffff9db0)->mode;
    summary.submode = ((DatFieldState*)iGpffff9db0)->submode;
    experience = D_00797400[0];
    level = 0;
    threshold = 0;
    goto level_test;
level_body:
    if (experience < D_005DD6E0[threshold]) {
        resultLevel = level;
        goto level_done;
    }
    level++;
    threshold++;
level_test:
    if (threshold < 99)
        goto level_body;
    resultLevel = 99;
level_done:
    summary.metadata.level = resultLevel;
    summary.metadata.cleared = datGetClearedWord();
    if (D_0079B3CC[0] & 0x10000)
        summary.metadata.difficulty = 0;
    else if (D_0079B3CC[0] & 0x20000)
        summary.metadata.difficulty = 2;
    else
        summary.metadata.difficulty = 1;
    summaryBytes = (u8 *)&summary;
    sum = 0;
    for (summaryIndex = 0; summaryIndex < 50; summaryIndex++)
        sum += summaryBytes[summaryIndex];
    summary.checksum = sum;
    memcpy(buffer + 4, &summary, 52);
    records = buffer + 56;
    tag = 1;
    memcpy(records, &tag, 4);
    length = 36;
    memcpy(buffer + 60, &length, 4);
    memcpy(buffer + 64, D_007973A0, 36);
    tag = 2;
    memcpy(buffer + 100, &tag, 4);
    length = 72;
    memcpy(buffer + 104, &length, 4);
    memcpy(buffer + 108, D_007973C4, 72);
    tag = 3;
    memcpy(buffer + 180, &tag, 4);
    length = 344;
    memcpy(buffer + 184, &length, 4);
    memcpy(buffer + 188, D_0079740C, 344);
    tag = 4;
    memcpy(buffer + 532, &tag, 4);
    length = 16;
    memcpy(buffer + 536, &length, 4);
    memcpy(buffer + 540, D_00797564, 16);
    tag = 5;
    memcpy(buffer + 556, &tag, 4);
    length = 6;
    memcpy(buffer + 560, &length, 4);
    memcpy(buffer + 564, D_00797574, 6);
    tag = 6;
    memcpy(buffer + 570, &tag, 4);
    length = 1536;
    memcpy(buffer + 574, &length, 4);
    memcpy(buffer + 578, D_0079757A, 1536);
    tag = 8;
    memcpy(buffer + 2114, &tag, 4);
    length = 2;
    memcpy(buffer + 2118, &length, 4);
    memcpy(buffer + 2122, D_00797B7A, 2);
    tag = 9;
    memcpy(buffer + 2124, &tag, 4);
    length = 1;
    memcpy(buffer + 2128, &length, 4);
    memcpy(buffer + 2132, D_00797B7C, 1);
    tag = 10;
    memcpy(buffer + 2133, &tag, 4);
    length = 4;
    memcpy(buffer + 2137, &length, 4);
    memcpy(buffer + 2141, D_00797B80, 4);
    tag = 11;
    memcpy(buffer + 2145, &tag, 4);
    length = 2;
    memcpy(buffer + 2149, &length, 4);
    memcpy(buffer + 2153, D_00797B84, 2);
    tag = 12;
    memcpy(buffer + 2155, &tag, 4);
    length = 1;
    memcpy(buffer + 2159, &length, 4);
    memcpy(buffer + 2163, D_00797B86, 1);
    tag = 13;
    memcpy(buffer + 2164, &tag, 4);
    length = 1024;
    memcpy(buffer + 2168, &length, 4);
    memcpy(buffer + 2172, D_00797B87, 1024);
    tag = 14;
    memcpy(buffer + 3196, &tag, 4);
    length = 2;
    memcpy(buffer + 3200, &length, 4);
    memcpy(buffer + 3204, D_00797F88, 2);
    tag = 15;
    memcpy(buffer + 3206, &tag, 4);
    length = 576;
    memcpy(buffer + 3210, &length, 4);
    memcpy(buffer + 3214, D_00797F8C, 576);
    tag = 16;
    memcpy(buffer + 3790, &tag, 4);
    length = 12288;
    memcpy(buffer + 3794, &length, 4);
    memcpy(buffer + 3798, D_007981CC, 12288);
    tag = 17;
    memcpy(buffer + 16086, &tag, 4);
    length = 704;
    memcpy(buffer + 16090, &length, 4);
    memcpy(buffer + 16094, D_0079B1CC, 704);
    tag = 18;
    memcpy(buffer + 16798, &tag, 4);
    length = 4;
    memcpy(buffer + 16802, &length, 4);
    memcpy(buffer + 16806, D_0079B68C, 4);
    tag = 19;
    memcpy(buffer + 16810, &tag, 4);
    length = 8;
    memcpy(buffer + 16814, &length, 4);
    memcpy(buffer + 16818, D_0079B690, 8);
    tag = 21;
    memcpy(buffer + 16826, &tag, 4);
    length = 4;
    memcpy(buffer + 16830, &length, 4);
    memcpy(buffer + 16834, D_0079B698, 4);
    tag = 22;
    memcpy(buffer + 16838, &tag, 4);
    length = 4;
    memcpy(buffer + 16842, &length, 4);
    memcpy(buffer + 16846, D_0079B69C, 4);
    tag = 23;
    memcpy(buffer + 16850, &tag, 4);
    length = 4;
    memcpy(buffer + 16854, &length, 4);
    memcpy(buffer + 16858, D_0079B6A0, 4);
    tag = 24;
    memcpy(buffer + 16862, &tag, 4);
    length = 340;
    memcpy(buffer + 16866, &length, 4);
    memcpy(buffer + 16870, D_0079BCD8, 340);
    tag = 25;
    memcpy(buffer + 17210, &tag, 4);
    length = 512;
    memcpy(buffer + 17214, &length, 4);
    memcpy(buffer + 17218, D_0079B48C, 512);
    tag = 26;
    memcpy(buffer + 17730, &tag, 4);
    length = 1536;
    memcpy(buffer + 17734, &length, 4);
    memcpy(buffer + 17738, D_0079B6D8, 1536);
    tag = 27;
    memcpy(buffer + 19274, &tag, 4);
    length = 52;
    memcpy(buffer + 19278, &length, 4);
    memcpy(buffer + 19282, D_0079B6A4, 52);
    tag = 34;
    memcpy(buffer + 19334, &tag, 4);
    length = 1;
    memcpy(buffer + 19338, &length, 4);
    memcpy(buffer + 19342, D_00797B7C, 1);
    tag = 35;
    memcpy(buffer + 19343, &tag, 4);
    length = 4;
    memcpy(buffer + 19347, &length, 4);
    memcpy(buffer + 19351, D_0079BEF4, 4);
    cursor = buffer + 19355;
    total += 19355;
    if (compact == 0) {
        tag = 37;
        memcpy(cursor, &tag, 4);
        length = 4;
        memcpy(cursor + 4, &length, 4);
        memcpy(cursor + 8, &iGpffffb1b4, 4);
        tag = 38;
        memcpy(cursor + 12, &tag, 4);
        length = 4;
        memcpy(cursor + 16, &length, 4);
        memcpy(cursor + 20, &iGpffffb1b8, 4);
        tag = 39;
        memcpy(cursor + 24, &tag, 4);
        length = 86016;
        memcpy(cursor + 28, &length, 4);
        memcpy(cursor + 32, D_007BBF00, 86016);
        cursor += 0x15020;
        total += 0x15020;
    }
    tag = 40;
    memcpy(cursor, &tag, 4);
    length = 200;
    memcpy(cursor + 4, &length, 4);
    memcpy(cursor + 8, D_0079BE2C, 200);
    tag = 41;
    memcpy(cursor + 208, &tag, 4);
    length = FldStepTableSize();
    memcpy(cursor + 212, &length, 4);
    cursor += 216;
    total += 216;
    memcpy(cursor, FldStepTable(), FldStepTableSize());
    cursor += FldStepTableSize();
    total += FldStepTableSize();
    for (unitIndex = 0; unitIndex < 10; unitIndex++) {
        tag = (unitIndex << 8) + 0x100;
        memcpy(cursor, &tag, 4);
        length = 4;
        memcpy(cursor + 4, &length, 4);
        unit = (u8 *)&((DatPartySlot *)D_00796E50)[unitIndex];
        memcpy(cursor + 8, unit, 4);
        tag = (unitIndex << 8) + 257;
        memcpy(cursor + 12, &tag, 4);
        length = 72;
        memcpy(cursor + 16, &length, 4);
        memcpy(cursor + 20, unit + 4, 72);
        tag = (unitIndex << 8) + 258;
        memcpy(cursor + 92, &tag, 4);
        length = 6;
        memcpy(cursor + 96, &length, 4);
        memcpy(cursor + 100, unit + 76, 6);
        tag = (unitIndex << 8) + 261;
        memcpy(cursor + 106, &tag, 4);
        length = 48;
        memcpy(cursor + 110, &length, 4);
        memcpy(cursor + 114, unit + 84, 48);
        tag = (unitIndex << 8) + 267;
        memcpy(cursor + 162, &tag, 4);
        length = 4;
        memcpy(cursor + 166, &length, 4);
        memcpy(cursor + 170, unit + 132, 4);
        cursor += 174;
        total += 174;
    }
    checksum = 0;
    for (checksumIndex = 0; checksumIndex < (u32)(total - 56); checksumIndex++)
        checksum += records[checksumIndex];
    tag = 0x2000;
    memcpy(cursor, &tag, 4);
    length = 1;
    memcpy(cursor + 4, &length, 4);
    memcpy(cursor + 8, &checksum, 1);
    tag = -1;
    memcpy(cursor + 9, &tag, 4);
    *outSize = total + 13;
    func_00440b68(D_005E45A0, total + 13);
    return buffer;
}
#pragma pop

/* Restore tagged sections until the terminator or checksum section, then rebuild protagonist names. */
// FUN_0010E710
void datSaveRestoreImage(s32 version, u8 *image, s32 unusedSize)
{
    u32 tag;
    u32 length;
    u8* cursor = image + 0x34;

    while (1)
    {
        memcpy(&tag, cursor, 4);
        func_00440b68(D_005E45C0, tag);
        if (tag == -1 || tag == 0x2000)
        {
            break;
        }
        memcpy(&length, cursor + 4, 4);
        cursor = cursor + 8;
        datSaveRestoreSection(version, tag, length, cursor);
        cursor = cursor + length;
    }
    iGpffffb19c = D_0079B67C[0];
    memset(DAT_00796de0, 0, 0x12);
    memset(DAT_00796e00, 0, 0x12);
    memset(DAT_00796e20, 0, 0x24);
    memcpy(DAT_00796de0, DAT_007973a0, 0x12);
    memcpy(DAT_00796e00, DAT_007973b2, 0x12);
    sprintf(DAT_00796e20, &iGpffff9bb0, DAT_00796e00, DAT_00796de0);
}

/* Walk variable-length save sections and compare their byte sum with the checksum section. */
// FUN_0010E880
/* The fixed image header precedes a flexible stream of tagged sections. */
s32 datSaveVerifyChecksum(s32 unusedVersion, u8 *image, s32 size)
{
    u8 byte;
    u32 tag;
    u32 length;
    u32 limit;
    u32 sum;
    u8* cursor;
    s32 checksum;
    u32 i;

    if (size < 0x1000)
    {
        return 0;
    }
    cursor = image + 0x34;
    sum = 0;
    limit = (u32)(size - 0x34);
    while (1)
    {
        memcpy(&tag, cursor, 4);
        if (tag == -1)
        {
            break;
        }
        if (tag == 0x2000)
        {
            checksum = 0;
            i = 0;
            while (i < sum)
            {
                checksum = (checksum + ((DatSaveImage *)(image + i))->sections[0]) & 0xFF;
                i = i + 1;
            }
            memcpy(&length, cursor + 4, 4);
            memcpy(&byte, cursor + 8, 1);
            return (checksum & 0xFF) == byte;
        }
        memcpy(&length, cursor + 4, 4);
        if (length == 0)
        {
            return 0;
        }
        cursor = cursor + 8;
        cursor = cursor + length;
        sum = sum + 8;
        sum = sum + length;
        if (sum >= limit)
        {
            return 0;
        }
    }
    return 0;
}

/* Copy one tagged save-data section back into its global save buffer, ignoring it unless its length
 * matches the size that tag expects. */
// FUN_0010E9E0
void datSaveRestoreSection(s32 unusedVersion, u32 tag, u32 length, u8* data)
{
    u32 index;
    switch (tag) {
    case 1:
        if (length == 36)
            memcpy(D_007973A0, data, 36);
        break;
    case 2:
        if (length == 72)
            memcpy(D_007973C4, data, 72);
        break;
    case 3:
        if (length == 344)
            memcpy(D_0079740C, data, 344);
        break;
    case 4:
        if (length == 16)
            memcpy(D_00797564, data, 16);
        break;
    case 5:
        if (length == 6)
            memcpy(D_00797574, data, 6);
        break;
    case 6:
        if (length == 1536)
            memcpy(D_0079757A, data, length);
        break;
    case 8:
        if (length == 2)
            memcpy(D_00797B7A, data, length);
        break;
    case 9:
        if (length == 1)
            memcpy(D_00797B7C, data, length);
        break;
    case 10:
        if (length == 4)
            memcpy(D_00797B80, data, length);
        break;
    case 11:
        if (length == 2)
            memcpy(D_00797B84, data, length);
        break;
    case 12:
        if (length == 1)
            memcpy(D_00797B86, data, length);
        break;
    case 13:
        if (length == 1024)
            memcpy(D_00797B87, data, length);
        break;
    case 14:
        if (length == 2)
            memcpy(D_00797F88, data, length);
        break;
    case 15:
        if (length == 576)
            memcpy(D_00797F8C, data, length);
        break;
    case 16:
        if (length == 12288)
            memcpy(D_007981CC, data, length);
        break;
    case 17:
        if (length == 704)
            memcpy(D_0079B1CC, data, length);
        break;
    case 18:
        if (length == 4)
            memcpy(D_0079B68C, data, length);
        break;
    case 19:
        if (length == 8)
            memcpy(D_0079B690, data, length);
        break;
    case 21:
        if (length == 4)
            memcpy(D_0079B698, data, length);
        break;
    case 22:
        if (length == 4)
            memcpy(D_0079B69C, data, length);
        break;
    case 23:
        if (length == 4)
            memcpy(D_0079B6A0, data, length);
        break;
    case 24:
        if (length == 340)
            memcpy(D_0079BCD8, data, length);
        break;
    case 25:
        if (length == 512)
            memcpy(D_0079B48C, data, length);
        break;
    case 26:
        if (length == 1536)
            memcpy(D_0079B6D8, data, length);
        break;
    case 27:
        if (length == 52)
            memcpy(D_0079B6A4, data, length);
        break;
    case 32:
        break;
    case 34:
        if (length == 1)
            memcpy(D_00797B7C, data, length);
        break;
    case 35:
        if (length == 4)
            memcpy(D_0079BEF4, data, length);
        break;
    case 37:
        if (length == 4)
            memcpy(&iGpffffb1b4, data, length);
        break;
    case 38:
        if (length == 4)
            memcpy(&iGpffffb1b8, data, length);
        break;
    case 39:
        if (length == 86016)
            memcpy(D_007BBF00, data, length);
        break;
    case 40:
        if (length == 200)
            memcpy(D_0079BE2C, data, length);
        break;
    case 41:
        if (length == FldStepTableSize())
            memcpy(FldStepTable(), data, length);
        break;
    case 0x100:
    case 0x200:
    case 0x300:
    case 0x400:
    case 0x500:
    case 0x600:
    case 0x700:
    case 0x800:
    case 0x900:
    case 0xa00:
        index = tag >> 8;
        if (length == 4)
            memcpy(&((DatPartySlot *)D_00796E50)[index - 1], data, length);
        break;
    case 0x101:
    case 0x201:
    case 0x301:
    case 0x401:
    case 0x501:
    case 0x601:
    case 0x701:
    case 0x801:
    case 0x901:
    case 0xa01:
        index = tag >> 8;
        if (length == 72)
            memcpy(&((DatPartySlot *)D_00796E50)[index - 1].character, data, length);
        break;
    case 0x102:
    case 0x202:
    case 0x302:
    case 0x402:
    case 0x502:
    case 0x602:
    case 0x702:
    case 0x802:
    case 0x902:
    case 0xa02:
        index = tag >> 8;
        if (length == 6)
            memcpy(((DatPartySlot *)D_00796E50)[index - 1].unknown4C, data, length);
        break;
    case 0x105:
    case 0x205:
    case 0x305:
    case 0x405:
    case 0x505:
    case 0x605:
    case 0x705:
    case 0x805:
    case 0x905:
    case 0xa05:
        index = tag >> 8;
        if (length == 48)
            memcpy(&((DatPartySlot *)D_00796E50)[index - 1].personaRecord, data, length);
        break;
    }
}

/* Clear all 85 words of the collection-entry bitmap. */
// FUN_0010F390
/* Linker interior alias: the collection words start at DAT_007973a0 + 0x4938. */
void datClearCollectionBitmap(void)
{
    u32 i = 0;
    u8* p = (u8*)DAT_007973a0;

    while (i < 0x55)
    {
        ((DatSaveState *)p)->collection[i] = 0;
        i = i + 1;
    }
}

/* Sets bit (bitIndex + entryIndex 8) in the bitmap D_0079BCD8; pairs with datTestBitmapBit.
 * Unsigned masks allow bit 31. */
// FUN_0010F3D0
void datSetBitmapBit(u32 entryIndex, u32 bitIndex)
{
    u32 bit = (bitIndex & 0xffff) + (entryIndex & 0xffff) * 8;

    D_0079BCD8[bit >> 5] |= 1U << (bit & 0x1f);
}

// Returns the state of bit (bitIndex + entryIndex 8) in the bitmap D_0079BCD8.
// FUN_0010F420
u32 datTestBitmapBit(u32 entryIndex, u32 bitIndex)
{
    u32 bit = (bitIndex & 0xffff) + (entryIndex & 0xffff) * 8;
    u32* p = &D_0079BCD8[bit >> 5];

    return *p & (1U << (bit & 0x1f));
}


/* measured: retail hoists the mask out of the loop. */
#pragma opt_loop_invariants on

/* Return the eight collection bits for the given entry index from the save state's collection
 * bitfield, combined with OR. Each bit stays at its original position. */
// FUN_0010F460
/* Linker interior alias: the collection words start at DAT_007973a0 + 0x4938. */
u32 datGetCollectionEntryBits(u16 entryIndex)
{
    u32 result = 0;
    u32 j = (u32)entryIndex * 8;
    u32 i = 0;
    u8* base = DAT_007973a0;

    while (i < 8)
    {
        result |= ((((DatSaveState *)base)->collection[j >> 5]) & (1 << (j & 0x1F)));
        i = i + 1;
        j = j + 1;
    }
    return result;
}
#pragma opt_loop_invariants off

// FUN_0010F4C0
/* Passes the saved battle-unit record table to its reset routine. */
void datResetBattleUnitSaveTable(void)
{
    btlUnitRecordResetSaveTable(D_0079BE2C);
}

/* Return the per-unit 20-byte roster slot for a nonzero signed selector below eleven. */
// FUN_0010F4F0
u8 *datPersonaGetRosterSlot(s32 unitId) {
    s32 v = (s16)unitId;

    if ((v == 0) || (v >= 0xB)) {
        return NULL;
    }
    return (u8 *)(((s32)D_007973A0 + ((v - 1) * 0x14)) + 0x4A8C);
}

// FUN_0010F540
/* Forwards the skill selector to datCalcIsSkillAvailable. */
s32 datIsSkillAvailable(s32 skillId)
{
    return datCalcIsSkillAvailable(skillId);
}

/* Resolve the character by id and pass its record to the threshold-kind reader. */
// FUN_0010F560
u16 datCalcThresholdKindById(s16 unitId, s32 skillId)
{
    u8* p;

    if (unitId == 1)
    {
        p = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(unitId < 0xB, 0x234);
        p = (u8 *)&((DatPartySlot *)D_00796E50)[unitId - 2].character;
    }
    return datCalcThresholdKind(p, skillId);
}

/* Resolve the character by id and compute its cost for the requested skill. */
// FUN_0010F600
u32 datCalcSkillCostById(s16 unitId, s32 skillId)
{
    u8* p;

    if (unitId == 1)
    {
        p = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(unitId < 0xB, 0x234);
        p = (u8 *)&((DatPartySlot *)D_00796E50)[unitId - 2].character;
    }
    return datCalcSkillCost(p, skillId);
}

/* Resolve the character, validate its embedded id and evaluate the requested threshold trigger. */
// FUN_0010F6A0
s32 datCalcThresholdTriggerById(s16 unitId, u32 skillId)
{
    u8* ptr;
    u16 v;

    if (unitId == 1)
    {
        ptr = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(unitId < 0xB, 0x234);
        ptr = (u8 *)&((DatPartySlot *)D_00796E50)[unitId - 2].character;
    }
    v = ((DatUnit*)ptr)->id;
    K_ASSERT(v != 0 && v < 0xB, 0xE54);
    return datCalcThresholdTrigger(ptr, skillId);
}

/* Resolve source and target character ids before applying the skill effect. */
// FUN_0010F770
void datCalcApplySkillEffectById(s16 sourceId, s16 targetId, u32 skillId, u32 flags)
{
    u8* source;
    u8* target;

    K_ASSERT(targetId != 0 && targetId < 0xB, 0xE6A);
    if (sourceId == 1)
    {
        source = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(sourceId < 0xB, 0x234);
        source = (u8 *)&((DatPartySlot *)D_00796E50)[sourceId - 2].character;
    }
    if (targetId == 1)
    {
        target = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(targetId < 0xB, 0x234);
        target = (u8 *)&((DatPartySlot *)D_00796E50)[targetId - 2].character;
    }
    datCalcApplySkillEffect(skillId, source, target, flags);
}

/* Checks the skill id below 0x1B8 and returns byte eight of its 0x28-byte record. */
// FUN_0010F8C0
u16 datGetSkillPropertyByte(s32 skillId)
{
    u8* table;
    u16 id;

    K_ASSERT((skillId & 0xffff) < 0x1B8, 0xE87);
    table = DAT_007644A8;
    id = skillId;
    return table[id * 0x28 + 8];
}

/* Resolve source and target character ids and return the skill-effect flags. */
// FUN_0010F930
s32 datCalcSkillEffectFlagsById(s16 sourceId, s16 targetId, u32 skillId, u32 flags)
{
    u8* source;
    u8* target;

    K_ASSERT(targetId != 0 && targetId < 0xB, 0xEAC);
    if (sourceId == 1)
    {
        source = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(sourceId < 0xB, 0x234);
        source = (u8 *)&((DatPartySlot *)D_00796E50)[sourceId - 2].character;
    }
    if (targetId == 1)
    {
        target = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(targetId < 0xB, 0x234);
        target = (u8 *)&((DatPartySlot *)D_00796E50)[targetId - 2].character;
    }
    return datCalcSkillEffectFlags(skillId, source, target, flags);
}

/* Resolve source and target character ids and pass all three result addresses to the outcome calculator. */
// FUN_0010FA80
void datCalcSkillOutcomeById(s16 sourceId, s16 targetId, u32 skillId, u32 flags, u32 firstResult, u32 secondResult, u32 thirdResult)
{
    u8* source;
    u8* target;

    if (sourceId == 1)
    {
        source = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(sourceId < 0xB, 0x234);
        source = (u8 *)&((DatPartySlot *)D_00796E50)[sourceId - 2].character;
    }
    if (targetId == 1)
    {
        target = (u8 *)D_007973C4;
    }
    else
    {
        K_ASSERT(targetId < 0xB, 0x234);
        target = (u8 *)&((DatPartySlot *)D_00796E50)[targetId - 2].character;
    }
    datCalcSkillOutcome(skillId, source, target, flags, (s32*)firstResult, (s32*)secondResult, (s32*)thirdResult);
}

/* Returns the first set flag among bits 1, 2 and 3 of the persona flag table. */
// FUN_0010FBD0
u32 datGetPersonaFlagClass(u32 personaId)
{
    u16 f;

    K_ASSERT(personaId < 0x100, 0xF04);
    f = ((DatPersonaFlags*)DAT_007644D0)[personaId].flags;
    if (f & 2)
    {
        return 2;
    }
    if (f & 4)
    {
        return 4;
    }
    if (f & 8)
    {
        return 8;
    }
    return 0;
}

// FUN_0010FC80
/* Zeros the complete 0x3000-byte persona-record cache. */
void datClearPersonaRecordCache(void)
{
    FUN_0043f9c8(D_007981CC, 0, 0x3000);
}

/* Return an active 0x30-byte cached persona record, or null when its active bit is clear. */
// FUN_0010FCB0
u8* datPersonaCachedRecord(s32 personaId)
{
    u16 v;

    K_ASSERT(personaId >= 0 && personaId < 0x100, 0xF1D);
    v = ((DatPersonaRecord*)D_007981CC)[personaId].flags;
    if (v & 1)
    {
        return (u8*)DAT_007973a0 + personaId * 0x30 + 0xE2C;
    }
    return 0;
}

/* Validate the source persona id and copy its complete record into the cache. */
// FUN_0010FD40
void datPersonaCacheRecord(u8* src)
{
    DatPersonaRecord* persona = (DatPersonaRecord*)src;
    s32 index;

    K_ASSERT(src != 0, 0xF27);
    index = persona->id;
    K_ASSERT(index >= 0 && index < 0x100, 0xF28);
    memcpy((u8*)DAT_007973a0 + persona->id * 48 + 0xE2C, src, 0x30);
}

/* Return excluded records unchanged, otherwise find the cached copy or seed a missing cache entry. */
// FUN_0010FDE0
u8* datPersonaResolveRecord(u8* record)
{
    DatPersonaRecord* persona = (DatPersonaRecord*)record;
    s32 v;
    u16 w;
    u8* q;

    if (record == NULL)
    {
        FUN_0046d730(__FILE__, 0xF5D);
    }
    v = persona->id;
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF5E);
    }
    v = persona->id;
    w = ((DatPersonaMetadata*)((u8*)iGpffffb3d4 + v * 14))->flags;
    if (w & 8)
    {
        return record;
    }
    if (w & 0x20)
    {
        return record;
    }
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF1D);
    }
    if (((DatPersonaRecord*)(D_007981CC + v * 0x30))->flags & 1)
    {
        q = (u8*)D_007973A0 + v * 0x30 + 0xE2C;
    }
    else
    {
        q = NULL;
    }
    if (q != NULL)
    {
        return q;
    }
    if (record == NULL)
    {
        FUN_0046d730(__FILE__, 0xF27);
    }
    v = persona->id;
    if ((v < 0) || (v >= 0x100))
    {
        FUN_0046d730(__FILE__, 0xF28);
    }
    v = persona->id;
    memcpy((u8*)D_007973A0 + v * 0x30 + 0xE2C, record, 0x30);
    return NULL;
}

/* Initialize every nonzero persona id and seed cache entries allowed by metadata flags. */
// FUN_0010FFA0
/* Seven id accesses use a byte-buffer base with halfword width; the other accesses use the real
 * layouts. */
void datPersonaInitAllRecords(void) {
    u8 buf[0x30];
    u8 *base;
    s32 id;
    s32 i;

    i = 1;
    while (i < 0x100)
    {
        FUN_0043f9c8(buf, 0, 0x30);
        datPersonaInitRecord(buf, (u16)i);
        ((DatPersonaRecord*)buf)->flags |= 1;
        if (((s32)((DatPersonaRecord*)buf)->id < 0) || ((s32)MEMBER(u16, buf, DatPersonaRecord, id) >= 0x100))
        {
            FUN_0046d730((const char *)D_005E4298, 0xF5E);
        }
        base = iGpffffb3d4;
        id = MEMBER(u16, buf, DatPersonaRecord, id);
        if (!(((DatPersonaMetadata*)((u8*)base + id * 14))->flags & 8) &&
            !(((DatPersonaMetadata*)((u8*)base + id * 14))->flags & 0x20))
        {
            if (((s32)MEMBER(u16, buf, DatPersonaRecord, id) < 0) || ((s32)MEMBER(u16, buf, DatPersonaRecord, id) >= 0x100))
            {
                FUN_0046d730((const char *)D_005E4298, 0xF1D);
            }
            {
                u8 *q;
                q = (u8 *)DAT_007973a0 + id * 0x30;
                if (((DatPersonaRecord*)(q + 0xE2C))->flags & 1)
                {
                    q = q + 0xE2C;
                }
                else
                {
                    q = NULL;
                }
                if (q == NULL)
                {
                    if (((s32)MEMBER(u16, buf, DatPersonaRecord, id) < 0) || ((s32)MEMBER(u16, buf, DatPersonaRecord, id) >= 0x100))
                    {
                        FUN_0046d730((const char *)D_005E4298, 0xF28);
                    }
                    memcpy((u8 *)DAT_007973a0 + (s32)MEMBER(u16, buf, DatPersonaRecord, id) * 0x30 + 0xE2C, buf, 0x30);
                }
            }
        }
        i = i + 1;
    }
}

/* Divides the number of active cached persona records by the metadata-eligible count and scales by 100. */
// FUN_00110140
s32 datGetPersonaCacheCompletionPercent(void)
{
    s32 count1 = 0;
    s32 i = 0;
    s32 count2;
    s32 j;
    u8* q;
    u16 v;
    u8* p;

    while (i < 0x100)
    {
        if ((i < 0) || (i >= 0x100))
        {
            FUN_0046d730(__FILE__, 0xF1D);
        }
        p = (u8*)DAT_007973a0 + i * 0x30;
        if (((DatPersonaRecord*)(p + 0xE2C))->flags & 1)
        {
            q = p + 0xE2C;
        }
        else
        {
            q = NULL;
        }
        if (q != NULL)
        {
            count1 = count1 + 1;
        }
        i = i + 1;
    }
    count2 = 0;
    j = 0;
    p = (u8*)iGpffffb3d4;
    while (j < 0x100)
    {
        v = ((DatPersonaMetadata*)p)[j].flags;
        if (!(v & 8) && !(v & 0x20))
        {
            count2 = count2 + 1;
        }
        j = j + 1;
    }
    return count1 * 0x64 / count2;
}

/* Copy a complete persona record into staging and store its separate selection id. */
// FUN_00110270
void datStageRecord(u8* src, u16 personaId)
{
    memcpy(D_0079B6A8, src, 0x30);
    D_0079B6A4[0] = personaId;
}

// FUN_001102C0
void datStageSetId(s16 personaId)
{
    D_0079B6A4[0] = personaId;
}

// FUN_001102D0
u16 datStagedId(void)
{
    return D_0079B6A4[0];
}

// FUN_001102E0
u8* datStagedRecord(void)
{
    return D_0079B6A8;
}

/* Builds and transforms a normalized camera-space ray and writes camera position plus scaled direction. */
// FUN_001102F0
u8* datScreenPointToWorldPosition(u8* output, s32 screenX, s32 screenY, f32 distance)
{
    f32 buf[3];
    u8* obj;
    u8* obj3;

    if (output == NULL)
    {
        FUN_0046d730(__FILE__, 0xFB8);
    }
    obj = kwlnGetCamera();
    buf[0] = -((f32)screenX - 320.0f) * ((RwCamera*)obj)->viewWindow[0] / 320.0f;
    buf[1] = -((f32)screenY - 224.0f) * ((RwCamera*)obj)->viewWindow[1] / 224.0f;
    buf[2] = 1.0f;
    RwV3dNormalize(buf, buf);
    obj3 = func_003e9700((s32)((RwCamera*)kwlnGetCamera())->object.object.parent);
    func_003e4320(buf, buf, obj3);
    buf[0] = buf[0] * distance;
    buf[1] = buf[1] * distance;
    buf[2] = buf[2] * distance;
    ((f32*)output)[0] = ((RwMatrixTag*)obj3)->pos.x + buf[0];
    ((f32*)output)[1] = ((RwMatrixTag*)obj3)->pos.y + buf[1];
    ((f32*)output)[2] = ((RwMatrixTag*)obj3)->pos.z + buf[2];
    return output;
}
