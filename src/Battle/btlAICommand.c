/* Source unit: src/Battle/btlEffect_001db100.c */
#include "type.h"
#include "include_asm.h"

typedef u8 bool;
typedef int (*code)(...);

extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern bool btlCond_MYWEAK(int param_1, short param_2);

s32 func_001db360(u64 formation, u16 index, s32 enabled);
/* definition (FUN_001DB580) is byte-verified; the extern's `int` first
   parameter was a guessed prototype and clashed with the merged definition */
extern void btlCond_MYNOMAL(u64 formation, u16 index);

extern u64 func_0010f460();

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

typedef void (*FormationCallback)(void);

extern s32 func_001dbba0();
void btlCond_MYBAD(void);

extern u64 func_00452490();

extern u8 *func_001b0cc0();
extern s32 func_001de000();
extern u32 func_0029cc00();
extern void func_0029cf50();
extern u8 *func_0029d050();

extern void func_001d9b60();
extern void func_001dacc0();
extern void func_001da230();
extern void func_001da270();
extern void func_001da2b0();
extern void func_001da2f0();
extern s32 func_001d9390();
extern s32 func_00235520();
extern void func_00233bb0(u32 arg0);
extern s32 func_001d8cb0(u32 arg0, u8 *arg1);
extern u32 func_001d8bc0(u8 *arg0);
extern void func_001d9740();
extern short func_0023d8e0(u32 arg0, u16 arg1);
extern u32 func_00243920(u32 arg0);
extern u32 *func_001d9280();
extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
extern s32 func_0010f420(u16 arg0, u16 arg1);
extern void func_001d8bf0(u8 *arg0, u8 *arg1);
extern u8 *D_0072449C;
extern void *D_00609850[];
extern u32 func_001b1570(u16 arg0);
extern u32 func_00233880(u32 arg0, u32 arg1);
extern u16 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3);
extern u16 func_00231d70(u16 arg0);
extern s32 func_001ef720(s32 arg0, s32 arg1);
extern s32 func_001ef4d0(s32 arg0, s32 arg1);
extern u32 func_00231ed0(u32 arg0);
extern u32 func_002340c0();
extern s32 func_00242800(u32 arg0, s32 arg1);
extern void func_001de640(u8 *a, u8 *b, u16 c);

extern void *D_00609934[];
extern void *D_00609940[];
extern void *D_0060994C[];
extern void *D_00609A30[];
extern void *D_00609A3C[];
extern void *D_00609A48[];
extern void *D_00609A6C[];
extern void *D_00609A78[];
extern void *D_00609B74[];
extern void *D_00609B80[];
extern void *D_00609B8C[];
extern void *D_00609CE0[];
extern void *D_00609CE8[];
extern void *D_00609CF0[];
extern void *D_00609CF8[];
extern void *D_00609D18[];
extern void *D_00609D20[];
extern void *D_00609D70[];
extern void *D_00609D78[];
extern void *D_00609D80[];
extern void *D_00609DF0[];
extern void *D_00609E18[];
extern void func_001d7c60(u8 *arg0, u8 *arg1, u16 arg2, s32 arg3, u8 *arg4);
extern s32 func_001dd570(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 func_001dbf20(u8 *arg0, u32 arg1);
extern char D_006095E0[];
extern void func_0046d730(const char *file, s32 line);
extern s32 func_00232710(u32 arg0, u32 arg1);
extern s32 func_00232730(u32 arg0, u32 arg1);
extern s32 func_0023ddc0(u32 arg0, u32 arg1);
extern u8 *iGpffffb3ac;
extern u32 func_00231e20(u32 arg0);
extern s32 func_002428f0(u32 arg0, u32 arg1);
extern u8 *iGpffffb3d0;
extern u8 iGpffffa2a8;
extern u8 *iGpffffb444;
extern void func_00442088(u8 *a, u8 *b, u32 c, u8 d);
extern s32 func_0029de20(u32 a, u8 *b);
extern s32 func_0029da90(u8 *a, u32 b, s32 c);
extern void func_0029dfe0(u32 a, u8 *b);
extern u8 *func_00452560(u32 a);
extern s32 func_0010d740(s32 a);
extern void func_00278450(s32 a, s32 b, u32 c);
extern void func_00452570(u8 *a, u32 b);
extern u8 D_00609E20[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;
extern void func_001eb3b0(u8 *a);
extern u8 func_001de800(u8 *p);
extern u8 *func_001dea90(u8 *p, u32 arg1);
extern s32 func_001debb0();
extern u16 func_0023dfe0(u32 arg0);
extern u16 func_0023dff0(u32 arg0);
extern void func_001ebc00(u8 *a, u8 *b);
extern s32 func_0023e130(u32 arg0);
extern s32 func_0023e140(u32 arg0);
extern u32 func_00231f80(u32 arg0);
extern s32 func_0043c6a0(u32 arg0);
extern u8 *iGpffffb3b8;


// FUN_001DAF40
s32 func_001daf40(u8 *p, u32 arg1) {
    s32 a;

    a = arg1 & 0xFFFF;
    if (a >= 0x240) {
        func_0046d730(D_006095E0, 0x45F);
    }
    p = *(u8 **)(p + 0x30);
    if (a < 0x1B8) {
        if (func_00232710(*(u32 *)(p + 0xA64), 0x80008) != 0)
            return 0;
        if (func_00232730(*(u32 *)(p + 0xA64), a) == 0)
            return 0;
        if (func_0023ddc0(*(u32 *)(p + 0xA64), a) == 0)
            goto ret1;
        return 0;
    }
    if (func_00232730(*(u32 *)(p + 0xA64), a) != 0)
        goto ret1;
    return 0;
ret1:
    return 1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB040 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB040
void func_001db040(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 6, (code *)&func_001da2f0);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB0A0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB0A0
void func_001db0a0(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 6, (code *)&func_001da2f0);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB100
void btlCond_ENWEAK_DW_PAI(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&btlCond_MYWEAK);
  return;
}
#pragma opt_rebuildconditionals on



/* measured: saved-register coloring floor — retail allocates cnt=$16, n=$17,
   t2=$18, i=$19, arg1=$20, p=$21, tab=$22 (use order), while mwcc b210 under
   every declaration order tried (m2c order, forward, reverse) colors
   i=$16, arg1=$17, p=$18, n=$21, cnt=$22, tab=$23 — the whole prologue and
   every A64 load rotates by 5 registers (nd ~84). Control flow, the 3d8e0
   sign-extend compares, the shared v=1 goto, and the reload pattern all
   compile correctly. */
// FUN_001DB160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db160);
/* measured: u64-parameter half-extraction floor — the callers pass a u64
   formation ($4-$5) whose HIGH half is the s16 index, but mwcc b210 models the
   u64 param as the low register only: formation >> 32 compiles to dsll32/dsra32
   no-op pairs instead of retail's move $19,$5, and (u8*)formation gets a
   dsll32/dsra32-0 pair instead of using $4 raw (nd ~112). The caller-side
   declaration (u64,u16,s32) must stay for the matched callers, so the m2c
   (u8*,s64,s32) signature is unreachable. */
// FUN_001DB360
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db360);
// FUN_001DB580
void btlCond_MYNOMAL(u64 formation, u16 index)
{
    func_001db360(formation, index, 1);
}



// FUN_001DB5B0
void func_001db5b0(u64 formation, u16 index)
{
    func_001db360(formation, index, 0);
}


// FUN_001DB5E0
s32 func_001db5e0(u8 *arg0, s16 arg1) {
    return !(func_00242800(*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), arg1) & 0x7000000);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB620 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB620
void func_001db620(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB680 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB680
void func_001db680(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB6E0
void btlCond_ENNOMAL_DW(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&btlCond_MYNOMAL);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB740
bool btlCond_ANALYZE(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return 0;
  }
  lVar2 = func_0010f460(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}



// FUN_001DB790
s32 btlCond_DOWN(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 8) ? 0 : 1;
}



// FUN_001DB7B0
s32 btlCond_SLIP(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 0x10) ? 0 : 1;
}



/* measured: f = (a == 0) boolean — retail emits a branchy set (bnez $v0,L;
   addiu $v0,1; b; L: move $v0,0; andi $s0,$v0,0xffff) while mwcc b210 folds
   every spelling (if/else, ternary, switch) into xor/sltiu booleanize; also
   mwcc insists t0=$16/f=$17 (retail f=$16/t0=$17) under all declaration orders
   and masks the u16 per-use in-loop instead of hoisting pre-loop. Best nd 45
   (switch form). $v0/$v1-coloring + fold floor. */
// FUN_001DB7D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db7d0);
// FUN_001DB8D0
s32 func_001db8d0(u8 *arg0) {
    return (s32)(func_002340c0(*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xA64)) != 0);
}

// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x10000000) != 0);
}



// FUN_001DB940
void func_001db940(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB990 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB990
void func_001db990(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals on
// FUN_001DB9F0
s32 func_001db9f0(u8 *arg0, s16 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(p + 0xA2) == 1 && func_001f9ce0(arg0, arg1) == 0 && func_0010f420(*(u16 *)(p + 0xA4), (u16)arg1) == 0)
        return 0;
    return (func_00242800(*(u32 *)(p + 0xA64), arg1) & 0x7000000) != 0;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DBA90 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DBA90
void func_001dba90(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&func_001db9f0);
}

#pragma opt_rebuildconditionals on
// FUN_001DBAF0
s32 func_001dbaf0(u8 *arg0, u32 arg1) {
    s32 mask = 0;
    if (arg1 & 1)
        mask |= 0x8000000;
    if (arg1 & 2)
        mask |= 0x10000000;
    if (arg1 & 4)
        mask |= 0x20000000;
    if (arg1 & 8)
        mask |= 0x40000000;
    if (mask == 0)
        return 0;
    return func_002340c0(*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), mask) != 0;
}

// FUN_001DBB90
s32 func_001dbb90(void) {
    return 1;
}

// FUN_001DBBA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbba0);

// FUN_001DBF20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbf20);

/* measured: only residual is the 2-word loop-body mask floor shared with
   FUN_001DCF10/FUN_001DC9A0 (retail andi $v0,$a0,0xffff; sll $v0,$v0,2 vs mwcc
   b210 in-place andi $a0,$a0,0xffff; sll $v0,$a0,2); the max-finding loop
   matches with the FUN_001DD0D0 recipe (decl order best,j,bestScore,count,
   explicit j = 0 before the hoisted count load, u32 bestScore/s, s < bestScore).
   Tried (u32)i cast and inline-no-q body: still 5. */
// FUN_001DC380
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc380);

/* measured: only residual is the 2-word loop-body mask floor shared with
   FUN_001DCF10/FUN_001DC9A0 (retail andi $v0,$a0,0xffff vs mwcc in-place
   andi $a0,$a0,0xffff); the min-finding loop matches with j as s32 + (u16)j in
   the body (breaks the mask CSE), bs/s as u16, bs = 0xFFFF init, and
   s < bs compare. */
// FUN_001DC480
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc480);
// FUN_001DC5B0
s32 func_001dc5b0(void) {
    return 0;
}

// FUN_001DC5C0
void func_001dc5c0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001d9b60);
}

// FUN_001DC600
void func_001dc600(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001d9b60);
}

// FUN_001DC640
void func_001dc640(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001dacc0);
}

/* measured: entire loop body and tail compile with mwcc b210's temp registers
   rotated one slot off retail ($v1/$a0/$a1 where retail uses $v0/$v1/$a0),
   starting from the gp load (lw $v1,($gp) vs lw $v0,-0x4c54($gp)) and cascading
   through lhu/andi, the 0x30-chain, the arr store (andi $a0.. vs $v0..), the
   (u16)i test (andi $v1 vs $a0) and the else path (extra move $a0,$s0 + andi on
   the u16 return). Control flow, frame, saved regs, call shapes all match.
   Tried: decl-order swaps, fl/np locals, inline exprs, g = iGpffffb3ac local,
   for/while, node-chain compare order, t = (u16)i local, arr[14]/arr[16] —
   all nd 40-56. $v0/$v1-coloring floor. */
// FUN_001DC6A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc6a0);


