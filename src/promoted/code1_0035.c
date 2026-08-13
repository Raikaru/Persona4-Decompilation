#include "include_asm.h"
#include "type.h"

extern void func_0034f5d0(u8 *arg0);

extern void func_002bb550(s8 arg0);
extern void (*D_008873EC[])(...);

extern void func_003549d0();
extern s32 func_001060b0(void);
extern s32 func_00110d60(s64 arg0);
extern s32 func_00353dc0(s64 arg0);
extern s32 func_00106330(s32 arg0);
extern u8 *func_00452380(const void *arg0);
extern s32 func_0029cc00(s32 arg0);
extern u8 D_0064B320[];
extern void func_00354280(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_0064B3B0[];
extern u8 D_0064B3D0[];
extern s32 func_00355460(u8 *arg0);
extern void func_003554b0(u8 *arg0);
extern void func_00442de8(void *dst, const void *src, u32 size);

extern void func_0046d280(s32 arg0);
extern void func_00452080(s32 arg0);
extern void func_002bc060(s32 arg0);
extern s32 func_002467b0(u16 arg0);
extern void func_0046d730(const void *module, u32 line);
extern void func_00442088(void *dst, const void *fmt, ...);
extern u8 D_0064CCF0[];
extern u8 D_0064CD10[];
extern u32 D_0064B310[];
extern u8 D_0064B3F0[];
extern u8 D_0064CC60[];
extern u8 D_0064CC70[];
extern u8 D_0064CC78[];

extern f32 D_00761260;

typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;
extern void func_003550d0(u8 *arg0, Float2 *arg1, Float2 *arg2);
extern void func_00355370(u8 *arg0, u8 *arg1);
extern void func_00355190(u8 *arg0, u16 arg1);

typedef struct S64u
{
    s32 lo;
    s32 hi;
} S64u;
static inline u32 add_offset_first(u32 offset, u32 base)
{
    return offset + base;
}



extern s32 func_0034c210(void);

extern void FUN_0046d730(const char *file, s32 line);
extern u32 D_0064B1E0[];

extern void func_004672c0(s32 arg0, s32 arg1);
extern void func_00454bd0(u8 *arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_00355740(u8 *arg0, s64 arg1);
extern void func_00355920(u8 *arg0);
extern void func_0035bc10(u8 *arg0, s8 arg1, s32 arg2);
extern void func_0035c480(s32 arg0, u16 arg1, s32 arg2);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_00361ae0(u8 *arg0);
extern void func_00361ca0(u8 *arg0);
extern void func_0035fd60(u8 *arg0);
extern s32 func_0035aec0(u8 *arg0);
extern void func_0035af10(u8 *arg0);
extern u8 D_0064CC98[];
extern u8 D_0064CD40[];
extern u8 D_0064CCB0[];
extern u8 D_0064CCD0[];
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern void func_00440b68();
extern s32 func_00454a60(u8 *arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern s32 func_004667d0();
extern s32 func_004669d0(s32 arg0, void *arg1, s32 arg2);
extern u8 iGpffffa960;
extern u8 D_0064B360[];
extern u8 D_0064B380[];
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *func_00451fc0(s32 arg0, const void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern void func_00365f00(f32 f0, f32 f1, f32 f2, f32 f3, s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 f4);
extern f32 iGpffff83d4;
extern f32 iGpffff8544;
extern void func_002bb7c0();
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 arg0);
extern void func_002bb9e0(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb290(s8 arg0, s32 arg1);
extern s32 func_002bb4e0(void);
extern s32 func_002bd7b0(const void *arg0);
extern s32 func_002bd840(s32 arg0);
extern u8 D_0064A790[];
extern void func_00149680(s32 arg0);
extern void func_0015a560(void);
extern void func_0034c260(s32 arg0);
extern void func_0034bb10(void);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s64 func_00105ee0(s32 arg0);
// FUN_00353B50
s16 func_00353b50(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 0; var_16 < 3; var_16++) {
        temp_3 = func_00105ee0(var_16);
        if (temp_3 != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
    }
    if (var_17 <= 4) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x259);
done:
    return var_17;
}
// FUN_00353C10
s16 func_00353c10(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 1; var_16 < 8; var_16++) {
        temp_3 = (s16)(var_16 + 1);
        if (func_00353dc0(temp_3) != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
    }
    if (var_17 <= 8) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x26F);
done:
    return var_17;
}
// FUN_00353CE0
s16 func_00353ce0(s16 *arg0)
{
    s16 var_17;
    s16 temp_3;
    s32 var_16;

    var_17 = 1;
    *arg0 = 1;
    for (var_16 = 1; var_16 < 8; var_16++) {
        temp_3 = (s16)(var_16 + 1);
        if (temp_3 == 5) {
            goto skip;
        }
        if (func_00353dc0(temp_3) != 0) {
            ((s16 *)arg0)[var_17] = temp_3;
            var_17++;
        }
skip:
        ;
    }
    if (var_17 <= 8) {
        goto done;
    }
    func_0046d730(&D_0064B310, 0x286);
done:
    return var_17;
}
// FUN_00353DC0
s32 func_00353dc0(s64 arg0)
{
    s64 value;
    s32 result;

    result = 0;
    value = (s16)arg0;
    if ((value <= 0) || (value >= 0xB)) {
        func_0046d730(&D_0064B310, 0x292);
    }
    switch (value) {
    case 1:
        result = 1;
        break;
    case 2:
        if (func_00106330(0x30) != 0) {
            result = 1;
        }
        break;
    case 3:
        if (func_00106330(0x31) != 0) {
            result = 1;
        }
        break;
    case 4:
        if (func_00106330(0x32) != 0) {
            result = 1;
        }
        break;
    case 5:
        if (func_00106330(0x34) != 0) {
            result = 1;
        }
        break;
    case 6:
        if (func_00106330(0x33) != 0) {
            result = 1;
        }
        break;
    case 8:
        if (func_00106330(0x35) != 0) {
            result = 1;
        }
        break;
    case 7:
        if (func_00106330(0x36) != 0) {
            result = 1;
        }
        break;
    default:
        func_0046d730(&D_0064B310, 0x2B0);
        break;
    }
    return result;
}
// FUN_00353F50
s32 func_00353f50(s32 arg0)
{
    func_002bb7c0();
    if (func_002bb600() == 0) {
        func_002bb1e0(arg0);
        return 0;
    }
    return 1;
}
// FUN_00353FB0
void func_00353fb0(void)
{
    func_00149680(0);
}
// FUN_00353FE0
void func_00353fe0(void)
{
    func_00149680(1);
}
// FUN_00354010
void func_00354010(void)
{
    func_0015a560();
}
// FUN_00354030
void func_00354030(void)
{
    func_0045af60(0, 2, 0, 4);
    func_0034c260(0);
    func_00149680(0);
    func_0034bb10();
}
// FUN_00354080
void func_00354080(s32 arg0)
{
    if ((u32)(arg0 - 1) < 2U) {
        func_0045af60(0, 1, 0, 0);
        return;
    }
    if ((u32)(arg0 - 3) < 2U) {
        func_0045af60(0, 1, 0, 5);
    }
}
// FUN_003540F0
s32 func_003540f0(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(work + 4);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = 1;
        break;
    case 1:
        func_002bb9e0(*(s8 *)(work + 8), 1);
        if (func_002bb680(*(s8 *)(work + 8)) == 0) {
            func_002bb290(*(s8 *)(work + 8), 1);
            if ((*(u16 *)work & 1) != 0) {
                func_002bd7b0(D_0064A790);
                func_002bd840(7);
                *(s32 *)(work + 4) = 2;
            } else {
                *(s32 *)(work + 4) = 3;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            func_002bb4e0();
            *(s32 *)(work + 4) = 3;
        }
        break;
    case 3:
        break;
    default:
        func_0046d730(&D_0064B310, 0x34A);
        break;
    }
    return 0;
}
// FUN_00354230
void func_00354230(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002bb550(*(s8 *)(temp_16 + 8));
    (*D_008873EC)(temp_16);
}

// FUN_00354280
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354280);
// FUN_00354490
u32 func_00354490(s32 arg0)
{
    if (!(arg0 < 0x40)) {
        FUN_0046d730(__FILE__, 0x3D6);
    }
    return D_0064B1E0[arg0];
}

// FUN_003544F0
s32 func_003544f0(void)
{
    return 50;
}

// FUN_00354500
s32 func_00354500(void) {
    s32 temp_17;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    if ((temp_2 = func_00452380(&D_0064B320)) != NULL) {
        temp_3 = *(s32 *)(*(u8 **)(temp_2 + 0x38) + 4);
        if (temp_3 == 3) {
            if (temp_3 != 3) {
                func_0046d730(&D_0064B310, 0x3CC);
            }
            func_00452080((s32)(u32)temp_2);
            return 1;
        }
        goto block_10;
    }
    temp_17 = func_0029cc00(0) - 1;
    func_0044ea90(&D_0064B310, 0x3AB);
    temp_2_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2_2 == NULL) {
        func_0046d730(&D_0064B310, 0x3AC);
    }
    if (func_00451fc0(0, &D_0064B320, 0xF, 0, 0,
                      (void *)func_003540f0, (void *)func_00354230,
                      temp_2_2) == NULL) {
        func_0046d730(&D_0064B310, 0x3B5);
    }
    func_00354280(temp_2_2, temp_17, 0);
block_10:
    return 0;
}
// FUN_00354660
s32 func_00354660(void) {
    s32 temp_17;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_2_2;

    if ((temp_2 = func_00452380(&D_0064B320)) != NULL) {
        temp_3 = *(s32 *)(*(u8 **)(temp_2 + 0x38) + 4);
        if (temp_3 == 3) {
            if (temp_3 != 3) {
                func_0046d730(&D_0064B310, 0x3CC);
            }
            func_00452080((s32)(u32)temp_2);
            return 1;
        }
        goto block_10_2;
    }
    temp_17 = func_0029cc00(0) - 1;
    func_0044ea90(&D_0064B310, 0x3AB);
    temp_2_2 = D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2_2 == NULL) {
        func_0046d730(&D_0064B310, 0x3AC);
    }
    if (func_00451fc0(0, &D_0064B320, 0xF, 0, 0,
                      (void *)func_003540f0, (void *)func_00354230,
                      temp_2_2) == NULL) {
        func_0046d730(&D_0064B310, 0x3B5);
    }
    func_00354280(temp_2_2, temp_17, 1);
