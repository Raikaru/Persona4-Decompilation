/* Consolidated Persona 4 source units. */
/* Original translation unit sdkClump.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90(const void *file, u32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00712518[];
extern u32 D_00712530[];
extern u8 D_00712558[];
extern u8 D_00712568[];
extern s32 func_004578b0(void *material, const char *name);
extern u32 func_00457a90(void *material, const char *name);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_003c21e0(void *arg0, s32 (*cb)(s32, void *), void *arg2);
extern void func_00462780(u8 *arg0, u32 arg1, u8 *arg2, s32 arg3);
extern void func_003bff30(void *object, void *callback, void *data);
extern void func_00462bf0(void *arg0);
extern s32 func_00462960(s32 arg0, void *arg1);


// FUN_00462A60
u8 *func_00462a60(u8 *arg0, u8 *arg1) {
    u8 sp30[0xC];
    s32 temp_4;

    func_0043f9c8(sp30, 0, 0xC);
    temp_4 = *(s32 *)(arg0 + 0x18);
    if (temp_4 != 0) {
        func_003c21e0((void *)temp_4, func_00462960, sp30);
        func_00462780(arg1, *(u32 *)(sp30 + 0), arg0, *(s32 *)(sp30 + 4));
    }
    return arg0;
}


/* measured: direct table references plus opt_loop_invariants reproduce both
   retail table-base preheaders and both loop bodies exactly (nd 15 -> 0).
   Committed at nd 0. */
/* measured: opt_loop_invariants probe for the retail base preheader. */
#pragma opt_loop_invariants on
// FUN_00462960
s32 func_00462960(s32 arg0, void *arg1) {
    s32 temp_2;
    s32 var_5;
    s32 var_6;

    temp_2 = func_004578b0((void *)arg0, (const char *)D_00712558);
    var_6 = 0;
    while (var_6 < 0xA) {
        if (*(s32 *)arg1 == (s32)D_00712530[var_6]) {
            break;
        }
        var_6++;
    }
    var_5 = 0;
    while (var_5 < 0xA) {
        if (temp_2 == (s32)D_00712530[var_5]) {
            break;
        }
        var_5++;
    }
    if (var_6 < var_5) {
        *(s32 *)arg1 = (s32)D_00712530[var_5];
    }
    if (func_00457a90((void *)arg0, (const char *)D_00712568) == 1) {
        *(s32 *)((u8 *)arg1 + 4) = 1;
    }
    return arg0;
}
/* measured: closes the opt_loop_invariants probe. */
#pragma opt_loop_invariants off


// FUN_00462780
void func_00462780(u8 *arg0, u32 arg1, u8 *arg2, s32 arg3) {
    u8 *temp_2;

    func_0044ea90(D_00712518, 0x22);
    temp_2 = D_008873F4[0](1, 0x28, 0x40000);
    *(u8 **)(temp_2 + 0) = arg2;
    if (arg3 == 1) {
        *(s32 *)(arg0 + 4) = *(s32 *)(arg0 + 4) + 1;
        *(s32 *)(temp_2 + 4) = 1;
    }
    *(s32 *)(temp_2 + 8) = 0x3F800000;
    *(s32 *)(temp_2 + 0xC) = 0x3F800000;
    *(s32 *)(temp_2 + 0x10) = 0x3F800000;
    *(s32 *)(temp_2 + 0x14) = 0x3F800000;
    switch (arg1) {
    case 0:
    case 1:
        *(s32 *)(temp_2 + 0x18) = 1;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 8);
        *(u8 **)(arg0 + 8) = temp_2;
        break;
    case 2:
        *(s32 *)(temp_2 + 0x18) = 2;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x14);
        *(u8 **)(arg0 + 0x14) = temp_2;
        break;
    case 3:
        *(s32 *)(temp_2 + 0x18) = 3;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x24);
        *(u8 **)(arg0 + 0x24) = temp_2;
        break;
    case 4:
        *(s32 *)(temp_2 + 0x18) = 4;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x28);
        *(u8 **)(arg0 + 0x28) = temp_2;
        break;
    case 5:
        *(s32 *)(temp_2 + 0x18) = 5;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0xC);
        *(u8 **)(arg0 + 0xC) = temp_2;
        break;
    case 6:
        *(s32 *)(temp_2 + 0x18) = 6;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x10);
        *(u8 **)(arg0 + 0x10) = temp_2;
        break;
    case 7:
        *(s32 *)(temp_2 + 0x18) = 7;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x18);
        *(u8 **)(arg0 + 0x18) = temp_2;
        break;
    case 8:
        *(s32 *)(temp_2 + 0x18) = 8;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x1C);
        *(u8 **)(arg0 + 0x1C) = temp_2;
        break;
    case 9:
        *(s32 *)(temp_2 + 0x18) = 9;
        *(u8 **)(temp_2 + 0x24) = *(u8 **)(arg0 + 0x20);
        *(u8 **)(arg0 + 0x20) = temp_2;
        break;
    }
    *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) + 1;
}


// FUN_00462AE0
void *func_00462ae0(void *(*arg0)(void *, void *)) {
    void *var_16;

    func_0044ea90(D_00712518, 0xAE);
    var_16 = D_008873F4[0](1, 0x2C, 0x40000);
    func_003bff30(arg0, func_00462a60, var_16);
    if ((*(s32 *)((u8 *)var_16 + 4) == 0) && ((*(u32 *)((u8 *)var_16 + 0) == 0) || ((*(s32 *)((u8 *)var_16 + 0x10) == 0) && (*(s32 *)((u8 *)var_16 + 0xC) == 0) && (*(s32 *)((u8 *)var_16 + 0x14) == 0) && (*(s32 *)((u8 *)var_16 + 0x24) == 0) && (*(s32 *)((u8 *)var_16 + 0x28) == 0) && (*(s32 *)((u8 *)var_16 + 0x18) == 0) && (*(s32 *)((u8 *)var_16 + 0x1C) == 0) && (*(s32 *)((u8 *)var_16 + 0x20) == 0)))) {
        func_00462bf0(var_16);
        var_16 = NULL;
    }
    return var_16;
}