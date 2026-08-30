#include "type.h"
#include "include_asm.h"
extern s32 func_00452380();
extern u8 iGpffffa7a8;

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
void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s32 iGpffffba48;

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
typedef unsigned int EvtU128 __attribute__((mode(TI)));
u8 *func_004ab420(s32 type, void *data);
s32 func_004ab960(void *data, s32 size);
extern u8 D_0063C648[];

typedef struct {
    u8 type;
    u8 pad01[3];
    u32 color0;
    u32 color1;
    u32 color2;
    f32 alpha0;
    u32 color3;
    f32 alpha1;
    u8 pad1C[8];
    s32 value24;
    s32 value28;
    f32 value2C;
    f32 value30;
    u8 pad34[4];
    f32 value38;
    f32 value3C;
    u8 pad40[0x24];
    f32 value64;
    f32 value68;
    u8 pad6C[0x24];
    f32 value90;
    f32 value94;
    u8 pad98[0x20];
    s32 valueB8;
    u8 active;
    u8 padBD[3];
} EvtFilterParams;

typedef struct {
    EvtFilterParams params;
    u8 extra[0x24];
    u8 padE4[0xC];
} EvtFilter2;

typedef struct {
    EvtFilterParams params;
    u8 extra[0x18];
    u8 padD8[4];
    s32 argument;
} EvtFilter1;

