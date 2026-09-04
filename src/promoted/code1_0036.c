#include "include_asm.h"
#include "type.h"
typedef struct {
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
extern s32 func_00104c70(s16 arg0);

extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00369440(void);
extern u8 *func_00457120(void);
extern void func_003e8180(void *arg0, f32 arg1);
extern void func_004577d0(void *arg0, f32 arg1);
extern void func_00457630(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void func_0011fd30(u8 *arg0);
extern void func_0011fd50(s64 arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
extern void func_0046d280(s32 arg0);
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
/* func_00367b80: retail prototype (the dispatcher keeps its own block-scope (void) declaration so
   it still preserves the incoming registers as retail does). */
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
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
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
extern void *func_003e4320(void *dst, void *src, void *matrix);
extern f32 func_0044b7b0(f32 arg0);
extern void func_003f6440(s32 arg0, s32 arg1);
extern s32 D_0064E440[];
extern f32 D_008872F8;
extern P4RenderState66C70 D_00887300[];
extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
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
            func_0046d280(temp_4);
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

// FUN_00361D20
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00361d20);
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
// FUN_003627B0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003627b0);
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
// FUN_00366380
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366380);
// FUN_00366670
/* measured: nd 152 -> 0. The vertex table is an explicit two-word copy loop from
   D_0064E3B0 (an initialiser hoists the lh of arg8 out of the entry). arg7/arg8 are
   s16 params reassigned in place with the (s16) offsets and the three primitive
   callees take s16 a5/a6, so no dsll32/dsra32 re-extension at the calls; `i = 0`
   before the rgba byte split gives the counter $v0 and the bytes $t4/$t0/$a3/$a2. */
void func_00366670(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8, s32 arg9)
{
    extern s64 iGpffffabe8;
    extern u8 D_0064E3B0[];
    extern s32 func_0045eb20(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s16 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    extern s32 func_0045e8e0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4, s16 a5, s16 a6, f32 f1, f32 f2, f32 f3, void *a7);
    extern void func_0045e6a0(void *arg0, void *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, f32 fparg1, f32 fparg2, f32 fparg3);
    f32 v[18][2];
    u8 col[0x48];
    f32 w;
    s32 *src;
    s32 *dst;
    s32 cnt;
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
    arg7 = (s16)(s32)((f32)arg7 - v[0][0]);
    arg8 = (s16)(s32)((f32)arg8 - v[0][1]);
    i = 0;
    rgba = (arg4 << 8) | arg5;
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
            func_0045eb20(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, (void *)arg9);
        } else {
            func_0045e8e0(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3, (void *)arg9);
        }
    } else if (arg5 == 0xFF) {
        iGpffffabe8 |= 0x80;
        func_0045e6a0(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3);
        iGpffffabe8 &= ~0x80;
    } else {
        func_0045e6a0(col, v, fparg0, 18, 5, arg6, arg7, arg8, fparg1, fparg2, fparg3);
    }
}
// FUN_00366960
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366960);
// FUN_00366C70
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00366c70);
// FUN_003671D0
void func_003671d0(s16 *arg0)
{
    memset((u8 *)arg0 + 4, 0, 0x18);
    *arg0 = 0;
}

// FUN_00367210
void func_00367210(P4Pair arg0, f32 arg4, s32 arg1, s16 *arg2, s32 arg3)
{
    s16 temp_3;
    extern void func_00367b80(void);

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
            func_00367b80();
            return;
        case 6:
            func_00367d00(*(s64 *)&arg0, arg4, arg1, (u8 *)arg2);
            break;
        }
    }
}
/* measured: best archived candidate is in build/E367_003672D0_body.c; object 340B, window 336B, normalized_diff 102. */
// FUN_003672D0
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_003672d0);
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
    extern s32 func_00274ed0(f32 x, f32 y, f32 scale, s32 color, s32 chr, s32 id, s32 str, s32 flags, s32 arg8);
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
    func_00274ed0((f32)(s32)*(f32 *)&arg0, (f32)(s32)y, 0.0f, color, 6, 1, *(s32 *)(arg2 + 0x14), 0, 0);
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

// FUN_00368E80
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_00368e80);
// FUN_00369470
void func_00369470(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00369440;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_0036AE90
INCLUDE_ASM("asm/nonmatchings/code1_0036", func_0036ae90);
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
