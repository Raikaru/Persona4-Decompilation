#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "model_matrix_internal.h"
#include "rw/ps2/ostypes.h"
#include "rw/plcore/barenderstate.h"

typedef struct RwMatrixTolerance {
    f32 Normal;
    f32 Orthogonal;
    f32 Identity;
} RwMatrixTolerance;

typedef struct RwV3d { f32 x; f32 y; f32 z; } Vec3;
typedef struct RwFrame RwFrame;
typedef struct RwCamera RwCamera;
typedef struct RpWorld RpWorld;
typedef struct RpLight RpLight;
typedef struct RwRGBAReal RwRGBAReal;
typedef struct RwMatrixTag RwMatrix;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;
typedef struct { f32 x; f32 y; f32 z; f32 w; } Vec4;

extern void func_00442088();
extern void func_00440b68(u8 *msg, u8 *file, s32 line);
extern s32 func_00454a60(char *path, s32 mode);
extern s32 func_004553c0(s32 handle);
extern u8 *func_00460f80(u8 *list, s32 arg1);
extern u8 *func_00461080(u8 *list, s32 arg1);
extern u8 *func_00461180(u8 *list, s32 arg1);
extern u8 *func_003e9d50(u8 *arg0);
extern void func_00152170(u8 *arg0, u8 *arg1);
extern s32 func_004581a0(void *object, const char *name);
extern void func_00458430(s32 *out, void *object, const char *name, s32 index);
extern void func_0046d730(const char *file, s32 line);
extern void func_004b1290(s32 a0, f32 f12, f32 f13, f32 f14);
extern void func_003c9d40(void *arg0);
extern void func_003c0700(void *arg0);
extern void func_00462bf0(void *arg0);
extern void func_004787e0(s32 arg0);
extern void func_004b1150(s32 arg0);
extern void func_003bbb60(void *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_00460e80(u8 *list, s32 arg1);
extern u8 *func_00461290(u8 *list, s32 arg1);
extern s32 func_00457120(void);
extern s32 func_00457190(void);
extern s32 func_004571a0(void);
extern s32 func_004571b0(void);
extern s32 func_004571c0(void);
extern u32 func_003e8110(u32 camera);
extern u32 func_003e8120(u32 camera);
extern RpWorld *func_003cbf30(RpWorld *world, RpLight *light);
extern RpWorld *func_003cbe80(RpWorld *world, RpLight *light);
extern s32 func_003cbc60(s32 world, u8 *camera);
extern RpWorld *func_003cbc10(RpWorld *world, RwCamera *camera);
extern RpLight *func_003c38b0(RpLight *light, const RwRGBAReal *color);
extern RwFrame *func_003e9cb0(RwFrame *frame, const RwMatrix *transform, RwOpCombineType combine);
extern s32 func_004782b0(u32 arg0);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern RwMatrix *func_003e9700(RwFrame *frame);
extern void func_00463250(void *arg0);
extern s32 func_004b1130(s32 a0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_00455f70(void *arg0, s32 *arg1);
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void func_003e2e40(s32 arg0, s32 arg1);
extern s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003dc370(void *arg0);
extern void func_003ef260(s32 arg0, void (*arg1)(void), void *arg2);
extern void func_003ef1b0(s32 arg0);
extern void func_00463100();
extern RwBool (*D_00887300[])(RwRenderState state, void *value);
extern u8 *func_00149ca0(void);
extern u8 *func_00149ce0(void);
extern u8 *func_00149d20(void);
extern RwBool func_003f6440(s32 state, void *payload);
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 *func_004669d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_00457ce0(u8 *arg0, char *arg1);
extern s32 func_00457c90(u8 *arg0, char *arg1);
extern void *func_00462ae0(void *arg0);
extern void func_003db550(u8 *arg0, u8 *arg1);
extern char D_005EFCE0[];
extern char D_005EFD00[];
extern char D_005EFD80[];
extern char D_005EFD98[];
extern char D_005EFDA8[];
extern char D_005EFDB8[];
extern char D_005EFDC8[];
extern char D_005EFDD8[];
extern char D_005EFDE8[];
extern char D_005EFE00[];
extern char D_005EFE10[];
extern char iGpffff9e10;
extern void func_00442428(char *dst, char *src);
extern s32 func_00477e80(s32 arg0, u16 arg1, char *arg2, s32 arg3);
extern s32 func_00477f10(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0014a230(s32 a0, s32 a1);
extern s32 func_0014a2a0(s32 a0, s32 a1);
extern u8 *func_0015c640(s32 a0, s32 a1);
extern u8 *func_00155280(void);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_0043c6b0(const char *arg0);
extern void func_00442830(char *dst, char *src);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 D_00754D88[];
extern s32 func_0044ec30(void);
extern s32 func_003c0520(s32 arg0);
extern s32 func_00478750(s32 arg0);
extern s32 func_004b11b0(s32 arg0);
extern void func_004b1250(void *effect, f32 *position);
extern RwBool func_003e0380(RwMatrixTolerance *tolerance);
extern RwMatrix *func_003e03e0(RwMatrix *matrix, const RwMatrixTolerance *tolerance);
extern RwFrame *func_003e9680(RwFrame *frame);
extern RwMatrix *func_003e0f80(void);
extern RwBool func_003e0f40(RwMatrix *matrix);
extern RwMatrix *func_003e0870(RwMatrix *matrix, const Vec3 *axis, f32 angle, RwOpCombineType combine);
extern Vec3 *func_003e42a0(Vec3 *pointOut, const Vec3 *pointIn, const RwMatrix *matrix);
extern RwMatrix *func_0047a180(RwMatrix *matrix, const Vec3 *translation, s32 combine);
extern s64 D_005EFE28[];
extern f32 D_005EFE30[];
extern u8 *iGpffff9db0;
extern void func_00454bd0(void *ptr);
extern u8 D_005EFD20[];
extern u8 D_005EFD40[];
extern u8 D_005EFD60[];
extern s64 D_005EFE38[];
extern f32 D_005EFE40[];
extern char D_005EFC60[];
extern u8 D_005EFC80[];
extern s32 iGpffffb200;   /* gp - 0x4E00 = 0x007642F0 */
extern s32 iGpffffb204;   /* gp - 0x4DFC = 0x007642F4 */
extern u8 iGpffff9df0;    /* gp - 0x6210 = 0x00762EE0 */
extern char D_005EFC90[];
extern u8 D_005F0590[];
extern u8 D_005F0591[];
extern u8 D_005F05B8[];
extern s32 D_007E8060[];
extern s32 iGpffffb208;   /* gp - 0x4DF8 = 0x007642F8 */


// FUN_0014EED0
void func_0014eed0(s32 arg0, s32 arg1)
{
    char path[0x40];

    if (iGpffffb200 == 0) {
        func_00442088(path, D_005EFC60, (u16)arg0, (u16)arg1);
        func_00440b68(&iGpffff9df0, D_005EFC80, 0x9E);
        iGpffffb200 = func_00454a60(path, 1);
    }
}

// FUN_0014EF40
s32 func_0014ef40(void)
{
    if (iGpffffb200 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb200) != 0;
}

// FUN_0014EF80
s32 func_0014ef80(void)
{
    if (iGpffffb204 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb204) != 0;
}

/* measured floor: 127 differing words (reloc-masked), obj 824B vs 848B window, verify normalized_diff 366.
 * Baseline C without pragma: 132 words, 828B. With #pragma opt_loop_invariants on before the second for loop:
 * 132 -> 127 words, 828B -> 824B. Genuinely OFF at baseline -O2, so real switch, not no-op.
 * Second lever (cast-at-call-site argument reorder) tested 2026-09-17 via probe_variants on this function:
 * s16 copies passed bare at both func_00442088 sites (delete (s16) casts) -> 127 vs base 127, no-op.
 * Expected: no trailing lw $t0 + nested-result daddu block exists here (args are regs/stack addiu), so no
 * reorder to fix. u16/u8 locals variant fails to compile. schedule-off / staging-temp not retried per wall
 * note (measured 2->120 / 80 elsewhere). K&R redeclaration / fifth-param-width variants not retried (no-ops).
 * Prologue/stack already match (0xD0 frame, 4 s-regs, args in s3/s2, var17/var16 in s1/s0).
 * Path1 table lookup (D_005F0591[D_005F0590[var17&0xFFFF]*12]) matches instruction-for-instruction.
 * Remaining walls: Path2 second base CSE (ours keeps D_005F0590 base in $a0 and reuses, retail reloads via $v0;
 * 5-word branch displacement shift at 0x112 from the 20B shortfall), first loop needs retail's hoisted
 * D_005F05B8+var17 preheader ($a3) with lbu -0x28($a3) and lb 2($v1) form (ours folds +2 into addiu and
 * uses lb 0), second loop needs hoisted D_007E8060 base in $a1 (ours rematerialises inside). Daddu home-move
 * order left as-is per wall note (invariant under declaration/initialiser/assignment/K&R models).
 * 2026-09-17 fnalign re-measure (base): retail 210 instrs vs object 206 instrs (4 short) + tail cascade,
 * edit 44 (+29 reloc-only), probe 127 words; confirms scan (second-strongest, 4-short/44-edit).
 * Shape B at flag-chain end (`else if (var16 < 0x100)` + dead `else {*(0x24) = 0;}`): 127->134 words (+7),
 * 44->51 edits (+7), 206->212 object instrs (212/212, 0 short) with object-only `slti $at,$s0,0x100` /
 * `sw $zero` plus extra `b` cascade and no retail counterpart; regresses, not adopted.
 * Shape A (`<= 0xFF` vs `< 0x100`): 134->134 (0, inert); no retail slti-$at row to fix (baseline 0 slti,
 * only `slt $2,$7,$2` register form, B1 slti is object-only), so lever has no target; not adopted.
 * Honest floor stays base (824B/848B, 2.83% short, within size gate, no SIZE_MISMATCH).
 * Guards as NONMATCHING with ASM fallback so verify stays 0 MISMATCH. */
/* measured 0014efc0: `opt_common_subs off` inside the guard is worth 21 words (127 -> 106); retail rematerialises what b210 hoists. */
// FUN_0014EFC0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_0014efc0(s32 arg0, s32 arg1)
{
    char sp90[0x40];
    char sp50[0x40];
    s32 var17;
    s32 var16;
    *(s32 *)(iGpffff9db0 + 0x24) = 0;
    *(s32 *)(iGpffff9db0 + 0x94) = 0;
    func_0043f9c8(iGpffff9db0 + 0x9C, 0, 0x40);
    if (func_0014a230(arg0, arg1) || func_0014a2a0(arg0, arg1)) {
        if (func_0014a2a0(arg0, arg1)) {
            var17 = ((arg0 & 0xFFFF) - 0x14) & 0xFFFF;
            *(s32 *)(iGpffff9db0 + 0x88) |= 0x80000000;
            var16 = (s32)func_0015c640(arg0, arg1);
            *(s32 *)(func_00155280() + 0x1864) = var16;
            var16 = D_005F0591[D_005F0590[var17 & 0xFFFF] * 12];
        } else {
            var17 = arg0 & 0xFFFF;
            var16 = D_005F0590[D_005F0590[var17] * 12];
        }
        if (*(s32 *)(iGpffff9db0 + 0x88) & 0x80000000) {
            if (iGpffffb204 == 0) {
                func_00442088(sp90, D_005EFC90, (s16)arg0, (s16)arg1);
                func_00440b68(&iGpffff9df0, D_005EFC80, 0xC9);
                iGpffffb204 = func_00454a60(sp90, 1);
            }
            {
                s32 i = var16 - 1;
                for (; i >= 0; i--) {
                    *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9C) = (s16)var17;
                    *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9E) = ((s8 *)D_005F0590)[D_005F0590[var17] * 12 + i + 2];
                    *(s32 *)(iGpffff9db0 + 0x98) += 1;
                }
            }
        } else {
            *(s32 *)(iGpffff9db0 + 0x24) = var16;
            {
                s32 i = 0;
#pragma opt_loop_invariants on
                for (; i < *(s32 *)(iGpffff9db0 + 0x24); i++) {
                    *(s32 *)(iGpffff9db0 + i * 4 + 0x28) = D_007E8060[i];
                }
            }
            *(s32 *)(iGpffff9db0 + 0x94) = 4;
        }
    } else {
        if (iGpffffb204 == 0) {
            func_00442088(sp50, D_005EFC90, (s16)arg0, (s16)arg1);
            func_00440b68(&iGpffff9df0, D_005EFC80, 0xC9);
            iGpffffb204 = func_00454a60(sp50, 1);
        }
        *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9C) = (s16)arg0;
        *(s16 *)(iGpffff9db0 + *(s32 *)(iGpffff9db0 + 0x98) * 4 + 0x9E) = (s16)arg1;
        *(s32 *)(iGpffff9db0 + 0x98) += 1;
    }
    iGpffffb208 = func_0044ec30();
}
#pragma opt_loop_invariants off
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014efc0);
#endif
/* measured 0014f310: opt_level 1 gives object 1346 vs retail 1374 (-28, -2.0%, inside 1333-1415 gate, 590 edits +73 reloc-only, max pure delete 9/insert 1). Switch 999/0x29/0x28/0x20 dispatch (jump-table vs beq-chain replace 32 vs 2, not hole/lump), frame -0x2B0 exact, 117 calls, lhu/lbu direct, float returns direct, u16 loads direct. Production stays ASM. */
// FUN_0014F310 NONMATCHING
#ifdef NON_MATCHING
#pragma optimization_level 1
s32 func_0014f310(s32 arg0, s32 arg1) {
    extern void *func_00150890(s16 arg0, s16 arg1);
    extern s32 func_00150c80(u8 *arg0);
    extern void func_00150ce0(u8 *arg0);
    extern s32 func_001510c0(u8 *arg0);
    extern void func_00151710(u8 *arg0);
    extern s32 func_00151c80(u8 *arg0);
    extern f32 func_0014b660(u8 *arg0);
    extern f32 func_0014b5d0(u8 *arg0);
    extern f32 func_0014b6f0(u8 *arg0);
    extern void func_00146e60(s32 arg0, u8 *arg1, f32 *arg2);
    extern s32 func_0014a270(void);
    extern s32 func_0014a200(void);
    extern void func_00149ea0(u8 *arg0);
    extern void func_0014a000(s32 arg0, s32 arg1);
    extern s32 func_00153c00(s32 arg0);
    extern s32 func_00153d60(u8 *arg0, s32 arg1);
    extern s32 func_00154b10(void);
    extern s32 func_00154be0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, s32 *arg4, u8 *arg5, f32 *arg6, f32 *arg7, s32 *arg_sp0, s32 *arg_sp8);
    extern s32 func_00146440(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4, s32 *arg5, s32 *arg6, f32 fparg0, f32 fparg1, f32 fparg2);
    extern u8 *func_001452b0(s32 arg0);
    extern u8 *func_00145270(s32 arg0);
    extern void func_00146630(u16 arg0);
    extern s32 func_00145ac0(u16 arg0, s32 arg1);
    extern s32 func_00145ba0(u16 arg0, s32 arg1);
    extern s32 func_00145c80(s32 arg0, u8 *arg1);
    extern u8 *func_0015f8e0(s32 arg0, s32 arg1);
    extern s32 func_0015f9b0(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3);
    extern void func_0015fb00(u8 *arg0, s32 arg1);
    extern u8 *func_0015e870(s32 arg0, s32 arg1, s16 arg2);
    extern s32 func_0015e960(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_0015f000(u8 *arg0, u8 *arg1);
    extern s32 func_0015c6f0(u8 *arg0);
    extern void func_0015c730(u8 *arg0);
    extern s32 func_0015c750(void);
    extern s32 func_0015c800(s32 arg0);
    extern s32 func_0015ccc0(void);
    extern s32 func_0015cd70(s32 arg0);
    extern s32 func_0015a160(void);
    extern s32 func_0015ac60(s32 arg0);
    extern s32 func_0015a7c0(s32 arg0);
    extern void func_001599d0(void);
    extern void func_0015b240(void);
    extern void func_001582f0(s32 arg0, s32 arg1, s32 arg2);
    extern void *func_0047a310(s32 arg0);
    extern s32 func_0018c6c0(u8 *arg0, s32 arg1);
    extern s32 func_003ef6d0(void);
    extern s32 func_003ef650(s32 arg0, u8 *arg1);
    extern void func_0043f810(void *dst, const void *src, s32 size);
    extern u8 *func_003e9700(u8 *arg0);
    extern u8 *func_003e8180(u8 *arg0, f32 arg1);
    extern s32 D_007D24E0;
    extern s32 D_007D24E8;
    extern u8 D_005EFCB0[];
    u8 *sp2AC;
    f32 sp2A8;
    s32 sp2A4;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    u8 sp280[0x10];
    u8 sp240[0x40];
    u8 sp200[0x40];
    u8 sp1E0[0x20];
    u8 sp60[0x180];
    s32 temp_16_12;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_6;
    s32 temp_16_7;
    s32 temp_16_8;
    s32 temp_16_9;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_19;
    s32 temp_3;
    s32 temp_3_10;
    s32 temp_4_5;
    s32 temp_7;
    s32 temp_7_2;
    s32 var_16;
    s32 var_16_10;
    s32 var_16_11;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_16_7;
    s32 var_16_8;
    s32 var_16_9;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_5;
    s32 var_17_6;
    s32 var_17_8;
    s32 var_17_9;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_18_5;
    s32 var_19;
    s32 var_19_2;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_9;
    s32 var_9_2;
    u16 temp_3_14;
    u32 var_17_3;
    u32 var_17_4;
    u8 temp_4_6;
    u8 temp_4_7;
    u8 *temp_16;
    u8 *temp_16_10;
    u8 *temp_16_11;
    u8 *temp_17_3;
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_3_11;
    u8 *temp_3_12;
    u8 *temp_3_13;
    u8 *temp_3_15;
    u8 *temp_3_16;
    u8 *temp_3_17;
    u8 *temp_3_18;
    u8 *temp_3_19;
    u8 *temp_3_20;
    u8 *temp_3_21;
    u8 *temp_3_22;
    u8 *temp_3_23;
    u8 *temp_3_24;
    u8 *temp_3_25;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_3_6;
    u8 *temp_3_7;
    u8 *temp_3_8;
    u8 *temp_3_9;
    u8 *temp_4;
    u8 *temp_4_10;
    u8 *temp_4_11;
    u8 *temp_4_12;
    u8 *temp_4_13;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_8;
    u8 *temp_8_2;
    u8 *var_17_7;
    u8 *var_18_4;

    temp_3 = (s32)(*( s32 * )(iGpffff9db0 + 0x94));
    switch (temp_3) {                               /* switch 1; irregular */
    default:                                        /* switch 1 */
        var_2 = 1;
        switch (temp_3) {                           /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            temp_4 = (u8 *)(iGpffffb200);
            if (temp_4 == NULL) {

            } else if (func_004553c0((s32)(temp_4)) != 0) {
                var_2 = 1;
            } else {
                var_2 = 0;
            }
            if (var_2 == 0) {
                return 0;
            }
            temp_4_2 = (u8 *)(iGpffffb204);
            if (temp_4_2 == NULL) {
                var_2_2 = 1;
            } else if (func_004553c0((s32)(temp_4_2)) != 0) {
                var_2_2 = 1;
            } else {
                var_2_2 = 0;
            }
            if (var_2_2 == 0) {
                return 0;
            }
            temp_3_2 = (u8 *)(iGpffff9db0);
            *( s32 * )(temp_3_2 + 0x98) = (s32) (*( s32 * )(temp_3_2 + 0x98) - 1);
            temp_16 = (u8 *)(iGpffff9db0);
            temp_2 = (u8 *)((*( s32 * )(temp_16 + 0x98) * 4) + temp_16);
            *( s32 * )(((*( s32 * )(temp_16 + 0x24) * 4) + temp_16) + 0x28) = (s32)func_00150890(*( s16 * )(temp_2 + 0x9C), *( s16 * )(temp_2 + 0x9E));
            *( s32 * )(iGpffff9db0 + 0x94) = 1;
        case 1:                                     /* switch 2 */
            temp_3_3 = (u8 *)(iGpffff9db0);
            if (func_00150c80(*( u8 ** )(((*( s32 * )(temp_3_3 + 0x24) * 4) + temp_3_3) + 0x28)) == 0) {
                return 0;
            }
            temp_3_4 = (u8 *)(iGpffff9db0);
            func_00150ce0((u8 *)(*( s8 ** )(((*( s32 * )(temp_3_4 + 0x24) * 4) + temp_3_4) + 0x28)));
            *( s32 * )(iGpffff9db0 + 0x94) = 2;
        case 0x2:                                   /* switch 1 */
            temp_3_5 = (u8 *)(iGpffff9db0);
            if (func_001510c0(*( u8 ** )(((*( s32 * )(temp_3_5 + 0x24) * 4) + temp_3_5) + 0x28)) == 0) {
                return 0;
            }
            temp_3_6 = (u8 *)(iGpffff9db0);
            *( s32 * )(temp_3_6 + 0x24) = (s32) (*( s32 * )(temp_3_6 + 0x24) + 1);
            temp_4_3 = (u8 *)(iGpffff9db0);
            if (*( s32 * )(temp_4_3 + 0x98) > 0) {
                *( s32 * )(temp_4_3 + 0x94) = 0;
                return 0;
            }
            if (*( s32 * )(temp_4_3 + 0xC) & 0x80000000) {
                *( s32 * )(temp_4_3 + 0) = (s32) *( s16 * )(*( u8 ** )(temp_4_3 + 0x28) + 4);
                temp_3_7 = (u8 *)(iGpffff9db0);
                *( s32 * )(temp_3_7 + 4) = (s32) *( s16 * )(*( u8 ** )(temp_3_7 + 0x28) + 6);
            }
            var_16 = 0;
loop_47:
            temp_3_8 = (u8 *)(iGpffff9db0);
            if (var_16 < *( s32 * )(temp_3_8 + 0x24)) {
                func_00151710(*( u8 ** )((temp_3_8 + (var_16 * 4)) + 0x28));
                var_16 += 1;
                goto loop_47;
            }
            *( s32 * )(temp_3_8 + 0x94) = 3;
        case 0x3:                                   /* switch 1 */
            var_17 = 0;
            var_16_2 = 0;
loop_53:
            temp_3_9 = (u8 *)(iGpffff9db0);
            if (var_16_2 < *( s32 * )(temp_3_9 + 0x24)) {
                if (func_00151c80(*( u8 ** )((temp_3_9 + (var_16_2 * 4)) + 0x28)) == 0) {
                    var_17 += 1;
                }
                var_16_2 += 1;
                goto loop_53;
            }
            if (var_17 != 0) {
                return 0;
            }
            temp_4_4 = (u8 *)(iGpffffb204);
            if (temp_4_4 != NULL) {
                func_00454bd0(temp_4_4);
                iGpffffb204 = 0;
            }
            temp_4_5 = (s32)(*( s32 * )(iGpffff9db0 + 0x8C));
            if (temp_4_5 != 0) {
                func_00463250((void *)(temp_4_5));
                *( s32 * )(iGpffff9db0 + 0x8C) = 0;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 4;
        case 0x4:                                   /* switch 1 */
            temp_3_10 = (s32)(func_0044ec30() - iGpffffb208);
            iGpffffb208 = temp_3_10;
            if (*( s32 * )(iGpffff9db0 + 0) < 0xC8) {
                iGpffffb208 = (s32) (temp_3_10 + 0x32000);
            }
            D_007D24E0 = func_0015c750();
            D_007D24E8 = func_0015ccc0();
            *( s32 * )(iGpffff9db0 + 0x94) = 5;
        case 0x5:                                   /* switch 1 */
            if (func_0015c800(D_007D24E0) == 0) {
                return 0;
            }
            D_007D24E0 = 0;
            if (func_0015cd70(D_007D24E8) == 0) {
                return 0;
            }
            D_007D24E8 = 0;
            *( s32 * )(iGpffff9db0 + 0x94) = 6;
        case 0x6:                                   /* switch 1 */
            *( s32 * )(iGpffff9db0 + 0x94) = 7;
        case 0x7:                                   /* switch 1 */
            var_16_3 = 0;
            if (func_0015c6f0((u8 *)(*( s32 * )(func_00155280() + 0x1864))) == 0) {
                var_16_3 = 1;
            }
            if (var_16_3 != 0) {
                return 0;
            }
            var_17_2 = 0;
loop_78:
            temp_3_11 = (u8 *)(iGpffff9db0);
            if (var_17_2 < *( s32 * )(temp_3_11 + 0x24)) {
                temp_16_2 = var_17_2 * 4;
                if (*( s32 * )(*( u8 ** )((temp_3_11 + temp_16_2) + 0x28) + 0xA40) == 0) {
                    temp_2_2 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_16_2) + 0x28));
                    *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_2) + 0x28) + 0xA3C) = (s32)func_0015f8e0(*( u16 * )(temp_2_2 + 4), *( u16 * )(temp_2_2 + 6));
                }
                var_17_2 += 1;
                goto loop_78;
            }
            if (func_0014a270() != 0) {
                temp_16_3 = (s32)(*( s32 * )(*( u8 ** )(func_00155280() + 0x1864) + 0x110));
                func_0043f810(func_00155280() + 0x54,(const void *)(temp_16_3 + 4), 0x1800);
                func_0015c730((u8 *)(*( s32 * )(func_00155280() + 0x1864)));
                var_18 = 0;
loop_88:
                if (var_18 < 0x18) {
                    var_19 = 0;
                    temp_17 = var_18 << 8;
loop_86:
                    if (var_19 >= 0x10) {
                        var_18 += 1;
                        goto loop_88;
                    }
                    temp_16_4 = var_19 * 0x10;
                    if ((*( u8 * )((temp_17 + func_00155280() + temp_16_4) + 0x54) == 1) && (*( u8 * )((temp_17 + func_00155280() + temp_16_4) + 0x58) == 6)) {
                        *( s8 * )(func_00155280() + 0x44) = (s8) (var_19 & 0xFF);
                        *( s8 * )(func_00155280() + 0x45) = (s8) (var_18 & 0xFF);
                    } else {
                        var_19 += 1;
                        goto loop_86;
                    }
                }
                var_19_2 = 0;
loop_99:
                if (var_19_2 < 0x18) {
                    var_18_2 = 0;
                    temp_17_2 = var_19_2 << 8;
loop_97:
                    if (var_18_2 >= 0x10) {
                        var_19_2 += 1;
                        goto loop_99;
                    }
                    temp_16_5 = var_18_2 * 0x10;
                    if ((*( u8 * )((temp_17_2 + func_00155280() + temp_16_5) + 0x54) == 1) && ((*( u8 * )((temp_17_2 + func_00155280() + temp_16_5) + 0x58) == 0xA) || (*( u8 * )((temp_17_2 + func_00155280() + temp_16_5) + 0x58) == 0xC) || (*( u8 * )((temp_17_2 + func_00155280() + temp_16_5) + 0x58) == 0xE))) {
                        *( s8 * )(func_00155280() + 0x46) = (s8) (var_18_2 & 0xFF);
                        *( s8 * )(func_00155280() + 0x47) = (s8) (var_19_2 & 0xFF);
                    } else {
                        var_18_2 += 1;
                        goto loop_97;
                    }
                }
                temp_2_3 = (u8 *)(iGpffff9db0);
                temp_16_6 = (s32)(func_0015f8e0(*( u16 * )(temp_2_3 + 0), *( u16 * )(temp_2_3 + 4)));
                *( s32 * )(func_00155280() + 0x1864) = temp_16_6;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 8;
        case 0x8:                                   /* switch 1 */
            if (func_0014a270() != 0) {
                sp2AC = NULL;
                var_16_4 = 0;
loop_107:
                if (var_16_4 >= *( s32 * )(iGpffff9db0 + 0x24)) {
                    var_16_5 = 0;
loop_110:
                    temp_17_3 = (u8 *)(iGpffff9db0);
                    if (var_16_5 < *( s32 * )(temp_17_3 + 0x24)) {
                        func_0015fb00((u8 *)(*( s8 ** )(*( u8 ** )((temp_17_3 + (var_16_5 * 4)) + 0x28) + 0xA40)), 0);
                        var_16_5 += 1;
                        goto loop_110;
                    }
                    if (func_0015f9b0((u8 *)(*( s32 * )(func_00155280() + 0x1864)),(u8 **)(&sp2AC), *( u16 * )(temp_17_3 + 0), *( u16 * )(temp_17_3 + 4)) == 0) {
                        return 0;
                    }
                    if (sp2AC != NULL) {
                        func_0015fb00((u8 *)(sp2AC), 1);
                        jtbl_008873EC[0](sp2AC);
                        *( s32 * )(func_00155280() + 0x1864) = 0;
                    }
                    goto block_123;
                }
                temp_17_4 = var_16_4 * 4;
                temp_2_4 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_17_4) + 0x28));
                if (func_0015f9b0((u8 *)(*( s32 * )(temp_2_4 + 0xA3C)),(u8 **)(temp_2_4 + 0xA40), *( u16 * )(temp_2_4 + 4), *( u16 * )(temp_2_4 + 6)) == 0) {
                    return 0;
                }
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_4) + 0x28) + 0xA3C) = 0;
                var_16_4 += 1;
                goto loop_107;
            }
            var_16_6 = 0;