typedef struct {
    EvtFilterParams params2;
    EvtFilterParams params1;
    u8 extra2[0x24];
    u8 pad1A4[0xC];
    u8 extra1[0x18];
    u8 pad1C8[8];
    EvtFilter2 filter2;
    EvtFilter1 filter1;
} EvtFilterFrame;



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



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0028D390
void func_0028d390(s32 arg0, s32 type, u8 *arg2)
{
    EvtFilterFrame frame;
    s32 mode1;
    s32 mode2;
    u8 *filter2;
    s32 *task1;
    s32 *task2;

    switch (type) {
    case 1:
        mode1 = 0;
        if (arg2[0x1B] & 1) {
            mode1 = 1;
            if (arg2[0x1B] & 2) {
                mode1 = 2;
            }
        }

        {
            u8 *var;
            s32 remaining;

            var = (u8 *)&frame.params1;
            remaining = sizeof(frame.params1);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        frame.params1.type = mode1;
        frame.params1.color0 = (arg2[0x1A] << 16) | 0xFF000000 |
                               (arg2[0x19] << 8) | arg2[0x18];
        frame.params1.color1 = (arg2[0x26] << 16) | 0xFF000000 |
                               (arg2[0x25] << 8) | arg2[0x24];
        frame.params1.color2 = (arg2[0x1E] << 16) | 0xFF000000 |
                               (arg2[0x1D] << 8) | arg2[0x1C];
        frame.params1.alpha0 = (f32)arg2[0x1F] / 100.0f;
        frame.params1.color3 = (arg2[0x22] << 16) | 0xFF000000 |
                               (arg2[0x21] << 8) | arg2[0x20];
        frame.params1.alpha1 = (f32)arg2[0x23] / 100.0f;
        frame.params1.value24 = arg2[0x27];
        frame.params1.value28 = arg2[0x1B] >> 4;
        frame.params1.value2C = (f32)arg2[0x28] / 100.0f;
        frame.params1.value30 = (f32)arg2[0x29] / 100.0f;
        frame.params1.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        frame.params1.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        frame.params1.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        frame.params1.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        frame.params1.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        frame.params1.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        frame.params1.valueB8 = *(s16 *)(arg2 + 0x10);

        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;

            source = (EvtU128 *)&frame.params1;
            destination = (EvtU128 *)&frame.filter1.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }

        {
            u8 *var;
            s32 remaining;

            var = frame.extra1;
            remaining = sizeof(frame.extra1);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value0;
            u32 value1;
            s32 blocks;

            source = (u32 *)frame.extra1;
            destination = (u32 *)frame.filter1.extra;
            blocks = 3;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }

        func_0044ea90(D_0063C638, 0x11E0);
        task1 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task1[0] = 0;
        task1[1] = (s32)func_004ab420(1, &frame.filter1);
        task1[3] = frame.filter1.params.valueB8;
        func_00451fc0(arg0, D_0063C648, 0xF, 0, 0,
                      (s32 (*)(u8 *))func_0028d280,
                      (void (*)(u8 *))func_0028d310, task1);
        break;

    case 2:
        mode2 = 0;
        if (arg2[0x1B] & 1) {
            mode2 = 1;
            if (arg2[0x1B] & 2) {
                mode2 = 2;
            }
        }

        {
            u8 *var;
            s32 remaining;

            var = (u8 *)&frame.params2;
            remaining = sizeof(frame.params2);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        frame.params2.type = mode2;
        frame.params2.color0 = (arg2[0x1A] << 16) | 0xFF000000 |
                               (arg2[0x19] << 8) | arg2[0x18];
        frame.params2.color1 = (arg2[0x26] << 16) | 0xFF000000 |
                               (arg2[0x25] << 8) | arg2[0x24];
        frame.params2.color2 = (arg2[0x1E] << 16) | 0xFF000000 |
                               (arg2[0x1D] << 8) | arg2[0x1C];
        frame.params2.alpha0 = (f32)arg2[0x1F] / 100.0f;
        frame.params2.color3 = (arg2[0x22] << 16) | 0xFF000000 |
                               (arg2[0x21] << 8) | arg2[0x20];
        frame.params2.alpha1 = (f32)arg2[0x23] / 100.0f;
        frame.params2.value24 = arg2[0x27];
        frame.params2.value28 = arg2[0x1B] >> 4;
        frame.params2.value2C = (f32)arg2[0x28] / 100.0f;
        frame.params2.value30 = (f32)arg2[0x29] / 100.0f;
        frame.params2.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        frame.params2.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        frame.params2.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        frame.params2.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        frame.params2.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        frame.params2.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        frame.params2.valueB8 = *(s16 *)(arg2 + 0x10);

        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;

            source = (EvtU128 *)&frame.params2;
            destination = (EvtU128 *)&frame.filter2.params;
            blocks = 6;
            do {
                value0 = source[0];
                value1 = source[1];
                source += 2;
                blocks--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (blocks > 0);
        }
        frame.filter2.params.active = 1;

        {
            u8 *var;
            s32 remaining;

            var = frame.extra2;
            remaining = sizeof(frame.extra2);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        {
            u32 *source;
            u32 *destination;
            u32 value;
            s32 blocks;

            source = (u32 *)frame.extra2;
            destination = (u32 *)frame.filter2.extra;
            blocks = 9;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        frame.filter1.argument = arg2[0x2A];

        filter2 = func_004ab420(2, &frame.filter2);
        *(s32 *)(filter2 + 0x28) =
            func_004ab960(&frame.filter1.argument, sizeof(frame.filter1.argument));
        func_0044ea90(D_0063C638, 0x11E0);
        task2 = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task2[0] = 0;
        if (filter2 != NULL) {
            task2[1] = (s32)filter2;
        } else {
            task2[1] = (s32)func_004ab420(2, &frame.filter2);
        }
        task2[3] = frame.filter2.params.valueB8;
        func_00451fc0(arg0, D_0063C648, 0xF, 0, 0,
                      (s32 (*)(u8 *))func_0028d280,
                      (void (*)(u8 *))func_0028d310, task2);
        break;
    }
}

/* No real C body was produced for this 4560-byte window. The nd 7 result came
   from an 8-byte empty stub and is a size-deficit artifact, not a near miss. */
// FUN_0028DC30
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028dc30);

// FUN_0028EE00
s32 func_0028ee00(u8 *arg0)
{
    s32 *work;
    f32 progress;
    u32 startColor;
    u32 endColor;
    u32 start;
    u32 end;
    u8 r;
    u8 g;
    u8 b;

    work = func_00452560();
    work[0]++;
    progress = (f32)work[0] / (f32)work[11];
    if (progress > 1.0f) {
        progress = 1.0f;
    }

    iGpffffba48 = 1;

    start = ((u32)work[7] >> 16) & 0xFF;
    end = ((u32)work[2] >> 16) & 0xFF;
    D_00764B3C = start + progress * (s32)(end - start);

    start = ((u32)work[7] >> 8) & 0xFF;
    end = ((u32)work[2] >> 8) & 0xFF;
    D_00764B40 = start + progress * (s32)(end - start);

    start = (u32)work[7] & 0xFF;
    end = (u32)work[2] & 0xFF;
    D_00764B44 = start + progress * (s32)(end - start);

    startColor = (u32)work[8];
    start = (startColor >> 16) & 0xFF;
    endColor = (u32)work[3];
    end = (endColor >> 16) & 0xFF;
    r = start + progress * (s32)(end - start);

    start = (startColor >> 8) & 0xFF;
    end = (endColor >> 8) & 0xFF;
    g = start + progress * (s32)(end - start);

    start = startColor & 0xFF;
    end = endColor & 0xFF;
    b = start + progress * (s32)(end - start);
    func_00457140(r, g, b, 0);

    *(f32 *)((u8 *)func_00457120() + 0x88) =
        *(f32 *)(work + 9) + progress * (*(f32 *)(work + 4) - *(f32 *)(work + 9));
    func_00457120();
    D_00764B5C =
        *(f32 *)(work + 10) + progress * (*(f32 *)(work + 5) - *(f32 *)(work + 10));

    if (work[0] >= work[11]) {
        if (work[1] & 1) {
            iGpffffba48 = 1;
        } else {
            iGpffffba48 = 0;
        }
        return -1;
    }
    return 0;
}

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
void func_0028f4f0(void) {
    s32 h;

    if (h = func_00452380(&iGpffffa7a8)) {
        func_00452080(h);
    }
}

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

