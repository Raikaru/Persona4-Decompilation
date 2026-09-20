#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"

typedef struct KwlnTask KwlnTask;
typedef struct PersonaWork PersonaWork;

extern s32 iGpffffa598;
extern u8 *iGpffffb3ac;
extern s32 iGpffffb470;
extern f32 D_008872F8[];
extern f32 fGpffff84a4;
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_00365ac0(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2);
extern u8 D_00628FA0[];
extern f32 D_007615B4;
extern f32 D_007615B8;
extern void (*D_00887314_abs[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
extern void func_00442088(u8 *dst, const char *fmt, s32 arg);
extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00271b70(s32 arg0);
extern void func_00277ad0(s32 arg0, s32 arg1);
extern void func_00201350(void);
extern void func_00211650(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);

extern u32 func_00452560(void *task);
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern f32 fGpffff837c;
extern f32 fGpffff8378;
extern u8 *iGpffffb414;
extern f32 *iGpffffb40c;
extern u8 *func_00105510(s16 arg0);
extern u32 func_00105210(s16 arg0);
extern void func_00105990(s16 arg0, u32 value);
extern u8 func_001059e0(s32 arg0);
extern s32 func_00106020(s32 arg0);
extern s32 func_00106600(s16 id);
extern void func_00106620(s32 arg0, s32 value);
extern void func_00231ef0(u8 *arg0, u8 arg1);
extern s32 func_00212180(s32);
extern void func_00216c40(s32, s32);
extern void func_001f7620(s16 channel, s32 fadeFrames);
extern void func_00454bd0(u8 *arg0);
extern u32 func_00106330(s32 arg0);
extern s32 func_00243ce0(u8 *arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290C0[];
extern u8 D_006290D0[];
extern void func_0044ea90(const void *arg0, s32 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern s32 func_00451fc0(s32 arg0, const void *data, s32 priority, s32 arg3,
                         s32 arg4, void *init, void *close, void *work);
extern s32 func_0036e690(s32 arg0, void *arg1);
extern s32 func_002215c0(s32 arg0);
extern void func_00460ac0(void *arg0, void *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern u8 D_00796340[];
extern s32 func_0046a750(s32 arg0);
extern s32 func_0021d4a0(s32 arg0);
extern u8 *iGpffffb3c4;
extern void *func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_0046aea0(void *arg0);
extern u8 D_00626C30[];
extern u8 D_00626CA0[];
extern void func_00212270(u8 *arg0, u8 *arg1);



extern void func_0046b0d0(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern s32 func_00213a80(void);
extern s32 func_00452380(void *arg0);
extern u8 D_00626C80[];
extern void func_0021b310();
extern s32 func_00221940(KwlnTask *task);
extern void func_0036e870(s32 arg0);
extern void func_00221770(s32 arg0);
extern u8 D_006290E0[];
extern s32 func_00451de0(const void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_0021dc50(s32 arg0, s32 *arg1);
extern void func_0021dd60(void);
extern u16 *func_0010ace0(s16 arg0);
extern u16 func_0010b6f0(void);
extern void func_0010c980(u8 *arg0, s32 arg1);
extern s32 func_0010c6f0(PersonaWork *arg0);
extern void func_0010c5a0(u8 *arg0, u8 *arg1);
extern u16 *func_0010a900(s32 arg0);
extern void func_00201720(void *arg0, f32 arg1, f32 arg2);
extern void func_00201300(s32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void func_002016e0(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
extern void func_002019d0(u8 *arg0, f32 arg1, f32 arg2);
extern s32 func_00243e90(u8 *arg0);
extern s32 func_001b1540(void);
extern void func_002142b0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void func_002161d0(s32 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, s32 arg2);
extern void func_00215c10(s32 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, s32 arg2);
extern f32 fGpffff84a0;
extern void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern s32 func_00231f80(s32 arg0);
extern s32 func_002428f0(u8 *arg0, s32 arg1);
extern f32 fGpffff8498;
extern f32 fGpffff8200;
extern s32 func_0021dba0(s32 task);
extern void func_00210c70(u8 *arg0, u8 *arg1);
extern void func_0020ff00(u8 *arg0, u8 *arg1);
extern void func_0021e110(u8 *arg0, u8 *arg1);
extern void func_0021e9a0(u8 *arg0, u8 *arg1);
extern void func_0021eb60(u8 *arg0);
extern void func_0021ec40(s32 arg0);

static inline f32 ws14_mul(f32 left, f32 right)
{
    return left * right;
}

static inline f32 ws14_add(f32 left, f32 right)
{
    return left + right;
}
static inline f32 ws14_sub(f32 left, f32 right)
{
    return left - right;
}



/* Floor: 367 differing words over 205 edits, 377 emitted against retail's
   400, from a first reconstruction.  Two m2c blanks were recovered from
   the image: the `adda.s`/`msub.s` pair is `2.2f - 1.2f * x`, whose two
   operands are gp-relative pool constants at gp-0x7EF0 and gp-0x7D84
   (1.2f and 2.2f read out of orig/SLUS_217.82), and the 0x432C0000
   immediates are 172.0f.  The out-parameter block that func_0020e690 and
   func_0020ea60 fill is one 0x18-byte struct at sp+0xA0 - m2c splits it
   into spA0/spA4/spA8/spAC/spB0 - with the position pair separate at
   sp+0xB8.
   WALL: 23 instructions short and one saved FPU register light (retail
   spills $f22).  Eighteen of them are the second float-to-u8 conversion
   of `255.0f * rate`: retail converts the same value twice where this
   build folds the two into one, and opt_common_subs off costs more
   elsewhere than it recovers (370 words, 341 edits).  The other four are
   retail keeping `20.0f * (1.0f - rate)` as a separate multiply where
   this build contracts the add into a madd; staging the product,
   opt_treetransformation, opt_movepostops, opt_propagation, lifetimes,
   dead-assignments, size and strength-reduction were all measured. */
/* measured 00210c70: `schedule on` inside the guard is worth 5 words (367 -> 362). */
/* measured 00210c70: `opt_propagation off` on top of `schedule on` is worth 1 word (362 -> 361). */
/* 2026-09-18: func_0020e420 and func_0020e690 now carry the parameter order
   of their live definitions in src/promoted/code1_0020.c (floats second and
   third, and fourth and fifth, respectively); the ints-first spelling here
   was a lie.  Measured neutral at 361 words - the EABI keeps integer and
   float arguments in separate register files - but the order is what b210
   emits argument setup in, so it has to be right before the rest of this
   floor can be read. */
/* 361 -> 359 (2026-09-18): func_00201650's in-body prototype now matches the
   live definition in src/promoted/code1_0020.c (floats fourth and fifth). */
// FUN_00210C70 NONMATCHING
#ifdef NON_MATCHING
void func_00210c70(u8 *arg0, u8 *arg1)
{
    extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
    extern f32 func_0020e5c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00195ea0(u8 *arg0, u8 *arg1);
    extern void func_00201650(s32 *arg0, s32 a, s32 b, f32 x, f32 y, u32 r, u32 g, u32 bl, u32 al);
    extern void func_0020ea60(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void func_0020ef10(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3);
    extern void func_0020f4d0(u8 *arg0, u8 *arg1, f32 x, f32 y);
    extern void func_0020e690(u8 *arg0, u8 *arg1, u8 *arg2, f32 x, f32 y, s32 a, f32 *out);
    extern void func_0020e420(s32 *arg0, f32 x, f32 y, s32 a, s32 b, s32 c);
    extern void func_0021aeb0(s32 a, u8 *b, s32 c, f32 d, f32 e, f32 f);
    u8 info[0x18];
    f32 pos[2];
    s32 *panel;
    s32 *icon;
    u8 *work;
    u8 *unit;
    s32 stage;
    s32 value;
    s32 colour;
    s32 drew;
    s32 first;
    s32 alive;
    f32 rate;
    f32 alpha;
    f32 fade;
    f32 scale;
    f32 height;
    f32 base;
    f32 shift;

    panel = (s32 *)func_00452560(*(void **)(arg0 + 4));
    if (((*(u16 *)(arg1 + 0x14) & 2) && (*(s32 *)(arg1 + 0x10) >= 6)) || (*(s32 *)(arg1 + 0x10) >= 0x19)) {
        *(u16 *)(arg1 + 0x14) = *(u16 *)(arg1 + 0x14) & 0xFFFE;
        alive = 0;
    } else {
        alive = 1;
    }
    if (alive != 0) {
        if (*(u16 *)(arg1 + 0x14) & 8) {
            func_00195ea0(*(u8 **)arg1, arg1 + 4);
        }
        if (func_001ec4a0((f32 *)(arg1 + 4), pos) != 0) {
            work = *(u8 **)arg1 + 0xA3C;
            *(s32 *)(info + 8) = 0;
            func_00201300(panel, pos[0] - 86.0f, pos[1] - 86.0f, 172.0f, 172.0f);
            drew = 0;
            if (*(u16 *)(arg1 + 0x20) & 1) {
                func_0020ea60(arg0, arg1, work, (f32 *)info);
                drew = 1;
            }
            if (*(u16 *)(arg1 + 0x20) & 2) {
                func_0020ef10(arg0, arg1, work, (f32 *)info);
                drew = 1;
            }
            if (*(u16 *)(arg1 + 0x20) & 4) {
                func_0020f4d0(arg0, arg1, pos[0] - 86.0f, pos[1] - 86.0f);
                drew = 1;
            }
            if (*(u16 *)(arg1 + 0x20) & 8) {
                icon = (s32 *)func_00452560(*(void **)(arg0 + 4));
                stage = *(s32 *)(arg1 + 0x10);
                if (!(func_0020e5c0(stage, 0, 4, 0) <= 0.0f)) {
                    scale = 2.2f - 1.2f * func_0020e5c0(stage, 0, 4, 0);
                    func_002019d0((u8 *)icon, scale, scale);
                    func_00201650(icon, 0xA, 0xF, 57.0f, 63.0f, 0x15U, 0x15U, 0x15U, 0xFFU);
                    func_00201650(icon, 0xA, 0x10, 86.0f, 63.0f, 0x15U, 0x15U, 0x15U, 0xFFU);
                    func_002019d0((u8 *)icon, 1.0f, 1.0f);
                }
                rate = func_0020e5c0(stage, 5, 7, 0);
                if (!(rate <= 0.0f)) {
                    alpha = 255.0f * rate;
                    fade = 20.0f * (1.0f - rate);
                    height = 75.0f + fade;
                    func_00201650(icon, 0xA, 0xA, 47.0f, height, 0x15U, 0x15U, 0x15U, (u8)(u32)alpha);
                    alpha = 255.0f * rate;
                    func_00201650(icon, 0xA, 9, 47.0f, height, 0xFFU, 0xFU, 2U, (u8)(u32)alpha);
                }
                drew = 1;
            }
            if (drew != 0) {
                base = 83.0f;
                first = 0;
                shift = 0.0f;
            } else {
                base = 83.0f;
                first = 1;
                if ((*(u16 *)(arg1 + 0x20) & 0x30) == 0x30) {
                    shift = -10.0f;
                } else {
                    shift = 0.0f;
                }
            }
            if (*(u16 *)(arg1 + 0x20) & 0x10) {
                value = *(s32 *)(arg1 + 0x18);
                if (value < 0) {
                    value = -value;
                    colour = -0x100;
                } else {
                    colour = 0xFFD92F00;
                }
                if (first != 0) {
                    func_0020e690(arg0, arg1, work, pos[0] - 86.0f, pos[1] - 86.0f, 0xFF, (f32 *)info);
                    first = 0;
                }
                if (info[4] > 0) {
                    func_0020e420(panel, 86.0f, shift + (83.0f + *(f32 *)info),
                                  value, 1, colour | info[4]);
                }
                if (*(s32 *)(info + 8) != 0) {
                    unit = *(u8 **)arg1;
                    func_0021aeb0(*(s32 *)(arg0 + 4), unit, 0xFF, *(f32 *)(info + 0xC),
                                  *(f32 *)(info + 0x10) + shift, *(f32 *)(unit + 0xA2C));
                }
                base = 83.0f + 27.0f;
            }
            if (*(u16 *)(arg1 + 0x20) & 0x20) {
                value = *(s32 *)(arg1 + 0x1C);
                if (value < 0) {
                    value = -value;
                    colour = 0x67F1FF00;
                } else {
                    colour = 0xB7FF3600;
                }
                if (first != 0) {
                    func_0020e690(arg0, arg1, work, pos[0] - 86.0f, pos[1] - 86.0f, 0xFF, (f32 *)info);
                }
                if (info[4] > 0) {
                    func_0020e420(panel, 86.0f, shift + (base + *(f32 *)info),
                                  value, 1, colour | info[4]);
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00210c70);
#endif
#pragma push
#pragma opt_loop_invariants on
/* Exact: 912/912 bytes, no relocations. Loop extraction retains the
   shared decay constants; separate counters describe independent phases. */
// FUN_002112C0
static void func_002112c0(u8 *state, u8 *output)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        *(u16 *)(output + 8 + i * 2) = 0;
    }
    if (*(u16 *)(state + 0x16) & 1) {
        s32 frame;
        s32 cursor;
        f32 weight;
        u16 phase;

        frame = *(u16 *)(state + 0x14);
        cursor = frame;
        weight = 1.0f;
        while (cursor >= 0) {
            if (cursor < 9) {
                *(u16 *)(output + 8 + cursor * 2) = (u16)(255.0f * weight);
            }
            cursor--;
            weight *= 0.75f;
        }
        if (!(*(u16 *)(state + 0x16) & 2) && frame > 4) {
            phase = frame;
            if (frame >= 8) {
                phase = 0;
            }
            if (phase % 2 == 0 && phase / 2 == 0) {
                *(u16 *)(state + 0x16) |= 2;
            }
        }
        if (frame >= 18) {
            *(u16 *)(state + 0x16) &= 0xFFFE;
            *(u16 *)(state + 0x16) |= 2;
        }
        *(s32 *)(output + 4) = 9;
    } else {
        *(s32 *)(output + 4) = 4;
    }
    if (*(u16 *)(state + 0x16) & 4) {
        s32 frame;
        f32 alpha;

        frame = *(u16 *)(state + 0x14);
        if (frame < 0) {
            alpha = 0.0f;
        } else if (frame < 3) {
            alpha = (f32)frame / 3.0f;
        } else {
            alpha = 1.0f;
        }
        *(f32 *)output = alpha;
        if (frame > 3) {
            *(u16 *)(state + 0x16) &= 0xFFFB;
        }
    } else {
        *(f32 *)output = 1.0f;
    }
    if (*(u16 *)(state + 0x16) & 2) {
        s32 frame;
        s32 trail;
        u16 phase;

        frame = *(u16 *)(state + 0x14);
        phase = frame % 8;
        if (phase % 2 == 0) {
            state[0x18 + phase / 2] = 255;
        }
        for (trail = 0; trail < 4; trail++) {
            u16 sum;
            f32 decay;

            decay = (f32)state[0x18 + trail];
            decay *= 0.75f;
            state[0x18 + trail] = (u8)decay;
            sum = *(u16 *)(output + 8 + trail * 2) + state[0x18 + trail];
            if (sum > 255) {
                sum = 255;
            }
            *(u16 *)(output + 8 + trail * 2) = sum;
        }
    }
    if (++*(u16 *)(state + 0x14) >= 144) {
        *(u16 *)(state + 0x14) = 0;
    }
}
#pragma pop
union ColorWord {
    s32 word;
    f32 value;
    u8 bytes[4];
};

// FUN_00211650
void func_00211650(u8 *arg0, u8 *arg1)
{
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_00201820(s32 arg0);
    extern s32 func_0021be60(void);
    extern void func_0021b630(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                              f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7,
                              f32 fparg8, union ColorWord arg0);
    extern f32 fGpffff84a0;
    union ColorWord frame;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_16;
    s32 var_17;

    D_00887300[0](1, func_0021be60());
    func_00201820(2);
    frame.bytes[0] = 0x52;
    frame.bytes[1] = 0xF3;
    frame.bytes[2] = 0;
    temp_16 = *(s32 *)(arg1 + 4);
    for (var_17 = 0; var_17 < temp_16; var_17++) {
        frame.bytes[3] = (s8)*(u16 *)(arg1 + 8 + (var_17 << 1));
        func_0021b630(21.0f + (f32)(var_17 * 0x14),
                      386.0f, 0.0f, 22.0f, 22.0f,
                      114.0f, 197.0f, 136.0f, 219.0f, frame);
    }
    temp_f22 = *(f32 *)arg1;
    if (!(temp_f22 <= 0.0f)) {
        frame.bytes[0] = 0x52;
        frame.bytes[1] = 0xF3;
        frame.bytes[2] = 0;
        frame.bytes[3] = 0xFF;
        temp_f21 = 21.0f * temp_f22;
        temp_f20 = ws14_mul(temp_f22, -10.5f);
        temp_f20 = ws14_add(fGpffff84a0, temp_f20);
        func_0021b630(14.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      37.0f, 218.0f, 49.0f, 239.0f, frame);
        func_0021b630(26.0f, temp_f20, 0.0f, 112.0f, temp_f21,
                      49.0f, 218.0f, 49.0f, 239.0f, frame);
        func_0021b630(138.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      49.0f, 218.0f, 37.0f, 239.0f, frame);
        func_00201820(0);
        frame.bytes[0] = 0xD;
        frame.bytes[1] = 0x1B;
        frame.bytes[2] = 0;
        frame.bytes[3] = 0xFF;
        func_0021b630(24.0f, fGpffff84a0 + ws14_mul(temp_f22, -9.5f),
                      0.0f, 116.0f, 19.0f * temp_f22, 136.0f,
                      235.0f, 252.0f, 254.0f, frame);
        return;
    }
    func_00201820(0);
}
// FUN_00211950
void func_00211950(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x20);
    *(s32 *)(arg0 + 4) = arg1;
    *(s32 *)(arg0 + 0x10) = 1;
}



// FUN_002119A0
void func_002119a0(u8 **arg0) {
    u8 *p = *arg0;
    u8 *next;

    while (p != NULL) {
        next = *(u8 **)(p + 0x24);
        *(u16 *)(*(u8 **)p + 0xA0) -= 1;
        jtbl_008873EC[0](p);
        p = next;
    }
    *arg0 = NULL;
}

// FUN_00211A10
void func_00211a10(u8 **arg0)
{
    u8 *var_4;
    u8 *var_17;
    u8 *temp_16;
    u8 *temp_3;

    var_4 = *arg0;
    var_17 = var_4;
    goto loop_test;
loop_body:
    *(s32 *)(var_4 + 0x10) = *(s32 *)(var_4 + 0x10) + 1;
    if ((*(u16 *)(var_4 + 0x14) & 1) == 0) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        if (*arg0 == var_4) {
            *arg0 = temp_16;
        } else {
            *(u8 **)(var_17 + 0x24) = temp_16;
        }
        temp_3 = *(u8 **)(var_4 + 0);
        *(u16 *)(temp_3 + 0xA0) = *(u16 *)(temp_3 + 0xA0) - 1;
        jtbl_008873EC[0](var_4);
        var_4 = temp_16;
    } else {
        var_17 = var_4;
        var_4 = *(u8 **)(var_4 + 0x24);
    }
    goto loop_test;
loop_test:
    if (var_4 != NULL) {
        goto loop_body;
    }
}
// FUN_00211AD0
void func_00211ad0(u8 *arg0, u8 *arg1)
{
    s32 *temp_2;
    u16 temp_4;
    u8 *var_18;

    temp_2 = (s32 *)func_00452560(*(void **)(arg1 + 4));
    if ((*temp_2 & 1) != 0) {
        func_00201350();
        var_18 = *(u8 **)arg1;
        goto loop_test;
loop_body:
        func_00210c70(arg1, var_18);
        var_18 = *(u8 **)(var_18 + 0x24);
loop_test:
        if (var_18 != NULL) {
            goto loop_body;
        }
        temp_4 = *(u16 *)(arg1 + 8);
        if ((temp_4 & 8) != 0) {
            if (*(u16 *)(arg1 + 0xE) < 0x3C) {
                func_0020ff00((u8 *)temp_2, arg1);
                return;
            }
            *(u16 *)(arg1 + 8) = temp_4 & 0xFFF7;
        }
    }
}
/* Measured: 1000/1008 bytes, eighteen resolved relocations and eight zero
 * alignment bytes. Projection writes three world and two screen floats;
 * the fade consumer reads the initialized twelve-byte typed packet. */
// FUN_00211BA0
void func_00211ba0(u8 *arg0, u8 *arg1)
{
    extern void func_00195f70(u8 *arg0, f32 *arg1);
    extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
    extern f32 func_0020e5c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_0020fa70(u8 *arg0, u8 *arg1);
    extern f32 fGpffff81e0;
    f32 world[3];
    f32 screen[2];
    struct {
        u8 alpha;
        s16 step;
        u16 flags;
        f32 scale;
    } fade;
    u8 *context;
    s16 frame;
    u16 flags;
    u8 *unit;
    s32 group;
    f32 pulse;
    u8 *draw;

    context = (u8 *)func_00452560(*(void **)(arg1 + 4));
    if (*(u32 *)context & 1) {
        if (*(u16 *)(arg1 + 8) & 1) {
            func_00201350();
            for (group = 0; group < 2; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + 0x178 + group * 8);
                     unit != NULL; unit = *(u8 **)(unit + 0xA6C)) {
                    if (!(*(u32 *)(unit + 0x9C) & 8)) {
                        continue;
                    }
                    if (!datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000)) {
                        continue;
                    }
                    func_00195f70(unit, world);
                    if (!func_001ec4a0(world, screen)) {
                        continue;
                    }
                    func_002012d0(context, screen[0] - 86.0f, screen[1] - 86.0f);
                    draw = (u8 *)func_00452560(*(void **)(arg1 + 4));
                    if (++*(u16 *)(unit + 0xA44) >= 25) {
                        *(u16 *)(unit + 0xA44) = 0;
                    }
                    pulse = func_0044b7b0((fGpffff81e0 * (f32)(s32)*(u16 *)(unit + 0xA44)) / 25.0f);
                    func_00201650(draw, 10, 17, 64.0f, (0.0f + 45.0f) + 10.0f * pulse,
                                   12, 79, 85, 255);
                    func_00201650(draw, 10, 17, 64.0f, (0.0f + 37.0f) + 5.0f * pulse,
                                   63, 255, 245, 255);
                    func_00201650(draw, 10, 8, 55.0f, 44.0f, 63, 255, 245, 255);
                    func_00201650(draw, 10, 7, 55.0f, 44.0f, 12, 79, 85, 255);
                }
            }
        }
        flags = *(u16 *)(arg1 + 8);
        if (flags & 2) {
            if (*(u16 *)(arg1 + 0xA) < 30) {
                frame = *(u16 *)(arg1 + 0xA);
                fade.flags = flags;
                {
                    f32 opacity = func_0020e5c0(frame, 0, 5, 0);
                    fade.alpha = (u8)(255.0f * (1.0f - opacity));
                }
                fade.step = (s16)(s32)(12.0f * func_0020e5c0(frame, 1, 12, 0));
                fade.scale = 1.0f - func_0020e5c0(frame, 20, 30, 0);
                *(u16 *)(arg1 + 0xA) += 1;
                func_0020fa70(context, (u8 *)&fade);
            } else {
                *(u16 *)(arg1 + 8) = flags & 0xFFFD;
            }
        }
    }
}
// FUN_00211F90
void func_00211f90(s32 arg0, u8 *arg1) {
    u8 sp30[0x20];
    u8 *b = (u8 *)func_00452560(*(void **)(arg1 + 4));

    func_00201350();
    if ((*(u16 *)(arg1 + 8) & 0x10) == 0) {
        return;
    }
    if (*(s32 *)(arg1 + 0x10) == 0) {
        return;
    }
    func_002112c0(arg1, sp30);
    func_00211650(b, sp30);
}

// FUN_00212010
void func_00212010(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) | 1;
}
// FUN_00212040
void func_00212040(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFFE;
}
// FUN_00212070
void func_00212070(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;

    p = (u8 *)func_00452560(arg0);
    sub = p + 0x75C;
    *(s16 *)(p + 0x766) = 0;
    if (*(u8 *)(*(u8 **)(arg1 + 0x30) + 0xA2) == 0) {
        *(u16 *)(sub + 8) |= 4;
    } else {
        *(u16 *)(sub + 8) &= 0xFFFB;
    }
    func_0045af60(1, 0xF, 2, 0xD);
    *(u16 *)(sub + 8) |= 2;
}
// FUN_00212100
void func_00212100(s32 arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)func_00452560((void *)arg0) + 0x75C;
    if (func_00212180(arg0) != 0) {
        func_0045af60(1, 0xE, 2, 2);
        *(s16 *)(temp_16 + 0xE) = 0;
        *(u16 *)(temp_16 + 8) |= 8;
    }
}



// FUN_00212180
s32 func_00212180(s32 arg0)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560((void *)arg0) + 0x764) & 8) != 0;
    return flag ^ 1;
}
// FUN_002121B0
void func_002121b0(s32 task)
{
    u8 *work;
    u8 *sub;

    work = (u8 *)func_00452560((void *)task);
    sub = work + 0x75C;
    *(s16 *)(work + 0x770) = 0;
    *(s16 *)(work + 0x772) = 5;
    func_0043f9c8(sub + 0x18, 0, 4);
    *(u16 *)(sub + 8) = *(u16 *)(sub + 8) | 0x10;
}

// FUN_00212210
void func_00212210(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s16 *)(p + 0x772) = 0;
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFEF;
}
// FUN_00212240
void func_00212240(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560(arg0) + 0x76C) = arg1;
}



