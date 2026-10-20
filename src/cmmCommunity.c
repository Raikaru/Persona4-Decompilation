#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - cmmCommunity.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"
#include "cmm_internal.h"

/* Effect tables contain 32-bit words; consumers select their little-endian low byte or halfword. */
typedef union CmmPointEffectWord { s32 word; u16 lowHalf; u8 lowByte; } CmmPointEffectWord;

/* Current-community task work is allocated as 0x20 bytes by cmmCommunitySetCurrent. */
typedef struct CmmCurrentWork {
    s16 communityId;
    u8 pad02[0x0E];
    u16 secondary;
    u8 pad12[0x0E];
} CmmCurrentWork;

/* Game flags are the 0xB0 words at +0x3E2C of the saved game state. */
typedef struct CmmGameState {
    u8 pad00[0x3E2C];
    s32 flags[0xB0];
} CmmGameState;

extern void *memset(void *dest, s32 value, s32 size);
extern s32 kwlnTaskGetTaskByName(void *name);
extern u32 kwlnTaskGetWork(s32 task);
extern void kAssertFail(const void *file, u32 line);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern s64 cmmCommunityArcana(s32 communityId);
extern s32 cmmFindCommunityOfCategory(s32 value);
extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 icon);
extern s32 cmmCommunityHasRecord(s32 communityId);
extern u16 cmmCommunityRecordValue(s32 communityId);
extern s32 cmmCommunityTestReversed(s32 communityId);
extern s32 cmmCommunityTestBroken(s32 communityId);
extern CmmCommunityRecord *cmmCommunityFindRecord(s32 value);
extern void cmmCommunitySetRank(s32 communityId, s32 rank);
extern s32 cmmCommunityGetCurrentId(void);
extern s32 D_005E42D8[];
extern f32 D_005E42DC[];
extern f32 D_005E42E0[];
extern s32 D_005E42E8[];
extern f32 D_005E42EC[];
extern f32 D_005E42F0[];
extern s32 D_005E42F8[];
extern f32 D_005E42FC[];
extern f32 D_005E4300[];
extern s32 cmmRosterHasArcana(s32 value);
extern u8 *cmmEntryValueRecord(void);
extern s32 datRankForPoints(s16 category, s16 points);
extern s16 D_007973F4[];
extern void *cmmKindRecord(s32 kindId);
extern void cmmCommunityReleaseRecord(s32 communityId);
extern void datSetFlag(s32 flagId, s32 enabled);
extern u32 D_0079B1CC[];
extern CmmGameState D_007973A0[];
extern void cmmCommunitySetFlagBand(s32 communityId, s32 band);

extern void datDestroyTaskByName(void);
extern void datFreeTaskWork(u8 *unusedTask);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_0079740C[];
extern CmmCommunityRecord D_00797410[];
extern s32 D_00797560[];
extern char D_005E42C8[];
extern char D_005E4308[];

// Community flag band: sets the band-b flag of community value after clearing its related flags. Band 1 and bands 4-12 clear the upper group (0x41F and the band 4-12 flags); bands 2 and 3 clear the paired entries (0x43F and 0x45F); band 0 only sets its own flag.
// FUN_00106DB0
void cmmCommunitySetFlagBand(s32 communityId, s32 band)
{
    s32 id = communityId & 0xFFFF;
    s32 i;

    if (id <= 0)
    {
        kAssertFail(D_005E42C8, 0x31);
    }
    if (band < 4 || band > 0xC)
    {
        if (band == 1)
        {
            goto bpath;
        }
        goto cpath;
    }
bpath:
    i = 4;
    while (i <= 0xC)
    {
        if (id <= 0)
        {
            kAssertFail(D_005E42C8, 0x1E);
        }
        datSetFlag(id + ((i << 5) + 0x3FF), 0);
        i++;
    }
    if (id <= 0)
    {
        kAssertFail(D_005E42C8, 0x1E);
    }
    datSetFlag(id + 0x41F, 0);
    goto end;
cpath:
    if ((u32)(band - 2) >= 2)
    {
        goto end;
    }
    if (id <= 0)
    {
        kAssertFail(D_005E42C8, 0x1E);
    }
    datSetFlag((communityId & 0xFFFF) + 0x43F, 0);
    if ((communityId & 0xFFFF) <= 0)
    {
        kAssertFail(D_005E42C8, 0x1E);
    }
    datSetFlag(id + 0x45F, 0);
end:
    datSetFlag(id + ((band << 5) + 0x3FF), 1);
}

/* measured: 356 executable bytes / 368B retail window, fully relocated exact.
   The inline clear helper owns the masked ID and loop-index lifetimes;
   its separate assertion preserves retail's record/ID saved-register order. */
/* Clear the thirteen community flags after validating the masked identifier. */
static inline void cmmClearCommunityFlags(s32 community)
{
    s32 id = community & 0xFFFF;
    s32 flag;
    if (id <= 0) {
        kAssertFail(D_005E42C8, 0x27);
    }
    for (flag = 0; flag < 13; flag++) {
        datSetFlag(id + ((flag << 5) + 0x3FF), 0);
    }
}