block_10_2:
    return 0;
}
// FUN_003547C0
void func_003547c0(s32 *arg0, u8 *arg1)
{
    func_003549d0();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    func_00442de8((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}



// FUN_00354830
s32 func_00354830(u8 *arg0) {
    s32 sp3C;
    s32 temp_2;
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0);
    switch (temp_3) {
    case 0:
        if (func_00452380(&D_0064B360) != NULL) {
            func_00440b68(&D_0064B380);
        } else {
            func_00440b68(&iGpffffa960, &D_0064B310, 0x433);
            temp_2 = func_00454a60(arg0 + 0x10, 0);
            *(s32 *)(arg0 + 8) = temp_2;
            if (temp_2 == 0) {
                func_0046d730(&D_0064B310, 0x434);
            }
            *(s32 *)(arg0 + 0) = 1;
        }
        goto block_15;
    case 1:
        if (func_004553c0(*(s32 *)(arg0 + 8)) != 0) {
            *(s32 *)(arg0 + 4) =
                func_004667d0(0, arg0 + 0x10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0) = 2;
        }
        goto block_15;
    case 2:
        *(s32 *)(arg0 + 0xC) =
            func_004669d0(*(s32 *)(arg0 + 4), &sp3C, 0);
        if (sp3C != 0) {
            *(s32 *)(arg0 + 4) = 0;
            func_00454bd0(*(u8 **)(arg0 + 8));
            *(s32 *)(arg0 + 8) = 0;
            *(s32 *)(arg0 + 0) = 3;
        }
        goto block_15;
    case 3:
        return 1;
    default:
        break;
    }
block_15:
    return 0;
}
// FUN_003549D0
void func_003549d0(u8 *arg0)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_004672c0(temp_4, *(s32 *)(arg0 + 8));
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 8) = 0;
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        func_00454bd0(*(u8 **)(arg0 + 8));
        *(s32 *)(arg0 + 8) = 0;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        func_003ef3a0(*(u8 **)(arg0 + 0xC));
        *(s32 *)(arg0 + 0xC) = 0;
    }
}