/* measured 00212270: object 3864B vs retail window 5248B; retail 1311 instrs vs object 966 instrs (-26.3%, gate needs 1272-1350); differing words 1165 reloc-masked (GUARDED_SCORE), fnalign 1052 edits. Prior 2026-09-19 baseline 3244B/811 instrs/-38.1%/1149 words/1066 edits; delta +620B/+155 instrs/-14 edits from second func_00457120 inv recompute plus 11 unsigned (f32)(u32) byte conversions (b0-b3). Frame object 0x3C0 vs retail 0x3A0 (32B over; was 0x390/16B short; extra inv2+b0-b3 locals plus second-call saves, s3 vs s4 arg1 park, f20 vs f23 div.s coloring). JAL retail 22 (1x201350,4x201820,2x34f460,2x34f4a0,4x364fb0,1x366c70,2x3e0870,2x457120,1x46d5f0,3x indirect D_00887310) vs object 22 (second func_00457120 added; call counts match, shortfall is straight-line packet/data code). */
/* shortfall (2026-09-19): largest retail[143:430] 287 vs object[120:122] 3 (remaining five packet headers/data 0x2480-0x2934: lui 0x435D/0x43D1/0x43E0/0x41E8 with sw/swc1 plus unsigned unpack/spills; first header at 0xB0 closed via second 457120+11 unsigned, prior largest 321 vs 5); dozens of 4-18 replaces for (s32)(204/255/4096-scaled smooth)&mask clamps (retail 0x4F00/c.ole/bc1t/cvt.w.s/mfc1/andi/or-0x80000000 vs compact). Excluded: all 7 pairs present, thresholds intact; no switch/call/unsigned/narrow/field bloat levers apply. */
/* gate: func_00212270 is FAR OUTSIDE the +-3% band - object 966 against retail 1311, -26.3%,
   where the band is 1272-1350.  One quarter of the function is still not written (was two fifths at 811).
   It is kept installed only because the missing code is localised and named: retail[143:430] 287 against 3, the remaining five packet headers/data at 0x2480-0x2934 (lui 0x435D/0x43D1/0x43E0/0x41E8 with sw/swc1 plus per-channel unsigned unpack and spills; first header at 0xB0 fixed 2026-09-19 via second 457120+11 unsigned).
   Everything else measured against this body is still outside-gate - the 1165 differing
   words and 1052 fnalign edits are scores against a body still 345 instrs short
   (handoff 7y), and they must not be quoted as progress or compared with any floor
   inside the gate.  The only work that counts here is writing the missing blocks:
   disassemble each retail range named above, describe what it computes, write it,
   measure.  Do not tune expressions in the part that exists. */
// FUN_00212270 NONMATCHING
#ifdef NON_MATCHING
void func_00212270(u8 *arg0, u8 *arg1)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0[3];
        f32 w;
        u32 pad1;
    } QuadA;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0[3];
        f32 w;
        u32 pad1[9];
    } QuadB;
    typedef struct {
        QuadA packet[6];
        u8 pad0[0xC0];
        s32 uv[8];
        u8 params[0x40];
        QuadB bars[4];
        u8 pad1[0x10];
    } Local;
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern f32 D_008872F8[];
    extern u8 D_0060A0E0[];
    extern u8 D_0060A0F0[];
    extern f32 fGpffff8370;
    extern void func_00201350(void);
    extern void func_00201820(s32 arg0);
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2,
                               f32 fparg0, f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                               s32 arg8);
    extern void func_00201720(u8 *arg0, f32 fparg0, f32 fparg1);
    extern s32 func_002340c0(s32 arg0, s32 arg1);
    extern void func_00271b70(s32 arg0);
    extern s32 func_002724d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_00272860(s32 arg0, s32 arg1);
    extern void func_00272950(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00272ba0(s32 arg0, s32 arg1);
    extern void func_00272c60(s32 arg0);
    extern void func_00272c80(s32 arg0);
    extern void func_00273170(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_002738d0(s32 arg0);
    extern void func_00274a20(s32 arg0, f32 fparg0);
    extern void func_00274ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                               s32 arg4, s32 arg5, f32 fparg0, f32 fparg1,
                               s32 arg8);
    extern void func_002778c0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00277ad0(s32 arg0, s32 arg1);
    extern void func_00278090(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278170(s32 arg0, s32 arg1);
    extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
    extern s32 func_002787d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00278ef0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern void func_002791f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                               s32 arg4, s32 arg5, f32 fparg0, f32 fparg1,
                               s32 arg8);
    extern void func_00279690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_00457120();
    extern u8 *func_00452560();
    extern u8 *func_0019f050(u8 *arg0);
    extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern s32 func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4,
                             s64 arg5, f32 fparg0, f32 fparg1);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                              f32 fparg2, s8 arg2, s8 arg3, s8 arg4,
                              s64 arg5, s64 arg6, s32 arg7, f32 fparg3,
                              s16 arg_sp0, s16 arg_sp8);
    extern s32 func_00364fb0(s64 arg0, u32 arg1, s32 arg2, s32 arg3,
                             f32 fparg0, f32 fparg1);
    extern s32 func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             s32 arg4, s32 arg5, s32 arg6, s16 arg7,
                             f32 fparg0, s16 arg_sp0, s32 *arg_sp8,
                             s32 arg_sp10, s32 *arg_sp18);
    extern s32 func_0046d5f0(u8 *arg0, s32 arg1);
    extern u16 D_008C024E;
    Local local;
    u8 *temp;
    s32 mode;
    s32 special;
    s32 alpha;
    s32 i;
    s32 flags;
    s32 value;
    s32 color;
    f32 scale;
    f32 t;
    f32 smooth;
    f32 offset;
    f32 inv;
    f32 inv2;
    u32 b0;
    u32 b1;
    u32 b2;
    u32 b3;

    (void)arg0;
    temp = func_00457120();
    inv = 1.0f / *(f32 *)(temp + 0x80);
    mode = *(s32 *)(arg1 + 0x38);
    if (mode == 0) {
        return;
    }
    if (mode < 0x25) {
        special = 1;
    } else {
        special = 0;
        mode -= 0x24;
    }
    func_00201350();
    func_00201820(2);
    if (special) {
        if (mode < 6) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 5);
            if (t >= 21.0f) {
                t = 1.0f;
            } else {
                t /= 21.0f;
            }
        }
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
    }
    smooth = 2.0f * t - t * t;
    alpha = (s32)(204.0f * smooth) & 0xFF;
    color = 0xFF7B0000 | alpha;
    scale = D_008872F8[0];
    b0 = ((u32)color >> 24) & 0xFF;
    b1 = ((u32)color >> 16) & 0xFF;
    b2 = ((u32)color >> 8) & 0xFF;
    b3 = (u32)color & 0xFF;
    temp = func_00457120();
    inv2 = 1.0f / *(f32 *)(temp + 0x80);
    local.packet[0].x = 640.0f;
    local.packet[0].y = 0.0f;
    local.packet[0].z = scale;
    local.packet[0].w = inv2;
    local.packet[1].x = (f32)b0;
    local.packet[1].y = (f32)b1;
    local.packet[1].z = (f32)b2;
    local.packet[1].w = (f32)b3;
    local.packet[2].x = 320.0f;
    local.packet[2].y = 0.0f;
    local.packet[2].z = scale;
    local.packet[2].w = inv2;
    local.packet[3].x = (f32)b0;
    local.packet[3].y = (f32)b1;
    local.packet[3].z = (f32)b2;
    local.packet[3].w = 0.0f;
    local.packet[4].x = 0.0f;
    local.packet[4].y = 320.0f;
    local.packet[4].z = scale;
    local.packet[4].w = inv2;
    local.packet[5].x = (f32)b0;
    local.packet[5].y = (f32)b1;
    local.packet[5].z = (f32)b2;
    local.packet[5].w = (f32)b3;
    D_00887310[0](3, local.packet, 6);
    if (special) {
        *(s32 *)(arg1 + 0x3C) += 1;
        if (*(s32 *)(arg1 + 0x3C) == 0x15) {
            *(s32 *)(arg1 + 0x3C) = 0;
        }
        offset = 90.0f - (360.0f * (f32)*(s32 *)(arg1 + 0x3C)) / 21.0f;
        alpha = 0xFF;
    } else if (*(s32 *)(arg1 + 0x3C) < 0xC) {
        *(s32 *)(arg1 + 0x3C) += 1;
        t = (f32)*(s32 *)(arg1 + 0x3C) / 12.0f;
        smooth = 2.0f * t - t * t;
        offset = 90.0f + 180.0f * (1.0f - smooth);
        alpha = 0xFF;
    } else {
        offset = 0.0f;
        alpha = 0;
    }
    if (alpha != 0) {
        func_003e0870(local.params, D_0060A0F0, 0, fGpffff8370);
        func_003e0870(local.params, D_0060A0E0, 2, offset);
        local.uv[0] = 0x3F1E0000;
        local.uv[1] = 0x3EE00000;
        local.uv[2] = 0x3F1E0000;
        local.uv[3] = 0x3F6C0000;
        local.uv[4] = 0x3B800000;
        local.uv[5] = 0x3EE00000;
        local.uv[6] = 0x3B800000;
        local.uv[7] = 0x3F6C0000;
        func_00366c70(0x13F, 0xE0, 0x78, 0x98, 0xFFFF761E, alpha,
                      0, 0x3C, 0, 0x4C, (s32 *)local.params,
                      func_0046d5f0((u8 *)*(s32 *)(arg1 + 4), 2),
                      local.uv);
    }
    func_00201820(0);
    if (special) {
        if (mode < 0xB) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xA);
            if (t >= 13.0f) {
                t = 1.0f;
            } else {
                t /= 13.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        offset = 300.0f * smooth;
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
        smooth = 2.0f * t - t * t;
        offset = -600.0f * smooth;
    }
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){563.0f - offset}) << 32) |
                   *(u32 *)&(f32){224.0f - offset},
                   0xFF, 0, 1, 0.0f, 0.0f);
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){76.0f + offset}) << 32) |
                   *(u32 *)&(f32){224.0f + offset},
                   0xFF, 0, 1, 0.0f, 0.0f);
    func_00201820(2);
    if (special) {
        if (mode < 0xD) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xC);
            if (t >= 14.0f) {
                t = 1.0f;
            } else {
                t /= 14.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        offset = 300.0f * (1.0f - smooth);
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 14.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 14.0f;
        }
        smooth = 2.0f * t - t * t;
        offset = -300.0f * (1.0f + smooth);
    }
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){182.0f - offset}) << 32) |
                   *(u32 *)&(f32){331.0f - offset},
                   0xFF6400FF, 0, 0, 0.0f, 0.0f);
    func_00364fb0(((s64)(u32)(*(u32 *)&(f32){457.0f + offset}) << 32) |
                   *(u32 *)&(f32){117.0f + offset},
                   0xFF6400FF, 0, 0, 0.0f, 0.0f);
    if (special) {
        if (mode < 0xB) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xA);
            if (t >= 15.0f) {
                t = 1.0f;
            } else {
                t /= 15.0f;
            }
        }
        smooth = 2.0f * t - t * t;
    } else {
        if (mode <= 0) {
            t = 0.0f;
        } else if ((f32)mode >= 8.0f) {
            t = 1.0f;
        } else {
            t = (f32)mode / 8.0f;
        }
        smooth = 2.0f * (1.0f - t) - (1.0f - t) * (1.0f - t);
    }
    local.bars[0].x = 0.0f;
    local.bars[0].y = 92.0f;
    local.bars[0].z = 0.0f;
    local.bars[0].w = inv;
    local.bars[1].x = 255.0f;
    local.bars[1].y = 100.0f;
    local.bars[1].z = 0.0f;
    local.bars[1].w = 0.0f;
    local.bars[2].x = 640.0f;
    local.bars[2].y = 92.0f;
    local.bars[2].z = 0.0f;
    local.bars[2].w = inv;
    local.bars[3].x = 255.0f;
    local.bars[3].y = 100.0f;
    local.bars[3].z = 0.0f;
    local.bars[3].w = 0.0f;
    color = (s32)(204.0f * smooth) & 0xFF;
    D_00887310[0](4, local.bars, 4);
    local.bars[0].x = 0.0f;
    local.bars[0].y = 224.0f;
    local.bars[0].z = 0.0f;
    local.bars[0].w = inv;
    local.bars[1].x = 255.0f;
    local.bars[1].y = 100.0f;
    local.bars[1].z = 0.0f;
    local.bars[1].w = 0.0f;
    local.bars[2].x = 640.0f;
    local.bars[2].y = 224.0f;
    local.bars[2].z = 0.0f;
    local.bars[2].w = inv;
    local.bars[3].x = 255.0f;
    local.bars[3].y = 100.0f;
    local.bars[3].z = 0.0f;
    local.bars[3].w = 0.0f;
    D_00887310[0](4, local.bars, 4);
    func_00201820(0);
    if (special) {
        if (mode < 0xF) {
            t = 0.0f;
        } else {
            t = (f32)(mode - 0xE);
            if (t >= 8.0f) {
                t = 1.0f;
            } else {
                t /= 8.0f;
            }
        }
        smooth = 2.0f * t - t * t;
        alpha = (s32)(255.0f * (1.0f - smooth)) & 0xFF;
        offset = 400.0f * (1.0f - (1.0f - smooth));
        func_0034f460(*(s32 *)(arg1 + 4), 0, 0, 0, 0, alpha,
                      165.0f + offset, 170.0f);
        func_0034f460(*(s32 *)(arg1 + 4), 1, 0, 0, 0, alpha,
                      313.0f - offset, 224.0f);
        return;
    }
    if (mode <= 0) {
        t = 0.0f;
    } else if ((f32)mode >= 8.0f) {
        t = 1.0f;
    } else {
        t = (f32)mode / 8.0f;
    }
    offset = 4096.0f * (1.0f - t);
    value = (s32)offset & 0xFFFF;
    func_0034f4a0(*(s32 *)(arg1 + 4), 0, 165.0f,
                  42.0f + 28.0f * t, 0.0f, 0, 0, 0,
                  0xFF, 0x1000, value, 0.0f, 0, 0);
    value = (s32)offset & 0xFFFF;
    func_0034f4a0(*(s32 *)(arg1 + 4), 1, 313.0f,
                  224.0f + 26.5f * t, 0.0f, 0, 0, 0,
                  0xFF, 0x1000, value, 0.0f, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212270);
#endif
// FUN_002136F0
s32 func_002136f0(s32 task)
{
    s16 temp_2_2;
    u8 *temp_2;
    s32 temp_2_3;
    s32 temp_3;

    temp_2 = (u8 *)func_00452560((void *)task);
    *(s32 *)(temp_2 + 8) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    func_00460ac0(&D_00796340, temp_2 + 8);
    temp_2_2 = *(s16 *)(temp_2 + 0);
    switch (temp_2_2) {
    case 0:
        goto block_14;
    case 1:
        if (func_0046a750(*(s32 *)(temp_2 + 4)) != 0) {
            *(s16 *)(temp_2 + 0) = 2;
        }
        goto block_14;
    case 2:
        if (*(s32 *)(temp_2 + 0x40) != 0) {
            func_0045af60(1, 0, 5, 0);
            *(s16 *)(temp_2 + 0) = 3;
        case 3:
            temp_2_3 = *(s32 *)(temp_2 + 0x38);
            if (temp_2_3 < 0x24) {
                *(s32 *)(temp_2 + 0x38) = temp_2_3 + 1;
            } else if ((*(s32 *)(temp_2 + 0x44) == 1) &&
                       (*(s32 *)(temp_2 + 0x3C) == 0)) {
                *(s16 *)(temp_2 + 0) = 4;
            }
        }
        goto block_14;
    case 4:
        temp_3 = *(s32 *)(temp_2 + 0x38);
        *(s32 *)(temp_2 + 0x38) = temp_3 + 1;
        if (temp_3 >= 0x34) {
            *(s16 *)(temp_2 + 0) = 5;
        }
        goto block_14;
    case 5:
        return -1;
    default:
block_14:
        return 0;
    }
}
// FUN_00213840
void func_00213840(u8 *arg0) {
    u8 *p;
    s32 v;

    p = (u8 *)func_00452560(arg0);
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0046b0d0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_002138A0
void func_002138a0(s32 arg0)
{
    f32 *temp_2;
    u8 *temp_17;

    temp_17 = (u8 *)func_00452560((void *)arg0);
    func_0044ea90(&D_00626C30, 0x3A);
    temp_2 = (f32 *)jtbl_008873E8[0](0x48, 0x40000);
    func_0043f9c8(temp_2, 0, 0x48);
    *(s32 *)((u8 *)temp_2 + 4) = func_0046aea0(&D_00626CA0);
    *(s16 *)((u8 *)temp_2 + 0) = 1;
    *(void **)((u8 *)temp_2 + 0x10) = (void *)func_00212270;
    *(f32 **)((u8 *)temp_2 + 0x18) = temp_2;
    *(s32 *)(temp_17 + 0x778) =
        func_00451fc0(arg0, &D_00626C80, 0xF, 0, 0,
                      (void *)func_002136f0, (void *)func_00213840,
                      temp_2);
}
// FUN_00213990
void func_00213990(s32 task)
{
    u8 *p;
    s32 value;

    p = (u8 *)func_00452560(*(s32 **)((u8 *)func_00452560((void *)task) + 0x778));
    value = 1;
    *(s32 *)(p + 0x40) = value;
}
// FUN_002139D0
s32 func_002139d0(s32 task)
{
    return *(s32 *)((u8 *)func_00452560(*(s32 **)((u8 *)func_00452560((void *)task) + 0x778)) + 0x38) >= 0x24;
}
// FUN_00213A10
void func_00213a10(s32 task)
{
    u8 *p;
    s32 value;

    p = (u8 *)func_00452560(*(s32 **)((u8 *)func_00452560((void *)task) + 0x778));
    value = 1;
    *(s32 *)(p + 0x44) = value;
}
// FUN_00213A50
s32 func_00213a50(void)
{
    s32 flag;

    flag = func_00213a80() != 0;
    return flag ^ 1;
}
// FUN_00213A80
s32 func_00213a80(void)
{
    return func_00452380(&D_00626C80) != 0;
}
// FUN_00213AB0
void func_00213ab0(s32 arg0, u8 *arg1) {
    func_0043f9c8(arg1, 0, 0x18);
    *(f32 *)(arg1 + 0x10) = 0.5f;
    *(f32 *)(arg1 + 0x14) = 170.0f;
    *(s16 *)(arg1 + 0xC) = 10;
    *(s16 *)(arg1 + 6) = -2;
    *(s16 *)(arg1 + 4) = -2;
}

// FUN_00213B10
void func_00213b10(u8 *arg0)
{
    *(s32 *)(arg0 + 0xA10) |= 1;
    *(s16 *)(arg0 + 0xA18) = 0;
}
// FUN_00213B30
void func_00213b30(u8 *arg0)
{
    *(s32 *)(arg0 + 0xA10) |= 2;
    *(s16 *)(arg0 + 0xA1A) = 0;
}
// FUN_00213B50
void func_00213b50(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~1;
}
// FUN_00213B80
void func_00213b80(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x1;
}

// FUN_00213BB0
void func_00213bb0(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~4;
}
// FUN_00213BE0
void func_00213be0(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x4;
}

// FUN_00213C10
void func_00213c10(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x2;
}

// FUN_00213C40
void func_00213c40(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~2;
}
// FUN_00213C70
void func_00213c70(u8 *view)
{
    u8 *p;

    p = (u8 *)func_00452560(view);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x100;
}

// FUN_00213CA0
void func_00213ca0(u8 *view)
{
    u8 *p;

    p = (u8 *)func_00452560(view);
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~0x100;
}
// FUN_00213CD0
void func_00213cd0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x10);
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 0) |= 0x100;
}



