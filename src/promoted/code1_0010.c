#include "include_asm.h"
#include "type.h"

extern u8 *D_00764298;
extern void func_00440b68();
extern s32 func_00100230(void);
extern void func_00101350(void);
extern u8 D_00559810[];
extern u8 D_00559820[];



// FUN_00100008
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100008);
// FUN_00100218
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100218);
// FUN_00100220
asm void func_00100220(void)
{
    addiu $3, $0, 0x23
    syscall 0
}



// FUN_00100230
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100230);
// FUN_001002C0
s32 func_001002c0(void) {
    s32 r;

    func_00440b68(D_00559810);
    r = func_00100230();
    func_00440b68(D_00559820, r);
    func_00101350();
    return 1;
}

// FUN_00100310
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100310);
// FUN_00100350
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100350);
// FUN_00100670
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100670);
// FUN_00100E30
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100e30);
// FUN_00100E60
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00100e60);
// FUN_00101270
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00101270);
// FUN_00101350
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00101350);
// FUN_00102780
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00102780);
// FUN_00102890
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00102890);
// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}

// FUN_00102B90
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00102b90);
// FUN_00102BB0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00102bb0);
// FUN_00103510
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103510);
// FUN_00103540
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103540);
// FUN_00103570
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103570);
// FUN_00103590
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103590);
// FUN_001035A0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001035a0);
// FUN_00103600
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103600);
// FUN_001036D0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001036d0);
// FUN_00103980
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103980);
// FUN_001039E0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001039e0);
// FUN_00103A60
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103a60);
// FUN_00103B00
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103b00);
// FUN_00103C40
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103c40);
// FUN_00103F00
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00103f00);
// FUN_001044D0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001044d0);
// FUN_00104510
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00104510);
// FUN_00104770
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00104770);
// FUN_001047B0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001047b0);
// FUN_00104830
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00104830);
// FUN_00104880
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_00104880);
// FUN_001048C0
INCLUDE_ASM("asm/nonmatchings/code1_0010", func_001048c0);