#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(void *ptr);
extern void func_00492cd0(void *ptr);
extern void func_003c0700(void *arg0);
extern u8 *func_003c0520(void *ptr);
extern void func_003bff30(void *ptr, void (*cb)(void *), void *userdata);
extern void func_0046d730(const char *file, s32 line);
extern char D_00714520[];
extern void func_004ae080();
extern void func_00492d10(void *arg0);
extern void func_004ae0a0(void *arg0, void *arg1);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern void func_0044ea90(const void *msg, s32 id);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern char D_00714508[];
extern s32 func_003e2f60(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_003df3c0(s32 arg0, s32 *arg1);
extern s32 func_003e2e40(s32 arg0, s32 *arg1);
extern u8 *func_003e6a90(s32 arg0);
extern void func_003ef260(void *arg0, s32 (*arg1)(s32, void *), s32 *arg2);
extern void func_003ef1b0(void *arg0);
extern u8 *func_003c0f20(s32 arg0);
extern void func_003e2ce0(s32 arg0, u32 arg1);
extern void func_00463250(void *arg0);
extern s32 func_00463100(s32 arg0, void *arg1);
extern u8 *func_00484490(void);
extern s32 func_004844d0(void *obj);

void func_004aea70(u8 *arg0, s32 arg1, s32 arg2);

void func_004ae880(u8 *arg0, u8 *arg1);
void func_004ae930(u8 *arg0, u32 arg1, u8 *arg2);

// FUN_004AE460
u8 *func_004ae460(u8 *arg0)
{
    s32 temp_2_3;
    s32 temp_3;
    u32 var_19;
    u8 *temp_2_2;
    u8 *temp_2;

    temp_2_2 = func_00484490();
    if (temp_2_2 == 0) {
        func_0046d730(D_00714520, 0xFD);
    }
    temp_3 = *(s32 *)(temp_2_2 + 0x64);
    if (temp_3 == 0) {
        var_19 = *(u32 *)(temp_2_2 + 0xFC) * *(u32 *)(temp_2_2 + 0x68);
    } else {
        var_19 = temp_3 * *(u32 *)(temp_2_2 + 0x68);
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    func_0044ea90(D_00714508, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    func_0043f9c8(temp_2, 0, 0x94);
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xC5);
    }
    *(u32 *)(temp_2 + 0) = var_19;
    *(u32 *)(temp_2 + 4) = -1;
    *(u32 *)(temp_2 + 8) = 0x3F800000;
    *(u16 *)(temp_2 + 0x7C) = 0x18;
    *(u8 **)(temp_2 + 0x80) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xFF);
    }
    func_0043f810(temp_2 + 0x10, temp_2_2, 0x44);
    func_004ae930(temp_2, *(u16 *)(arg0 + 0xC), temp_2_2 + 0x44);
    if (*(u32 *)(*(u8 **)(temp_2 + 0x58) + 8) == 0) {
        return temp_2;
    }
    temp_2_3 = func_004844d0(arg0);
    if (temp_2_3 != 0) {
        switch (*(u16 *)(arg0 + 0x1C)) {
        case 3:
            func_004aea70(temp_2, temp_2_3, *(u32 *)(arg0 + 0x24));
            break;
        default:
            func_0046d730(D_00714520, 0x114);
            break;
        }
        *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0x1C);
    }
    return temp_2;
}