// FUN_00354A50
u8 *func_00354a50(s32 arg0, u16 arg1) {
    Float2 sp48;
    u8 *temp_2;
    u8 *temp_2_2;

    func_0044ea90(&D_0064B310, 0x48C);
    temp_2_2 = D_008873F4[0](1, 0x258, 0x40000);
    if (temp_2_2 == NULL) {
        return NULL;
    }
    temp_2 = func_00451fc0(arg0, &D_0064B3D0, 0xC7, 0, 0,
                           (void *)func_00355460, (void *)func_003554b0,
                           temp_2_2);
    if (temp_2 == NULL) {
        return NULL;
    }
    *(s16 *)(temp_2_2 + 8) = 0;
    *(u8 *)(temp_2_2 + 0xA) = 0xFF;
    *(s32 *)(temp_2_2 + 0xC) =
        *(u8 *)(temp_2_2 + 0xA) | 0x2D2D2D00;
    sp48.x = 640.0f;
    sp48.y = 640.0f;
    func_003550d0(temp_2, &sp48, &sp48);
    func_00355370(temp_2, NULL);
    *(s32 *)(temp_2_2 + 0x150) = 0;
    *(s32 *)(temp_2_2 + 0x148) = 0;
    *(s32 *)(temp_2_2 + 0x14C) = 0;
    *(void **)(temp_2_2 + 0x254) = (void *)&D_0064B3B0;
    func_00355190(temp_2, arg1);
    return temp_2;
}
// FUN_00354BA0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354ba0);
// FUN_00355070
void func_00355070(u8 *arg0, u8 *arg1) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(temp_3 + 0x18) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(temp_3 + 0x1C) = (f32) *(f32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x20) = (f32) *(f32 *)(arg1 + 0);
        *(f32 *)(temp_3 + 0x24) = (f32) *(f32 *)(arg1 + 4);
    } else {
        *(f32 *)(temp_3 + 0x10) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x14) = (f32) *(f32 *)(temp_3 + 0x1C);
        *(f32 *)(temp_3 + 0x30) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x34) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    *(s32 *)(temp_3 + 4) = 0;
}

