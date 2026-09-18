/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonRing.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

typedef struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;

extern u8 *func_00484490();
extern void func_0046d730();
extern u8 *func_0049a370(u16 arg0, u8 *arg1);
extern u8 D_00713EF0[];
extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void func_0049a570(void *arg0);

extern void func_0044ea90();
extern void func_0043f810(void *dst, void *src, u32 size);
extern u8 *func_00482f70(u32 arg0, u32 arg1, u32 arg2, void *arg3, u32 arg4);
extern f32 func_004bd0b0();
extern u8 D_00713390[];
extern s32 func_0048abd0();
extern void func_004836b0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00483490(int arg0, int arg1);
extern f32 iGpffff8044;
extern f32 fGpffff8044;
extern void func_0049a610(void *arg0);
extern u8 *func_00482dc0();
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00713330[];
extern LineNovaColor iGpffffbb64;
extern u_long128 D_00713CE0[];
extern s32 D_00713F24[];
extern u32 D_00713F14[];
extern u32 D_00713F10[];
extern void func_0049a6c0(void *arg0);
extern u8 *func_003c2290(u8 *arg0, s32 arg1);
extern void func_003c22f0(void *arg0);
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b7b0(f32 arg0);
extern f32 fGpffff80d0;
extern f32 fabsf(f32 x);
extern f32 D_00713D10[];
extern f32 D_00713D14[];
extern f32 D_00713D18[];
extern void func_0049a660(u8 *arg0);



// FUN_00498DA0
u8 *func_00498da0(u8 *arg0) {
    u8 *alloc;
    u8 *p2;
    s32 count;
    s32 v44;
    s32 v48;
    s32 v4C;
    u32 i;
    u8 *dst;

    func_0044ea90(D_00713EF0, 0x39);
    alloc = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (alloc == NULL) {
        func_0046d730(D_00713EF0, 0x3A);
    }
    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    p2 = func_00482dc0(*(u16 *)(arg0 + 0x38), D_00713330, 4, 0x48);
    *(u32 *)alloc = (u32)p2;
    count = *(s16 *)(p2 + 8) / 4;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(p2 + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    v4C = *(s32 *)(arg0 + 0x4C);
    i = 0;
    while (i < (u32)count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v48;
        *(s32 *)(dst + 8) = v48;
        *(s32 *)(dst + 0xC) = v4C;
        i++;
        dst += 0x10;
    }
    return alloc;
}
// FUN_00498EC0
void func_00498ec0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}



/* measured: FP side fully matched - the fade math, the FMA fusion (adda/madd),
   the split VU0 asm blocks (lqc2/vmove/mfc1/qmtc2/vmulx + per-slot sqc2 so
   the operand addiu interleaves like retail), the doubling ((f32)t + (f32)t,
   never 2.0f * t which emits mul.s) and the FP saved/temp pools (declared
   var_f5, temp_f0, temp_f4, temp_f3, var_f1 in that order - the FP temp pool
   follows declaration order). The residual is the saved-GPR pool rotation:
   mwcc b210 pins temp_17/temp_18 to $s0/$s1 and moves var_16 between $s2/$s3
   with declaration order, while retail allocates var_16 to $s0, temp_17 $s1,
   temp_18 $s2, arg0 $s3 - a one-slot rotation that cascades 46 words (nd 46).
   Tried var_16 declared first/last/mid, pointer pair swapped - the pair never
   leaves $s0/$s1. Same recorded allocator-pool floor family as
   effPolygonFlash FUN_0049D360/0049E150 (5 declaration orders tried there). */
// FUN_00498F10 NONMATCHING
/* measured: banked reconstruction scores GUARDED_SCORE 34
   (`python3 tools/measure_guarded.py src/promoted/effPolygonRing.c
   func_00498f10`). Path: v1 nd 207 (missed temp_17 double-deref) -> v3 nd
   36 (double-deref + pair-quad for the sin/cos const stores mwcc deleted as
   dead + FP saved-pool order temp_f22/var_f21/temp_f20 + FMA addend swap +
   mul/add split across statements) -> v4 nd 34 (`q |=` restores srl/andi
   order). Residual: 30 words saved-GPR pool rotation (retail
   var_16/temp_17/temp_18/reuse $s0/$s1/$s2, mwcc pins the pair $s0/$s1;
   declaration-order floor per in-file note) + 4 words or/cvt coalescing
   (`or` dest $v0 vs $v1 with mtc1/cvt/add following; `|=` and operand swap
   tried, same floor as wind func_004A4450). Beats the prior claimed nd 46. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/effPolygonRing.c func_00498f10 --pairs` banked 34; best ties 34 (opt_dead_assignments off, opt_loop_invariants on, opt_propagation off, opt_strength_reduction off, opt_unroll_loops off and ten pairwise combos among them); all 28 pairs neutral or worse (schedule 195-202, commons 198-223, peephole 202-223). Confirms saved-GPR rotation + or/cvt floor per above. Floor stands; production stays ASM. */
