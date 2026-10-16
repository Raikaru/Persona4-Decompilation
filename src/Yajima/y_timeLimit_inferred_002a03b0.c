/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

extern u8 D_0063E918[];

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];

extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern f32 fGpffff8204;
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern f32 func_002a2cd0(u8 *arg0);
extern s32 func_002a2c10(u8 *arg0, f32 *arg1);
extern void func_0025e9e0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

typedef struct P4_002aa450_Pair {
    s64 bits;
    f32 value;
} P4_002aa450_Pair;
typedef struct P4_002aa450_Work {
    u8 matrix[0x40];
    P4_002aa450_Pair pair4;
    P4_002aa450_Pair pair3;
    P4_002aa450_Pair pair2;
    P4_002aa450_Pair pair1;
    P4_002aa450_Pair pair0;
} P4_002aa450_Work;
static inline f32 p4_002aa450_mul(f32 left, f32 right) {
    return left * right;
}
struct RwMatrixTag;
extern void func_00366960(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern f32 fGpffff855c;
extern u8 D_0063EDF0[];
extern u8 D_0063EDF8[];
extern u8 D_0063EE00[];
extern u8 D_0063EE08[];
extern u8 D_0063EE10[];
extern u8 D_0063EE18[];
extern u8 D_0063EE20[];
extern u8 D_0063EE28[];
extern u8 D_0063EE30[];
extern u8 D_0063EE38[];
extern u8 D_00882F28[];
extern u8 D_00882F2C[];
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;

/* Source unit: src/promoted/code1_002a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002a.c; members 002a03b0-002a03b0 */

extern void func_002a02f0(u8 *arg0, s32 arg1);
/* 3888/3888 bytes. Keep the remaining-alpha accumulator separate from
 * the narrowed active alpha, and apply each cursor offset before drawing. */
// FUN_002A03B0
void func_002a03b0(u8 *arg0) {
    extern u8 iGpffffb528[4];
    extern s32 iGpffffb538;
    extern s32 func_0029f790(u8 *arg0);
    extern u32 strlen(const void *arg0);
    extern void strncpy(void *arg0, const void *arg1, s32 arg2);
    extern s32 frFontExDrawText(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7, s32 arg8);
    f32 pos[2];
    f32 px;
    f32 py;
    f32 temp_f20;
    f32 temp_f21_2;
    f32 temp_f20_2;
    f32 var_f12;
    f32 var_f2;
    s32 temp_18_2;
    u8 temp_20_3;
    f32 tt;
    f32 yv;
    f32 cursorOfs = -12.0f;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 temp_6;
    s32 temp_lo;
    s32 temp_lo_2;
    u8 var_16;
    u8 var_20;
    s32 var_16_2;
    u8 var_18;
    s32 var_20_2;
    s32 var_18_2;
    s32 var_3_2;
    s32 var_2;
    u32 temp_16;
    u32 temp_16_2;
    u32 var_19;
    s32 var_18_3;
    u32 var_19_2;
    s32 var_18_4;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u8 *temp_20_2;
    s32 sum;
    u8 *rowBase;
    s32 yBase;
    s32 tv;
    s32 tex;

    temp_19 = *(u8 **)(arg0 + 0x38);
    func_0025e9e0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xA4, iGpffffb540, 1);
    temp_2 = *(s32 *)(temp_19 + 0x1C68) + 1;
    *(s32 *)(temp_19 + 0x1C68) = temp_2;
    if (temp_2 > 0x5A0) {
        *(s32 *)(temp_19 + 0x1C68) = 0;
    }
    func_0025ea20(-78.0f, -82.0f, 0.0f, 0x4972FF, 0xFF, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(*(s32 *)(temp_19 + 0x1C68) * -0x168) / 1440.0f, 1.0f, 1.0f);
    func_0025ea20(540.0f, 347.0f, 0.0f, 0x4972FF, 0xFF, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(*(s32 *)(temp_19 + 0x1C68) * -0x168) / 1440.0f, 1.0f, 1.0f);
    func_0025e9e0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1);
    func_0025e9e0(0.0f, 346.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1);
    func_002a2980(temp_19 + 0x2A8);
    var_16 = (u8)(255.0f * func_002a2cd0(temp_19 + 0x2A8));
    func_002a2c10(temp_19 + 0x2A8, pos);
    px = pos[0];
    py = pos[1];
    temp_3 = *(s32 *)(temp_19 + 0x1C34);
    if (temp_3 == 0) {
        var_20 = var_16 & 0xFF;
        var_18 = 0;
    } else if (temp_3 == 1) {
        s32 remaining = 0xFF;
        var_18 = var_16 & 0xFF;
        remaining -= var_18;
        var_20 = (remaining >> 2) & 0xFF;
    } else if (temp_3 == 2) {
        var_20 = var_16 & 0xFF;
        var_18 = ((0xFF - var_20) >> 2) & 0xFF;
    }
    func_0025e9e0(px, py, 0.0f, 0xFFFFFF, var_20, 0x13, iGpffffb540, 1);
    temp_f20 = 105.0f + px;
    func_0025e9e0(temp_f20, py, 0.0f, 0xFFFFFF, var_20, 0x11, iGpffffb540, 1);
    py = py + 3.0f;
    func_0025e9e0(px, py, 0.0f, 0xFFFFFF, var_18, 0x13, iGpffffb540, 1);
    func_0025e9e0(temp_f20, py, 0.0f, 0xFFFFFF, var_18, 0x12, iGpffffb540, 1);
    func_002a02f0(arg0, 0);
    if (*(s32 *)(temp_19 + 0x1C34) != 0) {
        var_16 = 0xFF;
    }
    temp_18 = *(u8 **)(arg0 + 0x38);
    func_0025e9e0(229.0f, 150.0f, 0.0f, 0x4972FF, var_16, 0x17, iGpffffb540, 1);
    func_0025e9e0(229.0f, 182.0f, 0.0f, 0x4972FF, var_16, 0x17, iGpffffb540, 1);
    if (*(s32 *)(temp_18 + 0x14) != 3) {
        temp_3_2 = iGpffffb538;
        if (temp_3_2 < 8) {
            var_3_2 = (temp_3_2 * 0x1C) + 0xE3;
            var_2 = 0x97;
        } else {
            var_3_2 = ((temp_3_2 - 8) * 0x1C) + 0xE3;
            var_2 = 0xB7;
        }
        func_0025e9e0((f32)var_3_2, (f32)var_2, 0.0f, 0xCCFF33, var_16, 0x18, iGpffffb540, 1);
    }
    func_002a2cd0(temp_19 + 0x210);
    func_002a2c10(temp_19 + 0x210, pos);
    temp_18_2 = *(s32 *)(temp_19 + 0x24) / 5;
    temp_21 = *(s32 *)(temp_19 + 0x30) / 5;
    temp_22 = *(s32 *)(temp_19 + 0x3C) / 5;
    var_16_2 = 0;
    while (var_16_2 < 0x18) {
        temp_f21_2 = (f32)(((var_16_2 / 6) * 0x94) + 0x19);
        temp_f20_2 = (f32)(((var_16_2 % 6) * 0x19) + 0xE3);
        func_0025e9e0(temp_f21_2, temp_f20_2, 0.0f, 0x4972FF, 0xFF, 1, iGpffffb540, 1);
        if (var_16_2 == 0) {
            func_0025e9e0(18.0f, 219.0f, 0.0f, 0x4972FF, 0xFF, 0x1B, iGpffffb540, 1);
        }
        if (var_16_2 == 5) {
            func_0025e9e0(18.0f, 366.0f, 0.0f, 0x4972FF, 0xFF, 0x1C, iGpffffb540, 1);
        }
        if (var_16_2 == 0x12) {
            func_0025e9e0((f32)0x24A, 219.0f, 0.0f, 0x4972FF, 0xFF, 0x1D, iGpffffb540, 1);
        }
        if (var_16_2 == 0x17) {
            func_0025e9e0((f32)0x24A, 366.0f, 0.0f, 0x4972FF, 0xFF, 0x1E, iGpffffb540, 1);
        }
        if (*(s32 *)(temp_19 + 0x14) != 3) {
            if ((temp_18_2 != temp_21) && (var_16_2 == temp_22)) {
                temp_20 = temp_19 + (var_16_2 * 0x98) + 0x340;
                func_002a2780((s32)temp_20);
                func_002a27c0((s32)temp_20, 0, 0, 0, 0,
                              fGpffff8204, 0, 0, 0x14);
            }
            temp_20_2 = temp_19 + (var_16_2 * 0x98) + 0x340;
            func_002a2980(temp_20_2);
            if (var_16_2 == temp_18_2) {
                func_0025e9e0(temp_f21_2, temp_f20_2, 0.0f, 0x49AFFD, 0xFF, 1, iGpffffb540, 1);
                if (var_16_2 == 0) {
                    func_0025e9e0(18.0f, pos[1], 0.0f, 0x49AFFD, 0xFF, 0x1B, iGpffffb540, 1);
                }
                if (var_16_2 == 5) {
                    func_0025e9e0(18.0f, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, 0xFF, 0x1C, iGpffffb540, 1);
                }
                if (var_16_2 == 0x12) {
                    func_0025e9e0((f32)0x24A, pos[1], 0.0f, 0x49AFFD, 0xFF, 0x1D, iGpffffb540, 1);
                }
                if (var_16_2 == 0x17) {
                    func_0025e9e0((f32)0x24A, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, 0xFF, 0x1E, iGpffffb540, 1);
                }
            } else if (func_002a2c70(temp_20_2) != 0) {
                tt = func_002a2cd0(temp_20_2);
                temp_20_3 = (u8)(255.0f * (1.0f - tt));
                func_0025e9e0(temp_f21_2, temp_f20_2, 0.0f, 0x49AFFD, temp_20_3, 1, iGpffffb540, 1);
                if (var_16_2 == 0) {
                    func_0025e9e0(18.0f, pos[1], 0.0f, 0x49AFFD, temp_20_3, 0x1B, iGpffffb540, 1);
                }
                if (var_16_2 == 5) {
                    func_0025e9e0(18.0f, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, temp_20_3, 0x1C, iGpffffb540, 1);
                }
                if (var_16_2 == 0x12) {
                    func_0025e9e0((f32)0x24A, pos[1], 0.0f, 0x49AFFD, temp_20_3, 0x1D, iGpffffb540, 1);
                }
                if (var_16_2 == 0x17) {
                    func_0025e9e0((f32)0x24A, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, temp_20_3, 0x1E, iGpffffb540, 1);
                }
            }
        }
        var_16_2 += 1;
    }
    func_0029f790(arg0);
    if (*(s32 *)(temp_19 + 0x14) != 3) {
        temp_6 = *(s32 *)(temp_19 + 0x20);
        temp_5 = *(s32 *)(temp_19 + 0x1C);
        var_f2 = (f32)((temp_5 % 5) * 0x1B);
        temp_lo = temp_5 / 5;
        switch (temp_lo) {
        case 0:
            var_f2 += 30.0f;
            break;
        case 1:
            var_f2 += 178.0f;
            break;
        case 2:
            var_f2 += 326.0f;
            break;
        case 3:
            var_f2 += 474.0f;
            break;
        }
        yv = (f32)((temp_6 * 0x19) + 0xE5);
        var_f2 += cursorOfs;
        yv += cursorOfs;
        func_0025e9e0(var_f2, yv, 0.0f, 0xCCFF33, 0xFF, 0xF, iGpffffb540, 1);
    }
    for (var_20_2 = 0; var_20_2 < 6; var_20_2++) {
        var_18_2 = 0;
        rowBase = D_007485D0 + (var_20_2 * 0x28);
        yBase = (var_20_2 * 25) + 0xE5;
        for (; var_18_2 < 0x14; var_18_2++) {
            tv = *(s16 *)(rowBase + (var_18_2 * 2));
            if (tv >= 0) {
                tex = tv + 0x20;
                var_f12 = (f32)((var_18_2 % 5) * 0x1B);
                temp_lo_2 = var_18_2 / 5;
                switch (temp_lo_2) {
                case 0:
                    var_f12 += 30.0f;
                    break;
                case 1:
                    var_f12 += 178.0f;
                    break;
                case 2:
                    var_f12 += 326.0f;
                    break;
                case 3:
                    var_f12 += 474.0f;
                    break;
                }
                func_0025e9e0(var_f12, (f32)yBase, 0.0f, 0x2D2D2D, 0xFF, tex, iGpffffb540, 1);
            }
        }
    }
    if ((*(s32 *)(temp_19 + 0x14) == 3) &&
        (*(s32 *)(temp_19 + 8) == 0)) {
        func_0025e9e0(0.0f, 102.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAC, iGpffffb540, 1);
    }
    if ((strlen(D_00882EF0) >> 1) != 0) {
        temp_16 = (u32)(strlen(D_00882EF0) >> 1);
        sum = 0;
        var_18_3 = 0xE7;
        var_19 = 0;
        while (var_19 < temp_16) {
            strncpy(iGpffffb528, D_00882EF0 + (var_19 * 2), 2);
            sum += frFontExDrawText((f32)var_18_3, 121.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            var_18_3 += 0x1C;
            var_19 += 1;
        }
    }
    if ((strlen(D_00882ED0) >> 1) != 0) {
        temp_16_2 = (u32)(strlen(D_00882ED0) >> 1);
        sum = 0;
        var_18_4 = 0xE7;
        var_19_2 = 0;
        while (var_19_2 < temp_16_2) {
            strncpy(iGpffffb528, D_00882ED0 + (var_19_2 * 2), 2);
            sum += frFontExDrawText((f32)var_18_4, 153.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            var_18_4 += 0x1C;
            var_19_2 += 1;
        }
    }
}

