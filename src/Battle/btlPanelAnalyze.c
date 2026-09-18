/* Original translation unit btlPanelAnalyze.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "btl_panel_internal.h"
extern void func_0043f9c8();
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
extern s32 (*D_00887310[])(s32, void *, s32);
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

/* 1624/1632 bytes; 53 resolved relocations and eight zero alignment bytes.
 * The explicit zero-add expression emits retail's adda.s/madd.s sequence.
 * Preserve unsigned controller conversion before subtracting 128, matrix
 * initialization before composition, and callback-visible field reloads. */
// FUN_00219130
void func_00219130(u8 *arg0) {
    typedef struct { f32 x, y, z; } AnalyzeVec3;
    typedef struct { f32 matrix[16]; } AnalyzeMatrix;
    extern u8 D_005DC9C8[];
    extern u8 D_00626FE0[][24];
    extern u8 D_00628F60[];
    extern u8 D_008C025C[];
    extern u8 D_0060A0D0[];
    extern u8 D_0060A0E0[];
    extern u8 D_00795020[];
    extern u8 *iGpffffb3cc;
    extern f32 fGpffff8480;
    extern f32 fGpffff8484;
    u8 *func_00478750(u8 *);
    void func_004787e0(u8 *);
    void func_0047aa30(u8 *, void *);
    void func_00478ea0(u8 *, void (*)(u8 *), u8 *);
    void func_00478eb0(u8 *, void (*)(u8 *), u8 *);
    void *func_003e4320(void *, const void *, const void *);
    void *func_003e0870(void *, const void *, f32, s32);
    void *func_003e05f0(void *, const void *, const void *);
    u8 *func_0047a2f0(u8 *);
    void func_0047a850(u8 *);
    void func_0047a220(u8 *, const void *);
    void func_00479100(void *, u8 *);
    AnalyzeVec3 position;
    AnalyzeVec3 transformed;
    AnalyzeMatrix rotation;
    u8 color[4];
    u8 *model;
    u8 *entry;
    u8 *matrix;
    u8 *unit;
    u16 flags;
    u32 table_address;
    f32 delta;
    f32 width;
    f32 height;
    f32 translated;

    if (*(u16 *)(arg0 + 2) == 0) {
        return;
    }
    switch (*(u16 *)(arg0 + 2)) {
    case 1:
        unit = *(u8 **)(arg0 + 8);
        model = func_00478750(*(u8 **)(*(u8 **)(unit + 0x30) + 0xA00));
        *(u8 **)(arg0 + 0xC) = model;
        func_0047aa30(model, D_005DC9C8);
        *(u32 *)(*(u8 **)(arg0 + 0xC) + 0xD8) &= ~0x100;
        entry = *(u8 **)(unit + 0x30);
        if (entry[0xA2] == 1) {
            table_address = *(u16 *)(entry + 0xA4) * 0xE8;
            table_address += (u32)iGpffffb3cc;
            flags = *(u16 *)(table_address + 0x18);
            if (flags & 2) {
                *(u32 *)(*(u8 **)(arg0 + 0xC) + 0xD8) |= 0x200;
            }
            if (flags & 8) {
                *(u32 *)(*(u8 **)(arg0 + 0xC) + 0xD8) |= 0x400;
            }
            if (flags & 0x10) {
                *(u32 *)(*(u8 **)(arg0 + 0xC) + 0xD8) |= 0x800;
            }
        }
        func_00478ea0(*(u8 **)(arg0 + 0xC), func_00218ea0, arg0);
        func_00478eb0(*(u8 **)(arg0 + 0xC), func_00219060, arg0);
        *(u16 *)(arg0 + 0) &= ~2;
        *(u16 *)(arg0 + 0) |= 1;
        *(f32 *)(arg0 + 0x88) = 0.0f;
        arg0[6] = 0;
        *(u16 *)(arg0 + 2) = 3;
        break;
    case 2:
        func_004787e0(*(u8 **)(arg0 + 0xC));
        model = func_00478750(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 8) + 0x30) + 0xA00));
        *(u8 **)(arg0 + 0xC) = model;
        func_0047aa30(model, D_005DC9C8);
        *(u32 *)(*(u8 **)(arg0 + 0xC) + 0xD8) &= ~0x100;
        func_00478ea0(*(u8 **)(arg0 + 0xC), func_00218ea0, arg0);
        func_00478eb0(*(u8 **)(arg0 + 0xC), func_00219060, arg0);
        *(f32 *)(arg0 + 0x88) = 0.0f;
        *(u16 *)(arg0 + 2) = 3;
    case 3:
        if (*(u16 *)(arg0 + 4) < 5) {
            break;
        }
        unit = *(u8 **)(*(u8 **)(arg0 + 8) + 0x30);
        if (unit[0xA2] == 1) {
            entry = D_00626FE0[*(u16 *)(unit + 0xA4)];
        } else {
            entry = D_00628F60;
        }
        delta = (f32)D_008C025C[0] - 128.0f;
        if (delta < -48.0f || delta > 48.0f) {
            *(f32 *)(arg0 + 0x88) = (0.0f + *(f32 *)(arg0 + 0x88)) + fGpffff8480 * delta;
        }
        if (entry[0x14] < 180 || entry[0x15] < 180) {
            if (*(f32 *)(arg0 + 0x88) > (f32)entry[0x14]) {
                *(f32 *)(arg0 + 0x88) = (f32)entry[0x14];
            } else if (*(f32 *)(arg0 + 0x88) < (f32)-entry[0x15]) {
                *(f32 *)(arg0 + 0x88) = (f32)-entry[0x15];
            }
        }
        unit = func_00457120();
        translated = *(f32 *)(unit + 0x68);
        width = 2.0f * (translated * fGpffff8484);
        height = 2.0f * (*(f32 *)(unit + 0x6C) * fGpffff8484);
        matrix = *(u8 **)(func_00457120() + 4) + 0x10;
        translated = 320.0f;
        translated += *(f32 *)(entry + 0);
        position.x = (0.5f + -translated / 640.0f) * width;
        position.y = (0.5f + -(224.0f + *(f32 *)(entry + 4)) / 448.0f) * height;
        translated = (f32)(s32)0x226;
        translated += *(f32 *)(entry + 8);
        position.z = translated;
        func_003e4320(&transformed, &position, matrix);
        func_003e0870(&rotation, D_0060A0E0, *(f32 *)(arg0 + 0x88), 0);
        func_003e0870(&rotation, D_0060A0D0, *(f32 *)(entry + 0xC), 2);
        func_003e0870(&rotation, D_0060A0E0, 180.0f + *(f32 *)(entry + 0x10), 2);
        func_003e05f0(func_0047a2f0(*(u8 **)(arg0 + 0xC)), &rotation, matrix);
        translated = *(f32 *)(matrix + 0x30) + transformed.x;
        *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0xC)) + 0x30) = translated;
        translated = *(f32 *)(matrix + 0x34) + transformed.y;
        *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0xC)) + 0x34) = translated;
        translated = *(f32 *)(matrix + 0x38) + transformed.z;
        *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0xC)) + 0x38) = translated;
        if (arg0[6] < 0xFF) {
            if (arg0[6] < 0xD7) {
                arg0[6] += 0x28;
            } else {
                arg0[6] = 0xFF;
            }
            func_0047a850(*(u8 **)(arg0 + 0xC));
            color[0] = 0xFF;
            color[1] = 0xFF;
            color[2] = 0xFF;
            color[3] = arg0[6];
            func_0047a220(*(u8 **)(arg0 + 0xC), color);
        }
        func_00479100(D_00795020, *(u8 **)(arg0 + 0xC));
        break;
    case 4:
        func_004787e0(*(u8 **)(arg0 + 0xC));
        *(u8 **)(arg0 + 0xC) = NULL;
        *(u16 *)(arg0 + 0) &= ~1;
        *(u16 *)(arg0 + 2) = 0;
        break;
    }
}