loop_119:
            if (var_16_6 >= *( s32 * )(iGpffff9db0 + 0x24)) {
                var_16_7 = 0;
loop_122:
                temp_3_12 = (u8 *)(iGpffff9db0);
                if (var_16_7 < *( s32 * )(temp_3_12 + 0x24)) {
                    func_0015fb00((u8 *)(*( s8 ** )(*( u8 ** )((temp_3_12 + (var_16_7 * 4)) + 0x28) + 0xA40)), 0);
                    var_16_7 += 1;
                    goto loop_122;
                }
block_123:
                if (func_0014a200() == 1) {
                    var_9 = 0;
                    temp_8 = (u8 *)(iGpffff9db0);
loop_126:
                    temp_4_6 = (u8)(*( u8 * )(((s32)D_005F05B8 + *( s32 * )(temp_8 + 0)) + -0x28));
                    if (var_9 < (s32) *((u8 *)(D_005F0590 + (temp_4_6 * 0xC)))) {
                        temp_7 = var_9 * 4;
                        *((u8 *)((s32)D_007E8060 + temp_7)) = *( s32 * )((temp_8 + temp_7) + 0x28);
                        var_9 += 1;
                        goto loop_126;
                    }
                    if (func_0015ac60(func_0015a160()) == 0) {
                        func_001582f0(*( s32 * )(iGpffff9db0 + 0) - 0x28, *( s32 * )(func_00155280() + 0x4C), 1);
                        func_0015a7c0(func_0015a160());
                    }
                    func_001599d0();
                    func_0015b240();
                } else if (func_0014a270() != 0) {
                    var_9_2 = 0;
                    temp_8_2 = (u8 *)(iGpffff9db0);
loop_133:
                    temp_4_7 = (u8)(*( u8 * )(((s32)D_005F05B8 + *( s32 * )(temp_8_2 + 0)) + -0x3C));
                    if (var_9_2 < (s32) *( u8 * )(((s32)D_005F0590 + (temp_4_7 * 0xC)) + 1)) {
                        temp_7_2 = var_9_2 * 4;
                        *((u8 *)((s32)D_007E8060 + temp_7_2)) = *( s32 * )((temp_8_2 + temp_7_2) + 0x28);
                        var_9_2 += 1;
                        goto loop_133;
                    }
                    if (func_0015ac60(func_0015a160()) == 0) {
                        func_0015a7c0(func_0015a160());
                    }
                    func_001599d0();
                    func_0015b240();
                } else {
                    func_00145c80(0, *( u8 ** )(iGpffff9db0 + 0x28));
                    var_17_3 = 0;
loop_150:
                    temp_3_13 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                    if (var_17_3 < (u32) *( u32 * )(temp_3_13 + 0x11C)) {
                        temp_16_7 = var_17_3 * 0x18;
                        temp_18 = (u8 *)(func_003e9700(*( u8 ** )((temp_3_13 + temp_16_7) + 0x128)));
                        temp_3_14 = (u16)(*( u16 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x120));
                        if ((temp_3_14 == 0) || (temp_3_14 == 2)) {
                            temp_2_5 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28) + (var_17_3 * 0x18));
                            temp_19 = (s32)(func_00145ac0(*( u16 * )(temp_2_5 + 0x124), *( s32 * )(temp_2_5 + 0x12C)) & 0xFFFF);
                            if (temp_19 == 0) {
                                func_0046d730((const char *)D_005EFC80, 0x297);
                            }
                            sp290 = func_0014b660(temp_18);
                            sp294 = func_0014b5d0(temp_18);
                            sp298 = func_0014b6f0(temp_18);
                            func_00146e60(temp_19, temp_18 + 0x30, &sp290);
                            temp_4_8 = (u8 *)(iGpffff9db0);
                            if ((*( s32 * )(temp_4_8 + 0) != 0x14) || (*( s32 * )(temp_4_8 + 4) != 1)) {
                                temp_18_2 = (s32)(func_0047a310(*( s32 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x12C)));
                                if (func_0018c6c0((u8 *)(temp_18_2), func_003ef650(func_003ef6d0(), D_005EFCB0)) == 1) {
                                    temp_2_6 = (u8 *)(func_00145270(temp_19));
                                    *( s32 * )(temp_2_6 + 0x28) = (s32) (*( s32 * )(temp_2_6 + 0x28) | 0x01000000);
                                }
                            }
                            if (*( u16 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x122) & 2) {
                                *( s32 * )(func_00145270(temp_19) + 0x150) = 1;
                            }
                            *( s32 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_7) + 0x12C) = 0;
                        }
                        var_17_3 += 1;
                        goto loop_150;
                    }
                    var_17_4 = 0;
