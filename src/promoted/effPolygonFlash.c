/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */
/* Original translation unit effPolygonFlash.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef signed __int128 s128;

extern u32 func_004bd050(u32);
extern f32 func_004bd0b0(u32);
extern f32 func_0044b610(f32);
extern f32 func_0044b7b0(f32);
/* Anonymous gp-relative float slots (-0x7FBC / -0x7F30 of $28), same
   convention as effPolygonThunder.c's iGpffff8044. */
extern f32 iGpffff8044;
extern f32 fGpffff80d0;
/* Scratch color quads, addressed absolutely by retail (lui/addiu). */
extern f32 D_00713D10[4];
extern f32 D_00713D14[4];
extern f32 D_00713D18[4];

extern void func_004833f0();
extern void (*jtbl_008873EC[])(void *);
extern void (*D_008873ec[])(void *);
extern void func_003c2290(void *, s32);
extern void func_003c22f0(void *);
extern s32 func_00481300(s32);
extern void func_003c42b0(void *, void *);
extern void func_00483970(void *, void *);
extern char D_00713408[];
extern void *func_004844d0(void);
extern void *func_00484490(void *);
extern char D_00714028[];
extern char D_00713CE0[];
extern void func_0043f810(void *, void *, void *);
extern char D_00714014[];
extern char D_00714010[];
extern void *func_004a1660(s32, void *);

extern u8 *(*jtbl_008873E8[])(s32, s32);
extern void func_0044ea90(char *, s32);
extern void func_0046d730(char *, s32);
extern s32 func_0048abd0(u8 *, u8 *, s32, s32);
extern void func_004836b0(void *, void *, void *, void *);
extern void func_00483490(void *, u16);

/* 4-byte color, copied field-by-field by retail. */
typedef struct
{
    u8 c[4];
} Color4;
extern char D_00713FF0[];
extern char D_007133A0[];
extern char D_007133C0[];
extern u8 *func_00482f70(s32, s32, s32, char *, s32);
extern u8 *func_00483270(void *);
extern void func_0049cfc0(u8 *, u8 *);
extern void func_0049ddd0(u8 *, u8 *);
extern void func_0049ebd0(u8 *, u8 *);
extern void func_004a08a0(u8 *, u8 *);

// FUN_0049A900
void *func_0049a900(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x89);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x90);
    mem = jtbl_008873E8[0](id * 24 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x91);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 3, 5, D_007133A0, 0x48);
    return mem;
}




// FUN_0049A9E0
void func_0049a9e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

/* measured in the sibling floor family (see FUN_0049D360/0049E150/004A0C00,
   all byte-exact except the same residuals): retail reads/writes the four
   s128 slots (sp100/spF0/spE0/spD0) with plain lq+slt/mtc1/div while mwcc
   b210 inserts dsll32+dsra32 after every (s32) cast, and the saved-GPR/FP
   pools rotate (retail $16/$17/$18/$19/$20 + $f20-$f28, mwcc allocates
   from $s4 downward and $f28 downward). This draft matches the d360 shape
   (sp110 count + fade tests on the s128 slots + VU0 chains), so the
   canonicalization floor applies unchanged. s128-canonicalization /
   allocator-pool floor family. */
// FUN_0049AA30
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049aa30);
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// FUN_0049B2B0
void func_0049b2b0(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}
/* measured: with #pragma opt_loop_invariants on, the fill loop matches retail
 * exactly (including the preheader -1 hoist and the slt/nop/bnez tail); the
 * residual is 8 words in the func_0043f9c8 argument block: retail completes
 * the four-load chain (p18->0x10->0x18->0x5C->0x14) before computing the size
 * operand, mwcc b210 splits the chain around the size computation (chain1-3,
 * size, chain4) regardless of spelling (inline chain, explicit temps, locals,
 * opt_propagation off). Argument-evaluation-order/scheduling floor.
 * measured: #pragma schedule was probed and does NOT move the residual (best
 * stays 8 differing words): schedule off at function scope = 8 (no-op, it is
 * the default), schedule on at function scope = 49, schedule off scoped around
 * the memset call = 49, schedule on scoped around the call = 8 (no-op).
 * optimization_level 3 = 49, optimization_level 1 = 46, opt_lifetimes on/off =
 * 8 (no-op). The chain split is a register-allocation artifact (retail loads
 * chain3 into $v0 and chain4 into $a0; mwcc reuses $a0 for both, forcing the
 * chain4 load after the size arithmetic), not a scheduling toggle. */
