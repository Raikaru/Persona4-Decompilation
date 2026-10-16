#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
s32 kwlnTaskGetTaskByName(void *arg0);
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;

s16 datGetDateIndex(void);
void calSplitDayOfYear(s64 arg0, s32 *arg1, s32 *arg2);
s32 calGetWeekdayOfDay(s64 arg0);



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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 0025c310-0025c3e0 */

// FUN_0025C310
void func_0025c310(void) {
    kwlnTaskGetTaskByName(D_006367C0);
}

// FUN_0025C340
s32 scrCommonGetMonth(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    calSplitDayOfYear(datGetDateIndex(), &sp1C, &sp18);
    scrSetReturnInt(sp1C);
    return 1;
}

// FUN_0025C390
s32 scrCommonGetDay(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    calSplitDayOfYear(datGetDateIndex(), &sp1C, &sp18);
    scrSetReturnInt(sp18);
    return 1;
}

// FUN_0025C3E0
s32 K_Cmd_DATE_WEEKDAY(void) {
    scrSetReturnInt(calGetWeekdayOfDay(datGetDateIndex()));
    return 1;
}

