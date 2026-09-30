/* Consolidated Persona 4 source units. */
/* Original translation unit cmpSkill.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "shd_misc_internal.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

/* The label dispatcher initializes these three halfwords; the skill renderer
   consumes the 12-byte payload as an ID and two value words. Its float view
   preserves the retail three-word aggregate transfer without numeric conversion. */
typedef struct {
    s16 kind;
    s16 style;
    s16 flags;
    Vec3f payload;
} SkillMenuDescriptor;

typedef struct {
    u8 red, green, blue, alpha;
} SkillMenuColor;

typedef struct {
    f32 x, y;
    f32 width, height;
    s32 paletteIndex;
} SkillDecoration;

s16 func_0010b510(void);
u16 func_0010b6f0(void);
s32 func_0010ace0(s16);
void func_0010b3b0(s16);
s32 func_00113520(s32, s32, s32, void *);
u16 *func_0010a900(u16);
u16 *datPersonaGetSkills(s32);
void func_0010fa80(s32, s32, u16, s32, s32 *, s32, s32);
void func_001437b0(void *, s32, s32);
void func_0046d280(void *);
s32 func_0034c210(void);
u32 RpRandom(void);
s32 func_0023d8e0(u8 *, u16);
void func_0034f1e0(void);
void func_0034c270(Vec2f, s32, s32, f32);
void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u8 arg4,
                   u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
void func_0034f2e0(void *, f32, f32, u8, u8, u8, u8);
void func_0034f9d0(Vec2f unused, f32 fparg0, u8 arg1, s32 arg2, s32 arg3);
void func_0013b370(u8 *work, Vec2f position, PackedColor4 color);
void func_0013b420(void *, Vec2f, s32, void *);
void func_00113730(s16 *);
void func_00113790(Vec2f, u8, void *, s32, f32);
void func_0013ad40(u8 *, s32, s32);
/* Two RGBA decoration colors. Retail copies exactly eight bytes; the next
   small-data object starts at 0x00762DC8. */
extern u8 D_00762DC0[8];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
void *func_0046a770(char *);
s32 func_0046d200(void *, u8);
s16 func_00353b50(void *);
void func_0046d730(char *, s32);
void memset(void *, s32, s32);
s32 func_0013a040(s16 *, s32, s32);
void func_0013a060(void *);
void func_0013a4a0(void *);
void func_00138bf0(u8 *);
s32 func_0013a530(u8 *, s32);
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

/* measured: the signed 16-bit bitfield keeps retail's dsll32/dsra32
   narrowing while the s32 loop carriers reproduce its saved-register
   allocation. The ordered asset-id loads and chained third-asset assignment,
   with the two measured optimization settings below, close all 1248 bytes. */
// FUN_00137FB0
/* measured: opt_propagation off preserves the retail constant and argument-load schedule. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on hoists the table and conversion constants like retail. */
#pragma opt_loop_invariants on
void func_00137fb0(u8 *arg0)
{
    s16 i;
    s16 j;
    s16 k;
    s32 m;
    s32 m_index;
    u8 *src;
    u8 *dst;
    u8 asset_id;
    f32 value;
    void *asset0;
    void *asset1;
    void *asset2;
    s32 *slot;
    s32 n;
    struct {
        s32 half : 16;
    } narrow;

    memset(arg0, 0, 0x1338);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *arg0 = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;

    for (i = 0; i < 4; i++) {
        *(s16 *)(arg0 + i * 2 + 0x5C) = 0;
    }

    for (j = 0; j < 0x26; j++) {
        src = D_005EBA00 + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x594) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x598) = *(f32 *)(src + 4);
        *(u8 *)(dst + 0x59E) = *(u8 *)(src + 0x10);
        value = *(f32 *)(src + 8);
        *(u16 *)(dst + 0x5A4) = (u16)value;
        value = *(f32 *)(src + 0xC);
        *(u16 *)(dst + 0x5AA) = (u16)value;
    }

    for (k = 0; k < 0x1C; k++) {
        dst = arg0 + k * 0x30;
        *(s32 *)(dst + 0xCB4) = 0;
        *(s32 *)(dst + 0xCB8) = 0;
        *(u8 *)(dst + 0xCBE) = 0;
        *(s32 *)(dst + 0xCCC) = 0;
        *(s32 *)(dst + 0xCD0) = 8;
        if (k % 0xE < 6) {
            *(s16 *)(dst + 0xCC0) = 0x64;
            *(s16 *)(dst + 0xCC2) = 0x64;
            *(s16 *)(dst + 0xCC6) = 0x64;
            *(s16 *)(dst + 0xCC8) = 0x64;
            *(u8 *)(dst + 0xCBC) = 0;
            *(u8 *)(dst + 0xCBD) = 0xFF;
        } else {
            *(s16 *)(dst + 0xCC0) = 0x64;
            *(s16 *)(dst + 0xCC2) = 0xB4;
            *(s16 *)(dst + 0xCC6) = 0x64;
            *(s16 *)(dst + 0xCC8) = 0xB4;
            *(u8 *)(dst + 0xCBC) = 0;
            *(u8 *)(dst + 0xCBD) = 0x7F;
        }
        *(s16 *)(arg0 + k * 2 + 0x24) = (k * 3) % 8;
    }

    m = 0;
    goto loop4_test;