/* measured: three separate defects, each worth a note.  m2c wrote the entry
   pointer as `s32 *` advancing by 0x1C, which walks 112 bytes where retail
   walks 28 - the loop still compiled and still looked right.  The -1 stored in
   the loop is loop-invariant and retail hoists it; b210 at -O2 rematerialises
   it inside instead, so opt_loop_invariants is what retail was built with here
   (nd 60 -> 17, and the hoisted addiu appears in the preheader exactly as
   retail has it).  The last 8 words were argument order: writing the texture
   handle as tex[5] instead of *(s32 *)(tex + 0x14) makes b210 finish the
   pointer chain before evaluating the size argument, which is what retail
   does; the cast-and-offset spelling lets the second load sink below the
   multiply and no declaration order fixes it.
   measured: without opt_loop_invariants the residual is nd 17, not 0. */
// FUN_0049B470
#pragma opt_loop_invariants on
void func_0049b470(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 7;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// FUN_0049B560
void *func_0049b560(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x1DE);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x1E5);
    mem = jtbl_008873E8[0](id * 28 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x1E6);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// FUN_0049B640
void func_0049b640(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

/* measured in the sibling floor family (see FUN_0049E150/004A0C00): only one
   s128 slot (spC0 - the -1/-2 test, fixable via the asm lq-read), but the
   saved-GPR pool rotates (retail temp_16/var_20 in $16/$20, mwcc allocates
   $s4-downward for the same declaration order - 5 orders tried across the
   family) and the fade denominator reloads differ. The e150-shaped layout
   structs, .word VU0 chains and adda/madd fusion otherwise reproduce
   byte-exact. allocator-pool floor family. */
// FUN_0049B690
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049b690);
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// FUN_0049BFF0
void func_0049bff0(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_0049C1B0
#pragma opt_loop_invariants on
void func_0049c1b0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 11;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
// FUN_0049C2A0
void *func_0049c2a0(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x349);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x350);
    mem = jtbl_008873E8[0](id * 44 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x351);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// FUN_0049C380
