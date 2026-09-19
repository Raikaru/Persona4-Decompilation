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
extern f32 fGpffff8044;
extern f32 fGpffff80d0;
/* Scratch color quads, addressed absolutely by retail (lui/addiu). */
extern f32 D_00713D10[4];
extern f32 D_00713D14[4];
extern f32 D_00713D18[4];
extern u32 D_00713F70[];
extern u32 D_00713FB0[];

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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): banked 488 words (u8+loop), fnalign 540/528/297, emitted 2112B/window 2176B (97.06%% PASS by 1B). Full 8+28 sweep: loop 488 ties with loop+dead/loop+strength/loop+unroll 488; peephole 491, loop+prop 503, dead/prop/strength/unroll 513, cse 520, schedule 516, no pair beats 488 -- installed loop stands (worth 27w/54ed, rotation collapses; u8 truthful for lbu). Residual is s128-canonicalization + standalone MMI pextlb/pextlh + interior VU vitof/vmul/vftoi/ppach + daddu zero-idiom; opclass daddu 0-vs-9, dsll32 0/0. Banked as guarded floor; production stays ASM. */
// FUN_0049AA30 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0049aa30(u8 *arg0)
{
    u8 *tmp40;
    u32 outer_ge;
    u32 outer_arg34;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 bVar;
    s32 iVar17;
    u32 *puVar15;
    u8 *puVar14;
    u32 c58;
    u32 c5c;
    s32 *pt58;
    s32 *pt5c;
    s128 au13;
    s128 au27;
    s128 au28;
    s128 au29;
    s128 au30;
    s128 au31;
    s128 au32;
    s128 au33;
    s32 iVar19;
    s32 iVar20;
    f32 f80d0;
    f32 scale;
    f32 fTmp;
    f32 fA;
    f32 fB;
    f32 fC;
    f32 fD;
    f32 fSin;
    f32 fCos;
    f32 f27save;
    s32 loop;
    s32 cur;
    s32 tmp22;
    f32 f1tmp;
    f32 f2tmp;
    u8 cVar1;

    tmp40 = *(u8 **)(arg0 + 0x40);
    outer_ge = *(u32 *)(tmp40 + 0x34);
    outer_arg34 = *(u32 *)(arg0 + 0x34);
    if ((outer_ge >= outer_arg34) || (outer_ge == 0)) {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(tmp40 + 0x38);
        iVar5 = *(s32 *)(tmp40 + 0x4C);
        if (iVar5 != 0) {
            if ((*(u8 *)(tmp40 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0)) {
                bVar = 0;
                iVar17 = *(s32 *)(tmp40 + 0x50);
            } else {
                bVar = 1;
                iVar17 = iVar4;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u8 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(tmp40 + 0x58) & 0xFFFFFF;
            pt58 = (s32 *)&c58;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt58), "f"(scale), "r"(&au13)
                : "$2", "$vf2", "$vf10", "memory");
            c5c = *(u32 *)(tmp40 + 0x5C) & 0xFFFFFF;
            pt5c = (s32 *)&c5c;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt5c), "f"(scale), "r"(&au27)
                : "$2", "$vf2", "$vf10", "memory");
            iVar19 = (s32)(*(f32 *)(tmp40 + 0x44) * (f32)iVar5);
            iVar20 = (s32)(*(f32 *)(tmp40 + 0x48) * (f32)iVar5);
            f27save = *(f32 *)(tmp40 + 0x7C);
            cVar1 = *(u8 *)(tmp40 + 0x54);
            f80d0 = fGpffff80d0;
            loop = 0;
            while (loop < iVar4) {
                cur = *piVar16;
                if (cur != -2) {
                    if (cur == -1) {
                        if (iVar17 != 0) {
                            fTmp = func_004bd0b0(0);
                            piVar16[2] = (s32)(f80d0 * fTmp);
                            fC = *(f32 *)(tmp40 + 0x78);
                            fTmp = func_004bd0b0(0);
                            piVar16[1] = (s32)(*(f32 *)(tmp40 + 0x74) * (0.0f + (1.0f - fC) + fC * fTmp));
                            tmp22 = func_004bd050(0);
                            if ((tmp22 & 1) != 0) {
                                piVar16[1] = (s32)((f32)piVar16[1] * -1.0f);
                            }
                            fC = *(f32 *)(tmp40 + 0x70);
                            fTmp = func_004bd0b0(0);
                            piVar16[3] = (s32)(*(f32 *)(tmp40 + 0x6C) * (0.0f + (1.0f - fC) + fC * fTmp));
                            fC = *(f32 *)(tmp40 + 0x68);
                            fTmp = func_004bd0b0(0);
                            f1tmp = (0.0f + (1.0f - fC) + fC * fTmp);
                            piVar16[4] = (s32)(*(f32 *)(tmp40 + 0x60) * f1tmp);
                            piVar16[5] = (s32)(*(f32 *)(tmp40 + 0x64) * f1tmp);
                            if (bVar != 0) {
                                tmp22 = func_004bd050(0);
                                *piVar16 = (s32)(tmp22 % (u32)iVar5);
                            } else {
                                *piVar16 = 0;
                            }
                            iVar17 += -1;
                        }
                    } else if (cur < iVar5) {
                        f1tmp = (f32)cur;
                        f2tmp = *(f32 *)(&piVar16[1]);
                        if (0.0f < f2tmp) {
                            f2tmp = 0.0f + f2tmp + 0.5f * (f27save * f1tmp);
                        } else {
                            f2tmp = 0.0f + f2tmp - 0.5f * (f27save * f1tmp);
                        }
                        fD = f1tmp * f2tmp + (f32)piVar16[2];
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "vmove.xyzw $vf10, $vf11  \n"
                            "lw $2, 16(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "lw $2, 20(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "sqc2 $vf11, 0(%4)        \n"
                            :
                            : "r"(D_00713CE0), "r"(piVar16), "r"(&au31), "r"(&au29), "r"(&au28)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        fSin = func_0044b610(fD);
                        fCos = func_0044b7b0(fD);
                        {
                            f32 _s = fSin;
                            f32 _c = fCos;
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "vmove.xyzw $vf12, $vf10  \n"
                                "qmfc2 $2, $vf10          \n"
                                "mtc1 $2, $f1             \n"
                                "qmfc2 $2, $vf10          \n"
                                "pexew $2, $2             \n"
                                "mtc1 $2, $f0             \n"
                                "nop                      \n"
                                "mfc1 $2, $f0             \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vaddx.x $vf10x, $vf0x, $vf2x \n"
                                "mfc1 $2, $f1             \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vaddx.z $vf10z, $vf0z, $vf2x \n"
                                "vmove.xyzw $vf11, $vf10  \n"
                                "lqc2 $vf10, 0(%1)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "sqc2 $vf10, 0(%1)        \n"
                                "vmove.xyzw $vf10, $vf12  \n"
                                "lqc2 $vf11, 0(%2)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "vmove.xyzw $vf12, $vf10  \n"
                                "lqc2 $vf10, 0(%1)        \n"
                                "vmove.xyzw $vf11, $vf10  \n"
                                "sqc2 $vf10, 0(%3)        \n"
                                "lwc1 $f0, 0(%3)          \n"
                                "swc1 $f0, 24(%4)         \n"
                                "lwc1 $f0, 4(%3)          \n"
                                "swc1 $f0, 28(%4)         \n"
                                "lwc1 $f0, 8(%3)          \n"
                                "swc1 $f0, 32(%4)         \n"
                                "vsub.xyz $vf11xyz, $vf0xyz, $vf11xyz \n"
                                "sqc2 $vf11, 0(%3)        \n"
                                "lwc1 $f0, 0(%3)          \n"
                                "swc1 $f0, 48(%4)         \n"
                                "lwc1 $f0, 4(%3)          \n"
                                "swc1 $f0, 52(%4)         \n"
                                "lwc1 $f0, 8(%3)          \n"
                                "swc1 $f0, 56(%4)         \n"
                                "lqc2 $vf10, 0(%1)        \n"
                                "vmove.xyzw $vf11, $vf10  \n"
                                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                                "sqc2 $vf10, 0(%3)        \n"
                                "lwc1 $f0, 0(%3)          \n"
                                "swc1 $f0, 0(%4)          \n"
                                "lwc1 $f0, 4(%3)          \n"
                                "swc1 $f0, 4(%4)          \n"
                                "lwc1 $f0, 8(%3)          \n"
                                "swc1 $f0, 8(%4)          \n"
                                "vadd.xyzw $vf11, $vf11, $vf12 \n"
                                "sqc2 $vf11, 0(%3)        \n"
                                "lwc1 $f0, 0(%3)          \n"
                                "swc1 $f0, 12(%4)         \n"
                                "lwc1 $f0, 4(%3)          \n"
                                "swc1 $f0, 16(%4)         \n"
                                "lwc1 $f0, 8(%3)          \n"
                                "swc1 $f0, 20(%4)         \n"
                                :
                                : "r"(&_s), "r"(&au29), "r"(&au31), "r"(D_00713D10), "r"(puVar15)
                                : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        }
                        if (cur < iVar19) {
                            fD = (f32)cur / (f32)iVar19;
                        } else {
                            fD = 1.0f;
                            if (iVar20 < cur) {
                                fD = (f32)(iVar5 - cur) / (f32)(iVar5 - iVar20);
                            }
                        }
                        {
                            u32 col0;
                            u32 col1;
                            f32 fade = fD;
                            __asm__ volatile(
                                "lqc2 $vf11, 0(%0)        \n"
                                "mfc1 $2, %1              \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "lqc2 $vf10, 0(%2)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "mfc1 $2, $f21            \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vftoi0.xyzw $vf10, $vf10 \n"
                                "qmfc2 $2, $vf10          \n"
                                "ppach $2, $0, $2         \n"
                                "ppacb $2, $0, $2         \n"
                                "sw $2, 0(%3)             \n"
                                :
                                : "r"(D_00713CE0), "f"(fade), "r"(&au27), "r"(&au32)
                                : "$2", "$vf2", "$vf10", "$vf11", "$f21", "memory");
                            col0 = *(u32 *)&au32;
                            *(u32 *)puVar14 = col0;
                            puVar14[4] = puVar14[0];
                            puVar14[5] = puVar14[1];
                            puVar14[6] = puVar14[2];
                            puVar14[7] = puVar14[3];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                                "mfc1 $2, $f21            \n"
                                "nop                      \n"
                                "qmtc2 $2, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vftoi0.xyzw $vf10, $vf10 \n"
                                "qmfc2 $2, $vf10          \n"
                                "ppach $2, $0, $2         \n"
                                "ppacb $2, $0, $2         \n"
                                "sw $2, 0(%1)             \n"
                                :
                                : "r"(&au13), "r"(&au30)
                                : "$2", "$vf2", "$vf10", "$vf11", "$f21", "memory");
                            col1 = *(u32 *)&au30;
                            if ((loop & 1) != 0) {
                                *(u32 *)(puVar14 + 12) = col1 | 0xFF000000;
                                fA = 128.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(puVar14 + 8) = _s;
                                    *(s32 *)(puVar14 + 16) = _s;
                                }
                            } else {
                                *(u32 *)(puVar14 + 12) = col1 | 0x40000000;
                                fA = 255.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(puVar14 + 8) = _s;
                                    *(s32 *)(puVar14 + 16) = _s;
                                }
                            }
                        }
                        *piVar16 = cur + 1;
                    } else {
                        s32 k;
                        for (k = 0; k < 5; k++) {
                            ((f32 *)puVar15)[k * 3 + 0] = 0.0f;
                            ((f32 *)puVar15)[k * 3 + 1] = 0.0f;
                            ((f32 *)puVar15)[k * 3 + 2] = 0.0f;
                            ((u32 *)puVar14)[k] = 0;
                        }
                        if (cVar1 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        *piVar16 = cur;
                    }
                }
                piVar16 += 6;
                puVar15 += 15;
                puVar14 += 20;
                loop += 1;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(puVar3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)puVar3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}

