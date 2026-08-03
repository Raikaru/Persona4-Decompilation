/* Consolidated Persona 4 source units. */
/* Original translation unit y_CmbCardEff.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef struct { f32 x, y, z; } CmbVec3f;
typedef struct { f32 x, y; } CmbVec2f;
typedef struct { u8 b0, b1, b2, b3; } CmbRGBA;

void func_0044ea90(void *arg0, u32 arg1);
s32 func_00451fc0(u8 *arg0, void *arg1, u32 arg2, u32 arg3, u32 arg4, void (*arg5)(u8 *), void (*arg6)(u8 *), void *arg7);
void func_00440b68(void *arg0, void *arg1, u32 arg2);
u32 func_00454a60(u8 *arg0, u32 arg1);
s32 func_00348330(u8 *arg0);
s32 func_00348c40(u8 *arg0);
s32 func_004553c0(u8 *ptr);
void func_004b1150(u32 arg0);
void func_00454bd0(u8 *ptr);
void func_0036d940(void *arg0);
s32 func_00347c70(u8 *arg0);
u8 *func_00348160(u8 *arg0, s32 *arg1);
void *func_00348290(u8 *arg0);
void func_003482a0(u8 *arg0, u8 arg1, u8 arg2, u16 arg3);
void func_003482d0(u8 *arg0, CmbVec2f arg1, CmbVec2f arg2, u16 arg3);
void func_003489c0(u8 *arg0, CmbVec3f *src, CmbRGBA col, u16 arg3, u32 arg4, f32 f0, f32 f1, f32 f2, f32 f3);
void func_002b2a60(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
s32 *func_00331620(void);
void func_003f6440(u32 arg0, u32 arg1);
void func_003dc740(void *arg0, void *arg1, u32 arg2);
void func_0036de20(void *arg0, void *arg1);
void func_0036dd10(void *arg0, void *arg1, f32 arg2);
s32 func_00285b30(void);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
u8 *func_00457120(void);
u8 *func_00461390(void *a, s32 b, void *c, s32 d);
void func_00347b30(u8 *arg0);
extern f32 D_008872F8[];
extern u8 D_00794F00[];
s32 func_00106330(s32 id);
void func_00106390(s32, s32);
void func_002b2970(s64 *out, f32 x, f32 y);
void func_002b29a0(u8 *arg0, f32 f0, f32 f1, f32 f2);
u8 func_0045aeb0(s16 channelIndex, u8 *name);
s32 func_00452490(s32 handle);
extern u8 D_0064A5B0[];
s16 func_002b2d00(s32, s32, s32, s32, s32);
s32 func_004b1130(s32);
s32 func_004b11b0(s32);
void func_004b1190(s32);
void func_004b11d0(s32, s32);
void func_004b1250(s32, u8 *);
void func_004b1290(s32, f32, f32, f32);
void func_004b13d0(s32, f32);
void func_004b13f0(s32, u8 *);
s32 func_004b1520(s32);
extern u8 D_005DC7D0[];
void func_002b5db0(s32, s64, void *);
s32 func_002b5c90(u8 *, s64);
void func_002b29e0(void *, f32, f32);
void func_002b5e30(s32, u32);
void func_002b6130(s32, s32);
void func_002b5e20(s32, f32);
void func_002b5fd0(s32, s64, s64, void *, void *, s32, s32);
s8 *func_002b5da0(s32);

extern u8 D_0064E590[];
extern u8 iGpffffa938;
extern u8 D_0064A4A0[];
extern u8 D_0064A5E8[];
extern u8 D_0064A600[];
extern u8 D_0064A5D0[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u32 D_00763A28;
extern s64 D_0064A5A0[];
extern f32 D_0064A5A8[];
extern void (*D_00887300[])(s32, s32);



/* measured: case-2 loop's address for the loop-test load (obj + i*2 + 2) is CSE'd with
   the q pointer used in the second func_0036da40 call: mwcc hoists the addiu $16-equivalent
   above the lhu/beqz and folds the +2 into the reload's displacement (nd 62 overall, all
   in this loop + branch-target shifts). Tried inline duplicates, q locals, u32-cast trees,
   shift-vs-mul scales, s16 copy (propagated back) — every spelling CSEs. The brief's
   "CSE of a loop-test load that retail re-issues in the body" floor; also the second
   call's pointer+0xE398 materialization is deferred past the lhu arg (fb90-style floor). */
// FUN_0033E5C0
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033e5c0);