void func_0049c380(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

/* measured in the sibling floor family (see FUN_0049D360/0049E150/004A0C00):
   four s128 slots (sp100/spF0/spE0/spD0) read via (s32) casts - mwcc b210
   canonicalizes every one with dsll32+dsra32 (retail uses plain lq), the
   saved-GPR pool rotates ($s4-down vs retail $16-up) and the FP pool starts
   at $f28 with 9 slots vs retail $f20-$f29. 10 FP saved regs here. Same
   s128-canonicalization / allocator-pool floor family. */
// FUN_0049C3D0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049c3d0);
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// FUN_0049CD10
void func_0049cd10(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_0049CED0
#pragma opt_loop_invariants on
void func_0049ced0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049CFC0
#pragma opt_loop_invariants on
void func_0049cfc0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x4BE);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// FUN_0049D100
void *func_0049d100(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x4A4);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    if (*(u32 *)(arg0 + 0x70) == 0) {
        *(u32 *)(arg0 + 0x70) = 1;
    }
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x12));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049cfc0(mem, arg0);
    return mem;
}
// FUN_0049D230
void *func_0049d230(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x4A4);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    if (*(u32 *)(p17 + 0x70) == 0) {
        *(u32 *)(p17 + 0x70) = 1;
    }
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049cfc0(mem, p17);
    return mem;
}
// FUN_0049D310
void func_0049d310(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
/* measured: byte-exact for the whole body except 8 canonicalization pairs:
   retail reads/writes the five s128 slots (sp100/spF0/spE0/spD0/spC0, the
   count/fade/modulo values) with plain lq/slt/mtc1/div on the low word,
   mwcc b210 inserts dsll32+dsra32 after every lq of a (s32)-cast s128 local
   and after the mfc1 of a (s128)(s32)(float) store (16 words: spF0/spE0
   stores, loop test, spC0 test, fade tests x2, fade denom, spD0 test,
   madd-div). Tried (s32)/(u32)/(u64)/(s64) casts, intermediate s32/s64
   locals, direct (f32) casts (those are clean), asm sq stores with
   hardcoded $sp offsets (layout rotates), and .word emission for the
   $4-based VU block (works) - all nd >= 16 via the length-cascade. VU0
   chains, FP regs ($f20-f27 incl. var_f27/tf27 sharing), stack layout,
   adda/madd/msub fusion and the frame are otherwise byte-identical.
   s128-canonicalization floor family (cf. effPolygonThunder func_00495160). */
// FUN_0049D360
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049d360);
// FUN_0049DB20
void func_0049db20(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_0049DCE0
#pragma opt_loop_invariants on
void func_0049dce0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049DDD0
#pragma opt_loop_invariants on
void func_0049ddd0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x65A);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// FUN_0049DF10
void *func_0049df10(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x644);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x13));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049ddd0(mem, arg0);
    return mem;
}
// FUN_0049E030
void *func_0049e030(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x644);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049ddd0(mem, p17);
    return mem;
}
// FUN_0049E100
void func_0049e100(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
/* measured: byte-exact for the whole body except a saved-GPR allocation
   quirk and two FP residuals. mwcc b210 allocates the saved GPRs from a
   rotated pool ($s3,$s2,$s1,$s4,$s0...) so temp_16 lands in $s4 and var_20
   in $s0 while retail has temp_16 in $s0/$16 and var_20 in $s4/$20 (the
   swap cascades ~40 words; 5 declaration orders tried, the pool rotates
   with the order and temp_16 always gets $s4). Also: retail's fade
   else-branch reloads spF0 (lw 0xF0) for the denominator while mwcc keeps
   the test's value in a register (2-3 words), and the fade clamp's
   mul.s operand order is $f21,$f0 vs mwcc's $f0,$f21. Everything else is
   byte-identical: the 0x70-byte sqC0 layout struct (16-byte union slots at
   0xF0-0x120 with real retail holes), the VU0 chains (incl. .word emission
   for the $4/$5-based lqc2/sqc2 forms and the asm lq-read for the spC0
   test, which avoids the dsll32/dsra32 canonicalization), the adda/madd
   fusion, FP regs ($f20-f27) and the frame. Lead for a future wave: the
   D_00713D10 lui/addiu inside asm should use %%hi/%%lo(D_00713D10) symbol
   forms (reloc-masked) instead of raw constants. */
// FUN_0049E150
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049e150);
// FUN_0049E920
void func_0049e920(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_0049EAE0
#pragma opt_loop_invariants on
void func_0049eae0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 10;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049EBD0
#pragma opt_loop_invariants on
void func_0049ebd0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x803);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// FUN_0049ED10
void *func_0049ed10(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 40;
    func_0044ea90(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x7ED);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x12));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049ebd0(mem, arg0);
    return mem;
}
// FUN_0049EE30
void *func_0049ee30(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 40;
    func_0044ea90(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x7ED);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049ebd0(mem, p17);
    return mem;
}
// FUN_0049EF00
void func_0049ef00(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
/* measured in the sibling floor family (see FUN_0049D360/0049E150/004A0C00):
   four s128 slots (sp100/spF0/spE0/spD0) get the mwcc b210 dsll32+dsra32
   canonicalization on every (s32)/div/slt use, the saved-GPR pool rotates
   ($s4-down vs retail $16-up) and the FP pool starts at $f28 vs retail
   $f20-$f29 (10 FP saved regs). Same s128-canonicalization /
   allocator-pool floor family. */
// FUN_0049EF50
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049ef50);
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// FUN_0049F820
void func_0049f820(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_0049F9E0
#pragma opt_loop_invariants on
void func_0049f9e0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 11;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
// FUN_0049FAD0
void *func_0049fad0(u8 *arg0)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 44;
    func_0044ea90(D_00713FF0, 0x98E);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x98F);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 3, 5, D_007133A0, 0x48);
    return mem;
}
// FUN_0049FBA0
void func_0049fba0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
/* measured in the sibling floor family (see FUN_0049D360/0049E150/004A0C00):
   four s128 slots (sp100/spF0/spE0/spD0) trigger the mwcc b210
   dsll32+dsra32 canonicalization on every read (retail: plain lq), the
   saved-GPR pool rotates ($s4-down vs retail $16-up) and the FP pool starts
   at $f28 vs retail $f20-$f30 (11 FP saved regs - the widest of the family).
   Same s128-canonicalization / allocator-pool floor family. */