// FUN_00213D20
void func_00213d20(u8 *arg0)
{
    u8 *entry;

    entry = *(u8 **)(iGpffffb3ac + 0x17C);
    while (entry != NULL) {
        if ((*(s32 *)arg0 & 1) != 0) {
            if (*(s16 *)(entry + 0xA16) > -2) {
                *(s16 *)(entry + 0xA16) = *(s16 *)(entry + 0xA16) - 1;
            }
        } else {
            if (*(s16 *)(entry + 0xA16) < 0x19) {
                *(s16 *)(entry + 0xA16) = *(s16 *)(entry + 0xA16) + 1;
            }
        }
        if ((*(s32 *)arg0 & 2) == 0) {
            *(s16 *)(entry + 0xA14) = *(s16 *)(entry + 0xA14) - 2;
            if (*(s16 *)(entry + 0xA14) < 0) {
                *(s16 *)(entry + 0xA14) = 0;
            }
        } else {
            if (*(s16 *)(entry + 0xA14) < 8) {
                *(s16 *)(entry + 0xA14) = *(s16 *)(entry + 0xA14) + 1;
            }
        }
        entry = *(u8 **)(entry + 0xA68);
    }
    if ((*(s32 *)arg0 & 4) != 0) {
        if (*(s16 *)(arg0 + 4) < 10) {
            *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 4) + 1;
        }
    } else {
        if (*(s16 *)(arg0 + 4) > 0) {
            *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 4) - 1;
        }
    }
}
// FUN_00213E20
void func_00213e20(u8 *arg0, u8 *arg1)
{
    extern s32 func_002326c0(s32 arg0);
    s32 value;

    value = func_002326c0(*(s32 *)(arg0 + 0xA64));
    *(s32 *)(arg1 + 0x14) = value;
    if (value == 0) {
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xAF;
        *(u8 *)(arg1 + 2) = 0x20;
        *(u8 *)(arg1 + 4) = 0xFE;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0x22;
        *(u8 *)(arg1 + 8) = 0xFF;
        *(u8 *)(arg1 + 9) = 0xFF;
        *(u8 *)(arg1 + 0xA) = 0xFF;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xAF;
        *(u8 *)(arg1 + 0x12) = 0x20;
        return;
    }
    switch (value) {
    case 2:
        *(u8 *)(arg1 + 0) = 0x8E;
        *(u8 *)(arg1 + 1) = 6;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0x41;
        *(u8 *)(arg1 + 6) = 0x40;
        *(u8 *)(arg1 + 8) = 0x7B;
        *(u8 *)(arg1 + 9) = 0xB;
        *(u8 *)(arg1 + 0xA) = 1;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0x41;
        *(u8 *)(arg1 + 0xE) = 0x40;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0x41;
        *(u8 *)(arg1 + 0x12) = 0x40;
        return;
    case 4:
        *(u8 *)(arg1 + 0) = 0x4E;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xF2;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0x40;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0xE;
        *(u8 *)(arg1 + 9) = 1;
        *(u8 *)(arg1 + 0xA) = 0x7B;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0x40;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0x40;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 8:
        *(u8 *)(arg1 + 0) = 0x42;
        *(u8 *)(arg1 + 1) = 0x6D;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0xA3;
        *(u8 *)(arg1 + 6) = 0;
        *(u8 *)(arg1 + 8) = 5;
        *(u8 *)(arg1 + 9) = 0x49;
        *(u8 *)(arg1 + 0xA) = 7;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0xA3;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0xA3;
        *(u8 *)(arg1 + 0x12) = 0;
        return;
    case 0x10:
        *(u8 *)(arg1 + 0) = 0xAF;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xB8;
        *(u8 *)(arg1 + 4) = 0xCE;
        *(u8 *)(arg1 + 5) = 0x21;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0x5F;
        *(u8 *)(arg1 + 9) = 0;
        *(u8 *)(arg1 + 0xA) = 0x5C;
        *(u8 *)(arg1 + 0xC) = 0xCE;
        *(u8 *)(arg1 + 0xD) = 0x21;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0xCE;
        *(u8 *)(arg1 + 0x11) = 0x21;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 1:
        *(u8 *)(arg1 + 0) = 0x8E;
        *(u8 *)(arg1 + 1) = 6;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0x41;
        *(u8 *)(arg1 + 6) = 0x40;
        *(u8 *)(arg1 + 8) = 0x7B;
        *(u8 *)(arg1 + 9) = 0xB;
        *(u8 *)(arg1 + 0xA) = 1;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0x41;
        *(u8 *)(arg1 + 0xE) = 0x40;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0x41;
        *(u8 *)(arg1 + 0x12) = 0x40;
        return;
    case 0x20:
        *(u8 *)(arg1 + 0) = 0x4E;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xF2;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0x40;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0xE;
        *(u8 *)(arg1 + 9) = 1;
        *(u8 *)(arg1 + 0xA) = 0x7B;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0x40;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0x40;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 0x40:
        *(u8 *)(arg1 + 0) = 0x3B;
        *(u8 *)(arg1 + 1) = 0x38;
        *(u8 *)(arg1 + 2) = 0xFF;
        *(u8 *)(arg1 + 4) = 0x59;
        *(u8 *)(arg1 + 5) = 0x57;
        *(u8 *)(arg1 + 6) = 0xE8;
        *(u8 *)(arg1 + 8) = 0xD;
        *(u8 *)(arg1 + 9) = 0x30;
        *(u8 *)(arg1 + 0xA) = 0x6E;
        *(u8 *)(arg1 + 0xC) = 0x59;
        *(u8 *)(arg1 + 0xD) = 0x57;
        *(u8 *)(arg1 + 0xE) = 0xE8;
        *(u8 *)(arg1 + 0x10) = 0x59;
        *(u8 *)(arg1 + 0x11) = 0x57;
        *(u8 *)(arg1 + 0x12) = 0xE8;
        return;
    case 0x80:
        *(u8 *)(arg1 + 0) = 0x96;
        *(u8 *)(arg1 + 1) = 0x96;
        *(u8 *)(arg1 + 2) = 0x96;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0x2B;
        *(u8 *)(arg1 + 9) = 0x2B;
        *(u8 *)(arg1 + 0xA) = 0x2B;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0xFF;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xFF;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 0x80000:
        *(u8 *)(arg1 + 0) = 0;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0;
        *(u8 *)(arg1 + 5) = 0;
        *(u8 *)(arg1 + 6) = 0;
        *(u8 *)(arg1 + 8) = 0x53;
        *(u8 *)(arg1 + 9) = 0x53;
        *(u8 *)(arg1 + 0xA) = 0x53;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0x89;
        *(u8 *)(arg1 + 0x11) = 0x89;
        *(u8 *)(arg1 + 0x12) = 0x89;
        return;
    default:
        *(s32 *)(arg1 + 0x14) = 0;
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xAF;
        *(u8 *)(arg1 + 2) = 0x20;
        *(u8 *)(arg1 + 4) = 0xFE;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0x22;
        *(u8 *)(arg1 + 8) = 0xFF;
        *(u8 *)(arg1 + 9) = 0xFF;
        *(u8 *)(arg1 + 0xA) = 0xFF;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xAF;
        *(u8 *)(arg1 + 0x12) = 0x20;
        return;
    }
}
/* measured 002142b0: retail 1624 instrs (6496B window), object 1636 instrs (6544B), 809 edits +4 reloc-only via `python3 -E -s tools/fnalign.py src/promoted/code1_0021.c func_002142b0 --candidate docs/probe_archive/Lane0021Full_002142b0_body.c` (was 1155 +4/object 1816). Truthful fixes: 00201650 floats-middle + u8 colors, 00201300 136.0f, 002016b0 s32, 0043f9c8 void*, 85.0*(f32)arg2. CFG hoist regresses 809->911 so kept. Frame -0x180 vs -0x170 + parks/coloring residual. Floor banked in Lane0021Full_002142b0_body.c (428 lines); production stays ASM. */
/* installed 2026-09-19 from docs/probe_archive/Lane0021Full_002142b0_body.c (428 lines, single-function, zero markers): compiles clean with no fixes, fresh 6544B/6496B (1636 vs 1624, +0.7% inside gate), 1468 words. Kept as floor. */
/* measured 002142b0 (owner, 2026-09-19): fnalign **809 -> 807 edits**, count
   1636 -> 1634 against retail 1624, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
// FUN_002142B0 NONMATCHING
#ifdef NON_MATCHING
void func_002142b0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1)
{
    typedef struct {
        s64 stat0[2];
        s64 stat1[2];
        u8 color[0x14];
        s32 status;
        f32 unused[2];
        f32 x[8];
        f32 y[8];
        f32 offset[8];
        f32 effect[8];
    } Work;
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201300(s32 *arg0, f32 fparg0, f32 fparg1,
                              f32 fparg2, f32 fparg3);
    extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                              f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                              f32 fparg1, u8 arg5, u8 arg6, u8 arg7,
                              u8 arg8);
    extern void func_002016b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00201820(s32 arg0);
    extern void func_002019d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00231ee0(s32 arg0);
    extern s32 func_00231f80(s32 arg0);
    extern s32 func_00232290(s32 arg0);
    extern s32 func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             s32 arg4, s32 arg5, s32 arg6, s16 arg7,
                             f32 fparg0, s16 arg_sp0, s32 *arg_sp8,
                             s32 arg_sp10, s32 *arg_sp18);
    extern void *func_0043f9c8(void *dst, s32 value, u32 size);
    extern f32 fGpffff815c;
    extern f32 fGpffff8218;
    extern f32 fGpffff84b4;
    extern f32 fGpffff84b8;
    extern u8 D_00626CC0[];
    extern u8 D_00626DE0[];
    extern u8 D_00626F00[];
    extern u8 D_00626F60[];
    extern u8 D_00626FC0[];
    extern u8 D_00626FD0[];
    Work work;
    u8 *context;
    s32 hp;
    s32 sp;
    s32 state;
    s32 frame;
    s32 i;
    s32 alpha;
    s32 alpha2;
    s32 tile;
    f32 t;
    f32 smooth;
    f32 fade;
    f32 value;
    f32 value2;
    f32 baseX;
    f32 baseY;
    f32 temp;

    context = (u8 *)arg0 + 0x80C;
    func_00213e20(arg1, work.color);
    hp = func_00231ed0(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    sp = func_00231ee0(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    work.stat0[0] = func_00231f80(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    work.stat1[0] = func_00232290(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    tile = *(u16 *)(arg1 + 0xA4);
    if (tile < 9) {
        tile -= 1;
    } else {
        tile = 0;
    }
    frame = *(s16 *)(arg1 + 0xA16);
    if (frame < -1) {
        return;
    }
    if (frame < 0x19) {
        frame = (s16)(frame - (s16)(arg2 * 2));
        state = *(s16 *)(arg1 + 0xA14);
        if (state > 0 && state < 9) {
            t = (f32)state;
            if (t <= 6.0f) {
                t = 1.0f;
            } else {
                t /= 6.0f;
            }
            smooth = 2.0f * t - t * t;
            fparg0 = fparg0 + smooth * (fGpffff84b4 - fparg0);
            t = (f32)arg2;
            fparg1 = fparg1 + smooth * (fGpffff84b8 + 85.0f * t - fparg1);
            fade = fGpffff8218 - fGpffff8218 * smooth;
            func_002019d0((u8 *)arg0, fade, fade);
            value = (f32)frame;
            for (i = 0; i < 3; i++) {
                if (value <= 8.0f) {
                    if (value < 0.0f) {
                        temp = 0.0f;
                    } else {
                        temp = value / 8.0f;
                    }
                } else {
                    temp = 1.0f;
                }
                smooth = 1.0f - (2.0f * temp - temp * temp);
                work.offset[i * 2] = 180.0f * smooth;
                work.offset[i * 2 + 1] = 80.0f * smooth;
                if (*(s32 *)context & 1) {
                    value += 0.75f;
                } else {
                    value -= 0.75f;
                }
            }
            value = (f32)(frame - 3);
            if (value <= 8.0f) {
                if (value < 0.0f) {
                    temp = 0.0f;
                } else {
                    temp = value / 8.0f;
                }
            } else {
                temp = 1.0f;
            }
            smooth = 1.0f - (2.0f * temp - temp * temp);
            baseX = 180.0f * smooth;
            baseY = -(80.0f * smooth);
            value = (f32)frame;
            for (i = 0; i < 3; i++) {
                temp = value - 5.0f;
                if (temp <= 8.0f) {
                    if (temp < 0.0f) {
                        fade = 0.0f;
                    } else {
                        fade = temp / 8.0f;
                    }
                } else {
                    fade = 1.0f;
                }
                smooth = 1.0f - (2.0f * fade - fade * fade);
                work.y[i * 2] = 180.0f * smooth;
                work.y[i * 2 + 1] = -(80.0f * smooth);
                temp = value - 7.0f;
                if (temp <= 8.0f) {
                    if (temp < 0.0f) {
                        fade = 0.0f;
                    } else {
                        fade = temp / 8.0f;
                    }
                } else {
                    fade = 1.0f;
                }
                smooth = 1.0f - (2.0f * fade - fade * fade);
                work.x[i * 2] = 180.0f * smooth;
                work.x[i * 2 + 1] = -(80.0f * smooth);
                value += 1.0f;
            }
        } else {
            state = *(s16 *)(arg1 + 0xA14);
            if (state > 0 && state < 9) {
                if (*(s32 *)(context + 8) != (s32)arg1 &&
                    (*(s32 *)context & 2)) {
                    state -= 2;
                }
                t = (f32)state;
                if (t <= 6.0f) {
                    t = 1.0f;
                } else {
                    t /= 6.0f;
                }
                smooth = 2.0f * t - t * t;
                fparg0 = fparg0 + smooth * (fGpffff84b4 - fparg0);
                t = (f32)arg2;
                fparg1 = fparg1 + smooth * (fGpffff84b8 + 85.0f * t - fparg1);
                fade = fGpffff8218 - fGpffff8218 * smooth;
                func_002019d0((u8 *)arg0, fade, fade);
                func_0043f9c8(work.offset, 0, 0x18);
                func_0043f9c8(work.y, 0, 0x18);
                func_0043f9c8(work.x, 0, 0x18);
                baseX = 0.0f;
                baseY = 0.0f;
            } else {
                func_002012d0((u8 *)arg0, fparg0, fparg1);
                func_0043f9c8(work.offset, 0, 0x18);
                func_0043f9c8(work.y, 0, 0x18);
                func_0043f9c8(work.x, 0, 0x18);
                baseX = 0.0f;
                baseY = 0.0f;
            }
        }
        state = *(s16 *)(context + 4);
        if (state > 0) {
            if (*(s32 *)context & 4) {
                value = (f32)state;
            } else {
                value = (f32)state - 2.5f;
            }
            if (*(s32 *)context & 4) {
                if (value <= 10.0f) {
                    if (value < 0.0f) {
                        t = 0.0f;
                    } else {
                        t = value / 10.0f;
                    }
                } else {
                    t = 1.0f;
                }
                smooth = 2.0f * t - t * t;
            } else {
                if (value <= 10.0f) {
                    if (value < 0.0f) {
                        t = 0.0f;
                    } else {
                        t = value / 10.0f;
                    }
                } else {
                    t = 1.0f;
                }
                smooth = 1.0f - (2.0f * t - t * t);
            }
            fade = 180.0f * smooth;
            baseX += fade;
            for (i = 0; i < 3; i++) {
                if (*(s32 *)context & 4) {
                    if (value <= 10.0f) {
                        if (value < 0.0f) {
                            t = 0.0f;
                        } else {
                            t = value / 10.0f;
                        }
                    } else {
                        t = 1.0f;
                    }
                    smooth = 2.0f * t - t * t;
                    value -= 1.25f;
                } else {
                    if (value <= 10.0f) {
                        if (value < 0.0f) {
                            t = 0.0f;
                        } else {
                            t = value / 10.0f;
                        }
                    } else {
                        t = 1.0f;
                    }
                    smooth = 1.0f - (2.0f * t - t * t);
                    value += 1.25f;
                }
                work.effect[i * 2] += 102.0f * smooth;
            }
        }
        if (*(s32 *)(arg1 + 0xA10) & 1) {
            tile = *(u16 *)(arg1 + 0xA18);
            value = func_0044b610(state) * fGpffff815c;
            value2 = func_0044b7b0(fGpffff815c);
            i = 0;
            do {
                temp = (f32)D_00626FC0[i] *
                       (f32)D_00626CC0[tile * 24 + i * 24];
                work.effect[i * 2] = temp * value;
                work.effect[i * 2 + 1] = -temp * value2;
                work.effect[i * 2 + 1] -=
                    (f32)D_00626FD0[i] *
                    (f32)D_00626CC0[tile * 24 + i * 24];
                i++;
            } while (i < 3);
            alpha = (s32)(64.0f * (f32)D_00626F00[tile]) & 0xFF;
            tile = (s16)tile + 1;
            *(u16 *)(arg1 + 0xA18) = (u16)tile;
            if ((s16)tile >= 0x18) {
                *(s32 *)(arg1 + 0xA10) &= ~1;
            }
        } else {
            func_0043f9c8(work.effect, 0, 0x18);
        }
        func_00201300(arg0, fparg0, fparg1, 136.0f, 136.0f);
        if (*(s32 *)(arg1 + 0xA10) & 0x200) {
            func_00201650((u8 *)arg0, 8, 0xE, 29.0f, 27.0f, 0x9D, 0xFF,
                          0x22, 0xFF);
        }
        if (*(s32 *)(arg1 + 0xA10) & 2) {
            temp = (f32)D_00626F60[(*(s16 *)(arg1 + 0xA1A)) * 4];
            alpha = (s32)(160.0f * temp) & 0xFF;
            alpha2 = (s32)(255.0f * temp) & 0xFF;
            func_00201650((u8 *)arg0, 8, 0xE, 29.0f, 27.0f, 0x9D, 0xFF,
                          0x22, alpha);
            *(s16 *)(arg1 + 0xA1A) += 1;
            if (*(s16 *)(arg1 + 0xA1A) >= 0x18) {
                *(s32 *)(arg1 + 0xA10) &= ~2;
            }
        }
        if (work.status != 0) {
            func_00201650((u8 *)arg0, 0xB, 0,
                          29.0f + work.effect[0] + work.offset[0],
                          27.0f + work.effect[1] + work.offset[1],
                          work.color[0xC], work.color[0xD],
                          work.color[0xE], 0xFF);
        }
        func_00201650((u8 *)arg0, tile, 1,
                      27.0f + work.effect[6] + work.y[6],
                      16.0f + work.effect[7] + work.y[7], work.color[4],
                      work.color[5], work.color[6], 0xFF);
        func_00201650((u8 *)arg0, tile, 1,
                      20.0f + work.effect[4] + work.y[4],
                      20.0f + work.effect[5] + work.y[5], work.color[0],
                      work.color[1], work.color[2], 0xFF);
        func_00201410((u8 *)arg0, tile, 0,
                      20.0f + work.effect[0] + work.offset[0],
                      20.0f + work.effect[1] + work.offset[1]);
        if (work.status != 0) {
            func_00201820(2);
            func_00201650((u8 *)arg0, tile, 0,
                          20.0f + work.effect[0] + work.offset[0],
                          20.0f + work.effect[1] + work.offset[1],
                          work.color[8], work.color[9], work.color[0xA],
                          0xFF);
            func_00201820(0);
        }
        if (*(s32 *)(arg1 + 0xA10) & 3) {
            func_00201820(2);
            func_00201650((u8 *)arg0, tile, 0, 20.0f + work.effect[0],
                          20.0f + work.effect[1], 0xFF, 0xFF, 0xFF,
                          alpha);
            func_00201820(0);
        }
        if (work.status != 0) {
            baseX = work.effect[0] + work.offset[0];
            baseY = work.effect[1] + work.offset[1];
            switch (work.status) {
            case 2:
                func_00201410((u8 *)arg0, 0xB, 0xA, 89.0f + baseX, 25.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xC, 66.0f + baseX, 53.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xB, 48.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 9, 27.0f + baseX, 86.0f + baseY);
                break;
            case 4:
                func_00201410((u8 *)arg0, 0xB, 0xE, 59.0f + baseX, 18.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xF, 46.0f + baseX, 77.0f + baseY);
                break;
            case 8:
                func_00201410((u8 *)arg0, 0xB, 0xD, 73.0f + baseX, 25.0f + baseY);
                break;
            case 0x10:
                func_00201410((u8 *)arg0, 0xB, 5, 36.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 6, 87.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 8, 32.0f + baseX, 88.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 7, 65.0f + baseX, 67.0f + baseY);
                break;
            case 1:
                func_00201410((u8 *)arg0, 0xB, 0x10, 59.0f + baseX, 21.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x12, 109.0f + baseX, 38.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x14, 46.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x11, 23.0f + baseX, 76.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x13, 38.0f + baseX, 99.0f + baseY);
                break;
            case 0x20:
                func_00201410((u8 *)arg0, 0xB, 1, 82.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 2, 47.0f + baseX, 23.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 3, 31.0f + baseX, 91.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 4, 31.0f + baseX, 44.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 4, 65.0f + baseX, 84.0f + baseY);
                break;
            case 0x40:
                func_00201410((u8 *)arg0, 0xB, 0x15, 73.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x16, 60.0f + baseX, 51.0f + baseY);
                break;
            case 0x80:
                func_00201410((u8 *)arg0, 0xB, 0x17, 83.0f + baseX, 30.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x18, 62.0f + baseX, 50.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x19, 78.0f + baseX, 26.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x1A, 32.0f + baseX, 88.0f + baseY);
                break;
            case 0x80000:
                func_00201410((u8 *)arg0, 0xB, 0x1B, 29.0f + baseX, 27.0f + baseY);
                break;
            }
        }
        func_00201650((u8 *)arg0, 8, 0xA, 63.0f + baseX, 82.0f + baseY,
                      work.color[0x10], work.color[0x11],
                      work.color[0x12], 0xFF);
        func_00201650((u8 *)arg0, 8, 0xB, 66.0f + baseX, 85.0f + baseY,
                      0x26, 0x26, 0x26, 0xFF);
        value = (f32)work.stat0[0];
        temp = 54.0f * (f32)hp / value;
        if (temp < 5.0f) {
            value = 0.0f;
        }
        func_002016b0((s32)arg0, 8, 0xC, (s32)value);
        func_00201650((u8 *)arg0, 8, 0xC, 70.0f + baseX, 88.0f + baseY,
                      0xFF, 0xE0, 0x51, 0xFF);
        value2 = (f32)work.stat1[0];
        temp = 54.0f * (f32)sp / value2;
        if (temp < 5.0f) {
            value2 = 0.0f;
        }
        func_002016b0((s32)arg0, 8, 0xC, (s32)value2);
        func_00201650((u8 *)arg0, 8, 0xC, 70.0f + baseX, 94.0f + baseY,
                      0xB7, 0xFF, 0x54, 0xFF);
        func_00201410((u8 *)arg0, 8, sp % 10,
                      121.0f + work.x[0], 64.0f + work.x[1]);
        if (sp / 10 != 0) {
            func_00201410((u8 *)arg0, 8, (sp / 10) % 10,
                          108.0f + work.x[2], 69.0f + work.x[3]);
        }
        if (sp / 100 != 0) {
            func_00201410((u8 *)arg0, 8, (sp / 100) % 10,
                          95.0f + work.x[4], 74.0f + work.x[5]);
        }
        func_00201410((u8 *)arg0, 8, hp % 10,
                      122.0f + work.y[0], 47.0f + work.y[1]);
        if (hp / 10 != 0) {
            func_00201410((u8 *)arg0, 8, (hp / 10) % 10,
                          109.0f + work.y[2], 52.0f + work.y[3]);
        }
        if (hp / 100 != 0) {
            func_00201410((u8 *)arg0, 8, (hp / 100) % 10,
                          96.0f + work.y[4], 57.0f + work.y[5]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002142b0);
#endif
/* measured 00215c10: banked floor obj 1464B/window 1472B via `python tools/measure_guarded.py src/promoted/code1_0021.c func_00215c10` (366/366 instrs, 13 edits +1 reloc-only via `python tools/fnalign.py src/promoted/code1_0021.c func_00215c10 --candidate /tmp/cand_both_reload.c` after s16 reload 21->13; park intsFirst/floatsFirst/pin neutral at 21/13; MAC neutral 79/81; pragmas schedule 431/prop 62/loopInv 21/commonSubs 226 by EDIT count; frame -0x60 correct, residual prologue park order, FPU coloring, 85/conversion coloring. Best legal plain-C; parked as compiler floor. */
/* measured 2026-09-17 full pragma_sweep --pairs: banked 20 via measure_guarded; */
/* best stays 20 (ties: loopinv on, strength off, unroll off and pairs; 172 dead */
/* group, 309-335 schedule group, 342-343 peephole ties, 348 prop group, 350 csoff */
/* group, 358-369 high). No pair wins; prologue move $s1,$a2 + FPU/85 coloring floor. */
/* `python3 -E -s tools/pragma_sweep.py src/promoted/code1_0021.c func_00215c10 --pairs`. */
/* 20 -> 18 (2026-09-18): same lever as the sibling func_002161d0 - the two
   float parameters are used directly instead of through var_f23/var_f22
   copies, which b210 propagates away before leaving the values in $f12/$f13
   where retail keeps them in $f23/$f22.  Remaining 18 words are the
   `move $s1, $a2` parameter save, two slots early, and the 85.0f constant
   that retail materialises before the (f32)(u32) conversion block and b210
   sinks to its use. */
