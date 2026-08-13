#include "include_asm.h"
#include "type.h"

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern u8 *func_00194470(s32 type, s32 workSize);
extern void func_00454bd0(u8 *ptr);
extern void func_0045ac90(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00230500(u8 *work);

extern void func_00231380(s32 *arg0, s32 arg1);
extern s32 func_001ef9a0(void);
extern s64 func_001060b0(void);
extern s32 func_00106330(s32 arg0);
extern s32 func_00106cd0(s32 arg0, s32 arg1);
extern s32 func_00110d60(s16 arg0);
extern s32 func_00442088(char *buf, char *fmt, ...);
extern void func_00231550(s32 arg0, s32 arg1);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern char D_007636e0;
extern char D_006358D0[];
extern char D_006358F0[];
extern char D_00635910[];
extern char D_00635678[];
extern char D_00635690[];
extern char D_006356B0[];
extern char D_006356D0[];
extern char D_006356F0[];
extern char D_00635710[];
extern char D_00635730[];
extern char D_00635750[];
extern char D_00635770[];
extern char D_00635790[];
extern char D_006357B0[];
extern s32 func_0047d0e0(void);
extern s32 func_0047d0b0(s32 arg0, s32 arg1, void *arg2);
extern s32 func_00442948(const void *arg0);
extern char D_006357C8[];
extern s32 func_00477c40(s32 arg0, s32 arg1, s32 arg2);
extern void func_0047aaa0(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                           void *arg4, s32 arg5);
extern void func_0047ac90(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4);
extern void func_0047adf0(void *arg0, s32 arg1, s32 arg2);
extern char D_006357E0[];
extern char D_00635800[];



// FUN_002305C0
void func_002305c0(s32 arg0)
{
    u8 *p;
    u8 *work;

    p = func_00194470(0xE01, 8);
    *(void **)(p + 0x6C) = (void *)func_00230500;
    work = *(u8 **)(p + 0x78);
    *(s32 *)(work + 0) = arg0;
    *(s32 *)(work + 4) = 0;
}
// FUN_00230610
s32 func_00230610(void)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0xB94);
    if (p != NULL) {
        func_00454bd0(p);
        *(u8 **)(iGpffffb3ac + 0xB94) = NULL;
    }
    return 1;
}
// FUN_00230650
void func_00230650(void)
{
    u8 *p;

    p = func_00194470(0xE02, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_00230610;
}
// FUN_00230690
s32 func_00230690(void)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0xB94);
    if (p != NULL) {
        func_0045ac90(2, *(s32 *)(p + 0x110), *(s32 *)(p + 0x118));
    }
    return 1;
}
// FUN_002306D0
void func_002306d0(void)
{
    u8 *p;

    p = func_00194470(0xE03, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_00230690;
}
// FUN_00230710
s32 func_00230710(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB94) != 0) {
        func_0045a9a0(2, 0);
    }
    return 1;
}