loop4_body:
    narrow.half = m;
    m_index = narrow.half;
    dst = arg0 + m_index * 0x30;
    *(s32 *)(dst + 0x11F4) = 0;
    *(s32 *)(dst + 0x11E4) = 0;
    *(s32 *)(dst + 0x11F0) = 0;
    *(s32 *)(dst + 0x11E8) = 0;
    *(u8 *)(dst + 0x11FD) = 0;
    *(u8 *)(dst + 0x11FC) = 0;
    *(s32 *)(dst + 0x120C) = 0;
    *(s32 *)(dst + 0x1210) = 3;
    m = (s16)(m + 1);
loop4_test:
    if ((s16)m < 2) {
        goto loop4_body;
    }

    *(s16 *)(arg0 + 0xFC) = func_00353b50(arg0 + 0xF4);
    *(s16 *)(arg0 + 0x580) = 0;

    asset0 = func_0046a770(D_005E5830);
    if (asset0 == 0) {
        func_0046d730(D_005ED9C0, 0x25F);
    }
    asset1 = func_0046a770(D_005E5850);
    if (asset1 == 0) {
        func_0046d730(D_005ED9C0, 0x261);
    }
    *(void **)(arg0 + 0x1334) = asset2 = func_0046a770(D_005E57F0);
    if (asset2 == 0) {
        func_0046d730(D_005ED9C0, 0x263);
    }

    n = 0;
    goto resolve_test;
resolve_body:
    if (narrow.half < 0x1B) {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset0, asset_id);
    } else if (narrow.half < 0x3A) {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset1, asset_id);
    } else {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset2, asset_id);
    }
    if (*slot == 0) {
        func_0046d730(D_005ED9C0, 0x270);
    }
    narrow.half = n + 1;
    n = narrow.half;
resolve_test:
    narrow.half = n;
    if (narrow.half < 0x3C) {
        goto resolve_body;
    }

    func_0013a530(arg0, 0);
    func_00138490(arg0);
}
/* measured: restore propagation after matching func_00137fb0. */
#pragma opt_propagation on
/* measured: restore loop-invariant optimization after matching func_00137fb0. */
#pragma opt_loop_invariants off

/* Ability-list record at +0x100 of the work area: id, sort key, two payload words. b210 copies any
   12-byte struct with a float member through $f0-$f2 (loads first, then stores), which is the retail
   record copy. */
typedef struct SkillRec
{
    s16 id;
    u16 key;
    f32 a;
    f32 b;
} SkillRec;
/* Inline search of a persona's eight-entry skill list; the 1/0 returns keep the result in $v0 exactly
   as the two retail copies do. */
static inline s32 campSkillListHas(u16 *skills, u16 skill)
{
    s32 k;

    for (k = 0; k < 8; k++) {
        if (skills[k] == skill) {
            return 1;
        }
    }
    return 0;
}
/* measured: matches with opt_loop_invariants on. With it off the compare `sel != -1` re-extends the s16
   inside the pair loops and the frame is 0xD0; with it on the extension is hoisted and spilled (sq 0xC0),
   which is retail's 0x100 frame with three quadword spills (0xA0 q key pointer, 0xB0 cur, 0xC0 sel).
   Loop shapes that matter: the query, dedupe and sort passes each keep their own index variables, the
   dedupe removes the last entry through a fresh pointer (e) and steps n back, the sort's range tests
   use `> 0xFF` for the second bound, and the record-table lookup names the doubled index in a local so
   b210 emits `addu index,base`. The fa80 calls pass the original mode value v, not a list result. */
