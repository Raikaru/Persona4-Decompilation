/* Original translation unit btlPanelAnalyze.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "btl_panel_internal.h"
extern void memset();
s32 func_0023a6b0(u8 *arg0, s32 arg1);
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
void sprintf(void *dst, const void *fmt, s32 value);
s32 strlen(const char *text);
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
void func_00218760(void *arg0, u32 arg1, f32 fparg0, s32 arg2, f32 fparg1) {
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
        sprintf(locals.text, &iGpffffa59c, arg1);
        length = strlen(locals.text);
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

    temp = func_0023a6b0((u8 *)arg1, (s16)arg2);
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
    memset(arg0, 0, 0x90);
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
    void *RwMatrixRotate(void *, const void *, f32, s32);
    void *RwMatrixMultiply(void *, const void *, const void *);
    u8 *mdlGetMatrix(u8 *);
    void func_0047a850(u8 *);
    void mdlSetColor(u8 *, const void *);
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
        RwMatrixRotate(&rotation, D_0060A0E0, *(f32 *)(arg0 + 0x88), 0);
        RwMatrixRotate(&rotation, D_0060A0D0, *(f32 *)(entry + 0xC), 2);
        RwMatrixRotate(&rotation, D_0060A0E0, 180.0f + *(f32 *)(entry + 0x10), 2);
        RwMatrixMultiply(mdlGetMatrix(*(u8 **)(arg0 + 0xC)), &rotation, matrix);
        translated = *(f32 *)(matrix + 0x30) + transformed.x;
        *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0xC)) + 0x30) = translated;
        translated = *(f32 *)(matrix + 0x34) + transformed.y;
        *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0xC)) + 0x34) = translated;
        translated = *(f32 *)(matrix + 0x38) + transformed.z;
        *(f32 *)(mdlGetMatrix(*(u8 **)(arg0 + 0xC)) + 0x38) = translated;
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
            mdlSetColor(*(u8 **)(arg0 + 0xC), color);
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

/* Kind reads follow the rendering callbacks, which can replace the table. */
static inline u8 btlPanelEnemyKind(u32 offset)
{
    extern u8 *iGpffffb3c4;
    u8 *kinds = iGpffffb3c4 + 2;
    return kinds[offset];
}

/* Name, affinity, skill and footer phases keep separate coordinates and fades.
 * See docs/probe_archive/BtlPanelAnalyze_00219790_20260929.md. */
