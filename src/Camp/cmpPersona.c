#include "include_asm.h"
/* Persona 4 USA decompilation - cmpPersona.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct CmpHead CmpHead;
struct CmpHead {
    u8 _pad00[0x1C];
    s32 flags; // 0x1C
    s16 f20;   // 0x20
    s16 f22;   // 0x22
};

s32 func_0010abd0(s16 arg0);
s32 func_0034c210(void);
void func_001437b0(void* arg0, s32 arg1, s32 arg2);
void func_0034f5d0(void* arg0);
u32 func_003b7060(void);
void func_0046d280(void *node);
void func_00452080(s32 arg0);
void func_002bb4e0(void);
void func_003550d0(s32 arg0, void* arg1, void* arg2);
void func_00355070(s32 arg0, void* arg1, void* arg2);
void func_00355300(s32 arg0, s32 arg1);
void func_0046d730(void* arg0, s32 arg1);
void func_00136fc0(u8* arg0);
void func_00135dc0(u8* arg0);
extern s32 D_005EB580[];
extern u8 D_005EB560[];
extern u8 D_005EB570[];
extern u8 D_005EB578[];
extern s16 D_005EB590[];
extern void func_0011cee0(u8* arg0);
extern u8 D_005E9FD0[];
extern u8 D_005EA2E0[];
extern u8 D_005EA5F0[];
extern u8 D_005EA900[];
extern u8 D_005EAC10[];
extern u8 D_005EAF20[];
extern u8 D_005EB230[];
typedef struct CmpPair CmpPair;
struct CmpPair {
    f32 x;
    f32 y;
};
void func_003552d0(s32 arg0, CmpPair arg1);

/* measured: plain-cast reconstruction candidate (corrected callee declarations
   and s16 loop counter) emitted the retail overflow-safe float-to-u16
   conversion idiom, but object size was 1288 versus the 1344-byte window and
   normalized_diff was 860. The remaining mismatch is reconstruction-scale;
   the prior explicit-guard floor classification is rejected. Retail uses
   func_00353c10 with only the s16* argument in $a0, while the resource
   handles are s32 values. */
/* measured: candidate object 322 instrs/retail 332 instrs (1288B/1344B, 10 short), probe reloc-masked 286 words (guard below, NON_MATCHING so production stays ASM; fnalign 197 edits +16 reloc-only). Reconstruction-scale residual with corrected callee decls and s16 counters; plain (u16)float casts use native overflow-safe idiom. Banked as floor. */
// FUN_001356D0 NONMATCHING
#ifdef NON_MATCHING
void func_001356d0(u8* arg0) {
 extern void func_00135c10(u8* arg0);
 extern s64 func_00353c10(s16* arg0);
 extern void func_0043f9c8(void* dst, s32 value, s32 size);
 extern s32 func_0046a770(u32 arg0);
 extern s32 func_0046d200(s32 arg0, s32 arg1);
 extern void func_002baac0(void* arg0);
 extern u8* func_00354a50(s32 arg0, s32 arg1);
 extern u8* func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
 extern void func_00117580(u8* arg0, s16 arg1);
 extern s32 func_001371a0(u8* arg0, u32 arg1);
 extern u8 D_005E57F0[];
 extern u8 D_005E5830[];
 extern u8 D_005E5850[];
 extern u8 D_005E9FB0[];
 extern u8 D_005EA2E0[];
 extern u8 D_0064A790[];
 s16 i;
 s32 resource0;
 s32 resource1;
 s32 resource2;
 s32* slot;
 u8* p;
 u8* src;

 func_0043f9c8(arg0, 0, 0x1CC4);
 *(s32*)(arg0 + 4) = 0;
 *(s32*)(arg0 + 8) = 0;
 *(u8*)arg0 = 0xFF;
 *(s32*)(arg0 + 0x18) = -1;
 *(s16*)(arg0 + 0x20) = 0;
 *(s32*)(arg0 + 0x14) = 0;
 for (i = 0; i < 4; i++) {
  p = arg0 + i * 2;
  *(s16*)(p + 0x50) = 0;
  *(s16*)(p + 0x58) = 0;
 }
 for (i = 0; i < 28; i++) {
  src = D_005EA2E0 + i * 0x1C;
  p = arg0 + i * 0x30;
  *(f32*)(p + 0x1064) = *(f32*)(src + 0);
  *(f32*)(p + 0x1068) = *(f32*)(src + 4);
  *(u16*)(p + 0x1074) = (u16)*(f32*)(src + 8);
  *(u16*)(p + 0x107A) = (u16)*(f32*)(src + 0xC);
  *(u8*)(p + 0x106E) = *(u8*)(src + 0x10);
 }
 for (i = 0; i < 120; i++) {
  p = arg0 + i * 0x14;
  *(s32*)(p + 0x68) = i % 10;
  *(s32*)(p + 0x70) = 10;
  *(s32*)(p + 0x6C) = i / 10;
  *(s32*)(p + 0x74) = 12;
 }
 for (i = 0; i < 84; i++) {
  p = arg0 + i * 0x14;
  *(s32*)(p + 0x9C8) = i % 7;
  *(s32*)(p + 0x9D0) = 7;
  *(s32*)(p + 0x9CC) = i / 7;
  *(s32*)(p + 0x9D4) = 12;
 }
 for (i = 0; i < 36; i++) {
  p = arg0 + i * 0x30;
  *(s32*)(p + 0x15A4) = 0;
  *(s32*)(p + 0x1594) = 0;
  *(s32*)(p + 0x15A0) = (s32)0xC2C80000;
  *(s32*)(p + 0x1598) = (s32)0xC2C80000;
  *(s8*)(p + 0x15AD) = 0x7F;
  *(s8*)(p + 0x15AC) = 0x7F;
  *(s32*)(p + 0x15BC) = 0;
  *(s32*)(p + 0x15C0) = 10;
 }
 *(s16*)(arg0 + 0x34) = func_00353c10((s16*)(arg0 + 0x24));
 resource0 = func_0046a770((u32)D_005E5830);
 if (resource0 == 0) {
  func_0046d730(&D_005EB580[0], 0x199);
 }
 resource1 = func_0046a770((u32)D_005E5850);
 if (resource1 == 0) {
  func_0046d730(&D_005EB580[0], 0x19B);
 }
 resource2 = func_0046a770((u32)D_005E57F0);
 *(s32*)(arg0 + 0x1CB0) = resource2;
 if (resource2 == 0) {
  func_0046d730(&D_005EB580[0], 0x19D);
 }
 for (i = 0; i < 23; i++) {
  slot = (s32*)(arg0 + i * 4 + 0x1C54);
  if (i < 6) {
   *slot = func_0046d200(resource0, *(u8*)(D_005E9FB0 + i));
  } else if (i < 9) {
   *slot = func_0046d200(resource2, *(u8*)(D_005E9FB0 + i));
  } else {
   *slot = func_0046d200(resource1, *(u8*)(D_005E9FB0 + i));
  }
  if (*slot == 0) {
   func_0046d730(&D_005EB580[0], 0x1AB);
  }
 }
 func_002baac0(D_0064A790);
 func_00135c10(arg0);
 *(s32*)(arg0 + 0x1CB8) = (s32)func_00354a50(0, 1);
 *(s32*)(arg0 + 0x1CB4) = (s32)func_00117780(0, 0xC7, 0, 8, 3);
 func_00117580(*(u8**)(arg0 + 0x1CB4), 0xB0);
 func_001371a0(arg0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_001356d0);
#endif

// FUN_00135C10
void func_00135c10(u8* arg0) {
    s16 j = 0;
    s16 i = 0;
    while (j < 0xC) {
        if (func_0010abd0(j) == 0) {
            break;
        }
        *(s16*)((u8*)arg0 + i * 2 + 0x36) = j;
        i++;
        j++;
    }
    *(s16*)((u8*)arg0 + 0x4E) = i;
}

// FUN_00135CB0
s32 func_00135cb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    default:
        return 1;
    }
}

