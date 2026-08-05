#include "include_asm.h"
#include "type.h"

extern void func_00213ab0();
extern void func_0021ae60(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern void func_00202e00(u8 *arg0, s16 *arg1);

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

extern u8 *func_00452560();
extern void func_002119a0(u8 *arg0);



extern void *func_00194470(u32 id, u32 size);
extern void func_00202070(void);

extern void func_00202180(void);

extern void func_00202640(void);

// FUN_00201280
void func_00201280(u8 *arg0, u8 *arg1) {
    func_00213ab0();
    func_0021ae60(arg0, arg1 + 0x18);
}



// FUN_00201300
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201300);

// FUN_00201650
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201650);

// FUN_00201A80
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201a80);

// FUN_00202120
void func_00202120(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x505, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)func_00202070;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_002022E0
void func_002022e0(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x507, 0xc);
  *(void **)(iVar2 + 0x6c) = (void *)func_00202180;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}

// FUN_00202400
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202400);

// FUN_00202460
void func_00202460(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00202570
void func_00202570(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00202620
void func_00202620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00202720
void func_00202720(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00202740
u8 *func_00202740(u8 *unit)
{
    u8 *packet;

    packet = (u8 *)func_00194470(0x501, 4);
    *(u8 *)(packet + 71) &= ~(1 << 4);
    *(void **)(packet + 0x68) = (void *)func_00202620;
    *(void **)(packet + 0x6C) = (void *)func_00202640;
    *(void **)(packet + 0x70) = (void *)func_00202720;
    *(u8 **)*(u8 **)(packet + 0x78) = unit;

    return packet;
}

// FUN_00202C60
void func_00202c60(u8 *arg0, s16 arg1, s16 arg2, void *arg3, void *arg4, void *arg5, void *arg6, u8 *arg7) {
    memset(arg0, 0, 0x34);
    *(s16 *)(arg0 + 6) = arg1;
    *(s16 *)(arg0 + 8) = arg2;
    *(void **)(arg0 + 0xC) = arg3;
    *(void **)(arg0 + 0x10) = arg4;
    *(void **)(arg0 + 0x14) = arg5;
    *(void **)(arg0 + 0x1C) = arg6;
    *(u8 **)(arg0 + 0x28) = arg7;
    *(u16 *)(arg0 + 0) |= 8;
    func_00202e00(arg0, NULL);
}



// FUN_00202E00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202e00);

// FUN_00202E60
void func_00202e60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x18) = arg1;
}

// FUN_00203360
void func_00203360(u8 *arg0, u8 *arg1) {
    u8 *temp_16;
    u8 *var_4;

    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(u8 **)(arg0 + 0xC) = arg1;
    *(u8 **)(arg0 + 8) = arg1;
    var_4 = arg1;
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0xC))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
}



// FUN_002033C0
void func_002033c0(u8 *arg0) {
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(arg0 + 8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0x1C))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
    *(u8 **)(arg0 + 8) = NULL;
}



// FUN_002035A0
void func_002035a0(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        (*(void (**)(u8 *, s32, u8 *))(var_16 + 0x14))(var_16, *(s32 *)(var_16 + 0x28), arg0);
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}



// FUN_00203600
void func_00203600(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        void (*fn)(u8 *, s32, u8 *) = *(void (**)(u8 *, s32, u8 *))(var_16 + 0x18);
        if (fn != NULL) {
            fn(var_16, *(s32 *)(var_16 + 0x28), arg0);
        }
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}



// FUN_00203880
void func_00203880(void)
{
}

// FUN_002038C0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002038c0);

// FUN_00204D90
void func_00204d90(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0xA0) = *(s32 *)(p + 0xA0) | 0x1;
}

// FUN_002089E0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002089e0);

// FUN_002090D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002090d0);

// FUN_00209740
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209740);

// FUN_00209CD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209cd0);

// FUN_00209D40
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209d40);

// FUN_0020A5D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020a5d0);

// FUN_0020AD70
void func_0020ad70(void)
{
}

// FUN_0020AD80
void func_0020ad80(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x5B4);
    *(s32 *)(arg0 + 0x5B0) = arg1;
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 0x5AC) = -1;
}



// FUN_0020B5A0
void func_0020b5a0(void)
{
}

// FUN_0020BAC0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020bac0);

// FUN_0020BB20
void func_0020bb20(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x1C);
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 2) = 3;
}



// FUN_0020E1D0
void func_0020e1d0(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 3;
    *(u16 *)(arg0 + 0x10) &= 0xFFFE;
    *(u16 *)(arg0 + 0x10) &= 0xFFFD;
    *(s16 *)(arg1 + 4) = 0;
    *(s16 *)(arg1 + 2) = 2;
    *(u16 *)(arg1 + 0x10) &= 0xFFF7;
    *(u16 *)(arg1 + 0x10) &= 0xFFFB;
    *(u16 *)(arg1 + 0x10) &= 0xFFFD;
    *(u16 *)(arg1 + 0x10) |= 1;
    *(Vec2f *)(arg1 + 8) = *(Vec2f *)(arg0 + 8);
}



// FUN_0020E3F0
void func_0020e3f0(void) {
    func_002119a0(func_00452560() + 0x75C);
}
