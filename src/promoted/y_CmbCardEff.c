/* Consolidated Persona 4 source units. */
/* Original translation unit y_CmbCardEff.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef struct { f32 x, y, z; } CmbVec3f;
typedef struct { f32 x, y; } CmbVec2f;
typedef struct { u8 b0, b1, b2, b3; } CmbRGBA;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    s64 a0, a8;
    CmbVec3f b0;
    u32 pad_bc;
    s64 c0, c8, d0, d8, e0;
    u32 pad_e8;
    u8 bytes[0x44];
} CmbFc80Work;
typedef union {
    s64 q;
    CmbVec2f v;
} CmbWorkPair;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    CmbWorkPair pA0, pA8, pB0, pB8, pC0, pC8;
    CmbVec3f d0;
    u32 pad_dc;
    CmbWorkPair pE0, pE8, pF0, pF8, p100, p108, p110, p118, p120;
    u8 bytes[0x58];
} Cmb407Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    CmbWorkPair pA0, pA8, pB0, pB8, pC0, pC8, pD0, pD8,
                pE0, pE8, pF0;
    CmbVec3f vecF8;
    u32 pad104;
    CmbWorkPair p108, p110, p118, p120, p128, p130, p138, p140,
                p148, p150, p158, p160, p168, p170;
    u8 bytes[0x68];
} Cmb416Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    u8 bytes[0x1B0];
} Cmb427Work;
typedef struct {
    f32 f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c;
    f32 fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc;
    f32 fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0, ff4, ff8, ffc;
    f32 f100, f104, f108, f10c, f110, f114, f118, f11c, f120, f124;
    f32 f128, f12c, f130, f134, f138, f13c, f140, f144, f148, f14c;
    u8 bytes[0x180];
} Cmb43Work;

static inline u8 *cmbAddPtrRev(u32 base, u32 index) { return (u8 *)(index + base); }

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
void func_0036d860(void *arg0, u32 arg1);
void func_0036d230(u32 arg0);
s32 func_0036d960(void);
void func_0036da40(void *arg0, u32 arg1);
s32 func_00347c70(u8 *arg0);
u8 *func_00348160(u8 *arg0, s32 *arg1);
void *func_00348290(u8 *arg0);
void func_003482a0(u8 *arg0, u8 arg1, u8 arg2, u16 arg3);
void func_003482d0(u8 *arg0, CmbVec2f arg1, CmbVec2f arg2, u16 arg3);
void func_003489c0(u8 *arg0, CmbVec3f *src, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA col, u16 arg3, u32 arg4);
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
extern f32 iGpffff8360;
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
extern u8 D_0064A4E0[];
extern u8 D_0064A4B0[];
extern u8 D_0064A500[];
extern u8 D_0064A520[];
extern u8 D_0064A540[];
extern u8 D_0064A560[];
extern u8 D_0064A580[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
s32 func_0033e810(u8 *arg0);
s32 func_0033e5c0(u8 *arg0);
u8 *func_003488d0(u8 *arg0, u8 *arg1, s8 arg2);
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
   q, retail q then p) — a scheduler-order defect across the two call args.
   Re-measured this wave: the gp-relative func_00440b68 arg0 is `&iGpffffa938`
   (gp-0x56C8, symbol already in the file); the function returns s32 (retail ends
   daddu $2,$0), so it is declared `s32 func_0033e5c0(u8*)` and the f690 callback
   sites cast it `(void (*)(u8 *))`; the loop's `*(s8 *)(obj+0x19FD8) += 1` must be
   s8 (signed lb) not u8 (lbu). `#pragma opt_propagation off` around the body
   REGRESSED to nd 49 (the q-then-p interleave is not a base-load-sink, it is a
   two-call-arg scheduler order). nd 39 confirmed floor. */
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

/* measured: MATCHED this wave — the recorded nd-22 copy-loop rotation floor is broken
   by three spellings together: (1) recipe B (u32 cast base `u32 base = (u32)D_008873F4;`
   + per-call `((u8 *(*)(s32,s32,s32))*(u32 *)base)()`) for the saved-$20 lui/addiu
   base hoist (typed-pointer local and array spelling still fold to per-call lui/lw);
   (2) `ret` declared FIRST (before blk1/base) — any other order puts ret in $s0 and
   blk1 in $s1, retail has ret=$s1/blk1=$s0, a pure 40-word rotation; (3) a SEPARATE
   `s16 j` counter for the second 0x84-stride loop — reusing i makes b210 pick $a2
   where retail's second loop counter is $a0 (the first loop holds $a2). nd path:
   68 (plain array spelling) -> 40 (recipe B) -> 8 (ret-first) -> 0 (separate j).
   Callbacks func_0033e810/0033e5c0 need file-scope prototypes for the arg passing. */
// FUN_0033F690
u8 *func_0033f690(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *ret;
    u8 *blk1;
    u32 base;
    u8 *blk2;
    u8 *ret2;
    s16 i;
    s16 j;
    func_0044ea90(D_0064A4A0, 0x1B8);
    base = (u32)D_008873F4;
    blk1 = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x6E0, 0x40000);
    ret = (u8 *)func_00451fc0(arg0, D_0064A4E0, 0xF, 0, 0, (void (*)(u8 *))func_0033e810, func_0033f660, blk1);
    func_0044ea90(D_0064A4A0, 0xAD);
    blk2 = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x19FDC, 0x40000);
    ret2 = (u8 *)func_00451fc0(ret, D_0064A4B0, 0xF, 0, 0, (void (*)(u8 *))func_0033e5c0, func_0033e7c0, blk2);
    for (i = 0; i < 0xC; i++) {
        *(s16 *)(blk2 + 2 + (s32)i * 2) = *(s16 *)(arg1 + (s32)i * 2);
    }
    *(u8 *)(blk2 + 0) = 0;
    *(u8 *)(blk2 + 0x19FD8) = 0;
    *(u32 *)(blk1 + 4) = (u32)ret2;
    for (j = 0; j < 0xC; j++) {
        *(s8 *)(blk1 + (s32)j * 0x84 + 0xC) = 0;
    }
    *(s8 *)(blk1 + 0) = 0;
    *(s8 *)(blk1 + 0x63E) = arg2;
    *(s8 *)(blk1 + 8) = 0;
    *(s8 *)(blk1 + 1) = 0;
    *(s8 *)(blk1 + 0x6B8) = 0;
    switch (arg2) {
    case 1:
        *(s8 *)(blk1 + 0x6B9) = 2;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A500, 6);
        break;
    case 2:
        *(s8 *)(blk1 + 0x6B9) = 3;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A520, 6);
        break;
    case 3:
        *(s8 *)(blk1 + 0x6B9) = 4;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A540, 6);
        break;
    case 4:
        *(s8 *)(blk1 + 0x6B9) = 5;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A560, 6);
        break;
    case 5:
        *(s8 *)(blk1 + 0x6B9) = 6;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A580, 6);
        break;
    case 6:
        *(s8 *)(blk1 + 0x6B9) = 0xC;
        *(u32 *)(blk1 + 0x64C) = (u32)func_003488d0(ret, D_0064A580, 6);
        break;
    }
    func_00106390(0x58, 0);
    func_00106390(0x59, 0);
    func_00106390(0x5A, 0);
    func_00106390(0x5B, 0);
    func_00106390(0x5C, 0);
    func_00106390(0x5D, 0);
    func_00106390(0x5E, 0);
    func_00106390(0x5F, 0);
    return ret;
}
// FUN_0033FA20
void *func_0033fa20(u8 *arg0) {
    return *(void **)(arg0 + 0x38);
}

