/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct RwObjectOwnerLink RwObjectOwnerLink;
typedef struct RwObject RwObject;

/* Canonical grouped function declarations. */
extern s32 iGpffffb994;
extern s32 iGpffffac10;
extern s32 iGpffffb900;
extern s32 iGpffffb9c0;
extern s32 iGpffffb9b8;
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
extern void func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
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
extern void (*D_00887310[])(void);
extern void (*D_00887314[])(void);
extern s32 func_0040afb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0040b230(u8 *arg0, s32 unused, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0040c0f0(s32 arg0, s32 arg1, s32 arg2);
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

// FUN_003E9240
u8 func_003e9240(RwObjectOwnerLink *param_1)
{
    return param_1->owner->type & 3;
}
/* measured: closes optimization_level 3 around func_003e9240. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9750.c (1 function markers) */
/* measured: source unit 003e9750 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_003E9250
void func_003e9250(u8 *arg0)
{
    extern void func_003e3b70(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern u8 D_0070B7A0[];
    u8 *temp_3;
    u8 *temp_5;
    s32 temp_2;
    s32 temp_6;
    s32 temp_7;

    *(u8 *)(arg0 + 0) = 0;
    temp_5 = arg0;
    *(u8 *)(arg0 + 1) = 0;
    temp_3 = temp_5 + 0x90;
    *(u8 *)(arg0 + 2) = 0;
    temp_7 = 3;
    *(u8 *)(arg0 + 3) = 0;
    temp_6 = 0x3f800000;
    *(s32 *)(arg0 + 4) = 0;
    temp_2 = 0x20003;
    *(s32 *)(arg0 + 0x90) = (s32)temp_3;
    *(s32 *)(arg0 + 0x94) = (s32)temp_3;
    *(s32 *)(arg0 + 0x1c) = temp_7;
    *(s32 *)(arg0 + 0x38) = temp_6;
    *(s32 *)(arg0 + 0x24) = temp_6;
    *(s32 *)(arg0 + 0x10) = temp_6;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x48) = 0;
    *(s32 *)(arg0 + 0x44) = 0;
    *(s32 *)(arg0 + 0x40) = 0;
    *(s32 *)(arg0 + 0x1c) |= temp_2;
    *(s32 *)(arg0 + 0x5c) = temp_7;
    *(s32 *)(arg0 + 0x78) = temp_6;
    *(s32 *)(arg0 + 0x64) = temp_6;
    *(s32 *)(arg0 + 0x50) = temp_6;
    *(s32 *)(arg0 + 0x60) = 0;
    *(s32 *)(arg0 + 0x58) = 0;
    *(s32 *)(arg0 + 0x54) = 0;
    *(s32 *)(arg0 + 0x74) = 0;
    *(s32 *)(arg0 + 0x70) = 0;
    *(s32 *)(arg0 + 0x68) = 0;
    *(s32 *)(arg0 + 0x88) = 0;
    *(s32 *)(arg0 + 0x84) = 0;
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x5c) |= temp_2;
    *(s32 *)(arg0 + 0x98) = 0;
    *(s32 *)(arg0 + 0x9c) = 0;
    *(u8 **)(arg0 + 0xa0) = temp_5;
    func_003e3b70(D_0070B7A0, temp_5, 0x3f800000, 3);
}
/* measured: retail callback guard is plain beqz, not bnel. */
#pragma no_branch_likely on
// FUN_003E9320
u8 *func_003e9320(void)
{
    u8 *temp_2;

    temp_2 = D_008873F8[0](
        *(u8 **)((u8 *)D_008872E0 + iGpffffb7c0),
        0x3000E);
    if (temp_2 != NULL) {
        func_003e9250(temp_2);
        return temp_2;
    }
    return NULL;
}
/* measured: closes no_branch_likely around func_003e9320. */
#pragma no_branch_likely off
// FUN_003E9390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9390);
/* measured: no_branch_likely keeps func_003e9460's plain branch guards. */
#pragma no_branch_likely on
// FUN_003E9460
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9460);
#pragma no_branch_likely off
// FUN_003E95C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e95c0);
/* measured: retail uses a plain beqz guard for func_003e9680. */
#pragma no_branch_likely on
// FUN_003E9680
u8 *func_003e9680(u8 *arg0)
{
    u8 temp_6;
    u8 *temp_3;
    u8 **head;

    temp_3 = *(u8 **)(arg0 + 0xa0);
    temp_6 = temp_3[3];
    if ((temp_6 & 3) == 0) {
        goto insert;
    }
flags:
    (*(u8 **)(arg0 + 0xa0))[3] = temp_6 | 3;
    arg0[3] |= 0xc;
    return arg0;
insert:
    head = (u8 **)&D_0088739C;
    *(u8 **)(temp_3 + 8) = *head;
    temp_3 = *(u8 **)(arg0 + 0xa0);
    *(u8 **)(temp_3 + 0xc) = (u8 *)head;
    temp_3 = *(u8 **)(arg0 + 0xa0);
    *(u8 **)(*head + 4) = temp_3 + 8;
    temp_3 = *(u8 **)(arg0 + 0xa0);
    *head = temp_3 + 8;
    goto flags;
}
/* measured: closes no_branch_likely around func_003e9680. */
#pragma no_branch_likely off
/* measured: retail uses a plain bnez for the callback guard. */
#pragma no_branch_likely on
// FUN_003E9700
u8 *func_003e9700(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xa0);
    if ((temp_4[3] & 1) == 0) {
        goto done;
    }
    goto callback;
done:
    return arg0 + 0x50;
callback:
    func_003ed960(temp_4);
    goto done;
}
/* measured: closes no_branch_likely around func_003e9700. */
#pragma no_branch_likely off
// FUN_003E9750
u32 func_003e9750(int param_1)
{
    return *(u32 *)(param_1 + 0xa0);
}
/* measured: closes optimization_level 3 around source unit 003e9750. */
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004125d0.c (1 function markers) */
/* measured: source unit 004125d0 requires optimization_level 3. */
#pragma optimization_level 3