/* 2026-09-18 lead pass, 5 measured variants; floor confirmed at 18 words.
   366/366 instructions.  Three residual slots, all scheduler decisions and
   all insensitive to source order: the `move $s1, $a2` parameter save lands
   two instructions early, retail materialises the 85.0f constant
   (`lui 0x42aa` / `mtc1`) before the two `cvt.s.w` conversions where this
   body materialises it after, and the conversion destination is $f2 in
   retail against $f3 here (a consequence of the second).
   Every reordering ties at 18 with a byte-identical stream: hoisting
   `var_f3 = 85.0f` above the `var_f4` statement, hoisting it to the top of
   the function, swapping it with `var_f2 = (f32)(u32)var_s17`, and both
   permutations of the three parameter-save assignments.  Its sibling
   `func_002161d0` carries the same three slots and the same five ties.
   Section 7m class; not where the next MATCH is. */
// FUN_00215C10 NONMATCHING
#ifdef NON_MATCHING
void func_00215c10(s32 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, s32 arg2)
{
    extern f32 D_007615A4;
    extern f32 D_007615A8;
    extern f32 fGpffff8218;
    extern f32 func_00201950(u8 *arg0, s32 arg1, s32 arg2);
    extern f32 func_00201990(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, u8 arg5, u8 arg6, u8 arg7, u8 arg8);
    s32 *var_s19;
    u8 *var_s18;
    s32 var_s17;
    u8 *var_s16;
    f32 var_f21;
    f32 var_f20;
    f32 var_f12;
    f32 var_f4;
    f32 var_f2;
    f32 var_f3;
    f32 var_f1;
    f32 var_f0;
    s32 var_flag;

    var_s19 = arg0;
    var_s18 = arg1;
    var_s17 = arg2;
    var_s16 = (u8 *)var_s19 + 0x80C;
    var_flag = *(s32 *)(var_s18 + 0xA10);
    if ((var_flag & 0x14) != 0) {
        if ((var_flag & 0x4) != 0) {
            *(s16 *)(var_s18 + 0xA1C) += 1;
            if (*(s16 *)(var_s18 + 0xA1C) >= 0x18) {
                *(s32 *)(var_s18 + 0xA10) &= ~4;
                *(s16 *)(var_s18 + 0xA1C) = 0x18;
            }
        } else if ((var_flag & 0x10) != 0) {
            *(s16 *)(var_s18 + 0xA1C) -= 1;
            if (*(s16 *)(var_s18 + 0xA1C) < 0xB) {
                *(s32 *)(var_s18 + 0xA10) &= ~0x10;
                *(s16 *)(var_s18 + 0xA1C) = 0xA;
            }
        }
        var_f1 = (f32)*(s16 *)(var_s18 + 0xA1C);
        var_f0 = var_f1 / 24.0f;
        var_f21 = var_f0 * var_f0;
    } else {
        var_f21 = 1.0f;
    }
    if (*(s16 *)(var_s18 + 0xA14) < 9) {
        var_f1 = (f32)*(s16 *)(var_s18 + 0xA14);
        if (var_f1 > 6.0f) {
            var_f2 = 1.0f;
        } else if (var_f1 < 0.0f) {
            var_f2 = 0.0f;
        } else {
            var_f2 = var_f1 / 6.0f;
        }
        var_f4 = 2.0f * var_f2 - var_f2 * var_f2;
        fparg0 = fparg0 + var_f4 * (D_007615A4 - fparg0);
        var_f3 = 85.0f;
        var_f2 = (f32)(u32)var_s17;
        var_f0 = D_007615A8 + var_f2 * var_f3;
        var_f0 = var_f0 - fparg1;
        fparg1 = fparg1 + var_f4 * var_f0;
        var_f12 = 1.0f - fGpffff8218 * var_f4;
    } else {
        var_f12 = 1.0f;
    }

    func_002019d0((u8 *)var_s19, var_f12, var_f12);
    if (*(s16 *)(var_s18 + 0xA16) < 0x19) {
        var_f1 = (f32)(s16)(*(s16 *)(var_s18 + 0xA16) - (var_s17 & 0xFFFF) * 2);
        if (var_f1 > 8.0f) {
            var_f3 = 1.0f;
        } else if (var_f1 < 0.0f) {
            var_f3 = 0.0f;
        } else {
            var_f3 = var_f1 / 8.0f;
        }
        var_f0 = 2.0f * var_f3 - var_f3 * var_f3;
        var_f1 = 1.0f - var_f0;
        fparg0 = fparg0 + 180.0f * var_f1;
        fparg1 = fparg1 + 80.0f * var_f1;
    }
    if (*(s16 *)(var_s16 + 4) > 0) {
        if ((*(s32 *)var_s16 & 4) != 0) {
            var_f1 = (f32)*(s16 *)(var_s16 + 4);
            if (var_f1 > 10.0f) {
                var_f2 = 1.0f;
            } else if (var_f1 < 0.0f) {
                var_f2 = 0.0f;
            } else {
                var_f2 = var_f1 / 10.0f;
            }
            var_f2 = 2.0f * var_f2 - var_f2 * var_f2;
        } else {
            var_f1 = (f32)*(s16 *)(var_s16 + 4) - 2.5f;
            if (var_f1 > 10.0f) {
                var_f3 = 1.0f;
            } else if (var_f1 < 0.0f) {
                var_f3 = 0.0f;
            } else {
                var_f3 = var_f1 / 10.0f;
            }
            var_f1 = 1.0f - var_f3;
            var_f0 = 2.0f * var_f1 - var_f1 * var_f1;
            var_f2 = 1.0f - var_f0;
        }
        fparg0 = fparg0 + 180.0f * var_f2;
    }

    var_f20 = 1.0f;
    func_00201300(var_s19, fparg0, fparg1, 136.0f, 136.0f);
    if (var_f20 == var_f21) {
        func_00201650((u8 *)var_s19, 8, 0xE, 29.0f, 27.0f, 0xFE, 0xFF, 0x22, 0xFF);
    } else {
        f32 ret1;
        f32 ret2;
        f32 f2;
        var_f20 = 1.0f - var_f21;
        ret1 = func_00201950((u8 *)var_s19, 8, 0xE);
        f2 = 0.5f * ret1;
        fparg1 = 29.0f + var_f20 * f2;
        ret2 = func_00201990((u8 *)var_s19, 8, 0xE);
        f2 = 0.5f * ret2;
        var_f20 = 27.0f + var_f20 * f2;
        func_00201720(var_s19, var_f21, var_f21);
        func_00201650((u8 *)var_s19, 8, 0xE, fparg1, var_f20, 0xFE, 0xFF, 0x22, 0xFF);
        func_00201720(var_s19, 1.0f, 1.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00215c10);
#endif
/* measured: plain-C reconstruction reaches object 1564B against the 1568B retail window at 21 differing words (reloc-masked, fnalign 14 edits + 3 reloc-only). Frame 0x70, saves s16-s20 + f20-f22, parks s20/s19/f22/f21/s18/s16, forward CFG, FMA adda/madda/madd/msub/div chains and (u8) clamps via cvt.w.s/mfc1/andi with or-0x80000000 path all match; residual is prologue park order, commutative add.s, param-vs-saved FPU coloring (f12 vs f22, f13 vs f21) and 85/conversion f2/f3 coloring. Mined MATCH neighbours for helper prototypes and flag offsets; probe_variants top-down 29->21 via u8 s17 (fixes daddiu 0xFF and andi/move). Endgame levers tried in order, no loop so invariants/guard N/A. Best legal plain-C body; parked as compiler floor. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/code1_0021.c func_002161d0 --pairs` banked 21; best ties 21 (opt_loop_invariants on, opt_strength_reduction off, opt_unroll_loops off and their three pairwise combos); all 28 pairs neutral or worse (next 327, worst opt_common_subs off + peephole off 430). fnalign retail/object 391/391, 14 edits + 3 reloc-only. Floor stands; production stays ASM. */
/* 21 -> 18 (2026-09-18).  Two measured levers:
   1. the two float parameters are used directly instead of being copied into
      var_f22/var_f21 locals.  b210 propagates the copies away and then keeps
      the values in $f12/$f13, where retail has them in the callee-saved
      $f22/$f21; dropping the copies makes b210 save them the same way.
      A two-definition pin on the copies is inert (20).
   2. `*(f32 *)(var_s19 + 0xA24) = var_f1 + 360.0f;` split into an
      accumulate (`var_f1 = var_f1 + 360.0f;` then the store) puts the
      variable in rs of the `add.s`, as retail does; commuting the operands
      in place is inert and `+=` on the memory destination costs 234.
   Remaining 18 words: the `move $s2, $a2` parameter save is two slots early,
   and retail materialises the 85.0f constant before the (f32)(u32)
   conversion block while b210 sinks it to its use.  Measured and rejected on
   that: a two-definition pin on var_f3 (18), hoisting its assignment above
   the var_f4 statement (18), inlining the literal (19), commuting the
   multiply (19). */
// FUN_002161D0 NONMATCHING
#ifdef NON_MATCHING
void func_002161d0(s32 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, s32 arg2)
{
    extern f32 D_007615A4;
    extern f32 D_007615A8;
    extern f32 D_007615AC;
    extern f32 D_007615B0;
    extern f32 fGpffff8218;
    s32 *var_s20;
    u8 *var_s19;
    u32 var_s18;
    u8 *var_s16;
    f32 var_f20;
    u8 var_s17;
    f32 var_f4;
    f32 var_f2;
    f32 var_f3;
    f32 var_f1;
    f32 var_f0;
    f32 var_f12;
    s32 var_flag;

    var_s20 = arg0;
    var_s19 = arg1;
    var_s18 = arg2;
    var_s16 = (u8 *)var_s20 + 0x80C;
    var_f20 = 1.0f;
    var_flag = *(s32 *)(arg1 + 0xA10);
    if ((var_flag & 0xA0) != 0) {
        var_f4 = *(f32 *)(var_s19 + 0xA20);
        var_f2 = -1.0f + -2.0f * var_f4 * var_f4 + 4.0f * var_f4;
        var_f2 = 2.0f * (var_f2 - 0.5f);
        if ((var_flag & 0x20) != 0) {
            var_f3 = 1.0f + 15.0f * var_f2;
            var_f1 = 255.0f * (1.0f - var_f2);
            var_s17 = (u8)var_f1;
            *(f32 *)(var_s19 + 0xA20) = *(f32 *)(var_s19 + 0xA20) - D_007615AC;
        } else {
            var_f3 = 1.0f + 10.0f * (1.0f - var_f2);
            var_f1 = 255.0f * var_f2;
            var_s17 = (u8)var_f1;
            *(f32 *)(var_s19 + 0xA20) = *(f32 *)(var_s19 + 0xA20) - D_007615B0;
        }
        var_f1 = *(f32 *)(var_s19 + 0xA20);
        if (var_f1 <= 0.5f) {
            if ((*(s32 *)(var_s19 + 0xA10) & 0x80) != 0) {
                *(f32 *)(var_s19 + 0xA24) = 170.0f;
            }
            *(s32 *)(var_s19 + 0xA10) &= ~0xA0;
            *(f32 *)(var_s19 + 0xA20) = 0.5f;
        }
    } else {
        var_f3 = 1.0f;
        var_s17 = 0xFF;
    }
    var_f1 = *(f32 *)(var_s19 + 0xA24) - var_f3;
    *(f32 *)(var_s19 + 0xA24) = var_f1;
    if (var_f1 < -180.0f) {
        var_f1 = var_f1 + 360.0f;
        *(f32 *)(var_s19 + 0xA24) = var_f1;
    }
    if (*(s16 *)(var_s19 + 0xA14) < 9) {
        var_f1 = (f32)*(s16 *)(var_s19 + 0xA14);
        if (var_f1 > 6.0f) {
            var_f2 = 1.0f;
        } else if (var_f1 < 0.0f) {
            var_f2 = 0.0f;
        } else {
            var_f2 = var_f1 / 6.0f;
        }
        var_f4 = 2.0f * var_f2 - var_f2 * var_f2;
        fparg0 = fparg0 + var_f4 * (D_007615A4 - fparg0);
        var_f3 = 85.0f;
        var_f2 = (f32)var_s18;
        var_f0 = D_007615A8 + var_f2 * var_f3;
        var_f0 = var_f0 - fparg1;
        fparg1 = fparg1 + var_f4 * var_f0;
        var_f12 = 1.0f - fGpffff8218 * var_f4;
    } else {
        var_f12 = 1.0f;
    }
    func_002019d0((u8 *)var_s20, var_f12, var_f12);
    if (*(s16 *)(var_s19 + 0xA16) < 0x19) {
        var_f1 = (f32)(s16)(*(s16 *)(var_s19 + 0xA16) - (var_s18 & 0xFFFF) * 2);
        if (var_f1 > 8.0f) {
            var_f3 = 1.0f;
        } else if (var_f1 < 0.0f) {
            var_f3 = 0.0f;
        } else {
            var_f3 = var_f1 / 8.0f;
        }
        var_f0 = 2.0f * var_f3 - var_f3 * var_f3;
        var_f1 = 1.0f - var_f0;
        fparg0 = fparg0 + 180.0f * var_f1;
        fparg1 = fparg1 + 80.0f * var_f1;
    }
    if (*(s16 *)(var_s16 + 4) > 0) {
        if ((*(s32 *)var_s16 & 4) != 0) {
            var_f1 = (f32)*(s16 *)(var_s16 + 4);
            if (var_f1 > 10.0f) {
                var_f20 = 1.0f;
            } else if (var_f1 < 0.0f) {
                var_f20 = 0.0f;
            } else {
                var_f20 = var_f1 / 10.0f;
            }
            var_f2 = 2.0f * var_f20 - var_f20 * var_f20;
        } else {
            var_f1 = (f32)*(s16 *)(var_s16 + 4) - 2.5f;
            if (var_f1 > 10.0f) {
                var_f20 = 1.0f;
            } else if (var_f1 < 0.0f) {
                var_f20 = 0.0f;
            } else {
                var_f20 = var_f1 / 10.0f;
            }
            var_f1 = 1.0f - var_f20;
            var_f0 = 2.0f * var_f1 - var_f1 * var_f1;
            var_f2 = 1.0f - var_f0;
        }
        fparg0 = fparg0 + 180.0f * var_f2;
    }
    func_00201300(var_s20, fparg0, fparg1, 136.0f, 136.0f);
    func_002016e0((u8 *)var_s20, 0x42, 0x41, *(f32 *)(var_s19 + 0xA24));
    func_00201650((u8 *)var_s20, 8, 0xD, 13.0f, 12.0f, 0xFE, 0xFF, 0x22, var_s17);
    func_002016e0((u8 *)var_s20, 0, 0, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002161d0);
#endif
/* 844/848 bytes; nine resolved relocations; four zero alignment bytes.
 * Snapshot the four party slots before callbacks can update the actor list. */
// FUN_002167F0
#pragma push
#pragma opt_loop_invariants on
void func_002167f0(u8 *arg0, u8 *arg1)
{
    s32 *work;
    u8 *selected;
    s32 i;
    s32 count;
    u8 *old;
    s32 j;
    u8 *iter;
    s32 selectedIndex;
    u8 local[0x30];
    f32 x;
    f32 y;

    work = (s32 *)func_00452560((void *)(*(u8 **)(arg1 + 0xC)));
    if ((*(s32 *)work & 1) != 0 && (*(s32 *)arg1 & 0x100) != 0) {
        func_00201350();
        selected = (u8 *)func_001b1540();
        if (selected != NULL) selected = *(u8 **)(selected + 0x30);
        else selected = *(u8 **)(arg1 + 8);
        selectedIndex = -1;
        count = 0;
        iter = *(u8 **)(iGpffffb3ac + 0x17C);
        while (iter != NULL) {
            if ((*(s32 *)(iter + 0x9C) & 8) != 0) {
                *(f32 *)(local + count * 8) = (f32)485;
                *(f32 *)(local + 4 + count * 8) = (f32)count * 105.0f + -15.0f;
                *(u8 **)(local + 0x20 + count * 4) = iter;
                if (selected == iter) selectedIndex = count;
                count += 1;
            }
            iter = *(u8 **)(iter + 0xA68);
        }
        if (selectedIndex >= 0) {
            old = *(u8 **)(arg1 + 8);
            if (old != selected) {
                if (old != NULL) {
                    s32 flags = *(s32 *)(old + 0xA10);
                    flags &= ~0xC; *(s32 *)(old + 0xA10) = flags;
                    flags |= 0x10; *(s32 *)(old + 0xA10) = flags;
                    if ((flags & 0x40) != 0) {
                        flags &= ~0x60; *(s32 *)(old + 0xA10) = flags;
                        flags |= 0x80; *(s32 *)(old + 0xA10) = flags;
                        *(f32 *)(old + 0xA20) = 1.0f;
                    }
                }
                old = selected;
                {
                    s32 flags = *(s32 *)(old + 0xA10);
                    flags |= 0xC; *(s32 *)(old + 0xA10) = flags;
                    flags &= ~0x10; *(s32 *)(old + 0xA10) = flags;
                    if ((s16)func_00243e90(*(u8 **)(old + 0xA64)) == 4) {
                        flags = *(s32 *)(old + 0xA10);
                        flags |= 0x60; *(s32 *)(old + 0xA10) = flags;
                        flags &= ~0x80; *(s32 *)(old + 0xA10) = flags;
                        *(f32 *)(old + 0xA20) = 1.0f;
                    }
                }
                *(u8 **)(arg1 + 8) = old;
            }
        } else {
            old = *(u8 **)(arg1 + 8);
            if (old != NULL) {
                s32 flags = *(s32 *)(old + 0xA10);
                flags &= ~0xC; *(s32 *)(old + 0xA10) = flags;
                flags |= 0x10; *(s32 *)(old + 0xA10) = flags;
                if ((flags & 0x40) != 0) {
                    flags &= ~0x60; *(s32 *)(old + 0xA10) = flags;
                    flags |= 0x80; *(s32 *)(old + 0xA10) = flags;
                    *(f32 *)(old + 0xA20) = 1.0f;
                }
                *(u8 **)(arg1 + 8) = NULL;
            }
        }
        i = 0;
        while (i < count) {
            old = *(u8 **)(local + 0x20 + i * 4);
            x = *(f32 *)(local + i * 8);
            y = *(f32 *)(local + 4 + i * 8);
            if ((*(s32 *)(old + 0xA10) & 0x1C) != 0) func_00215c10(work, old, x, y, i & 0xFFFF);
            if ((*(s32 *)(old + 0xA10) & 0xE0) != 0) func_002161d0(work, old, x, y, i & 0xFFFF);
            i += 1;
        }
        j = 0;
        while (j < count) {
            old = *(u8 **)(local + 0x20 + j * 4);
            x = *(f32 *)(local + j * 8);
            y = *(f32 *)(local + 4 + j * 8);
            func_002142b0(work, old, j & 0xFFFF, x, y);
            j += 1;
        }
        func_002019d0((u8 *)work, 1.0f, 1.0f);
    }
}
#pragma pop
// FUN_00216B40
void func_00216b40(s32 arg0, s32 arg1) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560((void *)arg0);
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x12) = 0;
    *(s16 *)(temp_16 + 0x14) = 1;
    *(s32 *)(temp_16 + 0x24) = arg1;
    func_00216c40(arg0, 0x20);
    *(u16 *)(temp_16 + 0x10) &= 0xFFF3;
}



// FUN_00216BB0
void func_00216bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560((void *)arg0);
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x12) = 1;
    *(s16 *)(temp_16 + 0x14) = 1;
    *(s32 *)(temp_16 + 0x20) = arg1;
    *(s32 *)(temp_16 + 0x18) = arg2;
    *(s32 *)(temp_16 + 0x1C) = arg3;
    func_00216c40(arg0, 0x20);
    *(u16 *)(temp_16 + 0x10) &= 0xFFF3;
}



