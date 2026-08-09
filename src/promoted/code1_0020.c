#include "include_asm.h"
#include "type.h"
extern void func_00113500(void);
extern void func_00113480(s16 a0, s16 a1, s16 a2, s16 a3);
extern void func_0046b260(void *arg0);
extern void func_0046b2f0(void *arg0);
extern s32 func_00201ee0(void);
extern s32 func_00202820(void);
extern void func_0021afa0(s32 arg0);
extern void func_0020e3f0();

extern s32 func_00106330(s32 arg0);
extern void func_00213ab0();
extern void func_0021ae60(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern void func_00202e00(u8 *arg0, s16 *arg1);
extern void func_00202460(u8 *arg0);
extern s32 func_00202480(u8 *arg0);
extern void func_00202570(u8 *arg0);
extern s32 func_001067f0(s16 arg0);

typedef struct {
    f32 x;
    f32 y;
} Vec2f;
static inline f32 func_0020_mul(f32 left, f32 right)
{
    return left * right;
}

extern u8 *func_00452560();
extern u32 func_001d8bc0(u8 *arg0);
extern void func_00201410(u8 *arg0, s32 a, s32 b);
extern void func_0011b360(s32 arg0);
extern void func_002119a0(u8 *arg0);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern void func_00216b40(s32 arg0, s32 arg1);
extern void func_00216bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00216d10(s32 arg0);



extern void *func_00194470(u32 id, u32 size);
extern s32 func_00202340(u8 *arg0);
extern s32 func_00202070(u8 *arg0);

extern void func_00202180(void);

extern s32 func_00202640(u8 *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626500[];
extern u8 D_006265B0[];
extern void func_0044ea90(const void *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00451fc0(s32 arg0, const void *data, s32 prio, s32 a3,
                         s32 a4, void *init, void *close, void *work);
extern s32 func_00200cf0(u8 *arg0);
extern void func_00200f30(void);
extern void func_00200fd0(s32 arg0, u8 *arg1);
extern s32 func_00201b00(u8 *arg0);
extern void func_00201db0(void *arg0);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_002777f0(s32 arg0);
extern void func_0046b0d0(void *arg0);
extern s16 func_00231ed0(s32 arg0);
extern s16 func_00231f80(s32 arg0);
extern void func_004abd60(s32 arg0);
extern void func_004b5790(void *arg0, void *arg1);
extern u8 D_00625240[];
extern void func_00213b50(s32 arg0);
extern void func_00213b80(s32 arg0);
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern s32 func_00200ce0(void);
extern void func_00205170(void);
extern void func_00205ff0(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          void (*callback)(void), u8 *arg3);
extern void func_002055d0(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern void func_00201820(s32 arg0);
extern void func_00205c20(void);
extern void func_00205950(void);
extern s32 func_00202e70(void);
extern s16 func_00243920(u16 arg0);

// FUN_00200720
void func_00200720(s32 *arg0) {
    s32 temp_4;

    temp_4 = *arg0;
    if (temp_4 != 0) {
        func_004abd60(temp_4);
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00200770
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200770);
// FUN_00200960
void func_00200960(void) {
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
}
/* measured: low-bit OR destination and FP scratch residual remain. Committed at nd 7. */
// FUN_00200980
#ifdef NON_MATCHING
void func_00200980(u8 *arg0)
{
    s32 temp_3;
    s32 temp_5;
    u8 *temp_6;
    u32 temp_7;
    u32 temp_8;
    f32 var_f1;
    f32 var_f0;
    f32 temp_f2;

    temp_6 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(arg0 + 0x28);
    temp_5 = *(s32 *)(temp_6 + 0);
    if ((temp_5 == 0) || ((u32)temp_5 < (u32)temp_3)) {
        return;
    }
    temp_f2 = *(f32 *)(temp_6 + 4);
    if (temp_3 >= 0) {
        var_f1 = (f32)temp_3;
    } else {
        temp_7 = (u32)temp_3 >> 1;
        temp_8 = (u32)temp_3 & 1;
        temp_7 |= temp_8;
        var_f1 = (f32)(s32)temp_7;
        var_f1 += var_f1;
    }
    if (temp_5 >= 0) {
        var_f0 = (f32)temp_5;
    } else {
        temp_7 = (u32)temp_5;
        var_f0 = (f32)(s32)((temp_7 >> 1) | (temp_7 & 1));
        var_f0 += var_f0;
    }
    var_f1 /= var_f0;
    var_f0 = *(f32 *)(temp_6 + 8) - temp_f2;
    var_f0 = func_0020_mul(var_f1, var_f0);
    var_f1 = var_f0 + temp_f2;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff81a8 * var_f1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200980);
#endif
// FUN_00200A50
void func_00200a50(void)
{
}
// FUN_00200A60
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200a60);
// FUN_00200C50
void func_00200c50(void)
{
    func_00113500();
}
// FUN_00200C70
void func_00200c70(u8 *arg0)
{
    u8 *temp_7;

    temp_7 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(arg0 + 0x28) == 0) {
        func_00113480(*(s16 *)(temp_7 + 0),
                      *(s16 *)(temp_7 + 4),
                      *(s16 *)(temp_7 + 8),
                      *(s16 *)(temp_7 + 0xC));
    }
}
// FUN_00200CB0
void func_00200cb0(void) {
    func_004b5790((void *)&D_00625240, (void *)func_00200ce0);
}
// FUN_00200CE0
s32 func_00200ce0(void)
{
    return D_0076449C != NULL;
}
// FUN_00200CF0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200cf0);
// FUN_00200F30
void func_00200f30(void)
{
    u8 *temp_2;
    s32 temp_4;
    s32 var_16;

    temp_2 = (u8 *)func_00452560();
    func_002119a0(temp_2 + 0x75C);
    var_16 = 0;
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(temp_2 + (var_16 * 4) + 0x2C);
    if (temp_4 != 0) {
        func_0046b0d0((void *)temp_4);
    }
    var_16 += 1;
loop_test:
    if (var_16 < 0xC) {
        goto loop_body;
    }
    goto loop_done;
loop_done:
    func_002777f0(*(s32 *)(temp_2 + 0x98));
    jtbl_008873EC[0](temp_2);
}
// FUN_00200FD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00200fd0);
// FUN_002011C0
s32 func_002011c0(s32 arg0)
{
    u8 *temp_2_2;
    s32 temp_2;

    func_0044ea90(&D_006265B0, 0x3A);
    temp_2_2 = (u8 *)(*jtbl_008873E8)(0xA20, 0x40000);
    func_0043f9c8(temp_2_2, 0, 0xA20);
    temp_2 = func_00451fc0(arg0, &D_00626500, 0xF, 0, 0,
                           (void *)func_00200cf0,
                           (void *)func_00200f30, temp_2_2);
    func_00200fd0(temp_2, temp_2_2);
    return temp_2;
}
// FUN_00201280
void func_00201280(u8 *arg0, u8 *arg1) {
    func_00213ab0();
    func_0021ae60(arg0, arg1 + 0x18);
}



// FUN_002012D0
void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1) {
    *(s32 *)(arg0 + 4) = (s32)fparg0;
    *(s32 *)(arg0 + 8) = (s32)fparg1;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
}
// FUN_00201300
void func_00201300(s32 *arg0, f32 fp0, f32 fp1, f32 fp2, f32 fp3) {
    arg0[1] = (s32)fp0;
    arg0[2] = (s32)fp1;
    arg0[3] = (s32)fp2;
    arg0[4] = (s32)fp3;
}

/* measured: caching D_00887300 in s0 reproduces retail's one-time
   lui/addiu vtable materialization across these callback calls. */
#pragma opt_propagation off
// FUN_00201350
void func_00201350(void)
{
    void (**base)(u32, u32);

    func_00201820(0);
    base = D_00887300;
    base[0](7, 2);
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](1, 0);
}
/* measured: close the vtable propagation probe and restore default state. */
#pragma opt_propagation on
// FUN_00201410
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201410);
// FUN_00201650
void func_00201650(u8 *arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    arg0[0x94] = arg3;
    arg0[0x95] = arg4;
    arg0[0x96] = arg5;
    arg0[0x7D] = 0xFF - (arg6 & 0xFF);
    func_00201410(arg0, arg1, arg2);
    arg0[0x94] = 0xFF;
    arg0[0x95] = 0xFF;
    arg0[0x96] = 0xFF;
    arg0[0x7D] = 0;
}

