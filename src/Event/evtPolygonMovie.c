#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtPolygonMovie.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef signed __int128 s128;

typedef struct {
    s128 a;
    s128 b;
} s2x128;

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern void func_002852a0(s32 arg0, s32 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_002909a0(s32 arg0);
extern void func_00290940(s32 arg0);
extern void func_00442088();
extern void func_0026c770(f32 *param_1, f32 *param_2, f32 *param_3);
extern void func_0026c680(f32 *param_1);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063C6A0[];
extern u8 D_0063C7A0[];
extern u8 D_0063C7C0[];
extern u8 D_0063C7E0[];
extern u8 D_0063C800[];
extern void (*jtbl_008873EC[])(void *ptr);
extern s128 D_0063C700;
extern s128 D_0063C710;
extern s128 D_0063C720[];
extern s128 D_0063C780;
extern s128 D_0063C790;

/* Without opt_loop_invariants the two lerp loops allocate the s2 value into
   $f0 (sub.s $f1,$f0,$f2, mtc1 $0,$f0 re-materialized inside the loop, madd.s
   result in $f0) vs retail's $f1 with the mtc1 hoisted to the preheader;
   expression variants (temps, product-first, (int)-cast addressing) never
   moved the allocation. measured: pragma on nd ~110 -> 0. */
#pragma opt_loop_invariants on

// FUN_0028F990
void func_0028f990(s32 arg0, f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3)
{
    f32 sp90[4];
    f32 sp80[4];
    f32 sp70[4];
    f32 sp60[4];
    f32 *var_16;
    f32 *var_18;

    var_18 = arg1;
    var_16 = arg3;
    if (var_16 == NULL) {
        func_0046d730(D_0063C6A0, 0x8F);
    }
    if (arg0 == 0) {
        fparg0 = 0.0f;
    }
    if (var_18 != NULL) {
        if (arg2 == NULL) {
            s32 var_5 = 6;

            do {
                s32 temp_4 = *(s32 *)var_18;
                s32 temp_3 = *(s32 *)(var_18 + 1);

                var_18 += 2;
                var_5 -= 1;
                *(s32 *)var_16 = temp_4;
                *(s32 *)(var_16 + 1) = temp_3;
                var_16 += 2;
            } while (var_5 > 0);
            return;
        }
        {
            s32 var_4;

            for (var_4 = 0; var_4 < 4; var_4++) {
                var_16[var_4 + 8] = var_18[var_4 + 8] + fparg0 * (arg2[var_4 + 8] - var_18[var_4 + 8]);
            }
        }
        {
            s32 var_4_2;

            for (var_4_2 = 0; var_4_2 < 4; var_4_2++) {
                var_16[var_4_2] = var_18[var_4_2] + fparg0 * (arg2[var_4_2] - var_18[var_4_2]);
            }
        }
        sp90[0] = var_18[4];
        sp90[1] = var_18[5];
        sp90[2] = var_18[6];
        sp80[0] = arg2[4];
        sp80[1] = arg2[5];
        sp80[2] = arg2[6];
        func_0026c770(&sp90[0], &sp80[0], &sp70[0]);
        sp60[0] = sp70[0] * fparg0 + var_18[4];
        sp60[1] = sp70[1] * fparg0 + var_18[5];
        sp60[2] = sp70[2] * fparg0 + var_18[6];
        func_0026c680(&sp60[0]);
        var_16[4] = sp60[0];
        var_16[5] = sp60[1];
        var_16[6] = sp60[2];
    }
}
#pragma opt_loop_invariants off

// FUN_0028FB90
u8 *func_0028fb90(void)
{
    u8 *work;

    func_0044ea90(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x114, 0x40000);
    func_002852a0(1, 0x114);
    if (work == NULL) {
        func_0046d730(D_0063C6A0, 0x12D);
        return NULL;
    }
    func_0043f9c8(work, 0, 0x114);
    return work;
}

/* measured, floor: 5 differing words over 4 fnalign edits, 522 emitted against
   retail's 522 (0.0%, 2096B against 2096B).  Levers that moved it:
   propagation-off copy locals recover retail's saved-register colouring
   (d2/d3/d4 = s5/s4/s3, idx = s2, c0/wk = s1/s0); declaring the switch
   scrutinee in a `code` local and the row base in b1/b2/b3 forces the
   retail lw-then-sll shape; source-order cases reversed against retail so
   b210 emits retail's descending beq chain; opt_loop_invariants on around
   the third loop hoists `addiu $v1, $zero, 4` into the preheader exactly
   as retail does (that pragma alone is worth 9 words: 14 -> 5, and it
   closes the 8-byte size gap, so the three shifted `b` targets vanish).
   WALL: the five parameter home moves.  b210 emits them in allocation
   order (a2, a3, t0, a0, a1 = s5, s4, s3, s1, s0); retail emits them in
   argument order (a0, a1, a2, a3, t0).  The colouring is already exact --
   only the emission order of the home block differs, and it is invariant
   under declaration order, initialiser-vs-assignment form, assignment
   order, K&R definition form, and direct-parameter-vs-copy models (all
   measured, all 5 words). Pragma re-probe on the 5wd body: propag removal
   202, loop-inv removal 14 (confirms 14 -> 5), cse-off 458, sched-on 489. */
/* measured: pair sweep 2026-09-17 `python3 -E -s tools/pragma_sweep.py src/Event/evtPolygonMovie.c func_0028fc40 --pairs` banked 5 (already carries opt_propagation off + opt_loop_invariants on); best 5 is the loop+propag pair reproducing the installed combo, so no new win. Stripped singles: propag-off alone 14 (+4 pairs 14), loop-inv alone 202 (+4 pairs 201-202), dead/strength/unroll/peephole singles + 6 pairs 209, commons block 455-458, schedule block 489-495. Confirms both installed pragmas load-bearing (5 -> 14 without loop, 5 -> 202 without propag). Home-move order wall stands at 522/522. */
/* 2026-09-18: the `opt_loop_invariants on` pragma now sits with the other
   pragma above the function instead of in the middle of the body.  b210
   applies optimization pragmas per function, and the two placements
   compile to the same bytes (measured, 5 words either way); removing the
   pragma costs 14, so it stays.  The 5 words are still the two parameter
   copies: retail saves $a0/$a1 before $a2/$a3/$t0, b210 after.  A
   twelve-local micro-experiment with the same declaration and assignment
   order emits retail's order, so the reordering is emergent from this
   body's register pressure, not from the declaration list. */
/* 2026-09-18 lead pass: the five words are one thing only, and it is not the
   register map.  Retail emits the five parameter saves in declaration order
   at offsets 8-12 (`move $s1,$a0; move $s0,$a1; move $s5,$a2; move $s4,$a3;
   move $s3,$t0`); this body emits the same five moves to the same five
   registers in first-use order (`$a2,$a3,$t0` first, because the first
   statement tests arg2).  All 522 instructions otherwise agree.
   Not reachable from source: copying every parameter into a local declared in
   order at the top of the body coalesces back into the same five moves and
   stays at 5.  Not reachable from pragmas either - `schedule off`,
   `opt_dead_assignments off`, `peephole off`, `opt_strength_reduction off`
   and `opt_unroll_loops off` all tie at 5 with a byte-identical stream, while
   `schedule on` costs 489 and `opt_common_subs off` 458.  The two pragmas
   already on the body stay load-bearing. */
// FUN_0028FC40 NONMATCHING
#ifdef NON_MATCHING
/* measured: propag-off above is load-bearing (removal 5 -> 202); the loop-invariants pair below closes 14 -> 5; body is 5wd exact at 522/522 instrs (2096B/2096B). */
#pragma opt_propagation off
#pragma opt_loop_invariants on
u8 *func_0028fc40(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4)
{
    u8 *d2;
    u8 *d3;
    u8 *d4;
    s32 idx;
    u8 *c0;
    u8 *wk;
    u8 *entry;
    s32 code;
    s32 k;
    u8 *b1;
    u8 *b2;
    u8 *b3;
    /* block-scope externs so this body drops into src/Event/evtPolygonMovie.c without file-scope changes (no sibling regression). */
    extern void func_0046d730(u8 *, s32);
    extern s32 func_00290880(u8 *, s32);
    extern void func_00440b68(u8 *, ...);
    extern u8 D_0063C6A0[];
    extern u8 D_0063C6C0[];
    extern u8 D_0063C6E0[];

    c0 = arg0;
    wk = arg1;
    d2 = arg2;
    d3 = arg3;
    d4 = arg4;
    if (d2 == NULL) {
        func_0046d730(D_0063C6A0, 0x155);
        return NULL;
    }
    *(s32 *)(wk + 0x110) = 0;
    *(u8 **)(wk + 0x10) = d2;
    *(u8 **)(wk + 0x14) = d2 + 0x20;
    *(s32 *)(wk + 0x18) = 0;
    *(s32 *)(wk + 0x1C) = 0;
    *(s32 *)(wk + 0x20) = 0;
    *(s32 *)(wk + 0x24) = 0;
    *(s32 *)(wk + 0x28) = 0;
    *(s32 *)(wk + 0x2C) = 0;
    *(s32 *)(wk + 0x30) = 0;
    *(s32 *)(wk + 0x34) = 0;
    *(s32 *)(wk + 0x38) = 0;
    *(s32 *)(wk + 0x3C) = 0;
    *(s32 *)(wk + 0x40) = 0;
    *(s32 *)(wk + 0x44) = 0;
    *(s32 *)(wk + 0x48) = 0;
    *(s32 *)(wk + 0x50) = 0;
    *(s32 *)(wk + 0x4C) = 0;
    *(s32 *)(wk + 0x54) = 0;
    *(s32 *)(wk + 0x58) = 0;
    *(s32 *)(wk + 0x5C) = 0;
    for (idx = 0; idx < *(s32 *)(*(u8 **)(wk + 0x10) + 0x10); idx++) {
        b1 = *(u8 **)(wk + 0x14);
        entry = b1 + idx * 0x10;
        code = *(s32 *)entry;
        if (code == 0x1B) {
            continue;
        }
        switch (code) {
        case 2:
            *(u8 **)(wk + 0x20) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x24) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 10:
            *(u8 **)(wk + 0x28) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 11:
            *(u8 **)(wk + 0x2C) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 12:
            *(u8 **)(wk + 0x30) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 3:
            *(u8 **)(wk + 0x34) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x38) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 9:
            *(u8 **)(wk + 0x3C) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 1:
            *(u8 **)(wk + 0x18) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x1C) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 6:
            *(u8 **)(wk + 0x4C) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x50) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 7:
            *(u8 **)(wk + 0x40) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x44) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 8:
            *(u8 **)(wk + 0x48) = d2 + *(s32 *)(entry + 0xC);
            break;
        case 22:
            *(u8 **)(wk + 0x54) = d2 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x58) = *(s32 *)(*(u8 **)(wk + 0x14) + idx * 0x10 + 8);
            break;
        case 23:
            *(u8 **)(wk + 0x5C) = d2 + *(s32 *)(entry + 0xC);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x1C3);
            break;
        }
    }
    *(u8 **)(wk + 0x80) = d3;
    if (d3 != NULL) {
        *(u8 **)(wk + 0x84) = d3 + 0x20;
    } else {
        *(s32 *)(wk + 0x84) = 0;
    }
    *(s32 *)(wk + 0x88) = 0;
    *(s32 *)(wk + 0x8C) = 0;
    *(s32 *)(wk + 0x90) = 0;
    *(s32 *)(wk + 0x94) = 0;
    *(s32 *)(wk + 0xAC) = 0;
    *(s32 *)(wk + 0xB0) = 0;
    *(s32 *)(wk + 0xB4) = 0;
    *(s32 *)(wk + 0xB8) = 0;
    *(s32 *)(wk + 0xBC) = 0;
    *(s32 *)(wk + 0xC0) = 0;
    *(s32 *)(wk + 0xC4) = 0;
    *(s32 *)(wk + 0xC8) = 0;
    *(s32 *)(wk + 0xCC) = 0;
    *(s32 *)(wk + 0xD0) = 0;
    *(s32 *)(wk + 0xD4) = 0;
    *(s32 *)(wk + 0xD8) = 0;
    *(s32 *)(wk + 0xDC) = 0;
    *(s32 *)(wk + 0xE0) = 0;
    *(s32 *)(wk + 0xE4) = 0;
    *(s32 *)(wk + 0xE8) = 0;
    *(s32 *)(wk + 0xEC) = 0;
    *(s32 *)(wk + 0xF0) = 0;
    *(s32 *)(wk + 0xF4) = 0;
    *(s32 *)(wk + 0x100) = 0;
    *(s32 *)(wk + 0x104) = 0;
    *(s32 *)(wk + 0xF8) = 0;
    *(s32 *)(wk + 0xFC) = 0;
    *(s32 *)(wk + 0x108) = 0;
    *(s32 *)(wk + 0x10C) = 0;
    *(s32 *)(wk + 0x60) = 0;
    *(s32 *)(wk + 0x64) = 0;
    if (d3 == NULL) {
        return wk;
    }
    func_00440b68(D_0063C6C0, *(s32 *)(*(u8 **)(wk + 0x80) + 0x10));
    for (idx = 0; idx < *(s32 *)(*(u8 **)(wk + 0x80) + 0x10); idx++) {
        b2 = *(u8 **)(wk + 0x84);
        entry = b2 + idx * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 0:
            *(u8 **)(wk + 0x90) = d3 + *(s32 *)(entry + 0xC);
            break;
        case 4:
            if (*(s32 *)(*(u8 **)(wk + 0x80) + 0x14) == 4) {
                *(u8 **)(wk + 0x94) = d3 + *(s32 *)(entry + 0xC);
                *(s32 *)(wk + 0x98) = 0;
            } else {
                *(u8 **)(wk + 0x98) = d3 + *(s32 *)(entry + 0xC);
                *(s32 *)(wk + 0x94) = 0;
            }
            *(s32 *)(wk + 0xAC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 1:
            *(u8 **)(wk + 0x88) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x8C) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 5:
            *(u8 **)(wk + 0xB0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xB4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 13:
            *(u8 **)(wk + 0xB8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xBC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 14:
            *(u8 **)(wk + 0xC0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xC4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 15:
            *(u8 **)(wk + 0xC8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xCC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 16:
            *(u8 **)(wk + 0xD0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xD4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 17:
            *(u8 **)(wk + 0xD8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xDC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 18:
            *(u8 **)(wk + 0xE0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xE4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 19:
            *(u8 **)(wk + 0xE8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xEC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 20:
            *(u8 **)(wk + 0xF0) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xF4) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 24:
            *(u8 **)(wk + 0xF8) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xFC) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 21:
            *(u8 **)(wk + 0x100) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x104) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            func_00440b68(D_0063C6E0);
            break;
        case 25:
            *(u8 **)(wk + 0x108) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x10C) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        case 26:
            *(u8 **)(wk + 0x60) = d3 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0x64) = *(s32 *)(*(u8 **)(wk + 0x84) + idx * 0x10 + 8);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x24D);
            break;
        }
    }
    if (*(u8 **)(wk + 0x90) != NULL) {
        if (*(u8 **)(wk + 0x4C) != NULL && *(s32 *)(wk + 0x50) > 0) {
            func_00290880(c0, *(s32 *)(wk + 0x4C));
        }
    }
    *(u8 **)(wk + 0x9C) = d4;
    if (d4 != NULL) {
        *(u8 **)(wk + 0xA0) = d4 + 0x20;
    } else {
        *(s32 *)(wk + 0xA0) = 0;
    }
    *(s32 *)(wk + 0xA4) = 0;
    *(s32 *)(wk + 0xA8) = 0;
    if (d4 == NULL) {
        return wk;
    }
    for (k = 0; k < *(s32 *)(*(u8 **)(wk + 0x9C) + 0x10); k++) {
        b3 = *(u8 **)(wk + 0xA0);
        entry = b3 + k * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 4:
            *(u8 **)(wk + 0xA4) = d4 + *(s32 *)(entry + 0xC);
            *(s32 *)(wk + 0xA8) = *(s32 *)(*(u8 **)(wk + 0xA0) + k * 0x10 + 8);
            break;
        default:
            break;
        }
    }
    return wk;
}
#pragma opt_loop_invariants off
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/evtPolygonMovie", func_0028fc40);
#endif

