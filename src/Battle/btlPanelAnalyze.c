/* Original translation unit btlPanelAnalyze.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_0043f9c8();
void func_00201650(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
s32 func_0023a6b0(s32 arg0, s64 arg1);
void func_00364c50(void);
void func_00364c70(void);
void func_003c38b0(void *arg0, void *arg1);
void func_003e8110(void *arg0);
void func_003e8120(void *arg0);
void func_003e8180(void *arg0, f32 arg1);
void func_003e81c0(void *arg0, f32 arg1);
void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
u8 *func_00457120(void);
u8 *func_004571a0(void);
u8 *func_004571c0(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);
extern f32 D_008872F8[];
extern f32 iGpffff847c;
extern f32 iGpffff80cc;

static inline f32 panelAdd2(f32 left, f32 right) { return left + right; }

/* measured: extreme saved-register pressure (9 saved regs + 3 fp). Retail keeps 7
   color bytes in $16..$18/$21..$23/$30 and loads them via daddiu (u8 locals); mwcc
   b210 spills most to the stack (frame 0x120 vs retail 0x150) and shifts the whole
   allocation (arg0 $s5 vs $s4, arg2 $s4 vs $s3). u8 colors give retail's daddiu but
   add andi-0xff masking; s32 colors drop the masking but lose the daddiu (nd 192).
   Tried u8/s32, m2c declaration order (colors last), and reordering; best 192.
   Saved-register-rotation + stack-layout floor. */
// FUN_00218760
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00218760);

typedef struct {
    f32 x, y, z;
    f32 _pad[3];
    f32 scale;
    f32 _pad2;
    u32 color[4];
    u32 _pad3[4];
} PanelQuad;

// FUN_00218AF0
void func_00218af0(f32 fparg0, f32 fparg1, f32 fparg2) {
    PanelQuad quads[4];
    u8 *p;
    f32 zval;
    f32 scale;

    zval = D_008872F8[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    p = (u8 *)&quads[0];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x18) = scale;
    *(u32 *)(p + 0x20) = 0x43090000;
    *(u32 *)(p + 0x24) = 0x437F0000;
    *(u32 *)(p + 0x28) = 0x41F80000;
    *(u32 *)(p + 0x2C) = 0x437F0000;
    p = (u8 *)&quads[1];
    *(f32 *)(p + 0) = 323.0f + fparg0;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x18) = scale;
    *(u32 *)(p + 0x20) = 0x43090000;
    *(u32 *)(p + 0x24) = 0x437F0000;
    *(u32 *)(p + 0x28) = 0x41F80000;
    *(u32 *)(p + 0x2C) = 0x437F0000;
    p = (u8 *)&quads[2];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1 + fparg2;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x18) = scale;
    *(u32 *)(p + 0x20) = 0x43090000;
    *(u32 *)(p + 0x24) = 0x437F0000;
    *(u32 *)(p + 0x28) = 0x41F80000;
    *(u32 *)(p + 0x2C) = 0x437F0000;
    p = (u8 *)&quads[3];
    *(f32 *)(p + 0) = 374.0f + fparg0;
    *(f32 *)(p + 4) = fparg1 + fparg2;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x18) = scale;
    *(u32 *)(p + 0x20) = 0x43090000;
    *(u32 *)(p + 0x24) = 0x437F0000;
    *(u32 *)(p + 0x28) = 0x41F80000;
    *(u32 *)(p + 0x2C) = 0x437F0000;
    D_00887300[0](1, 0);
    func_00364c50();
    D_00887310[0](4, &quads[0], 4);
    func_00364c70();
}

// FUN_00218C60
void func_00218c60(u8 *arg0, s32 arg1, s64 arg2, f32 fparg0, f32 fparg1) {
    s32 temp;
    f32 temp_f12;
    f32 temp_f13;

    temp = func_0023a6b0(arg1, (s64)(arg2 << 0x30) >> 0x30);
    func_00201650(arg0, 0xE, 0x43, fparg0, fparg1, 0x24, 0x4C, 0, 0xFF);
    temp_f12 = panelAdd2(fparg0, 2.0f);
    temp_f13 = panelAdd2(fparg1, 2.0f);
    if (temp & 0x08000000) {
        func_00201650(arg0, 0xD, 0x36, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (temp & 0x01000000) {
        func_00201650(arg0, 0xD, 0x38, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (temp & 0x10000000) {
        func_00201650(arg0, 0xD, 0x37, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (temp & 0x04000000) {
        func_00201650(arg0, 0xD, 0x39, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (temp & 0x02000000) {
        func_00201650(arg0, 0xD, 0x35, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    func_00201650(arg0, 0xD, 0x3A, temp_f12, temp_f13, 0x89, 0xFF, 0x1F, 0xFF);
}

// FUN_00218E50
void func_00218e50(u8 *arg0, s32 arg1) {
    func_0043f9c8(arg0, 0, 0x90);
    *(s32 *)(arg0 + 0x10) = arg1;
    *(s16 *)(arg0 + 0x2) = 0;
}


/* measured: probed all six callee declarations used by this function.
   Best archived body is build/F218_func_00218ea0_best_nd14.c.txt; named
   temporaries reproduce the retail argument-load order. Object 440B versus
   the 448B retail window, normalized_diff 14. Register-coloring residuals
   remain after five source-shape probes; retained as bare INCLUDE_ASM. */
// FUN_00218EA0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00218ea0);

// FUN_00219060
void func_00219060(u8 *arg0) {
    u8 *temp;

    func_003e8110(func_00457120());
    func_003c38b0(func_004571a0(), arg0 + 0x14);
    temp = func_004571c0();
    func_003c38b0(temp, arg0 + 0x24);
    func_003e9cb0((void *)*(s32 *)(temp + 4), arg0 + 0x40, 0);
    func_003e8180(func_00457120(), *(f32 *)(arg0 + 0x80));
    func_003e81c0(func_00457120(), *(f32 *)(arg0 + 0x84));
    func_003e8120(func_00457120());
}

/* measured: the arg0[0x88] update uses the FPU accumulator idiom (adda.s $f0,$f1
   then madd.s $f0,$f2,$f3 — a fused multiply-add of 0 + arg0[0x88] + iGpffff8480*f3)
   which m2c marks M2C_ERROR and no C float spelling reproduces byte-for-byte
   (same floor as btlAICommand func_001de370). The rest of the function (the
   state-machine switch on arg0[2], the D_00626FE0/D_00628F60 table pick, the
   D_008C025C signed-byte float conversion, the func_003e0870/05f0 render calls,
   the 0x28/0xFF fade counter) is readable. FPU-accumulator floor; no real body
   was produced for this 1632B retail window. */
// FUN_00219130
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00219130);

/* measured: the 7-element spell loop uses the FPU accumulator idiom (adda.s
   $f1,$f22 / madd.s $f23,$f0,$f20 in the loop body at 0x119EA4) which m2c marks
   M2C_ERROR and no C float spelling reproduces byte-for-byte (same floor as
   btlAICommand func_001de370 and this file's func_00219130). The rest (the
   tempered-float fade, the D_00628FB8 spell table, the func_00218760/18af0/18c60
   panel draws, the D_00887300/10 render dispatch) is readable. FPU-accumulator
   floor; no real body was produced for this 4128B retail window. */
// FUN_00219790
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00219790);