// Community refresh flags: clears the flag bands of community value and rebuilds them from its record: the base band (cmmCommunityHasRecord) and the rank band (rank 10 maps to band 1, others to rank + 3), then bands 2 (cmmCommunityTestReversed) and 3 (cmmCommunityTestBroken).
// FUN_00106F40
void cmmCommunityRefreshFlags(s32 communityId) {
    CmmCommunityRecord *record;
    s32 id;
    s32 rank;
    record = (CmmCommunityRecord *)cmmCommunityFindRecord(communityId);
    id = communityId & 0xFFFF;
    if (id <= 0) {
        kAssertFail(D_005E42C8, 0x48);
    }
    cmmClearCommunityFlags(communityId);
    if (record == NULL) {
        return;
    }
    if (cmmCommunityHasRecord(communityId) != 0) {
        cmmCommunitySetFlagBand(communityId, 0);
        rank = record->rank;
        if (rank == 0xA) {
            cmmCommunitySetFlagBand(communityId, 1);
        } else {
            cmmCommunitySetFlagBand(communityId, rank + 3);
        }
    }
    if (cmmCommunityTestReversed(communityId) != 0) {
        cmmCommunitySetFlagBand(communityId, 2);
    }
    if (cmmCommunityTestBroken(communityId) != 0) {
        cmmCommunitySetFlagBand(communityId, 3);
    }
}
// Community clear table: zeroes the community record table at D_0079740C (0x158 bytes).
// FUN_001070B0
void cmmCommunityClearTable(void)
{
    memset(D_0079740C, 0, 0x158);
}

// Community find record: returns the community table record for id value, or 0 when the id is 0 or absent from the table.
// FUN_001070E0
CmmCommunityRecord *cmmCommunityFindRecord(s32 value)
{
    s32 id = value & 0xFFFF;
    CmmCommunityRecord *ptr;
    s32 i;

    if (id >= 0x1F)
    {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0)
    {
        return 0;
    }
    ptr = D_00797410;
    i = 0;
    while (i < 0x15)
    {
        if (ptr->id == id)
        {
            return ptr;
        }
        ptr++;
        i++;
    }
    return 0;
}

// Community find by kind: returns the first flagged community id (cmmCommunityHasRecord) whose kind record (cmmKindRecord) equals value, or 0 when none matches.
// FUN_00107180
s32 cmmCommunityFindByKind(s16 kind)
{
    s32 i;
    s32 result;

    result = 0;
    if (kind >= 0x15)
    {
        kAssertFail(D_005E42C8, 0x77);
    }
    for (i = 1; i < 0x1F; i++)
    {
        if (kind == *(s32 *)cmmKindRecord(i & 0xFFFF))
        {
            if (cmmCommunityHasRecord((u16)i) != 0)
            {
                result = i;
                break;
            }
        }
    }
    return result & 0xFFFF;
}

// Community counterpart: returns the paired community id (3 and 4, 5 and 6, 0B and 0C, 0E and 0F, 15 and 16) and maps 19 to 1A and 1B to 1C. Other ids are returned unchanged.
// FUN_00107240
s16 cmmCommunityCounterpart(s32 communityId)
{
    u32 id = communityId & 0xFFFF;

    switch (id)
    {
    case 3:
        return 4;
    case 4:
        return 3;
    case 5:
        return 6;
    case 6:
        return 5;
    case 0xB:
        return 0xC;
    case 0xC:
        return 0xB;
    case 0xE:
        return 0xF;
    case 0xF:
        return 0xE;
    case 0x15:
        return 0x16;
    case 0x16:
        return 0x15;
    case 0x19:
        return 0x1A;
    case 0x1B:
        return 0x1C;
    }
    return (s16)communityId;
}

// Release counterparts: frees the paired records that value displaces (3<->4, 5<->6, 0B<->0C, 0E<->0F, 15<->16, 10<->11, and the 19/1A/1B/1C group) before cmmCommunityAllocRecord claims a slot.
// FUN_00107370
void cmmCommunityReleaseCounterparts(s32 communityId)
{
    u32 id = communityId & 0xFFFF;

    switch (id)
    {
    case 3:
        cmmCommunityReleaseRecord(4);
        break;
    case 4:
        cmmCommunityReleaseRecord(3);
        break;
    case 5:
        cmmCommunityReleaseRecord(6);
        break;
    case 6:
        cmmCommunityReleaseRecord(5);
        break;
    case 0xB:
        cmmCommunityReleaseRecord(0xC);
        break;
    case 0xC:
        cmmCommunityReleaseRecord(0xB);
        break;
    case 0xE:
        cmmCommunityReleaseRecord(0xF);
        break;
    case 0xF:
        cmmCommunityReleaseRecord(0xE);
        break;
    case 0x15:
        cmmCommunityReleaseRecord(0x16);
        break;
    case 0x16:
        cmmCommunityReleaseRecord(0x15);
        break;
    case 0x19:
        cmmCommunityReleaseRecord(0x1A);
        cmmCommunityReleaseRecord(0x1C);
        cmmCommunityReleaseRecord(0x1B);
        break;
    case 0x1A:
        cmmCommunityReleaseRecord(0x19);
        cmmCommunityReleaseRecord(0x1C);
        cmmCommunityReleaseRecord(0x1B);
        break;
    case 0x1B:
        cmmCommunityReleaseRecord(0x1C);
        cmmCommunityReleaseRecord(0x1A);
        cmmCommunityReleaseRecord(0x19);
        break;
    case 0x1C:
        cmmCommunityReleaseRecord(0x1B);
        cmmCommunityReleaseRecord(0x1A);
        cmmCommunityReleaseRecord(0x19);
        break;
    case 0x10:
        cmmCommunityReleaseRecord(0x11);
        break;
    case 0x11:
        cmmCommunityReleaseRecord(0x10);
        break;
    }
}