// FUN_00138490
#pragma push
#pragma opt_loop_invariants on
void func_00138490(void *arg0)
{
    s16 sel;
    s32 m;
    SkillRec *qr;
    u8 *b = (u8 *)arg0;
    s32 v;
    s32 count;
    s32 n;
    s32 r;
    s32 t;
    s32 w;
    s32 i;
    u8 *p;
    s32 j;
    u8 *q;
    u8 *e;
    s32 key;
    s32 cur;
    u16 *kp;
    s32 res;
    s32 x;
    s32 y;
    SkillRec innerTmp;
    SkillRec outerTmp;

    sel = -1;
    count = 0;
    v = *(s16 *)((u8 *)arg0 + 0x5C);
    {
        s32 off = v * 2;
        v = *(s16 *)((u8 *)(off + (s32)arg0) + 0xF4);
    }
    if (v == 1) {
        sel = func_0010b510();
        for (i = 0; i < func_0010b6f0(); i++) {
            w = func_0010ace0((s16)i);
            if (w != 0) {
                func_0010b3b0((s16)i);
                for (j = 0; j < 8; j++) {
                    p = b + count * 12;
                    if (func_00113520(1, w, j, p + 0x100) != 0) {
                        *(s16 *)(p + 0x100) = (s16)i;
                        count++;
                    }
                }
            }
        }
    } else {
        w = (s32)func_0010a900((u16)v);
        for (i = 0; i < 8; i++) {
            p = b + count * 12;
            if (func_00113520(v, w, i, p + 0x100) != 0) {
                *(s16 *)(p + 0x100) = -1;
                count++;
            }
        }
    }
    for (m = 0; m < count; m++) {
        p = b + m * 12;
        cur = *(u16 *)(p + 0x102);
        for (n = m + 1; n < count; n++) {
            q = b + n * 12;
            kp = (u16 *)(q + 0x102);
            key = *kp;
            if (cur == key) {
                if (cur < 0x1B8 && sel != -1) {
                    res = campSkillListHas(datPersonaGetSkills(func_0010ace0(*(s16 *)(p + 0x100))), 0x20A);
                    if (res == 0) {
                        qr = (SkillRec *)(q + 0x100);
                        res = campSkillListHas(datPersonaGetSkills(func_0010ace0(*(s16 *)(q + 0x100))), 0x20A);
                        if (res != 0) {
                            *(SkillRec *)(p + 0x100) = *qr;
                        } else {
                            func_0010b3b0(*(s16 *)(p + 0x100));
                            func_0010fa80(v, v, *(u16 *)(p + 0x102), 0, &x, 0, 0);
                            func_0010b3b0(qr->id);
                            func_0010fa80(v, v, *kp, 0, &y, 0, 0);
                            if (x < y) {
                                *(SkillRec *)(p + 0x100) = *qr;
                            }
                        }
                    }
                }
                count--;
                e = b + count * 12;
                *(SkillRec *)(q + 0x100) = *(SkillRec *)(e + 0x100);
                n--;
                *(s32 *)(e + 0x104) = 0;
                *(s32 *)(e + 0x108) = 0;
                *(u16 *)(e + 0x102) = 0;
                *(s16 *)(e + 0x100) = -1;
            }
        }
    }
    *(s16 *)(b + 0x580) = (s16)count;
    for (r = 0; r < count; r++) {
        u8 *outer;
        outer = b + r * 12;
        outerTmp = *(SkillRec *)(outer + 0x100);
        for (t = r + 1; t < count; t++) {
            u8 *inner;
            SkillRec *ip;

            inner = b + t * 12;
            ip = (SkillRec *)(inner + 0x100);
            innerTmp = *(SkillRec *)(inner + 0x100);
            if (innerTmp.key >= 0xC0 && innerTmp.key < 0x100) {
                if (outerTmp.key >= 0xC0 && outerTmp.key < 0x100) {
                    if (innerTmp.key < outerTmp.key) {
                        *(SkillRec *)(outer + 0x100) = innerTmp;
                        *ip = outerTmp;
                        outerTmp = innerTmp;
                    }
                } else {
                    *(SkillRec *)(outer + 0x100) = innerTmp;
                    *ip = outerTmp;
                    outerTmp = innerTmp;
                }
            } else if (outerTmp.key < 0xC0 || outerTmp.key > 0xFF) {
                if (innerTmp.key < outerTmp.key) {
                    *(SkillRec *)(outer + 0x100) = innerTmp;
                    *ip = outerTmp;
                    outerTmp = innerTmp;
                }
            }
        }
    }
    if (sel != -1) {
        func_0010b3b0(sel);
    }
    if (*(s16 *)(b + 0x580) > 0x60) {
        func_0046d730(D_005ED9C0, 0x336);
    }
    func_0013a040((s16 *)arg0, 1, 0);
    func_0013a040((s16 *)arg0, 2, 0);
}
#pragma pop

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
s32 func_00138b20(u8 *arg0)
{
    s32 i;
    s32 result = 1;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 0x26; i++) {
        p = arg0 + i * 0x30;
        v = *(s16 *)(arg0 + 0x20);
        func_001437b0(p + 0x584, v, 0);
        if (*(u8 *)(p + 0x59E) != 0) {
            result = 0;
        }
    }
    func_0013a060(arg0);
    func_0013a4a0(arg0);
    func_00138bf0(arg0);
    return result;
}
/* One 0x30-byte entry in the menu's animation arrays. The initializer,
   transition setup and updater jointly establish these fields. */
typedef struct {
    f32 sourceX, sourceY, targetX, targetY;
    f32 x, y;
    u8 sourceAlpha, targetAlpha, alpha, flags;
    u16 sourceScaleX, targetScaleX, scaleX;
    u16 sourceScaleY, targetScaleY, scaleY;
    s32 mode, duration;
} SkillMenuAnimation;

typedef struct {
    u8 alpha;
    u8 _01[3];
    f32 x, y;
    s32 _0c;
    s32 background;
    s32 _14[2];
    u32 visible;
    u8 _20[0x3e];
    s16 selectedRow;
    s16 scrollRow;
    u8 _62[0x9a];
    s16 partyCount;
    s16 _fe;
    union { SkillRec fields; Vec3f copy; } skills[96];
    s16 skillCount;
    s16 footerMode;
    SkillMenuAnimation animation[68];
    void *sprites[60];
    union { void *texture; s32 handle; } footer;
} SkillMenuView;

/* Preserve the observed left/right evaluation order of the three sums. */
static inline f32 skillPositionAdd(f32 left, f32 right)
{
    return left + right;
}

/* Draw the skill menu, including animated decorations, selection rows,
   scrolling controls and the pending skill overlay. The shared position,
   packed color and complete descriptor are the retail stack objects.
   measured: 5192 exact instruction bytes and an eight-byte zero tail.
   Lifetimes preserve the real resource reuse; disabling constant pulling
   retains per-draw float constants, and propagation-off preserves sprite
   snapshots before their coordinate calculations. */