// FUN_00135CF0
/* measured: without opt_common_subs off, mwcc CSEs (u8*)arg0 + 0x20 into a
   callee-saved pointer (nd 40); with it off each access keeps the
   base+offset form like retail (nd 0). */
#pragma opt_common_subs off
s32 func_00135cf0(u8* arg0) {
    s32 i;
    s32 result = 1;
    u8* p;
    s32 v = *(s16*)((u8*)arg0 + 0x20);
    if (v < 0x64) {
        *(s16*)((u8*)arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 0x1C; i++) {
        p = (u8*)arg0 + i * 0x30;
        v = *(s16*)((u8*)arg0 + 0x20);
        func_001437b0(p + 0x1054, v, 0);
        if (*(u8*)(p + 0x106E) != 0) {
            result = 0;
        }
    }
    func_00136fc0(arg0);
    func_00135dc0(arg0);
    return result;
}
#pragma opt_common_subs on

/* measured: cold reconstruction from m2c+romwright (QCMP stub is 8-line outline, nothing to recover).
   Candidate object 1115 instrs/retail 1143 instrs (4460B/4572B, 28 short, 2.4% within 3%),
   probe reloc-masked 1000 words, fnalign 248 edits +10 reloc-only. Guarded NONMATCHING so production stays ASM.
   Plain (u8)/(u16) casts use native overflow-safe idiom per 7a-quinquies; single-product accumulator
   at 0x00136610 (adda.s/madd.s) from `20.0f + base + 33.0f*(f32)i` per 7r, reachable from plain C.
   f32 fw0/fh0 passed to u16 params re-emit both 0034f320 conversions (was 38-instr gap, 351->247 edits).
   Flags reloaded per section (never hoist what retail reloads), entry+0x64/+0x9C4 materialized.
   Banked as floor.
   7o eight probes (2026-09-18, probe_variants, reloc-masked words; baseline 1000):
   step 1: residual_signature perm [$a1->$v1] (19 perms over 248 edits +10 reloc-only, reconstruction-scale, not exchange-class);
   body carries no `Type name = ...;` initialised declarations (already 7o form: bare decls + statement assigns, so strip step is vacuous).
   pal/mode (u8* pal vs s32 mode; retail pal->mode per lui $19 before addiu $18 at 0x00136748):
   p1 pal func retail 1000 (baseline tie); p2 pal func reverse (mode->pal) 1000 (tie, no 8->76 regression);
   p3 pal block retail 1000 (tie); p4 pal block reverse 1000 (tie).
   fw0/fh0 (f32 vs f32; retail fw0->fh0 per lhu 0x1314 before 0x131A at 0x001366B8):
   p5 fw func retail 1000 (baseline tie); p6 fw func reverse 1000 (tie);
   p7 fw block retail 1000 (tie); p8 fw block reverse 1000 (tie).
   All eight tie at 1000; lever has nothing to change on this floor (cf. 7o: most parked floors already in 7o form).
   Reversal does not regress here (unlike 7o's 8->76 etc) because the 248-edit reconstruction residual dominates. */
// FUN_00135DC0 NONMATCHING
#ifdef NON_MATCHING
void func_00135dc0(u8* arg0)
{
    typedef struct { f32 x, y; } Vec2f;
    extern void func_0034f1e0(void);
    extern void func_0034c270(Vec2f arg0, s32 arg1, s32 arg2, f32 fparg0);
    extern void func_0034f2e0(void* arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    extern void func_0034f320(u8* arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern f32 func_0034f720(u8* arg0, f32 fparg0, f32 fparg1, f32 fparg2);
    extern void func_0034f9d0(Vec2f arg0, f32 fparg0, u32 arg1, s32 arg2, s32 arg3);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_00355410(void* arg0, s32 arg1);
    extern void func_00354ba0(void* arg0);
    extern void func_00137890(u8* arg0, s32 arg1);
    extern s32 func_0010b5b0(void);
    extern s32 func_0010d6d0(s16 arg0);
    extern int func_00274ed0(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char* str, int flags, int extra);
    extern s32 func_0011d1e0(void* arg0);
    extern void func_0011dc50(void* arg0);
    extern void func_0011dd50(void* arg0);
    extern void func_0011de40(void* arg0, s32 arg1);
    extern void func_0011e400(void* arg0, void* arg1);
    extern s32 func_0011e460(void* arg0);
    extern f32 func_0044b610(f32 arg0);
    extern void func_00364680(f32 depth, s32 color, f32 x, f32 y, f32 sx, f32 sy, f32 w, f32 h, s32 tex, s32 mode, s32 flag);
    extern void func_0046d730(void* arg0, s32 arg1);
    extern u8 D_005EB540[];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern s32 D_005EB580[];
    extern f32 fGpffff8170;
    extern f32 fGpffff854c;
    extern f32 fGpffff84a4;
    f32 baseX;
    f32 baseY;
    f32 alphaBase;
    Vec2f pos;
    f32 fA0;
    f32 fA4;
    s32 i;
    u8* entry;
    u8* e2;
    f32 fx;
    f32 fy;
    f32 fa;
    u8 alpha;
    u8 c0;
    u8 c1;
    u8 c2;
    f32 fw0;
    f32 fh0;
    u8* pal;
    s32 mode;
    u8* base;
    void* spr;
    f32 t0;
    f32 t1;

    func_0034f1e0();
    baseX = *(f32*)(arg0 + 4);
    baseY = *(f32*)(arg0 + 8);
    alphaBase = (f32)*(u8*)arg0 / 255.0f;
    if (*(s32*)(arg0 + 0x10) != 0) {
        pos.x = baseX;
        pos.y = baseY;
        fa = 255.0f * alphaBase;
        alpha = (u8)fa;
        func_0034c270(pos, alpha, *(s32*)(arg0 + 0x10), 0.0f);
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x40) != 0) {
        fA0 = 227.0f + (baseX + *(f32*)(arg0 + 0x1484));
        fA4 = 9.0f + (baseY + *(f32*)(arg0 + 0x1488));
        fa = (f32)*(u8*)(arg0 + 0x148E) * alphaBase;
        alpha = (u8)fa;
        spr = *(void**)(arg0 + 0x1C70);
        for (i = 0; i < 0x78; i++) {
            entry = arg0 + i * 0x14;
            base = entry + 0x64;
            if (*(s16*)(base + 0) >= 0) {
                fx = fA0 + (f32)(*(s32*)(entry + 0x68) * 44);
                fy = fA4 + (f32)(*(s32*)(entry + 0x6C) * 37);
                t0 = func_0034f720(base, fGpffff8170, 0.75f, 1.0f);
                e2 = D_005EB540 + *(s16*)(base + 0) * 4;
                c0 = *(u8*)(e2 + 0x10);
                c1 = *(u8*)(e2 + 0x11);
                c2 = *(u8*)(e2 + 0x12);
                fa = (f32)alpha * t0;
                func_0034f2e0(spr, fx, fy, c0, c1, c2, (u8)fa);
            }
        }
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x80) != 0) {
        fA0 = 227.0f + (baseX + *(f32*)(arg0 + 0x14B4));
        fA4 = 9.0f + (baseY + *(f32*)(arg0 + 0x14B8));
        spr = *(void**)(arg0 + 0x1C74);
        func_003f6440(3, 0x71801);
        func_003f6440(2, 0x48);
        fa = 190.0f * alphaBase;
        alpha = (u8)fa;
        for (i = 0; i < 0x24; i++) {
            entry = arg0 + i * 0x30;
            func_0034f2e0(spr, fA0 + *(f32*)(entry + 0x15A4), fA4 + *(f32*)(entry + 0x15A8), 0, 0xFF, 0x64, alpha);
        }
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
        fa = (f32)*(u8*)(arg0 + 0x14BE) * alphaBase;
        alpha = (u8)fa;
        t1 = 255.0f * alphaBase;
        for (i = 0; i < 0x54; i++) {
            entry = arg0 + i * 0x14;
            base = entry + 0x9C4;
            if (*(s16*)(base + 0) >= 0) {
                fx = fA0 + (f32)(*(s32*)(entry + 0x9C8) * 44);
                fy = fA4 + (f32)(*(s32*)(entry + 0x9CC) * 37);
                if (*(s16*)(base + 0) == 3) {
                    fa = t1;
                    alpha = (u8)fa;
                } else {
                    t0 = func_0034f720(base, fGpffff854c, fGpffff854c, fGpffff8170);
                    fa = (f32)alpha * t0;
                    alpha = (u8)fa;
                }
                e2 = D_005EB540 + *(s16*)(base + 0) * 4;
                c0 = *(u8*)(e2 + 0);
                c1 = *(u8*)(e2 + 1);
                c2 = *(u8*)(e2 + 2);
                func_0034f2e0(spr, fx, fy, c0, c1, c2, alpha);
            }
        }
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x800) != 0) {
        fa = 255.0f * alphaBase;
        alpha = (u8)fa;
        func_00355410(*(void**)(arg0 + 0x1CB8), alpha);
        func_00354ba0(*(void**)(arg0 + 0x1CB8));
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x2) != 0) {
        for (i = 0; i < *(s16*)(arg0 + 0x34); i++) {
            entry = arg0 + i * 0x30;
            fA0 = 82.0f + (baseX + *(f32*)(entry + 0x1304));
            fA4 = 20.0f + (baseY + *(f32*)(entry + 0x1308)) + (f32)i * 33.0f;
            fa = (f32)*(u8*)(entry + 0x130E) * alphaBase;
            alpha = (u8)fa;
            fw0 = (f32)*(u16*)(entry + 0x1314);
            fh0 = (f32)*(u16*)(entry + 0x131A);
            if (*(s16*)(arg0 + 0x50) == i) {
                pal = D_0064B2E8;
                mode = 8;
            } else {
                pal = D_0064B2E0;
                mode = 6;
            }
            func_0034f320(*(u8**)(arg0 + 0x1C54), fA0, fA4, 0.0f, pal[0], pal[1], pal[2], alpha, fw0, fh0, 0, 0.0f, 0);
            func_0034f320(*(u8**)(arg0 + 0x1C58), 202.0f + fA0, fA4, 0.0f, pal[0], pal[1], pal[2], alpha, fw0, fh0, 0, 0.0f, 0);
            func_00274ed0(105.0f + fA0, fA4, 0.0f, (alpha | ~0xFF), mode, 1, (const char*)func_0010d6d0(*(s16*)(arg0 + i * 2 + 0x24)), 8, 0);
        }
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x100) != 0) {
        if (*(s32*)(arg0 + 0x1CB4) == 0) {
            func_0046d730(D_005EB580, 0x2AD);
        }
        {
            void* h = (void*)func_0011d1e0(*(void**)(arg0 + 0x1CB4));
            func_0011de40(h, 0xFF);
            func_0011dd50(h);
            func_0011dc50(h);
            if ((*(s32*)(arg0 + 0x1C) & 0x1000) != 0) {
                s32 t = func_0011e460(h);
                if (t != 0) {
                    s16 fr = *(s16*)(arg0 + 0x22);
                    s32 pulse;
                    func_0011e400(h, &pos);
                    fA0 = pos.x;
                    fA4 = pos.y;
                    if (fr < 5) {
                        pulse = 0xCC;
                    } else if (fr < 0x19) {
                        fa = 204.0f * func_0044b610((fGpffff84a4 * (f32)(fr - 5)) / 20.0f);
                        pulse = (u8)fa;
                    } else {
                        pulse = 0;
                    }
                    func_00364680(0.0f, (pulse & 0xFF) | 0xDCDCDC00, fA0, fA4, fA0, fA4, 512.0f, 512.0f, t, 0, 1);
                    func_003f6440(3, 0x717FB);
                    func_003f6440(2, 0x44);
                }
            }
        }
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x1) != 0) {
        fA0 = 20.0f + (baseX + *(f32*)(arg0 + 0x1574));
        fA4 = 402.0f + (baseY + *(f32*)(arg0 + 0x1578));
        fa = (f32)*(u8*)(arg0 + 0x157E) * alphaBase;
        func_0034f2e0(*(void**)(arg0 + 0x1C6C), fA0, fA4, 0xFF, 0xFF, 0xFF, (u8)fa);
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x200) != 0) {
        fA0 = 20.0f + (baseX + *(f32*)(arg0 + 0x1514));
        fA4 = 379.0f + (baseY + *(f32*)(arg0 + 0x1518));
        fa = (f32)*(u8*)(arg0 + 0x151E) * alphaBase;
        func_0034f2e0(*(void**)(arg0 + 0x1CA4), fA0, fA4, 0xFF, 0xFF, 0xFF, (u8)fa);
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x400) != 0) {
        fA0 = 20.0f + (baseX + *(f32*)(arg0 + 0x1544));
        fA4 = 379.0f + (baseY + *(f32*)(arg0 + 0x1548));
        fa = (f32)*(u8*)(arg0 + 0x154E) * alphaBase;
        func_0034f2e0(*(void**)(arg0 + 0x1C78), fA0, fA4, 0xFF, 0xFF, 0xFF, (u8)fa);
    }
    if ((*(s32*)(arg0 + 0x1C) & 0x4) != 0) {
        if (*(s16*)(arg0 + 0x4E) == 0) {
            func_0046d730(D_005EB580, 0x2FB);
        } else {
            for (i = 0; i < (func_0010b5b0() & 0xFFFF); i++) {
                func_00137890(arg0, i);
            }
        }
    }
    fA0 = 640.0f + (baseX + *(f32*)(arg0 + 0x14E4));
    fA4 = 400.0f + (baseY + *(f32*)(arg0 + 0x14E8));
    fa = (f32)*(u8*)(arg0 + 0x14EE) * alphaBase;
    pos.x = fA0;
    pos.y = fA4;
    func_0034f9d0(pos, 0.0f, (u8)fa, *(s16*)(arg0 + 0x60), *(s32*)(arg0 + 0x1CB0));
}
#else
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_00135dc0);
#endif