// FUN_0033FA30
#pragma push
/* measured: opt_propagation off keeps &sp40 in $a1 before the D_0064A5A0/D_0064A5A8
   staging loads and the p84 multiply below the arg0 chain (the "scheduler-CSE floor"
   above was propagation, not scheduling). */
#pragma opt_propagation off
void func_0033fa30(u8 *arg0, s8 arg1) {
    struct { f32 sp30[4]; s64 sp40; f32 sp48; } sp;
    s64 txy;
    f32 tz;
    f32 *p40;
    u8 *obj;
    u8 *table;
    u8 *pFB0;
    u8 *arg0_for_dd;
    u8 *p84;

    obj = *(u8 **)(arg0 + 0x38);
    p40 = (f32 *)&sp.sp40;
    txy = D_0064A5A0[0];
    tz = *(f32 *)&D_0064A5A0[1];
    sp.sp40 = txy;
    sp.sp48 = tz;
    func_003dc740(&sp.sp30, p40, 0);
    table = *(u8 **)(*(u8 **)(obj + 4) + 0x38);
    if ((s8)*table == 4) {
        pFB0 = table + (s32)arg1 * 0xFB0;
        arg0_for_dd = pFB0 + 0x2758;
        p84 = obj + (s32)arg1 * 0x84;
        func_0036dd10(arg0_for_dd, p84 + 0x20, 90.0f * *(f32 *)(p84 + 0x8C));
        func_0036de20(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758, &sp.sp30);
    }
}
#pragma pop

// FUN_0033FB10
void func_0033fb10(u8 *arg0, s8 arg1, s64 arg2) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    u32 scaled = (s32)arg1 * 0x84;
    func_0036dd10((u8 *)(*(u32 *)(*(u8 **)(obj + 4) + 0x38) + (s32)arg1 * 0xFB0 + 0x2758), &arg2, 90.0f * *(f32 *)(scaled + (u32)obj + 0x8C));
}
/* measured: MATCHED this wave. The nd-8 candidate had the correct 0xFB0 stride,
   stack s64 argument, and 90.0f scaling, but fndiff showed the final 0xE398
   address operation after the float setup (`lui/mtc1/nop/mul.s`) and with the
   wrong intermediate destination register. Applying the matching guide's
   pointer-typed staging lever — first compute `tmp = ptr + 0xE398`, then cast
   that pointer through a u32 local before the call — forces retail's
   `ori $at,$zero,0xE398; addu $a0,$v0,$at` before the float setup. The residual
   changed from 8 words (obj 108B/window 112B) to padding-only nd 1, and scoped
   lverify reports MATCH (normalized_diff 0). */
// FUN_0033FB90
void func_0033fb90(u8 *arg0, s8 arg1, s64 arg2, f32 fparg0) {
    s64 sp18;
    u8 *obj;
    u8 *table;
    u32 scaled;
    u8 *ptr;
    u8 *tmp;
    u32 dst;

    sp18 = arg2;
    obj = *(u8 **)(arg0 + 0x38);
    table = *(u8 **)(*(u8 **)(obj + 4) + 0x38);
    scaled = (s32)arg1 * 0xFB0;
    ptr = table + scaled;
    tmp = ptr + 0xE398;
    dst = (u32)tmp;
    func_0036dd10((u8 *)dst, &sp18, 90.0f * fparg0);
}
/* measured: MATCHED this wave — the old nd-1 "load-sinking + addu-order floor" is broken by
   lever 3 + opt_propagation: the inline helper cmbAddPtrRev carries the index-first addu
   (`addu $a0,$v1,$a2` vs the old base-first `addu $a0,$a2,$v1`) through its parameters,
   and `#pragma opt_propagation off` forces the single-use base load early into $a2
   (helper alone: nd 9, load sinks to $v1 and the sign-ext chain shifts to $a1;
   pragma alone on the plain expression: nd 3, still base-first addu). */
