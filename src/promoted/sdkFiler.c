/* Consolidated Persona 4 source units. */
/* Original translation unit sdkFiler.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void strcpy(s8 *arg0, s32 *arg1);
extern void func_00452080(u8 *arg0);



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
