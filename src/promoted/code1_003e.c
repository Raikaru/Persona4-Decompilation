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
void func_003e12f0(s32);
s32 func_003e1740(u8 *);
void func_003e1230(void *);
void func_003ed7e0(void);
void func_00410f40(s32);
u8 *func_003e1cb0(u8 *, void *);
void func_003e3dc0();
void func_003e3d00();
void func_003e3f00();
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


// measured: removing this pragma takes func_003e05d0 nd 0 -> nd 16: retail fills the
// jr $ra delay slot with sw $v1, 0xc($a0) and hoists move $v0,$a0 before the and;
// baseline -O2 emits lw; lui; ori; and; sw; move; jr; nop.

/* measured: no_branch_likely on reproduces the retail beqz/nop and
   shared address-calculation block for the NULL callback fallback. */
#pragma no_branch_likely on
/* measured: schedule on probe for the retail constant/address order. */
#pragma schedule on
// FUN_003E00F0
s32 func_003e00f0(Callback003e arg0) {
    u8 *globals;
    s32 result;
    if (arg0 == (Callback003e)0) {
        goto fallback;
    }
store:
    globals = (u8 *)D_008872E0 + (s32)iGpffffb768;
    result = 1;
    *(Callback003e *)(globals + 8) = arg0;
    return result;
fallback:
    arg0 = func_003df8c0;
    goto store;
}
#pragma schedule off
/* measured: close no_branch_likely around func_003e00f0. */
#pragma no_branch_likely off
// FUN_003E0130
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0130);
// FUN_003E0180
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0180);
// FUN_003E01E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e01e0);
// FUN_003E0250
/* measured: schedule bracket retained for func_003e0250. */
#pragma schedule on
/* measured: no_branch_likely on preserves func_003e0250 retail beqz. */
#pragma no_branch_likely on
u8 *func_003e0250(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + (s32)iGpffffb768);
    if (p != NULL) {
        func_003e12f0((s32)p);
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
// FUN_003E02C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e02c0);
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

// FUN_003E03B0
/* measured: use the same registered scalar and absolute array domain as the
   getter; retaining the true return value reproduces retail's addiu v0,1. */
/* measured: open the one-function optimization probe for func_003e03b0. */
#pragma optimization_level 3
s32 func_003e03b0(const MatrixTolerance003e *arg0) {
    u8 *globals;
    s32 result;
    globals = (u8 *)D_008872E0 + (s32)iGpffffb768;
    result = 1;
    *(MatrixTolerance003e *)(globals + 0xc) = *arg0;
    return result;
}
/* measured: close the one-function optimization probe for func_003e03b0. */
#pragma optimization_level 2
// FUN_003E03E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e03e0);
/* measured: open O3 only for func_003e05d0; do not span promoted stubs. */
#pragma optimization_level 3
// FUN_003E05D0
u8 *RwMatrixUpdate(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) &= 0xFFFDFFFC;
    return arg0;
}
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

// FUN_003E0960
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0960);

// FUN_003E0A90
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0a90);

// FUN_003E0C90
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0c90);

// FUN_003E0E20
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0e20);

// FUN_003E0F40
/* measured: schedule on preserves the callback load in the jalr delay slot. */
#pragma schedule on
s32 func_003e0f40(u8 *arg0) {
    u8 *base;
    base = D_008872E0 + (s32)iGpffffb768;
    jtbl_008873FC[0](*(u8 **)base, arg0);
    return 1;
}
/* measured: closes the single-function schedule bracket for func_003e0f40. */
#pragma schedule off

/* A schedule-on reconstruction for func_003e0f80 was three spellings short
   of the retail callback-load order and was removed after the probe limit. */
// FUN_003E0F80
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e0f80);
// measured: removing this pragma takes func_003e1020 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x54a0($gp); baseline -O2 emits sw; jr; nop.

#pragma optimization_level 3
// FUN_003E1020
void func_003e1020(s32 arg0) {
    D_008866D8 = arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2



/* measured: the circular-list sum reconstruction for func_003e1a70 stalled
   at nd 45 in its 112B window: register colouring and the entry comparison
   (`slt`/`beqz` versus b210's `blez`) remain. This exceeds the park threshold,
   so the bare INCLUDE_ASM fallback remains. */

// FUN_003E1030
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1030);

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
// FUN_003E1230
void func_003e1230(void *arg0) {
    u8 *self;
    u8 *node;
    u8 *next;
    u8 *prev;
    u8 *sentinel;
    s32 temp;
    void (**callback)(u8 *);
    extern s32 iGpffffb774;

    self = (u8 *)arg0;
    node = *(u8 **)(self + 0x10);
    sentinel = self + 0x10;
    if (node != sentinel) {
        callback = jtbl_008873EC;
        do {
            next = *(u8 **)node;
            prev = *(u8 **)(node + 4);
            *(u8 **)prev = next;
            prev = *(u8 **)(node + 4);
            next = *(u8 **)node;
            *(u8 **)(next + 4) = prev;
            (*callback)(node);
            node = *(u8 **)(self + 0x10);
            sentinel = self + 0x10;
        } while (node != sentinel);
    }
    if ((*(s32 *)(self + 0x18) & 1) == 0) {
        temp = iGpffffb774;
        if (temp != (s32)self && temp != 0) {
            jtbl_008873FC[0]((u8 *)temp, self);
            return;
        }
        jtbl_008873EC[0](self);
    }
}
/* measured: close no_branch_likely/schedule around func_003e1230. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003E12F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e12f0);

// FUN_003E13D0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e13d0);

// FUN_003E15A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e15a0);

// FUN_003E1740
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1740);

// FUN_003E18C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e18c0);

/* measured: sentinel-list sum candidate object 96B/window 112B,
   normalized_diff 18; prologue/registers match but branch and loop-exit
   shape remain unresolved. */