// FUN_0049FBF0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049fbf0);
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// FUN_004A05F0
void func_004a05f0(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

/* measured: shares func_0049b470's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see FUN_0049B470). */
/* measured: same shape as func_0049b470 above; see that note. */
// FUN_004A07B0
#pragma opt_loop_invariants on
void func_004a07b0(u8 *arg0)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 8;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_004A08A0
#pragma opt_loop_invariants on
void func_004a08a0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0xB08);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// FUN_004A09E0
void *func_004a09e0(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 32;
    func_0044ea90(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0xAF2);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x13));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_004a08a0(mem, arg0);
    return mem;
}
// FUN_004A0AF0
void *func_004a0af0(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 32;
    func_0044ea90(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0xAF2);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_004a08a0(mem, p17);
    return mem;
}




// FUN_004A0BB0
void func_004a0bb0(u8 *arg0) {
    func_004833f0(*(s32 *)(arg0 + 4));
    D_008873ec[0](*(void **)(arg0 + 8));
}

/* measured: byte-exact for the whole body except the mwcc saved-register
   pool rotation seen across this family (cf. FUN_0049E150): retail maps
   temp_16/var_20 to $16/$20 and FP $f20-$f30 (11 call-crossing locals),
   mwcc b210 rotates the saved GPR pool to ($s4,$s3,$s2,$s1,$s0,...) and
   starts the FP pool at $f28 with only 9 saved slots, scrambling ~70
   register words (5 GPR/FP declaration orders tried). Also retail reloads
   the fade denominator (lw 0x100) while mwcc keeps the test's value in a
   register (2-3 words). Everything else matches: the 0x90-byte sqD0
   layout struct (s128 d0 + union 16-byte slots v100-v130 + p140/p150 VU
   quads with the real retail holes), the .word VU0 chains ($3/$5/$4-based
   lqc2/sqc2 forms), the asm lq-read for the spD0 test (no dsll/dsra
   canonicalization), the adda/madd fusion, the sp160-quad madd updates,
   the frame 0x1A0 and the tail. Same floor family as FUN_0049D360 /
   FUN_0049E150. */
