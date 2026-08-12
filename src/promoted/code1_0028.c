#include "include_asm.h"
#include "type.h"

s32 func_00452380(void *arg0);
extern s32 D_0063C368[];

s32 *func_00452560();

void memset(void *arg0, s32 arg1, s32 arg2);
void func_00285260(void);
extern void func_0026be60(s32 arg0);
extern f32 iGpffff809c;
extern f32 iGpffff8218;
extern s32 func_00285af0(void);
extern u8 *func_00285480(u8 *arg0);
extern void func_004598e0(s16 arg0);
extern void func_0046d730(void *arg0, s32 arg1);
extern s32 D_0063C1D0[];
extern u8 D_0063C2B8[];
extern f32 D_00882214[];
extern f32 D_00882218[];
extern f32 D_0088221C[];
extern f32 D_00882220[];
extern f32 D_00882224[];
extern f32 D_00882228[];
extern f32 D_0088222C[];
extern f32 D_00882230[];
extern f32 D_00882234[];
extern f32 D_00882238[];
extern f32 D_0088223C[];
extern f32 D_00882240[];
extern f32 D_00882244[];
extern f32 D_00882210[];
extern s32 func_00144b80(s32 arg0, s32 arg1);
extern void func_00144c90(s32 arg0, s32 arg1);
extern void func_00144e10(s64 arg0);
extern void func_00144ed0(s16 arg0);
extern s64 func_001546a0(s32 arg0, s32 arg1);
extern void func_00440b68();
extern u8 D_0063C310[];

typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;
extern void func_0028b160(s32 *arg0, s32 arg1);
extern u8 *func_0028afe0(void);
extern void func_00285dd0(void);
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);

s32 func_00286430(u8 *arg0);
static inline s32 func_0028_sum(u16 arg0, s16 arg1) {
    return (s32)arg0 + arg1;
}
extern void (*jtbl_008873EC[])(void *ptr);

extern u8 iGpffffa790;

extern s32 D_00882170[];
extern s32 D_008825F0[10];



// FUN_002852A0
void func_002852a0(s32 arg0, s32 arg1) {
    s32 *temp_4;
    s32 *temp_4_2;

    if ((arg0 < 0xD) && (arg0 >= 0)) {
        switch (arg0) {
        case 0:
        case 4:
        case 5:
        case 6:
            temp_4_2 = &D_00882170[arg0];
            *temp_4_2 += arg1;
            break;
        default:
            temp_4 = &D_00882170[arg0];
            *temp_4 += arg1;
            break;
        }
    }
}
// FUN_00285330
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00285330);
// FUN_002853B0
s32 func_002853b0(void) {
    return 0;
}
// FUN_002853C0
void func_002853c0(void) {
    func_00452380(&iGpffffa790);
}
/* measured: retail hoists the lookup table address before the search loop. */
#pragma opt_loop_invariants on
// FUN_002853F0
s32 func_002853f0(s32 arg0) {
    s32 i;

    if (arg0 >= 0x3A) {
        func_0046d730(D_0063C2B8, 0x1E6);
    }
    i = 0;
    while (i < 0x3A) {
        if (arg0 == D_0063C1D0[i]) {
            return i;
        }
        i++;
    }
    return 0;
}
#pragma opt_loop_invariants off
// FUN_00285CC0
s32 func_00285cc0(u8 *arg0) {
    s64 temp_19;
    s32 temp_19_raw;
    s16 temp_18;
    s32 temp_17;
    s32 temp_16;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x90);
    temp_17 = *(s32 *)(temp_3 + 0x10);
    temp_16 = *(s32 *)(temp_3 + 0x14);
    temp_19_raw = *(u8 *)(temp_3 + 0x1A);
    temp_19 = (s16)temp_19_raw;
    temp_18 = *(s16 *)(temp_3 + 0x1C);
    if ((temp_17 == 0) && (temp_16 == 0)) {
        return 0;
    }
    if (func_00144b80(temp_17, temp_16) == 0) {
        return 0;
    }
    func_00144c90(temp_17, temp_16);
    func_00144e10(temp_19);
    if (temp_18 != 0) {
        func_00144ed0(temp_18);
    } else {
        func_00144ed0((s16)func_001546a0(temp_17 & 0xFFFF, temp_16 & 0xFFFF));
    }
    func_00440b68(D_0063C310, temp_17, temp_16);
    return 1;
}
// FUN_00285DD0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00285dd0);
// FUN_00286240
void func_00286240(void) {
    s32 *p;

    p = func_00452560();
    if (*p & 0x80000000) {
        func_0028b160(p, 1);
    } else {
        func_0028b160(p, 0);
    }
}
// FUN_002862A0
void func_002862a0(s32 arg0, s32 arg1) {
    s32 *p;

    p = (s32 *)func_0028afe0();
    p[0x76C / 4] = 0;
    p[0x77C / 4] = arg0;
    if (arg0 != 0) {
        p[0] |= 0x40000000;
    }
    func_00451de0(D_0063C368, 0, 0, 0, (void *)func_00285dd0,
                  (void *)func_00286240, p);
    if (arg1 != 0) {
        p[0] |= 0x80000000;
    }
}
// FUN_00286350
s32 func_00286350(void) {
    return func_00452380(D_0063C368);
}



