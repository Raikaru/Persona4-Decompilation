#include "type.h"
#include "include_asm.h"

/* Old-style declaration: the donor source called this without a prototype, and
 * several call sites below pass an argument (a0 is set by the caller), which a
 * (void) prototype would forbid. */
s32 *func_00452560();
void func_004ab680(s32 arg0);
void func_004ab140(s32 arg0);
extern void (*jtbl_008873EC[])(void *);

void func_0044ea90(const void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
s32 func_00452490(s32 buf);
s32 func_004553c0(s32 arg0);
void func_00454bd0(s32 arg0);
s32 func_004426e8(s32 *arg0, s32 arg1);
s32 func_00442830(s32 *arg0, s32 arg1);
s32 func_002852a0(s32 arg0, s32 arg1);
void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
s32 func_00454a60(void *arg0, s32 arg1);
u8 *func_00455f70(void *arg0, u32 *arg1);
s32 func_0029da90(s32 arg0, u8 *arg1, s32 arg2);
u8 *func_00457130(void);
void *func_00457120(void);
s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                 s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
s32 func_0028ee00(u8 *arg0);
void func_0028f360(void);
s32 func_0028f540(u8 *arg0);
void func_0028f6c0(u8 *arg0);
void func_0028f4f0(void);

/* Scalars (complete types) address gp-relative; strings/arrays use absolute
 * lui/addiu addressing. D_00763898 and the D_00764Bxx bytes are GPREL16 in
 * retail, so they must stay scalar-typed; the others are absolute. */
extern s32 D_00763898;
extern s32 D_007638A0;
extern u8 D_00764B3C;
extern u8 D_00764B40;
extern u8 D_00764B44;
extern f32 D_00764B5C;
extern u8 D_00748340[];
extern u8 D_0063C638[];
extern u8 D_0063C690[];
extern void *(*D_008873F4[])(s32, s32, s32);

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

typedef struct { f32 x, y, z; } SVec3;



// FUN_0028D110
void func_0028d110(s32 *arg0) {
    s32 *temp_16;

    if (arg0[0x10] != 0) {
        return;
    }
    func_0044ea90(D_00748340, 0x52);
    temp_16 = (s32 *)D_008873F4[0](1, 0x130, 0x40000);
    func_002852a0(0xA, 0x130);
    arg0[0x10] = (s32)temp_16;
    if (temp_16 == 0) {
        func_0046d730(D_0063C638, 0x1068);
    }
}

/* measured: without opt_loop_invariants on, MWCC rematerializes the loop
 * comparison constant (addiu v1,zero,1) inside the body instead of the
 * preheader, shifting every temp register (nd 18). */
#pragma opt_loop_invariants on

// FUN_0028D1B0
void func_0028d1b0(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 temp_7;
    s32 temp_10;
    s32 var_11;

    if (arg0[0] != 0) {
        return;
    }
    temp_7 = arg0[1];
    temp_10 = temp_7 * 3 + 1;
    arg1[0] = temp_7;
    var_11 = 0;
    while (var_11 < temp_10) {
        if (arg2 == 1) {
            s32 off = ((temp_10 - 1) - var_11) * 12;
            *(SVec3 *)(arg1 + var_11 * 12 + 4) = *(SVec3 *)(arg0 + off + 4);
        } else {
            s32 off = var_11 * 12;
            *(SVec3 *)(arg1 + off + 4) = *(SVec3 *)(arg0 + off + 4);
        }
        var_11++;
    }
}
/* measured: see annotation above (func_0028d1b0). */
#pragma opt_loop_invariants off

// FUN_0028D280
s32 func_0028d280(void) {
    s32 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560();
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        func_004ab8a0(temp_2[1]);
        temp_2[2] = temp_2[2] + 1;
        break;
    case 1:
        func_004ab360(temp_2[1]);
        temp_2[2] = temp_2[2] + 1;
        break;
    }
    return 0;
}

// FUN_0028D310
void func_0028d310(void) {
    s32 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560();
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        func_004ab680(temp_2[1]);
        break;
    case 1:
        func_004ab140(temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0028D390
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028d390);

// FUN_0028DC30
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028dc30);

// FUN_0028EE00
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028ee00);

