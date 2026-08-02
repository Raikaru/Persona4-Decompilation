/* Consolidated Persona 4 source units. */
/* Original translation unit cmpSkill.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    Vec3f v;
} StSkill;

s16 func_0010b510(void);
u16 func_0010b6f0(void);
s32 func_0010ace0(s16);
void func_0010b3b0(s16);
s32 func_00113520(s32, s32, s32, void *);
s32 func_0010a900(u16);
u16 *func_001094d0(s32);
void func_0010fa80(s32, s32, u16, s32, s32 *, s32, s32);
void func_001437b0(void *, s16, s32);
void func_0046d280(void *);
s32 func_0034c210(void);
s32 func_003b7060(void);
s16 func_0023d8e0(void *, s16);
void func_0034f1e0(void);
void func_0034c270(Vec2f, u8, f32);
void func_0034f320(void *, u8, u8, u8, s32, s32, s32, s32, f32, f32, f32, f32, f32);
void func_0034f2e0(void *, u8, u8, u8, s32, f32, f32);
void func_0034f9d0(Vec2f, u8, s16, void *, f32);
void func_0013b370(void *, Vec2f, u32);
void func_0013b420(void *, Vec2f, s32, void *);
void func_00113730(void *);
void func_00113790(Vec2f, u8, void *, s32, f32);
void func_0013ad40(void *, s32, s32);
extern u8 D_00762DC0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
void *func_0046a770(char *);
s32 func_0046d200(void *, u8);
s16 func_00353b50(void *);
void func_0046d730(char *, s32);
void func_0043f9c8(void *, s32, s32);
s32 func_0013a040(s16 *, s32, s16);
void func_0013a060(void *);
void func_0013a4a0(void *);
void func_00138bf0(void *);
s32 func_0013a530(void *, s32);
void func_00138490(void *);
extern char D_005ED9C0[];
extern char D_005E57F0[];
extern char D_005E5830[];
extern char D_005E5850[];
extern u8 D_005ED750[];
extern u8 D_005EB5D0[];
extern u8 D_005EBA00[];
extern u8 D_005EBE30[];
extern u8 D_005EC260[];
extern u8 D_005EC690[];
extern u8 D_005ECAC0[];
extern u8 D_005ECEF0[];
extern u8 D_005ED320[];
extern u8 D_005ED790[];
extern f32 DAT_00761640;

// FUN_00137FB0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00137fb0);

// FUN_00138490
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138490);

// FUN_00138AD0
s32 func_00138ad0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00138B20
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138b20);

// FUN_00138BF0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138bf0);

// FUN_0013A040
s32 func_0013a040(s16 *arg0, s32 arg1, s16 arg2)
{
    arg0[arg1 + 0x54] = arg0[arg1 + 0x2E];
    arg0[arg1 + 0x2E] = arg2;
    return 1;
}

// FUN_0013A060
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a060);

// FUN_0013A4A0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a4a0);

// FUN_0013A530
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a530);

// FUN_0013A8A0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a8a0);

// FUN_0013A930
void func_0013a930(void *arg0)
{
    f32 f0;
    f32 f1;
    *(u32 *)((u8 *)arg0 + 0x11E4) = 0x437F0000;
    *(u32 *)((u8 *)arg0 + 0x11EC) = 0x437F0000;
    *(u32 *)((u8 *)arg0 + 0x11F4) = 0x437F0000;
    *(u8 *)((u8 *)arg0 + 0x11FC) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x11FE) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x11FD) = 0;
    *(u32 *)((u8 *)arg0 + 0x1220) = 0;
    if (*(s16 *)((u8 *)arg0 + 0x60) > *(s16 *)((u8 *)arg0 + 0xAC)) {
        f0 = 21.0f + *(f32 *)((u8 *)arg0 + 0x8F8);
        *(f32 *)((u8 *)arg0 + 0x11F8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11E8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11F0) = *(f32 *)((u8 *)arg0 + 0x11F8) - 10.0f;
        *(u32 *)((u8 *)arg0 + 0x1218) = 0xC1200000;
    } else {
        f1 = 21.0f + *(f32 *)((u8 *)arg0 + 0x9E8);
        f0 = 170.0f + f1;
        *(f32 *)((u8 *)arg0 + 0x11F8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11E8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11F0) = 10.0f + *(f32 *)((u8 *)arg0 + 0x11F8);
        *(u32 *)((u8 *)arg0 + 0x1218) = 0x41200000;
    }
    *(s16 *)((u8 *)arg0 + 0x22) = 0;
}

// FUN_0013AA00
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013aa00);

// FUN_0013AA90
void func_0013aa90(void *arg0)
{
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(func_003b7060() & 1)) {
            u8 *q = (u8 *)arg0 + i * 0x30;
            *(s16 *)(q + 0xCC2) = 0xFA;
            *(s16 *)(q + 0xCC8) = 0x190;
            *(u32 *)(q + 0xCA4) = 0xC1F00000;
            *(u32 *)(q + 0xCA8) = 0xC1F00000;
            *(u32 *)(q + 0xCAC) = 0xC1F00000;
            *(u32 *)(q + 0xCB0) = 0xC1F00000;
            *(u32 *)(q + 0xCD0) = 10;
            *(s16 *)((u8 *)arg0 + i * 2 + 0x24) = 0;
        }
    }
}

// FUN_0013AB30
void func_0013ab30(u8 *arg0)
{
    s32 i;
    s32 *slot;

    for (i = 0; i < 0x3C; i++) {
        slot = (s32 *)(arg0 + i * 4 + 0x1244);
        if (*slot != 0) {
            func_0046d280((void *)*slot);
            *slot = 0;
        }
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}

// FUN_0013ABB0
s32 func_0013abb0(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 threshold;

    /* i is zeroed before the threshold load, and threshold is held as s32:
       an s16 local makes mwcc re-sign-extend it on every iteration. */
    result = 1;
    i = 0;
    threshold = *(s16 *)(arg0 + 0x20);
    while (i < 0x26) {
        if (threshold < *(s32 *)(arg0 + i * 48 + 0x5B0)) {
            result = 0;
        }
        i++;
    }
    return result & func_0034c210();
}

// FUN_0013AC30
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013ac30);

