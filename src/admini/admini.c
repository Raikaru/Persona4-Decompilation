/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00456690)
/* Source unit: src/admini/admini_00456690.c */
#include "type.h"

s32 func_004244c8(const char* format, ...);
extern char D_00711708[];

// FUN_00456690
s32 adminiSeqExitTest(void)
{
    func_004244c8(D_00711708);
    return 0;
}
#endif /* P4_UNIT_00456690 */