// FUN_0033FC00
#pragma opt_propagation off /* measured: see above; forces the base load early (lw $a2,0x38($a0) first) */
void func_0033fc00(u8 *arg0, s8 arg1, CmbVec2f arg2, CmbVec2f arg3, u16 arg4) {
    u8 *p = cmbAddPtrRev((u32)*(u8 **)(arg0 + 0x38), (u32)((s32)arg1 * 0x84));
    *(CmbVec2f *)(p + 0x20) = arg2;
    *(CmbVec2f *)(p + 0x10) = *(CmbVec2f *)(p + 0x20);
    *(CmbVec2f *)(p + 0x18) = arg3;
    *(u16 *)(p + 0x2A) = 0;
    *(u16 *)(p + 0x28) = arg4;
    *(s8 *)(p + 0xC) |= 1;
}
#pragma opt_propagation on
// FUN_0033FC80
s32 func_0033fc80(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *obj;
    CmbFc80Work work;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 value;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 2) {
            func_002b2a60(&work.bytes[0x3C], 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x18) = *(CmbRGBA *)(work.bytes + 0x3C);
            func_002b2a60(&work.bytes[0x40], 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x1C) = *(CmbRGBA *)(work.bytes + 0x40);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) = *(CmbRGBA *)(work.bytes + 0x1C);
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = *(CmbRGBA *)(work.bytes + 0x18);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 && func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970(&work.d8, 230.0f, 212.0f);
            *(CmbVec2f *)&work.f90 = *(CmbVec2f *)&work.d8;
            func_002b2970(&work.e0, 10.0f, 212.0f);
            *(CmbVec2f *)&work.f98 = *(CmbVec2f *)&work.e0;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = *(CmbVec2f *)&work.f98;
            *(CmbVec2f *)(slot + 0x10) = *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = *(CmbVec2f *)&work.f90;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            func_002b2a60(&work.bytes[0x34], 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x10) = *(CmbRGBA *)(work.bytes + 0x34);
            func_002b2a60(&work.bytes[0x38], 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x14) = *(CmbRGBA *)(work.bytes + 0x38);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) = *(CmbRGBA *)(work.bytes + 0x14);
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = *(CmbRGBA *)(work.bytes + 0x10);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970(&work.c8, 230.0f, 212.0f);
            *(CmbVec2f *)&work.f80 = *(CmbVec2f *)&work.c8;
            func_002b2970(&work.d0, 10.0f, 212.0f);
            *(CmbVec2f *)&work.f88 = *(CmbVec2f *)&work.d0;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) = *(CmbVec2f *)&work.f88;
            *(CmbVec2f *)(slot + 0x94) = *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) = *(CmbVec2f *)&work.f80;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            func_002b2a60(&work.bytes[0x2C], 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 8) = *(CmbRGBA *)(work.bytes + 0x2C);
            func_002b2a60(&work.bytes[0x30], 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0xC) = *(CmbRGBA *)(work.bytes + 0x30);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) = *(CmbRGBA *)(work.bytes + 0xC);
            *(CmbRGBA *)(slot + 0x100) = *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) = *(CmbRGBA *)(work.bytes + 8);
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970(&work.c0, 0x19F, 212.0f);
            *(CmbVec2f *)&work.f78 = *(CmbVec2f *)&work.c0;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) = *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) = func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 2) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x3C);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.b0, 0.0f, 5.0f, 30.0f);
        func_002b2a60(&work.bytes[0x28], 0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.b0,
                      0.0f, 0.0f, 0.0f, 1.0f,
                      *(CmbRGBA *)&work.bytes[0x28], 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 2) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 2) {
                func_002b2970(&work.a8, 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = *(CmbVec2f *)&work.a8;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) = *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) = *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) = *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                func_002b2970(&work.a0, 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)&work.a0, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        i10 = 0;
        while (i10 < 2) {
            func_002b2a60(&work.bytes[0x20], 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)work.bytes = *(CmbRGBA *)(work.bytes + 0x20);
            func_002b2a60(&work.bytes[0x24], 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 4) = *(CmbRGBA *)(work.bytes + 0x24);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) = *(CmbRGBA *)(work.bytes + 4);
            *(CmbRGBA *)(slot + 0x7C) = *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) = *(CmbRGBA *)work.bytes;
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(u8 *)(obj + 0x6B8) = 1;
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 && func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_003407F0
s32 func_003407f0(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb407Work work;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 3) {
            func_002b2a60(work.bytes + 0x50, 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x24) =
                *(CmbRGBA *)(work.bytes + 0x50);
            func_002b2a60(work.bytes + 0x54, 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x28) =
                *(CmbRGBA *)(work.bytes + 0x54);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x28);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x24);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970(&work.p118.q, 185.0f, 297.0f);
            work.pB0.v = work.p118.v;
            func_002b2970(&work.p120.q, -86.0f, 297.0f);
            work.pB8.v = work.p120.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = work.pB8.v;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = work.pB0.v;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            func_002b2a60(work.bytes + 0x48, 0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x1C) =
                *(CmbRGBA *)(work.bytes + 0x48);
            func_002b2a60(work.bytes + 0x4C, 0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x20) =
                *(CmbRGBA *)(work.bytes + 0x4C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x20);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x1C);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970(&work.p108.q, 185.0f, 297.0f);
            work.pA0.v = work.p108.v;
            func_002b2970(&work.p110.q, -86.0f, 297.0f);
            work.pA8.v = work.p110.v;
            slot2 = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot2 + 0xA4) = work.pA8.v;
            *(CmbVec2f *)(slot2 + 0x94) =
                *(CmbVec2f *)(slot2 + 0xA4);
            *(CmbVec2f *)(slot2 + 0x9C) = work.pA0.v;
            *(s16 *)(slot2 + 0xAE) = 0;
            *(s16 *)(slot2 + 0xAC) = 5;
            *(s8 *)(slot2 + 0x90) |= 1;
            func_002b2a60(work.bytes + 0x40,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x14) =
                *(CmbRGBA *)(work.bytes + 0x40);
            func_002b2a60(work.bytes + 0x44,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x18) =
                *(CmbRGBA *)(work.bytes + 0x44);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                *(CmbRGBA *)(work.bytes + 0x18);
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                *(CmbRGBA *)(work.bytes + 0x14);
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970(&work.p100.q, 456.0f, 297.0f);
            *(CmbVec2f *)&work.f98 = work.p100.v;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970(&work.pF0.q, 185.0f, 297.0f);
            *(CmbVec2f *)&work.f88 = work.pF0.v;
            func_002b2970(&work.pF8.q, -86.0f, 297.0f);
            *(CmbVec2f *)&work.f90 = work.pF8.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)&work.f90;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            func_002b2a60(work.bytes + 0x38,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0xC) =
                *(CmbRGBA *)(work.bytes + 0x38);
            func_002b2a60(work.bytes + 0x3C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x10) =
                *(CmbRGBA *)(work.bytes + 0x3C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                *(CmbRGBA *)(work.bytes + 0x10);
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                *(CmbRGBA *)(work.bytes + 0xC);
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970(&work.pE8.q, 456.0f, 297.0f);
            *(CmbVec2f *)&work.f80 = work.pE8.v;
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970(&work.pE0.q, 320.0f, 104.0f);
            *(CmbVec2f *)&work.f78 = work.pE0.v;
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x170);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot + 0x114) |= 8;
            *(s8 *)(slot + 0x170) =
                func_002b2cb0(*(s8 *)(slot + 0x170), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 3) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.d0, 0.0f, -5.0f, 30.0f);
        func_002b2a60(work.bytes + 0x34,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.d0,
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      *(CmbRGBA *)(work.bytes + 0x34), 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 3) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 3) {
                func_002b2970(&work.pC8.q, 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = work.pC8.v;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_002b2970(&work.pC0.q, 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              work.pC0.v, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 3) {
            func_002b2a60(work.bytes + 0x2C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 4) =
                *(CmbRGBA *)(work.bytes + 0x2C);
            func_002b2a60(work.bytes + 0x30,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 8) =
                *(CmbRGBA *)(work.bytes + 0x30);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 8);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 4);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(u8 *)(obj + 0x6B8) = 1;
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_00341640
s32 func_00341640(u8 *arg0) {
    u8 *ret;
    u8 *table6;
    u8 *table;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb416Work work;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    s32 index3;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 4) {
            func_002b2a60(work.bytes + 0x60,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x2C) =
                *(CmbRGBA *)(work.bytes + 0x60);
            func_002b2a60(work.bytes + 0x64,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x30) =
                *(CmbRGBA *)(work.bytes + 0x64);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x30);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x2C);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970(&work.p168.q, 188.0f, 217.0f);
            work.pD8.v = work.p168.v;
            func_002b2970(&work.p170.q, -82.0f, 217.0f);
            work.pE0.v = work.p170.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) = work.pE0.v;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) = work.pD8.v;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            func_002b2a60(work.bytes + 0x58,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x24) =
                *(CmbRGBA *)(work.bytes + 0x58);
            func_002b2a60(work.bytes + 0x5C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x28) =
                *(CmbRGBA *)(work.bytes + 0x5C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x28);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x24);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970(&work.p158.q, 188.0f, 217.0f);
            work.pC8.v = work.p158.v;
            func_002b2970(&work.p160.q, -82.0f, 217.0f);
            work.pD0.v = work.p160.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) = work.pD0.v;
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) = work.pC8.v;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            func_002b2a60(work.bytes + 0x50,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x1C) =
                *(CmbRGBA *)(work.bytes + 0x50);
            func_002b2a60(work.bytes + 0x54,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x20) =
                *(CmbRGBA *)(work.bytes + 0x54);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                *(CmbRGBA *)(work.bytes + 0x20);
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                *(CmbRGBA *)(work.bytes + 0x1C);
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970(&work.p150.q, 458.0f, 217.0f);
            work.pC0.v = work.p150.v;
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) = work.pC0.v;
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970(&work.p140.q, 188.0f, 217.0f);
            work.pB0.v = work.p140.v;
            func_002b2970(&work.p148.q, -82.0f, 217.0f);
            work.pB8.v = work.p148.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) = work.pB8.v;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) = work.pB0.v;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            func_002b2a60(work.bytes + 0x48,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x14) =
                *(CmbRGBA *)(work.bytes + 0x48);
            func_002b2a60(work.bytes + 0x4C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x18) =
                *(CmbRGBA *)(work.bytes + 0x4C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                *(CmbRGBA *)(work.bytes + 0x18);
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                *(CmbRGBA *)(work.bytes + 0x14);
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970(&work.p138.q, 458.0f, 217.0f);
            work.pA8.v = work.p138.v;
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) = work.pA8.v;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970(&work.p130.q, 323.0f, 337.0f);
            work.pA0.v = work.p130.v;
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x170);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) = work.pA0.v;
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot + 0x114) |= 8;
            *(s8 *)(slot + 0x170) =
                func_002b2cb0(*(s8 *)(slot + 0x170), 1, 5, 0, 1);
            func_002b2970(&work.p120.q, 188.0f, 217.0f);
            *(CmbVec2f *)&work.f90 = work.p120.v;
            func_002b2970(&work.p128.q, -82.0f, 217.0f);
            *(CmbVec2f *)&work.f98 = work.p128.v;
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)&work.f98;
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 5;
            *(s8 *)(slot + 0x198) |= 1;
            func_002b2a60(work.bytes + 0x40,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0xC) =
                *(CmbRGBA *)(work.bytes + 0x40);
            func_002b2a60(work.bytes + 0x44,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x10) =
                *(CmbRGBA *)(work.bytes + 0x44);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                *(CmbRGBA *)(work.bytes + 0x10);
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                *(CmbRGBA *)(work.bytes + 0xC);
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 5;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970(&work.p118.q, 458.0f, 217.0f);
            *(CmbVec2f *)&work.f88 = work.p118.v;
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970(&work.p110.q, 323.0f, 337.0f);
            *(CmbVec2f *)&work.f80 = work.p110.v;
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970(&work.p108.q, 323.0f, 82.0f);
            *(CmbVec2f *)&work.f78 = work.p108.v;
            slot = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot + 0x1F4);
            table = cmbAddPtrRev((u32)slot, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot + 0x198) |= 8;
            *(s8 *)(slot + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot + 0x1F4), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 4) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0((u8 *)&work.vecF8, 0.0f, 5.0f, 30.0f);
        func_002b2a60(work.bytes + 0x3C,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C), &work.vecF8,
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      *(CmbRGBA *)(work.bytes + 0x3C), 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 4) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 4) {
                func_002b2970(&work.pF0.q, 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 = work.pF0.v;
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot);
                func_002b2970(&work.pE8.q, 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot,
                              *(CmbVec2f *)(ret + 0x134),
                              work.pE8.v, 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 4) {
            func_002b2a60(work.bytes + 0x34,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 4) =
                *(CmbRGBA *)(work.bytes + 0x34);
            func_002b2a60(work.bytes + 0x38,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 8) =
                *(CmbRGBA *)(work.bytes + 0x38);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 8);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 4);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_003427A0
