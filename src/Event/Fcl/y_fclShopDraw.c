#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "fr_font_internal.h"

typedef struct { f32 x, y; } Vec2f;
typedef struct { u8 r, g, b, a; } RGBA;
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline f32 shopAdd(f32 left, f32 right) { return left + right; }
typedef struct {
    u8 pad0a[2];
    s16 field_2;
    s16 field_4;
    f32 field_8;
    u8 pad1a[5];
    s8 field_11;
    s16 field_12;
    u8 pad1b[0x18];
    f32 field_2C;
    f32 field_30;
    u8 pad2[0x2E];
    u8 field_62;
    u8 pad3[0x16];
    u8 field_79;
    u8 field_7A;
    u8 field_7B;
    u8 pad4[0x18];
    f32 field_94;
    u8 pad5[0x8];
    f32 field_A0;
    u8 pad6[0x20];
    f32 field_C4;
    u8 pad7[0x7];
    u8 field_CF;
    u8 pad8[0x24];
    u32 field_F4;
    s16 field_F8;
    u8 pad9[0x2];
    u32 field_FC;
    s16 field_100;
    s16 field_102;
    u8 padA1a1a[0xB20];
    s8 field_C24;
    u8 padA1a1b[0x1F];
    void *field_C44;
    void *field_C48;
    u8 padA1a2a[0x14];
    void *field_C60;
    void *field_C64;
    u8 padA1a2b[8];
    void *field_C70;
    void *field_C74;
    void *field_C78;
    u8 padA1a2c[4];
    void *field_C80;
    void *field_C84;
    u8 padA1a2d[4];
    void *field_C8C;
    void *field_C90;
    void *field_C94;
    void *field_C98;
    void *field_C9C;
    void *field_CA0;
    void *field_CA4;
    void *field_CA8;
    void *field_CAC;
    void *field_CB0;
    void *field_CB4;
    void *field_CB8;
    void *field_CBC;
    void *field_CC0;
    void *field_CC4;
    void *field_CC8;
    u8 padA2b1[4];
    void *field_CD0;
    void *field_CD4;
    void *field_CD8;
    void *field_CDC;
    void *field_CE0;
    void *field_CE4;
    void *field_CE8;
    u8 padA2b3a[0x80];
    void *field_D6C;
    void *field_D70;
    u8 padA2b3b[8];
    void *field_D7C;
    u8 padA2b3c[0xC];
    void *field_D8C;
    void *field_D90;
    void *field_D94;
    u8 padB1[0x24];
    void *field_DBC[3];
    void *field_DC8;
    u8 padB2a1[4];
    void *field_DD0;
    u8 padB2a2[8];
    void *field_DDC;
    void *field_DE0;
    void *field_DE4;
    u8 padB2b[0x44];
    void *field_E2C;
    void *field_E30;
    u8 padC1[4];
    void *field_E38;
    u8 padC2a[0x14];
    void *field_E50;
    void *field_E54;
    void *field_E58;
    void *field_E5C;
    void *field_E60;
    u8 padD1a1[0x1C];
    void *field_E80;
    void *field_E84;
    u8 padD1a2a[4];
    u8 padD1a2b[8];
    void *field_E94;
    void *field_E98;
    void *field_E9C;
    void *field_EA0;
    void *field_EA4;
    void *field_EA8;
    void *field_EAC;
    void *field_EB0;
    void *field_EB4;
    void *field_EB8;
    void *field_EBC;
    void *field_EC0;
    void *field_EC4;
    void *field_EC8;
    u8 padD1b[8];
    void *field_ED4;
    void *field_ED8;
    void *field_EDC;
    void *field_EE0;
    u8 padD2a[8];
    void *field_EEC;
    void *field_EF0;
    void *field_EF4;
    void *field_EF8;
    void *field_EFC;
    void *field_F00;
    void *field_F04;
    u8 padD2b2[0x10];
    void *field_F18[3];
    u8 padD2b[4];
    void *field_F28;
} ShopWork;

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00795E60[];
extern u8 D_00793E80[];
extern char iGpffffa884[2];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];
extern u8 D_0063FB70[];
extern u8 D_0063F560[];
extern u8 D_0063F9F0[];
extern f32 fGpffff8504;
extern f32 D_0063F650[];
extern f32 D_0063F658[];
extern f32 D_0063F5B0[];
extern f32 D_0063F5D0[];
extern f32 D_0063F5D8[];
extern f32 D_0063F5E0[];
extern f32 D_0063F5F0[];
extern f32 D_0063F5F8[];
extern f32 D_0063F880[];
extern f32 D_0063F890[];
extern s8 D_00748908[];
extern u8 D_00795E30[];
extern u8 D_00794EA0[];
extern u8 D_00794ED0[];
extern u8 D_0063FB50[];

void func_002be530(void);
void func_002be3c0(void);
s32 func_0010d6d0(s16);
void func_00105780(s32);
s32 func_00106b20(s16);
void func_0044ea90(const void *, u32);
s32 func_00451fc0(s32, const void *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
s32 func_002e0100(void *);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
/* measured: the second parameter is u8 - a u8 lvalue passed to a u8 parameter is a
   plain load and materialises in slot order (li $a0 before lbu $a1); passed to an
   s32 parameter it counts as a conversion and is hoisted ahead of the constant. */
s32 func_002b2a30(u8, u8, u8, u8);
s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s8 func_002e0570(void *, s32);
void *func_002e04e0(void *);
void func_002e04f0(void *, s32, s32);
void func_002e0620(void *, u64, u64, s32, s32, s16);
void func_002e0940(void *, f32, f32, s32, s32, s32);
void func_002b2970(void *, f32, f32);
void *func_002b5c90(void *, u64);
void *func_002e2590(void *, s32, s32, s32, s32);
char *func_00442830(char *, const char *);
void *func_0046d200(void *, s32);
f32 func_0046b260(void *);
f32 func_0046b2f0(void *);
void func_0046d280(void *);
void func_0046b0d0(void *);
void func_00454bd0(void *);
void func_002e29a0(void);
s8 func_002bab80(void *);
void func_002bbd80(s32, s32, void *);
void func_002badc0(s32, s16);
void func_002bafc0(s32, s32);
void func_002bb0a0(s32, s32);
void func_002bbf60(void);

s32 func_002dfec0(void *, s32, void *, s8);
s32 func_002dff90(void *, s32, void *, void *, s8);
u32 func_003b7060(void);
void func_0043f9c8(void *, s32, s32);
/* measured: floats first - retail materialises $f12-$f14 before $a0..$t1. */
void func_0025ec90(f32, f32, f32, s32, u8, s32, void *, s32, void *);
void func_002e0700(void *, s32, f32, f32, s32, s32, s32);
void func_002e09e0(void *, s32, f32);
void func_002e0690(void *, f32, f32, s32, s32, s32);
void func_002e0660(void *, u8, u8, u8, s16, s64);
s32 func_002e26f0(void *);
void func_002e06d0(void *, f32, f32, f32, f32, s32, s32, s32);
void func_002e0b20(s32, Vec2f, f32, s32, u8, s32, u8 *);
void *func_001067f0(s32);
s16 func_00106cd0(s16, s16);
u32 func_00106880(s16);
u16 func_001068b0(s16);
u16 func_001068e0(s16);
u16 func_00106940(s16);
u16 func_00106970(s16);
s32 func_002b3170(s32);
void func_002b2a60(void *, s32, s32, s32, s32);
void func_002cacd0(u64, f32, RGBA, s32, s16, u32, s32, s32, s32, s32, s32);
void *func_0046a770(void *);
s16 func_002e2830(void *, s32);
s32 func_00106600(s16 id);
u16 func_001069d0(s64);
void func_002bc7f0(s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_002e0ca0(s32, Vec2f, f32, s32, u8, s32, u8 *);
void func_002e0a60(void *, s32, f32);
void func_002e0080(void *, s8, Vec2f, void *);
void func_002d8200(void *, s8);
void func_002d83c0(void *);
s32 func_002e2670(void);
s16 func_002e26a0(void);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
s16 func_002b2d00(s32, s32, s32, s32, s32);
s16 func_002b2d50(s32, s32, s32, s32, s32);
void func_002b2e70(s32, s32, s32, s32, void *, void *);
void func_002b2f90(s32, s32, s32, s32, void *, void *);
void func_002e2a10(s32, s32, s32, s32);
void func_002e0970(void *, u32, u32, s32, s32, s32);
void func_002e09b0(void *, s32, f32);
void func_002e0be0(s32, Vec2f, f32, s32, u8, s32, u8 *);
u32 func_002e7a60(void);
u32 func_00106a90(s16);
s32 func_00110830(s32);
s8 func_002e29d0(void);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
void func_002e2700(void *);
extern f32 D_0063F9C0[];
extern f32 D_0063F9C8[];
extern f32 D_0063F9D0[];
extern f32 D_0063F888[];
extern f32 D_0063F5A0[];
extern f32 D_0063F5A8[];
extern f32 D_0063F5B8[];
extern f32 D_0063F778[];
extern f32 D_0063F780[];
extern f32 D_0063F788[];
extern f32 D_0063F790[];
extern f32 D_0063F798[];
extern f32 D_0063F7A0[];
extern f32 D_0063F7B0[];
extern f32 D_0063F7B8[];
extern f32 D_0063F8C0[];
extern f32 D_0063FA40;
extern s16 D_0063FA44;
extern s16 D_0063FA46;
extern u8 D_0063FA48[];
extern u8 D_0063FA50[];
extern u8 D_0063FA58[];
extern u8 D_0063FA60[];
extern u8 D_0063FA68[];
extern u16 D_008C024E;
extern u16 D_008C0276;
extern u16 D_008C027A;
extern f32 fGpffff7ad4;

/* measured: rule 1 is NOT VU0 here - retail ldr 0x2C/ldl 0x33 (12 sites, all
   on the func_002e04e0 result, e.g. 0x002C134C) is *(u64 *)(p + 0x2C): the
   b210 probe of that exact read emits ldr 0x2C/ldl 0x33 (and +0x38 emits ld),
   and func_002dd230 in this file already matches with the same idiom. Rule 2
   FMA sites (adda.s/madd.s, msub.s pairs at 0x002D.../0x002E...) are acc +
   a*b with preserved fs/ft order. Blocked by scale, not the rule: 0xC240
   bytes, 1525 jals, m2c draft 3700 lines with 200+ M2C_UNK slots and 20+
   M2C_ERROR sites across 3 shapes (saved-$s0 ldr base, temp_f20 madd, msub
   pairs); sibling func_002cdf80 with the same rules fully adapted measured
   nd 3325. Function-scale reconstruction floor. */
// FUN_002BE530
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002be530);

// FUN_002CA770
void func_002ca770(void *arg0) {
    s16 i;
    void *work = *(void **)((u8 *)arg0 + 0x38);

    for (i = 0; i < *(s8 *)((u8 *)work + 9); i++) {
        func_00105780(*(s8 *)((u8 *)work + i + 0xF73));
    }
    if (*(void **)((u8 *)work + 0xF28)) {
        func_0046b0d0(*(void **)((u8 *)work + 0xF28));
        *(u32 *)((s32)work + 0xF28) = 0;
    }
    if (*(void **)((u8 *)work + 0xF2C)) {
        func_00454bd0(*(void **)((u8 *)work + 0xF2C));
    }
    func_002e29a0();
    jtbl_008873EC[0](*(void **)((s32)arg0 + 0x38));
}

// FUN_002CA830
s32 func_002ca830(s32 arg0) {
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&D_0063FAC0, 0xC47);
    temp_2 = D_008873F4[0](1, 0x1174, 0x40000);
    temp_17 = func_00451fc0(arg0, (char *)&D_0063FB30, 0xF, 0, 0, (void (*)(u8 *))func_002be530, (void (*)(u8 *))func_002ca770, temp_2);
    *(s8 *)(temp_2 + 0) = 9;
    func_002b2970(&sp48, 240.0f, 20.0f);
    *(void **)(temp_2 + 0xC28) = func_002b5c90((void *)temp_17, sp48);
    *(s8 *)(temp_2 + 0xC24) = 0;
    func_002b2970(&sp40, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC2C) = func_002b5c90((void *)temp_17, sp40);
    func_002b2970(&sp38, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC30) = func_002b5c90((void *)temp_17, sp38);
    func_002b2970(&sp30, 50.0f, 30.0f);
    *(void **)(temp_2 + 0xC34) = func_002b5c90((void *)temp_17, sp30);
    *(u32 *)(temp_2 + 0xF28) = 0;
    *(s8 *)(temp_2 + 0xF30) = 0;
    *(void **)(temp_2 + 0xF18) = func_002e2590((void *)temp_17, 0x40000, 0, 4, 0);
    *(void **)(temp_2 + 0xF1C) = func_002e2590((void *)temp_17, 0xFFFF, 0x1FE0, 1, 0);
    *(void **)(temp_2 + 0xF20) = func_002e2590((void *)temp_17, 0x10000, 0, 1, 0);
    return temp_17;
}

// FUN_002CAA00
void func_002caa00(void *arg0, s8 arg1) {
    *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38)) = arg1;
}