// FUN_002016B0
void func_002016b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *table;
    u8 *base;
    u32 index;
    u32 offset;
    u8 *temp_4;

    index = (u32)(arg1 * 4);
    table = (u8 *)(index + (u32)arg0 + 0x2C);
    table = *(u8 **)table;
    offset = (u32)(arg2 << 7);
    base = *(u8 **)(table + 0x204);
    temp_4 = (u8 *)(offset + (u32)base);
    *(s32 *)(temp_4 + 0x5C) = arg3 + *(s32 *)(temp_4 + 0x54);
}
// FUN_002016E0
void func_002016e0(u8 *arg0, s16 arg1, s16 arg2, f32 fparg0)
{
    *(s16 *)(arg0 + 0x88) = arg1;
    *(s16 *)(arg0 + 0x8A) = arg2;
    *(f32 *)(arg0 + 0x84) = fparg0;
    *(f32 *)(arg0 + 0x24) = (f32)arg1;
    *(f32 *)(arg0 + 0x28) = (f32)arg2;
}
// FUN_00201720
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201720);
// FUN_00201820
void func_00201820(s32 arg0)
{
    s32 temp_5;

    temp_5 = arg0 & 0xFFFF;
    switch (temp_5) {
    case 0:
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        return;
    case 1:
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        return;
    case 2:
        func_003f6440(2, 0x48);
        func_003f6440(3, 0x71801);
        return;
    case 3:
        func_003f6440(2, 0x42);
        func_003f6440(3, 0x71801);
        return;
    case 4:
        func_003f6440(2, 6);
        func_003f6440(3, 0x71801);
        return;
    }
}
// FUN_00201950
void func_00201950(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    func_0046b260(arg0 + 0x6C);
}
// FUN_00201990
void func_00201990(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0x6C) =
        *(s32 *)((u8 *)(arg1 * 4) + (u32)arg0 + 0x2C);
    *(s32 *)(arg0 + 0x70) = arg2;
    func_0046b2f0(arg0 + 0x6C);
}
// FUN_002019D0
void func_002019d0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    *(f32 *)(arg0 + 0x14) = fparg0;
    *(f32 *)(arg0 + 0x18) = fparg1;
}
// FUN_002019E0
void func_002019e0(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 0x90) = fparg0;
}
// FUN_002019F0
void func_002019f0(s32 arg0, u32 arg1)
{
    u8 *temp_2;

    if (arg1 < 0x1000U) {
        temp_2 = D_0076449C;
        func_00216bb0(*(s32 *)(temp_2 + 0xDD4), arg0,
                      *(s32 *)(temp_2 + 0xC60), arg1);
        return;
    }
    func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                  iGpffffb448 + (((arg1 - 0x1000) & 0xFFFF) * 0x13));
    func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
}
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