// FUN_001DC7A0
void func_001dc7a0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001da230);
}

// FUN_001DC7E0
void func_001dc7e0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001da270);
}

// FUN_001DC820
void func_001dc820(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001da2b0);
}

// FUN_001DC860
void func_001dc860(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001da2f0);
}

// FUN_001DC8A0
void func_001dc8a0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001da230);
}

// FUN_001DC8E0
void func_001dc8e0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001da270);
}

// FUN_001DC920
void func_001dc920(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001da2b0);
}

// FUN_001DC960
void func_001dc960(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001da2f0);
}

// FUN_001DC9A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc9a0);
/* measured: same 2-word loop-body mask floor as FUN_001DCF10/FUN_001DC9A0 —
   retail zero-extends the u16 counter into scratch $v0 (andi $v0,$a0,0xffff;
   sll $v0,$v0,2), mwcc b210 masks in place (andi $a0,$a0,0xffff; sll $v0,$a0,2);
   everything else in the function is byte-identical (nd 5 = those 2 words +
   reloc accounting). Tried (u32)/(s32)/explicit-mask index spellings: nd >= 5. */
// FUN_001DCA60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dca60);

// FUN_001DCB50
void func_001dcb50(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 0, btlCond_MYBAD);
}



// FUN_001DCB90
void func_001dcb90(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 1, btlCond_MYBAD);
}



// FUN_001DCBD0
void func_001dcbd0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 0, func_001da230);
}

// FUN_001DCC10
void func_001dcc10(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 0, func_001da270);
}

// FUN_001DCC50
void func_001dcc50(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 0, func_001da2b0);
}

// FUN_001DCC90
void func_001dcc90(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 0, func_001da2f0);
}

// FUN_001DCCD0
void func_001dccd0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 1, func_001da230);
}

// FUN_001DCD10
void func_001dcd10(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 1, func_001da270);
}

// FUN_001DCD50
void func_001dcd50(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 1, func_001da2b0);
}

// FUN_001DCD90
void func_001dcd90(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 1048576, 0, 1, func_001da2f0);
}

// FUN_001DCDD0
void func_001dcdd0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 1, 0, func_001da230);
}

// FUN_001DCE10
void func_001dce10(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 1, 0, func_001da270);
}

// FUN_001DCE50
void func_001dce50(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 1, 0, func_001da2b0);
}

// FUN_001DCE90
void func_001dce90(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 1, 0, func_001da2f0);
}

// FUN_001DCED0
void func_001dced0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, func_001dacc0);
}

/* measured: retail keeps the u16 loop counter raw in $a0 and zero-extends into
   scratch $v0 per use (andi $v0,$a0,0xffff; sll $v0,$v0,2) while mwcc b210 masks the
   counter register in place (andi $a0,$a0,0xffff; sll $v0,$a0,2) in the loop body,
   exactly 2 words. Tried: u16 counter with pointer local, inline ptr arithmetic,
   s32 offset local + plain-assignment addu, (u32)<<2, s32 counter with (u16) casts
   (nd 25), declaration-order swaps, explicit u16 idx local — all identical nd 4.
   $v0/$v1-style coloring floor. */
// FUN_001DCF10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcf10);

// FUN_001DCFD0
void func_001dcfd0(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, (FormationCallback)func_001db8d0);
}

// FUN_001DD010
void func_001dd010(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 1, (FormationCallback)func_001db8d0);
}

// FUN_001DD050
void func_001dd050(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, func_001db9f0);
}

// FUN_001DD090
void func_001dd090(u64 formation, u32 flags) {
    func_001dbba0(formation, flags, 0, 0, 0, (FormationCallback)btlCond_MYNOMAL);
}

/* measured: only residual is the 2-word loop-body mask floor shared with
   FUN_001DCF10/FUN_001DC9A0 (retail andi $v0,$a0,0xffff; sll $v0,$v0,2 vs mwcc
   b210 andi $a0,$a0,0xffff; sll $v0,$a0,2); the whole second loop matches with
   declaration order best,j,bestScore,count + explicit j = 0 before the hoisted
   count load + u32 bestScore (sltu). Tried inline no-q body and (u16)i casts:
   still 2. */