#ifdef NON_MATCHING
void func_00498f10(u8 *arg0)
{
    u_long128 pair;
    u_long128 slot80;
    u_long128 slot70;
    u_long128 slot60;
    f32 var_f5;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f3;
    f32 var_f1;
    f32 temp_f22;
    f32 var_f21;
    f32 temp_f20;
    f32 sum0;
    f32 sum1;
    f32 sum2;
    s32 temp_3;
    s32 temp_4;
    s16 temp_2;
    s32 temp_2_2;
    s32 q;
    s32 var_16;
    u32 var_18;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *var_19;

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    temp_18 = *(u8 **)(arg0 + 0x40);
    temp_4 = *(s32 *)(arg0 + 0x34);
    temp_3 = *(s32 *)(temp_18 + 0x34);
    if ((temp_3 >= temp_4) || (temp_3 == 0)) {
        if (*(u8 *)(temp_18 + 0x68) != 0) {
            var_f5 = (f32)(temp_3 - temp_4);
        } else {
            var_f5 = (f32)temp_4;
        }
        temp_f3 = fabsf(*(f32 *)(temp_18 + 0x60));
        temp_f4 = *(f32 *)(temp_18 + 0x64);
        if (temp_f4 < 0.0f) {
            temp_f0 = 0.5f * (-temp_f3 / (0.5f * temp_f4));
            if (!(var_f5 <= temp_f0)) {
                var_f5 = temp_f0;
            }
        }
        sum2 = temp_f4 * var_f5;
        temp_f0 = 0.5f * sum2 + temp_f3;
        temp_f22 = var_f5 * temp_f0;
        temp_f22 += *(f32 *)(temp_18 + 0x40);
        temp_2 = *(s16 *)(temp_17 + 8);
        var_16 = temp_2 >> 2;
        if (temp_2 < 0) {
            var_16 = (temp_2 + 3) >> 2;
        }
        func_003c2290(*(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18), 2);
        var_19 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18) + 0x5C) + 0x14);
        var_f21 = 0.0f;
        temp_2_2 = *(s32 *)(temp_18 + 0x38);
        if (temp_2_2 >= 0) {
            var_f1 = (f32)temp_2_2;
        } else {
            q = (u32)temp_2_2 >> 1;
            q |= temp_2_2 & 1;
            var_f1 = (f32)q + (f32)q;
        }
        temp_f20 = fGpffff80d0 / var_f1;
        ((s32 *)&pair)[1] = 0;
        ((s32 *)&pair)[3] = 0x3F800000;
        sum0 = *(f32 *)(temp_18 + 0x50) + temp_f22;
        sum1 = sum0 + *(f32 *)(temp_18 + 0x54);
        sum2 = sum1 + *(f32 *)(temp_18 + 0x58);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vmove.xyzw $vf11, $vf10 \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            :
            : "r"(D_00713CE0), "f"(sum0)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&slot80) : "memory");
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf11 \n"
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(sum1), "f"(sum2)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&slot70) : "memory");
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(&slot60) : "memory");
        var_18 = 0;
        while (var_18 < (u32)var_16) {
            ((f32 *)&pair)[0] = func_0044b610(var_f21);
            ((f32 *)&pair)[2] = func_0044b7b0(var_f21);
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmove.xyzw $vf11, $vf10 \n"
                "mfc1 $2, %1 \n"
                "nop \n"
                "qmtc2.ni $2, $vf2 \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                :
                : "r"(&pair), "f"(temp_f22)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            *(f32 *)(var_19 + 0) = D_00713D10[0];
            *(f32 *)(var_19 + 4) = D_00713D14[0];
            *(f32 *)(var_19 + 8) = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&slot80)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            *(f32 *)(var_19 + 0xC) = D_00713D10[0];
            *(f32 *)(var_19 + 0x10) = D_00713D14[0];
            *(f32 *)(var_19 + 0x14) = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&slot70)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            *(f32 *)(var_19 + 0x18) = D_00713D10[0];
            *(f32 *)(var_19 + 0x1C) = D_00713D14[0];
            *(f32 *)(var_19 + 0x20) = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&slot60)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            *(f32 *)(var_19 + 0x24) = D_00713D10[0];
            *(f32 *)(var_19 + 0x28) = D_00713D14[0];
            *(f32 *)(var_19 + 0x2C) = D_00713D18[0];
            var_f21 += temp_f20;
            var_18 += 1;
            var_19 += 0x30;
        }
        temp_16 = *(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18);
        func_003c22f0(temp_16);
        if (*(u16 *)temp_17 & 4) {
            *(u16 *)(temp_16 + 0xC) = *(u16 *)(temp_16 + 0xC) | 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00498f10);