// FUN_00201B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00201b00);
// FUN_00201DE0
u8 *func_00201de0(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4,
                  s16 arg5, s16 arg6, s32 arg7, u16 arg_sp0)
{
    u8 *spAC;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50A, 0x3C);
    spAC = temp_2;
    *(void **)(temp_2 + 0x68) = (void *)func_00201a80;
    *(void **)(temp_2 + 0x6C) = (void *)func_00201b00;
    *(void **)(temp_2 + 0x70) = (void *)func_00201db0;
    temp_16 = *(u8 **)(temp_2 + 0x78);
    func_0043f810(temp_16 + 8, (void *)arg7, 0x20);
    *(s32 *)(temp_16 + 0) = arg0;
    *(s32 *)(temp_16 + 4) = arg1;
    *(s32 *)(temp_16 + 0x28) = arg2;
    *(s16 *)(temp_16 + 0x2C) = arg3;
    *(s16 *)(temp_16 + 0x2E) = arg4;
    *(s16 *)(temp_16 + 0x30) = arg5;
    *(s16 *)(temp_16 + 0x32) = arg6;
    *(u16 *)(temp_16 + 0x38) = arg_sp0;
    return spAC;
}
// FUN_00201EE0
s32 func_00201ee0(void)
{
    func_0020e3f0(*(s32 *)(D_0076449C + 0xDD4));
    func_0021afa0(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00201F20
void func_00201f20(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50B, 0);
    *(void **)(temp_2 + 0x6C) = (void *)func_00201ee0;
}
/* measured: opt_rebuildconditionals off tested for callback completion. */
#pragma opt_rebuildconditionals off
// FUN_00201F60
s32 func_00201f60(u8 *arg0)
{
    u8 *temp_4;
    u32 temp_2;

    temp_4 = D_0076449C;
    if ((*(s32 *)(temp_4 + 0xC) & 0x200) == 0) {
        return 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        func_00216b40(*(s32 *)(temp_4 + 0xDD4),
                      iGpffffb448 + (*(u16 *)(arg0 + 4) * 0x13));
        func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    if (temp_2 >= 0x20U) {
        return 1;
    }
    return 0;
}
// FUN_00202070
s32 func_00202070(u8 *arg0)
{
    u32 temp_2;

    if ((*(s32 *)(D_0076449C + 0xC) & 0x200) == 0) {
        return 1;
    }
    if (*(u32 *)(arg0 + 8) == 0) {
        func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                      func_001067f0(*(s16 *)(arg0 + 4)));
        func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    if (temp_2 >= 0x20U) {
        return 1;
    }
    return 0;
}
/* measured: restore conditional rebuilding after callback completion. */
#pragma opt_rebuildconditionals on
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

// FUN_00202180
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202180);
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

// FUN_00202340
s32 func_00202340(u8 *arg0)
{
    u32 temp_2;
    u32 temp_7;
    s32 temp_8;
    u8 *temp_2_2;

    if (*(u32 *)(arg0 + 8) == 0) {
        temp_7 = *(u32 *)(arg0 + 4);
        temp_8 = *(s32 *)(arg0 + 0);
        if (temp_7 < 0x1000U) {
            temp_2_2 = D_0076449C;
            func_00216bb0(*(s32 *)(temp_2_2 + 0xDD4),
                          temp_8,
                          *(s32 *)(temp_2_2 + 0xC60), temp_7);
        } else {
            func_00216b40(*(s32 *)(D_0076449C + 0xDD4),
                          iGpffffb448 +
                              (((temp_7 - 0x1000) & 0xFFFF) * 0x13));
            func_00216d10(*(s32 *)(D_0076449C + 0xDD4));
        }
    }
    temp_2 = *(u32 *)(arg0 + 8) + 1;
    *(u32 *)(arg0 + 8) = temp_2;
    return temp_2 >= 0x21U;
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

// FUN_00202480
s32 func_00202480(u8 *arg0)
{
    s16 temp_2;
    s16 temp_3_2;
    s32 var_17;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0);
    switch (*(u8 *)(arg0 + 4)) {
    case 0:
        var_17 = func_00231ed0(*(s32 *)(temp_16 + 0xA64));
        temp_3_2 = func_00231f80(*(s32 *)(temp_16 + 0xA64));
        temp_2 = *(s16 *)(arg0 + 6);
        if (temp_2 != 0) {
            var_17 = (s16)(var_17 + temp_2);
            if (temp_3_2 < var_17) {
                var_17 = temp_3_2;
            } else if (var_17 < 0) {
                var_17 = 0;
            }
        }
        *(f32 *)(temp_16 + 0xA28) = (f32)var_17 / (f32)temp_3_2;
        break;
    case 1:
        break;
    default:
        break;
    }
    return 1;
}
// FUN_00202570
void func_00202570(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + -1;
}

// FUN_00202590
void func_00202590(s32 arg0, s8 arg1, s16 arg2)
{
    u8 *packet;
    u8 *temp;

    packet = (u8 *)func_00194470(0x500, 8);
    *(u8 *)(packet + 0x47) &= 0xEF;
    *(void **)(packet + 0x68) = (void *)func_00202460;
    *(void **)(packet + 0x6C) = (void *)func_00202480;
    *(void **)(packet + 0x70) = (void *)func_00202570;
    temp = *(u8 **)(packet + 0x78);
    *(s32 *)(temp + 0) = arg0;
    *(s8 *)(temp + 4) = arg1;
    *(s16 *)(temp + 6) = arg2;
}
// FUN_00202620
void func_00202620(u8 *arg0)
{
    *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) = *(u16 *)(*(u8 **)(arg0 + 0x0) + 0xA0) + 1;
}

