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
typedef struct { s64 lo; s64 hi; } Cmb48V16;
typedef struct {
    Cmb48V16 v80;
    Cmb48V16 v90;
    Cmb48V16 vA0;
    Cmb48V16 vB0;
    Cmb48V16 vC0;
    Cmb48V16 vD0;
    Cmb48V16 vE0;
    Cmb48V16 vF0;
    Cmb48V16 v100;
    Cmb48V16 v110;
    Cmb48V16 v120;
    s64 s130;
    s64 s138;
    s64 s140;
    s64 s148;
    s64 s150;
    s64 s158;
    s64 s160;
    s64 s168;
    s64 s170;
    s64 s178;
    s64 s180;
    s64 s188;
    u32 pad190;
    u32 c194;
    u32 c198;
    u32 c19C;
} Cmb48Work;

static inline u8 *cmbAddPtrRev(u32 base, u32 index) { return (u8 *)(index + base); }

void func_0044ea90(void *arg0, u32 arg1);
s32 func_00451fc0(u8 *arg0, const void *arg1, u32 arg2, u32 arg3, u32 arg4, void (*arg5)(u8 *), void (*arg6)(u8 *), void *arg7);
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
void func_00348a90(u8 *arg0, CmbVec3f *src1, CmbRGBA arg2, u16 arg3, u32 arg4, CmbVec3f *src2, CmbRGBA arg6, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7);
void func_002b2a60(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
s32 *func_00331620(void);
void func_003f6440(u32 arg0, u32 arg1);
void func_003dc740(void *arg0, void *arg1, u32 arg2);
void func_0036de20(void *arg0, void *arg1);
void func_0036dd10(void *arg0, void *arg1, f32 arg2);
s32 func_00285b30(void);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
s32 func_002b2cb0(s32, s32, s32, s32, s32);
u8 *func_00457120(void);
u8 *func_00461390(void *a, s32 b, void *c, s32 d);
extern f32 iGpffff8360;
extern f32 iGpffff8508;
extern f32 iGpffff850c;
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
extern void *(*D_008873F4[])(size_t, size_t, u32);
s32 func_0033e810(u8 *arg0);
s32 func_0033e5c0(u8 *arg0);
u8 *func_003488d0(u8 *arg0, u8 *arg1, s8 arg2);
extern u32 D_00763A28;
extern s64 D_0064A5A0[];
extern f32 D_0064A5A8[];
extern void (*D_00887300[])(s32, s32);



/* Floor: 36 differing words (reloc-masked), obj 500B/window 512B, 125/125 instrs,
   33 fnalign edits plus 5 reloc-only. Body is
   docs/probe_archive/HOFTRY55_0033e5c0_body.c verbatim (direct-pointer form).
   The entire residual is register color plus one scheduler swap: retail holds the
   state pointer in $s1, this build in $s0; full map retail q=$s0/obj=$s1/i=$s2/p=$s3
   vs build obj=$s0/i=$s1/q=$s2/p=$s3, and the loop body's q and p address
   computations are swapped (build p-then-q with the disp-0 reload after the ori,
   retail q-then-p with the ori first and the reload last). Exhausted: six
   declaration permutations (all 36); two named-slot-pointer variants (both 58,
   reproduced this pass); value-side q-last q-before-p, q-last q-after-p,
   block-scope q, and s8-obj spellings (all 36); opt_propagation off REGRESSED to
   49. Semantic gate: s32 return (retail daddu $2,$0), s8 increments (signed lb),
   gp-relative `&iGpffffa938` first call arg; every call uses the file-scope
   prototypes, no block-scope prototype changes. Production stays ASM. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/y_CmbCardEff.c func_0033e5c0 --pairs` banked 36; best ties 36 (opt_dead_assignments off, opt_loop_invariants on, opt_propagation off, opt_strength_reduction off, opt_unroll_loops off and nine pairwise combos among them); all 28 pairs neutral or worse (schedule 105-110, commons 114-122, peephole 110-122). opclass `python3 -E -s tools/opclass.py src/promoted/y_CmbCardEff.c`: 3 floors scanned, 1 with surplus (00348c40), func_0033e5c0 clean — high 36-word count on small 125/125-instr body is register color + scheduler swap per above, not a whole-function width/signedness defect. Floor stands; production stays ASM. */
// FUN_0033E5C0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0033e5c0(u8 *arg0) {
    u8 *p;
    s16 i;
    u8 *obj;
    s8 type;

    obj = *(u8 **)(arg0 + 0x38);
    type = *(s8 *)obj;
    if (type != 4) {
        switch (type) {
        case 0:
            func_0036d860(obj + 0x20, 0);
            func_00440b68(&iGpffffa938, D_0064A4A0, 0x63);
            *(u8 **)(obj + 0x1C) = (u8 *)func_00454a60(D_0064E590, 0);
            *(s8 *)obj += 1;
            break;
        case 1:
            if (func_004553c0(*(u8 **)(obj + 0x1C)) != 0) {
                func_0036d230(*(u32 *)(*(u8 **)(obj + 0x1C) + 0x110));
                func_00454bd0(*(u8 **)(obj + 0x1C));
                *(s8 *)obj += 1;
            }
            break;
        case 2:
            for (i = 0; i < 0xC; i++) {
                if (*(u16 *)(obj + (s32)i * 2 + 2) == 0)
                    goto next_card;
                p = obj + (s32)i * 0xFB0;
                func_0036da40(p + 0x2758,
                              *(u16 *)(obj + (s32)i * 2 + 2));
                func_0036da40(p + 0xE398,
                              *(u16 *)(obj + (s32)i * 2 + 2));
                *(s8 *)(obj + 0x19FD8) += 1;
            next_card:
                ;
            }
            *(s8 *)obj += 1;
            break;
        case 3:
            if (func_0036d960() != 0) {
                *(s8 *)obj += 1;
            }
            break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033e5c0);
#endif
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
/* measured: cold reconstruction banked 806 (reloc-masked), retail 912 instrs / object 896 instrs (1.8% inside 3% gate), 166 fnalign edits +6 reloc-only. v1 817 (912/804, 11.8% short: hoisted slot/c, shared rgba, plain 0xFB0) -> v3 810 (912/895, 1.9%: unhoisted per-use obj+k*0x84 and (s8)k, separate rgba0/rgba1, block-scope true protos for 4-arg 003dc740 and 3-arg 0033fa30, D_00794E70/EA0 and D_0064A4C8/D_0064A4D0 externs) -> v3_loopinv 806 (912/896) with #pragma opt_loop_invariants on. Pragmas: commons off 1256 regress, unroll off 810 tie, schedule off 810 tie. Colour: register obj 806 tie, reversed decl order 806 tie. Residual: stack-alloc (frame -0x160 vs -0x170, sp 0x138->0x158, 0x154->0x16C), saved-reg rotation (s2/s3, s1/s2), RGBA lbu/sb interleave vs pairs, D_0064A4C8/D0 lui+ld/lwc1 vs gp ld. m2c plus romwright base, CmbVec2f by-value for 0033fc00 per prior note. */
/* 2026-09-18 `tools/solve_signedness.py`: the read at `obj + k*0x84 + 0xC`
   was `u8` where retail loads it signed; flipping it took the census
   mismatch from 21 to 7 with the instruction count unchanged.  The word
   score stays 806 because those positions already differ for other reasons -
   the census is the objective for signedness, not the score.  Two tables,
   D_00794E70 and D_00794EA0, are free: both spellings compile identically,
   so their signedness is unobservable here and should not be churned. */
// FUN_0033E810 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_0033e810(u8 *arg0) {
    void func_0033fa30(u8 *, s8, f32);
    void func_0033fb10(u8 *, s8, s64);
    void func_0033fb90(u8 *, s8, s64, f32);
    void func_0033fc00(u8 *, s8, CmbVec2f, CmbVec2f, u16);
    s32 func_0033fc80(u8 *);
    s32 func_003407f0(u8 *);
    s32 func_00341640(u8 *);
    s32 func_003427a0(u8 *);
    s32 func_00343cf0(u8 *);
    void func_00347940(u8 *);
    s32 func_00348be0(u8 *);
    void func_0036de20(void *, void *);
    void func_0036de40(void *, void *);
    void func_0036df90(void *, void *);
    void func_003dc740(void *, void *, u32, f32);
    extern s64 D_0064A4C8;
    extern f32 D_0064A4D0;
    extern u8 D_00794E70[];
    extern u8 D_00794EA0[];
    u8 *obj;
    s16 i;
    s16 j;
    s16 k;
    s64 tmp;
    u8 rgba0[4];
    u8 cpy0[4];
    u8 rgba1[4];
    u8 cpy1[4];
    s64 st64;
    f32 stf;
    u8 buf[24];
    u8 cv;
    f32 f0;
    f32 f20save;
    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(*(u8 **)(obj + 4) + 0x38) != 4) {
        return 0;
    }
    if (func_00285b30() >= 1000 && func_00285b30() < 1011) {
        func_00106390(0x5C, 0);
    }
    switch (*(s8 *)obj) {
    case 0:
        if (func_00348be0(*(u8 **)(obj + 0x64C)) == 0) {
            return 0;
        }
        for (i = 0; i < *(s8 *)(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + 0x19FD8); i++) {
            func_002b2970(&tmp, 0.0f, 0.0f);
            func_0033fb10(arg0, (s8)i, tmp);
            func_0033fa30(arg0, (s8)i, 0.0f);
            func_002b2a60(rgba0, 0xFF, 0xFF, 0xFF, 0);
            cpy0[0] = rgba0[0];
            cpy0[1] = rgba0[1];
            cpy0[2] = rgba0[2];
            cpy0[3] = rgba0[3];
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)i * 0xFB0 + 0xE398, cpy0);
            *(f32 *)(obj + (s32)i * 0x84 + 0x8C) = 1.0f;
            st64 = D_0064A4C8;
            stf = D_0064A4D0;
            func_003dc740(buf, &st64, 0, 180.0f);
            func_0036de20(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)i * 0xFB0 + 0xE398, buf);
        }
        *(s16 *)(obj + 0x63C) = 0;
        *obj = *(obj + 0x63E);
        func_00347940(arg0);
        break;
    case 1:
        func_0033fc80(arg0);
        break;
    case 2:
        func_003407f0(arg0);
        break;
    case 3:
        func_00341640(arg0);
        break;
    case 4:
        func_003427a0(arg0);
        break;
    case 5:
        func_00343cf0(arg0);
        break;
    case 6:
        for (j = 0; j < *(s8 *)(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + 0x19FD8); j++) {
            *(f32 *)(obj + (s32)j * 0x84 + 0x8C) = 0.75f;
        }
        func_00345700(arg0);
        break;
    case 7:
        return -1;
    }
    if (*(s16 *)(obj + 0x63C) == 9 && func_00285b30() < 490) {
        f20save = func_002b2aa0(0, *(f32 *)(obj + 0x8C), *(f32 *)(obj + 0x8C) + 0.125f, (f32)*(s16 *)(obj + 0x6BC), 60.0f);
        f0 = func_002b2aa0(1, 0.0f, 168.0f, (f32)*(s16 *)(obj + 0x6BC), 30.0f);
        cv = (u8)(s32)f0;
        *(s16 *)(obj + 0x6BC) = func_002b2cb0(*(s16 *)(obj + 0x6BC), 1, 60, 0, 2);
    }
    for (k = 0; k < *(s8 *)(obj + 0x6B9); k++) {
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 1) != 0) {
            *(f32 *)(obj + (s32)k * 0x84 + 0x20) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x10), *(f32 *)(obj + (s32)k * 0x84 + 0x18), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
            *(f32 *)(obj + (s32)k * 0x84 + 0x24) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x14), *(f32 *)(obj + (s32)k * 0x84 + 0x1C), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x2A) < *(s16 *)(obj + (s32)k * 0x84 + 0x28)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x2A) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x2A), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x28), 0, 1);
            } else if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 8) == 0) {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 1;
            } else {
                func_0033fc00(arg0, (s8)k, *(CmbVec2f *)(obj + (s32)k * 0x84 + 0x20), *(CmbVec2f *)(obj + (s32)*(s8 *)(obj + (s32)k * 0x84 + 0x69) * 0xC + (s32)k * 0x84 + 0x2C), *(u16 *)(obj + (s32)*(s8 *)(obj + (s32)k * 0x84 + 0x69) * 0xC + (s32)k * 0x84 + 0x34));
                *(f32 *)(obj + (s32)k * 0x84 + 0x20) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x10), *(f32 *)(obj + (s32)k * 0x84 + 0x18), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
                *(f32 *)(obj + (s32)k * 0x84 + 0x24) = func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x14), *(f32 *)(obj + (s32)k * 0x84 + 0x1C), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x2A), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x28));
                *(s16 *)(obj + (s32)k * 0x84 + 0x2A) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x2A), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x28), 0, 1);
                *(s8 *)(obj + (s32)k * 0x84 + 0x69) += 1;
                if (*(s8 *)(obj + (s32)k * 0x84 + 0x68) <= *(s8 *)(obj + (s32)k * 0x84 + 0x69)) {
                    *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 8;
                }
            }
        }
        func_0033fb10(arg0, (s8)k, *(s64 *)(obj + (s32)k * 0x84 + 0x20));
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 2) != 0) {
            *(f32 *)(obj + (s32)k * 0x84 + 0x74) = (f32)(s16)(s32)func_002b2aa0(0, *(f32 *)(obj + (s32)k * 0x84 + 0x6C), *(f32 *)(obj + (s32)k * 0x84 + 0x70), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x78), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x7A));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x78) < *(s16 *)(obj + (s32)k * 0x84 + 0x7A)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x78) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x78), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x7A), 0, 1);
            } else {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 2;
            }
            func_0033fa30(arg0, (s8)k, *(f32 *)(obj + (s32)k * 0x84 + 0x74));
        }
        if ((*(s8 *)(obj + (s32)k * 0x84 + 0xC) & 4) != 0) {
            *(u8 *)(obj + (s32)k * 0x84 + 0x84) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7C), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x80), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x85) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7D), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x81), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x86) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7E), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x82), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            *(u8 *)(obj + (s32)k * 0x84 + 0x87) = (u8)func_002b2aa0(0, (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x7F), (f32)*(u8 *)(obj + (s32)k * 0x84 + 0x83), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x88), (f32)*(s16 *)(obj + (s32)k * 0x84 + 0x8A));
            if (*(s16 *)(obj + (s32)k * 0x84 + 0x88) < *(s16 *)(obj + (s32)k * 0x84 + 0x8A)) {
                *(s16 *)(obj + (s32)k * 0x84 + 0x88) = func_002b2cb0(*(s16 *)(obj + (s32)k * 0x84 + 0x88), 1, *(s16 *)(obj + (s32)k * 0x84 + 0x8A), 0, 1);
            } else {
                *(s8 *)(obj + (s32)k * 0x84 + 0xC) ^= 4;
            }
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0x2758, obj + (s32)k * 0x84 + 0x84);
        }
        if (*(u8 *)(obj + (s32)k * 0x84 + 0x87) != 0 && *(obj + 0x6B8) == 0) {
            func_0036df90(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0x2758, D_00794E70);
        }
        if (*(s16 *)(obj + 0x63C) == 9 && func_00285b30() < 490 && *(obj + 0x6B8) == 0) {
            func_0033fb90(arg0, (s8)k, *(s64 *)(obj + (s32)k * 0x84 + 0x20), f20save);
            func_002b2a60(rgba1, 0xFF, 0xFF, 0xFF, cv);
            cpy1[0] = rgba1[0];
            cpy1[1] = rgba1[1];
            cpy1[2] = rgba1[2];
            cpy1[3] = rgba1[3];
            func_0036de40(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0xE398, cpy1);
            func_0036df90(*(u8 **)(*(u8 **)(obj + 4) + 0x38) + (s32)(s8)k * 0xFB0 + 0xE398, D_00794EA0);
        }
    }
    return 0;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_0033e810);