/* Measured: 696/704 bytes, fourteen resolved relocations, eight zero
   alignment bytes. Separate glyph acquisition/release scopes preserve
   the saved-register allocation and callback order. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
// FUN_002CAA10
void func_002caa10(Vec2f position, f32 depth, RGBA color, u32 number_, s16 glyphBase, void *sprite_, s32 style)
{
    char text[16];
    f32 x;
    u32 number;
    s32 digitWidth;
    void *sprite;
    s32 count;
    s16 commaWidth;
    u8 *entry;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    f32 y;
    s32 comma;

    sprite = sprite_;
    number = number_;
    count = 0;
    x = position.x;
    {
        void *glyph;
        s32 measuredBase;
        measuredBase = (s16)glyphBase;
        glyph = func_0046d200(sprite, measuredBase);
        digitWidth = (s16)(s32)(func_0046b260(glyph) - 1.0f);
        func_0046d280(glyph);
        comma = measuredBase + 10;
    }
    {
        void *commaGlyph;
        commaGlyph = func_0046d200(sprite, comma);
        commaWidth = (s16)(s32)(func_0046b260(commaGlyph) - 1.0f);
        func_0046d280(commaGlyph);
    }
    func_00442830(text, iGpffffa884);
    entry = D_00793E80 + style * 0x30;
    base = (s16)glyphBase;
    a = color.a;
    b = color.b;
    g = color.g;
    y = position.y;
    do {
        func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, base + number % 10, sprite, 1, entry);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, comma, sprite, 1, entry);
                x -= (f32)digitWidth;
            } else {
                x -= (f32)digitWidth;
            }
        } else {
            x -= (f32)digitWidth;
        }
    } while (number != 0);
}
#pragma pop

/* measured: object 536B/window 544B, nd 0. Signature (u64, f32, RGBA, s32, s16, u32,
   s32, s32, s32, s32, s32): fparg0 second so it homes to $f22 right after $a0; RGBA
   by value so the colour bytes are lbu from the $a1 home slot; arg5/arg6 are s32
   (dsll32 in place). Stack layout is first-use order high-to-low: 16-byte memset
   target 0xD0, arg1 0xCC, arg0 0xC0, arg3 0xBE, arg7 0xB8. Byte colour locals
   agree with the packer and wrapper contracts. `arg4 = arg4_` before `count = 0`
   so $t0 homes last, comma local declared last for $s7, count s32 with (s8) cast,
   the three `x -= arg2` branches spelled out. */
// FUN_002CACD0
void func_002cacd0(u64 arg0, f32 fparg0, RGBA arg1, s32 arg2, s16 arg3, u32 arg4_, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9)
{
    u8 spD0[16];
    u32 arg4;
    s32 count;
    u8 *entry;
    f32 x;
    f32 y;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    s32 comma;

    arg4 = arg4_;
    count = 0;
    x = ((f32 *)&arg0)[0];
    func_0043f9c8(spD0, 0, 1);
    entry = D_00793E80 + arg9 * 0x30;
    base = (s16)arg5;
    a = arg1.a;
    b = arg1.b;
    g = arg1.g;
    y = ((f32 *)&arg0)[1];
    comma = (s16)arg6;
    do {
        func_0025ec90(x, y, fparg0, func_002b2a30(0xFF, ((u8 *)&arg1)[0], g, b), a, base + arg4 % 10, (void *)(u32)arg7, 1, entry);
        arg4 /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (arg4 != 0) {
                x -= (f32)arg3;
                func_0025ec90(x, y, fparg0, func_002b2a30(0xFF, ((u8 *)&arg1)[0], g, b), a, comma, (void *)(u32)arg8, 1, entry);
                x -= (f32)arg2;
            } else {
                x -= (f32)arg2;
            }
        } else {
            x -= (f32)arg2;
        }
    } while (arg4 != 0);
}
// FUN_002CAEF0
void func_002caef0(void *arg0) {
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    RGBA c0;
    RGBA c1;
    RGBA c2;
    RGBA c3;
    RGBA c4;
    u8 *work;
    u8 *t;
    Vec2f *base;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    base = (Vec2f *)D_0063F5B0;
    func_002e0a60(*(void **)(work + 0xEEC), 0x41, 109.0f);
    func_002b2970(&sp110, base->x, base->y);
    func_002b2970(&sp108, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEEC), sp110, sp108, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEEC)))[0x62] = 0xCC;
    func_002b2a60(&c0, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEEC));
    *(RGBA *)(t + 0x79) = c0;

    base = (Vec2f *)D_0063F5F0;
    func_002e0a60(*(void **)(work + 0xEF4), 0x41, 109.0f);
    func_002b2970(&sp100, base->x, base->y);
    func_002b2970(&spF8, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEF4), sp100, spF8, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEF4)))[0x62] = 0xCC;
    func_002b2a60(&c1, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF4));
    *(RGBA *)(t + 0x79) = c1;

    base = (Vec2f *)D_0063F5D0;
    func_002e0a60(*(void **)(work + 0xEF8), 0x41, 111.0f);
    func_002b2970(&spF0, base->x, base->y);
    func_002b2970(&spE8, base->x - 750.0f, base->y);
    func_002e0620(*(void **)(work + 0xEF8), spF0, spE8, 0, 4, 0);
    ((u8 *)func_002e04e0(*(void **)(work + 0xEF8)))[0x62] = 0xCC;
    func_002b2a60(&c2, 0, 0, 0, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF8));
    *(RGBA *)(t + 0x79) = c2;

    func_002e0a60(*(void **)(work + 0xEF0), 0x41, 109.0f);
    func_002b2970(&spE0, 86.0f, 242.0f);
    func_002b2970(&spD8, 786.0f, 242.0f);
    func_002e0620(*(void **)(work + 0xEF0), spE0, spD8, 0, 4, 0);
    func_002b2a60(&c3, 0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEF0));
    *(RGBA *)(t + 0x79) = c3;

    base = (Vec2f *)D_0063F5F8;
    func_002e0a60(*(void **)(work + 0xEFC), 0x41, 112.0f);
    func_002b2970(&spD0, base->x, base->y);
    func_002b2970(&spC8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xEFC), spD0, spC8, 0, 4, 0);
    func_002b2a60(&c4, 0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)func_002e04e0(*(void **)(work + 0xEFC));
    *(RGBA *)(t + 0x79) = c4;

    base = (Vec2f *)D_0063F5D8;
    func_002e0a60(*(void **)(work + 0xF00), 0x41, 113.0f);
    func_002b2970(&spC0, base->x, base->y);
    func_002b2970(&spB8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xF00), spC0, spB8, 0, 4, 0);

    base = (Vec2f *)D_0063F5E0;
    func_002e0a60(*(void **)(work + 0xF04), 0x41, 114.0f);
    func_002b2970(&spB0, base->x, base->y);
    func_002b2970(&spA8, base->x + 700.0f, base->y);
    func_002e0620(*(void **)(work + 0xF04), spB0, spA8, 0, 4, 0);

    base = (Vec2f *)D_0063F5B0;
    func_002b2970(&spA0, base->x + 660.0f, base->y);
    func_002b2970(&sp98, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC60), spA0, sp98, 0, 4, 6);
    base = (Vec2f *)D_0063F5F0;
    func_002b2970(&sp90, base->x + 660.0f, base->y);
    func_002b2970(&sp88, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC80), sp90, sp88, 0, 4, 6);
    base = (Vec2f *)D_0063F5D0;
    func_002b2970(&sp80, base->x + 660.0f, base->y);
    func_002b2970(&sp78, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC70), sp80, sp78, 0, 4, 6);
    func_002b2970(&sp70, -614.0f, 242.0f);
    func_002b2970(&sp68, 86.0f, 242.0f);
    func_002e0620(*(void **)(work + 0xE80), sp70, sp68, 0, 4, 6);
    base = (Vec2f *)D_0063F5F8;
    func_002b2970(&sp60, base->x - 700.0f, base->y);
    func_002b2970(&sp58, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC84), sp60, sp58, 0, 4, 6);
    base = (Vec2f *)D_0063F5D8;
    func_002b2970(&sp50, base->x - 700.0f, base->y);
    func_002b2970(&sp48, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC74), sp50, sp48, 0, 4, 6);
    base = (Vec2f *)D_0063F5E0;
    func_002b2970(&sp40, base->x - 700.0f, base->y);
    func_002b2970(&sp38, base->x, base->y);
    func_002e0620(*(void **)(work + 0xC78), sp40, sp38, 0, 4, 6);
}

// FUN_002CB6A0
s32 func_002cb6a0(void *arg0) {
    return *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38) + 0xF30) == 1;
}

/* measured: full m2c draft adapted and compiles (rule 2 at all 3 FMA sites:
   retail adda/madd at 0x1CB77C/0x1CCFA4/0x1CD038 = 142.0f + work[0xC] *
   (f32)(field_2-field_4) and 78.0f + 35.0f * (f32)work[8], fs/ft order
   preserved; 0-arg func_002e2670 (draft's 2-arg forms were phantom);
   D_0063FA40/44/46 as real s16 symbols; 75680/0080 shapes fixed); nd 2429.
   Residual: D_0063F778/F8C0/F5B8-style base hoists, 26f0/2670 result width
   (retail uses raw 32-bit, s16 prototypes over-extend), and the usual
   arg-order scrambling. Hoist + width floor. */
/* measured: recipe B re-test 2026-08-03: full draft re-adapted with the
   the Vec2f / u8 base locals (b re-assigned per group, fa for the D_0063FA48/50/
   58/60/68 struct bases - both hoist into saved regs like retail), 3-arg
   func_002e0a60 shapes, 75680 prototype corrected to (s32 x6, void*, s32,
   f32 x3), signed (s16) reads of field_4 (kills the lw/bltz dup), > 5 slti
   form, float literals (140.0f etc. not 0x430A0000): nd 2429 -> 2229, FMA
   head and 0b20/0be0/0080/0970/09b0/0940 shapes byte-exact. Residual: frame
   0x260 vs 0x230 - mwcc b210 spills the loop's func_002e04e0/2a30 results
   (sw/lw 0xF0/0xE0) because the scheduler sinks t[0x62] past the 2a30 call
   (retail keeps lbu before it), 9 saved regs all used; plus the 15 color
   blocks' lbu-binding (see func_002caef0 note). Spill + scheduling floor. */
// FUN_002CB6C0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cb6c0);

// FUN_002CDF80
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cdf80);

/* measured: full m2c draft adapted and compiles (rule 2 at the FMA site
   0x1D2C58: 264.0f + work[0xC] * (f32)field_2 with madd fs/ft order
   preserved, f12 = D_0063F620[0] - 1.0f; four 75680 calls reordered to the
   (f32,f32,f32,...) prototype; 0080 Vec2f-by-value arg; func_002e2670 0-arg);
   nd 2637. Residual: D_0063F620/F660/F628/F630/F638/F640/F648/F668 base
   hoists per group, 26f0-width extension split, and 754f0/2a60 phantom-arg
   and arg-order scrambling. Hoist + width floor. */
// FUN_002D1590
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d1590);

/* measured: func_002d3ee0's full body was reconstructed (all call shapes,
   u64 slot pairs, switch, loops) and compiles; nd 462 with inline
   D_0063F5xx[0]/[1] globals. Retail caches each absolute global base in $s0
   across the func_002b2970/func_002e0620 groups; mwcc b210 rematerialises
   lui/addiu per load (D_00887300-family global-address-hoist floor, cf.
   func_002d7300 note). A Vec2f* base local makes mwcc cache the base but then
   work moves to $s2 and the frame grows 0x10 (all 19 u64 slots shift +0x10),
   nd ~470; tried both declaration orders and block-scoped i/t. Also: the
   func_002e0660 colour-byte args need a u8 prototype for lbu/0xFF codegen.
   Four-attempt budget exhausted. */
/* measured: recipe B re-test 2026-08-03: single Vec2f *b re-assigned per
   group (retail re-hoists its $s0 base per group) WORKS here: nd 462 -> 9.
   Also needed: field_4 retyped u32 -> s16 (retail reads it with lh; the u32
   read produced lw + bltz/dup on (f32)(field_4<<5) AND hoisted a work+4
   address into a 3rd saved reg, frame 0xD0 -> 0xE0); plain i++ s16 loops
   (explicit (s16)/(s32) casts double the dsll32/dsra32 pairs). Residual 9
   words: (1) loop index addu operand order (obj addu $v0,$v0,$s1 vs retail
   $s1,$v0; u32-arithmetic spelling does not change it); (2) func_002e0690
   arg materialization - retail f12, $4, mov.s f13, $5-$7; mwcc emits $5-$7
   then mov.s; (3) the sp58 f32-pair stores: mwcc always loads in reverse
   store order (lwc1 0x5C before 0x58, first-loaded binds $f1) - tried f32
   temps in all declaration/assignment orders. Scheduling floor. */
/* MATCHED 2026-09-18.  The last 4 words were `mov.s $f13, $f12` three slots
   late.  b210 emits call-argument setup in source order, so retail's copy
   landing between `lw $a0` and `move $a1` means func_002e0690's two floats
   are arguments 2 and 3, not 5 and 6; the EABI gives integer and float
   arguments separate register files, so the reordered prototype is the same
   ABI and leaves the MATCHed callee in src/promoted/code1_002e.c byte-exact.
   Everything else here was already exact: switch dispatch, Vec2f-by-value
   arguments, and the raw u64 stack slots. */
