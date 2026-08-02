#include "include_asm.h"
#include "type.h"

/* gp-relative global at 0x0072467C (gp - 0x4A74): pointer to the active list. */
static u8 *iGpffffb58c;
/* gp-relative global at 0x007244C4 (gp - 0x4C2C). */
static u8 *iGpffffb3d4;

extern char D_0063FC48[];
extern char D_0063FC58[];
extern u8 *D_00882F70[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*jtbl_008873EC[])(void *);

extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern void func_0044ea90(void *msg, s32 id);
extern void func_00452080(s32 handle);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, s32 (*init)(u8 *),
                        void (*close)(u8 *), void *buf);
extern s32 func_00451fc0(s32 arg0, void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_002e23b0(u8 *arg0);
extern s32 func_002e2410(u8 *arg0);
extern void func_002e2470(u8 *arg0);
extern void func_002e29a0(void);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);

// FUN_002E24A0
void func_002e24a0(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *buf;

    if (iGpffffb58c != NULL) {
        func_002e29a0();
    }
    func_0044ea90(D_0063FC48, 0x67);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    iGpffffb58c = (u8 *)func_00451de0(D_0063FC58, 0xF, 0, 0, func_002e23b0,
                                       func_002e2470, buf);
    *(s32 *)(buf + 4) = arg0;
    *(s32 *)(buf + 8) = arg1;
    *(s8 *)(buf + 1) = arg2;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg3;
}
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e24a0);

// FUN_002E2590
void func_002e2590(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4) {
    u8 *buf;

    func_0044ea90(D_0063FC48, 0x82);
    buf = D_008873F4[0](1, 0x1810, 0x40000);
    func_00451fc0(arg0, D_0063FC58, 0xF, 0, 0, func_002e2410, func_002e2470,
                  buf);
    *(s32 *)(buf + 4) = arg1;
    *(s32 *)(buf + 8) = arg2;
    *(s8 *)(buf + 1) = arg3;
    *(s8 *)(buf + 0) = 1;
    *(s8 *)(buf + 0xC) = arg4;
}

// FUN_002E2670
s16 func_002e2670(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return *(s16 *)(*(u8 **)(g + 0x38) + 2);
}

// FUN_002E26A0
s32 func_002e26a0(void) {
    u8 *g = iGpffffb58c;

    if (g == NULL) {
        return -1;
    }
    return func_002b2d00(*(s16 *)(*(u8 **)(g + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E26F0
s16 func_002e26f0(void *arg0) {
    return *(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2);
}

// FUN_002E2700
void func_002e2700(void *arg0) {
    func_002b2d00(*(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 2), 1, 0, 0, 1);
}

// FUN_002E2740
s16 func_002e2740(s32 arg0) {
    u8 *g = iGpffffb58c;
    u8 *p;
    s32 count;

    if (g == NULL) {
        return -1;
    }
    p = *(u8 **)(g + 0x38);
    if (g == NULL) {
        count = -1;
    } else {
        count = *(s16 *)(p + 2);
    }
    if (count < arg0) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg0 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg0 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E2830
s16 func_002e2830(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 2: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 3: {
        s32 idx = arg1 * 2;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0xE);
    }
    default:
        return -1;
    }
}

// FUN_002E28F0
s16 func_002e28f0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s16 *)(p + 2) < arg1) {
        return -1;
    }
    switch (*(s8 *)(p + 1)) {
    case 1: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    case 2:
        return 1;
    case 3:
        return 1;
    case 4: {
        s32 idx = arg1 * 4;
        return *(s16 *)((u8 *)(idx + (u32)p) + 0x10);
    }
    default:
        return -1;
    }
}

// FUN_002E29A0
void func_002e29a0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        func_00452080((s32)g);
        iGpffffb58c = NULL;
    }
}

// FUN_002E29D0
s8 func_002e29d0(void) {
    u8 *g = iGpffffb58c;

    if (g != NULL) {
        return *(s8 *)(*(void **)(g + 0x38));
    }
    return -1;
}

// FUN_002E2A00
s8 func_002e2a00(void *arg0) {
    return *(s8 *)(*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E2A10
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e2a10);

// FUN_002E3560
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e3560);

// FUN_002E4090
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4090);

// FUN_002E45E0
void func_002e45e0(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// FUN_002E4610
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4610);

// FUN_002E47B0
s8 func_002e47b0(void) {
    s16 i = 0;
    u8 **base = D_00882F70;

    while (i < 15) {
        if (*(u8 **)((u32)base + i * 4) == NULL) {
            return (s8)i;
        }
        i++;
    }
    return -1;
}

