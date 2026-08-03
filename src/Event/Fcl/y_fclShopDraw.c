#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct { f32 x, y; } Vec2f;
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline f32 shopAdd(f32 left, f32 right) { return left + right; }
typedef struct {
    u8 pad0a[2];
    s16 field_2;
    u32 field_4;
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
    u8 padD2[0x34];
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
extern u8 D_0063F650[];
extern u8 D_0063F658[];
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
extern u8 D_0063FB50[];

void func_002be530(void);
void func_002be3c0(void);
s32 func_0010d6d0(s16);
void func_00105780(s32);
s32 func_00106b20(s16);
void func_0044ea90(const void *, u32);
s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
s32 func_002b2a30(s32, s32, s32, s32);
void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
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
s16 func_002e26f0(void *);
void func_002e06d0(void *, f32, f32, f32, f32, s32, s32, s32);
void func_002e0b20(s32, u64, s32, s32, s32, void *, f32);
s32 func_00275680(f32, f32, f32, s32, s32, s32, void *, s32, s32, void *, s32);
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
void func_002cacd0(u64, s32, s32, s32, u32, s32, s32, s32, f32, s64, s64);
s32 func_0046a770(void *);

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

/* measured: func_002caa10 is a digit-draw loop; four variants compiled with the
   full body (s64 spB0/spC0 slots at 16-aligned offsets read via lq/sq, s16
   arg3 sign-extension, s8 loop counter, func_0025ec90/func_002b2a30 arg
   shapes) and every instruction family matches retail -- best nd 141. The
   remaining deltas are stack-slot placement and saved-reg choice only: mwcc
   b210 assigns stack slots in FIRST-USE order high-to-low (arg0's u64 slot
   and the 0xDC color/arg1 struct must be ONE 0x20 struct starting at 0xD0,
   with func_00442830's target at 0xE0 = &st.tail), and the loop counter wants
   s32 with an (s8) truncation cast (addiu first, then dsll32/dsra32 by 24).
   Four-attempt budget exhausted; layout+coloring floor. */
// FUN_002CAA10
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002caa10);

/* measured: digit-draw loop identical to func_002caa10 family; retail sets up
   func_0025ec90's args as [arg3, f12-f14, arg1, arg2, arg4, arg5, arg6] and
   func_002b2a30's constant 0xFF first; mwcc b210 emits FP args last and the
   constant last (same two families as y_fclItemShopDraw func_0033cc40 and
   func_002e0100 notes), and spills the three color-byte locals to 16B slots
   while retail keeps them in $s0/$s1/$s6 (register pressure from arg5/arg6
   saves; tried s32 locals + address-taken byte reads, nd 56). Arg-eval-order
   floor. */
// FUN_002CACD0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cacd0);

// FUN_002CAEF0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002caef0);

// FUN_002CB6A0
s32 func_002cb6a0(void *arg0) {
    return *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38) + 0xF30) == 1;
}

// FUN_002CB6C0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cb6c0);

// FUN_002CDF80
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002cdf80);

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
// FUN_002D3EE0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d3ee0);

/* measured: func_002d4760's full body was reconstructed (six 8-aligned stack
   arrays f0/e0/d8/d0/c0/b8 at 0xF0..0xB8, arg1 spill at 0xB7, both loops, the
   three-case switch with ascending case layout) and compiles; nd 417 in all
   four variants. mwcc b210 allocates a phantom 16-byte slot at 0xB0 (sq in
   the i==arg1 branch / lq at the loop head, value never truly used) which
   pushes the array region up 0x10 (frame 0x110 vs retail 0x100), shifting
   every store offset; also reloads the spilled arg1 byte per iteration
   instead of sign-extending once at entry, and reads D_00748908[i] with lbu
   vs retail's lb. Stack-slot + 16-byte-temp floor. */
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
// FUN_002D5040
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d5040);

// FUN_002D6190
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d6190);

/* measured: retail hoists the D_0063F658/D_0063F650 base into $s1 across
   the func_002b2970 calls; mwcc b210 rematerialises lui/addiu per call (tried
   inline globals, u8-star/f32-star named base, #pragma opt_loop_invariants,
   nd 495; the missing $s1 save shrinks the frame 0x10 and shifts all 46 u64
   slots). Global-address-hoist floor (D_00887300 family). */
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

// FUN_002D8A60
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d8a60);

// FUN_002DA0A0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002da0a0);

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

/* measured: retail evaluates func_0025ecd0's 14 args in the order [3, 8,
   f12-f14, 1, 2, 4, 5, 6, 7, f15-f17]; mwcc b210 emits [2, 3, 4, 6, 7, 8, 1, 5,
   f12-f14, f15-f17] regardless of spelling (inline, hoisted local, struct
   fields). Same family as y_fclItemShopDraw func_0033cc40 floor note; also the
   func_002b2a30 constant-first arg order. nd 45. Argument-evaluation-order
   scheduling floor. */
// FUN_002E0100
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002e0100);

// FUN_002E02D0
void func_002e02d0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured: retail keeps loop-invariant ptr D_0063F560+arg1*8 in $a3 and s16
   counter in $t0 with sign-extended index in $a2; mwcc b210 allocates the same
   three temps to $a2/$a3/$v1 for every declaration order tried (5 variants,
   best nd 22). Loop temp register allocation floor. */
// FUN_002E0300
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002e0300);