// FUN_0028F360
void func_0028f360(void)
{
    extern s32 *func_00452560(void);
    int iVar1;

    iVar1 = (s32)func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_0028F3A0
void func_0028f3a0(s32 arg0, s32 *arg1, s32 arg2) {
    s32 v;
    s32 acc;
    s32 t;
    u8 *dst;
    s32 *p;
    s32 *src;
    s32 i;

    func_0028f4f0();
    func_0044ea90(D_0063C638, 0x12E4);
    p = (s32 *)D_008873F4[0](1, 0x30, 0x40000);
    src = arg1;
    dst = (u8 *)p + 4;
    i = 5;
    do {
        v = *src;
        src++;
        i--;
        *(s32 *)dst = v;
        dst += 4;
    } while (i > 0);
    p[0xB] = arg2;
    p[6] = 1;
    p[7] = ((D_00764B3C << 16) | (D_00764B40 << 8)) | D_00764B44;
    acc = func_00457130()[0] << 16;
    acc |= func_00457130()[1] << 8;
    t = func_00457130()[2];
    p[8] = t | acc;
    *(f32 *)(p + 9) = *(f32 *)((u8 *)func_00457120() + 0x88);
    *(f32 *)(p + 0xA) = D_00764B5C;
    func_00451fc0(arg0, &D_00763898, 0xF, 0, 0, func_0028ee00,
                  (void (*)(u8 *))func_0028f360, p);
}

// FUN_0028F4F0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f4f0);

// FUN_0028F530
void func_0028f530(void) {
}

// FUN_0028F540
s32 func_0028f540(u8 *arg0) {
    s32 *p;
    u32 local_3C;
    u8 *s1;

    p = func_00452560();
    switch (p[0]) {
    case 0:
        if (p[0x43] != 0) {
            func_00454bd0(p[0x43]);
            p[0x43] = 0;
        }
        func_00440b68(&D_007638A0, D_0063C638, 0x1344);
        p[0x43] = func_00454a60(&p[3], 0);
        p[0] = 1;
    case 1:
        if (func_004553c0(p[0x43]) != 0) {
            p[0] = 2;
        }
        break;
    case 2:
        s1 = func_00455f70(&p[3], &local_3C);
        if (p[0x44] != 0) {
            func_0046d730(D_0063C638, 0x134E);
        }
        p[0x44] = func_0029da90(p[2], s1, p[1]);
        if (p[0x44] == 0) {
            func_0046d730(D_0063C638, 0x1350);
        }
        p[0] = 3;
    case 3:
        if (func_00452490(p[0x44]) != 0) {
            break;
        }
        p[0x44] = 0;
        p[0] = 4;
        break;
    case 4:
        break;
    }
    return 0;
}

// FUN_0028F6C0
void func_0028f6c0(u8 *arg0) {
    s32 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0x44] != 0 && func_00452490(temp_2[0x44]) != 0) {
        func_00452080(temp_2[0x44]);
    }
    if (temp_2[0x43] != 0) {
        if (func_004553c0(temp_2[0x43]) == 0) {
            func_0046d730(D_0063C638, 0x1364);
        }
        func_00454bd0(temp_2[0x43]);
    }
    jtbl_008873EC[0](temp_2);
}

// FUN_0028F770
void func_0028f770(s32 arg0) {
    s32 *temp_2;

    func_0044ea90(D_0063C638, 0x1370);
    temp_2 = (s32 *)D_008873F4[0](1, 0x114, 0x40000);
    temp_2[0] = 4;
    func_00451fc0(arg0, &D_0063C690, 0xF, 0, 0, func_0028f540, func_0028f6c0,
                  temp_2);
}

// FUN_0028F800
s32 func_0028f800(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_2;

    if (func_00452490(arg0) == 0) {
        func_0046d730(D_0063C638, 0x137E);
    }
    temp_2 = func_00452560(arg0);
    if (temp_2[0] == 4) {
        temp_2[2] = arg1;
        temp_2[1] = arg3;
        if (func_004426e8(&temp_2[3], arg2) == 0) {
            temp_2[0] = 2;
        } else {
            func_00442830(&temp_2[3], arg2);
            temp_2[0] = 0;
        }
        return 1;
    }
    return 0;
}

// FUN_0028F8E0
s32 func_0028f8e0(s32 arg0) {
    if (func_00452490(arg0) == 0) {
        func_0046d730(D_0063C638, 0x1393);
    }
    if (func_00452560(arg0)[0] == 4) {
        return 1;
    }
    return 0;
}