// FUN_002D3EE0
void func_002d3ee0(void *arg0) {
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    ShopWork *work;
    u8 *t;
    Vec2f *b;
    s16 i;
    s8 v7;
    work = *(ShopWork **)((u8 *)arg0 + 0x38);
    b = (Vec2f *)D_0063F5B0;
    func_002e09e0(work->field_C60, 0x41, 109.0f);
    func_002b2970(&spC8, b->x, b->y);
    func_002b2970(&spC0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C60, spC8, spC0, 0, 4, 0);
    b = (Vec2f *)D_0063F5F0;
    func_002e09e0(work->field_C80, 0x41, 109.0f);
    func_002b2970(&spB8, b->x, b->y);
    func_002b2970(&spB0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C80, spB8, spB0, 0, 4, 0);
    b = (Vec2f *)D_0063F5D0;
    func_002e09e0(work->field_C70, 0x41, 111.0f);
    func_002b2970(&spA8, b->x, b->y);
    func_002b2970(&spA0, b->x - 740.0f, b->y);
    func_002e0620(work->field_C70, spA8, spA0, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        func_002e04f0(*(void **)((u8 *)work + 0xE88 + i * 4), 0, 1);
    }
    func_002e04f0(work->field_EA4, 0, 1);
    func_002e04f0(work->field_EA8, 0, 1);
    v7 = *(s8 *)((u8 *)work + 7);
    switch (v7) {
    case 0:
        func_002e04f0(work->field_CA0, 0, 1);
        func_002e04f0(work->field_CA8, 0, 1);
        func_002e04f0(work->field_E98, 0, 1);
        func_002e04f0(work->field_EA0, 0, 1);
        break;
    case 1:
        func_002e04f0(work->field_C9C, 0, 1);
        func_002e04f0(work->field_CA4, 0, 1);
        func_002e04f0(work->field_E94, 0, 1);
        func_002e04f0(work->field_E9C, 0, 1);
        break;
    case 2:
        func_002e04f0(work->field_CB8, 0, 1);
        func_002e04f0(work->field_EAC, 0, 1);
        func_002e04f0(work->field_CBC, 0, 1);
        func_002e04f0(work->field_EB0, 0, 1);
        break;
    }
        func_002e09e0(work->field_E80, 0x41, 109.0f);
    func_002b2970(&sp98, 86.0f, 242.0f);
    func_002b2970(&sp90, 826.0f, 242.0f);
    func_002e0620(work->field_E80, sp98, sp90, 0, 4, 0);
    b = (Vec2f *)D_0063F5F8;
    func_002e09e0(work->field_C84, 0x41, 112.0f);
    func_002b2970(&sp88, b->x, b->y);
    func_002b2970(&sp80, 740.0f + b->x, b->y);
    func_002e0620(work->field_C84, sp88, sp80, 0, 4, 0);
    b = (Vec2f *)D_0063F5D8;
    func_002e09e0(work->field_C74, 0x41, 113.0f);
    func_002b2970(&sp78, b->x, b->y);
    func_002b2970(&sp70, 740.0f + b->x, b->y);
    func_002e0620(work->field_C74, sp78, sp70, 0, 4, 0);
    b = (Vec2f *)D_0063F5E0;
    func_002e09e0(work->field_C78, 0x41, 114.0f);
    func_002b2970(&sp68, b->x, b->y);
    func_002b2970(&sp60, 740.0f + b->x, b->y);
    func_002e0620(work->field_C78, sp68, sp60, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        func_002e04f0(*(void **)((u8 *)work + 0xDBC + i * 4), 0, 1);
    }
    func_002e04f0(work->field_CAC, 0, 1);
    func_002e04f0(work->field_E84, 0, 1);
    func_002e04f0(work->field_C94, 0, 1);
    func_002e04f0(work->field_C98, 0, 1);
    func_002e04f0(work->field_E60, 0, 1);
    func_002e04f0(work->field_DE0, 0, 1);
    func_002e0940(work->field_D6C, -110.0f, -14.0f, 0, 4, 0);
    func_002e0690(work->field_D70, 1.0f, 1.0f, 0, 0, 0);
    func_002e0660(work->field_D70, 0, 0xFF, 0, 8, 6);
    func_002b2970(&sp58, 46.0f, 294.0f);
    t = (u8 *)func_002e04e0(work->field_D70);
    *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp58;
    func_002e0660(work->field_D7C, 0, 0xFF, 0, 8, 6);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_C8C, t[0x62], 0xFF, 0, 8, 0);
    t = (u8 *)func_002e04e0(work->field_C90);
    func_002e0660(work->field_C90, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F880;
    func_002b2970(&sp50, 700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    func_002b2970(&sp48, b->x, b->y + (f32)(work->field_4 << 5));
    func_002e0620(work->field_DC8, sp50, sp48, 1, 3, 3);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_DC8, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F890;
    func_002b2970(&sp40, 700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    func_002b2970(&sp38, b->x, b->y + (f32)(work->field_4 << 5));
    func_002e0620(work->field_DD0, sp40, sp38, 1, 3, 3);
    t = (u8 *)func_002e04e0(work->field_C8C);
    func_002e0660(work->field_DD0, t[0x62], 0xFF, 0, 8, 0);
    func_002e0660(work->field_C64, 0, 0xCC, 0, 8, 0);
    func_002e04f0(work->field_DE4, 0, 0);
}

/* measured: MWCC -O2 plain, object 1948B/window 2000B, normalized_diff 389 (VSHD baseline 399/2044B -> s32-i -10, s32+(s16)cast -8). Shape u8 colorA/B[3][4], s16 primary/secondary/y/thirdY, s8 ret/i-d, u8 *work, frame 0x100 matches. Levers: s32/u32/int, switch/ifelse, derived/void/work/decl/d/ret/indexed/forward/reload/y/primary/RGBA as reported. Remaining work $s4-vs-$s3, init $v0-vs-$v1, 0x2D scheduling, D swap, second-loop temps. Combine RGBA transfer fails (+5/+15), u8[3][4] optimal. No volatile/asm. Staged /tmp/push_4760_full.c via NearGA.Fcl4760. */
// FUN_002D4760 NONMATCHING
#ifdef NON_MATCHING
s8 func_002d4760(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s8 ret;
    s32 i;
    s8 d;
    u8 *work;

    ret = arg1;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    colorA[2][0] = 0xBD;
    colorA[0][0] = 0xBD;
    colorA[2][1] = 0x68;
    colorA[0][1] = 0x68;
    colorA[2][2] = 3;
    colorA[0][2] = 3;
    primary[2] = 0x56;
    primary[0] = 0x56;
    y[2][0] = 0x86;
    y[0][0] = 0x86;
    y[2][1] = 0x87;
    y[0][1] = 0x87;
    colorB[2][0] = 0x2D;
    colorB[0][0] = 0x2D;
    colorB[2][1] = 0x2D;
    colorB[0][1] = 0x2D;
    colorB[2][2] = 0x2D;
    colorB[0][2] = 0x2D;
    secondary[2] = 0x57;
    secondary[0] = 0x57;
    thirdY[2] = 0x85;
    thirdY[0] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = 0x42;
    thirdY[1] = 0x88;
    for (i = 0; i < 3; i++) {
        d = D_00748908[i];
        if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
            colorA[i][2] = 0x2D;
            colorA[i][1] = 0x2D;
            colorA[i][0] = 0x2D;
            if (i == 1) {
                colorA[i][2] = 0;
                colorA[i][1] = 0;
                colorA[i][0] = 0;
            }
            colorB[i][2] = 0x6F;
            colorB[i][1] = 0x6F;
            colorB[i][0] = 0x6F;
        }
        if (i == arg1) {
            colorA[i][0] = 0xFF;
            colorA[i][1] = 0x96;
            colorA[i][2] = 1;
            primary[i] = 0x57;
            y[i][0] = 0x83;
            y[i][1] = 0x84;
            colorB[i][0] = 0xFF;
            colorB[i][1] = 0xF2;
            colorB[i][2] = 0x95;
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (d >= func_002e26f0(*(void **)(work + 0xF18 + i * 4))) {
                ((u8 *)colorA)[i * 4 + 2] = 0x9C;
                ((u8 *)colorA)[i * 4 + 1] = 0x9C;
                ((u8 *)colorA)[i * 4 + 0] = 0x9C;
                ((u8 *)colorB)[i * 4 + 2] = 0xFF;
                ((u8 *)colorB)[i * 4 + 1] = 0xFF;
                ((u8 *)colorB)[i * 4 + 0] = 0xFF;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            goto L2;
        }
        if (i == 1) {
            goto L1;
        }
        if (i == 0) {
            goto L0;
        }
        goto Lend;
L0: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xE38)) + 0x7B) = colorB[i][2];
        goto Lend;
L1: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB4)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEB8)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC4)) + 0x7B) = colorB[i][2];
        goto Lend;
L2: *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 8) = (f32)y[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEBC)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0xFC) = primary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 8) = (f32)y[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x79) = colorA[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7A) = colorA[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEC0)) + 0x7B) = colorA[i][2];
            *(s32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0xFC) = secondary[i];
            *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 8) = (f32)thirdY[i];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x79) = colorB[i][0];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7A) = colorB[i][1];
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC0)) + 0x7B) = colorB[i][2];
Lend: ;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d4760);
#endif

// FUN_002D4F30
s32 func_002d4f30(s16 arg0) {
    if (arg0 & 0x81) return 0x14;
    if (arg0 & 0x102) return 0x15;
    if (arg0 & 0x204) return 0x16;
    if (arg0 & 0x408) return 0x17;
    if (arg0 & 0x810) return 0x18;
    if (arg0 & 0x1020) return 0x19;
    if (arg0 & 0x2040) return 0x1A;
    if (arg0 & 0x4000) return 0x1B;
    if (arg0 & 0x8000) return 0x1C;
    if (arg0 & 0x40000) return 0x1D;
    return 0;
}

/* measured: probe_variants 924 differing words reloc-masked (V5 workFirst with opt_propagation off; bare V1 964, V4 handle 926, V6 tmpLast 924 tie); fnalign retail 1105 vs object 1090 instrs (-15, -1.36% PASS, 691 edits +32 reloc-only via --candidate v5_workFirst.c --quiet); verify/lint clean. Count-first PASS (within 3%). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 -o /var/tmp/cold2d5040/m2c.c` (193 lines, void(void*) + s64 homes) + `python3 -E -s tools/romwright_decompile.py func_002d5040 -o /var/tmp/cold2d5040/rom.c` (277 lines, (void*) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 --candidate V5=/var/tmp/cold2d5040/v5_workFirst.c` (924) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002d5040 --candidate /var/tmp/cold2d5040/v5_workFirst.c --quiet` (1105/1090) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002d5040`. */
/* Rounds in batch order (count first): v1 964 (m2c+rom de-noise, Vec2f/u64/RGBA homes, s32 c16=(s16)2740/106cd0 locals for dsll32/dsra32, byte-first addu (*(s8*)((u8*)(*(s8*)(work+8)+(u32)work)+0xF73)), 1153/1108 +45 FAIL); v1 propOff 927 (-37, 1090/1105 -15 PASS) <-- family convention (31fa20 needs propOff; 315600 deadOff 762->755; 302770 peephole 787->728); v1 deadOff 973 worse, peephole 1141 worse; v2 dual-04e0 999 worse (1165 +57 FAIL); v3 u16-mask 931 worse; v4 h0-handle 926 (-1, s32 h0=(s32)46a770 first-call save to $s2); v5 workFirst 924 (-2, best PASS) + v6 tmpLast 924 tie; v5 schedOn 923 (-1) but 942/1105 -163 FAIL unbankable; v7 noDoubleExt 927 worse. Step3 subscript tie (Vec2f/u64/RGBA already retail ld/lw forms); Step4 decl-order tie (workFirst/tmpLast). Stopped after three non-improving rounds above 60. Banked v5+propOff as guarded floor. */
/* Walls (same float-hoist+scheduling as sibling de5a0, now at 924): retail f20 hoisted vs object f12 rematerialised per 2970 pair (lui+lwc1 hoist vs interleaved lwc1/lui); retail lwc1/swc1 Vec2f copy vs object ld/sd; retail andi vs object ori/and under propOff (&0xFFFF); $s0/$s1 colouring (work/tmp/h0/dA/dB) persists -- body already in 7o form (bare decls, statement assigns in retail order) so eight probes are ties per handoff 7o; all logic matches: 2a30/0b20/75680 chain + three-case switch on work[7] (68b0/68e0 vs 6940/6970) + eight cacd0 digits (22.0f/0xF/0/0x1E/0x7B/h0/h1/0xA9) + blez/bgez tail pair (360+87/245/23). Prior nd-814 note superseded (sign-extension locals now in place via s32 cA/cB/c16); lever-1 audit void(void*) kept, cacd0 11-arg file decl kept (12-arg claim was wrong: 8 int regs + 2 stack + 1 float = 11). */
/* 2026-09-18 opcode census; floor stands at 924.  `tools/opclass.py` ranks
   this the largest opcode-class surplus on the board: `dsra32 +37`,
   `dsll32 +37` against `mtc1 -37` and `lui -35`.  Thirty-seven
   sign-extension pairs is the textbook too-narrow-local signature, but the
   `(s16)` casts in this body are not the cause - dropping the redundant
   `(s16)` on values that are already narrow ties at 924, declaring `cA`,
   `cB` and `c16` as `s16` and removing the casts ties at 924, and dropping
   every `(s16)` result cast costs 936.  The paired `mtc1`/`lui` deficit says
   retail materialises 35 constants this body does not, so the two halves are
   probably one phenomenon: retail keeps wide constants where this body
   narrows and re-extends.  That is the thread for the next pass. */
