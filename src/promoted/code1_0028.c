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
extern f32 D_00882210[];

typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;

s32 func_00286430(u8 *arg0);

extern s32 D_008825F0[10];



// FUN_002852A0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002852a0);
// FUN_00285330
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00285330);
// FUN_002853B0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002853b0);
// FUN_002853C0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002853c0);
// FUN_002853F0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002853f0);
// FUN_00285CC0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00285cc0);
// FUN_00285DD0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00285dd0);
// FUN_00286240
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_00286240);
// FUN_002862A0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002862a0);
// FUN_00286350
void func_00286350(void) {
    func_00452380(D_0063C368);
}



// FUN_00286380
void func_00286380(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x770) = *(s32 *)(p + 0x770) | 0x1;
}

// FUN_002863B0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002863b0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_002866c0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028bef0);

// FUN_0028BF90
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028bf90);

// FUN_0028BFB0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028bfb0);

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
#pragma pop

// FUN_0028C3F0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c3f0);
// FUN_0028C580
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028c580);
// FUN_0028CED0
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028ced0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0028", func_0028d0a0);