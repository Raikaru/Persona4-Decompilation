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

/* measured: retail 2152 instrs / object 2159 instrs (+0.3%, gate 2087-2217, mid-band), */
/* fnalign 3164 edits, frame object -0x200 exact. File idioms per 003097e0/002eb270: */
/* no (s64) first-arg casts, no &0xFFFF masks, D_ tables without (s32)&; production stays ASM. */
// FUN_002E90D0 NONMATCHING
#ifdef NON_MATCHING
void func_002e90d0(u8 *arg0)
{
    extern u8 D_00641870[];
    extern void func_00442088(void *dst, void *fmt, s32 value);
    extern char iGpffffa8a0;
    extern void func_0045af60(s32, s32, s32, s32);
    extern void func_0032fa30(u8 *, s16, u32, u32, u32);
    extern s8 func_0032fb60(s8);
    extern void func_00318840(u8 *, s8, s8, s16, s16);
    extern void func_00318f30(s16);
    extern s32 func_003190d0(u8 *);
    extern s32 func_0033e5a0(u8 *);
    extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
    extern void func_002ecfc0(u8 *);
    u8 *base;
    u8 *te;
    u8 *te2;


  u8 temp_v0;
  u8 temp_v1;
  u8 temp_v2;
  
  s8 temp_v3;
  void *pvVar6;
  s32 temp_v4;
  u32 temp_v5;
  s32 temp_v6;
  s64 temp_v7;
  s32 temp_v8;
  
  s16 temp_v9;
  s8 temp_v10;
  s32 temp_v11;
  float temp_v12;
  u8 temp_v13 [168];
  u32 uStack_e8;
  u32 uStack_e4;
  u32 uStack_e0;
  u32 uStack_dc;
  s64 stk_d8;
  s64 stk_d0;
  s64 stk_c8;
  s64 stk_c0;
  s64 stk_b8;
  s64 stk_b0;
  s64 stk_a8;
  s64 stk_a0;
  s64 stk_98;
  s64 stk_90;
  s64 stk_88;
  s64 stk_80;
  s64 stk_78;
  s64 stk_70;
  s64 stk_68;
  s32 iStack_60;
  u32 uStack_5c;
  s32 iStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u8 bStack_48;
  u8 uStack_47;
  u8 uStack_46;
  u8 uStack_45;
  u8 bStack_44;
  u8 uStack_43;
  u8 uStack_42;
  u8 uStack_41;
  u8 bStack_40;
  u8 uStack_3f;
  u8 uStack_3e;
  u8 uStack_3d;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u8 bStack_c;
  u8 uStack_b;
  u8 uStack_a;
  u8 uStack_9;
  u8 bStack_8;
  u8 uStack_7;
  u8 uStack_6;
  u8 uStack_5;
  u8 bStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  base = *(u8 **)(arg0 + 0x38);
  temp_v10 = base[1];
  if (temp_v10 == ' ') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb7]; temp_v9 = temp_v9 + 1) {
        temp_v4 = temp_v9 * 2;
        func_002b2970((s64 *)&stk_d8,26.0,(float)((temp_v9 * 0x10 + (s32)temp_v9) * 2 + 0x57));
        func_003147e0(arg0,(s8)temp_v9 + '\x04',stk_d8,*(u16 *)(base + temp_v4 + 0xb8),
                     (s16)temp_v4,0);
      }
      func_002b2a60(&bStack_40,0xc6,0xee,1,0xff);
      te = func_002b6150(((s8)base[0xb6] + 4) * 2 + 0x1f5);
      *(u8 *)(te + 0x85) = bStack_40;
      *(u8 *)(te + 0x86) = uStack_3f;
      *(u8 *)(te + 0x87) = uStack_3e;
      *(u8 *)(te + 0x88) = uStack_3d;
      te2 = func_002b6150(((s8)base[0xb6] + 4) * 2 + 500);
      temp_v0 = *(u8 *)(te + 0x86);
      temp_v1 = *(u8 *)(te + 0x87);
      temp_v2 = *(u8 *)(te + 0x88);
      *(u8 *)(te2 + 0x85) = *(u8 *)(te + 0x85);
      *(u8 *)(te2 + 0x86) = temp_v0;
      *(u8 *)(te2 + 0x87) = temp_v1;
      *(u8 *)(te2 + 0x88) = temp_v2;
      func_002b2a60(&bStack_44,0x2d,0x2d,0x2d,0xff);
      te = func_002b6150(*(u16 *)(base + (s8)base[0xb6] * 2 + 0xb8));
      *(u8 *)(te + 0x85) = bStack_44;
      *(u8 *)(te + 0x86) = uStack_43;
      *(u8 *)(te + 0x87) = uStack_42;
      *(u8 *)(te + 0x88) = uStack_41;
      func_002b2a60(&bStack_48,0x92,200,7,0xff);
      te = func_002b6150((s8)base[0xb6] + 0x2ff);
      *(u8 *)(te + 0x85) = bStack_48;
      *(u8 *)(te + 0x86) = uStack_47;
      *(u8 *)(te + 0x87) = uStack_46;
      *(u8 *)(te + 0x88) = uStack_45;
      base[1] = 0x1b;
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x1b') {
    te = func_002b6150(((s8)base[0xb7] + 3) * 2 + 500);
    temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
    if (temp_v9 != 1) {
      if ((D_008C027A[0] & 0x1000) == 0) {
        if ((D_008C027A[0] & 0x4000) == 0) {
          if ((D_008C024E[0] & 0x40) == 0) {
            if ((D_008C024E[0] & 0x20) != 0) {
              for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb7]; temp_v9 = temp_v9 + 1) {
                temp_v11 = temp_v9 + 4;
                te = func_002b6150((s16)temp_v11 * 2 + 500);
                uStack_e0 = *(u32 *)(temp_v4 + 0x38);
                uStack_dc = *(u32 *)(temp_v4 + 0x3c);
                temp_v8 = temp_v9 * 2;
                func_003147e0(arg0,(s8)temp_v11,*(u64 *)(temp_v4 + 0x38),
                             *(u16 *)(base + temp_v8 + 0xb8),(s16)temp_v8,1);
              }
              func_00315310(arg0,3);
              te = func_002b6150(0x1c6);
              func_002b6a70(0x1c6,(u32)*(u8 *)(te + 0x6e),0,0,10,0);
              func_003205f0(arg0,0x92,0x96);
              temp_v4 = func_00302570(arg0);
              if (temp_v4 == 0) {
                base[1] = 0x18;
              }
              func_0045af60(0,0,0,2);
            }
          }
          else {
            func_0045af60(0,0,0,1);
            if ((s8)base[0xb6] == (s32)((s8)base[0xb7] - 1)) {
              for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb7]; temp_v9 = temp_v9 + 1) {
                temp_v11 = temp_v9 + 4;
                te = func_002b6150((s16)temp_v11 * 2 + 500);
                uStack_50 = *(u32 *)(temp_v4 + 0x38);
                uStack_4c = *(u32 *)(temp_v4 + 0x3c);
                temp_v8 = temp_v9 * 2;
                func_003147e0(arg0,(s8)temp_v11,*(u64 *)(temp_v4 + 0x38),
                             *(u16 *)(base + temp_v8 + 0xb8),(s16)temp_v8,1);
              }
              func_00315310(arg0,3);
              func_003205f0(arg0,0x92,0x96);
              te = func_002b6150(0x1c6);
              func_002b6a70(0x1c6,(u32)*(u8 *)(te + 0x6e),0,0,10,0);
              temp_v4 = func_00302570(arg0);
              if (temp_v4 == 0) {
                base[1] = 0x18;
              }
            }
            else {
              for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb7]; temp_v9 = temp_v9 + 1) {
                temp_v11 = temp_v9 + 4;
                te = func_002b6150((s16)temp_v11 * 2 + 500);
                uStack_e8 = *(u32 *)(temp_v4 + 0x38);
                uStack_e4 = *(u32 *)(temp_v4 + 0x3c);
                temp_v8 = temp_v9 * 2;
                func_003147e0(arg0,(s8)temp_v11,*(u64 *)(temp_v4 + 0x38),
                             *(u16 *)(base + temp_v8 + 0xb8),(s16)temp_v8,1);
              }
              temp_v10 = base[0xb6];
              if (temp_v10 == '\x04') {
                temp_v6 = func_00106330(0x1305);
                if (temp_v6 != 0) {
                  func_00315310(arg0,3);
                  func_003205f0(arg0,0x92,0x96);
                  temp_v4 = func_00302570(arg0);
                  if (temp_v4 == 0) {
                    base[1] = 0x18;
                  }
                }
              }
              else if (temp_v10 == '\x03') {
                temp_v6 = func_00106330(0x1305);
                if (temp_v6 == 0) {
                  func_00315310(arg0,3);
                  func_003205f0(arg0,0x92,0x96);
                  temp_v4 = func_00302570(arg0);
                  if (temp_v4 == 0) {
                    base[1] = 0x18;
                  }
                }
                else {
                  *base = 10;
                  base[1] = 0xc2;
                }
              }
              else if (temp_v10 == '\x02') {
                temp_v6 = func_00106330(0x1305);
                if (temp_v6 == 0) {
                  *base = 10;
                  base[1] = 0xc2;
                }
                else {
                  *base = 8;
                  base[1] = 0x75;
                }
              }
              else if (temp_v10 == '\x01') {
                base[1] = 0x8a;
                *base = 0x10;
                func_003205f0(arg0,0x118,0x96);
              }
              else if (temp_v10 == '\0') {
                base[1] = 0x8a;
                *base = 0xf;
                func_003205f0(arg0,0x117,0x96);
              }
            }
          }
        }
        else {
          func_0045af60(0,0,0,0);
          temp_v3 = func_0032fb60(base[0xb6]);
          func_002b2a60((s64 *)&uStack_28,0,0,0x66,0xff);
          func_002b2a60((s64 *)&uStack_2c,0xcc,0xff,0xff,0xff);
          func_002b2a60((s64 *)&uStack_30,0x25,0x2f,0x94,0xff);
          func_0032fa30(arg0,(s16)temp_v3,uStack_28,uStack_2c,uStack_30);
          temp_v6 = func_00106330(0x1306);
          if (temp_v6 == 0) {
            temp_v4 = func_002b2cb0((s8)base[0xb6],1,(s32)(s16)((s8)base[0xb7] - 1),0,2
                                 );
            base[0xb6] = (s8)temp_v4;
          }
          else {
            temp_v4 = func_002b2cb0((s8)base[0xb6],1,(s32)(s16)((s8)base[0xb7] - 2),0,2
                                 );
            base[0xb6] = (s8)temp_v4;
          }
          temp_v3 = func_0032fb60(base[0xb6]);
          func_002b2a60((s64 *)&uStack_34,0xc6,0xee,1,0xff);
          func_002b2a60((s64 *)&uStack_38,0x2d,0x2d,0x2d,0xff);
          func_002b2a60((s64 *)&uStack_3c,0x92,200,7,0xff);
          func_0032fa30(arg0,(s16)temp_v3,uStack_34,uStack_38,uStack_3c);
        }
      }
      else {
        func_0045af60(0,0,0,0);
        temp_v3 = func_0032fb60(base[0xb6]);
        func_002b2a60((s64 *)&uStack_10,0,0,0x66,0xff);
        func_002b2a60((s64 *)&uStack_14,0xcc,0xff,0xff,0xff);
        func_002b2a60((s64 *)&uStack_18,0x25,0x2f,0x94,0xff);
        func_0032fa30(arg0,(s16)temp_v3,uStack_10,uStack_14,uStack_18);
        temp_v6 = func_00106330(0x1306);
        if (temp_v6 == 0) {
          temp_v4 = func_002b2d00((s8)base[0xb6],1,0,(s32)(s16)((s8)base[0xb7] - 1),2);
          base[0xb6] = (s8)temp_v4;
        }
        else {
          temp_v4 = func_002b2d00((s8)base[0xb6],1,0,(s32)(s16)((s8)base[0xb7] - 2),2);
          base[0xb6] = (s8)temp_v4;
        }
        temp_v3 = func_0032fb60(base[0xb6]);
        func_002b2a60((s64 *)&uStack_1c,0xc6,0xee,1,0xff);
        func_002b2a60((s64 *)&uStack_20,0x2d,0x2d,0x2d,0xff);
        func_002b2a60((s64 *)&uStack_24,0x92,200,7,0xff);
        func_0032fa30(arg0,(s16)temp_v3,uStack_1c,uStack_20,uStack_24);
      }
    }
  }
  else if (temp_v10 == '\x1c') {
    func_002eb270(arg0,1);
    *base = (s8)*(u16 *)(base + (s8)base[0xb4] * 10 + 0xc4);
    base[1] = (s8)*(u16 *)(base + (s8)base[0xb4] * 10 + 0xc6);
  }
  else if (temp_v10 == '\x1a') {
    temp_v4 = func_003190d0(arg0);
    if (temp_v4 != 1) {
      func_002b6140(*(s32 *)(base + 0x28c),0);
      func_002b6140(*(s32 *)(base + 0x290),0);
      if ((D_008C027A[0] & 0x8000) == 0) {
        if ((D_008C027A[0] & 0x2000) == 0) {
          if ((D_008C024E[0] & 0x40) == 0) {
            if ((D_008C024E[0] & 0x20) != 0) {
              func_002b68d0(0x2f2,0,1);
              temp_v4 = func_00302570(arg0);
              if (temp_v4 == 0) {
                base[1] = 0x18;
              }
              func_002eb270(arg0,1);
              func_0045af60(0,0,0,2);
              func_00315310(arg0,0);
              func_003205f0(arg0,0x92,0x96);
              te = func_002b6150(0x1c6);
              func_002b6a70(0x1c6,(u32)*(u8 *)(te + 0x6e),0,0,10,0);
            }
          }
          else {
            func_002b68d0(0x2f2,0,1);
            func_0045af60(0,0,0,1);
            if (*(s16 *)(base + (s8)base[0xb4] * 10 + 200) == 8) {
              temp_v4 = func_00302570(arg0);
              if (temp_v4 == 0) {
                base[1] = 0x18;
              }
              func_002eb270(arg0,1);
              func_00315310(arg0,0);
              func_003205f0(arg0,0x92,0x96);
              te = func_002b6150(0x1c6);
              func_002b6a70(0x1c6,(u32)*(u8 *)(te + 0x6e),0,0,10,0);
            }
            else {
              base[1] = 0x1c;
            }
          }
        }
        else {
          temp_v4 = func_002b2cb0((s8)base[0xb4],1,(s8)base[0xb5] - 1,0,2);
          base[0xb4] = (s8)temp_v4;
          func_00318f30(*(s16 *)(base + (s8)temp_v4 * 10 + 200));
          func_0045af60(0,0,0,0);
          for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb5]; temp_v9 = temp_v9 + 1) {
            func_00318840(arg0,(s8)temp_v9,base[temp_v9 * 10 + 200],
                         *(u16 *)(base + temp_v9 * 10 + 0xca),
                         *(u16 *)(base + temp_v9 * 10 + 0xcc));
          }
        }
      }
      else {
        temp_v4 = func_002b2d00((s8)base[0xb4],1,0,(s8)base[0xb5] - 1,2);
        base[0xb4] = (s8)temp_v4;
        func_00318f30(*(s16 *)(base + (s8)temp_v4 * 10 + 200));
        func_0045af60(0,0,0,0);
        for (temp_v9 = 0; (s32)temp_v9 < (s8)base[0xb5]; temp_v9 = temp_v9 + 1) {
          func_00318840(arg0,(s8)temp_v9,base[temp_v9 * 10 + 200],
                       *(u16 *)(base + temp_v9 * 10 + 0xca),
                       *(u16 *)(base + temp_v9 * 10 + 0xcc));
        }
      }
    }
  }
  else if (temp_v10 == -0x69) {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      temp_v4 = func_00302570(arg0);
      if (temp_v4 == 0) {
        base[1] = 0x18;
      }
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x19') {
    te = func_002b6150(500);
    temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
    if (temp_v9 != 1) {
      te = func_002b6150(0x92);
      temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
      if (temp_v9 != 1) {
        *base = 0xb;
      }
    }
  }
  else if (temp_v10 == '!') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      func_002b2970((s64 *)&stk_d0,D_00641660[0],D_00641660[1]);
      func_002b6c30(0x1c6,stk_d0,0x3d,242.0f);
      func_002b6a70(0x1c6,0,100,0,10,0);
      base[0xb6] = 0;
      func_0032f4d0(arg0);
      func_003205f0(arg0,0x96,0x92);
      base[1] = 0x1b;
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\"') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      func_002ecfc0(arg0);
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x18') {
    te = func_002b6150(500);
    temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
    if (temp_v9 != 1) {
      te = func_002b6150(0x1f6);
      temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
      if (temp_v9 != 1) {
        te = func_002b6150(0x1f8);
        temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
        if (temp_v9 != 1) {
          te = func_002b6150(0x1fa);
          temp_v9 = func_002b6970(*(s16 *)(temp_v4 + 0x10),1);
          if ((temp_v9 != 1) && (temp_v4 = func_003190d0(arg0), temp_v4 != 1)) {
            if ((D_008C027A[0] & 0x1000) == 0) {
              if ((D_008C027A[0] & 0x4000) == 0) {
                if ((D_008C024E[0] & 0x40) == 0) {
                  if ((D_008C024E[0] & 0x20) != 0) {
                    func_00315600(arg0,1);
                    func_00320970(arg0,1);
                    func_003205f0(arg0,0,0x92);
                    func_00316e80((s32)arg0,1,1,1,1,0,0,0,0,0,0);
                    func_002b6a70(0x81,0xff,0,0,6,0);
                    func_002b6a70(0x80,0xff,0,2,10,0);
                    func_002b6a70(0x20c,0xff,0,2,10,0);
                    func_002b6a70(0x84,0xff,0,0,6,0);
                    func_002b6a70(0x85,0xff,0,0,6,0);
                    for (temp_v9 = 0; temp_v9 < 3; temp_v9 = temp_v9 + 1) {
                      func_002b2970((s64 *)&stk_c8,26.0,(float)(temp_v9 * 0x22 + 0x57));
                      func_003147e0(arg0,(s8)temp_v9,stk_c8,
                                   *(u16 *)(base + temp_v9 * 2 + 0xb8),0,1);
                    }
                    base[1] = 0x19;
                    func_0045af60(0,0,0,2);
                  }
                }
                else {
                  func_0045af60(0,0,0,1);
                  for (temp_v9 = 0; temp_v9 < 3; temp_v9 = temp_v9 + 1) {
                    temp_v4 = temp_v9 * 2;
                    func_002b2970((s64 *)&stk_b0,26.0,
                                  (float)((temp_v9 * 0x10 + (s32)temp_v9) * 2 + 0x57));
                    func_003147e0(arg0,(s8)temp_v9,stk_b0,
                                 *(u16 *)(base + temp_v4 + 0xb8),(s16)temp_v4,1);
                  }
                  temp_v10 = base[0xb3];
                  if (temp_v10 == '\x02') {
                    func_00315600(arg0,1);
                    func_00320970(arg0,1);
                    func_003205f0(arg0,0,0x92);
                    func_00316e80((s32)arg0,1,1,1,1,0,0,0,0,0,0);
                    func_002b6a70(0x81,0xff,0,0,6,0);
                    func_002b6a70(0x80,0xff,0,2,10,0);
                    func_002b6a70(0x20c,0xff,0,2,10,0);
                    func_002b6a70(0x84,0xff,0,0,6,0);
                    func_002b6a70(0x85,0xff,0,0,6,0);
                    for (temp_v9 = 0; temp_v9 < 3; temp_v9 = temp_v9 + 1) {
                      func_002b2970((s64 *)&stk_c0,26.0,(float)(temp_v9 * 0x22 + 0x57));
                      func_003147e0(arg0,(s8)temp_v9,stk_c0,
                                   *(u16 *)(base + temp_v9 * 2 + 0xb8),0,1);
                    }
                    base[1] = 0x19;
                  }
                  else if (temp_v10 == '\x01') {
                    temp_v6 = func_00106330(0x131b);
                    if (temp_v6 == 0) {
                      pvVar6 = (void *)func_00331660();
                      temp_v7 = func_002bab80(pvVar6);
                      base[0xd] = (s8)temp_v7;
                      func_002badc0((s8)temp_v7,0x4f);
                      func_00106390(0x131b,1);
                      base[1] = 0x21;
                    }
                    else {
                      func_002b2970((s64 *)&stk_b8,D_00641660[0],D_00641660[1]);
                      func_002b6c30(0x1c6,stk_b8,0x3d,242.0f);
                      func_002b6a70(0x1c6,0,100,0,10,0);
                      base[0xb6] = 0;
                      func_0032f4d0(arg0);
                      func_003205f0(arg0,0x96,0x92);
                      base[1] = 0x1b;
                    }
                  }
                  else if (temp_v10 == '\0') {
                    temp_v6 = func_00106330(0x131e);
                    if (temp_v6 == 0) {
                      pvVar6 = (void *)func_00331660();
                      temp_v7 = func_002bab80(pvVar6);
                      base[0xd] = (s8)temp_v7;
                      func_002badc0((s8)temp_v7,0x4d);
                      func_00106390(0x131e,1);
                      base[1] = 0x22;
                    }
                    else {
                      func_002ecfc0(arg0);
                    }
                  }
                }
              }
              else {
                func_00317410(arg0,0);
              }
            }
            else {
              func_00317410(arg0,1);
            }
          }
        }
      }
    }
  }
  else if (temp_v10 == '\x17') {
    temp_v4 = func_0033e5a0(*(u8 **)(base + 0x250));
    if (temp_v4 != 0) {
      temp_v4 = func_00314320(arg0);
      *(s32 *)(base + 0x148) = temp_v4;
      func_00320970(arg0,0);
      func_00315310(arg0,0);
      func_002b2970((s64 *)&stk_68,-78.0,-82.0);
      func_002b6c30(0x80,stk_68,0x3f,220.0f);
      func_002b2a60(&bStack_4,0x49,0x72,0xff,0xff);
      te = func_002b6150(0x80);
      *(u8 *)(te + 0x85) = bStack_4;
      *(u8 *)(te + 0x86) = uStack_3;
      *(u8 *)(te + 0x87) = uStack_2;
      *(u8 *)(te + 0x88) = uStack_1;
      func_002b6b40(0x80,0,0x5a0,0,0.0,-360.0);
      func_002b68d0(0x80,6,0);
      te = func_002b6150(0x80);
      *(u8 *)(te + 0xdb) = 1;
      func_002b2970((s64 *)&stk_70,2.0,-2.0);
      func_002b2970((s64 *)&stk_78,-78.0,-82.0);
      func_002b69f0(0x80,stk_70,stk_78,1,10,0);
      func_002b6a70(0x80,0,0xff,2,10,0);
      func_002b2970((s64 *)&stk_80,540.0,347.0);
      func_002b6c30(0x20c,stk_80,0x3f,220.0f);
      func_002b2a60(&bStack_8,0x49,0x72,0xff,0xff);
      te = func_002b6150(0x20c);
      *(u8 *)(te + 0x85) = bStack_8;
      *(u8 *)(te + 0x86) = uStack_7;
      *(u8 *)(te + 0x87) = uStack_6;
      *(u8 *)(te + 0x88) = uStack_5;
      func_002b6b40(0x20c,0,0x5a0,0,0.0,-360.0);
      func_002b68d0(0x20c,6,0);
      te = func_002b6150(0x20c);
      *(u8 *)(te + 0xdb) = 1;
      func_002b2970((s64 *)&stk_88,460.0,267.0);
      func_002b2970((s64 *)&stk_90,540.0,347.0);
      func_002b69f0(0x20c,stk_88,stk_90,1,10,0);
      func_002b6a70(0x20c,0,0xff,2,10,0);
      func_002b2970((s64 *)&stk_98,-190.0,200.0);
      func_002b6c30(0x81,stk_98,0x56,215.0f);
      func_002b2a60(&bStack_c,0x49,0x72,0xff,0xff);
      te = func_002b6150(0x81);
      *(u8 *)(te + 0x85) = bStack_c;
      *(u8 *)(te + 0x86) = uStack_b;
      *(u8 *)(te + 0x87) = uStack_a;
      *(u8 *)(te + 0x88) = uStack_9;
      func_002b6a70(0x81,0,0xff,0,10,0);
      te = func_002b6150(0x81);
      *(u32 *)(temp_v4 + 0xd0) = 0x42b40000;
      func_002b2970((s64 *)&stk_a0,D_00640C50[0],D_00640C50[1]);
      func_002b6c30(0x84,stk_a0,0x40,217.0f);
      func_002b6a70(0x84,0,0xff,0,10,0);
      func_002b2970((s64 *)&stk_a8,D_00640C58[0],D_00640C58[1]);
      func_002b6c30(0x85,stk_a8,0x40,218.0f);
      func_002b6a70(0x85,0,0xff,0,10,0);
      func_00315600(arg0,0);
      func_003205f0(arg0,0x92,0);
      func_00316e80((s32)arg0,1,0,1,0,0,0,0,0,0,0);
      base[0x138] = 0;
      temp_v6 = func_00106330(0x1305);
      if ((temp_v6 != 0) && (temp_v6 = func_00106330(0x1308), temp_v6 == 0)) {
        base[0x138] = base[0x138] | 2;
      }
      temp_v4 = func_00302570(arg0);
      if (temp_v4 == 0) {
        base[1] = 0x18;
      }
    }
  }
  else if (temp_v10 == '\x16') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      func_00106390(*(s32 *)(D_00641870 + (s8)base[0x13f]*8 + 4),1);
      temp_v10 = -1;
      for (temp_v9 = 0; temp_v9 < 2; temp_v9 = temp_v9 + 1) {
        temp_v6 = func_00106330(*(u32 *)(D_00641870 + temp_v9*8 + 4));
        if ((temp_v6 == 0) &&
           (temp_v12 = func_00109190(), (float)(s32)*(s8 *)(D_00641870 + temp_v9*8) <= temp_v12 * 100.0
           )) {
          temp_v10 = (s8)temp_v9;
        }
      }
      base[0x13f] = temp_v10;
      if (temp_v10 == -1) {
        base[1] = 0x17;
      }
      else {
        temp_v4 = temp_v10 * 8;
        pvVar6 = (void *)func_00331660();
        temp_v7 = func_002bab80(pvVar6);
        base[0xd] = (s8)temp_v7;
        iStack_60 = (s32)*(s16 *)(D_00641870 + temp_v4 + 2);
        uStack_5c = 0;
        func_002bbd80((s8)base[0xd], 0, &iStack_60);
        func_002badc0((s8)base[0xd],9);
        temp_v5 = func_00106600(*(s16 *)(D_00641870 + temp_v4 + 2));
        func_00106620((s32)*(s16 *)(D_00641870 + temp_v4 + 2),((temp_v5 & 0xff) + 1) & 0xff);
      }
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x15') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      temp_v4 = (s8)base[0x13f] * 8;
      pvVar6 = (void *)func_00331660();
      temp_v7 = func_002bab80(pvVar6);
      base[0xd] = (s8)temp_v7;
      iStack_58 = (s32)*(s16 *)(D_00641870 + temp_v4 + 2);
      uStack_54 = 0;
      func_002bbd80((s8)base[0xd], 0, &iStack_58);
      func_002badc0((s8)base[0xd],9);
      temp_v5 = func_00106600(*(s16 *)(D_00641870 + temp_v4 + 2));
      func_00106620((s32)*(s16 *)(D_00641870 + temp_v4 + 2),((temp_v5 & 0xff) + 1) & 0xff);
      base[1] = 0x16;
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x14') {
    temp_v10 = -1;
    for (temp_v9 = 0; temp_v9 < 2; temp_v9 = temp_v9 + 1) {
      temp_v6 = func_00106330(*(u32 *)(D_00641870 + temp_v9*8 + 4));
      if ((temp_v6 == 0) &&
         (temp_v12 = func_00109190(), (float)(s32)*(s8 *)(D_00641870 + temp_v9*8) <= temp_v12 * 100.0))
      {
        temp_v10 = (s8)temp_v9;
      }
    }
    base[0x13f] = temp_v10;
    if (temp_v10 == -1) {
      base[1] = 0x17;
    }
    else {
      pvVar6 = (void *)func_00331660();
      temp_v7 = func_002bab80(pvVar6);
      base[0xd] = (s8)temp_v7;
      func_00442088(temp_v13,&iGpffffa8a0,*(u8 *)(D_00641870 + temp_v10*8));
      func_002bbd80((s8)base[0xd], 0, temp_v13);
      temp_v12 = func_00109190();
      if (1.0 <= temp_v12) {
        func_002badc0((s8)base[0xd],8);
      }
      else {
        func_002badc0((s8)base[0xd],7);
      }
      base[1] = 0x15;
    }
  }
  else if (temp_v10 == '\x13') {
    temp_v4 = func_002bb680((s8)base[0xd]);
    if (temp_v4 == 0) {
      func_002bb550((s8)base[0xd]);
      base[1] = 0x12;
    }
    else {
      func_002bbcf0((s8)base[0xd]);
    }
  }
  else if (temp_v10 == '\x12') {
    base[1] = 0x14;
    temp_v6 = func_00106330(0x131d);
    if (temp_v6 == 0) {
      pvVar6 = (void *)func_00331660();
      temp_v7 = func_002bab80(pvVar6);
      base[0xd] = (s8)temp_v7;
      func_002badc0((s8)temp_v7,0x4c);
      func_00106390(0x131d,1);
      base[1] = 0x13;
    }
  }
  else if (temp_v10 == '\x11') {
    base[1] = 0x12;
  }
  return;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e90d0);
