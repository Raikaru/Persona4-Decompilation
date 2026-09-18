#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclCombineDraw.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;
typedef FclVec2 f2;
typedef FclByte4 u4;

typedef unsigned int u_long128 __attribute__((mode(TI)));

static inline u32 addOff(u32 offset, u32 base) { return offset + base; }

/* Retail clears the eight-byte packet through a guarded byte loop rather than a
   call, so the clear has to be inline here too. */
static inline void fclZero8(u8 *p)
{
    s32 n = 8;

    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
}




/* Combine-draw conventions (established from MATCHed 00315310/00316e80 and retail 00314ef0): */
/* Work struct is { RGBA/col[16] at sp+0x70; u8 gap[16] at sp+0xB0; Pair/pos[16] at sp+0xC0 } (frame 0x140 for 16-entry windows). */
/* Colours are FclByte4 (4x u8); UV/pos are FclVec2 pairs copied as two u32 words (lw/sw, never lwc1). */
/* s64 params retain raw in s-reg (raw=arg1), normalize via (s16)raw to u32 base, loop increment as i=(s16)(i+1), offset-first address via addOff(idx*2,(u32)t). */
/* 16-entry dispatch is flat sltiu (i-14<2,i-6<4,i-10<4,else) to sp+0x70+i*4; use inclusive (<=1U/<=3U) if slti dest is $v0 not $at. */
/* 0032f4d0 skeleton (reuse for draw family): s64 locals spA0..sp78 fed to 2970 and cast to FclVec2 for tbl stores */
/* (tbl FclVec2[5] at 0x50, b7=5/6 out-of-bounds over sp78/sp80); 0x1306 nested inside 0x1305 (both beqz to block 6); */
/* third 2970(&sp98) block before 0x1305; t->0xB7 re-read inline (never named counter); f20=-14 last in 0x1306; */
/* r s16 (s8 re-extends at fa30); loop for(i=0;(s16)i<t->0xB7;i=(s16)(i+1)) with n=(s16)i and func_003147e0 6-arg call. */
/* Extensions from the 0032fbc0/00329310/0031ddf0/0032f4d0 floors (four smallest unguarded, 1184/1248/1328/1376B): */
/* 69f0 takes f2 by value: pass *(FclVec2*)&sp, never s64 (illegal conversion, forces ld/sd instead of lw/sw). */
/* 46d chain per source externs: h = func_0046d200(31560(), id); ... func_0046b2f0(h) ...; func_0046d280(h) with h u8* (void* node). */
/* 2e48a0 2nd param is s16 (source extern, not s32): pass (s16)i raw, no normalize. */
/* D_007495C0/D_00749600 are f32 arrays read by word index D_[v17], not byte offset. */
/* 6150 copy pattern: retain result in p1/p2 locals, *(FclByte4*)(p2+0x85)=*(FclByte4*)(p1+0x85); never re-call 6150 for the source. */
/* Pragma check on all four exact bodies: loop_invariants neutral (220->220, 249->250, 271->271, 307->307), common_subs off and schedule on worse except f4d0 cse_off 307->287 (ties prior F floor, noted not committed); rotation persists, so it stands as a measured wall here unlike mdlSE 0047e0f0 where loop_invariants dissolved it. */
/* Width check on all four: (s8) counters/args via lb with dsll24/dsra24, heap bytes via lbu/lhu; no s8/u8 mixups remain. */
/* Fresh 2026-09-17 (3212e0 lane, after 004941f0/00347c70 in order): pointer slots holding heap+offset (retail sq 0xC0/0xB0 on 3212e0) are plain u8* locals, not u_long128 -- u_long128 widens frame 0xF0->0x100 and costs 4 words (WIDE 321w/139ed/375B -> PTR 317w/136ed+3reloc/367B exact, retail 368/367). Byte-copy colours where retail shows batched lbu/sb stay u8[4] with per-byte copies; FclByte4 &c + struct-assign gives lw/sw and only applies where retail shows word copies (MATCHed 315310 idiom) -- trying FclByte4 here fails to compile (needs & + .bN rewrites) and would be the wrong shape. Guarded (u8)(s32)f conversion uses the same normal-first 2.1474836e9f > f + per-arm andi idiom as y_CmbCardEff 00348330 (shared across owners; polarity >= vs > is equality-edge only, both match retail c.le.s/bc1t). */
/* Even-lane 2026-09-17 guarded floors (within 3% per parent policy, NONMATCHING kept): 212e0 PTR 317w 367/367 exact via docs/probe_archive/PTR_003212e0_body.c, 297f0 356w 414/404 via docs/probe_archive/EVEN_003297f0_body.c, 18840 394w 457/444 via docs/probe_archive/EVEN_00318840_body.c; repro probe_variants --candidate CAND=<path> + fnalign --candidate <path> --quiet + measure_guarded; levers: (1) sq slots as plain u8* never u_long128 (212e0 0x100->0xF0), (2) heap *(FclVec2*)(p+0x38) emits ldr/ldl, (3) if-chain for 6/7/8 not switch plus s32 t16/t17/v18 reuse and word sw for 0x8. */
/* C147E0 lane 2026-09-17 (coldest owner, smallest-first): 147e0 367w 465/452 (+13, +2.88% PASS) via docs/probe_archive/C147E0_003147e0_body.c + `#pragma optimization_level 1` wrapper in src (bare O2 body 369w 463/452); repro probe_variants --candidate C147E0=<path> + fnalign --candidate <path> --quiet + measure_guarded; levers: (1) m2c 12-arg 77d0 carries a phantom M2C_ERROR 12th arg -- drop to the 11-arg extern, (2) function-local `extern void func_002b77d0(s16,s64,s16,s32,s64,s32,s64,s64,f32,s16,s32)` (1st/3rd s16 + 6th s32, no shared-top edit; global s64/s64/s64 costs per-call dsll32-0 extends, 469->463), (3) v19=(s8)arg1 reuse for 14ef0 2nd arg + lia=(s16)(li+0x174) share for loop a0/a2 + s16 temps for 7750, (4) s32 colour words (lw for 77d0 4th arg) + f32 spF0[4] for 29e0 16B with heap swc1 stores + slot=(u8**)(t+v19*4+0x258) with *slot for the five 81f0 calls. Frame note: retail is 0x160 but this body makes 0x150 (16 short -- c0/t as s64/u8* instead of 16B sq slots); the plain-u8* lever is 212e0-specific (0xF0), not universal, so a later lane can reclaim frame words with 16B slots without changing the count. Full pragma_sweep on the banked body: O1 367 <-- better, bare 369, O3/O4 393, schedule-on 394, peephole-off 413, O0 494. O3 wrapper on the pre-bank candidate measured 389w / 417 vs 449 (-7.1% short, FAIL) -- O-level-3 shrinkage overshoots here, so O3 is a measured negative on this body. Trap (parent-verified): mwcc silently ignores unknown pragmas (`inline_depth(0)`, `optimize_for_size on`, any misspelling) -- verify a new pragma changes object bytes (sha1/len via fnalign._object_for) before believing a tie. Next-cold decode (330060, 1872B): signature (u8*,s32) per y_fclCombine.c callers (arg0,0..5); head is three u8[4] byte-copy colours (lbu/sb, second copy sourced from first 6150 result p1, never re-call) + sb 1,0x13A + sltiu (s8)arg1<6 guard with plain switch (port arms from MATCHed 307b0 in this file, which has the same 6-case shape but a table address arg2 and t17 that 330060 lacks -- read constants off retail, do not copy t17); tail (+176B vs 307b0) is a 9-iteration 68d0 loop, an (0x11E-0x120) loop with 2970/6c30/68d0/6d60/2a60/6150, four colour restores, and the 0xA9/0xB1/0xB5 lwc1/madd/swc1 float chain reusing f20/f21. */
extern void func_0044ea90(const void *arg0, u32 arg1);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void *func_00451fc0(s32, const void *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern u8 *func_00117780(s32, s32, s32, s32, s32);
extern void func_00314010(u8 *arg0);
extern void func_003142f0(u8 *arg0);
extern s32 func_00106330(s32);
extern s32 func_00452490(void *);
extern void func_0011b9e0(u8 *arg0);
extern void func_0011d100(u8 *arg0, f32 *arg1);
extern void func_0011b480(u8 *, s32, u32, s32);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(s32, s32, s32, s8);
extern void func_0011c2c0(s32, s32, s32, s8);
extern void func_0011bdc0(u8 *arg0);
extern void func_0011bf10(u8 *arg0);
extern void func_002b2970(void *, f32, f32);
extern void func_002b6c30(s16, s64, s32, f32);
extern void func_002b6a70(s16, u8, u8, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s16 func_002b6970(s16, s16);
extern void func_002b7750(s16, s16);
extern void func_002b2a60(void *, s32, s32, s32, s32);
extern u8 *func_002e4870(s8 arg0);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern u8 *func_0034ae50(u8 *arg0, s64 arg1);
extern void func_002ba970(u8 *, s16, u32);
extern s32 func_002b2a30(u8, u8, u8, u8);
extern s32 func_0010b5b0(void);
extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
extern void func_002b6b90(s16, s32, s32, s32, s32, s32);
extern void func_002b8370(void *, s32, s32, s32, s32, s32);
extern void func_003147e0(u8 *, s8, s64, s16, s32, s32);
extern void func_0032fa30(u8 *, s16, u32, u32, u32);
extern s8 func_0032fb60(s8);
extern void func_003297f0(u8 *, s64, s32, f32, f32);
extern void func_0031ac10(u8 *, s64, s8, u16, u16, s32, s32, s32, s8, u8);
extern f32 D_006440F0[];
extern f32 D_006440F8[];
extern f32 D_00644290[];
extern f32 D_00644298[];
extern f32 D_00644350[];
extern void func_002b83e0(u8 *, s64, s64, s64, u8, u8, s32, s32, f32, f32, s64, s64);
extern void func_002b6af0(s16, u32, u32, s32, f32, f32, f32, f32);
extern void func_002b69f0(s16, f2, f2, u32, u32, s16);
extern u8 *func_0046d200(u32, u32);
extern f32 func_0046b2f0(u8 *);
extern void func_0046d280(void *node);
extern void func_002b68d0(s16, s16, s8);
extern f32 D_007495C0[];
extern f32 D_00749600[];
extern s32 func_00110140(void);
extern void func_002b6d60(s16);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s16 func_002b2d00(s32, s32, s32, s32, s8);
extern s16 func_002b2d50(s32, s32, s32, s32, s32);
extern void func_002b2e70(s16, s16, s32, s8, s16 *, s16 *);
extern void func_002b2f90(s16, s16, s32, s8, s16 *, s16 *);
extern f32 iGpffff8360;
extern f32 iGpffff8504;
extern void func_003191c0(u8 *, s64, s32, u16, u8, s32, s32, s8);
extern s32 func_00331560(void);
extern void func_002b77d0(s64, s64, s64, s32, s64, s64, s64, s64, f32, s16, s32);
extern void func_002b29e0(u8 *, f32, f32);
extern u8 *func_002b81f0(u8 *);
extern f32 func_0046b260(u8 *);
extern void func_00314ef0(u8 *, s64, s64, s32, s64, s32);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern void func_0046b0d0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
extern void func_002777f0(s32 arg0);
extern void func_00454bd0(u8 *arg0);
extern void (*D_008873EC[])(void *);
extern char D_00644D30[];
extern char D_00644D50[];
extern char D_00644DB0[];
extern char D_00644DD0[];
extern char D_00644DF0[];
extern char D_00644E10[];
extern char D_00644E30[];
extern char D_00644E48[];
extern char D_00644E60[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 D_00644C90[];
extern f32 D_00644020[];
extern f32 D_00644098[];
extern f32 D_00644AD0[];
extern f32 D_00644B00[];
extern s8 D_00749530[];
extern s64 iGpffffa900;
extern s64 iGpffffa908;
extern s32 iGpffffa910;
extern s32 iGpffffb598;
extern s32 iGpffffb440;
extern u8 D_00796310[];
extern u8 D_00796370[];
extern s32 func_00279350(f32, f32, f32, s32, s32, s32, s32, s32, s32, u8 *);
extern int func_00275820(f32, f32, f32, int, s8, int, const char *, int, int, void *, int);
extern void func_0034a640(s32, u16, s32);
extern s32 func_0034a630(u8 *);
extern u8 func_00109280(s32);
extern void func_0011d1d0(u8 *, f32);
extern s8 func_00331640(void);
extern void func_00330e50(s32, s64, f32, s32, u8, s32, f32, f32, void *);
extern f32 func_002b2aa0(s64, f32, f32, f32, f32);
extern void func_002b82d0(u8 *, u32, u32, u32, u32, s16);
extern u8 D_00795E60[];
extern void *func_00451de0(const void *, s32, s32, s32, void *, void *, void *);
extern void func_00440b68();
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_003312e0(u8 *);
extern char D_00644D70[];
extern char D_00644D90[];
extern f32 D_00644880[];
extern f32 D_00644888[];
extern f32 D_00644890[];
extern f32 D_00644898[];
extern f32 D_006440B8[];
extern void func_002b6140(u8 *, u8);
extern f32 D_00643D70[];
extern f32 D_00644CA0[];
extern f32 D_006441C8[];
extern f32 D_006441D0[];
extern f32 D_006441C0[];
extern f32 D_006441E0[];
extern f32 D_006441D8[];

// FUN_00314320
s32 func_00314320(s32 arg0) {
    s32 ret;
    u8 *p;

    func_0044ea90(D_00644D30, 0x16D);
    p = (u8 *)D_008873F4[0](1, 0x14, 0x40000);
    func_0043f9c8(p, 0, 0x14);
    ret = (s32)func_00451fc0(arg0, D_00644D50, 0xF, 0, 0, func_00314010,
                             func_003142f0, p);
    *(s8 *)p = 7;
    *(s32 *)(p + 4) = (s32)func_00117780(ret, 0xF, 3, 5, 5);
    *(s8 *)(p + 0xD) = 0;
    return ret;
}

// FUN_00314400
void func_00314400(u8 *arg0, s8 arg1) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0) = 0x10;
    if (arg1 == 1) {
        *(s8 *)(t + 0) = 0xF;
        func_0011bc70((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_00314450
void func_00314450(u8 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    f32 sp18[2];
    u32 t = *(u32 *)(arg0 + 0x38);

    fclZero8((u8 *)sp18);
    sp18[1] = 40.0f * (f32)arg3;
    *(s32 *)((u32)t + 8) = arg1;
    *(u8 *)((u32)t + 0xC) = arg2;
    *(u8 *)((u32)t + 0) = 0;
    func_0011d100((u8 *)*(u32 *)((u32)t + 4), sp18);
}

// FUN_003144D0
void func_003144d0(u8 *arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4) {
    f32 sp18[2];
    u32 t = *(u32 *)(arg0 + 0x38);

    fclZero8((u8 *)sp18);
    sp18[1] = 40.0f * (f32)arg4;
    *(s32 *)((u32)t + 8) = arg1;
    *(u8 *)((u32)t + 0xC) = arg2;
    *(u8 *)((u32)t + 0) = 8;
    *(s32 *)((u32)t + 0x10) = arg3;
    func_0011d100((u8 *)*(u32 *)((u32)t + 4), sp18);
}

// FUN_00314560
void func_00314560(u8 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (arg3 == 0) {
        *(s32 *)(t + 8) = arg1;
        *(s8 *)(t + 0xC) = arg2;
        func_0011c180(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
        return;
    }
    *(s32 *)(t + 8) = arg1;
    *(s8 *)(t + 0xC) = arg2;
    func_0011c2c0(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
}
// FUN_003145E0
s32 func_003145e0(u8 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (func_00452490((void *)arg0) == 0) {
        return 0;
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        return 0;
    }
    return *(s8 *)(*(u32 *)(arg0 + 0x38)) < 6;
}

// FUN_00314660
s8 func_00314660(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_00314670
void func_00314670(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38)) = arg1;
}

// FUN_00314680
void func_00314680(u8 *arg0) {
    s64 sp18;
    f32 *p;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp18, (sp18 = iGpffffa900, p)));
}
// FUN_003146C0
void func_003146c0(u8 *arg0) {
    func_0011b9e0(*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
}

/* Historical measurements before parking: the original all-s32 0011b480
   declaration scored nd 18, object 60/window 80; the canonical pointer
   prototype (u8 *, s32, u32, s32) scored nd 28, object 68/window 80.
   Retail copies arg2 into $v1 early, stores through $v0, and sign-extends
   $v1 into $a3 immediately before func_0011b480; MWCC reverses that
   materialization and reuses the object register. Exact residuals, probes,
   and ruled-outs remain archived in build/W8FclCombineDraw_003146f0_body.c.txt. */
/* measured: MATCH (68B in the 80B window). The late dsll32/dsra32 into $a3 is the
   canonicalisation of an s8 CALLEE parameter (block-scope declaration; the
   file-scope prototype stays s32 for the matched callers) fed by the reload of
   the byte just stored (`*(s8 *)(obj + 0xC)`, store-forwarded from the $v1 park),
   which mwcc materialises in argument order; an (s8)/(s64) cast of the parameter
   is hoisted ahead of the loaded arguments instead (nd45). */
// FUN_003146F0
void func_003146f0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern void func_0011b480(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
    u8 *obj;

    obj = *(u8 **)(arg0 + 0x38);
    *(s32 *)(obj + 8) = arg1;
    *(s8 *)(obj + 0xC) = arg2;
    func_0011b480(*(u8 **)(obj + 4), 0, *(s32 *)(obj + 8), *(s8 *)(obj + 0xC));
}

















// FUN_00314740
void func_00314740(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xD) = arg1;
}

// FUN_00314750
void func_00314750(u8 *arg0, s8 arg1) {
    u8 *t;
    s64 sp38;
    f32 *p;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp38, (sp38 = iGpffffa908, p)));
    if (arg1 == 0) {
        func_0011bdc0((u8 *)*(u32 *)(t + 4));
    } else {
        func_0011bf10((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_003147D0
u32 func_003147d0(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38) + 4);
}

/* measured (C147E0 lane 2026-09-17): probe_variants 367 differing words reloc-masked with `#pragma optimization_level 1` wrapper (bare O2 body 369w via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003147e0 --candidate C147E0=docs/probe_archive/C147E0_003147e0_body.c`); fnalign retail 452 vs object 465 instrs (+13, +2.88% PASS) via fnalign --candidate /tmp/b147e0_o1.c --quiet; full pragma_sweep on banked floor: O1 367 <-- better, bare 369, O3/O4 393, schedule-on 394, peephole-off 413, O0 494. Signature (u8*,s8,s64,s16,s32,s32) per retail daddu/dsll24/dsra24 + 14ef0 addiu $7; local extern for 002b77d0(s16,s64,s16,s32,s64,s32,s64,s64,f32,s16,s32) inside body (no shared-top edit); s32 colours with lw; f32 spF0[4] for 29e0. Prior nd-156 body lost (bare INCLUDE_ASM, m2c seed does not compile); this is first compilable floor since. O3 wrapper measured 389w / 417 vs 449 (-7.1% short, FAIL, not banked). Wall remains rotation + normalization-placement per preserved note. */
// FUN_003147E0 NONMATCHING
#ifdef NON_MATCHING
#pragma optimization_level 1
void func_003147e0(u8 *arg0, s8 arg1, s64 arg2, s16 arg3, s32 arg4, s32 arg5) {
    extern void func_002b77d0(s16, s64, s16, s32, s64, s32, s64, s64, f32, s16, s32);
    s32 c15C;
    s32 c158;
    s32 c154;
    s32 c150;
    s32 c14C;
    s32 c148;
    s32 c144;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    f32 spF0[4];
    s64 spE8;
    s64 c0;
    u8 *t;
    u8 *h;
    u8 *q;
    u8 *q2;
    u8 *q3;
    u8 *q4;
    u8 *q5;
    u8 **slot;
    s64 v19;
    s64 v23;
    s64 v21;
    s64 v20;
    s64 v30;
    s16 temp_16;
    s16 temp_16_2;
    s16 temp_16_3;
    f32 f20;
    f32 f21;
    s32 i;
    s64 li;
    s64 lia;
    spE8 = arg2;
    t = *(u8 **)(arg0 + 0x38);
    v19 = (s8)arg1;
    c0 = (s16)(v19 * 5 + 0x66);
    v21 = (s16)arg3;
    if (v21 == 0x16C) {
        func_002b2970(&sp128, 67.0f, 175.0f);
        func_00314ef0(arg0, v19, sp128, 0x16C, arg4, arg5);
        return;
    }
    v23 = v19 * 2;
    temp_16 = (s16)(v23 + 0x1F4);
    func_002b7750(temp_16, 0x1AC);
    v20 = (s16)c0;
    v30 = v20 + 2;
    f20 = *((f32 *)&spE8 + 1);
    func_002b2970(&sp120, *(f32 *)&spE8, f20);
    func_002b2a60(&c15C, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16, sp120, 0x1AC, c15C, (s16)v30, arg5, 3, 3, 154.0f, arg4, func_00331560());
    temp_16_2 = (s16)(v23 + 0x1F5);
    func_002b7750(temp_16_2, 0x1AF);
    func_002b2970(&sp130, 258.0f + *(f32 *)&spE8, f20);
    func_002b2a60(&c158, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_16_2, sp130, 0x1AF, c158, (s16)v30, arg5, 3, 3, 154.0f, arg4, func_00331560());
    func_002b2970(&sp138, *(f32 *)&sp130 - 28.0f, *((f32 *)&sp130 + 1));
    temp_16_3 = (s16)(v19 + 0x2FB);
    func_002b7750(temp_16_3, 0x131);
    func_002b2970(&sp130, 266.0f + *(f32 *)&spE8, f20);
    func_002b2a60(&c154, 0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(temp_16_3, sp138, 0x131, c154, (s16)(v20 + 3), arg5, 3, 3, 153.0f, arg4, func_00331560());
    func_002b68d0(temp_16_3, 0xE, 0);
    h = func_0046d200(func_00331560(), 0x131);
    slot = (u8 **)(t + v19 * 4 + 0x258);
    q = func_002b81f0(*slot);
    *(f32 *)(q + 0) = *(f32 *)&sp138;
    *(f32 *)(q + 4) = *((f32 *)&sp138 + 1);
    f21 = func_0046b260(h);
    func_002b29e0((u8 *)spF0, f21, func_0046b2f0(h));
    q2 = func_002b81f0(*slot);
    *(f32 *)(q2 + 8) = spF0[0];
    *(f32 *)(q2 + 12) = spF0[1];
    *(f32 *)(q2 + 16) = spF0[2];
    *(f32 *)(q2 + 20) = spF0[3];
    q3 = func_002b81f0(*slot);
    *(s32 *)(q3 + 0x120) = (s32)v20;
    q4 = func_002b81f0(*slot);
    *(f32 *)(q4 + 0x18) = 152.0f;
    q5 = func_002b81f0(*slot);
    *(u8 *)(q5 + 0x124) = 0;
    func_0046d280(h);
    if (v21 == -1) {
        return;
    }
    if (v21 == 0x174) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + *(f32 *)&spE8;
        i = 0;
        while ((s16)i < 2) {
            li = (s64)(s16)i;
            lia = (s16)(li + 0x174);
            func_002b2970(&sp118, f20 + (f32)(li * 0x67), f21);
            func_002b2a60(&c150, 0xCC, 0xFF, 0xFF, 0xFF);
            func_002b77d0((s16)lia, sp118, (s16)lia, c150, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
            i = (s16)(i + 1);
        }
        return;
    }
    if ((func_00106330(0x1305) != 0) && (v21 == 0x160)) {
        v20 = v20 + 4;
        f21 = 4.0f + f20;
        f20 = 6.0f + *(f32 *)&spE8;
        func_002b2970(&sp110, f20, f21);
        func_002b2a60(&c14C, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x160, sp110, 0x160, c14C, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
        func_002b7750(0x2EB, 0x16F);
        func_002b2970(&sp108, 100.0f + f20, f21);
        func_002b2a60(&c148, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002b77d0(0x2EB, sp108, 0x16F, c148, (s16)v20, arg5, 3, 3, 152.0f, arg4, func_00331560());
        return;
    }
    func_002b2970(&sp100, 6.0f + *(f32 *)&spE8, 4.0f + f20);
    func_002b2a60(&c144, 0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0((s16)v21, sp100, (s16)v21, c144, (s16)(v20 + 4), arg5, 3, 3, 152.0f, arg4, func_00331560());
}
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003147e0);
#endif
/* measured: nd 156 cascades from two allocation/scheduling decisions in the first
   block: (1) retail allocates v22 (v17*2) to $s6 and the CSE'd v16+2 to $s7, mwcc
   b210 always reverses them; (2) retail normalizes v16 (dsll32/dsra32 in place) and
   computes v16+2 immediately after the func_002b7750 call, mwcc defers both to the
   func_002b77d0 arg materialization (v23 as a local — s16 or s32 — adds extra
   normalizations, nd 195). All later blocks cascade from these two. Tried v23
   local (s32 nd 147/156, s16 nd 195), inline (s16)(v16+2) (nd 156), slot reorder.
   Saved-register rotation + normalization-placement floor.
   Re-measured from the M2C draft this wave (nd 225 — m2c's transcription is far off;
   lever-1 finding: m2c's s64 arg3 is WRONG, the caller sets addiu $7,0x16C so the
   checked-in s32 4th param is correct; the 5th param (arg4) IS s64 — sd to stack).
   Floor confirmed. */
/* measured: raw M2C seed archived at build/EFCL2_00314ef0_body.c; no live C body. */
/* temporary body measurement */
// FUN_00314EF0 NONMATCHING
#ifdef NON_MATCHING
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
void func_00314ef0(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s64 arg4, s32 arg5) {
    M2C_UNK spD4;
    M2C_UNK spD8;
    M2C_UNK spDC;
    M2C_UNK unkspCC;
    M2C_UNK unkspFC;
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    f32 spD0;
    s64 spC8;
    f32 temp_f21;
    f32 temp_f21_2;
    s32 temp_18_4;
    s32 temp_22;
    s32 temp_30;
    s64 temp_16;
    s64 temp_17;
    s64 temp_18;
    s64 temp_18_2;
    s64 temp_18_3;
    s64 temp_23;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;

    spC8 = arg2;
    temp_30 = (s32)(M2C_FIELD(arg0, s32 *, 0x38));
    temp_17 = (s64) (arg1 << 0x38) >> 0x38;
    temp_22 = temp_17 * 2;
    temp_18 = (s64) ((temp_22 + 0x1F4) << 0x30) >> 0x30;
    func_002b7750((s16)temp_18, 0x1AC);
    temp_16 = (s64) (((s64) (((temp_17 * 5) + 0x66) << 0x30) >> 0x30) << 0x30) >> 0x30;
    temp_23 = temp_16 + 2;
    func_002b2970(&spF0, M2C_BITWISE(f32, spC8), unkspCC);
    func_002b2a60(&sp10C, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_18, spF0, 0x1AC, sp10C, (s64) (temp_23 << 0x30) >> 0x30, arg5, 3, 3, 0x43170000, arg4, func_00331560());
    temp_18_2 = (s64) ((temp_22 + 0x1F5) << 0x30) >> 0x30;
    func_002b7750((s16)temp_18_2, 0x1B3);
    temp_f21 = 217.0f + M2C_BITWISE(f32, spC8);
    func_002b2970(&spE8, temp_f21, unkspCC);
    func_002b2a60(&sp108, 0, 0, 0x66, 0xFF);
    func_002b77d0(temp_18_2, spE8, 0x1B3, sp108, (s64) (temp_23 << 0x30) >> 0x30, arg5, 3, 3, 0x43170000, arg4, func_00331560());
    func_002b2970(&spF8, temp_f21 - 28.0f, unkspCC);
    temp_18_3 = (s64) ((temp_17 + 0x2FB) << 0x30) >> 0x30;
    func_002b7750((s16)temp_18_3, 0x131);
    func_002b2a60(&sp104, 0x25, 0x2F, 0x94, 0xFF);
    func_002b77d0(temp_18_3, spF8, 0x131, sp104, (s64) ((temp_16 + 3) << 0x30) >> 0x30, arg5, 3, 3, 0x43160000, arg4, func_00331560());
    func_002b68d0((s16)temp_18_3, 0xE, 0);
    temp_18_4 = (s32)func_0046d200((u32)func_00331560(), 0x131);
    temp_2 = (u8 *)((temp_17 * 4) + temp_30);
    temp_2_2 = (u8 *)(func_002b81f0((u8 *)M2C_FIELD(temp_2, s32 *, 0x258)));
    M2C_FIELD(temp_2_2, f32 *, 0) = (f32) spF8;
    M2C_FIELD(temp_2_2, f32 *, 4) = unkspFC;
    temp_f21_2 = func_0046b260((u8 *)temp_18_4);
    func_002b29e0((u8 *)&spD0, temp_f21_2, func_0046b2f0((u8 *)temp_18_4));
    temp_2_3 = (u8 *)(func_002b81f0((u8 *)M2C_FIELD(temp_2, s32 *, 0x258)));
    M2C_FIELD(temp_2_3, f32 *, 8) = spD0;
    M2C_FIELD(temp_2_3, f32 *, 0xC) = spD4;
    M2C_FIELD(temp_2_3, f32 *, 0x10) = spD8;
    M2C_FIELD(temp_2_3, f32 *, 0x14) = spDC;
    M2C_FIELD(func_002b81f0((u8 *)M2C_FIELD(temp_2, s32 *, 0x258)), s32 *, 0x120) = (s32) temp_16;
    M2C_FIELD(func_002b81f0((u8 *)M2C_FIELD(temp_2, s32 *, 0x258)), f32 *, 0x18) = 149.0f;
    M2C_FIELD(func_002b81f0((u8 *)M2C_FIELD(temp_2, s32 *, 0x258)), s8 *, 0x124) = 0;
    func_0046d280((void *)temp_18_4);
    func_002b7750((s16)arg3, (s16)arg3);
    func_002b2970(&spE0, 6.0f + M2C_BITWISE(f32, spC8), 8.0f + unkspCC);
    func_002b2a60(&sp100, 0xCC, 0xFF, 0xFF, 0xFF);
    func_002b77d0(arg3, spE0, arg3, sp100, (s64) ((temp_16 + 4) << 0x30) >> 0x30, arg5, 3, 3, 0x43140000, arg4, func_00331560());
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314ef0);
#endif

/* measured: nd 0, object 740/window 752 (the final 12 retail bytes are zero
   tail padding ignored by verify). Exact recipe: retain raw arg1 in s0, use a
   u32 base for the normalized 16-bit index, and write the loop increment as
   i = (s16)(i + 1); addOff(index*2, (u32)t) supplies the retail offset-first
   c74 address. */
// FUN_00315310
void func_00315310(u8 *arg0, s64 arg1) {
    FclByte4 c7C;
    FclByte4 c78;
    FclByte4 c74;
    FclByte4 c70;
    FclByte4 c6C;
    s64 sp60;
    s32 i;
    u8 *t;
    u32 base;
    s64 raw;
    s32 off;
    u8 *p;

    raw = arg1;
    t = *(u8 **)(arg0 + 0x38);
    *(s16 *)(t + 0xB8) = 0x15D;
    *(s16 *)(t + 0xBA) = 0x15E;
    *(s16 *)(t + 0xBC) = 0x15F;
    if (func_00106330(0x1305) != 0) {
        *(s16 *)(t + 0xBA) = 0x160;
    }
    i = 0;
    base = (s16)raw;
    for (; (s16)i < 3; i = (s16)(i + 1)) {
        off = (s16)i * 2;
        func_002b2970(&sp60, 26.0f, (f32)((s16)i * 34 + 0x57));
        func_003147e0(arg0, (s8)(s16)i, sp60, *(s16 *)(t + off + 0xB8), (s16)(base + off), 0);
    }
    func_002b2a60(&c7C, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = c7C;
    func_002b2a60(&c78, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = c78;
    func_002b2a60(&c74, 0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150((s16)*(s16 *)(addOff(*(s8 *)(t + 0xB3) * 2, (u32)t) + 0xB8));
    *(FclByte4 *)(p + 0x85) = c74;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
        func_002b2a60(&c70, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2EB);
        *(FclByte4 *)(p + 0x85) = c70;
        }
    }
    func_002b2a60(&c6C, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = c6C;
}

// measured: nd N/A (draw-family, s64-param floor). 69x func_002b2970 + 30x 69f0 + 16x 6c30 + 18x 6150: the s64 arg1/arg2 params fed to the s32/s16 params of 6c30/69f0/6a70 make mwcc b210 emit a dsll32/dsra32 normalization at every call site (retail passes the raw reg); the shared externs are locked by matched callers (16e80/17240/17320/18f30/24f80/2f060). s64-param-normalization floor.
// FUN_00315600
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);

// measured: nd N/A (draw-family, s64-param floor). 53x 2970 + 19x 6c30 + 17x 6a70 + 18x 69f0 + 4x 6b40: same s64-arg-to-s32-param normalization floor as func_00315600; externs locked by matched callers. s64-param-normalization floor.
// FUN_00316470
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316470);

// FUN_00316E80
void func_00316e80(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, s8 arg8, s8 arg9, s8 arg10) {
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    f32 *b1;
    f32 *b2;
    f32 *b3;
    f32 *b4;
    f32 *b5;

    if ((s8)arg1 == 1) {
        b1 = D_006441C8;
        if ((s8)arg2 == 0) {
            func_002b2970(&sp88, b1[0], b1[1]);
            func_002b6c30(0x8B, sp88, 0xBC, 103.0f);
            func_002b6a70(0x8B, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8B, *(u8 *)(func_002b6150(0x8B) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg3 == 1) {
        b2 = D_006441D0;
        if ((s8)arg4 == 0) {
            func_002b2970(&sp80, b2[0], b2[1]);
            func_002b6c30(0x8C, sp80, 0xBC, 103.0f);
            func_002b6a70(0x8C, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8C, *(u8 *)(func_002b6150(0x8C) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg5 == 1) {
        b3 = D_006441C0;
        if ((s8)arg6 == 0) {
            func_002b2970(&sp78, b3[0], b3[1]);
            func_002b6c30(0x8A, sp78, 0xBC, 103.0f);
            func_002b6a70(0x8A, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8A, *(u8 *)(func_002b6150(0x8A) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if ((s8)arg7 == 1) {
        b4 = D_006441E0;
        if (arg8 == 0) {
            func_002b2970(&sp70, b4[0], b4[1]);
            func_002b6c30(0x8E, sp70, 0xBC, 103.0f);
            func_002b6a70(0x8E, 0, 0xFF, 0, 0xA, 0);
        } else {
            func_002b6a70(0x8E, *(u8 *)(func_002b6150(0x8E) + 0x6E), 0, 0, 0xA, 0);
        }
    }
    if (arg9 == 1) {
        b5 = D_006441D8;
        if (arg10 == 0) {
            func_002b2970(&sp68, b5[0], b5[1]);
            func_002b6c30(0x8D, sp68, 0xBC, 103.0f);
            func_002b6a70(0x8D, 0, 0xFF, 0, 0xA, 0);
            return;
        }
        func_002b6a70(0x8D, *(u8 *)(func_002b6150(0x8D) + 0x6E), 0, 0, 0xA, 0);
    }
}

// FUN_00317240
void func_00317240(u8 *arg0, s64 arg1, f32 fparg0) {
    s64 sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970(&sp18, b[0] + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18, 0xBC, 103.0f);
        func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
        func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
}

// FUN_00317320
void func_00317320(u8 *arg0, s64 arg1, f32 fparg0) {
    s64 sp18;
    f32 *b;

    b = D_00644C90;
    if (((s64)(arg1 << 0x38) >> 0x38) == 0) {
        func_002b2970(&sp18, 358.0f + fparg0, b[1]);
        func_002b6c30(0x1E4, sp18, 0xBC, 103.0f);
        func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
        func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
        return;
    }
    func_002b6a70(0x1E4, *(u8 *)(func_002b6150(0x1E4) + 0x6E), 0, 0, 0xA, 0);
}

// FUN_00317410
void func_00317410(u8 *arg0, s8 arg1) {
    FclByte4 sp6C;
    FclByte4 sp68;
    FclByte4 sp64;
    FclByte4 sp60;
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    FclByte4 sp4C;
    FclByte4 sp48;
    FclByte4 sp44;
    u8 *p;
    u8 *t;
    u8 *q;
    s32 v;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2a60(&sp6C, 0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp6C;
    q = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
    func_002b2a60(&sp68, 0xCC, 0xFF, 0xFF, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp68;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp64, 0xCC, 0xFF, 0xFF, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp64;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp60, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp60;
    }
    func_002b2a60(&sp5C, 0x25, 0x2F, 0x94, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp5C;
    func_0045af60(0, 0, 0, 0);
    switch (arg1) {
    case 0:
        *(s8 *)(t + 0xB3) = (s8)func_002b2cb0(*(s8 *)(t + 0xB3), 1, 2, 0, 2);
        break;
    case 1:
        *(s8 *)(t + 0xB3) = (s8)func_002b2d00(*(s8 *)(t + 0xB3), 1, 0, 2, 2);
        break;
    case 2:
    case 3:
    default:
        break;
    }
    func_002b2a60(&sp58, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = sp58;
    func_002b2a60(&sp54, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp54;
    func_002b2a60(&sp50, 0x2D, 0x2D, 0x2D, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp50;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp4C, 0x2D, 0x2D, 0x2D, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp4C;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp48, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp48;
    }
    func_002b2a60(&sp44, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp44;
}


// measured: nd N/A (not yet reconstructed). Retail's adda.s/msub.s sequence is ordinary single-precision arithmetic that plain C can emit; no VU0/COP2 opcode is present in this function's retail window.
// FUN_00317900
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);

/* measured: nd 427 — the FP-saved-register allocation differs and nothing
   source-shaped moves it. Retail spills the sp108 f32 local to its stack slot
   (swc1 0x108) and assigns FP saved regs in def order to [sp10C->$f23, v2->$f22,
   v1->$f21, v20->$f20, v24->$f24]; mwcc b210 keeps BOTH sp108/sp10C in saved FP
   regs ($f24/$f25, frame 0x110 vs retail 0x120, one extra swc1) and assigns
   [sp10C->$f25, sp108->$f24, v1->$f23, v2->$f22, v20->$f21, v24->$f20].
   Tried: declaration-order permutations of the f32 locals (sp108/sp10C/v1/v2/
   v20/v24 in all plausible orders), and fully inlining the 6.0f+sp108 /
   62.0f+sp10C / 33.0f+sp108 / 20.0f+sp108 / sp10C-44.0f expressions at the six
   2970 calls (mwcc CSEs them into the identical allocation) — all nd 427. The
   rest of the function (if/else chains, 6150/2970/68d0/6c30 chains, the
   adda.s/msub.s FPU-fusion expression (5.0f+sp108)-2.0f*(46b260(h)/10.0f), the
   FclByte4 copies) matches. FP saved-register rotation floor. */
/* measured (even lane 2026-09-17): 394 differing words via `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00318840` (GUARDED_SCORE func_00318840: 394); banked as guarded floor per 3% rule -- probe 394w via docs/probe_archive/EVEN_00318840_body.c, fnalign 194 edits, retail 444 vs object 457 (+13, +2.93% PASS). */
// FUN_00318840 NONMATCHING
#ifdef NON_MATCHING
void func_00318840(u8 *arg0, s64 arg1, s64 arg2, s32 arg3, s64 arg4) {
    FclByte4 c11C;
    FclByte4 c118;
    FclByte4 c114;
    FclByte4 c110;
    f32 sp10C;
    f32 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f24;
    s32 t16;
    s32 t17;
    s32 v18;
    u8 *t;
    u8 *p;
    u8 *h;
    f32 hval;
    f32 fmsub;
    t = *(u8 **)(arg0 + 0x38);
    t17 = (s8)arg2;
    t16 = t17 + 0x20D;
    p = func_002b6150((s16)t16);
    sp108 = *(f32 *)(p + 0x38);
    sp10C = *(f32 *)(p + 0x3C);
    v18 = (s16)(t17 * 2 + 0xDF);
    if ((s8)t17 == 6) {
        v18 = 0xEF;
    } else if ((s8)t17 == 7) {
        v18 = 0xEB;
    } else if ((s8)t17 == 8) {
        v18 = 0xED;
    }
    if (((s64)(arg1 << 0x38) >> 0x38) == *(s8 *)(t + 0xB4)) {
        p = func_002b6150(0x1DC);
        *(FclVec2 *)(p + 0x38) = (FclVec2){sp108, sp10C};
        f22 = 62.0f + sp10C;
        f21 = 6.0f + sp108;
        func_002b2970(&sp100, f21, f22);
        p = func_002b6150(0x216);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&sp100;
        f20 = 33.0f + sp108;
        func_002b2970(&spF8, f20, f22);
        p = func_002b6150(0x217);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF8;
        f24 = 20.0f + sp108;
        func_002b2970(&spF0, f24, f22);
        p = func_002b6150(0x218);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spF0;
        f22 = sp10C - 44.0f;
        func_002b2970(&spE8, f21, f22);
        p = func_002b6150(0x219);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE8;
        func_002b2970(&spE0, f20, f22);
        p = func_002b6150(0x21A);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spE0;
        func_002b2970(&spD8, f24, f22);
        p = func_002b6150(0x21B);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD8;
        f20 = iGpffff8360;
        *(f32 *)(func_002b6150((s16)v18) + 0xA0) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0xAC) = f20;
        *(f32 *)(func_002b6150((s16)v18) + 0x14) = 59.0f;
        *(s32 *)(func_002b6150((s16)v18) + 0x8) = 0xAB;
        h = func_0046d200(func_00331560(), (u32)v18);
        hval = func_0046b260(h);
        fmsub = (5.0f + sp108) - 2.0f * (hval / 10.0f);
        func_002b2970(&spD0, fmsub, sp10C - 3.0f);
        p = func_002b6150((s16)v18);
        *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spD0;
        func_0046d280(h);
        func_002b2a60(&c11C, 0xE0, 0xFF, 0x33, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c11C;
        /* reuse t17 */
        func_002b68d0((s16)t16, 0, 1);
        func_002b68d0((s16)(t17 + 0xF2), 0, 1);
        func_002b2970(&spC8, sp108 - 12.0f, 104.0f + sp10C);
        func_002b6c30((s16)(t17 + 0xFD), spC8, 0xAC, 59.0f);
        if (t17 < 6) {
            func_002b2970(&spC0, sp108 - 12.0f, 123.0f + sp10C);
            func_002b6c30(0xFC, spC0, 0xAC, 59.0f);
            func_002b2a60(&c118, 0xE0, 0xFF, 0x33, 0xFF);
            *(FclByte4 *)(func_002b6150(0xFC) + 0x85) = c118;
            return;
        }
        func_002b68d0(0xFC, 0, 1);
        return;
    }
    /* reuse t17 */
    func_002b68d0((s16)(t17 + 0xFD), 0, 1);
    func_002b68d0((s16)t16, 0, 0);
    t16 = t17 + 0xF2;
    func_002b68d0((s16)t16, 0, 0);
    func_002b2a60(&c114, 0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)t16) + 0x85) = c114;
    *(f32 *)(func_002b6150((s16)v18) + 0xA0) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0xAC) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0x14) = (f32)arg3;
    *(s32 *)(func_002b6150((s16)v18) + 0x8) = (s32)arg4 + 1;
    func_002b2970(&spB8, 6.0f + sp108, 4.0f + sp10C);
    p = func_002b6150((s16)v18);
    *(FclVec2 *)(p + 0x38) = *(FclVec2 *)&spB8;
    func_002b2a60(&c110, 0x42, 0x6E, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150((s16)v18) + 0x85) = c110;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00318840);
#endif

// FUN_00318F30
void func_00318f30(s16 arg0) {
    s16 var;
    u8 *p;
    f32 fv;
    FclVec2 sp40;
    FclByte4 sp4C;
    s64 sp38;

    var = (s16)(arg0 * 2 + 0xDF);
    if (arg0 == 6) {
        var = 0xEF;
    } else if (arg0 == 7) {
        var = 0xEB;
    } else if (arg0 == 8) {
        var = 0xED;
    }
    func_002b7750(0x2F2, (s16)(var + 1));
    p = func_002b6150(var);
    sp40 = *(FclVec2 *)(p + 0x38);
    func_002b2970(&sp38, sp40.x - 15.0f, sp40.y - 7.0f);
    func_002b6c30(0x2F2, sp38, 0xAB, 58.0f);
    func_002b6a70(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    *(f32 *)(func_002b6150(0x2F2) + 0xA0) = fv;
    *(f32 *)(func_002b6150(0x2F2) + 0xAC) = fv;
    func_002b2a60(&sp4C, 0xE0, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2F2) + 0x85) = sp4C;
}

// FUN_003190D0
s32 func_003190d0(u8 *arg0) {
    u8 *t;
    s16 i;

    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < *(s8 *)(t + 0xB5); i++) {
        if (*(s8 *)(t + 0xB4) != i) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(*(s16 *)(t + i * 10 + 0xC8) + 0x20D)) + 0x10), 1) == 1) {
                return 1;
            }
        }
    }
    return (s16)func_002b6970(*(s16 *)(func_002b6150(0x1DC) + 0x10), 1) == 1;
}
// measured: nd N/A (draw-family, s64-param floor). 22x 2970 + 16x 6150 + 16x 2a60 + 13x 6a70 + 8x 6af0: same s64-arg normalization floor as func_00315600; externs locked by matched callers. s64-param-normalization floor.
// FUN_003191C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003191c0);

// measured: nd N/A (draw-family, s64-param floor). 42x 2970 + 13x 6c30 + 14x 6a70 + 14x 6af0 + 15x 69f0 + 10x 68d0: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_0031AC10
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ac10);

// measured: nd N/A (draw-family, s64-param floor). 20+ 2970/6c30/6a70/69f0 with packed-float arg pairs (unk sp14C/sp64/sp6C read as f32 halves of s64 args): same s64-arg normalization + float-pair hoist floor as func_0031fa20 (nd 668). s64-param + float-pair floor.
// FUN_0031C2B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031c2b0);

// measured: nd N/A (draw-family, s64-param floor). Same packed-float + 6c30/69f0/6a70 pattern as func_0031c2b0/1fa20: s64-arg normalization + float-pair register hoist. s64-param + float-pair floor.
// FUN_0031CCE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031cce0);

// measured: nd 466 (1 attempt). Full C body correct in logic; retail keeps arg0-arg4
// in saved regs ($s0/$s4/$s6/$fp/$s7) and only extracts a1=(s8)arg1 once into $s1;
// mwcc b210 spills arg2/arg3/arg4 to the stack (frame 0xE0->0xC0) and re-extracts
// the s8 args at every site, rotating every loop/color-store register. All call
// shapes (1ddf0/2a30/ba970/75820/4ae50/4b810) match; pure saved-register
// allocation + s8-arg-extraction floor. */
/* measured: probe_variants 290 differing words reloc-masked (V1 best; V2 420 worse, V3/V4 290 tie batch); fnalign retail 494 vs object 493 instrs (1 short, within 3% PASS; 126 edits +3 reloc-only) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031d630 --candidate /var/tmp/cold31d630/v1.c --quiet`; live measure_guarded GUARDED_SCORE func_0031d630: 290. Prior file notes nd 466/194 and source-repo 271 were bare INCLUDE_ASM with no banked body (no archive); this is the first banked floor since bare. */
/* Walls (same rotation as prior notes, now at 290): t in $s2 vs $s1, v in $s1 vs $s2, ret/off/base/i/j rotation shifting every lbu/sb + lh base and loop slt; constants retail addiu +0xFF/+0xA5/+0xCC vs object addiu -1/-91/-52 (u8 vs s8 store choice neutral, v2 u8-0x5E worse 420) plus extra move $a1 for (s8)i CSE. All logic matches: outer 6970==0 gate, 11E==v dispatch to 31ddf0 1/0 + 34b810 1/0, both arg4==0 loops with 34ae50 &4>>2 gate and 2e4870+off12+i+0x14 lb test, arg2==v||arg3==v block with six FclByte4 chains and tail 275820 text call. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_0031d630 -o /var/tmp/cold31d630/m2c.c` (176 lines, (void*,s64x4) + s8/s16 residues de-noised to (u8*,s64,s64,s64,s64) + (s8) casts, FclByte4 groups, s16 v/i/j, base+off12 hoist per 3212e0 PTR lever, 34b810 local extern u8*(u8*)); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0031d630 --candidate V1=/var/tmp/cold31d630/v1.c` (290) driven by fnalign edit script (count first: 493/494 exact-ish, then shapes). */
/* Rounds: v1 290 (FclByte4 groups, s16 v/i/j with separate i/j, s8 0x6E -1 and s8/u8 0x5E per retail immediates, base+off12 hoist); v2 420 worse (inline t+v*4 base, u8 0x5E stores, single i reuse: 505/496 +367 edits); v3/v4 290 tie (declaration-order neutral: t/v swap and ret-first, all 290). Pragma sweep already measured on this family (loop_invariants neutral, common_subs off worse, schedule on worse per prior 271 note; rotation persists) so not re-swept. Stopped after two consecutive non-lowering rounds (v2 worse + v3/v4 tie batch). Banked v1 as guarded floor (within 3%, compiles clean under -DNON_MATCHING). */
// FUN_0031D630 NONMATCHING
#ifdef NON_MATCHING
void func_0031d630(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4) {
    FclByte4 cDC;
    FclByte4 cD8;
    FclByte4 cD4;
    FclByte4 cD0;
    FclByte4 cCC;
    FclByte4 cC8;
    FclByte4 cC4;
    FclByte4 cC0;
    FclByte4 cBC;
    FclByte4 cB8;
    extern u8 *func_0034b810(u8 *);
    u8 *t;
    s16 v;
    s16 i;
    s16 j;
    u8 *p;
    u8 *q;
    u8 *e;
    s32 ret;
    f32 f;
    t = *(u8 **)(arg0 + 0x38);
    v = (s8)arg1;
    if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(v + 0x21C)) + 0x10), 1) != 0) {
        return;
    }
    if (*(s16 *)(t + 0x11E) == v) {
        ret = func_0031ddf0(arg0, arg1, 1, 0xFF);
        *(s8 *)(func_0034b810(*(u8 **)(t + (s32)v * 4 + 0x21C)) + 0xF00) = 1;
        if ((s8)arg4 == 0) {
            u8 *base = t + (s32)v * 4;
            s32 off12 = (s32)v * 12;
            for (i = 0; (s16)i < (u16)func_0010b5b0(); i = (s16)(i + 1)) {
                e = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    func_002b2a60(&cDC, 0x2D, 0x2D, 0x2D, 0xFF);
                    p = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                    *(FclByte4 *)(p + 0x75) = cDC;
                    *(s8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)i) + 0x5E) = -1;
                    if (*(s8 *)(func_002e4870(0) + off12 + (s16)i + 0x14) > 0) {
                        func_002b2a60(&cD8, 0xCC, 0xFF, 0x33, 0xFF);
                        p = func_0034ae50(*(u8 **)(base + 0x154), (s8)i);
                        *(FclByte4 *)(p + 0x75) = cD8;
                    }
                }
            }
        }
    } else {
        ret = func_0031ddf0(arg0, arg1, 0, 0xFF);
        if (v >= *(s32 *)(func_002e4870(0) + 8)) {
            func_002b2a60(&cD4, 0x24, 0x3F, 0x9F, 0xFF);
            p = func_002b6150((s16)(v + 0x244));
            *(FclByte4 *)(p + 0x85) = cD4;
            q = func_002b6150((s16)(v + 0x238));
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            *(s8 *)(func_0034b810(*(u8 **)(t + (s32)v * 4 + 0x21C)) + 0xF00) = 0;
        }
        if ((s8)arg2 == v || (s8)arg3 == v) {
            s16 v22b = (s16)(v + 0x22B);
            s16 v21c = (s16)(v + 0x21C);
            func_002b2a60(&cD0, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150(v22b);
            *(FclByte4 *)(p + 0x85) = cD0;
            q = func_002b6150(v21c);
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            *(s8 *)(func_002b6150(v22b) + 0x6E) = -1;
            *(s8 *)(func_002b6150(v21c) + 0x6E) = -1;
            func_002b2a60(&cCC, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_002b6150((s16)(v + 0x244));
            *(FclByte4 *)(p + 0x85) = cCC;
            q = func_002b6150((s16)(v + 0x238));
            *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
            func_002b2a60(&cC8, 0x8C, 0xE2, 0xFF, 0xFF);
            p = func_0034ae50(*(u8 **)(t + 0x188), arg1);
            *(FclByte4 *)(p + 0x75) = cC8;
            func_002b2a60(&cC4, 0, 0, 0x66, 0xFF);
            p = func_002b6150((s16)(v + 0x39));
            *(FclByte4 *)(p + 0x85) = cC4;
            ret = func_002b2a30(0, 0, 0x66, 0xFF);
            func_002b2a60(&cC0, 0, 0, 0x66, 0xFF);
            func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, *(s32 *)&cC0);
        }
        if ((s8)arg4 == 0) {
            u8 *base = t + (s32)v * 4;
            s32 off12 = (s32)v * 12;
            for (j = 0; (s16)j < (u16)func_0010b5b0(); j = (s16)(j + 1)) {
                e = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                if (((*(s16 *)e & 4) >> 2) == 0) {
                    func_002b2a60(&cBC, 0, 0, 0x99, 0xA5);
                    p = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                    *(FclByte4 *)(p + 0x75) = cBC;
                    *(s8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)j) + 0x5E) = 0xA5;
                    if (*(s8 *)(func_002e4870(0) + off12 + (s16)j + 0x14) > 0) {
                        func_002b2a60(&cB8, 0x49, 0x72, 0xFF, 0xA5);
                        p = func_0034ae50(*(u8 **)(base + 0x154), (s8)j);
                        *(FclByte4 *)(p + 0x75) = cB8;
                        *(s8 *)(func_0034ae50(*(u8 **)(base + 0x154), (s8)j) + 0x5E) = 0xCC;
                    }
                }
            }
        }
    }
    if (v < *(s32 *)(func_002e4870(0) + 8)) {
        f = (f32)((s32)v * 0x17 + 0x80);
        func_00275820(113.0f, f, 43.0f, ret, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)(func_002e48a0(0, (s16)v) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031d630);
#endif

/* measured: nd 194 — the whole body (both branches, all copy chains, call
   shapes) matches except a fixed saved-register rotation (6-declaration-order
   probe batch, all nd 194): retail allocates arg1->$s3, t->$s2, v17->$s1,
   v16a->$s0, v22->$s6, v20->$s4, chain->$s5, arg3->$s7; mwcc b210 always emits
   arg1->$s4, t->$s3, v17->$s2, v16a->$s1, v22->$s0, chain->$s5, arg3->$s6.
   Also the v20=0xFF / v16b=0x66 constants: retail materializes addiu +0xFF,
   normalizes with andi (u8 semantics) and keeps the value in a saved register
   across the second 6150 jal; mwcc always emits addiu -1 and re-materializes
   per use (the explicit &= 0xFF is DCE'd; (s8)(v20 & 0xFF) is constant-folded).
   Everything else — the FclByte4 copy chains (0x75/0x85 offsets), the
   (s8)arg1/(s16) casts, 2ba970/2a30/34ae50 calls, the andi after the first sb —
   reproduces exactly. Saved-register rotation + constant-materialization
   floor. */
/* measured (source repo): probe_variants 271 differing words; live verify obj 1292/window 1328 normalized_diff 863. Prior best in file nd 194. Pragmas on this exact body: loop_invariants 271->271 neutral, common_subs off 271->304 worse, schedule on 271->296 worse; rotation persists, so the saved-register rotation plus 0xFF/0x66 constant materialization (addiu+andi vs addiu-1) stand as measured walls. Widths verified: (s8)arg1 lb, (s16) casts for 6150 args, FclByte4 chains at 0x75/0x85, sb 0x6E plus andi; 2ba970 per source (s16,u32) externs and 2a30 per source (u8 x4) externs. Both arg2==1/else branches with 34ae50/2ba970/2a30 calls reproduce. Body re-derived from retail/IDA. Parked as floor. */
// FUN_0031DDF0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0031ddf0(u8 *arg0, s64 arg1, s8 arg2, s64 arg3) {
    FclByte4 cBC;
    FclByte4 cB8;
    FclByte4 cB4;
    FclByte4 cB0;
    FclByte4 cAC;
    FclByte4 cA8;
    FclByte4 cA4;
    FclByte4 cA0;
    u8 *t;
    s16 v16;
    s16 v17;
    s16 v18;
    u8 *p;
    u8 *q;
    s32 ret;

    t = *(u8 **)(arg0 + 0x38);
    if (arg2 == 1) {
        v16 = (s8)arg1;
        v17 = (s16)((s8)arg1 + 0x22B);
        v18 = (s16)((s8)arg1 + 0x21C);
        *(s8 *)(func_002b6150(v17) + 0x6E) = -1;
        *(s8 *)(func_002b6150(v18) + 0x6E) = -1;
        func_002b2a60(&cBC, 0xCC, 0xFF, 0x33, 0xFF);
        p = func_0034ae50(*(u8 **)(t + 0x188), arg1);
        *(s32 *)(p + 0x75) = *(s32 *)&cBC;
        q = func_002b6150((s16)(v16 + 0x244));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x75);
        p = func_002b6150((s16)(v16 + 0x238));
        *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(q + 0x85);
        q = func_002b6150(v17);
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        p = func_002b6150(v18);
        *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(q + 0x85);
        func_002b2a60(&cB8, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150((s16)(v16 + 0x250));
        *(FclByte4 *)(p + 0x85) = cB8;
        q = func_002b6150((s16)(v16 + 0x39));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        func_002b2a60(&cB4, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, *(s32 *)&cB4);
        ret = func_002b2a30(0x2D, 0x2D, 0x2D, (s32)arg3);
    } else {
        v16 = (s8)arg1;
        func_002b2a60(&cB0, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150((s16)(v16 + 0x22B));
        *(FclByte4 *)(p + 0x85) = cB0;
        q = func_002b6150((s16)(v16 + 0x21C));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        *(s8 *)(func_002b6150((s16)(v16 + 0x22B)) + 0x6E) = 0x66;
        *(s8 *)(func_002b6150((s16)(v16 + 0x21C)) + 0x6E) = 0x66;
        func_002b2a60(&cAC, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150((s16)(v16 + 0x244));
        *(s32 *)(p + 0x85) = *(s32 *)&cAC;
        q = func_002b6150((s16)(v16 + 0x238));
        *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
        func_002b2a60(&cA8, 0, 0, 0x99, 0xFF);
        *(s32 *)(func_0034ae50(*(u8 **)(t + 0x188), arg1) + 0x75) = *(s32 *)&cA8;
        func_002b2a60(&cA4, 0x8C, 0xE2, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)(v16 + 0x39)) + 0x85) = cA4;
        func_002b2a60(&cA0, 0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150((s16)(v16 + 0x250)) + 0x85) = cA0;
        func_002b2a60(&cBC, 0xCC, 0xFF, 0xFF, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s8)arg1, *(s32 *)&cBC);
        ret = func_002b2a30(0xCC, 0xFF, 0xFF, (s32)arg3);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ddf0);
#endif
// FUN_0031E320
void func_0031e320(u8 *arg0, s64 arg1) {
    s32 idx;
    s16 n1;
    s16 n2;
    s16 n3;
    s16 n4;
    u8 *work;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *q1;
    u8 *q2;
    FclByte4 c7C, c78, c74, c70, c6C;

    work = *(u8 **)(arg0 + 0x38);
    idx = (s8)arg1;
    n1 = (s16)(idx + 0x21C);
    p1 = func_002b6150(n1);
    func_002b2a60(&c7C, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n1, *(s32 *)(p1 + 0x85), *(s32 *)&c7C, 1, 6, 0);
    *(s8 *)(func_002b6150(n1) + 0x91) = 1;
    n2 = (s16)(idx + 0x22B);
    p2 = func_002b6150(n2);
    func_002b2a60(&c78, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n2, *(s32 *)(p2 + 0x85), *(s32 *)&c78, 1, 6, 0);
    *(s8 *)(func_002b6150(n2) + 0x91) = 1;
    n3 = (s16)(idx + 0x238);
    p3 = func_002b6150(n3);
    func_002b2a60(&c74, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n3, *(s32 *)(p3 + 0x85), *(s32 *)&c74, 1, 6, 0);
    *(s8 *)(func_002b6150(n3) + 0x91) = 1;
    n4 = (s16)(idx + 0x244);
    p4 = func_002b6150(n4);
    func_002b2a60(&c70, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b6b90(n4, *(s32 *)(p4 + 0x85), *(s32 *)&c70, 1, 6, 0);
    *(s8 *)(func_002b6150(n4) + 0x91) = 1;
    q1 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    q2 = func_0034ae50(*(u8 **)(work + 0x188), arg1);
    func_002b2a60(&c6C, 0xFF, 0xFF, 0x9E, 0xFF);
    func_002b8370(q1, *(s32 *)(q2 + 0x75), *(s32 *)&c6C, 1, 6, 0);
    *(s8 *)(func_0034ae50(*(u8 **)(work + 0x188), arg1) + 0x81) = 1;
}



// measured: nd N/A (draw-family, s64-param floor). 20+ 2970/6c30/6a70/6af0/69f0 with packed-float sp148 accumulator (M2C_BITWISE f32) and s64 args: same s64-arg normalization + float-pair hoist floor as func_0031fa20. s64-param + float-pair floor.
// FUN_0031E5B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);

/* measured: nd 668 (1 attempt). Retail keeps arg1 (a packed f32 pair, low=sp58
   high=sp5C) memory-resident and hoists only the high word into $f20, reloading
   the low word from sp58 at every use; mwcc b210 caches BOTH words in saved
   float regs ($f20-$f23), shrinking the frame 0x140->0x130 and rotating every
   call's arg setup. The s64 arg2/arg3 params also make mwcc emit a dsll32/dsra32
   normalization at every 6a70/69f0 call site (retail passes the raw reg).
   Float-pair register-hoist + s64-param-normalization floor. */
// FUN_0031FA20
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);

/* measured: nd 182-209 (4 attempts: FclVec2* base local 188, FclVec2* tbl+
   draft shapes 191, u8* tbl draft-exact 182, draft-exact + inline casts 209;
   the recorded nd-124 baseline did NOT reproduce with any spelling). Recipe B
   re-test FAILED for D_00644CA0: the typed pointer local IS materialized into a
   saved reg once (lui/addiu into $s0, matching retail's $16 hoist) but that one
   fix is drowned by two fixed codegen defects that no spelling removes: (1) the
   s64 arg1/arg2 parameters fed to the s32/s16 first params of 6c30/69f0/6a70
   make mwcc b210 emit a dsll32/dsra32 normalization pair at EVERY call site
   (retail passes the raw register, so the retail prototype must not have the
   s32/s16 params the tree's shared externs declare — cannot be tested without
   touching other matched callers); (2) storing the D_00643D70+idx*8 pointer
   into a saved register emits another dsll32/dsra32 pair (retail's addu is
   bare), from the s64 multiply intermediate. Plus the 2970-call arg-order
   swap (address vs addiu a0) from the func_00320970 note. All bodies are
   correct; object is 48-96B over window. Address-rematerialization + s64/s32
   conversion floor. */
/* measured: candidate archived at build/EFCL2_003205f0_body.c; object 964/window 896, normalized_diff 621. */
// FUN_003205F0
void func_003205f0(u8 *arg0, s64 arg1, s64 arg2) {
    extern void func_002b2970(u8 *, f32, f32);
    extern void func_002b6c30(s64, f2, s32, f32);
    extern void func_002b69f0(s64, f2, f2, u32, u32, s16);
    extern void func_002b6a70(s64, u8, u8, s32, s32, s32);
    extern void func_002b2a60(u8 *, s32, s32, s32, s32);
    extern u8 *func_002b6150(s64);
    extern void func_002b6140(u8 *, u8);
    f2 spA0;
    f2 sp98;
    f2 sp90;
    f2 sp88;
    f2 sp80;
    f2 sp78;
    f2 sp70;
    f2 sp68;
    f2 sp60;
    f2 sp58;
    f2 sp50;
    FclByte4 spAC;
    f2 *tbl1;
    f2 *tbl2;
    f2 *ca;
    s16 idx1;
    s16 idx2;
    u8 *obj;
    u8 *temp_2;

    obj = *(u8 **)(arg0 + 0x38);
    func_002b6140(*(u8 **)(obj + 0x28C), 0);
    func_002b6140(*(u8 **)(obj + 0x290), 0);
    idx1 = (s16)arg1;
    if (idx1 != 0) {
        tbl1 = (f2 *)&D_00643D70[idx1 * 2];
        func_002b2970((u8 *)&spA0, tbl1->x - 200.0f, tbl1->y);
        func_002b6c30(arg1, spA0, 0xAC, 54.0f);
        func_002b2970((u8 *)&sp98, tbl1->x - 200.0f, tbl1->y);
        func_002b2970((u8 *)&sp90, tbl1->x, tbl1->y);
        func_002b69f0(arg1, sp98, sp90, 0, 0xA, 0);
        func_002b6a70(arg1, 0, 0xFF, 0, 0xA, 0);
        if (idx1 == 0x92) {
            ca = (f2 *)D_00644CA0;
            func_002b2970((u8 *)&sp88, ca->x, ca->y);
            func_002b6c30(0x1E6, sp88, 0x65, 54.0f);
            func_002b2970((u8 *)&sp80, 58.0f, ca->y);
            func_002b2970((u8 *)&sp78, ca->x, ca->y);
            func_002b69f0(0x1E6, sp80, sp78, 0, 0xA, 3);
            func_002b6a70(0x1E6, 0, 0xFF, 0, 0xA, 3);
            func_002b2a60((u8 *)&spAC, 0x49, 0x72, 0xFF, 0xFF);
            temp_2 = func_002b6150(0x1E6);
            *(FclByte4 *)(temp_2 + 0x85) = spAC;
        }
    }
    idx2 = (s16)arg2;
    if (idx2 != 0) {
        tbl2 = (f2 *)&D_00643D70[idx2 * 2];
        func_002b2970((u8 *)&sp70, tbl2->x, tbl2->y);
        func_002b6c30(arg2, sp70, 0xAC, 54.0f);
        func_002b2970((u8 *)&sp68, tbl2->x, tbl2->y);
        func_002b2970((u8 *)&sp60, 200.0f + tbl2->x, tbl2->y);
        func_002b69f0(arg2, sp68, sp60, 0, 0xA, 0);
        func_002b6a70(arg2, 0xFF, 0, 0, 0xA, 0);
        if (idx2 == 0x92) {
            ca = (f2 *)D_00644CA0;
            func_002b2970((u8 *)&sp58, ca->x, ca->y);
            func_002b2970((u8 *)&sp50, 122.0f, ca->y);
            func_002b69f0(0x1E6, sp58, sp50, 0, 6, 2);
            func_002b6a70(0x1E6, 0xFF, 0, 0, 6, 2);
        }
    }
}
// FUN_00320970
void func_00320970(u8 *arg0, s64 arg1) {
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    s64 sp48;
    s64 sp40;
    s64 sp38;
    s64 sp30;
    FclVec2 *p;

    p = (FclVec2 *)D_00644020;
    func_002b2970(&sp48, p->x, p->y);
    func_002b2a60(&sp5C, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x56, sp48, 0x56, *(s32 *)&sp5C, 0xAA, arg1, 6, 6, 55.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644098;
    func_002b2970(&sp40, p->x, p->y);
    func_002b2a60(&sp58, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x65, sp40, 0x65, *(s32 *)&sp58, 0xAA, arg1, 6, 6, 56.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644AD0;
    func_002b2970(&sp38, p->x, p->y);
    func_002b2a60(&sp54, 0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1AC, sp38, 0x1AC, *(s32 *)&sp54, 0xA9, arg1, 6, 6, 57.0f, 0, func_00331560());
    p = (FclVec2 *)D_00644B00;
    func_002b2970(&sp30, p->x, p->y);
    func_002b2a60(&sp50, 0xE, 0x17, 0x49, 0x80);
    func_002b77d0(0x1B2, sp30, 0x1B2, *(s32 *)&sp50, 0xA9, arg1, 6, 6, 58.0f, 0, func_00331560());
}

// measured: nd N/A (draw-family, s64-param floor). 2b2970/6c30/6a70/6af0/69f0/83e0 + 191c0/e5b0/ac10 calls with s64 args: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* measured (FclDrawB 2026-09-17): probe_variants 338 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00320b80 --candidate V1=/var/tmp/drawB/c20b80_v1.c`; fnalign retail 472 vs object 472 instrs exact (178 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00320b80 --candidate /var/tmp/drawB/c20b80_v1.c --quiet`; 0 short (0% within 3% rule). Signature (u8*,s8) per dsll24/dsra24 + callers (arg0,0/1); local externs for 002e4ac0(s32,s32) + 002b8200(u8*,s64,s32,f32,f32,f32) inside body (no shared-top edit); u8[4] colours; FclVec2 for 69f0; iGpffff8504 for 6af0. Prior N/A; this 338 is first measured floor. Wall remains s64-param + rotation per preserved note. */
// FUN_00320B80 NONMATCHING
#ifdef NON_MATCHING
void func_00320b80(u8 *arg0, s8 arg1) {
    extern void func_002e4ac0(s32, s32);
    extern void func_002b8200(u8 *, s64, s32, f32, f32, f32);
    u8 c14C[4];
    u8 c148[4];
    u8 c144[4];
    u8 c140[4];
    u8 c13C[4];
    u8 c138[4];
    u8 c134[4];
    u8 c130[4];
    u8 c12C[4];
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    u8 *spE4;
    s32 spD0;
    u8 *spC0;
    u8 *t;
    s32 i;
    t = *(u8 **)(arg0 + 0x38);
    spE4 = arg0;
    *(s16 *)(t + 0x11E) = 0;
    *(s8 *)(t + 0x128) = -1;
    spD0 = (s8)arg1;
    if ((s8)arg1 == 0) {
        func_002e4ac0(0, 0);
    }
    func_002b2970(&sp120, 16.0f, 104.0f);
    func_0031e5b0(spE4, sp120, 0, 0, 0, 0, 0);
    i = 0;
    while ((s16)i < (u16)func_0010b5b0()) {
        s32 m = (s16)i * 23;
        u16 w = *(u16 *)(func_002e48a0(0, (s16)i) + 2);
        u8 b = *(u8 *)(func_002e48a0(0, (s16)i) + 4);
        func_002b2970(&sp118, 16.0f, 128.0f);
        func_003191c0(spE4, sp118, (s8)i, w, b, (s16)(i * 2), 0, *(s8 *)(func_002e4870(0) + 8));
        {
            s16 m2 = (s16)((s16)i + 0x25E);
            u8 *h = (u8 *)func_0046d200(func_00331560(), 0x39);
            s32 m14e = m + 0x14E;
            func_002b2970(&sp110, (f32)m14e, 110.0f);
            func_002b6c30(m2, sp110, 0x56, 158.0f);
            func_002b2a60(c14C, 0x8C, 0xE2, 0xFF, 0xFF);
            {
                u8 *p = func_002b6150(m2);
                p[0x85] = c14C[0];
                p[0x86] = c14C[1];
                p[0x87] = c14C[2];
                p[0x88] = c14C[3];
            }
            func_002b6a70(m2, 0, 0xFF, 0, 2, (s16)i);
            func_002b6af0(m2, 0, 2, (s16)i, 1.0f, 1.0f, iGpffff8504, 1.0f);
            func_002b2970(&sp108, (f32)m14e, 110.0f + func_0046b2f0(h) / 2.0f);
            func_002b2970(&sp100, (f32)m14e, 110.0f);
            func_002b69f0(m2, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 2, (s16)i);
            func_0046d280(h);
        }
        {
            u8 *e = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
            func_002b2970(&spF8, (f32)(m + 0x149), 104.0f);
            func_002b2a60(c148, 0, 0, 0x99, 0xFF);
            func_002b2a60(c144, 0, 0, 0x99, 0xFF);
            func_002b83e0(e, spF8, *(s32 *)c148, *(s32 *)c144, 0xFF, 0xFF, 2, (s16)i, 32.0f, 159.0f, 0, 0);
        }
        if (spD0 == 0) {
            s32 j = 0;
            u8 *q = t + (s16)i * 4;
            spC0 = t + (s16)i * 12;
            while ((s16)j < (u16)func_0010b5b0()) {
                u8 *e2 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                func_002b2970(&spF0, (f32)((s16)j * 23 + 0x149), (f32)(m + 0x7F));
                func_002b2a60(c140, 0, 0, 0x99, 0xA5);
                func_002b8200(e2, spF0, *(s32 *)c140, 1.0f, 0.0f, 159.0f);
                {
                    u8 *e3 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                    func_002b2a60(c13C, 0, 0, 0x99, 0xFF);
                    func_002b2a60(c138, 0x49, 0x72, 0xFF, 0xFF);
                    func_002b8370(e3, *(s32 *)c13C, *(s32 *)c138, 0, 0xA, (s16)j + (s16)i);
                    func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), (s8)j), 0, 0xA5, 0, 0xA, (s16)j + (s16)i);
                }
                *(s8 *)(spC0 + (s16)j + 0x18C) = 0;
                j = (s16)(j + 1);
            }
        } else {
            s32 j = 0;
            u8 *q = t + (s16)i * 4;
            while ((s16)j < (u16)func_0010b5b0()) {
                u8 *e2 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                func_002b2970(&spE8, (f32)((s16)j * 23 + 0x149), (f32)(m + 0x7F));
                func_002b2a60(c134, 0, 0, 0x99, 0xA5);
                func_002b8200(e2, spE8, *(s32 *)c134, 1.0f, 0.0f, 159.0f);
                {
                    u8 *e3 = func_0034ae50(*(u8 **)(q + 0x154), (s8)j);
                    func_002b2a60(c130, 0x49, 0x72, 0xFF, 0xA5);
                    func_002b2a60(c12C, 0, 0, 0x99, 0xA5);
                    func_002b8370(e3, *(s32 *)c130, *(s32 *)c12C, 0, 0xA, (s16)j + (s16)i);
                    func_002b82d0(func_0034ae50(*(u8 **)(q + 0x154), (s8)j), 0, 0xA5, 0, 0xA, 0);
                }
                *(s8 *)(t + (s16)i * 12 + (s16)j + 0x18C) = 0;
                j = (s16)(j + 1);
            }
        }
        i = (s16)(i + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320b80);
#endif

/* Floor: 321 differing words (probe_variants docs/probe_archive/WIDE_003212e0_body.c) over 139 fnalign edits */
/* (+3 reloc-only), retail 368 vs object 375 (+7, frames 0xF0 vs 0x100). New dsll/dsra lever: s16 i/j -> s32 */
/* (331->321 words, 154->139 edits, 381->375 object). WALL remains slot-layout + scheduling (u8 groups alias, */
/* byte-copy interleave vs batched, var_16 4-instr vs clean pair, u8 arg1 andi, u_long128 widening). Base G */
/* body 331/154/381 (both archives exist and reproduce). */
/* Fresh 2026-09-17 PTR lever (this lane): u_long128 spC0/spB0 -> plain u8* (spC0=temp_18+(s32)var_16, spB0=temp_18+temp_22, temp_2=spB0+(s32)j, (s8*)(spC0+0x18C)) measures 317w over 136 fnalign edits (+3 reloc-only), retail 367 vs object 367 exact (frame fixed 0x100->0xF0) via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003212e0 --candidate PTR=/tmp/fcl3212_ptr.c` (WIDE 321 same command) and `python3 tools/fnalign.py ... --candidate /tmp/fcl3212_ptr.c --quiet`. FclByte4 struct lever on the same base fails to compile (u8[4] decays to u8* for 2b2a60, struct needs & + .bN; plus wrong shape lw/sw vs retail lbu/sb) -- documented in conventions above, not re-probed. 317 is the new measured best; WALL now slot-layout + scheduling minus widening (var_16/u8-arg1/byte-interleave remain). Production stays INCLUDE_ASM per floor policy; archives unchanged (WIDE still reproduces 321). */
/* measured (even lane 2026-09-17): 317 differing words via `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_003212e0` (GUARDED_SCORE func_003212e0: 317); banked as guarded floor per 3% rule -- probe 317w via docs/probe_archive/PTR_003212e0_body.c, fnalign 136 edits (+3 reloc), retail 367 vs object 367 exact (0%). */
/* 2026-09-18: the hand-written float-to-u8 conversion replaced by the plain
   cast.  Tie at 317 words, edit groups 136 -> 120. */
// FUN_003212E0 NONMATCHING
#ifdef NON_MATCHING
void func_003212e0(u8 *arg0, u8 arg1, s8 arg2) {
    u8 spD7;
    u8 spD8[4];
    u8 spDC[4];
    u8 spE0[4];
    u8 spE4[4];
    u8 spE8[4];
    u8 spEC[4];
    u8 *spC0;
    u8 *spB0;
    f32 temp_f0;
    f32 f20;
    f32 f15;
    s32 temp_7;
    s32 var_3;
    s64 var_16;
    s32 i;
    s32 j;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_21_3;
    u8 *cell2;
    s32 temp_22;
    spD7 = arg1;
    temp_18 = *(u8 **)(arg0 + 0x38);
    var_16 = (s64)(s16)(((u16)func_0010b5b0() - 1) + (((u16)func_0010b5b0() - 1) * 0xC));
    func_0010b5b0();
    func_0010b5b0();
    func_002b2a60(spE0, 0, 0, 0x99, 0xFF);
    spEC[0] = spE0[0];
    spEC[1] = spE0[1];
    spEC[2] = spE0[2];
    spEC[3] = spE0[3];
    func_002b2a60(spDC, 0x49, 0x72, 0xFF, 0xFF);
    spE8[0] = spDC[0];
    spE8[1] = spDC[1];
    spE8[2] = spDC[2];
    spE8[3] = spDC[3];
    func_002b2a60(spD8, 0x49, 0x72, 0xFF, 0xFF);
    spE4[0] = spD8[0];
    spE4[1] = spD8[1];
    spE4[2] = spD8[2];
    spE4[3] = spD8[3];
    if (arg2 == 1) {
        func_002b2a60(spE8, 0, 0, 0x99, 0xFF);
        func_002b2a60(spEC, 0x49, 0x72, 0xFF, 0xFF);
        func_002b2a60(spE4, 0x49, 0x72, 0xFF, 0xFF);
        var_16 = 0;
    }
    spC0 = temp_18 + (s32)var_16;
    for (i = 0; (s16)i < (s32)(u16)func_0010b5b0(); i = (s16)(i + 1)) {
        j = 0;
        temp_22 = (s32)i * 0xC;
        spB0 = temp_18 + temp_22;
        temp_17 = temp_18 + ((s32)i * 4);
        for (; (s16)j < (s32)(u16)func_0010b5b0(); j = (s16)(j + 1)) {
            temp_2 = spB0 + (s32)j;
            if (*(s8 *)(temp_2 + 0x18C) == 0) {
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j) & 0x200) >> 9) == 0) {
                    func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j), *(s32 *)spE8, *(s32 *)spEC, 0, 2, 1);
                    if (*(s8 *)(func_002e4870(0) + temp_22 + (s32)j + 0x14) > 0) {
                        func_002b8370(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j), *(s32 *)spE8, *(s32 *)spE4, 0, 2, 1);
                        cell2 = func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j);
                        func_002b82d0(cell2, *(u8 *)(func_0034ae50(*(u8 **)(temp_17 + 0x154), (s64)(s8)j) + 0x5E), 0xCC, 0, 2, 1);
                    }
                    *(s8 *)(temp_2 + 0x18C) = 1;
                }
            } else if ((*(s8 *)(spC0 + 0x18C) == 1) && ((s32)var_16 == (j + temp_22))) {
                temp_21_3 = temp_18 + ((u16)func_0010b5b0() * 4);
                if (((*(s16 *)func_0034ae50(*(u8 **)(temp_21_3 + 0x150), (s64)(s8)((u16)func_0010b5b0() - 1)) & 0x200) >> 9) == 0) {
                    *(u8 *)(temp_18 + 1) = spD7;
                    if (*(s8 *)(temp_18 + 0x128) == -1) {
                        *(s16 *)(temp_18 + 0x11E) = 0;
                    }
                }
            }
        }
        f20 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)(i + 0x21C)) + 0x42);
        f15 = (f32)(s32)*(s16 *)((u8 *)func_002b6150((s16)(i + 0x21C)) + 0x40);
        temp_f0 = func_002b2aa0(0, 0.0f, 255.0f, f20, f15);
        var_3 = (u8)temp_f0;
        temp_7 = var_3 & 0xFF;
        if (*(s16 *)((u8 *)temp_18 + 0x11E) == i) {
            var_3 = func_002b2a30(0x2D, 0x2D, 0x2D, temp_7);
        } else {
            var_3 = func_002b2a30(0xCC, 0xFF, 0xFF, temp_7);
        }
        if ((s16)i < *(s32 *)((u8 *)func_002e4870(0) + 8)) {
            f20 = (f32)(s32)((s16)i * 0x17 + 0x80);
            func_00275820(113.0f, f20, 43.0f, var_3, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)((u8 *)func_002e48a0(0, i) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003212e0);
#endif

/* No banked body archived (docs/probe_archive/P01C_003218a0_body.c is a 1-line placeholder); retained as bare */
/* INCLUDE_ASM. Prior best-of-3 references a missing preserved body and is not currently reproducible with */
/* --candidate. WALL per prior shape work (preserved here for reuse): lwr/lwl 0x75/0x78 are */
/* plain *(u32 *)(p + 0x75) on heap func_0034ae50 results; sq/lq 0x120..0xC0 are mwcc spills of s32 */
/* loop-invariant locals (not source u_long128); residuals are loop-CSE of (s16)i normalize, m2 spill to 0x110 */
/* (frame 0x160 vs 0x170), and saved-reg rotation (arg1->$s6/t->$fp/v->$s7/i->$s5 vs $s5/$s7/$s6/$s2). */
/* Shapes that match: s32 v = (s16)arg1 raw to 6af0/69f0, sp16C..sp158 s32, 2a60 FclByte4 chains, inner if/else */
/* with 2e4870(0)+sp100+(s16)j+0x14 lb test, 83e0 6-call block, for(i=0;(s16)i<(u16)func_0010b5b0();i=(s16)(i+1)) */
/* with m=n*23, 25E/14E/7F constants, sq'd sp120 = v+3 reloaded as (s16) for 6a70. */
/* Fresh 2026-09-17 (this lane, last in order after 004941f0/00347c70/003212e0): no new source probing -- prior best-of-3 body still missing so no --candidate re-measurement possible (P01C placeholder still 1-line, verified). 3212e0 PTR lever in this same file applies verbatim here per the sq/lq spill line above: use s32/u8* locals, never source u_long128, for the 0x120..0xC0 slots (u_long128 would widen frame 0x170 further, same family as 3212e0 0xF0->0x100); lwr/lwl stay plain *(u32*)(p+0x75) per preserved shapes (do not re-try u8-byte or s32-index forms); guarded (u8)(s32)f where present uses the shared 2.1474836e9f idiom per conventions. Production stays INCLUDE_ASM; wall stands as documented (heap unaligned-load + loop-CSE/spill/saved-reg rotation). */
/* measured (FclDrawB 2026-09-17): probe_variants 264 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003218a0 --candidate V1=/var/tmp/drawB/c218a0_v1.c`; fnalign retail 366 vs object 357 instrs (206 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003218a0 --candidate /var/tmp/drawB/c218a0_v1.c --quiet`; 9 short (2.5% within 3% rule). Ports 003212e0 PTR lever (plain u8* for sq slots, never u_long128; u8[4] per-byte colours for lbu/sb; s32 v=(s16)arg1 raw to 6af0/69f0; iGpffff8504 for 6af0 7th arg). Prior best 273; this 264 is new best. Wall remains loop-CSE/spill/rotation per preserved note. */
// FUN_003218A0 NONMATCHING
#ifdef NON_MATCHING
void func_003218a0(u8 *arg0, s64 arg1) {
    u8 c16C[4];
    u8 c168[4];
    u8 c164[4];
    u8 c160[4];
    u8 c15C[4];
    u8 c158[4];
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s32 sp120;
    s32 sp110;
    s32 sp100;
    s32 spF0;
    u8 *spE0;
    u8 *spD0;
    u8 *spC0;
    u8 *t;
    s32 v;
    s32 i;
    s32 j;
    s32 m;
    s16 m2;
    u8 *h;
    u8 *e;
    u8 *p;
    t = *(u8 **)(arg0 + 0x38);
    v = (s16)arg1;
    sp120 = v + 3;
    i = 0;
    while ((s16)i < (s16)(u16)func_0010b5b0()) {
        m = (s16)i * 23;
        e = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
        func_002b2970(&sp150, (f32)(m + 0x149), 104.0f);
        func_002b2a60(c16C, 0, 0, 0x99, 0xFF);
        func_002b2a60(c168, 0, 0, 0x99, 0xFF);
        func_002b83e0(e, sp150, *(s32 *)c16C, *(s32 *)c168, 0xFF, 0xFF, 2, v, 32.0f, 159.0f, 0, 0);
        m2 = (s16)((s16)i + 0x25E);
        h = func_0046d200(func_00331560(), 0x39);
        func_002b6a70(m2, 0, 0xFF, 0, 0, (s16)sp120);
        func_002b6af0(m2, 0, 3, arg1, 1.0f, 1.0f, iGpffff8504, 1.0f);
        sp110 = m + 0x14E;
        func_002b2970(&sp148, (f32)sp110, 110.0f + func_0046b2f0(h) / 2.0f);
        func_002b2970(&sp140, (f32)sp110, 110.0f);
        func_002b69f0(m2, *(FclVec2 *)&sp148, *(FclVec2 *)&sp140, 0, 3, arg1);
        func_002b68d0(m2, 0, 0);
        func_0046d280(h);
        j = 0;
        p = t + (s16)i * 4;
        sp100 = (s16)i * 12;
        spF0 = m + 0x7F;
        while ((s16)j < (s16)(u16)func_0010b5b0()) {
            if (*(s16 *)(t + 0x11E) == (s16)i) {
                func_002b2a60(c164, 0x2D, 0x2D, 0x2D, 0xFF);
                e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                e[0x75] = c164[0];
                e[0x76] = c164[1];
                e[0x77] = c164[2];
                e[0x78] = c164[3];
                if (*(s8 *)(func_002e4870(0) + sp100 + (s16)j + 0x14) > 0) {
                    func_002b2a60(c160, 0xCC, 0xFF, 0x33, 0xFF);
                    e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                    e[0x75] = c160[0];
                    e[0x76] = c160[1];
                    e[0x77] = c160[2];
                    e[0x78] = c160[3];
                }
            } else {
                func_002b2a60(c15C, 0, 0, 0x99, 0xA5);
                e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                e[0x75] = c15C[0];
                e[0x76] = c15C[1];
                e[0x77] = c15C[2];
                e[0x78] = c15C[3];
                if (*(s8 *)(func_002e4870(0) + sp100 + (s16)j + 0x14) > 0) {
                    func_002b2a60(c158, 0x49, 0x72, 0xFF, 0xCC);
                    e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
                    e[0x75] = c158[0];
                    e[0x76] = c158[1];
                    e[0x77] = c158[2];
                    e[0x78] = c158[3];
                }
            }
            spE0 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b2970(&sp138, (f32)((s16)j * 23 + 0x149), (f32)spF0);
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spD0 = e;
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            spC0 = e;
            e = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b83e0(spE0, sp138, *(u32 *)(spD0 + 0x75), *(u32 *)(spC0 + 0x75), *(u8 *)(spD0 + 0x78), *(u8 *)(spC0 + 0x78), 3, v, 32.0f, *(f32 *)(e + 4), 0, 0);
            j = (s16)(j + 1);
        }
        i = (s16)(i + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003218a0);
#endif

// measured: nd N/A (ldr/ldl unaligned 8B loads + draw-family). M2C_ERROR on ldr/ldl at 0x28/0x2f; the 6c30/69f0/6a70 s64-arg normalization floor also applies. Unaligned-load + s64-param floor.
// FUN_00321E60
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00321e60);

// measured: nd N/A (draw-family, s64-param floor). 29x 6150 + 17x 2a60 + 12x 2970 + 8x 6a70 + 7x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_003233D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003233d0);

/* measured: nd 415 — two interlocked allocation defects; all call shapes (the
   191c0 u16/u8 params, ac10 10-arg stack call, e5b0, the FclByte4 copies, the
   loop conditions) match. (1) mask-CSE floor: mwcc b210 hoists the loop-invariant
   v0&0xFF / v1&0xFF masks into saved registers ($s3/$s4 + raw copies in $s7/$fp,
   frame 0x120 vs retail 0x100); retail re-issues andi per 6a70 call site. The
   6a70 params are u8 (conversion per call) yet the CSE persists. (2) loop-counter
   rotation: retail keeps i->$s2 with the (s16)i norm copy in $s0 and h->$s1;
   mwcc always emits i->$s0, norm->$s1, h->$s2. Fixed along the way: arg2 must be
   s32 (an s8 param makes mwcc pre-extend it into an extra saved reg for the e5b0
   arg), 191c0/ac10 4th/5th params are u16/u8 (s32 params add andi conversions).
   Mask-CSE + saved-reg rotation floor. */
/* measured (FclDrawB 2026-09-17): probe_variants 398 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00323d00 --candidate V1=/var/tmp/drawB/c23d00_v1.c`; fnalign retail 449 vs object 446 instrs (556 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00323d00 --candidate /var/tmp/drawB/c23d00_v1.c --quiet`; 3 short (0.7% within 3% rule). Signature (u8*,s32,s32) per callers (arg0,0/2,0/1) + wall arg2 s32; block-scope loop counters per Main lever; u8[4] colours; D_ arrays by word index. Prior best 415; this 398 is new best. Wall remains mask-CSE + rotation per preserved note. */
// FUN_00323D00 NONMATCHING
#ifdef NON_MATCHING
void func_00323d00(u8 *arg0, s32 arg1, s32 arg2) {
    u8 cFC[4];
    u8 cF8[4];
    u8 cF4[4];
    u8 cF0[4];
    u8 cEC[4];
    u8 cE8[4];
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    u8 *p;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    (void)t;
    func_002b2970(&spE0, 16.0f, 104.0f);
    func_0031e5b0(arg0, spE0, 0, arg2, 0, 1, 2);
    func_002b2970(&spD8, 313.0f, 104.0f);
    func_0031e5b0(arg0, spD8, 0, arg2, 1, 0, 0);
    {
        s32 k = 0;
        while (k < *(s32 *)(func_002e4870(1) + 8)) {
            u16 w = *(u16 *)(func_002e48a0(1, (s16)k) + 2);
            u8 b = *(u8 *)(func_002e48a0(1, (s16)k) + 4);
            func_002b2970(&spD0, 313.0f, 128.0f);
            func_003191c0(arg0, spD0, (s8)k, w, b, (s16)(k * arg1), arg2, *(s8 *)(func_002e4870(1) + 8));
            k++;
        }
    }
    {
        s32 k = 0;
        while (k < *(s32 *)(func_002e4870(0) + 8)) {
            u16 w = *(u16 *)(func_002e48a0(0, (s16)k) + 2);
            func_002b2970(&spC8, 16.0f, 128.0f);
            func_0031ac10(arg0, spC8, 0, (s8)k, w, *(u8 *)(func_002e48a0(0, (s16)k) + 4), (s16)(k * arg1), arg2, 1, 0xCC);
            k++;
        }
    }
    func_002b2970(&spC0, D_006440F8[0], D_006440F8[1]);
    func_002b6c30(0x71, spC0, 0x41, 138.0f);
    func_002b2a60(cFC, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x71);
    p[0x85] = cFC[0];
    p[0x86] = cFC[1];
    p[0x87] = cFC[2];
    p[0x88] = cFC[3];
    {
        s32 v0 = (1 - (s8)arg2) * 0xFF;
        s32 v1 = (s8)arg2 * 0xFF;
        func_002b6a70(0x71, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        func_002b2970(&spB8, D_006440F0[0], D_006440F0[1]);
        func_002b6c30(0x70, spB8, 0x41, 139.0f);
        func_002b2a60(cF8, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0x70);
        p[0x85] = cF8[0];
        p[0x86] = cF8[1];
        p[0x87] = cF8[2];
        p[0x88] = cF8[3];
        func_002b6a70(0x70, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        {
            s32 k = 0;
            while (k < 2) {
                s16 a = (s16)(k + 0x2BB);
                func_002b2970(&spB0, D_00644290[0] + (f32)(k * 0x139), D_00644290[1]);
                func_002b6c30(a, spB0, 0x41, 140.0f);
                func_002b2a60(cF4, 0x33, 0xCD, 0xFF, 0xFF);
                p = func_002b6150(a);
                p[0x85] = cF4[0];
                p[0x86] = cF4[1];
                p[0x87] = cF4[2];
                p[0x88] = cF4[3];
                func_002b6a70(a, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                {
                    s16 b2 = (s16)(k + 0x2BD);
                    func_002b2970(&spA8, D_00644298[0] + (f32)(k * 0x14A), D_00644298[1]);
                    func_002b6c30(b2, spA8, 0x41, 141.0f);
                    func_002b2a60(cF0, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(b2);
                    p[0x85] = cF0[0];
                    p[0x86] = cF0[1];
                    p[0x87] = cF0[2];
                    p[0x88] = cF0[3];
                    func_002b6a70(b2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                {
                    s16 c2 = (s16)(k + 0x2BF);
                    func_002b2970(&spA0, D_00644350[0] + (f32)(k * 0xE), D_00644350[1]);
                    func_002b6c30(c2, spA0, 0x41, 142.0f);
                    func_002b2a60(cEC, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(c2);
                    p[0x85] = cEC[0];
                    p[0x86] = cEC[1];
                    p[0x87] = cEC[2];
                    p[0x88] = cEC[3];
                    func_002b6a70(c2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                k++;
            }
        }
        func_002b2970(&sp98, 28.0f + D_00644350[0], D_00644350[1]);
        func_002b6c30(0xBC, sp98, 0x41, 142.0f);
        func_002b2a60(cE8, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0xBC);
        p[0x85] = cE8[0];
        p[0x86] = cE8[1];
        p[0x87] = cE8[2];
        p[0x88] = cE8[3];
        func_002b6a70(0xBC, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);
#endif

/* 00324410 body archived at build/WBFclCombineDraw_00324410_body.c.txt.
   Best complete candidate measured nd 118, object 616/624 after changing only
   func_002b7750's first parameter to s64 (the retained TU declaration);
   baseline helper declaration scored nd 249, object 612/624. The candidate
   matches the prologue, dispatch, all calls, and tail except for the FPU
   materialization block at offsets 0x11C-0x12C: retail emits
   [lwc1 y, lui 20.0f, mtc1, nop, add.s], while MWCC emits
   [lui 20.0f, mtc1, lwc1, add.s]. The missing nop makes the object eight
   bytes short and shifts the following branch/call rows. O1 (nd 421,
   object 640/624) and schedule-on (nd 408, object 536/624) were ruled out;
   ordinary source-order and pointer-pinning variants did not change nd 118.
   Caller-side width was also measured: retail entry uses direct
   daddu $s2,$a1 at 0x00324428 with no sign extension, but declaring arg1 s64
   scored nd 399, object 648/624; the first residual moved to 0x6C, where
   dsll32/dsra32 narrow arg1 for the still-s16 6150 call, and the same
   narrowing recurs at later s16-helper calls. A combined caller/helper-width
   probe (arg1 s64 plus s64 first params for 6150/68d0/69f0/6a70, with 6af0
   left s16) scored nd 117, object 616/624; it left the 6af0 narrowing pair
   at offsets 0x180/0x184. Widening 6af0 as well scored nd 249, object
   612/624. The s16 definition and original helper declarations are therefore
   retained; bare INCLUDE_ASM remains because nd 118 exceeds park threshold. */
/* measured: candidate archived at build/EFCL2_00324410_body.c; object 616/window 624, normalized_diff 118. */
// FUN_00324410
void func_00324410(u8 *arg0, s16 arg1, s8 arg2) {
    FclVec2 sp68;
    s64 sp60;
    s64 sp58;
    s64 sp50;
    f32 f20;
    f32 y;
    u8 *t;
    s32 v17;
    extern void func_002b69f0(s16, s64, s64, u32, u32, s16);

    t = *(u8 **)(arg0 + 0x38);
    sp68 = *(FclVec2 *)(t + 0x298);
    v17 = arg2;
    switch (*(s8 *)((u8 *)(v17 + (s32)t) + 0x294)) {
    case 0:
        if ((s64)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 2) == 1) { break; }
        func_002b7750(arg1, 0x1C7);
        func_002b68d0(arg1, 0, 0);
        if (v17 == 0) {
            func_002b2970(&sp60, 280.0f + sp68.x, sp68.y);
            func_002b69f0(arg1, *(s64 *)&sp68, sp60, 0, 0x32, 0);
        } else if (v17 == 1) {
            f20 = 20.0f + ((y = sp68.y), y);
            func_002b2970(&sp58, 280.0f + sp68.x, f20);
            func_002b2970(&sp50, sp68.x, f20);
            func_002b69f0(arg1, sp58, sp50, 0, 0x32, 0);
        }
        {
            extern void func_002b6af0(s16, f32, f32, f32, f32, u32, u32, s32);
            func_002b6af0(arg1, 1.0f, 2.0f, 1.0f, 1.0f, 0, 0, 0);
        }
        func_002b6a70(arg1, 0, 0xFF, 1, 0x32, 0);
        *(s8 *)(func_002b6150(arg1) + 0x73) = 1;
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 1;
        break;
    case 1:
        if ((s64)func_002b6970(*(s16 *)(func_002b6150(arg1) + 0x10), 1) == 1) { break; }
        *(s8 *)((u8 *)(v17 + (s32)t) + 0x294) = 0;
        break;
    case 2:
        func_002b68d0(arg1, 0, 1);
        break;
    }
}












// measured: nd N/A (draw-family, s64-param floor). 19x 6a70 + 19x 6150 + 19x 2970 + 17x 2a60 + 15x 6c30: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
/* measured: probe_variants 316 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 --candidate V4=/var/tmp/cold324680/v4.c`; fnalign retail 573 vs object 573 instrs exact (0 short, 0% within 3% rule) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 --candidate /var/tmp/cold324680/v4.c --quiet`; live measure_guarded GUARDED_SCORE func_00324680: 316. Prior file note nd N/A was bare INCLUDE_ASM with no banked body (no archive); this is the first banked floor since bare. */
/* Walls (same rotation+scheduling as siblings 31d630/32a960/23d00, now at 316): t in $s7 vs retail $s2, arg1 in $s4 vs $s0, arg2 in $s3 vs $s4, loop i/j and colour-temp rotation shifting every lbu/sb + lh base and loop slt; colour stores retail batched lbu/lbu/lbu then sb/sb/sb vs object interleaved lbu/sb per byte; D_ absolute lui/addiu + lwc1 pair vs object GP-relative plus FPR-colour swap (f0/f1) and cvt scheduling; 0xBC w0/w1 recompute matches retail re-materialisation (reuse would drop 8 instrs). */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00324680 -o /var/tmp/cold324680/m2c.c` (186 lines, (u8*,s64,s32) residues de-noised to (u8*,s32,s32) + (s8)/(s16) casts, u8[4] per-byte colours, FclByte4 for 2ba970 word, s16 i + s32 k with block-scope s16 a/b2/c2 per 23d00 lever, D_ arrays by word index, heap-chain p297/p28B/p27D per retail lbu/sb); `python3 -E -s tools/romwright_decompile.py func_00324680 -o /var/tmp/cold324680/rom.c` (230 lines, (ulonglong,short,ulonglong) residues, same chains confirmed); probe V4 316 driven by fnalign edit script (count first: 573/573 exact, then shapes). */
/* Rounds: v1 422 (direct 23d00 port with stack-to-heap colours); v2 353 (-69 via heap-to-heap p297/p28B/p27D chain); v3 488 worse (explicit s16 a1s hoist); v4 316 (-37 via w0/w1 recompute before 0xBC, count 573/573 exact); v5 377 worse (s16 k) + v6 316 tie (decl-order neutral) batch; v7 500 worse (s32 first loop) + v8 440 worse (double-truncation) batch. Stopped after two consecutive non-lowering rounds (v5/v6 + v7/v8). Banked v4 as guarded floor (exact count, compiles clean under -DNON_MATCHING). */
// FUN_00324680 NONMATCHING
#ifdef NON_MATCHING
void func_00324680(u8 *arg0, s32 arg1, s32 arg2) {
    extern void func_00316470(u8 *, s32, s32);
    extern f32 D_006443D8[];
    u8 c11C[4];
    u8 c118[4];
    FclByte4 c114;
    u8 c110[4];
    u8 c10C[4];
    u8 c108[4];
    u8 c104[4];
    u8 c100[4];
    u8 cFC[4];
    u8 cF8[4];
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s16 i;
    u8 *p;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    func_00316470(arg0, 0, arg2);
    func_002b2970(&spF0, 6.0f, 104.0f);
    func_0031e5b0(arg0, spF0, 0, arg2, 0, 1, 2);
    func_002b2970(&spE8, 315.0f, 104.0f);
    func_0031e5b0(arg0, spE8, 0, arg2, 1, 0, 0);
    for (i = 0; (s16)i < 12; i = (s16)(i + 1)) {
        u16 w = *(u16 *)(func_002e48a0(0, (s16)i) + 2);
        u8 b = *(u8 *)(func_002e48a0(0, (s16)i) + 4);
        func_002b2970(&spE0, 315.0f, 128.0f);
        func_003191c0(arg0, spE0, (s8)i, w, b, (s16)(i * arg1), arg2, *(s8 *)(func_002e4870(0) + 8));
    }
    func_002b2970(&spD8, 6.0f, 195.0f);
    {
        u16 w = *(u16 *)(func_002e48a0(1, 0) + 2);
        u8 b = *(u8 *)(func_002e48a0(1, 0) + 4);
        func_0031ac10(arg0, spD8, 0, 0, w, b, 0, arg2, 0, 0xCC);
    }
    if ((s8)arg2 == 0) {
        u8 *p297;
        u8 *p28B;
        u8 *p27D;
        func_002b2a60(c11C, 0xCC, 0xFF, 0x33, 0xFF);
        p297 = func_002b6150(0x297);
        p297[0x85] = c11C[0];
        p297[0x86] = c11C[1];
        p297[0x87] = c11C[2];
        p297[0x88] = c11C[3];
        p28B = func_002b6150(0x28B);
        p28B[0x85] = p297[0x85];
        p28B[0x86] = p297[0x86];
        p28B[0x87] = p297[0x87];
        p28B[0x88] = p297[0x88];
        p27D = func_002b6150(0x27D);
        p27D[0x85] = p28B[0x85];
        p27D[0x86] = p28B[0x86];
        p27D[0x87] = p28B[0x87];
        p27D[0x88] = p28B[0x88];
        p = func_002b6150(0x270);
        p[0x85] = p27D[0x85];
        p[0x86] = p27D[0x86];
        p[0x87] = p27D[0x87];
        p[0x88] = p27D[0x88];
        func_002b2a60(c118, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x2A3);
        p[0x85] = c118[0];
        p[0x86] = c118[1];
        p[0x87] = c118[2];
        p[0x88] = c118[3];
        func_002b2a60(&c114, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), *(s32 *)&c114);
    }
    func_002b2970(&spD0, D_006440F8[0], D_006440F8[1]);
    func_002b6c30(0x71, spD0, 0x41, 138.0f);
    func_002b2a60(c110, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x71);
    p[0x85] = c110[0];
    p[0x86] = c110[1];
    p[0x87] = c110[2];
    p[0x88] = c110[3];
    {
        s32 v0 = (1 - (s8)arg2) * 0xFF;
        s32 v1 = (s8)arg2 * 0xFF;
        func_002b6a70(0x71, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        func_002b2970(&spC8, D_006440F0[0], D_006440F0[1]);
        func_002b6c30(0x70, spC8, 0x41, 139.0f);
        func_002b2a60(c10C, 0x33, 0xCD, 0xFF, 0xFF);
        p = func_002b6150(0x70);
        p[0x85] = c10C[0];
        p[0x86] = c10C[1];
        p[0x87] = c10C[2];
        p[0x88] = c10C[3];
        func_002b6a70(0x70, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
        {
            s32 k = 0;
            while (k < 2) {
                s16 a = (s16)(k + 0x2BB);
                func_002b2970(&spC0, D_00644290[0] + (f32)(k * 0x139), D_00644290[1]);
                func_002b6c30(a, spC0, 0x41, 140.0f);
                func_002b2a60(c108, 0x33, 0xCD, 0xFF, 0xFF);
                p = func_002b6150(a);
                p[0x85] = c108[0];
                p[0x86] = c108[1];
                p[0x87] = c108[2];
                p[0x88] = c108[3];
                func_002b6a70(a, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                {
                    s16 b2 = (s16)(k + 0x2BD);
                    func_002b2970(&spB8, D_00644298[0] + (f32)(k * 0x14A), D_00644298[1]);
                    func_002b6c30(b2, spB8, 0x41, 141.0f);
                    func_002b2a60(c104, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(b2);
                    p[0x85] = c104[0];
                    p[0x86] = c104[1];
                    p[0x87] = c104[2];
                    p[0x88] = c104[3];
                    func_002b6a70(b2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                {
                    s16 c2 = (s16)(k + 0x2BF);
                    func_002b2970(&spB0, D_00644350[0] + (f32)(k * 0xE), D_00644350[1]);
                    func_002b6c30(c2, spB0, 0x41, 142.0f);
                    func_002b2a60(c100, 0x33, 0xCD, 0xFF, 0xFF);
                    p = func_002b6150(c2);
                    p[0x85] = c100[0];
                    p[0x86] = c100[1];
                    p[0x87] = c100[2];
                    p[0x88] = c100[3];
                    func_002b6a70(c2, v1 & 0xFF, v0 & 0xFF, 0, 0, 0);
                }
                k++;
            }
        }
        {
            s32 w0 = (1 - (s8)arg2) * 0xFF;
            s32 w1 = (s8)arg2 * 0xFF;
            func_002b2970(&spA8, 28.0f + D_00644350[0], D_00644350[1]);
            func_002b6c30(0xBC, spA8, 0x41, 142.0f);
            func_002b2a60(cFC, 0x33, 0xCD, 0xFF, 0xFF);
            p = func_002b6150(0xBC);
            p[0x85] = cFC[0];
            p[0x86] = cFC[1];
            p[0x87] = cFC[2];
            p[0x88] = cFC[3];
            func_002b6a70(0xBC, w1 & 0xFF, w0 & 0xFF, 0, 0, 0);
        }
    }
    func_002b2970(&spA0, D_006443D8[0], D_006443D8[1]);
    func_002b6c30(0xCD, spA0, 0x41, 143.0f);
    func_002b6a70(0xCD, ((s8)arg2 * 0xFF) & 0xFF, ((1 - (s8)arg2) * 0xFF) & 0xFF, 1, 0xF, 0);
    func_002b2a60(cF8, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0xCD);
    p[0x85] = cF8[0];
    p[0x86] = cF8[1];
    p[0x87] = cF8[2];
    p[0x88] = cF8[3];
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324680);
#endif

// FUN_00324F80
void func_00324f80(u8 *arg0, FclVec2 arg1, s32 arg2, s32 arg3) {
    s32 sp8C, sp88, sp84, sp80, sp7C;
    s64 sp70, sp68, sp60, sp58, sp50, sp48;
    s16 v17;
    f32 f20;

    v17 = (s8)arg2;
    if (v17 == 0) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xAA, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp70, arg1.x, arg1.y);
            func_002b6c30(0xAA, sp70, 0x41, 168.0f);
            func_002b2a60(&sp8C, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xAA) + 0x85) = *(FclByte4 *)&sp8C;
            func_002b6a70(0xAA, 0, 0xFF, 0, 6, 0);
        }
    } else if (v17 == 1) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xA9, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp68, arg1.x, arg1.y);
            func_002b6c30(0xA9, sp68, 0x41, 168.0f);
            func_002b2a60(&sp88, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xA9) + 0x85) = *(FclByte4 *)&sp88;
            func_002b6a70(0xA9, 0, 0xFF, 0, 6, 0);
        }
    }
    arg3 = (s8)arg3;
    if (arg3 == 1) {
        func_002b6a70(0xAD, 0xFF, 0, 0, 6, 0);
    } else {
        f20 = arg1.y;
        func_002b2970(&sp60, arg1.x, 176.0f + f20);
        func_002b6c30(0xAD, sp60, 0x41, 169.0f);
        if (v17 == 1) {
            func_002b2970(&sp58, arg1.x, 194.0f + f20);
            func_002b6c30(0xAD, sp58, 0x41, 169.0f);
        }
        func_002b2a60(&sp84, 0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(0xAD) + 0x85) = *(FclByte4 *)&sp84;
        func_002b6a70(0xAD, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB1, 0xFF, 0, 0, 6, 0);
    } else {
        func_002b2970(&sp50, arg1.x, arg1.y);
        func_002b6c30(0xB1, sp50, 0x56, 166.0f);
        func_002b2a60(&sp80, 0x49, 0x72, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0xB1) + 0x85) = *(FclByte4 *)&sp80;
        func_002b6a70(0xB1, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB5, 0xFF, 0, 0, 6, 0);
        return;
    }
    func_002b2970(&sp48, arg1.x, 52.0f + arg1.y);
    func_002b6c30(0xB5, sp48, 0x56, 167.0f);
    func_002b2a60(&sp7C, 0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0xB5) + 0x85) = *(FclByte4 *)&sp7C;
    func_002b6a70(0xB5, 0, 0xFF, 0, 6, 0);
}

// measured: nd N/A (largest, 16064 B; draw-family + 12 M2C_ERROR). Heavy 2970/6c30/6a70/69f0 + unaligned/vector opcodes; s64-arg normalization floor. s64-param + misc-opcode floor.
// FUN_00325450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00325450);

/* measured: nd 259 — one large saved-register allocation cascade, decl-order
   insensitive (6-candidate probe, all nd 259): retail reuses t's $s0 for v16 and
   keeps arg2 in $s3, v23 in $s7, v30 in $fp, and the (s16)v17 test temp in $v1
   (dies before the jal, slti reads it); mwcc b210 always keeps t in $s0, moves
   v16 to $s3, spills arg2, puts v23 in $fp and spills v30, and CSEs the loop
   increment onto the test temp (forcing $s1 saved) with the slti on the raw
   value. Also: the spD8->spE8 FclVec2 copy compiles interleaved
   (load-store-load-store) or merged/ld-sd instead of retail's
   load-load-store-store lwc1/swc1 batch, and the f20 y-load is hoisted above
   the 9.0f lui with an addiu+lwc1 pair instead of retail's lui/mtc1/lwc1
   direct-offset order. Everything else reproduces exactly: both loops' shapes,
   the v18==0x14B->0x14C adjust, 61*v21 and i2*3 strength reductions, the
   (s16)((s16)x+0xF1)+0x1F4 double-truncation pattern, D_007495C0/D_00749600
   absolute array addressing, the 3x func_002b77d0 11-arg calls with sp0/sp8
   s64 stack args, the >=3 && !=12 if/else branch layout. Saved-register
   rotation + load-scheduling floor. */
/* measured: declarations corrected for func_002b6150(s16), func_002b2970(void *, f32, f32), func_002b68d0(s16, s16, s8), func_002b2a60(void *, s32, s32, s32, s32), and func_002b7750(s16, s16). Best preserved body measured nd 322 (object 0xE0, retail window 0x4E0); archived at build/WFclCombineDraw_00329310_body.c.txt. Retained as bare INCLUDE_ASM because the body remains a reconstruction near-miss. */
/* measured (source repo): probe_variants 249 differing words; live verify obj 1224/window 1248 normalized_diff 802. Prior best in file nd 259. Pragmas on this exact body: loop_invariants 249->250 neutral, common_subs off 249->315 worse, schedule on 249->280 worse; rotation persists, so the saved-register cascade plus load-scheduling stand as measured walls. Widths verified: (s16)/(s8) casts per retail dsll/dsra, lwc1/swc1 FclVec2 stores, D_007495C0/D_00749600 as D_[v17] word-index absolute addressing (reusable). All chains reproduce: 2970 prologue with f21/f20 split, 14x 68d0 loop, 6150 stores, 2a60 groups, 11-arg 77d0 calls with 29.0f/25.0f, 68d0/7750 pairs, k*61 and k*3 strength reductions, >=3 && !=12 branch. Body re-derived from retail/IDA/M2C. Parked as floor. */
// FUN_00329310 NONMATCHING
#ifdef NON_MATCHING
void func_00329310(u8 *arg0, s64 arg1, s64 arg2) {
    FclByte4 cFC;
    FclByte4 cF8;
    FclByte4 cF4;
    FclByte4 cF0;
    s64 spD8;
    s64 spE0;
    f32 f21;
    f32 f20;
    s16 i;
    s16 v16;
    s16 v18;
    s16 v17;
    u8 *t;
    s16 k;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&spD8, 18.0f, 14.0f);
    f21 = *(f32 *)&spD8;
    f20 = *((f32 *)&spD8 + 1);
    v16 = (s16)(*(s8 *)(t + 0x122) - *(s16 *)(t + 0x120));
    for (i = 0; (s16)i < 14; i = (s16)(i + 1)) {
        func_002b68d0((s16)(i + 0x13F), 0, 1);
    }
    func_002b68d0(0x2E4, 0, 1);
    v17 = (s16)v16;
    k = 0;
    while ((s16)v17 < (s16)(v16 + 7)) {
        v18 = (s16)(v17 + 0x13F);
        if (v18 == 0x14B) {
            v18 = 0x14C;
        }
        func_002b2970(&spE0, 87.0f + f21 + (f32)(k * 61) + D_007495C0[v17], 9.0f + f20);
        *(FclVec2 *)(func_002b6150(v18) + 0x38) = *(FclVec2 *)&spE0;
        func_002b2a60(&cFC, 0xFF, 0xFF, 0xFF, 0xFF);
        func_002b77d0(v18, spE0, v18, *(s32 *)&cFC, 0xBD, arg2, arg1, 3, 29.0f, 0, func_00331560());
        func_002b68d0((s16)(k * 3 + 0x1F4), 0, 1);
        func_002b7750((s16)(k * 3 + 0x1F4), v18);
        func_002b2a60(&cF8, 0x2D, 0x2D, 0x2D, 0xFF);
        func_002b77d0((s16)(k * 3 + 0x1F4), spE0, v18, *(s32 *)&cF8, 0xBF, arg2, arg1, 3, 25.0f, 0, func_00331560());
        if ((s16)v17 >= 3 && (s16)v17 != 12) {
            func_002b2970(&spE0, *(f32 *)&spE0 + D_00749600[v17], 15.0f + *((f32 *)&spE0 + 1));
            func_002b7750((s16)(k * 3 + 0x1F5), 0x14B);
            func_002b2a60(&cF4, 0xFF, 0xFF, 0xFF, 0xFF);
            func_002b77d0((s16)(k * 3 + 0x1F5), spE0, 0x14B, *(s32 *)&cF4, 0xBD, arg2, arg1, 3, 29.0f, 0, func_00331560());
            func_002b7750((s16)(k * 3 + 0x1F6), 0x14B);
            func_002b2a60(&cF0, 0x2D, 0x2D, 0x2D, 0xFF);
            func_002b77d0((s16)(k * 3 + 0x1F6), spE0, 0x14B, *(s32 *)&cF0, 0xBF, arg2, arg1, 3, 25.0f, 0, func_00331560());
        } else {
            func_002b68d0((s16)(k * 3 + 0x1F5), 0, 1);
            func_002b68d0((s16)(k * 3 + 0x1F6), 0, 1);
        }
        v17 = (s16)(v17 + 1);
        k = (s16)(k + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329310);
#endif
/* Draft docs/probe_archive/P01C_003297f0_body.c measures 325 differing words (probe_variants) over 251 fnalign */
/* edits, object 257 vs retail 400 (143 short, 36% short, not bankable as floor per 3% rule). Retained as bare */
/* INCLUDE_ASM. Prior full-body rebuild is gone (no archive). WALL per prior work: */
/* f32* q lands in saved reg once but FIRST use rematerialized in $v0 (frame 0xE0->0xF0); five ldr/ldl 0x38/0x3F */
/* not reproducible (plain ld for s64 reads at 8-aligned displacements; struct-by-value blocked by shared s64 */
/* extern of func_002b69f0); (s8)arg2 split to $s1/$s2 vs retail in-place; spDC hoisted to $s4 vs reload. */
/* All 2970/6c30/2a60/6150/69f0 chains, f12 pass-through, switch and branch shapes byte-correct. */
/* measured (even lane 2026-09-17): 356 differing words via `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_003297f0` (GUARDED_SCORE func_003297f0: 356); banked as guarded floor per 3% rule -- probe 356w via docs/probe_archive/EVEN_003297f0_body.c, fnalign 151 edits, retail 404 vs object 414 (+10, +2.48% PASS). */
// FUN_003297F0 NONMATCHING
#ifdef NON_MATCHING
void func_003297f0(u8 *arg0, s64 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    FclByte4 cDC;
    FclByte4 cD8;
    s64 spD0;
    s64 spC8;
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 t16;
    s64 t4;
    u8 *p;
    u8 *q;
    func_002b2970(&spD0, fparg0, D_006440B8[1]);
    t16 = (s64)((s64)arg2 << 0x38) >> 0x38;
    if (t16 == 0) {
        func_002b6c30(0x69, spD0, 0x56, 132.0f);
        func_002b2a60(&cDC, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x69);
        *(FclByte4 *)(p + 0x85) = cDC;
        func_002b2970(&spC0, *(f32 *)&spD0 + fparg1, D_006440B8[1]);
        func_002b2970(&spB8, *(f32 *)&spD0, D_006440B8[1]);
        func_002b69f0(0x69, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 8, 0);
    } else {
        p = func_002b6150(0x69);
        func_002b2970(&spB0, *(f32 *)&spD0 + fparg1, D_006440B8[1]);
        func_002b69f0(0x69, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spB0, 0, 8, 0);
    }
    func_002b2970(&spC8, 17.0f + *(f32 *)&spD0, 9.0f + *((f32 *)&spD0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x1AD, spC8, 0x41, 135.0f);
        func_002b2a60(&cD8, 0xE, 0x17, 0x49, 0xFF);
        q = func_002b6150(0x1AD);
        *(FclByte4 *)(q + 0x85) = cD8;
        *(u8 *)(func_002b6150(0x1AD) + 0x6E) = 0x80;
        func_002b2970(&spA8, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x1AD, *(FclVec2 *)&spA8, *(FclVec2 *)&spC8, 0, 8, 0);
    } else {
        p = func_002b6150(0x1AD);
        func_002b2970(&spA0, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x1AD, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spA0, 0, 8, 0);
    }
    t4 = (s64)(arg1 << 0x38) >> 0x38;
    switch ((s8)t4) {
    case 0:
        func_002b2970(&spC8, 67.0f + *(f32 *)&spD0, 13.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x109, spC8, 0x56, 134.0f);
            func_002b2970(&sp98, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x109, *(FclVec2 *)&sp98, *(FclVec2 *)&spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x109);
            func_002b2970(&sp90, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x109, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp90, 0, 8, 0);
        }
        func_002b2970(&spC8, 95.0f + *(f32 *)&spD0, 15.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x10A, spC8, 0x56, 133.0f);
            func_002b2970(&sp88, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x10A, *(FclVec2 *)&sp88, *(FclVec2 *)&spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x10A);
        func_002b2970(&sp80, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x10A, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp80, 0, 8, 0);
        return;
    case 1:
        func_002b2970(&spC8, 114.0f + *(f32 *)&spD0, 11.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x11C, spC8, 0x56, 134.0f);
            func_002b2970(&sp78, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11C, *(FclVec2 *)&sp78, *(FclVec2 *)&spC8, 0, 8, 0);
        } else {
            p = func_002b6150(0x11C);
            func_002b2970(&sp70, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11C, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp70, 0, 8, 0);
        }
        func_002b2970(&spC8, 50.0f + *(f32 *)&spD0, 16.0f + *((f32 *)&spD0 + 1));
        if (t16 == 0) {
            func_002b6c30(0x11B, spC8, 0x56, 133.0f);
            func_002b2970(&sp68, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
            func_002b69f0(0x11B, *(FclVec2 *)&sp68, *(FclVec2 *)&spC8, 0, 8, 0);
            return;
        }
        p = func_002b6150(0x11B);
        func_002b2970(&sp60, *(f32 *)&spC8 + fparg1, *((f32 *)&spC8 + 1));
        func_002b69f0(0x11B, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&sp60, 0, 8, 0);
        return;
    default:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003297f0);
#endif
// measured: nd N/A (ldr/ldl + COP2). M2C_ERROR on ldr/ldl 0x38/0x3f and adda.s; draw-family s64-arg normalization floor. Unaligned-load + COP2 + s64-param floor.
// FUN_00329E40
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);

/* measured: nd 356 — the frame stays 0x60 vs retail 0x70 because mwcc b210
   refuses two saved values: (1) the per-block 0x66 constant (sb p+0x6E + 6a70
   arg) is sunk AFTER the second func_002b6150 jal into a dead temp ($a2), while
   retail materializes addiu $s1,0x66 BEFORE the jal and keeps it in $17 across
   it — tried named s32 local and inline 0x66, both sink; (2) the 11.0f+sp50.x
   value used by both the 0x2E2 and 0x2E3 2970 calls is coalesced onto the dead
   f21 register instead of retail's fresh $f22. Also the sp40->sp50 FclVec2 copy
   never reproduces retail's batched lwc1/lwc1/swc1/swc1 (struct assignment gives
   ld/sd, field-wise and cast forms give interleaved load-store-load-store).
   Everything else reproduces exactly: all 6 if/else blocks' 6c30/2a60/6150/
   FclByte4-copy/6a70 sequences, the (f32)0x125/(f32)0x11D cvt.s.w idiom, the
   1.0f swc1s at 0xAC/0xA0, 7750(0x2E2,0x9E)/7750(0x2E3,0xA0), 6d60, else-branch
   lbu p+0x6E args. Saved-register rotation + load-scheduling floor. */
/* measured (FclDrawB 2026-09-17): probe_variants 311 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0032a960 --candidate V1=/var/tmp/drawB/c2a960_v1.c`; fnalign retail 421 vs object 421 instrs exact (76 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0032a960 --candidate /var/tmp/drawB/c2a960_v1.c --quiet`; 0 short (0% within 3% rule). Signature (u8* unused, s8) per retail daddu $16,$5 + dsll24/dsra24 + callers (arg0,0/1); u8[4] per-byte colours for lbu/sb; s64 2970 temps split to f32 pair via *(f32*)&sp. Prior best 356; this 311 is new best. Wall remains rotation + scheduling per preserved note. */
// FUN_0032A960 NONMATCHING
#ifdef NON_MATCHING
void func_0032a960(u8 *arg0, s8 arg1) {
    u8 c6C[4];
    u8 c68[4];
    u8 c64[4];
    u8 c60[4];
    u8 c5C[4];
    u8 c58[4];
    s64 sp40;
    s64 sp48;
    f32 f50;
    f32 f54;
    f32 f21;
    f32 f22;
    u8 *p;
    (void)arg0;
    func_002b2970(&sp40, 22.0f, 78.0f);
    f50 = *(f32 *)&sp40;
    f54 = *((f32 *)&sp40 + 1);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x9E, sp40, 0xC1, 15.0f);
        func_002b2a60(c6C, 0, 0, 0, 0xFF);
        p = func_002b6150(0x9E);
        p[0x85] = c6C[0];
        p[0x86] = c6C[1];
        p[0x87] = c6C[2];
        p[0x88] = c6C[3];
        *(s8 *)(func_002b6150(0x9E) + 0x6E) = 0x66;
        func_002b6a70(0x9E, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0x9E, *(u8 *)(func_002b6150(0x9E) + 0x6E), 0, 0, 0, 0);
    }
    func_002b2970(&sp48, f50, 293.0f + f54);
    if ((s8)arg1 == 0) {
        func_002b6c30(0xA0, sp48, 0xC1, 16.0f);
        func_002b2a60(c68, 0, 0, 0, 0xFF);
        p = func_002b6150(0xA0);
        p[0x85] = c68[0];
        p[0x86] = c68[1];
        p[0x87] = c68[2];
        p[0x88] = c68[3];
        *(s8 *)(func_002b6150(0xA0) + 0x6E) = 0x66;
        func_002b6a70(0xA0, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0xA0, *(u8 *)(func_002b6150(0xA0) + 0x6E), 0, 0, 0, 0);
    }
    f21 = 23.0f + f54;
    func_002b2970(&sp48, 15.0f + f50, f21);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x196, sp48, 0xC2, 13.0f);
        func_002b2a60(c64, 0xFF, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x196);
        p[0x85] = c64[0];
        p[0x86] = c64[1];
        p[0x87] = c64[2];
        p[0x88] = c64[3];
        func_002b6a70(0x196, 0, 0xFF, 0, 5, 0);
    } else {
        func_002b6a70(0x196, *(u8 *)(func_002b6150(0x196) + 0x6E), 0, 0, 0, 0);
    }
    func_002b2970(&sp48, 285.0f + f50, f21);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x1A1, sp48, 0xC2, 14.0f);
        func_002b2a60(c60, 0xFF, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x1A1);
        p[0x85] = c60[0];
        p[0x86] = c60[1];
        p[0x87] = c60[2];
        p[0x88] = c60[3];
        func_002b6a70(0x1A1, 0, 0xFF, 0, 5, 0);
    } else {
        func_002b6a70(0x1A1, *(u8 *)(func_002b6150(0x1A1) + 0x6E), 0, 0, 0, 0);
    }
    func_002b7750(0x2E2, 0x9E);
    f22 = 11.0f + f50;
    func_002b2970(&sp48, f22, 13.0f + f54);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x2E2, sp48, 0xC1, 14.0f);
        func_002b6d60(0x2E2);
        func_002b2a60(c5C, 0, 0, 0, 0xFF);
        p = func_002b6150(0x2E2);
        p[0x85] = c5C[0];
        p[0x86] = c5C[1];
        p[0x87] = c5C[2];
        p[0x88] = c5C[3];
        *(s8 *)(func_002b6150(0x2E2) + 0x6E) = 0x66;
        *(f32 *)(func_002b6150(0x2E2) + 0xAC) = 1.0f;
        *(f32 *)(func_002b6150(0x2E2) + 0xA0) = 1.0f;
        func_002b6a70(0x2E2, 0, 0x66, 0, 5, 3);
    } else {
        func_002b6a70(0x2E2, *(u8 *)(func_002b6150(0x2E2) + 0x6E), 0, 0, 0, 0);
    }
    func_002b7750(0x2E3, 0xA0);
    func_002b2970(&sp48, f22, 306.0f + f54);
    if ((s8)arg1 == 0) {
        func_002b6c30(0x2E3, sp48, 0xC1, 14.0f);
        func_002b2a60(c58, 0, 0, 0, 0xFF);
        p = func_002b6150(0x2E3);
        p[0x85] = c58[0];
        p[0x86] = c58[1];
        p[0x87] = c58[2];
        p[0x88] = c58[3];
        *(s8 *)(func_002b6150(0x2E3) + 0x6E) = 0x66;
        *(f32 *)(func_002b6150(0x2E3) + 0xAC) = 1.0f;
        *(f32 *)(func_002b6150(0x2E3) + 0xA0) = 1.0f;
        func_002b6a70(0x2E3, 0, 0x66, 0, 5, 3);
        return;
    }
    func_002b6a70(0x2E3, *(u8 *)(func_002b6150(0x2E3) + 0x6E), 0, 0, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032a960);
#endif

/* measured: nd 395 — the f32-pair stack-slot placement is unmovable and breaks
   the s64 recombination. Retail keeps the 2970 output copy as f32s at 0xD0/0xD4
   (adjacent, read back as one s64 `ld $a1, 0xd0` for 6c30 and re-read as halves);
   mwcc b210 places the two f32 locals at 0xD8 and 0xCC (non-adjacent, the
   *(s64 *)&spD0 read then spans spDC, corrupting every downstream block ~20
   words), regardless of declaration order. An f32 spD0[2] array grows the frame
   0xE0->0xF0 (array placed at 0xE0); declaring the pair as one s64 adds a saved
   register (digit value gets a fresh $s3 instead of reusing t's $s2, frame
   0x100). Constants verified against retail during the attempts: 0x43850000 is
   266.0f, 0x43570000 215.0f, 0x43540000 148.0f, 0x43550000 149.0f, 0x43530000
   147.0f (my initial decode was off by one); the (s8)arg1 ext IS in-place on
   $s0. Stack-slot placement floor. */
/* measured (even lane 2026-09-17): 395 differing words via `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_0032b000` (GUARDED_SCORE func_0032b000: 395); banked as guarded floor per 3% rule -- probe 395w via docs/probe_archive/EVEN_0032b000_body.c, fnalign 77 edits, retail 475 vs object 471 (-4, -0.84% PASS). */
// FUN_0032B000 NONMATCHING
#ifdef NON_MATCHING
void func_0032b000(u8 *arg0, s32 arg1) {
    FclByte4 cDC;
    s64 spC0;
    s64 spC8;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    f32 f21;
    s32 t16;
    s32 t17;
    u8 *p;
    (void)arg0;
    func_002b2970(&spC0, 266.0f, (f32)0x163);
    t17 = (s8)func_00110140();
    t16 = (s8)arg1;
    if (t16 == 0) {
        func_002b6c30(0x2CF, spC0, 0x56, 215.0f);
        func_002b2a60(&cDC, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x2CF);
        *(FclByte4 *)(p + 0x85) = cDC;
        func_002b2970(&spB8, 380.0f + *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b2970(&spB0, *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b69f0(0x2CF, *(FclVec2 *)&spB8, *(FclVec2 *)&spB0, 1, 0xA, 0);
    } else {
        p = func_002b6150(0x2CF);
        func_002b2970(&spA8, 380.0f + *(f32 *)&spC0, *((f32 *)&spC0 + 1));
        func_002b69f0(0x2CF, *(FclVec2 *)(p + 0x38), *(FclVec2 *)&spA8, 1, 0xA, 0);
    }
    func_002b2970(&spC8, 35.0f + *(f32 *)&spC0, 11.0f + *((f32 *)&spC0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x119, spC8, 0x57, 212.0f);
        func_002b6a70(0x119, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&spA0, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x119, *(FclVec2 *)&spA0, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x119, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp98, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x119, *(FclVec2 *)&spC8, *(FclVec2 *)&sp98, 1, 0xA, 2);
    }
    func_002b2970(&spC8, (f32)0x11D + *(f32 *)&spC0, 12.0f + *((f32 *)&spC0 + 1));
    if (t16 == 0) {
        func_002b6c30(0x11A, spC8, 0x57, 213.0f);
        func_002b6a70(0x11A, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&sp90, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x11A, *(FclVec2 *)&sp90, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x11A, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp88, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x11A, *(FclVec2 *)&spC8, *(FclVec2 *)&sp88, 1, 0xA, 2);
    }
    f21 = *((f32 *)&spC0 + 1) - 3.0f;
    func_002b2970(&spC8, 247.0f + *(f32 *)&spC0, f21);
    if (t16 == 0) {
        func_002b6c30(0x2D0, spC8, 0x57, 211.0f);
        *(s16 *)(func_002b6150(0x2D0) + 0x4) = (s16)(((t17 % 10) + 0x10C));
        func_002b6a70(0x2D0, 0, 0xFF, 0, 0xA, 2);
        func_002b2970(&sp80, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x2D0, *(FclVec2 *)&sp80, *(FclVec2 *)&spC8, 1, 0xA, 2);
    } else {
        func_002b6a70(0x2D0, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp78, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x2D0, *(FclVec2 *)&spC8, *(FclVec2 *)&sp78, 1, 0xA, 2);
    }
    if (t17 >= 0xA) {
        func_002b2970(&spC8, 221.0f + *(f32 *)&spC0, f21);
        if (t16 == 0) {
            func_002b6c30(0x2D1, spC8, 0x57, 211.0f);
            *(s16 *)(func_002b6150(0x2D1) + 0x4) = (s16)(((t17 / 10 % 10) + 0x10C));
            func_002b6a70(0x2D1, 0, 0xFF, 0, 0xA, 2);
            func_002b2970(&sp70, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x2D1, *(FclVec2 *)&sp70, *(FclVec2 *)&spC8, 1, 0xA, 2);
        } else {
            func_002b6a70(0x2D1, 0xFF, 0, 0, 0xA, 0);
            func_002b2970(&sp68, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x2D1, *(FclVec2 *)&spC8, *(FclVec2 *)&sp68, 1, 0xA, 2);
        }
    }
    if (func_00110140() == 0x64) {
        func_002b2970(&spC8, 195.0f + *(f32 *)&spC0, f21);
        if (t16 == 0) {
            func_002b6c30(0x10D, spC8, 0x57, 211.0f);
            func_002b6a70(0x10D, 0, 0xFF, 0, 0xA, 2);
            func_002b2970(&sp60, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
            func_002b69f0(0x10D, *(FclVec2 *)&sp60, *(FclVec2 *)&spC8, 1, 0xA, 2);
            return;
        }
        func_002b6a70(0x10D, 0xFF, 0, 0, 0xA, 0);
        func_002b2970(&sp58, *(f32 *)&spC8, *((f32 *)&spC8 + 1) - 20.0f);
        func_002b69f0(0x10D, *(FclVec2 *)&spC8, *(FclVec2 *)&sp58, 1, 0xA, 2);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b000);
#endif

/* measured: 596B/608B, exact emitted instructions and three zero-tail words.
   The retail loop passes word-sized list indices; a narrowed call declaration
   inserts two normalization instructions. Removing the unused expression that
   read new_var/f20/f21 before initialization preserves every emitted word. */
// FUN_0032B770
void func_0032b770(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  float new_var5;
  f32 *new_var4;
  s64 spC8;
  s64 spC0;
  u8 *new_var;
  s64 spB8;
  f32 new_var11;
  f32 *new_var10;
  short new_var3;
  s16 i;
  s32 v1;
  s32 v2;
  u8 *new_var6;
  s16 new_var9;
  s16 *new_var8;
  u8 b;
  u8 **new_var2;
  u8 *obj;
  f32 f21;
  s16 new_var7;
  f32 f20;
  new_var2 = (u8 **) (arg0 + 0x38);
  obj = *new_var2;
  func_002b2970(&spC8, 156.0f, (float) ((float) 87.0f));
  func_0031e5b0(arg0, spC8, 0, arg3, 0, 1, 1);
  i = 0;
  v1 = (s16) arg1;
  new_var9 = (s16) arg2;
  v2 = new_var9;
  b = (unsigned char) 0xAA;
  while (((s16) i) < v2)
  {
    func_002b2970(&spC0, 162.0f, 111.0);
    ;
    ;
    func_0031ac10(arg0, spC0, -1, (s8) i, (*((u16 *) (func_002e48a0(0, i) + 2))) & 0xFFFFu, *((u8 *) (func_002e48a0(0, i) + 4)), (s16) (((s16) i) * v1), arg3, 0, 0x99);
    i++;
  }

  new_var3 = 0x3C;
  new_var8 = (s16 *) (obj + 0x11E);
  func_003297f0(arg0, 0, arg3, 417.0, 220.0f);
  new_var6 = obj;
  new_var10 = (f32 *) (obj + 0x124);
  func_002b2970(&spB8, 472.0f, 112.0f);
  func_00324f80(arg0, *((FclVec2 *) (&spB8)), 0, arg3);
  f21 = (new_var7 = *new_var8) - (*((s16 *) (new_var6 + 0x120)));
  f20 = *new_var10;
  new_var4 = &f20;
  new_var = func_002b6150(b) + 0x3C;
  *((f32 *) (func_002b6150(0xB1) + new_var3)) = (f20 = (*((f32 *) new_var)) + ((*new_var4) * f21));
  new_var11 = *((f32 *) (func_002b6150(0xB1) + 0x3C));
  new_var5 = 52.0f + new_var11;
  *((f32 *) (func_002b6150(0xB5) + 0x3C)) = (f20 = new_var5);
}

/* measured (FclDrawB 2026-09-17): probe_variants 289 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0032b9d0 --candidate V1=/var/tmp/drawB/c2b9d0_v1.c`; fnalign retail 440 vs object 433 instrs (189 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0032b9d0 --candidate /var/tmp/drawB/c2b9d0_v1.c --quiet`; 7 short (1.6% within 3% rule). Replaces adda/madd with plain mul+add (same 2-instr count); block-scope loop counters per Main 001679d0 lever; u8[4] colours; FclVec2 for 24f80. Prior best 1154; this 289 is new best. Wall remains COP1 accumulator + rotation per preserved note. */
// FUN_0032B9D0 NONMATCHING
#ifdef NON_MATCHING
void func_0032b9d0(u8 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    u8 c13C[4];
    u8 c138[4];
    u8 c134[4];
    u8 c130[4];
    u8 c12C[4];
    u8 c124[4];
    u8 c128[4];
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    s64 spD8;
    s64 spC8;
    s64 spC0;
    f32 f100;
    f32 f104;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&sp118, 88.0f, 127.0f);
    func_0031e5b0(arg0, sp118, 0, arg3, 0, 1, 3);
    func_002b2970(&spF8, 386.0f, 127.0f);
    f100 = *(f32 *)&spF8;
    f104 = *((f32 *)&spF8 + 1);
    func_002b2a60(c13C, 0, 0, 0x99, 0xFF);
    func_002b77d0(0x21E, spF8, 0x193, *(s32 *)c13C, 0x41, arg3, 6, 3, 191.0f, 0, func_00331560());
    func_002b2970(&spF0, 151.0f + f100, f104);
    func_002b2a60(c138, 0, 0, 0x99, 0xFF);
    func_002b77d0(0x19D, spF0, 0x19D, *(s32 *)c138, 0x41, arg3, 6, 3, 191.0f, 0, func_00331560());
    func_002b2970(&spE8, 24.0f + f100, 9.0f + f104);
    func_002b2a60(c134, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x2AF, spE8, 0x73, *(s32 *)c134, 0x56, arg3, 6, 3, 175.0f, 0, func_00331560());
    func_002b2970(&spE0, 65.0f + f100, 9.0f + f104);
    func_002b2a60(c130, 0x49, 0x72, 0xFF, 0xFF);
    func_002b77d0(0x2B0, spE0, 0x73, *(s32 *)c130, 0x56, arg3, 6, 3, 175.0f, 0, func_00331560());
    func_002b2970(&spD8, 119.0f + f100, 5.0f + f104);
    func_002b2a60(c12C, 0x33, 0xCD, 0xFF, 0xFF);
    func_002b77d0(0x11D, spD8, 0x11D, *(s32 *)c12C, 0x56, arg3, 6, 3, 191.0f, 0, func_00331560());
    func_00329e40(arg0, 0, arg3);
    {
        s32 k = *(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120);
        s32 j = 0;
        s32 end = (s32)arg2 + k;
        while (k < end) {
            func_002b2970(&sp110, 404.0f, 151.0f);
            {
                u16 w = *(u16 *)(func_002e48a0(0, k) + 2);
                func_0031ac10(arg0, sp110, -1, (s8)j, w, *(u8 *)(func_002e48a0(0, k) + 4), (s16)(j * arg1), arg3, 0, 0x99);
            }
            func_002b2970(&spC8, 386.0f, 151.0f);
            {
                f32 d0 = *(f32 *)&spC8;
                f32 d1 = *((f32 *)&spC8 + 1);
                func_002b2a60(c124, 0, 0, 0x99, 0x80);
                c128[0] = c124[0];
                c128[1] = c124[1];
                c128[2] = c124[2];
                c128[3] = c124[3];
                d1 += (f32)((s8)j * 23);
                if (*(s16 *)(t + 0x120) == (s8)j) {
                    func_002b2a60(c128, 0xCC, 0xFF, 0x33, 0xFF);
                }
                func_002b77d0((s16)((s8)j + 0x21F), spC8, 0x193, *(s32 *)c128, 0x41, arg3, 6, 3, 191.0f, (s16)(j * arg1), func_00331560());
                func_002b2970(&spC0, 132.0f + d0, d1);
                func_002b77d0((s16)((s8)j + 0x2C5), spC0, 0x19E, *(s32 *)c128, 0x41, arg3, 6, 3, 191.0f, (s16)(j * arg1), func_00331560());
            }
            k++;
            j++;
        }
    }
    func_002b2970(&sp108, 535.0f, 154.0f);
    func_00324f80(arg0, *(FclVec2 *)&sp108, 0, arg3);
    {
        s16 d = *(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120);
        f32 f21 = (f32)d;
        f32 f20 = *(f32 *)(t + 0x124);
        f32 mem = *(f32 *)(func_002b6150(0xAA) + 0x3C);
        f32 res = f20 * f21 + mem;
        *(f32 *)(func_002b6150(0xB1) + 0x3C) = res;
        *(f32 *)(func_002b6150(0xB5) + 0x3C) = res + 52.0f;
    }
    func_003297f0(arg0, 1, arg3, 359.0f, 417.0f);
    func_0032b000(arg0, arg3);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b9d0);
#endif

/* Measured: this C body is byte-exact under scoped verify.py (obj 956/window
   960, nd 0), but its switch emits one additional anonymous .rodata jump
   table (the current object labels it @551) alongside retail's one named
   six-entry table, jtbl_00749640. Retail func_0032c0c0 uses one jump table;
   this body emits one semantically identical table, but retaining the retail
   assembly table makes the linked TU contain an additional anonymous table.
   The scoped verifier is exact; whole-TU linked layout remains unverified.
   If tools/build.py reports its first linked-image difference inside the
   y_fclCombineDraw address range, inspect this function first. */
// FUN_0032C0C0
void func_0032c0c0(u8 *arg0, s64 arg1) {
    f32 fdiff;
    f32 facc;
    s32 r;
    s32 v4;
    u8 *obj;

    obj = *(u8 **)(arg0 + 0x38);
    r = 8;
    if (*(s32 *)(func_002e4870(0) + 8) < 8) {
        r = *(s16 *)(func_002e4870(0) + 8);
    }
    *(s8 *)(obj + 0x13A) = 1;
    switch ((s8)arg1) {
    case 0:
        *(s16 *)(obj + 0x11E) = func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 1);
        *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, 1);
        break;
    case 1:
        *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, 0, 1);
        *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s16 *)(func_002e4870(0) + 8), r, -1);
        break;
    case 2:
        func_002b2e70(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s32 *)(func_002e4870(0) + 8), 8, (s16 *)(obj + 0x11E), (s16 *)(obj + 0x120));
        break;
    case 3:
        func_002b2f90(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), *(s32 *)(func_002e4870(0) + 8), 8, (s16 *)(obj + 0x11E), (s16 *)(obj + 0x120));
        break;
    case 4:
        v4 = func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 0, 2);
        *(u16 *)(obj + 0x11E) = (u16)v4;
        if ((s16)v4 == 0) {
            *(s16 *)(obj + 0x120) = 0;
        } else {
            *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, 1);
        }
        break;
    case 5:
        if (*(s16 *)(obj + 0x11E) == 0) {
            *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
            *(s16 *)(obj + 0x120) = (s16)((s16)r - 1);
        } else {
            *(s16 *)(obj + 0x11E) = func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), 2);
            *(s16 *)(obj + 0x120) = func_002b2d50(*(s16 *)(obj + 0x11E), *(s16 *)(obj + 0x120), (s16)(*(s32 *)(func_002e4870(0) + 8) - 1), r, -1);
        }
        break;
    }
    fdiff = (f32)(*(s16 *)(obj + 0x11E) - *(s16 *)(obj + 0x120));
    facc = *(f32 *)(obj + 0x124);
    facc = 0.0f + *(f32 *)(func_002b6150(0xAA) + 0x3C) + facc * fdiff;
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = facc;
    facc = 52.0f + *(f32 *)(func_002b6150(0xB1) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = facc;
}
typedef struct {
    u8 reserved00[4];
    u8 *persona;
} CdfDrawWork;

typedef struct {
    u8 reserved00[0x11E];
    s16 selection;
    u8 reserved120[0x28];
    u8 *draw;
    u8 reserved14c[0x108];
    u8 *model;
} CdfCombineWork;

static inline u8 *cdfPersona(u8 *draw)
{
    return ((CdfDrawWork *)*(u8 **)(draw + 0x38))->persona;
}

/* measured: MWCCPS2 b210 -O2, 472B/window 480B, 21 resolved relocations,
 * eight zero alignment bytes. Ghidra supplies the float constants; IDA
 * supplies the signed selection and two-word position packet. Typed work
 * views and the canonical message-queue pointer preserve argument order. */
// FUN_0032C480
void func_0032c480(u8 *arg0)
{
    union { FclVec2 xy; s64 whole; } sp38;
    CdfCombineWork *obj;
    s32 n;

    obj = (CdfCombineWork *)*(u8 **)(arg0 + 0x38);
    func_00275820(140.0f, 101.0f, 1.0f, func_002b2a30(0, 0, 0, 0xFF), 0, 2,
        (const char *)((u8 *)iGpffffb440 + *(u16 *)(func_002e48a0(0, obj->selection) + 2) * 0x11),
        0, 0, D_00796310, 0x15);
    n = (s16)((func_00109280(*(u16 *)(func_002e48a0(0, obj->selection) + 2)) & 0xFF) + 0x1B);
    func_002b2970(&sp38.xy, 54.0f, 103.0f);
    func_00330e50(n, sp38.whole, 1.0f, 0xFF000000, 0xFF, 1, 1.0f, 1.0f, D_00796310);
    n = (s16)func_00331640();
    func_00279350(54.0f, 138.0f, 1.0f, -1, 1, 0, 1, n,
        *(u16 *)(func_002e48a0(0, obj->selection) + 2), D_00796370);
    func_0034a640((s32)obj->model, *(u16 *)(func_002e48a0(0, obj->selection) + 2), 1);
    *(u8 *)(func_0034a630(obj->model) + 1) = 0;
    func_0011d1d0(cdfPersona(obj->draw), 64000.0f);
}

// measured: nd N/A (draw-family, s64-param floor). 26x 2970 + 17x 69f0 + 8x 68d0 + 6x 6c30 + 6x 7750: same s64-arg normalization floor; externs locked by matched callers. s64-param-normalization floor.
// FUN_0032C660
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c660);

// measured: nd N/A (ldr/ldl unaligned 8B loads). M2C_ERROR on ldr/ldl at 0x50/0x57; plus 147e0 call. Unaligned-load floor.
// FUN_0032E570
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);

// FUN_0032F060
void func_0032f060(u8 *arg0, s32 arg1) {
    s32 sp6C, sp68, sp64, sp60, sp5C;
    s64 sp50, sp48, sp40, sp38, sp30;
    s32 v16;
    f32 *p;
    f32 f20;

    p = D_00644880;
    v16 = (s8)arg1;
    if (v16 == 0) {
        func_002b2970(&sp50, p[0], p[1]);
        func_002b6c30(0x162, sp50, 0xA1, 147.0f);
        func_002b2a60(&sp6C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x162) + 0x85) = *(FclByte4 *)&sp6C;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x162) + 0xD0) = f20;
        func_002b6a70(0x162, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x162, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644888;
    if (v16 == 0) {
        func_002b2970(&sp48, p[0], p[1]);
        func_002b6c30(0x163, sp48, 0xA2, 146.0f);
        func_002b2a60(&sp68, 0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(0x163) + 0x85) = *(FclByte4 *)&sp68;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x163) + 0xD0) = f20;
        func_002b6a70(0x163, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x163, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644890;
    if (v16 == 0) {
        func_002b2970(&sp40, p[0], p[1]);
        func_002b6c30(0x164, sp40, 0x59, 145.0f);
        func_002b2a60(&sp64, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x164) + 0x85) = *(FclByte4 *)&sp64;
        func_002b6a70(0x164, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x164, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644898;
    if (v16 == 0) {
        func_002b2970(&sp38, p[0], p[1]);
        func_002b6c30(0x165, sp38, 0x59, 145.0f);
        func_002b2a60(&sp60, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x165) + 0x85) = *(FclByte4 *)&sp60;
        func_002b6a70(0x165, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x165, 0xFF, 0, 0, 0xA, 0);
    }
    if (v16 == 0) {
        func_002b2970(&sp30, 0.0f, 65.0f);
        func_002b6c30(0x2DA, sp30, 0x59, 145.0f);
        func_002b2a60(&sp5C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x2DA) + 0x85) = *(FclByte4 *)&sp5C;
        func_002b6a70(0x2DA, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x2DA, 0xFF, 0, 0, 0xA, 0);
    }
}

/* Floor: 287 differing words (probe_variants docs/probe_archive/F_0032f4d0_body.c) over 88 fnalign edits, */
/* 343 emitted against retail's 343 (100% in 1376B window). WALL: (1) Six sh-index addus: retail addu */
/* $v0,$v0,$s0 (scaled index + t) vs object addu $v0,$s0,$v0 (t + index), invariant under ix-local lever */
/* (s32 ix = X*2; ix + t gave worse); (2) loop-CSE of (s16)i normalize (object once at bottom vs retail */
/* top AND test); (3) stack ldr/ldl 0x50/0x57 vs object ld (heap-base rule, stack base always ld); plus */
/* saved-reg rotation t $s0 vs $s1 and lb/lbu for 0xB7 counter. Reusable skeleton in conventions note above */
/* (spA0..sp78 s64 locals, tbl FclVec2[5] at 0x50, nested 0x1305/0x1306, third 2970 block, t->0xB7 re-read, */
/* f20=-14 last, r s16, for(i=0;(s16)i<t->0xB7;i=(s16)(i+1)) with n=(s16)i and func_003147e0 call). Old claim */
/* superseded (no archive; F body measures 287/88). Lever checklist: slti-$at N/A (no integer slti); */
/* dead-arm N/A (exact 343/343); opt_common_subs off 287->289 worse; opt_loop_invariants neutral. */
/* measured (source repo): probe_variants plain 307 differing words (cse_off variant 287, ties prior F-body floor 287; sched 311 worse; loop_invariants 307->307 neutral); live verify plain obj 1348/window 1376 normalized_diff 1002. Prior floor in file 287 words over 88 fnalign edits (343/343 emitted). Residual confirms the recorded wall: six sh-index addus base+scaled vs scaled+base, loop-CSE of (s16)i normalize, stack ldr/ldl vs ld, plus saved-reg rotation and lb/lbu counter. Shapes reproduce per skeleton in conventions note: s64 locals to 2970 cast to FclVec2 tbl[5] at 0x50, nested 1305/1306, f20=-14 last, s16 r, 147e0 6-arg loop, FclByte4 groups with p1/p2 locals (retain 6150 result, never re-call for the copy). Plain parked (cse_off 287 noted as variant, not committed, to avoid a pragma waiver on a far floor). Body re-derived from retail/IDA. Parked as floor. */
// FUN_0032F4D0 NONMATCHING
#ifdef NON_MATCHING
void func_0032f4d0(u8 *arg0) {
    FclVec2 tbl[5];
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    FclByte4 cBC;
    FclByte4 cB8;
    FclByte4 cB4;
    FclByte4 cB0;
    FclByte4 cAC;
    FclByte4 cA8;
    f32 f20;
    s16 i;
    s16 n;
    s16 r;
    u8 *t;
    u8 *p1;
    u8 *p2;

    t = *(u8 **)(arg0 + 0x38);
    f20 = 0.0f;
    *(s8 *)(t + 0xB7) = 0;
    *(s16 *)(t + 0xB8) = 0x169;
    func_002b2970(&spA0, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&spA0;
    *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
    *(s16 *)(t + *(s8 *)(t + 0xB7) * 2 + 0xB8) = 0x16A;
    func_002b2970(&sp98, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&sp98;
    *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
    if (func_00106330(0x1305) != 0) {
        *(s16 *)(t + *(s8 *)(t + 0xB7) * 2 + 0xB8) = 0x16B;
        func_002b2970(&sp90, 26.0f, (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
        tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&sp90;
        *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
        if (func_00106330(0x1306) != 0) {
            *(s16 *)(t + *(s8 *)(t + 0xB7) * 2 + 0xB8) = 0x16C;
            func_002b2970(&sp88, 26.0f, 20.0f + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
            tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&sp88;
            *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
            f20 = -14.0f;
        }
    }
    *(s16 *)(t + *(s8 *)(t + 0xB7) * 2 + 0xB8) = 0x16D;
    func_002b2970(&sp80, 26.0f, f20 + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&sp80;
    *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
    *(s16 *)(t + *(s8 *)(t + 0xB7) * 2 + 0xB8) = 0x16E;
    func_002b2970(&sp78, 26.0f, f20 + (f32)(*(s8 *)(t + 0xB7) * 34 + 0x57));
    tbl[*(s8 *)(t + 0xB7)] = *(FclVec2 *)&sp78;
    *(s8 *)(t + 0xB7) = *(s8 *)(t + 0xB7) + 1;
    i = 0;
    for (; (s16)i < *(s8 *)(t + 0xB7); i = (s16)(i + 1)) {
        n = (s16)i;
        func_003147e0(arg0, (s8)(n + 4), *(s64 *)((u8 *)tbl + n * 8), *(s16 *)(t + n * 2 + 0xB8), (s16)(n * 2 + 3), 0);
    }
    r = (s16)func_0032fb60(*(s8 *)(t + 0xB6));
    func_002b2a60(&cBC, 0xC6, 0xEE, 1, 0xFF);
    func_002b2a60(&cB8, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b2a60(&cB4, 0x92, 0xC8, 7, 0xFF);
    func_0032fa30(arg0, r, *(s32 *)&cBC, *(s32 *)&cB8, *(s32 *)&cB4);
    if (func_00106330(0x1306) != 0) {
        func_002b2a60(&cB0, 0x29, 0x29, 0x29, 0xFF);
        p1 = func_002b6150(0x201);
        *(FclByte4 *)(p1 + 0x85) = cB0;
        p2 = func_002b6150(0x200);
        *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
        func_002b2a60(&cAC, 0x61, 0x61, 0x61, 0xFF);
        *(FclByte4 *)(func_002b6150(0x16B) + 0x85) = cAC;
        func_002b2a60(&cA8, 0x4A, 0x4A, 0x4A, 0xFF);
        *(FclByte4 *)(func_002b6150(0x301) + 0x85) = cA8;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032f4d0);
#endif

// FUN_0032FA30
void func_0032fa30(u8 *arg0, s16 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u8 *t;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    s32 idx;

    t = *(u8 **)(arg0 + 0x38);
    p1 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)&arg2;
    p2 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    idx = arg1 * 2;
    p3 = func_002b6150(*(s16 *)(idx + (s32)t + 0xB8));
    *(FclByte4 *)(p3 + 0x85) = *(FclByte4 *)&arg3;
    p4 = func_002b6150((s16)(arg1 + 0x2FF));
    *(FclByte4 *)(p4 + 0x85) = *(FclByte4 *)&arg4;
}
// FUN_0032FB60
s8 func_0032fb60(s8 arg0) {
    if (func_00106330(0x1306)) {
        arg0 = (s8)(D_00749530[arg0] - 4);
    }
    return arg0;
}
/* measured: nd 176 — one fixed saved-register rotation: retail allocates t to $s7
   and the six inner-loop func_0034ae50 results to $fp/$s0/$s5/$s6 (e4/e5 spill to
   0xD0/0xC0, frame 0x110); mwcc b210 always gives t $fp and spills e0/e1 (frame
   0x120). Declaration order has ZERO effect (6-order probe batch, all nd 178),
   and the (s16)j loop-test temp lands in $s7 instead of reusing the dead e1 $s0.
   Also the v11 lb $t3 arg-8 load is emitted after the (s8)i dsll (retail before),
   and the inner pre-header emits sll/addu before the j=0 move (retail after).
   Everything else reproduces exactly: func_003191c0 8th stack-arg-in-$t3 call,
   p2 = t + (s16)i*4 hoist, ldr/ldl unaligned s64 args, lbu/lwc1 arg block,
   sp0/sp8 s64 stack args, FMA madd.s f12,f3,f2 + cvt.s.w 329.0f, div.s /2.0f,
   i2*23 strength-reduced mul, loop shapes. Saved-register rotation +
   load-scheduling floor. */
/* measured: nd 235 (best of 4: s16 loops 235, named-s16 240, draft-exact s64
   loops 250; the recorded nd-176 baseline did not reproduce with any spelling;
   one CE from the 31560->void* cast before the extern fix). Recipe C re-test:
   the inner-loop ldr/ldl at 0x28($e1) is NOT reproducible — probes prove mwcc
   b210 emits plain ld for ANY s64/u64 read at an 8-aligned displacement from
   ANY base (heap local, inline call result, u32 cast), and ldr/ldl only at
   4-mod-8; the retail pair is brief-mechanism-1 (8-byte struct by value),
   blocked by the shared s64 extern of func_002b83e0. Also: the e4/e5 spill is
   sq (128-bit) and the *(u_long128)(u32)ptr write emits the recorded
   dsll32/dsrl32 widening pair before each sq (read-back via *(u32 *)&slot is
   clean). The 31560 result must feed func_0046d200 through an s64 extern param
   (s64->void* adds dsll32/dsra32 0), same for 46b2f0's s32 param. Everything
   else (191c0 8-arg call, 83e0 arg block incl. lwr/lwl 0x75 reads, FMA
   madd.s f12,f3,f2 = 329.0f + 23.0f*(f32)t, div.s /2.0f, t*23 strength
   reduction, iGpffff8504 GPREL f32) reproduces; the residual is the recorded
   saved-register rotation (t->$fp vs $s7, 34ae50 results, frame 0x120 vs
   0x110) + the normalize-placement noise. Saved-reg rotation + ldr/ldl-vs-ld
   floor. */
/* measured (source repo): probe_variants 220 differing words reloc-masked; live verify obj 1164/window 1184 normalized_diff 710. Prior best in file nd 235 (nd-176 baseline not reproducing). Pragmas on this exact body: opt_loop_invariants 220->220 neutral, opt_common_subs off 220->242 worse, schedule on 220->251 worse; rotation persists under all three, so the saved-register rotation (t->$fp vs $s7, 34ae50 results, frame 0x120 vs retail 0x110) plus ldr/ldl unaligned s64 and s64-arg normalization stand as measured walls, not guesses. Single-byte widths verified: (s8)i/(s8)j with dsll24/dsra24, lhu/lbu for 2e48a0 results, lb for 2e4870+8. Address chains show frame/allocation residuals in the top fndiff rows, no sched-after-load signature, so double-def pinning not indicated. Body re-derived from retail asm plus IDA/M2C (not inherited); call shapes reproduce: 2970/1e5b0 prologue, 191c0 8-arg call, 34ae50 x6 plus 83e0 inner loop, FMA 329.0f+23.0f*(f32)i, 2a60 FclByte4 groups, 69f0 struct-by-value pairs via *(FclVec2*), 46d200(h u8*)/46b2f0(h)/46d280(h) chain per source void* extern. Parked as floor. */
// FUN_0032FBC0 NONMATCHING
#ifdef NON_MATCHING
void func_0032fbc0(u8 *arg0) {
    FclByte4 c10C;
    FclByte4 c108;
    s64 sp100;
    s64 spF8;
    s64 spF0;
    s64 spE8;
    s64 spE0;
    u8 *t;
    s16 i;
    s16 j;
    u16 w;
    u8 b;
    u8 *p;
    u8 *h;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&sp100, 16.0f, 104.0f);
    func_0031e5b0(arg0, sp100, 0, 1, 0, 0, 0);
    i = 0;
    while ((s16)i < (u16)func_0010b5b0()) {
        func_002b2970(&spF8, 16.0f, 128.0f);
        w = *(u16 *)(func_002e48a0(0, i) + 2);
        b = *(u8 *)(func_002e48a0(0, i) + 4);
        func_003191c0(arg0, spF8, (s8)i, w, b, 0, 1, *(s8 *)(func_002e4870(0) + 8));
        j = 0;
        p = t + (s16)i * 4;
        while ((s16)j < (u16)func_0010b5b0()) {
            u8 *e0;
            u8 *e1;
            u8 *e2;
            u8 *e3;
            u8 *e4;
            u8 *e5;
            e0 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e1 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e2 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e3 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e4 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            e5 = func_0034ae50(*(u8 **)(p + 0x154), (s8)j);
            func_002b83e0(e0, *(s64 *)(e1 + 0x28), *(s32 *)(e2 + 0x75), *(s32 *)(e3 + 0x75), *(u8 *)(e4 + 0x5E), *(u8 *)(e5 + 0x5E), 3, 0, 32.0f, *(f32 *)(func_0034ae50(*(u8 **)(p + 0x154), (s8)j) + 4), 1, 0);
            j = (s16)(j + 1);
        }
        p = func_0034ae50(*(u8 **)(t + 0x184), (s8)i);
        func_002b2970(&spF0, 329.0f + 23.0f * (f32)(s16)i, 104.0f);
        func_002b2a60(&c10C, 0, 0, 0x99, 0xFF);
        func_002b2a60(&c108, 0, 0, 0x99, 0xFF);
        func_002b83e0(p, spF0, *(s32 *)&c10C, *(s32 *)&c108, 0xFF, 0xFF, 2, 0, 32.0f, 159.0f, 1, 0);
        func_002b6a70((s16)((s16)i + 0x25E), 0xFF, 0, 0, 3, 0);
        func_002b6af0((s16)((s16)i + 0x25E), 0, 3, 0, 1.0f, 1.0f, 1.0f, 1.0f);
        h = func_0046d200(func_00331560(), 0x39);
        func_002b2970(&spE8, (f32)((s16)i * 23 + 0x14E), 110.0f);
        func_002b2970(&spE0, (f32)((s16)i * 23 + 0x14E), 110.0f + func_0046b2f0(h) / 2.0f);
        func_002b69f0((s16)((s16)i + 0x25E), *(FclVec2 *)&spE8, *(FclVec2 *)&spE0, 0, 3, 0);
        func_0046d280(h);
        i = (s16)(i + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032fbc0);
#endif

/* measured: probe_variants 418 differing words reloc-masked; fnalign retail 468 vs object 468 instrs exact (PASS); */
/* live measure_guarded GUARDED_SCORE func_00330060: 418. Prior nd-126 note did not reproduce (re-measured 418 */
/* on the described shape; 414->243 named-lim win already included). All logic matches: 6-case jtbl switch */
/* (sltiu 6, cases 0..5, no default), both loops, six FclByte4 chains, tail adda.s/madd.s FPU-fusion store. */
/* Walls (same three rotations as noted, now at 418): (1) t (*(u8**)(arg0+0x38)) in $s0 vs retail $s3: mwcc */
/* gives second-loop (s16)jj a fresh saved ($s1) where retail reuses dead arg1 $s1, shifting diff/cur/lim/bid; */
/* (2) first-loop counter raw in temp ($v1) + normalized in saved ($s1) vs retail raw in $s0 + temp per use; */
/* second-loop bid as s32 (definition (s16)cur+0x179, use (s16)bid) matches retail single-normalize, s16 bid */
/* costs an extra dsll (v1 421 -> v2 418); (3) case stores: retail sh $v0 before (s16) normalize for 2d50 arg, */
/* mwcc normalizes into $a0 first (s16 v local). Frame/stack shift persists (object 0xA0 vs retail 0xB0 region) */
/* so every lbu/sb + lh base differs by register/offset. */
/* Repro: m2c_decompile fails on bare .s (jr without jtbl at line 89); fixed by inserting .L003301B8/22C/29C/2EC/338/3B0 */
/* labels + .rdata jtbl_00749660 (.word .L...) via /var/tmp/cold330060/combined2.s -> /var/tmp/cold330060/m2c.c */
/* (164 lines, (void*,s64) + (s8)arg1 switch, M2C_ERROR on adda/madd tail de-noised to base*diff_f+fv / 52+fv2). */
/* Rounds (probe_variants driven by fnalign, count gap closed first: v1 466/467 1-short -> v2 468/468 exact): */
/* v1 421 (FclByte4 groups, s16 diff/cur/jj, s32 lim, s16 bid, double-cast 68d0), v2 418 (-3 via s32 bid + */
/* single-cast (s16)(i+0x179)/(s16)(cur+0x179)), v3 425 (s32 i/cur/jj/bid/v worse), pragma_sweep O4 412 / O3 414 / */
/* schedule 414 but 413 instrs (11% short, reject per 3% gate), isolated tailswap/v-s32/diff-s32 ties 418, i-s32 */
/* 427 worse. Stopped after two consecutive non-lowering rounds (v3 + v4-v7 tie batch). Banked v2 as guarded */
/* floor (exact count, compiles clean under -DNON_MATCHING, verify 37 MATCH / 33 ASM unchanged). */
// FUN_00330060
#ifdef NON_MATCHING
void func_00330060(u8 *arg0, s64 arg1) {
    FclByte4 cAC;
    FclByte4 cA8;
    FclByte4 cA4;
    FclByte4 cA0;
    FclByte4 c9C;
    FclByte4 c98;
    s64 sp90;
    u8 *t;
    u8 *p;
    u8 *p1;
    s16 i;
    s16 diff;
    s16 cur;
    s16 jj;
    s32 lim;
    s32 bid;
    s16 v;
    f32 diff_f;
    f32 base;
    f32 fv;
    f32 fv2;
    t = *(u8 **)(arg0 + 0x38);
    func_002b2a60(&cAC, 0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = cAC;
    p1 = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F4));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)(p + 0x85);
    func_002b2a60(&cA8, 0x25, 0x2F, 0x94, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = cA8;
    *(u8 *)(t + 0x13A) = 1;
    switch ((s8)arg1) {
    case 0:
        if (*(s16 *)(t + 0x11E) != 7) {
            func_0045af60(0, 0, 0, 0);
        }
        v = (s16)func_002b2cb0(*(s16 *)(t + 0x11E), 1, 7, 0, 1);
        *(s16 *)(t + 0x11E) = v;
        *(s16 *)(t + 0x120) = func_002b2d50((s16)v, *(s16 *)(t + 0x120), 7, 6, 1);
        break;
    case 1:
        if (*(s16 *)(t + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        v = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 0, 1);
        *(s16 *)(t + 0x11E) = v;
        *(s16 *)(t + 0x120) = func_002b2d50((s16)v, *(s16 *)(t + 0x120), 7, 6, -1);
        break;
    case 2:
        if (*(s16 *)(t + 0x11E) != 7) {
            func_0045af60(0, 0, 0, 0);
        }
        func_002b2e70(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 8, 6, (s16 *)(t + 0x11E), (s16 *)(t + 0x120));
        break;
    case 3:
        if (*(s16 *)(t + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        func_002b2f90(*(s16 *)(t + 0x11E), *(s16 *)(t + 0x120), 8, 6, (s16 *)(t + 0x11E), (s16 *)(t + 0x120));
        break;
    case 4:
        func_0045af60(0, 0, 0, 0);
        v = (s16)func_002b2cb0(*(s16 *)(t + 0x11E), 1, 7, 0, 2);
        *(s16 *)(t + 0x11E) = v;
        if ((s16)v == 0) {
            *(s16 *)(t + 0x120) = 0;
        } else {
            *(s16 *)(t + 0x120) = func_002b2d50((s16)v, *(s16 *)(t + 0x120), 7, 6, 1);
        }
        break;
    case 5:
        func_0045af60(0, 0, 0, 0);
        if (*(s16 *)(t + 0x11E) == 0) {
            *(s16 *)(t + 0x11E) = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 7, 2);
            *(s16 *)(t + 0x120) = 5;
        } else {
            v = (s16)func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, 7, 2);
            *(s16 *)(t + 0x11E) = v;
            *(s16 *)(t + 0x120) = func_002b2d50((s16)v, *(s16 *)(t + 0x120), 7, 6, -1);
        }
        break;
    }
    for (i = 0; (s16)i < 9; i = (s16)(i + 1)) {
        func_002b68d0((s16)(i + 0x179), 0, 1);
    }
    diff = (s16)(*(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120));
    cur = diff;
    jj = 0;
    lim = diff + 6;
    while ((s16)cur < lim) {
        bid = (s16)cur + 0x179;
        func_002b2970(&sp90, 32.0f, (f32)(jj * 34 + 0x5B));
        func_002b6c30((s16)bid, sp90, jj * 5 + 0x6A, 152.0f);
        func_002b68d0((s16)bid, 0, 0);
        func_002b6d60((s16)bid);
        func_002b2a60(&cA4, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150((s16)bid);
        *(FclByte4 *)(p + 0x85) = cA4;
        cur = (s16)(cur + 1);
        jj = (s16)(jj + 1);
    }
    func_002b2a60(&cA0, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = cA0;
    p1 = func_002b6150((s16)(*(s16 *)(t + 0x120) * 2 + 0x1F4));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)(p + 0x85);
    func_002b2a60(&c9C, 0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150((s16)(diff + 0x179 + *(s16 *)(t + 0x120)));
    *(FclByte4 *)(p + 0x85) = c9C;
    func_002b2a60(&c98, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s16 *)(t + 0x120) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = c98;
    diff_f = (f32)(*(s16 *)(t + 0x11E) - *(s16 *)(t + 0x120));
    base = *(f32 *)(t + 0x124);
    fv = *(f32 *)(func_002b6150(0xA9) + 0x3C);
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = base * diff_f + fv;
    fv2 = *(f32 *)(func_002b6150(0xB1) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = fv2 + 52.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330060);
#endif

/* measured: nd 4 (4 attempts: separate-u8 slots 371, FclByte4 groups 212,
   s64 t17/t16 fix 185, t16 as s32 -> 4). MATCH-QUALITY: everything byte-
   identical except 4 rows — the four +0x168 6150-arg sites emit
   addu $v0,$s3,$v0 where retail has addu $v0,$v0,$s3 (scaled+base); the
   (u8 *)(lh*2 + arg2) + 1 spelling still folds to base+scaled in mwcc b210
   (the other ten sites' arg2 + lh*2 naturally emit base+scaled, matching).
   Key measured spellings: 2a60 4-byte groups MUST be FclByte4 locals (plain
   u8s alias and collapse the frame); heap stores as *(FclByte4 *)(p + 0x85)
   struct assignments (batched lbu/sb, never field-wise which interleaves);
   t17 (s8 load of obj+0x139) must be s64 so the (s16)t17-1 sequence emits
   dsll32/dsra32 16 + addiu, and the case-0 t16 local must be s32 (s64 adds a
   dsll32/dsra32 0 at the 2cb0 call); the switch is a plain 6-case switch
   (cases 2/3 empty) reproducing the jtbl dispatch; the 0xA/0xB if/else-if
   chain with the (s8)(obj+0x138)&1 / &2>>1 tests matches; case 1/4/5 inline
   (s16)((s16)t17-1) expressions compute into the arg register with no
   conversion. MATCHED this wave (was the 4-word addu-operand-order floor):
   the fix was (1) the M2C draft's real param types — arg1 is s64 (switch on
   (s8)arg1), arg2 is s32 (the D_00882FB0 table ADDRESS as an integer, NOT a
   u8* pointer); (2) NO named lh local in the switch cases — retail reloads
   *(s16 *)(obj + 0x11E) at each use, inline it; (3) the lever-3 static inline
   addOff helper (offset-first) for the 4 +0x168 sites — addOff(lh*2, arg2)
   emits addu $v0,$v0,$s3 (scaled+base) which the raw (u8*)(lh*2+arg2)+1
   spelling never did; (4) hoisted s8 temp3 for the 0xA/0xB chain with ==1
   tests. nd path 244->14->0. */
// FUN_003307B0
void func_003307b0(u8 *arg0, s64 arg1, s32 arg2) {
    FclByte4 sp8C, sp88, sp84, sp80, sp7C, sp78, sp74, sp70, sp6C, sp68;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    s64 t17 = (s8)obj[0x139];
    s8 temp3;
    u8 *p1, *p2;

    func_002b2a60(&sp8C, 0, 0, 0x66, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp8C;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    func_002b2a60(&sp88, 0xCC, 0xFF, 0xFF, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp88;
    func_002b2a60(&sp84, 0x25, 0x2F, 0x94, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp84;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        func_002b2a60(&sp80, 0xCC, 0xFF, 0xFF, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp80;
    }
    temp3 = (s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2);
    if (temp3 == 0xA) {
        if (((s8)obj[0x138] & 1) == 1) {
            func_002b2a60(&sp7C, 0xFF, 0xCC, 0xFF, 0xFF);
            p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
            *(FclByte4 *)(p1 + 0x85) = sp7C;
        }
    } else if ((temp3 == 0xB) && (((s32)((s8)obj[0x138] & 2) >> 1) == 1)) {
        func_002b2a60(&sp78, 0xFF, 0xCC, 0xFF, 0xFF);
        p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
        *(FclByte4 *)(p1 + 0x85) = sp78;
    }
    obj[0x13A] = 1;
    switch ((s8)arg1) {
    case 0: {
        s32 t16 = (s16)((s16)t17 - 1);
        if (*(s16 *)(obj + 0x11E) != t16) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(obj + 0x11E) = (s16)func_002b2cb0(*(s16 *)(obj + 0x11E), 1, t16, 0, 1);
        break;
    }
    case 1:
        if (*(s16 *)(obj + 0x11E) != 0) {
            func_0045af60(0, 0, 0, 0);
        }
        *(s16 *)(obj + 0x11E) = (s16)func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)((s16)t17 - 1), 1);
        break;
    case 2:
    case 3:
        break;
    case 4:
        func_0045af60(0, 0, 0, 0);
        *(s16 *)(obj + 0x11E) = (s16)func_002b2cb0(*(s16 *)(obj + 0x11E), 1, (s16)((s16)t17 - 1), 0, 2);
        break;
    case 5:
        func_0045af60(0, 0, 0, 0);
        *(s16 *)(obj + 0x11E) = (s16)func_002b2d00(*(s16 *)(obj + 0x11E), 1, 0, (s16)((s16)t17 - 1), 2);
        break;
    }
    func_002b2a60(&sp74, 0xC6, 0xEE, 1, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = sp74;
    p2 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    func_002b2a60(&sp70, 0x2D, 0x2D, 0x2D, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(addOff(*(s16 *)(obj + 0x11E) * 2, (u32)arg2) + 1) + 0x168));
    *(FclByte4 *)(p1 + 0x85) = sp70;
    func_002b2a60(&sp6C, 0x92, 0xC8, 7, 0xFF);
    p1 = func_002b6150((s16)((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) + 0x2FB));
    *(FclByte4 *)(p1 + 0x85) = sp6C;
    if ((s8)*(u8 *)(arg2 + *(s16 *)(obj + 0x11E) * 2) == 1) {
        func_002b2a60(&sp68, 0x2D, 0x2D, 0x2D, 0xFF);
        p1 = func_002b6150(0x175);
        *(FclByte4 *)(p1 + 0x85) = sp68;
    }
}
// FUN_00330E50
void func_00330e50(s32 arg0, s64 arg1, f32 fparg0, s32 arg2, u8 arg3, s32 arg4, f32 fparg1, f32 fparg2, void *arg5) {
    s64 *p;

    p = &arg1;
    func_0025ecd0(*(f32 *)p, *((f32 *)p + 1), fparg0, arg2, arg3, (s16)arg0, (void *)(u32)func_00331560(), arg4, 0, 0, 0.0f, fparg1, fparg2, arg5);
}
// FUN_00330F20
s32 func_00330f20(u8 *arg0) {
    s32 sp3C, sp38, sp34, sp30;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(t + 0x45) == 1) {
        return -1;
    }
    switch (*(s8 *)(t + 0)) {
    case 0:
        if (func_004553c0(*(u32 *)(t + 0xC)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x10)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x14)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x18)) == 0) {
            return 0;
        }
        *(u32 *)(t + 4) = func_0046aea0(D_00644D70);
        *(u32 *)(t + 8) = func_0046aea0(D_00644D90);
        *(u32 *)(t + 0x34) = func_004667d0(0, D_00644DB0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x38) = func_004667d0(0, D_00644DD0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x3C) = func_004667d0(0, D_00644DF0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x40) = func_004667d0(0, D_00644E10, 0, 0, 0, 0, 0, 0, 0, 0);
        *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
    case 1:
        if (func_0046a750(*(u32 *)(t + 4)) != 0 && func_0046a750(*(u32 *)(t + 8)) != 0) {
            *(u32 *)(t + 0x24) = func_004669d0(*(u32 *)(t + 0x34), &sp3C, 0);
            if (sp3C != 0) {
                func_00454bd0((u8 *)*(u32 *)(t + 0xC));
                *(u32 *)(t + 0xC) = 0;
                *(u32 *)(t + 0x34) = 0;
                *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
            }
        }
        break;
    case 2:
        *(u32 *)(t + 0x28) = func_004669d0(*(u32 *)(t + 0x38), &sp38, 0);
        if (sp38 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x10));
            *(u32 *)(t + 0x10) = 0;
            *(u32 *)(t + 0x38) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 3:
        *(u32 *)(t + 0x2C) = func_004669d0(*(u32 *)(t + 0x3C), &sp34, 0);
        if (sp34 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x14));
            *(u32 *)(t + 0x14) = 0;
            *(u32 *)(t + 0x3C) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 4:
        *(u32 *)(t + 0x30) = func_004669d0(*(u32 *)(t + 0x40), &sp30, 0);
        if (sp30 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x18));
            *(u32 *)(t + 0x18) = 0;
            *(u32 *)(t + 0x40) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 5:
        if (func_004553c0(*(u32 *)(t + 0x1C)) != 0 && func_004553c0(*(u32 *)(t + 0x20)) != 0) {
            *(s8 *)(t + 0x44) = func_002774d0(func_00455f70(D_00644E30, 0));
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 6:
        break;
    }
    return 0;
}

// FUN_003312E0
void func_003312e0(u8 *arg0) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0046b0d0((u8 *)*(u32 *)(t + 4));
    func_0046b0d0((u8 *)*(u32 *)(t + 8));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x24));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x28));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x2C));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x30));
    func_002777f0(*(s8 *)(t + 0x44));
    func_00454bd0((u8 *)*(u32 *)(t + 0x1C));
    func_00454bd0((u8 *)*(u32 *)(t + 0x20));
    D_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00331390
void func_00331390(void) {
    u8 *p;

    if (iGpffffb598 != 0) {
        iGpffffb598 = 0;
    }
    func_0044ea90(D_00644D30, 0x16A4);
    p = D_008873F4[0](1, 0x48, 0x40000);
    iGpffffb598 = (s32)func_00451de0(D_00644E48, 0xF, 0, 0, (void *)func_00330f20, (void *)func_003312e0, p);
    *(s8 *)(p + 0) = 0;
    *(s8 *)(p + 0x45) = 0;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B2);
    *(s32 *)(p + 0xC) = (s32)func_00454a60((u8 *)D_00644DB0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B3);
    *(s32 *)(p + 0x10) = (s32)func_00454a60((u8 *)D_00644DD0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B4);
    *(s32 *)(p + 0x14) = (s32)func_00454a60((u8 *)D_00644DF0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B5);
    *(s32 *)(p + 0x18) = (s32)func_00454a60((u8 *)D_00644E10, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B7);
    *(s32 *)(p + 0x1C) = (s32)func_00454a60((u8 *)D_00644E30, 0);
    *(s8 *)(p + 0x44) = -1;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B9);
    *(s32 *)(p + 0x20) = (s32)func_00454a60((u8 *)D_00644E60, 0);
}
