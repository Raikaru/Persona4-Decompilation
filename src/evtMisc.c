#include "type.h"
#include "sdk_task_registration.h"
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

s32 func_0028ee00(u8 *arg0);
void func_0028f360(u8 *task);
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
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef int (*code)();
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
s32 func_0028d280(u8 *unusedTask) {
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
void func_0028d310(u8 *unusedTask) {
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
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task1));
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
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task2));
        break;
    }
}

/* measured: probe 1095 words, fnalign 265 edits (+10 reloc-only), retail 1140 instrs vs object 1147 (+7, +0.6% inside 3%).
   v1 exact-count 1139/1139 with 272 edits but missing case2 active and wrong case3 extra, so functionally wrong; v4 fixes active.
   Free pragmas singly via probe_variants (base 1095): opt_common_subs off 1150 (+55 worse, 1218 instrs +6.8% outside gate), opt_loop_invariants on 1095 tie, opt_unroll_loops off 1095 tie, schedule off 1095 tie; none kept.
   Subscript via probe_variants: index-for 11-block 1089 (-6 words) but 1151 instrs (+11) and 276 edits (+11) with for-branch vs retail bgtz, rejected; statement-order variant tie.
   Fresh counters already per-block (7n); colouring addr_else/addr_first tie at 1095/265, s3 hoisting persists (retail addiu $a1,sp,filter each use, object addiu $s3 once then move $a1,$s3), time-boxed per 7m. Hoist-removal round 2026-09-18 per 7k (batched probe_variants base + 3): else-&extra[-0xC0], else-extra-192, first-&extra[-0xC0] all tie at 1095 words / 1147 instrs / 265 edits with s3 and 0x7d0 frame unchanged; compiler folds all address forms to one CSE, so 7k subscript scheduling does not apply to this address hoist.
   Residual: frame 0x7d0 vs 0x7c0 (+16 systematic, all stack immediates +16), extra saved s3 (dpa/sq/lq) +7 instrs, register names ($s0 vs $s1 etc), 10 reloc-only. Decompilers: m2c 635 lines, romwright 560 lines; arity 3 (s32, type, u8*) from prologue $4/$5/$6, void return. */
