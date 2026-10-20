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
extern s32 cmmNextUnlistedDate(s32 startDate);
extern s32 calGetWeekdayOfDay(s32 dateIndex);
extern s32 calHasDayEntry(s32 day);
extern s32 cmmCommunityGetTableHead(void);
extern s32 cmmDateNotListed(s32 value);

extern f32 D_00761260;
extern f32 fGpffff811c;

extern s32 cmmEnsureRecord(void);
/* Script command 0x3018: returns 1 when the community table has entries and today's date is not yet
 * listed, else 0. */
// FUN_0024A0E0
s32 cmmTodayNotListed(void)
{
    s32 notListed;

    notListed = (cmmCommunityGetTableHead() & 0xFFFF) != 0;
    if (notListed != 0) {
        notListed = cmmDateNotListed((s16)datGetDateIndex()) != 0;
    }
    scrSetReturnInt(notListed);
    return 1;
}

// Classifies the next unlisted date: 1 when it is tomorrow, 2 when it falls on weekday 0, 3 when it
// has a day entry, else 0.
// FUN_0024A140
s32 cmmNextUnlistedDateKind(void)
{
    s32 date;
    s32 kind;
    date = cmmNextUnlistedDate((s16)datGetDateIndex());
    kind = 0;
    if (date == ((s16)datGetDateIndex() + 1)) {
        kind = 1;
    } else if (calGetWeekdayOfDay(date) == 0) {
        kind = 2;
    } else if (calHasDayEntry(date) != 0) {
        kind = 3;
    }
    scrSetReturnInt(kind);
    return 1;
}
