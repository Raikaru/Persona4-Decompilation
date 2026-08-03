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
extern void func_00483490(void *arg0, u16 arg1);
extern f32 iGpffff8044;
extern void func_0049a610(void *arg0);
extern u8 *func_00482dc0();
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00713330[];
extern LineNovaColor iGpffffbb64;
extern u_long128 D_00713CE0[];
extern s32 D_00713F24[];
extern u32 D_00713F14[];
extern u32 D_00713F10[];



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
// FUN_00498F10
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00498f10);

/* measured: byte-identical through the two VU0 colour-chain asm blocks and
   the sp40 sw; the residual is the post-block TEMP register pool. retail's
   first temp after block2 is $v1 (lw $v1,0x40($sp); addiu $t0,0xff; dst $a3;
   bytes $a2,$a1,$a0,$v1) while mwcc b210 always starts the pool at $v0
   (lw $v0; const $a3; dst $a2; bytes $a1,$a0,$v1,$v0) - a one-register
   offset that cascades 13 tail rows (nd 57). Tried: block2 clobber lists
   ($2+$3 / $3-only / $2-only), dummy "=r" output (nd 93), struct vs
   field-at-a-time color copy, load-order and declaration-order variants
   (nd 57-93). The sibling effPolygonFlash func_0049b2b0 matches because its
   block text uses $2 and retail there also pools from $v0; this function's
   retail pools from $v1 with a $3-based block. allocator-pool floor family
   (cf. effPolygonFlash FUN_0049D360/0049E150 notes). */
// FUN_004992A0
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_004992a0);

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
// FUN_00499730
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499730);

/* measured: everything matches byte-for-byte except the LAST of the three
   quadword copies (arg0+0x10): retail emits lw $v1,4($s0); lq $v0,0x10($s3);
   sq $v0,0x10($v1) but mwcc b210 emits lq $v1,0x10($s3); lw $v0,4($s0);
   sq $v0,0x10($v1) - the scheduler swaps the two independent loads of the
   final copy only (copies 1-2 come out in retail order). nd 6, exactly 3
   words. Tried: nested deref (nd 12, RHS-first eval), per-copy dest local
   (nd 6), #pragma schedule off (no effect, nd 6), pointer-local dstq/srcq
   (nd 9). The 0x30 sw copy, both colour-chain asm blocks, the s128-copy
   lui/pool allocation and the tail all reproduce exactly. Lead: untested
   s128 spelling for the copies. scheduler-reorder floor family. */
// FUN_00499A30
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499a30);

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

/* measured: the VU0 chains reproduce byte-exact when written as split asm
   blocks (lqc2/vmove/mfc1/qmtc2/vmulx, then a separate sqc2 block per stack
   slot so mwcc interleaves the operand addiu like retail) and the loop's
   three 0.0f stores need a named `zero` variable (bare 0.0f stores compile
   to sw $zero; retail keeps the float in saved $f20). The residual is the
   allocator pools starting one register lower than retail: saved GPRs
   temp_17/temp_18 land in $s0/$s1 (retail $s1/$s2, var_16 then wraps to the
   top), the FP temp pool gives var_f5 $f3 / fabs $f5 (retail $f5/$f3), and
   with the zero placed late the FP saved pool becomes {fade $f22, acc $f21,
   step $f20, zero $f23} (retail {zero $f20, step $f21, acc $f22, fade
   $f23}); early zero assignment fixes $f20 but hoists the mtc1 above the
   guard (retail materializes it right before the loop). Declaration orders
   tried rotate var_16 between $s2/$s3 but never below the pointer pair
   (nd 100+ / 162 with var_16 first). allocator-pool floor family (same
   rotation as the func_004992a0/0049a1a0 twins). */
// FUN_00499E40
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499e40);

/* measured: byte-identical through the two VU0 colour-chain asm blocks; the
   residual is the same post-block TEMP pool offset as its twin
   func_004992a0 (retail pools from $v1, mwcc b210 from $v0 - nd 57, all rows
   same opcodes). Retested with memory-only asm clobbers (no register
   clobbers at all): the pool still starts at $v0, so the offset is not
   clobber-driven. allocator-pool floor family. */
// FUN_0049A1A0
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_0049a1a0);

/* measured: retail copies the 16-byte global D_00713CE0 with lui+addiu+lq+sq;
   mwcc b210 folds the LO16 address into the lq (lui+lq %lo) whenever the copy
   sits in a register-pressured function, shifting the whole tail by one word
   (nd 39, all rows the same opcodes). Tried: array+direct deref, array+&+cast,
   scalar u_long128+&, quadSrc/quad locals, dstq local, memcpy(...,0x10),
   u64-pair, #pragma optimization_level 3, declaration reorders - every one
   either folds identically (39) or gets worse (40/81/88). Wave-4 retest of the
   rule-3 typed-alias read (*(u_long128 *)(dst) = *(u_long128 *)&D_00713CE0):
   retail has no dsll32/dsra32 and the candidate has no narrowing cast, so no
   canonicalization pair existed to remove; the typed-alias form folds exactly
   the same way (nd 39, verified byte-identical up to the copy site). Register
   allocation only settles on retail's 5-saved-GPR pool when the three masks
   are spelled differently ((u16)arg0 >= 4 / arg0 & 0xFFFF / (u16)arg0 * 0x18)
   to stop mwcc CSE-ing the mask constant into a 6th saved register (nd 74/80
   otherwise). This is the load-sinking / address-fold family of floors; the
   sibling effPolygonWind func_004a5630 has the identical retail shape and its
   owner is blocked on the same fold. */
// FUN_0049A370
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_0049a370);

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