#endif

/* Ported from P3FES mdlEffect.c FUN_00338360 (twin of func_0049a1a0).
   The VU0 colour-modulate block is genuine hardware asm (Category B) ported
   as inline asm with the pointer passed via a "r" constraint, not a bare
   addiu block. MATCH. */
// FUN_004992A0
void func_004992a0(u8 *param_1)
{
  u8 *iVar5;
  u8 *iVar1;
  u16 *puVar2;
  u8 colourStack[16];
  int iVar3;
  int iVar4;
  int iVar6;
  u8 *dest;
  f32 scale;
  u8 *cs8;

  iVar5 = (u8 *)param_1;
  iVar3 = *(int *)(iVar5 + 0x3c);
  iVar1 = *(u8 **)(iVar5 + 0x40);
  puVar2 = *(u16 **)iVar3;
  iVar6 = *(int *)(iVar5 + 0x34);
  iVar4 = *(int *)(iVar1 + 0x34);
  if (((u32)iVar6 <= (u32)iVar4) || (iVar4 == 0)) {
    iVar3 = func_0048abd0((char *)iVar1, (u32 *)(iVar1 + 0x24), iVar6, iVar4);
    *(u32 *)&colourStack[8] = *(u32 *)(iVar5 + 0x30);
    cs8 = &colourStack[8];
    scale = iGpffff8044;
    __asm__ volatile (
        ".set noreorder                  \n"
        "lw          $2, 0(%0)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $2, %2              \n"
        "nop                               \n"
        "qmtc2       $2, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmove.xyzw  $vf11, $vf10        \n"
        "sw          %1, 0x44($sp)       \n"
        "addiu       $2, $sp, 0x44       \n"
        "lw          $2, 0($2)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $3, %2              \n"
        "nop                               \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmul.xyzw   $vf10, $vf10, $vf11 \n"
        "lui         $3, 0x437F          \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10        \n"
        "qmfc2       $3, $vf10           \n"
        "ppach       $3, $zero, $3       \n"
        "ppacb       $3, $zero, $3       \n"
        "sw          $3, 0x40($sp)       \n"
        ".set reorder"
        :
        : "r"(cs8), "r"((u32)iVar3), "f"(scale)
        : "$2", "$3", "memory");
    *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
    if (colourStack[15] != 0xff) {
      dest = *(u8 **)(puVar2 + 10);
      *(RwRGBA *)(dest + 4) = *(RwRGBA *)&colourStack[12];
    }
    else {
      colourStack[15] = 0xfe;
      dest = *(u8 **)(puVar2 + 10);
      *(RwRGBA *)(dest + 4) = *(RwRGBA *)&colourStack[12];
      colourStack[15] = 0xff;
    }
    if (*(u8 *)(*(int *)(puVar2 + 10) + 7) != 0) {
      func_004836b0(puVar2, iVar5, iVar5 + 0x10, iVar5 + 0x20);
      if (*(u8 *)(iVar1 + 0x3c) != 0) {
        *puVar2 = *puVar2 | 1;
      }
      else {
        *puVar2 = *puVar2 & 0xfffe;
      }
      func_00483490((int)puVar2, *(u16 *)(iVar1 + 0x28));
    }
  }
}
// FUN_00499470
void func_00499470(u8 *arg0) {
    u8 *p8;
    u8 *p3;
    u8 *dst;

    p8 = *(u8 **)(arg0 + 0x3C);
    p3 = *(u8 **)(p8 + 8);
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p3 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p3 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    func_0049a610(*(void **)(p8 + 4));
}

// FUN_00499510
u8 *func_00499510(u8 *arg0) {
    u8 *work;
    u8 *p;
    u32 count;
    u32 stride;
    u32 i;
    u8 *dst;
    s32 v44;
    s32 v48;
    s32 avg;
    f32 f20;
    f32 t;

    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    count = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713EF0, 0x10F);
    stride = count * 4;
    p = (u8 *)(*jtbl_008873E8)(stride + 0x10, 0x40000);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x110);
    }
    work = p + stride;
    *(u32 *)(work + 0) = (u32)p;
    *(u32 *)(work + 0xC) = (u32)p;
    func_0043f810(arg0 + 0x5C, arg0, 0x5C);
    *(u32 *)(work + 4) = (u32)func_0049a370(1, arg0 + 0x5C);
    *(u32 *)(work + 8) = (u32)func_00482f70(count & 0xFFFF, 2, 4, D_00713390, 0x48);
    dst = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(work + 8) + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    i = 0;
    avg = (v44 & v48) + (s32)(((u32)(v44 ^ v48) & 0xFEFEFEFE) >> 1);
    while (i < count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v44;
        *(s32 *)(dst + 8) = avg;
        *(s32 *)(dst + 0xC) = v44;
        f20 = *(f32 *)(arg0 + 0xCC);
        t = func_004bd0b0(0);
        *(f32 *)(p + 0) = *(f32 *)(arg0 + 0xC8) * ((1.0f - f20) + f20 * t);
        i++;
        dst += 0x10;
        p += 4;
    }
    return work;
}
// FUN_004996E0
void func_004996e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 8));
    func_0049a570(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0xC));
}