// FUN_00286380
void func_00286380(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x770) = *(s32 *)(p + 0x770) | 0x1;
}

// FUN_002863B0
s32 func_002863b0(void) {
    return (*(s32 *)((u8 *)func_00452560() + 0x770) & 2) != 0;
}
// FUN_002863E0
void func_002863e0(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_2;

    temp_2 = func_00452560();
    *(s32 *)((u8 *)temp_2 + 0x78C) = arg1;
    *(s32 *)((u8 *)temp_2 + 0x790) = arg2;
    *(s32 *)((u8 *)temp_2 + 0x794) = arg3;
}
// FUN_00286430
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00286430);

// FUN_002865E0
void func_002865e0(UnkStruct_002865E0 *arg0) {
    s32 sp30[15];
    s32 *var_5;
    s32 *var_4;
    s32 *var_5_2;
    s32 *var_4_2;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 var_3_2;

    var_5 = arg0->field_76C;
    var_4 = sp30;
    var_3 = 0xF;
    do {
        temp_2 = *var_5;
        var_5++;
        var_3--;
        *var_4 = temp_2;
        var_4++;
    } while (var_3 > 0);
    temp_17 = *(s32 *)((u8 *)arg0 + 0);
    memset(arg0, 0, 0x7B0);
    var_5_2 = sp30;
    var_4_2 = (s32 *)((u8 *)arg0 + 0x76C);
    var_3_2 = 0xF;
    do {
        temp_2_2 = *var_5_2;
        var_5_2++;
        var_3_2--;
        *var_4_2 = temp_2_2;
        var_4_2++;
    } while (var_3_2 > 0);
    *(s32 *)((u8 *)arg0 + 0) = temp_17;
    func_00285260();
    *(s32 *)((u8 *)arg0 + 0) |= 1;
    *(s32 *)((u8 *)arg0 + 8) = 0x21C;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) - 1;
    if (*(s32 *)((u8 *)arg0 + 0) & 0x80000000) {
        *(s32 *)((u8 *)arg0 + 0x54) = 1;
    }
}



