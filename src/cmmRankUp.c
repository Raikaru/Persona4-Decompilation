/* Consolidated Persona 4 source units. */
/* Original translation unit cmmRankUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "fr_font_internal.h"
extern u8 *func_00460990();
extern void func_00251d80();
extern u8 D_007963D0[];
extern void func_00460ac0();
extern void func_002516f0();

/* Absolute-addressed data (retail emits lui/addiu for these, so they must be
 * array-typed; scalar spelling would switch them to GPREL16). */
extern u8 D_00635CF8[];
extern u8 D_00635D18[];
extern u8 D_006367C0[];
extern u8 D_00636310[];
extern u8 D_00636390[];
extern u8 D_00636410[];
extern u8 D_00636460[];
extern u8 D_00636480[];
extern u8 D_006364D0[];
extern u8 D_006364F0[];
extern u8 D_00636540[];
extern u8 D_00636210[];
extern u8 D_00636230[];
extern s64 D_00636250[];
extern f32 D_00636258[];
extern u8 D_00636260[];
extern u8 D_006361F0[];
extern u32 D_80000046[];
extern u32 D_8000001E[];
extern f32 D_00761184;
extern f32 D_007613A0;
extern f32 D_007612CC;
extern f32 D_007612D0;
extern f32 D_0076120C;
extern f32 D_00761288;
extern f32 D_0076122C;
extern void (*D_00887300[])(u32, u32);
extern void *(*D_008873F4[])(size_t, size_t, u32);

void func_0044ea90(void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
extern u8 *func_00145270(s32 size);
extern void func_0047a6d0(s32 arg0, s32 arg1, void *arg2);
extern void func_00189ec0();
extern void func_00268bd0(s32 arg0, s32 arg1);
extern void func_003ef3a0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit object copies (retail lq/sq). */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636560;
extern u_long128 D_00636570;
typedef struct { u32 w0; u32 w1; } CopyPair;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 f18;
    f32 f1C;
    s16 f20;
    s16 f22;
} Sp120;
extern u_long128 D_00636730;
extern void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_0045e6a0(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                          f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_00252230(Sp120 *arg0, Sp120 *arg1, Sp120 *arg2, f32 fparg0);
 extern void func_003e0870(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *func_00251570(s32 arg0, s32 arg1);
extern void func_00251850(s32 arg0);
extern s32 func_0025f360(s32 arg0, s32 arg1, u8 *arg2);
extern s32 func_0035afa0(s32 arg0);
extern s32 func_003b7060();
extern void func_003e05f0(void *arg0, void *arg1, void *arg2);
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern void func_0045db40(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                           f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, s16 arg7, f32 fparg0, s16 arg_sp0,
                          void *arg_sp8, s32 arg_sp10, void *arg_sp18);
extern s32 func_0025fe50(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
extern s32 func_0025ff60(s32 arg0);
extern void func_004b12e0(s32 arg0, s32 arg1);
extern void func_004b1250(s32 arg0, void *arg1);
extern void func_004b14f0(s32 arg0, f32 *arg1);
extern void func_004b13f0(s32 arg0, f32 *arg1);
extern void func_001102f0(void *arg0, s32 arg1, s32 arg2, f32 arg3);
extern u8 *func_00457120(void);
extern s32 func_003e9700(s32 arg0);
extern void func_00278450(s32 arg0, s32 arg1, void *arg2);
extern void func_0045aeb0(s32 arg0, void *arg1);
extern f32 fGpffffa66c;
extern f32 fGpffffa670;
extern f32 fGpffffa674;
extern f32 fGpffffa678;
extern u16 D_008C024E[];
extern u8 D_00636580[];
extern u8 D_006365D0[];
extern u_long128 D_006365F0;
extern u_long128 D_00636600;
extern u_long128 D_00636610;
extern u_long128 D_00636620;
extern u8 D_00636630[];
extern u8 D_00636650[];
extern u8 D_00636670[];
extern u8 D_00636690[];
extern u8 D_006366B0[];
extern u8 D_006366D0[];
extern u8 D_006366F0[];
extern u8 D_00636710[];
extern u8 D_00635C80[];
extern u8 D_00635CA0[];
extern u8 D_005DC974[];
extern s32 func_00248760();
extern u8 *func_002438b0();
extern u8 *func_00246d90();
extern u8 *func_00109220();

/* Old-style: the two callbacks passed here (func_00251e60 takes one s32,
 * func_00251ec0 takes none) do not share a signature, and a typed prototype
 * would force casts at every call site. */
s32 func_00451fc0();

/* Forward declarations for asm-fallback siblings referenced by C bodies. */
s32 func_00253850();
s32 func_00254a70();
s32 func_0025b240();
void func_0025c100();

typedef int (*code)();
extern code DAT_008873ec_abs[];



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.



// FUN_00251D80
void func_00251d80(s32 arg0, s32 *arg1) {
    extern s32 *func_00452560();
    u8 *base;
    s32 i;
    u8 *entry;

    base = (u8 *)func_00452560(arg1);
    entry = base;
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)entry & 1) {
            if (*(void **)(entry + 8) == NULL) {
                func_0046d730(D_00635CF8, 0x289);
            }
            if ((*(s32 (**)(u8 *, u8 *, u8 *))(entry + 8))(base, entry, *(u8 **)(base + 0x9E0)) != 0) {
                *(u32 *)entry &= ~1;
            }
        }
        entry += 0x78;
    }
    func_002516f0(base, *(u8 **)(base + 0x9E0));
}



// FUN_00251E60
s32 func_00251e60(s32 arg0) {
    u8 *p;

    func_00452560();
    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00251d80;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_007963D0, p);
    return 0;
}

// FUN_00251EC0
void func_00251ec0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00251F00
void func_00251f00(s32 arg0, u32 *arg1) {
    u8 *temp_2;

    func_0044ea90(D_00635CF8, 0x277);
    temp_2 = (u8 *)D_008873F4[0](1, 0x9E4, 0x40000);
    *(u8 **)(temp_2 + 0x9E0) = (u8 *)arg1;
    if (temp_2 == NULL) {
        func_0046d730(D_00635CF8, 0x2D5);
    }
    func_00451fc0(arg0, D_00635D18, 0xF, 0, 0, func_00251e60, func_00251ec0, temp_2);
}



/* Seven spellings were tried without this pragma - ~2 / 0xFFFFFFFD / -3
 * literals, mask locals before and after the call, for and while forms,
 * |= and &= operators, and a ternary - all stuck at nd 24.
 * measured: MWCC rematerializes the flag-clear mask (addiu a0,zero,-3) inside
 * the else-branch instead of the loop preheader, shifting every temp register;
 * with the pragma the object is byte-identical (nd 3 = window padding). */
#pragma opt_loop_invariants on

// FUN_00251FC0
void func_00251fc0(s32 arg0, s32 arg1) {
    extern u32 *func_00452560();
    u32 *p;
    u32 temp;
    s32 i;

    p = func_00452560();
    for (i = 0; i < 0x10; i++) {
        temp = *p;
        if (temp & 1) {
            if (arg1 != 0) {
                *p = temp | 2;
            } else {
                *p = temp & ~2;
            }
        }
        p = (u32 *)((u8 *)p + 0x78);
    }
}
/* measured: scope closer for the hoist above - leaving it on changes the
   next functions in this file, so it is turned off immediately after. */
#pragma opt_loop_invariants off

/* Absolute-addressed float data for func_00252050's stack snapshot. */
extern f32 D_00635D28[];
extern f32 D_00635D2C[];
extern f32 D_00635D30[];
extern u8 D_00635D40[];
extern u8 D_00636180[];
extern u8 *func_00251d30(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void *func_002467b0(s32 arg0);
extern s32 func_00106330(s32 flag);
extern s64 func_00248d80(s16 arg0);
extern void func_00279d40(s32 arg0);
extern u8 *func_00279030(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0,
                         s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *func_002736d0(u8 **arg0, s32 arg1);
extern s32 func_002738d0(u8 *arg0);
extern void func_00272a10(u8 *arg0, f32 fparg0, f32 fparg1);
extern void func_00272ba0(u8 *arg0, s32 arg1);
extern void func_00271b70(u8 *arg0);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00268cb0(u8 *arg0);
extern void func_00268c20(s32 arg0, s32 arg1);

/* measured: opt_propagation off around func_00252050 batches the D_00635D28/
   2C/30 lwc1 loads before the spFloat stores; plain float temps under the
   default propagation setting interleave each load/store pair. Loop 1's
   value pair and loop 2's counter are value-class locals (v/w/t) so they
   land in $v1/$v0, and loop 2 uses fresh pointer locals so mwcc
   re-allocates $a1/$a2 instead of keeping loop 1's $a2/$a3. */
/* measured: opt_propagation-off bracket pins the retail access-order batch. */
#pragma opt_propagation off
// FUN_00252050
void func_00252050(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 *func_00452560();
    f32 spFloat[3];
    s32 copy2[0x87 * 2];
    s32 copy1[0x1B];
    u8 *src;
    u8 *p;
    u8 *srcp;
    u8 *dstp;
    u8 *srcp2;
    u8 *dstp2;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    s32 temp_18;
    f32 fa;
    f32 fb;
    f32 fc;

    fa = *(f32 *)D_00635D28;
    fb = *(f32 *)D_00635D2C;
    fc = *(f32 *)D_00635D30;
    spFloat[0] = fa;
    spFloat[1] = fb;
    spFloat[2] = fc;

    srcp = D_00635D40;
    dstp = (u8 *)copy2;
    i = 0x87;
    do {
        v = *(s32 *)(srcp + 0);
        w = *(s32 *)(srcp + 4);
        srcp += 8;
        i--;
        *(s32 *)(dstp + 0) = v;
        *(s32 *)(dstp + 4) = w;
        dstp += 8;
    } while (i > 0);

    srcp2 = D_00636180;
    dstp2 = (u8 *)copy1;
    v = 0x1B;
    do {
        t = *(s32 *)(srcp2 + 0);
        srcp2 += 4;
        v--;
        *(s32 *)(dstp2 + 0) = t;
        dstp2 += 4;
    } while (v > 0);

    p = func_00452560(arg0);
    if (arg1 >= 3) {
        func_0046d730(D_00635CF8, 0x329);
    }
    switch (arg1) {
    case 0:
        src = (u8 *)copy2 + arg2 * 0x6C;
        break;
    case 1:
        src = (u8 *)copy1 + arg2 * 0x6C;
        break;
    case 2:
        src = NULL;
        break;
    }
    temp_18 = *(s32 *)&spFloat[arg1];
    p = func_00251d30(p);
    if (p == NULL) {
        func_0046d730(D_00635CF8, 0x2A5);
    }
    func_0043f9c8(p, 0, 0x78);
    *(u32 *)p |= 1;
    *(s32 *)(p + 8) = temp_18;
    if (src != NULL) {
        func_0043f810(p + 0xC, src, 0x6C);
    }
}
/* measured: closes opt_propagation-off bracket for func_00252050. */
#pragma opt_propagation on



/* 1244/1248 bytes; no relocations; four zero alignment bytes.
 * Named float snapshots preserve interpolation order. Packed channels use
 * unsigned word shifts and byte truncation, including the high channel. */
// FUN_00252230
void func_00252230(Sp120 *out, Sp120 *a, Sp120 *b, f32 t)
{
    f32 fa;
    f32 fb;
    f32 r;

    fa = a->f4;
    fb = b->f4;
    out->f4 = fa + t * (fb - fa);
    fa = a->f8;
    fb = b->f8;
    out->f8 = fa + t * (fb - fa);
    fa = a->fC;
    fb = b->fC;
    out->fC = fa + t * (fb - fa);
    fa = a->f10;
    fb = b->f10;
    out->f10 = fa + t * (fb - fa);
    fa = a->f14;
    fb = b->f14;
    out->f14 = fa + t * (fb - fa);
    fa = a->f1C;
    fb = b->f1C;
    out->f1C = fa + t * (fb - fa);
    fa = (f32)a->f20;
    fb = (f32)b->f20;
    out->f20 = (s16)(s32)(fa + t * (fb - fa));
    fa = (f32)a->f22;
    fb = (f32)b->f22;
    out->f22 = (s16)(s32)(fa + t * (fb - fa));
    {
        f32 ba;
        f32 bb;
        ba = (f32)(u32)(((u32)a->f18 >> 24) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 24) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 = (s32)(((u32)(u8)r) << 24);
        ba = (f32)(u32)(((u32)a->f18 >> 16) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 16) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(((u32)(u8)r) << 16);
        ba = (f32)(u32)(((u32)a->f18 >> 8) & 0xFF);
        bb = (f32)(u32)(((u32)b->f18 >> 8) & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(((u32)(u8)r) << 8);
        ba = (f32)(u32)((u32)a->f18 & 0xFF);
        bb = (f32)(u32)((u32)b->f18 & 0xFF);
        r = ba + t * (bb - ba);
        out->f18 |= (s32)(u32)(u8)r;
    }
}


/* measured: fixed solo + schedule on, 188 differing words (was 202), 211/211 exact instrs, 24 relocs resolved; frame 0x100 vs retail 0xF0 (one extra sq), s3/s1/s2/s0 vs s0/v0/s2/t0 coloring, D_00887300 hoist via work reuse, mtc1 zero scheduling; call-clobber floor (retail keeps ctx in v0/special in t0 across func_00252230 which never touches v0/t0, b210 spills to saved). Production stays ASM. */
/* measured 00252710 2026-09-19: remove unscheduled-retail `schedule on` guard (was 194 vs 208, -6.7%); unscheduled object 211 vs 211 (exact, inside 202-214), edits 208 -> 88. */
// FUN_00252710 NONMATCHING
#ifdef NON_MATCHING
s32 func_00252710(s32 arg0, u8 *work, u8 *ctx)
{
    Sp120 sp120;
    u8 mat[0x40];
    u8 uv[0x20];
    u8 *src;
    u8 *dst;
    s32 count;
    s32 temp_3;
    s32 temp_2;
    s32 rank;
    s32 done;
    s32 special;
    s32 tex;
    done = 0;
    special = 0;
    if (*(s32 *)(ctx + 8) == 0xA) {
        special = 1;
    }
    if (!(*(s32 *)(work + 0) & 2)) {
        *(s32 *)(work + 4) += 1;
    }
    rank = *(s32 *)(work + 4);
    if (rank >= 0x3C) {
        done = 1;
    }
    if (rank >= 0x1F) {
        func_00252230(&sp120, (Sp120 *)(work + 0x30), (Sp120 *)(work + 0x54),
                      (f32)(rank - 0x1E) / 30.0f);
    } else {
        func_00252230(&sp120, (Sp120 *)(work + 0xC), (Sp120 *)(work + 0x30),
                      (f32)rank / 30.0f);
    }
    if (special != 0) {
        if (sp120.f18 == 0xFFE92CFF) {
            *(s32 *)(work + 0xC) = 0;
            sp120.f18 = -1;
        } else {
            sp120.f18 = 0xBFBFBFFF;
        }
    }
    src = D_006361F0;
    dst = uv;
    count = 4;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    tex = func_0025f360(0x18, 0, *(u8 **)(ctx + 0x10));
    func_003e0870(mat, (u8 *)&sp120 + 0xC, sp120.f1C, 0);
    if (*(s32 *)(work + 0xC) == 1) {
        work = (u8 *)D_00887300;
        (*(void (**)(u32, u32))work)(7, 2);
        (*(void (**)(u32, u32))work)(9, 2);
        (*(void (**)(u32, u32))work)(6, 1);
        (*(void (**)(u32, u32))work)(8, 1);
        (*(void (**)(u32, u32))work)(0xC, 1);
        (*(void (**)(u32, u32))work)(2, 4);
        (*(void (**)(u32, u32))work)(0xE, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x48);
        func_00366c70((s32)sp120.f4, (s32)sp120.f8, sp120.f20, sp120.f22,
                      (u32)sp120.f18 >> 8, sp120.f18 & 0xFF, 0,
                      (s16)(sp120.f20 >> 1), 0.0f,
                      (s16)(sp120.f22 >> 1), mat, tex, uv);
    } else {
        func_00366c70((s32)sp120.f4, (s32)sp120.f8, sp120.f20, sp120.f22,
                      (u32)sp120.f18 >> 8, sp120.f18 & 0xFF, 1,
                      (s16)(sp120.f20 >> 1), 0.0f,
                      (s16)(sp120.f22 >> 1), mat, tex, uv);
    }
    return done;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252710);
#endif

/* measured: refused (2026-09-18): archived LRankUp_00252a60_body.c installed
   guarded, fixed one compile error (`*(s32 *)(arg2+0x10)` -> `*(u8 **)` to match
   current `func_0025f360(s32,s32,u8*)`, as elsewhere in this file), then measured
   GUARDED_SCORE 983 (reloc-masked, 762 edits +2 reloc-only via
   `python3 -E -s tools/measure_guarded.py src/cmmRankUp.c func_00252a60`);
   fnalign retail 892 vs object 1069 instrs (+177, +19.8%, outside the 3% gate of
   +/-27 via `python3 -E -s tools/fnalign.py src/cmmRankUp.c func_00252a60
   --candidate /var/tmp/bank52a60/cand.c --quiet`). Frame retail 0x240 vs object
   0x250 (+16B, one extra sq); prologue colours retail $s3/$s2/$s1 vs object
   $s0/$s3/$fp with GPR rotation through the body. No omitted call: all retail
   jal/jalr sites (43, incl. 2x func_00252230, 4x func_003e0870, 6x func_00366c70,
   vtable jalr x4, func_0025f360/func_0035afa0/func_003e05f0/func_0044b7b0/
   func_0044b610/func_00251570/func_00251850/func_003f6440) are present in the
   body. Longer direction points at insert runs: eight int-to-float sites with
   the `2.0f*(f32)(((u32)x>>1)|(x&1))` negative-path doubling (~10 instrs each),
   the aggregate RankUpLocals struct vs retail separate buffers, and FP saved-reg
   rotation. Archive health: 353 lines on disk (brief said 354); code is lines
   1-352, line 353 is a bare trailing note without comment delimiters, the `}` closer and
   the RankUpLocals typedef (0x28/0x20/0x20/0x40/0x40/0x40+Sp120+s64/f32/f32/f32/
   s64/f32, from .probe/Rank52710Recovery/owner_LRankUp_00252a60.c:398-412) are
   both missing from the archive and were supplied from the probe file; the
   archive's `*(s32 *)` spelling for the func_0025f360 arg was the only other
   difference from that probe. Production stays ASM. */
/* measured: skeleton (2026-09-19): guarded fnalign retail 889 vs object 880 instrs (-9, -1.0%, inside 865-919), 782 words, 249 edits (+5 reloc-only); frame retail 0x240 vs object 0x230 (one sq under); separate buffers, plain (f32)(u32) casts, two-temp do-while x4, all 43 jal/jalr present. Production stays ASM. */
// FUN_00252A60 NONMATCHING
#ifdef NON_MATCHING
s32 func_00252a60(s32 arg0, u8 *arg1, u8 *arg2) {
    u8 spC0[0x28];
    u8 spF0[0x20];
    u8 sp110[0x20];
    u8 sp130[0x40];
    u8 sp170[0x40];
    u8 sp1B0[0x40];
    Sp120 sp1F0;
    s64 sp218;
    f32 sp220;
    f32 sp228;
    f32 sp22C;
    s64 sp230;
    f32 sp238;
    u8 *src;
    u8 *dst;
    u8 *src2;
    u8 *dst2;
    u8 *src3;
    u8 *dst3;
    s32 count;
    s32 temp1;
    s32 temp2;
    s32 done;
    s32 is10;
    s32 alpha_i;
    s32 rnd;
    f32 f0;
    f32 f1;
    f32 f20;
    f32 f21;
    s32 call1;
    s32 call2;
    s32 call3;
    u_long128 *qsrc;
    u_long128 *qdst;
    void (**vt)(u32, u32);

    done = 0;
    is10 = 0;
    if (*(s32 *)(arg2 + 8) == 0xA) {
        is10 = 1;
    }
    if (!(*(s32 *)arg1 & 2)) {
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) + 1;
    }
    if ((*(s32 *)(arg1 + 4)) >= 0x3C) {
        done = 1;
    }
    if ((*(s32 *)(arg1 + 4)) >= 0x1F) {
        func_00252230(&sp1F0, (Sp120 *)(arg1 + 0x30), (Sp120 *)(arg1 + 0x54),
                      (f32)((*(s32 *)(arg1 + 4)) - 0x1E) / 30.0f);
    } else {
        f20 = (D_00761184 * (f32)(*(s32 *)(arg1 + 4))) / 30.0f;
        f20 = func_0044b7b0(f20);
        func_00252230(&sp1F0, (Sp120 *)(arg1 + 0xC), (Sp120 *)(arg1 + 0x30), f20);
    }

    src = D_00636210;
    dst = sp110;
    count = 4;
    do {
        temp1 = *(s32 *)(src + 0);
        temp2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)(dst + 0) = temp1;
        *(s32 *)(dst + 4) = temp2;
        dst += 8;
    } while (count > 0);

    src2 = D_00636230;
    dst2 = spF0;
    count = 4;
    do {
        temp1 = *(s32 *)(src2 + 0);
        temp2 = *(s32 *)(src2 + 4);
        src2 += 8;
        count--;
        *(s32 *)(dst2 + 0) = temp1;
        *(s32 *)(dst2 + 4) = temp2;
        dst2 += 8;
    } while (count > 0);

    if ((*(s32 *)(arg1 + 4)) < 0x1F) {
        func_003e0870(sp1B0, (u8 *)&sp1F0 + 0xC, sp1F0.f1C, 0);
    } else {
        temp1 = (*(s32 *)(arg1 + 4)) - 0x1E;
        sp218 = D_00636250[0];
        sp220 = D_00636258[0];
        sp230 = sp218;
        sp238 = D_00636258[0];
        func_003e0870(sp1B0, (u8 *)&sp1F0 + 0xC, sp1F0.f1C, 0);
        f20 = (-90.0f * (f32)temp1) / 30.0f;
        func_003e0870(sp1B0, &sp230, f20, 2);
    }

    call1 = func_0035afa0(*(s32 *)(arg2 + 0x14));
    call2 = func_0035afa0(*(s32 *)(arg2 + 0x18));
    if ((*(s32 *)(arg1 + 4)) >= 0x19) {
        call3 = func_0025f360(0x19, 0, *(u8 **)(arg2 + 0x10));
        if ((*(s32 *)(arg1 + 4)) < 0x1F) {
            f21 = (f32)((*(s32 *)(arg1 + 4)) - 0x19) / 5.0f;
        } else {
            f0 = (f32)((*(s32 *)(arg1 + 4)) - 0x1E);
            if (f0 < 5.0f) {
                f21 = 1.0f - (f0 / 5.0f);
            } else {
                f21 = 0.0f;
            }
        }
        f20 = D_007613A0 * f21;
        func_003e0870(sp170, (u8 *)&sp1F0 + 0xC, f20, 0);
        func_003e05f0(sp130, sp170, sp1B0);
        qsrc = (u_long128 *)sp130;
        qdst = (u_long128 *)sp170;
        count = 4;
        do {
            *qdst = *qsrc;
            qsrc++;
            count--;
            qdst++;
        } while (count > 0);
        func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                      0x73, 0x90, 0xFFFFFF,
                      *(u8 *)&sp1F0.f18, 1, 0x39, 0.0f, 0x48,
                      sp170, call3, spF0);
        if (is10 != 0) {
            func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                          0x6D, 0x89, 0x7F7F7F,
                          0xFF, 1, 0x37, 0.0f, 0x45,
                          sp1B0, call3, spF0);
        } else {
            func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                          0x6D, 0x89, 0xFF9C35,
                          0xFF, 1, 0x37, 0.0f, 0x45,
                          sp1B0, call3, spF0);
        }
    }

    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8,
                  ((u32)sp1F0.f18) & 0xFF, 3,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call1, sp110);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8,
                  ((u32)sp1F0.f18) & 0xFF, 5,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call2, sp110);

    vt = D_00887300;
    vt[0](7, 2);
    vt[0](9, 2);
    vt[0](6, 0);
    vt[0](8, 0);
    vt[0](0xC, 1);
    vt[0](2, 4);
    vt[0](0xE, 0);
    func_003f6440(3, 0x30003);
    func_003f6440(2, 0x48);

    temp1 = *(s16 *)(arg2 + 0x3C) + 1;
    *(s16 *)(arg2 + 0x3C) = (s16)temp1;
    if ((s16)temp1 >= 0x78) {
        *(s16 *)(arg2 + 0x3C) = 0;
    }
    f20 = (f32)(*(s16 *)(arg2 + 0x3C));
    f20 = (D_007612D0 * f20) / 120.0f;
    f20 = D_007612CC + f20;
    f20 = func_0044b7b0(f20);
    f20 = (1.0f + f20) / 2.0f;

    alpha_i = sp1F0.f18 & 0xFF;
    f21 = (f32)(u32)alpha_i;
    alpha_i = (s32)(D_0076120C * f21 * f20);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8, alpha_i, 2,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call1, sp110);

    alpha_i = sp1F0.f18 & 0xFF;
    f21 = (f32)(u32)alpha_i;
    alpha_i = (s32)(D_0076120C * f21 * f20);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8, alpha_i, 4,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call2, sp110);

    rnd = func_003b7060();
    f21 = (f32)(u32)rnd;
    f20 = D_007612D0 * (f21 / 2147483600.0f);
    rnd = func_003b7060();
    f21 = (f32)(u32)rnd;
    if ((f21 / 2147483600.0f) < D_00761288) {
        rnd = func_003b7060();
        f0 = (f32)(u32)rnd;
        f0 = 46.0f * (f0 / 2147483600.0f);
        if (!(f0 >= 2147483600.0f)) {
            temp1 = (s32)f0;
        } else {
            temp1 = (s32)(f0 - 2147483600.0f);
            temp1 |= (s32)0x80000000;
        }
        temp1 += 0x46;
        f21 = (f32)(u32)temp1;
    } else {
        rnd = func_003b7060();
        f0 = (f32)(u32)rnd;
        f0 = 40.0f * (f0 / 2147483600.0f);
        if (!(f0 >= 2147483600.0f)) {
            temp1 = (s32)f0;
        } else {
            temp1 = (s32)(f0 - 2147483600.0f);
            temp1 |= (s32)0x80000000;
        }
        temp1 += 0x1E;
        f21 = (f32)(u32)temp1;
    }
    sp228 = f21 * func_0044b610(f20);
    f1 = -f21 * func_0044b7b0(f20);
    sp22C = f1;

    if ((*(s32 *)(arg1 + 4)) < 0x29) {
        u8 *p = func_00251570(arg0, 0);
        if (p != NULL) {
            *(f32 *)(p + 4) = sp1F0.f4 + sp228;
            *(f32 *)(p + 8) = sp1F0.f8 + f1;
        }
        src3 = D_00636260;
        dst3 = spC0;
        count = 5;
        do {
            temp1 = *(s32 *)(src3 + 0);
            temp2 = *(s32 *)(src3 + 4);
            src3 += 8;
            count--;
            *(s32 *)(dst3 + 0) = temp1;
            *(s32 *)(dst3 + 4) = temp2;
            dst3 += 8;
        } while (count > 0);
        rnd = func_003b7060();
        f21 = (f32)(u32)rnd;
        temp1 = (s32)(5.0f * (f21 / 2147483600.0f));
        f20 = *(f32 *)(spC0 + temp1 * 8 + 4);
        sp228 = *(f32 *)(spC0 + temp1 * 8);
        sp22C = f20;
        p = func_00251570(arg0, 3);
        if (p != NULL) {
            rnd = func_003b7060();
            f21 = (f32)(u32)rnd;
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = sp228;
            *(f32 *)(p + 8) = f20;
        }
    }

    if ((*(s32 *)(arg1 + 4)) == 0x14) {
        u8 *p = func_00251570(arg0, 1);
        if (p != NULL) {
            *(u32 *)p |= 2;
            rnd = func_003b7060();
            f21 = (f32)(u32)rnd;
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = 112.0f;
            *(f32 *)(p + 8) = 272.0f;
        }
        p = func_00251570(arg0, 2);
        if (p != NULL) {
            *(u32 *)p |= 4;
            rnd = func_003b7060();
            f21 = (f32)(u32)rnd;
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = 68.0f;
            *(f32 *)(p + 8) = 419.0f;
        }
    } else if ((*(s32 *)(arg1 + 4)) == 0x1F) {
        func_00251850(arg0);
    }
    return done;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252a60);