// FUN_003550D0
void func_003550d0(u8 *arg0, Float2 *arg1, Float2 *arg2)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(&D_0064B310, 0x53A);
    }
    if (arg2 == NULL) {
        func_0046d730(&D_0064B310, 0x53B);
    }
    *(f32 *)(temp_16 + 0x18) = arg1->x;
    *(f32 *)(temp_16 + 0x1C) = arg1->y;
    *(f32 *)(temp_16 + 0x10) = arg1->x;
    *(f32 *)(temp_16 + 0x14) = arg1->y;
    *(f32 *)(temp_16 + 0x20) = arg2->x;
    *(f32 *)(temp_16 + 0x24) = arg2->y;
    *(f32 *)(temp_16 + 0x30) = arg1->x;
    *(f32 *)(temp_16 + 0x34) = arg1->y;
    *(s32 *)(temp_16 + 4) = 0;
}
// FUN_00355190
void func_00355190(u8 *arg0, u16 arg1)
{
    u8 sp50[0x100];
    s32 temp_17;
    s8 var_2;
    u8 *temp_16;
    u8 *temp_3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = arg1 & 0xFFFF;
    if (*(u16 *)(temp_16 + 8) != temp_17) {
        if (func_00110d60((s64)(s16)func_001060b0()) & 1) {
            var_2 = 0x61;
        } else {
            var_2 = 0x62;
        }
        if (temp_17 == 0) {
            func_003549d0(temp_16 + 0x144);
            *(s32 *)(temp_16 + 0x144) = 3;
        } else {
            func_00442088(sp50, &D_0064B3F0, temp_17, var_2);
            func_003549d0(temp_16 + 0x144);
            if ((u8 *)sp50 == NULL) {
                *(s32 *)(temp_16 + 0x144) = 3;
            } else {
                func_00442de8(temp_16 + 0x154, sp50, 0x100);
                *(s32 *)(temp_16 + 0x144) = 0;
            }
        }
        *(u16 *)(temp_16 + 8) = arg1;
        *(s32 *)(temp_16 + 0x40) = 0;
        temp_3 = *(u8 **)(arg0 + 0x38);
        *(f32 *)(temp_3 + 0x10) = *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x14) = *(f32 *)(temp_3 + 0x1C);
        *(f32 *)(temp_3 + 0x30) = *(f32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x34) = *(f32 *)(temp_3 + 0x1C);
        *(s32 *)(temp_3 + 4) = 0;
    }
}
// FUN_003552D0
void func_003552d0(u8 *arg0, Float2 arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);

    b[0xA] = arg1.x;
    b[0xB] = arg1.y;
}
// FUN_00355300
void func_00355300(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = arg1;
}

// FUN_00355310
void func_00355310(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32) *(f32 *)(temp_3 + 0x18);
        *(f32 *)(arg1 + 4) = (f32) *(f32 *)(temp_3 + 0x1C);
    }
    if (arg2 != NULL) {
        *(f32 *)(arg2 + 0) = (f32) *(f32 *)(temp_3 + 0x10);
        *(f32 *)(arg2 + 4) = (f32) *(f32 *)(temp_3 + 0x14);
    }
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = (f32) *(f32 *)(temp_3 + 0x20);
        *(f32 *)(arg3 + 4) = (f32) *(f32 *)(temp_3 + 0x24);
    }
}