// FUN_001DD0D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd0d0);
// FUN_001DD1C0
s32 func_001dd1c0(u8 *p, u8 *q, u16 *t, u32 u, u32 v) {
    u32 s;
    s32 bd;
    s32 best;
    s32 i;
    u32 v2;
    s32 u2;
    u16 *e;
    u16 w;
    u8 b;
    s32 d;
    s32 d2;

    s = func_00231ed0(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    best = -1;
    bd = 0xFFFFFF;
    i = 0;
    v2 = v & 0xFFFF;
    u2 = u & 0xFFFF;
    while ((i & 0xFFFF) < u2) {
        e = t + (u16)i;
        w = *(u16 *)e;
        if (w == 0)
            b = 0;
        else
            b = *(u8 *)(iGpffffb3b8 + w * 40 + 8);
        if ((v2 != 0 || (b & 0xFF) == 1) && (v2 != 1 || (b & 0xFF) == 0)) {
            d = func_00235520(w, *(u32 *)(*(u32 *)(p + 0x30) + 0xA64), *(u32 *)(*(u32 *)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1);
            d2 = s + d;
            if (d2 > 0 && bd > 0) {
                if (d2 < bd) {
                    best = *(u16 *)e;
                    bd = d2;
                }
                goto next;
            }
            if (d2 <= 0 && (bd > 0 || bd < d2)) {
                best = *(u16 *)e;
                bd = d2;
            }
        }
    next:
        i = (i + 1) & 0xFFFF;
    }
    func_00233bb0(*(u32 *)(*(u32 *)(p + 0x30) + 0xA64));
    func_00233bb0(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64));
    return best;
}
// FUN_001DD3A0
s32 func_001dd3a0(u8 *p, u8 *q, u16 *t, u32 u, s32 v) {
    u32 s1;
    u32 s2;
    s32 bd;
    s32 best;
    s32 i;
    u32 v2;
    s32 u2;
    u16 *e;
    u16 w;
    u8 b;
    s32 d;

    s1 = func_00231ed0(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    s2 = func_00231f80(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    best = -1;
    bd = 0xFFFFFF;
    i = 0;
    v2 = v & 0xFFFF;
    u2 = u & 0xFFFF;
    while ((i & 0xFFFF) < u2) {
        e = t + (u16)i;
        w = *(u16 *)e;
        if (w != 0 && w < 0x1B8) {
            b = *(u8 *)(iGpffffb3b8 + w * 40 + 8);
            if ((v2 != 0 || (b & 0xFF) == 1) && (v2 != 1 || (b & 0xFF) == 0)) {
                d = func_0043c6a0(s2 - (s1 + func_00235520(w, *(u32 *)(*(u32 *)(p + 0x30) + 0xA64), *(u32 *)(*(u32 *)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1)));
                if (d < bd) {
                    best = *(u16 *)e;
                    bd = d;
                }
            }
        }
        i = (i + 1) & 0xFFFF;
    }
    func_00233bb0(*(u32 *)(*(u32 *)(p + 0x30) + 0xA64));
    func_00233bb0(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64));
    return best;
}
// FUN_001DD570
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd570);

// FUN_001DD920
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd920);

/* measured: the func_001db360 call-site convention is unreachable in C — retail
   calls it with ($4=q, $5=stale s16 from the 3d8e0 compare, $6=1) while the
   matched callers need the typed (u64,u16,s32) declaration; an old-style extern
   satisfies de000 but adds a u16 promotion andi to the matched callers
   (MISMATCH), and the typed extern forces mwcc's broken u64 half-construction
   (dsll32/dsra32 pairs + or) at this call site. Also the n2 = (n2+1) fold
   (daddiu vs retail's addiu+andi) is a 1-word constant-propagation floor. */
// FUN_001DE000
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de000);
/* measured: the mid-loop float block uses the FPU accumulator idiom
   (adda.s $f0,$f1 / msub.s $f0,$f1,$f2 / cvt.w.s after the signed-negative
   (x>>1)|(x&1) conversion trick) which m2c marks M2C_ERROR and no C float
   spelling reproduces byte-for-byte; the surrounding loops (D_00609600 u8
   table, the list[] s16 entries, the bubble-sort pass, the weighted 31d70
   pick) are all readable. */
// FUN_001DE370
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de370);
// FUN_001DE640
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de640);
// FUN_001DE800
u8 func_001de800(u8 *p) {
    u8 *base;
    u8 *row;
    s32 k;
    s32 j;
    u32 w;
    u32 e;
    u32 a2;
    s32 x;
    u32 arr[3];

    base = iGpffffb3d0 + (*(u16 *)(*(u32 *)(p + 0x30) + 0xA4)) * 164;
    k = 0;
    while ((u16)k < 2) {
        row = base + (k & 0xFFFF) * 20 + 4;
        j = 0;
        while ((u16)j < 3) {
            w = *(s32 *)(row + (j & 0xFFFF) * 4);
            e = (w & 0xFF000000) >> 24;
            a2 = w & 0xFFFFFF;
            if (e == 0)
                x = 0;
            else
                x = ((s32 (*)(u8 *, u32))D_00609850[e * 3])(p, a2);
            arr[j & 0xFFFF] = x;
            j = (j + 1) & 0xFFFF;
        }
        if (arr[0] && arr[1] && arr[2] && *(u8 *)(row + 0xC) != 8)
            return *(u8 *)(row + 0xC);
        if (arr[0] && arr[1] && *(u8 *)(row + 0xD) != 8)
            return *(u8 *)(row + 0xD);
        if (arr[0] && arr[2] && *(u8 *)(row + 0xE) != 8)
            return *(u8 *)(row + 0xE);
        if (arr[1] && arr[2] && *(u8 *)(row + 0xF) != 8)
            return *(u8 *)(row + 0xF);
        if (arr[0] && *(u8 *)(row + 0x10) != 8)
            return *(u8 *)(row + 0x10);
        if (arr[1] && *(u8 *)(row + 0x11) != 8)
            return *(u8 *)(row + 0x11);
        if (arr[2] && *(u8 *)(row + 0x12) != 8)
            return *(u8 *)(row + 0x12);
        if (*(u8 *)(row + 0x13) != 8)
            return *(u8 *)(row + 0x13);
        k = (k + 1) & 0xFFFF;
    }
    return 0;
}

/* measured: preheader + loop-body coloring floor. Retail schedules the node
   base addu ($4) BEFORE the sum/i inits and re-issues the (i & 0xFFFF) mask in
   the loop body (andi $v0,$a3,0xffff; sll $v0,$v0,3), while mwcc b210 emits the
   inits after the whole node expression and CSEs the test mask across the
   branch (sll $v0,$v1,3), 1 word per iteration; the second loop's j2 counter
   then colors into unsaved $18. Best 51 nd with node = ...; sum=0; i=0;
   node += a*40. $v0/$v1-coloring floor. */
// FUN_001DEA90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dea90);
/* measured: load-sinking floor on the func_00442088 4th arg — retail loads the
   c byte right after the test (lbu $v0,0x10($v0); ...; move $a3,$v0) while mwcc
   b210 sinks it into $a3 at the call site (lbu $a3,0x10($v0)), 1 word + 4-byte
   shift of the else block. Hoisting c into a local made mwcc hoist the loads
   ABOVE the a2 test instead (nd 10 head). Everything else matches: d declared
   before t ($20/$19), buf[32], the case 0/1 switch, iGpffffb444 + x*21 chain. */
// FUN_001DEBB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001debb0);
/* measured: three 1-2 word scheduler residuals. (1) case 1's chain: retail
   loads iGpffffb3d0 FIRST (lw $a0,-0x4c30) then computes (a4&0xFFFF)*164 and
   addu $v0,$v0,$a0, while mwcc b210 sinks the global load after the chain and
   emits addu $v0,$v0,$v1 (base-first); (2) the v2 > 0 test's u16 mask lands in
   $v0 instead of retail's $a3; (3) func_001de640's args materialize lhu-before-
   moves instead of moves-then-lhu. Tried chain-first/global-first spellings and
   a g = iGpffffb3d0 local inside the case — all identical 16. Load-sinking +
   $v0/$v1-coloring floor. */
