/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct RwObjectOwnerLink RwObjectOwnerLink;
typedef struct RwObject RwObject;
typedef struct RwFrame RwFrame;
typedef struct RwMatrixTag RwMatrix;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;

/* Canonical grouped function declarations. */
extern s32 iGpffffb994;
extern s32 iGpffffac10;
extern s32 iGpffffb900;
extern s32 iGpffffb9c0;
extern s32 iGpffffb9b8;
extern s32 iGpffffb9cc;
extern s32 iGpffffb9c8;
extern s32 iGpffffb9bc;
extern void func_003e12f0(s32 arg0);
extern void func_00414fd0(s32 arg0);
extern s32 D_0070C220[];
extern s32 D_0070C35C[];
extern s32 iGpffffb7e0;
extern s32 iGpffffb7e8;
extern s32 iGpffffb7f8;
extern s32 iGpffffb7f4;
extern s32 iGpffffb7ec;
extern s8 iGpffffb7f0;
extern u16 iGpffffabd4;
extern s32 iGpffffb938;
extern s32 D_008872E0[];
extern s32 iGpffffb7c0;
extern s32 iGpffffb7d4;
extern s32 iGpffffb7d0;
extern u8 *(*D_008873F8[])(u8 *arg0, s32 arg1);
extern s32 iGpffffb7c8;
extern u8 D_0070B7C0[];
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern u8 *func_003ea510(u8 *arg0);
extern s32 (*D_00887340[])(s32 *arg0, u8 *arg1, s32 arg2);
extern s32 (*D_00887344[])(u8 *arg0, s32 *arg1, s32 arg2);
extern u8 *D_0088739C[];
extern void func_003ed650(u8 *arg0);
extern s32 iGpffffb958;
extern u8 *iGpffffb904;
extern s32 func_003ec330(u8 *arg0);
extern s32 iGpffffac00;
extern s32 D_008872F8[];
extern u8 D_0070B7A0[];
extern u8 D_0070B7E0[];
extern u8 D_0070B800[];
extern s32 func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s8 *func_003eab70(s8 *arg0, s32 arg1, s32 (*arg2)(s32, s32), s32 *arg3);
extern s32 func_003eb0d0(s32 arg0, u8 **arg1);
extern s32 func_00410ff0(void);
extern s32 (*D_00887368[])(s32 arg0, s32 arg1, s32 arg2);
extern u8 *iGpffffb980;
extern s32 D_0088CAC0[];
extern s32 D_0088CAC4[];
extern s32 D_0088CAC8[];
extern s32 D_0088CACC[];
extern void func_003ed960(u8 *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void (*D_00887388[])(s32 arg0, s32 arg1, s32 arg2);
extern s32 (*D_00887384[])(s32 *arg0, s32 arg1, s32 arg2);
extern s32 (*D_00887364[])(s32 *arg0, s32 arg1, s32 arg2);
extern void func_003ee470(void);
extern void func_003ee1d0(void);
extern u8 *iGpffffb978;
extern u8 *iGpffffb97c;
extern void (*D_00887308[])(void);
extern void (*D_0088730C[])(void);
extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887314[])(void);
extern s32 func_0040afb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0040b230(u8 *arg0, s32 unused, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0040c0f0(s32 arg0, void *arg1, s32 arg2);
extern s32 func_0040d0a0(s32 arg0, s32 arg1);
extern void func_0040aa60(void (*arg0)(void));
extern s32 func_00402d50(void *arg0, s32 *arg1);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s32 iGpffffb9b0;
extern s32 iGpffffb9ac;
extern void func_00415920(void *arg0);
extern s32 iGpffffb9b4;
extern u8 iGpffffb984;
extern u8 D_00753330[];
extern u8 D_00753340[];
extern void (*D_0070C300[])(void *arg0, s32 arg1, s32 arg2);
u32 func_003e8110(u32 camera);
u32 func_003e8120(u32 camera);
u8 func_003e9240(RwObjectOwnerLink *param_1);
u32 func_003e9750(int param_1);
u32 func_004125d0(int param_1);
s32 func_0041f208(int param_1);
u32 func_0041f6e0(u32 *param_1);
u32 func_0041f6f0(u32 *param_1);

/* Source unit: src/rw/rwcore_003e8110.c (1 function markers) */

/* measured: source unit 003e8110 requires optimization_level 3. */
#pragma optimization_level 3
// FUN_003E8110
u32 func_003e8110(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x1c))(camera);
}
/* measured: closes optimization_level 3 around func_003e8110. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e8120.c (1 function markers) */