// FUN_002866C0
void func_002866c0(u8 *arg0, s32 *arg1) {
    u8 *temp_3;
    u8 *var_7;

    var_7 = *(u8 **)(arg0 + 0x68);
    if (var_7 == NULL) {
        *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
        *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
        *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
        *(u8 **)((u8 *)arg1 + 0x50) = NULL;
        goto done;
    }
    goto loop_7_check;
loop_7_body:
    if ((s32)*(u16 *)arg1 < (s32)*(u16 *)var_7) {
        temp_3 = *(u8 **)(var_7 + 0x50);
        if (temp_3 == NULL) {
            *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = NULL;
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
        } else {
            *(u8 **)(temp_3 + 0x4C) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(var_7 + 0x50);
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
        }
        goto block_24;
    }
loop_7_next:
    var_7 = *(u8 **)(var_7 + 0x4C);
loop_7_check:
    if (var_7 != NULL) {
        goto loop_7_body;
    }
block_24:
    if (var_7 != NULL) {
        goto done;
    }
    *(u8 **)(*(u8 **)(arg0 + 0x6C) + 0x4C) = (u8 *)arg1;
    *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(arg0 + 0x6C);
    *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
    *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
done:
    *(s32 *)(arg0 + 0x64) = *(s32 *)(arg0 + 0x64) + 1;
}
// FUN_00287BF0
void func_00287bf0(s32 arg0, u8 *arg1) {
    u8 *var_17;
    u8 *var_16;
    u16 temp_4;

    var_17 = *(u8 **)(arg1 + 0x4C);
    while (var_17 != NULL) {
        if (*(s32 *)var_17 == 0x26) {
            var_16 = *(u8 **)(var_17 + 0x68);
            while (var_16 != NULL) {
                if (func_00286430(var_16) != 0) {
                    temp_4 = *(u16 *)var_16;
                    if (((s32)temp_4 <= arg0) && ((temp_4 + *(s16 *)(var_16 + 0x12)) >= arg0)) {
                        *(s32 *)(arg1 + 0x20) = *(s16 *)(var_16 + 0x10);
                        *(s32 *)(arg1 + 0x1C) = 1;
                        return;
                    }
                }
                var_16 = *(u8 **)(var_16 + 0x4C);
            }
        }
        var_17 = *(u8 **)(var_17 + 0x90);
    }
}



// FUN_0028B650
s32 func_0028b650(void) {
    s32 h = func_00285af0();

    if (h == 0) {
        return 0;
    }
    return *(s32 *)(func_00285480((u8 *)func_00452560(h)) + 0x768) != 0;
}

// FUN_0028B6B0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028b6b0);
// FUN_0028B7B0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028b7b0);
// FUN_0028BE70
void func_0028be70(u8 *arg0, s32 arg1)
{
    if (arg1 < 2) {
        switch (arg1) {
        case 0:
            func_0026be60(0x1E58);
            break;
        case 1:
            func_0026be60(0x1E59);
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0x524) = arg1;
    }
}

// measured: required for exact retail loop codegen in func_0028c370.
#pragma push
#pragma opt_loop_invariants on

// FUN_0028BEF0
s32 func_0028bef0(s32 arg0, u8 *arg1, s32 *arg2, s32 *arg3) {
    s32 temp_3_2;
    s8 temp_3;

    *arg2 = (s32)((s16)*(s16 *)(arg1 + 0x10) & 0xFFF);
    *arg3 = (((s16)*(s16 *)(arg1 + 0x10) >> 0xC) & 0xF);
    temp_3 = *(s8 *)(arg1 + 0x15);
    switch (temp_3) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        temp_3_2 = *(s32 *)((u8 *)(temp_3 * 4) + arg0 + 0x694);
        if (temp_3_2 == -1) {
            return 0;
        }
        *arg2 += temp_3_2;
        goto block_6;
    case 6:
        return 0;
    default:
block_6:
        return 1;
    }
}

// FUN_0028BF90
f32 func_0028bf90(s32 arg0) {
    return (f32)arg0 + 2.0f;
}

// FUN_0028BFB0
void func_0028bfb0(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3) {
    u8 *temp_3;
    s16 temp_8;
    s32 temp_6;

    *arg2 = NULL;
    *arg3 = NULL;
    if (arg0 == NULL) {
        goto done;
    }
    temp_8 = *(s16 *)(arg0 + 0x1C);
    *arg3 = *(u8 **)(arg0 + 0x68);
    goto loop_4_test;
loop_4_body:
    temp_6 = func_0028_sum(*(u16 *)temp_3, temp_8);
    if (temp_6 > arg1) {
        goto block_8;
    }
    *arg3 = *(u8 **)(temp_3 + 0x4C);
loop_4_test:
    temp_3 = *arg3;
    if (temp_3 != NULL) {
        goto loop_4_body;
    }
block_8:
    if (temp_3 != NULL) {
        *arg2 = *(u8 **)(temp_3 + 0x50);
        goto loop_10_test;
    }
    *arg2 = *(u8 **)(arg0 + 0x6C);
    goto loop_10_test;
loop_10_body:
    if (func_00286430(*arg2) == 1) {
        goto done;
    }
    *arg2 = *(u8 **)(*arg2 + 0x50);
loop_10_test:
    if (*arg2 != NULL) {
        goto loop_10_body;
    }
done:
    return;
}

