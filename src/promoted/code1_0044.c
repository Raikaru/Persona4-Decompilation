#include "include_asm.h"
#include "type.h"
/* Toolchain-blocked: retail saves callee-saved registers with sd; MWCCPS2 3.0.1 emits sq. See build/ORCH_sd_toolchain_blocked.txt. */

s32 func_004447f8();
s32 func_00444870();
s32 func_00421da8();
s32 func_0044a138();
f32 func_0044b018(s32 arg0, f32 fparg0, f32 fparg1);
extern s32 D_009389E0[];
s32 kwlnTaskGetCurrent(void);
s32 func_0044d4d0();
u64 func_00443fd0(s32 *arg0, s8 *arg1, s8 **arg2, s16 arg3);

typedef struct {
    u8 *unk0;      /* 0x0 */
    s32 unk8;      /* 0x8 */
    s16 unkC;      /* 0xC */
    u8 *unk10;     /* 0x10 */
    s32 unk14;     /* 0x14 */
    u8 pad18[0x3C];
    u8 *unk54;     /* 0x54 */
} Mesh048;

typedef struct E8Node E8Node;
typedef struct {
    E8Node *first;
    E8Node *last;
    E8Node *current;
    u8 padC[0xC];
    s32 count;
    s32 total;
    u8 pad20[0x10];
    s32 (*fn_30)(void);
} E8Pool;
struct E8Node {
    E8Node *next;
    E8Node *prev;
};
extern E8Pool *D_00763D1C;
extern s32 *D_00710070[];
extern s32 (*D_008BE290[])(u32);
extern void (*D_008BE294[])(u8 *);
extern s32 (*D_008BE298[])(void *, u32);
extern s32 (*D_008BE29C[])(s32, s32);
s32 chkmemAllocate(u32);
void chkmemFree(u8 *);
s32 chkmemReallocate(void *, u32);
s32 chkmemAllocZeroed(s32, s32);
s32 func_0044f4d0(void);
s32 func_00446108();

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00446108 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

