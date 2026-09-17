#include "include_asm.h"
#include "type.h"
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
extern s16 func_00104f10(s16 index);
extern u16 func_00105290(s16 pcId);
extern s32 func_00105a50(s16 pcId);
extern u8 *func_00109220(s32 personaId);
extern u8 func_00109280(s32 personaId);
extern u8 datPersonaGetLevel(s32 persona);
extern u32 datPersonaGetNextExp(s32 persona);
extern u32 func_00109440(PersonaWork *persona);
extern PersonaWork *func_0010a900(u16 pcId);

extern void func_003642e0(u8 *arg0, void *arg1);

extern void memset(void *dst, s32 value, s32 size);

extern void func_0036b650(u8 *arg0);
extern void func_0036aa20(void);
extern void func_0036d8b0(void);

extern void func_0036b750(void);
extern s32 func_0036bb60(void);
extern void func_001437b0(u8 *arg0, s16 arg1, s32 arg2);

extern s32 func_0034c210(void);
extern s32 func_00106330(s32 arg0);
extern s32 func_0035fa00(u8 *arg0, s32 arg1, s16 arg2);
extern void func_0034f8f0(void *arg0);
extern s32 func_00104c70(s32 arg0);

extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00369440(void);
extern u8 *func_00457120(void);
extern void func_003e8180(void *arg0, f32 arg1);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_00457630(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void func_0011fd30(u8 *arg0);
extern void func_0011fd50(s64 arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern void func_0046d280(void *node);
extern void func_00452080(s32 arg0);
extern void func_002bb550(s8 arg0);
extern f32 iGpffff84a4;
extern s32 func_0046a770(const void *arg0);
extern void func_0046d730(const void *arg0, s32 arg1);
extern void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

extern f32 func_0044b610(f32 arg0);
static inline f32 p4_00362f00_add(f32 left, f32 right)
{
    return left + right;
}
extern void func_003675f0(PairBits arg0, f32 fparg0, s32 arg1);
extern void func_00367420(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_003676f0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_00367940(P4Pair arg0, f32 arg1, s32 arg2, u8 *arg3);
extern void func_003679c0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_00367b80(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_00367d00(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);
extern void func_00367f50(void);
extern void func_0036a900(u8 *arg0);
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
extern void func_002badc0(s8 arg0, s32 arg1);
extern void func_002bafc0(s8 arg0, s32 arg1);
extern void func_002bb0a0(s8 arg0, s32 arg1);
extern void func_002bbf60(void);
extern s32 func_002bb180(s8 arg0);
extern void func_002bb290(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb9e0(s8 arg0, s32 arg1);
extern void func_00453670(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void func_004598e0(s32 arg0);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern void func_001029a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
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
extern f32 func_0044b7b0(f32 arg0);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;
extern f32 fGpffff83fc;

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
    s32 temp_4;
    s32 temp_4_2;
    s32 var_18;
    s8 temp_4_3;
    u8 *temp_3;

    var_18 = 0;
    while (var_18 < 0x2A) {
        temp_3 = arg0 + (var_18 * 4) + 0x658;
        temp_4 = *(s32 *)temp_3;
        if (temp_4 != 0) {
            func_0046d280((void *)temp_4);
            *(s32 *)temp_3 = 0;
        }
        var_18 += 1;
    }
    temp_4_2 = *(s32 *)(arg0 + 0x704);
    if (temp_4_2 != 0) {
        func_00452080(temp_4_2);
        *(s32 *)(arg0 + 0x704) = 0;
    }
    temp_4_3 = *(s8 *)(arg0 + 0x3C);
    if (temp_4_3 != -1) {
        func_002bb550(temp_4_3);
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
    s16 tmp1;
    s16 tmp2;
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
        tmp1 = (s16)(10 - d1 * 2);
        if (tmp1 > 1) score = tmp1;
        tmp2 = (s16)(8 - d2 * 2);
        if (score < tmp2) score = tmp2;
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
        func_001437b0(record + 0x5B8, count, 0);
    }
  }

/* measured: floor v3 MISMATCH nd1464B/498w obj2264/win2320 97.6% PASS 2250 (+14B, not draft); frame 0x200 vs 0x210, GPR +1 shift (s5/s4 vs s4/s3, s8 vs s7), FPR rotation, sq offsets -0x10, probe140 spills vs s8; fnalign 566/578 -12; MAC N/A (0 madd/mula/msub/adda); GP/type lowered (iGpffffa980), no slt-at entry, no volatile/asm. */
// FUN_00361D20 NONMATCHING
#ifdef NON_MATCHING
void func_00361d20(s32 arg0, u8 *arg1)
{
    extern s32 func_00106330(s32 arg0);
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    extern void func_00442088(void *dst, const void *fmt, ...);
    extern u32 func_00354490(s32 arg0);
    extern s32 func_002751a0(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 out, s32 charWidth);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 iGpffffa980;
    f32 baseX;
    f32 baseY;
    f32 scale;
    f32 f22;
    s32 idx;
    s32 probe100;
    s32 probe180;
    s32 probe140;
    s32 ptrA;
    s32 mode;
    s32 colorBase;
    u8 rgb1r;
    u8 rgb1g;
    u8 rgb1b;
    u8 rgb2r;
    u8 rgb2g;
    u8 rgb2b;
    u8 *row;
    f32 x1;
    f32 y1;
    u8 alpha1;
    s8 buf[256];
    f32 lx;
    f32 ly;
    u8 alphaLoop;
    f32 fx;
    f32 fy;
    u8 alphaFinal;

    baseX = *(f32 *)(arg1 + 4);
    baseY = *(f32 *)(arg1 + 8);
    scale = (f32)arg1[0] / 255.0f;
    idx = arg0 + *(s16 *)(arg1 + 0x2C);
    probe100 = func_00106330(idx + 0x100);
    probe180 = func_00106330(idx + 0x180);
    probe140 = func_00106330(idx + 0x140);
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
    row = arg1 + arg0 * 0x30;
    f22 = (f32)arg0 * 30.0f;
    x1 = 560.0f + (baseX + *(f32 *)(row + 0x1D8));
    y1 = -13.0f + (f22 + (113.0f + (baseY + *(f32 *)(row + 0x1DC))));
    alpha1 = (u8)((f32)row[0x1E2] * scale);
    func_0034f2e0((void *)ptrA, x1, y1, rgb1r, rgb1g, rgb1b, alpha1);
    if (probe180 != 0) {
        u8 *row2 = arg1 + arg0 * 0x30;
        f32 x2 = 15.0f + (baseX + *(f32 *)(row2 + 0x418));
        f32 y2 = -13.0f + (f22 + (117.0f + (baseY + *(f32 *)(row2 + 0x41C))));
        u8 a2 = (u8)((f32)row2[0x422] * scale);
        func_0034f2e0(*(void **)(arg1 + 0x6A4), x2, y2, 0x8C, 0x85, 0xFF, a2);
        func_0034f2e0(*(void **)(arg1 + 0x6A8), x2 + 60.0f, y2, 0x8C, 0x85, 0xFF, a2);
        func_0034f2e0(*(void **)(arg1 + 0x6A0), x2 + 10.0f, y2 + 3.0f, D_0064B2EC[0], D_0064B2EC[1], D_0064B2EC[2], a2);
    } else if (probe140 != 0) {
        u8 *row3 = arg1 + arg0 * 0x30;
        f32 x3 = 62.0f + (baseX + *(f32 *)(row3 + 0x418));
        f32 y3 = -13.0f + (f22 + (117.0f + (baseY + *(f32 *)(row3 + 0x41C))));
        u8 a3 = (u8)((f32)row3[0x422] * scale);
        func_0034f2e0(*(void **)(arg1 + 0x6F8), x3, y3, 0xFF, 0xFF, 0xFF, a3);
    }
    func_00442088(buf, &iGpffffa980, idx + 1);
    lx = 89.0f + (baseX + *(f32 *)(row + 0x1D8));
    ly = -13.0f + (f22 + (118.0f + (baseY + *(f32 *)(row + 0x1DC))));
    alphaLoop = (u8)((f32)row[0x1E2] * scale);
    {
        s32 i;
        for (i = 0; i < 2; i++) {
            s32 tbl = *(s32 *)(arg1 + (s32)buf[i] * 4 + 0x5EC);
            func_0034f2e0((void *)tbl, lx, ly, rgb2r, rgb2g, rgb2b, alphaLoop);
            lx += 22.0f;
        }
    }
    fx = 153.0f + (baseX + *(f32 *)(row + 0x1D8));
    fy = -13.0f + (f22 + (117.0f + (baseY + *(f32 *)(row + 0x1DC))));
    alphaFinal = (u8)((f32)row[0x1E2] * scale);
    if (probe100 == 0) {
        func_0034f2e0(*(void **)(arg1 + 0x69C), fx + 2.0f, fy + 1.0f, rgb2r, rgb2g, rgb2b, alphaFinal);
    } else {
        s32 color = colorBase | (alphaFinal & 0xFF);
        u32 str = func_00354490(idx);
        func_002751a0(fx, fy - 3.0f, 0.0f, color, (s8)mode, 1, (const char *)str, 0, 0x77, -1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00361d20);
#endif
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
        if (func_00106330(i + 0x180) != 0) {
            if ((s16)i >= count) {
                func_0046d730(D_0064E280, 0x37);
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
                func_0046d730(D_0064E280, 0x54);
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
            func_00452080(*(s32 *)(arg2 + 0x704));
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
                func_004598e0(0x1E);
                func_0045aac0(3, 0, 0x1E);
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
        if (func_00122720() != 0) {
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
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s16 temp_2;
    s16 temp_3;

    temp_3 = *(s16 *)(arg0 + 0x18);
    if (temp_3 < *(s16 *)(arg0 + 0x1A)) {
        *(s16 *)(arg0 + 0x18) = temp_3 + 1;
        temp_2 = *(s16 *)(arg0 + 0x18);
        temp_f4 = 1.0f - func_0044b610(iGpffff84a4 * ((f32)temp_2 / (f32)*(s16 *)(arg0 + 0x1A)));
        temp_f3 = *(f32 *)(arg0 + 0);
        temp_f2 = *(f32 *)(arg0 + 8);
        temp_f2 = temp_f2 - temp_f3;
        temp_f1 = *(f32 *)(arg0 + 0xC);
        temp_f0 = *(f32 *)(arg0 + 4);
        temp_f1 = temp_f1 - temp_f0;
        temp_f2 = temp_f2 * temp_f4;
        temp_f1 = temp_f1 * temp_f4;
        temp_f2 = temp_f2 + temp_f3;
        *(f32 *)(arg0 + 0x10) = temp_f2;
        temp_f0 = *(f32 *)(arg0 + 4);
        temp_f0 = p4_00362f00_add(temp_f1, temp_f0);
        *(f32 *)(arg0 + 0x14) = temp_f0;
        return 0;
    }
    return 1;
}
// FUN_003642A0
void func_003642a0(u8 *arg0)
{
    u16 *temp = *(u16 **)(arg0 + 0x38);

    func_003642e0(arg0, NULL);
    *temp |= 2;
}

// FUN_003642E0
void func_003642e0(u8 *arg0, void *arg1)
{
    u16 *temp;

    temp = *(u16 **)(arg0 + 0x38);
    if (arg1 != NULL) {
        *temp |= 1;
    } else {
        *temp &= (u16)~1;
    }
}
/* 752/752 bytes, ten resolved relocations, no alignment tail.
 * Capture both offset widths together: queued renderers consume a signed
 * halfword Y, while the immediate renderer takes its promoted signed word.
 */
// FUN_00366380
void func_00366380(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                   s16 arg8, void *arg9, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
    extern s64 iGpffffabe8;
    extern u8 D_0064E320[];
    extern void func_0045eb20(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    extern void func_0045e8e0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    extern void func_0045e6a0(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg1, f32 fparg2, f32 fparg3);
    f32 v[18][2];
    u8 col[0x48];
    f32 w;
    s32 *src;
    s32 *dst;
    s32 cnt, centerY;
    s32 t1;
    s32 t2;
    f32 h;
    u32 i;
    u32 rgba;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 fx;
    f32 fy;
    PairF32 *p;
    u8 *c;

    src = (s32 *)D_0064E320;
    dst = (s32 *)v;
    cnt = 18;
    do {
        t1 = src[0];
        t2 = src[1];
        src += 2;
        cnt -= 1;
        dst[0] = t1;
        dst[1] = t2;
        dst += 2;
    } while (cnt > 0);
    w = (f32)(arg2 - 10) * fparg2;
    v[0][0] = w * 0.5f + 5.0f;
    h = (f32)(arg3 - 10) * fparg3;
    v[0][1] = h * 0.5f + 5.0f;
    v[5][0] = w + 5.0f;
    v[6][0] = v[5][0] + 2.0f;
    v[7][0] = v[5][0] + 4.0f;
    v[8][0] = v[5][0] + 5.0f;
    v[9][0] = v[5][0] + 5.0f;
    v[9][1] = h + 5.0f;
    v[10][0] = v[5][0] + 4.0f;
    v[10][1] = v[9][1] + 2.0f;
    v[11][0] = v[5][0] + 2.0f;
    v[11][1] = v[9][1] + 4.0f;
    v[12][0] = v[5][0];
    v[12][1] = v[9][1] + 5.0f;
    v[13][1] = v[9][1] + 5.0f;
    v[14][1] = v[9][1] + 4.0f;
    v[15][1] = v[9][1] + 2.0f;
    v[16][1] = v[9][1];
    arg7 = (s32)(s16)(s32)((f32)arg7 - v[0][0]);
    centerY = (arg8 = (s16)(s32)((f32)arg8 - v[0][1]));
    i = 0;
    rgba = ((u32)arg4 << 8) | (u32)arg5;
    r = rgba >> 24;
    g = rgba >> 16;
    b = rgba >> 8;
    a = rgba;
    fx = (f32)arg0;
    fy = (f32)arg1;
    while (i < 18) {
        p = (PairF32 *)v[i];
        p->x += fx;
        p->y += fy;
        c = &col[i * 4];
        c[0] = r;
        c[1] = g;
        c[2] = b;
        c[3] = a;
        i++;
    }
    if (arg9 != 0) {
        if (arg5 == 0xFF) {
            func_0045eb20(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, arg9);
        } else {
            func_0045e8e0(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, arg9);
        }
    } else if (arg5 == 0xFF) {
        iGpffffabe8 |= 0x80;
        func_0045e6a0((s32)(u32)col, (s32)(u32)v, fparg0, 18, 5, arg6, arg7, centerY, fparg1, fparg2, fparg3);
        iGpffffabe8 &= ~0x80;
    } else {
        func_0045e6a0((s32)(u32)col, (s32)(u32)v, fparg0, 18, 5, arg6, arg7, centerY, fparg1, fparg2, fparg3);
    }
}
// FUN_00366670
/* 752/752 bytes, ten resolved relocations. The explicit table copy preserves
 * the entry halfword load; the paired offset assignment preserves both real
 * primitive ABIs. Keep i = 0 before splitting the unsigned packed color.
 */
void func_00366670(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, void *arg9, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) { extern s64 iGpffffabe8;
extern u8 D_0064E3B0[];
extern void func_0045eb20(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
extern void func_0045e8e0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
extern void func_0045e6a0(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg1, f32 fparg2, f32 fparg3);
f32 v[18][2];
u8 col[0x48];
f32 w;
s32 *src;
s32 *dst;
s32 cnt, centerY;
s32 t1;
s32 t2;
f32 h;
u32 i;
u32 rgba;
u8 r;
u8 g;
u8 b;
u8 a;
f32 fx;
f32 fy;
PairF32 *p;
u8 *c;

src = (s32 *)D_0064E3B0;
dst = (s32 *)v;
cnt = 18;
do {
    t1 = src[0];
    t2 = src[1];
    src += 2;
    cnt -= 1;
    dst[0] = t1;
    dst[1] = t2;
    dst += 2;
} while (cnt > 0);
w = (f32)(arg2 - 10) * fparg2;
v[0][0] = w * 0.5f + 5.0f;
h = (f32)(arg3 - 10) * fparg3;
v[0][1] = h * 0.5f + 5.0f;
v[5][0] = w + 5.0f;
v[6][0] = v[5][0] + 3.0f;
v[7][0] = v[5][0] + 4.0f;
v[8][0] = v[5][0] + 5.0f;
v[9][0] = v[5][0] + 5.0f;
v[9][1] = h + 5.0f;
v[10][0] = v[5][0] + 4.0f;
v[10][1] = v[9][1] + 3.0f;
v[11][0] = v[5][0] + 3.0f;
v[11][1] = v[9][1] + 4.0f;
v[12][0] = v[5][0];
v[12][1] = v[9][1] + 5.0f;
v[13][1] = v[9][1] + 5.0f;
v[14][1] = v[9][1] + 4.0f;
v[15][1] = v[9][1] + 3.0f;
v[16][1] = v[9][1];
arg7 = (s32)(s16)(s32)((f32)arg7 - v[0][0]);
centerY = (arg8 = (s16)(s32)((f32)arg8 - v[0][1]));
i = 0;
rgba = ((u32)arg4 << 8) | (u32)arg5;
r = rgba >> 24;
g = rgba >> 16;
b = rgba >> 8;
a = rgba;
fx = (f32)arg0;
fy = (f32)arg1;
while (i < 18) {
    p = (PairF32 *)v[i];
    p->x += fx;
    p->y += fy;
    c = &col[i * 4];
    c[0] = r;
    c[1] = g;
    c[2] = b;
    c[3] = a;
    i++;
}
if (arg9 != 0) {
    if (arg5 == 0xFF) {
        func_0045eb20(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, arg9);
    } else {
        func_0045e8e0(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, arg9);
    }
} else if (arg5 == 0xFF) {
    iGpffffabe8 |= 0x80;
    func_0045e6a0((s32)(u32)col, (s32)(u32)v, fparg0, 18, 5, arg6, arg7, centerY, fparg1, fparg2, fparg3);
    iGpffffabe8 &= ~0x80;
} else {
    func_0045e6a0((s32)(u32)col, (s32)(u32)v, fparg0, 18, 5, arg6, arg7, centerY, fparg1, fparg2, fparg3);
} }
/* 780/784 bytes; nine resolved relocations; four zero alignment bytes.
 * Keep the angle and shared scale local to each primitive call. */
#pragma push
#pragma opt_propagation off
// FUN_00366960
void func_00366960(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                   s32 alpha, s32 mode, s32 centerX, s16 centerY,
                   const struct RwMatrixTag *matrix, void *queue)
{
    extern s64 iGpffffabe8;
    extern void func_0045eb20(void *, void *, f32, s32, s32, s32, s32, s16, f32, f32, f32, void *);
    extern void func_0045e8e0(void *, void *, f32, s32, s32, s32, s32, s16, f32, f32, f32, void *);
    extern void func_0045e6a0(s32, s32, f32, u32, s32, s32, s32, s32, f32, f32, f32);
    f32 points[4][2] = { 0.0f };
    u8 colors[16];
    RwV3d transformed;
    u32 i;
    u32 packed;
    u8 r, g, b, a;

    points[1][0] = (f32)width;
    points[2][0] = points[1][0];
    points[2][1] = (f32)height;
    points[3][1] = points[2][1];
    i = 0;
    packed = ((u32)rgb << 8) | (u32)alpha;
    r = (u8)(packed >> 24);
    g = (u8)(packed >> 16);
    b = (u8)(packed >> 8);
    a = (u8)packed;
    while (i < 4) {
        u8 *color;
        f32 *point;
        f32 *pointY;
        color = &colors[i * 4];
        color[0] = r;
        color[1] = g;
        color[2] = b;
        color[3] = a;
        point = points[i];
        transformed.x = point[0] - (f32)centerX;
        pointY = point + 1;
        transformed.y = point[1] - (f32)centerY;
        transformed.z = 0.0f;
        func_003e4320(&transformed, &transformed, matrix);
        point[0] = transformed.x + (f32)x;
        *pointY = transformed.y + (f32)y;
        i++;
    }
    if (queue) {
        if (alpha == 255) {
            {
                f32 angle = 0.0f;
                f32 scale = 1.0f;
                func_0045eb20(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale, queue);
            }
        } else {
            {
                f32 angle = 0.0f;
                f32 scale = 1.0f;
                func_0045e8e0(colors, points, z, 4, 5, mode, 0, 0, angle, scale, scale, queue);
            }
        }
    } else if (alpha == 255) {
        iGpffffabe8 |= 0x80;
        {
            f32 angle = 0.0f;
            f32 scale = 1.0f;
            func_0045e6a0((s32)(u32)colors, (s32)(u32)points, z, 4, 5, mode, 0, 0, angle, scale, scale);
        }
        iGpffffabe8 &= ~0x80;
    } else {
        {
            f32 angle = 0.0f;
            f32 scale = 1.0f;
            func_0045e6a0((s32)(u32)colors, (s32)(u32)points, z, 4, 5, mode, 0, 0, angle, scale, scale);
        }
    }
}
/* Matched inside the same opt_propagation-off region as func_00366960: with
   propagation on MWCC folds the four edge differences into the mula.s/msub.s
   operands and evaluates them lazily, where retail computes dx1, dy1, dx2,
   dy2 in order first.  z is the third parameter (ABI-identical to the
   draft's order: ints fill $a0-$t3 and floats $f12 independently), which
   is what homes it in $f21 at the prologue; the identity matrix is
   RwMatrixSetIdentity's chained-assignment order; the render-state table
   goes through a u8 * copy so its address stays in $s0 across the calls;
   D_008872F8 is read as an absolute array element. */
// FUN_00366C70
s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                  s32 alpha, s32 mode, s16 centerX, s16 centerY,
                  struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2])
{
    typedef struct {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } P4Matrix;
    RwV3d transformed;
    f32 points[4][2] = { 0.0f };
    f32 defaultUv[4][2];
    P4Vertex66C70 vertices[4];
    P4Matrix identity;
    s32 *src;
    s32 *dst;
    s32 lo;
    s32 hi;
    s32 count;
    f32 depth;
    f32 inverse;
    u32 packed;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    u32 i;
    f32 cross;
    f32 dx1;
    f32 dy1;
    f32 dx2;
    f32 dy2;
    u8 *table;

    points[1][0] = (f32)width;
    points[2][1] = (f32)height;
    points[3][0] = points[1][0];
    points[3][1] = points[2][1];
    src = D_0064E440;
    dst = (s32 *)defaultUv;
    count = 4;
    do {
        lo = src[0];
        hi = src[1];
        src += 2;
        count -= 1;
        dst[0] = lo;
        dst[1] = hi;
        dst += 2;
    } while (count > 0);
    if (matrix == NULL) {
        identity.right.x = identity.up.y = identity.at.z = 1.0f;
        identity.right.y = identity.right.z = identity.up.x = 0.0f;
        identity.up.z = identity.at.x = identity.at.y = 0.0f;
        identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
        identity.flags |= 0x20003;
        matrix = (struct RwMatrixTag *)&identity;
    }
    if (uv == NULL) {
        uv = defaultUv;
    }
    inverse = 1.0f / *(f32 *)(func_00457120() + 0x80);
    depth = D_008872F8[0] - z;
    packed = ((u32)rgb << 8) | (u32)alpha;
    r = (packed >> 24) & 0xFF;
    g = (packed >> 16) & 0xFF;
    b = (packed >> 8) & 0xFF;
    a = packed & 0xFF;
    i = 0;
    while (i < 4) {
        u8 *point;
        P4Vertex66C70 *vertex;

        point = (u8 *)points + i * 8;
        transformed.x = *(f32 *)(point + 0) - (f32)centerX;
        transformed.y = *(f32 *)(point + 4) - (f32)centerY;
        transformed.z = 0.0f;
        func_003e4320(&transformed, &transformed, matrix);
        transformed.x = transformed.x + (f32)x;
        transformed.y = transformed.y + (f32)y;
        vertex = &vertices[i];
        vertex->x = transformed.x;
        vertex->y = transformed.y;
        vertex->z = depth;
        vertex->r = (f32)r;
        vertex->g = (f32)g;
        vertex->b = (f32)b;
        vertex->a = (f32)a;
        vertex->u = *(f32 *)((u8 *)uv + i * 8);
        vertex->v = *(f32 *)((u8 *)uv + i * 8 + 4);
        vertex->w = inverse;
        i++;
    }
    dx1 = vertices[1].x - vertices[0].x;
    dy1 = vertices[1].y - vertices[0].y;
    dx2 = vertices[2].x - vertices[0].x;
    dy2 = vertices[2].y - vertices[0].y;
    cross = dx1 * dy2 - dy1 * dx2;
    if (mode & 2) {
        if (cross <= 0.0f) {
            return 0;
        }
    } else if ((mode & 4) && cross >= 0.0f) {
        return 0;
    }
    if (mode & 1) {
        table = (u8 *)D_00887300;
        (*(P4RenderState66C70 *)table)(6, 1);
        (*(P4RenderState66C70 *)table)(7, 2);
        (*(P4RenderState66C70 *)table)(8, 1);
        (*(P4RenderState66C70 *)table)(9, 2);
        (*(P4RenderState66C70 *)table)(0xC, 1);
        (*(P4RenderState66C70 *)table)(0xB, 6);
        (*(P4RenderState66C70 *)table)(0xA, 5);
        (*(P4RenderState66C70 *)table)(2, 4);
        (*(P4RenderState66C70 *)table)(0xE, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x44);
    }
    table = (u8 *)D_00887300;
    (*(P4RenderState66C70 *)table)(1, texture);
    D_00887310[0](4, vertices, 4);
    (*(P4RenderState66C70 *)table)(1, 0);
    return 1;
}
#pragma pop
// FUN_003671D0
void func_003671d0(s16 *arg0)
{
    memset((u8 *)arg0 + 4, 0, 0x18);
    *arg0 = 0;
}

// FUN_00367210
void func_00367210(P4Pair arg0, f32 arg4, s32 arg1, s16 *arg2)
{
    s16 temp_3;

    if (arg1 & 0xFF) {
        temp_3 = *arg2;
        switch (temp_3) {
        case 0:
            func_00367420(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 1:
            func_003675f0(*(PairBits *)&arg0, arg4, arg1);
            return;
        case 2:
            func_003676f0(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 3:
            func_00367940(arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 4:
            func_003679c0(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 5:
            func_00367b80(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            return;
        case 6:
            func_00367d00(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            break;
        }
    }
}
// FUN_003672D0
// MATCH: 336B/336B. IDA-backed lookup lifetimes and canonical return contracts.
void func_003672d0(void *work, s16 pcId)
{
    u8 *state = (u8 *)work + 4;
    s32 personaId = (u16)func_00105290(pcId);
    PersonaWork *persona = func_0010a900((u16)pcId);
    *(s16 *)state = pcId;
    *(u8 **)(state + 16) = func_00109220(personaId);
    *(u8 *)(state + 20) = func_00109280(personaId);
    *(u8 *)(state + 21) = datPersonaGetLevel((s32)persona);
    if (pcId == 1) {
        s16 i;
        *(s32 *)(state + 12) = func_00105a50(pcId);
        for (i = 0; i < 5; i++)
            *(s16 *)(state + i * 2 + 2) = func_00104f10(i);
    } else {
        s32 remaining;
        PersonaWork *other = func_0010a900((u16)pcId);
        u32 next = func_00109440(other);
        // Retail subtracts in 32 bits, then applies a signed lower clamp.
        remaining = (s32)(next - datPersonaGetNextExp((s32)other));
        if (remaining < 0)
            remaining = 0;
        *(s32 *)(state + 12) = remaining;
    }
}
// FUN_00367420
void func_00367420(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    f32 y = *((f32 *)&arg0 + 1);
    PairBits temp;
    extern void func_00367b80(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2);

    if (arg1 & 0xFF) {
        temp.f.x = *(f32 *)&arg0 - 10.0f;
        temp.f.y = y + 20.0f;
        func_003675f0(temp, fparg0, arg1);

        temp.f.x = *(f32 *)&arg0 + 17.0f;
        temp.f.y = y + 76.0f;
        func_00367d00(temp.raw, fparg0, arg1, arg2);

        temp.f.x = *(f32 *)&arg0 + 105.0f;
        temp.f.y = y + 23.0f;
        func_00367940(*(P4Pair *)&temp, fparg0, arg1, arg2);

        temp.f.x = *(f32 *)&arg0 + 98.0f;
        temp.f.y = y + 85.0f;
        func_003679c0(temp.raw, fparg0, arg1, arg2);

        temp.f.x = *(f32 *)&arg0 + 22.0f;
        temp.f.y = y + 111.0f;
        func_003676f0(temp.raw, fparg0, arg1, arg2);

        temp.f.x = *(f32 *)&arg0 + 106.0f;
        temp.f.y = *(f32 *)&arg0 + 108.0f;
        func_00367b80(temp.raw, fparg0, arg1, arg2);
    }
}
// FUN_003675F0
void func_003675f0(PairBits arg0, f32 fparg0, s32 arg1)
{
    s32 temp;
    s32 alpha;

    temp = func_0046a770(D_005E5810);
    if (temp == 0) {
        func_0046d730(D_0064E460, 0xB5);
    }
    alpha = arg1 & 0xFF;
    alpha = 0xFF - alpha;
    func_0046d4c0(0, temp, 0x49, arg0.f.x, arg0.f.y,
                  alpha & 0xFF, 0xFB, 0xA2, 0, fparg0, 0);
    func_0046d4c0(0, temp, 0x48, 108.0f + arg0.f.x,
                  arg0.f.y, alpha & 0xFF,
                  0xFB, 0xA2, 0, fparg0, 0);
}
// FUN_003676F0
void func_003676f0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    f32 factor;
    s32 alpha;
    s32 tex0;
    u8 value;
    s16 offset;
    s32 tex1;
    f32 y;
    f32 ybase;
    f32 xbase;

    factor = fparg0;
    value = *(u8 *)(arg2 + 0x19);
    tex0 = func_0046a770(D_005E5810);
    if (tex0 == 0) {
        func_0046d730(D_0064E460, 0xDD);
    }
    tex1 = func_0046a770(D_005E5850);
    if (tex1 == 0) {
        func_0046d730(D_0064E460, 0xDF);
    }
    alpha = arg1 & 0xFF;
    alpha = 0xFF - alpha;
    y = *((f32 *)&arg0 + 1);
    func_0046d4c0(0, tex1, 0x3C, *(f32 *)&arg0, y,
                  alpha, 0xFF, 0xFF, 0x81, factor, 0);
    func_0046d4c0(0, tex1, 0x3B, *(f32 *)&arg0 + 76.0f, y,
                  alpha, 0xFF, 0xFF, 0x81, factor, 0);
    func_0046d4c0(0, tex1, 0x2A, *(f32 *)&arg0 + 7.0f, y + 38.0f,
                  alpha, 0xFB, 0xA2, 0, factor, 0);
    if (value < 10) {
        offset = 11;
    } else {
        offset = 0;
    }
    ybase = y + 31.0f;
    xbase = *(f32 *)&arg0 + 59.0f;
    while (value > 0) {
        func_0046d4c0(0, tex1, (value % 10) + 0x1D,
                      xbase - (f32)offset, ybase,
                      alpha, 0xFF, 0xA2, 0, factor, 0);
        offset += 22;
        value /= 10;
    }
}
// FUN_00367B80
/* measured: opt_common_subs off keeps the raw alpha argument in $s1 and re-masks it at each of
   its two uses (color entry, 0xFF - alpha at the sprite call) as retail does; with CSE on b210
   masks once into $s0 (nd 78). */
#pragma opt_common_subs off
void func_00367b80(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    
    f32 scale;
    s32 color;
    s32 tex;
    s32 value;
    f32 y;

    scale = fparg0;
    color = (arg1 & 0xFF) | 0xFFFFFF00;
    tex = func_0046a770(D_005E5810);
    if (tex == 0) {
        func_0046d730(D_0064E460, 0x174);
    }
    if (func_0046a770(D_005E5830) == 0) {
        func_0046d730(D_0064E460, 0x176);
    }
    y = *((f32 *)&arg0 + 1);
    func_00274ed0((f32)(s32)*(f32 *)&arg0, (f32)(s32)y, 0.0f, color, 6, 1, *(const char **)(arg2 + 0x14), 0, 0);
    value = *(u8 *)(arg2 + 0x18);
    if (value <= 0 || value >= 0x20) {
        func_0046d730(D_0064E460, 0x186);
    }
    func_0046d4c0(0, tex, (u8)((u8)value - 1) + 0x21, *(f32 *)&arg0, 30.0f + y,
                  (u8)(0xFF - (arg1 & 0xFF)), 0xEC, 0x7C, 0, scale, 0);
}

#pragma opt_common_subs on
// FUN_00367940
void func_00367940(P4Pair arg0, f32 fparg0, s32 arg1, u8 *arg2) { u8 tmp[12]; f32 factor; factor = fparg0; func_0011fd30(tmp); *(s32 *)(tmp + 8) = 3; *(s16 *)(tmp + 6) = 1; *(s16 *)tmp = *(s16 *)(arg2 + 4); func_0011fd50(*(s64 *)&arg0, factor, arg1, tmp, 1); }

// FUN_003679C0
/* measured: nd 9 -> 0. opt_loop_invariants on hoists the digit loop's 16.0f and 10
   ahead of the entry branch. Alpha: `n = arg1 & 0xFF; arg1 = 0xFF - n;` through the
   loop counter's register puts the andi before the li (fresh local or one expression: nd 3). */
#pragma opt_loop_invariants on
void func_003679c0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    f32 scale;
    s32 tex1;
    s32 tex2;
    s32 value;
    s32 n;
    f32 x;
    f32 y;
    f32 ty;

    scale = fparg0;
    y = *((f32 *)&arg0 + 1);
    tex1 = func_0046a770(D_005E5810);
    if (tex1 == 0) {
        func_0046d730(D_0064E460, 0x13D);
    }
    tex2 = func_0046a770(D_005E5830);
    if (tex2 == 0) {
        func_0046d730(D_0064E460, 0x13F);
    }
    n = arg1 & 0xFF;
    arg1 = 0xFF - n;
    func_0046d4c0(0, tex1, 0x39, *(f32 *)&arg0, y, arg1, 0xFB, 0xA2, 0, scale, 0);
    x = 130.0f + *(f32 *)&arg0;
    ty = 4.0f + y;
    value = *(s32 *)(arg2 + 0x10);
    n = value;
    while (n >= 10) {
        x += 16.0f;
        n /= 10;
    }
    do {
        func_0046d4c0(0, tex2, (value % 10) + 9, x, ty, arg1, 0x2D, 0x2D, 0x2D, scale, 0);
        value /= 10;
        x -= 16.0f;
    } while (value > 0);
}
/* measured: closes the loop-invariant bracket; the file default is off. */
#pragma opt_loop_invariants off

// FUN_00367D00
// measured: test ordered float loads with propagation disabled
#pragma opt_propagation off
void func_00367d00(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    s32 alpha;
    u8 value;
    s32 tex0;
    s16 offset;
    s32 tex1;
    f32 y;
    f32 first_y;
    f32 ybase;
    f32 xbase;
    f32 first_const;
    f32 first_9;
    f32 first_x;
    f32 factor;

    value = (u8)func_00104c70(*(s16 *)(arg2 + 4));
    factor = fparg0;
    tex0 = func_0046a770(D_005E5850);
    if (tex0 == 0) {
        func_0046d730(D_0064E460, 0x1A1);
    }
    tex1 = func_0046a770(D_005E57F0);
    if (tex1 == 0) {
        func_0046d730(D_0064E460, 0x1A3);
    }
    alpha = arg1 & 0xFF;
    alpha = 0xFF - alpha;
    y = *((f32 *)&arg0 + 1);
    first_y = y - 48.0f;
    first_const = 14.0f;
    first_9 = 9.0f;
    first_x = *(f32 *)&arg0;
    first_x = p4_00362f00_add(first_9, first_x);
    first_x = p4_00362f00_add(first_const, first_x);
    func_0046d4c0(0, tex0, 0xC9,
                  first_x, first_y,
                  alpha, 0xEF, 0x89, 0, factor, 0);
    func_0046d4c0(0, tex1, 0x1E, *(f32 *)&arg0 + 58.0f,
                  y - 23.0f, alpha, 0xD1, 0x6B, 0, factor, 0);
    if (value < 10) {
        offset = 11;
    } else {
        offset = 0;
    }
    ybase = first_y - 5.0f;
    xbase = *(f32 *)&arg0 + 64.0f;
    while (value > 0) {
        func_0046d4c0(0, tex0, (value % 10) + 0x1D,
                      xbase - (f32)offset, ybase,
                      alpha, 0xFF, 0xFF, 0x81, factor, 0);
        offset += 22;
        value /= 10;
    }
}
// measured: restore default propagation
#pragma opt_propagation on

// FUN_00368D30
void func_00368d30(u8 *arg0)
{
    RwV3d p1;
    RwV3d p2;
    RwV3d p3;
    RwV3d p4;
    u8 color;

    func_00367f50();
    *(s32 *)(arg0 + 4) = 3;
    func_0036a900(arg0 + 0xE0);
    p1.x = 3.0f;
    p1.y = fGpffff8390;
    p1.z = 0.0f;
    *(RwV3d *)(arg0 + 0x170) = p1;
    p2.x = -3.0f;
    p2.y = p1.y;
    p2.z = 0.0f;
    *(RwV3d *)(arg0 + 0x194) = p2;
    p3.x = -3.0f;
    p3.y = fGpffff8394;
    p3.z = 0.0f;
    *(RwV3d *)(arg0 + 0x1B8) = p3;
    p4.x = 3.0f;
    p4.y = p3.y;
    p4.z = 0.0f;
    *(RwV3d *)(arg0 + 0x1DC) = p4;
    color = 0xFF;
    *(u8 *)(arg0 + 0x17C) = color;
    *(u8 *)(arg0 + 0x17D) = color;
    *(u8 *)(arg0 + 0x17E) = color;
    *(u8 *)(arg0 + 0x17F) = color;
    *(u8 *)(arg0 + 0x1A0) = color;
    *(u8 *)(arg0 + 0x1A1) = color;
    *(u8 *)(arg0 + 0x1A2) = color;
    *(u8 *)(arg0 + 0x1A3) = color;
    *(u8 *)(arg0 + 0x1C4) = color;
    *(u8 *)(arg0 + 0x1C5) = color;
    *(u8 *)(arg0 + 0x1C6) = color;
    *(u8 *)(arg0 + 0x1C7) = color;
    *(u8 *)(arg0 + 0x1E8) = color;
    *(u8 *)(arg0 + 0x1E9) = color;
    *(u8 *)(arg0 + 0x1EA) = color;
    *(u8 *)(arg0 + 0x1EB) = color;
    *(u32 *)(arg0 + 0x18C) = 0x3F7E0000;
    *(u32 *)(arg0 + 0x1B0) = 0;
    *(u32 *)(arg0 + 0x1D4) = 0;
    *(u32 *)(arg0 + 0x1F8) = 0x3F7E0000;
    *(u32 *)(arg0 + 0x190) = 0x3C000000;
    *(u32 *)(arg0 + 0x1B4) = 0x3C000000;
    *(u32 *)(arg0 + 0x1D8) = 0x3F230000;
    *(u32 *)(arg0 + 0x1FC) = 0x3F230000;
}

/* measured: floor v4_switch MISMATCH nd430 obj1452/1472 (-20B -1.36%, >=1428 threshold, not draft); first 124 instrs exact, first residual off 496 FPU dest/coloring (div.s f1 vs f0, add/sub f0/f1 swap); rotation-loop angle f20 vs f24 + lwc1 scheduling + s-pointer materialization; tail flags &2/&1/&8 + jal 0036ae90 shape match; MAC staged intermediates (adda/madd/mula/msub) emittable, no asm. */
// FUN_00368E80 NONMATCHING
#ifdef NON_MATCHING
void func_00368e80(u8 *arg0)
{
    extern f32 D_007612D0;
    extern f32 fGpffff838c;
    extern void func_0036ae90(u8 *arg0, u8 *arg1);
    u8 *base;
    s32 mode;
    f32 ftmp;
    f32 frac3;
    f32 frac16;
    f32 frac4;
    f32 frac2;
    f32 t;
    f32 u;
    f32 acc;
    f32 divv;
    f32 f0v;
    f32 f1v;
    f32 angle;
    f32 c03;
    s32 i;
    s32 j;
    s32 k;
    f32 stack[8];

    base = arg0;
    *(f32 *)(base + 0x3C) += iGpffff8040;
    mode = *(s32 *)(base + 4);
    switch (mode) {
    case 0:
    ftmp = *(f32 *)(base + 0x3C) / 3.0f;
    frac3 = ftmp - (f32)(s32)ftmp;
    *(f32 *)(base + 0x2B8) = frac3;
    *(f32 *)(base + 0x2DC) = frac3;
    *(f32 *)(base + 0x300) = 1.0f + frac3;
    *(f32 *)(base + 0x324) = 1.0f + frac3;
    ftmp = *(f32 *)(base + 0x3C) / 16.0f;
    frac16 = ftmp - (f32)(s32)ftmp;
    *(f32 *)(base + 0x348) = frac16;
    *(f32 *)(base + 0x36C) = frac16;
    *(f32 *)(base + 0x390) = 1.0f + frac16;
    *(f32 *)(base + 0x3B4) = 1.0f + frac16;
    ftmp = *(f32 *)(base + 0x3C) / 4.0f;
    frac4 = ftmp - (f32)(s32)ftmp;
    if (frac4 < 0.5f) {
        c03 = fGpffff8198;
        *(f32 *)(base + 0x5FC) = c03 + ((c03 * frac4) / 0.5f);
    } else {
        t = (frac4 - 0.5f) / 0.5f;
        u = 1.0f - t;
        c03 = fGpffff8198;
        acc = c03 + c03 * u;
        *(f32 *)(base + 0x5FC) = acc;
    }
    ftmp = *(f32 *)(base + 0x3C) / 2.0f;
    frac2 = ftmp - (f32)(s32)ftmp;
    if (frac2 < 0.5f) {
        *(f32 *)(base + 0x5F8) = (0.5f * frac2) / 0.5f;
    } else {
        *(f32 *)(base + 0x5F8) = 0.5f * (1.0f - ((frac2 - 0.5f) / 0.5f));
    }
    acc = 100.0f + 20.0f * frac2;
    divv = acc / 100.0f;
    f1v = 0.5f + (0.38671875f / divv);
    *(f32 *)(base + 0x4F4) = f1v;
    *(f32 *)(base + 0x560) = f1v;
    f0v = 0.5f - (0.38671875f / divv);
    *(f32 *)(base + 0x518) = f0v;
    *(f32 *)(base + 0x53C) = f0v;
    f0v = 0.5f - (0.41015625f / divv);
    *(f32 *)(base + 0x4F8) = f0v;
    *(f32 *)(base + 0x51C) = f0v;
    f0v = 0.5f + (0.41015625f / divv);
    *(f32 *)(base + 0x540) = f0v;
    *(f32 *)(base + 0x564) = f0v;
        break;
    case 1:
    ftmp = *(f32 *)(base + 0x3C) / 2.0f;
    frac2 = ftmp - (f32)(s32)ftmp;
    if (frac2 < 0.5f) {
        *(f32 *)(base + 0x32C) = (fGpffff838c * frac2) / 0.5f;
    } else {
        t = (frac2 - 0.5f) / 0.5f;
        u = 1.0f - t;
        *(f32 *)(base + 0x32C) = fGpffff838c * u;
    }
    acc = 70.0f + 20.0f * frac2;
    divv = acc / 100.0f;
    f1v = 0.5f + (0.38671875f / divv);
    *(f32 *)(base + 0x2B4) = f1v;
    *(f32 *)(base + 0x320) = f1v;
    f0v = 0.5f - (0.38671875f / divv);
    *(f32 *)(base + 0x2D8) = f0v;
    *(f32 *)(base + 0x2FC) = f0v;
    f0v = 0.5f - (0.41015625f / divv);
    *(f32 *)(base + 0x2B8) = f0v;
    *(f32 *)(base + 0x2DC) = f0v;
    f0v = 0.5f + (0.41015625f / divv);
    *(f32 *)(base + 0x300) = f0v;
    *(f32 *)(base + 0x324) = f0v;
        break;
    }
done:
    if (((*(s32 *)base) & 2) != 0) {
        if (*(s32 *)(base + 4) == 0) {
            f32 *pa;
            f32 *pb;
            f32 x;
            f32 y;
            f32 c;
            f32 s;
            f32 nx;
            f32 ny;
            stack[0] = 1.0f;
            stack[1] = 1.0f;
            stack[2] = 0.0f;
            stack[3] = 1.0f;
            stack[4] = 0.0f;
            stack[5] = 0.0f;
            stack[6] = 1.0f;
            stack[7] = 0.0f;
            angle = D_007612D0 * (*(f32 *)(base + 0x3C) / 4.0f);
            for (i = 0; i < 4; i++) {
                stack[i * 2] -= 0.5f;
                stack[i * 2 + 1] -= 0.5f;
            }
            for (j = 0; j < 4; j++) {
                pa = &stack[j * 2];
                pb = pa + 1;
                x = pa[0];
                y = pb[0];
                c = func_0044b7b0(angle);
                s = func_0044b610(angle);
                nx = x * s - y * c;
                c = func_0044b7b0(angle);
                s = func_0044b610(angle);
                ny = y * s + x * c;
                pa[0] = nx;
                pb[0] = ny;
            }
            for (k = 0; k < 4; k++) {
                stack[k * 2] += 0.5f;
                stack[k * 2 + 1] += 0.5f;
            }
            *(f32 *)(base + 0x584) = stack[0];
            *(f32 *)(base + 0x588) = stack[1];
            *(f32 *)(base + 0x5A8) = stack[2];
            *(f32 *)(base + 0x5AC) = stack[3];
            *(f32 *)(base + 0x5CC) = stack[4];
            *(f32 *)(base + 0x5D0) = stack[5];
            *(f32 *)(base + 0x5F0) = stack[6];
            *(f32 *)(base + 0x5F4) = stack[7];
        }
    }
    if (((*(s32 *)base) & 1) != 0) {
        *(s32 *)(base + 0x44) += 0x10000;
        if (*(s32 *)(base + 0x48) != 1) {
            if (*(s32 *)(base + 0x48) == 0) {
                if ((u32)*(s32 *)(base + 0x44) >= 0x1E0000U) {
                    *(s32 *)base &= ~1;
                }
            }
        }
    }
    if (((*(s32 *)base) & 8) != 0) {
        func_0036ae90(*(u8 **)(base + 0xDC), base);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00368e80);
#endif
// FUN_00369470
void func_00369470(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00369440;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

/* measured: floor v12 MISMATCH nd292 exact-size 1504/1504 (delta 0, >=1459 threshold, not draft); frame -0x130 vs -0x140 + FPR/GPR coloring wall (swc1 f23/f22/f21/f20, s4/s3 vs s4/s2, mtx s5 vs s0, lwc1 f20/f22/f21 vs f2/f1/f0); reflection 2.0f*t-o adopted (-16) + exact size; MAC dot MULA-MADDA-MADD + (f32)(u32) 2147483648.0f lui 0x4F00 kept direct. */
// FUN_0036AE90 NONMATCHING
#ifdef NON_MATCHING
void func_0036ae90(u8 *arg0, u8 *arg1) {
    extern u8 *func_00457120(void);
    extern u8 *func_003e9700(s32 arg0);
    extern u8 *func_003e0f80(void);
    extern void func_0036abd0(void *arg0, void *arg1);
    extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src, const void *matrix);
    extern void func_003e42a0(void *dst, void *src, void *cam);
    extern void func_003e40b0(void *dst, void *src);
    extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void func_003e0f40(void *arg0);
    extern u8 D_0064E490[];
    extern u8 D_0064E498[];
    extern u8 D_0064E4A0[];
    extern u8 D_0064E4A8[];
    extern u8 D_0064E4B0[];
    extern u8 D_0064E4B8[];
    extern u8 D_0064E4C0[];
    extern u8 D_0064E4C8[];
    extern f32 fGpffff83fc;
    RwV3d stack130;
    RwV3d stack120;
    RwV3d stack110;
    RwV3d stackF0;
    RwV3d stack100;
    RwV3d stackE0;
    RwV3d stackD0;
    RwV3d stackC0;
    RwV3d stackB0;
    u8 *cam;
    u8 *mtx;
    u8 *tmp;
    f32 dot;
    s32 outer;
    s32 inner;
    s32 limit;
    f32 fx;
    f32 dot2;
    f32 pow6;
    f32 dot3;
    f32 clamped;
    f32 combined;
    u8 abyte;
    f32 af;
    f32 scaled;

    *(s64 *)&stack130 = *(s64 *)D_0064E490;
    *(f32 *)((u8 *)&stack130 + 8) = *(f32 *)D_0064E498;
    tmp = func_00457120();
    mtx = func_003e9700(*(s32 *)(tmp + 4)) + 0x30;
    *(s64 *)&stackD0 = *(s64 *)D_0064E4A0;
    *(f32 *)((u8 *)&stackD0 + 8) = *(f32 *)D_0064E4A8;
    *(s64 *)&stackC0 = *(s64 *)D_0064E4B0;
    *(f32 *)((u8 *)&stackC0 + 8) = *(f32 *)D_0064E4B8;
    *(s64 *)&stackB0 = *(s64 *)D_0064E4C0;
    *(f32 *)((u8 *)&stackB0 + 8) = *(f32 *)D_0064E4C8;
    cam = func_003e0f80();
    func_0036abd0(cam, arg1);
    func_003e4320(&stackD0, &stackD0, cam);
    stackE0.x = *(f32 *)(arg0 + 0x994);
    stackE0.y = *(f32 *)(arg0 + 0x998);
    stackE0.z = *(f32 *)(arg0 + 0x99C);
    if (*(s32 *)(arg1 + 0x38) != 0) {
        func_003e42a0(&stack100, arg1 + 0x20, func_003e9700(*(s32 *)(arg1 + 0x38)));
    } else {
        stack100.x = *(f32 *)(arg1 + 0x20);
        stack100.y = *(f32 *)(arg1 + 0x24);
        stack100.z = *(f32 *)(arg1 + 0x28);
    }
    dot = stackD0.x * (*(f32 *)mtx - stack100.x) + stackD0.y * (*(f32 *)(mtx + 4) - stack100.y) + stackD0.z * (*(f32 *)(mtx + 8) - stack100.z);
    *(s32 *)arg0 &= ~1;
    if (dot < 0.0f) {
        func_003e0870(cam, &stackC0, 1, 180.0f);
        *(s32 *)arg0 |= 1;
    }
    stack100.x = 0.0f;
    stack100.y = 0.0f;
    stack100.z = 100.0f;
    func_003e42a0(&stack100, &stack100, cam);
    func_003e4320(&stackB0, &stack130, cam);
    func_003e40b0(&stackB0, &stackB0);
    {
        u8 *dst = arg0 + 4;
        f32 ey = stackE0.y;
        f32 ez = stackE0.z;
        for (outer = 0; outer < 9; outer++) {
            if ((~outer & 1) != 0) {
                limit = 8;
            } else {
                limit = 7;
            }
            for (inner = 0; inner < limit; inner++) {
                if ((~outer & 1) == 0) {
                    fx = (f32)inner;
                } else if (inner == 0) {
                    fx = 0.0f;
                } else if (inner == limit - 1) {
                    fx = 6.0f;
                } else {
                    fx = (f32)(inner - 1) + 0.5f;
                }
                stack100.x = fx - 3.0f;
                stack100.y = fGpffff83fc * ((f32)outer / 8.0f - 0.5f);
                stack100.z = 0.0f;
                func_003e42a0(&stackF0, &stack100, cam);
                stack110.x = stackF0.x - *(f32 *)mtx;
                stack110.y = stackF0.y - *(f32 *)(mtx + 4);
                stack110.z = stackF0.z - *(f32 *)(mtx + 8);
                func_003e40b0(&stack110, &stack110);
                stack120.x = stackF0.x - stackE0.x;
                stack120.y = stackF0.y - ey;
                stack120.z = stackF0.z - ez;
                func_003e40b0(&stack120, &stack120);
                dot2 = stack110.x * stack130.x + stack110.y * stack130.y + stack110.z * *(((f32 *)&stack130) + 2);
                {
                    f32 t1 = *(((f32 *)&stack130) + 2) * dot2;
                    f32 t2 = stack130.x * dot2;
                    f32 t3 = stack130.y * dot2;
                    f32 u1 = 2.0f * t1 - stack110.z;
                    f32 u2 = 2.0f * t2 - stack110.x;
                    f32 u3 = 2.0f * t3 - stack110.y;
                    f32 v1 = stack120.x * u2 + stack120.y * u3 + stack120.z * u1;
                    if (v1 <= 0.0f) {
                        pow6 = 0.0f;
                    } else {
                        pow6 = v1 * v1 * v1 * v1 * v1 * v1;
                    }
                }
                stack120.x = stackE0.x - stackF0.x;
                stack120.y = ey - stackF0.y;
                stack120.z = ez - stackF0.z;
                func_003e40b0(&stack120, &stack120);
                dot3 = stack120.x * stackB0.x + stack120.y * stackB0.y + stack120.z * *(((f32 *)&stackB0) + 2);
                clamped = 0.0f;
                if (!(dot3 <= 0.0f)) {
                    clamped = dot3;
                }
                combined = pow6 * *(f32 *)(arg0 + 0x9A0) + clamped * *(f32 *)(arg0 + 0x9A4);
                if (!(combined <= 1.0f)) {
                    combined = 1.0f;
                }
                abyte = *(u8 *)(arg1 + 0x43);
                af = (f32)(u32)abyte;
                scaled = af * combined;
                if (scaled >= 2147483648.0f) {
                    dst[0xC] = (u8)((s32)(scaled - 2147483648.0f) | 0x80000000);
                } else {
                    dst[0xC] = (u8)(s32)scaled;
                }
                dst[0xD] = dst[0xC];
                dst[0xE] = dst[0xC];
                dst[0xF] = dst[0xC];
                dst += 0x24;
            }
        }
    }
    func_003e0f40(cam);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_0036ae90);
#endif
// FUN_0036B630
void func_0036b630(u8 *arg0, RwV3d *arg1)
{
    *(RwV3d *)(arg0 + 0x994) = *arg1;
}
// FUN_0036D860
void func_0036d860(u8 *arg0, s32 arg1)
{
    func_0036b650(arg0);
    func_0036aa20();
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
    s32 temp_2;

    temp_2 = (s32)func_00457120();
    func_003e8180((void *)temp_2, 1.0f);
    local.f30 = 0;
    local.f34 = 0;
    local.f38 = 0;
    local.f20 = 0;
    local.f24 = 0;
    local.f28 = 0x43480000;
    func_004577d0((void *)temp_2, 100.0f);
    func_00457630((void *)temp_2, &local.f30, &local.f20, 0);
}
// FUN_0036D940
void func_0036d940(void)
{
    func_0036bbf0();
}

// FUN_0036D960
s32 func_0036d960(void)
{
    func_0036b750();
    return !func_0036bb60();
}