// FUN_003E1A70
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1a70);

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

// FUN_003E1B10
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1b10);
// FUN_003E1C30
/* measured: schedule/no_branch_likely bracket retained for func_003e1c30. */
#pragma schedule on
#pragma no_branch_likely on
void func_003e1c30(void) {
    void **node = (void **)D_00764868;
    if (node != (void **)&D_00764868) {
        do {
            ((void **)node[1])[0] = node[0];
            ((void **)node[0])[1] = node[1];
            func_003e1230((u8 *)node - 0x1C);
            node = (void **)D_00764868;
        } while (node != (void **)&D_00764868);
    }
    {
        u8 *obj = (u8 *)D_00764864;
        ((void **) *(void **)(obj + 0x20))[0] = *(void **)(obj + 0x1C);
        ((void **) *(void **)(obj + 0x1C))[1] = *(void **)(obj + 0x20);
        func_003e1230(obj);
    }
    D_00764864 = 0;
    D_00764860 = 0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003E1CB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1cb0);
// FUN_003E1DB0
/* measured: no_branch_likely keeps the success test as retail's plain bnez. */
#pragma no_branch_likely on
#pragma schedule on
s32 func_003e1db0(u8 *arg0, s32 arg1) {
    D_00724870 = arg1;
    if (func_003e1cb0(D_008872E0 + arg1, D_00887408[0]) == 0) {
        return 0;
    }
    D_00764874++;
    return (s32)arg0;
}
// FUN_003E1E10
extern s32 iGpffffb780;
s32 func_003e1e10(s32 arg0)
{
    u8 *temp;

    func_003e2430();
    temp = *(u8 **)(D_008872E0 + (s32)iGpffffb780 + 0xC);
    if (temp != NULL) {
        func_003e4510(temp);
        jtbl_008873EC[0](*(u8 **)(D_008872E0 + (s32)iGpffffb780 + 0xC));
        *(s32 *)(D_008872E0 + (s32)iGpffffb780 + 0xC) = 0;
    }
    D_00764874 -= 1;
    return arg0;
}
/* measured: closes no_branch_likely/schedule around func_003e1e10. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003E1EA0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1ea0);

// FUN_003E1F50
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1f50);

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

/* measured: running-sum reconstruction remains object 68B/window 80B with
   normalized_diff 6-7; missing terminal nop is unresolved. */
// FUN_003E23E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e23e0);

/* measured: discarded nonvolatile candidate nd 31, object 120/128; the nd 0
   volatile spelling is rejected by H001 (ordinary-data compiler steering). */

// FUN_003E2430
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2430);
/* measured: registration worker reconstruction reaches object 120B/window
   128B, normalized_diff 14; store/reload and branch-delay order unresolved. */
// FUN_003E2570
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2570);
/* measured: schedule and no_branch_likely bracket retained around func_003e25f0. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003E25F0
u8 *func_003e25f0(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_00764878];
    if (v != 0) {
        func_003e12f0(v);
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
// FUN_003E2650
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2650);

// FUN_003E2750
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2750);

// FUN_003E2800
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2800);

// FUN_003E2910
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2910);

// FUN_003E2AB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2ab0);

// FUN_003E2CE0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2ce0);

// FUN_003E2E40
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2e40);

// FUN_003E2F60
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2f60);








/* measured: linked-list search/store reconstruction reaches object 80B/window
   80B, normalized_diff 16-20; retail's two loop-exit nops are unresolved. */
// FUN_003E3020
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3020);

/* measured: linked-list search/store reconstruction reaches object 72B/window
   80B, normalized_diff 16; branch/delay-slot sequence remains unresolved. */
// FUN_003E3070
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3070);

/* measured: linked-list search/store reconstruction reaches object 72B/window
   80B, normalized_diff 16; loop-exit nop and delay-slot sequence remain
   unresolved. */
// FUN_003E30C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e30c0);

// FUN_003E3110
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3110);
// FUN_003E32F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e32f0);

/* measured: recovered guarded body scores nd 22 at object 120/window 128.
   Every emitted instruction is right, but retail has one extra nop between
   the loop-exit branch and `move $v0, $s1`, shifting the epilogue by one word.
   do-while, while, explicit-goto, empty-statement and label probes remain
   nd 22-23 under schedule+no_branch_likely; schedule alone costs nd 32.
   This is the same loop-exit block-join artifact as func_003e3020. Committed at nd 22. */