/* measured: retail's slot search keeps the found-exit as an inline
   unconditional branch (bne->advance; b found; advance out-of-line), the same
   shape mwcc b210 emits for `if (cond) return;` in cmmCommunityFindRecord. mwcc merges
   `if (cond) goto found;` (any if/else polarity) into a single beqz->found with
   the advance inline. Tried while+break+retest (re-test not folded), goto,
   both if/else orders — all nd 10. Branch-shape floor. */
// Community alloc record: when value has no record, claims the first free slot of the table at D_00797410, sets its id and its +6 field to 1, and sets flag bands 0 and 4. Asserts on a full table or a zero id.
// FUN_001075D0
void cmmCommunityAllocRecord(s32 communityId) {
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (cmmCommunityHasRecord(communityId) != 0) {
        return;
    }
    cmmCommunityReleaseCounterparts(communityId);
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == 0) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        kAssertFail(D_005E42C8, 0x107);
    }
    if ((communityId & 0xFFFF) == 0) {
        kAssertFail(D_005E42C8, 0x108);
    }
    memset(r, 0, 0x10);
    r->flags = 0;
    r->id = communityId;
    r->rank = 1;
    cmmCommunitySetFlagBand(communityId, 0);
    cmmCommunitySetFlagBand(communityId, 4);
}

/* measured: retail's slot search emits the found-exit as an inline
   unconditional branch (bne->advance; b found) exactly like cmmCommunityFindRecord's
   `if (cond) return;`, but this is void with shared tail code. mwcc b210 merges
   any single-goto if/else branch into a conditional branch to the target
   (beq->found), and a post-loop NULL retest is only free (reuses the loop slti)
   when kept off the found path via goto; ==/> retest forms regress. Best nd 10
   (goto + >= retest); 4 attempts. Branch-shape + retest floor. */
/* Community-slot scan family (cmmCommunityReleaseRecord/cmmCommunityHasRecord/107a00/107bd0/107ce0/107dc0/
   107f00/107fe0): walk 21 records of stride 16 from D_007973A0[0x70] looking for a
   matching id. All eight sit at nd 38 with the body below, recovered from the m2c
   draft via tools/draft_probe.py. Two m2c defects had to be repaired first: the
   pointer is typed `s32 *` and advanced by `+= 0x10`, which walks 64 bytes per record
   instead of 16 (silently wrong, still compiles), and the base is emitted as a bare
   address literal D_00797410 that no file declares.
   The residual is one branch shape: retail leaves the loop on a match with a
   bne-to-advance plus b-to-exit PAIR, b210 with a single beq-to-exit. Measured NOT
   reachable via goto, break, inverted test with continue, advance-in-else, an
   explicit entry-goto mirroring retail block order, do/while, a single-case switch
   (right size, booleanised compare), while+break (nd 48-65, and it is what fixed
   evtMain func_00288020, so it is shape-specific not universal), s16/s32/u16
   signatures, and eleven control-flow pragmas including opt_rotateloops both ways.
   An in-loop `return` DOES produce the pair at the exact window size but then
   materialises its own return value where retail falls into the shared block.
   Committed at nd 72. */
// Community release record: when value has a record, clears it and its 13 flag bands; asserts on a zero id in that case.
// FUN_001076E0
void cmmCommunityReleaseRecord(s32 communityId) {
    s32 j;
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        memset(r, 0, 0x10);
        if (id <= 0) {
            kAssertFail(D_005E42C8, 0x27);
        }
        j = 0;
        while (j < 0xD) {
            datSetFlag(id + ((j << 5) + 0x3FF), 0);
            j++;
        }
    }
}

/* measured: retail slot search emits found-exit as inline unconditional b
   (bne->advance; b found) which mwcc b210 only produces for return-thens
   (cmmCommunityFindRecord); goto/break/switch/continue/m2c-goto-loop spellings all
   merge to a single conditional branch (best nd 14, m2c verbatim form has
   test-at-top layout). Shared tail after the loop blocks the return idiom.
   Branch-shape floor. */
