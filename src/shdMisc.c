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
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);

extern char D_005E5810[];
extern char D_0064E2F8;

u32 func_00105ed0(void);
s32 func_0046a770(u32 param);
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

// FUN_00364320
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364320);

/* measured: register allocation residual. Same do-while loop structure as m2c
   seed (digit store, dot-if, mod-3 counter update). Tried 16+ source variants
   (declaration order, char* / void* / s32 arg0, postfix, nested if, digit temp,
   for/while loop shapes, named constants, register locals) - all produce i->t1
   cnt->t0 with in-loop constant materialization vs retail i->v0 cnt->t3 with
   preheader hoisting of '.',2,3,10. 28-word nd, all register name diffs. */
// FUN_003645C0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_003645c0);

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

// FUN_00365F00
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);

