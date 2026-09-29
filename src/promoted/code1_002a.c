/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

s32 func_00452380(void *arg0);
extern u8 D_0063E918[];
void func_00452080(s32 arg0);

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void memset(void *dst, s32 value, u32 size);

extern s32 func_002aa890(u8 *arg0);
extern void func_002aa450(void);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 func_002abf70(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_003f6690(s32 arg0, s32 *arg1);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *arg0, void *arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern void func_002a1ef0(u8 *arg0);
extern f32 fGpffff8204;
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern void func_0029fbb0(u8 *arg0, s32 arg1);
extern s32 func_002a2ca0(u8 *arg0);
extern f32 func_002a2cd0(u8 *arg0);
extern s32 func_002a2c10(u8 *arg0, f32 *arg1);
extern void func_0025e9e0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
extern u8 func_002baac0(u8 *message);
extern void func_002bad10(s32 arg0);
extern void func_002baf40(s32 arg0);
extern void func_002bb050(s32 arg0);
extern s32 func_002bb0e0(void);
extern void func_002bb4e0(void);
extern s32 func_002bb600(void);
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 func_002bb700(void);
extern void func_002bbcc0(void);
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002bdb50(s32 arg0, s8 arg1);
extern void func_002bdea0(void);
extern s32 func_002e7510(s32 arg0);
extern void func_00308f40(void);
extern s32 func_003493b0(u8 *arg0);
extern s32 func_00452490(s32 arg0);
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
extern void RwMatrixRotate(void *arg0, void *arg1, f32 farg0, s32 arg2);
extern void RwMatrixScale(void *arg0, void *arg1, s32 arg2);
extern void func_003e4320(void *arg0, void *arg1, void *arg2);
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
extern void func_0010d490(u8 *arg0, u8 *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void func_00122640(s32 arg0, s32 arg1);
extern void func_0029ebf0(u8 *arg0, s32 arg1);
extern void func_0029f070(u8 *arg0);
extern void func_002a12e0(u8 *arg0, s32 arg1);
extern s32 strncmp(void *arg0, void *arg1, s32 arg2);



// FUN_002A02F0
void func_002a02f0(u8 *arg0, s32 arg1) {
    u8 *temp_4;
    s32 i;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if ((arg1 == 0) && (*(s32 *)(temp_4 + 0x14) != 1)) {
        for (i = 0; i < 6; i++) {
            *(s16 *)(temp_4 + (i * 4) + 0x1C38) = 0;
        }
    }
    func_0029fbb0(arg0, 0);
    func_0029fbb0(arg0, 1);
    func_0029fbb0(arg0, 2);
    func_0029fbb0(arg0, 4);
    func_0029fbb0(arg0, 5);
}
/* 3888/3888 bytes. Keep the remaining-alpha accumulator separate from
 * the narrowed active alpha, and apply each cursor offset before drawing. */
// FUN_002A03B0
void func_002a03b0(u8 *arg0) {
    extern u8 iGpffffb528[4];
    extern s32 iGpffffb538;
    extern s32 func_0029f790(u8 *arg0);
    extern u32 strlen(const void *arg0);
    extern void strncpy(void *arg0, const void *arg1, s32 arg2);
    extern s32 func_00274ed0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7, s32 arg8);
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
            sum += func_00274ed0((f32)var_18_3, 121.0f, 0.0f,
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
            sum += func_00274ed0((f32)var_18_4, 153.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            var_18_4 += 0x1C;
            var_19_2 += 1;
        }
    }
}
typedef struct NameTweenEntry {
    f32 startX, startY, endX, endY, stepX, stepY, rate;
    s8 delay, hold;
    s16 duration;
} NameTweenEntry;
typedef struct NameTweenState {
    NameTweenEntry entries[4];
    s32 current, count, frame;
    u32 flags;
    s32 timer, total;
} NameTweenState;
/* Existing task-work layout. The tween fields are defined by 002a27c0;
 * 0029fbb0 uses the selection pairs, status halfwords and flash flags.
 * State preceding the background tween is outside this renderer's view. */
typedef struct NameEntrySelectionTweens {
    NameTweenState slide, pulse;
} NameEntrySelectionTweens;
typedef struct NameEntryRenderWork {
    /* 0x0000 */ u8 stateBeforeBackground[0x178];
    /* 0x0178 */ NameTweenState background;
    /* 0x0210 */ NameTweenState rowOrigin;
    /* 0x02a8 */ NameTweenState modeTransition;
    /* 0x0340 */ NameTweenState cells[24];
    /* 0x1180 */ NameTweenState rows[6];
    /* 0x1510 */ NameEntrySelectionTweens selection[6];
    /* 0x1c30 */ s32 selectionState[2];
    /* 0x1c38 */ s16 selectionStatus[6][2];
    /* 0x1c50 */ s32 selectionFlash[6];
    /* 0x1c68 */ s32 backgroundFrame;
} NameEntryRenderWork;
typedef char NameTweenEntrySize[(sizeof(NameTweenEntry) == 0x20) ? 1 : -1];
typedef char NameTweenStateSize[(sizeof(NameTweenState) == 0x98) ? 1 : -1];
typedef char NameEntryWorkSize[(sizeof(NameEntryRenderWork) == 0x1c6c) ? 1 : -1];
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
/* Array-member accesses retain the row's animation address across glyph
 * calls. The grid index is reused by the later, disjoint glyph loop.
 * 1828 matching code bytes; the 1840-byte window has twelve zero tail bytes. */
// FUN_002A12E0
void func_002a12e0(u8 *arg0, s32 arg1) {
    NameEntryRenderWork *work;
    f32 stack[2];
    f32 glyphX;
    f32 glyphY;
    f32 rowY;
    f32 cellY;
    f32 cellRowY;
    f32 cellProgress;
    s32 i;
    s32 j;
    s32 cnt;
    s32 q;
    s16 character;

    work = *(NameEntryRenderWork **)(arg0 + 0x38);
    if ((arg1 >= 0) && (func_002a2ca0((u8 *)&work->background) == 0)) {
        u8 alpha;
        alpha = (u8)(255.0f * func_002a2cd0((u8 *)&work->background));
        func_0025e9e0(0.0f, 0.0f, 0.0f, 0xFFFFFF, alpha, 0xA4, iGpffffb540, 1);
        cnt = work->backgroundFrame + 1;
        work->backgroundFrame = cnt;
        if (cnt > 0x5A0) {
            work->backgroundFrame = 0;
        }
        func_0025ea20(-78.0f, -82.0f, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        func_0025ea20(540.0f, (f32)0x15B, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        func_0025e9e0(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1);
        func_0025e9e0(0.0f, 346.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1);
    }
    if (arg1 > 0) {
        func_002a02f0(arg0, 1);
        if (func_002a2ca0((u8 *)&work->rowOrigin) == 0) {
            func_002a2c10((u8 *)&work->rowOrigin, stack);
            func_002a2cd0((u8 *)&work->rowOrigin);
        }
    }
    if (arg1 >= 2) {
        for (i = 0; i < 0x18; i++) {
            NameTweenState *cellTween;
            u8 alpha2;
            cellTween = &work->cells[i];
            if (func_002a2ca0((u8 *)cellTween) == 0) {
                cellProgress = func_002a2cd0((u8 *)cellTween);
                cellRowY = (f32)((i % 6) * 0x19 + 0xE3);
                cellY = cellRowY;
                alpha2 = (u8)(255.0f * cellProgress);
                func_0025e9e0((f32)((i / 6) * 0x94 + 0x19), cellY, 0.0f, 0x4972FF, alpha2, 1, iGpffffb540, 1);
                if (i == 0) {
                    func_0025e9e0(18.0f, stack[1], 0.0f, 0x4972FF, alpha2, 0x1B, iGpffffb540, 1);
                }
                if (i == 5) {
                    func_0025e9e0(18.0f, (171.0f + stack[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1C, iGpffffb540,
                        1);
                }
                if (i == 0x12) {
                    func_0025e9e0((f32)0x24A, stack[1], 0.0f, 0x4972FF, alpha2, 0x1D, iGpffffb540, 1);
                }
                if (i == 0x17) {
                    func_0025e9e0((f32)0x24A, (171.0f + stack[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1E,
                        iGpffffb540, 1);
                }
            }
        }
    }
    if (arg1 >= 2) {
        for (j = 0; j < 6; j++) {
            if (func_002a2ca0((u8 *)&work->rows[j]) == 0) {
                {
                    s32 yBase;
                    u8 *rowBase;
                    i = 0;
                    rowBase = D_007485D0 + (j * 0x28);
                    yBase = (j * 25) + 0xE5;
                    for (; i < 0x14; i++) {
                        character = *(s16 *)(rowBase + (i * 2));
                        if (character >= 0) {
                            s32 tex;
                            tex = character + 0x20;
                            glyphX = (f32)((i % 5) * 0x1B);
                            q = i / 5;
                            switch (q) {
                            case 0:
                                glyphX += 30.0f;
                                break;
                            case 1:
                                glyphX += 178.0f;
                                break;
                            case 2:
                                glyphX += 326.0f;
                                break;
                            case 3:
                                glyphX += 474.0f;
                                break;
                            }
                            rowY = (f32)yBase;
                            glyphY = rowY;
                            func_002a2cd0((u8 *)&work->rows[j]);
                            func_002a2c10((u8 *)&work->rows[j], stack);
                            func_0025e9e0(glyphX, glyphY + (f32)(s32)stack[1], 0.0f, 0x2D2D2D, 0xFF, tex,
                                iGpffffb540, 1);
                        }
                    }
                }
            }
        }
    }
}

#pragma pop
// FUN_002A1A10
s32 func_002a1a10(u8 *arg0) {
    s32 temp_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_16 + 0x10);
    switch (temp_3) {
    case 0:
        iGpffffb52c = 0;
        func_002bb4e0();
        func_002baac0((u8 *)(D_0063E630));
        func_002bad10(1);
        func_002baf40(0);
        func_002bb050(0);
        *(s32 *)(temp_16 + 0x10) = 1;
        goto done;
    case 1:
        if (func_002bb600() != 0) {
            func_002bbcc0();
            if (func_002bb700() == 0) {
                iGpffffb52c = func_002bb0e0();
            }
        } else {
            *(s32 *)(temp_16 + 0x10) = 2;
        }
        goto done;
    case 2:
        func_002bb4e0();
        *(s32 *)(temp_16 + 0x10) = 0;
        return iGpffffb52c;
    default:
        goto done;
    }
done:
    return -1;
}
/* measured: disabling common-subexpression propagation prevents the repeated
   tween target from being held in a saved register across calls. */
#pragma opt_common_subs off
/* measured: disabling propagation preserves the retail call-site materialization. */
#pragma opt_propagation off
// FUN_002A1B20
s32 func_002a1b20(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x178));
        func_002a27c0((s32)(temp_16 + 0x178), 0, 0, 0, 0, fGpffff8204, 0, 10, 20);
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x178);
    if (func_002a2c70(temp_16 + 0x178) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}
/* measured: closes opt_propagation around func_002a1b20. */
#pragma opt_propagation on
/* measured: closes opt_common_subs around func_002a1b20. */
#pragma opt_common_subs on
/* measured: common-subexpression suppression preserves repeated target addresses. */
#pragma opt_common_subs off
/* measured: propagation suppression preserves retail call-site materialization. */
#pragma opt_propagation off
// FUN_002A1BD0
s32 func_002a1bd0(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        func_002a2780((s32)(temp_16 + 0x210));
        {
            s32 target;
            s32 value;

            target = (s32)(temp_16 + 0x210);
            value = 18;
            func_002a27c0(target, value, 249, value, 219, fGpffff8204, 0, 0, 10);
        }
        *(s32 *)(temp_16 + 8) = 1;
    }
    func_002a2980(temp_16 + 0x210);
    if (func_002a2c70(temp_16 + 0x210) != 0) {
        goto fail;
    }
    *(s32 *)(temp_16 + 8) = 0;
    return 1;
fail:
    return 0;
}
/* measured: closes propagation suppression around func_002a1bd0. */
#pragma opt_propagation on
/* measured: closes common-subexpression suppression around func_002a1bd0. */
#pragma opt_common_subs on
/* measured: no_branch_likely preserves retail's ordinary loop branches. */
#pragma no_branch_likely on
/* measured: opt_common_subs off preserves retail per-use index arithmetic. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves retail's global counter loads. */
#pragma opt_propagation off
// FUN_002A1C80
s32 func_002a1c80(u8 *arg0) {
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_17_3;
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_19;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 8) == 0) {
        iGpffffb530 = 0;
        *(s32 *)(temp_16 + 8) = 1;
    }
    if ((iGpffffb530 < 6) && ((*(s32 *)(temp_16 + 0x18) % 6) == 0)) {
        var_17 = 0;
        while (var_17 < 4) {
            temp_18 = temp_16 + ((iGpffffb530 + (var_17 * 6)) * 0x98) + 0x340;
            func_002a2780((s32)temp_18);
            func_002a27c0((s32)temp_18, 0, 0, 0, 0, fGpffff8204, 0, 0, 6);
            var_17++;
        }
        func_002a27c0((s32)(temp_16 + (iGpffffb530 * 0x98) + 0x1180),
                      0, -2, 0, 0, fGpffff8204, 0, 0, 12);
        iGpffffb530++;
    }
    var_17_2 = 0;
    while (var_17_2 < 24) {
        temp_18_2 = temp_16 + (var_17_2 * 0x98) + 0x340;
        if (func_002a2ca0(temp_18_2) == 0) {
            func_002a2980(temp_18_2);
        }
        var_17_2++;
    }
    var_18 = 0;
    var_17_3 = 0;
    while (var_17_3 < 6) {
        if (func_002a2ca0(temp_16 + (var_17_3 * 0x98) + 0x1180) == 0) {
            temp_19 = temp_16 + (var_17_3 * 0x98) + 0x1180;
            func_002a2980(temp_19);
            if (func_002a2c70(temp_19) == 0) {
                var_18++;
            }
        }
        var_17_3++;
    }
    if (var_18 == 6) {
        *(s32 *)(temp_16 + 8) = 0;
        *(s32 *)(temp_16 + 0x18) = 0;
        return 1;
    }
    *(s32 *)(temp_16 + 0x18) += 1;
    return 0;
}
/* measured: closes opt_propagation around func_002a1c80. */
#pragma opt_propagation on
/* measured: closes opt_common_subs around func_002a1c80. */
#pragma opt_common_subs on
/* measured: closes no_branch_likely around func_002a1c80. */
#pragma no_branch_likely off
// FUN_002A1F20
s32 func_002a1f20(u8 *arg0) {
    u8 *temp_2;

    if (*(s32 *)(*(u8 **)(arg0 + 0x38) + 4) != 3) {
        temp_2 = func_00460990();
        *(void (**)(u8 *))(temp_2 + 8) = func_002a1ef0;
        *(u8 **)(temp_2 + 0x10) = arg0;
        func_00460ac0(D_00795E60, temp_2);
        goto success;
    }
    return -1;
success:
    return 0;
}
/* measured: opt_loop_invariants on hoists the case-zero store constant into the
   preheader, matching retail's li $v1 before the loop-entry branch. */
#pragma opt_loop_invariants on
// FUN_002A1FA0
s32 func_002a1fa0(u8 *arg0) {

    u8 colors[4];
    s128 sp40;
    f32 *sp40_ptr;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 var_17;
    s32 var_17_2;
    s32 var_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    sp40_ptr = (f32 *)&sp40;
    sp40 = D_0063E8D0;
    if (iGpffffb540 == 0) {
        return 0;
    }
    colors[0] = 0;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    func_0045d6e0(colors, sp40_ptr, 0.0f, 1);
    temp_5 = *(s32 *)(temp_16 + 4);
    switch (temp_5) {
    case 0:
        func_00122640(1, 1);
        var_4 = 0;
        for (; var_4 < 6; var_4++) {
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C38) = 3;
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C3A) = 0;
        }
        *(s32 *)(temp_16 + 0) = 0;
        *(s32 *)(temp_16 + 0x14) = 0;
        *(s32 *)(temp_16 + 4) = 1;
        goto block_39;
    case 1:
        temp_2_2 = *(s32 *)(temp_16 + 0xC);
        if ((temp_2_2 < 3) && (D_0063E8C0[temp_2_2](arg0, temp_5) == 1)) {
            *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_16 + 0xC) + 1;
        }
        func_002a12e0(arg0, *(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 0xC) >= 3) {
            *(s32 *)(temp_16 + 0xC) = 0;
            *(s32 *)(temp_16 + 8) = 0;
            *(s32 *)(temp_16 + 0x18) = 0;
            *(s32 *)(temp_16 + 0x14) = 1;
            *(s32 *)(temp_16 + 4) = 2;
            *(s32 *)(temp_16 + 0x1C34) = 0;
            func_0029ebf0(arg0, 0);
        }
        goto block_39;
    case 2:
        temp_2_3 = *(s32 *)(temp_16 + 0x14);
        if (temp_2_3 == 1) {
            func_0029f070(arg0);
            temp_3 = *(s32 *)(temp_16 + 0x14);
            if ((temp_3 != 2) && (temp_3 == 3)) {
                *(s32 *)(temp_16 + 8) = 0;
                *(s32 *)(temp_16 + 0x10) = 0;
            }
            goto block_37;
        }
        if (temp_2_3 == 3) {
            if (*(s32 *)(temp_16 + 8) == 0) {
                temp_2_4 = func_002a1a10(arg0);
                if (temp_2_4 == 0) {
                    var_17 = 0xE;
                    goto loop_25_cond;
loop_25_body:
                    *(s8 *)(D_00882EF0 + var_17) = 0;
                    *(s8 *)(D_00882EF0 + var_17 + 1) = 0;
                    var_17 -= 2;
                    if (var_17 < 0) {
                        goto loop_28_init;
                    }
loop_25_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882EF0 + var_17, 2) == 0) {
                        goto loop_25_body;
                    }
loop_28_init:
                    var_17_2 = 0xE;
                    goto loop_28_cond;
loop_28_body:
                    *(s8 *)(D_00882ED0 + var_17_2) = 0;
                    *(s8 *)(D_00882ED0 + var_17_2 + 1) = 0;
                    var_17_2 -= 2;
                    if (var_17_2 < 0) {
                        goto clear_done;
                    }
loop_28_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882ED0 + var_17_2, 2) == 0) {
                        goto loop_28_body;
                    }