/* measured: retail's slot search found-exit (bne->advance; b found) is the
   return-then shape: an in-loop `return var_4 != NULL;` reproduces the branch
   pair exactly but duplicates the sltu value computation at the loop site
   (nd 17); goto/break/switch forms merge into a single conditional branch
   (best nd 14 m2c-goto form). The found path must jump to the shared return
   block, which mwcc b210 only does for the merged goto. Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Community has record: returns 1 when a record with id value is in the 21-entry table at D_00797410, else 0. Asserts the id is in range.
// FUN_001077F0
s32 cmmCommunityHasRecord(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    return r != NULL;
}

// Returns the record value of the first community with arcana value that has a record, or 0 when none.
// FUN_00107890
s32 cmmCommunityValueForArcana(s32 arcana)
{
    s32 i;
    s32 id;

    i = 0;
    id = arcana & 0xFFFF;
    while (i < 0x1F)
    {
        if ((id == (s8)cmmCommunityArcana(i & 0xFFFF)) && (cmmCommunityFindRecord(i & 0xFFFFu) != 0))
        {
            return cmmCommunityRecordValue((u16)i) & 0xFFFF;
        }
        i++;
    }
    return 0;
}

// Community active slot: returns the first active slot id in group value (0 = slots 1-2, 1 = slots 3-4), or 0 when none is active.
// FUN_00107930
s32 cmmCommunityFindActiveSlotInGroup(s32 group)
{
    switch (group)
    {
    case 0:
        if (cmmFindCommunityOfCategory(1) & 0xFFFF)
        {
            return 1;
        }
        if (cmmFindCommunityOfCategory(2) & 0xFFFF)
        {
            return 2;
        }
        break;
    case 1:
        if (cmmFindCommunityOfCategory(3) & 0xFFFF)
        {
            return 3;
        }
        if (cmmFindCommunityOfCategory(4) & 0xFFFF)
        {
            return 4;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* measured: same slot-search floor as cmmCommunityAllocRecord: retail's found-exit is
   bne->advance; b found, jumping to a shared NULL-retest tail; mwcc b210
   merges the goto spelling into a single beq->found (nd 24) and the
   return-then spelling inlines the found lw/and block into the loop instead
   of the shared retest tail (nd 25). Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Test record flags: returns the record's flag word ANDed with mask option, or 0 when value has no record.
// FUN_00107A00
s32 cmmCommunityTestRecordFlags(s32 communityId, s32 mask) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    return (s32)((CmmCommunityRecord *)r)->flags & mask;
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 22.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Returns the u16 value at +6 of the record for community value (the id is matched at +4), or 0 when there is none; ids of 0x1F or more assert.
// FUN_00107AC0
u16 cmmCommunityRecordValue(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    return r->rank;
}

// Test marked: returns 1 when value's record has the MARKED bit (0x4) set, else 0. The bit's meaning is not evidenced (see include/cmm_internal.h).
// FUN_00107B70
s32 cmmCommunityTestMarked(s32 communityId)
{
    s32 r = (s32)cmmCommunityFindRecord(communityId);
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = ((CmmCommunityRecord *)r)->flags & CMM_RECORD_FLAG_MARKED;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 22.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Set marked: sets the MARKED bit (0x4) in the record of community value; does nothing when the id has no record. The bit's meaning is not evidenced (see include/cmm_internal.h).
// FUN_00107BD0
void cmmCommunitySetMarked(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        ((CmmCommunityRecord *)r)->flags |= CMM_RECORD_FLAG_MARKED;
    }
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 31.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Set reversed: sets the REVERSED bit (0x1), clears BROKEN (0x2), then refreshes flag band 2. Nothing happens when value has no record.
// FUN_00107CE0
void cmmCommunitySetReversed(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        ((CmmCommunityRecord *)r)->flags |= CMM_RECORD_FLAG_REVERSED;
        ((CmmCommunityRecord *)r)->flags &= ~CMM_RECORD_FLAG_BROKEN;
        cmmCommunitySetFlagBand(communityId, 2);
    }
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 32.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Clear reversed: clears the REVERSED bit (0x1) and calls datSetFlag(id + 0x43F, 0); asserts on a zero id when the record exists.
// FUN_00107DC0
void cmmCommunityClearReversed(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        ((CmmCommunityRecord *)r)->flags &= ~CMM_RECORD_FLAG_REVERSED;
        if (id <= 0) {
            kAssertFail(D_005E42C8, 0x1E);
        }
        datSetFlag(id + 0x43F, 0);
    }
}

// Test reversed: returns 1 when value's record has the REVERSED bit (0x1) set, else 0. RefreshFlags reads it as flag band 2.
// FUN_00107C80
s32 cmmCommunityTestReversed(s32 communityId)
{
    s32 r = (s32)cmmCommunityFindRecord(communityId);
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = ((CmmCommunityRecord *)r)->flags & CMM_RECORD_FLAG_REVERSED;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

// Test broken: returns 1 when value's record has the BROKEN bit (0x2) set, else 0. RefreshFlags reads it as flag band 3.
// FUN_00107EA0
s32 cmmCommunityTestBroken(s32 communityId)
{
    s32 r = (s32)cmmCommunityFindRecord(communityId);
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = ((CmmCommunityRecord *)r)->flags & CMM_RECORD_FLAG_BROKEN;
    }
    if (r != 0)
    {
        return 1;
    }
    return 0;
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 31.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Set broken: sets the BROKEN bit (0x2), clears REVERSED (0x1), then refreshes flag band 3. Nothing happens when value has no record.
// FUN_00107F00
void cmmCommunitySetBroken(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        ((CmmCommunityRecord *)r)->flags |= CMM_RECORD_FLAG_BROKEN;
        ((CmmCommunityRecord *)r)->flags &= ~CMM_RECORD_FLAG_REVERSED;
        cmmCommunitySetFlagBand(communityId, 3);
    }
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 32.
   Branch-shape floor. */