// FUN_00216C40
void func_00216c40(s32 arg0, s32 arg1) {
    u8 *b = (u8 *)func_00452560((void *)arg0);
    u8 *p = b + 0x84C;

    *(s32 *)(b + 0x850) = arg1;
    if (arg1 < 0) {
        *(u16 *)(p + 0x10) |= 1;
    } else {
        *(u16 *)(p + 0x10) &= 0xFFFE;
    }
}

// FUN_00216CA0
void func_00216ca0(s32 task) {
    u8 *b = (u8 *)func_00452560((void *)task) + 0x84C;

    if (*(s32 *)b != 0) {
        func_00271b70(*(s32 *)b);
        *(s32 *)b = 0;
    }
    func_00277ad0(*(s32 *)(b + 0x18), 0);
    *(u16 *)(b + 0x10) &= 0xFFFD;
    *(u16 *)(b + 0x16) = 0;
    *(s32 *)(b + 8) = *(s32 *)(b + 4);
}

// FUN_00216D10
void func_00216d10(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(u16 *)(p + 0x85C) = *(u16 *)(p + 0x85C) | 8;
}
// FUN_00216D40
void func_00216d40(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(u16 *)(p + 0x85C) = *(u16 *)(p + 0x85C) | 4;
}
// FUN_00216D70
void func_00216d70(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560(arg0) + 0x86C) = arg1;
}



// FUN_00216DA0
void func_00216da0(u8 *arg0, s32 arg1) {
    u8 sp20[0x80];

    func_00442088(sp20, (const char *)&iGpffffa598, arg1);
    func_00278450(arg0, 1, sp20);
}

// FUN_00216DF0
void func_00216df0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x40);
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x3C) = arg1;
    *(s16 *)(arg0 + 0x28) = -1;
    *(s32 *)(arg0 + 0x2C) = -1;
}



// FUN_00216E50
void func_00216e50(void)
{
}

/* measured 00216e60: retail 1213 instrs (4864B window), object 1181 instrs (4724B, -2.6%) via `python3 -E -s tools/fnalign.py src/promoted/code1_0021.c func_00216e60 --candidate /tmp/prod_16e60.c` (was 1119, 424 edits +10 reloc-only; now 385 +11). Truthful fixes: D_00887300[0](1,0)+(8,1) before box, 103.0f-(f32)box3 for 83 (retail 103-20 split, cf. func_00215c10 85.0f hoist where ten of twelve diffs trace to one sunk constant), two func_00201720(1,1) after flag8 arms, extra func_002012d0(94,81) inside colour guard, (u8) pulse clamp, (s8)index/n/half compare. Frame 0x140 correct; residual prologue park order, FPU colouring, branch polarity. Inside gate 1177-1249, kept as floor. */
// FUN_00216E60 NONMATCHING
#ifdef NON_MATCHING
void func_00216e60(u8 *arg0, u8 *arg1)
{
    typedef struct {
        u8 cB0[0x10];
        u8 cC0[0x10];
        u8 cD0[0x10];
        u8 cE0[0x10];
        u8 cF0[0x10];
        s32 flag100;
        s32 flag110;
        s32 box0;
        s32 box1;
        s32 box2;
        s32 box3;
        u8 c13c[4];
    } Work;
    extern s32 func_0019f050(u8 *arg0);
    extern void func_002012d0(u8 *arg0, f32 x, f32 y);
    extern void func_00201410(u8 *arg0, s32 font, s32 id, f32 x, f32 y);
    extern void func_00201820(s32 mode);
    extern s32 func_002340c0(s32 arg0, s32 mask);
    extern u8 *func_002724d0(u8 *text, s64 style, s32 mode, s32 arg3, u8 *arg4);
    extern void func_00272860(s32 arg0, s32 arg1);
    extern void func_00272950(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00272ba0(s32 arg0, s32 arg1);
    extern void func_00272c60(s32 arg0);
    extern void func_00272c80(s32 arg0);
    extern void func_00273170(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_002738d0(s32 arg0);
    extern void func_00274a20(s32 arg0, f32 width);
    extern void func_00274ed0(s32 color, s32 font, s32 mode, s32 glyph,
                               s32 arg4, s32 arg5, f32 x, f32 y, f32 scale);
    extern void func_002778c0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278090(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278170(s32 arg0, s32 arg1);
    extern void func_00278ef0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_002791f0(f32 x, f32 y, f32 scale, s32 color, s32 arg4,
                             s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    extern s32 func_00279690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 arg3);
    extern void func_00201350(void);
    extern s32 func_002787d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00201650(u8 *work, s32 mode, s32 tile, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern void func_00201720(void *arg0, f32 arg1, f32 arg2);
    extern u16 D_008C024E;
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern s32 iGpffffb4b0;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;
    extern f32 fGpffff8218;
    extern f32 fGpffffb47c;
    Work work;
    u8 *ctx;
    u8 *subctx;
    s32 *p;
    s32 n;
    s32 half;
    s32 old;
    s32 index;
    s32 color;
    s32 color2;
    s32 color3;
    s32 all;
    s32 pulse;
    s16 key;
    u16 count;
    f32 t;
    f32 fade;
    f32 pulsef;

    (void)arg0;
    ctx = (u8 *)func_00452560(*(void **)(arg1 + 0x3C));
    p = (s32 *)ctx;
    if ((*p & 1) == 0) {
        return;
    }
    func_00201350();
    func_002012d0((u8 *)p, 0.0f, 0.0f);
    index = *(u16 *)(arg1 + 0x14);
    if (index == 1) {
        if (*(s32 *)arg1 != 0) {
            func_00271b70(*(s32 *)arg1);
            *(s32 *)arg1 = 0;
        }
        func_00277ad0(*(s32 *)(arg1 + 0x18), 0);
        *(u16 *)(arg1 + 0x10) &= (u16)~2;
        *(s32 *)(arg1 + 8) = *(s32 *)(arg1 + 4);
        if (*(u16 *)(arg1 + 0x12) == 1) {
            if (*(s32 *)(arg1 + 0x20) != 0) {
                func_00278450((u8 *)(*(s32 *)(arg1 + 0x18)), 0,
                              (u8 *)func_0019f050((u8 *)*(s32 *)(arg1 + 0x20)));
            }
            func_00278ef0(*(s32 *)(arg1 + 0x18), 2, 0, 0xFF, 0xFF);
            func_002778c0(*(s32 *)(arg1 + 0x18), *(s32 *)(arg1 + 0x1C), 0);
            func_00278ef0(*(s32 *)(arg1 + 0x18), 2, 0, 0xFF, 0xFF);
            func_00278170(*(s32 *)(arg1 + 0x18), 0x800000);
            n = func_002787d0(*(s32 *)(arg1 + 0x18), *(s32 *)(arg1 + 0x1C), 0, 2);
            half = n >> 4;
            if (n < 0) {
                half = (n + 0xF) >> 4;
            }
            if (*(u16 *)(arg1 + 0x10) & 4) {
                old = half >> 1;
                if (half < 0) {
                    old = (half + 1) >> 1;
                }
                func_00278090(*(s32 *)(arg1 + 0x18), (0xD0 - old) << 4, 0x2A0);
            } else {
                old = half >> 1;
                if (half < 0) {
                    old = (half + 1) >> 1;
                }
                func_00278090(*(s32 *)(arg1 + 0x18), (0x12F - old) << 4, 0x2B0);
            }
        } else {
            func_00272c60(1);
            func_00272c80(2);
            iGpffffb4b0 = 120;
            *(s32 *)arg1 = (s32)func_002724d0((u8 *)*(s32 *)(arg1 + 0x24), 1, 0, 0, 0);
            iGpffffb4b0 = 0;
            func_00272860(*(s32 *)arg1, -1);
            func_00272c80(1);
            func_00272c60(2);
            n = func_002738d0(*(s32 *)arg1);
            half = n >> 1;
            if (n < 0) {
                half = (n + 1) >> 1;
            }
            if (*(u16 *)(arg1 + 0x10) & 4) {
                func_00272950(*(s32 *)arg1, (0xD1 - half) << 4, 0x2A0);
            } else {
                func_00272950(*(s32 *)arg1, (0x130 - half) << 4, 0x2A0);
            }
            func_00274a20(*(s32 *)arg1, 50.0f);
            func_00272ba0(*(s32 *)arg1, -1);
        }
        *(s32 *)(arg1 + 0xC) = half;
        *(s32 *)(arg1 + 8) = 0;
        *(u16 *)(arg1 + 0x14) = 2;
        *(u16 *)(arg1 + 0x10) |= 2;
        index = 2;
    }
    if (index == 2) {
        if ((*(u16 *)(arg1 + 0x10) & 1) == 0) {
            old = *(s32 *)(arg1 + 8);
            *(s32 *)(arg1 + 8) = old + 1;
            if (old >= *(s32 *)(arg1 + 4)) {
                subctx = (u8 *)func_00452560(*(void **)(arg1 + 0x3C)) + 0x84C;
                if (*(s32 *)subctx != 0) {
                    func_00271b70(*(s32 *)subctx);
                    *(s32 *)subctx = 0;
                }
                func_00277ad0(*(s32 *)(subctx + 0x18), 0);
                *(u16 *)(subctx + 0x10) &= (u16)~2;
                *(u16 *)(subctx + 0x16) = 0;
                *(s32 *)(subctx + 8) = *(s32 *)(subctx + 4);
                *(u16 *)(arg1 + 0x14) = 0;
            }
        } else if (*(u16 *)(arg1 + 0x10) & 2) {
            count = *(u16 *)(arg1 + 0x16);
            if (count < 4) {
                count++;
                *(u16 *)(arg1 + 0x16) = count;
                t = (f32)count / 4.0f;
                fade = 2.0f * t - t * t;
                if (*(u16 *)(arg1 + 0x12) != 1) {
                    D_00887300[0](1, 0);
                    D_00887300[0](8, 1);
                    work.c13c[0] = 0;
                    work.c13c[1] = 0;
                    work.c13c[2] = 0xFF;
                    work.c13c[3] = 0;
                    work.box0 = 104;
                    work.box1 = (s32)(103.0f - (f32)work.box3 - 16.0f * fade);
                    work.box2 = 400;
                    work.box3 = 20;
                    func_0045d6e0(work.c13c, &work.box0, 0, 0.0f);
                    work.box1 = (s32)(99.0f + 16.0f * fade);
                    func_0045d6e0(work.c13c, &work.box0, 0, 0.0f);
                    work.box1 = (s32)(83.0f - 16.0f * fade);
                    work.box3 = (s32)(99.0f + 16.0f * fade - (f32)work.box1);
                    func_0045d6e0(work.c13c, &work.box0, 0, 51.0f);
                    D_00887300[0](8, 0);
                }
                func_00201720((u8 *)p, 1.0f, fade);
                fade = 18.5f * (1.0f - fade);
                work.c13c[3] = 0;
                work.flag110 = 1;
            } else {
                fade = 0.0f;
                work.c13c[3] = 0xFF;
                work.flag110 = 0;
            }
            if (*(u16 *)(arg1 + 0x10) & 8) {
                func_002012d0((u8 *)p, 0.0f, 81.0f);
                func_00201410((u8 *)p, 10, 44, 186.0f, fade);
                func_00201410((u8 *)p, 10, 41, 402.0f, fade);
                func_00201720((u8 *)p, 1.0f, 1.0f);
            } else {
                func_002012d0((u8 *)p, 94.0f, 81.0f);
                func_00201410((u8 *)p, 10, 40, 0.0f, fade);
                func_00201410((u8 *)p, 10, 41, 400.0f, fade);
                func_00201720((u8 *)p, 1.0f, 1.0f);
                if ((*(u16 *)(arg1 + 0x10) & 4) && work.c13c[3] != 0) {
                    s32 bits;
                    func_002012d0((u8 *)p, 94.0f, 81.0f);
                    bits = *(s32 *)(*(s32 *)(arg1 + 0x20) + 0xA64);
                    all = (func_002340c0(bits, 0x400) != 0 ||
                           func_002340c0(bits, 0x800) != 0);
                    if (func_002340c0(bits, 1) != 0 ||
                        func_002340c0(bits, 4) != 0) {
                        index = 0x25; color = 0xFF; color2 = 0x65; color3 = 0x74;
                    } else if (func_002340c0(bits, 2) != 0 ||
                               func_002340c0(bits, 8) != 0) {
                        index = 0x26; color = 0x79; color2 = 0xA1; color3 = 0xFF;
                    } else {
                        index = 0x27; color = 0x66; color2 = 0x66; color3 = 0x66;
                    }
                    if (func_002340c0(bits, 0x40) != 0) {
                        n = 0x25; old = 0xFF; work.cD0[0] = 0x65; work.cC0[0] = 0x74;
                    } else if (func_002340c0(bits, 0x80) != 0) {
                        n = 0x26; old = 0x79; work.cD0[0] = 0xA1; work.cC0[0] = 0xFF;
                    } else {
                        n = 0x27; old = 0x66; work.cD0[0] = 0x66; work.cC0[0] = 0x66;
                    }
                    if (func_002340c0(bits, 0x100) != 0 ||
                        func_002340c0(bits, 0x10) != 0) {
                        half = 0x25; pulse = 0xFF; work.cB0[0] = 0x65; work.cB0[1] = 0x74;
                    } else if (func_002340c0(bits, 0x200) != 0 ||
                               func_002340c0(bits, 0x20) != 0) {
                        half = 0x26; pulse = 0x79; work.cB0[0] = 0xA1; work.cB0[1] = 0xFF;
                    } else {
                        half = 0x27; pulse = 0x66; work.cB0[0] = 0x66; work.cB0[1] = 0x66;
                    }
                    if ((s8)index == 0x27 && (s8)n == 0x27 && (s8)half == 0x27 && !all) {
                        work.c13c[0] = 0x66;
                        work.c13c[1] = 0x66;
                        work.c13c[2] = 0x66;
                    } else {
                        work.c13c[0] = 0xFF;
                        work.c13c[1] = 0xFF;
                        work.c13c[2] = 0xFF;
                    }
                    func_00201650((u8 *)p, 10, 42, 222.0f, 6.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 43, 384.0f, 6.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 34, 233.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 35, 285.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 36, 337.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, n, 313.0f, 10.0f,
                                  old, work.cD0[0], work.cC0[0], work.c13c[3]);
                    func_00201650((u8 *)p, 10, half, 365.0f, 10.0f,
                                  pulse, work.cB0[0], work.cB0[1], work.c13c[3]);
                    if (!all) {
                        func_00201650((u8 *)p, 10, index, 261.0f, 10.0f,
                                      color, color2, color3, work.c13c[3]);
                    } else {
                        func_00201650((u8 *)p, 10, 0x56, 262.0f, -8.0f,
                                      work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x57, 252.0f, 26.0f,
                                      work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x25, 261.0f, 4.0f,
                                      0xFF, 0x65, 0x74, work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x25, 261.0f, 15.0f,
                                      0xFF, 0x65, 0x74, work.c13c[3]);
                        if (index == 0x25) {
                            pulsef = func_0044b7b0(fGpffff8478 * fGpffffb47c);
                            pulse = (u8)(255.0f * (fGpffff847c + fGpffff8218 * pulsef));
                            fGpffffb47c += 12.0f;
                            if (fGpffffb47c >= 180.0f) {
                                fGpffffb47c -= 180.0f;
                            }
                            func_00201820(2);
                            func_00201650((u8 *)p, 10, 0x58, 256.0f, -1.0f,
                                          0xFC, 0x30, 0x30, pulse & 0xFF);
                            func_00201820(0);
                        }
                    }
                }
            }
            if (*(s32 *)arg1 != 0) {
                func_00272c60(0x40);
                if (work.flag110 != 0) {
                    D_00887300[0](6, 1);
                    func_00273170(*(s32 *)arg1, 1, 0);
                    D_00887300[0](6, 0);
                } else {
                    func_00273170(*(s32 *)arg1, 1, 0);
                }
                func_00272c80(0x40);
            }
        }
    }
    if (*(u16 *)(arg1 + 0x10) & 0x10) {
        t = (f32)*(s32 *)(arg1 + 0x34) / 8.0f;
        fade = 1.0f;
        if (t <= 1.0f && t >= 0.0f) {
            fade = 2.0f * t - t * t;
        }
        func_002012d0((u8 *)p, 0.0f, -24.0f);
        func_00201720((u8 *)p, 1.0f, 1.0f);
        func_00201650((u8 *)p, 9, 0x52, 379.0f - 400.0f * (1.0f - fade),
                      303.0f, 0x21, 0x21, 0x21, 0xFF);
        t = (f32)(*(s32 *)(arg1 + 0x34) - 4) / 6.0f;
        fade = 1.0f;
        if (t <= 1.0f) {
            fade = 0.0f;
            if (t >= 0.0f) {
                fade = 2.0f * t - t * t;
            }
        }
        if (fade > 0.0f) {
            func_00201720((u8 *)p, 1.0f, fade);
            func_00201650((u8 *)p, 9, 0x50, 170.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            func_00201650((u8 *)p, 9, 0x51, 473.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            func_00201720((u8 *)p, 1.0f, 1.0f);
        }
        if (fade == 1.0f) {
            func_00201650((u8 *)p, 9, 0x53, 211.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            func_00201650((u8 *)p, 9, 0x54, 328.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            func_00274ed0(0x212121FF, 5, 0, (s32)iGpffffa598, 0, 0,
                          244.0f, 359.0f, 0.0f);
            func_00274ed0(0x212121FF, 5, 0, (s32)iGpffffa598, 0, 0,
                          361.0f, 359.0f, 0.0f);
            if (*(s32 *)(arg1 + 0x38) == 0) {
                func_00279690(*(s32 *)(arg1 + 0x2C), *(s32 *)(arg1 + 0x30), 1, 0xF561);
                *(s32 *)(arg1 + 0x38) = 1;
            }
            func_002791f0(-1.0f, 0.0f, 0.0f, 0, 0,
                          *(s32 *)(arg1 + 0x2C), *(s32 *)(arg1 + 0x30),
                          0x41F80000, 0x43960000);
            key = *(s16 *)(arg1 + 0x2A);
            if (key == 0) {
                if (*(s16 *)(arg1 + 0x28) == -1) {
                    if (D_008C024E & 0x40) {
                        *(s16 *)(arg1 + 0x28) = 0;
                    } else if (D_008C024E & 0x20) {
                        *(s16 *)(arg1 + 0x28) = 1;
                    }
                }
            } else {
                *(s16 *)(arg1 + 0x2A) = key - 1;
            }
        }
    (*(s32 *)(arg1 + 0x34))++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216e60);
#endif
// FUN_00218160
void func_00218160(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;
    s32 value;

    p = (u8 *)func_00452560(arg0);
    sub = p + 0x84C;
    *(s16 *)(p + 0x874) = -1;
    *(s32 *)(p + 0x880) = 0;
    *(s32 *)(p + 0x878) = *(s32 *)(p + 0x98);
    value = ((*(u16 *)(*(u8 **)(arg1 + 0x30) + 0xA4) - 2) * 3) + 5;
    *(s32 *)(sub + 0x30) = value + func_00231d70(3);
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) |= 0x10;
}
// FUN_00218200
s32 func_00218200(s32 task)
{
    return ~(*(s16 *)((u8 *)func_00452560((void *)task) + 0x874)) != 0;
}
// FUN_00218230
s32 func_00218230(s32 task)
{
    return *(s16 *)((u8 *)func_00452560((void *)task) + 0x874);
}
// FUN_00218260
void func_00218260(s32 task) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560((void *)task);
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x28) = -1;
    *(s32 *)(temp_16 + 0x2C) = -1;
    func_001f7620(1, 0);
    *(u16 *)(temp_16 + 0x10) &= 0xFFEF;
}



// FUN_002182C0
void func_002182c0(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;
    s32 value;

    p = (u8 *)func_00452560(arg0);
    sub = p + 0x84C;
    *(s16 *)(p + 0x874) = -1;
    *(s32 *)(p + 0x880) = 0;
    *(s32 *)(p + 0x878) = *(s32 *)(p + 0x98);
    value = ((*(u16 *)(*(u8 **)(arg1 + 0x30) + 0xA4) - 2) * 3) + 0x1A;
    *(s32 *)(sub + 0x30) = value + func_00231d70(3);
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) |= 0x10;
}
// FUN_00218360
s32 func_00218360(s32 task)
{
    return ~(*(s16 *)((u8 *)func_00452560((void *)task) + 0x874)) != 0;
}
// FUN_00218390
s32 func_00218390(s32 task)
{
    return *(s16 *)((u8 *)func_00452560((void *)task) + 0x874);
}
// FUN_002183C0
void func_002183c0(s32 task) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560((void *)task);
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x28) = -1;
    *(s32 *)(temp_16 + 0x2C) = -1;
    func_001f7620(1, 0);
    *(u16 *)(temp_16 + 0x10) &= 0xFFEF;
}

// FUN_00218420
void func_00218420(s32 task, u8 *arg1)
{
    u8 *work;
    u8 *sub;

    work = (u8 *)func_00452560((void *)task);
    sub = work + 0x84C;
    *(s16 *)(work + 0x874) = -1;
    *(s32 *)(work + 0x880) = 0;
    *(s32 *)(sub + 0x2C) = func_002774d0(func_001f3b80(0xCB));
    *(s32 *)(sub + 0x30) = 0;
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) = *(u16 *)(sub + 0x10) | 0x10;
}

// FUN_002184A0
s32 func_002184a0(s32 task)
{
    return ~(*(s16 *)((u8 *)func_00452560((void *)task) + 0x874)) != 0;
}
// FUN_002184D0
s32 func_002184d0(s32 task)
{
    return *(s16 *)((u8 *)func_00452560((void *)task) + 0x874);
}
// FUN_00218500
void func_00218500(s32 task)
{
    u8 *work;
    u8 *sub;
    s32 handle;

    work = (u8 *)func_00452560((void *)task);
    sub = work + 0x84C;
    *(s16 *)(work + 0x874) = -1;
    handle = *(s32 *)(work + 0x878);
    if (handle != -1) {
        func_002777f0(handle);
        *(s32 *)(sub + 0x2C) = -1;
    }
    *(u16 *)(sub + 0x10) = *(u16 *)(sub + 0x10) & 0xFFEF;
}

// FUN_00218560
void func_00218560(u8 *arg0, u8 *arg1)
{
    u8 *sub;

    sub = (u8 *)func_00452560(arg0) + 0x8C0;
    if (func_00106330(0x38) != 0) {
        *(u16 *)sub |= 4;
    } else {
        *(u16 *)sub &= 0xFFFB;
    }
    if (func_00243ce0(*(u8 **)(*(u8 **)(arg1 + 0x30) + 0xA64)) != 0) {
        *(u16 *)sub |= 8;
    } else {
        *(u16 *)sub &= 0xFFF7;
    }
    if (*(u8 *)(*(u8 **)(arg1 + 0x30) + 0xA2) == 1 &&
        (*(u16 *)(iGpffffb3c4 +
                  (*(u16 *)(*(u8 **)(*(u8 **)(arg1 + 0x30) + 0xA64) + 2) * 0x3C)) &
         0x4000) != 0) {
        *(u16 *)sub |= 8;
    }
    func_0045af60(1, 0xE, 2, 0xE);
    *(u16 *)sub &= 0xFFEF;
    *(u8 **)(sub + 8) = arg1;
    *(s16 *)(sub + 2) = 1;
    *(s16 *)(sub + 4) = 0;
}
// FUN_00218690
s32 func_00218690(s32 task)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560((void *)task) + 0x8C0) & 2) != 0;
    return flag ^ 1;
}
// FUN_002186C0
void func_002186c0(u8 *arg0, s32 arg1) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560(arg0);
    *(s32 *)(temp_2 + 0x8C8) = arg1;
    *(s16 *)(temp_2 + 0x8C2) = 2;
}

