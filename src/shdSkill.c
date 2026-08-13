#include "include_asm.h"
#include "type.h"
typedef struct {
    f32 x;
    f32 y;
} Vec2f;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} Color4;
static inline u8 *shdSkill_addOff(s32 offset, u8 *base) {
    return (u8 *)(offset + (s32)base);
}

u16 func_00115750(u8 *arg0);
void func_0046d730(void *file, s32 line);
void func_00115670(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s64 func_0023d8e0(u32 arg0, u16 arg1);
extern char D_005E4800[];
extern char D_005E47F0[];
void *func_00243840(u16 arg0);
void func_00275020(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7, s32 arg8);
void func_0046d4c0(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, f32 arg9, s32 arg10);
extern char D_005E5830[];
extern char D_005E5850[];
void func_002bc860(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_0046a770(const char *file);
void func_00274ed0(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
void func_001138c0(s64 arg0, u8 arg1, s16 *arg2, f32 arg3);

// FUN_001138C0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_001138c0);

/* measured: re-confirmed nd 5 this wave (reloc-masked; probe_variants reports
   11 unmasked) with the m2c-faithful 9-arg 275020 spelling -- the only
   residual is (a) prologue save order: retail `sd $a0,0x48; mov.s $f20,$f12;
   move $s1,$a1; move $s0,$a2`, mwcc groups `[GPR callee-saves, FP
   callee-saves, spills]` = `move $s1; move $s0; mov.s $f20; sd $a0` (same
   grouping floor as func_00114dc0), and (b) `mov.s $f14,$f20` deferred past
   the a2/a3/t0/t1 setup (retail emits it right after the lb $a1). Everything
   else byte-identical (243840 nested call, cvt pairs into f12/f13, the
   x*255/255U divu + |~0xFF chain, lh->sll->D_005E47F0 byte index). Probed
   this wave: z/sp48 assignment orders, arg1/arg2 locals, lo/hi locals -- all
   nd 5/11. prologue/FP-arg save-order floor. */
/* measured: MATCH, object 184/192. The cluster's float-first interleaving and callee-first local evaluation reproduce the retail body; the remaining 8 bytes are zero tail padding accepted by the verifier. */
// FUN_00113E30
void func_00113e30(Vec2f arg0, f32 fparg0, u8 arg1, void *arg2, s32 arg3) {
    f32 farg;
    s32 color;
    s32 index;
    void *temp;

    farg = fparg0;
    temp = func_00243840(*(u16 *)((u8 *)arg2 + 0xA));
    color = (((arg1 & 0xFF) * 0xFF) / 255U) | ~0xFF;
    index = *((s8 *)((s32)&D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2)));
    func_00275020((f32)(s32)arg0.x,
                  (f32)(s32)arg0.y,
                  farg,
                  color,
                  index,
                  1,
                  temp,
                  8,
                  -1);
}

/* measured: plain-C reconstruction attempt for the ordinary adda.s/madd.s
   color interpolation reached nd 1083 (object 1456/1392) and was discarded:
   the candidate's frame was 0xE0 versus retail 0xF0 and the saved-register
   allocation diverged before the first call. No body is kept; rebuild this
   target from retail rather than treating the measurement as a floor. */
// FUN_00113EF0
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00113ef0);

// FUN_00114460
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00114460);

// FUN_00114CB0
s32 func_00114cb0(u16 arg0) {
    s16 temp_2;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        return 0xC2;
    }
    temp_2 = (s16)func_0023d8e0(0, arg0);
    switch (temp_2) {
    case 0:
        return 0xB8;
    case 1:
        return 0xB9;
    case 2:
        return 0xBA;
    case 3:
        return 0xBB;
    case 4:
        return 0xBC;
    case 5:
        return 0xBD;
    case 6:
        return 0xBE;
    case 7:
        return 0xBF;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 0xC0;
    case -1:
        return -1;
    default:
        func_0046d730(D_005E4800, 0x32E);
        return 0;
    }
}