/* Community-slot scan family; see the note above cmmCommunityReleaseRecord. nd 38.
   Committed at nd 38. */
// Clear broken: clears the BROKEN bit (0x2) and calls datSetFlag(id + 0x45F, 0); asserts on a zero id when the record exists.
// FUN_00107FE0
void cmmCommunityClearBroken(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r != NULL) {
        ((CmmCommunityRecord *)r)->flags &= ~CMM_RECORD_FLAG_BROKEN;
        if (id <= 0) {
            kAssertFail(D_005E42C8, 0x1E);
        }
        datSetFlag(id + 0x45F, 0);
    }
}

/* measured: retail booleanizes the variable-mask bit check (lw; and; sltu
   $v0,$zero,$v0; beqz) and mwcc b210 folds `!= 0`, `(u32)x > 0`, boolean-local,
   u32-typed and `0 < x` spellings into a direct and;beqz (2 missing sltu words
   shift the whole tail; nd 64). Everything else matched on the first draft.
   Booleanize floor. */
/* measured: the typed game-state flag array preserves both owner matches; calling datGetFlag or a bit-test helper changes codegen. */
// Earn scale: returns the float multiplier for points community value earns, from cmmRosterHasArcana on its arcana, the event bit in D_0079B1CC, and the per-slot bands in D_007973A0.
/* The character lookup receives this function's incoming identifier.
   With that argument explicit, the configured O2 profile preserves every
   original instruction; the old omitted-argument O1 workaround is obsolete. */
// FUN_001080C0
#pragma optimization_level 2
f32 cmmCommunityEarnScale(s32 communityId) {
    f32 v;
    s32 i;
    s32 b;
    u32 *w;
    s32 *q;
    s32 hit;

    v = 1.0f;
    if (cmmRosterHasArcana((s8)cmmCommunityArcana(communityId)) != 0) {
        v = v * cmmEarnScaleTable()->arcanaMul;
    }
    if (cmmEarnScaleTable()->eventBit != 0) {
        b = cmmEarnScaleTable()->eventBit;
        w = &D_0079B1CC[b / 32];
        hit = (*w & (1 << (b % 32))) != 0;
        if (hit != 0) {
            v = v * cmmEarnScaleTable()->eventMul;
        }
    }
    if ((((CmmKindRecord *)cmmKindRecord(communityId))->flags & 0x20) != 0) {
        i = 0;
        while (i < 3) {
            if (cmmEarnScaleTable()->slot[i].flagBit != 0) {
                b = cmmEarnScaleTable()->slot[i].flagBit;
                /* Linker interior aliases: D_0079B1CC is D_007973A0 + 0x3E2C, the shared game-flag bank. */
                q = &D_007973A0->flags[b / 32];
                hit = (*q & (1 << (b % 32))) != 0;
                if (hit != 0) {
                    v = v * cmmEarnScaleTable()->slot[i].mul;
                }
            }
            i++;
        }
    }
    return v;
}
/* Continue at the configured O2 profile. */
#pragma optimization_level 2


/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 151
   (loop floor plus tail register-allocation noise). Branch-shape floor. */
// Add scaled points: adds option scaled by cmmCommunityEarnScale to value's point counter at +8 and returns the amount added; 0 when value has no record.
// FUN_00108290
s32 cmmCommunityAddScaledPoints(s32 communityId, u32 points) {
    f32 v;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 x;
    s32 id;
    s32 i;
    s32 b;
    u32 *w;
    s32 *q;
    s32 hit;
    u16 n;

    x = communityId;
    id = x & 0xFFFF;
    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    v = 1.0f;
    if (cmmRosterHasArcana((s8)cmmCommunityArcana(x)) != 0) {
        v = v * cmmEarnScaleTable()->arcanaMul;
    }
    if (cmmEarnScaleTable()->eventBit != 0) {
        b = cmmEarnScaleTable()->eventBit;
        w = &D_0079B1CC[b / 32];
        hit = (*w & (1 << (b % 32))) != 0;
        if (hit != 0) {
            v = v * cmmEarnScaleTable()->eventMul;
        }
    }
    if ((((CmmKindRecord *)cmmKindRecord(x))->flags & 0x20) != 0) {
        x = 0;
        while (x < 3) {
            if (cmmEarnScaleTable()->slot[x].flagBit != 0) {
                b = cmmEarnScaleTable()->slot[x].flagBit;
                /* Linker interior aliases: D_0079B1CC is D_007973A0 + 0x3E2C, the shared game-flag bank. */
                q = &D_007973A0->flags[b / 32];
                hit = (*q & (1 << (b % 32))) != 0;
                if (hit != 0) {
                    v = v * cmmEarnScaleTable()->slot[x].mul;
                }
            }
            x++;
        }
    }
    n = (u16)((f32)points * v);
    r->points = r->points + n;
    return n;
}