#endif

/* measured: GUARDED_SCORE 1719 via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombine.c func_002eb270 --candidate v11=/var/tmp/eb270/cand_eb270_v11_nocast.c` (baseline s64 2033 -> s32 1978 -> nocast 1902 inside); obj 1902I / retail 1876I (+26, +1.39% PASS, band 1820-1932, headroom 30). fnalign 2064 edits +6 reloc-only via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombine.c func_002eb270 --candidate /var/tmp/eb270/cand_eb270_v11_nocast.c --quiet`. m2c oracle from src/generated/code1_002e.c de-noised to file idiom (s64 stk[70] array forces distinct stack slots vs overlaid 0x180 frame, D_ tables without (s32)&, no (s64) first-arg casts, no &0xFFFF masks; s16 decl variant 2023-2049 outside, s64 baseline 2033 outside). No large hole: all 35x 317900 + 70x 22970 + 19x 3b7060 call sites present. */
// FUN_002EB270 NONMATCHING
#ifdef NON_MATCHING
void func_002eb270(u8 *arg0, s32 arg1) {
    extern u8 D_006407F0[];
    s64 stk[70];
    s32 var_3;
    s32 temp_16_10;
    s32 temp_16_11;
    s32 temp_16_12;
    s32 temp_16_13;
    s32 temp_16_14;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_7;
    s32 temp_16_8;
    s32 temp_17;
    s32 temp_17_10;
    s32 temp_17_2;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_18_4;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 temp_20_4;
    s32 temp_20_5;
    s32 temp_20_6;
    s32 temp_22;
    s32 temp_22_10;
    s32 temp_22_11;
    s32 temp_22_12;
    s32 temp_22_13;
    s32 temp_22_2;
    s32 temp_22_3;
    s32 temp_22_4;
    s32 temp_22_5;
    s32 temp_22_6;
    s32 temp_22_7;
    s32 temp_22_8;
    s32 temp_22_9;
    s32 temp_3;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s8 temp_4;
    u8 *temp_16;
    u8 *temp_16_6;
    u8 *temp_16_9;
    u8 *temp_17_11;
    u8 *temp_17_12;
    u8 *temp_17_3;
    u8 *temp_17_4;
    u8 *temp_17_5;
    u8 *temp_17_8;
    u8 *temp_19;
    u8 *temp_4_10;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_4_9;

    temp_19 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x38))));
    temp_4 = ((*( s8 * )((u8 *)(temp_19) + (0xB5))));
    var_3 = temp_4 & 1;
    if ((temp_4 < 0) && (var_3 != 0)) {
        var_3 -= 2;
    }
    if (var_3 == 0) {
        if (temp_4 == 6) {
            var_18 = 0;
            temp_17 = (arg1);
loop_10:
            temp_20 = (var_18);
            if (temp_20 < 3) {
                temp_16 = (u8 *)(D_00640760 + ((temp_20 + 1) * 0xC));
                if (temp_17 == 0) {
                    temp_20_2 = (var_18);
                    func_002b2970(&stk[69], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_002b2970(&stk[68], (*( f32 * )((u8 *)(temp_16) + (0))), (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_00317900(arg0, stk[69], stk[68], (var_18), ((temp_20_2 * 4)), ((((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57)));
                    temp_4_2 = (u8 *)(temp_19 + (temp_20_2 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_2) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_2) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57);
                } else {
                    temp_22 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[67], (*( f32 * )((u8 *)(temp_16) + (0))), (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_002b2970(&stk[66], -300.0f, (*( f32 * )((u8 *)(temp_16) + (4))) + (f32) temp_22);
                    func_00317900(arg0, stk[67], stk[66], (var_18), ((temp_20 * 2)), ((((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57)));
                }
                var_18 = ((var_18 + 1));
                goto loop_10;
            }
            if (temp_17 == 0) {
                func_002b2970(&stk[65], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_002b2970(&stk[64], (*( f32 * )((u8 *)(&D_006407A8) + (0))), (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_00317900(arg0, stk[65], stk[64], 8, 2, ((((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xFC))) = (s16) (((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xFE))) = (s16) ((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57);
            } else {
                temp_16_2 = (((func_003b7060() % 300U) - 0x96));
                func_002b2970(&stk[63], (*( f32 * )((u8 *)(&D_006407A8) + (0))), (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_002b2970(&stk[62], 700.0f, (*( f32 * )((u8 *)(&D_006407A8) + (4))) + (f32) temp_16_2);
                func_00317900(arg0, stk[63], stk[62], 8, 1, ((((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57)));
            }
            if (temp_17 == 0) {
                func_002b2970(&stk[61], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_002b2970(&stk[60], (*( f32 * )((u8 *)(&D_0064079C) + (0))), (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_00317900(arg0, stk[61], stk[60], 7, 6, ((((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57);
            } else {
                temp_18 = (((func_003b7060() % 300U) - 0x96));
                func_002b2970(&stk[59], (*( f32 * )((u8 *)(&D_0064079C) + (0))), (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_002b2970(&stk[58], 700.0f, (*( f32 * )((u8 *)(&D_0064079C) + (4))) + (f32) temp_18);
                func_00317900(arg0, stk[59], stk[58], 7, 3, ((((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57)));
            }
            if (temp_17 == 0) {
                func_002b2970(&stk[57], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970(&stk[56], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_00317900(arg0, stk[57], stk[56], 6, 0xA, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xE8))) = (s16) (((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xEA))) = (s16) ((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57);
            } else {
                temp_17_2 = (((func_003b7060() % 300U) - 0x96));
                func_002b2970(&stk[55], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970(&stk[54], 700.0f, (*( f32 * )((u8 *)(&D_00640790) + (4))) + (f32) temp_17_2);
                func_00317900(arg0, stk[55], stk[54], 6, 5, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
            }
        } else if (temp_4 == 8) {
            var_18_2 = 0;
            temp_16_3 = (arg1);
loop_26:
            temp_20_3 = (var_18_2);
            if (temp_20_3 < 4) {
                temp_17_3 = (u8 *)(D_00640760 + (temp_20_3 * 0xC));
                if (temp_16_3 == 0) {
                    temp_20_4 = (var_18_2);
                    func_002b2970(&stk[53], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_002b2970(&stk[52], (*( f32 * )((u8 *)(temp_17_3) + (0))), (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_00317900(arg0, stk[53], stk[52], (var_18_2), ((temp_20_4 * 4)), ((((*( s16 * )((u8 *)(temp_17_3) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_3) + (0xA))) + 0x57)));
                    temp_4_3 = (u8 *)(temp_19 + (temp_20_4 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_3) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_3) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_3) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_3) + (0xA))) + 0x57);
                } else {
                    temp_22_2 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[51], (*( f32 * )((u8 *)(temp_17_3) + (0))), (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_002b2970(&stk[50], -300.0f, (*( f32 * )((u8 *)(temp_17_3) + (4))) + (f32) temp_22_2);
                    func_00317900(arg0, stk[51], stk[50], (var_18_2), ((temp_20_3 * 2)), ((((*( s16 * )((u8 *)(temp_17_3) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_3) + (0xA))) + 0x57)));
                }
                var_18_2 = ((var_18_2 + 1));
                goto loop_26;
            }
            var_18_3 = 0;
loop_32:
            temp_3 = (var_18_3);
            if (temp_3 < 3) {
                temp_17_4 = (u8 *)(D_00640760 + ((7 - temp_3) * 0xC));
                if (temp_16_3 == 0) {
                    temp_20_5 = (var_18_3);
                    func_002b2970(&stk[49], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_002b2970(&stk[48], (*( f32 * )((u8 *)(temp_17_4) + (0))), (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_00317900(arg0, stk[49], stk[48], ((8 - temp_20_5)), (((temp_20_5 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57)));
                    temp_4_4 = (u8 *)(temp_19 + ((7 - temp_20_5) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_4) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_4) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57);
                } else {
                    temp_22_3 = (((func_003b7060() % 300U) - 0x96));
                    temp_20_6 = (var_18_3);
                    func_002b2970(&stk[47], (*( f32 * )((u8 *)(temp_17_4) + (0))), (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_002b2970(&stk[46], 700.0f, (*( f32 * )((u8 *)(temp_17_4) + (4))) + (f32) temp_22_3);
                    func_00317900(arg0, stk[47], stk[46], ((8 - temp_20_6)), (((temp_20_6 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57)));
                }
                var_18_3 = ((var_18_3 + 1));
                goto loop_32;
            }
            if (temp_16_3 == 0) {
                func_002b2970(&stk[45], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970(&stk[44], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_00317900(arg0, stk[45], stk[44], 4, 0xE, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57);
            } else {
                temp_16_4 = (((func_003b7060() % 300U) - 0x96));
                func_002b2970(&stk[43], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970(&stk[42], 700.0f, (*( f32 * )((u8 *)(&D_00640790) + (4))) + (f32) temp_16_4);
                func_00317900(arg0, stk[43], stk[42], 4, 7, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
            }
        }
    } else {
        switch (temp_4) {                           /* irregular */
        case 5:
            var_20 = 0;
            temp_18_2 = (arg1);
loop_45:
            temp_16_5 = (var_20);
            if (temp_16_5 < 2) {
                temp_17_5 = (u8 *)(D_006407C0 + ((temp_16_5 + 2) * 0xC));
                if (temp_18_2 == 0) {
                    temp_22_4 = (var_20);
                    func_002b2970(&stk[41], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_002b2970(&stk[40], (*( f32 * )((u8 *)(temp_17_5) + (0))), (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_00317900(arg0, stk[41], stk[40], (var_20), ((temp_22_4 * 4)), ((((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57)));
                    temp_4_5 = (u8 *)(temp_19 + (temp_22_4 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_5) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_5) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57);
                } else {
                    temp_22_5 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[39], (*( f32 * )((u8 *)(temp_17_5) + (0))), (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_002b2970(&stk[38], -300.0f, (*( f32 * )((u8 *)(temp_17_5) + (4))) + (f32) temp_22_5);
                    func_00317900(arg0, stk[39], stk[38], (var_20), ((temp_16_5 * 2)), ((((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57)));
                }
                temp_16_6 = (u8 *)(D_006407C0 + ((6 - temp_16_5) * 0xC));
                if (temp_18_2 == 0) {
                    temp_17_6 = (var_20);
                    func_002b2970(&stk[37], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_002b2970(&stk[36], (*( f32 * )((u8 *)(temp_16_6) + (0))), (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_00317900(arg0, stk[37], stk[36], ((8 - temp_17_6)), (((temp_17_6 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57)));
                    temp_4_6 = (u8 *)(temp_19 + ((4 - temp_17_6) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_6) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_6) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57);
                } else {
                    temp_22_6 = (((func_003b7060() % 300U) - 0x96));
                    temp_17_7 = (var_20);
                    func_002b2970(&stk[35], (*( f32 * )((u8 *)(temp_16_6) + (0))), (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_002b2970(&stk[34], 700.0f, (*( f32 * )((u8 *)(temp_16_6) + (4))) + (f32) temp_22_6);
                    func_00317900(arg0, stk[35], stk[34], ((8 - temp_17_7)), (((temp_17_7 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57)));
                }
                var_20 = ((var_20 + 1));
                goto loop_45;
            }
            if (temp_18_2 == 0) {
                func_002b2970(&stk[33], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970(&stk[32], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[33], stk[32], 6, 8, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xDE))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xE0))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_7 = (((func_003b7060() % 300U) - 0x96));
                if ((u32) (func_003b7060() % 100U) >= 0x32U) {
                    func_002b2970(&stk[31], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[30], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_7);
                    func_00317900(arg0, stk[31], stk[30], 6, 4, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970(&stk[29], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[28], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_7);
                    func_00317900(arg0, stk[29], stk[28], 6, 4, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                }
            }
            break;
        case 7:
            var_20_2 = 0;
            temp_18_3 = (arg1);
loop_60:
            temp_16_8 = (var_20_2);
            if (temp_16_8 < 3) {
                temp_17_8 = (u8 *)(D_006407C0 + ((temp_16_8 + 1) * 0xC));
                if (temp_18_3 == 0) {
                    temp_22_7 = (var_20_2);
                    func_002b2970(&stk[27], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_002b2970(&stk[26], (*( f32 * )((u8 *)(temp_17_8) + (0))), (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_00317900(arg0, stk[27], stk[26], (var_20_2), ((temp_22_7 * 4)), ((((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57)));
                    temp_4_7 = (u8 *)(temp_19 + (temp_22_7 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_7) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_7) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57);
                } else {
                    temp_22_8 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[25], (*( f32 * )((u8 *)(temp_17_8) + (0))), (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_002b2970(&stk[24], -300.0f, (*( f32 * )((u8 *)(temp_17_8) + (4))) + (f32) temp_22_8);
                    func_00317900(arg0, stk[25], stk[24], (var_20_2), ((temp_16_8 * 2)), ((((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57)));
                }
                temp_16_9 = (u8 *)(D_006407C0 + ((7 - temp_16_8) * 0xC));
                if (temp_18_3 == 0) {
                    temp_17_9 = (var_20_2);
                    func_002b2970(&stk[23], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_002b2970(&stk[22], (*( f32 * )((u8 *)(temp_16_9) + (0))), (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_00317900(arg0, stk[23], stk[22], ((8 - temp_17_9)), (((temp_17_9 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57)));
                    temp_4_8 = (u8 *)(temp_19 + ((6 - temp_17_9) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_8) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_8) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57);
                } else {
                    temp_22_9 = (((func_003b7060() % 300U) - 0x96));
                    temp_17_10 = (var_20_2);
                    func_002b2970(&stk[21], (*( f32 * )((u8 *)(temp_16_9) + (0))), (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_002b2970(&stk[20], 700.0f, (*( f32 * )((u8 *)(temp_16_9) + (4))) + (f32) temp_22_9);
                    func_00317900(arg0, stk[21], stk[20], ((8 - temp_17_10)), (((temp_17_10 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57)));
                }
                var_20_2 = ((var_20_2 + 1));
                goto loop_60;
            }
            if (temp_18_3 == 0) {
                func_002b2970(&stk[19], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970(&stk[18], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[19], stk[18], 3, 0xC, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xE8))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xEA))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_10 = (((func_003b7060() % 300U) - 0x96));
                if ((u32) (func_003b7060() % 100U) >= 0x32U) {
                    func_002b2970(&stk[17], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[16], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_10);
                    func_00317900(arg0, stk[17], stk[16], 3, 6, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970(&stk[15], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[14], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_10);
                    func_00317900(arg0, stk[15], stk[14], 3, 6, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                }
            }
            break;
        case 9:
            var_20_3 = 0;
            temp_18_4 = (arg1);
loop_75:
            temp_16_11 = (var_20_3);
            if (temp_16_11 < 4) {
                temp_17_11 = (u8 *)(D_006407C0 + (temp_16_11 * 0xC));
                if (temp_18_4 == 0) {
                    temp_22_10 = (var_20_3);
                    func_002b2970(&stk[13], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_002b2970(&stk[12], (*( f32 * )((u8 *)(temp_17_11) + (0))), (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_00317900(arg0, stk[13], stk[12], (var_20_3), ((temp_22_10 * 4)), ((((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57)));
                    temp_4_9 = (u8 *)(temp_19 + (temp_22_10 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_9) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_9) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57);
                } else {
                    temp_22_11 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[11], (*( f32 * )((u8 *)(temp_17_11) + (0))), (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_002b2970(&stk[10], -300.0f, (*( f32 * )((u8 *)(temp_17_11) + (4))) + (f32) temp_22_11);
                    func_00317900(arg0, stk[11], stk[10], (var_20_3), ((temp_16_11 * 2)), ((((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57)));
                }
                temp_16_12 = 8 - temp_16_11;
                temp_17_12 = (u8 *)(D_006407C0 + (temp_16_12 * 0xC));
                if (temp_18_4 == 0) {
                    temp_22_12 = (var_20_3);
                    temp_16_13 = 8 - temp_22_12;
                    func_002b2970(&stk[9], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_002b2970(&stk[8], (*( f32 * )((u8 *)(temp_17_12) + (0))), (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_00317900(arg0, stk[9], stk[8], (temp_16_13), (((temp_22_12 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57)));
                    temp_4_10 = (u8 *)(temp_19 + (temp_16_13 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_10) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_10) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57);
                } else {
                    temp_22_13 = (((func_003b7060() % 300U) - 0x96));
                    func_002b2970(&stk[7], (*( f32 * )((u8 *)(temp_17_12) + (0))), (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_002b2970(&stk[6], 700.0f, (*( f32 * )((u8 *)(temp_17_12) + (4))) + (f32) temp_22_13);
                    func_00317900(arg0, stk[7], stk[6], (temp_16_12), (((((s64) (var_20_3)) * 2) + 1) << 0x30) >> 0x30, ((((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57)));
                }
                var_20_3 = ((var_20_3 + 1));
                goto loop_75;
            }
            if (temp_18_4 == 0) {
                func_002b2970(&stk[5], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970(&stk[4], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[5], stk[4], 4, 0x10, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_14 = (((func_003b7060() % 300U) - 0x96));
                if ((u32) (func_003b7060() % 100U) >= 0x32U) {
                    func_002b2970(&stk[3], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[2], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_14);
                    func_00317900(arg0, stk[3], stk[2], 4, 8, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970(&stk[1], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970(&stk[0], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_14);
                    func_00317900(arg0, stk[1], stk[0], 4, 8, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                }
            }
            break;
        }
    }
    if (((arg1)) == 1) {
        (*( s8 * )((u8 *)(func_002b6150(0x216)) + (0x73))) = 0;
        func_002b6150(0x216);
        (*( s8 * )((u8 *)(func_002b6150(0x217)) + (0x73))) = 0;
        func_002b6150(0x217);
        (*( s8 * )((u8 *)(func_002b6150(0x218)) + (0x73))) = 0;
        func_002b6150(0x218);
        (*( s8 * )((u8 *)(func_002b6150(0x219)) + (0x73))) = 0;
        func_002b6150(0x219);
        (*( s8 * )((u8 *)(func_002b6150(0x21A)) + (0x73))) = 0;
        func_002b6150(0x21A);
        (*( s8 * )((u8 *)(func_002b6150(0x21B)) + (0x73))) = 0;
        func_002b6150(0x21B);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002eb270);
#endif

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

/* measured: GUARDED_SCORE 1690 via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombine.c func_002f9d90 --candidate v3=/var/tmp/Bd002e/f9d90_v3.c` (baseline 2251 -> s32 temps 2139 -> 43.0f literals 2131 inside); obj 2131I / retail 2116I (+15, +0.71% PASS, band 2053-2179, headroom 48). fnalign 656 edits +10 reloc-only. m2c oracle from src/generated/code1_002f.c + romwright second opinion, de-noised to file idiom (s64 stk buffers, s32 index temps, col10C/108/104[4] real colour layout per stack census 0x104/108/10C, ps-reused 002b6150 result with *(FclVec2f *)(ps+0x38) struct-by-value per 002ED430 note, (u8)f plain casts per 7a-quinquies, D_008C024E[2] for +4, float literals verified vs retail mtc1/cvt (650.0f via (f32)0x28A conversion kept, 42/43/60/97/128/195/255.0f literals), zero (s64)/stubs, prologue aligned incl. frame -0x110). No large hole: all 11 switch arms 0x63-0x6D present with full call sites. */
// FUN_002F9D90 NONMATCHING
#ifdef NON_MATCHING
void func_002f9d90(u8 *arg0) {
    extern void func_002e4610(s32, s8);
    extern void func_002e55c0(s8, s32, s8);
    extern s8 func_00314660(u8 *);
    extern void func_00314670(u8 *, s8);
    extern void func_00314680(u8 *);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00317240(u8 *, s64, f32);
    extern s32 func_003190d0(u8 *);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00324680(u8 *, s32, s32);
    extern s32 func_00325450(u8 *, s32, s32);
    extern void func_00329310(u8 *, s32, s32);
    extern u8 *func_002e4870(s8);
    extern s32 func_00275820(f32, f32, f32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern void func_002ba970(s32, s8, s32);
    extern s8 func_002bb1c0(s8);
    extern s32 func_00104c70(s32);
    extern s64 func_00247770(s32);
    extern f32 func_002b2aa0(s32, s32, f32, f32, f32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern void func_0011d140(u8 *, s32); /* retail sets $5 (colour); 1-arg def ignores it */
    extern u8 D_00795E60[];
    extern f32 D_00640E70[];
    u8 *ps;
    u8 col10C[4];
    u8 col108[4];
    u8 col104[4];
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    s16 *temp_2;
    s32 temp_17_10;
    u8 *temp_17_12;
    u8 *temp_17_13;
    u8 *temp_17_15;
    u8 *temp_17_17;
    u8 *temp_17_18;
    u8 *temp_17_20;
    s32 temp_17_2;
    u8 *temp_17_4;
    u8 *temp_17_6;
    u8 *temp_17_7;
    u8 *temp_17_8;
    s32 temp_20_3;
    s32 var_21_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_19_3;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_22;
    s32 temp_22_2;
    s32 temp_22_3;
    s32 temp_3_2;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_17_4;
    s32 var_17_5;
    s32 var_20;
    s8 temp_2_4;
    s8 temp_2_5;
    u16 *temp_17_16;
    u16 *temp_17_21;
    u16 *temp_17_3;
    u8 temp_17;
    u8 temp_17_11;
    u8 temp_17_14;
    u8 temp_17_19;
    u8 temp_17_5;
    u8 temp_19_4;
    u8 temp_3;
    u8 var_21;
    u8 *temp_16;
    u8 *temp_2_2;
    u8 *temp_2_3;

    temp_16 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x38))));
    temp_3 = (u8)((*( u8 * )((u8 *)(temp_16) + (1))));
    switch (temp_3) {
    case 0x63:
        func_002e4610(0xA, 0);
        func_002e4610(0xA, 1);
        func_002e55c0(0, 1, 1);
        func_002e55c0(0, 0x2C, 1);
        func_002e55c0(0, 0x92, 1);
        func_002e55c0(0, 0x7F, 1);
        func_002e55c0(0, 0x45, 1);
        func_002e55c0(0, 0x1E, 1);
        func_002e55c0(0, 0x56, 1);
        func_002e55c0(0, 0xA3, 1);
        func_002e55c0(0, 0x23, 1);
        func_002e55c0(0, 2, 1);
        func_002e55c0(0, 0xB, 1);
        func_002e55c0(0, 0x81, 1);
        func_002e55c0(1, 0xBD, 0);
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0x64U;
        return;
    case 0x64:
        if ((*(s8 *)func_002e4870(0) != 0) && (func_003190d0(arg0) != 1)) {
            (*( s8 * )((u8 *)(temp_16) + (0x20))) = 0;
            var_17 = 0;
loop_9:
            if (((var_17)) < 0xC) {
                if ((*( u8 * )((u8 *)(func_002e48a0(0, var_17)) + (4))) == 0) {
                    (*( s8 * )((u8 *)(temp_16) + (0x20))) = 1;
                }
                var_17 = ((var_17 + 1));
                goto loop_9;
            }
            var_17_2 = 0;
loop_12:
            if (((var_17_2)) < (func_0010b5b0() & 0xFFFF)) {
                func_002b2a60(col10C, 0, 0, 0x99, 0xFFU);
                temp_2 = (s16 *)(func_0034ae50((*( u8 ** )((u8 *)(temp_16) + (0x188))), (s8)var_17_2));
                (*( u8 * )((u8 *)(temp_2) + (0x75))) = col10C[0];
                (*( u8 * )((u8 *)(temp_2) + (0x76))) = col10C[1];
                (*( u8 * )((u8 *)(temp_2) + (0x77))) = col10C[2];
                (*( u8 * )((u8 *)(temp_2) + (0x78))) = col10C[3];
                var_17_2 = ((var_17_2 + 1));
                goto loop_12;
            }
            (*( s8 * )((u8 *)(temp_16) + (0x129))) = -1;
            (*( s8 * )((u8 *)(temp_16) + (0x128))) = -1;
            (*( s16 * )((u8 *)(temp_16) + (0x11E))) = -1;
            func_00315600(arg0, 1);
            func_00324680(arg0, 2, 0);
            if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            } else {
                func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
                temp_2_2 = (u8 *)(func_002b6150(0x8A));
                (*( f32 * )((u8 *)(temp_2_2) + (0x38))) = (f32) ((*( f32 * )((u8 *)(temp_2_2) + (0x38))) + 60.0f);
            }
            func_002b2970(&spF8, (*( f32 * )((u8 *)(D_00640E70) + (0))), (*( f32 * )((u8 *)(D_00640E70) + (4))));
            func_002b6c30(0xC8, spF8, 0x5A, 42.0f);
            func_002b6a70(0xC8, 0xFFU, 0, 0, 0xA, 0xA);
            func_002b2970(&spF0, (f32) 0x28A + (*( f32 * )((u8 *)(D_00640E70) + (0))), (*( f32 * )((u8 *)(D_00640E70) + (4))));
            func_002b2970(&spE8, (*( f32 * )((u8 *)(D_00640E70) + (0))) - 50.0f, (*( f32 * )((u8 *)(D_00640E70) + (4))));
            func_002b69f0(0xC8, *(FclVec2f *)&spF0, *(FclVec2f *)&spE8, 0, 0x14, 0);
            func_003205f0(arg0, 0x98, 0x96);
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x65U;
            return;
        }
    default:
        return;
    case 0x65:
        if (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) == 0xD) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x69U;
            return;
        }
        var_17_3 = 0;
loop_32:
        temp_19 = (var_17_3);
        if (temp_19 < 0xC) {
            if (temp_19 < (*( s32 * )((u8 *)(func_002e4870(0)) + (8)))) {
                if ((s32) (*( u8 * )((u8 *)(func_002e48a0(0, var_17_3)) + (4))) > 0) {
                    temp_22 = (var_17_3);
                    temp_20 = temp_22 + 0x21C;
                    temp_f20 = (f32) (*( s16 * )((u8 *)(func_002b6150((temp_20))) + (0x42)));
                    temp_f0 = func_002b2aa0(0, 0, 255.0f, temp_f20, (f32) (*( s16 * )((u8 *)(func_002b6150((temp_20))) + (0x40))));
                    if (!(temp_f0 >= 2.1474836e9f)) {
                        var_3 = (u8)(temp_f0);
                    } else {
                        var_3 = (u8)(temp_f0);
                    }
                    var_21 = var_3 & 0xFF;
                    (*( s8 * )((u8 *)(func_002b6150((temp_20))) + (0x6E))) = 0xCC;
                    (*( s8 * )((u8 *)(func_002b6150(((temp_22 + 0x22B)))) + (0x6E))) = 0xCC;
                } else {
                    temp_22_2 = (var_17_3);
                    temp_20_2 = temp_22_2 + 0x21C;
                    temp_f20_2 = (f32) (*( s16 * )((u8 *)(func_002b6150((temp_20_2))) + (0x42)));
                    temp_f0_2 = func_002b2aa0(0, 0, 128.0f, temp_f20_2, (f32) (*( s16 * )((u8 *)(func_002b6150((temp_20_2))) + (0x40))));
                    if (!(temp_f0_2 >= 2.1474836e9f)) {
                        var_3_2 = (u8)(temp_f0_2);
                    } else {
                        var_3_2 = (u8)(temp_f0_2);
                    }
                    var_21 = var_3_2 & 0xFF;
                    (*( s8 * )((u8 *)(func_002b6150((temp_20_2))) + (0x6E))) = 0x66;
                    (*( s8 * )((u8 *)(func_002b6150(((temp_22_2 + 0x22B)))) + (0x6E))) = 0x66;
                }
                temp_20_3 = func_002b2a30(0xCC, 0xFF, 0xFF, var_21);
                func_002b2a60(col108, 0xCC, 0xFF, 0xFF, var_21);
                func_002ba970((*( s32 * )((u8 *)(temp_16) + (0x2BC))), var_17_3, (*( s32 * )col108));
                func_00275820(temp_20_3, 0, 2, ((s32)iGpffffb440) + ((*( u16 * )((u8 *)(func_002e48a0(0, var_17_3)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, (f32) 0x19D, (f32) ((temp_19 * 0x17) + 0x80), 43.0f);
            }
            var_17_3 = ((var_17_3 + 1));
            goto loop_32;
        }
        temp_f20_3 = (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x42)));
        temp_f0_3 = func_002b2aa0(0, 0, 255.0f, temp_f20_3, (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x40))));
        if (!(temp_f0_3 >= 2.1474836e9f)) {
            var_3_3 = (u8)(temp_f0_3);
        } else {
            var_3_3 = (u8)(temp_f0_3);
        }
        temp_17 = var_3_3 & 0xFF;
        func_002b2a60(col104, 0x2D, 0x2D, 0x2D, temp_17);
        func_002ba970((*( s32 * )((u8 *)(temp_16) + (0x2BC))), 0xC, (*( s32 * )col104));
        temp_17_2 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_17);
        func_00275820(temp_17_2, 0, 2, ((s32)iGpffffb440) + ((*( u16 * )((u8 *)(func_002e48a0(1, 0)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 97.0f, 195.0f, 43.0f);
        (*( s8 * )((u8 *)(func_002b6150(0x27D)) + (0x6E))) = 0xFF;
        (*( s8 * )((u8 *)(func_002b6150(0x270)) + (0x6E))) = (s8) (0xFF & 0xFF);
        if (((((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) < 8) || (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) >= 0xE)) && ((((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) < 0) || (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) >= 6))) {
            var_17_4 = 0;
loop_43:
            temp_3_2 = (var_17_4);
            if (temp_3_2 >= 0xC) {
                if (((func_002b6970((*( s16 * )((u8 *)(func_002b6150(0xC8)) + (0x10))), 1))) != 1) {
                    if (D_008C024E[0] & 0x40) {
                        if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                            func_0045af60(0, 0, 0, 1);
                            (*( s8 * )((u8 *)(temp_16) + (0x2F9))) = 1;
                            (*( s8 * )((u8 *)(temp_16) + (0x2FA))) = 0;
                            temp_17_3 = (u16 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), 0));
                            temp_19_2 = (func_00247770((*( u8 * )((u8 *)((((*( u16 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (2))) * 0xE) + ((s32)iGpffffb3d4))) + (2)))));
                            func_003144d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), temp_17_3, 0, func_00311930(temp_19_2, func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))), 0), 1);
                            temp_17_4 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                            func_0011d140(temp_17_4, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                            temp_17_5 = (u8)((*( u8 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (4))));
                            if ((func_00104c70(1) & 0xFF) < (s32) temp_17_5) {
                                temp_17_6 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                                func_0011d140(temp_17_6, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                            }
                            func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
                            func_00325450(arg0, 8, 0);
                            func_00324680(arg0, 0, 1);
                            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                            func_00317240(arg0, 0, 0);
                            return;
                        }
                        func_0045af60(0, 0, 0, 8);
                        return;
                    }
                    if (D_008C024E[0] & 0x80) {
                        func_00324680(arg0, 0, 1);
                        if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                            func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                        } else {
                            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                        }
                        func_00317240(arg0, 0, 60.0f);
                        (*( u8 * )((u8 *)(temp_16) + (1))) = 0x66U;
                        func_0045af60(0, 1, 0, 3);
                        return;
                    }
                    if (D_008C024E[0] & 0x20) {
                        func_00324680(arg0, 0, 1);
                        if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                        } else {
                            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                        }
                        (*( u8 * )((u8 *)(temp_16) + (1))) = 0x68U;
                        func_0045af60(0, 0, 0, 2);
                        return;
                    }
                }
            } else if (((func_002b6970((*( s16 * )((u8 *)(func_002b6150((s16)(temp_3_2 + 0x21C))) + (0x10))), 1) << 0x30) >> 0x30) != 1) {
                var_17_4 = ((var_17_4 + 1));
                goto loop_43;
            }
        }
        break;
    case 0x66:
        if (((func_002b6970((*( s16 * )((u8 *)(func_002b6150(0x21C)) + (0x10))), 1))) != 1) {
            func_00314450((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), func_002e48a0(1, 0), 0, 0);
            func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
            if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                temp_17_7 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                func_0011d140(temp_17_7, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            } else {
                temp_17_8 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                func_0011d140(temp_17_8, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
            }
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x67U;
            return;
        }
        break;
    case 0x67:
        if (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) == 5) {
            if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 1) {
                func_0011caf0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 0) {
                    func_0011c630(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
                    func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 1);
                }
                goto block_79;
            }
            if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 1) {
                    func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
                    func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 1);
                    goto block_79;
                }
                if (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) == 5) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 3);
                    if (((func_002b6970((*( s16 * )((u8 *)(func_002b6150(0x1E4)) + (0x10))), 0))) == 1) {
                        func_002b6a70(0x1E4, (*( u8 * )((u8 *)(func_002b6150(0x1E4)) + (0x6E))), 0, 0, 0xA, 0);
                    }
                    goto block_79;
                }
            } else {
                goto block_79;
            }
        } else {
block_79:
            if ((((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) < 0) || (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) >= 6)) {
                func_00324680(arg0, 0, 0);
                if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                    func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                } else {
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                    temp_2_3 = (u8 *)(func_002b6150(0x8A));
                    (*( f32 * )((u8 *)(temp_2_3) + (0x38))) = (f32) ((*( f32 * )((u8 *)(temp_2_3) + (0x38))) + 60.0f);
                }
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0x65U;
                return;
            }
        }
        break;
    case 0x68:
        var_20 = 0;
loop_92:
        temp_17_9 = (var_20);
        if (temp_17_9 < (*( s32 * )((u8 *)(func_002e4870(0)) + (8)))) {
            temp_22_3 = (var_20);
            temp_19_3 = temp_22_3 + 0x21C;
            temp_f20_4 = (f32) (*( s16 * )((u8 *)(func_002b6150((temp_19_3))) + (0x42)));
            temp_f0_4 = func_002b2aa0(0, 255.0f, 0, temp_f20_4, (f32) (*( s16 * )((u8 *)(func_002b6150((temp_19_3))) + (0x40))));
            if (!(temp_f0_4 >= 2.1474836e9f)) {
                var_3_4 = (u8)(temp_f0_4);
            } else {
                var_3_4 = (u8)(temp_f0_4);
            }
            temp_19_4 = var_3_4 & 0xFF;
            var_21_2 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_19_4);
            if ((*( s16 * )((u8 *)(temp_16) + (0x11E))) == temp_22_3) {
                var_21_2 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_19_4);
            }
            func_00275820(var_21_2, 0, 2, ((s32)iGpffffb440) + ((*( u16 * )((u8 *)(func_002e48a0(0, var_20)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, (f32) 0x19D, (f32) ((temp_17_9 * 0x17) + 0x80), 43.0f);
            var_20 = ((var_20 + 1));
            goto loop_92;
        }
        if ((*( s32 * )((u8 *)(func_002e4870(0)) + (8))) >= 0xC) {
            temp_f20_5 = (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x42)));
            temp_f0_5 = func_002b2aa0(0, 255.0f, 0, temp_f20_5, (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x40))));
            if (!(temp_f0_5 >= 2.1474836e9f)) {
                var_3_5 = (u8)(temp_f0_5);
            } else {
                var_3_5 = (u8)(temp_f0_5);
            }
        } else {
            temp_f20_6 = (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x42)));
            temp_f0_6 = func_002b2aa0(0, 128.0f, 0, temp_f20_6, (f32) (*( s16 * )((u8 *)(func_002b6150(0x270)) + (0x40))));
            if (!(temp_f0_6 >= 2.1474836e9f)) {
                var_3_5 = (u8)(temp_f0_6);
            } else {
                var_3_5 = (u8)(temp_f0_6);
            }
        }
        temp_17_10 = func_002b2a30(0xCC, 0xFF, 0xFF, var_3_5 & 0xFF);
        func_00275820(temp_17_10, 0, 2, ((s32)iGpffffb440) + ((*( u16 * )((u8 *)(func_002e48a0(1, 0)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 97.0f, 195.0f, 43.0f);
        if ((((func_002b6970((*( s16 * )((u8 *)(func_002b6150(0x71)) + (0x10))), 1))) == 0) && (((func_002b6970((*( s16 * )((u8 *)(func_002b6150(0x70)) + (0x10))), 1))) == 0)) {
            func_002eb270(arg0, 0U);
            func_00315600(arg0, 0);
            func_003205f0(arg0, 0x96, 0x98);
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x1AU;
            (*( s8 * )((u8 *)(temp_16) + (0))) = 0;
            return;
        }
        break;
    case 0x69:
        if (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) == 0xD) {
            if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 1) {
                func_0011caf0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
            }
            if (D_008C024E[0] & 0x40) {
                func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))));
                func_0045af60(0, 0, 0, 1);
                temp_17_11 = (u8)((*( u8 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (4))));
                if ((func_00104c70(1) & 0xFF) < (s32) temp_17_11) {
                    func_00310960(arg0, 0x26, 0);
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0x6BU;
                    return;
                }
                func_00310960(arg0, 0x39, 1);
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0x6AU;
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 0) {
                    func_0011c630(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 0);
                    return;
                }
                func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
                func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))))) == 1) {
                    func_0011c6e0(func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))), 1);
                    func_00314740((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 1);
                    return;
                }
                func_00314670((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 0xB);
                func_00325450(arg0, 8, 1);
                func_00324680(arg0, 0, 0);
                if ((*( s8 * )((u8 *)(temp_16) + (0x20))) == 0) {
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                } else {
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
                }
                func_00317240(arg0, 1, 0);
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0x65U;
                func_0045af60(0, 0, 0, 2);
                return;
            }
            if (D_008C024E[2] & 8) {
                if ((*( s8 * )((u8 *)(temp_16) + (0x122))) != 0xC) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_2_4 = (s8)(func_002b2cb0((u8) (*( s8 * )((u8 *)(temp_16) + (0x122))), 1, 0xC, 0, 1));
                (*( s8 * )((u8 *)(temp_16) + (0x122))) = temp_2_4;
                (*( s16 * )((u8 *)(temp_16) + (0x120))) = func_002b2d50(temp_2_4, (*( s16 * )((u8 *)(temp_16) + (0x120))), 0xC, 7, 1);
                ps = func_002b6150(0x155);
                func_002b2970(&spE0, (f32) (((*( s16 * )((u8 *)(temp_16) + (0x120))) * 0x3D) + 0x6A), 16.0f);
                
                func_002b69f0(0x155, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&spE0, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&spD8, (f32) (((*( s16 * )((u8 *)(temp_16) + (0x120))) * 0x3D) + 0x6A), 16.0f);
                
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&spD8, 1, 4, 0);
                func_00329310(arg0, 0, 0);
                if ((*( s8 * )((u8 *)(temp_16) + (0x122))) < 0xC) {
                    temp_17_12 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_0011d140(temp_17_12, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), func_002e48a0(0, (*( s8 * )((u8 *)(temp_16) + (0x122)))), 0, 0, 1);
                    return;
                }
                temp_17_13 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                func_0011d140(temp_17_13, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                temp_17_14 = (u8)((*( u8 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (4))));
                if ((func_00104c70(1) & 0xFF) < (s32) temp_17_14) {
                    temp_17_15 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_0011d140(temp_17_15, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                }
                temp_17_16 = (u16 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))));
                temp_18 = (func_00247770((*( u8 * )((u8 *)((((*( u16 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (2))) * 0xE) + ((s32)iGpffffb3d4))) + (2)))));
                func_003144d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), temp_17_16, 0, func_00311930(temp_18, func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))), 0), 1);
                return;
            }
            if (D_008C024E[2] & 4) {
                if ((*( s8 * )((u8 *)(temp_16) + (0x122))) != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_2_5 = (s8)(func_002b2d00((*( s8 * )((u8 *)(temp_16) + (0x122))), 1, 0, 0, 1));
                (*( s8 * )((u8 *)(temp_16) + (0x122))) = temp_2_5;
                (*( s16 * )((u8 *)(temp_16) + (0x120))) = func_002b2d50(temp_2_5, (*( s16 * )((u8 *)(temp_16) + (0x120))), 0xC, 7, -1);
                ps = func_002b6150(0x155);
                func_002b2970(&spD0, (f32) (((*( s16 * )((u8 *)(temp_16) + (0x120))) * 0x3D) + 0x6A), 16.0f);
                
                func_002b69f0(0x155, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&spD0, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&spC8, (f32) (((*( s16 * )((u8 *)(temp_16) + (0x120))) * 0x3D) + 0x6A), 16.0f);
                
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&spC8, 1, 4, 0);
                func_00329310(arg0, 0, 0);
                if ((*( s8 * )((u8 *)(temp_16) + (0x122))) < 0xC) {
                    temp_17_17 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_0011d140(temp_17_17, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), func_002e48a0(0, (*( s8 * )((u8 *)(temp_16) + (0x122)))), 0, 0, 1);
                    return;
                }
                temp_17_18 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                func_0011d140(temp_17_18, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                temp_17_19 = (u8)((*( u8 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (4))));
                if ((func_00104c70(1) & 0xFF) < (s32) temp_17_19) {
                    temp_17_20 = (func_003147d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))));
                    func_0011d140(temp_17_20, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                }
                temp_17_21 = (u16 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))));
                temp_18_2 = (func_00247770((*( u8 * )((u8 *)((((*( u16 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (2))) * 0xE) + ((s32)iGpffffb3d4))) + (2)))));
                func_003144d0((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), temp_17_21, 0, func_00311930(temp_18_2, func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))), 0), 1);
                return;
            }
        }
        break;
    case 0x6A:
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        if (func_002bb1c0((*( s8 * )((u8 *)(temp_16) + (0xD)))) == 0) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x6CU;
            func_00122520(1, 0xA);
        } else {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x69U;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        return;
    case 0x6B:
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0x69U;
        return;
    case 0x6C:
        if (func_00122720() != 0) {
            func_00314670((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 0xB);
            func_00314680((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))));
            func_00325450(arg0, 8, 1);
            (*( s16 * )((u8 *)(temp_16) + (0x11E))) = (s16) (*( s8 * )((u8 *)(temp_16) + (0x122)));
            var_17_5 = 0;
loop_150:
            if (((var_17_5)) < 0x30C) {
                func_002b68d0(var_17_5, 0, 1);
                var_17_5 = ((var_17_5 + 1));
                goto loop_150;
            }
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0x6DU;
            return;
        }
        break;
    case 0x6D:
        if (((func_00314660((u8 *)(u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148)))))) == 0xE) {
            (*( s8 * )((u8 *)(temp_16) + (0xB2))) = 0;
            (*( s8 * )((u8 *)(temp_16) + (0))) = 0xD;
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC5U;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f9d90);
#endif

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

/* measured: GUARDED_SCORE 728 via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombine.c func_00302770` with scoped `#pragma peephole off` (baseline 787 -> 728, -59); obj 3828B / window 3744B. fnalign 957 vs 936 instrs (+21, +2.24% PASS), 385 edits +2 reloc-only. Band is 908-964 (936 +-3%): baseline v3 929 inside, peephole 957 inside, cse_off 732 at 962/936 (420ed) inside but worse than peephole so reject; loopinv_on/unroll_off/sched_off 787 tie; subscript ((u8**)p)[i+0x96] 787 tie, heap ((s64*)q)[7] 787 tie; colouring declswap/sporder 787 tie. m2c fails on jr/jtbl so romwright switch (0x6E-0x74, 0x6F last per jtbl_007492E0 order 6E,70,71,72,73,74,6F) de-noised: 38 s64 2970 homes, FclVec2f fv0-7 force -50 spill, f32 word copies, (s16)6970, (s32) casts. Residuals: heap 69f0 ldr/ldl vs ld (4 sites), gp fmt iGpffffa8a0 (addiu gp,0 vs -0x5760, 2 words), s0/s3 rotation vs s1/s3. */
// FUN_00302770 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma peephole off
void func_00302770(u8 *arg0) {
    extern u8 *func_002b81f0(u8 *arg0);
    extern void func_00325450(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_0032c660(u8 *arg0, s32 arg1, s64 arg2, s64 arg3, s32 arg4, s32 arg5);
    extern void func_0032e570(u8 *arg0);
    extern void func_0033e540(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s32 arg4);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00442088(void *dst, void *fmt, s32 value);
    extern u16 D_008C024E[];
    extern char iGpffffa8a0;
    s64 sp250;
    s64 sp248;
    s64 sp240;
    s64 sp238;
    s64 sp230;
    s64 sp228;
    s64 sp220;
    s64 sp218;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    s64 sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    s64 sp158;
    s64 sp130;
    s64 sp128;
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    FclVec2f fv0;
    FclVec2f fv1;
    FclVec2f fv2;
    FclVec2f fv3;
    FclVec2f fv4;
    FclVec2f fv5;
    FclVec2f fv6;
    FclVec2f fv7;
    char buf[128];
    u8 *p;
    u8 *q;
    u8 *r;
    s8 v;
    u16 d;
    s16 i;

    p = *(u8 **)(arg0 + 0x38);
    switch (p[1]) {
    case 0x6E:
        func_003205f0(arg0, 0x1E7, 0x96);
        if (func_00106330(0x131A) == 0) {
            v = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = v;
            func_002badc0(v, 0x4E);
            func_00106390(0x131A, 1);
            p[1] = 0x6F;
            return;
        }
        p[1] = 0x70;
        func_002b2970(&sp250, 640.0f, 98.0f);
        func_002b2970(&sp248, 413.0f, 99.0f);
        func_0033e540(*(u8 **)(p + 0x250), sp250, sp248, 6, 0);
        func_00316e80((s32)arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
        /* fallthrough */
    case 0x70:
        func_00313b50((s32)arg0);
        v = func_002bab80((void *)func_00331660());
        *(s8 *)(p + 0xD) = v;
        func_00442088(buf, &iGpffffa8a0, func_002e78a0());
        func_002bbd80(*(s8 *)(p + 0xD), 0, buf);
        func_00442088(buf, &iGpffffa8a0, func_002e78e0());
        func_002bbd80(*(s8 *)(p + 0xD), 1, buf);
        func_002badc0(*(s8 *)(p + 0xD), 0x4A);
        p[1] = 0x71;
        break;
    case 0x71:
        if (func_002bb680(*(s8 *)(p + 0xD)) == 0) {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x72;
            v = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = v;
            func_002badc0(v, 0x4B);
            func_00325450(arg0, 2, 0);
            func_002b2970(&sp240, 57.0f, 72.0f);
            func_002b2970(&sp238, -346.0f, 72.0f);
            func_0032c660(arg0, 0, sp240, sp238, 1, 0);
            func_002b2970(&sp230, 460.0f, 72.0f);
            func_002b2970(&sp228, 460.0f, 72.0f);
            func_0032c660(arg0, 1, sp230, sp228, 1, 0);
            func_002b6140(*(s32 *)(p + 0x28C), 1);
            func_002b6140(*(s32 *)(p + 0x290), 1);
            func_00315600(arg0, 1);
            func_00320970(arg0, 1);
        } else {
            func_002bbcf0(*(s8 *)(p + 0xD));
        }
        break;
    case 0x72:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x73;
        }
        /* fallthrough */
    case 0x73:
        func_0032e570(arg0);
        q = func_002b6150(0x2E3);
        fv0 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp220, fv0.x - 50.0f, fv0.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x258));
        *(f32 *)(r + 0) = *(f32 *)&sp220;
        *(f32 *)(r + 4) = *((f32 *)&sp220 + 1);
        q = func_002b6150(0x2E2);
        fv1 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp218, fv1.x - 50.0f, fv1.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x25C));
        *(f32 *)(r + 0) = *(f32 *)&sp218;
        *(f32 *)(r + 4) = *((f32 *)&sp218 + 1);
        q = func_002b6150(0x2E9);
        fv2 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp210, fv2.x - 50.0f, fv2.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x260));
        *(f32 *)(r + 0) = *(f32 *)&sp210;
        *(f32 *)(r + 4) = *((f32 *)&sp210 + 1);
        q = func_002b6150(0x2EF);
        fv3 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp208, fv3.x - 50.0f, fv3.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x264));
        *(f32 *)(r + 0) = *(f32 *)&sp208;
        *(f32 *)(r + 4) = *((f32 *)&sp208 + 1);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1CA) + 0x10), 1) != 1) {
            d = D_008C024E[0];
            if ((d & 8) != 0) {
                if (*(s8 *)(p + 0x122) != 1) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                func_002b2970(&sp200, 321.0f, 16.0f);
                func_002b69f0(0x150, *(s64 *)(q + 0x38), sp200, 1, 4, 0);
                q = func_002b6150(0x2E0);
                func_002b2970(&sp1F8, 321.0f, 16.0f);
                func_002b69f0(0x2E0, *(s64 *)(q + 0x38), sp1F8, 1, 4, 0);
                func_002b2970(&sp1F0, 57.0f, 72.0f);
                func_002b2970(&sp1E8, -346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1F0, sp1E8, 0, 1);
                func_002b2970(&sp1E0, 460.0f, 72.0f);
                func_002b2970(&sp1D8, 460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1E0, sp1D8, 0, 0);
                *(s8 *)(p + 0x122) = 0;
            } else if ((d & 4) != 0) {
                if (*(s8 *)(p + 0x122) != 0) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                func_002b2970(&sp1D0, 107.0f, 16.0f);
                func_002b69f0(0x150, *(s64 *)(q + 0x38), sp1D0, 1, 4, 0);
                q = func_002b6150(0x2E0);
                func_002b2970(&sp1C8, 107.0f, 16.0f);
                func_002b69f0(0x2E0, *(s64 *)(q + 0x38), sp1C8, 1, 4, 0);
                func_002b2970(&sp1C0, 57.0f, 72.0f);
                func_002b2970(&sp1B8, -346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1C0, sp1B8, 0, 0);
                func_002b2970(&sp1B0, 460.0f, 72.0f);
                func_002b2970(&sp1A8, 460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1B0, sp1A8, 0, 1);
                *(s8 *)(p + 0x122) = 1;
            } else {
                if ((d & 0x20) == 0) {
                    break;
                }
                if (p[1] != 0x73) {
                    break;
                }
                func_002bb550(*(s8 *)(p + 0xD));
                func_0045af60(0, 0, 0, 2);
                func_00325450(arg0, 2, 1);
                if (*(s8 *)(p + 0x122) == 1) {
                    func_002b2970(&sp1A0, 57.0f, 72.0f);
                    func_002b2970(&sp198, 940.0f, 72.0f);
                    func_0032c660(arg0, 0, sp1A0, sp198, 0, 1);
                    func_002b2970(&sp190, 460.0f, 72.0f);
                    func_002b2970(&sp188, 940.0f, 72.0f);
                    func_0032c660(arg0, 1, sp190, sp188, 0, 1);
                    func_002b68d0(0x2E8, 0, 1);
                    func_002b68d0(0x2EE, 0, 1);
                } else if (*(s8 *)(p + 0x122) == 0) {
                    func_002b2970(&sp180, 57.0f, 72.0f);
                    func_002b2970(&sp178, -640.0f, 72.0f);
                    func_0032c660(arg0, 0, sp180, sp178, 0, 1);
                    func_002b2970(&sp170, 460.0f, 72.0f);
                    func_002b2970(&sp168, -640.0f, 72.0f);
                    func_0032c660(arg0, 1, sp170, sp168, 0, 1);
                }
                func_002eb270(arg0, 0);
                p[1] = 0x74;
                func_00316e80((s32)arg0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                func_002b2970(&sp160, 413.0f, 99.0f);
                func_002b2970(&sp158, 640.0f, 98.0f);
                func_0033e540(*(u8 **)(p + 0x250), sp160, sp158, 6, 0);
                func_00315600(arg0, 0);
                func_00320970(arg0, 0);
            }
        }
        break;
    case 0x74:
        q = func_002b6150(0x2E3);
        fv4 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp150, fv4.x - 50.0f, fv4.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x258));
        *(f32 *)(r + 0) = *(f32 *)&sp150;
        *(f32 *)(r + 4) = *((f32 *)&sp150 + 1);
        q = func_002b6150(0x2E2);
        fv5 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp148, fv5.x - 50.0f, fv5.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x25C));
        *(f32 *)(r + 0) = *(f32 *)&sp148;
        *(f32 *)(r + 4) = *((f32 *)&sp148 + 1);
        q = func_002b6150(0x2E9);
        fv6 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp140, fv6.x - 50.0f, fv6.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x260));
        *(f32 *)(r + 0) = *(f32 *)&sp140;
        *(f32 *)(r + 4) = *((f32 *)&sp140 + 1);
        q = func_002b6150(0x2EF);
        fv7 = *(FclVec2f *)(q + 0x38);
        func_002b2970(&sp138, fv7.x - 50.0f, fv7.y - 50.0f);
        r = func_002b81f0(*(u8 **)(p + 0x264));
        *(f32 *)(r + 0) = *(f32 *)&sp138;
        *(f32 *)(r + 4) = *((f32 *)&sp138 + 1);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1CA) + 0x10), 1) != 1) {
            i = 0;
            while ((s16)i < 4) {
                r = func_002b81f0(*(u8 **)(p + (s16)i * 4 + 0x258));
                *(u8 *)(r + 0x124) = 1;
                i = (s16)(i + 1);
            }
            func_003205f0(arg0, 0x96, 0x1E7);
            func_002b6140(*(s32 *)(p + 0x28C), 0);
            func_002b6140(*(s32 *)(p + 0x290), 0);
            *p = 0;
            p[1] = 0x1A;
        }
        break;
    case 0x6F:
        if (func_002bb680(*(s8 *)(p + 0xD)) == 0) {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x70;
            func_002b2970(&sp130, 640.0f, 98.0f);
            func_002b2970(&sp128, 413.0f, 99.0f);
            func_0033e540(*(u8 **)(p + 0x250), sp130, sp128, 6, 0);
            func_00316e80((s32)arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            func_002bbcf0(*(s8 *)(p + 0xD));
        }
        break;
    default:
        break;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00302770);
#endif

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
/* 2026-09-18 lead pass, 4 measured variants; floor confirmed at 27 words.
   259/259 instructions.  Two residual classes, both allocation:
   (a) retail keeps one `s16` loop counter in the caller-saved $a1 while this
   body keeps it in the callee-saved $s3 - that loop contains no call in
   either stream, so retail simply had a temp free where this body did not;
   (b) a $s3/$s5 exchange on the later counter and the `lh 4($s1)` load,
   the ordinary section 7m pair.
   All four declaration permutations of the five `s16` locals tie at 27 with
   a byte-identical stream, so neither class is reachable by reordering.
   Register class, not register number, is the interesting half here: a
   future pass should look for what keeps a temp live across that loop in
   this body and not in retail.  Tried and tied at 27: giving the first
   `for (j = 0; j < count; j++)` loop its own counter, which is the fix that
   took func_0013fb50 from 34 to 28 on exactly this symptom.  So the shared
   counter is not the cause here. */
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
/* measured 00308f40 narrow-locals (19 lines: s64 n3->s32 n3, delete dead s64 k, total (s8)*->*(u8*), 8x store dest *(s8*)->*(u8*) + value (s8)func->(u8)func + arg *(s8*)->*(u8*)): dsll32/dsra32 +15->-1, lbu/lb fixed to 0, words 331->328, fnalign edits 357->323 (retail 428/obj 379, window 1712B). Remaining: nop -53, andi +6, beql/bnel, daddiu, dsll/sll packing, move rotation. Store-side u8 is the missing piece: reads-only flips score 333, reads+total+k 333, +s32 n3 335; adding 8x store dest/value/arg u8 reaches 328. */
/* gate: object 379 against retail 427, -11.2% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
// FUN_00308F40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma schedule on
void func_00308f40(void) {
    s32 raw;
    s64 n0;
    s64 n1;
    s64 n2;
    s32 n3;
    s64 i;
    s64 j;
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
            total += *(u8 *)((u8 *)func_001102e0() + j + 0x26);
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
                *(u8 *)((u8 *)func_001102e0() + 0x26) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x27) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 1:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x28) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x28),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1F) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x29) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x29),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 2:
            if (*(u8 *)((u8 *)func_001102e0() + 0x20) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x2A) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x2A),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1C) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x26) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x26),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
                return;
            }
            break;
        case 3:
            if (*(u8 *)((u8 *)func_001102e0() + 0x1D) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x27) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x27),
                                      *(u8 *)(D_00749350 + n3), 0x63, 0, 1);
            }
            if (*(u8 *)((u8 *)func_001102e0() + 0x1E) != 0x63) {
                *(u8 *)((u8 *)func_001102e0() + 0x28) =
                    (u8)func_002b2cb0(*(u8 *)((u8 *)func_001102e0() + 0x28),
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
/* measured: GUARDED_SCORE 1293 via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombine.c func_003097e0` with scoped `#pragma opt_common_subs off` + `#pragma opt_loop_invariants on` (baseline 1655 -> 1640/1629 -> 1614 -> 1606 s64->s8 for 002badc0 -> 1603 redundant &0xFFFF for u16 sav); obj 1603I / retail 1568I (+35, +2.23% PASS, band 1521-1615, headroom 12). fnalign 691 edits +21 reloc-only. m2c oracle from src/generated/code1_0030.c de-noised to file idiom (u16 buf[12], char spA0/sp80[32], u8 spC8/D8/E8[12], s32 spF4/F8/FC, s16 loop idiom per func_00303610, base pointer first per func_00263cb0). */
// FUN_003097E0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants on
void func_003097e0(u8 *arg0) {
    extern void func_0034a640(s32, u16, s32);
    extern s32 func_0033f690(u8 *, u16 *, s32);
    extern s32 func_003488d0(u8 *, void *, s32);
    extern s8 *func_0033fa20(s32);
    extern s32 func_00348be0(s32);
    extern s32 func_0033dc90(u8 *, s8);
    extern s64 func_00247770(s32);
    extern void func_00275980(void *, void *, s32);
    extern u8 *func_001102f0(u8 *, s32, s32, f32);
    extern void func_003489c0(s32, void *, s32, s32, s32, f32, f32, f32, f32);
    extern void func_00348c30(s32, s32);
    extern void func_0034a820(s32);
    extern void func_00442088(void *, void *, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern s32 func_00311930(s32, u16 *, s32);
    extern s32 func_00311900(s32);
    extern void func_00314400(u8 *, s8);
    extern s32 func_00303a20(u8 *);
    extern void func_00310960(u8 *, s32, s32);
    extern u8 D_00641B50[];
    extern char iGpffffa8a4;
    extern u8 *iGpffffb44c;

    u8 *temp_16;
    u16 temp_17;
    s32 spFC;
    s32 spF8;
    s32 spF4;
    u8 spE8[12];
    u8 spD8[12];
    u8 spC8[12];
    char spA0[32];
    char sp80[32];
    u16 buf[12];
    s16 temp_2_6;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_19;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_4_4;
    s32 var_4_5;
    s32 var_4_6;
    s32 var_4_7;
    s64 temp_17_3;
    s64 temp_20;
    s64 temp_20_2;
    s64 temp_3_2;
    s64 temp_3_5;
    s64 temp_4;
    s64 temp_4_10;
    s64 temp_4_11;
    s64 temp_4_3;
    s64 temp_4_6;
    s64 temp_4_7;
    s64 temp_4_8;
    s64 temp_4_9;
    s64 temp_5;
    s64 temp_5_2;
    s64 temp_5_3;
    s64 temp_5_5;
    s64 temp_5_6;
    s64 temp_5_7;
    s64 temp_7_11;
    s64 temp_7_6;
    s64 var_10;
    s64 var_10_2;
    s64 var_19;
    s64 var_19_2;
    s64 var_4;
    s64 var_7;
    s64 var_8;
    s64 var_8_10;
    s64 var_8_2;
    s64 var_8_3;
    s64 var_8_4;
    s64 var_8_5;
    s64 var_8_6;
    s64 var_8_7;
    s64 var_8_8;
    s64 var_8_9;
    s64 var_9;
    s64 var_9_2;
    s8 temp_2;
    s8 temp_2_2;
    s8 temp_2_4;
    s8 temp_3_3;
    s8 temp_4_2;
    s8 temp_4_4;
    s8 temp_4_5;
    s8 temp_5_4;
    s8 temp_6;
    s8 temp_6_2;
    s8 temp_6_3;
    s8 temp_6_4;
    s8 temp_6_6;
    s8 temp_6_7;
    s8 temp_7_10;
    s8 temp_7_3;
    s8 temp_7_4;
    s8 temp_7_5;
    s8 temp_7_8;
    s8 temp_7_9;
    s8 var_4_2;
    s8 var_4_3;
    u16 *temp_2_3;
    u16 *temp_2_5;
    u8 temp_3;
    temp_16 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x38))));
    temp_17 = (u16)((*( u16 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (2))));
    temp_3 = (u8)((*( u8 * )((u8 *)(temp_16) + (1))));
    switch (temp_3) {                               /* switch 1 */
    case 0xC5:                                      /* switch 1 */
        func_00106390(0x58, 0);
        func_00106390(0x59, 0);
        func_00106390(0x5A, 0);
        func_00106390(0x5B, 0);
        func_00106390(0x5C, 0);
        func_00106390(0x5D, 0);
        func_00106390(0x5E, 0);
        func_00106390(0x5F, 0);
        func_00106390(0x1450, 0);
        (*( s8 * )((u8 *)(temp_16) + (0x26))) = 0;
        (*( s8 * )((u8 *)(temp_16) + (0x20))) = 0;
        (*( s16 * )((u8 *)(temp_16) + (0xE))) = 0;
        (*( s8 * )((u8 *)(temp_16) + (0x21))) = 0;
        (*( s16 * )((u8 *)(temp_16) + (0x2D8))) = 0;
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        var_19 = 0;
loop_4:
        if (((s64) (var_19 << 0x30) >> 0x30) < 0x30C) {
            func_002b68d0(var_19, 0, 1);
            var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
            goto loop_4;
        }
        func_00303de0(arg0);
        func_0034a640((*( s32 * )((u8 *)(temp_16) + (0x254))), temp_17, 0);
        (*( s8 * )((u8 *)(func_0034a630((*( s32 * )((u8 *)(temp_16) + (0x254))))) + (1))) = 0;
        var_4 = 0;
loop_7:
        temp_3_2 = (s64) (var_4 << 0x30) >> 0x30;
        if (temp_3_2 < 0xC) {
            (buf[temp_3_2]) = 0;
            var_4 = (s64) ((var_4 + 1) << 0x30) >> 0x30;
            goto loop_7;
        }
        temp_2 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x1A))));
        switch (temp_2) {                           /* switch 2 */
        case 2:                                     /* switch 2 */
            buf[0] = (u16)((*( u16 * )((u8 *)(func_002e48a0(0, (*( s8 * )((u8 *)(temp_16) + (0x128))))) + (2))));
            buf[1] = (u16)((*( u16 * )((u8 *)(func_002e48a0(0, (s8) (*( s16 * )((u8 *)(temp_16) + (0x11E))))) + (2))));
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 1);
            break;
        case 3:                                     /* switch 2 */
            buf[0] = (u16)((*( u16 * )((u8 *)(func_002e48a0(0, (*( s8 * )((u8 *)(temp_16) + (0x128))))) + (2))));
            buf[1] = (u16)((*( u16 * )((u8 *)(func_002e48a0(0, (*( s8 * )((u8 *)(temp_16) + (0x129))))) + (2))));
            buf[2] = (u16)((*( u16 * )((u8 *)(func_002e48a0(0, (s8) (*( s16 * )((u8 *)(temp_16) + (0x11E))))) + (2))));
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 2);
            break;
        case 4:                                     /* switch 2 */
            buf[0] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 0)) + (2))));
            buf[1] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 1)) + (2))));
            buf[2] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 2)) + (2))));
            buf[3] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 3)) + (2))));
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 3);
            break;
        case 5:                                     /* switch 2 */
            buf[0] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 0)) + (2))));
            buf[1] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 1)) + (2))));
            buf[2] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 2)) + (2))));
            buf[3] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 3)) + (2))));
            buf[4] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 4)) + (2))));
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 4);
            break;
        case 6:                                     /* switch 2 */
            buf[0] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 0)) + (2))));
            buf[1] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 1)) + (2))));
            buf[2] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 2)) + (2))));
            buf[3] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 3)) + (2))));
            buf[4] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 4)) + (2))));
            buf[5] = (u16)((*( u16 * )((u8 *)(func_002e48a0((s8) ((s64) (((*( s16 * )((u8 *)(temp_16) + (0x11E))) + 1) << 0x38) >> 0x38), 5)) + (2))));
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 5);
            break;
        case 7:                                     /* switch 2 */
            var_19_2 = 0;
