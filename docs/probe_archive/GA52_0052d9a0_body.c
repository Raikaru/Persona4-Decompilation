/* floor: ee-gcc 2.96 -O2 -G0, object 60B / retail 96B (60B code + 36B zero pad), 2 differing words: retail movn-max,daddu,movn-min vs object movn-max,movn-min,daddu (adjacent swap). No source order among min/max/total/count gives retail NDN under 2.96 -O2 (24/24 orders give NND); MWCC b210/b119 give branches (no movn), ee-gcc 3.2 gives NND with t-reg colors (14 words). */
#include "type.h"
typedef struct {
    s64 total;
    s64 min;
    s64 max;
    s32 count;
} StatAccum52;
void func_0052d9a0(StatAccum52 *arg0, s64 arg1)
{
    s64 total = arg0->total;
    s64 mn = arg0->min;
    s64 mx = arg0->max;
    s32 count = arg0->count;

    if (mx < arg1) {
        mx = arg1;
    }
    if (arg1 < mn) {
        mn = arg1;
    }
    total += arg1;
    count += 1;
    arg0->total = total;
    arg0->min = mn;
    arg0->max = mx;
    arg0->count = count;
}