#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049aa30);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): measure_guarded 507 words (loop+prop), fnalign 597/585/316 (retail/object/edits instrs), emitted 2340B (585*4)/retail 2388B (597*4)/window 2400B (97.5%). Pragma sweep: bare 568, loop 519 WINNER (-49), loop+prop 507 WINNER (-12), prop 560, O3 558, O4 560, dead/strength/unroll tie 568, schedule on 573, peephole 584, subs/level1 628, level0 651; pairs confirm loop+prop stands. Probe chain: v1 bare 568 -> loop 519 (-49) -> loop+prop 507 (-12). Micro-priced casts: (s32)(f*(f32)n) 8 instrs vs (u32) 21 (saves 13 per fade, cf. func_0049ef50 8-vs-21); color packing via single VU bridge per loop (lui 0x437F) not per-channel casts. Subscript P[i] stands (both sll-before-lw; subptr tie 507). Colour swaps tie (vertex/color, cnt38/cnt4C, spEC/spE8, pi/pif, tmp17/tmp34 all 507). wscan OBJ 2 dsll32/dsra32 vs RETAIL 0 (s128 spC0 wall) + daddu 0-vs-11. Banked as guarded floor; production stays ASM. */
// FUN_0049B690 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
#pragma opt_propagation off
void func_0049b690(u8 *arg0)
{
    u8 *tmp17;
    u32 tmp34;
    u32 arg34;
    s32 *pi;
    f32 *pif;
    u16 *pu3;
    s32 cnt38;
    s32 cnt4C;
    s32 spEC;
    s32 spE8;
    s32 spD0;
    s32 sp100;
    s32 spF0;
    s32 bVar;
    s32 var22;
    f32 *vertex;
    u32 *color;
    u32 sp1AC;
    u32 sp1A8;
    s128 colA;
    s128 colB;
    s128 q130;
    s128 q140;
    s128 q150;
    s128 q160;
    s128 q170;
    u32 packA;
    u32 packB;
    s128 spC0;
    f32 scale;
    f32 f80d0;
    f32 f84;
    u8 cVar1;
    s32 loop;
    s32 cur;
    s32 tmp;
    f32 ftmp;
    f32 fC;
    f32 f1t;
    f32 fD;

    tmp17 = *(u8 **)(arg0 + 0x40);
    tmp34 = *(u32 *)(tmp17 + 0x34);
    arg34 = *(u32 *)(arg0 + 0x34);
    if ((tmp34 >= arg34) || (tmp34 == 0)) {
        pi = *(s32 **)(arg0 + 0x3C);
        pif = (f32 *)pi;
        pu3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        cnt38 = *(s32 *)(tmp17 + 0x38);
        cnt4C = *(s32 *)(tmp17 + 0x4C);
        if (cnt4C != 0) {
            if (*(u8 *)(tmp17 + 0x88) != 0) {
                spEC = cnt4C;
                spE8 = 0;
                spD0 = -1;
                sp100 = (s32)((1.0f - *(f32 *)(tmp17 + 0x48)) * (f32)cnt4C);
                spF0 = (s32)((1.0f - *(f32 *)(tmp17 + 0x44)) * (f32)cnt4C);
            } else {
                spEC = 0;
                spE8 = cnt4C;
                spD0 = 1;
                sp100 = (s32)(*(f32 *)(tmp17 + 0x44) * (f32)cnt4C);
                spF0 = (s32)(*(f32 *)(tmp17 + 0x48) * (f32)cnt4C);
            }
            if ((*(u8 *)(tmp17 + 0x55) == 0) || (arg34 != 0)) {
                bVar = 0;
                var22 = *(s32 *)(tmp17 + 0x50);
            } else {
                bVar = 1;
                var22 = cnt38;
            }
            func_003c2290(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18), 10);
            vertex = (f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x5C) + 0x14);
            color = (u32 *)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x30);
            sp1AC = *(u32 *)(tmp17 + 0x58) & 0xFFFFFF;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp1AC), "f"(scale), "r"(&colA)
                : "$2", "$vf2", "$vf10", "memory");
            sp1A8 = *(u32 *)(tmp17 + 0x5C) & 0xFFFFFF;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp1A8), "f"(scale), "r"(&colB)
                : "$2", "$vf2", "$vf10", "memory");
            f84 = *(f32 *)(tmp17 + 0x84);
            cVar1 = *(u8 *)(tmp17 + 0x54);
            spC0 = (s128)(s32)cVar1;
            ((s32 *)&q160)[1] = 0;
            ((s32 *)&q160)[3] = 0;
            f80d0 = fGpffff80d0;
            loop = 0;
            while (loop < cnt38) {
                cur = pi[0];
                if (cur != -2) {
                    if (cur == -1) {
                        if (var22 != 0) {
                            ftmp = func_004bd0b0(0);
                            pif[2] = f80d0 * ftmp;
                            fC = *(f32 *)(tmp17 + 0x70);
                            ftmp = func_004bd0b0(0);
                            pif[3] = *(f32 *)(tmp17 + 0x6C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            ftmp = func_004bd0b0(0);
                            pif[4] = *(f32 *)(tmp17 + 0x6C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x78);
                            ftmp = func_004bd0b0(0);
                            pif[5] = *(f32 *)(tmp17 + 0x74) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x80);
                            ftmp = func_004bd0b0(0);
                            pif[1] = *(f32 *)(tmp17 + 0x7C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x68);
                            ftmp = func_004bd0b0(0);
                            pif[6] = *(f32 *)(tmp17 + 0x60) * (0.0f + (1.0f - fC) + fC * ftmp);
                            if (bVar != 0) {
                                tmp = func_004bd050(0);
                                pi[0] = (s32)(tmp % (u32)cnt4C);
                            } else {
                                pi[0] = spEC;
                            }
                            var22 -= 1;
                        }
                    } else if (cur == spE8) {
                        s32 k;
                        k = 0;
                        while (k < 13) {
                            vertex[k * 3 + 0] = 0.0f;
                            vertex[k * 3 + 1] = 0.0f;
                            vertex[k * 3 + 2] = 0.0f;
                            color[k] = 0;
                            k++;
                        }
                        if ((s32)spC0 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        pi[0] = cur;
                    } else {
                        f32 curf;
                        f32 pi1;
                        f32 f3;
                        f32 f1m;
                        f32 f0m;
                        f32 f26v;
                        f32 s;
                        f32 c;
                        f32 fade;
                        s32 k;

                        curf = (f32)cur;
                        pi1 = pif[1];
                        f3 = curf;
                        if (f84 < 0.0f) {
                            f32 comp;
                            comp = 0.5f * (-(pi1) / (0.5f * f84));
                            if (curf > comp) {
                                f3 = comp;
                            }
                        }
                        f1m = f84 * f3;
                        f0m = 0.0f + pi1 + 0.5f * f1m;
                        f26v = f3 * f0m + pif[5];
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "lw $2, 24(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            :
                            : "r"(D_00713CE0), "r"(pi), "r"(&q150)
                            : "$2", "$vf2", "$vf10", "memory");
                        s = func_0044b610(pif[2]);
                        c = func_0044b7b0(pif[2]);
                        ((f32 *)&q160)[0] = s;
                        ((f32 *)&q160)[2] = c;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vmove.xyzw $vf11, $vf12  \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "lw $2, 16(%1)            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            "vmove.xyzw $vf10, $vf12  \n"
                            "mfc1 $2, %4              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%5)        \n"
                            "vmove.xyzw $vf2, $vf10   \n"
                            "vmove.xyzw $vf10, $vf12  \n"
                            "vmove.xyzw $vf12, $vf2   \n"
                            "qmfc2 $2, $vf10          \n"
                            "mtc1 $2, $f1             \n"
                            "qmfc2 $2, $vf10          \n"
                            "pexew $2, $2             \n"
                            "mtc1 $2, $f0             \n"
                            "nop                      \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.x $vf10, $vf0, $vf2x \n"
                            "neg.s $f0, $f1           \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.z $vf10, $vf0, $vf2x \n"
                            "lqc2 $vf11, 0(%6)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%6)        \n"
                            "sqc2 $vf12, 0(%7)        \n"
                            :
                            : "r"(&q160), "r"(pi), "r"(&q130), "r"(&q140), "f"(f26v), "r"(&q170), "r"(&q150), "r"(D_00713D10)
                            : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        vertex[0] = ((f32 *)D_00713D10)[0];
                        vertex[1] = ((f32 *)D_00713D10)[1];
                        vertex[2] = ((f32 *)D_00713D10)[2];
                        for (k = 0; k < 6; k++) {
                            u32 fb;
                            u32 f70w;
                            fb = D_00713FB0[k];
                            f70w = D_00713F70[k];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "qmtc2 %1, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                                "lqc2 $vf11, 0(%2)        \n"
                                "qmtc2 %3, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                                "sqc2 $vf10, 0(%4)        \n"
                                :
                                : "r"(&q130), "r"(fb), "r"(&q150), "r"(f70w), "r"(D_00713D10)
                                : "$vf2", "$vf10", "$vf11", "$vf12", "memory");
                            vertex[k * 3 + 3] = ((f32 *)D_00713D10)[0];
                            vertex[k * 3 + 4] = ((f32 *)D_00713D10)[1];
                            vertex[k * 3 + 5] = ((f32 *)D_00713D10)[2];
                        }
                        for (k = 6; k < 12; k++) {
                            u32 fb;
                            u32 f70w;
                            fb = D_00713FB0[k];
                            f70w = D_00713F70[k];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "qmtc2 %1, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                                "lqc2 $vf11, 0(%2)        \n"
                                "qmtc2 %3, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                                "sqc2 $vf10, 0(%4)        \n"
                                :
                                : "r"(&q140), "r"(fb), "r"(&q150), "r"(f70w), "r"(D_00713D10)
                                : "$vf2", "$vf10", "$vf11", "$vf12", "memory");
                            vertex[k * 3 + 3] = ((f32 *)D_00713D10)[0];
                            vertex[k * 3 + 4] = ((f32 *)D_00713D10)[1];
                            vertex[k * 3 + 5] = ((f32 *)D_00713D10)[2];
                        }
                        if (cur < sp100) {
                            fade = (f32)cur / (f32)sp100;
                        } else {
                            fade = 1.0f;
                            if (spF0 < cur) {
                                fade = (f32)(cnt4C - cur) / (f32)(cnt4C - spF0);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%4)             \n"
                            :
                            : "r"(D_00713CE0), "f"(fade), "r"(&colB), "f"(255.0f), "r"(&packA)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        {
                            s32 kk;
                            u32 pv = *(u32 *)&packA;
                            for (kk = 1; kk < 13; kk++) {
                                color[kk] = pv;
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%2)             \n"
                            :
                            : "r"(&colA), "f"(255.0f), "r"(&packB)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        {
                            f32 fA;
                            u32 cb = *(u32 *)&packB;
                            fA = 255.0f * fade;
                            if (fA >= 2147483600.0f) {
                                fA = fA - 2147483600.0f;
                            }
                            {
                                s32 _i = (s32)fA;
                                s32 _s = _i << 24;
                                color[0] = cb | (u32)_s;
                            }
                        }
                        pi[0] = cur + spD0;
                    }
                }
                pi += 7;
                pif = (f32 *)pi;
                vertex += 39;
                color += 13;
                loop++;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(pu3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)pu3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}