// FUN_00202640
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202640);
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

// FUN_002027B0
s32 func_002027b0(void) {
    func_00213b50(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00202820
s32 func_00202820(void) {
    func_00213b80(*(s32 *)(D_0076449C + 0xDD4));
    return 1;
}
// FUN_00202850
void func_00202850(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00194470(0x50E, 0);
    *(void **)(temp_2 + 0x6C) = (void *)func_00202820;
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



// FUN_00202D20
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202d20);
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

// FUN_00202E70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00202e70);
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



// FUN_00203420
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203420);
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



// FUN_00203670
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203670);
// FUN_002037B0
void func_002037b0(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(s16 *)(p + 0x9C) = 1;
}
// FUN_002037E0
u16 func_002037e0(void) {
    return *(u16 *)((u8 *)func_00452560() + 0x9C);
}
/* measured: opt_propagation off probe for 00203810 evaluation order. */
#pragma opt_propagation off
// FUN_00203810
s32 func_00203810(void)
{
    u8 *p;
    u8 *base;
    s32 field;

    p = func_00452560();
    base = p + 0x9C;
    field = *(s32 *)(p + 0xD4);
    base += 0x40;
    return (s32)(field == (s32)base);
}
/* measured: close opt_propagation after func_00203810 probe. */
#pragma opt_propagation on
// FUN_00203850
s32 func_00203850(void)
{
    return *(s16 *)((u8 *)func_00452560() + 0xAA) < 2;
}
// FUN_00203880
void func_00203880(void)
{
}