loop_157:
                    temp_4_9 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                    if (var_17_4 < (u32) *( u32 * )(temp_4_9 + 0x11C)) {
                        temp_16_8 = var_17_4 * 0x18;
                        func_003e9700(*( u8 ** )((temp_4_9 + temp_16_8) + 0x128));
                        temp_4_10 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                        if (*( u16 * )((temp_4_10 + temp_16_8) + 0x120) == 1) {
                            temp_2_7 = (u8 *)(temp_4_10 + (var_17_4 * 0x18));
                            temp_18_3 = (s32)(func_00145ba0(*( u16 * )(temp_2_7 + 0x124), *( s32 * )(temp_2_7 + 0x130)) & 0xFFFF);
                            if (temp_18_3 == 0) {
                                func_0046d730((const char *)D_005EFC80, 0x2C7);
                            }
                            *( s32 * )((*( u8 ** )(iGpffff9db0 + 0x28) + temp_16_8) + 0x130) = 0;
                            temp_2_8 = (u8 *)(func_00145270(temp_18_3));
                            *( s32 * )(temp_2_8 + 0x28) = (s32) (*( s32 * )(temp_2_8 + 0x28) | 2);
                        }
                        var_17_4 += 1;
                        goto loop_157;
                    }
                    *( u32 * )(temp_4_9 + 0x11C) = 0U;
                    func_00149ea0(temp_4_9);
                    func_0014a000(1, 1);
                }
                *( s32 * )(iGpffff9db0 + 0xDC) = func_00153c00(*( s16 * )(iGpffff9db0 + 0x12));
                if (*( s32 * )(iGpffff9db0 + 0) >= 0xC8) {
                    func_003e8180((void *)(u32)func_00457120(), 100.0f);
                }
                if (*( s32 * )(iGpffff9db0 + 0) < 0xC8) {
                    func_003e8180((void *)(u32)func_00457120(), 100.0f);
                }
                temp_3_15 = (u8 *)(iGpffff9db0);
                if (*( s32 * )(temp_3_15 + 0xDC) == 0) {
                    *( s32 * )(iGpffff9db0 + 0xDC) = func_00154b10();
                    temp_3_16 = (u8 *)(iGpffff9db0);
                    if (*( s32 * )(temp_3_16 + 0xDC) != 0) {
                        *( s32 * )(temp_3_16 + 0x94) = 0xA;
                    } else {
                        *( s32 * )(temp_3_16 + 0x94) = 0xB;
                    }
                    goto block_259;
                }
                *( s32 * )(temp_3_15 + 0x94) = 9;
            case 0x9:                               /* switch 1 */
                temp_2_9 = (u8 *)(iGpffff9db0);
                if (func_00153d60((u8 *)(*( s32 * )(temp_2_9 + 0xDC)), *( s16 * )(temp_2_9 + 0x12)) != 0) {
                    *( s32 * )(iGpffff9db0 + 0xDC) = func_00154b10();
                    temp_3_17 = (u8 *)(iGpffff9db0);
                    if (*( s32 * )(temp_3_17 + 0xDC) != 0) {
                        *( s32 * )(temp_3_17 + 0x94) = 0xA;
                    case 0xA:                       /* switch 1 */
                        if (func_00154be0((u8 *)(*( s32 * )(iGpffff9db0 + 0xDC)), sp240, sp200, &sp2A8, &sp2A4, sp280, &sp2A0, &sp29C, (s32 *)sp1E0, (s32 *)sp60) != 0) {
                            func_00146440(0, sp2A4, sp240, sp200, sp280, (s32 *)sp1E0, (s32 *)sp60, sp2A8, sp2A0, sp29C);
                            *( s32 * )(iGpffff9db0 + 0x94) = 0xB;
                            goto block_259;
                        }
                        return 0;
                    }
                    *( s32 * )(temp_3_17 + 0x94) = 0xB;
block_259:
                    return 0;
                }
                return 0;
            }
            temp_17_5 = var_16_6 * 4;
            temp_2_10 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_17_5) + 0x28));
            if (func_0015f9b0((u8 *)(*( s32 * )(temp_2_10 + 0xA3C)),(u8 **)(temp_2_10 + 0xA40), *( u16 * )(temp_2_10 + 4), *( u16 * )(temp_2_10 + 6)) == 0) {
                return 0;
            }
            *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_5) + 0x28) + 0xA3C) = 0;
            var_16_6 += 1;
            goto loop_119;
        }
        break;
    case 0xB:                                       /* switch 1 */
        if (func_0014a270() == 1) {
            temp_2_11 = (u8 *)(iGpffff9db0);
            *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_11 + 0), *( u16 * )(temp_2_11 + 4), *( s16 * )(temp_2_11 + 0x10));
        } else {
            var_16_8 = 0;
loop_180:
            if (var_16_8 < *( s32 * )(iGpffff9db0 + 0x24)) {
                temp_3_18 = (u8 *)(iGpffff9db0);
                temp_17_6 = var_16_8 * 4;
                temp_2_12 = (u8 *)(*( u8 ** )((temp_3_18 + temp_17_6) + 0x28));
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_6) + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_12 + 4), *( u16 * )(temp_2_12 + 6), *( s16 * )(temp_3_18 + 0x10));
                var_16_8 += 1;
                goto loop_180;
            }
        }
        *( s32 * )(iGpffff9db0 + 0x94) = 0xC;
        /* fallthrough */
    case 0xC:                                       /* switch 1 */
        var_16_9 = 0;
        if (func_0014a270() == 1) {
            temp_3_19 = (u8 *)(iGpffff9db0);
            temp_2_13 = (u8 *)(*( u8 ** )(temp_3_19 + 0x28));
            if (func_0015e960((u8 *)(*( s32 * )(temp_2_13 + 0xA48)), temp_2_13 + 0xA4C, *( u16 * )(temp_3_19 + 0), *( u16 * )(temp_3_19 + 4), *( s16 * )(temp_3_19 + 0x10)) == 0) {
                var_16_9 = 1;
            }
        } else {
            var_17_5 = 0;
loop_189:
            if (var_17_5 < *( s32 * )(iGpffff9db0 + 0x24)) {
                temp_3_20 = (u8 *)(iGpffff9db0);
                temp_2_14 = (u8 *)(*( u8 ** )((temp_3_20 + (var_17_5 * 4)) + 0x28));
                if (func_0015e960((u8 *)(*( s32 * )(temp_2_14 + 0xA48)), temp_2_14 + 0xA4C, *( u16 * )(temp_2_14 + 4), *( u16 * )(temp_2_14 + 6), *( s16 * )(temp_3_20 + 0x10)) == 0) {
                    var_16_9 += 1;
                }
                var_17_5 += 1;
                goto loop_189;
            }
        }
        if (var_16_9 != 0) {
            return 0;
        }
        *( s32 * )(iGpffff9db0 + 0x94) = 0xD;
    case 0xD:                                       /* switch 1 */
        var_17_6 = 0;
        var_18_3 = 0;
