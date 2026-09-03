#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (2004-09)
   rather than the project default b210: retail linked prebuilt RenderWare
   objects next to Atlus's b210 code, and this block carries b119-era idioms
   (`movz` conditional moves that b198/b210 never emit; measured 2026-09-03).
   The compiler is named in config/compiler_units.txt. Fallbacks stay under
   asm/nonmatchings/code1_003c. */

/* gp - 0x48F8 = 0x007647F8 */
extern s32 iGpffffb708;
extern u8 func_003ca740[];
extern u8 func_003ca780[];
extern u8 func_003ca7a0[];

/* measured: schedule on fills ca830's call and return delay slots. */
#pragma schedule on
// FUN_003CA830
u8 *func_003ca830(u8 *arg0) {
    u8 *f60 = func_003ca7a0;
    u8 *f00 = func_003ca740;
    u8 *f40 = func_003ca780;
    u8 *node = arg0 + iGpffffb708;

    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(node + 0x10) = *(s32 *)(arg0 + 0x18);
    *(s32 *)(node + 0x14) = *(s32 *)(arg0 + 0x1C);
    *(s32 *)(node + 0x18) = *(s32 *)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = f60;
    *(u8 **)(arg0 + 0x18) = f00;
    *(u8 **)(arg0 + 0x1C) = f40;
    *(s32 *)(node + 0xC) = 0;
    return arg0;
}

/* measured: closes the schedule bracket. */
#pragma schedule off

extern u8 D_008872E0[];
extern void *(*D_008873F8[])(s32 arg0, s32 arg1);
extern s32 func_003ce560(s32 arg0, u8 *arg1);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003c5d10(s32 arg0, u8 *arg1, u8 *arg2);
extern u8 *func_003c9c20(u8 *arg0);
extern s32 func_003cebb0(s32 arg0, u8 *arg1);