/* measured: retail prologue value-saves are `sd $a0,0x30; mov.s $f20,$f12; sw
   $a1,0x3c; move $s0,$a3` (stack spills interleaved around the FP save, $s0
   move LAST); mwcc b210 always groups `[callee-GPR move, mov.s $f20, stack
   spills in assignment order]` with the $s0 move FIRST, whatever the source
   ordering (re-measured this wave: 7 spellings incl. all decl/assign orders,
   decl-initialised, lo/hi/z locals, inline derefs -> best nd 3 = assignment
   `sp3C=arg1` before `sp30=arg0` which fixes the spill order to [a1,a0] but
   leaves the $s0 move first vs retail last; every other spelling nd 4).
   Everything after the prologue matches byte-for-byte (14cb0 call, blez,
   alpha chain, 11-arg d4c0 setup with a3=alpha, f12/f13=arg0 halves,
   t0-t2=arg1 bytes, f14=fparg0, t3=0). prologue-save scheduling floor. */
// FUN_00114DC0
void func_00114dc0(Vec2f arg0, f32 fparg0, Color4 arg1, u16 arg2, s32 arg3) {
    s32 temp;

    temp = func_00114cb0(arg2);
    if (temp > 0) {
        func_0046d4c0(0,
                      arg3,
                      temp,
                      arg0.x,
                      arg0.y,
                      (0xFF - arg1.b3) & 0xFF,
                      arg1.b0,
                      arg1.b1,
                      arg1.b2,
                      fparg0,
                      0);
    }
}
/* measured: best nd 38 (this wave, down from recorded 73) with an `s32 alpha
   local` = temp_16 & 0xFF passed as the d4c0 arg4 (a3) -- without it the
   masks are deleted and the arg setup reorders. Residual is five independent
   families: (1) prologue save rotation (4w: retail `sd $a0; mov.s $f21; move
   $s0; move $s3`, mwcc `move $s0; move $s3; mov.s $f21; sd $a0` -- same
   floor as func_00114dc0); (2) retail computes each call's f32 args before
   the alpha chain, mwcc emits the alpha chain first (8w, argument-evaluation
   order; x/y-locals spellings hoist all FP work before call 1, worse);
   (3) retail coalesces temp_16 into arg1's $s0 with `andi $a3,$s0,0xff` at
   ALL three calls, mwcc keeps temp_17 in $s0 / temp_16 in $s1 and deletes
   every mask (move $a3,$s1); (4) 2bc860 block: retail does both adds first
   ($f2 then $f1) then both cvt pairs, mwcc interleaves add/cvt and picks
   $f0; (5) mov.s $f14 before addiu $a1/$a2 vs retail after the or $a0.
   Prologue + 0x68 slot, hi hoisted to $f20, 46a770/trap/d4c0 setups and the
   beqz chain otherwise byte-identical. Tried: m2c-faithful (107), hi local
   (76), x/y locals (76), alpha local (38), temp_16-first, decl swaps,
   u8 alpha (79). arg-eval-order + reg-coalescing + FP-scheduling floor. */
