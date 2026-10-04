#include "fcl_scale_transition.h"
/* measured: this unit passes u8 colour channels unmasked (002f6cf0, 002f9d90); see fcl_color.h. */
#include "fcl_animation_internal.h"
#include "model_motion_internal.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "fcl_row_draw.h"
#include "fcl_row_mode.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
extern s32 func_002e7ac0(u8 *task);
extern void func_002e82b0(u8 *task);
#include "type.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;

#include "fcl_combine_internal.h"
#include "cmb_card_eff.h"

typedef FclVec2 FclVec2f;

extern void func_0032b770(u8 *, s32, s32, s8);
extern void func_0032b9d0(u8 *, s32, s32, s8);
extern void func_002e68b0(s8);
extern void func_002e6c90(s8);
extern void func_00314560(u8 *, s32, s8, s8);
extern void func_0032c480(u8 *);
extern s32 func_0034a630(u8 *);
extern void func_0011d1d0(u8 *, f32);
extern void func_00314750(u8 *, s8);
extern u8 func_001099f0(u8 *, s32);
extern s32 func_003026c0(u16, s32);
extern void func_002e7a80(s32);
extern void func_002cacd0(FclVec2, f32, FclDrawColor, s32, s16, u32, s32, s32, s32, s32, s32);
extern void *func_0046a770(void *);
extern u8 D_00641B30[];
extern void func_0032c0c0(u8 *, s64);
extern void func_00324f80(u8 *, FclVec2, s32, s8);
extern void func_003297f0(f32, f32, u8 *, s64, s8);
extern s32 func_0011ba00(u8 *);
extern char iGpffffa8a4;
extern u16 D_008C0252[];
extern void func_0032a960(u8 *, s8);
extern void func_002b5e90(u8 *, FclVec2, FclVec2, u32);
extern void func_002b60f0(u8 *, u8, u8, u32);
extern void func_00317320(u8 *, s64, f32);
extern void func_0034a890(u8 *);
extern void func_0034a840(u8 *);
extern u8 *func_0010fcb0(s32);
extern char iGpffffa8a0;

extern void func_003146f0(u8 *, s32, s8);
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern s32 func_00104c70(s32);
extern void func_002e4610(s32, s8);
extern void func_00315600(u8 *, s64);
extern s32 func_003190d0(u8 *);
extern u8 *func_002e4870(s8);
extern u8 *func_002e48a0(s8, s16);
extern void func_0010be60(u8 *, u8 *, s32);
extern s32 func_00313fb0(u8 *);
extern s32 func_0010b5b0(void);
extern void func_00316470(u8 *, s64, s8);
extern void func_00316e80(u8 *, s64, s64, s64, s64, s64, s64, s64, s8, s8, s8);
extern s32 func_002b2a30(u8, u8, u8, u8);
extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
extern u8 *func_0046d200(u32, u32);
extern s32 func_00331560(void);
extern f32 func_0046b260(u8 *);
extern f32 func_0046b2f0(u8 *);
extern void func_0046d280(void *);
extern void func_002b6a70(s16, u8, u8, u8, s32, s16);
extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
extern void func_00314450(u8 *, s32, u8, s32);
extern void func_0011c6e0(u8 *, s32);
extern void func_0011d140(u8 *, s32);
extern u32 func_0011c610(u8 *);
extern void func_0011caf0(u8 *);
extern void func_0011c630(u8 *);
extern void func_00314740(u8 *, s8);
extern u8 *func_003147d0(u8 *);
extern s32 func_0045af60(s16, s16, s16, s16);
extern void func_00314670(u8 *, s8);
extern void func_00317240(u8 *, s64, f32);
extern s8 func_00314660(u8 *);
extern void func_00314680(u8 *);
extern s16 func_002b6970(s16, s16);
extern u8 *func_002b6150(s16);
extern void func_00321e60(u8 *, s64, u8, u8);
extern void func_003233d0(u8 *);
extern void func_003191c0(u8 *, FclVec2, s32, s32, s16, s16, s8, s8);
extern void func_0031ac10(u8 *, FclVec2, s8, s8, s32, s16, s16, s8, s8, u8);
extern void func_0031c2b0(u8 *, s16, FclVec2f, FclVec2f);
extern void func_0031cce0(u8 *, s16, FclVec2, FclVec2);
extern void func_00320b80(u8 *, s8);
extern void func_003218a0(u8 *, s16);
extern void func_00324410(u8 *, s16, s8);
extern u32 RpRandom(void);
extern void func_002b68d0(s16, s16, s8);
extern s32 func_002bb550(s64);
extern void func_002bbcf0(s32);
extern s32 func_002e53b0(s8, s16);
extern void func_002eb270(u8 *, s32);
extern s8 func_00105f50(u16);
extern u32 datGetFlag(s32);
extern void *memset(void *, s32, u32);
extern void func_002e5ae0(s8, u16 *, s8);
extern void func_002e6280(s8, u16 *, s8);
extern s32 func_0010ce10(u8 *, u16);
extern s32 func_0010ceb0(u8 *);
extern s32 func_0010cc20(u8 *, u16);
extern s32 func_002bb680(s32);
extern s32 func_00122720(void);
extern s32 func_00122520(s32, s32);
extern s16 func_00247770(s32);
extern s32 func_00312bc0(s8);
extern void func_003144d0(u8 *, s32, s8, s32, s32);
extern s32 func_00311930(s32,  u8 *,  s8);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s32 func_002b2d00(s32, s32, s32, s32, s8);
extern f32 D_00640C10[];
extern f32 D_00640C18[];
extern u8 D_00795E60[];
extern u16 D_008C024E[];
extern u16 D_008C024C[];
extern u16 D_008C027A[];
extern u8 *iGpffffb440;
extern u8 *iGpffffb3d4;
extern f32 iGpffff8504;
extern f32 iGpffff8218;
extern void func_002f9c30(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
extern void func_00310960(u8 *, s32, s32);
extern void func_00310a10(u8 *, u16);
extern void func_0011b8f0(u8 *, u8 *);
extern s32 func_0011cc00(u8 *, u16, u16);
extern u8 *func_00243840(s32);
extern int func_00275520(f32, f32, f32, int, s8, int, const char *, int, int, void *);
extern s32 func_002bb1c0(s8);
extern void func_002e5000(void);
extern void func_0032fbc0(u8 *);
extern u16 *func_00308cc0(u8 *);
extern s32 func_00308dc0(u8 *);
extern s32 func_00308e50(u8 *);
extern s32 func_00309630(u16);
extern s32 func_003096d0(u8 *);
extern s32 func_0010cd70(u8 *, s16, u16);
extern u16 func_0010b6f0(void);
extern u8 *func_001102e0(void);
extern void func_002ba970(u8 *, s16, FclDrawColor);
extern s64 func_002bab80(void *);
extern s32 func_002badc0(s8, s32);
extern s32 func_002bafc0(s64, s32);
extern void func_002bb0a0(s64, s8);
extern int sprintf(char *, const char *, ...);
extern void func_002ba5d0(u8 *, s16, s32, FclVec2, FclDrawColor, f32, s64);
extern u32 func_002e7a60(void);
extern u8 *func_00349290(u8 *, s8);

extern void func_00313b50(u8 *task);
extern s32 func_0033e3f0(u8 *task);


extern void func_002b5e30(u8 *task, FclDrawColor color);
extern void func_002b5e20(u8 *task, f32 depth);
extern void func_002b6130(u8 *task, u32 order);
extern void func_002b6140(u8 *task, u8 hidden);
extern void func_002b6120(u8 *task, u8 mode);
extern void func_00145080(void);
extern s32 func_00452380(void *);
extern void func_003315a0(void);
extern void H_Cdvd_Destroy(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern s8 D_007490F8[];
extern u16 *func_0010ace0(s16);
extern u8 func_00109280(u16);
extern s32 func_00331660(void);
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
extern void func_002bbf60(void);
extern s32 func_0010cf40(void *, s16);
extern u16 *iGpffffb3ec;
extern u8 *iGpffffb594;
extern void func_0010fd40(void *);
extern void func_00106620(s16, s32);
extern u8 D_00641BE0[];
extern u8 D_00641C00[];
extern char iGpffffa8c8;
extern void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern void func_0045aac0(s32, s32, s32);
extern s32 func_00110460(void);
extern void func_00105690(s32, s32);
extern void func_00105fa0(s32);
extern u8 *func_0010b010(u16 personaId);
extern void func_00330060(u8 *arg0, s32);
extern u16 D_008C0276[];
extern f32 D_00640D78[];
extern void func_00106390(s32, s32);
extern void func_0044ea90(const void *, s32);
extern void *memcpy(void *, void *, u32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00641B00[];
extern u16 func_0010b460(void);
extern s32 func_0010ad80(s32);
extern s32 func_0010b190(u8 *);
extern s32 func_0010b300(s32);
extern void func_0010b7f0(void);
extern void func_0010cad0(u8 *arg0, u16 arg1);
extern s64 func_00312c60(u16 *arg0, u8 *arg1, s64 arg2);
/* The item id is an s16; the callee sign-extends its own table index. */
extern s32 func_00313690(s16 arg0);
extern u8 func_002e78a0(void);
extern s32 func_002e78e0(void);
extern s8 D_00641A60[];
extern s8 D_00749480[];
extern u8 *iGpffffb44c;
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
extern s32 func_002e8410(u8 *arg0);
extern s32 func_00452490(s32 arg0);
extern void func_00122640(s32, s32);
extern s32 H_Cdvd_IsFileLoaded(void *arg0);
extern void func_00144c90(s32, s32);
extern void func_00144e10(s32);
extern s16 func_00104f10(s16);
extern s32 func_0033e120(u8 *arg0, s32, s32);
extern void func_001075d0(s32);
extern s32 func_00144f60(void);
extern u8 *func_001452b0(s32);
extern u8 *func_00457120(void);
extern f32 func_0014b4d0(void);
extern void K_View_SetFov(u8 *arg0, f32 arg1);
extern s32 func_0014b450(void);
extern void func_003e9cb0(s32, s32, s32);
extern void func_00331390(void);
extern s32 func_00331580(void);
extern s32 func_0034a4f0(s32, s32);
extern u8 *func_002b74f0(s32, s32);
extern void func_002b7750(s16, s16);
extern s32 func_00331600(void);
extern u8 D_00641B10[];
extern s32 func_003145e0(s32);
extern s32 func_00285b30(void);
extern s32 func_00452490(s32);
extern s32 func_00452080(KwlnTask *);
extern s32 func_00459760(void);
extern void func_0045a3e0(s32, s32);
extern void func_0030f4f0(u8 *, s16 *);
extern s32 func_00314320(u8 *);
extern s32 func_00302570(u8 *);
extern f32 D_00640C50[];
extern f32 D_00640C58[];
extern u8 D_00641BB0[];
extern void func_00317900(u8 *, FclVec2, FclVec2, s8, s16, s16, s16);
extern u8 D_00640760[];
extern u8 D_00640790[];
extern u8 D_0064079C[];
extern u8 D_006407A8[];
extern u8 D_006407C0[];
extern u16 func_001102d0(void);
extern u16 func_00109470(u16);
extern void func_00110270(u8 *, u16);
extern void func_001102c0(u16);
extern u8 D_00749350[];
extern u16 func_003095f0(void);




/* Registers the combine UI and its child draw tasks. Creators return
 * real SDK handles; positions, colors and bounds use their shared contracts.
 * MWCCPS2 b210 -O2: 3256/3264 bytes, 148 resolved relocations, eight zero
 * tail bytes. See the SDK/Fcl closure evidence for every affected owner.
 */
// FUN_002E8410
s32 func_002e8410(u8 *arg0) {
    s32 k;
    s32 task;
    u8 *out;
    FclDrawColor menuColor;
    u8 *e;

    func_0044ea90(D_00641B00, 0x166);
    out = D_008873F4[0](1, 0x314, 0x40000);
    task = (s32)func_00451fc0((void *)((void *)((s32)arg0)), (const void *)(D_00641B10), 0xF, 0, 0, func_002e7ac0, func_002e82b0, (u8 *)(out));
    *out = 0;
    *(out + 1) = 0x11;
    *(out + 0x144) = 0;
    func_00313b50((u8 *)(task));
    *(out + 0x20) = 0;
    *(out + 0xB3) = 0;
    *(s32 *)(out + 0x254) = func_0034a4f0((s32)arg0, 0);
    {
        s32 partyIndex;
        for (partyIndex = 0; partyIndex < (func_0010b5b0() & 0xFFFF); partyIndex++) {
            *(s32 *)(out + partyIndex * 4 + 0x154) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
        }
    }
    *(s32 *)(out + 0x184) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x41);
    *(s32 *)(out + 0x188) = func_0034ad70((s32)arg0, func_0010b5b0() & 0xFF, 0x58);
    {
        s32 segmentIndex;
        for (segmentIndex = 0; segmentIndex < 0xC; segmentIndex++) {
            menuColor = func_002b2a60(0, 0, 0x99, 0xFF);
            e = func_0034ae50(*(u8 **)(out + 0x188), (s8)segmentIndex);
            *(FclDrawColor *)(e + 0x75) = menuColor;
        }
    }
    *(s32 *)(out + 0x24C) = (s32)func_002b74f0((s32)arg0, func_00331560());
    {
        s32 descriptorId;
        for (descriptorId = 0; descriptorId < 500; descriptorId++) {
            func_002b7750((s16)descriptorId, (s16)descriptorId);
        }
    }
    {
        s32 pairIndex;
        for (pairIndex = 0; pairIndex < 0xC; pairIndex++) {
            func_002b7750((s16)(pairIndex * 2 + 500), 0x1AC);
            func_002b7750((s16)(pairIndex * 2 + 501), 0x1AF);
        }
    }
    func_002b7750(0x20C, 0x80);
    {
        s32 arrowIndex;
        for (arrowIndex = 0; arrowIndex < 9; arrowIndex++) {
            func_002b7750((s16)(arrowIndex + 0x20D), 0xDC);
        }
    }
    {
        s32 indicatorIndex;
        for (indicatorIndex = 0; indicatorIndex < 3; indicatorIndex++) {
            func_002b7750((s16)(indicatorIndex + 0x216), 0x86);
            func_002b7750((s16)(indicatorIndex + 0x219), 0x87);
        }
    }
    {
        s32 rowIndex;
        for (rowIndex = 0; rowIndex < 0xC; rowIndex++) {
            func_002b7750((s16)(rowIndex + 0x21C), 0x193);
            func_002b7750((s16)(rowIndex + 0x22B), 0x19A);
            func_002b7750((s16)(rowIndex + 0x238), 0x188);
            func_002b7750((s16)(rowIndex + 0x244), 0x18C);
            func_002b7750((s16)(rowIndex + 0x250), 0x1C);
            func_002b7750((s16)(rowIndex + 0x25E), (s16)(rowIndex + 0x39));
            func_002b7750((s16)(rowIndex + 0x270), 0x193);
            func_002b7750((s16)(rowIndex + 0x27D), 0x19B);
            func_002b7750((s16)(rowIndex + 0x28B), 0x188);
            func_002b7750((s16)(rowIndex + 0x297), 0x18D);
            func_002b7750((s16)(rowIndex + 0x2A3), 0x1C);
        }
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
    {
        s32 ballIndex;
        for (ballIndex = 0; ballIndex < 0xC; ballIndex++) {
            *(s32 *)(out + ballIndex * 4 + 0x21C) = func_0034b740((s32)arg0);
        }
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
    func_002b7750(0x2DC, (s16)(((u8)func_002e78e0() / 10) + 9));
    func_002b7750(0x2DD, (s16)(((u8)func_002e78e0() % 10) + 9));
    func_002b7750(0x22A, 0x193);
    func_002b7750(0x2DE, 0x126);
    func_002b7750(0x2DE, 0x125);
    for (k = 0; k < 0xC; k++) {
        func_002b7750((s16)(k + 0x2FB), 0x131);
        *(s32 *)(out + k * 4 + 0x258) = func_002b8150(task);
    }
    *(s32 *)(out + 0x28C) = (s32)func_002b5c90(task, func_002b2970(288.0f, 14.0f));
    func_002b5db0((u8 *)*(s32 *)(out + 0x28C), func_002b2970(288.0f, 14.0f), func_002b29e0(160.0f, 36.0f));
    func_002b6130((u8 *)(*(s32 *)(out + 0x28C)), 0xAB);
    func_002b6140((u8 *)(*(s32 *)(out + 0x28C)), 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x28C), func_002b2a60(0xFF, 0xFF, 0xFF, 0));
    func_002b5e20((u8 *)(*(s32 *)(out + 0x28C)), 53.0f);
    *(s32 *)(out + 0x290) = (s32)func_002b5c90(task, func_002b2970(0.0f, 14.0f));
    func_002b5db0((u8 *)*(s32 *)(out + 0x290), func_002b2970(0.0f, 14.0f), func_002b29e0(26.0f, 36.0f));
    func_002b6130((u8 *)(*(s32 *)(out + 0x290)), 0xAB);
    func_002b6140((u8 *)(*(s32 *)(out + 0x290)), 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x290), func_002b2a60(0xFF, 0xFF, 0xFF, 0));
    func_002b5e20((u8 *)(*(s32 *)(out + 0x290)), 53.0f);
    *(s32 *)(out + 0x2AC) = (s32)func_002b5c90(task, func_002b2970(0.0f, 0.0f));
    func_002b5db0((u8 *)*(s32 *)(out + 0x2AC), func_002b2970(0.0f, 0.0f), func_002b29e0(640.0f, 7.0f));
    func_002b6130((u8 *)(*(s32 *)(out + 0x2AC)), 0xB2);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2AC), func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
    func_002b6140((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    func_002b6120((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    *(s32 *)(out + 0x2B0) = (s32)func_002b5c90(task, func_002b2970(0.0f, 432.0f));
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B0), func_002b2970(0.0f, 432.0f), func_002b29e0(640.0f, 16.0f));
    func_002b6130((u8 *)(*(s32 *)(out + 0x2B0)), 0xB2);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B0), func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
    func_002b6140((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    func_002b6120((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    *(s32 *)(out + 0x2B4) = (s32)func_002b5c90(task, func_002b2970(0.0f, 69.0f));
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B4), func_002b2970(0.0f, 69.0f), func_002b29e0(640.0f, 343.0f));
    func_002b6130((u8 *)(*(s32 *)(out + 0x2B4)), 0xB2);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B4), func_002b2a60(0x2D, 0x2D, 0x2D, 0xE5));
    func_002b6140((u8 *)(*(s32 *)(out + 0x2B4)), 1);
    func_002b6120((u8 *)(*(s32 *)(out + 0x2B4)), 1);
    *(s32 *)(out + 0x250) = func_0033e3f0((u8 *)(task));
    *(s32 *)(out + 0x2BC) = func_002b9f90(task, 0x30, func_00331600());
    return task;
}

/* One 10-byte combine row at task state +0xC4 (current row index at +0xB4). */
typedef struct {
    s16 state0;
    s16 state1;
    s16 id;
    s16 x;
    s16 y;
} FclCombineRow;

/* measured: 8604 executable bytes / 8608-byte window, verify MATCH, 287 relocations.
   Rewritten from the retail assembly.  The switch keeps retail's case order
   (MWCC tests the sparse labels in reverse); opt_lifetimes gives each loop
   index its own register as retail does; the second reward scan keeps its own
   selection local; row lookups use the 10-byte FclCombineRow at +0xC4. */
// FUN_002E90D0
#pragma push
#pragma opt_lifetimes on
void func_002e90d0(u8 *arg0)
{
    extern u8 D_00641870[];
    extern s32 func_00106330(s32);
    extern s32 func_0033e5a0(u8 *);
    extern void func_00315310(u8 *, s64);
    extern void func_00317410(u8 *, s8);
    extern void func_002ecfc0(u8 *);
    extern void func_00318f30(s16);
    extern void func_00318840(u8 *, s8, s8, s16, s16);
    extern s8 func_0032fb60(s8);
    extern void func_0032fa30(u8 *, s16, FclDrawColor, FclDrawColor, FclDrawColor);
    FclDrawColor color0;
    FclDrawColor color1;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    FclDrawColor color11;
    FclDrawColor color12;
    FclDrawColor color13;
    FclDrawColor color14;
    FclDrawColor color15;
    FclDrawColor color16;
    FclDrawColor color17;
    FclVec2 slotPos0;
    s32 msgArgs0[2];
    s32 msgArgs1[2];
    FclVec2 pos0;
    FclVec2 pos1;
    FclVec2 pos2;
    FclVec2 pos3;
    FclVec2 pos4;
    FclVec2 pos5;
    FclVec2 pos6;
    FclVec2 pos7;
    FclVec2 pos8;
    FclVec2 pos9;
    FclVec2 pos10;
    FclVec2 pos11;
    FclVec2 pos12;
    FclVec2 pos13;
    FclVec2 pos14;
    FclVec2 slotPos1;
    FclVec2 slotPos2;
    char text[0x88];
    s32 off;
    s8 selected2;
    s16 k2;
    s16 menu;
    u8 *te;
    s16 n;
    s8 *p;
    s8 selected;
    s16 j;
    FclVec2 *vec;
    u16 buttons;
    s16 k;
    u8 *entry;

    p = *(s8 **)(arg0 + 0x38);
    switch ((u8)p[1]) {
    case 0x11:
        p[1] = 0x12;
        break;
    case 0x12:
        p[1] = 0x14;
        if (func_00106330(0x131D) == 0) {
            p[0xD] = func_002bab80((void *)func_00331660());
            func_002badc0(p[0xD], 0x4C);
            func_00106390(0x131D, 1);
            p[1] = 0x13;
        }
        break;
    case 0x13:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        p[1] = 0x12;
        break;
    case 0x14:
        selected = -1;
        for (k = 0; k < 2; k++) {
            entry = D_00641870 + k * 8;
            if (func_00106330(*(s32 *)(entry + 4)) == 0) {
                if ((f32)*(s8 *)entry <= 100.0f * func_00109190()) {
                    selected = k;
                }
            }
        }
        p[0x13F] = selected;
        if (p[0x13F] != -1) {
            entry = D_00641870 + p[0x13F] * 8;
            p[0xD] = func_002bab80((void *)func_00331660());
            sprintf(text, &iGpffffa8a0, *(s8 *)entry);
            func_002bbd80(p[0xD], 0, text);
            if (func_00109190() >= 1.0f) {
                func_002badc0(p[0xD], 8);
            } else {
                func_002badc0(p[0xD], 7);
            }
            p[1] = 0x15;
        } else {
            p[1] = 0x17;
        }
        break;
    case 0x15:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        entry = D_00641870 + p[0x13F] * 8;
        p[0xD] = func_002bab80((void *)func_00331660());
        msgArgs0[0] = *(s16 *)(entry + 2);
        msgArgs0[1] = 0;
        func_002bbd80(p[0xD], 0, msgArgs0);
        func_002badc0(p[0xD], 9);
        func_00106620(*(s16 *)(entry + 2), (u8)((u8)func_00106600(*(s16 *)(entry + 2)) + 1));
        p[1] = 0x16;
        break;
    case 0x16:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        func_00106390(*(s32 *)(D_00641870 + p[0x13F] * 8 + 4), 1);
        selected2 = -1;
        for (k2 = 0; k2 < 2; k2++) {
            entry = D_00641870 + k2 * 8;
            if (func_00106330(*(s32 *)(entry + 4)) == 0) {
                if ((f32)*(s8 *)entry <= 100.0f * func_00109190()) {
                    selected2 = k2;
                }
            }
        }
        p[0x13F] = selected2;
        if (p[0x13F] == -1) {
            p[1] = 0x17;
            break;
        }
        entry = D_00641870 + p[0x13F] * 8;
        p[0xD] = func_002bab80((void *)func_00331660());
        msgArgs1[0] = *(s16 *)(entry + 2);
        msgArgs1[1] = 0;
        func_002bbd80(p[0xD], 0, msgArgs1);
        func_002badc0(p[0xD], 9);
        func_00106620(*(s16 *)(entry + 2), (u8)((u8)func_00106600(*(s16 *)(entry + 2)) + 1));
        break;
    case 0x17:
        if (func_0033e5a0(*(u8 **)(p + 0x250)) == 0) {
            break;
        }
        *(s32 *)(p + 0x148) = func_00314320(arg0);
        func_00320970(arg0, 0);
        func_00315310(arg0, 0);
        pos0 = func_002b2970(-78.0f, -82.0f);
        func_002b6c30(0x80, pos0, 220.0f, 0x3F);
        color0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x80) + 0x85) = color0;
        func_002b6b40(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
        func_002b68d0(0x80, 6, 0);
        func_002b6150(0x80)[0xDB] = 1;
        pos1 = func_002b2970(2.0f, -2.0f);
        pos2 = func_002b2970(-78.0f, -82.0f);
        func_002b69f0(0x80, pos1, pos2, 1, 0xA, 0);
        func_002b6a70(0x80, 0, 0xFF, 2, 0xA, 0);
        pos3 = func_002b2970(540.0f, (f32)0x15B);
        func_002b6c30(0x20C, pos3, 220.0f, 0x3F);
        color1 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x20C) + 0x85) = color1;
        func_002b6b40(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
        func_002b68d0(0x20C, 6, 0);
        func_002b6150(0x20C)[0xDB] = 1;
        pos4 = func_002b2970(460.0f, (f32)0x10B);
        pos5 = func_002b2970(540.0f, (f32)0x15B);
        func_002b69f0(0x20C, pos4, pos5, 1, 0xA, 0);
        func_002b6a70(0x20C, 0, 0xFF, 2, 0xA, 0);
        pos6 = func_002b2970(-190.0f, 200.0f);
        func_002b6c30(0x81, pos6, 215.0f, 0x56);
        color2 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x81) + 0x85) = color2;
        func_002b6a70(0x81, 0, 0xFF, 0, 0xA, 0);
        *(f32 *)(func_002b6150(0x81) + 0xD0) = 90.0f;
        vec = (FclVec2 *)D_00640C50;
        pos7 = func_002b2970(vec->x, vec->y);
        func_002b6c30(0x84, pos7, 217.0f, 0x40);
        func_002b6a70(0x84, 0, 0xFF, 0, 0xA, 0);
        vec = (FclVec2 *)D_00640C58;
        pos8 = func_002b2970(vec->x, vec->y);
        func_002b6c30(0x85, pos8, 218.0f, 0x40);
        func_002b6a70(0x85, 0, 0xFF, 0, 0xA, 0);
        func_00315600(arg0, 0);
        func_003205f0(arg0, 0x92, 0);
        func_00316e80(arg0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
        p[0x138] = 0;
        if (func_00106330(0x1305) != 0 && func_00106330(0x1308) == 0) {
            p[0x138] |= 2;
        }
        if (func_00302570(arg0) == 0) {
            p[1] = 0x18;
        }
        break;
    case 0x18:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1F4) + 0x10), 1) == 1) {
            break;
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1F6) + 0x10), 1) == 1) {
            break;
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1F8) + 0x10), 1) == 1) {
            break;
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1FA) + 0x10), 1) == 1) {
            break;
        }
        if (func_003190d0(arg0) == 1) {
            break;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            func_00317410(arg0, 1);
            break;
        }
        if (buttons & 0x4000) {
            func_00317410(arg0, 0);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            func_0045af60(0, 0, 0, 1);
            for (n = 0; n < 3; n++) {
                off = n * 2;
                pos9 = func_002b2970(26.0f, (f32)(n * 34 + 87));
                func_003147e0(arg0, n, pos9, *(s16 *)(p + off + 0xB8), (s16)off, 1);
            }
            switch (p[0xB3]) {
            case 0:
                if (func_00106330(0x131E) == 0) {
                    p[0xD] = func_002bab80((void *)func_00331660());
                    func_002badc0(p[0xD], 0x4D);
                    func_00106390(0x131E, 1);
                    p[1] = 0x22;
                } else {
                    func_002ecfc0(arg0);
                }
                break;
            case 1:
                if (func_00106330(0x131B) == 0) {
                    p[0xD] = func_002bab80((void *)func_00331660());
                    func_002badc0(p[0xD], 0x4F);
                    func_00106390(0x131B, 1);
                    p[1] = 0x21;
                } else {
                    vec = (FclVec2 *)D_00641660;
                    pos10 = func_002b2970(vec->x, vec->y);
                    func_002b6c30(0x1C6, pos10, 242.0f, 0x3D);
                    func_002b6a70(0x1C6, 0, 0x64, 0, 0xA, 0);
                    p[0xB6] = 0;
                    func_0032f4d0(arg0);
                    func_003205f0(arg0, 0x96, 0x92);
                    p[1] = 0x1B;
                }
                break;
            case 2:
                func_00315600(arg0, 1);
                func_00320970(arg0, 1);
                func_003205f0(arg0, 0, 0x92);
                func_00316e80(arg0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
                func_002b6a70(0x81, 0xFF, 0, 0, 6, 0);
                func_002b6a70(0x80, 0xFF, 0, 2, 0xA, 0);
                func_002b6a70(0x20C, 0xFF, 0, 2, 0xA, 0);
                func_002b6a70(0x84, 0xFF, 0, 0, 6, 0);
                func_002b6a70(0x85, 0xFF, 0, 0, 6, 0);
                for (n = 0; n < 3; n++) {
                    pos11 = func_002b2970(26.0f, (f32)(n * 34 + 87));
                    func_003147e0(arg0, n, pos11, *(s16 *)(p + n * 2 + 0xB8), 0, 1);
                }
                p[1] = 0x19;
                break;
            }
        } else if (buttons & 0x20) {
            func_00315600(arg0, 1);
            func_00320970(arg0, 1);
            func_003205f0(arg0, 0, 0x92);
            func_00316e80(arg0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
            func_002b6a70(0x81, 0xFF, 0, 0, 6, 0);
            func_002b6a70(0x80, 0xFF, 0, 2, 0xA, 0);
            func_002b6a70(0x20C, 0xFF, 0, 2, 0xA, 0);
            func_002b6a70(0x84, 0xFF, 0, 0, 6, 0);
            func_002b6a70(0x85, 0xFF, 0, 0, 6, 0);
            for (n = 0; n < 3; n++) {
                pos12 = func_002b2970(26.0f, (f32)(n * 34 + 87));
                func_003147e0(arg0, n, pos12, *(s16 *)(p + n * 2 + 0xB8), 0, 1);
            }
            p[1] = 0x19;
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 0x22:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        func_002ecfc0(arg0);
        break;
    case 0x21:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        vec = (FclVec2 *)D_00641660;
        pos13 = func_002b2970(vec->x, vec->y);
        func_002b6c30(0x1C6, pos13, 242.0f, 0x3D);
        func_002b6a70(0x1C6, 0, 0x64, 0, 0xA, 0);
        p[0xB6] = 0;
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x92);
        p[1] = 0x1B;
        break;
    case 0x19:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1F4) + 0x10), 1) == 1) {
            break;
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x92) + 0x10), 1) == 1) {
            break;
        }
        p[0] = 0xB;
        break;
    case 0x97:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        if (func_00302570(arg0) == 0) {
            p[1] = 0x18;
        }
        break;
    case 0x1A:
        if (func_003190d0(arg0) == 1) {
            break;
        }
        func_002b6140(*(u8 **)(p + 0x28C), 0);
        func_002b6140(*(u8 **)(p + 0x290), 0);
        buttons = D_008C027A[0];
        if (buttons & 0x8000) {
            p[0xB4] = func_002b2d00(p[0xB4], 1, 0, p[0xB5] - 1, 2);
            func_00318f30(((FclCombineRow *)(p + 0xC4))[p[0xB4]].id);
            func_0045af60(0, 0, 0, 0);
            for (n = 0; n < p[0xB5]; n++) {
                func_00318840(arg0, n, *(s16 *)(p + n * 10 + 0xC8), *(s16 *)(p + n * 10 + 0xCA), *(s16 *)(p + n * 10 + 0xCC));
            }
        } else if (buttons & 0x2000) {
            p[0xB4] = func_002b2cb0(p[0xB4], 1, p[0xB5] - 1, 0, 2);
            func_00318f30(((FclCombineRow *)(p + 0xC4))[p[0xB4]].id);
            func_0045af60(0, 0, 0, 0);
            for (n = 0; n < p[0xB5]; n++) {
                func_00318840(arg0, n, *(s16 *)(p + n * 10 + 0xC8), *(s16 *)(p + n * 10 + 0xCA), *(s16 *)(p + n * 10 + 0xCC));
            }
        } else {
            buttons = D_008C024E[0];
            if (buttons & 0x40) {
                func_002b68d0(0x2F2, 0, 1);
                func_0045af60(0, 0, 0, 1);
                if (((FclCombineRow *)(p + 0xC4))[p[0xB4]].id == 8) {
                    if (func_00302570(arg0) == 0) {
                        p[1] = 0x18;
                    }
                    func_002eb270(arg0, 1);
                    func_00315310(arg0, 0);
                    func_003205f0(arg0, 0x92, 0x96);
                    func_002b6a70(0x1C6, func_002b6150(0x1C6)[0x6E], 0, 0, 0xA, 0);
                } else {
                    p[1] = 0x1C;
                }
            } else if (buttons & 0x20) {
                func_002b68d0(0x2F2, 0, 1);
                if (func_00302570(arg0) == 0) {
                    p[1] = 0x18;
                }
                func_002eb270(arg0, 1);
                func_0045af60(0, 0, 0, 2);
                func_00315310(arg0, 0);
                func_003205f0(arg0, 0x92, 0x96);
                func_002b6a70(0x1C6, func_002b6150(0x1C6)[0x6E], 0, 0, 0xA, 0);
            }
        }
        break;
    case 0x1C:
        func_002eb270(arg0, 1);
        p[0] = ((FclCombineRow *)(p + 0xC4))[p[0xB4]].state0;
        p[1] = ((FclCombineRow *)(p + 0xC4))[p[0xB4]].state1;
        break;
    case 0x1B:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150((p[0xB7] + 3) * 2 + 0x1F4) + 0x10), 1) == 1) {
            break;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            func_0045af60(0, 0, 0, 0);
            menu = func_0032fb60(p[0xB6]);
            color3 = func_002b2a60(0, 0, 0x66, 0xFF);
            color4 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
            color5 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
            func_0032fa30(arg0, menu, color3, color4, color5);
            if (func_00106330(0x1306) != 0) {
                p[0xB6] = func_002b2d00(p[0xB6], 1, 0, (s16)(p[0xB7] - 2), 2);
            } else {
                p[0xB6] = func_002b2d00(p[0xB6], 1, 0, (s16)(p[0xB7] - 1), 2);
            }
            menu = func_0032fb60(p[0xB6]);
            color6 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
            color7 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            color8 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
            func_0032fa30(arg0, menu, color6, color7, color8);
            break;
        }
        if (buttons & 0x4000) {
            func_0045af60(0, 0, 0, 0);
            menu = func_0032fb60(p[0xB6]);
            color9 = func_002b2a60(0, 0, 0x66, 0xFF);
            color10 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
            color11 = func_002b2a60(0x25, 0x2F, 0x94, 0xFF);
            func_0032fa30(arg0, menu, color9, color10, color11);
            if (func_00106330(0x1306) != 0) {
                p[0xB6] = func_002b2cb0(p[0xB6], 1, (s16)(p[0xB7] - 2), 0, 2);
            } else {
                p[0xB6] = func_002b2cb0(p[0xB6], 1, (s16)(p[0xB7] - 1), 0, 2);
            }
            menu = func_0032fb60(p[0xB6]);
            color12 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
            color13 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
            color14 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
            func_0032fa30(arg0, menu, color12, color13, color14);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            func_0045af60(0, 0, 0, 1);
            if (p[0xB6] == p[0xB7] - 1) {
                for (j = 0; j < p[0xB7]; j++) {
                    slotPos0 = *(FclVec2 *)(func_002b6150((j + 4) * 2 + 0x1F4) + 0x38);
                    func_003147e0(arg0, j + 4, slotPos0, *(s16 *)(p + j * 2 + 0xB8), (s16)(j * 2), 1);
                }
                func_00315310(arg0, 3);
                func_003205f0(arg0, 0x92, 0x96);
                func_002b6a70(0x1C6, func_002b6150(0x1C6)[0x6E], 0, 0, 0xA, 0);
                if (func_00302570(arg0) == 0) {
                    p[1] = 0x18;
                }
            } else {
                for (j = 0; j < p[0xB7]; j++) {
                    slotPos2 = *(FclVec2 *)(func_002b6150((j + 4) * 2 + 0x1F4) + 0x38);
                    func_003147e0(arg0, j + 4, slotPos2, *(s16 *)(p + j * 2 + 0xB8), (s16)(j * 2), 1);
                }
                switch (p[0xB6]) {
                case 0:
                    ((u8 *)p)[1] = 0x8A;
                    p[0] = 0xF;
                    func_003205f0(arg0, 0x117, 0x96);
                    break;
                case 1:
                    ((u8 *)p)[1] = 0x8A;
                    p[0] = 0x10;
                    func_003205f0(arg0, 0x118, 0x96);
                    break;
                case 2:
                    if (func_00106330(0x1305) != 0) {
                        p[0] = 8;
                        p[1] = 0x75;
                    } else {
                        p[0] = 0xA;
                        ((u8 *)p)[1] = 0xC2;
                    }
                    break;
                case 3:
                    if (func_00106330(0x1305) != 0) {
                        p[0] = 0xA;
                        ((u8 *)p)[1] = 0xC2;
                    } else {
                        func_00315310(arg0, 3);
                        func_003205f0(arg0, 0x92, 0x96);
                        if (func_00302570(arg0) == 0) {
                            p[1] = 0x18;
                        }
                    }
                    break;
                case 4:
                    if (func_00106330(0x1305) != 0) {
                        func_00315310(arg0, 3);
                        func_003205f0(arg0, 0x92, 0x96);
                        if (func_00302570(arg0) == 0) {
                            p[1] = 0x18;
                        }
                    }
                    break;
                }
            }
        } else if (buttons & 0x20) {
            for (j = 0; j < p[0xB7]; j++) {
                slotPos1 = *(FclVec2 *)(func_002b6150((j + 4) * 2 + 0x1F4) + 0x38);
                func_003147e0(arg0, j + 4, slotPos1, *(s16 *)(p + j * 2 + 0xB8), (s16)(j * 2), 1);
            }
            func_00315310(arg0, 3);
            func_002b6a70(0x1C6, func_002b6150(0x1C6)[0x6E], 0, 0, 0xA, 0);
            func_003205f0(arg0, 0x92, 0x96);
            if (func_00302570(arg0) == 0) {
                p[1] = 0x18;
            }
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 0x20:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        for (j = 0; j < p[0xB7]; j++) {
            off = j * 2;
            pos14 = func_002b2970(26.0f, (f32)(j * 34 + 87));
            func_003147e0(arg0, j + 4, pos14, *(s16 *)(p + off + 0xB8), (s16)off, 0);
        }
        color15 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150((p[0xB6] + 4) * 2 + 0x1F5);
        *(FclDrawColor *)(te + 0x85) = color15;
        *(FclDrawColor *)(func_002b6150((p[0xB6] + 4) * 2 + 0x1F4) + 0x85) = *(FclDrawColor *)(te + 0x85);
        color16 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        *(FclDrawColor *)(func_002b6150(((s16 *)(p + 0xB8))[p[0xB6]]) + 0x85) = color16;
        color17 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
        *(FclDrawColor *)(func_002b6150(p[0xB6] + 0x2FF) + 0x85) = color17;
        p[1] = 0x1B;
        break;
    }
}
#pragma pop

/* One 12-byte slot of the combine layout tables at D_00640760 / D_006407C0. */
typedef struct {
    f32 x;
    f32 y;
    s16 col;
    s16 row;
} FclCombineLayoutSlot;

/* Layout 8 gives the consecutive left and right/central phases their own
   transition values. The real aggregate-return position temporaries remain
   at every placement. See docs/probe_archive/FclCombine_002eb270_20261004.md. */
// FUN_002EB270
void func_002eb270(u8 *task, s32 transition) {
    extern u8 D_006407F0[];
    FclCombineLayoutSlot *slot;
    u8 *work;
    s16 jitter;

    /* Only the signed low byte selects the transition: zero enters, every
       other value exits, and one also hides the six selection overlays. */
    work = *(u8 **)(task + 0x38);
    if (*(s8 *)(work + 0xB5) % 2 == 0) {
        if (*(s8 *)(work + 0xB5) == 6) {
            s32 transition6;
            s16 left6;

            for (left6 = 0, transition6 = (s8)transition; left6 < 3; left6++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (left6 + 1);
                if (transition6 == 0) {
                    func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 left6, left6 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + left6 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + left6 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 left6, left6 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407A8;
            if (transition6 == 0) {
                func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             8, 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xFC) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xFE) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             8, 1, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_0064079C;
            if (transition6 == 0) {
                func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             7, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             7, 3, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (transition6 == 0) {
                func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             6, 0xA, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             6, 5, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        } else if (*(s8 *)(work + 0xB5) == 8) {
            s32 leftTransition8;
            s32 rightTransition8;
            s16 left8;
            s16 right8;

            /* Each edge traversal owns its transition value. */
            for (left8 = 0, leftTransition8 = (s8)transition; left8 < 4; left8++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + left8;
                if (leftTransition8 == 0) {
                    func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 left8, left8 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + left8 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + left8 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 left8, left8 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            /* The left phase has finished; carry its mode into the right
               traversal and the remaining central placement. */
            for (right8 = 0, rightTransition8 = leftTransition8; right8 < 3; right8++) {
                slot = (FclCombineLayoutSlot *)D_00640760 + (7 - right8);
                if (rightTransition8 == 0) {
                    func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - right8, right8 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + (7 - right8) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + (7 - right8) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - right8, right8 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_00640790;
            if (rightTransition8 == 0) {
                func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             4, 0xE, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                             4, 7, slot->col * 3 + 0x3E, slot->row + 0x57);
            }
        }
    } else {
        if (*(s8 *)(work + 0xB5) == 5) {
            s32 transition5;
            s16 pair5;

            for (pair5 = 0, transition5 = (s8)transition; pair5 < 2; pair5++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (pair5 + 2);
                if (transition5 == 0) {
                    func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 pair5, pair5 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + pair5 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + pair5 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 pair5, pair5 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (6 - pair5);
                if (transition5 == 0) {
                    func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - pair5, pair5 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + (4 - pair5) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + (4 - pair5) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - pair5, pair5 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition5 == 0) {
                func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             6, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xDE) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xE0) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 6, 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (*(s8 *)(work + 0xB5) == 7) {
            s32 transition7;
            s16 pair7;

            for (pair7 = 0, transition7 = (s8)transition; pair7 < 3; pair7++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + (pair7 + 1);
                if (transition7 == 0) {
                    func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 pair7, pair7 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + pair7 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + pair7 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 pair7, pair7 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (7 - pair7);
                if (transition7 == 0) {
                    func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - pair7, pair7 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + (6 - pair7) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + (6 - pair7) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - pair7, pair7 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition7 == 0) {
                func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             3, 0xC, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xE8) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xEA) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 3, 6, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        } else if (*(s8 *)(work + 0xB5) == 9) {
            s32 transition9;
            s16 pair9;

            for (pair9 = 0, transition9 = (s8)transition; pair9 < 4; pair9++) {
                slot = (FclCombineLayoutSlot *)D_006407C0 + pair9;
                if (transition9 == 0) {
                    func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 pair9, pair9 * 4, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + pair9 * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + pair9 * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 pair9, pair9 * 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
                slot = (FclCombineLayoutSlot *)D_006407C0 + (8 - pair9);
                if (transition9 == 0) {
                    func_00317900(task, func_002b2970(700.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                                 8 - pair9, pair9 * 4 + 2, slot->col * 3 + 0x3E, slot->row + 0x57);
                    *(s16 *)(work + (8 - pair9) * 10 + 0xCA) = slot->col * 3 + 0x3E;
                    *(s16 *)(work + (8 - pair9) * 10 + 0xCC) = slot->row + 0x57;
                } else {
                    jitter = RpRandom() % 300 - 150;
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 8 - pair9, pair9 * 2 + 1, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
            slot = (FclCombineLayoutSlot *)D_006407F0;
            if (transition9 == 0) {
                func_00317900(task, func_002b2970(-200.0f, 100.0f + slot->y), func_002b2970(slot->x, slot->y),
                             4, 0x10, slot->col * 3 + 0x3E, slot->row + 0x57);
                *(s16 *)(work + 0xF2) = slot->col * 3 + 0x3E;
                *(s16 *)(work + 0xF4) = slot->row + 0x57;
            } else {
                jitter = RpRandom() % 300 - 150;
                if (RpRandom() % 100 >= 50) {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(-300.0f, slot->y + jitter),
                                 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                } else {
                    func_00317900(task, func_002b2970(slot->x, slot->y), func_002b2970(700.0f, slot->y + jitter),
                                 4, 8, slot->col * 3 + 0x3E, slot->row + 0x57);
                }
            }
        }
    }
    /* Each resource is looked up again after hiding it in retail. */
    if ((s8)transition == 1) {
        func_002b6150(0x216)[0x73] = 0;
        func_002b6150(0x216);
        func_002b6150(0x217)[0x73] = 0;
        func_002b6150(0x217);
        func_002b6150(0x218)[0x73] = 0;
        func_002b6150(0x218);
        func_002b6150(0x219)[0x73] = 0;
        func_002b6150(0x219);
        func_002b6150(0x21A)[0x73] = 0;
        func_002b6150(0x21A);
        func_002b6150(0x21B)[0x73] = 0;
        func_002b6150(0x21B);
    }
}


/* measured: full body now MATCH (object 1136B, retail window 1136B).
   The stack argument/global load is forced in retail order with the named
   FclVec2f base. Table stores use an integer-domain scaled offset so the
   addu has the retail offset-first operand order; direct byte increments
   preserve retail's store-before-next-index schedule. */
// FUN_002ECFC0
void func_002ecfc0(u8 *arg0) {
    FclVec2 sp38;
    u8 *temp_16;
    FclVec2f *base;

    temp_16 = *(u8 **)(arg0 + 0x38);
    base = (FclVec2f *)D_00641660;
    sp38 = func_002b2970(base->x, base->y);
    func_002b6c30(0x1C6, sp38, 242.0f, 0x3D);
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
    if (datGetFlag(0x1301) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 3;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 2;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (datGetFlag(0x1302) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 4;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 3;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (datGetFlag(0x1303) != 0) {
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC4) = 5;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC6) = 0x51;
        *(s16 *)((u8 *)(*(s8 *)(temp_16 + 0xB5) * 10) + (u32)temp_16 + 0xC8) = 4;
        *(s8 *)(temp_16 + 0xB5) = *(s8 *)(temp_16 + 0xB5) + 1;
    }
    if (datGetFlag(0x1304) != 0) {
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
/* measured 002ed430 2026-09-19: object 3816 against retail's 3764 instructions, +1.38% inside the 3651-3877 band with
   61 instructions of headroom; 2865 fnalign edits (+10 reloc-only), 3139 differing words.
   No pragmas: retail here is unscheduled like the rest of this unit.
   Built from the m2c oracle from src/generated/code1_002e.c de-noised to this file's idiom - M2C_FIELD expanded to direct
   casts, the gp temporaries resolved to ((s32)iGpffffb440) and ((s32)iGpffffb3d4), the six M2C_ERROR
   ldr/ldl sites written as struct-by-value `*(FclVec2f *)(ps + 0x38)` with `ps = func_002b6150(0x151/0x2E0)`,
   the 11 colour bases with their M2C_UNK companions folded to u8 colXXX[4] (`&sp` -> col, `sp` -> col[0],
   `(s32)sp` -> (*(s32 *)col)), the (s32)(sp)+0x110/0xF0 stores rewritten as sp110[]/spF0[] (u16[16]),
   37 s64 temporaries narrowed to s32 (3963 -> 3659) with four - var_16, var_16_2, var_16_3, var_17_2 - kept s64
   to land 3659 inside the band, the switch-3 labels restored as case 0-2 (retail jtbl, +157 to 3816, still inside),
   the m2c arg-count hallucinations on func_002b6150/func_0010b5b0/func_003190d0/func_00314660/func_002b6970/
   func_002bb680/func_00122720 cut back to the retail arg counts, the (f32)(s32) float wrappers collapsed
   (0x437F0000->255.0f, 0x43000000->128.0f, 0x422C0000->43.0f), and D_008C027A/024E to [0]. */
/* measured 002ed430 (owner, 2026-09-19): fnalign **2865 -> 2856 edits**, count
   3816 -> 3814 against retail 3764, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 002ed430 (2026-09-20): deficit_scan first per assignment - retail 3764 vs object 3814 (+50, +1.3% INSIDE) so deficit -50 and every retail-only run is CROSS (227 at 0x002efe74, 103 at 0x002ef934, 98 at 0x002eea48, all > deficit). Opcode delta BOTH directions: retail has more lb +22/bnez +12/addu +12, object has more dsll32 +43/dsra32 +42/mtc1 +16/mov.s +10/lui +7/cvt.s.w +5 - the surplus names double-extends + float conversions, as on func_0026a020 (mul.s/lui/mtc1 vs add.s doubling idiom, -66 there). Fixed: func_00275820 (f32x3->s32x3, 7 calls, each saved mtc1/lui/cvt), func_002b2aa0 (s32,s32->s32,f32 + 0->0.0f at both calls), func_002b68d0 (s32->s16 first), var_16/var_16_2/var_16_3/var_17_2 s64->s16 with (s8)/(s16) loop rewrites, *func_002e4870 u8->s8 (3 sites + 0xD), and 38x (s64)(<<0x30/0x38) to (s16)/(s8) for 0x128+1/00314660/002b6150 narrow params. fnalign **2856 -> 2559 edits** (-297, +31 reloc-only), count **3814 -> 3693** (-121) vs retail 3761 trimmed (-68, -1.8% INSIDE 3648-3874). Remaining retail dsll32 +19/dsra32 +20 vs object addiu +41/move +14 are CROSS (all long runs still > deficit 68), no ABSENT. */
/* measured: 15048 executable bytes / 15056B retail window, zero differing words.
   Keys: the colour branches of state 0x2A build their 0x270 sprite id as an
   unsigned sum, so it is not CSE'd with the alpha lookup's id and its spill
   gives retail's 0x260 frame; func_00275820 uses its real (f32 x, f32 y,
   f32 scale, ...) signature; `> 5` for the menu range test; store-then-reread
   of f11E/f2FA; func_003144d0 takes the slot byte as s8. */
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA4];
    s8 fB2;
    u8 padB3[0x6B];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    u8 *f148;
    u8 pad14C[0x3C];
    s32 f188;
    u8 pad18C[0x100];
    u8 *f28C;
    u8 *f290;
    u8 pad294[0x28];
    s32 f2BC;
    u8 pad2C0[0x39];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineWork;

typedef struct {
    u8 pad0[0x2E4];
    s8 f2E4;
} FclPartySlot;

/* measured: 15048B/window 15056B, eight zero alignment bytes. See
   docs/probe_archive/FclCombine_002ed430_recovery_20260925.md. */
// FUN_002ED430
void func_002ed430(u8 *arg0) {
    extern void func_00313800(s8);
    extern f32 D_00640E70[];
    s16 var_19_3;
    u8 *ps;
    FclDrawColor col25C;
    FclDrawColor col258;
    FclDrawColor col254;
    FclDrawColor col250;
    FclDrawColor col24C;
    FclDrawColor col248;
    FclDrawColor col244;
    FclDrawColor col240;
    FclDrawColor col23C;
    FclDrawColor col238;
    FclDrawColor col234;
    FclPackedPosition sp228;
    FclVec2 sp220;
    FclPackedPosition sp218;
    FclPackedPosition sp210;
    FclVec2 sp208;
    FclVec2 sp200;
    FclPackedPosition sp1F8;
    FclPackedPosition sp1F0;
    FclVec2 sp1E8;
    FclVec2 sp1E0;
    FclPackedPosition sp1D8;
    FclPackedPosition sp1D0;
    FclVec2 sp1C8;
    FclPackedPosition sp1C0;
    FclPackedPosition sp1B8;
    FclPackedPosition sp1B0;
    FclVec2 sp1A8;
    FclVec2 sp1A0;
    FclVec2 sp198;
    FclVec2 sp190;
    FclVec2 sp188;
    FclVec2 sp180;
    FclPackedPosition sp178;
    FclPackedPosition sp170;
    FclVec2 sp168;
    FclVec2 sp160;
    FclVec2f sp158;
    FclVec2f sp150;
    FclVec2f sp148;
    FclVec2f sp140;
    FclVec2f sp138;
    u16 sp110[16];
    u16 spF0[16];
    u8 spE0;
    s32 spD0;
    s8 var_16_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_2_3;
    s16 *temp_2;
    s16 temp_16_8;
    s16 temp_2_21;
    s32 temp_16_12;
    s32 temp_16_13;
    s32 temp_16_14;
    s32 temp_16_18;
    s32 temp_16_21;
    s32 temp_16_23;
    s32 temp_16_24;
    s32 temp_16_25;
    s32 temp_16_26;
    s32 temp_16_28;
    s32 temp_16_2;
    s32 temp_16_31;
    s32 temp_16_32;
    s32 temp_16_33;
    s32 temp_16_35;
    s32 temp_16_39;
    s32 temp_16_4;
    s32 var_17;
    s32 var_21;
    s32 var_3;
    s32 var_3_2;
    s32 temp_16;
    s32 temp_16_19;
    s32 temp_16_46;
    s32 temp_16_52;
    s32 temp_16_5;
    s32 temp_17;
    s32 temp_17_14;
    s32 temp_17_15;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_19_5;
    s32 temp_19_6;
    s32 temp_19_7;
    s16 temp_19_9;
    s32 temp_20;
    s32 temp_20_3;
    s32 temp_21;
    s32 temp_21_2;
    s32 temp_21_3;
    s32 temp_22;
    s32 temp_22_2;
    s32 temp_23;
    s32 temp_30;
    s16 var_16;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_5;
    s16 var_16_6;
    s16 var_17_2;
    s16 var_17_3;
    s16 var_17_4;
    s16 var_17_5;
    s16 var_17_6;
    s16 var_17_7;
    s16 var_17_8;
    s16 temp_19_10;
    s16 var_17_9;
    s16 var_19;
    s16 var_19_2;
    s8 temp_16_29;
    s8 temp_16_36;
    s8 temp_2_17;
    s8 temp_4;
    s8 temp_4_2;
    s8 var_4;
    u16 *temp_16_48;
    u16 *temp_16_54;
    u16 *temp_17_10;
    u16 *temp_17_11;
    u16 *temp_17_9;
    s32 temp_16_11;
    s32 temp_16_15;
    s32 temp_16_41;
    u16 temp_16_42;
    u16 temp_16_43;
    u16 temp_16_47;
    u16 temp_16_49;
    u16 temp_16_53;
    s32 temp_16_6;
    s32 temp_16_9;
    u32 temp_16_44;
    u32 temp_16_45;
    u8 temp_16_17;
    s32 temp_16_22;
    s32 temp_16_27;
    s32 temp_16_34;
    u8 temp_16_38;
    u8 temp_16_3;
    u8 temp_16_50;
    s32 temp_16_51;
    s32 temp_17_13;
    s32 temp_20_2;
    u8 temp_3;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_7;
    FclPartySlot *temp_16_20;
    FclPartySlot *temp_16_30;
    FclPartySlot *temp_16_37;
    FclCombineWork *temp_17_12;
    FclCombineWork *temp_17_3;
    FclCombineWork *temp_17_8;
    FclCombineWork *temp_18;
    u8 slotByte;
    s32 slotMode;
    FclVec2f *basePos;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_22;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_18 = *(FclCombineWork **)(arg0 + 0x38);
    temp_3 = (u8)((u8)((u8)(temp_18->f1)));
    switch (temp_3) {                               /* switch 1 */
    case 0x23:                                      /* switch 1 */
        func_002e4610(1, 0);
        func_002e4610(0xA, 1);
        func_002e4610(0xA, 2);
        func_002e4610(0xA, 3);
        func_002e4610(0xA, 4);
        func_002e4610(0xA, 5);
        func_002e4610(0xA, 6);
        func_002e4610(0xA, 7);
        func_002e4610(0xA, 8);
        func_002e4610(0xA, 9);
        func_002e4610(0xA, 0xA);
        func_002e4610(0xA, 0xB);
        func_002e4610(0xA, 0xC);
        func_002e4610(0, 0xD);
        func_00315600(arg0, 1);
        temp_18->f1 = 0x24U;
        return;
    case 0x24:
        if (func_003190d0(arg0) != 1 && *(s8 *)func_002e4870(0) == 1 && *(s8 *)func_002e4870(1) == 1
            && *(s8 *)func_002e4870(2) == 1 && *(s8 *)func_002e4870(0xD) == 1) {
            for (var_16 = 0; var_16 < (func_0010b5b0() & 0xFFFF); var_16++) {
                col25C = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)temp_18->f188, var_16) + 0x75) = col25C;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00320b80(arg0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_18->f129 = -1;
            temp_18->f1 = 0x25;
        }
        break;
    case 0x25:                                      /* switch 1 */
        func_003212e0(arg0, 0x27, 0);
        return;
    case 0x26:
        for (var_19 = 0; var_19 < (func_0010b5b0() & 0xFFFF); var_19++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(var_19 + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)*(s16 *)(func_002b6150(var_19 + 0x21C) + 0x40));
            if (temp_18->f11E == var_19) {
                var_17 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_17 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (var_19 < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(var_19 * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_17, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, var_19))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 0
            && (s16)func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_003205f0(arg0, 0x96, 0x93);
            func_002eb270(arg0, 0);
            func_00315600(arg0, 0);
            temp_18->f0 = 0;
            temp_18->f1 = 0x1A;
        }
        break;
    case 0x27:                                      /* switch 1 */
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) > 5) {
            func_00321e60(arg0, 0, 0x2A, 0x26);
            return;
        }
        break;
    case 0x28:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1))))) != (s32)((s32)(1))) {
            func_00314450(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f11E))), 0, 0);
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            temp_16_2 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
            func_0011d140((u8 *)temp_16_2, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_18->f1 = 0x29U;
            return;
        }
        break;
    case 0x29:
        if ((s8)func_00314660(temp_18->f148) == 5) {
            if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 0) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                } else {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                } else {
                    if ((s8)func_00314660(temp_18->f148) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(temp_18->f148, 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) > 5) {
            for (var_16_2 = 0; var_16_2 < (func_0010b5b0() & 0xFFFF); var_16_2++) {
                sp228.position = func_002b2970(16.0f, 128.0f);
                func_003191c0(arg0, sp228.position, (s8)(var_16_2), ((u16 *)func_002e48a0(0, var_16_2))[1], *(u8 *)((u8 *)((u16 *)func_002e48a0(0, var_16_2)) + 4), 0, 0, (s64)(*(s8 *)(func_002e4870(0) + 8)));
            }
            sp220 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp220, 0, 0, 0, 0, 0);
            func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_003218a0(arg0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x27;
        }
        break;
    case 0x2A:
        temp_16_3 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_3 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_2 = func_002b6150(0x7C);
        sp158 = *(FclVec2f *)(temp_2_2 + 0x38);
        temp_16_4 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_3);
        func_00275820(111.0f + sp158.x, sp158.y, 43.0f, temp_16_4, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, temp_17_3->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        for (var_19_2 = 0; var_19_2 < (func_0010b5b0() & 0xFFFF); var_19_2++) {
            func_0031d630(arg0, var_19_2, temp_18->f128, temp_18->f129, 0);
            if (temp_18->f128 != var_19_2 && *(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) > 0) {
                temp_23 = var_19_2 + 0x270;
                temp_f20_2 = (f32)*(s16 *)(func_002b6150(temp_23) + 0x42);
                spE0 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20_2, (f32)*(s16 *)(func_002b6150(temp_23) + 0x40));
                if (var_19_2 == temp_18->f11E) {
                    temp_30 = var_19_2 + 0x27D;
                    /* Unsigned: retail recomputes this id per colour branch instead of
                       reusing temp_23, and the resulting spill sets the 0x260 frame. */
                    spD0 = var_19_2 + 0x270U;
                    *(u8 *)(func_002b6150(spD0) + 0x6E) = *(u8 *)(func_002b6150(temp_30) + 0x6E) = 0xFF;
                    col258 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    temp_2_4 = func_002b6150(var_19_2 + 0x297);
                    *(FclDrawColor *)(temp_2_4 + 0x85) = col258;
                    temp_2_5 = func_002b6150(var_19_2 + 0x28B);
                    *(FclDrawColor *)(temp_2_5 + 0x85) = *(FclDrawColor *)(temp_2_4 + 0x85);
                    temp_2_6 = func_002b6150(temp_30);
                    *(FclDrawColor *)(temp_2_6 + 0x85) = *(FclDrawColor *)(temp_2_5 + 0x85);
                    *(FclDrawColor *)(func_002b6150(spD0) + 0x85) = *(FclDrawColor *)(temp_2_6 + 0x85);
                    col254 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col254;
                    col250 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970((u8 *)temp_18->f2BC, (s8)(var_19_2 + 0xC), col250);
                    var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, spE0);
                    if (*(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) == 2) {
                        func_002b68d0(0xCF, 0, 1);
                        func_002b68d0(0xD2, 0, 1);
                        func_002b68d0(temp_23, 0, 0);
                        func_002b68d0(temp_30, 0, 0);
                    }
                } else if (*(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + var_19_2 + 0x14) == 2) {
                    temp_21_2 = var_19_2 + 0x27D;
                    temp_22 = var_19_2 + 0x270U;
                    *(u8 *)(func_002b6150(temp_22) + 0x6E) = *(u8 *)(func_002b6150(temp_21_2) + 0x6E) = 0;
                    col24C = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
                    temp_2_9 = func_002b6150(temp_21_2);
                    *(FclDrawColor *)(temp_2_9 + 0x85) = col24C;
                    *(FclDrawColor *)(func_002b6150(temp_22) + 0x85) = *(FclDrawColor *)(temp_2_9 + 0x85);
                    col248 = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col248;
                    col244 = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                    func_002ba970((u8 *)temp_18->f2BC, (s8)(var_19_2 + 0xC), col244);
                    var_21 = func_002b2a30(0xFF, 0xCC, 0xFA, spE0);
                    func_002b68d0(0xCF, 0, 0);
                    func_002b68d0(0xD2, 0, 0);
                } else {
                    temp_21_3 = var_19_2 + 0x27D;
                    temp_22_2 = var_19_2 + 0x270U;
                    *(u8 *)(func_002b6150(temp_22_2) + 0x6E) = *(u8 *)(func_002b6150(temp_21_3) + 0x6E) = 0xCC;
                    col240 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_12 = func_002b6150(temp_21_3);
                    *(FclDrawColor *)(temp_2_12 + 0x85) = col240;
                    *(FclDrawColor *)(func_002b6150(temp_22_2) + 0x85) = *(FclDrawColor *)(temp_2_12 + 0x85);
                    col23C = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_14 = func_002b6150(var_19_2 + 0x297);
                    *(FclDrawColor *)(temp_2_14 + 0x85) = col23C;
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x28B) + 0x85) = *(FclDrawColor *)(temp_2_14 + 0x85);
                    col238 = func_002b2a60(0, 0, 0x66, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_2 + 0x2A3) + 0x85) = col238;
                    col234 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970((u8 *)temp_18->f2BC, (s8)(var_19_2 + 0xC), col234);
                    var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, spE0);
                }
                temp_f20_2 = (f32)(var_19_2 * 0x17 + 0x80);
                func_00275820((f32)0x195, temp_f20_2, 43.0f, var_21, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(temp_18->f128 + 1, var_19_2))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) > 5) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1C7) + 0x10), 0) == 1) {
                func_00324410(arg0, 0x1C7, 0);
                func_00324410(arg0, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                temp_18->f11E = (s8)func_002b2d00(temp_18->f11E, 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
                func_0045af60(0, 0, 0, 0);
            } else if (D_008C027A[0] & 0x4000) {
                temp_18->f11E = (s8)func_002b2cb0(temp_18->f11E, 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 2);
                func_0045af60(0, 0, 0, 0);
            } else if (D_008C024E[0] & 0x40) {
                if (temp_18->f128 != temp_18->f11E && *(s8 *)(func_002e4870(0) + temp_18->f128 * 0xC + temp_18->f11E + 0x14) > 0) {
                    func_0045af60(0, 0, 0, 1);
                    for (var_17_2 = 0; var_17_2 < (func_0010b5b0() & 0xFFFF); var_17_2++) {
                        sp218.position = func_002b2970((f32)0x149, 128.0f);
                        temp_16_6 = ((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_2))[1];
                        slotByte = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_2)) + 4);
                        func_0031ac10(arg0, sp218.position, temp_18->f128, var_17_2, temp_16_6, slotByte, 0, 1, 1, 0xCC);
                        sp210.position = func_002b2970(16.0f, 128.0f);
                        func_003191c0(arg0, sp210.position, (s8)(var_17_2), ((u16 *)func_002e48a0(0, var_17_2))[1], *(u8 *)((u8 *)((u16 *)func_002e48a0(0, var_17_2)) + 4), 0, 1, (s64)(*(s8 *)(func_002e4870(0) + 8)));
                    }
                    sp208 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp208, 0, 1, 0, 0, 0);
                    sp200 = func_002b2970((f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp200, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0.0f);
                    func_002b6140(temp_18->f28C, 1);
                    func_002b6140(temp_18->f290, 1);
                    temp_18->f1 = 0x2E;
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (D_008C024C[0] & 0x80) {
                if (temp_18->f11E < *(s32 *)(func_002e4870(0) + 8)) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_17_3 = 0; var_17_3 < (func_0010b5b0() & 0xFFFF); var_17_3++) {
                        sp1F8.position = func_002b2970((f32)0x149, 128.0f);
                        temp_16_9 = ((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_3))[1];
                        slotByte = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_3)) + 4);
                        func_0031ac10(arg0, sp1F8.position, temp_18->f128, var_17_3, temp_16_9, slotByte, 0, 1, 1, 0xCC);
                        sp1F0.position = func_002b2970(16.0f, 128.0f);
                        func_003191c0(arg0, sp1F0.position, (s8)(var_17_3), ((u16 *)func_002e48a0(0, var_17_3))[1], *(u8 *)((u8 *)((u16 *)func_002e48a0(0, var_17_3)) + 4), 0, 1, (s64)(*(s8 *)(func_002e4870(0) + 8)));
                    }
                    sp1E8 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1E8, 0, 1, 0, 0, 0);
                    sp1E0 = func_002b2970((f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp1E0, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140(temp_18->f28C, 1);
                    func_002b6140(temp_18->f290, 1);
                    temp_18->f1 = 0x2B;
                }
            } else if (D_008C024E[0] & 0x20) {
                func_0031ddf0(arg0, (s8)temp_18->f11E, 0, 0xFF);
                temp_18->f11E = temp_18->f128;
                func_0031ddf0(arg0, temp_18->f11E, 1, 0xFF);
                func_0045af60(0, 0, 0, 2);
                func_003205f0(arg0, 0x93, 0x94);
                basePos = (FclVec2f *)D_00640C10;
                sp1D8.position = func_002b2970(basePos->x, basePos->y);
                sp1D0.position = func_002b2970(-380.0f, basePos->y);
                func_0031c2b0(arg0, temp_18->f128, sp1D8.position, sp1D0.position);
                sp1C8 = func_002b2970((f32)0x149, 104.0f);
                func_0031fa20(arg0, sp1C8, 0, 1);
                for (var_17_4 = 0; var_17_4 < (func_0010b5b0() & 0xFFFF); var_17_4++) {
                    sp1C0.position = func_002b2970((f32)0x149, 128.0f);
                    temp_16_11 = ((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_4))[1];
                    slotByte = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_4)) + 4);
                    func_0031ac10(arg0, sp1C0.position, temp_18->f128, var_17_4, temp_16_11, slotByte, 0, 1, 1, 0xCC);
                }
                func_003218a0(arg0, 3);
                temp_18->f1 = 0x27;
            }
        }
        break;
    case 0x2B:
        temp_2_18 = func_002b6150(0x7C);
        sp150 = *(FclVec2f *)(temp_2_18 + 0x38);
        temp_16_12 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
        func_00275820(111.0f + sp150.x, sp150.y, 43.0f, temp_16_12, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, temp_18->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            func_00314450(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f11E))), 0, 0);
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            temp_16_13 = (s32)func_003147d0(temp_18->f148);
            func_0011d140((u8 *)temp_16_13, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            temp_18->f1 = 0x2C;
        }
        break;
    case 0x2C:
        temp_2_19 = func_002b6150(0x7C);
        sp148 = *(FclVec2f *)(temp_2_19 + 0x38);
        temp_16_14 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
        func_00275820(111.0f + sp148.x, sp148.y, 43.0f, temp_16_14, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, temp_18->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660(temp_18->f148) == 5) {
            if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x80) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 0) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                } else {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0(temp_18->f148)) == 1) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                } else {
                    if ((s8)func_00314660(temp_18->f148) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(temp_18->f148, 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if ((s8)func_00314660(temp_18->f148) < 0 || (s8)func_00314660(temp_18->f148) > 5) {
            for (var_17_5 = 0; var_17_5 < (func_0010b5b0() & 0xFFFF); var_17_5++) {
                sp1B8.position = func_002b2970((f32)0x149, 128.0f);
                temp_16_15 = ((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_5))[1];
                slotByte = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_5)) + 4);
                func_0031ac10(arg0, sp1B8.position, temp_18->f128, var_17_5, temp_16_15, slotByte, 0, 0, 1, 0xCC);
                sp1B0.position = func_002b2970(16.0f, 128.0f);
                func_003191c0(arg0, sp1B0.position, (s8)(var_17_5), ((u16 *)func_002e48a0(0, var_17_5))[1], *(u8 *)((u8 *)((u16 *)func_002e48a0(0, var_17_5)) + 4), 0, 0, (s64)(*(s8 *)(func_002e4870(0) + 8)));
            }
            sp1A8 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp1A8, 0, 0, 0, 0, 0);
            sp1A0 = func_002b2970((f32)0x149, 104.0f);
            func_0031fa20(arg0, sp1A0, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x2A;
        }
        break;
    case 0x2E:
        temp_16_17 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_8 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_20 = func_002b6150(0x7C);
        sp140 = *(FclVec2f *)(temp_2_20 + 0x38);
        temp_16_18 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_17);
        func_00275820(111.0f + sp140.x, sp140.y, 43.0f, temp_16_18, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, temp_17_8->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_18->f2FA = temp_18->f11E;
            temp_16_19 = temp_18->f2FA;
            temp_17_9 = ((u16 *)func_002e48a0(temp_18->f2F9, temp_16_19));
            temp_16_20 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_19);
            temp_19_5 = (s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))[1] * 14 + 2]);
            slotMode = func_00311930(temp_19_5, (u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))), 0);
            func_003144d0(temp_18->f148, (s32)(temp_17_9), temp_16_20->f2E4, slotMode, 1);
            temp_16_21 = (s32)func_003147d0(temp_18->f148);
            func_0011d140((u8 *)temp_16_21, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            temp_16_22 = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA)) + 4);
            if ((func_00104c70(1) & 0xFF) < temp_16_22) {
                temp_16_23 = (s32)func_003147d0(temp_18->f148);
                func_0011d140((u8 *)temp_16_23, func_002b2a30(0x14, 0x14, 0x14, 0xFF));
            }
            func_0011c6e0(func_003147d0(temp_18->f148), 1);
            func_00325450(arg0, 3, 0);
            temp_18->f1 = 0x2D;
        }
        break;
    case 0x2D:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) == (s32)((s32)(0xD))) {
            if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0(temp_18->f148));
            }
            if (D_008C024E[0] & 0x40) {
                temp_18->f1 = 0x2FU;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0(temp_18->f148));
                    func_00314740(temp_18->f148, 0);
                    return;
                }
                func_0011c6e0(func_003147d0(temp_18->f148), 1);
                func_00314740(temp_18->f148, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0(temp_18->f148)))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0(temp_18->f148), 1);
                    func_00314740(temp_18->f148, 1);
                    return;
                }
                temp_18->f1 = 0x35U;
                func_00314670(temp_18->f148, 0xB);
                func_00325450(arg0, 3, 1);
                func_00317240(arg0, 1, 0.0f);
                func_0045af60(0, 0, 0, 2);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (temp_18->f122 != 2) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_18->f122 = (s8)((s8)(func_002b2cb0(temp_18->f122, 1, 2, 0, 1)));
                ps = func_002b6150(0x151);
                sp198 = func_002b2970((f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), sp198, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                sp190 = func_002b2970((f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), sp190, 1, 4, 0);
                temp_4 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    temp_16_24 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_24, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 2 */
                    temp_16_25 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_25, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f11E))), 0, 0, 1);
                    return;
                case 2:                             /* switch 2 */
                    temp_16_26 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_26, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_27 = (u8)((u8)((u8)((*(u8 *)((u8 *)(((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA)))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_27))) {
                        temp_16_28 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_28, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_29 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_10 = (u16 *)(((u16 *)func_002e48a0(temp_18->f2F9, temp_16_29)));
                    temp_16_30 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_29);
                    temp_19_6 = (s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_6, (u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))), 0);
                    func_003144d0(temp_18->f148, (s32)(temp_17_10), temp_16_30->f2E4, slotMode, 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (temp_18->f122 != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_18->f122 = (s8)((s8)(func_002b2d00(temp_18->f122, 1, 0, 2, 1)));
                ps = func_002b6150(0x151);
                sp188 = func_002b2970((f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), sp188, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                sp180 = func_002b2970((f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), sp180, 1, 4, 0);
                temp_4_2 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4_2) {                 /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_31 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_31, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_32 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, (s32)(((u16 *)func_002e48a0(0, temp_18->f11E))), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_33 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_34 = (u8)((u8)((u8)((*(u8 *)((u8 *)(((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA)))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_34))) {
                        temp_16_35 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_35, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_36 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_11 = (u16 *)(((u16 *)func_002e48a0(temp_18->f2F9, temp_16_36)));
                    temp_16_37 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_36);
                    temp_19_7 = (s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_7, (u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))), 0);
                    func_003144d0(temp_18->f148, (s32)(temp_17_11), temp_16_37->f2E4, slotMode, 1);
                    return;
                }
            }
        }
        break;
    case 0x35:
        temp_16_38 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
        temp_17_12 = *(FclCombineWork **)(arg0 + 0x38);
        temp_2_22 = func_002b6150(0x7C);
        sp138 = *(FclVec2f *)(temp_2_22 + 0x38);
        temp_16_39 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_38);
        func_00275820(111.0f + sp138.x, sp138.y, 43.0f, temp_16_39, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, temp_17_12->f128))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660(temp_18->f148) == 0xE) {
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_18->f129 = -1;
            for (var_17_6 = 0; var_17_6 < (func_0010b5b0() & 0xFFFF); var_17_6++) {
                sp178.position = func_002b2970(16.0f, 128.0f);
                func_003191c0(arg0, sp178.position, (s8)(var_17_6), ((u16 *)func_002e48a0(0, var_17_6))[1], *(u8 *)((u8 *)((u16 *)func_002e48a0(0, var_17_6)) + 4), 0, 0, (s64)(*(s8 *)(func_002e4870(0) + 8)));
                sp170.position = func_002b2970((f32)0x149, 128.0f);
                temp_16_41 = ((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_6))[1];
                slotByte = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f128 + 1, var_17_6)) + 4);
                func_0031ac10(arg0, sp170.position, temp_18->f128, var_17_6, temp_16_41, slotByte, 0, 0, 1, 0xCC);
            }
            sp168 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp168, 0, 0, 0, 0, 0);
            sp160 = func_002b2970((f32)0x149, 104.0f);
            func_0031fa20(arg0, sp160, 0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x2A;
        }
        break;
    case 0x2F:
        temp_16_42 = ((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))[1];
        temp_17_13 = *(u8 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA)) + 4);
        if ((func_00104c70(1) & 0xFF) < temp_17_13) {
            func_00310960(arg0, 0x26, 0);
            temp_18->f1 = 0x31;
        } else if (func_002e53b0(0, (s32)(*(s16 *)((u8 *)((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA)) + 2))) == 1) {
            func_00310960(arg0, 0x27, 0);
            temp_18->f1 = 0x31;
        } else {
            if (func_00105f50(temp_16_42) == 0) {
                func_00310a10(arg0, temp_16_42);
            } else {
                func_00310960(arg0, (s8)(func_00105f50(temp_16_42) + 0x2E), 1);
            }
            temp_18->f1 = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((s8)(temp_18->fD)))) != (s32)((s32)(0))) {
            func_002bbcf0((s8)(temp_18->fD));
            return;
        }
        if ((s32)((s32)(func_002bb1c0(temp_18->fD))) == (s32)((s32)(0))) {
            temp_18->f1 = 0x33U;
            func_00122520(1, 0xA);
        } else {
            temp_18->f1 = 0x2DU;
        }
        func_002bb550((s8)(temp_18->fD));
        return;
    case 0x31:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((s8)(temp_18->fD)))) != (s32)((s32)(0))) {
            func_002bbcf0((s8)(temp_18->fD));
            return;
        }
        func_002bb550((s8)(temp_18->fD));
        temp_18->f1 = 0x2DU;
        return;
    case 0x33:                                      /* switch 1 */
        if ((s32)((s32)(func_00122720())) != (s32)((s32)(0))) {
            func_00314670(temp_18->f148, 0xB);
            func_00314680(temp_18->f148);
            func_00325450(arg0, 3, 1);
            for (var_16_3 = 0; var_16_3 < 0x30C; var_16_3++) {
                func_002b68d0(var_16_3, 0, 1);
            }
            temp_18->f1 = 0x32U;
            return;
        }
        break;
    case 0x32:                                      /* switch 1 */
        if ((s32)((s32)(((s8)(func_00314660(temp_18->f148))))) == (s32)((s32)(0xE))) {
            temp_18->f1 = 0x34U;
            return;
        }
        break;
    case 0x34:                                      /* switch 1 */
        var_16_4 = 2;
        if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18->f128 * 0xC) + temp_18->f11E))+(0x14))) == 2) {
            var_16_4 = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(func_00312bc0(var_16_4))) == (s32)((s32)(1))) {
                if (RpRandom() % 1000U < 0x1F4U) {
                    temp_18->f1 = 0x36U;
                    temp_18->fB2 = 1;
                    return;
                }
                temp_18->f1 = 0x37U;
                temp_18->fB2 = 2;
                return;
            }
            temp_18->fB2 = 0;
            temp_18->f0 = 0xD;
            temp_18->f1 = 0xC5U;
            return;
        }
        temp_18->f1 = 0x36U;
        temp_18->fB2 = 1;
        return;
    case 0x36:
        memset(&sp110, 0, 0x1A);
        for (var_16_5 = 0; var_16_5 < *(s32 *)(func_002e4870(0) + 8); var_16_5++) {
            sp110[var_16_5] = ((u16 *)func_002e48a0(0, var_16_5))[1];
        }
        temp_16_43 = ((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA))[1];
        sp110[*(s32 *)(func_002e4870(0) + 8)] = temp_16_43;
        func_002e5ae0(0xD, sp110, (s8)func_00104c70(1));
        temp_16_44 = *(u32 *)(func_002e4870(0xD) + 8);
        temp_16_45 = (RpRandom() % temp_16_44) * 0xA;
        temp_19_9 = (s8)(temp_16_45 % *(u32 *)(func_002e4870(0xD) + 8));
        temp_18->f2F9 = temp_18->f128 + 1;
        temp_18->f2FA = temp_18->f11E;
        for (var_17_7 = 0; var_17_7 < 8; var_17_7++) {
            if ((((1 << var_17_7) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f2FA + 0x2E4)) >> var_17_7) == 1
                && (s32)func_0010ceb0((u8 *)(((u16 *)func_002e48a0(0xD, temp_19_9)))) < 8) {
                temp_16_47 = ((u16 *)func_002e48a0(temp_18->f128 + 1, temp_18->f11E))[var_17_7 + 6];
                if (func_0010ce10((u8 *)((u16 *)func_002e48a0(0xD, temp_19_9)), temp_16_47) == -1) {
                    func_0010cc20((u8 *)((u16 *)func_002e48a0(0xD, temp_19_9)), temp_16_47);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_18->f2FA = temp_19_9;
        temp_16_48 = ((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA));
        func_003146f0(temp_18->f148, (s32)(temp_16_48), *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    case 0x37:
        var_19_3 = 0x63;
        memset(&spF0, 0, 0x1A);
        for (var_16_6 = 0; var_16_6 < *(s32 *)(func_002e4870(0) + 8); var_16_6++) {
            spF0[var_16_6] = ((u16 *)func_002e48a0(0, var_16_6))[1];
        }
        temp_16_49 = ((u16 *)func_002e48a0(temp_18->f128 + 1, temp_18->f11E))[1];
        spF0[*(s32 *)(func_002e4870(0) + 8)] = temp_16_49;
        func_002e6280(0xD, spF0, (s8)func_00104c70(1));
        if (*(s32 *)(func_002e4870(0xD) + 8) == 0) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_18->f2FA = temp_18->f11E;
            temp_18->f1 = 0x36;
            temp_18->fB2 = 1;
            break;
        }
        temp_18->f2F9 = 0xD;
        for (var_17_8 = 0; var_17_8 < *(s32 *)(func_002e4870(0xD) + 8); var_17_8++) {
            temp_16_50 = *(u8 *)((u8 *)((u16 *)func_002e48a0(0xD, var_17_8)) + 4);
            if (temp_16_50 >= (func_00104c70(1) & 0xFF)) {
                temp_18->f2FA = var_17_8;
                break;
            }
            if (var_19_3 > (func_00104c70(1) & 0xFF) - *(u8 *)((u8 *)((u16 *)func_002e48a0(0xD, var_17_8)) + 4)) {
                temp_16_51 = *(u8 *)((u8 *)((u16 *)func_002e48a0(0xD, var_17_8)) + 4);
                var_19_3 = (func_00104c70(1) & 0xFF) - temp_16_51;
                temp_18->f2FA = var_17_8;
            }
        }
        temp_19_10 = temp_18->f2FA;
        temp_18->f2F9 = temp_18->f128 + 1;
        for (var_17_9 = 0; var_17_9 < 8; var_17_9++) {
            if ((((1 << var_17_9) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f11E + 0x2E4)) >> var_17_9) == 1
                && (s32)func_0010ceb0((u8 *)(((u16 *)func_002e48a0(0xD, temp_19_10)))) < 8) {
                temp_16_53 = ((u16 *)func_002e48a0(temp_18->f2F9, temp_18->f11E))[var_17_9 + 6];
                if (func_0010ce10((u8 *)((u16 *)func_002e48a0(0xD, temp_19_10)), temp_16_53) == -1) {
                    func_0010cc20((u8 *)((u16 *)func_002e48a0(0xD, temp_19_10)), temp_16_53);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_16_54 = ((u16 *)func_002e48a0(0xD, temp_18->f2FA));
        func_003146f0(temp_18->f148, (s32)(temp_16_54), *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    }
}

/* Native position/color payloads and row views preserve the retail 0x400 frame. */
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA4];
    s8 fB2;
    u8 padB3[0x6B];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    u8 *f148;
    u8 pad14C[0x8];
    u8 *rows[12];
    u8 *f184;
    u8 *f188;
    u8 pad18C[0x100];
    u8 *f28C;
    u8 *f290;
    u8 pad294[0x65];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x5];
} FclCombineCtl;

typedef struct {
    u8 pad0[0x154];
    u8 *list;
} Fcl0f00RowList;

#define FCL0F00_GRID_ROW(menu, outer, mode, transition, headerPosition, cellPosition, color0, color1) do { \
    s32 grid = mode; \
 \
    s32 offset = outer * 23; \
    s32 y; \
    s16 inner; \
    Fcl0f00RowList *list; \
 \
    func_002b83e0(func_0034ae50((u8 *)menu->f184, (s8)outer), \
        (headerPosition = func_002b2970((f32)(offset + 329), 104.0f)), \
        (color0 = func_002b2a60(0, 0, 0x99, 0xFF)), \
        (color1 = func_002b2a60(0, 0, 0x99, 0xFF)), 255, 255, 32.0f, 159.0f, 3, 0, transition, 0); \
    inner = 0; \
    list = (Fcl0f00RowList *)((u8 *)menu + outer * 4); \
    y = offset + 127; \
    for (; inner < (func_0010b5b0() & 0xFFFF); inner++) { \
        if (grid) { \
            func_002b83e0(func_0034ae50(list->list, (s8)inner), \
                (cellPosition = func_002b2970((f32)(inner * 23 + 329), (f32)y)), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                32.0f, *(f32 *)(func_0034ae50(list->list, (s8)inner) + 4), 3, 0, transition, 0); \
        } else { \
            func_002b83e0(func_0034ae50(list->list, (s8)inner), \
                *(FclVec2 *)(func_0034ae50(list->list, (s8)inner) + 0x28), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                32.0f, *(f32 *)(func_0034ae50(list->list, (s8)inner) + 4), 3, 0, transition, 0); \
        } \
    } \
} while (0)


// FUN_002F0F00
#pragma push
#pragma opt_loop_invariants on
void func_002f0f00(u8 *arg0) {

    u8 *s0;
    FclDrawColor sp3FC;
    FclDrawColor sp3F8;
    FclDrawColor sp3F4;
    FclDrawColor sp3F0;
    FclDrawColor sp3EC;
    FclDrawColor sp3E8;
    FclDrawColor sp3E4;
    FclDrawColor sp3E0;
    FclDrawColor sp3DC;
    FclDrawColor sp3D8;
    FclVec2f base3A;
    FclVec2f sp3C8;
    FclVec2f sp3C0;
    FclVec2f sp3B8;
    FclVec2f sp3B0;
    FclVec2f sp3A8;
    FclVec2f sp3A0;
    FclVec2f sp398;
    FclVec2f sp390;
    FclVec2f sp388;
    FclVec2f sp380;
    FclVec2f sp378;
    FclVec2f sp370;
    FclVec2f sp368;
    FclVec2f sp360;
    FclVec2f sp358;
    FclVec2f sp350;
    FclVec2f sp348;
    FclVec2f sp340;
    FclVec2f sp338;
    FclVec2f sp330;
    FclVec2f sp328;
    FclVec2f sp320;
    FclVec2f sp318;
    FclVec2f sp310;
    FclVec2f sp308;
    FclVec2f sp300;
    FclVec2f sp2F8;
    FclVec2f sp2F0;
    FclVec2f sp2E8;
    FclVec2f sp2E0;
    FclVec2f sp2D8;
    FclVec2f sp2D0;
    FclVec2f sp2C8;
    FclVec2f sp2C0;
    FclVec2f sp2B8;
    FclVec2f sp2B0;
    FclVec2f sp2A8;
    FclVec2f sp2A0;
    FclVec2f sp298;
    FclVec2f sp290;
    FclVec2f sp288;
    FclVec2f sp280;
    FclVec2f sp278;
    FclVec2f sp270;
    FclVec2f sp268;
    FclVec2f sp260;
    FclVec2f sp258;
    FclVec2f sp250;
    FclVec2f sp248;
    FclVec2f sp240;
    FclVec2f sp238;
    FclVec2f sp230;
    FclVec2f sp228;
    FclVec2f sp220;
    FclVec2f sp218;
    FclVec2f sp210;
    FclVec2f sp208;
    FclVec2f sp200;
    FclVec2f sp1F8;
    FclVec2f sp1F0;
    FclVec2f sp1E8;
    FclVec2f sp1E0;
    FclVec2f sp1D8;
    FclVec2f sp1D0;
    FclVec2f sp1C8;
    FclVec2f sp1C0;
    FclVec2f sp1B8;
    FclVec2f sp1B0;
    FclVec2f sp1A8;
    FclVec2 sp1A0;
    FclVec2 sp198;
    FclVec2 sp190;
    FclVec2 sp188;
    FclVec2f sp180;
    FclVec2f sp178;
    u16 sp150[16];
    u16 sp130[16];
    s8 var_16_10;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f21;
    s16 temp_16_10;
    s16 temp_16_19;
    s16 temp_16_29;
    s16 temp_2_18;
    s16 temp_3_4;
    s16 temp_5;
    s32 temp_16_22;
    s32 temp_16_23;
    s32 temp_16_24;
    s32 temp_16_26;
    s32 temp_16_28;
    s32 temp_16_35;
    s32 temp_16_36;
    s32 temp_16_37;
    s32 temp_16_38;
    s32 temp_16_39;
    s32 temp_16_3;
    s32 temp_16_43;
    s32 temp_16_45;
    s32 temp_16_48;
    s32 temp_16_50;
    s32 temp_16_52;
    s32 temp_16_54;
    s32 temp_16_55;
    s32 temp_16_56;
    s32 temp_16_57;
    s32 temp_16_58;
    s32 temp_16_60;
    s32 temp_16_63;
    s32 temp_16_64;
    s32 temp_16_65;
    s32 temp_16_66;
    s32 temp_16_68;
    s32 temp_16_72;
    s32 temp_16_74;
    s32 temp_16_9;
    s32 temp_18_11;
    u8 *temp_18_20;
    s32 temp_19_7;
    s32 temp_20_5;
    u8 *temp_21_4;
    u8 *temp_21_8;
    s32 temp_22_4;
    s32 temp_2_2;
    u8 *temp_2_3;
    s16 temp_18_10;
    s16 temp_16_17;
    s16 temp_19_6;
    s16 temp_3_3;
    s16 gridRow;
    s16 partyRow;
    s16 resultRow;
    s32 var_18;
    s32 var_19;
    s32 var_19_3;
    s16 temp_16_13;
    s16 temp_16_21;
    s32 temp_16_46;
    s32 temp_18_12;
    s16 temp_18_15;
    s32 temp_18_42;
    s32 temp_19_11;
    s32 temp_19_12;
    s32 temp_19_13;
    s16 selectedResult;
    s32 temp_21_11;
    s16 var_16_11;
    s16 var_16_9;
    s16 var_18_7;
    s16 var_18_9;
    s32 var_19_8;
    s16 gridColumn;
    s16 var_21;
    s8 temp_16_14;
    s8 temp_16_61;
    s8 temp_16_69;
    s8 temp_18_16;
    s8 temp_18_28;
    s8 temp_18_39;
    s8 temp_18_44;
    s8 temp_2_10;
    s8 temp_4;
    s8 temp_4_2;
    u16 *temp_16_18;
    u16 *temp_18_31;
    u16 *temp_18_34;
    u16 *temp_18_35;
    u16 *temp_21_9;
    u16 *temp_22_5;
    u16 temp_16_77;
    u16 temp_16_78;
    u16 temp_16_82;
    u16 temp_16_88;
    u32 temp_16_79;
    u32 temp_16_80;
    u8 temp_16_25;
    u8 temp_16_27;
    u8 temp_16_42;
    u8 temp_16_44;
    s32 temp_16_49;
    u8 temp_16_51;
    u8 temp_16_53;
    s32 temp_16_59;
    s32 temp_16_67;
    u8 temp_16_71;
    u8 temp_16_73;
    u8 temp_16_8;
    s32 temp_18_40;
    u8 temp_3;
    u8 temp_7;
    u8 temp_7_2;
    u8 temp_7_3;
    FclVec2f *basePos;
    u8 *temp_16_47;
    u8 *temp_16_62;
    u8 *temp_16_70;
    FclCombineCtl *temp_17;
    Fcl0f00RowList *temp_18_21;
    FclCombineCtl *temp_18_23;
    FclCombineCtl *temp_18_24;
    FclCombineCtl *temp_18_25;
    FclCombineCtl *temp_18_26;
    FclCombineCtl *temp_18_29;
    FclCombineCtl *temp_18_30;
    FclCombineCtl *temp_18_32;
    FclCombineCtl *temp_18_33;
    FclCombineCtl *temp_18_36;
    FclCombineCtl *temp_18_37;
    FclCombineCtl *temp_18_8;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_17 = *(FclCombineCtl **)(arg0 + 0x38);
    temp_3 = (u8)((u8)((u8)(temp_17->f1)));
    switch (temp_3) {                               /* switch 1 */
    case 0x38:                                      /* switch 1 */
        func_002e4610(1, 0);
        func_002e4610(0xA, 1);
        func_002e4610(0xA, 2);
        func_002e4610(0xA, 3);
        func_002e4610(0xA, 4);
        func_002e4610(0xA, 5);
        func_002e4610(0xA, 6);
        func_002e4610(0xA, 7);
        func_002e4610(0xA, 8);
        func_002e4610(0xA, 9);
        func_002e4610(0xA, 0xA);
        func_002e4610(0xA, 0xB);
        func_002e4610(0xA, 0xC);
        func_002e4610(0, 0xD);
        func_00315600(arg0, 1);
        temp_17->f1 = 0x39U;
        return;
    case 0x39:                                      /* switch 1 */
        if (func_003190d0(arg0) != 1 && *(s8 *)func_002e4870(0) == 1) {
            for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
                sp3FC = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)temp_17->f188, partyRow) + 0x75) = sp3FC;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00320b80(arg0, 1);
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_17->f1 = 0x3AU;
            return;
        }
        break;
    case 0x3A:                                      /* switch 1 */
        for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(partyRow + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 0, 255.0f, temp_f20, (f32)*(s16 *)(func_002b6150(partyRow + 0x21C) + 0x40));
            if (temp_17->f11E == partyRow) {
                var_19 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_19 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (partyRow < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(partyRow * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_19, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
            }
        }
        if (((*(s16 *)func_0034ae50(((u8 **)((u8 *)temp_17 + 0x150))[func_0010b5b0() & 0xFFFF], (func_0010b5b0() & 0xFFFF) - 1) & 4) >> 2) == 0) {
            temp_f20_2 = (f32)(u32)func_0010b5b0() / 12.0f;
            sp3B8 = func_002b2970((f32)0x149, 128.0f);
            base3A = *(FclVec2f *)&sp3B8;
            temp_f1 = (f32)((func_0010b5b0() & 0xFFFF) * 0x17) / 2.0f;
            sp3C8 = func_002b2970(base3A.x + temp_f1, base3A.y + temp_f1);
            temp_2_3 = func_0046d200(func_00331560(), 0x7E);
            temp_f22 = temp_f20_2 * func_0046b260(temp_2_3) / 2.0f;
            temp_f21 = temp_f20_2 * func_0046b2f0(temp_2_3) / 2.0f;
            func_0046d280(temp_2_3);
            sp3C0 = func_002b2970(sp3C8.x - temp_f22, sp3C8.y - temp_f21);
            func_002b6c30(0x7E, sp3C0, 156.0f, 0x56);
            func_002b6a70(0x7E, 0, 0xFF, 0, 2, 0);
            *(f32 *)(func_002b6150(0x7E) + 0xAC) = temp_f20_2;
            *(f32 *)(func_002b6150(0x7E) + 0xA0) = temp_f20_2;
            switch (func_0010b5b0() & 0xFFFF) {
            case 12:
                sp3B0 = func_002b2970(sp3C0.x, sp3C0.y - 20.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3B0, 1, 8, 0);
                break;
            case 10:
                sp3A8 = func_002b2970(sp3C0.x, sp3C0.y - 16.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3A8, 1, 8, 0);
                break;
            case 8:
                sp3A0 = func_002b2970(sp3C0.x, sp3C0.y - 13.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp3A0, 1, 8, 0);
                break;
            case 6:
                sp398 = func_002b2970(sp3C0.x, sp3C0.y - 10.0f);
                func_002b69f0(0x7E, sp3C0, *(FclVec2f *)&sp398, 1, 8, 0);
                break;
            }
            *(s8 *)(func_002b6150(0x7E) + 0x47) = 1;
            func_002b6af0(0x7E, temp_f20_2, temp_f20_2, temp_f20_2 - iGpffff8218, temp_f20_2, 0, 4, 4);
            if (temp_17->f128 == -1) {
                temp_17->f11E = 0;
            }
            temp_17->f1 = 0x3DU;
            return;
        }
        break;
    case 0x3B:                                      /* switch 1 */
        for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {
            temp_f20_3 = (f32)*(s16 *)(func_002b6150(gridRow + 0x21C) + 0x42);
            temp_7_2 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20_3, (f32)*(s16 *)(func_002b6150(gridRow + 0x21C) + 0x40));
            if (temp_17->f11E == gridRow) {
                var_18 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_2);
            } else {
                var_18 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_2);
            }
            if (gridRow < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(gridRow * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_18, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, gridRow))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        if (((s32)((s32)(((s32) (*(s16 *)func_0034ae50((u8 *)(temp_17->rows[0]),  0) & 4) >> 2))) == (s32)((s32)(0))) && ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) == (s32)((s32)(0)))) {
            func_003205f0(arg0, 0x96, 0x93);
            func_002eb270(arg0, 0U);
            func_00315600(arg0, 0);
            temp_17->f0 = 0;
            temp_17->f1 = 0x1AU;
            return;
        }
        break;
    case 0x3D:                                      /* switch 1 */
        var_21 = -1;
        for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
            temp_f20_4 = (f32)*(s16 *)(func_002b6150(partyRow + 0x21C) + 0x42);
            temp_7_3 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20_4, (f32)*(s16 *)(func_002b6150(partyRow + 0x21C) + 0x40));
            if (temp_17->f11E == partyRow) {
                var_19_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_3);
            } else {
                var_19_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_3);
            }
            if (partyRow < *(s32 *)(func_002e4870(0) + 8)) {
                temp_f20 = (f32)(partyRow * 0x17 + 0x80);
                func_00275820(113.0f, temp_f20, 43.0f, var_19_3, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, partyRow))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
            temp_2_2 = (s16)func_002b6970(*(s16 *)(func_002b6150(partyRow + 0x21C) + 0x10), 1);
            if (temp_2_2 == 1) {
                var_21 = 1;
            }
        }
        if (((s16)(var_21)) == -1) {
            temp_17->f1 = 0x3CU;
            return;
        }
        break;
    case 0x3C:                                      /* switch 1 */
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            func_00321e60(arg0, 1, 0x40, 0x3B);
            return;
        }
        break;
    case 0x3E:                                      /* switch 1 */
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148), (s32)((u16 *)func_002e48a0(0, temp_17->f11E)), 0, 0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_3 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_3,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x3FU;
            return;
        }
        break;
    case 0x3F:                                      /* switch 1 */
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_83;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_83;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_83;
                }
            } else {
                goto block_83;
            }
        } else {
block_83:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
                    sp390 = func_002b2970(16.0f, 128.0f);

                    func_003191c0(arg0, sp390, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (4))))), 0, 0, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                }
                sp388 = func_002b2970(16.0f, 104.0f);
                func_0031e5b0(arg0, sp388, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {

                    FCL0F00_GRID_ROW(temp_17, gridRow, 1, 0, sp380, sp378, sp3F8, sp3F4);
                    {
                        s16 labelRow;
                        s16 labelId;
                        u8 *labelNode;
                        labelRow = (s16)gridRow;
                        labelId = (s16)((labelRow + 0x25E));
                        labelNode = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(labelId, 0U, 0xFF, 0, 3, 0);
                        func_002b6af0(labelId, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, 0);
                        temp_20_5 = (labelRow * 0x17) + 0x14E;
                        sp370 = func_002b2970((f32) temp_20_5, 110.0f + (func_0046b2f0(labelNode) / 2.0f));
                        sp368 = func_002b2970((f32) temp_20_5, 110.0f);
                        func_002b69f0(labelId, (*(FclVec2f *)&sp370), (*(FclVec2f *)&sp368),  0,  3,  0);
                        func_0046d280(labelNode);
                    }
                }
                func_002b6140((u8 *)(temp_17->f28C), 0);
                func_002b6140((u8 *)(temp_17->f290), 0);
                temp_17->f1 = 0x3CU;
                return;
            }
        }
        break;
    case 0x40:                                      /* switch 1 */
        temp_17->f129 = -1;
        for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
            func_0031d630(arg0, (s8)(partyRow), temp_17->f128, temp_17->f129, 0);
        }
        temp_16_8 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_8 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp1E8 = *(FclVec2f *)(temp_2_4 + 0x38);
        temp_16_9 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_8)));
        func_00275820(111.0f + sp1E8.x, sp1E8.y, 43.0f, temp_16_9, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_8->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = (s16)((s16)(func_002b2d00(temp_17->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = (s16)((s16)(func_002b2cb0(temp_17->f11E, 1, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_10 = (s16)((s16)((s16)(temp_17->f11E)));
                if (temp_16_10 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
                        sp360 = func_002b2970(16.0f, 128.0f);

                        func_003191c0(arg0, sp360, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (4))))), 0, 1, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                    }
                    sp358 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp358, 0, 1, 0, 0, 0);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {
                        FCL0F00_GRID_ROW(temp_17, gridRow, 0, 1, sp350, sp378, sp3F0, sp3EC);
                        temp_18_10 = (s16)(gridRow);
                        temp_16_13 = (s16)((temp_18_10 + 0x25E));
                        temp_21_4 = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(temp_16_13, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_13, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_11 = (temp_18_10 * 0x17) + 0x14E;
                        sp348 = func_002b2970((f32) temp_18_11, 110.0f);
                        sp340 = func_002b2970((f32) temp_18_11, 110.0f + (func_0046b2f0(temp_21_4) / 2.0f));
                        func_002b69f0(temp_16_13, (*(FclVec2f *)&sp348), (*(FclVec2f *)&sp340),  0,  3,  0);
                        func_0046d280(temp_21_4);
                    }
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    temp_17->f1 = 0x41U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_5 = (s16)((s16)((s16)(temp_17->f11E)));
                    if ((temp_17->f128 != temp_5) && ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_5))) + (2)))) != 0)) {
                        func_0045af60(0, 0, 0, 1);
                        temp_17->f129 = (s8)((s8)((s8) temp_17->f11E));
                        basePos = (FclVec2f *)D_00640C18;
                        sp338 = func_002b2970(-380.0f, 81.0f);
                        sp330 = func_002b2970(basePos->x, basePos->y);
                        func_0031cce0(arg0, temp_17->f129, sp338, sp330);
                        for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {
                        temp_18_12 = (s16)(gridRow);
                            temp_16_14 = (s8)((s8)((s8)(temp_17->f129)));
                            if ((*((s8 *)((u8 *)((func_002e4870((u32)temp_16_14 + 1U) + (temp_16_14 * 0xC) + temp_18_12)) + (0x14)))) > 0) {
                                sp328 = func_002b2970((f32) 0x149, 128.0f);

                                func_0031ac10(arg0, sp328, (s64)temp_17->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_16_14 + 1)), gridRow))) + (4))))), 3, 0, 1, 0xCC);
                            }
                            FCL0F00_GRID_ROW(temp_17, gridRow, 1, 1, sp320, sp318, sp3E8, sp3E4);
                            temp_16_17 = (s16)(gridRow);
                            temp_18_15 = (s16)((temp_16_17 + 0x25E));
                            temp_21_8 = func_0046d200(func_00331560(), 0x39);
                            func_002b6a70(temp_18_15, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_18_15, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_22_4 = (temp_16_17 * 0x17) + 0x14E;
                            sp310 = func_002b2970((f32) temp_22_4, 110.0f);
                            sp308 = func_002b2970((f32) temp_22_4, 110.0f + (func_0046b2f0(temp_21_8) / 2.0f));
                            func_002b69f0(temp_18_15, (*(FclVec2f *)&sp310), (*(FclVec2f *)&sp308),  0,  3,  0);
                            func_0046d280(temp_21_8);
                            temp_18_16 = (s8)((s8)((s8)(temp_17->f129)));
                            if ((*((s8 *)((u8 *)((func_002e4870((u32)temp_18_16 + 1U) + (temp_18_16 * 0xC) + temp_16_17)) + (0x14)))) > 0) {
                                temp_16_18 = (u16 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), gridRow)));
                                temp_21_9 = (u16 *)(((u16 *)func_002e48a0(0, temp_17->f128)));
                                temp_22_5 = (u16 *)(((u16 *)func_002e48a0(0, temp_17->f129)));
                                func_002f9c30(temp_16_18, (u8 *)temp_21_9, (u8 *)temp_22_5, (u8 *)((u16 *)func_002e48a0(0, gridRow)), NULL, NULL, NULL, 3, (s8)((temp_18_16 + 1)), (s8)(gridRow));
                            }
                        }
                        sp300 = func_002b2970((f32) 0x149, 104.0f);
                        func_0031fa20(arg0, sp300, 3, 0);
                        func_003205f0(arg0, 0x95, 0x94);
                        func_0031e320(arg0, temp_17->f129);
                        temp_17->f1 = 0x43U;
                        return;
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024C[0] & 0x80) {
                    temp_16_19 = (s16)((s16)((s16)(temp_17->f11E)));
                    if (temp_16_19 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                        func_0045af60(0, 1, 0, 3);
                        for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
                            sp2F8 = func_002b2970(16.0f, 128.0f);

                            func_003191c0(arg0, sp2F8, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (4))))), 0, 1, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                        }
                        sp2F0 = func_002b2970(16.0f, 104.0f);
                        func_0031e5b0(arg0, sp2F0, 0, 1, 0, 0, 0);
                        for (gridColumn = 0; gridColumn < (func_0010b5b0() & 0xFFFF); gridColumn++) {
                            FCL0F00_GRID_ROW(temp_17, gridColumn, 0, 1, sp2E8, sp378, sp3E0, sp3DC);
                            temp_19_6 = (s16)(gridColumn);
                            temp_16_21 = (s16)((((s8)((temp_19_6 + 0x6A))) + 0x1F4));
                            temp_18_20 = func_0046d200(func_00331560(), 0x39);
                            func_002b6a70(temp_16_21, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_16_21, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_19_7 = (temp_19_6 * 0x17) + 0x14E;
                            sp2E0 = func_002b2970((f32) temp_19_7, 110.0f);
                            sp2D8 = func_002b2970((f32) temp_19_7, 110.0f + (func_0046b2f0(temp_18_20) / 2.0f));
                            func_002b69f0(temp_16_21, (*(FclVec2f *)&sp2E0), (*(FclVec2f *)&sp2D8),  0,  3,  0);
                            func_0046d280(temp_18_20);
                        }
                        temp_17->f1 = 0x41U;
                        return;
                    }
                } else if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) temp_17->f11E, 0, 0xFF);
                    temp_17->f11E = temp_17->f128;
                    func_0031ddf0(arg0, (s8)temp_17->f11E, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    basePos = (FclVec2f *)D_00640C10;
                    sp2D0 = func_002b2970(basePos->x, basePos->y);
                    sp2C8 = func_002b2970(-380.0f, basePos->y);
                    func_0031c2b0(arg0, temp_17->f128, sp2D0, sp2C8);
                    func_0010b5b0();
                    for (gridColumn = 0; gridColumn < (func_0010b5b0() & 0xFFFF); gridColumn++) {
                        var_19_8 = 0;
                        temp_3_3 = (s16)(gridColumn);
                        temp_18_21 = (Fcl0f00RowList *)((u8 *)temp_17 + temp_3_3 * 4);
                        for (; (s32)((s32)(((s16)(var_19_8)))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        temp_21_11 = (s16)(var_19_8);
                            func_002b83e0(func_0034ae50(temp_18_21->list, (s8)var_19_8),
                                (sp2C0 = func_002b2970((f32)(temp_21_11 * 23 + 329), (f32)(temp_3_3 * 23 + 127))),
                                *(FclDrawColor *)(func_0034ae50(temp_18_21->list, (s8)var_19_8) + 0x75),
                                (sp3D8 = func_002b2a60(0, 0, 0x99, 0xA5)), 0xA5, 0xA5,
                                32.0f, *(f32 *)(func_0034ae50(temp_18_21->list, (s8)var_19_8) + 4), 6, 0, 1, 1);
                            var_19_8 = (s16)((var_19_8 + 1));
                        }
                    }
                    func_002b6a70(0x7E, 0U, 0xFF, 0, 3, 3);
                    func_002b68d0(0x7E, 0, 0);
                    temp_17->f1 = 0x3CU;
                    return;
                }
            }
        }
        break;
    case 0x41:                                      /* switch 1 */
        temp_2_6 = (u8 *)(func_002b6150(0x7C));
        sp1E0 = *(FclVec2f *)(temp_2_6 + 0x38);
        temp_16_22 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1E0.x, sp1E0.y, 43.0f, temp_16_22, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_17->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148), (s32)((u16 *)func_002e48a0(0, temp_17->f11E)), 0, 0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_23 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_23,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x42U;
            return;
        }
        break;
    case 0x42:                                      /* switch 1 */
        temp_2_7 = (u8 *)(func_002b6150(0x7C));
        sp1D8 = *(FclVec2f *)(temp_2_7 + 0x38);
        temp_16_24 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1D8.x, sp1D8.y, 43.0f, temp_16_24, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_17->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_166;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_166;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_166;
                }
            } else {
                goto block_166;
            }
        } else {
block_166:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                for (partyRow = 0; partyRow < (func_0010b5b0() & 0xFFFF); partyRow++) {
                    sp2B8 = func_002b2970(16.0f, 128.0f);

                    func_003191c0(arg0, sp2B8, (s8)partyRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, partyRow))) + (4))))), 0, 0, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                }
                sp2B0 = func_002b2970(16.0f, 104.0f);
                func_0031e5b0(arg0, sp2B0, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_003218a0(arg0, 0);
                func_002b6140((u8 *)(temp_17->f28C), 0);
                func_002b6140((u8 *)(temp_17->f290), 0);
                temp_17->f1 = 0x40U;
                return;
            }
        }
        break;
    case 0x43:                                      /* switch 1 */
        func_003233d0(arg0);
        temp_16_25 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_23 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_8 = (u8 *)(func_002b6150(0x7C));
        sp1D0 = *(FclVec2f *)(temp_2_8 + 0x38);
        temp_16_26 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_25)));
        func_00275820(111.0f + sp1D0.x, sp1D0.y, 43.0f, temp_16_26, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_23->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_27 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_24 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_9 = (u8 *)(func_002b6150(0x7D));
        sp1C8 = *(FclVec2f *)(temp_2_9 + 0x38);
        temp_16_28 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27)));
        func_00275820(111.0f + sp1C8.x, sp1C8.y, 43.0f, temp_16_28, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_24->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
            if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1C7)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                func_00324410(arg0, 0x1C7, 0);
                func_00324410(arg0, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                temp_17->f11E = (s16)((s16)(func_002b2d00(temp_17->f11E, 1, 0, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                temp_17->f11E = (s16)((s16)(func_002b2cb0(temp_17->f11E, 1, (s16)(((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1)), 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_29 = (s16)((s16)((s16)(temp_17->f11E)));
                if (temp_16_29 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    for (resultRow = 0; resultRow < (func_0010b5b0() & 0xFFFF); resultRow++) {
                        sp2A8 = func_002b2970((f32) 0x149, 128.0f);

                        func_0031ac10(arg0, sp2A8, (s64)temp_17->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                        sp2A0 = func_002b2970(16.0f, 128.0f);

                        func_003191c0(arg0, sp2A0, (s8)resultRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, resultRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, resultRow))) + (4))))), 0, 1, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                    }
                    sp298 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp298, 0, 1, 0, 0, 0);
                    sp290 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp290, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 60.0f);
                    func_002b6140((u8 *)(temp_17->f28C), 1);
                    func_002b6140((u8 *)(temp_17->f290), 1);
                    temp_17->f1 = 0x44U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_3_4 = (s16)((s16)((s16)(temp_17->f11E)));
                    if (temp_17->f128 != temp_3_4) {
                        temp_2_10 = (s8)((s8)((s8)(temp_17->f129)));
                        if ((temp_2_10 != temp_3_4) && ((*((s8 *)((u8 *)((func_002e4870((s8) ((s8)((temp_2_10 + 1)))) + (temp_17->f129 * 0xC) + temp_17->f11E)) + (0x14)))) > 0)) {
                            func_0045af60(0, 0, 0, 1);
                            for (resultRow = 0; resultRow < (func_0010b5b0() & 0xFFFF); resultRow++) {
                                sp288 = func_002b2970((f32) 0x149, 128.0f);

                                func_0031ac10(arg0, sp288, (s64)temp_17->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                                sp280 = func_002b2970(16.0f, 128.0f);

                                func_003191c0(arg0, sp280, (s8)resultRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, resultRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, resultRow))) + (4))))), 0, 1, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                            }
                            sp278 = func_002b2970(16.0f, 104.0f);
                            func_0031e5b0(arg0, sp278, 0, 1, 0, 0, 0);
                            sp270 = func_002b2970((f32) 0x149, 104.0f);
                            func_0031fa20(arg0, sp270, 0, 1);
                            func_00316470(arg0, 1, 1);
                            func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                            func_00317240(arg0, 0, 0);
                            func_002b6140((u8 *)(temp_17->f28C), 1);
                            func_002b6140((u8 *)(temp_17->f290), 1);
                            temp_17->f1 = 0x47U;
                            return;
                        }
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) temp_17->f11E, 0, 0xFF);
                    temp_17->f11E = temp_17->f129;
                    func_0031ddf0(arg0, (s8)temp_17->f11E, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    basePos = (FclVec2f *)D_00640C18;
                    sp268 = func_002b2970(basePos->x, basePos->y);
                    sp260 = func_002b2970(-380.0f, 81.0f);
                    func_0031cce0(arg0, temp_17->f129, sp268, sp260);
                    sp258 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp258, 0, 1);
                    for (resultRow = 0; resultRow < (func_0010b5b0() & 0xFFFF); resultRow++) {
                        sp250 = func_002b2970((f32) 0x149, 128.0f);

                        func_0031ac10(arg0, sp250, (s64)temp_17->f129, resultRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), resultRow))) + (4))))), 0, 1, 1, 0xCC);
                    }
                    func_003218a0(arg0, 3);
                    func_003205f0(arg0, 0x94, 0x95);
                    temp_17->f1 = 0x40U;
                    return;
                }
            }
        }
        break;
    case 0x44:                                      /* switch 1 */
        temp_2_12 = (u8 *)(func_002b6150(0x7C));
        sp1C0 = *(FclVec2f *)(temp_2_12 + 0x38);
        temp_16_35 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1C0.x, sp1C0.y, 43.0f, temp_16_35, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_17->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_18_25 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_13 = (u8 *)(func_002b6150(0x7D));
        sp1B8 = *(FclVec2f *)(temp_2_13 + 0x38);
        temp_16_36 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1B8.x, sp1B8.y, 43.0f, temp_16_36, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_25->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            func_00314450((u8 *)(temp_17->f148), (s32)((u16 *)func_002e48a0(0, temp_17->f11E)), 0, 0);
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            temp_16_37 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_37,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_17->f1 = 0x45U;
            return;
        }
        break;
    case 0x45:                                      /* switch 1 */
        temp_2_14 = (u8 *)(func_002b6150(0x7C));
        sp1B0 = *(FclVec2f *)(temp_2_14 + 0x38);
        temp_16_38 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1B0.x, sp1B0.y, 43.0f, temp_16_38, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_17->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_18_26 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_15 = (u8 *)(func_002b6150(0x7D));
        sp1A8 = *(FclVec2f *)(temp_2_15 + 0x38);
        temp_16_39 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(111.0f + sp1A8.x, sp1A8.y, 43.0f, temp_16_39, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_26->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                }
                goto block_215;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    goto block_215;
                }
                if (func_00314660((u8 *)(temp_17->f148)) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)(temp_17->f148),  3);
                    if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0))))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_215;
                }
            } else {
                goto block_215;
            }
        } else {
block_215:
            if ((s8)func_00314660((u8 *)temp_17->f148) < 0 || (s8)func_00314660((u8 *)temp_17->f148) > 5) {
                func_00316470(arg0, 1, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {

                    sp248 = func_002b2970(16.0f, 128.0f);

                    func_003191c0(arg0, sp248, (s8)gridRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, gridRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, gridRow))) + (4))))), 0, 0, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                    temp_18_28 = (s8)((s8)((s8)(temp_17->f129)));
                    if ((*((s8 *)((u8 *)((func_002e4870((u32)temp_18_28 + 1U) + (temp_18_28 * 0xC) + gridRow)) + (0x14)))) > 0) {
                        sp240 = func_002b2970((f32) 0x149, 128.0f);

                        func_0031ac10(arg0, sp240, (s64)temp_17->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_18_28 + 1)), gridRow))) + (4))))), 0, 0, 1, 0xCC);
                    }
                }
                sp238 = func_002b2970(16.0f, 104.0f);
                func_0031e5b0(arg0, sp238, 0, 0, 0, 0, 0);
                sp230 = func_002b2970((f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp230, 0, 0);
                temp_17->f1 = 0x43U;
                return;
            }
        }
        break;
    case 0x47:                                      /* switch 1 */
        temp_16_42 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_29 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_16 = (u8 *)(func_002b6150(0x7C));
        sp1A0 = *(FclVec2 *)(temp_2_16 + 0x38);
        temp_16_43 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_42)));
        func_00275820(111.0f + sp1A0.x, sp1A0.y, 43.0f, temp_16_43, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_29->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_44 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_30 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_17 = (u8 *)(func_002b6150(0x7D));
        sp198 = *(FclVec2 *)(temp_2_17 + 0x38);
        temp_16_45 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_44)));
        func_00275820(111.0f + sp198.x, sp198.y, 43.0f, temp_16_45, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_30->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s32)(((s16)(func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1))))) != (s32)((s32)(1))) {
            temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
            temp_2_18 = (s16)((s16)((s16)(temp_17->f11E)));
            temp_17->f2FA = (s8) temp_2_18;
            temp_16_46 = temp_17->f2FA;
            temp_18_31 = (u16 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_16_46)));
            temp_16_47 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_46)));
            temp_19_11 = (s64)((s64)((s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))[1] * 14 + 2])));
            func_003144d0((u8 *)(temp_17->f148), (s32)(temp_18_31), (*(s8 *)((u8 *)(temp_16_47)+(0x2E4))), func_00311930(temp_19_11, (u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA)))), 0), 1);
            temp_16_48 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
            func_0011d140((u8 *)temp_16_48,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_16_49 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (4)))))));
            if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_49))) {
                temp_16_50 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                func_0011d140((u8 *)temp_16_50,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
            }
            func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
            func_00325450(arg0, 4, 0);
            temp_17->f1 = 0x46U;
            return;
        }
        break;
    case 0x46:                                      /* switch 1 */
        temp_16_51 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_32 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_19 = (u8 *)(func_002b6150(0x7C));
        sp190 = *(FclVec2 *)(temp_2_19 + 0x38);
        temp_16_52 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_51)));
        func_00275820(111.0f + sp190.x, sp190.y, 43.0f, temp_16_52, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_32->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_53 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_33 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_20 = (u8 *)(func_002b6150(0x7D));
        sp188 = *(FclVec2 *)(temp_2_20 + 0x38);
        temp_16_54 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_53)));
        func_00275820(111.0f + sp188.x, sp188.y, 43.0f, temp_16_54, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_33->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((s32)((s8)func_00314660((u8 *)(temp_17->f148))) == (s32)(0xD)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)(temp_17->f148)));
            }
            if (D_008C024E[0] & 0x40) {
                temp_17->f1 = 0x48U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)(temp_17->f148)));
                    func_00314740((u8 *)(temp_17->f148), 0);
                    return;
                }
                func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                func_00314740((u8 *)(temp_17->f148), 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)(temp_17->f148))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)(temp_17->f148)), 1);
                    func_00314740((u8 *)(temp_17->f148),  1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                temp_17->f1 = 0x4EU;
                func_00314670((u8 *)(temp_17->f148),  0xB);
                func_00317240(arg0, 1, 0);
                func_00325450(arg0, 4, 1);
                return;
            }
            if (D_008C024E[0] & 8) {
                if (temp_17->f122 != 3) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_17->f122 = (s8)((s8)(func_002b2cb0(temp_17->f122, 1, 3, 0, 1)));
                s0 = func_002b6150(0x152);
                sp228 = func_002b2970((f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp228),  1,  4,  0);
                s0 = func_002b6150(0x2E0);
                sp220 = func_002b2970((f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp220),  1,  4,  0);
                temp_4 = (s8)((s8)((s8)(temp_17->f122)));
                switch (temp_4) {                   /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_55 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_55,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_56 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_56,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f129))), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_57 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_57,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f11E))), 0, 0, 1);
                    return;
                case 3:                             /* switch 3 */
                    temp_16_58 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_58,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_59 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_59))) {
                        temp_16_60 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                        func_0011d140((u8 *)temp_16_60,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_61 = (s8)((s8)((s8)(temp_17->f2FA)));
                    temp_18_34 = (u16 *)(((u16 *)func_002e48a0(temp_17->f2F9, (s64) temp_16_61)));
                    temp_16_62 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_61)));
                    temp_19_12 = (s64)((s64)((s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))[1] * 14 + 2])));
                    func_003144d0((u8 *)(temp_17->f148), (s32)(temp_18_34), (*(s8 *)((u8 *)(temp_16_62)+(0x2E4))), func_00311930(temp_19_12, (u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA)))), 0), 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (temp_17->f122 != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_17->f122 = (s8)((s8)(func_002b2d00(temp_17->f122, 1, 0, 3, 1)));
                s0 = func_002b6150(0x152);
                sp218 = func_002b2970((f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp218),  1,  4,  0);
                s0 = func_002b6150(0x2E0);
                sp210 = func_002b2970((f32)((temp_17->f122 * 0x6B) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp210),  1,  4,  0);
                temp_4_2 = (s8)((s8)((s8)(temp_17->f122)));
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_16_63 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_63,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f128))), 0, 0, 1);
                    return;
                case 1:                             /* switch 4 */
                    temp_16_64 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_64,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f129))), 0, 0, 1);
                    return;
                case 2:                             /* switch 4 */
                    temp_16_65 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_65,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))), (s32)(((u16 *)func_002e48a0(0, temp_17->f11E))), 0, 0, 1);
                    return;
                case 3:                             /* switch 4 */
                    temp_16_66 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                    func_0011d140((u8 *)temp_16_66,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_67 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_67))) {
                        temp_16_68 = (s32)((s32)((s32)(func_003147d0((u8 *)(temp_17->f148)))));
                        func_0011d140((u8 *)temp_16_68,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_69 = (s8)((s8)((s8)(temp_17->f2FA)));
                    temp_18_35 = (u16 *)(((u16 *)func_002e48a0(temp_17->f2F9, (s64) temp_16_69)));
                    temp_16_70 = (u8 *)(func_002e4870(temp_17->f2F9) + ((s8)(temp_16_69)));
                    temp_19_13 = (s64)((s64)((s16)func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))[1] * 14 + 2])));
                    func_003144d0((u8 *)(temp_17->f148), (s32)(temp_18_35), (*(s8 *)((u8 *)(temp_16_70)+(0x2E4))), func_00311930(temp_19_13, (u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA)))), 0), 1);
                    return;
                }
            }
        }
        break;
    case 0x4E:                                      /* switch 1 */
        temp_16_71 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_36 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_21 = (u8 *)(func_002b6150(0x7C));
        sp180 = *(FclVec2f *)(temp_2_21 + 0x38);
        temp_16_72 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_71)));
        func_00275820(111.0f + sp180.x, sp180.y, 43.0f, temp_16_72, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_36->f128))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        temp_16_73 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_37 = *(FclCombineCtl **)(arg0 + 0x38);
        temp_2_22 = (u8 *)(func_002b6150(0x7D));
        sp178 = *(FclVec2f *)(temp_2_22 + 0x38);
        temp_16_74 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_73)));
        func_00275820(111.0f + sp178.x, sp178.y, 43.0f, temp_16_74, 0, 2, (const char *)((iGpffffb440) + ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, temp_18_37->f129))) + (2)))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(0xE)) {
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {

                sp208 = func_002b2970(16.0f, 128.0f);

                func_003191c0(arg0, sp208, (s8)gridRow, ((*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, gridRow))) + (2))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0(0, gridRow))) + (4))))), 0, 0, ((s8)*(s32 *)(func_002e4870(0) + 8)));
                temp_18_39 = (s8)((s8)((s8)(temp_17->f129)));
                if ((*((s8 *)((u8 *)((func_002e4870((u32)temp_18_39 + 1U) + (temp_18_39 * 0xC) + gridRow)) + (0x14)))) > 0) {
                    sp200 = func_002b2970((f32) 0x149, 128.0f);

                    func_0031ac10(arg0, sp200, (s64)temp_17->f129, gridRow, ((u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), gridRow))) + (2)))))))), ((*((u8 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_18_39 + 1)), gridRow))) + (4))))), 0, 0, 1, 0xCC);
                }
            }
            sp1F8 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp1F8, 0, 0, 0, 0, 0);
            sp1F0 = func_002b2970((f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1F0, 0, 0);
            temp_17->f1 = 0x43U;
            return;
        }
        break;
    case 0x48:                                      /* switch 1 */
        temp_16_77 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (2)))))));
        temp_18_40 = (u8)((u8)((u8)((*((u8 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (4)))))));
        if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_18_40))) {
            func_00310960(arg0, 0x26, 0);
            temp_17->f1 = 0x4AU;
            return;
        }
        if (func_002e53b0(0, (s32)*(s16 *)(func_002e48a0(temp_17->f2F9, temp_17->f2FA) + 2)) == 1) {
            func_00310960(arg0, 0x27, 0);
            temp_17->f1 = 0x4AU;
            return;
        }
        if ((s32)((s32)(((s8)(func_00105f50(temp_16_77))))) == (s32)((s32)(0))) {
            func_00310a10(arg0, temp_16_77);
        } else {
            func_00310960(arg0, (s8)((((s8)(func_00105f50(temp_16_77))) + 0x2E)), 1);
        }
        temp_17->f1 = 0x49U;
        return;
    case 0x49:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((s8)(temp_17->fD)))) != (s32)((s32)(0))) {
            func_002bbcf0((s8)(temp_17->fD));
            return;
        }
        if ((s32)((s32)(func_002bb1c0(temp_17->fD))) == (s32)((s32)(0))) {
            temp_17->f1 = 0x4CU;
            func_00122520(1, 0xA);
        } else {
            temp_17->f1 = 0x46U;
        }
        func_002bb550((s8)(temp_17->fD));
        return;
    case 0x4A:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((s8)(temp_17->fD)))) != (s32)((s32)(0))) {
            func_002bbcf0((s8)(temp_17->fD));
            return;
        }
        func_002bb550((s8)(temp_17->fD));
        temp_17->f1 = 0x46U;
        return;
    case 0x4C:                                      /* switch 1 */
        if ((s32)((s32)(func_00122720())) != (s32)((s32)(0))) {
            func_00314670((u8 *)(temp_17->f148),  0xB);
            func_00314680((u8 *)(temp_17->f148));
            func_00325450(arg0, 4, 1);
            for (var_16_9 = 0; var_16_9 < 0x30C; var_16_9++) {
                func_002b68d0(var_16_9, 0, 1);
            }
            temp_17->f1 = 0x4BU;
            return;
        }
        break;
    case 0x4B:                                      /* switch 1 */
        if (func_00314660((u8 *)(temp_17->f148)) == (s32)(0xE)) {
            temp_17->f1 = 0x4DU;
            return;
        }
        break;
    case 0x4D:                                      /* switch 1 */
        var_16_10 = 3;
        if ((*((s8 *)((u8 *)((func_002e4870(0) + (temp_17->f129 * 0xC) + temp_17->f11E)) + (0x14)))) == 2) {
            var_16_10 = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(func_00312bc0(var_16_10))) == (s32)((s32)(1))) {
                if (RpRandom() % 1000U < 0x1F4U) {
                    temp_17->f1 = 0x4FU;
                    temp_17->fB2 = 1;
                    return;
                }
                temp_17->f1 = 0x50U;
                temp_17->fB2 = 2;
                return;
            }
            temp_17->fB2 = 0;
            temp_17->f0 = 0xD;
            temp_17->f1 = 0xC5U;
            return;
        }
        if (RpRandom() % 1000U < 0x1F4U) {
            temp_17->f1 = 0x4FU;
            temp_17->fB2 = 1;
            return;
        }
        temp_17->f1 = 0x50U;
        temp_17->fB2 = 2;
        return;
    case 0x4F:                                      /* switch 1 */
        memset(&sp150, 0, 0x1A);
        for (var_16_11 = 0; var_16_11 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8)))); var_16_11++) {
            sp150[var_16_11] = (u16)((u16)((u16) (*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, var_16_11))) + (2))))));
        }
        temp_16_78 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f2FA))) + (2)))))));
        sp150[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_78;
        func_002e5ae0(0xD, (u16 *)(sp150), (s8)(func_00104c70(1)));
        temp_16_79 = (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))));
        temp_16_80 = (u32)((u32)((RpRandom() % temp_16_79) * 0xA));
        selectedResult = (s64)((s64)((s8)((temp_16_80 % (u32) (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))))))));
        temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
        temp_17->f2FA = (s8)((s8)((s8) temp_17->f11E));
        for (var_18_7 = 0; var_18_7 < 8; var_18_7++) {

            if (((s32)((s32)(((s32) ((1 << var_18_7) & 0xFF & (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + temp_17->f2FA)) + (0x2E4))))) >> var_18_7))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0((u8 *)(func_002e48a0(0xD, selectedResult))))) < (s32)((s32)(8)))) {
                temp_16_82 = (u16)((u16)((u16)((*((u16 *)((u8 *)((((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), temp_17->f11E)) + var_18_7)) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(((u16 *)func_002e48a0(0xD, selectedResult))),  temp_16_82))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(((u16 *)func_002e48a0(0xD, selectedResult))),  temp_16_82);
                }
            }
        }
        temp_17->f2F9 = 0xD;
        temp_17->f2FA = (s8) selectedResult;
        temp_18_42 = temp_17->f2FA;
        func_003146f0((u8 *)(temp_17->f148), (s32)((u16 *)func_002e48a0(temp_17->f2F9, temp_18_42)), (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + ((s8)(temp_18_42)))) + (0x2E4)))));
        temp_17->f0 = 0xD;
        temp_17->f1 = 0xC5U;
        return;
    case 0x50:                                      /* switch 1 */
        {
            s16 var_19_11;
            s16 var_16_12;
            u16 temp_16_84;
            s16 var_18_8;
            s32 temp_16_85;
            var_19_11 = 0x63;
            memset(&sp130, 0, 0x1A);
            for (var_16_12 = 0; var_16_12 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8)))); var_16_12++) {
                sp130[var_16_12] = (u16)((u16)((u16) (*((u16 *)((u8 *)(((u16 *)func_002e48a0(0, var_16_12))) + (2))))));
            }
            temp_16_84 = (u16)((u16)((u16)((*((u16 *)((u8 *)(((u16 *)func_002e48a0((s8)((temp_17->f129 + 1)), temp_17->f11E))) + (2)))))));
            sp130[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_84;
            func_002e6280(0xD, (u16 *)(sp130), (s8)(func_00104c70(1)));
            if ((*((s32 *)((u8 *)(func_002e4870(0xD)) + (8)))) == 0) {
                temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
                temp_17->f2FA = (s8)((s8)((s8) temp_17->f11E));
                temp_17->f1 = 0x4FU;
                temp_17->fB2 = 1;
                return;
            }
            temp_17->f2F9 = 0xD;
            for (var_18_8 = 0; var_18_8 < *(s32 *)(func_002e4870(0xD) + 8); var_18_8++) {
                temp_16_85 = (*((u8 *)((u8 *)(((u16 *)func_002e48a0(0xD, var_18_8))) + (4))));
                if ((s32)((s32)((s32) temp_16_85)) >= (s32)((s32)((func_00104c70(1) & 0xFF)))) {
                    temp_17->f2FA = (s8) var_18_8;
                    break;
                } else {
                    if ((s16)var_19_11 > (s8)((func_00104c70(1) & 0xFF) - *(u8 *)((u8 *)((u16 *)func_002e48a0(0xD, var_18_8)) + 4))) {
                        var_19_11 = (s8)((func_00104c70(1) & 0xFF) - *(u8 *)((u8 *)((u16 *)func_002e48a0(0xD, var_18_8)) + 4));
                        temp_17->f2FA = (s8) var_18_8;
                    }

                }
            }
        }
        selectedResult = (s8)((s8)((s8)(temp_17->f2FA)));
        temp_17->f2F9 = (s8)((s8)((s8) (temp_17->f129 + 1)));
        for (var_18_9 = 0; var_18_9 < 8; var_18_9++) {

            if (((s32)((s32)(((s32) ((1 << var_18_9) & 0xFF & (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + temp_17->f11E)) + (0x2E4))))) >> var_18_9))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0((u8 *)(func_002e48a0(0xD, selectedResult))))) < (s32)((s32)(8)))) {
                temp_16_88 = (u16)((u16)((u16)((*((u16 *)((u8 *)((((u16 *)func_002e48a0(temp_17->f2F9, temp_17->f11E)) + var_18_9)) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(((u16 *)func_002e48a0(0xD, selectedResult))),  temp_16_88))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(((u16 *)func_002e48a0(0xD, selectedResult))),  temp_16_88);
                }
            }
        }
        temp_17->f2F9 = 0xD;
        temp_18_44 = (s8)((s8)((s8)(temp_17->f2FA)));
        func_003146f0((u8 *)(temp_17->f148), (s32)((u16 *)func_002e48a0(0xD, temp_18_44)), (*((s8 *)((u8 *)((func_002e4870(temp_17->f2F9) + ((s8)(temp_18_44)))) + (0x2E4)))));
        temp_17->f0 = 0xD;
        temp_17->f1 = 0xC5U;
        break;
    }

}
#pragma pop
#undef FCL0F00_GRID_ROW
/* measured: 12084 executable bytes / 12096-byte window, verify MATCH, 391 relocations.
   Rewritten from the retail assembly with opt_lifetimes (each loop and case keeps
   its own registers, as in retail).  00275820 takes its floats first; colour
   builders passed straight into 002ba5d0 keep retail's call order; the object ids
   reused inside the selected-row branch are locals computed before their first
   colour call; the row index is copied into its own local at each branch. */
/* The colour packers take byte channels through the shared interface: the
   alphas are u8 locals and retail passes them unmasked. func_00313ae0 is
   (s8 kind, u16 id) and widens the id once on entry. */
// FUN_002F6CF0
#pragma push
#pragma opt_lifetimes on
void func_002f6cf0(u8 *arg0) {
    extern void func_00313800(s8);
    extern void func_00323d00(u8 *, s32, s8);
    extern s32 func_003139d0(s8, s8);
    extern s8 func_00313ae0(s8, u16);
    extern s32 func_00313a80(s8, s8);
    extern f32 D_00640E70[];
    FclDrawColor color0;
    FclDrawColor color1;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    FclDrawColor color11;
    FclDrawColor color12;
    FclDrawColor color13;
    FclDrawColor color14;
    FclPackedPosition rowPos;
    FclPackedPosition pos0;
    FclPackedPosition pos1;
    FclPackedPosition pos2;
    FclPackedPosition pos3;
    FclPackedPosition pos4;
    FclPackedPosition pos5;
    FclPackedPosition pos6;
    s8 *p;
    u8 *ps;
    u8 *te;
    FclVec2 *base;
    s16 i;
    s16 k;
    s16 m;
    u8 alpha;
    u8 alpha2;
    u8 alpha3;
    s32 rgba;
    s32 rgba2;
    s32 rgba3;
    s16 step2;
    s16 obj2;
    s32 stepInt2;
    s16 step;
    s32 stepInt;
    s16 obj;
    s8 slot;
    u16 id;
    s32 objA;
    s32 row;
    s32 objB;
    s32 objC;
    u16 item;
    u8 shade;
    u16 buttons;

    p = *(s8 **)(arg0 + 0x38);
    switch ((u8)p[1]) {
    case 0x51:
        func_002e4610(0xA, 0);
        func_002e4610(0xA, 1);
        func_002e4610(0xA, 2);
        func_002e4610(0xA, 3);
        func_002e4610(0xA, 4);
        func_002e4610(0xA, 5);
        func_002e4610(0xA, 6);
        func_002e4610(0xA, 7);
        func_002e4610(0xA, 8);
        func_002e4610(0xA, 9);
        func_002e4610(0xA, 0xA);
        func_002e4610(0xA, 0xB);
        func_002e4610(0xA, 0xC);
        func_00315600(arg0, 1);
        func_00316470(arg0, 0, 0);
        func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        p[1] = 0x52;
        break;
    case 0x52:
        if (*(s8 *)func_002e4870(0) == 0) {
            break;
        }
        if (func_003190d0(arg0) == 1) {
            break;
        }
        p[0x129] = -1;
        p[0x128] = -1;
        *(s16 *)(p + 0x11E) = -1;
        for (i = 0; i < (u16)func_0010b5b0(); i++) {
            color0 = func_002b2a60(0, 0, 0x99, 0xFF);
            *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x188), i) + 0x75) = color0;
        }
        func_00313800(p[0x1A]);
        func_00323d00(arg0, 2, 0);
        base = (FclVec2 *)D_00640E70;
        pos0.position = func_002b2970(base->x, base->y);
        func_002b6c30(0xC8, pos0.position, 42.0f, 0x5A);
        func_002b6a70(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        pos1.position = func_002b2970((f32)0x28A + base->x, base->y);
        pos2.position = func_002b2970(base->x - 50.0f, base->y);
        func_002b69f0(0xC8, pos1.position, pos2.position, 0, 0x14, 0);
        func_003205f0(arg0, 0x98, 0x96);
        *(s16 *)(p + 0x11E) = 0;
        p[1] = 0x53;
        break;
    case 0x53:
        for (i = 0; i < *(s32 *)(func_002e4870(*(s16 *)(p + 0x11E) + 1) + 8); i++) {
            rowPos.position = func_002b2970((f32)0x139, 128.0f);
            rowPos.position.y += (f32)(i * 23);
            if (((s8 *)func_002e4870(*(s16 *)(p + 0x11E) + 1))[i + 0x14] == 0) {
                alpha = (u8)func_002b2aa0(0, 0.0f, 128.0f, *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
            } else {
                alpha = (u8)func_002b2aa0(0, 0.0f, 255.0f, *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
            }
            rgba = func_002b2a30(0xCC, 0xFF, 0xFF, alpha);
            func_00275820((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, rgba, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, i))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
            *(s16 *)(func_002b6150(i + 0x250) + 4) =
                (u8)func_00109280(((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, i))[1]) + 0x1B;
            if (((u8 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, i))[4] == 0) {
                row = i;
                color1 = func_002b2a60(0x24, 0x3F, 0x9F, 0xFF);
                *(FclDrawColor *)(func_002b6150(row + 0x238) + 0x85) = color1;
                color2 = func_002b2a60(0x24, 0x3F, 0x9F, 0xFF);
                *(FclDrawColor *)(func_002b6150(row + 0x244) + 0x85) = color2;
                shade = 0x66;
                func_002b6150(i + 0x21C)[0x6E] = shade;
                func_002b6150(row + 0x22B)[0x6E] = shade;
                func_002ba5d0(*(u8 **)(p + 0x2BC), (s8)i, 0, rowPos.position, color3 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha), 46.0f, 0x59);
            } else {
                row = i;
                color4 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                *(FclDrawColor *)(func_002b6150(row + 0x238) + 0x85) = color4;
                color5 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                *(FclDrawColor *)(func_002b6150(row + 0x244) + 0x85) = color5;
                shade = 0xCC;
                func_002b6150(i + 0x21C)[0x6E] = shade;
                func_002b6150(row + 0x22B)[0x6E] = shade;
                func_002ba5d0(*(u8 **)(p + 0x2BC), (s8)i, ((u8 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, i))[4],
                              rowPos.position, color6 = func_002b2a60(shade, 0xFF, 0xFF, alpha), 46.0f, 0x59);
            }
        }
        for (k = 0; k < *(s32 *)(func_002e4870(0) + 8); k++) {
            alpha2 = (u8)func_002b2aa0(0, 0.0f, 255.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                       *(s16 *)(func_002b6150(k + 0x270) + 0x40));
            if (*(s16 *)(p + 0x11E) == k) {
                color7 = func_002b2a60(0x2D, 0x2D, 0x2D, alpha2);
                func_002ba970((u8 *)*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(FclDrawColor *)&color7);
            } else if (func_003139d0(p[0x1A], (s8)k) == 1) {
                color8 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha2);
                func_002ba970((u8 *)*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(FclDrawColor *)&color8);
            } else {
                alpha2 = (u8)func_002b2aa0(0, 0.0f, 128.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                           *(s16 *)(func_002b6150(k + 0x270) + 0x40));
                color9 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha2);
                func_002ba970((u8 *)*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(FclDrawColor *)&color9);
            }
            rgba2 = func_002b2a30(0xCC, 0xFF, 0xFF, alpha2);
            if (*(s16 *)(p + 0x11E) == k) {
                rgba2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
            }
            func_00275820(97.0f, (f32)(k * 23 + 0x80), 43.0f, rgba2, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(0, k))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
            func_002b6150(k + 0x270)[0x6E] = func_002b6150(k + 0x27D)[0x6E] = 0x97;
            color10 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            te = func_002b6150(k + 0x27D);
            *(FclDrawColor *)(te + 0x85) = color10;
            *(FclDrawColor *)(func_002b6150(k + 0x270) + 0x85) = *(FclDrawColor *)(te + 0x85);
            objA = k + 0x297;
            objB = k + 0x28B;
            color11 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            te = func_002b6150(objA);
            *(FclDrawColor *)(te + 0x85) = color11;
            *(FclDrawColor *)(func_002b6150(objB) + 0x85) = *(FclDrawColor *)(te + 0x85);
            objC = k + 0x2A3;
            color12 = func_002b2a60(0, 0, 0x66, 0xFF);
            *(FclDrawColor *)(func_002b6150(objC) + 0x85) = color12;
            if (*(s16 *)(p + 0x11E) == k) {
                func_002b6150(k + 0x270)[0x6E] = func_002b6150(k + 0x27D)[0x6E] = 0xFF;
                color13 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                ps = func_002b6150(objA);
                *(FclDrawColor *)(ps + 0x85) = color13;
                te = func_002b6150(objB);
                *(FclDrawColor *)(te + 0x85) = *(FclDrawColor *)(ps + 0x85);
                ps = func_002b6150(k + 0x27D);
                *(FclDrawColor *)(ps + 0x85) = *(FclDrawColor *)(te + 0x85);
                *(FclDrawColor *)(func_002b6150(k + 0x270) + 0x85) = *(FclDrawColor *)(ps + 0x85);
                color14 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                *(FclDrawColor *)(func_002b6150(objC) + 0x85) = color14;
            }
        }
        for (m = 0; m < *(s32 *)(func_002e4870(1) + 8); m++) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(m + 0x21C) + 0x10), 1) == 1) {
                return;
            }
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0xC8) + 0x10), 1) == 1) {
            return;
        }
        buttons = D_008C027A[0];
        if (buttons & 0x1000) {
            func_0045af60(0, 0, 0, 0);
            *(s16 *)(p + 0x11E) = func_002b2d00(*(s16 *)(p + 0x11E), 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
            break;
        }
        if (buttons & 0x4000) {
            func_0045af60(0, 0, 0, 0);
            *(s16 *)(p + 0x11E) = func_002b2cb0(*(s16 *)(p + 0x11E), 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 2);
            break;
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            if (func_003139d0(p[0x1A], (s8)*(s16 *)(p + 0x11E)) == 1) {
                func_0045af60(0, 0, 0, 1);
                p[0x2FA] = *(s16 *)(p + 0x11E);
                *(s16 *)(p + 0x11E) = -1;
                func_00323d00(arg0, 0, 1);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                func_00317240(arg0, 0, 0.0f);
                *(s16 *)(p + 0x11E) = p[0x2FA];
                p[1] = 0x58;
                func_002b6140(*(u8 **)(p + 0x28C), 1);
                func_002b6140(*(u8 **)(p + 0x290), 1);
            } else {
                func_0045af60(0, 0, 0, 8);
            }
        } else if (buttons & 0x20) {
            func_0045af60(0, 0, 0, 2);
            p[0x2FA] = *(s16 *)(p + 0x11E);
            *(s16 *)(p + 0x11E) = -1;
            func_00323d00(arg0, 0, 1);
            *(s16 *)(p + 0x11E) = p[0x2FA];
            func_00316470(arg0, 0, 1);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
            func_003205f0(arg0, 0x96, 0x98);
            p[1] = 0x56;
        } else if (buttons & 0x80) {
            func_0045af60(0, 1, 0, 3);
            p[0x2FA] = *(s16 *)(p + 0x11E);
            *(s16 *)(p + 0x11E) = -1;
            func_00323d00(arg0, 0, 1);
            func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
            func_00317240(arg0, 0, 60.0f);
            func_002b6140(*(u8 **)(p + 0x28C), 1);
            func_002b6140(*(u8 **)(p + 0x290), 1);
            p[1] = 0x54;
        }
        break;
    case 0x54:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 1) {
            break;
        }
        id = ((u16 *)func_002e48a0(0, p[0x2FA]))[1];
        func_0010cad0((u8 *)func_002e48a0(0, p[0x2FA]), id);
        func_00314450(*(u8 **)(p + 0x148), (s32)func_002e48a0(0, p[0x2FA]), 0, 0);
        func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
        func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
        if (((u8 *)func_002e48a0(0, p[0x2FA]))[4] > (u8)func_00104c70(1)) {
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
        }
        p[1] = 0x55;
        break;
    case 0x55:
        if (func_00314660(*(u8 **)(p + 0x148)) == 5) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
            }
            buttons = D_008C024E[0];
            if (buttons & 0x80) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                    func_00314740(*(u8 **)(p + 0x148), 0);
                } else {
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00314740(*(u8 **)(p + 0x148), 1);
                }
            } else if (buttons & 0x20) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00314740(*(u8 **)(p + 0x148), 1);
                } else {
                    if (func_00314660(*(u8 **)(p + 0x148)) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(*(u8 **)(p + 0x148), 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, func_002b6150(0x1E4)[0x6E], 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if (func_00314660(*(u8 **)(p + 0x148)) < 0 || func_00314660(*(u8 **)(p + 0x148)) > 5) {
            func_00323d00(arg0, 0, 0);
            func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            *(s16 *)(p + 0x11E) = p[0x2FA];
            p[1] = 0x53;
            func_002b6140(*(u8 **)(p + 0x28C), 0);
            func_002b6140(*(u8 **)(p + 0x290), 0);
        }
        break;
    case 0x56:
        for (i = 0; i < *(s32 *)(func_002e4870(1) + 8); i++) {
            if (((s8 *)func_002e4870(*(s16 *)(p + 0x11E) + 1))[i + 0x14] == 0) {
                alpha3 = (u8)func_002b2aa0(0, 128.0f, 0.0f, *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                           *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
            } else {
                alpha3 = (u8)func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                           *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
            }
            rgba3 = func_002b2a30(0xCC, 0xFF, 0xFF, alpha3);
            func_00275820((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, rgba3, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, i))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
        }
        for (k = 0; k < *(s32 *)(func_002e4870(0) + 8); k++) {
            if (func_003139d0(p[0x1A], (s8)k) == 1) {
                alpha3 = (u8)func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                           *(s16 *)(func_002b6150(k + 0x270) + 0x40));
            } else {
                alpha3 = (u8)func_002b2aa0(0, 128.0f, 0.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                           *(s16 *)(func_002b6150(k + 0x270) + 0x40));
            }
            rgba3 = func_002b2a30(0xCC, 0xFF, 0xFF, alpha3);
            if (*(s16 *)(p + 0x11E) == k) {
                alpha3 = (u8)func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                           *(s16 *)(func_002b6150(k + 0x270) + 0x40));
                rgba3 = func_002b2a30(0x2D, 0x2D, 0x2D, alpha3);
            }
            func_00275820(97.0f, (f32)(k * 23 + 0x80), 43.0f, rgba3, 0, 2,
                          (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(0, k))[1] * 0x11),
                          0, 0, D_00795E60, 0x15);
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x2B4) + 0x10), 1) != 0) {
            break;
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x27C) + 0x10), 1) != 0) {
            break;
        }
        func_002eb270(arg0, 0);
        func_00315600(arg0, 0);
        p[1] = 0x1A;
        p[0] = 0;
        *(s16 *)(p + 0x11E) = -1;
        break;
    case 0x58:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 1) {
            break;
        }
        p[0x2F9] = 0;
        if (func_003139d0(p[0x1A], p[0x2FA]) == 1) {
            slot = p[0x2FA];
            func_002f9c30((u16 *)func_002e48a0(0, slot), (u8 *)func_002e48a0(p[0x2FA] + 1, 0),
                          (u8 *)func_002e48a0(p[0x2FA] + 1, 1), (u8 *)func_002e48a0(p[0x2FA] + 1, 2),
                          (u8 *)func_002e48a0(p[0x2FA] + 1, 3), (u8 *)func_002e48a0(p[0x2FA] + 1, 4),
                          (u8 *)func_002e48a0(slot + 1, 5), p[0x1A], 0, slot);
        }
        func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4], func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                      (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
        func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
        if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
        }
        func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
        func_00325450(arg0, (s8)(p[0x1A] + 1), 0);
        p[1] = 0x57;
        break;
    case 0x57:
        if (func_00314660(*(u8 **)(p + 0x148)) != 0xD) {
            break;
        }
        if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
            func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            p[1] = 0x59;
            func_0045af60(0, 0, 0, 1);
        } else if (buttons & 0x20) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(*(u8 **)(p + 0x148), 1);
            } else {
                p[1] = 0x5F;
                func_00314670(*(u8 **)(p + 0x148), 0xB);
                func_00325450(arg0, (s8)(p[0x1A] + 1), 1);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_00317240(arg0, 1, 0.0f);
                func_0045af60(0, 0, 0, 2);
            }
        } else if (buttons & 0x80) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                func_00314740(*(u8 **)(p + 0x148), 0);
            } else {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(*(u8 **)(p + 0x148), 1);
            }
        } else if (buttons & 8) {
            if (p[0x122] != *(s32 *)(func_002e4870(*(s16 *)(p + 0x11E) + 1) + 8)) {
                func_0045af60(0, 2, 0, 5);
            }
            p[0x122] = func_002b2cb0(p[0x122], 1, *(s32 *)(func_002e4870(*(s16 *)(p + 0x11E) + 1) + 8), 0, 1);
            switch (p[0x1A] + 1) {
            case 5:
                step = 0x55;
                obj = 0x153;
                break;
            case 6:
                step = 0x47;
                obj = 0x154;
                break;
            case 7:
                step = 0x3D;
                obj = 0x155;
                break;
            }
            stepInt = step;
            ps = func_002b6150(obj);
            pos3.position = func_002b2970((f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(obj, *(FclVec2 *)(ps + 0x38), pos3.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            pos4.position = func_002b2970((f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos4.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4], func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
            }
        } else if (buttons & 4) {
            if (p[0x122] != 0) {
                func_0045af60(0, 2, 0, 5);
            }
            p[0x122] = func_002b2d00(p[0x122], 1, 0, *(s32 *)(func_002e4870(*(s16 *)(p + 0x11E) + 1) + 8), 1);
            switch (p[0x1A] + 1) {
            case 5:
                step2 = 0x55;
                obj2 = 0x153;
                break;
            case 6:
                step2 = 0x47;
                obj2 = 0x154;
                break;
            case 7:
                step2 = 0x3D;
                obj2 = 0x155;
                break;
            }
            stepInt2 = step2;
            ps = func_002b6150(obj2);
            pos5.position = func_002b2970((f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(obj2, *(FclVec2 *)(ps + 0x38), pos5.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            pos6.position = func_002b2970((f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos6.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4], func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
            }
        }
        break;
    case 0x5F:
        if (func_00314660(*(u8 **)(p + 0x148)) != 0xE) {
            break;
        }
        *(s16 *)(p + 0x11E) = -1;
        func_00323d00(arg0, 0, 0);
        *(s16 *)(p + 0x11E) = p[0x2FA];
        func_002b6140(*(u8 **)(p + 0x28C), 0);
        func_002b6140(*(u8 **)(p + 0x290), 0);
        p[1] = 0x53;
        break;
    case 0x59:
        item = ((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1];
        if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
            func_00310960(arg0, 0x26, 0);
            p[1] = 0x5B;
            break;
        }
        if (func_00313a80(p[0x1A], func_00313ae0(p[0x1A], item)) == 1) {
            func_00310960(arg0, 0x27, 0);
            p[1] = 0x5B;
            break;
        }
        if (func_00105f50(item) == 0) {
            func_00310a10(arg0, item);
        } else {
            func_00310960(arg0, (s8)(func_00105f50(item) + 0x2E), 1);
        }
        p[1] = 0x5A;
        break;
    case 0x5A:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        if (func_002bb1c0(p[0xD]) == 0) {
            p[1] = 0x5D;
            func_00122520(1, 0xA);
        } else {
            p[1] = 0x57;
        }
        func_002bb550(p[0xD]);
        break;
    case 0x5B:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        p[1] = 0x57;
        break;
    case 0x5D:
        if (func_00122720() != 0) {
            func_00314670(*(u8 **)(p + 0x148), 0xB);
            func_00314680(*(u8 **)(p + 0x148));
            func_00325450(arg0, (s8)(p[0x1A] + 1), 1);
            for (i = 0; i < 0x30C; i++) {
                func_002b68d0(i, 0, 1);
            }
            p[1] = 0x5C;
        }
        break;
    case 0x5C:
        if (func_00314660(*(u8 **)(p + 0x148)) == 0xE) {
            p[1] = 0x5E;
            switch (((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1]) {
            case 0x17:
                func_00106390(0x130E, 1);
                break;
            case 0x57:
                func_00106390(0x130F, 1);
                break;
            case 0x93:
                func_00106390(0x1310, 1);
                break;
            case 0xB9:
                func_00106390(0x1311, 1);
                break;
            case 0x52:
                func_00106390(0x1312, 1);
                break;
            case 0x77:
                func_00106390(0x1313, 1);
                break;
            case 0x26:
                func_00106390(0x1314, 1);
                break;
            case 0x14:
                func_00106390(0x1315, 1);
                break;
            case 0x53:
                func_00106390(0x1316, 1);
                break;
            case 0x68:
                func_00106390(0x1317, 1);
                break;
            case 0x90:
                func_00106390(0x1318, 1);
                break;
            case 0xA6:
                func_00106390(0x1319, 1);
                break;
            }
        }
        break;
    case 0x5E:
        p[0xB2] = 0;
        p[0] = 0xD;
        ((u8 *)p)[1] = 0xC5;
        break;
    case 0x60:
    case 0x61:
    case 0x62:
        break;
    }
}
#pragma pop

// FUN_002F9C30
void func_002f9c30(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, u8 *arg6, s32 arg7, s8 arg8, s8 arg9) {
    u16 buf[6 * 24];
    s8 v;

    switch ((s16)arg7) {
    case 0:
        break;
    case 6:
        memcpy(buf + 5 * 24, arg6, 0x30);
        /* fallthrough */
    case 5:
        memcpy(buf + 4 * 24, arg5, 0x30);
        /* fallthrough */
    case 4:
        memcpy(buf + 3 * 24, arg4, 0x30);
        /* fallthrough */
    case 3:
        memcpy(buf + 2 * 24, arg3, 0x30);
        /* fallthrough */
    case 2:
        memcpy(buf + 1 * 24, arg2, 0x30);
        /* fallthrough */
    case 1:
        memcpy(buf, arg1, 0x30);
        break;
    }
    func_0010cad0((u8 *)arg0, arg0[1]);
    v = (s8)func_00312c60(arg0, (u8 *)buf, (s8)arg7);
    *(func_002e4870(arg8) + arg9 + 0x2E4) = v;
}

/* measured: 8460 executable bytes / 8464-byte window, verify MATCH, 298 relocations.
   Rewritten from the retail assembly: 00275820 takes its three floats first
   (frFontEx prototype), so the row y is an inline argument; each alpha and colour
   is its own int local (retail gives them distinct registers and passes them to
   002b2a30 unmasked), the 0x68 roster loop uses its own index, and the state
   range checks are written `> 5` / `> 0xD`. */
// FUN_002F9D90
void func_002f9d90(u8 *arg0) {
    extern void func_002e55c0(s8, s32, s8);
    extern void func_00324680(u8 *, s32, s32);
    extern void func_0011d140(u8 *, s32); /* retail loads the colour into $a1 */
    extern s16 func_002b2d50(s16, s16, s16, s16, s16);
    extern f32 D_00640E70[];
    FclDrawColor slotColor;
    FclDrawColor rowColor;
    FclDrawColor color0C;
    FclVec2 pos0;
    FclVec2 pos1;
    FclVec2 pos2;
    FclVec2 pos3;
    FclVec2 pos4;
    FclVec2 pos5;
    FclVec2 pos6;
    s16 j;
    u8 shade;
    u8 alpha;
    u8 alpha3;
    u8 alpha2;
    u8 alpha4;
    s32 color2;
    s32 color;
    u16 buttons;
    FclVec2 *base;
    u8 *ps;
    s16 i;
    s8 *p;

    p = *(s8 **)(arg0 + 0x38);
    switch ((u8)p[1]) {
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
        p[1] = 0x64;
        break;
    case 0x64:
        if (*(s8 *)func_002e4870(0) == 0) {
            break;
        }
        if (func_003190d0(arg0) == 1) {
            break;
        }
        p[0x20] = 0;
        for (i = 0; i < 12; i++) {
            if (((u8 *)func_002e48a0(0, i))[4] == 0) {
                p[0x20] = 1;
            }
        }
        for (i = 0; i < (u16)func_0010b5b0(); i++) {
            slotColor = func_002b2a60(0, 0, 0x99, 0xFF);
            *(FclDrawColor *)(func_0034ae50(*(u8 **)(p + 0x188), i) + 0x75) = slotColor;
        }
        p[0x129] = -1;
        p[0x128] = -1;
        *(s16 *)(p + 0x11E) = -1;
        func_00315600(arg0, 1);
        func_00324680(arg0, 2, 0);
        if (p[0x20] == 0) {
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        } else {
            func_00316e80(arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
            ps = func_002b6150(0x8A);
            *(f32 *)(ps + 0x38) += 60.0f;
        }
        base = (FclVec2 *)D_00640E70;
        pos0 = func_002b2970(base->x, base->y);
        func_002b6c30(0xC8, pos0, 42.0f, 0x5A);
        func_002b6a70(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        pos1 = func_002b2970((f32)0x28A + base->x, base->y);
        pos2 = func_002b2970(base->x - 50.0f, base->y);
        func_002b69f0(0xC8, pos1, pos2, 0, 0x14, 0);
        func_003205f0(arg0, 0x98, 0x96);
        p[1] = 0x65;
        break;
    case 0x65:
        if (func_00314660(*(u8 **)(p + 0x148)) == 0xD) {
            p[1] = 0x69;
            break;
        }
        for (i = 0; i < 12; i++) {
            if (i < *(s32 *)(func_002e4870(0) + 8)) {
                if (((u8 *)func_002e48a0(0, i))[4] > 0) {
                    alpha = (u8)func_002b2aa0(0, 0.0f, 255.0f,
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
                    shade = 0xCC;
                    func_002b6150(i + 0x21C)[0x6E] = shade;
                    func_002b6150(i + 0x22B)[0x6E] = shade;
                } else {
                    alpha = (u8)func_002b2aa0(0, 0.0f, 128.0f,
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x42),
                                          *(s16 *)(func_002b6150(i + 0x21C) + 0x40));
                    shade = 0x66;
                    func_002b6150(i + 0x21C)[0x6E] = shade;
                    func_002b6150(i + 0x22B)[0x6E] = shade;
                }
                color = func_002b2a30(0xCC, 0xFF, 0xFF, alpha);
                rowColor = func_002b2a60(0xCC, 0xFF, 0xFF, alpha);
                func_002ba970((u8 *)*(u8 **)(p + 0x2BC), i, *(FclDrawColor *)&rowColor);
                func_00275820((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, color, 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(0, i))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        alpha3 = (u8)func_002b2aa0(0, 0.0f, 255.0f, *(s16 *)(func_002b6150(0x270) + 0x42),
                              *(s16 *)(func_002b6150(0x270) + 0x40));
        color0C = func_002b2a60(0x2D, 0x2D, 0x2D, alpha3);
        func_002ba970((u8 *)*(u8 **)(p + 0x2BC), 0xC, *(FclDrawColor *)&color0C);
        func_00275820(97.0f, 195.0f, 43.0f, func_002b2a30(0x2D, 0x2D, 0x2D, alpha3), 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(1, 0))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        func_002b6150(0x270)[0x6E] = func_002b6150(0x27D)[0x6E] = 0xFF;
        if ((func_00314660(*(u8 **)(p + 0x148)) < 8 || func_00314660(*(u8 **)(p + 0x148)) > 0xD) &&
            (func_00314660(*(u8 **)(p + 0x148)) < 0 || func_00314660(*(u8 **)(p + 0x148)) > 5)) {
            for (i = 0; i < 12; i++) {
                if ((s16)func_002b6970(*(s16 *)(func_002b6150(i + 0x21C) + 0x10), 1) == 1) {
                    return;
                }
            }
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(0xC8) + 0x10), 1) == 1) {
                return;
            }
            buttons = D_008C024E[0];
            if (buttons & 0x40) {
                if (p[0x20] == 0) {
                    func_0045af60(0, 0, 0, 1);
                    p[0x2F9] = 1;
                    p[0x2FA] = 0;
                    func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0, func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                                  (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                    if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                        func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                    }
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00325450(arg0, 8, 0);
                    func_00324680(arg0, 0, 1);
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0.0f);
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (buttons & 0x80) {
                func_00324680(arg0, 0, 1);
                if (p[0x20] == 0) {
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                }
                func_00317240(arg0, 0, 60.0f);
                p[1] = 0x66;
                func_0045af60(0, 1, 0, 3);
            } else if (buttons & 0x20) {
                func_00324680(arg0, 0, 1);
                if (p[0x20] == 0) {
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    func_00316e80(arg0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                }
                p[1] = 0x68;
                func_0045af60(0, 0, 0, 2);
            }
        }
        break;
    case 0x66:
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 1) {
            break;
        }
        func_00314450(*(u8 **)(p + 0x148), (s32)func_002e48a0(1, 0), 0, 0);
        func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
        if (p[0x20] == 0) {
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
        } else {
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
        }
        p[1] = 0x67;
        break;
    case 0x67:
        if (func_00314660(*(u8 **)(p + 0x148)) == 5) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
            }
            buttons = D_008C024E[0];
            if (buttons & 0x80) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                    func_00314740(*(u8 **)(p + 0x148), 0);
                } else {
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00314740(*(u8 **)(p + 0x148), 1);
                }
            } else if (buttons & 0x20) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00314740(*(u8 **)(p + 0x148), 1);
                } else {
                    if (func_00314660(*(u8 **)(p + 0x148)) != 5) {
                        break;
                    }
                    func_0045af60(0, 1, 0, 4);
                    func_00314670(*(u8 **)(p + 0x148), 3);
                    if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1E4) + 0x10), 0) == 1) {
                        func_002b6a70(0x1E4, func_002b6150(0x1E4)[0x6E], 0, 0, 0xA, 0);
                    }
                }
            }
        }
        if (func_00314660(*(u8 **)(p + 0x148)) < 0 || func_00314660(*(u8 **)(p + 0x148)) > 5) {
            func_00324680(arg0, 0, 0);
            if (p[0x20] == 0) {
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            } else {
                func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                ps = func_002b6150(0x8A);
                *(f32 *)(ps + 0x38) += 60.0f;
            }
            p[1] = 0x65;
        }
        break;
    case 0x68:
        for (j = 0; j < *(s32 *)(func_002e4870(0) + 8); j++) {
            alpha2 = (u8)func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(func_002b6150(j + 0x21C) + 0x42),
                                  *(s16 *)(func_002b6150(j + 0x21C) + 0x40));
            color2 = func_002b2a30(0xCC, 0xFF, 0xFF, alpha2);
            if (*(s16 *)(p + 0x11E) == j) {
                color2 = func_002b2a30(0x2D, 0x2D, 0x2D, alpha2);
            }
            func_00275820((f32)0x19D, (f32)(j * 23 + 0x80), 43.0f, color2, 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(0, j))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        }
        alpha4 = (*(s32 *)(func_002e4870(0) + 8) >= 0xC)
                    ? (u8)func_002b2aa0(0, 255.0f, 0.0f, *(s16 *)(func_002b6150(0x270) + 0x42),
                                        *(s16 *)(func_002b6150(0x270) + 0x40))
                    : (u8)func_002b2aa0(0, 128.0f, 0.0f, *(s16 *)(func_002b6150(0x270) + 0x42),
                                        *(s16 *)(func_002b6150(0x270) + 0x40));
        func_00275820(97.0f, 195.0f, 43.0f, func_002b2a30(0xCC, 0xFF, 0xFF, alpha4), 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(1, 0))[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x71) + 0x10), 1) == 0 &&
            (s16)func_002b6970(*(s16 *)(func_002b6150(0x70) + 0x10), 1) == 0) {
            func_002eb270(arg0, 0);
            func_00315600(arg0, 0);
            func_003205f0(arg0, 0x96, 0x98);
            p[1] = 0x1A;
            p[0] = 0;
        }
        break;
    case 0x69:
        if (func_00314660(*(u8 **)(p + 0x148)) != 0xD) {
            break;
        }
        if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
            func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
        }
        buttons = D_008C024E[0];
        if (buttons & 0x40) {
            func_002e48a0(p[0x2F9], p[0x2FA]);
            func_0045af60(0, 0, 0, 1);
            if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                func_00310960(arg0, 0x26, 0);
                p[1] = 0x6B;
            } else {
                func_00310960(arg0, 0x39, 1);
                p[1] = 0x6A;
            }
        } else if (buttons & 0x80) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                func_00314740(*(u8 **)(p + 0x148), 0);
            } else {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(*(u8 **)(p + 0x148), 1);
            }
        } else if (buttons & 0x20) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(*(u8 **)(p + 0x148), 1);
            } else {
                func_00314670(*(u8 **)(p + 0x148), 0xB);
                func_00325450(arg0, 8, 1);
                func_00324680(arg0, 0, 0);
                if (p[0x20] == 0) {
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                } else {
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
                }
                func_00317240(arg0, 1, 0.0f);
                p[1] = 0x65;
                func_0045af60(0, 0, 0, 2);
            }
        } else if (D_008C024E[2] & 8) {
            if (p[0x122] != 0xC) {
                func_0045af60(0, 2, 0, 5);
            }
            p[0x122] = func_002b2cb0(p[0x122], 1, 0xC, 0, 1);
            *(s16 *)(p + 0x120) = func_002b2d50(p[0x122], *(s16 *)(p + 0x120), 0xC, 7, 1);
            ps = func_002b6150(0x155);
            pos3 = func_002b2970((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x155, *(FclVec2 *)(ps + 0x38), pos3, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            pos4 = func_002b2970((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos4, 1, 4, 0);
            func_00329310(arg0, 0, 0);
            if (p[0x122] < 0xC) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(0, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0, func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
            }
        } else if (D_008C024E[2] & 4) {
            if (p[0x122] != 0) {
                func_0045af60(0, 2, 0, 5);
            }
            p[0x122] = func_002b2d00(p[0x122], 1, 0, 0, 1);
            *(s16 *)(p + 0x120) = func_002b2d50(p[0x122], *(s16 *)(p + 0x120), 0xC, 7, -1);
            ps = func_002b6150(0x155);
            pos5 = func_002b2970((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x155, *(FclVec2 *)(ps + 0x38), pos5, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            pos6 = func_002b2970((f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos6, 1, 4, 0);
            func_00329310(arg0, 0, 0);
            if (p[0x122] < 0xC) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(0, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0, func_00311930(func_00247770(iGpffffb3d4[((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]))[1] * 14 + 2]),
                              (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
            }
        }
        break;
    case 0x6A:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        if (func_002bb1c0(p[0xD]) == 0) {
            p[1] = 0x6C;
            func_00122520(1, 0xA);
        } else {
            p[1] = 0x69;
        }
        func_002bb550(p[0xD]);
        break;
    case 0x6B:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
            break;
        }
        func_002bb550(p[0xD]);
        p[1] = 0x69;
        break;
    case 0x6C:
        if (func_00122720() != 0) {
            func_00314670(*(u8 **)(p + 0x148), 0xB);
            func_00314680(*(u8 **)(p + 0x148));
            func_00325450(arg0, 8, 1);
            *(s16 *)(p + 0x11E) = p[0x122];
            for (i = 0; i < 0x30C; i++) {
                func_002b68d0(i, 0, 1);
            }
            p[1] = 0x6D;
        }
        break;
    case 0x6D:
        if (func_00314660(*(u8 **)(p + 0x148)) == 0xE) {
            p[0xB2] = 0;
            p[0] = 0xD;
            ((u8 *)p)[1] = 0xC5;
        }
        break;
    }
}

/* measured: all 26320 bytes match; distinct caption origin and mutable
 * iterator lifetimes retain the retail loop allocation. */
#pragma push
#pragma opt_lifetimes on
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xA9];
    s8 fB7;
    u8 padB8[0x66];
    s16 f11E;
    s16 f120;
    s8 f122;
    s8 f123;
    f32 f124;
    s8 f128;
    s8 f129;
    u8 pad12A[0x10];
    s8 f13A;
    u8 pad13B[0xD];
    u8 * f148;
    u8 pad14C[0x108];
    s32 f254;
    u8 pad258[0x34];
    s32 f28C;
    s32 f290;
    u8 pad294[0x18];
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    u8 pad2C0[0x60];
} FclCombineSel;

// FUN_002FBEA0
void func_002fbea0(u8 *arg0) {

    struct {
        s16 firstEntry;
        u8 alpha;
        s32 fontColor;
    } caption;
    FclCombineSel *p;
    u8 state;
    FclDrawColor fc_colW5;
    FclDrawColor fc_colW7;
    FclDrawColor fc_colW4;
    FclDrawColor fc_colW2;
    FclVec2f rowOrigin;
    u8 *ps;
    s32 var_16_6;
    s16 var_18;
    s16 var_19;
    s32 var_22;
    f32 temp_f20;
    u8 temp_7;
    s32 var_21;
    s32 total;
    s32 saved;
    s16 drawSlot;
    u16 bitSav;
    u16 originalFlags;
    s32 tmpu8;

    char sp2A0[32];
    char sp220[128];
    s16 sp1B0;
    p = *(FclCombineSel **)(arg0 + 0x38);
    state = p->f1;
    switch (state) {
    case 0x8A:
        func_00315600(arg0, 1);
        if (p->f0 == 0x10) {
            func_002e4610(6, 0);
        } else if (p->f0 == 0xF) {
            if (datGetFlag(0x1460) != 0) {
                func_002e4610(8, 0);
            } else {
                func_002e4610(2, 0);
            }
        }
        p->f11E = 0;
        p->f120 = 0;
        p->f129 = -1;
        p->f128 = -1;
        p->f123 = 0;
        p->f1 = 0x8B;
        return;
    case 0x8B:
        if (*(s8 *)func_002e4870(0) == 0) {
            return;
        }
        for (var_19 = 0; var_19 < p->fB7; var_19++) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150(var_19 * 2 + 0x1F8) + 0x10), 1) == 1) {
                return;
            }
        }
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
            p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
        }
        if (p->f0 == 0x10) {
            if (*(s32 *)(func_002e4870(0) + 8) == 0) {
                p->fD = func_002bab80((void *)func_00331660());
                func_002badc0(p->fD, 0xE);
                p->f1 = 0x93;
            } else {
                func_0032b770(arg0, 2, var_16_6, 0);
                p->f1 = 0x8D;
            }
        } else if (p->f0 == 0xF) {
            p->f123 = 0;
            if (datGetFlag(0x1460) == 0) {
                func_002e68b0(0);
            }
            func_0032b9d0(arg0, 2, var_16_6, 0);
            p->f1 = 0x98;
        }
        *(u8 *)(func_002b6150(p->f11E + 0x270) + 0x6E) = *(u8 *)(func_002b6150(p->f11E + 0x27D) + 0x6E) = 0xFF;
        func_002b68d0(0x270, 2, 1);
        func_002b68d0(0x27D, 2, 1);
        *(FclDrawColor *)(func_002b6150(p->f11E + 0x270) + 0x85) = *(FclDrawColor *)((func_002b6150(p->f11E + 0x27D)) + 0x85) = *(FclDrawColor *)((func_002b6150(p->f11E + 0x28B)) + 0x85) = *(FclDrawColor *)((func_002b6150(p->f11E + 0x297)) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
        *(FclDrawColor *)(func_002b6150(p->f11E + 0x2A3) + 0x85) = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970((u8 *)p->f2BC, (s8)(p->f11E + 0xC), func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
        return;
    case 0x8D:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        var_19 = p->f11E - p->f120;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            temp_7 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fc_colW5 = func_002b2a60(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fc_colW5 = func_002b2a60(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(244.0f, (f32)(s32)((var_18 * 0x17) + 0x6E), 43.0f, var_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            drawSlot = (s8)(var_18 + 0xC);
            func_002ba5d0((u8 *)p->f2BC, drawSlot,
                          *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4),
                          func_002b2970(146.0f, 111.0f + 23.0f * (f32)var_18),
                          fc_colW5, 46.0f, 0x59);
            *(s16 *)(func_002b6150(((var_18 + 0x2A3))) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x10), 1) == 0) {
                if ((s16)var_19 == p->f11E) {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0xFF;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970((u8 *)p->f2BC, drawSlot, func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0x80;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0, 0, 0x66, 0xFF);
                    func_002ba970((u8 *)p->f2BC, drawSlot, func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            var_19++;
            var_18++;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((((s16)var_16_6 + 0x26F))) + 0x10), 1) == 1) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            func_0032c0c0(arg0, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                break;
            }
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 3);
            return;
        } else if (D_008C024E[0] & 0x40) {
            if (*(s32 *)(func_002e4870(0) + 8) > p->f11E) {
                p->f122 = 0;
                var_16_6 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                    var_16_6 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                    p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b770(arg0, 0, var_16_6, 1);
                p->f1 = 0x8E;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                p->fD = func_002bab80((void *)func_00331660());
                func_002bafc0(p->fD, 0);
                func_002badc0(p->fD, 0xC);
                func_002bb0a0(p->fD, 0);
                func_002bbf60();
                p->f1 = 0x96;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            var_19 = p->f11E - p->f120;
            var_18 = 0;
            var_22 = (s16)var_16_6 + var_19;
            while (var_19 < var_22) {
                func_0031ac10(arg0, func_002b2970(162.0f, 111.0f), -1, var_18, *(u16 *)((u8 *)func_002e48a0(0, var_19) + 2), *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4), 0, 1, 0, 0xCC);
                var_19++;
                var_18++;
            }
            func_0031e5b0(arg0, func_002b2970(156.0f, 87.0f), 0, 1, 0, 1, 1);
            func_00324f80(arg0, func_002b2970(472.0f, 112.0f), 0, 1);
            func_003297f0((f32)0x1A1, 220.0f, arg0, 0, 1);
            p->f1 = 0x94;
            func_0045af60(0, 0, 0, 2);
        }
        p->f13A = 0;
        break;
    case 0x95:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            originalFlags = *(u16 *)func_002e48a0(0, p->f11E);
            if (*(u16 *)func_002e48a0(0, p->f11E) & 4) {
                *(u16 *)func_002e48a0(0, p->f11E) = 0;
                *(u16 *)func_002e48a0(0, p->f11E) |= 1;
                func_0010fd40(func_002e48a0(0, p->f11E));
                *(u16 *)func_002e48a0(0, p->f11E) = originalFlags;
            } else {
                func_0010fd40(func_002e48a0(0, p->f11E));
            }
            func_002bb550(p->fD);
            p->fD = func_002bab80((void *)func_00331660());
            func_002badc0(p->fD, 0xD);
            p->f1 = 0x91;
            return;
        }
        p->f1 = 0x8F;
        func_002bb550(p->fD);
        return;
    case 0x96:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        var_19 = p->f11E - p->f120;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            temp_7 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(244.0f, (f32)(s32)((var_18 * 0x17) + 0x6E), 43.0f, var_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            var_19++;
            var_18++;
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            var_19 = 0;
            while (var_19 < *(s32 *)(func_002e4870(0) + 8)) {
                bitSav = *(u16 *)func_002e48a0(0, var_19);
                if (*(u16 *)func_002e48a0(0, var_19) & 4) {
                    *(u16 *)func_002e48a0(0, var_19) = 0;
                    *(u16 *)func_002e48a0(0, var_19) |= 1;
                    func_0010fd40(func_002e48a0(0, var_19));
                    *(u16 *)func_002e48a0(0, var_19) = bitSav;
                } else {
                    func_0010fd40(func_002e48a0(0, var_19));
                }
                var_19++;
            }
            func_002bb550(p->fD);
            p->fD = func_002bab80((void *)func_00331660());
            func_002badc0(p->fD, 0xD);
            p->f1 = 0x92;
            func_0032b770(arg0, 0, var_16_6, 1);
            return;
        }
        p->f1 = 0x8D;
        func_002bb550(p->fD);
        return;
    case 0x8E:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_002b6140((u8 *)(p->f28C), 1);
            func_002b6140((u8 *)(p->f290), 1);
            func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
            func_0011c6e0(func_003147d0(p->f148), 1);
            func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 0, 0);
            p->f1 = 0x8F;
            return;
        }
        break;
    case 0x8F:
        if ((s8)func_00314660(p->f148) != 5) {
            break;
        }
        if (func_0011c610(func_003147d0(p->f148)) == 1) {
            func_0011caf0(func_003147d0(p->f148));
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 5);
                if (p->f122 == 0) {
                    func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                    goto conv8F;
                }
                if (p->f11E != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 1);
                if (p->f122 == 0) {
                    func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 1) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 5);
            if (p->f122 == 0) {
                func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 4);
                if (p->f122 == 0) {
                    func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                    goto conv8F;
                }
                if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 0);
                if (p->f122 == 0) {
                    func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                    func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0252[0] & 2) {
            if (*(s32 *)(func_002e4870(0) + 8) <= 1) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 4);
            if (p->f122 == 0) {
                func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            if (p->f122 == 0) {
                func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if (D_008C024E[0] & 8) {
            if (p->f122 == 1) {
                p->f122 = 0;
                ps = func_002b6150(0x150);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), func_002b2970((f32)0x141, 16.0f), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), func_002b2970((f32)0x141, 16.0f), 1, 4, 0);
                func_00314560(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 4) {
            if (p->f122 == 0) {
                p->f122 = 1;
                ps = func_002b6150(0x150);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), func_002b2970(107.0f, 16.0f), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), func_002b2970(107.0f, 16.0f), 1, 4, 0);
                func_00314560(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 0);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 0x40) {
            p->fD = func_002bab80((void *)func_00331660());
            sprintf(sp2A0, &iGpffffa8a4, ((char *)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11));
            func_002bbd80(p->fD, 0, &sp2A0);
            func_002bafc0(p->fD, 0);
            func_002badc0(p->fD, 0xB);
            func_002bb0a0(p->fD, 0);
            func_002bbf60();
            p->f1 = 0x95;
            func_0045af60(0, 0, 0, 1);
            goto conv8F;
        } else if (D_008C024E[0] & 0x20) {
            if (func_0011ba00(func_003147d0(p->f148)) == 1) {
                break;
            }
            if (func_0011c610(func_003147d0(p->f148)) == 1) {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(p->f148, 1);
            } else {
                func_00314670(p->f148, 3);
                func_00325450(arg0, 0, 1);
                p->f1 = 0x90;
                func_0045af60(0, 0, 0, 2);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                func_0011c630(func_003147d0(p->f148));
                func_00314740(p->f148, 0);
            } else {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(p->f148, 1);
            }
        }
    conv8F:
        p->f13A = 0;
        break;
    case 0x90:
        if (((s8)func_00314660(p->f148) < 0 || (s8)func_00314660(p->f148) > 5) && *(s8 *)func_002e4870(0) != 0) {
            var_16_6 = *(s16 *)(func_002e4870(0) + 8);
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                var_16_6 = 8;
            }
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
            }
            func_002b6140((u8 *)(p->f28C), 0);
            func_002b6140((u8 *)(p->f290), 0);
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                func_0032b770(arg0, 0, var_16_6, 0);
                p->f11E = 0;
                p->f120 = 0;
                p->f1 = 0x8B;
                return;
            }
            p->fD = func_002bab80((void *)func_00331660());
            func_002badc0(p->fD, 0xE);
            p->f1 = 0x93;
            return;
        }
        break;
    case 0x91:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_00314670(p->f148, 3);
        func_00325450(arg0, 0, 1);
        func_002e4610(6, 0);
        p->f1 = 0x90;
        return;
    case 0x92:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x93:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        p->f0 = 0;
        p->f1 = 0x1B;
        return;
    case 0x97:
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        if (func_00302570(arg0) == 0) {
            if ((s8)func_00314660(p->f148) == 5) {
                func_00314670(p->f148, 3);
                func_00325450(arg0, 0, 1);
            }
            p->f1 = 0x8D;
            return;
        }
        break;
    case 0x94:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        var_19 = p->f11E - p->f120;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            temp_7 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_18) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(244.0f, (f32)(s32)((var_18 * 0x17) + 0x6E), 43.0f, var_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            var_19++;
            var_18++;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x118);
            func_00315600(arg0, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x98:
        func_002cacd0(func_002b2970(250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f), 47.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, func_002e7a60(), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        var_19 = p->f11E - p->f120;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            temp_7 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fc_colW7 = func_002b2a60(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fc_colW7 = func_002b2a60(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(172.0f, (f32)(s32)((var_18 * 0x17) + 0x96), 43.0f, var_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x2A3))) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150(((var_18 + 0x2A3))) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            sp1B0 = (s8)(var_18 + 0xC);
            tmpu8 = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
            func_002ba5d0((u8 *)p->f2BC, sp1B0, tmpu8, func_002b2970(74.0f, 151.0f + 23.0f * (f32)var_18), fc_colW7, 46.0f, 0x59);
            total = ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) * ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002cacd0(func_002b2970(510.0f, (f32)(s32)((var_18 * 0x17) + 0x9E)), 47.0f, fc_colW7, 0x10, 5, func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x10), 1) == 0) {
                if ((s16)var_19 == p->f11E) {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0xFF;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970((u8 *)p->f2BC, sp1B0, func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0x80;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0, 0, 0x66, 0xFF);
                    func_002ba970((u8 *)p->f2BC, sp1B0, func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x21F))) + 0x10), 1) == 0) {
                if ((s16)var_19 == p->f11E) {
                    *(u8 *)(func_002b6150(((var_18 + 0x21F))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x2C5))) + 0x6E) = 0xFF;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x21F)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x2C5)))) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                } else {
                    *(u8 *)(func_002b6150(((var_18 + 0x21F))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x2C5))) + 0x6E) = 0x80;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x21F)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x2C5)))) + 0x85) = func_002b2a60(0, 0, 0x99, 0xFF);
                }
            }
            var_19++;
            var_18++;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((((s16)var_16_6 + 0x26F))) + 0x10), 1) == 1) {
            return;
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (p->f11E != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 3);
            return;
        } else if (D_008C0276[0] & 8) {
            if (p->f123 == 0) {
                if (datGetFlag(0x1460) == 0) {
                    func_002e6c90(0);
                }
                p->f123 = 1;
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2EA) + 0x38);
                func_002b69f0(0x2EA, rowOrigin, func_002b2970(336.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2EB) + 0x38);
                func_002b69f0(0x2EB, rowOrigin, func_002b2970(556.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2E2) + 0x38);
                func_002b69f0(0x2E2, rowOrigin, func_002b2970(336.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2E3) + 0x38);
                func_002b69f0(0x2E3, rowOrigin, func_002b2970(556.0f, rowOrigin.y), 1, 8, 0);
                func_0045af60(0, 0, 0, 5);
            }
            goto conv98;
        } else if (D_008C0276[0] & 4) {
            if (p->f123 == 1) {
                if (datGetFlag(0x1460) == 0) {
                    func_002e68b0(0);
                }
                p->f123 = 0;
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2EA) + 0x38);
                func_002b69f0(0x2EA, rowOrigin, func_002b2970(79.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2EB) + 0x38);
                func_002b69f0(0x2EB, rowOrigin, func_002b2970((f32)0x12B, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2E2) + 0x38);
                func_002b69f0(0x2E2, rowOrigin, func_002b2970(79.0f, rowOrigin.y), 1, 8, 0);
                rowOrigin = *(FclVec2f *)(func_002b6150(0x2E3) + 0x38);
                func_002b69f0(0x2E3, rowOrigin, func_002b2970((f32)0x12B, rowOrigin.y), 1, 8, 0);
                func_0045af60(0, 0, 0, 5);
            }
            goto conv98;
        } else if (D_008C024E[0] & 0x40) {
            p->f122 = 0;
            var_16_6 = *(s16 *)(func_002e4870(0) + 8);
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                var_16_6 = 8;
            }
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
            }
            func_0032b9d0(arg0, 0, var_16_6, 1);
            p->f1 = 0x99;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            var_16_6 = *(s16 *)(func_002e4870(0) + 8);
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                var_16_6 = 8;
            }
            if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
            }
            func_0032b9d0(arg0, 0, var_16_6, 1);
            p->f1 = 0x9C;
            func_0045af60(0, 0, 0, 2);
        }
    conv98:
        p->f13A = 0;
        break;
    case 0x9D:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630((u8 *)p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9E:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630((u8 *)p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        if (func_002bb1c0(p->fD) == 0) {
            func_0010b190((u8 *)func_002e48a0(0, p->f11E));
            total = ((func_001099f0((u8 *)func_002e48a0(0, p->f11E), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 4) & 0xFF)) * ((func_001099f0((u8 *)func_002e48a0(0, p->f11E), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 4) & 0xFF)) + 0x7D0;
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2), total);
            func_002e7a80(func_002e7a60() - saved);
            func_002bb550(p->fD);
            p->fD = func_002bab80((void *)func_00331660());
            func_002bbd80(p->fD, 0, (void *)(((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11)));
            func_002badc0(p->fD, 0x10);
            p->f1 = 0x9F;
            func_0045af60(1, 0, 2, 6);
            if (p->f2B8 != 0) {
                p->f2B8 = 0;
            }
            p->f2B8 = (s32)func_00349290(arg0, p->f122);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x9F:
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630((u8 *)p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if (func_002bb680(p->fD) != 0) {
            func_002bbcf0(p->fD);
            return;
        }
        func_002bb550(p->fD);
        p->f1 = 0x9A;
        return;
    case 0x99:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_00314750(p->f148, 0);
            func_00314450(p->f148, (s32)func_002e48a0(0, p->f11E), 0, 1);
            func_0011c6e0(func_003147d0(p->f148), 1);
            func_0011d140(func_003147d0(p->f148), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 1, 0);
            p->f1 = 0x9A;
            return;
        }
        break;
    case 0x9A:
        if ((s8)func_00314660(p->f148) < 0 || (s8)func_00314660(p->f148) > 5) {
            break;
        }
        func_002b6140((u8 *)p->f28C, 1);
        func_002b6140((u8 *)p->f290, 1);
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        func_002b68d0(0x80, 0, 1);
        func_002b68d0(0x20C, 0, 1);
        if (p->f122 == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630((u8 *)p->f254) + 1) = 1;
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
        }
        if ((s8)func_00314660(p->f148) != 5) {
            return;
        }
        if (func_0011c610(func_003147d0(p->f148)) == 1) {
            func_0011caf0(func_003147d0(p->f148));
        }
        if ((D_008C0276[0] & 0x1000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) != 0) {
                return;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 5);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (func_0011c610(func_003147d0(p->f148)) != 0) {
                return;
            }
            if (p->f11E != 0) {
                func_0045af60(0, 2, 0, 5);
            }
            func_0032c0c0(arg0, 1);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            return;
        } else if (D_008C0252[0] & 1) {
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 5);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            return;
        } else if ((D_008C0276[0] & 0x4000) && (p->f13A == 0)) {
            if (func_0011c610(func_003147d0(p->f148)) != 0) {
                return;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 4);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (func_0011c610(func_003147d0(p->f148)) != 0) {
                return;
            }
            if (p->f11E != (s16)((*(s32 *)(func_002e4870(0) + 8) - 1))) {
                func_0045af60(0, 2, 0, 5);
            }
            func_0032c0c0(arg0, 0);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            return;
        } else if (D_008C0252[0] & 2) {
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 4);
            func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
            goto conv9A;
        } else if (D_008C024E[0] & 0x80) {
            if (p->f122 == 1) {
                return;
            }
            if (func_0011c610(func_003147d0(p->f148)) == 0) {
                func_0011c630(func_003147d0(p->f148));
                func_00314740(p->f148, 0);
            } else {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(p->f148, 1);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 8) {
            if (p->f122 == 1) {
                p->f122 = 0;
                ps = func_002b6150(0x150);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), func_002b2970((f32)0x141, 16.0f), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), func_002b2970((f32)0x141, 16.0f), 1, 4, 0);
                func_00314750(p->f148, 0);
                func_0032a960(arg0, 1);
                func_002b5e90((u8 *)p->f2AC, func_002b2970(0.0f, 0.0f), func_002b2970(0.0f, -7.0f), 4);
                func_002b5e90((u8 *)p->f2B0, func_002b2970(0.0f, 432.0f), func_002b2970(0.0f, 480.0f), 6);
                func_002b5ef0((u8 *)p->f2B4, func_002b2970(0.0f, 69.0f), func_002b2970(0.0f, 93.0f), func_002b29e0(640.0f, (f32)0x157), func_002b29e0(640.0f, 294.0f), 5);
                func_002b60f0((u8 *)p->f2B4, 0xE5, 0, 5);
                func_00317320(arg0, 0, 0.0f);
                func_00314450(p->f148, (s32)func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)), 0, 1);
                func_0045af60(0, 0, 0, 5);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 4) {
            if (p->f122 == 0) {
                p->f122 = 1;
                ps = func_002b6150(0x150);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), func_002b2970(107.0f, 16.0f), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), func_002b2970(107.0f, 16.0f), 1, 4, 0);
                func_00314750(p->f148, 1);
                func_0032a960(arg0, 0);
                func_0045af60(0, 0, 0, 5);
                func_002b5e90((u8 *)p->f2AC, func_002b2970(0.0f, -10.0f), func_002b2970(0.0f, 0.0f), 4);
                func_002b5e90((u8 *)p->f2B0, func_002b2970(0.0f, 480.0f), func_002b2970(0.0f, 432.0f), 6);
                func_002b5ef0((u8 *)p->f2B4, func_002b2970(0.0f, 93.0f), func_002b2970(0.0f, 69.0f), func_002b29e0(640.0f, 294.0f), func_002b29e0(640.0f, (f32)0x157), 5);
                func_002b60f0((u8 *)p->f2B4, 0, 0xE5, 5);
                func_00317240(arg0, 1, 0.0f);
            }
            goto conv9A;
        } else if (D_008C024E[0] & 0x40) {
            func_0045af60(0, 0, 0, 1);
            if (func_0010ac10(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2)) != 0) {
                func_00310960(arg0, 0x12, 0);
                p->f1 = 0x9D;
                return;
            }
            if ((func_0010b5b0() & 0xFFFF) <= (func_0010b6f0() & 0xFFFF)) {
                func_00310960(arg0, 0x14, 0);
                p->f1 = 0x9D;
                return;
            }
            total = ((func_001099f0((u8 *)func_002e48a0(0, p->f11E), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 4) & 0xFF)) * ((func_001099f0((u8 *)func_002e48a0(0, p->f11E), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, p->f11E), 4) & 0xFF)) + 0x7D0;
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + 2), total);
            if (func_002e7a60() >= saved) {
                p->fD = func_002bab80((void *)func_00331660());
                sprintf(sp2A0, &iGpffffa8a4, ((char *)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, p->f11E)) + (2))) * 0x11));
                func_002bbd80(p->fD, 0, &sp2A0);
                sprintf(sp220, &iGpffffa8a0, saved);
                func_002bbd80(p->fD, 1, &sp220);
                func_002bafc0(p->fD, 0);
                func_002badc0(p->fD, 0xF);
                func_002bb0a0(p->fD, 0);
                func_002bbf60();
                p->f1 = 0x9E;
                goto conv9A;
            } else {
                func_00310960(arg0, 0x11, 0);
                p->f1 = 0x9D;
                goto conv9A;
            }
        } else if (D_008C024E[0] & 0x20) {
            if (func_0011ba00(func_003147d0(p->f148)) == 1) {
                return;
            }
            if (func_0011c610(func_003147d0(p->f148)) == 1 && p->f122 == 0) {
                func_0011c6e0(func_003147d0(p->f148), 1);
                func_00314740(p->f148, 1);
            } else {
                func_0045af60(0, 0, 0, 2);
                func_00314670(p->f148, 3);
                func_00325450(arg0, 1, 1);
                if (p->f122 == 1) {
                    func_0032a960(arg0, 1);
                    func_002b5e90((u8 *)p->f2AC, func_002b2970(0.0f, 0.0f), func_002b2970(0.0f, -7.0f), 5);
                    func_002b5e90((u8 *)p->f2B0, func_002b2970(0.0f, 432.0f), func_002b2970(0.0f, 480.0f), 5);
                    func_002b5ef0((u8 *)p->f2B4, func_002b2970(0.0f, 69.0f), func_002b2970(0.0f, 239.0f), func_002b29e0(640.0f, (f32)0x157), func_002b29e0(640.0f, 0.0f), 5);
                } else {
                    func_00317240(arg0, 1, 0.0f);
                }
                func_0034a890((u8 *)p->f254);
                var_16_6 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                    var_16_6 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) > 8) {
                    p->f124 = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b9d0(arg0, 0, var_16_6, 0);
                p->f1 = 0x9B;
                *(s8 *)(func_0034a630((u8 *)p->f254) + 1) = 1;
                func_0034a840((u8 *)p->f254);
                func_002b68d0(0x80, 0, 0);
                func_002b68d0(0x20C, 0, 0);
                func_002b6140((u8 *)p->f28C, 0);
                func_002b6140((u8 *)p->f290, 0);
                func_002b68d0(0x84, 0, 0);
                func_002b68d0(0x85, 0, 0);
                func_002b68d0(0x1C6, 0, 0);
            }
            goto conv9A;
        }
    conv9A:
        p->f13A = 0;
        return;
    case 0x9B:
        func_002cacd0(func_002b2970(250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f), 47.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, func_002e7a60(), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        var_19 = p->f11E - p->f120;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            temp_7 = (u8)func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fc_colW4 = func_002b2a60(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fc_colW4 = func_002b2a60(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(172.0f, (f32)(s32)((var_18 * 0x17) + 0x96), 43.0f, var_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x2A3))) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150(((var_18 + 0x2A3))) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            total = ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) * ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002cacd0(func_002b2970(510.0f, (f32)(s32)((var_18 * 0x17) + 0x9E)), 47.0f, fc_colW4, 0x10, 5, func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x10), 1) == 0) {
                if ((s16)var_19 == p->f11E) {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0xFF;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970((u8 *)p->f2BC, (s8)(var_18 + 0xC), func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF));
                } else {
                    *(u8 *)(func_002b6150(((var_18 + 0x270))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x27D))) + 0x6E) = 0x80;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x270)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x27D)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x28B)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x297)))) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x2A3)))) + 0x85) = func_002b2a60(0, 0, 0x66, 0xFF);
                    func_002ba970((u8 *)p->f2BC, (s8)(var_18 + 0xC), func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF));
                }
            }
            if (func_002b6970(*(s16 *)(func_002b6150(((var_18 + 0x21F))) + 0x10), 1) == 0) {
                if ((s16)var_19 == p->f11E) {
                    *(u8 *)(func_002b6150(((var_18 + 0x21F))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x2C5))) + 0x6E) = 0xFF;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x21F)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x2C5)))) + 0x85) = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                } else {
                    *(u8 *)(func_002b6150(((var_18 + 0x21F))) + 0x6E) = *(u8 *)(func_002b6150(((var_18 + 0x2C5))) + 0x6E) = 0x80;
                    *(FclDrawColor *)((func_002b6150(((var_18 + 0x21F)))) + 0x85) = *(FclDrawColor *)((func_002b6150(((var_18 + 0x2C5)))) + 0x85) = func_002b2a60(0, 0, 0x99, 0xFF);
                }
            }
            var_19++;
            var_18++;
        }
        if ((s8)func_00314660(p->f148) == 6) {
            func_0011d1d0(func_003147d0(p->f148), 0.0f);
            p->f1 = 0x98;
            return;
        }
        break;
    case 0x9C:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) > 8) {
            var_16_6 = 8;
        }
        caption.firstEntry = p->f11E - p->f120;
        func_002cacd0(func_002b2970(254.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f), 47.0f, func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF), 0x10, 5, func_002e7a60(), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0x56);
        var_19 = caption.firstEntry;
        var_18 = 0;
        var_22 = (s16)var_16_6 + var_19;
        while (var_19 < var_22) {
            temp_f20 = (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x42));
            caption.alpha = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)(*(s16 *)(func_002b6150(((var_18 + 0x270))) + 0x40)));
            if (p->f11E == var_19) {
                caption.fontColor = func_002b2a30(0x2D, 0x2D, 0x2D, caption.alpha);
                fc_colW2 = func_002b2a60(0x2D, 0x2D, 0x2D, caption.alpha);
            } else {
                caption.fontColor = func_002b2a30(0xCC, 0xFF, 0xFF, caption.alpha);
                fc_colW2 = func_002b2a60(0xCC, 0xFF, 0xFF, caption.alpha);
            }
            func_00275820(172.0f, (f32)(s32)((var_18 * 0x17) + 0x96), 43.0f, caption.fontColor, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11)), 0, 0, D_00795E60, 0x15);
            total = ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) * ((func_001099f0((u8 *)func_002e48a0(0, var_19), 0) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 1) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 2) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 3) & 0xFF) + (func_001099f0((u8 *)func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002cacd0(func_002b2970(510.0f, (f32)(s32)((var_18 * 0x17) + 0x9E)), 47.0f, fc_colW2, 0x10, 5, func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total), 9, 0x37, (s32)func_0046a770(&D_00641B30), func_00331560(), 0xAA);
            var_19++;
            var_18++;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x117);
            func_00315600(arg0, 0);
            p->f0 = 0;
            p->f1 = 0x1B;
            return;
        }
        break;
    case 0x8C:
        break;
    default:
        return;
    }
}

#pragma pop
// FUN_00302570
s32 func_00302570(u8 *arg0) {
    u8 *p;
    s32 idx;
    s8 i;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0x130) = 0;
    i = 0;
    while ((s32)i < 4) {
        if ((datGetFlag((s32)i + 0x1309) == 0) && (func_00110140() >= D_00749100[(s32)i])) {
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
s32 func_003026c0(u16 arg0, s32 arg1)
{
    s16 i;

    func_00109280(arg0);
    for (i = 0; i < 4; i++) {
        if (datGetFlag(0x130C - i) != 0) {
            return arg1 - (arg1 / 100) * (0x19 - i * 5);
        }
    }
    return arg1;
}

/* MATCHED: no pragmas. Retail-order rewrite of the guarded draft: both
   bb680 tests take the busy arm first; the 0xD store is re-read as
   *(s8 *)(p + 0xD) (b210 forwards it); the tracked positions are FclVec2f
   struct copies in and out of func_002b81f0; func_002b69f0 takes FclVec2f
   by value, so *(FclVec2f *)(q + 0x38) gives retail's ldr/ldl; 413 and 321
   are (f32) int conversions (cvt.s.w); the format string is a gp-relative
   s32 (iGpffffa8a0). Stack slots follow declaration order: fv0 first, the
   FclVec2 constructor results, then fv7..fv1, then buf. */
// FUN_00302770
void func_00302770(u8 *arg0) {
    extern u8 *func_002b81f0(u8 *arg0);
    extern void func_0032e570(u8 *arg0);
    FclVec2f fv0;
    FclVec2 sp250;
    FclVec2 sp248;
    FclVec2 sp240;
    FclVec2 sp238;
    FclVec2 sp230;
    FclVec2 sp228;
    FclVec2 sp220;
    FclVec2 sp218;
    FclVec2 sp210;
    FclVec2 sp208;
    FclVec2 sp200;
    FclVec2 sp1F8;
    FclVec2 sp1F0;
    FclVec2 sp1E8;
    FclVec2 sp1E0;
    FclVec2 sp1D8;
    FclVec2 sp1D0;
    FclVec2 sp1C8;
    FclVec2 sp1C0;
    FclVec2 sp1B8;
    FclVec2 sp1B0;
    FclVec2 sp1A8;
    FclVec2 sp1A0;
    FclVec2 sp198;
    FclVec2 sp190;
    FclVec2 sp188;
    FclVec2 sp180;
    FclVec2 sp178;
    FclVec2 sp170;
    FclVec2 sp168;
    FclVec2 sp160;
    FclVec2 sp158;
    FclVec2 sp150;
    FclVec2 sp148;
    FclVec2 sp140;
    FclVec2 sp138;
    FclVec2 sp130;
    FclVec2 sp128;
    FclVec2f fv7;
    FclVec2f fv6;
    FclVec2f fv5;
    FclVec2f fv4;
    FclVec2f fv3;
    FclVec2f fv2;
    FclVec2f fv1;
    char buf[128];
    u8 *p;
    u8 *q;
    s16 i;

    p = *(u8 **)(arg0 + 0x38);
    switch (p[1]) {
    case 0x6E:
        func_003205f0(arg0, 0x1E7, 0x96);
        if (datGetFlag(0x131A) == 0) {
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002badc0(*(s8 *)(p + 0xD), 0x4E);
            func_00106390(0x131A, 1);
            p[1] = 0x6F;
            break;
        }
        p[1] = 0x70;
        sp250 = func_002b2970(640.0f, 98.0f);
        sp248 = func_002b2970((f32)413, 99.0f);
        func_0033e540(*(u8 **)(p + 0x250), sp250, sp248, 6, 0);
        func_00316e80(arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    case 0x70:
        func_00313b50(arg0);
        *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
        sprintf(buf, (const char *)&iGpffffa8a0, func_002e78a0());
        func_002bbd80(*(s8 *)(p + 0xD), 0, buf);
        sprintf(buf, (const char *)&iGpffffa8a0, (u8)func_002e78e0());
        func_002bbd80(*(s8 *)(p + 0xD), 1, buf);
        func_002badc0(*(s8 *)(p + 0xD), 0x4A);
        p[1] = 0x71;
        break;
    case 0x71:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x72;
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002badc0(*(s8 *)(p + 0xD), 0x4B);
            func_00325450(arg0, 2, 0);
            sp240 = func_002b2970(57.0f, 72.0f);
            sp238 = func_002b2970(-346.0f, 72.0f);
            func_0032c660(arg0, 0, sp240, sp238, 1, 0);
            sp230 = func_002b2970(460.0f, 72.0f);
            sp228 = func_002b2970(460.0f, 72.0f);
            func_0032c660(arg0, 1, sp230, sp228, 1, 0);
            func_002b6140((u8 *)(*(s32 *)(p + 0x28C)), 1);
            func_002b6140((u8 *)(*(s32 *)(p + 0x290)), 1);
            func_00315600(arg0, 1);
            func_00320970(arg0, 1);
        }
        break;
    case 0x72:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x73;
        }
    case 0x73:
        func_0032e570(arg0);
        q = func_002b6150(0x2E3);
        fv0 = *(FclVec2f *)(q + 0x38);
        sp220 = func_002b2970(fv0.x - 50.0f, fv0.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x258)) = sp220;
        q = func_002b6150(0x2E2);
        fv1 = *(FclVec2f *)(q + 0x38);
        sp218 = func_002b2970(fv1.x - 50.0f, fv1.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x25C)) = sp218;
        q = func_002b6150(0x2E9);
        fv2 = *(FclVec2f *)(q + 0x38);
        sp210 = func_002b2970(fv2.x - 50.0f, fv2.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x260)) = sp210;
        q = func_002b6150(0x2EF);
        fv3 = *(FclVec2f *)(q + 0x38);
        sp208 = func_002b2970(fv3.x - 50.0f, fv3.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x264)) = sp208;
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1CA) + 0x10), 1) != 1) {
            if (D_008C024E[0] & 8) {
                if (*(s8 *)(p + 0x122) != 1) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                sp200 = func_002b2970((f32)321, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(q + 0x38), sp200, 1, 4, 0);
                q = func_002b6150(0x2E0);
                sp1F8 = func_002b2970((f32)321, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(q + 0x38), sp1F8, 1, 4, 0);
                sp1F0 = func_002b2970(57.0f, 72.0f);
                sp1E8 = func_002b2970(-346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1F0, sp1E8, 0, 1);
                sp1E0 = func_002b2970(460.0f, 72.0f);
                sp1D8 = func_002b2970(460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1E0, sp1D8, 0, 0);
                *(s8 *)(p + 0x122) = 0;
            } else if (D_008C024E[0] & 4) {
                if (*(s8 *)(p + 0x122) != 0) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                sp1D0 = func_002b2970(107.0f, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(q + 0x38), sp1D0, 1, 4, 0);
                q = func_002b6150(0x2E0);
                sp1C8 = func_002b2970(107.0f, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(q + 0x38), sp1C8, 1, 4, 0);
                sp1C0 = func_002b2970(57.0f, 72.0f);
                sp1B8 = func_002b2970(-346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1C0, sp1B8, 0, 0);
                sp1B0 = func_002b2970(460.0f, 72.0f);
                sp1A8 = func_002b2970(460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1B0, sp1A8, 0, 1);
                *(s8 *)(p + 0x122) = 1;
            } else if ((D_008C024E[0] & 0x20) && p[1] == 0x73) {
                func_002bb550(*(s8 *)(p + 0xD));
                func_0045af60(0, 0, 0, 2);
                func_00325450(arg0, 2, 1);
                if (*(s8 *)(p + 0x122) == 1) {
                    sp1A0 = func_002b2970(57.0f, 72.0f);
                    sp198 = func_002b2970(940.0f, 72.0f);
                    func_0032c660(arg0, 0, sp1A0, sp198, 0, 1);
                    sp190 = func_002b2970(460.0f, 72.0f);
                    sp188 = func_002b2970(940.0f, 72.0f);
                    func_0032c660(arg0, 1, sp190, sp188, 0, 1);
                    func_002b68d0(0x2E8, 0, 1);
                    func_002b68d0(0x2EE, 0, 1);
                } else if (*(s8 *)(p + 0x122) == 0) {
                    sp180 = func_002b2970(57.0f, 72.0f);
                    sp178 = func_002b2970(-640.0f, 72.0f);
                    func_0032c660(arg0, 0, sp180, sp178, 0, 1);
                    sp170 = func_002b2970(460.0f, 72.0f);
                    sp168 = func_002b2970(-640.0f, 72.0f);
                    func_0032c660(arg0, 1, sp170, sp168, 0, 1);
                }
                func_002eb270(arg0, 0);
                p[1] = 0x74;
                func_00316e80(arg0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                sp160 = func_002b2970((f32)413, 99.0f);
                sp158 = func_002b2970(640.0f, 98.0f);
                func_0033e540(*(u8 **)(p + 0x250), sp160, sp158, 6, 0);
                func_00315600(arg0, 0);
                func_00320970(arg0, 0);
            }
        }
        break;
    case 0x74:
        q = func_002b6150(0x2E3);
        fv4 = *(FclVec2f *)(q + 0x38);
        sp150 = func_002b2970(fv4.x - 50.0f, fv4.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x258)) = sp150;
        q = func_002b6150(0x2E2);
        fv5 = *(FclVec2f *)(q + 0x38);
        sp148 = func_002b2970(fv5.x - 50.0f, fv5.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x25C)) = sp148;
        q = func_002b6150(0x2E9);
        fv6 = *(FclVec2f *)(q + 0x38);
        sp140 = func_002b2970(fv6.x - 50.0f, fv6.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x260)) = sp140;
        q = func_002b6150(0x2EF);
        fv7 = *(FclVec2f *)(q + 0x38);
        sp138 = func_002b2970(fv7.x - 50.0f, fv7.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x264)) = sp138;
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1CA) + 0x10), 1) != 1) {
            for (i = 0; i < 4; i++) {
                *(u8 *)(func_002b81f0(*(u8 **)(p + i * 4 + 0x258)) + 0x124) = 1;
            }
            func_003205f0(arg0, 0x96, 0x1E7);
            func_002b6140((u8 *)(*(s32 *)(p + 0x28C)), 0);
            func_002b6140((u8 *)(*(s32 *)(p + 0x290)), 0);
            *p = 0;
            p[1] = 0x1A;
        }
        break;
    case 0x6F:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0x70;
            sp130 = func_002b2970(640.0f, 98.0f);
            sp128 = func_002b2970((f32)413, 99.0f);
            func_0033e540(*(u8 **)(p + 0x250), sp130, sp128, 6, 0);
            func_00316e80(arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
}

/* measured: 1036/1040 bytes with eight resolved code relocations and a fully resolved
   44-byte switch table at 0x00749300. Independent searches keep their own
   short counters; the nested category search retains separate inner/outer
   lifetimes. The existing loop-invariant pragma hoists the flag constant. */
// FUN_00303610
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
        case 1: {
            s16 item;
            for (item = 0; item < count; item++) {
                want = *(s16 *)(rule + 4);
                if (want == (func_00109280(arg2[item]) & 0xFF)) {
                    found = 1;
                    break;
                }
            }
            break;
        }
        case 2: {
            s16 item;
            for (item = 0; item < count; item++) {
                if (*(s16 *)(rule + 4) == arg2[item]) {
                    found = 1;
                    break;
                }
            }
            break;
        }
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
            for (k = 0; k < count; k++) {
                want = *(s16 *)(rule + 4);
                if (want == (func_00109280(arg2[k]) & 0xFF)) {
                    for (j = 0; j < count; j++) {
                        want = *(s16 *)(rule + 6);
                        if (want == (func_00109280(arg2[j]) & 0xFF)) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        case 6: {
            s16 first;
            s16 second;
            for (first = 0; first < count; first++) {
                if (*(s16 *)(rule + 4) == arg2[first]) {
                    for (second = 0; second < count; second++) {
                        if (*(s16 *)(rule + 6) == arg2[second]) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            break;
        }
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

// FUN_00303A20
s32 func_00303a20(u8 *arg0) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    u16 buf[7];

    switch (p[0x1A]) {
    case 2:
        buf[0] = *(u16 *)((u16 *)func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[2] = *(u16 *)((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 3:
        buf[0] = *(u16 *)((u16 *)func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)((u16 *)func_002e48a0(0, p[0x129]) + 1);
        buf[2] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[3] = *(u16 *)((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 4:
        buf[0] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 5:
        buf[0] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 6:
        buf[0] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)((u16 *)func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 5) + 1);
        buf[6] = *(u16 *)((u16 *)func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    }
    return func_00303610(arg0, p[0x1A], buf);
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
    calendar = (s8 *)D_006406F0 + (s8)func_00110a60(month, (u8)func_002e78e0()) * 20;
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
        roll = (s16)(RpRandom() % total);
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
/* Defined below.  The selector is a signed byte that func_003040d0 forwards
   without re-extending it. */
s32 func_003042f0(s32 arg0, s8 arg1);
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
s32 func_003040d0(u8 *arg0, s16 arg1, s8 arg2)
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
    roll = (s8)(RpRandom() % 100);
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
    if (RpRandom() % 100 < 30) {
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
s32 func_003042f0(s32 arg0, s8 arg1)
{
    switch (arg1) {
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

/* A 0x30-byte combination recipe, as copied out by func_002e4960 and
   passed by value to func_00304410.  Its word alignment gives the
   two-word copy loop retail uses for the argument. */
typedef struct {
    s32 data[12];
} FclCombineRecipe;

/* measured: MATCH.  The recipe is passed by value: the six 8-byte blocks
   retail copies into sp+0x4F0 are the compiler's own copy of the struct
   argument.  The key arrives as an s16 and goes to func_00313690
   unextended; bound takes the sign extension.  The loop then fills an
   sp+0x70 s16 table from the func_00313690 key and retries rand()%count
   until func_0010ce10 succeeds.  The random divisor is a separate s32
   local after the sign-extended s64 count; a signed modulo result and a
   named s16 *entry table pointer give retail's dsll32/dsra32 remainder
   and its separate addiu 0x70 before lhu. */
// FUN_00304410
u16 func_00304410(FclCombineRecipe recipe, s16 arg1) {
    s16 table[0x240];
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

    key = (s16)func_00313690(arg1);
    count = (s16)key;
    i = 0;
    retry = 0;
    j = 0;
    bound = arg1;
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
        entry = table + (s16)(RpRandom() % (u32)divisor);
        selected = *entry;
        if (func_0010ce10((u8 *)&recipe, selected) == -1) {
            retry = 1;
        }
    } while ((s8)retry == 0);
    return selected;
}
typedef struct {
    s8 f0;
    u8 f1;
    u8 pad2[0xB];
    s8 fD;
    u8 padE[0xE];
    s16 f1C;
    u8 pad1E[0x98];
    s8 fB6;
    u8 padB7[0x5];
    s16 fBC;
    u8 padBE[0x60];
    s16 f11E;
    u8 pad120[0x2];
    s8 f122;
    u8 pad123[0x5];
    s8 f128;
    s8 f129;
    u8 pad12A[0x1E];
    s32 f148;
    u8 pad14C[0x38];
    s32 f184;
    s32 f188;
    u8 pad18C[0x100];
    s32 f28C;
    s32 f290;
    u8 pad294[0x28];
    u8 *f2BC;
    u8 pad2C0[0x18];
    s16 f2D8;
    u8 pad2DA[0x1F];
    s8 f2F9;
    s8 f2FA;
    u8 pad2FB[0x11];
    u8 f30C[5];
    u8 pad311[0xF];
} FclCombineMenu;

/* A work-relative view used while stepping through the row-task table. */
typedef struct {
    u8 pad0[0x154];
    u8 *list;
} FclCombineRowView;

typedef struct {
    u16 original;
    u16 replacement;
} FclSkillPair;

#pragma push
/* Preserve signed loop induction and row-coordinate invariants from retail. */
#pragma opt_loop_invariants on
/* Both grid transitions share the header/row draw sequence; mode 0 preserves cell positions. */
#define FCL_COMBINE_GRID_ROW(menu, outer, inner, mode, headerPosition, cellPosition, color0, color1) do { \
    s32 grid = mode; \
 \
    s32 offset = outer * 23; \
    s32 y; \
    FclCombineRowView *list; \
 \
    func_002b83e0(func_0034ae50((u8 *)menu->f184, (s8)outer), \
        (headerPosition = func_002b2970((f32)(offset + 329), 104.0f)), \
        (color0 = func_002b2a60(0, 0, 0x99, 0xFF)), \
        (color1 = func_002b2a60(0, 0, 0x99, 0xFF)), 255, 255, 32.0f, 159.0f, 3, 0, 1, 0); \
    inner = 0; \
    list = (FclCombineRowView *)((u8 *)menu + outer * 4); \
    y = offset + 127; \
    for (; inner < (func_0010b5b0() & 0xFFFF); inner++) { \
        if (grid) { \
            func_002b83e0(func_0034ae50(list->list, (s8)inner), \
                (cellPosition = func_002b2970((f32)(inner * 23 + 329), (f32)y)), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                32.0f, *(f32 *)(func_0034ae50(list->list, (s8)inner) + 4), 3, 0, 1, 0); \
        } else { \
            func_002b83e0(func_0034ae50(list->list, (s8)inner), \
                *(FclVec2 *)(func_0034ae50(list->list, (s8)inner) + 0x28), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                *(FclDrawColor *)(func_0034ae50(list->list, (s8)inner) + 0x75), \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                func_0034ae50(list->list, (s8)inner)[0x5e], \
                32.0f, *(f32 *)(func_0034ae50(list->list, (s8)inner) + 4), 3, 0, 1, 0); \
        } \
    } \
} while (0)

// FUN_00304580
void func_00304580(u8 *arg0) {
    FclDrawColor col2FC;
    FclDrawColor col2F8;
    FclDrawColor col2F4;
    FclDrawColor col2F0;
    FclDrawColor col2EC;
    FclDrawColor col2E8;
    FclDrawColor col2E4;
    FclDrawColor col2E0;
    FclDrawColor col2DC;
    FclDrawColor col2D8;
    FclDrawColor col2D4;
    FclDrawColor col2D0;
    u8 *ps;





    u8 sp2C8[5];
    u8 sp2C0[5];
    u8 sp2B8[5];
    u8 sp2B0[5];
    u8 sp2A8[5];
    u8 sp2A0[5];
    FclVec2 sp298;
    FclVec2 sp290;
    FclVec2 sp288;
    FclVec2 sp280;
    FclVec2 sp278;
    FclVec2 sp270;
    FclVec2 sp268;
    FclVec2 sp260;
    FclVec2 sp258;
    FclVec2 sp250;
    FclVec2 sp248;
    FclVec2 sp240;
    FclVec2 sp238;
    FclVec2 sp230;
    FclVec2 sp228;
    FclVec2 sp220;
    FclVec2 sp218;
    FclVec2 sp210;
    FclVec2 sp208;
    FclVec2 sp200;
    FclVec2 sp1F8;
    FclVec2 sp1F0;
    FclVec2 sp1E8;
    FclVec2 sp1E0;
    FclVec2 sp1D8;
    FclVec2 sp1D0;
    FclVec2 sp1C8;
    FclVec2 sp1C0;
    FclVec2 sp1B8;
    FclVec2 sp1B0;
    FclVec2 sp1A8;
    FclVec2 sp1A0;
    FclVec2 sp198;
    FclVec2 sp190;
    FclVec2 sp188;
    FclVec2 sp180;
    FclVec2 sp178;
    FclVec2 sp170;
    FclVec2 sp168;
    FclVec2f sp160;
    FclVec2f sp158;
    FclVec2f sp150;
    FclVec2f sp148;
    FclVec2f sp140;
    char skillName[0x20];
    u8 *sp11C;
    f32 temp_f20;
    s16 temp_16_5;
    s32 temp_16;
    s32 temp_16_10;
    s32 temp_16_13;
    s32 temp_16_16;
    s32 temp_16_21;
    s32 temp_16_22;
    s32 temp_16_24;
    s32 temp_16_28;
    s32 temp_16_32;
    s32 temp_16_33;
    s32 temp_16_35;
    s32 temp_16_38;
    s32 temp_18_4;
    s32 temp_19_3;
    u8 *temp_21_2;
    u8 *temp_21_6;
    u16 temp_3_2;
    u16 temp_4_3;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_21;
    s32 var_21_2;
    s64 temp_16_37;
    s16 temp_16_4;
    s16 temp_16_9;
    s8 temp_18_14;
    s32 temp_18_16;
    s64 temp_18_17;
    s16 temp_18_3;
    s16 temp_19_2;
    s8 temp_2_2;
    s64 temp_3_10;
    s64 temp_3_17;
    s16 temp_3_18;
    s8 temp_4;
    s64 temp_4_2;
    s16 var_16;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_4;
    s16 var_16_5;
    s16 gridRow;
    s16 gridColumn;
    s16 var_18_5;
    s16 var_18_6;
    s16 var_18_7;
    s16 var_18_8;
    s16 var_18_9;
    FclVec2f *basePos;
    s16 var_19_3;
    s16 var_19_4;
    s32 id27D;
    s32 id270;
    s32 id27D_2;
    s32 id270_2;
    s16 var_19_5;
    s16 var_19_6;
    s16 var_4;
    s16 var_4_2;
    s16 var_4_3;
    s16 var_4_4;
    s16 var_4_5;
    s16 var_4_6;
    s16 var_4_7;
    s8 var_5;
    s16 var_6;
    s8 temp_2_27;
    s32 temp_2_37;
    s8 temp_3_13;
    s8 temp_3_15;
    u16 *temp_16_39;
    u16 *temp_2_15;
    u16 *temp_2_16;
    u16 *temp_2_17;
    u16 *temp_2_18;
    u16 *temp_2_19;
    u16 *temp_2_20;
    u16 *temp_2_21;
    u16 *temp_2_22;
    u16 *temp_2_28;
    u16 *temp_2_29;
    u16 *temp_2_30;
    u16 *temp_2_31;
    u16 *temp_2_32;
    u16 *temp_2_33;
    u16 *temp_2_34;
    u16 *temp_2_35;
    u16 *temp_2_38;
    u16 *temp_2_39;
    u16 *temp_2_40;
    u16 *temp_2_41;
    u16 *temp_2_42;
    u16 *temp_2_43;
    u16 *temp_2_44;
    u16 *temp_2_45;
    s32 temp_16_15;
    s32 temp_16_17;
    s32 temp_16_19;
    s32 temp_16_25;
    s32 temp_16_31;
    s32 temp_16_6;
    u8 temp_16_12;
    u8 temp_16_20;
    u8 temp_16_23;
    u8 temp_16_27;
    u8 temp_16_34;
    u8 temp_3;
    u8 temp_7;
    FclSkillPair *temp_16_40;
    FclCombineMenu *work;
    u8 slotByte;
    FclCombineMenu *temp_18_11;
    FclCombineMenu *temp_18_12;
    FclCombineMenu *temp_18_13;
    FclCombineMenu *temp_18_15;
    FclCombineMenu *temp_18_7;
    u8 *temp_2_10;
    u8 *temp_2_12;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_36;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    work = *(FclCombineMenu **)(arg0 + 0x38);
    temp_3 = (u8)(work->f1);
    switch (temp_3) {                               /* switch 1 */
    case 0x75:
        if (datGetFlag(0x131C) == 0) {
            work->fD = func_002bab80((void *)func_00331660());
            func_002badc0(work->fD, 0x50);
            func_00106390(0x131C, 1);
            work->f1 = 0x76;
        } else {
            work->f1 = 0x77;
        }
        break;
    case 0x76:
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
        } else {
            func_002bb550(work->fD);
            work->f1 = 0x77;
        }
        break;
    case 0x77:
        func_00315600(arg0, 1);
        if (datGetFlag(0x1306) != 0) {
            func_00314740((u8 *)work->f148, 1);
            func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
            temp_16 = (s32)func_003147d0((u8 *)work->f148);
            func_0011d140((u8 *)temp_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_003146f0((u8 *)work->f148, (s32)func_001102e0(), 0);
            func_00314670((u8 *)work->f148, 1);
            if (datGetFlag(0x1307) == 0) {
                temp_3_2 = func_001102d0() & 0xFFFF;
                var_5 = temp_3_2 & 0xF;
                temp_4 = (temp_3_2 >> 0xC) & 0xF;
                for (var_6 = 0; var_6 < 5; var_6++) {
                    work->f30C[var_6] = 0;
                }
                switch (var_5) {
                case 0: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < temp_4 + 1; bonusIndex++) {
                        work->f30C[0] += D_00749350[bonusIndex];
                        work->f30C[1] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 1: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < temp_4 + 1; bonusIndex++) {
                        work->f30C[2] += D_00749350[bonusIndex];
                        work->f30C[3] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 2: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < temp_4 + 1; bonusIndex++) {
                        work->f30C[4] += D_00749350[bonusIndex];
                        work->f30C[0] += D_00749350[bonusIndex];
                    }
                    break;
                }
                case 3: {
                    s16 bonusIndex;
                    for (bonusIndex = 0; bonusIndex < temp_4 + 1; bonusIndex++) {
                        work->f30C[1] += D_00749350[bonusIndex];
                        work->f30C[2] += D_00749350[bonusIndex];
                    }
                    break;
                }
                }
                func_0011b8f0(func_003147d0((u8 *)work->f148), work->f30C);
            } else {
                func_00310960(arg0, 0x22, 0);
                work->f1 = 0x85;
                break;
            }
            temp_2_2 = (s8)(((func_001102d0() & 0xFFFF) >> 0xC) & 0xF);
            if (temp_2_2 < 4) {
                func_00310960(arg0, 0x1F, 0);
            } else if (temp_2_2 < 7) {
                func_00310960(arg0, 0x20, 0);
            } else {
                func_00310960(arg0, 0x21, 0);
            }
            work->f1 = 0x85;
        } else {
            for (var_16 = 0; var_16 < (func_0010b5b0() & 0xFFFF); var_16++) {
                col2FC = func_002b2a60(0, 0, 0x99, 0xFF);
                *(FclDrawColor *)(func_0034ae50((u8 *)work->f188, var_16) + 0x75) = col2FC;
            }
            func_003205f0(arg0, 0x93, 0x96);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00314740((u8 *)work->f148, 0);
            func_002e4610(5, 0);
            func_002e4610(0xA, 1);
            func_002e4610(0xA, 2);
            func_002e4610(0xA, 3);
            func_002e4610(0xA, 4);
            func_002e4610(0xA, 5);
            func_002e4610(0xA, 6);
            func_002e4610(0xA, 7);
            func_002e4610(0xA, 8);
            func_002e4610(0xA, 9);
            func_002e4610(0xA, 0xA);
            func_002e4610(0xA, 0xB);
            func_002e4610(0xA, 0xC);
            work->f1 = 0x78;
        }
        break;
    case 0x78:
        if (*(s8 *)func_002e4870(0) != 0) {
            func_002e5000();
            work->f11E = 0;
            func_00320b80(arg0, 1);
            work->f1 = 0x79;
        }
        break;
    case 0x79:
        func_003212e0(arg0, 0x7B, 0);
        break;
    case 0x7B:                                      /* switch 1 */
        for (var_16_2 = 0; var_16_2 < (func_0010b5b0() & 0xFFFF); var_16_2++) {
            func_0031d630(arg0, (s8)(var_16_2), -1, -1, 0);
        }
        if ((((s8)(func_00314660((u8 *)work->f148))) < 0) || (((s8)(func_00314660((u8 *)work->f148))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                work->f11E = func_002b2d00(work->f11E, 1, 0, (func_0010b5b0() & 0xFFFF) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                work->f11E = func_002b2cb0(work->f11E, 1, (func_0010b5b0() & 0xFFFF) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                func_0045af60(0, 1, 0, 3);
                for (var_16_3 = 0; var_16_3 < (func_0010b5b0() & 0xFFFF); var_16_3++) {
                    sp298 = func_002b2970(16.0f, 128.0f);
                    func_003191c0(arg0, sp298, (s8)var_16_3,
                        ((u16 *)func_002e48a0(0, var_16_3))[1],
                        *(u8 *)((u8 *)func_002e48a0(0, var_16_3) + 4),
                        0, 1, (s8)*(s32 *)(func_002e4870(0) + 8));
                }
                sp290 = func_002b2970(16.0f, 104.0f);
                func_0031e5b0(arg0, sp290, 0, 1, 0, 0, 0);
                for (gridColumn = 0; gridColumn < (func_0010b5b0() & 0xFFFF); gridColumn++) {
                    sp11C = func_0046d200(func_00331560(), 0x77);
                    FCL_COMBINE_GRID_ROW(work, gridColumn, gridRow, 0, sp288, sp250, col2F8, col2F4);
                    func_0046d280(sp11C);
                    temp_19_2 = (s16)(gridColumn);
                    temp_16_4 = (s16)((temp_19_2 + 0x25E));
                    temp_21_2 = func_0046d200(func_00331560(), 0x39);
                    func_002b6a70(temp_16_4, 0xFFU, 0, 0, 3, 0);
                    func_002b6af0(temp_16_4, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    temp_19_3 = (temp_19_2 * 0x17) + 0x14E;
                    sp280 = func_002b2970((f32) temp_19_3, 110.0f);
                    sp278 = func_002b2970((f32) temp_19_3, 110.0f + (func_0046b2f0(temp_21_2) / 2.0f));
                    func_002b69f0(temp_16_4, (*(FclVec2f *)&sp280), (*(FclVec2f *)&sp278), 0, 3, 0);
                    func_0046d280(temp_21_2);
                }
                func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                func_002b6140((u8 *)(work->f28C), 1);
                func_002b6140((u8 *)(work->f290), 1);
                work->f1 = 0x7CU;
                return;
            }
            if (D_008C024E[0] & 0x40) {
                temp_16_5 = (s16)(work->f11E);
                if (temp_16_5 < (*(s32 *)((u8 *)(func_002e4870(0))+(8)))) {
                    func_0045af60(0, 0, 0, 1);
                    work->f128 = (s8) work->f11E;
                    work->f129 = -1;
                    basePos = (FclVec2f *)D_00640C10;
                    sp270 = func_002b2970(-380.0f, basePos->y);
                    sp268 = func_002b2970(basePos->x, basePos->y);
                    func_0031c2b0(arg0, work->f11E, *(FclVec2f *)&sp270, *(FclVec2f *)&sp268);
                    for (gridRow = 0; gridRow < (func_0010b5b0() & 0xFFFF); gridRow++) {
                        sp260 = func_002b2970((f32) 0x149, 128.0f);
                        temp_16_6 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), gridRow))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, gridRow) + 4);
                        func_0031ac10(arg0, sp260, work->f128, gridRow, temp_16_6, slotByte, 3, 0, 1, 0xCC);
                        FCL_COMBINE_GRID_ROW(work, gridRow, gridColumn, 1, sp258, sp250, col2F0, col2EC);
                        temp_18_3 = (s16)(gridRow);
                        temp_16_9 = (s16)((temp_18_3 + 0x25E));
                        temp_21_6 = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(temp_16_9, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_9, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_4 = (temp_18_3 * 0x17) + 0x14E;
                        sp248 = func_002b2970((f32) temp_18_4, 110.0f);
                        sp240 = func_002b2970((f32) temp_18_4, 110.0f + (func_0046b2f0(temp_21_6) / 2.0f));
                        func_002b69f0(temp_16_9, (*(FclVec2f *)&sp248), (*(FclVec2f *)&sp240), 0, 3, 0);
                        func_0046d280(temp_21_6);
                    }
                    sp238 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp238, 3, 0);
                    func_003205f0(arg0, 0x94, 0x93);
                    func_0031e320(arg0, (s64)work->f128);
                    work->f1 = 0x7EU;
                    return;
                }
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                func_0032fbc0(arg0);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                func_00316470(arg0, 1, 1);
                func_0032f4d0(arg0);
                work->f1 = 0x7AU;
                return;
            }
        }
        break;
    case 0x7C:                                      /* switch 1 */
        if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1))) != 1) {
            func_00314450((u8 *)work->f148, (s32)func_002e48a0(0, work->f11E), 0, 0);
            temp_16_10 = (s32)(func_003147d0((u8 *)work->f148));
            func_0011d140((u8 *)temp_16_10, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
            work->f1 = 0x7DU;
            return;
        }
        break;
    case 0x7D:                                      /* switch 1 */
        if ((((s8)(func_00314660((u8 *)work->f148))) < 0) || (((s8)(func_00314660((u8 *)work->f148))) > 5)) {
            for (var_16_4 = 0; var_16_4 < (func_0010b5b0() & 0xFFFF); var_16_4++) {
                sp230 = func_002b2970(16.0f, 128.0f);
                func_003191c0(arg0, sp230, (s8)var_16_4,
                    ((u16 *)func_002e48a0(0, var_16_4))[1],
                    *(u8 *)((u8 *)func_002e48a0(0, var_16_4) + 4),
                    0, 0, (s8)*(s32 *)(func_002e4870(0) + 8));
            }
            sp228 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp228, 0, 0, 0, 0, 0);
            func_003218a0(arg0, 0);
            func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_002b6140((u8 *)(work->f28C), 1);
            func_002b6140((u8 *)(work->f290), 1);
            work->f1 = 0x7BU;
            return;
        }
        break;
    case 0x7A:
        for (var_19_3 = 0; var_19_3 < (func_0010b5b0() & 0xFFFF); var_19_3++) {
            temp_f20 = (f32)*(s16 *)(func_002b6150(var_19_3 + 0x21C) + 0x42);
            temp_7 = (u8)func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)*(s16 *)(func_002b6150(var_19_3 + 0x21C) + 0x40));
            if (work->f11E == var_19_3) {
                var_18_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_18_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (var_19_3 < *(s32 *)(func_002e4870(0) + 8) - 1) {
                temp_f20 = (f32)(var_19_3 * 0x17 + 0x80);
                func_00275520(113.0f, temp_f20, 43.0f, var_18_3, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(0, var_19_3))[1] * 0x11), 0, 0, D_00795E60);
            }
        }
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) == 0
            && (s16)func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_003205f0(arg0, 0x96, 0x93);
            func_00315600(arg0, 0);
            work->f0 = 0;
            work->f1 = 0x1B;
        }
        break;
    case 0x7E:                                      /* switch 1 */
        work->f129 = -1;
        temp_16_12 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_7 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp160 = *(FclVec2f *)(temp_2_4 + 0x38);
        temp_16_13 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_12);
        func_00275820(111.0f + sp160.x, sp160.y, 43.0f, temp_16_13, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_7->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_4 = 0; var_19_4 < (func_0010b5b0() & 0xFFFF); var_19_4++) {
            func_0031d630(arg0, (s8)(var_19_4), work->f128, work->f129, 0);
            if ((((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150((s16)((var_19_4 + 0x270))))+(0x10))), 1))) == 0) && (work->f128 != var_19_4) && ((*(s8 *)((u8 *)((func_002e4870(0) + (work->f128 * 0xC) + var_19_4))+(0x14))) > 0)) {
                if (var_19_4 == work->f11E) {
                    id27D = var_19_4 + 0x27D;
                    id270 = var_19_4 + 0x270U;
                    *(u8 *)(func_002b6150(id270) + 0x6E) = *(u8 *)(func_002b6150(id27D) + 0x6E) = 0xFF;
                    col2E8 = func_002b2a60(0xCC, 0xFF, 0x33, 0xFF);
                    temp_2_5 = func_002b6150(var_19_4 + 0x297);
                    *(FclDrawColor *)(temp_2_5 + 0x85) = col2E8;
                    temp_2_6 = func_002b6150(var_19_4 + 0x28B);
                    *(FclDrawColor *)(temp_2_6 + 0x85) = *(FclDrawColor *)(temp_2_5 + 0x85);
                    temp_2_7 = func_002b6150(id27D);
                    *(FclDrawColor *)(temp_2_7 + 0x85) = *(FclDrawColor *)(temp_2_6 + 0x85);
                    *(FclDrawColor *)(func_002b6150(id270) + 0x85) = *(FclDrawColor *)(temp_2_7 + 0x85);
                    col2E4 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x2A3) + 0x85) = col2E4;
                    col2E0 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(work->f2BC, (s8)(var_19_4 + 0xC), col2E0);
                    var_18_4 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
                } else {
                    id27D_2 = var_19_4 + 0x27D;
                    id270_2 = var_19_4 + 0x270U;
                    *(u8 *)(func_002b6150(id270_2) + 0x6E) = *(u8 *)(func_002b6150(id27D_2) + 0x6E) = 0xCC;
                    col2DC = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_10 = func_002b6150(id27D_2);
                    *(FclDrawColor *)(temp_2_10 + 0x85) = col2DC;
                    *(FclDrawColor *)(func_002b6150(id270_2) + 0x85) = *(FclDrawColor *)(temp_2_10 + 0x85);
                    col2D8 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                    temp_2_12 = func_002b6150(var_19_4 + 0x297);
                    *(FclDrawColor *)(temp_2_12 + 0x85) = col2D8;
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x28B) + 0x85) = *(FclDrawColor *)(temp_2_12 + 0x85);
                    col2D4 = func_002b2a60(0, 0, 0x66, 0xFF);
                    *(FclDrawColor *)(func_002b6150(var_19_4 + 0x2A3) + 0x85) = col2D4;
                    col2D0 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(work->f2BC, (s8)(var_19_4 + 0xC), col2D0);
                    var_18_4 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
                }
                temp_f20 = (f32) ((var_19_4 * 0x17) + 0x80);
                func_00275520((f32) 0x195, temp_f20, 43.0f, var_18_4, 0, 2, (const char *)(iGpffffb440 + ((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_19_4))+(2))) * 0x11)), 0, 0, D_00795E60);
            }
        }
        if ((((s8)(func_00314660((u8 *)work->f148))) < 0) || (((s8)(func_00314660((u8 *)work->f148))) > 5)) {
            if (D_008C027A[0] & 0x1000) {
                work->f11E = func_002b2d00(work->f11E, 1, 0, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                work->f11E = func_002b2cb0(work->f11E, 1, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                if ((work->f128 != work->f11E) && ((*(s8 *)((u8 *)((func_002e4870(0) + (work->f128 * 0xC) + work->f11E))+(0x14))) > 0)) {
                    func_0045af60(0, 0, 0, 1);
                    for (var_18_5 = 0; var_18_5 < (func_0010b5b0() & 0xFFFF); var_18_5++) {
                        sp220 = func_002b2970((f32) 0x149, 128.0f);
                        temp_16_15 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_18_5))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, var_18_5) + 4);
                        func_0031ac10(arg0, sp220, work->f128, var_18_5, temp_16_15, slotByte, 3, 1, 1, 0xCC);
                    }
                    work->f2F9 = (s8) (work->f128 + 1);
                    work->f2FA = (s8) work->f11E;
                    work->f129 = (s8) work->f11E;
                    for (var_4 = 0; var_4 < 5; var_4++) {
                        work->f30C[var_4] = 0;
                    }
                    temp_3_10 = (s8)(func_00308e50(arg0));
                    switch (temp_3_10) {            /* switch 3; irregular */
                    case 0:                         /* switch 3 */
                        temp_2_15 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_15)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_15)+(0x1C))) + 6);
                        temp_2_16 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_16)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_16)+(0x1D))) + 6);
                        work->f30C[0] = 6;
                        work->f30C[1] = 6;
                        break;
                    case 1:                         /* switch 3 */
                        temp_2_17 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_17)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_17)+(0x1E))) + 6);
                        temp_2_18 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_18)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_18)+(0x1F))) + 6);
                        work->f30C[2] = 6;
                        work->f30C[3] = 6;
                        break;
                    case 2:                         /* switch 3 */
                        temp_2_19 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_19)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_19)+(0x20))) + 6);
                        temp_2_20 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_20)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_20)+(0x1C))) + 6);
                        work->f30C[4] = 6;
                        work->f30C[0] = 6;
                        break;
                    case 3:                         /* switch 3 */
                        temp_2_21 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_21)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_21)+(0x1D))) + 6);
                        temp_2_22 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                        (*(u8 *)((u8 *)(temp_2_22)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_22)+(0x1E))) + 6);
                        work->f30C[1] = 6;
                        work->f30C[2] = 6;
                        break;
                    }
                    func_003144d0((u8 *)work->f148, (s32)func_002e48a0(work->f2F9, work->f2FA), 0, 0, 1);
                    temp_16_16 = (s32)(func_003147d0((u8 *)work->f148));
                    func_0011d140((u8 *)temp_16_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
                    work->f1 = 0x81U;
                    for (var_16_5 = 0; var_16_5 < (func_0010b5b0() & 0xFFFF); var_16_5++) {
                        sp218 = func_002b2970(16.0f, 128.0f);
                        func_003191c0(arg0, sp218, (s8)var_16_5,
                            ((u16 *)func_002e48a0(0, var_16_5))[1],
                            *(u8 *)((u8 *)func_002e48a0(0, var_16_5) + 4),
                            0, 1, (s8)*(s32 *)(func_002e4870(0) + 8));
                    }
                    sp210 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp210, 0, 1, 0, 0, 0);
                    sp208 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp208, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0);
                    func_00325450(arg0, 3, 0);
                    func_002b6140((u8 *)(work->f28C), 1);
                    func_002b6140((u8 *)(work->f290), 1);
                    return;
                }
            } else {
                if (D_008C024C[0] & 0x80) {
                    func_0045af60(0, 1, 0, 3);
                    for (var_18_6 = 0; var_18_6 < (func_0010b5b0() & 0xFFFF); var_18_6++) {
                        sp200 = func_002b2970((f32) 0x149, 128.0f);
                        temp_16_17 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_18_6))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, var_18_6) + 4);
                        func_0031ac10(arg0, sp200, work->f128, var_18_6, temp_16_17, slotByte, 0, 1, 1, 0xCC);
                        sp1F8 = func_002b2970(16.0f, 128.0f);
                        func_003191c0(arg0, sp1F8, (s8)var_18_6,
                            ((u16 *)func_002e48a0(0, var_18_6))[1],
                            *(u8 *)((u8 *)func_002e48a0(0, var_18_6) + 4),
                            0, 1, (s8)*(s32 *)(func_002e4870(0) + 8));
                    }
                    sp1F0 = func_002b2970(16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1F0, 0, 1, 0, 0, 0);
                    sp1E8 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1E8, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_002b6140((u8 *)(work->f28C), 1);
                    func_002b6140((u8 *)(work->f290), 1);
                    work->f1 = 0x7FU;
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) work->f11E, 0, 0xFF);
                    work->f11E = work->f128;
                    func_0031ddf0(arg0, work->f11E, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    basePos = (FclVec2f *)D_00640C10;
                    sp1E0 = func_002b2970(basePos->x, basePos->y);
                    sp1D8 = func_002b2970(-380.0f, basePos->y);
                    func_0031c2b0(arg0, work->f128, *(FclVec2f *)&sp1E0, *(FclVec2f *)&sp1D8);
                    sp1D0 = func_002b2970((f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1D0, 0, 1);
                    for (var_18_7 = 0; var_18_7 < (func_0010b5b0() & 0xFFFF); var_18_7++) {
                        sp1C8 = func_002b2970((f32) 0x149, 128.0f);
                        temp_16_19 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_18_7))+(2))));
                        slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, var_18_7) + 4);
                        func_0031ac10(arg0, sp1C8, work->f128, var_18_7, temp_16_19, slotByte, 0, 1, 1, 0xCC);
                    }
                    func_003218a0(arg0, 3);
                    work->f1 = 0x7BU;
                    return;
                }
            }
        }
        break;
    case 0x7F:                                      /* switch 1 */
        temp_16_20 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_11 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_24 = (u8 *)(func_002b6150(0x7C));
        sp158 = *(FclVec2f *)(temp_2_24 + 0x38);
        temp_16_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_20);
        func_00275820(111.0f + sp158.x, sp158.y, 43.0f, temp_16_21, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_11->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x270))+(0x10))), 1))) != 1) {
            func_00314450((u8 *)work->f148, (s32)func_002e48a0(0, work->f11E), 0, 0);
            temp_16_22 = (s32)(func_003147d0((u8 *)work->f148));
            func_0011d140((u8 *)temp_16_22, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
            work->f1 = 0x80U;
            return;
        }
        break;
    case 0x80:                                      /* switch 1 */
        temp_16_23 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_12 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_25 = (u8 *)(func_002b6150(0x7C));
        sp150 = *(FclVec2f *)(temp_2_25 + 0x38);
        temp_16_24 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_23);
        func_00275820(111.0f + sp150.x, sp150.y, 43.0f, temp_16_24, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_12->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        if ((((s8)(func_00314660((u8 *)work->f148))) < 0) || (((s8)(func_00314660((u8 *)work->f148))) > 5)) {
            for (var_18_8 = 0; var_18_8 < (func_0010b5b0() & 0xFFFF); var_18_8++) {
                sp1C0 = func_002b2970((f32) 0x149, 128.0f);
                temp_16_25 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_18_8))+(2))));
                slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, var_18_8) + 4);
                func_0031ac10(arg0, sp1C0, work->f128, var_18_8, temp_16_25, slotByte, 0, 0, 1, 0xCC);
                sp1B8 = func_002b2970(16.0f, 128.0f);
                func_003191c0(arg0, sp1B8, (s8)var_18_8,
                    ((u16 *)func_002e48a0(0, var_18_8))[1],
                    *(u8 *)((u8 *)func_002e48a0(0, var_18_8) + 4),
                    0, 0, (s8)*(s32 *)(func_002e4870(0) + 8));
            }
            sp1B0 = func_002b2970(16.0f, 104.0f);
            func_0031e5b0(arg0, sp1B0, 0, 0, 0, 0, 0);
            sp1A8 = func_002b2970((f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1A8, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            work->f1 = 0x7EU;
            return;
        }
        break;
    case 0x81:                                      /* switch 1 */
        temp_16_27 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_13 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_26 = (u8 *)(func_002b6150(0x7C));
        sp148 = *(FclVec2f *)(temp_2_26 + 0x38);
        temp_16_28 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27);
        func_00275820(111.0f + sp148.x, sp148.y, 43.0f, temp_16_28, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_13->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_5 = 0; var_19_5 < (func_0010b5b0() & 0xFFFF); var_19_5++) {
            func_0031d630(arg0, (s8)(var_19_5), work->f128, work->f129, 0);
            if (var_19_5 == work->f11E) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
            }
            temp_2_27 = (s8)(work->f128);
            if (temp_2_27 != var_19_5) {
                temp_18_14 = (s8)(temp_2_27);
                if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_14 * 0xC) + var_19_5))+(0x14))) > 0) {
                    temp_f20 = (f32) ((var_19_5 * 0x17) + 0x80);
                    func_00275520((f32) 0x195, temp_f20, 43.0f, var_21, 0, 2, (const char *)(iGpffffb440 + ((*(u16 *)((u8 *)(func_002e48a0((s8)((temp_18_14 + 1)), var_19_5))+(2))) * 0x11)), 0, 0, D_00795E60);
                }
            }
        }
        if (work->f122 == 2) {
            func_0011b8f0(func_003147d0((u8 *)work->f148), work->f30C);
        }
        if (((s8)(func_00314660((u8 *)work->f148))) == 0xD) {
            if (func_0011c610(func_003147d0((u8 *)work->f148)) == 1) {
                func_0011caf0(func_003147d0((u8 *)work->f148));
            }
            if (D_008C024E[0] & 0x40) {
                func_00310960(arg0, 0x1B, 1);
                work->f1 = 0x83U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0((u8 *)work->f148)) == 1) {
                    func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
                    func_00314740((u8 *)work->f148, 1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                work->f1 = 0x82U;
                func_00314670((u8 *)work->f148, 0xB);
                func_00325450(arg0, 3, 1);
                func_00316470(arg0, 1, 0);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                work->f129 = -1;
                for (var_18_9 = 0; var_18_9 < (func_0010b5b0() & 0xFFFF); var_18_9++) {
                    sp1A0 = func_002b2970(16.0f, 128.0f);
                    func_003191c0(arg0, sp1A0, (s8)var_18_9,
                        ((u16 *)func_002e48a0(0, var_18_9))[1],
                        *(u8 *)((u8 *)func_002e48a0(0, var_18_9) + 4),
                        0, 0, (s8)*(s32 *)(func_002e4870(0) + 8));
                    sp198 = func_002b2970((f32) 0x149, 128.0f);
                    temp_16_31 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s8)((work->f128 + 1)), var_18_9))+(2))));
                    slotByte = *(u8 *)((u8 *)func_002e48a0(work->f128 + 1, var_18_9) + 4);
                    func_0031ac10(arg0, sp198, work->f128, var_18_9, temp_16_31, slotByte, 0, 0, 1, 0xCC);
                }
                sp190 = func_002b2970(16.0f, 104.0f);
                func_0031e5b0(arg0, sp190, 0, 0, 0, 0, 0);
                sp188 = func_002b2970((f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp188, 0, 0);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_00317240(arg0, 1, 0);
                for (var_4_2 = 0; var_4_2 < 5; var_4_2++) {
                    sp2C8[var_4_2] = 0;
                }
                func_0011b8f0(func_003147d0((u8 *)work->f148), sp2C8);
                temp_4_2 = (s8)(func_00308e50(arg0));
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_2_28 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_28)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_28)+(0x1C))) - 6);
                    temp_2_29 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_29)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_29)+(0x1D))) - 6);
                    return;
                case 1:                             /* switch 4 */
                    temp_2_30 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_30)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_30)+(0x1E))) - 6);
                    temp_2_31 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_31)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_31)+(0x1F))) - 6);
                    return;
                case 2:                             /* switch 4 */
                    temp_2_32 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_32)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_32)+(0x20))) - 6);
                    temp_2_33 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_33)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_33)+(0x1C))) - 6);
                    return;
                case 3:                             /* switch 4 */
                    temp_2_34 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_34)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_34)+(0x1D))) - 6);
                    temp_2_35 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                    (*(u8 *)((u8 *)(temp_2_35)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_35)+(0x1E))) - 6);
                    return;
                }
            } else {
                if (D_008C024E[0] & 8) {
                    if (work->f122 != 2) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    work->f122 = func_002b2cb0(work->f122, 1, 2, 0, 1);
                    ps = func_002b6150(0x151);
                    sp180 = func_002b2970((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp180), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    sp178 = func_002b2970((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp178), 1, 4, 0);
                    for (var_4_3 = 0; var_4_3 < 5; var_4_3++) {
                        sp2C0[var_4_3] = 0;
                    }
                    func_0011b8f0(func_003147d0((u8 *)work->f148), sp2C0);
                    temp_3_13 = (s8)(work->f122);
                    switch (temp_3_13) {            /* switch 5; irregular */
                    case 0:                         /* switch 5 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(0, work->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 5 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(0, work->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 5 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(work->f2F9, work->f2FA), 0, 0, 1);
                        break;
                    }
                    temp_16_32 = (s32)(func_003147d0((u8 *)work->f148));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 4) {
                    if (work->f122 != 0) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    work->f122 = func_002b2d00(work->f122, 1, 0, 2, 1);
                    ps = func_002b6150(0x151);
                    sp170 = func_002b2970((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp170), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    sp168 = func_002b2970((f32) ((work->f122 * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp168), 1, 4, 0);
                    for (var_4_4 = 0; var_4_4 < 5; var_4_4++) {
                        sp2B8[var_4_4] = 0;
                    }
                    func_0011b8f0(func_003147d0((u8 *)work->f148), sp2B8);
                    temp_3_15 = (s8)(work->f122);
                    switch (temp_3_15) {            /* switch 6; irregular */
                    case 0:                         /* switch 6 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(0, work->f128), 0, 0, 1);
                        break;
                    case 1:                         /* switch 6 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(0, work->f129), 0, 0, 1);
                        break;
                    case 2:                         /* switch 6 */
                        func_003144d0((u8 *)work->f148, (s32)func_002e48a0(work->f2F9, work->f2FA), 0, 0, 1);
                        break;
                    }
                    temp_16_33 = (s32)(func_003147d0((u8 *)work->f148));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 0x80) {
                    if (func_0011c610(func_003147d0((u8 *)work->f148)) == 0) {
                        func_0011c630(func_003147d0((u8 *)work->f148));
                        func_00314740((u8 *)work->f148, 0);
                        return;
                    }
                    func_0011c6e0(func_003147d0((u8 *)work->f148), 1);
                    func_00314740((u8 *)work->f148, 1);
                    return;
                }
            }
        }
        break;
    case 0x82:                                      /* switch 1 */
        temp_16_34 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_15 = *(FclCombineMenu **)(arg0 + 0x38);
        temp_2_36 = (u8 *)(func_002b6150(0x7C));
        sp140 = *(FclVec2f *)(temp_2_36 + 0x38);
        temp_16_35 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_34);
        func_00275820(111.0f + sp140.x, sp140.y, 43.0f, temp_16_35, 0, 2, (const char *)((iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, temp_18_15->f128))+(2))) * 0x11)), 0, 0, D_00795E60, 0x15);
        for (var_19_6 = 0; var_19_6 < (func_0010b5b0() & 0xFFFF); var_19_6++) {
            func_0031d630(arg0, (s8)(var_19_6), work->f128, work->f129, 0);
            if (((s16)(func_002b6970((*(s16 *)((u8 *)(func_002b6150((s16)((var_19_6 + 0x270))))+(0x10))), 1))) == 0) {
                if (var_19_6 == work->f11E) {
                    var_21_2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
                } else {
                    var_21_2 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
                }
                temp_2_37 = (s8)(work->f128);
                if (temp_2_37 != var_19_6) {
                    temp_18_16 = (s8)(temp_2_37);
                    if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_16 * 0xC) + var_19_6))+(0x14))) > 0) {
                        temp_f20 = (f32)(var_19_6 * 0x17 + 0x80);
                        func_00275520((f32)0x195, temp_f20, 43.0f, var_21_2, 0, 2, (const char *)(iGpffffb440 + ((u16 *)func_002e48a0(temp_18_16 + 1, var_19_6))[1] * 0x11), 0, 0, D_00795E60);
                    }
                }
            }
        }
        if (((s8)(func_00314660((u8 *)work->f148))) == 0xE) {
            func_002b6140((u8 *)(work->f28C), 0);
            func_002b6140((u8 *)(work->f290), 0);
            work->f1 = 0x7EU;
            return;
        }
        break;
    case 0x83:                                      /* switch 1 */
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
            return;
        }
        if (func_002bb1c0(work->fD) == 0) {
            func_00106390(0x1306, 1);
            func_00314670((u8 *)work->f148, 0xB);
            func_00325450(arg0, 3, 1);
            func_002b68d0(0x7C, 0, 1);
            func_002b68d0(0x228, 0, 1);
            func_002b68d0(0x1A2, 0, 1);
            func_002b68d0(0x25C, 0, 1);
            func_002b68d0(0x54, 0, 1);
            func_002b68d0(0x26A, 0, 1);
            func_002b68d0(0x26B, 0, 1);
            func_002b68d0(0x74, 0, 1);
            func_00317240(arg0, 1, 0);
            for (var_4_5 = 0; var_4_5 < 5; var_4_5++) {
                sp2B0[var_4_5] = 0;
            }
            func_0011b8f0(func_003147d0((u8 *)work->f148), sp2B0);
            temp_3_17 = (s8)(func_00308e50(arg0));
            switch (temp_3_17) {                    /* switch 7; irregular */
            case 0:                                 /* switch 7 */
                temp_2_38 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_38)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_38)+(0x1C))) - 6);
                temp_2_39 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_39)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_39)+(0x1D))) - 6);
                break;
            case 1:                                 /* switch 7 */
                temp_2_40 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_40)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_40)+(0x1E))) - 6);
                temp_2_41 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_41)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_41)+(0x1F))) - 6);
                break;
            case 2:                                 /* switch 7 */
                temp_2_42 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_42)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_42)+(0x20))) - 6);
                temp_2_43 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_43)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_43)+(0x1C))) - 6);
                break;
            case 3:                                 /* switch 7 */
                temp_2_44 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_44)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_44)+(0x1D))) - 6);
                temp_2_45 = (u16 *)(func_002e48a0(work->f2F9, work->f2FA));
                (*(u8 *)((u8 *)(temp_2_45)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_45)+(0x1E))) - 6);
                break;
            }
            temp_18_17 = (s8)(func_00308dc0(arg0));
            temp_16_37 = (s8)(func_00308e50(arg0));
            func_00110270((u8 *)func_00308cc0(arg0), ((((s8)(temp_18_17)) << 8) | (((s8)(temp_16_37)) | 0x30)) & 0xFFFF);
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, work->f128))+(2))));
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, work->f129))+(2))));
            func_003205f0(arg0, 0x96, 0x94);
            work->f1 = 0x84U;
        } else {
            work->f1 = 0x81U;
        }
        func_002bb550(work->fD);
        return;
    case 0x84:                                      /* switch 1 */
        if (((s8)(func_00314660((u8 *)work->f148))) == 0xE) {
            func_00315600(arg0, 0);
            func_002b6140((u8 *)(work->f28C), 0);
            func_002b6140((u8 *)(work->f290), 0);
            work->fB6 = 0;
            func_0032f4d0(arg0);
            work->f0 = 0;
            work->f1 = 0x1BU;
            return;
        }
        break;
    case 0x85:                                      /* switch 1 */
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
            return;
        }
        work->f1 = 0x86U;
        func_002bb550(work->fD);
        temp_16_38 = func_0010b6f0() & 0xFFFF;
        if (temp_16_38 == (func_0010b5b0() & 0xFFFF)) {
            func_00310960(arg0, 0x23, 0);
            work->f1 = 0x87U;
            return;
        }
        if (func_00309630((*(u16 *)((u8 *)(func_001102e0())+(2)))) == 1) {
            func_00310960(arg0, 0x27, 0);
            work->f1 = 0x87U;
            return;
        }
        func_00310960(arg0, 0x1E, 1);
        return;
    case 0x86:                                      /* switch 1 */
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
            return;
        }
        if (func_002bb1c0(work->fD) == 0) {
            temp_4_3 = func_001102d0() & 0xFFFF;
            if ((((s8)(((temp_4_3 >> 0xC) & 0xF))) >= ((s8)(((temp_4_3 >> 4) & 0xF)))) && (datGetFlag(0x1307) == 0)) {
                work->f1C = func_003096d0(arg0);
                temp_3_18 = work->f1C;
                if (temp_3_18 == -1) {
                    func_0010b190((u8 *)func_001102e0());
                    func_00106390(0x1306, 0);
                    func_00106390(0x1307, 0);
                    work->fBC = 0x16B;
                    goto block_274;
                }
                temp_16_39 = (u16 *)((u8 *)iGpffffb3ec + temp_3_18 * 4);
                work->fD = func_002bab80((void *)func_00331660());
                sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(*temp_16_39));
                func_002bbd80(work->fD, 0, &skillName);
                func_002bafc0(work->fD, 0);
                func_002badc0(work->fD, 0x24);
                func_002bb0a0(work->fD, 0);
                func_002bbf60();
                work->f1 = 0x88U;
                return;
            }
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            work->fBC = 0x16B;
            for (var_4_6 = 0; var_4_6 < 5; var_4_6++) {
                sp2A8[var_4_6] = 0;
            }
            func_0011b8f0(func_003147d0((u8 *)work->f148), sp2A8);
            goto block_274;
        }
block_274:
        func_00314670((u8 *)work->f148, 0xB);
        work->f1 = 0x84U;
        func_002bb550(work->fD);
        return;
    case 0x88:                                      /* switch 1 */
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
            return;
        }
        if (func_002bb1c0(work->fD) == 0) {
            func_002bb550(work->fD);
            work->f2D8 = 0;
            work->f1 = 0x89U;
            return;
        }
        func_002bb550(work->fD);
        func_00314670((u8 *)work->f148, 0xB);
        work->f1 = 0x84U;
        func_0010b190((u8 *)func_001102e0());
        func_00106390(0x1306, 0);
        func_00106390(0x1307, 0);
        work->fBC = 0x16B;
        return;
    case 0x89:                                      /* switch 1 */
        temp_16_40 = (FclSkillPair *)iGpffffb3ec + work->f1C;
        work->f2D8 = func_002b2cb0(work->f2D8, 1, 0x28, 0, 1);
        if (work->f2D8 == 0x14) {
            func_0011cc00(func_003147d0((u8 *)work->f148), temp_16_40->original, temp_16_40->replacement);
            func_0010cd70((u8 *)func_001102e0(), (s16)temp_16_40->original, temp_16_40->replacement);
            func_0045af60(1, 3, 3, 2);
        }
        if (work->f2D8 >= 0x28) {
            work->fD = func_002bab80((void *)func_00331660());
            sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(temp_16_40->original));
            func_002bbd80(work->fD, 0, &skillName);
            sprintf(skillName, (const char *)&iGpffffa8a4, (const char *)func_00243840(temp_16_40->replacement));
            func_002bbd80(work->fD, 1, &skillName);
            func_002badc0(work->fD, 0x57);
            work->f1 = 0x87U;
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            work->fBC = 0x16B;
            return;
        }
        break;
    case 0x87:                                      /* switch 1 */
        if (func_002bb680(work->fD) != 0) {
            func_002bbcf0(work->fD);
            return;
        }
        func_00314670((u8 *)work->f148, 0xB);
        work->f1 = 0x84U;
        func_002bb550(work->fD);
        for (var_4_7 = 0; var_4_7 < 5; var_4_7++) {
            sp2A0[var_4_7] = 0;
        }
        func_0011b8f0(func_003147d0((u8 *)work->f148), sp2A0);
        break;
    }
}
#undef FCL_COMBINE_GRID_ROW
#pragma pop
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
        if (table[i] == ((u16 *)func_002e48a0(0, p[0x128]))[1]) {
            return (u16 *)func_002e48a0(0, p[0x129]);
        }
        if (table[i] == ((u16 *)func_002e48a0(0, p[0x129]))[1]) {
            return (u16 *)func_002e48a0(0, p[0x128]);
        }
    }
    return 0;
}
// FUN_00308DC0
s32 func_00308dc0(u8 *task)
{
    s16 i;
    s32 temp;
    s8 *p;

    temp = (u8)(RpRandom() % 100U);
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
        if (table[i] == ((u16 *)func_002e48a0(0, p[0x128]))[1]) return (s8)i;
        if (table[i] == ((u16 *)func_002e48a0(0, p[0x129]))[1]) return (s8)i;
    }
    return -1;
}
/* floor (above marker kept clear for the verifier): the array-address
   sequence sll/addu(sp)/addiu(0x48) vs mwcc's sll/addiu/addu with swapped
   $v0/$v1 coloring — probed array, pointer, named-temp, separate-locals,
   byte-offset forms and schedule/opt_* pragmas; best nd 4 (scheduling). */
/* MATCHED: the four nibbles are s8 locals (retail re-extends each at use)
   extracted in n1, n2, n0, n3 order; the flag walk counter is s32 against a
   (u16) count; total is s16; packed is u16 built n0-first with no nibble
   masks; the switch is on n0, not n2.  func_003095f0 returns u16 and
   func_001102c0 takes u16 (no mask / sign-extension at either call site).
   The byte sum reads ((u8 *)&func_001102e0()[0x13])[j] (addu, lbu 0x26)
   and packed is declared before j (register rotation). */
// FUN_00308F40
void func_00308f40(void) {
    u16 raw;
    s8 n0;
    s8 n1;
    s8 n2;
    s8 n3;
    s16 total;
    s32 i;
    u16 packed;
    s32 j;
    u8 *p;

    raw = func_001102d0();
    n1 = (raw >> 4) & 0xF;
    n2 = (raw >> 8) & 0xF;
    n0 = raw & 0xF;
    n3 = (raw >> 12) & 0xF;
    total = 0;
    for (i = 0; i < (u16)func_0010b6f0(); i++) {
        if (func_00109470(i) & 4) {
            if (func_00109470(i) & 0x80) {
                *func_0010ace0(i) ^= 4;
                *func_0010ace0(i) ^= 0x20;
                *func_0010ace0(i) ^= 0x40;
                *func_0010ace0(i) ^= 0x80;
            } else if (func_00109470(i) & 0x40) {
                *func_0010ace0(i) |= 0x80;
            } else if (func_00109470(i) & 0x20) {
                *func_0010ace0(i) |= 0x40;
            } else {
                *func_0010ace0(i) |= 0x20;
            }
        }
    }
    if (datGetFlag(0x1307) == 0 && datGetFlag(0x1306) != 0) {
        n3 = func_002b2cb0(n3, 1, 6, 0, 1);
        packed = n0 | (n1 << 4) | (n2 << 8) | (n3 << 12);
        for (j = 0; j < 5; j++) {
            total += ((u8 *)&((u16 *)func_001102e0())[0x13])[j];
        }
        if (n3 >= n2 || n3 == 6) {
            p = (u8 *)func_001102e0();
            func_0010cad0(p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), packed);
            func_00106390(0x1307, 1);
            return;
        }
        if (total >= 0x1E) {
            p = (u8 *)func_001102e0();
            func_0010cad0(p, func_003095f0());
            func_00110270((u8 *)func_001102e0(), packed);
            func_00106390(0x1307, 1);
            return;
        }
        func_001102c0(packed);
        switch (n0) {
        case 0:
            if (((u8 *)func_001102e0())[0x1C] != 0x63) {
                ((u8 *)func_001102e0())[0x26] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x26],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)func_001102e0())[0x1D] != 0x63) {
                ((u8 *)func_001102e0())[0x27] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x27],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 1:
            if (((u8 *)func_001102e0())[0x1E] != 0x63) {
                ((u8 *)func_001102e0())[0x28] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x28],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)func_001102e0())[0x1F] != 0x63) {
                ((u8 *)func_001102e0())[0x29] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x29],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 2:
            if (((u8 *)func_001102e0())[0x20] != 0x63) {
                ((u8 *)func_001102e0())[0x2A] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x2A],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)func_001102e0())[0x1C] != 0x63) {
                ((u8 *)func_001102e0())[0x26] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x26],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        case 3:
            if (((u8 *)func_001102e0())[0x1D] != 0x63) {
                ((u8 *)func_001102e0())[0x27] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x27],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            if (((u8 *)func_001102e0())[0x1E] != 0x63) {
                ((u8 *)func_001102e0())[0x28] =
                    func_002b2cb0(((u8 *)func_001102e0())[0x28],
                                 D_00749350[n3], 0x63, 0, 1);
            }
            break;
        }
    }
}

// FUN_003095F0
u16 func_003095f0(void)
{
    if (((u16 *)func_001102e0())[1] == 0xB3) {
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
s32 func_003096d0(u8 *task)
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
        temp_18 = (s16)(RpRandom() % temp_16);
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
/* measured: 6272B == retail window, zero differing words. The search helper
   below is inlined at each single-id test; the two 6-id scans in states
   0xCC/0xCE are written out with their own index declared before the outer
   counter, which gives retail's $t2/$t1 colouring (the helper form swaps them).
   The fade tail is a second inline so each expansion gets its own stack slots. */
/* Membership test over the work's slot list (count at +0x2DF, entries at
   +0x2DA). Retail inlines it at every use and re-reads the work pointer. */
static inline s32 fclCombineHasEntry(u8 *task, s8 id)
{
    u8 *w = *(u8 **)(task + 0x38);
    s16 i;

    for (i = 0; i < *(s8 *)(w + 0x2DF); i++) {
        if (*(s8 *)(w + i + 0x2DA) == id) {
            return 1;
        }
    }
    return 0;
}

/* Starts the 20-frame fade used when the combine result is confirmed. */
static inline void fclCombineStartFade(u8 *task)
{
    extern u8 *func_001102f0(u8 *, s32, s32, f32);
    extern void func_00348c30(s32, s32);
    u8 *w = *(u8 **)(task + 0x38);
    FclVec3 pos;
    FclDrawColor color;

    func_001102f0((u8 *)&pos, 0x140, 0xA5, 300.0f);
    color = func_002b2a60(0xFF, 0xFF, 0xFF, 0xFF);
    func_003489c0(*(u8 **)(w + 0x308), pos, 0.0f, 0.0f, 0.0f, 1.0f, color, 0, -1);
    func_00348c30(*(s32 *)(w + 0x308), 0x14);
    *(s16 *)(w + 0x2D8) = 0;
}

/* measured: the loop-invariant pragma hoists the slot-search id and count out of
   every inlined search, as retail does. */
// FUN_003097E0
#pragma opt_loop_invariants on
void func_003097e0(u8 *arg0) {
    extern void func_0034a640(s32, u16, s32);
    extern s32 func_0033f690(u8 *, u16 *, s32);
    extern s32 func_003488d0(u8 *, void *, s32);
    extern s8 *func_0033fa20(s32);
    extern s32 func_00348be0(s32);
    extern s32 func_0033dc90(u8 *, s8);
    extern void func_00275980(void *, void *, s32);
    extern void func_0034a820(s32);
    extern s32 func_00311900(s32);
    extern void func_00314400(u8 *, s8);
    extern void func_00303de0(u8 *);
    extern u8 D_00641B50[];
    u8 *p;
    u16 cls;
    s16 i;
    s16 j;
    s32 v;
    s16 k;
    char spA0[32];
    char sp80[32];
    u16 buf[12];

    p = *(u8 **)(arg0 + 0x38);
    cls = *(u16 *)((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1);
    switch (p[1]) {
    case 0xC5:
        func_00106390(0x58, 0);
        func_00106390(0x59, 0);
        func_00106390(0x5A, 0);
        func_00106390(0x5B, 0);
        func_00106390(0x5C, 0);
        func_00106390(0x5D, 0);
        func_00106390(0x5E, 0);
        func_00106390(0x5F, 0);
        func_00106390(0x1450, 0);
        *(s8 *)(p + 0x26) = 0;
        *(s8 *)(p + 0x20) = 0;
        *(s16 *)(p + 0xE) = 0;
        *(s8 *)(p + 0x21) = 0;
        *(s16 *)(p + 0x2D8) = 0;
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        for (i = 0; i < 0x30C; i++) {
            func_002b68d0(i, 0, 1);
        }
        func_00303de0(arg0);
        func_0034a640(*(s32 *)(p + 0x254), cls, 0);
        *(((s8 *)func_0034a630(*(u8 **)(p + 0x254))) + 1) = 0;
        for (k = 0; k < 0xC; k++) {
            buf[k] = 0;
        }
        switch (*(s8 *)(p + 0x1A)) {
        case 2:
            buf[0] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 1);
            break;
        case 3:
            buf[0] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x129)) + 1);
            buf[2] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 2);
            break;
        case 4:
            buf[0] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 3);
            break;
        case 5:
            buf[0] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 4);
            break;
        case 6:
            buf[0] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            buf[5] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 5) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 5);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                buf[i] = *(u16 *)((u16 *)func_002e48a0(0, i) + 1);
            }
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 6);
            break;
        }
        if (func_00105f50(cls) > 0) {
            *(s32 *)(p + 0x308) = func_003488d0(arg0, D_00641B50, 7);
        }
        p[1] = 0xC6;
        break;
    case 0xC6:
        if (*func_0033fa20(*(s32 *)(p + 0x304)) != 0 &&
            (func_00105f50(cls) <= 0 || func_00348be0(*(s32 *)(p + 0x308)) != 0)) {
            *(s32 *)(p + 0x300) = func_0033dc90(arg0, *(s8 *)(p + 0x1A) - 2);
            if (*(s8 *)(p + 0xB2) != 0) {
                func_00106390(0x5C, 1);
            }
            p[1] = 0xC7;
        }
        break;
    case 0xC7:
        if (datGetFlag(0x5B) != 0) {
            if (*(s8 *)(p + 0xB2) == 1) {
                func_00310960(arg0, 0x28, 0);
                p[1] = 0xC8;
                return;
            }
            if (*(s8 *)(p + 0xB2) == 2) {
                func_00310960(arg0, 0x29, 0);
                p[1] = 0xC8;
                return;
            }
            if (func_00303a20(arg0) == 1 && fclCombineHasEntry(arg0, 0xC) == 1) {
                p[1] = 0xCB;
                *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
                func_002badc0(*(s8 *)(p + 0xD), 0x2A);
                *(u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
                return;
            }
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        }
        break;
    case 0xC8:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (func_00303a20(arg0) == 1 && fclCombineHasEntry(arg0, 0xC) == 1) {
            p[1] = 0xCB;
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002badc0(*(s8 *)(p + 0xD), 0x2A);
            *(u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
            return;
        }
        if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
            p[1] = 0xCC;
            return;
        }
        *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
        sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
        func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
        func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
        p[1] = 0xCA;
        break;
    case 0xC9:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xC7;
        break;
    case 0xCA:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xCC;
        if (datGetFlag(0x5B) != 0) {
            p[1] = 0xCC;
        }
        break;
    case 0xCB:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (datGetFlag(0x5B) != 0) {
            if (iGpffffb3d4[cls * 0xE + 0xD] == 0) {
                p[1] = 0xCC;
                return;
            }
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), iGpffffb3d4[cls * 0xE + 0xD] + 0x71);
            p[1] = 0xCA;
        } else if (datGetFlag(0x5C) != 0) {
            p[1] = 0xC9;
        }
        p[1] = 0xC7;
        break;
    case 0xCC:
        if (func_00105f50(cls) == 0) {
            p[1] = 0xCF;
            if (func_00303a20(arg0) == 1) {
                if (fclCombineHasEntry(arg0, 7) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    *(s8 *)(p + 0x13C) = 1;
                    return;
                }
                if (fclCombineHasEntry(arg0, 0xD) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                    *(s8 *)(p + 0x13C) = 3;
                    return;
                }
                if (fclCombineHasEntry(arg0, 0xA) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
                {
                    s16 n;
                    s16 m;
                    u8 *w;
                    s32 r;

                    for (m = 0; m < 6; m++) {
                        w = *(u8 **)(arg0 + 0x38);
                        for (n = 0; n < *(s8 *)(w + 0x2DF); n++) {
                            if (*(s8 *)(w + n + 0x2DA) == (s8)(m + 1)) {
                                r = 1;
                                goto found_cc;
                            }
                        }
                        r = 0;
                    found_cc:
                        if (r == 1) {
                            func_00106390(0x59, 1);
                            *(s8 *)p = 0xC;
                            p[1] = 0xA0;
                            break;
                        }
                    }
                }
                if (fclCombineHasEntry(arg0, 9) == 1) {
                    func_00106390(0x59, 1);
                    *(s8 *)p = 0xC;
                    p[1] = 0xA0;
                }
            }
        } else {
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(s8 *)(p + 0xD), 0,
                          iGpffffb44c + func_00109280(*(u16 *)((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9),
                                                                             *(s8 *)(p + 0x2FA)) + 1)) * 0x15);
            sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
            func_002badc0(*(s8 *)(p + 0xD), 0x3A);
            p[1] = 0xCD;
        }
        break;
    case 0xCD:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (fclCombineHasEntry(arg0, 8) == 1) {
            v = func_00247770(iGpffffb3d4[cls * 0xE + 2]);
            *(s32 *)(p + 0x10) = func_00311930(v, func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 1);
            if (func_00303a20(arg0) == 1) {
                *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
                sprintf(spA0, (const char *)&iGpffffa8a4, func_00311900(func_00247770(iGpffffb3d4[cls * 0xE + 2])));
                func_00275980(spA0, sp80, 0x20);
                func_002bbd80(*(s8 *)(p + 0xD), 0, sp80);
                sprintf(spA0, (const char *)&iGpffffa8a4, iGpffffb440 + cls * 0x11);
                func_002bbd80(*(s8 *)(p + 0xD), 1, spA0);
                func_002badc0(*(s8 *)(p + 0xD), 0x55);
                *(s8 *)(p + 0x21) = 1;
                p[1] = 0xD0;
                return;
            }
            func_0034a820(*(s32 *)(p + 0x254));
            func_00106390(0x59, 1);
            fclCombineStartFade(arg0);
            p[1] = 0xD1;
        } else {
            *(s32 *)(p + 0x10) = func_00311930(func_00247770(iGpffffb3d4[cls * 0xE + 2]), func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 0);
            func_0034a820(*(s32 *)(p + 0x254));
            func_00106390(0x59, 1);
            fclCombineStartFade(arg0);
            p[1] = 0xD1;
        }
        break;
    case 0xCE:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        p[1] = 0xCF;
        if (func_00303a20(arg0) == 1) {
            if (fclCombineHasEntry(arg0, 7) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                *(s8 *)(p + 0x13C) = 1;
                return;
            }
            if (fclCombineHasEntry(arg0, 0xD) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
                *(s8 *)(p + 0x13C) = 3;
                return;
            }
            if (fclCombineHasEntry(arg0, 0xA) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
            {
                s16 n;
                s16 m;
                u8 *w;
                s32 r;

                for (m = 0; m < 6; m++) {
                    w = *(u8 **)(arg0 + 0x38);
                    for (n = 0; n < *(s8 *)(w + 0x2DF); n++) {
                        if (*(s8 *)(w + n + 0x2DA) == (s8)(m + 1)) {
                            r = 1;
                            goto found_ce;
                        }
                    }
                    r = 0;
                found_ce:
                    if (r == 1) {
                        func_00106390(0x59, 1);
                        *(s8 *)p = 0xC;
                        p[1] = 0xA0;
                        break;
                    }
                }
            }
            if (fclCombineHasEntry(arg0, 9) == 1) {
                func_00106390(0x59, 1);
                *(s8 *)p = 0xC;
                p[1] = 0xA0;
            }
        }
        break;
    case 0xCF:
        func_00106390(0x59, 1);
        func_00106390(0x5D, 1);
        func_00106390(0x5F, 1);
        *(s8 *)p = 0xE;
        p[1] = 0xD2;
        func_00314400((u8 *)*(s32 *)(p + 0x148), 0);
        break;
    case 0xD0:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        func_0034a820(*(s32 *)(p + 0x254));
        func_00106390(0x59, 1);
        fclCombineStartFade(arg0);
        p[1] = 0xD1;
        break;
    case 0xD1:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x32, 0, 1);
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            func_0045af60(1, 0, 4, 5);
        }
        if (*(s8 *)(((s8 *)func_0034a630(*(u8 **)(p + 0x254))) + 4) == 4 && *(s16 *)(p + 0x2D8) >= 0x14) {
            *(s8 *)p = 0xC;
            p[1] = 0xA0;
        }
        break;
    }
}
#pragma opt_loop_invariants reset

/* MATCHED: switch on the state byte (C2/C3/C4) with s16 loop counters;
   colours are FclDrawColor struct returns copied whole to te+0x85 (lbu x4,
   sb x4); the D_00640D78 pair is read through a named FclVec2f base (lui/
   addiu base then lwc1 0/4); the flag at p+0x13A is s8; the scroll loop
   declares k before e and keeps lim as s32; the 0xD store is re-read as
   *(s8 *)(p + 0xD) for func_002badc0 (b210 forwards it after the lh). */
// FUN_0030B060
void func_0030b060(u8 *arg0)
{
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    s16 k;
    s16 e;
    s32 lim;
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    u8 *te;
    FclVec2f *base;

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
            v0 = func_002b2970(26.0f, (f32)(j * 0x22 + 0x57));
            func_003147e0(arg0, (s8)j, v0, (s16)(j + 0x179), (s16)(j * 2 + 2), 0);
        }
        c0 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) * 2 + 500));
        *(FclDrawColor *)(te + 0x85) = c0;
        c1 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) * 2 + 501));
        *(FclDrawColor *)(te + 0x85) = c1;
        c2 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x11E) + 0x179));
        *(FclDrawColor *)(te + 0x85) = c2;
        c3 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
        te = func_002b6150((s16)(*(s16 *)(p + 0x120) + 0x2FB));
        *(FclDrawColor *)(te + 0x85) = c3;
        base = (FclVec2f *)D_00640D78;
        v1 = func_002b2970(base->x, base->y);
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
                                if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
                                    func_00330060(arg0, 5);
                                    return;
                                }
                                if (D_008C027A[0] & 0x1000) {
                                    func_00330060(arg0, 1);
                                    return;
                                }
                                if ((D_008C0276[0] & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
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
*(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
                                    func_002badc0(*(s8 *)(p + 0xD), *(s16 *)(p + 0x11E) + 0x58);
                                    *(p + 1) = 0xC4;
                                } else if (D_008C024E[0] & 0x20) {
                                    func_0045af60(0, 0, 0, 2);
                                    func_003205f0(arg0, 0x96, 0x97);
                                    base = (FclVec2f *)D_00640D78;
                                    v2 = func_002b2970(base->x, base->y);
                                    func_00324f80(arg0, v2, 1, 1);
                                    e = *(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120);
                                    k = 0;
                                    lim = e + 6;
                                    for (; e < lim; e++, k++) {
                                        v3 = func_002b2970(26.0f, (f32)(k * 0x22 + 0x57));
                                        func_003147e0(arg0, (s8)k, v3, (s16)(e + 0x179),
                                                      (s16)((5 - k) * 2), 1);
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
        if (func_002bb680((s8)*(p + 0xD)) != 0) {
            func_002bbcf0((s8)*(p + 0xD));
        } else {
            func_002bb550((s8)*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}

/* MATCHED: colours are FclDrawColor struct returns copied whole (the
   501 -> 500 copy is a struct copy between the two elements); the flag
   words are read directly (b210 CSEs them where retail does); case 0 tests
   func_00104f10(1) >= 3 && !flag 0x96F for the 0x70 arm; *(s8 *)te is the
   second func_003147e0 argument. The row loop derives the second byte as
   &D_00882FB0[j * 2] + 1: that second use of j is what makes b210
   re-extend j at the top of the body instead of reusing the test's copy. */
// FUN_0030B7B0
void func_0030b7b0(u8 *arg0) {
    u8 *p;
    u8 kind;
    s16 i;
    s16 j;
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclVec2 v4;
    FclVec2 v5;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    FclDrawColor c5;
    FclDrawColor c6;
    u8 *te;
    u8 *te2;
    u8 *p501;
    u8 *p500;
    u8 *row;
    s8 sidx;
    s8 t;

    p = *(u8 **)(arg0 + 0x38);
    kind = *(p + 1);
    switch (kind) {
    case 0xC2:
        func_003205f0(arg0, 0x97, 0x96);
        *(s16 *)(p + 0x11E) = 0;
        *(p + 0x139) = 0;
        v0 = func_002b2970(26.0f, 87.0f);
        func_003147e0(arg0, 0, v0, 0x168, 2, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0;
        *(s8 *)(p + 0x139) += 1;
        v1 = func_002b2970(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 1, v1, 0x174, 4, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 1;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xC;
        *(s8 *)(p + 0x139) += 1;
        v2 = func_002b2970(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 2, v2, 0x170, 6, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 2;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 8;
        *(s8 *)(p + 0x139) += 1;
        v3 = func_002b2970(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 3, v3, 0x171, 8, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 3;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 9;
        *(s8 *)(p + 0x139) += 1;
        if (datGetFlag(0x1305) != 0) {
            v4 = func_002b2970(26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
            func_003147e0(arg0, 0xB, v4, 0x173, 0xA, 0);
            D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0xB;
            D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xB;
            *(s8 *)(p + 0x139) += 1;
        }
        for (j = 0; j < *(s8 *)(p + 0x139); j++) {
            te = &D_00882FB0[j * 2];
            c0 = func_002b2a60(0, 0, 0x66, 0xFF);
            p501 = func_002b6150((s16)(*(s8 *)te * 2 + 501));
            *(FclDrawColor *)(p501 + 0x85) = c0;
            p500 = func_002b6150((s16)(*(s8 *)te * 2 + 500));
            *(FclDrawColor *)(p500 + 0x85) = *(FclDrawColor *)(p501 + 0x85);
            row = &D_00882FB0[j * 2] + 1;
            c1 = func_002b2a60(0xCC, 0xFF, 0xFF, 0xFF);
            te2 = func_002b6150((s16)(*(s8 *)row + 0x168));
            *(FclDrawColor *)(te2 + 0x85) = c1;
            if (*(s8 *)te == 0xB && datGetFlag(0x1308) == 0) {
                c2 = func_002b2a60(0xFF, 0xCC, 0xFF, 0xFF);
                te2 = func_002b6150((s16)(*(s8 *)row + 0x168));
                *(FclDrawColor *)(te2 + 0x85) = c2;
            }
        }
        c3 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150(500);
        *(FclDrawColor *)(te + 0x85) = c3;
        c4 = func_002b2a60(0xC6, 0xEE, 1, 0xFF);
        te = func_002b6150(501);
        *(FclDrawColor *)(te + 0x85) = c4;
        c5 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
        te = func_002b6150(0x168);
        *(FclDrawColor *)(te + 0x85) = c5;
        c6 = func_002b2a60(0x92, 0xC8, 7, 0xFF);
        te = func_002b6150((s16)(*(s8 *)(D_00882FB0 + *(s16 *)(p + 0x11E) * 2) + 0x2FB));
        *(FclDrawColor *)(te + 0x85) = c6;
        if (*(s8 *)(p + 0x138) > 0) {
            func_0032f060(arg0, 0);
        }
        *(p + 1) = 0xC3;
        break;
    case 0xC3:
        if ((s16)func_002b6970(
                *(s16 *)(func_002b6150((s16)(*(s8 *)(D_00882FAE + *(s8 *)(p + 0x139) * 2) * 2 + 500)) + 0x10),
                1) != 1) {
            if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
                func_003307b0(arg0, 5, D_00882FB0);
                return;
            }
            if (D_008C027A[0] & 0x1000) {
                func_003307b0(arg0, 1, D_00882FB0);
                return;
            }
            if ((D_008C0276[0] & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
                func_003307b0(arg0, 4, D_00882FB0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                func_003307b0(arg0, 0, D_00882FB0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                func_0045af60(0, 0, 0, 1);
                t = D_00882FB0[*(s16 *)(p + 0x11E) * 2];
                switch (t) {
                case 0:
                    *(p + 0xD) = func_002bab80((void *)func_00331660());
                    if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 &&
                        (func_002e78e0() & 0xFF) < 0x20) {
                        func_002badc0((s8)*(p + 0xD), 0x6F);
                    } else if ((s16)func_00104f10(1) >= 3 && datGetFlag(0x96F) == 0) {
                        func_002badc0((s8)*(p + 0xD), 0x70);
                    } else {
                        func_002badc0((s8)*(p + 0xD), (func_00107ac0(0x14) & 0xFFFF) + 0x64);
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
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                for (i = 0; i < *(s8 *)(p + 0x139); i++) {
                    te = &D_00882FB0[i * 2];
                    v5 = func_002b2970(26.0f, (f32)(i * 0x22 + 0x57));
                    func_003147e0(arg0, *(s8 *)te, v5, (s16)(*(s8 *)(te + 1) + 0x168), (s16)(i * 2 + 2), 1);
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
        if (func_002bb680((s8)*(p + 0xD)) != 0) {
            func_002bbcf0((s8)*(p + 0xD));
        } else {
            func_002bb550((s8)*(p + 0xD));
            *(p + 1) = 0xC3;
        }
        break;
    }
}

/* One four-byte ingredient slot of the D_0063FCA0 recipe rows and the
   D_006406F0 calendar rows read by func_0030c3c0. */
typedef struct {
    s8 kind;
    s8 weight;
    s16 item;
} FclCombineSlot;

/* Nonzero when the task's slot list (count at 0x2DF, kinds from 0x2DA)
   holds the given kind.  Retail inlines this at every use. */
static inline s32 fclCombineHasSlotKind(u8 *arg0, s8 kind)
{
    s8 *q = *(s8 **)(arg0 + 0x38);
    s16 i;

    for (i = 0; i < q[0x2DF]; i++) {
        if (q[i + 0x2DA] == kind) {
            return 1;
        }
    }
    return 0;
}

/* The item table lookup of func_003042f0, which retail inlines into
   func_0030c3c0 with the kind read before the roll is made. */
static inline s16 fclCombinePickItem(s8 kind, s8 roll)
{
    switch (kind) {
    case 1:
        return D_00749040[roll];
    case 2:
        return D_00749060[roll];
    case 3:
        return D_00749080[roll];
    case 4:
        return D_007490A0[roll];
    case 5:
        return D_007490C0[roll];
    case 6:
        return D_007490E0[roll];
    }
    return -1;
}

/* The independent state scans preserve each counter's lifetime.
   Item values narrow at their halfword consumers; the skill replacement
   provider and every caller use a signed-halfword previous-skill ID.
   The progress value is explicitly forwarded to the child setter. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_common_subs off
static inline u16 fclItemHalf(const s32 *value)
{
    return *value;
}
#pragma pop
// FUN_0030C3C0
#pragma push
/* measured: hoists each slot scan's count and kind out of its loop. */
#pragma opt_loop_invariants on
/* measured: keeps the 0xAC slot pointer as its own index-first address. */
#pragma opt_propagation off
void func_0030c3c0(u8 *arg0) {
    extern s32 func_00106330(s32);
    extern u32 func_0011f560(u8 *);
    extern void func_003146c0(u8 *, u32);
    extern s32 func_0045aa90(s16, s16);
    extern u8 *func_0011f410(s32, s32, u8 *, s32, s32, s32 *);
    extern u8 *func_0011fbc0(s32, u8 *, s32, u8 *);
    extern s32 func_0011fcf0(u8 *);
    extern void func_00275980(void *, void *, s32);
    extern void func_0011cdd0(u8 *, s32);
    extern void func_0011ce30(u8 *);
    extern s32 func_0011cb70(u8 *, u16);
    extern void func_002e4960(u8 *, s8, s16);
    extern void func_00314400(u8 *, s8);
    extern s32 D_00641B90[];
    extern u8 D_00641AD0[];
    u8 list[5];
    FclPackedPosition pos;
    char text[0x20];
    char name[0x20];
    FclCombineRecipe info;
    u8 *p;
    s8 *slot;
    u8 *e;
    u8 *row;
    FclCombineSlot *cal;
    s16 j1;
    s8 *q2;
    s16 k2;
    s32 found2;
    s16 j2;
    s8 *q3;
    s16 k3;
    s32 found3;
    s16 j3;
    s16 i1;
    s16 i2;
    s16 i3;
    s16 i4;
    s16 i5;
    s16 i6;
    s16 i7;
    s16 i8;
    s16 i9;
    s8 *q4;
    s16 k4;
    s32 found4;
    s16 j4;
    s16 i10;
    s16 i11;
    s8 *q5;
    s16 k5;
    s32 found5;
    s16 j5;
    s8 *q6;
    s16 k6;
    s32 found6;
    s16 j6;
    s8 *q7;
    s16 k7;
    s32 found7;
    s16 j7;
    s16 i12;
    s16 j8;
    s16 i13;
    s16 i14;
    s16 i15;
    s8 best;
    s8 top;
    u32 count;
    s8 kind;
    s8 roll;
    s32 item;
    u16 id;

    p = *(u8 **)(arg0 + 0x38);
    id = ((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[1];
    switch (p[1]) {
    case 0xA0:
        if (func_00106330(0x5E) != 0) {
            *((s8 *)func_0034a630(*(u8 **)(p + 0x254))) = 4;
            func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), 0, 0, 0);
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
            p[1] = 0xA1;
        }
        break;
    case 0xA1:
        func_00106390(0x5D, 1);
        if (func_00105f50(id) > 0) {
            p[1] = 0xA2;
            {
                u8 *persona;
                s32 experience;
                persona = func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
                experience = *(s32 *)(p + 0x10);
                func_0010be60(persona, p + 0x28, experience);
            }
            p[0xB1] = p[0x28];
        } else if (func_00303a20(arg0) == 1) {
            if (fclCombineHasSlotKind(arg0, 7) == 1) {
                p[1] = 0xA8;
                p[0x22] = 0xA8;
                p[0x13C] = 1;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            } else if (fclCombineHasSlotKind(arg0, 0xD) == 1) {
                p[1] = 0xA8;
                p[0x22] = 0xA8;
                p[0x13C] = 3;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            } else if (fclCombineHasSlotKind(arg0, 0xA) == 1) {
                p[1] = 0xB2;
                p[0x22] = 0xB2;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            } else {
                for (j1 = 0; j1 < 6; j1++) {
                    if (fclCombineHasSlotKind(arg0, j1 + 1) == 1) {
                        p[1] = 0xAC;
                        p[0x22] = 0xAC;
                        if (*(s8 *)(p + 0x21) == 0) {
                            p[1] = 0xBD;
                        }
                        return;
                    }
                }
                if (fclCombineHasSlotKind(arg0, 9) == 1) {
                    p[1] = 0xB8;
                    p[0x22] = 0xB8;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                }
            }
        }
        break;
    case 0xA2:
        if (*(s8 *)(p + 0xB1) != 0) {
            *(s32 *)(p + 0x14) = func_00313fb0(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            {
                u8 *persona;
                s32 experience;
                persona = func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
                experience = *(s32 *)(p + 0x14);
                func_0010be60(persona, p + 0x28, experience);
            }
            *(s32 *)(p + 0x10) -= *(s32 *)(p + 0x14);
            *(s16 *)(p + 0x1C) = 0;
            *(s16 *)(p + 0x2D8) = 1;
            (*(s8 *)(p + 0xB1))--;
            p[1] = 0xA4;
            func_0045af60(0, 0, 0, 0xA);
        } else {
            p[1] = 0xBF;
            if (func_00303a20(arg0) == 1) {
                if (fclCombineHasSlotKind(arg0, 7) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 1;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                } else if (fclCombineHasSlotKind(arg0, 0xD) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 3;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                } else if (fclCombineHasSlotKind(arg0, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j2 = 0; j2 < 6; j2++) {
                        q2 = *(s8 **)(arg0 + 0x38);
                        for (k2 = 0; k2 < q2[0x2DF]; k2++) {
                            if (q2[k2 + 0x2DA] == (s8)(j2 + 1)) {
                                found2 = 1;
                                goto checked2;
                            }
                        }
                        found2 = 0;
                    checked2:
                        if (found2 == 1) {
                            p[1] = 0xAC;
                            p[0x22] = 0xAC;
                            if (*(s8 *)(p + 0x21) == 0) {
                                p[1] = 0xBD;
                            }
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(arg0, 9) == 1) {
                        p[1] = 0xB8;
                        p[0x22] = 0xB8;
                        if (*(s8 *)(p + 0x21) == 0) {
                            p[1] = 0xBD;
                        }
                    }
                }
            }
        }
        break;
    case 0xA3:
        if (func_0011f560(*(u8 **)(p + 0x2A4)) != 0) {
            func_00452080((KwlnTask *)*(u8 **)(p + 0x2A4));
            *(u8 **)(p + 0x2A4) = 0;
            p[1] = 0xA2;
        }
        break;
    case 0xA4:
        func_003146c0(*(u8 **)(p + 0x148),
                      *(u32 *)(p + 0x14) - (u32)func_002b2aa0(2, 1.0f, (f32)*(u32 *)(p + 0x14),
                                                               (f32)*(s16 *)(p + 0x2D8), 55.0f));
        if (*(s16 *)(p + 0x2D8) < 0x37) {
            *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x37, 0, 1);
            if (*(s16 *)(p + 0x2D8) > 0xF &&
                ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x800))) {
                *(s16 *)(p + 0x2D8) = 0x37;
            }
        } else {
            func_0045aa90(0, 0);
            *(s32 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 8) += func_00313fb0(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            if (*(s8 *)(p + 0xB1) == 0) {
                *(s32 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 8) += *(s32 *)(p + 0x10);
            }
            *(u8 **)(p + 0x2A4) = func_0011f410((s32)arg0, (s32)func_003147d0(*(u8 **)(p + 0x148)), p + 0x28,
                                                func_00331660(), 0, (s32 *)D_00641AD0);
            p[1] = 0xA3;
        }
        break;
    case 0xCE:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            if (func_00303a20(arg0) == 1) {
                if (fclCombineHasSlotKind(arg0, 7) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 1;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBC;
                    }
                    func_00314670(*(u8 **)(p + 0x148), 9);
                } else if (fclCombineHasSlotKind(arg0, 0xD) == 1) {
                    p[1] = 0xA8;
                    p[0x22] = 0xA8;
                    p[0x13C] = 3;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBC;
                    }
                    func_00314670(*(u8 **)(p + 0x148), 9);
                } else if (fclCombineHasSlotKind(arg0, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j3 = 0; j3 < 6; j3++) {
                        q3 = *(s8 **)(arg0 + 0x38);
                        for (k3 = 0; k3 < q3[0x2DF]; k3++) {
                            if (q3[k3 + 0x2DA] == (s8)(j3 + 1)) {
                                found3 = 1;
                                goto checked3;
                            }
                        }
                        found3 = 0;
                    checked3:
                        if (found3 == 1) {
                            p[1] = 0xAC;
                            p[0x22] = 0xAC;
                            if (*(s8 *)(p + 0x21) == 0) {
                                p[1] = 0xBC;
                            }
                            func_00314670(*(u8 **)(p + 0x148), 9);
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(arg0, 9) == 1) {
                        p[1] = 0xB8;
                        p[0x22] = 0xB8;
                        if (*(s8 *)(p + 0x21) == 0) {
                            p[1] = 0xBC;
                        }
                        func_00314670(*(u8 **)(p + 0x148), 9);
                    }
                }
            }
        }
        break;
    case 0xA8:
        /* This retail state retains a counter-only traversal. */
        for (i1 = 0; i1 < 5; i1++) {
        }
        p[0xD] = func_002bab80((void *)func_00331660());
        for (i2 = 0; i2 < 0x20; i2++) {
            text[i2] = 0;
        }
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        func_002bbd80(*(s8 *)(p + 0xD), 0, text);
        func_002badc0(*(s8 *)(p + 0xD), 0x54);
        p[1] = 0xA9;
        break;
    case 0xA9:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            for (i3 = 0; i3 < 5; i3++) {
                list[i3] = 0;
            }
            p[0xD] = func_002bab80((void *)func_00331660());
            for (i4 = 0; i4 < 0x20; i4++) {
                name[i4] = 0;
                text[i4] = 0;
            }
            e = (u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            best = 0;
            top = e[0x1C];
            for (i5 = 1; i5 < 5; i5++) {
                if (top < e[i5 + 0x1C]) {
                    top = e[i5 + 0x1C];
                    best = i5;
                }
            }
            p[0x13D] = best;
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)D_00641B90[best]);
            func_00275980(text, name, 0x20);
            func_002bbd80(*(s8 *)(p + 0xD), 0, name);
            list[*(s8 *)(p + 0x13D)] = *(s8 *)(p + 0x13C);
            ((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x13D) + 0x1C] += (u8)p[0x13C];
            for (i6 = 0; i6 < 0x20; i6++) {
                name[i6] = 0;
                text[i6] = 0;
            }
            sprintf(text, &iGpffffa8a0, *(s8 *)(p + 0x13C));
            func_002bbd80(*(s8 *)(p + 0xD), 1, text);
            e = (u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            best = 0;
            top = e[0x1C];
            for (i7 = 1; i7 < 5; i7++) {
                if (e[i7 + 0x1C] < top) {
                    top = e[i7 + 0x1C];
                    best = i7;
                }
            }
            p[0x13E] = best;
            list[best] = *(s8 *)(p + 0x13C);
            ((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x13E) + 0x1C] += (u8)p[0x13C];
            func_0011b8f0(func_003147d0(*(u8 **)(p + 0x148)), list);
            p[0xB0] = 0;
            func_002badc0(*(s8 *)(p + 0xD), 0x3E);
            p[1] = 0xAA;
        }
        break;
    case 0xAA:
        *(s8 *)(p + 0xB0) = func_002b2cb0(*(s8 *)(p + 0xB0), 1, 0x14, 0, 1);
        if (*(s8 *)(p + 0xB0) == 0xF) {
            func_0045af60(1, 3, 3, 1);
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[0xD] = func_002bab80((void *)func_00331660());
            for (i8 = 0; i8 < 0x20; i8++) {
                name[i8] = 0;
                text[i8] = 0;
            }
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)D_00641B90[*(s8 *)(p + 0x13E)]);
            func_00275980(text, name, 0x20);
            func_002bbd80(*(s8 *)(p + 0xD), 0, name);
            for (i9 = 0; i9 < 0x20; i9++) {
                name[i9] = 0;
                text[i9] = 0;
            }
            sprintf(text, &iGpffffa8a0, *(s8 *)(p + 0x13C));
            func_002bbd80(*(s8 *)(p + 0xD), 1, text);
            func_002badc0(*(s8 *)(p + 0xD), 0x3E);
            p[1] = 0xAB;
            p[0xB0] = 0;
        }
        break;
    case 0xAB:
        *(s8 *)(p + 0xB0) = func_002b2cb0(*(s8 *)(p + 0xB0), 1, 0x14, 0, 1);
        if (*(s8 *)(p + 0xB0) == 0xF) {
            func_0045af60(1, 3, 3, 1);
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            if (func_00303a20(arg0) == 1) {
                if (fclCombineHasSlotKind(arg0, 0xA) == 1) {
                    p[1] = 0xB2;
                    p[0x22] = 0xB2;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                } else {
                    for (j4 = 0; j4 < 6; j4++) {
                        q4 = *(s8 **)(arg0 + 0x38);
                        for (k4 = 0; k4 < q4[0x2DF]; k4++) {
                            if (q4[k4 + 0x2DA] == (s8)(j4 + 1)) {
                                found4 = 1;
                                goto checked4;
                            }
                        }
                        found4 = 0;
                    checked4:
                        if (found4 == 1) {
                            p[1] = 0xAC;
                            return;
                        }
                    }
                    if (fclCombineHasSlotKind(arg0, 9) == 1) {
                        p[1] = 0xB8;
                    }
                }
            }
        }
        break;
    case 0xB2:
        row = D_0063FCA0 + *(s8 *)(p + 0x2D4) * 28;
        cal = (FclCombineSlot *)(D_006406F0 + (s8)func_00110a60(func_002e78a0(), (u8)func_002e78e0()) * 20);
        if (*(s8 *)(p + 0x2D4) == -1) {
            for (i10 = 0; i10 < 5; i10++) {
                if (*(s8 *)(p + i10 + 0x2DA) == 0xA) {
                    *(s16 *)(p + 0x1C) = cal[i10].item;
                    break;
                }
            }
        } else {
            for (i11 = 0; i11 < *(s8 *)(p + 0x2DF); i11++) {
                if (*(s8 *)(p + i11 + 0x2DA) == 0xA) {
                    *(s16 *)(p + 0x1C) = ((FclCombineSlot *)(row + 8))[i11].item;
                    break;
                }
            }
        }
        func_0011cdd0(func_003147d0(*(u8 **)(p + 0x148)), *(u16 *)(p + 0x1C));
        *(s16 *)(p + 0x2D8) = 0;
        p[1] = 0xB3;
        break;
    case 0xB3:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x14, 0, 1);
        if (*(s16 *)(p + 0x2D8) >= 0x14) {
            p[0xD] = func_002bab80((void *)func_00331660());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
            func_002bbd80(*(s8 *)(p + 0xD), 0, text);
            func_002badc0(*(s8 *)(p + 0xD), 0x51);
            p[1] = 0xB6;
        }
        break;
    case 0xB5:
        if (func_0011fcf0(*(u8 **)(p + 0x2A8)) == 1) {
            func_00452080((KwlnTask *)*(u8 **)(p + 0x2A8));
            *(u8 **)(p + 0x2A8) = 0;
            func_0011ce30(func_003147d0(*(u8 **)(p + 0x148)));
            p[1] = 0xBF;
            for (j5 = 0; j5 < 6; j5++) {
                q5 = *(s8 **)(arg0 + 0x38);
                for (k5 = 0; k5 < q5[0x2DF]; k5++) {
                    if (q5[k5 + 0x2DA] == (s8)(j5 + 1)) {
                        found5 = 1;
                        goto checked5;
                    }
                }
                found5 = 0;
            checked5:
                if (found5 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(arg0, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xB6:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            *(s16 *)(p + 0x2D8) = 0;
            p[1] = 0xB7;
            e = func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            {
                u16 selectedSkill;
                selectedSkill = *(u16 *)(p + 0x1C);
                if (func_0010ce10(e, selectedSkill) != -1) {
                    p[0xD] = func_002bab80((void *)func_00331660());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                    func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                    func_002badc0(*(s8 *)(p + 0xD), 0x52);
                    p[1] = 0xB4;
                } else if ((s32)func_0010ceb0(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA))) >= 8) {
                    p[1] = 0xB5;
                    *(u8 **)(p + 0x2A8) = func_0011fbc0((s32)arg0, func_003147d0(*(u8 **)(p + 0x148)), func_00331660(), D_00641AD0);
                }
            }
        }
        break;
    case 0xB4:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
            func_0011ce30(func_003147d0(*(u8 **)(p + 0x148)));
            for (j6 = 0; j6 < 6; j6++) {
                q6 = *(s8 **)(arg0 + 0x38);
                for (k6 = 0; k6 < q6[0x2DF]; k6++) {
                    if (q6[k6 + 0x2DA] == (s8)(j6 + 1)) {
                        found6 = 1;
                        goto checked6;
                    }
                }
                found6 = 0;
            checked6:
                if (found6 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(arg0, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xB7:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            {
                u8 *personaTask;
                u16 skill;
                personaTask = func_003147d0(*(u8 **)(p + 0x148));
                skill = *(u16 *)(p + 0x1C);
                func_0011cb70(personaTask, skill);
            }
            func_0011ce30(func_003147d0(*(u8 **)(p + 0x148)));
            func_0045af60(1, 3, 3, 2);
        } else if (*(s16 *)(p + 0x2D8) >= 0x28) {
            p[1] = 0xBF;
            for (j7 = 0; j7 < 6; j7++) {
                q7 = *(s8 **)(arg0 + 0x38);
                for (k7 = 0; k7 < q7[0x2DF]; k7++) {
                    if (q7[k7 + 0x2DA] == (s8)(j7 + 1)) {
                        found7 = 1;
                        goto checked7;
                    }
                }
                found7 = 0;
            checked7:
                if (found7 == 1) {
                    p[1] = 0xAC;
                    p[0x22] = 0xAC;
                    if (*(s8 *)(p + 0x21) == 0) {
                        p[1] = 0xBD;
                    }
                    return;
                }
            }
            if (fclCombineHasSlotKind(arg0, 9) == 1) {
                p[1] = 0xB8;
                p[0x22] = 0xB8;
                if (*(s8 *)(p + 0x21) == 0) {
                    p[1] = 0xBD;
                }
            }
        }
        break;
    case 0xAC:
        p[0x20] = 0;
        for (i12 = 0; i12 < *(s8 *)(p + 0x2DF); i12++) {
            if (*(s8 *)(p + i12 + 0x2DA) > 0 && *(s8 *)(p + i12 + 0x2DA) < 7) {
                slot = (s8 *)(p + 0x2DA) + i12;
                p[0x1F] = *(s8 *)(p + i12 + 0x2DA);
                *slot = 0;
                break;
            }
        }
        *(s16 *)(p + 0x1C) = func_003040d0(arg0, ((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[4], *(s8 *)(p + 0x1F));
        item = *(u16 *)(p + 0x1C);
        if (func_0010ce10((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
            p[0xD] = func_002bab80((void *)func_00331660());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
            func_002bbd80(*(s8 *)(p + 0xD), 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
            func_002bbd80(*(s8 *)(p + 0xD), 0, text);
        } else {
            kind = *(s8 *)(p + 0x1F);
            roll = func_002b2cb0(*(s8 *)(p + 0x1E), 1, 9, 0, 1);
            item = (u16)fclCombinePickItem(kind, roll);
            if (func_0010ce10((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
                p[0xD] = func_002bab80((void *)func_00331660());
                sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                func_002bbd80(*(s8 *)(p + 0xD), 1, text);
                sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
                func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                *(s16 *)(p + 0x1C) = item;
            } else {
                kind = *(s8 *)(p + 0x1F);
                roll = func_002b2d00(*(s8 *)(p + 0x1E), 1, 0, 9, 1);
                item = (u16)fclCombinePickItem(kind, roll);
                if (func_0010ce10((u8 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), fclItemHalf(&item)) == -1) {
                    p[0xD] = func_002bab80((void *)func_00331660());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    func_002bbd80(*(s8 *)(p + 0xD), 1, text);
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(item));
                    func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                    *(s16 *)(p + 0x1C) = item;
                } else {
                    p[0x20] = 1;
                    p[0xD] = func_002bab80((void *)func_00331660());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    func_002bbd80(*(s8 *)(p + 0xD), 1, text);
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                    func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                }
            }
        }
        func_0011cdd0(func_003147d0(*(u8 **)(p + 0x148)), *(u16 *)(p + 0x1C));
        p[1] = 0xB0;
        break;
    case 0xAD:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            if (*(s8 *)(p + 0x20) == 1) {
                for (j8 = 0; j8 < 8; j8++) {
                    if (((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[j8 + 6] != 0 &&
                        *(s16 *)(p + 0x1C) == ((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[j8 + 6]) {
                        p[0xD] = func_002bab80((void *)func_00331660());
                        sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                        func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                        func_002badc0(*(s8 *)(p + 0xD), 0x52);
                        p[1] = 0xAE;
                    }
                }
                if (p[1] != 0xAE) {
                    p[0xD] = func_002bab80((void *)func_00331660());
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
                    func_002bbd80(*(s8 *)(p + 0xD), 0, text);
                    sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
                    func_002bbd80(*(s8 *)(p + 0xD), 1, text);
                    func_002badc0(*(s8 *)(p + 0xD), 0x53);
                    p[1] = 0xAE;
                }
            } else {
                p[1] = 0xB1;
                *(s16 *)(p + 0x2D8) = 0;
                if ((s32)func_0010ceb0(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA))) >= 8) {
                    p[1] = 0xAF;
                    *(u8 **)(p + 0x2A8) = func_0011fbc0((s32)arg0, func_003147d0(*(u8 **)(p + 0x148)), func_00331660(), D_00641AD0);
                }
            }
        }
        break;
    case 0xAF:
        if (func_0011fcf0(*(u8 **)(p + 0x2A8)) == 1) {
            func_00452080((KwlnTask *)*(u8 **)(p + 0x2A8));
            *(u8 **)(p + 0x2A8) = 0;
            func_0011ce30(func_003147d0(*(u8 **)(p + 0x148)));
            for (i13 = 0; i13 < *(s8 *)(p + 0x2DF); i13++) {
                if (*(s8 *)(p + i13 + 0x2DA) > 0 && *(s8 *)(p + i13 + 0x2DA) < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
            if (fclCombineHasSlotKind(arg0, 9) == 1) {
                p[1] = 0xB8;
            }
        }
        break;
    case 0xB0:
        *(s16 *)(p + 0xE) = func_002b2cb0(*(s16 *)(p + 0xE), 1, 0x28, 0, 1);
        if (*(s16 *)(p + 0xE) >= 0x28) {
            p[1] = 0xAD;
            func_002badc0(*(s8 *)(p + 0xD), 0x51);
        }
        break;
    case 0xB1:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        if (*(s16 *)(p + 0x2D8) == 0xF) {
            {
                u8 *personaTask;
                u16 skill;
                personaTask = func_003147d0(*(u8 **)(p + 0x148));
                skill = *(u16 *)(p + 0x1C);
                func_0011cb70(personaTask, skill);
            }
            func_0045af60(1, 3, 3, 2);
        }
        if (*(s16 *)(p + 0x2D8) >= 0x28) {
            func_0011ce30(func_003147d0(*(u8 **)(p + 0x148)));
            for (i14 = 0; i14 < *(s8 *)(p + 0x2DF); i14++) {
                if (*(s8 *)(p + i14 + 0x2DA) > 0 && *(s8 *)(p + i14 + 0x2DA) < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
            if (fclCombineHasSlotKind(arg0, 9) == 1) {
                p[1] = 0xB8;
            }
        }
        break;
    case 0xAE:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            for (i15 = 0; i15 < *(s8 *)(p + 0x2DF); i15++) {
                if (*(s8 *)(p + i15 + 0x2DA) > 0 && *(s8 *)(p + i15 + 0x2DA) < 7) {
                    p[1] = 0xAC;
                    return;
                }
            }
            p[1] = 0xBF;
        }
        break;
    case 0xB8:
        p[0xD] = func_002bab80((void *)func_00331660());
        do {
            count = func_0010ceb0(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)));
            p[0x27] = RpRandom() % count;
        } while ((s16)func_00313690(((s16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x27) + 6]) == 0);
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x27) + 6]));
        *(s16 *)(p + 0x1C) = ((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)))[*(s8 *)(p + 0x27) + 6];
        func_002bbd80(*(s8 *)(p + 0xD), 0, text);
        func_002badc0(*(s8 *)(p + 0xD), 0x56);
        func_002bafc0(*(s8 *)(p + 0xD), 0);
        func_002bb0a0(*(s8 *)(p + 0xD), 0);
        func_002bbf60();
        p[1] = 0xB9;
        break;
    case 0xB9:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else if (func_002bb1c0(*(s8 *)(p + 0xD)) == 0) {
            func_002bb550(*(s8 *)(p + 0xD));
            func_002e4960((u8 *)&info, *(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA));
            *(s16 *)(p + 0x24) = func_00304410(info, *(s16 *)(p + 0x1C));
            *(s16 *)(p + 0x2D8) = 0;
            p[1] = 0xBA;
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
        }
        break;
    case 0xBA:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x28, 0, 1);
        if (*(s16 *)(p + 0x2D8) == 0x14) {
            {
                u8 *personaTask;
                u16 originalSkill;
                personaTask = func_003147d0(*(u8 **)(p + 0x148));
                originalSkill = *(u16 *)(p + 0x1C);
                func_0011cc00(personaTask, originalSkill, *(u16 *)(p + 0x24));
            }
            func_0010cd70(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)), *(s16 *)(p + 0x1C), *(u16 *)(p + 0x24));
            func_0045af60(1, 3, 3, 2);
        }
        if (*(s16 *)(p + 0x2D8) >= 0x28) {
            p[0xD] = func_002bab80((void *)func_00331660());
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x24)));
            func_002bbd80(*(s8 *)(p + 0xD), 1, text);
            sprintf(text, (const char *)&iGpffffa8a4, (const char *)func_00243840(*(u16 *)(p + 0x1C)));
            func_002bbd80(*(s8 *)(p + 0xD), 0, text);
            func_002badc0(*(s8 *)(p + 0xD), 0x57);
            p[1] = 0xBB;
        }
        break;
    case 0xBB:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[1] = 0xBF;
        }
        break;
    case 0xBC:
        p[0xD] = func_002bab80((void *)func_00331660());
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        func_002bbd80(*(s8 *)(p + 0xD), 0, text);
        func_002badc0(*(s8 *)(p + 0xD), 0x47);
        p[1] = 0xBE;
        break;
    case 0xBD:
        p[0xD] = func_002bab80((void *)func_00331660());
        sprintf(text, (const char *)&iGpffffa8a4, (const char *)iGpffffb440 + id * 0x11);
        func_002bbd80(*(s8 *)(p + 0xD), 0, text);
        func_002badc0(*(s8 *)(p + 0xD), 0x48);
        p[1] = 0xBE;
        break;
    case 0xBE:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            p[0x21] = 1;
            p[1] = p[0x22];
        }
        break;
    case 0xBF:
        *(s16 *)(p + 0x2D8) = 0;
        p[1] = 0xC0;
        /* fallthrough */
    case 0xC0:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0x3C, 0, 1);
        if (*(s16 *)(p + 0x2D8) >= 0x3C &&
            func_00314660(*(u8 **)(p + 0x148)) != 0xE) {
            func_00314670(*(u8 **)(p + 0x148), 0xB);
            pos.position = func_002b2970(0.0f, 0.0f);
            func_002b6c30(0x1E8, pos.position, 6.0f, 0xAA);
            func_002b68d0(0x1E8, 0, 0);
            func_002b6a70(0x1E8, 0xFF, 0, 0, 0x32, 0xA);
            p[1] = 0xC1;
        }
        break;
    case 0xC1:
        if (func_00314660(*(u8 **)(p + 0x148)) == 0xE) {
            func_00314400(*(u8 **)(p + 0x148), 1);
            p[0] = 0xE;
            p[1] = 0xD2;
        }
        break;
    }
}
#pragma pop
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
            func_0010b300(*(u16 *)((u16 *)func_002e48a0(*(s8 *)(work + 0x2F9), *(s8 *)(work + 0x2FA)) + 1));
            func_0010ad80(equippedId);
            break;
        }
        searchIndex++;
    }
    func_0010b7f0();
}
#pragma pop
/* MATCHED: struct colour copies straight into func_002b6150(...) + 0x85;
   func_00285b30 takes no argument and func_002b6b40 ends in two floats
   (0.0f, -360.0f); the second constructor coordinates for 0x20C are
   (f32)347 / (f32)267 (retail converts them with cvt.s.w). Stored bytes
   are re-read (*(s16 *)(p + 0x2D8), *(s8 *)(p + 0xD)) so b210 forwards
   them as retail does; the D_00640C50/C58/41660 pairs go through a named
   FclVec2f base; the table rows use the func_002ecfc0 offset spelling; the
   material switch keeps the 6 -> 5 -> 4 fallthrough labels (jump table);
   i is s8 and declared first, then cls, then p (saved-register order). */
// FUN_0030F650
void func_0030f650(u8 *arg0) {
    s8 i;
    s16 cls;
    u8 *p;
    u8 kind;
    s16 mats[12];
    FclVec2 w0;
    FclVec2 w1;
    FclVec2 w2;
    FclVec2 w3;
    FclVec2 w4;
    FclVec2 w5;
    FclVec2 w6;
    FclVec2 w7;
    FclVec2 w8;
    FclVec2 w9;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclVec2f *base;

    p = *(u8 **)(arg0 + 0x38);
    cls = *(s16 *)((u16 *)func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1);
    kind = *(p + 1);
    switch (kind) {
    case 0xD2:
        if (func_003145e0(*(s32 *)(p + 0x148)) == 1) {
            break;
        }
        *(p + 1) = 0xD3;
        *(s16 *)(p + 0x2D8) = 0;
    case 0xD3:
        *(s16 *)(p + 0x2D8) = func_002b2cb0(*(s16 *)(p + 0x2D8), 1, 0xF, 0, 1);
        if (*(s16 *)(p + 0x2D8) >= 0xF) {
            func_00106390(0x5F, 1);
            func_00106390(0x59, 0);
            func_00106390(0x5B, 0);
            *(p + 1) = 0xD4;
        }
        break;
    case 0xD4:
        if (func_00285b30() >= 0x2D0) {
            if (*((s8 *)func_0034a630(*(u8 **)(p + 0x254))) != 0) {
                *((s8 *)func_0034a630(*(u8 **)(p + 0x254))) = 4;
            }
            if (func_00105f50((u16)cls) > 0) {
                if (func_00452490(*(s32 *)(p + 0x308)) != 0) {
                    func_00452080((KwlnTask *)(u32)*(s32 *)(p + 0x308));
                    *(s32 *)(p + 0x308) = 0;
                }
            }
            *(p + 1) = 0xD5;
        }
        break;
    case 0xD5:
        if (datGetFlag(0x5B) != 0) {
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(s8 *)(p + 0xD), 0, iGpffffb440 + cls * 0x11);
            func_002badc0(*(s8 *)(p + 0xD), 0x49);
            *(p + 1) = 0xD6;
        }
        break;
    case 0xD6:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            *(p + 1) = 0xD7;
            func_00106390(0x59, 1);
        }
        break;
    case 0xD7:
        if (func_00452490(*(s32 *)(p + 0x300)) == 1) {
            break;
        }
        if (func_00452380(D_00641BB0) != 0) {
            func_00452080((KwlnTask *)(u32)*(s32 *)(p + 0x304));
            *(s32 *)(p + 0x304) = 0;
        }
        if (func_00459760() == -1) {
            func_0045a3e0(0x14, 1);
        }
        switch (*(s8 *)(p + 0x1A)) {
        case 2:
            mats[0] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            mats[1] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            break;
        case 3:
            mats[0] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            mats[1] = *(u16 *)((u16 *)func_002e48a0(0, *(s8 *)(p + 0x129)) + 1);
            mats[2] = *(u16 *)((u16 *)func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            break;
        case 6:
            mats[5] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 5) + 1);
        case 5:
            mats[4] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
        case 4:
            mats[0] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            mats[1] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            mats[2] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            mats[3] = *(u16 *)((u16 *)func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                mats[i] = *(u16 *)((u16 *)func_002e48a0(0, i) + 1);
            }
            break;
        }
        func_0030f4f0(arg0, mats);
        if (*(s32 *)(p + 0x304) != 0) {
            func_00452080((KwlnTask *)(u32)*(s32 *)(p + 0x304));
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
            w0 = func_002b2970(-78.0f, -82.0f);
            func_002b6c30(0x80, w0, 220.0f, 0x3F);
            c0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x80) + 0x85) = c0;
            func_002b6b40(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
            func_002b68d0(0x80, 6, 0);
            *(func_002b6150(0x80) + 0xDB) = 1;
            w1 = func_002b2970(2.0f, -2.0f);
            w2 = func_002b2970(-78.0f, -82.0f);
            func_002b69f0(0x80, w1, w2, 1, 0xA, 0);
            func_002b6a70(0x80, 0, 0xFF, 2, 0xA, 0);
            w3 = func_002b2970(540.0f, (f32)347);
            func_002b6c30(0x20C, w3, 220.0f, 0x3F);
            c1 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x20C) + 0x85) = c1;
            func_002b6b40(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
            func_002b68d0(0x20C, 6, 0);
            *(func_002b6150(0x20C) + 0xDB) = 1;
            w4 = func_002b2970(460.0f, (f32)267);
            w5 = func_002b2970(540.0f, (f32)347);
            func_002b69f0(0x20C, w4, w5, 1, 0xA, 0);
            func_002b6a70(0x20C, 0, 0xFF, 2, 0xA, 0);
            w6 = func_002b2970(-190.0f, 200.0f);
            func_002b6c30(0x81, w6, 215.0f, 0x56);
            c2 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x81) + 0x85) = c2;
            *(f32 *)(func_002b6150(0x81) + 0xD0) = 90.0f;
            base = (FclVec2f *)D_00640C50;
            w7 = func_002b2970(base->x, base->y);
            func_002b6c30(0x84, w7, 217.0f, 0x40);
            base = (FclVec2f *)D_00640C58;
            w8 = func_002b2970(base->x, base->y);
            func_002b6c30(0x85, w8, 218.0f, 0x40);
            func_00315600(arg0, 0);
            func_00316e80(arg0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
            base = (FclVec2f *)D_00641660;
            w9 = func_002b2970(base->x, base->y);
            func_002b6c30(0x1C6, w9, 242.0f, 0x3D);
            func_002b6a70(0x1C6, 0, 0x64, 0, 0xA, 0);
            *(s8 *)(p + 0xB4) = 0;
            *(s8 *)(p + 0xB5) = 0;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 1;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x23;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 0;
            *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 2;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x38;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 1;
            *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            if (datGetFlag(0x1301) != 0) {
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 3;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x51;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 2;
                *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            }
            if (datGetFlag(0x1302) != 0) {
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 4;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x51;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 3;
                *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            }
            if (datGetFlag(0x1303) != 0) {
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 5;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x51;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 4;
                *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            }
            if (datGetFlag(0x1304) != 0) {
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 6;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x63;
                *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 5;
                *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            }
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 7;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0x6E;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 6;
            *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 9;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0xC2;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 7;
            *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC4) = 0xB;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC6) = 0xD8;
            *(s16 *)((u8 *)(*(s8 *)(p + 0xB5) * 10) + (u32)p + 0xC8) = 8;
            *(s8 *)(p + 0xB5) = *(s8 *)(p + 0xB5) + 1;
            func_002eb270(arg0, 0);
            func_003205f0(arg0, 0x96, 0);
            *p = 0;
            *(p + 1) = 0x1A;
        }
        break;
    case 0x97:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
        } else {
            func_002bb550(*(s8 *)(p + 0xD));
            if (func_00302570(arg0) == 0) {
                *p = 0;
                *(p + 1) = 0x17;
            }
        }
        break;
    }
}

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
                if (func_0010ce10((u8 *)p, (u16)*(u32 *)(e + 8)) == -1) {
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
                if (datGetFlag(*(u32 *)(e + 4)) != 0) {
                    return 0;
                }
                break;
            }
            if (*(s16 *)(e + 8) == 1 && datGetFlag(*(u32 *)(e + 4)) == 0) {
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
    memset(iGpffffb594, 0, 0x3000);
    i = 0;
    while (i < 0x100) {
        if (func_0010fcb0(i) != 0) {
            j = (s16)i;
            memcpy(iGpffffb594 + (s32)j * 0x30, func_0010fcb0(j), 0x30);
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 0;
        if (datGetFlag((s16)i + 0x1309) != 0) {
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
/* measured: u16 class id, as its three callers pass it (raw lhu). With
   func_00109280(u16), the row index masks into a temp, as retail does. */
// FUN_00310A10
void func_00310a10(u8 *arg0, u16 arg1) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    s8 *t;
    s32 s0;
    s32 s4;
    s32 s3;
    u8 x;

    s0 = D_00749480[func_002e78a0() & 0xFF] * 100 + (func_002e78e0() & 0xFF);
    x = iGpffffb3d4[arg1 * 14 + 2];
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
        if (H_Cdvd_IsFileLoaded(*(u8 **)(p + 0x10)) != 0) {
            if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                if (datGetFlag(0x1459) == 0) {
                    func_00144c90(8, 3);
                    func_00144e10(1);
                }
                p[0] = 9;
                return 0;
            }
            if (datGetFlag(0x413) == 0 && datGetFlag(0x96F) != 0 && func_00104f10(1) >= 3) {
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
            if (datGetFlag(0x1459) == 0) {
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
            if (datGetFlag(0x1459) == 0) {
                K_View_SetFov(func_00457120(), func_0014b4d0());
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
    if (datGetFlag(0x1459) == 0) {
        func_00145080();
    }
    if (func_00452380(D_00641BC8) != 0) {
        func_003315a0();
    }
    H_Cdvd_Destroy(*(void **)(p + 0x10));
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
    result = (s32)func_00451fc0((void *)((void *)(result)), (const void *)(D_00641BE0), 0xF, 0, 0, func_00310bf0, func_003111d0, (u8 *)(p));
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
        datGetFlag(0x1DD) != 0 &&
        datGetFlag(0x1301) != 0 &&
        datGetFlag(0x1302) != 0 &&
        datGetFlag(0x1303) != 0) {
        func_00106390(0x1304, 1);
    }
    if (datGetFlag(0x1463) != 0) {
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