/* measured: same saved-GPR pool rotation as the rest of this unit - retail
   allocates temp_16 $s0, temp_17 $s1, var_18 $s2, temp_19 $s3, temp_20 $s4,
   temp_21 $s5 while mwcc b210 pins temp_17 to $s0, var_18 $s1, temp_16 $s2
   regardless of declaration order (nd 152, rotation cascades through the
   8-saved-register loop). The 13 hoisted %hi D_00713D10/14/18 lui bases, the
   vrsqrt chain (vmulax/vmadday/vmaddz/vrsqrt/vwaitq/vmulq as one asm block
   with "$22"-clobber forcing the saved $22), the var_8==0 pointer math and
   the tail all reproduce otherwise. allocator-pool floor family. */
// FUN_00499730 NONMATCHING
/* measured: banked reconstruction scores GUARDED_SCORE 83
   (`python3 tools/measure_guarded.py src/promoted/effPolygonRing.c
   func_00499730`). Path: v1 nd 184 (plain-C + split VU0 blocks, no hoist
   pragma, 6-saved frame) -> v2 nd 83 (`"$22"` clobber on the vrsqrt asm
   restores the 7th saved reg and the 0x90 frame; opt_loop_invariants hoists
   the 13 %hi bases + $3 full address to the preheader; stride moved next to
   allocator coloring with no opcode/signedness/width defect (verified by
   inspection: no surplus dsll32/lbu/cvt/div/jalr): saved-GPR one-slot
   rotation, loop-temp coloring (counter/var_7/var_6/limit/bias land
   $a3/$t0/$t1/$a2/$a1 vs retail $t0/$a3/$a2/$a1/$a0), stride scratch via
   temps vs $s6, mfc1/qmtc2 via $2 vs $22. Beats the prior claimed nd 152
   (no body was ever banked for that number). */
#ifdef NON_MATCHING
/* measured: without opt_loop_invariants, mwcc rematerializes the 13
   D_00713D10/14/18 %hi bases inside the loop; with it they hoist to the
   preheader like retail (same waiver idiom as wind func_004A3010). */