// FUN_00136FA0
s32 func_00136fa0(s16* arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 * 2;
    s16* p = (s16*)(idx + (s32)arg0);
    p[0x2C] = p[0x28];
    p[0x28] = arg2;
    return 1;
}

// FUN_00136FC0
void func_00136fc0(u8* arg0) {
    s16 temp_3;
    s32 i;

    temp_3 = *(s16*)(arg0 + 0x22);
    if (temp_3 < 0x64) {
        *(s16*)(arg0 + 0x22) = temp_3 + 1;
    }
    if (*(s16*)(arg0 + 0x22) == 0x19) {
        *(s32*)(arg0 + 0x1C) &= ~0x1000;
    }
    for (i = 0; i < 0x24; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1594, *(s16*)(arg0 + 0x22), 0);
    }
    for (i = 0; i < 0x78; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x64);
    }
    for (i = 0; i < 0x54; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x9C4);
    }
}

/* measured: opt_propagation off preserves the retail stack-local value-pointer
   address sequence (MATCH); leaving propagation on folds the +0x40 into lh. */
#pragma opt_propagation off
// FUN_001370E0
void func_001370e0(u8* arg0) {
    s16 values[0x19];
    s16* src;
    s16* dst;
    s16* value;
    s16 idx;
    s32 count;
    s32 i;
    s32 offset;
    u8* p;

    src = &D_005EB590[0];
    dst = &values[0];
    count = 0x19;
    do {
        idx = *src;
        src++;
        count--;
        *dst = idx;
        dst++;
    } while (count > 0);
    for (i = 0; i < 0x19; i++) {
        offset = i * 2;
        value = (s16*)((u8*)&values[0] + offset);
        idx = *value;
        p = arg0 + idx * 0x14;
        *(s16*)(p + 0x9C4) = 3;
        *(s16*)(p + 0x9C6) = (s16)(func_003b7060() % 0x19 + 0xF);
    }
}
#pragma opt_propagation on


