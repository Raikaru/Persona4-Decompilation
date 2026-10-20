/* Source unit: src/datCalendar.c (clndGetMoonPhase) */
#include "list_item_internal.h"
#include "type.h"

extern u8 D_0079B6D8[];

extern s32 calDayOfYearFromMonthDay(s32 month, s32 day);
extern s16 datGetDateIndex(void);



// FUN_00110830
u8 clndGetMoonPhase(s32 daysSinceApr5)
{
    return D_0079B6D8[daysSinceApr5];
}



/* Test the current date against inclusive endpoints within the same year. */
// FUN_0014BDB0
u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay)
{
    s32 startDate = calDayOfYearFromMonthDay(startMonth, startDay);
    s32 endDate = calDayOfYearFromMonthDay(endMonth, endDay);

    if (datGetDateIndex() >= startDate && datGetDateIndex() <= endDate)
    {
        return 1;
    }

    return 0;
}
