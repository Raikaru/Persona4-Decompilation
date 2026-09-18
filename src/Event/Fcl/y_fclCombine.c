/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;

typedef struct {
    f32 x;
    f32 y;
} FclVec2f;
extern u16 *func_001102e0(void);
extern s32 func_00106330(s32);
extern void func_00145080(void);
extern s32 func_00452380(void *);
extern void func_003315a0(void);
extern void func_00454bd0(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern u32 func_003b7060(void);
extern s8 D_007490F8[];
extern u16 *func_0010ace0(s16);
extern s32 func_0010b6f0(void);
extern u8 func_00109280(s32);
extern s32 func_00331660(void);
extern s8 func_002bab80(void *);
extern void func_002badc0(s8, s32);
extern void func_002bbd80(s8, s32, void *);
extern s32 func_00110140(void);
extern void *func_001067f0(s16);
extern s16 D_00749040[];
extern s16 D_00749060[];
extern s16 D_00749080[];
extern s16 D_007490A0[];
extern s16 D_007490C0[];
extern s16 D_007490E0[];
extern s8 D_00749100[];
extern void func_002bafc0(s8, s32);
extern void func_002bb0a0(s8, s32);
extern void func_002bbf60(void);
extern u16 *func_002e48a0(s8 arg0, s16 arg1);
extern u32 func_0010ceb0(void *);
extern s32 func_0010cf40(void *, s16);
extern u16 *iGpffffb3ec;
extern u8 *iGpffffb594;
extern void func_0010fd40(void *);
extern void func_00106620(s16, s32);
extern s32 func_0010b5b0(void);
extern u8 D_00641BE0[];
extern u8 D_00641C00[];
extern char iGpffffa8c8;
extern s32 func_00451fc0(s32 arg0, const void *arg1, s32, s32, s32, void *, void *, void *);
extern void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern void func_0045aac0(s32, s32, s32);
extern s32 func_00110460(void);
extern void func_00105690(s32, s32);
extern void func_00105fa0(s32);
extern u8 *func_0010b010(u16 personaId);
extern void func_002b68d0(s16, s32, s32);
extern void func_003147e0(u8 *arg0, s8, s64, s16, s16, s32);
extern void func_00324f80(u8 *arg0, s64, s32, s32);
extern void func_00330060(u8 *arg0, s32);
extern void func_002b2a60(void *arg0, s32, s32, s32, s32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u16 D_008C024E[];
extern f32 D_00640D78[];
extern void func_00106390(s32, s32);
extern void func_0044ea90(const void *, s32);
extern void func_0043f9c8(void *, s32, u32);
extern void *func_0043f810(void *, void *, u32);
extern u8 *func_0010fcb0();
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00641B00[];
extern u16 func_0010b460(void);
extern s32 func_0010ad80(s32);
extern s32 func_0010b190(u8 *);
extern s32 func_0010b300(s32);
extern void func_0010b7f0(void);
extern void func_0010cad0(u8 *arg0, u16 arg1);
extern s64 func_00312c60(u16 *arg0, u8 *arg1, s64 arg2);
extern u8 *func_002e4870(s8 arg0);
extern s32 func_0010ce10(u8 *arg0, u32 arg1);
extern s32 func_00313690(s64 arg0);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s8 D_00641A60[];
extern s8 D_00749480[];
extern u8 *iGpffffb3d4;
extern u8 *iGpffffb44c;
extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s8 iGpffffa8a8;
extern u16 func_00107ac0(s32 arg0);
extern u16 *func_0010ac10(s32 arg0);
extern s32 func_00106600(s16 id);
extern u8 D_00641880[];
extern u8 D_0063FCA0[];
extern u8 D_006406F0[];
extern s64 func_00110a60(s32 arg0, s32 arg1);
extern s32 func_00303610(u8 *arg0, s8 arg1, u16 *arg2);
extern f32 D_00641660[];
extern u8 D_006417E0[];
extern u8 D_00882FAE[];
extern u8 D_00882FB0[];
extern u8 D_00882FB1[];
extern f32 func_00109190(void);
extern void func_0032f060(u8 *arg0, s32 arg1);
extern void func_0032f4d0(u8 *arg0);
extern void func_003307b0(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_002b2970(s64 *out, f32 x, f32 y);
extern void func_002b6c30(s32 a, s64 b, s32 c, f32 d);
extern void func_002b6a70(s32, s32, s32, s32, s32, s32);
extern void func_002eb270(u8 *arg0, s32 arg1);
extern void func_003205f0(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_002e8410(u8 *arg0);
extern s32 func_00452490(s32 arg0);
extern void func_00122640(s32, s32);
extern s32 func_00122720(void);
extern void func_00122520(s32, s32);
extern s32 func_002bb680(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern void func_002bb550(s8 arg0);
extern s32 func_004553c0(void *arg0);
extern void func_00144c90(s32, s32);
extern void func_00144e10(s32);
extern s16 func_00104f10(s16);
extern s32 func_0033e120(u8 *arg0, s32, s32);
extern void func_001075d0(s32);
extern s32 func_00144f60(void);
extern u8 *func_001452b0(s32);
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern u8 *func_00457120(void);
extern f32 func_0014b4d0(void);
extern void func_004577d0(u8 *arg0, f32 arg1);
extern s32 func_0014b450(void);
extern void func_003e9cb0(s32, s32, s32);
extern void func_00331390(void);
extern s32 func_00331580(void);
extern void func_002e7ac0(void);
extern void func_002e82b0(void);
extern void func_00313b50(s32);
extern s32 func_0034a4f0(s32, s32);
extern s32 func_0034ad70(s32, u32, s32);
extern u8 *func_0034ae50(u8 *, s8);
extern u8 *func_002b74f0(s32, s32);
extern void func_002b7750(s16, s16);
extern s32 func_0034b740(s32);
extern s32 func_002b8150(s32);
extern void *func_002b5c90(void *, u64);
extern void func_002b29e0(void *, f32, f32);
extern void func_002b5db0(s32, s64, void *);
extern void func_002b5e30(s32, u32);
extern void func_002b5e20(s32, f32);
extern void func_002b6130(s32, u32);
extern void func_002b6140(s32, u8);
extern void func_002b6120(s32, u8);
extern s32 func_0033e3f0(s32);
extern s32 func_002b9f90(s32, s16, s32);
extern s32 func_00331600(void);
extern u8 D_00641B10[];
extern s32 func_003145e0(s32);
extern s32 func_00285b30(u8);
extern s8 *func_0034a630(s32);
extern s8 func_00105f50(u32);
extern s32 func_00452490(s32);
extern void func_00452080(s32);
extern s32 func_00459760(void);
extern void func_0045a3e0(s32, s32);
extern void func_0030f4f0(u8 *, s16 *);
extern s32 func_00314320(u8 *);
extern void func_00320970(u8 *, s32);
extern void func_002b6c30(s32, s64, s32, f32);
extern void func_002b6b40(s32, s32, s32, s32, s32, f32);
extern void func_002b69f0(s32, s64, s64, s32, s32, s32);
extern void func_00315600(u8 *, s32);
extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00302570(u8 *);
extern u8 *iGpffffb440;
extern f32 D_00640C50[];
extern f32 D_00640C58[];
extern u8 D_00641BB0[];
extern void func_00317900(u8 *, s64, s64, s8, s16, s16, s16);
extern u8 D_00640760[];
extern u8 D_00640790[];
extern u8 D_0064079C[];
extern u8 D_006407A8[];
extern u8 D_006407C0[];
extern u16 func_001102d0(void);
extern u16 func_00109470(u16);
extern void func_00110270(u8 *, u16);
extern void func_001102c0(s16);
extern u8 D_00749350[];




/* measured: best nd 12 (10 real + 2 padding). Structure is byte-identical
   to retail except the argument-materialization order at the five
   func_002b5c90 call sites: retail emits `move $a0,$s1` (temp_17) BEFORE
   the `ld $a1, 0xNN($sp)` (s64 vector), mwcc b210 always schedules the
   stack load first. Tried pointer/s32 temp_17, u64/s64 locals, explicit
   (void *) casts, declaration orders — all nd 12. Argument-evaluation
   order floor (also blocked the 0xB0 stack hole: retail frames the five
   16-byte func_002b29e0 outputs at 0x60-0xA0 and the ten s64s at 0xB8+,
   mwcc reproduces that exactly). */
/* measured: GUARDED_SCORE 84 via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombine.c func_002e8410` (pwd source/Persona4-Decompilation; obj 814I == retail 814I, differing words 84; fnalign 90 edits +6 reloc-only). History nd 12 retained below as evidence of 5x 5c90 move-vs-ld arg-order floor (10I) + colour-copy 6I + rotation; current vB candidate details below marker. */
// FUN_002E8410 NONMATCHING
/* measured: vB candidate — obj 814I == retail 814I, probe 84 words, fnalign 90 edits (+6 reloc-only). Decl-search 10 variants (out/task/i/k perms + s16 + stack orders); best k,i,task,out (84 vs v1 143, others 107-149, s16 651, stack same). Earliest divergence saved-reg rotation arg0=$s3 vs $s2/out=$s2 vs $s0 (all decl orders probed). Residuals: rotation + colour-copy load-all vs interleave (6I) + 5x 5c90 move-vs-ld argument order (10I floor per prior note). Prior best nd 12 retained as reference. New levers N-A (see fnalign): single andi 0xFFFF (no CSE/frame+0x10), no adjacent-OR sltiu fold, no COP2. */
#ifdef NON_MATCHING
s32 func_002e8410(u8 *arg0) {
    s32 k;
    s32 i;
    s32 task;
    u8 *out;
    s64 v0;
    s64 v1;
    s64 v2;
    s64 v3;
    s64 v4;
    s64 v5;
    s64 v6;
    s64 v7;
    s64 v8;
    s64 v9;
    FclByte4 c0;
    FclByte4 c1;
    FclByte4 c2;
    FclByte4 c3;
    FclByte4 c4;
    u8 b0[16];
    u8 b1[16];
    u8 b2[16];
    u8 b3[16];
    u8 b4[16];
    u8 *e;
    extern s32 func_00331560(void);

    func_0044ea90(D_00641B00, 0x166);
    out = D_008873F4[0](1, 0x314, 0x40000);
    task = func_00451fc0((s32)arg0, D_00641B10, 0xF, 0, 0, func_002e7ac0, func_002e82b0, out);
    *out = 0;
    *(out + 1) = 0x11;
    *(out + 0x144) = 0;
    func_00313b50(task);
    *(out + 0x20) = 0;
    *(out + 0xB3) = 0;
    *(s32 *)(out + 0x254) = func_0034a4f0((s32)arg0, 0);
    for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
        *(s32 *)(out + i * 4 + 0x154) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
    }
    *(s32 *)(out + 0x184) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
    *(s32 *)(out + 0x188) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x58);
    for (i = 0; i < 0xC; i++) {
        func_002b2a60(&c0, 0, 0, 0x99, 0xFF);
        e = func_0034ae50(*(u8 **)(out + 0x188), (s8)i);
        *(e + 0x75) = c0.b0;
        *(e + 0x76) = c0.b1;
        *(e + 0x77) = c0.b2;
        *(e + 0x78) = c0.b3;
    }
    *(s32 *)(out + 0x24C) = (s32)func_002b74f0((s32)arg0, func_00331560());
    for (i = 0; i < 500; i++) {
        func_002b7750((s16)i, (s16)i);
    }
    for (i = 0; i < 0xC; i++) {
        func_002b7750((s16)(i * 2 + 500), 0x1AC);
        func_002b7750((s16)(i * 2 + 501), 0x1AF);
    }
    func_002b7750(0x20C, 0x80);
    for (i = 0; i < 9; i++) {
        func_002b7750((s16)(i + 0x20D), 0xDC);
    }
    for (i = 0; i < 3; i++) {
        func_002b7750((s16)(i + 0x216), 0x86);
        func_002b7750((s16)(i + 0x219), 0x87);
    }
    for (i = 0; i < 0xC; i++) {
        func_002b7750((s16)(i + 0x21C), 0x193);
        func_002b7750((s16)(i + 0x22B), 0x19A);
        func_002b7750((s16)(i + 0x238), 0x188);
        func_002b7750((s16)(i + 0x244), 0x18C);
        func_002b7750((s16)(i + 0x250), 0x1C);
        func_002b7750((s16)(i + 0x25E), (s16)(i + 0x39));
        func_002b7750((s16)(i + 0x270), 0x193);
        func_002b7750((s16)(i + 0x27D), 0x19B);
        func_002b7750((s16)(i + 0x28B), 0x188);
        func_002b7750((s16)(i + 0x297), 0x18D);
        func_002b7750((s16)(i + 0x2A3), 0x1C);
    }
    func_002b7750(0x228, 0x193);
    func_002b7750(0x229, 0x193);
    func_002b7750(0x2B1, 0x1A2);
    func_002b7750(0x25C, 0x1C);
    func_002b7750(0x25D, 0x1C);
    func_002b7750(0x27C, 0x193);
    func_002b7750(0x289, 0x19B);
    func_002b7750(0x28A, 0x19B);
    func_002b7750(0x237, 0x73);
    func_002b7750(0x2AF, 0x73);
    func_002b7750(0x2B0, 0x73);
    func_002b7750(0x26A, 0x46);
    func_002b7750(0x26B, 0x46);
    func_002b7750(0x26C, 0x46);
    func_002b7750(0x26D, 0x46);
    func_002b7750(0x26E, 0x46);
    func_002b7750(0x26F, 0x46);
    func_002b7750(0x2B2, 0x54);
    func_002b7750(0x2B3, 0x54);
    for (i = 0; i < 0xC; i++) {
        *(s32 *)(out + i * 4 + 0x21C) = func_0034b740((s32)arg0);
    }
    func_002b7750(0x2B4, 0x193);
    func_002b7750(0x2B5, 0x19A);
    func_002b7750(0x2B6, 0x51);
    func_002b7750(0x2B7, 0x52);
    func_002b7750(0x2B8, 0x53);
    func_002b7750(0x2B9, 0x73);
    func_002b7750(0x2BA, 0x73);
    for (k = 0; k < 2; k++) {
        func_002b7750((s16)(k + 0x2BB), 0xA4);
        func_002b7750((s16)(k + 0x2BD), 0xA5);
        func_002b7750((s16)(k + 0x2BF), 0xBC);
        func_002b7750((s16)(k + 0x2C3), 0x19C);
        func_002b7750((s16)(k + 0x2C1), 0x14F);
    }
    for (k = 0; k < 8; k++) {
        func_002b7750((s16)(k + 0x2C5), 0x19E);
    }
    func_002b7750(0x2CD, 0x9E);
    func_002b7750(0x2CE, 0xA0);
    func_002b7750(0x2CF, 0x81);
    func_002b7750(0x2D0, 0x11E);
    func_002b7750(0x2D1, 0x11E);
    func_002b7750(0x2D8, 0x1D6);
    func_002b7750(0x2D9, 0x1D7);
    func_002b7750(0x2DA, 0x165);
    func_002b7750(0x2DB, (s16)((func_002e78a0() % 10) + 9));
    func_002b7750(0x2DC, (s16)((func_002e78e0() / 10) + 9));
    func_002b7750(0x2DD, (s16)((func_002e78e0() % 10) + 9));
    func_002b7750(0x22A, 0x193);
    func_002b7750(0x2DE, 0x126);
    func_002b7750(0x2DE, 0x125);
    for (k = 0; k < 0xC; k++) {
        func_002b7750((s16)(k + 0x2FB), 0x131);
        *(s32 *)(out + k * 4 + 0x258) = func_002b8150(task);
    }
    func_002b2970(&v0, 288.0f, 14.0f);
    *(s32 *)(out + 0x28C) = (s32)func_002b5c90((void *)task, v0);
    func_002b2970(&v1, 288.0f, 14.0f);
    func_002b29e0(b0, 160.0f, 36.0f);
    func_002b5db0(*(s32 *)(out + 0x28C), v1, b0);
    func_002b6130(*(s32 *)(out + 0x28C), 0xAB);
    func_002b6140(*(s32 *)(out + 0x28C), 0);
    func_002b2a60(&c0, 0xFF, 0xFF, 0xFF, 0);
    func_002b5e30(*(s32 *)(out + 0x28C), *(s32 *)&c0);
    func_002b5e20(*(s32 *)(out + 0x28C), 53.0f);
    func_002b2970(&v2, 0.0f, 14.0f);
    *(s32 *)(out + 0x290) = (s32)func_002b5c90((void *)task, v2);
    func_002b2970(&v3, 0.0f, 14.0f);
    func_002b29e0(b1, 26.0f, 36.0f);
    func_002b5db0(*(s32 *)(out + 0x290), v3, b1);
    func_002b6130(*(s32 *)(out + 0x290), 0xAB);
    func_002b6140(*(s32 *)(out + 0x290), 0);
    func_002b2a60(&c1, 0xFF, 0xFF, 0xFF, 0);
    func_002b5e30(*(s32 *)(out + 0x290), *(s32 *)&c1);
    func_002b5e20(*(s32 *)(out + 0x290), 53.0f);
    func_002b2970(&v4, 0.0f, 0.0f);
    *(s32 *)(out + 0x2AC) = (s32)func_002b5c90((void *)task, v4);
    func_002b2970(&v5, 0.0f, 0.0f);
    func_002b29e0(b2, 640.0f, 7.0f);
    func_002b5db0(*(s32 *)(out + 0x2AC), v5, b2);
    func_002b6130(*(s32 *)(out + 0x2AC), 0xB2);
    func_002b2a60(&c2, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30(*(s32 *)(out + 0x2AC), *(s32 *)&c2);
    func_002b6140(*(s32 *)(out + 0x2AC), 1);
    func_002b6120(*(s32 *)(out + 0x2AC), 1);
    func_002b2970(&v6, 0.0f, 432.0f);
    *(s32 *)(out + 0x2B0) = (s32)func_002b5c90((void *)task, v6);
    func_002b2970(&v7, 0.0f, 432.0f);
    func_002b29e0(b3, 640.0f, 16.0f);
    func_002b5db0(*(s32 *)(out + 0x2B0), v7, b3);
    func_002b6130(*(s32 *)(out + 0x2B0), 0xB2);
    func_002b2a60(&c3, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30(*(s32 *)(out + 0x2B0), *(s32 *)&c3);
    func_002b6140(*(s32 *)(out + 0x2B0), 1);
    func_002b6120(*(s32 *)(out + 0x2B0), 1);
    func_002b2970(&v8, 0.0f, 69.0f);
    *(s32 *)(out + 0x2B4) = (s32)func_002b5c90((void *)task, v8);
    func_002b2970(&v9, 0.0f, 69.0f);
    func_002b29e0(b4, 640.0f, 343.0f);
    func_002b5db0(*(s32 *)(out + 0x2B4), v9, b4);
    func_002b6130(*(s32 *)(out + 0x2B4), 0xB2);
    func_002b2a60(&c4, 0x2D, 0x2D, 0x2D, 0xE5);
    func_002b5e30(*(s32 *)(out + 0x2B4), *(s32 *)&c4);
    func_002b6140(*(s32 *)(out + 0x2B4), 1);
    func_002b6120(*(s32 *)(out + 0x2B4), 1);
    *(s32 *)(out + 0x250) = func_0033e3f0(task);
    *(s32 *)(out + 0x2BC) = func_002b9f90(task, 0x30, func_00331600());
    return task;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e8410);
#endif

// FUN_002E90D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e90d0);

/* measured: attempt aborted — a scripted m2c-draft transform of this
   29.5KB state machine (72 s64 stack locals, ~30 func_00317900 7-arg
   calls) produced 90+ mwcc parse errors; the checked-in draft's
   (s64)(((...))-style paren/cast noise defeats mechanical adaptation and
   no clean measured nd was reached (compile never succeeded). Left as
   INCLUDE_ASM. */
// FUN_002EB270
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002eb270);

/* measured: full body now MATCH (object 1136B, retail window 1136B).
   The stack argument/global load is forced in retail order with the named
   FclVec2f base. Table stores use an integer-domain scaled offset so the
   addu has the retail offset-first operand order; direct byte increments
   preserve retail's store-before-next-index schedule. */
// FUN_002ECFC0
void func_002ecfc0(u8 *arg0) {
    s64 sp38;
    u8 *temp_16;
    FclVec2f *base;

    temp_16 = *(u8 **)(arg0 + 0x38);
    base = (FclVec2f *)D_00641660;
    func_002b2970(&sp38, base->x, base->y);
    func_002b6c30(0x1C6, sp38, 0x3D, 242.0f);
    func_002b6a70(0x1C6, 0, 0x64, 0, 0xA, 0);
    *(s8 *)(temp_16 + 0xB4) = 0;
    *(s8 *)(temp_16 + 0xB5) = 0;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 1;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x23;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 0;
    *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 2;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x38;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 1;
    *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    if (func_00106330(0x1301) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 3;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 2;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (func_00106330(0x1302) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 4;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 3;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (func_00106330(0x1303) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 5;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 4;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (func_00106330(0x1304) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 6;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x63;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 5;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 7;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x6E;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 6;
    *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 9;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0xC2;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 7;
    *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 0xB;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0xD8;
    *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 8;
    *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    func_002eb270(arg0, 0);
    func_003205f0(arg0, 0x96, 0x92);
    *(u8 *)(temp_16 + 1) = 0x1A;
}
// FUN_002ED430
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002ed430);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements when the value is an 8-byte struct passed
   BY VALUE (mechanism 1): take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0)
   compiles ldr $a1,0x38 / ldl $a1,0x3F, byte-identical to retail's 6 pairs
   here (0x28/0x2F + 0x38/0x3F, all 8-aligned, feeding func_002b69f0-style
   calls; the s64 spelling gives plain ld — the old note's 20+ probes never
   tried the struct form). Full body still INCLUDE_ASM: ~6200-line asm state
   machine; the m2c draft needs its M2C_ERROR ldr sites replaced with
   struct-by-value args plus the usual m2c-noise cleanup; no full-body nd
   measured. */
// FUN_002F0F00
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f0f00);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~3100-line
   asm; no full-body nd measured. */
// FUN_002F6CF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f6cf0);

// FUN_002F9C30
void func_002f9c30(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, u8 *arg6, s32 arg7, s8 arg8, s8 arg9) {
    u16 buf[6 * 24];
    s8 v;

    switch ((s16)arg7) {
    case 0:
        break;
    case 6:
        func_0043f810(buf + 5 * 24, arg6, 0x30);
        /* fallthrough */
    case 5:
        func_0043f810(buf + 4 * 24, arg5, 0x30);
        /* fallthrough */
    case 4:
        func_0043f810(buf + 3 * 24, arg4, 0x30);
        /* fallthrough */
    case 3:
        func_0043f810(buf + 2 * 24, arg3, 0x30);
        /* fallthrough */
    case 2:
        func_0043f810(buf + 1 * 24, arg2, 0x30);
        /* fallthrough */
    case 1:
        func_0043f810(buf, arg1, 0x30);
        break;
    }
    func_0010cad0((u8 *)arg0, arg0[1]);
    v = (s8)func_00312c60(arg0, (u8 *)buf, (s8)arg7);
    *(func_002e4870(arg8) + arg9 + 0x2E4) = v;
}

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~2200-line
   asm; no full-body nd measured. */
// FUN_002F9D90
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f9d90);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 8 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~6800-line
   asm state machine (also carries adda.s/madd.s FPU-MAC chains); no
   full-body nd measured. */
// FUN_002FBEA0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002fbea0);

// FUN_00302570
s32 func_00302570(u8 *arg0) {
    u8 *p;
    s32 idx;
    s8 i;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0x130) = 0;
    i = 0;
    while ((s32)i < 4) {
        if ((func_00106330((s32)i + 0x1309) == 0) && (func_00110140() >= D_00749100[(s32)i])) {
            *(s8 *)(p + 0x130) = (s8)i;
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(s8 *)(p + 0xD), 0, func_001067f0((s16)(*(s8 *)(p + 0x130) + 0x464)));
            func_002badc0(*(s8 *)(p + 0xD), *(s8 *)(p + 0x130) + 0x17);
            func_00106390((s32)i + 0x1309, 1);
            func_00106620((s16)(i + 0x464), 1);
            *(u8 *)(p + 1) = 0x97;
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_003026C0
s32 func_003026c0(s32 arg0, s32 arg1)
{
    s16 i;

    func_00109280(arg0);
    for (i = 0; i < 4; i++) {
        if (func_00106330(0x130C - i) != 0) {
            return arg1 - (arg1 / 100) * (0x19 - i * 5);
        }
    }
    return arg1;
}

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here at 0x38/0x3F feeding
   func_002b69f0; plain s64 gives ld). Full body still INCLUDE_ASM: ~950-line
   asm state machine; no full-body nd measured. */
// FUN_00302770
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00302770);

/* wave 14: signature re-checked via the m2c oracle and the retail prologue
   (dsll32 $16,$5,24 / dsra32 = byte sign-extend): arg1 IS s8; the m2c's
   s64 arg1 is widening noise. */
/* Floor: 27 differing words / 35 edits (was 32 words / 37 edits; wave-14 attempt measured 131 and kept no
   body).  Two things carried it: `arg2` is a `u16 *`, so the draft's
   `*(u8 *)(arg2 + j * 2)` double-scales - plain `arg2[j]` gives retail's
   `sll 1` plus `lhu` - and `opt_loop_invariants on` hoists the constant 1
   that every case's flag set reuses, which is the const-hoist the earlier
   note identified but did not close (145 -> 44 words on its own).
   measured: hoisting `i = 0` above `count`/`last` (retail rule,i,count,last order) removes the early
   `move $s6` scheduling split (37 -> 35 edits, 32 -> 27 words; fnalign retail/object 259/259 instrs).
   WALL: retail keeps the per-case loop counters in temps ($a1/$a3/$a2) and splits
   j/k across $s5/$s3, while this build holds j in $s3 throughout.  Block-scoped per-case counters (240)
   and 200 declaration orders were measured. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/Event/Fcl/y_fclCombine.c func_00303610 --pairs` banked 27 (already carries opt_loop_invariants on); best ties 27 (loopinv alone plus four loopinv+second combos); bare without loopinv is 132, so the banked pragma stays load-bearing. All 28 pairs neutral or worse (commons 240-261, schedule 235-247, peephole 275-339). fnalign retail/object 259/259 per assignment. Floor stands; production stays ASM. */
// FUN_00303610 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_00303610(u8 *arg0, s8 arg1, u16 *arg2)
{
    u8 *rule;
    u16 *last;
    s16 want;
    s8 kind;
    s8 index;
    s16 i;
    s16 j;
    s16 k;
    s16 count;
    s8 found;

    index = *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x2D4);
    if (index == -1) {
        return 1;
    }
    rule = D_0063FCA0 + index * 0x1C;
    i = 0;
    count = arg1;
    last = arg2 + count;
    for (; i < 3; i++) {
        kind = *(s8 *)(rule + 2);
        if (kind == 0) {
            continue;
        }
        found = 0;
        switch (kind) {
        case 1:
            for (j = 0; j < count; j++) {
                want = *(s16 *)(rule + 4);
                if (want == (func_00109280(arg2[j]) & 0xFF)) {
                    found = 1;
                    break;
                }
            }
            break;
        case 2:
            for (j = 0; j < count; j++) {
                if (*(s16 *)(rule + 4) == arg2[j]) {
                    found = 1;
                    break;
                }
            }
            break;
        case 3:
            want = *(s16 *)(rule + 4);
            if (want == (func_00109280(*last) & 0xFF)) {
                found = 1;
            }
            break;
        case 4:
            if (*(s16 *)(rule + 4) == *last) {
                found = 1;
            }
            break;
        case 5:
            for (j = 0; j < count; j++) {
                want = *(s16 *)(rule + 4);
                if (want == (func_00109280(arg2[j]) & 0xFF)) {
                    for (k = 0; k < count; k++) {
                        want = *(s16 *)(rule + 6);
                        if (want == (func_00109280(arg2[k]) & 0xFF)) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        case 6:
            for (j = 0; j < count; j++) {
                if (*(s16 *)(rule + 4) == arg2[j]) {
                    for (k = 0; k < count; k++) {
                        if (*(s16 *)(rule + 6) == arg2[k]) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        case 7:
            if (count != 3) {
                return 0;
            }
            found = 1;
            break;
        case 8:
            if (count != 4) {
                return 0;
            }
            found = 1;
            break;
        case 9:
            if (count != 5) {
                return 0;
            }
            found = 1;
            break;
        case 10:
            if (count != 6) {
                return 0;
            }
            found = 1;
            break;
        }
        if (found == 0) {
            return 0;
        }
    }
    return 1;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303610);
#endif

// FUN_00303A20
void func_00303a20(u8 *arg0) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    u16 buf[7];

    switch (p[0x1A]) {
    case 2:
        buf[0] = *(u16 *)(func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[2] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 3:
        buf[0] = *(u16 *)(func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)(func_002e48a0(0, p[0x129]) + 1);
        buf[2] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[3] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 4:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 5:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 6:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 5) + 1);
        buf[6] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    }
    func_00303610(arg0, p[0x1A], buf);
}

/* measured: 740 executable bytes / 752B retail window, all eight relocations exact.
   Five s32 weights and five s8 IDs reproduce the real stack buffers. A named
   compact-store pointer and the s16 value cast preserve retail address lifetimes. */
// FUN_00303DE0
#pragma opt_loop_invariants on
void func_00303de0(u8 *arg0)
{
    s32 weights[5];
    s8 ids[5];
    s8 *p;
    u32 total;
    s8 count;
    s16 cumulative;
    u32 selectedAddress;
    s8 *calendar;
    s32 month;
    s16 i;
    s16 j;
    s16 k;
    s32 roll;
    s32 *entry;

    p = *(s8 **)(arg0 + 0x38);
    total = 0;
    count = 0;
    cumulative = 0;
    /* Keep the pre-callback selector snapshot without forming a pointer
       before the table when the selector is -1. */
    selectedAddress = (u32)D_0063FCA0 + p[724] * 28;
    month = func_002e78a0();
    calendar = (s8 *)D_006406F0 + (s8)func_00110a60(month, func_002e78e0()) * 20;
    p[735] = 0;
    if (p[724] == -1) {
        for (i = 0; i < 5; i++) {
            s8 id;
            s8 weight;
            ids[i] = 0;
            weights[i] = 0;
            id = calendar[i * 4];
            if (id != 0) {
                weight = calendar[i * 4 + 1];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    } else {
        for (j = 0; j < 5; j++) {
            s8 id;
            s8 weight;
            ids[j] = 0;
            weights[j] = 0;
            id = ((s8 *)selectedAddress)[j * 4 + 8];
            if (id != 0) {
                weight = ((s8 *)selectedAddress)[j * 4 + 9];
                if (weight == 100) {
                    p[p[735] + 730] = id;
                    p[735]++;
                } else {
                    entry = weights + count;
                    *entry = weight;
                    total += weight;
                    ids[count] = id;
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        roll = (s16)(func_003b7060() % total);
        for (k = 0; k < count; k++) {
            cumulative += (s16)weights[k];
            if (roll < cumulative) {
                p[p[735] + 730] = ids[k];
                p[735]++;
                return;
            }
        }
    }
}
#pragma opt_loop_invariants reset
/* measured: object 532B/window 544B, nd 0. The five-byte weight table copy is
   the tree's load / advance / decrement / store order through a named byte
   temporary. The random roll is an s32 holding the (s8) remainder (extended
   once, retail $a0); the running sum and the s16 index are narrow locals that
   re-extend at each use. The picked stage is an s8 assigned from the call
   (extension at the assignment), then copied into a separate s32 `cur`
   (second extension after the join) that the retry loop compares without a
   further extension; count is an s32 narrowed with `(s8)(count + 1)` so the
   final call passes it raw. Declaration order colours k/limit/count into
   $s5/$s4/$s3 (count reuses arg1's register after its last use). */
// FUN_003040D0
s32 func_003040d0(u8 *arg0, s16 arg1, s32 arg2)
{
    s8 weights[5];
    u8 *work;
    s8 *src;
    s8 *dst;
    s32 n;
    s8 v;
    s16 i;
    s8 acc;
    s32 roll;
    s16 k;
    s8 limit;
    s32 count;
    s8 stage;
    s8 pick;
    s32 cur;

    work = *(u8 **)(arg0 + 0x38);
    src = &iGpffffa8a8;
    dst = weights;
    n = 5;
    do {
        v = *src;
        src += 1;
        n -= 1;
        *dst = v;
        dst += 1;
    } while (n > 0);
    roll = (s8)(func_003b7060() % 100);
    acc = weights[0];
    i = 0;
    goto check;
body:
    if (roll < acc) {
        stage = i;
        goto found;
    }
    acc += weights[i + 1];
    i += 1;
check:
    if (i < 4) goto body;
    stage = 4;
found:
    limit = 10;
    if (func_003b7060() % 100 < 30) {
        pick = func_002b2d00(arg1, stage, 1, 0x63, 1);
    } else {
        pick = func_002b2cb0(arg1, stage, 0x63, 1, 1);
    }
    cur = pick;
    k = 0;
    count = 0;
    goto check2;
body2:
    if (cur < limit) goto done;
    limit = func_002b2cb0(limit, 10, 0x63, 1, 1);
    count = (s8)(count + 1);
    k += 1;
check2:
    if (k < 10) goto body2;
done:
    *(s8 *)(work + 0x1E) = count;
    return func_003042f0(count, arg2);
}
// FUN_003042F0
s32 func_003042f0(s32 arg0, s32 arg1)
{
    switch ((s8)arg1) {
    case 1:
        return D_00749040[(s8)arg0];
    case 2:
        return D_00749060[(s8)arg0];
    case 3:
        return D_00749080[(s8)arg0];
    case 4:
        return D_007490A0[(s8)arg0];
    case 5:
        return D_007490C0[(s8)arg0];
    case 6:
        return D_007490E0[(s8)arg0];
    }
    return -1;
}

/* measured: full body now MATCH. Retail copies six 8-byte blocks into an
   sp+0x4F0 buffer, fills an sp+0x70 s16 table from the func_00313690 key
   loop, then retries rand()%count until func_0010ce10 succeeds. The copy
   buffer is declared before the table so the stack offsets match, and the
   copy loop uses two s32 load/store temporaries with the counter decrement
   between pointer increment and stores. The random divisor is a separate s32
   local after the sign-extended s64 count; a signed modulo result and named
   s16 *entry table pointer force retail's dsll32/dsra32 remainder and its
   separate addiu 0x70 before lhu. Scoped verify reports byte-exact MATCH. */
// FUN_00304410
u16 func_00304410(u8 *arg0, s64 arg1) {
    u8 copy[0x30];
    s16 table[0x240];
    u8 *src;
    u8 *dst;
    s32 temp_1;
    s32 temp_2;
    s32 copy_count;
    s64 arg1_saved;
    s64 key;
    s64 count;
    s32 j;
    s32 i;
    s64 j_mask;
    s8 retry;
    s32 divisor;
    s16 *entry;
    u16 selected;
    s64 bound;

    arg1_saved = arg1;
    src = arg0;
    dst = copy;
    copy_count = 6;
    do {
        temp_1 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        copy_count -= 1;
        *(s32 *)dst = temp_1;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (copy_count > 0);
    key = (s16)func_00313690(arg1_saved);
    count = (s16)key;
    i = 0;
    retry = 0;
    j = 0;
    bound = (s16)arg1_saved;
    goto scan;
scan_body:
    key = (s16)func_00313690((s16)j);
    if (count == (s16)key && bound != j_mask) {
        table[(s16)i] = (s16)j;
        i = (s16)(i + 1);
    }
    j = (j + 1) & 0xFFFF;
scan:
    j_mask = (u16)j;
    if (j_mask < 0x240) goto scan_body;
    j_mask = (s16)i;
    divisor = (s32)j_mask;
    do {
        entry = table + (s16)(func_003b7060() % (u32)divisor);
        selected = *entry;
        if (func_0010ce10(copy, selected) == -1) {
            retry = 1;
        }
    } while ((s8)retry == 0);
    return selected;
}
// FUN_00304580
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00304580);

/* measured: same stack-lookup-table floor as func_00308e50 — retail loads
   tbl[i] via sll/addu($sp)/addiu(0x48)/lh ($v0); mwcc b210 folds the 0x48
   into the load displacement in every spelling (array-index nd 42,
   byte-offset arithmetic nd 42), shifting all following words by one. */
/* MATCHED wave 14: the stack-table INITIALIZER was the real defect, not the
   load form. A `s16 table[4] = {…}` initializer makes mwcc load the 4
   constants from a gp-relative pool (lh $a2,($gp) x4) instead of retail's
   four addiu/sh pairs; writing `table[0]=0xD; table[1]=0x35; …` as
   individual stores reproduces retail exactly (the sll/addu/sp/addiu(0x48)/
   lhu load shape then matches byte-for-byte). nd 95 -> 1 -> MATCH. Note the
   return type is u16* (returns the raw func_002e48a0 results), and the
   per-iteration args reload p[0x128]/p[0x129] with (s8) hunches. */
// FUN_00308CC0
u16 *func_00308cc0(u8 *arg0) {
    s16 table[4];
    s8 *p = *(s8 **)(arg0 + 0x38);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == func_002e48a0(0, p[0x128])[1]) {
            return func_002e48a0(0, p[0x129]);
        }
        if (table[i] == func_002e48a0(0, p[0x129])[1]) {
            return func_002e48a0(0, p[0x128]);
        }
    }
    return 0;
}
// FUN_00308DC0
s32 func_00308dc0(void)
{
    s16 i;
    s32 temp;
    s8 *p;

    temp = (u8)(func_003b7060() % 100U);
    i = 0;
    p = D_007490F8;
    while (i < 6) {
        if (temp < p[i]) {
            return (s8)i;
        }
        i++;
    }
    return 5;
}
/* measured: retail loads the stack lookup table via sll/addu($sp)/addiu(0x48)
   then lh ($v0); mwcc b210 folds the 0x48 into the load displacement
   (sll/addu/lh 0x48($v0)) no matter the spelling — probed array-index,
   named pointer, byte-offset arithmetic, for-loop, initializer-list, and
   #pragma schedule on (nd 56); best nd 40. Same floor family as func_00308f40. */
/* MATCHED wave 14: same fix as func_00308cc0 — the table INITIALIZER was the
   defect. Individual stores `table[0]=0xD; …` (not the array initializer,
   which pulls the 4 constants from a gp pool) reproduce retail's addiu/sh
   pairs; the sll/addu/sp/addiu(0x48)/lh read immediately matches, and the
   loop/branch layout falls into place (nd 10 -> 1 benign padding -> MATCH).
   Key types: table is s16[4], p is the s8* work at arg0+0x38, table compare
   against func_002e48a0(0, p[0x128])[1] / [0x129] with (s8)i return. */
// FUN_00308E50
s32 func_00308e50(u8 *arg0) {
    s16 table[4];
    s8 *p = *(s8 **)(arg0 + 0x38);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == func_002e48a0(0, p[0x128])[1]) return (s8)i;
        if (table[i] == func_002e48a0(0, p[0x129])[1]) return (s8)i;
    }
    return -1;
}
/* floor (above marker kept clear for the verifier): the array-address
   sequence sll/addu(sp)/addiu(0x48) vs mwcc's sll/addiu/addu with swapped
   $v0/$v1 coloring — probed array, pointer, named-temp, separate-locals,
   byte-offset forms and schedule/opt_* pragmas; best nd 4 (scheduling). */
/* measured (wave C retest): full body adapted from the m2c draft — best
   nd 182, obj 1712B == window, every residual row is a saved-register
   swap except one: b210 drops the andi 0xF on the (s8)((x >> 0xC) & 0xF)
   nibble extract (sra 12; dsll32/dsra32, no mask; the other three nibbles
   keep theirs; two-statement and use-site-cast spellings both drop it —
   recorded as a fold floor). Key spellings that DID land: func_00109470
   declared u16-returning so b210 emits the andi 0xFFFF result mask before
   the user's bit-test andi (s32 return folds the chain to one andi); u16
   parameter so the var_20 & 0xFFFF arg mask lands at each call site (an
   explicit & 0xFFFF arg gets CSE-hoisted into a saved register and grows
   the frame to 0x80); (u8) store slots kill the (s8) sign-extension pair
   after the 2b2cb0 andi. Residual rotation: mine temp_17=$s3,temp_16=$s2,
   temp_19=$s0,var_18=$s4,var_20=$s1 vs retail temp_17=$s1,temp_16=$s0,
   temp_19=$s3,var_18=$s2,var_20=$s4 — declaration orders probed, no
   change. The earlier "best nd 4" note was wrong or belonged to another
   source shape; the previous agent's note was inaccurate about the 0x48
   stack table (none exists in this function). */
/* wave 14: re-checked the signature via the m2c oracle
   (void func_00308f40(void) — no args, correct); the nibble-extract fold
   and every residual row are saved-register swaps that resist decl order
   (all probed). No wave-14 lever applies (no global base, no jtbl reload,
   no addu-order site). Best measured nd 182 unchanged. */
/* measured: `s32 raw` (retail sra, not dsra) + reuse first-block nibbles in the 1307/1306 arm
   (raw is saved across the flag loop, so the 4-line recompute is redundant and made the first
   block dead; retail reuses). Words 372 -> 356, edits 179 -> 171 (fnalign retail 428 / object 449-450
   instrs, window 1712B); frame 0x70 vs 0x60 + saved-reg rotation remain the WALL. */
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
/* measured 00308f40: `schedule on` inside the guard is worth 15 words (356 -> 341). */
/* measured 00308f40: `opt_propagation off` inside the guard is worth 10 words (341 -> 331). */
// FUN_00308F40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma schedule on
void func_00308f40(void) {
    s32 raw;
    s64 n0;
    s64 n1;
    s64 n2;
    s64 n3;
    s64 i;
    s64 j;
    s64 k;
    s64 total;
    s64 packed;
    u16 *p;

    raw = (s32)func_001102d0() & 0xFFFF;
    n0 = (s8)((raw & 0xF));
    n1 = (s8)(((raw >> 4) & 0xF));
    n2 = (s8)(((raw >> 8) & 0xF));
    n3 = (s8)(((raw >> 0xC) & 0xF));
    total = 0;
    i = 0;
    while (i < (func_0010b6f0() & 0xFFFF)) {
        if ((func_00109470((u16)i) & 4) != 0) {
            if ((func_00109470((u16)i) & 0x80) != 0) {
                *(u16 *)func_0010ace0((s16)i) ^= 4;
                *(u16 *)func_0010ace0((s16)i) ^= 0x20;
                *(u16 *)func_0010ace0((s16)i) ^= 0x40;
                *(u16 *)func_0010ace0((s16)i) ^= 0x80;
            } else if ((func_00109470((u16)i) & 0x40) != 0) {
                *(u16 *)func_0010ace0((s16)i) |= 0x80;
            } else if ((func_00109470((u16)i) & 0x20) != 0) {
                *(u16 *)func_0010ace0((s16)i) |= 0x40;
            } else {
                *(u16 *)func_0010ace0((s16)i) |= 0x20;
            }
        }
        i++;
    }
    if ((func_00106330(0x1307) == 0) && (func_00106330(0x1306) != 0)) {
        n3 = (s8)func_002b2cb0((s32)n3, 1, 6, 0, 1);
        packed = ((n3 & 0xF) << 0xC) | ((n2 & 0xF) << 8) |
                 ((n1 & 0xF) << 4) | (n0 & 0xF);
        j = 0;
        total = 0;
        while (j < 5) {
            total += (s8)*((u8 *)func_001102e0() + j + 0x26);
            j++;
        }
        if ((n3 >= n2) || (n3 == 6)) {
            p = func_001102e0();
            func_0010cad0((u8 *)p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), (u16)packed);
            func_00106390(0x1307, 1);
            return;
        }
        if (total >= 0x1E) {
            p = func_001102e0();
            func_0010cad0((u8 *)p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), (u16)packed);
            func_00106390(0x1307, 1);
            return;
        }
        func_001102c0((s16)packed);
        switch ((s8)n2) {
        case 0:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1C) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x26) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x27) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 1:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x28) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x28),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1F) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x29) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x29),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 2:
            if (*(u8 *)((u8 *)func_001102e0() + 0x20) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x2A) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x2A),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1C) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x26) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 3:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x27) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(s8 *)((u8 *)func_001102e0() + 0x28) =
                    (s8)func_002b2cb0(*(s8 *)((u8 *)func_001102e0() + 0x28),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            break;
        }
    }
}
#pragma schedule off
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00308f40);
#endif

