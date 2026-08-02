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
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00218af0);

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

typedef struct { f32 x, y, z, w; } PanelVec4X;
// FUN_00218EA0
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

// FUN_00219130
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00219130);

// FUN_00219790
INCLUDE_ASM("asm/nonmatchings/btlPanelAnalyze", func_00219790);

