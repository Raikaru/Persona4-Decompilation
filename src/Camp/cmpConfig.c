#include "include_asm.h"
/* Persona 4 USA decompilation - cmpConfig.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void func_0046d730(void* arg0, s32 arg1);
void func_0046d280(s32 arg0);
void func_00460ac0(void* param, void* work);
void func_00106390(s32 a, s32 b);
s32 func_0035f0c0(u32* arg0, s32* arg1, u8* arg2);
s32 func_0034c210(void);
extern u8 D_0064D3C8[];
extern u8 D_00793E80[];
extern s32 D_0064D3A0[];
extern u8 D_0064CD90[];
extern u8 D_0064CF00[];
extern u8 D_0064D070[];

// FUN_0035C690
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035c690);

// FUN_0035C7D0
s32 func_0035c7d0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 1) != 0;
}

// FUN_0035C7F0
s32 func_0035c7f0(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 4) != 0;
}

// FUN_0035C810
s32 func_0035c810(u8 *arg0) {
    return (s32)((*(u8 **)((s8 *)arg0 + 0x38))[4] & 2) != 0;
}

// FUN_0035C830
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035c830);

// FUN_0035CAB0
s32 func_0035cab0(u8 *arg0, s32 idx, s32 val) {
    s32 scaled = idx * 4;
    u8 *p = (u8 *)(scaled + (int)arg0);

    *(s32 *)(p + 0x34) = *(s32 *)(p + 0x30);
    *(s32 *)(p + 0x30) = val;
    if (idx == 0) {
        if (val == 6) {
            *(u16 *)(arg0 + 0x38) = 0;
        } else {
            *(u16 *)(arg0 + 0x38) = 0x12;
        }
    }
    return 1;
}

// FUN_0035CB00
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035cb00);

// FUN_0035CC80
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035cc80);

// FUN_0035CE10
s32 func_0035ce10(u8* arg0, s32 mode) {
    u8* tab = 0;
    s32 i;
    s32 j;

    if (*(s32*)(arg0 + 0x20) == mode) {
        return 0;
    }
    for (i = 0; i < 18; i++) {
        *(f32*)(arg0 + i * 48 + 0x78) = *(f32*)(arg0 + i * 48 + 0x88);
        *(f32*)(arg0 + i * 48 + 0x7C) = *(f32*)(arg0 + i * 48 + 0x8C);
        *(u8*)(arg0 + i * 48 + 0x90) = *(u8*)(arg0 + i * 48 + 0x92);
    }
    switch (mode) {
    case 0:
        tab = D_0064CD90;
        *(s32*)(arg0 + 0x24) = 3;
        *(u16*)(arg0 + 0x38) = 0x12;
        break;
    case 1:
        tab = D_0064D070;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    case 2:
        tab = D_0064CF00;
        *(s32*)(arg0 + 0x24) = 3;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x207);
        break;
    }
    if (tab != 0) {
        for (j = 0; j < 18; j++) {
            *(f32*)(arg0 + j * 48 + 0x80) = *(f32*)(tab + j * 20 + 0);
            *(f32*)(arg0 + j * 48 + 0x84) = *(f32*)(tab + j * 20 + 4);
            *(u8*)(arg0 + j * 48 + 0x91) = *(u8*)(tab + j * 20 + 8);
            *(s32*)(arg0 + j * 48 + 0xA0) = *(s32*)(tab + j * 20 + 0xC);
            *(s32*)(arg0 + j * 48 + 0xA4) = *(s32*)(tab + j * 20 + 0x10);
        }
        *(s32*)(arg0 + 0x20) = mode;
        *(u16*)(arg0 + 0x28) = 0;
    }
    return 1;
}

// FUN_0035CFB0
s32 func_0035cfb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x18);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x18) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_0035D000
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035d000);

// FUN_0035D0A0
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035d0a0);

// FUN_0035DCC0
s32 func_0035dcc0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x28);

    while (i < 18) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xA4)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_0035DD40
void func_0035dd40(u8* arg0) {
    s32 i;

    *(u8*)(arg0 + 4) |= 2;
    for (i = 0; i < 6; i++) {
        if (*(s32*)(arg0 + i * 4 + 0x48) != 0) {
            func_00106390(D_0064D3A0[i], 1);
        } else {
            func_00106390(D_0064D3A0[i], 0);
        }
    }
}

// FUN_0035DDF0
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035ddf0);

// FUN_0035DFB0
INCLUDE_ASM("asm/nonmatchings/cmpConfig", func_0035dfb0);

// FUN_0035E6A0
void func_0035e6a0(u8* arg0) {
    s32 i;

    for (i = 0; i < 0xB; i++) {
        u8* q = arg0 + i * 4;
        s32 v = *(s32*)(q + 0x448);

        if (v != 0) {
            func_0046d280(v);
            *(s32*)(arg0 + i * 4 + 0x448) = 0;
        }
    }
    *(s32*)(arg0 + 0x24) = 0;
}

// FUN_0035E720
s32 func_0035e720(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x38);
    s32 local;

    if (p[4] & 1) {
        return 0;
    }
    switch (func_0035f0c0((u32*)(p + 0x478), &local, p)) {
    case 0:
        if (local != 0) {
            *(s32*)(p + 0x47C) = 0;
            *(s32*)(p + 0x480) = 0;
            func_00460ac0(D_00793E80 + *(u16*)(p + 0x4AC) * 48, p + 0x47C);
        }
        break;
    case 2:
        p[4] |= 4;
        /* fallthrough */
    case 1:
        p[4] |= 1;
        break;
    default:
        func_0046d730(D_0064D3C8, 0x49E);
        break;
    }
    return 0;
}
