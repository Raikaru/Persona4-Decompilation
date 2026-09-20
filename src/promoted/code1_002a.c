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
extern void func_0043f9c8(void *dst, s32 value, u32 size);

extern s32 func_002aa890(u8 *arg0);
extern void func_002aa450(void);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 func_002abf70(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_003f6690(s32 arg0, s32 *arg1);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025f3f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         u8 *arg4, s32 arg5, f32 farg0, f32 farg1,
                         f32 farg2);
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
extern void func_0025e9e0(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, f32 farg0, f32 farg1, f32 farg2);
extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg3, f32 farg4, f32 farg5);
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
extern void func_003e0870(void *arg0, void *arg1, f32 farg0, s32 arg2);
extern void func_003e0a90(void *arg0, void *arg1, s32 arg2);
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
extern s32 func_00442c30(void *arg0, void *arg1, s32 arg2);



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
/* Floor for func_002a03b0 (retail 3888B/971 instrs @0x002A03B0, window 3888B).
   Candidate (modernized Lane0041_002a_002a03b0_body.c:156-414, 259-line range only; other FUNs untouched):
   3864B emitted / 3888B window (24B short), fnalign 966/971 instrs (5 short, 0.5% gap, within ~3%),
   278 edit instrs +40 reloc-only, probe 876 differing words. Production guarded to ASM (0 MISMATCH overall).
   Modernization vs archived snapshot (required for compile, not tuning): honest e9e0 ints-first
   (s32,s32,s32,void*,s32,f32,f32,f32 per code1_0025, 28 calls translated from floats-first),
   iGpffffb540 for gp-0x4AC0, iGpffffb538 (was *(s32*)0x0 null deref) for gp-0x4AC8 UI index,
   iGpffffb528 buffer for gp-0x4AD8 string path, inside-function externs for 274ed0/442de8/442948/29f790
   (file-scope lacks them; inside keeps edit inside function per batch discipline).
   7o exchange probes on tail s2/s3 pair (var_18_3/var_19 + var_18_4/var_19_2, bare decls + statement assigns
   already in 7o form): func/block x decl-retail/decl-reverse x assign-retail/assign-reverse = 8 probes,
   all 876 ties (F_R_R 876, F_R_V 876, F_V_R 876, F_V_V 876, B_R_R 876, B_R_V 876, B_V_R 876, B_V_V 876).
   Reversal never improves here; residual is pervasive (float-conv shapes, slti-at vs slti-v0, s2/s4 + FPR
   colour, gp-lui vs gp-addiu for undefined b528 buffer) not a single exchange. Next: argument-setup order
   and conversion-register levers top-down per 7a-bis/7a-quinquies, not declaration permutation. */