#pragma opt_propagation on
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049b690);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): measure_guarded 523 words (loop+prop), fnalign 592/592/419 (retail/object/edits instrs), emitted 2368B/window 2368B (100% exact size). Pragma sweep: loop 553, loop+prop 523 WINNER (-30), loop+dead 542 (-11), O4 553 tie, prop 563, sched 563, dead 577, strength/unroll 584, peephole 588, subs 608, O0 626; pairs confirm loop+prop stands. Probe chain: v1 scalar+bridges 585 -> v2 u32 colors+int quad zeros 584 (-1) -> installed loop 553 (-31) -> loop+prop 523 (-30). Micro-priced casts: (s32)(f*(f32)n) vs (u32) 584 vs 598 (+14 for 2 fades, cf. func_0049ef50 8-vs-21); color packing via single VU bridge per loop (lui 0x437F) not per-channel casts. wscan OBJ 5 dsll32/dsra32 vs RETAIL 0 (s128 width wall) + daddu 0-vs-13 (zero-idiom); opclass 15: nop -10, addiu +8, sw +7, dsra32 +5, lui -5, dsll32 +4, lw -3. Residual is saved-GPR/FP pool rotation + COP2 slot addresses + standalone MMI pextlb/pextlh (romwright m2c-shaped fails _pextlb intrinsic) + s128-canonicalization + daddu zero-idiom + interior VU vitof/vmul/vftoi/ppach. Banked as guarded floor; production stays ASM. See /var/tmp/cold49c3d0/ (m2c.c 309L, rw_raw.c 323L, rw_types.txt, v1/v2/v3u, cand523.c). */
// FUN_0049C3D0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
#pragma opt_propagation off
void func_0049c3d0(u8 *arg0)
{
    u8 *tmp17;
    u32 tmp34;
    u32 arg34;
    s32 *pi;
    f32 *pif;
    u16 *pu3;
    s32 cnt38;
    s32 cnt4C;
    s32 bVar;
    s32 var22;
    f32 *vertex;
    u32 *color;
    u32 sp18C;
    u32 sp188;
    s128 colA;
    s128 colB;
    s128 sp120;
    s128 sp130;
    s128 q140;
    s128 sp150;
    u32 packA;
    u32 packB;
    s128 spD0;
    s128 spF0;
    s128 spE0;
    s128 sp100;
    f32 scale;
    f32 f80d0;
    f32 f8C;
    f32 f98;
    u8 cVar1;
    s32 loop;
    s32 cur;
    s32 tmp;
    f32 ftmp;
    f32 fC;
    f32 f1t;
    f32 fD;

    tmp17 = *(u8 **)(arg0 + 0x40);
    tmp34 = *(u32 *)(tmp17 + 0x34);
    arg34 = *(u32 *)(arg0 + 0x34);
    if ((tmp34 >= arg34) || (tmp34 == 0)) {
        pi = *(s32 **)(arg0 + 0x3C);
        pif = (f32 *)pi;
        pu3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        cnt38 = *(s32 *)(tmp17 + 0x38);
        *(s32 *)&sp100 = cnt38;
        cnt4C = *(s32 *)(tmp17 + 0x4C);
        if (cnt4C != 0) {
            if ((*(u8 *)(tmp17 + 0x55) == 0) || (arg34 != 0)) {
                bVar = 0;
                var22 = *(s32 *)(tmp17 + 0x50);
            } else {
                bVar = 1;
                var22 = cnt38;
            }
            func_003c2290(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18), 10);
            vertex = (f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x5C) + 0x14);
            color = (u32 *)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x30);
            ((s32 *)&sp150)[1] = 0;
            ((s32 *)&sp150)[3] = 0;
            sp18C = *(u32 *)(tmp17 + 0x58) & 0xFFFFFF;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp18C), "f"(scale), "r"(&colA)
                : "$2", "$vf2", "$vf10", "memory");
            sp188 = *(u32 *)(tmp17 + 0x5C) & 0xFFFFFF;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp188), "f"(scale), "r"(&colB)
                : "$2", "$vf2", "$vf10", "memory");
            *(s32 *)&spF0 = (s32)(*(f32 *)(tmp17 + 0x44) * (f32)cnt4C);
            *(s32 *)&spE0 = (s32)(*(f32 *)(tmp17 + 0x48) * (f32)cnt4C);
            f8C = *(f32 *)(tmp17 + 0x8C);
            f98 = *(f32 *)(tmp17 + 0x98);
            cVar1 = *(u8 *)(tmp17 + 0x54);
            spD0 = (s128)(s32)cVar1;
            ((s32 *)&sp120)[1] = 0;
            ((s32 *)&sp120)[3] = 0;
            ((s32 *)&sp130)[1] = 0;
            ((s32 *)&sp130)[3] = 0;
            f80d0 = fGpffff80d0;
            loop = 0;
            while (loop < (s32)sp100) {
                cur = pi[0];
                if (cur != -2) {
                    if (cur == -1) {
                        if (var22 != 0) {
                            ftmp = func_004bd0b0(0);
                            pif[3] = f80d0 * ftmp;
                            fC = *(f32 *)(tmp17 + 0x70);
                            ftmp = func_004bd0b0(0);
                            pif[4] = *(f32 *)(tmp17 + 0x6C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            ftmp = func_004bd0b0(0);
                            pif[5] = *(f32 *)(tmp17 + 0x6C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x78);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x74) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[6] = f1t;
                            fC = *(f32 *)(tmp17 + 0x80);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x7C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[7] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x94);
                            ftmp = func_004bd0b0(0);
                            pif[1] = *(f32 *)(tmp17 + 0x90) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x88);
                            ftmp = func_004bd0b0(0);
                            pif[2] = *(f32 *)(tmp17 + 0x84) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x68);
                            ftmp = func_004bd0b0(0);
                            pif[8] = *(f32 *)(tmp17 + 0x60) * (0.0f + (1.0f - fC) + fC * ftmp);
                            if (bVar != 0) {
                                tmp = func_004bd050(0);
                                pi[0] = (s32)(tmp % (u32)cnt4C);
                            } else {
                                pi[0] = 0;
                            }
                            var22 -= 1;
                        }
                    } else if (cur < cnt4C) {
                        f32 curf;
                        f32 pi1;
                        f32 pi2;
                        f32 pi3;
                        f32 f30;
                        f32 f26v;
                        f32 f29v;
                        f32 f20v;
                        f32 s;
                        f32 c;
                        f32 fade;
                        s32 k;

                        curf = (f32)cur;
                        pi2 = pif[2];
                        pi3 = pif[3];
                        f30 = 0.5f * (f8C * curf);
                        f26v = f98 * curf;
                        pi1 = pif[1];
                        f29v = pif[6] + pif[7] * curf;
                        f20v = curf * (pi1 + f30) - curf * f26v * 0.5f;
                        ((f32 *)&sp120)[1] = pif[4];
                        ((f32 *)&sp130)[1] = pif[5];
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "lw $2, 32(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            :
                            : "r"(D_00713CE0), "r"(pi), "r"(&q140)
                            : "$2", "$vf2", "$vf10", "memory");
                        s = func_0044b610(curf * (pi2 + f30) + pi3);
                        c = func_0044b7b0(curf * (pi2 + f30) + pi3);
                        ((f32 *)&sp150)[0] = s;
                        ((f32 *)&sp150)[2] = c;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "mfc1 $2, %2              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.y $vf10, $vf0, $vf2x \n"
                            "vmove.xyzw $vf2, $vf10   \n"
                            "vmove.xyzw $vf10, $vf12  \n"
                            "vmove.xyzw $vf12, $vf2   \n"
                            "qmfc2 $2, $vf10          \n"
                            "mtc1 $2, $f1             \n"
                            "qmfc2 $2, $vf10          \n"
                            "pexew $2, $2             \n"
                            "mtc1 $2, $f0             \n"
                            "nop                      \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.x $vf10, $vf0, $vf2x \n"
                            "mfc1 $2, $f1             \n"
                            "nop                      \n"
                            "neg.s $f0, $f1           \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.z $vf10, $vf0, $vf2x \n"
                            "lqc2 $vf11, 0(%3)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "sqc2 $vf12, 0(%4)        \n"
                            :
                            : "r"(&sp150), "f"(f29v), "f"(f20v), "r"(&q140), "r"(D_00713D10)
                            : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        vertex[0] = ((f32 *)D_00713D10)[0];
                        vertex[1] = ((f32 *)D_00713D10)[1];
                        vertex[2] = ((f32 *)D_00713D10)[2];
                        for (k = 0; k < 6; k++) {
                            u32 fb;
                            u32 f70w;
                            fb = D_00713FB0[k];
                            f70w = D_00713F70[k];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "qmtc2 %1, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                                "lqc2 $vf11, 0(%2)        \n"
                                "qmtc2 %3, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                                "sqc2 $vf10, 0(%4)        \n"
                                :
                                : "r"(&sp120), "r"(fb), "r"(&q140), "r"(f70w), "r"(D_00713D10)
                                : "$vf2", "$vf10", "$vf11", "$vf12", "memory");
                            vertex[k * 3 + 3] = ((f32 *)D_00713D10)[0];
                            vertex[k * 3 + 4] = ((f32 *)D_00713D10)[1];
                            vertex[k * 3 + 5] = ((f32 *)D_00713D10)[2];
                        }
                        for (k = 6; k < 12; k++) {
                            u32 fb;
                            u32 f70w;
                            fb = D_00713FB0[k];
                            f70w = D_00713F70[k];
                            __asm__ volatile(
                                "lqc2 $vf10, 0(%0)        \n"
                                "qmtc2 %1, $vf2           \n"
                                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                                "lqc2 $vf11, 0(%2)        \n"
                                "qmtc2 %3, $vf2           \n"
                                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                                "sqc2 $vf10, 0(%4)        \n"
                                :
                                : "r"(&sp130), "r"(fb), "r"(&q140), "r"(f70w), "r"(D_00713D10)
                                : "$vf2", "$vf10", "$vf11", "$vf12", "memory");
                            vertex[k * 3 + 3] = ((f32 *)D_00713D10)[0];
                            vertex[k * 3 + 4] = ((f32 *)D_00713D10)[1];
                            vertex[k * 3 + 5] = ((f32 *)D_00713D10)[2];
                        }
                        if (cur < (s32)spF0) {
                            fade = (f32)cur / (f32)(s32)spF0;
                        } else {
                            fade = 1.0f;
                            if ((s32)spE0 < cur) {
                                fade = (f32)(cnt4C - cur) / (f32)(cnt4C - (s32)spE0);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%4)             \n"
                            :
                            : "r"(D_00713CE0), "f"(fade), "r"(&colB), "f"(255.0f), "r"(&packA)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        {
                            s32 kk;
                            u32 pv = *(u32 *)&packA;
                            for (kk = 1; kk < 13; kk++) {
                                color[kk] = pv;
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%2)             \n"
                            :
                            : "r"(&colA), "f"(255.0f), "r"(&packB)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        {
                            f32 fA;
                            u32 cb = *(u32 *)&packB;
                            fA = 255.0f * fade;
                            if (fA >= 2147483600.0f) {
                                fA = fA - 2147483600.0f;
                            }
                            {
                                s32 _i = (s32)fA;
                                s32 _s = _i << 24;
                                color[0] = cb | (u32)_s;
                            }
                        }
                        pi[0] = cur + 1;
                    } else {
                        s32 k;
                        k = 0;
                        while (k < 13) {
                            vertex[k * 3 + 0] = 0.0f;
                            vertex[k * 3 + 1] = 0.0f;
                            vertex[k * 3 + 2] = 0.0f;
                            color[k] = 0;
                            k++;
                        }
                        if ((s32)spD0 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        pi[0] = cur;
                    }
                }
                pi += 11;
                pif = (f32 *)pi;
                vertex += 39;
                color += 13;
                loop++;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(pu3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)pu3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}