// FUN_00138BF0
#pragma push
#pragma opt_lifetimes on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
void func_00138bf0(u8 *work)
{
    extern s32 func_0013ac30(u16 skill);
    SkillMenuView *menu;
    s32 rowIndex;
    f32 opacity;
    f32 originX;
    f32 originY;
    u8 spriteAlpha;
    f32 value;
    f32 offset;
    PackedColor4 color;
    Vec2f position;
    SkillMenuColor palette[2];
    SkillMenuDescriptor descriptor;
    SkillMenuColor *decorationColor;
    s32 payloadIndex;

    menu = (SkillMenuView *)work;
    func_0034f1e0();
    originX = menu->x;
    originY = menu->y;
    opacity = (f32)menu->alpha / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        value = 255.0f * opacity;
        spriteAlpha = (u8)value;
        func_0034c270(position, spriteAlpha, menu->background, 0.0f);
    }
    if ((menu->visible & 0x1000) != 0) {
        s8 *paletteSource;
        s8 *paletteBytes;
        s32 pairsRemaining;
        u8 *decorationSprite;
        paletteSource = (s8 *)D_00762DC0;
        paletteBytes = (s8 *)palette;
        pairsRemaining = 4;
        do {
            s8 b0;
            s8 b1;
            b0 = paletteSource[0];
            b1 = paletteSource[1];
            paletteSource += 2;
            pairsRemaining--;
            paletteBytes[0] = b0;
            paletteBytes[1] = b1;
            paletteBytes += 2;
        } while (pairsRemaining > 0);
        decorationSprite = menu->sprites[42];
        /* Twenty decorations are drawn from the 28-entry animation group.
           Keep the work-relative row base: fields +0xCB4/+0xCBE/+0xCC4
           are position, alpha and scale in those 0x30-byte entries. */
        for (rowIndex = 0; rowIndex < 0x14; rowIndex++) {
            u8 *animation;
            SkillDecoration *layout;
            layout = (SkillDecoration *)D_005ED790 + rowIndex;
            animation = work + rowIndex * 0x30;
            offset = originX + *(f32 *)(animation + 0xCB4);
            position.x = offset + layout->x;
            offset = originY + *(f32 *)(animation + 0xCB8);
            position.y = offset + layout->y;
            value = (f32)*(u8 *)(animation + 0xCBE);
            value = value * opacity;
            spriteAlpha = (u8)value;
            decorationColor = &palette[layout->paletteIndex];
            func_0034f320(decorationSprite, position.x, position.y, 0.0f,
                          decorationColor->red, decorationColor->green, decorationColor->blue, spriteAlpha,
                          (u16)(1.0f + ((f32)*(u16 *)(animation + 0xCC4) * layout->width) / 100.0f),
                          (u16)(((f32)*(u16 *)(animation + 0xCCA) * layout->height) / 100.0f),
                          0, 0.0f, 0);
        }
    }
    if ((menu->visible & 1) != 0) {
        position.x = 16.0f + (originX + menu->animation[0].x);
        position.y = 368.0f + (originY + menu->animation[0].y);
        value = (f32)menu->animation[0].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        func_0034f2e0(menu->sprites[58], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x200) != 0) {
        position.x = 14.0f + (originX + menu->animation[33].x);
        position.y = 405.0f + (originY + menu->animation[33].y);
        value = (f32)menu->animation[33].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        func_0034f2e0(menu->sprites[27], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x400) != 0) {
        position.x = 14.0f + (originX + menu->animation[34].x);
        position.y = 405.0f + (originY + menu->animation[34].y);
        value = (f32)menu->animation[34].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        func_0034f2e0(menu->sprites[28], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 0x800) != 0) {
        position.x = 71.0f + (originX + menu->animation[35].x);
        position.y = 405.0f + (originY + menu->animation[35].y);
        value = (f32)menu->animation[35].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        func_0034f2e0(menu->sprites[29], position.x, position.y, 0xFF, 0xFF, 0xFF, spriteAlpha);
    }
    if ((menu->visible & 2) != 0) {
        for (rowIndex = 0; rowIndex < menu->partyCount; rowIndex++) {
            func_0013ad40(work, rowIndex, 0);
        }
    }
    if ((menu->visible & 0x20) != 0) {
        SkillMenuColor *paletteColor;
        position.x = 257.0f + (originX + menu->animation[17].x);
        position.y = 21.0f + (originY + menu->animation[17].y);
        value = (f32)menu->animation[17].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        paletteColor = (void *)D_0064B2F4;
        color.rgba[0] = paletteColor->red;
        color.rgba[1] = paletteColor->green;
        color.rgba[2] = paletteColor->blue;
        color.rgba[3] = spriteAlpha;
        func_0013b370(work, position, color);
        position.x = 255.0f + (originX + menu->animation[17].x);
        position.y = 21.0f + (originY + menu->animation[17].y);
        func_00113730(&descriptor.kind);
        descriptor.kind = 1;
        descriptor.style = 4;
        descriptor.flags = 1;
        payloadIndex = (s32)menu->scrollRow + (s32)menu->selectedRow;
        descriptor.payload = menu->skills[payloadIndex].copy;
        func_00113790(position, spriteAlpha, &descriptor.kind, 1, 0.0f);
    }
    if ((menu->visible & 0x2000) != 0) {
        f32 scrollOriginY;
        u8 scrollAlpha;
        f32 scrollOriginX;
        SkillMenuColor *paletteColor;
        f32 scrollX;
        scrollOriginX = menu->animation[67].x + (originX + menu->animation[16].x);
        scrollOriginY = menu->animation[67].y + (originY + menu->animation[16].y);
        value = (f32)menu->animation[16].alpha;
        value = value * opacity;
        scrollAlpha = (u8)value;
        scrollX = 607.0f + scrollOriginX;
        position.x = scrollX;
        position.y = 32.0f + scrollOriginY;
        func_0034f2e0(menu->sprites[11], position.x, position.y, 0xFF, 0xFF, 0xFF, scrollAlpha);
        position.x = scrollX;
        position.y = 197.0f + scrollOriginY;
        func_0034f2e0(menu->sprites[12], position.x, position.y, 0xFF, 0xFF, 0xFF, scrollAlpha);
        position.x = scrollX;
        position.y = 35.0f + scrollOriginY;
        if (menu->skillCount - 6 > 0) {
            position.y += (f32)(((menu->scrollRow * 0x42 + (s32)menu->scrollRow) * 2) / (menu->skillCount - 6));
        }
        paletteColor = (void *)D_0064B2E8;
        func_0034f2e0(menu->sprites[13], position.x, position.y, paletteColor->red, paletteColor->green,
                      paletteColor->blue, scrollAlpha);
    }
    if ((menu->visible & 8) != 0) {
        if (menu->animation[66].alpha > 0) {
            u8 *rowSprite;
            SkillMenuColor *paletteColor;
            position.x = originX + menu->animation[66].x;
            position.y = originY + menu->animation[66].y;
            paletteColor = (void *)D_0064B2E4;
            rowSprite = menu->sprites[0];
            func_0034f320(rowSprite, position.x, position.y, 0.0f, paletteColor->red, paletteColor->green,
                          paletteColor->blue, menu->animation[66].alpha, 0x1000, 0x1000, 0, 0.0f, 0);
        }
        /* Six visible entries use the +0x8F4 animation group and their
           labels use +0x774. The initializer fixes both strides at 0x30. */
        for (rowIndex = 0; rowIndex < 6; rowIndex++) {
            SkillMenuColor *iconColor;
            if (menu->skillCount > rowIndex + menu->scrollRow) {
                if (menu->selectedRow == rowIndex && ((menu->visible & 0x10) != 0)) {
                    if ((menu->visible & 0x80) == 0) {
                        SkillMenuColor *paletteColor;
                        iconColor = (void *)D_0064B2EC;
                        position.x = 257.0f + (originX + menu->animation[9].x);
                        value = 0.0f + menu->animation[9].y + 34.0f * (f32)menu->selectedRow;
                        value = skillPositionAdd(21.0f, value);
                        position.y = originY + value;
                        paletteColor = (void *)D_0064B2E8;
                        color.rgba[0] = paletteColor->red;
                        color.rgba[1] = paletteColor->green;
                        color.rgba[2] = paletteColor->blue;
                        value = (f32)menu->animation[9].alpha;
                        value = value * opacity;
                        color.rgba[3] = (u8)value;
                        func_0013b370(work, position, color);
                    } else {
                        continue;
                    }
                } else {
                    u8 *rowSprite;
                    SkillMenuColor *paletteColor;
                    paletteColor = (void *)D_0064B2E4;
                    iconColor = (void *)D_0064B2E0;
                    position.x = 255.0f + (originX + *(f32 *)(work + rowIndex * 0x30 + 0x8F4));
                    value = 0.0f + (originY + *(f32 *)(work + rowIndex * 0x30 + 0x8F8)) + 34.0f * (f32)rowIndex;
                    position.y = 21.0f + value;
                    value = (f32)*(u8 *)(work + rowIndex * 0x30 + 0x8FE);
                    value = value * opacity;
                    spriteAlpha = (u8)value;
                    rowSprite = menu->sprites[0];
                    func_0034f320(rowSprite, position.x, position.y, 0.0f, paletteColor->red, paletteColor->green,
                                  paletteColor->blue, spriteAlpha, 0x1000, *(u16 *)(work + rowIndex * 0x30 + 0x90A),
                                  0, 0.0f, 0);
                }
                payloadIndex = func_0013ac30(*(u16 *)(work + (menu->scrollRow + rowIndex) * 0xC + 0x102));
                if (payloadIndex > 0) {
                    u8 *skillIconSprite;
                    skillIconSprite = *(u8 **)(work + payloadIndex * 4 + 0x1244);
                    position.x = 258.0f + (originX + *(f32 *)(work + rowIndex * 0x30 + 0x8F4));
                    value = 0.0f + (originY + *(f32 *)(work + rowIndex * 0x30 + 0x8F8)) + 34.0f * (f32)rowIndex;
                    position.y = 23.0f + value;
                    value = (f32)*(u8 *)(work + rowIndex * 0x30 + 0x8FE);
                    value = value * opacity;
                    spriteAlpha = (u8)value;
                    func_0034f320(skillIconSprite, position.x, position.y, 0.0f, iconColor->red, iconColor->green,
                                  iconColor->blue, spriteAlpha, 0x1000, *(u16 *)(work + rowIndex * 0x30 + 0x90A), 0,
                                  0.0f, 0);
                }
                position.x = 300.0f + (originX + *(f32 *)(work + rowIndex * 0x30 + 0x774));
                offset = *(f32 *)(work + rowIndex * 0x30 + 0x778);
                value = 0.0f + originY + 34.0f * (f32)rowIndex;
                value = skillPositionAdd(offset, value);
                position.y = 21.0f + value;
                value = (f32)*(u8 *)(work + rowIndex * 0x30 + 0x77E);
                value = value * opacity;
                spriteAlpha = (u8)value;
                func_00113730(&descriptor.kind);
                descriptor.kind = 1;
                if (menu->selectedRow == rowIndex && ((menu->visible & 0x10) != 0)) {
                    descriptor.style = 3;
                } else {
                    descriptor.style = 2;
                }
                payloadIndex = (s32)menu->scrollRow + rowIndex;
                descriptor.payload = *(Vec3f *)(work + payloadIndex * 0xC + 0x100);
                func_00113790(position, spriteAlpha, &descriptor.kind, 1, 0.0f);
            }
        }
    }
    if ((menu->visible & 0x40) != 0) {
        for (rowIndex = 0; rowIndex < menu->partyCount; rowIndex++) {
            func_0013ad40(work, rowIndex, 3);
        }
    }
    if ((menu->visible & 0x80) != 0) {
        s32 overlayAlpha;
        position.x = 257.0f + (originX + menu->animation[9].x);
        value = 0.0f + originY + (f32)menu->selectedRow * 34.0f;
        value = skillPositionAdd(menu->animation[9].y, value);
        position.y = 21.0f + value;
        value = (f32)menu->animation[32].alpha;
        value = value * opacity;
        overlayAlpha = spriteAlpha = (u8)value;
        func_00113730(&descriptor.kind);
        descriptor.kind = 1;
        descriptor.style = 3;
        descriptor.flags = 1;
        payloadIndex = (s32)menu->scrollRow + (s32)menu->selectedRow;
        descriptor.payload = menu->skills[payloadIndex].copy;
        func_0013b420(work, position, overlayAlpha, &descriptor.kind);
    }
    {
        position.x = 640.0f + (originX + menu->animation[36].x);
        position.y = 400.0f + (originY + menu->animation[36].y);
        value = (f32)menu->animation[36].alpha;
        value = value * opacity;
        spriteAlpha = (u8)value;
        func_0034f9d0(position, 0.0f, spriteAlpha, menu->footerMode, menu->footer.handle);
    }
}
#pragma pop