// FUN_00114E50
void func_00114e50(Vec2f arg0, f32 fparg0, s32 arg1, s32 arg2) {
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    f32 x;
    f32 y;
    s32 temp_7;

    temp_2 = func_0046a770(D_005E5850);
    if (temp_2 == 0) {
        func_0046d730(D_005E4800, 0x353);
    }
    x = 1.0f + arg0.x;
    y = arg0.y - 1.0f;
    temp_17 = arg1 & 0xFF;
    temp_16 = 0xFF - temp_17;
    func_0046d4c0(0, temp_2, 0x61, x, y, temp_16 & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
    x = 393.0f + arg0.x;
    y = arg0.y - 1.0f;
    temp_16 = 0xFF - temp_17;
    func_0046d4c0(0, temp_2, 0x60, x, y, temp_16 & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
    x = arg0.x - 1.0f;
    y = arg0.y;
    temp_16 = 0xFF - temp_17;
    func_0046d4c0(0, temp_2, 0x17, x, y, temp_16 & 0xFF, 0xFF, 0xA0, 0x0B, fparg0, 0);
    temp_7 = arg2 & 0xFFFF;
    if (temp_7 != 0) {
        x = 62.0f + arg0.x;
        y = 22.0f + arg0.y;
        func_002bc860((f32)(s32)x, (f32)(s32)y, fparg0, temp_17 | ~0xFF, 1, 8, temp_7);
    }
}

/* measured: re-measured this wave with a rebuilt body, best nd 45. The
   working spelling: `u16 count = *(u16 *)(arg0 + 0x22C)` loaded BEFORE
   `var_6 = arg1 != 0` (fixes retail's lhu-before-sltu order and the
   `andi $v1,$v1,0xffff` promotion mask), s8 temp_2/var_8/temp_7, s32
   temp_5/var_3 with the %4 fixup run in s32 BEFORE the trailing `(s8)`
   conversion (an early (s8) cast breaks the fixup chain, nd 186), and
   D_008C027A[0] array form for the absolute lhu. Residual: (1) temp_7 -> $a2
   / var_6 -> $a3 swap vs retail $a3/$a2 (recorded floor, all decl+def orders
   tried); (2) temp_5/var_3 rotate too: mwcc reuses t's $v1 for temp_5
   (`addiu $v1,$v1,3`) and puts var_3 in $a1, retail gives temp_5 $a1 / var_3
   $v1, in all six %4 fixup chains. The m2c (s64)<<0x38>>0x38 spelling
   double-emits the dsll32/dsra32 pairs (nd 154). Everything else byte-
   identical (s8 pairs, slti/beqz chains, sb stores, beq join). nd 45;
   temp-register rotation floor. */
// FUN_00115020
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115020);

// FUN_001152B0
u16 func_001152b0(u8 *arg0) {
    s8 temp_17;
    s32 p;
    u16 r;

    temp_17 = *(s8 *)(arg0 + 4);
    if ((temp_17 < 0) || (temp_17 > 8)) {
        func_0046d730(D_005E4800, 0x447);
    }
    if (temp_17 < 8) {
        if (temp_17 < (s32) *(u16 *)(arg0 + 0x68)) {
            p = temp_17 * 12;
            r = *(u16 *)(p + (s32)arg0 + 0xA);
        } else {
            r = 0;
        }
    } else {
        if ((temp_17 - 8) >= (s32) *(u16 *)(arg0 + 0x22C)) {
            func_0046d730(D_005E4800, 0x453);
        }
        r = *(u16 *)(arg0 + 0x6E);
    }
    return r;
}


// FUN_00115380
s16 func_00115380(u8 *arg0, s32 arg1) {
    s16 i;
    s32 target;
    s32 count;

    i = 0;
    target = arg1 & 0xFFFF;
    count = *(u16 *)(arg0 + 0x60);
    for (; i < count; i++) {
        if (target == *(u16 *)(arg0 + i * 12 + 2)) {
            return i;
        }
    }
    if (target == (func_00115750(arg0) & 0xFFFF)) {
        return 8;
    }
    return -1;
}

/* measured: retail allocates the s16 loop counter to $a1, the match key
   (`arg0 & 0xFFFF`) to $a3 and the u16 bound (0x224) to $a2, and reuses the
   counter register directly at the func_00115670 call (`move $a0,$s0; jal`,
   $5 already holds the counter). mwcc b210 pins the s16 counter in $a3 and
   gives the key $a2 / bound $a1 for EVERY spelling tried (10+ probe_variants
   batches: all 6 declaration orders, all 6 def orders, u16/s16 variants of
   key/bound/count, comparison-form swaps, while vs for, inline bound/key
   expressions, for-init placement, bound/key hoisted before the trap). The
   whole function is otherwise byte-identical. nd 23, all in this rotation
   plus the extra dsll32/dsra32 re-extension the call path needs; temp-register
   rotation floor. */
// FUN_00115420
void func_00115420(s32 arg0, u8 *arg1) {
    s32 target;
    s32 value;
    s32 i;
    s32 bound;
    u16 count;

    if (*(u16 *)(arg1 + 0x60) >= 8) {
        func_0046d730(D_005E4800, 0x472);
    }
    count = *(u16 *)(arg1 + 0x60);
    *(u16 *)(arg1 + 0x60) = count + 1;
    *(s16 *)((u8 *)shdSkill_addOff(count * 12, arg1) + 2) = (s16)arg0;
    i = 0;
    target = arg0 & 0xFFFF;
    bound = *(u16 *)(arg1 + 0x224);
    goto loop_test;
loop_body:
    value = *(u16 *)(arg1 + (s16)i * 12 + 0x66);
    if (value == target) {
        func_00115670(arg1, i, bound, target);
        return;
    }
    i = (s16)(i + 1);
loop_test:
    if ((s16)i < bound) {
        goto loop_body;
    }
}

/* measured: same rotation as func_00115420 — retail reuses loop-1's dead
   registers for loop 2 (counter -> $a1, key -> $a3, bound -> $a2), mwcc b210
   assigns counter $a3 / key $a2 / bound $a1 regardless of declaration and def
   order (probed), adding a dsll32/dsra32 in the call path. First loop, join,
   trap and store all match. nd 25, all this rotation; temp-register rotation
   floor. */
// FUN_00115500
INCLUDE_ASM("asm/nonmatchings/shdSkill", func_00115500);

// FUN_00115760
void func_00115760(u8 *arg0) {
    typedef struct {
        f32 v[3];
    } S3f;
    s32 i;
    s32 off;
    s32 p;

    if (*(u16 *)(arg0 + 0x224) <= 0) {
        func_0046d730(D_005E4800, 0x4B7);
    }
    for (i = 0; i < *(u16 *)(arg0 + 0x224) - 1; i++) {
        *(S3f *)(arg0 + i * 12 + 0x64) = *(S3f *)(arg0 + i * 12 + 0x70);
        *(u16 *)(arg0 + i * 2 + 0x1E4) = *(u16 *)(arg0 + i * 2 + 0x1E6);
    }
    off = *(u16 *)(arg0 + 0x224) * 12;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x5A) = 0;
    off = *(u16 *)(arg0 + 0x224) * 2;
    p = off + (s32)arg0;
    *(u16 *)(p + 0x1E2) = 0;
    *(u16 *)(arg0 + 0x224) -= 1;
}

