#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void func_001437b0(void *arg0, s32 arg1, s32 arg2);
void func_001344d0(u8 *arg0);
void func_00131a00(u8 *arg0);
s16 func_00106cd0(s16 arg0, s16 arg1);
u8 func_00106600(s16 arg0);
s32 func_00106c30(s16 arg0, s16 arg1);
s32 func_00106c80(s16 arg0);
s16 func_00353ce0(void *arg0);
void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
void *func_0046a770(void *arg0);
s32 func_0046d200(void *arg0, s8 arg1);
void func_0046d730(void *arg0, s32 arg1);
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s8 D_005E76E0[];
extern u8 D_005E7BA0[];
extern u8 D_005E7720[];
extern u8 D_005E8020[];
extern u8 D_005E84A0[];
extern u8 D_005E8920[];
extern u8 D_005E8DA0[];
extern u8 D_005E9220[];
extern u8 D_005E96A0[];
extern u8 D_005E9B20[];
extern u8 D_005E9FA0[];
/* measured: both initializers hoist the conversion constants and table bases. */
#pragma opt_loop_invariants on
/* measured: initializer conversion and table setup match the retail window. */
// FUN_001312B0
void func_001312b0(u8 *arg0)
{
    s16 inner_i;
    s16 value;
    s32 offset;
    void *asset0;
    void *asset1;
    void *asset2;
    u8 *base;
    s32 *slot;
    s16 final_i;
    s16 clear_i;
    s16 second_i;
    s16 table_i;
    s16 outer_i;
    s16 inner_value;
    f32 float_value;
    s8 byte;

    func_0043f9c8(arg0, 0, 0x1598);
    base = arg0;
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 8) = 0;
    *(u8 *)base = 0xFF;
    *(s32 *)(base + 0x18) = -1;
    *(s32 *)(base + 0x14) = 0;

    for (clear_i = 0; clear_i < 4; clear_i++) {
        *(s16 *)(base + clear_i * 2 + 0x28) = 0;
    }
    for (table_i = 0; table_i < 0x29; table_i++) {
        offset = table_i * 0x1C;
        *(f32 *)(base + table_i * 0x30 + 0xC90) = *(f32 *)(D_005E7BA0 + offset);
        *(f32 *)(base + table_i * 0x30 + 0xC94) = *(f32 *)(D_005E7BA0 + offset + 4);
        *(u8 *)(base + table_i * 0x30 + 0xC9A) = *(u8 *)(D_005E7BA0 + offset + 0x10);
        float_value = *(f32 *)(D_005E7BA0 + offset + 8);
        *(u16 *)(base + table_i * 0x30 + 0xCA0) = (u16)float_value;
        float_value = *(f32 *)(D_005E7BA0 + offset + 0xC);
        *(u16 *)(base + table_i * 0x30 + 0xCA6) = (u16)float_value;
    }
    for (second_i = 0; second_i < 3; second_i++) {
        *(s32 *)(base + second_i * 0x30 + 0x1440) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1430) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x143C) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1434) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1449) = 0;
        *(u8 *)(base + second_i * 0x30 + 0x1448) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x1458) = 0;
        *(s32 *)(base + second_i * 0x30 + 0x145C) = 3;
    }
    value = func_00353ce0(base + 0x38);
    *(s16 *)(base + 0x48) = value;
    for (outer_i = 0; outer_i < *(s16 *)(base + 0x48); outer_i++) {
        value = *(s16 *)(base + outer_i * 2 + 0x38);
        inner_i = 0;
        slot = (s32 *)(base + outer_i * 6);
        while (inner_i < 3) {
            inner_value = func_00106cd0(value, inner_i);
            ((s16 *)slot)[inner_i + 0x624] = inner_value;
            inner_i++;
        }
    }
    func_00134560(base, 0);
    asset0 = func_0046a770(D_005E5830);
    if (asset0 == 0) {
        func_0046d730(D_005E9FA0, 0x26A);
    }
    asset1 = func_0046a770(D_005E5850);
    if (asset1 == 0) {
        func_0046d730(D_005E9FA0, 0x26C);
    }
    *(s32 *)(base + 0x1590) = (s32)(asset2 = func_0046a770(D_005E57F0));
    if (asset2 == 0) {
        func_0046d730(D_005E9FA0, 0x26E);
    }
    for (final_i = 0; final_i < 0x34; final_i++) {
        if (final_i < 0x29) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset0, byte);
        } else if (final_i < 0x33) {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset1, byte);
        } else {
            slot = (s32 *)(base + final_i * 4 + 0x14C0);
            byte = D_005E76E0[final_i];
            *slot = func_0046d200(asset2, byte);
        }
        if (*slot == 0) {
            func_0046d730(D_005E9FA0, 0x27B);
        }
    }
}