// FUN_002E4820
void func_002e4820(s8 arg0) {
    u8 **p = &D_00882F70[arg0];

    if (*p != NULL) {
        func_00452080((s32)*p);
        *p = NULL;
    }
}

// FUN_002E4870
u8 *func_002e4870(s8 arg0) {
    return *(void **)(D_00882F70[arg0] + 0x38);
}

// FUN_002E48A0
u8 *func_002e48a0(s8 arg0, s16 arg1) {
    u8 *p = *(u8 **)(D_00882F70[arg0] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((arg1 * 3) * 0x10) + 0xA4;
    default:
        return p + ((arg1 * 3) * 0x10) + 0x14;
    }
}

// FUN_002E4960
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4960);

// FUN_002E4AC0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e4ac0);

// FUN_002E5000
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5000);

// FUN_002E5270
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5270);

// FUN_002E53B0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* measured: without `opt_loop_invariants on` the switch jump-table base is
   rematerialized in the loop body instead of hoisted to the preheader (nd 30+). */
s32 func_002e53b0(s8 arg0, s16 arg1) {
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;
    s16 i = 0;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return 1;
            }
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e53b0). */
#pragma opt_loop_invariants off

// FUN_002E54C0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
s16 func_002e54c0(s8 arg0, s16 arg1) {
    s16 i = 0;
    u8 **entryp = &D_00882F70[arg0];
    u8 *entry;
    u8 *p;
    u8 *q;
    s32 count;
    s32 key;

    if (*(u32 *)entryp != 0) {
        i = 0;
        key = (s16)arg1;
        p = *(u8 **)((u8 *)*(u32 *)entryp + 0x38);
        count = *(s32 *)(p + 8);
        for (; i < count; i++) {
            entry = *entryp;
            p = *(u8 **)(entry + 0x38);
            switch (*(u32 *)(p + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                q = p + ((i * 3) * 0x10) + 0xA4;
                break;
            default:
                q = p + ((i * 3) * 0x10) + 0x14;
                break;
            }
            if (key == *(u16 *)(q + 2)) {
                return i;
            }
        }
    }
    return -1;
}
/* measured: see the annotation above the matching `on` pragma (func_002e54c0). */
#pragma opt_loop_invariants off

// FUN_002E55C0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e55c0);

// FUN_002E5960
void func_002e5960(s8 arg0) {
    u8 *p;
    s16 i;
    s16 j;
    s32 type;

    if (D_00882F70[arg0] == NULL) {
        return;
    }
    p = *(u8 **)(D_00882F70[arg0] + 0x38);
    type = *(s32 *)(p + 4);
    switch (type) {
    case 0:
    case 7:
    case 8:
        for (i = 0; i < 0x100; i++) {
            func_0043f9c8(p + ((i * 3) * 0x10) + 0x14, 0, 0x30);
        }
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        for (j = 0; j < 0xC; j++) {
            func_0043f9c8(p + ((j * 3) * 0x10) + 0xA4, 0, 0x30);
            *(u8 *)(p + j + 0x2E4) = 0;
        }
        break;
    default:
        break;
    }
    *(s16 *)(p + 0xE) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s32 *)(p + 8) = 0;
}

// FUN_002E5AE0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e5ae0);

// FUN_002E6230
s32 func_002e6230(u16 arg0, u16 *arg1) {
    s32 i = 0;
    s32 key = arg0 & 0xFFFF;

    while (i < 13) {
        if (*(u16 *)((u8 *)arg1 + i * 2) == key) {
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_002E6280
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6280);

// FUN_002E6630
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6630);

// FUN_002E68B0
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e68b0);

// FUN_002E6B20
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6b20);

// FUN_002E6C90
INCLUDE_ASM("asm/nonmatchings/y_list", func_002e6c90);

// FUN_002E6F00
/* measured: without `opt_loop_invariants on` MWCC rematerializes the -1 store
   constant at the top of the loop body (nd 6) instead of hoisting it into the
   preheader as retail does (addiu $a1,$zero,-1 before the initial branch). */
#pragma opt_loop_invariants on
void func_002e6f00(void) {
    s16 *buf;
    s16 i;
    s16 value;

    func_0044ea90(D_0063FC48, 0x649);
    buf = (s16 *)D_008873F4[0](1, 0x62, 0x40000);
    i = 0;
    value = -1;
    while (i < 0x30) {
        buf[i] = value;
        i++;
    }
    buf[0x30] = 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e6f00). */
#pragma opt_loop_invariants off
