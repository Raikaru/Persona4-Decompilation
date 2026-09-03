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
    extern s32 iGpffffb700;
    u8 *base;
    u8 *temp_2;
    u8 *temp_4;
    u8 *(*allocator)(u8 *, u32);

    allocator = (u8 *(*)(u8 *, u32))D_008873F8[0];
    base = D_008872E0 + iGpffffb700;
    temp_2 = allocator(*(u8 **)base, 0x40507U);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 0) = arg0;
        *(s32 *)(temp_2 + 4) = arg1;
        *(s32 *)(temp_2 + 8) =
            *(s32 *)((s8 *)((s32)&D_008872E0 + iGpffffb700 + 4));
        *(u8 **)(temp_2 + 0xC) =
            (u8 *)((s32)&D_008872E0 + iGpffffb700 + 4);
        temp_4 = temp_2 + 8;
        *(u8 **)(*(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb700 + 4) + 0) + 4) =
            temp_4;
        *(u8 **)((s8 *)((s32)&D_008872E0 + iGpffffb700 + 4)) = temp_4;
    }
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern void (*jtbl_008873EC[])();
extern void func_003e3b70(u8 *arg0, u8 *arg1);
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
extern f32 D_0070B008[];
extern f32 D_0070B00C[];
extern f32 D_0070B010[];
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
// FUN_003C4140
#pragma schedule on
#pragma opt_propagation off
u8 *func_003c4140(void) {
    /* measured: volatile u8 locals force the compiler to keep the four 0xFF
       bytes in stack slots and read them back for the object stores. */
    u8 *s0;
    volatile u8 d;
    volatile u8 c;
    volatile u8 b;
    volatile u8 a;
    f32 f2;
    f32 f1;
    f32 f0;

    s0 = (u8 *)D_008873F8[0](*(s32 *)(D_008872E0 + iGpffffb6e0), 0x30007);
    if (s0 == NULL) {
        return NULL;
    }

    a = 0xFF;
    b = 0xFF;
    c = 0xFF;
    d = 0xFF;

    *(s16 *)(s0 + 0x18) = 1;
    *(u8 *)(s0 + 4) = a;
    *(u8 *)(s0 + 5) = b;
    *(u8 *)(s0 + 6) = c;
    *(u8 *)(s0 + 7) = d;
    *(s32 *)(s0 + 0) = 0;
    *(s32 *)(s0 + 8) = 0;

    f2 = D_0070B008[0];
    f1 = D_0070B00C[0];
    f0 = D_0070B010[0];

    *(f32 *)(s0 + 0xC) = f2;
    *(f32 *)(s0 + 0x10) = f1;
    *(f32 *)(s0 + 0x14) = f0;
    func_003e3b70(D_0070AFF0, s0);
    return s0;
}
#pragma opt_propagation on
/* measured: closes the schedule bracket for func_003c4140. */
#pragma schedule off

// FUN_003C59F0
#pragma schedule on
u8 *func_003c59f0(u8 *arg0, s32 (*arg1)(u8 *, u8 *, s32), s32 arg2) {
    s32 remaining;
    u8 *cursor;
    u8 *self;
    s32 (*callback)(u8 *, u8 *, s32);
    u16 count;

    self = arg0;
    callback = arg1;
    count = *(u16 *)(self + 4);
    remaining = (s32)count - 1;
    cursor = (u8 *)(*(s32 *)(self + 0xC) + (s32)self + 0x10);
    if (count != 0) {
        do {
            if (callback(cursor, self, arg2) == 0)
                return self;
            cursor += 0xC;
        } while (remaining-- != 0);
    }
    return self;
}
/* measured: closes the schedule bracket. */
#pragma schedule off

