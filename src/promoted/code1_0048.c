#include "include_asm.h"
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700();
void func_003e9cb0(void *frame, void *matrix, u32 flags);

void func_00483810();

extern u8 D_00713480[];



extern void (*jtbl_008873EC[])();

// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_00484510
void func_00484510(void)
{
}

// FUN_00484520
void func_00484520(void)
{
}

// FUN_00484530
s32 func_00484530(void)
{
    return 0;
}

// FUN_00484540
void func_00484540(void)
{
}

// FUN_00484550
void func_00484550(void)
{
}

// FUN_00484560
s32 func_00484560(void)
{
    return 1;
}

// FUN_00484790
void func_00484790(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        *(u8 **)(arg0 + 0x18) = NULL;
    }
}

// FUN_004847E0
void func_004847e0(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u8 **)(arg0 + 0x28) = NULL;
    }
}

// FUN_00484970
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484970);

// FUN_00484A40
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484a40);

// FUN_00484A90
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484a90);

// FUN_00484AE0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484ae0);

// FUN_00484B30
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484b30);

// FUN_00485FE0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485fe0);

// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}