clear_done:
                    func_0010d490(D_00882EF0, D_00882ED0);
                    *(s32 *)(temp_16 + 0x18) = 0;
                    *(s32 *)(temp_16 + 8) = 1;
                } else if (temp_2_4 == 1) {
                    *(s32 *)(temp_16 + 0x14) = 1;
                }
                goto block_37;
            }
            if (*(s32 *)(temp_16 + 0x18) == 0) {
                func_00122520(1, 0x1E);
            }
            temp_3_2 = *(s32 *)(temp_16 + 0x18);
            if (temp_3_2 >= 0x1E) {
                *(s32 *)(temp_16 + 0x18) = 0;
                *(s32 *)(temp_16 + 4) = 3;
                goto block_39;
            }
            *(s32 *)(temp_16 + 0x18) = temp_3_2 + 1;
        }
block_37:
        func_002a03b0(arg0);
        goto block_39;
    case 3:
        return -1;
    default:
        goto block_39;
    }
block_39:
    return 0;
}
/* measured: closes opt_loop_invariants around func_002a1fa0. */
#pragma opt_loop_invariants off
// FUN_002A2310
void func_002a2310(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_002A2710
s32 func_002a2710(void) {
    return (s32)(func_00452380(D_0063E918) != 0);
}



// FUN_002A2740
void func_002a2740(void) {
    s32 temp_2;

    if ((temp_2 = func_00452380(D_0063E918)) != 0) {
        func_00452080(temp_2);
    }
}



// FUN_002A2E10
void func_002a2e10(f32 f0, f32 f1, f32 f2, s32 arg0, u8 arg1, s8 * arg2, s32 arg3, s32 arg4, u8 * arg5) {
    s32 value;

    value = arg2[arg3];
    if (value == 0) {
        value = 10;
    }
    func_0025f3f0(f0, f1, f2, arg0, arg1, value, 0, arg5, 1);
}
// FUN_002AA3F0
s32 func_002aa3f0(void) {
    s32 r;

    if (func_00452380(&D_00763918) == 0) {
        r = (D_00764634 != 0) ? 1 : 2;
    } else {
        r = 0;
    }
    return r;
}

// FUN_002AA450
void func_002aa450(void) {
    s64 bits;
    s32 *state;
    u8 *source;
    P4_002aa450_Work work;
    f32 phase;
    f32 offset;
    f32 ratio;
    f32 angle;
    f32 value;
    f32 scale;
    f32 color_x;
    f32 color_y;
    s32 color_value;
    s32 temp;

    state = (s32 *)D_00882F20;
    bits = *(s64 *)D_0063EDF0;
    value = *(f32 *)D_0063EDF8;
    work.pair0.bits = bits;
    work.pair0.value = value;
    bits = *(s64 *)D_0063EE00;
    value = *(f32 *)D_0063EE08;
    work.pair1.bits = bits;
    work.pair1.value = value;
    bits = *(s64 *)D_0063EE10;
    value = *(f32 *)D_0063EE18;
    work.pair2.bits = bits;
    work.pair2.value = value;
    bits = *(s64 *)D_0063EE20;
    value = *(f32 *)D_0063EE28;
    work.pair3.bits = bits;
    work.pair3.value = value;
    source = D_0063EE30;
    bits = *(s64 *)source;
    source = D_0063EE38;
    value = *(f32 *)source;
    work.pair4.bits = bits;
    work.pair4.value = value;
    ratio = (f32)(*(s32 *)D_00882F2C) / 5.0f;
    bits = *(s32 *)D_00882F28;
    temp = (s32)bits + 1;
    *(s32 *)D_00882F28 = temp;
    if (temp >= 0x3C) {
        state[2] = 0;
    }
    phase = (f32)state[2] / 60.0f;
    scale = 10.0f;
    offset = 1.0f - ratio;
    offset = p4_002aa450_mul(scale, offset);
    offset = -80.0f - offset;
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    func_003e4320(&work.pair3, &work.pair3, work.matrix);
    angle = 360.0f * phase;
    RwMatrixRotate(work.matrix, &work.pair3, angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    color_x = (f32)0x1A3;
    color_y = (f32)0x242;
    color_value = 397;
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 120.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFFFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 240.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF0000, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair1, fGpffff855c, 0);
    RwMatrixRotate(work.matrix, &work.pair2, 357.0f * phase + 3.0f, 2);
    ((f32 *)&work.pair4)[0] *= ratio;
    ((f32 *)&work.pair4)[1] *= ratio;
    ((f32 *)&work.pair4)[2] *= ratio;
    RwMatrixScale(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)(color_value - ratio * 2.0f), 0.0f, 0x22, 0x2C,
                  0xE6E6E6, 0xFF, 1, 0x11, 0x16,
                  (const struct RwMatrixTag *)work.matrix, 0);
}
// FUN_002AA890
s32 func_002aa890(u8 *arg0) {
    s32 *state;
    u8 *temp_2;

    state = D_00882F20;
    switch (state[1]) {
    case 0:
        state[1] = 1;
    case 1:
        if ((state[0] & 1) != 0) {
            state[1] = 3;
        }
        break;
    case 3:
        state[1] = 4;
        state[2] = 0;
        state[0] |= 2;
    case 4:
        if ((state[0] & 1) == 0) {
            state[0] |= 4;
        }
        if ((state[0] & 2) != 0) {
            if (state[3] < 5) {
                state[3]++;
            } else {
                state[0] &= ~2;
            }
        } else if ((state[0] & 4) != 0) {
            if (state[3] > 0) {
                state[3]--;
            } else {
                state[0] &= ~4;
                state[1] = 1;
            }
        }
        temp_2 = func_00460990();
        *(void **)(temp_2 + 8) = (void *)func_002aa450;
        *(u8 **)(temp_2 + 0x10) = arg0;
        func_00460ac0(D_007966A0, temp_2);
        break;
    }
    return 0;
}
// FUN_002AAA00
void func_002aaa00(u8 *unusedTask)
{
}

