/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fcl_draw_types.h"
extern void (*jtbl_008873EC[])(void *ptr);
/* Row colours reach the packer as bytes in this unit: retail passes the u8
   locals through with no zero-extension, so this view of func_002b2a60
   takes u8 components (include/fcl_color.h keeps the int view other units
   need). */
typedef struct {
    u8 c0, c1, c2, c3;
} FclDrawColor;

FclDrawColor func_002b2a60(u8 red, u8 green, u8 blue, u8 alpha);
extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef FclVec2 F2_0033;

extern u32 func_002e7a60(void);
extern s32 func_002b3170(s32 arg0);
extern void func_0033d3c0(void *, f32);
extern void func_0033d3e0(void *, F2_0033, F2_0033, u32, u32, s64);
extern void func_0033d4b0(void *, u8, u8, u8, s16, s64);
extern void func_0033d4e0(u8 *arg0, f32 fparg0, f32 fparg1, s8 arg1, s16 arg2, s64 arg3);
extern f32 D_0064A1D8[];
extern f32 D_0064A1E0[];
extern f32 D_0064A1E8[];
extern f32 D_0064A0E8[];
extern f32 D_0064A2A0[];
extern f32 D_0064A2A8[];
extern f32 D_0064A338[];
extern f32 D_0064A094[];
extern f32 D_0064A1F0[];
extern f32 D_0064A1F8[];
extern f32 D_0064A200[];
extern f32 D_0064A208[];
extern f32 D_0064A220[];
extern f32 D_0064A228[];
extern f32 D_0064A230[];
extern f32 D_0064A318[];
extern f32 D_0064A320[];
extern f32 D_0064A340[];
extern f32 D_0064A348[];
extern f32 D_0064A350[];
extern f32 D_0064A358[];
extern void func_0033d420(u8 *arg0, F2_0033 p1, F2_0033 p2, u32 arg3, s8 arg4, u32 arg5, s16 arg6);
extern void func_003322d0(u8 *arg0);
void func_0033bf90(u8 *arg0);


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

s32 func_00332bb0(u8 *arg0);
extern void func_00332a80(void);
extern s32 func_0033cc40(u8 *task);
void func_0044ea90(const void *, u32);

void func_002e29a0(void);
void H_Cdvd_Destroy(void *);
void func_0046b0d0(void *);
s32 func_00106a90(s64);
void *func_0046d200(void *, s32, ...);
void func_002e24a0(s32, s32, s32, s32);
f32 func_0046b260(void *);
f32 func_0046b2f0(void *);
void func_0046d280(void *);
s32 func_0033d390(void *, s32);
void func_0033d320(u8 *arg0, s32 arg1, s8 arg2);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
s32 func_002b2a30(u8, u8, u8, u8);
extern s32 func_00275520(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void *arg9);
extern s64 func_002e2740(s32 arg0);
extern u32 func_001067f0(s16 arg0);
extern s32 func_00106600(s16 arg0);
extern s32 clndGetMoonPhase(s64 arg0);
extern void func_002caa10(F2_0033 position, f32 depth, FclDrawColor color, u32 number, s16 glyphBase, void *sprite,
                          s32 style);
