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
/* gate: object 309 against retail 264, +17.0% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
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
/* measured: probe_variants 755 differing words reloc-masked (V11 reassoc with opt_dead_assignments off; bare V11 762, V4 805, V2 816, V1 824); fnalign retail 920 vs object 896 instrs (-24, -2.61% PASS, 286 edits +2 reloc-only via --candidate v11_reassoc.c --quiet); live measure_guarded GUARDED_SCORE func_00315600: 755; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Walls (same rotation+scheduling as siblings 31cce0/324680/318840/316470, now at 755): D base retail $s1 hoisted vs object $v0 rematerialised per use; stack high-half retail folded lwc1 offset(sp) vs object addiu $s0,sp+0x18C + lwc1 ($s0); colours retail batched lbu/lbu/lbu then sb/sb/sb ($a2/$a1/$a0) vs object interleaved lbu/sb per byte ($v1); FPR retail $f1 vs object $f20 for 300.0f; residual_signature $s1->$s2 exchange (630 edits, 1 perm, 99 other) persists -- body already in 7o form (bare decls, statement assigns in retail order) so the eight probes are ties per handoff 7o; all logic matches: (s8)arg1 gate, 7-block + 5-draw (2e78a0/10+9, 2DB/19/2DC/2DD) + D_00643D70[tmp18] with 0/6/00110d30 colours + 17/18 + D_00643D70[idx2] tail vs 9x 6150 compact tail. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 -o /var/tmp/cold315600/m2c.c` (254 lines, (s64)+s8 residues de-noised to (u8*,s64)+(s8) casts, FclVec2 for 69f0, u8[4] per-byte colours) + `python3 -E -s tools/romwright_decompile.py func_00315600 -o /var/tmp/cold315600/rom.c` (282 lines, (ulonglong,char) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 --candidate V11=/var/tmp/cold315600/v11_reassoc.c` (762) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00315600 --candidate /var/tmp/cold315600/v11_reassoc.c --quiet` (920/896) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00315600` (755 with dead off, 762 bare) + `python3 -E -s tools/residual_signature.py src/Event/Fcl/y_fclCombineDraw.c func_00315600` (1 perm [$s1->$s2]); unit conventions per 0031fa20 (635 with opt_propagation off load-bearing, scoped as on 0032e570): propagation off helps V4 805->781 but hurts V11 762->775, dead off best 762->755. */
/* Rounds in batch order (count first): v1 824 (m2c+rom de-noise, s64 homes, f20+b, u8 colours, 961/924 +37 FAIL); v2 816 (-8 via raw/tmp18/b/2970/gate order, 961/924); v4 805 (-11 via D_ byte-offset idx*8, 956/924 +32 FAIL); v11 762 (-43 via 37/50/64/74/87 reassoc for 24+(13/26/40/50/63+sp188), 896/920 -24 PASS). Step2 pragmas on v11 bare 762: dead off 755 <-- better, loop_invariants/strength/unroll off 762 tie, O1 774 worse, propagation off 775 worse, O3/schedule on 775 worse, O4 777 worse, common off 789 worse, peephole off 794 worse, O0 911 worse (sweep; pairs best propagation+peephole 771 on V4, not adopted -- bare V11 already better). Step3 subscript tie: ((f32*)&sp)[0]/[1] 762, *(p+0x85) 762. Step4 decl-order tie: b/p swap 762, f20/b swap 762 (register hints tie 805 on V4). Stopped after three consecutive non-improving rounds above 60 (pragma best still 755>>60, subscript+decl ties). Banked v11+dead-off as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
// FUN_00315600 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_dead_assignments off
void func_00315600(u8 *arg0, s64 arg1) {
    extern s64 func_001060b0(void);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s64 func_00110a60(s32 arg0, s32 arg1);
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern f32 D_00643DA8[];
    extern f32 D_00643E28[];
    extern f32 D_00643E30[];
    u8 c1AC[4];
    u8 c1A8[4];
    u8 c1A4[4];
    u8 c1A0[4];
    u8 c19C[4];
    u8 c198[4];
    u8 c194[4];
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    s64 sp158;
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
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
    s64 sp50;
    s64 sp48;
    s64 sp40;
    s64 raw;
    s32 gate;
    s32 tmp18;
    s16 idx2;
    f32 f20;
    f32 *b;
    u8 *p;
    (void)arg0;
    raw = arg1;
    tmp18 = func_00110580((s16)func_001060b0());
    b = D_00643DA8;
    func_002b2970(&sp188, b[0], b[1]);
    gate = (s8)raw;
    f20 = 300.0f;
    if (gate == 0) {
        func_002b2970(&sp180, 24.0f + b[0], b[1]);
        func_002b6c30(7, sp180, 0x41, 94.0f);
        func_002b2a60(c1AC, 0x19, 0x19, 0x19, 0xFF);
        p = func_002b6150(7);
        p[0x85] = c1AC[0];
        p[0x86] = c1AC[1];
        p[0x87] = c1AC[2];
        p[0x88] = c1AC[3];
        func_002b2970(&sp178, f20 + (24.0f + b[0]), b[1]);
        func_002b2970(&sp170, 24.0f + b[0], b[1]);
        func_002b69f0(7, *(FclVec2 *)&sp178, *(FclVec2 *)&sp170, 0, 0xA, 0);
    } else {
        func_002b2970(&sp168, 24.0f + b[0], b[1]);
        func_002b2970(&sp160, 24.0f + (f20 + b[0]), b[1]);
        func_002b69f0(7, *(FclVec2 *)&sp168, *(FclVec2 *)&sp160, 0, 0xA, 0);
    }
    if (gate == 0) {
        s16 idA;
        s16 idAb;
        idA = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        func_002b2970(&sp158, 37.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(idA, sp158, 0x56, 89.0f);
        idAb = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        func_002b2970(&sp150, f20 + (37.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970(&sp148, 37.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idAb, *(FclVec2 *)&sp150, *(FclVec2 *)&sp148, 0, 0xA, 0);
        func_002b2970(&sp140, 50.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DB, sp140, 0x56, 89.0f);
        func_002b2970(&sp138, f20 + (50.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970(&sp130, 50.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DB, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 0xA, 0);
        func_002b2970(&sp128, 64.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x19, sp128, 0x56, 89.0f);
        func_002b2970(&sp120, f20 + (64.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970(&sp118, 64.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x19, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 0xA, 0);
        func_002b2970(&sp110, 74.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DC, sp110, 0x56, 89.0f);
        func_002b2970(&sp108, f20 + (74.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970(&sp100, 74.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DC, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 0xA, 0);
        func_002b2970(&spF8, 87.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b6c30(0x2DD, spF8, 0x56, 89.0f);
        func_002b2970(&spF0, f20 + (87.0f + *(f32 *)&sp188), *((f32 *)&sp188 + 1));
        func_002b2970(&spE8, 87.0f + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DD, *(FclVec2 *)&spF0, *(FclVec2 *)&spE8, 0, 0xA, 0);
        func_002b2970(&spE0, *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b6c30((s16)tmp18, spE0, 0x56, 90.0f);
        if (tmp18 == 0) {
            func_002b2a60(c1A8, 0xFF, 0xAC, 0x99, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A8[0];
            p[0x86] = c1A8[1];
            p[0x87] = c1A8[2];
            p[0x88] = c1A8[3];
        }
        if (tmp18 == 6) {
            func_002b2a60(c1A4, 0x99, 0xA4, 0xFF, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A4[0];
            p[0x86] = c1A4[1];
            p[0x87] = c1A4[2];
            p[0x88] = c1A4[3];
        }
        if (func_00110d30((s16)func_001060b0()) == 1) {
            func_002b2a60(c1A0, 0xFF, 0xAC, 0x99, 0xFF);
            p = func_002b6150((s16)tmp18);
            p[0x85] = c1A0[0];
            p[0x86] = c1A0[1];
            p[0x87] = c1A0[2];
            p[0x88] = c1A0[3];
        }
        func_002b2970(&spD8, f20 + *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b2970(&spD0, *(f32 *)((u8 *)D_00643D70 + tmp18 * 8), *(f32 *)((u8 *)D_00643D70 + tmp18 * 8 + 4));
        func_002b69f0((s16)tmp18, *(FclVec2 *)&spD8, *(FclVec2 *)&spD0, 0, 0xA, 0);
        b = D_00643E28;
        func_002b2970(&spC8, b[0], b[1]);
        func_002b6c30(0x17, spC8, 0x56, 93.0f);
        func_002b2a60(c19C, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x17);
        p[0x85] = c19C[0];
        p[0x86] = c19C[1];
        p[0x87] = c19C[2];
        p[0x88] = c19C[3];
        func_002b2970(&spC0, f20 + b[0], b[1]);
        func_002b2970(&spB8, b[0], b[1]);
        func_002b69f0(0x17, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 0xA, 0);
        b = D_00643E30;
        func_002b2970(&spB0, b[0], b[1]);
        func_002b6c30(0x18, spB0, 0x57, 92.0f);
        func_002b2a60(c198, 0x19, 0x19, 0x19, 0xFF);
        p = func_002b6150(0x18);
        p[0x85] = c198[0];
        p[0x86] = c198[1];
        p[0x87] = c198[2];
        p[0x88] = c198[3];
        func_002b2970(&spA8, f20 + b[0], b[1]);
        func_002b2970(&spA0, b[0], b[1]);
        func_002b69f0(0x18, *(FclVec2 *)&spA8, *(FclVec2 *)&spA0, 0, 0xA, 0);
        idx2 = (s16)((s8)func_00110a60(func_002e78a0() & 0xFF, func_002e78e0() & 0xFF) + 0x13);
        func_002b2970(&sp98, *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b6c30(idx2, sp98, 0x58, 91.0f);
        func_002b2a60(c194, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(idx2);
        p[0x85] = c194[0];
        p[0x86] = c194[1];
        p[0x87] = c194[2];
        p[0x88] = c194[3];
        func_002b2970(&sp90, f20 + *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b2970(&sp88, *(f32 *)((u8 *)D_00643D70 + idx2 * 8), *(f32 *)((u8 *)D_00643D70 + idx2 * 8 + 4));
        func_002b69f0(idx2, *(FclVec2 *)&sp90, *(FclVec2 *)&sp88, 0, 0xA, 0);
    } else {
        s16 idB;
        idB = (s16)(((func_002e78a0() & 0xFF) / 10) + 9);
        p = func_002b6150(idB);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp80, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idB, *(FclVec2 *)&sp188, *(FclVec2 *)&sp80, 0, 0xA, 0);
        p = func_002b6150(0x2DB);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp78, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DB, *(FclVec2 *)&sp188, *(FclVec2 *)&sp78, 0, 0xA, 0);
        p = func_002b6150(0x2DC);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp70, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DC, *(FclVec2 *)&sp188, *(FclVec2 *)&sp70, 0, 0xA, 0);
        p = func_002b6150(0x2DD);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp68, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x2DD, *(FclVec2 *)&sp188, *(FclVec2 *)&sp68, 0, 0xA, 0);
        p = func_002b6150(0x19);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp60, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x19, *(FclVec2 *)&sp188, *(FclVec2 *)&sp60, 0, 0xA, 0);
        p = func_002b6150((s16)tmp18);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp58, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0((s16)tmp18, *(FclVec2 *)&sp188, *(FclVec2 *)&sp58, 0, 0xA, 0);
        p = func_002b6150(0x17);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp50, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x17, *(FclVec2 *)&sp188, *(FclVec2 *)&sp50, 0, 0xA, 0);
        p = func_002b6150(0x18);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp48, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(0x18, *(FclVec2 *)&sp188, *(FclVec2 *)&sp48, 0, 0xA, 0);
        idx2 = (s16)((s8)func_00110a60(func_002e78a0() & 0xFF, func_002e78e0() & 0xFF) + 0x13);
        p = func_002b6150(idx2);
        *(f32 *)&sp188 = *(f32 *)(p + 0x38);
        *((f32 *)&sp188 + 1) = *(f32 *)(p + 0x3C);
        func_002b2970(&sp40, f20 + *(f32 *)&sp188, *((f32 *)&sp188 + 1));
        func_002b69f0(idx2, *(FclVec2 *)&sp188, *(FclVec2 *)&sp40, 0, 0xA, 0);
    }
}
#pragma opt_dead_assignments on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);
#endif

// measured: nd N/A (draw-family, s64-param floor). 53x 2970 + 19x 6c30 + 17x 6a70 + 18x 69f0 + 4x 6b40: same s64-arg-to-s32-param normalization floor as func_00315600; externs locked by matched callers. s64-param-normalization floor.
/* measured: probe_variants 516 differing words reloc-masked (V1); fnalign retail 644 vs object 653 instrs (+9, +1.40% PASS, 83 edits +8 reloc-only via --candidate v1.c --quiet); live measure_guarded GUARDED_SCORE func_00316470: 516; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Walls (same rotation+scheduling as siblings 31cce0/324680/318840, now at 516): D base retail $s1 hoisted vs object $v0 rematerialised per use ($s2 for AD8 block); stack high-half retail folded lwc1 offset(sp) vs object addiu $s1,sp+0x15C + lwc1 ($s1); colours retail batched lbu/lbu/lbu then sb/sb/sb ($a2/$a1/$a0) vs object interleaved lbu/sb per byte ($v1); FPR retail $f1 vs object $f20 for else-path 300.0f; digit 0x80/s16 retail $s1 vs object $s2; all logic matches: (s8)arg1==1 gate, four D blocks (0xC2/0xC1/0xC3/0xC4) + 0x69/(f32)0x167 + 1AD/D_00644AD8 + 2B3/(f32)0x23B + 26E/263-251 + 26F/251 with 00104c70 &0xFF/%10//10 digits. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00316470 -o /var/tmp/cold316470/m2c.c` (184 lines, (s64,s64)+s8 residues de-noised to (u8*,s64,s64)+(s8) casts, FclVec2 for 69f0, u8[4] per-byte colours) + `python3 -E -s tools/romwright_decompile.py func_00316470 -o /var/tmp/cold316470/rom.c` (218 lines, (ulonglong,char,char) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00316470 --candidate V1=/var/tmp/cold316470/v1.c` (516) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00316470 --candidate /var/tmp/cold316470/v1.c --quiet` (644/653) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00316470` (516). */
/* Rounds in batch order (count first): v1 516 (u8[4] colours, s64 sp158-sp50 homes, f20=300.0f + b pointer, (f32)0x167/0x23B/0x263/0x251 immediates, 653/644 exact-ish). Step2 pragmas tie: opt_loop_invariants on 516, opt_unroll_loops off 516, schedule off 516 (sweep also strength_reduction off 516 tie; schedule on 529, peephole off 532, propagation off 545, O1 561, common_subs off 572 worse). Step3 subscript tie: ((f32*)&sp)[0]/[1] 516, *b/ *(b+1) 516, *(p+0x85) 516. Step4 decl-order tie: b/p swap 516, f20/b swap 516, colours reverse 516. Stopped after three consecutive non-improving rounds above 60 (pragma+subscript+decl). Banked v1 as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
// FUN_00316470 NONMATCHING
#ifdef NON_MATCHING
void func_00316470(u8 *arg0, s64 arg1, s64 arg2) {
    extern s32 func_00104c70(s32);
    extern f32 D_00644380[];
    extern f32 D_00644378[];
    extern f32 D_00644388[];
    extern f32 D_00644390[];
    extern f32 D_00644AD8[];
    u8 c16C[4];
    u8 c168[4];
    u8 c164[4];
    s64 sp158;
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
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
    s64 sp50;
    f32 f20;
    f32 *b;
    u8 *p;
    (void)arg0;
    f20 = 300.0f;
    if ((s8)arg1 == 1) {
        b = D_00644380;
        func_002b2970(&sp158, b[0], b[1]);
        if ((s8)arg2 == 0) {
            func_002b2970(&sp150, b[0], b[1]);
            func_002b6c30(0xC2, sp150, 0x41, 100.0f);
            func_002b2970(&sp148, f20 + b[0], b[1]);
            func_002b2970(&sp140, b[0], b[1]);
            func_002b69f0(0xC2, *(FclVec2 *)&sp148, *(FclVec2 *)&sp140, 0, 0xA, 0);
        } else {
            func_002b2970(&sp138, b[0], b[1]);
            func_002b2970(&sp130, f20 + b[0], b[1]);
            func_002b69f0(0xC2, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 0xA, 0);
        }
        b = D_00644378;
        func_002b2970(&sp158, b[0], b[1]);
        if ((s8)arg2 == 0) {
            func_002b2970(&sp128, b[0], b[1]);
            func_002b6c30(0xC1, sp128, 0x41, 100.0f);
            func_002b2970(&sp120, f20 + b[0], b[1]);
            func_002b2970(&sp118, b[0], b[1]);
            func_002b69f0(0xC1, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 0xA, 0);
        } else {
            func_002b2970(&sp110, b[0], b[1]);
            func_002b2970(&sp108, f20 + b[0], b[1]);
            func_002b69f0(0xC1, *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 0xA, 0);
        }
        b = D_00644388;
        func_002b2970(&sp158, b[0], b[1]);
        if ((s8)arg2 == 0) {
            func_002b2970(&sp100, b[0], b[1]);
            func_002b6c30(0xC3, sp100, 0x56, 99.0f);
            func_002b2970(&spF8, f20 + b[0], b[1]);
            func_002b2970(&spF0, b[0], b[1]);
            func_002b69f0(0xC3, *(FclVec2 *)&spF8, *(FclVec2 *)&spF0, 0, 0xA, 0);
        } else {
            func_002b2970(&spE8, b[0], b[1]);
            func_002b2970(&spE0, f20 + b[0], b[1]);
            func_002b69f0(0xC3, *(FclVec2 *)&spE8, *(FclVec2 *)&spE0, 0, 0xA, 0);
        }
        b = D_00644390;
        func_002b2970(&sp158, b[0], b[1]);
        if ((s8)arg2 == 0) {
            func_002b2970(&spD8, b[0], b[1]);
            func_002b6c30(0xC4, spD8, 0x56, 99.0f);
            func_002b2970(&spD0, f20 + b[0], b[1]);
            func_002b2970(&spC8, b[0], b[1]);
            func_002b69f0(0xC4, *(FclVec2 *)&spD0, *(FclVec2 *)&spC8, 0, 0xA, 0);
        } else {
            func_002b2970(&spC0, b[0], b[1]);
            func_002b2970(&spB8, f20 + b[0], b[1]);
            func_002b69f0(0xC4, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 0xA, 0);
        }
    }
    func_002b2970(&sp158, (f32)0x167, 29.0f);
    if ((s8)arg2 == 0) {
        func_002b6c30(0x69, sp158, 0x56, 98.0f);
        func_002b2970(&spB0, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x69, *(FclVec2 *)&spB0, *(FclVec2 *)&sp158, 0, 0xA, 0);
        func_002b2a60(c16C, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x69);
        p[0x85] = c16C[0];
        p[0x86] = c16C[1];
        p[0x87] = c16C[2];
        p[0x88] = c16C[3];
    } else {
        func_002b2970(&spA8, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x69, *(FclVec2 *)&sp158, *(FclVec2 *)&spA8, 0, 0xA, 0);
    }
    b = D_00644AD8;
    func_002b2970(&sp158, b[0], b[1]);
    if ((s8)arg2 == 0) {
        func_002b2970(&spA0, b[0], b[1]);
        func_002b6c30(0x1AD, spA0, 0x41, 100.0f);
        func_002b2970(&sp98, f20 + b[0], b[1]);
        func_002b2970(&sp90, b[0], b[1]);
        func_002b69f0(0x1AD, *(FclVec2 *)&sp98, *(FclVec2 *)&sp90, 0, 0xA, 0);
        func_002b2a60(c168, 0x0E, 0x17, 0x49, 0xFF);
        p = func_002b6150(0x1AD);
        p[0x85] = c168[0];
        p[0x86] = c168[1];
        p[0x87] = c168[2];
        p[0x88] = c168[3];
        *(u8 *)(func_002b6150(0x1AD) + 0x6E) = 0x80;
    } else {
        func_002b2970(&sp88, b[0], b[1]);
        func_002b2970(&sp80, f20 + b[0], b[1]);
        func_002b69f0(0x1AD, *(FclVec2 *)&sp88, *(FclVec2 *)&sp80, 0, 0xA, 0);
    }
    func_002b2970(&sp158, (f32)0x23B, 50.0f);
    if ((s8)arg2 == 0) {
        func_002b6c30(0x2B3, sp158, 0x56, 189.0f);
        func_002b2970(&sp78, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x2B3, *(FclVec2 *)&sp78, *(FclVec2 *)&sp158, 0, 0xA, 0);
        func_002b2a60(c164, 0x49, 0x72, 0xFF, 0xFF);
        p = func_002b6150(0x2B3);
        p[0x85] = c164[0];
        p[0x86] = c164[1];
        p[0x87] = c164[2];
        p[0x88] = c164[3];
    } else {
        func_002b2970(&sp70, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x2B3, *(FclVec2 *)&sp158, *(FclVec2 *)&sp70, 0, 0xA, 0);
    }
    func_002b2970(&sp158, (f32)0x263, 50.0f);
    if ((func_00104c70(1) & 0xFF) < 0xA) {
        func_002b2970(&sp158, (f32)0x251, 50.0f);
    }
    if ((s8)arg2 == 0) {
        func_002b6c30(0x26E, sp158, 0x56, 46.0f);
        *(s16 *)(func_002b6150(0x26E) + 4) = (s16)((func_00104c70(1) & 0xFF) % 10 + 0x46);
        func_002b2970(&sp68, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x26E, *(FclVec2 *)&sp68, *(FclVec2 *)&sp158, 0, 0xA, 0);
    } else {
        func_002b2970(&sp60, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
        func_002b69f0(0x26E, *(FclVec2 *)&sp158, *(FclVec2 *)&sp60, 0, 0xA, 0);
    }
    func_002b2970(&sp158, (f32)0x251, 50.0f);
    if ((func_00104c70(1) & 0xFF) / 10 > 0) {
        if ((s8)arg2 == 0) {
            func_002b6c30(0x26F, sp158, 0x56, 46.0f);
            *(s16 *)(func_002b6150(0x26F) + 4) = (s16)((func_00104c70(1) & 0xFF) / 10 + 0x46);
            func_002b2970(&sp58, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
            func_002b69f0(0x26F, *(FclVec2 *)&sp58, *(FclVec2 *)&sp158, 0, 0xA, 0);
        } else {
            func_002b2970(&sp50, f20 + *(f32 *)&sp158, *((f32 *)&sp158 + 1));
            func_002b69f0(0x26F, *(FclVec2 *)&sp158, *(FclVec2 *)&sp50, 0, 0xA, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316470);
#endif

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
/* measured: probe_variants 821 differing words reloc-masked (V5B with opt_propagation off; bare V1 901, PROP 822, S64E 834 worse, FCLB 822 tie wrong shape, S32C 819 FAIL count, 6a70s16 821 <-- better); fnalign retail 973 vs object 962 instrs (-11, -1.13% PASS, 733 edits via --candidate v5b.c --quiet); live measure_guarded GUARDED_SCORE func_00317900: 821; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* measured 2026-09-19 (float-unshare+stack lane): probe_variants 769 differing words reloc-masked (A_STACK: unshare f22/f24/f25 to per-use 6.0f+bx/by/sp100x where retail rematerialises 6.0 per block, keep f20a/f21 shared where retail keeps 78/104+sp100y, sp218u decl first so sp218u at 0x218/sp210 at 0x210 matching retail folded lwc1, opt_propagation off kept; A 774 without stack, F22 785/F22F24 775/F22F25 784 singles, F20A 803/F21 800 worse so kept shared, S16ALL 787 with dsll/move exact 0/0 but 932 FAIL count, A_S16 789 undo, HOIST216/COLOUR ties, REV/V18LAST ties); fnalign retail 973 vs object 950 instrs (-23, -2.36% PASS, 476 edits via --candidate v_A_stack.c --quiet, was 725); census add.s +7, addiu +10, cvt.s.w -3, dsll32 +17, dsra32 +17, jal +3, lui -23, lwc1 +6, mov.s -13, move -18, mtc1 -26, nop -7, sub.s +7 (was mtc1 -27/lui -24/move -18/dsll+17/addiu+10/mov.s -10/nop -8/sub.s+7/add.s+5/lwc1+4 at 789); live measure_guarded GUARDED_SCORE func_00317900: 769; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* measured 2026-09-18 (float-hoist lane): probe_variants 789 differing words reloc-masked (BXBY: bx/by locals for sp218u halves, opt_propagation off kept; ALL 793 with 12 saved FAIL count, CXCY 775 with 0x230 frame mismatch, V5B 821 baseline); fnalign retail 973 vs object 946 instrs (-27, -2.77% PASS, 725 edits via --candidate new_banked.c --quiet); live measure_guarded GUARDED_SCORE func_00317900: 789; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Hoist rationale (per thread lwc1+34/mov.s-30 swap): body reloaded sp218u halves (bx 17 uses, by 18 uses) via lwc1 where retail keeps them live via mov.s; giving them ordinary f32 locals (bx,by) with lifetime spanning uses converts reloads to moves and lets CSE share derived 6+bx/62+by etc. Opclass BXBY: lwc1 +34->+4, mov.s -30->-10, add.s +20->+5, nop -19->-8, addiu +14->+10; frame 0x230->0x240 matching retail with 10 saved f20-f29 matching retail (was 7 f20-f26). Remaining walls: lui -24/mtc1 -27 (retail rematerialises 6.0/12.0/62.0 etc. per-use into temps where object shares one lui in saved reg across calls), sub.s +7 (by-44/bx-12 per-use vs shared), s64-param normalization dsll32/dsra32 +17/move -18 and integer rotation $s4/$s3/$s5 vs $s1/$s4/$s3 persist as sibling floors. */
/* Walls (same rotation+scheduling as siblings 315600/31fa20/318840, now at 821): saved-reg retail $s4/$s3/$s5 vs object $s1/$s4/$s3 rotation; stack high-half retail folded lwc1 offset(sp) vs object addiu $sX,sp+off + lwc1; colours retail batched lbu/lbu/lbu then sb/sb/sb ($a2/$a1/$a0) vs object interleaved lbu/sb per byte ($v1); FPR retail $f20-$f29 vs object $f21-$f24 rotation; s64-param normalization (dsll32/dsra32 at 6150/6c30/69f0/6a70/68d0 where retail passes raw) persists -- body already in 7o form (bare decls, statement assigns in retail order) so subscript/decl probes are ties; all logic matches: (s8)arg3 6/7/8 if-chain to EF/EB/ED, 7-block + 46d chain (31560/d200/b260/d280) with (5.0f+sp)-2.0f*(hval/10.0f) fusion + iGpffff8360 for A0/AC, 1DC/FC/216-21B draws with 0x46/0x6A/0x82 and 0xE0/0xFF/0x33 and 0x42/0x6E/0xFF colours. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 -o /var/tmp/cold317900/m2c.c` (287 lines, (void*,s64x3,s16,s64x2) residues de-noised to (u8*,s64x6)+(s8)/(s16) casts, FclVec2 for 69f0, u8[4] per-byte colours) + `python3 -E -s tools/romwright_decompile.py func_00317900 -o /var/tmp/cold317900/rom.c` (321 lines, (int,ulonglongx2,char,ulonglong,int,short) arity confirmed, CONCAT44/stack extents confirmed); `python3 -E -s tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 --candidate V1=/var/tmp/cold317900/v1.c` (901) + `--candidate PROP=/var/tmp/cold317900/v1_opt_propagation_off.c` (822) + `python3 -E -s tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00317900 --candidate /var/tmp/cold317900/v5b.c --quiet` (973/962) + `python3 -E -s tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_00317900` (821). */
/* Rounds in batch order (count first): v1 901 (m2c+rom de-noise, s64 homes spF8/sp100/sp210-sp108 + sp218u pair, f24/f25 + b?/t/p/h, u8 colours, 1063/976 +87 FAIL); PROP 822 (-79 via opt_propagation off, 956/973 -17 PASS) <-- better (try all three early per assignment: dead off 907 worse, peephole off 919 worse; sibling 315600 dead 755 and 302770 peephole 728 tried early, only prop helps here). Step2 pragmas on v1 bare 901: prop off 822 <-- better, schedule on 845, O4 834, O3 845, common off 910 worse, dead off 907 worse, peephole off 919 worse, loopinv/strength/unroll 901 tie, O1 933 worse, O0 1144 worse (sweep; pairs prop+schedule 834/prop+dead 822 tie/prop+peephole 827/prop+common 933 worse, not adopted -- bare PROP already better). Step3 subscript tie: ((f32*)&sp)[0]/[1] 822, *(p+0x85) 822. Step4 decl-order tie: t/p swap 822, f24/f25 swap 822, colours reverse 822. v5 821 (-1 via (s16)t18/t26/t17b for 6a70 last, 962/973 -11 PASS); reassoc tie (6.0f+sp vs sp+6.0f 821). Stopped after two consecutive non-improving rounds above 60 (reassoc+decl, following three-way tie before v5). Banked v5b as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
// FUN_00317900 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_00317900(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6) {
    u8 c23C[4];
    u8 c238[4];
    u8 c234[4];
    u8 c230[4];
    u8 c22C[4];
    u8 c228[4];
    u8 c224[4];
    s64 sp218u;
    s64 sp210;
    s64 sp208;
    s64 sp200;
    s64 sp1F8;
    s64 sp1F0;
    s64 sp1E8;
    s64 sp1E0;
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    s64 sp1A8;
    s64 sp1A0;
    s64 sp198;
    s64 sp190;
    s64 sp188;
    s64 sp180;
    s64 sp178;
    s64 sp170;
    s64 sp168;
    s64 sp160;
    s64 sp158;
    s64 sp150;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
    s64 sp100;
    s64 spF8;
    s64 spD0;
    s32 v18;
    s32 t22;
    s32 t16;
    s32 t17;
    s32 t23;
    s32 t30;
    s32 tFD;
    s32 tD0;
    s32 t18;
    s32 t26;
    s32 t17b;
    f32 f20a;
    f32 f21;
    f32 bx;
    f32 by;
    u8 *t;
    u8 *p;
    u8 *h;
    f32 hval;
    f32 fmsub;
    f32 fmsub2;
    f32 ftmp;
    t = *(u8 **)(arg0 + 0x38);
    spF8 = arg1;
    sp100 = arg2;
    func_002b2970(&sp210, *(f32 *)&spF8, *((f32 *)&spF8 + 1));
    *(f32 *)&sp218u = *(f32 *)&sp210;
    *((f32 *)&sp218u + 1) = *((f32 *)&sp210 + 1);
    bx = *(f32 *)&sp218u;
    by = *((f32 *)&sp218u + 1);
    t17 = (s8)arg3;
    v18 = (s16)(t17 * 2 + 0xDF);
    if (t17 == 6) {
        v18 = 0xEF;
    } else if (t17 == 7) {
        v18 = 0xEB;
    } else if (t17 == 8) {
        v18 = 0xED;
    }
    t22 = (s16)arg6;
    t16 = t22 + 1;
    func_002b2970(&sp208, (6.0f + bx), (4.0f + by));
    func_002b6c30((s16)v18, sp208, t16, (f32)arg5);
    func_002b2a60(c23C, 0x46, 0x6A, 0x82, 0xFF);
    p = func_002b6150((s16)v18);
    p[0x85] = c23C[0];
    p[0x86] = c23C[1];
    p[0x87] = c23C[2];
    p[0x88] = c23C[3];
    *(f32 *)(func_002b6150((s16)v18) + 0xA0) = 1.0f;
    *(f32 *)(func_002b6150((s16)v18) + 0xAC) = 1.0f;
    func_002b2970(&sp200, (6.0f + bx), (4.0f + by));
    func_002b2970(&sp1F8, (6.0f + *(f32 *)&sp100), 4.0f + *((f32 *)&sp100 + 1));
    func_002b69f0((s16)v18, *(FclVec2 *)&sp200, *(FclVec2 *)&sp1F8, 0, 8, (s16)arg4);
    t23 = t17 + 0x20D;
    tD0 = (s16)arg5 + 1;
    spD0 = tD0;
    func_002b6c30((s16)t23, sp100, t22, (f32)tD0);
    f20a = 78.0f + *((f32 *)&sp100 + 1);
    t30 = t17 + 0xF2;
    func_002b2970(&sp1F0, (6.0f + *(f32 *)&sp100), f20a);
    func_002b6c30((s16)t30, sp1F0, t16, (f32)spD0);
    func_002b2a60(c238, 0x46, 0x6A, 0x82, 0xFF);
    p = func_002b6150((s16)t30);
    p[0x85] = c238[0];
    p[0x86] = c238[1];
    p[0x87] = c238[2];
    p[0x88] = c238[3];
    f21 = 104.0f + *((f32 *)&sp100 + 1);
    tFD = t17 + 0xFD;
    func_002b2970(&sp1E8, *(f32 *)&sp100 - 12.0f, f21);
    func_002b6c30((s16)tFD, sp1E8, t22 + 2, (f32)arg5);
    func_002b2a60(c234, 0xE0, 0xFF, 0x33, 0xFF);
    p = func_002b6150((s16)tFD);
    p[0x85] = c234[0];
    p[0x86] = c234[1];
    p[0x87] = c234[2];
    p[0x88] = c234[3];
    if (t17 == *(s16 *)((*(s8 *)(t + 0xB4) * 10 + (s32)t) + 0xC8)) {
        func_002b2970(&sp1E0, (6.0f + bx), (4.0f + by));
        func_002b6c30((s16)v18, sp1E0, 0xAB, 59.0f);
        ftmp = iGpffff8360;
        *(f32 *)(func_002b6150((s16)v18) + 0xA0) = ftmp;
        *(f32 *)(func_002b6150((s16)v18) + 0xAC) = ftmp;
        h = func_0046d200(func_00331560(), (u32)v18);
        hval = func_0046b260(h);
        fmsub = (5.0f + bx) - 2.0f * (hval / 10.0f);
        func_002b2970(&sp1D8, fmsub, by - 3.0f);
        hval = func_0046b260(h);
        fmsub2 = (5.0f + *(f32 *)&sp100) - 2.0f * (hval / 10.0f);
        func_002b2970(&sp1D0, fmsub2, *((f32 *)&sp100 + 1) - 3.0f);
        func_002b69f0((s16)v18, *(FclVec2 *)&sp1D8, *(FclVec2 *)&sp1D0, 0, 8, (s16)arg4);
        func_0046d280(h);
        func_002b2a60(c230, 0xE0, 0xFF, 0x33, 0xFF);
        p = func_002b6150((s16)v18);
        p[0x85] = c230[0];
        p[0x86] = c230[1];
        p[0x87] = c230[2];
        p[0x88] = c230[3];
        func_002b6c30(0x1DC, sp218u, 0xAA, 60.0f);
        func_002b69f0(0x1DC, *(FclVec2 *)&sp218u, *(FclVec2 *)&sp100, 0, 8, (s16)arg4);
        func_002b2970(&sp1C8, bx - 12.0f, 104.0f + by);
        func_002b2970(&sp1C0, *(f32 *)&sp100 - 12.0f, f21);
        func_002b69f0((s16)tFD, *(FclVec2 *)&sp1C8, *(FclVec2 *)&sp1C0, 0, 8, (s16)arg4);
        func_002b68d0((s16)t23, 0, 1);
        if (t17 < 6) {
            func_002b2970(&sp1B8, bx - 12.0f, 123.0f + by);
            func_002b6c30(0xFC, sp1B8, 0xAC, 59.0f);
            func_002b2970(&sp1B0, bx - 12.0f, 123.0f + by);
            func_002b2970(&sp1A8, *(f32 *)&sp100 - 12.0f, 123.0f + *((f32 *)&sp100 + 1));
            func_002b69f0(0xFC, *(FclVec2 *)&sp1B0, *(FclVec2 *)&sp1A8, 0, 8, (s16)arg4);
            func_002b2a60(c22C, 0xE0, 0xFF, 0x33, 0xFF);
            p = func_002b6150(0xFC);
            p[0x85] = c22C[0];
            p[0x86] = c22C[1];
            p[0x87] = c22C[2];
            p[0x88] = c22C[3];
        }
        func_002b68d0((s16)t30, 0, 1);
        func_002b7750(0x216, 0x87);
        p = func_002b6150(0x216);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp1A0, 6.0f + bx, 62.0f + by);
        func_002b6c30(0x216, sp1A0, 0xAA, 62.0f);
        func_002b2970(&sp198, 6.0f + bx, 62.0f + by);
        func_002b2970(&sp190, 6.0f + *(f32 *)&sp100, 62.0f + *((f32 *)&sp100 + 1));
        func_002b69f0(0x216, *(FclVec2 *)&sp198, *(FclVec2 *)&sp190, 0, 8, (s16)arg4);
        t18 = (s16)arg4 + 8;
        func_002b6a70(0x216, 0x40, 0x80, 1, 0x3C, (s16)t18);
        p = func_002b6150(0x216);
    p[0x73] = 1;
        func_002b68d0(0x216, 0xB, 0);
        func_002b7750(0x217, 0x87);
        p = func_002b6150(0x217);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp188, 33.0f + bx, 62.0f + by);
        func_002b6c30(0x217, sp188, 0xAA, 62.0f);
        func_002b2970(&sp180, 33.0f + bx, 62.0f + by);
        func_002b2970(&sp178, 33.0f + *(f32 *)&sp100, 62.0f + *((f32 *)&sp100 + 1));
        func_002b69f0(0x217, *(FclVec2 *)&sp180, *(FclVec2 *)&sp178, 0, 8, (s16)arg4);
        t26 = (s16)arg4 + 0x26;
        func_002b6a70(0x217, 0x40, 0x80, 1, 0x3C, (s16)t26);
        p = func_002b6150(0x217);
    p[0x73] = 1;
        func_002b68d0(0x217, 0xB, 0);
        func_002b7750(0x218, 0x86);
        p = func_002b6150(0x218);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp170, 20.0f + bx, 62.0f + by);
        func_002b6c30(0x218, sp170, 0xAA, 61.0f);
        func_002b2970(&sp168, 20.0f + bx, 62.0f + by);
        func_002b2970(&sp160, 20.0f + *(f32 *)&sp100, 62.0f + *((f32 *)&sp100 + 1));
        func_002b69f0(0x218, *(FclVec2 *)&sp168, *(FclVec2 *)&sp160, 0, 8, (s16)arg4);
        t17b = (s16)arg4 + 0x17;
        func_002b6a70(0x218, 0x40, 0x80, 1, 0x3C, (s16)t17b);
        p = func_002b6150(0x218);
    p[0x73] = 1;
        func_002b68d0(0x218, 0xB, 0);
        func_002b7750(0x219, 0x89);
        p = func_002b6150(0x219);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp158, 6.0f + bx, by - 44.0f);
        func_002b6c30(0x219, sp158, 0xAA, 62.0f);
        func_002b2970(&sp150, 6.0f + bx, by - 44.0f);
        func_002b2970(&sp148, 6.0f + *(f32 *)&sp100, *((f32 *)&sp100 + 1) - 44.0f);
        func_002b69f0(0x219, *(FclVec2 *)&sp150, *(FclVec2 *)&sp148, 0, 8, (s16)arg4);
        func_002b6a70(0x219, 0x80, 0xFF, 1, 0x3C, (s16)t18);
        p = func_002b6150(0x219);
    p[0x73] = 1;
        func_002b68d0(0x219, 0xB, 0);
        func_002b7750(0x21A, 0x89);
        p = func_002b6150(0x21A);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp140, 33.0f + bx, by - 44.0f);
        func_002b6c30(0x21A, sp140, 0xAA, 62.0f);
        func_002b2970(&sp138, 33.0f + bx, by - 44.0f);
        func_002b2970(&sp130, 33.0f + *(f32 *)&sp100, *((f32 *)&sp100 + 1) - 44.0f);
        func_002b69f0(0x21A, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 8, (s16)arg4);
        func_002b6a70(0x21A, 0x80, 0xFF, 1, 0x3C, (s16)t26);
        p = func_002b6150(0x21A);
    p[0x73] = 1;
        func_002b68d0(0x21A, 0xB, 0);
        func_002b7750(0x21B, 0x88);
        p = func_002b6150(0x21B);
    *(s16 *)(p + 0x10) = 0;
        func_002b2970(&sp128, 20.0f + bx, by - 44.0f);
        func_002b6c30(0x21B, sp128, 0xAA, 61.0f);
        func_002b2970(&sp120, 20.0f + bx, by - 44.0f);
        func_002b2970(&sp118, 20.0f + *(f32 *)&sp100, *((f32 *)&sp100 + 1) - 44.0f);
        func_002b69f0(0x21B, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 8, (s16)arg4);
        func_002b6a70(0x21B, 0x80, 0xFF, 1, 0x3C, (s16)t17b);
        p = func_002b6150(0x21B);
    p[0x73] = 1;
        func_002b68d0(0x21B, 0xB, 0);
        return;
    }
    func_002b69f0((s16)t23, *(FclVec2 *)&sp218u, *(FclVec2 *)&sp100, 0, 8, (s16)arg4);
    func_002b2970(&sp110, (6.0f + bx), 78.0f + by);
    func_002b2970(&sp108, (6.0f + *(f32 *)&sp100), f20a);
    func_002b69f0((s16)(t17 + 0xF2), *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 8, (s16)arg4);
    func_002b2a60(c228, 0x42, 0x6E, 0xFF, 0xFF);
    p = func_002b6150((s16)(t17 + 0xF2));
    p[0x85] = c228[0];
    p[0x86] = c228[1];
    p[0x87] = c228[2];
    p[0x88] = c228[3];
    func_002b68d0((s16)tFD, 0, 1);
    func_002b2a60(c224, 0x42, 0x6E, 0xFF, 0xFF);
    p = func_002b6150((s16)v18);
    p[0x85] = c224[0];
    p[0x86] = c224[1];
    p[0x87] = c224[2];
    p[0x88] = c224[3];
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);
#endif

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
/* measured: probe_variants 566 differing words reloc-masked (V1 best; LOOP/UNROLL/SCHED/SUB1/SUB2/WB/FREV/CREV all 566 tie) via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0031c2b0 --candidate V1=/var/tmp/cold31c2b0/v1.c [...]`; fnalign retail 652 vs object 670 instrs (+18, +2.76% PASS; 272 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031c2b0 --candidate /var/tmp/cold31c2b0/v1.c --quiet`; live measure_guarded GUARDED_SCORE func_0031c2b0: 566. Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_0031c2b0 -o /var/tmp/cold31c2b0/m2c.c` (198 lines, (s16,s64,s64) + s8/s16 residues de-noised to (u8* unused,s16,s64,s64) + (s8)/(s16) casts) + `python3 -E -s tools/romwright_decompile.py func_0031c2b0 -o /var/tmp/cold31c2b0/rom.c` (236 lines, (ulonglong x4) arity confirmed, CONCAT44/stack extents confirmed); verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Rounds in batch order (count first): v1 566 (u8[4] colours, s64 sp148-sp70 homes, f20-24 + w/b + t16/p, 670/652 exact-ish). Step2 pragmas tie: opt_loop_invariants on 566, opt_unroll_loops off 566, schedule off 566. Step3 subscript tie: ((s16*)...)[1]/((u8*)...)[4]/((s16*)6150)[2] 566, ((f32*)&sp)[0]/[1] 566. Step4 decl-order tie: w/b swap 566, f24-20 reverse 566, colours reverse 566. Stopped after three consecutive non-improving rounds above 60 (pragma+subscript+decl). Banked v1 as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
/* Walls (same rotation+scheduling as siblings 31cce0/3233d0/324680, now at 566): frame 0x180 vs retail 0x170 (+0x10, all stack offsets +0x10); saved-reg rotation shifting every lh/lbu/sb + ld/sd base and slti/div colour; FPR rotation plus object materialised `addiu sp + lwc1` where retail folds `lwc1 offset(sp)`; colour stores retail batched lbu x4 then sb x4 vs object interleaved per-byte; w/b dsll32/dsra32 + andi chain neutral. All logic matches: 2e48a0 u16/u8 pair, 0x7C t16, six sprite blocks (0x7C/0x228/0x1A2/0x25C/0x54/0x74 with 2970+6c30+2a60+6150+69f0), b<10 vs >=10 split to 26A/single+68d0 vs 26A+26B with 00109280 &0xFF/%10//10 digits plus trailing 0x74. */
// FUN_0031C2B0 NONMATCHING
#ifdef NON_MATCHING
void func_0031c2b0(u8 *arg0, s16 arg1, s64 arg2, s64 arg3) {
    u8 c16C[4];
    u8 c168[4];
    u8 c164[4];
    u8 c160[4];
    u8 c15C[4];
    u8 c158[4];
    u8 c154[4];
    u8 c150[4];
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
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
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    s16 w;
    s16 b;
    u8 t16;
    u8 *p;
    (void)arg0;
    w = *(s16 *)(func_002e48a0(0, arg1) + 2);
    b = *(u8 *)(func_002e48a0(0, arg1) + 4);
    sp148 = arg2;
    t16 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
    func_002b2970(&sp140, *(f32 *)&sp148, *((f32 *)&sp148 + 1) - 2.0f);
    func_002b6c30(0x7C, sp140, 0x58, 124.0f);
    func_002b2970(&sp138, *(f32 *)&arg2, *((f32 *)&arg2 + 1) - 2.0f);
    func_002b2970(&sp130, *(f32 *)&arg3, *((f32 *)&arg3 + 1) - 2.0f);
    func_002b69f0(0x7C, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 0xA, 0);
    f20 = *((f32 *)&sp148 + 1) - 2.0f;
    f23 = 36.0f + *(f32 *)&sp148;
    func_002b2970(&sp128, f23, f20);
    func_002b6c30(0x228, sp128, 0x58, 126.0f);
    func_002b2a60(c16C, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x228);
    p[0x85] = c16C[0];
    p[0x86] = c16C[1];
    p[0x87] = c16C[2];
    p[0x88] = c16C[3];
    p = func_002b6150(0x228);
    *(u8 *)(p + 0x6E) = t16;
    f24 = *((f32 *)&arg3 + 1) - 2.0f;
    func_002b2970(&sp120, f23, f20);
    func_002b2970(&sp118, 36.0f + *(f32 *)&arg3, f24);
    func_002b69f0(0x228, *(FclVec2 *)&sp120, *(FclVec2 *)&sp118, 0, 0xA, 0);
    f23 = 94.0f + *(f32 *)&sp148;
    func_002b2970(&sp110, f23, f20);
    func_002b6c30(0x1A2, sp110, 0x58, 126.0f);
    func_002b2a60(c168, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x1A2);
    p[0x85] = c168[0];
    p[0x86] = c168[1];
    p[0x87] = c168[2];
    p[0x88] = c168[3];
    p = func_002b6150(0x1A2);
    *(u8 *)(p + 0x6E) = t16;
    func_002b2970(&sp108, f23, f20);
    func_002b2970(&sp100, 94.0f + *(f32 *)&arg3, f24);
    func_002b69f0(0x1A2, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 0xA, 0);
    f23 = *((f32 *)&sp148 + 1);
    f20 = 43.0f + *(f32 *)&sp148;
    func_002b2970(&spF8, f20, f23);
    func_002b6c30(0x25C, spF8, 0x59, 46.0f);
    *(s16 *)(func_002b6150(0x25C) + 4) = (s16)((s16)(func_00109280(w & 0xFFFF) & 0xFF) + 0x1B);
    func_002b2a60(c164, 0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150(0x25C);
    p[0x85] = c164[0];
    p[0x86] = c164[1];
    p[0x87] = c164[2];
    p[0x88] = c164[3];
    p = func_002b6150(0x25C);
    *(u8 *)(p + 0x6E) = t16;
    func_002b2970(&spF0, f20, f23);
    func_002b2970(&spE8, 43.0f + *(f32 *)&arg3, *((f32 *)&arg3 + 1));
    func_002b69f0(0x25C, *(FclVec2 *)&spF0, *(FclVec2 *)&spE8, 0, 0xA, 0);
    f22 = 6.0f + *((f32 *)&sp148 + 1);
    func_002b2970(&spE0, (f32)0x117 + *(f32 *)&sp148, f22);
    func_002b6c30(0x54, spE0, 0x56, 189.0f);
    func_002b2a60(c160, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x54);
    p[0x85] = c160[0];
    p[0x86] = c160[1];
    p[0x87] = c160[2];
    p[0x88] = c160[3];
    p = func_002b6150(0x54);
    *(u8 *)(p + 0x6E) = t16;
    f21 = 6.0f + *((f32 *)&arg3 + 1);
    func_002b2970(&spD8, (f32)0x115 + *(f32 *)&sp148, f22);
    func_002b2970(&spD0, (f32)0x115 + *(f32 *)&arg3, f21);
    func_002b69f0(0x54, *(FclVec2 *)&spD8, *(FclVec2 *)&spD0, 0, 0xA, 0);
    if (b >= 0xA) {
        f20 = 6.0f + *((f32 *)&sp148 + 1);
        f21 = 320.0f + *(f32 *)&sp148;
        func_002b2970(&spC8, f21, f20);
        func_002b6c30(0x26A, spC8, 0x59, 46.0f);
        *(s16 *)(func_002b6150(0x26A) + 4) = (s16)(b % 10 + 0x46);
        func_002b2a60(c15C, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x26A);
        p[0x85] = c15C[0];
        p[0x86] = c15C[1];
        p[0x87] = c15C[2];
        p[0x88] = c15C[3];
        f22 = 6.0f + *((f32 *)&arg3 + 1);
        func_002b2970(&spC0, f21, f20);
        func_002b2970(&spB8, 320.0f + *(f32 *)&arg3, f22);
        func_002b69f0(0x26A, *(FclVec2 *)&spC0, *(FclVec2 *)&spB8, 0, 0xA, 0);
        f21 = (f32)0x12D + *(f32 *)&sp148;
        func_002b2970(&spB0, f21, f20);
        func_002b6c30(0x26B, spB0, 0x59, 46.0f);
        *(s16 *)(func_002b6150(0x26B) + 4) = (s16)(b / 10 + 0x46);
        func_002b2a60(c158, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x26B);
        p[0x85] = c158[0];
        p[0x86] = c158[1];
        p[0x87] = c158[2];
        p[0x88] = c158[3];
        func_002b2970(&spA8, f21, f20);
        func_002b2970(&spA0, (f32)0x12D + *(f32 *)&arg3, f22);
        func_002b69f0(0x26B, *(FclVec2 *)&spA8, *(FclVec2 *)&spA0, 0, 0xA, 0);
    } else {
        f22 = 6.0f + *((f32 *)&sp148 + 1);
        func_002b2970(&sp98, (f32)0x13D + *(f32 *)&sp148, f22);
        func_002b6c30(0x26A, sp98, 0x59, 46.0f);
        *(s16 *)(func_002b6150(0x26A) + 4) = (s16)(b % 10 + 0x46);
        func_002b2a60(c154, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x26A);
        p[0x85] = c154[0];
        p[0x86] = c154[1];
        p[0x87] = c154[2];
        p[0x88] = c154[3];
        f21 = 6.0f + *((f32 *)&arg3 + 1);
        func_002b2970(&sp90, (f32)0x137 + *(f32 *)&sp148, f22);
        func_002b2970(&sp88, (f32)0x137 + *(f32 *)&arg3, f21);
        func_002b69f0(0x26A, *(FclVec2 *)&sp90, *(FclVec2 *)&sp88, 0, 0xA, 0);
        func_002b68d0(0x26B, 0, 1);
    }
    f22 = 13.0f + *((f32 *)&sp148 + 1);
    f20 = (f32)0x14D + *(f32 *)&sp148;
    func_002b2970(&sp80, f20, f22);
    func_002b6c30(0x74, sp80, 0x58, 188.0f);
    func_002b2a60(c150, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x74);
    p[0x85] = c150[0];
    p[0x86] = c150[1];
    p[0x87] = c150[2];
    p[0x88] = c150[3];
    p = func_002b6150(0x74);
    *(u8 *)(p + 0x6E) = t16;
    f21 = 13.0f + *((f32 *)&arg3 + 1);
    func_002b2970(&sp78, f20, f22);
    func_002b2970(&sp70, (f32)0x14D + *(f32 *)&arg3, f21);
    func_002b69f0(0x74, *(FclVec2 *)&sp78, *(FclVec2 *)&sp70, 0, 0xA, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031c2b0);
#endif

// measured: nd N/A (draw-family, s64-param floor). Same packed-float + 6c30/69f0/6a70 pattern as func_0031c2b0/1fa20: s64-arg normalization + float-pair register hoist. s64-param + float-pair floor.
/* measured: probe_variants 507 differing words reloc-masked (V2 best; V1 514, LOOP/UNROLL/SCHED/V3/V4/V5/V6/V7 all 507 tie) via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_0031cce0 --candidate V2=/var/tmp/cold31cce0/v2.c [...]`; fnalign retail 596 vs object 601 instrs (+5, +0.84% PASS; 221 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031cce0 --candidate /var/tmp/cold31cce0/v2.c --quiet`; live measure_guarded GUARDED_SCORE func_0031cce0: 507. Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_0031cce0 -o /var/tmp/cold31cce0/m2c.c` (179 lines, (s16,s64,s64) + s8/s16 residues de-noised to (u8* unused,s16,s64,s64) + (s8)/(s16) casts) + `python3 -E -s tools/romwright_decompile.py func_0031cce0 -o /var/tmp/cold31cce0/rw.c` (215 lines, arity 4 confirmed, widths ignored) + `--types` (int,int,void*,float ignored). */
/* Rounds in batch order (count first): v1 514 (u8[4] colours, s64 temps, f20-24 + tA-tC, sp68/sp70 homes: 604/596); v2 507 (-7 via drop sp68/sp70 homes to arg halves + reuse f20-24, 601/596 exact-ish). Step2 pragmas tie: opt_loop_invariants on 507, opt_unroll_loops off 507, schedule off 507 (sched_on variant also 507). Step3 subscript tie: ((s16*)...)[1]/((u8*)...)[4]/((s16*)6150)[2] 507, ((f32*)&sp)[0]/[1] 507. Step4 decl-order tie: w/b swap 507, f24-20 reverse 507, c144-15C reverse 507. Stopped after three consecutive non-improving rounds above 60 (pragma+subscript+decl). Banked v2 as guarded floor (within 3%, compiles clean under -DNON_MATCHING, verify 37 MATCH/33 ASM, lint 0). */
/* Walls (same rotation+scheduling as siblings 31d630/3233d0/324680/32a960/330060, now at 507): frame 0x170 vs retail 0x160 (+0x10, all stack offsets +0x10: 0x68->0x78, 0x138->0x148, colours 0x15C->0x17C etc); saved-reg rotation t16 $s0 vs $s3, w $s2 vs $s4, b $s1 vs $s3 shifting every lh/lbu/sb + ld/sd base and slti/div colour; FPR rotation $f22/$f20/$f23 vs $f1/$f20/$f21 plus object materialised `addiu $s1/$s2,sp + lwc1 ($s1)` where retail folds `lwc1 offset(sp)`; colour stores retail `lbu $a2/sb` vs object `lbu $v1/sb` + extra `move $s0,$v0`; w/b dsll32/dsra32 + andi chain neutral. All logic matches: 2e48a0 u16/u8 pair, 0x7C t16, five sprite blocks (0x7D/0x229/0x2B1/0x25D/0x2B2 with 2970+6c30+2a60+6150+69f0), b<10 vs >=10 split to 26C/single+68d0 vs 26C+26D double. */
// FUN_0031CCE0 NONMATCHING
#ifdef NON_MATCHING
void func_0031cce0(u8 *arg0, s16 arg1, s64 arg2, s64 arg3) {
    u8 c15C[4];
    u8 c158[4];
    u8 c154[4];
    u8 c150[4];
    u8 c14C[4];
    u8 c148[4];
    u8 c144[4];
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
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
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    s16 w;
    s16 b;
    u8 t16;
    u8 *p;
    (void)arg0;
    w = *(s16 *)(func_002e48a0(0, arg1) + 2);
    b = *(u8 *)(func_002e48a0(0, arg1) + 4);
    sp138 = arg2;
    t16 = *(u8 *)(func_002b6150(0x7C) + 0x6E);
    func_002b2970(&sp130, *(f32 *)&sp138, *((f32 *)&sp138 + 1) - 1.0f);
    func_002b6c30(0x7D, sp130, 0x58, 125.0f);
    func_002b2970(&sp128, *(f32 *)&arg2, *((f32 *)&arg2 + 1) - 1.0f);
    func_002b2970(&sp120, *(f32 *)&arg3, *((f32 *)&arg3 + 1) - 1.0f);
    func_002b69f0(0x7D, *(FclVec2 *)&sp128, *(FclVec2 *)&sp120, 0, 0xA, 0);
    f20 = *((f32 *)&sp138 + 1) - 2.0f;
    f23 = 36.0f + *(f32 *)&sp138;
    func_002b2970(&sp118, f23, f20);
    func_002b6c30(0x229, sp118, 0x58, 126.0f);
    func_002b2a60(c15C, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x229);
    p[0x85] = c15C[0];
    p[0x86] = c15C[1];
    p[0x87] = c15C[2];
    p[0x88] = c15C[3];
    p = func_002b6150(0x229);
    *(u8 *)(p + 0x6E) = t16;
    f24 = *((f32 *)&arg3 + 1) - 2.0f;
    func_002b2970(&sp110, f23, f20);
    func_002b2970(&sp108, 36.0f + *(f32 *)&arg3, f24);
    func_002b69f0(0x229, *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 0xA, 0);
    f23 = 94.0f + *(f32 *)&sp138;
    func_002b2970(&sp100, f23, f20);
    func_002b6c30(0x2B1, sp100, 0x58, 126.0f);
    func_002b2a60(c158, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x2B1);
    p[0x85] = c158[0];
    p[0x86] = c158[1];
    p[0x87] = c158[2];
    p[0x88] = c158[3];
    p = func_002b6150(0x2B1);
    *(u8 *)(p + 0x6E) = t16;
    func_002b2970(&spF8, f23, f20);
    func_002b2970(&spF0, 94.0f + *(f32 *)&arg3, f24);
    func_002b69f0(0x2B1, *(FclVec2 *)&spF8, *(FclVec2 *)&spF0, 0, 0xA, 0);
    f23 = 1.0f + *((f32 *)&sp138 + 1);
    f20 = 43.0f + *(f32 *)&sp138;
    func_002b2970(&spE8, f20, f23);
    func_002b6c30(0x25D, spE8, 0x59, 46.0f);
    *(s16 *)(func_002b6150(0x25D) + 4) = (s16)((s16)(func_00109280(w & 0xFFFF) & 0xFF) + 0x1B);
    func_002b2a60(c154, 0x2D, 0x2D, 0x2D, 0xFF);
    p = func_002b6150(0x25D);
    p[0x85] = c154[0];
    p[0x86] = c154[1];
    p[0x87] = c154[2];
    p[0x88] = c154[3];
    p = func_002b6150(0x25D);
    *(u8 *)(p + 0x6E) = t16;
    func_002b2970(&spE0, f20, f23);
    func_002b2970(&spD8, 43.0f + *(f32 *)&arg3, 1.0f + *((f32 *)&arg3 + 1));
    func_002b69f0(0x25D, *(FclVec2 *)&spE0, *(FclVec2 *)&spD8, 0, 0xA, 0);
    f22 = 6.0f + *((f32 *)&sp138 + 1);
    func_002b2970(&spD0, (f32)0x117 + *(f32 *)&sp138, f22);
    func_002b6c30(0x2B2, spD0, 0x56, 189.0f);
    func_002b2a60(c150, 0xCC, 0xFF, 0x33, 0xFF);
    p = func_002b6150(0x2B2);
    p[0x85] = c150[0];
    p[0x86] = c150[1];
    p[0x87] = c150[2];
    p[0x88] = c150[3];
    p = func_002b6150(0x2B2);
    *(u8 *)(p + 0x6E) = t16;
    f21 = 6.0f + *((f32 *)&arg3 + 1);
    func_002b2970(&spC8, (f32)0x115 + *(f32 *)&sp138, f22);
    func_002b2970(&spC0, (f32)0x115 + *(f32 *)&arg3, f21);
    func_002b69f0(0x2B2, *(FclVec2 *)&spC8, *(FclVec2 *)&spC0, 0, 0xA, 0);
    if (b >= 0xA) {
        f20 = 6.0f + *((f32 *)&sp138 + 1);
        f21 = 320.0f + *(f32 *)&sp138;
        func_002b2970(&spB8, f21, f20);
        func_002b6c30(0x26C, spB8, 0x59, 46.0f);
        *(s16 *)(func_002b6150(0x26C) + 4) = (s16)(b % 10 + 0x46);
        func_002b2a60(c14C, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x26C);
        p[0x85] = c14C[0];
        p[0x86] = c14C[1];
        p[0x87] = c14C[2];
        p[0x88] = c14C[3];
        f22 = 6.0f + *((f32 *)&arg3 + 1);
        func_002b2970(&spB0, f21, f20);
        func_002b2970(&spA8, 320.0f + *(f32 *)&arg3, f22);
        func_002b69f0(0x26C, *(FclVec2 *)&spB0, *(FclVec2 *)&spA8, 0, 0xA, 0);
        f21 = (f32)0x12D + *(f32 *)&sp138;
        func_002b2970(&spA0, f21, f20);
        func_002b6c30(0x26D, spA0, 0x59, 46.0f);
        *(s16 *)(func_002b6150(0x26D) + 4) = (s16)(b / 10 + 0x46);
        func_002b2a60(c148, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x26D);
        p[0x85] = c148[0];
        p[0x86] = c148[1];
        p[0x87] = c148[2];
        p[0x88] = c148[3];
        func_002b2970(&sp98, f21, f20);
        func_002b2970(&sp90, (f32)0x12D + *(f32 *)&arg3, f22);
        func_002b69f0(0x26D, *(FclVec2 *)&sp98, *(FclVec2 *)&sp90, 0, 0xA, 0);
        return;
    }
    f21 = *((f32 *)&sp138 + 1) + 6.0f;
    func_002b2970(&sp88, (f32)0x13D + *(f32 *)&sp138, f21);
    func_002b6c30(0x26C, sp88, 0x59, 46.0f);
    *(s16 *)(func_002b6150(0x26C) + 4) = (s16)(b % 10 + 0x46);
    func_002b2a60(c144, 0xCC, 0xFF, 0xFF, 0xFF);
    p = func_002b6150(0x26C);
    p[0x85] = c144[0];
    p[0x86] = c144[1];
    p[0x87] = c144[2];
    p[0x88] = c144[3];
    func_002b2970(&sp80, (f32)0x137 + *(f32 *)&sp138, f21);
    func_002b2970(&sp78, (f32)0x137 + *(f32 *)&arg3, f21);
    func_002b69f0(0x26C, *(FclVec2 *)&sp80, *(FclVec2 *)&sp78, 0, 0xA, 0);
    func_002b68d0(0x26D, 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031cce0);
#endif

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
/* v1 skeleton floor (0031e5b0): m2c + romwright agree on 7-arg (u8*,s64,s32 x5), six-block 46d chain (0x193 + var-id + 0x51/0x52/0x53/0x73/0x237 with 0x2B4-0x2BA/0x28A variants), arg6 4-case switch + 7750(id,idB), arg3-conditional duplicate 69f0 blocks; written in the 0031fa20 idiom (s64 sp pairs to 2970, u8[4] per-byte colour stores, *(FclVec2*)&sp to 69f0, global f32 callees, s64 (s8)arg temps, shared h5 across last two blocks). */
/* v2 (frame-first): blocks 0/1 pass live sp148 to 6c30 instead of copying to sp140/sp118 (as blocks 2+ already did) — two dead s64 (16B) leave the frame: object 0x180 -> 0x170 exact, words 1126 -> 1118, edits 1561 -> 489 (cascade misalignment resolved), count 1287 -> 1277 (-30, -2.30% PASS). Probed DIRECT beats V1 on all three numbers; installed. */
// FUN_0031E5B0 NONMATCHING
#ifdef NON_MATCHING
void func_0031e5b0(u8 *arg0, s64 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 c0[4];
    u8 c1[4];
    u8 c2[4];
    u8 c3[4];
    u8 c4[4];
    u8 c5[4];
    u8 c6[4];
    s64 spA0;
    s64 sp148;
    s64 sp140;
    s64 sp138;
    s64 sp130;
    s64 sp128;
    s64 sp120;
    s64 sp118;
    s64 sp110;
    s64 sp108;
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
    s64 spB0;
    s64 spA8;
    f32 by;
    f32 y;
    s16 id;
    s16 idB;
    s16 id2;
    s16 id3;
    s16 id4;
    s16 id5;
    s16 id6;
    s64 t3;
    s64 t4;
    s64 t5;
    s64 t6;
    u8 *h0;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    u8 *h5;
    u8 *p;
    (void)arg0;
    spA0 = arg1;
    sp148 = arg1;
    by = *((f32 *)&spA0 + 1);
    id = 0x193;
    idB = (s16)arg6;
    t3 = (s8)arg3;
    t4 = (s8)arg4;
    t5 = (s8)arg5;
    t6 = (s8)arg6;
    if (t4 == 1) {
        id = 0x2B4;
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 1.0f;
    }
    h0 = func_0046d200(func_00331560(), 0x193);
    func_002b6c30(id, sp148, 0x57, 191.0f);
    func_002b2a60(c0, 0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    p[0x85] = c0[0];
    p[0x86] = c0[1];
    p[0x87] = c0[2];
    p[0x88] = c0[3];
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&sp138, *(f32 *)&sp148, by + func_0046b2f0(h0) / 2.0f);
    func_002b2970(&sp130, *(f32 *)&sp148, by);
    func_002b69f0(id, *(FclVec2 *)&sp138, *(FclVec2 *)&sp130, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&sp128, *(f32 *)&sp148, by);
        func_002b2970(&sp120, *(f32 *)&sp148, by + func_0046b2f0(h0) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp128, *(FclVec2 *)&sp120, 0, 3, arg2);
    }
    func_0046d280(h0);
    switch ((s8)arg6) {
    case 0:
        id = 0x19A;
        idB = 0x19A;
        func_002b2970(&sp148, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970(&sp148, (f32)0x11D + *(f32 *)&spA0, by);
        }
        break;
    case 1:
        id = 0x1A0;
        idB = 0x1A0;
        func_002b2970(&sp148, 36.0f + ((f32)0x12D + *(f32 *)&spA0), by);
        if (t5 == 1) {
            func_002b2970(&sp148, 36.0f + ((f32)0x11D + *(f32 *)&spA0), by);
        }
        break;
    case 2:
        id = 0x1A4;
        idB = 0x1A4;
        func_002b2970(&sp148, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970(&sp148, (f32)0x11D + *(f32 *)&spA0, by);
        }
        break;
    case 3:
        id = 0x1A4;
        idB = 0x1A4;
        func_002b2970(&sp148, (f32)0x12D + *(f32 *)&spA0, by);
        if (t5 == 1) {
            func_002b2970(&sp148, (f32)0x11D + *(f32 *)&spA0, by);
        }
        *(f32 *)&sp148 = *(f32 *)&sp148 + 4.0f;
        break;
    }
    if (t4 == 1) {
        id = 0x2B5;
    }
    if (t5 == 1) {
        id = 0x28A;
    }
    func_002b7750(id, idB);
    h1 = func_0046d200(func_00331560(), (u32)idB);
    func_002b6c30(id, sp148, 0x57, 191.0f);
    func_002b2a60(c1, 0, 0, 0x99, 0xFF);
    p = func_002b6150(id);
    p[0x85] = c1[0];
    p[0x86] = c1[1];
    p[0x87] = c1[2];
    p[0x88] = c1[3];
    func_002b6a70(id, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&sp110, *(f32 *)&sp148, by + func_0046b2f0(h1) / 2.0f);
    func_002b2970(&sp108, *(f32 *)&sp148, by);
    func_002b69f0(id, *(FclVec2 *)&sp110, *(FclVec2 *)&sp108, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&sp100, *(f32 *)&sp148, by);
        func_002b2970(&spF8, *(f32 *)&sp148, by + func_0046b2f0(h1) / 2.0f);
        func_002b69f0(id, *(FclVec2 *)&sp100, *(FclVec2 *)&spF8, 0, 3, arg2);
    }
    func_0046d280(h1);
    id2 = 0x51;
    y = 5.0f + by;
    func_002b2970(&sp148, 29.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id2 = 0x2B6;
    }
    if (t5 == 1) {
        func_002b2970(&sp148, 13.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 3.0f;
    }
    h2 = func_0046d200(func_00331560(), 0x51);
    func_002b6c30(id2, sp148, 0x59, 176.0f);
    func_002b2a60(c2, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id2);
    p[0x85] = c2[0];
    p[0x86] = c2[1];
    p[0x87] = c2[2];
    p[0x88] = c2[3];
    func_002b6a70(id2, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id2, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spF0, *(f32 *)&sp148, y + func_0046b2f0(h2) / 2.0f);
    func_002b69f0(id2, *(FclVec2 *)&spF0, *(FclVec2 *)&sp148, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id2, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id2, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spE8, *(f32 *)&sp148, y + func_0046b2f0(h2) / 2.0f);
        func_002b69f0(id2, *(FclVec2 *)&sp148, *(FclVec2 *)&spE8, 0, 3, arg2);
    }
    func_0046d280(h2);
    id3 = 0x52;
    func_002b2970(&sp148, 151.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id3 = 0x2B7;
    }
    if (t5 == 1) {
        func_002b2970(&sp148, 135.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 3.0f;
    }
    h3 = func_0046d200(func_00331560(), 0x52);
    func_002b6c30(id3, sp148, 0x59, 176.0f);
    func_002b2a60(c3, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id3);
    p[0x85] = c3[0];
    p[0x86] = c3[1];
    p[0x87] = c3[2];
    p[0x88] = c3[3];
    func_002b6a70(id3, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id3, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spE0, *(f32 *)&sp148, y + func_0046b2f0(h3) / 2.0f);
    func_002b69f0(id3, *(FclVec2 *)&spE0, *(FclVec2 *)&sp148, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id3, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id3, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spD8, *(f32 *)&sp148, y + func_0046b2f0(h3) / 2.0f);
        func_002b69f0(id3, *(FclVec2 *)&sp148, *(FclVec2 *)&spD8, 0, 3, arg2);
    }
    func_0046d280(h3);
    id4 = 0x53;
    y = 6.0f + by;
    func_002b2970(&sp148, 274.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id4 = 0x2B8;
    }
    if (t5 == 1) {
        func_002b2970(&sp148, 258.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 6.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 3.0f;
    }
    h4 = func_0046d200(func_00331560(), 0x53);
    func_002b6c30(id4, sp148, 0x59, 176.0f);
    func_002b2a60(c4, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(id4);
    p[0x85] = c4[0];
    p[0x86] = c4[1];
    p[0x87] = c4[2];
    p[0x88] = c4[3];
    func_002b6a70(id4, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id4, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spD0, *(f32 *)&sp148, y + func_0046b2f0(h4) / 2.0f);
    func_002b69f0(id4, *(FclVec2 *)&spD0, *(FclVec2 *)&sp148, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id4, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id4, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spC8, *(f32 *)&sp148, y + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(id4, *(FclVec2 *)&sp148, *(FclVec2 *)&spC8, 0, 3, arg2);
    }
    func_0046d280(h4);
    id5 = 0x73;
    y = 9.0f + by;
    func_002b2970(&sp148, 100.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id5 = 0x2B9;
    }
    if (t5 == 1) {
        func_002b2970(&sp148, 84.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 3.0f;
    }
    h5 = func_0046d200(func_00331560(), 0x73);
    func_002b6c30(id5, sp148, 0x59, 175.0f);
    func_002b2a60(c5, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id5);
    p[0x85] = c5[0];
    p[0x86] = c5[1];
    p[0x87] = c5[2];
    p[0x88] = c5[3];
    func_002b6a70(id5, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id5, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spC0, *(f32 *)&sp148, y + func_0046b2f0(h5) / 2.0f);
    func_002b69f0(id5, *(FclVec2 *)&spC0, *(FclVec2 *)&sp148, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id5, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id5, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spB8, *(f32 *)&sp148, y + func_0046b2f0(h5) / 2.0f);
        func_002b69f0(id5, *(FclVec2 *)&sp148, *(FclVec2 *)&spB8, 0, 3, arg2);
    }
    id6 = 0x237;
    func_002b2970(&sp148, 225.0f + *(f32 *)&spA0, y);
    if (t4 == 1) {
        id6 = 0x2BA;
    }
    if (t5 == 1) {
        func_002b2970(&sp148, 209.0f + *(f32 *)&spA0, y);
    }
    if (t6 == 3) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 4.0f;
    }
    if (t6 == 1) {
        *(f32 *)&sp148 = *(f32 *)&sp148 + 3.0f;
    }
    func_002b6c30(id6, sp148, 0x59, 175.0f);
    func_002b2a60(c6, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(id6);
    p[0x85] = c6[0];
    p[0x86] = c6[1];
    p[0x87] = c6[2];
    p[0x88] = c6[3];
    func_002b6a70(id6, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(id6, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spB0, *(f32 *)&sp148, y + func_0046b2f0(h5) / 2.0f);
    func_002b69f0(id6, *(FclVec2 *)&spB0, *(FclVec2 *)&sp148, 0, 3, arg2);
    if (t3 == 1) {
        func_002b6a70(id6, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(id6, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spA8, *(f32 *)&sp148, y + func_0046b2f0(h5) / 2.0f);
        func_002b69f0(id6, *(FclVec2 *)&sp148, *(FclVec2 *)&spA8, 0, 3, arg2);
    }
    func_0046d280(h5);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);
#endif

/* measured: nd 668 (1 attempt). Retail keeps arg1 (a packed f32 pair, low=sp58
   high=sp5C) memory-resident and hoists only the high word into $f20, reloading
   the low word from sp58 at every use; mwcc b210 caches BOTH words in saved
   float regs ($f20-$f23), shrinking the frame 0x140->0x130 and rotating every
   call's arg setup. The s64 arg2/arg3 params also make mwcc emit a dsll32/dsra32
   normalization at every 6a70/69f0 call site (retail passes the raw reg).
   Float-pair register-hoist + s64-param-normalization floor. */
/* measured 2026-09-18: reconstructed from a bare marker; banked floor 635
   reloc-masked words.  753 retail instructions against 743 object, 10 short
   at -1.33%, inside the 3% gate; 459 fnalign edits.  `opt_propagation off`
   is load bearing and scoped, as it is on the sibling func_0032e570.  The
   parameters are s64 because the caller passes packed 128-bit colour rows;
   spelling them s32 costs the whole tail. */
/* measured 2026-09-18 (float-hoist lane): probe_variants 615 differing words reloc-masked (BY: by local for sp58 high, opt_propagation off kept; BXBY 628, BX_S32 630, BX_U8 657, U8ONLY 659, V1 736, CUR 635 baseline); fnalign retail 753 vs object 749 instrs (-4, -0.53% PASS, 514 edits via --candidate by_u8.c --quiet); live measure_guarded GUARDED_SCORE func_0031fa20: 615; verify 37 MATCH/33 ASM/0 MISMATCH, lint 0. Count-first PASS (within 3%). */
/* Hoist rationale (per thread lwc1+31/mov.s-31 swap): body reloaded both sp58 halves via lwc1 where retail keeps the high half live in $f20 via mov.s and reloads only the low half; giving the high half an ordinary f32 local (by) with lifetime spanning the uses converts high reloads to moves and lets the five colour stores match retail batched lbu/sb via u8[4] per-byte copies (s32 gave lw/sw +20/+20 wall). Opclass BY_U8: lwc1 +31->+8, mov.s -31->-16, add.s +21->+12, lbu/sb -20->0, lui/mtc1 -11 kept; frame stays 0x140 with f20/f21 matching retail. Remaining walls: lui -11/mtc1 -11 (retail rematerialises 191.0f/1.0f/102.0f etc. per-use where object shares), nop +11/swc1 +3 (float-spill scheduling), same rotation+scheduling as sibling 317900 now at 789. */
/* measured 2026-09-19 (69f0-width lane): before probe_variants 615 words reloc-masked, fnalign retail 753 vs object 749 instrs (-4, -0.53% PASS, 731-776) 514 edits hole 40 lump 61 via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --candidate /tmp/before.c` without --quiet (hole retail[682:722] 40 = 0x2B0 cond 6a70/6af0/2970 plus 208.0/9.0 hoist lwc1/lui/add.s that body recomputes per-use via lwc1+add.s, lump object[662:723] 61 = per-use lwc1 $f0,0x68 + add.s $f12,$f23,$f0 for 55/208+low plus hoisted $t1 that the aligner duplicates) and `python3 tools/gate_audit.py --composition` split; after 619 words (+4), retail 753 vs object 749 (-4 PASS) 393 edits hole 3 lump 3 via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --candidate /tmp/after_u16.c --quiet` and without --quiet (max pure 3 = mov.s/lwc1 scheduling) plus live `python3 tools/measure_guarded.py src/Event/Fcl/y_fclCombineDraw.c func_0031fa20 --save-candidate /tmp/after_u16.c` GUARDED_SCORE 619; `python3 tools/verify.py src/Event/Fcl/y_fclCombineDraw.c` 37 MATCH/33 ASM/0 MISMATCH, `python3 tools/decomp_lint.py src/Event/Fcl/y_fclCombineDraw.c` 0 errors. Cheap causes in order: t17 s64->s8/s16/s32 neutral (514/40/61 kept), block order correct (27C/289/72/2AF/2B0 matches retail jal immediates, 40!=61 not moved code), no inlined call (92 jals both sides, 2a60/6150 separate), struct u8[4] already correct (s32 fails compile, lw/sw wall); fix is extern-width s64->u16 for 69f0 last (wider than retail 16-bit per 7ab): `andi $t1,$s0,0xffff` hoisted before a0 vs `move $t1,$s0` before jal, collapses 40/61->3/3 and 514->393 at same count. */
// FUN_0031FA20 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0031fa20(u8 *arg0, s64 arg1, s64 arg2, s64 arg3) {
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
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    s64 t17;
    f32 by;
    u8 *h1;
    u8 *h2;
    u8 *h3;
    u8 *h4;
    extern void func_002b6c30(s64, s64, s32, f32);
    extern void func_002b69f0(s64, f2, f2, u32, u32, u16);
    extern void func_002b6a70(s64, u8, u8, s32, s32, s64);
    extern void func_002b6af0(s64, u32, u32, s64, f32, f32, f32, f32);
    extern u8 *func_002b6150(s64);
    u8 *p;
    (void)arg0;
    sp58 = arg1;
    by = *((f32 *)&sp58 + 1);
    h1 = func_0046d200(func_00331560(), 0x193);
    func_002b2970(&sp120, *(f32 *)&sp58, by);
    func_002b6c30(0x27C, sp120, 0x57, 191.0f);
    func_002b2a60(c13C, 0, 0, 0x99, 0xFF);
    p = func_002b6150(0x27C);
    p[0x85] = c13C[0];
    p[0x86] = c13C[1];
    p[0x87] = c13C[2];
    p[0x88] = c13C[3];
    func_002b6a70(0x27C, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x27C, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&sp118, *(f32 *)&sp58, by + func_0046b2f0(h1) / 2.0f);
    func_002b2970(&sp110, *(f32 *)&sp58, by);
    func_002b69f0(0x27C, *(FclVec2 *)&sp118, *(FclVec2 *)&sp110, 0, 3, arg2);
    t17 = (s8)arg3;
    if (t17 == 1) {
        func_002b6a70(0x27C, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x27C, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&sp108, *(f32 *)&sp58, by);
        func_002b2970(&sp100, *(f32 *)&sp58, by + func_0046b2f0(h1) / 2.0f);
        func_002b69f0(0x27C, *(FclVec2 *)&sp108, *(FclVec2 *)&sp100, 0, 3, arg2);
    }
    func_0046d280(h1);
    h2 = func_0046d200(func_00331560(), 0x19B);
    func_002b2970(&spF8, (f32)0x11D + *(f32 *)&sp58, by);
    func_002b6c30(0x289, spF8, 0x57, 191.0f);
    func_002b2a60(c138, 0, 0, 0x99, 0xFF);
    p = func_002b6150(0x289);
    p[0x85] = c138[0];
    p[0x86] = c138[1];
    p[0x87] = c138[2];
    p[0x88] = c138[3];
    func_002b6a70(0x289, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x289, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spF0, (f32)0x11D + *(f32 *)&sp58, by + func_0046b2f0(h2) / 2.0f);
    func_002b2970(&spE8, (f32)0x11D + *(f32 *)&sp58, by);
    func_002b69f0(0x289, *(FclVec2 *)&spF0, *(FclVec2 *)&spE8, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x289, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x289, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spE0, (f32)0x11D + *(f32 *)&sp58, by);
        func_002b2970(&spD8, (f32)0x11D + *(f32 *)&sp58, by + func_0046b2f0(h2) / 2.0f);
        func_002b69f0(0x289, *(FclVec2 *)&spE0, *(FclVec2 *)&spD8, 0, 3, arg2);
    }
    func_0046d280(h2);
    h3 = func_0046d200(func_00331560(), 0x72);
    func_002b2970(&spD0, 102.0f + *(f32 *)&sp58, 4.0f + by);
    func_002b6c30(0x72, spD0, 0x59, 177.0f);
    func_002b2a60(c134, 0x33, 0xCD, 0xFF, 0xFF);
    p = func_002b6150(0x72);
    p[0x85] = c134[0];
    p[0x86] = c134[1];
    p[0x87] = c134[2];
    p[0x88] = c134[3];
    func_002b6a70(0x72, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x72, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spC8, 102.0f + *(f32 *)&sp58, 4.0f + by + func_0046b2f0(h3) / 2.0f);
    func_002b2970(&spC0, 102.0f + *(f32 *)&sp58, 4.0f + by);
    func_002b69f0(0x72, *(FclVec2 *)&spC8, *(FclVec2 *)&spC0, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x72, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x72, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&spB8, 102.0f + *(f32 *)&sp58, 4.0f + by);
        func_002b2970(&spB0, 102.0f + *(f32 *)&sp58, 4.0f + by + func_0046b2f0(h3) / 2.0f);
        func_002b69f0(0x72, *(FclVec2 *)&spB8, *(FclVec2 *)&spB0, 0, 3, arg2);
    }
    func_0046d280(h3);
    h4 = func_0046d200(func_00331560(), 0x73);
    func_002b2970(&spA8, 55.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b6c30(0x2AF, spA8, 0x59, 175.0f);
    func_002b2a60(c130, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0x2AF);
    p[0x85] = c130[0];
    p[0x86] = c130[1];
    p[0x87] = c130[2];
    p[0x88] = c130[3];
    func_002b6a70(0x2AF, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2AF, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&spA0, 55.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
    func_002b2970(&sp98, 55.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b69f0(0x2AF, *(FclVec2 *)&spA0, *(FclVec2 *)&sp98, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x2AF, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x2AF, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&sp90, 55.0f + *(f32 *)&sp58, 9.0f + by);
        func_002b2970(&sp88, 55.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(0x2AF, *(FclVec2 *)&sp90, *(FclVec2 *)&sp88, 0, 3, arg2);
    }
    func_002b2970(&sp80, 208.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b6c30(0x2B0, sp80, 0x59, 175.0f);
    func_002b2a60(c12C, 0x49, 0x72, 0xFF, 0xFF);
    p = func_002b6150(0x2B0);
    p[0x85] = c12C[0];
    p[0x86] = c12C[1];
    p[0x87] = c12C[2];
    p[0x88] = c12C[3];
    func_002b6a70(0x2B0, 0, 0xFF, 0, 0, arg2);
    func_002b6af0(0x2B0, 0, 3, arg2, 1.0f, 1.0f, iGpffff8504, 1.0f);
    func_002b2970(&sp78, 208.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
    func_002b2970(&sp70, 208.0f + *(f32 *)&sp58, 9.0f + by);
    func_002b69f0(0x2B0, *(FclVec2 *)&sp78, *(FclVec2 *)&sp70, 0, 3, arg2);
    if (t17 == 1) {
        func_002b6a70(0x2B0, 0xFF, 0, 0, 0, ((s16)arg2 + 3));
        func_002b6af0(0x2B0, 0, 3, arg2, 1.0f, 1.0f, 1.0f, iGpffff8504);
        func_002b2970(&sp68, 208.0f + *(f32 *)&sp58, 9.0f + by);
        func_002b2970(&sp60, 208.0f + *(f32 *)&sp58, 9.0f + by + func_0046b2f0(h4) / 2.0f);
        func_002b69f0(0x2B0, *(FclVec2 *)&sp68, *(FclVec2 *)&sp60, 0, 3, arg2);
    }
    func_0046d280(h4);
}

#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);
#endif

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
/* measured: probe_variants 366 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 --candidate V9=/var/tmp/cold3233d0/v9.c`; fnalign retail 587 vs object 586 instrs (1 short, 0.17% within 3% rule, 53 edits +3 reloc-only) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 --candidate /var/tmp/cold3233d0/v9.c --quiet`; live measure_guarded GUARDED_SCORE func_003233d0: 366. Prior file note nd N/A was bare INCLUDE_ASM with no banked body (no archive); this is the first banked floor since bare. */
/* Walls (same rotation+scheduling as siblings 31d630/324680/32a960/23d00, now at 366): t in $s? vs retail $s1, i raw/norm rotation shifting every lb/lh base and loop slt; 0x6E stores retail sb $s4 + andi $s4 vs object addiu $v1,-1/-52 + sb (s8 -1/-52/0 wins over u8 0xFF/0xCC by 41, v2 458 vs v1 499); FP saved-reg $f20 vs $f14 + mov.s wall and conversion result $v1 vs $v0 + andi chain (explicit normal-first 2.1474836e9f > f + per-arm andi beats plain (u8)f 461 vs 458); lw scheduling + branch offsets. All logic matches: outer 10b5b0 loop with 31d630 call, three colour branches with FclByte4 chains, tail 2aa0 guarded + 275820 text call. */
/* Repro: `python3 -E -s tools/m2c_decompile.py src/Event/Fcl/y_fclCombineDraw.c func_003233d0 -o /var/tmp/cold3233d0/m2c.c` (193 lines, (void*) + s8/s16 residues de-noised to (u8*) + (s8)/(s16) casts, FclByte4 groups per 31d630 lever, s16 i with (s16)i<(u16)10b5b0 loop, heap-to-heap FclByte4 chains per retail lw/sw, 2aa0 + guarded (u8)(s32)f normal-first idiom per y_CmbCardEff 00348330, 275820 text tail); `python3 -E -s tools/romwright_decompile.py func_003233d0 -o /var/tmp/cold3233d0/rom.c` (241 lines, (ulonglong) residues, same chains confirmed); probe V9 366 driven by fnalign edit script (count first: 586/587 exact, then shapes). */
/* Rounds: v1 499 (u8 0x6E + a/b hoist + explicit guard, heap-to-heap u8 chains); v2 458 (-41 via s8 -1/-52/0 stores); v3 498 tie (inline a/b on u8 base, neutral); v4 430 (-28 via inline a/b on s8 base); v5 461 worse (plain (u8)f guard) + v6 506 worse (s32 i) batch; v7 430 tie (decl-order neutral) + v8 401 (-29 via tail id inline) batch; v9 366 (-35 via FclByte4 struct-assign for all heap colours, lw/sw) + v10 401 tie (s32 ba970 neutral) batch; v11/v12 366 tie (s32 ba970 + decl-order neutral) batch; v13 491 worse (u8 revert) + v14 407 worse (tail hoist revert) batch. Stopped after two consecutive non-lowering rounds (v11/v12 tie + v13/v14 worse). Banked v9 as guarded floor (exact count, compiles clean under -DNON_MATCHING). */
// FUN_003233D0 NONMATCHING
#ifdef NON_MATCHING
void func_003233d0(u8 *arg0) {
    extern void func_0031d630(u8 *, s64, s64, s64, s64);
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
    s16 i;
    u8 *t;
    u8 *p;
    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; (s16)i < (u16)func_0010b5b0(); i = (s16)(i + 1)) {
        func_0031d630(arg0, (s8)i, *(s8 *)(t + 0x128), *(s8 *)(t + 0x129), 0);
        if ((s16)i < *(s32 *)(func_002e4870(0) + 8)) {
            if ((s16)i == *(s16 *)(t + 0x11E)) {
                u8 *p297;
                u8 *p28B;
                u8 *p27D;
                p = func_002b6150((s16)((s16)i + 0x27D));
                *(s8 *)(p + 0x6E) = -1;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(s8 *)(p + 0x6E) = -1;
                func_002b2a60(&cDC, 0xCC, 0xFF, 0x33, 0xFF);
                p297 = func_002b6150((s16)((s16)i + 0x297));
                *(FclByte4 *)(p297 + 0x85) = cDC;
                p28B = func_002b6150((s16)((s16)i + 0x28B));
                *(FclByte4 *)(p28B + 0x85) = *(FclByte4 *)(p297 + 0x85);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = *(FclByte4 *)(p28B + 0x85);
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                func_002b2a60(&cD8, 0x2D, 0x2D, 0x2D, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cD8;
                func_002b2a60(&cD4, 0x2D, 0x2D, 0x2D, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), *(s32 *)&cD4);
                func_002b2a30(0x2D, 0x2D, 0x2D, 0xFF);
                if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                    func_002b68d0(0xCF, 0, 1);
                    func_002b68d0(0xD2, 0, 1);
                    func_002b68d0((s16)((s16)i + 0x270), 0, 0);
                    func_002b68d0((s16)((s16)i + 0x27D), 0, 0);
                }
            } else if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                u8 *p27D;
                p = func_002b6150((s16)((s16)i + 0x27D));
                *(s8 *)(p + 0x6E) = 0;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(s8 *)(p + 0x6E) = 0;
                func_002b2a60(&cD0, 0xFF, 0xFF, 0xFF, 0xFF);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = cD0;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                func_002b2a60(&cCC, 0xFF, 0xCC, 0xFA, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cCC;
                func_002b2a60(&cC8, 0xFF, 0xCC, 0xFA, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), *(s32 *)&cC8);
                func_002b2a30(0xFF, 0xCC, 0xFA, 0xFF);
                func_002b68d0(0xCF, 0, 0);
                func_002b68d0(0xD2, 0, 0);
            } else {
                u8 *p27D;
                u8 *p297;
                p = func_002b6150((s16)((s16)i + 0x27D));
                *(s8 *)(p + 0x6E) = -52;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(s8 *)(p + 0x6E) = -52;
                func_002b2a60(&cC4, 0x49, 0x72, 0xFF, 0xFF);
                p27D = func_002b6150((s16)((s16)i + 0x27D));
                *(FclByte4 *)(p27D + 0x85) = cC4;
                p = func_002b6150((s16)((s16)i + 0x270));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p27D + 0x85);
                func_002b2a60(&cC0, 0x49, 0x72, 0xFF, 0xFF);
                p297 = func_002b6150((s16)((s16)i + 0x297));
                *(FclByte4 *)(p297 + 0x85) = cC0;
                p = func_002b6150((s16)((s16)i + 0x28B));
                *(FclByte4 *)(p + 0x85) = *(FclByte4 *)(p297 + 0x85);
                func_002b2a60(&cBC, 0, 0, 0x66, 0xFF);
                p = func_002b6150((s16)((s16)i + 0x2A3));
                *(FclByte4 *)(p + 0x85) = cBC;
                func_002b2a60(&cB8, 0xCC, 0xFF, 0xFF, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), (s16)((s16)i + 0xC), *(s32 *)&cB8);
                func_002b2a30(0xCC, 0xFF, 0xFF, 0xFF);
            }
            if (*(s8 *)(t + 0x128) != (s16)i && *(s8 *)(t + 0x129) != (s16)i) {
                if (*(s8 *)(func_002e4870((s8)(*(s8 *)(t + 0x129) + 1)) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) > 0) {
                    s16 v42 = *(s16 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x42);
                    s16 v40 = *(s16 *)(func_002b6150((s16)((s16)i + 0x270)) + 0x40);
                    f32 f = func_002b2aa0(0, 0.0f, 255.0f, (f32)v42, (f32)v40);
                    s32 v;
                    u8 alpha;
                    s32 ret;
                    if (2.1474836e9f > f) {
                        v = (s32)f;
                        v &= 0xFF;
                    } else {
                        v = (s32)(f - 2.1474836e9f) | 0x80000000;
                        v &= 0xFF;
                    }
                    alpha = v & 0xFF;
                    if (*(s16 *)(t + 0x11E) == (s16)i) {
                        ret = func_002b2a30(0x2D, 0x2D, 0x2D, alpha);
                    } else {
                        ret = func_002b2a30(0xCC, 0xFF, 0xFF, alpha);
                        if (*(s8 *)(func_002e4870(0) + *(s8 *)(t + 0x129) * 0xC + (s16)i + 0x14) == 2) {
                            ret = func_002b2a30(0xFF, 0xCC, 0xFA, alpha);
                        }
                    }
                    func_00275820(405.0f, (f32)((s16)i * 0x17 + 0x80), 43.0f, ret, 0, 2, (const char *)((u8 *)iGpffffb440 + (u16)(*(u16 *)(func_002e48a0((s8)(*(s8 *)(t + 0x129) + 1), (s16)i) + 2)) * 0x11), 0, 0, D_00795E60, 0x15);
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003233d0);
#endif

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
/* measured 2026-09-19 (hole-close lane): probe_variants 363 differing words reloc-masked (S16+LOOPINV: s16 loop counters for all three k loops + opt_loop_invariants on; S16 bare 407, CUR 398); fnalign retail 452 vs object 456 instrs (+4, +0.9% PASS, 199 edits via --candidate s16_loopinv.c --quiet); gate_audit --composition hole 3 lump 12 PASS (was hole 207 lump 104 FAIL on CUR 446/449). Rounds: S16 407 closes composition (hole 207->2, lump 104->12, edits 556->229); LOOPINV 363 (-44, count 462->456) real per 7u (count -1.3% steady); pairs LOOP+DEAD 367/LOOP+PROP 403/LOOP+SCHED 394/LOOP+COMMON 413 worse; SCHED alone 397 but 405/449 short FAIL gate + hole 90; COMMON 412/STRENGTH tie/UNROLL tie/PEEP 430/O1 412/O3 394 worse; decl p/t + subscript + colour-reverse ties at 363. Banked S16+LOOPINV as guarded floor (within 3%, composition PASS). */
// FUN_00323D00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
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
        s16 k = 0;
        while (k < *(s32 *)(func_002e4870(1) + 8)) {
            u16 w = *(u16 *)(func_002e48a0(1, (s16)k) + 2);
            u8 b = *(u8 *)(func_002e48a0(1, (s16)k) + 4);
            func_002b2970(&spD0, 313.0f, 128.0f);
            func_003191c0(arg0, spD0, (s8)k, w, b, (s16)(k * arg1), arg2, *(s8 *)(func_002e4870(1) + 8));
            k++;
        }
    }
    {
        s16 k = 0;
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
            s16 k = 0;
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
#pragma opt_loop_invariants off
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
/* measured: probe_variants 481 differing words reloc-masked via `python3 tools/probe_variants.py src/Event/Fcl/y_fclCombineDraw.c func_00329e40 --candidate S32=/var/tmp/cold329e40/v_s32_common.c` (V1 609 u8+s64+local-s64-10th 713/712 +1 465 edits, V2 609 tie via (f32)0x1DF, GLOBAL 612 worse, S64COPY 584 worse, S32 bare 617 worse; S32+common-off 481 best); fnalign retail 710 vs object 710 instrs exact (0 short, 0% within 3% rule, 99 edits) via `python3 tools/fnalign.py src/Event/Fcl/y_fclCombineDraw.c func_00329e40 --candidate /var/tmp/cold329e40/v_s32_common.c --quiet`; count first PASS. Shapes: s64 2970 homes, s32 colours with lw for 77d0 4th arg (u8[4] per-byte 556 worse), f32 base copies via *(f32 *)&sp (s64 copy 584 worse), local extern for 77d0 (s64 10th, no shared-top edit; global s16 10th 612 worse), (f32)0x1DF integer conversion, s8 load for 0x123*0x101. */
/* Rounds in batch order (count first): v1 609 (u8 colours, s64 temps, f32 copies, local s64 10th); v2 609 tie (0x1DF); s32 bare 617 worse + s32+common-off 481 (-136, 710/710 exact). Step2 pragmas on s32: opt_common_subs off 481 <-- better (vs 617 bare), opt_propagation off 481 tie, opt_loop_invariants on 481 tie, opt_unroll_loops off 481 tie, peephole off 481 tie, schedule on 597 worse, O1 481 tie, O0 750 worse. Step3 subscript tie: ((f32 *)&sp)[0]/[1] 481 tie. Step4 decl-order tie: t-first 481 tie, colours reverse 489 worse. Stopped after two consecutive non-improving rounds above 60 (subscript+decl). Banked s32+common-off as guarded floor (exact count, compiles clean under -DNON_MATCHING). */
/* Walls (same rotation+scheduling as siblings 31cce0/3233d0/324680, now at 481): saved-reg rotation shifting every ld/lw base and loop; colour stores retail batched lbu x4 then sb x4 vs object lw/sw word (s32) or interleaved per-byte (u8); base copy retail load-load-store-store lwc1 batch vs object interleaved load-store-load-store; float scheduling retail mtc1-offset + lwc1-base vs object lwc1-base + mtc1-offset plus extra lwc1; move-reuse vs addiu rematerialisation for 2a60/77d0 immediates. All logic matches: 23x 2970 + 13x 2a60 + 18x 77d0 + 12x 7750 + 2x 68d0 straight-line fusion UI draw with 0x123*0x101 offsets and 31560 tail. */
// FUN_00329E40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_00329e40(u8 *arg0, s64 arg1, s64 arg2) {
    extern void func_002b77d0(s64, s64, s64, s32, s64, s64, s64, s64, f32, s64, s32);
    s32 c11C;
    s32 c118;
    s32 c114;
    s32 c110;
    s32 c10C;
    s32 c108;
    s32 c104;
    s32 c100;
    s32 cFC;
    s32 cF8;
    s32 cF4;
    s32 cF0;
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
    s64 sp98;
    s64 sp90;
    s64 sp88;
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;
    s64 sp60;
    s64 sp58;
    u8 *t;
    t = *(u8 **)(arg0 + 0x38);
    func_002b2970(&spE0, 79.0f, 97.0f);
    *(f32 *)&spE8 = *(f32 *)&spE0;
    *((f32 *)&spE8 + 1) = *((f32 *)&spE0 + 1);
    func_002b2a60(&c114, 0, 0, 0x99, 0xFF);
    c11C = c114;
    func_002b2a60(&c110, 0xFF, 0xFF, 0xFF, 0xFF);
    c118 = c110;
    func_002b2a60(&c118, 0x2D, 0x2D, 0x2D, 0xFF);
    func_002b77d0(0x21C, spE8, 0x193, c11C, 0x41, arg2, 6, 3, 191.0f, arg1, func_00331560());
    func_002b2970(&spD8, (f32)0x1DF + *(f32 *)&spE8, *((f32 *)&spE8 + 1));
    func_002b77d0(0x1A3, spD8, 0x1A3, c11C, 0x41, arg2, 6, 3, 191.0f, arg1, func_00331560());
    func_002b2970(&spD0, 20.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x120, spD0, 0x120, c118, 0x56, arg2, 6, 3, 184.0f, arg1, func_00331560());
    func_002b7750(0x2E8, 0x120);
    func_002b2970(&spC8, 30.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x2E8, spC8, 0x120, c118, 0x56, arg2, 6, 3, 184.0f, arg1, func_00331560());
    func_002b2970(&spC0, 47.0f + *(f32 *)&spE8, 2.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x11F, spC0, 0x11F, c118, 0x56, arg2, 6, 3, 183.0f, arg1, func_00331560());
    func_002b2970(&spE8, 314.0f, 97.0f);
    func_002b2970(&spB8, 214.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x121, spB8, 0x121, c118, 0x56, arg2, 6, 3, 185.0f, arg1, func_00331560());
    func_002b7750(0x2E9, 0x121);
    func_002b2970(&spB0, 224.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x2E9, spB0, 0x121, c118, 0x56, arg2, 6, 3, 185.0f, arg1, func_00331560());
    func_002b2970(&spA8, 97.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b77d0(0x11E, spA8, 0x11E, c118, 0x56, arg2, 6, 3, 182.0f, arg1, func_00331560());
    func_002b2a60(&c11C, 0xCC, 0xFF, 0x33, 0xFF);
    func_002b2970(&spE8, 79.0f, 97.0f);
    func_002b7750(0x2EA, 0x193);
    func_002b2970(&spA0, *(f32 *)&spE8 + (f32)(*(s8 *)(t + 0x123) * 0x101), *((f32 *)&spE8 + 1));
    func_002b77d0(0x2EA, spA0, 0x193, c11C, 0x41, arg2, 6, 3, 187.0f, arg1, func_00331560());
    func_002b7750(0x2EB, 0x19C);
    func_002b2970(&sp98, 220.0f + *(f32 *)&spE8 + (f32)(*(s8 *)(t + 0x123) * 0x101), *((f32 *)&spE8 + 1));
    func_002b77d0(0x2EB, sp98, 0x19C, c11C, 0x41, arg2, 6, 3, 187.0f, arg1, func_00331560());
    func_002b2970(&spE8, 79.0f, 97.0f);
    func_002b7750(0x2EC, 0x11F);
    func_002b2970(&sp90, 47.0f + *(f32 *)&spE8, 2.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&c10C, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2EC, sp90, 0x11F, c10C, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b7750(0x2E4, 0x120);
    func_002b2970(&sp88, 20.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&c108, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2E4, sp88, 0x120, c108, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b7750(0x2E5, 0x120);
    func_002b2970(&sp80, 30.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&c104, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2E5, sp80, 0x120, c104, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b2970(&spE8, 314.0f, 97.0f);
    func_002b7750(0x2E1, 0x11E);
    func_002b2970(&sp78, 97.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&c100, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2E1, sp78, 0x11E, c100, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b7750(0x2E6, 0x121);
    func_002b2970(&sp70, 214.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&cFC, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2E6, sp70, 0x121, cFC, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b7750(0x2E7, 0x121);
    func_002b2970(&sp68, 224.0f + *(f32 *)&spE8, 3.0f + *((f32 *)&spE8 + 1));
    func_002b2a60(&cF8, 0xFF, 0xFF, 0xFF, 0xFF);
    func_002b77d0(0x2E7, sp68, 0x121, cF8, 0x5A, arg2, 6, 3, 181.0f, arg1, func_00331560());
    func_002b2a60(&c11C, 0xCC, 0xFF, 0x33, 0xFF);
    func_002b2970(&spE8, 79.0f, 97.0f);
    func_002b7750(0x2E2, 0x193);
    func_002b2970(&sp60, *(f32 *)&spE8 + (f32)(*(s8 *)(t + 0x123) * 0x101), *((f32 *)&spE8 + 1));
    func_002b2a60(&cF4, 0xCC, 0xFF, 0x33, 0);
    func_002b77d0(0x2E2, sp60, 0x193, cF4, 0x59, arg2, 6, 3, 180.0f, arg1, func_00331560());
    func_002b68d0(0x2E2, 0xD, 0);
    func_002b7750(0x2E3, 0x19C);
    func_002b2970(&sp58, 220.0f + *(f32 *)&spE8 + (f32)(*(s8 *)(t + 0x123) * 0x101), *((f32 *)&spE8 + 1));
    func_002b2a60(&cF0, 0xCC, 0xFF, 0x33, 0);
    func_002b77d0(0x2E3, sp58, 0x19C, cF0, 0x59, arg2, 6, 3, 180.0f, arg1, func_00331560());
    func_002b68d0(0x2E3, 0xD, 0);
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);
#endif

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

/* measured: probe_variants 623 differing words reloc-masked (V3 with opt_propagation off); fnalign retail 697 vs object 694 instrs (-3, -0.43% PASS, 824 edits +8 reloc-only); count first PASS (V1 633/647 short, V2 630/697 exact). Shapes: s64 2970 homes, char buffers sp130[64]/spF0[64]/spB0[128], f21=153.0f saved for else 5-loop, plain (u8)f alpha, D_ pointer arrays, local externs for new helpers (no shared-top edit). */
/* Rounds in batch order (count first): v1 633 (m2c+romwright de-noise, 647/697 short); v2 630 (-3 via full 3-loop with 442830+2b32d0+275520, 697/697 exact). Step2 pragmas: opt_propagation off 623 <-- better, opt_dead_assignments off 630 tie, opt_strength_reduction off 630 tie, opt_unroll_loops off 630 tie, schedule on 631, opt_loop_invariants on 632, O3/O4 632, common_subs off 648 worse, peephole off 671 worse, O1 673 worse, O0 812 worse (pragma_sweep). Step3 subscript tie: addOff-v 623 tie, D_006430B0 offset 623 tie, D_00643220 P[i] 625 worse. Step4 decl-order tie: t/base swap 623, j/n swap 623, f21/t swap 623. Stopped after two consecutive non-improving rounds above 60 (subscript+decl). Banked v3 as guarded floor (within 3%, compiles clean under -DNON_MATCHING via probe, verify 37 MATCH/33 ASM, lint 0). */
/* 2026-09-18 opcode census: 623 -> 621.  The census showed `mov.s +33`
   against `lui -26, mtc1 -20` - this body copies float values between
   registers where retail rematerialises the constant at each use.  Spelling
   `153.0f` at its three call sites instead of holding it in `f21` is worth
   two words and removes the local entirely.  The remaining `mov.s` surplus
   is elsewhere in the body.  Re-censusing after the change confirms the
   mechanism and its size: `mov.s` 33 -> 28, `lui` -26 -> -23, `mtc1`
   -20 -> -17, all three moving together by the same three.  So the
   remaining 28 are twenty-eight more float values this body holds in a
   register and copies where retail re-materialises them.
   The obvious lever does not work: `opt_common_subs off`, which should stop
   the compiler pooling repeated float constants, costs 621 -> 642.
   `peephole off` costs 693; `opt_propagation off` and
   `opt_dead_assignments off` both tie at 621.  So the copies are not a CSE
   of the literals - look for float locals whose live range spans several
   calls and try spelling their value at each use instead. */
// FUN_0032E570 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_0032e570(u8 *arg0) {
    extern u8 func_002e78a0(void);
    extern u8 func_002e78e0(void);
    extern s64 func_00110a60(s32 arg0, s32 arg1);
    extern u8 D_00643D00[];
    extern u8 D_006432B0[];
    extern char *D_006430B0[];
    extern u8 D_00643220[];
    extern char *D_00644D18;
    extern char *D_00644D1C;
    extern char *D_00644D20;
    extern s32 iGpffffb44c;
    extern int func_00275520(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int unused, void *param);
    extern void func_00442830(char *dst, const char *src);
    extern void func_00442428(char *dst, char *src);
    extern void func_00275980(char *src, char *dst, s32 maxlen);
    extern u8 *func_002b32d0(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4);
    extern u8 *func_00243840(s32 arg0);
    s64 sp1D8;
    s64 sp1D0;
    s64 sp1C8;
    s64 sp1C0;
    s64 sp1B8;
    s64 sp1B0;
    char sp130[64];
    char spF0[64];
    char spB0[128];
    u8 *t;
    u8 *base;
    u8 alpha;
    s8 v;
    s16 j;
    s16 n;
    s16 k;
    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0x2D6) = *(s8 *)(t + 0x122) ^ 1;
    {
        f32 fx = (f32)*(s16 *)(func_002b6150(0x2E4) + 0x42);
        f32 fy = (f32)*(s16 *)(func_002b6150(0x2E4) + 0x40);
        f32 f = func_002b2aa0(2, 0.0f, 255.0f, fx, fy);
        alpha = (u8)f;
    }
    v = *(s8 *)(t + *(s8 *)(t + 0x2D6) + 0x2D4);
    if (v == -1) {
        if (*(s8 *)(t + 0x122) == 1) {
            u8 m1 = func_002e78a0();
            u8 d1 = func_002e78e0();
            base = D_00643D00 + (s8)func_00110a60(m1 & 0xFF, d1 & 0xFF) * 0x14;
        } else if (*(s8 *)(t + 0x122) == 0) {
            base = D_00643D00 + (s8)func_00110a60(*(s8 *)(t + 0x2D2), *(s8 *)(t + 0x2D3)) * 0x14;
        }
        func_002b2970(&sp1D8, 135.0f, 96.0f);
        func_00330e50(0x1D2, sp1D8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        func_00275520(153.0f, 86.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18, 0, 0, D_00795E60);
        n = 0;
        for (j = 0; (s16)j < 5; j = (s16)(j + 1)) {
            if (*(s8 *)(t + *(s8 *)(t + 0x2D6) * 5 + (s16)j + 0x2C4) == 1) {
                s32 off = (s16)n * 0x22;
                u8 *e;
                s8 id;
                func_002b2970(&sp1D0, 135.0f, (f32)(off + 0xC3));
                func_00330e50(0x1D2, sp1D0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                e = base + (s16)j * 4;
                id = *(s8 *)e;
                if (id == 0xA) {
                    u16 w = *(u16 *)(e + 2);
                    u8 *s = func_00243840(w);
                    func_00442830(sp130, (const char *)s);
                    func_00442830(spB0, D_00644D20);
                    func_00275980(spB0, spF0, 0x40);
                    func_00442428(sp130, spF0);
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, sp130, 0, 0, D_00795E60);
                } else {
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n = (s16)(n + 1);
            }
        }
        if ((s16)n == 0) {
            func_002b2970(&sp1C8, 135.0f, 195.0f);
            func_00330e50(0x1D2, sp1C8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            func_00275520(153.0f, 185.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C, 0, 0, D_00795E60);
        }
    } else {
        u8 *ent = D_006432B0 + v * 0x1C;
        func_002b2970(&sp1C0, 135.0f, 96.0f);
        func_00330e50(0x1D2, sp1C0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
        if (*(s8 *)(ent + 2) == 0) {
            func_00275520(153.0f, 86.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D18, 0, 0, D_00795E60);
        } else {
            s8 vv = *(s8 *)(ent + 2);
            for (k = 0; (s16)k < 3; k = (s16)(k + 1)) {
                char *str0 = *(char **)(D_00643220 + vv * 0xC + (s16)k * 4);
                s16 v6 = *(s16 *)(ent + 6);
                s16 v4 = *(s16 *)(ent + 4);
                u8 *s;
                func_00442830(sp130, str0);
                s = func_002b32d0((u8 *)sp130, (s32)((u8 *)iGpffffb440 + v4 * 0x11), (u8 *)((u8 *)iGpffffb440 + v6 * 0x11), (u8 *)((u8 *)iGpffffb44c + v4 * 0x15), (u8 *)((u8 *)iGpffffb44c + v6 * 0x15));
                func_00275520(153.0f, (f32)((s16)k * 0x19 + 0x56), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, (const char *)s, 0, 0, D_00795E60);
            }
        }
        n = 0;
        for (j = 0; (s16)j < 5; j = (s16)(j + 1)) {
            if (*(s8 *)(t + *(s8 *)(t + 0x2D6) * 5 + (s16)j + 0x2C4) == 1) {
                s32 off = (s16)n * 0x22;
                u8 *e = ent + (s16)j * 4;
                s8 id = *(s8 *)(e + 8);
                func_002b2970(&sp1B8, 135.0f, (f32)(off + 0xC3));
                func_00330e50(0x1D2, sp1B8, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
                if (id == 0xA) {
                    u16 w = *(u16 *)(e + 10);
                    u8 *s = func_00243840(w);
                    func_00442830(sp130, (const char *)s);
                    func_00442830(spB0, D_00644D20);
                    func_00275980(spB0, spF0, 0x40);
                    func_00442428(sp130, spF0);
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, sp130, 0, 0, D_00795E60);
                } else {
                    func_00275520(153.0f, (f32)(off + 0xB9), 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_006430B0[id], 0, 0, D_00795E60);
                }
                n = (s16)(n + 1);
            }
        }
        if ((s16)n == 0) {
            func_002b2970(&sp1B0, 135.0f, 195.0f);
            func_00330e50(0x1D2, sp1B0, 43.0f, func_002b2a30(0, 0x42, 0x42, 0xCA), alpha, 0, 1.0f, 1.0f, D_00795E60);
            func_00275520(153.0f, 185.0f, 43.0f, func_002b2a30(0xFF, 0xFF, 0xFF, alpha), 0, 1, D_00644D1C, 0, 0, D_00795E60);
        }
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);
#endif

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
// FUN_00330060 NONMATCHING
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