// FUN_0013A040
s32 func_0013a040(s16 *arg0, s32 arg1, s32 arg2)
{
    arg0[arg1 + 0x54] = arg0[arg1 + 0x2E];
    arg0[arg1 + 0x2E] = arg2;
    return 1;
}

/* measured: delayed s16 narrowing fixes the loop-counter live ranges, named
   float temporaries preserve the retail load schedule, and the two settings
   below close the full 1076-byte object (normalized_diff 0). */
// FUN_0013A060
/* measured: opt_common_subs off preserves the retail per-iteration address formation. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves the retail scalar and FP operand order. */
#pragma opt_propagation off
void func_0013a060(void *arg0)
{
    s32 i;
    s32 idx;
    s16 *counter;
    u8 *row;
    s32 *statep;
    s32 state;
    s32 count;
    s32 hundred;
    s32 hundred_eighty;
    u8 *flagp;
    u8 *p;
    f32 *x;
    f32 *y;
    f32 *table;
    f32 value;
    f32 divisor;
    f32 scale;
    f32 half;
    f32 temp;
    u32 random;

    for (i = 0; i < 0x1C; i++) {
        idx = i * 2;
        counter = (s16 *)((u8 *)arg0 + idx + 0x24);
        count = *counter + 1;
        *counter = count;
        row = (u8 *)arg0 + (idx + i) * 0x10;
        statep = (s32 *)(row + 0xCD0);
        state = *statep;
        count = (s16)count;
        if (state < count) {
            if (i % 0xE < 6) {
                if (state == 0xA) {
                    *(s16 *)(row + 0xCC8) =
                        *(s16 *)(row + 0xCC2) = 0x64;
                    *(s32 *)(row + 0xCA4) = 0;
                    *(s32 *)(row + 0xCA8) = 0;
                    *(s32 *)(row + 0xCAC) = 0;
                    *(s32 *)(row + 0xCB0) = 0;
                    *statep = 6;
                }
                flagp = row + 0xCBE;
                if (*flagp != 0) {
                    p = (u8 *)arg0 + i * 0x30;
                    *(f32 *)(p + 0xCA4) = *(f32 *)(p + 0xCAC);
                    *(f32 *)(p + 0xCA8) = *(f32 *)(p + 0xCB0);
                    *statep = 0x10;
                } else {
                    p = (u8 *)arg0 + i * 0x30;
                    x = (f32 *)(p + 0xCA4);
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(p + 0xCA8);
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *y = (f32)random;
                    *(f32 *)(p + 0xCAC) = *x;
                    *(f32 *)(p + 0xCB0) = *y;
                    *statep = 8;
                }
                p = (u8 *)arg0 + i * 0x30;
                *(u8 *)(p + 0xCBD) = *(u8 *)(p + 0xCBC);
                *(u8 *)(p + 0xCBC) = *flagp;
            } else {
                flagp = row + 0xCBE;
                if (*flagp != 0) {
                    if (count < state + 0xA) {
                        continue;
                    }
                    *(f32 *)(row + 0xCA4) = *(f32 *)(row + 0xCAC);
                    *(f32 *)(row + 0xCA8) = *(f32 *)(row + 0xCB0);
                    *(u16 *)(row + 0xCC0) = *(u16 *)(row + 0xCC2);
                    *(u16 *)(row + 0xCC6) = *(u16 *)(row + 0xCC8);
                    *statep = 4;
                } else {
                    x = (f32 *)(row + 0xCA4);
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(row + 0xCA8);
                    random = (u32)RpRandom() % 0x28 - 0x14;
                    *y = (f32)random;
                    table = (f32 *)(D_005ED790 + i * 0x14);
                    temp = table[2];
                    value =
                        (57.0f * temp) / (divisor = 4096.0f);
                    scale = DAT_00761640;
                    value =
                        (scale * value - value) / (half = 2.0f);
                    *(f32 *)(row + 0xCAC) = *x - value;
                    temp = table[3];
                    value = (60.0f * temp) / divisor;
                    value = (scale * value - value) / half;
                    *(f32 *)(row + 0xCB0) = *y - value;
                    hundred = 0x64;
                    *(s16 *)(row + 0xCC0) = hundred;
                    hundred_eighty = 0xB4;
                    *(s16 *)(row + 0xCC2) = hundred_eighty;
                    *(s16 *)(row + 0xCC6) = hundred;
                    *(s16 *)(row + 0xCC8) = hundred_eighty;
                    *statep = 8;
                }
                p = (u8 *)arg0 + i * 0x30;
                *(u8 *)(p + 0xCBD) = *(u8 *)(p + 0xCBC);
                *(u8 *)(p + 0xCBC) = *flagp;
            }
            *counter = 0;
        }
        func_001437b0(row + 0xCA4, *counter, 1);
    }
}
/* measured: restore propagation after matching func_0013a060. */
#pragma opt_propagation on
/* measured: restore common-subexpression optimization after matching func_0013a060. */
#pragma opt_common_subs on

