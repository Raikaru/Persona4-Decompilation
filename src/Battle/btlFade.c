/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001FC230)
/* Source unit: src/Battle/btlFade_001fc230.c */
#include "type.h"

typedef struct BtlFadeWork {
    u8 state;
    u8 unk_01;
    u16 timer;
    u16 delay;
    s16 fadeType;
} BtlFadeWork;

extern BtlFadeWork D_00764558;

// FUN_001FC230
void btlFadeStart(u16 delay)
{
    D_00764558.timer = 0;
    D_00764558.delay = delay;
    D_00764558.state = 1;
}
#endif /* P4_UNIT_001FC230 */

#if defined(P4_UNIT_001FC250)
/* Source unit: src/Battle/btlFade_001fc250.c */
#include "type.h"

typedef struct BtlFadeWork {
    u8 state;
    u8 unk_01;
    u16 timer;
    u16 delay;
    s16 fadeType;
} BtlFadeWork;

extern BtlFadeWork D_00764558;

// FUN_001FC250
void btlFadeStartImmediate(void)
{
    D_00764558.timer = 0;
    D_00764558.delay = 0;
    D_00764558.state = 1;
}
#endif /* P4_UNIT_001FC250 */
