#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

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
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00795E60[];
extern u8 D_00793E80[];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];
extern u8 D_0063FB70[];
extern u8 D_0063F560[];
extern u8 D_0063F9F0[];
extern f32 fGpffff7afc;
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
s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
s32 func_002e0100(void *);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
s32 func_002b2a30(s32, s32, s32, s32);
void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, void *);
s8 func_002e0570(void *, s32);
void *func_002e04e0(void *);
void func_002e04f0(void *, s32, s32);
void func_002e0620(void *, u64, u64, s32, s32, s16);
void func_002e0940(void *, f32, f32, s32, s32, s32);
void func_002b2970(void *, f32, f32);
void *func_002b5c90(void *, u64);
void *func_002e2590(void *, s32, s32, s32, s32);
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
s32 func_00275520(f32, f32, f32, void *, s32, s32, s32, s32, s32, void *);
s32 func_002dfec0(void *, s32, void *, s8);
s32 func_002dff90(void *, s32, void *, void *, s8);
u32 func_003b7060(void);
void func_0043f9c8(void *, s32, s32);
void func_0025ec90(s32, s32, s32, s32, s32, void *, f32, f32, f32);
void func_002e0700(void *, s32, f32, f32, s32, s32, s32);
void func_002e09e0(void *, s32, f32);
void func_002e0690(void *, s32, s32, s32, f32, f32);
void func_002e0660(void *, u8, u8, u8, s16, s64);
s32 func_002e26f0(void *);
void func_002e06d0(void *, f32, f32, f32, f32, s32, s32, s32);
void func_002e0b20(s32, u64, s32, s32, s32, void *, f32);
s32 func_00275680(s32, s32, s32, s32, s32, s32, void *, s32, f32, f32, f32);
void *func_001067f0(s32);
s16 func_00106cd0(s16, s16);
s32 func_002e2740(s32);
u32 func_00106880(s16);
u16 func_001068b0(s16);
u16 func_001068e0(s16);
u16 func_00106940(s16);
u16 func_00106970(s16);
s16 func_002b3170(s32);
void func_002b2a60(void *, s32, s32, s32, s32);
void func_002cacd0(u64, s32, s32, s16, u32, s64, s64, s32, f32, s32, s32);
s64 func_0046a770(void *);
s16 func_002e2830(void *, s32);
u8 func_00106600(s64);
u16 func_001069d0(s64);
s64 func_00106b80(s64);
void func_002bc7f0(s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_002e0ca0(s32, s64, s32, u8, s32, u8 *, f32);
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
void func_002e0be0(s32, u64, s32, s32, s32, void *, f32);
u32 func_002e7a60(void);
u32 func_00106a90(s32);
s32 func_00110830(s32);
void func_0045af60(s32, s32, s32, s32);
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

/* measured (this wave): func_002caa10's true signature is 7 args
   (s64, s32, u32, s64, void*, s32, f32) -- m2c-confirmed, matches its usage;
   no lever-1 defect. Same digit-draw family as func_002cacd0 (10 saved regs,
   frame 0xF0, color bytes in $s0/$s1/$s7, func_0025ec90/func_002b2a30 arg
   shapes). Four variants compiled with the full body (s64 spB0/spC0 slots at
   16-aligned offsets read via lq/sq, s16 arg3 sign-extension, s8 loop
   counter) and every instruction family matches retail -- best nd 141. The
   remaining deltas are stack-slot placement and saved-reg choice only: mwcc
   b210 assigns stack slots in FIRST-USE order high-to-low (arg0's u64 slot
   and the 0xDC color/arg1 struct must be ONE 0x20 struct starting at 0xD0,
   with func_00442830's target at 0xE0 = &st.tail), and the loop counter wants
   s32 with an (s8) truncation cast. Four-attempt budget exhausted;
   layout+coloring floor. */
// FUN_002CAA10
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002caa10);

/* Signature audit: func_002cacd0 currently has 11 parameters
   (u64, s32, s32, s16, u32, s64, s64, s32, f32, s32, s32), corroborated by
   generated/code1_002c.c:183. The previously noted 12-argument diagnosis
   is historical and closed; no prototype change remains. */
// FUN_002CACD0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cacd0);
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
/* measured (this wave re-test): three fresh spellings from the m2c draft --
   individual u64 slots (nd 462), Vec2f *b reassigned per group over u64
   slots (nd 461), Vec2f buf[19] + `Vec2f *b` reassigned over the array
   (nd 463) -- all reproduce the documented pre-recipe-B baseline, NOT the
   recipe-B nd 9; the exact working structure from the re-test note above is
   not recoverable from the description (the global-base-cache-in-$s0 aspect
   requires the D_0063F5xx insns themselves, which mwcc rematerialises).
   Confirmed lever-1: func_002e0660 is (void*, u8, u8, u8, s16, s64) and
   func_002e0690 is (void*, s32, s32, s32, f32, f32) -- both match their
   declarations. Func_002e26f0 extern is s16 -- matches retail's per-site
   sign-extension split. Continuous scheduling+hoist floor. */