/* measured: without #pragma opt_common_subs off, mwcc b210 CSEs the
   (u8*)arg0 + 0x22 address into a callee-saved pointer (nd 34); with it off
   each access keeps base+offset like retail (nd 3 = 3 padding words only).
   Same call-site trick as the cmpPersona sibling func_00135cf0. */
// FUN_0013A4A0
#pragma opt_common_subs off
void func_0013a4a0(void *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)((u8 *)arg0 + 0x22);
    if (v < 0x64) {
        *(s16 *)((u8 *)arg0 + 0x22) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = (u8 *)arg0 + i * 0x30 + 0x11E4;
        func_001437b0(p, *(s16 *)((u8 *)arg0 + 0x22), 0);
    }
}
/* measured: opt_common_subs off is required for the retail base+offset access order. */
#pragma opt_common_subs on

/* measured: setup/switch and data-copy loops match with common-subexpression
   elimination disabled; re-enabling it before the table loop reproduces the
   retail source/destination registers and hoisted float-conversion constants.
   Loop-invariant optimization is required for the conversion preheader. */
#pragma opt_common_subs off
#pragma opt_loop_invariants on
// FUN_0013A530
s32 func_0013a530(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *p;
    u8 *src;
    f32 value;

    table = 0;
    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x26; i++) {
        p = arg0 + i * 0x30;
        *(f32 *)(p + 0x584) = *(f32 *)(p + 0x594);
        *(f32 *)(p + 0x588) = *(f32 *)(p + 0x598);
        *(u16 *)(p + 0x5A0) = *(u16 *)(p + 0x5A4);
        *(u16 *)(p + 0x5A6) = *(u16 *)(p + 0x5AA);
        *(u8 *)(p + 0x59C) = *(u8 *)(p + 0x59E);
    }
    switch (arg1) {
    case 0:
        table = D_005EB5D0;
        *(s32 *)(arg0 + 0x1C) = 0x220B;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 1:
        table = D_005EBA00;
        break;
    case 2:
        *(s32 *)(arg0 + 0x1C) = 0x220B;
        table = D_005EBE30;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 3:
        *(s32 *)(arg0 + 0x1C) = 0x269B;
        table = D_005EC260;
        *(s16 *)(arg0 + 0x582) = 1;
        break;
    case 4:
        *(s32 *)(arg0 + 0x1C) = 0x241B;
        table = D_005EC690;
        *(s16 *)(arg0 + 0x582) = 1;
        break;
    case 5:
        table = D_005ECAC0;
        *(s32 *)(arg0 + 0x1C) = 0xC61;
        *(f32 *)(arg0 + 0x8B8) =
            34.0f * (f32)*(s16 *)(arg0 + 0x5E);
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 6:
        table = D_005ECAC0;
        *(s32 *)(arg0 + 0x1C) = 0x1861;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 7:
        table = D_005ECEF0;
        *(s32 *)(arg0 + 0x1C) = 0xD61;
        *(f32 *)(arg0 + 0x8B8) =
            34.0f * (f32)*(s16 *)(arg0 + 0x5E);
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 8:
        table = D_005ECEF0;
        *(s32 *)(arg0 + 0x1C) = 0x1961;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 9:
        table = D_005ED320;
        *(s32 *)(arg0 + 0x1C) = 0x249B;
        *(s16 *)(arg0 + 0x582) = 2;
        break;
    case 10:
        table = D_005ED320;
        *(s32 *)(arg0 + 0x1C) = 0x249B;
        *(s16 *)(arg0 + 0x582) = 2;
        break;
    default:
        func_0046d730(D_005ED9C0, 0x5C9);
        break;
    }
    if (table != 0) {
        /* measured: re-enable common-subexpression optimization here to
           reproduce retail's table-loop register allocation. */
#pragma opt_common_subs on
        for (j = 0; j < 0x26; j++) {
            src = table + j * 0x1C;
            p = arg0 + j * 0x30;
            *(f32 *)(p + 0x58C) = *(f32 *)(src + 0);
            *(f32 *)(p + 0x590) = *(f32 *)(src + 4);
            *(u8 *)(p + 0x59D) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(p + 0x5A2) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(p + 0x5A8) = (u16)value;
            *(s32 *)(p + 0x5AC) = *(s32 *)(src + 0x14);
            *(s32 *)(p + 0x5B0) = *(s32 *)(src + 0x18);
        }
        *(s32 *)(arg0 + 0x18) = arg1;
        *(s16 *)(arg0 + 0x20) = 0;
    }
    return 1;
}
#pragma opt_loop_invariants off
/* measured: retail hoists the lui 0x41c8 (25.0f constant) into the loop
   preheader; mwcc b210 sinks the materialization into the if-branch unless
   #pragma opt_loop_invariants on is active. Tried s32/u32/f32 locals, register,
   ternary, chained-assign, while-loop spellings — all nd 30 without the pragma. */