s64 func_004470f0(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004470f0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
/* measured: nd 45 against retail's 88-byte object. Retail builds a partially
   initialised 0x58-byte record at the frame base and hands its address to
   func_004447f8; b210 lays the same struct out at frame offset 0x20, so every
   store and the argument setup are displaced. Probed a bare local struct
   (mwccps2 rejects a struct type defined inside a function), the file-scope
   Mesh048 typedef used here, individual scalar locals (dead-store eliminated
   down to one), and taking the address of the first member instead of the
   struct. Committed at nd 45. */

// FUN_004420F8
s32 func_004420f8(void) {
    return 0;
}

/* measured: strstr.  Object 23 instrs against retail 22 (diff 1, INSIDE the*/
/* 2-instr slack a 22-instruction function gets under the +-3% gate), 22*/
/* differing words, 19 edits.  Improved from 25 instrs / 24 words / 21 edits*/
/* by fixing BOTH back-edges at once (see below).  Re-measured 2026-09-20:*/
/*  - entry: all 7 spellings re-probed on this body.  `return (*arg1 == 0) ?*/
/*    result : NULL;` ties best at 22 words; `if (*arg1 != 0) result = NULL;*/
/*    return result;` is worst (30 words on this body, 28 instrs on the old*/
/*    body - the old note's "32 instrs" was the pre-hoist body, direction*/
/*    still holds).  Reversing the ternary costs 1 word (22->23); `(s8 *)0`*/
/*    for NULL, two-return, and temp forms tie at 22.  Retail's*/
/*    `lb $t7,($a1)` / `jr $ra` / `movn $v0,$zero,$t7` stays +2 real (+1*/
/*    window): b210 never emits `movn` from any spelling (b119 does emit it*/
/*    but schedules worse at 26 instrs with delay nops, measured via direct*/
/*    mwccgap runs), so the branchless select is the remaining wall.*/
/*  - body: hoisting `p2 = result + counter;` above the `c1 == 0` test saves*/
/*    1 (B1 without hoist: 25 words vs 24), reproducing retail's*/
/*    `beqz` delay `addu $t6,$v0,$t4` exactly - prior diagnosis verified.*/
/*  - back-edges: base used `if (c1 == c2)` + `if (*result != 0)` with a*/
/*    shared `result = NULL; done:` tail (25 instrs).  B2 (early*/
/*    `return NULL;`) fixes the OUTER edge to retail's `bnel` + delay*/
/*    `move $t4,$zero` with fall-through NULL (24 instrs, 23 words); L1*/
/*    (`if (c1 != c2)` mismatch block) fixes the INNER edge to `beql` + delay*/
/*    `addiu $t4,1` with fall-through `addiu $v0,1` (24 instrs, 23 words).*/
/*    C1 combines both (`if (c1 != c2) { result++; if (*result == 0) return*/
/*    NULL; counter = 0; goto inner; } counter++; goto inner;`) for 23*/
/*    instrs / 22 words / 19 edits.  The compiler merges the two returns*/
/*    into retail's single shared `jr`, so the early `return NULL` costs no*/
/*    extra epilogue.*/
/*  - pragmas on C1: `#pragma no_branch_likely on` -> 31 words (far worse,*/
/*    prior "31 instrs" verified); `#pragma schedule on` and*/
/*    `#pragma opt_propagation off` -> 22 words each (neutral, verified).*/
/*  - decl order (4 rotations) and `char`/`int` for `s8`/`s32` -> all 22*/
/*    words (neutral).  Native smoke vs libc strstr passes 99*/
/*    haystack/needle cases for both base and C1.*/
// FUN_00443010 NONMATCHING
#ifdef NON_MATCHING
s8 *func_00443010(s8 *arg0, s8 *arg1) {
    s32 counter;
    s8 *result;
    s8 *p2;
    s8 c1;
    s8 c2;

    result = arg0;
    if (*arg0 == 0) {
        return (*arg1 == 0) ? result : NULL;
    }
    counter = 0;
inner:
    c1 = arg1[counter];
    p2 = result + counter;
    if (c1 == 0) {
        goto done;
    }
    c2 = *p2;
    if (c1 != c2) {
        result++;
        if (*result == 0) {
            return NULL;
        }
        counter = 0;
        goto inner;
    }
    counter++;
    goto inner;
done:
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00443010);
#endif

/* measured: 15 differing words, object 17 instrs / retail 17, exact count (third-party unit, so floorboard/opclass skip it). Control shape matches (delay-slot move, shared epilogue); residual is frame/saves and lw/sw register picks. Tried: loc/tag-hoist respelling (16 edits, neutral), all 8 singles + all 28 pragma pairs (all 15; peephole off 17). Retail saves $s0 with sd, b210 emits sq (file-top toolchain note): ~6 save/frame words permanently blocked. */
// FUN_00444700 NONMATCHING
#ifdef NON_MATCHING
s32 __sprint(u8 *arg0, u8 *arg1) {
    extern s32 __sfvwrite(u8 *arg0, u8 *arg1);
    s32 result;

    if (*(s32 *)(arg1 + 8) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return 0;
    }
    result = __sfvwrite(arg0, arg1);
    *(s32 *)(arg1 + 4) = 0;
    *(s32 *)(arg1 + 8) = 0;
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_00444700);
#endif

/* measured: nd 83 against retail's 112-byte object (object_size 104/112).
   Retail reads the incoming float's bits via `mfc1 $t7,$f12` then `and`s with
   0x7FFFFFFF and does an integer `slt` against 0x3F490FDA (pi/4) to pick the
   reduction path. b210 will NOT emit that mfc1 from any reinterpret idiom --
   *s32*&x, a union, u32 casts all compile to a stack round-trip
   (swc1/lw + dsll32/dsrl32 sign-extend) -- and fabsf() inlines to abs.s with a
   float c.le.s compare instead of the integer path. On top of that the local
   f32[2] reduction buffer lands at frame offset 0x18 where retail puts it at
   the frame base (the same aggregate-frame-displacement wall as the parked
   func_00446ed8 / func_00446f30), shifting every lwc1 and the arg setup.
   Probed mfc1 idioms (pointer/union/u32/direct), fabsf with a declared
   prototype, comparison polarity (>, >=, constant-left, <=/inv), shared-call
   vs two-return layout, and function-scope vs if-scope local array. Committed
   at nd 83.
   Committed at nd 83. */

#pragma pop

s32 func_00447b88(s64 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447b88 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

s32 func_00447d00(s64 arg0, s32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00447d00 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00448d10(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00448d10 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449120(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449120 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_004494b8(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_004494b8 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449680(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449680 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 func_00449938(f32 arg0, f32 arg1);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_00449938 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

f32 __ieee754_sqrtf(f32 arg0);

/* measured: retail is a frame'd tail jump (addiu $sp,-0x10 / sd $ra /
 * ld $ra / j func_0044a4d0 / addiu $sp,0x10 in the delay slot). b210's
 * tailcall pass collapses any unconditional tail call to a bare `j` and
 * never allocates the frame; no pragma/flag/structure combination
 * reproduces the frame'd shape (probed O2/O3/O4, schedule, tailcall,
 * opt_* pragmas, forced-frame locals, conditional/loop/goto variants).
 * Best achievable: bare tail jump, nd 18 -> 2 -> NONMATCHING floor. */

#pragma push
#pragma schedule on
#pragma tailcall on
#pragma pop

// Kept here so this multi-run bucket stays link-eligible (has_first_party); see tools/build.py eligible_c_objects.
// FUN_0044F4D0
s32 func_0044f4d0(void) {
    s32 temp;
    temp = kwlnTaskGetCurrent();
    if (temp != 0) {
        return temp;
    }
    return 0;
}
