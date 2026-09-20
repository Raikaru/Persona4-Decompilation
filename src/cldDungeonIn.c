/* Consolidated Persona 4 source units. */
/* Original translation unit cldDungeonIn.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

extern u8 *func_00452560();
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00268230(void *unused, void *task);
extern u8 D_007964F0[];
extern void func_002e1ef0(void *a);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0045a8d0(s32 a, s32 b);
extern void func_00106390(s32 a, s32 b);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_0044ea90(const void *msg, s32 id);
extern u8 *func_002e1db0(s32 a, s32 b, s32 c, s32 d);
extern void func_0045b2e0(s32 a);
extern u8 D_00638FC0[];
extern u8 D_0063B070[];

s32 func_00268870(u8 *arg0);
void func_00268920(u8 *task);

// FUN_00268920
void func_00268920(u8 *unusedTask) {
    u8 *s0 = func_00452560();
    func_002e1ef0((void *)**(s32 **)(s0 + 8));
    jtbl_008873EC[0](s0);
    func_0045a8d0(3, 0);
    func_00106390(0x1470, 0);
}

/* measured: retail dispatch is beq 3,2,1,0 (state 3 -> -1, else 0) with body
   layout [-1 body first, 0 body second]. mwcc b210 linear-chain switch emits
   TESTS in reverse of declaration order but BODIES in declaration order, so the
   two are mutually exclusive here: declaring [0,1,2,3] gives test [3,2,1,0]
   (correct) but body [0,3] (wrong, nd 18); declaring [3,0,1,2] gives body
   [3,0] (correct) but test [2,1,0,3] (wrong, nd 8). if/else-if chains give
   inline bne (not out-of-line beq), and if+switch / two-switch splits collapse
   the all-return-0 sub-switch into a single return 0. Best nd 8. */
// FUN_00268870
s32 func_00268870(u8 *arg0)
{
    u8 *state;
    u8 *obj;

    state = func_00452560();
    obj = func_00460990();
    *(void **)(obj + 8) = (void *)func_00268230;
    *(u8 **)(obj + 0x10) = arg0;
    func_00460ac0(D_007964F0, obj);
    switch (*(s32 *)state) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        return -1;
    }
    return 0;
}
// FUN_00268990
s32 func_00268990(s32 arg0) {
    u8 *s0;
    u8 *v0;
    u8 **v1;
    s32 ret;

    func_0044ea90(D_00638FC0, 0x33D);
    s0 = D_008873F4[0](1, 0xC, 0x40000);
    *(s32 *)s0 = 0;
    v0 = func_002e1db0(0x10, 0, 0, 0);
    v1 = *(u8 ***)(v0 + 0x24);
    *v1 = v0;
    *(u8 ***)(s0 + 8) = v1;
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063B070), 0xF, 0, 0, func_00268870, func_00268920, (u8 *)(s0));
    func_0045b2e0(0x40);
    func_00106390(0x1470, 1);
    return ret;
}

/* measured: 1600B state-machine (switch on work->state, cases 0/1/2/default).
   Case 1 embeds a PS2 FPU multiply-accumulate polynomial chain that m2c cannot
   decode (M2C_ERROR): mula.s $f0,$f1 / madda.s $f14,$f2 / madda.s $f3,$f4 /
   madd.s $f2,$f8,$f5 computes f16 = f6*(f0*f1 + f14*f2 + f3*f4 + f8*f5) feeding
   func_00267b20's 12 args. Heavy register pressure (8 saved regs + $f20), a
   0x169-word D_0063AAB0 copy loop, a nested 0x13-iteration node loop with
   func_002e2170, and the 0x4F000000 range-guard (f32)(s32) idiom in case 2.
   The m2c draft is not compilable (M2C_ERROR blocks); full reconstruction not
   attempted beyond FPU decode. */
/* measured: candidate object 399 instrs/retail 399 instrs (1596B/1600B, 1 short), probe reloc-masked 12 words (guard below, NON_MATCHING so production stays ASM; fnalign 20 edits +19 reloc-only). Earliest hunks are lwc1 GP-relative pool offsets and D_0063AA80 lq vs immediate color/rect construction; insert at 288 is extra 0043f810 call block. Within 12-variant probe budget for future closing. Banked as floor. Pairs 2026-09-17 (`tools/pragma_sweep.py --pairs`, 8 singles + 28 pairs, banked 12): ties at 12 among dead_off/loopinv/strength_off/unroll_off + 6 pairs among them; peephole 286, cse_off 370, sched 374, prop 423 (pairs 286-441). No pair beats the singles; opclass clean, floor stands. */
/* 2026-09-18 lead pass, 7 measured variants, floor confirmed at 12 words.
   The residual is one address: retail computes `addiu $s4, $v0, 0xd0` before
   the third `func_0043f810` call and derives the fourth destination from it
   (`addiu $s1, $s4, 0x1c`), where this body recomputes both from the node
   base after the call.  Same CSE-versus-rematerialise family as 7h-ter.
   The repeated `entries[i].current` subscript in the two middle copies is
   LOAD-BEARING and must not be tidied: hoisting it into a local costs
   12 -> 373, and using `entry->current` instead costs 12 -> 375.  Inlining
   the `initial`/`target` locals back into their calls costs 12 -> 379, and
   dropping the `entry` pointer entirely costs 12 -> 21.  Spelling the three
   scalar reads as `entries[i].mode/.duration/.kind` costs 12 -> 14; spelling
   `initial`/`target` that way ties at 12.
   In short the body is at a local optimum in every direction tried; only the
   pre-call address survives. */
