/* Source unit: src/datCalendar.c (clndGetMoonPhase) */
#include "type.h"

extern u8 D_0079B6D8[];

extern s32 func_00110600(s32 month, s32 day);
extern s16 func_001060b0(void);



// FUN_00110830
u8 clndGetMoonPhase(u32 daysSinceApr5)
{
    return D_0079B6D8[daysSinceApr5];
}



// FUN_0014BDB0
u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay)
{
    s32 startDate = func_00110600(startMonth, startDay);
    s32 endDate = func_00110600(endMonth, endDay);

    if (func_001060b0() >= startDate && func_001060b0() <= endDate)
    {
        return 1;
    }

    return 0;
}