// FUN_00219790
void func_00219790(s32 unusedTask, u8 *panel)
{
    extern f32 fGpffff84a4;
    extern u8 *iGpffffb3c4;
    extern u8 *iGpffffb444;
    extern u16 D_00628FB8[];
    f32 cosf(f32);
    f32 sinf(f32);
    void func_00201350(void);
    void func_002012d0(u8 *, f32, f32);
    void func_00201720(u8 *, f32, f32);
    f32 func_00201950(u8 *, s32, s32);
    s32 func_00231e20(void *);
    u16 func_00231f80(void *);
    u16 func_00232290(void *);
    u32 func_0023e130(u8 *);
    u8 *func_0023e140(u8 *);
    u8 *func_00243840(s32);
    s32 func_001f0950(s32, s32);
    u32 func_00452560(u8 *);
    int func_00275020(f32, f32, f32, s32, s32, s32, const void *, s32, s32);
    PanelQuad quads[3];
    char text[128];
    u8 *work;
    u8 *unit;
    s32 frame;
    s32 enemyIndex;
    f32 skillFade;
    f32 iconX;
    f32 footerFade;
    f32 x0;
    s32 len;
    s32 digitIndex;
    u32 affinityIndex;
    u32 hp;
    u32 sp;
    u16 *affinity;
    (void)unusedTask;
    work = (u8 *)func_00452560(*(u8 **)(panel + 0x10));
    if ((*(u32 *)work & 1) == 0) {
        return;
    }
    if ((*(u16 *)panel & 1) == 0) {
        return;
    }
    frame = *(u16 *)(panel + 4);
    func_00201350();
    func_002012d0(work, 0.0f, 0.0f);
    unit = *(u8 **)(*(u8 **)(panel + 8) + 0x30);
    enemyIndex = *(u16 *)(unit + 0xA4);
    {
        f32 nameFade;
        f32 nameX;
        if (frame < 4) {
            nameFade = 0.0f;
        } else if (frame < 10) {
            nameFade = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 4) / 6.0f));
        } else {
            nameFade = 1.0f;
        }
        if (nameFade > 0.0f) {
            nameX = (1.0f - nameFade) * -500.0f;
            func_00201650(work, 10, 0x47, 103.0f + nameX, 103.0f, 0x89, 0xFF, 0x1F, 0xFF);
            func_00201650(work, 13, 0x2A, 30.0f + nameX, 147.0f, 0x24, 0x4C, 0, 0xFF);
            if ((*(u16 *)panel & 8) == 0) {
                f32 nx;
                nx = 60.0f + nameX;
                sprintf(text, &iGpffffa59c, func_00231e20(*(u8 **)(unit + 0xA64)) & 0xFF);
                len = strlen(text);
                if (len > 2) {
                    func_0046d730(D_00628F80, 0xF4);
                }
                nx += ((f32)(2 - len) * 22.0f) / 2.0f;
                digitIndex = 0;
                while (digitIndex < len) {
                    func_00201650(work, 13, text[digitIndex] - 0x13, nx, 140.0f, 0x0D, 0x1B, 0, 0xFF);
                    nx += 22.0f;
                    digitIndex += 1;
                }
            } else {
                func_00201650(work, 10, 0x4A, 68.0f + nameX, 138.0f, 0x0D, 0x1B, 0, 0xFF);
            }
            {
                u32 tableOffset = (u32)enemyIndex * 0x3C;
                if (btlPanelEnemyKind(tableOffset) == 0x17) {
                    func_00201650(work, 10, 0x59, 20.0f + nameX, 108.0f, 0x70, 0x70, 0x70, 0xFF);
                } else {
                    u8 kind;
                    f32 w;
                    kind = btlPanelEnemyKind(tableOffset);
                    w = func_00201950(work, 14, (s32)kind + 0x20);
                    {
                        f32 calculatedX = (57.0f - w / 2.0f) + nameX;
                        f32 displayedX = calculatedX;
                        f32 calculatedY = 110.0f;
                        f32 displayedY = calculatedY;
                        func_00201650(work, 14, (s32)btlPanelEnemyKind(tableOffset) + 0x20,
                            displayedX, displayedY, 0x24, 0x4C, 0, 0xFF);
                    }
                }
            }
            func_00275020(112.0f + nameX, 136.0f, 0.0f, 0x89FF1FFF, 0, 1, iGpffffb444 + (u32)enemyIndex * 0x15, 0, -1);
            if ((*(u16 *)panel & 8) == 0) {
                nameX = panelAdd2(15.0f, nameX);
                hp = func_00231f80(*(u8 **)(unit + 0xA64)) & 0xFFFF;
                if (hp > 999U) {
                    hp = 999;
                }
                func_00218760(work, hp, nameX, 0, 167.0f);
                sp = func_00232290(*(u8 **)(unit + 0xA64)) & 0xFFFF;
                if (sp > 999U) {
                    sp = 999;
                }
                func_00218760(work, sp, nameX, 1, 187.0f);
            } else {
                f32 bx;
                bx = 15.0f + nameX;
                func_00218760(work, 0, bx, 2, 167.0f);
                func_00218760(work, 0, bx, 3, 187.0f);
                nameX = panelAdd2(111.0f, nameX);
                func_00201650(work, 10, 0x48, nameX, 166.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x49, 22.0f + nameX, 166.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x4A, 7.0f + nameX, 176.0f, 0, 0, 0, 0xFF);
            }
        }
    }
    {
        f32 affinityFade;
        f32 y22;
        f32 yBase;
        f32 y24;
        if ((s32)frame < 0) {
            affinityFade = 0.0f;
        } else if (frame < 8) {
            affinityFade = 1.0f - cosf(fGpffff84a4 * ((f32)frame / 8.0f));
        } else {
            affinityFade = 1.0f;
        }
        if (affinityFade > 0.0f) {
            f32 inv;
            func_00201720(work, 1.0f, affinityFade);
            inv = 1.0f - affinityFade;
            {
                f32 calculatedTop = 215.0f + ((51.0f * inv) / 2.0f);
                f32 displayedTop = calculatedTop;
                func_00218af0(-10.0f, displayedTop, 51.0f * affinityFade);
            }
            iconX = 19.0f;
            yBase = 217.0f + ((49.0f * inv) / 2.0f);
            affinityIndex = 0;
            y22 = (0.0f + yBase) + affinityFade * 22.0f;
            y24 = (0.0f + yBase) + affinityFade * 24.0f;
            while (affinityIndex < 7) {
                affinity = &D_00628FB8[affinityIndex];
                if (func_001f0950((s32)enemyIndex & 0xFFFF, (s32)*affinity) != 0) {
                    func_00201650(work, 13, affinityIndex + 0x2E, iconX, yBase, 0x24, 0x4C, 0, 0xFF);
                    func_00218c60(work, *(s32 *)(unit + 0xA64), (s64)*affinity, iconX - 2.0f, y22);
                } else {
                    func_00201650(work, 13, affinityIndex + 0x2E, iconX, yBase, 0x70, 0x70, 0x70, 0xFF);
                    func_00201650(work, 14, 0x43, iconX - 2.0f, y22, 0x70, 0x70, 0x70, 0xFF);
                    func_00201650(work, 10, 0x4A, iconX, y24, 0x89, 0xFF, 0x1F, 0xFF);
                }
                if (affinityIndex == 0) {
                    iconX += 51.0f;
                } else {
                    iconX += 37.0f;
                }
                affinityIndex += 1;
            }
            func_00201720(work, 1.0f, 1.0f);
        }
    }
    if ((*(u16 *)panel & 4) != 0) {
        if (frame < 4) {
            skillFade = 0.0f;
        } else if (frame < 10) {
            skillFade = 1.0f - cosf(fGpffff84a4 * ((f32)(frame - 4) / 6.0f));
        } else {
            skillFade = 1.0f;
        }
        if (skillFade > 0.0f) {
            struct { f32 x; f32 y; } slide;
            slide.x = (1.0f - skillFade) * -500.0f;
            slide.y = 0.0f;
            if ((*(u16 *)panel & 8) == 0) {
                u16 n;
                u32 count;
                u16 *cmds;
                u32 skillIndex;
                n = func_0023e130(*(u8 **)(unit + 0xA64)) & 0xFFFF;
                cmds = (u16 *)func_0023e140(*(u8 **)(unit + 0xA64));
                skillIndex = 0;
                count = n & 0xFFFF;
                while (skillIndex < count) {
                    u32 ox;
                    u32 oy;
                    f32 fy;
                    f32 fx;
                    ox = (skillIndex >> 2) * 0xC6;
                    fx = (f32)ox;
                    fx = slide.x + (18.0f + fx);
                    oy = (skillIndex & 3) * 0x19;
                    fy = (f32)oy;
                    fy = panelAdd2(slide.y, panelAdd2(284.0f, fy));
                    func_00201650(work, 12, 0x5A, fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    func_00201650(work, 12, 0x5B, 192.0f + fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    if (cmds[skillIndex] != 0) {
                        func_00275020(96.0f + fx, fy - 2.0f, 0.0f, 0x244C00FF, 0, 1, func_00243840(cmds[skillIndex]), 8, -1);
                    }
                    skillIndex += 1;
                }
            } else {
                f32 qx;
                f32 qy;
                u8 *m;
                f32 z;
                f32 sc;
                z = D_008872F8[0];
                m = func_00457120();
                sc = *(f32 *)(m + 0x80);
                qx = 18.0f + slide.x;
                func_00201650(work, 10, 0x3E, qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x3F, 388.0f + qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
                x0 = 22.0f + slide.x;
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
                func_00201650(work, 10, 0x4D, 25.0f + slide.x, 289.0f, 8, 8, 8, 0xFF);
                slide.x = panelAdd2(202.0f, slide.x);
                func_00201650(work, 10, 0x48, slide.x, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x49, 22.0f + slide.x, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                func_00201650(work, 10, 0x4A, 7.0f + slide.x, 324.0f, 0, 0, 0, 0xFF);
            }
        }
    }
    if ((*(u16 *)panel & 0x10) != 0) {
        if (frame < 8) {
            footerFade = 0.0f;
        } else if (frame < 13) {
            footerFade = sinf(fGpffff84a4 * ((f32)(frame - 8) / 5.0f));
        } else {
            footerFade = 1.0f;
        }
        if (footerFade > 0.0f) {
            f32 yy;
            f32 xx;
            func_00201720(work, 1.0f, footerFade);
            if ((*(u16 *)panel & 4) != 0) {
                xx = 18.0f;
                yy = (f32)(s32)399;
            } else {
                xx = 18.0f;
                yy = 282.0f;
            }
            yy += ((1.0f - footerFade) * 23.0f) / 2.0f;
            func_00201650(work, 10, 0x42, xx, yy, 0x89, 0xFF, 0x1F, 0xFF);
            func_00201650(work, 10, 0x43, 147.0f + xx, yy, 0x89, 0xFF, 0x1F, 0xFF);
            {
                f32 offsetY = footerFade * 2.0f;
                f32 translatedY = offsetY;
                f32 nextY = yy + translatedY;
                yy = nextY;
            }
            func_00201650(work, 10, 0x4B, 10.0f + xx, yy, 0xFF, 0xFF, 0xFF, 0xFF);
            func_00201650(work, 10, 0x4C, 68.0f + xx, yy, 0x2D, 0x2D, 0x2D, 0xFF);
            func_00201720(work, 1.0f, 1.0f);
        }
    }
}