// FUN_00203890
void func_00203890(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(s16 *)(p + 0x9C) = 4;
}
// FUN_002038C0
void func_002038c0(void) {
    u8 *b = (u8 *)func_00452560() + 0x9C;

    *(s32 *)(b + 4) &= ~2;
    func_002033c0(b + 0x2C);
    if (*(s32 *)(b + 0x5A8) != 0) {
        func_0011b360(*(s32 *)(b + 0x5A8));
        *(s32 *)(b + 0x5A8) = 0;
        *(s16 *)(b + 0x5AC) = -1;
    }
    *(s32 *)(b + 0x178) = 0;
    *(s16 *)b = 0;
}

// FUN_00203930
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00203930);
// FUN_00204690
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204690);
// FUN_00204A30
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204a30);
// FUN_00204B80
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204b80);
// FUN_00204D50
void func_00204d50(void)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    *(s16 *)(temp_2 + 0xAC) = 0;
    *(s32 *)(temp_2 + 0xA0) &= ~1;
}
// FUN_00204D90
void func_00204d90(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0xA0) = *(s32 *)(p + 0xA0) | 0x1;
}

// FUN_00204DC0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00204dc0);
// FUN_00205170
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205170);
// FUN_002055D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002055d0);
// FUN_00205950
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205950);
// FUN_00205C20
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205c20);
// FUN_00205E00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205e00);
// FUN_00205FF0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00205ff0);
// FUN_00206DD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00206dd0);
// FUN_00207140
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207140);
// FUN_00207320
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207320);
// FUN_00207B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00207b00);
// FUN_00208870
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208870);
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