loop_198:
        temp_3_21 = (u8 *)(iGpffff9db0);
        if (var_18_3 < *( s32 * )(temp_3_21 + 0x24)) {
            temp_16_9 = var_18_3 * 4;
            temp_2_15 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_16_9) + 0x28));
            if (func_0015f000((u8 *)(*( s32 * )(temp_2_15 + 0xA48)),(u8 *)(*( s32 * )(temp_2_15 + 0xA4C))) == 0) {
                var_17_6 += 1;
            } else {
                *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_9) + 0x28) + 0xA48) = 0;
            }
            var_18_3 += 1;
            goto loop_198;
        }
        if (var_17_6 != 0) {
            return 0;
        }
        *( s32 * )(temp_3_21 + 0x94) = 0x3E7;
        goto block_259;
    case 0x1E:                                      /* switch 1 */
        var_18_4 = (u8 *)(func_001452b0(3));
        var_17_7 = (u8 *)(func_001452b0(8));
        temp_4_11 = (u8 *)(iGpffffb200);
        if (temp_4_11 == NULL) {
            var_2_3 = 1;
        } else if (func_004553c0((s32)(temp_4_11)) != 0) {
            var_2_3 = 1;
        } else {
            var_2_3 = 0;
        }
        if (var_2_3 != 0) {
loop_210:
            if (var_18_4 != NULL) {
                temp_16_10 = (u8 *)(*( u8 ** )(var_18_4 + 0x138));
                func_00146630(*( u16 * )(var_18_4 + 0));
                var_18_4 = (u8 *)(temp_16_10);
                goto loop_210;
            }
loop_213:
            if (var_17_7 != NULL) {
                temp_16_11 = (u8 *)(*( u8 ** )(var_17_7 + 0x138));
                func_00146630(*( u16 * )(var_17_7 + 0));
                var_17_7 = (u8 *)(temp_16_11);
                goto loop_213;
            }
            if (func_0014a270() == 1) {
                temp_2_16 = (u8 *)(iGpffff9db0);
                *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_16 + 0), *( u16 * )(temp_2_16 + 4), *( s16 * )(temp_2_16 + 0x10));
            } else {
                var_16_10 = 0;
loop_218:
                if (var_16_10 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_3_22 = (u8 *)(iGpffff9db0);
                    temp_17_7 = var_16_10 * 4;
                    temp_2_17 = (u8 *)(*( u8 ** )((temp_3_22 + temp_17_7) + 0x28));
                    *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_17_7) + 0x28) + 0xA48) = (s32)func_0015e870(*( u16 * )(temp_2_17 + 4), *( u16 * )(temp_2_17 + 6), *( s16 * )(temp_3_22 + 0x10));
                    var_16_10 += 1;
                    goto loop_218;
                }
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 0x1F;
        case 0x1F:                                  /* switch 1 */
            var_16_11 = 0;
            if (func_0014a270() == 1) {
                temp_3_23 = (u8 *)(iGpffff9db0);
                temp_2_18 = (u8 *)(*( u8 ** )(temp_3_23 + 0x28));
                if (func_0015e960((u8 *)(*( s32 * )(temp_2_18 + 0xA48)), temp_2_18 + 0xA4C, *( u16 * )(temp_3_23 + 0), *( u16 * )(temp_3_23 + 4), *( s16 * )(temp_3_23 + 0x10)) == 0) {
                    var_16_11 = 1;
                }
            } else {
                var_17_8 = 0;
loop_227:
                if (var_17_8 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_3_24 = (u8 *)(iGpffff9db0);
                    temp_2_19 = (u8 *)(*( u8 ** )((temp_3_24 + (var_17_8 * 4)) + 0x28));
                    if (func_0015e960((u8 *)(*( s32 * )(temp_2_19 + 0xA48)), temp_2_19 + 0xA4C, *( u16 * )(temp_2_19 + 4), *( u16 * )(temp_2_19 + 6), *( s16 * )(temp_3_24 + 0x10)) == 0) {
                        var_16_11 += 1;
                    }
                    var_17_8 += 1;
                    goto loop_227;
                }
            }
            if (var_16_11 != 0) {
                return 0;
            }
            *( s32 * )(iGpffff9db0 + 0x94) = 0x20;
        case 0x20:                                  /* switch 1 */
            var_17_9 = 0;
            if (func_0014a270() == 1) {
                temp_2_20 = (u8 *)(*( u8 ** )(iGpffff9db0 + 0x28));
                if (func_0015f000((u8 *)(*( s32 * )(temp_2_20 + 0xA48)),(u8 *)(*( s32 * )(temp_2_20 + 0xA4C))) == 0) {
                    var_17_9 = 1;
                } else {
                    *( s32 * )(*( u8 ** )(iGpffff9db0 + 0x28) + 0xA48) = 0;
                }
            } else {
                var_18_5 = 0;
loop_240:
                if (var_18_5 < *( s32 * )(iGpffff9db0 + 0x24)) {
                    temp_16_12 = var_18_5 * 4;
                    temp_2_21 = (u8 *)(*( u8 ** )((iGpffff9db0 + temp_16_12) + 0x28));
                    if (func_0015f000((u8 *)(*( s32 * )(temp_2_21 + 0xA48)),(u8 *)(*( s32 * )(temp_2_21 + 0xA4C))) == 0) {
                        var_17_9 += 1;
                    } else {
                        *( s32 * )(*( u8 ** )((iGpffff9db0 + temp_16_12) + 0x28) + 0xA48) = 0;
                    }
                    var_18_5 += 1;
                    goto loop_240;
                }
            }
            if (var_17_9 != 0) {
                return 0;
            }
            temp_3_25 = (u8 *)(iGpffff9db0);
            if (*( s32 * )(temp_3_25 + 0xC) & 4) {
                *( s32 * )(temp_3_25 + 0x94) = 0x28;
            case 0x28:                              /* switch 1 */
                temp_4_12 = (u8 *)(iGpffffb200);
                if (temp_4_12 == NULL) {
                    var_2_4 = 1;
                } else if (func_004553c0((s32)(temp_4_12)) != 0) {
                    var_2_4 = 1;
                } else {
                    var_2_4 = 0;
                }
                if (var_2_4 != 0) {
                    *( s32 * )(iGpffff9db0 + 0xDC) = func_00153c00(*( s16 * )(iGpffff9db0 + 0x12));
                    *( s32 * )(iGpffff9db0 + 0x94) = 0x29;
                case 0x29:                          /* switch 1 */
                    temp_2_22 = (u8 *)(iGpffff9db0);
                    if (func_00153d60((u8 *)(*( s32 * )(temp_2_22 + 0xDC)), *( s16 * )(temp_2_22 + 0x12)) != 0) {
                        *( s32 * )(iGpffff9db0 + 0x94) = 0x3E7;
                        goto block_259;
                    }
                    return 0;
                }
                goto block_259;
            }
            *( s32 * )(temp_3_25 + 0x94) = 0x3E7;
            goto block_259;
        }
        goto block_259;
    case 0x3E7:                                     /* switch 1 */
        temp_4_13 = (u8 *)(iGpffffb200);
        if (temp_4_13 != NULL) {
            func_00454bd0(temp_4_13);
            iGpffffb200 = 0;
        }
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014f310);
#endif
/* measured: opt_loop_invariants hoists the slash loop constant. */
#pragma push
#pragma opt_loop_invariants on