/* thread resolved 2026-09-19: retail `mtc1` spans are two families -- float-bit `lui+mtc1` for 37.0/35.0/31.0/79.0/34.0/296.0/51.0/87.0/22.0/149.0/360.0/245.0/23.0 (each `lwc1`-then-`lui/mtc1/add.s`, interleaved with dual `04e0` calls per `2970`) plus int-path `mtc1+cvt.s.w` for 263 (`addiu 0x107`) and `(nA-1)*8` (`sll 3`); body round-trips three values narrow: (1) `0046a770` handle via wrong file-scope `s64` (def returns `u8*`, sibs use `voidptr/s32`) -- `(s32)` narrows `s64->s32` as `dsll32 0/dsra32 0` (16 pairs, `daddu` in retail); (2) `002b3170` via wrong file-scope `s16` (def/promoted/sib return `s32`) -- `nA=(s16)` extends before `-1` (8 pairs, retail extends after only); (3) `c16` s32 store vs retail `daddu` for `06cd0->068x` chains. `and+17/andi-13` is mask `0xFFFF` hoisted to `$s3` (`ori+and`) under `propOff` via `cB/tmp` reuse across 8 arms vs retail per-use `andi`. */
/* banked 2026-09-19 at 907 words (-17): file-scope `0046a770 s64->void*` + `002b3170 s16->s32` (match defs/sibs, verify 26 MATCH no regress) + split 6 two-load `2970`s to dual `04e0` calls (`*(p+0x2C/0x30)` -> `*((u8*)04e0+0x2C/0x30)` each, 20->26 occ, fixes `jal/lw -4`, counts 1105/1074 PASS) + `cB8/cB0` struct->field assigns (`ld/sd` -> `lwc1/swc1`, edits 691->436). `measure_guarded` 907, `fnalign --candidate` 1105/1074 +44 reloc-only, `opclass` `dsll/dsra 13` (was 37: -16 handle, -8 nA), `mtc1/lui` + `and/andi` + `mov.s` walls stand (floats hoisted to `$f21-$f27`, mask to `$s3`). Rejected: wide-`u16` (drop `(s16)` on `68b0/e0/6940/6970`, 930/936 worse -- narrow matches retail `andi` sites); `c16`-inline (925, -43 FAIL); `commonSubs off` (908 tie, 1141 FAIL, 1530 edits). */
// FUN_002D5040 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_002d5040(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    RGBA sp12C;
    RGBA sp128;
    RGBA sp124;
    RGBA sp120;
    RGBA sp11C;
    RGBA sp118;
    RGBA sp114;
    RGBA sp110;
    Vec2f cB8;
    Vec2f cB0;
    u8 *work;
    s32 tmp;
    s32 t0;
    s32 t1;
    s32 c16;
    s32 cA;
    s32 cB;
    s32 nA;
    s32 h0;
    s32 dA;
    s32 dB;
    u8 *pCE4;
    u8 *pEDC;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    cB = (s16)func_00106880((s16)cA);
    tmp = func_002d4f30((s16)cB) & 0xFFFF;
    func_002b2970(&sp108, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
    func_002e0b20(tmp, sp108, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    t0 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp100, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xCE4)) + 0x30));
    cB8.x = sp100.x; cB8.y = sp100.y;
    cA = (s16)func_002e2740(*(s16 *)(work + 2));
    func_00275680(cB8.x, cB8.y, 31.0f, t0, 0, 1, (const char *)func_001067f0(cA), 0, 0, D_00795E30, -1);
    t1 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&spF8, 79.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 34.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
    cB0.x = spF8.x; cB0.y = spF8.y;
    c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7));
    func_00275680(cB0.x, cB0.y, 31.0f, t1, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    if (*(s8 *)(work + 7) == 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA8, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp12C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA8, 22.0f, sp12C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&spA0, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp128, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(spA0, 22.0f, sp128, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spF0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), spF0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068b0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp98, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp124, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp98, 22.0f, sp124, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        cB = (s16)func_001068e0(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp90, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp120, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp90, 22.0f, sp120, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068b0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068b0((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        tmp = func_001068e0(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_001068e0((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 1) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp88, 51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C)) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp11C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp88, 22.0f, sp11C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp80, 87.0f + (51.0f + (296.0f + *(f32 *)(pCE4 + 0x2C))) + (f32)((s16)(nA - 1) * 8), 263.0f);
        func_002b2a60(&sp118, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp80, 22.0f, sp118, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        func_002b2970(&spE8, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1B, spE8, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106940(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp78, 51.0f + (296.0f + *(f32 *)(pEDC + 0x2C)) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp114, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp78, 22.0f, sp114, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        pEDC = func_002e04e0(*(void **)(work + 0xEDC));
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        cB = (s16)func_00106970(c16);
        tmp = cB & 0xFFFF;
        nA = func_002b3170(tmp);
        func_002b2970(&sp70, 87.0f + (51.0f + (296.0f + *(f32 *)(pEDC + 0x2C))) + (f32)((s16)(nA - 1) * 8), 149.0f);
        func_002b2a60(&sp110, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp70, 22.0f, sp110, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, (s32)func_0046a770(D_0063FB50), 0xA9);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106940(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106940((s16)cA);
        dB = (s16)((cB & 0xFFFF) - tmp);
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        tmp = func_00106970(c16) & 0xFFFF;
        cA = (s16)func_002e2740(*(s16 *)(work + 2));
        cB = (s16)func_00106970((s16)cA);
        dA = (s16)((cB & 0xFFFF) - tmp);
    } else if (*(s8 *)(work + 7) == 2) {
        func_002b2970(&spE0, 37.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)func_002e04e0(*(void **)(work + 0xEDC)) + 0x30));
        func_002e0b20(0x1C, spE0, 31.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        dA = 0;
        dB = 0;
    } else {
        dA = 0;
        dB = 0;
    }
    if (dB > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD8, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x28, spD8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dB < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spD0, 360.0f + *(f32 *)(pCE4 + 0x2C), 245.0f);
        func_002e0b20(0x29, spD0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (dA > 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC8, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x28, spC8, 23.0f, func_002b2a30(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
        return;
    }
    if (dA < 0) {
        pCE4 = func_002e04e0(*(void **)(work + 0xCE4));
        func_002b2970(&spC0, 87.0f + (360.0f + *(f32 *)(pCE4 + 0x2C)), 245.0f);
        func_002e0b20(0x29, spC0, 23.0f, func_002b2a30(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d5040);
#endif

/* measured: full body reconstructed (19 RGBA color groups + 0a60/2a60/04e0/
   2970/0620 chains, 48 u64 slots, 2 ifs + 3-case switch); frame 0x200 and all
   slot offsets matched; best nd 895 (obj only 2 words over window). Three
   residual families: (1) D_0063F658/D_0063F650 (f32[2]) base: retail hoists it
   into $s0 across the group's calls (lwc1 ($s0)/4($s0)); mwcc b210
   rematerialises lui+lwc1 per access even with named f32* base locals --
   same D_00887300 family as the func_002d7300 note. (2) color bytes: retail
   batches 4 lbu then 4 sb in address order into $a2/$a1/$a0/$v1; mwcc emits
   scrambled load order (g,b,a,r) for every spelling tried (array, u8 scalars,
   RGBA struct, explicit r/g/b/a temps). (3) work[7] if/switch: retail reloads
   lb 7($s1) per site; mwcc hoists addiu $s0,$s1,7. Global-address-hoist +
   scheduling floor. */
// FUN_002D6190
void func_002d6190(void *arg0) {
    RGBA sp1FC;
    RGBA sp1F8;
    RGBA sp1F4;
    RGBA sp1F0;
    RGBA sp1EC;
    RGBA sp1E8;
    RGBA sp1E4;
    RGBA sp1E0;
    RGBA sp1DC;
    RGBA sp1D8;
    RGBA sp1D4;
    RGBA sp1D0;
    RGBA sp1CC;
    RGBA sp1C8;
    RGBA sp1C4;
    RGBA sp1C0;
    RGBA sp1BC;
    RGBA sp1B8;
    RGBA sp1B4;
    u64 sp1A8;
    u64 sp1A0;
    u64 sp198;
    u64 sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    u8 *work;
    u8 *t;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002e0a60(*(void **)(work + 0xCE4), 0x56, 35.0f);
    func_002b2a60(&sp1FC, 0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCE4)));
    *(RGBA *)(t + 0x79) = sp1FC;
    func_002b2970(&sp1A8, (f32) -0x212, 208.0f);
    func_002b2970(&sp1A0, 70.0f, 208.0f);
    func_002e0620(*(void **)(work + 0xCE4), sp1A8, sp1A0, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xCE8), 0x56, 35.0f);
    func_002b2a60(&sp1F8, 0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCE8)));
    *(RGBA *)(t + 0x79) = sp1F8;
    func_002b2970(&sp198, -37.0f, 208.0f);
    func_002b2970(&sp190, (f32) 0x233, 208.0f);
    func_002e0620(*(void **)(work + 0xCE8), sp198, sp190, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    func_002e0a60(*(void **)(work + 0xCB4), 0x57, 33.0f);
    func_002b2a60(&sp1F4, 0xF7, 0x94, 0x1D, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCB4)));
    *(RGBA *)(t + 0x79) = sp1F4;
    func_002b2970(&sp188, base->x - 600.0f, base->y);
    func_002b2970(&sp180, base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB4), sp188, sp180, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        func_002e0a60(*(void **)(work + 0xCAC), 0x57, 30.0f);
        func_002b2a60(&sp1F0, 0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCAC)));
        *(RGBA *)(t + 0x79) = sp1F0;
        func_002b2970(&sp178, -232.0f, 227.0f);
        func_002b2970(&sp170, 368.0f, 227.0f);
        func_002e0620(*(void **)(work + 0xCAC), sp178, sp170, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE84), 0x57, 30.0f);
        func_002b2a60(&sp1EC, 0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE84)));
        *(RGBA *)(t + 0x79) = sp1EC;
        func_002b2970(&sp168, 468.0f, 338.0f);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE84)));
        *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp168;
        func_002b2970(&sp160, -145.0f, 227.0f);
        func_002b2970(&sp158, (f32) 0x1C7, 227.0f);
        func_002e0620(*(void **)(work + 0xE84), sp160, sp158, 0, 8, 0);
    }
    func_002e0a60(*(void **)(work + 0xEDC), 0x56, 35.0f);
    func_002b2a60(&sp1E8, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xEDC)));
    *(RGBA *)(t + 0x79) = sp1E8;
    func_002b2970(&sp150, (f32) 0x29E, 94.0f);
    func_002b2970(&sp148, 70.0f, 94.0f);
    func_002e0620(*(void **)(work + 0xEDC), sp150, sp148, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xEE0), 0x56, 35.0f);
    func_002b2a60(&sp1E4, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xEE0)));
    *(RGBA *)(t + 0x79) = sp1E4;
    func_002b2970(&sp140, (f32) 0x48B, 94.0f);
    func_002b2970(&sp138, (f32) 0x233, 94.0f);
    func_002e0620(*(void **)(work + 0xEE0), sp140, sp138, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    func_002e0a60(*(void **)(work + 0xCB0), 0x57, 34.0f);
    func_002b2a60(&sp1E0, 0xB0, 0xAF, 0xAF, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCB0)));
    *(RGBA *)(t + 0x79) = sp1E0;
    func_002b2970(&sp130, 600.0f + base->x, base->y);
    func_002b2970(&sp128, base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB0), sp130, sp128, 0, 8, 0);
    func_002e0a60(*(void **)(work + 0xCD0), 0x57, 32.0f);
    func_002b2a60(&sp1DC, 0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(func_002e04e0(*(void **)(work + 0xCD0)));
    *(RGBA *)(t + 0x79) = sp1DC;
    func_002b2970(&sp120, (f32) 0x395, 178.0f);
    func_002b2970(&sp118, (f32) 0x13D, 178.0f);
    func_002e0620(*(void **)(work + 0xCD0), sp120, sp118, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        func_002e0a60(*(void **)(work + 0xEA4), 0x57, 30.0f);
        func_002b2a60(&sp1D8, 0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA4)));
        *(RGBA *)(t + 0x79) = sp1D8;
        func_002b2970(&sp110, 968.0f, 113.0f);
        func_002b2970(&sp108, 368.0f, 113.0f);
        func_002e0620(*(void **)(work + 0xEA4), sp110, sp108, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xEA8), 0x57, 30.0f);
        func_002b2a60(&sp1D4, 0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA8)));
        *(RGBA *)(t + 0x79) = sp1D4;
        func_002b2970(&sp100, 468.0f, 338.0f);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA8)));
        *(Vec2f *)(t + 0x2C) = *(Vec2f *)&sp100;
        func_002b2970(&spF8, (f32) 0x41F, 113.0f);
        func_002b2970(&spF0, (f32) 0x1C7, 113.0f);
        func_002e0620(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    }
    temp_4 = (s8)(*(s8 *)(work + 7));
    switch (temp_4) {                               /* irregular */
    case 0:
        func_002e0a60(*(void **)(work + 0xCA0), 0x58, 27.0f);
        func_002b2a60(&sp1D0, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA0)));
        *(RGBA *)(t + 0x79) = sp1D0;
        func_002b2970(&spE8, -230.0f, 234.0f);
        func_002b2970(&spE0, 370.0f, 234.0f);
        func_002e0620(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCA8), 0x58, 26.0f);
        func_002b2a60(&sp1CC, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA8)));
        *(RGBA *)(t + 0x79) = sp1CC;
        func_002b2970(&spD8, -143.0f, 234.0f);
        func_002b2970(&spD0, (f32) 0x1C9, 234.0f);
        func_002e0620(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE98), 0x58, 27.0f);
        func_002b2a60(&sp1C8, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE98)));
        *(RGBA *)(t + 0x79) = sp1C8;
        func_002b2970(&spC8, (f32) 0x3CA, 121.0f);
        func_002b2970(&spC0, 370.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xEA0), 0x58, 26.0f);
        func_002b2a60(&sp1C4, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xEA0)));
        *(RGBA *)(t + 0x79) = sp1C4;
        func_002b2970(&spB8, (f32) 0x421, 121.0f);
        func_002b2970(&spB0, (f32) 0x1C9, 121.0f);
        func_002e0620(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        func_002e0a60(*(void **)(work + 0xC9C), 0x58, 25.0f);
        func_002b2a60(&sp1C0, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xC9C)));
        *(RGBA *)(t + 0x79) = sp1C0;
        func_002b2970(&spA8, -230.0f, 234.0f);
        func_002b2970(&spA0, 370.0f, 234.0f);
        func_002e0620(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCA4), 0x58, 24.0f);
        func_002b2a60(&sp1BC, 0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xCA4)));
        *(RGBA *)(t + 0x79) = sp1BC;
        func_002b2970(&sp98, -143.0f, 234.0f);
        func_002b2970(&sp90, (f32) 0x1C9, 234.0f);
        func_002e0620(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE94), 0x58, 25.0f);
        func_002b2a60(&sp1B8, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE94)));
        *(RGBA *)(t + 0x79) = sp1B8;
        func_002b2970(&sp88, (f32) 0x3CA, 121.0f);
        func_002b2970(&sp80, 370.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xE9C), 0x58, 24.0f);
        func_002b2a60(&sp1B4, 0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(func_002e04e0(*(void **)(work + 0xE9C)));
        *(RGBA *)(t + 0x79) = sp1B4;
        func_002b2970(&sp78, (f32) 0x421, 122.0f);
        func_002b2970(&sp70, (f32) 0x1C9, 120.0f);
        func_002e0620(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        func_002e0a60(*(void **)(work + 0xCB8), 0x58, 28.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xCB8)))[0x62] = 0x7F;
        func_002b2970(&sp68, -233.0f, 225.0f);
        func_002b2970(&sp60, (f32) 0x16F, 225.0f);
        func_002e0620(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        func_002e09e0(*(void **)(work + 0xEAC), 0x58, 28.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xEAC)))[0x62] = 0x7F;
        func_002b2970(&sp58, -146.0f, 225.0f);
        func_002b2970(&sp50, 454.0f, 225.0f);
        func_002e0620(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        func_002e0a60(*(void **)(work + 0xCBC), 0x58, 29.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xCBC)))[0x62] = 0xFF;
        func_002b2970(&sp48, (f32) 0x3C7, 111.0f);
        func_002b2970(&sp40, (f32) 0x16F, 111.0f);
        func_002e0620(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        func_002e09e0(*(void **)(work + 0xEB0), 0x58, 29.0f);
        ((u8 *)func_002e04e0(*(void **)(work + 0xEB0)))[0x62] = 0xFF;
        func_002b2970(&sp38, (f32) 0x41E, 111.0f);
        func_002b2970(&sp30, 454.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
        return;
    }
}