/* 2026-09-18 section 7o pass, 8 measured variants, floor stands at 12 words.
   `tools/residual_signature.py src/cldDungeonIn.c func_00268230` prints
   20 edits with 0 mask/0 cvt/0 class/0 perm/6 other and an empty mapping:
   there is no exchanged pair to name. `tools/measure_guarded.py` confirms
   12 reloc-masked words at +1152..+1200: retail hoists the entry-base
   `addiu $s4, $v0, 0xd0` above the third `func_0043f810` call and derives
   `addiu $s1, $s4, 0x1c` from it, where this body sinks the recompute below
   the call (`addiu $v0, $v0, 0xd0` / `addiu $s1, $v0, 0x1c`). Address
   CSE-versus-rematerialise across a call, not a 7m/7o register exchange.
   Probed the closest 7o-shaped pair anyway (`f32 *initial` / `f32 *target`,
   both uninitialised and assigned as statements) in one batched
   `tools/probe_variants.py` call (8 candidates): v1 FF retail 12 (tie),
   v2 FF rev 64, v3 FB retail 12 (tie), v4 FB rev 64, v5 BF retail 63,
   v6 BF rev 19, v7 BB retail 12 (tie), v8 BB rev 64. Scopes: F=function top,
   B=inside `for (i...)` body; retail order `initial` then `target`, rev the
   reverse. No variant beats 12; the three ties confirm the current
   function-scope retail-order spelling. */
/* measured 2026-09-19 (lead): object 399 instrs against retail 399, exact,
   12 differing words, 20 edits plus 19 reloc-only - one of the closest
   first-party floors in the tree.  The whole residual is one instruction's
   position: retail computes `addiu $s4, $v0, 0xd0` *before* the third
   `func_0043f810` call and derives `$s1, $s4, 0x1c` from it, where b210 sinks
   the recompute below the call.
   Hoisting it in source makes things dramatically worse, which is worth
   recording so nobody repeats it: naming `entry->current` in a local and
   passing that to both the third and fourth calls scores 374, and writing
   `entry->current` instead of `entries[i].current` scores 375, against 12 for
   the form below.  The array-subscript spelling is load-bearing.  Eight scope
   variants tie at 12 (see the earlier note); only the pre-call address
   placement survives as a difference. */
// FUN_00268230 NONMATCHING
#ifdef NON_MATCHING
typedef struct DungeonInColor { u8 r, g, b, a; } DungeonInColor;
typedef struct DungeonInRect { s32 x, y, width, height; } DungeonInRect;
typedef struct DungeonInEntry {
    u32 kind;
    f32 duration;
    u32 mode;
    f32 initial[4];
    f32 current[4];
    f32 previous[4];
    f32 target[4];
} DungeonInEntry;
typedef struct DungeonInNodeWork {
    u32 flags;
    u32 kind;
    u32 unknown08;
    u32 mode;
    f32 unknown10;
    f32 duration;
    f32 initial[4];
    f32 current[4];
    f32 previous[4];
    f32 target[4];
} DungeonInNodeWork;
typedef struct DungeonInList {
    u32 unknown00[4];
    u16 count;
} DungeonInList;
typedef struct DungeonInNode {
    u32 unknown00[5];
    DungeonInNodeWork *work;
} DungeonInNode;
typedef struct DungeonInWork {
    s32 state;
    s32 frame;
    DungeonInList **list;
} DungeonInWork;
extern void func_0045d6e0(void *, void *, f32, s32);
extern void func_001228a0(s32, s32, s32);
extern void func_00267b20(f32, f32, f32, u32, u8, s32, s32, s32, s32, f32, f32, f32);
extern void func_0025ea20(f32, f32, f32, u32, u8, s32, void *, s32, s32, s32, f32, f32, f32);
extern void *func_0046a770(const void *);
extern DungeonInNode *func_002e2170(DungeonInList *, s32, s32);
extern void func_0046d730(const void *, s32);
extern void *func_0043f810(void *, const void *, u32);
extern void func_00267670(DungeonInList **);
extern u8 D_005E5810[];

static inline f32 dungeonInBezier(f32 t, f32 start, f32 control1, f32 control2, f32 end)
{
    f32 u = 1.0f - t;
    f32 threeU = 3.0f * u;
    return start * (u * (u * u)) + control1 * (t * (threeU * u))
         + control2 * (t * (threeU * t)) + end * (t * (t * t));
}