extern void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern s32 func_002e2670(void);
extern s64 func_00106b80(s32 arg0);
extern u8 *func_0033d310(u8 *arg0);
extern void func_0033d3d0(u8 *arg0, s32 arg1);
extern f32 D_0064A2B0[];
extern f32 D_0064A2B8[];
extern u8 D_00795E60[];
extern u32 func_0033cbc0(void *arg0, s64 arg1);
s32 func_002b2cb0(s32, s32, s32, s32, s8);
s32 func_002b2d00(s32, s32, s32, s32, s8);
void memcpy(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_00795FE0[];
extern u8 D_0064A360[];
extern u8 D_0064A3A0[];
extern u8 D_00763A18[];
extern void func_00332b60(u8 *, u8 *);
extern s32 func_0046aea0(void *);
extern void func_00440b68(void *, void *, s32);
extern void *func_00454a60(void *, s32);
extern s32 func_0046a750(s32);
extern s32 H_Cdvd_IsFileLoaded(void *);
extern u8 *func_0033d130(void *, s32, s32);
extern s32 func_00122720(void);
extern s32 func_002bb680(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern void func_002bb550(s8 arg0);
extern s8 func_002bab80(s32 arg0);
extern void func_002badc0(s32 arg0, s32 arg1);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s32 func_00110a60(s32 arg0, s32 arg1);
extern s32 func_00452380(void *arg0);
extern u8 D_0064A3C0[];
extern f32 func_0033d630(F2_0033 pos, s16 angleStep, f32 angleOffset, u8 alpha, s8 highlight);
extern void func_0033d520(u8 *arg0, f32 fparg0, f32 fparg1, s8 arg1, s16 arg2, s64 arg3);
extern void func_00122520(s32 arg0, s32 arg1);
extern f32 iGpffff8424;
extern f32 iGpffff851c;
extern f32 iGpffff809c;
extern f32 iGpffff84cc;
extern f32 D_0064A210[];
extern f32 D_0064A218[];
extern void func_0045af60(s32, s32, s32, s32);
extern s8 func_002bb1c0(s8 arg0);
extern void func_00106620(s16 arg0, s32 arg1);
extern void func_002e7a80(s32 arg0);
void func_0033c490(u8 *arg0);
extern void func_0033d550(void *arg0);
extern u16 D_008C024E[];
extern f32 D_0064A290[];
extern f32 D_0064A298[];
extern f32 D_0064A328[];
extern f32 D_0064A330[];
extern u16 D_008C027A[];
extern u8 D_007950B0[];
extern char iGpffffa930;
extern void func_002e7870(void);
extern u16 D_008C0276[];
extern s32 func_002e26a0(void);
extern s16 func_002b2d50(s16, s16, s16, s16, s16);
extern void func_002b2e70(s32, s32, s32, s32, void *, void *);
extern void func_002b2f90(s32, s32, s32, s32, void *, void *);
extern void sprintf(void *dst, void *fmt, s32 val);
extern void func_002bbd80(s8 arg0, s32 arg1, void *arg2);
extern void func_002bafc0(s8 arg0, s32 arg1);
extern void func_002bb0a0(s8 arg0, s32 arg1);
extern void func_002bbf60(void);

/* The shared SDK update signature accepts func_00332bb0 directly at the
   func_0033be40 registration site. */
// FUN_00332BB0
/* Object 37380/window 37392 (retail tail is zero padding). The loops that
   retail colours apart keep their own counters; the case 5 slot loop needs its
   counter and slot index as block locals for retail's $s5/$s4 colouring.
   measured: normalized_diff 0; opt_loop_invariants on hoists the 140/340/20/10
   and (s8)1 loop constants into the preheaders as retail does. */
#pragma opt_loop_invariants on
s32 func_00332bb0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);
    s16 k;
    s16 i;
    s16 i4;
    s16 i7;
    s16 i10;
    s16 i11;
    s16 i15;
    s16 i16;
    s16 i17;
    s16 i22;
    s16 i32;
    s16 i34;
    s16 i35;
    s16 i42;
    s8 flag = 0;
    s16 j;
    void *task;
    F2_0033 *tbl;
    void *font;
    s64 layer0;
    s64 layer1;
    s64 layer2;
    s64 layer3;
    s32 index;
    f32 *coords;
    s32 slot;
    f32 *slotPos;
    void *slotFont;
    char buf[128];
    void *labelFont;
    void *rowFont;
    void *capFont;
    void *cardFont;
    void *iconFont;
    s32 rowIndex;
    s32 listIndex;
    s32 cardIndex;

    task = func_00460990();
    *(void **)((u8 *)task + 8) = (void *)func_00332b60;
    *(void **)((u8 *)task + 0x10) = work;
    func_00460ac0(D_00795FE0, task);
    switch (*(s8 *)(work + 0)) {
    case 0:
        *(s32 *)(work + 0xC) = func_0046aea0(D_0064A360);
        func_00440b68("%s %d", D_0064A380, 0x17B);
        *(void **)(work + 0x428) = func_00454a60(D_0064A3A0, 0);
        *(s8 *)(work + 0) = 1;
        /* fallthrough */
    case 1:
        if (func_0046a750(*(s32 *)(work + 0xC)) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(*(void **)(work + 0x428)) == 0) {
            break;
        }
        *(s8 *)(work + 0) = 2;
        for (j = 0; j < 0x5A; j++) {
            if (*(void **)(work + j * 4 + 0x10) != 0) {
                *(void **)(work + j * 4 + 0x10) = 0;
            }
            *(void **)(work + j * 4 + 0x10) = func_0033d130(arg0, (u16)j, *(s32 *)(work + 0xC));
        }
        for (k = 0; k < 0xF; k++) {
            if (*(void **)(work + k * 4 + 0x178) != 0) {
                *(void **)(work + k * 4 + 0x178) = 0;
            }
        }
        *(void **)(work + 0x178) = func_0033d130(arg0, 0x2B, *(s32 *)(work + 0xC));
        *(void **)(work + 0x17C) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
        *(void **)(work + 0x180) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
        *(void **)(work + 0x184) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
        for (j = 0; j < 4; j++) {
            *(void **)(work + j * 4 + 0x188) = func_0033d130(arg0, 0x28, *(s32 *)(work + 0xC));
            func_0033d320(*(void **)(work + j * 4 + 0x188), 13, 0);
            func_0033d4e0(*(void **)(work + j * 4 + 0x188), 0.0f, 0.0f, 0, 0, 0);
        }
        *(void **)(work + 0x19C) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x198) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A0) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A4) = func_0033d130(arg0, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A8) = func_0033d130(arg0, 0x40, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1AC) = func_0033d130(arg0, 0x41, *(s32 *)(work + 0xC));
        if (func_002e2670() > 5) {
            *(f32 *)(work + 0x420) = 108.0f / (f32)(func_002e2670() - 5);
        }
        *(s8 *)(work + 9) = 0;
        if ((s8)func_00110a60(func_002e78a0(), func_002e78e0()) == 1) {
            *(s8 *)(work + 9) = 1;
        }
        break;
    case 2:
        func_002e7870();
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        *(s16 *)(work + 0x41E) = 1;
        tbl = (F2_0033 *)D_0064A290;
        func_0033d320(*(void **)(work + 0x110), 0, 0);
        func_0033d3e0(*(void **)(work + 0x110), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x110), 17.0f);
        func_0033d3d0(*(void **)(work + 0x110), 0x63);
        tbl = (F2_0033 *)D_0064A298;
        func_0033d320(*(void **)(work + 0x114), 0, 0);
        func_0033d3e0(*(void **)(work + 0x114), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x114), 17.0f);
        func_0033d3d0(*(void **)(work + 0x114), 0x63);
        tbl = (F2_0033 *)D_0064A290;
        func_0033d320(*(void **)(work + 0x1A8), 0, 0);
        func_0033d3e0(*(void **)(work + 0x1A8), func_002b2970(-0x125, tbl->y), func_002b2970(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        *(FclDrawColor *)(func_0033d310(*(void **)(work + 0x1A8)) + 0x79) = func_002b2a60(0, 0, 0, 0xFF);
        func_0033d3c0(*(void **)(work + 0x1A8), 16.0f);
        func_0033d3d0(*(void **)(work + 0x1A8), 0x63);
        tbl = (F2_0033 *)D_0064A298;
        func_0033d320(*(void **)(work + 0x1AC), 0, 0);
        func_0033d3e0(*(void **)(work + 0x1AC), func_002b2970(-180.0f, tbl->y), func_002b2970(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        *(FclDrawColor *)(func_0033d310(*(void **)(work + 0x1AC)) + 0x79) = func_002b2a60(0, 0, 0, 0xFF);
        func_0033d3c0(*(void **)(work + 0x1AC), 16.0f);
        func_0033d3d0(*(void **)(work + 0x1AC), 0x63);
        func_0033d320(*(void **)(work + 0x10), 0, 0);
        func_0033d3e0(*(void **)(work + 0x10), func_002b2970(0x28A, D_0064A090[1]), func_002b2970(D_0064A090[0], D_0064A090[1]),
                      0, 0x1E, 0xA);
        func_0033d320(*(void **)(work + 0x10), 3, 0);
        func_0033d520(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0x1E, 0xA);
        func_0033d3c0(*(void **)(work + 0x10), 36.0f);
        func_0033d3d0(*(void **)(work + 0x10), 0x62);
        tbl = (F2_0033 *)D_0064A338;
        func_0033d320(*(void **)(work + 0x164), 0, 0);
        func_0033d4b0(*(void **)(work + 0x164), 0, 0xFF, 0, 0, 0x2B);
        func_0033d4e0(*(void **)(work + 0x164), 0.1f, 1.0f, 0, 0xF, 0x2B);
        labelFont = func_0046d200(*(void **)(work + 0xC), 0x55);
        func_0033d3e0(*(void **)(work + 0x164),
                      func_002b2970((func_0046b260(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (func_0046b2f0(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      func_002b2970(tbl->x, tbl->y), 0, 0xF, 0x2B);
        func_0046d280(labelFont);
        func_0033d3c0(*(void **)(work + 0x164), 69.0f);
        func_0033d3d0(*(void **)(work + 0x164), 0x56);
        *(s16 *)(work + 0x3D4) = 0x2D;
        func_0033d320(*(void **)(work + 0xB0), 0, 0);
        func_0033d4b0(*(void **)(work + 0xB0), 0, 0xFF, 0, 7, 0x3F);
        func_0033d4e0(*(void **)(work + 0xB0), 0.1f, 1.0f, 0, 0xF, 0x3F);
        func_0033d3c0(*(void **)(work + 0xB0), 52.0f);
        func_0033d3d0(*(void **)(work + 0xB0), 0x5B);
        for (i4 = 0; i4 < 3; i4++) {
            func_0033d320(*(void **)(work + i4 * 4 + 0x17C), 0, 0);
            func_0033d4b0(*(void **)(work + i4 * 4 + 0x17C), 0, 0xFF, 0, 7, 0x3F);
            func_0033d4e0(*(void **)(work + i4 * 4 + 0x17C), 0.1f, 1.0f, 0, 0xF, 0x3F);
            func_0033d520(*(u8 **)(work + i4 * 4 + 0x17C), (f32)((i4 + 1) * 0x5A), (f32)((i4 + 1) * 0x5A), 0, 0, 0);
            func_0033d3c0(*(void **)(work + i4 * 4 + 0x17C), (f32)(i4 + 0x31));
            func_0033d3d0(*(void **)(work + i4 * 4 + 0x17C), 0x5B);
            *(s16 *)(func_0033d310(*(void **)(work + i4 * 4 + 0x17C)) + 0x100) = *(s16 *)(func_0033d310(*(void **)(work + i4 * 4 + 0x17C)) + 0x102) = 0;
        }
        *(f32 *)(work + 0x1D0) = 0x28A;
        *(f32 *)(work + 0x1D4) = 15.0f;
        *(f32 *)(work + 0x1D8) = 580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()) + 0.0f;
        *(f32 *)(work + 0x1DC) = 15.0f;
        *(s16 *)(work + 0x1E8) = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        func_0033d320(*(void **)(work + 0xB4), 0, 0);
        func_0033d3e0(*(void **)(work + 0xB4), func_002b2970(-180.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0xF, 0x16);
        func_0033d3c0(*(void **)(work + 0xB4), 47.0f);
        func_0033d3d0(*(void **)(work + 0xB4), 0x61);
        tbl = (F2_0033 *)D_0064A1E0;
        func_0033d320(*(void **)(work + 0xB8), 0, 0);
        func_0033d3e0(*(void **)(work + 0xB8), func_002b2970(-200.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1, 9, 0x1C);
        func_0033d3c0(*(void **)(work + 0xB8), 33.0f);
        func_0033d3d0(*(void **)(work + 0xB8), 0x61);
        tbl = (F2_0033 *)D_0064A1E8;
        func_0033d320(*(void **)(work + 0xBC), 0, 0);
        func_0033d3e0(*(void **)(work + 0xBC), func_002b2970(-50.0f, tbl->y), func_002b2970(153.0f, tbl->y), 0, 0xF, 0x19);
        func_0033d3c0(*(void **)(work + 0xBC), 48.0f);
        func_0033d3d0(*(void **)(work + 0xBC), 0x61);
        func_0033d320(*(void **)(work + 0x178), 0, 0);
        func_0033d3e0(*(void **)(work + 0x178), func_002b2970(-50.0f, tbl->y), func_002b2970(203.0f, tbl->y), 0, 0xF, 0x19);
        func_0033d3c0(*(void **)(work + 0x178), 48.0f);
        func_0033d3d0(*(void **)(work + 0x178), 0x61);
        tbl = (F2_0033 *)D_0064A0E8;
        func_0033d320(*(void **)(work + 0x3C), 0, 0);
        func_0033d3e0(*(void **)(work + 0x3C), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d4b0(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xA, 0x28);
        func_0033d3c0(*(void **)(work + 0x3C), 46.0f);
        func_0033d3d0(*(void **)(work + 0x3C), 0x62);
        func_0033d320(*(void **)(work + 0x14), 0, 0);
        func_0033d4b0(*(void **)(work + 0x14), 0, 0xFF, 0, 5, 0x28);
        func_0033d3c0(*(void **)(work + 0x14), 30.0f);
        func_0033d3d0(*(void **)(work + 0x14), 0x63);
        for (j = 0; j < 4; j++) {
            layer0 = (s16)(j * 3 + 0x2D);
            rowIndex = j + 3;
            coords = (f32 *)((u8 *)D_0064A090 + rowIndex * 8);
            func_0033d320(*(void **)(work + j * 4 + 0x1C), 0, 0);
            func_0033d4e0(*(void **)(work + j * 4 + 0x1C), 0.7f, 1.0f, 0, 5, layer0);
            func_0033d4b0(*(void **)(work + j * 4 + 0x1C), 0, 0xFF, 0, 5, layer0);
            func_0033d3c0(*(void **)(work + j * 4 + 0x1C), (f32)(j + 0x1A));
            func_0033d3d0(*(void **)(work + j * 4 + 0x1C), 0x63);
            rowFont = func_0046d200(*(void **)(work + 0xC), rowIndex);
            func_0033d3e0(*(void **)(work + j * 4 + 0x1C),
                          func_002b2970((func_0046b260(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (func_0046b2f0(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          func_002b2970(coords[0], coords[1]), 0, 5, layer0);
            func_0046d280(rowFont);
        }
        *(s8 *)(work + 0) = 3;
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        /* fallthrough */
    case 3:
        *(s16 *)(work + 0x3D4) = func_002b2d00(*(s16 *)(work + 0x3D4), 1, 0, 0, 1);
        if (*(s16 *)(work + 0x3D4) == 0) {
            for (i7 = 0; i7 < 0x24; i7++) {
                *(u8 *)(work + i7 + 0x2B4) = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
                if (*(s8 *)(work + i7 + 0x2D8) == 1) {
                    *(f32 *)(work + i7 * 4 + 0x2FC) =
                        func_0033d630(func_002b2970(23.0f, 225.0f), (s16)(i7 * 10), *(f32 *)(work + 0x2A8), *(u8 *)(work + i7 + 0x2B4), 1);
                }
            }
            *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
            *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), *(s16 *)(work + 0x41E), 0x2D0, 1, 2);
            *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        }
        for (j = 0; j < 4; j++) {
            if (func_0033d390(*(void **)(work + j * 4 + 0x1C), 2) == 0) {
                func_0033d3d0(*(void **)(work + j * 4 + 0x1C), 0xAB);
            }
        }
        if (func_0033d390(*(void **)(work + 0xB0), 2) == 0 && func_0033d390(*(void **)(work + 0xB0), 4) == 0) {
            func_0033d320(*(void **)(work + 0x58), 0, 0);
            func_0033d3c0(*(void **)(work + 0x58), 80.0f);
            func_0033d3d0(*(void **)(work + 0x58), 0x3D);
            func_0033d320(*(void **)(work + 0x5C), 0, 0);
            func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
            func_0033d3d0(*(void **)(work + 0x5C), 0x3D);
            tbl = (F2_0033 *)D_0064A2A0;
            func_0033d320(*(void **)(work + 0x118), 0, 0);
            func_0033d3c0(*(void **)(work + 0x118), 82.0f);
            func_0033d3d0(*(void **)(work + 0x118), 0x3E);
            func_0033d3e0(*(void **)(work + 0x118), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                          func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
            tbl = (F2_0033 *)D_0064A2A8;
            func_0033d320(*(void **)(work + 0x11C), 0, 0);
            func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
            func_0033d3d0(*(void **)(work + 0x11C), 0x3E);
            func_0033d3e0(*(void **)(work + 0x11C), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                          func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
            for (j = 0; j < 6; j++) {
                func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
                func_0033d3c0(*(void **)(work + j * 4 + 0x40), (f32)(j + 0x4A));
                func_0033d3d0(*(void **)(work + j * 4 + 0x40), 0x3F);
            }
            func_0033d320(*(void **)(work + 0x4C), 0, 0);
            func_0033d320(*(void **)(work + 0x44), 0, 0);
            func_0033d320(*(void **)(work + 0x48), 0, 0);
            for (i10 = 0; i10 < 0x24; i10++) {
                if (!(*(f32 *)(work + i10 * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + i10 * 4 + 0x2FC) < 340.0f) {
                    *(s8 *)(work + i10 + 0x2D8) = 0;
                } else if (!(*(f32 *)(work + i10 * 4 + 0x2FC) < 140.0f)) {
                    *(s16 *)(work + i10 * 2 + 0x38C) = (*(f32 *)(work + i10 * 4 + 0x2FC) - 340.0f) / 10.0f;
                } else {
                    *(s16 *)(work + i10 * 2 + 0x38C) = (20.0f + *(f32 *)(work + i10 * 4 + 0x2FC)) / 10.0f;
                }
                *(s16 *)(work + i10 * 2 + 0x3D6) = 0;
                *(s32 *)(work + 0x2B0) = 0;
            }
            *(s8 *)(work + 0) = 4;
            break;
        }
        if (!(D_008C024E[0] & 0x40) && !(D_008C024E[0] & 0x20) && !(D_008C024E[0] & 0x10) && !(D_008C024E[0] & 0x80)) {
            break;
        }
        tbl = (F2_0033 *)D_0064A290;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0x1A8)) + 0x2C) = func_002b2970(200.0f + tbl->x, tbl->y);
        func_0033d320(*(void **)(work + 0x1A8), 1, 1);
        tbl = (F2_0033 *)D_0064A298;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0x1AC)) + 0x2C) = func_002b2970(200.0f + tbl->x, tbl->y);
        func_0033d320(*(void **)(work + 0x1AC), 1, 1);
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0x10)) + 0x2C) = func_002b2970(D_0064A090[0], D_0064A090[1]);
        *(f32 *)(func_0033d310(*(void **)(work + 0x10)) + 0xC4) = 0.0f;
        func_0033d320(*(void **)(work + 0x10), 1, 1);
        func_0033d320(*(void **)(work + 0x10), 3, 1);
        tbl = (F2_0033 *)D_0064A338;
        *(u8 *)(func_0033d310(*(void **)(work + 0x164)) + 0x62) = 0xFF;
        *(f32 *)(func_0033d310(*(void **)(work + 0x164)) + 0x94) = 1.0f;
        *(f32 *)(func_0033d310(*(void **)(work + 0x164)) + 0xA0) = 1.0f;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0x164)) + 0x2C) = func_002b2970(tbl->x, tbl->y);
        func_0033d320(*(void **)(work + 0x164), 2, 1);
        func_0033d320(*(void **)(work + 0x164), 1, 1);
        func_0033d320(*(void **)(work + 0x164), 4, 1);
        *(u8 *)(func_0033d310(*(void **)(work + 0xB0)) + 0x62) = 0xFF;
        *(f32 *)(func_0033d310(*(void **)(work + 0xB0)) + 0x94) = 1.0f;
        *(f32 *)(func_0033d310(*(void **)(work + 0xB0)) + 0xA0) = 1.0f;
        func_0033d320(*(void **)(work + 0xB0), 2, 1);
        func_0033d320(*(void **)(work + 0xB0), 4, 1);
        for (i11 = 0; i11 < 3; i11++) {
            *(u8 *)(func_0033d310(*(void **)(work + i11 * 4 + 0x17C)) + 0x62) = 0xFF;
            *(f32 *)(func_0033d310(*(void **)(work + i11 * 4 + 0x17C)) + 0x94) = 1.0f;
            *(f32 *)(func_0033d310(*(void **)(work + i11 * 4 + 0x17C)) + 0xA0) = 1.0f;
            *(f32 *)(func_0033d310(*(void **)(work + i11 * 4 + 0x17C)) + 0xC4) = (i11 + 1) * 0x5A;
            func_0033d320(*(void **)(work + i11 * 4 + 0x17C), 2, 1);
            func_0033d320(*(void **)(work + i11 * 4 + 0x17C), 3, 1);
            func_0033d320(*(void **)(work + i11 * 4 + 0x17C), 4, 1);
        }
        *(f32 *)(work + 0x1E0) = 580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()) + 0.0f;
        *(f32 *)(work + 0x1E4) = 15.0f;
        *(s16 *)(work + 0x1EA) = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0xB4)) + 0x2C) = func_002b2970(tbl->x, tbl->y);
        func_0033d320(*(void **)(work + 0xB4), 1, 1);
        tbl = (F2_0033 *)D_0064A1E0;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0xB8)) + 0x2C) = func_002b2970(tbl->x, tbl->y);
        func_0033d320(*(void **)(work + 0xB8), 1, 1);
        tbl = (F2_0033 *)D_0064A1E8;
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0xBC)) + 0x2C) = func_002b2970(153.0f, tbl->y);
        func_0033d320(*(void **)(work + 0xBC), 1, 1);
        *(F2_0033 *)(func_0033d310(*(void **)(work + 0x178)) + 0x2C) = func_002b2970(203.0f, tbl->y);
        func_0033d320(*(void **)(work + 0x178), 1, 1);
        *(u8 *)(func_0033d310(*(void **)(work + 0x3C)) + 0x62) = 0xFF;
        func_0033d320(*(void **)(work + 0x3C), 2, 1);
        *(u8 *)(func_0033d310(*(void **)(work + 0x14)) + 0x62) = 0xFF;
        func_0033d320(*(void **)(work + 0x14), 2, 1);
        for (j = 0; j < 4; j++) {
            coords = (f32 *)((u8 *)D_0064A090 + (j + 3) * 8);
            *(F2_0033 *)(func_0033d310(*(void **)(work + j * 4 + 0x1C)) + 0x2C) = func_002b2970(coords[0], coords[1]);
            *(f32 *)(func_0033d310(*(void **)(work + j * 4 + 0x1C)) + 0x94) = 1.0f;
            *(f32 *)(func_0033d310(*(void **)(work + j * 4 + 0x1C)) + 0xA0) = 1.0f;
            *(u8 *)(func_0033d310(*(void **)(work + j * 4 + 0x1C)) + 0x62) = 0xFF;
            func_0033d320(*(void **)(work + j * 4 + 0x1C), 2, 1);
            func_0033d320(*(void **)(work + j * 4 + 0x1C), 1, 1);
            func_0033d320(*(void **)(work + j * 4 + 0x1C), 4, 1);
        }
        for (i = 0; i < 0x24; i++) {
            *(u8 *)(work + i + 0x2B4) = 0xFF;
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        func_0033d320(*(void **)(work + 0x58), 0, 0);
        func_0033d3c0(*(void **)(work + 0x58), 80.0f);
        func_0033d3d0(*(void **)(work + 0x58), 0x3D);
        func_0033d320(*(void **)(work + 0x5C), 0, 0);
        func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
        func_0033d3d0(*(void **)(work + 0x5C), 0x3D);
        tbl = (F2_0033 *)D_0064A2A0;
        func_0033d320(*(void **)(work + 0x118), 0, 0);
        func_0033d3c0(*(void **)(work + 0x118), 82.0f);
        func_0033d3d0(*(void **)(work + 0x118), 0x3E);
        func_0033d3e0(*(void **)(work + 0x118), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        func_0033d320(*(void **)(work + 0x11C), 0, 0);
        func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
        func_0033d3d0(*(void **)(work + 0x11C), 0x3E);
        func_0033d3e0(*(void **)(work + 0x11C), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        for (j = 0; j < 6; j++) {
            func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
            func_0033d3c0(*(void **)(work + j * 4 + 0x40), (f32)(j + 0x4A));
            func_0033d3d0(*(void **)(work + j * 4 + 0x40), 0x3F);
        }
        func_0033d320(*(void **)(work + 0x4C), 0, 0);
        func_0033d320(*(void **)(work + 0x44), 0, 0);
        func_0033d320(*(void **)(work + 0x48), 0, 0);
        for (i15 = 0; i15 < 0x24; i15++) {
            if (!(*(f32 *)(work + i15 * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + i15 * 4 + 0x2FC) < 340.0f) {
                *(s8 *)(work + i15 + 0x2D8) = 0;
            } else if (!(*(f32 *)(work + i15 * 4 + 0x2FC) < 140.0f)) {
                *(s16 *)(work + i15 * 2 + 0x38C) = (*(f32 *)(work + i15 * 4 + 0x2FC) - 340.0f) / 10.0f;
            } else {
                *(s16 *)(work + i15 * 2 + 0x38C) = (20.0f + *(f32 *)(work + i15 * 4 + 0x2FC)) / 10.0f;
            }
            *(s16 *)(work + i15 * 2 + 0x3D6) = 0;
            *(s32 *)(work + 0x2B0) = 0;
        }
        *(s8 *)(work + 0) = 4;
        break;
    case 4:
        *(f32 *)(work + 0x1E0) =
            func_002b2aa0(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), *(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = func_002b2cb0(*(s16 *)(work + 0x1EA), 1, 10, 1, 1);
        for (i16 = 0; i16 < 0x24; i16++) {
            if (*(s8 *)(work + i16 + 0x2D8) == 1) {
                *(s16 *)(work + i16 * 2 + 0x38C) = func_002b2d00(*(s16 *)(work + i16 * 2 + 0x38C), 1, 0, 0, 1);
                if (*(s16 *)(work + i16 * 2 + 0x38C) == 0) {
                    *(u8 *)(work + i16 + 0x2B4) = func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(work + i16 * 2 + 0x3D6), 15.0f);
                    *(s16 *)(work + i16 * 2 + 0x3D6) = func_002b2cb0(*(s16 *)(work + i16 * 2 + 0x3D6), 1, 0xF, 1, 1);
                }
                *(f32 *)(work + i16 * 4 + 0x2FC) = func_0033d630(func_002b2970(23.0f, 225.0f), (s16)(i16 * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + i16 + 0x2B4), 1);
            }
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), *(s16 *)(work + 0x41E), 0x2D0, 1, 2);
        for (i17 = 0; i17 < 0x24; i17++) {
            if (!(*(f32 *)(work + i17 * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + i17 * 4 + 0x2FC) < 340.0f) {
                *(s8 *)(work + i17 + 0x2D8) = 0;
            } else if (*(s16 *)(work + i17 * 2 + 0x3D6) == 0xF) {
                *(s8 *)(work + i17 + 0x2D8) = 0;
            }
            if (*(s8 *)(work + i17 + 0x2D8) == 1) {
                flag = 1;
            }
        }
        if (flag != 0) {
            break;
        }
        func_0033d320(*(void **)(work + 0x60), 0, 0);
        func_0033d3c0(*(void **)(work + 0x60), 14.0f);
        func_0033d3d0(*(void **)(work + 0x60), 0x64);
        func_0033d320(*(void **)(work + 0x164), 0, 1);
        *(s32 *)(work + 0x2AC) = 0;
        *(s8 *)(work + 0) = 5;
        if (*(s8 *)(work + 0x424) == 1) {
            *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            func_002badc0(*(s8 *)(work + 8), 2);
            *(s8 *)(work + 0) = 6;
        } else if (*(s8 *)(work + 9) == 1) {
            *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            func_002badc0(*(s8 *)(work + 8), 3);
            *(s8 *)(work + 0) = 7;
        } else {
            *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            func_002badc0(*(s8 *)(work + 8), 4);
            *(s8 *)(work + 0) = 7;
        }
        break;
    case 6:
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
            break;
        }
        func_002bb550(*(s8 *)(work + 8));
        *(s8 *)(work + 0) = 5;
        if (*(s8 *)(work + 9) == 1) {
            *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            func_002badc0(*(s8 *)(work + 8), 3);
            *(s8 *)(work + 0) = 7;
        }
        break;
    case 7:
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
            break;
        }
        func_002bb550(*(s8 *)(work + 8));
        *(s8 *)(work + 0) = 5;
        break;
    case 5:
        if (D_008C027A[0] & 0x4000) {
            *(s8 *)(work + 1) = func_002b2cb0(*(s8 *)(work + 1), 1, 2, 0, 2);
            for (j = 0; j < 6; j++) {
                func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
            }
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            *(s8 *)(work + 1) = func_002b2d00(*(s8 *)(work + 1), 1, 0, 2, 2);
            for (j = 0; j < 6; j++) {
                func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
            }
            func_0045af60(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            func_0045af60(0, 0, 0, 1);
            switch (*(s8 *)(work + 1)) {
            case 0:
                {
                    s16 n;
                    s32 slot;

                    for (n = 0; n < 4; n++) {
                        slot = n + 3;
                        slotPos = (f32 *)((u8 *)D_0064A090 + slot * 8);
                        func_0033d4e0(*(void **)(work + n * 4 + 0x1C), 1.0f, 0.5f, 0, 3, n);
                        func_0033d4b0(*(void **)(work + n * 4 + 0x1C), 0xFF, 0, 0, 3, n);
                        slotFont = func_0046d200(*(void **)(work + 0xC), slot);
                        func_0033d3e0(*(void **)(work + n * 4 + 0x1C), func_002b2970(slotPos[0], slotPos[1]),
                                      func_002b2970((func_0046b260(slotFont) / 10.0f) * 1.5f + slotPos[0] + 0.0f,
                                                    (func_0046b2f0(slotFont) / 10.0f) * 1.5f + slotPos[1] + 0.0f),
                                      0, 3, n);
                        func_0046d280(slotFont);
                    }
                }
                func_0033d320(*(void **)(work + 0x14), 0, 0);
                func_0033d4b0(*(void **)(work + 0x14), 0xFF, 0, 0, 6, 0);
                tbl = (F2_0033 *)D_0064A1D8;
                func_0033d3e0(*(void **)(work + 0xB4), func_002b2970(tbl->x, tbl->y), func_002b2970(-180.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A1E0;
                func_0033d3e0(*(void **)(work + 0xB8), func_002b2970(tbl->x, tbl->y), func_002b2970(-200.0f, tbl->y), 0, 0xD,
                              8);
                tbl = (F2_0033 *)D_0064A1E8;
                func_0033d3e0(*(void **)(work + 0xBC), func_002b2970(153.0f, tbl->y), func_002b2970(-100.0f, tbl->y), 0, 0xD,
                              5);
                func_0033d3e0(*(void **)(work + 0x178), func_002b2970(203.0f, tbl->y), func_002b2970(-50.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A0E8;
                func_0033d3e0(*(void **)(work + 0x3C), func_002b2970(tbl->x, tbl->y), func_002b2970(-200.0f, tbl->y), 0, 0xD,
                              5);
                func_0033d4e0(*(void **)(work + 0xB0), 1.0f, 4.5f, 0, 0x14, 0);
                for (j = 0; j < 3; j++) {
                    func_0033d4e0(*(void **)(work + j * 4 + 0x17C), 1.0f, 4.5f, 0, 0x14, 0);
                }
                func_0033d3c0(*(void **)(work + 0x110), 84.0f);
                func_0033d3c0(*(void **)(work + 0x114), 84.0f);
                func_0033d3c0(*(void **)(work + 0x60), 83.0f);
                *(s8 *)(work + 0) = 9;
                break;
            case 1:
                for (j = 0; j < 4; j++) {
                    func_0033d4b0(*(void **)(work + j * 4 + 0x1C), 0xFF, 0, 0, 5, 0);
                }
                func_0033d4b0(*(void **)(work + 0x10), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x110), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x114), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x14), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0xB4), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0xB8), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0xBC), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x178), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x3C), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0xB0), 0xFF, 0, 0, 5, 0);
                for (j = 0; j < 3; j++) {
                    func_0033d4b0(*(void **)(work + j * 4 + 0x17C), 0xFF, 0, 0, 5, 0);
                }
                func_0033d4b0(*(void **)(work + 0x58), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x5C), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x118), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x11C), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x40), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x50), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x48), 0xFF, 0, 0, 5, 0);
                func_0033d4b0(*(void **)(work + 0x60), 0xFF, 0, 0, 5, 0);
                func_003322d0(arg0);
                *(s8 *)(work + 0) = 0x10;
                break;
            case 2:
                func_0033bf90(arg0);
                break;
            }
        } else if (D_008C024E[0] & 0x20) {
            func_0033bf90(arg0);
            func_0045af60(0, 0, 0, 2);
        }
        tbl = (F2_0033 *)D_0064A2A0;
        func_0033d3e0(*(void **)(work + 0x118), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        func_0033d3e0(*(void **)(work + 0x11C), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        switch (*(s8 *)(work + 1)) {
        case 0:
            func_0033d320(*(void **)(work + 0x4C), 0, 0);
            func_0033d320(*(void **)(work + 0x44), 0, 0);
            func_0033d320(*(void **)(work + 0x48), 0, 0);
            break;
        case 1:
            func_0033d320(*(void **)(work + 0x40), 0, 0);
            func_0033d320(*(void **)(work + 0x50), 0, 0);
            func_0033d320(*(void **)(work + 0x48), 0, 0);
            break;
        case 2:
            func_0033d320(*(void **)(work + 0x40), 0, 0);
            func_0033d320(*(void **)(work + 0x44), 0, 0);
            func_0033d320(*(void **)(work + 0x54), 0, 0);
            break;
        }
        break;
    case 9:
        if (func_0033d390(*(void **)(work + 0x14), 2) != 0 || func_0033d390(*(void **)(work + 0x1C), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x1C), 2) != 0 || func_0033d390(*(void **)(work + 0x1C), 1) != 0 ||
            func_0033d390(*(void **)(work + 0x20), 4) != 0 || func_0033d390(*(void **)(work + 0x20), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x20), 1) != 0 || func_0033d390(*(void **)(work + 0x24), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x24), 2) != 0 || func_0033d390(*(void **)(work + 0x24), 1) != 0 ||
            func_0033d390(*(void **)(work + 0x28), 4) != 0 || func_0033d390(*(void **)(work + 0x28), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x28), 1) != 0) {
            break;
        }
        for (j = 0; j < 6; j++) {
            func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
        }
        func_0033d320(*(void **)(work + 0x58), 0, 1);
        func_0033d320(*(void **)(work + 0x5C), 0, 1);
        func_0033d320(*(void **)(work + 0x118), 0, 1);
        func_0033d320(*(void **)(work + 0x11C), 0, 1);
        func_0033d320(*(void **)(work + 0x110), 0, 1);
        func_0033d320(*(void **)(work + 0x114), 0, 1);
        func_0033d320(*(void **)(work + 0x60), 0, 1);
        func_0033d3d0(*(void **)(work + 0xB0), 0x65);
        for (j = 0; j < 3; j++) {
            func_0033d3d0(*(void **)(work + j * 4 + 0x17C), 0x65);
        }
        for (i22 = 0; i22 < 4; i22++) {
            func_0033d320(*(void **)(work + i22 * 4 + 0x188), 13, 0);
            func_0033d320(*(void **)(work + i22 * 4 + 0x188), 0, 0);
            func_0033d4e0(*(void **)(work + i22 * 4 + 0x188), 0.1f, 2.7f, 0, 0xC, 0);
            func_0033d520(*(u8 **)(work + i22 * 4 + 0x188), 0.0f, i22 * 0x5A, 0, 0, 0);
            func_0033d3c0(*(void **)(work + i22 * 4 + 0x188), 1.0f);
            func_0033d3d0(*(void **)(work + i22 * 4 + 0x188), 0x64);
            *(s16 *)(func_0033d310(*(void **)(work + i22 * 4 + 0x188)) + 0x100) = *(s16 *)(func_0033d310(*(void **)(work + i22 * 4 + 0x188)) + 0x102) = 0;
            *(u8 *)(func_0033d310(*(void **)(work + i22 * 4 + 0x188)) + 0x62) = 2;
        }
        func_0033d320(*(void **)(work + 0x10), 0, 0);
        func_0033d3e0(*(void **)(work + 0x10), func_002b2970(D_0064A090[0], D_0064A090[1]), func_002b2970(428.0f, 241.0f),
                      0, 0xF, 0);
        func_0033d520(*(u8 **)(work + 0x10), -360.0f, 0.0f, 0, 0xF, 0);
        tbl = (F2_0033 *)D_0064A320;
        func_0033d320(*(void **)(work + 0x158), 0, 0);
        func_0033d4b0(*(void **)(work + 0x158), 0, 0xFF, 0, 0, 0xF);
        func_0033d4e0(*(void **)(work + 0x158), 0.1f, 1.0f, 0, 8, 0xF);
        func_0033d3c0(*(void **)(work + 0x158), 45.0f);
        func_0033d3d0(*(void **)(work + 0x158), 0x5B);
        labelFont = func_0046d200(*(void **)(work + 0xC), 0x52);
        func_0033d3e0(*(void **)(work + 0x158),
                      func_002b2970((func_0046b260(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (func_0046b2f0(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      func_002b2970(tbl->x, tbl->y), 0, 8, 0xF);
        func_0046d280(labelFont);
        tbl = (F2_0033 *)D_0064A200;
        func_0033d320(*(void **)(work + 0xC8), 0, 0);
        func_0033d3e0(*(void **)(work + 0xC8), func_002b2970(660.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1, 0x14, 5);
        func_0033d3c0(*(void **)(work + 0xC8), 42.0f);
        func_0033d3d0(*(void **)(work + 0xC8), 0x61);
        tbl = (F2_0033 *)D_0064A1F0;
        func_0033d320(*(void **)(work + 0xC0), 0, 0);
        func_0033d3e0(*(void **)(work + 0xC0), func_002b2970(660.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 8, 5);
        func_0033d3c0(*(void **)(work + 0xC0), 43.0f);
        func_0033d3d0(*(void **)(work + 0xC0), 0x61);
        tbl = (F2_0033 *)D_0064A1F8;
        func_0033d320(*(void **)(work + 0xC4), 0, 0);
        func_0033d3e0(*(void **)(work + 0xC4), func_002b2970(980.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 8, 5);
        func_0033d520(*(u8 **)(work + 0xC4), 0.0f, -90.0f, 0, 0, 0);
        *(f32 *)(func_0033d310(*(void **)(work + 0xC4)) + 0xBC) = *(f32 *)(func_0033d310(*(void **)(work + 0xC4)) + 0xC0) =
            *(f32 *)(func_0033d310(*(void **)(work + 0xC4)) + 0xC4) = -90.0f;
        func_0033d3c0(*(void **)(work + 0xC4), 44.0f);
        func_0033d3d0(*(void **)(work + 0xC4), 0x61);
        for (j = 0; j < 4; j++) {
            layer1 = (s16)(j * 3 + 0xF);
            listIndex = j + 7;
            coords = (f32 *)((u8 *)D_0064A090 + listIndex * 8);
            func_0033d320(*(void **)(work + j * 4 + 0x2C), 0, 0);
            func_0033d4e0(*(void **)(work + j * 4 + 0x2C), 0.7f, 1.0f, 0, 5, layer1);
            func_0033d4b0(*(void **)(work + j * 4 + 0x2C), 0, 0xFF, 0, 5, layer1);
            func_0033d3c0(*(void **)(work + j * 4 + 0x2C), (f32)(j + 0x1A));
            func_0033d3d0(*(void **)(work + j * 4 + 0x2C), 0x63);
            rowFont = func_0046d200(*(void **)(work + 0xC), listIndex);
            func_0033d3e0(*(void **)(work + j * 4 + 0x2C),
                          func_002b2970((func_0046b260(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (func_0046b2f0(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          func_002b2970(coords[0], coords[1]), 0, 5, layer1);
            func_0046d280(rowFont);
        }
        func_0033d320(*(void **)(work + 0x18), 0, 0);
        func_0033d4b0(*(void **)(work + 0x18), 0, 0xFF, 0, 0x14, 0xA);
        func_0033d3c0(*(void **)(work + 0x18), 21.0f);
        func_0033d3d0(*(void **)(work + 0x18), 0x64);
        tbl = (F2_0033 *)D_0064A208;
        func_0033d320(*(void **)(work + 0xCC), 0, 0);
        func_0033d3e0(*(void **)(work + 0xCC), func_002b2970(660.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xCC), 68.0f);
        func_0033d3d0(*(void **)(work + 0xCC), 0x5B);
        tbl = (F2_0033 *)D_0064A210;
        func_0033d320(*(void **)(work + 0xD0), 0, 0);
        func_0033d3e0(*(void **)(work + 0xD0), func_002b2970(1064.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xD0), 60.0f);
        func_0033d3d0(*(void **)(work + 0xD0), 0x5B);
        tbl = (F2_0033 *)D_0064A218;
        func_0033d320(*(void **)(work + 0xD4), 0, 0);
        func_0033d3e0(*(void **)(work + 0xD4), func_002b2970(1064.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xD4), 59.0f);
        func_0033d3d0(*(void **)(work + 0xD4), 0x5B);
        func_0033d320(*(void **)(work + 0x150), 0, 0);
        func_0033d4b0(*(void **)(work + 0x150), 0, 0xFF, 0, 0, 0xA);
        func_0033d3c0(*(void **)(work + 0x150), 56.0f);
        func_0033d3d0(*(void **)(work + 0x150), 0x5B);
        func_0033d320(*(void **)(work + 0x198), 0, 0);
        func_0033d4b0(*(void **)(work + 0x198), 0, 0xFF, 0, 0, 0xA);
        func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x198), 57.0f);
        *(u16 *)(func_0033d310(*(void **)(work + 0x198)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) % 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x198), 0x5B);
        *(FclDrawColor *)(func_0033d310(*(void **)(work + 0x198)) + 0x79) = func_002b2a60(0x7E, 0, 8, 0xFF);
        func_0033d320(*(void **)(work + 0x19C), 0, 0);
        func_0033d4b0(*(void **)(work + 0x19C), 0, 0xFF, 0, 0, 0xA);
        func_0033d3e0(*(void **)(work + 0x19C), func_002b2970(552.0f, 185.0f), func_002b2970(552.0f, 185.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x19C), 57.0f);
        *(u16 *)(func_0033d310(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x19C), 0x5B);
        *(FclDrawColor *)(func_0033d310(*(void **)(work + 0x19C)) + 0x79) = func_002b2a60(0x7E, 0, 8, 0xFF);
        if ((u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 == 0) {
            func_0033d320(*(void **)(work + 0x19C), 0, 1);
            func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0, 0, 0);
        }
        for (j = 0; j < 4; j++) {
            func_0033d320(*(void **)(work + j * 4 + 0x64), 0, 0);
            func_0033d4b0(*(void **)(work + j * 4 + 0x64), 0, 0xFF, 0, 0xA, 0x19);
            func_0033d3c0(*(void **)(work + j * 4 + 0x64), 15.0f);
            func_0033d3d0(*(void **)(work + j * 4 + 0x64), 0x64);
        }
        func_0033d320(*(void **)(work + 0x70), 0, 1);
        tbl = (F2_0033 *)D_0064A228;
        func_0033d320(*(void **)(work + 0xDC), 0, 1);
        func_0033d3e0(*(void **)(work + 0xDC), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xDC), 66.0f);
        func_0033d3d0(*(void **)(work + 0xDC), 0x5B);
        tbl = (F2_0033 *)D_0064A230;
        func_0033d320(*(void **)(work + 0xE0), 0, 1);
        func_0033d3e0(*(void **)(work + 0xE0), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xE0), 67.0f);
        func_0033d3d0(*(void **)(work + 0xE0), 0x5B);
        tbl = (F2_0033 *)D_0064A220;
        func_0033d320(*(void **)(work + 0xD8), 0, 1);
        func_0033d3e0(*(void **)(work + 0xD8), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xD8), 61.0f);
        func_0033d3d0(*(void **)(work + 0xD8), 0x5B);
        if (*(s8 *)(work + 0x424) == 1) {
            capFont = func_0046d200(*(void **)(work + 0xC), 0x51);
            tbl = (F2_0033 *)D_0064A318;
            func_0033d320(*(void **)(work + 0x154), 0, 0);
            func_0033d3e0(*(void **)(work + 0x154), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
            func_0033d520(*(u8 **)(work + 0x154), -90.0f, 0.0f, 0, 7, 0xA);
            func_0033d3c0(*(void **)(work + 0x154), 40.0f);
            func_0033d3d0(*(void **)(work + 0x154), 0x62);
            *(s16 *)(func_0033d310(*(void **)(work + 0x154)) + 0x100) = 0;
            *(s16 *)(func_0033d310(*(void **)(work + 0x154)) + 0x102) = func_0046b2f0(capFont);
            func_0046d280(capFont);
        }
        if (*(s8 *)(work + 9) == 1) {
            tbl = (F2_0033 *)D_0064A340;
            func_0033d320(*(void **)(work + 0x168), 0, 0);
            func_0033d3e0(*(void **)(work + 0x168), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
            func_0033d520(*(u8 **)(work + 0x168), 150.0f, 0.0f, 0, 0xA, 0x1B);
            *(s16 *)(func_0033d310(*(void **)(work + 0x168)) + 0x100) = 0x231 - tbl->x;
            *(s16 *)(func_0033d310(*(void **)(work + 0x168)) + 0x102) = 470.0f - tbl->y;
            func_0033d3c0(*(void **)(work + 0x168), 24.0f);
            func_0033d3d0(*(void **)(work + 0x168), 0x63);
            tbl = (F2_0033 *)D_0064A348;
            func_0033d320(*(void **)(work + 0x16C), 0, 0);
            func_0033d3e0(*(void **)(work + 0x16C), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0, 0, 0);
            func_0033d4b0(*(void **)(work + 0x16C), 0xFF, 0x33, 0, 0x14, 0x34);
            func_0033d4e0(*(void **)(work + 0x16C), 0.0f, 1.0f, 0, 0, 0x25);
            *(f32 *)(func_0033d310(*(void **)(work + 0x16C)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x16C), 23.0f);
            func_0033d3d0(*(void **)(work + 0x16C), 0x63);
            labelFont = func_0046d200(*(void **)(work + 0xC), 0x58);
            tbl = (F2_0033 *)D_0064A350;
            func_0033d320(*(void **)(work + 0x170), 0, 0);
            func_0033d3e0(*(void **)(work + 0x170),
                          func_002b2970(tbl->x + func_0046b260(labelFont) / 2.0f, tbl->y + func_0046b2f0(labelFont) / 2.0f),
                          func_002b2970(tbl->x - 4.0f, tbl->y - 3.0f), 0, 5, 0x23);
            func_0033d4e0(*(void **)(work + 0x170), 0.0f, 1.05f, 2, 5, 0x23);
            func_0033d4b0(*(void **)(work + 0x170), 0, 0xFF, 0, 0, 0x23);
            *(f32 *)(func_0033d310(*(void **)(work + 0x170)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x170), 22.0f);
            func_0033d3d0(*(void **)(work + 0x170), 0x63);
            func_0046d280(labelFont);
            tbl = (F2_0033 *)D_0064A358;
            func_0033d320(*(void **)(work + 0x174), 0, 0);
            func_0033d420(*(u8 **)(work + 0x174), func_002b2970(0x113 + tbl->x, tbl->y),
                          func_002b2970(tbl->x, tbl->y - 120.0f), 1, 0, 0xE, 0x20);
            *(f32 *)(func_0033d310(*(void **)(work + 0x174)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x174), 9.0f);
            func_0033d3d0(*(void **)(work + 0x174), 0x64);
        }
        *(s8 *)(work + 2) = 0;
        *(s8 *)(work + 0) = 0xA;
        break;
    case 8:
        break;
    case 10:
        if (func_0033d390(*(void **)(work + 0x170), 4) == 0) {
            func_0033d4e0(*(void **)(work + 0x170), 0.0f, 1.0f, 0, 0, 0);
        }
        if (func_0033d390(*(void **)(work + 0x188), 4) != 0) {
            break;
        }
        func_0033d3d0(*(void **)(work + 0xB0), 0x5B);
        for (j = 0; j < 3; j++) {
            func_0033d3d0(*(void **)(work + j * 4 + 0x17C), 0x5B);
        }
        for (j = 0; j < 4; j++) {
            func_0033d320(*(void **)((work + j * 4) + 0x188), 0, 1);
            func_0033d320(*(void **)((work + j * 4) + 0x17C), 0, 1);
        }
        func_0033d320(*(void **)(work + 0xB0), 0, 1);
        *(s32 *)(work + 0x2B0) = 0;
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        *(s8 *)(work + 0) = 0xB;
        break;
    case 11:
        *(s8 *)(work + 3) = 1;
        if (func_0033d390(*(void **)(work + 0x170), 4) == 0) {
            tbl = (F2_0033 *)D_0064A350;
            *(F2_0033 *)(func_0033d310(*(void **)(work + 0x170)) + 0x2C) = func_002b2970(tbl->x, tbl->y);
            *(f32 *)(func_0033d310(*(void **)(work + 0x170)) + 0x94) = 1.0f;
            *(f32 *)(func_0033d310(*(void **)(work + 0x170)) + 0xA0) = 1.0f;
        }
        for (j = 0; j < 0x24; j++) {
            *(u8 *)(work + j + 0x2B4) = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + j + 0x2D8) == 1) {
                *(f32 *)(work + j * 4 + 0x2FC) = func_0033d630(func_002b2970(400.0f, 220.0f), (s16)(j * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + j + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        if (func_0033d390(*(void **)(work + 0xCC), 1) == 0) {
            func_002caa10(func_002b2970(0x253, 78.0f), 1.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF),
                          func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))), 0x35, *(void **)(work + 0xC), 0xAB);
            func_0033c490(arg0);
            tbl = (F2_0033 *)D_0064A218;
            *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30) =
                (f32)(*(s16 *)(work + 4) - *(s16 *)(work + 6)) * *(f32 *)(work + 0x420) + tbl->y + 0.0f;
        }
        *(u16 *)(func_0033d310(*(void **)(work + 0x198)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) % 10 + 0x46;
        func_0033d320(*(void **)(work + 0x19C), 0, 0);
        *(u16 *)(func_0033d310(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 + 0x46;
        if ((u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 == 0) {
            func_0033d320(*(void **)(work + 0x19C), 0, 1);
            func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0, 0, 0);
        }
        if (func_0033d390(*(void **)(work + 0x158), 1) != 0 || func_0033d390(*(void **)(work + 0x158), 4) != 0 ||
            func_0033d390(*(void **)(work + 0xC8), 1) != 0 || func_0033d390(*(void **)(work + 0xC0), 1) != 0 ||
            func_0033d390(*(void **)(work + 0xC4), 1) != 0 || func_0033d390(*(void **)(work + 0x2C), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x30), 4) != 0 || func_0033d390(*(void **)(work + 0x34), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x38), 4) != 0 || func_0033d390(*(void **)(work + 0x18), 2) != 0 ||
            func_0033d390(*(void **)(work + 0xCC), 1) != 0 || func_0033d390(*(void **)(work + 0xD0), 1) != 0 ||
            func_0033d390(*(void **)(work + 0xD4), 1) != 0 || func_0033d390(*(void **)(work + 0x150), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x198), 2) != 0 || func_0033d390(*(void **)(work + 0x19C), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x64), 2) != 0 || func_0033d390(*(void **)(work + 0x68), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x6C), 2) != 0 || func_0033d390(*(void **)(work + 0x70), 2) != 0) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && *(s8 *)(work + 0x425) == 0) {
            func_0045af60(0, 0, 0, 0);
            if (*(s16 *)(work + 4) == 0) {
                *(s16 *)(work + 4) = func_002e26a0();
                *(s16 *)(work + 6) = func_002b2cb0(0, *(s16 *)(work + 4), 4, 0, 1);
            } else {
                *(s16 *)(work + 4) = func_002b2d00(*(s16 *)(work + 4), 1, 0, (s16)func_002e2670(), 2);
                *(s16 *)(work + 6) =
                    func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e2670(), 5, -1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s16 *)(work + 4) != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = func_002b2d00(*(s16 *)(work + 4), 1, 0, 0, 1);
            *(s16 *)(work + 6) = func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e2670(), 5, -1);
            *(s8 *)(work + 0x425) = 1;
        } else if ((D_008C0276[0] & 0x4000) && *(s8 *)(work + 0x425) == 0) {
            func_0045af60(0, 0, 0, 0);
            *(s16 *)(work + 4) = func_002b2cb0(*(s16 *)(work + 4), 1, func_002e26a0(), 0, 2);
            if (*(s16 *)(work + 4) == 0) {
                *(s16 *)(work + 6) = 0;
            } else if (func_002e26a0() >= 5) {
                *(s16 *)(work + 6) = func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e26a0(), 5, 1);
            } else {
                *(s16 *)(work + 6) = func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e26a0(),
                                                   (s16)func_002e2670(), 1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s16 *)(work + 4) != func_002e26a0()) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = func_002b2cb0(*(s16 *)(work + 4), 1, func_002e26a0(), 0, 1);
            if (func_002e26a0() >= 5) {
                *(s16 *)(work + 6) = func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e26a0(), 5, 1);
            } else {
                *(s16 *)(work + 6) = func_002b2d50(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)func_002e26a0(),
                                                   (s16)func_002e2670(), 1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else {
            if ((D_008C027A[0] & 8) || (D_008C027A[0] & 0x2000)) {
                if (*(s16 *)(work + 4) != func_002e26a0()) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2e70(*(s16 *)(work + 4), *(s16 *)(work + 6), func_002e2670(), 5, work + 4, work + 6);
            } else if ((D_008C027A[0] & 4) || (D_008C027A[0] & 0x8000)) {
                if (*(s16 *)(work + 4) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_002b2f90(*(s16 *)(work + 4), *(s16 *)(work + 6), func_002e2670(), 5, work + 4, work + 6);
            } else if (D_008C024E[0] & 0x40) {
                if (func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))) <= func_002e7a60() &&
                    (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) < 0x63) {
                    tbl = (F2_0033 *)D_0064A210;
                    func_0033d3e0(*(void **)(work + 0xD0),
                                  func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                                  func_002b2970(tbl->x - 0x193, tbl->y), 0, 7, 0);
                    tbl = (F2_0033 *)D_0064A218;
                    func_0033d3e0(*(void **)(work + 0xD4),
                                  func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x2C),
                                                *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)),
                                  func_002b2970(tbl->x - 0x193, *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)),
                                  0, 7, 0);
                    tbl = (F2_0033 *)D_0064A328;
                    func_0033d320(*(void **)(work + 0x15C), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x15C), func_002b2970(tbl->x, tbl->y),
                                  func_002b2970(tbl->x, tbl->y - 7.0f), 1, 0xA, 7);
                    func_0033d4b0(*(void **)(work + 0x15C), 0, 0xFF, 0, 0xA, 7);
                    func_0033d3c0(*(void **)(work + 0x15C), 54.0f);
                    func_0033d3d0(*(void **)(work + 0x15C), 0x5B);
                    *(s8 *)(func_0033d310(*(void **)(work + 0x15C)) + 0x3B) = 1;
                    tbl = (F2_0033 *)D_0064A330;
                    func_0033d320(*(void **)(work + 0x160), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x160), func_002b2970(tbl->x, tbl->y),
                                  func_002b2970(tbl->x, 7.0f + tbl->y), 1, 0xA, 7);
                    func_0033d4b0(*(void **)(work + 0x160), 0, 0xFF, 0, 0xA, 7);
                    func_0033d3c0(*(void **)(work + 0x160), 55.0f);
                    func_0033d3d0(*(void **)(work + 0x160), 0x5B);
                    *(s8 *)(func_0033d310(*(void **)(work + 0x160)) + 0x3B) = 1;
                    *(s8 *)(work + 0) = 0xC;
                    *(s8 *)(work + 3) = 1;
                    func_0045af60(0, 0, 0, 1);
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (D_008C024E[0] & 0x80) {
                if (*(s8 *)(work + 2) == 0) {
                    func_0045af60(0, 1, 0, 3);
                }
                if (*(s8 *)(work + 2) == 1) {
                    func_0045af60(0, 1, 0, 4);
                }
                *(s8 *)(work + 2) ^= 1;
            } else if (D_008C024E[0] & 0x20) {
                if (*(s8 *)(work + 2) == 1) {
                    *(s8 *)(work + 2) = 0;
                    func_0045af60(0, 1, 0, 4);
                } else {
                    func_0045af60(0, 0, 0, 2);
                    tbl = (F2_0033 *)D_0064A320;
                    func_0033d320(*(void **)(work + 0x158), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x158), 0xFF, 0, 0, 5, 0);
                    func_0033d4e0(*(void **)(work + 0x158), 1.0f, 0.6f, 0, 5, 0);
                    func_0033d3c0(*(void **)(work + 0x158), 45.0f);
                    cardFont = func_0046d200(*(void **)(work + 0xC), 0x52);
                    func_0033d3e0(*(void **)(work + 0x158), func_002b2970(tbl->x, tbl->y),
                                  func_002b2970((func_0046b260(cardFont) / 10.0f) * 2.0f + tbl->x + 0.0f,
                                                (func_0046b2f0(cardFont) / 10.0f) * 2.0f + tbl->y + 0.0f),
                                  0, 5, 0);
                    func_0046d280(cardFont);
                    tbl = (F2_0033 *)D_0064A200;
                    func_0033d320(*(void **)(work + 0xC8), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xC8), func_002b2970(tbl->x, tbl->y), func_002b2970(660.0f, tbl->y), 0,
                                  0xF, 0);
                    func_0033d3c0(*(void **)(work + 0xC8), 42.0f);
                    tbl = (F2_0033 *)D_0064A1F0;
                    func_0033d320(*(void **)(work + 0xC0), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xC0), func_002b2970(tbl->x, tbl->y), func_002b2970(660.0f, tbl->y), 0,
                                  0xC, 0);
                    func_0033d3c0(*(void **)(work + 0xC0), 43.0f);
                    tbl = (F2_0033 *)D_0064A1F8;
                    func_0033d320(*(void **)(work + 0xC4), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xC4), func_002b2970(tbl->x, tbl->y),
                                  func_002b2970(320.0f + tbl->x, tbl->y), 0, 0xC, 0);
                    func_0033d3c0(*(void **)(work + 0xC4), 44.0f);
                    for (j = 0; j < 4; j++) {
                        layer2 = (s16)(j * 2);
                        cardIndex = j + 7;
                        coords = (f32 *)((u8 *)D_0064A090 + cardIndex * 8);
                        func_0033d4e0(*(void **)(work + j * 4 + 0x2C), 1.0f, 0.7f, 0, 4, layer2);
                        func_0033d4b0(*(void **)(work + j * 4 + 0x2C), 0xFF, 0, 0, 4, layer2);
                        func_0033d3c0(*(void **)(work + j * 4 + 0x2C), (f32)(j + 0x1A));
                        font = func_0046d200(*(void **)(work + 0xC), cardIndex);
                        func_0033d3e0(*(void **)(work + j * 4 + 0x2C), func_002b2970(coords[0], coords[1]),
                                      func_002b2970((func_0046b260(font) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (func_0046b2f0(font) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      0, 4, layer2);
                        func_0046d280(font);
                    }
                    func_0033d320(*(void **)(work + 0x18), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x18), 0xFF, 0, 0, 5, 0);
                    func_0033d3c0(*(void **)(work + 0x18), 21.0f);
                    tbl = (F2_0033 *)D_0064A208;
                    func_0033d320(*(void **)(work + 0xCC), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xCC), func_002b2970(tbl->x, tbl->y), func_002b2970(660.0f, tbl->y), 0,
                                  0xA, 0);
                    func_0033d3c0(*(void **)(work + 0xCC), 68.0f);
                    tbl = (F2_0033 *)D_0064A210;
                    func_0033d320(*(void **)(work + 0xD0), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xD0), func_002b2970(tbl->x, tbl->y), func_002b2970(1064.0f, tbl->y), 0,
                                  0xA, 0);
                    func_0033d3c0(*(void **)(work + 0xD0), 60.0f);
                    tbl = (F2_0033 *)D_0064A218;
                    func_0033d320(*(void **)(work + 0xD4), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xD4),
                                  func_002b2970(tbl->x, *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)),
                                  func_002b2970(1064.0f, *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)), 0, 0xA,
                                  0);
                    func_0033d3c0(*(void **)(work + 0xD4), 59.0f);
                    func_0033d4b0(*(void **)(work + 0x150), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x150), 56.0f);
                    func_0033d320(*(void **)(work + 0x198), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0,
                                  0, 0);
                    func_0033d4b0(*(void **)(work + 0x198), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x198), 57.0f);
                    *(u16 *)(func_0033d310(*(void **)(work + 0x198)) + 0xF8) =
                        (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) % 10 + 0x46;
                    func_0033d320(*(void **)(work + 0x19C), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x19C), func_002b2970(552.0f, 185.0f), func_002b2970(552.0f, 185.0f), 0,
                                  0, 0);
                    func_0033d4b0(*(void **)(work + 0x19C), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x19C), 57.0f);
                    *(u16 *)(func_0033d310(*(void **)(work + 0x19C)) + 0xF8) =
                        (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 + 0x46;
                    if ((u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 == 0) {
                        func_0033d320(*(void **)(work + 0x19C), 0, 1);
                        func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f),
                                      func_002b2970(0x243, 185.0f), 0, 0, 0);
                    }
                    for (j = 0; j < 4; j++) {
                        func_0033d4b0(*(void **)(work + j * 4 + 0x64), 0xFF, 0, 0, 5, 0);
                        func_0033d3c0(*(void **)(work + j * 4 + 0x64), 15.0f);
                    }
                    if (*(s8 *)(work + 2) == 1) {
                        tbl = (F2_0033 *)D_0064A228;
                        func_0033d3e0(*(void **)(work + 0xDC), func_002b2970(tbl->x, tbl->y), func_002b2970(0x2A3, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A230;
                        func_0033d3e0(*(void **)(work + 0xE0), func_002b2970(tbl->x, tbl->y), func_002b2970(0x413, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A220;
                        func_0033d3e0(*(void **)(work + 0xD8), func_002b2970(tbl->x, tbl->y), func_002b2970(0x2AD, tbl->y),
                                      0, 0xA, 0);
                    }
                    func_0033d320(*(void **)(work + 0x120), 0, 1);
                    func_0033d320(*(void **)(work + 0x124), 0, 1);
                    if (*(s8 *)(work + 0x424) == 1) {
                        func_0033d520(*(u8 **)(work + 0x154), 0.0f, 180.0f, 0, 7, 0);
                    }
                    if (*(s8 *)(work + 9) == 1) {
                        func_0033d520(*(u8 **)(work + 0x168), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A348;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x16C)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x16C)) + 0x102) = 470.0f - tbl->y;
                        func_0033d520(*(u8 **)(work + 0x16C), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A350;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x170)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x170)) + 0x102) = 470.0f - tbl->y;
                        func_0033d520(*(u8 **)(work + 0x170), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A358;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x174)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(func_0033d310(*(void **)(work + 0x174)) + 0x102) = 470.0f - tbl->y;
                        func_0033d520(*(u8 **)(work + 0x174), 0.0f, -30.0f, 0, 2, 0);
                        func_0033d420(*(u8 **)(work + 0x174), *(F2_0033 *)(func_0033d310(*(void **)(work + 0x174)) + 0x2C),
                                      func_002b2970(-300.0f + tbl->x, 250.0f + tbl->y), 0, 2, 0x14, 1);
                    }
                    *(s32 *)(work + 0x2B0) = 0;
                    func_0033d320(*(void **)(work + 0x10), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x10), func_002b2970(428.0f, 241.0f),
                                  func_002b2970(D_0064A090[0], D_0064A090[1]), 0, 0xF, 5);
                    func_0033d520(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0xF, 5);
                    tbl = (F2_0033 *)D_0064A1D8;
                    func_0033d320(*(void **)(work + 0xB4), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xB4), func_002b2970(-180.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 0,
                                  0xF, 0xC);
                    func_0033d3c0(*(void **)(work + 0xB4), 47.0f);
                    tbl = (F2_0033 *)D_0064A1E0;
                    func_0033d320(*(void **)(work + 0xB8), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xB8), func_002b2970(-200.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 1,
                                  9, 0xC);
                    func_0033d3c0(*(void **)(work + 0xB8), 33.0f);
                    tbl = (F2_0033 *)D_0064A1E8;
                    func_0033d320(*(void **)(work + 0xBC), 0, 0);
                    func_0033d3e0(*(void **)(work + 0xBC), func_002b2970(-50.0f, tbl->y), func_002b2970(153.0f, tbl->y), 0,
                                  0xF, 0x18);
                    func_0033d3c0(*(void **)(work + 0xBC), 48.0f);
                    func_0033d320(*(void **)(work + 0x178), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x178), func_002b2970(-50.0f, tbl->y), func_002b2970(203.0f, tbl->y), 0,
                                  0xF, 0x18);
                    func_0033d3c0(*(void **)(work + 0x178), 48.0f);
                    tbl = (F2_0033 *)D_0064A0E8;
                    func_0033d320(*(void **)(work + 0x3C), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x3C), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y), 0,
                                  0, 0);
                    func_0033d4b0(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xF, 0x25);
                    func_0033d3c0(*(void **)(work + 0x3C), 46.0f);
                    tbl = (F2_0033 *)D_0064A290;
                    func_0033d320(*(void **)(work + 0x110), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x110), func_002b2970(660.0f, tbl->y), func_002b2970(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    func_0033d3c0(*(void **)(work + 0x110), 17.0f);
                    tbl = (F2_0033 *)D_0064A298;
                    func_0033d320(*(void **)(work + 0x114), 0, 0);
                    func_0033d3e0(*(void **)(work + 0x114), func_002b2970(0x305, tbl->y), func_002b2970(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    func_0033d3c0(*(void **)(work + 0x114), 17.0f);
                    for (i16 = 0; i16 < 4; i16++) {
                        layer3 = (s16)(i16 * 3 + 0x14);
                        index = i16 + 3;
                        coords = (f32 *)((u8 *)D_0064A090 + index * 8);
                        func_0033d320(*(void **)(work + i16 * 4 + 0x1C), 0, 0);
                        func_0033d4e0(*(void **)(work + i16 * 4 + 0x1C), 0.7f, 1.0f, 0, 4, layer3);
                        func_0033d4b0(*(void **)(work + i16 * 4 + 0x1C), 0, 0xFF, 0, 4, layer3);
                        func_0033d4b0(*(void **)(work + i16 * 4 + 0x1C), 0, 0xFF, 0, 0, layer3);
                        func_0033d3c0(*(void **)(work + i16 * 4 + 0x1C), (f32)(i16 + 0x1A));
                        iconFont = func_0046d200(*(void **)(work + 0xC), index);
                        func_0033d3e0(*(void **)(work + i16 * 4 + 0x1C),
                                      func_002b2970((func_0046b260(iconFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (func_0046b2f0(iconFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      func_002b2970(coords[0], coords[1]), 0, 4, layer3);
                        func_0046d280(iconFont);
                    }
                    func_0033d320(*(void **)(work + 0x14), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x14), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x14), 30.0f);
                    func_0033d320(*(void **)(work + 0xB0), 0, 0);
                    func_0033d4b0(*(void **)(work + 0xB0), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d4e0(*(void **)(work + 0xB0), 0.35f, 1.0f, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0xB0), 52.0f);
                    for (i32 = 0; i32 < 3; i32++) {
                        func_0033d320(*(void **)(work + i32 * 4 + 0x17C), 0, 0);
                        func_0033d4b0(*(void **)(work + i32 * 4 + 0x17C), 0, 0xFF, 0, 0xA, 0x14);
                        func_0033d4e0(*(void **)(work + i32 * 4 + 0x17C), 0.35f, 1.0f, 0, 0xA, 0x14);
                        func_0033d3c0(*(void **)(work + i32 * 4 + 0x17C), (f32)(i32 + 0x31));
                    }
                    func_0033d320(*(void **)(work + 0x58), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x58), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x58), 80.0f);
                    func_0033d320(*(void **)(work + 0x5C), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x5C), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
                    tbl = (F2_0033 *)D_0064A2A0;
                    func_0033d320(*(void **)(work + 0x118), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x118), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x118), 82.0f);
                    func_0033d3e0(*(void **)(work + 0x118), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                                  func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
                    tbl = (F2_0033 *)D_0064A2A8;
                    func_0033d320(*(void **)(work + 0x11C), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x11C), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
                    func_0033d3e0(*(void **)(work + 0x11C), func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                                  func_002b2970(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
                    for (j = 0; j < 6; j++) {
                        func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
                        func_0033d4b0(*(void **)(work + j * 4 + 0x40), 0, 0xFF, 0, 0xA, 0x14);
                        func_0033d3c0(*(void **)(work + j * 4 + 0x40), (f32)(j + 0x4A));
                    }
                    func_0033d320(*(void **)(work + 0x4C), 0, 0);
                    func_0033d320(*(void **)(work + 0x44), 0, 0);
                    func_0033d320(*(void **)(work + 0x48), 0, 0);
                    func_0033d320(*(void **)(work + 0x60), 0, 0);
                    func_0033d4b0(*(void **)(work + 0x60), 0, 0xFF, 0, 0xF, 0x14);
                    func_0033d3c0(*(void **)(work + 0x60), 14.0f);
                    *(s8 *)(work + 0) = 0xE;
                }
            }
            *(s8 *)(work + 0x425) = 0;
        }
        break;
    case 12:
        for (j = 0; j < 0x24; j++) {
            *(u8 *)(work + j + 0x2B4) = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + j + 0x2D8) == 1) {
                *(f32 *)(work + j * 4 + 0x2FC) = func_0033d630(func_002b2970(400.0f, 220.0f), (s16)(j * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + j + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        func_002caa10(func_002b2970(0x253, 78.0f), 1.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF),
                      *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))), 0x35,
                      *(void **)(work + 0xC), 0xAB);
        func_0033c490(arg0);
        *(u16 *)(func_0033d310(*(void **)(work + 0x198)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) % 10 + 0x46;
        func_0033d320(*(void **)(work + 0x19C), 0, 0);
        *(u16 *)(func_0033d310(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 + 0x46;
        if ((u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 == 0) {
            func_0033d320(*(void **)(work + 0x19C), 0, 1);
            func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0, 0, 0);
        }
        if (func_0033d390(*(void **)(work + 0xD0), 1) != 0) {
            break;
        }
        func_0033d320(*(void **)(work + 0x1A0), 0, 0);
        func_0033d3e0(*(void **)(work + 0x1A0), func_002b2970(0x167, 134.0f), func_002b2970(0x167, 134.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x1A0), 57.0f);
        *(u16 *)(func_0033d310(*(void **)(work + 0x1A0)) + 0xF8) = *(s8 *)(work + 3) % 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x1A0), 0x61);
        func_0033d320(*(void **)(work + 0x1A4), 0, 0);
        func_0033d3e0(*(void **)(work + 0x1A4), func_002b2970(332.0f, 134.0f), func_002b2970(332.0f, 134.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x1A4), 57.0f);
        *(u16 *)(func_0033d310(*(void **)(work + 0x1A4)) + 0xF8) = *(s8 *)(work + 3) / 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x1A4), 0x61);
        if (*(s8 *)(work + 3) / 10 == 0) {
            func_0033d320(*(void **)(work + 0x1A4), 0, 1);
            func_0033d3e0(*(void **)(work + 0x1A0), func_002b2970(346.0f, 134.0f), func_002b2970(346.0f, 134.0f), 0, 0, 0);
        }
        func_0033d320(*(void **)(work + 0xA0), 0, 0);
        func_0033d3e0(*(void **)(work + 0xA0), func_002b2970(45.0f, 133.0f), func_002b2970(45.0f, 133.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xA0), 53.0f);
        func_0033d3d0(*(void **)(work + 0xA0), 0x61);
        func_00275520(82.0f, 132.0f, 58.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      func_001067f0((s16)func_002e2740(*(s16 *)(work + 4))), 0, 0, D_007950B0);
        if (D_008C024E[0] & 0x40) {
            func_0045af60(0, 0, 0, 1);
            *(s8 *)(work + 8) = func_002bab80(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            sprintf(buf, "%d", *(s8 *)(work + 3));
            func_002bbd80(*(s8 *)(work + 8), 1, buf);
            sprintf(buf, "%d", *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))));
            func_002bbd80(*(s8 *)(work + 8), 2, buf);
            func_002badc0(*(s8 *)(work + 8), 1);
            func_002bafc0(*(s8 *)(work + 8), 0);
            func_002bb0a0(*(s8 *)(work + 8), 0);
            func_002bbf60();
            *(s8 *)(work + 0) = 0xD;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))))) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = func_002b2cb0(*(s8 *)(work + 3), 1,
                                              (s16)(0x63 - (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4)))), 0, 1);
            if (*(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))) > func_002e7a60()) {
                *(s8 *)(work + 3) = func_002e7a60() / func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4)));
            }
            tbl = (F2_0033 *)D_0064A328;
            func_0033d3e0(*(void **)(work + 0x15C), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s8 *)(work + 3) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = func_002b2d00(*(s8 *)(work + 3), 1, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            func_0033d3e0(*(void **)(work + 0x160), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))))) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = func_002b2cb0(*(s8 *)(work + 3), 0xA,
                                              (s16)(0x63 - (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4)))), 0, 1);
            if (*(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))) > func_002e7a60()) {
                *(s8 *)(work + 3) = func_002e7a60() / func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4)));
            }
            tbl = (F2_0033 *)D_0064A328;
            func_0033d3e0(*(void **)(work + 0x15C), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s8 *)(work + 3) != 1) {
                func_0045af60(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = func_002b2d00(*(s8 *)(work + 3), 0xA, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            func_0033d3e0(*(void **)(work + 0x160), func_002b2970(tbl->x, tbl->y), func_002b2970(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C024E[0] & 0x20) {
            func_0045af60(0, 0, 0, 2);
            tbl = (F2_0033 *)D_0064A210;
            func_0033d3e0(*(void **)(work + 0xD0),
                          func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                          func_002b2970(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            func_0033d3e0(*(void **)(work + 0xD4),
                          func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x2C),
                                        *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)),
                          func_002b2970(tbl->x, *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)), 0, 7, 0);
            *(s8 *)(work + 0) = 0xB;
            func_0033d320(*(void **)(work + 0x15C), 0, 1);
            func_0033d320(*(void **)(work + 0x160), 0, 1);
            func_0033d320(*(void **)(work + 0x1A0), 0, 1);
            func_0033d320(*(void **)(work + 0x1A4), 0, 1);
            func_0033d320(*(void **)(work + 0xA0), 0, 1);
        }
        break;
    case 13:
        for (i34 = 0; i34 < 0x24; i34++) {
            *(u8 *)(work + i34 + 0x2B4) = func_002b2aa0(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + i34 + 0x2D8) == 1) {
                *(f32 *)(work + i34 * 4 + 0x2FC) = func_0033d630(func_002b2970(400.0f, 220.0f), (s16)(i34 * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + i34 + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        func_002caa10(func_002b2970(0x253, 78.0f), 1.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF),
                      *(s8 *)(work + 3) * func_0033cbc0(arg0, func_002e2740(*(s16 *)(work + 4))), 0x35,
                      *(void **)(work + 0xC), 0xAB);
        func_0033c490(arg0);
        func_00275520(82.0f, 132.0f, 58.0f, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      func_001067f0((s16)func_002e2740(*(s16 *)(work + 4))), 0, 0, D_00795E60);
        if (func_002bb680(*(s8 *)(work + 8)) != 0) {
            func_002bbcf0(*(s8 *)(work + 8));
            break;
        }
        *(s8 *)(work + 0) = 0xC;
        if (!func_002bb1c0(*(s8 *)(work + 8))) {
            func_00106620((s16)func_002e2740(*(s16 *)(work + 4)),
                          (u8)(*(s8 *)(work + 3) + (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4)))));
            func_002e7a80(func_002e7a60() -
                          *(s8 *)(work + 3) * func_0033cbc0(arg0, (s16)func_002e2740(*(s16 *)(work + 4))));
            *(f32 *)(work + 0x1E0) = 580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()) + 0.0f;
            *(u16 *)(func_0033d310(*(void **)(work + 0x198)) + 0xF8) =
                (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) % 10 + 0x46;
            func_0033d320(*(void **)(work + 0x19C), 0, 0);
            *(u16 *)(func_0033d310(*(void **)(work + 0x19C)) + 0xF8) =
                (u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 + 0x46;
            if ((u8)func_00106600((s16)func_002e2740(*(s16 *)(work + 4))) / 10 == 0) {
                func_0033d320(*(void **)(work + 0x19C), 0, 1);
                func_0033d3e0(*(void **)(work + 0x198), func_002b2970(0x243, 185.0f), func_002b2970(0x243, 185.0f), 0, 0,
                              0);
            }
            tbl = (F2_0033 *)D_0064A210;
            func_0033d3e0(*(void **)(work + 0xD0),
                          func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                          func_002b2970(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            func_0033d3e0(*(void **)(work + 0xD4),
                          func_002b2970(*(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x2C),
                                        *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)),
                          func_002b2970(tbl->x, *(f32 *)(func_0033d310(*(void **)(work + 0xD4)) + 0x30)), 0, 7, 0);
            *(s8 *)(work + 0) = 0xB;
            func_0033d320(*(void **)(work + 0x15C), 0, 1);
            func_0033d320(*(void **)(work + 0x160), 0, 1);
            func_0033d320(*(void **)(work + 0x1A0), 0, 1);
            func_0033d320(*(void **)(work + 0x1A4), 0, 1);
            func_0033d320(*(void **)(work + 0xA0), 0, 1);
            func_0045af60(0, 0, 0, 6);
        }
        func_002bb550(*(s8 *)(work + 8));
        break;
    case 14:
        for (i35 = 0; i35 < 0x24; i35++) {
            *(u8 *)(work + i35 + 0x2B4) = func_002b2aa0(0, 255.0f, 0.0f, (f32)*(s32 *)(work + 0x2B0), 5.0f);
            if (*(s8 *)(work + i35 + 0x2D8) == 1) {
                *(f32 *)(work + i35 * 4 + 0x2FC) = func_0033d630(func_002b2970(400.0f, 220.0f), (s16)(i35 * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + i35 + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = func_002b2aa0(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = func_002b2cb0(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = func_002b2cb0(*(s32 *)(work + 0x2B0), 1, 5, 1, 1);
        if (func_0033d390(*(void **)(work + 0x10), 1) == 0 && func_0033d390(*(void **)(work + 0x10), 3) == 0 &&
            func_0033d390(*(void **)(work + 0xB4), 1) == 0 && func_0033d390(*(void **)(work + 0xB8), 1) == 0 &&
            func_0033d390(*(void **)(work + 0x110), 1) == 0 && func_0033d390(*(void **)(work + 0x114), 1) == 0 &&
            func_0033d390(*(void **)(work + 0x1C), 4) == 0 && func_0033d390(*(void **)(work + 0x20), 4) == 0 &&
            func_0033d390(*(void **)(work + 0x24), 4) == 0 && func_0033d390(*(void **)(work + 0x28), 4) == 0 &&
            func_0033d390(*(void **)(work + 0x14), 2) == 0 && func_0033d390(*(void **)(work + 0xB0), 4) == 0 &&
            func_0033d390(*(void **)(work + 0xB0), 2) == 0 && func_0033d390(*(void **)(work + 0x17C), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x17C), 4) == 0 && func_0033d390(*(void **)(work + 0x180), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x180), 4) == 0 && func_0033d390(*(void **)(work + 0x184), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x184), 4) == 0 && func_0033d390(*(void **)(work + 0x58), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x5C), 2) == 0 && func_0033d390(*(void **)(work + 0x118), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x11C), 2) == 0 && func_0033d390(*(void **)(work + 0x40), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x44), 2) == 0 && func_0033d390(*(void **)(work + 0x48), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x4C), 2) == 0 && func_0033d390(*(void **)(work + 0x50), 2) == 0 &&
            func_0033d390(*(void **)(work + 0x54), 2) == 0 && func_0033d390(*(void **)(work + 0x60), 2) == 0) {
            *(s8 *)(work + 0) = 5;
        } else if (func_0033d390(*(void **)(work + 0x10), 1) != 0 && (D_008C024E[0] & 0x20)) {
            func_0045af60(0, 0, 0, 2);
            *(f32 *)(work + 0x1D0) = 580.0f - 21.0f * (f32)func_002b3170(func_002e7a60()) + 0.0f;
            *(f32 *)(work + 0x1D4) = 15.0f;
            *(f32 *)(work + 0x1D8) = 0x28A;
            *(f32 *)(work + 0x1DC) = 15.0f;
            *(s16 *)(work + 0x1EA) = 0;
            func_0033d3e0(*(void **)(work + 0x10), *(F2_0033 *)(func_0033d310(*(void **)(work + 0x10)) + 0x2C),
                          func_002b2970(0x28A, *(f32 *)(func_0033d310(*(void **)(work + 0x10)) + 0x30)), 0, 0xA, 0);
            func_0033d520(*(u8 **)(work + 0x10), *(f32 *)(func_0033d310(*(void **)(work + 0x10)) + 0xC4),
                          *(f32 *)(func_0033d310(*(void **)(work + 0x10)) + 0xBC), 0, 0xA, 0);
            func_0033d550(*(void **)(work + 0xB4));
            func_0033d550(*(void **)(work + 0xB8));
            func_0033d550(*(void **)(work + 0xBC));
            func_0033d550(*(void **)(work + 0x178));
            func_0033d550(*(void **)(work + 0x3C));
            func_0033d550(*(void **)(work + 0x110));
            func_0033d550(*(void **)(work + 0x114));
            for (j = 0; j < 4; j++) {
                func_0033d550(*(void **)(work + j * 4 + 0x1C));
            }
            func_0033d550(*(void **)(work + 0x14));
            func_0033d550(*(void **)(work + 0xB0));
            for (j = 0; j < 3; j++) {
                func_0033d550(*(void **)(work + j * 4 + 0x17C));
            }
            func_0033d550(*(void **)(work + 0x58));
            func_0033d550(*(void **)(work + 0x5C));
            func_0033d550(*(void **)(work + 0x118));
            func_0033d550(*(void **)(work + 0x11C));
            for (j = 0; j < 6; j++) {
                func_0033d550(*(void **)(work + j * 4 + 0x40));
            }
            func_0033d550(*(void **)(work + 0x60));
            func_00122520(1, 0xA);
            *(s8 *)(work + 0) = 0xF;
        }
        break;
    case 15:
        if (func_00122720() == 0) {
            break;
        }
        return -1;
    case 16:
        if (func_00452380(D_0064A3C0) != 0) {
            break;
        }
        for (j = 0; j < 4; j++) {
            func_0033d4b0(*(void **)(work + j * 4 + 0x1C), 0, 0xFF, 0, 5, 0);
        }
        func_0033d4b0(*(void **)(work + 0x10), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x110), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x114), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x14), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0xB4), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0xB8), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0xBC), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x178), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x3C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0xB0), 0, 0xFF, 0, 5, 0);
        for (j = 0; j < 3; j++) {
            func_0033d4b0(*(void **)(work + j * 4 + 0x17C), 0, 0xFF, 0, 5, 0);
        }
        func_0033d4b0(*(void **)(work + 0x58), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x5C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x118), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x11C), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x40), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x50), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x48), 0, 0xFF, 0, 5, 0);
        func_0033d4b0(*(void **)(work + 0x60), 0, 0xFF, 0, 5, 0);
        *(s8 *)(work + 0) = 5;
        break;
    case 17:
        *(f32 *)(work + 0x1E0) =
            func_002b2aa0(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), *(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = func_002b2cb0(*(s16 *)(work + 0x1EA), 1, 10, 1, 1);
        for (j = 0; j < 4; j++) {
            *(f32 *)(func_0033d310(*(void **)(work + j * 4 + 0x188)) + 0xC4) = 0.01f;
        }
        if (func_0033d390(*(void **)(work + 0x14), 2) != 0 || func_0033d390(*(void **)(work + 0x1C), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x1C), 2) != 0 || func_0033d390(*(void **)(work + 0x1C), 1) != 0 ||
            func_0033d390(*(void **)(work + 0x20), 4) != 0 || func_0033d390(*(void **)(work + 0x20), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x20), 1) != 0 || func_0033d390(*(void **)(work + 0x24), 4) != 0 ||
            func_0033d390(*(void **)(work + 0x24), 2) != 0 || func_0033d390(*(void **)(work + 0x24), 1) != 0 ||
            func_0033d390(*(void **)(work + 0x28), 4) != 0 || func_0033d390(*(void **)(work + 0x28), 2) != 0 ||
            func_0033d390(*(void **)(work + 0x28), 1) != 0) {
            break;
        }
        for (j = 0; j < 6; j++) {
            func_0033d320(*(void **)(work + j * 4 + 0x40), 0, 1);
        }
        func_0033d320(*(void **)(work + 0x58), 0, 1);
        func_0033d320(*(void **)(work + 0x5C), 0, 1);
        func_0033d320(*(void **)(work + 0x118), 0, 1);
        func_0033d320(*(void **)(work + 0x11C), 0, 1);
        func_0033d3d0(*(void **)(work + 0xB0), 0x65);
        for (j = 0; j < 3; j++) {
            func_0033d3d0(*(void **)(work + j * 4 + 0x17C), 0x65);
        }
        func_0033d3d0(*(void **)(work + 0x110), 0x65);
        func_0033d3d0(*(void **)(work + 0x114), 0x65);
        func_0033d3d0(*(void **)(work + 0x60), 0x65);
        for (i42 = 0; i42 < 4; i42++) {
            func_0033d320(*(void **)(work + i42 * 4 + 0x188), 13, 0);
            func_0033d320(*(void **)(work + i42 * 4 + 0x188), 0, 0);
            func_0033d4e0(*(void **)(work + i42 * 4 + 0x188), 0.1f, 2.7f, 0, 0xA, 0);
            func_0033d520(*(u8 **)(work + i42 * 4 + 0x188), 0.0f, i42 * 0x5A, 0, 0, 0);
            func_0033d3c0(*(void **)(work + i42 * 4 + 0x188), 1.0f);
            *(s16 *)(func_0033d310(*(void **)(work + i42 * 4 + 0x188)) + 0x100) = *(s16 *)(func_0033d310(*(void **)(work + i42 * 4 + 0x188)) + 0x102) = 0;
            *(u8 *)(func_0033d310(*(void **)(work + i42 * 4 + 0x188)) + 0x62) = 2;
            func_0033d3d0(*(void **)(work + i42 * 4 + 0x188), 0x64);
        }
        func_0033d320(*(void **)(work + 0x10), 0, 0);
        func_0033d3e0(*(void **)(work + 0x10), func_002b2970(D_0064A090[0], D_0064A090[1]), func_002b2970(0x28A, 241.0f),
                      0, 0xA, 0);
        func_0033d520(*(u8 **)(work + 0x10), -720.0f, 0.0f, 0, 0xA, 0);
        func_0033d3d0(*(void **)(work + 0x10), 0x62);
        func_00122520(1, 0x1E);
        *(s8 *)(work + 0) = 0x12;
        break;
    case 18:
        if (func_00122720() == 0) {
            break;
        }
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off /* measured: restore the baseline */