/* measured: full body reconstructed (45 u64 slots, 22 2970/0620 chains, 3-case
   switch on work[7]) with D_0063F650/D_0063F658 redeclared f32[] and read via
   `Vec2f *base = (Vec2f *)D_0063F658;` - this DOES reproduce retail's $s1 base
   hoist (frame 0x1A0, ra/s1/s0, all slot offsets byte-match; the func_002d6190
   note's d658/d650 hoist floor does not apply to this shape). Four variants,
   best nd 70 (obj 2316B vs window 2320B): every func_002e0620 site loads
   arg1/arg2 (ld sp198/sp190) BEFORE arg0 (lw 0xCE4($s0)) where retail loads
   arg0 first - a 2-instruction pre-jal ordering swap at each of 22 sites.
   func_002df4c0 (matched) has the identical call shape with u64 slots and
   retail order lw-first, so the s64-vs-u64 slot type or slot offset likely
   drives the scheduler; untested within budget. Pre-jal arg-order floor. */
/* lever-1 audit (this wave): func_002d7300 is void (void *arg0) -- confirmed
   by generated-draft call sites. D_0063F650/D_0063F658 are f32[] (matches
   the note's Vec2f*(f32[]) reading); func_002e0620 (void*,u64,u64,s32,s32,
   s16) and func_002e04e0 (void*) match m2c. No extern-width defect. */
