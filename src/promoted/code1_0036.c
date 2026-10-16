#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
typedef struct {
    f32 x;
    f32 y;
} PairF32;
typedef union {
    s64 raw;
    PairF32 f;
} PairBits;
typedef struct PersonaWork PersonaWork;
extern s16 datCategoryRank(s16 index);
extern u16 func_00105290(s16 pcId);
extern s32 func_00105a50(s16 pcId);
extern u8 *datPersonaGetRow(u16 personaId);
extern u8 datPersonaGetArcana(u16 personaId);
extern u8 datPersonaGetLevel(s32 persona);
extern u32 datPersonaGetNextExp(s32 persona);
extern u32 datPersonaGetExpToNextLevel(PersonaWork *persona);
extern u16 *datPersonaGetRecord(u16 pcId);

extern void func_003642e0(u8 *arg0, void *arg1);

extern void memset(void *dst, s32 value, s32 size);

extern void pscResInit(u8 *arg0);
extern void pscBuildGridIndexTable(void);
extern void func_0036d8b0(void);

extern void pscResUpdate(void);
extern s32 pscResAnySlotInUse(void);
extern void radarAnimateValue(u8 *arg0, s16 arg1, s32 arg2);

extern s32 func_0034c210(void);
extern u32 datGetFlag(s32 arg0);
extern s32 func_0035fa00(u8 *arg0, s32 arg1, s16 arg2);
extern void func_0034f8f0(void *arg0);
extern s32 datCalcGetLevelById(s32 arg0);

extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00369440(void);
extern u8 *func_00457120(void);
extern void func_003e8180(void *arg0, f32 arg1);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern void func_00457630(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void datPanelResetCursor(u8 *arg0);
extern void datPanelDrawByKind(s64 arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void func_002bb550(s8 arg0);
extern f32 iGpffff84a4;
extern s32 resourceFindByName(const void *arg0);
extern void kAssertFail(const void *arg0, s32 arg1);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

extern f32 cosf(f32 arg0);
static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
extern void sflDataDrawSpritePair(PairBits arg0, f32 fparg0, s32 arg1);
extern void sflDataDrawPersonaPanel(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void sflDataDrawByteValuePanel(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_00367940(P4Pair arg0, f32 arg1, s32 arg2, u8 *arg3);
extern void sflDataDrawNumberValue(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void sflDataDrawTitledIcon(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void sflDataDrawLevelBadge(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void sflDataInitPanel(void);
extern void pscLightInitQuad(u8 *arg0);
extern f32 fGpffff8390;
extern f32 fGpffff8394;
extern void func_00362630(u8 *arg0);
extern void func_0035f5b0(u8 *arg0);
extern s32 func_0035fc40(u8 *arg0);
extern s32 func_0035fa20(u8 *arg0, u32 arg1);
extern void func_0034bb20(s32 arg0);
extern void func_00353fb0(void);
extern void func_00353fe0(void);
extern s32 func_00354030(void);
extern void func_00354080(s32 arg0);
extern s32 func_0035c690(void *arg0, s32 arg1);
extern s32 func_0035c7d0(u8 *arg0);
extern s32 func_0035c7f0(u8 *arg0);
extern s32 func_002badc0(s8 arg0, s32 arg1);
extern void func_002bafc0(s8 arg0, s32 arg1);
extern void func_002bb0a0(s8 arg0, s32 arg1);
extern void func_002bbf60(void);
extern s32 func_002bb180(s8 arg0);
extern void func_002bb290(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb9e0(s32 arg0, s32 arg1);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void sdkSndStopChannel(s32 arg0);
extern void sdkSndFadeOutChannelFrames(s32 arg0, s32 arg1, s32 arg2);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 fadeStatus(void);
extern u16 D_008C024E[];
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0;
    f32 u;
    f32 v;
    f32 w;
    f32 pad1;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 pad2[4];
} P4Vertex66C70;
typedef struct {
    s32 matrix[16];
    P4Vertex66C70 vertices[4];
    s32 config[8];
    u8 local[0x30];
} P4DrawFrame66C70;
typedef void (*P4RenderState66C70)(s32 state, s32 value);
extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src,
                           const struct RwMatrixTag *matrix);
extern f32 sinf(f32 arg0);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

// FUN_00361970
void func_00361970(u8 *arg0)
{
    *(s32 *)(arg0 + 0x5C4) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x32)) {
        *(f32 *)(arg0 + 0x5BC) = -10.0f;
    } else {
        *(f32 *)(arg0 + 0x5BC) = 10.0f;
    }
    *(s16 *)(arg0 + 0x26) = 0;
}

// FUN_003619B0
s32 func_003619b0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 29) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x74)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_00361A30
void func_00361a30(u8 *arg0)
{
    s32 handle;
    s32 handle704;
    s32 i;
    s8 id;
    u8 *slot;

    i = 0;
    while (i < 0x2A) {
        slot = arg0 + (i * 4) + 0x658;
        handle = *(s32 *)slot;
        if (handle != 0) {
            sdkSpriteFreeNode((void *)handle);
            *(s32 *)slot = 0;
        }
        i += 1;
    }
    handle704 = *(s32 *)(arg0 + 0x704);
    if (handle704 != 0) {
        kwlnTaskDestroyWithHierarchy(handle704);
        *(s32 *)(arg0 + 0x704) = 0;
    }
    id = *(s8 *)(arg0 + 0x3C);
    if (id != -1) {
        func_002bb550(id);
        *(s8 *)(arg0 + 0x3C) = -1;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}
// FUN_00361AE0
void func_00361ae0(u8 *arg0)
{
    s32 top;
    s32 bottom;
    s32 i;
    s32 d1;
    s32 d2;
    s64 score;
    s16 topScore;
    s16 bottomScore;
    u8 *p;

    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) >= 0x19) *(s16 *)(arg0 + 0x22) = 0;
    *(s16 *)(arg0 + 0x24) = *(s16 *)(arg0 + 0x24) + 1;
    if (*(s16 *)(arg0 + 0x24) >= 0x1E) *(s16 *)(arg0 + 0x24) = 0;
    top = (s32)((11.0f * (f32)*(s16 *)(arg0 + 0x22)) / 25.0f);
    bottom = (s32)(11.0f * (1.0f - ((f32)*(s16 *)(arg0 + 0x24) / 30.0f)));
    i = 0;
    while (i < 0xB) {
        if (i < top) d1 = top - i; else d1 = i - top;
        if (i < bottom) d2 = bottom - i; else d2 = i - bottom;
        score = 1;
        topScore = (s16)(10 - d1 * 2);
        if (topScore > 1) score = topScore;
        bottomScore = (s16)(8 - d2 * 2);
        if (score < bottomScore) score = bottomScore;
        p = arg0 + i * 0xA;
        *(s16 *)(p + 0x5E8) = (s16)score;
        func_0034f8f0(p + 0x5E8);
        i++;
    }
}
// FUN_00361CA0
void func_00361ca0(u8 *arg0) {
    s16 c = *(s16 *)(arg0 + 0x26);
    s32 count;
    s32 i;
    u8 *record;

    if (c < 100) {
        *(s16 *)(arg0 + 0x26) = c + 1;
    }
    for (i = 0; i <= 0; i++) {
        record = arg0 + i * 0x30;
        count = *(s16 *)(arg0 + 0x26);
        radarAnimateValue(record + 0x5B8, count, 0);
    }
  }

/* Measured 2026-09-28: 2316 bytes plus four zero alignment bytes.
   The 0x30-byte row stride and independent field pointers preserve field
   reloads across draws. Palette channels are read after the badge calls;
   final byte opacity is packed into the text color before name lookup. */
// FUN_00361D20
void func_00361d20(s32 arg0, u8 *arg1)
{
    typedef struct MenuPaletteColor { u8 r, g, b, a; } MenuPaletteColor;
    typedef struct MenuRowStride { u8 bytes[0x30]; } MenuRowStride;
    extern void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
    extern int sprintf(char *dst, const char *fmt, ...);
    extern u32 func_00354490(s32 arg0);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 iGpffffa980;
    f32 *rowX;
    f32 *rowY;
    u8 *rowAlpha;
    f32 scale;
    f32 baseX;
    f32 baseY;
    f32 rowOffsetY;
    s32 idx;
    s32 probe100;
    s32 probe180;
    s32 probe140;
    s32 ptrA;
    void *drawNode;
    s8 mode;
    s32 colorBase;
    u8 rgb1r;
    u8 rgb1g;
    u8 rgb1b;
    u8 rgb2r;
    u8 rgb2g;
    u8 rgb2b;
    f32 x;
    f32 y;
    s32 alpha;
    s8 buf[256];
    f32 lx;
    f32 ly;
    u8 alphaLoop;
    f32 fx;
    f32 fy;
    u8 finalAlpha;

    baseX = *(f32 *)(arg1 + 4);
    baseY = *(f32 *)(arg1 + 8);
    scale = (f32)arg1[0] / 255.0f;
    idx = arg0 + *(s16 *)(arg1 + 0x2C);
    probe100 = datGetFlag(idx + 0x100);
    probe180 = datGetFlag(idx + 0x180);
    probe140 = datGetFlag(idx + 0x140);
    if (arg0 == *(s16 *)(arg1 + 0x2A)) {
        ptrA = *(s32 *)(arg1 + 0x6E8);
        mode = 8;
        if (probe100 != 0) {
            if (probe140 != 0) {
                colorBase = 0xAAAAAA00;
                rgb2r = 0xAA;
                rgb2g = 0xAA;
                rgb2b = 0xAA;
                rgb1r = D_0064B2E8[0];
                rgb1g = D_0064B2E8[1];
                rgb1b = D_0064B2E8[2];
            } else {
                colorBase = 0xFFFFFF00;
                rgb2r = D_0064B2EC[0];
                rgb2g = D_0064B2EC[1];
                rgb2b = D_0064B2EC[2];
                rgb1r = D_0064B2E8[0];
                rgb1g = D_0064B2E8[1];
                rgb1b = D_0064B2E8[2];
            }
        } else {
            colorBase = 0xAAAAAA00;
            rgb2r = 0xAA;
            rgb2g = 0xAA;
            rgb2b = 0xAA;
            rgb1r = D_0064B2E8[0];
            rgb1g = D_0064B2E8[1];
            rgb1b = D_0064B2E8[2];
        }
    } else {
        ptrA = *(s32 *)(arg1 + 0x6D4);
        colorBase = 0xFFFFFF00;
        if (probe100 != 0) {
            if (probe140 != 0) {
                mode = 8;
                rgb2r = D_0064B2EC[0];
                rgb2g = D_0064B2EC[1];
                rgb2b = D_0064B2EC[2];
                rgb1r = 0xAD;
                rgb1g = 0xAD;
                rgb1b = 0xAD;
            } else {
                mode = 6;
                rgb2r = D_0064B2E4[0];
                rgb2g = D_0064B2E4[1];
                rgb2b = D_0064B2E4[2];
                rgb1r = D_0064B2E0[0];
                rgb1g = D_0064B2E0[1];
                rgb1b = D_0064B2E0[2];
            }
        } else {
            mode = 6;
            rgb2r = D_0064B2E0[0];
            rgb2g = D_0064B2E0[1];
            rgb2b = D_0064B2E0[2];
            rgb1r = 0xFF;
            rgb1g = 0xC8;
            rgb1b = 0x2B;
        }
    }
    rowX = (f32 *)((MenuRowStride *)(arg1 + 0x1D8) + arg0);
    x = 560.0f + (baseX + *rowX);
    rowY = (f32 *)((MenuRowStride *)(arg1 + 0x1DC) + arg0);
    rowOffsetY = (f32)arg0 * 30.0f;
    y = -13.0f + (rowOffsetY + (113.0f + (baseY + *rowY)));
    rowAlpha = (u8 *)((MenuRowStride *)(arg1 + 0x1E2) + arg0);
    alpha = (u8)((f32)*rowAlpha * scale);
    sdkSpriteDrawAt((void *)ptrA, x, y, rgb1r, rgb1g, rgb1b, alpha);
    if (probe180 != 0) {
        MenuPaletteColor *pal;
        f32 x2 = 15.0f + (baseX + *(f32 *)((MenuRowStride *)(arg1 + 0x418) + arg0));
        f32 y2 = -13.0f + (rowOffsetY + (117.0f + (baseY + *(f32 *)((MenuRowStride *)(arg1 + 0x41C) + arg0))));
        u8 a2 = (u8)((f32)*(u8 *)(arg1 + 0x422 + arg0 * 0x30) * scale);
        pal = (MenuPaletteColor *)D_0064B2EC;
        sdkSpriteDrawAt(*(void **)(arg1 + 0x6A4), x2, y2, 0x8C, 0x85, 0xFF, a2);
        drawNode = *(void **)(arg1 + 0x6A8);
        sdkSpriteDrawAt(drawNode, x2 + 60.0f, y2, 0x8C, 0x85, 0xFF, a2);
        drawNode = *(void **)(arg1 + 0x6A0);
        sdkSpriteDrawAt(drawNode, x2 + 10.0f, y2 + 3.0f, pal->r, pal->g, pal->b, a2);
    } else if (probe140 != 0) {
        x = 62.0f + (baseX + *(f32 *)((MenuRowStride *)(arg1 + 0x418) + arg0));
        y = -13.0f + (rowOffsetY + (117.0f + (baseY + *(f32 *)((MenuRowStride *)(arg1 + 0x41C) + arg0))));
        alpha = (u8)((f32)*(u8 *)(arg1 + 0x422 + arg0 * 0x30) * scale);
        sdkSpriteDrawAt(*(void **)(arg1 + 0x6F8), x, y, 0xFF, 0xFF, 0xFF, alpha);
    }
    sprintf((char *)buf, (const char *)&iGpffffa980, idx + 1);
    lx = 89.0f + (baseX + *rowX);
    ly = -13.0f + (rowOffsetY + (118.0f + (baseY + *rowY)));
    alphaLoop = (u8)((f32)*rowAlpha * scale);
    {
        s32 i;
        for (i = 0; i < 2; i++) {
            s32 tbl = *(s32 *)(arg1 + (s32)buf[i] * 4 + 0x5EC);
            sdkSpriteDrawAt((void *)tbl, lx, ly, rgb2r, rgb2g, rgb2b, alphaLoop);
            lx += 22.0f;
        }
    }
    fx = 153.0f + (baseX + *rowX);
    fy = -13.0f + (rowOffsetY + (117.0f + (baseY + *rowY)));
    finalAlpha = (u8)((f32)*rowAlpha * scale);
    if (probe100 != 0) {
        s32 color;
        u32 str;
        color = colorBase;
        color |= finalAlpha & 0xFF;
        str = func_00354490(idx);
        frFontExDrawTextOutA(fx, fy - 3.0f, 0.0f, color, mode, 1, (const char *)str, 0, 0x77, -1);
    } else {
        drawNode = *(void **)(arg1 + 0x69C);
        sdkSpriteDrawAt(drawNode, fx + 2.0f, fy + 1.0f, rgb2r, rgb2g, rgb2b, finalAlpha);
    }
}
// FUN_00362630
void func_00362630(u8 *arg0)
{
    s32 count;
    s32 i;
    s16 difference;
    s16 offset;

    count = *(s32 *)(arg0 + 0x38);
    i = 0;
    while (i < count) {
        if (datGetFlag(i + 0x180) != 0) {
            if ((s16)i >= count) {
                kAssertFail(D_0064E280, 0x37);
            }
            if ((s16)i < 3) {
                offset = 0;
            } else if ((s16)i >= count - 3) {
                offset = count - 6;
            } else {
                offset = (s16)i - 3;
            }
            difference = i - offset;
            if (difference + offset >= count) {
                kAssertFail(D_0064E280, 0x54);
            }
            func_0035fa00(arg0, 1, difference);
            func_0035fa00(arg0, 2, offset);
            break;
        }
        i++;
    }
    if (i == count) {
        func_0035fa00(arg0, 1, 0);
        func_0035fa00(arg0, 2, 0);
    }
}
/* MATCHED: arg0 is a u32 * state word - the switch on *arg0 is unsigned,
   which is what keeps retail's sltiu bound check - and the shared exit
   path is a label after the switch, so every arm that does no work jumps
   straight to `return 0`. */
// FUN_003627B0
s32 func_003627b0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    u8 query[0x30];
    s32 resultFlag = 1;
    s32 queryResult;
    s16 soundType;
    f32 alpha;

    *arg1 = 1;
    switch (*arg0) {
    case 0:
        *(s32 *)(arg2 + 4) = 0;
        *(s32 *)(arg2 + 8) = 0;
        *(u8 *)arg2 = 0xFF;
        func_0035f5b0(arg2);
        *arg0 = 1;
        *arg1 = 0;
        goto block_64;
    case 1:
        if ((func_0035fc40(arg2) != 0) && (func_0034c210() != 0)) {
            *arg0 = 3;
            func_0034bb20(0x1D);
        } else {
            *arg1 = 0;
        }
        goto block_64;
    case 2:
        if (func_003619b0(arg2) != 0) {
            func_00361a30(arg2);
            return 1;
        }
        goto block_64;
    case 3:
        if (func_003619b0(arg2) != 0) {
            func_0035fa20(arg2, 2);
            *arg0 = 4;
        }
        goto block_64;
    case 4:
        if (D_008C024E[0] & 0x20) {
            func_0035fa20(arg2, resultFlag);
            *arg0 = 2;
            func_0034bb20(0x1E);
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            soundType = *(s16 *)(arg2 + 0x28);
            switch (soundType) {
            case 0:
                func_0035fa20(arg2, resultFlag);
                *arg0 = 5;
                func_0034bb20(0x1E);
                break;
            case 1:
                func_0035fa20(arg2, resultFlag);
                *arg0 = 8;
                func_0034bb20(0x1E);
                break;
            case 2:
                func_002badc0(*(s8 *)(arg2 + 0x3C), 4);
                func_002bafc0(*(s8 *)(arg2 + 0x3C), 0);
                func_002bbf60();
                func_002bb0a0(*(s8 *)(arg2 + 0x3C), 1);
                *arg0 = 0xA;
                break;
            }
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xC;
        } else {
            func_00453670(query, 3, 3, *(s16 *)(arg2 + 0x28), 0);
            func_004538e0(query, 0x4000, 0x1000, 0, 0);
            if (func_00453960(query) != 0) {
                soundType = *(s16 *)(query + 0x24);
                func_0035fa00(arg2, 0, soundType);
                func_0045af60(0, 1, 0, 0);
            }
        }
        goto block_64;
    case 5:
        if (func_003619b0(arg2) != 0) {
            func_00362630(arg2);
            func_0035fa20(arg2, 3);
            *arg0 = 6;
            func_0034bb20(0x1F);
        }
        goto block_64;
    case 6:
        if (func_003619b0(arg2) != 0) {
            func_0035fa20(arg2, 4);
            *arg0 = 7;
            func_00353fe0();
        }
        goto block_64;
    case 7:
        if (D_008C024E[0] & 0x20) {
            func_0035fa20(arg2, 5);
            *arg0 = 1;
            func_0034bb20(0x20);
            func_00353fb0();
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xC;
        } else {
            func_00453670(query, 6, *(s32 *)(arg2 + 0x38),
                          *(s16 *)(arg2 + 0x2A), *(s16 *)(arg2 + 0x2C));
            func_004538e0(query, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((queryResult = func_00453960(query)) > 0) {
                soundType = *(s16 *)(query + 0x24);
                func_0035fa00(arg2, 1, soundType);
                soundType = *(s16 *)(query + 0x28);
                func_0035fa00(arg2, 2, soundType);
                if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x32)) {
                    func_00361970(arg2);
                }
                func_00354080(queryResult);
            }
        }
        goto block_64;
    case 8:
        if (func_0034c210() != 0) {
            *(s32 *)(arg2 + 0x704) = func_0035c690(0, 0);
            *arg0 = 9;
        }
        goto block_64;
    case 9:
        if (func_0035c7d0(*(u8 **)(arg2 + 0x704)) != 0) {
            if (func_0035c7f0(*(u8 **)(arg2 + 0x704)) != 0) {
                return 2;
            }
            kwlnTaskDestroyWithHierarchy(*(s32 *)(arg2 + 0x704));
            *(s32 *)(arg2 + 0x704) = 0;
            *arg0 = 1;
        }
        goto block_64;
    case 10:
        func_002bb9e0(*(s8 *)(arg2 + 0x3C), resultFlag);
        if (func_002bb680(*(s8 *)(arg2 + 0x3C)) == 0) {
            switch (func_002bb180(*(s8 *)(arg2 + 0x3C))) {
            case 0:
                func_00122520(1, 0x1E);
                sdkSndStopChannel(0x1E);
                sdkSndFadeOutChannelFrames(3, 0, 0x1E);
                *arg0 = 0xB;
                break;
            case 1:
                *arg0 = 4;
                break;
            }
            func_002bb290((s8)*(s8 *)(arg2 + 0x3C), 1);
        }
        goto block_64;
    case 11:
        if (fadeStatus() != 0) {
            func_001029a0(0x1B, 0, 0, 0xA);
        }
        goto block_64;
    case 12:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            queryResult = (u8)alpha;
            *(u8 *)arg2 = queryResult;
            resultFlag = 0;
        }
        break;
    default:
        goto block_64;
    }
    if (resultFlag != 0) {
        return 2;
    }
