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
void func_00347b30(u8 *arg0, u8 *arg1);
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



/* measured: re-tested recipe A (no u16->float conversion exists in this function —
   N/A) and recipe B (no global base hoist; retail itself rematerializes the 0x19FD8
   lui/addu twice). The recorded "loop-test load CSE" floor did NOT reproduce:
   with the reload written as its own expression (q = (u16 *)(obj + i*2 + 2) inside
   the if, reload `lhu $a1, ($q)`) mwcc emits retail's exact shape — test lhu at
   disp 2, addiu q after the beqz, disp-0 reload, ori 0xE398 before the second jal
   (nd 62 -> 39, obj 488B vs 512B window). Actual residual: (1) a 3-register saved
   rotation obj=$s0/i=$s1/q=$s2 vs retail q=$s0/obj=$s1/i=$s2 (p=$s3 matches); tried
   4 declaration orders incl. q-first — the allocator ignores decl order here;
   (2) the q and p address computations in the loop body are swapped (mine p then
   q, retail q then p) — a scheduler-order defect across the two call args. */
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

/* measured: recipe B (u32 cast base: `u32 base = (u32)D_008873F4;` + per-call
   `((u8 *(*)(s32,s32,s32))*(u32 *)base)(...)`) SOLVES the recorded base-hoist floor:
   retail's saved-$20 lui/addiu once + lw $2,0($20)/jalr twice now compiles
   byte-exact (the typed-pointer local and direct array spelling still fold to
   per-call lui/lw). With ret2 declared FIRST, everything matches except the
   first copy loop (arg1[i] -> blk2+2): a 3-register temp rotation (mine
   ext=$v0/scale=$a0/lh=$v1/i=$a1 vs retail ext=$v1/scale=$a1/lh=$a0/i=$a2)
   plus the `sw ret2,4(blk1)` after the loop reads $s1 where retail's surviving
   $v0 copy feeds it — my loop clobbers $v0 so b210 kills ret2's $v0 copy
   (nd 22, all 22 words in this loop + the store). Tried 4 decl orders (only
   ret2-first gives the right saved map), s16/u32 index casts, pointer locals. */
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

// FUN_00347B30
void func_00347b30(u8 *arg0, u8 *arg1) {
    u32 base = (u32)D_00887300;

    ((void (*)(s32, s32))*(u32 *)base)(6, 1);
    ((void (*)(s32, s32))*(u32 *)base)(7, 2);
    ((void (*)(s32, s32))*(u32 *)base)(8, 1);
    ((void (*)(s32, s32))*(u32 *)base)(9, 2);
    ((void (*)(s32, s32))*(u32 *)base)(0xC, 1);
    ((void (*)(s32, s32))*(u32 *)base)(2, 3);
    ((void (*)(s32, s32))*(u32 *)base)(0xB, 6);
    ((void (*)(s32, s32))*(u32 *)base)(0xA, 5);
    func_003f6440(2, 0x48);
    func_003f6440(3, 0x71801);
    *(s32 *)(arg1 + 0x20) = 0;
    *(s32 *)(arg1 + 0x24) = 0;
    *(u32 *)(arg1 + 0x60) = 0x3F800000;
    *(s32 *)(arg1 + 0x64) = 0;
    *(s32 *)(arg1 + 0xA0) = 0;
    *(u32 *)(arg1 + 0xA4) = 0x3F800000;
    *(u32 *)(arg1 + 0xE0) = 0x3F800000;
    *(u32 *)(arg1 + 0xE4) = 0x3F800000;
    ((void (*)(s32, s32))*(u32 *)base)(1, *func_00331620());
}

/* measured: re-tested with recipe A (4-part bltz shape: s32 v = *(u8*)load, u32 c = v,
   (f32)(s32)((c>>1)|(c&1)), x+x doubling) + recipe B (D_008872F8 base): the single
   bare bltz guard, srl/andi/or, cvt.s.w and add.s x+x per site ALL now reproduce
   retail byte-for-byte (nd 312 -> 263, obj 1216B = window). Two residuals remain:
   (1) the or/mtc1 chain at each of the 6 conversion sites keeps its result in $v1
   (or $v1,$a0,$v1) where retail coalesces into $a0 (or $a0,$a0,$v1) — tried both
   if/else orders, j=(u32)i loop copies, per-site fresh locals, decl reorders: the
   or-result register never moves; (2) mwcc b210 places the loop-invariant
   `lui %hi(D_008872F8)` INSIDE the loop body (direct array spelling) or emits
   lui+addiu at entry (pointer local) — retail hoists a lui-ONLY base into $v0 at
   entry with %lo folded into the lwc1; no spelling reproduces the 1-word hoist.
   Recipe A cracked the doubled-alpha CFG; the or-register coloring + lui hoist
   remain compiler floors (same family as func_0024f160 / mdlManager conv-CFG). */
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