/* MATCHED: Vec2f *base over f32[] D_0063F658/D_0063F650 reproduces the $s1 base hoist; (f32)int casts + float literals reproduce every 2970 chain. */
// FUN_002D7300
void func_002d7300(void *arg0) {
    u64 sp198;
    u64 sp190;
    u64 sp188;
    u64 sp180;
    u64 sp178;
    u64 sp170;
    u64 sp168;
    u64 sp160;
    u64 sp158;
    u64 sp150;
    u64 sp148;
    u64 sp140;
    u64 sp138;
    u64 sp130;
    u64 sp128;
    u64 sp120;
    u64 sp118;
    u64 sp110;
    u64 sp108;
    u64 sp100;
    u64 spF8;
    u64 spF0;
    u64 spE8;
    u64 spE0;
    u64 spD8;
    u64 spD0;
    u64 spC8;
    u64 spC0;
    u64 spB8;
    u64 spB0;
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    u8 *work;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002b2970(&sp198, 70.0f, 208.0f);
    func_002b2970(&sp190, (f32)0x29E, 208.0f);
    func_002e0620(*(void **)(work + 0xCE4), sp198, sp190, 0, 8, 0);
    func_002b2970(&sp188, (f32)0x233, 208.0f);
    func_002b2970(&sp180, (f32)0x48B, 208.0f);
    func_002e0620(*(void **)(work + 0xCE8), sp188, sp180, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    func_002b2970(&sp178, base->x, base->y);
    func_002b2970(&sp170, 600.0f + base->x, base->y);
    func_002e0620(*(void **)(work + 0xCB4), sp178, sp170, 0, 8, 0);
    func_002b2970(&sp168, 368.0f, 227.0f);
    func_002b2970(&sp160, 968.0f, 227.0f);
    func_002e0620(*(void **)(work + 0xCAC), sp168, sp160, 0, 8, 0);
    func_002b2970(&sp158, (f32)0x1C7, 227.0f);
    func_002b2970(&sp150, (f32)0x41F, 227.0f);
    func_002e0620(*(void **)(work + 0xE84), sp158, sp150, 0, 8, 0);
    func_002b2970(&sp148, 70.0f, 94.0f);
    func_002b2970(&sp140, (f32)-0x212, 94.0f);
    func_002e0620(*(void **)(work + 0xEDC), sp148, sp140, 0, 8, 0);
    func_002b2970(&sp138, (f32)0x233, 94.0f);
    func_002b2970(&sp130, -37.0f, 94.0f);
    func_002e0620(*(void **)(work + 0xEE0), sp138, sp130, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    func_002b2970(&sp128, base->x, base->y);
    func_002b2970(&sp120, base->x - 600.0f, base->y);
    func_002e0620(*(void **)(work + 0xCB0), sp128, sp120, 0, 8, 0);
    func_002b2970(&sp118, (f32)0x13D, 178.0f);
    func_002b2970(&sp110, (f32)-0x11B, 178.0f);
    func_002e0620(*(void **)(work + 0xCD0), sp118, sp110, 0, 8, 0);
    func_002b2970(&sp108, 368.0f, 113.0f);
    func_002b2970(&sp100, -232.0f, 113.0f);
    func_002e0620(*(void **)(work + 0xEA4), sp108, sp100, 0, 8, 0);
    func_002b2970(&spF8, (f32)0x1C7, 113.0f);
    func_002b2970(&spF0, -145.0f, 113.0f);
    func_002e0620(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    temp_4 = *(s8 *)(work + 7);
    switch (temp_4) {
    case 0:
        func_002b2970(&spE8, 370.0f, 234.0f);
        func_002b2970(&spE0, (f32)0x3CA, 234.0f);
        func_002e0620(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        func_002b2970(&spD8, (f32)0x1C9, 234.0f);
        func_002b2970(&spD0, (f32)0x421, 234.0f);
        func_002e0620(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        func_002b2970(&spC8, 370.0f, 121.0f);
        func_002b2970(&spC0, -230.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        func_002b2970(&spB8, (f32)0x1C9, 121.0f);
        func_002b2970(&spB0, -143.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        func_002b2970(&spA8, 370.0f, 234.0f);
        func_002b2970(&spA0, (f32)0x3CA, 234.0f);
        func_002e0620(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        func_002b2970(&sp98, (f32)0x1C9, 234.0f);
        func_002b2970(&sp90, (f32)0x421, 234.0f);
        func_002e0620(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        func_002b2970(&sp88, 370.0f, 121.0f);
        func_002b2970(&sp80, -230.0f, 121.0f);
        func_002e0620(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        func_002b2970(&sp78, (f32)0x1C9, 120.0f);
        func_002b2970(&sp70, -143.0f, 122.0f);
        func_002e0620(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        func_002b2970(&sp68, (f32)0x16F, 225.0f);
        func_002b2970(&sp60, (f32)0x3C7, 225.0f);
        func_002e0620(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        func_002b2970(&sp58, 454.0f, 225.0f);
        func_002b2970(&sp50, (f32)0x41E, 225.0f);
        func_002e0620(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        func_002b2970(&sp48, (f32)0x16F, 111.0f);
        func_002b2970(&sp40, -233.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        func_002b2970(&sp38, 454.0f, 111.0f);
        func_002b2970(&sp30, -146.0f, 111.0f);
        func_002e0620(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
        return;
    }
}



// FUN_002D7C10
void func_002d7c10(void *arg0, s16 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;

    r = (s32)func_0046d200(work->field_F28, 4);
    func_0046b260((u8 *)r);
    func_0046b2f0((u8 *)r);
    func_0046d280((u8 *)r);
    func_002e0940(work->field_EC4, ((ShopWork *)func_002e04e0(work->field_EC4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EC8, ((ShopWork *)func_002e04e0(work->field_EC8))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_CC4, ((ShopWork *)func_002e04e0(work->field_CC4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EB4, ((ShopWork *)func_002e04e0(work->field_EB4))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EB8, ((ShopWork *)func_002e04e0(work->field_EB8))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_CC0, ((ShopWork *)func_002e04e0(work->field_CC0))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EBC, ((ShopWork *)func_002e04e0(work->field_EBC))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_EC0, ((ShopWork *)func_002e04e0(work->field_EC0))->field_C4, 0.0f, 0, 2, 0);
    func_002e0940(work->field_E38, ((ShopWork *)func_002e04e0(work->field_E38))->field_C4, 0.0f, 0, 2, 0);
    switch ((s32)arg1) {
    case 0:
        func_002e0940(work->field_EC4, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EC8, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_E38, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 1:
        func_002e0940(work->field_EB4, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EB8, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_CC4, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 2:
        func_002e0940(work->field_EBC, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_EC0, 0.0f, -3.0f, 0, 2, 0);
        func_002e0940(work->field_CC0, 0.0f, -3.0f, 0, 2, 0);
        break;
    }
}

// FUN_002D7F90
void func_002d7f90(void *arg0) {
    s16 v1;
    u8 *p;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    u32 hi;
    f32 f1;
    f32 f20;

    p = D_0063F9F0 + (s32)*(s8 *)((u8 *)work + 7) * 12;
    r = (s32)func_0046d200(work->field_F28, 4);
    v1 = (s16)(s32)((*(f32 *)(p + 8) + func_0046b260((u8 *)r)) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C44))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C44))->field_102 = v2;
    f1 = (f32)v1;
    v1 = (s16)(s32)(f1 - *(f32 *)(p + 8));
    ((ShopWork *)func_002e04e0(work->field_C48))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_C48))->field_102 = v2;
    hi = func_003b7060() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)func_002e04e0(work->field_C44))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    func_002e0940(work->field_C44, 0.0f, f20, 0, 0, 0);
    func_002e0940(work->field_C48, 0.0f, f20, 0, 0, 0);
    func_0046d280((u8 *)r);
}

// FUN_002D8200
void func_002d8200(void *arg0, s8 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v;
    f32 f20;

    func_002e04e0(work->field_E60);
    f20 = 4.0f;
    if (arg1 == 1) {
        f20 = f20 * -1.0f;
    }
    r = (s32)func_0046d200(work->field_F28, 0x7D);
    v = (s16)(s32)func_0046b260((u8 *)r);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_100 = v;
    v = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_102 = v;
    ((ShopWork *)func_002e04e0(work->field_E30))->field_100 = 0;
    v = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_E30))->field_102 = v;
    func_002e0940(work->field_E2C, 0.0f, f20, 0, 4, 0);
    func_002e0940(work->field_E30, 0.0f, f20, 0, 4, 0);
    ((ShopWork *)func_002e04e0(work->field_E2C))->field_CF = 1;
    ((ShopWork *)func_002e04e0(work->field_E30))->field_CF = 1;
    func_0046d280((u8 *)r);
}


// FUN_002D83C0
void func_002d83c0(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    s16 v1;
    u32 hi;
    f32 f1;
    f32 f20;

    r = (s32)func_0046d200(work->field_F28, 4);
    v1 = (s16)(s32)((func_0046b260((u8 *)r) + 79.0f) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED4))->field_100 = v1;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED4))->field_102 = v2;
    v2 = (s16)(v1 - 0x4F);
    ((ShopWork *)func_002e04e0(work->field_ED8))->field_100 = v2;
    v2 = (s16)(s32)(func_0046b2f0((u8 *)r) / 2.0f);
    ((ShopWork *)func_002e04e0(work->field_ED8))->field_102 = v2;
    hi = func_003b7060() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)func_002e04e0(work->field_ED4))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    func_002e0940(work->field_ED4, 0.0f, f20, 0, 0, 0);
    func_002e0940(work->field_ED8, 0.0f, f20, 0, 0, 0);
    func_0046d280((u8 *)r);
}

// FUN_002D8600
void func_002d8600(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s16 i;
    u8 *t;
    Vec2f grp1;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    Vec2f grp4;
    Vec2f grp3;
    Vec2f grp2;

    func_002e04f0(work->field_CA0, 0, 1);
    func_002e04f0(work->field_CA8, 0, 1);
    func_002e04f0(work->field_C9C, 0, 1);
    func_002e04f0(work->field_CA4, 0, 1);
    func_002e04f0(work->field_CB8, 0, 1);
    func_002e04f0(work->field_EAC, 0, 1);
    for (i = 0; i < 3; i++) {
        s32 off = (s32)i * 4;
        func_002e04f0(*(void **)((u8 *)work + 0xDBC + off), 0, 1);
    }
    func_002e04f0(work->field_CAC, 0, 1);
    func_002e04f0(work->field_E84, 0, 1);
    func_002e04f0(work->field_C94, 0, 1);
    func_002e04f0(work->field_C98, 0, 1);
    t = (u8 *)func_002e04e0(work->field_E50);
    grp1 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp60, 740.0f + grp1.x, grp1.y);
    func_002e0620(work->field_E50, *(u64 *)&grp1, sp60, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E54);
    grp2 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp58, 740.0f + grp2.x, grp2.y);
    func_002e0620(work->field_E54, *(u64 *)&grp2, sp58, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E58);
    grp3 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp50, 740.0f + grp3.x, grp3.y);
    func_002e0620(work->field_E58, *(u64 *)&grp3, sp50, 0, 4, 0);
    t = (u8 *)func_002e04e0(work->field_E5C);
    grp4 = *(Vec2f *)((u8 *)t + 0x2C);
    func_002b2970(&sp48, 740.0f + grp4.x, grp4.y);
    func_002e0620(work->field_E5C, *(u64 *)&grp4, sp48, 0, 4, 0);
    func_002e0700(work->field_EC4, 3, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EC8, 4, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_E38, 0x80, fGpffff8504, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EB4, 3, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EB8, 4, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_CC4, 0x23, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EBC, 3, fGpffff8504, 1.0f, 6, 2, 1);
    func_002e0700(work->field_EC0, 4, fGpffff8504, 1.0f, 6, 2, 1);
    func_002e0700(work->field_CC0, 0x22, fGpffff8504, 1.0f, 6, 1, 1);
    func_002e04f0(work->field_DDC, 0, 0);
    func_002e04f0(work->field_DE4, 0, 0);
    func_002e04f0(work->field_DE0, 0, 1);
    *(s8 *)((u8 *)work + 0xC24) = 0;
}

/* measured: full m2c draft adapted (color-group chains, 46b260/2b2cb0/2a30
   calls, phantom args dropped, D_0063F9C0/C8/D0 f32[2] bases - real symbols
   here, unlike func_002da0a0 where they were mislabels) and compiles;
   nd 1196. Residual: D_0063F9C0-family base hoist into $s0 (retail lui+addiu
   once per group; mwcc rematerialises per access - cf. func_002d7300 note,
   Vec2f cast may apply), (f32)(s32) round-trip casts m2c invented on the
   temp_f2x values, and 46b260/26f0 result width handling. Hoist + cast
   floor. */
/* Wave 7 ran out of turns partway through adapting this body and left it
   uncompilable (a func_002e09e0 call with the wrong arity). Reverted. The
   wave's measured findings for this file's family are recorded above
   func_002CAEF0 and func_002D7300: the group base hoist works via a reassigned
   `Vec2f *base` local, taking func_002CAEF0 from nd 414 to 36. */
// FUN_002D8A60
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d8a60);

/* Archived C reconstruction: build/W8ShopRGBA_func_002da0a0_highnd.c.
   Best measured candidate object 5032/window 4960, normalized_diff 3080;
   bare INCLUDE_ASM restored after ruled-out source-shape probes. */
// FUN_002DA0A0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002da0a0);

/* measured: full m2c draft adapted (40 2970 chains, 46b200/46b260/46b2f0/
   46d280 handle calls, FA70-FA98 f32[2] bases, phantom args dropped) and
   compiles; nd 1663. Residual: D_0063F5B8/F65x base hoist into $s1 per group
   (retail lwc1 0/4($s1); mwcc lui+lwc1 per access - cf. func_002d7300 note),
   plus m2c's (s64)(s32) return-width casts on 46b260/46b2f0 and the 26f0
   sign-extension split. Hoist + width floor. */
// FUN_002DB400
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002db400);
// FUN_002DD230
void func_002dd230(void *arg0) {
    u64 sp48;
    u64 sp40;
    u64 sp38;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *s1;

    s1 = func_002e04e0(work->field_D90);
    func_002b2970(&sp48, 311.0f, -17.0f);
    func_002e0620(work->field_D90, *(u64 *)((u8 *)s1 + 0x2C), sp48, 0, 0xA, 0);
    s1 = func_002e04e0(work->field_D94);
    func_002b2970(&sp40, 564.0f, -17.0f);
    func_002e0620(work->field_D94, *(u64 *)((u8 *)s1 + 0x2C), sp40, 0, 0xA, 0);
    s1 = func_002e04e0(work->field_D8C);
    func_002b2970(&sp38, -610.0f, -620.0f);
    func_002e0620(work->field_D8C, *(u64 *)((u8 *)s1 + 0x2C), sp38, 0, 0xA, 0);
    func_002e04f0(work->field_D8C, 3, 1);
    func_002e0940(work->field_D8C, 0.0f, 360.0f, 0, 0x708, 0);
    func_002e04f0(work->field_D8C, 6, 0);
}

/* measured: func_002dd3b0's best reconstructed C body is archived verbatim at
   build/WBFclShopDraw_func_002dd3b0_archive.txt. Its scoped result was object
   4816B against a 4592B retail window, normalized_diff 3543, MISMATCH. The
   archive records the candidate/retail prologue and saved-register facts, the
   exact fndiff prologue rows, the two-call func_0046a770 findings for all four
   branch groups, the two regular work->field_F28 calls, and ruled-out probes. */
/* measured: probe_variants 895 differing words reloc-masked (V9loop with opt_propagation off + opt_common_subs off + opt_loop_invariants on; bare V1 1028, V2 swap 1025, V3prop 969, V7 cached 958, V8common 902); fnalign retail 1148 vs object 1163 instrs (+15, +1.31% PASS, 378 edits +26 reloc-only via --candidate v9_loop.c --quiet); verify/lint clean. Count-first PASS (within 3%). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 -o /var/tmp/cold2dd3b0/m2c.c` (jr/jtbl failure, no output) + `python3 -E -s tools/romwright_decompile.py func_002dd3b0 -o /var/tmp/cold2dd3b0/rom.c` (356 lines, (void*) arity, stack extents) + `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 --candidate V9=/var/tmp/cold2dd3b0/v9_loop.c` (895) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0 --candidate /var/tmp/cold2dd3b0/v9_loop.c --quiet` (1148/1163) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002dd3b0`. */
/* Rounds in batch order (count first): v1 1028 (m2c+rom de-noise, Vec2f/u64/RGBA homes, correct 0b20/cacd0/75680 orders per file header + fr_font_internal.h, 1209/1148 +61 FAIL); v2 swap 1025 (-3, outer dispatch 1-first to match retail L002DD960 layout 1-near/0-2-far, edits 1344->498); v3 propOff 969 (-56, family convention as 2d5040) + v3 commonOff 1002 (-23) vs loop/unroll/sched ties; v4 subscript ties (F18 P[i] vs off); v5 colouring ties (work/tmp swaps); v6 f32 ties (micro shows (f32)0x246 and 582.0f both emit addiu+cvt); v7 cached 958 (-11, 04e0 result caching 37->17 calls matching retail 17, 1146/1147 -1 PASS); v8 common 902 (-56, propOff+commonOff) + v8 loop 949 (-9) vs unroll/sched/sub ties; v9 loop 895 (-7, triple propOff+commonOff+loopInvOn) vs unroll/sched/col/sub ties; v10 sweep ties (dead/str/sched/unroll) + peep 1062 worse; v11 width worse (loop s16 970, c16 s16 984) + workLast tie. Step3/Step4 ties per handoff 7o (bare decls, assigns in retail order). */
/* Walls (same float-hoist+scheduling as sibling 2d5040, now at 895): retail f20 hoisted vs object f12 rematerialised per 2970 pair; retail lwc1/swc1 Vec2f copy vs object ld/sd; retail andi vs object ori/and under propOff (&0xFFFF); $s0/$s1/$s2 colouring (work/tmp/h0/pT) persists -- body already in 7o form so subscript/colouring probes are ties; all logic matches: 0b20/cacd0/75680 chains with correct 11-arg signatures + outer C24 + inner 26f0 + 069d0 loop/bc7f0 + three-case work[7] dispatch (0/2 far, 1 near with 20-28 jump table) + eight 04e0 groups cached. Prior nd-3543 archive superseded (helper orders + caching + dispatch layout fixed). */
// FUN_002DD3B0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_loop_invariants on
void func_002dd3b0(void *arg0) {
    extern s16 func_002e2740(s32 arg0);
    extern s64 func_00106b80(s32 arg0);
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp128;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    u64 sp130;
    u64 sp120;
    RGBA sp16C;
    RGBA sp168;
    RGBA sp154;
    RGBA sp150;
    RGBA sp14C;
    RGBA sp148;
    RGBA rCA0;
    RGBA rCA8;
    RGBA rC9C;
    RGBA rCA4;
    Vec2f c138;
    Vec2f cF8;
    Vec2f cD8;
    Vec2f cD0;
    u8 *work;
    u8 *pT;
    s32 tmp;
    s32 col;
    s32 c16;
    s32 div5;
    s32 msk;
    s32 nA;
    s32 h0;
    s32 h1;
    s32 sw;
    s32 sw2;
    s32 i;
    f32 var;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0xC24) != 0) {
        if (func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) >= 2) {
            if (*(s8 *)(work + 0x11) == 0) {
                if (func_002e26f0(*(void **)((u8 *)work + 0xF18)) >= 3) {
                    *(f32 *)(work + 0xC) = 91.0f / (f32)(func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) - 2);
                } else {
                    *(f32 *)(work + 0xC) = 91.0f;
                }
                var = 146.0f + *(f32 *)(work + 0xC) * (f32)(*(s16 *)(work + 2) - 1);
            } else {
                *(f32 *)(work + 0xC) = 91.0f / (f32)(func_002e26f0(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18)) - 1);
                var = 146.0f + *(f32 *)(work + 0xC) * (f32)*(s16 *)(work + 2);
            }
            func_002b2970(&sp140, 582.0f, var);
            tmp = func_002b2a30(0xFF, 0xFF, 0x6D, 0x31);
            func_002e0b20(0x36, sp140, 88.0f, tmp, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xC94)) + 0x62), 0, D_00794EA0);
            func_002e04f0(*(void **)(work + 0xC94), 0, 0);
            func_002e04f0(*(void **)(work + 0xC98), 0, 0);
        } else {
            func_002e04f0(*(void **)(work + 0xC94), 0, 1);
            func_002e04f0(*(void **)(work + 0xC98), 0, 1);
        }
        c16 = (s16)func_002e2830(*(void **)((u8 *)work + (*(s8 *)(work + 0x11) * 4) + 0xF18), *(s16 *)(work + 2));
        col = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp138, 129.0f, 134.0f);
        c138 = sp138;
        func_00275680(c138.x, c138.y, 70.0f, col, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
        div5 = func_00106a90((s16)c16) / 5;
        func_002b2970(&sp130, 486.0f, 145.0f);
        func_002b2a60(&sp16C, 0x2D, 0x2D, 0x2D, 0xFF);
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp130, 70.0f, sp16C, 0x10, 5, (u32)div5, 9, 0x7B, h0, (s32)*(void **)(work + 0xF28), 0xA9);
        func_002b2970(&sp128, 514.0f, 147.0f);
        func_002e0b20(0x47, sp128, 70.0f, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
        func_002b2970(&sp120, 545.0f, 145.0f);
        func_002b2a60(&sp168, 0x2D, 0x2D, 0x2D, 0xFF);
        msk = func_00106600((s16)c16) & 0xFF;
        h0 = (s32)func_0046a770(D_0063FB50);
        func_002cacd0(sp120, 70.0f, sp168, 0x10, 5, (u32)msk, 9, 0x7B, h0, (s32)*(void **)(work + 0xF28), 0xA9);
        if ((func_001069d0((s64)c16) & 0xFFFF) == 0) {
            for (i = 0; i < 0xF; i++) {
                func_002b2970(&sp118, (f32)(i * 0x16 + 0x6F), 178.0f);
                func_002e0b20(0x3C, sp118, 86.0f, func_002b2a30(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
            }
        } else {
            tmp = func_001069d0((s64)c16) & 0xFFFF;
            func_002bc7f0(tmp, func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 169.0f, 70.0f);
        }
        if (*(s8 *)(work + 0x11) == 1) {
            tmp = func_002d4f30((s16)func_00106880((s16)c16)) & 0xFFFF;
            func_002b2970(&sp110, 86.0f, 135.0f);
            func_002e0b20(tmp, sp110, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            sw = func_002d4f30((s16)func_00106880((s16)c16));
            switch (sw) {
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xCA0), 0x57, 83.0f);
                func_002b2a60(&rCA0, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA0));
                *(u8 *)(pT + 0x79) = rCA0.r;
                *(u8 *)(pT + 0x7A) = rCA0.g;
                *(u8 *)(pT + 0x7B) = rCA0.b;
                *(u8 *)(pT + 0x7C) = rCA0.a;
                func_002b2970(&sp108, 481.0f, 174.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA0));
                *(f32 *)(pT + 0x2C) = sp108.x;
                *(f32 *)(pT + 0x30) = sp108.y;
                func_002e09e0(*(void **)(work + 0xCA8), 0x57, 82.0f);
                func_002b2a60(&rCA8, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA8));
                *(u8 *)(pT + 0x79) = rCA8.r;
                *(u8 *)(pT + 0x7A) = rCA8.g;
                *(u8 *)(pT + 0x7B) = rCA8.b;
                *(u8 *)(pT + 0x7C) = rCA8.a;
                func_002b2970(&sp100, 481.0f, 224.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA8));
                *(f32 *)(pT + 0x2C) = sp100.x;
                *(f32 *)(pT + 0x30) = sp100.y;
                func_002b2970(&spF8, 526.0f, 202.0f);
                cF8 = spF8;
                tmp = func_001068b0((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp70, cF8.x + (f32)((s16)(nA - 1) * 8), cF8.y);
                func_002b2a60(&sp154, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp70, 22.0f, sp154, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                func_002b2970(&spE8, 526.0f, 252.0f);
                cF8 = spE8;
                tmp = func_001068e0((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp68, cF8.x + (f32)((s16)(nA - 1) * 8), cF8.y);
                func_002b2a60(&sp150, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp68, 22.0f, sp150, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                return;
            case 27:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xC9C), 0x57, 81.0f);
                func_002b2a60(&rC9C, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xC9C));
                *(u8 *)(pT + 0x79) = rC9C.r;
                *(u8 *)(pT + 0x7A) = rC9C.g;
                *(u8 *)(pT + 0x7B) = rC9C.b;
                *(u8 *)(pT + 0x7C) = rC9C.a;
                func_002b2970(&spE8, 481.0f, 174.0f);
                pT = func_002e04e0(*(void **)(work + 0xC9C));
                *(f32 *)(pT + 0x2C) = spE8.x;
                *(f32 *)(pT + 0x30) = spE8.y;
                func_002e09e0(*(void **)(work + 0xCA4), 0x57, 80.0f);
                func_002b2a60(&rCA4, 0xFE, 0xEF, 0x80, 0xFF);
                pT = func_002e04e0(*(void **)(work + 0xCA4));
                *(u8 *)(pT + 0x79) = rCA4.r;
                *(u8 *)(pT + 0x7A) = rCA4.g;
                *(u8 *)(pT + 0x7B) = rCA4.b;
                *(u8 *)(pT + 0x7C) = rCA4.a;
                func_002b2970(&spE0, 481.0f, 224.0f);
                pT = func_002e04e0(*(void **)(work + 0xCA4));
                *(f32 *)(pT + 0x2C) = spE0.x;
                *(f32 *)(pT + 0x30) = spE0.y;
                func_002b2970(&spD8, 526.0f, 202.0f);
                cD8 = spD8;
                tmp = func_00106940((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp60, cD8.x + (f32)((s16)(nA - 1) * 8), cD8.y);
                func_002b2a60(&sp14C, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp60, 22.0f, sp14C, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                func_002b2970(&spD0, 526.0f, 252.0f);
                cD0 = spD0;
                tmp = func_00106970((s16)c16) & 0xFFFF;
                nA = func_002b3170(tmp);
                func_002b2970(&sp58, cD0.x + (f32)((s16)(nA - 1) * 8), cD0.y);
                func_002b2a60(&sp148, 0x2D, 0x2D, 0x2D, 0xFF);
                h0 = (s32)func_0046a770(D_0063FB50);
                h1 = (s32)func_0046a770(D_0063FB50);
                func_002cacd0(*(u64 *)&sp58, 22.0f, sp148, 0xF, 0, (u32)tmp, 0x1E, 0x7B, h0, h1, 0xA9);
                return;
            case 28:
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 201.0f, 70.0f);
                func_002e09e0(*(void **)(work + 0xCB8), 0x57, 84.0f);
                *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
                func_002b2970(&spC8, 478.0f, 166.0f);
                pT = func_002e04e0(*(void **)(work + 0xCB8));
                *(f32 *)(pT + 0x2C) = spC8.x;
                *(f32 *)(pT + 0x30) = spC8.y;
                func_002e09e0(*(void **)(work + 0xEAC), 0x57, 84.0f);
                *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
                func_002b2970(&spC0, 477.0f, 216.0f);
                pT = func_002e04e0(*(void **)(work + 0xEAC));
                *(f32 *)(pT + 0x2C) = spC0.x;
                *(f32 *)(pT + 0x30) = spC0.y;
                return;
            }
        } else if (*(s8 *)(work + 0x11) == 0 || *(s8 *)(work + 0x11) == 2) {
            if (*(s8 *)(work + 0x11) == 2) {
                func_002b2970(&spB8, 86.0f, 135.0f);
                func_002e0ca0(0x1B, spB8, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 4, 0x57, 109.0f, 201.0f, 70.0f);
            } else {
                func_002b2970(&spB0, 86.0f, 135.0f);
                func_002e0ca0(0x1A, spB0, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
                tmp = (s16)func_00106b80(c16);
                func_002bc7f0(tmp, func_002b2a30(0xDF, 0x6C, 0, 0xFF), 1, 0, 7, 0x57, 109.0f, 201.0f, 70.0f);
            }
            func_002e09e0(*(void **)(work + 0xCB8), 0x56, 84.0f);
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
            func_002b2970(&spC8, 478.0f, 166.0f);
            pT = func_002e04e0(*(void **)(work + 0xCB8));
            *(f32 *)(pT + 0x2C) = spC8.x;
            *(f32 *)(pT + 0x30) = spC8.y;
            func_002e09e0(*(void **)(work + 0xEAC), 0x56, 84.0f);
            *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
            func_002b2970(&spC0, 477.0f, 216.0f);
            pT = func_002e04e0(*(void **)(work + 0xEAC));
            *(f32 *)(pT + 0x2C) = spC0.x;
            *(f32 *)(pT + 0x30) = spC0.y;
        }
    }
}
#pragma opt_loop_invariants off
#pragma opt_common_subs on
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002dd3b0);
#endif

