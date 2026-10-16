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
extern void cmmCommunityAllocRecord(s32 arg0);
extern s32 cmmCommunityHasRecord(s32 arg0);
extern s32 cmmCommunityGetCurrentId(void);
extern s32 cmmCommunityRecordValue(s32 arg0);
extern s32 cmmCommunityTryRankUp(s32 arg0);
extern s32 cmmCommunityCanRankUp(s32 arg0);
extern s32 cmmCommunityTestReversed(s32 arg0);
extern s32 cmmCommunitySetReversed(s32 arg0);
extern s32 cmmCommunityClearReversed(s32 arg0);
extern s32 cmmCommunityTestBroken(s32 arg0);
extern s32 cmmCommunitySetBroken(s32 arg0);
extern s32 cmmCommunityClearBroken(s32 arg0);
extern s32 cmmCommunityAddScaledPoints(s32 arg0, s32 arg1);
extern s32 cmmCommunityAddPoints(s32 arg0, s32 arg1, s32 arg2);
extern s64 datGetDateIndex(void);
extern s32 calSplitDayOfYear(s64 arg0, s32 *arg1, s32 *arg2);
extern s32 cmmNthEligibleCommunity(s32 arg0, s32 arg1, s32 arg2);
extern s32 cmmCommunitySetTableHead(s32 arg0);

extern f32 D_00761260;
extern f32 fGpffff811c;
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
static inline f32 add_f32_ordered(f32 left, f32 right)
{
    return left + right;
}
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00249b10-0024a060 */

/* measured: optimization_level 1 preserves the saved task id across the guard. */
/* measured: func_00249b10 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// Ensures the community entry for the id (arg 0, or the current community when 0) has a record, allocating one when missing [inferred].
// FUN_00249B10
s32 cmmEnsureRecord(void)
{
    s32 temp_16;

    temp_16 = scrGetParamInt(0);
    if (temp_16 == 0) {
        temp_16 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityHasRecord(temp_16 & 0xFFFF) == 0) {
        cmmCommunityAllocRecord(temp_16 & 0xFFFF);
    }
    return 1;
}

/* measured: closes optimization_level 1 around func_00249b10. */
/* measured: cmmAddPointId, cmmSetBroken, cmmSetReverse, func_00249d00 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// Intent: Event command CMM_EXIST (p4flow Event 0x3002): stores whether the cmm entry exists [inferred]
// FUN_00249B80
s32 cmmExist(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    scrSetReturnInt(cmmCommunityHasRecord(var_2 & 0xFFFF));
    return 1;
}

// Intent: Event command CMM_GET_LV (p4flow Event 0x3003): returns the cmm entry level [inferred]
// FUN_00249BE0
s32 cmmGetLevel(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    scrSetReturnInt(cmmCommunityRecordValue(var_2 & 0xFFFF) & 0xFFFF);
    return 1;
}

// Tries to rank up the community entry for the id (arg 0, or the current community when 0) [inferred].
// FUN_00249C40
s32 cmmTryRankUp(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunityTryRankUp(var_2 & 0xFFFF);
    return 1;
}

// Intent: Event command CMM_CHK_LVUP (p4flow Event 0x300E): returns whether the cmm entry can level up [inferred]
// FUN_00249C90
s32 cmmCheckLevelUp(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityCanRankUp(var_2 & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Adds scaled points (arg 1) to the community entry for the id (arg 0, or the current community when 0) [inferred].
// FUN_00249D00
s32 cmmAddScaledPointId(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    if (var_17 == 0) {
        var_17 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunityAddScaledPoints(var_17 & 0xFFFF, temp_16 & 0xFFFF);
    return 1;
}

// Intent: Event command CMM_ADD_POINT_ID (p4flow Event 0x3031): adds points to the cmm entry [inferred]
// FUN_00249D70
s32 cmmAddPointId(void)
{
    s32 temp_16;
    s32 temp_17;

    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    cmmCommunityAddPoints(temp_17 & 0xFFFF, temp_16 & 0xFFFF, scrGetParamInt(2));
    return 1;
}

// Returns 1 when the community entry for the id is reversed, else 0 [inferred].
// FUN_00249DE0
s32 cmmIsReversed(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityTestReversed(var_2 & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Intent: Event command CMM_SET_REVERSE (p4flow Event 0x3011): sets or clears the reverse flag [inferred]
// FUN_00249E50
s32 cmmSetReverse(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    if (var_17 == 0) {
        var_17 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (temp_16 != 0) {
        cmmCommunitySetReversed(var_17 & 0xFFFF);
    } else {
        cmmCommunityClearReversed(var_17 & 0xFFFF);
    }
    return 1;
}

// Returns 1 when the community entry for the id is broken, else 0 [inferred].
// FUN_00249EE0
s32 cmmIsBroken(void)
{
    s32 var_2;

    var_2 = scrGetParamInt(0);
    if (var_2 == 0) {
        var_2 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmCommunityTestBroken(var_2 & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// Intent: Event command CMM_SET_BROKEN (p4flow Event 0x3012): sets or clears the broken flag [inferred]
// FUN_00249F50
s32 cmmSetBroken(void)
{
    s32 temp_16;
    s32 var_17;

    var_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    if (var_17 == 0) {
        var_17 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (temp_16 != 0) {
        cmmCommunitySetBroken(var_17 & 0xFFFF);
    } else {
        cmmCommunityClearBroken(var_17 & 0xFFFF);
    }
    return 1;
}

// Returns the nth community eligible for today's date index; the nth is arg 0 [inferred].
// FUN_00249FE0
s32 cmmGetNthEligibleId(void)
{
    s32 sp2C;
    s32 sp28;
    s32 temp_16;
    temp_16 = scrGetParamInt(0);
    calSplitDayOfYear((s16)datGetDateIndex(), &sp2C, &sp28);
    scrSetReturnInt(cmmNthEligibleCommunity(temp_16, sp2C, sp28));
    return 1;
}

// Sets the community table head to the id in arg 0 (or the current community when 0) [inferred].
// FUN_0024A060
s32 cmmSetTableHead(void)
{
    s32 var_4;

    var_4 = scrGetParamInt(0) & 0xFFFF;
    if (var_4 == 0) {
        var_4 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunitySetTableHead(var_4);
    return 1;
}