// FUN_00218700
void func_00218700(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s16 *)(p + 0x8C2) = 4;
}
// FUN_00218730
void func_00218730(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(u16 *)(p + 0x8C0) = *(u16 *)(p + 0x8C0) | 0x10;
}
/* measured 0021a7b0: retail 427 instrs, object 418 instrs (-9, -2.1%, band 414-440) via `python3 -E -s tools/fnalign.py src/promoted/code1_0021.c func_0021a7b0 --candidate /tmp/final_candidate.c` (was 337, -90/-21.1% under-size floor); fndiff 401 words reloc-masked, fnalign 458 edits. Frame -0x210 correct (was -0x1B0): six packet structs stride 0x40 at sp+0x80/0xC0/0x100/0x140/0x180/0x1C0, not 48B; u8[48]->u8[64] fixes 96B (sp60[24] already pads 24->32 to 0x80). `opt_common_subs off` scoped recovers 81 instrs (337->418): retail recomputes (u8)(204.0f*var_f24) per packet (lui 0x4F00/c.le/bc1t/cvt.w.s/mfc1/andi/or-0x80000000) where b210 CSEs the float->int once and reuses $a0 for three packets; big if(var_f24>0) block 172 vs retail 240 with CSE on. `schedule on` retained (7 words 393->386 on old base). Residual is prologue park order, int-vs-FPU packet stores, and FPU save coloring; best legal plain-C floor, production stays ASM. */
/* gate: func_0021a7b0 is OUTSIDE the +-3% band at 460 against retail 428 (+7.5%).  The body previously read
   418/427, 458 edits only because `#pragma schedule on` was filling delay slots that retail leaves
   empty.  Retail's first-party build is entirely unscheduled: across 212 byte-exact MATCH
   first-party functions there are 2909 branches and **zero** filled delay slots, and this
   function's own retail window has 49 branches with 49 empty slots and none filled.  The
   pragma therefore never reproduced retail codegen - it deleted nops to shrink the count, and
   it was hiding a genuine instruction surplus.  It is removed; the surplus is now visible and
   has to be written out of the body.  Any differing-word score measured with the pragma in
   place is not comparable to one measured inside the gate (handoff 7y, 7au). */
// FUN_0021A7B0 NONMATCHING
#ifdef SKIP_ASM
#pragma opt_common_subs off
void func_0021a7b0(u8 *arg1) {
    struct { s32 lo; s32 hi; } sp208pair;
    f32 spB8;
    s32 spA8;
    f32 spA0;
    u8 sp80[64];
    u8 spC0[64];
    u8 sp100[64];
    u8 sp140[64];
    u8 sp180[64];
    u8 sp1C0[64];
    u8 sp60[24];
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f21;
    f32 var_f0;
    f32 var_f1_5;
    f32 var_f24;
    f32 ySum;
    s32 var_16;
    s32 temp_16;
    s32 temp_4;
    s32 *temp_22;
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);

    temp_22 = (s32 *)func_00452560(*(void **)(arg1 + 0x10));
    if ((*temp_22 & 1) == 0) {
        return;
    }
    temp_4 = *(u16 *)(arg1 + 0);
    if (temp_4 & 1) {
        if (!(temp_4 & 2)) {
            *(u16 *)(arg1 + 4) += 1;
            if (*(u16 *)(arg1 + 4) == 0x0E) {
                *(u16 *)(arg1 + 0) |= 2;
            }
        }
        temp_16 = *(u16 *)(arg1 + 4);
        func_00201350();
        func_002012d0((u8 *)temp_22, 0.0f, 0.0f);
        if (*(u16 *)(arg1 + 0) & 4) {
            var_f21 = 298.0f;
        } else {
            var_f21 = 181.0f;
        }
        if ((s32)temp_16 < 5) {
            var_f24 = 0.0f;
        } else if ((s32)temp_16 < 0x0E) {
            var_f24 = (f32)((s32)temp_16 - 5) / 9.0f;
        } else {
            var_f24 = 1.0f;
        }
        ySum = 95.0f + var_f21;
        if (!(var_f24 <= 0.0f)) {
            u8 *var_6 = D_00628FA0;
            u8 *var_5 = sp60;
            s32 var_4 = 6;
            s32 t3;
            s32 t22;
            temp_f20 = D_008872F8[0];
            temp_f0 = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
            do {
                t3 = *(s16 *)var_6;
                t22 = *(s16 *)(var_6 + 2);
                var_6 += 4;
                var_4 -= 1;
                *(s16 *)var_5 = (s16)t3;
                *(s16 *)(var_5 + 2) = (s16)t22;
                var_5 += 4;
            } while (var_4 > 0);
            *(f32 *)(sp80 + 0) = -10.0f;
            *(f32 *)(sp80 + 4) = 95.0f;
            *(f32 *)(sp80 + 8) = temp_f20;
            *(f32 *)(sp80 + 0x18) = temp_f0;
            *(s32 *)(sp80 + 0x20) = 0;
            *(s32 *)(sp80 + 0x24) = 0;
            *(s32 *)(sp80 + 0x28) = 0;
            {
                f32 tf3 = 204.0f * var_f24;
                s32 v42 = (u8)tf3;
                if (v42 >= 0) {
                    *(f32 *)(sp80 + 0x2C) = (f32)v42;
                } else {
                    s32 q42 = ((u32)v42 >> 1) | (v42 & 1);
                    f32 g42 = (f32)q42;
                    g42 += g42;
                    *(f32 *)(sp80 + 0x2C) = g42;
                }
            }
            *(f32 *)(spC0 + 0) = -10.0f + 241.0f;
            *(f32 *)(spC0 + 4) = 95.0f;
            *(f32 *)(spC0 + 8) = temp_f20;
            *(f32 *)(spC0 + 0x18) = temp_f0;
            *(s32 *)(spC0 + 0x20) = 0;
            *(s32 *)(spC0 + 0x24) = 0;
            *(s32 *)(spC0 + 0x28) = 0;
            {
                f32 tf3b = 204.0f * var_f24;
                s32 v43 = (u8)tf3b;
                if (v43 >= 0) {
                    *(f32 *)(spC0 + 0x2C) = (f32)v43;
                } else {
                    s32 q43 = ((u32)v43 >> 1) | (v43 & 1);
                    f32 g43 = (f32)q43;
                    g43 += g43;
                    *(f32 *)(spC0 + 0x2C) = g43;
                }
            }
            {
                *(f32 *)(sp100 + 0) = -10.0f;
                *(f32 *)(sp100 + 4) = ySum;
                *(f32 *)(sp100 + 8) = temp_f20;
                *(f32 *)(sp100 + 0x18) = temp_f0;
                *(s32 *)(sp100 + 0x20) = 0;
                *(s32 *)(sp100 + 0x24) = 0;
                *(s32 *)(sp100 + 0x28) = 0;
                {
                    f32 tf3c = 204.0f * var_f24;
                    s32 v44 = (u8)tf3c;
                    if (v44 >= 0) {
                        *(f32 *)(sp100 + 0x2C) = (f32)v44;
                    } else {
                        s32 q44 = ((u32)v44 >> 1) | (v44 & 1);
                        f32 g44 = (f32)q44;
                        g44 += g44;
                        *(f32 *)(sp100 + 0x2C) = g44;
                    }
                }
            }
            {
                *(f32 *)(sp140 + 0) = -10.0f + 241.0f;
                *(f32 *)(sp140 + 4) = ySum;
                *(f32 *)(sp140 + 8) = temp_f20;
                *(f32 *)(sp140 + 0x18) = temp_f0;
                *(s32 *)(sp140 + 0x20) = 0;
                *(s32 *)(sp140 + 0x24) = 0;
                *(s32 *)(sp140 + 0x28) = 0;
                {
                    f32 tf3d = 204.0f * var_f24;
                    s32 v45 = (u8)tf3d;
                    if (v45 >= 0) {
                        *(f32 *)(sp140 + 0x2C) = (f32)v45;
                    } else {
                        s32 q45 = ((u32)v45 >> 1) | (v45 & 1);
                        f32 g45 = (f32)q45;
                        g45 += g45;
                        *(f32 *)(sp140 + 0x2C) = g45;
                    }
                }
            }
            {
                f32 tf1 = -10.0f + (f32)0x15D;
                *(f32 *)(sp180 + 0) = tf1;
                *(f32 *)(sp180 + 4) = 95.0f;
                *(f32 *)(sp180 + 8) = temp_f20;
                *(f32 *)(sp180 + 0x18) = temp_f0;
                *(s32 *)(sp180 + 0x20) = 0;
                *(s32 *)(sp180 + 0x24) = 0;
                *(s32 *)(sp180 + 0x28) = 0;
                *(s32 *)(sp180 + 0x2C) = 0;
                *(f32 *)(sp1C0 + 0) = tf1;
                *(f32 *)(sp1C0 + 4) = ySum;
                *(f32 *)(sp1C0 + 8) = temp_f20;
                *(f32 *)(sp1C0 + 0x18) = temp_f0;
                *(s32 *)(sp1C0 + 0x20) = 0;
                *(s32 *)(sp1C0 + 0x24) = 0;
                *(s32 *)(sp1C0 + 0x28) = 0;
                *(s32 *)(sp1C0 + 0x2C) = 0;
            }
            D_00887300[0](1, 0);
            D_00887314_abs[0](3, sp80, 6, sp60, 12);
        }
        sp208pair.lo = 0x43FB0000;
        sp208pair.hi = 0x43570000;
        {
            if (temp_16 < 0) {
                var_f0 = 0.0f;
            } else if (temp_16 < 0x0A) {
                var_f0 = func_0044b7b0(fGpffff84a4 * ((f32)temp_16 / 10.0f));
            } else {
                var_f0 = 1.0f;
            }
            if (!(var_f0 <= 0.0f)) {
                func_003657d0(*(Vec2f *)&sp208pair, 0xCC, 0, 0, D_007615B4 * var_f0, D_007615B8 * var_f0);
            }
        }
        {
            if (temp_16 < 0) {
                var_f1_5 = 0.0f;
            } else if (temp_16 < 8) {
                var_f1_5 = 1.0f - func_0044b610(fGpffff84a4 * ((f32)temp_16 / 8.0f));
            } else {
                var_f1_5 = 1.0f;
            }
            if (!(var_f1_5 <= 0.0f)) {
                func_00365ac0(*(s64 *)&sp208pair, 0x89FF1FFF, 1, 0.0f, fGpffff84a4 * var_f1_5, 125.5f * var_f1_5, 16.0f);
            }
        }
    }
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021a7b0);
#endif
// FUN_0021AE60
void func_0021ae60(u8 *arg0, u8 *arg1)
{
    *(f32 *)(arg1 + 0) = -1.0f;
    *(f32 *)(arg1 + 4) = 1.0f;
    *(s16 *)(arg1 + 0x10) = -1;
}
// FUN_0021AE80
void func_0021ae80(s32 arg0)
{
    func_0021b310(arg0 + 0xA3C);
}
// FUN_0021AEB0
void func_0021aeb0(s32 arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2)
{
    f32 temp_f0;
    f32 var_f20;
    u16 *temp_4;
    u16 *temp_4_2;

    var_f20 = fparg2;
    if (arg2 != 0) {
        temp_4 = *(u16 **)(arg1 + 0xA64);
        if ((temp_4 != NULL) &&
            (func_002428f0((u8 *)temp_4, 0) == 0)) {
            temp_4_2 = *(u16 **)(arg1 + 0xA64);
            if ((*temp_4_2 & 0x20) != 0) {
                if ((func_00231ed0((s32)temp_4_2) & 0xFFFF) <= 1) {
                    goto callback;
                }
            }
            if (!(var_f20 <= 0.0f)) {
                temp_f0 = fGpffff8498;
                if (var_f20 < temp_f0) {
                    var_f20 = temp_f0;
                }
            }
        }
callback:
        func_0021b330(arg0, arg1 + 0xA3C, fparg0, fparg1, var_f20);
    }
}
// FUN_0021AFA0
void func_0021afa0(void)
{
    u8 *p;
    u8 *work;
    u32 i;
s16 value0;
s16 value1;

    i = 0;
    goto outer_test;
outer_body:
    p = *(u8 **)(iGpffffb3ac + (i * 8) + 0x178);
    goto loop_test;
loop_body:
    if (*(u8 **)(p + 0xA64) != NULL) {
        work = p + 0xA28;
        if (*(s16 *)(p + 0xA38) >= 0 &&
            *(s16 *)(p + 0xA38) < 0xC) {
            value0 = (s16)func_00231ed0(*(s32 *)(p + 0xA64));
            value1 = (s16)func_00231f80(*(s32 *)(p + 0xA64));
            *(s16 *)(work + 0x10) = -1;
            *(f32 *)work = -1.0f;
            *(f32 *)(work + 4) = (f32)value0 / (f32)value1;
        }
    }
    p = *(u8 **)(p + 0xA6C);
loop_test:
    if (p != NULL) {
        goto loop_body;
    }
    i++;
outer_test:
    if (i < 2U) {
        goto outer_body;
    }
}
/* MATCHED: unsigned-return conversion idiom and block-scope DatUnit pointer
   declaration reproduce retail exactly; object 240B / window 240B / nd 0.
   A u16 return declaration matches func_00231f80's definition but regresses
   this call site to object 244B / nd 137, so the call-site s32 return view is
   intentional. */
// FUN_0021B0A0
f32 func_0021b0a0(u8 *arg0)
{
    typedef struct DatUnit DatUnit;
    extern s32 func_00231ed0(DatUnit *arg0);
    extern s32 func_00231f80(DatUnit *arg0);
    f32 var_f20;
    f32 var_f0;
    u32 temp_2;
    u32 temp_2_2;

    if (*(s32 *)(arg0 + 0xA64) == 0) {
        return 0.0f;
    }
    temp_2 = (u32)func_00231f80((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f20 = (f32)temp_2;
    if (var_f20 == 0.0f) {
        return 0.0f;
    }
    temp_2_2 = (u32)func_00231ed0((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f0 = (f32)temp_2_2;
    return var_f0 / var_f20;
}
// FUN_0021B190
void func_0021b190(u8 *arg0, s32 arg1)
{
    func_0043f9c8(arg0, 0, 4);
    *(s32 *)arg0 = arg1;
}
// FUN_0021B1E0
void func_0021b1e0(void)
{
}
// FUN_0021B1F0
// measured: loop-invariant constant hoisting probe for func_0021b1f0.
#pragma opt_loop_invariants on
void func_0021b1f0(s32 arg0, s32 *arg1)
{
    f32 temp_f0;
    f32 temp_f3;
    s16 temp_3;
    u8 *var_7;
    u32 var_6;
    u8 *temp_5;

    if ((*(s32 *)func_00452560((void *)*arg1) & 1) != 0) {
        var_6 = 0;
        while (var_6 < 2U) {
            var_7 = *(u8 **)(iGpffffb3ac + var_6 * 8 + 0x178);
            while (var_7 != NULL) {
                if (*(s32 *)(var_7 + 0xA64) != 0) {
                    temp_5 = var_7 + 0xA28;
                    temp_f0 = *(f32 *)(var_7 + 0xA28);
                    if (!(temp_f0 < 0.0f)) {
                        *(f32 *)(temp_5 + 0xC) = temp_f0;
                        *(f32 *)(temp_5 + 8) = *(f32 *)(temp_5 + 4);
                        *(s32 *)temp_5 = (s32)0xBF800000;
                        *(s16 *)(temp_5 + 0x10) = 0;
                    }
                    temp_3 = *(s16 *)(temp_5 + 0x10);
                    if (temp_3 >= 0 && temp_3 < 0xD) {
                        if (temp_3 < 0xC) {
                            temp_f3 = *(f32 *)(temp_5 + 8);
                            temp_f0 = (f32)temp_3 / 12.0f;
                            *(f32 *)(temp_5 + 4) =
                                temp_f0 * (*(f32 *)(temp_5 + 0xC) -
                                           temp_f3) +
                                (0.0f + temp_f3);
                        } else {
                            *(f32 *)(temp_5 + 4) = *(f32 *)(temp_5 + 0xC);
                        }
                        *(s16 *)(temp_5 + 0x10) =
                            *(s16 *)(temp_5 + 0x10) + 1;
                    }
                }
                var_7 = *(u8 **)(var_7 + 0xA6C);
            }
            var_6 += 1;
        }
    }
}
// measured: restore loop-invariant baseline after func_0021b1f0.
#pragma opt_loop_invariants off
// FUN_0021B310
void func_0021b310(u8 *arg0, s32 arg1)
{
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0) = 0;
    }
    *(s32 *)(arg0 + 4) = arg1;
}
/* archived body: build/D21B_0021b330_body.c; object 452B; retail window 464B;
   normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C.
   Best legal plain-C body; residual is saved FPU parameter coloring and 12B
   tail padding. */
/* object 452B; retail window 464B; normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C; best legal plain-C body; residual is saved FPU parameter-coloring and 12B tail padding. */
// FUN_0021B330
void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    extern f32 fGpffff849c;
    u8 *context;
    s32 value;
    f32 amount;

    context = (u8 *)func_00452560((void *)arg0);
    if (*(s32 *)(arg1 + 4) != 0) {
        value = *(s32 *)arg1;
        *(s32 *)arg1 = value + 1;
        amount = (f32)(value + 1) / 4.0f;
        if (amount > 1.0f) {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (amount != 0.0f) {
        fparg1 = (1.0f - amount) * 5.5f + fparg1 + 0.0f;
        func_00201720(context, 1.0f, amount);
        func_00201650(context, 10, 0, fparg0, fparg1, 0x19, 0x19, 0x19, 0xFF);
        if (!(fparg2 <= fGpffff849c)) {
            func_00201720(context, fparg2, amount);
            func_00201650(context, 10, 1,
                          (1.0f - fparg2) * 5.0f + fparg0 + 0.0f,
                          fparg1, 0xFF, 0xFF, 0x51, 0xFF);
        }
        func_00201720(context, 1.0f, 1.0f);
    }
}
// FUN_0021B500
void func_0021b500(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5)
{
    union {
        s32 word;
        u8 bytes[4];
    } spC;

    spC.word = arg1;
    *(f32 *)(arg0 + 0) = fparg0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg2;
    *(f32 *)(arg0 + 0x20) = (f32)(u32)spC.bytes[0];
    *(f32 *)(arg0 + 0x24) = (f32)(u32)spC.bytes[1];
    *(f32 *)(arg0 + 0x28) = (f32)(u32)spC.bytes[2];
    *(f32 *)(arg0 + 0x2C) = (f32)(u32)spC.bytes[3];
    *(f32 *)(arg0 + 0x10) = fparg3;
    *(f32 *)(arg0 + 0x14) = fparg4;
    *(f32 *)(arg0 + 0x18) = fparg5;
}
typedef struct {
    f32 x, y, z;
    f32 padding0;
    f32 u, v;
    f32 scale;
    f32 padding1;
    f32 color[4];
    u32 padding2[4];
} PanelQuad;

/* One four-vertex strip. The union preserves the packed RGBA bits through
 * the retail float-local spill; channel values are stored as floats.
 * Nine float formals precede the color union to preserve caller scheduling. */
// FUN_0021B630
void func_0021b630(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7,
                   f32 fparg8, union ColorWord arg0)
{
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern s32 func_00457120(void);
    f32 color;
    PanelQuad quads[4];
    union {
        s32 word;
        f32 value;
        u8 bytes[4];
    } spC, sp8, sp4, sp0;
    u8 *p;
    f32 zval;
    f32 scale;

    zval = D_008872F8[0] - fparg2;
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    fparg5 = fparg5 / 256.0f;
    fparg6 = fparg6 / 256.0f;
    fparg7 = fparg7 / 256.0f;
    fparg8 = fparg8 / 256.0f;
    color = arg0.value;
    spC.value = color;
    p = (u8 *)&quads[0];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)spC.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)spC.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)spC.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)spC.bytes[3];
    *(f32 *)(p + 0x10) = fparg5;
    *(f32 *)(p + 0x14) = fparg6;
    *(f32 *)(p + 0x18) = scale;
    sp8.value = color;
    p = (u8 *)&quads[1];
    *(f32 *)(p + 0) = fparg0 + fparg3;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp8.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp8.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp8.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp8.bytes[3];
    *(f32 *)(p + 0x10) = fparg7;
    *(f32 *)(p + 0x14) = fparg6;
    *(f32 *)(p + 0x18) = scale;
    sp4.value = color;
    p = (u8 *)&quads[2];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1 + fparg4;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp4.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp4.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp4.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp4.bytes[3];
    *(f32 *)(p + 0x10) = fparg5;
    *(f32 *)(p + 0x14) = fparg8;
    *(f32 *)(p + 0x18) = scale;
    sp0.value = color;
    p = (u8 *)&quads[3];
    *(f32 *)(p + 0) = fparg0 + fparg3;
    *(f32 *)(p + 4) = fparg1 + fparg4;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp0.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp0.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp0.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp0.bytes[3];
    *(f32 *)(p + 0x10) = fparg7;
    *(f32 *)(p + 0x14) = fparg8;
    *(f32 *)(p + 0x18) = scale;
    D_00887310[0](4, &quads[0], 4);
}
// FUN_0021BBB0
void func_0021bbb0(s32 arg0, u16 arg1)
{
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045c870(u8 *arg0, s32 arg1);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern f32 fGpffff84a4;
    extern f32 fGpffff84cc;
    union {
        f32 value;
        u8 bytes[4];
    } color;
    union {
        f32 f;
        s32 i;
    } color_value;
    union {
        f32 f;
        s32 i;
    } arg_color_copy;
    union {
        Vec2f v;
        struct {
            s32 low;
            s32 high;
        } raw;
    } coords;
    f32 scale;

    coords.raw.low = 0x43A00000;
    coords.raw.high = 0x43640000;
    D_00887300[0](1, 0);
    arg1 = arg1 & 0xFFFF;
    if ((arg1 >= 0x21) && (arg1 < 0x30)) {
        color.bytes[0] = 0;
        color.bytes[1] = 0;
        color.bytes[2] = 0;
        scale = 400.0f *
                (1.0f - func_0044b610(
                    fGpffff84a4 * ((f32)(arg1 - 0x21) / 15.0f)));
        func_00489f80();
        func_003f6440(3, 0x31801);
        color.bytes[3] = 0;
        func_0045c870(color.bytes, 0);
        color.bytes[3] = 0xFF;
        color_value.f = color.value;
        func_00365f00(coords.v, 0.0f,
                      color_value.i, color_value.i,
                      scale, 0.0f, 0x24, fGpffff84cc, 1.0f, 0);
        func_0048a000();
        func_003f6440(3, 0x37801);
    }
    if (arg1 >= 3) {
        if (arg1 < 0x21) {
            func_003f6440(2, 0x48);
            scale = 400.0f *
                    func_0044b7b0(
                        fGpffff84a4 * ((f32)(arg1 - 3) / 30.0f));
            arg_color_copy.f = *(f32 *)&arg0;
            func_00365f00(coords.v, 0.0f,
                          arg_color_copy.i, arg_color_copy.i,
                          scale, 0.0f, 0x24, fGpffff84cc, 1.0f, 0);
            func_003f6440(2, 0x44);
        } else if (arg1 < 0x30) {
            func_003f6440(2, 0x48);
            func_0045c870((u8 *)&arg0, 0);
            func_003f6440(2, 0x44);
        }
    }
}
// FUN_0021BE10
void func_0021be10(u8 *arg0, s32 arg1)
{
    func_0043f9c8(arg0, 0, 0xC);
    *(s32 *)(arg0 + 8) = arg1;
    *(s16 *)(arg0 + 4) = 1;
}
// FUN_0021BE60
s32 func_0021be60(void)
{
    return iGpffffb470;
}
// FUN_0021BE70
void func_0021be70(void)
{
}
/* measured 0021be80: object 3236B vs retail window 5568B; retail 1392 instrs vs object 809 instrs (-41.9%, gate needs 1350-1433); differing words 1248 reloc-masked (GUARDED_SCORE), fnalign 1353 edits +9 reloc-only. Archive claimed object 3228B vs 5568B nd 2356 (sizes ~match +8B from truthful D_008872F8[0]/ctx casts, score disagrees, not copied). Frame object 0x180 vs retail 0x2F0 (368B short). JAL retail 53 (1x452560,1x201350,8x21b500,18x21b630,2x21bbb0,3x3b7060,4x3f6440,2x457120,2x45af60,8x46d730,4x indirect) vs object ~31 (missing 6x21b500 static,7x21b630,2x457120 inv,7x46d730). */
/* shortfall clusters: largest retail[320:670] 351 vs object[240:243] 4, next retail[989:1138] 150 vs 3, plus dozens of 5-35 replaces for (s32)(4.0f/2.0f scaled)&mask clamps and fGpffff84cc sign mul chains. Excluded: dropped else (mode&1/frame<0x30/==1 arms present), off-by-one (0x30/0xC/4/12/6 intact), folded switch (none), omitted-call as sole cause (22 missing jal ~300 instrs, not 583), unsigned/narrow/field bloat (signed, no s16, per-field). Truthful compile fixes (D_008872F8[0], (u8*)ctx casts) kept for measure; lying 21b500 (7 vs 8 args)/21b630 (s32 vs union)/21bbb0 (s32 vs u16) noted, production stays ASM. */
/* gate: func_0021be80 is FAR OUTSIDE the +-3% band - object 809 against retail 1389, -41.8%,
   where the band is 1350-1433.  Two fifths of the function is simply not written.
   It is kept installed only because the missing code is localised and named: retail[320:670] 351 against 4 and retail[989:1138] 150 against 3.
   Everything else measured against this body is meaningless - the 1248 differing
   words and 1353 fnalign edits are scores against a body of the wrong length
   (handoff 7y), and they must not be quoted as progress or compared with any floor
   inside the gate.  The only work that counts here is writing the missing blocks:
   disassemble each retail range named above, describe what it computes, write it,
   measure.  Do not tune expressions in the part that exists. */