// FUN_003E3370 NONMATCHING
#ifdef NON_MATCHING
/* measured: probe schedule */
#pragma schedule on
/* measured: probe branch form */
#pragma no_branch_likely on
s32 func_003e3370(u8 *arg0, s32 arg1)
{
    s32 (*fn)(s32, s32, s32);
    s32 got;
    s32 total;
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    total = 0;
    if (node != NULL) {
        do {
            fn = *(s32 (**)(s32, s32, s32))(node + 0x14);
            if (fn != NULL) {
                got = fn(arg1, *(s32 *)node, *(s32 *)(node + 4));
                if (got > 0) {
                    total += got + 0xC;
                }
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }

    return total;
}
/* measured: closes the bracket noted above the marker. */
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3370);
#endif

// FUN_003E33F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e33f0);
// FUN_003E3560
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3560);
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
// FUN_003E3680
void func_003e3680(u8 *arg0, u8 *arg1) {
    u8 *base;

    base = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(base + 0x10) != 0) {
        *(s32 *)base = *(s32 *)(base + 4);
        base = *(u8 **)(arg0 + 0x38);
        *(s32 *)(base + 0x10) = 0;
        base = *(u8 **)(arg0 + 0x38);
        *(s32 *)(base + 0x14) = 0;
    }
    jtbl_008873FC[0](arg1, arg0);
}
/* measured: closes the schedule bracket around func_003e3680. */
#pragma schedule off
/* measured: closes the single-function tailcall bracket. */
#pragma tailcall off
// FUN_003E36C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e36c0);
/* measured: archived linked-list reconstruction object 60B/window 64B,
   normalized_diff 7; branch-join delay scheduling remains unresolved. */
/* measured: linked-list search probes remain object 60-68B/window 64B,
   normalized_diff 7-10; branch-join scheduling unresolved. */
/* measured: archived explicit linked-list reconstruction object 56-68B/window
   64B, normalized_diff 7-10; branch-join scheduling remains unresolved. */
// FUN_003E3830
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3830);
// FUN_003E3870
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3870);
/* measured: schedule/no_branch_likely preserve the two callback-loop paths. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003E3B70
u8 *func_003e3b70(u8 *arg0, u8 *arg1) {
    u8 *node;
    s32 result;

    node = *(u8 **)(arg0 + 0x10);
    if (node == NULL) {
        goto return_arg0;
    }
first_loop:
    result = ((s32 (*)(s32, s32, s32))(*(s32 *)(node + 0x20)))(
        (s32)arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
    if (result == 0) {
        node = *(u8 **)(node + 0x34);
        if (node == NULL) {
            goto return_zero;
        }
second_loop:
        do {
            ((s32 (*)(s32, s32, s32))(*(s32 *)(node + 0x24)))(
                (s32)arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(u8 **)(node + 0x34);
        } while (node != NULL);
        goto return_zero;
    }
    node = *(u8 **)(node + 0x30);
    if (node != NULL) {
        goto first_loop;
    }
return_arg0:
    return arg0;
return_zero:
    return NULL;
}
/* measured: closes schedule/no_branch_likely around func_003e3b70. */
#pragma no_branch_likely off
#pragma schedule off


/* measured: callback-list loop candidate object 96B/window 112B,
   normalized_diff 12; all loop instructions match, but retail has one
   additional branch-join nop before the return. */
// FUN_003E3C20
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3c20);
// FUN_003E3C90
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e3c90 bracket. */
#pragma no_branch_likely on
s32 func_003e3c90(s32 arg0, s32 arg1, s32 arg2) {
    s32 node = *(s32 *)(arg0 + 0x10);
    if (node) {
        do {
            ((s32 (*)(s32, s32, s32, s32))(*(s32 *)(node + 0x28)))(arg1, arg2, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(s32 *)(node + 0x30);
        } while (node);
    }
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off


// FUN_003E3D00
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3d00);
// FUN_003E3DC0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3dc0);
// FUN_003E3E60
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3e60);
// FUN_003E3F00
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3f00);

// FUN_003E3F80
/* measured: opt_propagation off and explicit fallback labels preserve the
   retail repeated base materialisation and out-of-line defaults. */
#pragma opt_propagation off
/* measured: schedule on fills each fallback branch delay slot. */
#pragma schedule on
/* measured: no_branch_likely on preserves the retail plain beqz guards. */
#pragma no_branch_likely on
typedef u8 *(*Fn3f80A)(u8 *, u8 *, u8 *);
typedef u8 *(*Fn3f80B)(u8 *, s32, u8 *);
s32 func_003e3f80(Fn3f80A arg0, Fn3f80B arg1, Fn3f80A arg2, Fn3f80B arg3) {
    if (arg0 == NULL) {
        goto set0;
    }
store0:
    *(Fn3f80A *)((u8 *)D_008872E0 + D_00764890 + 8) = arg0;
    if (arg1 == NULL) {
        goto set1;
    }
store1:
    *(Fn3f80B *)((u8 *)D_008872E0 + D_00764890 + 0xC) = arg1;
    if (arg2 == NULL) {
        goto set2;
    }
store2:
    *(Fn3f80A *)((u8 *)D_008872E0 + D_00764890 + 0x10) = arg2;
    if (arg3 == NULL) {
        goto set3;
    }
store3:
    *(Fn3f80B *)((u8 *)D_008872E0 + D_00764890 + 0x14) = arg3;
    return 1;
set0:
    arg0 = (Fn3f80A)func_003e3dc0;
    goto store0;
set1:
    arg1 = (Fn3f80B)func_003e3d00;
    goto store1;
set2:
    arg2 = (Fn3f80A)func_003e3f00;
    goto store2;
set3:
    arg3 = (Fn3f80B)func_003e3e60;
    goto store3;
}
/* measured: close no_branch_likely around func_003e3f80. */
#pragma no_branch_likely off
/* measured: close schedule around func_003e3f80. */
#pragma schedule off
/* measured: close opt_propagation around func_003e3f80. */
#pragma opt_propagation on
// FUN_003E4030
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4030);


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