loop_17:
            temp_20 = (s64) (var_19_2 << 0x30) >> 0x30;
            if (temp_20 < 0xC) {
                (buf[temp_20]) = (u16) (*( u16 * )((u8 *)(func_002e48a0(0, (s8) var_19_2)) + (2)));
                var_19_2 = (s64) ((var_19_2 + 1) << 0x30) >> 0x30;
                goto loop_17;
            }
            (*( s32 * )((u8 *)(temp_16) + (0x304))) = func_0033f690(arg0, buf /*buf[0]*/, 6);
            break;
        }
        if (((s64) (func_00105f50(temp_17) << 0x38) >> 0x38) > 0) {
            (*( s32 * )((u8 *)(temp_16) + (0x308))) = func_003488d0(arg0, &D_00641B50, 7);
        }
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC6U;
        return;
    case 0xC6:                                      /* switch 1 */
        if ((*func_0033fa20((*( s32 * )((u8 *)(temp_16) + (0x304)))) != 0) && ((((s64) (func_00105f50(temp_17) << 0x38) >> 0x38) <= 0) || (func_00348be0((*( s32 * )((u8 *)(temp_16) + (0x308)))) != 0))) {
            (*( s32 * )((u8 *)(temp_16) + (0x300))) = func_0033dc90(arg0, (s64) (((*( s8 * )((u8 *)(temp_16) + (0x1A))) - 2) << 0x38) >> 0x38);
            if ((*( s8 * )((u8 *)(temp_16) + (0xB2))) != 0) {
                func_00106390(0x5C, 1);
            }
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC7U;
            return;
        }
    default:                                        /* switch 1 */
        return;
    case 0xC7:                                      /* switch 1 */
        if (func_00106330(0x5B) != 0) {
            temp_3_3 = (s8)((*( s8 * )((u8 *)(temp_16) + (0xB2))));
            if (temp_3_3 == 1) {
                func_00310960(arg0, 0x28, 0);
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC8U;
                return;
            }
            if (temp_3_3 == 2) {
                func_00310960(arg0, 0x29, 0);
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC8U;
                return;
            }
            if (func_00303a20(arg0) == 1) {
                var_8 = 0;
                temp_6 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_38:
                temp_4 = (s64) (var_8 << 0x30) >> 0x30;
                if (temp_4 >= temp_6) {
                    var_4_2 = 0;
                } else if ((*( s8 * )((u8 *)((temp_16 + temp_4)) + (0x2DA))) == 0xC) {
                    var_4_2 = 1;
                } else {
                    var_8 = (s64) ((var_8 + 1) << 0x30) >> 0x30;
                    goto loop_38;
                }
                if (var_4_2 == 1) {
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCBU;
                    temp_2_2 = (s8)(func_002bab80((void *)func_00331660()));
                    (*( s8 * )((u8 *)(temp_16) + (0xD))) = temp_2_2;
                    func_002badc0(temp_2_2, 0x2A);
                    temp_2_3 = (u16 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))));
                    *temp_2_3 |= 4;
                    return;
                }
                goto block_42;
            }