block_64:
    return 0;
}
// FUN_00362F00
s32 func_00362f00(u8 *arg0)
{
    f32 startY;
    f32 y;
    f32 x;
    f32 startX;
    f32 ease;
    s16 step;
    s16 frame;

    frame = *(s16 *)(arg0 + 0x18);
    if (frame < *(s16 *)(arg0 + 0x1A)) {
        *(s16 *)(arg0 + 0x18) = frame + 1;
        step = *(s16 *)(arg0 + 0x18);
        ease = 1.0f - cosf(iGpffff84a4 * ((f32)step / (f32)*(s16 *)(arg0 + 0x1A)));
        startX = *(f32 *)(arg0 + 0);
        x = *(f32 *)(arg0 + 8);
        x = x - startX;
        y = *(f32 *)(arg0 + 0xC);
        startY = *(f32 *)(arg0 + 4);
        y = y - startY;
        x = x * ease;
        y = y * ease;
        x = x + startX;
        *(f32 *)(arg0 + 0x10) = x;
        startY = *(f32 *)(arg0 + 4);
        startY = p4_00362f00_add(y, startY);
        *(f32 *)(arg0 + 0x14) = startY;
        return 0;
    }
    return 1;
}
// FUN_003642A0
void func_003642a0(u8 *arg0)
{
    u16 *flags = *(u16 **)(arg0 + 0x38);

    func_003642e0(arg0, NULL);
    *flags |= 2;
}