// FUN_00150970
u8 *func_00150970(char *arg0)
{
    u32 base;
    u8 *resource;
    u8 *work;
    s32 valid = 1;
    struct {
        char token[4];
        char pad[4];
    } local;

    func_0044ea90(D_005EFC80, 0x460);
    base = (u32)D_008873F4;
    resource = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0xAB0, 0x40000);
    if (resource == NULL) {
        return resource;
    }
    func_0044ea90(D_005EFC80, 0x462);
    work = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(valid, 0x12C, 0x40000);
    *(u8 **)(resource + 0xA44) = work;
    if (work == NULL) {
        jtbl_008873EC[0](resource);
        return NULL;
    }
    func_00442830((char *)work, arg0);
    while (*arg0 != '\0') {
        arg0++;
    }
    for (; *arg0 != '/'; arg0--) {
    }
    if (arg0[1] == 'f') {
        if ((D_00754D88[(s8)arg0[2]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[3]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[4]] & 4) == 0) {
            valid = 0;
        }
        if (arg0[5] != '_') {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[6]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[7]] & 4) == 0) {
            valid = 0;
        }
        if ((D_00754D88[(s8)arg0[8]] & 4) == 0) {
            valid = 0;
        }
    } else {
        valid = 0;
    }
    if (valid) {
        local.token[0] = arg0[2];
        local.token[1] = arg0[3];
        local.token[2] = arg0[4];
        local.token[3] = '\0';
        *(u16 *)(resource + 4) = (u16)func_0043c6b0(local.token);
        local.token[0] = arg0[6];
        local.token[1] = arg0[7];
        local.token[2] = arg0[8];
        local.token[3] = '\0';
        *(u16 *)(resource + 6) = (u16)func_0043c6b0(local.token);
    } else {
        *(s16 *)(resource + 4) = -1;
        *(s16 *)(resource + 6) = -1;
    }
    if (iGpffffb204 == 0) {
        func_00440b68(&iGpffff9df0, D_005EFC80, 0x4A5);
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) =
            func_00454a60(*(char **)(resource + 0xA44), 0);
    } else {
        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x80) = 1;
    }
    return resource;
}
#pragma pop

// FUN_00150C80
s32 func_00150c80(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80);
    if (p == NULL) {
        return 1;
    }
    if (iGpffffb204 == 0) {
        return func_004553c0((s32)p) != 0;
    }
    return 1;
}

/* measured: 988B/992B, all emitted instructions match; 4B retail zero tail.
   The stream descriptors and complete chunk header are real helper storage.
   Keep resource snapshots on their retail side of the asynchronous callbacks. */
// FUN_00150CE0
void func_00150ce0(u8 *resource)
{
    s32 size;
    s32 memory[2]; /* RwMemory: start, length. */
    s32 chunkMemory[2];
    u32 chunk[5]; /* RwChunkHeaderInfo, including the unsigned byte length. */
    s32 data;
    s32 callbackHandle;
    s32 streamHandle;
    s32 child;
    u8 *destination;

    data = func_00455f70(*(u8 **)(resource + 0xA44), &size);
    memory[0] = data;
    memory[1] = size;
    if (data != 0) {
        streamHandle = func_003e2f60(3, 1, &memory[0]);
        if (streamHandle != 0) {
            while (func_003df3c0(streamHandle, (s32 *)chunk) != 0) {
                switch (chunk[0]) {
                case 11:
                    if (*(s32 *)(*(u8 **)(resource + 0xA44) +
                                 *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) * 4 + 0x90) == 0) {
                        chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    }
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    destination = *(u8 **)(resource + 0xA44);
                    child = func_004667d0(1, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    *(s32 *)(destination + *(s32 *)(destination + 0x8C) * 4 + 0x90) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) =
                        *(s32 *)(*(u8 **)(resource + 0xA44) + 0x8C) + 1;
                    break;
                case 16:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_003e2f60(3, 1, &chunkMemory[0]);
                    destination = *(u8 **)(resource + 0xA44);
                    child = func_004667d0(2, 0, 0, 0, child, 0, 0, 0, 0, 0);
                    *(s32 *)(destination + *(s32 *)(destination + 0xA0) * 4 + 0xA4) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0xA0) =
                        *(s32 *)(*(u8 **)(resource + 0xA44) + 0xA0) + 1;
                    break;
                case 35:
                    callbackHandle = func_003dc370((void *)streamHandle);
                    func_003ef260(callbackHandle, func_00463100,
                                  *(u8 **)(resource + 0xA44) + 0x128);
                    func_003ef1b0(callbackHandle);
                    break;
                case 22:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_004667d0(8, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x84) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                case 12:
                    chunkMemory[0] = memory[0] + *(s32 *)((u8 *)streamHandle + 0xC);
                    chunkMemory[1] = memory[1];
                    child = func_004667d0(0xB, 0, 0, 0, func_003e2f60(3, 1, &chunkMemory[0]), 0, 0, 0, 0, 0);
                    *(s32 *)(*(u8 **)(resource + 0xA44) + 0x124) = child;
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                default:
                    func_003e2ce0(streamHandle, chunk[1]);
                    break;
                }
            }
            if (streamHandle != 0) {
                func_003e2e40(streamHandle, 0);
            }
        } else {
            if (*(u8 **)(resource + 0xA44) != NULL) {
                func_00454bd0(*(u8 **)(*(u8 **)(resource + 0xA44) + 0x80));
                jtbl_008873EC[0](*(u8 **)(resource + 0xA44));
            }
            if (resource != NULL) {
                jtbl_008873EC[0](resource);
            }
        }
    }
}

// FUN_001510C0
s32 func_001510c0(u8 *arg0)
{
    s32 sp6C;
    s32 sp68;
    s32 var_16;
    u32 var_20;
    s32 temp_18;
    u8 *temp_19;
    u8 *temp_20;
    u32 var_19;

    var_16 = 0;
    if (*(u8 **)(arg0 + 0xA44) == NULL) {
        return 1;
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) != 0) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
            func_0046d730((const char *)D_005EFC80, 0x56C);
        }
        temp_18 = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84), &sp68, &sp6C);
        if (sp68 == 1) {
            func_003ef260(temp_18, func_00463100, *(u8 **)(arg0 + 0xA44) + 0x128);
            func_003ef1b0(temp_18);
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x84) = 0;
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
        } else {
            var_16 += 1;
        }
    }
    for (var_20 = 0; var_20 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x8C); var_20++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) != 0) {
            temp_19 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_19 == NULL) {
                    func_0046d730((const char *)D_005EFC80, 0x588);
                }
                if (func_00457ce0(temp_19, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_19;
                } else if (func_00457ce0(temp_19, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_19;
                } else if (*(s32 *)(arg0 + 0xC) == 0) {
                    *(s32 *)(arg0 + 0xC) = (s32)temp_19;
                    func_003db550(temp_19, (void *)(u32)func_00457120());
                } else {
                    *(s32 *)(arg0 + 8) = (s32)temp_19;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_20 * 4 + 0x90) = 0;
                *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 1;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    for (var_19 = 0; var_19 < *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0xA0); var_19++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) != 0) {
            temp_20 = func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4), &sp68, &sp6C);
            if (sp68 == 1) {
                if (temp_20 == NULL) {
                    func_0046d730((const char *)D_005EFC80, 0x5B4);
                }
                if (func_00457c90(temp_20, D_005EFCE0) != 0) {
                    *(s32 *)(arg0 + 0x10) = (s32)temp_20;
                } else if (func_00457c90(temp_20, D_005EFD00) != 0) {
                    *(s32 *)(arg0 + 0x14) = (s32)temp_20;
                } else if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 8) == 0) {
                    *(s32 *)(arg0 + 8) = (s32)temp_20;
                    *(void **)(arg0 + 0xC) = func_00462ae0(temp_20);
                } else {
                    *(s32 *)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x1C) = (s32)temp_20;
                    *(void **)(arg0 + *(s32 *)(arg0 + 0x18) * 4 + 0x9C) = func_00462ae0(temp_20);
                    *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) + 1;
                }
                *(s32 *)(*(u8 **)(arg0 + 0xA44) + var_19 * 4 + 0xA4) = 0;
                if (sp6C != 0) {
                    func_003e2e40(sp6C, 0);
                }
            } else {
                var_16 += 1;
            }
        }
    }
    if (*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) != 0) {
        *(s32 *)(arg0 + 0xA20) = (s32)func_004669d0(*(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124), &sp68, &sp6C);
        if (sp68 == 1) {
            if (sp6C != 0) {
                func_003e2e40(sp6C, 0);
            }
            if (*(s32 *)(arg0 + 0xA20) == 0) {
                func_0046d730((const char *)D_005EFC80, 0x5D9);
            }
            *(s32 *)(*(u8 **)(arg0 + 0xA44) + 0x124) = 0;
        } else {
            var_16 += 1;
        }
    }
    if (var_16 == 0) {
        if (*(s32 *)(arg0 + 8) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
            *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 0xC);
        }
        if (!(*(s32 *)(arg0 + 0) & 1) && *(s32 *)(arg0 + 0x18) == 0) {
            *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) | 0x10000000;
        }
        if (iGpffffb204 == 0) {
            func_00454bd0(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x80));
        }
        *(s32 *)(arg0 + 0xA24) = 0x3F800000;
        *(s32 *)(arg0 + 0xA28) = 0x3F800000;
        *(s32 *)(arg0 + 0xA2C) = 0x3F800000;
        return 1;
    }
    return 0;
}