// FUN_003E9760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9760);
/* measured: no_branch_likely on preserves plain list branches for func_003e9830. */
#pragma no_branch_likely on
// FUN_003E9830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9830);
/* measured: closes no_branch_likely around func_003e9830. */
#pragma no_branch_likely off
// FUN_003E99A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e99a0);
/* measured: closes no_branch_likely around func_003e99a0. */
#pragma no_branch_likely off
/* measured: retail list callback branches are plain beqz/bnez. */
#pragma no_branch_likely on
// FUN_003E9AF0
u8 *func_003e9af0(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2)
{
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(arg0 + 0x98);
    if (var_4 == NULL) {
        goto done_zero;
    }
loop_1:
    temp_16 = *(u8 **)(var_4 + 0x9c);
    if (arg1(var_4, arg2) != 0) {
        goto callback;
    }
    goto done;
done:
    return arg0;
callback:
    var_4 = temp_16;
    if (var_4 != NULL) {
        goto loop_1;
    }
done_zero:
    return arg0;
}
/* measured: closes no_branch_likely around func_003e9af0. */
#pragma no_branch_likely off
// FUN_003E9B60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9b60);
/* measured: retail uses plain beqz in func_003e9c10's flag test. */
#pragma no_branch_likely on
// FUN_003E9C10
u8 *func_003e9c10(u8 *arg0)
{
    extern s32 func_003e0c90();
    u8 *temp_3;
    u8 temp_5;
    u8 **head;

    func_003e0c90(arg0 + 0x10);
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
// FUN_003E9CB0
u8 *func_003e9cb0(u8 *arg0)
{
    extern s32 func_003e0e20();
    u8 *temp_3;
    u8 temp_5;
    u8 **head;

    func_003e0e20(arg0 + 0x10);
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
/* measured: closes no_branch_likely around func_003e9cb0. */
#pragma no_branch_likely off
/* measured: sibling list helper func_003e9d50 uses plain beqz branches. */
#pragma no_branch_likely on
// FUN_003E9D50
u8 *func_003e9d50(u8 *arg0)
{
    extern s32 func_003e0870();
    u8 *temp_3;
    u8 temp_5;
    u8 **head;

    func_003e0870(arg0 + 0x10);
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
/* measured: closes no_branch_likely around func_003e9d50. */
#pragma no_branch_likely off
/* measured: func_003e9df0 uses plain beqz in the shared list setup. */
#pragma no_branch_likely on
// FUN_003E9DF0
u8 *func_003e9df0(u8 *arg0)
{
    u8 temp_6;
    u8 *temp_3;
    u8 **head;

    *(u32 *)(arg0 + 0x38) = 0x3F800000U;
    *(u32 *)(arg0 + 0x24) = 0x3F800000U;
    *(u32 *)(arg0 + 0x10) = 0x3F800000U;
    *(u32 *)(arg0 + 0x20) = 0;
    *(u32 *)(arg0 + 0x18) = 0;
    *(u32 *)(arg0 + 0x14) = 0;
    *(u32 *)(arg0 + 0x34) = 0;
    *(u32 *)(arg0 + 0x30) = 0;
    *(u32 *)(arg0 + 0x28) = 0;
    *(u32 *)(arg0 + 0x48) = 0;
    *(u32 *)(arg0 + 0x44) = 0;
    *(u32 *)(arg0 + 0x40) = 0;
    *(u32 *)(arg0 + 0x1C) |= 0x20003U;
    temp_3 = *(u8 **)(arg0 + 0xA0);
    temp_6 = *(u8 *)(temp_3 + 3);
    if ((temp_6 & 3) == 0) {
        goto insert;
    }
update:
    *(u8 *)(*(u8 **)(arg0 + 0xA0) + 3) = (u8)(temp_6 | 3);
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
/* measured: closes no_branch_likely around func_003e9df0. */
#pragma no_branch_likely off
// FUN_003E9EB0
void func_003e9eb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_003e3870(D_0070B7A0, arg0, arg1, arg2, arg3, arg4);
}
// FUN_003E9EE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003e9ee0);
// FUN_003EA130
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea130);
/* measured: callback guard in func_003ea2c0 is a plain beqz. */
#pragma no_branch_likely on
// FUN_003EA2C0
u8 *func_003ea2c0(s32 arg0, s32 arg1, s32 arg2)
{
    extern void func_003e3b70(u8 *arg0, u8 *arg1);
    u8 *temp_2;

    temp_2 = D_008873F8[0](
        *(u8 **)((u8 *)D_008872E0 + iGpffffb7c0),
        0x30018U);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = arg0;
        *(s32 *)(temp_2 + 8) = arg1;
        *(s32 *)(temp_2 + 0xC) = arg2;
        *(s32 *)(temp_2 + 0x14) = 0;
        *(s32 *)(temp_2 + 0x18) = 0;
        *(s32 *)temp_2 = 0;
        func_003e3b70(D_0070B7C0, temp_2);
        return temp_2;
    }
    return NULL;
}
/* measured: closes no_branch_likely around func_003ea2c0. */
#pragma no_branch_likely off
/* measured: retail flag guard is plain beqz, not beql. */
#pragma no_branch_likely on
// FUN_003EA370
s32 func_003ea370(u8 *arg0)
{
    extern void func_003e3c20(u8 *arg0, u8 *arg1);

    if ((*(s32 *)arg0 & 1) != 0) {
        func_003ea510(arg0);
    }
    func_003e3c20(D_0070B7C0, arg0);
    jtbl_008873FC[0](*(u8 **)((u8 *)D_008872E0 + iGpffffb7e0), arg0);
    return 1;
}
/* measured: closes no_branch_likely around func_003ea370. */
#pragma no_branch_likely off
// FUN_003EA3E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea3e0);
// FUN_003EA510
u8 *func_003ea510(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x14));
    *(u8 **)(arg0 + 0x14) = NULL;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)arg0 &= ~1;
    return arg0;
}
// FUN_003EA560
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea560);
// FUN_003EA690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ea690);
// FUN_003EAA80
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaa80);
// FUN_003EAB70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eab70);
// FUN_003EAF00
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaf00);
// FUN_003EAF60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eaf60);
// FUN_003EB0D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb0d0);
// FUN_003EB1C0
s8 *func_003eb1c0(s8 *arg0)
{
    s32 sp1C;

    sp1C = 0;
    func_003eab70(arg0, 0x14, (s32 (*)(s32, s32))func_003eb0d0, &sp1C);
    return (s8 *)sp1C;
}
// FUN_003EB1F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb1f0);
// FUN_003EB3B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb3b0);
// FUN_003EB700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eb700);
// FUN_003EBAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebac0);
// FUN_003EBBF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebbf0);
// FUN_003EBDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebde0);
// FUN_003EBFF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ebff0);
/* measured: retail callback and flag branches are plain beqz/bnez. */
#pragma no_branch_likely on
// FUN_003EC110
s32 *func_003ec110(s32 *arg0, u8 *arg1)
{
    if (D_00887340[0](arg0, arg1, 0) == 0) {
        goto fail;
    }
    if ((arg1[0x22] & 1) != 0) {
        goto set_flag;
    }
    goto success;
success:
    return arg0;
set_flag:
    *arg0 |= 2;
    goto success;
fail:
    return NULL;
}
/* measured: closes no_branch_likely around func_003ec110. */
#pragma no_branch_likely off
/* measured: retail callback and flag branches are plain beqz/bnez. */
#pragma no_branch_likely on
// FUN_003EC180
u8 *func_003ec180(u8 *arg0, s32 *arg1)
{
    if (D_00887344[0](arg0, arg1, 0) == 0) {
        goto fail;
    }
    if ((*arg1 & 2) != 0) {
        goto set_flag;
    }
    goto success;
success:
    return arg0;
set_flag:
    arg0[0x22] |= 1;
    goto success;
fail:
    return NULL;
}
/* measured: closes no_branch_likely around func_003ec180. */
#pragma no_branch_likely off
/* measured: retail uses a plain bnez for the callback result. */
#pragma no_branch_likely on
// FUN_003EC1F0
s32 func_003ec1f0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5)
{
    extern s32 (*D_0088734C[])(u8 *arg0, s32 arg1, s32 arg2);
    u8 sp60[0x34];

    if (D_0088734C[0](sp60, arg0, arg1) == 0) {
        return 0;
    }
    *arg5 = (sp60[0x23] << 8) | sp60[0x20];
    *arg2 = *(s32 *)(sp60 + 0xc);
    *arg3 = *(s32 *)(sp60 + 0x10);
    *arg4 = *(s32 *)(sp60 + 0x14);
    return arg0;
}
/* measured: closes no_branch_likely around func_003ec1f0. */
#pragma no_branch_likely off
// FUN_003EC2A0
s32 func_003ec2a0(s32 arg0)
{
    D_00887368[0](0, arg0, 0);
    return arg0;
}
// FUN_003EC2E0
u8 *func_003ec2e0(u8 *arg0)
{
    D_00887388[0](0, (s32)arg0, 0);
    arg0[0x22] = (u8)(arg0[0x22] & ~0x18);
    return arg0;
}
// FUN_003EC330
s32 func_003ec330(u8 *arg0)
{
    extern void func_003e3c20(u8 *arg0, u8 *arg1);
    extern s32 (*D_0088733C[])(s32 arg0, s32 arg1, s32 arg2);
    extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);

    func_003e3c20(D_0070B7E0, arg0);
    D_0088733C[0](0, (s32)arg0, 0);
    jtbl_008873FC[0](*(u8 **)((u8 *)D_008872E0 + iGpffffb7e0 + 0x60), arg0);
    return 1;
}
// FUN_003EC3A0
void func_003ec3a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_003e3870(D_0070B7E0, arg0, arg1, arg2, arg3, arg4);
}
/* measured: retail uses a plain beqz for the callback result. */
#pragma no_branch_likely on
// FUN_003EC3D0
s32 func_003ec3d0(s32 arg0, s32 arg1)
{
    s32 sp1C;

    if (D_00887384[0](&sp1C, arg0, arg1) != 0) {
        return sp1C;
    }
    return 0;
}
/* measured: closes no_branch_likely around func_003ec3d0. */
#pragma no_branch_likely off
/* measured: retail callback result uses a plain beqz, not bnel. */
#pragma no_branch_likely on
// FUN_003EC420
s32 func_003ec420(u8 *arg0)
{
    extern s32 (*D_00887398[])(s32 *arg0, u8 *arg1, s32 arg2);
    s32 sp1C;

    if (((arg0[0x23] << 8) & 0x8000) == 0) {
        return 1;
    }
    if (D_00887398[0](&sp1C, arg0, 0) != 0) {
        return sp1C;
    }
    return -1;
}
/* measured: closes no_branch_likely around func_003ec420. */
#pragma no_branch_likely off
// FUN_003EC480
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec480);
/* measured: callback guard uses retail's plain bnez in func_003ec4f0. */
#pragma no_branch_likely on
// FUN_003EC4F0
u8 *func_003ec4f0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    extern s32 (*D_00887358[])(u8 *arg0, u8 *arg1, s32 arg2);
    s16 temp_7;

    if ((arg0[0x21] & 0x80) == 0) {
        return NULL;
    }
    *(s32 *)(arg0 + 0xc) = *(s32 *)(arg2 + 8);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg2 + 0xc);
    *(s16 *)(arg0 + 0x1c) = *(s16 *)(arg1 + 0x1c) + *(s16 *)arg2;
    temp_7 = *(s16 *)(arg1 + 0x1e);
    *(s16 *)(arg0 + 0x1e) = temp_7 + *(s16 *)(arg2 + 4);
    if (D_00887358[0](arg0, arg1, 0) == 0) {
        return NULL;
    }
    *(s32 *)arg0 = *(s32 *)arg1;
    return arg0;
}
/* measured: closes no_branch_likely around func_003ec4f0. */
#pragma no_branch_likely off
// FUN_003EC590
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec590);
/* measured: retail uses a plain beqz for the callback result. */
#pragma no_branch_likely on
// FUN_003EC6A0
s32 func_003ec6a0(s32 arg0, s32 arg1, s32 arg2)
{
    s32 sp1C;

    if (D_00887364[0](&sp1C, arg0, arg2 + ((arg1 & 0xff) << 8)) != 0) {
        return sp1C;
    }
    return 0;
}
/* measured: closes no_branch_likely around func_003ec6a0. */
#pragma no_branch_likely off
/* measured: retail uses a plain beqz for the callback guard. */
#pragma no_branch_likely on
// FUN_003EC6F0
s32 func_003ec6f0(s32 arg0)
{
    extern void func_003e12f0(s32 arg0);
    s32 temp_4;

    temp_4 = *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x60);
    if (temp_4 != 0) {
        func_003e12f0(temp_4);
        *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x60) = 0;
    }
    iGpffffb9b4 = iGpffffb9b4 - 1;
    return arg0;
}
/* measured: closes no_branch_likely around func_003ec6f0. */
#pragma no_branch_likely off
// FUN_003EC760
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec760);
// FUN_003EC840
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ec840);
// FUN_003ECE40
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ece40);
// FUN_003ED0B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed0b0);
// FUN_003ED2D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed2d0);
// FUN_003ED450
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed450);
// FUN_003ED540
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed540);
// FUN_003ED650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed650);
// FUN_003ED7E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed7e0);
// FUN_003ED850
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed850);
// FUN_003ED960
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ed960);
// FUN_003EDA60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eda60);
// FUN_003EDB30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003edb30);
// FUN_003EDC30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003edc30);
// FUN_003EDE50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ede50);
// FUN_003EE1D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ee1d0);
// FUN_003EE470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ee470);
// FUN_003EEA90
void func_003eea90(void)
{
    if (*(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x1c) != 0) {
        func_003ee470();
        return;
    }
    func_003ee1d0();
}
// FUN_003EEAE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eeae0);
// FUN_003EEE70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eee70);
// FUN_003EEF60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003eef60);
// FUN_003EF000
s32 func_003ef000(s32 arg0)
{
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x1c) = arg0;
    return 1;
}
// FUN_003EF020
s32 func_003ef020(void)
{
    return *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x1c);
}
// FUN_003EF040
s32 func_003ef040(s32 arg0)
{
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x20) = arg0;
    return 1;
}
// FUN_003EF060
s32 func_003ef060(void)
{
    return *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x20);
}
// FUN_003EF080
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef080);
/* measured: retail ef0d0 allocator guard is plain beqz, not bnel. */
#pragma no_branch_likely on
// FUN_003EF0D0
u8 *func_003ef0d0(void)
{
    extern u8 *(*D_008873F8[])(u8 *arg0, s32 arg1);
    extern s32 D_008872E0[];
    extern s32 iGpffffb7e0;
    extern u8 D_0070B820[];
    extern void func_003e3b70(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    u8 *temp_2;
    u8 *temp_6;

    temp_2 = D_008873F8[0](
        *(u8 **)((u8 *)D_008872E0 + iGpffffb7e0 + 0xC),
        0x30016);
    if (temp_2 != NULL) {
        temp_2[0] = 6;
        temp_2[1] = 0;
        temp_2[2] = 0;
        temp_6 = temp_2 + 0x10;
        temp_2[3] = 0;
        *(s32 *)(temp_2 + 4) = 0;
        *(s32 *)(temp_2 + 0x10) = *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0);
        *(u8 **)(temp_2 + 0x14) = (u8 *)D_008872E0 + iGpffffb7e0;
        *(u8 **)(*(u8 **)((u8 *)D_008872E0 + iGpffffb7e0) + 4) = temp_6;
        *(u8 **)((u8 *)D_008872E0 + iGpffffb7e0) = temp_6;
        *(u8 **)(temp_2 + 8) = temp_2 + 8;
        *(u8 **)(temp_2 + 0xC) = temp_2 + 8;
        func_003e3b70(D_0070B820, temp_2, temp_6, (u8 *)D_008872E0);
        return temp_2;
    }
    return NULL;
}
/* measured: closes no_branch_likely around func_003ef0d0. */
#pragma no_branch_likely off
/* measured: retail ef1b0 equal-head branch is plain beq, not beql. */
#pragma no_branch_likely on
// FUN_003EF1B0
s32 func_003ef1b0(u8 *arg0)
{
    extern s32 func_003ef260(u8 *arg0, s32 (*arg1)(), s32 arg2);
    extern s32 func_003ef3a0();
    extern void func_003e3c20(u8 *arg0, u8 *arg1);
    extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
    extern s32 D_008872E0[];
    extern s32 iGpffffb7e0;
    extern u8 D_0070B820[];
    u8 *clear;
    u8 **temp_6;

    clear = (u8 *)D_008872E0 + iGpffffb7e0 + 0x10;
    if (*(u8 **)clear == arg0) {
        goto clear_head;
    }
process:
    func_003ef260(arg0, func_003ef3a0, 0);
    func_003e3c20(D_0070B820, arg0);
    *(u8 **)(*(u8 **)(arg0 + 0x14)) = *(u8 **)(arg0 + 0x10);
    temp_6 = *(u8 ***)(arg0 + 0x14);
    *(u8 **)(*(u8 **)(arg0 + 0x10) + 4) = (u8 *)temp_6;
    jtbl_008873FC[0](
        *(u8 **)((u8 *)D_008872E0 + iGpffffb7e0 + 0xC),
        arg0);
    return 1;
clear_head:
    *(u8 **)clear = NULL;
    goto process;
}
/* measured: closes no_branch_likely around func_003ef1b0. */
#pragma no_branch_likely off
// FUN_003EF260
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef260);
// FUN_003EF2E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef2e0);
// FUN_003EF3A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef3a0);
// FUN_003EF470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef470);
// FUN_003EF510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef510);
/* measured: retail list-detach branch in func_003ef5b0 is plain bnez. */
#pragma no_branch_likely on
// FUN_003EF5B0
u8 *func_003ef5b0(u8 *arg0, u8 *arg1)
{
    typedef struct RwLink {
        struct RwLink *next;
        struct RwLink *prev;
    } RwLink;
    typedef struct RwList {
        u8 padding[4];
        u8 *item;
        RwLink link;
    } RwList;
    typedef struct RwNode {
        u8 padding[8];
        RwLink link;
    } RwNode;
    RwList *list;
    RwNode *node;

    list = (RwList *)arg1;
    node = (RwNode *)arg0;
    if (list->item != NULL) {
        goto detach;
    }
insert:
    list->item = arg0;
    list->link.next = node->link.next;
    list->link.prev = &node->link;
    node->link.next->prev = &list->link;
    node->link.next = &list->link;
    return arg1;
detach:
    list->link.prev->next = list->link.next;
    list->link.next->prev = list->link.prev;
    goto insert;
}
/* measured: closes no_branch_likely around func_003ef5b0. */
#pragma no_branch_likely off
/* measured: no_branch_likely preserves the retail list-detach branch. */
#pragma no_branch_likely on
// FUN_003EF610
u8 *func_003ef610(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        goto body;
    }
    goto done;
