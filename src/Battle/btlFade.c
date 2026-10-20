/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef struct BtlFadeWork {
    u8 state;
    u8 unk_01;
    u16 timer;
    u16 delay;
    s16 fadeType;
} BtlFadeWork;

extern BtlFadeWork D_00764558;

/* Restart the fade controller with the caller's delay before its active phase. */
// FUN_001FC230
void btlFadeStart(u16 delay)
{
    D_00764558.timer = 0;
    D_00764558.delay = delay;
    D_00764558.state = 1;
}

/* Restart the fade controller without waiting before its active phase. */
// FUN_001FC250
void btlFadeStartImmediate(void)
{
    D_00764558.timer = 0;
    D_00764558.delay = 0;
    D_00764558.state = 1;
}