/* measured: source unit 003e8120 requires optimization_level 3. */
#pragma optimization_level 3
// FUN_003E8120
u32 func_003e8120(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x18))(camera);
}
/* measured: closes optimization_level 3 around func_003e8120. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9240.c (1 function markers) */
/* measured: source unit 003e9240 requires optimization_level 3. */
#pragma optimization_level 3
struct RwObjectOwnerLink {
    u8 padding[0xa0];
    RwObject *owner;
};
struct RwObject {
    u8 padding[3];
    u8 type;
};

extern u8 func_003e9240(RwObjectOwnerLink *param_1); /* P4: ported verbatim into src/renderware */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9750.c (1 function markers) */
/* measured: source unit 003e9750 requires optimization_level 3. */
#pragma optimization_level 3

/* measured: retail callback guard is plain beqz, not bnel. */
#pragma no_branch_likely on
extern u8 *func_003e9320(void); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses a plain beqz guard for func_003e9680. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003e9680. */
#pragma no_branch_likely off
/* measured: retail uses a plain bnez for the callback guard. */
#pragma no_branch_likely on
extern u8 *func_003e9700(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: closes optimization_level 3 around source unit 003e9750. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004125d0.c (1 function markers) */
/* measured: source unit 004125d0 requires optimization_level 3. */
#pragma optimization_level 3

/* measured: retail list callback branches are plain beqz/bnez. */
#pragma no_branch_likely on
extern u8 *func_003e9af0(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses plain beqz in func_003e9c10's flag test. */
#pragma no_branch_likely on
// FUN_003E9C10
u8 *func_003e9c10(u8 *arg0, const f32 *translation, s32 combineOp)
{
    extern u8 *func_003e0c90(u8 *, const f32 *, s32);
    u8 *temp_3;
    u8 temp_5;
    u8 **head;

    func_003e0c90(arg0 + 0x10, translation, combineOp);
    temp_3 = *(u8 **)(arg0 + 0xA0);
    temp_5 = *(u8 *)(temp_3 + 3);
    if ((temp_5 & 3) == 0) {
        goto insert;
    }
update:
    *(u8 *)(*(u8 **)(arg0 + 0xA0) + 3) = (u8)(temp_5 | 3);
    *(u8 *)(arg0 + 3) = (u8)(*(u8 *)(arg0 + 3) | 0xC);
    return arg0;
insert:
    head = (u8 **)D_0088739C;
    *(u8 **)(temp_3 + 8) = *head;
    *(u8 **)(*(u8 **)(arg0 + 0xA0) + 0xC) = (u8 *)head;
    *(u8 **)(*head + 4) = *(u8 **)(arg0 + 0xA0) + 8;
    *head = *(u8 **)(arg0 + 0xA0) + 8;
    goto update;
}
/* measured: closes no_branch_likely around func_003e9c10. */
#pragma no_branch_likely off
/* measured: sibling list helper func_003e9cb0 uses plain beqz branches. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003e9cb0. */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_003e9d50(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_003e9df0(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_003ea2c0(s32 arg0, s32 arg1, s32 arg2); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail flag guard is plain beqz, not beql. */
#pragma no_branch_likely on
extern s32 func_003ea370(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
extern u8 *func_003ea510(u8 *arg0); /* P4: ported verbatim into src/renderware */
// FUN_003EB700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb700);
// FUN_003EBBF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebbf0);
/* measured: retail callback and flag branches are plain beqz/bnez. */
#pragma no_branch_likely on
extern s32 *func_003ec110(s32 *arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail callback and flag branches are plain beqz/bnez. */
#pragma no_branch_likely on
extern u8 *func_003ec180(u8 *arg0, s32 *arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses a plain bnez for the callback result. */
#pragma no_branch_likely on
extern s32 func_003ec1f0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
extern s32 func_003ec330(u8 *arg0); /* P4: ported verbatim into src/renderware */
/* measured: retail uses a plain beqz for the callback result. */
#pragma no_branch_likely on
extern s32 func_003ec3d0(s32 arg0, s32 arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail callback result uses a plain beqz, not bnel. */
#pragma no_branch_likely on
extern s32 func_003ec420(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_003ec4f0(u8 *arg0, u8 *arg1, u8 *arg2); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses a plain beqz for the callback result. */
#pragma no_branch_likely on
extern s32 func_003ec6a0(s32 arg0, s32 arg1, s32 arg2); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses a plain beqz for the callback guard. */
#pragma no_branch_likely on
extern s32 func_003ec6f0(s32 arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
// FUN_003EC840
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec840);
// FUN_003ED850
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed850);
/* measured: retail ef0d0 allocator guard is plain beqz, not bnel. */
#pragma no_branch_likely on
extern u8 *func_003ef0d0(void); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail ef1b0 equal-head branch is plain beq, not beql. */
#pragma no_branch_likely on
extern s32 func_003ef1b0(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_003ef5b0(u8 *arg0, u8 *arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: no_branch_likely preserves the retail list-detach branch. */
#pragma no_branch_likely on
extern u8 *func_003ef610(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: no_branch_likely preserves the retail callback null branch. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003ef6f0. */
#pragma no_branch_likely off
/* measured: no_branch_likely preserves the retail list-link branch. */
#pragma no_branch_likely on
extern void func_003efda0(u8 *arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
// FUN_003EFF30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eff30);
// FUN_003F0110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0110);
// FUN_003F02D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f02d0);
// FUN_003F03F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f03f0);
// FUN_003F0510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0510);
// FUN_003F0610
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0610);
// FUN_003F0C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0c10);
// FUN_003F0DE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f0de0);
// FUN_003F1030
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1030);
// FUN_003F1240
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1240);
// FUN_003F13B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f13b0);
// FUN_003F1520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1520);
// FUN_003F1600
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1600);
// FUN_003F1700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1700);
// FUN_003F25C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f25c0);
// FUN_003F4370
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4370);
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely off
/* measured: retail uses plain branches in func_003f4f90. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f4f90. */
#pragma no_branch_likely off
// FUN_003F6690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6690);
/* measured: retail emits plain bnez/beqz branches with the zero-return block last. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f6780. */
#pragma no_branch_likely off
// FUN_003F67E0
s32 func_003f67e0(s32 arg0)
{
    iGpffffb994 = arg0;
    return 1;
}
// FUN_003F67F0
s32 func_003f67f0(s32 arg0)
{
    iGpffffac10 = arg0;
    return 1;
}
// FUN_003F6800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6800);
/* measured: retail uses plain bnez/beqz branches in func_003f68a0. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f68a0. */
#pragma no_branch_likely off
// FUN_003F7A60
s32 func_003f7a60(s32 *arg0, s32 arg1)
{
    *arg0 = arg1;
    return 1;
}
// FUN_003FB3F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb3f0);
// FUN_003FD630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd630);
// FUN_003FDF20
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fdf20);
// FUN_003FE1F0
s32 func_003fe1f0(void)
{
    return 1;
}
// FUN_003FE200
s32 func_003fe200(void)
{
    return 0;
}
// FUN_003FE210
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe210);
// FUN_003FE470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe470);
// FUN_003FF5B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff5b0);
/* measured: retail cleanup tests are plain beqz. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_004015e0. */
#pragma no_branch_likely off
// FUN_00401B80
s32 func_00401b80(void)
{
    return iGpffffb900;
}
// FUN_00402390
void func_00402390(u8 *arg0, u8 *arg1, u8 *arg2)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x10($5)\n"
        "lqc2 $vf3, 0x20($5)\n"
        "lqc2 $vf4, 0x30($5)\n"
        "lqc2 $vf5, 0x0($6)\n"
        "lqc2 $vf6, 0x10($6)\n"
        "lqc2 $vf7, 0x20($6)\n"
        "lqc2 $vf8, 0x30($6)\n"
        "lqc2 $vf13, 0x0($4)\n"
        "vmulax.xyz $ACC, $vf5, $vf1x\n"
        "vmadday.xyz $ACC, $vf6, $vf1y\n"
        "vmaddz.xyz $vf9, $vf7, $vf1z\n"
        "vmulax.xyz $ACC, $vf5, $vf2x\n"
        "vmadday.xyz $ACC, $vf6, $vf2y\n"
        "vmaddz.xyz $vf10, $vf7, $vf2z\n"
        "vmove.w $vf9, $vf13\n"
        "vmulax.xyz $ACC, $vf5, $vf3x\n"
        "vmadday.xyz $ACC, $vf6, $vf3y\n"
        "vmaddz.xyz $vf11, $vf7, $vf3z\n"
        "vmulax.xyz $ACC, $vf5, $vf4x\n"
        "vmadday.xyz $ACC, $vf6, $vf4y\n"
        "vmaddaz.xyz $ACC, $vf7, $vf4z\n"
        "vmaddw.xyz $vf12, $vf8, $vf0w\n"
        "sqc2 $vf9, 0x0($4)\n"
        "sqc2 $vf10, 0x10($4)\n"
        "sqc2 $vf11, 0x20($4)\n"
        "sqc2 $vf12, 0x30($4)\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "$vf6", "$vf7", "$vf8", "$vf9", "$vf10", "$vf11", "$vf12", "$vf13", "ACC", "memory");
}
// FUN_00402410
u8 *func_00402410(u8 *arg0, u8 *arg1, u8 *arg2)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($6)\n"
        "lqc2 $vf2, 0x10($6)\n"
        "lqc2 $vf3, 0x20($6)\n"
        "lqc2 $vf4, 0x30($6)\n"
        "lwu $3, 0x0($5)\n"
        "lwu $1, 0x4($5)\n"
        "lwu $2, 0x8($5)\n"
        "dsll32 $1, $1, 0\n"
        "or $1, $1, $3\n"
        "pcpyld $2, $2, $1\n"
        "qmtc2.ni $2, $vf5\n"
        "vmulax.xyz $ACC, $vf1, $vf5x\n"
        "vmadday.xyz $ACC, $vf2, $vf5y\n"
        "vmaddaz.xyz $ACC, $vf3, $vf5z\n"
        "vmaddw.xyz $vf5, $vf4, $vf0w\n"
        "qmfc2.ni $1, $vf5\n"
        "dsrl32 $2, $1, 0\n"
        "pcpyud $3, $1, $1\n"
        "sw $1, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        "daddu $2, $4, $0\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "ACC", "memory");
}
// FUN_00402470
u8 *func_00402470(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "daddu $8, $4, $0\n"
        "lqc2 $vf1, 0x0($7)\n"
        "lqc2 $vf2, 0x10($7)\n"
        "lqc2 $vf3, 0x20($7)\n"
        "lqc2 $vf4, 0x30($7)\n"
        "lwu $13, 0x0($5)\n"
        "lwu $11, 0x4($5)\n"
        "lwu $12, 0x8($5)\n"
        "dsll32 $11, $11, 0\n"
        "or $11, $11, $13\n"
        "pcpyld $12, $12, $11\n"
        "qmtc2.ni $12, $vf5\n"
        "1:\n"
        "blez $6, 2f\n"
        "addi $5, $5, 0xC\n"
        "vmulax.xyz $ACC, $vf1, $vf5x\n"
        "vmadday.xyz $ACC, $vf2, $vf5y\n"
        "vmaddaz.xyz $ACC, $vf3, $vf5z\n"
        "vmaddw.xyz $vf6, $vf4, $vf0w\n"
        "lwu $13, 0x0($5)\n"
        "lwu $11, 0x4($5)\n"
        "lwu $12, 0x8($5)\n"
        "addi $6, $6, -0x1\n"
        "dsll32 $11, $11, 0\n"
        "or $11, $11, $13\n"
        "pcpyld $12, $12, $11\n"
        "qmtc2.ni $12, $vf5\n"
        "qmfc2.ni $25, $vf6\n"
        "dsrl32 $2, $25, 0\n"
        "pcpyud $3, $25, $25\n"
        "sw $25, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        "b 1b\n"
        "addi $4, $4, 0xC\n"
        "2:\n"
        "daddu $2, $8, $0\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2), "r"(arg3)
        : "$vf1", "$vf2", "$vf3", "$vf4", "$vf5", "$vf6", "ACC", "memory");
}
// FUN_00402510
u8 *func_00402510(u8 *arg0, u8 *arg1, u8 *arg2)
{
    __asm__ volatile(
        ".set noat\n"
        ".set noreorder\n"
        "lqc2 $vf1, 0x0($6)\n"
        "lqc2 $vf2, 0x10($6)\n"
        "lqc2 $vf3, 0x20($6)\n"
        "lwu $1, 0x0($5)\n"
        "lwu $2, 0x4($5)\n"
        "lwu $3, 0x8($5)\n"
        "dsll32 $2, $2, 0\n"
        "or $2, $2, $1\n"
        "pcpyld $3, $3, $2\n"
        "qmtc2.ni $3, $vf4\n"
        "vmulax.xyz $ACC, $vf1, $vf4x\n"
        "vmadday.xyz $ACC, $vf2, $vf4y\n"
        "vmaddz.xyz $vf4, $vf3, $vf4z\n"
        "qmfc2.ni $1, $vf4\n"
        "dsrl32 $2, $1, 0\n"
        "pcpyud $3, $1, $1\n"
        "sw $1, 0x0($4)\n"
        "sw $2, 0x4($4)\n"
        "sw $3, 0x8($4)\n"
        "daddu $2, $4, $0\n"
        ".set reorder\n"
        :
        : "r"(arg0), "r"(arg1), "r"(arg2)
        : "$vf1", "$vf2", "$vf3", "$vf4", "ACC", "memory");
}
// FUN_00402570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402570);
/* measured: no_branch_likely preserves the two retail plain null branches. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_00402680. */
#pragma no_branch_likely off
// FUN_00407BD0
s32 func_00407bd0(s32 arg0, u8 *arg1)
{
    iGpffffb980 = arg1;
    D_0088CAC0[0] = *(s16 *)(arg1 + 0x1c);
    D_0088CAC4[0] = *(s16 *)(arg1 + 0x1e);
    D_0088CAC8[0] = *(s32 *)(arg1 + 0xc);
    D_0088CACC[0] = *(s32 *)(arg1 + 0x10);
    return 1;
}
// FUN_00407C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407c10);
// FUN_00407D10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407d10);
/* measured: retail selector branch is plain beqz, not beql. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_0040afb0. */
#pragma no_branch_likely off
/* measured: retail selector branch in func_0040b230 is plain beqz, not beql. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_0040b230. */
#pragma no_branch_likely off
/* measured: retail 0040c0f0 uses plain blez/beqz branches. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_0040c0f0. */
#pragma no_branch_likely off
/* measured: retail func_0040d0a0 uses plain blez/beqz branches. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_0040d0a0. */
#pragma no_branch_likely off
// FUN_0040D110
void func_0040d110(void)
{
    D_00887308[0] = (void (*)(void))func_0040afb0;
    D_0088730C[0] = (void (*)(void))func_0040b230;
    D_00887310[0] = func_0040c0f0;
    D_00887314[0] = (void (*)(void))func_0040d0a0;
    func_0040aa60((void (*)(void))func_0040c0f0);
}
// FUN_0040D160
void func_0040d160(void)
{
}
// FUN_0040D570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d570);
// FUN_0040DF40
void func_0040df40(void)
{
}
// FUN_0040EEE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040eee0);
// FUN_00410360
s32 func_00410360(void)
{
    return D_0070C35C[0];
}
#pragma no_branch_likely on
extern s32 func_00410a40(s32 arg0); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern s32 func_00410ab0(s32 arg0, u32 arg1); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern s32 func_00410ff0(void); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
#pragma no_branch_likely on
extern u8 *func_004115d0(void); /* P4: ported verbatim into src/renderware */
#pragma no_branch_likely off
/* measured: retail uses a plain bnez for the allocator range guard. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_004117b0. */
#pragma no_branch_likely off
/* measured: closes optimization_level 3 around source unit 004125d0. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f208.c (1 function markers) */
/* measured: source unit 0041f208 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_0041F208
s32 func_0041f208(int param_1)
{
    return *(s32 *)(*(s32 *)(param_1 + 0x40) + 0x878) = 1;
}
/* measured: closes optimization_level 3 around func_0041f208. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6e0.c (1 function markers) */
/* measured: source unit 0041f6e0 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_0041F6E0
u32 func_0041f6e0(u32 *param_1)
{
    return param_1[3] = param_1[2];
}
/* measured: closes optimization_level 3 around func_0041f6e0. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6f0.c (1 function markers) */
/* measured: source unit 0041f6f0 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_0041F6F0
u32 func_0041f6f0(u32 *param_1)
{
    return param_1[2] = param_1[3];
}
/* measured: closes optimization_level 3 around func_0041f6f0. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004222b0.c (1 function markers) */
/* measured: source unit 004222b0 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_004222B0
asm u32 QueryIntrContext(void)
{
    .set noreorder
    mfc0 $v0, $12
    xori $v0, $v0, 1
    jr $ra
    andi $v0, $v0, 1
}
/* measured: closes optimization_level 3 around func_004222b0. */
#pragma optimization_level 2
