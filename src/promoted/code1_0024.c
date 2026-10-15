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
extern s32 func_002480e0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00248040(s32 arg0);
extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern s32 cmmCommunitySetTableHead(s32 arg0);
extern s32 cmmCommunityGetTableHead(void);
extern s32 func_00247f60(s32 arg0);

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

// FUN_00244110
void func_00244110(void)
{
    extern s32 datScriptCmdFlag2Set(void);
    extern f32 sqrtf(f32 arg0);
    extern f32 fGpffff82c0;
    extern f32 fGpffff824c;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    if (datScriptCmdFlag2Set() != 0) {
        if (datScriptTargetLacksFlag4() != 0) {
            temp_f20 = datScriptCalcFloat(0xE, 2);
            temp_f20 += datScriptCalcFloat(0xE, 2);
            temp_f1 = datScriptCalcFloat(0x13, 0) / 2.0f;
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = 5.0f * temp_f20;
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f20 *= datScriptCalcFloat(0x17, 0);
        } else {
            temp_f20 = datScriptCalcFloat(0x20, 0) / 4.0f;
            temp_f3 = 2.0f;
            temp_f0 = datScriptCalcFloat(0xE, 2);
            temp_f2 = temp_f20 / temp_f3;
            temp_f1 = temp_f2 + temp_f3 * temp_f0;
            temp_f0 = fGpffff811c * temp_f1;
            temp_f20 = temp_f0;
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = mul_f32_ordered(5.0f, temp_f20);
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f1 = temp_f20 * datScriptCalcFloat(0x17, 0);
            temp_f20 = fGpffff82c0 * temp_f1;
        }
    } else {
        if (datScriptTargetLacksFlag4() != 0) {
            temp_f20 = datScriptCalcFloat(0xE, 2);
            temp_f20 += datScriptCalcFloat(0xE, 2);
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = 5.0f * temp_f20;
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f20 *= datScriptCalcFloat(0x17, 0);
        } else {
            temp_f20 = datScriptCalcFloat(0x20, 0) / 2.0f;
            temp_f3 = 2.0f;
            temp_f0 = datScriptCalcFloat(0xE, 2);
            temp_f2 = temp_f20 / temp_f3;
            temp_f1 = temp_f2 + temp_f3 * temp_f0;
            temp_f0 = fGpffff811c * temp_f1;
            temp_f20 = temp_f0;
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = mul_f32_ordered(5.0f, temp_f20);
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f1 = temp_f20 * datScriptCalcFloat(0x17, 0);
            temp_f20 = temp_f1 - 30.0f;
            if (temp_f20 <= 0.0f)
                temp_f20 = 1.0f;
            temp_f20 *= fGpffff824c;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
        }
    }
    datScriptSetResult(temp_f20);
}
// FUN_00244540
void func_00244540(void)
{
    extern f32 sqrtf(f32 arg0);
    extern f32 fGpffff824c;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    if (datScriptTargetLacksFlag4() != 0) {
        temp_f20 = datScriptCalcFloat(0xE, 2);
        temp_f20 += datScriptCalcFloat(0xE, 2);
        temp_f1 = datScriptCalcFloat(0x13, 0);
        temp_f1 = mul_f32_ordered(30.0f, temp_f1);
        temp_f0 = 5.0f * temp_f20;
        temp_f20 = temp_f1 / temp_f0;
        temp_f0 = datScriptCalcFloat(0xD, 1) / 5.0f;
        temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
        temp_f1 = sqrtf(temp_f0);
        temp_f21 = 10.0f * temp_f1;
        temp_f21 *= datScriptCalcFloat(0xC, 0);
        temp_f20 = datScriptCalcFloat(0x17, 0);
        temp_f0 = datScriptCalcFloat(0x19, 0);
        temp_f20 = temp_f0 + temp_f21 * temp_f20;
    } else {
        temp_f20 = datScriptCalcFloat(0x20, 0) / 2.0f;
        temp_f3 = 2.0f;
        temp_f0 = datScriptCalcFloat(0xE, 2);
        temp_f2 = temp_f20 / temp_f3;
        temp_f1 = temp_f2 + temp_f3 * temp_f0;
        temp_f0 = fGpffff811c * temp_f1;
        temp_f20 = temp_f0;
        temp_f1 = datScriptCalcFloat(0x13, 0);
        temp_f1 = mul_f32_ordered(30.0f, temp_f1);
        temp_f0 = mul_f32_ordered(5.0f, temp_f20);
        temp_f20 = temp_f1 / temp_f0;
        temp_f0 = datScriptCalcFloat(0xD, 1) / 5.0f;
        temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
        temp_f1 = sqrtf(temp_f0);
        temp_f21 = 10.0f * temp_f1;
        temp_f20 = datScriptCalcFloat(0x17, 0);
        temp_f0 = datScriptCalcFloat(0x19, 0);
        temp_f2 = temp_f0 + temp_f21 * temp_f20;
        temp_f0 = 30.0f;
        temp_f20 = temp_f2 - temp_f0;
        if (temp_f20 <= 0.0f)
            temp_f20 = 1.0f;
        temp_f20 *= 2.0f;
        temp_f20 *= datScriptCalcFloat(0xC, 0);
    }
    datScriptSetResult(temp_f20);
}
// FUN_00244870
void func_00244870(void)
{
    extern f32 fGpffff824c;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;

    if (datScriptTargetLacksFlag4() != 0) {
        temp_f20 = add_f32_ordered(200.0f, datScriptCalcFloat(0xD, 3));
        temp_f0 = add_f32_ordered(200.0f, datScriptCalcFloat(0xE, 3));
        temp_f20 = temp_f20 / temp_f0;
        temp_f0 = temp_f20 * datScriptCalcFloat(0x11, 0);
    } else {
        temp_f20 = add_f32_ordered(200.0f, datScriptCalcFloat(0xD, 3));
        temp_f0 = add_f32_ordered(200.0f, datScriptCalcFloat(0xE, 3));
        temp_f21 = temp_f20 / temp_f0;
        temp_f20 = datScriptCalcFloat(0x1F, 0) / fGpffff824c;
        temp_f1 = datScriptCalcFloat(0x11, 0) - temp_f20;
        if (temp_f1 <= 0.0f)
            temp_f1 = 1.0f;
        temp_f0 = temp_f21 * temp_f1;
    }
    datScriptSetResult(temp_f0);
}
// FUN_00244CF0
void func_00244cf0(void)
{
    extern f32 sqrtf(f32 arg0);
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;

    temp_f20 = datScriptCalcFloat(0xE, 2);
    temp_f20 += datScriptCalcFloat(0xE, 2);
    temp_f0 = datScriptCalcFloat(0x13, 0);
    temp_f1 = temp_f0 / 2.0f;
    temp_f0 = 30.0f * temp_f1;
    temp_f1 = 5.0f * temp_f20;
    temp_f20 = temp_f0 / temp_f1;
    temp_f0 = datScriptCalcFloat(0xD, 0);
    temp_f0 = temp_f0 / 5.0f;
    temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
    temp_f1 = sqrtf(temp_f0);
    temp_f20 = 10.0f * temp_f1;
    temp_f20 *= datScriptCalcFloat(0xC, 0);
    temp_f20 *= datScriptCalcFloat(0x17, 0);
    temp_f20 *= datScriptCalcFloat(0x1B, 0);
    temp_f1 = temp_f20 * datScriptCalcFloat(0x21, 0);
    temp_f0 = temp_f1 * fGpffff811c;
    datScriptSetResult(temp_f0);
}
// FUN_00246550
s32 func_00246550(void)
{
    func_00243ed0();
    return 1;
}
// FUN_00246580
s32 func_00246580(u8 *unusedTask)
{
    return 0;
}
// FUN_00246590
void func_00246590(u8 *unusedTask)
{
}
// Intent: Creates the model_neck_test debug task with the mdlNeckTest.c alloc site [inferred]
// FUN_002465A0
void mdlNeckTestCreate(void)
{
    chkmemAllocSiteTag(D_00635990, 0xD1);
    (s32)kwlnTaskCreate((const void *)(D_006359A0), 0xF, 0, 0, func_00246580, func_00246590, (u8 *)(D_008873F4[0](1, 8, 0x40000)));
}
// Intent: Starts the model_neck_test debug task by calling mdlNeckTestCreate [inferred]
// FUN_00246620
void mdlNeckTestStart(void)
{
    mdlNeckTestCreate();
}
// Intent: Reports whether the model_neck_test debug task exists [inferred]
// FUN_00246640
s32 mdlNeckTestExists(void)
{
    return kwlnTaskGetTaskByName(D_006359B0) != 0;
}
// Intent: Destroys the model_neck_test debug task, asserting it exists (niidaTestMenu.c) [inferred]
// FUN_00246670
void mdlNeckTestDestroy(void)
{
    s32 temp_2;

    temp_2 = kwlnTaskGetTaskByName(D_006359B0);
    if (temp_2 == 0) {
        kAssertFail(D_006359C0, 0x3D);
    }
    kwlnTaskDestroyWithHierarchy(temp_2);
}
// FUN_002466D0
void func_002466d0(void)
{
}
// FUN_002466E0
void func_002466e0(void)
{
}
// FUN_002466F0
void func_002466f0(void)
{
}
/* measured: optimization_level 1 preserves the saved task id across the guard. */
#pragma optimization_level 1
// FUN_00249B10
s32 func_00249b10(void)
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
    scrSetReturnInt(func_00107ac0(var_2 & 0xFFFF) & 0xFFFF);
    return 1;
}
// FUN_00249C40
s32 func_00249c40(void)
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
// FUN_00249D00
s32 func_00249d00(void)
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
// FUN_00249DE0
s32 func_00249de0(void)
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
// FUN_00249EE0
s32 func_00249ee0(void)
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
// FUN_00249FE0
s32 func_00249fe0(void)
{
    s32 sp2C;
    s32 sp28;
    s32 temp_16;
    temp_16 = scrGetParamInt(0);
    func_001104d0((s16)func_001060b0(), &sp2C, &sp28);
    scrSetReturnInt(func_002480e0(temp_16, sp2C, sp28));
    return 1;
}
// FUN_0024A060
s32 func_0024a060(void)
{
    s32 var_4;

    var_4 = scrGetParamInt(0) & 0xFFFF;
    if (var_4 == 0) {
        var_4 = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunitySetTableHead(var_4);
    return 1;
}
// FUN_0024A0E0
s32 func_0024a0e0(void)
{
    s32 var_4;

    var_4 = (cmmCommunityGetTableHead() & 0xFFFF) != 0;
    if (var_4 != 0) {
        var_4 = func_00247f60((s16)func_001060b0()) != 0;
    }
    scrSetReturnInt(var_4);
    return 1;
}
// FUN_0024A140
s32 func_0024a140(void)
{
    s32 temp_17;
    s32 var_16;
    temp_17 = func_00248040((s16)func_001060b0());
    var_16 = 0;
    if (temp_17 == ((s16)func_001060b0() + 1)) {
        var_16 = 1;
    } else if (func_00110580(temp_17) == 0) {
        var_16 = 2;
    } else if (func_00110d30(temp_17) != 0) {
        var_16 = 3;
    }
    scrSetReturnInt(var_16);
    return 1;
}