block_42:
            temp_4_2 = temp_17;
            temp_18 = temp_4_2 * 0xE;
            if ((*( u8 * )((u8 *)((temp_18 + ((s32)iGpffffb3d4))) + (0xD))) == 0) {
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCCU;
                return;
            }
            (*( s8 * )((u8 *)(temp_16) + (0xD))) = func_002bab80((void *)func_00331660());
            func_00442088(spA0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17) * 0x11));
            func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),1,(void *)(spA0));
            func_002badc0((*( s8 * )((u8 *)(temp_16) + (0xD))), (*( u8 * )((u8 *)((temp_18 + ((s32)iGpffffb3d4))) + (0xD))) + 0x71);
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCAU;
            return;
        }
        break;
    case 0xC8:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        if (func_00303a20(arg0) == 1) {
            var_8_2 = 0;
            temp_6_2 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_52:
            temp_4_3 = (s64) (var_8_2 << 0x30) >> 0x30;
            if (temp_4_3 >= temp_6_2) {
                var_4_3 = 0;
            } else if ((*( s8 * )((u8 *)((temp_16 + temp_4_3)) + (0x2DA))) == 0xC) {
                var_4_3 = 1;
            } else {
                var_8_2 = (s64) ((var_8_2 + 1) << 0x30) >> 0x30;
                goto loop_52;
            }
            if (var_4_3 == 1) {
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCBU;
                temp_2_4 = (s8)(func_002bab80((void *)func_00331660()));
                (*( s8 * )((u8 *)(temp_16) + (0xD))) = temp_2_4;
                func_002badc0(temp_2_4, 0x2A);
                temp_2_5 = (u16 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))));
                *temp_2_5 |= 4;
                return;
            }
            goto block_56;
        }