#pragma opt_propagation on
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049c3d0);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
// FUN_0049D360 NONMATCHING
/* Floor (re-measured 2026-09-17, source-repo only): measure_guarded 465 words (1932B/1984B), fnalign 493/483/466. Four-pragma sweep: bare 465/466, opt_propagation off 461/451 WINNER by words, loop_invariants 463/352 (99 fewer edits, rotation collapses per mdlSE lesson), both COMPILE ERROR, others neutral/worse. measured: opt_propagation off inside guard (push/pop) is worth 4 words; loop gives fewer edits but 2 more words -- prop installed by words, loop edits noted for next pass. Residual is saved/FP coloring + COP2 slot addresses + standalone MMI pextlb/pextlh + s128-canonicalization family. Emitted 1928B/window 1984B (97.2%%, 2.8%% short PASS). Banked as guarded floor (updates prior guard); production stays ASM. */
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_0049d360(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_21;
    s32 temp_22;
    f32 temp_24;
    f32 temp_25;
    f32 temp_26;
    f32 scale;
    f32 fVar9;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 iVar6;
    s32 bVar7;
    s32 iVar17;
    s32 iVar18;
    s32 iVar19;
    s32 iVar20;
    f32 fVar21;
    u32 uVar22;
    u32 uVar23;
    u32 *puVar15;
    u32 *puVar14;
    u32 c58;
    u32 c5c;
    s32 *pt58;
    s32 *pt5c;
    s128 au13;
    s128 au27;
    s128 au28;
    s128 au29;
    s128 au30;
    s128 au31;
    s128 au32;
    s128 au33;
    u32 temp_6;
    u32 temp_7;
    f32 t320;
    f32 t328;
    f32 f6c;
    f32 f27o;
    s8 cVar1;

    temp_2 = *(u8 **)(arg0 + 0x40);
    temp_7 = *(u32 *)(temp_2 + 0x34);
    temp_6 = *(u32 *)(arg0 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(temp_2 + 0x38);
        iVar5 = *(s32 *)(temp_2 + 0x4C);
        if (iVar5 != 0)
        {
            if ((*(s8 *)(temp_2 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0))
            {
                bVar7 = 0;
                iVar17 = *(s32 *)(temp_2 + 0x50);
            }
            else
            {
                bVar7 = 1;
                iVar17 = iVar4;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u32 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(temp_2 + 0x58);
            pt58 = (s32 *)&c58;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt58), "f"(scale), "r"(&au13)
                : "$2", "$vf2", "$vf10", "memory");
            c5c = *(u32 *)(temp_2 + 0x5C);
            pt5c = (s32 *)&c5c;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(pt5c), "f"(scale), "r"(&au27)
                : "$2", "$vf2", "$vf10", "memory");
            iVar19 = (s32)(*(f32 *)(temp_2 + 0x44) * (f32)iVar5);
            iVar20 = (s32)(*(f32 *)(temp_2 + 0x48) * (f32)iVar5);
            temp_26 = *(f32 *)(temp_2 + 0x7C);
            iVar6 = *(s32 *)(temp_2 + 0x70);
            cVar1 = *(s8 *)(temp_2 + 0x54);
            fVar9 = 0.5f;
            temp_18 = 0;
            while (temp_18 < iVar4)
            {
                temp_21 = *piVar16;
                if (temp_21 != -2)
                {
                    if (temp_21 == -1)
                    {
                        if (iVar17 != 0)
                        {
                            temp_24 = func_004bd0b0(0);
                            piVar16[2] = (s32)(scale * temp_24);
                            f6c = *(f32 *)(temp_2 + 0x78);
                            temp_24 = func_004bd0b0(0);
                            piVar16[1] = (s32)(*(f32 *)(temp_2 + 0x74) * (0.0f + (1.0f - f6c) + f6c * temp_24));
                            temp_22 = func_004bd050(0);
                            if ((temp_22 & 1) != 0)
                            {
                                piVar16[1] = (s32)((f32)piVar16[1] * -1.0f);
                            }
                            piVar16[3] = 0;
                            f6c = *(f32 *)(temp_2 + 0x6C);
                            temp_24 = func_004bd0b0(0);
                            piVar16[4] = (s32)((*(f32 *)(temp_2 + 0x68) * (0.0f + (1.0f - f6c) + f6c * temp_24)) / (f32)iVar6);
                            f6c = *(f32 *)(temp_2 + 100);
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[5] = *(f32 *)(temp_2 + 0x60) * (0.0f + (1.0f - f6c) + f6c * temp_24);
                            if (bVar7 != 0)
                            {
                                temp_22 = func_004bd050(0);
                                *piVar16 = (s32)(temp_22 % (u32)iVar5);
                                piVar16[3] = (s32)(0.0f + (f32)piVar16[3] + (f32)piVar16[4] * (f32)((temp_22 % (u32)iVar5) % iVar6));
                            }
                            else
                            {
                                *piVar16 = 0;
                            }
                            iVar17 += -1;
                        }
                    }
                    else if (temp_21 < iVar5)
                    {
                        temp_24 = (f32)temp_21;
                        temp_25 = *(f32 *)(&piVar16[1]);
                        if (0.0f < temp_25)
                        {
                            temp_25 = 0.0f + temp_25 + fVar9 * (temp_26 * temp_24);
                        }
                        else
                        {
                            temp_25 = 0.0f + temp_25 - fVar9 * (temp_26 * temp_24);
                        }
                        f27o = temp_24 * temp_25 + (f32)piVar16[2];
                        if (temp_21 < iVar6)
                        {
                            piVar16[3] = (s32)((f32)piVar16[3] + (f32)piVar16[4]);
                        }
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "vmove.xyzw $vf10, $vf11  \n"
                            "lw $2, 20(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            :
                            : "r"(D_00713CE0), "r"(piVar16), "r"(&au31), "r"(&au29)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        t320 = func_0044b610(fVar21);
                        t328 = func_0044b7b0(fVar21);
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "qmfc2 $2, $vf10          \n"
                            "mtc1 $2, $f1             \n"
                            "qmfc2 $2, $vf10          \n"
                            "pexew $2, $2             \n"
                            "mtc1 $2, $f0             \n"
                            "nop                      \n"
                            "mfc1 $2, $f0             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.x $vf10x, $vf0x, $vf2x \n"
                            "mfc1 $2, $f1             \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.z $vf10z, $vf0z, $vf2x \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf10, $vf12  \n"
                            "lqc2 $vf11, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 24(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 28(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 32(%4)         \n"
                            "vsub.xyz $vf11xyz, $vf0xyz, $vf11xyz \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 36(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 40(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 44(%4)         \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "vadd.xyzw $vf10, $vf10, $vf12 \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 0(%4)          \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 4(%4)          \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 8(%4)          \n"
                            "vadd.xyzw $vf11, $vf11, $vf12 \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            "lwc1 $f0, 0(%3)          \n"
                            "swc1 $f0, 12(%4)         \n"
                            "lwc1 $f0, 4(%3)          \n"
                            "swc1 $f0, 16(%4)         \n"
                            "lwc1 $f0, 8(%3)          \n"
                            "swc1 $f0, 20(%4)         \n"
                            :
                            : "r"(&t320), "r"(&au29), "r"(&au31), "r"(D_00713D10), "r"(puVar15)
                            : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "$f1", "memory");
                        if (temp_21 < iVar19)
                        {
                            fVar21 = (f32)temp_21 / (f32)iVar19;
                        }
                        else
                        {
                            fVar21 = 1.0f;
                            if (iVar20 < temp_21)
                            {
                                fVar21 = (f32)(iVar5 - temp_21) / (f32)(iVar5 - iVar20);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, $f20            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%3)             \n"
                            "lw $2, 0(%3)             \n"
                            "sw $2, 0(%4)             \n"
                            "sw $2, 4(%4)             \n"
                            "lqc2 $vf10, 0(%5)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, $f20            \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%6)             \n"
                            "lw $2, 0(%6)             \n"
                            "sw $2, 8(%4)             \n"
                            "sw $2, 12(%4)            \n"
                            :
                            : "r"(D_00713CE0), "f"(fVar21), "r"(&au29), "r"(&au32), "r"(puVar14), "r"(&au13), "r"(&au30)
                            : "$2", "$vf2", "$vf10", "$vf11", "$f20", "memory");
                        *piVar16 = temp_21 + 1;
                    }
                    else
                    {
                        for (temp_21 = 0; temp_21 < 4; temp_21++)
                        {
                            puVar15[temp_21 * 3 + 0] = 0;
                            puVar15[temp_21 * 3 + 1] = 0;
                            puVar15[temp_21 * 3 + 2] = 0;
                            puVar14[temp_21] = 0;
                        }
                        if (cVar1 == 0)
                        {
                            temp_21 = -2;
                        }
                        else
                        {
                            temp_21 = -1;
                        }
                        *piVar16 = temp_21;
                    }
                    piVar16 += 6;
                    puVar15 += 12;
                    puVar14 += 4;
                }
                temp_17 = *(u8 **)(*(u32 **)(puVar3 + 8) + 6);
                func_003c22f0(temp_17);
                if (*(u16 *)puVar3 & 4)
                {
                    *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
                }
            }
        }
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049d360);
#endif





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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-19, source-repo only): banked 479 words (schedule+prop + pi-float), fnalign 499/491/731, emitted 1964B/window 2000B (-1.8%% inside gate). Base schedule+prop 483 (2024B/2000B +1.2%% over, 784 edits) -> pi-float 479 (-4, 1964B, 731 edits). piVar16[1..5] are floats via swc1 (m2c var_20->unk8/unkC/unk10/unk4/unk14 as (f32)(...), retail swc1 0x8/0xC/0x10/0x4/0x14), not (s32) ints: *(f32*)&piVar16[N] saves 5x cvt.w.s/mfc1/sw and adds 5x swc1 (opclass cvt +25->+20, mfc1 +17->+12, sw +19->+14, swc1 -24->-19, nop -27->-31 from rescheduling). Remaining +20/-19/+14/+12 are puVar15 12 float copies (retail lwc1/swc1 triples from D_00713D10, this body (u32) with 0x4F00 clamping) + puVar14 4 unsigned (retail VU vftoi/ppach/ppacb, this body (u32)(fade*255) with c.ole.s/bc1tl/or/lui) + c58/c5c 2 (retail VU pextlb/vitof/vmulx/sqc2 to 0x170/0x160, this body scalar (u32)((f32)(c&0xFF)*scale)): single float-vs-int mechanism ~44 instrs as assigned. dmtc2 -12/dmfc2 -4 (16 qmtc2/qmfc2) + ?? -35 + bbit132/032 -8/-8 are interior VU (vitof0/vmulx/vmove/vadd/vsub/vftoi/ppach + pextlb/h) + GPR lq/sq, not FPU accumulator: capstone renders VU macro-mode as ?? (handoff VU section); retail ??36 = 5 GPR lq/sq +6 FPU adda/madd +2 c1 +23 VU/MMI per mdlEffect 004a6e70 census, obj ??15 = 7 GPR +6 FPU +2 c1 +0 VU. u_long128/s128 aligned(16) emits GPR lq/sq (micro: u_long128 -> andi.b/ext, f32[4] -> lwc1/swc1), never qmtc2/vitof/vmul/vftoi (mdlEffect note); interior pipeline needs genuine COP2 asm bridges as in sibling 0049aa30 (pextlb/qmtc2/vitof/mfc1/qmtc2/vmulx/sqc2 + lqc2/vmove/qmtc2/vmulx/sqc2 + lqc2/vmul/vftoi/qmfc2/ppach, btlMain RwV4d/u_long128 matrix copy is GPR idiom). Tried: V1 pi+puVar15-float 463 but 357 vs 499 (-28%% outside gate); V3b V1+c58-VU(nomask, retail has no &0xFFFFFF unlike sibling) 448 but 386 vs 499 outside; V4 color-VU (D_00713CE0/fade/vec160->pack0 + vec170->pack1, $f20=255) 472 worse (extra addiu for pack pointer, $vf11 persistence); V6 position-VU (vec150[0]=t320/[2]=t328 with [1]/[3]=0 hoisted, lqc2/vmove/qmtc2/vmulx/sqc2 0x130/0x140 + qmfc2/pexew/vaddx + lqc2/vadd/sqc2 D_00713D10 + 4x lwc1/swc1 triples) 463/468 worse (extra per-iter zeros, _f27 move); V9 c58-only 507 worse (+29, 535 vs 500 +7%% outside); V10 pi+c58 488 worse; V5 s32-color ties 448; V7 pi-only 479 stands (inside gate). dsll32/dsra32 +6/+6 s128 width wall (sp100 reused for 0x110+0x100, spC0 (s32) narrowing needs asm lq-read per note), lb+3/lbu-3 kept s8 (u8 +4). Frame -0x110 vs -0x190 (5 vectors short: 0x130/0x140/0x150/0x160/0x170 + 0xC0 sq), rotation persists. Banked as guarded floor; production stays ASM. */
/* measured 2026-09-19 loopinv: schedule+prop+loopinv 479->463 words (-16), fnalign 499/489/661 (was 499/491/731, -70 edits), opclass lui +20->+17 (-3), lwc1 -13->-8, swc1 -19->-14, emitted 1956B/window 2000B (-2.2% inside gate). Installed (strict win, inside gate). Zero-lui float variant (puVar15-float) reaches lui -1 with 463->? words but 357/499 outside gate, not banked; missing VU interior (D_00713CE0 + vftoi/ppach) to bring count back. */
// FUN_0049E150 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_0049e150(u8 *arg0)
{
    u8 *temp_2;
    s32 *piVar16;
    u16 *puVar3;
    s32 iVar4;
    s32 iVar5;
    s32 bVar;
    s32 iVar17;
    u32 *puVar15;
    u32 *puVar14;
    u32 c58;
    u32 c5c;
    f32 scale;
    s128 sp100 __attribute__((aligned(16)));
    s128 spF0 __attribute__((aligned(16)));
    s128 spD0 __attribute__((aligned(16)));
    s128 spC0 __attribute__((aligned(16)));
    s32 temp_18;
    s32 temp_21;
    s32 temp_22;
    f32 temp_24;
    f32 temp_25;
    f32 fVar21;
    f32 f27o;
    s32 iVar19;
    s32 iVar20;
    s8 cVar1;
    f32 fVar26;
    f32 t320;
    f32 t328;
    f32 f6c;
    u32 temp_6;
    u32 temp_7;
    s32 ecVal;
    s32 e8Val;
    s32 d0Val;
    f32 fVar18;
    f32 f25;

    temp_2 = *(u8 **)(arg0 + 0x40);
    temp_7 = *(u32 *)(temp_2 + 0x34);
    temp_6 = *(u32 *)(arg0 + 0x34);
    if ((temp_7 >= temp_6) || (temp_7 == 0))
    {
        piVar16 = *(s32 **)(arg0 + 0x3C);
        puVar3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        iVar4 = *(s32 *)(temp_2 + 0x38);
        *(s32 *)&sp100 = iVar4;
        iVar5 = *(s32 *)(temp_2 + 0x4C);
        if (iVar5 != 0)
        {
            if (*(u8 *)(temp_2 + 0x84) == 0)
            {
                ecVal = 0;
                e8Val = iVar5;
                d0Val = 1;
                *(s32 *)&spD0 = d0Val;
                iVar19 = (s32)(*(f32 *)(temp_2 + 0x44) * (f32)iVar5);
                *(s32 *)&sp100 = iVar19;
                iVar20 = (s32)(*(f32 *)(temp_2 + 0x48) * (f32)iVar5);
                *(s32 *)&spF0 = iVar20;
            }
            else
            {
                ecVal = iVar5;
                e8Val = 0;
                d0Val = -1;
                *(s32 *)&spD0 = d0Val;
                iVar19 = (s32)((1.0f - *(f32 *)(temp_2 + 0x48)) * (f32)iVar5);
                *(s32 *)&sp100 = iVar19;
                iVar20 = (s32)((1.0f - *(f32 *)(temp_2 + 0x44)) * (f32)iVar5);
                *(s32 *)&spF0 = iVar20;
            }
            if ((*(u8 *)(temp_2 + 0x55) == 0) || (*(u32 *)(arg0 + 0x34) != 0))
            {
                bVar = 0;
                iVar17 = *(s32 *)(temp_2 + 0x50);
            }
            else
            {
                bVar = 1;
                iVar17 = (s32)sp100;
            }
            func_003c2290(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18), 10);
            puVar15 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x5C) + 0x14);
            puVar14 = (u32 *)(*(u8 **)(*(u8 **)(puVar3 + 8) + 0x18) + 0x30);
            c58 = *(u32 *)(temp_2 + 0x58);
            scale = fGpffff8044;
            c58 = (u32)((f32)(c58 & 0xFF) * scale);
            c5c = *(u32 *)(temp_2 + 0x5C);
            c5c = (u32)((f32)(c5c & 0xFF) * scale);
            fVar26 = *(f32 *)(temp_2 + 0x80);
            cVar1 = *(s8 *)(temp_2 + 0x54);
            spC0 = (s128)(s32)(s32)cVar1;
            temp_18 = 0;
            while (temp_18 < (s32)sp100)
            {
                temp_21 = *piVar16;
                if (temp_21 != -2)
                {
                    if (temp_21 == -1)
                    {
                        if (iVar17 != 0)
                        {
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[2] = fGpffff80d0 * temp_24;
                            f6c = *(f32 *)(temp_2 + 0x6C);
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[3] = *(f32 *)(temp_2 + 0x68) * (0.0f + (1.0f - f6c) + f6c * temp_24);
                            f6c = *(f32 *)(temp_2 + 0x74);
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[4] = *(f32 *)(temp_2 + 0x70) * (0.0f + (1.0f - f6c) + f6c * temp_24);
                            f6c = *(f32 *)(temp_2 + 0x7C);
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[1] = *(f32 *)(temp_2 + 0x78) * (0.0f + (1.0f - f6c) + f6c * temp_24);
                            f6c = *(f32 *)(temp_2 + 100);
                            temp_24 = func_004bd0b0(0);
                            *(f32 *)&piVar16[5] = *(f32 *)(temp_2 + 0x60) * (0.0f + (1.0f - f6c) + f6c * temp_24);
                            if (bVar != 0)
                            {
                                temp_22 = func_004bd050(0);
                                *piVar16 = (s32)(temp_22 % (u32)iVar5);
                            }
                            else
                            {
                                *piVar16 = ecVal;
                            }
                            iVar17 += -1;
                        }
                    }
                    else if (temp_21 == e8Val)
                    {
                        s32 k;
                        k = 0;
                        while (k < 4)
                        {
                            puVar15[k * 3 + 0] = 0;
                            puVar15[k * 3 + 1] = 0;
                            puVar15[k * 3 + 2] = 0;
                            puVar14[k] = 0;
                            k++;
                        }
                        if ((s32)spC0 == 0)
                        {
                            temp_21 = -2;
                        }
                        else
                        {
                            temp_21 = -1;
                        }
                        *piVar16 = temp_21;
                    }
                    else
                    {
                        temp_24 = (f32)temp_21;
                        temp_25 = *(f32 *)(&piVar16[1]);
                        fVar21 = temp_24;
                        if (fVar26 < 0.0f)
                        {
                            f25 = -(float)piVar16[1] / (0.5f * fVar26);
                            fVar18 = 0.5f * fVar26;
                            f25 = f25 * 0.5f;
                            if (fVar21 <= f25)
                            {
                                fVar18 = fVar21;
                            }
                            else
                            {
                                fVar18 = f25;
                            }
                        }
                        else
                        {
                            fVar18 = fVar21;
                        }
                        f27o = fVar18 * (0.5f * fVar26 * fVar18 + (float)piVar16[1] + 0.0f) + (float)piVar16[2];
                        t320 = func_0044b610(*(f32 *)&piVar16[2]);
                        t328 = func_0044b7b0(*(f32 *)&piVar16[2]);
                        D_00713D10[0] = f27o;
                        D_00713D10[1] = t320;
                        D_00713D10[2] = t328;
                        puVar15[0] = (u32)D_00713D10[0];
                        puVar15[1] = (u32)D_00713D10[1];
                        puVar15[2] = (u32)D_00713D10[2];
                        puVar15[3] = (u32)D_00713D10[0];
                        puVar15[4] = (u32)D_00713D10[1];
                        puVar15[5] = (u32)D_00713D10[2];
                        puVar15[6] = (u32)f27o;
                        puVar15[7] = (u32)t320;
                        puVar15[8] = (u32)t328;
                        puVar15[9] = (u32)f27o;
                        puVar15[10] = (u32)t320;
                        puVar15[11] = (u32)t328;
                        if (temp_21 < (s32)sp100)
                        {
                            fVar21 = (f32)temp_21 / (f32)(s32)sp100;
                        }
                        else
                        {
                            fVar21 = 1.0f;
                            if ((s32)spF0 < temp_21)
                            {
                                fVar21 = (f32)(iVar5 - temp_21) / (f32)(iVar5 - (s32)spF0);
                            }
                        }
                        puVar14[0] = (u32)(fVar21 * 255.0f);
                        puVar14[1] = (u32)(fVar21 * 255.0f);
                        puVar14[2] = (u32)(fVar21 * 255.0f);
                        puVar14[3] = (u32)(fVar21 * 255.0f);
                        *piVar16 = temp_21 + (s32)spD0;
                    }
                    piVar16 += 6;
                    puVar15 += 12;
                    puVar14 += 4;
                }
                {
                    u8 *temp_17;
                    temp_17 = *(u8 **)(*(u32 **)(puVar3 + 8) + 6);
                    func_003c22f0(temp_17);
                    if (*(u16 *)puVar3 & 4)
                    {
                        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
                    }
                }
                temp_18++;
            }
        }
    }
}