// FUN_0013A8A0
#pragma opt_loop_invariants on
void func_0013a8a0(u8 *arg0)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0x5B4) = *(f32 *)(q + 0x5C4);
        *(f32 *)(q + 0x5B8) = *(f32 *)(q + 0x5C8);
        *(u8 *)(q + 0x5CC) = *(u8 *)(q + 0x5CE);
        *(f32 *)(q + 0x674) = *(f32 *)(q + 0x684);
        *(f32 *)(q + 0x678) = *(f32 *)(q + 0x688);
        *(u8 *)(q + 0x68C) = *(u8 *)(q + 0x68E);
        if (*(s16 *)(arg0 + 0x5C) == i) {
            *(s32 *)(q + 0x5BC) = 0x41C80000;
            *(s32 *)(q + 0x67C) = 0x41C80000;
        } else {
            *(s32 *)(q + 0x5BC) = 0;
            *(s32 *)(q + 0x67C) = 0;
        }
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
/* measured: opt_loop_invariants on is required for the retail preheader constant hoist. */
#pragma opt_loop_invariants off
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

/* measured: same lui-hoist floor as func_0013a8a0 (constant 0x41C80000 into
   preheader); without #pragma opt_loop_invariants on mwcc b210 sinks the lui
   into the branch — identical nd 30 on every spelling tried. */
