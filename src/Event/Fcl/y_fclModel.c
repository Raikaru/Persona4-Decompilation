/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90(u8 *file, s32 line);
extern u8 D_0064A618[];
extern u8 D_0064A630[];
extern u8 D_0064A6B0[];
extern u8 D_0064A6C0[];

/* The two 12-byte vectors retail copies global->stack as ld/sd for the first
   eight bytes plus lwc1/swc1 for the last four. */
typedef struct
{
    s64 xy;
    f32 z;
} FclVec3;
extern u8 D_0064A6D0[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 func_00451fc0(s32 arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern void func_00349340(u8 *arg0);
extern void func_00349380(u8 *arg0);
extern void func_00349440(u8 *arg0);
extern void func_004787e0(u8 *arg0);
extern void func_00104a00(u8 *arg0);
extern s32 func_004782b0(u8 *arg0);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern void *func_004571a0(void);
extern void func_003c38b0(void *arg0, void *arg1);
extern void *func_004571b0(void);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern u8 *func_00104900(s8 arg0);
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 arg3);
extern void func_003e0c90(void *arg0, void *arg1, s32 arg2);
extern s32 func_00349c50(u8 *arg0);
extern u8 *func_00478140(s32, u16, s32);
extern void func_00479940(u8 *, s32, s32, s32, s32);
extern s32 func_00106330(s32);
extern s32 func_00348be0(u8 *);
extern s32 func_00348c10(u8 *);
extern void func_001102f0(void *, s32, s32, s32);
extern void func_002b2a60(void *, s32, s32, s32, s32);
extern void func_003489c0(u8 *, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00285b30(u8 *);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern s16 func_002b2cb0(s32, s32, s32, s32, s32);
extern void func_00479100(void *, u8 *);
extern void func_0047aa30(u8 *, void *);
extern void func_00452080(u8 *);
extern u8 D_00793E80[];
extern u8 D_005DCA70[];
extern u8 D_005DCA1C[];

// FUN_003493B0
void func_003493b0(s32 arg0)
{
    u8 *work;

    func_0044ea90(D_0064A618, 0x555);
    work = D_008873F4[0](1, 0x1A0, 0x40000);
    func_00451fc0(arg0, D_0064A630, 0xF, 0, 0, func_00349340, func_00349380, work);
}

/* measured: retail uses the FPU accumulator idiom (mula.s $f4,$f4 / madda.s
   $f12,$f12 / madda.s $f11,$f11 / madd.s $f1,$f3,$f3) to compute the rotation
   matrix sum-of-squares; m2c marks it M2C_ERROR and no C float spelling
   reproduces it byte-for-byte (recorded FPU FMA-fusion floor, same as
   btlPanelAnalyze func_00481360 / btlShuffleSeqShuffle4). Also uses gp-relative
   stores at |gp-0x4A60| (iGpffffb5a0) and |gp-0x7AE8| (iGpffff8518) and s128
   quadword copies. INCLUDE_ASM retained. */
// FUN_00349440
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349440);

// FUN_00349B90
void func_00349b90(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg1 + 0xC);
    if ((temp_4 != NULL) && (func_004782b0(temp_4) != 0)) {
        func_004577d0(func_00457120(), *(f32 *)(arg1 + 0x70));
        func_003c38b0(func_004571a0(), arg1 + 0x74);
        func_003c38b0(func_004571b0(), arg1 + 0x84);
        func_003e9cb0(*(s32 *)((u8 *)func_004571b0() + 4), arg1 + 0xA0, 0);
        *(s8 *)((u8 *)func_004571b0() + 2) = 3;
        func_004571b0();
    }
}

/* measured: state-machine switch on object[0] with nested switch on object[4]
   and a shared return-0 block. Retail frame is 0x50; b210 emits 0x30 because the
   case-1 stack locals (sp28/sp38/sp44/sp48/sp4C) are dead-store-eliminated (only
   sp28's address is taken; the sp44->sp4C byte copy and sp48/sp4C color stores
   vanish). Same lever-4 dead-store elimination as func_0034a4f0. Shared-return
   restructure (cases 0/1/2/4 -> break + trailing return 0) only moved 378->374;
   frame and byte-copy residuals remain. INCLUDE_ASM retained. */