#endif

/* measured: not attempted this wave (4640 B); m2c draft is structurally
   complete; its msub.s/adda.s M2C_ERRORs in the func_0025f3f0 args are
   `a - b*c` / `a + b*c` accumulator idioms (verified on mwcc b210 - msub.s/
   madd.s), and the sp110 table reads feed the loop's func_0025f3f0 calls.
   Same family walls as func_00252a60/002566d0/002570f0: (u32)-cast alpha
   sites, D_00887300 base rematerialization, mwcc stack-slot overlap of
   same-type locals + 0x10 alignment of buffers >= 0x10, FP saved-reg
   rotation, and the D_00636290 copy loop + zero-fill loops need the m2c
   two-temp/do-while spellings. gp-0x7F7C/-0x7F6C floats: 0x00761174/
   0x00761184 (GP base 0x007690F0). */
/* measured: skeleton (2026-09-19): scratch candidate fnalign retail 1157 vs object 1128 instrs, edits 528 (+14 reloc-only), within 3% gate (1122-1192) and 1125-1195 band; delivered s32 shape obj 4516B = 1129 instrs, frame 0x150 both sides, words (reloc-masked) 1057. All 52 retail jal sites present; counted fors; two-temp/do-while copies + zero-fills; (u32)-cast alphas; accumulators as plain C. Requires fwd-decl fix void->s32 (line 102, as for 00254a70). Production stays ASM. */
// FUN_00253850 NONMATCHING
#ifdef NON_MATCHING
typedef struct {
    u8 pad[8];
    u8 spB0[0x10];
    u8 spC0[0x20];
    u8 spE0[0x10];
    u8 spF0[0x20];
    u8 sp110[0x40];
} RankUp38Locals;
extern u8 D_00636290[];
extern u8 D_00635CC0[];
extern u8 D_00635CE0[];
extern f32 D_00761174;
extern f32 D_0076118C;
extern f32 D_00761308;
extern f32 D_0076132C;
extern f32 D_0076139C;
s32 func_0025f3f0(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, f32 f0, f32 f1, f32 f2);
s32 func_0025f430(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, s32 a7, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void func_0045dfd0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4);
u8 *func_0046a770(char *arg0);
f32 func_0046b1f0(void *ptr, s32 idx);
void func_0025e9e0(s32 a0, s32 a1, s32 a2, void *a3, s32 a4, f32 f0, f32 f1, f32 f2);
u8 *func_00246830(s32 arg0);
s32 func_00253850(arg0, arg1, arg2)
s32 arg0;
u8 *arg1;
u8 *arg2;
{
    RankUp38Locals sp;
    s32 special;
    s32 rank;
    s32 i;
    s32 d;
    s32 color;
    s32 iv;
    s32 alpha;
    s32 n;
    s32 t1;
    s32 t2;
    s32 tbl;
    s32 asset;
    s32 font;
    s32 idx;
    s32 cnt;
    f32 s;
    f32 f;
    f32 f20;
    f32 f21;
    f32 w;
    f32 x;
    u8 *src;
    u8 *dst;
    u8 *p;

    special = 0;
    if (*(s32 *)(arg2 + 8) == 0xA) {
        special = 1;
    }
    rank = *(s32 *)(arg1 + 4);
    if (rank >= 0x10) {
        if (rank < 0x20) {
            src = D_00636290;
            dst = sp.sp110;
            n = 8;
            do {
                t1 = *(s32 *)src;
                t2 = *(s32 *)(src + 4);
                src += 8;
                n--;
                *(s32 *)dst = t1;
                *(s32 *)(dst + 4) = t2;
                dst += 8;
            } while (n > 0);
            for (i = 0; i < 8; i++) {
                d = rank - 0xF;
                if (i <= d) {
                    d = d - i;
                    if (d < 9) {
                        s = func_0044b7b0((D_00761174 * (f32)d) / 8.0f);
                        func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0, *(u8 **)(arg2 + 0x10), 1,
                            ((f32 *)sp.sp110)[i * 2],
                            ((f32 *)sp.sp110)[i * 2 + 1] - s * 40.0f, 0.0f);
                    } else {
                        func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0, *(u8 **)(arg2 + 0x10), 1,
                            ((f32 *)sp.sp110)[i * 2],
                            ((f32 *)sp.sp110)[i * 2 + 1], 0.0f);
                    }
                }
            }
        } else {
            func_0025f3f0(0xFFFFFF, 0xFF, 0xD, 0, *(u8 **)(arg2 + 0x10), 1, 356.0f, 340.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0xE, 0, *(u8 **)(arg2 + 0x10), 1, 396.0f, 350.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0xF, 0, *(u8 **)(arg2 + 0x10), 1, 430.0f, 350.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x10, 0, *(u8 **)(arg2 + 0x10), 1, 467.0f, 338.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x11, 0, *(u8 **)(arg2 + 0x10), 1, 515.0f, 349.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x12, 0, *(u8 **)(arg2 + 0x10), 1, 550.0f, 347.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x13, 0, *(u8 **)(arg2 + 0x10), 1, 588.0f, 340.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x13, 0, *(u8 **)(arg2 + 0x10), 1, 603.0f, 340.0f, 0.0f);
        }
    }
    if (rank < 0x10) {
        s = func_0044b7b0((D_00761184 * (f32)rank) / 15.0f);
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0, *(u8 **)(arg2 + 0x10), 1,
            -((1.0f - s) * 640.0f), 375.0f, 0.0f);
    } else {
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0, *(u8 **)(arg2 + 0x10), 1, 0.0f, 375.0f, 0.0f);
    }
    if (rank >= 8) {
        if (rank < 0x10) {
            s = func_0044b7b0((D_00761184 * ((f32)rank - 7.0f)) / 8.0f);
            func_0025f430(0xFFFFFF, 0xFF, special + 0x2A, 0, *(u8 **)(arg2 + 0x10), 1, 0, 0,
                0.0f, (1.0f - s) * 10.0f + 380.0f, 0.0f, 0.0f, 1.0f, s);
        } else {
            func_0025f3f0(0xFFFFFF, 0xFF, special + 0x2A, 0, *(u8 **)(arg2 + 0x10), 1, 0.0f, 380.0f, 0.0f);
        }
    }
    if (rank >= 0x13) {
        if (rank < 0x1B) {
            s = func_0044b7b0((D_00761184 * (f32)(rank - 0x12)) / 8.0f);
            f = (1.0f - s) * 450.0f;
            if (special == 0) {
                func_0025f3f0(0xFFFFFF, 0xFF, 1, 0, *(u8 **)(arg2 + 0x10), 1, 188.0f + f, 375.0f, 0.0f);
            } else {
                func_0025f3f0(0xFFFFFF, 0xFF, 0x1A, 0, *(u8 **)(arg2 + 0x10), 1, 184.0f + f, 336.0f, 0.0f);
            }
            src = D_00635CC0;
            dst = sp.spF0;
            n = 4;
            do {
                t1 = *(s32 *)src;
                t2 = *(s32 *)(src + 4);
                src += 8;
                n--;
                *(s32 *)dst = t1;
                *(s32 *)(dst + 4) = t2;
                dst += 8;
            } while (n > 0);
            x = (f32)(s32)(218.0f + f);
            for (i = 0; i < 4; i++) {
                ((f32 *)sp.spF0)[i * 2] += x;
                ((f32 *)sp.spF0)[i * 2 + 1] += 406.0f;
                p = sp.spE0 + i * 4;
                p[0] = 0;
                p[1] = 0;
                p[2] = 0;
                p[3] = 0x99;
            }
            func_0045dfd0(sp.spE0, sp.spF0, 0.0f, 4, 4, 1);
            tbl = *(s32 *)(arg2 + 4);
            asset = *(s32 *)(arg2 + 0x10);
            font = (s32)func_0046a770((char *)D_00635CE0);
            if (font == 0) {
                func_0046d730(D_00635CF8, 0x1E4);
            }
            w = func_0046b1f0((void *)font, (s32)(((u8 *)func_002467b0(tbl & 0xFFFF))[8]) + 0x20);
            iv = (s32)f;
            func_0025e9e0(0xFFFFFF, 0xFF, (s32)(((u8 *)func_002467b0(tbl & 0xFFFF))[8]) + 0x20,
                (void *)font, 1, (f32)(iv + 299 - ((s32)w >> 1)), 407.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (u8 *)asset, 1, (f32)(iv + 0x163), 411.0f, 0.0f);
            func_00274ed0((f32)(iv + 0x188), 403.0f, 0.0f, -1, 0, 1,
                (const char *)func_00246830(tbl & 0xFFFF), 0, 0);
        } else {
            if (special == 0) {
                func_0025f3f0(0xFFFFFF, 0xFF, 1, 0, *(u8 **)(arg2 + 0x10), 1, 188.0f, 375.0f, 0.0f);
            } else {
                func_0025f3f0(0xFFFFFF, 0xFF, 0x1A, 0, *(u8 **)(arg2 + 0x10), 1, 184.0f, 336.0f, 0.0f);
            }
            src = D_00635CC0;
            dst = sp.spC0;
            n = 4;
            do {
                t1 = *(s32 *)src;
                t2 = *(s32 *)(src + 4);
                src += 8;
                n--;
                *(s32 *)dst = t1;
                *(s32 *)(dst + 4) = t2;
                dst += 8;
            } while (n > 0);
            for (i = 0; i < 4; i++) {
                ((f32 *)sp.spC0)[i * 2] += 218.0f;
                ((f32 *)sp.spC0)[i * 2 + 1] += 406.0f;
                p = sp.spB0 + i * 4;
                p[0] = 0;
                p[1] = 0;
                p[2] = 0;
                p[3] = 0x99;
            }
            func_0045dfd0(sp.spB0, sp.spC0, 0.0f, 4, 4, 1);
            tbl = *(s32 *)(arg2 + 4);
            asset = *(s32 *)(arg2 + 0x10);
            font = (s32)func_0046a770((char *)D_00635CE0);
            if (font == 0) {
                func_0046d730(D_00635CF8, 0x1E4);
            }
            w = func_0046b1f0((void *)font, (s32)(((u8 *)func_002467b0(tbl & 0xFFFF))[8]) + 0x20);
            func_0025e9e0(0xFFFFFF, 0xFF, (s32)(((u8 *)func_002467b0(tbl & 0xFFFF))[8]) + 0x20,
                (void *)font, 1, (f32)(299 - ((s32)w >> 1)), 407.0f, 0.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (u8 *)asset, 1, 355.0f, 411.0f, 0.0f);
            func_00274ed0(392.0f, 403.0f, 0.0f, -1, 0, 1,
                (const char *)func_00246830(tbl & 0xFFFF), 0, 0);
        }
    }
    if (rank >= 0x1F) {
        if (rank < 0x27) {
            s = func_0044b7b0((D_00761174 * (f32)(rank - 0x1E)) / 8.0f);
            if (special == 0) {
                func_0025f3f0(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0, *(u8 **)(arg2 + 0x10), 1,
                    277.0f, 350.0f - s * 17.0f, 0.0f);
            }
        } else if (special == 0) {
            func_0025f3f0(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0, *(u8 **)(arg2 + 0x10), 1,
                277.0f, 350.0f, 0.0f);
        }
    }
    color = 0xFFFFFF;
    if (rank >= 0x18) {
        if (rank < 0x27) {
            for (i = 0; i < 0xA; i++) {
                d = rank - 0x17;
                if (i <= d) {
                    if (i >= *(s32 *)(arg2 + 8)) {
                        color = 0xDE7201;
                    } else {
                        color = 0xFFFFFF;
                    }
                    f = (f32)(d - i);
                    if (f < 5.0f) {
                        s = func_0044b7b0((D_00761184 * f) / 5.0f);
                        func_0025f3f0(color, 0xFF, 0x15, 0, *(u8 **)(arg2 + 0x10), 1,
                            (1.0f - s) * 400.0f + (f32)(i * 0x17 + 0x162), 381.0f, 0.0f);
                    } else {
                        func_0025f3f0(color, 0xFF, 0x15, 0, *(u8 **)(arg2 + 0x10), 1,
                            (f32)(i * 0x17 + 0x162), 381.0f, 0.0f);
                    }
                }
            }
        } else {
            for (i = 0; i < 0xA; i++) {
                if (i >= *(s32 *)(arg2 + 8)) {
                    color = 0xDE7201;
                } else {
                    color = 0xFFFFFF;
                }
                func_0025f3f0(color, 0xFF, 0x15, 0, *(u8 **)(arg2 + 0x10), 1,
                    (f32)(i * 0x17 + 0x162), 381.0f, 0.0f);
            }
        }
    }
    if (rank >= 0x1F) {
        cnt = *(s16 *)(arg2 + 0x3E) + 1;
        *(s16 *)(arg2 + 0x3E) = (s16)cnt;
        if (cnt >= 0x2D) {
            *(s16 *)(arg2 + 0x3E) = 0;
        }
        idx = *(s32 *)(arg2 + 8) - 1;
        s = func_0044b7b0(D_007612CC + (D_007612D0 * (f32)*(s16 *)(arg2 + 0x3E)) / 45.0f);
        f21 = 1.0f;
        f20 = D_00761288 + D_0076118C * ((s + 1.0f) / 2.0f);
        if (rank < 0x3D) {
            f21 = (f32)(rank - 0x1E) / 30.0f;
            f = (1.0f - f21) * 255.0f;
            if (!(f >= 2147483648.0f)) {
                alpha = (s32)f & 0xFF;
            } else {
                alpha = ((s32)(f - 2147483648.0f) | 0x80000000) & 0xFF;
            }
            func_0025f430(0xFFFFFF, alpha, 0x1B, 0, *(u8 **)(arg2 + 0x10), 1,
                (s32)(s16)(s32)(58.0f * f21), (s32)(s16)(s32)(62.0f * f21),
                (f32)(idx * 0x17 + 0x165) - 58.0f * f21, 385.0f - 62.0f * f21, 0.0f,
                90.0f * f21, f21, f21);
        }
        f20 = f20 * f21;
        f = 1.0f + D_00761308 * f20;
        x = f20 * 255.0f;
        if (!(x >= 2147483648.0f)) {
            alpha = (s32)x & 0xFF;
        } else {
            alpha = ((s32)(x - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0025f430(color, alpha, 0x1C, 0, *(u8 **)(arg2 + 0x10), 1, 0, 0,
            (f32)(idx * 0x17 + 0x15E) - D_0076139C * f20, 377.0f - D_0076132C * f20, 0.0f, 0.0f,
            f, f);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00253850);
#endif


/* measured: banked (2026-09-18): archived docs/probe_archive/LRankUp_00254a70_body.c
   (332 lines on disk, code 1-331, line 332 bare trailing note stripped) installed
   guarded. GUARDED_SCORE 931 (reloc-masked via `python3 -E -s tools/measure_guarded.py
   src/cmmRankUp.c func_00254a70 --save-candidate /tmp/cand54a70_banked2.c`); fnalign
   retail 1060 vs object 1070 instrs (+10, +0.9% within 3% gate +/-32 via `python3 -E -s
   tools/fnalign.py src/cmmRankUp.c func_00254a70 --candidate /tmp/cand54a70_banked2.c --quiet`)
   with 481 edits +13 reloc-only, body 4280B vs retail 4240B (+40B), 102 relocs, frame
   both 0x170. "Content fails" concretely: 931 differing words / 481 edits dominated by
   (a) D_00887300 vtable-base rematerialization (retail hoists base to $18 once per
   7-call block, MWCC emits lui/addiu per jalr), (b) saved-GPR/FPR color rotation
   (retail $s/$f allocation vs MWCC reverse-decl order), (c) scheduling (copy-loop
   load/store batching, float interpolation and call-arg materialization order).
   Frame matches, no missing calls (15 jal targets +14 vtable jalr all present).
   Repairs from archive: supplied RankUp54Locals (not sibling RankUpLocals: 13 fields
   240B covering 0x80-0x170), 4 data externs above, fixed forward decl `void`->`s32`
   `func_00254a70()` (K&R kept as archived `s32(arg0,arg1,arg2)`; 0-arg caller in
   func_00255b00 still allowed via unspecified args; modernizing would prototype the
   caller and break the 0-arg call, so kept K&R), added `(char *)/(void *)/(s32)` casts
   for 0046a770/0025e9e0 sites (same moves), reordered 2x func_00274ed0 calls
   to header order (fr_font_internal.h floats-first, same $a/$f mapping), supplied 7
   prototypes above (0025f3f0/0025f430 from shdSprite, 0045dfd0 from mc, 0046a770 from
   promoted/code1_0046 `u8*(char*)`, 0046b1f0 from shdSprite/sdkSpr `f32(void*,s32)`,
   00246830 from cmmMisc `u8*(s32)`); no func_0025f360 calls so sibling `*(s32*)` fix
   N/A. No dummy locals (all used), no volatile/asm. Correctness doubt for Main:
   func_0025e9e0 has no recovered definition (still ASM in code1_0025); prototype
   `void(s32x4+void*+s32+f32x3)` inferred from two retail call sites ($a0-$a3+$t0 and
   $f12-$f14 with $f14=0.0f via mtc1 $0) and matching generated call shapes; return
   assumed void (unused). If verified definition required, treat as doubt.
   Production stays ASM via guard (build unchanged); next pass starts from this floor. */
// FUN_00254A70 NONMATCHING
#ifdef NON_MATCHING
typedef struct {
    u8 sp80[0x10];
    u8 sp90[0x20];
    u8 spB0[0x10];
    u8 spC0[0x20];
    u8 spE0[0x10];
    u8 spF0[0x10];
    u8 sp100[0x10];
    u_long128 sp110;
    u8 sp120[0x40];
    u32 sp160;
    u32 sp164;
    u32 sp168;
    u32 sp16C;
} RankUp54Locals;
extern u8 D_006362D0[];
extern u8 D_00635CC0[];
extern u8 D_00635CE0[];
extern f32 D_0076118C;
s32 func_0025f3f0(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, f32 f0, f32 f1, f32 f2);
s32 func_0025f430(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, s32 a7, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void func_0045dfd0(void *a0, void *a1, f32 f0, s32 a2, s32 a3, s32 a4);
u8 *func_0046a770(char *arg0);
f32 func_0046b1f0(void *ptr, s32 idx);
void func_0025e9e0(s32 a0, s32 a1, s32 a2, void *a3, s32 a4, f32 f0, f32 f1, f32 f2);
u8 *func_00246830(s32 arg0);
s32 func_00254a70(arg0, arg1, arg2)
s32 arg0;
u8 *arg1;
u8 *arg2;
{
    RankUp54Locals sp;
    s32 var_16;
    s32 temp_17;
    s32 i;
    s32 color;
    s32 temp_s0;
    s32 font;
    s32 asset;
    s32 count;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f14;
    f32 temp_f20;
    f32 temp_f21;
    void (**vtable)(u32, u32);
    u8 *src;
    u8 *dst;
    u8 *p;
    s32 n;

    var_16 = 0;
    if (*(s32 *)(arg2 + 8) == 0xA) {
        var_16 = 1;
    }
    temp_17 = *(s32 *)(arg1 + 4) - 0x3C;
    if (temp_17 < 0x13) {
        src = D_006362D0;
        dst = sp.sp120;
        n = 8;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);

        p = (u8 *)&sp.sp168;
        n = 4;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        sp.sp16C = sp.sp168;

        p = sp.sp100;
        n = 0x10;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        ((s32 *)sp.sp100)[0] = 0x15E;
        ((s32 *)sp.sp100)[1] = 0x17C;
        ((s32 *)sp.sp100)[2] = 0x122;
        ((s32 *)sp.sp100)[3] = 0x64;
        sp.sp110 = *(u_long128 *)sp.sp100;

        vtable = D_00887300;
        vtable[0](0xE, 0);
        vtable[0](0xC, 1);
        vtable[0](7, 2);
        vtable[0](9, 1);
        vtable[0](0x14, 1);
        vtable[0](6, 0);
        vtable[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp.sp16C, &sp.sp110, 0, 5.0f);
        func_0048a000();

        i = 0;
        while (i < 8) {
            if (temp_17 < i) {
                func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0,
                              *(void **)(arg2 + 0x10), 1,
                              ((f32 *)sp.sp120)[i * 2],
                              ((f32 *)sp.sp120)[i * 2 + 1], 10.0f);
            } else if (temp_17 - i < 9) {
                temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - i)) / 8.0f);
                temp_f1 = ((f32 *)sp.sp120)[i * 2 + 1];
                temp_f13 = temp_f1 + 50.0f * temp_f0;
                func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0,
                              *(void **)(arg2 + 0x10), 1,
                              ((f32 *)sp.sp120)[i * 2], temp_f13, 10.0f);
            }
            i++;
        }

        p = (u8 *)&sp.sp160;
        n = 4;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        sp.sp164 = sp.sp160;

        p = sp.spE0;
        n = 0x10;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        ((s32 *)sp.spE0)[0] = 0x15E;
        ((s32 *)sp.spE0)[1] = 0x17C;
        ((s32 *)sp.spE0)[2] = 0x122;
        ((s32 *)sp.spE0)[3] = 0x64;
        *(u_long128 *)sp.spF0 = *(u_long128 *)sp.spE0;

        vtable = D_00887300;
        vtable[0](0xE, 0);
        vtable[0](0xC, 1);
        vtable[0](7, 2);
        vtable[0](9, 1);
        vtable[0](0x14, 1);
        vtable[0](6, 0);
        vtable[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp.sp164, &sp.spF0, 0, 0.0f);
        func_0048a000();
    }

    if (temp_17 < 0x19) {
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0,
                      *(void **)(arg2 + 0x10), 1, 0.0f, 375.0f, 0.0f);
    } else if (temp_17 < 0x24) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x19)) / 10.0f);
        temp_f12 = 640.0f * temp_f0;
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0,
                      *(void **)(arg2 + 0x10), 1, temp_f12, 375.0f, 0.0f);
    }
    if (temp_17 < 0x1E) {
        func_0025f3f0(0xFFFFFF, 0xFF, var_16 + 0x2A, 0,
                      *(void **)(arg2 + 0x10), 1, 0.0f, 380.0f, 0.0f);
    } else if (temp_17 < 0x24) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x1E)) / 5.0f);
        temp_f12 = 380.0f;
        temp_f13 = 375.0f + 10.0f * temp_f0;
        temp_f14 = temp_f12;
        func_0025f430(0xFFFFFF, 0xFF, var_16 + 0x2A, 0,
                      *(void **)(arg2 + 0x10), 1, 0, 0,
                      temp_f12, temp_f13, temp_f14, temp_f14, 1.0f,
                      1.0f - temp_f0);
    }

    if (temp_17 < 0x14) {
        if (var_16 == 0) {
            func_0025f3f0(0xFFFFFF, 0xFF, 1, 0,
                          *(void **)(arg2 + 0x10), 1, 188.0f, 375.0f, 0.0f);
        } else {
            func_0025f3f0(0xFFFFFF, 0xFF, 0x1A, 0,
                          *(void **)(arg2 + 0x10), 1, 184.0f, 336.0f, 0.0f);
        }
        if (var_16 == 0) {
            func_0025f3f0(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0,
                          *(void **)(arg2 + 0x10), 1, 277.0f, 350.0f, 0.0f);
        }
    } else if (temp_17 < 0x1A) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x14)) / 5.0f);
        temp_f20 = (f32)(s32)temp_f0;
        temp_f21 = 1.0f - temp_f0;
        if (var_16 == 0) {
            temp_f14 = 188.0f;
            temp_f13 = 375.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 1, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        } else {
            temp_f14 = 184.0f;
            temp_f13 = 368.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 0x1A, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        }
        if (var_16 == 0) {
            temp_f14 = 277.0f;
            temp_f13 = 350.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        }
    }

    if (temp_17 < 5) {
        src = D_00635CC0;
        dst = sp.spC0;
        n = 4;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);
        i = 0;
        while (i < 4) {
            ((f32 *)sp.spC0)[i * 2] += 218.0f;
            ((f32 *)sp.spC0)[i * 2 + 1] += 406.0f;
            p = sp.spB0 + i * 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0x99;
            i++;
        }
        func_0045dfd0(sp.spB0, sp.spC0, 4.0f, 4, 1, 0);
        temp_s0 = *(s32 *)(arg2 + 4);
        asset = *(s32 *)(arg2 + 0x10);
        font = (s32)func_0046a770((char *)D_00635CE0);
        if (font == 0) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        temp_f20 = (f32)(299 - (((s32)func_0046b1f0(
            (void *)font,
            (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20)) >> 1));
        func_0025e9e0(0xFFFFFF, 0xFF,
                      (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20,
                      (void *)font, 1, temp_f20, 407.0f, 0.0f);
        func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (void *)asset, 1,
                      355.0f, 411.0f, 0.0f);
        func_00274ed0(392.0f, 403.0f, 0.0f, -1, 0, 1, (const char *)func_00246830(temp_s0 & 0xFFFF),
                      0, 0);

        i = 0;
        while (i < 0xA) {
            if (i >= *(s32 *)(arg2 + 8)) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            func_0025f3f0(color, 0xFF, 0x15, 0, (void *)asset, 1,
                          (f32)(i * 0x17 + 0x162), 381.0f, 0.0f);
            i++;
        }
        count = *(s16 *)(arg2 + 0x3E) + 1;
        *(s16 *)(arg2 + 0x3E) = (s16)count;
        if ((s16)count >= 0x2D) {
            *(s16 *)(arg2 + 0x3E) = 0;
        }
        temp_f0 = func_0044b7b0(D_007612CC +
                                (D_007612D0 * (f32)*(s16 *)(arg2 + 0x3E)) / 45.0f);
        temp_f1 = (D_0076118C + D_00761288 * ((temp_f0 + 1.0f) / 2.0f));
        temp_f1 = 255.0f * temp_f1 *
                  (1.0f - (f32)temp_17 / 5.0f);
        if (!(temp_f1 >= 2147483648.0f)) {
            count = (s32)temp_f1 & 0xFF;
        } else {
            count = ((s32)(temp_f1 - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0025f3f0(color, count, 0x1C, 0, (void *)asset, 1,
                      (f32)((*(s32 *)(arg2 + 8) - 1) * 0x17 + 0x15D),
                      376.0f, 0.0f);
    } else if (temp_17 < 0x15) {
        temp_f20 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 5)) / 15.0f);
        src = D_00635CC0;
        dst = sp.sp90;
        n = 4;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);
        i = 0;
        while (i < 4) {
            ((f32 *)sp.sp90)[i * 2] += 218.0f + 500.0f * temp_f20;
            ((f32 *)sp.sp90)[i * 2 + 1] += 406.0f;
            p = sp.sp80 + i * 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0x99;
            i++;
        }
        func_0045dfd0(sp.sp80, sp.sp90, 4.0f, 4, 1, 0);
        temp_s0 = *(s32 *)(arg2 + 4);
        asset = *(s32 *)(arg2 + 0x10);
        font = (s32)func_0046a770((char *)D_00635CE0);
        if (font == 0) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        temp_f0 = func_0046b1f0(
            (void *)font,
            (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20);
        temp_s0 = (s32)(500.0f * temp_f20);
        temp_f21 = (f32)(temp_s0 + 299 - ((s32)temp_f0 >> 1));
        func_0025e9e0(0xFFFFFF, 0xFF,
                      (s32)(((u8 *)func_002467b0((*(s32 *)(arg2 + 4)) & 0xFFFF))[8]) + 0x20,
                      (void *)font, 1, temp_f21, 407.0f, 0.0f);
        func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (void *)asset, 1,
                      (f32)(temp_s0 + 355), 411.0f, 0.0f);
        func_00274ed0((f32)(temp_s0 + 392), 403.0f, 0.0f,
                      -1, 0, 1, (const char *)func_00246830((*(s32 *)(arg2 + 4)) & 0xFFFF),
                      0, 0);

        i = 0;
        while (i < 0xA) {
            if (i >= *(s32 *)(arg2 + 8)) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            func_0025f3f0(color, 0xFF, 0x15, 0, (void *)asset, 1,
                          (f32)(i * 0x17 + 0x162) + temp_f20,
                          381.0f, 0.0f);
            i++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00254a70);
