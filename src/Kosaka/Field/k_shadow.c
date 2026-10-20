/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

// FUN_001026B0
s32 FldShadow_PollIntcBit13(void)
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

// Matches P3 AddIntcHandler/EnableIntc/RemoveIntcHandler (00502e40/00503ca8/00502e60).
extern s32 FldShadow_PollIntcBit13();
extern s32 func_004214c0(s32 cause, s32 (*handler)(s32), s32 mode);
extern s32 func_00422328(s32 cause);
extern s32 RemoveIntcHandler(s32 cause, s32 handle);
extern s32 D_007616AC;
extern s32 D_00764294;

/* Register and enable INTC channel 2 for shadow polling; remove the handler if enabling fails. */
// FUN_001026F0
s32 FldShadow_InstallIntcHandler(void)
{
    s32 handle;

    handle = func_004214c0(2, (s32 (*)(s32))FldShadow_PollIntcBit13, 0);
    D_007616AC = handle;
    if (handle == -1)
    {
        return 0;
    }

    handle = func_00422328(2);
    D_00764294 = handle;
    if (handle == -1)
    {
        RemoveIntcHandler(2, D_007616AC);
        D_007616AC = -1;
        return 0;
    }

    return 1;
}