/* measured: opt_common_subs off around the setup/switch and
   opt_loop_invariants on around the table loop reproduce the retail
   register/constant placement (MATCH). Plain `(u16)float` casts use MWCC's
   native overflow-safe conversion sequence (c.le.s 0x4F000000; trunc.w.s;
   mfc1; andi 0xFFFF with the out-of-line subtract/or path). func_0011cee0
   receives the pointer loaded from 0x1CB4. The switch jump table has case 9
   targeting the default block, so no empty case is needed. */
#pragma opt_common_subs off
// FUN_001371A0
s32 func_001371a0(u8* arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8* table;
    u8* src;
    u8* dst;
    f32 value;
    table = 0;
    if (*(s32*)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x1C; i++) {
        dst = arg0 + i * 0x30;
        *(f32*)(dst + 0x1054) = *(f32*)(dst + 0x1064);
        *(f32*)(dst + 0x1058) = *(f32*)(dst + 0x1068);
        *(u16*)(dst + 0x1070) = *(u16*)(dst + 0x1074);
        *(u16*)(dst + 0x1076) = *(u16*)(dst + 0x107A);
        *(u8*)(dst + 0x106C) = *(u8*)(dst + 0x106E);
    }
    switch (arg1) {
    case 0:
        table = D_005E9FD0;
        *(s32*)(arg0 + 0x1C) = 0x243;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 1:
        table = D_005EA2E0;
        break;
    case 2:
        table = D_005EA5F0;
        *(s32*)(arg0 + 0x1C) = 0xA43;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 3:
        table = D_005EA900;
        *(s32*)(arg0 + 0x1C) = 0xFE7;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 4:
    case 5:
        table = D_005EAC10;
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 6:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 0x48D;
        *(s16*)(arg0 + 0x60) = -1;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 7:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 9;
        break;
    case 8:
        table = D_005EB230;
        *(s32*)(arg0 + 0x1C) = 0xA13;
        *(s16*)(arg0 + 0x60) = 0xE;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 10:
        *(s32*)(arg0 + 0x1C) = 8;
        *(s16*)(arg0 + 0x60) = -1;
        break;
    case 11:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 12:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    default:
        func_0046d730(D_005EB580, 0x3BA);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table/dst stride multiplies
   out of the j loop to match retail; without it the function mismatches. */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 0x1C; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32*)(dst + 0x105C) = *(f32*)(src + 0);
            *(f32*)(dst + 0x1060) = *(f32*)(src + 4);
            value = *(f32*)(src + 8);
            *(u16*)(dst + 0x1072) = (u16)value;
            value = *(f32*)(src + 0xC);
            *(u16*)(dst + 0x1078) = (u16)value;
            *(u8*)(dst + 0x106D) = *(u8*)(src + 0x10);
            *(s32*)(dst + 0x107C) = *(s32*)(src + 0x14);
            *(s32*)(dst + 0x1080) = *(s32*)(src + 0x18);
        }
    *(s16*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x18) = arg1;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants on scope opened above for
   func_001371a0's table loop. */