#endif

// FUN_00255B00
s32 func_00255b00(s32 arg0, s32 *arg1) {
    s32 v;
    s32 rv;

    rv = 0;
    if (arg1[1] < 0x3C || !(arg1[0] & 2)) {
        arg1[1]++;
    }
    v = arg1[1];
    if (v >= 0x78) {
        rv = 1;
    }
    if (v < 0x3D) {
        func_00253850();
    } else {
        func_00254a70();
    }
    return rv;
}



// FUN_00255B90
u8 *func_00255b90(void) {
    u8 *entry;
    s32 count;
    u8 *cnt;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node4;

    count = 0;
    cnt = func_001452b0(1);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(2);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(3);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(0xA);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    func_0044ea90(D_00635CF8, 0x5FA);
    entry = (u8 *)D_008873F4[0](1, (count + 1) * 0x10, 0x40000);
    count = 0;
    node1 = func_001452b0(1);
    while (node1 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node1 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node1);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node1 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node1;
        count++;
        func_0047a0e0(*(u8 **)(node1 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node1 = *(u8 **)(node1 + 0x138);
    }
    node2 = func_001452b0(2);
    while (node2 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node2 + 0x158);
        *(s32 *)(e + 0xC) = func_00268cb0(node2);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node2 + 0x158) + 0xF4);
        *(u8 **)(e + 8) = node2;
        count++;
        func_0047a0e0(*(u8 **)(node2 + 0x158), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node2 = *(u8 **)(node2 + 0x138);
    }
    node3 = func_001452b0(3);
    while (node3 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node3 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node3);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node3 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node3;
        count++;
        func_0047a0e0(*(u8 **)(node3 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node3 + 0), 1);
        node3 = *(u8 **)(node3 + 0x138);
    }
    node4 = func_001452b0(0xA);
    while (node4 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node4 + 0x144);
        *(s32 *)(e + 0xC) = func_00268cb0(node4);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node4 + 0x144) + 0xF4);
        *(u8 **)(e + 8) = node4;
        count++;
        func_0047a0e0(*(u8 **)(node4 + 0x144), 0, 0.0f);
        func_00268c20(*(u16 *)(node4 + 0), 1);
        node4 = *(u8 **)(node4 + 0x138);
    }
    return entry;
}



