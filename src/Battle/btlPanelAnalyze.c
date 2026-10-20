/* Original translation unit btlPanelAnalyze.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "btl_panel_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_action_internal.h"
extern void memset();
s32 datCalcGetAffinity(u8 *unit, s32 elementIndex);
void shdEnableBlendFlag(void);
void shdDisableBlendFlag(void);
void func_003c38b0(void *, void *);
void func_003e8110(void *camera);
void func_003e8120(void *camera);
void func_003e8180(void *, f32);
void func_003e81c0(void *, f32);
void func_003e9cb0(void *frame, void *transform, s32 combine);
u8 *kwlnGetCamera(void);
u8 *K_Clump_GetLightA(void);
u8 *K_Clump_GetLightC(void);
void sprintf(void *dst, const void *fmt, s32 value);
s32 strlen(const char *text);
void kAssertFail(const void *file, s32 line);
extern u8 D_00628F80[];
extern char iGpffffa59c;
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 (*D_00887310[])(s32, void *, s32);
extern f32 D_008872F8[];
extern f32 fGpffff847c;
extern f32 fGpffff80cc;

static inline f32 panelAdd2(f32 left, f32 right) { return left + right; }

/* btlPanelClear clears 0x90 bytes; layout callbacks save lights, matrix and
 * projection values while the model updater owns state, opacity and yaw. */
typedef struct BtlAnalyzePanel
{
    u16 flags;
    u16 state;
    u16 frame;
    u8 opacity;
    u8 pad07;
    u8 *action;
    u8 *model;
    s32 task;
    f32 savedLightA[4];
    f32 savedLightC[4];
    u8 pad34[0x0C];
    f32 savedMatrix[16];
    f32 savedProjection;
    f32 savedFarClip;
    f32 yaw;
    u8 pad8C[4];
} BtlAnalyzePanel;

/* measured: opt_propagation off preserves the split mode live range and
   retail's parameter-save order (MATCH nd0; without it, nd10). */
#pragma opt_propagation off
// FUN_00218760
/* Draw an HP/SP number or hidden-value panel using active/disabled colors and digit sprites. */
void btlPanelAddEntry(void *work, u32 value, f32 x, s32 displayMode, f32 yPosition) {
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

    px = x;
    py = yPosition;
    mode = displayMode;
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
    kAssertFail(D_00628F80, 0x12D);
mode_done:
    mode2 = mode;
    btlUiDrawSpriteFaded(work, 0xA, 0x40, px, py,
                  color0, color1, blue, color2);
    btlUiDrawSpriteFaded(work, 0xA, 0x41, 81.0f + px, py,
                  color0, color1, blue, color2);
    y = 2.0f + py;
    btlUiDrawSpriteFaded(work, 0xA, 0x46, 6.0f + px, y,
                  color3, color4, color5, color6);
    switch (mode2) {
    case 0:
    case 2:
        btlUiDrawSpriteFaded(work, 0xA, 0x44, 59.0f + px, y,
                      color3, color4, color5, color6);
        break;
    case 1:
    case 3:
        btlUiDrawSpriteFaded(work, 0xA, 0x45, 59.0f + px, y,
                      color3, color4, color5, color6);
        break;
    default:
        kAssertFail(D_00628F80, 0x13F);
        break;
    }
    switch (mode2) {
    case 0:
    case 1:
        px = panelAdd2(96.0f, px);
        sprintf(locals.text, &iGpffffa59c, value);
        length = strlen(locals.text);
        i = 0;
        y = 4.0f + py;
        while (i < length) {
            btlUiDrawSpriteFaded(work, 0xC, locals.text[i] - 0x27,
                          px, y, 0x89, 0xFF, 0x1F, 0xFF);
            px += 16.0f;
            i += 1;
        }
        break;
    case 2:
    case 3:
        break;
    default:
        kAssertFail(D_00628F80, 0x14E);
        break;
    }
}
/* measured: restores propagation after btlPanelAddEntry. */
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
/* Draw the four-vertex affinity backdrop at the requested position and height. The raw projection-
 * scale access is an external SDK camera field. */