// FUN_003E42A0
/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
u8 *func_003e42a0(u8 *arg0) {
    u8 *base;
    base = D_008872E0 + D_00764890;
    ((void (*)(void))(*(void **)(base + 8)))();
    return arg0;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

// FUN_003E42E0
/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
u8 *func_003e42e0(u8 *arg0) {
    u8 *base;
    base = D_008872E0 + D_00764890;
    ((void (*)(void))(*(void **)(base + 0xC)))();
    return arg0;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

// FUN_003E4320
/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
u8 *func_003e4320(u8 *arg0) {
    u8 *base;
    base = D_008872E0 + D_00764890;
    ((void (*)(void))(*(void **)(base + 0x10)))();
    return arg0;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off
// FUN_003E4360
/* measured: schedule on places the saved self in the jalr delay slot. */
#pragma schedule on
u8 *func_003e4360(u8 *arg0) {
    u8 *base;
    base = D_008872E0 + D_00764890;
    ((void (*)(void))(*(void **)(base + 0x14)))();
    return arg0;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

// FUN_003E43A0
/* measured: schedule on places the GP decrement in the jr delay slot. */
#pragma schedule on
s32 func_003e43a0(s32 arg0) {
    D_0088731C -= 1;
    return arg0;
}
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
    D_0076489C += 1;
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
// FUN_003E4420
void func_003e4420(u8 *arg0, u32 arg1) {
    s32 value;
    u8 *temp3;
    u8 *temp3_2;
    u8 *temp6;
    u8 *temp7;

    temp6 = *(u8 **)(arg0 + 4);
    temp3 = arg0 + arg1;
    temp7 = temp3 + 0x20;
    if (temp6 == NULL) {
        goto fallback;
    }
    if ((~(*(s32 *)(temp6 + 0x10)) & 1) == 0) {
        goto fallback;
    }
    *(u8 **)(temp7 + 4) = *(u8 **)(temp6 + 4);
    value = *(s32 *)(*(u8 **)(arg0 + 4) + 0xC) +
        (*(s32 *)(arg0 + 0xC) - (s32)arg1);
    *(s32 *)(temp7 + 0xC) = value;
common:
    *(u8 **)(arg0 + 4) = temp7;
    *(s32 *)(temp7 + 0x10) = 0;
    *(u8 **)(temp7 + 8) = arg0;
    temp3_2 = *(u8 **)(temp7 + 4);
    if (temp3_2 != NULL) {
        *(u8 **)(temp3_2 + 8) = temp7;
    }
    *(u32 *)(arg0 + 0xC) = arg1;
    *(s32 *)temp7 = *(s32 *)arg0;
    goto done;
fallback:
    *(u8 **)(temp7 + 4) = temp6;
    value = *(s32 *)(arg0 + 0xC) - (s32)arg1 - 0x20;
    *(s32 *)(temp7 + 0xC) = value;
    goto common;
done:
    ;
}
/* measured: closes schedule/no_branch_likely around func_003e4420. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003E44B0
/* measured: schedule/no_branch_likely bracket retained for func_003e44b0. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e44b0(u8 *arg0, s32 arg1)
{
    s32 *base;
    s32 size;

    base = (s32 *)(((s32)arg0 + 0x27) & ~0x1F);
    size = ((((s32)arg0 + arg1) & ~0x1F) - (s32)base) - 0x20;
    if (size >= 0x20) {
        goto init;
    }
    return 0;
init:
    base[0] = (s32)arg0;
    base[1] = 0;
    base[2] = 0;
    base[4] = 0;
    base[3] = size;
    *(s32 *)arg0 = (s32)base;
    *(s32 *)(arg0 + 4) = (s32)base;
    return 1;
}
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

// FUN_003E4520
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4520);

// FUN_003E45F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e45f0);
/* measured: store/reload-tail probes remain nd 14; schedule-off reaches
   nd 30 and O1/common-subexpression variants do not recover retail. */
// FUN_003E46E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e46e0);
/* measured: schedule/no_branch_likely bracket retained for func_003e4760. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003E4760
u8 *func_003e4760(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_00764898];
    if (v != 0) {
        func_003e12f0(v);
    }
    D_0076489C--;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off


/* measured: schedule on plus no_branch_likely on. schedule alone gets nd 26
   (retail fills the loop's branch delay slots), and b210 then wants beql/bnel
   where retail has plain bne/bnez, which is the rest of it. */

// FUN_003E47C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e47c0);
/* measured: schedule/no_branch_likely bracket retained for func_003e4880. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003E4880
s8 *func_003e4880(s8 *arg0) {
    s8 *var_5;
    s8 temp_3;

    if (arg0 != NULL) {
        var_5 = (s8 *)(arg0);
        if (*arg0 != 0) {
            do {
                temp_3 = (s8)(*var_5);
                if ((temp_3 >= 0x61) && (temp_3 < 0x7B)) {
                    *var_5 = temp_3 - 0x20;
                }
                var_5 += 1;
            } while (*var_5 != 0);
        }
    }
    return (s8 *)(arg0);
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule on plus no_branch_likely on. schedule alone gets nd 26
   (retail fills the loop's branch delay slots), and b210 then wants beql/bnel
   where retail has plain bne/bnez, which is the rest of it. */
// FUN_003E48D0
/* measured: schedule/no_branch_likely bracket retained for func_003e48d0. */
#pragma schedule on
#pragma no_branch_likely on
s8 *func_003e48d0(s8 *arg0) {
    s8 *var_5;
    s8 temp_3;

    if (arg0 != NULL) {
        var_5 = (s8 *)(arg0);
        if (*arg0 != 0) {
            do {
                temp_3 = (s8)(*var_5);
                if ((temp_3 >= 0x41) && (temp_3 < 0x5B)) {
                    *var_5 = temp_3 + 0x20;
                }
                var_5 += 1;
            } while (*var_5 != 0);
        }
    }
    return (s8 *)(arg0);
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off


/* Parked candidate: the string-search loop and sign-extension sequence are
   structurally right, but b210 keeps the found-pointer value in the wrong
   temporary registers and shifts the equality branch. Residual
   normalized_diff 23. Committed at nd 23. */
/* measured: string-search candidates remain nonmatching (best active probe
   object 56B/window 64B, normalized_diff 10); restored assembly fallback. */
// FUN_003E4920
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4920);
/* measured: last-byte-search reconstruction remains a 64-byte object with
   normalized_diff 10-16 across typed pointer, explicit key, and O1 probes;
   restored assembly fallback. */
/* measured: last-byte search candidate object 52B/window 64B,
   normalized_diff 9; signed-key prologue matches, but delayed pointer
   sign-extension and loop-exit scheduling remain unresolved. */
// FUN_003E4960
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4960);

// FUN_003E49A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e49a0);
// FUN_003E4AC0
void func_003e4ac0(void)
{
}

/* measured: schedule on is load-bearing (nd 55 without it, and the object
   overflows the window at 84 bytes); the default-argument substitution is
   reached by goto so it lands out of line after the call, as retail has it. */
// FUN_003E4AD0
/* measured: schedule bracket retained for func_003e4ad0. */
#pragma schedule on
s32 func_003e4ad0(char *arg0) {
    s32 r;

    if (arg0 == NULL) {
        goto setdef;
    }
call:
    r = D_008873D4[0](arg0);
    return (r + 4) & -4;
setdef:
    arg0 = D_00752FA8;
    goto call;
}
/* measured: closes the function pragma bracket. */
#pragma schedule off

/* measured: schedule on + no_branch_likely on are load-bearing for this body
   (nd 76 without them) - they place result=0 in the beqz  delay slot and
   keep the arg0[1]==0x3A test's xori/sltiu out of a branch-likely. */

// FUN_003E4B20
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4b20);

// FUN_003E4BE0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4be0);

// FUN_003E4D80
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4d80);

// FUN_003E4F60
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4f60);
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

