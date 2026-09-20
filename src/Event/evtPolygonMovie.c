#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtPolygonMovie.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef signed __int128 s128;

typedef struct {
    s128 a;
    s128 b;
} s2x128;

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern void func_002852a0(s32 arg0, s32 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_002909a0(s32 arg0);
extern void func_00290940(s32 arg0);
extern void func_00442088();
extern void func_0026c770(f32 *param_1, f32 *param_2, f32 *param_3);
extern void func_0026c680(f32 *param_1);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063C6A0[];
extern u8 D_0063C7A0[];
extern u8 D_0063C7C0[];
extern u8 D_0063C7E0[];
extern u8 D_0063C800[];
extern void (*jtbl_008873EC[])(void *ptr);
extern s128 D_0063C700;
extern s128 D_0063C710;
extern s128 D_0063C720[];
extern s128 D_0063C780;
extern s128 D_0063C790;

/* Without opt_loop_invariants the two lerp loops allocate the s2 value into
   $f0 (sub.s $f1,$f0,$f2, mtc1 $0,$f0 re-materialized inside the loop, madd.s
   result in $f0) vs retail's $f1 with the mtc1 hoisted to the preheader;
   expression variants (temps, product-first, (int)-cast addressing) never
   moved the allocation. measured: pragma on nd ~110 -> 0. */
#pragma opt_loop_invariants on

// FUN_0028F990
void func_0028f990(s32 arg0, f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3)
{
    f32 sp90[4];
    f32 sp80[4];
    f32 sp70[4];
    f32 sp60[4];
    f32 *var_16;
    f32 *var_18;

    var_18 = arg1;
    var_16 = arg3;
    if (var_16 == NULL) {
        func_0046d730(D_0063C6A0, 0x8F);
    }
    if (arg0 == 0) {
        fparg0 = 0.0f;
    }
    if (var_18 != NULL) {
        if (arg2 == NULL) {
            s32 var_5 = 6;

            do {
                s32 temp_4 = *(s32 *)var_18;
                s32 temp_3 = *(s32 *)(var_18 + 1);

                var_18 += 2;
                var_5 -= 1;
                *(s32 *)var_16 = temp_4;
                *(s32 *)(var_16 + 1) = temp_3;
                var_16 += 2;
            } while (var_5 > 0);
            return;
        }
        {
            s32 var_4;

            for (var_4 = 0; var_4 < 4; var_4++) {
                var_16[var_4 + 8] = var_18[var_4 + 8] + fparg0 * (arg2[var_4 + 8] - var_18[var_4 + 8]);
            }
        }
        {
            s32 var_4_2;

            for (var_4_2 = 0; var_4_2 < 4; var_4_2++) {
                var_16[var_4_2] = var_18[var_4_2] + fparg0 * (arg2[var_4_2] - var_18[var_4_2]);
            }
        }
        sp90[0] = var_18[4];
        sp90[1] = var_18[5];
        sp90[2] = var_18[6];
        sp80[0] = arg2[4];
        sp80[1] = arg2[5];
        sp80[2] = arg2[6];
        func_0026c770(&sp90[0], &sp80[0], &sp70[0]);
        sp60[0] = sp70[0] * fparg0 + var_18[4];
        sp60[1] = sp70[1] * fparg0 + var_18[5];
        sp60[2] = sp70[2] * fparg0 + var_18[6];
        func_0026c680(&sp60[0]);
        var_16[4] = sp60[0];
        var_16[5] = sp60[1];
        var_16[6] = sp60[2];
    }
}
#pragma opt_loop_invariants off

// FUN_0028FB90
u8 *func_0028fb90(void)
{
    u8 *work;

    func_0044ea90(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x114, 0x40000);
    func_002852a0(1, 0x114);
    if (work == NULL) {
        func_0046d730(D_0063C6A0, 0x12D);
        return NULL;
    }
    func_0043f9c8(work, 0, 0x114);
    return work;
}

/* Bind the resource sections into the existing movie work object. Keep the
   work-field reloads between writes and callbacks, and stop before overlay
   setup when the secondary resource is absent.
   Measured b210: 2088/2096 bytes, 16 resolved relocations and eight zero tail
   bytes. Direct parameters with lifetime analysis preserve the retail entry
   moves; propagation-off and loop-invariant analysis preserve the traversals.
   See docs/probe_archive/evtPolygonMovie_0028fc40_167e607.md. */
// FUN_0028FC40
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
u8 *func_0028fc40(u8 *messageContext, u8 *work, u8 *primary, u8 *secondary, u8 *overlay)
{
    s32 recordIndex;
    u8 *entry;
    s32 code;
    s32 overlayIndex;
    u8 *primaryRecords;
    u8 *secondaryRecords;
    u8 *overlayRecords;
    extern s32 func_00290880(u8 *, s32);
    extern s32 func_00440b68(const char *, ...);
    extern char D_0063C6C0[];
    extern char D_0063C6E0[];

    if (primary == NULL) {
        func_0046d730(D_0063C6A0, 0x155);
        return NULL;
    }
    *(s32 *)(work + 0x110) = 0;
    *(u8 **)(work + 0x10) = primary;
    *(u8 **)(work + 0x14) = primary + 0x20;
    *(s32 *)(work + 0x18) = 0;
    *(s32 *)(work + 0x1C) = 0;
    *(s32 *)(work + 0x20) = 0;
    *(s32 *)(work + 0x24) = 0;
    *(s32 *)(work + 0x28) = 0;
    *(s32 *)(work + 0x2C) = 0;
    *(s32 *)(work + 0x30) = 0;
    *(s32 *)(work + 0x34) = 0;
    *(s32 *)(work + 0x38) = 0;
    *(s32 *)(work + 0x3C) = 0;
    *(s32 *)(work + 0x40) = 0;
    *(s32 *)(work + 0x44) = 0;
    *(s32 *)(work + 0x48) = 0;
    *(s32 *)(work + 0x50) = 0;
    *(s32 *)(work + 0x4C) = 0;
    *(s32 *)(work + 0x54) = 0;
    *(s32 *)(work + 0x58) = 0;
    *(s32 *)(work + 0x5C) = 0;
    for (recordIndex = 0; recordIndex < *(s32 *)(*(u8 **)(work + 0x10) + 0x10); recordIndex++) {
        primaryRecords = *(u8 **)(work + 0x14);
        entry = primaryRecords + recordIndex * 0x10;
        code = *(s32 *)entry;
        if (code == 0x1B) {
            continue;
        }
        switch (code) {
        case 2:
            *(u8 **)(work + 0x20) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x24) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 10:
            *(u8 **)(work + 0x28) = primary + *(s32 *)(entry + 0xC);
            break;
        case 11:
            *(u8 **)(work + 0x2C) = primary + *(s32 *)(entry + 0xC);
            break;
        case 12:
            *(u8 **)(work + 0x30) = primary + *(s32 *)(entry + 0xC);
            break;
        case 3:
            *(u8 **)(work + 0x34) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x38) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 9:
            *(u8 **)(work + 0x3C) = primary + *(s32 *)(entry + 0xC);
            break;
        case 1:
            *(u8 **)(work + 0x18) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x1C) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 6:
            *(u8 **)(work + 0x4C) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x50) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 7:
            *(u8 **)(work + 0x40) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x44) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 8:
            *(u8 **)(work + 0x48) = primary + *(s32 *)(entry + 0xC);
            break;
        case 22:
            *(u8 **)(work + 0x54) = primary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x58) = *(s32 *)(*(u8 **)(work + 0x14) + recordIndex * 0x10 + 8);
            break;
        case 23:
            *(u8 **)(work + 0x5C) = primary + *(s32 *)(entry + 0xC);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x1C3);
            break;
        }
    }
    *(u8 **)(work + 0x80) = secondary;
    if (secondary != NULL) {
        *(u8 **)(work + 0x84) = secondary + 0x20;
    } else {
        *(s32 *)(work + 0x84) = 0;
    }
    *(s32 *)(work + 0x88) = 0;
    *(s32 *)(work + 0x8C) = 0;
    *(s32 *)(work + 0x90) = 0;
    *(s32 *)(work + 0x94) = 0;
    *(s32 *)(work + 0xAC) = 0;
    *(s32 *)(work + 0xB0) = 0;
    *(s32 *)(work + 0xB4) = 0;
    *(s32 *)(work + 0xB8) = 0;
    *(s32 *)(work + 0xBC) = 0;
    *(s32 *)(work + 0xC0) = 0;
    *(s32 *)(work + 0xC4) = 0;
    *(s32 *)(work + 0xC8) = 0;
    *(s32 *)(work + 0xCC) = 0;
    *(s32 *)(work + 0xD0) = 0;
    *(s32 *)(work + 0xD4) = 0;
    *(s32 *)(work + 0xD8) = 0;
    *(s32 *)(work + 0xDC) = 0;
    *(s32 *)(work + 0xE0) = 0;
    *(s32 *)(work + 0xE4) = 0;
    *(s32 *)(work + 0xE8) = 0;
    *(s32 *)(work + 0xEC) = 0;
    *(s32 *)(work + 0xF0) = 0;
    *(s32 *)(work + 0xF4) = 0;
    *(s32 *)(work + 0x100) = 0;
    *(s32 *)(work + 0x104) = 0;
    *(s32 *)(work + 0xF8) = 0;
    *(s32 *)(work + 0xFC) = 0;
    *(s32 *)(work + 0x108) = 0;
    *(s32 *)(work + 0x10C) = 0;
    *(s32 *)(work + 0x60) = 0;
    *(s32 *)(work + 0x64) = 0;
    if (secondary == NULL) {
        return work;
    }
    func_00440b68(D_0063C6C0, *(s32 *)(*(u8 **)(work + 0x80) + 0x10));
    for (recordIndex = 0; recordIndex < *(s32 *)(*(u8 **)(work + 0x80) + 0x10); recordIndex++) {
        secondaryRecords = *(u8 **)(work + 0x84);
        entry = secondaryRecords + recordIndex * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 0:
            *(u8 **)(work + 0x90) = secondary + *(s32 *)(entry + 0xC);
            break;
        case 4:
            if (*(s32 *)(*(u8 **)(work + 0x80) + 0x14) == 4) {
                *(u8 **)(work + 0x94) = secondary + *(s32 *)(entry + 0xC);
                *(s32 *)(work + 0x98) = 0;
            } else {
                *(u8 **)(work + 0x98) = secondary + *(s32 *)(entry + 0xC);
                *(s32 *)(work + 0x94) = 0;
            }
            *(s32 *)(work + 0xAC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 1:
            *(u8 **)(work + 0x88) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x8C) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 5:
            *(u8 **)(work + 0xB0) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xB4) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 13:
            *(u8 **)(work + 0xB8) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xBC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 14:
            *(u8 **)(work + 0xC0) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xC4) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 15:
            *(u8 **)(work + 0xC8) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xCC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 16:
            *(u8 **)(work + 0xD0) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xD4) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 17:
            *(u8 **)(work + 0xD8) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xDC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 18:
            *(u8 **)(work + 0xE0) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xE4) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 19:
            *(u8 **)(work + 0xE8) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xEC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 20:
            *(u8 **)(work + 0xF0) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xF4) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 24:
            *(u8 **)(work + 0xF8) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xFC) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 21:
            *(u8 **)(work + 0x100) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x104) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            func_00440b68(D_0063C6E0);
            break;
        case 25:
            *(u8 **)(work + 0x108) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x10C) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        case 26:
            *(u8 **)(work + 0x60) = secondary + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0x64) = *(s32 *)(*(u8 **)(work + 0x84) + recordIndex * 0x10 + 8);
            break;
        default:
            func_0046d730(D_0063C6A0, 0x24D);
            break;
        }
    }
    if (*(u8 **)(work + 0x90) != NULL) {
        if (*(u8 **)(work + 0x4C) != NULL && *(s32 *)(work + 0x50) > 0) {
            func_00290880(messageContext, *(s32 *)(work + 0x4C));
        }
    }
    *(u8 **)(work + 0x9C) = overlay;
    if (overlay != NULL) {
        *(u8 **)(work + 0xA0) = overlay + 0x20;
    } else {
        *(s32 *)(work + 0xA0) = 0;
    }
    *(s32 *)(work + 0xA4) = 0;
    *(s32 *)(work + 0xA8) = 0;
    if (overlay == NULL) {
        return work;
    }
    for (overlayIndex = 0; overlayIndex < *(s32 *)(*(u8 **)(work + 0x9C) + 0x10); overlayIndex++) {
        overlayRecords = *(u8 **)(work + 0xA0);
        entry = overlayRecords + overlayIndex * 0x10;
        code = *(s32 *)entry;
        switch (code) {
        case 4:
            *(u8 **)(work + 0xA4) = overlay + *(s32 *)(entry + 0xC);
            *(s32 *)(work + 0xA8) = *(s32 *)(*(u8 **)(work + 0xA0) + overlayIndex * 0x10 + 8);
            break;
        default:
            break;
        }
    }
    return work;
}
#pragma pop
// FUN_00290470
void func_00290470(s32 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        if (func_002909a0(arg1) == 1) {
            func_00290940(arg1);
        }
        jtbl_008873EC[0](arg0);
        func_002852a0(1, -0x114);
    }
}