block_56:
        temp_4_4 = temp_17;
        temp_18_2 = temp_4_4 * 0xE;
        if ((*( u8 * )((u8 *)((temp_18_2 + ((s32)iGpffffb3d4))) + (0xD))) == 0) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCCU;
            return;
        }
        (*( s8 * )((u8 *)(temp_16) + (0xD))) = func_002bab80((void *)func_00331660());
        func_00442088(spA0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17) * 0x11));
        func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),1,(void *)(spA0));
        func_002badc0((*( s8 * )((u8 *)(temp_16) + (0xD))), (*( u8 * )((u8 *)((temp_18_2 + ((s32)iGpffffb3d4))) + (0xD))) + 0x71);
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCAU;
        return;
    case 0xC9:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC7U;
        return;
    case 0xCA:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCCU;
        if (func_00106330(0x5B) != 0) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCCU;
            return;
        }
        break;
    case 0xCB:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        if (func_00106330(0x5B) != 0) {
            temp_4_5 = temp_17;
            temp_18_3 = temp_4_5 * 0xE;
            if ((*( u8 * )((u8 *)((temp_18_3 + ((s32)iGpffffb3d4))) + (0xD))) == 0) {
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCCU;
                return;
            }
            (*( s8 * )((u8 *)(temp_16) + (0xD))) = func_002bab80((void *)func_00331660());
            func_00442088(spA0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17) * 0x11));
            func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),1,(void *)(spA0));
            func_002badc0((*( s8 * )((u8 *)(temp_16) + (0xD))), (*( u8 * )((u8 *)((temp_18_3 + ((s32)iGpffffb3d4))) + (0xD))) + 0x71);
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCAU;
            goto block_74;
        }
        if (func_00106330(0x5C) != 0) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC9U;
        }
