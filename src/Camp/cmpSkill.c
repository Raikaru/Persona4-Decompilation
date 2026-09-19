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
void func_001437b0(void *, s32, s32);
void func_0046d280(void *);
s32 func_0034c210(void);
s32 func_003b7060(void);
s32 func_0023d8e0(u8 *, u16);
void func_0034f1e0(void);
void func_0034c270(Vec2f, u8, f32);
void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u32 arg4,
                   u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
void func_0034f2e0(void *, f32, f32, u8, u8, u8, u32);
void func_0034f9d0(Vec2f unused, f32 fparg0, u32 arg1, s32 arg2, s32 arg3);
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

    func_0043f9c8(arg0, 0, 0x1338);
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

/* measured: retail keeps var30 in $fp, var19 in $s3, temp20 in $s4 and uses
   a 0x100 frame with 10 saved registers ($fp/$s7..$s0) across the nested
   sort loops; mwcc b210 allocates a 0xD0 frame and different $s6/$s4/$s7
   registers (nd 309). The m2c draft's s128/s64 stack values (sq 0xB0/0xA0/
   0xC0) and the ld/sd swap collapse to different register coloring. Tried
   the m2c body converted to C89 — frame/register allocation floor. */
/* measured: candidate object 393 instrs/retail 397 instrs (1572B/1588B window 1600B, -4, -1.0% INSIDE +-3% band 385-409), probe reloc-masked 317 words (guard below, NON_MATCHING so production stays ASM; fnalign 309 edits +2 reloc-only). 0xD0 frame vs retail 0x100 (10 saves $fp/s7..s0); jal 19 vs 19. Restored dropped sort arm: early sh count to 0x580, nested i/j loops over 0xC entries with 0xC0/0x100 range checks and three swap tails (both-in/both-out/in-vs-out) via f32 moves + outerTmp/innerTmp stack temps, matching retail 3887C-38A20. Dedup 12B copies via f32 (lwc1/swc1) and 0x20A loads via u16 (lhu) per retail opcodes; signedness solver 7 fields no accepts so no type-spelling change. Banked as inside-gate floor. */
// FUN_00138490 NONMATCHING
#ifdef NON_MATCHING
void func_00138490(void *arg0)
{
    u8 *b = (u8 *)arg0;
    s16 sel;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 idx;
    u8 *p;
    u8 *q;
    s32 v;
    s32 w;
    u16 key;
    u16 cur;
    s32 a;
    s32 bv;
    s32 res;
    s32 tmp[4];

    count = 0;
    sel = -1;
    v = *(s16 *)((u8 *)arg0 + 0x5C);
    v = *(s16 *)((u8 *)arg0 + v * 2 + 0xF4);
    if (v == 1) {
        sel = func_0010b510();
        for (i = 0; (u32)i < (func_0010b6f0() & 0xFFFF); i++) {
            v = func_0010ace0((s16)i);
            if (v != 0) {
                func_0010b3b0((s16)i);
                for (j = 0; j < 8; j++) {
                    p = b + count * 12;
                    if (func_00113520(1, v, j, p + 0x100) != 0) {
                        *(s16 *)(p + 0x100) = (s16)i;
                        count++;
                    }
                }
            }
        }
    } else {
        w = func_0010a900((u16)v);
        for (i = 0; i < 8; i++) {
            p = b + count * 12;
            if (func_00113520(v, w, i, p + 0x100) != 0) {
                *(s16 *)(p + 0x100) = -1;
                count++;
            }
        }
    }
    for (i = 0; i < count; i++) {
        p = b + i * 12;
        cur = *(u16 *)(p + 0x102);
        for (j = i + 1; j < count; j++) {
            q = b + j * 12;
            key = *(u16 *)(q + 0x102);
            if (cur == key) {
                if (cur < 0x1B8 && sel != -1) {
                    v = func_0010ace0(*(s16 *)(p + 0x100));
                    a = (s32)func_001094d0(v);
                    res = 0;
                    for (k = 0; k < 8; k++) {
                        if (*(u16 *)(a + k * 2) == 0x20A) {
                            res = 1;
                            break;
                        }
                    }
                    if (res == 0) {
                        v = func_0010ace0(*(s16 *)(q + 0x100));
                        bv = (s32)func_001094d0(v);
                        res = 0;
                        for (k = 0; k < 8; k++) {
                            if (*(u16 *)(bv + k * 2) == 0x20A) {
                                res = 1;
                                break;
                            }
                        }
                        if (res != 0) {
                            *(f32 *)(p + 0x100) = *(f32 *)(q + 0x100);
                            *(f32 *)(p + 0x104) = *(f32 *)(q + 0x104);
                            *(f32 *)(p + 0x108) = *(f32 *)(q + 0x108);
                        } else {
                            func_0010b3b0(*(s16 *)(p + 0x100));
                            func_0010fa80(v, v, *(u16 *)(p + 0x102), 0, tmp, 0, 0);
                            func_0010b3b0(*(s16 *)(q + 0x100));
                            func_0010fa80(v, v, *(u16 *)(q + 0x102), 0, tmp + 2, 0, 0);
                            if (tmp[0] < tmp[2]) {
                                *(f32 *)(p + 0x100) = *(f32 *)(q + 0x100);
                                *(f32 *)(p + 0x104) = *(f32 *)(q + 0x104);
                                *(f32 *)(p + 0x108) = *(f32 *)(q + 0x108);
                            }
                        }
                    }
                }
                count--;
                p = b + count * 12;
                *(f32 *)(q + 0x100) = *(f32 *)(p + 0x100);
                *(f32 *)(q + 0x104) = *(f32 *)(p + 0x104);
                *(f32 *)(q + 0x108) = *(f32 *)(p + 0x108);
                *(s32 *)(p + 0x104) = 0;
                *(s32 *)(p + 0x108) = 0;
                *(u16 *)(p + 0x102) = 0;
                *(s16 *)(p + 0x100) = -1;
            }
        }
    }
    *(s16 *)(b + 0x580) = (s16)count;
    for (i = 0; i < count; i++) {
        u8 *outer;
        f32 outerTmp[3];
        u16 oKey;
        outer = b + i * 12;
        outerTmp[0] = *(f32 *)(outer + 0x100);
        outerTmp[1] = *(f32 *)(outer + 0x104);
        outerTmp[2] = *(f32 *)(outer + 0x108);
        oKey = *(u16 *)((u8 *)outerTmp + 2);
        for (j = i + 1; j < count; j++) {
            u8 *inner;
            f32 innerTmp[3];
            u16 nKey;
            inner = b + j * 12;
            innerTmp[0] = *(f32 *)(inner + 0x100);
            innerTmp[1] = *(f32 *)(inner + 0x104);
            innerTmp[2] = *(f32 *)(inner + 0x108);
            nKey = *(u16 *)((u8 *)innerTmp + 2);
            if (nKey < 0xC0 || nKey >= 0x100) {
                if ((oKey < 0xC0 || oKey >= 0x100) && nKey < oKey) {
                    *(f32 *)(outer + 0x100) = innerTmp[0];
                    *(f32 *)(outer + 0x104) = innerTmp[1];
                    *(f32 *)(outer + 0x108) = innerTmp[2];
                    *(f32 *)(inner + 0x100) = outerTmp[0];
                    *(f32 *)(inner + 0x104) = outerTmp[1];
                    *(f32 *)(inner + 0x108) = outerTmp[2];
                    outerTmp[0] = innerTmp[0];
                    outerTmp[1] = innerTmp[1];
                    outerTmp[2] = innerTmp[2];
                    oKey = nKey;
                }
            } else if (oKey < 0xC0 || oKey >= 0x100) {
                *(f32 *)(outer + 0x100) = innerTmp[0];
                *(f32 *)(outer + 0x104) = innerTmp[1];
                *(f32 *)(outer + 0x108) = innerTmp[2];
                *(f32 *)(inner + 0x100) = outerTmp[0];
                *(f32 *)(inner + 0x104) = outerTmp[1];
                *(f32 *)(inner + 0x108) = outerTmp[2];
                outerTmp[0] = innerTmp[0];
                outerTmp[1] = innerTmp[1];
                outerTmp[2] = innerTmp[2];
                oKey = nKey;
            } else if (nKey < oKey) {
                *(f32 *)(outer + 0x100) = innerTmp[0];
                *(f32 *)(outer + 0x104) = innerTmp[1];
                *(f32 *)(outer + 0x108) = innerTmp[2];
                *(f32 *)(inner + 0x100) = outerTmp[0];
                *(f32 *)(inner + 0x104) = outerTmp[1];
                *(f32 *)(inner + 0x108) = outerTmp[2];
                outerTmp[0] = innerTmp[0];
                outerTmp[1] = innerTmp[1];
                outerTmp[2] = innerTmp[2];
                oKey = nKey;
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
#else
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138490);
#endif

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
/* Floor (measured 2026-09-19, source-repo only, draft): reconstruction from ghidra+m2c with file idioms; unsigned (f32)(u8)/(f32)(u16) kept for bltz/srl/or sites, signed (f32)(s16) for lh sites; float-first draw ABIs per header; 0xA0 frame via locals. Banked as guarded floor; production stays ASM. */
// FUN_00138BF0 NONMATCHING
#ifdef NON_MATCHING
void func_00138bf0(u8 *arg0)
{
    extern s32 func_0013ac30(u16 arg0);
    extern s8 iGpffff9cd0[];
    s32 i;
    s32 j;
    u8 *sprite;
    f32 fx;
    f32 fy;
    f32 opacity;
    u8 alpha;
    f32 f0;
    f32 f1;
    s32 n;
    u8 buf[8];
    f32 sp90;
    f32 sp94;
    s16 st30;
    s16 st2e;
    s16 st2c;
    s32 st28;
    s32 st24;
    s32 st20;
    u8 *pu;
    s32 tmp;
    func_0034f1e0();
    fx = *(f32 *)(arg0 + 4);
    fy = *(f32 *)(arg0 + 8);
    opacity = (f32)*(u8 *)arg0 / 255.0f;
    if (*(s32 *)(arg0 + 0x10) != 0) {
        Vec2f pos;
        sp90 = fx;
        sp94 = fy;
        f0 = 255.0f * opacity;
        alpha = (u8)f0;
        pos.x = sp90;
        pos.y = sp94;
        func_0034c270(pos, alpha, 0.0f);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x1000) != 0) {
        s8 *gsrc;
        s8 *gdst;
        u8 *handle;
        gsrc = (s8 *)iGpffff9cd0;
        gdst = (s8 *)buf;
        n = 4;
        do {
            s8 b0;
            s8 b1;
            b0 = gsrc[0];
            b1 = gsrc[1];
            gsrc += 2;
            n--;
            gdst[0] = b0;
            gdst[1] = b1;
            gdst += 2;
        } while (n > 0);
        handle = *(u8 **)(arg0 + 0x12EC);
        for (i = 0; i < 0x14; i++) {
            u8 *row;
            u8 *tbl;
            u8 b0;
            u8 b1;
            u8 b2;
            u16 u0;
            u16 u1;
            row = arg0 + i * 0x30;
            tbl = D_005ED790 + i * 0x14;
            sp90 = fx + *(f32 *)(row + 0xCB4) + *(f32 *)(tbl + 0);
            sp94 = fy + *(f32 *)(row + 0xCB8) + *(f32 *)(tbl + 4);
            f0 = (f32)*(u8 *)(row + 0xCBE) * opacity;
            alpha = (u8)f0;
            tmp = (*(s32 *)(tbl + 0x10) * 4);
            pu = (u8 *)(tmp + (s32)buf + 0x88);
            b0 = pu[0];
            b1 = pu[1];
            b2 = pu[2];
            u0 = (u16)(1.0f + ((f32)*(u16 *)(row + 0xCC4) * *(f32 *)(tbl + 8)) / 100.0f);
            u1 = (u16)(((f32)*(u16 *)(row + 0xCCA) * *(f32 *)(tbl + 0xC)) / 100.0f);
            func_0034f320(handle, sp90, sp94, 0.0f, b0, b1, b2, alpha, u0, u1, 0, 0.0f, 0);
        }
    }
    if ((*(u32 *)(arg0 + 0x1C) & 1) != 0) {
        sp90 = 16.0f + (fx + *(f32 *)(arg0 + 0x594));
        sp94 = 368.0f + (fy + *(f32 *)(arg0 + 0x598));
        f0 = (f32)*(u8 *)(arg0 + 0x59E) * opacity;
        alpha = (u8)f0;
        func_0034f2e0(*(void **)(arg0 + 0x132C), sp90, sp94, 0xFF, 0xFF, 0xFF, alpha);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x200) != 0) {
        sp90 = 14.0f + (fx + *(f32 *)(arg0 + 0xBC4));
        sp94 = 405.0f + (fy + *(f32 *)(arg0 + 0xBC8));
        f0 = (f32)*(u8 *)(arg0 + 0xBCE) * opacity;
        alpha = (u8)f0;
        func_0034f2e0(*(void **)(arg0 + 0x12B0), sp90, sp94, 0xFF, 0xFF, 0xFF, alpha);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x400) != 0) {
        sp90 = 14.0f + (fx + *(f32 *)(arg0 + 0xBF4));
        sp94 = 405.0f + (fy + *(f32 *)(arg0 + 0xBF8));
        f0 = (f32)*(u8 *)(arg0 + 0xBFE) * opacity;
        alpha = (u8)f0;
        func_0034f2e0(*(void **)(arg0 + 0x12B4), sp90, sp94, 0xFF, 0xFF, 0xFF, alpha);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x800) != 0) {
        sp90 = 71.0f + (fx + *(f32 *)(arg0 + 0xC24));
        sp94 = 405.0f + (fy + *(f32 *)(arg0 + 0xC28));
        f0 = (f32)*(u8 *)(arg0 + 0xC2E) * opacity;
        alpha = (u8)f0;
        func_0034f2e0(*(void **)(arg0 + 0x12B8), sp90, sp94, 0xFF, 0xFF, 0xFF, alpha);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 2) != 0) {
        for (i = 0; i < *(s16 *)(arg0 + 0xFC); i++) {
            func_0013ad40(arg0, i, 0);
        }
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x20) != 0) {
        Vec2f pos;
        u8 c0;
        u8 c1;
        u8 c2;
        sp90 = 257.0f + (fx + *(f32 *)(arg0 + 0x8C4));
        sp94 = 21.0f + (fy + *(f32 *)(arg0 + 0x8C8));
        f0 = (f32)*(u8 *)(arg0 + 0x8CE) * opacity;
        alpha = (u8)f0;
        c0 = D_0064B2F4[0];
        c1 = D_0064B2F4[1];
        c2 = D_0064B2F4[2];
        pos.x = sp90;
        pos.y = sp94;
        func_0013b370(arg0, pos, (u32)c0 | ((u32)c1 << 8) | ((u32)c2 << 16) | ((u32)alpha << 24));
        sp90 = 255.0f + (fx + *(f32 *)(arg0 + 0x8C4));
        sp94 = 21.0f + (fy + *(f32 *)(arg0 + 0x8C8));
        func_00113730(&st30);
        st30 = 1;
        st2e = 4;
        st2c = 1;
        tmp = (s32)*(s16 *)(arg0 + 0x60) + (s32)*(s16 *)(arg0 + 0x5E);
        st28 = *(s32 *)(arg0 + tmp * 0xC + 0x100);
        st24 = *(s32 *)(arg0 + tmp * 0xC + 0x104);
        st20 = *(s32 *)(arg0 + tmp * 0xC + 0x108);
        pos.x = sp90;
        pos.y = sp94;
        func_00113790(pos, alpha, &st30, 1, 0.0f);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x2000) != 0) {
        f32 fy2;
        u8 a2;
        f32 fx2;
        fy2 = *(f32 *)(arg0 + 0x1228) + fy + *(f32 *)(arg0 + 0x898);
        f0 = (f32)*(u8 *)(arg0 + 0x89E) * opacity;
        a2 = (u8)f0;
        fx2 = *(f32 *)(arg0 + 0x1224) + fx + *(f32 *)(arg0 + 0x894) + 607.0f;
        sp90 = fx2;
        sp94 = fy2 + 32.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1270), sp90, sp94, 0xFF, 0xFF, 0xFF, a2);
        sp94 = fy2 + 197.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1274), sp90, sp94, 0xFF, 0xFF, 0xFF, a2);
        sp94 = fy2 + 35.0f;
        if (*(s16 *)(arg0 + 0x580) - 6 > 0) {
            sp94 += (f32)((*(s16 *)(arg0 + 0x60) * 0x42 + (s32)*(s16 *)(arg0 + 0x60)) * 2) / (f32)(*(s16 *)(arg0 + 0x580) - 6);
        }
        func_0034f2e0(*(void **)(arg0 + 0x1278), sp90, sp94, D_0064B2E8[0], D_0064B2E8[1], D_0064B2E8[2], a2);
    }
    if ((*(u32 *)(arg0 + 0x1C) & 8) != 0) {
        if (*(u8 *)(arg0 + 0x11FE) != 0) {
            f32 bx;
            f32 by;
            bx = fx + *(f32 *)(arg0 + 0x11F4);
            by = fy + *(f32 *)(arg0 + 0x11F8);
            func_0034f320(*(u8 **)(arg0 + 0x1244), bx, by, 0.0f, D_0064B2E4[0], D_0064B2E4[1], D_0064B2E4[2], *(u8 *)(arg0 + 0x11FE), 0x1000, 0x1000, 0, 0.0f, 0);
        }
        for (j = 0; j < 6; j++) {
            if ((s32)(j + *(s16 *)(arg0 + 0x60)) < (s32)*(s16 *)(arg0 + 0x580)) {
                if (*(s16 *)(arg0 + 0x5E) == (s16)j && ((*(u32 *)(arg0 + 0x1C) & 0x10) != 0)) {
                    if ((*(u32 *)(arg0 + 0x1C) & 0x80) == 0) {
                        Vec2f p2;
                        sp90 = 257.0f + (fx + *(f32 *)(arg0 + 0x744));
                        sp94 = 21.0f + (f32)*(s16 *)(arg0 + 0x5E) * 34.0f + fy + *(f32 *)(arg0 + 0x748);
                        f0 = (f32)*(u8 *)(arg0 + 0x74E) * opacity;
                        alpha = (u8)f0;
                        p2.x = sp90;
                        p2.y = sp94;
                        func_0013b370(arg0, p2, (u32)D_0064B2E8[0] | ((u32)D_0064B2E8[1] << 8) | ((u32)D_0064B2E8[2] << 16) | ((u32)alpha << 24));
                    }
                } else {
                    u8 *hand;
                    hand = *(u8 **)(arg0 + 0x1244);
                    sp90 = 255.0f + (fx + *(f32 *)(arg0 + j * 0x30 + 0x8F4));
                    sp94 = 21.0f + (f32)j * 34.0f + fy + *(f32 *)(arg0 + j * 0x30 + 0x8F8);
                    f0 = (f32)*(u8 *)(arg0 + j * 0x30 + 0x8FE) * opacity;
                    alpha = (u8)f0;
                    func_0034f320(hand, sp90, sp94, 0.0f, D_0064B2E4[0], D_0064B2E4[1], D_0064B2E4[2], alpha, 0x1000, *(u16 *)(arg0 + j * 0x30 + 0x90A), 0, 0.0f, 0);
                }
                tmp = func_0013ac30(*(u16 *)(arg0 + (*(s16 *)(arg0 + 0x60) + j) * 0xC + 0x102));
                if (tmp > 0) {
                    u8 *hand2;
                    hand2 = *(u8 **)(arg0 + tmp * 4 + 0x1244);
                    sp90 = 258.0f + (fx + *(f32 *)(arg0 + j * 0x30 + 0x8F4));
                    sp94 = 23.0f + (f32)j * 34.0f + fy + *(f32 *)(arg0 + j * 0x30 + 0x8F8);
                    f0 = (f32)*(u8 *)(arg0 + j * 0x30 + 0x8FE) * opacity;
                    alpha = (u8)f0;
                    func_0034f320(hand2, sp90, sp94, 0.0f, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], alpha, 0x1000, *(u16 *)(arg0 + j * 0x30 + 0x90A), 0, 0.0f, 0);
                }
                sp90 = 300.0f + (fx + *(f32 *)(arg0 + j * 0x30 + 0x774));
                sp94 = 21.0f + (f32)j * 34.0f + fy + *(f32 *)(arg0 + j * 0x30 + 0x778);
                f0 = (f32)*(u8 *)(arg0 + j * 0x30 + 0x77E) * opacity;
                alpha = (u8)f0;
                func_00113730(&st30);
                st30 = 1;
                if (*(s16 *)(arg0 + 0x5E) == (s16)j && ((*(u32 *)(arg0 + 0x1C) & 0x10) != 0)) {
                    st2e = 3;
                } else {
                    st2e = 2;
                }
                tmp = (s32)*(s16 *)(arg0 + 0x60) + j;
                st28 = *(s32 *)(arg0 + tmp * 0xC + 0x100);
                st24 = *(s32 *)(arg0 + tmp * 0xC + 0x104);
                st20 = *(s32 *)(arg0 + tmp * 0xC + 0x108);
                {
                    Vec2f p3;
                    p3.x = sp90;
                    p3.y = sp94;
                    func_00113790(p3, alpha, &st30, 1, 0.0f);
                }
            }
        }
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x40) != 0) {
        for (i = 0; i < *(s16 *)(arg0 + 0xFC); i++) {
            func_0013ad40(arg0, i, 3);
        }
    }
    if ((*(u32 *)(arg0 + 0x1C) & 0x80) != 0) {
        Vec2f p4;
        sp90 = 257.0f + (fx + *(f32 *)(arg0 + 0x744));
        sp94 = 21.0f + (f32)*(s16 *)(arg0 + 0x5E) * 34.0f + fy + *(f32 *)(arg0 + 0x748);
        f0 = (f32)*(u8 *)(arg0 + 0xB9E) * opacity;
        alpha = (u8)f0;
        func_00113730(&st30);
        st30 = 1;
        st2e = 3;
        st2c = 1;
        tmp = (s32)*(s16 *)(arg0 + 0x60) + (s32)*(s16 *)(arg0 + 0x5E);
        st28 = *(s32 *)(arg0 + tmp * 0xC + 0x100);
        st24 = *(s32 *)(arg0 + tmp * 0xC + 0x104);
        st20 = *(s32 *)(arg0 + tmp * 0xC + 0x108);
        p4.x = sp90;
        p4.y = sp94;
        func_0013b420(arg0, p4, alpha, &st30);
    }
    {
        Vec2f p5;
        sp90 = 640.0f + (fx + *(f32 *)(arg0 + 0xC54));
        sp94 = 400.0f + (fy + *(f32 *)(arg0 + 0xC58));
        f0 = (f32)*(u8 *)(arg0 + 0xC5E) * opacity;
        alpha = (u8)f0;
        p5.x = sp90;
        p5.y = sp94;
        func_0034f9d0(p5, 0.0f, alpha, *(s16 *)(arg0 + 0x582), *(s32 *)(arg0 + 0x1334));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138bf0);
#endif

// FUN_0013A040
s32 func_0013a040(s16 *arg0, s32 arg1, s16 arg2)
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
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(p + 0xCA8);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
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
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(row + 0xCA8);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
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