done:
    return arg0;
body:
    *(s32 *)(arg0 + 4) = 0;
    *(u8 **)(*(u8 **)(arg0 + 0xc)) = *(u8 **)(arg0 + 8);
    *(u8 **)(*(u8 **)(arg0 + 8) + 4) = *(u8 **)(arg0 + 0xc);
    goto done;
}
/* measured: closes no_branch_likely around func_003ef610. */
#pragma no_branch_likely off
// FUN_003EF650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef650);
// FUN_003EF6B0
s32 func_003ef6b0(s32 arg0)
{
    *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x10) = arg0;
    return arg0;
}
// FUN_003EF6D0
s32 func_003ef6d0(void)
{
    return *(s32 *)((u8 *)D_008872E0 + iGpffffb7e0 + 0x10);
}
/* measured: no_branch_likely preserves the retail callback null branch. */
#pragma no_branch_likely on
// FUN_003EF6F0
s32 func_003ef6f0(void)
{
    s32 (*temp_2)(void);

    temp_2 = *(s32 (**)(void))((u8 *)D_008872E0 + iGpffffb7e0 + 0x30);
    if (temp_2 == NULL) {
        goto zero;
    }
    return temp_2();
zero:
    return 0;
}
/* measured: closes no_branch_likely around func_003ef6f0. */
#pragma no_branch_likely off
// FUN_003EF740
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef740);
// FUN_003EF890
void func_003ef890(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_003e3870(D_0070B800, arg0, arg1, arg2, arg3, arg4);
}
// FUN_003EF8C0
s32 func_003ef8c0(void)
{
    s32 (*func)(void);

    func = *(s32 (**)(void))((u8 *)D_008872E0 + iGpffffb7e0 + 0x2c);
    return func() != 0;
}
// FUN_003EF900
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ef900);
// FUN_003EFAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efac0);
// FUN_003EFD20
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efd20);
/* measured: no_branch_likely preserves the retail list-link branch. */
#pragma no_branch_likely on
// FUN_003EFDA0
void func_003efda0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        goto body;
    }
    goto done;
