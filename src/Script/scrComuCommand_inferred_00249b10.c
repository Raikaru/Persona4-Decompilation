#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "datScript_internal.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern u8 D_006359B0[];
extern u8 D_006359C0[];
extern void cmmCommunityAllocRecord(s32 communityId);
extern s32 cmmCommunityHasRecord(s32 communityId);
extern s32 cmmCommunityGetCurrentId(void);
extern s32 cmmCommunityRecordValue(s32 communityId);
extern s32 cmmCommunityTryRankUp(s32 communityId);
extern s32 cmmCommunityCanRankUp(s32 communityId);
extern s32 cmmCommunityTestReversed(s32 communityId);
extern s32 cmmCommunitySetReversed(s32 communityId);
extern s32 cmmCommunityClearReversed(s32 communityId);
extern s32 cmmCommunityTestBroken(s32 communityId);
extern s32 cmmCommunitySetBroken(s32 communityId);
extern s32 cmmCommunityClearBroken(s32 communityId);
extern s32 cmmCommunityAddScaledPoints(s32 communityId, s32 points);
extern s32 cmmCommunityAddPoints(s32 communityId, s32 points, s32 resourceId);
extern s64 datGetDateIndex(void);
extern s32 calSplitDayOfYear(s64 dateIndex, s32 *monthOut, s32 *dayOut);
extern s32 cmmNthEligibleCommunity(s32 requestedIndex, s32 month, s32 day);
extern s32 cmmCommunitySetTableHead(s32 value);

extern f32 D_00761260;
extern f32 fGpffff811c;
/* Promoted from the canonical function map: each function here has a C body in this file; see the `// FUN_` marker above it. */

/* measured: retail code generation for cmmEnsureRecord needs optimization level 1. */
#pragma optimization_level 1
// Ensures the community entry for the id (arg 0, or the current community when 0) has a record,
// allocating one when missing.
// FUN_00249B10
s32 cmmEnsureRecord(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityHasRecord(communityId & 0xFFFF) == 0) {
        cmmCommunityAllocRecord(communityId & 0xFFFF);
    }
    return 1;
}

/* measured: cmmAddPointId, cmmSetBroken, cmmSetReverse and func_00249d00 only reproduce retail code
 * at optimization level 2. */
#pragma optimization_level 2
// Script command 0x3002 (CMM_EXIST): returns whether the given community, or the current one if
// zero, has a record.
// FUN_00249B80
s32 cmmExist(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    scrSetReturnInt(cmmCommunityHasRecord(communityId & 0xFFFF));
    return 1;
}

// Script command 0x3003 (CMM_GET_LV): returns the community's level, using the current community
// when the parameter is 0.
// FUN_00249BE0
s32 cmmGetLevel(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    scrSetReturnInt(cmmCommunityRecordValue(communityId & 0xFFFF) & 0xFFFF);
    return 1;
}

// Script command 0x3004: tries to rank up the community given by arg 0, or the current community
// when arg 0 is 0.
// FUN_00249C40
s32 cmmTryRankUp(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunityTryRankUp(communityId & 0xFFFF);
    return 1;
}

// Script command 0x300E (CMM_CHK_LVUP): returns whether the current or given community can rank up.
// FUN_00249C90
s32 cmmCheckLevelUp(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityCanRankUp(communityId & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Script command 0x3005: adds scaled points (arg 1) to the community entry for the id (arg 0, or
// the current community when 0).
// FUN_00249D00
s32 cmmAddScaledPointId(void)
{
    s32 points;
    s32 communityId;

    communityId = scrGetParamInt(0);
    points = scrGetParamInt(1);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunityAddScaledPoints(communityId & 0xFFFF, points & 0xFFFF);
    return 1;
}

// Script command 0x3031 (CMM_ADD_POINT_ID): adds points to a community entry.
// FUN_00249D70
s32 cmmAddPointId(void)
{
    s32 points;
    s32 communityId;

    communityId = scrGetParamInt(0);
    points = scrGetParamInt(1);
    cmmCommunityAddPoints(communityId & 0xFFFF, points & 0xFFFF, scrGetParamInt(2));
    return 1;
}

// Script command 0x300F: returns 1 when the community entry for the id (0 means current) is
// reversed, else 0.
// FUN_00249DE0
s32 cmmIsReversed(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityTestReversed(communityId & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Script command 0x3011 (CMM_SET_REVERSE): sets or clears a community's reverse flag; community id
// 0 means the current community.
// FUN_00249E50
s32 cmmSetReverse(void)
{
    s32 enabled;
    s32 communityId;

    communityId = scrGetParamInt(0);
    enabled = scrGetParamInt(1);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (enabled != 0) {
        cmmCommunitySetReversed(communityId & 0xFFFF);
    } else {
        cmmCommunityClearReversed(communityId & 0xFFFF);
    }
    return 1;
}

// Script command 0x3010: returns 1 when the community entry for the id is broken, else 0.
// FUN_00249EE0
s32 cmmIsBroken(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityTestBroken(communityId & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Script command 0x3012 (CMM_SET_BROKEN): sets or clears a community's broken flag; community 0
// means the current one.
// FUN_00249F50
s32 cmmSetBroken(void)
{
    s32 enabled;
    s32 communityId;

    communityId = scrGetParamInt(0);
    enabled = scrGetParamInt(1);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (enabled != 0) {
        cmmCommunitySetBroken(communityId & 0xFFFF);
    } else {
        cmmCommunityClearBroken(communityId & 0xFFFF);
    }
    return 1;
}

// Returns the nth community eligible for today's date index, where n is arg 0. Script command
// 0x3006 (no p4flow name).
// FUN_00249FE0
s32 cmmGetNthEligibleId(void)
{
    s32 month;
    s32 day;
    s32 ordinal;
    ordinal = scrGetParamInt(0);
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &day);
    scrSetReturnInt(cmmNthEligibleCommunity(ordinal, month, day));
    return 1;
}

// Sets the community table head to the id in arg 0, or the current community when 0. Script command
// 0x3007.
// FUN_0024A060
s32 cmmSetTableHead(void)
{
    s32 communityId;

    communityId = scrGetParamInt(0) & 0xFFFF;
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunitySetTableHead(communityId);
    return 1;
}

