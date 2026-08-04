#include "include_asm.h"
#include "type.h"
extern void func_004787e0();

extern void func_004841c0(s32 arg0);
extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern f32 D_00922D80[];
extern void func_003e9c10(s32 arg0, f32 *arg1, s32 arg2);

extern void func_004a7c00(u8 *arg0, s32 arg1);

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);



// FUN_004A22C0
void func_004a22c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A35F0
void func_004a35f0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A49C0
void func_004a49c0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    func_004841c0(*(s32 *)(temp_16 + 4));
    D_008873ec[0](*(void **)(temp_16 + 8));
}



// FUN_004A58B0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a58b0);

// FUN_004A59B0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a59b0);

// FUN_004A5A00
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5a00);

// FUN_004A5A60
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5a60);

// FUN_004A5B60
void func_004a5b60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x30) = arg1;
}

// FUN_004A5DE0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a5de0);

// FUN_004A5F90
void func_004a5f90(u8 *arg0)
{
    *(s32 *)(arg0 + 0x2C) = 0;
}

// FUN_004A6BE0
void func_004a6be0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}

// FUN_004A6DC0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a6dc0);

// FUN_004A6E40
void func_004a6e40(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

// FUN_004A77B0
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a77b0);

// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}



// FUN_004A7A90
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7a90);

// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10(D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}



// FUN_004A7B70
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004a7b70);

// FUN_004A7BF0
void func_004a7bf0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x0) = 0;
}

// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004A7DE0
void func_004a7de0(void) {
}



// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}



// FUN_004ABB60
INCLUDE_ASM("asm/nonmatchings/code1_004a", func_004abb60);

// FUN_004ABD60
void func_004abd60(void)
{
    func_004787e0();
}

// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}