#pragma opt_loop_invariants off

// FUN_001374D0
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_001374d0(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 8; i++) {
        cur = *(s16*)((u8*)arg0 + 0x50);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0x44480000;
            *(s32*)(p + 0x1300) = 0;
            *(u8*)(p + 0x130D) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0;
            *(f32*)(p + 0x1300) = f;
            *(u8*)(p + 0x130D) = 0;
        }
    }
}
/* measured: see annotation above (func_001374d0). */
#pragma opt_loop_invariants off

// FUN_00137570
/* measured: without opt_loop_invariants on, mwcc rematerializes the 0x41F00000
   constant inside the loop body (nd 22); with it the lui hoists to the
   preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137570(u8* arg0) {
    s32 i;
    u8* p;
    s32 c = 0x41F00000;
    for (i = 0; i < 0xC; i++) {
        p = (u8*)arg0 + i * 0x30;
        *(f32*)(p + 0x10B4) = *(f32*)(p + 0x10C4);
        *(f32*)(p + 0x10B8) = *(f32*)(p + 0x10C8);
        *(u8*)(p + 0x10CC) = *(u8*)(p + 0x10CE);
        if (*(s16*)((u8*)arg0 + 0x52) == i) {
            *(s32*)(p + 0x10BC) = c;
        } else {
            *(s32*)(p + 0x10BC) = 0;
        }
    }
    *(s16*)((u8*)arg0 + 0x20) = 0;
    *(s32*)((u8*)arg0 + 0x1C) &= ~0x1000;
}
/* measured: see annotation above (func_00137570). */
#pragma opt_loop_invariants off