/* measured: object 604 bytes against the 592-byte retail window, normalized_diff 206, first differing offsets 42,44,46,47,50,51,54-59,62,63,66,67; archived in build/CMMC_00108590_body.c. Retail's int-to-float bltz/mtc1/cvt.s.w and srl/andi/or/mtc1/cvt.s.w/add.s paths are represented by (f32)(u32)option, and its c.le.s/trunc.w.s/mfc1/andi or sub.s/trunc.w.s/mfc1/lui 0x8000/or/andi paths by (u16)temp_f1. Corrected block-scope callee declarations; direct/aggregate layouts, aliases, parameter mutation, O1, loop forms, floating guard polarity, explicit branch labels, and declaration variants were ruled out. */
/* measured: explicit earned-value widening after effect-index initialization matches with loop invariants at baseline. */
// Add points: adds option scaled by cmmCommunityEarnScale to value's point counter at +8, plays the threshold effect (sdkSndStartStream) and the resource check (MT_Scene_SpawnResIconTask) when selection is not -1, and returns the new counter. A zero value uses the current community.
// FUN_00108590
u16 cmmCommunityAddPoints(s32 communityId, s32 points, s32 resourceId) {
    extern void kAssertFail(void *file, s32 line);
    typedef struct { f32 x; f32 y; f32 z; } Vec3;
    typedef struct {
        CmmPointEffectWord bytes[3];
        s32 pad0;
        CmmPointEffectWord durations[3];
        s32 pad1;
        s32 thresholds[3];
        s32 pad2;
    } Table;
    Table vals;
    u16 earnedPoints;
    f32 multiplier;
    f32 scaledPoints;
    f32 basePoints;
    CmmCommunityRecord *record;
    u32 effectIndex;
    s32 earnedValue;
    *(Vec3 *)vals.thresholds = *(Vec3 *)D_005E42D8;
    *(Vec3 *)vals.durations = *(Vec3 *)D_005E42E8;
    *(Vec3 *)vals.bytes = *(Vec3 *)D_005E42F8;
    if (!(communityId & 0xFFFF)) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (!(communityId & 0xFFFF)) {
        kAssertFail(&D_005E42C8[0], 0x21F);
    }
    {
        CmmCommunityRecord *earnedRecord;
        earnedRecord = (CmmCommunityRecord *)cmmCommunityFindRecord(communityId);
        if (earnedRecord == NULL) {
            earnedPoints = 0;
        } else {
            multiplier = cmmCommunityEarnScale(communityId);
            basePoints = (f32)(u32)points;
            scaledPoints = basePoints * multiplier;
            earnedPoints = (u16)scaledPoints;
            earnedRecord->points =
                (u16)(earnedRecord->points + earnedPoints);
        }
    }
    effectIndex = 0;
    earnedValue = earnedPoints;
    while (effectIndex < 3U) {
        if (earnedValue > *(s32 *)&vals.thresholds[effectIndex]) {
            effectIndex += 1;
            continue;
        }
        break;
    }
    /* Tables store word-sized slots; the sound/icon APIs consume only their low half/byte. */
    sdkSndStartStream(0, 0, 4, vals.durations[effectIndex].lowHalf);
    if (resourceId != -1) {
        MT_Scene_SpawnResIconTask(((resourceId & 0x3FF) | 0xC00) & 0xFFFF,
                      vals.bytes[effectIndex].lowByte);
    }
    record = (CmmCommunityRecord *)cmmCommunityFindRecord(communityId);
    if (record == NULL) {
        return 0U;
    }
    return record->points;
}
// Can rank up: returns 1 when value has a record below max rank 0xA and its point counter reaches the threshold for its current rank in the kind record's table, else 0.
// FUN_001087E0
s32 cmmCommunityCanRankUp(s32 communityId) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;
    s32 t;
    s32 rank;
    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    t = (s32)cmmCommunityFindRecord(communityId);
    if (t == 0) {
        t = 0;
    } else {
        t = ((CmmCommunityRecord *)t)->rank;
    }
    if ((t & 0xFFFF) == 0xA) {
        return 0;
    }
    t = (s32)cmmCommunityFindRecord(communityId);
    if (t == 0) {
        t = 0;
    } else {
        t = ((CmmCommunityRecord *)t)->rank;
    }
    id = t & 0xFFFF;
    rank = r->points;
    if (rank >= ((CmmKindRecord *)cmmKindRecord(communityId))->rankThreshold[id & 0xFFFF]) {
        return 1;
    }
    return 0;
}