/* measured: live MATCH, object 220B/window 224B, normalized_diff 0. Corrected func_0046d730 to (void *, s32). The trampoline form initializes a named input local before the guard and assigns the loop counter after the guard; this makes retail's entry branch target the loop pre-jump instead of b210 threading directly to loop_test. */
// FUN_00115670
void func_00115670(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {
        f32 v[3];
    } S3f;
    s32 i;
    s32 input;
    u16 count;
    u8 *p;
    u8 *q;

    input = (s64)(s16)arg1;
    if (input < (s32)*(u16 *)(arg0 + 0x224)) {
        goto loop_entry_15670;
    }
    func_0046d730(D_005E4800, 0x4B7);
loop_entry_15670:
    i = input;
    goto loop_test_15670;
loop_body_15670:
    p = (u8 *)(arg0 + i * 12);
    *(S3f *)(p + 0x64) = *(S3f *)(p + 0x70);
    q = (u8 *)(arg0 + i * 2);
    *(u16 *)(q + 0x1E4) = *(u16 *)(q + 0x1E6);
    i += 1;
loop_test_15670:
    count = *(u16 *)(arg0 + 0x224);
    if (i < (s32)(count - 1)) {
        goto loop_body_15670;
    }
    p = shdSkill_addOff(count * 12, arg0);
    *(u16 *)(p + 0x5A) = 0;
    p = shdSkill_addOff(*(u16 *)(arg0 + 0x224) * 2, arg0);
    *(u16 *)(p + 0x1E2) = 0;
    *(u16 *)(arg0 + 0x224) = *(u16 *)(arg0 + 0x224) - 1;
}

// FUN_00115750
u16 func_00115750(u8 *arg0) {
    return *(u16 *)(arg0 + 0x66);
}