// FUN_003C00E0
#pragma schedule on
u8 *func_003c00e0(void) {
    extern void func_003e3b70();
    extern u8 *func_003c1b90();
    extern u8 func_003be9a0[];
    extern u8 func_003be9f0[];
    u8 *obj;

    obj = (u8 *)D_008873F8[0](
        *(s32 *)(D_008872E0 + iGpffffb6c0), 0x30014);
    if (obj != NULL) {
        *(u8 *)(obj + 0) = 1;
        *(u8 *)(obj + 1) = 0;
        *(u8 *)(obj + 2) = 0;
        *(u8 *)(obj + 3) = 0;
        *(s32 *)(obj + 4) = 0;
        *(u8 **)(obj + 0x10) = func_003be9a0;
        *(s32 *)(obj + 0x14) = 0;
        *(u8 *)(obj + 2) = 5;
        *(u8 *)(obj + 3) = 1;
        func_003c1b90(obj, NULL, 1);
        *(s32 *)(obj + 0x18) = 0;
        *(s32 *)(obj + 0x28) = 0;
        *(s32 *)(obj + 0x1C) = 0;
        *(s32 *)(obj + 0x20) = 0;
        *(s32 *)(obj + 0x24) = 0;
        *(s32 *)(obj + 0x38) = 0;
        *(s32 *)(obj + 0x2C) = 0;
        *(s32 *)(obj + 0x30) = 0;
        *(s32 *)(obj + 0x34) = 0;
        *(u8 **)(obj + 0x48) = func_003be9f0;
        if (*(u8 **)(obj + 0x48) == NULL)
            goto reset_callback;
init:
        *(s16 *)(obj + 0x50) = 0;
        *(s16 *)(obj + 0x52) = 0;
        *(s32 *)(obj + 0x54) = 0x3F800000;
        *(s32 *)(obj + 0x58) = 0x3F800000;
        *(s32 *)(obj + 0x5C) = 0;
        *(s32 *)(obj + 0x4C) = 3;
        *(s32 *)(obj + 0x44) = 0;
        *(s32 *)(obj + 0x40) = 0;
        *(s32 *)(obj + 0x3C) = 0;
        *(s32 *)(obj + 0x6C) = 0;
        *(u8 **)(obj + 0x64) = obj + 0x64;
        *(u8 **)(obj + 0x68) = obj + 0x64;
        func_003e3b70(D_0070AF70, obj);
        goto done;
    }
null_result:
    return NULL;
reset_callback:
    *(u8 **)(obj + 0x48) = func_003be9f0;
    goto init;
done:
    return obj;
}
/* measured: closes the schedule bracket. */
#pragma schedule off

// FUN_003CC370
#pragma schedule on
s32 func_003cc370(void) {
    extern u8 *func_003cc2c0(void);
    extern s32 func_0039b6e0(s32 arg0);
    u8 *temp_20;
    s32 temp_17;
    s32 temp_19;
    s32 temp_16;
    s32 temp_18;
    u8 *temp_2;

    temp_20 = func_003cc2c0();
    temp_17 = func_0039b6e0(4);
    temp_19 = func_0039b6e0(6);
    temp_16 = func_0039b6e0(5);
    temp_18 = func_0039b6e0(7);
    temp_2 = D_008872E0 + iGpffffb9b0;
    *(u8 **)(temp_2 + 0x1C) = temp_20;
    *(s32 *)(temp_2 + 0x20) = temp_19;
    *(s32 *)(temp_2 + 0x24) = temp_19;
    *(s32 *)(temp_2 + 0x28) = temp_19;
    *(s32 *)(temp_2 + 0x2C) = temp_18;
    *(s32 *)(temp_2 + 0x30) = temp_18;
    *(s32 *)(temp_2 + 0x38) = temp_17;
    *(s32 *)(temp_2 + 0x3C) = temp_16;
    func_00410a40((s32)temp_20);
    func_00410ab0(temp_19, 3);
    func_00410ab0(temp_19, 5);
    func_00410ab0(temp_19, 4);
    func_00410ab0(temp_18, 1);
    func_00410ab0(temp_18, 2);
    return 1;
}
/* measured: closes the schedule bracket. */
#pragma schedule off