// FUN_003E5110
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5110);

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
// FUN_003E5250
s32 func_003e5250(s32 arg0) {
    s32 offset;
    s32 result;

    offset = 0x2C;
    result = func_003e3370((u8 *)D_0070B710, arg0);
    result += 0xC;
    return offset + result;
}
/* measured: closes the single-function propagation bracket for func_003e5250. */
#pragma opt_propagation on
/* measured: closes optimization_level 3 around func_003e5220/5250. */
#pragma optimization_level 2

// FUN_003E5290
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5290);

// FUN_003E53B0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e53b0);
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

// FUN_003E5550
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5550);

// FUN_003E5830
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5830);
/* measured: count/loop reconstruction reaches object 80-88B/window 80B,
   normalized_diff 11-14; signed-positive guard and branch/epilogue delay-slot
   order remain unresolved. */
/* measured: indexed search reconstruction follows retail's count guard,
   pointer walk, output-index store, and success/failure return paths. */
// FUN_003E5990
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5990);

/* measured: two things are load-bearing here. Retail tests POSITIVELY and puts
   the indirect call out of line after the return path, then jumps back to it -
   the plain `if (cond) { call(); } return arg0;` form compiles inline with a
   negated skip and scores nd 31, while the goto graph below is exact. And the
   jal and branch delay slots are filled, which needs schedule on. */
// FUN_003E59E0
/* measured: schedule bracket retained for func_003e59e0. */
#pragma schedule on
u8 *func_003e59e0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        goto call;
    }