// FUN_002AAA10
void func_002aaa10(void) {
    memset(D_00882F20, 0, 0x10);
    (s32)func_00451fc0((void *)(NULL), (const void *)(D_0063EE40), 0xF, 0, 0, func_002aa890, func_002aaa00, (u8 *)(NULL));
}

// FUN_002AAA80
void func_002aaa80(void) {
    D_00882F20[0] |= 1;
}
// FUN_002AAAA0
void func_002aaaa0(void) {
    D_00882F20[0] &= ~1;
}


/* measured: opt_propagation off keeps the D_00887300 base in $s0 and
   reloads the dispatch target before each call, as in retail. */
#pragma opt_propagation off
// FUN_002AAAC0
void func_002aaac0(void) {
    void (**base)(s32 arg0, s32 arg1);

    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
}
/* measured: closes the opt_propagation bracket for func_002aaac0. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves the cached dispatch base and retail call-site order. */
#pragma opt_propagation off
// FUN_002AABF0
void func_002aabf0(void *arg0, u8 *arg1) {
    P4_002aabf0_Work work;
    u8 *ptr;
    void (**base)(s32 arg0, s32 arg1);
    f32 temp_f20;
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    u8 temp_6;
    u8 temp_7;
    u8 temp_8;
    u8 temp_9;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    ptr = arg1;
    temp_6 = ptr[0x14];
    temp_7 = ptr[0x15];
    temp_8 = ptr[0x16];
    temp_9 = ptr[0x17];
    work.colors[0] = temp_6;
    work.colors[1] = temp_7;
    work.colors[2] = temp_8;
    work.colors[3] = temp_9;
    temp_f3 = *(f32 *)(ptr + 0);
    temp_f2 = *(f32 *)(ptr + 4);
    temp_f1 = *(f32 *)(ptr + 8);
    temp_f0 = *(f32 *)(ptr + 0xC);
    work.values[0] = temp_f3;
    work.values[1] = temp_f2;
    work.values[2] = temp_f1;
    work.values[3] = temp_f0;
    temp_f20 = *(f32 *)(ptr + 0x10);
    temp_19 = *(s32 *)(ptr + 0x18);
    temp_18 = temp_19 & 0x100;
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    temp_17 = temp_19 & 0x200;
    if (temp_17 != 0) {
        func_003f6690(2, &work.sp84);
    }
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
    if (temp_18 != 0) {
        RpSkyRenderStateSet(3, work.sp88);
    }
    if (temp_17 != 0) {
        RpSkyRenderStateSet(2, work.sp84);
    }
    if (temp_19 & 1) {
        base[0](6, 1);
    }
    if (temp_19 & 2) {
        base[0](8, 1);
    }
    if (temp_19 & 4) {
        RpSkyRenderStateSet(3, 0x5000D);
    }
    if (temp_19 & 8) {
        RpSkyRenderStateSet(2, 0x54);
    }
    if (temp_19 & 0x20) {
        RpSkyRenderStateSet(2, 0x58);
    }
    temp_17_2 = temp_19 & 0x40;
    if (temp_17_2 != 0) {
        func_00364c50();
    }
    temp_16 = temp_19 & 0x10;
    if (temp_16 != 0) {
        func_00489f80();
    }
    func_0045d6e0(work.colors, work.values, temp_f20, 0);
    if (temp_16 != 0) {
        func_0048a000();
    }
    if (temp_17_2 != 0) {
        func_00364c70();
    }
    jtbl_008873EC[0](ptr);
}
/* measured: closes opt_propagation around func_002aabf0. */
#pragma opt_propagation on
// FUN_002ABF70
s32 func_002abf70(u8 *arg0) {
    s32 temp_3;
    s8 temp_4;
    u8 *temp_16;
    void *temp_17;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s8 *)(temp_16 + 0);
    switch (temp_4) {
    case 0:
    case 1:
    case 2:
    case 3:
        *(s8 *)(temp_16 + 0) = temp_4 + 1;
        break;
    case 4:
        temp_f0 = 100.0f;
        temp_f1 = 156.0f;
        temp_f2 = 1.0f;
        temp_17 = (void *)*(s32 *)(D_0063EEA0 +
                                   (*(s32 *)(temp_16 + 0x6C0) * 4));
        func_00274ed0(temp_f0, temp_f1, temp_f2,
                      -1, 0, 0, temp_17, 0, 0);
        if (D_008C027A[0] & 0x8000) {
            *(s32 *)(temp_16 + 0x6C0) =
                func_002b2cb0(*(s32 *)(temp_16 + 0x6C0), 1, 3, 0, 1);
        } else if (D_008C027A[0] & 0x2000) {
            *(s32 *)(temp_16 + 0x6C0) =
                func_002b2d00(*(s32 *)(temp_16 + 0x6C0), 1, 0, 3, 1);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            temp_3 = *(s32 *)(temp_16 + 0x6C0);
            switch (temp_3) {
            case 0:
                *(s32 *)(temp_16 + 0x6C8) = func_002bdb50((s32)arg0, 0);
                break;
            case 1:
                *(s32 *)(temp_16 + 0x6C8) = func_002e7510((s32)arg0);
                break;
            case 2:
                iGpffffb54c = 0;
                *(s32 *)(temp_16 + 0x6C8) = func_00311260(arg0);
                break;
            case 3:
                *(s32 *)(temp_16 + 0x6C8) = func_003493b0(arg0);
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x10) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            switch (*(s32 *)(temp_16 + 0x6C0)) {
            case 2:
                iGpffffb54c = 1;
                *(s32 *)(temp_16 + 0x6C8) = func_00311260(arg0);
                break;
            default:
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x80) {
            func_0045af60(0, 0, 0, 0xA);
        }
        break;
    case 5:
        if (iGpffffb54c == 1) {
            temp_f0 = 20.0f;
            temp_f2 = 1.0f;
            temp_f1 = temp_f0;
            func_00274ed0(temp_f0, temp_f1, temp_f2,
                          (s32)0x808080FF, 0, 2,
                          (void *)D_0063EEB0, 0, 0);
        }
        if (func_00452490(*(s32 *)(temp_16 + 0x6C8)) == 0) {
            *(s8 *)(temp_16 + 0) = 0;
            func_002bdea0();
            func_00308f40();
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// FUN_002AC270
void func_002ac270(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002AC2A0
void func_002ac2a0(void) {
    u8 *p;

    func_0044ea90(D_0063EEC0, 0x4B9);
    p = D_008873F4[0](1, 0x4D78, 0x40000);
    (s32)func_00451de0((const void *)(D_0063EED0), 0xF, 0, 0, func_002abf70, func_002ac270, (u8 *)(p));
    *(u8 *)(p + 0) = 0;
    *(s32 *)(p + 0x6B4) = 0x3F800000;
    *(s16 *)(p + 0x6B8) = 0x1F;
    *(s16 *)(p + 0x6BA) = 0;
    *(s8 *)(p + 0x6BC) = 1;
    *(s8 *)(p + 0x6BD) = 1;
    *(s32 *)(p + 0x6C0) = 0;
}
// FUN_002AC360
void func_002ac360(void) {
    s16 i;

    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
}
// FUN_002AC3B0
u32 func_002ac3b0(void) {
    return (u32)D_00764658;
}
// FUN_002AC3C0
s64 func_002ac3c0(s32 arg0, s32 arg1) {
    s32 temp;

    temp = arg0 & 0xff;
    return (s8)(((1 << temp) & 0xffff & D_00764658[arg1 & 0xff]) >> temp);
}