// FUN_00349C50
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349c50);
// FUN_0034A480
void func_0034a480(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 0xC);
    if (temp_4 != NULL) {
        func_004787e0(temp_4);
    }
    temp_4_2 = *(u8 **)(temp_16 + 0x14);
    if (temp_4_2 != NULL) {
        func_00104a00(temp_4_2);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* measured: retail loads the {s64 @0x50, f32 @0x58} and {s64 @0x40, f32 @0x48}
   pairs as ld+lwc1 (load-both-then-store-both). A struct copy of {s64,f32}
   (16B padded) makes b210 copy both fields as 8-byte integer ld/sd (nd 4);
   field-by-field assignment copies the float correctly but interleaves
   load-store-load-store instead of load-load-store-store (nd 9); #pragma
   pack(4) splits the s64 into two lwc1 (nd 70). Mixed s64+f32 struct-copy
   grouping is a b210 floor. */
/* measured: reconstructed from scratch (this function had no note). Now nd 5,
   of which 2 words are window padding, so THREE real words remain -- all in
   the second 12-byte vector copy, where retail loads `ld` then `lwc1` and b210
   emits them the other way round.

   What got it here, in order of effect: (1) copy each 12-byte vector as an
   explicit s64 + f32 pair, NOT as a {s64; f32} struct assignment -- the struct
   pads to 16 and copies the tail as a second ld/sd (nd 22); (2) load both
   halves into temps before storing either, which is the load-both-then-
   store-both shape retail uses, and it fixes the FIRST copy (10 -> 5);
   (3) declaration order `handle, entry, mem` -- with `mem` first the whole
   function rotates $s0/$s1/$s2 against retail (26 vs 10).

   Measured and rejected: separate temps for the second copy (8, worse than
   reusing them); a {s64; f32} struct (22). The two callbacks need casts
   because func_00349c50 and func_0034a480 are declared returning s32/int.
   Body kept below so the last three words can be attacked without redoing
   any of the above. */
// FUN_0034A4F0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0034a4f0(s32 arg0, s32 arg1)
{
    u8 sp50[0xC];
    u8 sp40[0xC];
    s32 handle;
    u8 *entry;
    u8 *mem;
    s64 xy;
    f32 z;

    /* measured: the 12-byte vectors are copied as an explicit s64 + f32 pair so
       b210 emits retail's ld/sd plus lwc1/swc1; a {s64; f32} struct assignment
       pads to 16 and copies the tail as a second ld/sd. */
    xy = *(s64 *)&D_0064A6B0[0];
    z = *(f32 *)&D_0064A6B0[8];
    *(s64 *)&sp50[0] = xy;
    *(f32 *)&sp50[8] = z;
    xy = *(s64 *)&D_0064A6C0[0];
    z = *(f32 *)&D_0064A6C0[8];
    *(s64 *)&sp40[0] = xy;
    *(f32 *)&sp40[8] = z;
    func_0044ea90(D_0064A618, 0x7A9);
    mem = D_008873F4[0](1, 0x100, 0x40000);
    handle = func_00451fc0(arg0, D_0064A6D0, 0xF, 0, 0,
                           (void (*)(u8 *))func_00349c50,
                           (void (*)(u8 *))func_0034a480, mem);
    *(s8 *)(mem + 0) = 0;
    *(s16 *)(mem + 8) = 0;
    *(s8 *)(mem + 5) = 0;
    entry = func_00104900((s8)arg1);
    *(u8 **)(mem + 0x14) = entry;
    *(s32 *)(mem + 0x10) = *(s32 *)(entry + 8);
    *(s32 *)(mem + 0xE8) = 0xB3;
    func_003e0870(mem + 0x30, &sp40[0], 0, 180.0f);
    func_003e0c90(mem + 0x30, &sp50[0], 2);
    return handle;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_0034a4f0);
#endif