ret:
    return arg0;
call:
    (*jtbl_008873EC)(*(u8 **)arg0);
    goto ret;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: schedule on is load-bearing - it hoists move $s1,$a0 before the
   first call and fills each jal delay slot with the running-total addu. */

// FUN_003E5A30
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5a30);

// FUN_003E5AE0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5ae0);

// FUN_003E5DF0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5df0);

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
// FUN_003E6240
#pragma schedule on
s32 func_003e6240(s32 arg0) {
    s32 total = 0x10;
    total += func_003e4ad0((char *)(arg0 + 0x10)) + 0xC;
    total += func_003e4ad0((char *)(arg0 + 0x30)) + 0xC;
    total += func_003e3370((u8 *)D_0070B800, arg0) + 0xC;
    return total;
}
/* measured: closes the function pragma bracket. */
#pragma schedule off




// FUN_003E62B0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e62b0);

// FUN_003E6430
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6430);

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



/* measured: plain C matches 252 of the 256 retail bytes; residual argument-load
   ordering at the D_00887394 call remains after direct locals, a forced stack
   load, and an inline wrapper probe. Committed at nd 6. */
// FUN_003E6770 NONMATCHING
#ifdef NON_MATCHING
/* measured: optimization_level 3 is load-bearing for func_003e6770. */
#pragma optimization_level 3
typedef u8 *(*Callback6770)(u8 *, u8 *);
extern s32 (*D_0088738C[])(s32 *, Callback6770, s32);
extern s32 (*D_00887394[])(s32, Callback6770, s32);
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
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
/* measured: closes optimization_level 3 around func_003e6770. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6770);
#endif

// FUN_003E6870
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6870);

/* measured: optimization_level 3 is load-bearing for func_003e6a60. */
#pragma optimization_level 3
// FUN_003E6A60
s32 func_003e6a60(s32 arg0) {
    func_003ef3a0();
    return arg0;
}
/* measured: closes optimization_level 3 around func_003e6a60. */
#pragma optimization_level 2

// FUN_003E6A90
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6a90);

// FUN_003E6DB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6db0);

// FUN_003E6E70
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6e70);

// FUN_003E7680
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7680);

// FUN_003E7810
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7810);

// FUN_003E7D50
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7d50);
/* measured: optimization_level 3 is load-bearing for func_003e7ee0. */
#pragma optimization_level 3
// FUN_003E7EE0
u8 *func_003e7ee0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x14) == 1) {
        func_003e7680();
        func_003e6e70(arg0);
    } else {
        func_003e7d50();
        func_003e7810(arg0);
    }
    func_003e5110(arg0 + 0x10C, arg0 + 0x124, 8);
    return arg0;
}
/* measured: closes optimization_level 3 around func_003e7ee0. */
#pragma optimization_level 2

/* measured: schedule+no_branch_likely load-bearing; flipped guard polarity so
   the D_008872E0=0 work lands out of line after the early return 0. */
// FUN_003E7F50
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e7f50 bracket. */
#pragma no_branch_likely on
s32 func_003e7f50(u8 *arg0) {
    if (D_00887350[0](0, (s32)arg0, 0) == 0) {
        return 0;
    }
    *(s32 *)D_008872E0 = 0;
    return (s32)arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off






/* measured: schedule+no_branch_likely load-bearing - schedule puts the
   D_008872E0 store in the func_003ed7e0 jal delay slot. */
// FUN_003E7FB0
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003e7fb0 bracket. */
#pragma no_branch_likely on
s32 func_003e7fb0(u8 *arg0) {
    *(s32 *)D_008872E0 = (s32)arg0;
    func_003ed7e0();
    if (D_0088732C[0](0, (s32)arg0, 0) == 0) {
        return 0;
    }
    func_00410f40((s32)arg0);
    return (s32)arg0;
}
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
        func_003e12f0(v);
        *(s32 *)&D_008872E0[D_007648A0] = 0;
    }
    D_007648A4--;
    return arg0;
}
/* measured: closes the function pragma bracket. */
#pragma no_branch_likely off
#pragma schedule off


// FUN_003E8080
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8080);

/* measured: two-float load-order reconstruction reaches object 72B/window
   80B, normalized_diff 16; b210 keeps both loads after the frame save. */
// FUN_003E8130
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8130);
/* measured: no_branch_likely on forces the retail beqz+nop shape. */
#pragma no_branch_likely on
/* measured: optimization_level 3 is load-bearing for func_003e8180. */
#pragma optimization_level 3
// FUN_003E8180
u8 *func_003e8180(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    *(f32 *)(arg0 + 0x80) = fparg0;
    func_003e6db0();
    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_003e9680((void *)temp_4);
    }
    return arg0;
}
/* measured: closes optimization_level 3 around func_003e8180. */
#pragma optimization_level 2
/* measured: close no_branch_likely around func_003e8180. */
#pragma no_branch_likely off