// FUN_003642E0
void func_003642e0(u8 *arg0, void *arg1)
{
    u16 *flags;

    flags = *(u16 **)(arg0 + 0x38);
    if (arg1 != NULL) {
        *flags |= 1;
    } else {
        *flags &= (u16)~1;
    }
}
#pragma push
#pragma opt_propagation off
/* Matched inside the same opt_propagation-off region as func_00366960: with
   propagation on MWCC folds the four edge differences into the mula.s/msub.s
   operands and evaluates them lazily, where retail computes dx1, dy1, dx2,
   dy2 in order first.  z is the third parameter (ABI-identical to the
   draft's order: ints fill $a0-$t3 and floats $f12 independently), which
   is what homes it in $f21 at the prologue; the identity matrix is
   RwMatrixSetIdentity's chained-assignment order; the render-state table
   goes through a u8 * copy so its address stays in $s0 across the calls;
   D_008872F8 is read as an absolute array element. */
#pragma pop

#pragma opt_common_subs off

#pragma opt_common_subs on

#pragma opt_loop_invariants on
/* measured: closes the loop-invariant bracket; the file default is off. */
#pragma opt_loop_invariants off

#pragma opt_propagation off
// measured: restore default propagation
#pragma opt_propagation on


#pragma push
#pragma opt_loop_invariants on
#pragma pop

struct PanelMatrix;
struct PanelTransform;
#pragma push
#pragma opt_loop_invariants on
#pragma pop
// FUN_0036D860
void func_0036d860(u8 *arg0, s32 arg1)
{
    pscResInit(arg0);
    pscBuildGridIndexTable();
    if (arg1 != 0) {
        func_0036d8b0();
    }
}

// FUN_0036D8B0
void func_0036d8b0(void)
{
    struct {
        s32 f20;
        s32 f24;
        s32 f28;
        s32 pad2c;
        s32 f30;
        s32 f34;
        s32 f38;
        u8 pad[4];
    } local;
    s32 view;

    view = (s32)func_00457120();
    func_003e8180((void *)view, 1.0f);
    local.f30 = 0;
    local.f34 = 0;
    local.f38 = 0;
    local.f20 = 0;
    local.f24 = 0;
    local.f28 = 0x43480000;
    K_View_SetFov((void *)view, 100.0f);
    func_00457630((void *)view, &local.f30, &local.f20, 0);
}
// FUN_0036D940
void func_0036d940(void *arg0)
{
    pscResDestroy();
}

// FUN_0036D960
s32 func_0036d960(void)
{
    pscResUpdate();
    return !pscResAnySlotInUse();
}