// FUN_0033BDC0
void func_0033bdc0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002e29a0();
    if (*(s32 *)(work + 0x428) != 0) {
        H_Cdvd_Destroy((void *)*(s32 *)(work + 0x428));
    }
    if (*(s32 *)(work + 0xC) != 0) {
        func_0046b0d0((void *)*(s32 *)(work + 0xC));
        *(s32 *)(work + 0xC) = 0;
    }
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured: object_size 324/window 336, normalized_diff 0 (retail tail is
   zero padding). MWCCPS2 needs opt_loop_invariants on to hoist the loop's
   `1` constant before the entry jump, matching retail's preheader materialisation. */
#pragma opt_loop_invariants on
// FUN_0033BE40
u8 *func_0033be40(u8 *arg0) {
    s32 i;
    s32 one;
    u8 *temp_17;
    s8 *temp_2;

    func_0044ea90(D_0064A380, 0x958);
    temp_2 = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    temp_17 = func_00451fc0((void *)(arg0), (const void *)(D_0064A3D8), 0xF, 0, 0, func_00332bb0, func_0033bdc0, (u8 *)((u8 *)temp_2));
    *(s8 *)(temp_2 + 0) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    *(f32 *)(temp_2 + 0x1E0) = (f32)0x28A;
    *(s32 *)(temp_2 + 0x1E4) = 0x41700000;
    *(s16 *)(temp_2 + 0x1EA) = 0;
    *(s16 *)(temp_2 + 0x1EC) = 0;
    *(s8 *)(temp_2 + 1) = 0;
    *(s32 *)(temp_2 + 0x2B0) = 0;
    *(s32 *)(temp_2 + 0x2A8) = 0;
    *(s32 *)(temp_2 + 0x2AC) = 0;
    *(s8 *)(temp_2 + 0x424) = 0;
    one = 1;
    i = 0;
    while ((s16)i < 0x24) {
        *(s8 *)(temp_2 + (s16)i + 0x2D8) = one;
        i = (s16)(i + 1);
    }
    if (func_002e71c0() == 1) {
        *(s8 *)(temp_2 + 0x424) = 1;
    }
    func_002e24a0(0x10000, 0, 2, 1);
    return temp_17;
}
/* measured: closes the opt_loop_invariants scope required by func_0033be40. */
#pragma opt_loop_invariants off