// FUN_00255ED0
s32 func_00255ed0(s64 arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)func_002467b0((u16)arg0) + 4) & 0x10) != 0 &&
        (arg0 != 0x18 || func_00106330(0x38) != 0)) {
        if ((s16)func_00248d80(arg0) == 3 ||
            (s16)func_00248d80(arg0) == 4) {
            if (arg1 == 3) {
                return 7;
            }
            if (arg1 == 6) {
                return 8;
            }
            if (arg1 == 10) {
                return 9;
            }
        } else {
            if (arg1 == 3) {
                return 2;
            }
            if (arg1 == 7) {
                return 3;
            }
            if (arg1 == 5) {
                return 4;
            }
            if (arg1 == 9) {
                return 5;
            }
            if (arg1 == 1) {
                return 6;
            }
        }
    }
    return 0;
}



// FUN_00256040
void func_00256040(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                   s32 arg7) {
    u8 *spAC;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;

    func_00279d40(arg5);
    spAC = func_00279030(fparg0, fparg1, fparg2, (arg0 << 8) | arg1, arg2,
                         arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        var_18 = func_002736d0(&spAC, arg7);
        if (var_18 == NULL) {
            var_18 = spAC;
            spAC = NULL;
        }
        var_17 = var_18;
        var_16 = 0;
        while (var_17 != NULL) {
            var_16 += func_002738d0(var_17);
            var_17 = *(u8 **)(var_17 + 0x24);
        }
        func_00272a10(var_18, fparg0 - ((f32)var_16 / 2.0f), fparg1);
        func_00272ba0(var_18, arg1 | ~0xFF);
        func_00273170(var_18, 1, 0);
        func_00271b70(var_18);
        if (spAC != NULL) {
            func_00271b70(spAC);
        }
    }
}



/* measured: retail frame is -0x140 with ra and $s0-$s5 saved; the two
   arrays are rgba at sp+0x70 and pairs at sp+0xc0, with an unexplained
   sixteen-byte slot at sp+0xb0.  The best complete reconstruction is
   archived in build/WB561_work_gap_pairwalk.json:
   `struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work`.
   This one aggregate reproduces the frame, saved-register set, and both
   array offsets; its object is 628 bytes against the 624-byte window
   (nd 484).  Its first fndiff row is offset 0x20: the persistent rgba
   base emits `addiu $t7,$sp,0x70` where retail starts the global read.
   Direct indexed variants scalarize the aggregate (frames -0x120/-0x130,
   objects 608-620), while the persistent base pins the gap at the cost
   of that one surplus instruction.  Explicit qword/union/alignment
   variants, separate locals, and branch-local pointer variants were
   ruled out.  General finding: an unexplained retail stack gap is a real
   declared object; declaring the complete frame as one struct in source
   declaration order reproduces offsets that separate locals do not. */
/* measured: W3CRNK_002561f0_body.c fresh 150wd (obj608B/window624B) vs aggregate 628B/nd484 per owner note; head-start recipe (16x8B down-count loop, colours with trailing andi, 255 round-trip unfolded, sltiu i-14<2/i-6<4/i-10<4 else to sp+0x70+i*4, 0045e6a0(sp+0x70,sp+0xC0,16,4,...)) tried via this body; inclusive-bound/dead-arm/cast/loop-invariant/s64 levers checked (no convertible slt $at range guard; call-setup casts per EABI t0-t3 kept). Honest table/CSE/stack-gap floor; banked. No volatile/asm. */
/* measured 002561f0: `schedule on` inside the guard is worth 2 words (150 -> 148). */
/* measured 002561f0 2026-09-19: remove unscheduled-retail `schedule on` guard (was 140 vs 152, -7.9%); unscheduled object 152 vs 152 (exact, inside 147-157), edits 160 -> 154. */
/* measured 002561f0 (owner, this session): three honest source corrections, edits 154 -> 148,
   words 150 unchanged, count still exact at 152/152.
   (a) `packed`/`packed2`/`packed3`/`packed4` are u32, not s32 - retail extracts the bytes with
       `srl` (R36/R38/R40/R42), the s32 spelling emitted `sra`.
   (b) the packed3/packed4 component masks are gone: retail masks only the `packed` and
       `packed2` sets (`andi` at R22/R24/R26/R27 and R41/R43/R45/R46) because b1 is passed to
       func_0045e6a0, and leaves the other two unmasked (R53-R55, R61-R63) since `sb` truncates.
   (c) the `one = 1` dummy local is deleted - `i == 1` measures identically (154 both ways), and
       retail's `addiu $s0, $zero, 1` at R47 is the allocator hoisting the constant by itself.
   Remaining wall is register pressure, not structure: retail saves $s0-$s5 (frame 0x140, ra at
   0x60), the object saves $s0-$s3 (frame 0x120, ra at 0x40).  Retail keeps the `packed` set in
   temps ($t4/$t3/$v1/$v0), the `packed2` set in $s4-$s1, the constant 1 in $s0 and the per-
   iteration element pointer in $s5; the object has two fewer saved registers to spend.  Swapping
   the packed3/packed4 statement order to match retail's R48-R63 emission order was measured and
   is worse (155), so the source order is already right and the scheduler is reordering. */
// FUN_002561F0 NONMATCHING
#ifdef NON_MATCHING
void func_002561f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s64 arg5, s64 arg6, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    typedef struct { u8 r; u8 g; u8 b; u8 a; } RGBA;
    typedef union { struct { f32 x; f32 y; } f; struct { u32 w0; u32 w1; } w; s64 align; } Pair;
    typedef struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work;
    Work work;
    Pair *pairp; u8 *p; u8 *base; s32 i; s32 count; u32 w0; u32 w1; Pair *src; Pair *dst;
    u32 packed; u32 packed2; u32 packed3; u32 packed4; f32 value2; f32 value3;
    s32 b0; s32 b1; s32 b2; s32 b3; s32 c0; s32 c1; s32 c2; s32 c3;
    s32 d0; s32 d1; s32 d2; s32 d3; s32 e0; s32 e1; s32 e2; s32 e3;
    src = (Pair *)D_00636310; dst = work.pairs; count = 16; do { w0 = src->w.w0; w1 = src->w.w1; src++; count--; dst->w.w0 = w0; dst->w.w1 = w1; dst++; } while (count > 0);
    i = 0; packed = arg0 << 8; b0 = (packed >> 24) & 0xFF; b1 = (packed >> 16) & 0xFF; b2 = arg0 & 0xFF; b3 = packed & 0xFF;
    value2 = ((f32)arg2 * 255.0f) / 255.0f; value3 = ((f32)arg3 * 255.0f) / 255.0f; packed2 = packed | arg1; c0 = (packed2 >> 24) & 0xFF; c1 = (packed2 >> 16) & 0xFF; c2 = (packed2 >> 8) & 0xFF; c3 = packed2 & 0xFF; packed4 = packed | (s32)value2; e0 = (packed4 >> 24); e1 = (packed4 >> 16); e2 = (packed4 >> 8); e3 = packed4; packed3 = packed | (s32)value3; d0 = (packed3 >> 24); d1 = (packed3 >> 16); d2 = (packed3 >> 8); d3 = packed3;
    while (i < 16) {
      work.pairs[i].f.x += fparg0; work.pairs[i].f.y += fparg1;
      if (i == 0 || i == 1 || (u32)(i - 0xE) < 2U) { work.rgba[i].r = b0; work.rgba[i].g = b1; work.rgba[i].b = b2; work.rgba[i].a = b3; }
      else if ((u32)(i - 6) < 4U) { work.rgba[i].r = e0; work.rgba[i].g = e1; work.rgba[i].b = e2; work.rgba[i].a = e3; }
      else if ((u32)(i - 0xA) < 4U) { work.rgba[i].r = d0; work.rgba[i].g = d1; work.rgba[i].b = d2; work.rgba[i].a = d3; }
      else { work.rgba[i].r = c0; work.rgba[i].g = c1; work.rgba[i].b = c2; work.rgba[i].a = c3; }
      i++;
    }
    base = (u8 *)work.rgba;
    func_0045e6a0(base, work.pairs, fparg2, 0x10, 4, (s32)(s16)arg5, (s32)(s16)arg6, b1, 0, fparg3, fparg4);
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002561f0);
#endif
/* Floor: 48 differing words over 57 edit instructions, 153 emitted against
   retail's 153, from a first reconstruction.  The signature is 7 ints and 5
   floats: the MIPS EABI passes integer arguments 5-8 in $t0-$t3, which is
   where arg4..arg6 live, and arg4 is forwarded to func_0045e6a0 untouched -
   retail never reloads it.  The vertex table is copied with an explicit
   two-word CopyPair loop; letting MWCC copy the 8-byte struct directly
   emits lwc1/swc1 where retail uses lw/sw.  The colour buffer is
   `u8 color[20][4]`, which is what puts the position array at 0xC0 and
   makes the frame 0x140.  Hoisting the four base-colour bytes above the
   loop took 66 words to 48.
   WALL: FPU scheduling.  Retail issues both `255.0f * (f32)argN` products
   before the main colour and only then the two divisions; this build sinks
   each product onto its own division, so the two chains are emitted whole
   one after the other.  opt_propagation off (158), opt_serializeassignments
   and folding the divide into the product were all measured. */
// FUN_00256460 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_00256460(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4)
{
    f32 pos[16][2];
    u8 color[20][4];
    CopyPair *src;
    CopyPair *dst;
    u32 w0;
    u32 w1;
    u32 rgb;
    u32 main;
    u32 lower;
    u32 upper;
    s32 n;
    u32 i;
    f32 scaled2;
    f32 scaled3;
    s32 b0;
    s32 b1;
    s32 b2;
    s32 b3;

    src = (CopyPair *)D_00636390;
    dst = (CopyPair *)pos;
    n = 0x10;
    do {
        w0 = src->w0;
        w1 = src->w1;
        src++;
        n--;
        dst->w0 = w0;
        dst->w1 = w1;
        dst++;
    } while (n > 0);
    i = 0;
    rgb = arg0 << 8;
    b0 = (rgb >> 0x18) & 0xFF;
    b1 = (rgb >> 0x10) & 0xFF;
    b2 = arg0 & 0xFF;
    b3 = rgb & 0xFF;
    scaled2 = 255.0f * (f32)arg2;
    scaled3 = 255.0f * (f32)arg3;
    main = rgb | arg1;
    lower = rgb | (s32)(scaled3 / 255.0f);
    upper = rgb | (s32)(scaled2 / 255.0f);
    while (i < 0x10U) {
        pos[i][0] = pos[i][0] + fparg0;
        pos[i][1] = pos[i][1] + fparg1;
        if (i == 0 || i == 1 || (u32)(i - 0xE) < 2U) {
            color[i][0] = (u8)b0;
            color[i][1] = (u8)b1;
            color[i][2] = (u8)b2;
            color[i][3] = (u8)b3;
        } else if ((u32)(i - 6) < 4U) {
            color[i][0] = (u8)(upper >> 0x18);
            color[i][1] = (u8)(upper >> 0x10);
            color[i][2] = (u8)(upper >> 8);
            color[i][3] = (u8)upper;
        } else if ((u32)(i - 0xA) < 4U) {
            color[i][0] = (u8)(lower >> 0x18);
            color[i][1] = (u8)(lower >> 0x10);
            color[i][2] = (u8)(lower >> 8);
            color[i][3] = (u8)lower;
        } else {
            color[i][0] = (u8)((main >> 0x18) & 0xFF);
            color[i][1] = (u8)((main >> 0x10) & 0xFF);
            color[i][2] = (u8)((main >> 8) & 0xFF);
            color[i][3] = (u8)(main & 0xFF);
        }
        i++;
    }
    func_0045e6a0(color, pos, fparg2, 0x10, 4, arg4, (s16)arg5, (s16)arg6,
                  0.0f, fparg3, fparg4);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256460);
#endif



/* measured: nd 303 after four attempts; frame 0x150, prologue, both copy
   loops, func_00252230/003e0870 call shapes and the func_00366c70 arg layout
   (incl. s16 arg7 in $11, s16 stack args, msub.s alpha args) all match.
   Residual: (1) FP saved-reg rotation - retail keeps fparg4/temp_f21/temp_f20
   in $f22/$f21/$f20, mwcc allocates $f21/$f20/$f22 regardless of declaration
   order (tried both orders); (2) the D_00887300 vtable base must be assigned
   to a local JUST BEFORE its calls (retail lui/addiu into $s2 there); assigned
   early mwcc hoists it to the top in $s1 and the whole mid-function shifts.
   Tried: 6- and 9-param signatures (positional float regs confirmed: 3 unused
   leading f32s needed to place fparg3/fparg4 at $f15/$f16), (s16)/(s64) arg
   spellings, named vt local. FP-allocation floor + vtable-hoist placement. */
/* object 1264B, window 1296B, normalized_diff 735 (verify); abandoned alpha/register probe */
// FUN_002566D0 NONMATCHING
#ifdef NON_MATCHING
void func_002566d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4) {
    Sp120 sp120;
    u8 spD0[0x48];
    u8 spB0[0x20];
    u8 sp70[0x40];
    u8 *src;
    u8 *dst;
    s32 count;
    s32 temp_3;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f0;
    s32 temp_2;
    u32 alpha_u;
    s32 call_x;
    s32 call_y;
    s16 call_w;
    s16 call_h;
    s32 call_alpha;
    void (*vt)(u32, u32);
    temp_f22 = fparg4;
    src = D_00636410;
    dst = spD0;
    count = 9;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    src = D_00636460;
    dst = spB0;
    count = 4;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    temp_f21 = (f32)arg1 / 255.0f;
    temp_f20 = 0.25f * temp_f22;
    func_00252230(&sp120, (Sp120 *)spD0,
                  (Sp120 *)((u8 *)spD0 + 0x24), fparg3);
    func_003e0870(sp70, (u8 *)&sp120 + 0xC, sp120.f1C, 0);
    call_h = sp120.f22;
    call_w = sp120.f20;
    call_alpha = sp120.f18;
    call_x = (s32)sp120.f4;
    call_y = (s32)sp120.f8;
    alpha_u = call_alpha;
    temp_2 = alpha_u & 0xFF;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = (f32)(s32)(((u32)temp_2 >> 1) | ((u32)temp_2 & 1));
        var_f0 += var_f0;
    }
    func_00366c70(call_x, call_y,
                  call_w, call_h, call_alpha >> 8,
                  (s32)(var_f0 * temp_f21), 3,
                  (s16)(call_w >> 1), 0.0f,
                  (s16)(call_h >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70((s32)sp120.f4, (s32)sp120.f8,
                  sp120.f20, sp120.f22, sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f21), 5,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
    vt = D_00887300[0];
    vt(6, 0);
    vt(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x48);
    temp_f21_2 = 1.0f + temp_f20;
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 2,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 4,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002566d0);
#endif

/* measured: nd 303 after four attempts; twin of func_002566d0 (same walls):
   frame 0x150, prologue, copy loops and all call shapes match, but (1) FP
   saved-reg rotation (fparg4/temp_f21/temp_f20 in $f22/$f21/$f20 retail vs
   $f21/$f20/$f22 mwcc, both declaration orders tried), (2) GPR rotation: mwcc
   saves the D_00887300 vt base in $s1 with arg2 in $s2 while retail uses $18
   for vt and $s1/$s0 for arg2's halves (vt declared first/last both tried),
   (3) the vt base must be assigned early to force a saved reg at all (late
   assignment makes mwcc rematerialize lui/lw per call and the frame shrinks
   to 0x140). Saved-register rotation + D_00887300 vtable-hoist floors; alpha
   sites need the (u32) cast like func_002570f0. */
/* measured: ported twin 002566d0 floor with D_00636480/D_006364D0 tables, D_0076122C global, 0.5x position factor (0.125 vs 0.25), 271 differing words; twin walls (FP/GPR rotation, vt hoist, (u32) alpha); production stays ASM. */
// FUN_00256BE0 NONMATCHING
#ifdef NON_MATCHING
void func_00256be0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4) {
    Sp120 sp120;
    u8 spD0[0x48];
    u8 spB0[0x20];
    u8 sp70[0x40];
    u8 *src;
    u8 *dst;
    s32 count;
    s32 temp_3;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f0;
    s32 temp_2;
    u32 alpha_u;
    s32 call_x;
    s32 call_y;
    s16 call_w;
    s16 call_h;
    s32 call_alpha;
    void (*vt)(u32, u32);
    temp_f22 = fparg4;
    src = D_00636480;
    dst = spD0;
    count = 9;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    src = D_006364D0;
    dst = spB0;
    count = 4;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    temp_f21 = (f32)arg1 / 255.0f;
    temp_f20 = 0.25f * temp_f22;
    temp_f20_2 = 0.5f * temp_f20;
    temp_f22 = D_0076122C * (1.0f - temp_f22) * temp_f21;
    temp_f21_2 = 1.0f + temp_f20;
    func_00252230(&sp120, (Sp120 *)spD0,
                  (Sp120 *)((u8 *)spD0 + 0x24), fparg3);
    func_003e0870(sp70, (u8 *)&sp120 + 0xC, sp120.f1C, 0);
    call_h = sp120.f22;
    call_w = sp120.f20;
    call_alpha = sp120.f18;
    call_x = (s32)sp120.f4;
    call_y = (s32)sp120.f8;
    alpha_u = call_alpha;
    temp_2 = alpha_u & 0xFF;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = (f32)(s32)(((u32)temp_2 >> 1) | ((u32)temp_2 & 1));
        var_f0 += var_f0;
    }
    func_00366c70(call_x, call_y,
                  call_w, call_h, call_alpha >> 8,
                  (s32)(var_f0 * temp_f21), 3,
                  (s16)(call_w >> 1), 0.0f,
                  (s16)(call_h >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70((s32)sp120.f4, (s32)sp120.f8,
                  sp120.f20, sp120.f22, sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f21), 5,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
    vt = D_00887300[0];
    vt(6, 0);
    vt(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x48);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20_2),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20_2),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 2,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20_2),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20_2),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 4,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
}