// FUN_001375F0
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
void func_001375f0(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0x24; i++) {
        if (func_003b7060() & 3) {
            p = arg0 + i * 0x30;
            val = (func_003b7060() % 7U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x159C) = f;
            *(f32 *)(p + 0x1594) = f;
            *(u32 *)(p + 0x1598) = 0x43FA0000;
            *(f32 *)(p + 0x15A8) = *(f32 *)(p + 0x1598);
            *(s32 *)(p + 0x15A0) = 0xC2C80000;
            q = (u32 *)(p + 0x15BC);
            random = func_003b7060() % 10U;
            *q = random;
            *(s32 *)(p + 0x15C0) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x1598) = *(f32 *)(p + 0x15A0);
        }
    }
    *(s16 *)(arg0 + 0x22) = 0;
    *(s32 *)(arg0 + 0x1C) |= 0x1000;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2

// FUN_00137740
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137740(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 0xC; i++) {
        cur = *(s16*)((u8*)arg0 + 0x52);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0x44480000;
            *(s32*)(p + 0x10C0) = 0;
            *(u8*)(p + 0x10CD) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0;
            *(f32*)(p + 0x10C0) = f;
            *(u8*)(p + 0x10CD) = 0;
        }
    }
}
/* measured: see annotation above (func_00137740). */
#pragma opt_loop_invariants off

// FUN_001377E0
void func_001377e0(u8* arg0) {
    u8* base = arg0;
    s32 i;
    s32* p;
    for (i = 0; i < 0x17; i++) {
        p = (s32*)(base + i * 4 + 0x1C54);
        if (*p != 0) {
            func_0046d280((void *)*p);
            *p = 0;
        }
    }
    if (*(s32*)(base + 0x1CB4) != 0) {
        func_00452080(*(s32*)(base + 0x1CB4));
        *(s32*)(base + 0x1CB4) = 0;
    }
    if (*(s32*)(base + 0x1CB8) != 0) {
        func_00452080(*(s32*)(base + 0x1CB8));
        *(s32*)(base + 0x1CB8) = 0;
    }
    func_002bb4e0();
    *(s32*)(base + 0x1C) = 0;
}

/* measured: the plain `(u8)` cast uses MWCC's native guarded conversion
   idiom; it is not a float-to-unsigned compiler floor. This function still
   has the genuine COP1 accumulator-chain floor: retail contains
   `adda.s $f0,$f1` / `madd.s $f20,$f3,$f2` for the alpha calculation, plus the
   doubled-bltz u16 sign-test pattern. */