/* measured: func_002de5a0's full body was reconstructed (all six 2a30/0b20
   groups, the three if/else dispatch pairs on work[7], the func_00275680
   calls with the Vec2f copies) and compiles; nd 586 across four variants,
   dominated by two mwcc b210 allocation gaps: (1) retail hoists the shared
   constants (f32)0x177 and 70.0f into callee-saved f21/f22 at the first-if
   branch tops for reuse in the second/third groups' 2970/0b20 calls, while
   mwcc rematerialises them per call site, so the candidate saves only f20
   (prologue 0x10 shorter, whole stream shifts 2 words); (2) work lands in
   $s1 instead of $s0 once the byte-index sum is written as (u32) pointer
   arithmetic. The byte-first addu ($v1,$v1,$s0) IS reproducible with
   `*(s8 *)((u8 *)(*(s8 *)(w+8) + (u32)w) + 0xF7C)`. FP-constant-hoist +
   register-coloring floor. */
/* measured: recipe B re-test 2026-08-03: full draft re-adapted; the
   f21/f22 constant hoist IS reproducible with named locals `f32 c375 =
   (f32)0x177; f32 c70 = 70.5f;` (retail hoists both at the first-if top;
   without the locals mwcc rematerialises per site), the (s32)-local c16 =
   (s16)func_00106cd0 emits retail's dsll32/dsra32 before func_001067f0, and
   the 75680/0b20 shapes match: nd 586 -> 572, frame 0x110 vs retail 0x120.
   Residual: mwcc b210 CSE-hoists `(u8 *)work + 8` and `(u8 *)work + 7` into
   saved regs $s1/$s0 (7 and 3 uses across calls; every spelling of the
   byte-index expr tried - (u32) cast, plain pointer add, reordered sum - and
   the struct-field read all fold to the same IR and hoist), so the candidate
   saves s0-s3 + f20-f22 vs retail s0-s1 + f20-f22, the frame stays 0x110 and
   every slot shifts 0x10; per-site the candidate is identical except
   lb ($s1) vs retail lb 8($s0). CSE-of-invariant-address floor. */