/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 93
   (loop floor plus tail noise). Branch-shape floor. */
/* measured: reconstructed this wave. Slot-search head plus the community
   rank-up predicate. Three levers took it from nd 163 to nd 1: reusing the
   masked-id local for the cmmCommunityFindRecord result (retail reuses $s0 for both),
   declaring the slot pointer before the id so the pair lands $s1/$s0 rather
   than $s0/$s1, and #pragma optimization_level 1, which stops b210 folding
   the third guarded load into the level register and restores retail's
   andi. The single residual word is retail's `daddiu $v0,$zero,1` for the
   predicate's true value where b210 emits `addiu`. Probed for that one word:
   ok as s32, u32, long, unsigned long, s64, u64, and both
   pointer types, with 1, 1U, 1LL,
   (s64)1, (u8 *)1, !0 and -(-1); inverted and pre-set branch polarity
   (nd 11 and nd 343); goto/switch/result-variable tail layouts (all
   identical); schedule on/off, no_branch_likely, opt_common_subs off,
   opt_propagation off, opt_rebuildconditionals, opt_loop_invariants at -O1
   return-merge, which b210 does not inline (object collapses to 324).
   New comparison-spelling probes changed `id >= 0x1F` to `id > 0x1E`
   and `i < 0x15` to `i <= 0x14`; each scored nd 3, so the nd 1 base
   remains the lowest body. The daddiu residual did not move; this is a
   settled floor after the comparison lever. Committed at nd 1. */
// Try rank up: runs the same checks as cmmCommunityCanRankUp inline; when they pass, raises the rank by one through cmmCommunitySetRank, zeroes the point counter, and clears record flag 4. Returns 1 on success.
/* measured: -O1 is load-bearing for this body - at -O2 mwcc coalesces the
   third cmmCommunityFindRecord result straight into the level saved register and
   drops retail's andi, costing nd 162. */
// FUN_00108950
#pragma optimization_level 1
s32 cmmCommunityTryRankUp(s32 communityId) {
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 id;
    s32 i;
    s32 t;
    s32 u;
    s32 lv;
    u8 ok;
    id = communityId & 0xFFFF;
    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return 0;
    }
    id = (s32)cmmCommunityFindRecord(communityId);
    if (id == 0) {
        ok = 0;
    } else {
        t = (s32)cmmCommunityFindRecord(communityId);
        if (t == 0) {
            t = 0;
        } else {
            t = ((CmmCommunityRecord *)t)->rank;
        }
        if ((t & 0xFFFF) == 0xA) {
            ok = 0;
        } else {
            u = (s32)cmmCommunityFindRecord(communityId);
            if (u == 0) {
                u = 0;
            } else {
                u = ((CmmCommunityRecord *)u)->rank;
            }
            lv = u & 0xFFFF;
            id = ((CmmCommunityRecord *)id)->points;
            if (id >= ((CmmKindRecord *)cmmKindRecord(communityId))->rankThreshold[lv & 0xFFFF]) {
                ok = (u8)1;
            } else {
                ok = 0;
            }
        }
    }
    if (!ok) {
        goto ret0;
    }
    t = (s32)cmmCommunityFindRecord(communityId);
    if (t == 0) {
        t = 0;
    } else {
        t = ((CmmCommunityRecord *)t)->rank;
    }
    cmmCommunitySetRank(communityId, (t & 0xFFFF) + 1);
    r->points = 0;
    t = (s32)cmmCommunityFindRecord(communityId);
    if (t != 0) {
        ((CmmCommunityRecord *)t)->flags = ((CmmCommunityRecord *)t)->flags & ~CMM_RECORD_FLAG_MARKED;
    }
    return 1;
ret0:
    return 0;
}
/* measured: closes the -O1 bracket above at the file's -O2 baseline. */
#pragma optimization_level 2

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 18
   (tail matched; s16 option variant only differs by mwcc's post-jal
   re-extension, nd 47 with s32 option from assert-block scheduling).
   Branch-shape floor. */
// Set rank: stores option (1 to 0xA) as value's rank at +6 and sets flag band 1 at max rank, or band rank + 3 otherwise.
// FUN_00108B60
void cmmCommunitySetRank(s32 communityId, s32 rank) {
    s32 id = communityId & 0xFFFF;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;

    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return;
    }
    if (rank == 0) {
        kAssertFail(D_005E42C8, 0x254);
    }
    if (rank > 0xA) {
        kAssertFail(D_005E42C8, 0x255);
    }
    r->rank = rank;
    if (r->rank == 0xA) {
        cmmCommunitySetFlagBand(communityId, 1);
        return;
    }
    cmmCommunitySetFlagBand(communityId, r->rank + 3);
}

// Community task noop: the first task callback passed to kwlnTaskCreate; does nothing and returns 0.
// FUN_00108CA0
s32 cmmCommunityTaskNoop(u8 *unusedTask)
{
    return 0;
}