/* measured: candidate object 296 instrs/retail 334 instrs (1184B/1344B, 38 short), probe reloc-masked 252 words (guard below, NON_MATCHING so production stays ASM; fnalign 384 edits +2 reloc-only). Frame 0x160 vs small object frame from fewer live locals across 0034f2e0 calls (8 saves + f20-22 in retail); COP1 adda.s/madd.s alpha chain at 37958/3795C from plain C multiply. Banked as floor. */
/* gate: object 296 against retail 334, -11.4% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
/* 2026-09-19 lead audit: this floor's 252-word score is meaningless and the
   -11.4% count understates how wrong the body is.  fnalign shows a single
   `delete retail[140:317]` of **177 instructions** that this body does not
   have at all, offset by a 96-instruction `replace` and a 45-instruction
   `insert` of code retail does not have.  A 177-instruction hole cancelling
   against ~141 instructions of invented work is the compensating-surplus
   pattern from handoff 7u: the count looks nearly right and the structure is
   badly wrong.
   Whoever takes this next: recover the retail block at 140-317 first - it
   begins `jal` / `b .+177` / `addiu $a0, $sp, 0xd0` / `jal`, so it is a
   call-heavy arm built around a 0xD0 stack object - and delete the invented
   96- and 45-instruction regions rather than tuning anything.  Do not trust
   any pragma or colouring number measured against the present body. */
/* gate: object 296 against retail 334, -11.4% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
/* measured 2026-09-19 (lead, by hand against the retail listing): object 323
   instrs against retail 334, one instruction outside the 324-344 band, with
   **fnalign 384 edits -> 106**.  The body was 296/334 at 384 edits and a
   177-instruction pure delete when this pass started; that delete is gone.
   Four defects, each read out of the disassembly rather than guessed:
   1. **Both `if` arms were inverted.**  Retail tests `slt $s4, 0x4e($s5)` and
      *branches* to the long arm, so the short two-call arm is the
      fall-through: the source is `if (arg1 >= count) { two calls } else
      { ... }`.  The inner test is the same shape - `bne $s4, 0x52($s5)`
      branches to the constants arm, so the table arm is the fall-through and
      the source reads `if (arg1 == sel) { table } else { constants }`.
      Those two inversions alone took 384 edits to 150 and dissolved the
      177-instruction hole into runs of 15 or fewer.
   2. **The coordinate pair is a `f32 pos[2]` in the frame, not two scalars.**
      Retail stores `swc1 $f12, 0x158($sp)` / `swc1 $f13, 0x15c($sp)` before
      every draw call and reloads both inside the digit loop
      (`lwc1 $f12, 0x158($sp)`), and the final call takes them as one
      `ld $a0, 0x158($sp)`.  Writing through `pos[0]`/`pos[1]` and passing
      `pos[0], pos[1]` recovered ten instructions.
   3. **The last call passes the pair as a 64-bit value**, with `0.0f` in
      `$f12`: `func_00115c40(*(s64 *)pos, 0.0f, alpha, stack90)` against the
      old `(0, 0, alpha, stack90)`.
   4. **The alpha conversion must be the plain unsigned cast.**  Retail emits
      the `cvt.w.s`/`mfc1`/`lui 0x8000`/`or`/`andi` recipe; the hand-written
      `if (fa >= 2.1474836e9f) fa -= ...` guard compiled to one instruction.
      Writing `alpha = (u32)fa & 0xFF` restores the ten-instruction recipe.
   Measured and rejected: `opt_propagation off` 173 edits; `s64` colour
   locals 118; naming `D_0064B2ED`/`D_0064B2EE` separately instead of
   `D_0064B2E8[1]`/`[2]` no change (b210 folds adjacent symbols); writing
   `*(s16 *)(stack90 + 2) = sel` in both arms 112.
   What remains, all small: retail[150:166] 16 against 13 in the table arm,
   retail[169:180] 11 against 9 in the constants arm (retail materialises
   those six constants with `daddiu`, so they may be 64-bit in the original),
   and four 4-to-6 instruction replaces in the draw sequence. */
