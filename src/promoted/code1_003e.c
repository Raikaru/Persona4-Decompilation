#include "include_asm.h"
#include "type.h"
typedef struct {
    f32 normal;
    f32 orthogonal;
    f32 identity;
} MatrixTolerance003e;
typedef void (*Callback003e)(u8 *, u8 *, u8 *);

extern s32 D_008866D8;

extern s32 D_0088731C;

extern s32 D_00886700;

extern s32 D_00887330;
extern s32 iGpffffb7b8;

extern u8 D_008872E0[];
extern u8 D_008871C0[];
extern s32 iGpffffab50;
extern s32 iGpffffb768;
extern u8 *iGpffffb778;
extern s32 D_00724870;
extern s32 (*D_008873D4[])(char *arg0);
extern char D_00752FA8[];
extern u8 D_00887250[];
extern void *D_00887408[];
extern s32 D_00763C68;
extern s32 D_00763C6C;
extern s32 D_00764874;
extern s32 D_00764878;
extern s32 D_0076487C;
extern s32 D_00764884;
extern s32 D_00764888;
extern s32 D_00764890;
extern s32 D_00764898;
extern s32 D_0076489C;
extern s32 D_00763C54;
extern s32 D_00763C58;
extern s32 D_00763C70;
extern s32 D_00763C74;
extern s32 D_00764860;
extern void *D_00764864;
extern void *D_00764868;
extern s32 D_007648A0;
extern s32 D_007648A4;
extern s32 D_0070B800[];
extern u8 D_00887220[];
extern u8 D_00887280[];
extern s8 D_00754D88[];
extern s32 (*D_0088732C[])(s32, s32, s32);
extern s32 (*D_00887350[])(s32, s32, s32);
extern s32 (*D_0088737C)(void);
extern u8 D_008872F0[];
extern s32 func_003e87f0();
extern s32 func_003df590(s32 arg0, ...);
extern void func_003df4d0(void *arg0);
extern u8 D_0070B730[];
s32 func_003e1220(s32, s32, s32, s32, void *, s32);
extern s32 func_003ec480();
s32 func_003e12f0(u8 *);
s32 func_003e1740(u8 *);
void func_003e1230(void *);
void func_003ed7e0(void);
void func_00410f40(s32);
u8 *func_003e1cb0(u8 *, void *);
void func_003e3dc0();
void func_003e3d00();
u8 *func_003e3f00(u8 *, u8 *, u8 *);
void func_003e3e60();
extern u8 *func_003df9f0(u8 *arg0, u8 *arg1);
extern s32 func_003e1030(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern void func_0043ece8(s32 arg0);
extern void func_00441558(u8 *arg0, u8 *arg1);
extern void func_0043c710(s32 arg0, s32 arg1);
extern s32 func_003e3830(u8 *arg0, s32 arg1);
extern u8 D_0070B760[];
extern u8 D_0070B710[];
extern u8 D_0070B7A0[];
extern void func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_003ef3a0(void);
extern f32 sqrtf(f32 x);
extern void func_003df8c0(u8 *, u8 *, u8 *);
extern void func_003e6db0();
extern void func_003e9680(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void *(*jtbl_008873E8[])(void *arg0, s32 arg1);
extern s32 iGpffffb76c;
extern s32 iGpffffb7c0;
extern s32 iGpffffb7c4;
extern s32 iGpffffb7a4;
extern s32 iGpffffb780;
extern s32 iGpffffb7a0;
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern void func_003efda0(u8 *arg0);
extern void func_0043ed08(s32 arg0);
extern s32 iGpffffb770;
extern s32 iGpffffb77C;
extern s32 iGpffffb78C;
extern s32 iGpffffb788;
extern s32 D_008871F0;
extern u8 D_008873F0[];
extern s32 func_003ddf20(void *arg0);
extern s32 func_003e3370(u8 *arg0, s32 arg1);
extern s32 func_003e2ab0(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_003e4520(void *arg0, s32 arg1);
extern void func_003e4960();
extern void func_003e4920();
extern void func_003e47c0();
extern u8 D_008873A4[];
extern u8 D_008873A8[];
extern u8 D_008873AC[];
extern u8 D_008873B0[];
extern u8 D_008873B4[];
extern u8 D_008873B8[];
extern u8 D_008873BC[];
extern u8 D_008873C0[];
extern u8 D_008873C4[];
extern u8 D_008873C8[];
extern u8 D_008873CC[];
extern u8 D_008873D0[];
extern s32 (*D_008873D4[])(char *arg0);
extern u8 D_008873D8[];
extern u8 D_008873DC[];
extern u8 D_008873E0[];
extern u8 D_008873E4[];
extern void func_00442088();
extern void func_00446ed8();
extern void func_00442830();
extern void func_00442de8();
extern void func_00442428();
extern void func_00442a80();
extern void func_00443010();
extern void func_004426e8();
extern void func_00442c30();
extern void func_00442948();
extern void func_00443f18();
extern void func_00442100();
typedef struct {
    void *next;
    void *prev;
    s32 size;
    void *owner;
    void *dtor;
    void *cb;
} Node2430003e;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 count;
    s32 unkC;
    void *head_next;
    void *head_prev;
    void *tail_next;
    void *tail_prev;
} Ctx2430003e;
extern u8 D_008873F4[];

// measured: removing this pragma takes func_003e05d0 nd 0 -> nd 16: retail fills the
// jr $ra delay slot with sw $v1, 0xc($a0) and hoists move $v0,$a0 before the and;
// baseline -O2 emits lw; lui; ori; and; sw; move; jr; nop.

/* measured: no_branch_likely on reproduces the retail beqz/nop and
   shared address-calculation block for the NULL callback fallback. */
#pragma no_branch_likely on
/* measured: schedule on probe for the retail constant/address order. */
#pragma schedule on
extern s32 func_003e00f0(Callback003e arg0); /* P4: ported verbatim into src/renderware */
#pragma schedule off
#pragma no_branch_likely off
/* measured: best candidate archived at build/X3E_003e0130_body.c; object
   80/80 B, nd 45-46 across schedule / no_branch_likely / optimization_level 3
   probes (12 variants). Ghidra-verified semantics:
   (m4*m9-m5*m8)*m2 + (m5*m10-m6*m9)*m0 + (m6*m8-m4*m10)*m1; the older
   H3E1/F3E1 archives pair the cofactors wrongly and were never compiled.
   Residual is retail's EE COP1 accumulator-MAC register bank, not
   reproducible from plain C in b210. */
// FUN_003E0250
/* measured: schedule bracket retained for func_003e0250. */
#pragma schedule on
/* measured: no_branch_likely on preserves func_003e0250 retail beqz. */
#pragma no_branch_likely on
u8 *func_003e0250(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + (s32)iGpffffb768);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + (s32)iGpffffb768) = NULL;
    }
    iGpffffb76c -= 1;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket opened above and restores the
   translation-unit baseline. */
