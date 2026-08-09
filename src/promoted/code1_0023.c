#include "include_asm.h"
#include "type.h"

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;
extern void func_0045a9a0(s32 arg0, s32 arg1);

extern void func_00231380(s32 *arg0, s32 arg1);



// FUN_002305C0
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_002305c0);
// FUN_00230610
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230610);
// FUN_00230650
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230650);
// FUN_00230690
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230690);
// FUN_002306D0
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_002306d0);
// FUN_00230710
s32 func_00230710(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB94) != 0) {
        func_0045a9a0(2, 0);
    }
    return 1;
}



// FUN_00230750
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230750);
// FUN_00230790
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230790);
// FUN_002308A0
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_002308a0);
// FUN_00230C00
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230c00);
// FUN_00230D30
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230d30);
// FUN_00231380
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00231380);
// FUN_00231550
void func_00231550(s32 arg0, s32 arg1)
{
    func_00231380((s32 *)arg0, arg1 & 0xFFFF);
}