// FUN_00137890 NONMATCHING
#ifdef NON_MATCHING
void func_00137890(u8 *arg0, s32 arg1)
{
    extern s32 func_0010b5b0(void);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern s32 func_0010ace0(s16 arg0);
    extern void func_00115830(void *arg0);
    extern void func_00115940(void *arg0, void *arg1, s32 arg2);
    extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1, u8 arg1, u8 arg2, u8 arg3, u32 arg4);
    extern s32 func_00105330(s32 arg0);
    extern void func_00115c40(s64 arg0, f32 fparg0, u32 arg1, void *arg2);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E9[];
    extern u8 D_0064B2EA[];
    extern u8 D_0064B2EC[];
    s32 idx;
    f32 fx;
    f32 fy;
    f32 fa;
    u32 alpha;
    s16 count;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    u8 cc0;
    u8 cc1;
    u8 sel;
    f32 pos[2];
    u8 stack90[8];
    u8 stackd0[16];
    u32 div;
    u32 ualpha;
    u32 ubase;
    u32 k;

    if (arg1 < 0 || arg1 >= (func_0010b5b0() & 0xFFFF)) {
        func_0046d730(D_005EB580, 0x478);
    }
    idx = arg1;
    fx = (*(f32 *)(arg0 + 4) + *(f32 *)(arg0 + idx * 0x30 + 0x10C4)) - 10.0f;
    fy = (f32)idx * 30.0f + *(f32 *)(arg0 + 8) + *(f32 *)(arg0 + idx * 0x30 + 0x10C8);
    ualpha = *(u8 *)(arg0 + idx * 0x30 + 0x10CE);
    ubase = *arg0;
    fa = (f32)ualpha * ((f32)ubase / 255.0f);
    alpha = (u32)fa & 0xFF;
    if (arg1 >= *(s16 *)(arg0 + 0x4E)) {
        pos[0] = fx - 40.0f;
        pos[1] = fy + 21.0f;
        func_0034f2e0(*(u8 **)(arg0 + 0x1C64), pos[0], pos[1], 0xFF, 0xE9, 0x2C, alpha);
        pos[0] = fx + 89.0f;
        pos[1] = fy + 21.0f;
        func_0034f2e0(*(u8 **)(arg0 + 0x1C68), pos[0], pos[1], 0xFF, 0xE9, 0x2C, alpha);
    } else {
        func_00115830(stack90);
        if (arg1 == *(s16 *)(arg0 + 0x52)) {
            c0 = D_0064B2E8[0];
            c1 = D_0064B2E9[0];
            c2 = D_0064B2EA[0];
            c3 = D_0064B2EC[0];
            cc0 = D_0064B2E8[1];
            cc1 = D_0064B2E8[2];
            sel = 1;
            *(s16 *)(stack90 + 2) = 0;
        } else {
            c0 = 0xFF;
            c1 = 0xE9;
            c2 = 0x2C;
            c3 = 0xF7;
            cc0 = 0xAF;
            cc1 = 0x22;
            sel = 0;
            *(s16 *)(stack90 + 2) = 1;
        }
        *(s16 *)stack90 = 2;
        func_00115940((void *)(s32)func_0010ace0(*(s16 *)(arg0 + idx * 2 + 0x36)), stackd0, 2);
        pos[0] = fx - 40.0f;
        pos[1] = fy + 21.0f;
        func_0034f2e0(*(u8 **)(arg0 + 0x1C5C), pos[0], pos[1], c0, c1, c2, alpha);
        pos[0] = fx + 89.0f;
        pos[1] = pos[1];
        func_0034f2e0(*(u8 **)(arg0 + 0x1C60), pos[0], pos[1], c0, c1, c2, alpha);
        k = *(u8 *)(stackd0 + 12);
        pos[0] = fx + 72.0f;
        pos[1] = fy + 26.0f;
        do {
            div = k % 10;
            func_0034f2e0(*(u8 **)(arg0 + div * 4 + 0x1C7C), pos[0], pos[1], c3, cc0, cc1, alpha);
            pos[0] -= 22.0f;
            k /= 10;
        } while (k != 0);
        if (sel == 0) {
            pos[0] = fx + 24.0f;
            pos[1] = fy + 33.0f;
            func_0034f2e0(*(u8 **)(arg0 + 0x1CA8), pos[0], pos[1], c3, cc0, cc1, alpha);
        }
        if (arg1 == func_00105330(1) && (*(u32 *)(arg0 + 0x1C) & 0x20) != 0) {
            pos[0] = 22.0f;
            func_0034f2e0(*(u8 **)(arg0 + 0x1CAC), pos[0], pos[1], 0xFF, 0x85, 0x1F, alpha);
        }
        pos[0] = fx + 99.0f;
        pos[1] = fy + 20.0f;
        func_00115c40(*(s64 *)pos, 0.0f, alpha, stack90);
        count = 0;
        (void)count;
        (void)fa;
        (void)sel;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cmpPersona", func_00137890);
#endif

// FUN_00137DD0
s32 func_00137dd0(u8* arg0) {
    s32 result = 1;
    s32 i = 0;
    s32 cmp = *(s16*)((u8*)arg0 + 0x20);
    for (; i < 0x1C; i++) {
        if (cmp < *(s32*)((u8*)arg0 + i * 0x30 + 0x1080)) {
            result = 0;
        }
    }
    return result & func_0034c210();
}

// FUN_00137E50
void func_00137e50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* var_5;
    u8* var_6;
    CmpPair pair;
    if ((arg1 < 0) || (arg1 > 0)) {
        func_0046d730(&D_005EB580[0], 0x505);
    }
    if (arg0 == 0) {
        func_0046d730(&D_005EB580[0], 0x506);
    }
    if (arg3 != 0) {
        var_6 = &D_005EB560[arg1 * 0x1C];
        var_5 = var_6 + 8;
    } else {
        var_5 = &D_005EB560[arg1 * 0x1C];
        var_6 = var_5 + 8;
    }
    pair = *(CmpPair*)&D_005EB570[arg1 * 0x1C];
    arg1 = *(s32*)&D_005EB578[arg1 * 0x1C];
    if (arg2 != 0) {
        func_003550d0(arg0, var_5, var_6);
    } else {
        func_00355070(arg0, var_6, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, arg1);
}