#endif

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

/* cold target: faithful v4 (759 lines, file idioms s8/lb s16/switch s32/daddu, file-scope protos incl. new 00348a90 + iGpffff8508/850c, 104 jal/0 jalr exact, 0 unsigned (0 bltz) / 14 signed int->float via 0x141/0x143/0x153/0x16B/0x187 bare mtc1/cvt) probes 1911 differing words (reloc-masked; skeleton v1 2031), fnalign retail 2190/object 2038 (152 short, 6.9%, band 2126-2258), 997 edits +2 reloc-only, frame retail -0x3D0 vs object -0x6D0, no large pure hole/lump (52 deletes max 4-5, 1 insert; e.g. retail[198:202] 0x00345A18-0x00345A28, retail[209:213] 0x00345A44-0x00345A54, retail[302:306] 0x00345BB8-0x00345BC8). Exact: python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00345700 --candidate v4=/tmp/cmb45700_v4.c (1911); python3 tools/fnalign.py src/promoted/y_CmbCardEff.c func_00345700 --candidate /tmp/cmb45700_v4.c (2190/2038, 997+2, -0x3D0/-0x6D0). Production stays INCLUDE_ASM (short, do not bank). */
// checked per Main: read retail at all fourteen int->float sites first -- retail has 0 bltz, 85 mtc1, 14 cvt.s.w (bare signed); object v4 has 0 bltz, 85 mtc1, 14 cvt.s.w (identical); all fourteen genuinely signed, fix 0, count stays 2038/2190 -152 -6.9% outside 2126-2258 (applying (f32)(u32) would invent 14x11=154 bltz retail lacks, fake exact 2192 with worse words per 7u, rejected); frame preserved: object -0x6D0 vs retail -0x3D0 (+768 surplus, big buffers held where retail computes in place, attack after conversions, same story); production stays INCLUDE_ASM.
/* measured: rule 1 applies verbatim (same clone site as func_0033fc80): the single */
/* ldr $a1,0x134/ldl $a1,0x13B pair is `func_003482d0(slot, *(CmbVec2f *)(ret + 0x134), v, 3)` */
/* with ret = func_00348290 result — 8-byte by-value read at 4-mod-8 offset, verified */
/* emitting the exact pair on func_0033fc80. Not re-attempted individually: the whole */
/* 0x84-stride state-machine family shares func_0033fc80's stack-alloc floor. */
// v5 aggregate-removal alone (2026-09-19): v4->v5 retail 2190/object 2038->2038 (+0, still 152 short, 6.9%, outside band 2126-2258; predicted +162 via 50x lwc1 reappearing did NOT materialize), frame -0x6D0->-0x410 (1744->1040, -704, still +64 over retail -0x3D0=976; added 920 vs 864 target +56), words 1911->1911 (+0), edits 997->1009 (+12), jal 104/0 exact, 0 bltz; exact: python3 tools/fnalign.py src/promoted/y_CmbCardEff.c func_00345700 --candidate /tmp/cmb45700_v5.c --quiet + python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00345700 --candidate v5=/tmp/cmb45700_v5.c; residual 49 pure deletes (max 14 at retail[211:225] 0x00345A4C-0x00345A84, e.g. retail[198:202] 0x00345A18-0x00345A28, retail[302:306] 0x00345BB8-0x00345BC8), 1 real insert + tail, no large hole/lump (>=25); production stays INCLUDE_ASM (short, do not bank).
// storage shape, not arithmetic: retail spills each func_002b2970 scratch result to a low stack slot as it goes (e.g. 0x2D8->0x188, 0x2E0->0x190, 50 sites of 8-byte lwc1/lwc1/swc1/swc1 with varying indices, sequential distinct), where v4/v5 keep one big buffer (Cmb43Work + twork, +768 frame); retail uses a rolling pair of small slots and copies out -- fix is storage shape (smaller slots + per-result copies, +162 to 2200) not conversions (all fourteen genuinely signed, 0 changed).
/* measured 00345700 (owner, 2026-09-19): the storage-shape hypothesis in the note above is
   **disproved at this granularity**.  All 36 `func_002b2970` scratch destinations in the
   0x210-byte `ttmp` buffer are written once and read exactly twice, so each was replaced
   with its own `CmbVec2f` local - 36 separate two-float objects instead of disjoint slices
   of one array.  Result: object 2138 and 1141 fnalign edits, **identical to the buffer
   form**.  MWCC already treats provably disjoint slices of a local array as separate
   values, so splitting them changes nothing.  If retail's low stack offsets are still the
   answer, the difference has to come from the *order* the slots are allocated in or from
   the other 229 `ttmp` offsets, not from the 36 scratch pairs. */