// FUN_001DED30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001ded30);
// FUN_001DEEE0
u32 func_001deee0(int param_1)
{
  u32 uVar1 = 0;
  long lVar2 = 0;

  if (*(u8 *)(param_1 + 0x30) == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = func_00452490(*(int *)(param_1 + 0x4c));
    if (lVar2 == 0) {
      *(u8 *)(param_1 + 0x30) = 0;
      *(u32 *)(param_1 + 0x4c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// FUN_001DEF60
u32 func_001def60(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = (char *)func_0029d050();

  func_001de640(pVar1, pVar1 + 0x38, 0x8000);
  return 1;
}



// FUN_001DEFA0
s32 func_001defa0(void) {
    u8 *p = func_0029d050();
    s32 r = func_0029cc00(0);
    if (r == 0)
        func_001de640(p, p + 0x38, 0x8000);
    else if (r > 0)
        func_001de640(p, p + 0x38, (u16)r);
    else
        func_001de640(p, p + 0x38, 0x8002);
    return 1;
}

// FUN_001DF040
s32 func_001df040(void) {
    u8 *p = func_0029d050();
    s32 r = func_0029cc00(0);
    if (r >= 0) {
        *(u16 *)(p + 0x6C) = 3;
        *(u16 *)(p + 0x70) = r;
        *(u16 *)(p + 0x6E) = func_00243920((u16)r);
    } else {
        func_001de640(p, p + 0x38, 0x8002);
    }
    return 1;
}

// FUN_001DF0C0
u32 func_001df0c0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8001);
  return 1;
}



// FUN_001DF100
u32 func_001df100(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8002);
  return 1;
}



// FUN_001DF140
s32 func_001df140(void) {
    u8 *p = func_0029d050();
    *(u16 *)(p + 0xEC) = func_0029cc00(0);
    func_001de640(p, p + 0x38, 0x8002);
    return 1;
}

// FUN_001DF1A0
s32 func_001df1a0(void) {
    u8 *p = func_0029d050();
    *(u16 *)(p + 0x6C) = 9;
    *(u16 *)(p + 0x6E) = 0x111;
    *(u16 *)(p + 0x76) = func_0029cc00(0);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001DF230
s32 func_001df230(void) {
    u8 *p = func_0029d050();
    *(u16 *)(p + 0x6C) = 9;
    *(u16 *)(p + 0x6E) = 0x111;
    *(u16 *)(p + 0x76) = func_0029cc00(0);
    *(u16 *)(p + 0x78) = func_0029cc00(1);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001DF2D0
u32 func_001df2d0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8007);
  return 1;
}



// FUN_001DF310
s32 func_001df310(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF3C0
s32 func_001df3c0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x2000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF470
s32 func_001df470(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF520
s32 func_001df520(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x4000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF5D0
s32 func_001df5d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x5000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF680
s32 func_001df680(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x6000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF730
s32 func_001df730(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x7000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF7E0
s32 func_001df7e0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x8000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF890
s32 func_001df890(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x9000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF940
s32 func_001df940(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xA000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DF9F0
s32 func_001df9f0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xB000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFAA0
s32 func_001dfaa0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xC000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFB50
s32 func_001dfb50(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xD000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFC00
s32 func_001dfc00(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xE000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFCB0
s32 func_001dfcb0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xF000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFD60
s32 func_001dfd60(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x10000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFE10
s32 func_001dfe10(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x11000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFEC0
s32 func_001dfec0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x12000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001DFF70
s32 func_001dff70(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609934[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001DFFC0
s32 func_001dffc0(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609940[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0010
s32 func_001e0010(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_0060994C[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0060
s32 func_001e0060(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x16000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0110
s32 func_001e0110(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x17000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E01C0
s32 func_001e01c0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x18000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0270
s32 func_001e0270(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x19000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0320
s32 func_001e0320(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1A000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E03D0
s32 func_001e03d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1B000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0480
s32 func_001e0480(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1C000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0530
s32 func_001e0530(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1D000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E05E0
s32 func_001e05e0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1E000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0690
s32 func_001e0690(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1F000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0740
s32 func_001e0740(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x20000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E07F0
s32 func_001e07f0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x21000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E08A0
s32 func_001e08a0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x22000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0950
s32 func_001e0950(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x23000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0A00
s32 func_001e0a00(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x24000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0AB0
s32 func_001e0ab0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x25000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0B60
s32 func_001e0b60(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x26000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0C10
s32 func_001e0c10(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x27000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0CC0
s32 func_001e0cc0(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609A30[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0D10
s32 func_001e0d10(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609A3C[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0D60
s32 func_001e0d60(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609A48[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0DB0
s32 func_001e0db0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x2B000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0E60
s32 func_001e0e60(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x2C000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E0F10
s32 func_001e0f10(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609A6C[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0F60
s32 func_001e0f60(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609A78[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E0FB0
s32 func_001e0fb0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x2F000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E1060
s32 func_001e1060(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x30000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E1110
s32 func_001e1110(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x31000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E11C0
s32 func_001e11c0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x32000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E1270
s32 func_001e1270(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x33000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E1320
s32 func_001e1320(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x34000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E13D0
s32 func_001e13d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x35000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E1480
s32 func_001e1480(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x36000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1530
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1530);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1620
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1620);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1710
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1710);

/* measured: only residual is the join-branch chain — retail's e==0 path does
   b 0x1e1900 (jumping into the call block's own tail b 0x1e190c, branch-to-branch
   sharing) while mwcc b210 always emits b 0x1e190c directly; tried if/else and
   goto-done spellings, same 1 word. Everything else matches with m/a2 as u32
   locals and the w/e/a2 chain computed before the e test. */
// FUN_001E1800
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1800);
// FUN_001E1940
s32 func_001e1940(void) {
    u8 *p = func_0029d050();
    u32 *r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = func_002340c0(*(u32 *)(*(u8 **)((u8 *)r + 0x30) + 0xA64), func_0029cc00(1));
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E19F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e19f0);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1AE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1ae0);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1BD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1bd0);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1CC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1cc0);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1DB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1db0);

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E1EA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1ea0);

// FUN_001E1F90
s32 func_001e1f90(void) {
    u8 *p = func_0029d050();
    u32 *r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)r, 0);
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E2030
s32 func_001e2030(void) {
    u8 *p = func_0029d050();
    u32 *r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)r, 0);
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

/* measured: mwcc b210 folds f = (a == 0) into an xor/sltiu booleanize no matter
   the spelling (if/else, ternary, inline in the shift, f = 0 first, switch,
   goto) while retail keeps a branchy set (bnez $v0,L; addiu $v0,1; b; L: move
   $v0,0), which then shifts the whole dispatch tail by 4 words; same fold floor
   as FUN_001DB7D0. The rest (9280 arg order, dsll32/dsrl32 24-bit masks, the
   e*3 table call) all compile correctly when f is the only difference. */
// FUN_001E20D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e20d0);
// FUN_001E21E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e21e0);

// FUN_001E22F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e22f0);

// FUN_001E2400
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2400);

// FUN_001E2550
s32 func_001e2550(void) {
    u32 v;
    u32 m2;
    u32 c02;
    u32 m;
    u32 c0;
    u8 *node;
    s32 n;
    s32 k;
    u8 *np;
    u32 flag;

    m = (1 << (*(u8 *)(*(u32 *)(func_0029d050() + 0x30) + 0xA2))) & 0xFFFF;
    c0 = func_0029cc00(0) & 0xFFFF;
    v = func_0029cc00(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xFFFF;
    c02 = c0 & 0xFFFF;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1A) & 1) && (*(u16 *)(node + 0x1A) & 8)) {
            np = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(np + 0xA2)))) != 0) {
                if (*(u16 *)(np + 0xA4) == c02) {
                    if (func_002428f0(*(u32 *)(np + 0xA64), 0) == 0) {
                        n = (n + 1) & 0xFFFF;
                        if (func_00232710(*(u32 *)(np + 0xA64), v) != 0) {
                            k = (k + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xFFFF) > 0 && (n & 0xFFFF) == (k & 0xFFFF))
        flag = 1;
    func_0029cf50(flag != 0);
    return 1;
}

// FUN_001E26C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e26c0);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E2850 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001E2850
s32 func_001e2850(void) {
    u32 shift;
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = func_002340c0(*(u32 *)(*(u8 **)((u8 *)r + 0x30) + 0xA64), func_0029cc00(1));
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}
#pragma opt_rebuildconditionals on

// FUN_001E2910
s32 func_001e2910(void) {
    u32 v;
    u32 m2;
    u32 c02;
    u32 m;
    u32 c0;
    u8 *node;
    s32 n;
    s32 k;
    u8 *np;
    u32 flag;

    m = (1 << (*(u8 *)(*(u32 *)(func_0029d050() + 0x30) + 0xA2))) & 0xFFFF;
    c0 = func_0029cc00(0) & 0xFFFF;
    v = func_0029cc00(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xFFFF;
    c02 = c0 & 0xFFFF;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1A) & 1) && (*(u16 *)(node + 0x1A) & 8)) {
            np = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(np + 0xA2)))) != 0) {
                if (*(u16 *)(np + 0xA4) == c02) {
                    if (func_002428f0(*(u32 *)(np + 0xA64), 0) == 0) {
                        n = (n + 1) & 0xFFFF;
                        if (func_002340c0(*(u32 *)(np + 0xA64), v) != 0) {
                            k = (k + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xFFFF) > 0 && (n & 0xFFFF) == (k & 0xFFFF))
        flag = 1;
    func_0029cf50(flag != 0);
    return 1;
}

// FUN_001E2A80
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2a80);

// FUN_001E2C10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2c10);

// FUN_001E2D20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2d20);

// FUN_001E2E30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2e30);

// FUN_001E2F40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2f40);

// FUN_001E3050
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3050);

// FUN_001E3160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3160);

// FUN_001E3270
#pragma opt_rebuildconditionals off
/* Removing this loses FUNC_001E3270 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUNC_001E3270
s32 func_001e3270(void) {
    u32 shift;
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)r, 0);
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}
#pragma opt_rebuildconditionals on

// FUN_001E3320
#pragma opt_rebuildconditionals off
/* Removing this loses FUNC_001E3320 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUNC_001E3320
s32 func_001e3320(void) {
    u32 shift;
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)r, 0);
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}
#pragma opt_rebuildconditionals on

// FUN_001E33D0
s32 func_001e33d0(void) {
    u8 *p = func_0029d050();
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 flag = 1;
    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    func_0029cf50(flag != 0);
    return 1;
}

// FUN_001E34B0
s32 func_001e34b0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x38000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3560
s32 func_001e3560(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x39000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3610
s32 func_001e3610(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3A000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E36C0
s32 func_001e36c0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3B000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3770
s32 func_001e3770(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3C000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3820
s32 func_001e3820(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3D000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E38D0
s32 func_001e38d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3E000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3980
s32 func_001e3980(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x3F000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3A30
s32 func_001e3a30(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x40000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3AE0
s32 func_001e3ae0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x41000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3B90
s32 func_001e3b90(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x42000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3C40
s32 func_001e3c40(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609B74[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E3C90
s32 func_001e3c90(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609B80[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E3CE0
s32 func_001e3ce0(void) {
    func_0029cf50(((s32 (*)(u8 *, s32))D_00609B8C[0])(func_0029d050(), 0) != 0);
    return 1;
}

// FUN_001E3D30
s32 func_001e3d30(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x46000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

/* measured: only residual is the join-branch chain — retail's e==0 path does
   b 0x1e3ed4 (into the call block's tail b 0x1e3ee0, branch-to-branch sharing)
   while mwcc b210 emits b 0x1e3ee0 directly; same floor as FUN_001E1800, 1 word.
   Everything else matches: switch(c0) with ascending cases 0/1, c1 as u32, and
   the a2 = w & 0xFFFFFF local computed before the e test. */
// FUN_001E3DE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3de0);
// FUN_001E3F10
s32 func_001e3f10(void) {
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = func_001d9280(b, 1, 0x80000);
        break;
    case 1:
        r = func_001d9280(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x1800) != 0;
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E3FD0
s32 func_001e3fd0(void) {
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = func_001d9280(b, 1, 0x80000);
        break;
    case 1:
        r = func_001d9280(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x1000) != 0;
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E4090
s32 func_001e4090(void) {
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = func_001d9280(b, 1, 0x80000);
        break;
    case 1:
        r = func_001d9280(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x800) != 0;
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E4150
s32 func_001e4150(void) {
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = func_001d9280(b, 1, 0x80000);
        break;
    case 1:
        r = func_001d9280(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x2000) != 0;
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E4210
s32 func_001e4210(void) {
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 b = func_0029cc00(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = func_001d9280(b, 1, 0x80000);
        break;
    case 1:
        r = func_001d9280(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609B74[0])((u8 *)r, 0);
    else
        x = 0;
    func_0029cf50(x != 0);
    return 1;
}

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E42E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e42e0);

// FUN_001E43D0
s32 func_001e43d0(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_002340c0(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), func_0029cc00(0)) != 0);
    return 1;
}

/* measured: retail routes the inner cmd == 0 path through the outer null path's branch;
   mwcc b210 collapses that branch-to-branch and jumps straight to the join, leaving exactly
   one differing word. Renesting as if (r == 0) first gives nd 28, hoisting the dispatch
   locals gives nd 14, so the natural shape is already optimal. Layout floor, not a defect. */
// FUN_001E4430
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4430);

// FUN_001E4520
s32 func_001e4520(void) {
    u8 *p = func_0029d050();
    u32 flag = 0;
    u16 i;
    for (i = 1; i < 0xC; i++) {
        u32 r = func_001b1570(i);
        if (r == 0)
            break;
        if (r == *(u32 *)(D_0072449C + 0x170))
            break;
        if (r == (u32)p) {
            flag = 1;
            break;
        }
    }
    func_0029cf50(flag != 0);
    return 1;
}

// FUN_001E45D0
s32 func_001e45d0(void) {
    func_0029cf50(0);
    return 1;
}

// FUN_001E4600
s32 func_001e4600(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x48000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E46B0
s32 func_001e46b0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x49000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E4760
s32 func_001e4760(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x4A000000;
    u8 *p = func_0029d050();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E4810
s32 func_001e4810(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4880
s32 func_001e4880(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609CE8[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E48F0
s32 func_001e48f0(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609CF0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4960
s32 func_001e4960(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609CF8[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E49D0
s32 func_001e49d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x4000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4A80
s32 func_001e4a80(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x5000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4B30
s32 func_001e4b30(void) {
    u32 a = func_0029cc00(0);
    u32 b = func_0029cc00(1);
    func_001dbba0(func_0029d050(), a, b, 0, 0, func_001dacc0);
    return 1;
}

// FUN_001E4BB0
s32 func_001e4bb0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x6000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4C60
s32 func_001e4c60(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609D18[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4CD0
s32 func_001e4cd0(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4D40
s32 func_001e4d40(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x9000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4DF0
s32 func_001e4df0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xA000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4EA0
s32 func_001e4ea0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xB000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E4F50
s32 func_001e4f50(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xC000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5000
s32 func_001e5000(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xD000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E50B0
s32 func_001e50b0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xE000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5160
s32 func_001e5160(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0xF000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5210
s32 func_001e5210(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x10000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E52C0
s32 func_001e52c0(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609D70[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5330
s32 func_001e5330(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609D78[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E53A0
s32 func_001e53a0(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609D80[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5410
s32 func_001e5410(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x15000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E54C0
s32 func_001e54c0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x16000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5570
s32 func_001e5570(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x17000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5620
s32 func_001e5620(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x18000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E56D0
s32 func_001e56d0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x19000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5780
s32 func_001e5780(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1A000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5830
s32 func_001e5830(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1B000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E58E0
s32 func_001e58e0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x1C000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5990
s32 func_001e5990(void) {
    u8 *p = func_0029d050();
    u32 q = *(u32 *)(D_0072449C + 0x170);
    if (q != 0) {
        func_001d8bf0(p + 0x98, (u8 *)q + 0x98);
        if (!((s32 (*)(u8 *, s32))D_00609D70[0])(p, 0))
            ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    }
    return 1;
}

// FUN_001E5A20
s32 func_001e5a20(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x21000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5AD0
s32 func_001e5ad0(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609DF0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5B40
s32 func_001e5b40(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x23000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5BF0
s32 func_001e5bf0(void) {
    u32 v = (func_0029cc00(0) & 0xFFFFFF) | 0x24000000;
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5CA0
s32 func_001e5ca0(void) {
    u32 a = func_0029cc00(0);
    u32 b = func_0029cc00(1);
    func_001dbba0(func_0029d050(), a, b, 0x40, 0, func_001dacc0);
    return 1;
}

// FUN_001E5D20
s32 func_001e5d20(void) {
    u8 *p = func_0029d050();
    if (!((s32 (*)(u8 *, s32))D_00609E18[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

// FUN_001E5D90
s32 func_001e5d90(void) {
    u8 *p = func_0029d050();
    u32 a = func_0029cc00(0) & 0xFFFF;
    u32 q;
    func_00233880(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 8);
    func_00233880(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 9);
    func_00233880(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 0xA);
    func_00233880(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 0xB);
    q = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
    *(u16 *)(q + 4) = a;
    return 1;
}

// FUN_001E5E40
s32 func_001e5e40(void) {
    u8 *p = func_0029d050();
    if ((func_0029cc00(0) & 0xFFFF) == 0) {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f |= 8;
    } else {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f &= 0xFFF7;
    }
    return 1;
}

// FUN_001E5EC0
s32 func_001e5ec0(void) {
    u8 *p = func_0029d050();
    if ((func_0029cc00(0) & 0xFFFF) == 0) {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f |= 0x10;
    } else {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f &= 0xFFEF;
    }
    return 1;
}

// FUN_001E5F40
s32 func_001e5f40(void) {
    u8 *p = func_0029d050();
    *(u16 *)(p + 0x80) = func_0029cc00(0);
    *(u8 *)(p + 0x82) = func_0029cc00(1);
    return 1;
}

// FUN_001E5F90
s32 func_001e5f90(void) {
    u32 a = *(u32 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA64);
    func_0029cf50(*(u16 *)(a + 4));
    return 1;
}

// FUN_001E5FD0
s32 func_001e5fd0(void) {
    u8 *p = func_0029d050();
    u32 *r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    func_0029cf50(r != 0 ? *(u32 *)((u8 *)r + 0x20) : 0);
    return 1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6050 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001E6050
s32 func_001e6050(void) {
    u32 shift;
    u32 *r;
    {
        if (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = func_001d9280(func_0029cc00(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    func_0029cf50(r != 0 ? *(u32 *)((u8 *)r + 0x20) : 0);
    return 1;
}
#pragma opt_rebuildconditionals on

// FUN_001E60F0
s32 func_001e60f0(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 1, 0, &func_001db8d0, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6160
s32 func_001e6160(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 1, 1, &func_001db8d0, 0) & 0xFFFF);
    return 1;
}

// FUN_001E61D0
s32 func_001e61d0(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 1, 0, &func_001d9b60, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6240
s32 func_001e6240(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 2, 0, &func_001d9b60, 0) & 0xFFFF);
    return 1;
}

// FUN_001E62B0
s32 func_001e62b0(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 2, 0, &func_001db8d0, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6320
s32 func_001e6320(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 2, 1, &func_001db8d0, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6390
s32 func_001e6390(void) {
    u8 *p = func_0029d050();
    func_0029cf50(func_001d9390(p, func_0029cc00(0), 0x80000, 1, 0, &func_001d9740, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6400
s32 func_001e6400(void) {
    func_0029cf50(func_001ef4d0((1 << (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2))) & 0xFFFF, 0x80000) & 0xFFFF);
    return -1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6450 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001E6450
s32 func_001e6450(void) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_0029cf50(func_001ef4d0((1 << (shift & 0xffff)) & 0xffff, 0x80000) & 0xFFFF);
    return -1;
}
#pragma opt_rebuildconditionals on

// FUN_001E64C0
s32 func_001e64c0(void) {
    u8 *p = func_0029d050();
    short r = (short)func_0029cc00(0);
    func_0029cf50(func_0023d8e0(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), (u16)r));
    return -1;
}

// FUN_001E6530
s32 func_001e6530(void) {
    func_0029d050();
    func_0029cf50(func_001ef720(1, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6570
s32 func_001e6570(void) {
    func_0029d050();
    func_0029cf50(func_001ef720(2, 0) & 0xFFFF);
    return -1;
}

// FUN_001E65B0
s32 func_001e65b0(void) {
    func_0029cf50(func_00231ed0(*(u32 *)(*(u8 **)((u8 *)func_0029d050() + 0x30) + 0xA64)) & 0xFFFF);
    return -1;
}

// FUN_001E65F0
s32 func_001e65f0(void) {
    u32 a = func_0029cc00(0);
    u32 b = func_0029cc00(1);
    u8 *p = func_001b0cc0(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x1000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x1000000) & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E66C0
s32 func_001e66c0(void) {
    u32 a = func_0029cc00(0);
    u32 b = func_0029cc00(1);
    u8 t = func_002340c0(*(u32 *)(*(u8 **)((u8 *)func_001b0cc0(a & 0xFFFFFFF) + 0x30) + 0xA64), b) != 0;
    func_0029cf50(t != 0);
    return 1;
}

// FUN_001E6740
s32 func_001e6740(void) {
    u8 *p = func_0029d050();
    u8 *q = func_001b0cc0(func_0029cc00(0) & 0xFFFFFFF);
    s32 x = func_00235520(0, *(u32 *)(*(u8 **)(p + 0x30) + 0xA64), *(u32 *)(*(u8 **)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1);
    s32 off;
    s32 sum;
    func_00233bb0(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64));
    func_00233bb0(*(u32 *)(*(u8 **)(q + 0x30) + 0xA64));
    off = (s32)(func_00231ed0(*(u32 *)(*(u8 **)(q + 0x30) + 0xA64)) & 0xFFFF);
    sum = off + x;
    func_0029cf50(sum <= 0);
    return 1;
}

// FUN_001E6820
s32 func_001e6820(void) {
    u32 temp_16;
    u32 temp_17;
    u8 *temp_18;

    temp_18 = (u8 *)(func_0029d050());
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_0029cf50(~func_001de000(temp_18, func_001b0cc0(temp_17 & 0xFFFFFFF), (s16) temp_16, 0) != 0);
    return 1;
}



// FUN_001E68C0
s32 func_001e68c0(void) {
    u32 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_001b0cc0(temp_16 & 0xFFFFFFF);
    func_0029cf50(0U);
    return 1;
}



// FUN_001E6930
s32 func_001e6930(void) {
    u32 a = func_0029cc00(0);
    u32 b = func_0029cc00(1);
    u8 *p = func_001b0cc0(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x3F000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x3F000000) & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}

// FUN_001E6A00
s32 func_001e6a00(void) {
    func_0029cf50(*(u8 *)(*(u8 **)(func_001b0cc0(func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA2) == 0);
    return 1;
}
// FUN_001E6A50
s32 func_001e6a50(void) {
    s32 r0 = func_0029cc00(0);
    s32 r1 = func_0029cc00(1);
    u8 *q = func_001b0cc0(r0 & 0xFFFFFFF);
    s32 idx = r1 & 0xFFFF;
    s32 x;
    if (idx >= 0x240)
        func_0046d730(D_006095E0, 0x45F);
    q = *(u8 **)(q + 0x30);
    if (idx < 0x1B8) {
        if (func_00232710(*(u32 *)(q + 0xA64), 0x80008) != 0)
            x = 0;
        else if (func_00232730(*(u32 *)(q + 0xA64), idx) == 0)
            x = 0;
        else if (func_0023ddc0(*(u32 *)(q + 0xA64), idx) != 0)
            x = 0;
        else
            goto one;
    } else if (func_00232730(*(u32 *)(q + 0xA64), idx) != 0)
        goto one;
    else
        x = 0;
    goto done;
one:
    x = 1;
done:
    func_0029cf50(x != 0);
    return 1;
}

