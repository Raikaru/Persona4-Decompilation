#include "type.h"

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;
extern void func_0045a9a0(s32 arg0, s32 arg1);

extern void func_00231380(s32 *arg0, s32 arg1);



// FUN_00230710
s32 func_00230710(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB94) != 0) {
        func_0045a9a0(2, 0);
    }
    return 1;
}



// FUN_00231550
void func_00231550(s32 arg0, s32 arg1)
{
    func_00231380((s32 *)arg0, arg1 & 0xFFFF);
}