// FUN_002904F0
s32 *func_002904f0(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C700;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(4, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_002905A0
s32 *func_002905a0(s32 **arg0)
{
    u8 sp30[0x54];
    s128 *src;
    s128 *dst;
    s32 count;
    s32 *temp;

    src = &D_0063C720[0];
    dst = (s128 *)&sp30[0];
    count = 5;
    do {
        s128 temp;

        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    *(f32 *)dst = *(f32 *)src;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x54, 0x40000);
    func_002852a0(5, 0x54);
    func_0043f810(temp, &sp30[0], 0x54);
    *arg0 = temp;
    return temp;
}

// FUN_00290660
s32 *func_00290660(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C780;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(6, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_00290710
void func_00290710(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5)
{
    s32 temp;

    if (arg2 == 0) {
        func_0046d730(D_0063C6A0, 0x36B);
    }
    if (arg3 == 0) {
        func_0046d730(D_0063C6A0, 0x36C);
    }
    if (arg4 == 0) {
        func_0046d730(D_0063C6A0, 0x36D);
    }
    if (arg5 == 0) {
        func_0046d730(D_0063C6A0, 0x36E);
    }
    temp = (arg0 / 10) * 10;
    func_00442088(arg2, D_0063C7A0, temp, arg0, arg1);
    func_00442088(arg3, D_0063C7C0, temp, arg0, arg1);
    func_00442088(arg4, D_0063C7E0, temp, arg0, arg1);
    func_00442088(arg5, D_0063C800, temp, arg0, arg1);
}