// FUN_00290470
void func_00290470(s32 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        if (func_002909a0(arg1) == 1) {
            func_00290940(arg1);
        }
        jtbl_008873EC[0](arg0);
        func_002852a0(1, -0x114);
    }
}

// FUN_002904F0
s32 *func_002904f0(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C700;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(4, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_002905A0
s32 *func_002905a0(s32 **arg0)
{
    u8 sp30[0x54];
    s128 *src;
    s128 *dst;
    s32 count;
    s32 *temp;

    src = &D_0063C720[0];
    dst = (s128 *)&sp30[0];
    count = 5;
    do {
        s128 temp;

        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    *(f32 *)dst = *(f32 *)src;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x54, 0x40000);
    func_002852a0(5, 0x54);
    func_0043f810(temp, &sp30[0], 0x54);
    *arg0 = temp;
    return temp;
}

// FUN_00290660
s32 *func_00290660(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C780;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(6, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_00290710
void func_00290710(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5)
{
    s32 temp;

    if (arg2 == 0) {
        func_0046d730(D_0063C6A0, 0x36B);
    }
    if (arg3 == 0) {
        func_0046d730(D_0063C6A0, 0x36C);
    }
    if (arg4 == 0) {
        func_0046d730(D_0063C6A0, 0x36D);
    }
    if (arg5 == 0) {
        func_0046d730(D_0063C6A0, 0x36E);
    }
    temp = (arg0 / 10) * 10;
    func_00442088(arg2, D_0063C7A0, temp, arg0, arg1);
    func_00442088(arg3, D_0063C7C0, temp, arg0, arg1);
    func_00442088(arg4, D_0063C7E0, temp, arg0, arg1);
    func_00442088(arg5, D_0063C800, temp, arg0, arg1);
}