done:
    ;
    return;
body:
    *(u8 **)(*(u8 **)(arg0 + 0xc)) = *(u8 **)(arg0 + 8);
    *(u8 **)(*(u8 **)(arg0 + 8) + 4) = *(u8 **)(arg0 + 0xc);
    goto done;
}
/* measured: closes no_branch_likely around func_003efda0. */
#pragma no_branch_likely off
// FUN_003EFDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003efde0);
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
// FUN_003F07D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f07d0);
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
// FUN_003F17E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f17e0);
// FUN_003F1CE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f1ce0);
// FUN_003F24A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f24a0);
// FUN_003F25C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f25c0);
// FUN_003F26C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f26c0);
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
// FUN_003F4FF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f4ff0);
// FUN_003F5040
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5040);
// FUN_003F5070
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5070);
// FUN_003F5D90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f5d90);
// FUN_003F6440
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6440);
// FUN_003F6690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f6690);
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
// FUN_003F7A60
s32 func_003f7a60(s32 *arg0, s32 arg1)
{
    *arg0 = arg1;
    return 1;
}
// FUN_003F7A70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f7a70);
// FUN_003F8110
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f8110);
// FUN_003F9750
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f9750);
// FUN_003F98A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003f98a0);
// FUN_003FB3F0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fb3f0);
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
// FUN_003FD630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd630);
// FUN_003FD690
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd690);
// FUN_003FD940
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fd940);
// FUN_003FDD10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fdd10);
// FUN_003FDDC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fddc0);
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
// FUN_003FE320
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe320);
// FUN_003FE470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe470);
// FUN_003FE630
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe630);
// FUN_003FE700
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fe700);
// FUN_003FEA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003fea90);
// FUN_003FF160
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff160);
// FUN_003FF5B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_003ff5b0);
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
// FUN_00401B80
s32 func_00401b80(void)
{
    return iGpffffb900;
}
// FUN_00401B90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00401b90);
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
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402410);
// FUN_00402470
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402470);
// FUN_00402510
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402510);
// FUN_00402570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402570);
// FUN_00402600
s32 func_00402600(void)
{
    extern u8 *func_003ec590(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_003ec330(u8 *arg0);
    extern u8 *iGpffffb980;
    extern u8 *iGpffffb978;
    extern u8 *iGpffffb97c;
    extern s32 iGpffffb970;
    u8 *temp_2;
    u8 *temp_2_2;

    iGpffffb980 = NULL;
    temp_2 = func_003ec590(0, 0, 0, 0x80);
    iGpffffb978 = temp_2;
    if (temp_2 == NULL) {
        goto fail_first;
    }
    temp_2_2 = func_003ec590(0, 0, 0, 0x80);
    iGpffffb97c = temp_2_2;
    if (temp_2_2 == NULL) {
        goto fail_second;
    }
    iGpffffb970 = 0;
    return 1;
fail_first:
    return 0;
fail_second:
    func_003ec330(iGpffffb978);
    iGpffffb978 = NULL;
    return 0;
}
/* measured: no_branch_likely preserves the two retail plain null branches. */
#pragma no_branch_likely on
// FUN_00402680
void func_00402680(void)
{
    u8 *temp_4;
    u8 *temp_4_2;

    temp_4 = iGpffffb978;
    if (temp_4 == NULL) {
        goto second;
    }
    func_003ec330(temp_4);
    iGpffffb978 = NULL;
second:
    temp_4_2 = iGpffffb97c;
    if (temp_4_2 == NULL) {
        goto done;
    }
    func_003ec330(temp_4_2);
    iGpffffb97c = NULL;
done:
    ;
}
/* measured: closes no_branch_likely around func_00402680. */
#pragma no_branch_likely off
// FUN_004026D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004026d0);
// FUN_00402970
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402970);
// FUN_00402AB0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402ab0);
// FUN_00402C10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402c10);
// FUN_00402D50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402d50);
// FUN_00402FE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00402fe0);
// FUN_00403170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00403170);
// FUN_00403390
s32 func_00403390(void)
{
    s32 sp10[4];
    s32 var_2;
    u8 *temp_3;

    temp_3 = iGpffffb980;
    var_2 = 0;
    if (temp_3 != NULL) {
        sp10[1] = 0;
        sp10[0] = 0;
        sp10[2] = *(s32 *)(temp_3 + 0xc);
        sp10[3] = *(s32 *)(temp_3 + 0x10);
        var_2 = func_00402d50(NULL, sp10);
    }
    return var_2;
}
// FUN_004033E0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004033e0);
// FUN_00403930
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00403930);
// FUN_004052B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004052b0);
// FUN_00406B60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00406b60);
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
// FUN_00407DF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407df0);
// FUN_00407FF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00407ff0);
// FUN_00409150
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409150);
// FUN_00409D30
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409d30);
// FUN_00409E10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00409e10);
// FUN_0040A090
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a090);
// FUN_0040A500
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a500);
// FUN_0040A650
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a650);
// FUN_0040A800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040a800);
// FUN_0040AA10
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040aa10);
// FUN_0040AA60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040aa60);
// FUN_0040ADF0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040adf0);
/* measured: retail selector branch is plain beqz, not beql. */
#pragma no_branch_likely on
// FUN_0040AFB0
s32 func_0040afb0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *base;

    if ((iGpffffb984 & 1) != 0) {
        base = D_00753340;
    } else {
        base = D_00753330;
    }
    func_0040adf0(base, 0, arg0 + (arg2 << 6), arg0 + (arg3 << 6));
    return 1;
}
/* measured: closes no_branch_likely around func_0040afb0. */
#pragma no_branch_likely off
// FUN_0040B010
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b010);
/* measured: retail selector branch in func_0040b230 is plain beqz, not beql. */
#pragma no_branch_likely on
// FUN_0040B230
s32 func_0040b230(u8 *arg0, s32 unused, s32 arg2, s32 arg3, s32 arg4)
{
    extern s32 func_0040b010(void *arg0, s32 arg1, u8 *arg2, u8 *arg3,
                             u8 *arg4, void *arg5);
    u8 *base;

    if ((iGpffffb984 & 1) != 0) {
        base = D_00753340;
    } else {
        base = D_00753330;
    }
    func_0040b010(
        base,
        0,
        arg0 + (arg2 << 6),
        arg0 + (arg3 << 6),
        arg0 + (arg4 << 6),
        base);
    return 1;
}
/* measured: closes no_branch_likely around func_0040b230. */
#pragma no_branch_likely off
// FUN_0040B290
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b290);
// FUN_0040B520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b520);
// FUN_0040B7B0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040b7b0);
// FUN_0040BAC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040bac0);
// FUN_0040BDE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040bde0);
/* measured: retail 0040c0f0 uses plain blez/beqz branches. */
#pragma no_branch_likely on
// FUN_0040C0F0
s32 func_0040c0f0(s32 arg0, s32 arg1, s32 arg2)
{
    extern u8 iGpffffb984;
    extern u8 D_00753330[];
    extern u8 D_00753340[];
    extern void (*D_0070C2E0[])(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    u8 *var_4;

    if ((arg0 > 0) && ((u32)arg0 < 6U)) {
        if ((iGpffffb984 & 1) != 0) {
            var_4 = D_00753340;
        } else {
            var_4 = D_00753330;
        }
        D_0070C2E0[arg0](var_4, 0, arg1, arg2);
    }
    return 1;
}
/* measured: closes no_branch_likely around func_0040c0f0. */
#pragma no_branch_likely off
// FUN_0040C170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c170);
// FUN_0040C420
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c420);
// FUN_0040C6D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040c6d0);
// FUN_0040CA00
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040ca00);
// FUN_0040CD60
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040cd60);
/* measured: retail func_0040d0a0 uses plain blez/beqz branches. */
#pragma no_branch_likely on
// FUN_0040D0A0
s32 func_0040d0a0(s32 arg0, s32 arg1)
{
    u8 *base;

    if ((arg0 > 0) && ((u32)arg0 < 6U)) {
        if ((iGpffffb984 & 1) != 0) {
            base = D_00753340;
        } else {
            base = D_00753330;
        }
        D_0070C300[arg0](base, 0, arg1);
    }
    return 1;
}
/* measured: closes no_branch_likely around func_0040d0a0. */
#pragma no_branch_likely off
// FUN_0040D110
void func_0040d110(void)
{
    D_00887308[0] = (void (*)(void))func_0040afb0;
    D_0088730C[0] = (void (*)(void))func_0040b230;
    D_00887310[0] = (void (*)(void))func_0040c0f0;
    D_00887314[0] = (void (*)(void))func_0040d0a0;
    func_0040aa60((void (*)(void))func_0040c0f0);
}
// FUN_0040D160
void func_0040d160(void)
{
}
// FUN_0040D170
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d170);
// FUN_0040D570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d570);
// FUN_0040D720
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040d720);
// FUN_0040DA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040da90);
// FUN_0040DCC0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040dcc0);
// FUN_0040DF40
void func_0040df40(void)
{
}
// FUN_0040DF50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040df50);
// FUN_0040E830
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040e830);
// FUN_0040EEE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040eee0);
// FUN_0040F020
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f020);
// FUN_0040F1B0
void func_0040f1b0(void)
{
}
// FUN_0040F1C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f1c0);
// FUN_0040F480
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f480);
// FUN_0040F570
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040f570);
// FUN_0040FA90
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040fa90);
// FUN_0040FCD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_0040fcd0);
// FUN_00410080
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410080);
// FUN_00410360
s32 func_00410360(void)
{
    return D_0070C35C[0];
}
// FUN_00410370
s32 func_00410370(s32 arg0, s32 *arg1, s32 *arg2)
{
    u8 *temp_4;

    temp_4 = (u8 *)(arg0 + iGpffffb938);
    *arg2 = *(s32 *)(temp_4 + 8);
    *arg1 = *(s32 *)(temp_4 + 0xc);
    return arg0;
}
// FUN_00410390
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410390);
// FUN_00410420
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410420);
/* measured: retail 004104d0 null guard is plain beqz, not beql. */
#pragma no_branch_likely on
// FUN_004104D0
s32 func_004104d0(void)
{
    u8 *temp_3;

    temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
    if (*(s32 *)(temp_3 + 0x44) == 0) {
        goto zero;
    }
    func_0043f9c8(temp_3 + 0x40, 0, 0x3c);
    goto done;
zero:
    return 0;
done:
    return 1;
}
/* measured: closes no_branch_likely around func_004104d0. */
#pragma no_branch_likely off
// FUN_00410520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410520);
// FUN_004106A0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004106a0);
// FUN_00410800
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410800);
// FUN_00410930
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410930);
/* measured: retail uses plain null branches in func_00410a40. */
#pragma no_branch_likely on
// FUN_00410A40
s32 func_00410a40(s32 arg0)
{
    s32 temp_2;
    u8 *temp_3;

    if (arg0 == 0)
        goto null_path;
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0) = arg0;
finish:
    return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0);