// FUN_002D3EE0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d3ee0);

// FUN_002D4760
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d4760);

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

/* measured: func_002d5040's full body was reconstructed (the 2a30/0b20/75680
   chain, the three-case switch on work[7], the eight func_002cacd0 digit
   calls) and compiles; nd 814 after four variants, dominated by ONE missing
   instruction per 75680 group: retail sign-extends the func_002e2740/
   func_00106cd0 result (dsll32/dsra32 16) before func_001067f0, and mwcc b210
   emits nothing for an (s16) cast passed straight into a call arg (tried s16
   and s32 params on func_001067f0) -- the value must be assigned to an s32
   local first, `s32 c16 = (s16)func_002e2740(...);` (the func_002caa10 t21
   pattern, which does emit the pair), then passed. That one word per group
   shifts the rest of the stream; the lbu-vs-lb on the work[8]/work[7] byte
   reads should then fall out of the alignment. Four-attempt budget
   exhausted; missing-sign-extension floor. */
/* lever-1 audit (this wave): func_002d5040 is void (void *arg0); the 8
   func_002cacd0 calls now use the corrected 12-arg decl (last s32 arg_sp8 =
   D_00793E80 + arg_sp8*0x30, was missing). func_001067f0 is void*(s32) and
   func_002e2740 is s32(s32) -- both match; the documented fix (s32 c16 =
   (s16)func_002e2740(...) local before func_001067f0) still stands. */
// FUN_002D5040
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d5040);

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
/* lever-1 audit (this wave): func_002d6190 is void (void *arg0) -- confirmed
   by generated-draft call sites (arg0 only). All color-helper externs checked
   against m2c: func_002e0660 (void*,u8,u8,u8,s16,s64), func_002e0690
   (void*,s32,s32,s32,f32,f32), func_002e0b20/func_002e0be0 (s32,u64,s32,s32,
   s32,void*,f32), func_00275680 (11-arg) -- all match declarations. No
   extern-width defect. */
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
// FUN_002D7300
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d7300);



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
    func_002e0700(work->field_EC4, 3, fGpffff7afc, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EC8, 4, fGpffff7afc, 1.0f, 6, 0, 1);
    func_002e0700(work->field_E38, 0x80, fGpffff7afc, 1.0f, 6, 0, 1);
    func_002e0700(work->field_EB4, 3, fGpffff7afc, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EB8, 4, fGpffff7afc, 1.0f, 6, 1, 1);
    func_002e0700(work->field_CC4, 0x23, fGpffff7afc, 1.0f, 6, 1, 1);
    func_002e0700(work->field_EBC, 3, fGpffff7afc, 1.0f, 6, 2, 1);
    func_002e0700(work->field_EC0, 4, fGpffff7afc, 1.0f, 6, 2, 1);
    func_002e0700(work->field_CC0, 0x22, fGpffff7afc, 1.0f, 6, 1, 1);
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
// FUN_002DD3B0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002dd3b0);

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
/* lever-1 audit (this wave): func_002de5a0 is void (void *arg0). func_00275680
   is 11-arg s32(...) and func_002e0b20 is (s32,u64,s32,s32,s32,void*,f32) --
   both match m2c; func_00106cd0 is s16(s16,s16) matching the c16 sign-extension
   pattern. No extern-width defect. */
// FUN_002DE5A0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002de5a0);

// FUN_002DF020
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002df020);










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
    func_00275520(77.0f + arg2.x, arg2.y, 1.0f, arg3, 0, 1,
                  func_0010d6d0(arg1), 8, 0, D_00795E60);
}

/* measured (lever 1, this wave): func_0025ecd0's true signature is
   (s32 x7, f32 x6, void *) -- the pointer is the LAST arg in $11, verified
   from its own prologue ($4-$10, $f12-$f17, $11). The old decl had void* in
   position 8, scrambling arg evaluation order; fixed. Residual register floor:
   retail keeps arg0=$s1/p=$s0 (frame 0x30) and recomputes p+4 per call; mwcc
   CSEs p+4. Field-spelling `&p->field_4` for one call + (u8*)p+4 for the
   other broke that CSE: nd 94 -> 65 (obj 444B vs window 464B). Remaining:
   func_002b2a30 constant-first arg order (retail addiu $a0 first, mwcc lbu
   first) and func_0025ecd0's arg-load order [3, 8, f12-f14, 1, 2, 4, 5, 6, 7,
   f15-f17] vs mwcc's declaration order. Arg-scheduling floor. */
// FUN_002E0100
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002e0100);
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

