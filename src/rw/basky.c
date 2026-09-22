/* Retail RenderWare-block functions attributed to basky.c.
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
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f4be0. */
#pragma no_branch_likely off
/* measured: retail uses plain branches in func_003f4f90. */
#pragma no_branch_likely on
/* measured: closes no_branch_likely around func_003f4f90. */
#pragma no_branch_likely off
// FUN_003F5040
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5040);
// FUN_003F5070
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5070);
// FUN_003F5D90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5d90);
// FUN_003F6440
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6440);
/* measured: retail emits plain bnez/beqz branches with the zero-return block last. */
#pragma no_branch_likely on
// FUN_003F6780
s32 func_003f6780(s32 arg0)
{
    if (iGpffffb958 != 0) {
        goto done_zero;
    }
    if (arg0 == 0) {
        goto zero_case;
    }
nonzero:
    iGpffffac00 = 0x20;
    D_008872F8[0] = 0x4B7FFFFF;
    goto done_one;
zero_case:
    iGpffffac00 = 0x10;
    D_008872F8[0] = 0x477FFF00;
done_one:
    return 1;
done_zero:
    return 0;
}
/* measured: closes no_branch_likely around func_003f6780. */
#pragma no_branch_likely off
/* measured: retail uses plain bnez/beqz branches in func_003f68a0. */
#pragma no_branch_likely on
// FUN_003F68A0
s32 *func_003f68a0(s32 *arg0, u32 arg1)
{
    s32 temp_7;
    u32 var_5;
    u8 *temp_4;
    u8 *temp_6;
    s32 *result;
    result = arg0;
    if (arg0 != NULL) {
        temp_7 = *arg0;
        if (temp_7 != 0) {
            if (arg1 > 3U)
                var_5 = 3;
            else
                var_5 = arg1;
            temp_6 = (u8 *)(temp_7 + iGpffffb938);
            *(u16 *)(temp_6 + 0x14) = (u16)(*(u16 *)(temp_6 + 0x14) & 0xCFFF);
            temp_4 = (u8 *)(*arg0 + iGpffffb938);
            *(u16 *)(temp_4 + 0x14) = (u16)(*(u16 *)(temp_4 + 0x14) | (u16)(((var_5 & 0xFFFF) << 0xC) & 0xFFFF));
            return result;
        }
    }
    return NULL;
}
/* measured: closes no_branch_likely around func_003f68a0. */
#pragma no_branch_likely off
// FUN_003F6910
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6910);
// FUN_003F6990
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6990);
// FUN_003F69F0
s32 func_003f69f0(s32 *arg0)
{
    s32 var_2;

    var_2 = 0;
    if ((arg0 != NULL) && (*arg0 != 0)) {
        var_2 = 4;
    }
    return var_2;
}
// FUN_003F6A10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6a10);
// FUN_003F73D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f73d0);
// FUN_003F7490
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7490);
// FUN_003F79B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f79b0);
// FUN_003F7A70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7a70);
// FUN_003F8110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f8110);
// FUN_003F9750
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f9750);
// FUN_003F98A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f98a0);
// FUN_003FB830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb830);
// FUN_003FB9D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb9d0);
// FUN_003FBC50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fbc50);
// FUN_003FBFF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fbff0);
// FUN_003FC280
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fc280);
// FUN_003FC5F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fc5f0);
// FUN_003FD230
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd230);
// FUN_003FD460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd460);
// FUN_003FD520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd520);
// FUN_003FD690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd690);
// FUN_003FD940
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd940);
// FUN_003FDD10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fdd10);
// FUN_003FDDC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fddc0);
// FUN_003FE320
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe320);
// FUN_003FE630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe630);
// FUN_003FE700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe700);
// FUN_003FEA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fea90);
// FUN_003FF160
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff160);
// FUN_004010C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004010c0);
// FUN_00401450
s32 *func_00401450(void)
{
    return &D_0070C220[0];
}
// FUN_00401460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401460);
/* measured: retail cleanup tests are plain beqz. */
#pragma no_branch_likely on
// FUN_004015E0
s32 func_004015e0(void)
{
    s32 temp_16;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = iGpffffb958;
    if (temp_16 != 0) {
        temp_4 = iGpffffb904;
        if (temp_4 != NULL) {
            if (temp_4 != NULL) {
                func_003ec330(temp_4);
            }
            iGpffffb904 = NULL;
        }
        temp_4_2 = (u8 *)iGpffffb900;
        if (temp_4_2 != NULL) {
            if (temp_4_2 != NULL) {
                func_003ec330(temp_4_2);
            }
            iGpffffb900 = 0;
        }
    }
    return temp_16;
}
/* measured: closes no_branch_likely around func_004015e0. */
#pragma no_branch_likely off
// FUN_00401650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401650);
// FUN_00401870
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401870);
// FUN_00401AA0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401aa0);
// FUN_00401B90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401b90);
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