// FUN_004AE650
void func_004ae650(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;

    temp_4 = *(u32 *)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492cd0((void *)temp_4);
    }
    temp_4_2 = *(u32 *)(arg0 + 0x60);
    if (temp_4_2 != 0) {
        jtbl_008873EC[0]((void *)temp_4_2);
    }
    temp_4_3 = *(u8 **)(arg0 + 0x54);
    if (temp_4_3 != 0) {
        func_003c0700(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}

// FUN_004AE6D0
u8 *func_004ae6d0(u8 *arg0)
{
    u32 temp_3;
    u32 var_19;
    u8 *temp_17;
    u8 *temp_2;
    if (*(u8 **)(arg0 + 0x58) == 0) {
        func_0046d730(D_00714520, 0x148);
    }
    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0x58) + 0x24);
    if (temp_17 == 0) {
        func_0046d730(D_00714520, 0x14A);
    }
    temp_3 = *(u32 *)(temp_17 + 0x20);
    if (temp_3 == 0) {
        var_19 = *(u32 *)(temp_17 + 0xB8) * *(u32 *)(temp_17 + 0x24);
    } else {
        var_19 = temp_3 * *(u32 *)(temp_17 + 0x24);
    }
    if (var_19 > 0x64) {
        var_19 = 0x64;
    }
    func_0044ea90(D_00714508, 0x171);
    temp_2 = (u8 *)jtbl_008873E8[0](0x94, 0x40000);
    func_0043f9c8(temp_2, 0, 0x94);
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0xC5);
    }
    *(u32 *)(temp_2 + 0) = var_19;
    *(u32 *)(temp_2 + 4) = -1;
    *(u32 *)(temp_2 + 8) = 0x3F800000;
    *(u16 *)(temp_2 + 0x7C) = 0x18;
    *(u8 **)(temp_2 + 0x80) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_00714520, 0x14C);
    }
    func_0043f810(temp_2 + 0x10, arg0 + 0x10, 0x44);
    func_004ae930(temp_2, *(u16 *)(*(u8 **)(arg0 + 0x58) + 0), temp_17);
    if (*(u32 *)(*(u8 **)(temp_2 + 0x58) + 8) == 0) {
        return temp_2;
    }
    func_004ae880(temp_2, arg0);
    return temp_2;
}
// FUN_004AE880
void func_004ae880(u8 *arg0, u8 *arg1)
{
    u8 *temp_2;

    switch (*(u16 *)(arg1 + 0xC)) {
    case 3:
        if (*(u32 *)(arg0 + 0x54) != 0) {
            func_003c0700((void *)*(u32 *)(arg0 + 0x54));
        }
        temp_2 = func_003c0520((void *)*(u32 *)(arg1 + 0x54));
        *(u8 **)(arg0 + 0x54) = temp_2;
        func_003bff30(temp_2, func_004ae080, 0);
        break;
    default:
        func_0046d730(D_00714520, 0x172);
        break;
    }
    *(u16 *)(arg0 + 0xC) = *(u16 *)(arg1 + 0xC);
}

// FUN_004AE930
void func_004ae930(u8 *arg0, u32 arg1, u8 *arg2)
{
    u32 temp_16;
    u8 *var_19;
    u32 var_18;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492cd0(temp_4);
    }
    if (*(u32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(D_00714520, 0x18B);
    }
    *(u8 **)(arg0 + 0x58) = func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
    if (*(u32 *)(arg0 + 0x60) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(arg0 + 0x60));
    }
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x58) + 8);
    func_0044ea90(D_00714520, 0x195);
    *(u8 **)(arg0 + 0x60) = (u8 *)jtbl_008873E8[0](temp_16 * 0x18, 0x40000);
    if (*(u8 **)(arg0 + 0x60) == 0) {
        func_0046d730(D_00714520, 0x196);
    }
    var_19 = *(u8 **)(arg0 + 0x60);
    *(u8 **)(arg0 + 0x5C) = var_19;
    var_18 = 0;
    while (var_18 < temp_16) {
        func_004ae0a0(arg0, var_19);
        var_18++;
        var_19 += 0x18;
    }
}

/* measured: retail's default-case call func_003e2ce0(temp_18, sp60[1]) sets
   up args as [move $a0; lw $a1, 0x64($sp)]; mwcc b210 emits [lw $a1; move
   $a0] (load-first argument materialization). Tried: s32/u32 casts on both
   args, hoisting sp60[1] into its own local (sp64 = sp60[1]) before the call,
   and declaration-order permutations -- all give the identical nd 4 (the two
   swapped instructions). Same b210 call-argument setup floor measured in
   k_clumpInstance.c func_00191e90. All other bytes of the function match. */
// FUN_004AEA70
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aea70);

// FUN_004AEC50
void func_004aec50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AEC80
void func_004aec80(u8 *arg0)
{
    s32 temp_16;
    s32 var_20;
    u8 *var_18;
    u8 *var_17;
    u8 *temp_4;

    func_00492d10((void *)*(u32 *)(arg0 + 0x58));
    temp_4 = *(u8 **)(arg0 + 0x58);
    temp_16 = *(s32 *)(temp_4 + 8);
    if ((temp_16 != 0) && (*(s32 *)(temp_4 + 0x10) != 0)) {
        var_18 = *(u8 **)(temp_4 + 0x18);
        var_17 = *(u8 **)(arg0 + 0x5C);
        switch (*(u16 *)(arg0 + 0xC)) {
        case 3:
            var_20 = 0;
            while (var_20 < temp_16) {
                if (*(s32 *)(var_18 + 0x10) == 0) {
                    func_004ae0a0(arg0, var_17);
                }
                var_20++;
                var_18 += 0x20;
                var_17 += 0x18;
            }
            break;
        default:
            func_0046d730(D_00714520, 0x213);
            break;
        }
    }
}

// FUN_004AED70
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aed70);
