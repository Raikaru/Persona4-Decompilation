#include "include_asm.h"
#include "type.h"
extern u8 * iGpffff9db0;
extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 D_00762EA0;

extern s32 func_00145540(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_007642E4;

typedef struct { f32 x, y, z; } SVec3;

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;



// FUN_00142130
void func_00142130(u8 *arg0) {
    *(f32 *)(arg0 + 0x250) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0x42C80000;
    *(s32 *)(arg0 + 0x220) = 0x42C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(s32 *)(arg0 + 0x708) = 0xC3160000;
    *(s32 *)(arg0 + 0x6D8) = 0xC2C80000;
    *(s32 *)(arg0 + 0x738) = 0xC2C80000;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_001421B0
void func_001421b0(u8 *arg0) {
    *(s32 *)(arg0 + 0x250) = 0xC3160000;
    *(s32 *)(arg0 + 0x258) = 0;
    *(s32 *)(arg0 + 0x1F0) = 0xC2C80000;
    *(s32 *)(arg0 + 0x220) = 0xC2C80000;
    *(u8 *)(arg0 + 0x208) = 0;
    *(u8 *)(arg0 + 0x209) = 0xFF;
    *(u8 *)(arg0 + 0x238) = 0;
    *(u8 *)(arg0 + 0x239) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0xFF;
    *(f32 *)(arg0 + 0x708) = (f32) 0x28A;
    *(s32 *)(arg0 + 0x6D8) = 0x42C80000;
    *(s32 *)(arg0 + 0x738) = 0x42C80000;
    *(u8 *)(arg0 + 0x778) = 0xFF;
    *(u8 *)(arg0 + 0x718) = 0xFF;
    *(u8 *)(arg0 + 0x6E8) = 0xFF;
    *(u8 *)(arg0 + 0x748) = 0xFF;
    *(u8 *)(arg0 + 0x7A8) = 0xFF;
    *(s16 *)(arg0 + 0x20) = 0;
}



// FUN_00142230
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142230);

// FUN_00142340
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00142340);

// FUN_00143B70
void func_00143b70(void)
{
}

// FUN_00143B80
void func_00143b80(void)
{
}

// FUN_00143B90
void func_00143b90(void)
{
}

// FUN_00144AC0
void func_00144ac0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00145250
s32 func_00145250(void) {
    return D_00762EA0;
}



// FUN_001452B0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001452b0);

// FUN_00145510
void func_00145510(s32 arg0, s32 arg1) {
    func_00145540(arg0, 0, arg1);
}



// FUN_001475C0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_001475c0);

// FUN_00149620
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149620);

// FUN_00149680
void func_00149680(s32 arg0) {
    D_007642E4 = arg0;
}



// FUN_00149D60
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149d60);

// FUN_00149DB0
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149db0);

// FUN_00149E00
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149e00);

// FUN_00149E50
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_00149e50);

// FUN_0014A190
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014a190);

// FUN_0014A2F0
void func_0014a2f0(s32 arg0)
{
    *(s32 *)(iGpffff9db0 + 0x18) = arg0;
}

// FUN_0014B510
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014b510);

// FUN_0014B840
void func_0014b840(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014D470
INCLUDE_ASM("asm/nonmatchings/code1_0014", func_0014d470);

// FUN_0014D4E0
void func_0014d4e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014D7D0
void func_0014d7d0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014D9E0
void func_0014d9e0(u8 *arg0, u8 *arg1) {
    *(SVec3 *)(*(u8 **)(arg0 + 0x38) + 4) = *(SVec3 *)arg1;
}



// FUN_0014DCD0
void func_0014dcd0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x44) = arg1;
}

// FUN_0014DD10
void func_0014dd10(u8 *arg0, u8 *arg1) {
    f32 sp20[4];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(SVec3 *)(temp_16 + 0x30) = *(SVec3 *)arg1;
    RwEngineGetMatrixTolerances(&sp20[0]);
    RwMatrixOptimize(temp_16, &sp20[0]);
    RwMatrixUpdate(temp_16);
}



// FUN_0014EC20
void func_0014ec20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_0014EEC0
s32 func_0014eec0(void) {
    return D_007642F0;
}
