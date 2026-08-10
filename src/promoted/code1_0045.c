#include "include_asm.h"
#include "type.h"
extern f32 D_008872F8_abs[];
extern f32 D_008872FC_abs[];
extern u8 *iGpffffb9e0;
extern s32 iGpffffac74;
extern s32 iGpffffad88;
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern void func_003e18c0(void *object, void *callback, s32 userdata);
extern void func_003bff30(void *object, void *callback, void *userdata);
extern void func_003ca270(void *object, void *callback, void *userdata);
extern void func_003c21e0();
extern void func_004526f0(u8 *arg0, s32 arg1);
extern void func_004587d0(void);
extern u8 *func_00458c40(u8 *arg0, s32 arg1);
extern void func_00458ce0(void);
extern u8 *func_00458f00(u8 *arg0, s32 arg1);
extern u8 D_007117B0[];
extern u8 D_00711738[];
extern void func_004244c8(u8 *arg0);
extern void func_00426f80(s32 arg0);
extern void func_00428f08(void *arg0, s32 arg1);
extern s32 iGpffffba80;
extern s32 iGpffffba70;
extern s32 iGpffffba74;
extern s32 iGpffffba78;
extern s32 iGpffffba7c;
extern s8 iGpffffba84;
extern s8 iGpffffba85;
extern s8 iGpffffba86;
extern s8 iGpffffba87;
extern s8 iGpffffba88;
extern s8 iGpffffba89;
extern s8 iGpffffba8a;
extern s8 iGpffffba8b;
extern s32 iGpffffba10;
extern void (*D_008873FC[])(s32 param, u8* arg);

extern s32 D_008D2B90[];
extern s16 D_008D2B98[];

extern s32 D_008D2F2C[];
extern s16 D_008D2F34[];
extern u8 D_008C02EC[];
extern u8 D_008C02EE[];
extern u8 D_008C02F2[];
extern u8 D_008C0300[];
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];

extern void func_0042eae0(s32 arg0);
extern void func_0042f600(s32 arg0);
extern void func_0042efe0(s32 arg0);
extern void func_00468a10(s32 arg0);
extern u8 D_008C8780[];
extern u8 D_008D1B80[];
extern u8 D_008D1B84[];
extern u8 D_008D1B88[];
extern u8 D_008D1C90[];
extern u8 D_008D1C98[];
extern u8 D_008D1CD4[];


/* measured: object 92B vs window 96B, normalized_diff 15; residual load ordering and FPU register coloring. */
// Committed at nd 15.
// FUN_00450490
#ifdef NON_MATCHING
f32 func_00450490(f32 fparg0)
{
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f0;
    f32 temp_f1;

    temp_f4 = D_008872FC_abs[0];
    temp_f2 = *(f32 *)(iGpffffb9e0 + 0x84);
    temp_f3 = *(f32 *)(iGpffffb9e0 + 0x80);
    temp_f0 = D_008872F8_abs[0];
    temp_f1 = temp_f0 - temp_f4;
    temp_f0 = temp_f3 - temp_f2;
    temp_f1 = temp_f1 / temp_f0;
    temp_f0 = fparg0 - temp_f2;
    temp_f2 = temp_f0 * temp_f1;
    temp_f0 = temp_f3 / fparg0;
    temp_f1 = temp_f4 + temp_f0 * temp_f2;
    if (temp_f1 < 0.0f) {
        temp_f1 = 0.0f;
    }
    return temp_f1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450490);
#endif
// FUN_00450630
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450630);
// FUN_00450A50
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450a50);
// FUN_00450DD0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450dd0);
// FUN_00450E80
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00450e80);
// FUN_004526A0
void func_004526a0(u8 *arg0) {
    u8 *var_6;
    u8 *var_5;

    var_6 = *(u8 **)(arg0 + 0x4C);
    goto loop_004526a0_check;
loop_004526a0_body:
    if (*(u8 **)(var_6 + 0x48) == arg0) {
        var_5 = var_6;
    }
    var_6 = *(u8 **)(var_6 + 0x50);
    *(s32 *)(var_5 + 0x48) = 0;
    *(s32 *)(var_5 + 0x50) = 0;
loop_004526a0_check:
    if (var_6 != NULL) {
        goto loop_004526a0_body;
    }
}
// FUN_004526E0
s32 func_004526e0(void)
{
    return iGpffffba10;
}
// FUN_004526F0
void func_004526f0(u8* arg0, s32 arg1)
{
    (*D_008873FC)(arg1, arg0);
}