// Community set current: replaces the current community task with a new one for id value.
// FUN_00108CF0
void cmmCommunitySetCurrent(s32 communityId)
{
    CmmCurrentWork *work;

    datDestroyTaskByName();
    chkmemAllocSiteTag(D_005E42C8, 0x271);
    work = D_008873F4[0](1, 0x20, 0x40000);
    work->communityId = communityId;
    kwlnTaskCreate((const void *)(D_005E4308), 0xF, 0, 0, cmmCommunityTaskNoop, datFreeTaskWork, (u8 *)(work));
}

// Community current work: returns the work pointer of the current community record, or 0 when none is set.
// FUN_00108DC0
s32 cmmCommunityGetCurrentWork(void)
{
    s32 ret = kwlnTaskGetTaskByName(D_005E4308);
    if (ret != 0)
    {
        return (s32)kwlnTaskGetWork(ret);
    }
    return 0;
}

// Community current id: returns the id of the current community record, or 0 when none is set.
// FUN_00108E10
s32 cmmCommunityGetCurrentId(void)
{
    s32 r = kwlnTaskGetTaskByName(D_005E4308);
    if (r != 0)
    {
        r = (s32)kwlnTaskGetWork(r);
    }
    else
    {
        r = 0;
    }
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = *(u16 *)r;
    }
    return r;
}

// Community secondary: returns the u16 at +0x10 of the current record (field meaning not yet recovered), or 0 when no current record is set.
// FUN_00108E70
s32 cmmCommunityGetCurrentSecondary(void)
{
    s32 r = kwlnTaskGetTaskByName(D_005E4308);
    if (r != 0)
    {
        r = (s32)kwlnTaskGetWork(r);
    }
    else
    {
        r = 0;
    }
    if (r == 0)
    {
        r = 0;
    }
    else
    {
        r = ((CmmCurrentWork *)r)->secondary;
    }
    return r;
}

// Community table head set: stores value in the first u16 of the community record table (D_0079740C).
// FUN_00108ED0
void cmmCommunitySetTableHead(u16 value)
{
    D_0079740C[0] = value;
}

// Community table head: returns the first u16 of the community record table (D_0079740C).
// FUN_00108EE0
u16 cmmCommunityGetTableHead(void)
{
    return D_0079740C[0];
}

/* measured: same slot-search floor as cmmCommunityTestRecordFlags/cmmCommunityAllocRecord (found-exit
   bne->advance; b found vs mwcc's merged beq->found); goto spelling nd 93
   (loop floor; the descending switch and call loop match otherwise).
   Branch-shape floor. */
// Community advance form: sets the upgraded form id of the record for value (3->4, 5->6, 0B->0C, 0E->0F, 15->16, 19->1A, 1B->1C), clears flag bands 0-12, and refreshes that record's flags.
// FUN_00108EF0
void cmmCommunityAdvanceForm(s32 communityId) {
    s32 id;
    CmmCommunityRecord *r;
    CmmCommunityRecord *p;
    s32 i;
    s32 j;

    id = communityId & 0xFFFF;
    if (id >= 0x1F) {
        kAssertFail(D_005E42C8, 0x66);
    }
    if (id == 0) {
        r = NULL;
        goto ret;
    }
    p = D_00797410;
    i = 0;
    while (i < 0x15) {
        if (p->id == id) {
            r = p;
            goto ret;
        }
        p++;
        i++;
    }
    r = NULL;
ret:
    if (r == NULL) {
        return;
    }
    switch (id) {
    case 3:
        r->id = 4;
        break;
    case 5:
        r->id = 6;
        break;
    case 0xB:
        r->id = 0xC;
        break;
    case 0xE:
        r->id = 0xF;
        break;
    case 0x15:
        r->id = 0x16;
        break;
    case 0x19:
        r->id = 0x1A;
        break;
    case 0x1B:
        r->id = 0x1C;
        break;
    }
    if (id <= 0) {
        kAssertFail(D_005E42C8, 0x27);
    }
    j = 0;
    while (j < 0xD) {
        datSetFlag(id + ((j << 5) + 0x3FF), 0);
        j++;
    }
    cmmCommunityRefreshFlags(r->id);
}


// Community total add: adds value to the running total (D_00797560).
// FUN_001090C0
void cmmCommunityAddTotal(s32 value)
{
    D_00797560[0] += value;
}

// Community total: returns the running total (D_00797560).
// FUN_001090E0
s32 cmmCommunityGetTotal(void)
{
    return D_00797560[0];
}

// Community entry value: looks up the current entry's value through cmmEntryValueRecord, indexed by datRankForPoints over D_007973F4; asserts the index is positive. The extern passes an argument that this definition ignores.
// FUN_00109100
s32 cmmCommunityGetCurrentEntryValue(void)
{
    u8 *work;
    s16 id;
    s32 index;

    work = cmmEntryValueRecord();
    id = *(s16 *)work;
    index = (s16)datRankForPoints(id, D_007973F4[id]);
    if (index <= 0) {
        kAssertFail(D_005E42C8, 0x2F6);
    }
    /* Entry-value records are six words; index 0 contains the stat id. */
    return ((s32 *)work)[index];
}