/* 2026-09-19: frame -0xa0 exact (addiu sp,sp,-0xa0 both sides). Lui audit retail 90 vs object 94 (+4 surplus): retail {0xc140:1, 0x75:1, 0x88:6 + floats} vs object {0x4140:1, 0:11 + same floats}; surplus is symbols, not floats	D_007485D0 base (retail lui 0x75+addiu -0x7a30 at 0x2A0FA8 vs object lui 0 at obj@757) + 4x iGpffffb528 buffer (retail addiu gp,-0x4AD8 1 instr at 0x2A117C/0x2A11AC/0x2A123C/0x2A126C vs object lui 0+addiu 0 2 instrs). Float 0xc140 (retail -12.0f add at 0x2A0F54) vs 0x4140 (object +12.0f sub) is colour, not surplus. Counts fnalign 966 vs 971 (-5, -0.5%), words 876, edits 278 +40 reloc. Deletes 19 tot 34 (largest 22 vs 4 at 766:788 tail D_007485D0/div + 17 vs 3 at 762:765, rest 1-3 mov.s/lwc1/nop FPR spills at 0x2A03EC,0x2A0524,0x2A0538,0x2A0570,0x2A061C,0x2A068C,0x2A06C8,0x2A0704,0x2A0730,0x2A0920,0x2A0AFC,0x2A0B38,0x2A0BD4,0x2A0C80,0x2A0CEC,0x2A0D28,0x2A0DC4,0x2A0E74,0x2A1110); inserts 17 tot 26. No single missing arm; residual pervasive per prior note. No code change this round (before=after); fixing buffer gp-lui would save 4 but push count 966->962 (-9), so left. */
// FUN_002A03B0 NONMATCHING
#ifdef NON_MATCHING
void func_002a03b0(u8 *arg0) {
    extern u8 iGpffffb528[];
    extern s32 iGpffffb538;
    extern s32 func_0029f790(u8 *arg0);
    extern s32 func_00442948(const void *arg0);
    extern void func_00442de8(void *arg0, const void *arg1, s32 arg2);
    extern s32 func_00274ed0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7, s32 arg8);
    f32 sp9c;
    f32 sp98;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f12;
    f32 var_f2;
    s16 temp_2_2;
    s32 temp_18_2;
    s32 temp_20_3;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 var_16;
    s32 var_16_2;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_20;
    s32 var_20_2;
    s32 var_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    u32 temp_16;
    u32 temp_16_2;
    u32 var_19;
    u32 var_19_2;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u8 *temp_20_2;
    s32 sum;

    temp_19 = *(u8 **)(arg0 + 0x38);
    func_0025e9e0(0xFFFFFF, 0xFF, 0xA4, iGpffffb540, 1, 0.0f, 0.0f, 0.0f);
    temp_2 = *(s32 *)(temp_19 + 0x1C68) + 1;
    *(s32 *)(temp_19 + 0x1C68) = temp_2;
    if (temp_2 >= 0x5A1) {
        *(s32 *)(temp_19 + 0x1C68) = 0;
    }
    func_0025ea20(-78.0f, -82.0f, 0.0f, 0x4972FF, 0xFF, 0xB1,
                  iGpffffb540, 1, 0x5B, 0x5B,
                  (f32)(*(s32 *)(temp_19 + 0x1C68) * -0x168) / 1440.0f,
                  1.0f, 1.0f);
    func_0025ea20(540.0f, 347.0f, 0.0f, 0x4972FF, 0xFF, 0xB1,
                  iGpffffb540, 1, 0x5B, 0x15B,
                  (f32)(*(s32 *)(temp_19 + 0x1C68) * -0x168) / 1440.0f,
                  1.0f, 1.0f);
    func_0025e9e0(0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1, 0.0f, 0.0f, 0.0f);
    func_0025e9e0(0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1, 0.0f, 346.0f, 0.0f);
    func_002a2980(temp_19 + 0x2A8);
    temp_f1 = 255.0f * func_002a2cd0(temp_19 + 0x2A8);
    if (!(temp_f1 >= 2.1474836e9f)) {
        var_3 = 0x4F000000 & 0xFF;
    } else {
        var_3 = ((s32)(temp_f1 - 2.1474836e9f) | 0x80000000) & 0xFF;
    }
    var_16 = var_3 & 0xFF;
    func_002a2c10(temp_19 + 0x2A8, &sp98);
    temp_3 = *(s32 *)(temp_19 + 0x1C34);
    switch (temp_3) {
    case 0:
        var_20 = var_16 & 0xFF;
        var_18 = 0;
        break;
    case 1:
        var_18 = var_16 & 0xFF;
        var_20 = ((0xFF - var_18) >> 2) & 0xFF;
        break;
    case 2:
        var_20 = var_16 & 0xFF;
        var_18 = ((0xFF - var_20) >> 2) & 0xFF;
        break;
    }
    func_0025e9e0(0xFFFFFF, var_20, 0x13, iGpffffb540, 1, sp98, sp9c, 0.0f);
    temp_f20 = 105.0f + sp98;
    func_0025e9e0(0xFFFFFF, var_20, 0x11, iGpffffb540, 1, temp_f20, sp9c, 0.0f);
    temp_f21 = sp9c + 3.0f;
    func_0025e9e0(0xFFFFFF, var_18, 0x13, iGpffffb540, 1, sp98, temp_f21, 0.0f);
    func_0025e9e0(0xFFFFFF, var_18, 0x12, iGpffffb540, 1, temp_f20, temp_f21, 0.0f);
    func_002a02f0(arg0, 0);
    if (*(s32 *)(temp_19 + 0x1C34) != 0) {
        var_16 = 0xFF;
    }
    temp_18 = *(u8 **)(arg0 + 0x38);
    func_0025e9e0(0x4972FF, var_16, 0x17, iGpffffb540, 1, 229.0f, 150.0f, 0.0f);
    func_0025e9e0(0x4972FF, var_16, 0x17, iGpffffb540, 1, 229.0f, 182.0f, 0.0f);
    if (*(s32 *)(temp_18 + 0x14) != 3) {
        temp_3_2 = iGpffffb538;
        if (temp_3_2 < 8) {
            var_3_2 = (temp_3_2 * 0x1C) + 0xE3;
            var_2 = 0x97;
        } else {
            var_3_2 = ((temp_3_2 - 8) * 0x1C) + 0xE3;
            var_2 = 0xB7;
        }
        func_0025e9e0(0xCCFF33, var_16, 0x18, iGpffffb540, 1, (f32)var_3_2, (f32)var_2, 0.0f);
    }
    func_002a2cd0(temp_19 + 0x210);
    func_002a2c10(temp_19 + 0x210, &sp98);
    temp_18_2 = *(s32 *)(temp_19 + 0x24) / 5;
    temp_21 = *(s32 *)(temp_19 + 0x30) / 5;
    temp_22 = *(s32 *)(temp_19 + 0x3C) / 5;
    var_16_2 = 0;
    while (var_16_2 < 0x18) {
        temp_f21_2 = (f32)(((var_16_2 / 6) * 0x94) + 0x19);
        temp_f20_2 = (f32)(((var_16_2 % 6) * 0x19) + 0xE3);
        func_0025e9e0(0x4972FF, 0xFF, 1, iGpffffb540, 1, temp_f21_2, temp_f20_2, 0.0f);
        if (var_16_2 == 0) {
            func_0025e9e0(0x4972FF, 0xFF, 0x1B, iGpffffb540, 1, 18.0f, 219.0f, 0.0f);
        }
        if (var_16_2 == 5) {
            func_0025e9e0(0x4972FF, 0xFF, 0x1C, iGpffffb540, 1, 18.0f, 366.0f, 0.0f);
        }
        if (var_16_2 == 0x12) {
            func_0025e9e0(0x4972FF, 0xFF, 0x1D, iGpffffb540, 1, (f32)0x24A, 219.0f, 0.0f);
        }
        if (var_16_2 == 0x17) {
            func_0025e9e0(0x4972FF, 0xFF, 0x1E, iGpffffb540, 1, (f32)0x24A, 366.0f, 0.0f);
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
                func_0025e9e0(0x49AFFD, 0xFF, 1, iGpffffb540, 1, temp_f21_2, temp_f20_2, 0.0f);
                if (var_16_2 == 0) {
                    func_0025e9e0(0x49AFFD, 0xFF, 0x1B, iGpffffb540, 1, 18.0f, sp9c, 0.0f);
                }
                if (var_16_2 == 5) {
                    func_0025e9e0(0x49AFFD, 0xFF, 0x1C, iGpffffb540, 1, 18.0f, (171.0f + sp9c) - 24.0f, 0.0f);
                }
                if (var_16_2 == 0x12) {
                    func_0025e9e0(0x49AFFD, 0xFF, 0x1D, iGpffffb540, 1, (f32)0x24A, sp9c, 0.0f);
                }
                if (var_16_2 == 0x17) {
                    func_0025e9e0(0x49AFFD, 0xFF, 0x1E, iGpffffb540, 1, (f32)0x24A, (171.0f + sp9c) - 24.0f, 0.0f);
                }
            } else if (func_002a2c70(temp_20_2) != 0) {
                temp_f1_2 = 255.0f * (1.0f - func_002a2cd0(temp_20_2));
                if (!(temp_f1_2 >= 2.1474836e9f)) {
                    var_3_3 = 0x4F000000 & 0xFF;
                } else {
                    var_3_3 = ((s32)(temp_f1_2 - 2.1474836e9f) | 0x80000000) & 0xFF;
                }
                temp_20_3 = var_3_3 & 0xFF;
                func_0025e9e0(0x49AFFD, temp_20_3, 1, iGpffffb540, 1, temp_f21_2, temp_f20_2, 0.0f);
                if (var_16_2 == 0) {
                    func_0025e9e0(0x49AFFD, temp_20_3, 0x1B, iGpffffb540, 1, 18.0f, sp9c, 0.0f);
                }
                if (var_16_2 == 5) {
                    func_0025e9e0(0x49AFFD, temp_20_3, 0x1C, iGpffffb540, 1, 18.0f, (171.0f + sp9c) - 24.0f, 0.0f);
                }
                if (var_16_2 == 0x12) {
                    func_0025e9e0(0x49AFFD, temp_20_3, 0x1D, iGpffffb540, 1, (f32)0x24A, sp9c, 0.0f);
                }
                if (var_16_2 == 0x17) {
                    func_0025e9e0(0x49AFFD, temp_20_3, 0x1E, iGpffffb540, 1, (f32)0x24A, (171.0f + sp9c) - 24.0f, 0.0f);
                }
            }
        }
        var_16_2 += 1;
    }
    func_0029f790(arg0);
    if (*(s32 *)(temp_19 + 0x14) != 3) {
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
        func_0025e9e0(0xCCFF33, 0xFF, 0xF, iGpffffb540, 1, var_f2 - 12.0f, (f32)((*(s32 *)(temp_19 + 0x20) * 0x19) + 0xE5) - 12.0f, 0.0f);
    }
    var_20_2 = 0;
    while (var_20_2 < 6) {
        var_18_2 = 0;
        while (var_18_2 < 0x14) {
            temp_2_2 = *(s16 *)(D_007485D0 + (var_20_2 * 0x28) + (var_18_2 * 2));
            if (temp_2_2 >= 0) {
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
                func_0025e9e0(0x2D2D2D, 0xFF, temp_2_2 + 0x20, iGpffffb540, 1, var_f12, (f32)((var_20_2 * 0x19) + 0xE5), 0.0f);
            }
            var_18_2 += 1;
        }
        var_20_2 += 1;
    }
    if ((*(s32 *)(temp_19 + 0x14) == 3) &&
        (*(s32 *)(temp_19 + 8) == 0)) {
        func_0025e9e0(0xFFFFFF, 0xFF, 0xAC, iGpffffb540, 1, 0.0f, 102.0f, 0.0f);
    }
    if ((func_00442948(D_00882EF0) >> 1) != 0) {
        temp_16 = (u32)(func_00442948(D_00882EF0) >> 1);
        var_18_3 = 0xE7;
        var_19 = 0;
        sum = 0;
        while (var_19 < temp_16) {
            func_00442de8(iGpffffb528, D_00882EF0 + (var_19 * 2), 2);
            sum += func_00274ed0((f32)var_18_3, 121.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            var_18_3 += 0x1C;
            var_19 += 1;
        }
    }
    if ((func_00442948(D_00882ED0) >> 1) != 0) {
        temp_16_2 = (u32)(func_00442948(D_00882ED0) >> 1);
        var_18_4 = 0xE7;
        var_19_2 = 0;
        sum = 0;
        while (var_19_2 < temp_16_2) {
            func_00442de8(iGpffffb528, D_00882ED0 + (var_19_2 * 2), 2);
            sum += func_00274ed0((f32)var_18_4, 153.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            var_18_4 += 0x1C;
            var_19_2 += 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a03b0);
#endif
/* Floor for func_002a12e0 (retail 1840B/456 instrs @0x002A12E0, window 1840B).
   Candidate (this C body, measured via probe splice): 1780B emitted / 1840B window (60B short),
   fnalign 445/456 instrs (11 short, 2.4% gap, within ~3%), 190 edit instrs +6 reloc-only,
   verify nd1213 as live C (MISMATCH). Production guarded to ASM (0 MISMATCH overall).
   Frame and saves match retail with measured propagation-off: 0xA0 frame, sq s0-s6 + swc1 f20/f21
   (baseline without pragma was 0x90 with 6+1 saves). yBase integer hoisted to s6 and rowBase to s5
   (D_007485D0 + j*0x28, yBase=j*25+0xE5 sharing 5*j, matching retail's sll/addu CSE) closed the
   frame; var_f20/var_f21 (x=27*(k%5)+{30,178,326,474}, y=(f32)yBase) kept in f20/f21 across the
   2cd0/2c10 calls. Honest decls per code1_0025 definitions: e9e0 ints-first
   (s32,s32,s32,void*,s32,f32,f32,f32), ea20 floats-first
   (f32,f32,f32,s32,s32,s32,void*,s32,s32,s32,f32,f32,f32), 2cd0 f32(u8*), 2c10 s32(u8*,f32*),
   D_007485D0 u8[] with s16 loads (lh, matching retail), alpha s32 with (u8)(255.0f*ret) (andi
   double-mask as retail), stack f32[2] at 0x98 (lwc1 0x9C for second float, matching retail),
   iGpffffb540 for the gp-0x4AC0 slot (0x00764630, per symbol_data_addrs).
   Levers measured and banked (all quoted from verify/fnalign on this TU, b210 -O2):
   - baseline prop-off only 1780B nd1213 (frame 0xA0, 7+2 saves) vs no-pragma 1800B nd1415 (0x90, 6+1 saves).
   - targeted opt_loop_invariants on immediately before for(i)/for(j)/for(k) each 1788B nd1232
     (+8B, +19 nd vs baseline), regressed, removed (parent 0028fc40 lever, negative here).
   - declaration-order temp_16 first vs last identical 1780B nd1213 (dead locals dropped, no effect).
   - floats-first e9e0 decl+calls 1792B nd1192 (-21 nd, +12B) but mismatches e9e0 definition
     (ints-first per code1_0025), rejected as dishonest; ea20 floats-first honest, no size/nd change.
   - second parent lever (cast at call site moves load): audited all e9e0/ea20 trailing args;
     no removable casts (int->float (f32) for 148*(i/6)+25 etc, (f32)0x24A for 586 via addiu+cvt
     not lui, trunc+cvt (f32)(s32)stack[1] for second float, all necessary for retail's cvt/trunc
     shapes); bare-vs-cast staging not applicable, schedule-off not tried (parent measured 2->120 worse).
   Wall (banked, not ground): pervasive $s/$f colour permutation (temp_16 s2 vs s0, arg0 s4 vs s2,
   arg1 s0 vs s3, alpha s3 vs s1) and e9e0/ea20 argument-setup order (object ints luis/moves before
   float mtc1/movs, retail floats mtc1/nop/movs before ints luis, 5+ sites, ~100 edits). Home-move
   block order itself is identical (arg0, arg1, temp_16) so per parent the ORDER is a wall (invariant
   under decl/initialiser/assignment/K&R/copy models, all identical); the remaining colour part is
   a search wall at 190 edits. Archive probe body is this file's NON_MATCHING arm (measured, not stale).
   Emitted 445/456 instrs satisfies assignment ~3% gate (2.4% short) for a guarded floor. */
#pragma opt_propagation off
/* measured: object 1792B/window 1840B/normalized_diff 1226 (379 differing words, live re-measured current tree). */
/* measured: inclusive <=0x5A0 with redundant-store dead-arm keeps slti-at (fnalign 143 to 142, slti-at vs slti-v0 fixed) and reaches floor size (1792 vs 1840, 2pt short); net words 375 to 379 and nd1213 to 1226 due to branch shape; arg-setup and loop-invariant to follow top-down. */
// FUN_002A12E0 NONMATCHING
#ifdef NON_MATCHING
void func_002a12e0(u8 *arg0, s32 arg1) {
    u8 *temp_16;
    u8 *loop_ptr;
    u8 *row_ptr;
    f32 stack[2];
    f32 var_f21;
    f32 var_f20;
    s32 alpha;
    s32 alpha2;
    s32 i;
    s32 j;
    s32 k;
    s32 cnt;
    s32 q;
    s16 table_val;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((arg1 >= 0) && (func_002a2ca0(temp_16 + 0x178) == 0)) {
        alpha = (u8)(255.0f * func_002a2cd0(temp_16 + 0x178));
        func_0025e9e0(0xFFFFFF, alpha, 0xA4, iGpffffb540, 1, 0.0f, 0.0f, 0.0f);
        cnt = *(s32 *)(temp_16 + 0x1C68) + 1;
        *(s32 *)(temp_16 + 0x1C68) = cnt;
        if (cnt <= 0x5A0) {
            *(s32 *)(temp_16 + 0x1C68) = cnt;
        } else {
            *(s32 *)(temp_16 + 0x1C68) = 0;
        }
        func_0025ea20(-78.0f, -82.0f, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(*(s32 *)(temp_16 + 0x1C68) * -0x168) / 1440.0f, 1.0f, 1.0f);
        func_0025ea20(540.0f, (f32)0x15B, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(*(s32 *)(temp_16 + 0x1C68) * -0x168) / 1440.0f, 1.0f, 1.0f);
        func_0025e9e0(0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1, 0.0f, 0.0f, 0.0f);
        func_0025e9e0(0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1, 0.0f, 346.0f, 0.0f);
    }
    if (arg1 > 0) {
        func_002a02f0(arg0, 1);
        if (func_002a2ca0(temp_16 + 0x210) == 0) {
            func_002a2c10(temp_16 + 0x210, stack);
            func_002a2cd0(temp_16 + 0x210);
        }
    }
    if (arg1 >= 2) {
        for (i = 0; i < 0x18; i++) {
            loop_ptr = temp_16 + (i * 0x98) + 0x340;
            if (func_002a2ca0(loop_ptr) == 0) {
                alpha2 = (u8)(255.0f * func_002a2cd0(loop_ptr));
                func_0025e9e0(0x4972FF, alpha2, 1, iGpffffb540, 1, (f32)((i / 6) * 0x94 + 0x19), (f32)((i % 6) * 0x19 + 0xE3), 0.0f);
                if (i == 0) {
                    func_0025e9e0(0x4972FF, alpha2, 0x1B, iGpffffb540, 1, 18.0f, stack[1], 0.0f);
                }
                if (i == 5) {
                    func_0025e9e0(0x4972FF, alpha2, 0x1C, iGpffffb540, 1, 18.0f, (171.0f + stack[1]) - 24.0f, 0.0f);
                }
                if (i == 0x12) {
                    func_0025e9e0(0x4972FF, alpha2, 0x1D, iGpffffb540, 1, (f32)0x24A, stack[1], 0.0f);
                }
                if (i == 0x17) {
                    func_0025e9e0(0x4972FF, alpha2, 0x1E, iGpffffb540, 1, (f32)0x24A, (171.0f + stack[1]) - 24.0f, 0.0f);
                }
            }
        }
    }
    if (arg1 >= 2) {
        for (j = 0; j < 6; j++) {
            row_ptr = temp_16 + (j * 0x98);
            if (func_002a2ca0(row_ptr + 0x1180) == 0) {
                {
                    s32 yBase;
                    u8 *rowBase;
                    yBase = (j * 25) + 0xE5;
                    rowBase = D_007485D0 + (j * 0x28);
                    for (k = 0; k < 0x14; k++) {
                        table_val = *(s16 *)(rowBase + (k * 2));
                        if (table_val >= 0) {
                            var_f21 = (f32)((k % 5) * 0x1B);
                            q = k / 5;
                            switch (q) {
                            case 0:
                                var_f21 += 30.0f;
                                break;
                            case 1:
                                var_f21 += 178.0f;
                                break;
                            case 2:
                                var_f21 += 326.0f;
                                break;
                            case 3:
                                var_f21 += 474.0f;
                                break;
                            }
                            var_f20 = (f32)yBase;
                            func_002a2cd0(row_ptr + 0x1180);
                            func_002a2c10(row_ptr + 0x1180, stack);
                            func_0025e9e0(0x2D2D2D, 0xFF, table_val + 0x20, iGpffffb540, 1, var_f21, var_f20 + (f32)(s32)stack[1], 0.0f);
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_002a", func_002a12e0);
#endif
/* measured: closes propagation around func_002a12e0 (see floor note). */
#pragma opt_propagation on
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
                    if (func_00442c30(&iGpffffa7e8,
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
                    if (func_00442c30(&iGpffffa7e8,
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
void func_002a2e10(f32 f0, f32 f1, f32 f2, s32 arg0, s32 arg1,
                   s8 *arg2, s32 arg3, s32 arg4, u8 *arg5) {
    s32 value;

    value = arg2[arg3];
    if (value == 0) {
        value = 10;
    }
    func_0025f3f0(arg0, arg1, value, 0, arg5, 1, f0, f1, f2);
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
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e4320(&work.pair3, &work.pair3, work.matrix);
    angle = 360.0f * phase;
    func_003e0870(work.matrix, &work.pair3, angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    color_x = (f32)0x1A3;
    color_y = (f32)0x242;
    color_value = 397;
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e0870(work.matrix, &work.pair3, 120.0f + angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFFFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    func_003e0870(work.matrix, &work.pair0, offset, 0);
    func_003e0870(work.matrix, &work.pair3, 240.0f + angle, 2);
    func_003e0a90(work.matrix, &work.pair4, 2);
    func_00366960((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF0000, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    func_003e0870(work.matrix, &work.pair1, fGpffff855c, 0);
    func_003e0870(work.matrix, &work.pair2, 357.0f * phase + 3.0f, 2);
    ((f32 *)&work.pair4)[0] *= ratio;
    ((f32 *)&work.pair4)[1] *= ratio;
    ((f32 *)&work.pair4)[2] *= ratio;
    func_003e0a90(work.matrix, &work.pair4, 2);
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
    func_0043f9c8(D_00882F20, 0, 0x10);
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
    func_003f6440(3, 0x50003);
    func_003f6440(2, 0x44);
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
    func_003f6440(3, 0x50003);
    func_003f6440(2, 0x44);
    base[0](1, 0);
    if (temp_18 != 0) {
        func_003f6440(3, work.sp88);
    }
    if (temp_17 != 0) {
        func_003f6440(2, work.sp84);
    }
    if (temp_19 & 1) {
        base[0](6, 1);
    }
    if (temp_19 & 2) {
        base[0](8, 1);
    }
    if (temp_19 & 4) {
        func_003f6440(3, 0x5000D);
    }
    if (temp_19 & 8) {
        func_003f6440(2, 0x54);
    }
    if (temp_19 & 0x20) {
        func_003f6440(2, 0x58);
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