// FUN_0021BE80 NONMATCHING
#ifdef NON_MATCHING
void func_0021be80(u8 *arg0, u8 *arg1)
{
    extern void func_0021bbb0(s32 color, s32 frame);
    extern void func_0021b500(void *dst, f32 x, f32 y, f32 z, f32 u, f32 v,
                              s32 color);
    extern s32 func_003b7060(void);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_00457120(void);
    extern void func_0046d730(void *file, s32 line);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern void func_0021b630(f32 f0, f32 f1, f32 f2, f32 f3, f32 f4,
                              f32 f5, f32 f6, f32 f7, s32 color, f32 f8);
    extern f32 D_00628FD0[];
    extern f32 D_00628FE8[];
    extern f32 D_00629000[];
    extern f32 D_00629018[];
    extern f32 D_00629030[];
    extern f32 D_006290B0;
    extern f32 D_006290B4;
    extern f32 D_006290B8;
    extern f32 D_006290BC;
    extern f32 D_008872F8[];
    extern f32 fGpffff84cc;
    extern f32 fGpffff84d0;
    u8 quad[0x100];
    u8 quadB[0x100];
    u8 color0[4];
    u8 *ctx;
    f32 *tile;
    f32 *tex;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 u0;
    f32 v0;
    f32 du;
    f32 dv;
    f32 scale;
    f32 z;
    f32 randomf;
    f32 edge;
    f32 width;
    f32 height;
    f32 texw;
    f32 texh;
    s32 mode;
    s32 frame;
    s32 i;
    s32 j;
    s32 bit;
    s32 id;
    s32 row;
    s32 group;
    s32 side;
    s32 signx;
    s32 signy;
    s32 value;
    s32 flags;
    s32 color;
    s32 base;
    u16 index;
    f32 t0[4];
    f32 t1[4];
    f32 t2[4];
    f32 t3[4];
    s32 id0;
    s32 id1;
    s32 id2;
    s32 id3;
    s32 row0;
    s32 row1;
    s32 row2;
    s32 row3;
    s32 group0;
    s32 group1;
    s32 group2;
    s32 group3;
    s32 side0;
    s32 side1;
    s32 side2;
    s32 side3;
    s32 signx0;
    s32 signx1;
    s32 signx2;
    s32 signx3;
    s32 signy0;
    s32 signy1;
    s32 signy2;
    s32 signy3;
    s32 q60;
    s32 q61;
    s32 q62;
    s32 q63;
    s32 q30;
    s32 q31;
    s32 q32;
    s32 q33;
    s32 r60;
    s32 r61;
    s32 r62;
    s32 r63;
    s32 r30;
    s32 r31;
    s32 r32;
    s32 r33;
    s32 nxt;
    f32 sx0;
    f32 sy0;
    f32 sx1;
    f32 sy1;
    f32 sx2;
    f32 sy2;
    f32 sx3;
    f32 sy3;
    f32 f120;
    f32 f130;
    f32 f150;
    f32 f160;
    f32 f121;
    f32 f131;
    f32 f151;
    f32 f161;
    f32 f122;
    f32 f132;
    f32 f152;
    f32 f162;
    f32 f123;
    f32 f133;
    f32 f153;
    f32 f163;
    f32 *tile0;
    f32 *tile1;
    f32 *tile2;
    f32 *tile3;
    f32 tR[4];
    f32 tF[4];
    s32 rowR;
    s32 rowF;
    s32 groupR;
    s32 groupF;
    s32 sideR;
    s32 sideF;
    s32 signxR;
    s32 signxF;
    s32 signyR;
    s32 signyF;
    s32 q6R;
    s32 q6F;
    s32 q3R;
    s32 q3F;
    s32 r6R;
    s32 r6F;
    s32 r3R;
    s32 r3F;
    f32 sxR;
    f32 syR;
    f32 sxF;
    f32 syF;
    f32 f12R;
    f32 f13R;
    f32 f15R;
    f32 f16R;
    f32 f12F;
    f32 f13F;
    f32 f15F;
    f32 f16F;
    f32 *tileR;
    f32 *tileF;

    (void)arg0;
    ctx = (u8 *)func_00452560(*(void **)(arg1 + 8));
    func_00201350();
    mode = *(u16 *)arg1;
    if (mode & 1) {
        frame = *(u16 *)(arg1 + 2);
        if (frame < 0x30) {
            if (*(u16 *)(iGpffffb3ac + 0x1A) == 1) {
                if (frame == 4) {
                    func_0045af60(1, 14, 2, 0);
                }
                color = 0xFFFF9F2D;
                func_0021bbb0(color, frame);
                D_00887300[0](1, iGpffffb470);
                func_0021b630(D_00628FD0[0], D_00628FD0[1], 0.0f,
                              D_00628FD0[2], D_00628FD0[3], D_00628FD0[4],
                              D_00628FD0[5], D_00628FD0[4] + D_00628FD0[2],
                              color, D_00628FD0[5] + D_00628FD0[3]);
                func_0021b630(D_00628FE8[0], D_00628FE8[1], 0.0f,
                              D_00628FE8[2], D_00628FE8[3], D_00628FE8[4],
                              D_00628FE8[5], D_00628FE8[4] + D_00628FE8[2],
                              color, D_00628FE8[5] + D_00628FE8[3]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_003f6440(2, 0x48);
                color = 0xFF6B9EFF;
                index = *(u16 *)(arg1 + 4);
                if (index >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                id0 = (s32)index;
                t0[0] = D_006290B0;
                t0[1] = D_006290B4;
                t0[2] = D_006290B8;
                t0[3] = D_006290BC;
                if (id0 < 0 || id0 >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                q60 = id0 / 6;
                q30 = id0 / 3;
                side0 = (q30 + q60) & 1;
                r60 = id0 % 6;
                r30 = id0 % 3;
                row0 = (r60 < 3) ? r30 : (2 - r30);
                tile0 = &D_00628FD0[(row0 + 5) * 6];
                group0 = id0 / 6;
                signx0 = (side0 == 0) ? 1 : -1;
                signy0 = (group0 == 0) ? 1 : -1;
                sx0 = (f32)signx0;
                sy0 = (f32)signy0;
                f120 = (f32)0x13F - fGpffff84cc * ((t0[side0 * 2] - (f32)0x13F) + sx0 * tile0[0]);
                f130 = fGpffff84d0 - ((t0[group0 * 2 + 1] - fGpffff84d0) + sy0 * tile0[1]);
                f150 = fGpffff84cc * ((f32)(-signx0) * tile0[2]);
                f160 = (f32)(-signy0) * tile0[3];
                func_0021b630(f120, f130, 0.0f, f150, f160, tile0[4], tile0[5], tile0[4] + tile0[2], color, tile0[5] + tile0[3]);
                id1 = (s32)index + 6;
                t1[0] = D_006290B0;
                t1[1] = D_006290B4;
                t1[2] = D_006290B8;
                t1[3] = D_006290BC;
                if (id1 < 0 || id1 >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                q61 = id1 / 6;
                q31 = id1 / 3;
                side1 = (q31 + q61) & 1;
                r61 = id1 % 6;
                r31 = id1 % 3;
                row1 = (r61 < 3) ? r31 : (2 - r31);
                tile1 = &D_00628FD0[(row1 + 5) * 6];
                group1 = id1 / 6;
                signx1 = (side1 == 0) ? 1 : -1;
                signy1 = (group1 == 0) ? 1 : -1;
                sx1 = (f32)signx1;
                sy1 = (f32)signy1;
                f121 = (f32)0x13F - fGpffff84cc * ((t1[side1 * 2] - (f32)0x13F) + sx1 * tile1[0]);
                f131 = fGpffff84d0 - ((t1[group1 * 2 + 1] - fGpffff84d0) + sy1 * tile1[1]);
                f151 = fGpffff84cc * ((f32)(-signx1) * tile1[2]);
                f161 = (f32)(-signy1) * tile1[3];
                func_0021b630(f121, f131, 0.0f, f151, f161, tile1[4], tile1[5], tile1[4] + tile1[2], color, tile1[5] + tile1[3]);
                nxt = ((s32)index + 1) % 6;
                id2 = nxt;
                t2[0] = D_006290B0;
                t2[1] = D_006290B4;
                t2[2] = D_006290B8;
                t2[3] = D_006290BC;
                if (id2 < 0 || id2 >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                q62 = id2 / 6;
                q32 = id2 / 3;
                side2 = (q32 + q62) & 1;
                r62 = id2 % 6;
                r32 = id2 % 3;
                row2 = (r62 < 3) ? r32 : (2 - r32);
                tile2 = &D_00628FD0[(row2 + 5) * 6];
                group2 = id2 / 6;
                signx2 = (side2 == 0) ? 1 : -1;
                signy2 = (group2 == 0) ? 1 : -1;
                sx2 = (f32)signx2;
                sy2 = (f32)signy2;
                f122 = (f32)0x13F - fGpffff84cc * ((t2[side2 * 2] - (f32)0x13F) + sx2 * tile2[0]);
                f132 = fGpffff84d0 - ((t2[group2 * 2 + 1] - fGpffff84d0) + sy2 * tile2[1]);
                f152 = fGpffff84cc * ((f32)(-signx2) * tile2[2]);
                f162 = (f32)(-signy2) * tile2[3];
                func_0021b630(f122, f132, 0.0f, f152, f162, tile2[4], tile2[5], tile2[4] + tile2[2], color, tile2[5] + tile2[3]);
                id3 = nxt + 6;
                t3[0] = D_006290B0;
                t3[1] = D_006290B4;
                t3[2] = D_006290B8;
                t3[3] = D_006290BC;
                if (id3 < 0 || id3 >= 0xC) {
                    func_0046d730((void *)&D_00629030[0], 0xC6);
                }
                q63 = id3 / 6;
                q33 = id3 / 3;
                side3 = (q33 + q63) & 1;
                r63 = id3 % 6;
                r33 = id3 % 3;
                row3 = (r63 < 3) ? r33 : (2 - r33);
                tile3 = &D_00628FD0[(row3 + 5) * 6];
                group3 = id3 / 6;
                signx3 = (side3 == 0) ? 1 : -1;
                signy3 = (group3 == 0) ? 1 : -1;
                sx3 = (f32)signx3;
                sy3 = (f32)signy3;
                f123 = (f32)0x13F - fGpffff84cc * ((t3[side3 * 2] - (f32)0x13F) + sx3 * tile3[0]);
                f133 = fGpffff84d0 - ((t3[group3 * 2 + 1] - fGpffff84d0) + sy3 * tile3[1]);
                f153 = fGpffff84cc * ((f32)(-signx3) * tile3[2]);
                f163 = (f32)(-signy3) * tile3[3];
                func_0021b630(f123, f133, 0.0f, f153, f163, tile3[4], tile3[5], tile3[4] + tile3[2], color, tile3[5] + tile3[3]);
                func_003f6440(2, 0x44);
                color0[0] = 0x14;
                color0[1] = 0x14;
                color0[2] = 0x14;
                color0[3] = 0xFF;
                tex = D_00629000;
                x0 = tex[0];
                y0 = tex[1];
                u0 = tex[2];
                v0 = tex[3];
                width = tex[4];
                height = tex[5];
                z = D_008872F8[0];
                for (i = 0; i < 4; i++) {
                    func_0021b500(quad + i * 0x40,
                                  x0 + ((i == 1 || i == 3) ? width : 0.0f),
                                  y0 + ((i >= 2) ? height : 0.0f), z,
                                  (i == 1 || i == 3) ? width / 256.0f : 0.0f,
                                  (i >= 2) ? height / 256.0f : 0.0f,
                                  *(s32 *)color0);
                }
                D_00887310[0](4, quad, 4);
                index = *(u16 *)(arg1 + 4) + 1;
                *(u16 *)(arg1 + 4) = (index >= 6) ? 0 : index;
            } else {
                if (frame == 4) {
                    func_0045af60(1, 14, 2, 1);
                }
                color = 0xFF2324FF;
                func_0021bbb0(color, frame);
                D_00887300[0](1, iGpffffb470);
                func_0021b630(D_00628FD0[0], D_00628FD0[1], 0.0f,
                              D_00628FD0[2], D_00628FD0[3], D_00628FD0[4],
                              D_00628FD0[5], D_00628FD0[4] + D_00628FD0[2],
                              color, D_00628FD0[5] + D_00628FD0[3]);
                func_0021b630(D_00628FE8[0], D_00628FE8[1], 0.0f,
                              D_00628FE8[2], D_00628FE8[3], D_00628FE8[4],
                              D_00628FE8[5], D_00628FE8[4] + D_00628FE8[2],
                              color, D_00628FE8[5] + D_00628FE8[3]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], -D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              -fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_0021b630(D_00629030[0], D_00629030[1], 0.0f,
                              fGpffff84cc * D_00629030[2], D_00629030[3],
                              D_00629030[4] + D_00629030[2],
                              D_00629030[5] + D_00629030[3], D_00629030[4],
                              color, D_00629030[5]);
                func_003f6440(2, 0x48);
                color = 0xFF2727FF;
                for (i = 0; i < 12; i++) {
                    bit = 1 << i;
                    if (bit & 0xC61) {
                        value = func_003b7060();
                        randomf = (value < 0) ? (f32)(2 * (((u32)value >> 1) | (value & 1))) :
                            (f32)value;
                        if ((s32)(4.0f * (randomf / 2147483600.0f)) == 0) {
                            tR[0] = D_006290B0;
                            tR[1] = D_006290B4;
                            tR[2] = D_006290B8;
                            tR[3] = D_006290BC;
                            if (i < 0 || i >= 0xC) {
                                func_0046d730((void *)&D_00629030[0], 0xC6);
                            }
                            q6R = i / 6;
                            q3R = i / 3;
                            sideR = (q3R + q6R) & 1;
                            r6R = i % 6;
                            r3R = i % 3;
                            rowR = (r6R < 3) ? r3R : (2 - r3R);
                            tileR = &D_00628FD0[(rowR + 5) * 6];
                            groupR = i / 6;
                            signxR = (sideR == 0) ? 1 : -1;
                            signyR = (groupR == 0) ? 1 : -1;
                            sxR = (f32)signxR;
                            syR = (f32)signyR;
                            f12R = (f32)0x13F - fGpffff84cc * ((tR[sideR * 2] - (f32)0x13F) + sxR * tileR[0]);
                            f13R = fGpffff84d0 - ((tR[groupR * 2 + 1] - fGpffff84d0) + syR * tileR[1]);
                            f15R = fGpffff84cc * ((f32)(-signxR) * tileR[2]);
                            f16R = (f32)(-signyR) * tileR[3];
                            func_0021b630(f12R, f13R, 0.0f, f15R, f16R, tileR[4], tileR[5], tileR[4] + tileR[2], color, tileR[5] + tileR[3]);
                        }
                    }
                    if (*(u16 *)(arg1 + 4) & bit) {
                        tF[0] = D_006290B0;
                        tF[1] = D_006290B4;
                        tF[2] = D_006290B8;
                        tF[3] = D_006290BC;
                        if (i < 0 || i >= 0xC) {
                            func_0046d730((void *)&D_00629030[0], 0xC6);
                        }
                        q6F = i / 6;
                        q3F = i / 3;
                        sideF = (q3F + q6F) & 1;
                        r6F = i % 6;
                        r3F = i % 3;
                        rowF = (r6F < 3) ? r3F : (2 - r3F);
                        tileF = &D_00628FD0[(rowF + 5) * 6];
                        groupF = i / 6;
                        signxF = (sideF == 0) ? 1 : -1;
                        signyF = (groupF == 0) ? 1 : -1;
                        sxF = (f32)signxF;
                        syF = (f32)signyF;
                        f12F = (f32)0x13F - fGpffff84cc * ((tF[sideF * 2] - (f32)0x13F) + sxF * tileF[0]);
                        f13F = fGpffff84d0 - ((tF[groupF * 2 + 1] - fGpffff84d0) + syF * tileF[1]);
                        f15F = fGpffff84cc * ((f32)(-signxF) * tileF[2]);
                        f16F = (f32)(-signyF) * tileF[3];
                        func_0021b630(f12F, f13F, 0.0f, f15F, f16F, tileF[4], tileF[5], tileF[4] + tileF[2], color, tileF[5] + tileF[3]);
                    }
                }
                func_003f6440(2, 0x44);
                color0[0] = 0x14;
                color0[1] = 0x14;
                color0[2] = 0x14;
                color0[3] = 0xFF;
                tex = D_00629018;
                x0 = tex[0];
                y0 = tex[1];
                u0 = tex[2];
                v0 = tex[3];
                width = tex[4];
                height = tex[5];
                z = D_008872F8[0];
                for (i = 0; i < 4; i++) {
                    func_0021b500(quadB + i * 0x40,
                                  x0 + ((i == 1 || i == 3) ? width : 0.0f),
                                  y0 + ((i >= 2) ? height : 0.0f), z,
                                  (i == 1 || i == 3) ? width / 256.0f : 0.0f,
                                  (i >= 2) ? height / 256.0f : 0.0f,
                                  *(s32 *)color0);
                }
                D_00887310[0](4, quadB, 4);
                index = *(u16 *)(arg1 + 2);
                if ((index & 1) == 0) {
                    value = func_003b7060();
                    randomf = (value < 0) ? (f32)(2 * (((u32)value >> 1) | (value & 1))) :
                        (f32)value;
                    value = (s32)(2.0f * (randomf / 2147483600.0f));
                    *(u16 *)(arg1 + 4) = (u16)(func_003b7060() & (0xAAAAA >> value));
                }
            }
            (*(u16 *)(arg1 + 2))++;
            return;
        }
        *(u16 *)arg1 &= (u16)~1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be80);
#endif
// FUN_0021D440
void func_0021d440(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    *(s16 *)(p + 0x9E6) = 0;
    *(u16 *)(p + 0x9E4) = *(u16 *)(p + 0x9E4) | 1;
}
// FUN_0021D470
s32 func_0021d470(s32 task)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560((void *)task) + 0x9E4) & 1) != 0;
    return flag ^ 1;
}
// FUN_0021D4A0
s32 func_0021d4a0(s32 arg0)
{
    extern s32 func_0036e8a0(s32 arg0);
    extern s32 func_002218e0(KwlnTask *task);
    extern void func_0036e7e0(s32 arg0);
    extern void func_0021e110(u8 *arg0, u8 *arg1);
    extern s32 func_002216b0(s32 arg0);
    extern s32 func_0036e840(s32 arg0);
    extern void func_0036e810(s32 arg0);
    extern s32 func_00221740(s32 arg0);
    extern void func_002216e0(s32 arg0);
    extern s32 func_002230e0(s32 arg0);
    extern s32 func_00223730(s32 arg0);
    extern s32 func_00223f40(s32 arg0);
    extern s32 func_00223240(KwlnTask *task);
    extern void func_002231e0(KwlnTask *task);
    extern s32 func_00223890(KwlnTask *task);
    extern void func_00223830(KwlnTask *task);
    extern s32 func_00224080(KwlnTask *task);
    extern void func_00224040(KwlnTask *task);
    extern s32 func_0036e8d0(void);
    extern s32 func_00221910(void);
    extern s32 func_00223270(void);
    extern s32 func_002238c0(void);
    extern s32 func_002240b0(void);
    u8 *work;
    s32 flags;
    s32 ready;

    work = (u8 *)func_00452560((void *)arg0);
    switch (*(s32 *)(work + 4)) {
    case 1:
        *(s32 *)(work + 4) = 2;
        break;
    case 2:
        flags = *(s32 *)work;
        if ((flags & 1) == 0 || (flags & 4) == 0) {
            if ((flags & 2) != 0) {
                ready = 1;
                if ((*(s32 *)(work + 0x60) & 1) != 0 &&
                    func_0036e8a0(*(s32 *)(work + 0x938)) != 0) {
                    ready = 0;
                }
                if (func_002218e0(*(KwlnTask **)(work + 0x93C)) != 0) {
                    ready = 0;
                }
                if (ready != 0) {
                    flags = *(s32 *)work;
                    flags &= ~2;
                    *(s32 *)work = flags;
                    flags |= 4;
                    *(s32 *)work = flags;
                }
            }
            break;
        }
    case 3:
        flags = *(s32 *)(work + 0x60);
        if ((flags & 1) != 0) {
            func_0036e7e0(*(s32 *)(work + 0x938));
            *(s32 *)(work + 4) = 4;
        } else {
            func_0021e110(work + 0x60, work + 8);
            func_002216b0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 4:
        if (func_0036e840(*(s32 *)(work + 0x938)) == 0) {
            func_0036e810(*(s32 *)(work + 0x938));
            *(s32 *)(work + 0x938) = 0;
            func_0021e110(work + 0x60, work + 8);
            func_002216b0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 5:
        if (func_00221740(*(s32 *)(work + 0x93C)) == 0) {
            func_002216e0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 0x93C) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 2) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                *(s32 *)(work + 0x940) = func_002230e0(arg0);
                *(s32 *)(work + 4) = 6;
            } else if ((flags & 8) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                *(s32 *)(work + 0x944) = func_00223730(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                func_0021eb60(work + 0x60);
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                func_0021e9a0(work + 0x60, work + 8);
                func_0021eb60(work + 0x60);
                func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 6:
        if (func_00223240(*(KwlnTask **)(work + 0x940)) == 0) {
            func_002231e0(*(KwlnTask **)(work + 0x940));
            *(s32 *)(work + 0x940) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 8) != 0) {
                *(s32 *)(work + 0x944) = func_00223730(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                func_0021eb60(work + 0x60);
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                func_0021eb60(work + 0x60);
                func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 7:
        if (func_00223890(*(KwlnTask **)(work + 0x944)) == 0) {
            func_00223830(*(KwlnTask **)(work + 0x944));
            *(s32 *)(work + 0x944) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 0x10) != 0) {
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
            func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 8:
        if (func_00224080(*(KwlnTask **)(work + 0x948)) == 0) {
            func_00224040(*(KwlnTask **)(work + 0x948));
            *(s32 *)(work + 0x948) = 0;
            *(s32 *)(work + 4) = 9;
        }
        break;
    case 9:
        if (func_0036e8d0() == 0 &&
            func_00221910() == 0 &&
            func_00223270() == 0 &&
            func_002238c0() == 0 &&
            func_002240b0() == 0) {
            *(s32 *)(work + 4) = 0;
        }
        break;
    }
    return 0;
}
// FUN_0021D920
void func_0021d920(s32 task)
{
    u8 *p;
    s32 value;

    p = (u8 *)func_00452560((void *)task);
    value = *(s32 *)(p + 0x934);
    if (value != 0) {
        func_00454bd0((u8 *)value);
    }
    jtbl_008873EC[0](p);
}
// FUN_0021D980
s32 func_0021d980(s32 arg0, u16 *arg1)
{
    u8 *work;
    s32 result;

    func_0044ea90(&D_006290D0, 0x3A);
    work = (u8 *)jtbl_008873E8[0](0x94C, 0x40000);
    func_0043f9c8(work, 0, 0x94C);
    result = func_00451fc0(arg0, &D_006290C0, 0xF, 0, 0,
                           (void *)func_0021d4a0, (void *)func_0021d920, work);
    func_0043f810(work + 8, arg1, 0x58);
    if ((*arg1 & 1) != 0) {
        *(s32 *)(work + 0x60) |= 1;
    }
    *(s32 *)(work + 4) = 1;
    if ((*(s32 *)(work + 0x60) & 1) != 0) {
        *(s32 *)(work + 0x938) = func_0036e690(result, work + 0x48);
    }
    *(s32 *)(work + 0x93C) = func_002215c0(result);
    return result;
}
// FUN_0021DAB0
void func_0021dab0(s32 task)
{
    u8 *p;

    p = (u8 *)func_00452560((void *)task);
    if ((*(s32 *)(p + 0x60) & 1) != 0) {
        func_0036e870(*(s32 *)(p + 0x938));
    }
    func_00221770(*(s32 *)(p + 0x93C));
    *(s32 *)p |= 2;
}
// FUN_0021DB10
s32 func_0021db10(s32 task)
{
    return (*(s32 *)func_00452560((void *)task) & 2) != 0;
}
// FUN_0021DB40
s32 func_0021db40(s32 task)
{
    u8 *p;
    s32 temp;

    p = (u8 *)func_00452560((void *)task);
    if (*(s32 *)(p + 0x938) != 0) {
        return 0;
    }
    temp = *(s32 *)(p + 0x93C);
    if (temp != 0) {
        return func_00221940((KwlnTask *)temp);
    }
    return 0;
}
// FUN_0021DBA0
s32 func_0021dba0(s32 task)
{
    u8 *p;
    s32 value;

    p = (u8 *)func_00452560((void *)task);
    *(s32 *)(p + 4) = 0;
    *(s32 *)(p + 8) = 0;
    func_00460ac0(&D_00796340, p + 4);
    value = *(s32 *)p + 1;
    *(s32 *)p = value;
    if (value == 0xC) {
        func_00122520(1, 1);
        goto exit;
    }
    if (value <= 0xC) {
        goto exit;
    }
    if (func_00122720() != 0) {
        return -1;
    }
exit:
    return 0;
}
// FUN_0021DC50
void func_0021dc50(s32 arg0, s32 *arg1)
{
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    Vec2f sp38;
    f32 var_f1;

    func_00201350();
    var_f20 = (f32)*(s32 *)(arg1 + 0) / 12.0f;
    if (!(var_f20 <= 1.0f)) {
        var_f20 = 1.0f;
    }
    sp38.x = 0.0f;
    sp38.y = -500.0f;
    sp38.x = sp38.x + var_f20 * (800.0f * func_0044b7b0(fGpffff837c));
    temp_f0 = func_0044b610(fGpffff837c);
    temp_f1 = 800.0f * temp_f0;
    sp38.y = sp38.y + var_f20 * temp_f1;
    func_00364c90(sp38, 0.0f, 0xFF,
                  1500.0f, 1000.0f, fGpffff8378, 0);
}
// FUN_0021DDA0
void func_0021dda0(void)
{
    u8 *work;

    if (func_00452380(&D_006290E0) == 0) {
        func_0044ea90(&D_006290D0, 0x3A);
        work = (u8 *)jtbl_008873E8[0](0x34, 0x40000);
        func_0043f9c8(work, 0, 0x34);
        func_00451de0(&D_006290E0, 0x10, 0, 0,
                      (void *)func_0021dba0, (void *)func_0021dd60, work);
        *(void **)(work + 0xC) = (void *)func_0021dc50;
        *(u8 **)(work + 0x14) = work;
    }
}
// FUN_0021DE60
s32 func_0021de60(void)
{
    return func_00452380(&D_006290E0) == 0;
}
/* measured: 440/448B, five resolved relocations, no instruction differences;
   the remaining eight bytes are zero alignment. The u32 result retains retail
   allocation only with signed casts at both clamp bounds. Valid tables,
   nonzero divisor and representable intermediate conversions are required. */
// FUN_0021DE90
#pragma push
#pragma opt_propagation off
s32 func_0021de90(s32 arg0, u8 *arg1)
{
    s32 value;
    u32 result;
    f32 scale;
    f32 table_value;
    s32 delta;
    s32 index;

    value = *(s32 *)(arg1 + 4);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg1 & 8) == 0 && func_00106330(0x1403) != 0) {
        if (func_00106330(0x1428) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (func_00106330(0x1429) != 0) {
            value = 0;
        }
    }
    scale = 1.0f / (f32)*(s32 *)(arg1 + 0x20);
    if ((*(s32 *)(iGpffffb414 + (*(s32 *)(arg1 + 0xC) * 0x18)) & 0x80) != 0) {
        result = (s32)((f32)value * scale);
    } else {
        delta = *(s32 *)(arg1 + 0x38) - arg0;
        if (delta >= 10) {
            index = 20;
        } else if (delta < -9) {
            index = 0;
        } else {
            index = delta + 10;
        }
        table_value = iGpffffb40c[index];
        result = (s32)(scale * ((f32)value * table_value));
    }
    if ((s32)result <= 0xFFFF) {
        goto normal_result;
    }
    result = 0xFFFF;
    goto finish;
normal_result:
    if ((s32)result > 0) {
        goto finish;
    }
    result = 1;
finish:

    return result;
}
#pragma opt_propagation on
#pragma pop
// FUN_0021E050
s32 func_0021e050(u8 *arg0)
{
    s32 value;

    value = *(s32 *)(arg0 + 8);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg0 & 8) == 0 && (func_00106330(0x1403) != 0)) {
        if (func_00106330(0x1420) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (func_00106330(0x1421) != 0) {
            value = 1;
        }
    }
    return value;
}
extern s32 func_00104c70(s32 arg0);
extern u8 datPersonaGetLevel(int persona);
extern u32 datPersonaGetNextExp(int persona);
extern u16 *datPersonaGetSkills(int persona);
extern u16 func_001069d0(s16 arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern u32 func_0010c750(void *persona, u16 level);

/* Prepare XP awards and 0x88-byte growth deltas without applying them.
 * Inventory deltas end at 0x698; four party deltas end at 0x8D4.
 * Loop invariants on preserves the retail award hoists: 2188/2192 bytes,
 * 49 resolved calls, with only four zero alignment bytes remaining. */
#pragma opt_loop_invariants on
// FUN_0021E110
void func_0021e110(u8 *arg0, u8 *arg1)
{
    s32 i;
    s32 j;
    s32 out;
    s32 level;
    s32 base;
    s32 lv;
    s32 lv2;
    s32 lv3;
    s32 level2;
    s32 v6;
    s32 v7;
    u16 *entry3;

    s32 sum;
    s32 count;
    s32 count2;
    s32 id;
    s32 id2;
    s32 v;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 k;
    u8 c;
    u16 *entry;
    u16 *entry2;
    s32 ref;

    func_0043f9c8(arg0, 0, 0x8D4);
    out = 0;
    if (*(u16 *)arg1 & 1) {
        *(u32 *)arg0 |= 1;
    }
    c = func_00104c70(1) & 0xFF;
    level = func_0021de90(c, arg1);
    base = level;
    if (func_001069d0(func_00106cd0(1, 0)) == 0x86) {
        level += (s32)(0.5f * (f32)level);
    }
    if (func_001069d0(func_00106cd0(1, 1)) == 0x86) {
        level += (s32)(0.5f * (f32)base);
    }
    if (c != (func_001059e0(level + func_00105210(1)) & 0xFF)) {
        *(u32 *)arg0 |= 2;
    }
    *(s16 *)(arg0 + 0x698) = *(s16 *)(arg1 + 0x10);
    *(u32 *)(arg0 + 4) = level;
    entry = func_0010a900(1);
    func_00105510(1);
    ref = entry[1];
    count = func_0010b6f0() & 0xFFFF;
    for (i = 0; i < count; i++) {
        entry2 = func_0010ace0((s16)i);
        id = datPersonaGetLevel((s32)entry2) & 0xFF;
        lv = func_0021de90(id, arg1);
        if (entry2[1] == ref) {
            level = lv;
            if (func_0010a9b0(1) != 0) {
                level += (s32)(0.5f * (f32)lv);
            }
            if (func_001069d0(func_00106cd0(1, 0)) == 0x86) {
                level += (s32)(0.5f * (f32)lv);
            }
            if (func_001069d0(func_00106cd0(1, 1)) == 0x86) {
                level += (s32)(0.5f * (f32)lv);
            }
        } else {
            v = (s32)datPersonaGetSkills((s32)entry2);
            level = 0;
            for (k = 0; k < 8; k++) {
                v2 = *(u16 *)(v + k * 2);
                if (v2 != 0) {
                    switch (v2) {
                    case 0x1FF:
                        level += (s32)(0.25f * (f32)lv);
                        break;
                    case 0x200:
                        level += (s32)(0.5f * (f32)lv);
                        break;
                    case 0x201:
                        level += (s32)(f32)lv;
                        break;
                    }
                }
            }
            sum = level;
            if (entry2[0] & 4) {
                level += (s32)(0.5f * (f32)level);
            }
            if (func_001069d0(func_00106cd0(1, 0)) == 0x86) {
                level += (s32)(0.5f * (f32)sum);
            }
            if (func_001069d0(func_00106cd0(1, 1)) == 0x86) {
                level += (s32)(0.5f * (f32)sum);
            }
        }
        if (id < 99) {
            v3 = datPersonaGetNextExp((s32)entry2);
            v4 = (s32)func_0010c750(entry2, (u16)(id + 1));
            if (v4 <= v3 + level) {
                *(u32 *)arg0 |= 8;
                func_0010be60((u8 *)entry2, arg0 + i * 0x88 + 0x38, level);
            }
            if (level != 0) {
                *(u32 *)(arg0 + i * 4 + 8) = level;
            }
        }
    }
    count2 = *(s32 *)(arg1 + 0x1C);
    for (j = 0; j < count2; j++) {
        id2 = *(u16 *)(arg1 + j * 2 + 0x12);
        if (id2 != 1) {
            entry3 = func_0010a900((u16)id2);
            v5 = datPersonaGetLevel((s32)entry3) & 0xFF;
            lv2 = func_0021de90(v5, arg1);
            level2 = lv2;
            if (func_001069d0(func_00106cd0((s16)id2, 0)) == 0x86) {
                level2 += (s32)(0.5f * (f32)lv2);
            }
            if (func_001069d0(func_00106cd0((s16)id2, 1)) == 0x86) {
                level2 += (s32)(0.5f * (f32)lv2);
            }
            if (v5 < 99) {
                v3 = datPersonaGetNextExp((s32)entry3);
                v4 = (s32)func_0010c750(entry3, (u16)(v5 + 1));
                if (v4 <= v3 + level2) {
                    *(u32 *)arg0 |= 0x10;
                    func_0010be60((u8 *)entry3, arg0 + out * 0x88 + 0x6B4, level2);
                }
                *(u32 *)(arg0 + out * 4 + 0x6A4) = level2;
            }
            *(u16 *)(arg0 + out * 2 + 0x69A) = id2;
            out += 1;
        }
    }
    if (func_00106330(0x38) != 0) {
        entry3 = func_0010a900(5);
        v5 = datPersonaGetLevel((s32)entry3) & 0xFF;
        lv3 = func_0021de90(v5, arg1);
        level2 = lv3;
        if (func_001069d0(func_00106cd0(5, 0)) == 0x86) {
            level2 += (s32)(0.5f * (f32)lv3);
        }
        if (func_001069d0(func_00106cd0(5, 1)) == 0x86) {
            level2 += (s32)(0.5f * (f32)lv3);
        }
        if (v5 < 99) {
            v3 = datPersonaGetNextExp((s32)entry3);
            v4 = (s32)func_0010c750(entry3, (u16)(v5 + 1));
            if (v4 <= v3 + level2) {
                *(u32 *)arg0 |= 0x10;
                func_0010be60((u8 *)entry3, arg0 + out * 0x88 + 0x6B4, level2);
            }
            v6 = out * 4;
            *(u32 *)(v6 + (s32)arg0 + 0x6A4) = level2;
        }
        v7 = out * 2;
        *(u16 *)(v7 + (s32)arg0 + 0x69A) = 5;
    }
}
#pragma opt_loop_invariants off
/* measured: plain-C reconstruction reaches object size 448B against the
   448B retail window at normalized_diff 7. The prologue, calls, loop
   addressing, and arithmetic all match; the residual is register naming in
   the final sign-extension/clamp sequence. Re-measured at nd 94 after later
   declaration-environment changes in this file. */
/* measured: the per-slot clamp must be one s16 local (`sum`, compared with `> 0x63`):
   the dsll32/dsra32 canonicalisation, slti and li then share $v0 as retail; an s32
   temporary with an (s16) compare colours the sign-extension into $v1. The named
   call-result operand on the left keeps the addu order (v1 + v0). */
// FUN_0021E9A0
void func_0021e9a0(u8 *arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 var_16;
    s32 var_17;
    u8 *temp_19;
    u8 *temp_20;
    s32 temp_21;
    s16 sum;
    temp_17 = (s32)func_00105510(1);
    temp_2 = (s32)func_00105210(1);
    if ((func_001059e0(temp_2) & 0xFF) < 0x63) {
        temp_16 = temp_2 + *(s32 *)(arg0 + 4);
        func_00105990(1, temp_16);
        func_00231ef0((u8 *)temp_17, func_001059e0(temp_16));
    }
    var_16 = *(s32 *)(arg1 + 8);
    if (var_16 <= 0) {
        var_16 = 0;
    } else if ((*(u16 *)arg1 & 8) == 0 && func_00106330(0x1403) != 0) {
        if (func_00106330(0x1420) != 0) {
            var_16 = (s32)(2.0f * (f32)var_16);
        } else if (func_00106330(0x1421) != 0) {
            var_16 = 1;
        }
    }
    func_00106020(var_16);
    var_17 = 0;
    while (var_17 < *(s32 *)(arg1 + 0x30)) {
        temp_19 = arg1 + var_17 * 4;
        temp_20 = temp_19 + 0x24;
        temp_21 = (s16)(func_00106600(*(s16 *)(temp_19 + 0x24)) & 0xFF);
        sum = temp_21 + *(s16 *)(temp_19 + 0x26);
        if (sum > 0x63) {
            sum = 0x63;
        }
        func_00106620(*(s16 *)temp_20, (u8)sum);
        var_17 += 1;
    }
}
// FUN_0021EB60
void func_0021eb60(u8 *arg0)
{
    s32 limit;
    s32 value;
    u8 *persona;
    s32 i;

    limit = func_0010b6f0() & 0xFFFF;
    i = 0;
    while (i < limit) {
        value = *(s32 *)(arg0 + (i * 4) + 8);
        if (value != 0) {
            persona = (u8 *)func_0010ace0((s16)i);
            func_0010c980(persona, value);
            if (func_0010c6f0((PersonaWork *)persona) != 0) {
                func_0010c5a0(persona, arg0 + (i * 0x88) + 0x38);
            }
        }
        i += 1;
    }
}
// FUN_0021EC40
void func_0021ec40(s32 arg0)
{
    s32 temp_2;
    s32 temp_19;
    s32 var_16;

    var_16 = 0;
    goto loop_test;
loop_body:
    temp_19 = *(s32 *)((u8 *)arg0 + (var_16 * 4) + 0x6A4);
    if (temp_19 != 0) {
        temp_2 = (s32)func_0010a900(*(u16 *)((u8 *)arg0 + (var_16 * 2) + 0x69A));
        func_0010c980((u8 *)temp_2, temp_19);
        if (func_0010c6f0((PersonaWork *)temp_2) != 0) {
            func_0010c5a0((u8 *)temp_2,
                          (u8 *)arg0 + (var_16 * 0x88) + 0x6B4);
        }
    }
    var_16 += 1;
loop_test:
    if (var_16 < 4) {
        goto loop_body;
    }
}