// FUN_00151580
s32 func_00151580(u8 *arg0, s32 arg1, s32 *arg2)
{
    s32 spA8[2];
    s32 spA0[2];
    s32 sp98[2];
    s32 var_17;
    s32 var_16;
    u8 *temp_21;
    s32 var_22;
    s32 temp_23;

    var_22 = 0;
    for (var_17 = 0; var_17 < *(u32 *)(arg0 + 0x18); var_17++) {
        temp_21 = arg0 + var_17 * 4;
        temp_23 = func_004581a0(*(void **)(temp_21 + 0x1C), (const char *)D_005EFD20);
        for (var_16 = 0; var_16 < temp_23; var_16++) {
            func_00458430(spA0, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD40, var_16);
            if (spA0[0] == 0) {
                func_0046d730((const char *)D_005EFC80, 0x622);
            }
            func_00458430(spA8, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD20, var_16);
            func_00458430(sp98, *(void **)(temp_21 + 0x1C), (const char *)D_005EFD60, var_16);
            if (sp98[0] != 0) {
                *arg2 = 1;
            } else {
                *arg2 = 0;
            }
            if (spA8[0] != 1 && arg1 == spA0[0]) {
                var_22 = spA8[1];
                goto out;
            }
        }
    }
out:
    return var_22;
}

// FUN_00151710
void func_00151710(u8 *arg0)
{
    s32 temp_16;
    u8 *temp_17;
    u32 var_19;
    s32 var_18;
    s32 sp20C;
    s32 sp208;
    s32 sp200[2];
    s32 sp1F8[2];
    s32 sp1F0[2];
    s32 sp1E8[2];
    s32 sp1E0[2];
    char sp1A0[0x40];
    char sp160[0x40];
    char sp120[0x40];
    char spE0[0x40];
    char spA0[0x40];
    char sp60[0x40];
    s32 r;

    for (var_19 = 0; var_19 < *(u32 *)(arg0 + 0x18); var_19++) {
        temp_17 = arg0 + var_19 * 4;
        temp_16 = func_004581a0(*(void **)(temp_17 + 0x1C), (const char *)D_005EFD20);
        for (var_18 = 0; var_18 < temp_16; var_18++) {
            func_00458430(sp1F8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD80, var_18);
            if (sp1F8[0] != 0) {
                func_00458430(sp1E8, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD40, var_18);
                if (sp1E8[0] == 0) {
                    func_0046d730((const char *)D_005EFC80, 0x65A);
                }
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x124) = (u16)sp1E8[0];
                func_00458430(sp1E0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD60, var_18);
                if (sp1E0[0] != 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) = 2;
                }
                func_00458430(sp200, *(void **)(temp_17 + 0x1C), (const char *)D_005EFD20, var_18);
                *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x120) = (u16)sp200[0];
                if (sp200[0] == 0) {
                    if (iGpffffb204 == 0) {
                        func_00442830(sp1A0, D_005EFD98);
                        func_00442088(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp1A0, sp160);
                        func_00442088(sp160, D_005EFDA8, sp1F8[0]);
                        func_00442428(sp1A0, sp160);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477e80(4, (u16)sp1F8[0], sp1A0, 0);
                    } else {
                        func_00442830(sp1A0, D_005EFDB8);
                        func_00442088(sp160, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp1A0, sp160);
                        func_00442088(sp160, D_005EFDA8, sp1F8[0]);
                        func_00442428(sp1A0, sp160);
                        r = func_00455f70(sp1A0, &sp20C);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477f10(4, (u16)sp1F8[0], r, sp20C, 0);
                    }
                } else if (sp200[0] == 1) {
                    if (iGpffffb204 == 0) {
                        func_00442830(sp120, D_005EFDC8);
                        func_00442088(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp120, spE0);
                        func_00442088(spE0, D_005EFDD8, sp1F8[0]);
                        func_00442428(sp120, spE0);
                        func_00440b68(&iGpffff9df0, D_005EFC80, 0x6A1);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00454a60(sp120, 0);
                        if (*(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) == 0) {
                            func_0046d730((const char *)D_005EFC80, 0x6A2);
                        }
                    } else {
                        func_00442830(sp120, D_005EFDE8);
                        func_00442088(spE0, &iGpffff9e10, *(s16 *)(arg0 + 4));
                        func_00442428(sp120, spE0);
                        func_00442088(spE0, D_005EFDD8, sp1F8[0]);
                        func_00442428(sp120, spE0);
                        *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x134) = func_00455f70(sp120, &sp208);
                    }
                } else if (sp200[0] == 2) {
                    func_00442830(spA0, D_005EFE00);
                    func_00442088(sp60, D_005EFDA8, sp1F8[0]);
                    func_00442428(spA0, sp60);
                    *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x12C) = func_00477e80(4, (u16)(sp1F8[0] + 0x3E8), spA0, 0);
                }
                func_00458430(sp1F0, *(void **)(temp_17 + 0x1C), (const char *)D_005EFE10, var_18);
                if (sp200[0] == 0) {
                    *(u16 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x122) |= (u16)sp1F0[0];
                }
                *(s32 *)(arg0 + *(u32 *)(arg0 + 0x11C) * 0x18 + 0x128) = sp200[1];
                *(u32 *)(arg0 + 0x11C) = *(u32 *)(arg0 + 0x11C) + 1;
            }
        }
    }
}

// FUN_00151C80
s32 func_00151c80(u8 *arg0)
{
    u32 i;
    u32 j;

    for (i = 0; i < *(u32 *)(arg0 + 0x11C); i++) {
        if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + i * 0x18 + 0x120) == 2) {
            if (*(u32 *)(arg0 + i * 0x18 + 0x12C) == 0) {
                func_0046d730((const char *)D_005EFC80, 0x6E4);
            }
            if (func_004782b0(*(u32 *)(arg0 + i * 0x18 + 0x12C)) == 0) {
                return 0;
            }
        } else if (*(u16 *)(arg0 + i * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0 && *(u8 **)(arg0 + i * 0x18 + 0x134) != NULL && func_004553c0((s32)*(u8 **)(arg0 + i * 0x18 + 0x134)) == 0) {
                return 0;
            }
        }
    }
    for (j = 0; j < *(u32 *)(arg0 + 0x11C); j++) {
        if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 0 || *(u16 *)(arg0 + j * 0x18 + 0x120) == 2) {
            func_0047a1c0(*(void **)(arg0 + j * 0x18 + 0x12C), func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)), 0);
            if (*(u16 *)(arg0 + j * 0x18 + 0x122) & 1) {
                func_0047a0e0(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0.0f);
            } else {
                func_00479940(*(void **)(arg0 + j * 0x18 + 0x12C), 0, 0, 8, 1);
            }
        } else if (*(u16 *)(arg0 + j * 0x18 + 0x120) == 1) {
            if (iGpffffb204 == 0) {
                if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                    *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130(*(u32 *)(*(u8 **)(arg0 + j * 0x18 + 0x134) + 0x110));
                    func_004b1250(*(void **)(arg0 + j * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)) + 0x30));
                    func_00454bd0(*(u8 **)(arg0 + j * 0x18 + 0x134));
                    *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
                }
            } else if (*(u8 **)(arg0 + j * 0x18 + 0x134) != NULL) {
                *(s32 *)(arg0 + j * 0x18 + 0x130) = func_004b1130((s32)*(u8 **)(arg0 + j * 0x18 + 0x134));
                func_004b1250(*(void **)(arg0 + j * 0x18 + 0x130), (f32 *)((u8 *)func_003e9700(*(RwFrame **)(arg0 + j * 0x18 + 0x128)) + 0x30));
                *(u8 **)(arg0 + j * 0x18 + 0x134) = NULL;
            }
        }
    }
    if (*(u8 **)(arg0 + 0xA44) != NULL) {
        if (*(s16 *)(arg0 + 4) >= 0x28 && *(s16 *)(arg0 + 4) < 0x31) {
            if (*(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128) != 0) {
                *(s32 *)(iGpffff9db0 + 0x8C) = *(u32 *)(*(u8 **)(arg0 + 0xA44) + 0x128);
            }
        } else {
            func_00463250(*(u8 **)(*(u8 **)(arg0 + 0xA44) + 0x128));
        }
        jtbl_008873EC[0](*(u8 **)(arg0 + 0xA44));
        *(u8 **)(arg0 + 0xA44) = NULL;
    }
    return 1;
}

// FUN_00151F80
void func_00151f80(u8 *arg0)
{
    s32 temp_4;
    u32 var_16;
    u32 var_18;
    u8 *temp_16;
    u8 *temp_4_8;

    if (*(u32 *)arg0 & 1) {
        temp_4 = *(s32 *)(arg0 + 8);
        if (temp_4 != 0 && temp_4 != *(s32 *)(arg0 + 0xC)) {
            func_003c9d40((void *)temp_4);
        }
        if (*(s32 *)(arg0 + 0xC) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0xC));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c9d40((void *)*(s32 *)(arg0 + 0x14));
        }
    } else {
        func_00462bf0((void *)*(s32 *)(arg0 + 0xC));
        if (*(s32 *)(arg0 + 8) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 8));
        }
        if (*(s32 *)(arg0 + 0x10) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x10));
        }
        if (*(s32 *)(arg0 + 0x14) != 0) {
            func_003c0700((void *)*(s32 *)(arg0 + 0x14));
        }
    }
    for (var_18 = 0; var_18 < *(u32 *)(arg0 + 0x18); var_18++) {
        temp_16 = arg0 + var_18 * 4;
        func_00462bf0((void *)*(s32 *)(temp_16 + 0x9C));
        func_003c0700((void *)*(s32 *)(temp_16 + 0x1C));
    }
    for (var_16 = 0; var_16 < *(u32 *)(arg0 + 0x11C); var_16++) {
        temp_4_8 = arg0 + var_16 * 0x18;
        if (*(u16 *)(temp_4_8 + 0x120) == 0 || *(u16 *)(temp_4_8 + 0x120) == 2) {
            func_004787e0(*(s32 *)(temp_4_8 + 0x12C));
        } else if (*(u16 *)(temp_4_8 + 0x120) == 1) {
            func_004b1150(*(s32 *)(temp_4_8 + 0x130));
        }
    }
    if (*(s32 *)(arg0 + 0xA20) != 0) {
        func_003bbb60((void *)*(s32 *)(arg0 + 0xA20));
    }
    if (*(s32 *)(arg0 + 0xA40) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(arg0 + 0xA40));
    }
    jtbl_008873EC[0](arg0);
}

/* The draw-state table has two address lifetimes: one at the initial call,
 * and one shared by the final render-state sequence. The context is passed
 * in the callback's second argument. Saved Vec4 values are light colors. */
