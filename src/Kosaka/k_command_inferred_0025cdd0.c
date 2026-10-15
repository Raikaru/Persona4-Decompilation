#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "datPersona_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;




float scrGetParamFloat(s32 arg0);
s16 datCategoryRankProgress(s16 arg0, float arg1);
s16 datCategoryRank(s16 arg0);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void func_0045dfd0(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Source unit: src/promoted/code1_0025.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 0025cdd0-0025cf70 */

// FUN_0025CDD0
s32 func_0025cdd0(void) {
    s32 temp_16;

    temp_16 = scrGetParamInt(0);
    scrSetReturnInt((s32)datCategoryRankProgress((s16)temp_16, scrGetParamFloat(1)));
    return 1;
}

// Intent: Common script command GET_PC_PARAM (p4flow Common 0x0044): returns the player character parameter [inferred]
// FUN_0025CE40
s32 scrCommonGetPcParam(void) {
    scrSetReturnInt((s32)datCategoryRank((s16)scrGetParamInt(0)));
    return 1;
}

/* measured: preserving the raw third-call result in s32 before masking the first two arguments reproduces retail's setup order; exact match nd 0 (obj 112B/window 112B). */
// FUN_0025CE90
s32 func_0025ce90(void) {
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;

    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    datPersonaAddStatById(temp_17 & 0xFFFF, temp_16 & 0xFFFF, (s8)temp_18);
    return 1;
}

// FUN_0025CF00
s32 func_0025cf00(void) {
    s32 temp_16;
    s32 temp_17;

    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    datPersonaAddToBonusStatByPcId(temp_17 & 0xFFFF, temp_16 & 0xFFFF, scrGetParamInt(2));
    return 1;
}

// FUN_0025CF70
s32 func_0025cf70(void) {
    s32 temp_16;
    s32 temp_17;

    temp_16 = scrGetParamInt(0);
    temp_17 = scrGetParamInt(1);
    scrSetReturnInt(datPersonaGetTotalStatById(temp_16 & 0xFFFF, temp_17 & 0xFFFF) & 0xFF);
    return 1;
}