#pragma opt_loop_invariants on
void func_00499730(u8 *arg0)
{
    u8 *temp_3;
    u8 *temp_5;
    u8 **temp_17;
    u8 *temp_19;
    u8 *temp_16;
    u8 *temp_18a;
    s32 temp_21;
    s32 temp_20;
    f32 step;
    u32 limit;
    u8 *temp_4;
    s32 stmp;
    s32 stride;
    u8 *var_6;
    u8 *var_7;
    u32 counter;
    s32 bias;
    u8 *addr;
    f32 fscale;
    f32 t2;
    f32 t1;
    f32 t0;
    u8 *temp_18b;
    u8 *temp_17b;
    u8 *temp_17c;

    temp_3 = *(u8 **)(arg0 + 0x3C);
    temp_5 = *(u8 **)(temp_3 + 4);
    temp_17 = *(u8 ***)(temp_5 + 0x3C);
    temp_19 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_3 + 8);
    temp_18a = *(u8 **)temp_3;
    temp_21 = *(s32 *)(arg0 + 0x34);
    temp_20 = *(s32 *)(temp_19 + 0x34);
    if ((temp_20 >= temp_21) || (temp_20 == 0)) {
        func_0049a660(temp_5);
        step = (f32)temp_21 / (f32)temp_20;
        func_003c2290(*(u8 **)(*(u8 **)(temp_16 + 0x10) + 0x18), 2);
        func_003c2290(*(u8 **)(*(u8 **)(*temp_17 + 0x10) + 0x18), 2);
        limit = *(u32 *)(temp_19 + 0x38);
        temp_4 = *temp_17;
        stmp = *(s16 *)(temp_4 + 8) - 1;
        var_7 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_16 + 0x10) + 0x18) + 0x5C) + 0x14);
        var_6 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_4 + 0x10) + 0x18) + 0x5C) + 0x14);
        if (*(u8 *)(temp_19 + 0xC4) == 0) {
            counter = 0;
            bias = -0x48;
            stride = stmp * 12;
            while (counter < limit) {
                D_00713D10[0] = *(f32 *)(var_6 + 0xC);
                D_00713D14[0] = *(f32 *)(var_6 + 0x10);
                D_00713D18[0] = *(f32 *)(var_6 + 0x14);
                __asm__ volatile(
                    "lqc2 $vf10, 0(%0) \n"
                    "vmove.xyzw $vf12, $vf10 \n"
                    :
                    : "r"(D_00713D10)
                    : "$vf10", "$vf12", "memory");
                D_00713D10[0] = *(f32 *)(var_6 + 0x24);
                D_00713D14[0] = *(f32 *)(var_6 + 0x28);
                D_00713D18[0] = *(f32 *)(var_6 + 0x2C);
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0) \n"
                    "sqc2 $vf10, 0(%0) \n"
                    :
                    : "r"(D_00713D10)
                    : "$vf10", "$vf11", "memory");
                *(f32 *)(var_7 + 0x18) = D_00713D10[0];
                *(f32 *)(var_7 + 0x1C) = D_00713D14[0];
                *(f32 *)(var_7 + 0x20) = D_00713D18[0];
                __asm__ volatile(
                    "vsub.xyzw $vf10, $vf10, $vf11 \n"
                    "vmul.xyz $vf2, $vf10, $vf10 \n"
                    "vmulax.w $ACC, $vf0, $vf2x \n"
                    "vmadday.w $ACC, $vf0, $vf2y \n"
                    "vmaddz.w $vf2, $vf0, $vf2z \n"
                    "vrsqrt $Q, $vf0w, $vf2w \n"
                    "vwaitq \n"
                    "vmulq.xyz $vf10, $vf10, $Q \n"
                    :
                    :
                    : "$vf2", "$vf10", "$vf11", "$vf12", "$22", "ACC", "Q", "memory");
                fscale = *(f32 *)temp_18a * step;
                __asm__ volatile(
                    "mfc1 $2, %0 \n"
                    "nop \n"
                    "qmtc2.ni $2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    :
                    : "f"(fscale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
                *(f32 *)(var_7 + 0) = D_00713D10[0];
                *(f32 *)(var_7 + 4) = D_00713D14[0];
                *(f32 *)(var_7 + 8) = D_00713D18[0];
                t2 = *(f32 *)(var_6 + 0x3C);
                t1 = *(f32 *)(var_6 + 0x40);
                t0 = *(f32 *)(var_6 + 0x44);
                *(f32 *)(var_7 + 0xC) = t2;
                *(f32 *)(var_7 + 0x10) = t1;
                *(f32 *)(var_7 + 0x14) = t0;
                if (counter == 0) {
                    addr = var_6 + stride + bias;
                    t2 = *(f32 *)(addr + 0);
                    t1 = *(f32 *)(addr + 4);
                    t0 = *(f32 *)(addr + 8);
                    *(f32 *)(var_7 + 0x24) = t2;
                    *(f32 *)(var_7 + 0x28) = t1;
                    *(f32 *)(var_7 + 0x2C) = t0;
                } else {
                    t2 = *(f32 *)(var_6 - 0x24);
                    t1 = *(f32 *)(var_6 - 0x20);
                    t0 = *(f32 *)(var_6 - 0x1C);
                    *(f32 *)(var_7 + 0x24) = t2;
                    *(f32 *)(var_7 + 0x28) = t1;
                    *(f32 *)(var_7 + 0x2C) = t0;
                }
                counter += 1;
                var_7 += 0x30;
                var_6 += 0x30;
                temp_18a += 4;
            }
        }
        temp_18b = *temp_17;
        temp_17b = *(u8 **)(*(u8 **)(temp_18b + 0x10) + 0x18);
        func_003c22f0(temp_17b);
        if (*(u16 *)temp_18b & 4) {
            *(u16 *)(temp_17b + 0xC) = *(u16 *)(temp_17b + 0xC) | 1;
        }
        temp_17c = *(u8 **)(*(u8 **)(temp_16 + 0x10) + 0x18);
        func_003c22f0(temp_17c);
        if (*(u16 *)temp_16 & 4) {
            *(u16 *)(temp_17c + 0xC) = *(u16 *)(temp_17c + 0xC) | 1;
        }
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499730);
#endif