null_path:
    temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
    temp_2 = *(s32 *)(temp_3 + 0x1c);
    if (temp_2 != 0) {
        *(s32 *)temp_3 = temp_2;
    } else {
        *(s32 *)temp_3 = 0;
    }
    goto finish;
}
/* measured: closes no_branch_likely around func_00410a40. */
#pragma no_branch_likely off
/* measured: retail preserves plain switch and callback branches in func_00410ab0. */
#pragma no_branch_likely on
// FUN_00410AB0
s32 func_00410ab0(s32 arg0, u32 arg1)
{
    s32 error_set[2];
    s32 error_get[2];
    s32 temp_2;
    u8 *temp_3;

    if (arg0 != 0) {
        switch (arg1) {
        case 3:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 4) = arg0;
            return arg0;
        case 5:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 8) = arg0;
            return arg0;
        case 4:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0xC) = arg0;
            return arg0;
        case 1:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x10) = arg0;
            return arg0;
        case 2:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x14) = arg0;
            return arg0;
        case 6:
            *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x18) = arg0;
            return arg0;
        default:
            error_set[0] = 1;
            error_set[1] = func_003df590(0x25);
            func_003df4d0(error_set);
error_return:
            return 0;
        }
    } else {
        switch (arg1) {
        case 3:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x20);
            if (temp_2 == 0)
                goto zero3;
            *(s32 *)(temp_3 + 4) = temp_2;
read3:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 4);
        case 5:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x24);
            if (temp_2 == 0)
                goto zero5;
            *(s32 *)(temp_3 + 8) = temp_2;
