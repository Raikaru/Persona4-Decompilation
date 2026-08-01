/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001026B0)
/* Source unit: src/Kosaka/Field/k_shadow.c */
#include "type.h"

// FUN_001026B0
s32 func_001026b0(void)
{
    volatile u64* intcStat = (volatile u64*)0x12001000;

    if (((*intcStat >> 13) & 1) == 0)
    {
        __asm__ volatile (
            ".set noreorder\n"
            "sync\n"
            "ei\n"
            ".set reorder"
            :
            :
            : "memory"
        );
        return -1;
    }

    __asm__ volatile (
        ".set noreorder\n"
        "sync\n"
        "ei\n"
        ".set reorder"
        :
        :
        : "memory"
    );
    return 0;
}
#endif /* P4_UNIT_001026B0 */

#if defined(P4_UNIT_001026F0)
/* Source unit: src/Kosaka/Field/k_shadow.c */
#include "type.h"

// P3 donor: AddIntcHandler/EnableIntc/RemoveIntcHandler (00502e40/00503ca8/00502e60),
// DAT_007cc148 -> D_007616AC, DAT_007ce13c -> D_00764294 per map_shared_p3.py.
extern s32 func_001026b0();
extern s32 func_004214c0(s32 cause, s32 (*handler)(s32), s32 mode);
extern s32 func_00422328(s32 cause);
extern s32 func_004214e0(s32 cause, s32 handle);
extern s32 D_007616AC;
extern s32 D_00764294;

// FUN_001026F0
s32 func_001026f0(void)
{
    s32 handle;

    handle = func_004214c0(2, (s32 (*)(s32))func_001026b0, 0);
    D_007616AC = handle;
    if (handle == -1)
    {
        return 0;
    }

    handle = func_00422328(2);
    D_00764294 = handle;
    if (handle == -1)
    {
        func_004214e0(2, D_007616AC);
        D_007616AC = -1;
        return 0;
    }

    return 1;
}
#endif /* P4_UNIT_001026F0 */