// FUN_00499A30
void func_00499a30(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_17;
    u8 colourStack[16];
    s32 temp_3;
    u8 *dest;
    u8 *cs8;
    f32 scale;
    u_long128 *dstq;

    temp_16 = *(u8 **)(arg0 + 0x3C);
    temp_18 = *(u8 **)(arg0 + 0x40);
    temp_17 = *(u8 **)(temp_16 + 8);
    if ((*(u32 *)(temp_18 + 0x34) >= *(u32 *)(arg0 + 0x34)) ||
        (*(u32 *)(temp_18 + 0x34) == 0)) {
        temp_3 = func_0048abd0(temp_18, temp_18 + 0x24,
                               *(u32 *)(arg0 + 0x34),
                               *(u32 *)(temp_18 + 0x34));
        *(u32 *)&colourStack[8] = *(u32 *)(arg0 + 0x30);
        cs8 = &colourStack[8];
        scale = fGpffff8044;
        __asm__ volatile(
            ".set noreorder              \n"
            "lw $2, 0(%0)                 \n"
            "pextlb $2, $0, $2            \n"
            "pextlh $2, $0, $2            \n"
            "qmtc2.ni $2, $vf10           \n"
            "vitof0.xyzw $vf10, $vf10     \n"
            "mfc1 $2, %2                 \n"
            "nop                         \n"
            "qmtc2.ni $2, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10      \n"
            "sw %1, 0x54($sp)             \n"
            "addiu $2, $sp, 0x54          \n"
            "lw $2, 0($2)                 \n"
            "pextlb $2, $0, $2            \n"
            "pextlh $2, $0, $2            \n"
            "qmtc2.ni $2, $vf10           \n"
            "vitof0.xyzw $vf10, $vf10     \n"
            "mfc1 $3, %2                 \n"
            "nop                         \n"
            "qmtc2.ni $3, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F               \n"
            "qmtc2.ni $3, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10    \n"
            "qmfc2.ni $3, $vf10           \n"
            "ppach $3, $0, $3             \n"
            "ppacb $3, $0, $3             \n"
            "sw $3, 0x50($sp)             \n"
            ".set reorder                \n"
            :
            : "r"(cs8), "r"(temp_3), "f"(scale)
            : "$2", "$3", "memory");
        *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
        if (colourStack[15] != 0xFF) {
            dest = *(u8 **)(temp_17 + 0x14);
            *(LineNovaColor *)(dest + 4) =
                *(LineNovaColor *)&colourStack[12];
        } else {
            colourStack[15] = 0xFE;
            dest = *(u8 **)(temp_17 + 0x14);
            *(LineNovaColor *)(dest + 4) =
                *(LineNovaColor *)&colourStack[12];
            colourStack[15] = 0xFF;
        }
        if (*(u8 *)(*(u8 **)(temp_17 + 0x14) + 7) != 0) {
            *(s32 *)(*(u8 **)(temp_16 + 4) + 0x30) =
                *(s32 *)(arg0 + 0x30);
            dstq = (u_long128 *)(*(u8 **)(temp_16 + 4) + 0x20);
            *dstq = *(u_long128 *)(arg0 + 0x20);
            dstq = (u_long128 *)(*(u8 **)(temp_16 + 4) + 0x0);
            *dstq = *(u_long128 *)(arg0 + 0x0);
            dest = *(u8 **)(temp_16 + 4);
            dstq = (u_long128 *)(dest + 0x10);
            *dstq = *(u_long128 *)(arg0 + 0x10);
            func_0049a6c0(*(void **)(temp_16 + 4));
            func_004836b0(temp_17, arg0, arg0 + 0x10, arg0 + 0x20);
            if (*(u8 *)(temp_18 + 0x3C) != 0) {
                *(u16 *)temp_17 = *(u16 *)temp_17 | 1;
            } else {
                *(u16 *)temp_17 = *(u16 *)temp_17 & 0xFFFE;
            }
            func_00483490((s32)temp_17, *(u16 *)(temp_18 + 0x28));
        }
    }
}

// FUN_00499C50
void func_00499c50(u8 *arg0) {
    u8 *p4;
    u8 *dst;

    p4 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p4 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p4 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
}

// FUN_00499CD0
u8 *func_00499cd0(u8 *arg0) {
    u8 *alloc;
    u8 *p2;
    s32 count;
    s32 v44;
    s32 v48;
    s32 v4C;
    u32 i;
    u8 *dst;

    func_0044ea90(D_00713EF0, 0x1E6);
    alloc = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (alloc == NULL) {
        func_0046d730(D_00713EF0, 0x1E7);
    }
    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    p2 = func_00482dc0(*(u16 *)(arg0 + 0x38), D_00713330, 4, 0x48);
    *(u32 *)alloc = (u32)p2;
    count = *(s16 *)(p2 + 8) / 4;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(p2 + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    v4C = *(s32 *)(arg0 + 0x4C);
    i = 0;
    while (i < (u32)count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v48;
        *(s32 *)(dst + 8) = v48;
        *(s32 *)(dst + 0xC) = v4C;
        i++;
        dst += 0x10;
    }
    return alloc;
}
// FUN_00499DF0
void func_00499df0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}