// FUN_0033BF90
void func_0033bf90(u8 *arg0) {
    s32 i;
    u8 *work;
    s32 item_index;
    s64 layer;
    f32 *coords;
    u8 *item;
    void *font;
    register u8 *table;
    f32 x;
    f32 y;
    F2_0033 pos0;
    F2_0033 pos1;
    F2_0033 pos2;
    F2_0033 pos3;
    F2_0033 pos4;
    F2_0033 pos5;
    F2_0033 pos6;
    F2_0033 pos7;
    F2_0033 pos8;
    F2_0033 pos9;
    F2_0033 pos10;
    F2_0033 pos11;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while ((s16)i < 4) {
        layer = (s64)(s16)((s16)i * 3);
        item_index = (s16)i + 3;
        coords = (f32 *)((u8 *)D_0064A090 + (item_index * 8));
        item = work + (s16)i * 4 + 0x1C;
        func_0033d4e0((void *)*(s32 *)item, 1.0f, 0.5f, 0, 10, layer);
        func_0033d4b0((void *)*(s32 *)item, 0xFF, 0, 0, 10, layer);
        func_0033d3d0((void *)*(s32 *)item, 0xAC);
        font = func_0046d200((void *)*(s32 *)(work + 0xC), item_index);
        pos0 = func_002b2970(coords[0], coords[1]);
        x = (func_0046b260(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (func_0046b2f0(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        pos1 = func_002b2970(x, y);
        func_0033d3e0((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        func_0046d280(font);
        i = (s16)(i + 1);
    }
    func_0033d320((void *)*(s32 *)(work + 0x14), 0, 0);
    func_0033d4b0((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0);
    func_0033d3d0((void *)*(s32 *)(work + 0x14), 0xAC);
    table = (u8 *)D_0064A1D8;
    pos2 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos3 = func_002b2970(-180.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB4), pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    pos4 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos5 = func_002b2970(-200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB8), pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    pos6 = func_002b2970(153.0f, *(f32 *)(table + 4));
    pos7 = func_002b2970(-100.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xBC), pos6, pos7, 0, 0x14, 0);
    pos8 = func_002b2970(203.0f, *(f32 *)(table + 4));
    pos9 = func_002b2970(-50.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x178), pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    pos10 = func_002b2970(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos11 = func_002b2970(-200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x3C), pos10, pos11, 0, 0xF, 0);
    func_0033d4e0((void *)*(s32 *)(work + 0xB0), 1.0f, 4.5f, 0, 0xF, 0);
    i = 0;
    while ((s16)i < 3) {
        func_0033d4e0((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 1.0f, 4.5f, 0, 0xF, 0);
        i = (s16)(i + 1);
    }
    func_0033d3c0((void *)*(s32 *)(work + 0x110), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x114), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x60), 83.0f);
    *(f32 *)(work + 0x1D0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
    *(s32 *)(work + 0x1D4) = 0x41700000;
    *(f32 *)(work + 0x1D8) = (f32)0x28A;
    *(s32 *)(work + 0x1DC) = 0x41700000;
    *(s16 *)(work + 0x1EA) = 0;
    *(s8 *)(work + 0) = 0x11;
}

/* Item list panel: the selected-item header, or five scrolling item rows with
   their frame, name and price. Shaping that matters: the frame and name
   draws are inline helpers (their float y parameters live in $f20 and the
   shared row top is one int that retail spills), the price goes out through
   its own pos/colour pair, the cursor tables are read through an F2_0033
   pointer (kept in $s1 across the reset call), and the shaded colour is
   written `green = blue = 0` (the andi on $zero). */
static inline void fclShopDrawItemFrame(u8 *p, f32 y, u8 red, u8 green, u8 blue)
{
    func_0025ecd0(44.0f, y, 62.0f, func_002b2a30(0xFF, red, green, blue), 0xFF, 0x24,
                  *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

static inline void fclShopDrawItemName(s16 item, f32 y, u8 red, u8 green, u8 blue)
{
    func_00275520(78.0f, y, 62.0f, func_002b2a30(red, green, blue, 0xFF), 0, 1,
                  func_001067f0((s16)func_002e2740(item)), 0, 0, D_00795E60);
}

// FUN_0033C490
void func_0033c490(u8 *arg0)
{
    u8 *p;
    s32 color;
    u32 value;
    s16 i;
    s16 row;
    s32 bound;
    u8 red;
    u8 green;
    u8 blue;
    u32 price;
    s32 y;
    s32 top;
    f32 fy;
    F2_0033 *tbl;
    F2_0033 pos1;
    FclDrawColor col1;
    F2_0033 pos2;
    FclDrawColor col2;

    p = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(p + 2) == 1) {
        func_0025ecd0(44.0f, 77.0f, 62.0f, func_002b2a30(0xFF, 0x26, 0x26, 0x26), 0xFF, 0x24,
                      *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
        color = func_002b2a30(0x26, 0x26, 0x26, 0xFF);
        value = func_001067f0((s16)func_002e2740(*(s16 *)(p + 4)));
        func_00275520(78.0f, 77.0f, 62.0f, color, 0, 1, value, 0, 0, D_00795E60);
        pos1 = func_002b2970(406.0f, 84.0f);
        col1 = func_002b2a60(0x26, 0x26, 0x26, 0xFF);
        func_002caa10(pos1, 62.0f, col1,
                      func_0033cbc0(arg0, func_002e2740(*(s16 *)(p + 4))), 0x19,
                      *(void **)(p + 0xC), 0xAB);
        func_002bc7f0((s16)func_00106b80((s16)func_002e2740(*(s16 *)(p + 4))), -1, 1, 0, 4, 0xAA,
                      71.0f, 135.0f, 62.0f);
        func_0033d320(*(void **)(p + 0x120), 0, 1);
        func_0033d320(*(void **)(p + 0x124), 0, 1);
        func_0033d320(*(void **)(p + 0xDC), 0, 0);
        func_0033d320(*(void **)(p + 0xE0), 0, 0);
        func_0033d320(*(void **)(p + 0x6C), 0, 1);
        func_0033d320(*(void **)(p + 0x70), 0, 0);
        func_0033d320(*(void **)(p + 0xD8), 0, 0);
        return;
    }
    func_0033d320(*(void **)(p + 0xDC), 0, 1);
    func_0033d320(*(void **)(p + 0xE0), 0, 1);
    func_0033d320(*(void **)(p + 0x6C), 0, 0);
    func_0033d320(*(void **)(p + 0x70), 0, 1);
    func_0033d320(*(void **)(p + 0xD8), 0, 1);
    tbl = (F2_0033 *)D_0064A2B0;
    func_0033d320(*(void **)(p + 0x120), 0, 0);
    fy = tbl->x;
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x120)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x120)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x120), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x120), 0x5B);
    tbl = (F2_0033 *)D_0064A2B8;
    func_0033d320(*(void **)(p + 0x124), 0, 0);
    fy = tbl->x;
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x124)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(func_0033d310(*(u8 **)(p + 0x124)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x124), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x124), 0x5B);
    i = *(s16 *)(p + 4) - *(s16 *)(p + 6);
    row = 0;
    bound = i + 5;
    for (; i < bound; i++, row++) {
        if (i >= func_002e2670()) {
            continue;
        }
        red = green = blue = 0xFF;
        if (i == *(s16 *)(p + 4)) {
            red = green = blue = 0x26;
        } else {
            price = func_0033cbc0(arg0, func_002e2740(i));
            if (func_002e7a60() < price) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)func_00106600((s16)func_002e2740(i)) == 0x63) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)clndGetMoonPhase(func_002e2740(i)) & 1) {
                red = 0x9F;
                blue = 0x2F;
            }
        }
        y = row * 28;
        top = y + 0x4D;
        fclShopDrawItemFrame(p, (f32)top, red, green, blue);
        fclShopDrawItemName(i, (f32)top, red, green, blue);
        pos2 = func_002b2970(406.0f, (f32)(y + 0x54));
        col2 = func_002b2a60(red, green, blue, 0xFF);
        func_002caa10(pos2, 62.0f, col2, func_0033cbc0(arg0, func_002e2740(i)),
                      0x19, *(void **)(p + 0xC), 0xAB);
    }
}
// FUN_0033CBC0
u32 func_0033cbc0(void *arg0, s64 arg1) {
    u8 *work = *(u8 **)((u8 *)arg0 + 0x38);
    u32 d = (u32)((s32)(*(s8 *)(work + 9) * (s32)func_00106a90((s64)(s16)arg1)) * 0x14) / 100U;

    return (u32)func_00106a90((s64)(s16)(s32)arg1) - d;
}

