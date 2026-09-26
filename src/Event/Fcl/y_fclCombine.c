#include "model_motion_internal.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "fcl_color.h"
#include "fcl_row_draw.h"
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

typedef FclVec2 FclVec2f;
extern void func_00313b50(u8 *task);
extern s32 func_0033e3f0(u8 *task);


extern void func_002b5e30(u8 *task, FclDrawColor color);
extern void func_002b5e20(u8 *task, f32 depth);
extern void func_002b6130(u8 *task, u32 order);
extern void func_002b6140(u8 *task, u8 hidden);
extern void func_002b6120(u8 *task, u8 mode);
extern u16 *func_001102e0(void);
extern s32 datGetFlag(s32);
extern void func_00145080(void);
extern s32 func_00452380(void *);
extern void func_003315a0(void);
extern void H_Cdvd_Destroy(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern u32 RpRandom(void);
extern s8 D_007490F8[];
extern u16 *func_0010ace0(s16);
extern s32 func_0010b6f0(void);
extern u8 func_00109280(u16);
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
extern void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern void func_0045aac0(s32, s32, s32);
extern s32 func_00110460(void);
extern void func_00105690(s32, s32);
extern void func_00105fa0(s32);
extern u8 *func_0010b010(u16 personaId);
extern void func_002b68d0(s16, s32, s32);
extern void func_00324f80(u8 *arg0, s64, s32, s32);
extern void func_00330060(u8 *arg0, s32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u16 D_008C024E[];
extern f32 D_00640D78[];
extern void func_00106390(s32, s32);
extern void func_0044ea90(const void *, s32);
extern void memset(void *, s32, u32);
extern void *memcpy(void *, void *, u32);
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
extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
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
extern s8 *func_0034a630(s32);
extern s8 func_00105f50(u16);
extern s32 func_00452490(s32);
extern void func_00452080(s32);
extern s32 func_00459760(void);
extern void func_0045a3e0(s32, s32);
extern void func_0030f4f0(u8 *, s16 *);
extern s32 func_00314320(u8 *);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
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
    FclVec2 v0;
    FclVec2 v1;
    FclVec2 v2;
    FclVec2 v3;
    FclVec2 v4;
    FclVec2 v5;
    FclVec2 v6;
    FclVec2 v7;
    FclVec2 v8;
    FclVec2 v9;
    FclDrawColor menuColor;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    FclBoundsPacket b0;
    FclBoundsPacket b1;
    FclBoundsPacket b2;
    FclBoundsPacket b3;
    FclBoundsPacket b4;
    u8 *e;
    extern s32 func_00331560(void);

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
    func_002b7750(0x2DC, (s16)((func_002e78e0() / 10) + 9));
    func_002b7750(0x2DD, (s16)((func_002e78e0() % 10) + 9));
    func_002b7750(0x22A, 0x193);
    func_002b7750(0x2DE, 0x126);
    func_002b7750(0x2DE, 0x125);
    for (k = 0; k < 0xC; k++) {
        func_002b7750((s16)(k + 0x2FB), 0x131);
        *(s32 *)(out + k * 4 + 0x258) = func_002b8150(task);
    }
    func_002b2970((u8 *)&v0, 288.0f, 14.0f);
    *(s32 *)(out + 0x28C) = (s32)func_002b5c90(task, v0);
    func_002b2970((u8 *)&v1, 288.0f, 14.0f);
    func_002b29e0((u8 *)&b0, 160.0f, 36.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x28C), v1, &b0);
    func_002b6130((u8 *)(*(s32 *)(out + 0x28C)), 0xAB);
    func_002b6140((u8 *)(*(s32 *)(out + 0x28C)), 0);
    c0 = func_002b2a60(0xFF, 0xFF, 0xFF, 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x28C), c0);
    func_002b5e20((u8 *)(*(s32 *)(out + 0x28C)), 53.0f);
    func_002b2970((u8 *)&v2, 0.0f, 14.0f);
    *(s32 *)(out + 0x290) = (s32)func_002b5c90(task, v2);
    func_002b2970((u8 *)&v3, 0.0f, 14.0f);
    func_002b29e0((u8 *)&b1, 26.0f, 36.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x290), v3, &b1);
    func_002b6130((u8 *)(*(s32 *)(out + 0x290)), 0xAB);
    func_002b6140((u8 *)(*(s32 *)(out + 0x290)), 0);
    c1 = func_002b2a60(0xFF, 0xFF, 0xFF, 0);
    func_002b5e30((u8 *)*(s32 *)(out + 0x290), c1);
    func_002b5e20((u8 *)(*(s32 *)(out + 0x290)), 53.0f);
    func_002b2970((u8 *)&v4, 0.0f, 0.0f);
    *(s32 *)(out + 0x2AC) = (s32)func_002b5c90(task, v4);
    func_002b2970((u8 *)&v5, 0.0f, 0.0f);
    func_002b29e0((u8 *)&b2, 640.0f, 7.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2AC), v5, &b2);
    func_002b6130((u8 *)(*(s32 *)(out + 0x2AC)), 0xB2);
    c2 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2AC), c2);
    func_002b6140((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    func_002b6120((u8 *)(*(s32 *)(out + 0x2AC)), 1);
    func_002b2970((u8 *)&v6, 0.0f, 432.0f);
    *(s32 *)(out + 0x2B0) = (s32)func_002b5c90(task, v6);
    func_002b2970((u8 *)&v7, 0.0f, 432.0f);
    func_002b29e0((u8 *)&b3, 640.0f, 16.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B0), v7, &b3);
    func_002b6130((u8 *)(*(s32 *)(out + 0x2B0)), 0xB2);
    c3 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B0), c3);
    func_002b6140((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    func_002b6120((u8 *)(*(s32 *)(out + 0x2B0)), 1);
    func_002b2970((u8 *)&v8, 0.0f, 69.0f);
    *(s32 *)(out + 0x2B4) = (s32)func_002b5c90(task, v8);
    func_002b2970((u8 *)&v9, 0.0f, 69.0f);
    func_002b29e0((u8 *)&b4, 640.0f, 343.0f);
    func_002b5db0((u8 *)*(s32 *)(out + 0x2B4), v9, &b4);
    func_002b6130((u8 *)(*(s32 *)(out + 0x2B4)), 0xB2);
    c4 = func_002b2a60(0x2D, 0x2D, 0x2D, 0xE5);
    func_002b5e30((u8 *)*(s32 *)(out + 0x2B4), c4);
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
    extern char iGpffffa8a0;
    extern s32 func_00106330(s32);
    extern void func_00442088(char *, const char *, s32);
    extern s32 func_0033e5a0(u8 *);
    extern void func_00315310(u8 *, s64);
    extern void func_002b6b40(s16, u8, s16, s32, f32, f32);
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s16);
    extern s32 func_003190d0(u8 *);
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
    FclPackedPosition pos0;
    FclPackedPosition pos1;
    FclPackedPosition pos2;
    FclPackedPosition pos3;
    FclPackedPosition pos4;
    FclPackedPosition pos5;
    FclPackedPosition pos6;
    FclPackedPosition pos7;
    FclPackedPosition pos8;
    FclPackedPosition pos9;
    FclPackedPosition pos10;
    FclPackedPosition pos11;
    FclPackedPosition pos12;
    FclPackedPosition pos13;
    FclPackedPosition pos14;
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
            func_00442088(text, &iGpffffa8a0, *(s8 *)entry);
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
        func_002b2970((u8 *)&pos0, -78.0f, -82.0f);
        func_002b6c30(0x80, pos0.position, 220.0f, 0x3F);
        color0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x80) + 0x85) = color0;
        func_002b6b40(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
        func_002b68d0(0x80, 6, 0);
        func_002b6150(0x80)[0xDB] = 1;
        func_002b2970((u8 *)&pos1, 2.0f, -2.0f);
        func_002b2970((u8 *)&pos2, -78.0f, -82.0f);
        func_002b69f0(0x80, pos1.position, pos2.position, 1, 0xA, 0);
        func_002b6a70(0x80, 0, 0xFF, 2, 0xA, 0);
        func_002b2970((u8 *)&pos3, 540.0f, (f32)0x15B);
        func_002b6c30(0x20C, pos3.position, 220.0f, 0x3F);
        color1 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x20C) + 0x85) = color1;
        func_002b6b40(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
        func_002b68d0(0x20C, 6, 0);
        func_002b6150(0x20C)[0xDB] = 1;
        func_002b2970((u8 *)&pos4, 460.0f, (f32)0x10B);
        func_002b2970((u8 *)&pos5, 540.0f, (f32)0x15B);
        func_002b69f0(0x20C, pos4.position, pos5.position, 1, 0xA, 0);
        func_002b6a70(0x20C, 0, 0xFF, 2, 0xA, 0);
        func_002b2970((u8 *)&pos6, -190.0f, 200.0f);
        func_002b6c30(0x81, pos6.position, 215.0f, 0x56);
        color2 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
        *(FclDrawColor *)(func_002b6150(0x81) + 0x85) = color2;
        func_002b6a70(0x81, 0, 0xFF, 0, 0xA, 0);
        *(f32 *)(func_002b6150(0x81) + 0xD0) = 90.0f;
        vec = (FclVec2 *)D_00640C50;
        func_002b2970((u8 *)&pos7, vec->x, vec->y);
        func_002b6c30(0x84, pos7.position, 217.0f, 0x40);
        func_002b6a70(0x84, 0, 0xFF, 0, 0xA, 0);
        vec = (FclVec2 *)D_00640C58;
        func_002b2970((u8 *)&pos8, vec->x, vec->y);
        func_002b6c30(0x85, pos8.position, 218.0f, 0x40);
        func_002b6a70(0x85, 0, 0xFF, 0, 0xA, 0);
        func_00315600(arg0, 0);
        func_003205f0(arg0, 0x92, 0);
        func_00316e80((s32)arg0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
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
                func_002b2970((u8 *)&pos9, 26.0f, (f32)(n * 34 + 87));
                func_003147e0(arg0, n, pos9.position, *(s16 *)(p + off + 0xB8), (s16)off, 1);
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
                    func_002b2970((u8 *)&pos10, vec->x, vec->y);
                    func_002b6c30(0x1C6, pos10.position, 242.0f, 0x3D);
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
                func_00316e80((s32)arg0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
                func_002b6a70(0x81, 0xFF, 0, 0, 6, 0);
                func_002b6a70(0x80, 0xFF, 0, 2, 0xA, 0);
                func_002b6a70(0x20C, 0xFF, 0, 2, 0xA, 0);
                func_002b6a70(0x84, 0xFF, 0, 0, 6, 0);
                func_002b6a70(0x85, 0xFF, 0, 0, 6, 0);
                for (n = 0; n < 3; n++) {
                    func_002b2970((u8 *)&pos11, 26.0f, (f32)(n * 34 + 87));
                    func_003147e0(arg0, n, pos11.position, *(s16 *)(p + n * 2 + 0xB8), 0, 1);
                }
                p[1] = 0x19;
                break;
            }
        } else if (buttons & 0x20) {
            func_00315600(arg0, 1);
            func_00320970(arg0, 1);
            func_003205f0(arg0, 0, 0x92);
            func_00316e80((s32)arg0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
            func_002b6a70(0x81, 0xFF, 0, 0, 6, 0);
            func_002b6a70(0x80, 0xFF, 0, 2, 0xA, 0);
            func_002b6a70(0x20C, 0xFF, 0, 2, 0xA, 0);
            func_002b6a70(0x84, 0xFF, 0, 0, 6, 0);
            func_002b6a70(0x85, 0xFF, 0, 0, 6, 0);
            for (n = 0; n < 3; n++) {
                func_002b2970((u8 *)&pos12, 26.0f, (f32)(n * 34 + 87));
                func_003147e0(arg0, n, pos12.position, *(s16 *)(p + n * 2 + 0xB8), 0, 1);
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
        func_002b2970((u8 *)&pos13, vec->x, vec->y);
        func_002b6c30(0x1C6, pos13.position, 242.0f, 0x3D);
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
            func_002b2970((u8 *)&pos14, 26.0f, (f32)(j * 34 + 87));
            func_003147e0(arg0, j + 4, pos14.position, *(s16 *)(p + off + 0xB8), (s16)off, 0);
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
                    func_002b2970((u8 *)&stk[69], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_002b2970((u8 *)&stk[68], (*( f32 * )((u8 *)(temp_16) + (0))), (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_00317900(arg0, stk[69], stk[68], (var_18), ((temp_20_2 * 4)), ((((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57)));
                    temp_4_2 = (u8 *)(temp_19 + (temp_20_2 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_2) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_2) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57);
                } else {
                    temp_22 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[67], (*( f32 * )((u8 *)(temp_16) + (0))), (*( f32 * )((u8 *)(temp_16) + (4))));
                    func_002b2970((u8 *)&stk[66], -300.0f, (*( f32 * )((u8 *)(temp_16) + (4))) + (f32) temp_22);
                    func_00317900(arg0, stk[67], stk[66], (var_18), ((temp_20 * 2)), ((((*( s16 * )((u8 *)(temp_16) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16) + (0xA))) + 0x57)));
                }
                var_18 = ((var_18 + 1));
                goto loop_10;
            }
            if (temp_17 == 0) {
                func_002b2970((u8 *)&stk[65], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_002b2970((u8 *)&stk[64], (*( f32 * )((u8 *)(&D_006407A8) + (0))), (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_00317900(arg0, stk[65], stk[64], 8, 2, ((((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xFC))) = (s16) (((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xFE))) = (s16) ((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57);
            } else {
                temp_16_2 = (((RpRandom() % 300U) - 0x96));
                func_002b2970((u8 *)&stk[63], (*( f32 * )((u8 *)(&D_006407A8) + (0))), (*( f32 * )((u8 *)(&D_006407A8) + (4))));
                func_002b2970((u8 *)&stk[62], 700.0f, (*( f32 * )((u8 *)(&D_006407A8) + (4))) + (f32) temp_16_2);
                func_00317900(arg0, stk[63], stk[62], 8, 1, ((((*( s16 * )((u8 *)(&D_006407A8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407A8) + (0xA))) + 0x57)));
            }
            if (temp_17 == 0) {
                func_002b2970((u8 *)&stk[61], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_002b2970((u8 *)&stk[60], (*( f32 * )((u8 *)(&D_0064079C) + (0))), (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_00317900(arg0, stk[61], stk[60], 7, 6, ((((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57);
            } else {
                temp_18 = (((RpRandom() % 300U) - 0x96));
                func_002b2970((u8 *)&stk[59], (*( f32 * )((u8 *)(&D_0064079C) + (0))), (*( f32 * )((u8 *)(&D_0064079C) + (4))));
                func_002b2970((u8 *)&stk[58], 700.0f, (*( f32 * )((u8 *)(&D_0064079C) + (4))) + (f32) temp_18);
                func_00317900(arg0, stk[59], stk[58], 7, 3, ((((*( s16 * )((u8 *)(&D_0064079C) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_0064079C) + (0xA))) + 0x57)));
            }
            if (temp_17 == 0) {
                func_002b2970((u8 *)&stk[57], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970((u8 *)&stk[56], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_00317900(arg0, stk[57], stk[56], 6, 0xA, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xE8))) = (s16) (((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xEA))) = (s16) ((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57);
            } else {
                temp_17_2 = (((RpRandom() % 300U) - 0x96));
                func_002b2970((u8 *)&stk[55], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970((u8 *)&stk[54], 700.0f, (*( f32 * )((u8 *)(&D_00640790) + (4))) + (f32) temp_17_2);
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
                    func_002b2970((u8 *)&stk[53], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_002b2970((u8 *)&stk[52], (*( f32 * )((u8 *)(temp_17_3) + (0))), (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_00317900(arg0, stk[53], stk[52], (var_18_2), ((temp_20_4 * 4)), ((((*( s16 * )((u8 *)(temp_17_3) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_3) + (0xA))) + 0x57)));
                    temp_4_3 = (u8 *)(temp_19 + (temp_20_4 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_3) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_3) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_3) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_3) + (0xA))) + 0x57);
                } else {
                    temp_22_2 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[51], (*( f32 * )((u8 *)(temp_17_3) + (0))), (*( f32 * )((u8 *)(temp_17_3) + (4))));
                    func_002b2970((u8 *)&stk[50], -300.0f, (*( f32 * )((u8 *)(temp_17_3) + (4))) + (f32) temp_22_2);
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
                    func_002b2970((u8 *)&stk[49], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_002b2970((u8 *)&stk[48], (*( f32 * )((u8 *)(temp_17_4) + (0))), (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_00317900(arg0, stk[49], stk[48], ((8 - temp_20_5)), (((temp_20_5 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57)));
                    temp_4_4 = (u8 *)(temp_19 + ((7 - temp_20_5) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_4) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_4) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57);
                } else {
                    temp_22_3 = (((RpRandom() % 300U) - 0x96));
                    temp_20_6 = (var_18_3);
                    func_002b2970((u8 *)&stk[47], (*( f32 * )((u8 *)(temp_17_4) + (0))), (*( f32 * )((u8 *)(temp_17_4) + (4))));
                    func_002b2970((u8 *)&stk[46], 700.0f, (*( f32 * )((u8 *)(temp_17_4) + (4))) + (f32) temp_22_3);
                    func_00317900(arg0, stk[47], stk[46], ((8 - temp_20_6)), (((temp_20_6 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_17_4) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_4) + (0xA))) + 0x57)));
                }
                var_18_3 = ((var_18_3 + 1));
                goto loop_32;
            }
            if (temp_16_3 == 0) {
                func_002b2970((u8 *)&stk[45], 700.0f, 100.0f + (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970((u8 *)&stk[44], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_00317900(arg0, stk[45], stk[44], 4, 0xE, ((((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_00640790) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_00640790) + (0xA))) + 0x57);
            } else {
                temp_16_4 = (((RpRandom() % 300U) - 0x96));
                func_002b2970((u8 *)&stk[43], (*( f32 * )((u8 *)(&D_00640790) + (0))), (*( f32 * )((u8 *)(&D_00640790) + (4))));
                func_002b2970((u8 *)&stk[42], 700.0f, (*( f32 * )((u8 *)(&D_00640790) + (4))) + (f32) temp_16_4);
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
                    func_002b2970((u8 *)&stk[41], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_002b2970((u8 *)&stk[40], (*( f32 * )((u8 *)(temp_17_5) + (0))), (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_00317900(arg0, stk[41], stk[40], (var_20), ((temp_22_4 * 4)), ((((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57)));
                    temp_4_5 = (u8 *)(temp_19 + (temp_22_4 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_5) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_5) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57);
                } else {
                    temp_22_5 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[39], (*( f32 * )((u8 *)(temp_17_5) + (0))), (*( f32 * )((u8 *)(temp_17_5) + (4))));
                    func_002b2970((u8 *)&stk[38], -300.0f, (*( f32 * )((u8 *)(temp_17_5) + (4))) + (f32) temp_22_5);
                    func_00317900(arg0, stk[39], stk[38], (var_20), ((temp_16_5 * 2)), ((((*( s16 * )((u8 *)(temp_17_5) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_5) + (0xA))) + 0x57)));
                }
                temp_16_6 = (u8 *)(D_006407C0 + ((6 - temp_16_5) * 0xC));
                if (temp_18_2 == 0) {
                    temp_17_6 = (var_20);
                    func_002b2970((u8 *)&stk[37], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_002b2970((u8 *)&stk[36], (*( f32 * )((u8 *)(temp_16_6) + (0))), (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_00317900(arg0, stk[37], stk[36], ((8 - temp_17_6)), (((temp_17_6 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57)));
                    temp_4_6 = (u8 *)(temp_19 + ((4 - temp_17_6) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_6) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_6) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57);
                } else {
                    temp_22_6 = (((RpRandom() % 300U) - 0x96));
                    temp_17_7 = (var_20);
                    func_002b2970((u8 *)&stk[35], (*( f32 * )((u8 *)(temp_16_6) + (0))), (*( f32 * )((u8 *)(temp_16_6) + (4))));
                    func_002b2970((u8 *)&stk[34], 700.0f, (*( f32 * )((u8 *)(temp_16_6) + (4))) + (f32) temp_22_6);
                    func_00317900(arg0, stk[35], stk[34], ((8 - temp_17_7)), (((temp_17_7 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_16_6) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_6) + (0xA))) + 0x57)));
                }
                var_20 = ((var_20 + 1));
                goto loop_45;
            }
            if (temp_18_2 == 0) {
                func_002b2970((u8 *)&stk[33], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970((u8 *)&stk[32], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[33], stk[32], 6, 8, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xDE))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xE0))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_7 = (((RpRandom() % 300U) - 0x96));
                if ((u32) (RpRandom() % 100U) >= 0x32U) {
                    func_002b2970((u8 *)&stk[31], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[30], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_7);
                    func_00317900(arg0, stk[31], stk[30], 6, 4, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970((u8 *)&stk[29], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[28], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_7);
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
                    func_002b2970((u8 *)&stk[27], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_002b2970((u8 *)&stk[26], (*( f32 * )((u8 *)(temp_17_8) + (0))), (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_00317900(arg0, stk[27], stk[26], (var_20_2), ((temp_22_7 * 4)), ((((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57)));
                    temp_4_7 = (u8 *)(temp_19 + (temp_22_7 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_7) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_7) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57);
                } else {
                    temp_22_8 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[25], (*( f32 * )((u8 *)(temp_17_8) + (0))), (*( f32 * )((u8 *)(temp_17_8) + (4))));
                    func_002b2970((u8 *)&stk[24], -300.0f, (*( f32 * )((u8 *)(temp_17_8) + (4))) + (f32) temp_22_8);
                    func_00317900(arg0, stk[25], stk[24], (var_20_2), ((temp_16_8 * 2)), ((((*( s16 * )((u8 *)(temp_17_8) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_8) + (0xA))) + 0x57)));
                }
                temp_16_9 = (u8 *)(D_006407C0 + ((7 - temp_16_8) * 0xC));
                if (temp_18_3 == 0) {
                    temp_17_9 = (var_20_2);
                    func_002b2970((u8 *)&stk[23], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_002b2970((u8 *)&stk[22], (*( f32 * )((u8 *)(temp_16_9) + (0))), (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_00317900(arg0, stk[23], stk[22], ((8 - temp_17_9)), (((temp_17_9 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57)));
                    temp_4_8 = (u8 *)(temp_19 + ((6 - temp_17_9) * 0xA));
                    (*( s16 * )((u8 *)(temp_4_8) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_8) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57);
                } else {
                    temp_22_9 = (((RpRandom() % 300U) - 0x96));
                    temp_17_10 = (var_20_2);
                    func_002b2970((u8 *)&stk[21], (*( f32 * )((u8 *)(temp_16_9) + (0))), (*( f32 * )((u8 *)(temp_16_9) + (4))));
                    func_002b2970((u8 *)&stk[20], 700.0f, (*( f32 * )((u8 *)(temp_16_9) + (4))) + (f32) temp_22_9);
                    func_00317900(arg0, stk[21], stk[20], ((8 - temp_17_10)), (((temp_17_10 * 2) + 1)), ((((*( s16 * )((u8 *)(temp_16_9) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_16_9) + (0xA))) + 0x57)));
                }
                var_20_2 = ((var_20_2 + 1));
                goto loop_60;
            }
            if (temp_18_3 == 0) {
                func_002b2970((u8 *)&stk[19], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970((u8 *)&stk[18], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[19], stk[18], 3, 0xC, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xE8))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xEA))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_10 = (((RpRandom() % 300U) - 0x96));
                if ((u32) (RpRandom() % 100U) >= 0x32U) {
                    func_002b2970((u8 *)&stk[17], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[16], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_10);
                    func_00317900(arg0, stk[17], stk[16], 3, 6, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970((u8 *)&stk[15], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[14], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_10);
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
                    func_002b2970((u8 *)&stk[13], -200.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_002b2970((u8 *)&stk[12], (*( f32 * )((u8 *)(temp_17_11) + (0))), (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_00317900(arg0, stk[13], stk[12], (var_20_3), ((temp_22_10 * 4)), ((((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57)));
                    temp_4_9 = (u8 *)(temp_19 + (temp_22_10 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_9) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_9) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57);
                } else {
                    temp_22_11 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[11], (*( f32 * )((u8 *)(temp_17_11) + (0))), (*( f32 * )((u8 *)(temp_17_11) + (4))));
                    func_002b2970((u8 *)&stk[10], -300.0f, (*( f32 * )((u8 *)(temp_17_11) + (4))) + (f32) temp_22_11);
                    func_00317900(arg0, stk[11], stk[10], (var_20_3), ((temp_16_11 * 2)), ((((*( s16 * )((u8 *)(temp_17_11) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_11) + (0xA))) + 0x57)));
                }
                temp_16_12 = 8 - temp_16_11;
                temp_17_12 = (u8 *)(D_006407C0 + (temp_16_12 * 0xC));
                if (temp_18_4 == 0) {
                    temp_22_12 = (var_20_3);
                    temp_16_13 = 8 - temp_22_12;
                    func_002b2970((u8 *)&stk[9], 700.0f, 100.0f + (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_002b2970((u8 *)&stk[8], (*( f32 * )((u8 *)(temp_17_12) + (0))), (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_00317900(arg0, stk[9], stk[8], (temp_16_13), (((temp_22_12 * 4) + 2)), ((((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57)));
                    temp_4_10 = (u8 *)(temp_19 + (temp_16_13 * 0xA));
                    (*( s16 * )((u8 *)(temp_4_10) + (0xCA))) = (s16) (((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E);
                    (*( s16 * )((u8 *)(temp_4_10) + (0xCC))) = (s16) ((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57);
                } else {
                    temp_22_13 = (((RpRandom() % 300U) - 0x96));
                    func_002b2970((u8 *)&stk[7], (*( f32 * )((u8 *)(temp_17_12) + (0))), (*( f32 * )((u8 *)(temp_17_12) + (4))));
                    func_002b2970((u8 *)&stk[6], 700.0f, (*( f32 * )((u8 *)(temp_17_12) + (4))) + (f32) temp_22_13);
                    func_00317900(arg0, stk[7], stk[6], (temp_16_12), (((((s64) (var_20_3)) * 2) + 1) << 0x30) >> 0x30, ((((*( s16 * )((u8 *)(temp_17_12) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(temp_17_12) + (0xA))) + 0x57)));
                }
                var_20_3 = ((var_20_3 + 1));
                goto loop_75;
            }
            if (temp_18_4 == 0) {
                func_002b2970((u8 *)&stk[5], -200.0f, 100.0f + (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_002b2970((u8 *)&stk[4], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                func_00317900(arg0, stk[5], stk[4], 4, 0x10, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                (*( s16 * )((u8 *)(temp_19) + (0xF2))) = (s16) (((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E);
                (*( s16 * )((u8 *)(temp_19) + (0xF4))) = (s16) ((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57);
            } else {
                temp_16_14 = (((RpRandom() % 300U) - 0x96));
                if ((u32) (RpRandom() % 100U) >= 0x32U) {
                    func_002b2970((u8 *)&stk[3], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[2], -300.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_14);
                    func_00317900(arg0, stk[3], stk[2], 4, 8, ((((*( s16 * )((u8 *)(&D_006407F0) + (8))) * 3) + 0x3E)), (((*( s16 * )((u8 *)(&D_006407F0) + (0xA))) + 0x57)));
                } else {
                    func_002b2970((u8 *)&stk[1], (*( f32 * )((u8 *)(&D_006407F0) + (0))), (*( f32 * )((u8 *)(&D_006407F0) + (4))));
                    func_002b2970((u8 *)&stk[0], 700.0f, (*( f32 * )((u8 *)(&D_006407F0) + (4))) + (f32) temp_16_14);
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
    FclPackedPosition sp38;
    u8 *temp_16;
    FclVec2f *base;

    temp_16 = *(u8 **)(arg0 + 0x38);
    base = (FclVec2f *)D_00641660;
    func_002b2970((u8 *)&sp38, base->x, base->y);
    func_002b6c30(0x1C6, sp38.position, 242.0f, 0x3D);
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
    extern s32 func_00104c70(s32);
    extern s32 func_0010b5b0(void);
    extern void func_0010cc20(u8 *, u16);
    extern s32 func_0010ce10(u8 *, u16);
    extern u32 func_0010ceb0(void *);
    extern s32 datGetFlag(s32);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern void func_0011d140(u8 *, s32);
    extern s32 func_0011c610(u8 *);
    extern s32 func_00122720(void);
    extern void func_00122520(s32, s32);
    extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern void func_002b2970(void *, f32, f32);
    extern void func_002b68d0(s16, s32, s32);
    extern u8 *func_002b6150(s16);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern s32 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002bb680(s8);
    extern void func_002e4610(s32, s8);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern s32 func_002e53b0(s32, s32);
    extern void func_002e5ae0(s32, void *, s64);
    extern void func_002e6280(s32, void *, s64);
    extern s64 func_00247770(s32);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern void func_002ba970(s32, s8, s32);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00310a10(u8 *, u16);
    extern s32 func_00311930(s32, u8 *, s8);
    extern s32 func_00312bc0(s32);
    extern void func_00313800(s8);
    extern void func_00314670(u8 *, s8);
    extern void func_00314680(u8 *);
    extern void func_003146f0(u8 *, u16 *, s8);
    extern s8 func_00314660(u8 *);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_003144d0(u8 *, u16 *, s8, s32, s32);
    extern void func_00315600(u8 *, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00317240(u8 *, s32, f32);
    extern s32 func_003190d0(u8 *);
    extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s8, u16, u8, s32, s32, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00321e60(u8 *, s32, s32, s32);
    extern void func_00324410(u8 *, s32, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern u32 RpRandom(void);
    extern void memset(void *, s32, u32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern f32 D_00640C10[];
    extern f32 D_00640E70[];
    extern u8 D_00795E60[];
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
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
    FclVec2f sp158;
    FclVec2f sp150;
    FclVec2f sp148;
    FclVec2f sp140;
    FclVec2f sp138;
    u16 sp110[16];
    u16 spF0[16];
    u8 spE0;
    s32 spD0;
    s32 var_16_4;
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
    u16 temp_16_11;
    u16 temp_16_15;
    u16 temp_16_41;
    u16 temp_16_42;
    u16 temp_16_43;
    u16 temp_16_47;
    u16 temp_16_49;
    u16 temp_16_53;
    u16 temp_16_6;
    u16 temp_16_9;
    u16 temp_19;
    u16 temp_19_2;
    u16 temp_19_3;
    u16 temp_19_4;
    u16 temp_19_8;
    u32 temp_16_44;
    u32 temp_16_45;
    u8 temp_16_10;
    u8 temp_16_16;
    u8 temp_16_17;
    s32 temp_16_22;
    s32 temp_16_27;
    s32 temp_16_34;
    u8 temp_16_38;
    u8 temp_16_3;
    u8 temp_16_40;
    u8 temp_16_50;
    s32 temp_16_51;
    u8 temp_16_7;
    s32 temp_17_13;
    u8 temp_17_2;
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
    s8 partyCount;
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
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
                func_00275820(113.0f, temp_f20, 43.0f, var_17, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, var_19)[1] * 0x11), 0, 0, D_00795E60, 0x15);
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
            func_00314450(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0);
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
                func_002b2970(&sp228, 16.0f, 128.0f);
                temp_19 = func_002e48a0(0, var_16_2)[1];
                temp_17_2 = *(u8 *)((u8 *)func_002e48a0(0, var_16_2) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp228, var_16_2, temp_19, temp_17_2, 0, 0, partyCount);
            }
            func_002b2970(&sp220, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp220, 0, 0, 0, 0, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
        func_00275820(111.0f + sp158.x, sp158.y, 43.0f, temp_16_4, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, temp_17_3->f128)[1] * 0x11), 0, 0, D_00795E60, 0x15);
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
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col250);
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
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col244);
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
                    func_002ba970(temp_18->f2BC, var_19_2 + 0xC, *(s32 *)&col234);
                    var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, spE0);
                }
                temp_f20_2 = (f32)(var_19_2 * 0x17 + 0x80);
                func_00275820((f32)0x195, temp_f20_2, 43.0f, var_21, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(temp_18->f128 + 1, var_19_2)[1] * 0x11), 0, 0, D_00795E60, 0x15);
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
                        func_002b2970(&sp218, (f32)0x149, 128.0f);
                        temp_16_6 = func_002e48a0(temp_18->f128 + 1, var_17_2)[1];
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_2) + 4);
                        func_0031ac10(arg0, sp218, temp_18->f128, var_17_2, temp_16_6, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp210, 16.0f, 128.0f);
                        temp_19_2 = func_002e48a0(0, var_17_2)[1];
                        temp_16_7 = *(u8 *)((u8 *)func_002e48a0(0, var_17_2) + 4);
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp210, var_17_2, temp_19_2, temp_16_7, 0, 1, partyCount);
                    }
                    func_002b2970(&sp208, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp208, 0, 1, 0, 0, 0);
                    func_002b2970(&sp200, (f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp200, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
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
                        func_002b2970(&sp1F8, (f32)0x149, 128.0f);
                        temp_16_9 = func_002e48a0(temp_18->f128 + 1, var_17_3)[1];
                        slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_3) + 4);
                        func_0031ac10(arg0, sp1F8, temp_18->f128, var_17_3, temp_16_9, slotByte, 0, 1, 1, 0xCC);
                        func_002b2970(&sp1F0, 16.0f, 128.0f);
                        temp_19_3 = func_002e48a0(0, var_17_3)[1];
                        temp_16_10 = *(u8 *)((u8 *)func_002e48a0(0, var_17_3) + 4);
                        partyCount = *(s8 *)(func_002e4870(0) + 8);
                        func_003191c0(arg0, sp1F0, var_17_3, temp_19_3, temp_16_10, 0, 1, partyCount);
                    }
                    func_002b2970(&sp1E8, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1E8, 0, 1, 0, 0, 0);
                    func_002b2970(&sp1E0, (f32)0x149, 104.0f);
                    func_0031fa20(arg0, sp1E0, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
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
                func_002b2970(&sp1D8, basePos->x, basePos->y);
                func_002b2970(&sp1D0, -380.0f, basePos->y);
                func_0031c2b0(arg0, temp_18->f128, sp1D8, sp1D0);
                func_002b2970(&sp1C8, (f32)0x149, 104.0f);
                func_0031fa20(arg0, sp1C8, 0, 1);
                for (var_17_4 = 0; var_17_4 < (func_0010b5b0() & 0xFFFF); var_17_4++) {
                    func_002b2970(&sp1C0, (f32)0x149, 128.0f);
                    temp_16_11 = func_002e48a0(temp_18->f128 + 1, var_17_4)[1];
                    slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_4) + 4);
                    func_0031ac10(arg0, sp1C0, temp_18->f128, var_17_4, temp_16_11, slotByte, 0, 1, 1, 0xCC);
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
        func_00275820(111.0f + sp150.x, sp150.y, 43.0f, temp_16_12, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, temp_18->f128)[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            func_00314450(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0);
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
        func_00275820(111.0f + sp148.x, sp148.y, 43.0f, temp_16_14, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, temp_18->f128)[1] * 0x11), 0, 0, D_00795E60, 0x15);
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
                func_002b2970(&sp1B8, (f32)0x149, 128.0f);
                temp_16_15 = func_002e48a0(temp_18->f128 + 1, var_17_5)[1];
                slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_5) + 4);
                func_0031ac10(arg0, sp1B8, temp_18->f128, var_17_5, temp_16_15, slotByte, 0, 0, 1, 0xCC);
                func_002b2970(&sp1B0, 16.0f, 128.0f);
                temp_19_4 = func_002e48a0(0, var_17_5)[1];
                temp_16_16 = *(u8 *)((u8 *)func_002e48a0(0, var_17_5) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp1B0, var_17_5, temp_19_4, temp_16_16, 0, 0, partyCount);
            }
            func_002b2970(&sp1A8, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1A8, 0, 0, 0, 0, 0);
            func_002b2970(&sp1A0, (f32)0x149, 104.0f);
            func_0031fa20(arg0, sp1A0, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
        func_00275820(111.0f + sp140.x, sp140.y, 43.0f, temp_16_18, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, temp_17_8->f128)[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x21C) + 0x10), 1) != 1) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_18->f2FA = temp_18->f11E;
            temp_16_19 = temp_18->f2FA;
            temp_17_9 = func_002e48a0(temp_18->f2F9, temp_16_19);
            temp_16_20 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_19);
            temp_19_5 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
            slotMode = func_00311930(temp_19_5, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
            func_003144d0(temp_18->f148, temp_17_9, temp_16_20->f2E4, slotMode, 1);
            temp_16_21 = (s32)func_003147d0(temp_18->f148);
            func_0011d140((u8 *)temp_16_21, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            temp_16_22 = *(u8 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 4);
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
                func_002b2970(&sp198, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp198), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp190, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp190), 1, 4, 0);
                temp_4 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4) {                   /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    temp_16_24 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_24, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f128), 0, 0, 1);
                    return;
                case 1:                             /* switch 2 */
                    temp_16_25 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_25, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0, 1);
                    return;
                case 2:                             /* switch 2 */
                    temp_16_26 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_26, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_27 = (u8)((u8)((u8)((*(u8 *)((u8 *)(func_002e48a0(temp_18->f2F9, temp_18->f2FA))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_27))) {
                        temp_16_28 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_28, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_29 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_10 = (u16 *)(func_002e48a0(temp_18->f2F9, temp_16_29));
                    temp_16_30 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_29);
                    temp_19_6 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_6, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
                    func_003144d0(temp_18->f148, temp_17_10, temp_16_30->f2E4, slotMode, 1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if (temp_18->f122 != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                temp_18->f122 = (s8)((s8)(func_002b2d00(temp_18->f122, 1, 0, 2, 1)));
                ps = func_002b6150(0x151);
                func_002b2970(&sp188, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp188), 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp180, (f32)((temp_18->f122 * 0x8E) + 0x6A), 16.0f);
                func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp180), 1, 4, 0);
                temp_4_2 = (s8)((s8)((s8)(temp_18->f122)));
                switch (temp_4_2) {                 /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_31 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_31, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f128), 0, 0, 1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_32 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0(temp_18->f148, func_002e48a0(0, temp_18->f11E), 0, 0, 1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_33 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_34 = (u8)((u8)((u8)((*(u8 *)((u8 *)(func_002e48a0(temp_18->f2F9, temp_18->f2FA))+(4))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_34))) {
                        temp_16_35 = (s32)((s32)((s32)(func_003147d0(temp_18->f148))));
                        func_0011d140((u8 *)temp_16_35, func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_36 = (s8)((s8)((s8)(temp_18->f2FA)));
                    temp_17_11 = (u16 *)(func_002e48a0(temp_18->f2F9, temp_16_36));
                    temp_16_37 = (FclPartySlot *)(func_002e4870(temp_18->f2F9) + (s8)temp_16_36);
                    temp_19_7 = (s16)func_00247770(iGpffffb3d4[func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1] * 14 + 2]);
                    slotMode = func_00311930(temp_19_7, (u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA), 0);
                    func_003144d0(temp_18->f148, temp_17_11, temp_16_37->f2E4, slotMode, 1);
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
        func_00275820(111.0f + sp138.x, sp138.y, 43.0f, temp_16_39, 0, 2, (const char *)(iGpffffb440 + func_002e48a0(0, temp_17_12->f128)[1] * 0x11), 0, 0, D_00795E60, 0x15);
        if ((s8)func_00314660(temp_18->f148) == 0xE) {
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            temp_18->f129 = -1;
            for (var_17_6 = 0; var_17_6 < (func_0010b5b0() & 0xFFFF); var_17_6++) {
                func_002b2970(&sp178, 16.0f, 128.0f);
                temp_19_8 = func_002e48a0(0, var_17_6)[1];
                temp_16_40 = *(u8 *)((u8 *)func_002e48a0(0, var_17_6) + 4);
                partyCount = *(s8 *)(func_002e4870(0) + 8);
                func_003191c0(arg0, sp178, var_17_6, temp_19_8, temp_16_40, 0, 0, partyCount);
                func_002b2970(&sp170, (f32)0x149, 128.0f);
                temp_16_41 = func_002e48a0(temp_18->f128 + 1, var_17_6)[1];
                slotByte = *(u8 *)((u8 *)func_002e48a0(temp_18->f128 + 1, var_17_6) + 4);
                func_0031ac10(arg0, sp170, temp_18->f128, var_17_6, temp_16_41, slotByte, 0, 0, 1, 0xCC);
            }
            func_002b2970(&sp168, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp168, 0, 0, 0, 0, 0);
            func_002b2970(&sp160, (f32)0x149, 104.0f);
            func_0031fa20(arg0, sp160, 0, 0);
            func_002b6140(temp_18->f28C, 0);
            func_002b6140(temp_18->f290, 0);
            temp_18->f1 = 0x2A;
        }
        break;
    case 0x2F:
        temp_16_42 = func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1];
        temp_17_13 = *(u8 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 4);
        if ((func_00104c70(1) & 0xFF) < temp_17_13) {
            func_00310960(arg0, 0x26, 0);
            temp_18->f1 = 0x31;
        } else if (func_002e53b0(0, *(s16 *)((u8 *)func_002e48a0(temp_18->f2F9, temp_18->f2FA) + 2)) == 1) {
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
        if ((s32)((s32)(func_002bb680(temp_18->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_18->fD);
            return;
        }
        if ((s32)((s32)(func_002bb1c0(temp_18->fD))) == (s32)((s32)(0))) {
            temp_18->f1 = 0x33U;
            func_00122520(1, 0xA);
        } else {
            temp_18->f1 = 0x2DU;
        }
        func_002bb550(temp_18->fD);
        return;
    case 0x31:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680(temp_18->fD))) != (s32)((s32)(0))) {
            func_002bbcf0(temp_18->fD);
            return;
        }
        func_002bb550(temp_18->fD);
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
            sp110[var_16_5] = func_002e48a0(0, var_16_5)[1];
        }
        temp_16_43 = func_002e48a0(temp_18->f2F9, temp_18->f2FA)[1];
        sp110[*(s32 *)(func_002e4870(0) + 8)] = temp_16_43;
        func_002e5ae0(0xD, &sp110, (s8)func_00104c70(1));
        temp_16_44 = *(u32 *)(func_002e4870(0xD) + 8);
        temp_16_45 = (RpRandom() % temp_16_44) * 0xA;
        temp_19_9 = (s8)(temp_16_45 % *(u32 *)(func_002e4870(0xD) + 8));
        temp_18->f2F9 = temp_18->f128 + 1;
        temp_18->f2FA = temp_18->f11E;
        for (var_17_7 = 0; var_17_7 < 8; var_17_7++) {
            if ((((1 << var_17_7) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f2FA + 0x2E4)) >> var_17_7) == 1
                && (s32)func_0010ceb0(func_002e48a0(0xD, temp_19_9)) < 8) {
                temp_16_47 = func_002e48a0(temp_18->f128 + 1, temp_18->f11E)[var_17_7 + 6];
                if (func_0010ce10((u8 *)func_002e48a0(0xD, temp_19_9), temp_16_47) == -1) {
                    func_0010cc20((u8 *)func_002e48a0(0xD, temp_19_9), temp_16_47);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_18->f2FA = temp_19_9;
        temp_16_48 = func_002e48a0(temp_18->f2F9, temp_18->f2FA);
        func_003146f0(temp_18->f148, temp_16_48, *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    case 0x37:
        var_19_3 = 0x63;
        memset(&spF0, 0, 0x1A);
        for (var_16_6 = 0; var_16_6 < *(s32 *)(func_002e4870(0) + 8); var_16_6++) {
            spF0[var_16_6] = func_002e48a0(0, var_16_6)[1];
        }
        temp_16_49 = func_002e48a0(temp_18->f128 + 1, temp_18->f11E)[1];
        spF0[*(s32 *)(func_002e4870(0) + 8)] = temp_16_49;
        func_002e6280(0xD, &spF0, (s8)func_00104c70(1));
        if (*(s32 *)(func_002e4870(0xD) + 8) == 0) {
            temp_18->f2F9 = temp_18->f128 + 1;
            temp_18->f2FA = temp_18->f11E;
            temp_18->f1 = 0x36;
            temp_18->fB2 = 1;
            break;
        }
        temp_18->f2F9 = 0xD;
        for (var_17_8 = 0; var_17_8 < *(s32 *)(func_002e4870(0xD) + 8); var_17_8++) {
            temp_16_50 = *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4);
            if (temp_16_50 >= (func_00104c70(1) & 0xFF)) {
                temp_18->f2FA = var_17_8;
                break;
            }
            if (var_19_3 > (func_00104c70(1) & 0xFF) - *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4)) {
                temp_16_51 = *(u8 *)((u8 *)func_002e48a0(0xD, var_17_8) + 4);
                var_19_3 = (func_00104c70(1) & 0xFF) - temp_16_51;
                temp_18->f2FA = var_17_8;
            }
        }
        temp_19_10 = temp_18->f2FA;
        temp_18->f2F9 = temp_18->f128 + 1;
        for (var_17_9 = 0; var_17_9 < 8; var_17_9++) {
            if ((((1 << var_17_9) & 0xFF & *(s8 *)(func_002e4870(temp_18->f2F9) + temp_18->f11E + 0x2E4)) >> var_17_9) == 1
                && (s32)func_0010ceb0(func_002e48a0(0xD, temp_19_10)) < 8) {
                temp_16_53 = func_002e48a0(temp_18->f2F9, temp_18->f11E)[var_17_9 + 6];
                if (func_0010ce10((u8 *)func_002e48a0(0xD, temp_19_10), temp_16_53) == -1) {
                    func_0010cc20((u8 *)func_002e48a0(0xD, temp_19_10), temp_16_53);
                }
            }
        }
        temp_18->f2F9 = 0xD;
        temp_16_54 = func_002e48a0(0xD, temp_18->f2FA);
        func_003146f0(temp_18->f148, temp_16_54, *(s8 *)(func_002e4870(temp_18->f128 + 1) + temp_18->f11E + 0x2E4));
        temp_18->f0 = 0xD;
        temp_18->f1 = 0xC5;
        break;
    }
}

/* measured: func_002f0f00 recon + jump-table recovery + guarded body installed (see below). */
/* Retail 24048B = 6012 instrs, band 5832-6192 (+-3%: 6012*0.97=5831.64, 6012*1.03=6192.36). Frame 0x400 */
/* (addiu $29,$29,-0x400; sd $31 + sq $30/$23-$16 + swc1 $f22/$f21/$f20). Calls 761 jal. */
/* nop 1109/6012 = 18.45%; cond branches 162 (beqz 45/bnez 48/bne 35/beq 19/bltz 7/blez 5/bc1t 3); */
/* total branch/jump 1036 (162 cond + 111 b + 761 jal + 2 jr); jr x2 (dispatch jr $3 at 0x002F0F68 + return jr $ra). */
/* Delay slots: 0 non-nop. Method: counted from asm/nonmatchings/y_fclCombine/func_002f0f00.s comment-lines + mnemonic regex. */
/* Dispatch: lbu $3,0x1($17); addiu $3,$3,-0x38; sltiu $1,$3,0x19; beqz $1,.L002F6CB0 (default); */
/*   lui/addiu jtbl_00749170; sll $3,$3,2; addu; lw; jr $3 (delay nop). The -0x38 means */
/*   the C switch is over states 0x38..0x50 (56..80): index = state-0x38, 25 cases (0..24). */
/* jtbl_00749170 at 0x00749170, extent 28 words (0x70) to next jtbl_007491E0 at 0x007491E0; */
/*   valid 25 (indices 0..24); words 25-27 are 0x0 pad, not cases. sltiu bound 0x19 = 25 */
/*   cases; with default that is 26 arms. */
/* Default .L002F6CB0 = 0x002F6CB0 (+0x5DB0 from entry 0x002F0F00); no case shares it (all 25 targets distinct). */
/* Full table (valid 25; `python3 tools/jtbl.py 0x00749170 25 --func 0x002f0f00`): */
/*   case  0 (0x38): 0x002F0F70 (+0x70)    case 13 (0x45): 0x002F4AC4 (+0x3BC4) */
/*   case  1 (0x39): 0x002F1070 (+0x170)   case 14 (0x46): 0x002F53D4 (+0x44D4) */
/*   case  2 (0x3A): 0x002F11A4 (+0x2A4)   case 15 (0x47): 0x002F5098 (+0x4198) */
/*   case  3 (0x3B): 0x002F1754 (+0x854)   case 16 (0x48): 0x002F62DC (+0x53DC) */
/*   case  4 (0x3C): 0x002F1BE8 (+0xCE8)   case 17 (0x49): 0x002F6408 (+0x5508) */
/*   case  5 (0x3D): 0x002F19B8 (+0xAB8)   case 18 (0x4A): 0x002F6480 (+0x5580) */
/*   case  6 (0x3E): 0x002F1C44 (+0xD44)   case 19 (0x4B): 0x002F6554 (+0x5654) */
/*   case  7 (0x3F): 0x002F1D00 (+0xE00)   case 20 (0x4C): 0x002F64C4 (+0x55C4) */
/*   case  8 (0x40): 0x002F2404 (+0x1504)  case 21 (0x4D): 0x002F6584 (+0x5684) */
/*   case  9 (0x41): 0x002F38D4 (+0x29D4)  case 22 (0x4E): 0x002F5EFC (+0x4FFC) */
/*   case 10 (0x42): 0x002F3A30 (+0x2B30)  case 23 (0x4F): 0x002F66AC (+0x57AC) */
/*   case 11 (0x43): 0x002F3E70 (+0x2F70)  case 24 (0x50): 0x002F6940 (+0x5A40) */
/*   case 12 (0x44): 0x002F48C4 (+0x39C4)  words 25-27: 0x0 pad (next table at 0x7491E0). */
/* Object order (ascending targets): 0,1,2,3,5,4,6,7,8,9,10,11,12,13,15,14,22,16,17,18,20,19,21,23,24. */
/*   Out-of-order pairs (5 before 4; 15 before 14; 22 before 16-21; 20 before 19) are object layout only; */
/*   m2c prints labels permuted - source order stays numeric. */
/* C shape: switch (state - 0x38) { case 0: ... case 24: ...; default: ... } (or equivalently */
/*   switch (state) { case 0x38: ... case 0x50: ...; default: ... } - mwcc normalises contiguous */
/*   0x38..0x50 to the same addiu -0x38 + sltiu 0x19). All 25 cases present; the bound matches */
/*   iff all are present. Two extra sltiu 0x1F4 (500) range checks inside case bodies are branch */
/*   if-chains, not jump tables (no jtbl refs). */
/* m2c with tables (this lane): staged /tmp/m2c_in_002f0f00.s = build/m2c/func_002f0f00.s plus */
/*   the 25 .word entries as `.word .L<target>` under .rdata plus the missing `.L<target>:` */
/*   labels at each target's address-comment line (cf. tools/m2c_bulk.py prepare_assembly_block). */
/*   `python3 tools/vendor/m2c/m2c.py --target mipsee-mwcc-c --context build/m2c/func_002f0f00.ctx.c */
/*   --globals=used -f func_002f0f00 /tmp/m2c_in_002f0f00.s > /tmp/m2c_2f0f00_out.c` succeeds; */
/*   without the table it fails `Found jr instruction` at the dispatch (same class as 002be530/00332bb0). */
/*   Output /tmp/m2c_2f0f00_out.c region (src/generated/code1_002f.c P4_UNIT_002f0f00): 1657 lines, */
/*   12 M2C_ERROR (6 ldr/ldl pairs at 0x28/0x2F + 0x38/0x3F, all 8-aligned, feeding 002b69f0-style */
/*   struct-by-value calls; s64 spelling gives plain ld - cf. wave C note above), 21 M2C_UNK decls */
/*   (s0/s5 + sp3FD/sp3FE/sp3FF + unksp3BC/3C4/3CC + sp150/sp130 + var_16_10 + 6 s128 pointer slots), */
/*   612 M2C_FIELD, 9 M2C_LWL, 12 M2C_BITWISE, 46 switches (1 main jtbl with 25 cases permuted */
/*   5/4,15/14,22/16-21,20/19 in m2c output; switches 2 (cases 12/10/8/6) and 3 (cases 0-3) irregular */
/*   4-case groups are branch if-chains, not jtbls; remaining 43 are small branch if-chains). */
/* Width calibration: this TU has five banked floors with object/retail instr counts - 002eb270 */
/*   1902/1876 (+1.39% PASS), 002f6cf0 2937/3020 (-2.75% PASS), 002f9d90 2131/2116 (+0.71% PASS), */
/*   00302770 957/936 (+2.24% PASS), 003097e0 1603/1568 (+2.23% PASS). Per assignment, an all-s32 */
/*   draft was expected ~10% short with a 2-3 var landing set (cf. 001a7720: seven of twelve */
/*   candidates cost nothing, one cost 556 alone). Here: s64-heavy draft (72 s64 temps kept) */
/*   6514 vs 6011 (+503, +8.37% over, outside above by 323); all-s32 draft (72 temps narrowed, */
/*   sp buffers stay s64 as in siblings) 5867 vs 6011 (-144, -2.40%, band 5831-6191 PASS with 36 */
/*   headroom above lower, 324 below upper; for 6012 band 5832-6192, 35/322). Landing set empty - */
/*   no s64 temps needed to keep; s0 assigned from 002b6150 returns and sp130/sp150 arrays used */
/*   for the (s32)(sp)+0x130/0x150 stack slots (cf. 002f6cf0's s64 stk + s32 index + col arrays). */
/* measured 002f0f00 (owner, all-s32 from m2c-adapted /tmp/cand_002f0f00_s32.c): object 5867 vs */
/*   retail 6011 (-144, -2.40%, band 5831-6191 PASS), fnalign 4252 edits (+66 reloc-only) via */
/*   `python3 tools/fnalign.py src/Event/Fcl/y_fclCombine.c func_002f0f00 --candidate */
/*   /tmp/cand_002f0f00_s32.c --quiet`, probe_variants 4972 differing words (reloc-masked) via */
/*   `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombine.c func_002f0f00 --candidate */
/*   cand=/tmp/cand_002f0f00_s32.c`. No pragmas: retail here is unscheduled like the rest of this */
/*   unit, and `schedule on` is a lint error in first-party bodies now (H010). Built from the m2c */
/*   oracle de-noised to this file's idiom - M2C_FIELD expanded to direct casts, gp temporaries */
/*   resolved to ((s32)iGpffffb440)/((s32)iGpffffb3d4)/iGpffff8504, six ldr/ldl pairs written as */
/*   struct-by-value `*(FclVec2f *)(s0 + 0x38)` with `s0 = func_002b6150(0x152/0x2E0)` (cf. wave C */
/*   mechanism 1) and `*(FclVec2f *)&spXXX` for stack FclVec2f slots, 72 s64 temps narrowed to s32, */
/*   m2c arg-count hallucinations cut back (0010b5b0()->0 args, 002b6150/00314660 second jtbl arg */
/*   dropped, 003190d0(&jtbl)->arg0, 003233d0(&jtbl)->arg0, 00122720()->0 args, 002bb680/002e4870 */
/*   second arg dropped), D_008C024E/024C/027A scalar uses fixed to [0], and later-defined callees */
/*   given local prototypes (002f9c30/00310960/00310a10/003233d0). Production guarded (edits 4252). */
/* measured 002f0f00 (owner, 2026-09-19): fnalign **4252 -> 4247 edits**, count
   5867 -> 5865 against retail 6011, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 002f0f00 (owner, 2026-09-19): fnalign **4247 -> 4120 edits**, count
   5865 -> 6057 against retail 6012 (assignment says 6011/5865, -146; now +45,
   band 5832-6192 PASS), via tail_classify + table_order + structural hunks + loops.
   tail_classify: 793 structure/101 register -> 840/106, still STRUCTURE (70% wrong
   in shape, so regions before spelling). table_order: source already in jtbl layout
   order 0,1,2,3,5,4,6,7,8,9,10,11,12,13,15,14,22,16,17,18,20,19,21,23,24 (matches
   header object order); tool silent on this file (`case X:  ...  slash-star switch
   star-slash` suffix fails its `case:` regex), manual check shows no reorder win.
   switch 4 had no `case` labels (m2c left `slash-star switch 4 star-slash` only, so
   three arms unreachable): restored `case 0/1/2/3` mirroring switch 3, verified vs
   retail beq 3/2/1/0 at 0x002F5C2C-0x002F5C54 layout 0/1/2/3 (65C64/5CD0/5D3C/5DA8).
   Cost +188 count (5865->6053), +24 edits (4247->4271), but truthful and gate PASS.
   Loops: m2c `loop_N: if (cond) { ...; goto loop_N; }` (top slti/beqz + bottom b)
   vs retail `b cond; body; cond/bnez` (micro: for/while has initial b, do has none,
   goto has top test). Banked loop_7 do kept per assignment (for would be 4271->4270
   +2 count, marginally closer, but banked work stands). Other loops measured
   individually as `for (; cond;)` (with initial b, matching retail): 19/46/62 each
   -3..-5 (4271->4266->4263->4259), 87/108/135 each -6 (4259->4241), 170/184/192 each
   -6 (4241->4223), bulk 93/97/114/112/141/139/149/198 + 91/128/124/147/221/273 (8
   direct + 6 temp-pre with temp moved inside) -103 combined (4223->4120, 6055->6057
   +2). Constants 295 (<0x30C) and 319/339 (<8) neutral: s32<<48 is UB, micro shows
   goto/for/do collapse to one shape, so left alone. Inner switches 2 (12/10/8/6)
   and 3/4 (0/1/2/3) already match retail (micro: checks reverse of layout, layout
   in source order, exactly retail beq 6/8/10/12 and 3/2/1/0). */
/* measured 002f0f00 (lane, 2026-09-20): fnalign **4120 -> 2929 edits** (-1191), count
   6057 -> 5874 against retail 6011 (-2.3%, band 5831-6191 PASS, headroom 43).
   tail_classify 840/106 -> 889/122, still STRUCTURE (unslide revealed small hunks;
   net -1191). deficit_scan retail-only runs 251+201+83 -> 45+38+33 (R201 0x541C and
   R251 0x5B0C crossed blocks unslid, not missing code; lump 475 -> ~357 -> gone).
   Banked, in order (all via measure_guarded + fnalign --candidate, one at a time):
   43.0f for int 0x422C0000 (2 sites, case 0x46): 4120->4116, -4 count (retail
   lui/mtc1 direct; int literal forced cvt.s.w, wrong value 1.1e9 vs 43.0f).
   plain f32 loads for triple (f32)(s32)x3 (0x46, 4 sites): 4116->4092, -24 count
   (retail lwc1/swc1/add.s with no converts; kept stack round-trip via spXXX).
   int-add hoist defeat `(u8 *)((u32)base + 0x148U)` (switch-3/4 second uses, 6 arms):
   4090->3933 (-157), -5 count; micro-proven (tools/micro_codegen.py): b210 hoists a
   repeated `base+OFF` into `addiu $sX,$sY,OFF` + `lw ($sX)` (object had 29x 0x148,
   10x 0x11e, 6x 0x129/0x2f9, 5x 0x2fa/0x154 bumps; retail has none), int-add emits
   the identical `lw OFF(base)` without merging, struct-member also defeats but
   struct/int/pointer all SELF-merge so rotation caps at 3 shapes per merge group.
   (s64)(<<0x38>>0x38) -> plain on s8-return 00314660 guards (9 sites: 0x46 ==0xD +
   8x ==5/==0xE): 3933->3928->3865 (-68 total), -53 count (retail extends s8 via
   dsll32/dsra32 24; verified at 0x553C; micro e2/e3 confirm plain/(s8) emit 24).
   Same for 6x <0||>=6 range guards (12 wrappers): 3865->3787 (-78), -72 count.
   Case 0x47 floats (4 loads + 2x 43.0f): 3787->3765 (-22), -28 count.
   temp_17 reload `temp_17 = *(arg0+0x38)` before case-0x46 `&80` block: 3765->2929
   (-836), +5 count; the reload breaks the TW+0x148 CSE chain (v1 micro: a load
   between uses defeats it) and unslid R201+R251 wholesale. loop_319 goto->do-while
   (retail head 0x67DC has no top-test; temp_20_6->temp_16_81 in body): neutral,
   kept as retail-verified shape. (s8) on 0x46 guard: neutral, kept.
   Tried and REVERTED (losses, excluded from banked state): if-chain mixed
   int/struct rotation +5; lone 4221 int-add +7 (int-adds merge ACROSS the case,
   consolidating one shared hoist - six-arm won by consolidating 6 -> fewer, adding
   a 7th lengthened its span); (s8)var_20 x6 -850 alone BUT +8 on top of reload
   (same slide fixed twice, shapes conflict); post-loop temp_17 reload neutral
   (compiler eliminated it); bare `(temp_18_XX)` s8-use in 3146f0 args does NOT
   compile (mwcc rejects; (s64)56 stays at 4512/4574). ldr/ldl already correct
   (object matches retail pairs; missing pairs live in crossed regions). Float
   homes $f20 vs retail $f1 and swc1-less preloads are register-class, tolerated.
   Left: 45-run 0x6894 (0x4F post-loop extends/hoists), 38-run 0x6C18 (0x50 tail),
   33-run 0x33E8 (0x3B six 34ae50 loop, 0x154 hoist + extends); further float-case
   cleanups (0x40/45/4E) deferred: each costs ~28 count, headroom is 43. */
/* measured 002f0f00 (owner, 2026-09-20): helper census 6x __floatdisf -> 0, kept per
   refined rule (short floor: helper removal must shorten, count not judged).
   Retail at all six sites is plain narrow lwc1 with no helper nearby:
   lwc1 $f1,0x3B8 / lwc1 $f0,0x3BC / swc1 $f1,0x3D0 at 0x002F1430-38,
   lwc1 $f0,0x3C8 at 0x002F150C, lwc1 $f12,0x3C0 at 0x002F15E0/0x002F162C/
   0x002F16C4 (0x002F16AC equivalent). Fixes: sp3D0 = *(f32 *)&sp3B8,
   *(f32 *)&sp3C8, 4x sp3C0.position.x for ((f32)(sp3C0.bits)).
   fnalign 2929 -> 2909 edits (-20), words 4982 -> 4969 (-13), count
   5874 -> 5857 (-17) against retail 6011 (band 5831-6191 PASS, headroom 43 -> 26).
   Count moves away by 17 because a helper call (jal + shuffling) is longer than
   the single lwc1 that replaces it; on this short floor that direction is expected. */
/* measured 002f0f00 (owner, 2026-09-20): 33-run 0x002F33E8 extends-only tried and
   REVERTED. Six (s64)(var_20<<0x38)>>0x38 (s32<<56, UB) -> plain var_20 in the
   temp_18_6/0x154 loop: micro proves plain emits retail dsll32/dsra32 24 while UB
   emits move $a1,$zero, but in full context the loop still emits move zero and
   keeps addiu $s1,base,0x154 + lw ($s1) hoist vs retail lw 0x154(base) x6.
   fnalign 2909 -> 2917 (+8), words 4969 -> 4976 (+7), count 5857 -> 5865 (+8);
   partial fix without hoist defeat misaligns, so reverted. Hoist defeat has no
   measured lever here (loop micro: plain and (u32)+U both hoist after first use).
   45-run 0x002F6894 and 38-run 0x002F6C18 still ABSENT, deferred with headroom 26. */
// FUN_002F0F00 NONMATCHING
#ifdef NON_MATCHING
void func_002f0f00(u8 *arg0) {
    extern s32 func_00104c70(s32);
    extern void func_002e4610(s32, s8);
    extern void func_00315600(u8 *, s32);
    extern s32 func_003190d0(u8 *);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern s32 func_0010b5b0(void);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern void func_00275820(s32, s32, s32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern void func_002b2970(void *, f32, f32);
    extern s32 func_0046d200(s32, s32);
    extern s64 func_00331560(void);
    extern f32 func_0046b260(s32);
    extern f32 func_0046b2f0(s32);
    extern void func_0046d280(s32);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);

    extern void func_00314450(u8 *,  u16 *,  s32,  s32);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011d140(u8 *,  s32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011caf0(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_00314740(u8 *,  s32);
    extern u8 *func_003147d0(u8 *);
    extern void func_0045af60(s32, s32, s32, s32);
    extern void func_00314670(u8 *,  s32);
    extern void func_00317240(u8 *, s32, f32);
    extern void func_00325450(u8 *, s32, s32);
    extern s8 func_00314660(u8 *);
    extern void func_00314680(u8 *);
    extern s32 func_002b6970(s16, s32);
    extern u8 *func_002b6150(s16);
    extern void func_00321e60(u8 *, s32, s32, s32);
    extern void func_003233d0(u8 *);
    extern void func_003191c0(u8 *, s64, s32, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s32, u16, u8, s32, s32, s32, s32);
    extern void func_0031c2b0(u8 *, s64, s32, s32);
    extern void func_0031cce0(u8 *, s64, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00324410(u8 *, s32, s32);
    extern u32 RpRandom(void);
    extern void func_002b68d0(s16, s32, s32);
    extern void func_002bb550(s8);
    extern void func_002bbcf0(s8);
    extern s32 func_002e53b0(s32, s32);
    extern void func_002eb270(u8 *, s32);
    extern s32 func_00105f50(s16);
    extern s32 datGetFlag(s32);
    extern void memset(void *, s32, u32);
    extern void func_002e5ae0(s32, void *, s64);
    extern void func_002e6280(s32, void *, s64);
    extern s32 func_0010ce10(u8 *,  u32);
    extern s32 func_0010ceb0(void *);
    extern void func_0010cc20(u8 *,  u16);
    extern s32 func_002bb680(s8);
    extern s32 func_00122720();
    extern void func_00122520(s32, s32);
    extern s64 func_00247770(s32);
    extern s32 func_00312bc0(s32);
    extern void func_003144d0(u8 *,  u16 *,  s32,  s32,  s32);
    extern s32 func_00311930(s32,  u8 *,  s8);
    extern s32 func_002b2cb0(u8, s32, s32, s32, s32);
    extern s32 func_002b2d00(u8, s32, s32, s32, s32);
    extern f32 D_00640C10[];
    extern f32 D_00640C18[];
    extern u8 D_00795E60[];
    extern u16 D_008C024E[];
    extern u16 D_008C024C[];
    extern u16 D_008C027A[];
    extern u8 *iGpffffb440;
    extern u8 *iGpffffb3d4;
    extern f32 iGpffff8504;
    extern void func_002f9c30(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00310a10(u8 *, u16);

    u8 *s0;
    u8 sp3FD;
    u8 sp3FE;
    u8 sp3FF;
    f32 unksp3BC;
    f32 unksp3C4;
    f32 unksp3CC;
    u8 sp3FC;
    u8 sp3F8;
    u8 sp3F4;
    u8 sp3F0;
    u8 sp3EC;
    u8 sp3E8;
    u8 sp3E4;
    u8 sp3E0;
    u8 sp3DC;
    u8 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    s64 sp3C8;
    FclPackedPosition sp3C0;
    s64 sp3B8;
    s64 sp3B0;
    s64 sp3A8;
    s64 sp3A0;
    s64 sp398;
    s64 sp390;
    s64 sp388;
    s64 sp380;
    s64 sp378;
    s64 sp370;
    s64 sp368;
    s64 sp360;
    s64 sp358;
    s64 sp350;
    s64 sp348;
    s64 sp340;
    s64 sp338;
    s64 sp330;
    s64 sp328;
    s64 sp320;
    s64 sp318;
    s64 sp310;
    s64 sp308;
    s64 sp300;
    s64 sp2F8;
    s64 sp2F0;
    s64 sp2E8;
    s64 sp2E0;
    s64 sp2D8;
    s64 sp2D0;
    s64 sp2C8;
    s64 sp2C0;
    s64 sp2B8;
    s64 sp2B0;
    s64 sp2A8;
    s64 sp2A0;
    s64 sp298;
    s64 sp290;
    s64 sp288;
    s64 sp280;
    s64 sp278;
    s64 sp270;
    s64 sp268;
    s64 sp260;
    s64 sp258;
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
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E4;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D4;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    u16 sp150[16];
    u16 sp130[16];
    u8 *sp120;
    u8 *sp110;
    u8 *sp100;
    s32 spF0;
    u8 *spE0;
    u8 *spD0;
    s32 var_16_10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f1;
    s16 *temp_16_20;
    s16 *temp_16_6;
    s16 *temp_18_14;
    s16 *temp_20_3;
    s16 *temp_21_10;
    s16 *temp_21_12;
    s16 *temp_21_2;
    s16 *temp_21_3;
    s16 *temp_21_7;
    s16 *temp_22;
    s16 *temp_22_2;
    s16 *temp_22_3;
    s16 *temp_22_6;
    s16 *temp_22_7;
    s16 *temp_23;
    s16 *temp_23_2;
    s16 *temp_23_3;
    s16 *temp_23_4;
    s16 *temp_2;
    s16 *temp_30;
    s16 *temp_30_2;
    s16 *temp_30_3;
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
    s32 temp_16_4;
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
    s32 temp_16_7;
    s32 temp_16_9;
    s32 temp_18_11;
    s32 temp_18_20;
    s32 temp_19_7;
    s32 temp_20_5;
    s32 temp_21_4;
    s32 temp_21_5;
    s32 temp_21_8;
    s32 temp_22_4;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 var_18;
    s32 var_19;
    s32 var_19_3;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 temp_16_11;
    s32 temp_16_13;
    s32 temp_16_15;
    s32 temp_16_17;
    s32 temp_16_21;
    s32 temp_16_2;
    s32 temp_16_40;
    s32 temp_16_46;
    s32 temp_16_5;
    s32 temp_16_75;
    s32 temp_16_81;
    s32 temp_16_87;
    s32 temp_18;
    s32 temp_18_10;
    s32 temp_18_12;
    s32 temp_18_15;
    s32 temp_18_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_18_41;
    s32 temp_18_42;
    s32 temp_18_43;
    s32 temp_18_5;
    s32 temp_18_7;
    s32 temp_19;
    s32 temp_19_11;
    s32 temp_19_12;
    s32 temp_19_13;
    s32 temp_19_14;
    s32 temp_19_2;
    s32 temp_19_6;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_4;
    s32 temp_20_6;
    s32 temp_20_8;
    s32 temp_21;
    s32 temp_21_11;
    s32 temp_21_6;
    s32 temp_3_3;
    s32 var_16;
    s32 var_16_11;
    s32 var_16_12;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_16_7;
    s32 var_16_8;
    s32 var_16_9;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_18_5;
    s32 var_18_6;
    s32 var_18_7;
    s32 var_18_8;
    s32 var_18_9;
    s32 var_19_10;
    s32 var_19_11;
    s32 var_19_2;
    s32 var_19_4;
    s32 var_19_5;
    s32 var_19_6;
    s32 var_19_7;
    s32 var_19_8;
    s32 var_19_9;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_21;
    s8 temp_16_14;
    s8 temp_16_61;
    s8 temp_16_69;
    s8 temp_18_16;
    s8 temp_18_28;
    s8 temp_18_39;
    s8 temp_18_44;
    s8 temp_19_15;
    s8 temp_2_10;
    s8 temp_2_11;
    s8 temp_2_5;
    s8 temp_4;
    s8 temp_4_2;
    s8 var_4;
    u16 *temp_16_18;
    u16 *temp_16_83;
    u16 *temp_16_89;
    u16 *temp_18_31;
    u16 *temp_18_34;
    u16 *temp_18_35;
    u16 *temp_21_9;
    u16 *temp_22_5;
    u16 temp_16_30;
    u16 temp_16_32;
    u16 temp_16_34;
    u16 temp_16_41;
    u16 temp_16_76;
    u16 temp_16_77;
    u16 temp_16_78;
    u16 temp_16_82;
    u16 temp_16_84;
    u16 temp_16_88;
    u16 temp_18_13;
    u16 temp_19_10;
    u16 temp_19_3;
    u16 temp_19_4;
    u16 temp_19_5;
    u16 temp_19_8;
    u16 temp_19_9;
    u16 temp_21_13;
    u16 temp_21_14;
    u32 temp_16_79;
    u32 temp_16_80;
    u8 temp_16_25;
    u8 temp_16_27;
    u8 temp_16_31;
    u8 temp_16_33;
    u8 temp_16_42;
    u8 temp_16_44;
    u8 temp_16_49;
    u8 temp_16_51;
    u8 temp_16_53;
    u8 temp_16_59;
    u8 temp_16_67;
    u8 temp_16_71;
    u8 temp_16_73;
    u8 temp_16_85;
    u8 temp_16_86;
    u8 temp_16_8;
    u8 temp_18_17;
    u8 temp_18_22;
    u8 temp_18_27;
    u8 temp_18_38;
    u8 temp_18_40;
    u8 temp_18_4;
    u8 temp_18_9;
    u8 temp_20_7;
    u8 temp_3;
    u8 temp_7;
    u8 temp_7_2;
    u8 temp_7_3;
    u8 *temp_16;
    u8 *temp_16_12;
    u8 *temp_16_16;
    u8 *temp_16_47;
    u8 *temp_16_62;
    u8 *temp_16_70;
    u8 *temp_17;
    u8 *temp_18_19;
    u8 *temp_18_21;
    u8 *temp_18_23;
    u8 *temp_18_24;
    u8 *temp_18_25;
    u8 *temp_18_26;
    u8 *temp_18_29;
    u8 *temp_18_30;
    u8 *temp_18_32;
    u8 *temp_18_33;
    u8 *temp_18_36;
    u8 *temp_18_37;
    u8 *temp_18_6;
    u8 *temp_18_8;
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

    temp_17 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
    temp_3 = (u8)((u8)((u8)((*((u8 *)((u8 *)(temp_17) + (1)))))));
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
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x39U;
        return;
    case 0x39:                                      /* switch 1 */
        if ((s32)((s32)(func_003190d0(arg0))) != (s32)((s32)(1))) {
            var_4 = (s8)((s8)(*func_002e4870(0)));
            if (var_4 == 1) {
                var_16 = 0;
do {
                        fclWriteColorBytes((u8 *)(&sp3FC), 0, 0, 0x99, 0xFFU);
                        temp_2 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x188))))),  (s64) (var_16 << 0x38) >> 0x38));
                        var_4 = (s8) sp3FE;
                        (*((u8 *)((u8 *)(temp_2) + (0x75)))) = sp3FC;
                        (*((u8 *)((u8 *)(temp_2) + (0x76)))) = sp3FD;
                        (*((s8 *)((u8 *)(temp_2) + (0x77)))) = var_4;
                        (*((u8 *)((u8 *)(temp_2) + (0x78)))) = sp3FF;
                        var_16 = (s64) ((var_16 + 1) << 0x30) >> 0x30;
} while ((s32)((s32)(((s64) (var_16 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF))));
                func_003205f0(arg0, 0x93, 0x96);
                func_00320b80(arg0, 1);
                func_00316470(arg0, 1, 0);
                func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3AU;
                return;
            }
        }
    default:                                        /* switch 1 */
        return;
    case 0x3A:                                      /* switch 1 */
        var_16_2 = 0;
        for (; (s32)((s32)(((s64) (var_16_2 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
            temp_18 = (s64) (var_16_2 << 0x30) >> 0x30;
            temp_20 = (s64) (var_16_2 << 0x30) >> 0x30;
            temp_19 = temp_20 + 0x21C;
            temp_f20 = (f32)(s32)((f32)(s32)((f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_19 << 0x30) >> 0x30)) + (0x42))))));
            temp_f0 = (f32)(s32)((f32)(s32)(func_002b2aa0(0, 0, 0x437F0000, temp_f20, (f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_19 << 0x30) >> 0x30)) + (0x40)))))));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if ((*((s16 *)((u8 *)(temp_17) + (0x11E)))) == temp_20) {
                var_19 = (s32)((s32)(func_002b2a30(0x2D, 0x2D, 0x2D, temp_7)));
            } else {
                var_19 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_7)));
            }
            if (temp_18 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                func_00275820(var_19, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, var_16_2)) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 113.0f, (f32)(s32)((temp_18 * 0x17) + 0x80), 0x422C0000);
            }
            var_16_2 = (s64) ((var_16_2 + 1) << 0x30) >> 0x30;
        }
        temp_16 = (u8 *)(((func_0010b5b0() & 0xFFFF) * 4) + (s32)(temp_17));
        if ((s32)((s32)(((s32) (*func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16) + (0x150))))),  (s64) (((func_0010b5b0() & 0xFFFF) - 1) << 0x38) >> 0x38) & 4) >> 2))) == (s32)((s32)(0))) {
            temp_2_2 = (s32)((s32)(func_0010b5b0()));
            if (temp_2_2 >= 0) {
                var_f1 = (f32) temp_2_2;
            } else {
                var_f1 = 2.0f * (f32)(s32)(((u32) temp_2_2 >> 1) | (temp_2_2 & 1));
            }
            temp_f20_2 = var_f1 / 12.0f;
            func_002b2970(&sp3B8, (f32) 0x149, 128.0f);
            sp3D0 = *(f32 *)&sp3B8;
            sp3D4 = unksp3BC;
            temp_f1 = (f32)(s32)((f32)(s32)((f32)(s32)((func_0010b5b0() & 0xFFFF) * 0x17) / 2.0f));
            func_002b2970(&sp3C8, sp3D0 + temp_f1, unksp3BC + temp_f1);
            temp_2_3 = (s32)((s32)(func_0046d200(func_00331560(), 0x7E)));
            temp_f22 = (f32)(s32)((f32)(s32)((temp_f20_2 * func_0046b260(temp_2_3)) / 2.0f));
            temp_f21 = (f32)(s32)((f32)(s32)((temp_f20_2 * func_0046b2f0(temp_2_3)) / 2.0f));
            func_0046d280(temp_2_3);
            func_002b2970(&sp3C0.bits, *(f32 *)&sp3C8 - temp_f22, unksp3CC - temp_f21);
            func_002b6c30(0x7E, sp3C0.position, 0x431C0000, 0x56);
            func_002b6a70(0x7E, 0U, 0xFF, 0, 2, 0);
            (*((f32 *)((u8 *)(func_002b6150(0x7E)) + (0xAC)))) = temp_f20_2;
            (*((f32 *)((u8 *)(func_002b6150(0x7E)) + (0xA0)))) = temp_f20_2;
            temp_3_2 = (s32)((s32)(func_0010b5b0() & 0xFFFF));
            switch (temp_3_2) {                     /* switch 2; irregular */
            case 12:                                /* switch 2 */
                func_002b2970(&sp3B0, sp3C0.position.x, unksp3C4 - 20.0f);
                func_002b69f0(0x7E, (*(FclVec2f *)&sp3C0.bits), (*(FclVec2f *)&sp3B0),  1,  8,  0);
                break;
            case 10:                                /* switch 2 */
                func_002b2970(&sp3A8, sp3C0.position.x, unksp3C4 - 16.0f);
                func_002b69f0(0x7E, (*(FclVec2f *)&sp3C0.bits), (*(FclVec2f *)&sp3A8),  1,  8,  0);
                break;
            case 8:                                 /* switch 2 */
                func_002b2970(&sp3A0, sp3C0.position.x, unksp3C4 - 13.0f);
                func_002b69f0(0x7E, (*(FclVec2f *)&sp3C0.bits), (*(FclVec2f *)&sp3A0),  1,  8,  0);
                break;
            case 6:                                 /* switch 2 */
                func_002b2970(&sp398, sp3C0.position.x, unksp3C4 - 10.0f);
                func_002b69f0(0x7E, (*(FclVec2f *)&sp3C0.bits), (*(FclVec2f *)&sp398),  1,  8,  0);
                break;
            }
            (*((s8 *)((u8 *)(func_002b6150(0x7E)) + (0x47)))) = 1;
            func_002b6af0(0x7E, temp_f20_2, temp_f20_2, temp_f20_2 - iGpffff8504, temp_f20_2, 0, 4, 4);
            if ((*((s8 *)((u8 *)(temp_17) + (0x128)))) == -1) {
                (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = 0;
            }
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3DU;
            return;
        }
        break;
    case 0x3B:                                      /* switch 1 */
        var_19_2 = 0;
        for (; (s32)((s32)(((s64) (var_19_2 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
            temp_16_2 = (s64) (var_19_2 << 0x30) >> 0x30;
            temp_18_2 = (s64) (var_19_2 << 0x30) >> 0x30;
            temp_21 = temp_18_2 + 0x21C;
            temp_f20_3 = (f32)(s32)((f32)(s32)((f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_21 << 0x30) >> 0x30)) + (0x42))))));
            temp_f0_2 = (f32)(s32)((f32)(s32)(func_002b2aa0(0, 0x437F0000, 0, temp_f20_3, (f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_21 << 0x30) >> 0x30)) + (0x40)))))));
            if (!(temp_f0_2 >= 2.1474836e9f)) {
                var_3_2 = ((s32)(temp_f0_2)) & 0xFF;
            } else {
                var_3_2 = (((s32)((temp_f0_2 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7_2 = var_3_2 & 0xFF;
            if ((*((s16 *)((u8 *)(temp_17) + (0x11E)))) == temp_18_2) {
                var_18 = (s32)((s32)(func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_2)));
            } else {
                var_18 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_2)));
            }
            if (temp_16_2 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                func_00275820(var_18, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, var_19_2)) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 113.0f, (f32)(s32)((temp_16_2 * 0x17) + 0x80), 0x422C0000);
            }
            var_19_2 = (s64) ((var_19_2 + 1) << 0x30) >> 0x30;
        }
        if (((s32)((s32)(((s32) (*func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x154))))),  0) & 4) >> 2))) == (s32)((s32)(0))) && ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1) << 0x30) >> 0x30))) == (s32)((s32)(0)))) {
            func_003205f0(arg0, 0x96, 0x93);
            func_002eb270(arg0, 0U);
            func_00315600(arg0, 0);
            (*((s8 *)((u8 *)(temp_17) + (0)))) = 0;
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x1AU;
            return;
        }
        break;
    case 0x3D:                                      /* switch 1 */
        var_21 = -1;
        var_16_3 = 0;
        for (; (s32)((s32)(((s64) (var_16_3 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
            temp_18_3 = (s64) (var_16_3 << 0x30) >> 0x30;
            temp_19_2 = (s64) (var_16_3 << 0x30) >> 0x30;
            temp_20_2 = temp_19_2 + 0x21C;
            temp_f20_4 = (f32)(s32)((f32)(s32)((f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_20_2 << 0x30) >> 0x30)) + (0x42))))));
            temp_f0_3 = (f32)(s32)((f32)(s32)(func_002b2aa0(0, 0, 0x437F0000, temp_f20_4, (f32) (*((s16 *)((u8 *)(func_002b6150((s64) (temp_20_2 << 0x30) >> 0x30)) + (0x40)))))));
            if (!(temp_f0_3 >= 2.1474836e9f)) {
                var_3_3 = ((s32)(temp_f0_3)) & 0xFF;
            } else {
                var_3_3 = (((s32)((temp_f0_3 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7_3 = var_3_3 & 0xFF;
            if ((*((s16 *)((u8 *)(temp_17) + (0x11E)))) == temp_19_2) {
                var_19_3 = (s32)((s32)(func_002b2a30(0x2D, 0x2D, 0x2D, temp_7_3)));
            } else {
                var_19_3 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_7_3)));
            }
            if (temp_18_3 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                func_00275820(var_19_3, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, var_16_3)) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 113.0f, (f32)(s32)((temp_18_3 * 0x17) + 0x80), 0x422C0000);
            }
            if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150((s64) (temp_20_2 << 0x30) >> 0x30)) + (0x10)))), 1) << 0x30) >> 0x30))) == (s32)((s32)(1))) {
                var_21 = (s64) (1 << 0x30) >> 0x30;
            }
            var_16_3 = (s64) ((var_16_3 + 1) << 0x30) >> 0x30;
        }
        if (((s64) (var_21 << 0x30) >> 0x30) == -1) {
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3CU;
            return;
        }
        break;
    case 0x3C:                                      /* switch 1 */
        if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
            func_00321e60(arg0, 1, 0x40, 0x3B);
            return;
        }
        break;
    case 0x3E:                                      /* switch 1 */
        if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1) << 0x30) >> 0x30))) != (s32)((s32)(1))) {
            func_00314450((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  func_002e48a0(0, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
            temp_16_3 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
            func_0011d140((u8 *)temp_16_3,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3FU;
            return;
        }
        break;
    case 0x3F:                                      /* switch 1 */
        if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                }
                goto block_83;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                    goto block_83;
                }
                if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  3);
                    if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0) << 0x30) >> 0x30))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_83;
                }
            } else {
                goto block_83;
            }
        } else {
block_83:
            if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
                var_16_4 = 0;
                for (; (s32)((s32)(((s64) (var_16_4 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                    func_002b2970(&sp390, 16.0f, 128.0f);
                    temp_19_3 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_4)) + (2))));
                    temp_18_4 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_4)) + (4))));
                    func_003191c0(arg0, sp390, (s64) (var_16_4 << 0x38) >> 0x38, temp_19_3, temp_18_4, 0, 0, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                    var_16_4 = (s64) ((var_16_4 + 1) << 0x30) >> 0x30;
                }
                func_002b2970(&sp388, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp388, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                var_19_4 = 0;
                for (; (s32)((s32)(((s64) (var_19_4 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                    temp_18_5 = (s64) (var_19_4 << 0x30) >> 0x30;
                    temp_16_4 = temp_18_5 * 0x17;
                    temp_20_3 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x184))))),  (s64) (var_19_4 << 0x38) >> 0x38));
                    func_002b2970(&sp380, (f32) (temp_16_4 + 0x149), 104.0f);
                    fclWriteColorBytes((u8 *)(&sp3F8), 0, 0, 0x99, 0xFFU);
                    fclWriteColorBytes((u8 *)(&sp3F4), 0, 0, 0x99, 0xFFU);
                    func_002b83e0((u8 *)temp_20_3, fclDrawPositionValue(fclPacketPosition(sp380)), fclPacketColor((u32)((s32) sp3F8)), fclPacketColor((u32)((s32) sp3F4)), 0xFFU, 0xFFU, 0x42000000, 159.0f, 3, 0, 0, 0);
                    var_20 = 0;
                    temp_18_6 = (u8 *)((s32)(temp_17) + (temp_18_5 * 4));
                    for (; (s32)((s32)(((s64) (var_20 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                    temp_16_5 = (s64) (var_20 << 0x30) >> 0x30;
                        sp120 = (u8*)((u8*)((u8*)(s32)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38))));
                        func_002b2970(&sp378, (f32)(s32)((temp_16_5 * 0x17) + 0x149), (f32) (temp_16_4 + 0x7F));
                        temp_16_6 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38));
                        temp_21_2 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38));
                        temp_22 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38));
                        temp_23 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38));
                        func_002b83e0((u8 *)((s16 *) sp120), fclDrawPositionValue(fclPacketPosition(sp378)), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_16_6) + (0x78))))))), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_21_2) + (0x78))))))), (*((u8 *)((u8 *)(temp_22) + (0x5E)))), (*((u8 *)((u8 *)(temp_23) + (0x5E)))), 0x42000000, (*((f32 *)((u8 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_6) + (0x154))))),  (s64) (var_20 << 0x38) >> 0x38)) + (4)))), 3, 0, 0, 0);
                        var_20 = (s64) ((var_20 + 1) << 0x30) >> 0x30;
                    }
                    temp_20_4 = (s64) (var_19_4 << 0x30) >> 0x30;
                    temp_18_7 = (s64) ((temp_20_4 + 0x25E) << 0x30) >> 0x30;
                    temp_16_7 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                    func_002b6a70(temp_18_7, 0U, 0xFF, 0, 3, 0);
                    func_002b6af0(temp_18_7, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, 0);
                    temp_20_5 = (temp_20_4 * 0x17) + 0x14E;
                    func_002b2970(&sp370, (f32) temp_20_5, 110.0f + (func_0046b2f0(temp_16_7) / 2.0f));
                    func_002b2970(&sp368, (f32) temp_20_5, 110.0f);
                    func_002b69f0(temp_18_7, (*(FclVec2f *)&sp370), (*(FclVec2f *)&sp368),  0,  3,  0);
                    func_0046d280(temp_16_7);
                    var_19_4 = (s64) ((var_19_4 + 1) << 0x30) >> 0x30;
                }
                func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x28C))))), 0);
                func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x290))))), 0);
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3CU;
                return;
            }
        }
        break;
    case 0x40:                                      /* switch 1 */
        (*((s8 *)((u8 *)(temp_17) + (0x129)))) = -1;
        var_16_5 = 0;
        for (; (s32)((s32)(((s64) (var_16_5 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
            func_0031d630(arg0, (s64) (var_16_5 << 0x38) >> 0x38, (*((s8 *)((u8 *)(temp_17) + (0x128)))), (*((s8 *)((u8 *)(temp_17) + (0x129)))), 0);
            var_16_5 = (s64) ((var_16_5 + 1) << 0x30) >> 0x30;
        }
        temp_16_8 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_8 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp1E8 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_4) + (0x38)))))));
        sp1EC = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_4) + (0x3C)))))));
        temp_16_9 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_8)));
        func_00275820(temp_16_9, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_8) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1E8, sp1EC, 0x422C0000);
        if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
            if (D_008C027A[0] & 0x1000) {
                (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16)((s16)(func_002b2d00((s8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 1, 0, (s64) (((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1) << 0x30) >> 0x30, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16)((s16)(func_002b2cb0((u8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 1, (s64) (((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1) << 0x30) >> 0x30, 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_10 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
                if (temp_16_10 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    var_16_6 = 0;
                    for (; (s32)((s32)(((s64) (var_16_6 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        func_002b2970(&sp360, 16.0f, 128.0f);
                        temp_19_4 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_6)) + (2))));
                        temp_18_9 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_6)) + (4))));
                        func_003191c0(arg0, sp360, (s64) (var_16_6 << 0x38) >> 0x38, temp_19_4, temp_18_9, 0, 1, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                        var_16_6 = (s64) ((var_16_6 + 1) << 0x30) >> 0x30;
                    }
                    func_002b2970(&sp358, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp358, 0, 1, 0, 0, 0);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    var_19_5 = 0;
                    for (; (s32)((s32)(((s64) (var_19_5 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        temp_16_11 = (s64) (var_19_5 << 0x30) >> 0x30;
                        temp_21_3 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x184))))),  (s64) (var_19_5 << 0x38) >> 0x38));
                        func_002b2970(&sp350, (f32)(s32)((temp_16_11 * 0x17) + 0x149), 104.0f);
                        fclWriteColorBytes((u8 *)(&sp3F0), 0, 0, 0x99, 0xFFU);
                        fclWriteColorBytes((u8 *)(&sp3EC), 0, 0, 0x99, 0xFFU);
                        func_002b83e0((u8 *)temp_21_3, fclDrawPositionValue(fclPacketPosition(sp350)), fclPacketColor((u32)((s32) sp3F0)), fclPacketColor((u32)((s32) sp3EC)), 0xFFU, 0xFFU, 0x42000000, 159.0f, 3, 0, 1, 0);
                        var_18_2 = 0;
                        temp_16_12 = (u8 *)((s32)(temp_17) + (temp_16_11 * 4));
                        for (; (s32)((s32)(((s64) (var_18_2 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            temp_30 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38));
                            func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38);
                            temp_22_2 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38));
                            temp_23_2 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38));
                            sp110 = (u8*)((u8*)((u8*)(s32)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38))));
                            sp100 = (u8*)((u8*)((u8*)(s32)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38))));
                            0;
                            func_002b83e0((u8 *)temp_30, fclDrawPositionValue(fclPacketPosition(0)), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_22_2) + (0x78))))))), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_23_2) + (0x78))))))), (*((u8 *)((u8 *)(sp110) + (0x5E)))), (*((u8 *)((u8 *)(sp100) + (0x5E)))), 0x42000000, (*((f32 *)((u8 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_12) + (0x154))))),  (s64) (var_18_2 << 0x38) >> 0x38)) + (4)))), 3, 0, 1, 0);
                            var_18_2 = (s64) ((var_18_2 + 1) << 0x30) >> 0x30;
                        }
                        temp_18_10 = (s64) (var_19_5 << 0x30) >> 0x30;
                        temp_16_13 = (s64) ((temp_18_10 + 0x25E) << 0x30) >> 0x30;
                        temp_21_4 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                        func_002b6a70(temp_16_13, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_13, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_11 = (temp_18_10 * 0x17) + 0x14E;
                        func_002b2970(&sp348, (f32) temp_18_11, 110.0f);
                        func_002b2970(&sp340, (f32) temp_18_11, 110.0f + (func_0046b2f0(temp_21_4) / 2.0f));
                        func_002b69f0(temp_16_13, (*(FclVec2f *)&sp348), (*(FclVec2f *)&sp340),  0,  3,  0);
                        func_0046d280(temp_21_4);
                        var_19_5 = (s64) ((var_19_5 + 1) << 0x30) >> 0x30;
                    }
                    func_00317240(arg0, 0, 0x42700000);
                    func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x28C))))), 1);
                    func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x290))))), 1);
                    (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x41U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_5 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
                    if (((*((s8 *)((u8 *)(temp_17) + (0x128)))) != temp_5) && ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) temp_5)) + (2)))) != 0)) {
                        func_0045af60(0, 0, 0, 1);
                        (*((s8 *)((u8 *)(temp_17) + (0x129)))) = (s8)((s8)((s8) (*((s16 *)((u8 *)(temp_17) + (0x11E))))));
                        func_002b2970(&sp338, -380.0f, 81.0f);
                        func_002b2970(&sp330, (*((f32 *)((u8 *)(&D_00640C18) + (0)))), (*((f32 *)((u8 *)(&D_00640C18) + (4)))));
                        func_0031cce0(arg0, (*((s8 *)((u8 *)(temp_17) + (0x129)))), sp338, sp330);
                        var_19_6 = 0;
                        for (; (s32)((s32)(((s64) (var_19_6 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        temp_18_12 = (s64) (var_19_6 << 0x30) >> 0x30;
                            temp_16_14 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                            if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s64) ((temp_16_14 + 1) << 0x38) >> 0x38)) + (temp_16_14 * 0xC) + temp_18_12)) + (0x14)))) > 0) {
                                func_002b2970(&sp328, (f32) 0x149, 128.0f);
                                temp_18_13 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_19_6)) + (2)))))));
                                func_0031ac10(arg0, sp328, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_19_6 << 0x38) >> 0x38, temp_18_13, (*((u8 *)((u8 *)(func_002e48a0((s64) ((temp_16_14 + 1) << 0x38) >> 0x38, var_19_6)) + (4)))), 3, 0, 1, 0xCC);
                            }
                            temp_16_15 = (s64) (var_19_6 << 0x30) >> 0x30;
                            temp_21_5 = temp_16_15 * 0x17;
                            temp_18_14 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x184))))),  (s64) (var_19_6 << 0x38) >> 0x38));
                            func_002b2970(&sp320, (f32) (temp_21_5 + 0x149), 104.0f);
                            fclWriteColorBytes((u8 *)(&sp3E8), 0, 0, 0x99, 0xFFU);
                            fclWriteColorBytes((u8 *)(&sp3E4), 0, 0, 0x99, 0xFFU);
                            func_002b83e0((u8 *)temp_18_14, fclDrawPositionValue(fclPacketPosition(sp320)), fclPacketColor((u32)((s32) sp3E8)), fclPacketColor((u32)((s32) sp3E4)), 0xFFU, 0xFFU, 0x42000000, 159.0f, 3, 0, 1, 0);
                            var_18_3 = 0;
                            temp_16_16 = (u8 *)((s32)(temp_17) + (temp_16_15 * 4));
                            spF0 = temp_21_5 + 0x7F;
                            for (; (s32)((s32)(((s64) (var_18_3 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            temp_21_6 = (s64) (var_18_3 << 0x30) >> 0x30;
                                spE0 = (u8*)((u8*)((u8*)(s32)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38))));
                                func_002b2970(&sp318, (f32)(s32)((temp_21_6 * 0x17) + 0x149), (f32) spF0);
                                temp_21_7 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38));
                                temp_22_3 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38));
                                temp_23_3 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38));
                                temp_30_2 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38));
                                func_002b83e0((u8 *)((s16 *) spE0), fclDrawPositionValue(fclPacketPosition(sp318)), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_21_7) + (0x78))))))), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_22_3) + (0x78))))))), (*((u8 *)((u8 *)(temp_23_3) + (0x5E)))), (*((u8 *)((u8 *)(temp_30_2) + (0x5E)))), 0x42000000, (*((f32 *)((u8 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_16_16) + (0x154))))),  (s64) (var_18_3 << 0x38) >> 0x38)) + (4)))), 3, 0, 1, 0);
                                var_18_3 = (s64) ((var_18_3 + 1) << 0x30) >> 0x30;
                            }
                            temp_16_17 = (s64) (var_19_6 << 0x30) >> 0x30;
                            temp_18_15 = (s64) ((temp_16_17 + 0x25E) << 0x30) >> 0x30;
                            temp_21_8 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                            func_002b6a70(temp_18_15, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_18_15, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_22_4 = (temp_16_17 * 0x17) + 0x14E;
                            func_002b2970(&sp310, (f32) temp_22_4, 110.0f);
                            func_002b2970(&sp308, (f32) temp_22_4, 110.0f + (func_0046b2f0(temp_21_8) / 2.0f));
                            func_002b69f0(temp_18_15, (*(FclVec2f *)&sp310), (*(FclVec2f *)&sp308),  0,  3,  0);
                            func_0046d280(temp_21_8);
                            temp_18_16 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                            if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s64) ((temp_18_16 + 1) << 0x38) >> 0x38)) + (temp_18_16 * 0xC) + temp_16_17)) + (0x14)))) > 0) {
                                temp_16_18 = (u16 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_19_6));
                                temp_21_9 = (u16 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128))))));
                                temp_22_5 = (u16 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x129))))));
                                func_002f9c30(temp_16_18, (u8 *)temp_21_9, (u8 *)temp_22_5, (u8 *)func_002e48a0(0, var_19_6), NULL, NULL, NULL, 3, (s64) ((temp_18_16 + 1) << 0x38) >> 0x38, (s64) (var_19_6 << 0x38) >> 0x38);
                            }
                            var_19_6 = (s64) ((var_19_6 + 1) << 0x30) >> 0x30;
                        }
                        func_002b2970(&sp300, (f32) 0x149, 104.0f);
                        func_0031fa20(arg0, sp300, 3, 0);
                        func_003205f0(arg0, 0x95, 0x94);
                        func_0031e320(arg0, (*((s8 *)((u8 *)(temp_17) + (0x129)))));
                        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x43U;
                        return;
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024C[0] & 0x80) {
                    temp_16_19 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
                    if (temp_16_19 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                        func_0045af60(0, 1, 0, 3);
                        var_16_7 = 0;
                        for (; (s32)((s32)(((s64) (var_16_7 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            func_002b2970(&sp2F8, 16.0f, 128.0f);
                            temp_19_5 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_7)) + (2))));
                            temp_18_17 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_7)) + (4))));
                            func_003191c0(arg0, sp2F8, (s64) (var_16_7 << 0x38) >> 0x38, temp_19_5, temp_18_17, 0, 1, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                            var_16_7 = (s64) ((var_16_7 + 1) << 0x30) >> 0x30;
                        }
                        func_002b2970(&sp2F0, 16.0f, 104.0f);
                        func_0031e5b0(arg0, sp2F0, 0, 1, 0, 0, 0);
                        var_20_2 = 0;
                        for (; (s32)((s32)(((s64) (var_20_2 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                            temp_18_18 = (s64) (var_20_2 << 0x30) >> 0x30;
                            temp_16_20 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x184))))),  (s64) (var_20_2 << 0x38) >> 0x38));
                            func_002b2970(&sp2E8, (f32)(s32)((temp_18_18 * 0x17) + 0x149), 104.0f);
                            fclWriteColorBytes((u8 *)(&sp3E0), 0, 0, 0x99, 0xFFU);
                            fclWriteColorBytes((u8 *)(&sp3DC), 0, 0, 0x99, 0xFFU);
                            func_002b83e0((u8 *)temp_16_20, fclDrawPositionValue(fclPacketPosition(sp2E8)), fclPacketColor((u32)((s32) sp3E0)), fclPacketColor((u32)((s32) sp3DC)), 0xFFU, 0xFFU, 0x42000000, 159.0f, 3, 0, 1, 0);
                            var_19_7 = 0;
                            temp_18_19 = (u8 *)((s32)(temp_17) + (temp_18_18 * 4));
                            for (; (s32)((s32)(((s64) (var_19_7 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                                temp_23_4 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38));
                                func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38);
                                temp_21_10 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38));
                                temp_22_6 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38));
                                temp_30_3 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38));
                                spD0 = (u8*)((u8*)((u8*)(s32)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38))));
                                0;
                                func_002b83e0((u8 *)temp_23_4, fclDrawPositionValue(fclPacketPosition(0)), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_21_10) + (0x78))))))), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_22_6) + (0x78))))))), (*((u8 *)((u8 *)(temp_30_3) + (0x5E)))), (*((u8 *)((u8 *)(spD0) + (0x5E)))), 0x42000000, (*((f32 *)((u8 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_19) + (0x154))))),  (s64) (var_19_7 << 0x38) >> 0x38)) + (4)))), 3, 0, 1, 0);
                                var_19_7 = (s64) ((var_19_7 + 1) << 0x30) >> 0x30;
                            }
                            temp_19_6 = (s64) (var_20_2 << 0x30) >> 0x30;
                            temp_16_21 = (s64) ((((s64) ((temp_19_6 + 0x6A) << 0x38) >> 0x38) + 0x1F4) << 0x30) >> 0x30;
                            temp_18_20 = (s32)((s32)(func_0046d200(func_00331560(), 0x39)));
                            func_002b6a70(temp_16_21, 0xFFU, 0, 0, 3, 0);
                            func_002b6af0(temp_16_21, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                            temp_19_7 = (temp_19_6 * 0x17) + 0x14E;
                            func_002b2970(&sp2E0, (f32) temp_19_7, 110.0f);
                            func_002b2970(&sp2D8, (f32) temp_19_7, 110.0f + (func_0046b2f0(temp_18_20) / 2.0f));
                            func_002b69f0(temp_16_21, (*(FclVec2f *)&sp2E0), (*(FclVec2f *)&sp2D8),  0,  3,  0);
                            func_0046d280(temp_18_20);
                            var_20_2 = (s64) ((var_20_2 + 1) << 0x30) >> 0x30;
                        }
                        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x41U;
                        return;
                    }
                } else if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 0, 0xFF);
                    temp_2_5 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x128)))))));
                    (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16) temp_2_5;
                    func_0031ddf0(arg0, temp_2_5, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    func_002b2970(&sp2D0, (*((f32 *)((u8 *)(&D_00640C10) + (0)))), (*((f32 *)((u8 *)(&D_00640C10) + (4)))));
                    func_002b2970(&sp2C8, -380.0f, (*((f32 *)((u8 *)(&D_00640C10) + (4)))));
                    func_0031c2b0(arg0, (*((s8 *)((u8 *)(temp_17) + (0x128)))), sp2D0, sp2C8);
                    func_0010b5b0();
                    var_20_3 = 0;
                    for (; (s32)((s32)(((s64) (var_20_3 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        var_19_8 = 0;
                        temp_3_3 = (s64) (var_20_3 << 0x30) >> 0x30;
                        temp_18_21 = (u8 *)((s32)(temp_17) + (temp_3_3 * 4));
                        for (; (s32)((s32)(((s64) (var_19_8 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        temp_21_11 = (s64) (var_19_8 << 0x30) >> 0x30;
                            temp_22_7 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_21) + (0x154))))),  (s64) (var_19_8 << 0x38) >> 0x38));
                            func_002b2970(&sp2C0, (f32)(s32)((temp_21_11 * 0x17) + 0x149), (f32)(s32)((temp_3_3 * 0x17) + 0x7F));
                            temp_21_12 = (s16 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_21) + (0x154))))),  (s64) (var_19_8 << 0x38) >> 0x38));
                            fclWriteColorBytes((u8 *)(&sp3D8), 0, 0, 0x99, 0xA5U);
                            func_002b83e0((u8 *)temp_22_7, fclDrawPositionValue(fclPacketPosition(sp2C0)), fclPacketColor((u32)(((*((s32 *)((u8 *)(temp_21_12) + (0x78))))))), fclPacketColor((u32)((s32) sp3D8)), 0xA5U, 0xA5U, 0x42000000, (*((f32 *)((u8 *)(func_0034ae50((u8 *)((*((s32 *)((u8 *)(temp_18_21) + (0x154))))),  (s64) (var_19_8 << 0x38) >> 0x38)) + (4)))), 6, 0, 1, 1);
                            var_19_8 = (s64) ((var_19_8 + 1) << 0x30) >> 0x30;
                        }
                        var_20_3 = (s64) ((var_20_3 + 1) << 0x30) >> 0x30;
                    }
                    func_002b6a70(0x7E, 0U, 0xFF, 0, 3, 3);
                    func_002b68d0(0x7E, 0, 0);
                    (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x3CU;
                    return;
                }
            }
        }
        break;
    case 0x41:                                      /* switch 1 */
        temp_2_6 = (u8 *)(func_002b6150(0x7C));
        sp1E0 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_6) + (0x38)))))));
        sp1E4 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_6) + (0x3C)))))));
        temp_16_22 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_22, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1E0, sp1E4, 0x422C0000);
        if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1) << 0x30) >> 0x30))) != (s32)((s32)(1))) {
            func_00314450((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  func_002e48a0(0, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
            temp_16_23 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
            func_0011d140((u8 *)temp_16_23,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x42U;
            return;
        }
        break;
    case 0x42:                                      /* switch 1 */
        temp_2_7 = (u8 *)(func_002b6150(0x7C));
        sp1D8 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_7) + (0x38)))))));
        sp1DC = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_7) + (0x3C)))))));
        temp_16_24 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_24, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1D8, sp1DC, 0x422C0000);
        if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                }
                goto block_166;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                    goto block_166;
                }
                if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  3);
                    if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0) << 0x30) >> 0x30))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_166;
                }
            } else {
                goto block_166;
            }
        } else {
block_166:
            if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
                var_16_8 = 0;
                for (; (s32)((s32)(((s64) (var_16_8 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                    func_002b2970(&sp2B8, 16.0f, 128.0f);
                    temp_19_8 = (*((u16 *)((u8 *)(func_002e48a0(0, var_16_8)) + (2))));
                    temp_18_22 = (*((u8 *)((u8 *)(func_002e48a0(0, var_16_8)) + (4))));
                    func_003191c0(arg0, sp2B8, (s64) (var_16_8 << 0x38) >> 0x38, temp_19_8, temp_18_22, 0, 0, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                    var_16_8 = (s64) ((var_16_8 + 1) << 0x30) >> 0x30;
                }
                func_002b2970(&sp2B0, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp2B0, 0, 0, 0, 0, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_003218a0(arg0, 0);
                func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x28C))))), 0);
                func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x290))))), 0);
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x40U;
                return;
            }
        }
        break;
    case 0x43:                                      /* switch 1 */
        func_003233d0(arg0);
        temp_16_25 = (*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E))));
        temp_18_23 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_8 = (u8 *)(func_002b6150(0x7C));
        sp1D0 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_8) + (0x38)))))));
        sp1D4 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_8) + (0x3C)))))));
        temp_16_26 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_25)));
        func_00275820(temp_16_26, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_23) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1D0, sp1D4, 0x422C0000);
        temp_16_27 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_24 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_9 = (u8 *)(func_002b6150(0x7D));
        sp1C8 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_9) + (0x38)))))));
        sp1CC = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_9) + (0x3C)))))));
        temp_16_28 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27)));
        func_00275820(temp_16_28, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_24) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1C8, sp1CC, 0x422C0000);
        if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
            if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1C7)) + (0x10)))), 0) << 0x30) >> 0x30))) == (s32)((s32)(1))) {
                func_00324410(arg0, 0x1C7, 0);
                func_00324410(arg0, 0x2E8, 1);
            }
            if (D_008C027A[0] & 0x1000) {
                (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16)((s16)(func_002b2d00((s8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 1, 0, (s64) (((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1) << 0x30) >> 0x30, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16)((s16)(func_002b2cb0((u8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 1, (s64) (((*((s32 *)((u8 *)(func_002e4870(0)) + (8)))) - 1) << 0x30) >> 0x30, 0, 2)));
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                temp_16_29 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
                if (temp_16_29 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
                    func_0045af60(0, 1, 0, 3);
                    var_18_4 = 0;
                    for (; (s32)((s32)(((s64) (var_18_4 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        func_002b2970(&sp2A8, (f32) 0x149, 128.0f);
                        temp_16_30 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_4)) + (2)))))));
                        func_0031ac10(arg0, sp2A8, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_18_4 << 0x38) >> 0x38, temp_16_30, (*((u8 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_4)) + (4)))), 0, 1, 1, 0xCC);
                        func_002b2970(&sp2A0, 16.0f, 128.0f);
                        temp_19_9 = (*((u16 *)((u8 *)(func_002e48a0(0, var_18_4)) + (2))));
                        temp_16_31 = (*((u8 *)((u8 *)(func_002e48a0(0, var_18_4)) + (4))));
                        func_003191c0(arg0, sp2A0, (s64) (var_18_4 << 0x38) >> 0x38, temp_19_9, temp_16_31, 0, 1, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                        var_18_4 = (s64) ((var_18_4 + 1) << 0x30) >> 0x30;
                    }
                    func_002b2970(&sp298, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp298, 0, 1, 0, 0, 0);
                    func_002b2970(&sp290, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp290, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0x42700000);
                    func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x28C))))), 1);
                    func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x290))))), 1);
                    (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x44U;
                    return;
                }
            } else {
                if (D_008C024E[0] & 0x40) {
                    temp_3_4 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
                    if ((*((s8 *)((u8 *)(temp_17) + (0x128)))) != temp_3_4) {
                        temp_2_10 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                        if ((temp_2_10 != temp_3_4) && ((*((s8 *)((u8 *)((func_002e4870((s8) ((s64) ((temp_2_10 + 1) << 0x38) >> 0x38)) + ((*((s8 *)((u8 *)(temp_17) + (0x129)))) * 0xC) + (*((s16 *)((u8 *)(temp_17) + (0x11E)))))) + (0x14)))) > 0)) {
                            func_0045af60(0, 0, 0, 1);
                            var_18_5 = 0;
                            for (; (s32)((s32)(((s64) (var_18_5 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                                func_002b2970(&sp288, (f32) 0x149, 128.0f);
                                temp_16_32 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_5)) + (2)))))));
                                func_0031ac10(arg0, sp288, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_18_5 << 0x38) >> 0x38, temp_16_32, (*((u8 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_5)) + (4)))), 0, 1, 1, 0xCC);
                                func_002b2970(&sp280, 16.0f, 128.0f);
                                temp_19_10 = (*((u16 *)((u8 *)(func_002e48a0(0, var_18_5)) + (2))));
                                temp_16_33 = (*((u8 *)((u8 *)(func_002e48a0(0, var_18_5)) + (4))));
                                func_003191c0(arg0, sp280, (s64) (var_18_5 << 0x38) >> 0x38, temp_19_10, temp_16_33, 0, 1, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                                var_18_5 = (s64) ((var_18_5 + 1) << 0x30) >> 0x30;
                            }
                            func_002b2970(&sp278, 16.0f, 104.0f);
                            func_0031e5b0(arg0, sp278, 0, 1, 0, 0, 0);
                            func_002b2970(&sp270, (f32) 0x149, 104.0f);
                            func_0031fa20(arg0, sp270, 0, 1);
                            func_00316470(arg0, 1, 1);
                            func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                            func_00317240(arg0, 0, 0);
                            func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x28C))))), 1);
                            func_002b6140((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x290))))), 1);
                            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x47U;
                            return;
                        }
                    }
                    func_0045af60(0, 0, 0, 8);
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) (*((s16 *)((u8 *)(temp_17) + (0x11E)))), 0, 0xFF);
                    temp_2_11 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                    (*((s16 *)((u8 *)(temp_17) + (0x11E)))) = (s16) temp_2_11;
                    func_0031ddf0(arg0, temp_2_11, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_002b2970(&sp268, (*((f32 *)((u8 *)(&D_00640C18) + (0)))), (*((f32 *)((u8 *)(&D_00640C18) + (4)))));
                    func_002b2970(&sp260, -380.0f, 81.0f);
                    func_0031cce0(arg0, (*((s8 *)((u8 *)(temp_17) + (0x129)))), sp268, sp260);
                    func_002b2970(&sp258, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp258, 0, 1);
                    var_18_6 = 0;
                    for (; (s32)((s32)(((s64) (var_18_6 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                        func_002b2970(&sp250, (f32) 0x149, 128.0f);
                        temp_16_34 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_6)) + (2)))))));
                        func_0031ac10(arg0, sp250, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_18_6 << 0x38) >> 0x38, temp_16_34, (*((u8 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_18_6)) + (4)))), 0, 1, 1, 0xCC);
                        var_18_6 = (s64) ((var_18_6 + 1) << 0x30) >> 0x30;
                    }
                    func_003218a0(arg0, 3);
                    func_003205f0(arg0, 0x94, 0x95);
                    (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x40U;
                    return;
                }
            }
        }
        break;
    case 0x44:                                      /* switch 1 */
        temp_2_12 = (u8 *)(func_002b6150(0x7C));
        sp1C0 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_12) + (0x38)))))));
        sp1C4 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_12) + (0x3C)))))));
        temp_16_35 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_35, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1C0, sp1C4, 0x422C0000);
        temp_18_25 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_13 = (u8 *)(func_002b6150(0x7D));
        sp1B8 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_13) + (0x38)))))));
        sp1BC = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_13) + (0x3C)))))));
        temp_16_36 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_36, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_25) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1B8, sp1BC, 0x422C0000);
        if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1) << 0x30) >> 0x30))) != (s32)((s32)(1))) {
            func_00314450((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  func_002e48a0(0, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))),  0,  0);
            func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
            temp_16_37 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
            func_0011d140((u8 *)temp_16_37,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x45U;
            return;
        }
        break;
    case 0x45:                                      /* switch 1 */
        temp_2_14 = (u8 *)(func_002b6150(0x7C));
        sp1B0 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_14) + (0x38)))))));
        sp1B4 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_14) + (0x3C)))))));
        temp_16_38 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_38, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1B0, sp1B4, 0x422C0000);
        temp_18_26 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_15 = (u8 *)(func_002b6150(0x7D));
        sp1A8 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_15) + (0x38)))))));
        sp1AC = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_15) + (0x3C)))))));
        temp_16_39 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU)));
        func_00275820(temp_16_39, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_26) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1A8, sp1AC, 0x422C0000);
        if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
            }
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  0);
                } else {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                }
                goto block_215;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                    goto block_215;
                }
                if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(5)) {
                    func_0045af60(0, 1, 0, 4);
                    func_00314670((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  3);
                    if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x1E4)) + (0x10)))), 0) << 0x30) >> 0x30))) == (s32)((s32)(1))) {
                        func_002b6a70(0x1E4, (*((u8 *)((u8 *)(func_002b6150(0x1E4)) + (0x6E)))), 0, 0, 0xA, 0);
                    }
                    goto block_215;
                }
            } else {
                goto block_215;
            }
        } else {
block_215:
            if (((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) < (s32)((s32)(0))) || ((s32)((s32)(func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))) >= (s32)((s32)(6)))) {
                func_00316470(arg0, 1, 0);
                func_00316e80(arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                var_19_9 = 0;
                for (; (s32)((s32)(((s64) (var_19_9 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
                temp_16_40 = (s64) (var_19_9 << 0x30) >> 0x30;
                    func_002b2970(&sp248, 16.0f, 128.0f);
                    temp_21_13 = (*((u16 *)((u8 *)(func_002e48a0(0, var_19_9)) + (2))));
                    temp_18_27 = (*((u8 *)((u8 *)(func_002e48a0(0, var_19_9)) + (4))));
                    func_003191c0(arg0, sp248, (s64) (var_19_9 << 0x38) >> 0x38, temp_21_13, temp_18_27, 0, 0, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                    temp_18_28 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                    if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s64) ((temp_18_28 + 1) << 0x38) >> 0x38)) + (temp_18_28 * 0xC) + temp_16_40)) + (0x14)))) > 0) {
                        func_002b2970(&sp240, (f32) 0x149, 128.0f);
                        temp_16_41 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_19_9)) + (2)))))));
                        func_0031ac10(arg0, sp240, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_19_9 << 0x38) >> 0x38, temp_16_41, (*((u8 *)((u8 *)(func_002e48a0((s64) ((temp_18_28 + 1) << 0x38) >> 0x38, var_19_9)) + (4)))), 0, 0, 1, 0xCC);
                    }
                    var_19_9 = (s64) ((var_19_9 + 1) << 0x30) >> 0x30;
                }
                func_002b2970(&sp238, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp238, 0, 0, 0, 0, 0);
                func_002b2970(&sp230, (f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp230, 0, 0);
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x43U;
                return;
            }
        }
        break;
    case 0x47:                                      /* switch 1 */
        temp_16_42 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_29 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_16 = (u8 *)(func_002b6150(0x7C));
        sp1A0 = *((f32 *)((u8 *)(temp_2_16) + (0x38)));
        sp1A4 = *((f32 *)((u8 *)(temp_2_16) + (0x3C)));
        temp_16_43 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_42)));
        func_00275820(temp_16_43, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_29) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp1A0, sp1A4, 43.0f);
        temp_16_44 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_30 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_17 = (u8 *)(func_002b6150(0x7D));
        sp198 = *((f32 *)((u8 *)(temp_2_17) + (0x38)));
        sp19C = *((f32 *)((u8 *)(temp_2_17) + (0x3C)));
        temp_16_45 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_44)));
        func_00275820(temp_16_45, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_30) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp198, sp19C, 43.0f);
        if ((s32)((s32)(((s64) (func_002b6970((*((s16 *)((u8 *)(func_002b6150(0x21C)) + (0x10)))), 1) << 0x30) >> 0x30))) != (s32)((s32)(1))) {
            (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = (s8)((s8)((s8) ((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1)));
            temp_2_18 = (s16)((s16)((s16)((*((s16 *)((u8 *)(temp_17) + (0x11E)))))));
            (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8) temp_2_18;
            temp_16_46 = (s64) ((s64) temp_2_18 << 0x38) >> 0x38;
            temp_18_31 = (u16 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), temp_16_46));
            temp_16_47 = (u8 *)(func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + ((s64) (temp_16_46 << 0x38) >> 0x38));
            temp_19_11 = (s64)((s64)((s64) (func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))) << 0x30) >> 0x30));
            func_003144d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  temp_18_31,  (*((s8 *)((u8 *)(temp_16_47) + (0x2E4)))),  func_00311930(temp_19_11, (u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))),  0),  1);
            temp_16_48 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
            func_0011d140((u8 *)temp_16_48,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            temp_16_49 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (4)))))));
            if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_49))) {
                temp_16_50 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                func_0011d140((u8 *)temp_16_50,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
            }
            func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
            func_00325450(arg0, 4, 0);
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x46U;
            return;
        }
        break;
    case 0x46:                                      /* switch 1 */
        temp_16_51 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_32 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_19 = (u8 *)(func_002b6150(0x7C));
        sp190 = *((f32 *)((u8 *)(temp_2_19) + (0x38)));
        sp194 = *((f32 *)((u8 *)(temp_2_19) + (0x3C)));
        temp_16_52 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_51)));
        func_00275820(temp_16_52, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_32) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp190, sp194, 43.0f);
        temp_16_53 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_33 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_20 = (u8 *)(func_002b6150(0x7D));
        sp188 = *((f32 *)((u8 *)(temp_2_20) + (0x38)));
        sp18C = *((f32 *)((u8 *)(temp_2_20) + (0x3C)));
        temp_16_54 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_53)));
        func_00275820(temp_16_54, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_33) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp188, sp18C, 43.0f);
        if ((s32)((s8)func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))) == (s32)(0xD)) {
            if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                func_0011caf0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
            }
            if (D_008C024E[0] & 0x40) {
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x48U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            temp_17 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
            if (D_008C024E[0] & 0x80) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(0))) {
                    func_0011c630(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))));
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))), 0);
                    return;
                }
                func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))), 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if ((s32)((s32)(func_0011c610(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))))))) == (s32)((s32)(1))) {
                    func_0011c6e0(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))), 1);
                    func_00314740((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4EU;
                func_00314670((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  0xB);
                func_00317240(arg0, 1, 0);
                func_00325450(arg0, 4, 1);
                return;
            }
            if (D_008C024E[0] & 8) {
                if ((*((s8 *)((u8 *)(temp_17) + (0x122)))) != 3) {
                    func_0045af60(0, 2, 0, 5);
                }
                (*((s8 *)((u8 *)(temp_17) + (0x122)))) = (s8)((s8)(func_002b2cb0((u8) (*((s8 *)((u8 *)(temp_17) + (0x122)))), 1, 3, 0, 1)));
                s0 = s0 = func_002b6150(0x152);
                func_002b2970(&sp228, (f32)(s32)(((*((s8 *)((u8 *)(temp_17) + (0x122)))) * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp228),  1,  4,  0);
                s0 = s0 = func_002b6150(0x2E0);
                func_002b2970(&sp220, (f32)(s32)(((*((s8 *)((u8 *)(temp_17) + (0x122)))) * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp220),  1,  4,  0);
                temp_4 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x122)))))));
                switch (temp_4) {                   /* switch 3; irregular */
                case 0:                             /* switch 3 */
                    temp_16_55 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_55,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128))))),  0,  0,  1);
                    return;
                case 1:                             /* switch 3 */
                    temp_16_56 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_56,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x129))))),  0,  0,  1);
                    return;
                case 2:                             /* switch 3 */
                    temp_16_57 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_57,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))),  0,  0,  1);
                    return;
                case 3:                             /* switch 3 */
                    temp_16_58 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_58,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_59 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_59))) {
                        temp_16_60 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                        func_0011d140((u8 *)temp_16_60,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_61 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x2FA)))))));
                    temp_18_34 = (u16 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) temp_16_61));
                    temp_16_62 = (u8 *)(func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + ((s64) ((s64) temp_16_61 << 0x38) >> 0x38));
                    temp_19_12 = (s64)((s64)((s64) (func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))) << 0x30) >> 0x30));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  temp_18_34,  (*((s8 *)((u8 *)(temp_16_62) + (0x2E4)))),  func_00311930(temp_19_12, (u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))),  0),  1);
                    return;
                }
            } else if (D_008C024E[0] & 4) {
                if ((*((s8 *)((u8 *)(temp_17) + (0x122)))) != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                (*((s8 *)((u8 *)(temp_17) + (0x122)))) = (s8)((s8)(func_002b2d00((*((s8 *)((u8 *)(temp_17) + (0x122)))), 1, 0, 3, 1)));
                s0 = s0 = func_002b6150(0x152);
                func_002b2970(&sp218, (f32)(s32)(((*((s8 *)((u8 *)(temp_17) + (0x122)))) * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x152, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp218),  1,  4,  0);
                s0 = s0 = func_002b6150(0x2E0);
                func_002b2970(&sp210, (f32)(s32)(((*((s8 *)((u8 *)(temp_17) + (0x122)))) * 0x6B) + 0x6A), 16.0f);
                0;
                func_002b69f0(0x2E0, (*(FclVec2f *)(s0 + 0x38)), (*(FclVec2f *)&sp210),  1,  4,  0);
                temp_4_2 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x122)))))));
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_16_63 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_63,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x128))))),  0,  0,  1);
                    return;
                case 1:                             /* switch 4 */
                    temp_16_64 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_64,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_17) + (0x129))))),  0,  0,  1);
                    return;
                case 2:                             /* switch 4 */
                    temp_16_65 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_65,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)((u32)(temp_17) + (0x148U)))))),  func_002e48a0(0, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))),  0,  0,  1);
                    return;
                case 3:                             /* switch 4 */
                    temp_16_66 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                    func_0011d140((u8 *)temp_16_66,  func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    temp_16_67 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (4)))))));
                    if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_16_67))) {
                        temp_16_68 = (s32)((s32)((s32)(func_003147d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))))));
                        func_0011d140((u8 *)temp_16_68,  func_002b2a30(0x14, 0x14, 0x14, 0xFFU));
                    }
                    temp_16_69 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x2FA)))))));
                    temp_18_35 = (u16 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) temp_16_69));
                    temp_16_70 = (u8 *)(func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + ((s64) ((s64) temp_16_69 << 0x38) >> 0x38));
                    temp_19_13 = (s64)((s64)((s64) (func_00247770((*((u8 *)((u8 *)((((*((u16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2)))) * 0xE) + ((s32)iGpffffb3d4))) + (2))))) << 0x30) >> 0x30));
                    func_003144d0((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  temp_18_35,  (*((s8 *)((u8 *)(temp_16_70) + (0x2E4)))),  func_00311930(temp_19_13, (u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))),  0),  1);
                    return;
                }
            }
        }
        break;
    case 0x4E:                                      /* switch 1 */
        temp_16_71 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002b6150(0x7C)) + (0x6E)))))));
        temp_18_36 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_21 = (u8 *)(func_002b6150(0x7C));
        sp180 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_21) + (0x38)))))));
        sp184 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_21) + (0x3C)))))));
        temp_16_72 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_71)));
        func_00275820(temp_16_72, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_36) + (0x128)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp180, sp184, 0x422C0000);
        temp_16_73 = (*((u8 *)((u8 *)(func_002b6150(0x7D)) + (0x6E))));
        temp_18_37 = (u8 *)((*((u8 **)((u8 *)(arg0) + (0x38)))));
        temp_2_22 = (u8 *)(func_002b6150(0x7D));
        sp178 = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_22) + (0x38)))))));
        sp17C = (f32)(s32)((f32)(s32)((f32)(s32)((*((f32 *)((u8 *)(temp_2_22) + (0x3C)))))));
        temp_16_74 = (s32)((s32)(func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_73)));
        func_00275820(temp_16_74, 0, 2, ((s32)iGpffffb440) + ((*((u16 *)((u8 *)(func_002e48a0(0, (s64) (*((s8 *)((u8 *)(temp_18_37) + (0x129)))))) + (2)))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp178, sp17C, 0x422C0000);
        if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(0xE)) {
            func_00316470(arg0, 1, 0);
            func_00316e80(arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            var_19_10 = 0;
            for (; (s32)((s32)(((s64) (var_19_10 << 0x30) >> 0x30))) < (s32)((s32)((func_0010b5b0() & 0xFFFF)));) {
            temp_16_75 = (s64) (var_19_10 << 0x30) >> 0x30;
                func_002b2970(&sp208, 16.0f, 128.0f);
                temp_21_14 = (*((u16 *)((u8 *)(func_002e48a0(0, var_19_10)) + (2))));
                temp_18_38 = (*((u8 *)((u8 *)(func_002e48a0(0, var_19_10)) + (4))));
                func_003191c0(arg0, sp208, (s64) (var_19_10 << 0x38) >> 0x38, temp_21_14, temp_18_38, 0, 0, (*((s8 *)((u8 *)(func_002e4870(0)) + (8)))));
                temp_18_39 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x129)))))));
                if ((*((s8 *)((u8 *)((func_002e4870((s8) ((s64) ((temp_18_39 + 1) << 0x38) >> 0x38)) + (temp_18_39 * 0xC) + temp_16_75)) + (0x14)))) > 0) {
                    func_002b2970(&sp200, (f32) 0x149, 128.0f);
                    temp_16_76 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, var_19_10)) + (2)))))));
                    func_0031ac10(arg0, sp200, (*((s8 *)((u8 *)(temp_17) + (0x129)))), (s64) (var_19_10 << 0x38) >> 0x38, temp_16_76, (*((u8 *)((u8 *)(func_002e48a0((s64) ((temp_18_39 + 1) << 0x38) >> 0x38, var_19_10)) + (4)))), 0, 0, 1, 0xCC);
                }
                var_19_10 = (s64) ((var_19_10 + 1) << 0x30) >> 0x30;
            }
            func_002b2970(&sp1F8, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1F8, 0, 0, 0, 0, 0);
            func_002b2970(&sp1F0, (f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1F0, 0, 0);
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x43U;
            return;
        }
        break;
    case 0x48:                                      /* switch 1 */
        temp_16_77 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2)))))));
        temp_18_40 = (u8)((u8)((u8)((*((u8 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (4)))))));
        if ((s32)((s32)((func_00104c70(1) & 0xFF))) < (s32)((s32)((s32) temp_18_40))) {
            func_00310960(arg0, 0x26, 0);
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4AU;
            return;
        }
        if ((s32)((s32)(func_002e53b0(0, (*((s16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2))))))) == (s32)((s32)(1))) {
            func_00310960(arg0, 0x27, 0);
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4AU;
            return;
        }
        if ((s32)((s32)(((s64) (func_00105f50(temp_16_77) << 0x38) >> 0x38))) == (s32)((s32)(0))) {
            func_00310a10(arg0, temp_16_77);
        } else {
            func_00310960(arg0, (s64) ((((s64) (func_00105f50(temp_16_77) << 0x38) >> 0x38) + 0x2E) << 0x38) >> 0x38, 1);
        }
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x49U;
        return;
    case 0x49:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*((s8 *)((u8 *)(temp_17) + (0xD))))))) != (s32)((s32)(0))) {
            func_002bbcf0((*((s8 *)((u8 *)(temp_17) + (0xD)))));
            return;
        }
        if ((s32)((s32)(func_002bb1c0((*((s8 *)((u8 *)(temp_17) + (0xD))))))) == (s32)((s32)(0))) {
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4CU;
            func_00122520(1, 0xA);
        } else {
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x46U;
        }
        func_002bb550((*((s8 *)((u8 *)(temp_17) + (0xD)))));
        return;
    case 0x4A:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*((s8 *)((u8 *)(temp_17) + (0xD))))))) != (s32)((s32)(0))) {
            func_002bbcf0((*((s8 *)((u8 *)(temp_17) + (0xD)))));
            return;
        }
        func_002bb550((*((s8 *)((u8 *)(temp_17) + (0xD)))));
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x46U;
        return;
    case 0x4C:                                      /* switch 1 */
        if ((s32)((s32)(func_00122720())) != (s32)((s32)(0))) {
            func_00314670((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))),  0xB);
            func_00314680((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148))))));
            func_00325450(arg0, 4, 1);
            var_16_9 = 0;
loop_295:
            if (((s64) (var_16_9 << 0x30) >> 0x30) < 0x30C) {
                func_002b68d0(var_16_9, 0, 1);
                var_16_9 = (s64) ((var_16_9 + 1) << 0x30) >> 0x30;
                goto loop_295;
            }
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4BU;
            return;
        }
        break;
    case 0x4B:                                      /* switch 1 */
        if (func_00314660((u8 *)((*((s32 *)((u8 *)(temp_17) + (0x148)))))) == (s32)(0xE)) {
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4DU;
            return;
        }
        break;
    case 0x4D:                                      /* switch 1 */
        var_16_10 = 3;
        if ((*((s8 *)((u8 *)((func_002e4870(0) + ((*((s8 *)((u8 *)(temp_17) + (0x129)))) * 0xC) + (*((s16 *)((u8 *)(temp_17) + (0x11E)))))) + (0x14)))) == 2) {
            var_16_10 = 0;
        }
        if ((s32)((s32)(datGetFlag(0x1461))) == (s32)((s32)(0))) {
            if ((s32)((s32)(func_00312bc0(var_16_10))) == (s32)((s32)(1))) {
                if ((s32)((s32)((u32) (RpRandom() % 1000U))) < (s32)((s32)(0x1F4U))) {
                    (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4FU;
                    (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 1;
                    return;
                }
                (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x50U;
                (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 2;
                return;
            }
            (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 0;
            (*((s8 *)((u8 *)(temp_17) + (0)))) = 0xD;
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0xC5U;
            return;
        }
        if ((s32)((s32)((u32) (RpRandom() % 1000U))) < (s32)((s32)(0x1F4U))) {
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4FU;
            (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 1;
            return;
        }
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x50U;
        (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 2;
        return;
    case 0x4F:                                      /* switch 1 */
        memset(&sp150, 0, 0x1A);
        var_16_11 = 0;
loop_312:
        temp_18_41 = (s64) (var_16_11 << 0x30) >> 0x30;
        if (temp_18_41 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
            sp150[temp_18_41] = (u16)((u16)((u16) (*((u16 *)((u8 *)(func_002e48a0(0, var_16_11)) + (2))))));
            var_16_11 = (s64) ((var_16_11 + 1) << 0x30) >> 0x30;
            goto loop_312;
        }
        temp_16_78 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (2)))))));
        sp150[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_78;
        func_002e5ae0(0xD, &sp150, (s64) (func_00104c70(1) << 0x38) >> 0x38);
        temp_16_79 = (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))));
        temp_16_80 = (u32)((u32)((RpRandom() % temp_16_79) * 0xA));
        temp_19_14 = (s64)((s64)((s64) ((s64) (temp_16_80 % (u32) (*((u32 *)((u8 *)(func_002e4870(0xD)) + (8))))) << 0x38) >> 0x38));
        (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = (s8)((s8)((s8) ((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1)));
        (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8)((s8)((s8) (*((s16 *)((u8 *)(temp_17) + (0x11E))))));
        var_18_7 = 0;
        do {
            temp_16_81 = (s64) (var_18_7 << 0x30) >> 0x30;
            if (((s32)((s32)(((s32) ((1 << temp_16_81) & 0xFF & (*((s8 *)((u8 *)((func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + (*((s8 *)((u8 *)(temp_17) + (0x2FA)))))) + (0x2E4))))) >> temp_16_81))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0(func_002e48a0(0xD, temp_19_14)))) < (s32)((s32)(8)))) {
                temp_16_82 = (u16)((u16)((u16)((*((u16 *)((u8 *)((func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))) + (temp_16_81 * 2))) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(func_002e48a0(0xD, temp_19_14)),  temp_16_82))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(func_002e48a0(0xD, temp_19_14)),  temp_16_82);
                }
            }
            var_18_7 = (s64) ((var_18_7 + 1) << 0x30) >> 0x30;
        } while ((s32)((s32)(((s64) (var_18_7 << 0x30) >> 0x30))) < (s32)((s32)(8)));
        (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = 0xD;
        (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8) temp_19_14;
        temp_18_42 = (s64) (temp_19_14 << 0x38) >> 0x38;
        temp_16_83 = (u16 *)(func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), temp_18_42));
        func_003146f0((*((s32 *)((u8 *)(temp_17) + (0x148)))), temp_16_83, (*((s8 *)((u8 *)((func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + ((s64) (temp_18_42 << 0x38) >> 0x38))) + (0x2E4)))));
        (*((s8 *)((u8 *)(temp_17) + (0)))) = 0xD;
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0xC5U;
        return;
    case 0x50:                                      /* switch 1 */
        var_19_11 = 0x63;
        memset(&sp130, 0, 0x1A);
        var_16_12 = 0;
loop_323:
        temp_18_43 = (s64) (var_16_12 << 0x30) >> 0x30;
        if (temp_18_43 < (*((s32 *)((u8 *)(func_002e4870(0)) + (8))))) {
            sp130[temp_18_43] = (u16)((u16)((u16) (*((u16 *)((u8 *)(func_002e48a0(0, var_16_12)) + (2))))));
            var_16_12 = (s64) ((var_16_12 + 1) << 0x30) >> 0x30;
            goto loop_323;
        }
        temp_16_84 = (u16)((u16)((u16)((*((u16 *)((u8 *)(func_002e48a0((s64) (((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1) << 0x38) >> 0x38, (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E)))))) + (2)))))));
        sp130[(*((s32 *)((u8 *)(func_002e4870(0)) + (8))))] = temp_16_84;
        func_002e6280(0xD, &sp130, (s64) (func_00104c70(1) << 0x38) >> 0x38);
        if ((*((s32 *)((u8 *)(func_002e4870(0xD)) + (8)))) == 0) {
            (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = (s8)((s8)((s8) ((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1)));
            (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8)((s8)((s8) (*((s16 *)((u8 *)(temp_17) + (0x11E))))));
            (*((u8 *)((u8 *)(temp_17) + (1)))) = 0x4FU;
            (*((s8 *)((u8 *)(temp_17) + (0xB2)))) = 1;
            return;
        }
        (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = 0xD;
        var_18_8 = 0;
loop_332:
        if (((s64) (var_18_8 << 0x30) >> 0x30) < (*((s32 *)((u8 *)(func_002e4870(0xD)) + (8))))) {
            temp_16_85 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
            if ((s32)((s32)((s32) temp_16_85)) >= (s32)((s32)((func_00104c70(1) & 0xFF)))) {
                (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8) var_18_8;
            } else {
                temp_20_7 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
                if ((s32)((s32)(((s64) (((func_00104c70(1) & 0xFF) - temp_20_7) << 0x38) >> 0x38))) < (s32)((s32)(((s64) (var_19_11 << 0x30) >> 0x30)))) {
                    temp_16_86 = (*((u8 *)((u8 *)(func_002e48a0(0xD, var_18_8)) + (4))));
                    var_19_11 = (s64)((s64)((s64) (((func_00104c70(1) & 0xFF) - temp_16_86) << 0x38) >> 0x38));
                    (*((s8 *)((u8 *)(temp_17) + (0x2FA)))) = (s8) var_18_8;
                }
                var_18_8 = (s64) ((var_18_8 + 1) << 0x30) >> 0x30;
                goto loop_332;
            }
        }
        temp_19_15 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x2FA)))))));
        (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = (s8)((s8)((s8) ((*((s8 *)((u8 *)(temp_17) + (0x129)))) + 1)));
        var_18_9 = 0;
loop_339:
        temp_20_8 = (s64) (var_18_9 << 0x30) >> 0x30;
        if (temp_20_8 < 8) {
            temp_16_87 = (s64) (var_18_9 << 0x30) >> 0x30;
            if (((s32)((s32)(((s32) ((1 << temp_16_87) & 0xFF & (*((s8 *)((u8 *)((func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + (*((s16 *)((u8 *)(temp_17) + (0x11E)))))) + (0x2E4))))) >> temp_16_87))) == (s32)((s32)(1))) && ((s32)((s32)(func_0010ceb0(func_002e48a0(0xD, (s64) temp_19_15)))) < (s32)((s32)(8)))) {
                temp_16_88 = (u16)((u16)((u16)((*((u16 *)((u8 *)((func_002e48a0((s64) (*((s8 *)((u8 *)(temp_17) + (0x2F9)))), (s64) (*((s16 *)((u8 *)(temp_17) + (0x11E))))) + (temp_20_8 * 2))) + (0xC)))))));
                if ((s32)((s32)(func_0010ce10((u8 *)(func_002e48a0(0xD, (s64) temp_19_15)),  temp_16_88))) == (s32)((s32)(-1))) {
                    func_0010cc20((u8 *)(func_002e48a0(0xD, (s64) temp_19_15)),  temp_16_88);
                }
            }
            var_18_9 = (s64) ((var_18_9 + 1) << 0x30) >> 0x30;
            goto loop_339;
        }
        (*((s8 *)((u8 *)(temp_17) + (0x2F9)))) = 0xD;
        temp_18_44 = (s8)((s8)((s8)((*((s8 *)((u8 *)(temp_17) + (0x2FA)))))));
        temp_16_89 = (u16 *)(func_002e48a0(0xD, (s64) temp_18_44));
        func_003146f0((*((s32 *)((u8 *)(temp_17) + (0x148)))), temp_16_89, (*((s8 *)((u8 *)((func_002e4870((*((s8 *)((u8 *)(temp_17) + (0x2F9))))) + ((s64) ((s64) temp_18_44 << 0x38) >> 0x38))) + (0x2E4)))));
        (*((s8 *)((u8 *)(temp_17) + (0)))) = 0xD;
        (*((u8 *)((u8 *)(temp_17) + (1)))) = 0xC5U;
        break;
    }

}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f0f00);
#endif

/* measured: 12084 executable bytes / 12096-byte window, verify MATCH, 391 relocations.
   Rewritten from the retail assembly with opt_lifetimes (each loop and case keeps
   its own registers, as in retail).  00275820 takes its floats first; colour
   builders passed straight into 002ba5d0 keep retail's call order; the object ids
   reused inside the selected-row branch are locals computed before their first
   colour call; the row index is copied into its own local at each branch. */
/* Parked: with every declaration agreeing with its definition this is 4 words
   off, all at one call. Case 0x59 passes the lhu item id unmasked to
   func_00313ae0, but that function's definition (code1_0031.c) takes a wider
   parameter and masks it on entry (retail andi $a1, 0xffff), which b210 only
   emits for a wider parameter; a u16 prototype here matches this caller but not
   the callee. func_00310a10 and func_00105f50 take u16 (see
   docs/probe_archive/FclCombine_002ed430_recovery_20260925.md). */
// FUN_002F6CF0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
void func_002f6cf0(u8 *arg0) {
    extern void func_002e4610(s32, s8);
    extern s8 func_00314660(u8 *);
    extern void func_00314670(u8 *, s8);
    extern void func_00314680(u8 *);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00317240(u8 *, s64, f32);
    extern s32 func_003190d0(u8 *);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00310a10(u8 *, u16);
    extern void func_00325450(u8 *, s32, s32);
    extern void func_00313800(s8);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00323d00(u8 *, s32, s32);
    extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s16);
    /* The callee masks every channel itself; retail passes the unmasked alpha. */
    extern s32 func_002b2a30(s32, s32, s32, s32);
    extern void func_002ba970(u8 *, s16, u32);
    extern void func_002ba5d0(u8 *, s32, s32, s64, FclDrawColor, s64, f32);
    extern s32 func_003139d0(s8, s8);
    extern s32 func_002bb1c0(s8);
    extern s32 func_00104c70(s32);
    extern s16 func_00247770(s32);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern void func_0011d140(u8 *, s32); /* retail loads the colour into $a1 */
    extern void func_003144d0(u8 *, s32, s8, s32, s32);
    extern void func_00314450(u8 *, s32, u8, s32);
    extern s32 func_00311930(s32, u8 *, s8);
    extern s64 func_00313ae0(s64, s32);
    extern s32 func_00313a80(s64, s64);
    extern void func_002f9c30(u16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, s8, s8);
    extern u8 D_00795E60[];
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
    s32 alpha;
    s32 alpha2;
    s32 alpha3;
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
        func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
        func_002b2970((u8 *)&pos0, base->x, base->y);
        func_002b6c30(0xC8, pos0.position, 42.0f, 0x5A);
        func_002b6a70(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        func_002b2970((u8 *)&pos1, (f32)0x28A + base->x, base->y);
        func_002b2970((u8 *)&pos2, base->x - 50.0f, base->y);
        func_002b69f0(0xC8, pos1.position, pos2.position, 0, 0x14, 0);
        func_003205f0(arg0, 0x98, 0x96);
        *(s16 *)(p + 0x11E) = 0;
        p[1] = 0x53;
        break;
    case 0x53:
        for (i = 0; i < *(s32 *)(func_002e4870(*(s16 *)(p + 0x11E) + 1) + 8); i++) {
            func_002b2970((u8 *)&rowPos, (f32)0x139, 128.0f);
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
                func_002ba5d0(*(u8 **)(p + 0x2BC), (s8)i, 0, rowPos.bits, color3 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha), 0x59, 46.0f);
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
                              rowPos.bits, color6 = func_002b2a60(shade, 0xFF, 0xFF, alpha), 0x59, 46.0f);
            }
        }
        for (k = 0; k < *(s32 *)(func_002e4870(0) + 8); k++) {
            alpha2 = (u8)func_002b2aa0(0, 0.0f, 255.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                       *(s16 *)(func_002b6150(k + 0x270) + 0x40));
            if (*(s16 *)(p + 0x11E) == k) {
                color7 = func_002b2a60(0x2D, 0x2D, 0x2D, alpha2);
                func_002ba970(*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(u32 *)&color7);
            } else if (func_003139d0(p[0x1A], (s8)k) == 1) {
                color8 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha2);
                func_002ba970(*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(u32 *)&color8);
            } else {
                alpha2 = (u8)func_002b2aa0(0, 0.0f, 128.0f, *(s16 *)(func_002b6150(k + 0x270) + 0x42),
                                           *(s16 *)(func_002b6150(k + 0x270) + 0x40));
                color9 = func_002b2a60(0xCC, 0xFF, 0xFF, alpha2);
                func_002ba970(*(u8 **)(p + 0x2BC), (s8)(k + 0xC), *(u32 *)&color9);
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
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
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
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
            func_003205f0(arg0, 0x96, 0x98);
            p[1] = 0x56;
        } else if (buttons & 0x80) {
            func_0045af60(0, 1, 0, 3);
            p[0x2FA] = *(s16 *)(p + 0x11E);
            *(s16 *)(p + 0x11E) = -1;
            func_00323d00(arg0, 0, 1);
            func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
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
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
            func_002f9c30(func_002e48a0(0, slot), (u8 *)func_002e48a0(p[0x2FA] + 1, 0),
                          (u8 *)func_002e48a0(p[0x2FA] + 1, 1), (u8 *)func_002e48a0(p[0x2FA] + 1, 2),
                          (u8 *)func_002e48a0(p[0x2FA] + 1, 3), (u8 *)func_002e48a0(p[0x2FA] + 1, 4),
                          (u8 *)func_002e48a0(slot + 1, 5), p[0x1A], 0, slot);
        }
        func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]),
                      ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4],
                      func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
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
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
            func_002b2970((u8 *)&pos3, (f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(obj, *(FclVec2 *)(ps + 0x38), pos3.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            func_002b2970((u8 *)&pos4, (f32)(stepInt * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos4.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]),
                              ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4],
                              func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
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
            func_002b2970((u8 *)&pos5, (f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(obj2, *(FclVec2 *)(ps + 0x38), pos5.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            func_002b2970((u8 *)&pos6, (f32)(stepInt2 * p[0x122] + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos6.position, 1, 4, 0);
            if (p[0x122] < p[0x1A]) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2FA] + 1, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]),
                              ((s8 *)func_002e4870(p[0x2F9]))[p[0x2FA] + 0x2E4],
                              func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
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
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f6cf0);
#endif

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
    extern void func_00325450(u8 *, s32, s32);
    extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
    extern void func_002b69f0(s16, FclVec2, FclVec2, u32, u32, s16);
    /* The callee masks every channel itself; retail passes the unmasked alpha. */
    extern s32 func_002b2a30(s32, s32, s32, s32);
    extern void func_002ba970(u8 *, s16, u32);
    extern s32 func_002bb1c0(s8);
    extern s32 func_00104c70(s32);
    extern s16 func_00247770(s32);
    extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern void func_0011d140(u8 *, s32); /* retail loads the colour into $a1 */
    extern void func_003144d0(u8 *, s32, u8, s32, s32);
    extern void func_00314450(u8 *, s32, u8, s32);
    extern s32 func_00311930(s32, u8 *, s8);
    extern s16 func_002b2d50(s16, s16, s16, s16, s16);
    extern u8 D_00795E60[];
    extern f32 D_00640E70[];
    FclDrawColor slotColor;
    FclDrawColor rowColor;
    FclDrawColor color0C;
    FclPackedPosition pos0;
    FclPackedPosition pos1;
    FclPackedPosition pos2;
    FclPackedPosition pos3;
    FclPackedPosition pos4;
    FclPackedPosition pos5;
    FclPackedPosition pos6;
    s16 j;
    u8 shade;
    s32 alpha;
    s32 alpha3;
    s32 alpha2;
    s32 alpha4;
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
            func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        } else {
            func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
            ps = func_002b6150(0x8A);
            *(f32 *)(ps + 0x38) += 60.0f;
        }
        base = (FclVec2 *)D_00640E70;
        func_002b2970((u8 *)&pos0, base->x, base->y);
        func_002b6c30(0xC8, pos0.position, 42.0f, 0x5A);
        func_002b6a70(0xC8, 0xFF, 0, 0, 0xA, 0xA);
        func_002b2970((u8 *)&pos1, (f32)0x28A + base->x, base->y);
        func_002b2970((u8 *)&pos2, base->x - 50.0f, base->y);
        func_002b69f0(0xC8, pos1.position, pos2.position, 0, 0x14, 0);
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
                func_002ba970(*(u8 **)(p + 0x2BC), i, *(u32 *)&rowColor);
                func_00275820((f32)0x19D, (f32)(i * 23 + 0x80), 43.0f, color, 0, 2,
                      (const char *)((u8 *)iGpffffb440 + ((u16 *)func_002e48a0(0, i))[1] * 0x11), 0, 0, D_00795E60, 0x15);
            }
        }
        alpha3 = (u8)func_002b2aa0(0, 0.0f, 255.0f, *(s16 *)(func_002b6150(0x270) + 0x42),
                              *(s16 *)(func_002b6150(0x270) + 0x40));
        color0C = func_002b2a60(0x2D, 0x2D, 0x2D, alpha3);
        func_002ba970(*(u8 **)(p + 0x2BC), 0xC, *(u32 *)&color0C);
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
                    func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0,
                                  func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
                                                (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                    if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                        func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                    }
                    func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    func_00325450(arg0, 8, 0);
                    func_00324680(arg0, 0, 1);
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0.0f);
                } else {
                    func_0045af60(0, 0, 0, 8);
                }
            } else if (buttons & 0x80) {
                func_00324680(arg0, 0, 1);
                if (p[0x20] == 0) {
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                }
                func_00317240(arg0, 0, 60.0f);
                p[1] = 0x66;
                func_0045af60(0, 1, 0, 3);
            } else if (buttons & 0x20) {
                func_00324680(arg0, 0, 1);
                if (p[0x20] == 0) {
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                } else {
                    func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0);
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
                func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            } else {
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
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
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                } else {
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0);
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
            func_002b2970((u8 *)&pos3, (f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x155, *(FclVec2 *)(ps + 0x38), pos3.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            func_002b2970((u8 *)&pos4, (f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos4.position, 1, 4, 0);
            func_00329310(arg0, 0, 0);
            if (p[0x122] < 0xC) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(0, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0,
                              func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
                                            (u8 *)func_002e48a0(p[0x2F9], p[0x2FA]), 0), 1);
            }
        } else if (D_008C024E[2] & 4) {
            if (p[0x122] != 0) {
                func_0045af60(0, 2, 0, 5);
            }
            p[0x122] = func_002b2d00(p[0x122], 1, 0, 0, 1);
            *(s16 *)(p + 0x120) = func_002b2d50(p[0x122], *(s16 *)(p + 0x120), 0xC, 7, -1);
            ps = func_002b6150(0x155);
            func_002b2970((u8 *)&pos5, (f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x155, *(FclVec2 *)(ps + 0x38), pos5.position, 1, 4, 0);
            ps = func_002b6150(0x2E0);
            func_002b2970((u8 *)&pos6, (f32)(*(s16 *)(p + 0x120) * 61 + 0x6A), 16.0f);
            func_002b69f0(0x2E0, *(FclVec2 *)(ps + 0x38), pos6.position, 1, 4, 0);
            func_00329310(arg0, 0, 0);
            if (p[0x122] < 0xC) {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(0, p[0x122]), 0, 0, 1);
            } else {
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                if (((u8 *)func_002e48a0(p[0x2F9], p[0x2FA]))[4] > (u8)func_00104c70(1)) {
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0x14, 0x14, 0x14, 0xFF));
                }
                func_003144d0(*(u8 **)(p + 0x148), (s32)func_002e48a0(p[0x2F9], p[0x2FA]), 0,
                              func_00311930(func_00247770(iGpffffb3d4[func_002e48a0(p[0x2F9], p[0x2FA])[1] * 14 + 2]),
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

/* measured 002fbea0 recon + jump-table recovery + partial guarded body (see below). */
/* Retail 26320B = 6580 instrs (6579 trimmed per fnalign), band 6383-6777. Frame -0x500 */
/* (addiu $29,$29,-0x500; sd $31 + sq $30/$23-$16 + swc1 $f20). Calls 931 jal. */
/* Total branch/jump includes 2 jr: dispatch jr $3 at 0x002FBF00 + return jr $31 at 0x00302568. */
/* Dispatch: lbu $3,0x1($17); addiu $3,$3,-0x8A; sltiu $1,$3,0x16; beqz $1,.L00302538 (default); */
/*   lui/addiu jtbl_00749280; sll $3,$3,2; addu; lw; jr $3 (delay nop). Base 0x8A = 138, */
/*   so the C switch is over states 0x8A..0x9F with 22 cases (indices 0..21) + default. */
/* jtbl_00749280 holds 22 valid words; words 22-23 are 0x0 pad to jtbl_007492E0 at 0x7492E0 */
/*   (entries 24+ belong to the next table). sltiu bound 0x16 = 22 cases; case 2 (0x8C) */
/*   targets the default .L00302538 (+0x6698), i.e. an empty state sharing the epilogue. */
/* Full table (`python3 tools/jtbl.py 0x00749280 30 --func 0x002fbea0`): */
/*   case  0 (0x8A): 0x002FBF08 (+0x68)    case 11 (0x95): 0x002FD088 (+0x11E8) */
/*   case  1 (0x8B): 0x002FBFAC (+0x10C)   case 12 (0x96): 0x002FD1E0 (+0x1340) */
/*   case  2 (0x8C): 0x00302538 (+0x6698, default)  case 13 (0x97): 0x002FE730 (+0x2890) */
/*   case  3 (0x8D): 0x002FC378 (+0x4D8)   case 14 (0x98): 0x002FEA3C (+0x2B9C) */
/*   case  4 (0x8E): 0x002FD58C (+0x16EC)  case 15 (0x99): 0x003001D4 (+0x4334) */
/*   case  5 (0x8F): 0x002FD678 (+0x17D8)  case 16 (0x9A): 0x003002B4 (+0x4414) */
/*   case  6 (0x90): 0x002FE450 (+0x25B0)  case 17 (0x9B): 0x00301408 (+0x5568) */
/*   case  7 (0x91): 0x002FE5C8 (+0x2728)  case 18 (0x9C): 0x00301F9C (+0x60FC) */
/*   case  8 (0x92): 0x002FE640 (+0x27A0)  case 19 (0x9D): 0x002FFD78 (+0x3ED8) */
/*   case  9 (0x93): 0x002FE6B8 (+0x2818)  case 20 (0x9E): 0x002FFE08 (+0x3F68) */
/*   case 10 (0x94): 0x002FE7CC (+0x292C)  case 21 (0x9F): 0x00300144 (+0x42A4) */
/* C shape: switch (state) { case 0x8A: ... case 0x9F: ...; default: ... } in ascending */
/*   order, one case per table entry (0x8C kept explicit as break: it shares the default */
/*   target). The object reproduces the dispatch identically (fnalign elides the */
/*   sll/addu/lw/jr $3/nop sequence as matching; the lui/addiu table setup is reloc-only). */
/* Coverage: all 22 states written. Prior twelve (0x8A, 0x8B, 0x8E, 0x90, 0x91, 0x92, 0x93, */
/*   0x97, 0x95, 0x99, 0x9D, 0x9F) as before; new 0x94 (275820-loop + 0x1B tail, gp= */
/*   iGpffffb440), 0x9E (1099f0 sums + 3026c0 + bbd80/badc0-0x10 tail to 0x9F), 0x96 (same */
/*   loop with (0,0.0f,255.0f) + bit-dance loop + 32b770 tail to 0x92, else 0x8D), 0x9C */
/*   (loop + 1099f0 chain + 2cacd0 pair, 172.0f/0x96/510.0f/0x9E), 0x9B (loop + 0x2A3-store */
/*   + full colour-copy blocks + 0x2C5-block + 314660==6 tail to 0x98), 0x8D (loop + MAC */
/*   `111.0f + 23.0f * x` + 2ba5d0 + colour blocks + D0276/D027A/D024E tail dispatch), */
/*   0x8F complete (converging else-if chain to conv8F, NOT returning per block; the banked */
/*   partial's `0x13A=0; return` inside the D8 arm was wrong - retail converges), 0x9A */
/*   (range guard + D-dispatch with 314450-tails + ldr-blocks + 0x40/0x20 tails to 0x9D/0x9E), */
/*   0x98 (loop + MAC#2 `151.0f + 23.0f * idx` + colour blocks + tail). Still missing: none. */
/* Codegen facts (measured with MWCC b210 probes, keep): e48a0 salt is s64 - s16-MEM folds */
/*   (lh, free) and s64 loop vars pass raw (daddu), saving +2/site over the (s8,s16) decl; */
/*   adda.s/madd.s EMIT from plain C (`111.0f + 23.0f * x`, `151.0f + 23.0f * x` verified */
/*   insn-for-insn); 2b2aa0 float order is per-arm ($f12=255/$f13=0 vs $f12=0/$f13=255); */
/*   2cacd0 is (u64,s32x7,f32,s32,s32) with sd stack args (ShopDraw-matched); (f32)0xNNN int-> */
/*   float conversions (0x141, 0x1A1, 0x157) and 640.0f-for-0x44200000 are load-bearing; */
/*   0x8D true span is 0xD10=836I (not 0xC10/772 - recompute before trusting old notes). */
/* measured 002fbea0 complete: object 6533I vs retail 6579I (99.3%) via */
/*   `python3 tools/fnalign.py src/Event/Fcl/y_fclCombine.c func_002fbea0 */
/*   --candidate /tmp/cand_002fbea0.c`. Per-arm count deltas vs span: 0x94 +160/+156, */
/*   0x9E +209/+207, 0x96 +243/+235, 0x9C +358/+359, 0x9B +749/+741, 0x8D +855/+836, */
/*   0x8F +826/~806rem, 0x9A +1100/+1109, 0x98 +1166/+1231 (-65, no major block absent */
/*   per fnalign deletes; likely spills/compacted idiom - revisit on the match pass). */
/* INSIDE the +-3% band (6533 vs 6383-6777, -0.7%): all states 0x8D, 0x94, 0x96, 0x98, */
/*   0x9A, 0x9B, 0x9C, 0x9E written and 0x8F completed. Dispatch + case order unchanged. */
/* gate: func_002fbea0 is INSIDE the +-3% band at 6533 against retail 6579 (-0.7%, band */
/*   6383-6777).  All 22 jump-table states 0x8A-0x9F have bodies; 0x8C shares the default */
/*   target as an explicit break.  Still missing: none.  Next worker starts from a */
/*   complete dispatch skeleton at 99.3% of retail count; remaining work is idiom-level */
/*   (spills, D-flag reload CSE, float-literal forms) on the match pass, not structure. */
// FUN_002FBEA0 NONMATCHING
#ifdef NON_MATCHING
void func_002fbea0(u8 *arg0) {
    extern void func_00315600(u8 *, s32);
    extern void func_002e4610(s32, s8);
    extern s32 datGetFlag(s32);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s64);
    extern u8 *func_002b6150(s16);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b68d0(s16, s32, s32);
    extern void func_002ba970(s32, s8, s32);
    extern s8 func_002bab80(void *);
    extern void func_002badc0(s8, s32);
    extern s32 func_00331660(void);
    extern void func_0032b770(u8 *, s32, s32, s32);
    extern void func_0032b9d0(u8 *, s32, s32, s32);
    extern void func_002e68b0(s32);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_00314560(u8 *, u16 *, s32, s32);
    extern u8 *func_003147d0(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011d140(u8 *, s32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern void func_002bb550(s8);
    extern void func_00314670(u8 *, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern void func_0032f4d0(u8 *);
    extern void func_003205f0(u8 *, s32, s32);
    extern s32 func_00302570(u8 *);
    extern s8 func_00314660(u8 *);
    extern void func_002b2970(s64 *, f32, f32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern void func_0045af60(s32, s32, s32, s32);
    extern void func_0032c480(u8 *);
    extern s8 *func_0034a630(s32);
    extern void func_0011d1d0(u8 *, f32);
    extern s8 func_002bb1c0(s8);
    extern void func_0010fd40(void *);
    extern void func_00314750(u8 *, s32);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_00275820(s32, s32, s32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern u8 *iGpffffb440;
    extern u8 D_00795E60[];
    extern s32 func_0010b190(u8 *);
    extern s32 func_001099f0(u16 *, s32);
    extern s32 func_003026c0(u16, s32);
    extern s32 func_002e7a60(void);
    extern void func_002e7a80(s32);
    extern void func_002bbd80(s8, s32, void *);
    extern s32 func_00349290(u8 *, s8);
    extern void func_002cacd0(u64, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32);
    extern void *func_0046a770(void *);
    extern s32 func_00331560(void);
    extern u8 D_00641B30[];
    extern u8 func_00109280(u16);
    extern void func_002ba5d0(u8 *, s32, s32, s64, s32, s64, f32);
    extern void func_0032c0c0(u8 *, s32);
    extern void func_002bafc0(s8, s32);
    extern void func_002bb0a0(s8, s32);
    extern void func_002bbf60(void);
    extern void func_0031ac10(u8 *, s64, s8, s32, u16, u8, s32, s32, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_00324f80(u8 *arg0, s64, s32, s32);
    extern void func_003297f0(u8 *, s32, s32, f32, f32);
    extern u16 D_008C0276[];
    extern u16 D_008C027A[];
    extern s32 func_0011c610(u8 *);
    extern void func_0011caf0(u8 *);
    extern u16 *func_0010fcb0();
    extern s32 func_0011ba00(u8 *);
    extern void func_00314740(u8 *, s8);
    extern void sprintf(void *dst, void *fmt, s32 value);
    extern char iGpffffa8a4;
    extern u16 D_008C0252[];
    extern void func_0032a960(u8 *, s32);
    extern void func_002b5e90(s32, s64, s64, s32);
    extern void func_002b5ef0(s32, s64, s64, void *, void *, s32);
    extern void func_002b60f0(s32, s32, s32, s32);
    extern void func_00317320(u8 *, s32, s32);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00317240(u8 *, s64, s32);
    extern void func_0034a890(s32);
    extern void func_0034a840(s32);

    u8 *p;
    u8 state;
    s64 var_16;
    s16 var_16_2;
    s16 var_16_5;
    s16 base;
    s8 tmp8;
    u8 *r2;
    u8 *r3;
    u8 *r4;
    u8 *r5;
    u8 *r6;
    u8 *ps;
    u8 col0;
    u8 col1;
    u8 col2;
    u8 col3;
    u8 colB0;
    u8 colB1;
    u8 colB2;
    u8 colB3;
    u8 colC0;
    u8 colC1;
    u8 colC2;
    u8 colC3;
    u8 c0;
    u8 c1;
    s64 sp440;
    s64 sp438;
    s64 var_16_6;
    s64 var_18;
    s64 var_19;
    s64 var_22;
    s64 temp_16;
    s64 temp_21;
    f32 temp_f20;
    f32 temp_f0;
    s32 var_3;
    s32 temp_7;
    s32 var_21;
    s32 sumA;
    s32 sumB;
    s32 total;
    s32 saved;
    u16 bitSav;
    s64 sp308;
    s32 colW1;
    s64 sp300;
    s32 colW2;
    s32 tmpe;
    s32 tmpv;
    s64 tmp22;
    s64 tmp21F;
    u8 d0;
    u8 d1;
    u8 d2;
    u8 d3;
    s64 sp318;
    s32 colW3;
    s64 sp310;
    s32 colW4;
    u8 w498[4];
    u8 w494[4];
    s32 w490;
    u8 w48C[4];
    u8 w488[4];
    u8 w484[4];
    s32 w480;
    u8 w47C[4];
    u8 w478[4];
    s64 sp460;
    s32 colW5;
    s32 tmpu8;
    u8 w4E0[4];
    u8 w4DC[4];
    s32 w4D8;
    u8 w4D4[4];
    u8 w4D0[4];
    u8 w4CC[4];
    s32 w4C8;
    s64 sp458;
    s64 sp450;
    s64 sp448;

    s64 sp430;
    s64 sp428;
    u8 sp2A0[64];
    s64 sp3C8;
    s64 sp3C0;
    s64 sp3B8;
    s64 sp3B0;
    s64 sp3A8;
    s64 sp3A0;
    s64 sp398;
    s64 sp390;
    s64 sp210;
    s64 sp200;
    s64 sp388;
    s64 sp380;
    s64 sp378;
    s64 sp370;
    s64 sp368;
    s64 sp360;
    s64 sp358;
    s64 sp350;
    s64 sp1F0;
    s64 sp1E0;
    s64 sp348;
    s64 sp340;
    s64 sp338;
    s64 sp330;
    s64 sp328;
    s64 sp320;
    s64 sp1D0;
    s64 sp1C0;
    u8 sp220[64];
    s64 sp420;
    s32 colW6;
    s64 sp418;
    s32 colW7;
    s64 sp410;
    s16 sp1B0;
    u8 w4C0[4];
    u8 w4BC[4];
    s32 w4B8;
    u8 w4B4[4];
    u8 w4B0[4];
    u8 w4AC[4];
    s32 w4A8;
    u8 w4A4[4];
    u8 w4A0[4];
    s64 sp3E8;
    s64 sp3E0;
    s64 sp3D8;
    s64 sp3D0;
    p = *(u8 **)(arg0 + 0x38);
    state = *(p + 1);
    switch (state) {
    case 0x8A:
        func_00315600(arg0, 1);
        if (*(p + 0) == 0x10) {
            func_002e4610(6, 0);
        } else if (*(p + 0) == 0xF) {
            if (datGetFlag(0x1460) != 0) {
                func_002e4610(8, 0);
            } else {
                func_002e4610(2, 0);
            }
        }
        *(s16 *)(p + 0x11E) = 0;
        *(s16 *)(p + 0x120) = 0;
        *(s8 *)(p + 0x129) = -1;
        *(s8 *)(p + 0x128) = -1;
        *(s8 *)(p + 0x123) = 0;
        *(p + 1) = 0x8B;
        return;
    case 0x8B:
        if (*(s8 *)func_002e4870(0) == 0) {
            return;
        }
        var_16 = 0;
        while ((s64)((var_16 << 0x30) >> 0x30) < (s64)(*(s8 *)(p + 0xB7))) {
            if (func_002b6970(*(s16 *)(func_002b6150((s16)(var_16 * 2 + 0x1F8)) + 0x10), 1) == 1) {
                return;
            }
            var_16 = (s64)((var_16 + 1) << 0x30) >> 0x30;
        }
        var_16_2 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_2 = 8;
            *(f32 *)(p + 0x124) = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
        }
        if (*(p + 0) == 0x10) {
            if (*(s32 *)(func_002e4870(0) + 8) == 0) {
                tmp8 = func_002bab80((void *)func_00331660());
                *(s8 *)(p + 0xD) = tmp8;
                func_002badc0(tmp8, 0xE);
                *(p + 1) = 0x93;
            } else {
                func_0032b770(arg0, 2, var_16_2, 0);
                *(p + 1) = 0x8D;
            }
        } else if (*(p + 0) == 0xF) {
            *(s8 *)(p + 0x123) = 0;
            if (datGetFlag(0x1460) == 0) {
                func_002e68b0(0);
            }
            func_0032b9d0(arg0, 2, var_16_2, 0);
            *(p + 1) = 0x98;
        }
        base = *(s16 *)(p + 0x11E);
        *(s8 *)(func_002b6150((s16)(base + 0x27D)) + 0x6E) = -1;
        *(s8 *)(func_002b6150((s16)(base + 0x270)) + 0x6E) = -1;
        func_002b68d0(0x270, 2, 1);
        func_002b68d0(0x27D, 2, 1);
        fclWriteColorBytes((u8 *)(&col0), 0xCC, 0xFF, 0x33, 0xFF);
        r2 = func_002b6150((s16)(base + 0x297));
        *(r2 + 0x85) = col0;
        *(r2 + 0x86) = col1;
        *(r2 + 0x87) = col2;
        *(r2 + 0x88) = col3;
        r3 = func_002b6150((s16)(base + 0x28B));
        c0 = *(r2 + 0x85);
        c1 = *(r2 + 0x86);
        *(r3 + 0x85) = c0;
        *(r3 + 0x86) = c1;
        *(r3 + 0x87) = *(r2 + 0x87);
        *(r3 + 0x88) = *(r2 + 0x88);
        r4 = func_002b6150((s16)(base + 0x27D));
        c0 = *(r3 + 0x85);
        c1 = *(r3 + 0x86);
        *(r4 + 0x85) = c0;
        *(r4 + 0x86) = c1;
        *(r4 + 0x87) = *(r3 + 0x87);
        *(r4 + 0x88) = *(r3 + 0x88);
        r5 = func_002b6150((s16)(base + 0x270));
        *(r5 + 0x85) = *(r4 + 0x85);
        *(r5 + 0x86) = *(r4 + 0x86);
        *(r5 + 0x87) = *(r4 + 0x87);
        *(r5 + 0x88) = *(r4 + 0x88);
        fclWriteColorBytes((u8 *)(&colB0), 0x2D, 0x2D, 0x2D, 0xFF);
        r6 = func_002b6150((s16)(base + 0x2A3));
        *(r6 + 0x85) = colB0;
        *(r6 + 0x86) = colB1;
        *(r6 + 0x87) = colB2;
        *(r6 + 0x88) = colB3;
        fclWriteColorBytes((u8 *)(&colC0), 0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(s32 *)(p + 0x2BC), (s8)(base + 0xC), (s32)colC0);
        return;
    case 0x8C:
        break;
    case 0x8D:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW5, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW5, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            tmpu8 = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
            func_002b2970(&sp460, 146.0f, 111.0f + 23.0f * (f32)var_19);
            func_002ba5d0(*(u8 **)(p + 0x2BC), (s8)(temp_16 + 0xC), tmpu8, sp460, colW5, 0x59, 46.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                if (*(s16 *)(p + 0x11E) == var_19) {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30)) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -1;
                    fclWriteColorBytes(w4E0, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w4E0[0];
                    d1 = w4E0[1];
                    d2 = w4E0[2];
                    d3 = w4E0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4DC, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w4DC[0];
                    d1 = w4DC[1];
                    d2 = w4DC[2];
                    d3 = w4DC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4D8, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w4D8);
                } else {
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -128;
                    fclWriteColorBytes(w4D4, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = w4D4[0];
                    d1 = w4D4[1];
                    d2 = w4D4[2];
                    d3 = w4D4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w4D0, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w4D0[0];
                    d1 = w4D0[1];
                    d2 = w4D0[2];
                    d3 = w4D0[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4CC, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w4CC[0];
                    d1 = w4CC[1];
                    d2 = w4CC[2];
                    d3 = w4CC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4C8, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w4C8);
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((s64)(((var_16_6 + 0x26F) << 0x30) >> 0x30)) + 0x10), 1) == 1) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 5);
            return;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s16 *)(p + 0x11E) != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0032c0c0(arg0, 1);
            return;
        } else if (D_008C0276[0] & 0x4000) {
            if (*(s8 *)(p + 0x13A) != 0) {
                break;
            }
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            func_0045af60(0, 0, 0, 0);
            func_0032c0c0(arg0, 4);
            return;
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 0);
            return;
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 2);
            return;
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                break;
            }
            if (*(s16 *)(p + 0x11E) != 0) {
                func_0045af60(0, 0, 0, 0);
            }
            func_0032c0c0(arg0, 3);
            return;
        } else if (D_008C024E[0] & 0x40) {
            if (*(s16 *)(p + 0x11E) < *(s32 *)(func_002e4870(0) + 8)) {
                *(s8 *)(p + 0x122) = 0;
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    *(f32 *)(p + 0x124) = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b770(arg0, 0, var_16_2, 1);
                *(p + 1) = 0x8E;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                tmp8 = func_002bab80((void *)func_00331660());
                *(s8 *)(p + 0xD) = tmp8;
                func_002bafc0(tmp8, 0);
                func_002badc0(*(s8 *)(p + 0xD), 0xC);
                func_002bb0a0(*(s8 *)(p + 0xD), 0);
                func_002bbf60();
                *(p + 1) = 0x96;
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
            var_18 = 0;
            var_22 = var_16_6 + var_19;
            while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
                func_002b2970(&sp458, 162.0f, 111.0f);
                func_0031ac10(arg0, sp458, -1, (s8)var_18, *(u16 *)((u8 *)func_002e48a0(0, var_19) + 2), *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4), 0, 1, 0, 0xCC);
                var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
                var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
            }
            func_002b2970(&sp450, 156.0f, 87.0f);
            func_0031e5b0(arg0, sp450, 0, 1, 0, 1, 1);
            func_002b2970(&sp448, 472.0f, 112.0f);
            func_00324f80(arg0, sp448, 0, 1);
            func_003297f0(arg0, 0, 1, (f32)0x1A1, 220.0f);
            *(p + 1) = 0x94;
            func_0045af60(0, 0, 0, 2);
        }
        *(s8 *)(p + 0x13A) = 0;
        break;
    case 0x8E:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_002b6140((u8 *)(*(s32 *)(p + 0x28C)), 1);
            func_002b6140((u8 *)(*(s32 *)(p + 0x290)), 1);
            func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
            func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 0, 0);
            *(p + 1) = 0x8F;
            return;
        }
        break;
    case 0x8F:
        if ((s8)func_00314660(*(u8 **)(p + 0x148)) != 5) {
            break;
        }
        if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
            func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
        }
        if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 5);
                if (*(s8 *)(p + 0x122) == 0) {
                    func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                if (*(s16 *)(p + 0x11E) != 0) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 1);
                if (*(s8 *)(p + 0x122) == 0) {
                    func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0276[0] & 1) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 5);
            if (*(s8 *)(p + 0x122) == 0) {
                func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if ((D_008C0276[0] & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 4);
                if (*(s8 *)(p + 0x122) == 0) {
                    func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                    goto conv8F;
                }
                if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                    func_0045af60(0, 2, 0, 5);
                }
                func_0032c0c0(arg0, 0);
                if (*(s8 *)(p + 0x122) == 0) {
                    func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                } else {
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
                }
                goto conv8F;
            }
        } else if (D_008C0252[0] & 2) {
            if (*(s32 *)(func_002e4870(0) + 8) < 2) {
                goto conv8F;
            }
            func_0045af60(0, 2, 0, 5);
            func_0032c0c0(arg0, 4);
            if (*(s8 *)(p + 0x122) == 0) {
                func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            if (*(s8 *)(p + 0x122) == 0) {
                func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            } else {
                func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            }
            goto conv8F;
        } else if (D_008C024E[0] & 8) {
            if (*(s8 *)(p + 0x122) == 1) {
                *(s8 *)(p + 0x122) = 0;
                ps = func_002b6150(0x150);
                func_002b2970(&sp440, (f32)0x141, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp440, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp438, (f32)0x141, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp438, 1, 4, 0);
                func_00314560(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 4) {
            if (*(s8 *)(p + 0x122) == 0) {
                *(s8 *)(p + 0x122) = 1;
                ps = func_002b6150(0x150);
                func_002b2970(&sp430, 107.0f, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp430, 1, 4, 0);
                ps = func_002b6150(0x2E0);
                func_002b2970(&sp428, 107.0f, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp428, 1, 4, 0);
                func_00314560(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 0);
                func_0045af60(0, 2, 0, 5);
            }
            goto conv8F;
        } else if (D_008C024E[0] & 0x40) {
            tmp8 = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = tmp8;
            sprintf(&sp2A0, &iGpffffa8a4, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + (2))) * 0x11));
            func_002bbd80(*(s8 *)(p + 0xD), 0, &sp2A0);
            func_002bafc0(tmp8, 0);
            func_002badc0(*(s8 *)(p + 0xD), 0xB);
            func_002bb0a0(*(s8 *)(p + 0xD), 0);
            func_002bbf60();
            *(p + 1) = 0x95;
            func_0045af60(0, 0, 0, 1);
            goto conv8F;
        } else if (D_008C024E[0] & 0x20) {
            if (func_0011ba00(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                break;
            }
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 1);
            } else {
                func_00314670(*(u8 **)(p + 0x148), 3);
                func_00325450(arg0, 0, 1);
                *(p + 1) = 0x90;
                func_0045af60(0, 0, 0, 2);
            }
        } else if (D_008C024E[0] & 0x80) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 0);
            } else {
                func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 1);
            }
        }
    conv8F:
        *(s8 *)(p + 0x13A) = 0;
        break;
    case 0x90:
        if (((s8)func_00314660(*(u8 **)(p + 0x148)) < 0 || (s8)func_00314660(*(u8 **)(p + 0x148)) >= 6) && *(s8 *)func_002e4870(0) != 0) {
            var_16_5 = *(s16 *)(func_002e4870(0) + 8);
            if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                var_16_5 = 8;
            }
            if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                *(f32 *)(p + 0x124) = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
            }
            func_002b6140((u8 *)(*(s32 *)(p + 0x28C)), 0);
            func_002b6140((u8 *)(*(s32 *)(p + 0x290)), 0);
            if (*(s32 *)(func_002e4870(0) + 8) > 0) {
                func_0032b770(arg0, 0, var_16_5, 0);
                *(s16 *)(p + 0x11E) = 0;
                *(s16 *)(p + 0x120) = 0;
                *(p + 1) = 0x8B;
                return;
            }
            tmp8 = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = tmp8;
            func_002badc0(tmp8, 0xE);
            *(p + 1) = 0x93;
            return;
        }
        break;
    case 0x91:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        func_00314670(*(u8 **)(p + 0x148), 3);
        func_00325450(arg0, 0, 1);
        func_002e4610(6, 0);
        *(p + 1) = 0x90;
        return;
    case 0x92:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        *(p + 0) = 0;
        *(p + 1) = 0x1B;
        return;
    case 0x93:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        func_0032f4d0(arg0);
        func_003205f0(arg0, 0x96, 0x118);
        func_00315600(arg0, 0);
        *(p + 0) = 0;
        *(p + 1) = 0x1B;
        return;
    case 0x94:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 255.0f, 0.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == temp_16) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x118);
            func_00315600(arg0, 0);
            *(p + 0) = 0;
            *(p + 1) = 0x1B;
            return;
        }
        break;
    case 0x95:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        if (func_002bb1c0(*(s8 *)(p + 0xD)) == 0) {
            var_16_2 = *func_002e48a0(0, *(s16 *)(p + 0x11E));
            if (*func_002e48a0(0, *(s16 *)(p + 0x11E)) & 4) {
                *func_002e48a0(0, *(s16 *)(p + 0x11E)) = 0;
                *func_002e48a0(0, *(s16 *)(p + 0x11E)) |= 1;
                func_0010fd40(func_002e48a0(0, *(s16 *)(p + 0x11E)));
                *func_002e48a0(0, *(s16 *)(p + 0x11E)) = var_16_2;
            } else {
                func_0010fd40(func_002e48a0(0, *(s16 *)(p + 0x11E)));
            }
            func_002bb550(*(s8 *)(p + 0xD));
            tmp8 = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = tmp8;
            func_002badc0(tmp8, 0xD);
            *(p + 1) = 0x91;
            return;
        }
        *(p + 1) = 0x8F;
        func_002bb550(*(s8 *)(p + 0xD));
        return;
    case 0x96:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 244.0f, (f32)(s32)((temp_16 * 0x17) + 0x6E), 43.0f);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        if (func_002bb1c0(*(s8 *)(p + 0xD)) == 0) {
            var_18 = 0;
            while ((s64)((var_18 << 0x30) >> 0x30) < *(s32 *)(func_002e4870(0) + 8)) {
                bitSav = *func_002e48a0(0, var_18);
                if (*func_002e48a0(0, var_18) & 4) {
                    *func_002e48a0(0, var_18) = 0;
                    *func_002e48a0(0, var_18) |= 1;
                    func_0010fd40(func_002e48a0(0, var_18));
                    *func_002e48a0(0, var_18) = bitSav;
                } else {
                    func_0010fd40(func_002e48a0(0, var_18));
                }
                var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
            }
            func_002bb550(*(s8 *)(p + 0xD));
            tmp8 = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = tmp8;
            func_002badc0(tmp8, 0xD);
            *(p + 1) = 0x92;
            func_0032b770(arg0, 0, var_16_6, 1);
            return;
        }
        *(p + 1) = 0x8D;
        func_002bb550(*(s8 *)(p + 0xD));
        return;
    case 0x97:
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        if (func_00302570(arg0) == 0) {
            if ((s8)func_00314660(*(u8 **)(p + 0x148)) == 5) {
                func_00314670(*(u8 **)(p + 0x148), 3);
                func_00325450(arg0, 0, 1);
            }
            *(p + 1) = 0x8D;
            return;
        }
        break;
    case 0x98:
        func_002b2970(&sp420, 250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW6, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp420, colW6, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW7, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW7, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            sp1B0 = (s8)(temp_16 + 0xC);
            tmpu8 = *(u8 *)((u8 *)func_002e48a0(0, var_19) + 4);
            func_002b2970(&sp418, 74.0f, 151.0f + 23.0f * (f32)var_18);
            func_002ba5d0(*(u8 **)(p + 0x2BC), sp1B0, tmpu8, sp418, colW7, 0x59, 46.0f);
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp410, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp410, colW7, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                if (*(s16 *)(p + 0x11E) == var_19) {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30)) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -1;
                    fclWriteColorBytes(w4C0, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w4C0[0];
                    d1 = w4C0[1];
                    d2 = w4C0[2];
                    d3 = w4C0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4BC, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w4BC[0];
                    d1 = w4BC[1];
                    d2 = w4BC[2];
                    d3 = w4BC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4B8, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w4B8);
                } else {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30)) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -128;
                    fclWriteColorBytes(w4B4, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = w4B4[0];
                    d1 = w4B4[1];
                    d2 = w4B4[2];
                    d3 = w4B4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w4B0, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w4B0[0];
                    d1 = w4B0[1];
                    d2 = w4B0[2];
                    d3 = w4B0[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w4AC, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w4AC[0];
                    d1 = w4AC[1];
                    d2 = w4AC[2];
                    d3 = w4AC[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w4A8, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w4A8);
                }
            }
            tmp21F = temp_16 + 0x21F;
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                if (*(s16 *)(p + 0x11E) == var_19) {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30)) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x6E) = -1;
                    fclWriteColorBytes(w4A4, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30));
                    d0 = w4A4[0];
                    d1 = w4A4[1];
                    d2 = w4A4[2];
                    d3 = w4A4[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((tmp21F << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                } else {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30)) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x6E) = -128;
                    fclWriteColorBytes(w4A0, 0, 0, 0x99, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30));
                    d0 = w4A0[0];
                    d1 = w4A0[1];
                    d2 = w4A0[2];
                    d3 = w4A0[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((tmp21F << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150((s64)(((var_16_6 + 0x26F) << 0x30) >> 0x30)) + 0x10), 1) != 1) {
            if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
                func_0045af60(0, 0, 0, 0);
                func_0032c0c0(arg0, 5);
                return;
            } else if (D_008C027A[0] & 0x1000) {
                if (*(s16 *)(p + 0x11E) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 1);
                return;
            } else if ((D_008C0276[0] & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
                func_0045af60(0, 0, 0, 0);
                func_0032c0c0(arg0, 4);
                return;
            } else if (D_008C027A[0] & 0x4000) {
                if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 0);
                return;
            } else if (D_008C027A[0] & 0x2000) {
                if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 2);
                return;
            } else if (D_008C027A[0] & 0x8000) {
                if (*(s16 *)(p + 0x11E) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                func_0032c0c0(arg0, 3);
                return;
            } else if (D_008C0276[0] & 8) {
                if (*(s8 *)(p + 0x123) == 0) {
                    if (datGetFlag(0x1460) == 0) {
                        func_002e68b0(0);
                    }
                    *(s8 *)(p + 0x123) = 1;
                    func_0045af60(0, 0, 0, 5);
                }
                return;
            } else if (D_008C0276[0] & 4) {
                if (*(s8 *)(p + 0x123) == 1) {
                    if (datGetFlag(0x1460) == 0) {
                        func_002e68b0(0);
                    }
                    *(s8 *)(p + 0x123) = 0;
                    ps = func_002b6150(0x2EA);
                    func_002b2970(&sp458, 79.0f, *(f32 *)(func_002b6150(0x2EA) + 0x3C));
                    func_002b69f0(0x2EA, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp458, 1, 8, 0);
                    ps = func_002b6150(0x2EB);
                    func_002b2970(&sp450, (f32)0x12B, *(f32 *)(func_002b6150(0x2EB) + 0x3C));
                    func_002b69f0(0x2EB, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp450, 1, 8, 0);
                    ps = func_002b6150(0x2E2);
                    func_002b2970(&sp448, 79.0f, *(f32 *)(func_002b6150(0x2E2) + 0x3C));
                    func_002b69f0(0x2E2, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp448, 1, 8, 0);
                    ps = func_002b6150(0x2E3);
                    func_002b2970(&sp3D8, (f32)0x12B, *(f32 *)(func_002b6150(0x2E3) + 0x3C));
                    func_002b69f0(0x2E3, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3D8, 1, 8, 0);
                    func_0045af60(0, 0, 0, 5);
                }
                return;
            } else if (D_008C024E[0] & 0x40) {
                *(s8 *)(p + 0x122) = 0;
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    *(f32 *)(p + 0x124) = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b9d0(arg0, 0, var_16_2, 1);
                *(p + 1) = 0x99;
                func_0045af60(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x20) {
                var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    var_16_2 = 8;
                }
                if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                    *(f32 *)(p + 0x124) = 125.0f / (f32)(*(s32 *)(func_002e4870(0) + 8) - 8);
                }
                func_0032b9d0(arg0, 0, var_16_2, 1);
                *(p + 1) = 0x9C;
                func_0045af60(0, 0, 0, 2);
            }
        }
        *(s8 *)(p + 0x13A) = 0;
        break;
    case 0x99:
        if (func_002b6970(*(s16 *)(func_002b6150(0x270) + 0x10), 1) != 1) {
            func_00314750(*(u8 **)(p + 0x148), 0);
            func_00314450(*(u8 **)(p + 0x148), func_002e48a0(0, *(s16 *)(p + 0x11E)), 0, 1);
            func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
            func_0011d140(func_003147d0(*(u8 **)(p + 0x148)), func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_00325450(arg0, 1, 0);
            *(p + 1) = 0x9A;
            return;
        }
        break;
    case 0x9A:
        if ((s8)func_00314660(*(u8 **)(p + 0x148)) < 0 || (s8)func_00314660(*(u8 **)(p + 0x148)) >= 6) {
            break;
        }
        func_002b6140(*(s32 *)(p + 0x28C), 1);
        func_002b6140(*(s32 *)(p + 0x290), 1);
        func_002b68d0(0x84, 0, 1);
        func_002b68d0(0x85, 0, 1);
        func_002b68d0(0x1C6, 0, 1);
        func_002b68d0(0x80, 0, 1);
        func_002b68d0(0x20C, 0, 1);
        if (*(s8 *)(p + 0x122) == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 1;
            func_0011d1d0(func_003147d0(*(u8 **)(p + 0x148)), 0.0f);
        }
        if ((s8)func_00314660(*(u8 **)(p + 0x148)) == 5) {
            if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1) {
                func_0011caf0(func_003147d0(*(u8 **)(p + 0x148)));
            }
            if ((D_008C0276[0] & 0x1000) && (*(s8 *)(p + 0x13A) == 0)) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    func_0045af60(0, 2, 0, 5);
                    func_0032c0c0(arg0, 5);
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C027A[0] & 0x1000) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    if (*(s16 *)(p + 0x11E) != 0) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    func_0032c0c0(arg0, 1);
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C0252[0] & 1) {
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 5);
                func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                return;
            } else if ((D_008C0276[0] & 0x4000) && (*(s8 *)(p + 0x13A) == 0)) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    func_0045af60(0, 2, 0, 5);
                    func_0032c0c0(arg0, 4);
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C027A[0] & 0x4000) {
                if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                    if (*(s16 *)(p + 0x11E) != (s64)(((*(s32 *)(func_002e4870(0) + 8) - 1) << 0x30) >> 0x30)) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    func_0032c0c0(arg0, 0);
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    return;
                }
            } else if (D_008C0252[0] & 2) {
                func_0045af60(0, 2, 0, 5);
                func_0032c0c0(arg0, 4);
                func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                goto conv9A;
            } else if (D_008C024E[0] & 0x80) {
                if (*(s8 *)(p + 0x122) != 1) {
                    if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 0) {
                        func_0011c630(func_003147d0(*(u8 **)(p + 0x148)));
                        func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 0);
                    } else {
                        func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                        func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    }
                    goto conv9A;
                }
            } else if (D_008C024E[0] & 8) {
                if (*(s8 *)(p + 0x122) == 1) {
                    *(s8 *)(p + 0x122) = 0;
                    ps = func_002b6150(0x150);
                    func_002b2970(&sp3C8, (f32)0x141, 16.0f);
                    func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3C8, 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp3C0, (f32)0x141, 16.0f);
                    func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp3C0, 1, 4, 0);
                    func_00314750(*(u8 **)(p + 0x148), 0);
                    func_0032a960(arg0, 1);
                    func_002b2970(&sp3B8, 0.0f, 0.0f);
                    func_002b2970(&sp3B0, 0.0f, -7.0f);
                    func_002b5e90(*(s32 *)(p + 0x2AC), sp3B8, sp3B0, 4);
                    func_002b2970(&sp3A8, 0.0f, 432.0f);
                    func_002b2970(&sp3A0, 0.0f, 480.0f);
                    func_002b5e90(*(s32 *)(p + 0x2B0), sp3A8, sp3A0, 6);
                    func_002b2970(&sp398, 0.0f, 69.0f);
                    func_002b2970(&sp390, 0.0f, 93.0f);
                    func_002b29e0(&sp210, 640.0f, (f32)0x157);
                    func_002b29e0(&sp200, 640.0f, 294.0f);
                    func_002b5ef0(*(s32 *)(p + 0x2B4), sp398, sp390, &sp210, &sp200, 5);
                    func_002b60f0(*(s32 *)(p + 0x2B4), 0xE5, 0, 5);
                    func_00317320(arg0, 0, 0);
                    func_00314450(*(u8 **)(p + 0x148), func_0010fcb0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)), 0, 1);
                    func_0045af60(0, 0, 0, 5);
                }
                goto conv9A;
            } else if (D_008C024E[0] & 4) {
                if (*(s8 *)(p + 0x122) == 0) {
                    *(s8 *)(p + 0x122) = 1;
                    ps = func_002b6150(0x150);
                    func_002b2970(&sp388, 107.0f, 16.0f);
                    func_002b69f0(0x150, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp388, 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp380, 107.0f, 16.0f);
                    func_002b69f0(0x2E0, *(FclVec2f *)(ps + 0x38), *(FclVec2f *)&sp380, 1, 4, 0);
                    func_00314750(*(u8 **)(p + 0x148), 1);
                    func_0032a960(arg0, 0);
                    func_0045af60(0, 0, 0, 5);
                    func_002b2970(&sp378, 0.0f, -10.0f);
                    func_002b2970(&sp370, 0.0f, 0.0f);
                    func_002b5e90(*(s32 *)(p + 0x2AC), sp378, sp370, 4);
                    func_002b2970(&sp368, 0.0f, 480.0f);
                    func_002b2970(&sp360, 0.0f, 432.0f);
                    func_002b5e90(*(s32 *)(p + 0x2B0), sp368, sp360, 6);
                    func_002b2970(&sp358, 0.0f, 93.0f);
                    func_002b2970(&sp350, 0.0f, 69.0f);
                    func_002b29e0(&sp1F0, 640.0f, 294.0f);
                    func_002b29e0(&sp1E0, 640.0f, (f32)0x157);
                    func_002b5ef0(*(s32 *)(p + 0x2B4), sp358, sp350, &sp1F0, &sp1E0, 5);
                    func_002b60f0(*(s32 *)(p + 0x2B4), 0, 0xE5, 5);
                    func_00317240(arg0, 1, 0);
                }
                goto conv9A;
            } else if (D_008C024E[0] & 0x40) {
                func_0045af60(0, 0, 0, 1);
                if (func_0010ac10(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2)) != 0) {
                    func_00310960(arg0, 0x12, 0);
                    *(p + 1) = 0x9D;
                    return;
                }
                if ((func_0010b6f0() & 0xFFFF) >= (func_0010b5b0() & 0xFFFF)) {
                    func_00310960(arg0, 0x14, 0);
                    *(p + 1) = 0x9D;
                    return;
                }
                sumA = func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 0) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 1) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 2) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 3) & 0xFF;
                sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 4) & 0xFF;
                sumB = func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 0) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 1) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 2) & 0xFF;
                sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 3) & 0xFF;
                total = sumA * (sumB + (func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 4) & 0xFF)) + 0x7D0;
                saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2), total);
                if (func_002e7a60() >= saved) {
                    tmp8 = func_002bab80((void *)func_00331660());
                    *(s8 *)(p + 0xD) = tmp8;
                    sprintf(&sp2A0, &iGpffffa8a4, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + (2))) * 0x11));
                    func_002bbd80(*(s8 *)(p + 0xD), 0, &sp2A0);
                    sprintf(&sp220, &iGpffffa8a4 - 4, saved);
                    func_002bbd80(*(s8 *)(p + 0xD), 1, &sp220);
                    func_002bafc0(*(s8 *)(p + 0xD), 0);
                    func_002badc0(*(s8 *)(p + 0xD), 0xF);
                    func_002bb0a0(*(s8 *)(p + 0xD), 0);
                    func_002bbf60();
                    *(p + 1) = 0x9E;
                    goto conv9A;
                } else {
                    func_00310960(arg0, 0x11, 0);
                    *(p + 1) = 0x9D;
                    goto conv9A;
                }
            } else if (D_008C024E[0] & 0x20) {
                if (func_0011ba00(func_003147d0(*(u8 **)(p + 0x148))) != 1) {
                    if (func_0011c610(func_003147d0(*(u8 **)(p + 0x148))) == 1 && *(s8 *)(p + 0x122) == 0) {
                        func_0011c6e0(func_003147d0(*(u8 **)(p + 0x148)), 1);
                        func_00314740(func_003147d0(*(u8 **)(p + 0x148)), 1);
                    } else {
                        func_0045af60(0, 0, 0, 2);
                        func_00314670(*(u8 **)(p + 0x148), 3);
                        func_00325450(arg0, 1, 1);
                        if (*(s8 *)(p + 0x122) == 1) {
                            func_0032a960(arg0, 1);
                            func_002b2970(&sp348, 0.0f, 0.0f);
                            func_002b2970(&sp340, 0.0f, -7.0f);
                            func_002b5e90(*(s32 *)(p + 0x2AC), sp348, sp340, 5);
                            func_002b2970(&sp338, 0.0f, 432.0f);
                            func_002b2970(&sp330, 0.0f, 480.0f);
                            func_002b5e90(*(s32 *)(p + 0x2B0), sp338, sp330, 5);
                            func_002b2970(&sp328, 0.0f, 69.0f);
                            func_002b2970(&sp320, 0.0f, 239.0f);
                            func_002b29e0(&sp1D0, 640.0f, (f32)0x157);
                            func_002b29e0(&sp1C0, 640.0f, 0.0f);
                            func_002b5ef0(*(s32 *)(p + 0x2B4), sp328, sp320, &sp1D0, &sp1C0, 5);
                        } else {
                            func_00317240(arg0, 1, 0);
                        }
                        func_0034a890(*(s32 *)(p + 0x254));
                        var_16_2 = *(s16 *)(func_002e4870(0) + 8);
                        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
                            var_16_2 = 8;
                        }
                        func_0032b9d0(arg0, 0, var_16_2, 0);
                        *(p + 1) = 0x9B;
                        *(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 1;
                        func_0034a840(*(s32 *)(p + 0x254));
                        func_002b68d0(0x80, 0, 0);
                        func_002b68d0(0x20C, 0, 0);
                        func_002b6140(*(s32 *)(p + 0x28C), 0);
                        func_002b6140(*(s32 *)(p + 0x290), 0);
                        func_002b68d0(0x84, 0, 0);
                        func_002b68d0(0x85, 0, 0);
                        func_002b68d0(0x1C6, 0, 0);
                    }
                    goto conv9A;
                }
            }
        }
    conv9A:
        *(s8 *)(p + 0x13A) = 0;
        return;
    case 0x9B:
        func_002b2970(&sp318, 250.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW3, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp318, colW3, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW4, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW4, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            tmp22 = temp_16 + 0x2A3;
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                *(s16 *)(func_002b6150((s64)((tmp22 << 0x30) >> 0x30)) + 4) = (s16)((func_00109280(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2)) & 0xFF) + 0x1B);
            }
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp310, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp310, colW4, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                if (*(s16 *)(p + 0x11E) == var_19) {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30)) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -1;
                    fclWriteColorBytes(w498, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w498[0];
                    d1 = w498[1];
                    d2 = w498[2];
                    d3 = w498[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    r4 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = *(r3 + 0x85);
                    d1 = *(r3 + 0x86);
                    d2 = *(r3 + 0x87);
                    d3 = *(r3 + 0x88);
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w494, 0x2D, 0x2D, 0x2D, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w494[0];
                    d1 = w494[1];
                    d2 = w494[2];
                    d3 = w494[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w490, 0x2D, 0x2D, 0x2D, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w490);
                } else {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30)) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x6E) = -128;
                    fclWriteColorBytes(w48C, 0x49, 0x72, 0xFF, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x27D) << 0x30) >> 0x30));
                    d0 = w48C[0];
                    d1 = w48C[1];
                    d2 = w48C[2];
                    d3 = w48C[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((temp_21 << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                    fclWriteColorBytes(w488, 0x49, 0x72, 0xFF, 0xFF);
                    r4 = func_002b6150((s64)(((temp_16 + 0x297) << 0x30) >> 0x30));
                    d0 = w488[0];
                    d1 = w488[1];
                    d2 = w488[2];
                    d3 = w488[3];
                    *(r4 + 0x85) = d0;
                    *(r4 + 0x86) = d1;
                    *(r4 + 0x87) = d2;
                    *(r4 + 0x88) = d3;
                    r5 = func_002b6150((s64)(((temp_16 + 0x28B) << 0x30) >> 0x30));
                    d0 = *(r4 + 0x85);
                    d1 = *(r4 + 0x86);
                    d2 = *(r4 + 0x87);
                    d3 = *(r4 + 0x88);
                    *(r5 + 0x85) = d0;
                    *(r5 + 0x86) = d1;
                    *(r5 + 0x87) = d2;
                    *(r5 + 0x88) = d3;
                    fclWriteColorBytes(w484, 0, 0, 0x66, 0xFF);
                    r6 = func_002b6150((s64)((tmp22 << 0x30) >> 0x30));
                    d0 = w484[0];
                    d1 = w484[1];
                    d2 = w484[2];
                    d3 = w484[3];
                    *(r6 + 0x85) = d0;
                    *(r6 + 0x86) = d1;
                    *(r6 + 0x87) = d2;
                    *(r6 + 0x88) = d3;
                    fclWriteColorBytes(&w480, 0xCC, 0xFF, 0xFF, 0xFF);
                    func_002ba970(*(s32 *)(p + 0x2BC), (s8)(temp_16 + 0xC), w480);
                }
            }
            tmp21F = temp_16 + 0x21F;
            if (func_002b6970(*(s16 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x10), 1) == 0) {
                if (*(s16 *)(p + 0x11E) == var_19) {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30)) + 0x6E) = -1;
                    *(s8 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x6E) = -1;
                    fclWriteColorBytes(w47C, 0xCC, 0xFF, 0x33, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30));
                    d0 = w47C[0];
                    d1 = w47C[1];
                    d2 = w47C[2];
                    d3 = w47C[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((tmp21F << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                } else {
                    *(s8 *)(func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30)) + 0x6E) = -128;
                    *(s8 *)(func_002b6150((s64)((tmp21F << 0x30) >> 0x30)) + 0x6E) = -128;
                    fclWriteColorBytes(w478, 0, 0, 0x99, 0xFF);
                    r2 = func_002b6150((s64)(((temp_16 + 0x2C5) << 0x30) >> 0x30));
                    d0 = w478[0];
                    d1 = w478[1];
                    d2 = w478[2];
                    d3 = w478[3];
                    *(r2 + 0x85) = d0;
                    *(r2 + 0x86) = d1;
                    *(r2 + 0x87) = d2;
                    *(r2 + 0x88) = d3;
                    r3 = func_002b6150((s64)((tmp21F << 0x30) >> 0x30));
                    d0 = *(r2 + 0x85);
                    d1 = *(r2 + 0x86);
                    d2 = *(r2 + 0x87);
                    d3 = *(r2 + 0x88);
                    *(r3 + 0x85) = d0;
                    *(r3 + 0x86) = d1;
                    *(r3 + 0x87) = d2;
                    *(r3 + 0x88) = d3;
                }
            }
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if ((s8)func_00314660(*(u8 **)(p + 0x148)) == 6) {
            func_0011d1d0(func_003147d0(*(u8 **)(p + 0x148)), 0.0f);
            *(p + 1) = 0x98;
            return;
        }
        break;
    case 0x9C:
        var_16_6 = *(s16 *)(func_002e4870(0) + 8);
        if (*(s32 *)(func_002e4870(0) + 8) >= 9) {
            var_16_6 = 8;
        }
        var_19 = (s64)(*(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120));
        func_002b2970(&sp308, 254.0f + *(f32 *)(func_002b6150(0x69) + 0x38), 46.0f);
        fclWriteColorBytes(&colW1, 0xFF, 0xFF, 0xFF, 0xFF);
        tmpe = func_002e7a60();
        tmpv = (s32)func_0046a770(&D_00641B30);
        func_002cacd0(sp308, colW1, 0x10, 5, tmpe, 9, 0x37, tmpv, 47.0f, func_00331560(), 0x56);
        var_18 = 0;
        var_22 = var_16_6 + var_19;
        while ((s64)((var_19 << 0x30) >> 0x30) < var_22) {
            temp_16 = (s64)((var_18 << 0x30) >> 0x30);
            temp_21 = temp_16 + 0x270;
            temp_f20 = (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x42));
            temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, temp_f20, (f32)(*(s16 *)(func_002b6150((s64)((temp_21 << 0x30) >> 0x30)) + 0x40)));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = ((s32)(temp_f0)) & 0xFF;
            } else {
                var_3 = (((s32)((temp_f0 - 2.1474836e9f))) | 0x80000000) & 0xFF;
            }
            temp_7 = var_3 & 0xFF;
            if (*(s16 *)(p + 0x11E) == var_19) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
                fclWriteColorBytes(&colW2, 0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
                fclWriteColorBytes(&colW2, 0xCC, 0xFF, 0xFF, temp_7);
            }
            func_00275820(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + (2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 172.0f, (f32)(s32)((temp_16 * 0x17) + 0x96), 43.0f);
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            sumB = (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF) + sumA;
            sumA = func_001099f0(func_002e48a0(0, var_19), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, var_19), 3) & 0xFF;
            total = sumB * (sumA + (func_001099f0(func_002e48a0(0, var_19), 4) & 0xFF)) + 0x7D0;
            func_002b2970(&sp300, 510.0f, (f32)(s32)((temp_16 * 0x17) + 0x9E));
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, var_19)) + 2), total);
            tmpv = (s32)func_0046a770(&D_00641B30);
            func_002cacd0(sp300, colW2, 0x10, 5, saved, 9, 0x37, tmpv, 47.0f, func_00331560(), 0xAA);
            var_19 = (s64)((var_19 + 1) << 0x30) >> 0x30;
            var_18 = (s64)((var_18 + 1) << 0x30) >> 0x30;
        }
        if (func_002b6970(*(s16 *)(func_002b6150(0x193) + 0x10), 1) == 0) {
            func_0032f4d0(arg0);
            func_003205f0(arg0, 0x96, 0x117);
            func_00315600(arg0, 0);
            *(p + 0) = 0;
            *(p + 1) = 0x1B;
            return;
        }
        break;
    case 0x9D:
        if (*(s8 *)(p + 0x122) == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 1;
            func_0011d1d0(func_003147d0(*(u8 **)(p + 0x148)), 0.0f);
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        *(p + 1) = 0x9A;
        return;
    case 0x9E:
        if (*(s8 *)(p + 0x122) == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 1;
            func_0011d1d0(func_003147d0(*(u8 **)(p + 0x148)), 0.0f);
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        if (func_002bb1c0(*(s8 *)(p + 0xD)) == 0) {
            func_0010b190((u8 *)func_002e48a0(0, *(s16 *)(p + 0x11E)));
            sumA = func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 0) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 1) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 2) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 3) & 0xFF;
            sumA += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 4) & 0xFF;
            sumB = func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 0) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 1) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 2) & 0xFF;
            sumB += func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 3) & 0xFF;
            total = sumA * (sumB + (func_001099f0(func_002e48a0(0, *(s16 *)(p + 0x11E)), 4) & 0xFF)) + 0x7D0;
            saved = func_003026c0(*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + 2), total);
            func_002e7a80(func_002e7a60() - saved);
            func_002bb550(*(s8 *)(p + 0xD));
            tmp8 = func_002bab80((void *)func_00331660());
            *(s8 *)(p + 0xD) = tmp8;
            func_002bbd80(*(s8 *)(p + 0xD), 0, (void *)(((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, *(s16 *)(p + 0x11E))) + (2))) * 0x11)));
            func_002badc0(*(s8 *)(p + 0xD), 0x10);
            *(p + 1) = 0x9F;
            func_0045af60(1, 0, 2, 6);
            if (*(s32 *)(p + 0x2B8) != 0) {
                *(s32 *)(p + 0x2B8) = 0;
            }
            *(s32 *)(p + 0x2B8) = func_00349290(arg0, *(s8 *)(p + 0x122));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        *(p + 1) = 0x9A;
        return;
    case 0x9F:
        if (*(s8 *)(p + 0x122) == 1) {
            func_0032c480(arg0);
        } else {
            *(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 1;
            func_0011d1d0(func_003147d0(*(u8 **)(p + 0x148)), 0.0f);
        }
        if (func_002bb680(*(s8 *)(p + 0xD)) != 0) {
            func_002bbcf0(*(s8 *)(p + 0xD));
            return;
        }
        func_002bb550(*(s8 *)(p + 0xD));
        *(p + 1) = 0x9A;
        return;
    default:
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002fbea0);
#endif

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
   s64 constructor homes, then fv7..fv1, then buf. */
// FUN_00302770
void func_00302770(u8 *arg0) {
    extern u8 *func_002b81f0(u8 *arg0);
    extern void func_00325450(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_0032c660(u8 *arg0, s32 arg1, s64 arg2, s64 arg3, s32 arg4, s32 arg5);
    extern void func_0032e570(u8 *arg0);
    extern void func_0033e540(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s32 arg4);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void sprintf(void *dst, const char *fmt, ...);
    extern u16 D_008C024E[];
    extern s32 iGpffffa8a0;
    FclVec2f fv0;
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
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
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
        func_002b2970((u8 *)&sp250, 640.0f, 98.0f);
        func_002b2970((u8 *)&sp248, (f32)413, 99.0f);
        func_0033e540(*(u8 **)(p + 0x250), sp250, sp248, 6, 0);
        func_00316e80((s32)arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    case 0x70:
        func_00313b50(arg0);
        *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
        sprintf(buf, (const char *)&iGpffffa8a0, func_002e78a0());
        func_002bbd80(*(s8 *)(p + 0xD), 0, buf);
        sprintf(buf, (const char *)&iGpffffa8a0, func_002e78e0());
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
            func_002b2970((u8 *)&sp240, 57.0f, 72.0f);
            func_002b2970((u8 *)&sp238, -346.0f, 72.0f);
            func_0032c660(arg0, 0, sp240, sp238, 1, 0);
            func_002b2970((u8 *)&sp230, 460.0f, 72.0f);
            func_002b2970((u8 *)&sp228, 460.0f, 72.0f);
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
        func_002b2970((u8 *)&sp220, fv0.x - 50.0f, fv0.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x258)) = *(FclVec2f *)&sp220;
        q = func_002b6150(0x2E2);
        fv1 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp218, fv1.x - 50.0f, fv1.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x25C)) = *(FclVec2f *)&sp218;
        q = func_002b6150(0x2E9);
        fv2 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp210, fv2.x - 50.0f, fv2.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x260)) = *(FclVec2f *)&sp210;
        q = func_002b6150(0x2EF);
        fv3 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp208, fv3.x - 50.0f, fv3.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x264)) = *(FclVec2f *)&sp208;
        if ((s16)func_002b6970(*(s16 *)(func_002b6150(0x1CA) + 0x10), 1) != 1) {
            if (D_008C024E[0] & 8) {
                if (*(s8 *)(p + 0x122) != 1) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                func_002b2970((u8 *)&sp200, (f32)321, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(q + 0x38), *(FclVec2f *)&sp200, 1, 4, 0);
                q = func_002b6150(0x2E0);
                func_002b2970((u8 *)&sp1F8, (f32)321, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(q + 0x38), *(FclVec2f *)&sp1F8, 1, 4, 0);
                func_002b2970((u8 *)&sp1F0, 57.0f, 72.0f);
                func_002b2970((u8 *)&sp1E8, -346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1F0, sp1E8, 0, 1);
                func_002b2970((u8 *)&sp1E0, 460.0f, 72.0f);
                func_002b2970((u8 *)&sp1D8, 460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1E0, sp1D8, 0, 0);
                *(s8 *)(p + 0x122) = 0;
            } else if (D_008C024E[0] & 4) {
                if (*(s8 *)(p + 0x122) != 0) {
                    break;
                }
                func_0045af60(0, 0, 0, 5);
                q = func_002b6150(0x150);
                func_002b2970((u8 *)&sp1D0, 107.0f, 16.0f);
                func_002b69f0(0x150, *(FclVec2f *)(q + 0x38), *(FclVec2f *)&sp1D0, 1, 4, 0);
                q = func_002b6150(0x2E0);
                func_002b2970((u8 *)&sp1C8, 107.0f, 16.0f);
                func_002b69f0(0x2E0, *(FclVec2f *)(q + 0x38), *(FclVec2f *)&sp1C8, 1, 4, 0);
                func_002b2970((u8 *)&sp1C0, 57.0f, 72.0f);
                func_002b2970((u8 *)&sp1B8, -346.0f, 72.0f);
                func_0032c660(arg0, 0, sp1C0, sp1B8, 0, 0);
                func_002b2970((u8 *)&sp1B0, 460.0f, 72.0f);
                func_002b2970((u8 *)&sp1A8, 460.0f, 72.0f);
                func_0032c660(arg0, 1, sp1B0, sp1A8, 0, 1);
                *(s8 *)(p + 0x122) = 1;
            } else if ((D_008C024E[0] & 0x20) && p[1] == 0x73) {
                func_002bb550(*(s8 *)(p + 0xD));
                func_0045af60(0, 0, 0, 2);
                func_00325450(arg0, 2, 1);
                if (*(s8 *)(p + 0x122) == 1) {
                    func_002b2970((u8 *)&sp1A0, 57.0f, 72.0f);
                    func_002b2970((u8 *)&sp198, 940.0f, 72.0f);
                    func_0032c660(arg0, 0, sp1A0, sp198, 0, 1);
                    func_002b2970((u8 *)&sp190, 460.0f, 72.0f);
                    func_002b2970((u8 *)&sp188, 940.0f, 72.0f);
                    func_0032c660(arg0, 1, sp190, sp188, 0, 1);
                    func_002b68d0(0x2E8, 0, 1);
                    func_002b68d0(0x2EE, 0, 1);
                } else if (*(s8 *)(p + 0x122) == 0) {
                    func_002b2970((u8 *)&sp180, 57.0f, 72.0f);
                    func_002b2970((u8 *)&sp178, -640.0f, 72.0f);
                    func_0032c660(arg0, 0, sp180, sp178, 0, 1);
                    func_002b2970((u8 *)&sp170, 460.0f, 72.0f);
                    func_002b2970((u8 *)&sp168, -640.0f, 72.0f);
                    func_0032c660(arg0, 1, sp170, sp168, 0, 1);
                }
                func_002eb270(arg0, 0);
                p[1] = 0x74;
                func_00316e80((s32)arg0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                func_002b2970((u8 *)&sp160, (f32)413, 99.0f);
                func_002b2970((u8 *)&sp158, 640.0f, 98.0f);
                func_0033e540(*(u8 **)(p + 0x250), sp160, sp158, 6, 0);
                func_00315600(arg0, 0);
                func_00320970(arg0, 0);
            }
        }
        break;
    case 0x74:
        q = func_002b6150(0x2E3);
        fv4 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp150, fv4.x - 50.0f, fv4.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x258)) = *(FclVec2f *)&sp150;
        q = func_002b6150(0x2E2);
        fv5 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp148, fv5.x - 50.0f, fv5.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x25C)) = *(FclVec2f *)&sp148;
        q = func_002b6150(0x2E9);
        fv6 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp140, fv6.x - 50.0f, fv6.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x260)) = *(FclVec2f *)&sp140;
        q = func_002b6150(0x2EF);
        fv7 = *(FclVec2f *)(q + 0x38);
        func_002b2970((u8 *)&sp138, fv7.x - 50.0f, fv7.y - 50.0f);
        *(FclVec2f *)func_002b81f0(*(u8 **)(p + 0x264)) = *(FclVec2f *)&sp138;
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
            func_002b2970((u8 *)&sp130, 640.0f, 98.0f);
            func_002b2970((u8 *)&sp128, (f32)413, 99.0f);
            func_0033e540(*(u8 **)(p + 0x250), sp130, sp128, 6, 0);
            func_00316e80((s32)arg0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
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
        entry = table + (s16)(RpRandom() % (u32)divisor);
        selected = *entry;
        if (func_0010ce10(copy, selected) == -1) {
            retry = 1;
        }
    } while ((s8)retry == 0);
    return selected;
}
/* measured 00304580 2026-09-19: object 4473 against retail's 4557 trimmed instructions (4560 raw), -1.84% inside the 4423-4697 band with
   50 instructions of headroom above lower (224 below upper); 2299 fnalign edits (+30 reloc-only), 3791 differing words.
   No pragmas: retail here is unscheduled like the rest of this unit.
   Built from the m2c oracle from src/generated/code1_0030.c de-noised to this file's idiom - M2C_FIELD expanded to direct
   casts, the gp temporaries resolved to ((s32)iGpffffb440) and iGpffff8504 and iGpffffb3ec and &iGpffffa8a4, the four M2C_ERROR
   ldr/ldl sites at 0x38/0x3F written as struct-by-value `*(FclVec2f *)(ps + 0x38)` with `ps = func_002b6150(0x151/0x2E0)`,
   the 0x28/0x2F site kept as s64 ld (1 instruction short, accepted for gate), the 12 colour bases with their M2C_UNK companions
   folded to u8 colXXX[4] (`&sp` -> col, `(s32)sp` -> (*(s32 *)col), `sp` -> col[0]), the six 5-byte buffers to u8 spXXX[8]
   (`(temp+sp)+0x2XX` -> spXXX[temp]), the s128 pointer slots to u8* (except spE0 kept s64), 8 s64 temporaries narrowed to s32
   (4751 -> 4473) to land inside, the outer switch kept whole through 0x89 (retail sltiu 0x15, no empty arms), inner 0-2 switches
   kept as jtbl, the m2c arg-count hallucinations cut back, the float bit patterns collapsed (0x42000000->32.0f etc.),
   and D_008C027A/024E to [0]. */
/* measured: seven `s64` temps were forcing MWCC's `__floatdisf` runtime call
   where retail converts in 32 bits.  Six are the sign-extend-from-16 idiom
   `(s64)(x << 0x30) >> 0x30` (temp_16_2, temp_21_4, temp_16_11, temp_16_14,
   temp_16_29, temp_16_36), rewritten as the `s32` they are with an `(s16)`
   cast on the right-hand side; the seventh, spE0, was a gratuitous `(s64)`
   cast around an `s32` sum.
   Retail evidence, asm/nonmatchings/y_fclCombine/func_00304580.s: at
   0x00304F7C the sequence is `addiu $2, $19, 0x149` / `mtc1 $2, $f0` / nop /
   `cvt.s.w $f12, $f0`, a 32-bit integer-to-float conversion inline with NO
   call between the integer arithmetic and the float use - a `__floatdisf`
   would need a `jal` and its argument setup right there.  All 33 conversions
   in the retail listing are `cvt.s.w`.
   Helpers 3 -> 0.  Object 4473 -> 4477 against retail 4557, so this floor is
   the SHORTER-than-retail case: the count is not the test (see the amended
   rule - a helper call is longer than the `mtc1`/`cvt.s.w` pair that replaces
   it, so removal cannot move a short object toward retail).  It moved 4 the
   right way anyway.  Edits 2299 -> 2279, differing words 3791 -> 3778. */
// FUN_00304580 NONMATCHING
#ifdef NON_MATCHING
void func_00304580(u8 *arg0) {
    u8 col2FC[4];
    u8 col2F8[4];
    u8 col2F4[4];
    u8 col2F0[4];
    u8 col2EC[4];
    u8 col2E8[4];
    u8 col2E4[4];
    u8 col2E0[4];
    u8 col2DC[4];
    u8 col2D8[4];
    u8 col2D4[4];
    u8 col2D0[4];
    u8 *ps;

    extern s32 datGetFlag(s32);
    extern void func_00106390(s32, s32);
    extern s32 func_0010b5b0(void);
    extern s32 func_0010b6f0(void);
    extern void func_0011b8f0(u8 *, s32);
    extern s32 func_0011c610(u8 *);
    extern void func_0011c630(u8 *);
    extern void func_0011c6e0(u8 *, s32);
    extern void func_0011caf0(u8 *);
    extern s32 func_0011cc00(u8 *, u16, u16);
    extern void func_0011d140(u8 *, s32);
    extern void *func_00243840(u16);
    extern s32 func_00275520(s32, s32, s32, s32, s32, s32, const char *, f32, f32, f32);
    extern s32 func_00275820(s32, s32, s32, s32, s32, s32, const char *, s32, f32, f32, f32);
    extern void func_002b2970(s64 *, f32, f32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern f32 func_002b2aa0(s32, s32, f32, f32, f32);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern u8 *func_002b6150(s16);
    extern void func_002b68d0(s16, s32, s32);
    extern s32 func_002b6970(s16, s32);
    extern void func_002b69f0(s16, FclVec2f, FclVec2f, u32, u32, s16);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);

    extern void func_002ba970(s32, s8, s32);
    extern s8 func_002bab80(void *);
    extern void func_002badc0(s8, s32);
    extern void func_002bafc0(s8, s32);
    extern void func_002bb0a0(s8, s32);
    extern s8 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern void func_002bbd80(s8, s32, void *);
    extern void func_002bbf60(void);
    extern void func_002e4610(s32, s8);
    extern u8 *func_002e4870(s8);
    extern u16 *func_002e48a0(s8, s16);
    extern void func_002e5000(void);
    extern void func_00310960(u8 *, s32, s32);
    extern void func_00314450(u8 *, u16 *, s32, s32);
    extern void func_003144d0(u8 *, u16 *, s32, s32, s32);
    extern s8 func_00314660(u8 *);
    extern void func_00314670(u8 *, s8);
    extern void func_003146f0(u8 *, u16 *, s8);
    extern void func_00314740(u8 *, s8);
    extern u8 *func_003147d0(u8 *);
    extern void func_00315600(u8 *, s32);
    extern void func_00316470(u8 *, s64, s64);
    extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_00317240(u8 *, s64, s32);
    extern void func_003191c0(u8 *, s64, s32, u16, u8, s32, s32, s8);
    extern void func_0031ac10(u8 *, s64, s8, s32, u16, u8, s32, s32, s32, s32);
    extern void func_0031c2b0(u8 *, s64, s32, s32);
    extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
    extern void func_0031fa20(u8 *, s64, s32, s32);
    extern void func_003205f0(u8 *, s32, s32);
    extern void func_00320b80(u8 *, s32);
    extern void func_003218a0(u8 *, s32);
    extern void func_00325450(u8 *, s32, s32);
    extern void func_0032f4d0(u8 *);
    extern void func_0032fbc0(u8 *);
    extern s32 func_00331560(void);
    extern s32 func_00331660(void);
    extern u32 RpRandom(void);
    extern void sprintf(void *, void *, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern f32 func_0046b2f0(s32);
    extern s32 func_0046d200(s32, s32);
    extern void func_0046d280(s32);
    extern f32 D_00640C10[];
    extern u8 D_00749350[];
    extern u8 D_00795E60[];
    extern u16 D_008C024C;
    extern u16 D_008C024E[];
    extern u16 D_008C027A[];
    extern s8 D_007490F8[];
    extern f32 iGpffff8504;

    extern u16 *func_00308cc0(u8 *);
    extern s32 func_00308dc0(u8 *);
    extern s32 func_00308e50(u8 *);
    extern u16 func_003095f0(void);
    extern s32 func_00309630(u16);
    extern s32 func_003096d0(u8 *);
    extern s32 func_0010cd70(u8 *, s32, u16);
    extern void func_00110270(u8 *, u16);
    extern void func_001102c0(u16);
    extern s32 func_001102d0(void);
    extern u16 *func_001102e0(void);
    extern u16 *func_0010ace0(s16);
    extern s32 func_0010ad80(s32);
    extern void func_0010cad0(u8 *, u16);
    extern char iGpffffa8a4;


    u8 sp2C8[8];
    u8 sp2C0[8];
    u8 sp2B8[8];
    u8 sp2B0[8];
    u8 sp2A8[8];
    u8 sp2A0[8];
    s64 sp298;
    s64 sp290;
    s64 sp288;
    s64 sp280;
    s64 sp278;
    s64 sp270;
    s64 sp268;
    s64 sp260;
    s64 sp258;
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
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    s32 sp120;
    s32 sp11C;
    u8 *sp100;
    u8 *spF0;
    s32 spE0;
    u8 *spD0;
    f32 temp_f0;
    f32 temp_f20;
    s16 *temp_18_2;
    s16 *temp_21;
    s16 *temp_21_5;
    s16 *temp_22;
    s16 *temp_22_2;
    s16 *temp_23;
    s16 *temp_23_2;
    s16 *temp_2_3;
    s16 *temp_30;
    s16 *temp_30_2;
    s16 temp_16_5;
    s16 temp_2_46;
    s16 temp_2_47;
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
    s32 temp_21_2;
    s32 temp_21_3;
    s32 temp_21_6;
    s32 temp_3_2;
    s32 temp_4_3;
    s32 var_18_3;
    s32 var_18_4;
    s32 var_21;
    s32 var_21_2;
    s32 var_3;
    s32 temp_16_11;
    s32 temp_16_14;
    s32 temp_16_29;
    s32 temp_16_2;
    s32 temp_16_36;
    s64 temp_16_37;
    s64 temp_16_4;
    s64 temp_16_7;
    s64 temp_16_9;
    s64 temp_18_14;
    s64 temp_18_16;
    s64 temp_18_17;
    s64 temp_18_3;
    s64 temp_18_6;
    s64 temp_18_8;
    s64 temp_18_9;
    s64 temp_19_2;
    s32 temp_21_4;
    s64 temp_21_7;
    s64 temp_21_8;
    s64 temp_22_3;
    s64 temp_23_3;
    s64 temp_2_2;
    s64 temp_30_3;
    s64 temp_3_10;
    s64 temp_3_11;
    s64 temp_3_12;
    s64 temp_3_14;
    s64 temp_3_16;
    s64 temp_3_17;
    s64 temp_3_18;
    s64 temp_3_19;
    s64 temp_3_20;
    s64 temp_3_3;
    s64 temp_3_4;
    s64 temp_3_9;
    s32 temp_4;
    s64 temp_4_2;
    s64 var_16;
    s64 var_16_2;
    s64 var_16_3;
    s64 var_16_4;
    s64 var_16_5;
    s32 var_18;
    s32 var_18_2;
    s64 var_18_5;
    s64 var_18_6;
    s64 var_18_7;
    s64 var_18_8;
    s32 var_18_9;
    s32 var_19;
    s32 var_19_2;
    s64 var_19_3;
    s32 var_19_4;
    s64 var_19_5;
    s64 var_19_6;
    s64 var_4;
    s64 var_4_2;
    s64 var_4_3;
    s64 var_4_4;
    s64 var_4_5;
    s64 var_4_6;
    s64 var_4_7;
    s64 var_5;
    s32 var_6;
    s8 temp_2;
    s8 temp_2_23;
    s8 temp_2_27;
    s8 temp_2_37;
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
    u16 temp_16_15;
    u16 temp_16_17;
    u16 temp_16_19;
    u16 temp_16_25;
    u16 temp_16_31;
    u16 temp_16_6;
    u16 temp_19;
    u16 temp_19_4;
    u16 temp_19_5;
    u16 temp_19_6;
    u16 temp_19_7;
    u16 temp_19_8;
    u8 temp_16_12;
    u8 temp_16_18;
    u8 temp_16_20;
    u8 temp_16_23;
    u8 temp_16_26;
    u8 temp_16_27;
    u8 temp_16_30;
    u8 temp_16_34;
    u8 temp_18;
    u8 temp_18_10;
    u8 temp_18_5;
    u8 temp_3;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_6;
    u8 temp_6_2;
    u8 temp_7;
    u8 *temp_16_3;
    u8 *temp_16_40;
    u8 *temp_16_8;
    u8 *temp_17;
    u8 *temp_18_11;
    u8 *temp_18_12;
    u8 *temp_18_13;
    u8 *temp_18_15;
    u8 *temp_18_7;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_36;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    temp_17 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
    temp_3 = (u8)((*(u8 *)((u8 *)(temp_17)+(1))));
    switch (temp_3) {                               /* switch 1 */
    case 0x75:                                      /* switch 1 */
        if (datGetFlag(0x131C) == 0) {
            temp_2 = func_002bab80((void *)func_00331660());
            (*(s8 *)((u8 *)(temp_17)+(0xD))) = temp_2;
            func_002badc0((s64) ((s64) temp_2 << 0x38) >> 0x38, 0x50);
            func_00106390(0x131C, 1);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x76U;
            return;
        }
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x77U;
        return;
    case 0x76:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x77U;
        return;
    case 0x77:                                      /* switch 1 */
        func_00315600(arg0, 1);
        if (datGetFlag(0x1306) != 0) {
            func_00314740((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 1);
            func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
            temp_16 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
            func_0011d140((u8 *)temp_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_003146f0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_001102e0(), 0);
            func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 1);
            if (datGetFlag(0x1307) == 0) {
                temp_3_2 = func_001102d0() & 0xFFFF;
                var_5 = (s64) ((temp_3_2 & 0xF) << 0x38) >> 0x38;
                temp_4 = (s64) (((temp_3_2 >> 0xC) & 0xF) << 0x38) >> 0x38;
                var_6 = 0;
loop_12:
                temp_3_3 = (s64) (var_6 << 0x30) >> 0x30;
                if (temp_3_3 < 5) {
                    (*(s8 *)((u8 *)((temp_17 + temp_3_3))+(0x30C))) = 0;
                    var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                    goto loop_12;
                }
                temp_3_4 = (s64) (var_5 << 0x38) >> 0x38;
                switch (temp_3_4) {                 /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    var_6 = 0;
                    var_5 = ((s64) (temp_4 << 0x38) >> 0x38) + 1;
loop_20:
                    if (((s64) (var_6 << 0x30) >> 0x30) < var_5) {
                        temp_3_5 = (u8)(*((u8 *)((D_00749350 + ((s64) (var_6 << 0x30) >> 0x30)))));
                        (*(u8 *)((u8 *)(temp_17)+(0x30C))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30C))) + temp_3_5);
                        (*(u8 *)((u8 *)(temp_17)+(0x30D))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30D))) + temp_3_5);
                        var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                        goto loop_20;
                    }
                    break;
                case 1:                             /* switch 2 */
                    var_6 = 0;
                    var_5 = ((s64) (temp_4 << 0x38) >> 0x38) + 1;
loop_24:
                    if (((s64) (var_6 << 0x30) >> 0x30) < var_5) {
                        temp_3_6 = (u8)(*((u8 *)((D_00749350 + ((s64) (var_6 << 0x30) >> 0x30)))));
                        (*(u8 *)((u8 *)(temp_17)+(0x30E))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30E))) + temp_3_6);
                        (*(u8 *)((u8 *)(temp_17)+(0x30F))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30F))) + temp_3_6);
                        var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                        goto loop_24;
                    }
                    break;
                case 2:                             /* switch 2 */
                    var_6 = 0;
                    var_5 = ((s64) (temp_4 << 0x38) >> 0x38) + 1;
loop_28:
                    if (((s64) (var_6 << 0x30) >> 0x30) < var_5) {
                        temp_3_7 = (u8)(*((u8 *)((D_00749350 + ((s64) (var_6 << 0x30) >> 0x30)))));
                        (*(u8 *)((u8 *)(temp_17)+(0x310))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x310))) + temp_3_7);
                        (*(u8 *)((u8 *)(temp_17)+(0x30C))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30C))) + temp_3_7);
                        var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                        goto loop_28;
                    }
                    break;
                case 3:                             /* switch 2 */
                    var_6 = 0;
                    var_5 = ((s64) (temp_4 << 0x38) >> 0x38) + 1;
loop_32:
                    if (((s64) (var_6 << 0x30) >> 0x30) < var_5) {
                        temp_3_8 = (u8)(*((u8 *)((D_00749350 + ((s64) (var_6 << 0x30) >> 0x30)))));
                        (*(u8 *)((u8 *)(temp_17)+(0x30D))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30D))) + temp_3_8);
                        (*(u8 *)((u8 *)(temp_17)+(0x30E))) = (u8) ((*(u8 *)((u8 *)(temp_17)+(0x30E))) + temp_3_8);
                        var_6 = (s64) ((var_6 + 1) << 0x30) >> 0x30;
                        goto loop_32;
                    }
                    break;
                }
                func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)(temp_17 + 0x30C));
                temp_2_2 = (s64) ((((s32) (func_001102d0() & 0xFFFF) >> 0xC) & 0xF) << 0x38) >> 0x38;
                if (temp_2_2 < 4) {
                    func_00310960(arg0, 0x1F, 0);
                } else if (temp_2_2 < 7) {
                    func_00310960(arg0, 0x20, 0);
                } else {
                    func_00310960(arg0, 0x21, 0);
                }
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x85U;
                return;
            }
            func_00310960(arg0, 0x22, 0);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x85U;
            return;
        }
        var_16 = 0;
loop_43:
        if (((s64) (var_16 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
            fclWriteColorBytes((u8 *)(col2FC), 0, 0, 0x99, 0xFFU);
            temp_2_3 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x188))), (s64) (var_16 << 0x38) >> 0x38));
            (*(u8 *)((u8 *)(temp_2_3)+(0x75))) = col2FC[0];
            (*(u8 *)((u8 *)(temp_2_3)+(0x76))) = col2FC[1];
            (*(u8 *)((u8 *)(temp_2_3)+(0x77))) = col2FC[2];
            (*(u8 *)((u8 *)(temp_2_3)+(0x78))) = col2FC[3];
            var_16 = (s64) ((var_16 + 1) << 0x30) >> 0x30;
            goto loop_43;
        }
        func_003205f0(arg0, 0x93, 0x96);
        func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        func_00316470(arg0, 1, 0);
        func_00314740((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0);
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
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x78U;
        return;
    case 0x78:                                      /* switch 1 */
        if (*func_002e4870(0) != 0) {
            func_002e5000();
            (*(s16 *)((u8 *)(temp_17)+(0x11E))) = 0;
            func_00320b80(arg0, 1);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x79U;
            return;
        }
    default:                                        /* switch 1 */
        return;
    case 0x79:                                      /* switch 1 */
        func_003212e0(arg0, 0x7B, 0);
        return;
    case 0x7B:                                      /* switch 1 */
        var_16_2 = 0;
loop_50:
        if (((s64) (var_16_2 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
            func_0031d630(arg0, (s64) (var_16_2 << 0x38) >> 0x38, -1, -1, 0);
            var_16_2 = (s64) ((var_16_2 + 1) << 0x30) >> 0x30;
            goto loop_50;
        }
        if ((((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) < 0) || (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) >= 6)) {
            if (D_008C027A[0] & 0x1000) {
                (*(s16 *)((u8 *)(temp_17)+(0x11E))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), 1, 0, (func_0010b5b0() & 0xFFFF) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                (*(s16 *)((u8 *)(temp_17)+(0x11E))) = func_002b2cb0((u8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), 1, (func_0010b5b0() & 0xFFFF) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x80) {
                func_0045af60(0, 1, 0, 3);
                var_16_3 = 0;
loop_60:
                if (((s64) (var_16_3 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                    func_002b2970(&sp298, 16.0f, 128.0f);
                    temp_19 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_3))+(2)));
                    temp_18 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_3))+(4)));
                    func_003191c0(arg0, sp298, (s64) (var_16_3 << 0x38) >> 0x38, temp_19, temp_18, 0, 1, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                    var_16_3 = (s64) ((var_16_3 + 1) << 0x30) >> 0x30;
                    goto loop_60;
                }
                func_002b2970(&sp290, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp290, 0, 1, 0, 0, 0);
                var_18 = 0;
loop_66:
                if (((s64) (var_18 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                    sp11C = func_0046d200(func_00331560(), 0x77);
                    temp_16_2 = (s16)var_18;
                    temp_21 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x184))), (s64) (var_18 << 0x38) >> 0x38));
                    func_002b2970(&sp288, (f32) ((temp_16_2 * 0x17) + 0x149), 104.0f);
                    fclWriteColorBytes((u8 *)(col2F8), 0, 0, 0x99, 0xFFU);
                    fclWriteColorBytes((u8 *)(col2F4), 0, 0, 0x99, 0xFFU);
                    func_002b83e0((u8 *)temp_21, fclDrawPositionValue(fclPacketPosition(sp288)), fclPacketColor((u32)((*(s32 *)col2F8))), fclPacketColor((u32)((*(s32 *)col2F4))), 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                    var_19 = 0;
                    temp_16_3 = (u8 *)(temp_17 + (temp_16_2 * 4));
loop_64:
                    if (((s64) (var_19 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        temp_30 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38));
                        func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38);
                        temp_22 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38));
                        temp_23 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38));
                        sp100 = func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38);
                        spF0 = func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38);
                        func_002b83e0((u8 *)temp_30, fclDrawPositionValue(fclPacketPosition(0)), fclPacketColor((u32)(((*(u8 *)((u8 *)(temp_22)+(0x78)))))), fclPacketColor((u32)(((*(u8 *)((u8 *)(temp_23)+(0x78)))))), (*(u8 *)(sp100+0x5E)), (*(u8 *)(spF0+0x5E)), 32.0f, (*(f32 *)((u8 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_3)+(0x154))), (s64) (var_19 << 0x38) >> 0x38))+(4))), 3, 0, 1, 0);
                        var_19 = (s64) ((var_19 + 1) << 0x30) >> 0x30;
                        goto loop_64;
                    }
                    func_0046d280(sp11C);
                    temp_19_2 = (s64) (var_18 << 0x30) >> 0x30;
                    temp_16_4 = (s64) ((temp_19_2 + 0x25E) << 0x30) >> 0x30;
                    temp_21_2 = func_0046d200(func_00331560(), 0x39);
                    func_002b6a70(temp_16_4, 0xFFU, 0, 0, 3, 0);
                    func_002b6af0(temp_16_4, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    temp_19_3 = (temp_19_2 * 0x17) + 0x14E;
                    func_002b2970(&sp280, (f32) temp_19_3, 110.0f);
                    func_002b2970(&sp278, (f32) temp_19_3, 110.0f + (func_0046b2f0(temp_21_2) / 2.0f));
                    func_002b69f0(temp_16_4, (*(FclVec2f *)&sp280), (*(FclVec2f *)&sp278), 0, 3, 0);
                    func_0046d280(temp_21_2);
                    var_18 = (s64) ((var_18 + 1) << 0x30) >> 0x30;
                    goto loop_66;
                }
                func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 1);
                func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 1);
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7CU;
                return;
            }
            if (D_008C024E[0] & 0x40) {
                temp_16_5 = (s16)((*(s16 *)((u8 *)(temp_17)+(0x11E))));
                if (temp_16_5 < (*(s32 *)((u8 *)(func_002e4870(0))+(8)))) {
                    func_0045af60(0, 0, 0, 1);
                    (*(s8 *)((u8 *)(temp_17)+(0x128))) = (s8) (*(s16 *)((u8 *)(temp_17)+(0x11E)));
                    (*(s8 *)((u8 *)(temp_17)+(0x129))) = -1;
                    func_002b2970(&sp270, -380.0f, (*(f32 *)((u8 *)(&D_00640C10)+(4))));
                    func_002b2970(&sp268, (*(f32 *)((u8 *)(&D_00640C10)+(0))), (*(f32 *)((u8 *)(&D_00640C10)+(4))));
                    func_0031c2b0(arg0, (s8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), sp270, sp268);
                    var_19_2 = 0;
loop_75:
                    if (((s64) (var_19_2 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        func_002b2970(&sp260, (f32) 0x149, 128.0f);
                        temp_16_6 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_19_2))+(2))));
                        func_0031ac10(arg0, sp260, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_19_2 << 0x38) >> 0x38, temp_16_6, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_19_2))+(4))), 3, 0, 1, 0xCC);
                        temp_16_7 = (s64) (var_19_2 << 0x30) >> 0x30;
                        temp_21_3 = temp_16_7 * 0x17;
                        temp_18_2 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x184))), (s64) (var_19_2 << 0x38) >> 0x38));
                        func_002b2970(&sp258, (f32) (temp_21_3 + 0x149), 104.0f);
                        fclWriteColorBytes((u8 *)(col2F0), 0, 0, 0x99, 0xFFU);
                        fclWriteColorBytes((u8 *)(col2EC), 0, 0, 0x99, 0xFFU);
                        func_002b83e0((u8 *)temp_18_2, fclDrawPositionValue(fclPacketPosition(sp258)), fclPacketColor((u32)((*(s32 *)col2F0))), fclPacketColor((u32)((*(s32 *)col2EC))), 0xFFU, 0xFFU, 32.0f, 159.0f, 3, 0, 1, 0);
                        var_18_2 = 0;
                        temp_16_8 = (u8 *)(temp_17 + (temp_16_7 * 4));
                        spE0 = temp_21_3 + 0x7F;
loop_73:
                        temp_21_4 = (s16)var_18_2;
                        if (temp_21_4 < (func_0010b5b0() & 0xFFFF)) {
                            spD0 = func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38);
                            func_002b2970(&sp250, (f32) ((temp_21_4 * 0x17) + 0x149), (f32) spE0);
                            temp_21_5 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38));
                            temp_22_2 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38));
                            temp_23_2 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38));
                            temp_30_2 = (s16 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38));
                            func_002b83e0(spD0, fclDrawPositionValue(fclPacketPosition(sp250)), fclPacketColor((u32)(((*(u8 *)((u8 *)(temp_21_5)+(0x78)))))), fclPacketColor((u32)(((*(u8 *)((u8 *)(temp_22_2)+(0x78)))))), (*(u8 *)((u8 *)(temp_23_2)+(0x5E))), (*(u8 *)((u8 *)(temp_30_2)+(0x5E))), 32.0f, (*(f32 *)((u8 *)(func_0034ae50((u8 *)(*(s32 *)((u8 *)(temp_16_8)+(0x154))), (s64) (var_18_2 << 0x38) >> 0x38))+(4))), 3, 0, 1, 0);
                            var_18_2 = (s64) ((var_18_2 + 1) << 0x30) >> 0x30;
                            goto loop_73;
                        }
                        temp_18_3 = (s64) (var_19_2 << 0x30) >> 0x30;
                        temp_16_9 = (s64) ((temp_18_3 + 0x25E) << 0x30) >> 0x30;
                        temp_21_6 = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(temp_16_9, 0xFFU, 0, 0, 3, 0);
                        func_002b6af0(temp_16_9, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        temp_18_4 = (temp_18_3 * 0x17) + 0x14E;
                        func_002b2970(&sp248, (f32) temp_18_4, 110.0f);
                        func_002b2970(&sp240, (f32) temp_18_4, 110.0f + (func_0046b2f0(temp_21_6) / 2.0f));
                        func_002b69f0(temp_16_9, (*(FclVec2f *)&sp248), (*(FclVec2f *)&sp240), 0, 3, 0);
                        func_0046d280(temp_21_6);
                        var_19_2 = (s64) ((var_19_2 + 1) << 0x30) >> 0x30;
                        goto loop_75;
                    }
                    func_002b2970(&sp238, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp238, 3, 0);
                    func_003205f0(arg0, 0x94, 0x93);
                    func_0031e320(arg0, (s64)(*(s8 *)((u8 *)(temp_17)+(0x128))));
                    (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7EU;
                    return;
                }
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                func_0032fbc0(arg0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                func_00316470(arg0, 1, 1);
                func_0032f4d0(arg0);
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7AU;
                return;
            }
        }
        break;
    case 0x7C:                                      /* switch 1 */
        if (((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1) << 0x30) >> 0x30) != 1) {
            func_00314450((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s16 *)((u8 *)(temp_17)+(0x11E)))), 0, 0);
            temp_16_10 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
            func_0011d140((u8 *)temp_16_10, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7DU;
            return;
        }
        break;
    case 0x7D:                                      /* switch 1 */
        if ((((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) < 0) || (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) >= 6)) {
            var_16_4 = 0;
loop_85:
            if (((s64) (var_16_4 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                func_002b2970(&sp230, 16.0f, 128.0f);
                temp_19_4 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_4))+(2)));
                temp_18_5 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_4))+(4)));
                func_003191c0(arg0, sp230, (s64) (var_16_4 << 0x38) >> 0x38, temp_19_4, temp_18_5, 0, 0, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                var_16_4 = (s64) ((var_16_4 + 1) << 0x30) >> 0x30;
                goto loop_85;
            }
            func_002b2970(&sp228, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp228, 0, 0, 0, 0, 0);
            func_003218a0(arg0, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 1);
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 1);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7BU;
            return;
        }
        break;
    case 0x7A:                                      /* switch 1 */
        var_19_3 = 0;
loop_97:
        temp_16_11 = (s16)var_19_3;
        if (temp_16_11 < (func_0010b5b0() & 0xFFFF)) {
            temp_18_6 = (s64) (var_19_3 << 0x30) >> 0x30;
            temp_21_7 = temp_18_6 + 0x21C;
            temp_f20 = (f32) (*(s16 *)((u8 *)(func_002b6150((s64) (temp_21_7 << 0x30) >> 0x30))+(0x42)));
            temp_f0 = func_002b2aa0(0, 255.0f, 0, temp_f20, (f32) (*(s16 *)((u8 *)(func_002b6150((s64) (temp_21_7 << 0x30) >> 0x30))+(0x40))));
            if (!(temp_f0 >= 2.1474836e9f)) {
                var_3 = (u8)(temp_f0);
            } else {
                var_3 = (u8)(temp_f0);
            }
            temp_7 = var_3 & 0xFF;
            if ((*(s16 *)((u8 *)(temp_17)+(0x11E))) == temp_18_6) {
                var_18_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
            } else {
                var_18_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
            }
            if (temp_16_11 < ((*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1)) {
                func_00275520(var_18_3, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, var_19_3))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 113.0f, (f32) ((temp_16_11 * 0x17) + 0x80), 43.0f);
            }
            var_19_3 = (s64) ((var_19_3 + 1) << 0x30) >> 0x30;
            goto loop_97;
        }
        if ((((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x21C))+(0x10))), 1) << 0x30) >> 0x30) == 0) && (((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x193))+(0x10))), 1) << 0x30) >> 0x30) == 0)) {
            func_003205f0(arg0, 0x96, 0x93);
            func_00315600(arg0, 0);
            (*(s8 *)((u8 *)(temp_17)+(0))) = 0;
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x1BU;
            return;
        }
        break;
    case 0x7E:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_17)+(0x129))) = -1;
        temp_16_12 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_7 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
        temp_2_4 = (u8 *)(func_002b6150(0x7C));
        sp160 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_4)+(0x38))));
        sp164 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_4)+(0x3C))));
        temp_16_13 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_12);
        func_00275820(temp_16_13, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_18_7)+(0x128)))))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp160, sp164, 43.0f);
        var_19_4 = 0;
loop_110:
        temp_16_14 = (s16)var_19_4;
        if (temp_16_14 < (func_0010b5b0() & 0xFFFF)) {
            func_0031d630(arg0, (s64) (var_19_4 << 0x38) >> 0x38, (*(s8 *)((u8 *)(temp_17)+(0x128))), (*(s8 *)((u8 *)(temp_17)+(0x129))), 0);
            if ((((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150((s64) ((temp_16_14 + 0x270) << 0x30) >> 0x30))+(0x10))), 1) << 0x30) >> 0x30) == 0) && ((*(s8 *)((u8 *)(temp_17)+(0x128))) != temp_16_14) && ((*(s8 *)((u8 *)((func_002e4870(0) + ((*(s8 *)((u8 *)(temp_17)+(0x128))) * 0xC) + temp_16_14))+(0x14))) > 0)) {
                if (temp_16_14 == (*(s16 *)((u8 *)(temp_17)+(0x11E)))) {
                    temp_18_8 = (s64) (var_19_4 << 0x30) >> 0x30;
                    temp_23_3 = temp_18_8 + 0x27D;
                    temp_30_3 = temp_18_8 + 0x270;
                    (*(s8 *)((u8 *)(func_002b6150((s64) (temp_23_3 << 0x30) >> 0x30))+(0x6E))) = 0xFF;
                    (*(s8 *)((u8 *)(func_002b6150((s64) (temp_30_3 << 0x30) >> 0x30))+(0x6E))) = (s8) (0xFF & 0xFF);
                    fclWriteColorBytes((u8 *)(col2E8), 0xCC, 0xFF, 0x33, 0xFFU);
                    temp_2_5 = (u8 *)(func_002b6150((s64) ((temp_18_8 + 0x297) << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_5)+(0x85))) = col2E8[0];
                    (*(u8 *)((u8 *)(temp_2_5)+(0x86))) = col2E8[1];
                    (*(u8 *)((u8 *)(temp_2_5)+(0x87))) = col2E8[2];
                    (*(u8 *)((u8 *)(temp_2_5)+(0x88))) = col2E8[3];
                    temp_2_6 = (u8 *)(func_002b6150((s64) ((temp_18_8 + 0x28B) << 0x30) >> 0x30));
                    temp_6 = (u8)((*(u8 *)((u8 *)(temp_2_5)+(0x85))));
                    temp_5 = (u8)((*(u8 *)((u8 *)(temp_2_5)+(0x86))));
                    (*(u8 *)((u8 *)(temp_2_6)+(0x85))) = temp_6;
                    (*(u8 *)((u8 *)(temp_2_6)+(0x86))) = temp_5;
                    (*(u8 *)((u8 *)(temp_2_6)+(0x87))) = (u8) (*(u8 *)((u8 *)(temp_2_5)+(0x87)));
                    (*(u8 *)((u8 *)(temp_2_6)+(0x88))) = (u8) (*(u8 *)((u8 *)(temp_2_5)+(0x88)));
                    temp_2_7 = (u8 *)(func_002b6150((s64) (temp_23_3 << 0x30) >> 0x30));
                    temp_6_2 = (u8)((*(u8 *)((u8 *)(temp_2_6)+(0x85))));
                    temp_5_2 = (u8)((*(u8 *)((u8 *)(temp_2_6)+(0x86))));
                    (*(u8 *)((u8 *)(temp_2_7)+(0x85))) = temp_6_2;
                    (*(u8 *)((u8 *)(temp_2_7)+(0x86))) = temp_5_2;
                    (*(u8 *)((u8 *)(temp_2_7)+(0x87))) = (u8) (*(u8 *)((u8 *)(temp_2_6)+(0x87)));
                    (*(u8 *)((u8 *)(temp_2_7)+(0x88))) = (u8) (*(u8 *)((u8 *)(temp_2_6)+(0x88)));
                    temp_2_8 = (u8 *)(func_002b6150((s64) (temp_30_3 << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_8)+(0x85))) = (u8) (*(u8 *)((u8 *)(temp_2_7)+(0x85)));
                    (*(u8 *)((u8 *)(temp_2_8)+(0x86))) = (u8) (*(u8 *)((u8 *)(temp_2_7)+(0x86)));
                    (*(u8 *)((u8 *)(temp_2_8)+(0x87))) = (u8) (*(u8 *)((u8 *)(temp_2_7)+(0x87)));
                    (*(u8 *)((u8 *)(temp_2_8)+(0x88))) = (u8) (*(u8 *)((u8 *)(temp_2_7)+(0x88)));
                    fclWriteColorBytes((u8 *)(col2E4), 0x2D, 0x2D, 0x2D, 0xFFU);
                    temp_2_9 = (u8 *)(func_002b6150((s64) ((temp_18_8 + 0x2A3) << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_9)+(0x85))) = col2E4[0];
                    (*(u8 *)((u8 *)(temp_2_9)+(0x86))) = col2E4[1];
                    (*(u8 *)((u8 *)(temp_2_9)+(0x87))) = col2E4[2];
                    (*(u8 *)((u8 *)(temp_2_9)+(0x88))) = col2E4[3];
                    fclWriteColorBytes((u8 *)(col2E0), 0x2D, 0x2D, 0x2D, 0xFFU);
                    func_002ba970((*(s32 *)((u8 *)(temp_17)+(0x2BC))), (s64) ((temp_18_8 + 0xC) << 0x38) >> 0x38, (*(s32 *)col2E0));
                    var_18_4 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
                } else {
                    temp_18_9 = (s64) (var_19_4 << 0x30) >> 0x30;
                    temp_21_8 = temp_18_9 + 0x27D;
                    temp_22_3 = temp_18_9 + 0x270;
                    (*(s8 *)((u8 *)(func_002b6150((s64) (temp_21_8 << 0x30) >> 0x30))+(0x6E))) = 0xCC;
                    (*(s8 *)((u8 *)(func_002b6150((s64) (temp_22_3 << 0x30) >> 0x30))+(0x6E))) = (s8) (0xCC & 0xFF);
                    fclWriteColorBytes((u8 *)(col2DC), 0x49, 0x72, 0xFF, 0xFFU);
                    temp_2_10 = (u8 *)(func_002b6150((s64) (temp_21_8 << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_10)+(0x85))) = col2DC[0];
                    (*(u8 *)((u8 *)(temp_2_10)+(0x86))) = col2DC[1];
                    (*(u8 *)((u8 *)(temp_2_10)+(0x87))) = col2DC[2];
                    (*(u8 *)((u8 *)(temp_2_10)+(0x88))) = col2DC[3];
                    temp_2_11 = (u8 *)(func_002b6150((s64) (temp_22_3 << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_11)+(0x85))) = (u8) (*(u8 *)((u8 *)(temp_2_10)+(0x85)));
                    (*(u8 *)((u8 *)(temp_2_11)+(0x86))) = (u8) (*(u8 *)((u8 *)(temp_2_10)+(0x86)));
                    (*(u8 *)((u8 *)(temp_2_11)+(0x87))) = (u8) (*(u8 *)((u8 *)(temp_2_10)+(0x87)));
                    (*(u8 *)((u8 *)(temp_2_11)+(0x88))) = (u8) (*(u8 *)((u8 *)(temp_2_10)+(0x88)));
                    fclWriteColorBytes((u8 *)(col2D8), 0x49, 0x72, 0xFF, 0xFFU);
                    temp_2_12 = (u8 *)(func_002b6150((s64) ((temp_18_9 + 0x297) << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_12)+(0x85))) = col2D8[0];
                    (*(u8 *)((u8 *)(temp_2_12)+(0x86))) = col2D8[1];
                    (*(u8 *)((u8 *)(temp_2_12)+(0x87))) = col2D8[2];
                    (*(u8 *)((u8 *)(temp_2_12)+(0x88))) = col2D8[3];
                    temp_2_13 = (u8 *)(func_002b6150((s64) ((temp_18_9 + 0x28B) << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_13)+(0x85))) = (u8) (*(u8 *)((u8 *)(temp_2_12)+(0x85)));
                    (*(u8 *)((u8 *)(temp_2_13)+(0x86))) = (u8) (*(u8 *)((u8 *)(temp_2_12)+(0x86)));
                    (*(u8 *)((u8 *)(temp_2_13)+(0x87))) = (u8) (*(u8 *)((u8 *)(temp_2_12)+(0x87)));
                    (*(u8 *)((u8 *)(temp_2_13)+(0x88))) = (u8) (*(u8 *)((u8 *)(temp_2_12)+(0x88)));
                    fclWriteColorBytes((u8 *)(col2D4), 0, 0, 0x66, 0xFFU);
                    temp_2_14 = (u8 *)(func_002b6150((s64) ((temp_18_9 + 0x2A3) << 0x30) >> 0x30));
                    (*(u8 *)((u8 *)(temp_2_14)+(0x85))) = col2D4[0];
                    (*(u8 *)((u8 *)(temp_2_14)+(0x86))) = col2D4[1];
                    (*(u8 *)((u8 *)(temp_2_14)+(0x87))) = col2D4[2];
                    (*(u8 *)((u8 *)(temp_2_14)+(0x88))) = col2D4[3];
                    fclWriteColorBytes((u8 *)(col2D0), 0xCC, 0xFF, 0xFF, 0xFFU);
                    func_002ba970((*(s32 *)((u8 *)(temp_17)+(0x2BC))), (s64) ((temp_18_9 + 0xC) << 0x38) >> 0x38, (*(s32 *)col2D0));
                    var_18_4 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
                }
                func_00275520(var_18_4, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_19_4))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, (f32) 0x195, (f32) ((temp_16_14 * 0x17) + 0x80), 43.0f);
            }
            var_19_4 = (s64) ((var_19_4 + 1) << 0x30) >> 0x30;
            goto loop_110;
        }
        if ((((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) < 0) || (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) >= 6)) {
            if (D_008C027A[0] & 0x1000) {
                (*(s16 *)((u8 *)(temp_17)+(0x11E))) = func_002b2d00((s8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), 1, 0, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C027A[0] & 0x4000) {
                (*(s16 *)((u8 *)(temp_17)+(0x11E))) = func_002b2cb0((u8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), 1, (*(s32 *)((u8 *)(func_002e4870(0))+(8))) - 1, 0, 2);
                func_0045af60(0, 0, 0, 0);
                return;
            }
            if (D_008C024E[0] & 0x40) {
                if (((*(s8 *)((u8 *)(temp_17)+(0x128))) != (*(s16 *)((u8 *)(temp_17)+(0x11E)))) && ((*(s8 *)((u8 *)((func_002e4870(0) + ((*(s8 *)((u8 *)(temp_17)+(0x128))) * 0xC) + (*(s16 *)((u8 *)(temp_17)+(0x11E)))))+(0x14))) > 0)) {
                    func_0045af60(0, 0, 0, 1);
                    var_18_5 = 0;
loop_122:
                    if (((s64) (var_18_5 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        func_002b2970(&sp220, (f32) 0x149, 128.0f);
                        temp_16_15 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_5))+(2))));
                        func_0031ac10(arg0, sp220, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_18_5 << 0x38) >> 0x38, temp_16_15, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_5))+(4))), 3, 1, 1, 0xCC);
                        var_18_5 = (s64) ((var_18_5 + 1) << 0x30) >> 0x30;
                        goto loop_122;
                    }
                    (*(s8 *)((u8 *)(temp_17)+(0x2F9))) = (s8) ((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1);
                    (*(s8 *)((u8 *)(temp_17)+(0x2FA))) = (s8) (*(s16 *)((u8 *)(temp_17)+(0x11E)));
                    (*(s8 *)((u8 *)(temp_17)+(0x129))) = (s8) (*(s16 *)((u8 *)(temp_17)+(0x11E)));
                    var_4 = 0;
loop_125:
                    temp_3_9 = (s64) (var_4 << 0x30) >> 0x30;
                    if (temp_3_9 < 5) {
                        (*(s8 *)((u8 *)((temp_17 + temp_3_9))+(0x30C))) = 0;
                        var_4 = (s64) ((var_4 + 1) << 0x30) >> 0x30;
                        goto loop_125;
                    }
                    temp_3_10 = (s64) (func_00308e50(arg0) << 0x38) >> 0x38;
                    switch (temp_3_10) {            /* switch 3; irregular */
                    case 0:                         /* switch 3 */
                        temp_2_15 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_15)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_15)+(0x1C))) + 6);
                        temp_2_16 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_16)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_16)+(0x1D))) + 6);
                        (*(u8 *)((u8 *)(temp_17)+(0x30C))) = 6U;
                        (*(u8 *)((u8 *)(temp_17)+(0x30D))) = 6U;
                        break;
                    case 1:                         /* switch 3 */
                        temp_2_17 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_17)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_17)+(0x1E))) + 6);
                        temp_2_18 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_18)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_18)+(0x1F))) + 6);
                        (*(u8 *)((u8 *)(temp_17)+(0x30E))) = 6U;
                        (*(u8 *)((u8 *)(temp_17)+(0x30F))) = 6U;
                        break;
                    case 2:                         /* switch 3 */
                        temp_2_19 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_19)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_19)+(0x20))) + 6);
                        temp_2_20 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_20)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_20)+(0x1C))) + 6);
                        (*(u8 *)((u8 *)(temp_17)+(0x310))) = 6U;
                        (*(u8 *)((u8 *)(temp_17)+(0x30C))) = 6U;
                        break;
                    case 3:                         /* switch 3 */
                        temp_2_21 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_21)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_21)+(0x1D))) + 6);
                        temp_2_22 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                        (*(u8 *)((u8 *)(temp_2_22)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_22)+(0x1E))) + 6);
                        (*(u8 *)((u8 *)(temp_17)+(0x30D))) = 6U;
                        (*(u8 *)((u8 *)(temp_17)+(0x30E))) = 6U;
                        break;
                    }
                    func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))), 0, 0, 1);
                    temp_16_16 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
                    func_0011d140((u8 *)temp_16_16, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
                    (*(u8 *)((u8 *)(temp_17)+(1))) = 0x81U;
                    var_16_5 = 0;
loop_137:
                    if (((s64) (var_16_5 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        func_002b2970(&sp218, 16.0f, 128.0f);
                        temp_19_5 = (*(u16 *)((u8 *)(func_002e48a0(0, var_16_5))+(2)));
                        temp_18_10 = (*(u8 *)((u8 *)(func_002e48a0(0, var_16_5))+(4)));
                        func_003191c0(arg0, sp218, (s64) (var_16_5 << 0x38) >> 0x38, temp_19_5, temp_18_10, 0, 1, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                        var_16_5 = (s64) ((var_16_5 + 1) << 0x30) >> 0x30;
                        goto loop_137;
                    }
                    func_002b2970(&sp210, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp210, 0, 1, 0, 0, 0);
                    func_002b2970(&sp208, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp208, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_00317240(arg0, 0, 0);
                    func_00325450(arg0, 3, 0);
                    func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 1);
                    func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 1);
                    return;
                }
            } else {
                if (D_008C024C & 0x80) {
                    func_0045af60(0, 1, 0, 3);
                    var_18_6 = 0;
loop_142:
                    if (((s64) (var_18_6 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        func_002b2970(&sp200, (f32) 0x149, 128.0f);
                        temp_16_17 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_6))+(2))));
                        func_0031ac10(arg0, sp200, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_18_6 << 0x38) >> 0x38, temp_16_17, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_6))+(4))), 0, 1, 1, 0xCC);
                        func_002b2970(&sp1F8, 16.0f, 128.0f);
                        temp_19_6 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_6))+(2)));
                        temp_16_18 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_6))+(4)));
                        func_003191c0(arg0, sp1F8, (s64) (var_18_6 << 0x38) >> 0x38, temp_19_6, temp_16_18, 0, 1, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                        var_18_6 = (s64) ((var_18_6 + 1) << 0x30) >> 0x30;
                        goto loop_142;
                    }
                    func_002b2970(&sp1F0, 16.0f, 104.0f);
                    func_0031e5b0(arg0, sp1F0, 0, 1, 0, 0, 0);
                    func_002b2970(&sp1E8, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1E8, 0, 1);
                    func_00316470(arg0, 1, 1);
                    func_00316e80((s32)arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
                    func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 1);
                    func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 1);
                    (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7FU;
                    return;
                }
                if (D_008C024E[0] & 0x20) {
                    func_0031ddf0(arg0, (s8) (*(s16 *)((u8 *)(temp_17)+(0x11E))), 0, 0xFF);
                    temp_2_23 = (s8)((*(s8 *)((u8 *)(temp_17)+(0x128))));
                    (*(s16 *)((u8 *)(temp_17)+(0x11E))) = (s16) temp_2_23;
                    func_0031ddf0(arg0, temp_2_23, 1, 0xFF);
                    func_0045af60(0, 0, 0, 2);
                    func_003205f0(arg0, 0x93, 0x94);
                    func_002b2970(&sp1E0, (*(f32 *)((u8 *)(&D_00640C10)+(0))), (*(f32 *)((u8 *)(&D_00640C10)+(4))));
                    func_002b2970(&sp1D8, -380.0f, (*(f32 *)((u8 *)(&D_00640C10)+(4))));
                    func_0031c2b0(arg0, (*(s8 *)((u8 *)(temp_17)+(0x128))), sp1E0, sp1D8);
                    func_002b2970(&sp1D0, (f32) 0x149, 104.0f);
                    func_0031fa20(arg0, sp1D0, 0, 1);
                    var_18_7 = 0;
loop_147:
                    if (((s64) (var_18_7 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                        func_002b2970(&sp1C8, (f32) 0x149, 128.0f);
                        temp_16_19 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_7))+(2))));
                        func_0031ac10(arg0, sp1C8, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_18_7 << 0x38) >> 0x38, temp_16_19, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_7))+(4))), 0, 1, 1, 0xCC);
                        var_18_7 = (s64) ((var_18_7 + 1) << 0x30) >> 0x30;
                        goto loop_147;
                    }
                    func_003218a0(arg0, 3);
                    (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7BU;
                    return;
                }
            }
        }
        break;
    case 0x7F:                                      /* switch 1 */
        temp_16_20 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_11 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
        temp_2_24 = (u8 *)(func_002b6150(0x7C));
        sp158 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_24)+(0x38))));
        sp15C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_24)+(0x3C))));
        temp_16_21 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_20);
        func_00275820(temp_16_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_18_11)+(0x128)))))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp158, sp15C, 43.0f);
        if (((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150(0x270))+(0x10))), 1) << 0x30) >> 0x30) != 1) {
            func_00314450((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s16 *)((u8 *)(temp_17)+(0x11E)))), 0, 0);
            temp_16_22 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
            func_0011d140((u8 *)temp_16_22, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
            func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x80U;
            return;
        }
        break;
    case 0x80:                                      /* switch 1 */
        temp_16_23 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_12 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
        temp_2_25 = (u8 *)(func_002b6150(0x7C));
        sp150 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_25)+(0x38))));
        sp154 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_25)+(0x3C))));
        temp_16_24 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_23);
        func_00275820(temp_16_24, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_18_12)+(0x128)))))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp150, sp154, 43.0f);
        if ((((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) < 0) || (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) >= 6)) {
            var_18_8 = 0;
loop_155:
            if (((s64) (var_18_8 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                func_002b2970(&sp1C0, (f32) 0x149, 128.0f);
                temp_16_25 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_8))+(2))));
                func_0031ac10(arg0, sp1C0, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_18_8 << 0x38) >> 0x38, temp_16_25, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_8))+(4))), 0, 0, 1, 0xCC);
                func_002b2970(&sp1B8, 16.0f, 128.0f);
                temp_19_7 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_8))+(2)));
                temp_16_26 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_8))+(4)));
                func_003191c0(arg0, sp1B8, (s64) (var_18_8 << 0x38) >> 0x38, temp_19_7, temp_16_26, 0, 0, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                var_18_8 = (s64) ((var_18_8 + 1) << 0x30) >> 0x30;
                goto loop_155;
            }
            func_002b2970(&sp1B0, 16.0f, 104.0f);
            func_0031e5b0(arg0, sp1B0, 0, 0, 0, 0, 0);
            func_002b2970(&sp1A8, (f32) 0x149, 104.0f);
            func_0031fa20(arg0, sp1A8, 0, 0);
            func_00316470(arg0, 1, 0);
            func_00316e80((s32)arg0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7EU;
            return;
        }
        break;
    case 0x81:                                      /* switch 1 */
        temp_16_27 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_13 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
        temp_2_26 = (u8 *)(func_002b6150(0x7C));
        sp148 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_26)+(0x38))));
        sp14C = (f32)(s32)((*(f32 *)((u8 *)(temp_2_26)+(0x3C))));
        temp_16_28 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_27);
        func_00275820(temp_16_28, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_18_13)+(0x128)))))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp148, sp14C, 43.0f);
        var_19_5 = 0;
loop_165:
        temp_16_29 = (s16)var_19_5;
        if (temp_16_29 < (func_0010b5b0() & 0xFFFF)) {
            func_0031d630(arg0, (s64) (var_19_5 << 0x38) >> 0x38, (*(s8 *)((u8 *)(temp_17)+(0x128))), (*(s8 *)((u8 *)(temp_17)+(0x129))), 0);
            if (temp_16_29 == (*(s16 *)((u8 *)(temp_17)+(0x11E)))) {
                var_21 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
            } else {
                var_21 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
            }
            temp_2_27 = (s8)((*(s8 *)((u8 *)(temp_17)+(0x128))));
            if (temp_2_27 != temp_16_29) {
                temp_18_14 = (s64) ((s64) temp_2_27 << 0x38) >> 0x38;
                if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_14 * 0xC) + temp_16_29))+(0x14))) > 0) {
                    func_00275520(var_21, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0((s64) ((temp_18_14 + 1) << 0x38) >> 0x38, var_19_5))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, (f32) 0x195, (f32) ((temp_16_29 * 0x17) + 0x80), 43.0f);
                }
            }
            var_19_5 = (s64) ((var_19_5 + 1) << 0x30) >> 0x30;
            goto loop_165;
        }
        if ((*(s8 *)((u8 *)(temp_17)+(0x122))) == 2) {
            func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)(temp_17 + 0x30C));
        }
        if (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) == 0xD) {
            if (func_0011c610(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))))) == 1) {
                func_0011caf0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
            }
            if (D_008C024E[0] & 0x40) {
                func_00310960(arg0, 0x1B, 1);
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x83U;
                func_0045af60(0, 0, 0, 1);
                return;
            }
            if (D_008C024E[0] & 0x20) {
                if (func_0011c610(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))))) == 1) {
                    func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
                    func_00314740((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 1);
                    return;
                }
                func_0045af60(0, 0, 0, 2);
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x82U;
                func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0xB);
                func_00325450(arg0, 3, 1);
                func_00316470(arg0, 1, 0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                (*(s8 *)((u8 *)(temp_17)+(0x129))) = -1;
                var_18_9 = 0;
loop_178:
                if (((s64) (var_18_9 << 0x30) >> 0x30) < (func_0010b5b0() & 0xFFFF)) {
                    func_002b2970(&sp1A0, 16.0f, 128.0f);
                    temp_19_8 = (*(u16 *)((u8 *)(func_002e48a0(0, var_18_9))+(2)));
                    temp_16_30 = (*(u8 *)((u8 *)(func_002e48a0(0, var_18_9))+(4)));
                    func_003191c0(arg0, sp1A0, (s64) (var_18_9 << 0x38) >> 0x38, temp_19_8, temp_16_30, 0, 0, (*(s8 *)((u8 *)(func_002e4870(0))+(8))));
                    func_002b2970(&sp198, (f32) 0x149, 128.0f);
                    temp_16_31 = (u16)((*(u16 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_9))+(2))));
                    func_0031ac10(arg0, sp198, (*(s8 *)((u8 *)(temp_17)+(0x128))), (s64) (var_18_9 << 0x38) >> 0x38, temp_16_31, (*(u8 *)((u8 *)(func_002e48a0((s64) (((*(s8 *)((u8 *)(temp_17)+(0x128))) + 1) << 0x38) >> 0x38, var_18_9))+(4))), 0, 0, 1, 0xCC);
                    var_18_9 = (s64) ((var_18_9 + 1) << 0x30) >> 0x30;
                    goto loop_178;
                }
                func_002b2970(&sp190, 16.0f, 104.0f);
                func_0031e5b0(arg0, sp190, 0, 0, 0, 0, 0);
                func_002b2970(&sp188, (f32) 0x149, 104.0f);
                func_0031fa20(arg0, sp188, 0, 0);
                func_00316e80((s32)arg0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
                func_00317240(arg0, 1, 0);
                var_4_2 = 0;
loop_181:
                temp_3_11 = (s64) (var_4_2 << 0x30) >> 0x30;
                if (temp_3_11 < 5) {
                    sp2C8[temp_3_11] = 0;
                    var_4_2 = (s64) ((var_4_2 + 1) << 0x30) >> 0x30;
                    goto loop_181;
                }
                func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2C8);
                temp_4_2 = (s64) (func_00308e50(arg0) << 0x38) >> 0x38;
                switch (temp_4_2) {                 /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    temp_2_28 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_28)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_28)+(0x1C))) - 6);
                    temp_2_29 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_29)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_29)+(0x1D))) - 6);
                    return;
                case 1:                             /* switch 4 */
                    temp_2_30 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_30)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_30)+(0x1E))) - 6);
                    temp_2_31 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_31)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_31)+(0x1F))) - 6);
                    return;
                case 2:                             /* switch 4 */
                    temp_2_32 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_32)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_32)+(0x20))) - 6);
                    temp_2_33 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_33)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_33)+(0x1C))) - 6);
                    return;
                case 3:                             /* switch 4 */
                    temp_2_34 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_34)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_34)+(0x1D))) - 6);
                    temp_2_35 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                    (*(u8 *)((u8 *)(temp_2_35)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_35)+(0x1E))) - 6);
                    return;
                }
            } else {
                if (D_008C024E[0] & 8) {
                    if ((*(s8 *)((u8 *)(temp_17)+(0x122))) != 2) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    (*(s8 *)((u8 *)(temp_17)+(0x122))) = func_002b2cb0((u8) (*(s8 *)((u8 *)(temp_17)+(0x122))), 1, 2, 0, 1);
                    ps = func_002b6150(0x151);
                    func_002b2970(&sp180, (f32) (((*(s8 *)((u8 *)(temp_17)+(0x122))) * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp180), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp178, (f32) (((*(s8 *)((u8 *)(temp_17)+(0x122))) * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp178), 1, 4, 0);
                    var_4_3 = 0;
loop_196:
                    temp_3_12 = (s64) (var_4_3 << 0x30) >> 0x30;
                    if (temp_3_12 < 5) {
                        sp2C0[temp_3_12] = 0;
                        var_4_3 = (s64) ((var_4_3 + 1) << 0x30) >> 0x30;
                        goto loop_196;
                    }
                    func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2C0);
                    temp_3_13 = (s8)((*(s8 *)((u8 *)(temp_17)+(0x122))));
                    switch (temp_3_13) {            /* switch 5; irregular */
                    case 0:                         /* switch 5 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x128)))), 0, 0, 1);
                        break;
                    case 1:                         /* switch 5 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x129)))), 0, 0, 1);
                        break;
                    case 2:                         /* switch 5 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))), 0, 0, 1);
                        break;
                    }
                    temp_16_32 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
                    func_0011d140((u8 *)temp_16_32, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 4) {
                    if ((*(s8 *)((u8 *)(temp_17)+(0x122))) != 0) {
                        func_0045af60(0, 2, 0, 5);
                    }
                    (*(s8 *)((u8 *)(temp_17)+(0x122))) = func_002b2d00((*(s8 *)((u8 *)(temp_17)+(0x122))), 1, 0, 2, 1);
                    ps = func_002b6150(0x151);
                    func_002b2970(&sp170, (f32) (((*(s8 *)((u8 *)(temp_17)+(0x122))) * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x151, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp170), 1, 4, 0);
                    ps = func_002b6150(0x2E0);
                    func_002b2970(&sp168, (f32) (((*(s8 *)((u8 *)(temp_17)+(0x122))) * 0x8E) + 0x6A), 16.0f);
                    func_002b69f0(0x2E0, (*(FclVec2f *)(ps + 0x38)), (*(FclVec2f *)&sp168), 1, 4, 0);
                    var_4_4 = 0;
loop_210:
                    temp_3_14 = (s64) (var_4_4 << 0x30) >> 0x30;
                    if (temp_3_14 < 5) {
                        sp2B8[temp_3_14] = 0;
                        var_4_4 = (s64) ((var_4_4 + 1) << 0x30) >> 0x30;
                        goto loop_210;
                    }
                    func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2B8);
                    temp_3_15 = (s8)((*(s8 *)((u8 *)(temp_17)+(0x122))));
                    switch (temp_3_15) {            /* switch 6; irregular */
                    case 0:                         /* switch 6 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x128)))), 0, 0, 1);
                        break;
                    case 1:                         /* switch 6 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x129)))), 0, 0, 1);
                        break;
                    case 2:                         /* switch 6 */
                        func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))), 0, 0, 1);
                        break;
                    }
                    temp_16_33 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
                    func_0011d140((u8 *)temp_16_33, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFFU));
                    return;
                }
                if (D_008C024E[0] & 0x80) {
                    if (func_0011c610(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))))) == 0) {
                        func_0011c630(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))));
                        func_00314740((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0);
                        return;
                    }
                    func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), 1);
                    func_00314740((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 1);
                    return;
                }
            }
        }
        break;
    case 0x82:                                      /* switch 1 */
        temp_16_34 = (u8)((*(u8 *)((u8 *)(func_002b6150(0x7C))+(0x6E))));
        temp_18_15 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
        temp_2_36 = (u8 *)(func_002b6150(0x7C));
        sp140 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_36)+(0x38))));
        sp144 = (f32)(s32)((*(f32 *)((u8 *)(temp_2_36)+(0x3C))));
        temp_16_35 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_16_34);
        func_00275820(temp_16_35, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_18_15)+(0x128)))))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, 0x15, 111.0f + sp140, sp144, 43.0f);
        var_19_6 = 0;
loop_232:
        temp_16_36 = (s16)var_19_6;
        if (temp_16_36 < (func_0010b5b0() & 0xFFFF)) {
            func_0031d630(arg0, (s64) (var_19_6 << 0x38) >> 0x38, (*(s8 *)((u8 *)(temp_17)+(0x128))), (*(s8 *)((u8 *)(temp_17)+(0x129))), 0);
            if (((s64) (func_002b6970((*(s16 *)((u8 *)(func_002b6150((s64) ((temp_16_36 + 0x270) << 0x30) >> 0x30))+(0x10))), 1) << 0x30) >> 0x30) == 0) {
                if (temp_16_36 == (*(s16 *)((u8 *)(temp_17)+(0x11E)))) {
                    var_21_2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFFU);
                } else {
                    var_21_2 = func_002b2a30(0xCC, 0xFF, 0xFF, 0xFFU);
                }
                temp_2_37 = (s8)((*(s8 *)((u8 *)(temp_17)+(0x128))));
                if (temp_2_37 != temp_16_36) {
                    temp_18_16 = (s64) ((s64) temp_2_37 << 0x38) >> 0x38;
                    if ((*(s8 *)((u8 *)((func_002e4870(0) + (temp_18_16 * 0xC) + temp_16_36))+(0x14))) > 0) {
                        func_00275520(var_21_2, 0, 2, ((s32)iGpffffb440) + ((*(u16 *)((u8 *)(func_002e48a0((s64) ((temp_18_16 + 1) << 0x38) >> 0x38, var_19_6))+(2))) * 0x11), 0, 0, (const char *)D_00795E60, (f32) 0x195, (f32) ((temp_16_36 * 0x17) + 0x80), 43.0f);
                    }
                }
            }
            var_19_6 = (s64) ((var_19_6 + 1) << 0x30) >> 0x30;
            goto loop_232;
        }
        if (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) == 0xE) {
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 0);
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 0);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x7EU;
            return;
        }
        break;
    case 0x83:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        if (func_002bb1c0((*(s8 *)((u8 *)(temp_17)+(0xD)))) == 0) {
            func_00106390(0x1306, 1);
            func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0xB);
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
            var_4_5 = 0;
loop_240:
            temp_3_16 = (s64) (var_4_5 << 0x30) >> 0x30;
            if (temp_3_16 < 5) {
                sp2B0[temp_3_16] = 0;
                var_4_5 = (s64) ((var_4_5 + 1) << 0x30) >> 0x30;
                goto loop_240;
            }
            func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2B0);
            temp_3_17 = (s64) (func_00308e50(arg0) << 0x38) >> 0x38;
            switch (temp_3_17) {                    /* switch 7; irregular */
            case 0:                                 /* switch 7 */
                temp_2_38 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_38)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_38)+(0x1C))) - 6);
                temp_2_39 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_39)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_39)+(0x1D))) - 6);
                break;
            case 1:                                 /* switch 7 */
                temp_2_40 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_40)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_40)+(0x1E))) - 6);
                temp_2_41 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_41)+(0x1F))) = (u8) ((*(u8 *)((u8 *)(temp_2_41)+(0x1F))) - 6);
                break;
            case 2:                                 /* switch 7 */
                temp_2_42 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_42)+(0x20))) = (u8) ((*(u8 *)((u8 *)(temp_2_42)+(0x20))) - 6);
                temp_2_43 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_43)+(0x1C))) = (u8) ((*(u8 *)((u8 *)(temp_2_43)+(0x1C))) - 6);
                break;
            case 3:                                 /* switch 7 */
                temp_2_44 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_44)+(0x1D))) = (u8) ((*(u8 *)((u8 *)(temp_2_44)+(0x1D))) - 6);
                temp_2_45 = (u16 *)(func_002e48a0((s64) (*(s8 *)((u8 *)(temp_17)+(0x2F9))), (s64) (*(s8 *)((u8 *)(temp_17)+(0x2FA)))));
                (*(u8 *)((u8 *)(temp_2_45)+(0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_2_45)+(0x1E))) - 6);
                break;
            }
            temp_18_17 = (s64) (func_00308dc0(arg0) << 0x38) >> 0x38;
            temp_16_37 = (s64) (func_00308e50(arg0) << 0x38) >> 0x38;
            func_00110270((u8 *)func_00308cc0(arg0), ((((s64) (temp_18_17 << 0x38) >> 0x38) << 8) | (((s64) (temp_16_37 << 0x38) >> 0x38) | 0x30)) & 0xFFFF);
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x128)))))+(2))));
            func_0010ad80((*(u16 *)((u8 *)(func_002e48a0(0, (s64) (*(s8 *)((u8 *)(temp_17)+(0x129)))))+(2))));
            func_003205f0(arg0, 0x96, 0x94);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x84U;
        } else {
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x81U;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        return;
    case 0x84:                                      /* switch 1 */
        if (((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))) << 0x38) >> 0x38) == 0xE) {
            func_00315600(arg0, 0);
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x28C)))), 0);
            func_002b6140((u8 *)((*(s32 *)((u8 *)(temp_17)+(0x290)))), 0);
            (*(s8 *)((u8 *)(temp_17)+(0xB6))) = 0;
            func_0032f4d0(arg0);
            (*(s8 *)((u8 *)(temp_17)+(0))) = 0;
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x1BU;
            return;
        }
        break;
    case 0x85:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x86U;
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        temp_16_38 = func_0010b6f0() & 0xFFFF;
        if (temp_16_38 == (func_0010b5b0() & 0xFFFF)) {
            func_00310960(arg0, 0x23, 0);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x87U;
            return;
        }
        if (func_00309630((*(u16 *)((u8 *)(func_001102e0())+(2)))) == 1) {
            func_00310960(arg0, 0x27, 0);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x87U;
            return;
        }
        func_00310960(arg0, 0x1E, 1);
        return;
    case 0x86:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        if (func_002bb1c0((*(s8 *)((u8 *)(temp_17)+(0xD)))) == 0) {
            temp_4_3 = func_001102d0() & 0xFFFF;
            if ((((s64) (((temp_4_3 >> 0xC) & 0xF) << 0x38) >> 0x38) >= ((s64) (((temp_4_3 >> 4) & 0xF) << 0x38) >> 0x38)) && (datGetFlag(0x1307) == 0)) {
                temp_2_46 = (s16)(func_003096d0(arg0));
                (*(s16 *)((u8 *)(temp_17)+(0x1C))) = temp_2_46;
                temp_3_18 = (s64) ((s64) temp_2_46 << 0x30) >> 0x30;
                if (temp_3_18 == -1) {
                    func_0010b190((u8 *)func_001102e0());
                    func_00106390(0x1306, 0);
                    func_00106390(0x1307, 0);
                    (*(s16 *)((u8 *)(temp_17)+(0xBC))) = 0x16B;
                    goto block_274;
                }
                temp_16_39 = (u16 *)(iGpffffb3ec + (temp_3_18 * 4));
                (*(s8 *)((u8 *)(temp_17)+(0xD))) = func_002bab80((void *)func_00331660());
                sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840(*temp_16_39));
                func_002bbd80((*(s8 *)((u8 *)(temp_17)+(0xD))), 0, &sp120);
                func_002bafc0((s64) (*(s8 *)((u8 *)(temp_17)+(0xD))), 0);
                func_002badc0((s64) (*(s8 *)((u8 *)(temp_17)+(0xD))), 0x24);
                func_002bb0a0((*(s8 *)((u8 *)(temp_17)+(0xD))), 0);
                func_002bbf60();
                (*(u8 *)((u8 *)(temp_17)+(1))) = 0x88U;
                return;
            }
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            (*(s16 *)((u8 *)(temp_17)+(0xBC))) = 0x16B;
            var_4_6 = 0;
loop_272:
            temp_3_19 = (s64) (var_4_6 << 0x30) >> 0x30;
            if (temp_3_19 < 5) {
                sp2A8[temp_3_19] = 0;
                var_4_6 = (s64) ((var_4_6 + 1) << 0x30) >> 0x30;
                goto loop_272;
            }
            func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2A8);
            goto block_274;
        }
block_274:
        func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0xB);
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x84U;
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        return;
    case 0x88:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        if (func_002bb1c0((*(s8 *)((u8 *)(temp_17)+(0xD)))) == 0) {
            func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
            (*(s16 *)((u8 *)(temp_17)+(0x2D8))) = 0;
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x89U;
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0xB);
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x84U;
        func_0010b190((u8 *)func_001102e0());
        func_00106390(0x1306, 0);
        func_00106390(0x1307, 0);
        (*(s16 *)((u8 *)(temp_17)+(0xBC))) = 0x16B;
        return;
    case 0x89:                                      /* switch 1 */
        temp_16_40 = (u8 *)(iGpffffb3ec + ((*(s16 *)((u8 *)(temp_17)+(0x1C))) * 4));
        temp_2_47 = (s16)(func_002b2cb0((u8) (*(s16 *)((u8 *)(temp_17)+(0x2D8))), 1, 0x28, 0, 1));
        (*(s16 *)((u8 *)(temp_17)+(0x2D8))) = temp_2_47;
        if (((s64) ((s64) temp_2_47 << 0x30) >> 0x30) == 0x14) {
            func_0011cc00(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s16)(*(u16 *)((u8 *)(temp_16_40)+(0))), (*(u16 *)((u8 *)(temp_16_40)+(2))));
            func_0010cd70((u8 *)func_001102e0(), (s16)(*(u16 *)((u8 *)(temp_16_40)+(0))), (*(u16 *)((u8 *)(temp_16_40)+(2))));
            func_0045af60(1, 3, 3, 2);
        }
        if ((*(s16 *)((u8 *)(temp_17)+(0x2D8))) >= 0x28) {
            (*(s8 *)((u8 *)(temp_17)+(0xD))) = func_002bab80((void *)func_00331660());
            sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840((*(u16 *)((u8 *)(temp_16_40)+(0)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_17)+(0xD))), 0, &sp120);
            sprintf(&sp120, &iGpffffa8a4, (s32)func_00243840((*(u16 *)((u8 *)(temp_16_40)+(2)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_17)+(0xD))), 1, &sp120);
            func_002badc0((s64) (*(s8 *)((u8 *)(temp_17)+(0xD))), 0x57);
            (*(u8 *)((u8 *)(temp_17)+(1))) = 0x87U;
            func_0010b190((u8 *)func_001102e0());
            func_00106390(0x1306, 0);
            func_00106390(0x1307, 0);
            (*(s16 *)((u8 *)(temp_17)+(0xBC))) = 0x16B;
            return;
        }
        break;
    case 0x87:                                      /* switch 1 */
        if (func_002bb680((*(s8 *)((u8 *)(temp_17)+(0xD)))) != 0) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_17)+(0xD))));
            return;
        }
        func_00314670((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148))), 0xB);
        (*(u8 *)((u8 *)(temp_17)+(1))) = 0x84U;
        func_002bb550((*(s8 *)((u8 *)(temp_17)+(0xD))));
        var_4_7 = 0;
loop_288:
        temp_3_20 = (s64) (var_4_7 << 0x30) >> 0x30;
        if (temp_3_20 < 5) {
            sp2A0[temp_3_20] = 0;
            var_4_7 = (s64) ((var_4_7 + 1) << 0x30) >> 0x30;
            goto loop_288;
        }
        func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_17)+(0x148)))), (s32)&sp2A0);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00304580);
#endif

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
        if (table[i] == func_002e48a0(0, p[0x128])[1]) return (s8)i;
        if (table[i] == func_002e48a0(0, p[0x129])[1]) return (s8)i;
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
            total += ((u8 *)&func_001102e0()[0x13])[j];
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
    extern void func_003489c0(u8 *, u8 *, f32, f32, f32, f32, FclDrawColor, u16, u32);
    extern void func_00348c30(s32, s32);
    u8 *w = *(u8 **)(task + 0x38);
    u8 pos[12];
    FclDrawColor color;

    func_001102f0(pos, 0x140, 0xA5, 300.0f);
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
    extern s16 func_00247770(s32);
    extern void func_00275980(void *, void *, s32);
    extern void func_0034a820(s32);
    extern void sprintf(void *, const char *, ...);
    extern void func_0045af60(s32, s32, s32, s32);
    extern s32 func_00311930(s32, u16 *, s32);
    extern s32 func_00311900(s32);
    extern void func_00314400(u8 *, s8);
    extern void func_00303de0(u8 *);
    extern void func_00310960(u8 *, s32, s32);
    extern u8 D_00641B50[];
    extern s32 iGpffffa8a4;
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
    cls = *(u16 *)(func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) + 1);
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
        *(func_0034a630(*(s32 *)(p + 0x254)) + 1) = 0;
        for (k = 0; k < 0xC; k++) {
            buf[k] = 0;
        }
        switch (*(s8 *)(p + 0x1A)) {
        case 2:
            buf[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 1);
            break;
        case 3:
            buf[0] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x128)) + 1);
            buf[1] = *(u16 *)(func_002e48a0(0, *(s8 *)(p + 0x129)) + 1);
            buf[2] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 2);
            break;
        case 4:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 3);
            break;
        case 5:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 4);
            break;
        case 6:
            buf[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            buf[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            buf[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            buf[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            buf[4] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
            buf[5] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 5) + 1);
            *(s32 *)(p + 0x304) = func_0033f690(arg0, buf, 5);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                buf[i] = *(u16 *)(func_002e48a0(0, i) + 1);
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
                *func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
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
            *func_002e48a0(*(s8 *)(p + 0x2F9), *(s8 *)(p + 0x2FA)) |= 4;
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
                          iGpffffb44c + func_00109280(*(u16 *)(func_002e48a0(*(s8 *)(p + 0x2F9),
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
        if (*(s8 *)(func_0034a630(*(s32 *)(p + 0x254)) + 4) == 4 && *(s16 *)(p + 0x2D8) >= 0x14) {
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
    FclPackedPosition v0;
    s64 v1;
    s64 v2;
    FclPackedPosition v3;
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
            func_002b2970((u8 *)&v0.bits, 26.0f, (f32)(j * 0x22 + 0x57));
            func_003147e0(arg0, (s8)j, v0.position, (s16)(j + 0x179), (s16)(j * 2 + 2), 0);
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
        func_002b2970((u8 *)&v1, base->x, base->y);
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
                                    func_002b2970((u8 *)&v2, base->x, base->y);
                                    func_00324f80(arg0, v2, 1, 1);
                                    e = *(s16 *)(p + 0x11E) - *(s16 *)(p + 0x120);
                                    k = 0;
                                    lim = e + 6;
                                    for (; e < lim; e++, k++) {
                                        func_002b2970((u8 *)&v3.bits, 26.0f, (f32)(k * 0x22 + 0x57));
                                        func_003147e0(arg0, (s8)k, v3.position, (s16)(e + 0x179),
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
        if (func_002bb680(*(p + 0xD)) != 0) {
            func_002bbcf0(*(p + 0xD));
        } else {
            func_002bb550(*(p + 0xD));
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
    FclPackedPosition v0;
    FclPackedPosition v1;
    FclPackedPosition v2;
    FclPackedPosition v3;
    FclPackedPosition v4;
    FclPackedPosition v5;
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
        func_002b2970((u8 *)&v0.bits, 26.0f, 87.0f);
        func_003147e0(arg0, 0, v0.position, 0x168, 2, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 0;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970((u8 *)&v1.bits, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 1, v1.position, 0x174, 4, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 1;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 0xC;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970((u8 *)&v2.bits, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 2, v2.position, 0x170, 6, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 2;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 8;
        *(s8 *)(p + 0x139) += 1;
        func_002b2970((u8 *)&v3.bits, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
        func_003147e0(arg0, 3, v3.position, 0x171, 8, 0);
        D_00882FB0[*(s8 *)(p + 0x139) * 2] = 3;
        D_00882FB1[*(s8 *)(p + 0x139) * 2] = 9;
        *(s8 *)(p + 0x139) += 1;
        if (datGetFlag(0x1305) != 0) {
            func_002b2970((u8 *)&v4.bits, 26.0f, (f32)(*(s8 *)(p + 0x139) * 0x22 + 0x57));
            func_003147e0(arg0, 0xB, v4.position, 0x173, 0xA, 0);
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
                        func_002badc0(*(p + 0xD), 0x6F);
                    } else if ((s16)func_00104f10(1) >= 3 && datGetFlag(0x96F) == 0) {
                        func_002badc0(*(p + 0xD), 0x70);
                    } else {
                        func_002badc0(*(p + 0xD), (func_00107ac0(0x14) & 0xFFFF) + 0x64);
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
                    func_002b2970((u8 *)&v5.bits, 26.0f, (f32)(i * 0x22 + 0x57));
                    func_003147e0(arg0, *(s8 *)te, v5.position, (s16)(*(s8 *)(te + 1) + 0x168), (s16)(i * 2 + 2), 1);
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

/* measured 0030c3c0 2026-09-19: object 3116 against retail's 3148 instructions, -1.02% inside the 3054-3242 band with
   62 instructions of headroom; 2483 fnalign edits (+24 reloc-only), 2750 differing words.
   No pragmas: retail here is unscheduled like the rest of this unit.
   Built from the m2c oracle from src/generated/code1_0030.c de-noised to this file's idiom - M2C_FIELD expanded to direct
   casts, the gp temporaries resolved to &iGpffffa8a4/&iGpffffa8a0 and ((s32)iGpffffb440), the D_ tables without (s32)&,
   29 s64 temporaries narrowed to s32 (3539 -> 3025 instructions) with seven - var_8, var_8_2-var_8_7 - kept s64 to land
   3116 inside the band, the m2c arg-count hallucinations on func_00331660/func_00106330/func_002e78a0/func_002bb680/
   func_00303a20/func_002b2aa0/func_002e48a0/func_00314670/func_003147d0 cut back to the retail arg counts, the inner
   switch-3 labels restored as case 1-6 plus default (retail sltiu 0x7 jtbl pair), the outer 32-case beq chain kept whole
   through 0xCE (retail has no sltiu bound there, so no empty arms), and the stack slots typed from the frame census
   (spB0/sp90 32B, sp60 48B, spD8/spD0 8B). */
/* measured 0030c3c0 (owner, 2026-09-19): fnalign **2483 -> 2476 edits**, count
   3116 -> 3114 against retail 3145, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 0030c3c0 (owner, 2026-09-20): fnalign **2476 -> 2257 edits** (-219), count
   3114 against retail 3145 (-1.0% INSIDE, deficit 31), words 2768 -> 2761.
   deficit_scan runs 164+54+38 -> 164+32+32: with deficit 31 every run longer than
   31 is a CROSS and was not written. Checked in order per 7bj: hoisted pointer
   (int-add for temp_16+0xD/+1/arg0+0x38 and opt_loop_invariants off, all neutral),
   reload (temp_16 re-read before A9, +1 count neutral; source already reloads
   *(arg0+0x38) 13x matching retail 13x lw 0x38), then arm order. Six `if (>=6)`
   with 9-check vs (temp+1)-check arms were backwards vs retail emission (retail
   tests `<6` with slti/bnez to the (temp+1) arm, source tested `>=6` to the 9
   arm): inverting to `if (<6)` and swapping bodies, semantics-preserving,
   CE loop_200 -42, B4 loop_342 -31, B7 loop_367 -31, B5 loop_312 -31,
   A1 loop_77 -41, A2 loop_129 -43. AB loop_275 tried the same swap and
   regressed +34, so it stays `>=6` (retail matches source there). Remaining
   164 at 0xD450 (A9, no >=6, hoist/reload neutral) and 32+32 at 0xEC3C/0xEDF8
   (AF/B1 BF+9+B8 THEN arms, identical bodies) stay CROSS, not absent. */
// FUN_0030C3C0 NONMATCHING
#ifdef NON_MATCHING
void func_0030c3c0(u8 *arg0) {
    extern s8 func_00105f50(u32);
    extern s32 datGetFlag(s32);
    extern void func_00106390(s32, s32);
    extern void func_0010be60(u8 *, u8 *, s32);
    extern s32 func_0010cd70(u8 *, s32, u16);
    extern s32 func_0010ce10(u8 *, u32);
    extern u32 func_0010ceb0(void *);
    extern s64 func_00110a60(s32, s32);
    extern void func_0011b8f0(u8 *, s32);
    extern void func_0011c6e0(u8 *, s32);
    extern s32 func_0011cb70(u8 *, s32);
    extern s32 func_0011cc00(u8 *, u16, u16);
    extern void func_0011cdd0(u8 *, s16);
    extern void func_0011ce30(u8 *);
    extern void func_0011d140(u8 *, s32);
    extern s32 func_0011f410(u8 *, u16, u8 *, s32, s32, void *);
    extern s32 func_0011f560(s32, s32);
    extern u8 *func_0011fbc0(u8 *, u16, s32, void *);
    extern s32 func_0011fcf0(s32, s32);
    extern s32 func_00243840(s32);
    extern void func_00275980(void *, void *, s32);
    extern void func_002b2970(s64 *, f32, f32);
    extern s32 func_002b2a30(u8, u8, u8, u8);
    extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
    extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
    extern s32 func_002b2d00(s32, s32, s32, s32, s8);
    extern void func_002b68d0(s16, s32, s32);
    extern void func_002b6a70(s32, u8, s32, s32, s32, s32);
    extern s8 func_002bab80(void *);
    extern void func_002badc0(s8, s32);
    extern void func_002bafc0(s8, s32);
    extern void func_002bb0a0(s8, s32);
    extern s8 func_002bb1c0(s8);
    extern void func_002bb550(s8);
    extern s32 func_002bb680(s8);
    extern void func_002bbcf0(s8);
    extern void func_002bbd80(s8, s32, void *);
    extern void func_002bbf60(void);
    extern u16 *func_002e48a0(s8, s16);
    extern void func_002e4960(u8 *, s64, s64);
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern s32 func_00303a20(u8 *);
    extern s32 func_003040d0(u8 *, s16, s32);
    extern u16 func_00304410(u8 *, s64);
    extern s32 func_00313690(s64);
    extern s32 func_00313fb0(u16 *);
    extern void func_00314400(u8 *, s8);
    extern void func_003144d0(u8 *, u16 *, s32, s32, s32);
    extern s8 func_00314660(u8 *);
    extern void func_00314670(u8 *, s8);
    extern void func_003146c0(u8 *, s32);
    extern u8 *func_003147d0(u8 *);
    extern s32 func_00331660(void);
    extern s8 *func_0034a630(s32);
    extern u32 RpRandom(void);
    extern void sprintf(void *, void *, s32);
    extern void func_00452080(s32);
    extern void func_0045aa90(s32, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    extern u8 D_0063FCA0[];
    extern u8 D_006406F0[];
    extern s32 D_00641B90[];
    extern u8 D_00641AD0[];
    extern s16 D_00749040[];
    extern s16 D_00749060[];
    extern s16 D_00749080[];
    extern s16 D_007490A0[];
    extern s16 D_007490C0[];
    extern s16 D_007490E0[];
    extern u16 D_008C024E[];
    extern char iGpffffa8a4;
    extern char iGpffffa8a0;
    u8 spD8[8];
    FclPackedPosition spD0;
    char spB0[32];
    char sp90[32];
    u8 sp60[48];
    f32 temp_f0;
    s32 var_3;
    f32 var_f13;
    s16 temp_18_7;
    s16 temp_2_13;
    s16 temp_2_14;
    s16 temp_2_17;
    s16 temp_2_18;
    s16 temp_2_19;
    s16 temp_2_20;
    s16 temp_2_2;
    s16 temp_4_2;
    s16 var_2;
    s16 var_2_2;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_8;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_4;
    s32 var_4_12;
    s32 var_4_13;
    s32 var_4_14;
    s32 var_4_15;
    s32 var_4_16;
    s32 var_4_17;
    s32 var_4_18;
    s32 var_4_19;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_4_4;
    s32 var_4_5;
    s32 var_4_6;
    s32 var_4_7;
    s32 var_4_8;
    s32 var_4_9;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s64 temp_2_15;
    s64 temp_2_16;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_9;
    s64 temp_4_10;
    s64 temp_4_11;
    s64 temp_4_12;
    s64 temp_4_13;
    s64 temp_4_14;
    s64 temp_4_15;
    s64 temp_4_16;
    s64 temp_4_17;
    s64 temp_4_18;
    s64 temp_4_19;
    s64 temp_4_21;
    s64 temp_4_22;
    s64 temp_4_23;
    s64 temp_4_24;
    s64 temp_4_25;
    s64 temp_4_3;
    s64 temp_4_5;
    s64 temp_4_7;
    s64 temp_4_8;
    s64 temp_4_9;
    s64 temp_5;
    s64 temp_5_10;
    s64 temp_5_11;
    s64 temp_5_12;
    s64 temp_5_13;
    s64 temp_5_14;
    s64 temp_5_15;
    s64 temp_5_16;
    s64 temp_5_17;
    s64 temp_5_18;
    s64 temp_5_19;
    s64 temp_5_20;
    s64 temp_5_21;
    s64 temp_5_22;
    s64 temp_5_2;
    s64 temp_5_3;
    s64 temp_5_4;
    s64 temp_5_5;
    s64 temp_5_6;
    s64 temp_5_7;
    s64 temp_5_8;
    s64 temp_5_9;
    s64 temp_7_4;
    s64 var_10;
    s64 var_10_2;
    s64 var_10_3;
    s64 var_10_4;
    s64 var_10_5;
    s64 var_10_6;
    s64 var_10_7;
    s64 var_20;
    s64 var_3_2;
    s64 var_3_3;
    s64 var_3_4;
    s64 var_3_5;
    s64 var_3_6;
    s32 var_4_10;
    s32 var_4_11;
    s32 var_5_10;
    s64 var_6;
    s64 var_6_2;
    s64 var_6_3;
    s64 var_6_4;
    s64 var_6_5;
    s64 var_6_6;
    s32 var_7;
    s32 var_7_2;
    s64 var_8;
    s32 var_8_10;
    s32 var_8_11;
    s32 var_8_12;
    s32 var_8_13;
    s32 var_8_14;
    s32 var_8_15;
    s32 var_8_16;
    s32 var_8_17;
    s32 var_8_18;
    s32 var_8_19;
    s64 var_8_2;
    s64 var_8_3;
    s64 var_8_4;
    s64 var_8_5;
    s64 var_8_6;
    s64 var_8_7;
    s32 var_8_8;
    s32 var_8_9;
    s64 var_9;
    s64 var_9_2;
    s64 var_9_3;
    s64 var_9_4;
    s64 var_9_5;
    s64 var_9_6;
    s64 var_9_7;
    s8 temp_18_3;
    s8 temp_18_5;
    s8 temp_2_12;
    s8 temp_2_9;
    s8 temp_3_12;
    s8 temp_3_13;
    s8 temp_3_14;
    s8 temp_3_15;
    s8 temp_6;
    s8 temp_7;
    s8 temp_7_2;
    s8 temp_7_3;
    s8 var_5_7;
    s8 var_5_8;
    u16 *temp_2_3;
    u16 *temp_2_4;
    u16 *temp_2_6;
    u16 *temp_2_8;
    u16 temp_17;
    u16 temp_18_2;
    u16 temp_18_4;
    u16 temp_18_6;
    u32 temp_17_10;
    u8 temp_17_5;
    u8 temp_17_6;
    u8 temp_4;
    u8 temp_4_20;
    u8 temp_4_4;
    u8 temp_4_6;
    u8 *temp_16;
    u8 *temp_17_7;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_6;
    u8 *temp_3_7;
    u8 *temp_3_8;
    u8 *temp_7_5;
    u8 *temp_7_6;
    u8 *temp_7_7;
    u8 *temp_7_8;
    u8 *temp_7_9;
    u8 *temp_8;
    u8 *temp_8_2;
    u8 *temp_8_3;
    u8 *var_5_9;

    temp_16 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
    temp_17 = (u16)((u16)((u16)((*(u16 *)((u8 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))))+(2))))));
    temp_4 = (u8)((u8)((u8)((*(u8 *)((u8 *)(temp_16)+(1))))));
    switch (temp_4) {                               /* switch 1; irregular */
    case 0xA0:                                      /* switch 1 */
        if ((s32)((s32)(datGetFlag(0x5E))) != (s32)((s32)(0))) {
            *func_0034a630((*(s32 *)((u8 *)(temp_16)+(0x254)))) = 4;
            func_003144d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), 0, 0, 0);
            temp_17_2 = (s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
            func_0011d140((u8 *)temp_17_2, func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF));
            func_0011c6e0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), 1);
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA1U;
            return;
        }
        return;
    case 0xA1:                                      /* switch 1 */
        func_00106390(0x5D, 1);
        if ((s32)((s32)(((s64) (func_00105f50(temp_17) << 0x38) >> 0x38))) > (s32)((s32)(0))) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA2U;
            func_0010be60((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), (temp_16 + 0x28), (*(s32 *)((u8 *)(temp_16)+(0x10))));
            (*(u8 *)((u8 *)(temp_16)+(0xB1))) = (u8)((u8)((u8) (*(u8 *)((u8 *)(temp_16)+(0x28)))));
            return;
        }
        if ((s32)((s32)(func_00303a20(arg0))) == (s32)((s32)(1))) {
            temp_3 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_8 = 0;
loop_42:
            temp_5 = (s64) (var_8 << 0x30) >> 0x30;
            if (temp_5 >= (*(s8 *)((u8 *)(temp_3)+(0x2DF)))) {
                var_5 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3) + temp_5))+(0x2DA))) == 7) {
                var_5 = 1;
            } else {
                var_8 = (s64) ((var_8 + 1) << 0x30) >> 0x30;
                goto loop_42;
            }
            if (var_5 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 1;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    return;
                }
            } else {
                var_8_2 = 0;
loop_51:
                temp_5_2 = (s64) (var_8_2 << 0x30) >> 0x30;
                if (temp_5_2 >= (*(s8 *)((u8 *)(temp_3)+(0x2DF)))) {
                    var_5_2 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_3) + temp_5_2))+(0x2DA))) == 0xD) {
                    var_5_2 = 1;
                } else {
                    var_8_2 = (s64) ((var_8_2 + 1) << 0x30) >> 0x30;
                    goto loop_51;
                }
                if (var_5_2 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                    (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 3;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                        return;
                    }
                } else {
                    var_8_3 = 0;
loop_60:
                    temp_5_3 = (s64) (var_8_3 << 0x30) >> 0x30;
                    if (temp_5_3 >= (*(s8 *)((u8 *)(temp_3)+(0x2DF)))) {
                        var_4 = 0;
                    } else if ((*(s8 *)((u8 *)(((s32)(temp_3) + temp_5_3))+(0x2DA))) == 0xA) {
                        var_4 = 1;
                    } else {
                        var_8_3 = (s64) ((var_8_3 + 1) << 0x30) >> 0x30;
                        goto loop_60;
                    }
                    if (var_4 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB2U;
                        (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB2U;
                        if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                            return;
                        }
                    } else {
                        var_10 = 0;
loop_77:
                        temp_5_4 = (s64) (var_10 << 0x30) >> 0x30;
                        if (temp_5_4 < 6) {
                            var_9 = 0;
loop_70:
                            temp_5_6 = (s64) (var_9 << 0x30) >> 0x30;
                            if (temp_5_6 >= (*(s8 *)((u8 *)(temp_3)+(0x2DF)))) {
                                var_4_3 = 0;
                            } else if (((s64) ((temp_5_4 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_3) + temp_5_6))+(0x2DA)))) {
                                var_4_3 = 1;
                            } else {
                                var_9 = (s64) ((var_9 + 1) << 0x30) >> 0x30;
                                goto loop_70;
                            }
                            if (var_4_3 == 1) {
                                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                                }
                                return;
                            }
                            var_10 = (s64) ((var_10 + 1) << 0x30) >> 0x30;
                            goto loop_77;
                        } else {
                            var_8_4 = 0;
loop_82:
                            temp_5_5 = (s64) (var_8_4 << 0x30) >> 0x30;
                            if (temp_5_5 >= (*(s8 *)((u8 *)(temp_3)+(0x2DF)))) {
                                var_4_2 = 0;
                            } else if ((*(s8 *)((u8 *)(((s32)(temp_3) + temp_5_5))+(0x2DA))) == 9) {
                                var_4_2 = 1;
                            } else {
                                var_8_4 = (s64) ((var_8_4 + 1) << 0x30) >> 0x30;
                                goto loop_82;
                            }
                            if (var_4_2 == 1) {
                                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 0xA2:                                      /* switch 1 */
        if ((s32)((s32)((s8) (*(u8 *)((u8 *)(temp_16)+(0xB1))))) != (s32)((s32)(0))) {
            (*(s32 *)((u8 *)(temp_16)+(0x14))) = (s32)((s32)(func_00313fb0(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))))));
            func_0010be60((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), (temp_16 + 0x28), (*(s32 *)((u8 *)(temp_16)+(0x14))));
            (*(s32 *)((u8 *)(temp_16)+(0x10))) = (s32)((s32)((s32) ((*(s32 *)((u8 *)(temp_16)+(0x10))) - (*(s32 *)((u8 *)(temp_16)+(0x14))))));
            (*(s16 *)((u8 *)(temp_16)+(0x1C))) = 0;
            (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 1;
            (*(u8 *)((u8 *)(temp_16)+(0xB1))) = (u8)((u8)((u8) ((s8) (*(u8 *)((u8 *)(temp_16)+(0xB1))) - 1)));
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA4U;
            func_0045af60(0, 0, 0, 0xA);
            return;
        }
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        if ((s32)((s32)(func_00303a20(arg0))) == (s32)((s32)(1))) {
            temp_3_2 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_8_5 = 0;
loop_94:
            temp_5_7 = (s64) (var_8_5 << 0x30) >> 0x30;
            if (temp_5_7 >= (*(s8 *)((u8 *)(temp_3_2)+(0x2DF)))) {
                var_5_3 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_2) + temp_5_7))+(0x2DA))) == 7) {
                var_5_3 = 1;
            } else {
                var_8_5 = (s64) ((var_8_5 + 1) << 0x30) >> 0x30;
                goto loop_94;
            }
            if (var_5_3 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 1;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    return;
                }
            } else {
                var_8_6 = 0;
loop_103:
                temp_5_8 = (s64) (var_8_6 << 0x30) >> 0x30;
                if (temp_5_8 >= (*(s8 *)((u8 *)(temp_3_2)+(0x2DF)))) {
                    var_5_4 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_3_2) + temp_5_8))+(0x2DA))) == 0xD) {
                    var_5_4 = 1;
                } else {
                    var_8_6 = (s64) ((var_8_6 + 1) << 0x30) >> 0x30;
                    goto loop_103;
                }
                if (var_5_4 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                    (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 3;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                        return;
                    }
                } else {
                    var_8_7 = 0;
loop_112:
                    temp_5_9 = (s64) (var_8_7 << 0x30) >> 0x30;
                    if (temp_5_9 >= (*(s8 *)((u8 *)(temp_3_2)+(0x2DF)))) {
                        var_4_4 = 0;
                    } else if ((*(s8 *)((u8 *)(((s32)(temp_3_2) + temp_5_9))+(0x2DA))) == 0xA) {
                        var_4_4 = 1;
                    } else {
                        var_8_7 = (s64) ((var_8_7 + 1) << 0x30) >> 0x30;
                        goto loop_112;
                    }
                    if (var_4_4 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB2U;
                        (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB2U;
                        if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                            return;
                        }
                    } else {
                        var_9_2 = 0;
loop_129:
                        temp_5_10 = (s64) (var_9_2 << 0x30) >> 0x30;
                        if (temp_5_10 < 6) {
                            var_10_2 = 0;
loop_122:
                            temp_5_12 = (s64) (var_10_2 << 0x30) >> 0x30;
                            if (temp_5_12 >= (*(s8 *)((u8 *)(temp_3_2)+(0x2DF)))) {
                                var_4_6 = 0;
                            } else if (((s64) ((temp_5_10 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_3_2) + temp_5_12))+(0x2DA)))) {
                                var_4_6 = 1;
                            } else {
                                var_10_2 = (s64) ((var_10_2 + 1) << 0x30) >> 0x30;
                                goto loop_122;
                            }
                            if (var_4_6 == 1) {
                                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                                }
                                return;
                            }
                            var_9_2 = (s64) ((var_9_2 + 1) << 0x30) >> 0x30;
                            goto loop_129;
                        } else {
                            var_8_8 = 0;
loop_134:
                            temp_5_11 = (s64) (var_8_8 << 0x30) >> 0x30;
                            if (temp_5_11 >= (*(s8 *)((u8 *)(temp_3_2)+(0x2DF)))) {
                                var_4_5 = 0;
                            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_2) + temp_5_11))+(0x2DA))) == 9) {
                                var_4_5 = 1;
                            } else {
                                var_8_8 = (s64) ((var_8_8 + 1) << 0x30) >> 0x30;
                                goto loop_134;
                            }
                            if (var_4_5 == 1) {
                                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 0xA3:                                      /* switch 1 */
        if ((s32)((s32)(func_0011f560((*(s32 *)((u8 *)(temp_16)+(0x2A4))), 0xA3))) != (s32)((s32)(0))) {
            func_00452080((*(s32 *)((u8 *)(temp_16)+(0x2A4))));
            (*(s32 *)((u8 *)(temp_16)+(0x2A4))) = 0;
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA2U;
            return;
        }
        break;
    case 0xA4:                                      /* switch 1 */
        temp_2 = (s32)((s32)((s32)((*(s32 *)((u8 *)(temp_16)+(0x14))))));
        if (temp_2 >= 0) {
            var_f13 = (f32) temp_2;
        } else {
            var_f13 = 2.0f * (f32)(s32)(((u32) temp_2 >> 1) | (temp_2 & 1));
        }
        temp_f0 = func_002b2aa0(2, 1.0f, var_f13, (f32) (*(s16 *)((u8 *)(temp_16)+(0x2D8))), 55.0f);
        if (!(temp_f0 >= 2.1474836e9f)) {
            var_3 = (s32) temp_f0;
        } else {
            var_3 = (s32) (temp_f0 - 2.1474836e9f) | 0x80000000;
        }
        func_003146c0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), (*(s32 *)((u8 *)(temp_16)+(0x14))) - var_3);
        temp_4_2 = (s16)((s16)((s16)((*(s16 *)((u8 *)(temp_16)+(0x2D8))))));
        if (temp_4_2 < 0x37) {
            temp_2_2 = (s16)((s16)(func_002b2cb0(temp_4_2, 1, 0x37, 0, 1)));
            (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_2;
            if ((((s64) ((s64) temp_2_2 << 0x30) >> 0x30) >= 0x10) && ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x800))) {
                (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0x37;
                return;
            }
        } else {
            func_0045aa90(0, 0);
            temp_17_3 = (s32)((s32)((s32)(func_00313fb0(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA))))))));
            temp_2_3 = (u16 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))));
            (*(s32 *)((u8 *)(temp_2_3)+(8))) = (s32)((s32)((s32) ((*(s32 *)((u8 *)(temp_2_3)+(8))) + temp_17_3)));
            if ((s32)((s32)((s8) (*(u8 *)((u8 *)(temp_16)+(0xB1))))) == (s32)((s32)(0))) {
                temp_2_4 = (u16 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))));
                (*(s32 *)((u8 *)(temp_2_4)+(8))) = (s32)((s32)((s32) ((*(s32 *)((u8 *)(temp_2_4)+(8))) + (*(s32 *)((u8 *)(temp_16)+(0x10))))));
            }
            temp_17_4 = (s32)((s32)((s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))))));
            (*(s32 *)((u8 *)(temp_16)+(0x2A4))) = (s32)((s32)(func_0011f410(arg0, temp_17_4, (temp_16 + 0x28), func_00331660(), 0, &D_00641AD0)));
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA3U;
            return;
        }
        break;
    case 0xCE:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        if ((s32)((s32)(func_00303a20(arg0))) == (s32)((s32)(1))) {
            temp_3_3 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_8_9 = 0;
            temp_7 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_3_3)+(0x2DF))))));
loop_163:
            temp_5_13 = (s64) (var_8_9 << 0x30) >> 0x30;
            if (temp_5_13 >= temp_7) {
                var_5_5 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_3) + temp_5_13))+(0x2DA))) == 7) {
                var_5_5 = 1;
            } else {
                var_8_9 = (s64) ((var_8_9 + 1) << 0x30) >> 0x30;
                goto loop_163;
            }
            if (var_5_5 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 1;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBCU;
                }
                func_00314670((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 9);
                return;
            }
            var_8_10 = 0;
            temp_7_2 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_3_3)+(0x2DF))))));
loop_173:
            temp_5_14 = (s64) (var_8_10 << 0x30) >> 0x30;
            if (temp_5_14 >= temp_7_2) {
                var_5_6 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_3) + temp_5_14))+(0x2DA))) == 0xD) {
                var_5_6 = 1;
            } else {
                var_8_10 = (s64) ((var_8_10 + 1) << 0x30) >> 0x30;
                goto loop_173;
            }
            if (var_5_6 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA8U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xA8U;
                (*(s8 *)((u8 *)(temp_16)+(0x13C))) = 3;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBCU;
                }
                func_00314670((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 9);
                return;
            }
            var_8_11 = 0;
loop_183:
            temp_5_15 = (s64) (var_8_11 << 0x30) >> 0x30;
            if (temp_5_15 >= (*(s8 *)((u8 *)(temp_3_3)+(0x2DF)))) {
                var_4_7 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_3) + temp_5_15))+(0x2DA))) == 0xA) {
                var_4_7 = 1;
            } else {
                var_8_11 = (s64) ((var_8_11 + 1) << 0x30) >> 0x30;
                goto loop_183;
            }
            if (var_4_7 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB2U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB2U;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    return;
                }
            } else {
                var_9_3 = 0;
loop_200:
                temp_5_16 = (s64) (var_9_3 << 0x30) >> 0x30;
                if (temp_5_16 < 6) {
                    var_10_3 = 0;
                    temp_7_4 = (s64) ((temp_5_16 + 1) << 0x38) >> 0x38;
                    temp_6 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_3_3)+(0x2DF))))));
loop_193:
                    temp_5_18 = (s64) (var_10_3 << 0x30) >> 0x30;
                    if (temp_5_18 >= temp_6) {
                        var_4_9 = 0;
                    } else if (temp_7_4 == (*(s8 *)((u8 *)(((s32)(temp_3_3) + temp_5_18))+(0x2DA)))) {
                        var_4_9 = 1;
                    } else {
                        var_10_3 = (s64) ((var_10_3 + 1) << 0x30) >> 0x30;
                        goto loop_193;
                    }
                    if (var_4_9 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                        (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                        if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBCU;
                        }
                        func_00314670((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 9);
                        return;
                    }
                    var_9_3 = (s64) ((var_9_3 + 1) << 0x30) >> 0x30;
                    goto loop_200;
                } else {
                    var_8_12 = 0;
                    temp_7_3 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_3_3)+(0x2DF))))));
loop_205:
                    temp_5_17 = (s64) (var_8_12 << 0x30) >> 0x30;
                    if (temp_5_17 >= temp_7_3) {
                        var_4_8 = 0;
                    } else if ((*(s8 *)((u8 *)(((s32)(temp_3_3) + temp_5_17))+(0x2DA))) == 9) {
                        var_4_8 = 1;
                    } else {
                        var_8_12 = (s64) ((var_8_12 + 1) << 0x30) >> 0x30;
                        goto loop_205;
                    }
                    if (var_4_8 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                        (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                        if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBCU;
                        }
                        func_00314670((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 9);
                        return;
                    }
                }
            }
        }
        break;
    case 0xA8:                                      /* switch 1 */
        var_3_2 = 0;
do {
                var_3_2 = (s64) ((var_3_2 + 1) << 0x30) >> 0x30;
} while (((s64) (var_3_2 << 0x30) >> 0x30) < 5);
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        var_4_10 = 0;
loop_216:
        temp_3_4 = (s64) (var_4_10 << 0x30) >> 0x30;
        if (temp_3_4 < 0x20) {
            spB0[temp_3_4] = 0;
            var_4_10 = (s64) ((var_4_10 + 1) << 0x30) >> 0x30;
            goto loop_216;
        }
        sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x54);
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xA9U;
        return;
    case 0xA9:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        var_4_11 = 0;
loop_222:
        temp_3_5 = (s64) (var_4_11 << 0x30) >> 0x30;
        if (temp_3_5 < 5) {
            spD8[temp_3_5] = 0;
            var_4_11 = (s64) ((var_4_11 + 1) << 0x30) >> 0x30;
            goto loop_222;
        }
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        var_3_3 = 0;
loop_225:
        if (((s64) (var_3_3 << 0x30) >> 0x30) < 0x20) {
            sp90[((s64) (var_3_3 << 0x30) >> 0x30)] = 0;
            spB0[((s64) (var_3_3 << 0x30) >> 0x30)] = 0;
            var_3_3 = (s64) ((var_3_3 + 1) << 0x30) >> 0x30;
            goto loop_225;
        }
        temp_2_6 = (u16 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))));
        var_6 = 0;
        var_5_7 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_2_6)+(0x1C))))));
        var_7 = 1;
loop_230:
        temp_4_3 = (s64) (var_7 << 0x30) >> 0x30;
        if (temp_4_3 < 5) {
            temp_4_4 = (u8)((u8)((u8)((*(u8 *)((u8 *)(((s32)(temp_2_6) + temp_4_3))+(0x1C))))));
            if (((s64) ((s64) var_5_7 << 0x38) >> 0x38) < (s32) temp_4_4) {
                var_5_7 = (s8) ((s64) ((s64) temp_4_4 << 0x38) >> 0x38);
                var_6 = (s64) (var_7 << 0x38) >> 0x38;
            }
            var_7 = (s64) ((var_7 + 1) << 0x30) >> 0x30;
            goto loop_230;
        }
        (*(s8 *)((u8 *)(temp_16)+(0x13D))) = (s8) var_6;
        sprintf(spB0, &iGpffffa8a4, *(s32 *)((u8 *)D_00641B90 + (((s64) (var_6 << 0x38) >> 0x38) * 4)));
        func_00275980(&spB0, &sp90, 0x20);
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &sp90);
        spD8[(*(s8 *)((u8 *)(temp_16)+(0x13D)))] = (*(s8 *)((u8 *)(temp_16)+(0x13C)));
        temp_17_5 = (u8)((u8)((u8) (*(s8 *)((u8 *)(temp_16)+(0x13C)))));
        temp_3_6 = (u8 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + (*(s8 *)((u8 *)(temp_16)+(0x13D))));
        (*(u8 *)((u8 *)(temp_3_6)+(0x1C))) = (u8)((u8)((u8) ((*(u8 *)((u8 *)(temp_3_6)+(0x1C))) + temp_17_5)));
        var_3_4 = 0;
loop_233:
        if (((s64) (var_3_4 << 0x30) >> 0x30) < 0x20) {
            sp90[((s64) (var_3_4 << 0x30) >> 0x30)] = 0;
            spB0[((s64) (var_3_4 << 0x30) >> 0x30)] = 0;
            var_3_4 = (s64) ((var_3_4 + 1) << 0x30) >> 0x30;
            goto loop_233;
        }
        sprintf(&spB0, &iGpffffa8a0, (s32) (*(s8 *)((u8 *)(temp_16)+(0x13C))));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
        temp_2_8 = (u16 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))));
        var_6_2 = 0;
        var_5_8 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_2_8)+(0x1C))))));
        var_7_2 = 1;
loop_238:
        temp_4_5 = (s64) (var_7_2 << 0x30) >> 0x30;
        if (temp_4_5 < 5) {
            temp_4_6 = (u8)((u8)((u8)((*(u8 *)((u8 *)(((s32)(temp_2_8) + temp_4_5))+(0x1C))))));
            if ((s32) temp_4_6 < ((s64) ((s64) var_5_8 << 0x38) >> 0x38)) {
                var_5_8 = (s8) ((s64) ((s64) temp_4_6 << 0x38) >> 0x38);
                var_6_2 = (s64) (var_7_2 << 0x38) >> 0x38;
            }
            var_7_2 = (s64) ((var_7_2 + 1) << 0x30) >> 0x30;
            goto loop_238;
        }
        (*(s8 *)((u8 *)(temp_16)+(0x13E))) = (s8) var_6_2;
        spD8[((s64) (var_6_2 << 0x38) >> 0x38)] = (*(s8 *)((u8 *)(temp_16)+(0x13C)));
        temp_17_6 = (u8)((u8)((u8) (*(s8 *)((u8 *)(temp_16)+(0x13C)))));
        temp_3_7 = (u8 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + (*(s8 *)((u8 *)(temp_16)+(0x13E))));
        (*(u8 *)((u8 *)(temp_3_7)+(0x1C))) = (u8)((u8)((u8) ((*(u8 *)((u8 *)(temp_3_7)+(0x1C))) + temp_17_6)));
        func_0011b8f0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (s32)spD8);
        (*(s8 *)((u8 *)(temp_16)+(0xB0))) = 0;
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x3E);
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xAAU;
        return;
    case 0xAA:                                      /* switch 1 */
        temp_2_9 = (s8)((s8)((s8)(func_002b2cb0((s16) (*(s8 *)((u8 *)(temp_16)+(0xB0))), 1, 0x14, 0, 1))));
        (*(s8 *)((u8 *)(temp_16)+(0xB0))) = temp_2_9;
        if (((s64) ((s64) temp_2_9 << 0x38) >> 0x38) == 0xF) {
            func_0045af60(1, 3, 3, 1);
        }
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        var_3_5 = 0;
loop_246:
        if (((s64) (var_3_5 << 0x30) >> 0x30) < 0x20) {
            sp90[((s64) (var_3_5 << 0x30) >> 0x30)] = 0;
            spB0[((s64) (var_3_5 << 0x30) >> 0x30)] = 0;
            var_3_5 = (s64) ((var_3_5 + 1) << 0x30) >> 0x30;
            goto loop_246;
        }
        sprintf(spB0, &iGpffffa8a4, *(s32 *)((u8 *)D_00641B90 + ((*(s8 *)((u8 *)(temp_16)+(0x13E))) * 4)));
        func_00275980(&spB0, &sp90, 0x20);
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &sp90);
        var_3_6 = 0;
loop_249:
        if (((s64) (var_3_6 << 0x30) >> 0x30) < 0x20) {
            sp90[((s64) (var_3_6 << 0x30) >> 0x30)] = 0;
            spB0[((s64) (var_3_6 << 0x30) >> 0x30)] = 0;
            var_3_6 = (s64) ((var_3_6 + 1) << 0x30) >> 0x30;
            goto loop_249;
        }
        sprintf(&spB0, &iGpffffa8a0, (s32) (*(s8 *)((u8 *)(temp_16)+(0x13C))));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x3E);
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xABU;
        (*(s8 *)((u8 *)(temp_16)+(0xB0))) = 0;
        return;
    case 0xAB:                                      /* switch 1 */
        temp_2_12 = (s8)((s8)((s8)(func_002b2cb0((s16) (*(s8 *)((u8 *)(temp_16)+(0xB0))), 1, 0x14, 0, 1))));
        (*(s8 *)((u8 *)(temp_16)+(0xB0))) = temp_2_12;
        if (((s64) ((s64) temp_2_12 << 0x38) >> 0x38) == 0xF) {
            func_0045af60(1, 3, 3, 1);
        }
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        if ((s32)((s32)(func_00303a20(arg0))) == (s32)((s32)(1))) {
            temp_3_8 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_8_13 = 0;
loop_260:
            temp_5_19 = (s64) (var_8_13 << 0x30) >> 0x30;
            if (temp_5_19 >= (*(s8 *)((u8 *)(temp_3_8)+(0x2DF)))) {
                var_4_12 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_3_8) + temp_5_19))+(0x2DA))) == 0xA) {
                var_4_12 = 1;
            } else {
                var_8_13 = (s64) ((var_8_13 + 1) << 0x30) >> 0x30;
                goto loop_260;
            }
            if (var_4_12 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB2U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB2U;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    return;
                }
            } else {
                var_9_4 = 0;
loop_275:
                temp_5_20 = (s64) (var_9_4 << 0x30) >> 0x30;
                if (temp_5_20 >= 6) {
                    var_8_14 = 0;
loop_280:
                    temp_5_21 = (s64) (var_8_14 << 0x30) >> 0x30;
                    if (temp_5_21 >= (*(s8 *)((u8 *)(temp_3_8)+(0x2DF)))) {
                        var_4_13 = 0;
                    } else if ((*(s8 *)((u8 *)(((s32)(temp_3_8) + temp_5_21))+(0x2DA))) == 9) {
                        var_4_13 = 1;
                    } else {
                        var_8_14 = (s64) ((var_8_14 + 1) << 0x30) >> 0x30;
                        goto loop_280;
                    }
                    if (var_4_13 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                        return;
                    }
                } else {
                    var_10_4 = 0;
loop_270:
                    temp_5_22 = (s64) (var_10_4 << 0x30) >> 0x30;
                    if (temp_5_22 >= (*(s8 *)((u8 *)(temp_3_8)+(0x2DF)))) {
                        var_4_14 = 0;
                    } else if (((s64) ((temp_5_20 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_3_8) + temp_5_22))+(0x2DA)))) {
                        var_4_14 = 1;
                    } else {
                        var_10_4 = (s64) ((var_10_4 + 1) << 0x30) >> 0x30;
                        goto loop_270;
                    }
                    if (var_4_14 == 1) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                        return;
                    }
                    var_9_4 = (s64) ((var_9_4 + 1) << 0x30) >> 0x30;
                    goto loop_275;
                }
            }
        }
        break;
    case 0xB2:                                      /* switch 1 */
        temp_17_7 = (u8 *)(D_0063FCA0 + ((*(s8 *)((u8 *)(temp_16)+(0x2D4))) * 0x1C));
        temp_18 = (s32)((s32)(func_002e78a0() & 0xFF));
        var_5_9 = (u8 *)(D_006406F0 + (((s64) (func_00110a60(temp_18, func_002e78e0() & 0xFF) << 0x38) >> 0x38) * 0x14));
        if ((*(s8 *)((u8 *)(temp_16)+(0x2D4))) == -1) {
            var_6_3 = 0;
loop_289:
            temp_3_9 = (s64) (var_6_3 << 0x30) >> 0x30;
            if (temp_3_9 >= 5) {

            } else if ((*(s8 *)((u8 *)(((s32)(temp_16) + temp_3_9))+(0x2DA))) == 0xA) {
                (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16)((s16)((s16) (*(s16 *)((u8 *)(((temp_3_9 * 4) + (s32)(var_5_9)))+(2)))));
            } else {
                var_6_3 = (s64) ((var_6_3 + 1) << 0x30) >> 0x30;
                goto loop_289;
            }
        } else {
            var_6_3 = 0;
            var_5_9 = (u8 *) (*(s8 *)((u8 *)(temp_16)+(0x2DF)));
loop_295:
            temp_3_10 = (s64) (var_6_3 << 0x30) >> 0x30;
            if ((s32)((s32)(temp_3_10)) < (s32)((s32)((s32) var_5_9))) {
                if ((*(s8 *)((u8 *)(((s32)(temp_16) + temp_3_10))+(0x2DA))) == 0xA) {
                    (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16)((s16)((s16) (*(s16 *)((u8 *)(((temp_3_10 * 4) + (s32)(temp_17_7)))+(0xA)))));
                } else {
                    var_6_3 = (s64) ((var_6_3 + 1) << 0x30) >> 0x30;
                    goto loop_295;
                }
            }
        }
        func_0011cdd0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0;
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB3U;
        return;
    case 0xB3:                                      /* switch 1 */
        temp_2_13 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0x2D8))), 1, 0x14, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_13;
        if (((s64) ((s64) temp_2_13 << 0x30) >> 0x30) >= 0x14) {
            (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
            sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
            sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
            func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x51);
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB6U;
            return;
        }
        break;
    case 0xB5:                                      /* switch 1 */
        if ((s32)((s32)(func_0011fcf0((*(s32 *)((u8 *)(temp_16)+(0x2A8))), 0xB5))) == (s32)((s32)(1))) {
            func_00452080((*(s32 *)((u8 *)(temp_16)+(0x2A8))));
            (*(s32 *)((u8 *)(temp_16)+(0x2A8))) = 0;
            func_0011ce30(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
            var_9_5 = 0;
loop_312:
            temp_4_7 = (s64) (var_9_5 << 0x30) >> 0x30;
            if (temp_4_7 < 6) {
                temp_8 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_10_5 = 0;
loop_305:
                temp_4_9 = (s64) (var_10_5 << 0x30) >> 0x30;
                if (temp_4_9 >= (*(s8 *)((u8 *)(temp_8)+(0x2DF)))) {
                    var_3_7 = 0;
                } else if (((s64) ((temp_4_7 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_8) + temp_4_9))+(0x2DA)))) {
                    var_3_7 = 1;
                } else {
                    var_10_5 = (s64) ((var_10_5 + 1) << 0x30) >> 0x30;
                    goto loop_305;
                }
                if (var_3_7 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    }
                    return;
                }
                var_9_5 = (s64) ((var_9_5 + 1) << 0x30) >> 0x30;
                goto loop_312;
            } else {
                temp_7_5 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_8_15 = 0;
loop_317:
                temp_4_8 = (s64) (var_8_15 << 0x30) >> 0x30;
                if (temp_4_8 >= (*(s8 *)((u8 *)(temp_7_5)+(0x2DF)))) {
                    var_4_15 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_7_5) + temp_4_8))+(0x2DA))) == 9) {
                    var_4_15 = 1;
                } else {
                    var_8_15 = (s64) ((var_8_15 + 1) << 0x30) >> 0x30;
                    goto loop_317;
                }
                if (var_4_15 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                        return;
                    }
                }
            }
        }
        break;
    case 0xB6:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0;
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB7U;
        if ((s32)((s32)(func_0010ce10((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))))) != (s32)((s32)(-1))) {
            (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
            sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
            func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x52);
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB4U;
            return;
        }
        if ((s32)((s32)(func_0010ceb0(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA))))))) >= (s32)((s32)(8))) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB5U;
            temp_17_8 = (s32)((s32)((s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))))));
            (*(s32 *)((u8 *)(temp_16)+(0x2A8))) = (s32)((s32)(func_0011fbc0(arg0, temp_17_8, func_00331660(), &D_00641AD0)));
            return;
        }
        break;
    case 0xB4:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        func_0011ce30(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
        var_9_6 = 0;
loop_342:
        temp_4_10 = (s64) (var_9_6 << 0x30) >> 0x30;
        if (temp_4_10 < 6) {
            temp_8_2 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_10_6 = 0;
loop_335:
            temp_4_12 = (s64) (var_10_6 << 0x30) >> 0x30;
            if (temp_4_12 >= (*(s8 *)((u8 *)(temp_8_2)+(0x2DF)))) {
                var_3_8 = 0;
            } else if (((s64) ((temp_4_10 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_8_2) + temp_4_12))+(0x2DA)))) {
                var_3_8 = 1;
            } else {
                var_10_6 = (s64) ((var_10_6 + 1) << 0x30) >> 0x30;
                goto loop_335;
            }
            if (var_3_8 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                }
                return;
            }
            var_9_6 = (s64) ((var_9_6 + 1) << 0x30) >> 0x30;
            goto loop_342;
        } else {
            temp_7_6 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
            var_8_16 = 0;
loop_347:
            temp_4_11 = (s64) (var_8_16 << 0x30) >> 0x30;
            if (temp_4_11 >= (*(s8 *)((u8 *)(temp_7_6)+(0x2DF)))) {
                var_4_16 = 0;
            } else if ((*(s8 *)((u8 *)(((s32)(temp_7_6) + temp_4_11))+(0x2DA))) == 9) {
                var_4_16 = 1;
            } else {
                var_8_16 = (s64) ((var_8_16 + 1) << 0x30) >> 0x30;
                goto loop_347;
            }
            if (var_4_16 == 1) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    return;
                }
            }
        }
        break;
    case 0xB7:                                      /* switch 1 */
        temp_2_14 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0x2D8))), 1, 0x28, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_14;
        temp_4_13 = (s64) ((s64) temp_2_14 << 0x30) >> 0x30;
        if (temp_4_13 == 0x14) {
            func_0011cb70(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C))));
            func_0011ce30(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
            func_0045af60(1, 3, 3, 2);
            return;
        }
        if (temp_4_13 >= 0x28) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
            var_9_7 = 0;
loop_367:
            temp_4_14 = (s64) (var_9_7 << 0x30) >> 0x30;
            if (temp_4_14 < 6) {
                temp_8_3 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_10_7 = 0;
loop_360:
                temp_4_16 = (s64) (var_10_7 << 0x30) >> 0x30;
                if (temp_4_16 >= (*(s8 *)((u8 *)(temp_8_3)+(0x2DF)))) {
                    var_3_9 = 0;
                } else if (((s64) ((temp_4_14 + 1) << 0x38) >> 0x38) == (*(s8 *)((u8 *)(((s32)(temp_8_3) + temp_4_16))+(0x2DA)))) {
                    var_3_9 = 1;
                } else {
                    var_10_7 = (s64) ((var_10_7 + 1) << 0x30) >> 0x30;
                    goto loop_360;
                }
                if (var_3_9 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xACU;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                    }
                    return;
                }
                var_9_7 = (s64) ((var_9_7 + 1) << 0x30) >> 0x30;
                goto loop_367;
            } else {
                temp_7_7 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_8_17 = 0;
loop_372:
                temp_4_15 = (s64) (var_8_17 << 0x30) >> 0x30;
                if (temp_4_15 >= (*(s8 *)((u8 *)(temp_7_7)+(0x2DF)))) {
                    var_4_17 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_7_7) + temp_4_15))+(0x2DA))) == 9) {
                    var_4_17 = 1;
                } else {
                    var_8_17 = (s64) ((var_8_17 + 1) << 0x30) >> 0x30;
                    goto loop_372;
                }
                if (var_4_17 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                    (*(u8 *)((u8 *)(temp_16)+(0x22))) = 0xB8U;
                    if ((*(s8 *)((u8 *)(temp_16)+(0x21))) == 0) {
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBDU;
                        return;
                    }
                }
            }
        }
        break;
    case 0xAC:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_16)+(0x20))) = 0;
        var_5_10 = 0;
loop_382:
        temp_3_11 = (s64) (var_5_10 << 0x30) >> 0x30;
        if (temp_3_11 < (*(s8 *)((u8 *)(temp_16)+(0x2DF)))) {
            temp_3_12 = (s8)((s8)((s8)((*(s8 *)((u8 *)(((s32)(temp_16) + temp_3_11))+(0x2DA))))));
            if ((temp_3_12 > 0) && (temp_3_12 < 7)) {
                (*(s8 *)((u8 *)(temp_16)+(0x1F))) = temp_3_12;
                (*(s8 *)((u8 *)((((s64) (var_5_10 << 0x30) >> 0x30) + (s32)(temp_16)))+(0x2DA))) = 0;
            } else {
                var_5_10 = (s64) ((var_5_10 + 1) << 0x30) >> 0x30;
                goto loop_382;
            }
        }
        (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16)((s16)(func_003040d0(arg0, (*(u8 *)((u8 *)(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))))+(4))), (*(s8 *)((u8 *)(temp_16)+(0x1F))))));
        temp_18_2 = (u16)((u16)((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
        if ((s32)((s32)(func_0010ce10((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), temp_18_2))) == (s32)((s32)(-1))) {
            (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
            sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
            sprintf(&spB0, &iGpffffa8a4, func_00243840(temp_18_2));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
        } else {
            temp_18_3 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_16)+(0x1F))))));
            temp_4_17 = (s64)((s64)((s64) (func_002b2cb0((s16) (*(s8 *)((u8 *)(temp_16)+(0x1E))), 1, 9, 0, 1) << 0x38) >> 0x38));
            temp_2_15 = (s64) ((s64) temp_18_3 << 0x38) >> 0x38;
            switch (temp_2_15) {                    /* switch 2 */
            case 1:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_00749040 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            case 2:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_00749060 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            case 3:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_00749080 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            case 4:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_007490A0 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            case 5:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_007490C0 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            case 6:                                 /* switch 2 */
                var_2 = (*(s16 *)((u8 *)D_007490E0 + (((s64) (temp_4_17 << 0x38) >> 0x38) * 2)));
                break;
            default:                                /* switch 2 */
                var_2 = -1;
                break;
            }
            temp_18_4 = var_2 & 0xFFFF;
            if ((s32)((s32)(func_0010ce10((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), temp_18_4))) == (s32)((s32)(-1))) {
                (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
                sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
                func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
                sprintf(&spB0, &iGpffffa8a4, func_00243840(temp_18_4));
                func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
                (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16) temp_18_4;
            } else {
                temp_18_5 = (s8)((s8)((s8)((*(s8 *)((u8 *)(temp_16)+(0x1F))))));
                temp_4_18 = (s64)((s64)((s64) (func_002b2d00((*(s8 *)((u8 *)(temp_16)+(0x1E))), 1, 0, 9, 1) << 0x38) >> 0x38));
                temp_2_16 = (s64) ((s64) temp_18_5 << 0x38) >> 0x38;
                switch (temp_2_16) {                /* switch 3 */
                case 1:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_00749040 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                case 2:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_00749060 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                case 3:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_00749080 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                case 4:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_007490A0 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                case 5:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_007490C0 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                case 6:                                 /* switch 3 */
                    var_2_2 = (*(s16 *)((u8 *)D_007490E0 + (((s64) (temp_4_18 << 0x38) >> 0x38) * 2)));
                    break;
                default:                                /* switch 3 */
                    var_2_2 = -1;
                    break;
                }
                temp_18_6 = var_2_2 & 0xFFFF;
                if ((s32)((s32)(func_0010ce10((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), temp_18_6))) == (s32)((s32)(-1))) {
                    (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
                    sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
                    func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
                    sprintf(&spB0, &iGpffffa8a4, func_00243840(temp_18_6));
                    func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
                    (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16) temp_18_6;
                } else {
                    (*(s8 *)((u8 *)(temp_16)+(0x20))) = 1;
                    (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
                    sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
                    func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
                    sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
                    func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
                }
            }
        }
        func_0011cdd0(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB0U;
        return;
    case 0xAD:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        if ((*(s8 *)((u8 *)(temp_16)+(0x20))) == 1) {
            var_20 = 0;
loop_417:
            temp_4_19 = (s64) (var_20 << 0x30) >> 0x30;
            if (temp_4_19 < 8) {
                temp_19 = temp_4_19 * 2;
                if ((*(u16 *)((u8 *)((func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + temp_19))+(0xC))) != 0) {
                    temp_18_7 = (s16)((s16)((s16)((*(s16 *)((u8 *)(temp_16)+(0x1C))))));
                    if (temp_18_7 == (*(u16 *)((u8 *)((func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + temp_19))+(0xC)))) {
                        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
                        sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
                        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
                        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x52);
                        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xAEU;
                    }
                }
                var_20 = (s64) ((var_20 + 1) << 0x30) >> 0x30;
                goto loop_417;
            }
            temp_4_20 = (u8)((u8)((u8)((*(u8 *)((u8 *)(temp_16)+(1))))));
            if (temp_4_20 != 0xAE) {
                (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
                sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
                func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
                sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
                func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
                func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x53);
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xAEU;
                return;
            }
        } else {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB1U;
            (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0;
            if ((s32)((s32)(func_0010ceb0(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA))))))) >= (s32)((s32)(8))) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xAFU;
                temp_17_9 = (s32)((s32)((s32)(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))))));
                (*(s32 *)((u8 *)(temp_16)+(0x2A8))) = (s32)((s32)(func_0011fbc0(arg0, temp_17_9, func_00331660(), &D_00641AD0)));
                return;
            }
        }
        break;
    case 0xAF:                                      /* switch 1 */
        if ((s32)((s32)(func_0011fcf0((*(s32 *)((u8 *)(temp_16)+(0x2A8))), 0xAF))) == (s32)((s32)(1))) {
            func_00452080((*(s32 *)((u8 *)(temp_16)+(0x2A8))));
            (*(s32 *)((u8 *)(temp_16)+(0x2A8))) = 0;
            func_0011ce30(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
            var_6_4 = 0;
loop_428:
            temp_4_21 = (s64) (var_6_4 << 0x30) >> 0x30;
            if (temp_4_21 >= (*(s8 *)((u8 *)(temp_16)+(0x2DF)))) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
                temp_7_8 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_8_18 = 0;
loop_433:
                temp_4_22 = (s64) (var_8_18 << 0x30) >> 0x30;
                if (temp_4_22 >= (*(s8 *)((u8 *)(temp_7_8)+(0x2DF)))) {
                    var_4_18 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_7_8) + temp_4_22))+(0x2DA))) == 9) {
                    var_4_18 = 1;
                } else {
                    var_8_18 = (s64) ((var_8_18 + 1) << 0x30) >> 0x30;
                    goto loop_433;
                }
                if (var_4_18 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                    return;
                }
            } else {
                temp_3_13 = (s8)((s8)((s8)((*(s8 *)((u8 *)(((s32)(temp_16) + temp_4_21))+(0x2DA))))));
                if ((temp_3_13 > 0) && (temp_3_13 < 7)) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                    return;
                }
                var_6_4 = (s64) ((var_6_4 + 1) << 0x30) >> 0x30;
                goto loop_428;
            }
        }
        break;
    case 0xB0:                                      /* switch 1 */
        temp_2_17 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0xE))), 1, 0x28, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0xE))) = temp_2_17;
        if (((s64) ((s64) temp_2_17 << 0x30) >> 0x30) >= 0x28) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xADU;
            func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x51);
            return;
        }
        break;
    case 0xB1:                                      /* switch 1 */
        temp_2_18 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0x2D8))), 1, 0x28, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_18;
        if (((s64) ((s64) temp_2_18 << 0x30) >> 0x30) == 0xF) {
            func_0011cb70(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C))));
            func_0045af60(1, 3, 3, 2);
        }
        if ((*(s16 *)((u8 *)(temp_16)+(0x2D8))) >= 0x28) {
            func_0011ce30(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))));
            var_6_5 = 0;
loop_447:
            temp_4_23 = (s64) (var_6_5 << 0x30) >> 0x30;
            if (temp_4_23 >= (*(s8 *)((u8 *)(temp_16)+(0x2DF)))) {
                (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
                temp_7_9 = (u8 *)((*(u8 **)((u8 *)(arg0)+(0x38))));
                var_8_19 = 0;
loop_452:
                temp_4_24 = (s64) (var_8_19 << 0x30) >> 0x30;
                if (temp_4_24 >= (*(s8 *)((u8 *)(temp_7_9)+(0x2DF)))) {
                    var_4_19 = 0;
                } else if ((*(s8 *)((u8 *)(((s32)(temp_7_9) + temp_4_24))+(0x2DA))) == 9) {
                    var_4_19 = 1;
                } else {
                    var_8_19 = (s64) ((var_8_19 + 1) << 0x30) >> 0x30;
                    goto loop_452;
                }
                if (var_4_19 == 1) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB8U;
                    return;
                }
            } else {
                temp_3_14 = (s8)((s8)((s8)((*(s8 *)((u8 *)(((s32)(temp_16) + temp_4_23))+(0x2DA))))));
                if ((temp_3_14 > 0) && (temp_3_14 < 7)) {
                    (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
                    return;
                }
                var_6_5 = (s64) ((var_6_5 + 1) << 0x30) >> 0x30;
                goto loop_447;
            }
        }
        break;
    case 0xAE:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        var_6_6 = 0;
loop_463:
        temp_4_25 = (s64) (var_6_6 << 0x30) >> 0x30;
        if (temp_4_25 >= (*(s8 *)((u8 *)(temp_16)+(0x2DF)))) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
            return;
        }
        temp_3_15 = (s8)((s8)((s8)((*(s8 *)((u8 *)(((s32)(temp_16) + temp_4_25))+(0x2DA))))));
        if ((temp_3_15 > 0) && (temp_3_15 < 7)) {
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xACU;
            return;
        }
        var_6_6 = (s64) ((var_6_6 + 1) << 0x30) >> 0x30;
        goto loop_463;
    case 0xB8:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        do {
            temp_17_10 = (u32)((u32)((u32)(func_0010ceb0(func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA))))))));
            (*(s8 *)((u8 *)(temp_16)+(0x27))) = (s8)((s8)((s8) (RpRandom() % temp_17_10)));
        } while ((s32)((s32)(((s64) (func_00313690((*(s16 *)((u8 *)((func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + ((*(s8 *)((u8 *)(temp_16)+(0x27))) * 2)))+(0xC)))) << 0x30) >> 0x30))) == (s32)((s32)(0)));
        sprintf(&spB0, &iGpffffa8a4, func_00243840((*(u16 *)((u8 *)((func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + ((*(s8 *)((u8 *)(temp_16)+(0x27))) * 2)))+(0xC)))));
        (*(s16 *)((u8 *)(temp_16)+(0x1C))) = (s16)((s16)((s16) (*(u16 *)((u8 *)((func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))) + ((*(s8 *)((u8 *)(temp_16)+(0x27))) * 2)))+(0xC)))));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x56);
        func_002bafc0((*(s8 *)((u8 *)(temp_16)+(0xD))), 0);
        func_002bb0a0((*(s8 *)((u8 *)(temp_16)+(0xD))), 0);
        func_002bbf60();
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xB9U;
        return;
    case 0xB9:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        if ((s32)((s32)(func_002bb1c0((*(s8 *)((u8 *)(temp_16)+(0xD)))))) == (s32)((s32)(0))) {
            func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
            func_002e4960(sp60, (*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA))));
            (*(u16 *)((u8 *)(temp_16)+(0x24))) = (u16)((u16)(func_00304410(sp60, (*(s16 *)((u8 *)(temp_16)+(0x1C))))));
            (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0;
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBAU;
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        return;
    case 0xBA:                                      /* switch 1 */
        temp_2_19 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0x2D8))), 1, 0x28, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_19;
        if (((s64) ((s64) temp_2_19 << 0x30) >> 0x30) == 0x14) {
            func_0011cc00(func_003147d0((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))), (u16) (*(s16 *)((u8 *)(temp_16)+(0x1C))), (*(u16 *)((u8 *)(temp_16)+(0x24))));
            func_0010cd70((u8 *)func_002e48a0((*(s8 *)((u8 *)(temp_16)+(0x2F9))), (*(s8 *)((u8 *)(temp_16)+(0x2FA)))), (*(s16 *)((u8 *)(temp_16)+(0x1C))), (*(u16 *)((u8 *)(temp_16)+(0x24))));
            func_0045af60(1, 3, 3, 2);
        }
        if ((*(s16 *)((u8 *)(temp_16)+(0x2D8))) >= 0x28) {
            (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
            sprintf(&spB0, &iGpffffa8a4, func_00243840((*(u16 *)((u8 *)(temp_16)+(0x24)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 1, &spB0);
            sprintf(&spB0, &iGpffffa8a4, func_00243840((u16) (*(s16 *)((u8 *)(temp_16)+(0x1C)))));
            func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
            func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x57);
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBBU;
            return;
        }
        break;
    case 0xBB:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBFU;
        return;
    case 0xBC:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x47);
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBEU;
        return;
    case 0xBD:                                      /* switch 1 */
        (*(s8 *)((u8 *)(temp_16)+(0xD))) = (s8)((s8)(func_002bab80((void *)func_00331660())));
        sprintf(&spB0, &iGpffffa8a4, ((s32)iGpffffb440) + ((temp_17 & 0xFFFF) * 0x11));
        func_002bbd80((*(s8 *)((u8 *)(temp_16)+(0xD))), 0, &spB0);
        func_002badc0((s64) (*(s8 *)((u8 *)(temp_16)+(0xD))), 0x48);
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xBEU;
        return;
    case 0xBE:                                      /* switch 1 */
        if ((s32)((s32)(func_002bb680((*(s8 *)((u8 *)(temp_16)+(0xD)))))) != (s32)((s32)(0))) {
            func_002bbcf0((*(s8 *)((u8 *)(temp_16)+(0xD))));
            return;
        }
        func_002bb550((*(s8 *)((u8 *)(temp_16)+(0xD))));
        (*(s8 *)((u8 *)(temp_16)+(0x21))) = 1;
        (*(u8 *)((u8 *)(temp_16)+(1))) = (u8)((u8)((u8) (*(u8 *)((u8 *)(temp_16)+(0x22)))));
        return;
    case 0xBF:                                      /* switch 1 */
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = 0;
        (*(u8 *)((u8 *)(temp_16)+(1))) = 0xC0U;
        /* fallthrough */
    case 0xC0:                                      /* switch 1 */
        temp_2_20 = (s16)((s16)((s16)(func_002b2cb0((*(s16 *)((u8 *)(temp_16)+(0x2D8))), 1, 0x3C, 0, 1))));
        (*(s16 *)((u8 *)(temp_16)+(0x2D8))) = temp_2_20;
        if ((((s64) ((s64) temp_2_20 << 0x30) >> 0x30) >= 0x3C) && ((s32)((s32)(((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))) << 0x38) >> 0x38))) != (s32)((s32)(0xE)))) {
            func_00314670((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 0xB);
            func_002b2970(&spD0.bits, 0.0f, 0.0f);
            func_002b6c30(0x1E8, spD0.position, 6.0f, 0xAA);
            func_002b68d0(0x1E8, 0, 0);
            func_002b6a70(0x1E8, 0xFF, 0, 0, 0x32, 0xA);
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xC1U;
            return;
        }
        break;
    case 0xC1:                                      /* switch 1 */
        if ((s32)((s32)(((s64) (func_00314660((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148)))) << 0x38) >> 0x38))) == (s32)((s32)(0xE))) {
            func_00314400((u8 *)(*(s32 *)((u8 *)(temp_16)+(0x148))), 1);
            (*(s8 *)((u8 *)(temp_16)+(0))) = 0xE;
            (*(u8 *)((u8 *)(temp_16)+(1))) = 0xD2U;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030c3c0);
#endif

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
    FclPackedPosition w0;
    s64 w1;
    s64 w2;
    FclPackedPosition w3;
    s64 w4;
    s64 w5;
    FclPackedPosition w6;
    FclPackedPosition w7;
    FclPackedPosition w8;
    FclPackedPosition w9;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclVec2f *base;

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
            if (*func_0034a630(*(s32 *)(p + 0x254)) != 0) {
                *func_0034a630(*(s32 *)(p + 0x254)) = 4;
            }
            if (func_00105f50((u16)cls) > 0) {
                if (func_00452490(*(s32 *)(p + 0x308)) != 0) {
                    func_00452080(*(s32 *)(p + 0x308));
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
            mats[5] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 5) + 1);
        case 5:
            mats[4] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 4) + 1);
        case 4:
            mats[0] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 0) + 1);
            mats[1] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 1) + 1);
            mats[2] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 2) + 1);
            mats[3] = *(u16 *)(func_002e48a0(*(s16 *)(p + 0x11E) + 1, 3) + 1);
            break;
        case 7:
            for (i = 0; i < 0xC; i++) {
                mats[i] = *(u16 *)(func_002e48a0(0, i) + 1);
            }
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
            func_002b2970((u8 *)&w0.bits, -78.0f, -82.0f);
            func_002b6c30(0x80, w0.position, 220.0f, 0x3F);
            c0 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x80) + 0x85) = c0;
            func_002b6b40(0x80, 0, 0x5A0, 0, 0.0f, -360.0f);
            func_002b68d0(0x80, 6, 0);
            *(func_002b6150(0x80) + 0xDB) = 1;
            func_002b2970((u8 *)&w1, 2.0f, -2.0f);
            func_002b2970((u8 *)&w2, -78.0f, -82.0f);
            func_002b69f0(0x80, *(FclVec2f *)&w1, *(FclVec2f *)&w2, 1, 0xA, 0);
            func_002b6a70(0x80, 0, 0xFF, 2, 0xA, 0);
            func_002b2970((u8 *)&w3.bits, 540.0f, (f32)347);
            func_002b6c30(0x20C, w3.position, 220.0f, 0x3F);
            c1 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x20C) + 0x85) = c1;
            func_002b6b40(0x20C, 0, 0x5A0, 0, 0.0f, -360.0f);
            func_002b68d0(0x20C, 6, 0);
            *(func_002b6150(0x20C) + 0xDB) = 1;
            func_002b2970((u8 *)&w4, 460.0f, (f32)267);
            func_002b2970((u8 *)&w5, 540.0f, (f32)347);
            func_002b69f0(0x20C, *(FclVec2f *)&w4, *(FclVec2f *)&w5, 1, 0xA, 0);
            func_002b6a70(0x20C, 0, 0xFF, 2, 0xA, 0);
            func_002b2970((u8 *)&w6.bits, -190.0f, 200.0f);
            func_002b6c30(0x81, w6.position, 215.0f, 0x56);
            c2 = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
            *(FclDrawColor *)(func_002b6150(0x81) + 0x85) = c2;
            *(f32 *)(func_002b6150(0x81) + 0xD0) = 90.0f;
            base = (FclVec2f *)D_00640C50;
            func_002b2970((u8 *)&w7.bits, base->x, base->y);
            func_002b6c30(0x84, w7.position, 217.0f, 0x40);
            base = (FclVec2f *)D_00640C58;
            func_002b2970((u8 *)&w8.bits, base->x, base->y);
            func_002b6c30(0x85, w8.position, 218.0f, 0x40);
            func_00315600(arg0, 0);
            func_00316e80((s32)arg0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
            base = (FclVec2f *)D_00641660;
            func_002b2970((u8 *)&w9.bits, base->x, base->y);
            func_002b6c30(0x1C6, w9.position, 242.0f, 0x3D);
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
