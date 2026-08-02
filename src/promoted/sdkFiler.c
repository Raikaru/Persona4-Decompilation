/* Consolidated Persona 4 source units. */
/* Original translation unit sdkFiler.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern void (*jtbl_008873EC[])(void *ptr);


extern void strcpy(s8 *arg0, s32 *arg1);
extern void func_00452080(u8 *arg0);




// FUN_00468170
INCLUDE_ASM("asm/nonmatchings/sdkFiler", func_00468170);

// FUN_00468260
INCLUDE_ASM("asm/nonmatchings/sdkFiler", func_00468260);

// FUN_004685C0
INCLUDE_ASM("asm/nonmatchings/sdkFiler", func_004685c0);

// FUN_004688A0
void func_004688a0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_004688D0
s32 func_004688d0(u8 *arg0, s8 *arg1)
{
    s32 *temp_16 = *(s32 **)(arg0 + 0x38);

    strcpy(arg1, (s32 *)((u8 *)temp_16 + 0x10));
    if (*temp_16 == 2) {
        func_00452080(arg0);
        return 1;
    }
    return 0;
}

// FUN_00468940
INCLUDE_ASM("asm/nonmatchings/sdkFiler", func_00468940);