#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256be0);
#endif

/* measured: nd 189 after four attempts; frame 0x1C0, all stack offsets, both
   copy loops, all zero-fill loops, the struct stores/copies (lq/sq), and the
   func_00252230/003e0870/0045d6e0/0048a000/0045db40 call shapes match. Two
   unreachable residuals: (1) the D_00887300 render-vtable hoist floor - retail
   keeps the base in $s0 and does lw 0($s0)/jalr per call; mwcc b210 emits a
   dead lui/addiu $s0 and rematerializes lui+lw per call (7 calls per half).
   (2) alpha sites: `x & 0xFF >= 0` on an s32 is provably true so mwcc drops
   the branch - the (u32) cast (`(u32)x & 0xFF`) defeats the prover and emits
   the retail andi/bltz exactly (verified on b210 after this was written).
   Also: s16 arg7/stack s16s, s64 vs s32 arg_sp10 (s64 shifts every stack arg
   and is worse). */
/* measured (2026-09-18): probe_variants 431 differing words reloc-masked via `python3 tools/probe_variants.py src/cmmRankUp.c func_002570f0 --candidate FIX14=/tmp/cand570_fix14.c`; fnalign retail 460 vs object 472 instrs (263 edits) via `python3 tools/fnalign.py src/cmmRankUp.c func_002570f0 --candidate /tmp/cand570_fix14.c --quiet`; +12 over (2.6% within 3% rule). Signature s32 x3 + f32 x4 (s64->s32 saves 4 per opclass width wall; true s64 per prior note shifts stack and is worse); neg lever temp_f20=-temp_f21 saves 2 vs -80*mul; (u32) alpha + s16 narrowing per prior nd189 walls; copy/zero/0045d6e0/0045db40/00366c70 shapes per prior note. Wall remains vt-hoist + FPU/scheduling + frame 0x180 vs 0x1C0 (64 short, top-relative match). No volatile/asm. */
// FUN_002570F0 NONMATCHING
#ifdef NON_MATCHING

void func_002570f0(s32 arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    s8 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    Sp120 sp180;
    Sp120 sp154;
    Sp120 sp130;
    u8 sp110[32];
    u8 spD0[64];
    u_long128 spC0;                                      /* compiler-managed */
    u_long128 spB0;
    u_long128 spA0;
    u_long128 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    u_long128 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    u8 *var_6_2;
    u8 *var_6;
    f32 *var_3_2;
    f32 *var_3_4;
    f32 temp_2;
    f32 temp_3;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f0;
    f32 var_f0_2;
    s32 *var_3_3;
    s32 *var_3_5;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3_2;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_4;
    s32 var_4_2;
    s8 *var_3;
    u8 *var_7;
    u8 *var_7_2;

    var_7 = D_006364F0;
    var_6 = (u8 *)&sp130;
    var_4 = 9;
    do {
        temp_3 = *(f32 *)var_7;
        temp_2 = *(f32 *)(var_7 + 4);
        var_7 += 8;
        var_4 -= 1;
        *(f32 *)var_6 = temp_3;
        *(f32 *)(var_6 + 4) = temp_2;
        var_6 += 8;
    } while (var_4 > 0);
    var_7_2 = D_00636540;
    var_6_2 = sp110;
    var_4_2 = 4;
    do {
        temp_3_2 = *(s32 *)var_7_2;
        temp_2_2 = *(s32 *)(var_7_2 + 4);
        var_7_2 += 8;
        var_4_2 -= 1;
        *(s32 *)var_6_2 = temp_3_2;
        *(s32 *)(var_6_2 + 4) = temp_2_2;
        var_6_2 += 8;
    } while (var_4_2 > 0);
    var_3 = &sp1BC;
    var_2 = 4;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    temp_f22 = (f32) arg1 / 255.0f;
    func_00252230(&sp180, &sp130, &sp154, 0.0f);
    func_003e0870(&spD0, &sp180.fC, sp180.f1C, 0);
    temp_f21 = 80.0f * fparg3;
    temp_f20 = -temp_f21;
    var_3_2 = &sp1B4;
    var_2_2 = 4;
    if (var_3_2 != NULL) {
        do {
            *var_3_2 = 0;
            var_3_2 += 1;
            var_2_2 -= 1;
        } while (var_2_2 != 0);
    }
    sp1B8 = sp1B4;
    var_3_3 = &sp80;
    var_2_3 = 0x10;
    if (var_3_3 != NULL) {
        do {
            *var_3_3 = 0;
            var_3_3 += 1;
            var_2_3 -= 1;
        } while (var_2_3 != 0);
    }
    sp80 = 0;
    sp84 = 0;
    sp88 = 0x280;
    sp8C = 0x1E0;
    sp90 = (u_long128) sp80;
    D_00887300[0](0xEU, 0U);
    D_00887300[0](0xCU, 1U);
    D_00887300[0](7U, 2U);
    D_00887300[0](9U, 1U);
    D_00887300[0](0x14U, 1U);
    D_00887300[0](6U, 0U);
    D_00887300[0](8U, 1U);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp1B8, &sp90, 10.0f, 0);
    func_0048a000();
    spB0 = D_00636560;
    spC0 = spB0;
    *(f32 *)&spC0 = *(f32 *)&spC0 + temp_f21;
    spC0 = (f32) spC0 + temp_f20;
    D_00887300[0](6U, 1U);
    D_00887300[0](8U, 1U);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_0045db40(&sp1BC, &spC0, 0, 0xC8, 0, 0.0f, 45.0f, 1.0f, 1.0f);
    temp_2_3 = (u32)sp180.f18 & 0xFF;
    if (temp_2_3 >= 0) {
        var_f0 = (f32) temp_2_3;
    } else {
        var_f0 = (f32)(((u32)temp_2_3 >> 1) | (temp_2_3 & 1)); var_f0 += var_f0;
    }
    func_00366c70((s32) (sp180.f4 + temp_f21), (s32) (sp180.f8 + temp_f20), (s32) sp180.f20, (s32) sp180.f22, (s32) ((u32) sp180.f18 >> 8), (s32) (var_f0 * temp_f22), 1, (s16)(sp180.f20 >> 1), 5.0f, (s16)(sp180.f22 >> 1), &spD0, arg2, &sp110);
    var_3_4 = &sp1AC;
    var_2_4 = 4;
    if (var_3_4 != NULL) {
        do {
            *var_3_4 = 0;
            var_3_4 += 1;
            var_2_4 -= 1;
        } while (var_2_4 != 0);
    }
    sp1B0 = sp1AC;
    var_3_5 = &sp60;
    var_2_5 = 0x10;
    if (var_3_5 != NULL) {
        do {
            *var_3_5 = 0;
            var_3_5 += 1;
            var_2_5 -= 1;
        } while (var_2_5 != 0);
    }
    sp60 = 0;
    sp64 = 0;
    sp68 = 0x280;
    sp6C = 0x1E0;
    sp70 = (u_long128) sp60;
    D_00887300[0](0xEU, 0U);
    D_00887300[0](0xCU, 1U);
    D_00887300[0](7U, 2U);
    D_00887300[0](9U, 1U);
    D_00887300[0](0x14U, 1U);
    D_00887300[0](6U, 0U);
    D_00887300[0](8U, 1U);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp1B0, &sp70, 10.0f, 0);
    func_0048a000();
    spA0 = D_00636570;
    spC0 = spA0;
    *(f32 *)&spC0 = *(f32 *)&spC0 - temp_f21;
    spC0 = (f32) spC0 + (-temp_f20 - 200.0f);
    D_00887300[0](6U, 1U);
    D_00887300[0](8U, 1U);
    func_003f6440(3, 0x71003);
    func_003f6440(2, 0x44);
    func_0045db40(&sp1BC, &spC0, 0, 0xC8, 0xC8, 0.0f, 45.0f, 1.0f, 1.0f);
    temp_2_4 = (u32)sp180.f18 & 0xFF;
    if (temp_2_4 >= 0) {
        var_f0_2 = (f32) temp_2_4;
    } else {
        var_f0_2 = (f32)(((u32)temp_2_4 >> 1) | (temp_2_4 & 1)); var_f0_2 += var_f0_2;
    }
    func_00366c70((s32) (sp180.f4 - temp_f21), (s32) (sp180.f8 - temp_f20), (s32) sp180.f20, (s32) sp180.f22, (s32) ((u32) sp180.f18 >> 8), (s32) (var_f0_2 * temp_f22), 1, (s16)(sp180.f20 >> 1), 5.0f, (s16)(sp180.f22 >> 1), &spD0, arg2, &sp110);
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002570f0);
#endif

// FUN_00257820
s32 func_00257820(s32 arg0, void *arg1) {
    s32 var_4;
    u8 *var_2;
    u16 var_17;

    var_17 = 0x400;
    var_2 = func_00145270(0x400);
    if (var_2 == NULL) {
        var_17 = ((arg0 & 0x3FF) | 0xC00) & 0xFFFF;
        var_2 = func_00145270(var_17);
    }
    if (var_2 != NULL) {
        var_4 = 0;
        switch ((s32)((var_17 & 0xFFC00) >> 0xA)) {
        case 1:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        case 3:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        }
        if (var_4 != 0) {
            func_0047a6d0(var_4, 2, arg1);
            return 1;
        }
    }
    return 0;
}



/* measured: not attempted this wave (14320 B, the file's biggest); m2c draft
   is complete apart from 6 M2C_ERRORs (VU0-free - check them against the
   retail asm before writing). It drives func_00256460/002566d0/00256be0/
   002570f0 and the func_0025f3f0 menu draws. Call-signature facts established
   this wave and needed here: func_002566d0 takes (s32 arg0, s32 arg1, s64
   arg2, s64 arg3, f32 fparg0..fparg4) with floats position-allocated from
   $f12 (3 unused leading floats place fparg3/fparg4 at $f15/$f16);
   func_002570f0 takes (s32, s32, s64, f32 x4); func_00366c70 is (s32 x7, s16,
   f32, s16, void*, s32, void*) with the s16s sign-extended via dsll32/dsra32;
   func_00256460 takes 8 ints + 5 floats (its 6th/7th params are passed to
   func_0045e6a0 with (s16) narrowing). Family walls (see the sibling notes):
   (u32)-cast alpha sites, vt-base rematerialization, stack-slot overlap. */