// FUN_00452730
void func_00452730(void *arg0)
{
    func_003e18c0(arg0, func_004526f0, (s32)arg0);
}
// FUN_00452760
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452760);
// FUN_00452870
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452870);
// FUN_00452CE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452ce0);
// FUN_00452DB0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00452db0);
// FUN_004530B0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004530b0);
// Parked register-coloring residual (object exact, normalized_diff 16). Committed at nd 16.
// FUN_00453250
#ifdef NON_MATCHING
void func_00453250(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_4;
    u8 *temp_6;
    u16 *temp_4_2;
    s32 temp_7;

    temp_7 = arg0 * 0x4A;
    temp_4 = arg1 & 0xFFFF;
    if (temp_4 & *(u16 *)(D_008C02EE + temp_7)) {
        *(u8 *)(D_008C0300 + temp_7 + arg2) = 7;
        return;
    }
    if (temp_4 & *(u16 *)(D_008C02EC + temp_7)) {
        temp_6 = D_008C0300 + temp_7 + arg2;
        *temp_6 -= 1;
        if (*temp_6 == 0) {
            temp_4_2 = (u16 *)(D_008C02F2 + temp_7);
            *temp_4_2 |= arg1;
            *temp_6 = 3;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00453250);
#endif
// Parked register-coloring residual (object exact, normalized_diff 16). Committed at nd 16.
// FUN_00453310
#ifdef NON_MATCHING
void func_00453310(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_7;
    s32 temp_4;
    u16 *temp_4_2;
    u8 *temp_6;

    temp_7 = arg0 * 0x4A;
    temp_4 = arg1 & 0xFFFF;
    if (temp_4 & *(u16 *)(D_008C0316 + temp_7)) {
        *(u8 *)(D_008C031E + temp_7 + arg2) = 7;
        return;
    }
    if (temp_4 & *(u16 *)(D_008C0314 + temp_7)) {
        temp_6 = D_008C031E + temp_7 + arg2;
        *temp_6 -= 1;
        if (*temp_6 == 0) {
            temp_4_2 = (u16 *)(D_008C031A + temp_7);
            *temp_4_2 |= arg1;
            *temp_6 = 3;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00453310);
#endif
// FUN_004533D0
void func_004533d0(void)
{
    s16 temp_3;
    s16 temp_4;
    s16 temp_5;

    temp_4 = iGpffffba1c;
    switch (temp_4) {
    case 0:
        iGpffffba34 = 0;
        iGpffffba2c = 0;
        iGpffffba20 = 0;
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        iGpffffba1c = (s16)(temp_4 + 1);
        return;
    case 1:
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        return;
    case 2:
        if (iGpffffba34 == 0) {
            iGpffffba1c = 1;
            return;
        }
        temp_3 = iGpffffba30;
        if (temp_3 == 0) {
            if (iGpffffba24 == 0) {
                temp_5 = iGpffffba20;
                D_008C030C[0] = temp_5 & 1;
                D_008C030E[0] = temp_5 & 0xFF;
                iGpffffba30 = iGpffffba2c;
                iGpffffba24 = 1;
            } else {
                D_008C030C[0] = 0;
                D_008C030E[0] = 0;
                iGpffffba30 = iGpffffba28;
                iGpffffba24 = 0;
            }
        } else {
            iGpffffba30 = (s16)(temp_3 - 1);
        }
        iGpffffba34 -= 1;
        return;
    }
}
// FUN_004534F0
void func_004534f0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (func_004535b0() == 0) {
        return;
    }
    iGpffffba34 = arg0;
    iGpffffba30 = 0;
    iGpffffba2c = arg2;
    iGpffffba28 = arg3;
    iGpffffba20 = arg1;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}

// FUN_004535B0
s32 func_004535b0(void)
{
    return iGpffffac74;
}

// FUN_004543D0
s32 func_004543d0(u8 *arg0) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_6;

    temp_2 = *(s32 *)(arg0 + 0x14);
    temp_5 = *(s32 *)(arg0 + 0x20);
    var_6 = temp_2;
    if (temp_5 < temp_2) {
        var_6 = temp_5;
    }
    temp_3 = *(s32 *)(arg0 + 0x28);
    if ((temp_3 + temp_2) >= temp_5) {
        goto zero;
    }
    temp_2_2 = temp_3 + *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = temp_2_2;
    temp_5_2 = *(s32 *)(arg0 + 0x14);
    temp_3_2 = *(s32 *)(arg0 + 0x20);
    if (temp_3_2 >= (temp_2_2 + temp_5_2)) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = temp_3_2 - temp_5_2;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = temp_5 - var_6;
    *(s32 *)(arg0 + 0x24) = var_6 - 1;
    return 0;
one:
    return 1;
}
// FUN_00454460
/* The three exits are laid out with explicit gotos because retail places the
   `return 0` block and the `return 1` block out of line, in that order, after
   the main body. The natural nested-if / result-variable spellings all merge
   them into one epilogue and come out two words short (nd 24). */
s32 func_00454460(u8 *arg0) {
    s32 v;
    s32 t;

    v = *(s32 *)(arg0 + 0x28);
    if (v <= 0) {
        goto zero;
    }
    t = v - *(s32 *)(arg0 + 0x1C);
    *(s32 *)(arg0 + 0x28) = t;
    if (t >= 0) {
        goto one;
    }
    *(s32 *)(arg0 + 0x28) = 0;
    goto one;
zero:
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 0;
one:
    return 1;
}

// FUN_004544B0
void func_004544b0(void)
{
    s32 var_4;
    u8 *temp_base;

    func_0042eae0(0);
    func_0042f600(2);
    func_0042efe0(0);
    *(u8 **)D_008D1B80 = NULL;
    *(u8 **)D_008D1B84 = NULL;
    *(s32 *)D_008D1C90 = 0;
    *(s32 *)D_008D1C98 = 0;
    *(s32 *)D_008D1B88 = 0;
    var_4 = 0;
    temp_base = D_008C8780;
    while (var_4 < 0x100) {
        *(s32 *)(temp_base + (var_4 * 0x94)) = 0;
        var_4 += 1;
    }
    *(s32 *)D_008D1CD4 = 0;
    func_00468a10(var_4);
}
// FUN_004556B0
s32 func_004556b0(u8* arg0, u32 arg1)
{
    if (arg1 < *(u32*)(arg0 + 4)) {
        return (s32)(*(u8**)(arg0 + 0x58) + arg1 * 0x110);
    }
    return 0;
}



// FUN_00456530
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456530);
// FUN_004566C0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004566c0);
// FUN_00456840
void func_00456840(u8 *arg0) {
    func_004244c8(D_00711738);
    *(s32 *)(arg0 + 0x38) = 1;
    func_00426f80(*(s32 *)(arg0 + 0x74));
    func_00428f08(&iGpffffad88, 0);
}

// FUN_00456C30
u8 *func_00456c30(void)
{
    func_004244c8(D_007117B0);
    return (u8 *)&iGpffffad88;
}
// FUN_00456C60
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456c60);
// FUN_00456E40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00456e40);
// FUN_00457120
s32 func_00457120(void)
{
    return iGpffffba80;
}