// FUN_00355370
void func_00355370(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(temp_4 + 0x38) = 0x3F800000;
        *(u32 *)(temp_4 + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(temp_4 + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(temp_4 + 0x3C) = *(f32 *)(arg1 + 4);
    }
}



// FUN_003553B0
void func_003553b0(u8 *arg0, f32 *arg1)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(temp_16 + 0x38);
    arg1[1] = *(f32 *)(temp_16 + 0x3C);
}



/* measured: the read and the write of the same field must use DIFFERENT
   spellings. Written identically both times, b210 CSEs the address into a
   callee-saved register (addiu $s0, $v1, 0x40 then sw at 0) and leaves the
   struct pointer in a caller-saved one; retail keeps the POINTER in $s0 and
   stores at 0x40($s0). Reading through the array index and writing through the
   cast-and-offset breaks the CSE and the function matches exactly. Same shape
   in func_0035aec0 and func_0035be70. */

// FUN_00355410
void func_00355410(u8 *arg0, s8 arg1)
{
    u8 *temp_4;

    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xA) = arg1;
    temp_4 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_4 + 0xC) = ((s32 *)temp_4)[3];
}

// FUN_00355430
s32 func_00355430(u8 *arg0)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_3 + 0x40) != 0) {
        return *(s32 *)(temp_3 + 0x150);
    }
    return 0;
}
// FUN_00355460
s32 func_00355460(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[16] == 0) && (*(u16 *)(p + 8) != 0)) {
        *(s32 *)(p + 0x40) = func_00354830(p + 0x144);
    }
    return 0;
}

// FUN_003554B0
void func_003554b0(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(p + 0x148);
    if (temp_4 != 0) {
        func_004672c0(temp_4, *(s32 *)(p + 0x14C));
        *(s32 *)(p + 0x148) = 0;
        *(s32 *)(p + 0x14C) = 0;
        *(s32 *)(p + 0x150) = 0;
    } else {
        temp_4_2 = *(s32 *)(p + 0x14C);
        if (temp_4_2 != 0) {
            func_00454bd0((u8 *)temp_4_2);
            *(s32 *)(p + 0x14C) = 0;
        }
        temp_4_3 = *(s32 *)(p + 0x150);
        if (temp_4_3 != 0) {
            func_003ef3a0((void *)temp_4_3);
            *(s32 *)(p + 0x150) = 0;
        }
    }
    (*D_008873EC)(p);
}
/* measured: object 328B/window 336B; normalized_diff 33; differing offsets
   0x2C-0x44, 0xDC-0xF4, 0xFC-0x100, 0x10C-0x140. Trial body archived in
   build/V035_00355550_body.c; no conversion idiom present. */
// FUN_00355550 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355550);
// FUN_003556A0
void func_003556a0(u8 *arg0, s16 arg1, s32 arg2)
{
    s32 i;
    u8 *p;

    *(s32 *)(arg0 + 8) = 1;
    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(s32 *)(p + 0x20) = 0;
        *(s32 *)(p + 0x24) = 0;
        i += 1;
    }
    func_00355740(arg0, arg1);
    func_0043f9c8(arg0 + 0x1F8, 0, 0x30);
    *(s32 *)(arg0 + 0x200) = (s32)func_00355920;
    *(s32 *)(arg0 + 0x208) = (s32)arg0;
    *(s32 *)(arg0 + 0x228) = arg2;
}
// FUN_00355740
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355740);
// FUN_003558A0
s32 func_003558a0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_16 + 0x1F8) = 0;
    *(s32 *)(temp_16 + 0x1FC) = 0;
    func_00460ac0((u8 *)&D_00793E80 + (*(s32 *)(temp_16 + 0x228) * 0x30), temp_16 + 0x1F8);
    if (!(*(s32 *)(temp_16 + 8) & 4)) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}

// FUN_00355920
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355920);
// FUN_00356140
void func_00356140(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}



/* measured: object 96B/window 96B; normalized_diff 8; differing offsets
   0x08 and 0x10 (prologue save/move order). Archived in
   build/V035_00356170_body.c. Ruled out scalar locals (object 100B) and
   alternate assignment/call staging; best plain-C candidate remains nd 8. */
// FUN_00356170 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356170);
/* measured: object 116B/window 128B; normalized_diff 15; differing offsets
   0x10, 0x18, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58 (call setup and
   relocation-masked tail). The plain-C body is archived in
   build/V035_003561d0_body.c; declaration and schedule variants were ruled
   out without changing the residual family. */
