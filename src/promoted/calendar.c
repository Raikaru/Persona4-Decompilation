#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit calendar.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00452380();
extern u8 D_005E4FE8[];
extern u8 D_005E4FD8[];

extern s32 D_007242B4;
extern void (*jtbl_008873EC[])(void *);



// FUN_001211B0
INCLUDE_ASM("asm/nonmatchings/calendar", func_001211b0);

// FUN_00121280
s32 func_00121280(void)
{
    return (s32)(func_00452380(D_005E4FE8) != 0);
}

// FUN_001212B0
void func_001212b0(void)
{
    s32 handle = func_00452380(D_005E4FE8);

    if (handle == 0) {
        func_0046d730(D_005E4FD8, 0xA8);
    }
    func_00452080(handle);
}

// FUN_00121310
INCLUDE_ASM("asm/nonmatchings/calendar", func_00121310);
// FUN_00121660
void func_00121660(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B4 = 0;
    jtbl_008873EC[0](p);
}

// FUN_00121690
INCLUDE_ASM("asm/nonmatchings/calendar", func_00121690);

// FUN_00121940
INCLUDE_ASM("asm/nonmatchings/calendar", func_00121940);

// FUN_00121A20
INCLUDE_ASM("asm/nonmatchings/calendar", func_00121a20);