s32 func_003427a0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb427Work work;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    s32 index3;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 ||
        *(s8 *)(obj + 0x21C) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 5) {
            func_002b2a60(work.bytes + 0x1A8,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x16C) =
                *(CmbRGBA *)(work.bytes + 0x1A8);
            func_002b2a60(work.bytes + 0x1AC,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x170) =
                *(CmbRGBA *)(work.bytes + 0x1AC);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x170);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x16C);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((s64 *)(work.bytes + 0x128), 185.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x68) =
                *(CmbVec2f *)(work.bytes + 0x128);
            func_002b2970((s64 *)(work.bytes + 0x130), -95.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x70) =
                *(CmbVec2f *)(work.bytes + 0x130);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) =
                *(CmbVec2f *)(work.bytes + 0x70);
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) =
                *(CmbVec2f *)(work.bytes + 0x68);
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 5;
            *(s8 *)(slot + 0xC) |= 1;
            func_002b2a60(work.bytes + 0x1A0,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x164) =
                *(CmbRGBA *)(work.bytes + 0x1A0);
            func_002b2a60(work.bytes + 0x1A4,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x168) =
                *(CmbRGBA *)(work.bytes + 0x1A4);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x168);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x164);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 5;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((s64 *)(work.bytes + 0x118), 185.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x58) =
                *(CmbVec2f *)(work.bytes + 0x118);
            func_002b2970((s64 *)(work.bytes + 0x120), -95.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x60) =
                *(CmbVec2f *)(work.bytes + 0x120);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) =
                *(CmbVec2f *)(work.bytes + 0x60);
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) =
                *(CmbVec2f *)(work.bytes + 0x58);
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 5;
            *(s8 *)(slot + 0x90) |= 1;
            func_002b2a60(work.bytes + 0x198,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x15C) =
                *(CmbRGBA *)(work.bytes + 0x198);
            func_002b2a60(work.bytes + 0x19C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x160) =
                *(CmbRGBA *)(work.bytes + 0x19C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                *(CmbRGBA *)(work.bytes + 0x160);
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                *(CmbRGBA *)(work.bytes + 0x15C);
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 5;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((s64 *)(work.bytes + 0x110), 465.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x50) =
                *(CmbVec2f *)(work.bytes + 0x110);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)(work.bytes + 0x50);
            *(s16 *)(table + 0xB8) = 5;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x100), 185.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x40) =
                *(CmbVec2f *)(work.bytes + 0x100);
            func_002b2970((s64 *)(work.bytes + 0x108), -95.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x48) =
                *(CmbVec2f *)(work.bytes + 0x108);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)(work.bytes + 0x48);
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)(work.bytes + 0x40);
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 5;
            *(s8 *)(slot + 0x114) |= 1;
            func_002b2a60(work.bytes + 0x190,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x154) =
                *(CmbRGBA *)(work.bytes + 0x190);
            func_002b2a60(work.bytes + 0x194,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x158) =
                *(CmbRGBA *)(work.bytes + 0x194);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                *(CmbRGBA *)(work.bytes + 0x158);
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                *(CmbRGBA *)(work.bytes + 0x154);
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 5;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xF8), 465.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x38) =
                *(CmbVec2f *)(work.bytes + 0xF8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)(work.bytes + 0x38);
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xF0), 239.0f, 343.0f);
            *(CmbVec2f *)(work.bytes + 0x30) =
                *(CmbVec2f *)(work.bytes + 0xF0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)(work.bytes + 0x30);
            *(s16 *)(table + 0x13C) = 5;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xE0), 185.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x20) =
                *(CmbVec2f *)(work.bytes + 0xE0);
            func_002b2970((s64 *)(work.bytes + 0xE8), -95.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x28) =
                *(CmbVec2f *)(work.bytes + 0xE8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)(work.bytes + 0x28);
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)(work.bytes + 0x20);
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 5;
            *(s8 *)(slot + 0x198) |= 1;
            func_002b2a60(work.bytes + 0x188,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x14C) =
                *(CmbRGBA *)(work.bytes + 0x188);
            func_002b2a60(work.bytes + 0x18C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x150) =
                *(CmbRGBA *)(work.bytes + 0x18C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                *(CmbRGBA *)(work.bytes + 0x150);
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                *(CmbRGBA *)(work.bytes + 0x14C);
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 5;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xD8), 465.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x18) =
                *(CmbVec2f *)(work.bytes + 0xD8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.bytes + 0x18);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xD0), 239.0f, 343.0f);
            *(CmbVec2f *)(work.bytes + 0x10) =
                *(CmbVec2f *)(work.bytes + 0xD0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.bytes + 0x10);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xC8), 411.0f, 343.0f);
            *(CmbVec2f *)(work.bytes + 0x8) =
                *(CmbVec2f *)(work.bytes + 0xC8);
            slot = *(u8 **)(arg0 + 0x38);
            index3 = *(s8 *)(slot + 0x1F4);
            table = cmbAddPtrRev((u32)slot, (u32)(index3 * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)(work.bytes + 0x8);
            *(s16 *)(table + 0x1C0) = 5;
            *(s8 *)(slot + 0x198) |= 8;
            *(s8 *)(slot + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xB8), 185.0f, 182.0f);
            *(CmbVec2f *)&work.f98 =
                *(CmbVec2f *)(work.bytes + 0xB8);
            func_002b2970((s64 *)(work.bytes + 0xC0), -95.0f, 182.0f);
            *(CmbVec2f *)(work.bytes + 0x0) =
                *(CmbVec2f *)(work.bytes + 0xC0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x230) =
                *(CmbVec2f *)(work.bytes + 0x0);
            *(CmbVec2f *)(slot + 0x220) =
                *(CmbVec2f *)(slot + 0x230);
            *(CmbVec2f *)(slot + 0x228) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(slot + 0x23A) = 0;
            *(s16 *)(slot + 0x238) = 5;
            *(s8 *)(slot + 0x21C) |= 1;
            func_002b2a60(work.bytes + 0x180,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x144) =
                *(CmbRGBA *)(work.bytes + 0x180);
            func_002b2a60(work.bytes + 0x184,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x148) =
                *(CmbRGBA *)(work.bytes + 0x184);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x294) =
                *(CmbRGBA *)(work.bytes + 0x148);
            *(CmbRGBA *)(slot + 0x28C) =
                *(CmbRGBA *)(slot + 0x294);
            *(CmbRGBA *)(slot + 0x290) =
                *(CmbRGBA *)(work.bytes + 0x144);
            *(s16 *)(slot + 0x298) = 0;
            *(s16 *)(slot + 0x29A) = 5;
            *(s8 *)(slot + 0x21C) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xB0), 465.0f, 182.0f);
            *(CmbVec2f *)&work.f90 =
                *(CmbVec2f *)(work.bytes + 0xB0);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xA8), 239.0f, 343.0f);
            *(CmbVec2f *)&work.f88 =
                *(CmbVec2f *)(work.bytes + 0xA8);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xA0), 411.0f, 343.0f);
            *(CmbVec2f *)&work.f80 =
                *(CmbVec2f *)(work.bytes + 0xA0);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x98), 325.0f, 83.0f);
            *(CmbVec2f *)&work.f78 =
                *(CmbVec2f *)(work.bytes + 0x98);
            slot = *(u8 **)(arg0 + 0x38);
            index2 = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index2 * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x244) = 5;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 5) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot2 = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot2 + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(work.bytes + 0x88, 0.0f, 5.0f, 30.0f);
        func_002b2a60(work.bytes + 0x17C,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(work.bytes + 0x88),
                      0.0f, 0.0f, 0.0f, iGpffff8360,
                      *(CmbRGBA *)(work.bytes + 0x17C), 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 5) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 5) {
                func_002b2970((s64 *)(work.bytes + 0x80), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 =
                    *(CmbVec2f *)(work.bytes + 0x80);
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((s64 *)(work.bytes + 0x78), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(work.bytes + 0x78), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 5) {
            func_002b2a60(work.bytes + 0x174,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x13C) =
                *(CmbRGBA *)(work.bytes + 0x174);
            func_002b2a60(work.bytes + 0x178,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x140) =
                *(CmbRGBA *)(work.bytes + 0x178);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x140);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x13C);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

// FUN_00343CF0
s32 func_00343cf0(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    Cmb43Work work;
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;

    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 ||
        *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 ||
        *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 6) {
            func_002b2a60(work.bytes + 0x178,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x134) =
                *(CmbRGBA *)(work.bytes + 0x178);
            func_002b2a60(work.bytes + 0x17C,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x138) =
                *(CmbRGBA *)(work.bytes + 0x17C);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x138);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x134);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i0 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i0++;
        }
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        return 0;
    }
    state = *(s16 *)(obj + 0x63C);
    switch (state) {
    case 0:
        if (func_00285b30() >= 0x50) {
            func_002b2970((s64 *)(work.bytes + 0xE8), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f140 =
                *(CmbVec2f *)(work.bytes + 0xE8);
            func_002b2970((s64 *)(work.bytes + 0xF0), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f148 =
                *(CmbVec2f *)(work.bytes + 0xF0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x20) =
                *(CmbVec2f *)&work.f148;
            *(CmbVec2f *)(slot + 0x10) =
                *(CmbVec2f *)(slot + 0x20);
            *(CmbVec2f *)(slot + 0x18) =
                *(CmbVec2f *)&work.f140;
            *(s16 *)(slot + 0x2A) = 0;
            *(s16 *)(slot + 0x28) = 4;
            *(s8 *)(slot + 0xC) |= 1;
            func_002b2a60(work.bytes + 0x170,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x12C) =
                *(CmbRGBA *)(work.bytes + 0x170);
            func_002b2a60(work.bytes + 0x174,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x130) =
                *(CmbRGBA *)(work.bytes + 0x174);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x130);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0x12C);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 4;
            *(s8 *)(slot + 0xC) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xD8), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f130 =
                *(CmbVec2f *)(work.bytes + 0xD8);
            func_002b2970((s64 *)(work.bytes + 0xE0), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f138 =
                *(CmbVec2f *)(work.bytes + 0xE0);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0xA4) =
                *(CmbVec2f *)&work.f138;
            *(CmbVec2f *)(slot + 0x94) =
                *(CmbVec2f *)(slot + 0xA4);
            *(CmbVec2f *)(slot + 0x9C) =
                *(CmbVec2f *)&work.f130;
            *(s16 *)(slot + 0xAE) = 0;
            *(s16 *)(slot + 0xAC) = 4;
            *(s8 *)(slot + 0x90) |= 1;
            func_002b2a60(work.bytes + 0x168,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x124) =
                *(CmbRGBA *)(work.bytes + 0x168);
            func_002b2a60(work.bytes + 0x16C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x128) =
                *(CmbRGBA *)(work.bytes + 0x16C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x108) =
                *(CmbRGBA *)(work.bytes + 0x128);
            *(CmbRGBA *)(slot + 0x100) =
                *(CmbRGBA *)(slot + 0x108);
            *(CmbRGBA *)(slot + 0x104) =
                *(CmbRGBA *)(work.bytes + 0x124);
            *(s16 *)(slot + 0x10C) = 0;
            *(s16 *)(slot + 0x10E) = 4;
            *(s8 *)(slot + 0x90) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xD0), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f128 =
                *(CmbVec2f *)(work.bytes + 0xD0);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0xEC);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0xB0) =
                *(CmbVec2f *)&work.f128;
            *(s16 *)(table + 0xB8) = 4;
            *(s8 *)(slot + 0x90) |= 8;
            *(s8 *)(slot + 0xEC) =
                func_002b2cb0(*(s8 *)(slot + 0xEC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xC0), 321.0f, 70.0f);
            *(CmbVec2f *)&work.f118 =
                *(CmbVec2f *)(work.bytes + 0xC0);
            func_002b2970((s64 *)(work.bytes + 0xC8), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f120 =
                *(CmbVec2f *)(work.bytes + 0xC8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x128) =
                *(CmbVec2f *)&work.f120;
            *(CmbVec2f *)(slot + 0x118) =
                *(CmbVec2f *)(slot + 0x128);
            *(CmbVec2f *)(slot + 0x120) =
                *(CmbVec2f *)&work.f118;
            *(s16 *)(slot + 0x132) = 0;
            *(s16 *)(slot + 0x130) = 4;
            *(s8 *)(slot + 0x114) |= 1;
            func_002b2a60(work.bytes + 0x160,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x11C) =
                *(CmbRGBA *)(work.bytes + 0x160);
            func_002b2a60(work.bytes + 0x164,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x120) =
                *(CmbRGBA *)(work.bytes + 0x164);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x18C) =
                *(CmbRGBA *)(work.bytes + 0x120);
            *(CmbRGBA *)(slot + 0x184) =
                *(CmbRGBA *)(slot + 0x18C);
            *(CmbRGBA *)(slot + 0x188) =
                *(CmbRGBA *)(work.bytes + 0x11C);
            *(s16 *)(slot + 0x190) = 0;
            *(s16 *)(slot + 0x192) = 4;
            *(s8 *)(slot + 0x114) |= 4;
            func_002b2970((s64 *)(work.bytes + 0xB8), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f110 =
                *(CmbVec2f *)(work.bytes + 0xB8);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f110;
            *(s16 *)(table + 0x13C) = 4;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xB0), 186.0f, 285.0f);
            *(CmbVec2f *)&work.f108 =
                *(CmbVec2f *)(work.bytes + 0xB0);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x170);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x134) =
                *(CmbVec2f *)&work.f108;
            *(s16 *)(table + 0x13C) = 4;
            *(s8 *)(slot2 + 0x114) |= 8;
            *(s8 *)(slot2 + 0x170) =
                func_002b2cb0(*(s8 *)(slot2 + 0x170), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0xA0), 321.0f, 70.0f);
            *(CmbVec2f *)&work.ff8 =
                *(CmbVec2f *)(work.bytes + 0xA0);
            func_002b2970((s64 *)(work.bytes + 0xA8), 421.0f, -43.0f);
            *(CmbVec2f *)&work.f100 =
                *(CmbVec2f *)(work.bytes + 0xA8);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x1AC) =
                *(CmbVec2f *)&work.f100;
            *(CmbVec2f *)(slot + 0x19C) =
                *(CmbVec2f *)(slot + 0x1AC);
            *(CmbVec2f *)(slot + 0x1A4) =
                *(CmbVec2f *)&work.ff8;
            *(s16 *)(slot + 0x1B6) = 0;
            *(s16 *)(slot + 0x1B4) = 4;
            *(s8 *)(slot + 0x198) |= 1;
            func_002b2a60(work.bytes + 0x158,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x114) =
                *(CmbRGBA *)(work.bytes + 0x158);
            func_002b2a60(work.bytes + 0x15C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x118) =
                *(CmbRGBA *)(work.bytes + 0x15C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x210) =
                *(CmbRGBA *)(work.bytes + 0x118);
            *(CmbRGBA *)(slot + 0x208) =
                *(CmbRGBA *)(slot + 0x210);
            *(CmbRGBA *)(slot + 0x20C) =
                *(CmbRGBA *)(work.bytes + 0x114);
            *(s16 *)(slot + 0x214) = 0;
            *(s16 *)(slot + 0x216) = 4;
            *(s8 *)(slot + 0x198) |= 4;
            func_002b2970((s64 *)(work.bytes + 0x98), 186.0f, 143.0f);
            *(CmbVec2f *)&work.ff0 =
                *(CmbVec2f *)(work.bytes + 0x98);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.ff0;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x90), 186.0f, 285.0f);
            *(CmbVec2f *)&work.fe8 =
                *(CmbVec2f *)(work.bytes + 0x90);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.fe8;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x88), 321.0f, 348.0f);
            *(CmbVec2f *)&work.fe0 =
                *(CmbVec2f *)(work.bytes + 0x88);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x1F4);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x1B8) =
                *(CmbVec2f *)&work.fe0;
            *(s16 *)(table + 0x1C0) = 4;
            *(s8 *)(slot2 + 0x198) |= 8;
            *(s8 *)(slot2 + 0x1F4) =
                func_002b2cb0(*(s8 *)(slot2 + 0x1F4), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x78), 321.0f, 70.0f);
            *(CmbVec2f *)&work.fd0 =
                *(CmbVec2f *)(work.bytes + 0x78);
            func_002b2970((s64 *)(work.bytes + 0x80), 421.0f, -43.0f);
            *(CmbVec2f *)&work.fd8 =
                *(CmbVec2f *)(work.bytes + 0x80);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x230) =
                *(CmbVec2f *)&work.fd8;
            *(CmbVec2f *)(slot + 0x220) =
                *(CmbVec2f *)(slot + 0x230);
            *(CmbVec2f *)(slot + 0x228) =
                *(CmbVec2f *)&work.fd0;
            *(s16 *)(slot + 0x23A) = 0;
            *(s16 *)(slot + 0x238) = 4;
            *(s8 *)(slot + 0x21C) |= 1;
            func_002b2a60(work.bytes + 0x150,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x10C) =
                *(CmbRGBA *)(work.bytes + 0x150);
            func_002b2a60(work.bytes + 0x154,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x110) =
                *(CmbRGBA *)(work.bytes + 0x154);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x294) =
                *(CmbRGBA *)(work.bytes + 0x110);
            *(CmbRGBA *)(slot + 0x28C) =
                *(CmbRGBA *)(slot + 0x294);
            *(CmbRGBA *)(slot + 0x290) =
                *(CmbRGBA *)(work.bytes + 0x10C);
            *(s16 *)(slot + 0x298) = 0;
            *(s16 *)(slot + 0x29A) = 4;
            *(s8 *)(slot + 0x21C) |= 4;
            func_002b2970((s64 *)(work.bytes + 0x70), 186.0f, 143.0f);
            *(CmbVec2f *)&work.fc8 =
                *(CmbVec2f *)(work.bytes + 0x70);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fc8;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x68), 186.0f, 285.0f);
            *(CmbVec2f *)&work.fc0 =
                *(CmbVec2f *)(work.bytes + 0x68);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fc0;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x60), 321.0f, 348.0f);
            *(CmbVec2f *)&work.fb8 =
                *(CmbVec2f *)(work.bytes + 0x60);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fb8;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x58), 456.0f, 285.0f);
            *(CmbVec2f *)&work.fb0 =
                *(CmbVec2f *)(work.bytes + 0x58);
            slot = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot + 0x278);
            table = cmbAddPtrRev((u32)slot, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x23C) =
                *(CmbVec2f *)&work.fb0;
            *(s16 *)(table + 0x244) = 4;
            *(s8 *)(slot + 0x21C) |= 8;
            *(s8 *)(slot + 0x278) =
                func_002b2cb0(*(s8 *)(slot + 0x278), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x48), 321.0f, 70.0f);
            *(CmbVec2f *)&work.fa0 =
                *(CmbVec2f *)(work.bytes + 0x48);
            func_002b2970((s64 *)(work.bytes + 0x50), 421.0f, -43.0f);
            *(CmbVec2f *)&work.fa8 =
                *(CmbVec2f *)(work.bytes + 0x50);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbVec2f *)(slot + 0x2B4) =
                *(CmbVec2f *)&work.fa8;
            *(CmbVec2f *)(slot + 0x2A4) =
                *(CmbVec2f *)(slot + 0x2B4);
            *(CmbVec2f *)(slot + 0x2AC) =
                *(CmbVec2f *)&work.fa0;
            *(s16 *)(slot + 0x2BE) = 0;
            *(s16 *)(slot + 0x2BC) = 4;
            *(s8 *)(slot + 0x2A0) |= 1;
            func_002b2a60(work.bytes + 0x148,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x104) =
                *(CmbRGBA *)(work.bytes + 0x148);
            func_002b2a60(work.bytes + 0x14C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0x108) =
                *(CmbRGBA *)(work.bytes + 0x14C);
            slot = *(u8 **)(arg0 + 0x38);
            *(CmbRGBA *)(slot + 0x318) =
                *(CmbRGBA *)(work.bytes + 0x108);
            *(CmbRGBA *)(slot + 0x310) =
                *(CmbRGBA *)(slot + 0x318);
            *(CmbRGBA *)(slot + 0x314) =
                *(CmbRGBA *)(work.bytes + 0x104);
            *(s16 *)(slot + 0x31C) = 0;
            *(s16 *)(slot + 0x31E) = 4;
            *(s8 *)(slot + 0x2A0) |= 4;
            func_002b2970((s64 *)(work.bytes + 0x40), 186.0f, 143.0f);
            *(CmbVec2f *)&work.f98 =
                *(CmbVec2f *)(work.bytes + 0x40);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f98;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x38), 186.0f, 285.0f);
            *(CmbVec2f *)&work.f90 =
                *(CmbVec2f *)(work.bytes + 0x38);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f90;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x30), 321.0f, 348.0f);
            *(CmbVec2f *)&work.f88 =
                *(CmbVec2f *)(work.bytes + 0x30);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f88;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x28), 456.0f, 285.0f);
            *(CmbVec2f *)&work.f80 =
                *(CmbVec2f *)(work.bytes + 0x28);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f80;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            func_002b2970((s64 *)(work.bytes + 0x20), 456.0f, 143.0f);
            *(CmbVec2f *)&work.f78 =
                *(CmbVec2f *)(work.bytes + 0x20);
            slot2 = *(u8 **)(arg0 + 0x38);
            index = *(s8 *)(slot2 + 0x2FC);
            table = cmbAddPtrRev((u32)slot2, (u32)(index * 0xC));
            *(CmbVec2f *)(table + 0x2C0) =
                *(CmbVec2f *)&work.f78;
            *(s16 *)(table + 0x2C8) = 4;
            *(s8 *)(slot2 + 0x2A0) |= 8;
            *(s8 *)(slot2 + 0x2FC) =
                func_002b2cb0(*(s8 *)(slot2 + 0x2FC), 1, 5, 0, 1);
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 6) {
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i6 * 0x84;
                *(s32 *)(slot + 0x74) = 0;
                *(s32 *)(slot + 0x6C) = 0;
                *(s32 *)(slot + 0x70) = (s32)0xC3340000;
                *(s16 *)(slot + 0x78) = 0;
                *(s16 *)(slot + 0x7A) = 3;
                *(s8 *)(slot + 0xC) |= 2;
                table6 = obj + (s32)i6 * 4;
                slot2 = obj + (s32)i6 * 0x84;
                table = table6 + 0x658;
                fvalue = *(f32 *)(slot2 + 0x20) + 16.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(work.bytes + 0x10, 0.0f, 5.0f, 30.0f);
        func_002b2a60(work.bytes + 0x144,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_003489c0(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(work.bytes + 0x10),
                      0.0f, 0.0f, 0.0f, 1.5f,
                      *(CmbRGBA *)(work.bytes + 0x144), 0, 0x28);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 6) {
                table = obj + (s32)i8 * 4;
                ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
                *(s32 *)(ret + 0x11C) |= 2;
                i8++;
            }
            *(s16 *)(obj + 0x63C) = 9;
        }
        break;
    case 9:
        if (func_00285b30() >= 0x1EA) {
            i9 = 0;
            while (i9 < 6) {
                func_002b2970((s64 *)(work.bytes + 0x8), 323.0f, 217.0f);
                *(CmbVec2f *)&work.f70 =
                    *(CmbVec2f *)(work.bytes + 0x8);
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&work.f70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((s64 *)(work.bytes + 0x0), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(work.bytes + 0x0), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 6) {
            func_002b2a60(work.bytes + 0x13C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(work.bytes + 0xFC) =
                *(CmbRGBA *)(work.bytes + 0x13C);
            func_002b2a60(work.bytes + 0x140,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(work.bytes + 0x100) =
                *(CmbRGBA *)(work.bytes + 0x140);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(work.bytes + 0x100);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(work.bytes + 0xFC);
            *(s16 *)(slot + 0x88) = 0;
            *(s16 *)(slot + 0x8A) = 0;
            *(s8 *)(slot + 0xC) |= 4;
            table = obj + (s32)i10 * 4;
            ret = (u8 *)func_00348290(*(u8 **)(table + 0x658));
            *(s32 *)(ret + 0x11C) &= 0xFFFD;
            i10++;
        }
        *(s16 *)(obj + 0x63C) = 11;
        break;
    case 11:
        if (func_00285b30() >= 0x208 &&
            func_00285b30() < 0x348) {
            func_00106390(0x1450, 1);
        }
        break;
    case 12:
        *(s8 *)obj += 1;
        break;
    }
    return 1;
}

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
   the or-result register never moves; (2) mwcc b210 places the loop-invariant
   `lui %hi(D_008872F8)` INSIDE the loop body (direct array spelling) or emits
   lui+addiu at entry (pointer local) — retail hoists a lui-ONLY base into $v0 at
   entry with %lo folded into the lwc1; no spelling reproduces the 1-word hoist.
   Recipe A cracked the doubled-alpha CFG; the or-register coloring + lui hoist
   remain compiler floors (same family as func_0024f160 / mdlManager conv-CFG).
   Re-measured this wave: two fresh full-body reconstructions (m2c-based 426,
   FMA-idiom zero+base-f3*mul block with s8-doubled-alpha per the inline-pointer-
   out skill 433) BOTH landed well above the recorded 263 — the exact recipe-A
   body is not recoverable from the truncated note + m2c draft (the adda.s/msub.s/
   madd.s accumulator block and the lui-only D_008872F8 hoist are the structural
   crux). 263 remains the measured best; not re-pursued to window-exactness. */
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
   a saved reg and rotates obj to $s1. All verified against this function's retail.
   Re-measured this wave: two fresh m2c-draft-based reconstructions (285, then the
   same with 3-way if/else-if dispatch + indexed D_005DC7D0, 279) both far above
   the recorded 16 — the exact winning recipe is not recoverable from the
   truncated note; confirmed func_004553c0 takes ONE arg (the m2c draft's 2nd arg
   is wrong), and the gated conversion needs the explicit `2.1474836e9f > f0`
   guard to keep the c.ole.s/bc1t + per-arm andi. 16 remains the measured best. */
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
void func_003489c0(u8 *arg0, CmbVec3f *src, f32 f0, f32 f1, f32 f2, f32 f3, CmbRGBA col, u16 arg3, u32 arg4) {
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