#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049e150);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): probe 471 words (v4), fnalign 563/562/247 (retail/object/edits, 1 short PASS), emitted window 2256B. Chain: v1 scalar+bridges 518/278/548 -> v2 packs-to-words+q140-min 504/262/540 -> v3 correct q140(pi5)/q130(pi7)+c-post 474/257/547 -> v4 interleave second-half VU (vsub/vmove/pi3) 471/247/562. Micro-priced casts: (s32)(f*(f32)n) 8 instrs vs (u32) 21 (saves 13 per fade, cf. func_004aed70 815->493 via signed s32 word arithmetic); colour packing via single VU bridge per loop (lui 0x437F) not per-channel unsigned casts. Float order sweep (f80d0/fA0/fC/f1t/fD, 4 variants) neutral 471, stopped. Residual is saved-GPR/FP pool rotation + COP2 slot addresses + standalone MMI pextlb/pextlh + s128-canonicalization (lq/dsll32/dsra32 on sp100/spF0/spE0/spD0) + daddu zero-idiom + paddub move. Banked as guarded floor; production stays ASM. */
// FUN_0049EF50 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0049ef50(u8 *arg0)
{
    u8 *tmp17;
    u32 tmp34;
    u32 arg34;
    s32 *pi;
    f32 *pif;
    u16 *pu3;
    s32 cnt38;
    s32 cnt4C;
    s32 bVar;
    s32 var22;
    f32 *vertex;
    u32 *color;
    s32 sp19C;
    s32 sp198;
    s128 colA;
    s128 colB;
    s128 q120;
    s128 q140;
    s128 q130;
    u32 packA;
    u32 packB;
    s128 spD0;
    s128 spF0;
    s128 spE0;
    s128 sp100;
    f32 scale;
    f32 f80d0;
    f32 fA0;
    u8 cVar1;
    s32 loop;
    s32 cur;
    s32 tmp;
    f32 ftmp;
    f32 fC;
    f32 f1t;
    f32 fD;
    f32 fRem;

    tmp17 = *(u8 **)(arg0 + 0x40);
    tmp34 = *(u32 *)(tmp17 + 0x34);
    arg34 = *(u32 *)(arg0 + 0x34);
    if ((tmp34 >= arg34) || (tmp34 == 0)) {
        pi = *(s32 **)(arg0 + 0x3C);
        pif = (f32 *)pi;
        pu3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        cnt38 = *(s32 *)(tmp17 + 0x38);
        *(s32 *)&sp100 = cnt38;
        cnt4C = *(s32 *)(tmp17 + 0x4C);
        if (cnt4C != 0) {
            if ((*(u8 *)(tmp17 + 0x55) == 0) || (arg34 != 0)) {
                bVar = 0;
                var22 = *(s32 *)(tmp17 + 0x50);
            } else {
                bVar = 1;
                var22 = cnt38;
            }
            func_003c2290(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18), 10);
            vertex = (f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x5C) + 0x14);
            color = (u32 *)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x30);
            sp19C = *(s32 *)(tmp17 + 0x58);
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp19C), "f"(scale), "r"(&colA)
                : "$2", "$vf2", "$vf10", "memory");
            sp198 = *(s32 *)(tmp17 + 0x5C);
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp198), "f"(scale), "r"(&colB)
                : "$2", "$vf2", "$vf10", "memory");
            *(s32 *)&spF0 = (s32)(*(f32 *)(tmp17 + 0x44) * (f32)cnt4C);
            *(s32 *)&spE0 = (s32)(*(f32 *)(tmp17 + 0x48) * (f32)cnt4C);
            fA0 = *(f32 *)(tmp17 + 0xA0);
            cVar1 = *(u8 *)(tmp17 + 0x54);
            spD0 = (s128)(s32)cVar1;
            f80d0 = fGpffff80d0;
            ((s32 *)&q140)[1] = 0;
            ((s32 *)&q140)[3] = 0;
            loop = 0;
            while (loop < (s32)sp100) {
                cur = pi[0];
                if (cur != -2) {
                    if (cur == -1) {
                        if (var22 != 0) {
                            ftmp = func_004bd0b0(0);
                            pif[1] = f80d0 * ftmp;
                            fC = *(f32 *)(tmp17 + 0x6C);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x68) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[3] = f1t;
                            fC = *(f32 *)(tmp17 + 0x74);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x70) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[4] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x7C);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x78) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[5] = f1t;
                            fC = *(f32 *)(tmp17 + 0x84);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x80) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[6] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x8C);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x88) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[7] = f1t;
                            fC = *(f32 *)(tmp17 + 0x94);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x90) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[8] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x64);
                            ftmp = func_004bd0b0(0);
                            pif[9] = *(f32 *)(tmp17 + 0x60) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x9C);
                            ftmp = func_004bd0b0(0);
                            pif[2] = *(f32 *)(tmp17 + 0x98) * (0.0f + (1.0f - fC) + fC * ftmp);
                            if (bVar != 0) {
                                tmp = func_004bd050(0);
                                fRem = (f32)(u32)(tmp % (u32)cnt4C);
                                pif[3] = pif[3] + pif[4] * fRem;
                                pif[5] = pif[5] + pif[6] * fRem;
                                pif[7] = pif[7] + pif[8] * fRem;
                                pi[0] = (s32)fRem;
                            } else {
                                pi[0] = 0;
                            }
                            var22 -= 1;
                        }
                    } else if (cur < cnt4C) {
                        f32 curf;
                        f32 pi1;
                        f32 pi2;
                        f32 f3;
                        f32 f0m;
                        f32 f29v;
                        f32 s;
                        f32 c;
                        f32 fade;
                        f32 pi5;
                        f32 pi7;

                        curf = (f32)cur;
                        pi1 = pif[1];
                        pi2 = pif[2];
                        f0m = 0.0f + pi2 + 0.5f * (fA0 * curf);
                        f29v = curf * f0m + pi1;
                        pi5 = pif[5];
                        pi7 = pif[7];
                        s = func_0044b610(f29v);
                        c = func_0044b7b0(f29v);
                        ((f32 *)&q140)[0] = s * pi5;
                        ((f32 *)&q140)[2] = c * pi5;
                        ((f32 *)&q130)[0] = s * pi7;
                        ((f32 *)&q130)[1] = 1.0f - pi7;
                        ((f32 *)&q130)[2] = c * pi7;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyz $vf2, $vf10, $vf10 \n"
                            "vmulax.w $ACC, $vf0, $vf2x \n"
                            "vmadday.w $ACC, $vf0, $vf2y \n"
                            "vmaddz.w $vf2, $vf0, $vf2z \n"
                            "vrsqrt $Q, $vf0w, $vf2w \n"
                            "vwaitq                  \n"
                            "vmulq.xyz $vf10, $vf10, $Q \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            :
                            : "r"(&q130)
                            : "$vf2", "$vf10", "$vf12", "memory");
                        ((f32 *)&q130)[0] = c;
                        ((f32 *)&q130)[1] = 0.0f;
                        ((f32 *)&q130)[2] = -(s);
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "lw $2, 36(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "lqc2 $vf10, 0(%3)        \n"
                            "lqc2 $vf11, 0(%2)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%4)        \n"
                            :
                            : "r"(&q130), "r"(pi), "r"(&q120), "r"(&q140), "r"(D_00713D10)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        vertex[6] = ((f32 *)D_00713D10)[0];
                        vertex[7] = ((f32 *)D_00713D10)[1];
                        vertex[8] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%0)        \n"
                            :
                            : "r"(D_00713D10)
                            : "$vf10", "$vf11", "memory");
                        vertex[9] = ((f32 *)D_00713D10)[0];
                        vertex[10] = ((f32 *)D_00713D10)[1];
                        vertex[11] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vmove.xyzw $vf11, $vf12  \n"
                            "lw $2, 12(%0)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "lqc2 $vf11, 0(%2)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            :
                            : "r"(pi), "r"(&q140), "r"(&q120), "r"(D_00713D10)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        vertex[0] = ((f32 *)D_00713D10)[0];
                        vertex[1] = ((f32 *)D_00713D10)[1];
                        vertex[2] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%0)        \n"
                            :
                            : "r"(D_00713D10)
                            : "$vf10", "$vf11", "memory");
                        vertex[3] = ((f32 *)D_00713D10)[0];
                        vertex[4] = ((f32 *)D_00713D10)[1];
                        vertex[5] = ((f32 *)D_00713D10)[2];
                        pif[3] = pif[3] + pif[4];
                        pif[7] = pif[7] + pif[8];
                        pif[5] = pif[5] + pif[6];
                        if (cur < (s32)spF0) {
                            fade = (f32)cur / (f32)(s32)spF0;
                        } else {
                            fade = 1.0f;
                            if ((s32)spE0 < cur) {
                                fade = (f32)(cnt4C - cur) / (f32)(cnt4C - (s32)spE0);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%4)             \n"
                            :
                            : "r"(D_00713CE0), "f"(fade), "r"(&colB), "f"(255.0f), "r"(&packA)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        color[0] = *(u32 *)&packA;
                        color[1] = *(u32 *)&packA;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%2)             \n"
                            :
                            : "r"(&colA), "f"(255.0f), "r"(&packB)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        color[2] = *(u32 *)&packB;
                        color[3] = *(u32 *)&packB;
                        pi[0] = cur + 1;
                    } else {
                        s32 k;
                        k = 0;
                        while (k < 4) {
                            vertex[k * 3 + 0] = 0.0f;
                            vertex[k * 3 + 1] = 0.0f;
                            vertex[k * 3 + 2] = 0.0f;
                            color[k] = 0;
                            k++;
                        }
                        if ((s32)spD0 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        pi[0] = cur;
                    }
                }
                pi += 10;
                pif = (f32 *)pi;
                vertex += 12;
                color += 4;
                loop++;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(pu3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)pu3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049ef50);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): measure_guarded 594 words (loop), fnalign 640/640/32 (+20 reloc-only, exact count). Pragma sweep: bare 612, loop 594 WINNER (-18), unroll off 612 tie, schedule off 612 tie; pairs not tried (loop stands by words). Subscript: clear-loop row-hoist (v=vertex+k*3) 594 tie, off=k*3 594 tie -- direct vertex[k*3+.] stands. Colouring: vertex/color swap 594 tie, colA/colB swap 594 tie -- declaration order stands. Micro-priced casts: (s32)(f*(f32)n) for spF0/spE0 fades (8 instrs vs (u32) 21, cf. func_0049ef50); colour packing via single VU bridge per loop (lui 0x437F, mfc1 $f22) not per-channel casts. Structure: 11-word pi (extra 0x64 slot sharing 0x68 rand), 15-word vertex (extra 12..14 triple via double vsub), 5-word color with loop&1 alpha (0xFF+128 vs 0x80+255, cf. func_0049aa30 but 0x80 not 0x40). Residual is saved-GPR/FP pool rotation + COP2 slot addresses + standalone MMI pextlb/pextlh + s128-canonicalization (lq/dsll32) + paddub move + daddu zero-idiom; banked as guarded floor; production stays ASM. */