#pragma schedule off
// FUN_003E0380
/* measured: iGpffffb768 is the registered scalar for GP -0x4898. The
   absolute D_008872E0 array plus the scalar offset reproduces retail's
   lui/addiu, gp-load, addu addressing sequence. */
/* measured: open the one-function optimization probe for func_003e0380. */
#pragma optimization_level 3
s32 func_003e0380(MatrixTolerance003e *arg0) {
    u8 *globals;
    s32 result;
    globals = (u8 *)D_008872E0 + (s32)iGpffffb768;
    result = 1;
    *(MatrixTolerance003e *)arg0 = *(MatrixTolerance003e *)(globals + 0xc);
    return result;
}
/* measured: close the one-function optimization probe for func_003e0380. */
#pragma optimization_level 2

/* measured: use the same registered scalar and absolute array domain as the
   getter; retaining the true return value reproduces retail's addiu v0,1. */
#pragma optimization_level 3
extern s32 func_003e03b0(const MatrixTolerance003e *arg0); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
#pragma optimization_level 3
extern u8 *RwMatrixUpdate(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: schedule on keeps the returned pointer in retail's jr delay slot. */
#pragma schedule on
// FUN_003E05F0
u8 *func_003e05f0(u8 *arg0, u8 *arg1, u8 *arg2) {
    __asm__ volatile(
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x10($5)\n"
        "lqc2 $vf3, 0x20($5)\n"
        "lqc2 $vf4, 0x30($5)\n"
        "lwu $3, 0xC($5)\n"
        "lqc2 $vf5, 0x0($6)\n"
        "lqc2 $vf6, 0x10($6)\n"
        "lqc2 $vf7, 0x20($6)\n"
        "lqc2 $vf8, 0x30($6)\n"
        "lwu $2, 0xC($6)\n"
        "vmulax.xyz $ACC, $vf5, $vf1x\n"
        "vmadday.xyz $ACC, $vf6, $vf1y\n"
        "vmaddz.xyz $vf9, $vf7, $vf1z\n"
        "vmulax.xyz $ACC, $vf5, $vf2x\n"
        "vmadday.xyz $ACC, $vf6, $vf2y\n"
        "vmaddz.xyz $vf10, $vf7, $vf2z\n"
        "vmulax.xyz $ACC, $vf5, $vf3x\n"
        "vmadday.xyz $ACC, $vf6, $vf3y\n"
        "vmaddz.xyz $vf11, $vf7, $vf3z\n"
        "vmulax.xyz $ACC, $vf5, $vf4x\n"
        "vmadday.xyz $ACC, $vf6, $vf4y\n"
        "vmaddaz.xyz $ACC, $vf7, $vf4z\n"
        "vmaddw.xyz $vf12, $vf8, $vf0w\n"
        "and $2, $2, $3\n"
        "sqc2 $vf9, 0x0($4)\n"
        "sqc2 $vf10, 0x10($4)\n"
        "sqc2 $vf11, 0x20($4)\n"
        "sqc2 $vf12, 0x30($4)\n"
        "sw $2, 0xC($4)\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$2", "$3", "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "$vf6", "$vf7", "$vf8", "$vf9", "$vf10", "$vf11", "$vf12", "ACC", "memory");
    return arg0;
}
/* measured: closes schedule on for the VU0 function. */
#pragma schedule off

// FUN_003E0670
/* measured: probe typed tailcall for retail's direct matrix wrapper. */
#pragma schedule on
#pragma tailcall on
u8 *func_003e0670(u8 *arg0, u8 *arg1) {
    return func_003df9f0(arg0, arg1);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off

// FUN_003E0680
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0680);

// FUN_003E0870
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0870);

/* measured: one-function optimization probe for func_003e0e20. */
#pragma optimization_level 3
/* measured: no_branch_likely probe paired with optimization-level probe. */
#pragma no_branch_likely on
// FUN_003E0E20
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0e20);
/* measured: close no_branch_likely probe. */
#pragma no_branch_likely off
/* measured: schedule on preserves the callback load in the jalr delay slot. */
/* measured: close the one-function optimization probe. */
#pragma optimization_level 2