// FUN_00208A50
void func_00208a50(u16 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 6), *(s16 *)(p + 4));
        }
    }
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}
// FUN_00208B00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208b00);
// FUN_00208D00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00208d00);
// FUN_00208FD0
void func_00208fd0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        func_00205ff0(arg1, arg0, arg2[0], arg2[1], func_00205170, arg0);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
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

// FUN_00209140
void func_00209140(u16 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 0xA), *(s16 *)(p + 8));
        }
    }
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}
/* measured: switch declaration and state-width spellings reached nd 6;
   remaining differences are compiler shape residuals. Committed at nd 9 in-file (nd 6 measured in isolation). */
// FUN_002091F0
#ifdef NON_MATCHING
s32 func_002091f0(u8 *arg0, u8 *arg1)
{
    s32 temp_2;
    s32 value;

    value = func_00202e70() & 0xFFFF;
    switch (value) {
    case 2:
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 3;
        temp_2 = *(s16 *)(arg1 + (*(s16 *)(arg0 + 4) * 4) + 0x1A6);
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x70) = temp_2;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) =
            func_00243920(*(u16 *)(*(u8 **)(arg1 + 0x178) + 0x70));
        *(s16 *)(arg1 + 0x1A) = 0;
        value = 4;
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 0xD, 2, 0x17);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            value = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            value = 2;
        }
        break;
    default:
        value = 1;
        break;
    }
    return value;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002091f0);
