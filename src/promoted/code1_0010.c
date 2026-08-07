#include "include_asm.h"
#include "type.h"

extern u8 *D_00764298;
extern void func_00440b68();
extern s32 func_00100230(void);
extern void func_00101350(void);
extern u8 D_00559810[];
extern u8 D_00559820[];



// FUN_00100220
asm void func_00100220(void)
{
    addiu $3, $0, 0x23
    syscall 0
}



// FUN_001002C0
s32 func_001002c0(void) {
    s32 r;

    func_00440b68(D_00559810);
    r = func_00100230();
    func_00440b68(D_00559820, r);
    func_00101350();
    return 1;
}

// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}