/* measured: probe 915 differing words (reloc-masked), fnalign 319 edits +7 reloc-only; object 1043 vs retail 1032 instrs (4128B window 0x1020) +11 +1.07% inside 1001-1063 (+-3%) band.
 * Signature (s32 arg0, u8 *arg1): arg0 unused matches retail $4 dead (lw $4,0x10($5) overwrites entry $4, daddu $20,$5 saves live pointer); romwright (int, void*) arity.
 * Frame text[128] at 0x90 plus PanelQuad quads[3] at 0x110 (64B each) fills 0x1D0 frame; object 0x1E0 (+16) from extra spills, offsets 0x160 vs 0x90.
 * Free pragma round (one probe call, 7 variants): base 924 best; common_off 968 (+44), loopinv_on 942 (+18), unroll_off tie, sched_off tie, peephole_off 973 (+49), dead_off 942 (+18). No pragma kept.
 * Subscript round (one call, 7 variants): base 924 best; off_hoist 949 (+25), subscript 947 (+23), spell/cmds/text tie, str_hoist 949 (+25, +1 instr). Base pointer arithmetic retained.
 * Loop-counter round 7n (one call, 3 variants): base/shared/reuse all 924 tie; three loops already distinct (i_name/i_spell/i_skill), no call-free vs call split.
 * Address round 7p (one call, 3 variants): hoist_tbl 915 (-9) adopted (u8 *tbl = iGpffffb3c4+idx*0x3C, tbl[2] for kind and tile); hoist_uA64 931 (+7) rejected, reload of *(unit+0xA64) retained per 7k step 3.
 * Colouring round (one call, 3 variants): base/no_base/swap all 915 tie; adopted no_base (folds unitBase into unit, removes meaningless temporary, same score cleaner).
 * Accumulator: y22=(0.0f+yBase)+fade*22.0f and y24=(0.0f+yBase)+fade*24.0f emit retail adda.s/madd.s per 00219130 precedent; single-product +0.0 sites preserved.
 * Remaining: branch polarity (beqz vs bnez), saved-reg colour ($s0/$s1 unit), float regs ($f2/$f21), stack offsets; exchange class not isolated (7m/7o deferred, body already bare-decl 7o form). */