// FUN_0049FBF0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0049fbf0(u8 *arg0)
{
    u8 *tmp17;
    u32 tmp34;
    u32 arg34;
    s32 *pi;
    f32 *pif;
    u16 *pu3;
    s32 cnt38;
    s32 cnt4C;
    s32 bVar;
    s32 var22;
    f32 *vertex;
    u32 *color;
    s32 sp18C;
    s32 sp188;
    s128 colA;
    s128 colB;
    s128 q120;
    s128 q130;
    s128 q140;
    s128 q150;
    u32 packA;
    u32 packB;
    s128 spD0;
    s128 spF0;
    s128 spE0;
    s128 sp100;
    f32 scale;
    f32 f80d0;
    f32 fA4;
    u8 cVar1;
    s32 loop;
    s32 cur;
    s32 tmp;
    f32 ftmp;
    f32 fC;
    f32 f1t;
    f32 fD;
    f32 fRem;

    tmp17 = *(u8 **)(arg0 + 0x40);
    tmp34 = *(u32 *)(tmp17 + 0x34);
    arg34 = *(u32 *)(arg0 + 0x34);
    if ((tmp34 >= arg34) || (tmp34 == 0)) {
        pi = *(s32 **)(arg0 + 0x3C);
        pif = (f32 *)pi;
        pu3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        cnt38 = *(s32 *)(tmp17 + 0x38);
        *(s32 *)&sp100 = cnt38;
        cnt4C = *(s32 *)(tmp17 + 0x4C);
        if (cnt4C != 0) {
            if ((*(u8 *)(tmp17 + 0x55) == 0) || (arg34 != 0)) {
                bVar = 0;
                var22 = *(s32 *)(tmp17 + 0x50);
            } else {
                bVar = 1;
                var22 = cnt38;
            }
            func_003c2290(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18), 10);
            vertex = (f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x5C) + 0x14);
            color = (u32 *)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x30);
            sp18C = *(s32 *)(tmp17 + 0x58) & 0xFFFFFF;
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp18C), "f"(scale), "r"(&colA)
                : "$2", "$vf2", "$vf10", "memory");
            sp188 = *(s32 *)(tmp17 + 0x5C) & 0xFFFFFF;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp188), "f"(scale), "r"(&colB)
                : "$2", "$vf2", "$vf10", "memory");
            *(s32 *)&spF0 = (s32)(*(f32 *)(tmp17 + 0x44) * (f32)cnt4C);
            *(s32 *)&spE0 = (s32)(*(f32 *)(tmp17 + 0x48) * (f32)cnt4C);
            fA4 = *(f32 *)(tmp17 + 0xA4);
            cVar1 = *(u8 *)(tmp17 + 0x54);
            spD0 = (s128)(s32)cVar1;
            f80d0 = fGpffff80d0;
            ((s32 *)&q150)[1] = 0;
            ((s32 *)&q150)[3] = 0;
            loop = 0;
            while (loop < (s32)sp100) {
                cur = pi[0];
                if (cur != -2) {
                    if (cur == -1) {
                        if (var22 != 0) {
                            ftmp = func_004bd0b0(0);
                            pif[1] = f80d0 * ftmp;
                            fC = *(f32 *)(tmp17 + 0x70);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x6C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[3] = f1t;
                            fC = *(f32 *)(tmp17 + 0x78);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x74) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[4] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x80);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x7C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[5] = f1t;
                            fC = *(f32 *)(tmp17 + 0x88);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x84) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[6] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x90);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x8C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[7] = f1t;
                            fC = *(f32 *)(tmp17 + 0x98);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x94) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[8] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x68);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x60) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[9] = f1t;
                            pif[10] = *(f32 *)(tmp17 + 0x64) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0xA0);
                            ftmp = func_004bd0b0(0);
                            pif[2] = *(f32 *)(tmp17 + 0x9C) * (0.0f + (1.0f - fC) + fC * ftmp);
                            if (bVar != 0) {
                                tmp = func_004bd050(0);
                                fRem = (f32)(u32)(tmp % (u32)cnt4C);
                                pif[3] = pif[3] + pif[4] * fRem;
                                pif[5] = pif[5] + pif[6] * fRem;
                                pif[7] = pif[7] + pif[8] * fRem;
                                pi[0] = (s32)fRem;
                            } else {
                                pi[0] = 0;
                            }
                            var22 -= 1;
                        }
                    } else if (cur < cnt4C) {
                        f32 curf;
                        f32 pi1;
                        f32 pi2;
                        f32 f0m;
                        f32 f29v;
                        f32 s;
                        f32 c;
                        f32 fade;
                        f32 pi5;
                        f32 pi7;

                        curf = (f32)cur;
                        pi1 = pif[1];
                        pi2 = pif[2];
                        f0m = 0.0f + pi2 + 0.5f * (fA4 * curf);
                        f29v = curf * f0m + pi1;
                        pi5 = pif[5];
                        pi7 = pif[7];
                        s = func_0044b610(f29v);
                        c = func_0044b7b0(f29v);
                        ((f32 *)&q150)[0] = s * pi5;
                        ((f32 *)&q150)[2] = c * pi5;
                        ((f32 *)&q140)[0] = s * pi7;
                        ((f32 *)&q140)[1] = 1.0f - pi7;
                        ((f32 *)&q140)[2] = c * pi7;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyz $vf2, $vf10, $vf10 \n"
                            "vmulax.w $ACC, $vf0, $vf2x \n"
                            "vmadday.w $ACC, $vf0, $vf2y \n"
                            "vmaddz.w $vf2, $vf0, $vf2z \n"
                            "vrsqrt $Q, $vf0w, $vf2w \n"
                            "vwaitq                  \n"
                            "vmulq.xyz $vf10, $vf10, $Q \n"
                            "vmove.xyzw $vf12, $vf10  \n"
                            :
                            : "r"(&q140)
                            : "$vf2", "$vf10", "$vf12", "memory");
                        ((f32 *)&q140)[0] = c;
                        ((f32 *)&q140)[1] = 0.0f;
                        ((f32 *)&q140)[2] = -(s);
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 36(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "lw $2, 40(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "sqc2 $vf11, 0(%3)        \n"
                            :
                            : "r"(&q140), "r"(pi), "r"(&q130), "r"(&q120)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "sqc2 $vf10, 0(%1)        \n"
                            :
                            : "r"(&q150), "r"(D_00713D10)
                            : "$vf10", "memory");
                        vertex[9] = ((f32 *)D_00713D10)[0];
                        vertex[10] = ((f32 *)D_00713D10)[1];
                        vertex[11] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%1)        \n"
                            :
                            : "r"(&q130), "r"(D_00713D10)
                            : "$vf10", "$vf11", "memory");
                        vertex[6] = ((f32 *)D_00713D10)[0];
                        vertex[7] = ((f32 *)D_00713D10)[1];
                        vertex[8] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%0)        \n"
                            :
                            : "r"(D_00713D10)
                            : "$vf10", "$vf11", "memory");
                        vertex[12] = ((f32 *)D_00713D10)[0];
                        vertex[13] = ((f32 *)D_00713D10)[1];
                        vertex[14] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vmove.xyzw $vf11, $vf12  \n"
                            "lw $2, 12(%0)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%1)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "lqc2 $vf11, 0(%2)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%3)        \n"
                            :
                            : "r"(pi), "r"(&q150), "r"(&q120), "r"(D_00713D10)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        vertex[0] = ((f32 *)D_00713D10)[0];
                        vertex[1] = ((f32 *)D_00713D10)[1];
                        vertex[2] = ((f32 *)D_00713D10)[2];
                        __asm__ volatile(
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%0)        \n"
                            :
                            : "r"(D_00713D10)
                            : "$vf10", "$vf11", "memory");
                        vertex[3] = ((f32 *)D_00713D10)[0];
                        vertex[4] = ((f32 *)D_00713D10)[1];
                        vertex[5] = ((f32 *)D_00713D10)[2];
                        pif[3] = pif[3] + pif[4];
                        pif[7] = pif[7] + pif[8];
                        pif[5] = pif[5] + pif[6];
                        if (cur < (s32)spF0) {
                            fade = (f32)cur / (f32)(s32)spF0;
                        } else {
                            fade = 1.0f;
                            if ((s32)spE0 < cur) {
                                fade = (f32)(cnt4C - cur) / (f32)(cnt4C - (s32)spE0);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%4)             \n"
                            :
                            : "r"(D_00713CE0), "f"(fade), "r"(&colB), "f"(255.0f), "r"(&packA)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        color[0] = *(u32 *)&packA;
                        color[1] = *(u32 *)&packA;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%2)             \n"
                            :
                            : "r"(&colA), "f"(255.0f), "r"(&packB)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        {
                            f32 fA;
                            u32 cb = *(u32 *)&packB;
                            if ((loop & 1) != 0) {
                                *(u32 *)(color + 3) = cb | 0xFF000000;
                                fA = 128.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(color + 2) = _s;
                                    *(s32 *)(color + 4) = _s;
                                }
                            } else {
                                *(u32 *)(color + 3) = cb | 0x80000000;
                                fA = 255.0f * fade;
                                if (fA >= 2147483600.0f) {
                                    fA = fA - 2147483600.0f;
                                }
                                {
                                    s32 _i = (s32)fA;
                                    s32 _s = _i << 24;
                                    *(s32 *)(color + 2) = _s;
                                    *(s32 *)(color + 4) = _s;
                                }
                            }
                        }
                        pi[0] = cur + 1;
                    } else {
                        s32 k;
                        k = 0;
                        while (k < 5) {
                            vertex[k * 3 + 0] = 0.0f;
                            vertex[k * 3 + 1] = 0.0f;
                            vertex[k * 3 + 2] = 0.0f;
                            color[k] = 0;
                            k++;
                        }
                        if ((s32)spD0 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        pi[0] = cur;
                    }
                }
                pi += 11;
                pif = (f32 *)pi;
                vertex += 15;
                color += 5;
                loop++;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(pu3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)pu3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049fbf0);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