// FUN_00152170
void func_00152170(u8 *arg0, u8 *arg1)
{
    typedef struct { u32 w0; u32 w1; } CopyPair;
    u8 *gs;
    void *raster;
    u8 *cam;
    CopyPair *src;
    CopyPair *dst;
    u32 w0;
    u32 w1;
    s32 n;
    s32 flags;
    s32 light;

    raster = (void *)(u32)func_00457120();
    gs = (u8 *)D_00887300;
    (*(RwBool (**)(RwRenderState, void *))gs)(0x14, (void *)2);
    func_003e8110((u32)raster);
    cam = (u8 *)(u32)func_004571a0();
    *(Vec4 *)(arg1 + 0xA50) = *(Vec4 *)(cam + 0x18);
    cam = (u8 *)(u32)func_004571b0();
    *(Vec4 *)(arg1 + 0xA60) = *(Vec4 *)(cam + 0x18);
    src = (CopyPair *)(*(u8 **)((u8 *)(u32)func_004571b0() + 4) + 0x10);
    dst = (CopyPair *)(arg1 + 0xA70);
    n = 8;
    do {
        w0 = src->w0;
        w1 = src->w1;
        src++;
        n--;
        dst->w0 = w0;
        dst->w1 = w1;
        dst++;
    } while (n > 0);
    if (func_00149ca0() != 0) {
        func_003c38b0((RpLight *)(u32)func_004571a0(), (const RwRGBAReal *)func_00149ca0());
        func_003c38b0((RpLight *)(u32)func_004571b0(), (const RwRGBAReal *)func_00149ce0());
        func_003e9cb0(*(RwFrame **)((u8 *)(u32)func_004571b0() + 4),
                      (const RwMatrix *)func_00149d20(), rwCOMBINEREPLACE);
    }
    *(s8 *)((u8 *)(u32)func_004571b0() + 2) = 3;
    func_004571b0();
    if (*(s32 *)arg1 & 1) {
        func_003cbc60(func_00457190(), (u8 *)raster);
        flags = *(s32 *)arg1;
        if (flags & 0x80000000) {
            func_003cbc10(*(RpWorld **)(arg1 + 0xC), (RwCamera *)raster);
        } else if (flags & 0x40000000) {
            light = *(s32 *)(arg1 + 0x10);
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else if (flags & 0x20000000) {
            light = *(s32 *)(arg1 + 0x14);
            if (light != 0) {
                func_003cbc10((RpWorld *)(u32)light, (RwCamera *)raster);
            }
        } else {
            func_003cbc10(*(RpWorld **)(arg1 + 8), (RwCamera *)raster);
        }
        func_003cbf30((RpWorld *)(u32)func_00457190(), (RpLight *)(u32)func_004571a0());
        func_003cbf30((RpWorld *)(u32)func_00457190(), (RpLight *)(u32)func_004571b0());
        flags = *(s32 *)arg1;
        if (flags & 0x80000000) {
            func_003cbe80(*(RpWorld **)(arg1 + 0xC), (RpLight *)(u32)func_004571a0());
            func_003cbe80(*(RpWorld **)(arg1 + 0xC), (RpLight *)(u32)func_004571b0());
        } else if (flags & 0x40000000) {
            func_003cbe80(*(RpWorld **)(arg1 + 0x10), (RpLight *)(u32)func_004571a0());
            func_003cbe80(*(RpWorld **)(arg1 + 0x10), (RpLight *)(u32)func_004571b0());
        } else if ((flags & 0x20000000) && (*(s32 *)(arg1 + 0x14) != 0)) {
            func_003cbe80(*(RpWorld **)(arg1 + 0x14), (RpLight *)(u32)func_004571a0());
            func_003cbe80(*(RpWorld **)(arg1 + 0x14), (RpLight *)(u32)func_004571b0());
        } else {
            func_003cbe80(*(RpWorld **)(arg1 + 8), (RpLight *)(u32)func_004571a0());
            func_003cbe80(*(RpWorld **)(arg1 + 8), (RpLight *)(u32)func_004571b0());
        }
    } else {
        func_003cbf30((RpWorld *)(u32)func_00457190(), (RpLight *)(u32)func_004571c0());
    }
    func_003e8120((u32)raster);
    gs = (u8 *)D_00887300;
    (*(RwBool (**)(RwRenderState, void *))gs)(6, (void *)1);
    (*(RwBool (**)(RwRenderState, void *))gs)(8, (void *)1);
    func_003f6440(2, (void *)0x44);
    func_003f6440(3, (void *)0x717FB);
    (*(RwBool (**)(RwRenderState, void *))gs)(0x14, (void *)2);
    if (iGpffffba48 == 1) {
        (*(RwBool (**)(RwRenderState, void *))gs)(0xE, (void *)1);
        (*(RwBool (**)(RwRenderState, void *))gs)(0xF,
            (void *)(iGpffffba54 | (((u32)iGpffffba50 << 8) | (((u32)iGpffffba58 << 0x18) | ((u32)iGpffffba4c << 0x10)))));
        (*(RwBool (**)(RwRenderState, void *))gs)(0x10, (void *)1);
    }
}

// FUN_00152630
void func_00152630(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_18_3;

    temp_2 = (void *)(u32)func_00457120();
    func_003e8110((u32)temp_2);
    if (*(u32 *)arg1 & 1) {
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0xC), (RpLight *)(u32)func_004571a0());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0xC), (RpLight *)(u32)func_004571b0());
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x10), (RpLight *)(u32)func_004571a0());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x10), (RpLight *)(u32)func_004571b0());
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x14), (RpLight *)(u32)func_004571a0());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 0x14), (RpLight *)(u32)func_004571b0());
        } else {
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 8), (RpLight *)(u32)func_004571a0());
            func_003cbf30((RpWorld *)(u32)*(s32 *)(arg1 + 8), (RpLight *)(u32)func_004571b0());
        }
        temp_18 = (void *)(u32)func_00457190();
        func_003cbe80((RpWorld *)temp_18, (RpLight *)(u32)func_004571a0());
        temp_18_2 = (void *)(u32)func_00457190();
        func_003cbe80((RpWorld *)temp_18_2, (RpLight *)(u32)func_004571b0());
        if (*(u32 *)arg1 & 0x80000000) {
            func_003cbc60(*(s32 *)(arg1 + 0xC), (u8 *)temp_2);
        } else if (*(u32 *)arg1 & 0x40000000) {
            func_003cbc60(*(s32 *)(arg1 + 0x10), (u8 *)temp_2);
        } else if ((*(u32 *)arg1 & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
            func_003cbc60(*(s32 *)(arg1 + 0x14), (u8 *)temp_2);
        } else {
            func_003cbc60(*(s32 *)(arg1 + 8), (u8 *)temp_2);
        }
        func_003cbc10((RpWorld *)(u32)func_00457190(), (RwCamera *)temp_2);
    } else {
        temp_18_3 = (void *)(u32)func_00457190();
        func_003cbe80((RpWorld *)temp_18_3, (RpLight *)(u32)func_004571c0());
    }
    func_003c38b0((RpLight *)(u32)func_004571a0(), (const RwRGBAReal *)(arg1 + 0xA50));
    func_003c38b0((RpLight *)(u32)func_004571b0(), (const RwRGBAReal *)(arg1 + 0xA60));
    func_003e9cb0((RwFrame *)(u32)*(s32 *)((u8 *)(u32)func_004571b0() + 4),
                  (const RwMatrix *)(arg1 + 0xA70), rwCOMBINEREPLACE);
    *(s8 *)((u8 *)(u32)func_004571b0() + 2) = 3;
    func_004571b0();
    func_003e8120((u32)temp_2);
}

// FUN_00152930
void func_00152930(u8 *arg0, u8 *arg1)
{
    u8 *var_2;
    u8 *var_6;
    u8 *p2;
    s32 temp_3;
    u32 flags;
    u32 i;

    var_6 = NULL;
    flags = *(u32 *)arg1;
    if (flags & 1) {
        temp_3 = *(s32 *)(arg1 + 8);
        if (temp_3 != 0) {
            if (flags & 0x80000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0xC));
            } else if (flags & 0x40000000) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x10));
            } else if ((flags & 0x20000000) && *(s32 *)(arg1 + 0x14) != 0) {
                var_2 = func_00461290(arg0, *(s32 *)(arg1 + 0x14));
            } else {
                var_2 = func_00461290(arg0, temp_3);
            }
            *(void (**)(void))(var_2 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_2 + 0x10) = arg1;
            *(void (**)(void))(var_2 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_2 + 0x14) = arg1;
        }
    } else {
        if (flags & 0x80000000) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00460e80(arg0, *(s32 *)(arg1 + 0xC));
            } else {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 8));
            }
        } else if (flags & 0x40000000) {
            var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
        } else if (flags & 0x20000000) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(s32 *)(arg1 + 0x9C + i * 4) != 0) {
                p2 = func_00460e80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
            } else {
                p2 = func_00461180(arg0, *(s32 *)(arg1 + 0x1C + i * 4));
            }
            if (p2 != NULL && i == 0) {
                *(void (**)(void))(p2 + 8) = (void (*)(void))func_00152170;
                *(u8 **)(p2 + 0x10) = arg1;
            }
            if (p2 != NULL && i == *(u32 *)(arg1 + 0x18) - 1) {
                *(void (**)(void))(p2 + 0xC) = (void (*)(void))func_00152630;
                *(u8 **)(p2 + 0x14) = arg1;
            }
        }
    }
}

// FUN_00152BB0
void func_00152bb0(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000) && *(u8 **)(arg1 + 0xC) != NULL) {
            var_6 = func_00460f80(arg0, *(s32 *)(arg1 + 0xC));
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00460f80(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00152170;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))func_00152630;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

// FUN_00152CD0
void func_00152cd0(u8 *arg0, u8 *arg1)
{
    u8 *var_6;
    u8 *temp_2;
    u32 i;

    var_6 = NULL;
    if (!(*(u32 *)arg1 & 1)) {
        if ((*(u32 *)arg1 & 0x80000000)) {
            if (*(s32 *)(arg1 + 0xC) != 0) {
                var_6 = func_00461080(arg0, *(s32 *)(arg1 + 0xC));
            }
        } else if ((*(u32 *)arg1 & 0x40000000)) {
            if (*(s32 *)(arg1 + 0x10) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x10));
            }
        } else if ((*(u32 *)arg1 & 0x20000000)) {
            if (*(s32 *)(arg1 + 0x14) != 0) {
                var_6 = func_00461180(arg0, *(s32 *)(arg1 + 0x14));
            }
        }
        if (var_6 != NULL) {
            *(void (**)(void))(var_6 + 8) = (void (*)(void))func_00152170;
            *(u8 **)(var_6 + 0x10) = arg1;
            *(void (**)(void))(var_6 + 0xC) = (void (*)(void))func_00152630;
            *(u8 **)(var_6 + 0x14) = arg1;
        }
    }
    if (!(*(u32 *)arg1 & 0xC0000000)) {
        for (i = 0; i < *(u32 *)(arg1 + 0x18); i++) {
            if (*(u8 **)(arg1 + 0x9C + i * 4) != NULL) {
                temp_2 = func_00461080(arg0, *(s32 *)(arg1 + 0x9C + i * 4));
                if (temp_2 != NULL && i == 0) {
                    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00152170;
                    *(u8 **)(temp_2 + 0x10) = arg1;
                    *(void (**)(void))(temp_2 + 0xC) = (void (*)(void))func_00152630;
                    *(u8 **)(temp_2 + 0x14) = arg1;
                }
            }
        }
    }
}

/* Measured: 1188 bytes and 27 resolved relocations; twelve zero tail bytes.
 * Real twelve-byte vectors/tolerances occupy quadword-aligned stack slots.
 * The packed axis view preserves the independent eight- and four-byte loads;
 * resource pointers, loop bounds and the post-rotate frame remain reloads. */