void func_00268230(void *unused, void *task)
{
    DungeonInColor color;
    DungeonInRect rect;
    DungeonInWork *work;
    s32 alpha;
    s32 frame;
    u32 i;
    f32 t, curve;
    DungeonInEntry *entry;
    DungeonInNodeWork *nodeWork;
    f32 *initial;
    f32 *target;
    u32 kind, mode;
    f32 duration;

    work = (DungeonInWork *)func_00452560(task);
    switch (work->state) {
    case 0:
        {
            color = (DungeonInColor){0, 0, 0, 255};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0(&color, &rect, 0.0f, 1);
        }
        if (++work->frame >= 15) {
            work->frame = 0;
            work->state = 1;
            func_001228a0(196, 196, 196);
        }
        break;
    case 1:
        {
            color = (DungeonInColor){0, 0, 0, 255};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0(&color, &rect, 0.0f, 1);
        }
        frame = ++work->frame;
        if (frame < 41) {
            t = (f32)frame / 40.0f;
            curve = dungeonInBezier(t, 0.0f, 0.01f, 0.1f, 1.0f);
            func_00267b20(288.0f, 222.0f, 0.0f, 0xC4C4C4, 255,
                          1, 9, 0, 0, 0.0f + -45.0f + 70.0f * curve,
                          3.0f * curve, 3.0f * curve);
        } else {
            if (frame < 133) {
                color = (DungeonInColor){196, 196, 196, 255};
            } else {
                color = (DungeonInColor){196, 196, 196, 255};
            }
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0(&color, &rect, 0.0f, 1);
        }
        alpha = 0;
        if (work->frame < 36) {
            alpha = 0;
        } else if (work->frame < 66) {
            alpha = (s32)((f32)(255 * (work->frame - 35)) / 30.0f);
        } else if (work->frame < 121) {
            alpha = 255;
        } else if (work->frame < 131) {
            alpha = (s32)(255.0f * (1.0f - (f32)(work->frame - 120) / 10.0f));
        }
        func_0025ea20(28.0f, -38.0f, 0.0f, 0xFFFFFF, (u8)alpha, 75,
                      func_0046a770(D_005E5810), 1, 0, 0, 0.0f,
                      15.999990f, 15.999f);
        if (work->frame == 17) {
            DungeonInEntry entries[19] = {
                {18, 30.0f, 0, {0.0f, 0.0f, 60.0f, 0.0f}, {0.0f, 0.0f, 60.0f, 0.100000001f}, {0.0f, 0.0f, 60.0f, 0.100000001f}, {0.0f, 0.0f, 60.0f, 7.0f}},
                {0, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {1, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {2, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {3, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {4, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {5, 30.0f, 0, {0.0f, 0.0f, 45.0f, 0.0f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {6, 20.0f, 0, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {7, 20.0f, 0, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.00999999978f}, {0.0f, 0.0f, 45.0f, 0.100000001f}, {0.0f, 0.0f, 45.0f, 7.0f}},
                {10, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {11, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {12, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {13, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {14, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {15, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {16, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {17, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {9, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}},
                {8, 20.0f, 0, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.00999999978f}, {0.0f, 0.0f, 0.0f, 0.100000001f}, {0.0f, 0.0f, 0.0f, 7.0f}}
            };
            for (i = 0; i < 19; i++) {
                entry = &entries[i];
                mode = entry->mode;
                duration = entry->duration;
                kind = entry->kind;
                nodeWork = func_002e2170(*work->list, (*work->list)->count + 1, 0x58)->work;
                nodeWork->flags |= 1;
                if (nodeWork == NULL) func_0046d730(D_00638FC0, 86);
                initial = entry->initial;
                if (initial == NULL) func_0046d730(D_00638FC0, 87);
                target = entry->target;
                if (target == NULL) func_0046d730(D_00638FC0, 88);
                nodeWork->kind = kind;
                nodeWork->duration = duration;
                nodeWork->mode = mode;
                func_0043f810(nodeWork->initial, initial, 16);
                func_0043f810(nodeWork->current, entries[i].current, 16);
                func_0043f810(nodeWork->previous, entries[i].current, 16);
                func_0043f810(nodeWork->target, target, 16);
            }
        }
        func_00267670(work->list);
        if (work->frame >= 170) {
            work->frame = 0;
            work->state = 2;
        }
        break;
    case 2:
        t = (f32)work->frame / 20.0f;
        {
            color = (DungeonInColor){196, 196, 196, (u8)(255.0f * (1.0f - t))};
            rect = (DungeonInRect){0, 0, 640, 480};
            func_0045d6e0(&color, &rect, 0.0f, 1);
        }
        if (++work->frame >= 20) {
            work->state = 3;
            work->frame = 0;
        }
        break;
    case 4:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cldDungeonIn", func_00268230);
#endif