// FUN_003561D0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003561d0);
// FUN_00356250
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356250);
// FUN_00356820
s32 func_00356820(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00356870
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356870);
// FUN_00356A10
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356a10);
// FUN_00359340
void func_00359340(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x960);
    }
}

// FUN_003593B0
void func_003593b0(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}



// FUN_003593E0
s32 func_003593e0(s32 arg0, s32 arg1, s16 arg2)
{
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x24);
    *(s16 *)(p + 0x24) = arg2;
    return 1;
}
// FUN_00359400
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00359400);
// FUN_003596A0
s32 func_003596a0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 43) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x17C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00359720
void func_00359720(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_17;
    u8 *temp_2;

    var_17 = 0;
    goto loop_test;
loop_body:
    temp_2 = arg0 + (var_17 * 4) + 0x11D0;
    temp_4 = *(s32 *)temp_2;
    if (temp_4 != 0) {
        func_0046d280(temp_4);
        *(s32 *)temp_2 = 0;
    }
    var_17 += 1;
loop_test:
    if (var_17 < 0x4D) {
        goto loop_body;
    }
    temp_4_2 = *(s32 *)(arg0 + 0x1308);
    if (temp_4_2 != 0) {
        func_00452080(temp_4_2);
        *(s32 *)(arg0 + 0x1308) = 0;
    }
    temp_4_3 = *(s32 *)(arg0 + 0x130C);
    if (temp_4_3 != 0) {
        func_00452080(temp_4_3);
        *(s32 *)(arg0 + 0x130C) = 0;
    }
    temp_4_4 = *(s32 *)(arg0 + 0x1310);
    if (temp_4_4 != 0) {
        func_00452080(temp_4_4);
        *(s32 *)(arg0 + 0x1310) = 0;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
    func_002bc060(0xB);
}
// FUN_003597F0
void func_003597f0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4_2;
    s32 var_18;
    s32 var_17;
    u8 *temp_4;
    u8 *temp_5;

    temp_16 = func_002467b0(
        *(u16 *)((u8 *)add_offset_first(
            (s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC,
            (u32)arg0) + 0x3A));
    var_18 = 0;
    var_17 = 0;
    goto loop_test;
loop_body:
    temp_4 = (u8 *)(temp_16 + (var_18 * 8));
    temp_5 = temp_4 + 0x28;
    if ((*(s32 *)temp_5 != 0) &&
        ((temp_4_2 = *(s32 *)(temp_4 + 0x24), temp_4_2 == 0) ||
         (func_00106330(temp_4_2) != 0))) {
        *(s16 *)(arg0 + (var_17 * 2) + 0x136) = *(s32 *)temp_5;
        var_17 += 1;
    }
    var_18 += 1;
loop_test:
    if (var_18 < 8) {
        goto loop_body;
    }
    *(s32 *)(arg0 + 0x148) = var_17;
}
/* measured: probe loop-invariant constant hoisting for func_003598d0. */
#pragma opt_loop_invariants on
// FUN_003598D0
void func_003598d0(u8 *arg0)
{
    s32 temp_3;
    s32 var_5;
    f32 value_1;
    f32 value_2;
    f32 value_3;
    s32 value_4;
    f32 value_5;

    temp_3 = *(s16 *)(arg0 + 0x24);
    var_5 = 0;
    value_1 = 800.0f;
    value_2 = -400.0f;
    value_3 = 29.5f;
    value_4 = 1;
    value_5 = 22.0f;
    goto loop_test;
loop_body:
    if (var_5 != temp_3) {
        if (var_5 < temp_3) {
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_2;
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_2;
        } else {
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_1;
            *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_1;
        }
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x4B8) = value_5;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x4CE) = value_4;
    } else {
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x5AC) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x5C4) = value_4;
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x18C) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x1A4) = value_4;
        *(f32 *)(arg0 + (var_5 * 0x30) + 0x4BC) = value_3;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0x4D4) = value_4;
    }
    var_5 += 1;
loop_test:
    if (var_5 < 5) {
        goto loop_body;
    }
}
/* measured: restore loop-invariant optimization after func_003598d0. */
#pragma opt_loop_invariants off
// FUN_003599A0
void func_003599a0(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}