/* measured: re-derived via probe (this wave): direct (f32)*(u32*)(0x38) unsigned, tmp2/4 direct, opt_propagation off. Probe 94 differing words (`python3 source/Persona4-Decompilation/tools/probe_variants.py source/Persona4-Decompilation/src/promoted/effPolygonRing.c func_00499e40 --candidate src99fixed=/tmp/src99e40_candidate2.c`); GUARDED_SCORE 94 (`python3 source/Persona4-Decompilation/tools/measure_guarded.py source/Persona4-Decompilation/src/promoted/effPolygonRing.c func_00499e40`); hw-TU verify obj868/win864 (0.5% within 3%) nd246. Guarded floor (GPR/FP rotation + VU interleave remain). */
// FUN_00499E40 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
void func_00499e40(u8 *arg0)
{
    u8 *temp_18;
    u8 *temp_17;
    s32 temp_4;
    s32 temp_3;
    s16 tmp2;
    s32 var_16;
    u32 var_18;
    u8 *var_19;
    f32 var_f5;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f3;
    f32 var_f1;
    f32 zero;
    f32 step;
    f32 phase;
    f32 fade;
    f32 f2;
    f32 f1;
    f32 f0;
    f32 sp60[4];
    f32 sp70[4];
    f32 sp80[4];
    s32 stk[4];
    f32 cosv;
    f32 sinv;
    u8 *tmp16;

    {
        u8 *tmp3p = *(u8 **)(arg0 + 0x3C);
        temp_18 = *(u8 **)(arg0 + 0x40);
        temp_17 = *(u8 **)tmp3p;
        temp_4 = *(s32 *)(arg0 + 0x34);
        temp_3 = *(s32 *)(temp_18 + 0x34);
    }
    if ((temp_3 >= temp_4) || (temp_3 == 0)) {
        if (*(u8 *)(temp_18 + 0x64) != 0) {
            var_f5 = (f32)(temp_3 - temp_4);
        } else {
            var_f5 = (f32)temp_4;
        }
        temp_f3 = fabsf(*(f32 *)(temp_18 + 0x5C));
        temp_f4 = *(f32 *)(temp_18 + 0x60);
        if (temp_f4 < 0.0f) {
            temp_f0 = 0.5f * (-temp_f3 / (0.5f * temp_f4));
            if (var_f5 > temp_f0) {
                var_f5 = temp_f0;
            }
        }
        f2 = temp_f4 * var_f5;
        f0 = temp_f3 + 0.5f * f2;
        f1 = var_f5 * f0;
        fade = f1 + *(f32 *)(temp_18 + 0x40);
        tmp2 = *(s16 *)(temp_17 + 8);
        var_16 = tmp2 / 4;
        func_003c2290(*(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18), 2);
        var_19 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18) + 0x5C) + 0x14);
        phase = 0.0f;
        var_f1 = (f32)*(u32 *)(temp_18 + 0x38);
        step = fGpffff80d0 / var_f1;
        zero = 0.0f;
        stk[1] = 0;
        stk[3] = 0x3F800000;
        f2 = *(f32 *)(temp_18 + 0x50) + fade;
        f1 = f2 + *(f32 *)(temp_18 + 0x54);
        f0 = f1 + *(f32 *)(temp_18 + 0x58);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vmove.xyzw $vf11, $vf10 \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            : : "r"(D_00713CE0), "f"(f2) : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(sp80) : "$vf10", "memory");
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf11 \n"
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            : : "f"(f1) : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(sp70) : "$vf10", "memory");
        __asm__ volatile(
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            : : "f"(f0) : "$2", "$vf2", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(sp60) : "$vf11", "memory");
        var_18 = 0;
        while (var_18 < (u32)var_16) {
            cosv = func_0044b610(phase);
            sinv = func_0044b7b0(phase);
            *(f32 *)&stk[0] = cosv;
            *(f32 *)&stk[2] = sinv;
            *(f32 *)(var_19 + 0) = zero;
            *(f32 *)(var_19 + 4) = zero;
            *(f32 *)(var_19 + 8) = zero;
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(stk) : "$vf11", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp80) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            *(f32 *)(var_19 + 0xC) = D_00713D10[0];
            *(f32 *)(var_19 + 0x10) = D_00713D14[0];
            *(f32 *)(var_19 + 0x14) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp70) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            *(f32 *)(var_19 + 0x18) = D_00713D10[0];
            *(f32 *)(var_19 + 0x1C) = D_00713D14[0];
            *(f32 *)(var_19 + 0x20) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp60) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            *(f32 *)(var_19 + 0x24) = D_00713D10[0];
            *(f32 *)(var_19 + 0x28) = D_00713D14[0];
            *(f32 *)(var_19 + 0x2C) = D_00713D18[0];
            phase = phase + step;
            var_18 += 1;
            var_19 += 0x30;
        }
        tmp16 = *(u8 **)(*(u8 **)(temp_17 + 0x10) + 0x18);
        func_003c22f0(tmp16);
        if (*(u16 *)temp_17 & 4) {
            *(u16 *)(tmp16 + 0xC) = *(u16 *)(tmp16 + 0xC) | 1;
        }
    }
}
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499e40);
#endif