// FUN_00345700 NONMATCHING
#ifdef NON_MATCHING
s32 func_00345700(u8 *arg0) {
    u8 *ret;
    u8 *table;
    u8 *table6;
    u8 *slot;
    u8 *slot2;
    u8 *obj;
    u8 ttmp[0x210];
    u8 workB[0x180];
    CmbVec2f workF70;
    CmbVec2f flow[37];
    s16 state;
    s8 i0;
    s8 i6;
    s8 i8;
    s8 i9;
    s8 i10;
    s32 index;
    s32 index2;
    f32 fvalue;
    s32 tmpI;
    obj = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(obj + 0xC) != 0 || *(s8 *)(obj + 0x90) != 0 || *(s8 *)(obj + 0x114) != 0 || *(s8 *)(obj + 0x198) != 0 || *(s8 *)(obj + 0x21C) != 0 || *(s8 *)(obj + 0x2A0) != 0 || *(s8 *)(obj + 0x324) != 0 || *(s8 *)(obj + 0x3A8) != 0 || *(s8 *)(obj + 0x42C) != 0 || *(s8 *)(obj + 0x4B0) != 0 || *(s8 *)(obj + 0x534) != 0 || *(s8 *)(obj + 0x5B8) != 0) {
        return 0;
    }
    if (func_00106330(0x58) != 0) {
        *(u8 *)(obj + 0x6B8) = 1;
        i0 = 0;
        while (i0 < 12) {
            func_002b2a60(workB + 0x178,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(workB + 0x134) =
                *(CmbRGBA *)(workB + 0x178);
            func_002b2a60(workB + 0x17C,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(workB + 0x138) =
                *(CmbRGBA *)(workB + 0x17C);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i0 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(workB + 0x138);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(workB + 0x134);
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
        func_002b2970((s64*)&ttmp[0xf8], 0x141, 70.0f);
        flow[0].x = (*(f32*)&ttmp[0xf8]);
        flow[0].y = (*(f32*)&ttmp[0xfc]);
        func_002b2970((s64*)&ttmp[0xf0], 326.0f, 224.0f);
        flow[1].x = (*(f32*)&ttmp[0xf0]);
        flow[1].y = (*(f32*)&ttmp[0xf4]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x20) = flow[1].x;
        *(f32 *)(slot + 0x24) = flow[1].y;
        *(f32 *)(slot + 0x10) = *(f32 *)(slot + 0x20);
        *(f32 *)(slot + 0x14) = *(f32 *)(slot + 0x24);
        *(f32 *)(slot + 0x18) = flow[0].x;
        *(f32 *)(slot + 0x1c) = flow[0].y;
        *(s16 *)(slot + 0x2a) = 0;
        *(s16 *)(slot + 0x28) = 8;
        *(s8 *)(slot + 0xc) = *(s8 *)(slot + 0xc) | 1;
        func_002b2a60(&ttmp[0x10],0xff,0xff,0xff,0xff);
        (ttmp[0x88]) = (ttmp[0x10]);
        (ttmp[0x87]) = (ttmp[0xf]);
        (ttmp[0x86]) = (ttmp[0xe]);
        (ttmp[0x85]) = (ttmp[0xd]);
        func_002b2a60(&ttmp[0xc],0xff,0xff,0xff,0);
        (ttmp[0x84]) = (ttmp[0xc]);
        (ttmp[0x83]) = (ttmp[0xb]);
        (ttmp[0x82]) = (ttmp[0xa]);
        (ttmp[0x81]) = (ttmp[0x9]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x84) = (ttmp[0xc]);
        *(u8 *)(slot + 0x85) = (ttmp[0xb]);
        *(u8 *)(slot + 0x86) = (ttmp[0xa]);
        *(u8 *)(slot + 0x87) = (ttmp[0x9]);
        *(u8 *)(slot + 0x7c) = *(u8 *)(slot + 0x84);
        *(u8 *)(slot + 0x7d) = *(u8 *)(slot + 0x85);
        *(u8 *)(slot + 0x7e) = *(u8 *)(slot + 0x86);
        *(u8 *)(slot + 0x7f) = *(u8 *)(slot + 0x87);
        *(u8 *)(slot + 0x80) = (ttmp[0x88]);
        *(u8 *)(slot + 0x81) = (ttmp[0x87]);
        *(u8 *)(slot + 0x82) = (ttmp[0x86]);
        *(u8 *)(slot + 0x83) = (ttmp[0x85]);
        *(s16 *)(slot + 0x88) = 0;
        *(s16 *)(slot + 0x8a) = 8;
        *(s8 *)(slot + 0xc) = *(s8 *)(slot + 0xc) | 4;
        func_002b2970((s64*)&ttmp[0x108], 0x141, 70.0f);
        flow[2].x = (*(f32*)&ttmp[0x108]);
        flow[2].y = (*(f32*)&ttmp[0x10c]);
        func_002b2970((s64*)&ttmp[0x100], 326.0f, 224.0f);
        flow[3].x = (*(f32*)&ttmp[0x100]);
        flow[3].y = (*(f32*)&ttmp[0x104]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0xa4) = flow[3].x;
        *(f32 *)(slot + 0xa8) = flow[3].y;
        *(f32 *)(slot + 0x94) = *(f32 *)(slot + 0xa4);
        *(f32 *)(slot + 0x98) = *(f32 *)(slot + 0xa8);
        *(f32 *)(slot + 0x9c) = flow[2].x;
        *(f32 *)(slot + 0xa0) = flow[2].y;
        *(s16 *)(slot + 0xae) = 0;
        *(s16 *)(slot + 0xac) = 8;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 1;
        func_002b2a60(&ttmp[0x18],0xff,0xff,0xff,0xff);
        (ttmp[0x90]) = (ttmp[0x18]);
        (ttmp[0x8f]) = (ttmp[0x17]);
        (ttmp[0x8e]) = (ttmp[0x16]);
        (ttmp[0x8d]) = (ttmp[0x15]);
        func_002b2a60(&ttmp[0x14],0xff,0xff,0xff,0);
        (ttmp[0x8c]) = (ttmp[0x14]);
        (ttmp[0x8b]) = (ttmp[0x13]);
        (ttmp[0x8a]) = (ttmp[0x12]);
        (ttmp[0x89]) = (ttmp[0x11]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x108) = (ttmp[0x14]);
        *(u8 *)(slot + 0x109) = (ttmp[0x13]);
        *(u8 *)(slot + 0x10a) = (ttmp[0x12]);
        *(u8 *)(slot + 0x10b) = (ttmp[0x11]);
        *(u8 *)(slot + 0x100) = *(u8 *)(slot + 0x108);
        *(u8 *)(slot + 0x101) = *(u8 *)(slot + 0x109);
        *(u8 *)(slot + 0x102) = *(u8 *)(slot + 0x10a);
        *(u8 *)(slot + 0x103) = *(u8 *)(slot + 0x10b);
        *(u8 *)(slot + 0x104) = (ttmp[0x90]);
        *(u8 *)(slot + 0x105) = (ttmp[0x8f]);
        *(u8 *)(slot + 0x106) = (ttmp[0x8e]);
        *(u8 *)(slot + 0x107) = (ttmp[0x8d]);
        *(s16 *)(slot + 0x10c) = 0;
        *(s16 *)(slot + 0x10e) = 8;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 4;
        func_002b2970((s64*)&ttmp[0x110], 250.0f, 95.0f);
        flow[4].x = (*(f32*)&ttmp[0x110]);
        flow[4].y = (*(f32*)&ttmp[0x114]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0xec) * 0xc + slot;
        *(f32 *)(table + 0xb0) = flow[4].x;
        *(f32 *)(table + 0xb4) = flow[4].y;
        *(s16 *)(table + 0xb8) = 5;
        *(s8 *)(slot + 0x90) = *(s8 *)(slot + 0x90) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0xec),1,5,0,1);
        *(s8 *)(slot + 0xec) = tmpI;
        func_002b2970((s64*)&ttmp[0x120], 0x141, 70.0f);
        flow[5].x = (*(f32*)&ttmp[0x120]);
        flow[5].y = (*(f32*)&ttmp[0x124]);
        func_002b2970((s64*)&ttmp[0x118], 326.0f, 224.0f);
        flow[6].x = (*(f32*)&ttmp[0x118]);
        flow[6].y = (*(f32*)&ttmp[0x11c]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x128) = flow[6].x;
        *(f32 *)(slot + 0x12C) = flow[6].y;
        *(f32 *)(slot + 0x118) = *(f32 *)(slot + 0x128);
        *(s32 *)(slot + 0x11c) = *(f32 *)(slot + 0x12C);
        *(f32 *)(slot + 0x120) = flow[5].x;
        *(f32 *)(slot + 0x124) = flow[5].y;
        *(s16 *)(slot + 0x132) = 0;
        *(s16 *)(slot + 0x130) = 8;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 1;
        func_002b2a60(&ttmp[0x20],0xff,0xff,0xff,0xff);
        (ttmp[0x98]) = (ttmp[0x20]);
        (ttmp[0x97]) = (ttmp[0x1f]);
        (ttmp[0x96]) = (ttmp[0x1e]);
        (ttmp[0x95]) = (ttmp[0x1d]);
        func_002b2a60(&ttmp[0x1c],0xff,0xff,0xff,0);
        (ttmp[0x94]) = (ttmp[0x1c]);
        (ttmp[0x93]) = (ttmp[0x1b]);
        (ttmp[0x92]) = (ttmp[0x1a]);
        (ttmp[0x91]) = (ttmp[0x19]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x18c) = (ttmp[0x1c]);
        *(u8 *)(slot + 0x18d) = (ttmp[0x1b]);
        *(u8 *)(slot + 0x18e) = (ttmp[0x1a]);
        *(u8 *)(slot + 0x18F) = (ttmp[0x19]);
        *(u8 *)(slot + 0x184) = *(u8 *)(slot + 0x18c);
        *(u8 *)(slot + 0x185) = *(u8 *)(slot + 0x18d);
        *(u8 *)(slot + 0x186) = *(u8 *)(slot + 0x18e);
        *(u8 *)(slot + 0x187) = *(u8 *)(slot + 0x18F);
        *(u8 *)(slot + 0x188) = (ttmp[0x98]);
        *(u8 *)(slot + 0x189) = (ttmp[0x97]);
        *(u8 *)(slot + 0x18a) = (ttmp[0x96]);
        *(u8 *)(slot + 0x18b) = (ttmp[0x95]);
        *(s16 *)(slot + 0x190) = 0;
        *(s16 *)(slot + 0x192) = 8;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 4;
        func_002b2970((s64*)&ttmp[0x128], 250.0f, 95.0f);
        flow[7].x = (*(f32*)&ttmp[0x128]);
        flow[7].y = (*(f32*)&ttmp[0x12c]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x170) * 0xc + slot;
        *(f32 *)(table + 0x134) = flow[7].x;
        *(f32 *)(table + 0x138) = flow[7].y;
        *(s16 *)(table + 0x13c) = 5;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x170),1,5,0,1);
        *(s8 *)(slot + 0x170) = tmpI;
        func_002b2970((s64*)&ttmp[0x130], 175.0f, 141.0f);
        flow[8].x = (*(f32*)&ttmp[0x130]);
        flow[8].y = (*(f32*)&ttmp[0x134]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x170) * 0xc + slot;
        *(f32 *)(table + 0x134) = flow[8].x;
        *(f32 *)(table + 0x138) = flow[8].y;
        *(s16 *)(table + 0x13c) = 5;
        *(s8 *)(slot + 0x114) = *(s8 *)(slot + 0x114) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x170),1,5,0,1);
        *(s8 *)(slot + 0x170) = tmpI;
        func_002b2970((s64*)&ttmp[0x140], 156.0f, 232.0f);
        flow[9].x = (*(f32*)&ttmp[0x140]);
        flow[9].y = (*(f32*)&ttmp[0x144]);
        func_002b2970((s64*)&ttmp[0x138], 326.0f, 224.0f);
        flow[10].x = (*(f32*)&ttmp[0x138]);
        flow[10].y = (*(f32*)&ttmp[0x13c]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x1ac) = flow[10].x;
        *(f32 *)(slot + 0x1b0) = flow[10].y;
        *(f32 *)(slot + 0x19c) = *(f32 *)(slot + 0x1ac);
        *(f32 *)(slot + 0x1a0) = *(f32 *)(slot + 0x1b0);
        *(f32 *)(slot + 0x1a4) = flow[9].x;
        *(f32 *)(slot + 0x1a8) = flow[9].y;
        *(s16 *)(slot + 0x1b6) = 0;
        *(s16 *)(slot + 0x1b4) = 8;
        *(s8 *)(slot + 0x198) = *(s8 *)(slot + 0x198) | 1;
        func_002b2a60(&ttmp[0x28],0xff,0xff,0xff,0xff);
        (ttmp[0xa0]) = (ttmp[0x28]);
        (ttmp[0x9f]) = (ttmp[0x27]);
        (ttmp[0x9e]) = (ttmp[0x26]);
        (ttmp[0x9d]) = (ttmp[0x25]);
        func_002b2a60(&ttmp[0x24],0xff,0xff,0xff,0);
        (ttmp[0x9c]) = (ttmp[0x24]);
        (ttmp[0x9b]) = (ttmp[0x23]);
        (ttmp[0x9a]) = (ttmp[0x22]);
        (ttmp[0x99]) = (ttmp[0x21]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x210) = (ttmp[0x24]);
        *(u8 *)(slot + 0x211) = (ttmp[0x23]);
        *(u8 *)(slot + 0x212) = (ttmp[0x22]);
        *(u8 *)(slot + 0x213) = (ttmp[0x21]);
        *(u8 *)(slot + 0x208) = *(u8 *)(slot + 0x210);
        *(u8 *)(slot + 0x209) = *(u8 *)(slot + 0x211);
        *(u8 *)(slot + 0x20a) = *(u8 *)(slot + 0x212);
        *(u8 *)(slot + 0x20b) = *(u8 *)(slot + 0x213);
        *(u8 *)(slot + 0x20c) = (ttmp[0xa0]);
        *(u8 *)(slot + 0x20d) = (ttmp[0x9f]);
        *(u8 *)(slot + 0x20e) = (ttmp[0x9e]);
        *(u8 *)(slot + 0x20f) = (ttmp[0x9d]);
        *(s16 *)(slot + 0x214) = 0;
        *(s16 *)(slot + 0x216) = 8;
        *(s8 *)(slot + 0x198) = *(s8 *)(slot + 0x198) | 4;
        func_002b2970((s64*)&ttmp[0x150], 156.0f, 232.0f);
        flow[11].x = (*(f32*)&ttmp[0x150]);
        flow[11].y = (*(f32*)&ttmp[0x154]);
        func_002b2970((s64*)&ttmp[0x148], 326.0f, 224.0f);
        flow[12].x = (*(f32*)&ttmp[0x148]);
        flow[12].y = (*(f32*)&ttmp[0x14c]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x230) = flow[12].x;
        *(f32 *)(slot + 0x234) = flow[12].y;
        *(f32 *)(slot + 0x220) = *(f32 *)(slot + 0x230);
        *(f32 *)(slot + 0x224) = *(f32 *)(slot + 0x234);
        *(f32 *)(slot + 0x228) = flow[11].x;
        *(f32 *)(slot + 0x22c) = flow[11].y;
        *(s16 *)(slot + 0x23a) = 0;
        *(s16 *)(slot + 0x238) = 8;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 1;
        func_002b2a60(&ttmp[0x30],0xff,0xff,0xff,0xff);
        (ttmp[0xa8]) = (ttmp[0x30]);
        (ttmp[0xa7]) = (ttmp[0x2f]);
        (ttmp[0xa6]) = (ttmp[0x2e]);
        (ttmp[0xa5]) = (ttmp[0x2d]);
        func_002b2a60(&ttmp[0x2c],0xff,0xff,0xff,0);
        (ttmp[0xa4]) = (ttmp[0x2c]);
        (ttmp[0xa3]) = (ttmp[0x2b]);
        (ttmp[0xa2]) = (ttmp[0x2a]);
        (ttmp[0xa1]) = (ttmp[0x29]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x294) = (ttmp[0x2c]);
        *(u8 *)(slot + 0x295) = (ttmp[0x2b]);
        *(u8 *)(slot + 0x296) = (ttmp[0x2a]);
        *(u8 *)(slot + 0x297) = (ttmp[0x29]);
        *(u8 *)(slot + 0x28c) = *(u8 *)(slot + 0x294);
        *(u8 *)(slot + 0x28d) = *(u8 *)(slot + 0x295);
        *(u8 *)(slot + 0x28e) = *(u8 *)(slot + 0x296);
        *(u8 *)(slot + 0x28f) = *(u8 *)(slot + 0x297);
        *(u8 *)(slot + 0x290) = (ttmp[0xa8]);
        *(u8 *)(slot + 0x291) = (ttmp[0xa7]);
        *(u8 *)(slot + 0x292) = (ttmp[0xa6]);
        *(u8 *)(slot + 0x293) = (ttmp[0xa5]);
        *(s16 *)(slot + 0x298) = 0;
        *(s16 *)(slot + 0x29a) = 8;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 4;
        func_002b2970((s64*)&ttmp[0x158], 180.0f, 322.0f);
        flow[13].x = (*(f32*)&ttmp[0x158]);
        flow[13].y = (*(f32*)&ttmp[0x15c]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x278) * 0xc + slot;
        *(f32 *)(table + 0x23c) = flow[13].x;
        *(f32 *)(table + 0x240) = flow[13].y;
        *(s16 *)(table + 0x244) = 5;
        *(s8 *)(slot + 0x21c) = *(s8 *)(slot + 0x21c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x278),1,5,0,1);
        *(s8 *)(slot + 0x278) = tmpI;
        func_002b2970((s64*)&ttmp[0x168], 156.0f, 232.0f);
        flow[14].x = (*(f32*)&ttmp[0x168]);
        flow[14].y = (*(f32*)&ttmp[0x16c]);
        func_002b2970((s64*)&ttmp[0x160], 326.0f, 224.0f);
        flow[15].x = (*(f32*)&ttmp[0x160]);
        flow[15].y = (*(f32*)&ttmp[0x164]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x2b4) = flow[15].x;
        *(f32 *)(slot + 0x2b8) = flow[15].y;
        *(f32 *)(slot + 0x2a4) = *(f32 *)(slot + 0x2b4);
        *(f32 *)(slot + 0x2a8) = *(f32 *)(slot + 0x2b8);
        *(f32 *)(slot + 0x2ac) = flow[14].x;
        *(f32 *)(slot + 0x2b0) = flow[14].y;
        *(s16 *)(slot + 0x2be) = 0;
        *(s16 *)(slot + 0x2BC) = 8;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 1;
        func_002b2a60(&ttmp[0x38],0xff,0xff,0xff,0xff);
        (ttmp[0xb0]) = (ttmp[0x38]);
        (ttmp[0xaf]) = (ttmp[0x37]);
        (ttmp[0xae]) = (ttmp[0x36]);
        (ttmp[0xad]) = (ttmp[0x35]);
        func_002b2a60(&ttmp[0x34],0xff,0xff,0xff,0);
        (ttmp[0xac]) = (ttmp[0x34]);
        (ttmp[0xab]) = (ttmp[0x33]);
        (ttmp[0xaa]) = (ttmp[0x32]);
        (ttmp[0xa9]) = (ttmp[0x31]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x318) = (ttmp[0x34]);
        *(u8 *)(slot + 0x319) = (ttmp[0x33]);
        *(u8 *)(slot + 0x31a) = (ttmp[0x32]);
        *(u8 *)(slot + 0x31b) = (ttmp[0x31]);
        *(u8 *)(slot + 0x310) = *(u8 *)(slot + 0x318);
        *(u8 *)(slot + 0x311) = *(u8 *)(slot + 0x319);
        *(u8 *)(slot + 0x312) = *(u8 *)(slot + 0x31a);
        *(u8 *)(slot + 0x313) = *(u8 *)(slot + 0x31b);
        *(u8 *)(slot + 0x314) = (ttmp[0xb0]);
        *(u8 *)(slot + 0x315) = (ttmp[0xaf]);
        *(u8 *)(slot + 0x316) = (ttmp[0xae]);
        *(u8 *)(slot + 0x317) = (ttmp[0xad]);
        *(s16 *)(slot + 0x31c) = 0;
        *(s16 *)(slot + 0x31e) = 8;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 4;
        func_002b2970((s64*)&ttmp[0x170], 180.0f, 322.0f);
        flow[16].x = (*(f32*)&ttmp[0x170]);
        flow[16].y = (*(f32*)&ttmp[0x174]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x2fc) * 0xc + slot;
        *(f32 *)(table + 0x2c0) = flow[16].x;
        *(f32 *)(table + 0x2c4) = flow[16].y;
        *(s16 *)(table + 0x2c8) = 5;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x2fc),1,5,0,1);
        *(s8 *)(slot + 0x2fc) = tmpI;
        func_002b2970((s64*)&ttmp[0x178], 250.0f, 0x16B);
        flow[17].x = (*(f32*)&ttmp[0x178]);
        flow[17].y = (*(f32*)&ttmp[0x17c]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x2fc) * 0xc + slot;
        *(f32 *)(table + 0x2c0) = flow[17].x;
        *(f32 *)(table + 0x2c4) = flow[17].y;
        *(s16 *)(table + 0x2c8) = 5;
        *(s8 *)(slot + 0x2a0) = *(s8 *)(slot + 0x2a0) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x2fc),1,5,0,1);
        *(s8 *)(slot + 0x2fc) = tmpI;
        func_002b2970((s64*)&ttmp[0x188], 0x141, 388.0f);
        flow[18].x = (*(f32*)&ttmp[0x188]);
        flow[18].y = (*(f32*)&ttmp[0x18c]);
        func_002b2970((s64*)&ttmp[0x180], 326.0f, 224.0f);
        flow[19].x = (*(f32*)&ttmp[0x180]);
        flow[19].y = (*(f32*)&ttmp[0x184]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x338) = flow[19].x;
        *(f32 *)(slot + 0x33c) = flow[19].y;
        *(f32 *)(slot + 0x328) = *(f32 *)(slot + 0x338);
        *(f32 *)(slot + 0x32c) = *(f32 *)(slot + 0x33c);
        *(f32 *)(slot + 0x330) = flow[18].x;
        *(f32 *)(slot + 0x334) = flow[18].y;
        *(s16 *)(slot + 0x342) = 0;
        *(s16 *)(slot + 0x340) = 8;
        *(s8 *)(slot + 0x324) = *(s8 *)(slot + 0x324) | 1;
        func_002b2a60(&ttmp[0x40],0xff,0xff,0xff,0xff);
        (ttmp[0xb8]) = (ttmp[0x40]);
        (ttmp[0xb7]) = (ttmp[0x3f]);
        (ttmp[0xb6]) = (ttmp[0x3e]);
        (ttmp[0xb5]) = (ttmp[0x3d]);
        func_002b2a60(&ttmp[0x3c],0xff,0xff,0xff,0);
        (ttmp[0xb4]) = (ttmp[0x3c]);
        (ttmp[0xb3]) = (ttmp[0x3b]);
        (ttmp[0xb2]) = (ttmp[0x3a]);
        (ttmp[0xb1]) = (ttmp[0x39]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x39c) = (ttmp[0x3c]);
        *(u8 *)(slot + 0x39d) = (ttmp[0x3b]);
        *(u8 *)(slot + 0x39e) = (ttmp[0x3a]);
        *(u8 *)(slot + 0x39f) = (ttmp[0x39]);
        *(u8 *)(slot + 0x394) = *(u8 *)(slot + 0x39c);
        *(u8 *)(slot + 0x395) = *(u8 *)(slot + 0x39d);
        *(u8 *)(slot + 0x396) = *(u8 *)(slot + 0x39e);
        *(u8 *)(slot + 0x397) = *(u8 *)(slot + 0x39f);
        *(u8 *)(slot + 0x398) = (ttmp[0xb8]);
        *(u8 *)(slot + 0x399) = (ttmp[0xb7]);
        *(u8 *)(slot + 0x39a) = (ttmp[0xb6]);
        *(u8 *)(slot + 0x39b) = (ttmp[0xb5]);
        *(s16 *)(slot + 0x3a0) = 0;
        *(s16 *)(slot + 0x3a2) = 8;
        *(s8 *)(slot + 0x324) = *(s8 *)(slot + 0x324) | 4;
        func_002b2970((s64*)&ttmp[0x198], 0x141, 388.0f);
        flow[20].x = (*(f32*)&ttmp[0x198]);
        flow[20].y = (*(f32*)&ttmp[0x19c]);
        func_002b2970((s64*)&ttmp[0x190], 326.0f, 224.0f);
        flow[21].x = (*(f32*)&ttmp[0x190]);
        flow[21].y = (*(f32*)&ttmp[0x194]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x3bc) = flow[21].x;
        *(f32 *)(slot + 0x3c0) = flow[21].y;
        *(f32 *)(slot + 0x3ac) = *(f32 *)(slot + 0x3bc);
        *(f32 *)(slot + 0x3b0) = *(f32 *)(slot + 0x3c0);
        *(f32 *)(slot + 0x3b4) = flow[20].x;
        *(f32 *)(slot + 0x3b8) = flow[20].y;
        *(s16 *)(slot + 0x3c6) = 0;
        *(s16 *)(slot + 0x3c4) = 8;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 1;
        func_002b2a60(&ttmp[0x48],0xff,0xff,0xff,0xff);
        (ttmp[0xc0]) = (ttmp[0x48]);
        (ttmp[0xbf]) = (ttmp[0x47]);
        (ttmp[0xbe]) = (ttmp[0x46]);
        (ttmp[0xbd]) = (ttmp[0x45]);
        func_002b2a60(&ttmp[0x44],0xff,0xff,0xff,0);
        (ttmp[0xbc]) = (ttmp[0x44]);
        (ttmp[0xbb]) = (ttmp[0x43]);
        (ttmp[0xba]) = (ttmp[0x42]);
        (ttmp[0xb9]) = (ttmp[0x41]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x420) = (ttmp[0x44]);
        *(u8 *)(slot + 0x421) = (ttmp[0x43]);
        *(u8 *)(slot + 0x422) = (ttmp[0x42]);
        *(u8 *)(slot + 0x423) = (ttmp[0x41]);
        *(u8 *)(slot + 0x418) = *(u8 *)(slot + 0x420);
        *(u8 *)(slot + 0x419) = *(u8 *)(slot + 0x421);
        *(u8 *)(slot + 0x41a) = *(u8 *)(slot + 0x422);
        *(u8 *)(slot + 0x41b) = *(u8 *)(slot + 0x423);
        *(u8 *)(slot + 0x41c) = (ttmp[0xc0]);
        *(u8 *)(slot + 0x41d) = (ttmp[0xbf]);
        *(u8 *)(slot + 0x41e) = (ttmp[0xbe]);
        *(u8 *)(slot + 0x41f) = (ttmp[0xbd]);
        *(s16 *)(slot + 0x424) = 0;
        *(s16 *)(slot + 0x426) = 8;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 4;
        func_002b2970((s64*)&ttmp[0x1a0], 0x187, 0x16B);
        flow[22].x = (*(f32*)&ttmp[0x1a0]);
        flow[22].y = (*(f32*)&ttmp[0x1a4]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x404) * 0xc + slot;
        *(f32 *)(table + 0x3c8) = flow[22].x;
        *(f32 *)(table + 0x3cc) = flow[22].y;
        *(s16 *)(table + 0x3d0) = 5;
        *(s8 *)(slot + 0x3a8) = *(s8 *)(slot + 0x3a8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x404),1,5,0,1);
        *(s8 *)(slot + 0x404) = tmpI;
        func_002b2970((s64*)&ttmp[0x1b0], 0x141, 388.0f);
        flow[23].x = (*(f32*)&ttmp[0x1b0]);
        flow[23].y = (*(f32*)&ttmp[0x1b4]);
        func_002b2970((s64*)&ttmp[0x1a8], 326.0f, 224.0f);
        flow[24].x = (*(f32*)&ttmp[0x1a8]);
        flow[24].y = (*(f32*)&ttmp[0x1ac]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x440) = flow[24].x;
        *(f32 *)(slot + 0x444) = flow[24].y;
        *(f32 *)(slot + 0x430) = *(f32 *)(slot + 0x440);
        *(f32 *)(slot + 0x434) = *(f32 *)(slot + 0x444);
        *(f32 *)(slot + 0x438) = flow[23].x;
        *(f32 *)(slot + 0x43c) = flow[23].y;
        *(s16 *)(slot + 0x44a) = 0;
        *(s16 *)(slot + 0x448) = 8;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 1;
        func_002b2a60(&ttmp[0x50],0xff,0xff,0xff,0xff);
        (ttmp[0xc8]) = (ttmp[0x50]);
        (ttmp[0xc7]) = (ttmp[0x4f]);
        (ttmp[0xc6]) = (ttmp[0x4e]);
        (ttmp[0xc5]) = (ttmp[0x4d]);
        func_002b2a60(&ttmp[0x4c],0xff,0xff,0xff,0);
        (ttmp[0xc4]) = (ttmp[0x4c]);
        (ttmp[0xc3]) = (ttmp[0x4b]);
        (ttmp[0xc2]) = (ttmp[0x4a]);
        (ttmp[0xc1]) = (ttmp[0x49]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x4a4) = (ttmp[0x4c]);
        *(u8 *)(slot + 0x4a5) = (ttmp[0x4b]);
        *(u8 *)(slot + 0x4a6) = (ttmp[0x4a]);
        *(u8 *)(slot + 0x4a7) = (ttmp[0x49]);
        *(u8 *)(slot + 0x49c) = *(u8 *)(slot + 0x4a4);
        *(u8 *)(slot + 0x49d) = *(u8 *)(slot + 0x4a5);
        *(u8 *)(slot + 0x49e) = *(u8 *)(slot + 0x4a6);
        *(u8 *)(slot + 0x49f) = *(u8 *)(slot + 0x4a7);
        *(u8 *)(slot + 0x4a0) = (ttmp[0xc8]);
        *(u8 *)(slot + 0x4a1) = (ttmp[0xc7]);
        *(u8 *)(slot + 0x4a2) = (ttmp[0xc6]);
        *(u8 *)(slot + 0x4a3) = (ttmp[0xc5]);
        *(s16 *)(slot + 0x4a8) = 0;
        *(s16 *)(slot + 0x4aa) = 8;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 4;
        func_002b2970((s64*)&ttmp[0x1b8], 0x187, 0x16B);
        flow[25].x = (*(f32*)&ttmp[0x1b8]);
        flow[25].y = (*(f32*)&ttmp[0x1bc]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x488) * 0xc + slot;
        *(f32 *)(table + 0x44c) = flow[25].x;
        *(f32 *)(table + 0x450) = flow[25].y;
        *(s16 *)(table + 0x454) = 5;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x488),1,5,0,1);
        *(s8 *)(slot + 0x488) = tmpI;
        func_002b2970((s64*)&ttmp[0x1c0], 458.0f, 322.0f);
        flow[26].x = (*(f32*)&ttmp[0x1c0]);
        flow[26].y = (*(f32*)&ttmp[0x1c4]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x488) * 0xc + slot;
        *(f32 *)(table + 0x44c) = flow[26].x;
        *(f32 *)(table + 0x450) = flow[26].y;
        *(s16 *)(table + 0x454) = 5;
        *(s8 *)(slot + 0x42c) = *(s8 *)(slot + 0x42c) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x488),1,5,0,1);
        *(s8 *)(slot + 0x488) = tmpI;
        func_002b2970((s64*)&ttmp[0x1d0], 482.0f, 232.0f);
        flow[27].x = (*(f32*)&ttmp[0x1d0]);
        flow[27].y = (*(f32*)&ttmp[0x1d4]);
        func_002b2970((s64*)&ttmp[0x1c8], 326.0f, 224.0f);
        flow[28].x = (*(f32*)&ttmp[0x1c8]);
        flow[28].y = (*(f32*)&ttmp[0x1cc]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x4c4) = flow[28].x;
        *(f32 *)(slot + 0x4c8) = flow[28].y;
        *(f32 *)(slot + 0x4b4) = *(f32 *)(slot + 0x4c4);
        *(f32 *)(slot + 0x4b8) = *(f32 *)(slot + 0x4c8);
        *(f32 *)(slot + 0x4bc) = flow[27].x;
        *(f32 *)(slot + 0x4c0) = flow[27].y;
        *(s16 *)(slot + 0x4ce) = 0;
        *(s16 *)(slot + 0x4cc) = 8;
        *(s8 *)(slot + 0x4b0) = *(s8 *)(slot + 0x4b0) | 1;
        func_002b2a60(&ttmp[0x58],0xff,0xff,0xff,0xff);
        (ttmp[0xd0]) = (ttmp[0x58]);
        (ttmp[0xcf]) = (ttmp[0x57]);
        (ttmp[0xce]) = (ttmp[0x56]);
        (ttmp[0xcd]) = (ttmp[0x55]);
        func_002b2a60(&ttmp[0x54],0xff,0xff,0xff,0);
        (ttmp[0xcc]) = (ttmp[0x54]);
        (ttmp[0xcb]) = (ttmp[0x53]);
        (ttmp[0xca]) = (ttmp[0x52]);
        (ttmp[0xc9]) = (ttmp[0x51]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x528) = (ttmp[0x54]);
        *(u8 *)(slot + 0x529) = (ttmp[0x53]);
        *(u8 *)(slot + 0x52a) = (ttmp[0x52]);
        *(u8 *)(slot + 0x52b) = (ttmp[0x51]);
        *(u8 *)(slot + 0x520) = *(u8 *)(slot + 0x528);
        *(u8 *)(slot + 0x521) = *(u8 *)(slot + 0x529);
        *(u8 *)(slot + 0x522) = *(u8 *)(slot + 0x52a);
        *(u8 *)(slot + 0x523) = *(u8 *)(slot + 0x52b);
        *(u8 *)(slot + 0x524) = (ttmp[0xd0]);
        *(u8 *)(slot + 0x525) = (ttmp[0xcf]);
        *(u8 *)(slot + 0x526) = (ttmp[0xce]);
        *(u8 *)(slot + 0x527) = (ttmp[0xcd]);
        *(s16 *)(slot + 0x52c) = 0;
        *(s16 *)(slot + 0x52e) = 8;
        *(s8 *)(slot + 0x4b0) = *(s8 *)(slot + 0x4b0) | 4;
        func_002b2970((s64*)&ttmp[0x1e0], 482.0f, 232.0f);
        flow[29].x = (*(f32*)&ttmp[0x1e0]);
        flow[29].y = (*(f32*)&ttmp[0x1e4]);
        func_002b2970((s64*)&ttmp[0x1d8], 326.0f, 224.0f);
        flow[30].x = (*(f32*)&ttmp[0x1d8]);
        flow[30].y = (*(f32*)&ttmp[0x1dc]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x548) = flow[30].x;
        *(f32 *)(slot + 0x54c) = flow[30].y;
        *(f32 *)(slot + 0x538) = *(f32 *)(slot + 0x548);
        *(f32 *)(slot + 0x53c) = *(f32 *)(slot + 0x54c);
        *(f32 *)(slot + 0x540) = flow[29].x;
        *(f32 *)(slot + 0x544) = flow[29].y;
        *(s16 *)(slot + 0x552) = 0;
        *(s16 *)(slot + 0x550) = 8;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 1;
        func_002b2a60(&ttmp[0x60],0xff,0xff,0xff,0xff);
        (ttmp[0xd8]) = (ttmp[0x60]);
        (ttmp[0xd7]) = (ttmp[0x5f]);
        (ttmp[0xd6]) = (ttmp[0x5e]);
        (ttmp[0xd5]) = (ttmp[0x5d]);
        func_002b2a60(&ttmp[0x5c],0xff,0xff,0xff,0);
        (ttmp[0xd4]) = (ttmp[0x5c]);
        (ttmp[0xd3]) = (ttmp[0x5b]);
        (ttmp[0xd2]) = (ttmp[0x5a]);
        (ttmp[0xd1]) = (ttmp[0x59]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x5ac) = (ttmp[0x5c]);
        *(u8 *)(slot + 0x5ad) = (ttmp[0x5b]);
        *(u8 *)(slot + 0x5ae) = (ttmp[0x5a]);
        *(u8 *)(slot + 0x5af) = (ttmp[0x59]);
        *(u8 *)(slot + 0x5a4) = *(u8 *)(slot + 0x5ac);
        *(u8 *)(slot + 0x5a5) = *(u8 *)(slot + 0x5ad);
        *(u8 *)(slot + 0x5a6) = *(u8 *)(slot + 0x5ae);
        *(u8 *)(slot + 0x5a7) = *(u8 *)(slot + 0x5af);
        *(u8 *)(slot + 0x5a8) = (ttmp[0xd8]);
        *(u8 *)(slot + 0x5a9) = (ttmp[0xd7]);
        *(u8 *)(slot + 0x5aa) = (ttmp[0xd6]);
        *(u8 *)(slot + 0x5ab) = (ttmp[0xd5]);
        *(s16 *)(slot + 0x5b0) = 0;
        *(s16 *)(slot + 0x5b2) = 8;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 4;
        func_002b2970((s64*)&ttmp[0x1e8], 462.0f, 141.0f);
        flow[31].x = (*(f32*)&ttmp[0x1e8]);
        flow[31].y = (*(f32*)&ttmp[0x1ec]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x590) * 0xc + slot;
        *(f32 *)(table + 0x554) = flow[31].x;
        *(f32 *)(table + 0x558) = flow[31].y;
        *(s16 *)(table + 0x55c) = 5;
        *(s8 *)(slot + 0x534) = *(s8 *)(slot + 0x534) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x590),1,5,0,1);
        *(s8 *)(slot + 0x590) = tmpI;
        func_002b2970((s64*)&ttmp[0x1f8], 482.0f, 232.0f);
        flow[32].x = (*(f32*)&ttmp[0x1f8]);
        flow[32].y = (*(f32*)&ttmp[0x1fc]);
        func_002b2970((s64*)&ttmp[0x1f0], 326.0f, 224.0f);
        flow[33].x = (*(f32*)&ttmp[0x1f0]);
        flow[33].y = (*(f32*)&ttmp[0x1f4]);
        slot = *(u8 **)(arg0 + 0x38);
        *(f32 *)(slot + 0x5cc) = flow[33].x;
        *(f32 *)(slot + 0x5d0) = flow[33].y;
        *(f32 *)(slot + 0x5bc) = *(f32 *)(slot + 0x5cc);
        *(f32 *)(slot + 0x5c0) = *(f32 *)(slot + 0x5d0);
        *(f32 *)(slot + 0x5c4) = flow[32].x;
        *(f32 *)(slot + 0x5c8) = flow[32].y;
        *(s16 *)(slot + 0x5d6) = 0;
        *(s16 *)(slot + 0x5d4) = 8;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 1;
        func_002b2a60(&ttmp[0x68],0xff,0xff,0xff,0xff);
        (ttmp[0xe0]) = (ttmp[0x68]);
        (ttmp[0xdf]) = (ttmp[0x67]);
        (ttmp[0xde]) = (ttmp[0x66]);
        (ttmp[0xdd]) = (ttmp[0x65]);
        func_002b2a60(&ttmp[0x64],0xff,0xff,0xff,0);
        (ttmp[0xdc]) = (ttmp[0x64]);
        (ttmp[0xdb]) = (ttmp[0x63]);
        (ttmp[0xda]) = (ttmp[0x62]);
        (ttmp[0xd9]) = (ttmp[0x61]);
        slot = *(u8 **)(arg0 + 0x38);
        *(u8 *)(slot + 0x630) = (ttmp[0x64]);
        *(u8 *)(slot + 0x631) = (ttmp[0x63]);
        *(u8 *)(slot + 0x632) = (ttmp[0x62]);
        *(u8 *)(slot + 0x633) = (ttmp[0x61]);
        *(u8 *)(slot + 0x628) = *(u8 *)(slot + 0x630);
        *(u8 *)(slot + 0x629) = *(u8 *)(slot + 0x631);
        *(u8 *)(slot + 0x62a) = *(u8 *)(slot + 0x632);
        *(u8 *)(slot + 0x62b) = *(u8 *)(slot + 0x633);
        *(u8 *)(slot + 0x62c) = (ttmp[0xe0]);
        *(u8 *)(slot + 0x62d) = (ttmp[0xdf]);
        *(u8 *)(slot + 0x62e) = (ttmp[0xde]);
        *(u8 *)(slot + 0x62f) = (ttmp[0xdd]);
        *(s16 *)(slot + 0x634) = 0;
        *(s16 *)(slot + 0x636) = 8;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 4;
        func_002b2970((s64*)&ttmp[0x200], 462.0f, 141.0f);
        flow[34].x = (*(f32*)&ttmp[0x200]);
        flow[34].y = (*(f32*)&ttmp[0x204]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x614) * 0xc + slot;
        *(f32 *)(table + 0x5d8) = flow[34].x;
        *(f32 *)(table + 0x5dc) = flow[34].y;
        *(s16 *)(table + 0x5e0) = 5;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x614),1,5,0,1);
        *(s8 *)(slot + 0x614) = tmpI;
        func_002b2970((s64*)&ttmp[0x208], 0x187, 95.0f);
        flow[35].x = (*(f32*)&ttmp[0x208]);
        flow[35].y = (*(f32*)&ttmp[0x20c]);
        slot = *(u8 **)(arg0 + 0x38);
        table = *(s8 *)(slot + 0x614) * 0xc + slot;
        *(f32 *)(table + 0x5d8) = flow[35].x;
        *(f32 *)(table + 0x5dc) = flow[35].y;
        *(s16 *)(table + 0x5e0) = 5;
        *(s8 *)(slot + 0x5b8) = *(s8 *)(slot + 0x5b8) | 8;
        tmpI = func_002b2cb0(*(s8 *)(slot + 0x614),1,5,0,1);
        *(s8 *)(slot + 0x614) = tmpI;
            *(s16 *)(obj + 0x63C) = 6;
        }
        break;
    case 6:
        if (func_00285b30() >= 0x73) {
            i6 = 0;
            while (i6 < 12) {
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
                fvalue = *(f32 *)(slot2 + 0x20) + 12.0f;
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x134) = fvalue;
                fvalue = *(f32 *)(slot2 + 0x24);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x138) = fvalue;
                func_003482a0(*(u8 **)table, 0, 0x80, 0x32);
                ret = (u8 *)func_00348290(*(u8 **)table);
                *(f32 *)(ret + 0x1A0) = iGpffff8508;
                i6++;
            }
            *(s16 *)(obj + 0x63C) = 7;
        }
        break;
    case 7:
        func_0045aeb0(2, D_0064A5B0);
        func_002b29a0(workB + 0x10, 0.0f, -5.0f, 30.0f);
        func_002b2a60(workB + 0x144,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_002b29a0(workB + 0x20, 35.0f, 5.0f, 30.0f);
        func_002b2a60(workB + 0x148,
                      0xFF, 0xFF, 0xFF, 0xFFU);
        func_00348a90(*(u8 **)(obj + 0x64C),
                      (CmbVec3f *)(workB + 0x10),
                      *(CmbRGBA *)(workB + 0x144), 0, 0x28,
                      (CmbVec3f *)(workB + 0x20),
                      *(CmbRGBA *)(workB + 0x148),
                      0.0f, 0.0f, 0.0f, iGpffff850c,
                      0.0f, 0.0f, 31.5f, iGpffff850c);
        *(s16 *)(obj + 0x63C) = 8;
        /* fallthrough */
    case 8:
        if (func_00452490(*(s32 *)(obj + 0x64C)) != 1) {
            i8 = 0;
            while (i8 < 12) {
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
            while (i9 < 12) {
                func_002b2970((s64 *)(workB + 0x8), 323.0f, 217.0f);
                flow[36].x = *(f32 *)(workB + 0x8);
                flow[36].y = *(f32 *)(workB + 0xC);
                *(CmbVec2f *)&workF70 = flow[36];
                slot = *(u8 **)(arg0 + 0x38);
                slot += (s32)i9 * 0x84;
                table = obj + (s32)i9 * 0x84;
                *(CmbVec2f *)(slot + 0x20) =
                    *(CmbVec2f *)(table + 0x20);
                *(CmbVec2f *)(slot + 0x10) =
                    *(CmbVec2f *)(slot + 0x20);
                *(CmbVec2f *)(slot + 0x18) =
                    *(CmbVec2f *)&workF70;
                *(s16 *)(slot + 0x2A) = 0;
                *(s16 *)(slot + 0x28) = 3;
                *(s8 *)(slot + 0xC) |= 1;
                table = obj + (s32)i9 * 4;
                slot2 = table + 0x658;
                ret = (u8 *)func_00348290(*(u8 **)slot2);
                func_002b2970((s64 *)(workB + 0x0), 339.0f, 217.0f);
                func_003482d0(*(u8 **)slot2,
                              *(CmbVec2f *)(ret + 0x134),
                              *(CmbVec2f *)(workB + 0x0), 3);
                i9++;
            }
            *(s16 *)(obj + 0x63C) = 10;
        }
        break;
    case 10:
        *(u8 *)(obj + 0x6B8) = 1;
        i10 = 0;
        while (i10 < 12) {
            func_002b2a60(workB + 0x13C,
                          0xFF, 0xFF, 0xFF, 0U);
            *(CmbRGBA *)(workB + 0xFC) =
                *(CmbRGBA *)(workB + 0x13C);
            func_002b2a60(workB + 0x140,
                          0xFF, 0xFF, 0xFF, 0xFFU);
            *(CmbRGBA *)(workB + 0x100) =
                *(CmbRGBA *)(workB + 0x140);
            slot = *(u8 **)(arg0 + 0x38);
            slot += (s32)i10 * 0x84;
            *(CmbRGBA *)(slot + 0x84) =
                *(CmbRGBA *)(workB + 0x100);
            *(CmbRGBA *)(slot + 0x7C) =
                *(CmbRGBA *)(slot + 0x84);
            *(CmbRGBA *)(slot + 0x80) =
                *(CmbRGBA *)(workB + 0xFC);
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
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00345700);
#endif

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
/* measured: re-derived inherited nd263 -> nd56 (differing words reloc-masked, 301/301 instrs, 1204B/1216B) in correct tree pwd /home/raikaru/Projects/Persona 3 Decomp/source/Persona4-Decompilation.
   Exact commands (bare repo-relative paths):
     python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00347c70 --candidate v10b=/var/tmp/cmb347c70/body_v10b.c  # 56 (v9 raw 265, v4 tight 261, v5 reload 279, v11 dtab 270, v12 dtab+pragma 289, v13 recipeA 76)
     python3 tools/fnalign.py src/promoted/y_CmbCardEff.c func_00347c70 --candidate /var/tmp/cmb347c70/body_v10b.c  # 58 edits (+4 reloc-only), retail 301 object 301
     python3 tools/probe_archive.py docs/probe_archive/yCmb_00347c70_body.c src/promoted/y_CmbCardEff.c  # 56, source unchanged
   Reconstruction top-down: lw 0x38(a0)->s0, 1.0f/div.s, ((flags&2)>>1)==1 gate, s16 i<4 loop x4 with (f32)*(u8*) srl/bltz, FMA reload *(0x134/0x138) +/- 64.0f**(0x1A0) (literal 64 for lui/mtc1, adda/msub/madd), 00285b30<0x208 alloc 00461390+00347b30, ((flags&4)>>2)==1 with 002b2aa0(0,...)/002b2cb0, ((flags&0x10)>>4)==1 with 002b2aa0(1,...)/(u8)(s32) guard + 002b2cb0.
   Levers that moved it (docs/matching.md): raw byte-offset ((s32)obj+(s32)i*0x40+off) fixes body-head dsll32/dsra32 (p-style folds ext to bottom only; isolated loop3 int+short vs loop4 short proof) + reload FMA fixes ACC (cached f1b/c64 h1=mul vs reload h2=adda, isolated fma_test proof) + #pragma push/opt_loop_invariants on/pop 265->56 (full D-1.0 hoist vs lui-only; dtab variants reject). Recipe A explicit v/c/doubling 76 rejects (plain already single bltz as in matched 003489c0). Flag ((x&N)>>k)==1, s16, u8/lbu, s16/lh, f32, /2 correction all match.
   Remaining 56 floor (fnalign earliest hunk loop preheader, nothing after is real until it is gone): lui-only hoist granularity (retail lui $v0 alone at entry + lwc1/sub per iter; pragma hoists whole lui+lwc1+sub to preheader, direct keeps lui in body) + or/mtc1 coloring ($v1 vs $a0, dest $a0 vs $a1, counter $a1 vs $a2, srl/andi/or/mtc1 x4 + final mfc1/or/sb $v0 vs $v1) + branch displacement cascade. Same family as prior 263 note + y_draw 002b7f20 + y_smap 002b0b10. Tried p/raw/off+base/while/dtab/recipeA/decl orders, all measured. Production stays INCLUDE_ASM per floor policy; best faithful body banked as docs/probe_archive/yCmb_00347c70_body.c (LF) with push/pop pragma. No live body, no TEMP-PROBE, externs preserved, CRLF preserved. */
/* Fresh 2026-09-17 (this lane, in order after 004941f0): `python3 tools/probe_archive.py docs/probe_archive/yCmb_00347c70_body.c src/promoted/y_CmbCardEff.c` re-measures 56, source unchanged — banked body still reproduces. Two fresh levers via `python3 tools/probe_variants.py src/promoted/y_CmbCardEff.c func_00347c70 --candidate v_s32=/tmp/cmb_v_s32.c --candidate v_nop=/tmp/cmb_v_nop.c`: v_s32 (func_00348330 exact guarded idiom `s32 v; if (2.1474836e9f > fres) { v=(s32)fres; v&=0xFF; } else { v=(s32)(fres-K)|0x80000000; v&=0xFF; } *(u8*)=(u8)v;` replacing archive `u8 cv` direct) ties at 56 — the tail mfc1/or/sb $v0-vs-$v1 coloring wall persists across u8/s32 spellings, same family as 00348330 nd15 (3 sites x 5 words there, 1 site here within the 56); v_nop (strip push/loop_invariants) regresses to 265, confirming the banked pragma stays load-bearing 265->56 (matches inherited v9 raw 265). No new win; 56 floor stands, production stays INCLUDE_ASM per floor policy, archive unchanged. */
/* measured: banked yCmb_00347c70_body.c verbatim (301/301 instrs, 0.0% deviation, within 3% gate; 1204B/1216B, 56 differing words reloc-masked, 58 fnalign edits +4 reloc-only). 3% check: |301-301|/301 = 0.0% <= 3%, so guarded floor per handoff banking rule. Body keeps file conventions: obj = *(u8**)(arg0+0x38), raw (s32)obj+(s32)i*0x40+off, s16 i, ((x&N)>>k)==1 flags, reload FMA, (u8)(s32)fres guard shared with func_00348330 nd15 idiom. Residual is hoist-granularity + or/mtc1 coloring + tail conversion coloring, same family as 00348330. Verified via probe_archive 56 and fnalign 301/301. Production stays guarded (not MATCH) per floor policy. */
/* 56 -> 51 (2026-09-18): the hand-written float-to-u8 conversion replaced by
   the plain `(u8)fres` cast, which b210 expands itself and colours the way
   retail does.  Same lever as func_00348330 above. */
// FUN_00347C70 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_00347c70(u8 *arg0)
{
    u8 *obj;
    f32 div;
    s16 i;
    obj = *(u8 **)(arg0 + 0x38);
    div = 1.0f / *(f32 *)(func_00457120() + 0x80);
    if (((( *(s32 *)(obj + 0x11C) & 2) >> 1) == 1)) {
        for (i = 0; i < 4; i++) {
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x18) = D_008872F8[0] - 1.0f;
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x28) = div;
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x30) = (f32)*(u8 *)(obj + 0x198);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x34) = (f32)*(u8 *)(obj + 0x199);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x38) = (f32)*(u8 *)(obj + 0x19A);
            *(f32 *)((s32)obj + (s32)i * 0x40 + 0x3C) = (f32)*(u8 *)(obj + 0x19B);
        }
    }
    *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x134) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x138) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x50) = *(f32 *)(obj + 0x134) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x54) = *(f32 *)(obj + 0x138) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x90) = *(f32 *)(obj + 0x134) - 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0x94) = *(f32 *)(obj + 0x138) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0xD0) = *(f32 *)(obj + 0x134) + 64.0f * *(f32 *)(obj + 0x1A0);
    *(f32 *)(obj + 0xD4) = *(f32 *)(obj + 0x138) + 64.0f * *(f32 *)(obj + 0x1A0);
    if (func_00285b30() < 0x208) {
        u8 *alloc = func_00461390(D_00794F00, 4, obj + 0x10, 4);
        *(u32 *)(alloc + 8) = (u32)func_00347b30;
        *(u8 **)(alloc + 0x10) = obj;
    }
    if (((( *(s32 *)(obj + 0x11C) & 4) >> 2) == 1)) {
        f32 f14 = (f32)*(s16 *)(obj + 0x13E);
        f32 f15 = (f32)*(s16 *)(obj + 0x13C);
        *(f32 *)(obj + 0x134) = func_002b2aa0(0, *(f32 *)(obj + 0x124), *(f32 *)(obj + 0x12C), f14, f15);
        f14 = (f32)*(s16 *)(obj + 0x13E);
        f15 = (f32)*(s16 *)(obj + 0x13C);
        *(f32 *)(obj + 0x138) = func_002b2aa0(0, *(f32 *)(obj + 0x128), *(f32 *)(obj + 0x130), f14, f15);
        if (*(s16 *)(obj + 0x13E) < *(s16 *)(obj + 0x13C)) {
            *(s16 *)(obj + 0x13E) = func_002b2cb0(*(s16 *)(obj + 0x13E), 1, *(s16 *)(obj + 0x13C), 0, 1);
        } else {
            *(s32 *)(obj + 0x11C) &= 0xFFFB;
        }
    }
    if (((( *(s32 *)(obj + 0x11C) & 0x10) >> 4) == 1)) {
        f32 f12 = (f32)*(u8 *)(obj + 0x193);
        f32 f13 = (f32)*(u8 *)(obj + 0x197);
        f32 f14 = (f32)*(s16 *)(obj + 0x19C);
        f32 f15 = (f32)(*(s16 *)(obj + 0x19E) / 2);
        f32 fres = func_002b2aa0(1, f12, f13, f14, f15);
        *(u8 *)(obj + 0x19B) = (u8)fres;
        if (*(s16 *)(obj + 0x19C) < *(s16 *)(obj + 0x19E)) {
            *(s16 *)(obj + 0x19C) = func_002b2cb0(*(s16 *)(obj + 0x19C), 1, *(s16 *)(obj + 0x19E), 0, 1);
        } else {
            *(s16 *)(obj + 0x19C) = 0;
        }
    }
    return 0;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00347c70);
