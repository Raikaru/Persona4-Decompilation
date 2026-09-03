/* Original translation unit btlPanelAnalyze.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_0043f9c8();
void func_00201650(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8);
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
void func_00442088(void *dst, const void *fmt, s32 value);
s32 func_00442948(const char *text);
void func_0046d730(const void *file, s32 line);
extern u8 D_00628F80[];
extern char iGpffffa59c;
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);
extern f32 D_008872F8[];
extern f32 fGpffff847c;
extern f32 fGpffff80cc;

static inline f32 panelAdd2(f32 left, f32 right) { return left + right; }

/* measured: opt_propagation off preserves the split mode live range and
   retail's parameter-save order (MATCH nd0; without it, nd10). */
#pragma opt_propagation off
// FUN_00218760
void func_00218760(void *arg0, u32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    struct {
        char text[128];
    } locals;
    u8 blue;
    s32 mode;
    s32 mode2;
    s32 length;
    s32 i;
    u8 color0;
    u8 color1;
    u8 color2;
    u8 color3;
    u8 color4;
    u8 color5;
    u8 color6;
    f32 py;
    f32 px;
    f32 y;

    px = fparg0;
    py = fparg1;
    mode = arg2;
    switch (mode) {
    case 0:
    case 1:
        goto mode01;
    case 2:
    case 3:
        goto mode23;
    default:
        goto mode_error;
    }
mode01:
    color0 = 0x89;
    color1 = 0xFF;
    blue = 0x1F;
    color2 = 0xFF;
    color3 = 0x24;
    color4 = 0x4C;
    color5 = 0;
    color6 = 0xFF;
    goto mode_done;
mode23:
    color0 = 0x70;
    color1 = color0;
    blue = color0;
    color2 = 0xFF;
    color3 = 8;
    color4 = 8;
    color5 = 8;
    color6 = 0xFF;
    goto mode_done;
mode_error:
    func_0046d730(D_00628F80, 0x12D);
mode_done:
    mode2 = mode;
    func_00201650(arg0, 0xA, 0x40, px, py,
                  color0, color1, blue, color2);
    func_00201650(arg0, 0xA, 0x41, 81.0f + px, py,
                  color0, color1, blue, color2);
    y = 2.0f + py;
    func_00201650(arg0, 0xA, 0x46, 6.0f + px, y,
                  color3, color4, color5, color6);
    switch (mode2) {
    case 0:
    case 2:
        func_00201650(arg0, 0xA, 0x44, 59.0f + px, y,
                      color3, color4, color5, color6);
        break;
    case 1:
    case 3:
        func_00201650(arg0, 0xA, 0x45, 59.0f + px, y,
                      color3, color4, color5, color6);
        break;
    default:
        func_0046d730(D_00628F80, 0x13F);
        break;
    }
    switch (mode2) {
    case 0:
    case 1:
        px = panelAdd2(96.0f, px);
        func_00442088(locals.text, &iGpffffa59c, arg1);
        length = func_00442948(locals.text);
        i = 0;
        y = 4.0f + py;
        while (i < length) {
            func_00201650(arg0, 0xC, locals.text[i] - 0x27,
                          px, y, 0x89, 0xFF, 0x1F, 0xFF);
            px += 16.0f;
            i += 1;
        }
        break;
    case 2:
    case 3:
        break;
    default:
        func_0046d730(D_00628F80, 0x14E);
        break;
    }
}
/* measured: restores propagation after func_00218760. */
#pragma opt_propagation on

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


/* measured: aggregate vector copies and paired 32-bit copy loop; named
   temporaries reproduce the 003e9cb0 argument-load order. The dst/src_base
   saved-register colouring (retail dst $s1, src_base $s0) needs the source
   pointer re-derived from src_base INSIDE the copy loop (`src = (s32 *)src_base`
   each iteration, consumed after the loop): a loop-carried alias of src_base
   drops it to $s0. Found by tools/permute_ast.py, minimised to this one line. */
// FUN_00218EA0
void func_00218ea0(u8 *arg0) {
    typedef struct { f32 x, y, z, w; } PanelVec4X;
    s32 *src;
    u8 *temp_2;
    u8 *temp_2_2;
    u32 src_base;
    u8 *var_6;
    u8 *var_5;
    u8 *dst;
    s32 var_4;
    s32 temp_3;
    s32 temp_2_3;
    PanelVec4X tmp;

    dst = arg0;
    func_003e8110(func_00457120());
    temp_2 = func_004571a0();
    *(PanelVec4X *)(dst + 0x14) = *(PanelVec4X *)(temp_2 + 0x18);
    tmp.x = fGpffff847c;
    tmp.y = fGpffff847c;
    tmp.z = fGpffff847c;
    tmp.w = 1.0f;
    func_003c38b0(temp_2, &tmp);
    temp_2_2 = func_004571c0();
    *(PanelVec4X *)(dst + 0x24) = *(PanelVec4X *)(temp_2_2 + 0x18);
    tmp.x = fGpffff80cc;
    tmp.y = 1.0f;
    tmp.z = fGpffff80cc;
    tmp.w = 1.0f;
    func_003c38b0(temp_2_2, &tmp);
    src_base = (u32)(temp_2_2 + 4);
    var_6 = (u8 *)(*(s32 *)(u8 *)src_base + 0x10);
    var_5 = dst + 0x40;
    var_4 = 8;
    do {
        temp_3 = *(s32 *)var_6;
        src = (s32 *)(u8 *)src_base;
        temp_2_3 = *(s32 *)(var_6 + 4);
        var_6 += 8;
        var_4 -= 1;
        *(s32 *)var_5 = temp_3;
        *(s32 *)(var_5 + 4) = temp_2_3;
        var_5 += 8;
    } while (var_4 > 0);
    temp_2_2 = (u8 *)(*(u32 *)(func_00457120() + 4));
    temp_2 = (u8 *)*src;
    func_003e9cb0(temp_2, temp_2_2 + 0x10, 0);
    *(f32 *)(dst + 0x80) = *(f32 *)(func_00457120() + 0x80);
    *(f32 *)(dst + 0x84) = *(f32 *)(func_00457120() + 0x84);
    func_003e8180(func_00457120(), 35.0f);
    func_003e81c0(func_00457120(), (f32)(s32)0xDAC0);
    func_003e8120(func_00457120());
}

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

