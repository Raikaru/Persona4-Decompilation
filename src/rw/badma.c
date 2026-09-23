/* Retail RenderWare-block functions attributed to badma.c.
 *
 * The donor-verbatim port of this translation unit, where the public
 * RenderWare source provides one, lives under src/renderware/.  What is here
 * is the retail code that source revision does not reproduce: reconstructed
 * bodies, INCLUDE_ASM fallbacks and inline assembly.  Split out of
 * rwcore_grouped.c by local/split_grouped.py along the NBA Ballers DWARF
 * translation-unit attribution (docs/sky2/rw_unit_attribution.json).
 * Everything except the unowned function bodies is verbatim from the grouped
 * file, so each function compiles against the state it had there.
 */

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
extern void memset(void *arg0, s32 arg1, s32 arg2);
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
/* measured: closes optimization_level 3 around func_003e8110. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e8120.c (1 function markers) */

/* measured: source unit 003e8120 requires optimization_level 3. */
#pragma optimization_level 3
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
// FUN_003F2760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2760);
// FUN_003F2830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2830);
// FUN_003F2CD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2cd0);
// FUN_003F2F40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f2f40);
// FUN_003F32D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f32d0);
// FUN_003F34E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f34e0);
// FUN_003F36A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f36a0);
// FUN_003F3750
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f3750);
// FUN_003F38D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f38d0);
// FUN_003F39C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f39c0);
// FUN_003F3EB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f3eb0);
// FUN_003F4370
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4370);
// FUN_003F44C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f44c0);
// FUN_003F4730
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4730);
// FUN_003F4950
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4950);
// FUN_003F4A80
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4a80);
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely on
// FUN_003F4BE0
void func_003f4be0(void)
{
    extern void func_00422390(s32 arg0);
    extern void func_004222c0(s32 arg0);
    extern void func_00421510(s32 arg0, s32 arg1);
    extern void func_004214e0(s32 arg0, s32 arg1);
    extern u8 iGpffffb804;
    extern u8 iGpffffb800;
    extern u8 iGpffffb7fc;
    extern s32 iGpffffabe0;
    extern s32 iGpffffabdc;
    extern s32 iGpffffabd8;

    if (iGpffffb804 != 0)
        goto callback1;
check2:
    if (iGpffffb800 != 0)
        goto callback2;
check3:
    if (iGpffffb7fc != 0)
        goto callback3;
cleanup:
    func_00421510(2, iGpffffabe0);
    iGpffffabe0 = -1;
    func_00421510(1, iGpffffabdc);
    iGpffffabdc = -1;
    func_004214e0(2, iGpffffabd8);
    iGpffffabd8 = -1;
    goto done;
callback1:
    func_00422390(2);
    iGpffffb804 = 0;
    goto check2;
callback2:
    func_00422390(1);
    iGpffffb800 = 0;
    goto check3;
callback3:
    func_004222c0(2);
    iGpffffb7fc = 0;
    goto cleanup;
done:
    ;
}
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely off
// FUN_003F4C90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4c90);
// FUN_003F4F30
void func_003f4f30(void)
{
    extern void func_003f4a80(void);

    func_003f4a80();
    iGpffffb7e8 = 0;
    if (iGpffffb7f8 == 0) {
        goto callback;
    }
cleanup:
    iGpffffb7f4 = 0;
    iGpffffb7f8 = 0;
    iGpffffb7ec = 0;
    iGpffffb7f0 = 0;
    goto done;
callback:
    jtbl_008873EC[0]((void *)iGpffffb7f4);
    goto cleanup;
done:
    return;
}
/* measured: retail uses plain branches in func_003f4f90. */
#pragma no_branch_likely on
// FUN_003F4F90
s32 func_003f4f90(s32 arg0, s32 arg1, s32 arg2)
{
    s32 result;
    s32 var_5;

    var_5 = arg1;
    if (var_5 == 0) {
        var_5 = iGpffffabd4;
    }
    if (iGpffffb7e8 != 0) {
        goto zero;
    }
    if (arg2 == 0) {
        goto success;
    }
    if ((arg2 & 0x7f) != 0) {
        return 0;
    }
    goto assign_arg2;
zero:
    result = 0;
    goto return_result;
assign_arg2:
    iGpffffb7f4 = arg2;
success:
    iGpffffb7f8 = arg0;
    iGpffffabd4 = var_5;
    result = 1;
return_result:
    return result;
}
/* measured: closes no_branch_likely around func_003f4f90. */
#pragma no_branch_likely off
/* measured: retail emits plain bnez/beqz branches with the zero-return block last. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f6780. */
#pragma no_branch_likely off
/* measured: retail uses plain bnez/beqz branches in func_003f68a0. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f68a0. */
#pragma no_branch_likely off
/* measured: retail cleanup tests are plain beqz. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_004015e0. */
#pragma no_branch_likely off
/* measured: no_branch_likely preserves the two retail plain null branches. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_00402680. */
#pragma no_branch_likely off
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

/* measured: closes optimization_level 3 around func_0041f208. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6e0.c (1 function markers) */
/* measured: source unit 0041f6e0 requires optimization_level 3. */
#pragma optimization_level 3

/* measured: closes optimization_level 3 around func_0041f6e0. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6f0.c (1 function markers) */
/* measured: source unit 0041f6f0 requires optimization_level 3. */
#pragma optimization_level 3

/* measured: closes optimization_level 3 around func_0041f6f0. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004222b0.c (1 function markers) */
/* measured: source unit 004222b0 requires optimization_level 3. */
#pragma optimization_level 3

/* measured: closes optimization_level 3 around func_004222b0. */
#pragma optimization_level 2