// FUN_00219790 NONMATCHING
#ifdef NON_MATCHING
void func_00219790(s32 arg0, u8 *arg1) {
    extern f32 fGpffff84a4;
    extern u8 *iGpffffb3c4;
    extern u8 *iGpffffb444;
    extern u16 D_00628FB8[];
    f32 func_0044b610(f32);
    f32 func_0044b7b0(f32);
    void func_00201350(void);
    void func_002012d0(u8 *, f32, f32);
    void func_00201720(u8 *, f32, f32);
    f32 func_00201950(u8 *, s32, s32);
    s32 func_00231e20(void *);
    u16 func_00231f80(void *);
    u16 func_00232290(void *);
    u32 func_0023e130(void *);
    u16 *func_0023e140(void *);
    u8 *func_00243840(u16);
    s32 func_001f0950(s32, s32);
    u8 *func_00452560(s32);
    int func_00275020(f32, f32, f32, s32, s32, s32, const void *, s32, s32);
    char text[128];
    PanelQuad quads[3];
    u8 *work;
    u8 *unit;
    u16 mode;
    u16 enemyIdx;
    f32 fade;
    f32 fade2;
    f32 tmp;
    f32 tmp2;
    f32 x0;
    f32 yBase;
    f32 y22;
    f32 y24;
    s32 len;
    s32 i_name;
    s32 i_spell;
    s32 i_skill;
    u32 v;
    u32 v2;
    u16 *cmds;
    u16 spell;
    (void)arg0;
    work = func_00452560(*(s32 *)(arg1 + 0x10));
    if (((*(u32 *)work & 1) == 0) || ((*(u16 *)arg1 & 1) == 0)) {
        return;
    }
    mode = *(u16 *)(arg1 + 4);
    func_00201350();
    func_002012d0(work, 0.0f, 0.0f);
    unit = *(u8 **)(*(u8 **)(arg1 + 8) + 0x30);
    enemyIdx = *(u16 *)(unit + 0xA4);
    if (mode < 4) {
        fade = 0.0f;
    } else if (mode < 10) {
        fade = 1.0f - func_0044b610(fGpffff84a4 * (f32)(s32)(mode - 4) / 6.0f);
    } else {
        fade = 1.0f;
    }
    if (fade > 0.0f) {
        tmp = (1.0f - fade) * -500.0f;
        func_00201650(work, 10, 0x47, 103.0f + tmp, 103.0f, 0x89, 0xFF, 0x1F, 0xFF);
        func_00201650(work, 13, 0x2A, 30.0f + tmp, 147.0f, 0x24, 0x4C, 0, 0xFF);
        if ((*(u16 *)arg1 & 8) == 0) {
            f32 nx;
            nx = 60.0f + tmp;
            func_00442088(text, &iGpffffa59c, func_00231e20(*(u8 **)(unit + 0xA64)) & 0xFF);
            len = func_00442948(text);
            if (len >= 3) {
                func_0046d730(D_00628F80, 0xF4);
            }
            nx += ((f32)(2 - len) * 22.0f) / 2.0f;
            i_name = 0;
            while (i_name < len) {
                func_00201650(work, 13, text[i_name] - 0x13, nx, 140.0f, 0x0D, 0x1B, 0, 0xFF);
                nx += 22.0f;
                i_name += 1;
            }
        } else {
            func_00201650(work, 10, 0x4A, 68.0f + tmp, 138.0f, 0x0D, 0x1B, 0, 0xFF);
        }
        {
            u8 *tbl = iGpffffb3c4 + (u32)enemyIdx * 0x3C;
            if (tbl[2] == 0x17) {
                func_00201650(work, 10, 0x59, 20.0f + tmp, 108.0f, 0x70, 0x70, 0x70, 0xFF);
            } else {
                u8 kind;
                f32 w;
                kind = tbl[2];
                w = func_00201950(work, 14, (s32)kind + 0x20);
                func_00201650(work, 14, (s32)tbl[2] + 0x20, (57.0f - w / 2.0f) + tmp, 110.0f, 0x24, 0x4C, 0, 0xFF);
            }
        }
        func_00275020(112.0f + tmp, 136.0f, 0.0f, 0x89FF1FFF, 0, 1, iGpffffb444 + (u32)enemyIdx * 0x15, 0, -1);
        if ((*(u16 *)arg1 & 8) == 0) {
            v = func_00231f80(*(u8 **)(unit + 0xA64)) & 0xFFFF;
            if (v >= 1000) {
                v = 999;
            }
            func_00218760(work, v, 0, 15.0f + tmp, 167.0f);
            v2 = func_00232290(*(u8 **)(unit + 0xA64)) & 0xFFFF;
            if (v2 >= 1000) {
                v2 = 999;
            }
            func_00218760(work, v2, 1, 15.0f + tmp, 187.0f);
        } else {
            f32 bx;
            bx = 15.0f + tmp;
            func_00218760(work, 0, 2, bx, 167.0f);
            func_00218760(work, 0, 3, bx, 187.0f);
            tmp += 111.0f;
            func_00201650(work, 10, 0x48, tmp, 166.0f, 0x70, 0x70, 0x70, 0xFF);
            func_00201650(work, 10, 0x49, 22.0f + tmp, 166.0f, 0x70, 0x70, 0x70, 0xFF);
            func_00201650(work, 10, 0x4A, 7.0f + tmp, 176.0f, 0, 0, 0, 0xFF);
        }
    }
    if ((s32)mode < 0) {
        fade = 0.0f;
    } else if (mode < 8) {
        fade = 1.0f - func_0044b610(fGpffff84a4 * (f32)mode / 8.0f);
    } else {
        fade = 1.0f;
    }
    if (fade > 0.0f) {
        f32 inv;
        inv = 1.0f - fade;
        func_00201720(work, 1.0f, fade);
        func_00218af0(-10.0f, 215.0f + ((51.0f * inv) / 2.0f), 51.0f * fade);
        tmp = 19.0f;
        yBase = 217.0f + ((49.0f * inv) / 2.0f);
        y22 = (0.0f + yBase) + fade * 22.0f;
        y24 = (0.0f + yBase) + fade * 24.0f;
        i_spell = 0;
        while (i_spell < 7) {
            spell = D_00628FB8[i_spell];
            if (func_001f0950((s32)enemyIdx & 0xFFFF, (s32)spell) != 0) {
                func_00201650(work, 13, i_spell + 0x2E, tmp, yBase, 0x24, 0x4C, 0, 0xFF);
                func_00218c60(work, *(s32 *)(unit + 0xA64), (s64)spell, tmp - 2.0f, y22);
            } else {
                func_00201650(work, 13, i_spell + 0x2E, tmp, yBase, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 14, 0x43, tmp - 2.0f, y22, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x4A, tmp, (0.0f + yBase) + fade * 24.0f, 0x89, 0xFF, 0x1F, 0xFF);
            }
            if (i_spell == 0) {
                tmp += 51.0f;
            } else {
                tmp += 37.0f;
            }
            i_spell += 1;
        }
        func_00201720(work, 1.0f, 1.0f);
    }
    if ((*(u16 *)arg1 & 4) != 0) {
        if (mode < 4) {
            fade2 = 0.0f;
        } else if (mode < 10) {
            fade2 = 1.0f - func_0044b610(fGpffff84a4 * (f32)(s32)(mode - 4) / 6.0f);
        } else {
            fade2 = 1.0f;
        }
        if (fade2 > 0.0f) {
            f32 bx;
            bx = (1.0f - fade2) * -500.0f;
            if ((*(u16 *)arg1 & 8) == 0) {
                u32 n;
                n = func_0023e130(*(u8 **)(unit + 0xA64)) & 0xFFFF;
                cmds = func_0023e140(*(u8 **)(unit + 0xA64));
                i_skill = 0;
                while ((u32)i_skill < (n & 0xFFFF)) {
                    s32 ox;
                    s32 oy;
                    f32 fx;
                    f32 fy;
                    ox = (i_skill >> 2) * 0xC6;
                    if (ox < 0) {
                        fx = 2.0f * (f32)(((u32)ox >> 1) | ((u32)ox & 1));
                    } else {
                        fx = (f32)ox;
                    }
                    fx = bx + (18.0f + fx);
                    oy = (i_skill & 3) * 0x19;
                    if (oy < 0) {
                        fy = 2.0f * (f32)(((u32)oy >> 1) | ((u32)oy & 1));
                    } else {
                        fy = (f32)oy;
                    }
                    fy = 284.0f + fy + 0.0f;
                    func_00201650(work, 12, 0x5A, fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    func_00201650(work, 12, 0x5B, 192.0f + fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    if (cmds[i_skill] != 0) {
                        func_00275020(96.0f + fx, fy - 2.0f, 0.0f, 0x244C00FF, 0, 1, func_00243840(cmds[i_skill]), 8, -1);
                    }
                    i_skill += 1;
                }
            } else {
                f32 qx;
                f32 qy;
                u8 *m;
                f32 z;
                f32 sc;
                m = func_00457120();
                z = D_008872F8[0];
                sc = *(f32 *)(m + 0x80);
                qx = 18.0f + bx;
                func_00201650(work, 10, 0x3E, qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x3F, 388.0f + qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
                x0 = 22.0f + bx;
                quads[0].x = x0;
                quads[0].y = 287.0f;
                quads[0].z = z;
                quads[0].scale = sc;
                quads[0].color[0] = 0x42E00000;
                quads[0].color[1] = 0x42E00000;
                quads[0].color[2] = 0x42E00000;
                quads[0].color[3] = 0x437F0000;
                quads[1].x = 88.0f + x0;
                quads[1].y = 287.0f;
                quads[1].z = z;
                quads[1].scale = sc;
                quads[1].color[0] = 0x42E00000;
                quads[1].color[1] = 0x42E00000;
                quads[1].color[2] = 0x42E00000;
                quads[1].color[3] = 0x437F0000;
                quads[2].x = x0;
                *(u32 *)&quads[2].y = 0x43A90000;
                quads[2].z = z;
                quads[2].scale = sc;
                quads[2].color[0] = 0x42E00000;
                quads[2].color[1] = 0x42E00000;
                quads[2].color[2] = 0x42E00000;
                quads[2].color[3] = 0x437F0000;
                D_00887300[0](1, 0);
                func_00364c50();
                D_00887310[0](4, &quads[0], 3);
                func_00364c70();
                func_00201650(work, 10, 0x4D, 25.0f + bx, 289.0f, 8, 8, 8, 0xFF);
                bx += 202.0f;
                func_00201650(work, 10, 0x48, bx, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x49, 22.0f + bx, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x4A, 7.0f + bx, 324.0f, 0, 0, 0, 0xFF);
            }
        }
    }
    if ((*(u16 *)arg1 & 0x10) != 0) {
        if (mode < 8) {
            tmp2 = 0.0f;
        } else if (mode < 13) {
            tmp2 = func_0044b7b0(fGpffff84a4 * (f32)(s32)(mode - 8) / 5.0f);
        } else {
            tmp2 = 1.0f;
        }
        if (tmp2 > 0.0f) {
            f32 yy;
            func_00201720(work, 1.0f, tmp2);
            if ((*(u16 *)arg1 & 4) == 0) {
                yy = 282.0f;
            } else {
                yy = 399.0f;
            }
            yy += ((1.0f - tmp2) * 23.0f) / 2.0f;
            func_00201650(work, 10, 0x42, 18.0f, yy, 0x89, 0xFF, 0x1F, 0xFF);
            func_00201650(work, 10, 0x43, 165.0f, yy, 0x89, 0xFF, 0x1F, 0xFF);
            yy += tmp2 * 2.0f;
            func_00201650(work, 10, 0x4B, 28.0f, yy, 0xFF, 0xFF, 0xFF, 0xFF);
            func_00201650(work, 10, 0x4C, 86.0f, yy, 0x2D, 0x2D, 0x2D, 0xFF);
            func_00201720(work, 1.0f, 1.0f);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00219790);
#endif