// FUN_004A0C00
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a0c00);
// FUN_004A14A0
void func_004a14a0(u8 *arg0)
{
    union
    {
        s32 w;
        u8 b[4];
    } sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 temp_3;
    u8 *temp_2;
    u8 *temp_17;
    u8 *temp_16;
    u32 temp_6;
    u32 temp_7;

    temp_2 = *(u8 **)(arg0 + 0x3C);
    temp_17 = *(u8 **)(arg0 + 0x40);
    temp_16 = *(u8 **)(temp_2 + 4);
    temp_6 = *(u32 *)(arg0 + 0x34);
    temp_7 = *(u32 *)(temp_17 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        s32 *pt;

        temp_3 = func_0048abd0(temp_17, temp_17 + 0x24, temp_6, temp_7);
        sp48 = *(s32 *)(arg0 + 0x30);
        pt = &sp48;
        __asm__ volatile(
            "lwc1 $f0, -0x7FBC($28)  \n"
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, $f0          \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sp44)
            : "$2", "$f0", "$vf2", "$vf10", "$vf11", "memory");
        sp4C.w = *(s32 *)&sp40;
        if (sp4C.b[3] != 0xFF)
        {
            u8 *dst = *(u8 **)(temp_16 + 0x14);
            *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
        }
        else
        {
            sp4C.b[3] = 0xFE;
            {
                u8 *dst = *(u8 **)(temp_16 + 0x14);
                *(Color4 *)(dst + 4) = *(Color4 *)&sp4C;
            }
            sp4C.b[3] = 0xFF;
        }
        func_004836b0(temp_16, arg0, arg0 + 0x10, arg0 + 0x20);
        if (*(u8 *)(temp_17 + 0x56) != 0)
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 | 1;
        }
        else
        {
            *(u16 *)temp_16 = *(u16 *)temp_16 & 0xFFFE;
        }
        {
            s32 temp_28 = *(u16 *)(temp_17 + 0x28);
            func_00483490(temp_16, temp_28);
        }
    }
}

// FUN_004A1660
/* measured: without opt_propagation off, mwcc folds the %lo of D_00713CE0
 * into the lq offset (lui+lq); retail materializes lui+addiu+lq. */
#pragma opt_propagation off
void *func_004a1660(s32 arg0, void *arg1)
{
    u8 *p18;
    u_long128 *quadSrc;
    u_long128 quad;
    s32 temp_16;
    s32 temp_17;

    if ((u16)arg0 >= 0xA) {
        func_0046d730(D_00713FF0, 0xCD2);
    }
    temp_16 = arg0 & 0xFFFF;
    temp_17 = *(s32 *)(D_00714028 + temp_16 * 0x1C);
    func_0044ea90(D_00713FF0, 0xCD6);
    p18 = jtbl_008873E8[0](temp_17 + 0x50, 0x40000);
    if (p18 == NULL) {
        func_0046d730(D_00713FF0, 0xCD7);
    }
    *(u32 *)(p18 + 0x40) = (u32)(p18 + 0x50);
    *(u32 *)(p18 + 0x34) = 0;
    *(u32 *)(p18 + 0x38) = (u32)temp_16;
    *(u32 *)(p18 + 0x30) = -1;
    quadSrc = (u_long128 *)D_00713CE0;
    quad = *quadSrc;
    *(u_long128 *)(p18 + 0x20) = quad;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(p18) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(p18) : "memory");
    func_0043f810(*(void **)(p18 + 0x40), arg1, (void *)temp_17);
    return p18;
}
#pragma opt_propagation on

// FUN_004A1780
void *func_004a1780(u8 *arg0)
{
    u8 *p16;
    u8 *p19;
    u8 *p18;
    u8 *p17;
    u32 idx;

    p18 = func_004844d0();
    if (p18 == NULL) {
        func_0046d730(D_00713FF0, 0xD08);
    }
    switch (*(u16 *)(arg0 + 0x1C)) {
    case 1:
        break;
    case 4:
        p18 = NULL;
        break;
    default:
        func_0046d730(D_00713FF0, 0xD11);
        break;
    }
    p19 = func_00484490(arg0);
    if (p19 == NULL) {
        func_0046d730(D_00713FF0, 0xD16);
    }
    p16 = (u8 *)(*(u16 *)(arg0 + 0xC) & 0xFFFF);
    p17 = func_004a1660((s32)p16, p19);
    idx = ((u32)p16 & 0xFFFF) * 28;
    *(u32 *)(p17 + 0x3C) = (u32)((void *(*)(void *, void *))(*(void **)(D_00714014 + idx)))(p19, p18);
    ((void (*)(void *))(*(void **)(D_00714010 + idx)))(p17);
    if (p17 == NULL) {
        func_0046d730(D_00713FF0, 0xD18);
    }
    return p17;
}