/* measured: optimization_level 3 is load-bearing for func_003e81c0. */
#pragma optimization_level 3
// FUN_003E81C0
/* measured: no_branch_likely on forces the retail beqz+nop shape. */
#pragma no_branch_likely on
u8 *func_003e81c0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    *(f32 *)(arg0 + 0x84) = fparg0;
    func_003e6db0();
    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_003e9680((void *)temp_4);
    }
    return arg0;
}
/* measured: closes optimization_level 3 around func_003e81c0. */
#pragma optimization_level 2
/* measured: close no_branch_likely around func_003e81c0. */
#pragma no_branch_likely off

// FUN_003E8200
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8200);

/* measured: callback conditional-move reconstruction reaches object 60-72B/window
   64B, normalized_diff 8-16; b210 emits branches rather than retail movz. */
// FUN_003E82A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e82a0);

/* measured: direct wrapper reaches object 56B/window 48B,
   normalized_diff 8; callback load/delay slot matches but movz remains. */
// FUN_003E82E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e82e0);
/* measured: no_branch_likely on preserves 8310's plain comparison branches. */
#pragma no_branch_likely on
/* measured: optimization_level 3 is load-bearing for func_003e8310. */
#pragma optimization_level 3
// FUN_003E8310
u8 *func_003e8310(u8 *arg0, s32 arg1) {
    s32 local[2];
    s32 value;

    switch (arg1) {
    case 2:
    case 1:
        goto normal;
    default:
        goto fallback;
    }
normal:
    *(s32 *)(arg0 + 0x14) = arg1;
    value = *(s32 *)(arg0 + 4);
    if (value != 0) {
        func_003e9680((void *)value);
    }
    func_003e6db0(arg0);
    return arg0;
fallback:
    local[0] = 1;
    local[1] = func_003df590(0x80000003, D_0070B730);
    func_003df4d0(local);
    return NULL;
}
/* measured: closes optimization_level 3 around func_003e8310. */
#pragma optimization_level 2
/* measured: closes no_branch_likely around func_003e8310. */
#pragma no_branch_likely off
/* measured: normalization wrapper reconstruction reaches object 108B/window
   112B, normalized_diff 7; input-load placement before the frame save remains
   unresolved. */
// FUN_003E83A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e83a0);

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

/* measured: optimization_level 3 is load-bearing for func_003e8440. */
#pragma optimization_level 3
// FUN_003E8440
#pragma schedule on
s32 func_003e8440(u8 *arg0) {
    func_003e3c20((s32)D_0070B710, (s32)arg0);
    func_003efda0(arg0);
    jtbl_008873FC[0](*(u8 **)(D_008872E0 + D_007648A0), arg0);
    return 1;
}
/* measured: closes optimization_level 3 around func_003e8440. */
#pragma optimization_level 2
/* measured: closes the schedule bracket opened above and restores the
   translation-unit baseline. */
#pragma schedule off

/* measured: optimization_level 3 is load-bearing for func_003e84a0. */
#pragma optimization_level 3
// FUN_003E84A0
/* measured: schedule-on probe for 003e84a0 prologue and store ordering. */
#pragma schedule on
/* measured: no_branch_likely-on probe restores retail's plain null test. */
#pragma no_branch_likely on
u8 *func_003e84a0(void) {
    extern u8 *(*D_008873F8[])(s32, s32);
    extern void func_003e6db0(u8 *, s32, s32, s32);
    extern void func_003e3b70(u8 *, u8 *);
    u8 *temp;

    temp = D_008873F8[0](*(s32 *)(D_008872E0 + D_007648A0), 0x30005);
    if (temp == NULL) {
        goto fail;
    }
    *(u8 *)(temp + 0) = 4;
    *(u8 *)(temp + 1) = 0;
    *(u8 *)(temp + 2) = 0;
    *(u8 *)(temp + 3) = 0;
    *(s32 *)(temp + 4) = 0;
    *(void **)(temp + 0x10) = (void *)func_003e7ee0;
    *(void **)(temp + 0x18) = (void *)func_003e7fb0;
    *(void **)(temp + 0x1C) = (void *)func_003e7f50;
    *(s32 *)(temp + 0x6C) = 0x3F800000;
    *(s32 *)(temp + 0x68) = 0x3F800000;
    *(s32 *)(temp + 0x74) = 0x3F800000;
    *(s32 *)(temp + 0x70) = 0x3F800000;
    *(s32 *)(temp + 0x7C) = 0;
    *(s32 *)(temp + 0x78) = 0;
    *(s32 *)(temp + 0x80) = 0x3D4CCCCD;
    *(s32 *)(temp + 0x84) = 0x41200000;
    *(s32 *)(temp + 0x88) = 0x40A00000;
    *(s32 *)(temp + 0x60) = 0;
    *(s32 *)(temp + 0x64) = 0;
    *(s32 *)(temp + 0x14) = 1;
    func_003e6db0(temp, 0x41200000, 0x3D4CCCCD, 0x3F800000);
    *(s32 *)(temp + 0x2C) = 0;
    func_003e3b70(D_0070B710, temp);
    goto done;
fail:
    return NULL;
done:
    return temp;
}
/* measured: closes optimization_level 3 around func_003e84a0. */
#pragma optimization_level 2
/* measured: closes no_branch_likely inside func_003e84a0. */
#pragma no_branch_likely off
/* measured: closes schedule inside func_003e84a0. */
#pragma schedule off