// FUN_0033E7C0
void func_0033e7c0(u8 *arg0) {
    func_0036d940((u8 *)(*(u8 **)(arg0 + 0x38)) + 0x20);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* measured: rule 1 refined — the three `ldr $6,0($18/30)/ldl $6,7(...)` pairs (s64
   args to func_0033fc00/0033fb10/0033fb90 at pointer = slot+0x20, disp 0 but base is
   4-mod-8 via the 0x84 stride) come from CmbVec2f BY-VALUE args: probe-verified
   `*(CmbVec2f *)p` at disp 0 emits ldr/ldl while `*(s64 *)p` at disp 0 emits plain ld
   (and `*(s64 *)(p+0x2C)` emits ldr/ldl per the brief's rule). The func_0033fc00 arg3
   `*(CmbVec2f *)(slot + b*0xC + 0x2C)` and s16 arg4 match too. Full-function match
   blocked by the same stack-alloc/register wall as func_0033fc80 (0x84-stride state
   machine, 970-line dispatcher). */
// FUN_0033E810
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033e810);

// FUN_0033F660
void func_0033f660(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* measured: retail hoists the D_008873F4 allocator-table base into saved $20
   (lui/addiu once, lw $2,0($20); jalr twice across the func_00451fc0 calls); mwcc b210
   folds both the direct array spelling and a cached local (u8 *(**fp)(...)) back to
   per-call lui/lw, which also reshuffles the saved-register allocation ($s0/$s2/$s4 vs
   retail $s1/$s0/$s4). D_008873F4 vtable-base hoisting floor (same mechanism as the
   confirmed D_00887300 floor). */
// FUN_0033F690
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033f690);

// FUN_0033FA20
void *func_0033fa20(u8 *arg0) {
    return *(void **)(arg0 + 0x38);
}

/* measured: two scheduler-order defects keep this at nd 12. (1) The &sp40 argument setup
   (addiu $a1,$sp,0x40) and the load-load-store-store of D_0064A5A0/D_0064A5A8: retail
   emits [addiu a1][lui][ld][lui][lwc1][sd][swc1], mwcc emits [lui][ld][sd][lui][lwc1]
   [swc1][addiu a1] for scalar/array/struct-member spellings; the one-statement 16-byte
   struct copy does hoist the addiu a1 first but then copies ld/ld (16B) instead of
   ld/lwc1, and a pack(4) 12-byte copy degrades to three lwc1s. (2) The shared
   (s32)arg1*0x84 mul for the p84 address is CSE-hoisted above the arg0 chain
   (base+idx+0x2758) in every spelling (inline, locals, u32-cast trees, 132-vs-0x84
   literals, declaration/statement reorderings); retail computes it in place between
   arg0 and the float. Both measured across 15+ variants. Scheduler-CSE floor. */
// FUN_0033FA30
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033fa30);

// FUN_0033FB10
void func_0033fb10(u8 *arg0, s8 arg1, s64 arg2) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 scaled = (s32)arg1 * 0x84;
    func_0036dd10((u8 *)(*(u32 *)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758), &arg2, 90.0f * *(f32 *)(scaled + (u32)obj + 0x8C));
}
/* measured: retail computes (base + idx*0xFB0) in $v0 then materializes 0xE398 with
   `ori $at,$zero,0xE398; addu $a0,$v0,$at` before the 90.0f mul block; mwcc b210 with
   any pointer-arithmetic spelling (`+ 0xE398`, `addr += 0xE398`, struct-member access,
   u32-cast variants) emits the ori+addu only by deferring it past the float argument,
   which reallocates the chain result to $v1 and hoists lui/mtc1/mul.s (nd 8); with the
   u32-chain spelling the constant folds as two addiu (0x7FFF+0x6399) instead of ori+addu
   (nd 2). Both spellings measured via probe_variants and standalone compiles; no
   spelling reproduces retail's order+encoding simultaneously. $v0/$v1 coalescing floor. */
// FUN_0033FB90
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033fb90);
/* measured: retail loads base early (lw $a2,0x38($a0) first) and ends with
   `addu $a0,$v1,$a2` (index,base); with the scaled offset named in an s32 local and
   base added as a plain assignment (the brief's addu-operand-order recipe) mwcc emits
   the right addu but load-sinks the single-use base load past the index math (nd 7);
   with the load inline as the right operand of + it stays early but the addu comes out
   base-first `addu $a0,$a2,$v1` (nd 1). Measured all combos of inline/local, left/right
   operand order, struct-subscript and cast spellings; the load position and the addu
   operand order are mutually exclusive in every spelling. Load-sinking + addu-order floor. */