/* measured: 1216B/1216B MATCH (304 instrs, 0 edits + 9 reloc-only). Re-probed from scratch: floats-first func_0025ecd0 spelling (f32,f32,f32 first, then color/ints, then f32,f32,f32, pointer last) with u16 0xF8 load (lhu) and inline s16/2 division gives retail scheduling; shift+temp hoisting was +33, s16 F8 was +2 (35), archive ints-first is a compile error under this prototype. Mixed-arg orders tested explicitly. */
// FUN_0033CC40
s32 func_0033cc40(u8 *arg0) {
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f20;
    s16 temp_4;
    s16 temp_4_2;
    s16 temp_6;
    s8 temp_3;
    s8 temp_3_5;
    u8 *temp_2;
    u8 *callback_work;

    callback_work = *(u8 **)((u8 *)arg0 + 0x38);
    memcpy(callback_work + 4, func_002b89a0(callback_work + 4), 0xF0);
    if (func_0033d390((u8 *)arg0, 0xA) == 1) {
        temp_4 = *(s16 *)(callback_work + 0x38);
        if (temp_4 == 0) {
            temp_3 = *(s8 *)(callback_work + 0x3B);
            switch (temp_3) {
            case 0:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x20),
                    *(f32 *)(callback_work + 0x28), (f32)*(s16 *)(callback_work + 0x36),
                    (f32)(*(s16 *)(callback_work + 0x34) / 2));
                break;
            case 1:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    *(s8 *)(callback_work + 0x3A), *(f32 *)(callback_work + 0x1C),
                    *(f32 *)(callback_work + 0x24), (f32)*(s16 *)(callback_work + 0x36),
                    (f32)(*(s16 *)(callback_work + 0x34) / 2));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    0, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                break;
            case 2:
                *(f32 *)(callback_work + 0x2C) = func_002b2aa0(
                    1, *(f32 *)(callback_work + 0x1C), *(f32 *)(callback_work + 0x24),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = func_002b2aa0(
                    2, *(f32 *)(callback_work + 0x20), *(f32 *)(callback_work + 0x28),
                    (f32)*(s16 *)(callback_work + 0x36), (f32)*(s16 *)(callback_work + 0x34));
                *(f32 *)(callback_work + 0x30) = (f32)(
                    *(f32 *)(callback_work + 0x30) -
                    func_002b2aa0(1, 0.0f, 100.0f,
                                  (f32)*(s16 *)(callback_work + 0x36), (f32)(*(s16 *)(callback_work + 0x34) / 2)));
                break;
            }
            temp_6 = *(s16 *)(callback_work + 0x34);
            temp_4_2 = *(s16 *)(callback_work + 0x36);
            if (temp_4_2 < temp_6) {
                *(s16 *)(callback_work + 0x36) = func_002b2cb0(
                    (s32)temp_4_2, 1, (s32)temp_6, 0, 1);
            } else {
                *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x24);
                *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x28);
                temp_3_5 = *(s8 *)(callback_work + 0x3B);
                if (temp_3_5 == 0) {
                    *(f32 *)(callback_work + 0x30) = *(f32 *)(callback_work + 0x20);
                } else if (temp_3_5 == 1) {
                    *(f32 *)(callback_work + 0x2C) = *(f32 *)(callback_work + 0x1C);
                }
                func_0033d320((u8 *)arg0, 0xA, 1);
            }
        } else {
            *(s16 *)(callback_work + 0x38) = func_002b2d00(temp_4, 1, 0, 0, 1);
        }
    }
    if (func_0033d390((u8 *)arg0, 0) == 1) {
        if (func_0033d390((u8 *)arg0, 0xD) == 1) {
            temp_2 = (u8 *)func_00460990();
            *(void **)(temp_2 + 8) = (void *)func_00332a80;
            *(s32 *)(temp_2 + 0x10) = 0;
            func_00460ac0(
                (void *)((u8 *)D_00793E80 +
                         (*(s32 *)(callback_work + 0xFC) * 0x30)),
                temp_2);
            func_0025ecd0(
                *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                *(f32 *)(callback_work + 8),
                func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                              *(u8 *)(callback_work + 0x7A), *(u8 *)(callback_work + 0x7B)),
                *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                (void *)*(s32 *)(callback_work + 0xF4), 0,
                *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                *(f32 *)(callback_work + 0xC4),
                *(f32 *)(callback_work + 0x94), *(f32 *)(callback_work + 0xA0),
                (void *)((u8 *)D_00793E80 + (*(s32 *)(callback_work + 0xFC) * 0x30)));
        } else {
            temp_f20 = *(f32 *)(callback_work + 0x94);
            temp_f0 = iGpffff8504;
            if (!(temp_f20 < temp_f0)) {
                temp_f21 = *(f32 *)(callback_work + 0xA0);
                if (!(temp_f21 < temp_f0)) {
                    func_0025ecd0(
                        *(f32 *)(callback_work + 0x2C), *(f32 *)(callback_work + 0x30),
                        *(f32 *)(callback_work + 8),
                        func_002b2a30(0xFF, *(u8 *)(callback_work + 0x79),
                                      *(u8 *)(callback_work + 0x7A),
                                      *(u8 *)(callback_work + 0x7B)),
                        *(u8 *)(callback_work + 0x62), *(u16 *)(callback_work + 0xF8),
                        (void *)*(s32 *)(callback_work + 0xF4), 1,
                        *(s16 *)(callback_work + 0x100), *(s16 *)(callback_work + 0x102),
                        *(f32 *)(callback_work + 0xC4),
                        temp_f20, temp_f21,
                        (void *)((u8 *)D_00793E80 + (*(s32 *)(callback_work + 0xFC) * 0x30)));
                }
            }
        }
    }
    return 0;
}

