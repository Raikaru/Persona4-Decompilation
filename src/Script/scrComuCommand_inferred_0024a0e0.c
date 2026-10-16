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
extern s64 datGetDateIndex(void);
extern s32 cmmNextUnlistedDate(s32 arg0);
extern s32 calGetWeekdayOfDay(s32 arg0);
extern s32 calHasDayEntry(s32 arg0);
extern s32 cmmCommunityGetTableHead(void);
extern s32 cmmDateNotListed(s32 arg0);

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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 0024a0e0-0024a140 */

extern s32 cmmEnsureRecord(void);
/* measured: optimization_level 1 preserves the saved task id across the guard. */
/* measured: closes optimization_level 1 around func_00249b10. */
// Returns 1 when the community table has entries and today's date is not yet listed, else 0 [inferred].
// FUN_0024A0E0
s32 cmmTodayNotListed(void)
{
    s32 var_4;

    var_4 = (cmmCommunityGetTableHead() & 0xFFFF) != 0;
    if (var_4 != 0) {
        var_4 = cmmDateNotListed((s16)datGetDateIndex()) != 0;
    }
    scrSetReturnInt(var_4);
    return 1;
}

// Classifies the next unlisted date: 1 when it is tomorrow, 2 when it falls on weekday 0, 3 when it has a day entry, else 0 [inferred].
// FUN_0024A140
s32 cmmNextUnlistedDateKind(void)
{
    s32 temp_17;
    s32 var_16;
    temp_17 = cmmNextUnlistedDate((s16)datGetDateIndex());
    var_16 = 0;
    if (temp_17 == ((s16)datGetDateIndex() + 1)) {
        var_16 = 1;
    } else if (calGetWeekdayOfDay(temp_17) == 0) {
        var_16 = 2;
    } else if (calHasDayEntry(temp_17) != 0) {
        var_16 = 3;
    }
    scrSetReturnInt(var_16);
    return 1;
}