// FUN_0013AA00
#pragma opt_loop_invariants on
void func_0013aa00(u8 *arg0)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0xA04) = *(f32 *)(q + 0xA14);
        *(f32 *)(q + 0xA08) = *(f32 *)(q + 0xA18);
        *(u8 *)(q + 0xA1C) = *(u8 *)(q + 0xA1E);
        *(f32 *)(q + 0xAC4) = *(f32 *)(q + 0xAD4);
        *(f32 *)(q + 0xAC8) = *(f32 *)(q + 0xAD8);
        *(u8 *)(q + 0xADC) = *(u8 *)(q + 0xADE);
        if (*(s16 *)(arg0 + 0x62) == i) {
            *(s32 *)(q + 0xA0C) = 0x41C80000;
            *(s32 *)(q + 0xACC) = 0x41C80000;
        } else {
            *(s32 *)(q + 0xA0C) = 0;
            *(s32 *)(q + 0xACC) = 0;
        }
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
/* measured: opt_loop_invariants on is required for the retail preheader constant hoist. */
#pragma opt_loop_invariants off

// FUN_0013AA90
void func_0013aa90(void *arg0)
{
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(RpRandom() & 1)) {
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

/* Case values decoded from jtbl_007469C0 with tools/jtbl.py: twenty dense
   entries mapping index+1 to 0x2B..0x32, with 9-19 sharing 0x33 and index 0
   returning -1; >= 0x14 hits the assert. The labels are declared in that
   object order because b210 lays case bodies out in declaration order.
   The unsigned-halfword ID is forwarded unchanged. The signed-halfword
   result projection before adding one matches the retail switch index. */
// FUN_0013AC30
s32 func_0013ac30(u16 arg0) {
    s32 v;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        return 0x35;
    }
    v = (s16)func_0023d8e0(NULL, arg0) + 1;
    switch ((u32)v) {
    case 1:
        return 0x2B;
    case 2:
        return 0x2C;
    case 3:
        return 0x2D;
    case 4:
        return 0x2E;
    case 5:
        return 0x2F;
    case 6:
        return 0x30;
    case 7:
        return 0x31;
    case 8:
        return 0x32;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        return 0x33;
    case 0:
        return -1;
    }
    func_0046d730(D_005ED9C0, 0x6B2);
    return -1;
}
