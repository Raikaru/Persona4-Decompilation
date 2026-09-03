#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_0039. */

extern s32 func_003df360(s32 arg0, s32 *arg1, s32 arg2);
extern s32 iGpffffb5e0;
extern void func_0038fb10(s32 arg0);
extern s32 func_00399b10(s32 arg0);
extern s32 func_00399b80(s32 arg0);
extern void func_0039a8a0(s32 arg0);
extern s32 iGpffffb5e4;
extern s32 iGpffffb5e8;
extern s32 iGpffffb5ec;
extern s32 iGpffffb5dc;
extern s32 iGpffffb5d8;
extern s32 iGpffffb5f0;
extern s32 iGpffffb5c8;
extern void (*jtbl_008873EC[])(void *);
extern u8 *func_0039aa50(u8 *arg0);
extern void func_003ef3a0(void *arg0, s32 arg1);
extern s32 func_0039a7e0(u8 *arg0, s32 arg1);
extern void func_0039a910(s32 arg0);
extern s32 D_007246B0;
extern s32 D_007246B4;
extern u8 D_008872E0[];
extern s32 D_007246EC;
extern s32 D_00884ACC[];
extern s32 D_00884AC8[];
extern s32 D_00884ADC[];
extern s32 D_00884A7C[];
extern s32 D_00884A80[];
extern s32 func_0039aa40(void);
extern void func_003e12f0(s32 arg0);
extern void func_00398410(u8 *arg0);
extern void (*jtbl_008873FC[])(s32, void *);
extern void func_003d5830(u8 *arg0);
extern s32 func_00397120(u8 *arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_003df4d0(s32 *arg0);
extern u8 *func_003bfae0(s32 arg0);
extern s32 func_003e9700(s32 arg0);
extern void func_003e0960(void *arg0, s32 arg1);
extern u8 *D_007646D0;
extern void func_0039b830(u8 *arg0);
extern void func_0039b8d0(s32 arg0, s32 arg1);
extern s32 func_003e1220(s32, s32, s32, s32, void *, s32);
extern s32 func_0039aa30(void);
extern s32 iGpffffaa08;
extern s32 iGpffffaa0c;
extern u8 D_00884A90[];
extern s32 func_0039b7c0(s32 arg0, s32 arg1);
extern void func_0039ba80(s32 arg0);
extern s32 func_003e8920(void);
extern u8 *func_0039ac80(u8 *arg0, u8 *arg1);
extern s32 func_0039ae90(s32 arg0, s32 arg1);
extern s32 func_0039b080(s32 arg0, s32 arg1);
extern s32 func_0039af40(s32 arg0, s32 arg1);
extern s32 func_003e8930(s32 arg0, s32 arg1, s32 (*arg2)(), s32 (*arg3)());
extern s32 func_003e5520(s32 arg0, s32 (*arg1)(), s32 (*arg2)(), s32 (*arg3)());
extern s32 func_003e9eb0(s32 arg0, s32 arg1, s32 (*arg2)(), s32 (*arg3)(), s32 (*arg4)());
extern s32 func_00396750();
extern s32 func_00396a40();
extern s32 func_00396c00();
extern s32 func_00396890();
extern s32 func_00396940();
extern s32 func_00396e80();
extern s32 func_003c1ab0(s32 arg0, s32 arg1, s32 (*arg2)(), s32 (*arg3)(), s32 (*arg4)());
extern s32 func_003c4310(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003c4370(s32 arg0, s32 arg1);
extern s32 func_003c1b60(s32 arg0, s32 arg1);
extern s32 func_003c8d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003c8d80(s32 arg0, s32 arg1);
extern s32 func_003c2b70(s32 arg0, s32 arg1, s32 (*arg2)(), s32 (*arg3)(), s32 (*arg4)());
extern s32 func_003c2ba0(s32 arg0, s32 (*arg1)(), s32 (*arg2)(), s32 (*arg3)());
extern s32 func_0038fb20(u8 *arg0);
extern s32 func_003df240(s32 arg0, s32 *arg1, s32 arg2);
extern u8 *func_004115d0(void);
extern s32 *func_00412ca0(s32 *arg0);
extern s32 *func_003cfa70(void);
extern u8 *func_00412fb0(u8 *arg0, s32 *arg1, s32 *arg2, s32 arg3);
extern s32 **func_00412e90(u8 *arg0, s32 arg1, s32 arg2, s32 *arg3);
extern u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2);
extern u8 *func_003cfa30(u8 *arg0, s32 arg1);
extern void func_00411670(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *func_0039bb70(u8 **arg0, s32 arg1);
extern void (*D_0064F2B4[])(u8 *arg0, s32 arg1, s32 arg2);
static inline s32 p4_mul_003963b0(s32 left, s32 right)
{
    return left * right;
}
extern s32 D_00884AC0[];

// FUN_0039F050
/* LANE_9F050_D: opt_propagation off + an explicit obj local so arg0 is not coalesced and can sit below temp_17 (s1) in saved-register order. */
/* LANE_9F050_G: schedule on + opt_propagation off + entry local to get call setup and saved-field load order. */
/* LANE_9F050_J: schedule on + opt_propagation off + opt_common_subs off to stop CSE from splitting the table address around temp_17. */
#pragma push
#pragma opt_propagation off
#pragma no_branch_likely on
#pragma schedule on
void func_0039f050(u8 *arg0)
{
    s32 temp_17;
    u8 *obj;
    s32 temp_5;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_6;
    s32 (*func)(u8 *, s32, u8 *);

    temp_2 = *(u8 **)(*(s32 *)(*(u8 **)(arg0 + 0x2C) + 8) + iGpffffb5e0);
    if (temp_2 != NULL) {
        var_2 = *(s32 *)(temp_2 + 0x80);
    } else {
        var_2 = 0;
    }
    obj = arg0;
    temp_6 = *(u8 **)(obj + 4);
    temp_5 = var_2 * 0x10;
    temp_17 = *(s32 *)(temp_6 + 0x18);
    *(s32 *)(temp_6 + 0x18) = temp_17 + temp_5;
    func = (s32 (*)(u8 *, s32, u8 *))*(void **)((u8 *)D_0064F2B4 + (var_2 * 4));
    func(obj, temp_5, temp_6);
    *(s32 *)(*(u8 **)(obj + 4) + 0x18) = temp_17;
}
#pragma pop