// FUN_003599C0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003599c0);
// FUN_0035AC60
void func_0035ac60(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    Float2 pair;
    s32 temp_17;
    u8 *temp_2;
    u8 *var_5;
    u8 *var_6;

    if ((arg1 < 0) || (arg1 >= 2)) {
        func_0046d730(&D_0064CC98, 0x6B8);
    }
    if (arg0 == NULL) {
        func_0046d730(&D_0064CC98, 0x6B9);
    }
    if (arg3 != 0) {
        var_6 = D_0064CC60 + (arg1 * 0x1C);
        var_5 = var_6 + 8;
    } else {
        var_5 = D_0064CC60 + (arg1 * 0x1C);
        var_6 = var_5 + 8;
    }
    temp_2 = D_0064CC70 + (arg1 * 0x1C);
    pair = *(Float2 *)temp_2;
    temp_17 = *(s32 *)(D_0064CC78 + (arg1 * 0x1C));
    if (arg2 != 0) {
        func_003550d0(arg0, (Float2 *)var_5, (Float2 *)var_6);
    } else {
        func_00355070(arg0, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, temp_17);
}
// FUN_0035ADC0
u8 *func_0035adc0(s32 arg0, s64 arg1, s32 arg2)
{
    u8 *temp_2;
    u8 *temp_18;

    func_0044ea90(&D_0064CC98, 0x6ED);
    temp_2 = D_008873F4[0](1, 0x144, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064CC98, 0x6EE);
    }
    temp_18 = func_00451fc0(arg0, &D_0064CCD0, 0xC7, 0, 0,
                            (void *)func_0035aec0, (void *)func_0035af10,
                            temp_2);
    *(s8 *)(temp_2 + 0x20) = 0;
    *(s32 *)(temp_2 + 0x2C) = 0;
    *(u8 **)(temp_2 + 0x140) = D_0064CCB0;
    {
        extern void func_0035bc10();
        func_0035bc10((s32)temp_18, arg1, arg2);
    }
    return temp_18;
}
// FUN_0035AEC0
s32 func_0035aec0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(s8 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035AF10
void func_0035af10(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035AF60
s32 func_0035af60(u8 *arg0)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(temp_3 + 0x2C) == 0) || (*(s8 *)(temp_3 + 0x20) == 0)) {
        return 0;
    }
    return 1;
}
// FUN_0035AFA0
s32 func_0035afa0(u8 *arg0) {
    s32 var_2;
    u8 *temp_3;

    temp_3 = (u8 *)(*(u8 **)(arg0 + 0x38));
    if ((*(s32 *)(temp_3 + 0x2C) == 0) || (*(s8 *)(temp_3 + 0x20) == 0)) {
        var_2 = 0;
    } else {
        var_2 = 1;
    }
    if (var_2 != 0) {
        return (s32)(**(s32 **)(temp_3 + 0x3C));
    }
    return 0;
}

// FUN_0035AFF0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035aff0);
// FUN_0035BAD0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bad0);
// FUN_0035BC10
void func_0035bc10(u8 *arg0, s8 arg1, s32 arg2)
{
    u8 *base;
    s8 old;
    u8 buf[0x100];

    base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x22) = 0;
    *(f32 *)(base + 0x0) = 71.5f;
    *(f32 *)(base + 0x4) = 106.0f;
    *(f32 *)(base + 0x10) = 1.0f;
    *(s32 *)(base + 0x18) = 0;
    *(f32 *)(base + 0x1C) = 1.0f;
    *(f32 *)(base + 0x14) = 1.0f;
    old = *(s8 *)(base + 0x20);
    if (old == arg1) {
        goto unchanged;
    }
    switch (arg1) {
    case -1:
        goto minus_one_case;
    case 0:
        goto zero_case;
    default:
        goto other_case;
    }
minus_one_case:
    func_00442088(buf, D_0064CCF0);
    func_003547c0((s32 *)(base + 0x30), buf);
    goto done;
zero_case:
    func_003547c0((s32 *)(base + 0x30), NULL);
    goto done;
other_case:
    func_00442088(buf, D_0064CD10, (s32)arg1 - 1);
    func_003547c0((s32 *)(base + 0x30), buf);
done:
    *(s8 *)(base + 0x20) = arg1;
    *(s32 *)(base + 0x28) = arg2;
    *(s32 *)(base + 0x2C) = 0;
unchanged: ;
}
/* measured: skipped floor; retail uses COP1 accumulator chain
   (mula.s/madda.s/madd.s) in both interpolation blocks. Body archived in
   build/V035_0035bd20_body.c. */
// FUN_0035BD20 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035bd20);
// FUN_0035BE70
s32 func_0035be70(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(u16 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = func_00354830(p + 0x30);
    }
    return 0;
}