#pragma schedule on
extern s32 func_003e0f40(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the single-function schedule bracket for func_003e0f40. */
#pragma schedule off

// measured: removing this pragma takes func_003e1020 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x54a0($gp); baseline -O2 emits sw; jr; nop.

#pragma optimization_level 3
// FUN_003E1020
void func_003e1020(s32 arg0) {
    D_008866D8 = arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

// FUN_003E1220
/* measured: probe typed tailcall for the six-argument allocator wrapper. */
#pragma schedule on
#pragma tailcall on
s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5) {
    return func_003e1030(arg0, arg1, arg2, arg3, arg4, arg5);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off

/* measured: schedule/no_branch_likely preserve the callback-loop reloads,
   callback delay slots, and the two ordered flag tests. */
#pragma schedule on
#pragma no_branch_likely on
extern void func_003e1230(void *arg0); /* P4: ported verbatim into src/renderware */
/* measured: close no_branch_likely/schedule around func_003e1230. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: schedule/no_branch_likely probe for func_003e12f0. */
#pragma schedule on
#pragma no_branch_likely on

extern s32 func_003e12f0(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: close no_branch_likely/schedule probe for func_003e12f0. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003E1740
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1740);

// FUN_003E18C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e18c0);

/* measured: best plain-C body archived in build/H3E2_003e1a70_body.c;
   object 108B/window 112B, normalized_diff 48; GP-sentinel and loop layout remain. */

// FUN_003E1AE0
#pragma tailcall on
void func_003e1ae0(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, s32 arg5, void *arg6) {
    func_0043ece8(arg0);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off

// FUN_003E1AF0
/* measured: probe typed tailcall for callback trampoline. */
#pragma schedule on
#pragma tailcall on
void func_003e1af0(u8 *arg0, u8 *arg1) {
    func_00441558(arg0, arg1);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off

// FUN_003E1B00
/* measured: probe typed tailcall for callback trampoline. */
#pragma schedule on
#pragma tailcall on
void func_003e1b00(s32 arg0, s32 arg1) {
    func_0043c710(arg0, arg1);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off

/* measured: best reconstruction archived in build/E3E_003e1b10_body.c at
   normalized_diff 30, object 284B / window 288B; structure fully decoded
   (sentinel-address-first init, arg-reuse ok flag, float-register callback
   copy, goto-web flow); residual is b210 lui/addiu pair ordering plus one
   branch displacement that no probed source spelling reproduced. */
/* measured: schedule/no_branch_likely bracket retained for func_003e1c30. */
#pragma schedule on
#pragma no_branch_likely on
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule/no_branch_likely reproduce retail's plain beqz/bnez guards. */
#pragma schedule on
#pragma no_branch_likely on
extern u8 *func_003e1cb0(u8 *arg0, void *arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: no_branch_likely keeps the success test as retail's plain bnez. */
#pragma no_branch_likely on
#pragma schedule on
extern s32 iGpffffb780;
extern s32 func_003e1e10(s32 arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes no_branch_likely/schedule around func_003e1e10. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003E1FF0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1ff0);

// FUN_003E22C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e22c0);

/* measured: sum's initial load is written before base setup so b210 keeps
   the D_008872E0 + offset base in $v1 while retail uses $v0 for the running
   sum (nd 10 -> nd 7). The remaining difference is one missing nop before
   the jr: candidate branches to the return at +0x3c while retail has a nop
   at +0x3c and the jr at +0x40. Retail's three all-zero words after its jr
   are alignment padding, not missing body instructions. Tail/control-flow,
   declaration-order, base-local, O1/O3/CSE/loop-invariant/schedule probes
   did not improve nd 7. Object 68/window 80. Committed at nd 7. */
/* measured: archived object 72B/window 80B, normalized_diff 24; initial
   compare delay-slot load and loop-join placement remain unresolved. */
// FUN_003E2430
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2430);
/* measured: loop-rotation residual around store/reload remains open after
   exhaustive while/if/pragma probes; reverting to INCLUDE_ASM for now. */
/* measured: the reload of the slot before the branch is a store-to-load forwarding
   that b210 does as a peephole; peephole off keeps it (the archive needed volatile). */
#pragma schedule on
#pragma no_branch_likely on
#pragma peephole off
// FUN_003E2570
s32 func_003e2570(s32 arg0, s32 arg1)
{
    s32 *slot;
    s32 result;

    D_00764878 = arg1;
    result = func_003e1220(0x24, D_00763C54, 4, D_00763C58, D_00887220, 0x40404);
    slot = (s32 *)(D_008872E0 + D_00764878);
    *slot = result;
    result = *slot;
    if (result == 0) {
        return 0;
    }
    D_0076487C += 1;
    return arg0;
}
/* measured: closes the peephole/no_branch_likely/schedule bracket for func_003e2570. */
#pragma peephole on
#pragma no_branch_likely off
#pragma schedule off
/* measured: schedule and no_branch_likely bracket retained around func_003e25f0. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003E25F0
u8 *func_003e25f0(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_00764878];
    if (v != 0) {
        func_003e12f0((void *)v);
    }
    D_0076487C--;
    return arg0;
}
/* measured: closes the schedule/no_branch_likely bracket opened above
   func_003e25f0; the explicit opposite state is required by the functions
   that follow. */
#pragma no_branch_likely off
/* measured: closes the function pragma bracket. */
#pragma schedule off
/* measured: no_branch_likely plus schedule probe for func_003e2650. */
#pragma no_branch_likely on
#pragma schedule on
extern u8 *func_003e2650(u8 *arg0, s32 arg1, u32 arg2); /* P4: ported verbatim into src/renderware */
/* measured: closes no_branch_likely plus schedule probe for func_003e2650. */
#pragma schedule off
#pragma no_branch_likely off

/* measured: schedule on fills the jr delay slot and the alignment nop after
   the filled back-edge, and no_branch_likely on preserves the plain beq/bne
   shape for the linked-list search. */
// FUN_003E3110 NONMATCHING
#ifdef NON_MATCHING
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
s32 func_003deea0(); /* extern */
s32 func_003df050();      /* extern */
M2C_UNK func_003df4d0();                       /* extern */
s32 func_003df590();                         /* extern */
s32 func_003e2ce0();                        /* extern */
u8 *func_003e3110(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sp5C;
    u32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 (*temp_2)(s32, s32, s32, s32, s32);
    s32 (*temp_2_3)(s32, s32, s32);
    s32 temp_2_2;
    u8 *var_17;
    u8 *var_8;

    if (func_003df050(arg1, 3, &sp5C, &sp58) != 0) {
        if ((sp58 >= 0x35000U) && (sp58 < 0x37003U)) {
            if (sp5C == 0) {
                goto block_4;
            }
loop_9:
            if (func_003deea0(arg1, &sp54, &sp50, 0, 0) == 0) {
                goto block_27;
            }
            var_8 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x10));
            if (var_8 != NULL) {
loop_13:
                if (M2C_FIELD(var_8, s32 *, 8) != sp54) {
                    var_8 = (u8 *)(M2C_FIELD(var_8, u8 **, 0x30));
                    if (var_8 != NULL) {
                        goto loop_13;
                    }
                }
            }
            if (var_8 != NULL) {
                temp_2 = (s32 (*)(s32, s32, s32, s32, s32))(M2C_FIELD(var_8, s32 (**)(s32, s32, s32, s32, s32), 0xC));
                if (temp_2 != NULL) {
                    if (temp_2(arg1, sp50, arg2, M2C_FIELD(var_8, s32 *, 0), M2C_FIELD(var_8, s32 *, 4)) == 0) {
                        goto block_27;
                    }
                    goto block_19;
                }
            }
            if (func_003e2ce0(arg1, sp50) == 0) {
                goto block_27;
            }
block_19:
            temp_2_2 = sp5C - (sp50 + 0xC);
            sp5C = temp_2_2;
            if (temp_2_2 == 0) {
block_4:
                var_17 = (u8 *)(M2C_FIELD(arg0, u8 **, 0x10));
                if (var_17 != NULL) {
loop_5:
                    temp_2_3 = (s32 (*)(s32, s32, s32))(M2C_FIELD(var_17, s32 (**)(s32, s32, s32), 0x18));
                    if ((temp_2_3 != NULL) && (temp_2_3(arg2, M2C_FIELD(var_17, s32 *, 0), M2C_FIELD(var_17, s32 *, 4)) == 0)) {
                        goto block_27;
                    }
                    var_17 = (u8 *)(M2C_FIELD(var_17, u8 **, 0x30));
                    if (var_17 == NULL) {
                        goto block_25;
                    }
                    goto loop_5;
                }
block_25:
                return (u8 *)(arg0);
            }
            goto loop_9;
        }
        sp48 = 1;
        sp4C = func_003df590(0x80000004);
        func_003df4d0(&sp48);
        goto block_27;
    }
block_27:
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3110);
#endif

// FUN_003E3630
/* measured: schedule bracket retained for func_003e3630. */
#pragma schedule on
s32 func_003e3630(void) {
    s32 r;
    r = func_003e1220(0x3C, D_00763C68, 4, D_00763C6C, D_00887250, 0x40000);
    D_00764888 = r;
    if (r != 0) {
        D_00764884 = 0;
        return 1;
    }
    return 0;
}
/* measured: closes the schedule bracket opened above func_003e3630; the
   explicit opposite state is required by the functions that follow. */
#pragma schedule off
/* measured: tailcall on preserves the indirect jump while direct reloads of
   the state pointer retain retail's three stores. */
/* measured: schedule on places self preservation in the guard delay slot. */
#pragma schedule on
#pragma tailcall on
extern void func_003e3680(u8 *arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes the schedule bracket around func_003e3680. */
#pragma schedule off
/* measured: closes the single-function tailcall bracket. */
#pragma tailcall off
/* measured: schedule/no_branch_likely preserve the two callback-loop paths. */
#pragma schedule on
#pragma no_branch_likely on
extern u8 *func_003e3b70(u8 *arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes schedule/no_branch_likely around func_003e3b70. */
#pragma no_branch_likely off
#pragma schedule off

#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e3c90 bracket. */
#pragma no_branch_likely on
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: opt_propagation off and explicit fallback labels preserve the
   retail repeated base materialisation and out-of-line defaults. */
#pragma opt_propagation off
/* measured: schedule on fills each fallback branch delay slot. */
#pragma schedule on
/* measured: no_branch_likely on preserves the retail plain beqz guards. */
#pragma no_branch_likely on
typedef u8 *(*Fn3f80A)(u8 *, u8 *, u8 *);
typedef u8 *(*Fn3f80B)(u8 *, s32, u8 *);
extern s32 func_003e3f80(Fn3f80A arg0, Fn3f80B arg1, Fn3f80A arg2, Fn3f80B arg3); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: close schedule around func_003e3f80. */
#pragma schedule off
#pragma opt_propagation on
/* measured: plain bc1t required for 003e4030. */
/* measured: optimization_level 3 probe for 003e4030. */
#pragma optimization_level 3
// FUN_003E4030 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4030);
/* measured: best reconstruction archived in build/E3E_003e4030_body.c at
   normalized_diff 51, object 108B / window 128B; math byte-exact through the
   FMA chain, sole residual is b210 hoisting mtc1 zero,$f1 above the FMAs
   (len kept in $f0) which no probed source shape reproduces. */
// FUN_003E40B0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e40b0);

/* measured: optimization_level 3 is load-bearing for func_003e4180. */
#pragma optimization_level 3
// FUN_003E4180
/* measured: ordinary COP1 MAC lowering is plain-C matchable; this staged
   accumulator spelling follows retail's y*y, x*x, z*z order. */
f32 func_003e4180(f32 *arg0) {
    f32 result;
    result = arg0[1] * arg0[1];
    result += arg0[0] * arg0[0];
    result += arg0[2] * arg0[2];
    return sqrtf(result);
}
/* measured: closes optimization_level 3 around func_003e4180. */
#pragma optimization_level 2

/* measured: optimization_level 3 is load-bearing for func_003e41b0. */
#pragma optimization_level 3
// FUN_003E41B0
/* measured: ordinary COP1 MAC lowering is plain-C matchable; retain the
   two-dimensional y*y then x*x accumulator order from retail. */
f32 func_003e41b0(f32 *arg0) {
    f32 result;
    result = arg0[1] * arg0[1];
    result += arg0[0] * arg0[0];
    return sqrtf(result);
}
/* measured: closes optimization_level 3 around func_003e41b0. */
#pragma optimization_level 2

// FUN_003E41E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e41e0);

/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off
/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: schedule on places the GP decrement in the jr delay slot. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: schedule-on callback initializer matches object 84B/window 96B,
   normalized_diff 0; direct callback stores reproduce retail order. */
#pragma schedule on
// FUN_003E43C0
s32 func_003e43c0(s32 arg0, s32 arg1) {
    D_00764890 = arg1;
    *(Fn3f80A *)((u8 *)D_008872E0 + D_00764890 + 8) =
        (Fn3f80A)func_003e3dc0;
    *(Fn3f80B *)((u8 *)D_008872E0 + D_00764890 + 0xC) =
        (Fn3f80B)func_003e3d00;
    *(Fn3f80A *)((u8 *)D_008872E0 + D_00764890 + 0x10) =
        (Fn3f80A)func_003e3f00;
    *(Fn3f80B *)((u8 *)D_008872E0 + D_00764890 + 0x14) =
        (Fn3f80B)func_003e3e60;
    iGpffffb7a4 += 1;
    return arg0;
}
/* measured: closes schedule-on callback initializer, object 84B/window 96B,
   normalized_diff 0. */
#pragma schedule off

/* measured: same out-of-line-body shape as func_003e59e0 - retail branches to
   the initialisation block and falls into the early `return 0`, so the goto
   graph is needed and the plain `if (size < 0x20) return 0;` form is not
   (nd 23 with it). schedule on fills the branch delay slot with the first store
   as retail does, and no_branch_likely is then needed to stop b210 turning the
   test into a beql, which was the last differing word. */

/* measured: schedule/no_branch_likely preserve the explicit fallback block. */
#pragma schedule on
#pragma no_branch_likely on
extern void func_003e4420(u8 *arg0, u32 arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes schedule/no_branch_likely around func_003e4420. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: schedule/no_branch_likely bracket retained for func_003e44b0. */
#pragma schedule on
#pragma no_branch_likely on
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E4510
s32 func_003e4510(void) {
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

// measured: removing this pragma takes func_003e5510 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x5478($gp); baseline -O2 emits sw; jr; nop.

/* measured: discarded nonvolatile candidate nd 31, object 120/128; the nd 0
   volatile spelling is rejected by H001 (ordinary-data compiler steering). */

/* measured: schedule/no-branch-likely probe for func_003e4520. */
#pragma no_branch_likely on
#pragma schedule on
/* measured: closes schedule/no-branch-likely probe around func_003e4520. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule/no_branch_likely bracket retained for func_003e4880. */
#pragma schedule on
#pragma no_branch_likely on
extern s8 *func_003e4880(s8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule on plus no_branch_likely on. schedule alone gets nd 26
   (retail fills the loop's branch delay slots), and b210 then wants beql/bnel
   where retail has plain bne/bnez, which is the rest of it. */
/* measured: schedule/no_branch_likely bracket retained for func_003e48d0. */
#pragma schedule on
#pragma no_branch_likely on
extern s8 *func_003e48d0(s8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* Parked candidate: the string-search loop and sign-extension sequence are
   structurally right, but b210 keeps the found-pointer value in the wrong
   temporary registers and shifts the equality branch. Residual
   normalized_diff 23. Committed at nd 23. */
/* measured: string-search candidates remain nonmatching (best active probe
   object 56B/window 64B, normalized_diff 10); restored assembly fallback. */
/* measured: last-byte-search reconstruction remains a 64-byte object with
   normalized_diff 10-16 across typed pointer, explicit key, and O1 probes;
   restored assembly fallback. */
/* measured: last-byte search candidate object 52B/window 64B,
   normalized_diff 9; signed-key prologue matches, but delayed pointer
   sign-extension and loop-exit scheduling remain unresolved. */

#pragma schedule on
#pragma schedule off
/* Best candidate archived at build/F3E_003e49a0_body.c: normalized_diff 94,
   object 220 / window 288 -- undersized, so the table init is incomplete. */

// FUN_003E4AC0
void func_003e4ac0(void)
{
}

/* measured: schedule on is load-bearing (nd 55 without it, and the object
   overflows the window at 84 bytes); the default-argument substitution is
   reached by goto so it lands out of line after the call, as retail has it. */
/* measured: schedule bracket retained for func_003e4ad0. */
#pragma schedule on
extern s32 func_003e4ad0(char *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma schedule off

/* measured: schedule on + no_branch_likely on are load-bearing for this body
   (nd 76 without them) - they place result=0 in the beqz  delay slot and
   keep the arg0[1]==0x3A test's xori/sltiu out of a branch-likely. */

// FUN_003E4BE0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4be0);

// FUN_003E4D80
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4d80);

// FUN_003E50A0
/* measured: schedule/no_branch_likely bracket retained for func_003e50a0. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e50a0(s8 *arg0) {
    s32 result = 0;
    if (arg0 != 0) {
        s32 flag = 1;
        if (arg0[0] != 0x5C) {
            s32 cond = (D_00754D88[arg0[0]] & 3) != 0;
            if (cond) {
                cond = (arg0[1] == 0x3A);
            }
            if (!cond) {
                flag = 0;
            }
        }
        if (flag) {
            result = 1;
        }
    }
    return result;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: optimization_level 3 is load-bearing for func_003e5220/5250. */
#pragma optimization_level 3
// FUN_003E5220
#pragma tailcall on
void func_003e5220(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003e3020(D_0070B710, arg0, arg1, arg2, arg3);
}
/* measured: closes the function pragma bracket. */
#pragma tailcall off

/* measured: disabling propagation keeps the 0x2C offset in s16 across the
   loader call, reproducing retail's sq/lq frame and post-call addu. */
#pragma opt_propagation off
extern s32 func_003e5250(s32 arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the single-function propagation bracket for func_003e5250. */
#pragma opt_propagation on
/* measured: closes optimization_level 3 around func_003e5220/5250. */
#pragma optimization_level 2

#pragma schedule on
#pragma no_branch_likely on
#pragma no_branch_likely off
#pragma schedule off
/* measured: optimization_level 3 is load-bearing for func_003e5510. */
#pragma optimization_level 3
// FUN_003E5510
void func_003e5510(s32 arg0) {
    D_00886700 = arg0;
}
/* measured: closes optimization_level 3 around func_003e5510. */
#pragma optimization_level 2

// measured: removing this pragma takes func_003e6750 nd 0 -> nd 15: retail fills the
// jr $ra delay slot with sw $v1, ($a1) and hoists move $v0,$a0 before the addiu;
// baseline -O2 emits lw; addiu; sw; move; jr; nop.

/* measured: the m2c draft advanced the s32* cursor by 4 ELEMENTS (16 bytes)
   where retail advances one element; with `p++` the loop body, the found-exit
   `*arg2 = i; return 1` and the count/limit registers are all correct and the
   object is exactly the 80-byte window without any scheduling pragma (nd 43).
   Two residuals remain: retail materialises the entry guard as
   `slt $at,$zero,$v1; beqz $at` where b210 emits a single `blez` for `n > 0`,
   `0 < n` and `!(n <= 0)` alike, and retail's in-loop mismatch test is a plain
   `bne` + nop while b210 wants `bnel`. Adding no_branch_likely fixes the
   second but costs the first (nd 49); schedule on shrinks the object to
   64 bytes (nd 46). Entry-guard materialisation floor.
   Committed at nd 43. */

/* measured: optimization_level 3 reproduces retail's argument-register
   materialisation for this direct wrapper. */
#pragma optimization_level 3
// FUN_003E5520
/* measured: tailcall knob retains the func_003e5520 bracket. */
#pragma tailcall on
void func_003e5520(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003e3020(D_0070B7A0, arg0, arg1, arg2, arg3);
}
/* measured: closes the function pragma bracket. */
#pragma tailcall off
/* measured: closes optimization_level 3 around func_003e5520. */
#pragma optimization_level 2

/* measured: schedule on moves the saved input into the initial guard delay
   slot and preserves retail's recursive call delay slots. */
#pragma schedule on
/* measured: no_branch_likely on keeps each NULL-child branch plain, as in
   the retail recursive walk. */
#pragma no_branch_likely on
extern s32 func_003e5550(u8 ***arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: closes the schedule bracket opened above func_003e5550. */
#pragma schedule off

/* measured: best plain-C body archived in build/H3E2_003e5990_body.c;
   object 80B/window 80B, normalized_diff 42; guard and return layout remain. */

/* measured: two things are load-bearing here. Retail tests POSITIVELY and puts
   the indirect call out of line after the return path, then jumps back to it -
   the plain `if (cond) { call(); } return arg0;` form compiles inline with a
   negated skip and scores nd 31, while the goto graph below is exact. And the
   jal and branch delay slots are filled, which needs schedule on. */
/* measured: schedule bracket retained for func_003e59e0. */
#pragma schedule on
extern u8 *func_003e59e0(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: schedule on is load-bearing - it hoists move $s1,$a0 before the
   first call and fills each jal delay slot with the running-total addu. */

/* measured: optimization_level 3 reproduces retail's argument-register
   materialisation for this direct wrapper. */
#pragma optimization_level 3
// FUN_003E6210
/* measured: tailcall knob retains the func_003e6210 bracket. */
#pragma tailcall on
void func_003e6210(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003e3020((u8 *)D_0070B800, arg0, arg1, arg2, arg3);
}
/* measured: closes the function pragma bracket. */
#pragma tailcall off
/* measured: closes optimization_level 3 around func_003e6210. */
#pragma optimization_level 2
#pragma schedule on
/* measured: closes the function pragma bracket. */
#pragma schedule off

/* measured: optimization_level 3 is load-bearing for func_003e66c0/6750. */
#pragma optimization_level 3
// FUN_003E66C0
typedef u8 *(*Callback66c0)(u8 *, u8 *);
extern s32 (*D_0088738C[])(s32 *, Callback66c0, s32);
/* measured: no_branch_likely knob retains the func_003e66c0 bracket. */
#pragma no_branch_likely on
Callback66c0 func_003e66c0(Callback66c0 arg0, u8 *arg1)
{
    s32 sp3C;

    if (D_0088738C[0](&sp3C, arg0, 0) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return NULL;
    }
    *(s32 *)arg1 += sp3C + 0xC;
    *(s32 *)arg1 += func_003e3370((u8 *)D_0070B800, (s32)arg0) + 0xC;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
// FUN_003E6750
s32 func_003e6750(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* MATCHED: object 252B / retail window 256B / normalized_diff 0. The
   D_00887394 callback's third parameter must be u32 (not s32); that
   prototype signedness flips the two residual load-order words at offsets
   148 and 152 without any volatile barrier. Probed direct locals, named
   argument assignments, comma ordering, pragma toggles, callback prototypes,
   and pointer/cast variants. */
// FUN_003E6770
/* measured: optimization_level 3 is load-bearing for func_003e6770. */
#pragma optimization_level 3
typedef u8 *(*Callback6770)(u8 *, u8 *);
extern s32 (*D_0088738C[])(s32 *, Callback6770, s32);
extern s32 (*D_00887394[])(s32, Callback6770, u32);
extern s32 func_003deff0(s32, s32, s32, s32, s32);
extern u8 *func_003e33f0(u8 *, s32, Callback6770);
/* measured: no_branch_likely knob retains the func_003e6770 bracket. */
#pragma no_branch_likely on
Callback6770 func_003e6770(Callback6770 arg0, u8 *arg1)
{
    s32 sp3C;
    if (D_0088738C[0](&sp3C, arg0, 0) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return NULL;
    }
    sp3C += func_003e3370((u8 *)D_0070B800, (s32)arg0) + 0xC;
    if (func_003deff0(*(s32 *)arg1, 0x15, sp3C, 0x37002, 0x37) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return NULL;
    }
    if (D_00887394[0](*(s32 *)arg1, arg0, sp3C) == 0) {
        *(s32 *)(arg1 + 4) = 0;
        return NULL;
    }
    if (func_003e33f0((u8 *)D_0070B800, *(s32 *)arg1, arg0) != 0) {
        return arg0;
    }
    *(s32 *)(arg1 + 4) = 0;
    return NULL;
}
/* measured: closes no_branch_likely and optimization_level 3 for func_003e6770. */
#pragma no_branch_likely off
#pragma optimization_level 2

/* measured: optimization_level 3 is load-bearing for func_003e6a60. */
#pragma optimization_level 3
// FUN_003E6A60
s32 func_003e6a60(s32 arg0) {
    func_003ef3a0();
    return arg0;
}
/* measured: closes optimization_level 3 around func_003e6a60. */
#pragma optimization_level 2

// FUN_003E6E70
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6e70);

// FUN_003E7810
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7810);

#pragma optimization_level 3
extern u8 *func_003e7ee0(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2

/* measured: schedule+no_branch_likely load-bearing; flipped guard polarity so
   the D_008872E0=0 work lands out of line after the early return 0. */
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e7f50 bracket. */
#pragma no_branch_likely on
extern s32 func_003e7f50(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule+no_branch_likely load-bearing - schedule puts the
   D_008872E0 store in the func_003ed7e0 jal delay slot. */
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e7fb0 bracket. */
#pragma no_branch_likely on
extern s32 func_003e7fb0(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule+no_branch_likely load-bearing, same shape as func_003e25f0
   but with a D_008872E0[D_007648A0]=0 store inside the guard. */
// FUN_003E8010
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e8010 bracket. */
#pragma no_branch_likely on
u8 *func_003e8010(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_007648A0];
    if (v != 0) {
        func_003e12f0((void *)v);
        *(s32 *)&D_008872E0[D_007648A0] = 0;
    }
    D_007648A4--;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: the reload of the slot before the branch is a store-to-load forwarding
   that b210 does as a peephole; peephole off keeps it (the archive needed volatile). */
#pragma schedule on
#pragma no_branch_likely on
#pragma peephole off
extern s32 func_003e8080(s32 arg0, s32 arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes the peephole/no_branch_likely/schedule bracket for func_003e8080. */
#pragma peephole on
#pragma no_branch_likely off
#pragma schedule off
/* measured: H001 rejects volatile-only exactness; nonvolatile best body is object 124B/window 144B, normalized_diff 17. */

/* measured: best plain-C body is archived in build/H3E2_003e8130_body.c;
   object 76B/window 80B, normalized_diff 24, prologue load order remains. */
/* measured: no_branch_likely on forces the retail beqz+nop shape. */
#pragma no_branch_likely on
#pragma optimization_level 3
extern u8 *func_003e8180(u8 *arg0, f32 fparg0); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
#pragma no_branch_likely off

#pragma optimization_level 3
/* measured: no_branch_likely on forces the retail beqz+nop shape. */
#pragma no_branch_likely on
extern u8 *func_003e81c0(u8 *arg0, f32 fparg0); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
#pragma no_branch_likely off

/* measured: no_branch_likely on preserves 8310's plain comparison branches. */
#pragma no_branch_likely on
#pragma optimization_level 3
extern u8 *func_003e8310(u8 *arg0, s32 arg1); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
#pragma no_branch_likely off

/* measured: optimization_level 3 is load-bearing for func_003e8410. */
#pragma optimization_level 3
// FUN_003E8410
#pragma tailcall on
void func_003e8410(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_003e3870(D_0070B710, arg0, arg1, arg2, arg3, arg4);
}
/* measured: closes optimization_level 3 around func_003e8410. */
#pragma optimization_level 2
#pragma tailcall off

#pragma optimization_level 3
#pragma schedule on
extern s32 func_003e8440(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
/* measured: closes the schedule bracket opened above and restores the
   translation-unit baseline. */
#pragma schedule off

#pragma optimization_level 3
/* measured: schedule-on probe for 003e84a0 prologue and store ordering. */
#pragma schedule on
/* measured: no_branch_likely-on probe restores retail's plain null test. */
#pragma no_branch_likely on
extern u8 *func_003e84a0(void); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
#pragma no_branch_likely off
/* measured: closes schedule inside func_003e84a0. */
#pragma schedule off

// FUN_003E85A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e85a0);

/* measured: opt_propagation off tests retaining table-address materialisation before the argument load. */
#pragma opt_propagation off
/* measured: tailcall on emits the retail jr-v0 wrapper for the table fetch. */
#pragma tailcall on
#pragma optimization_level 3
extern void *func_003e8790(void *arg0, s32 arg1); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
/* measured: closes the single-function tailcall bracket. */
/* measured: closes the opt_propagation bracket for func_003e8790. */
#pragma opt_propagation on
#pragma tailcall off

/* measured: schedule on hoists the callback table load before saving self. */
#pragma schedule on
#pragma optimization_level 3
extern u8 *func_003e87b0(u8 *arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: optimization_level 3 is load-bearing for func_003e8910. */
#pragma optimization_level 3
// FUN_003E8910
/* measured: schedule on places the GP load in the jr delay slot. */
#pragma schedule on
s32 func_003e8910(void) {
    return iGpffffb7b8;
}
/* measured: closes optimization_level 3 around func_003e8910. */
#pragma optimization_level 2
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

/* measured: optimization_level 3 reproduces retail's argument-register
   materialisation for this direct wrapper. */
#pragma optimization_level 3
/* measured: tailcall knob retains the func_003e8930 bracket. */
#pragma tailcall on
extern void func_003e8930(s32 arg0, s32 arg1, s32 arg2, s32 arg3); /* P4: ported verbatim into src/renderware */
/* measured: closes the function pragma bracket. */
#pragma tailcall off
#pragma optimization_level 2
/* measured: probe typed tailcall for global-base forwarding wrapper. */
#pragma schedule on
#pragma tailcall on
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off
/* measured: old-style loader ABI plus schedule/no_branch_likely preserve the
   hidden fifth argument, saved result pointer and plain success branch. */
#pragma no_branch_likely on
#pragma schedule on
extern s32 *func_003e8970(s32 *arg0, s32 arg1); /* P4: ported verbatim into src/renderware */
/* measured: closes schedule/no_branch_likely around func_003e8970. */
#pragma schedule off
#pragma no_branch_likely off
/* measured: old-style loader ABI and schedule on preserve the stack output
   pointer plus hidden fifth argument in the 80-byte retail wrapper. */
/* measured: no_branch_likely on restores retail's plain beqz and shared
   return block. */
#pragma no_branch_likely on
#pragma schedule on
extern s32 func_003e89c0(void); /* P4: ported verbatim into src/renderware */
/* measured: closes the single-function schedule bracket. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: schedule on preserves the five-argument loader call and boolean
   result in the 64-byte retail wrapper. */
#pragma schedule on
/* measured: closes the single-function schedule bracket. */
#pragma schedule off
/* measured: the reload of the slot before the branch is a store-to-load forwarding
   that b210 does as a peephole; peephole off keeps it (the archive left this open).
   Under peephole off the redundant-lui merge is gone too, so the list head is
   written through a pointer local and D_008873A0 through its own symbol. */
#pragma schedule on
#pragma no_branch_likely on
#pragma peephole off
// FUN_003E8DC0
s32 func_003e8dc0(s32 arg0, s32 arg1)
{
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);
    extern s32 iGpffffab94;
    extern s32 iGpffffab98;
    extern u8 D_0088B2E0[];
    extern u8 *D_0088739C[];
    extern u8 *D_008873A0[];
    s32 *slot;
    s32 result;
    u8 *head;

    iGpffffb7c0 = arg1;
    result = func_003e1220(*(s32 *)D_0070B7A0, iGpffffab94, 0x10, iGpffffab98, D_0088B2E0, 0x4000E);
    slot = (s32 *)(D_008872E0 + iGpffffb7c0);
    *slot = result;
    result = *slot;
    if (result == 0) {
        return 0;
    }
    head = (u8 *)D_0088739C;
    D_008873A0[0] = head;
    *(u8 **)head = head;
    iGpffffb7c4 += 1;
    return arg0;
}
/* measured: closes the peephole/no_branch_likely/schedule bracket for func_003e8dc0. */
#pragma peephole on
#pragma no_branch_likely off
#pragma schedule off
// FUN_003E8E60
/* measured: schedule/no_branch_likely bracket retained for func_003e8e60. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003e8e60(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb7c0);
    if (p != NULL) {
        func_003e12f0(p);
        *(u8 **)(D_008872E0 + iGpffffb7c0) = NULL;
    }
    iGpffffb7c4 -= 1;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket opened above and restores the
   translation-unit baseline. */
#pragma schedule off
/* measured: schedule on and no_branch_likely on reproduce the retail
   incoming-a0/second-argument call to func_003e8f80 and the plain branch.
   This exact cleaned M2C shape compiles MATCH at nd 0. */
/* measured: schedule/no_branch_likely bracket retained for func_003e90f0. */
#pragma schedule on
#pragma no_branch_likely on
extern s32 *func_003e90f0(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: closes schedule around func_003e90f0. */
#pragma schedule off
/* measured: schedule on probe for func_003e9140's branch-delay and call order. */
#pragma schedule on
/* measured: no_branch_likely on pairs with schedule for func_003e9140. */
#pragma no_branch_likely on
/* measured: close schedule on around func_003e9140. */
#pragma no_branch_likely off
#pragma schedule off