// FUN_003E85A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e85a0);

/* measured: opt_propagation off tests retaining table-address materialisation before the argument load. */
#pragma opt_propagation off
/* measured: tailcall on emits the retail jr-v0 wrapper for the table fetch. */
#pragma tailcall on
/* measured: optimization_level 3 is load-bearing for func_003e8790. */
#pragma optimization_level 3
// FUN_003E8790
void *func_003e8790(void *arg0, s32 arg1) {
    u8 *base;

    base = (u8 *)0x00880000;
    return (*(void *(**)(void *, s32))(base + 0x73e8))(*(void **)arg0, arg1);
}
/* measured: closes optimization_level 3 around func_003e8790. */
#pragma optimization_level 2
/* measured: closes the single-function tailcall bracket. */
/* measured: closes the opt_propagation bracket for func_003e8790. */
#pragma opt_propagation on
#pragma tailcall off

/* measured: schedule on hoists the callback table load before saving self. */
#pragma schedule on
/* measured: optimization_level 3 is load-bearing for func_003e87b0. */
#pragma optimization_level 3
// FUN_003E87B0
u8 *func_003e87b0(u8 *arg0, u8 *arg1) {
    u8 *self;

    self = arg0;
    (*jtbl_008873EC)(arg1);
    return self;
}
/* measured: closes optimization_level 3 around func_003e87b0. */
#pragma optimization_level 2
/* measured: closes the single-function schedule bracket. */
#pragma schedule off

// FUN_003E87F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e87f0);
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
// FUN_003E8930
/* measured: tailcall knob retains the func_003e8930 bracket. */
#pragma tailcall on
void func_003e8930(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003e3870(D_0070B760, arg0, arg1, arg2, arg3, 0);
}
/* measured: closes the function pragma bracket. */
#pragma tailcall off
/* measured: closes optimization_level 3 around func_003e8930. */
#pragma optimization_level 2
// FUN_003E8960
/* measured: probe typed tailcall for global-base forwarding wrapper. */
#pragma schedule on
#pragma tailcall on
s32 func_003e8960(s32 arg0) {
    return func_003e3830(D_0070B760, arg0);
}
/* measured: close typed tailcall probe. */
#pragma tailcall off
#pragma schedule off
/* measured: old-style loader ABI plus schedule/no_branch_likely preserve the
   hidden fifth argument, saved result pointer and plain success branch. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003E8970
s32 *func_003e8970(s32 *arg0, s32 arg1) {
    s32 *result;

    result = arg0;
    if (func_003e87f0(D_008872F0, 6, result, 0, arg1) == 0) {
        result = NULL;
    }
    return result;
}
/* measured: closes schedule/no_branch_likely around func_003e8970. */
#pragma schedule off
#pragma no_branch_likely off
/* measured: old-style loader ABI and schedule on preserve the stack output
   pointer plus hidden fifth argument in the 80-byte retail wrapper. */
/* measured: no_branch_likely on restores retail's plain beqz and shared
   return block. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003E89C0
s32 func_003e89c0(void) {
    s32 result;

    if (func_003e87f0(D_008872F0, 0xA, &result, 0, 0) != 0) {
        return result;
    }
    return -1;
}
/* measured: closes the single-function schedule bracket. */
/* measured: closes no_branch_likely around func_003e89c0. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: schedule on preserves the five-argument loader call and boolean
   result in the 64-byte retail wrapper. */
#pragma schedule on
// FUN_003E8A10
s32 func_003e8a10(s32 arg0) {
    return func_003e87f0(D_008872F0, 7, (s32 *)0, 0, arg0) != 0;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off
// FUN_003E8A50
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8a50);
// FUN_003E8B10
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8b10);
// FUN_003E8C60
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8c60);
// FUN_003E8DC0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8dc0);
// FUN_003E8E60
/* measured: schedule/no_branch_likely bracket retained for func_003e8e60. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003e8e60(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(D_008872E0 + iGpffffb7c0);
    if (p != NULL) {
        func_003e12f0((s32)p);
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
// FUN_003E8ED0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8ed0);
// FUN_003E8F80
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8f80);
/* measured: schedule on and no_branch_likely on reproduce the retail
   incoming-a0/second-argument call to func_003e8f80 and the plain branch.
   This exact cleaned M2C shape compiles MATCH at nd 0. */
// FUN_003E90F0
/* measured: schedule/no_branch_likely bracket retained for func_003e90f0. */
#pragma schedule on
#pragma no_branch_likely on
s32 *func_003e90f0(u8 *arg0) {
    s32 *temp_2;
    temp_2 = (s32 *)(func_003e8f80(arg0, 0));
    if (temp_2 != NULL) {
        *(u8 *)((u8 *)(temp_2) + 3) = (u8)(*(u8 *)((u8 *)(temp_2) + 3) & ~3);
        func_003e9680(temp_2);
    }
    return (s32 *)(temp_2);
}
/* measured: closes no_branch_likely around func_003e90f0. */
#pragma no_branch_likely off
/* measured: closes schedule around func_003e90f0. */
#pragma schedule off
// FUN_003E9140
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e9140);