// FUN_00257900 NONMATCHING
#ifdef NON_MATCHING
s32 func_00257900(u8 *arg0) {

    u8 *ctx;
    s32 temp_18;
    s32 temp_17;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_8;
    s32 temp_3_9;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_12;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_19_3;
    s32 temp_19_4;
    s32 temp_19_5;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 temp_20_4;
    s32 temp_20_5;
    s32 temp_20_6;
    s32 temp_20_7;
    s32 temp_20_8;
    s32 temp_20_9;
    s32 temp_20_10;
    s32 temp_20_11;
    s32 temp_20_12;
    s32 temp_20_13;
    s32 temp_20_14;
    s32 temp_20_15;
    s32 temp_20_16;
    s32 temp_20_17;
    s32 temp_21;
    s32 temp_21_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_12;
    s32 temp_2_13;
    s32 temp_2_14;
    s32 temp_2_15;
    s32 temp_2_16;
    s32 temp_2_17;
    s32 temp_2_18;
    s32 temp_2_19;
    s32 temp_2_20;
    s32 temp_2_21;
    s32 temp_2_22;
    s32 temp_2_23;
    s32 temp_2_24;
    s32 temp_2_25;
    s32 temp_2_26;
    s32 temp_2_27;
    s32 temp_2_28;
    s32 temp_2_29;
    s32 temp_2_30;
    s32 temp_2_31;
    s32 temp_2_32;
    s32 temp_2_33;
    s32 temp_2_34;
    s32 temp_2_35;
    s32 temp_2_36;
    s32 temp_2_37;
    s32 temp_2_38;
    s32 temp_2_39;
    s32 temp_2_40;
    s32 temp_2_41;
    s32 temp_2_42;
    s32 temp_2_43;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    s32 var_4_4;
    s32 var_4_5;
    s32 var_4_6;
    u8 var_3;
    s8 var_3_2;
    u8 var_3_3;
    u8 var_3_4;
    u8 var_3_5;
    s8 var_3_6;
    u8 var_7;
    u8 *var_17;
    u8 *var_19;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f1_8;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;
    f32 var_f3;
    f32 var_f3_2;
    f32 var_f4;
    f32 var_f4_2;
    s32 sp174;
    s32 sp178;
    s32 sp188;
    s32 sp18C;
    s32 sp190;
    s32 sp192;
    s32 sp254;
    s32 sp258;
    s32 sp268;
    s32 sp26C;
    s32 sp270;
    s32 sp272;
    s32 sp334;
    s32 sp338;
    s32 sp348;
    s32 sp34C;
    s32 sp350;
    s32 sp352;
    u8 unksp3CB;
    u8 unksp3D7;
    s32 sp3DC;
    u8 sp3DB;
    f32 sp3D8;
    f32 sp3D4;
    f32 sp3D0;
    f32 sp3CC;
    f32 sp3C8;
    f32 sp3C4;
    f32 sp3C0;
    u8 sp3B0[0x140];
    u_long128 sp3A0;
    u_long128 sp390;
    u_long128 sp380;
    u_long128 sp370;
    u_long128 sp360;
    s32 sp33C;
    Sp120 sp330;
    s32 sp31C;
    Sp120 sp304;
    s32 sp2F8;
    u8 sp2E0[72];
    u8 sp2C0[32];
    u8 sp280[64];
    s32 sp25C;
    Sp120 sp250;
    s32 sp23C;
    Sp120 sp224;
    s32 sp218;
    u8 sp200[72];
    u8 sp1E0[32];
    u8 sp1A0[64];
    s32 sp17C;
    Sp120 sp170;
    s32 sp15C;
    Sp120 sp144;
    s32 sp138;
    u8 sp120[72];
    u8 sp100[32];
    u8 spC0[64];
    u_long128 spB0;
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    u8 *var_5;
    u8 *var_5_2;
    u8 *var_5_3;
    u8 *var_5_4;
    u8 *var_5_5;
    u8 *var_5_6;
    u8 *var_6;
    u8 *var_6_2;
    u8 *var_6_3;
    u8 *var_6_4;
    u8 *var_6_5;
    u8 *var_6_6;
    f32 *var_3_7;
    s32 *var_3_8;

    ctx = (u8 *)func_00452560(arg0);
    temp_18 = (s32)(func_0035afa0(*(s32 *)(ctx + 0x2C)));
    temp_17 = (s32)(func_0035afa0(*(s32 *)(ctx + 0x30)));
    temp_3 = (s32)(*(s32 *)(ctx + 0x1C));
    switch (temp_3) {                               /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        if (*(s32 *)(ctx + 8) >= 0x96) {
            temp_2_2 = (s32)(*(s32 *)(ctx + 0x48) + 1);
            *(s32 *)(ctx + 0x48) = temp_2_2;
            if (temp_2_2 >= 0x2D) {
                *(s32 *)(ctx + 0x48) = 0;
            }
        }
        temp_f20 = (f32) *(s32 *)(ctx + 0x48) / 45.0f;
        if (*(s32 *)(ctx + 8) == 0) {
            temp_20 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_20_2 = func_0025ff60(temp_20);
            func_004b12e0(temp_20_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_2, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0) {
            temp_20_3 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636650, &sp3DC), 0x64, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xB4, 300.0f);
            temp_20_4 = func_0025ff60(temp_20_3);
            func_004b12e0(temp_20_4, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_4, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0x78) {
            temp_20_5 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636670, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xB4, 300.0f);
            temp_20_6 = func_0025ff60(temp_20_5);
            func_004b12e0(temp_20_6, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_6, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0x23A) {
            temp_20_7 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_20_8 = func_0025ff60(temp_20_7);
            func_004b12e0(temp_20_8, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_8, sp3B0);
        }
        if ((*(s32 *)(ctx + 8) == 0x258) && (func_00257820(*(s32 *)(ctx + 0x20), sp3B0) != 0)) {
            temp_20_9 = (s32)(func_0025ff60(func_0025fe50(arg0, func_00455f70(&D_00636690, &sp3DC), 0x96, &D_005DC974)));
            func_004b12e0(temp_20_9, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_9, sp3B0);
        }
        if ((*(s32 *)(ctx + 8) == 0x280) && (func_00257820(*(s32 *)(ctx + 0x20), sp3B0) != 0)) {
            func_004b1250(func_0025ff60(func_0025fe50(arg0, func_00455f70(&D_006366B0, &sp3DC), 0x96, &D_005DC974)), sp3B0);
        }
        temp_3_2 = (s32)(*(s32 *)(ctx + 8));
        if (temp_3_2 >= 0xA) {
            if (temp_3_2 < 0x50) {
                func_002566d0(0xFFFFFF, (s32)( (255.0f * ((f32) (temp_3_2 - 0xA) / 70.0f))), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            } else if (temp_3_2 < 0x65) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            } else if (temp_3_2 < 0x79) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 1.0f - ((f32) (temp_3_2 - 0x64) / 20.0f), 0.0f);
            } else if (temp_3_2 < 0x97) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            } else if (temp_3_2 < 0xBF) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20);
            } else if (temp_3_2 < 0x1EB) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20);
                temp_17_2 = (s32)(*(s32 *)(ctx + 8) - 0xBE);
                func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
                temp_2_3 = (s32)(*(s32 *)(ctx + 0xC));
                if (temp_2_3 > 0) {
                    *(s32 *)(ctx + 0xC) = (s32) (temp_2_3 + 1);
                }
                temp_2_4 = (s32)(*(s32 *)(ctx + 0x10));
                if (temp_2_4 > 0) {
                    *(s32 *)(ctx + 0x10) = (s32) (temp_2_4 + 1);
                }
                temp_2_5 = (s32)(*(s32 *)(ctx + 0x14));
                if (temp_2_5 > 0) {
                    *(s32 *)(ctx + 0x14) = (s32) (temp_2_5 + 1);
                }
                if (*(u32 *)(ctx + 0) & 0x10) {
                    temp_2_6 = (s32)(*(s32 *)(ctx + 0xC));
                    if (temp_2_6 == 0) {
                        *(s32 *)(ctx + 0xC) = (s32) (temp_2_6 + 1);
                    }
                    temp_2_7 = (s32)(*(s32 *)(ctx + 0x10));
                    if (temp_2_7 == 0) {
                        *(s32 *)(ctx + 0x10) = (s32) (temp_2_7 + 1);
                    }
                    temp_2_8 = (s32)(*(s32 *)(ctx + 0x14));
                    if (temp_2_8 == 0) {
                        *(s32 *)(ctx + 0x14) = (s32) (temp_2_8 + 1);
                    }
                } else {
                    switch (temp_17_2) {            /* switch 2; irregular */
                    case 0x1:                       /* switch 2 */
                        *(s32 *)(ctx + 0xC) = (s32) (*(s32 *)(ctx + 0xC) + 1);
                        break;
                    case 0x5A:                      /* switch 2 */
                        *(s32 *)(ctx + 0x10) = (s32) (*(s32 *)(ctx + 0x10) + 1);
                        break;
                    case 0xB4:                      /* switch 2 */
                        *(s32 *)(ctx + 0x14) = (s32) (*(s32 *)(ctx + 0x14) + 1);
                        break;
                    }
                }
                var_f2 = 0.0f;
                var_f4 = 0.0f;
                var_f3 = 0.0f;
                temp_2_9 = (s32)(*(s32 *)(ctx + 0xC));
                if (temp_2_9 > 0) {
                    var_f2 = (f32) temp_2_9 / 30.0f;
                    if (!(var_f2 < 1.0f)) {
                        var_f2 = 1.0f;
                    }
                }
                temp_2_10 = (s32)(*(s32 *)(ctx + 0x10));
                if (temp_2_10 > 0) {
                    var_f4 = (f32) temp_2_10 / 30.0f;
                    if (!(var_f4 < 1.0f)) {
                        var_f4 = 1.0f;
                    }
                }
                temp_2_11 = (s32)(*(s32 *)(ctx + 0x14));
                if (temp_2_11 > 0) {
                    var_f3 = (f32) temp_2_11 / 30.0f;
                    if (!(var_f3 < 1.0f)) {
                        var_f3 = 1.0f;
                    }
                }
                if (!(var_f2 <= 0.0f)) {
                    func_002561f0(0, (s32)( (153.0f * var_f2)), (s32)( (153.0f * var_f4)), (s32)( (153.0f * var_f3)), 1, 0, 0.0f, 0.0f, 40.0f, 0.0f, 1.0f);
                }
                temp_2_12 = (s32)(*(s32 *)(ctx + 0xC));
                if (temp_2_12 > 0) {
                    var_f1 = (f32) temp_2_12 / 30.0f;
                    if (!(var_f1 < 1.0f)) {
                        var_f1 = 1.0f;
                    }
                    temp_f0 = 255.0f * var_f1;
                    func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 0);
                    func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 1);
                }
                temp_2_13 = (s32)(*(s32 *)(ctx + 0x10));
                if (temp_2_13 > 0) {
                    var_f1_2 = (f32) temp_2_13 / 30.0f;
                    if (!(var_f1_2 < 1.0f)) {
                        var_f1_2 = 1.0f;
                    }
                    temp_f0_2 = 255.0f * var_f1_2;
                    func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 2);
                    func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 3);
                    func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_2), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 4);
                }
                temp_2_14 = (s32)(*(s32 *)(ctx + 0x14));
                if (temp_2_14 > 0) {
                    var_f1_3 = (f32) temp_2_14 / 30.0f;
                    if (!(var_f1_3 < 1.0f)) {
                        var_f1_3 = 1.0f;
                    }
                    temp_f0_3 = 255.0f * var_f1_3;
                    func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_3), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 5);
                    func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_3), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 6);
                }
                if ((D_008C024E[0] & 0x40) && (*(s32 *)(ctx + 8) < 0x1CC)) {
                    *(s32 *)(ctx + 8) = 0x1CC;
                    *(u32 *)(ctx + 0) |= 0x10;
                }
            } else if (temp_3_2 < 0x213) {
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20);
                func_002561f0(0, 0x99, 0x99, 0x99, 1, 0, 0.0f, 0.0f, 40.0f, 0.0f, 1.0f);
                func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 2);
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 5);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 6);
            } else if (temp_3_2 < 0x227) {
                temp_f21 = 1.0f - ((f32) (temp_3_2 - 0x212) / 20.0f);
                func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20);
                temp_f0_4 = 153.0f * temp_f21;
                func_002561f0(0, (s32)( temp_f0_4), (s32)( temp_f0_4), (s32)( temp_f0_4), 1, 0, 0.0f, 0.0f, 40.0f, 0.0f, 1.0f);
                func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
                temp_f0_5 = 255.0f * temp_f21;
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 2);
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 5);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_5), 0, 0, 0, *(s8 *)(ctx + 0x3C), 0, 6);
            } else if (temp_3_2 < 0x24F) {
                temp_19 = temp_3_2 - 0x226;
                if (temp_19 == 1) {
                    temp_3_3 = (s32)(*(s32 *)(ctx + 0x1C));
                    if ((temp_3_3 == 0xA) || (temp_3_3 == 0)) {
                        func_0045aeb0(2, &D_00635C80);
                    } else {
                        func_0045aeb0(2, &D_00635CA0);
                    }
                }
                func_002566d0(0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) temp_19 / 40.0f)))), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20);
            }
        }
        temp_2_15 = (s32)(*(s32 *)(ctx + 8) + 1);
        *(s32 *)(ctx + 8) = temp_2_15;
        if (temp_2_15 >= 0x2BC) {
            *(s32 *)(ctx + 0x44) = 1;
        }
        break;
    case 10:                                        /* switch 1 */
        if (*(s32 *)(ctx + 8) >= 0x6E) {
            temp_2_16 = (s32)(*(s32 *)(ctx + 0x48) + 1);
            *(s32 *)(ctx + 0x48) = temp_2_16;
            if (temp_2_16 >= 0x2D) {
                *(s32 *)(ctx + 0x48) = 0;
            }
        }
        temp_f20_2 = (f32) *(s32 *)(ctx + 0x48) / 45.0f;
        if (*(s32 *)(ctx + 8) == 0) {
            temp_20_10 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_20_11 = func_0025ff60(temp_20_10);
            func_004b12e0(temp_20_11, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_11, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0xA) {
            func_0045aeb0(2, &D_006366D0);
        }
        temp_3_4 = (s32)(*(s32 *)(ctx + 8));
        if (((temp_3_4 % 10) == 0) && (temp_3_4 < 0x1CD)) {
            temp_20_12 = (s32)(func_0025fe50(arg0, func_00455f70(&D_006366F0, &sp3DC), 0x32, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_20_13 = func_0025ff60(temp_20_12);
            func_004b12e0(temp_20_13, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_13, sp3B0);
            func_004b14f0(temp_20_13, (f32 *) &sp3D8);
            if ((s32) sp3DB >= 0) {
                var_f1_4 = (f32) sp3DB;
            } else {
                var_f1_4 = 2.0f * (f32) ((sp3DB >> 1) | (sp3DB & 1));
            }
            temp_f1 = var_f1_4 * 0.5f;
            if (!(temp_f1 >= 2.1474836e9f)) {
                var_3 = 0x4F000000 & 0xFF;
            } else {
                var_3 = ((s32)( (temp_f1 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            sp3DB = var_3;
            func_004b13f0(temp_20_13, (f32 *) &sp3D8);
        }
        if (*(s32 *)(ctx + 8) == 0x21C) {
            temp_20_14 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_20_15 = func_0025ff60(temp_20_14);
            func_004b12e0(temp_20_15, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_15, sp3B0);
        }
        if ((*(s32 *)(ctx + 8) == 0x23A) && (func_00257820(*(s32 *)(ctx + 0x20), sp3B0) != 0)) {
            temp_20_16 = (s32)(func_0025ff60(func_0025fe50(arg0, func_00455f70(&D_00636690, &sp3DC), 0x96, &D_005DC974)));
            func_004b12e0(temp_20_16, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_20_16, sp3B0);
        }
        if ((*(s32 *)(ctx + 8) == 0x262) && (func_00257820(*(s32 *)(ctx + 0x20), sp3B0) != 0)) {
            temp_19_2 = (s32)(func_0025ff60(func_0025fe50(arg0, func_00455f70(&D_006366B0, &sp3DC), 0x96, &D_005DC974)));
            func_004b12e0(temp_19_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_19_2, sp3B0);
        }
        temp_2_17 = (s32)(*(s32 *)(ctx + 8));
        if (temp_2_17 < 0x50) {
            func_002566d0(0xFFFFFF, (s32)( (255.0f * ((f32) temp_2_17 / 80.0f))), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        } else if (temp_2_17 < 0x5B) {
            func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        } else if (temp_2_17 < 0x97) {
            func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20_2);
        } else if (temp_2_17 < 0x1C3) {
            func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20_2);
            temp_17_3 = (s32)(*(s32 *)(ctx + 8) - 0x96);
            func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(ctx + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(ctx + 0x18))) + 0x40)));
            temp_2_18 = (s32)(*(s32 *)(ctx + 0xC));
            if (temp_2_18 > 0) {
                *(s32 *)(ctx + 0xC) = (s32) (temp_2_18 + 1);
            }
            temp_2_19 = (s32)(*(s32 *)(ctx + 0x10));
            if (temp_2_19 > 0) {
                *(s32 *)(ctx + 0x10) = (s32) (temp_2_19 + 1);
            }
            temp_2_20 = (s32)(*(s32 *)(ctx + 0x14));
            if (temp_2_20 > 0) {
                *(s32 *)(ctx + 0x14) = (s32) (temp_2_20 + 1);
            }
            if (*(u32 *)(ctx + 0) & 0x10) {
                temp_2_21 = (s32)(*(s32 *)(ctx + 0xC));
                if (temp_2_21 == 0) {
                    *(s32 *)(ctx + 0xC) = (s32) (temp_2_21 + 1);
                }
                temp_2_22 = (s32)(*(s32 *)(ctx + 0x10));
                if (temp_2_22 == 0) {
                    *(s32 *)(ctx + 0x10) = (s32) (temp_2_22 + 1);
                }
                temp_2_23 = (s32)(*(s32 *)(ctx + 0x14));
                if (temp_2_23 == 0) {
                    *(s32 *)(ctx + 0x14) = (s32) (temp_2_23 + 1);
                }
            } else {
                switch (temp_17_3) {                /* switch 3; irregular */
                case 0x1:                           /* switch 3 */
                    *(s32 *)(ctx + 0xC) = (s32) (*(s32 *)(ctx + 0xC) + 1);
                    break;
                case 0x5A:                          /* switch 3 */
                    *(s32 *)(ctx + 0x10) = (s32) (*(s32 *)(ctx + 0x10) + 1);
                    break;
                case 0xB4:                          /* switch 3 */
                    *(s32 *)(ctx + 0x14) = (s32) (*(s32 *)(ctx + 0x14) + 1);
                    break;
                }
            }
            var_f4_2 = 0.0f;
            var_f3_2 = 0.0f;
            var_f2_2 = 0.0f;
            temp_2_24 = (s32)(*(s32 *)(ctx + 0xC));
            if (temp_2_24 > 0) {
                var_f4_2 = (f32) temp_2_24 / 30.0f;
                if (!(var_f4_2 < 1.0f)) {
                    var_f4_2 = 1.0f;
                }
            }
            temp_2_25 = (s32)(*(s32 *)(ctx + 0x10));
            if (temp_2_25 > 0) {
                var_f3_2 = (f32) temp_2_25 / 30.0f;
                if (!(var_f3_2 < 1.0f)) {
                    var_f3_2 = 1.0f;
                }
            }
            temp_2_26 = (s32)(*(s32 *)(ctx + 0x14));
            if (temp_2_26 > 0) {
                var_f2_2 = (f32) temp_2_26 / 30.0f;
                if (!(var_f2_2 < 1.0f)) {
                    var_f2_2 = 1.0f;
                }
            }
            if (!(var_f4_2 <= 0.0f)) {
                func_00256460(0, (s32)( (153.0f * var_f4_2)), (s32)( (153.0f * var_f3_2)), (s32)( (153.0f * var_f2_2)), 1, 0, 0, 0.0f, 40.0f, 0.0f, 1.0f, 1.0f);
            }
            temp_2_27 = (s32)(*(s32 *)(ctx + 0xC));
            if (temp_2_27 > 0) {
                var_f1_5 = (f32) temp_2_27 / 30.0f;
                if (!(var_f1_5 < 1.0f)) {
                    var_f1_5 = 1.0f;
                }
                temp_f0_6 = 255.0f * var_f1_5;
                func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 0);
                func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 1);
                func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_6), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 2);
            }
            temp_2_28 = (s32)(*(s32 *)(ctx + 0x10));
            if (temp_2_28 > 0) {
                var_f1_6 = (f32) temp_2_28 / 30.0f;
                if (!(var_f1_6 < 1.0f)) {
                    var_f1_6 = 1.0f;
                }
                temp_f0_7 = 255.0f * var_f1_6;
                func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 3);
                func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 4);
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_7), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 5);
            }
            temp_2_29 = (s32)(*(s32 *)(ctx + 0x14));
            if (temp_2_29 > 0) {
                var_f1_7 = (f32) temp_2_29 / 30.0f;
                if (!(var_f1_7 < 1.0f)) {
                    var_f1_7 = 1.0f;
                }
                temp_f0_8 = 255.0f * var_f1_7;
                func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 6);
                func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 7);
                func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_8), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 8);
            }
            if ((D_008C024E[0] & 0x40) && (*(s32 *)(ctx + 8) < 0x1A4)) {
                *(s32 *)(ctx + 8) = 0x1A4;
                *(u32 *)(ctx + 0) |= 0x10;
            }
        } else if (temp_2_17 < 0x1F5) {
            func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20_2);
            func_00256460(0, 0x99, 0x99, 0x99, 1, 0, 0, 0.0f, 40.0f, 0.0f, 1.0f, 1.0f);
            func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(ctx + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(ctx + 0x18))) + 0x40)));
            func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 0);
            func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 1);
            func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 2);
            func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 3);
            func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 4);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 5);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 6);
            func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 7);
            func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 8);
        } else if (temp_2_17 < 0x209) {
            temp_f21_2 = 1.0f - ((f32) (temp_2_17 - 0x1F4) / 20.0f);
            func_002566d0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20_2);
            temp_f0_9 = 153.0f * temp_f21_2;
            func_00256460(0, (s32)( temp_f0_9), (s32)( temp_f0_9), (s32)( temp_f0_9), 1, 0, 0, 0.0f, 40.0f, 0.0f, 1.0f, 1.0f);
            func_00278450(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            func_00278450(*(s8 *)(ctx + 0x3C), 1, func_00109220(*(u16 *)((u8 *)func_00246d90((s32)(s8)func_00248760(*(u16 *)(ctx + 0x18))) + 0x40)));
            temp_f0_10 = 255.0f * temp_f21_2;
            func_00256040(320.0f, 60.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 0);
            func_00256040(320.0f, 100.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 1);
            func_00256040(320.0f, 140.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 2);
            func_00256040(320.0f, 180.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 3);
            func_00256040(320.0f, 220.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 4);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 5);
            func_00256040(320.0f, 260.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 6);
            func_00256040(320.0f, 300.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 7);
            func_00256040(320.0f, 340.0f, 0.0f, 0xFFFFFF, (s32)( temp_f0_10), 0, 0, 0, *(s8 *)(ctx + 0x3C), 1, 8);
        } else if (temp_2_17 < 0x231) {
            temp_19_3 = temp_2_17 - 0x208;
            if (temp_19_3 == 1) {
                temp_3_5 = (s32)(*(s32 *)(ctx + 0x1C));
                if ((temp_3_5 == 0xA) || (temp_3_5 == 0)) {
                    func_0045aeb0(2, &D_00635C80);
                } else {
                    func_0045aeb0(2, &D_00635CA0);
                }
            }
            func_002566d0(0xFFFFFF, (s32)( (255.0f * (1.0f - ((f32) temp_19_3 / 40.0f)))), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, temp_f20_2);
        }
        temp_2_30 = (s32)(*(s32 *)(ctx + 8) + 1);
        *(s32 *)(ctx + 8) = temp_2_30;
        if (temp_2_30 >= 0x29E) {
            *(s32 *)(ctx + 0x44) = 1;
        }
        break;
    case 11:                                        /* switch 1 */
        temp_20_17 = (s32)(**(s32 **)(ctx + 0x54));
        if (*(s32 *)(ctx + 8) == 0) {
            temp_21 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_21_2 = func_0025ff60(temp_21);
            func_004b12e0(temp_21_2, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_21_2, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0xBE) {
            temp_19_4 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_19_5 = func_0025ff60(temp_19_4);
            func_004b12e0(temp_19_5, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_19_5, sp3B0);
        }
        temp_2_31 = (s32)(*(s32 *)(ctx + 8));
        if (temp_2_31 < 0x50) {
            func_00256be0(0xFFFFFF, (s32)( (255.0f * ((f32) temp_2_31 / 80.0f))), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, 0);
        } else if (temp_2_31 < 0x65) {
            func_00256be0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 0.0f, 0);
        } else if (temp_2_31 < 0x6F) {
            temp_f20_3 = (f32) (temp_2_31 - 0x64) / 10.0f;
            func_00256be0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, temp_f20_3, 0);
            var_6 = (u8 *)(&D_00636580);
            var_5 = (u8 *)((Sp120 *)&sp2E0);
            var_4 = 9;
            do {
                temp_3_6 = (s32)(*(s32 *)(var_6 + 0));
                temp_2_32 = (s32)(*(s32 *)(var_6 + 4));
                var_6 += 8;
                var_4 -= 1;
                *(s32 *)(var_5 + 0) = temp_3_6;
                *(s32 *)(var_5 + 4) = temp_2_32;
                var_5 += 8;
            } while (var_4 > 0);
            sp2F8 = 0xFF0000FF;
            sp31C = 0xFF0000FF;
            var_6_2 = (u8 *)(&D_006365D0);
            var_5_2 = (u8 *)((void *)&sp2C0);
            var_4_2 = 4;
            do {
                temp_3_7 = (s32)(*(s32 *)(var_6_2 + 0));
                temp_2_33 = (s32)(*(s32 *)(var_6_2 + 4));
                var_6_2 += 8;
                var_4_2 -= 1;
                *(s32 *)(var_5_2 + 0) = temp_3_7;
                *(s32 *)(var_5_2 + 4) = temp_2_33;
                var_5_2 += 8;
            } while (var_4_2 > 0);
            func_00252230(&sp330, (Sp120 *)&sp2E0, &sp304, temp_f20_3);
            func_003e0870((void *)sp280, (void *)((u8 *)&sp330 + 0xC), sp330.f1C, 0);
            D_00887300[0](6, 0);
            D_00887300[0](8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            temp_2_34 = sp348 & 0xFF;
            if (temp_2_34 >= 0) {
                var_f2_3 = (f32) temp_2_34;
            } else {
                var_f2_3 = 2.0f * (f32) (((u32) temp_2_34 >> 1) | (temp_2_34 & 1));
            }
            func_00366c70(sp334, sp338, sp350, sp352, sp348 >> 8, (s32)( (var_f2_3 * ((f32) (255.0f * temp_f20_3) / 255.0f))), 0, (s16)(sp350 >> 1), 0, (s16)(sp352 >> 1), (void *)sp280, temp_20_17, (void *)&sp2C0);
        } else if (temp_2_31 < 0xAB) {
            func_00256be0(0xFFFFFF, 0xFF, temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 1.0f, 0);
            var_6_3 = (u8 *)(&D_00636580);
            var_5_3 = (u8 *)((Sp120 *)&sp200);
            var_4_3 = 9;
            do {
                temp_3_8 = (s32)(*(s32 *)(var_6_3 + 0));
                temp_2_35 = (s32)(*(s32 *)(var_6_3 + 4));
                var_6_3 += 8;
                var_4_3 -= 1;
                *(s32 *)(var_5_3 + 0) = temp_3_8;
                *(s32 *)(var_5_3 + 4) = temp_2_35;
                var_5_3 += 8;
            } while (var_4_3 > 0);
            sp218 = 0xFF0000FF;
            sp23C = 0xFF0000FF;
            var_6_4 = (u8 *)(&D_006365D0);
            var_5_4 = (u8 *)((void *)&sp1E0);
            var_4_4 = 4;
            do {
                temp_3_9 = (s32)(*(s32 *)(var_6_4 + 0));
                temp_2_36 = (s32)(*(s32 *)(var_6_4 + 4));
                var_6_4 += 8;
                var_4_4 -= 1;
                *(s32 *)(var_5_4 + 0) = temp_3_9;
                *(s32 *)(var_5_4 + 4) = temp_2_36;
                var_5_4 += 8;
            } while (var_4_4 > 0);
            func_00252230(&sp250, (Sp120 *)&sp200, &sp224, 1.0f);
            func_003e0870((void *)sp1A0, (void *)((u8 *)&sp250 + 0xC), sp250.f1C, 0);
            D_00887300[0](6, 0);
            D_00887300[0](8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            temp_2_37 = sp268 & 0xFF;
            if (temp_2_37 >= 0) {
                var_f1_8 = (f32) temp_2_37;
            } else {
                var_f1_8 = 2.0f * (f32) (((u32) temp_2_37 >> 1) | (temp_2_37 & 1));
            }
            func_00366c70(sp254, sp258, sp270, sp272, sp268 >> 8, (s32)( (var_f1_8 * 1.0f)), 0, (s16)(sp270 >> 1), 0, (s16)(sp272 >> 1), (void *)sp1A0, temp_20_17, (void *)&sp1E0);
        } else if (temp_2_31 < 0xD3) {
            temp_f0_11 = 255.0f * (1.0f - ((f32) (temp_2_31 - 0xAA) / 40.0f));
            func_00256be0(0xFFFFFF, (s32)( temp_f0_11), temp_18, (f32)( temp_17), 0.0f, 0.0f, 0.0f, 1.0f, 0);
            var_6_5 = (u8 *)(&D_00636580);
            var_5_5 = (u8 *)((Sp120 *)&sp120);
            var_4_5 = 9;
            do {
                temp_3_10 = (s32)(*(s32 *)(var_6_5 + 0));
                temp_2_38 = (s32)(*(s32 *)(var_6_5 + 4));
                var_6_5 += 8;
                var_4_5 -= 1;
                *(s32 *)(var_5_5 + 0) = temp_3_10;
                *(s32 *)(var_5_5 + 4) = temp_2_38;
                var_5_5 += 8;
            } while (var_4_5 > 0);
            sp138 = 0xFF0000FF;
            sp15C = 0xFF0000FF;
            var_6_6 = (u8 *)(&D_006365D0);
            var_5_6 = (u8 *)((void *)&sp100);
            var_4_6 = 4;
            do {
                temp_3_11 = (s32)(*(s32 *)(var_6_6 + 0));
                temp_2_39 = (s32)(*(s32 *)(var_6_6 + 4));
                var_6_6 += 8;
                var_4_6 -= 1;
                *(s32 *)(var_5_6 + 0) = temp_3_11;
                *(s32 *)(var_5_6 + 4) = temp_2_39;
                var_5_6 += 8;
            } while (var_4_6 > 0);
            func_00252230(&sp170, (Sp120 *)&sp120, &sp144, 1.0f);
            func_003e0870((void *)spC0, (void *)((u8 *)&sp170 + 0xC), sp170.f1C, 0);
            D_00887300[0](6, 0);
            D_00887300[0](8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x48);
            temp_2_40 = sp188 & 0xFF;
            if (temp_2_40 >= 0) {
                var_f2_4 = (f32) temp_2_40;
            } else {
                var_f2_4 = 2.0f * (f32) (((u32) temp_2_40 >> 1) | (temp_2_40 & 1));
            }
            func_00366c70(sp174, sp178, sp190, sp192, sp188 >> 8, (s32)( (var_f2_4 * ((f32) temp_f0_11 / 255.0f))), 0, (s16)(sp190 >> 1), 0, (s16)(sp192 >> 1), (void *)spC0, temp_20_17, (void *)&sp100);
        }
        temp_2_41 = (s32)(*(s32 *)(ctx + 8) + 1);
        *(s32 *)(ctx + 8) = temp_2_41;
        if (temp_2_41 >= 0xD2) {
            *(s32 *)(ctx + 0x44) = 1;
        }
        break;
    case 12:                                        /* switch 1 */
        if (*(s32 *)(ctx + 8) == 0) {
            temp_17_4 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636630, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xA5, 300.0f);
            temp_17_5 = func_0025ff60(temp_17_4);
            func_004b12e0(temp_17_5, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_17_5, sp3B0);
        }
        if (*(s32 *)(ctx + 8) == 0x9B) {
            temp_17_6 = (s32)(func_0025fe50(arg0, func_00455f70(&D_00636710, &sp3DC), 0x96, &D_005DC974));
            func_001102f0(sp3B0, 0x140, 0xB4, 300.0f);
            temp_17_7 = func_0025ff60(temp_17_6);
            func_004b12e0(temp_17_7, func_003e9700(*(s32 *)((u8 *)func_00457120() + 4)));
            func_004b1250(temp_17_7, sp3B0);
        }
        temp_2_42 = (s32)(*(s32 *)(ctx + 8));
        if (temp_2_42 < 0x50) {
            func_002570f0(0xFFFFFF, (s32)( (255.0f * ((f32) temp_2_42 / 80.0f))), (f32)( temp_18), 0, 0, 0, 0.0f);
        } else if (temp_2_42 < 0x65) {
            func_002570f0(0xFFFFFF, 0xFF, (f32)( temp_18), 0, 0, 0, 0.0f);
        } else if (temp_2_42 < 0x8D) {
            sp3D4 = (f32)(s32)(fGpffffa66c);
            temp_f1_2 = 76.5f * ((f32) (temp_2_42 - 0x64) / 40.0f);
            if (!(temp_f1_2 >= 2.1474836e9f)) {
                var_3_2 = 0x4F000000 & 0xFF;
            } else {
                var_3_2 = ((s32)( (temp_f1_2 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            unksp3D7 = var_3_2;
            sp3D8 = sp3D4;
            sp390 = D_006365F0;
            sp3A0 = D_006365F0;
            func_0045d6e0((f32 *) &sp3D8, &sp3A0, 1, 0.0f);
            var_19 = (u8 *)(func_003ec3d0(temp_18, 1));
            var_17 = (u8 *)(*(u8 **)(ctx + 0x58));
            if (var_19 == NULL) {
                func_0046d730(&D_00635CF8, 0xA5E);
            }
            var_2 = 0;
loop_257:
            if (var_2 < 0x100) {
                temp_3_12 = (u8)(var_19[1]);
                var_7 = (u8)(var_19[0]);
                if ((s32) temp_3_12 < (s32) var_7) {

                } else {
                    var_7 = temp_3_12;
                }
                if ((s32) var_7 < (s32) var_19[2]) {
                    var_7 = var_19[2];
                }
                temp_f0_12 = (f32)var_17[0] + (((f32)(temp_2_42 - 0x64) / 40.0f) * (f32)(var_7 - var_17[0]));
                if (!(temp_f0_12 >= 2.1474836e9f)) {
                    var_3_3 = (s32)( temp_f0_12) & 0xFF;
                } else {
                    var_3_3 = ((s32)( (temp_f0_12 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                var_19[0] = var_3_3;
                temp_f0_13 = (f32)var_17[1] + (((f32)(temp_2_42 - 0x64) / 40.0f) * (f32)(var_7 - var_17[1]));
                if (!(temp_f0_13 >= 2.1474836e9f)) {
                    var_3_4 = (s32)( temp_f0_13) & 0xFF;
                } else {
                    var_3_4 = ((s32)( (temp_f0_13 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                var_19[1] = var_3_4;
                temp_f0_14 = (f32)var_17[2] + (((f32)(temp_2_42 - 0x64) / 40.0f) * (f32)(var_7 - var_17[2]));
                if (!(temp_f0_14 >= 2.1474836e9f)) {
                    var_3_5 = (s32)( temp_f0_14) & 0xFF;
                } else {
                    var_3_5 = ((s32)( (temp_f0_14 - 2.1474836e9f)) | 0x80000000) & 0xFF;
                }
                var_19[2] = var_3_5;
                var_19[3] = (u8) var_19[3];
                var_19 += 4;
                var_17 += 4;
                var_2 += 1;
                goto loop_257;
            }
            func_003ec2e0(temp_18);
            func_002570f0(0xFFFFFF, 0xFF, (f32)( temp_18), 0, 0, 0, 0.0f);
        } else if (temp_2_42 < 0xA1) {
            temp_f0_15 = (f32)(s32)(fGpffffa670);
            sp3D0 = temp_f0_15;
            sp3D8 = temp_f0_15;
            sp380 = D_00636600;
            sp3A0 = D_00636600;
            func_0045d6e0((f32 *) &sp3D8, &sp3A0, 1, 0.0f);
            func_002570f0(0xFFFFFF, 0xFF, (f32)( temp_18), 0, 0, 0, 0.0f);
        } else if (temp_2_42 < 0xA4) {
            temp_f0_16 = (f32)(s32)(fGpffffa674);
            sp3CC = temp_f0_16;
            sp3D8 = temp_f0_16;
            sp370 = D_00636610;
            sp3A0 = D_00636610;
            func_0045d6e0(&sp3D8, &sp3A0, 1, 0.0f);
            temp_f0_17 = (f32) (*(s32 *)(ctx + 8) - 0xA0) / 3.0f;
            func_002570f0(0xFFFFFF, 0xFF, (f32)( temp_18), 0, 0, 0, temp_f0_17 * temp_f0_17);
        } else if (temp_2_42 < 0xC9) {
            sp3C8 = (f32)(s32)(fGpffffa678);
            temp_f20_4 = 1.0f - ((f32) (temp_2_42 - 0xA3) / 37.0f);
            temp_f1_3 = 76.5f * temp_f20_4;
            if (!(temp_f1_3 >= 2.1474836e9f)) {
                var_3_6 = 0x4F000000 & 0xFF;
            } else {
                var_3_6 = ((s32)( (temp_f1_3 - 2.1474836e9f)) | 0x80000000) & 0xFF;
            }
            unksp3CB = var_3_6;
            sp3D8 = sp3C8;
            sp360 = D_00636620;
            sp3A0 = D_00636620;
            func_0045d6e0(&sp3D8, &sp3A0, 1, 0.0f);
            func_002570f0(0xFFFFFF, (s32)( (255.0f * temp_f20_4)), (f32)( temp_18), 0, 0, 0, 1.0f);
        }
        temp_2_43 = (s32)(*(s32 *)(ctx + 8) + 1);
        *(s32 *)(ctx + 8) = temp_2_43;
        if (temp_2_43 >= 0xF0) {
            *(s32 *)(ctx + 8) = 0x64;
            *(s32 *)(ctx + 0x44) = 1;
        }
        break;
    }
    var_3_7 = (f32 *)(&sp3C0);
    var_2_2 = 4;
    if (var_3_7 != NULL) {
        do {
            *var_3_7 = 0;
            var_3_7 += 1;
            var_2_2 -= 1;
        } while (var_2_2 != 0);
    }
    sp3C4 = sp3C0;
    var_3_8 = (s32 *)(&spA0);
    var_2_3 = 0x10;
    if (var_3_8 != NULL) {
        do {
            *var_3_8 = 0;
            var_3_8 += 1;
            var_2_3 -= 1;
        } while (var_2_3 != 0);
    }
    spA0 = 0;
    spA4 = 0;
    spA8 = 0x280;
    spAC = 0x1C0;
    spB0 = (u_long128) spA0;
    D_00887300[0](0xE, 0);
    D_00887300[0](0xC, 1);
    D_00887300[0](7, 2);
    D_00887300[0](9, 1);
    D_00887300[0](0x14, 1);
    D_00887300[0](6, 0);
    D_00887300[0](8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x44);
    func_00489f80();
    func_0045d6e0(&sp3C4, &spB0, 0, (f32) 0xFFFF);
    func_0048a000();
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00257900);
#endif

/* measured: nd 94 with a full C body, object 320B against a 336B window (wave 7
   ran out of turns here and left it uncommitted). The body is undersized, so work
   is missing rather than merely mis-scheduled; re-attempt from the m2c draft. */
/* measured: best plain-C probe is object 324B against the 336B retail window;
   verify normalized_diff 24B (fndiff: 11 differing words), with first differing
   byte offsets 196, 198, 199, 200, 203, 206, 207, 210, 211, 212, 213, 214,
   215, 220, 222, 223. The exact float-to-unsigned spelling is
   `f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f; buf[3] = (u8)f;`.
   Best body is archived in build/VRNK_0025b0f0_body.c. The reordered arr16
   pointer-store shape improved fndiff from 12 to 11 differing words; the
   remaining residual is retail's hoisted addiu $a0,$sp,0x5C and addiu
   $a1,$sp,0x40 versus MWCC's sunk materializations. */
#pragma push
/* measured: opt_propagation off keeps the two argument addresses where they
   are taken - &fbuf before the fbuf store, &arr[16] between the two quad
   stores - reproducing retail's hoisted addiu $a0/$a1 (nd24 -> 0). */
#pragma opt_propagation off
// FUN_0025B0F0
void func_0025b0f0(s32 arg0, u8 *arg1) {
    extern u32 *func_00452560();
    u8 *sp;
    u8 *p;
    s32 i;
    f32 fbuf;
    u8 buf[4];
    u8 arr[32];
    u_long128 quad;
    u_long128 *arr16;
    f32 *pfbuf;
    f32 f;

    sp = (u8 *)func_00452560(arg1);
    p = buf;
    i = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
        } while (--i != 0);
    }
    f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f;
    buf[3] = (u8)f;
    pfbuf = &fbuf;
    fbuf = *(f32 *)buf;
    quad = D_00636730;
    *(u_long128 *)&arr[0] = quad;
    arr16 = (u_long128 *)&arr[16];
    *(u_long128 *)&arr[16] = quad;
    func_0045d6e0(pfbuf, arr16, 0.0f, 1);
    switch (*(u32 *)(sp + 4)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 9:
    case 10:
        func_00257900(arg1);
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }
}
#pragma pop
/* measured: banked (2026-09-18): de-noised romwright+m2c switch (17 cases 0-0x10, jtbl_00747EC0 numeric order) + m2c frame (sp80 0xD8 at 0x80, sp160 0x20 at 0x160, arr58[7] at 0x58 covering copy dest 0x60, st188/18c). GUARDED_SCORE 654 (reloc-masked via probe_variants); fnalign retail 944 vs object 944 (+0, within 3% gate 916-972) with 276 edits +40 reloc-only, frame both 0x190. Free pragmas: common_off 758 worse, peephole_off 865 worse, loopinv/unroll/sched/dead 676 ties (baseline 676). Subscript: ((s32 *)ctx)[i] 766 worse (+90), raw arr 676 tie, indexed copy for(n<5)arr[n+2]=src[n] 656 best (-20). Fresh counters N/A (single call-free copy loop, n fresh). Address materialisation (p4/p8 split) 656 tie. Colouring: tmp-order swap 656 tie, arr-first decl 654 best (-2). Residuals: s64 second-arg dsll/dsra vs move (0035adc0 x2, 00255ed0 x2), branch polarity beq/bne, saved-GPR/FPR rotation, dropped move $s2,$zero, D_008873F4 rematerialization. No RankUpLocals needed (separate buffers give exact frame); no func_0025f360 calls so *(s32*)->*(u8**) fix N/A (as in 00254a70 note). Production stays ASM via guard. */
/* measured 0025b240 (owner, 2026-09-19): fnalign edits **276 -> 226** by writing the
   `if (c == c) ... else if` chain as a `switch (c)` with the cases sorted ascending.
   MWCC lowers a switch as descending comparisons with the arm bodies laid out in
   ascending case order (handoff 7av), and a chain cannot produce that shape however the
   arms are ordered in source.  Found by sweeping every first-party floor that carries a
   four-or-more arm equality chain and measuring both spellings; the sweep also found
   `func_001adea0` where the switch is *worse* (49 -> 51), so this is measured per
   function and never assumed. */
// FUN_0025B240 NONMATCHING
#ifdef NON_MATCHING
extern u8 D_00636740[];
extern u8 D_00636760[];
extern u8 D_00636780[];
extern u8 D_006367A0[];
extern u8 D_00635D08[];
extern u8 D_005DC974[];
extern s32 gp599C;
extern s32 gp5998;
extern f32 gp7D5C;
extern s32 gp4BB8;
extern char gp5980;
extern char gp5978;
extern s32 func_0035adc0();
extern void func_00440b68();
extern u8 *func_00454a60();
extern s32 func_004553c0();
extern s32 func_00455f70();
extern s32 func_004667d0();
extern u32 func_003ec3d0();
extern void func_003ec2e0();
extern void func_0043f810();
extern void func_0043f9c8();
extern s32 func_004669d0();
extern s32 func_00459760();
extern s32 func_0045b400();
extern s32 func_00459a60();
extern void func_0045aac0();
extern void func_0025fd70(u8 *arg0, s32 arg1, u8 arg2);
extern void func_0025fbb0(u8 *dst, u8 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 farg0, f32 farg1);
extern void func_0025fd00(u8 *dst, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
extern void func_0025fab0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern u8 *func_00255b90();
extern void func_002518d0();
extern s32 func_00189fa0();
extern void func_00452080();
extern s32 func_00452380();
extern s32 func_002774d0();
extern void func_002777f0();
extern s32 func_002bb680();
extern void func_002bb420();
extern void func_002bb550();
extern void func_002bbcf0();
extern s8 func_002bab80();
extern void func_002badc0();
extern void func_002bae80();
extern s32 func_00255ed0();
extern s32 func_00248760();
extern u8 *func_002438b0();
extern u8 *func_00246830();
extern u8 *func_002468a0();
extern u8 *func_00246d90();
extern u8 *func_00109220();
extern void func_00442830();
extern void func_00275980();
extern void func_002bbd80();
extern s32 func_00106330();
extern void func_00106390();
extern u8 *func_0010a900();
extern s32 func_0010cc20();
extern void func_004599a0();
extern void func_00459950();
extern void func_00459880();
extern void func_004598e0();
extern void func_0045a8d0();
extern void func_0045b2e0();
extern void func_002519e0();
extern void func_00251ce0();
extern void func_00460ac0();
extern u8 *func_00460990();
s32 func_0025b240(u8 *arg0) {
    u8 *ctx;
    s32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 st18c;
    s32 st188;
    s32 arr58[7];
    u8 sp80[0xD8];
    u8 sp160[0x20];
    s8 c;
    s8 cc;
    u8 *pb;
    void *pv;
    s32 n;
    u8 *argb = arg0;
    ctx = (u8 *)func_00452560(argb);
    tmp = 0;
    switch (*(s32 *)(ctx + 4)) {
    case 0:
        *(s32 *)(ctx + 4) = 3;
        c = (s8)func_00248760((u16)*(s32 *)(ctx + 0x18));
        *(s32 *)(ctx + 0x2C) = func_0035adc0((s32)argb, c, 0);
        *(s32 *)(ctx + 0x30) = func_0035adc0((s32)argb, -1, 0);
        func_00440b68(&gp5980, D_00635CF8, 0xADB);
        *(u8 **)(ctx + 0x34) = func_00454a60(D_00636760, 1);
        goto tail;
    case 1:
        *(s32 *)(ctx + 4) = 2;
        if (*(s32 *)(ctx + 0x1C) < 1 || *(s32 *)(ctx + 0x1C) > 9) {
            func_004598e0(10);
        }
        /* fallthrough */
    case 2:
        if ((*(s32 *)ctx & 8) != 0) {
            goto tail;
        }
        if (gp599C == -1) {
            func_00459880();
        } else {
            func_004599a0((s16)gp599C, 10);
            func_00459950(-0x3C);
        }
        if (gp5998 == -1) {
            func_0045a8d0(3, 0);
        } else {
            func_0045b2e0(gp5998);
        }
        return -1;
    case 3:
        if (func_0035af60(*(s32 *)(ctx + 0x2C)) == 0) {
            goto tail;
        }
        if (func_0035af60(*(s32 *)(ctx + 0x30)) == 0) {
            goto tail;
        }
        if (func_004553c0(*(u8 **)(ctx + 0x34)) == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 4;
        *(s32 *)(ctx + 0x38) = func_00455f70((s32)D_00636780, &st18c);
        *(s32 *)(ctx + 0x50) = func_004667d0(0, (s32)D_006367A0, 0, 0, 0, 0, 0, 0, 0, 0);
        tmp = func_0035afa0(*(s32 *)(ctx + 0x2C));
        tmp2 = func_003ec3d0(tmp, 1);
        if (tmp2 == 0) {
            func_0046d730(D_00635CF8, 0xAF7);
        }
        func_0044ea90(D_00635CF8, 0xAF8);
        pv = D_008873F4[0](1, 0x400, 0x40000);
        *(u8 **)(ctx + 0x58) = (u8 *)pv;
        func_0043f810(pv, (void *)tmp2, 0x400);
        func_003ec2e0(tmp);
        goto tail;
    case 4:
        *(s32 *)(ctx + 0x54) = func_004669d0(*(s32 *)(ctx + 0x50), &st188, 0);
        if (st188 == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 5;
        *(s32 *)(ctx + 0x50) = 0;
        goto tail;
    case 5:
        gp599C = func_00459760();
        gp5998 = func_0045b400();
        func_00459a60();
        func_0045aac0(3, 0, 10);
        *(s32 *)(ctx + 4) = 6;
        *(s32 *)(ctx + 8) = 0;
        func_0043f9c8(sp80, 0, 0xD8);
        func_0025fd70(sp80, 0x35, 0);
        func_0025fbb0(sp80, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0, 0, 0.0f, 0.0f);
        tmp2 = 0x3E800000;
        func_0025fd00(sp80, 0xFF, 0, gp7D5C, 0.25f);
        func_0025fab0((s32)argb, 1, 0, sp80, (s32)D_005DC974);
        *(s32 *)(ctx + 0x28) = tmp2;
        *(s32 *)(ctx + 0x40) = (s32)func_00255b90();
        func_002518d0(*(s32 *)(ctx + 0x1C));
    case 6:
        tmp3 = *(s32 *)(ctx + 8) + 1;
        *(s32 *)(ctx + 8) = tmp3;
        if (tmp3 == 5 && func_00189fa0() != 0) {
            *(s32 *)ctx |= 1;
        }
        if (*(s32 *)(ctx + 8) <= 0x34) {
            goto tail;
        }
        func_00452080(*(s32 *)(ctx + 0x28));
        if (*(s32 *)(ctx + 0x1C) < 1 || *(s32 *)(ctx + 0x1C) > 10) {
            *(s32 *)(ctx + 4) = 9;
        } else {
            *(s32 *)(ctx + 4) = 7;
        }
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 7:
        *(s32 *)(ctx + 4) = 8;
        tmp4 = *(s32 *)(ctx + 0x1C);
        tmp3 = *(s32 *)(ctx + 0x18);
        if (tmp3 == 0) {
            func_0046d730(D_00635CF8, 0x25D);
        }
        func_0044ea90(D_00635CF8, 0x25E);
        pv = D_008873F4[0](1, 0x40, 0x40000);
        *(s32 *)((u8 *)pv + 4) = tmp3;
        *(s32 *)((u8 *)pv + 8) = tmp4;
        *(void **)(ctx + 0x24) = (void *)func_00451fc0(argb, D_00635D08, 0xF, 0, 0, (void *)func_002519e0, (void *)func_00251ce0, pv);
    case 8:
        if (func_00452380(D_00635D08) != 0) {
            goto tail;
        }
        if (*(s32 *)(ctx + 0x1C) == 0 || *(s32 *)(ctx + 0x1C) == 10) {
            *(s32 *)(ctx + 4) = 9;
        } else {
            *(s32 *)(ctx + 4) = 0xB;
        }
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 9:
        *(s32 *)(ctx + 4) = 10;
        *(s8 *)(ctx + 0x3C) = (s8)func_002774d0(*(s32 *)(ctx + 0x38));
        *(s32 *)(ctx + 0x44) = 0;
        *(s32 *)ctx |= 2;
        tmp4 = *(s32 *)(ctx + 0x1C);
        func_0045aac0(3, 0, 10);
        if (tmp4 >= 1 && tmp4 <= 9) {
            goto case10tail;
        }
        if (tmp4 != 10) {
            func_004599a0(0xE, 10);
        } else {
            func_004599a0(0xF, 10);
        }
        /* fallthrough */
    case 10:
    case10tail:
        if (*(s32 *)((u8 *)func_00452560(argb) + 0x44) == 0) {
            goto tail;
        }
        *(s32 *)(ctx + 4) = 0xB;
        func_002777f0(*(s8 *)(ctx + 0x3C));
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 11:
        *(s32 *)(ctx + 4) = 0xC;
    case 12:
        *(s32 *)(ctx + 4) = 0xD;
        *(s32 *)(ctx + 8) = 0;
        goto tail;
    case 13:
        *(s32 *)(ctx + 4) = 0xE;
        *(s8 *)(ctx + 0x3C) = func_002bab80(*(void **)(ctx + 0x38));
        tmp4 = *(s32 *)(ctx + 0x1C);
        if (tmp4 == 0) {
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            if (*(s32 *)(ctx + 0x18) == 7) {
                func_002badc0(*(s8 *)(ctx + 0x3C), 0xC);
            } else {
                func_002badc0(*(s8 *)(ctx + 0x3C), 2);
            }
        } else if (tmp4 == 10) {
            func_00275980((char *)func_00246830(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            func_00275980((char *)func_00246d90(func_00248760(*(u16 *)(ctx + 0x18))), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 2, sp160);
            pb = func_00109220(*(u16 *)(func_00246d90(func_00248760(*(u16 *)(ctx + 0x18))) + 0x40));
            func_00442830((char *)sp160, (char *)pb);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 3, sp160);
            func_002badc0(*(s8 *)(ctx + 0x3C), 4);
        } else if (tmp4 == 11) {
            func_002badc0(*(s8 *)(ctx + 0x3C), 5);
        } else if (tmp4 == 12) {
            func_002badc0(*(s8 *)(ctx + 0x3C), 6);
        } else {
            if (gp599C == -1) {
                func_00459880();
            } else {
                func_004599a0((s16)gp599C, 10);
                func_00459950(-0xB4);
            }
            if (gp5998 == -1) {
                func_0045a8d0(3, 0);
            } else {
                func_0045b2e0(gp5998);
            }
            func_00275980((char *)func_00246830(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
            func_00442088(sp160, &gp5978, *(s32 *)(ctx + 0x1C));
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, sp160);
            func_002bbd80(*(s8 *)(ctx + 0x3C), 2, func_002438b0(func_00248760(*(u16 *)(ctx + 0x18)) & 0xFF));
            func_002badc0(*(s8 *)(ctx + 0x3C), 3);
        }
    case 14:
        if (func_002bb680(*(s8 *)(ctx + 0x3C)) == 0) {
            func_002bb420(*(s8 *)(ctx + 0x3C));
            tmp4 = *(s32 *)(ctx + 0x1C);
            cc = (s8)tmp4;
            if (cc == 0) {
                cc = 1;
            }
            if (tmp4 == 0xB || tmp4 == 0xC || func_00255ed0(*(s32 *)(ctx + 0x18), cc) == 0) {
                func_002bb550(*(s8 *)(ctx + 0x3C));
                *(s32 *)(ctx + 4) = 1;
                *(s32 *)ctx |= 4;
            } else {
                *(s32 *)(ctx + 4) = 0xF;
            }
        }
        func_002bbcf0(*(s8 *)(ctx + 0x3C));
        goto tail;
    case 15:
        *(s32 *)(ctx + 4) = 0x10;
        cc = *(s8 *)(ctx + 0x1C);
        if (cc == 0) {
            cc = 1;
        }
        for (n = 0; n < 5; n++) {
            arr58[n + 2] = ((s32 *)D_00636740)[n];
        }
        tmp = func_00255ed0(*(s32 *)(ctx + 0x18), cc);
        c = (s8)tmp;
        if (c >= 2 && c <= 6 && (*(s32 *)ctx & 0x20) != 0) {
            func_00106390(arr58[c], 1);
            switch (c) {
            case 2:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xD);
                break;
            case 3:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xE);
                break;
            case 4:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0xF);
                break;
            case 5:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0x10);
                break;
            case 6:
                func_002bae80(*(s8 *)(ctx + 0x3C), 0x11);
                break;
            }
            *(s32 *)ctx &= ~0x20;
            goto case16tail;
        }
        if (c > 1 && c < 7 && func_00106330(arr58[c]) == 0) {
            *(s32 *)ctx |= 0x20;
        }
        func_00275980((char *)func_002468a0(*(u16 *)(ctx + 0x18)), (char *)sp160, 0x20);
        func_002bbd80(*(s8 *)(ctx + 0x3C), 0, sp160);
        switch (c) {
        case 2:
            func_002badc0(*(s8 *)(ctx + 0x3C), 7);
            break;
        case 3:
            func_002badc0(*(s8 *)(ctx + 0x3C), 8);
            break;
        case 4:
            func_002badc0(*(s8 *)(ctx + 0x3C), 9);
            break;
        case 5:
            func_002badc0(*(s8 *)(ctx + 0x3C), 10);
            break;
        case 6:
            func_002badc0(*(s8 *)(ctx + 0x3C), 11);
            break;
        case 7:
            tmp = 0x113;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)((s32)gp4BB8 + 0x1469));
            func_002badc0(*(s8 *)(ctx + 0x3C), 0x12);
            pb = func_0010a900(5);
            func_0010cc20(pb, 0x113);
            break;
        case 8:
            tmp = 0x112;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)((s32)gp4BB8 + 0x1456));
            func_002badc0(*(s8 *)(ctx + 0x3C), 0x13);
            pb = func_0010a900(5);
            func_0010cc20(pb, 0x112);
            break;
        case 9:
            tmp = 0x10D;
            func_002bbd80(*(s8 *)(ctx + 0x3C), 1, (void *)((s32)gp4BB8 + 0x13F7));
            pb = func_0010a900(5);
            func_0010cc20(pb, 0x10D);
            break;
        }
        if (tmp == 0x113) {
            func_00106390(0x1013, 1);
        }
        if (tmp == 0x112) {
            func_00106390(0x1012, 1);
        }
        /* fallthrough */
    case 16:
    case16tail:
        if (func_002bb680(*(s8 *)(ctx + 0x3C)) == 0) {
            func_002bb420(*(s8 *)(ctx + 0x3C));
            if ((*(s32 *)ctx & 0x20) == 0) {
                func_002bb550(*(s8 *)(ctx + 0x3C));
                *(s32 *)(ctx + 4) = 1;
                *(s32 *)ctx |= 4;
            } else {
                *(s32 *)(ctx + 4) = 0xF;
            }
        }
        func_002bbcf0(*(s8 *)(ctx + 0x3C));
        goto tail;
    default:
        goto tail;
    }
tail:
    tmp4 = *(s32 *)ctx;
    if ((tmp4 & 8) == 0) {
        if ((tmp4 & 2) != 0) {
            tmp = *(s32 *)(ctx + 0x4C) + 1;
            *(s32 *)(ctx + 0x4C) = tmp;
            if (tmp >= 0x28) {
                *(s32 *)ctx &= ~2;
                *(s32 *)ctx |= 8;
            }
        }
    } else if ((tmp4 & 4) != 0) {
        tmp = *(s32 *)(ctx + 0x4C) - 1;
        *(s32 *)(ctx + 0x4C) = tmp;
        if (tmp <= 0) {
            *(s32 *)ctx &= ~4;
            *(s32 *)ctx &= ~8;
        }
    }
    pb = func_00460990();
    *(void **)(pb + 8) = (void *)func_0025b0f0;
    *(u8 **)(pb + 0x10) = argb;
    func_00460ac0(D_007963D0, pb);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025b240);
#endif



/* measured: retail hoists the jtbl_008873EC base into $s0 (reusing the dead
 * loop counter) and reloads the element per call; mwcc b210 rematerializes
 * the base at the FIRST call site (lui+lw) even when the base is cached in a
 * local (nd 34 with late assignment, nd 69 with early assignment, nd 28
 * direct). Loop and all other calls match byte-for-byte. Same floor as the
 * confirmed D_00887300 vtable calls. */
// FUN_0025C100
void func_0025c100(void) {
    void (**fp)(void *);
    u8 *p;
    u8 *list;
    s32 i;

    p = (u8 *)func_00452560();
    if (*(s32 *)p & 1) {
        func_00189ec0();
    }
    list = *(u8 **)(p + 0x40);
    i = 0;
    while (*(s32 *)(list + i * 0x10 + 8) != 0) {
        if (*(s32 *)(list + i * 0x10 + 0xC) == 0) {
            func_00268bd0(*(s32 *)(list + i * 0x10 + 8), 0);
        }
        func_0047a0e0(*(u8 **)(list + i * 0x10 + 4), 0, *(f32 *)(list + i * 0x10));
        i++;
    }
    fp = (void (**)(void *))DAT_008873ec_abs;
    (*fp)(list);
    if (*(u32 *)(p + 0x50) != 0) {
        func_0046d730(&D_00635CF8, 0xC2F);
    }
    if (*(u8 **)(p + 0x58) != NULL) {
        (*fp)(*(u8 **)(p + 0x58));
    }
    if (*(u32 *)(p + 0x54) != 0) {
        func_003ef3a0(*(u32 *)(p + 0x54));
    }
    func_00454bd0(*(u32 *)(p + 0x34));
    (*fp)(p);
}
// FUN_0025C230
void func_0025c230(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    if (arg1 == 0) {
        func_0046d730(D_00635CF8, 0xC40);
    }
    func_0044ea90(D_00635CF8, 0xC41);
    p = (u8 *)D_008873F4[0](1, 0x5C, 0x40000);
    *(s32 *)(p + 0x18) = arg1;
    *(s32 *)(p + 0x1C) = arg2;
    *(s32 *)(p + 0x20) = arg3;
    *(s32 *)(p + 0x4) = 0;
    func_00451fc0(arg0, D_006367C0, 0xF, 0, 0, func_0025b240, func_0025c100, p);
}