// FUN_0033D100
void func_0033d100(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0033D130
/* Counter must be s32 with explicit (s16) casts at each use to reproduce
   retail's $a3 counter coloring and the per-use dsll32/dsra32 normalization.
   measured: without this pragma mwcc rematerializes the 0xFF / 0x3F800000
   constants inside the loop body (nd 50+); with it they hoist to the
   preheader exactly as retail does (nd 0). */
#pragma opt_loop_invariants on
u8 *func_0033d130(void *arg0, s32 arg1, s32 arg2) {
    s32 i;
    u8 *temp_17;
    u8 *work;
    f32 *item_data;
    void *r;

    func_0044ea90(D_0064A380, 0xACA);
    work = D_008873F4[0](1, 0x104, 0x40000);
    temp_17 = func_00451fc0((void *)(arg0), (const void *)(D_0064A3F0), 0xF, 0, 0, func_0033cc40, func_0033d100, (u8 *)(work));
    work[0] = 0;
    *(s16 *)(work + 0xF8) = arg1;
    *(s32 *)(work + 0xF4) = arg2;
    item_data = (f32 *)((u8 *)D_0064A090 + ((arg1 & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        *(f32 *)(work + (s16)i * 8 + 0x1C) = item_data[0];
        *(f32 *)(work + (s16)i * 8 + 0x20) = item_data[1];
        work[(s16)i + 0x60] = 0xFF;
        *(s32 *)(work + (s16)i * 4 + 0x8C) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0x98) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0xBC) = 0;
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    *(s32 *)(work + 8) = 0x42C80000;
    *(s32 *)(work + 0xFC) = 0x55;
    *(s16 *)(work + 4) = 0;
    r = func_0046d200((void *)*(s32 *)(work + 0xF4), 0, item_data, i);
    *(s16 *)(work + 0x100) = (s16)(s32)(func_0046b260(r) / 2.0f);
    *(s16 *)(work + 0x102) = (s16)(s32)(func_0046b2f0(r) / 2.0f);
    func_0046d280(r);
    return temp_17;
}
/* measured: see annotation above (func_0033d130). */
#pragma opt_loop_invariants off