#endif
// FUN_00209370
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209370);
// FUN_00209640
void func_00209640(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        func_00205ff0(arg1, arg0, arg2[0], arg2[1], func_002055d0, arg0);
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
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

// FUN_002097B0
void func_002097b0(u16 *arg0, u8 *arg1)
{
    u8 *p;

    if (func_00106330(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            func_00202d20(arg0, *(s16 *)(p + 0xE), *(s16 *)(p + 0xC));
        }
    }
    *arg0 |= 1;
    *arg0 |= 2;
    if (*(s32 *)(arg1 + 0x3C) != (s32)(arg1 + 0x110)) {
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(arg1 + 0x20) = 0;
        *(s16 *)(arg1 + 0x22) = 0;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
    }
}
// FUN_00209870
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209870);
// FUN_002099C0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_002099c0);
// FUN_00209BC0
void func_00209bc0(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u8 **)(arg1 + 0x38) == arg1 + 0xDC) {
        if (*(u16 *)arg1 != 2) {
            func_00205ff0(arg1, arg0, arg2[0], arg2[1], func_00205c20, arg0);
        }
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
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

// FUN_00209DC0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209dc0);
// FUN_00209F90
void func_00209f90(void)
{
}
// FUN_00209FA0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_00209fa0);
// FUN_0020A5C0
void func_0020a5c0(void)
{
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

// FUN_0020A640
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020a640);
// FUN_0020AA70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020aa70);
// FUN_0020AC70
void func_0020ac70(s32 arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)arg1 != 2) {
        func_00205ff0(arg1, (u8 *)arg0, arg2[0], arg2[1],
                      func_00205950, (u8 *)arg0);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
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



// FUN_0020ADD0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020add0);
// FUN_0020B1A0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b1a0);
// FUN_0020B3A0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b3a0);
// FUN_0020B5A0
void func_0020b5a0(void)
{
}

/* measured: nd 41 against retail's 96-byte window (real body 92). Retail
   materialises the ~0x200 mask in the loop preheader, ahead of the branch into
   the condition, and keeps it in $a0 for the whole loop; b210 rematerialises it
   inside the body, which also transposes the and's operands. Declaring the mask
   first, assigning it last, and spelling the update as an explicit
   `x = x & mask` all leave it at nd 41, and retail additionally carries a nop
   at the loop's condition label that b210 never emits. Committed at nd 41. */

// FUN_0020B5B0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b5b0);

// FUN_0020B6D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020b6d0);

// FUN_0020BA00
u16 func_0020ba00(void) {
    return *(u16 *)((u8 *)func_00452560() + 0x712);
}

// FUN_0020BA30
void func_0020ba30(void)
{
    *(s16 *)((u8 *)func_00452560() + 0x712) = 0;
}

// FUN_0020BA60
void func_0020ba60(void)
{
    func_001d8bc0(*(u8 **)((u8 *)func_00452560() + 0x720));
}

// FUN_0020BA90
void func_0020ba90(void)
{
    func_001d8bc0(*(u8 **)((u8 *)func_00452560() + 0x720));
}
// FUN_0020BAC0
/* measured: retail keeps the ~0x200 mask live in the loop preheader; plain -O2
   rematerialises it inside the body (nd 41 -> byte-exact with the hoist). */
#pragma opt_loop_invariants on
void func_0020bac0(void) {
    u8 *w = (u8 *)func_00452560() + 0x710;
    s32 mask = ~0x200;
    u8 *p = *(u8 **)(D_0076449C + 0x178);

    while (p != NULL) {
        *(s32 *)(p + 0xA10) &= mask;
        p = *(u8 **)(p + 0xA6C);
    }
    *(s16 *)(w + 2) = 3;
}
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// FUN_0020BB20
void func_0020bb20(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x1C);
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 2) = 3;
}



// FUN_0020BB70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020bb70);
// FUN_0020BD70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020bd70);
// FUN_0020BF60
void func_0020bf60(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(u16 *)(p + 0x710) |= 1;
}
// FUN_0020BF90
void func_0020bf90(void) {
    u8 *p;

    p = (u8 *)func_00452560();
    *(u16 *)(p + 0x710) &= 0xFFFE;
}
// FUN_0020BFC0
void func_0020bfc0(u8 *arg0, s16 arg1)
{
    *(s16 *)(arg0 + 0) = arg1;
    *(s16 *)(arg0 + 2) = 0;
}
// FUN_0020BFD0
void func_0020bfd0(u8 *arg0)
{
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 1;
}
// FUN_0020E010
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e010);
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



// FUN_0020E250
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e250);
// FUN_0020E3F0
void func_0020e3f0() {
    func_002119a0(func_00452560() + 0x75C);
}

// FUN_0020E420
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e420);
// FUN_0020E5C0
f32 func_0020e5c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    f32 temp_f0;

    if (arg0 < arg1) {
        temp_f0 = 0.0f;
        goto done;
    }
    if (arg0 < arg2) {
        temp_f0 = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 1:
            temp_f0 = func_0044b7b0(fGpffff84a4 * temp_f0);
            goto done;
        case 2:
            temp_f0 = 1.0f - func_0044b610(fGpffff84a4 * temp_f0);
            goto done;
        default:
            goto done;
        }
    }
    temp_f0 = 1.0f;
done:
    return temp_f0;
}
// FUN_0020E690
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020e690);
// FUN_0020EA60
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ea60);
// FUN_0020EF10
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ef10);
// FUN_0020F4D0
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020f4d0);
// FUN_0020F730
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020f730);
// FUN_0020FA70
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020fa70);
// FUN_0020FF00
INCLUDE_ASM("asm/nonmatchings/code1_0020", func_0020ff00);