read5:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 8);
        case 4:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x28);
            if (temp_2 == 0)
                goto zero4;
            *(s32 *)(temp_3 + 0xC) = temp_2;
read4:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x28);
        case 1:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x2C);
            if (temp_2 == 0)
                goto zero1;
            *(s32 *)(temp_3 + 0x10) = temp_2;
read1:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x2C);
        case 2:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x30);
            if (temp_2 == 0)
                goto zero2;
            *(s32 *)(temp_3 + 0x14) = temp_2;
read2:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x30);
        case 6:
            temp_3 = (u8 *)((u8 *)D_008872E0 + iGpffffb9b0);
            temp_2 = *(s32 *)(temp_3 + 0x34);
            if (temp_2 == 0)
                goto zero6;
            *(s32 *)(temp_3 + 0x18) = temp_2;
read6:
            return *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x34);
        default:
            error_get[0] = 1;
            error_get[1] = func_003df590(0x25);
            func_003df4d0(error_get);
            goto error_return;
        }
    }
zero3:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 4) = 0;
    goto read3;
zero5:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 8) = 0;
    goto read5;
zero4:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0xC) = 0;
    goto read4;
zero1:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x10) = 0;
    goto read1;
zero2:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x14) = 0;
    goto read2;
zero6:
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x18) = 0;
    goto read6;
}
/* measured: closes no_branch_likely around func_00410ab0. */
#pragma no_branch_likely off
/* measured: retail preserves plain return branches in func_00410df0. */
#pragma no_branch_likely on
// FUN_00410D90
s32 func_00410d90(s32 arg0)
{
    func_00415940((void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x20));
    func_00415920((void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x1c));
    iGpffffb9b4 -= 1;
    return arg0;
}
// FUN_00410DF0
s32 func_00410df0(s32 arg0, s32 arg1)
{
    s32 var_2;
    u8 *temp_4;

    extern s32 func_00415930(void *arg0);
    extern s32 func_00415950(void *arg0);

    iGpffffb9b0 = arg1;
    temp_4 = (u8 *)((u8 *)D_008872E0 + arg1);
    iGpffffb9ac = (s32)temp_4;
    iGpffffb9b4 += 1;
    func_0043f9c8(temp_4, 0, 0x7C);
    var_2 = func_00415930(
        (void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x1C));
    if (var_2 != 0)
        goto call_second;
check_done:
    if (var_2 == 0)
        goto cleanup;
    return arg0;
call_second:
    var_2 = func_00415950(
        (void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x20));
    goto check_done;
cleanup:
    func_00415940(
        (void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x20));
    func_00415920(
        (void *)((u8 *)D_008872E0 + iGpffffb9b0 + 0x1C));
    iGpffffb9b4 -= 1;
    return 0;
}
/* measured: closes no_branch_likely around func_00410df0. */
#pragma no_branch_likely off
// FUN_00410ED0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410ed0);
// FUN_00410F00
s32 func_00410f00(s32 arg0)
{
    func_00410ff0();
    return arg0;
}
// FUN_00410F30
s32 func_00410f30(void)
{
    return 1;
}
// FUN_00410F40
void func_00410f40(void)
{
}
// FUN_00410F50
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00410f50);
#pragma no_branch_likely on
// FUN_00410FF0
s32 func_00410ff0(void)
{
    if (iGpffffb9bc != 0) {
        goto body;
    }
    goto done;
done:
    return 1;
body:
    func_003e12f0(*(s32 *)((u8 *)D_008872E0 + iGpffffb9b8));
    *(s32 *)((u8 *)D_008872E0 + iGpffffb9b8) = 0;
    func_00414fd0(iGpffffb9c0);
    iGpffffb9c0 = 0;
    iGpffffb9bc = 0;
    goto done;
}
/* measured: closes no_branch_likely around func_00410ff0. */
#pragma no_branch_likely off
// FUN_00411060
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411060);
// FUN_00411130
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411130);
// FUN_004114C0
s32 func_004114c0(void)
{
    return iGpffffb9c0;
}
// FUN_004114D0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004114d0);
/* measured: retail func_004115d0 uses plain beqz and a nop delay. */
#pragma no_branch_likely on
// FUN_004115D0
u8 *func_004115d0(void)
{
    extern s32 func_003df590();
    extern void func_003df4d0(void *arg0);
    struct {
        s32 sp28;
        s32 sp2C;
    } stack;
    u8 *temp_2;

    temp_2 = D_008873F8[0](
        *(u8 **)((u8 *)D_008872E0 + iGpffffb9b8),
        0x30409);
    if (temp_2 != NULL) {
        func_0043f9c8(temp_2, 0, 0x34);
        *(s32 *)temp_2 = 0;
        return temp_2;
    }
    stack.sp28 = 1;
    stack.sp2C = func_003df590(0x80000013, 0x34);
    func_003df4d0(&stack.sp28);
    return NULL;
}
/* measured: closes no_branch_likely around func_004115d0. */
#pragma no_branch_likely off
// FUN_00411670
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411670);
// FUN_00411740
u32 func_00411740(s32 arg0)
{
    extern s32 func_003df590();
    extern s32 func_003df4d0();
    struct {
        s32 sp18;
        s32 sp1C;
    } stack;
    u32 temp_2;
    u32 temp_5;

    temp_5 = (arg0 + 3) & ~3;
    temp_2 = (u32)(iGpffffb9b8 - temp_5);
    iGpffffb9b8 = temp_2;
    if (temp_2 >= (u32)iGpffffb9bc)
        return temp_2;
    iGpffffb9b8 = temp_2 + temp_5;
    stack.sp18 = 1;
    stack.sp1C = func_003df590(0x80000013, temp_5);
    func_003df4d0(&stack.sp18);
    return 0;
}
/* measured: retail uses a plain bnez for the allocator range guard. */
#pragma no_branch_likely on
// FUN_004117B0
u8 **func_004117b0(s32 arg0)
{
    extern s32 func_003df590();
    extern s32 func_003df4d0();
    struct {
        s32 sp18;
        s32 sp1C;
    } stack;
    u32 temp_3;
    u32 temp_5;

    temp_5 = (arg0 + 3) & ~3;
    temp_3 = (u32)(iGpffffb9bc + temp_5);
    iGpffffb9bc = temp_3;
    if (temp_3 > (u32)iGpffffb9b8)
        goto allocate;
    return (u8 **)(temp_3 - temp_5);
allocate:
    iGpffffb9bc = temp_3 - temp_5;
    stack.sp18 = 1;
    stack.sp1C = func_003df590(0x80000013, temp_5);
    func_003df4d0(&stack.sp18);
    return NULL;
}
/* measured: closes no_branch_likely around func_004117b0. */
#pragma no_branch_likely off
// FUN_00411820
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411820);
// FUN_004118C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004118c0);
// FUN_00411A70
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411a70);
// FUN_00411CE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411ce0);
// FUN_00411EE0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411ee0);
// FUN_00411FD0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00411fd0);
// FUN_004123C0
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_004123c0);
// FUN_00412520
INCLUDE_ASM("asm/nonmatchings/rwcore_grouped", func_00412520);
// FUN_004125D0
u32 func_004125d0(int param_1)
{
    return *(u32 *)(param_1 + 0x20);
}
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