#pragma push
#pragma opt_propagation off
// FUN_00152E50
void func_00152e50(u8 *arg0, u8 *arg1, f32 fparg0)
{
    struct {
        Vec3 RWALIGN(trans, 16);
        union {
            Vec3 vector;
            struct { s64 xy; f32 z; } bits;
        } RWALIGN(axis, 16);
        RwMatrixTolerance RWALIGN(t3, 16);
        Vec3 RWALIGN(v3, 16);
        RwMatrixTolerance RWALIGN(t2, 16);
        Vec3 RWALIGN(v2, 16);
        RwMatrixTolerance RWALIGN(t1, 16);
        Vec3 RWALIGN(v1, 16);
        RwMatrixTolerance RWALIGN(t0, 16);
        Vec3 RWALIGN(v0, 16);
    } stk;
    u16 kind;
    u32 i;
    u8 *mtx2;
    u32 j;
    u8 *frame;
    u8 *frame2;
    u8 *frame3;
    u8 *frame4;
    u8 *mtx;
    u8 *res;
    u8 *res2;
    u8 *res3;
    u8 *res4;

    if (!(*(s32 *)arg0 & 1)) {
        res = *(u8 **)(arg0 + 8);
        if (res != NULL) {
            frame = *(u8 **)(res + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame);
            stk.v0 = *(Vec3 *)(mtx + 0x30);
            stk.v0.x += *(f32 *)(arg1 + 0);
            stk.v0.y += *(f32 *)(arg1 + 4);
            stk.v0.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame + 0x40) = stk.v0;
            func_003e0380(&stk.t0);
            func_003e03e0((RwMatrix *)(frame + 0x10), &stk.t0);
            func_003e9680((RwFrame *)frame);
        }
        res2 = *(u8 **)(arg0 + 0x10);
        if (res2 != NULL) {
            frame2 = *(u8 **)(res2 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame2);
            stk.v1 = *(Vec3 *)(mtx + 0x30);
            stk.v1.x += *(f32 *)(arg1 + 0);
            stk.v1.y += *(f32 *)(arg1 + 4);
            stk.v1.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame2 + 0x40) = stk.v1;
            func_003e0380(&stk.t1);
            func_003e03e0((RwMatrix *)(frame2 + 0x10), &stk.t1);
            func_003e9680((RwFrame *)frame2);
        }
        res3 = *(u8 **)(arg0 + 0x14);
        if (res3 != NULL) {
            frame3 = *(u8 **)(res3 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame3);
            stk.v2 = *(Vec3 *)(mtx + 0x30);
            stk.v2.x += *(f32 *)(arg1 + 0);
            stk.v2.y += *(f32 *)(arg1 + 4);
            stk.v2.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame3 + 0x40) = stk.v2;
            func_003e0380(&stk.t2);
            func_003e03e0((RwMatrix *)(frame3 + 0x10), &stk.t2);
            func_003e9680((RwFrame *)frame3);
        }
    }
    i = 0;
    while (i < *(u32 *)(arg0 + 0x18)) {
        res4 = *(u8 **)(arg0 + i * 4 + 0x1C);
        if (res4 != NULL) {
            frame4 = *(u8 **)(res4 + 4);
            mtx = (u8 *)func_003e9700((RwFrame *)frame4);
            stk.v3 = *(Vec3 *)(mtx + 0x30);
            stk.v3.x += *(f32 *)(arg1 + 0);
            stk.v3.y += *(f32 *)(arg1 + 4);
            stk.v3.z += *(f32 *)(arg1 + 8);
            *(Vec3 *)(frame4 + 0x40) = stk.v3;
            func_003e0380(&stk.t3);
            func_003e03e0((RwMatrix *)(frame4 + 0x10), &stk.t3);
            func_003e9680((RwFrame *)frame4);
        }
        i += 1;
    }
    j = 0;
    while (j < *(u32 *)(arg0 + 0x11C)) {
        kind = *(u16 *)(arg0 + j * 0x18 + 0x120);
        if (kind == 0 || kind == 2) {
            func_0047a180(*(RwMatrix **)(arg0 + j * 0x18 + 0x12C), (const Vec3 *)arg1, 2);
        } else if (kind == 1) {
            {
                s64 tmp_xy = D_005EFE28[0];
                f32 tmp_z = D_005EFE30[0];
                stk.axis.bits.xy = tmp_xy;
                stk.axis.bits.z = tmp_z;
            }
            mtx2 = (u8 *)func_003e0f80();
            *(s32 *)(mtx2 + 0x28) = 0x3F800000;
            *(s32 *)(mtx2 + 0x14) = 0x3F800000;
            *(s32 *)(mtx2 + 0) = 0x3F800000;
            *(s32 *)(mtx2 + 0x10) = 0;
            *(s32 *)(mtx2 + 8) = 0;
            *(s32 *)(mtx2 + 4) = 0;
            *(s32 *)(mtx2 + 0x24) = 0;
            *(s32 *)(mtx2 + 0x20) = 0;
            *(s32 *)(mtx2 + 0x18) = 0;
            *(s32 *)(mtx2 + 0x38) = 0;
            *(s32 *)(mtx2 + 0x34) = 0;
            *(s32 *)(mtx2 + 0x30) = 0;
            *(s32 *)(mtx2 + 0xC) |= 0x20003;
            func_003e0870((RwMatrix *)mtx2, &stk.axis.vector, fparg0, rwCOMBINEPOSTCONCAT);
            {
                u32 k = j;
                u8 *base = arg0 + k * 0x18;
                mtx = (u8 *)func_003e9700(*(RwFrame **)(base + 0x128));
                stk.trans = *(Vec3 *)(mtx + 0x30);
                func_003e42a0(&stk.trans, &stk.trans, (const RwMatrix *)mtx2);
                stk.trans.x += *(f32 *)(arg1 + 0);
                stk.trans.y += *(f32 *)(arg1 + 4);
                stk.trans.z += *(f32 *)(arg1 + 8);
                func_004b1250(*(void **)(base + 0x130), (f32 *)&stk.trans);
            }
            func_003e0f40((RwMatrix *)mtx2);
        }
        j += 1;
    }
}
#pragma pop

/* measured: opt_propagation off preserves the named scalar global loads; this scalar pair copy suppresses aggregate ld/sd traffic. */
#pragma push
#pragma opt_propagation off
#define COPY_SCALAR_PAIR(dst, src) \
do { \
    s64 copy_s64; \
    f32 copy_f32; \
    copy_s64 = (src).sp40; \
    copy_f32 = (src).sp48; \
    (dst).sp40 = copy_s64; \
    (dst).sp48 = copy_f32; \
} while (0)
// FUN_00153300
void func_00153300(s8 *arg0, f32 fparg0)
{
    extern void func_003e9d50(s32 a0, void *a1, f32 f12, s32 a3);
    void *ptr;
    struct {
        s64 sp40;
        f32 sp48;
    } sp;
    u16 temp_4;
    u32 var_16;
    u32 var_16_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_5;

    ptr = &sp.sp40;
    COPY_SCALAR_PAIR(sp, *(typeof(sp) *)D_005EFE38);
    if (!(*(u32 *)arg0 & 1)) {
        temp_3 = *(u8 **)(arg0 + 8);
        if (temp_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3 + 4), ptr, fparg0, 2);
        }
        temp_3_2 = *(u8 **)(arg0 + 0x10);
        if (temp_3_2 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_2 + 4), &sp.sp40, fparg0, 2);
        }
        temp_3_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_3 + 4), &sp.sp40, fparg0, 2);
        }
    }
    var_16 = 0;
    goto loop_test_11;
loop_body_11:
    temp_3_4 = *(u8 **)(arg0 + var_16 * 4 + 0x1C);
    if (temp_3_4 != NULL) {
        func_003e9d50(*(s32 *)(temp_3_4 + 4), &sp.sp40, fparg0, 2);
    }
    var_16 += 1;
loop_test_11:
    if (var_16 < *(u32 *)(arg0 + 0x18)) {
        goto loop_body_11;
    }
    var_16_2 = 0;
    goto loop_test_19;
loop_body_19:
    temp_5 = (u8 *)arg0 + var_16_2 * 0x18;
    temp_4 = *(u16 *)(temp_5 + 0x120);
    if (temp_4 == 0) {
        goto switch_body_a;
    }
    if (temp_4 != 2) {
        goto switch_case_1_test;
    }
switch_body_a:
    func_0047a1a0((void *)(*(s32 *)(temp_5 + 0x12C)), &sp.sp40, fparg0, 2);
    goto switch_end;
switch_case_1_test:
    if (temp_4 != 1) {
        goto switch_end;
    }
    func_004b1290(*(s32 *)(temp_5 + 0x130), 0.0f, fparg0, 0.0f);
switch_end:
    ;
    var_16_2 += 1;
loop_test_19:
    if (var_16_2 < *(u32 *)(arg0 + 0x11C)) {
        goto loop_body_19;
    }
}
/* measured: restore propagation after func_00153300. */
#pragma pop

typedef struct {
    u16 type;
    u16 flags;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} k_fldSubEntry;

typedef struct {
    u32 flags;
    s16 field_04;
    s16 field_06;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    u32 count1;
    s32 arr1[32];
    s32 arr2[32];
    u32 count2;
    k_fldSubEntry entries[96];
    s32 field_a20;
    Vec3 scale;
} k_fldResource;

extern void func_00152e50(u8 *arg0, u8 *arg1, f32 arg2);

/* measured: MWCCPS2 b210 -O2, 792B/window 800B, 17 relocations,
 * eight zero alignment bytes. Ghidra identifies the unsigned angle
 * conversion; IDA identifies the three-pair copy of each 24-byte entry.
 * The arrays end at the measured count/scale fields, not at the allocation
 * boundary: the original allocation remains 0xAB0 bytes. */
// FUN_001534A0
k_fldResource *func_001534a0(k_fldResource *src, void *arg1, u32 arg2)
{
    k_fldResource *dst;
    f32 temp_f20;
    u32 i;
    u32 j;
    u8 *p_dst;

    temp_f20 = 90.0f * (f32)arg2;
    if (src->flags & 1) {
        return NULL;
    }
    func_0044ea90(D_005EFC80, 0xA2A);
    dst = (k_fldResource *)D_008873F4[0](1, 0xAB0, 0x40000);
    dst->flags = src->flags | 2;
    dst->field_04 = src->field_04;
    dst->field_06 = src->field_06;
    if (src->field_08 != 0) {
        dst->field_08 = func_003c0520(src->field_08);
        dst->field_0c = (s32)func_00462ae0((void *)dst->field_08);
    }
    if (src->field_10 != 0) {
        dst->field_10 = func_003c0520(src->field_10);
    }
    if (src->field_14 != 0) {
        dst->field_14 = func_003c0520(src->field_14);
    }
    dst->count1 = src->count1;
    for (i = 0; i < src->count1; i++) {
        s32 arg = *(s32 *)((u8 *)src + i * 4 + 28);
        if (arg != 0) {
            s32 *s1;
            p_dst = (u8 *)dst + i * 4;
            s1 = (s32 *)(p_dst + 28);
            *s1 = func_003c0520(arg);
            *(s32 *)(p_dst + 156) = (s32)func_00462ae0((void *)*s1);
        }
    }
    dst->count2 = src->count2;
    for (j = 0; j < src->count2; j++) {
        u8 *src_base = (u8 *)src + (s32)j * 24;
        k_fldSubEntry *a3 = (k_fldSubEntry *)(src_base + 288);
        p_dst = (u8 *)dst + (s32)j * 24;
        *(k_fldSubEntry *)(p_dst + 288) = *a3;

        if (a3->type == 0 || a3->type == 2) {
            u8 *s1 = (u8 *)src + j * 24;
            s32 *s0 = &dst->entries[j].field_c;
            *s0 = func_00478750(*(s32 *)(s1 + 300));
            func_0047a1c0((void *)*s0, func_003e9700(*(void **)(s1 + 296)), 0);
            if (*(u16 *)(s1 + 290) & 2) {
                *(u16 *)(p_dst + 290) |= 2;
            }
        } else if (a3->type == 1) {
            *(s32 *)(p_dst + 304) = func_004b11b0(*(s32 *)(src_base + 304));
        }
    }
    dst->scale = src->scale;
    func_00153300((s8 *)dst, temp_f20);
    func_00152e50((u8 *)dst, arg1, temp_f20);
    return dst;
}