// FUN_0033FC00
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033fc00);
/* measured: rule 1 APPLIES — `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), *(CmbVec2f *)&vA0, 3)`
   emits retail's exact ldr $a1,0x134/ldl $a1,0x13B pair (candidate obj verified; only
   saved-reg $s0-vs-$s1 differs) — the 8-byte CmbVec2f by-value read at 4-mod-8 offset
   0x134 is ordinary source, not VU0. Whole function otherwise stuck at nd 680 across 4
   spellings (scalar u8 stack model, u8[4]+CmbRGBA-copy model, CmbRGBA buffers): mwcc b210
   packs/coalesces the byte-buffer stack locals (frame 0x100 vs retail 0x130, obj 2588B)
   and rotates saved regs ($s2/$s3 obj vs retail $s3, extra $f21) — the 0x84-stride card
   state machine needs the original declaration shape/lifetimes to reproduce retail's
   0xEC-0x12F slot layout; m2c's scalar draft does not round-trip. Stack-alloc floor. */
// FUN_0033FC80
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033fc80);

/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single
   ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)`
   with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified
   emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole
   0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// FUN_003407F0
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_003407f0);

/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single
   ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)`
   with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified
   emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole
   0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// FUN_00341640
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00341640);

/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single
   ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)`
   with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified
   emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole
   0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// FUN_003427A0
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_003427a0);

/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single
   ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)`
   with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified
   emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole
   0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// FUN_00343CF0
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00343cf0);

