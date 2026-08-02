#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct { f32 x, y; } Vec2f;
typedef struct {
    u8 pad0[0xCF];
    u8 field_CF;
    u8 pad1[0x30];
    s16 field_100;
    s16 field_102;
    u8 pad2[0xD28];
    void *field_E2C;
    void *field_E30;
    u8 pad3[0x2C];
    void *field_E60;
    u8 pad4[0xC4];
    void *field_F28;
} ShopWork;

extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00795E60[];
extern u8 D_00793E80[];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];

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
void func_00460ac0(void *);
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
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002ca830);

// FUN_002CAA00
void func_002caa00(void *arg0, s8 arg1) {
    *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38)) = arg1;
}

// FUN_002CAA10
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002caa10);

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

// FUN_002D5040
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d5040);

// FUN_002D6190
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d6190);

// FUN_002D7300
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d7300);

// FUN_002D7C10
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d7c10);

// FUN_002D7F90
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d7f90);

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
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d83c0);

// FUN_002D8600
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d8600);

// FUN_002D8A60
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002d8a60);

// FUN_002DA0A0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002da0a0);

// FUN_002DB400
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002db400);

// FUN_002DD230
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002dd230);

// FUN_002DD3B0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002dd3b0);

// FUN_002DE5A0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002de5a0);

// FUN_002DF020
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002df020);

// FUN_002DF4C0
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002df4c0);

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

// FUN_002E0100
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002e0100);

extern void (*jtbl_008873EC[])(void *ptr);

// FUN_002E02D0
void func_002e02d0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E0300
INCLUDE_ASM("asm/nonmatchings/y_fclShopDraw", func_002e0300);