// FUN_003095F0
s32 func_003095f0(void)
{
    if (func_001102e0()[1] == 0xB3) {
        return 0xBA;
    }
    return 0xB3;
}

// FUN_00309630
s32 func_00309630(u16 arg0)
{
    s16 i;
    s32 key;

    i = 0;
    key = arg0;
    while (i < (u16)func_0010b6f0()) {
        if (key == *(u16 *)((u8 *)func_0010ace0(i) + 2)) {
            return 1;
        }
        i++;
    }
    return 0;
}
// FUN_003096D0
s32 func_003096d0(void)
{
    u32 temp_16;
    u16 *temp_17;
    s32 var_20;
    s32 var_19;
    s16 temp_18;
    u16 temp_16_2;

    var_19 = 0;
    var_20 = 0;
    while ((s16)var_20 < 4) {
        temp_16 = func_0010ceb0(func_001102e0());
        temp_18 = (s16)(func_003b7060() % temp_16);
    loop_2:
        temp_17 = &iGpffffb3ec[(s16)var_19 * 2];
        temp_16_2 = temp_17[0];
        if (temp_16_2 == func_0010cf40(func_001102e0(), temp_18)) {
            return var_19;
        }
        var_19 = (s16)(var_19 + 1);
        if ((temp_16_2 == 0) || (temp_17[1] == 0)) {
            var_20 = (s16)(var_20 + 1);
        } else {
            goto loop_2;
        }
    }
    return -1;
}
// FUN_003097E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003097e0);

