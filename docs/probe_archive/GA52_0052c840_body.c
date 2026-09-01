/* archived best measured attempt: object=52 window=48 normalized_diff=35. */
#include "type.h"
s32 func_0052c840(u8 *arg0)
{
    f32 zero = 0.0f;
    f32 value0 = *(f32 *)(arg0 + 0x3C);
    f32 value1;
    s32 result = 1;

    if (value0 == zero) {
        value1 = *(f32 *)(arg0 + 0x40);
        if (value1 == zero) {
            result = 0;
        }
    }
    return result;
}
