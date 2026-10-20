#include "include_asm.h"
#include "type.h"

extern s32 D_00745AF8;

extern s32 D_00745ABC;

extern s32 D_007609B0[];

extern s32 D_00745C84;

extern s32 D_00745C6C;

extern s32 D_0074613C;

/* func_0052c890, func_0050d088 and func_005249b0 still build with larger frames and sq saves where
 * retail uses sd saves; cause unknown. */

typedef void (*Code1B9Callback)(s32 first, s32 second, void *data);
typedef struct {
    Code1B9Callback callback;
    s32 second;
    s32 count;
} Code1B9Work;

extern s32 *func_00528c30(void);
extern void func_0052c870(s32 first);
typedef struct {
    s64 total;
    s64 min;
    s64 max;
    s32 count;
} RunningStat;
/* Accumulate one signed 64-bit sample and update the extrema and sample count. */
// FUN_0052D9A0
void RunningStatAdd(RunningStat *stats, s64 value)
{
    stats->total += value;
    stats->min = (value < stats->min) ? value : stats->min;
    stats->max = (stats->max < value) ? value : stats->max;
    stats->count++;
}