// FUN_0028DC30 NONMATCHING
#ifdef NON_MATCHING
void func_0028dc30(s32 arg0, s32 type, u8 *arg2)
{
    extern u8 *func_004aaee0();
    extern u8 D_0063C660[];
    typedef struct { EvtFilterParams params; u8 extra[0x28]; } F28;
    typedef struct { EvtFilterParams params; u8 extra[0x2C]; } F2C;
    F28 f1;
    F2C f2;
    F2C f3;
    F28 f5;
    u8 s1[0x28];
    u8 s2[0x2C];
    u8 s3[0x2C];
    u8 s5[0x28];
    EvtFilterParams p1;
    EvtFilterParams p2;
    EvtFilterParams p3;
    EvtFilterParams p5;
    s32 argSave;
    s32 mode;
    s32 *task;
    u8 *tmp;

    switch (type) {
    case 1:
        mode = 0;
        if (arg2[0x1B] & 1) {
            mode = 1;
            if (arg2[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *var;
            s32 remaining;
            var = (u8 *)&p1;
            remaining = sizeof(p1);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        p1.type = mode;
        p1.color0 = (arg2[0x1A] << 16) | 0xFF000000 | (arg2[0x19] << 8) | arg2[0x18];
        p1.color1 = (arg2[0x26] << 16) | 0xFF000000 | (arg2[0x25] << 8) | arg2[0x24];
        p1.color2 = (arg2[0x1E] << 16) | 0xFF000000 | (arg2[0x1D] << 8) | arg2[0x1C];
        p1.alpha0 = (f32)arg2[0x1F] / 100.0f;
        p1.color3 = (arg2[0x22] << 16) | 0xFF000000 | (arg2[0x21] << 8) | arg2[0x20];
        p1.alpha1 = (f32)arg2[0x23] / 100.0f;
        p1.value24 = arg2[0x27];
        p1.value28 = arg2[0x1B] >> 4;
        p1.value2C = (f32)arg2[0x28] / 100.0f;
        p1.value30 = (f32)arg2[0x29] / 100.0f;
        p1.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        p1.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        p1.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        p1.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        p1.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        p1.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        p1.valueB8 = *(s16 *)(arg2 + 0x10);
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&p1;
            destination = (EvtU128 *)&f1.params;
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
            var = s1;
            remaining = sizeof(s1);
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
            source = (u32 *)s1;
            destination = (u32 *)f1.extra;
            blocks = 5;
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
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        task[1] = (s32)func_004aaee0(1, (s32)&f1.params);
        task[3] = f1.params.valueB8;
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task));
        break;
    case 2:
        mode = 0;
        if (arg2[0x1B] & 1) {
            mode = 1;
            if (arg2[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *var;
            s32 remaining;
            var = (u8 *)&p2;
            remaining = sizeof(p2);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        p2.type = mode;
        p2.color0 = (arg2[0x1A] << 16) | 0xFF000000 | (arg2[0x19] << 8) | arg2[0x18];
        p2.color1 = (arg2[0x26] << 16) | 0xFF000000 | (arg2[0x25] << 8) | arg2[0x24];
        p2.color2 = (arg2[0x1E] << 16) | 0xFF000000 | (arg2[0x1D] << 8) | arg2[0x1C];
        p2.alpha0 = (f32)arg2[0x1F] / 100.0f;
        p2.color3 = (arg2[0x22] << 16) | 0xFF000000 | (arg2[0x21] << 8) | arg2[0x20];
        p2.alpha1 = (f32)arg2[0x23] / 100.0f;
        p2.value24 = arg2[0x27];
        p2.value28 = arg2[0x1B] >> 4;
        p2.value2C = (f32)arg2[0x28] / 100.0f;
        p2.value30 = (f32)arg2[0x29] / 100.0f;
        p2.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        p2.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        p2.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        p2.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        p2.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        p2.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        p2.valueB8 = *(s16 *)(arg2 + 0x10);
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&p2;
            destination = (EvtU128 *)&f2.params;
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
        f2.params.active = 1;
        {
            u8 *var;
            s32 remaining;
            var = s2;
            remaining = sizeof(s2);
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
            source = (u32 *)s2;
            destination = (u32 *)f2.extra;
            blocks = 11;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        argSave = arg2[0x2A];
        tmp = func_004aaee0(2, (s32)&f2.params);
        *(s32 *)(tmp + 0x28) = func_004ab960(&argSave, 4);
        func_0044ea90(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (tmp != NULL) {
            task[1] = (s32)tmp;
        } else {
            task[1] = (s32)func_004aaee0(2, (s32)&f2.params);
        }
        task[3] = f2.params.valueB8;
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task));
        break;
    case 3:
        mode = 0;
        if (arg2[0x1B] & 1) {
            mode = 1;
            if (arg2[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *var;
            s32 remaining;
            var = (u8 *)&p3;
            remaining = sizeof(p3);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        p3.type = mode;
        p3.color0 = (arg2[0x1A] << 16) | 0xFF000000 | (arg2[0x19] << 8) | arg2[0x18];
        p3.color1 = (arg2[0x26] << 16) | 0xFF000000 | (arg2[0x25] << 8) | arg2[0x24];
        p3.color2 = (arg2[0x1E] << 16) | 0xFF000000 | (arg2[0x1D] << 8) | arg2[0x1C];
        p3.alpha0 = (f32)arg2[0x1F] / 100.0f;
        p3.color3 = (arg2[0x22] << 16) | 0xFF000000 | (arg2[0x21] << 8) | arg2[0x20];
        p3.alpha1 = (f32)arg2[0x23] / 100.0f;
        p3.value24 = arg2[0x27];
        p3.value28 = arg2[0x1B] >> 4;
        p3.value2C = (f32)arg2[0x28] / 100.0f;
        p3.value30 = (f32)arg2[0x29] / 100.0f;
        p3.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        p3.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        p3.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        p3.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        p3.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        p3.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        p3.valueB8 = *(s16 *)(arg2 + 0x10);
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&p3;
            destination = (EvtU128 *)&f3.params;
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
        f3.params.active = 1;
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value;
            s32 blocks;
            source = (EvtU128 *)D_0063C660;
            destination = (EvtU128 *)s3;
            blocks = 2;
            do {
                value = source[0];
                source += 1;
                blocks--;
                destination[0] = value;
                destination += 1;
            } while (blocks > 0);
        }
        *(s64 *)(s3 + 0x20) = *(s64 *)(D_0063C660 + 0x20);
        *(f32 *)(s3 + 0x28) = *(f32 *)(D_0063C660 + 0x28);
        *(s32 *)(s3 + 0x00) = arg2[0x2B];
        *(s32 *)(s3 + 0x04) = *(s16 *)(arg2 + 0x14);
        *(f32 *)(s3 + 0x08) = (f32)arg2[0x13] / 100.0f;
        *(s32 *)(s3 + 0x28) = *(s16 *)(arg2 + 0x16);
        {
            u32 *source;
            u32 *destination;
            u32 value;
            s32 blocks;
            source = (u32 *)s3;
            destination = (u32 *)f3.extra;
            blocks = 11;
            do {
                value = *source;
                source++;
                blocks--;
                *destination = value;
                destination++;
            } while (blocks > 0);
        }
        argSave = arg2[0x2A];
        tmp = func_004aaee0(3, (s32)&f3.params);
        *(s32 *)(tmp + 0x28) = func_004ab960(&argSave, 4);
        func_0044ea90(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (tmp != NULL) {
            task[1] = (s32)tmp;
        } else {
            task[1] = (s32)func_004aaee0(3, (s32)&f3.params);
        }
        task[3] = f3.params.valueB8;
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task));
        break;
    case 5:
        mode = 0;
        if (arg2[0x1B] & 1) {
            mode = 1;
            if (arg2[0x1B] & 2) {
                mode = 2;
            }
        }
        {
            u8 *var;
            s32 remaining;
            var = (u8 *)&p5;
            remaining = sizeof(p5);
            if (var != NULL) {
                do {
                    *var = 0;
                    var++;
                    remaining--;
                } while (remaining != 0);
            }
        }
        p5.type = mode;
        p5.color0 = (arg2[0x1A] << 16) | 0xFF000000 | (arg2[0x19] << 8) | arg2[0x18];
        p5.color1 = (arg2[0x26] << 16) | 0xFF000000 | (arg2[0x25] << 8) | arg2[0x24];
        p5.color2 = (arg2[0x1E] << 16) | 0xFF000000 | (arg2[0x1D] << 8) | arg2[0x1C];
        p5.alpha0 = (f32)arg2[0x1F] / 100.0f;
        p5.color3 = (arg2[0x22] << 16) | 0xFF000000 | (arg2[0x21] << 8) | arg2[0x20];
        p5.alpha1 = (f32)arg2[0x23] / 100.0f;
        p5.value24 = arg2[0x27];
        p5.value28 = arg2[0x1B] >> 4;
        p5.value2C = (f32)arg2[0x28] / 100.0f;
        p5.value30 = (f32)arg2[0x29] / 100.0f;
        p5.value38 = (f32)*(s16 *)(arg2 + 0x30) / 10.0f;
        p5.value3C = (f32)*(s16 *)(arg2 + 0x32) / 10.0f;
        p5.value64 = (f32)*(s16 *)(arg2 + 0x34) / 10.0f;
        p5.value68 = (f32)*(s16 *)(arg2 + 0x36) / 10.0f;
        p5.value90 = (f32)*(s16 *)(arg2 + 0x2C) / 10.0f;
        p5.value94 = (f32)*(s16 *)(arg2 + 0x2E) / 10.0f;
        p5.valueB8 = *(s16 *)(arg2 + 0x10);
        {
            EvtU128 *source;
            EvtU128 *destination;
            EvtU128 value0;
            EvtU128 value1;
            s32 blocks;
            source = (EvtU128 *)&p5;
            destination = (EvtU128 *)&f5.params;
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
            var = s5;
            remaining = sizeof(s5);
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
            source = (u32 *)s5;
            destination = (u32 *)f5.extra;
            blocks = 5;
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
        argSave = 0;
        tmp = func_004aaee0(5, (s32)&f5.params);
        *(s32 *)(tmp + 0x28) = func_004ab960(&argSave, 4);
        func_0044ea90(D_0063C638, 0x11E0);
        task = (s32 *)D_008873F4[0](1, 0x10, 0x40000);
        task[0] = 1;
        if (tmp != NULL) {
            task[1] = (s32)tmp;
        } else {
            task[1] = (s32)func_004aaee0(5, (s32)&f5.params);
        }
        task[3] = f5.params.valueB8;
        (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063C648), 0xF, 0, 0, func_0028d280, func_0028d310, (u8 *)(task));
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028dc30);
#endif

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
void func_0028f360(u8 *unusedTask)
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
    (s32)func_00451fc0((void *)(arg0), (const void *)(&D_00763898), 0xF, 0, 0, func_0028ee00, func_0028f360, (u8 *)(p));
}

// FUN_0028F4F0
void func_0028f4f0(void) {
    s32 h;

    if (h = func_00452380(&iGpffffa7a8)) {
        func_00452080(h);
    }
}

// FUN_0028F530
void func_0028f530(u8 *resource) {
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
    (s32)func_00451fc0((void *)(arg0), (const void *)(&D_0063C690), 0xF, 0, 0, func_0028f540, func_0028f6c0, (u8 *)(temp_2));
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