/* `movz $s0,$zero,$v0` is the b119 lowering of `call() ? arg0 : 0`. */
// FUN_003CB790
#pragma schedule on
s32 func_003cb790(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003ce560(arg0, arg2) ? arg0 : 0;
}
// FUN_003CB7E0
s32 func_003cb7e0(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003cebb0(arg0, arg2) ? arg0 : 0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003CB870
#pragma schedule on
s32 func_003cb870(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp;

    temp = func_003c9c20(arg2);
    *(s32 *)(arg2 + 0x78) = func_003c5d10(arg0, temp, temp + 0x10);
    return *(s32 *)(arg2 + 0x78) ? arg0 : 0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* The b210 residual (base addu before the allocator load) is not there
   under b119: the archived body is exact. */
// FUN_003C9940
#pragma schedule on
void func_003c9940(s32 arg0, s32 arg1) {
    extern s32 iGpffffb6f8;
    u8 *base;
    u8 *temp_2;
    u8 *temp_4;
    u8 *(*allocator)(u8 *, u32);

    allocator = (u8 *(*)(u8 *, u32))D_008873F8[0x46];
    base = D_008872E0 + iGpffffb6f8;
    temp_2 = allocator(*(u8 **)base, 0x40507U);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 0) = arg0;
        *(s32 *)(temp_2 + 4) = arg1;
        *(s32 *)(temp_2 + 8) =
            *(s32 *)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4));
        *(u8 **)(temp_2 + 0xC) =
            (u8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4);
        temp_4 = temp_2 + 8;
        *(u8 **)(*(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4) + 0) + 4) =
            temp_4;
        *(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb6f8 + 4)) = temp_4;
    }
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern void (*jtbl_008873EC[])();
extern void func_003e3b70(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern void func_003bf320();
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003c5760(u8 *arg0);
extern s32 func_003c2bd0(u8 *arg0);
extern s32 func_003c4c00(u8 *arg0);
extern s32 func_003c4a80(u8 *arg0, s32 arg1);
extern s32 func_003c4bc0(u8 *arg0, s32 arg1);
extern u8 *func_003c2290(u8 *arg0, s32 arg1);
extern u8 *func_003c49a0(u8 *arg0);
extern s32 func_003ce2e0(u8 *arg0);
extern s32 func_003c2c90(u8 *arg0);
extern s32 func_003e3370(u8 *desc, u8 *arg1);
extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern s32 func_003e3c20(u8 *desc, u8 *arg1);
extern s32 func_003e3070(u8 *desc, s32 arg0, s32 arg1);
extern s32 func_003e30c0(u8 *desc, s32 arg0, s32 arg1);
extern s32 func_003e3830(u8 *desc, s32 arg0);
extern s32 func_003c3cc0(u8 *arg0);
extern u8 *func_003c8200(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_003c5fd0(u8 *arg0, u8 *arg1);
extern s32 func_003ce840(u8 *arg0);
extern s32 iGpffffb730;
extern s32 func_003ce3a0(s32 arg0, u8 *arg1);
extern s32 func_003ce9e0(s32 arg0, u8 *arg1);
extern s32 func_003ceeb0(u8 *arg0);
extern s32 iGpffffaa98;
extern s32 iGpffffaa9c;
extern u8 D_00886550[];
typedef struct { f32 x, y, z, w; } Vec4f;
typedef struct { u8 pad[0x54]; s32 field; } Cb720Obj;
extern u16 D_008872E8[];
extern u8 func_003cac30[];
extern u8 func_003caef0[];
extern u8 D_0070AFB0[];
extern u8 D_0070B020[];
extern u8 *(*D_0070B030)(u8 *arg0, s32 arg1);
extern s32 D_0070B034;
extern u8 *func_003c8920(u8 *arg0, s32 arg1);
extern s32 iGpffffb9b8;
extern s32 iGpffffb9b0;
extern s32 func_00410a40(s32 arg0);
extern s32 func_00410ab0(s32 arg0, s32 arg1);
extern void func_00411670(s32 arg0);
extern s64 iGpffffb8f0;
extern s32 iGpffffb70c;
extern s32 iGpffffb6c8;
extern s32 iGpffffb6cc;
extern s32 iGpffffb6b4;
extern s32 iGpffffb6b0;
extern s32 iGpffffb714;
extern s32 iGpffffb71c;
extern u8 *iGpffffb6f0;
extern s32 iGpffffb6c0;
extern void func_003e9680(u8 *arg0);
extern void (*jtbl_008873FC[])(u8 *arg0, u8 *arg1);
extern void (*jtbl_008873E8[])(u8 *arg0, s32 arg1);
extern s32 iGpffffb6d0;
extern s32 iGpffffb6d4;
extern s32 iGpffffb6e0;
extern s32 iGpffffb6e4;
extern u8 *iGpffffb6e8;
extern u8 *iGpffffb718;
extern s32 iGpffffb6f4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern s32 func_003c3890(u8 *arg0);
extern u8 D_0070AFD0[];
extern u8 D_0070AFF0[];
extern u8 *func_003c9640(u8 *arg0);
extern u8 D_0070AF70[];
extern u8 D_0070B040[];
extern u8 D_008872E4[];
extern s32 func_003c5a90(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3);
extern u8 *func_003cbde0(u8 *arg0, u8 *(*arg1)(u8 *arg0, u8 *arg1), u8 *arg2);
extern u8 *func_003c8dd0(u8 *arg0, u8 *arg1);
extern u8 *func_003cbc90(u8 *arg0, u8 *arg1);
extern void func_003cbe80(u8 *arg0, u8 *arg1);
extern u8 D_0070AF90[];
extern u8 D_0070B060[];
extern s32 func_003e3870(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_003efd20(u8 *arg0, u8 *arg1);
extern s32 func_003e3020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern s32 D_007647CC;
extern s32 D_007647C8;
extern s32 D_007647BC;
extern void func_003c38a0(void);
extern s32 D_007647EC;
extern s32 iGpffffb700;
extern s32 iGpffffb704;
extern void func_003cc130(void);
extern u8 D_008872E4[];
extern s32 D_0070B110[];
extern s32 func_003cc170(void);
/* Archived b210 near-miss (K3C1_003c95a0); exact under b119 with schedule on. */
// FUN_003C95A0
#pragma schedule on
s32 func_003c95a0(s32 arg0, s32 arg1) {
    extern s32 func_003cc170(void);
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             void *arg4, s32 arg5);
    extern u8 D_008865B0[];
    u8 *slot;
    s32 result;
    iGpffffb700 = arg1;
    if (func_003cc170() == 0)
        return 0;
    result = func_003e1220(0x10, 8, 4, 1, D_008865B0, 0x4000B);
    slot = D_008872E0 + iGpffffb700;
    *(s32 *)slot = result;
    result = *(s32 *)slot;
    if (result == 0)
        return 0;
    slot += 4;
    *(u8 **)(slot + 0) = slot;
    *(u8 **)(slot + 4) = slot;
    iGpffffb704 += 1;
    return arg0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off