#endif
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

/* measured: nd 15, obj 1296B = window (323 instrs both) — dispatch (lb 0x4, beq 3,2,1 + beqz 0 + b default), 004553c0/004b11xx/002b2d00 branches and float loads all match; EVERYTHING matches except the guarded-conversion result register: three `if (2.1474836e9f > f0) { v = (s32)f0; v &= 0xFF; } else { v = (s32)(f0-K)|0x80000000; v &= 0xFF; }` keep b210 mfc1/or/sb in $v0 where retail coalesces into $v1 (3 sites x 5 = 15 words; tried u8 locals, f0/v order, inline stores — no shift, same family as cmmScript func_0024c0e0). Recipe (correct-tree, top-down fnalign): outer switch cases 0,1,2,3 ascending (reverse beq chain 3,2,1,0+beqz) with case0/default break-shared to single return 0 (explicit return 0 in case1/2 regresses to 275; order 1,0,2,3 regresses dispatch to 39); inner 0x39 3-way if/else-if (x==0/1/2) reusing $a1=2; D_005DC7D0 indexed `&D_005DC7D0[idx*0x54]` (reloc-only); half via `h/2` (manual sra+bgez keeps $v0/$v1 swap, 29); nv via reload `*(s16*)=func...; if (*(s16*)<...)` (nv-local + explicit (s32)(s16) cast mis-schedules sh, 18). func_004553c0 takes ONE arg (m2c 2nd arg wrong); guard must be `2.1474836e9f > f0` with normal-first to keep c.le.s/bc1t + per-arm andi. Path 275->39->29->18->15. Production stays ASM. */
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
/* measured 2026-09-17 full pragma_sweep --pairs: banked 15 via measure_guarded; */
/* best stays 15 (ties: loopinv on, strength off, unroll off and pairs; 26-group */
/* prop/dead pairs; 234-235 csoff group, 277-281 schedule group, 310-331 peephole */
/* group). No pair wins; floor stands. */
/* MATCHED 2026-09-18.  The three `*(u8 *)(obj + 0x38) = ...` sites had the
   float-to-unsigned-byte conversion written out by hand (compare against
   2.1474836e9f, subtract, or in 0x80000000, mask).  b210 generates exactly
   that sequence for a plain `(u8)f0` cast, and its own version colours the
   result $v1 with the constant in $v0 - the hand-written form does the
   reverse, which was the whole 15-word residual.  Writing the cast fixes all
   three at once; fixing only the two shallow sites leaves 5. */