/* measured: bank 2026-09-17 S1 002de5a0 — object 2632B/window 2688B (2.1% short), normalized_diff 1925 MISMATCH via `python3 tools/try_bodies.py src/Event/Fcl/y_fclShopDraw.c func_002de5a0 /tmp/v_de5a0.json` (pwd source/Persona4-Decompilation); GUARDED_SCORE 583 via `python3 tools/measure_guarded.py src/Event/Fcl/y_fclShopDraw.c func_002de5a0` (differing words 583). Vec2f slots + Vec2f copies + s32 c16=(s16)106cd0 local + byte-first addu (*(s8*)((u8*)(*(s8*)(work+8)+(u32)work)+0xF7C/F73)); FP-hoist + CSE floor as prior note. */
// FUN_002DE5A0 NONMATCHING
#ifdef NON_MATCHING
void func_002de5a0(void *arg0) {
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f c100;
    Vec2f cE8;
    Vec2f cC8;
    Vec2f cB0;
    Vec2f c90;
    Vec2f c78;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 c16;
    u8 *work;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    func_002b2970(&sp118, 378.0f, 245.0f);
    func_002e0b20(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), sp118, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 0) {
        func_002b2970(&sp110, (f32)0x177, 243.0f);
        func_002e0b20(2, sp110, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&sp108, 420.0f, 246.0f);
        func_002e0b20(5, sp108, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t0 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp100, 420.0f, (f32)0x10F);
        c100 = sp100;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        func_00275680(c100.x, c100.y, 70.0f, t0, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    } else {
        func_002b2970(&spF8, (f32)0x177, 243.0f);
        func_002e0b20(2, spF8, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        func_002b2970(&spF0, 420.0f, 246.0f);
        func_002e0b20(5, spF0, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        t1 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
        func_002b2970(&spE8, 420.0f, (f32)0x10F);
        cE8 = spE8;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0);
        func_00275680(cE8.x, cE8.y, 70.0f, t1, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    }
    func_002b2970(&spE0, 378.0f, (f32)0x12F);
    func_002e0b20(0x1B, spE0, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 1) {
        func_002b2970(&spD8, (f32)0x177, (f32)0x12D);
        func_002e0b20(3, spD8, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&spD0, 420.0f, (f32)0x131);
        func_002e0b20(6, spD0, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t2 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&spC8, 420.0f, 330.0f);
        cC8 = spC8;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        func_00275680(cC8.x, cC8.y, 70.0f, t2, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    } else {
        func_002b2970(&spC0, (f32)0x177, (f32)0x12D);
        func_002e0b20(3, spC0, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        func_002b2970(&spB8, 420.0f, (f32)0x131);
        func_002e0b20(6, spB8, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        t3 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
        func_002b2970(&spB0, 420.0f, 330.0f);
        cB0 = spB0;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1);
        func_00275680(cB0.x, cB0.y, 70.0f, t3, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
    }
    func_002b2970(&spA8, 378.0f, 368.0f);
    func_002e0b20(0x1C, spA8, 69.0f, func_002b2a30(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 2) {
        func_002b2970(&spA0, (f32)0x177, 366.0f);
        func_002e0b20(3, spA0, 70.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        func_002b2970(&sp98, 420.0f, (f32)0x171);
        func_002e0b20(7, sp98, 69.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        t4 = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
        func_002b2970(&sp90, 420.0f, 394.0f);
        c90 = sp90;
        c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
        func_00275680(c90.x, c90.y, 70.0f, t4, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
        return;
    }
    func_002b2970(&sp88, (f32)0x177, 366.0f);
    func_002e0b20(3, sp88, 70.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
    func_002b2970(&sp80, 420.0f, (f32)0x171);
    func_002e0b20(7, sp80, 69.0f, func_002b2a30(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
    t5 = func_002b2a30(0xFF, 0xEF, 0x81, 0xFF);
    func_002b2970(&sp78, 420.0f, 394.0f);
    c78 = sp78;
    c16 = (s16)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2);
    func_00275680(c78.x, c78.y, 70.0f, t5, 0, 1, (const char *)func_001067f0(c16), 0, 0, D_00795E30, -1);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002de5a0);
#endif

/* Floor: 219 reloc-masked differing words (window 296 words/1184B, emitted 301 words/1204B).
   Levers that closed it from 271 to 219: u64 Vec2f slots with Vec2f direct pass
   for 002e0ca0/002e0b20 (ld $a1, not lwc1), (f32)0x1F1 for the 497 cvt.s.w chain,
   goto order 0,1,2 (L0 first, L1 second, L2 third, Ljoin) to match retail layout
   L070/L0D8/L160/L1C0, single s32 tmp + u8 *work to hold frame at retail 0xC0
   with sd $ra + sq s3/s2/s1/s0, *(u64*)(iGpffffa890-8) for the 0x763978 GP load.
   Residual is systematic (2 sites, then shift): off 32 lw $s0 vs retail $s1 and
   off 36 lb ($s0) vs ($s1) -- work wants $s1, tmp wants $s0, candidate has them
   swapped (~10 words via work+0x12/0xF28/0xCC8 and andi); off 64 bnez vs beqz +
   off 72 missing b+nop -- IROEVAL "Removing branch around goto" folds beq-over-b
   (over 1) to bnez with L0 inline (6 words before L0, not retail 8), shifting
   every later offset by 8 so fndiff marks ~200 words that are mnemonically
   identical once realigned. #pragma opt_optimizecontrolflow off/on (file and
   scoped) is ignored by b210; #pragma peephole off restores beq+b (aligned) but
   costs +46 elsewhere (265). Orders 1,2,0 score 250. Archive: v11 floor banked
   in docs/probe_archive/ShopDraw_002df020_body.c (62 lines). */
/* measured 002df020: `opt_propagation off` inside the guard is worth 4 words (219 -> 215). */
/* measured 002df020 width: block-scope (arg1 s32, 106880 s32, 0046a770 pointer; keep 106a90 s16 + outer s16) removes all six excess pairs */
/* (wscan obj 8 -> 2 matching retail) but trades 215 words / 207 edits for 232 / 191 -- do not install; remaining is work/tmp colouring, */
/* bnez vs beqz+b, GP ld and lbu schedule. Correct but not yet profitable; prerequisite for the rest. */
// FUN_002DF020 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_002df020(void *arg0, s64 arg1, s32 arg2) {
    extern u8 iGpffffa890[];
    extern u8 D_0063FAA0[];
    s32 tmp;
    u8 *work;
    RGBA spBC;
    RGBA spB8;
    RGBA spB4;
    u64 spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    u64 sp88;
    u64 sp80;
    Vec2f sp78;
    u64 sp70;
    Vec2f sp68;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0x11) == 2) {
        goto L2;
    }
    if (*(s8 *)(work + 0x11) == 1) {
        goto L1;
    }
    if (*(s8 *)(work + 0x11) == 0) {
        goto L0;
    }
    goto Ljoin;
L0:
    func_002b2970(&spA0, 97.0f, 178.0f);
    func_002e0ca0(0x1A, spA0, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L1:
    tmp = func_002d4f30((s16)func_00106880((s16)arg1)) & 0xFFFF;
    func_002b2970(&sp98, 97.0f, 178.0f);
    func_002e0b20(tmp, sp98, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    goto Ljoin;
L2:
    func_002b2970(&sp90, 97.0f, 178.0f);
    func_002e0ca0(0x1B, sp90, 13.0f, func_002b2a30(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
Ljoin:
    tmp = func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2970(&sp88, 140.0f, 178.0f);
    sp68 = *(Vec2f *)&sp88;
    func_00275680(sp68.x, sp68.y, 13.0f, tmp, 0, 1, (const char *)func_001067f0((s32)arg1), 0, 0, D_00795E30, -1);
    tmp = func_00106a90((s16)arg1) / 5U;
    func_002b2970(&sp80, 448.0f, 185.0f);
    func_002b2a60(&spBC, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(sp80, 13.0f, spBC, 0x10, 5, (u32)tmp, 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp78, 476.0f, 187.0f);
    func_002e0b20(0x47, sp78, 13.0f, func_002b2a30(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    spA8 = *(u64 *)(iGpffffa890 - 8);
    if (*(s16 *)(work + 0x12) < 10) {
        *(f32 *)&spA8 = *(f32 *)&spA8 - 8.0f;
    }
    func_002b2a60(&spB8, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002cacd0(spA8, 13.0f, spB8, 0x10, 5, *(s16 *)(work + 0x12), 9, 0x7B, (s32)func_0046a770(D_0063FB50), *(s32 *)(work + 0xF28), 0xA9);
    func_002b2970(&sp70, (f32)0x1F1, 247.0f);
    func_002b2a60(&spB4, 0xDF, 0x6C, 0, *(u8 *)((u8 *)func_002e04e0(*(void **)(work + 0xCC8)) + 0x62));
    tmp = (s32)func_0046a770(D_0063FAA0);
    func_002cacd0(sp70, 1.0f, spB4, 0x1B, 0, arg2 & 0xFF, 0x2F, 0, tmp, (s32)func_0046a770(D_0063FAA0), 0xA9);
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002df020);
#endif










// FUN_002DF4C0
void func_002df4c0(void *arg0) {
    u64 spA8;
    u64 spA0;
    u64 sp98;
    u64 sp90;
    u64 sp88;
    u64 sp80;
    u64 sp78;
    u64 sp70;
    u64 sp68;
    u64 sp60;
    u64 sp58;
    u64 sp50;
    u64 sp48;
    u64 sp40;
    u64 sp38;
    u64 sp30;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *r;

    if (work->field_C24 == 1) {
        r = func_0046d200(work->field_F28, 0x2B);
        func_002e06d0(work->field_CE4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&spA8, 67.0f, 140.0f);
        func_002b2970(&spA0, 67.0f, 140.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE4, spA8, spA0, 0, 5, 0);
        func_002e0660(work->field_CE4, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x2C);
        func_002e06d0(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp98, (f32)0x22F, 140.0f);
        func_002b2970(&sp90, (f32)0x22F, 140.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE8, sp98, sp90, 0, 5, 0);
        func_002e0660(work->field_CE8, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x28);
        func_002e06d0(work->field_CD8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CD8, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp88, 48.0f, 127.0f);
        func_002b2970(&sp80, 48.0f, 127.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CD8, sp88, sp80, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x29);
        func_002e06d0(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CDC, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp78, 584.0f, 127.0f);
        func_002b2970(&sp70, 584.0f, 127.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CDC, sp78, sp70, 0, 5, 0);
        func_0046d280((u8 *)r);
    } else {
        r = func_0046d200(work->field_F28, 0x2A);
        func_002e06d0(work->field_CE0, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp68, 63.0f, 148.0f);
        func_002b2970(&sp60, 63.0f, 148.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE0, sp68, sp60, 0, 5, 0);
        func_002e0660(work->field_CE0, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x2C);
        func_002e06d0(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002b2970(&sp58, (f32)0x222, 148.0f);
        func_002b2970(&sp50, (f32)0x222, 148.0f + 5.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CE8, sp58, sp50, 0, 5, 0);
        func_002e0660(work->field_CE8, 0xFF, 0, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x27);
        func_002e06d0(work->field_CD4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CD4, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp48, 46.0f, 136.0f);
        func_002b2970(&sp40, 46.0f, 136.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CD4, sp48, sp40, 0, 5, 0);
        func_0046d280((u8 *)r);
        r = func_0046d200(work->field_F28, 0x29);
        func_002e06d0(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        func_002e0660(work->field_CDC, 0xFF, 0, 0, 5, 0);
        func_002b2970(&sp38, (f32)0x232, 136.0f);
        func_002b2970(&sp30, (f32)0x232, 136.0f + 2.0f * (func_0046b2f0((u8 *)r) / 10.0f));
        func_002e0620(work->field_CDC, sp38, sp30, 0, 5, 0);
        func_0046d280((u8 *)r);
    }
}

// FUN_002DFD00
s32 func_002dfd00(u16 arg0) {
    if (arg0 == 0x540 || arg0 == 0x503 || arg0 == 0x596 || arg0 == 0x517 ||
        arg0 == 0x52C || arg0 == 0x555 || arg0 == 0x54D || arg0 == 0x54B ||
        arg0 == 0x56A || arg0 == 0x519 || arg0 == 0x598 || arg0 == 0x582 ||
        arg0 == 0x599 || arg0 == 0x51A || arg0 == 0x59A || arg0 == 0x580 ||
        arg0 == 0x559 || arg0 == 0x59B) {
        return 1;
    }
    return 0;
}

// FUN_002DFE00
void func_002dfe00(void *arg0) {
    s32 r;
    s32 idx;
    u16 v;
    u32 t[2];
    void *work = *(void **)((u8 *)arg0 + 0x38);

    idx = *(s16 *)((u8 *)work + 0xC18) * 2;
    r = func_00106b20(*(s16 *)(idx + (u32)work + 0x16));
    v = (u16)((r & 0xFFF00) >> 8);
    t[0] = v;
    t[1] = 0;
    if (func_002dfd00(v) == 0) {
        *(s8 *)((u8 *)work + 0x10) = func_002dfec0(arg0, 7, t, 0);
    } else {
        *(s8 *)((u8 *)work + 0x10) = func_002dfec0(arg0, 8, t, 0);
    }
}

// FUN_002DFEC0
s32 func_002dfec0(void *arg0, s32 arg1, void *arg2, s8 arg3) {
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    v = func_002bab80(*(void **)((u8 *)t + 0x110));
    if (arg2 != 0) {
        func_002bbd80(v, 0, arg2);
    }
    func_002badc0(v, arg1);
    if (arg3 == 1) {
        func_002bafc0(v, 0);
        func_002bb0a0(v, 0);
        func_002bbf60();
    }
    return v;
}

// FUN_002DFF90
s32 func_002dff90(void *arg0, s32 arg1, void *arg2, void *arg3, s8 arg4) {
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    v = func_002bab80(*(void **)((u8 *)t + 0x110));
    func_002bbd80(v, 0, arg2);
    func_002bbd80(v, 1, arg3);
    func_002badc0(v, arg1);
    if (arg4 == 1) {
        func_002bafc0(v, 0);
        func_002bb0a0(v, 0);
        func_002bbf60();
    }
    return v;
}

// FUN_002E0080
void func_002e0080(void *arg0, s8 arg1, Vec2f arg2, void *arg3) {
    func_00275520(77.0f + arg2.x, arg2.y, 1.0f, (s32)(u32)arg3, 0, 1,
                  (const char *)func_0010d6d0(arg1), 8, 0, D_00795E60);
}

/* measured: 452B/464B, only three zero-tail words. Canonical byte color and
   opacity parameters preserve constant-first loads and the float-first draw
   argument sequence. Distinct p+4 spellings preserve both retail addresses. */
// FUN_002E0100
s32 func_002e0100(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);

    func_0043f810((u8 *)work + 4, func_002b89a0(&work->field_4), 0xF0);
    if (func_002e0570(arg0, 0) == 1) {
        if (func_002e0570(arg0, 0xD) == 1) {
            void *t = func_00460990();
            *(void (**)(void))((u8 *)t + 8) = func_002be3c0;
            *(s32 *)((u8 *)t + 0x10) = 0;
            func_00460ac0(&D_00793E80[work->field_FC * 0x30], t);
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                0,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        } else {
            func_0025ecd0(
                work->field_2C, work->field_30, work->field_8,
                func_002b2a30(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                1,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        }
    }
    return 0;
}
// FUN_002E02D0
void func_002e02d0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured (this wave): func_002e0300's register layout is retail frame 0x50
   ($s0=p, $s1=arg0, $s2=arg2, $s3=arg1, loop counter $t0, base src ptr $a3,
   sign-ext index $a2). mwcc b210 balloons to frame 0x70 with $s0-$s5 for any
   natural spelling (nd 111): the `s32 a1=arg1` local + `src` local force extra
   saved regs and the loop counter lands in $a1 instead of $t0. Also confirmed
   func_0046d200's 2nd arg is (s32)sign-extended arg1 (kept in $5 across the
   loop as loop-invariant, m2c-confirmed), and func_00451fc0's callbacks need
   (void (*)(u8 *)) casts. The recorded best nd 22 (5 variants) not reachable
   via these levers. Loop-temp register-allocation floor. */
// FUN_002E0300
/* measured: retail hoists the loop-invariant 0xFF and 1.0f into the preheader. */
#pragma opt_loop_invariants on
s32 func_002e0300(s32 arg0, s16 arg1, u32 arg2) {
    s32 r;
    u8 *w;
    u8 *src;
    s16 i;
    void *h;
    func_0044ea90(&D_0063FAC0, 0x1D6A);
    w = D_008873F4[0](1, 0x104, 0x40000);
    r = func_00451fc0(arg0, (char *)&D_0063FB70, 0xF, 0, 0,
                      (void (*)(u8 *))func_002e0100, (void (*)(u8 *))func_002e02d0, w);
    w[0] = 0;
    *(s16 *)(w + 0xF8) = arg1;
    *(u32 *)(w + 0xF4) = arg2;
    src = D_0063F560 + arg1 * 8;
    for (i = 0; i < 3; i++) {
        *(f32 *)(w + i * 8 + 0x1C) = *(f32 *)src;
        *(f32 *)(w + i * 8 + 0x20) = *(f32 *)(src + 4);
        w[i + 0x60] = 0xFF;
        *(f32 *)(w + i * 4 + 0x98) = 1.0f;
        *(f32 *)(w + i * 4 + 0x8C) = 1.0f;
        *(s32 *)(w + i * 4 + 0xBC) = 0;
        w[i * 4 + 0x73] = 0xFF;
        w[i * 4 + 0x72] = 0xFF;
        w[i * 4 + 0x71] = 0xFF;
    }
    *(f32 *)(w + 8) = 100.0f;
    *(u32 *)(w + 0xFC) = 0x55;
    *(s16 *)(w + 4) = 0;
    h = func_0046d200(*(void **)(w + 0xF4), arg1);
    *(s16 *)(w + 0x100) = (s32)(func_0046b260(h) / 2.0f);
    *(s16 *)(w + 0x102) = (s32)(func_0046b2f0(h) / 2.0f);
    func_0046d280(h);
    return r;
}
// measured: closes the opt_loop_invariants bracket opened above and restores
// the -O2 baseline for the rest of the file.
#pragma opt_loop_invariants off