// FUN_0028C080
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c080);
// FUN_0028C370
void func_0028c370(void)
{
    f32 fVar1;
    f32 fVar2;
    s32 iVar3;
    f32 *pfVar4;
    f32 *pfVar5;
    u32 uVar6;

    iVar3 = 0;
    pfVar5 = D_00882210;
    fVar1 = iGpffff809c;
    fVar2 = iGpffff8218;
    uVar6 = 0x40e00000;
    for (; iVar3 < 3; iVar3 = iVar3 + 1) {
        pfVar4 = &pfVar5[iVar3 * 0x10];
        pfVar4[2] = fVar1;
        pfVar4[3] = fVar1;
        pfVar4[4] = fVar1;
        pfVar4[5] = 0.0f;
        pfVar4[6] = 0.0f;
        pfVar4[7] = 0.0f;
        pfVar4[8] = 0.0f;
        pfVar4[9] = 0.0f;
        pfVar4[10] = fVar2;
        pfVar4[11] = fVar2;
        pfVar4[12] = fVar2;
        pfVar4[13] = 0.0f;
        ((u32 *)pfVar4)[14] = uVar6;
        pfVar4[15] = 0.0f;
        pfVar4[0] = 0.0f;
        pfVar4[1] = 0.0f;
    }
}
/* measured: restore pragma state after func_0028c370. */
#pragma pop

// FUN_0028C3F0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c3f0);
// FUN_0028C580
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c580);
// FUN_0028CED0
void func_0028ced0(s32 arg0, s32 arg1, s32 arg2, f32 *arg3,
                   f32 *arg4, f32 *arg5) {
    s32 temp_3;

    if (arg0 < 3) {
        temp_3 = arg0 << 6;
        *(f32 *)((u8 *)D_00882218 + temp_3) = arg3[0];
        *(f32 *)((u8 *)D_0088221C + temp_3) = arg3[1];
        *(f32 *)((u8 *)D_00882220 + temp_3) = arg3[2];
        *(u32 *)((u8 *)D_00882224 + temp_3) = 0;
        *(f32 *)((u8 *)D_00882228 + temp_3) = arg4[0];
        *(f32 *)((u8 *)D_0088222C + temp_3) = arg4[1];
        *(f32 *)((u8 *)D_00882230 + temp_3) = arg4[2];
        *(f32 *)((u8 *)D_00882234 + temp_3) = arg4[3];
        *(f32 *)((u8 *)D_00882238 + temp_3) = arg5[0];
        *(f32 *)((u8 *)D_0088223C + temp_3) = arg5[1];
        *(f32 *)((u8 *)D_00882240 + temp_3) = arg5[2];
        *(u32 *)((u8 *)D_00882244 + temp_3) = 0x3F800000;
        *(s32 *)((u8 *)D_00882210 + temp_3) = arg1;
        if (arg1 == 3) {
            *(s32 *)((u8 *)D_00882214 + temp_3) = arg2;
            return;
        }
        *(s32 *)((u8 *)D_00882214 + temp_3) = 0;
    }
}
// FUN_0028D020
void func_0028d020(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA) || (arg0 < 0)) {
        return;
    }
    D_008825F0[arg0] = arg1;
}



// FUN_0028D060
s32 func_0028d060(s32 arg0) {
    if (arg0 >= 0xA) {
        return -1;
    }
    return D_008825F0[arg0];
}

// FUN_0028D0A0
void func_0028d0a0(u8 *arg0) {
    s32 i;

    i = 0;
    while (i < *(s32 *)(arg0 + 0xD4)) {
        func_004598e0(*(s16 *)(arg0 + i * 4 + 0xD8));
        i++;
    }
    *(s32 *)(arg0 + 0xD4) = 0;
}