/* Ported from P3FES mdlEffect.c FUN_00338360 (twin of func_004992a0).
   Same VU0 inline-asm + constraint-pointer shape as its twin. MATCH. */
// FUN_0049A1A0
void func_0049a1a0(u8 *param_1)
{
  u8 *iVar5;
  u8 *iVar1;
  u16 *puVar2;
  u8 colourStack[16];
  int iVar3;
  int iVar4;
  int iVar6;
  u8 *dest;
  f32 scale;
  u8 *cs8;

  iVar5 = (u8 *)param_1;
  iVar3 = *(int *)(iVar5 + 0x3c);
  iVar1 = *(u8 **)(iVar5 + 0x40);
  puVar2 = *(u16 **)iVar3;
  iVar6 = *(int *)(iVar5 + 0x34);
  iVar4 = *(int *)(iVar1 + 0x34);
  if (((u32)iVar6 <= (u32)iVar4) || (iVar4 == 0)) {
    iVar3 = func_0048abd0((char *)iVar1, (u32 *)(iVar1 + 0x24), iVar6, iVar4);
    *(u32 *)&colourStack[8] = *(u32 *)(iVar5 + 0x30);
    cs8 = &colourStack[8];
    scale = iGpffff8044;
    __asm__ volatile (
        ".set noreorder                  \n"
        "lw          $2, 0(%0)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $2, %2              \n"
        "nop                               \n"
        "qmtc2       $2, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmove.xyzw  $vf11, $vf10        \n"
        "sw          %1, 0x44($sp)       \n"
        "addiu       $2, $sp, 0x44       \n"
        "lw          $2, 0($2)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $3, %2              \n"
        "nop                               \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmul.xyzw   $vf10, $vf10, $vf11 \n"
        "lui         $3, 0x437F          \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10        \n"
        "qmfc2       $3, $vf10           \n"
        "ppach       $3, $zero, $3       \n"
        "ppacb       $3, $zero, $3       \n"
        "sw          $3, 0x40($sp)       \n"
        ".set reorder"
        :
        : "r"(cs8), "r"((u32)iVar3), "f"(scale)
        : "$2", "$3", "memory");
    *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
    if (colourStack[15] != 0xff) {
      dest = *(u8 **)(puVar2 + 10);
      *(RwRGBA *)(dest + 4) = *(RwRGBA *)&colourStack[12];
    }
    else {
      colourStack[15] = 0xfe;
      dest = *(u8 **)(puVar2 + 10);
      *(RwRGBA *)(dest + 4) = *(RwRGBA *)&colourStack[12];
      colourStack[15] = 0xff;
    }
    if (*(u8 *)(*(int *)(puVar2 + 10) + 7) != 0) {
      func_004836b0(puVar2, iVar5, iVar5 + 0x10, iVar5 + 0x20);
      if (*(u8 *)(iVar1 + 0x3c) != 0) {
        *puVar2 = *puVar2 | 1;
      }
      else {
        *puVar2 = *puVar2 & 0xfffe;
      }
      func_00483490((int)puVar2, *(u16 *)(iVar1 + 0x28));
    }
  }
}
// FUN_0049A370
/* measured: opt_propagation off keeps the named D_00713CE0 pointer's
   lui/addiu/lq sequence instead of folding the low half into lq. */
#pragma opt_propagation off
u8 *func_0049a370(u16 arg0, u8 *arg1)
{
    u8 *p;
    u_long128 *quadSrc;
    u_long128 quad;
    s32 size;
    u32 idx;

    if (arg0 >= 4) {
        func_0046d730(D_00713EF0, 0x2BD);
    }
    idx = arg0;
    size = D_00713F24[idx * 6];
    func_0044ea90(D_00713EF0, 0x2C1);
    p = (u8 *)(*jtbl_008873E8)(size + 0x50, 0x40000);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x2C2);
    }
    *(u8 **)(p + 0x40) = p + 0x50;
    *(s32 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x38) = idx;
    *(s32 *)(p + 0x30) = -1;
    quadSrc = (u_long128 *)D_00713CE0;
    quad = *quadSrc;
    *(u_long128 *)(p + 0x20) = quad;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 vf0, 0x10(%0)" : : "r"(p) : "memory");
    func_0043f810(*(void **)(p + 0x40), arg1, size);
    *(u32 *)(p + 0x3C) =
        ((u32 (*)(u8 *))D_00713F14[arg0 * 6])(arg1);
    ((void (*)(u8 *))D_00713F10[arg0 * 6])(p);
    return p;
}
#pragma opt_propagation on
// FUN_0049A4E0
u8 *func_0049a4e0(u8 *arg0) {
    u8 *p;

    p = func_00484490(arg0);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x2E5);
    }
    p = func_0049a370(*(u16 *)(arg0 + 0xC), p);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x2E7);
    }
    return p;
}