/* wave 14: signature re-checked via the m2c oracle (void func_0030b060(u8 *
   arg0) — correct). All wave-14 levers checked: the function has no global
   base, no jtbl reload, no addu-order site; residuals are the frame-size/saved-
   reg map (retail 0xB0 with a never-used $s6 vs mwcc 0xA0 six-save) and the
   switch/loop register schedule. opt_propagation off not applicable
   (multi-store switch). Best nd 90 edits / 139 words (switch; was ~N/A unmeasured). */
/* measured: retail's frame is 0xB0 with 7 saved GPR slots ($s6 saved but
   never used) while mwcc b210 allocates 6 saved regs (frame 0xA0), and the
   whole saved-register map rotates (mine arg0=$s1,p=$s0 vs retail
   arg0=$s5,p=$s2). Structure verified: switch 0xC2/0xC3/0xC4 with
   reversed tests, 4 separate s64 vector locals + 4 FclByte4 color locals,
   26.0f/cvt.s.w int-to-float args, per-call lbu/sb color copies, the
   6-way func_002b6970 guard, bit-flag dispatch chain, e/lim/k loop.
   measured: switch (C2,C3,C4 source order) vs if-chain fixes the dispatch layout
   (386 -> 139 words, 583 -> 90 edits [+6 reloc]; fnalign retail 468 / object 470
   instrs, window 1872B / object 1880B). Residual WALL is frame-size + rotation plus
   the 4-byte colour load-all-store-all vs interleaved lbu/sb schedule and 8B size shift. */