// FUN_00348330
s32 func_00348330(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)(obj + 4)) {
    case 0:
        break;
    case 1: {
        if (func_004553c0(*(u8 **)(obj + 0)) == 0) {
            return 0;
        }
        {
            u32 h = *(u32 *)(obj + 8);
            if (h != 0) {
                func_004b1150(h);
                *(u32 *)(obj + 8) = 0;
            }
        }
        {
            s32 nv = func_004b1130(*(s32 *)(*(u8 **)(obj + 0) + 0x110));
            *(s32 *)(obj + 8) = nv;
            func_004b1250(nv, obj + 0x18);
            func_004b1290(*(s32 *)(obj + 8), *(f32 *)(obj + 0x24), *(f32 *)(obj + 0x28), *(f32 *)(obj + 0x2C));
            func_004b13d0(*(s32 *)(obj + 8), *(f32 *)(obj + 0x30));
            func_004b13f0(*(s32 *)(obj + 8), obj + 0x34);
            if (*(u8 *)(obj + 0x48) == 1) {
                s32 nv2 = func_004b11b0(*(s32 *)(obj + 8));
                *(s32 *)(obj + 0x44) = nv2;
                func_004b1250(nv2, obj + 0x4C);
                func_004b1290(*(s32 *)(obj + 0x44), *(f32 *)(obj + 0x58), *(f32 *)(obj + 0x5C), *(f32 *)(obj + 0x60));
                func_004b13d0(*(s32 *)(obj + 0x44), *(f32 *)(obj + 0x64));
                func_004b13f0(*(s32 *)(obj + 0x44), obj + 0x68);
            }
        }
        *(u16 *)(obj + 0xC) = 0;
        *(s8 *)(obj + 4) += 1;
        break;
    }
    case 2: {
        s16 cnt = *(s16 *)(obj + 0x3E);
        if (cnt > 0) {
            *(s16 *)(obj + 0x3E) = func_002b2d00(cnt, 1, 0, 0, 1);
            return 0;
        }
        {
            u8 mode = *(u8 *)(obj + 0x39);
            if (mode == 0) {
                f32 f0 = func_002b2aa0(0, 0.0f, *(f32 *)(obj + 0x40), (f32)*(s16 *)(obj + 0x3C), (f32)*(s16 *)(obj + 0x3A));
                *(u8 *)(obj + 0x38) = (u8)f0;
            } else if (mode == 1) {
                f32 f0 = func_002b2aa0(0, *(f32 *)(obj + 0x40), 0.0f, (f32)*(s16 *)(obj + 0x3C), (f32)*(s16 *)(obj + 0x3A));
                *(u8 *)(obj + 0x38) = (u8)f0;
                if (*(s16 *)(obj + 0x3C) >= *(s16 *)(obj + 0x3A)) {
                    *(s8 *)(obj + 4) = 3;
                }
            } else if (mode == 2) {
                s16 h = *(s16 *)(obj + 0x3A);
                s32 half = h / 2;
                {
                    f32 f0 = func_002b2aa0(1, 0.0f, 255.0f, (f32)*(s16 *)(obj + 0x3C), (f32)half);
                    *(u8 *)(obj + 0x38) = (u8)f0;
                }
            }
        }
        {
            *(s16 *)(obj + 0x3C) = func_002b2cb0(*(s16 *)(obj + 0x3C), 1, *(s16 *)(obj + 0x3A), 0, 1);
            if (*(s16 *)(obj + 0x3C) < *(s16 *)(obj + 0x3A)) {
                *(u8 *)(obj + 0x37) = *(u8 *)(obj + 0x38);
                func_004b13f0(*(s32 *)(obj + 8), obj + 0x34);
                if (*(u8 *)(obj + 0x48) == 1) {
                    *(u8 *)(obj + 0x6B) = *(u8 *)(obj + 0x38);
                    func_004b13f0(*(s32 *)(obj + 0x44), obj + 0x68);
                }
            }
        }
        func_004b1190(*(s32 *)(obj + 8));
        func_004b11d0((s32)&D_005DC7D0[*(u8 *)(obj + 0x14) * 0x54], *(s32 *)(obj + 8));
        if (*(u8 *)(obj + 0x48) == 1) {
            func_004b1190(*(s32 *)(obj + 0x44));
            func_004b11d0((s32)&D_005DC7D0[*(u8 *)(obj + 0x14) * 0x54], *(s32 *)(obj + 0x44));
        }
        {
            s32 lim = *(s32 *)(obj + 0x10);
            if (lim == -1) {
                if (func_004b1520(*(s32 *)(obj + 8)) == 0) {
                    *(s8 *)(obj + 4) = 3;
                }
            } else {
                *(u16 *)(obj + 0xC) = func_002b2cb0(*(u16 *)(obj + 0xC), 1, lim, 0, 1);
                if (*(u16 *)(obj + 0xC) >= *(s32 *)(obj + 0x10)) {
                    *(s8 *)(obj + 4) = 3;
                }
            }
        }
        break;
    }
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
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

/* measured: banked reconstruction (switch 0,1 + Cmb48Work struct with V16+pad) matches retail calls/constants; frame now 0x1A0 via 11xV16 (0x80-0x12F) +12xs64 (0x130-0x18F)+pad+3xu32 (0x194-0x19C), fixing prior 0x150 coalescing claim. fnalign retail 389/object 386, 56 edits: register-color (obj s3 vs s1, idx s0 vs s4, slot s2 vs s0, scaled s1 vs s5, colors s5/s4 vs s3/s2) + tail return branchless (xori/sltiu/negu vs bne/addiu -1) + displacements. Tried: if-1-first vs switch-0,1 (switch gives retail beq-1/beqz-0), scalar s64 vs struct (struct fixes frame), pad190 fixes color offsets, decl-order flips (no move), s16->s32 return fixes dsll32/dsra32. Floor: register allocation + -1/0 materialization. */
// FUN_00348C40 NONMATCHING
#ifdef NON_MATCHING
s32 func_00348c40(u8 *arg0) {
    s32 i;
    s32 base;
    s32 r;
    s32 g;
    s32 b;
    u8 *slot;
    u8 *obj;
    Cmb48Work work;
    /* --- state dispatch: retail beq-1/beqz-0, ascending 0,1 switch gives it --- */
    obj = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)(obj + 1)) {
    case 0:
        /* --- init loop: 5 handles (offsets 4,8,C,10,14) --- */
        i = 0;
        while (i < 5) {
            /* handle create: 465,0 -> 5c90 */
            slot = obj + i * 4 + 4;
            func_002b2970(&work.s188, 0x1D1, 0.0f);
            *(s32 *)slot = func_002b5c90(arg0, work.s188);
            /* vec: 9.0,480.0 -> 5db0 */
            func_002b2970(&work.s180, 0x1D1, 0.0f);
            func_002b29e0(&work.v120, 9.0f, 480.0f);
            func_002b5db0(*(s32 *)slot, work.s180, &work.v120);
            /* color conditional: byte0==1 uses (i+2)*10 else gray */
            if (*(s8 *)obj == 1) {
                base = (i + 2) * 10;
                r = func_002b2cb0(base, 10, 0xFF, 0, 1) & 0xFF;
                g = func_002b2cb0(base + 0x37, 10, 0xFF, 0, 1) & 0xFF;
                b = func_002b2cb0(base + 0xF2, 10, 0xFF, 0, 1) & 0xFF;
                func_002b2a60(&work.c19C, r, g, b, 0xFF);
                func_002b5e30(*(s32 *)slot, work.c19C);
                if (i == 4) {
                    base = (i + 1) * 10;
                    r = func_002b2cb0(base, 10, 0xFF, 0, 1) & 0xFF;
                    g = func_002b2cb0(base + 0x37, 10, 0xFF, 0, 1) & 0xFF;
                    b = func_002b2cb0(base + 0xF2, 10, 0xFF, 0, 1) & 0xFF;
                    func_002b2a60(&work.c198, r, g, b, 0xFF);
                    func_002b5e30(*(s32 *)slot, work.c198);
                }
            } else {
                func_002b2a60(&work.c194, 0, 0x37, 0xF2, 0xFF);
                func_002b5e30(*(s32 *)slot, work.c194);
            }
            /* per-iteration tail: 0xBB + 50.0f */
            slot = obj + i * 4 + 4;
            func_002b6130(*(s32 *)slot, 0xBB);
            func_002b5e20(*(s32 *)slot, 50.0f);
            i++;
        }
        /* --- five post-loop 5fd0 groups --- */
        /* group offset 4: 465,275 + 8,480 + 380,480, last 0 */
        func_002b2970(&work.s178, 0x1D1, 0.0f);
        func_002b2970(&work.s170, 0x113, 0.0f);
        func_002b29e0(&work.v110, 8.0f, 480.0f);
        func_002b29e0(&work.v100, 380.0f, 480.0f);
        func_002b5fd0(*(s32 *)(obj + 4), work.s178, work.s170, &work.v110, &work.v100, 0xF, 0);
        /* group offset 8: same, last 2 */
        func_002b2970(&work.s168, 0x1D1, 0.0f);
        func_002b2970(&work.s160, 0x113, 0.0f);
        func_002b29e0(&work.vF0, 8.0f, 480.0f);
        func_002b29e0(&work.vE0, 380.0f, 480.0f);
        func_002b5fd0(*(s32 *)(obj + 8), work.s168, work.s160, &work.vF0, &work.vE0, 0xF, 2);
        /* group offset C: same, last 9 */
        func_002b2970(&work.s158, 0x1D1, 0.0f);
        func_002b2970(&work.s150, 0x113, 0.0f);
        func_002b29e0(&work.vD0, 8.0f, 480.0f);
        func_002b29e0(&work.vC0, 380.0f, 480.0f);
        func_002b5fd0(*(s32 *)(obj + 0xC), work.s158, work.s150, &work.vD0, &work.vC0, 0xF, 9);
        /* group offset 0x10: 8,480 + 8,480, last 9 */
        func_002b2970(&work.s148, 0x1D1, 0.0f);
        func_002b2970(&work.s140, 0x113, 0.0f);
        func_002b29e0(&work.vB0, 8.0f, 480.0f);
        func_002b29e0(&work.vA0, 8.0f, 480.0f);
        func_002b5fd0(*(s32 *)(obj + 0x10), work.s148, work.s140, &work.vB0, &work.vA0, 0xF, 9);
        /* group offset 0x14: 465,655 + 8,480 + 8,480, last 9 */
        func_002b2970(&work.s138, 0x1D1, 0.0f);
        func_002b2970(&work.s130, 0x28F, 0.0f);
        func_002b29e0(&work.v90, 8.0f, 480.0f);
        func_002b29e0(&work.v80, 8.0f, 480.0f);
        func_002b5fd0(*(s32 *)(obj + 0x14), work.s138, work.s130, &work.v90, &work.v80, 0xF, 9);
        *(s8 *)(obj + 1) = 1;
        break;
    case 1:
        /* --- state-1 check: 5th handle via 5da0, -1 if byte==1 else 0 --- */
        if (*(s8 *)func_002b5da0(*(s32 *)(obj + 0x14)) != 1) {
            return 0;
        }
        return -1;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_CmbCardEff", func_00348c40);
#endif

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