void btlPanelSetRgb(f32 x, f32 y, f32 height) {
    PanelQuad quads[4];
    u8 *p;
    f32 zval;
    f32 scale;

    zval = D_008872F8[0];
    scale = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
    p = (u8 *)&quads[0];
    ((PanelQuad *)p)->x = x;
    ((PanelQuad *)p)->y = y;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->scale = scale;
    ((PanelQuad *)p)->color[0] = 0x43090000;
    ((PanelQuad *)p)->color[1] = 0x437F0000;
    ((PanelQuad *)p)->color[2] = 0x41F80000;
    ((PanelQuad *)p)->color[3] = 0x437F0000;
    p = (u8 *)&quads[1];
    ((PanelQuad *)p)->x = 323.0f + x;
    ((PanelQuad *)p)->y = y;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->scale = scale;
    ((PanelQuad *)p)->color[0] = 0x43090000;
    ((PanelQuad *)p)->color[1] = 0x437F0000;
    ((PanelQuad *)p)->color[2] = 0x41F80000;
    ((PanelQuad *)p)->color[3] = 0x437F0000;
    p = (u8 *)&quads[2];
    ((PanelQuad *)p)->x = x;
    ((PanelQuad *)p)->y = y + height;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->scale = scale;
    ((PanelQuad *)p)->color[0] = 0x43090000;
    ((PanelQuad *)p)->color[1] = 0x437F0000;
    ((PanelQuad *)p)->color[2] = 0x41F80000;
    ((PanelQuad *)p)->color[3] = 0x437F0000;
    p = (u8 *)&quads[3];
    ((PanelQuad *)p)->x = 374.0f + x;
    ((PanelQuad *)p)->y = y + height;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->scale = scale;
    ((PanelQuad *)p)->color[0] = 0x43090000;
    ((PanelQuad *)p)->color[1] = 0x437F0000;
    ((PanelQuad *)p)->color[2] = 0x41F80000;
    ((PanelQuad *)p)->color[3] = 0x437F0000;
    D_00887300[0](1, 0);
    shdEnableBlendFlag();
    D_00887310[0](4, &quads[0], 4);
    shdDisableBlendFlag();
}

// FUN_00218C60
/* Draw the affinity icon selected by the unit data flags, in priority order for the tested affinity
 * bits. */
