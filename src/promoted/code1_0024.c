#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern s32 datScriptTargetLacksFlag4(void);
extern f32 datScriptCalcFloat(s32 arg0, s32 arg1);
#include "datScript_internal.h"
extern void chkmemAllocSiteTag(void *file, s32 line);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 kwlnTaskGetTaskByName(void *path);
extern void kAssertFail(void *file, s32 line);
extern u8 D_006359B0[];
extern u8 D_006359C0[];
extern void cmmCommunityAllocRecord(s32 arg0);
extern s32 cmmCommunityHasRecord(s32 arg0);
extern s32 cmmCommunityGetCurrentId(void);
extern s32 func_00107ac0(s32 arg0);
extern s32 cmmCommunityTryRankUp(s32 arg0);
extern s32 scrGetParamInt(s32 arg0);
extern void scrSetReturnInt(s32 arg0);
extern s32 cmmCommunityCanRankUp(s32 arg0);
extern s32 cmmCommunityTestReversed(s32 arg0);
extern s32 cmmCommunitySetReversed(s32 arg0);
extern s32 cmmCommunityClearReversed(s32 arg0);
extern s32 cmmCommunityTestBroken(s32 arg0);
extern s32 cmmCommunitySetBroken(s32 arg0);
extern s32 cmmCommunityClearBroken(s32 arg0);
extern s32 cmmCommunityAddScaledPoints(s32 arg0, s32 arg1);
extern s32 cmmCommunityAddPoints(s32 arg0, s32 arg1, s32 arg2);
extern s64 func_001060b0(void);
extern s32 func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);
extern s32 cmmNthEligibleCommunity(s32 arg0, s32 arg1, s32 arg2);
extern s32 cmmNextUnlistedDate(s32 arg0);
extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern s32 cmmCommunitySetTableHead(s32 arg0);
extern s32 cmmCommunityGetTableHead(void);
extern s32 cmmDateNotListed(s32 arg0);

extern void func_00243ed0(void);
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

#pragma optimization_level 1
#pragma optimization_level 2