block_74:
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xC7U;
        return;
    case 0xCC:                                      /* switch 1 */
        if (((s64) (func_00105f50(temp_17) << 0x38) >> 0x38) == 0) {
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCFU;
            if (func_00303a20(arg0) == 1) {
                var_8_3 = 0;
                temp_7_3 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_81:
                temp_5 = (s64) (var_8_3 << 0x30) >> 0x30;
                if (temp_5 >= temp_7_3) {
                    var_4_4 = 0;
                } else if ((*( s8 * )((u8 *)((temp_16 + temp_5)) + (0x2DA))) == 7) {
                    var_4_4 = 1;
                } else {
                    var_8_3 = (s64) ((var_8_3 + 1) << 0x30) >> 0x30;
                    goto loop_81;
                }
                if (var_4_4 == 1) {
                    func_00106390(0x59, 1);
                    (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                    (*( s8 * )((u8 *)(temp_16) + (0x13C))) = 1;
                    return;
                }
                var_8_4 = 0;
                temp_7_4 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_89:
                temp_5_2 = (s64) (var_8_4 << 0x30) >> 0x30;
                if (temp_5_2 >= temp_7_4) {
                    var_4_5 = 0;
                } else if ((*( s8 * )((u8 *)((temp_16 + temp_5_2)) + (0x2DA))) == 0xD) {
                    var_4_5 = 1;
                } else {
                    var_8_4 = (s64) ((var_8_4 + 1) << 0x30) >> 0x30;
                    goto loop_89;
                }
                if (var_4_5 == 1) {
                    func_00106390(0x59, 1);
                    (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                    (*( s8 * )((u8 *)(temp_16) + (0x13C))) = 3;
                    return;
                }
                var_8_5 = 0;
                temp_7_5 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_97:
                temp_5_3 = (s64) (var_8_5 << 0x30) >> 0x30;
                if (temp_5_3 >= temp_7_5) {
                    var_3 = 0;
                } else if ((*( s8 * )((u8 *)((temp_16 + temp_5_3)) + (0x2DA))) == 0xA) {
                    var_3 = 1;
                } else {
                    var_8_5 = (s64) ((var_8_5 + 1) << 0x30) >> 0x30;
                    goto loop_97;
                }
                if (var_3 == 1) {
                    func_00106390(0x59, 1);
                    (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                }
                var_9 = 0;
loop_111:
                temp_4_6 = (s64) (var_9 << 0x30) >> 0x30;
                if (temp_4_6 < 6) {
                    var_10 = 0;
                    temp_7_6 = (s64) ((temp_4_6 + 1) << 0x38) >> 0x38;
                    temp_6_3 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_106:
                    temp_4_7 = (s64) (var_10 << 0x30) >> 0x30;
                    if (temp_4_7 >= temp_6_3) {
                        var_3_2 = 0;
                    } else if (temp_7_6 == (*( s8 * )((u8 *)((temp_16 + temp_4_7)) + (0x2DA)))) {
                        var_3_2 = 1;
                    } else {
                        var_10 = (s64) ((var_10 + 1) << 0x30) >> 0x30;
                        goto loop_106;
                    }
                    if (var_3_2 == 1) {
                        func_00106390(0x59, 1);
                        (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                    } else {
                        var_9 = (s64) ((var_9 + 1) << 0x30) >> 0x30;
                        goto loop_111;
                    }
                }
                var_8_6 = 0;
                temp_6_4 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_116:
                temp_4_8 = (s64) (var_8_6 << 0x30) >> 0x30;
                if (temp_4_8 >= temp_6_4) {
                    var_3_3 = 0;
                } else if ((*( s8 * )((u8 *)((temp_16 + temp_4_8)) + (0x2DA))) == 9) {
                    var_3_3 = 1;
                } else {
                    var_8_6 = (s64) ((var_8_6 + 1) << 0x30) >> 0x30;
                    goto loop_116;
                }
                if (var_3_3 == 1) {
                    func_00106390(0x59, 1);
                    (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                    return;
                }
            }
        } else {
            (*( s8 * )((u8 *)(temp_16) + (0xD))) = func_002bab80((void *)func_00331660());
            func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),0,(void *)(((s32)iGpffffb44c) + ((func_00109280((*( u16 * )((u8 *)(func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA))))) + (2)))) & 0xFF) * 0x15)));
            func_00442088(spA0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17) * 0x11));
            func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),1,(void *)(spA0));
            func_002badc0((*( s8 * )((u8 *)(temp_16) + (0xD))), 0x3A);
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCDU;
            return;
        }
        break;
    case 0xCD:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        var_7 = 0;
        temp_5_4 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_127:
        temp_3_5 = (s64) (var_7 << 0x30) >> 0x30;
        if (temp_3_5 >= temp_5_4) {
            var_3_4 = 0;
        } else if ((*( s8 * )((u8 *)((temp_16 + temp_3_5)) + (0x2DA))) == 8) {
            var_3_4 = 1;
        } else {
            var_7 = (s64) ((var_7 + 1) << 0x30) >> 0x30;
            goto loop_127;
        }
        if (var_3_4 == 1) {
            temp_19 = (temp_17) * 0xE;
            temp_20_2 = (s64) (func_00247770((*( u8 * )((u8 *)((temp_19 + ((s32)iGpffffb3d4))) + (2)))) << 0x30) >> 0x30;
            (*( s32 * )((u8 *)(temp_16) + (0x10))) = func_00311930(temp_20_2, func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))), 1);
            if (func_00303a20(arg0) == 1) {
                (*( s8 * )((u8 *)(temp_16) + (0xD))) = func_002bab80((void *)func_00331660());
                func_00442088(spA0, &iGpffffa8a4, func_00311900((s64) (func_00247770((*( u8 * )((u8 *)((temp_19 + ((s32)iGpffffb3d4))) + (2)))) << 0x30) >> 0x30));
                func_00275980(spA0, sp80, 0x20);
                func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),0,(void *)(sp80));
                func_00442088(spA0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17) * 0x11));
                func_002bbd80((*( s8 * )((u8 *)(temp_16) + (0xD))),1,(void *)(spA0));
                func_002badc0((*( s8 * )((u8 *)(temp_16) + (0xD))), 0x55);
                (*( s8 * )((u8 *)(temp_16) + (0x21))) = 1;
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xD0U;
                return;
            }
            func_0034a820((*( s32 * )((u8 *)(temp_16) + (0x254))));
            func_00106390(0x59, 1);
            func_001102f0(spE8, 0x140, 0xA5, 300.0f);
            func_002b2a60(&spFC, 0xFF, 0xFF, 0xFF, 0xFF);
            func_003489c0((*( s32 * )((u8 *)(temp_16) + (0x308))), spE8, spFC, 0, -1, 0, 0, 0, 1.0f);
            func_00348c30((*( s32 * )((u8 *)(temp_16) + (0x308))), 0x14);
            (*( s16 * )((u8 *)(temp_16) + (0x2D8))) = 0;
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xD1U;
            return;
        }
        temp_17_3 = (s64) (func_00247770((*( u8 * )((u8 *)((((temp_17) * 0xE) + ((s32)iGpffffb3d4))) + (2)))) << 0x30) >> 0x30;
        (*( s32 * )((u8 *)(temp_16) + (0x10))) = func_00311930(temp_17_3, func_002e48a0((*( s8 * )((u8 *)(temp_16) + (0x2F9))), (*( s8 * )((u8 *)(temp_16) + (0x2FA)))), 0);
        func_0034a820((*( s32 * )((u8 *)(temp_16) + (0x254))));
        func_00106390(0x59, 1);
        func_001102f0(spD8, 0x140, 0xA5, 300.0f);
        func_002b2a60(&spF8, 0xFF, 0xFF, 0xFF, 0xFF);
        func_003489c0((*( s32 * )((u8 *)(temp_16) + (0x308))), spD8, spF8, 0, -1, 0, 0, 0, 1.0f);
        func_00348c30((*( s32 * )((u8 *)(temp_16) + (0x308))), 0x14);
        (*( s16 * )((u8 *)(temp_16) + (0x2D8))) = 0;
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xD1U;
        return;
    case 0xCE:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xCFU;
        if (func_00303a20(arg0) == 1) {
            var_8_7 = 0;
            temp_7_8 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_141:
            temp_5_5 = (s64) (var_8_7 << 0x30) >> 0x30;
            if (temp_5_5 >= temp_7_8) {
                var_4_6 = 0;
            } else if ((*( s8 * )((u8 *)((temp_16 + temp_5_5)) + (0x2DA))) == 7) {
                var_4_6 = 1;
            } else {
                var_8_7 = (s64) ((var_8_7 + 1) << 0x30) >> 0x30;
                goto loop_141;
            }
            if (var_4_6 == 1) {
                func_00106390(0x59, 1);
                (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                (*( s8 * )((u8 *)(temp_16) + (0x13C))) = 1;
                return;
            }
            var_8_8 = 0;
            temp_7_9 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_149:
            temp_5_6 = (s64) (var_8_8 << 0x30) >> 0x30;
            if (temp_5_6 >= temp_7_9) {
                var_4_7 = 0;
            } else if ((*( s8 * )((u8 *)((temp_16 + temp_5_6)) + (0x2DA))) == 0xD) {
                var_4_7 = 1;
            } else {
                var_8_8 = (s64) ((var_8_8 + 1) << 0x30) >> 0x30;
                goto loop_149;
            }
            if (var_4_7 == 1) {
                func_00106390(0x59, 1);
                (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                (*( s8 * )((u8 *)(temp_16) + (0x13C))) = 3;
                return;
            }
            var_8_9 = 0;
            temp_7_10 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_157:
            temp_5_7 = (s64) (var_8_9 << 0x30) >> 0x30;
            if (temp_5_7 >= temp_7_10) {
                var_3_5 = 0;
            } else if ((*( s8 * )((u8 *)((temp_16 + temp_5_7)) + (0x2DA))) == 0xA) {
                var_3_5 = 1;
            } else {
                var_8_9 = (s64) ((var_8_9 + 1) << 0x30) >> 0x30;
                goto loop_157;
            }
            if (var_3_5 == 1) {
                func_00106390(0x59, 1);
                (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
            }
            var_9_2 = 0;
loop_171:
            temp_4_9 = (s64) (var_9_2 << 0x30) >> 0x30;
            if (temp_4_9 < 6) {
                var_10_2 = 0;
                temp_7_11 = (s64) ((temp_4_9 + 1) << 0x38) >> 0x38;
                temp_6_6 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_166:
                temp_4_10 = (s64) (var_10_2 << 0x30) >> 0x30;
                if (temp_4_10 >= temp_6_6) {
                    var_3_6 = 0;
                } else if (temp_7_11 == (*( s8 * )((u8 *)((temp_16 + temp_4_10)) + (0x2DA)))) {
                    var_3_6 = 1;
                } else {
                    var_10_2 = (s64) ((var_10_2 + 1) << 0x30) >> 0x30;
                    goto loop_166;
                }
                if (var_3_6 == 1) {
                    func_00106390(0x59, 1);
                    (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                    (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                } else {
                    var_9_2 = (s64) ((var_9_2 + 1) << 0x30) >> 0x30;
                    goto loop_171;
                }
            }
            var_8_10 = 0;
            temp_6_7 = (s8)((*( s8 * )((u8 *)(temp_16) + (0x2DF))));
loop_176:
            temp_4_11 = (s64) (var_8_10 << 0x30) >> 0x30;
            if (temp_4_11 >= temp_6_7) {
                var_3_7 = 0;
            } else if ((*( s8 * )((u8 *)((temp_16 + temp_4_11)) + (0x2DA))) == 9) {
                var_3_7 = 1;
            } else {
                var_8_10 = (s64) ((var_8_10 + 1) << 0x30) >> 0x30;
                goto loop_176;
            }
            if (var_3_7 == 1) {
                func_00106390(0x59, 1);
                (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
                (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
                return;
            }
        }
        break;
    case 0xCF:                                      /* switch 1 */
        func_00106390(0x59, 1);
        func_00106390(0x5D, 1);
        func_00106390(0x5F, 1);
        (*( s8 * )((u8 *)(temp_16) + (0))) = 0xE;
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xD2U;
        func_00314400((u8 *)(*( s32 * )((u8 *)(temp_16) + (0x148))), 0);
        return;
    case 0xD0:                                      /* switch 1 */
        if (func_002bb680((*( s8 * )((u8 *)(temp_16) + (0xD)))) != 0) {
            func_002bbcf0((*( s8 * )((u8 *)(temp_16) + (0xD))));
            return;
        }
        func_002bb550((*( s8 * )((u8 *)(temp_16) + (0xD))));
        func_0034a820((*( s32 * )((u8 *)(temp_16) + (0x254))));
        func_00106390(0x59, 1);
        func_001102f0(spC8, 0x140, 0xA5, 300.0f);
        func_002b2a60(&spF4, 0xFF, 0xFF, 0xFF, 0xFF);
        func_003489c0((*( s32 * )((u8 *)(temp_16) + (0x308))), spC8, spF4, 0, -1, 0, 0, 0, 1.0f);
        func_00348c30((*( s32 * )((u8 *)(temp_16) + (0x308))), 0x14);
        (*( s16 * )((u8 *)(temp_16) + (0x2D8))) = 0;
        (*( u8 * )((u8 *)(temp_16) + (1))) = 0xD1U;
        return;
    case 0xD1:                                      /* switch 1 */
        temp_2_6 = (s16)(func_002b2cb0((*( s16 * )((u8 *)(temp_16) + (0x2D8))), 1, 0x32, 0, 1));
        (*( s16 * )((u8 *)(temp_16) + (0x2D8))) = temp_2_6;
        if (((s64) ((s64) temp_2_6 << 0x30) >> 0x30) == 0x14) {
            func_0045af60(1, 0, 4, 5);
        }
        if (((*( s8 * )((u8 *)(func_0034a630((*( s32 * )((u8 *)(temp_16) + (0x254))))) + (4))) == 4) && ((*( s16 * )((u8 *)(temp_16) + (0x2D8))) >= 0x14)) {
            (*( s8 * )((u8 *)(temp_16) + (0))) = 0xC;
            (*( u8 * )((u8 *)(temp_16) + (1))) = 0xA0U;
        }
        break;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003097e0);
#endif

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
/* measured: signedness census 16 -> 0 (`solve_signedness` lb 33/lbu 41 ->
   41/33, exact; opclass surplus 20 -> 4, only the pre-existing andi +2 /
   dsll32/dsra32 -1 extension-shape floor remains). The eight retail-lb sites
   are plain-deref/subscript reads the solver does not group: te[1] x3
   (1906/1913/2013), *te (0xB compare), D_00882FB0[] (0x2FB), *(p+0x13A) x2,
   *(te+sidx); all spelled *(s8 *)(base+off) per the file's existing
   convention (p stays u8*: the *(p+1) kind load is lbu on both sides).
   Count-neutral (obj 769I). The solver's kind->s8 accept is a trap (switch
   on 0xC2 breaks) and was not taken. */
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
            te2 = func_002b6150((s16)(*(s8 *)(te + 1) + 0x168));
            *(te2 + 0x85) = c1.b0;
            *(te2 + 0x86) = c1.b1;
            *(te2 + 0x87) = c1.b2;
            *(te2 + 0x88) = c1.b3;
            if (*(s8 *)te == 0xB && func_00106330(0x1308) == 0) {
                func_002b2a60(&c2, 0xFF, 0xCC, 0xFF, 0xFF);
                te2 = func_002b6150((s16)(*(s8 *)(te + 1) + 0x168));
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
        te = func_002b6150((s16)(*(s8 *)(D_00882FB0 + *(s16 *)(p + 0x11E) * 2) + 0x2FB));
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
            if ((f276 & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
                func_003307b0(arg0, 5, D_00882FB0);
                return;
            }
            if (f27a & 0x1000) {
                func_003307b0(arg0, 1, D_00882FB0);
                return;
            }
            if ((f276 & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
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
                    func_002badc0(*(s8 *)(p + 0xD), *(s8 *)(te + sidx) + 2);
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
                    func_003147e0(arg0, *te, v5, (s16)(*(s8 *)(te + 1) + 0x168), (s16)(i * 2 + 2), 1);
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