// FUN_00131730
void func_00131730(s16 *arg0) {
    s16 i;
    s16 count;
    s16 id;
    s32 type;
    s64 call_type;
    s32 found;
    s32 filter;
    s16 value;
    s16 *entry;

    id = arg0[arg0[20] + 28];
    type = arg0[21];
    call_type = type;
    for (i = 0, count = 0; i < 0x2FF; i++) {
        found = i == func_00106cd0(id, call_type);
        if (!found) {
            filter = func_00106600(i) != 0;
            if (filter) {
                filter = func_00106c30(i, id) != 0;
            }
            if (filter) {
                filter = (s32)type == func_00106c80(i);
            }
            if (!filter) {
                goto skip;
            }
        }
        value = found + func_00106600(i);
        if (value > 99) {
            value = 99;
        }
        entry = &arg0[2 * count];
        entry[37] = i;
        entry[38] = value;
        count++;
    skip:
        ;
    }
    arg0[1571] = count;
    if (count > 0x2FF) {
        func_0046d730(D_005E9FA0, 0x299);
    }
}
// FUN_001318C0
s32 func_001318c0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00131910
s32 func_00131910(u8 *arg0) {
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (*(s16 *)(arg0 + 0x20) < 0x64) {
        *(s16 *)(arg0 + 0x20) = *(s16 *)(arg0 + 0x20) + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0xC80, *(s16 *)(arg0 + 0x20), 0);
        if (*(u8 *)(p + 0xC9A) != 0) {
            rv = 0;
        }
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) >= 0x168) {
        *(s16 *)(arg0 + 0x22) = 0;
    }
    func_001344d0(arg0);
    func_00131a00(arg0);
    return rv;
}
/* measured: retail window 10928 bytes; no real C body was produced in this lane, so this function remains the bare assembly fallback. */
// FUN_00131A00
INCLUDE_ASM("asm/nonmatchings/cmpEquip", func_00131a00);

// FUN_001344B0
s32 func_001344b0(u8 *arg0, s32 arg1, s16 arg2) {
    /* The offset must be computed before the base is added: writing
       `arg0 + arg1 * 2` makes mwcc emit `addu $v1,$a0,$v0`, retail has
       `addu $v1,$v0,$a0`. */
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x30) = *(s16 *)(p + 0x28);
    *(s16 *)(p + 0x28) = arg2;
    return 1;
}

// FUN_001344D0
void func_001344d0(u8 *arg0) {
    s32 i;
    s16 v;

    v = *(s16 *)(arg0 + 0x24);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x24) = v + 1;
    }
    for (i = 0; i < 3; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1430, *(s16 *)(arg0 + 0x24), 0);
    }
}

/* measured: equipment-mode switch and table update match the retail window. */
/* measured: common-subexpression elimination is disabled for the setup and switch layout. */
#pragma opt_common_subs off
// FUN_00134560
s32 func_00134560(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = arg0 + i * 0x30;
        *(f32 *)(dst + 0xC80) = *(f32 *)(dst + 0xC90);
        *(f32 *)(dst + 0xC84) = *(f32 *)(dst + 0xC94);
        *(u8 *)(dst + 0xC98) = *(u8 *)(dst + 0xC9A);
        *(u16 *)(dst + 0xC9C) = *(u16 *)(dst + 0xCA0);
        *(u16 *)(dst + 0xCA2) = *(u16 *)(dst + 0xCA6);
    }
    switch (arg1) {
    case 0:
        table = D_005E7720;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 1:
        table = D_005E7BA0;
        break;
    case 2:
        table = D_005E8020;
        *(s32 *)(arg0 + 0x1C) = 0x494;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 3:
        table = D_005E84A0;
        *(s32 *)(arg0 + 0x1C) = 0x5BC;
        *(s16 *)(arg0 + 0xC78) = 0;
        *(f32 *)(arg0 + 0x11F4) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0x1224) =
            30.0f * (f32)*(s16 *)(arg0 + 0x28);
        break;
    case 4:
        table = D_005E8920;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 5:
        table = D_005E8DA0;
        *(s32 *)(arg0 + 0x1C) = 0x538;
        *(s16 *)(arg0 + 0xC78) = 0;
        break;
    case 6:
        table = D_005E9220;
        func_00131730((s16 *)arg0);
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 7:
        table = D_005E96A0;
        *(s32 *)(arg0 + 0x1C) = 0x3A0B;
        *(s16 *)(arg0 + 0xC78) = 3;
        break;
    case 8:
    case 9:
        table = D_005E9B20;
        *(s32 *)(arg0 + 0x1C) = 0x3A4A;
        *(s16 *)(arg0 + 0xC78) = 4;
        break;
    default:
        func_0046d730(D_005E9FA0, 0x5F8);
        break;
    }
    if (table != 0) {
#pragma opt_common_subs on
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
            *(f32 *)(dst + 0xC88) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0xC8C) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0xC99) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0xC9E) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(dst + 0xCA4) = (u16)value;
            *(s32 *)(dst + 0xCA8) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0xCAC) = *(s32 *)(src + 0x18);
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
#pragma opt_loop_invariants off

