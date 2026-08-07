#include "include_asm.h"
#include "type.h"

extern s32 func_00106330(s32 arg0);
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
extern s32 func_00202340(u8 *arg0);
extern void func_00202070(void);

extern void func_00202180(void);

extern void func_00202640(void);

// FUN_00201280
void func_00201280(u8 *arg0, u8 *arg1) {
    func_00213ab0();
    func_0021ae60(arg0, arg1 + 0x18);
}



// FUN_00201300
void func_00201300(s32 *arg0, f32 fp0, f32 fp1, f32 fp2, f32 fp3) {
    arg0[1] = (s32)fp0;
    arg0[2] = (s32)fp1;
    arg0[3] = (s32)fp2;
    arg0[4] = (s32)fp3;
}

// FUN_00201650
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201650);

// FUN_00201A80
void func_00201a80(u8 *arg0) {
    s32 temp_4;
    u8 *temp_5;
    u8 *temp_5_2;

    temp_5 = (u8 *)(*(u8 **)(arg0 + 0));
    *(u16 *)(temp_5 + 0xA0) = (u16) (*(u16 *)(temp_5 + 0xA0) + 1);
    temp_5_2 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_5_2 + 0xA0) = (u16) (*(u16 *)(temp_5_2 + 0xA0) + 1);
    temp_4 = (s32)(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA64));
    if ((temp_4 != 0) && (func_00232710(temp_4, 0x100000) != 0)) {
        *(s32 *)(arg0 + 0x34) = 1;
        return;
    }
    *(s32 *)(arg0 + 0x34) = 0;
}

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
void func_00202400(s32 arg0, s32 arg1)
{
    u8 *temp_2;
    u8 *temp_3;

    temp_2 = (u8 *)func_00194470(0x506, 0xC);
    *(void **)(temp_2 + 0x6C) = (void *)func_00202340;
    temp_3 = *(u8 **)(temp_2 + 0x78);
    *(s32 *)(temp_3 + 0) = arg0;
    *(s32 *)(temp_3 + 4) = arg1;
    *(s32 *)(temp_3 + 8) = 0;
}

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
void func_00202e00(u8 *arg0, s16 *arg1)
{
    if (arg1 != NULL) {
        func_0043f810(arg0 + 0x2C, arg1, 8);
        return;
    }
    *(s16 *)(arg0 + 0x2C) = 0x1000;
    *(s16 *)(arg0 + 0x2E) = 0x4000;
    *(u16 *)(arg0 + 0x30) = 0x8000;
    *(s16 *)(arg0 + 0x32) = 0x2000;
}

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
void func_002089e0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[1] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[0] = *(s16 *)(arg0 + 2);
}

// FUN_002090D0
void func_002090d0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[3] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[2] = *(s16 *)(arg0 + 2);
}

// FUN_00209740
void func_00209740(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[5] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[4] = *(s16 *)(arg0 + 2);
}

// FUN_00209CD0
void func_00209cd0(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (func_00106330(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[7] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[6] = *(s16 *)(arg0 + 2);
}

// FUN_00209D40
void func_00209d40(u16 *arg0, u8 *arg1) {
    func_0045af60(0, 0, 0, 3);
    func_00202d20(arg0, 0, 0);
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x1C) = 0;
    *(s16 *)(arg1 + 0x1E) = 0;
}

// FUN_0020A5D0
void func_0020a5d0(u16 *arg0, u8 *arg1) {
    func_0045af60(0, 0, 0, 3);
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}

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