void btlPanelAddStatusEntry(u8 *work, s32 unitData, s64 affinity, f32 x, f32 y) {
    s32 flags;
    f32 iconX;
    f32 iconY;

    flags = datCalcGetAffinity((u8 *)unitData, (s16)affinity);
    btlUiDrawSpriteFaded(work, 0xE, 0x43, x, y, 0x24, 0x4C, 0, 0xFF);
    iconX = panelAdd2(x, 2.0f);
    iconY = panelAdd2(y, 2.0f);
    if (flags & 0x08000000) {
        btlUiDrawSpriteFaded(work, 0xD, 0x36, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (flags & 0x01000000) {
        btlUiDrawSpriteFaded(work, 0xD, 0x38, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (flags & 0x10000000) {
        btlUiDrawSpriteFaded(work, 0xD, 0x37, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (flags & 0x04000000) {
        btlUiDrawSpriteFaded(work, 0xD, 0x39, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    if (flags & 0x02000000) {
        btlUiDrawSpriteFaded(work, 0xD, 0x35, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
        return;
    }
    btlUiDrawSpriteFaded(work, 0xD, 0x3A, iconX, iconY, 0x89, 0xFF, 0x1F, 0xFF);
}

// FUN_00218E50
/* Clear the complete 0x90-byte analysis panel and record its owning task. */
void btlPanelClear(u8 *panel, s32 task) {
    memset(panel, 0, 0x90);
    ((BtlAnalyzePanel *)panel)->task = task;
    ((BtlAnalyzePanel *)panel)->state = 0;
}


/* measured: aggregate vector copies and paired 32-bit copy loop; named
   temporaries reproduce the 003e9cb0 argument-load order. The dst/src_base
   saved-register colouring (retail dst $s1, src_base $s0) needs the source
   pointer re-derived from src_base INSIDE the copy loop (`src = (s32 *)src_base`
   each iteration, consumed after the loop): a loop-carried alias of src_base
   drops it to $s0. Found by tools/permute_ast.py, minimised to this one line. */
// FUN_00218EA0
/* Save the current light colors, light frame and camera projection, then install the analysis
 * presentation. Raw SDK light/frame words preserve the measured paired-copy and argument-load order. */
void btlPanelSetupLayout(u8 *panel) {
    typedef struct { f32 x, y, z, w; } PanelVec4X;
    s32 *src;
    u8 *firstLight;
    u8 *secondLight;
    u32 frameAddress;
    u8 *matrixSource;
    u8 *matrixDestination;
    u8 *dst;
    s32 copyCount;
    s32 firstWord;
    s32 secondWord;
    PanelVec4X tmp;

    dst = panel;
    func_003e8110(kwlnGetCamera());
    firstLight = K_Clump_GetLightA();
    *(PanelVec4X *)(dst + 0x14) = *(PanelVec4X *)(firstLight + 0x18);
    tmp.x = fGpffff847c;
    tmp.y = fGpffff847c;
    tmp.z = fGpffff847c;
    tmp.w = 1.0f;
    func_003c38b0(firstLight, &tmp);
    secondLight = K_Clump_GetLightC();
    *(PanelVec4X *)(dst + 0x24) = *(PanelVec4X *)(secondLight + 0x18);
    tmp.x = fGpffff80cc;
    tmp.y = 1.0f;
    tmp.z = fGpffff80cc;
    tmp.w = 1.0f;
    func_003c38b0(secondLight, &tmp);
    frameAddress = (u32)(secondLight + 4);
    matrixSource = (u8 *)(*(s32 *)(u8 *)frameAddress + 0x10);
    matrixDestination = dst + 0x40;
    copyCount = 8;
    do {
        firstWord = *(s32 *)matrixSource;
        src = (s32 *)(u8 *)frameAddress;
        secondWord = *(s32 *)(matrixSource + 4);
        matrixSource += 8;
        copyCount -= 1;
        *(s32 *)matrixDestination = firstWord;
        *(s32 *)(matrixDestination + 4) = secondWord;
        matrixDestination += 8;
    } while (copyCount > 0);
    secondLight = (u8 *)(*(u32 *)(kwlnGetCamera() + 4));
    firstLight = (u8 *)*src;
    func_003e9cb0(firstLight, secondLight + 0x10, 0);
    *(f32 *)(dst + 0x80) = *(f32 *)(kwlnGetCamera() + 0x80);
    *(f32 *)(dst + 0x84) = *(f32 *)(kwlnGetCamera() + 0x84);
    func_003e8180(kwlnGetCamera(), 35.0f);
    func_003e81c0(kwlnGetCamera(), (f32)(s32)0xDAC0);
    func_003e8120(kwlnGetCamera());
}

// FUN_00219060
/* Restore the light colors, frame and camera projection saved by the analysis draw callback. The raw
 * SDK frame pointer is the light attachment. */
void btlPanelResetLayout(u8 *panel) {
    u8 *temp;

    func_003e8110(kwlnGetCamera());
    func_003c38b0(K_Clump_GetLightA(), panel + 0x14);
    temp = K_Clump_GetLightC();
    func_003c38b0(temp, panel + 0x24);
    func_003e9cb0((void *)*(s32 *)(temp + 4), panel + 0x40, 0);
    func_003e8180(kwlnGetCamera(), ((BtlAnalyzePanel *)panel)->savedProjection);
    func_003e81c0(kwlnGetCamera(), ((BtlAnalyzePanel *)panel)->savedFarClip);
    func_003e8120(kwlnGetCamera());
}

/* 1624/1632 bytes; 53 resolved relocations and eight zero alignment bytes.
 * The explicit zero-add expression emits retail's adda.s/madd.s sequence.
 * Preserve unsigned controller conversion before subtracting 128, matrix
 * initialization before composition, and callback-visible field reloads. */
// FUN_00219130
/* Create or replace the analysis model, apply controller yaw limits, and animate opacity before
 * queuing it. Measured: typed state, yaw, model and actor reloads each change MATCH; raw SDK matrices
 * and descriptor rows retain external layouts. */
void btlPanelLoadModels(u8 *panel) {
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
    u8 *mdlCloneModelObject(u8 *);
    void mdlDestroyModelObject(u8 *);
    void mdlSetAttachedOwner(u8 *, void *);
    void mdlSetDrawCallback(u8 *, void (*)(u8 *), u8 *);
    void mdlSetResetCallback(u8 *, void (*)(u8 *), u8 *);
    void *func_003e4320(void *, const void *, const void *);
    void *RwMatrixRotate(void *, const void *, f32, s32);
    void *RwMatrixMultiply(void *, const void *, const void *);
    u8 *mdlGetMatrix(u8 *);
    void mdlSetAlphaBlend(u8 *);
    void mdlSetColor(u8 *, const void *);
    void mdlQueueModelForDraw(void *, u8 *);
    AnalyzeVec3 position;
    AnalyzeVec3 transformed;
    AnalyzeMatrix rotation;
    u8 color[4];
    u8 *model;
    u8 *entry;
    u8 *matrix;
    u8 *unit;
    u16 flags;
    u32 tableAddress;
    f32 delta;
    f32 width;
    f32 height;
    f32 translated;

    if (*(u16 *)(panel + 2) == 0) {
        return;
    }
    switch (*(u16 *)(panel + 2)) {
    case 1:
        unit = ((BtlAnalyzePanel *)panel)->action;
        model = mdlCloneModelObject(*(u8 **)(*(u8 **)(unit + 0x30) + 0xA00));
        *(u8 **)(panel + 0xC) = model;
        mdlSetAttachedOwner(model, D_005DC9C8);
        *(u32 *)(*(u8 **)(panel + 0xC) + 0xD8) &= ~0x100;
        entry = *(u8 **)(unit + 0x30);
        if (entry[0xA2] == 1) {
            tableAddress = ((BtlUnit *)entry)->charId * 0xE8;
            tableAddress += (u32)iGpffffb3cc;
            flags = *(u16 *)(tableAddress + 0x18);
            if (flags & 2) {
                *(u32 *)(*(u8 **)(panel + 0xC) + 0xD8) |= 0x200;
            }
            if (flags & 8) {
                *(u32 *)(*(u8 **)(panel + 0xC) + 0xD8) |= 0x400;
            }
            if (flags & 0x10) {
                *(u32 *)(*(u8 **)(panel + 0xC) + 0xD8) |= 0x800;
            }
        }
        mdlSetDrawCallback(*(u8 **)(panel + 0xC), btlPanelSetupLayout, panel);
        mdlSetResetCallback(*(u8 **)(panel + 0xC), btlPanelResetLayout, panel);
        ((BtlAnalyzePanel *)panel)->flags &= ~2;
        ((BtlAnalyzePanel *)panel)->flags |= 1;
        *(f32 *)(panel + 0x88) = 0.0f;
        panel[6] = 0;
        *(u16 *)(panel + 2) = 3;
        break;
    case 2:
        mdlDestroyModelObject(*(u8 **)(panel + 0xC));
        model = mdlCloneModelObject(*(u8 **)(*(u8 **)(((BtlAnalyzePanel *)panel)->action + 0x30) + 0xA00));
        *(u8 **)(panel + 0xC) = model;
        mdlSetAttachedOwner(model, D_005DC9C8);
        *(u32 *)(*(u8 **)(panel + 0xC) + 0xD8) &= ~0x100;
        mdlSetDrawCallback(*(u8 **)(panel + 0xC), btlPanelSetupLayout, panel);
        mdlSetResetCallback(*(u8 **)(panel + 0xC), btlPanelResetLayout, panel);
        *(f32 *)(panel + 0x88) = 0.0f;
        *(u16 *)(panel + 2) = 3;
    case 3:
        if (((BtlAnalyzePanel *)panel)->frame < 5) {
            break;
        }
        unit = *(u8 **)(((BtlAnalyzePanel *)panel)->action + 0x30);
        if (unit[0xA2] == 1) {
            entry = D_00626FE0[((BtlUnit *)unit)->charId];
        } else {
            entry = D_00628F60;
        }
        delta = (f32)D_008C025C[0] - 128.0f;
        if (delta < -48.0f || delta > 48.0f) {
            *(f32 *)(panel + 0x88) = (0.0f + *(f32 *)(panel + 0x88)) + fGpffff8480 * delta;
        }
        if (entry[0x14] < 180 || entry[0x15] < 180) {
            if (*(f32 *)(panel + 0x88) > (f32)entry[0x14]) {
                *(f32 *)(panel + 0x88) = (f32)entry[0x14];
            } else if (*(f32 *)(panel + 0x88) < (f32)-entry[0x15]) {
                *(f32 *)(panel + 0x88) = (f32)-entry[0x15];
            }
        }
        unit = kwlnGetCamera();
        translated = *(f32 *)(unit + 0x68);
        width = 2.0f * (translated * fGpffff8484);
        height = 2.0f * (*(f32 *)(unit + 0x6C) * fGpffff8484);
        matrix = *(u8 **)(kwlnGetCamera() + 4) + 0x10;
        translated = 320.0f;
        translated += *(f32 *)(entry + 0);
        position.x = (0.5f + -translated / 640.0f) * width;
        position.y = (0.5f + -(224.0f + *(f32 *)(entry + 4)) / 448.0f) * height;
        translated = (f32)(s32)0x226;
        translated += *(f32 *)(entry + 8);
        position.z = translated;
        func_003e4320(&transformed, &position, matrix);
        RwMatrixRotate(&rotation, D_0060A0E0, *(f32 *)(panel + 0x88), 0);
        RwMatrixRotate(&rotation, D_0060A0D0, *(f32 *)(entry + 0xC), 2);
        RwMatrixRotate(&rotation, D_0060A0E0, 180.0f + *(f32 *)(entry + 0x10), 2);
        RwMatrixMultiply(mdlGetMatrix(*(u8 **)(panel + 0xC)), &rotation, matrix);
        translated = *(f32 *)(matrix + 0x30) + transformed.x;
        *(f32 *)(mdlGetMatrix(*(u8 **)(panel + 0xC)) + 0x30) = translated;
        translated = *(f32 *)(matrix + 0x34) + transformed.y;
        *(f32 *)(mdlGetMatrix(*(u8 **)(panel + 0xC)) + 0x34) = translated;
        translated = *(f32 *)(matrix + 0x38) + transformed.z;
        *(f32 *)(mdlGetMatrix(*(u8 **)(panel + 0xC)) + 0x38) = translated;
        if (panel[6] < 0xFF) {
            if (panel[6] < 0xD7) {
                panel[6] += 0x28;
            } else {
                panel[6] = 0xFF;
            }
            mdlSetAlphaBlend(*(u8 **)(panel + 0xC));
            color[0] = 0xFF;
            color[1] = 0xFF;
            color[2] = 0xFF;
            color[3] = panel[6];
            mdlSetColor(*(u8 **)(panel + 0xC), color);
        }
        mdlQueueModelForDraw(D_00795020, *(u8 **)(panel + 0xC));
        break;
    case 4:
        mdlDestroyModelObject(*(u8 **)(panel + 0xC));
        *(u8 **)(panel + 0xC) = NULL;
        ((BtlAnalyzePanel *)panel)->flags &= ~1;
        *(u16 *)(panel + 2) = 0;
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
/* Animate name, rewards, affinities, skills and footer using independently timed fades. Measured:
 * typed data-record pointer reloads change MATCH; raw camera fields retain the SDK boundary layout. */
void btlPanelAnimate(s32 unusedTask, u8 *panel)
{
    extern f32 fGpffff84a4;
    extern u8 *iGpffffb3c4;
    extern u8 *iGpffffb444;
    extern u16 D_00628FB8[];
    f32 cosf(f32);
    f32 sinf(f32);
    void btlUiSetRenderStates(void);
    void btlUiSetOrigin(u8 *, f32, f32);
    void btlUiSetScale(u8 *, f32, f32);
    f32 btlUiSpriteWidth(u8 *, s32, s32);
    s32 datCalcGetLevel(void *);
    u16 datCalcMaxHp(void *);
    u16 datCalcMaxSp(void *);
    u8 *datCalcGetIdRecord(s32);
    s32 btlTargetTestUnitFlag(s32, s32);
    u32 kwlnTaskGetWork(u8 *);
    int frFontExDrawTextWithCharWidth(f32, f32, f32, s32, s32, s32, const void *, s32, s32);
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
    work = (u8 *)kwlnTaskGetWork((u8 *)((BtlAnalyzePanel *)panel)->task);
    if ((*(u32 *)work & 1) == 0) {
        return;
    }
    if ((((BtlAnalyzePanel *)panel)->flags & 1) == 0) {
        return;
    }
    frame = ((BtlAnalyzePanel *)panel)->frame;
    btlUiSetRenderStates();
    btlUiSetOrigin(work, 0.0f, 0.0f);
    unit = *(u8 **)(((BtlAnalyzePanel *)panel)->action + 0x30);
    enemyIndex = ((BtlUnit *)unit)->charId;
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
            btlUiDrawSpriteFaded(work, 10, 0x47, 103.0f + nameX, 103.0f, 0x89, 0xFF, 0x1F, 0xFF);
            btlUiDrawSpriteFaded(work, 13, 0x2A, 30.0f + nameX, 147.0f, 0x24, 0x4C, 0, 0xFF);
            if ((((BtlAnalyzePanel *)panel)->flags & 8) == 0) {
                f32 nx;
                nx = 60.0f + nameX;
                sprintf(text, &iGpffffa59c, datCalcGetLevel(*(u8 * *)(unit + 0xA64)) & 0xFF);
                len = strlen(text);
                if (len > 2) {
                    kAssertFail(D_00628F80, 0xF4);
                }
                nx += ((f32)(2 - len) * 22.0f) / 2.0f;
                digitIndex = 0;
                while (digitIndex < len) {
                    btlUiDrawSpriteFaded(work, 13, text[digitIndex] - 0x13, nx, 140.0f, 0x0D, 0x1B, 0, 0xFF);
                    nx += 22.0f;
                    digitIndex += 1;
                }
            } else {
                btlUiDrawSpriteFaded(work, 10, 0x4A, 68.0f + nameX, 138.0f, 0x0D, 0x1B, 0, 0xFF);
            }
            {
                u32 tableOffset = (u32)enemyIndex * 0x3C;
                if (btlPanelEnemyKind(tableOffset) == 0x17) {
                    btlUiDrawSpriteFaded(work, 10, 0x59, 20.0f + nameX, 108.0f, 0x70, 0x70, 0x70, 0xFF);
                } else {
                    u8 kind;
                    f32 w;
                    kind = btlPanelEnemyKind(tableOffset);
                    w = btlUiSpriteWidth(work, 14, (s32)kind + 0x20);
                    {
                        f32 calculatedX = (57.0f - w / 2.0f) + nameX;
                        f32 displayedX = calculatedX;
                        f32 calculatedY = 110.0f;
                        f32 displayedY = calculatedY;
                        btlUiDrawSpriteFaded(work, 14, (s32)btlPanelEnemyKind(tableOffset) + 0x20,
                            displayedX, displayedY, 0x24, 0x4C, 0, 0xFF);
                    }
                }
            }
            frFontExDrawTextWithCharWidth(112.0f + nameX, 136.0f, 0.0f, 0x89FF1FFF, 0, 1, iGpffffb444 + (u32)enemyIndex * 0x15, 0, -1);
            if ((((BtlAnalyzePanel *)panel)->flags & 8) == 0) {
                nameX = panelAdd2(15.0f, nameX);
                hp = datCalcMaxHp(*(u8 * *)(unit + 0xA64)) & 0xFFFF;
                if (hp > 999U) {
                    hp = 999;
                }
                btlPanelAddEntry(work, hp, nameX, 0, 167.0f);
                sp = datCalcMaxSp(*(u8 * *)(unit + 0xA64)) & 0xFFFF;
                if (sp > 999U) {
                    sp = 999;
                }
                btlPanelAddEntry(work, sp, nameX, 1, 187.0f);
            } else {
                f32 bx;
                bx = 15.0f + nameX;
                btlPanelAddEntry(work, 0, bx, 2, 167.0f);
                btlPanelAddEntry(work, 0, bx, 3, 187.0f);
                nameX = panelAdd2(111.0f, nameX);
                btlUiDrawSpriteFaded(work, 10, 0x48, nameX, 166.0f, 0x70, 0x70, 0x70, 0xFF);
                btlUiDrawSpriteFaded(work, 10, 0x49, 22.0f + nameX, 166.0f, 0x70, 0x70, 0x70, 0xFF);
                btlUiDrawSpriteFaded(work, 10, 0x4A, 7.0f + nameX, 176.0f, 0, 0, 0, 0xFF);
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
            btlUiSetScale(work, 1.0f, affinityFade);
            inv = 1.0f - affinityFade;
            {
                f32 calculatedTop = 215.0f + ((51.0f * inv) / 2.0f);
                f32 displayedTop = calculatedTop;
                btlPanelSetRgb(-10.0f, displayedTop, 51.0f * affinityFade);
            }
            iconX = 19.0f;
            yBase = 217.0f + ((49.0f * inv) / 2.0f);
            affinityIndex = 0;
            y22 = (0.0f + yBase) + affinityFade * 22.0f;
            y24 = (0.0f + yBase) + affinityFade * 24.0f;
            while (affinityIndex < 7) {
                affinity = &D_00628FB8[affinityIndex];
                if (btlTargetTestUnitFlag((s32)enemyIndex & 0xFFFF, (s32)*affinity) != 0) {
                    btlUiDrawSpriteFaded(work, 13, affinityIndex + 0x2E, iconX, yBase, 0x24, 0x4C, 0, 0xFF);
                    btlPanelAddStatusEntry(work, *(s32 *)(unit + 0xA64), (s64)*affinity, iconX - 2.0f, y22);
                } else {
                    btlUiDrawSpriteFaded(work, 13, affinityIndex + 0x2E, iconX, yBase, 0x70, 0x70, 0x70, 0xFF);
                    btlUiDrawSpriteFaded(work, 14, 0x43, iconX - 2.0f, y22, 0x70, 0x70, 0x70, 0xFF);
                    btlUiDrawSpriteFaded(work, 10, 0x4A, iconX, y24, 0x89, 0xFF, 0x1F, 0xFF);
                }
                if (affinityIndex == 0) {
                    iconX += 51.0f;
                } else {
                    iconX += 37.0f;
                }
                affinityIndex += 1;
            }
            btlUiSetScale(work, 1.0f, 1.0f);
        }
    }
    if ((((BtlAnalyzePanel *)panel)->flags & 4) != 0) {
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
            if ((((BtlAnalyzePanel *)panel)->flags & 8) == 0) {
                u16 n;
                u32 count;
                u16 *cmds;
                u32 skillIndex;
                n = datCalcGetTableLength(*(DatUnit * *)(unit + 0xA64)) & 0xFFFF;
                cmds = (u16 *)datCalcSkillList(*(DatUnit * *)(unit + 0xA64));
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
                    btlUiDrawSpriteFaded(work, 12, 0x5A, fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    btlUiDrawSpriteFaded(work, 12, 0x5B, 192.0f + fx, fy, 0x89, 0xFF, 0x1F, 0xFF);
                    if (cmds[skillIndex] != 0) {
                        frFontExDrawTextWithCharWidth(96.0f + fx, fy - 2.0f, 0.0f, 0x244C00FF, 0, 1, datCalcGetIdRecord(cmds[skillIndex]), 8, -1);
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
                m = kwlnGetCamera();
                sc = *(f32 *)(m + 0x80);
                qx = 18.0f + slide.x;
                btlUiDrawSpriteFaded(work, 10, 0x3E, qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
                btlUiDrawSpriteFaded(work, 10, 0x3F, 388.0f + qx, 283.0f, 0x70, 0x70, 0x70, 0xFF);
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
                shdEnableBlendFlag();
                D_00887310[0](4, &quads[0], 3);
                shdDisableBlendFlag();
                btlUiDrawSpriteFaded(work, 10, 0x4D, 25.0f + slide.x, 289.0f, 8, 8, 8, 0xFF);
                slide.x = panelAdd2(202.0f, slide.x);
                btlUiDrawSpriteFaded(work, 10, 0x48, slide.x, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                btlUiDrawSpriteFaded(work, 10, 0x49, 22.0f + slide.x, 314.0f, 0x70, 0x70, 0x70, 0xFF);
                btlUiDrawSpriteFaded(work, 10, 0x4A, 7.0f + slide.x, 324.0f, 0, 0, 0, 0xFF);
            }
        }
    }
    if ((((BtlAnalyzePanel *)panel)->flags & 0x10) != 0) {
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
            btlUiSetScale(work, 1.0f, footerFade);
            if ((((BtlAnalyzePanel *)panel)->flags & 4) != 0) {
                xx = 18.0f;
                yy = (f32)(s32)399;
            } else {
                xx = 18.0f;
                yy = 282.0f;
            }
            yy += ((1.0f - footerFade) * 23.0f) / 2.0f;
            btlUiDrawSpriteFaded(work, 10, 0x42, xx, yy, 0x89, 0xFF, 0x1F, 0xFF);
            btlUiDrawSpriteFaded(work, 10, 0x43, 147.0f + xx, yy, 0x89, 0xFF, 0x1F, 0xFF);
            {
                f32 offsetY = footerFade * 2.0f;
                f32 translatedY = offsetY;
                f32 nextY = yy + translatedY;
                yy = nextY;
            }
            btlUiDrawSpriteFaded(work, 10, 0x4B, 10.0f + xx, yy, 0xFF, 0xFF, 0xFF, 0xFF);
            btlUiDrawSpriteFaded(work, 10, 0x4C, 68.0f + xx, yy, 0x2D, 0x2D, 0x2D, 0xFF);
            btlUiSetScale(work, 1.0f, 1.0f);
        }
    }
}