/* Named compiler floor: retail's standalone R5900 MMI pextlb/pextlh pair widens
   packed scalar color data before the COP2 block; b210 cannot emit this sequence
   from C. Leave the assembly fallback rather than forcing ordinary-computation asm. */
/* Floor (measured 2026-09-18, source-repo only): measure_guarded 492 words (loop), fnalign 552/540/250 (retail/object/edits), emitted 2160B/window 2208B (97.83% PASS by 48B). Pragma sweep: bare 523, prop 504, loop 492 WINNER, subs 560, sched 519, dead 511; loop+prop 504/203ed (fewer edits but more words, loop stands by words). Micro-priced casts: (s32)(f*(f32)n) 8 instrs vs (u32) 21 (saves 13 per fade); color packing via single VU bridge per loop (lui 0x437F) not per-channel unsigned casts (saves 60+, cf. func_004aed70 815->493 via signed s32 word arithmetic). Residual is saved-GPR/FP pool rotation + COP2 slot addresses + standalone MMI pextlb/pextlh + s128-canonicalization + daddu zero-idiom. Banked as guarded floor; production stays ASM. */
// FUN_004A0C00 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_004a0c00(u8 *arg0)
{
    u8 *tmp17;
    u32 tmp34;
    u32 arg34;
    s32 *pi;
    f32 *pif;
    u16 *pu3;
    s32 cnt38;
    s32 cnt4C;
    s32 spFC;
    s32 spF8;
    s32 spE0;
    s32 sp110;
    s32 sp100;
    s32 sp130;
    s32 var22;
    f32 *vertex;
    u32 *color;
    s32 sp19C;
    s32 sp198;
    s128 colA;
    s128 colB;
    s128 q140;
    s128 q150;
    s128 q160;
    s128 packA;
    s128 packB;
    s128 spD0;
    f32 scale;
    f32 f80d0;
    f32 f30;
    u8 cVar1;
    s32 loop;
    s32 cur;
    s32 tmp;
    f32 ftmp;
    f32 fC;
    f32 f1t;
    f32 fD;

    tmp17 = *(u8 **)(arg0 + 0x40);
    tmp34 = *(u32 *)(tmp17 + 0x34);
    arg34 = *(u32 *)(arg0 + 0x34);
    if ((tmp34 >= arg34) || (tmp34 == 0)) {
        pi = *(s32 **)(arg0 + 0x3C);
        pif = (f32 *)pi;
        pu3 = (u16 *)(*(u32 **)(arg0 + 0x3C))[1];
        cnt38 = *(s32 *)(tmp17 + 0x38);
        cnt4C = *(s32 *)(tmp17 + 0x4C);
        if (cnt4C != 0) {
            if (*(u8 *)(tmp17 + 0x94) != 0) {
                spFC = cnt4C;
                spF8 = 0;
                spE0 = -1;
                sp110 = (s32)((1.0f - *(f32 *)(tmp17 + 0x48)) * (f32)cnt4C);
                sp100 = (s32)((1.0f - *(f32 *)(tmp17 + 0x44)) * (f32)cnt4C);
            } else {
                spFC = 0;
                spF8 = cnt4C;
                spE0 = 1;
                sp110 = (s32)(*(f32 *)(tmp17 + 0x44) * (f32)cnt4C);
                sp100 = (s32)(*(f32 *)(tmp17 + 0x48) * (f32)cnt4C);
            }
            if ((*(u8 *)(tmp17 + 0x55) == 0) || (arg34 != 0)) {
                sp130 = 0;
                var22 = *(s32 *)(tmp17 + 0x50);
            } else {
                sp130 = 1;
                var22 = cnt38;
            }
            func_003c2290(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18), 10);
            vertex = (f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x5C) + 0x14);
            color = (u32 *)(*(u8 **)(*(u8 **)(pu3 + 8) + 0x18) + 0x30);
            sp19C = *(s32 *)(tmp17 + 0x58);
            scale = fGpffff8044;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp19C), "f"(scale), "r"(&colA)
                : "$2", "$vf2", "$vf10", "memory");
            sp198 = *(s32 *)(tmp17 + 0x5C);
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2 $2, $vf10       \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2 $2, $vf2        \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "sqc2 $vf10, 0(%2)     \n"
                :
                : "r"(&sp198), "f"(scale), "r"(&colB)
                : "$2", "$vf2", "$vf10", "memory");
            f30 = *(f32 *)(tmp17 + 0x90);
            cVar1 = *(u8 *)(tmp17 + 0x54);
            spD0 = (s128)(s32)cVar1;
            f80d0 = fGpffff80d0;
            ((f32 *)&q160)[0] = 0.0f;
            ((f32 *)&q160)[1] = 0.0f;
            ((s32 *)&q160)[1] = 0;
            ((s32 *)&q160)[3] = 0;
            loop = 0;
            while (loop < cnt38) {
                cur = pi[0];
                if (cur != -2) {
                    if (cur == -1) {
                        if (var22 != 0) {
                            ftmp = func_004bd0b0(0);
                            pif[2] = f80d0 * ftmp;
                            fC = *(f32 *)(tmp17 + 0x6C);
                            ftmp = func_004bd0b0(0);
                            pif[3] = *(f32 *)(tmp17 + 0x68) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x74);
                            ftmp = func_004bd0b0(0);
                            f1t = *(f32 *)(tmp17 + 0x70) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[4] = f1t;
                            fC = *(f32 *)(tmp17 + 0x7C);
                            ftmp = func_004bd0b0(0);
                            fD = *(f32 *)(tmp17 + 0x78) * (0.0f + (1.0f - fC) + fC * ftmp);
                            pif[5] = (fD - f1t) / (f32)cnt4C;
                            fC = *(f32 *)(tmp17 + 0x8C);
                            ftmp = func_004bd0b0(0);
                            pif[1] = *(f32 *)(tmp17 + 0x88) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x64);
                            ftmp = func_004bd0b0(0);
                            pif[7] = *(f32 *)(tmp17 + 0x60) * (0.0f + (1.0f - fC) + fC * ftmp);
                            fC = *(f32 *)(tmp17 + 0x84);
                            ftmp = func_004bd0b0(0);
                            pif[6] = *(f32 *)(tmp17 + 0x80) * (0.0f + (1.0f - fC) + fC * ftmp);
                            if (sp130 != 0) {
                                tmp = func_004bd050(0);
                                pi[0] = (s32)(tmp % (u32)cnt4C);
                            } else {
                                pi[0] = spFC;
                            }
                            var22 -= 1;
                        }
                    } else if (cur == spF8) {
                        s32 k;
                        k = 0;
                        while (k < 4) {
                            vertex[k * 3 + 0] = 0.0f;
                            vertex[k * 3 + 1] = 0.0f;
                            vertex[k * 3 + 2] = 0.0f;
                            color[k] = 0;
                            k++;
                        }
                        if ((s32)spD0 == 0) {
                            cur = -2;
                        } else {
                            cur = -1;
                        }
                        pi[0] = cur;
                    } else {
                        f32 curf;
                        f32 pi1;
                        f32 f3;
                        f32 f1m;
                        f32 f0m;
                        f32 f29v;
                        f32 f21v;
                        f32 pi4;
                        f32 pi5;
                        f32 pi6;
                        f32 s;
                        f32 c;
                        f32 fade;

                        curf = (f32)cur;
                        pi1 = pif[1];
                        f3 = curf;
                        if (f30 < 0.0f) {
                            f32 comp;
                            comp = 0.5f * (-(pi1) / (0.5f * f30));
                            if (curf > comp) {
                                f3 = comp;
                            }
                        }
                        f1m = f30 * f3;
                        f0m = 0.0f + pi1 + 0.5f * f1m;
                        f29v = f3 * f0m;
                        pi4 = pif[4];
                        pi5 = pif[5];
                        f21v = pi4 + pi5 * f3;
                        pi6 = pif[6];
                        s = func_0044b610(pif[2]);
                        c = func_0044b7b0(pif[2]);
                        ((f32 *)&q160)[0] = s * pi6;
                        ((f32 *)&q160)[1] = 1.0f - pi6;
                        ((f32 *)&q160)[2] = c * pi6;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmove.xyzw $vf11, $vf10  \n"
                            "lw $2, 12(%1)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%2)        \n"
                            "vmove.xyzw $vf10, $vf11  \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%0)        \n"
                            :
                            : "r"(&q160), "r"(pi), "r"(&q140), "f"(f29v)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        ((f32 *)&q160)[0] = ((f32 *)&q160)[0] + s * f21v;
                        ((f32 *)&q160)[2] = ((f32 *)&q160)[2] + c * f21v;
                        __asm__ volatile(
                            "mfc1 $2, %0              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.x $vf10, $vf0, $vf2x \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.y $vf10, $vf0, $vf2x \n"
                            "mfc1 $2, %2              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vaddx.z $vf10, $vf0, $vf2x \n"
                            "lw $2, 28(%3)            \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "sqc2 $vf10, 0(%4)        \n"
                            "lqc2 $vf12, 0(%5)        \n"
                            "lqc2 $vf10, 0(%6)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf12 \n"
                            "lqc2 $vf11, 0(%4)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%7)        \n"
                            "lwc1 $f0, 0(%7)          \n"
                            "swc1 $f0, 0(%8)          \n"
                            "lwc1 $f0, 4(%7)          \n"
                            "swc1 $f0, 4(%8)          \n"
                            "lwc1 $f0, 8(%7)          \n"
                            "swc1 $f0, 8(%8)          \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%7)        \n"
                            "lwc1 $f0, 0(%7)          \n"
                            "swc1 $f0, 12(%8)         \n"
                            "lwc1 $f0, 4(%7)          \n"
                            "swc1 $f0, 16(%8)         \n"
                            "lwc1 $f0, 8(%7)          \n"
                            "swc1 $f0, 20(%8)         \n"
                            "lqc2 $vf10, 0(%6)        \n"
                            "vsub.xyz $vf10, $vf0, $vf10 \n"
                            "vadd.xyzw $vf10, $vf10, $vf12 \n"
                            "lqc2 $vf11, 0(%4)        \n"
                            "vadd.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%7)        \n"
                            "lwc1 $f0, 0(%7)          \n"
                            "swc1 $f0, 24(%8)         \n"
                            "lwc1 $f0, 4(%7)          \n"
                            "swc1 $f0, 28(%8)         \n"
                            "lwc1 $f0, 8(%7)          \n"
                            "swc1 $f0, 32(%8)         \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "vsub.xyzw $vf10, $vf10, $vf11 \n"
                            "sqc2 $vf10, 0(%7)        \n"
                            "lwc1 $f0, 0(%7)          \n"
                            "swc1 $f0, 36(%8)         \n"
                            "lwc1 $f0, 4(%7)          \n"
                            "swc1 $f0, 40(%8)         \n"
                            "lwc1 $f0, 8(%7)          \n"
                            "swc1 $f0, 44(%8)         \n"
                            :
                            : "f"(c), "f"(0.0f), "f"(-(s)), "r"(pi), "r"(&q150), "r"(&q160), "r"(&q140), "r"(D_00713D10), "r"(vertex)
                            : "$2", "$vf2", "$vf10", "$vf11", "$vf12", "$f0", "memory");
                        if (cur < sp110) {
                            fade = (f32)cur / (f32)sp110;
                        } else {
                            fade = 1.0f;
                            if (sp100 < cur) {
                                fade = (f32)(cnt4C - cur) / (f32)(cnt4C - sp100);
                            }
                        }
                        __asm__ volatile(
                            "lqc2 $vf11, 0(%0)        \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                            "lqc2 $vf10, 0(%2)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %3              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%4)             \n"
                            :
                            : "r"(D_00713CE0), "f"(fade), "r"(&colB), "f"(255.0f), "r"(&packA)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        color[0] = *(u32 *)&packA;
                        color[1] = *(u32 *)&packA;
                        __asm__ volatile(
                            "lqc2 $vf10, 0(%0)        \n"
                            "vmul.xyzw $vf10, $vf10, $vf11 \n"
                            "mfc1 $2, %1              \n"
                            "nop                      \n"
                            "qmtc2 $2, $vf2           \n"
                            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                            "vftoi0.xyzw $vf10, $vf10 \n"
                            "qmfc2 $2, $vf10          \n"
                            "ppach $2, $0, $2         \n"
                            "ppacb $2, $0, $2         \n"
                            "sw $2, 0(%2)             \n"
                            :
                            : "r"(&colA), "f"(255.0f), "r"(&packB)
                            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                        color[2] = *(u32 *)&packB;
                        color[3] = *(u32 *)&packB;
                        pi[0] = cur + spE0;
                    }
                }
                pi += 8;
                pif = (f32 *)pi;
                vertex += 12;
                color += 4;
                loop++;
            }
            {
                u8 *tail;
                tail = *(u8 **)(*(u8 **)(pu3 + 8) + 0x18);
                func_003c22f0(tail);
                if (*(u16 *)pu3 & 4) {
                    *(u16 *)(tail + 0xC) = *(u16 *)(tail + 0xC) | 1;
                }
            }
        }
    }
}

#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a0c00);
#endif
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
    f32 scale;

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
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp44 = temp_3;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
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
            : "r"(&sp44), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
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