// FUN_00457130
s8 *func_00457130(void)
{
    return &iGpffffba88;
}
// FUN_00457140
void func_00457140(s8 arg0, s8 arg1, s8 arg2, s8 arg3)
{
    iGpffffba88 = arg0;
    iGpffffba89 = arg1;
    iGpffffba8a = arg2;
    iGpffffba8b = arg3;
}
// FUN_00457160
s8 *func_00457160(void)
{
    return (s8 *)&iGpffffba84;
}
// FUN_00457170
void func_00457170(s8 arg0, s8 arg1, s8 arg2, s8 arg3)
{
    iGpffffba84 = arg0;
    iGpffffba85 = arg1;
    iGpffffba86 = arg2;
    iGpffffba87 = arg3;
}
// FUN_00457190
s32 func_00457190(void)
{
    return iGpffffba70;
}

// FUN_004571A0
s32 func_004571a0(void)
{
    return iGpffffba74;
}

// FUN_004571B0
s32 func_004571b0(void)
{
    return iGpffffba78;
}

// FUN_004571C0
s32 func_004571c0(void)
{
    return iGpffffba7c;
}

// FUN_00457630
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00457630);
// FUN_004585C0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004585c0);
// FUN_004586F0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004586f0);
// FUN_004587D0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_004587d0);
/* Measured callback-wrapper idiom: preserve the object in s0, move userdata to a2, and call the shared iterator with the object field and callback. */
// FUN_00458C40
u8 *func_00458c40(u8 *arg0, s32 arg1)
{
    func_003c21e0(*(s32 *)(arg0 + 0x18), func_004587d0, arg1);
    return arg0;
}
// FUN_00458C80
void func_00458c80(void *arg0, void *arg1)
{
    func_003bff30(arg0, func_00458c40, arg1);
}
// FUN_00458CB0
void func_00458cb0(void *arg0, void *arg1)
{
    func_003ca270(arg0, func_004587d0, arg1);
}
// FUN_00458CE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_00458ce0);
// FUN_00458F00
u8 *func_00458f00(u8 *arg0, s32 arg1)
{
    func_003c21e0(*(s32 *)(arg0 + 0x18), func_00458ce0, arg1);
    return arg0;
}
// FUN_00458F40
void func_00458f40(void *arg0, void *arg1)
{
    func_003bff30(arg0, func_00458f00, arg1);
}
// FUN_00458F70
void func_00458f70(void *arg0, void *arg1)
{
    func_003ca270(arg0, func_00458ce0, arg1);
}
// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}



// FUN_0045B400
s16 func_0045b400(void)
{
    if (D_008D2F2C[0] == 0) {
        return -1;
    }
    return D_008D2F34[0];
}

// FUN_0045B430
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045b430);
// FUN_0045C870
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045c870);
// FUN_0045CE40
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ce40);
// FUN_0045D370
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d370);
// FUN_0045D6E0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d6e0);
// FUN_0045D890
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d890);
// FUN_0045ED60
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ed60);
// FUN_0045EE00
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045ee00);
// FUN_0045FBE0
INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045fbe0);