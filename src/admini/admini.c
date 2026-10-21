#include "type.h"

s32 func_004244c8(const char* format, ...);
extern char D_00711708[];


/* HDD file-device exit-test callback: print " HDD EOF \n" and always return zero. */
// FUN_00456690
s32 adminiSeqExitTest(void)
{
    func_004244c8(D_00711708);
    return 0;
}