/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single
   ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)`
   with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified
   emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole
   0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// FUN_00345700
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00345700);

// FUN_00347940
void func_00347940(u8 *arg0) {
    u8 *obj;
    s16 i;

    obj = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < 0xC; i++) {
        *(s32 *)(obj + (s32)i * 4 + 0x658) = 0;
    }
    switch (*(s8 *)(obj + 0x63E)) {
    case 6:
        *(u32 *)(obj + 0x670) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x674) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x678) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x67C) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x680) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x684) = (u32)func_00348160(arg0, func_00331620());
    case 5:
        *(u32 *)(obj + 0x66C) = (u32)func_00348160(arg0, func_00331620());
    case 4:
        *(u32 *)(obj + 0x668) = (u32)func_00348160(arg0, func_00331620());
    case 3:
        *(u32 *)(obj + 0x664) = (u32)func_00348160(arg0, func_00331620());
    case 2:
        *(u32 *)(obj + 0x660) = (u32)func_00348160(arg0, func_00331620());
    case 1:
        *(u32 *)(obj + 0x658) = (u32)func_00348160(arg0, func_00331620());
        *(u32 *)(obj + 0x65C) = (u32)func_00348160(arg0, func_00331620());
        break;
    }
}

/* measured: retail hoists the D_00887300 render-vtable base into saved $16
   (lui/addiu once, then lw $2,0($16) per call, frame 0x30 with sq $16/$17); mwcc b210
   folds both the direct array spelling and a cached local back to per-call
   lui/lw (frame 0x20, one saved reg) — measured nd vs the 0x30 frame layout.
   D_00887300 vtable-base hoisting floor (confirmed by sibling wave). */
// FUN_00347B30
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00347b30);

/* measured: MAC block (`obj->0x10 = obj->0x134 - 64.0f * obj->0x1A0` and 7 siblings)
   compiles byte-exact (adda.s $f2,$f0 / msub|madd.s $f0,$f3,$f1, zero hoisted once) —
   the b210 FMA chain is fully source-driven. The GS doubled-alpha conversion
   (lbu + bltz + srl/andi/or + cvt.s.w + add.s x+x per byte site) is a real CFG
   floor: u8/s32/u32 locals, both if/else orders, inline-vs-local stores, x+x vs
   *2.0f, ternary, and per-site fresh locals ALL emit a 3-way CFG (double bltz +
   dead sra+srl doubling copies, obj 1388B vs 1216B window, nd 312); only an s8
   load (lb) gives retail's single-branch clean CFG (obj 1124B, nd 265) but is
   1 byte off retail's lbu per site (6 sites) plus the 0x4F000000 guard on the
   0x19B store is deleted (nd 265, best of 4). Same family as cmmScript
   func_0024f160 / mdlManager doubled-alpha conv-CFG floors. */
// FUN_00347C70
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00347c70);
// FUN_00348130
void func_00348130(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00348160
u8 *func_00348160(u8 *arg0, s32 *arg1) {
    u8 sp5C[4];
    u8 *ret;
    u8 *blk;
    s16 i;

    func_0044ea90(D_0064A4A0, 0x702);
    blk = D_008873F4[0](1, 0x1B0, 0x40000);
    ret = (u8 *)func_00451fc0(arg0, D_0064A5D0, 0xF, 0, 0, (void (*)(u8 *))func_00347c70, func_00348130, blk);
    *(s32 **)(blk + 0x118) = arg1;
    *(s32 *)(blk + 0x11C) = 0;
    for (i = 0; i < 3; i++) {
        func_002b2a60(&sp5C[0], 0xFF, 0xFF, 0xFF, 0xFF);
        *(CmbRGBA *)(blk + (s32)i * 4 + 0x190) = *(CmbRGBA *)&sp5C[0];
    }
    *(u32 *)(blk + 0x1A0) = 0x3F800000;
    return ret;
}

// FUN_00348290
void *func_00348290(u8 *arg0) {
    return *(void **)(arg0 + 0x38);
}

// FUN_003482A0
void func_003482a0(u8 *arg0, u8 arg1, u8 arg2, u16 arg3) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(u32 *)(obj + 0x11C) |= 0x10;
    *(u8 *)(obj + 0x19B) = arg1;
    *(u8 *)(obj + 0x193) = arg1;
    *(u8 *)(obj + 0x197) = arg2;
    *(u16 *)(obj + 0x19C) = 0;
    *(u16 *)(obj + 0x19E) = arg3;
}

// FUN_003482D0
void func_003482d0(u8 *arg0, CmbVec2f arg1, CmbVec2f arg2, u16 arg3) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(u32 *)(obj + 0x11C) |= 4;
    *(CmbVec2f *)(obj + 0x134) = arg1;
    *(CmbVec2f *)(obj + 0x124) = *(CmbVec2f *)(obj + 0x134);
    *(CmbVec2f *)(obj + 0x12C) = arg2;
    *(u16 *)(obj + 0x13E) = 0;
    *(u16 *)(obj + 0x13C) = arg3;
}

/* measured: nd 16, obj 1292B vs 1296B window — EVERYTHING matches byte-for-byte
   except the guarded-conversion result register: the three
   `if (2.1474836e9f > f0) { v = (u8)(s32)f0; } else { v = (u8)((s32)(f0-2.1474836e9f)|0x80000000); }`
   chains (explicit guard needed — implicit (u8)(s32) deletes the c.ole.s/bc1t guard
   AND the per-arm andi) keep b210's mfc1/or/sb chain in $v0 where retail coalesces
   into $v1 (3 sites x 5 words; tried u8 locals, f0/v declaration orders, inline
   stores — no shift). Same family as cmmScript func_0024c0e0's conversion-coloring
   floor. Also measured: outer state switch needs cases declared 0,1,2,3 ascending
   (reversed beq chain 3,2,1,0 + beqz); inner 0x39 dispatch is a 3-way if/else-if
   chain (x==0 / x==1 / x==2) whose x==2 test reuses the dispatch's $a1=2 constant;
   D_005DC7D0 must be indexed (`&D_005DC7D0[idx*0x54]`) or b210 hoists the base into
   a saved reg and rotates obj to $s1. All verified against this function's retail. */
// FUN_00348330
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00348330);

// FUN_00348840
void func_00348840(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 p = *(u32 *)(obj + 8);
    if (p != 0) {
        func_004b1150(p);
        *(u32 *)(obj + 8) = 0;
    }
    if (*(u8 *)(obj + 0x48) == 1) {
        u32 q = *(u32 *)(obj + 0x44);
        if (q != 0) {
            func_004b1150(q);
            *(u32 *)(obj + 0x44) = 0;
        }
    }
    func_00454bd0(*(u8 **)obj);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_003488D0
u8 *func_003488d0(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *ret;
    u8 *blk;

    func_0044ea90(D_0064A4A0, 0x7F5);
    blk = D_008873F4[0](1, 0x70, 0x40000);
    ret = (u8 *)func_00451fc0(arg0, D_0064A5E8, 0xF, 0, 0, (void (*)(u8 *))func_00348330, func_00348840, blk);
    *(s8 *)(blk + 4) = 0;
    *(s8 *)(blk + 0x14) = arg2;
    func_00440b68(&D_00763A28, D_0064A4A0, 0x805);
    *(u32 *)(blk + 0) = func_00454a60(arg1, 0);
    *(u32 *)(blk + 0x40) = 0x437F0000;
    return ret;
}
// FUN_003489C0
void func_003489c0(u8 *arg0, CmbVec3f *src, CmbRGBA col, u16 arg3, u32 arg4, f32 f0, f32 f1, f32 f2, f32 f3) {
    CmbVec3f tmp = *src;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(s8 *)(obj + 4) = 1;
    *(CmbVec3f *)(obj + 0x18) = tmp;
    *(f32 *)(obj + 0x24) = f0;
    *(f32 *)(obj + 0x28) = f1;
    *(f32 *)(obj + 0x2C) = f2;
    *(f32 *)(obj + 0x30) = f3;
    *(CmbRGBA *)(obj + 0x34) = col;
    *(f32 *)(obj + 0x40) = (f32)col.b3;
    *(u16 *)(obj + 0x3C) = 0;
    *(u16 *)(obj + 0x3A) = arg3;
    *(u8 *)(obj + 0x39) = 0;
    *(u32 *)(obj + 0x10) = arg4;
}

// FUN_00348A90
void func_00348a90(u8 *arg0, CmbVec3f *src1, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f *src2, CmbRGBA arg6, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    CmbVec3f tmp1 = *src1;
    CmbVec3f tmp2 = *src2;
    u8 *obj = *(u8 **)(arg0 + 0x38);
    f32 farg2 = *(f32 *)&arg2;
    *(s8 *)(obj + 4) = 1;
    *(CmbVec3f *)(obj + 0x18) = tmp1;
    *(f32 *)(obj + 0x24) = f0;
    *(f32 *)(obj + 0x28) = f1;
    *(f32 *)(obj + 0x2C) = f2;
    *(f32 *)(obj + 0x30) = f3;
    *(CmbRGBA *)(obj + 0x34) = arg2;
    *(f32 *)(obj + 0x40) = (f32)((u8 *)&farg2)[3];
    *(u16 *)(obj + 0x3C) = 0;
    *(u16 *)(obj + 0x3A) = arg3;
    *(u8 *)(obj + 0x39) = 0;
    *(u32 *)(obj + 0x10) = arg4;
    *(CmbVec3f *)(obj + 0x4C) = tmp2;
    *(f32 *)(obj + 0x58) = f4;
    *(f32 *)(obj + 0x5C) = f5;
    *(f32 *)(obj + 0x60) = f6;
    *(f32 *)(obj + 0x64) = f7;
    *(CmbRGBA *)(obj + 0x68) = arg6;
    *(u8 *)(obj + 0x48) = 1;
}

// FUN_00348BE0
s32 func_00348be0(u8 *arg0) {
    return func_004553c0(*(u8 **)(*(u8 **)(arg0 + 0x38))) != 0;
}

// FUN_00348C10
u32 func_00348c10(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38) + 4) == 2;
}
// FUN_00348C30
void func_00348c30(u8 *arg0, u16 arg1) {
    *(u16 *)(*(u8 **)(arg0 + 0x38) + 0x3E) = arg1;
}

/* measured: full transcription of the init loop + 5 func_002b5fd0 groups; every call
   sequence/constant matches retail instruction-for-instruction, but mwcc b210 packs the
   23 s64 stack buffers (frame 0x150 vs retail 0x1A0, nd 104) in every spelling — scalar
   s64 locals, q[12]/r[11] arrays (retail's 0x80-0x18F layout is exactly array-like),
   decl-order flips. Same stack-alloc floor as func_0033fc80 / func_00347c70: b210's
   slot coalescing of disjoint-lifetime address-taken buffers cannot reproduce this
   file's retail frames from C. State switch: ascending case order 0,1 gives retail's
   reversed beq-1/beqz-0 dispatch. */
// FUN_00348C40
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00348c40);

// FUN_00349260
void func_00349260(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

extern u8 D_0064A600[];
s32 func_00348c40(u8 *arg0);

// FUN_00349290
u8 *func_00349290(u8 *arg0, u8 arg1) {
    u8 *blk;
    u8 *ret;

    func_0044ea90(D_0064A4A0, 0x8B9);
    blk = D_008873F4[0](1, 0x18, 0x40000);
    ret = (u8 *)func_00451fc0(arg0, D_0064A600, 0xF, 0, 0, (void (*)(u8 *))func_00348c40, func_00349260, blk);
    *(s8 *)(blk + 0) = arg1;
    *(s8 *)(blk + 1) = 0;
    return ret;
}
