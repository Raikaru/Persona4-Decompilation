/* Consolidated Persona 4 source units. */
/* Original translation unit fclBankManager.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

// P4 retail reaches this object at gp-0x4A78, i.e. absolute 0x007690f0 - 0x4a78
// = 0x00724678, GP-relative.
extern int iGpffffb588;



// FUN_002E0F90
void func_002e0f90(void)
{
    *(s32 *)(*(int *)(iGpffffb588 + 0x24) + 0x2C) |= 1;
}