/* measured 0030b060: `opt_loop_invariants on` inside the guard is worth 4 words (139 -> 135). */
// FUN_0030B060 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0030b060(u8 *arg0)
{
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    s16 e;
    s16 k;
    s16 lim;
    s64 v0;
    s64 v1;
    s64 v2;
    s64 v3;
    FclByte4 c0;
    FclByte4 c1;
    FclByte4 c2;
    FclByte4 c3;
    u8 *te;
    s8 t;

    p = *(u8 **)(arg0 + 0x38);
    kind = *(p + 1);
    switch (kind) {
    case 0xC2:
        *(s16 *)(p + 0x120) = 0;
        *(s16 *)(p + 0x11E) = 0;
        func_003205f0(arg0, 0x97, 0x96);
        for (i = 0; i < 8; i++) {
            func_002b68d0((s16)(i + 0x179), 0, 1);
        }
        for (j = 0; j < 6; j++) {
            func_002b2970(&v0, 26.0f, (f32)(j * 0x22 + 0x57));
            func_003147e0(arg0, (s8)j, v0, (s16)(j + 0x179), (s16)(j * 2 + 2), 0);
        }
        func_002b2a60(&c0, 0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) * 2 + 500));
        *(te + 0x85) = c0.b0;
        *(te + 0x86) = c0.b1;
        *(te + 0x87) = c0.b2;
        *(te + 0x88) = c0.b3;
        func_002b2a60(&c1, 0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) * 2 + 501));
        *(te + 0x85) = c1.b0;
        *(te + 0x86) = c1.b1;
        *(te + 0x87) = c1.b2;
        *(te + 0x88) = c1.b3;
        func_002b2a60(&c2, 0x2D, 0x2D, 0x2D, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) + 0x179));
        *(te + 0x85) = c2.b0;
        *(te + 0x86) = c2.b1;
        *(te + 0x87) = c2.b2;
        *(te + 0x88) = c2.b3;
        func_002b2a60(&c3, 0x92, 0xC8, 7, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x120) + 0x2FB));
        *(te + 0x85) = c3.b0;
        *(te + 0x86) = c3.b1;
        *(te + 0x87) = c3.b2;
        *(te + 0x88) = c3.b3;
        func_002b2970(&v1, D_00640D78[0], D_00640D78[1]);
        func_00324f80(arg0, v1, 1, 0);
        *(s32 *)(p + 0x124) = 0x428F0000;
        *(p + 1) = 0xC3;
        break;
    case 0xC3:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(500) + 0x10), 1) != 1) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(502) + 0x10), 1) != 1) {
                if ((s16)func_002b6970(*(s16 *)(func_002b6150(504) + 0x10), 1) != 1) {
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(506) + 0x10), 1) != 1) {
                        if ((s16)func_002b6970(*(s16 *)(func_002b6150(508) + 0x10), 1) != 1) {
                            if ((s16)func_002b6970(*(s16 *)(func_002b6150(510) + 0x10), 1) != 1) {
                                if ((D_008C0276[0] & 0x1000) && (*(p + 0x13A) == 0)) {
                                    func_00330060(arg0, 5);
                                    return;
                                }
                                if (D_008C027A[0] & 0x1000) {
                                    func_00330060(arg0, 1);
                                    return;
                                }
                                if ((D_008C0276[0] & 0x4000) && (*(p + 0x13A) == 0)) {
                                    func_00330060(arg0, 4);
                                    return;
                                }
                                if (D_008C027A[0] & 0x4000) {
                                    func_00330060(arg0, 0);
                                    return;
                                }
                                if (D_008C027A[0] & 0x8000) {
                                    func_00330060(arg0, 3);
                                    return;
                                }
                                if (D_008C027A[0] & 0x2000) {
                                    func_00330060(arg0, 2);
                                    return;
                                }
                                if (D_008C024E[0] & 0x40) {
                                    func_0045af60(0, 0, 0, 1);
                                    t = func_002bab80((void *)func_00331660());
                                    *(p + 0xD) = t;
                                    func_002badc0(t, *(s16 *)(p + 0x11E) + 0x58);
                                    *(p + 1) = 0xC4;
                                } else if (D_008C024E[0] & 0x20) {
                                    func_0045af60(0, 0, 0, 2);
                                    func_003205f0(arg0, 0x96, 0x97);
                                    func_002b2970(&v2, D_00640D78[0], D_00640D78[1]);
                                    func_00324f80(arg0, v2, 1, 1);
                                    e = *(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120);
                                    k = 0;
                                    lim = e + 6;
                                    for (; e < lim; e++, k++) {
                                        func_002b2970(&v3, 26.0f, (f32)(k * 0x22 + 0x57));
                                        func_003147e0(arg0, (s8)k, v3, (s16)(e + 0x179), (s16)((5 - k) * 2), 1);
                                    }
                                    func_002eb270(arg0, 0);
                                    *p = 0;
                                    *(p + 1) = 0x1A;
                                }
                                *(p + 0x13A) = 0;
                                return;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 0xC4:
        if (func_002bb680(*(p + 0xD)) != 0) {
            func_002bbcf0(*(p + 0xD));
        } else {
            func_002bb550(*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b060);
#endif

/* wave 14: signature re-checked via the m2c oracle (void func_0030b7b0(u8 *
   arg0) — correct). All wave-14 levers checked: no global base, no jtbl
   reload; residuals are the arg0/k saved-reg rotation, the (s8) increment-
   before-sb IR ordering, and the lbu/sb-per-byte vs load-all-store-all
   colour copies (FclByte4 struct copies compile 10B larger — struct form
   is the wrong direction). Best nd 295 unchanged. */
/* measured: full m2c-adapted body — obj 3088B == window, best nd 295 (all
   rows are register names + two scheduling patterns). Structural fixes that
   DID land: (s16) cast on the func_002b6970 result (retail sign-extends it),
   flag loads CSE'd into locals across the func_003307b0 calls (retail loads
   D_008C0276/027A/024E once), shared te pointer in the case-0xC3 loop
   (retail keeps &D_00882FB0[k*2] in a saved reg). Residuals: (1) saved-
   register rotation arg0=$s2,k=$s1 vs retail arg0=$s1,k=$s4 — all
   declaration orders probed, no change; (2) the (s8) increment narrowing
   pair is emitted before the sb (5 sites) vs retail store-first — IR
   ordering, schedule on/off and s32/s8 temps don't move it; (3) the 4-byte
   colour copies interleave lbu/sb per byte vs retail load-all-store-all
   (FclByte4 struct copies compile 10B larger); (4) retail materializes a
   te+1 pointer for the [1] reads. Saved-register rotation + scheduling
   floor. */
// FUN_0030B7B0 NONMATCHING
/* measured: v2 candidate — obj 769I == retail 769I (stripped), probe 475 words, fnalign 119 edits (+40 reloc-only). Earliest divergence now branch-offset only for first 200I; first real divergence at 219 (s16 extend for j) + colour-copy load-all vs interleave + te+1 pointer. Saved-reg rotation fixed vs v1 (arg0=$s1,p=$s0 match). Floor candidate for guarded install; prior best nd 295 retained as reference. */
#ifdef NON_MATCHING
void func_0030b7b0(u8 *arg0) {
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    s64 v0;
    s64 v1;
    s64 v2;
    s64 v3;
    s64 v4;
    s64 v5;
    FclByte4 c0;
    FclByte4 c1;
    FclByte4 c2;
    FclByte4 c3;
    FclByte4 c4;
    FclByte4 c5;
    FclByte4 c6;
    u8 *te;
    u8 *te2;
    u8 *p501;
    u8 *p500;
    s8 sidx;
    s8 t;
    u16 f276;
    u16 f27a;
    u16 f24e;

    p = *(u8 **)(arg0 + 0x38);
    kind = *(p + 1);
    switch (kind) {
    case 0xC2:
        func_003205f0(arg0, 0x97, 0x96);
        *(s16 *)(p + 0x11E) = 0;
        *(p + 0x139) = 0;
        func_002b2970(&v0, 26.0f, 87.0f);
        func_003147e0(arg0, 0, v0, 0x168, 2, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970(&v1, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 1, v1, 0x174, 4, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 1;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xC;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970(&v2, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 2, v2, 0x170, 6, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 2;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 8;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970(&v3, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 3, v3, 0x171, 8, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 3;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 9;
        *(s8 *)(p + 0x139) += 1;
        if (func_00106330(0x1305) != 0) {
            func_002b2970(&v4, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
            func_003147e0(arg0, 0xB, v4, 0x173, 0xA, 0);
            D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0xB;
            D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xB;
            *(s8 *)(p + 0x139) += 1;
        }
        for (j = 0; j < *(s8 *)(p + 0x139); j++) {
            te = &D_00882FB0[j * 2];
            func_002b2a60(&c0, 0, 0, 0x66, 0xFF);
            p501 = func_002b6150((s16)(*(s8 *)te * 2 + 501));
            *(p501 + 0x85) = c0.b0;
            *(p501 + 0x86) = c0.b1;
            *(p501 + 0x87) = c0.b2;
            *(p501 + 0x88) = c0.b3;
            p500 = func_002b6150((s16)(*(s8 *)te * 2 + 500));
            *(p500 + 0x85) = *(p501 + 0x85);
            *(p500 + 0x86) = *(p501 + 0x86);
            *(p500 + 0x87) = *(p501 + 0x87);
            *(p500 + 0x88) = *(p501 + 0x88);
            func_002b2a60(&c1, 0xCC, 0xFF, 0xFF, 0xFF);
            te2 = func_002b6150((s16)(te[1] + 0x168));
            *(te2 + 0x85) = c1.b0;
            *(te2 + 0x86) = c1.b1;
            *(te2 + 0x87) = c1.b2;
            *(te2 + 0x88) = c1.b3;
            if (*te == 0xB && func_00106330(0x1308) == 0) {
                func_002b2a60(&c2, 0xFF, 0xCC, 0xFF, 0xFF);
                te2 = func_002b6150((s16)(te[1] + 0x168));
                *(te2 + 0x85) = c2.b0;
                *(te2 + 0x86) = c2.b1;
                *(te2 + 0x87) = c2.b2;
                *(te2 + 0x88) = c2.b3;
            }
        }
        func_002b2a60(&c3, 0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150(500);
        *(te + 0x85) = c3.b0;
        *(te + 0x86) = c3.b1;
        *(te + 0x87) = c3.b2;
        *(te + 0x88) = c3.b3;
        func_002b2a60(&c4, 0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150(501);
        *(te + 0x85) = c4.b0;
        *(te + 0x86) = c4.b1;
        *(te + 0x87) = c4.b2;
        *(te + 0x88) = c4.b3;
        func_002b2a60(&c5, 0x2D, 0x2D, 0x2D, 0xFF);
        te = func_002b6150(0x168);
        *(te + 0x85) = c5.b0;
        *(te + 0x86) = c5.b1;
        *(te + 0x87) = c5.b2;
        *(te + 0x88) = c5.b3;
        func_002b2a60(&c6, 0x92, 0xC8, 7, 0xFF);
        te = func_002b6150((s16)(D_00882FB0[*(s16 *)(p + 0x11E) * 2] + 0x2FB));
        *(te + 0x85) = c6.b0;
        *(te + 0x86) = c6.b1;
        *(te + 0x87) = c6.b2;
        *(te + 0x88) = c6.b3;
        if (*(s8 *)(p + 0x138) > 0) {
            func_0032f060(arg0, 0);
        }
        *(p + 1) = 0xC3;
        break;
    case 0xC3:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(*(s8 *)(D_00882FAE + *(s8 *)(p + 0x139) * 2) * 2 + 500)) + 0x10), 1) != 1) {
            f276 = D_008C0276[0];
            f27a = D_008C027A[0];
            if ((f276 & 0x1000) && (*(p + 0x13A) == 0)) {
                func_003307b0(arg0, 5, D_00882FB0);
                return;
            }
            if (f27a & 0x1000) {
                func_003307b0(arg0, 1, D_00882FB0);
                return;
            }
            if ((f276 & 0x4000) && (*(p + 0x13A) == 0)) {
                func_003307b0(arg0, 4, D_00882FB0);
                return;
            }
            if (f27a & 0x4000) {
                func_003307b0(arg0, 0, D_00882FB0);
                return;
            }
            f24e = D_008C024E[0];
            if (f24e & 0x40) {
                func_0045af60(0, 0, 0, 1);
                t = D_00882FB0[*(s16 *)(p + 0x11E) * 2];
                switch (t) {
                case 0:
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                        func_002badc0(*(p + 0xD), 0x6F);
                    } else if ((s16)func_00104f10(1) < 3 || func_00106330(0x96F) != 0) {
                        func_002badc0(*(p + 0xD), (func_00107ac0(0x14) & 0xFFFF) + 0x64);
                    } else {
                        func_002badc0(*(p + 0xD), 0x70);
                    }
                    break;
                case 1:
                    sidx = (s8)(10.0f * func_00109190());
                    te = D_006417E0 + ((func_002e78a0() & 0xFF) - 1) * 0xB;
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    func_002badc0(*(s8 *)(p + 0xD), *(te + sidx) + 2);
                    break;
                case 2:
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    func_002badc0(*(s8 *)(p + 0xD), 0x61);
                    break;
                case 3:
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    func_002badc0(*(s8 *)(p + 0xD), 0x62);
                    break;
                case 11:
                    func_00106390(0x1308, 1);
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    func_002badc0(*(s8 *)(p + 0xD), 0x63);
                    if (*(s8 *)(p + 0x138) == 0) {
                        func_0032f060(arg0, 1);
                    }
                    break;
                }
                *(p + 1) = 0xC4;
            } else if (f24e & 0x20) {
                func_0045af60(0, 0, 0, 2);
                for (i = 0; i < *(s8 *)(p + 0x139); i++) {
                    te = &D_00882FB0[i * 2];
                    func_002b2970(&v5, 26.0f, (f32)(i * 0x22 + 0x57));
                    func_003147e0(arg0, *te, v5, (s16)(te[1] + 0x168), (s16)(i * 2 + 2), 1);
                }
                if (*(s8 *)(p + 0x138) > 0) {
                    func_0032f060(arg0, 1);
                }
                func_0032f4d0(arg0);
                func_003205f0(arg0, 0x96, 0x97);
                *p = 0;
                *(p + 1) = 0x1B;
            }
            *(p + 0x13A) = 0;
            return;
        }
        break;
    case 0xC4:
        if (func_002bb680(*(p + 0xD)) != 0) {
            func_002bbcf0(*(p + 0xD));
        } else {
            func_002bb550(*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b7b0);
#endif

// FUN_0030C3C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030c3c0);

/* measured: MWCC b210 -O2, 348B / 352B window; executable bytes exact.
 * Halfword counters/bound and loop-invariant motion recover the narrowing.
 * Direct identifier comparisons let the compiler cache the masked key;
 * an explicit second identifier local instead rotates three saved registers. */
// FUN_0030F4F0
#pragma push
#pragma opt_loop_invariants on
void func_0030f4f0(u8 *task, s16 *materials) {
    s16 materialIndex;
    s16 searchIndex;
    s16 count;
    s32 equippedId;
    u8 *work;

    work = *(u8 **)(task + 0x38);
    equippedId = func_0010b460();
    count = *(s8 *)(work + 0x1A);
    if (count == 7) {
        count = 0xC;
    }
    materialIndex = 0;
    while (materialIndex < count) {
        if ((u16)equippedId != materials[materialIndex]) {
            func_0010ad80(materials[materialIndex] & 0xFFFF);
        }
        materialIndex++;
    }
    func_0010b190((u8 *)func_002e48a0(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)));
    searchIndex = 0;
    while (searchIndex < count) {
        if ((u16)equippedId == materials[searchIndex]) {
            func_0010b300(*(u16 *)(func_002e48a0(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)) + 1));
            func_0010ad80(equippedId);
            break;
        }
        searchIndex++;
    }
    func_0010b7f0();
}
#pragma pop
// FUN_0030F650 NONMATCHING
/* measured: v1 candidate — obj 899I vs retail 905I (-6I tail scheduling), probe 628 words, fnalign 150 edits (+4 reloc-only). Earliest divergence lh-vs-lhu for cls (fixed to s16 lh, -57 words 685->628); next andi-vs-dsll32 for (u16)cls (u16-alone +56, N-A per lever1 single-andi/no-CSE/no-frame+0x10), lb-vs-lbu for ste (s8 cast costless, kept). Decl-search 3 orders (all 628, no delta); jt 0,1 cases (no delta). Prior bare, no best. New levers N-A: single andi 0xFFFF (no CSE), sltiu០8 for 0..7 range (honest switch 2..7+default, jt 0,1 no delta), no adjacent-OR fold, no COP2. */
#ifdef NON_MATCHING
void func_0030f650(u8 *arg0) {
    u8 *p;
    u8 kind;
    s16 cls;
    s16 mats[12];
    s16 i;
    s16 k;
    s64 w0;
    s64 w1;
    s64 w2;
    s64 w3;
    s64 w4;
    s64 w5;
    s64 w6;
    s64 w7;
    s64 w8;
    s64 w9;
    FclByte4 c0;
    FclByte4 c1;
    FclByte4 c2;
    u8 *te;
    s32 ret;

    p = *(u8 **)(arg0 + 0x38);
    cls = *(s16 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1);
    kind = *(p + 1);
    switch (kind) {
    case 0xD2:
        if (func_003145e0(*(s32 *)(p + 0x148)) == 1) {
            break;
        }
        *(p + 1) = 0xD3;
        *(s16 *)(p + 0x2D8) = 0;
    case 0xD3:
        ret = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0xF, 0, 1);
        *(s16 *)(p + 0x2D8) = (s16)ret;
        if ((s16)ret >= 0xF) {
            func_00106390(0x5F, 1);
            func_00106390(0x59, 0);
            func_00106390(0x5B, 0);
            *(p + 1) = 0xD4;
        }
        break;
    case 0xD4:
        if (func_00285b30(*p) >= 0x2D0) {
            te = (u8 *)func_0034a630(*(s32 *)(p + 0x254));
            if (*(s8 *)te != 0) {
                *func_0034a630(*(s32 *)(p + 0x254)) = 4;
            }
            ret = func_00105f50(cls);
            if ((s8)ret > 0) {
                ret = func_00452490(*(s32 *)(p + 0x308));
                if (ret != 0) {
                    func_00452080(*(s32 *)(p + 0x308));
                    *(s32 *)(p + 0x308) = 0;
                }
            }
            *(p + 1) = 0xD5;
        }
        break;
    case 0xD5:
        if (func_00106330(0x5B) != 0) {
            *(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(p + 0xD), 0, iGpffffb440 + (s16)cls * 0x11);
            func_002badc0(*(p + 0xD), 0x49);
            *(p + 1) = 0xD6;
        }
        break;
    case 0xD6:
        if (func_002bb680(*(p + 0xD)) == 0) {
            func_002bb550(*(p + 0xD));
            *(p + 1) = 0xD7;
            func_00106390(0x59, 1);
        } else {
            func_002bbcf0(*(p + 0xD));
        }
        break;
    case 0xD7:
        ret = func_00452490(*(s32 *)(p + 0x300));
        if (ret == 1) {
            break;
        }
        if (func_00452380(D_00641BE0) != 0) {
            func_00452080(*(s32 *)(p + 0x304));
            *(s32 *)(p + 0x304) = 0;
        }
        if (func_00459760() == -1) {
            func_0045a3e0(0x14, 1);
        }
        switch (*(s8 *)(p + 0x1A)) {
        case 2:
            mats[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            mats[1] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            break;
        case 3:
            mats[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            mats[1] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x129)) + 1);
            mats[2] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            break;
        case 6:
            mats[5] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 5) + 1);
        case 5:
            mats[4] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        case 4:
            mats[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
            mats[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
            mats[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
            mats[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                mats[i] = *(u16 *)(func_002e48a0(0, i) + 1);
            }
            break;
        default:
            break;
        }
        func_0030f4f0(arg0, mats);
        if (*(s32 *)(p + 0x304) != 0) {
            func_00452080(*(s32 *)(p + 0x304));
            *(s32 *)(p + 0x304) = 0;
        }
        func_002b68d0(0x84, 0, 0);
        func_002b68d0(0x85, 0, 0);
        func_002b68d0(0x1C6, 0, 0);
        if (func_00302570(arg0) == 0) {
            if (*(s32 *)(p + 0x148) != 0) {
                *(s32 *)(p + 0x148) = 0;
            }
            *(s32 *)(p + 0x148) = func_00314320(arg0);
            func_00320970(arg0, 0);
            func_002b2970(&w0, -78.0f, -82.0f);
            func_002b6c30(0x80, w0, 0x3F, 220.0f);
            func_002b2a60(&c0, 0x49, 0x72, 0xFF, 0xFF);
            te = func_002b6150(0x80);
            *(te + 0x85) = c0.b0;
            *(te + 0x86) = c0.b1;
            *(te + 0x87) = c0.b2;
            *(te + 0x88) = c0.b3;
            func_002b6b40(0x80, 0, 0x5A0, 0, 0, 0.0f);
            func_002b68d0(0x80, 6, 0);
            *(func_002b6150(0x80) + 0xDB) = 1;
            func_002b2970(&w1, 2.0f, -2.0f);
            func_002b2970(&w2, -78.0f, -82.0f);
            func_002b69f0(0x80, w1, w2, 1, 0xA, 0);
            func_002b6a70(0x80, 0, 0xFF, 2, 0xA, 0);
            func_002b2970(&w3, 540.0f, 347.0f);
            func_002b6c30(0x20C, w3, 0x3F, 220.0f);
            func_002b2a60(&c1, 0x49, 0x72, 0xFF, 0xFF);
            te = func_002b6150(0x20C);
            *(te + 0x85) = c1.b0;
            *(te + 0x86) = c1.b1;
            *(te + 0x87) = c1.b2;
            *(te + 0x88) = c1.b3;
            func_002b6b40(0x20C, 0, 0x5A0, 0, 0, 0.0f);
            func_002b68d0(0x20C, 6, 0);
            *(func_002b6150(0x20C) + 0xDB) = 1;
            func_002b2970(&w4, 460.0f, 347.0f);
            func_002b2970(&w5, 540.0f, 347.0f);
            func_002b69f0(0x20C, w4, w5, 1, 0xA, 0);
            func_002b6a70(0x20C, 0, 0xFF, 2, 0xA, 0);
            func_002b2970(&w6, -190.0f, 200.0f);
            func_002b6c30(0x81, w6, 0x56, 215.0f);
            func_002b2a60(&c2, 0x49, 0x72, 0xFF, 0xFF);
            te = func_002b6150(0x81);
            *(te + 0x85) = c2.b0;
            *(te + 0x86) = c2.b1;
            *(te + 0x87) = c2.b2;
            *(te + 0x88) = c2.b3;
            *(f32 *)(func_002b6150(0x81) + 0xD0) = 90.0f;
            func_002b2970(&w7, D_00640C50[0], D_00640C50[1]);
            func_002b6c30(0x84, w7, 0x40, 242.0f);
            func_002b2970(&w8, D_00640C58[0], D_00640C58[1]);
            func_002b6c30(0x85, w8, 0x40, 242.0f);
            func_00315600(arg0, 0);
            func_00316e80((s32)arg0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
            func_002b2970(&w9, D_00641660[0], D_00641660[1]);
            func_002b6c30(0x1C6, w9, 0x3D, 242.0f);
            func_002b6a70(0x1C6, 0, 0x64, 0, 0xA, 0);
            *(p + 0xB4) = 0;
            *(p + 0xB5) = 0;
            *(s16 *)(p + 0xC4) = 1;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x23;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 0;
            *(s8 *)(p + 0xB5) += 1;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 2;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x38;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 1;
            *(s8 *)(p + 0xB5) += 1;
            if (func_00106330(0x1301) != 0) {
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 3;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x51;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 2;
                *(s8 *)(p + 0xB5) += 1;
            }
            if (func_00106330(0x1302) != 0) {
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 4;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x51;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 3;
                *(s8 *)(p + 0xB5) += 1;
            }
            if (func_00106330(0x1303) != 0) {
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 5;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x51;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 4;
                *(s8 *)(p + 0xB5) += 1;
            }
            if (func_00106330(0x1304) != 0) {
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 6;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x63;
                *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 5;
                *(s8 *)(p + 0xB5) += 1;
            }
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 7;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0x6E;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 6;
            *(s8 *)(p + 0xB5) += 1;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 9;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0xC2;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 7;
            *(s8 *)(p + 0xB5) += 1;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC4) = 0xB;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC6) = 0xD8;
            *(s16 *)(p + (s8)*(p + 0xB5) * 10 + 0xC8) = 8;
            *(s8 *)(p + 0xB5) += 1;
            func_002eb270(arg0, 0);
            func_003205f0(arg0, 0x96, 0);
            *p = 0;
            *(p + 1) = 0x1A;
        }
        break;
    case 0x97:
        if (func_002bb680(*(p + 0xD)) == 0) {
            func_002bb550(*(p + 0xD));
            ret = func_00302570(arg0);
            if (ret == 0) {
                *p = 0;
                *(p + 1) = 0x17;
            }
        } else {
            func_002bbcf0(*(p + 0xD));
        }
        break;
    default:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030f650);
#endif

// FUN_00310480
s32 func_00310480(void) {
    u16 *p;
    s8 *base;
    s16 i;
    s8 *e;

    if (!(func_00107ac0(0x14) & 0xFFFF)) {
        return 0;
    }
    if ((func_00107ac0(0x14) & 0xFFFF) == 0xA) {
        return 0;
    }
    base = (s8 *)D_00641880 + ((func_00107ac0(0x14) & 0xFFFF) - 1) * 48;
    for (i = 0; i < 4; i++) {
        e = base + i * 12;
        switch (e[0]) {
        case 0:
            p = func_0010ac10(*(u16 *)(e + 4));
            if (p != 0) {
                if (func_0010ce10((u8 *)p, *(u16 *)(e + 8)) == -1) {
                    return 0;
                }
                break;
            }
            return 0;
        case 1:
            if ((func_00106600(*(s16 *)(base + i * 12 + 4)) & 0xFF) < *(s16 *)(base + i * 12 + 8)) {
                return 0;
            }
            break;
        case 2:
            if ((func_00107ac0(*(u16 *)(base + i * 12 + 4)) & 0xFFFF) > *(s16 *)(base + i * 12 + 8)) {
                return 0;
            }
            break;
        case 4:
            if (*(s16 *)(e + 8) == 0) {
                if (func_00106330(*(u32 *)(e + 4)) != 0) {
                    return 0;
                }
                break;
            }
            if (*(s16 *)(e + 8) == 1 && func_00106330(*(u32 *)(e + 4)) == 0) {
                return 0;
            }
            break;
        case 3:
            if (func_00110140() > *(s16 *)(e + 8)) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
// FUN_00310700
void func_00310700(void)
{
    s16 i;
    s16 j;

    func_0044ea90(&D_00641B00[0], 0x2ABD);
    iGpffffb594 = D_008873F4[0](1, 0x3004, 0x40000);
    func_0043f9c8(iGpffffb594, 0, 0x3000);
    i = 0;
    while (i < 0x100) {
        if (func_0010fcb0(i) != 0) {
            j = (s16)i;
            func_0043f810(iGpffffb594 + (s32)j * 0x30, func_0010fcb0(j), 0x30);
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 0;
        if (func_00106330((s16)i + 0x1309) != 0) {
            *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 1;
        }
        i++;
    }
}

// FUN_00310850
void func_00310850(void)
{
    s16 i;

    if (iGpffffb594 == NULL) {
        return;
    }
    i = 0;
    while (i < 0x100) {
        func_0010fd40(iGpffffb594 + i * 0x30);
        i++;
    }
    i = 0;
    while (i < 4) {
        if (*(s8 *)((u32)iGpffffb594 + i + 0x3000) == 1) {
            func_00106620((s16)(i + 0x464), 1);
            func_00106390(i + 0x1309, 1);
        }
        i++;
    }
    jtbl_008873EC[0](iGpffffb594);
    iGpffffb594 = NULL;
}

// FUN_00310960
void func_00310960(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *p;
    s8 t;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
    t = *(s8 *)(p + 0xD);
    func_002badc0(t, (s8)arg1);
    if ((s8)arg2 == 1) {
        func_002bafc0(*(s8 *)(p + 0xD), 0);
        func_002bb0a0(*(s8 *)(p + 0xD), 0);
        func_002bbf60();
    }
}
// FUN_00310A10
void func_00310a10(u8 *arg0, s32 arg1) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    s8 *t;
    s32 s0;
    s32 s4;
    s32 s3;
    u8 x;

    s0 = D_00749480[func_002e78a0() & 0xFF] * 100 + (func_002e78e0() & 0xFF);
    x = iGpffffb3d4[(arg1 & 0xFFFF) * 14 + 2];
    t = D_00641A60 + x * 4;
    s4 = D_00749480[t[0]] * 100 + t[1];
    s3 = D_00749480[t[2]] * 100 + t[3];
    p[0xD] = func_002bab80((void *)func_00331660());
    func_002bbd80(p[0xD], 0, iGpffffb44c + (func_00109280(arg1) & 0xFF) * 21);
    if (s0 < s4) {
        func_002badc0(p[0xD], 0x2B);
    } else if (s0 >= s3) {
        func_002badc0(p[0xD], 0x2D);
    } else {
        func_002badc0(p[0xD], 0x2C);
    }
    func_002bafc0(p[0xD], 0);
    func_002bb0a0(p[0xD], 0);
    func_002bbf60();
}

// FUN_00310BF0
s32 func_00310bf0(u8 *arg0) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    u8 *q;
    u8 *t2;
    s32 r2;

    switch (p[0]) {
    case 1:
        p[0] = 2;
        if (*(u32 *)(p + 0x1C) != 0) {
            *(u32 *)(p + 0x1C) = 0;
        }
        *(u32 *)(p + 0x1C) = func_002e8410(arg0);
        break;
    case 2:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            p[0] = 0;
            p[0] = 5;
        }
        break;
    case 3:
        func_00122640(1, 0);
        p[0] = 4;
        /* fallthrough */
    case 4:
        if (func_00122720() != 0) {
            p[0] = 1;
        }
        break;
    case 5:
        func_00122520(1, 0);
        p[0] = 6;
        /* fallthrough */
    case 6:
        if (func_00122720() != 0) {
            return -1;
        }
        break;
    case 7:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
        } else {
            func_002bb550(p[0xD]);
            p[0] = 1;
        }
        break;
    case 8:
        if (func_004553c0(*(u8 **)(p + 0x10)) != 0) {
            if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                if (func_00106330(0x1459) == 0) {
                    func_00144c90(8, 3);
                    func_00144e10(1);
                }
                p[0] = 9;
                return 0;
            }
            if (func_00106330(0x413) == 0 && func_00106330(0x96F) != 0 && func_00104f10(1) >= 3) {
                if (*(u32 *)(p + 0x1C) != 0) {
                    *(u32 *)(p + 0x1C) = 0;
                }
                *(u32 *)(p + 0x1C) = func_0033e120(arg0, 0x294, 0xA);
                func_00106390(0x413, 1);
                if (!(func_00107ac0(0x14) & 0xFFFF)) {
                    func_001075d0(0x14);
                }
                p[0] = 0xB;
                func_0045a3e0(0x14, 1);
                return 0;
            }
            if (func_00106330(0x1459) == 0) {
                func_00144c90(8, 3);
                func_00144e10(1);
            }
            p[0] = 9;
        }
        break;
    case 9:
        if (func_00144f60() != 0) {
            q = func_001452b0(3);
            while (q != 0) {
                if ((*(u16 *)q & 0x3FF) == 0x38) {
                    func_00479940((u8*)*(u32 *)(q + 0x164), 0, 0xD, 0, 1);
                }
                q = *(u8 **)(q + 0x138);
            }
            if (func_00106330(0x1459) == 0) {
                func_004577d0(func_00457120(), func_0014b4d0());
                t2 = func_00457120();
                r2 = func_0014b450();
                func_003e9cb0(*(u32 *)(t2 + 4), r2, 0);
            }
            func_00331390();
            func_0045a3e0(0x14, 1);
            p[0] = 0xA;
        }
        break;
    case 10:
        if (func_00331580() != 0) {
            if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                p[0] = 0;
                p[0] = 3;
            } else if (func_00310480() == 1) {
                if (*(u32 *)(p + 0x1C) != 0) {
                    *(u32 *)(p + 0x1C) = 0;
                }
                *(u32 *)(p + 0x1C) = func_0033e120(arg0, 0x294, 1);
                p[0] = 0xE;
            } else {
                p[0] = 0;
                p[0] = 3;
            }
        }
        break;
    case 11:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            return -1;
        }
        break;
    case 12:
        if (func_00122720() != 0) {
            return -1;
        }
        break;
    case 14:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            p[0xD] = func_002bab80((void *)*(u32 *)(*(u8 **)(p + 0x10) + 0x110));
            func_002badc0(p[0xD], (func_00107ac0(0x14) & 0xFFFF) - 2);
            p[0] = 0xF;
        }
        break;
    case 15:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
        } else {
            func_002bb550(p[0xD]);
            if ((func_00107ac0(0x14) & 0xFFFF) == 0xA) {
                func_00106620(0x4A2, ((func_00106600(0x4A2) & 0xFF) + 1) & 0xFF);
            }
            p[0] = 0;
            p[0] = 1;
        }
        break;
    }
    return 0;
}
// FUN_003111D0
void func_003111d0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if (func_00106330(0x1459) == 0) {
        func_00145080();
    }
    if (func_00452380(D_00641BC8) != 0) {
        func_003315a0();
    }
    func_00454bd0(*(void **)(p + 0x10));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* measured: full body now MATCH (object 1688B, retail window 1696B).
   Retail reuses the resource pointer register as the first loop index, then
   rotates the later loop index/flag pair. Separate first/later locals,
   explicit skip labels for the b5b0 threshold guard, and the <=-equivalent
   `found > b5b0` spelling reproduce the saved-register and slt shapes. */
// FUN_00311260
s32 func_00311260(u8 *arg0)
{
    u8 *p;
    s32 i;
    s32 found;
    s32 found2;
    s32 i2;
    s32 result;

    result = (s32)arg0;
    found = 0;
    func_0044ea90(&D_00641B00[0], 0x2C88);
    p = D_008873F4[0](1, 0x2C, 0x40000);
    result = func_00451fc0(result, D_00641BE0, 0xF, 0, 0,
                           func_00310bf0, func_003111d0, p);
    p[0] = 8;
    func_00440b68(&iGpffffa8c8, D_00641B00, 0x2C96);
    *(s32 *)(p + 0x10) = func_00454a60(D_00641C00, 0);
    func_0045aac0(3, 0, 0x1E);
    *(s32 *)(p + 0x4) = 0x41000000;
    *(s32 *)(p + 0x8) = 0x41200000;
    *(u8 *)(p + 0xC) = 0;
    *(u8 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x20) = 0x41000000;
    *(s32 *)(p + 0x24) = 0x41200000;
    *(s16 *)(p + 0x28) = 0;
    if (func_00110460() != 0 &&
        func_00106330(0x1DD) != 0 &&
        func_00106330(0x1301) != 0 &&
        func_00106330(0x1302) != 0 &&
        func_00106330(0x1303) != 0) {
        func_00106390(0x1304, 1);
    }
    if (func_00106330(0x1463) != 0) {
        func_00105690(1, 0x63);
        func_00105fa0(0xF4240);
        func_00106390(0x1202, 1);
        func_00106390(0x1305, 1);
        func_00106390(0x1301, 1);
        func_00106390(0x1302, 1);
        func_00106390(0x1303, 1);
        func_00106390(0x1304, 1);
        func_00106390(0x131A, 1);
        func_00106390(0x131B, 1);
        func_00106390(0x131C, 1);
        func_00106390(0x131D, 1);
        func_00106390(0x131E, 1);
        func_00106390(0x131F, 1);
        func_00106390(0x1320, 1);
        func_00106390(0x1321, 1);
        func_00106390(0x1322, 1);
        i = 0;
        while (i < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i) + 2) == 0x36) {
                found = 1;
            }
            i++;
        }
        if ((s8)found == 0) {
            found = (u16)func_0010b6f0();
            if (found > (u16)func_0010b5b0()) {
                goto loop_92;
            }
            func_0010b010(0x36);
        }
loop_92:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0x92) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto loop_17;
            }
            func_0010b010(0x92);
        }
loop_17:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0x17) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto loop_16;
            }
            func_0010b010(0x17);
        }
loop_16:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0x16) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto loop_D;
            }
            func_0010b010(0x16);
        }
loop_D:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0xD) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto loop_E;
            }
            func_0010b010(0xD);
        }
loop_E:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0xE) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto loop_70;
            }
            func_0010b010(0xE);
        }
loop_70:
        found2 = 0;
        i2 = 0;
        while (i2 < (u16)func_0010b6f0()) {
            if (*(u16 *)((u8 *)func_0010ace0((s16)i2) + 2) == 0x70) {
                found2 = 1;
            }
            i2++;
        }
        if ((s8)found2 == 0) {
            found2 = (u16)func_0010b6f0();
            if (found2 > (u16)func_0010b5b0()) {
                goto done_70;
            }
            func_0010b010(0x70);
        }
done_70:;
    }
    return result;
}