// FUN_0035BEC0
void func_0035bec0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035BF10
u8 *func_0035bf10(s32 arg0, u16 arg1, s32 arg2)
{
    u8 *temp_2;
    u8 *temp_16;

    func_0044ea90(&D_0064CC98, 0x905);
    temp_2 = D_008873F4[0](1, 0x144, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(&D_0064CC98, 0x906);
    }
    temp_16 = func_00451fc0(arg0, &D_0064CD40, 0xC7, 0, 0,
                            (void *)func_0035be70, (void *)func_0035bec0,
                            temp_2);
    *(s16 *)(temp_2 + 0x20) = 0;
    *(s32 *)(temp_2 + 0x2C) = 0;
    *(f32 *)(temp_2 + 0x10) = 353.0f;
    *(s32 *)(temp_2 + 0x14) = 0x42BC0000;
    *(f32 *)(temp_2 + 8) = 300.0f + *(f32 *)(temp_2 + 0x10);
    *(f32 *)(temp_2 + 0xC) = *(f32 *)(temp_2 + 0x14);
    func_0035c480((s32)temp_16, arg1, arg2);
    return temp_16;
}
// FUN_0035C040
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035c040);
// FUN_0035C480
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035c480);
// FUN_0035C670
void func_0035c670(u8 *arg0, f32 *arg1)
{
    *(Float2 *)arg1 = *(Float2 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_0035E820
void func_0035e820(u8 *arg0)
{
    u8 *base;
    s32 i;
    s32 *slot;

    base = *(u8 **)(arg0 + 0x38);
    i = 0;
    goto loop_test;
loop_body:
    slot = (s32 *)(base + i * 4 + 0x448);
    if (*slot != 0) {
        func_0046d280(*slot);
        *slot = 0;
    }
    i++;
loop_test:
    if (i < 11) {
        goto loop_body;
    }
    *(s32 *)(base + 0x24) = 0;
    (*D_008873EC)(base);
}
// FUN_0035E8B0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035e8b0);
// FUN_0035EF80
void func_0035ef80(u8 *arg0)
{
    s32 var_6;
    s32 temp_3;
    s8 temp_4;
    u8 *temp_2;

    temp_2 = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    temp_4 = *(s8 *)(temp_2 + 0x38);
    var_6 = 0;
    temp_3 = *(s32 *)(temp_2 + 0x40);
    switch (temp_3) {
    case 2:
        var_6 |= 1;
        break;
    case 3:
        var_6 |= 2;
        break;
    case 1:
        var_6 |= 4;
        break;
    }
    func_0035bc10((u8 *)*(s32 *)(arg0 + 0x130C), temp_4, var_6);
}
// FUN_0035F020
void func_0035f020(u8 *arg0)
{
    s32 var_6;
    s32 temp_3;
    u16 temp_4;
    u8 *temp_2;

    temp_4 = *(u16 *)((u8 *)add_offset_first((s32)*(s16 *)(arg0 + 0x28) * 2, (u32)arg0) + 0x136);
    var_6 = 0;
    temp_2 = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    temp_3 = *(s32 *)(temp_2 + 0x40);
    switch (temp_3) {
    case 2:
        var_6 |= 1;
        break;
    case 3:
        var_6 |= 2;
        break;
    case 1:
        var_6 |= 4;
        break;
    }
    func_0035c480(*(s32 *)(arg0 + 0x1310), temp_4, var_6);
}
// FUN_0035F0C0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035f0c0);
// FUN_0035FC40
s32 func_0035fc40(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0035FC90
s32 func_0035fc90(u8 *arg0)
{
    s16 temp_2;
    s32 var_17;
    s32 var_16;
    u8 *temp_19;

    var_16 = 1;
    temp_2 = *(s16 *)(arg0 + 0x20);
    if (temp_2 < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp_2 + 1;
    }
    var_17 = 0;
    goto loop_test;
loop_body:
    temp_19 = arg0 + var_17 * 0x30;
    func_001437b0(temp_19 + 0x48, *(s16 *)(arg0 + 0x20), 0);
    if (*(u8 *)(temp_19 + 0x62) != 0) {
        var_16 = 0;
    }
    var_17 += 1;
loop_test:
    if (var_17 < 0x1D) {
        goto loop_body;
    }
    func_00361ae0(arg0);
    func_00361ca0(arg0);
    func_0035fd60(arg0);
    return var_16;
}
// FUN_0035FD60
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035fd60);
