/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* gp - 0x5418 = 0x00763CD8, accessed as a 64-bit word (ld/sd). */
extern s64 iGpffffabe8;

/* gp - 0x4A58 = 0x00763BA8. */
extern s32 iGpffffb5a8;

extern f32 D_0064E310[];
extern f32 D_0064E314[];
extern f32 D_0064E318[];
extern f32 D_0064E31C[];
extern f32 D_008872F8[];
extern f32 iGpffff8094;
extern f32 iGpffff81e0;
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);

extern char D_005E5810[];
extern char D_0064E2F8[];

u32 func_00105ed0(void);
s32 func_0046a770(char *param);
void func_0046d730(char *, s32);
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3,
                  f32 z, s32 arg4);
void func_003f6440(s32 param, s32 value);
void func_00489f80(void);
void func_0048a000(void);
u8 *func_00457120(void);
f32 func_0044b610(f32 fparg0);
f32 func_0044b7b0(f32 fparg0);
void func_003645c0();

/* measured: register allocation / stack-layout floor. Retail stores first arg
   (s64) as one sd at 0x48, keeps arg0-HIGH in $s1 across the 9 vtable calls,
   frame 0x90. mwcc either emits two separate sw (s32-arg spelling) or spills
   arg0 to 0x58 with frame 0xa0 (extra $s2 for var_17) and reads the high byte
   via lbu from the stack (s64-arg spelling). Tried 4 spellings: s32/s64 arg0,
   (arg0>>32) vs *((s32*)&arg0+1) high-word access, float locals vs address-
   taken reads. The D_00887300 base-hoist recipe and D_0064E2F8 array decl both
   match retail exactly; only the arg-spill/register-allocation shape differs. */
// FUN_00364320
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364320);


/* measured: plain -O2 variants kept the digit index in $t1 and counter in
   $t0 while retail hoists '.',2,3,10 and uses $v0/$t3. Adding named constants
   plus #pragma opt_loop_invariants on fixes the hoist and leaves only the
   documented scratch-register residual; see the committed nd 12 body below. */
/* measured: named constants plus #pragma opt_loop_invariants on hoist '.', 2, 3, and 10 into the retail preheader; all control flow and 38/40 words match. The remaining 10 differing words are one scratch-register allocation: b210 keeps the digit-buffer index in $t4 while retail reuses $v0. Declaration order, counter types, initializer forms, third-argument signature, and optimization-level probes did not move it. Committed at nd 12. */
// FUN_003645C0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_003645c0(char *arg0, s32 rem)
{
    s32 i;
    s32 cnt;
    s32 dot;
    s32 two;
    s32 three;
    s32 ten;
    s32 next;
    s32 j;
    char tmp[16];

    i = 0;
    cnt = 0;
    dot = 0x2e;
    two = 2;
    three = 3;
    ten = 10;
    do {
        tmp[i] = (char)((rem % ten) + 0x30);
        i += 1;
        rem = rem / ten;
        if ((rem > 0) && (cnt == two)) {
            tmp[i] = (char)dot;
            i += 1;
        }
        next = cnt + 1;
        cnt = next % three;
    } while (rem > 0);
    j = 0;
    while (j < i) {
        next = j + 1;
        arg0[j] = tmp[i - next];
        j = next;
    }
    arg0[j] = 0;
}
/* measured: candidate probe */
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_003645c0);
#endif




/* measured: multi-issue floor. Retail 1488B; mwcc-compiled candidate 1840B
   (352B over) via 4x0x10 struct-array + separate struct-field stores. The
   D_00887300/D_00887310 base-hoist recipes and the D_0064E2F8 array decl
   match retail exactly; the bltz color-byte pattern needs the `f = f + f`
   doubling (retail add.s f0,f0,f0) not `2.0f *` (mul.s). Remaining issues:
   f26/f25 float-register swap (sub.s/div.s), arg-prologue int-vs-float move
   order, arg3 switch test order (retail tests ==1 then ==0), and the third
   D_00887310 call's base-hoist timing. Tried 1 spelling (struct array). */
// FUN_00364680
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364680);

// FUN_00364C50
void func_00364c50(void) {
    iGpffffabe8 |= 0x80;
}

// FUN_00364C70
void func_00364c70(void) {
    iGpffffabe8 &= ~0x80;
}

/* measured: register allocation residual. Structure (m2c-verified) matches
   retail exactly: FPU adda/madda/msub/madd chains DO compile correctly, arg0
   slot lands at 0x68 via direct &arg0 reads, hi/lo/scale/c land on f20-f23.
   Tried ~25 variants: interleaved parameter order, diff local before/after
   calls, inline diff, struct-copy w init, all declaration orders. mwcc always
   allocates the 5th float local (diff) to f24 with args at f25-f28, while
   retail puts diff at f28 with args at f24-f27; s32 args come out arg1->s0
   arg2->s1 vs retail s1/s0; w-init compiles interleaved vs retail load-all-
   store-all. 163-word nd. */
// FUN_00364C90
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364c90);



// FUN_00364FB0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364fb0);

// FUN_003657D0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_003657d0);


// FUN_00365AC0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365ac0);

/* measured: nd 787 with a full C body (object 1208B over a 1152B window).
   Wave 10 ran out of turns here and left it uncommitted, so this is a partial
   adaptation, not a settled floor. Established along the way: the signature is
   (s64 arg0, ...) which gives retail's single `sd` spill instead of two `sw`,
   and D_0064E2F8 needs an array declaration to get absolute lui/addiu rather
   than GPREL. Re-attempt from there. */
// FUN_00365F00
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);