// FUN_00230750
void func_00230750(void)
{
    u8 *p;

    p = func_00194470(0xE04, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)func_00230710;
}
// FUN_00230790
s32 func_00230790(void)
{
    switch (func_001ef9a0()) {
    case 0x200:
        return 0x100;
    case 0x201:
        return 0x101;
    case 0x202:
        return 0x102;
    case 0x203:
        return 0x103;
    case 0x204:
        return -1;
    case 0x205:
        return 0x105;
    case 0x206:
        return 0x106;
    case 0x207:
        return 0x107;
    case 0x208:
        return 0x108;
    case 0x209:
        return -1;
    case 0x20A:
        return 0x10A;
    case 0x20B:
        return 0x10B;
    case 0x215:
        return 0x10E;
    case 0x20C:
        return -1;
    case 0x20D:
        return -1;
    case 0x214:
        return -1;
    default:
        return -1;
    }
}
// FUN_002308A0
s32 func_002308a0(s32 arg0, s32 arg1, char *arg2)
{
    s32 temp_16;
    s32 temp_18;
    u8 temp_20;
    switch (arg0 & 0xFFFF)
    {
    case 1:
        temp_16 = arg1 & 0xFFFF;
        if (temp_16 != 3)
        {
            if (func_00106330(0x1438) != 0 && temp_16 == 1)
                func_00442088(arg2, D_00635690, &D_007636e0, temp_16);
            else if (func_00110d60((s16)func_001060b0()) & 1)
                func_00442088(arg2, D_006356B0, &D_007636e0, temp_16);
            else
                func_00442088(arg2, D_006356D0, &D_007636e0, temp_16);
        }
        else
        {
            temp_18 = func_00106cd0(3, 0) & 0xFFFF;
            if (temp_18 >= 0x70 && temp_18 < 0x96)
            {
                if (func_00110d60((s16)func_001060b0()) & 1)
                    func_00442088(arg2, D_006356F0, &D_007636e0, temp_18);
                else
                    func_00442088(arg2, D_00635710, &D_007636e0, temp_18);
            }
            else if (func_00110d60((s16)func_001060b0()) & 1)
                func_00442088(arg2, D_006356B0, &D_007636e0, temp_16);
            else
                func_00442088(arg2, D_006356D0, &D_007636e0, temp_16);
        }
        break;
    case 2:
        func_00442088(arg2, D_00635730, D_00635678, arg1 & 0xFFFF);
        break;
    case 3:
        func_00442088(arg2, D_00635750, D_00635678, arg1 & 0xFFFF);
        break;
    case 7:
    case 10:
        func_00442088(arg2, D_006356F0, &D_007636e0, arg1 & 0xFFFF);
        break;
    case 8:
        func_00442088(arg2, D_00635770, &D_007636e0, arg1 & 0xFFFF);
        break;
    case 9:
        temp_20 = (u8)((arg1 & 0xFFFF) >> 8);
        func_00442088(arg2, D_00635790, &D_007636e0,
                      temp_20, arg1 & 0xFF);
        break;
    case 5:
        func_00231550((s32)arg2, arg1);
        break;
    case 11:
        func_00442088(arg2, D_006357B0, &D_007636e0, arg1 & 0xFFFF);
        break;
    }
    return 1;
}
// FUN_00230C00 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0023", func_00230c00);
// measured: optimization level 1 preserves the retail direct field loads and
// saved-register colouring for this function.
#pragma optimization_level 1
// FUN_00230D30
s32 func_00230d30(void *arg0)
{
    extern s32 func_00106cd0(s16 arg0, s16 arg1);
    extern s32 func_00477c40(s32 arg0, s32 arg1, s32 arg2);
    extern void func_0047aaa0(void *arg0, s32 arg1, void *arg2, void *arg3,
                               void *arg4, u32 arg5);
    extern void func_0047ac90(void *arg0, u32 arg1, void *arg2, void *arg3,
                              u32 arg4);
    extern void func_0047adf0(u8 *arg0, u16 arg1, s32 arg2);
    s32 temp_16;
    u8 sp40[0x100];
    s32 temp_18;

    if (*(u16 *)((s8 *)arg0 + 0xD4) != 1) return 0;
    temp_16 = (s32)(func_00106cd0(*(s16 *)((u8 *)arg0 + 0xD6), 0) & 0xFFFF);
    switch (*(u16 *)((s8 *)arg0 + 0xD6)) {
    case 2:
        if (func_00477c40(7, temp_16, 0) == 0) {
            func_00442088((char *)sp40, D_006357E0,
                          (char *)&iGpffffb3ac - 0x5A10, temp_16 & 0xFFFF);
            func_0047aaa0(arg0, 0, (void *)7, (void *)temp_16,
                          sp40, 0);
        } else {
            func_0047ac90(arg0, 0, (void *)7, (void *)temp_16, 0);
        }
        temp_18 = (temp_16 & 0xFFFF) + 0x3E8;
        if (func_00477c40(7, temp_18 & 0xFFFF, 0) == 0) {
            func_00442088((char *)sp40, D_00635800,
                          (char *)&iGpffffb3ac - 0x5A10, temp_16 & 0xFFFF);
            func_0047aaa0(arg0, 1, (void *)7,
                          (void *)(temp_18 & 0xFFFF),
                          sp40, 0);
        } else {
            func_0047ac90(arg0, 1, (void *)7,
                          (void *)(temp_18 & 0xFFFF), 0);
        }
        break;
    case 3:
        return 0;
    default:
        func_0047ac90(arg0, 0, (void *)7, (void *)temp_16, 0);
        goto block_13;
    }
block_13:
    func_0047adf0((u8 *)arg0, 0, 0x1F4);
    func_0047adf0((u8 *)arg0, 1, 0x1F5);
    return 1;
}
#pragma optimization_level 2
// FUN_00231380
void func_00231380(s32 *arg0, s32 arg1)
{
    u32 sp5C;
    s16 var_17;
    s32 var_19;
    s32 temp_18;
    s32 temp_5;
    s32 var_4;
    s32 var_6;
    s64 temp_17;
    s64 temp_3_2;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;

    var_19 = 0;
    var_17 = 0;
    temp_2 = func_00455f70(&D_006358D0, &sp5C);
    temp_5 = *(s32 *)(temp_2 + 4);
    temp_4 = temp_2 + 8;
    temp_18 = arg1 & 0xFFFF;
    var_6 = 0;
    while (var_6 < temp_5)
    {
        temp_3 = temp_4 + (var_6 * 4);
        if (temp_18 == *(u16 *)temp_3)
            var_17 = *(s16 *)(temp_3 + 2);
        else
        {
            var_6++;
            continue;
        }
        break;
    }
    temp_17 = (s64)var_17;
    if (temp_17 > 0)
    {
        temp_3_2 = (s64)(s16)func_00110d60((s16)func_001060b0());
        if (!(temp_3_2 & 1))
        {
            if (temp_17 & 3)
                var_4 = 0;
            else
                var_4 = 1;
        }
        else if (temp_17 & 0xC)
            var_4 = 1;
        else
            var_4 = 0;
        if (temp_3_2 & 2)
        {
            if (temp_17 & 0xA)
                var_19 = (var_4 * 2) + 2;
            else
                var_19 = (var_4 * 2) + 1;
        }
        else if (temp_17 & 5)
            var_19 = (var_4 * 2) + 1;
        else
            var_19 = (var_4 * 2) + 2;
    }
    if (temp_18 < 0xC50)
        func_00442088((char *)arg0, D_006358F0, &D_007636e0,
                      temp_18, var_19);
    else
        func_00442088((char *)arg0, D_00635910, &D_007636e0,
                      temp_18, var_19);
}
// FUN_00231550
void func_00231550(s32 arg0, s32 arg1)
{
    func_00231380((s32 *)arg0, arg1 & 0xFFFF);
}
