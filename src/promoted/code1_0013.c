#include "include_asm.h"
#include "type.h"
extern s32 func_0034c210(void);
extern u8 *func_00106820();
extern s32 func_0010f930(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
extern void func_0046d280(s32 arg0);
extern void func_00105780(s16 arg0);

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* measured: donor loop shape requires invariant hoisting for the retail preheader and loop register coloring. */
#pragma opt_loop_invariants on
// FUN_001302D0
void func_001302d0(u8 *arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0x1608) = *(f32 *)(q + 0x1618);
        *(f32 *)(q + 0x160c) = *(f32 *)(q + 0x161c);
        *(u8 *)(q + 0x1620) = *(u8 *)(q + 0x1622);
        *(f32 *)(q + 0x16c8) = *(f32 *)(q + 0x16d8);
        *(f32 *)(q + 0x16cc) = *(f32 *)(q + 0x16dc);
        *(u8 *)(q + 0x16e0) = *(u8 *)(q + 0x16e2);
        if (*(s16 *)(arg0 + 0x26) == i) {
            *(s32 *)(q + 0x1610) = 0x41c80000;
            *(s32 *)(q + 0x16d0) = 0x41c80000;
        } else {
            *(s32 *)(q + 0x1610) = 0;
            *(s32 *)(q + 0x16d0) = 0;
        }
    }
    *(s16 *)(arg0 + 0x1c) = 0;
}
/* measured: close the donor loop's invariant-hoisting bracket. */
#pragma opt_loop_invariants off
// FUN_00130360
void func_00130360(u8 *arg0) {
    f32 f0;
    f32 f1;

    *(u32 *)(arg0 + 0x1ab8) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac0) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac8) = 0x435d0000;
    *(u8 *)(arg0 + 0x1ad0) = 0xff;
    *(u8 *)(arg0 + 0x1ad2) = 0xff;
    *(u8 *)(arg0 + 0x1ad1) = 0;
    *(u32 *)(arg0 + 0x1af4) = 0;
    if (*(s16 *)(arg0 + 0x24) > *(s16 *)(arg0 + 0x2a)) {
        f0 = 21.0f + *(f32 *)(arg0 + 0x149c);
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = *(f32 *)(arg0 + 0x1acc) - 10.0f;
        *(u32 *)(arg0 + 0x1aec) = 0xc1200000;
    } else {
        f1 = 21.0f + *(f32 *)(arg0 + 0x158c);
        f0 = 170.0f + f1;
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = 10.0f + *(f32 *)(arg0 + 0x1acc);
        *(u32 *)(arg0 + 0x1aec) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_00130430
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130430);
// FUN_00130580
void func_00130580(u8 *arg0) {
    s32 i;
    u8 *p;
    u8 *q;
    s32 temp;

    i = 0;
    while (i < 0x33) {
        q = arg0 + i * 4;
        p = q + 0x1b18;
        temp = *(s32 *)(q + 0x1b18);
        if (temp != 0) {
            func_0046d280(temp);
            *(s32 *)p = 0;
        }
        i++;
    }
    *(s32 *)(arg0 + 0x14) = 0;
}
// FUN_00130600
s32 func_00130600(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x1c);

    while (i < 0x1e) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x1304)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}
// FUN_00130680
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130680);
// FUN_00130C30
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130c30);
// FUN_00130CE0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130ce0);
// FUN_00134890
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00134890);
// FUN_00134990
void func_00134990(u8 *arg0, s16 arg1, s16 arg2) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x1374) = 0;
    *(s32 *)(arg0 + 0x137c) = 0xc1200000;
    *(u8 *)(arg0 + 0x1388) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0x41200000;
    *(s32 *)(arg0 + 0x101c) = 0;
    *(s8 *)(arg0 + 0x1028) = 0;
    *(s16 *)(arg0 + 0xc7a) = arg1;
    *(s16 *)(arg0 + 0xc7c) = arg2;
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_001349F0
void func_001349f0(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0x42480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0xc2480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_00134A50
void func_00134a50(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0xc2480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0x42480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_00134AB0
void func_00134ab0(u8 *arg0) {
    s32 temp;
    s32 var17;
    s32 var18;
    u8 *p;
    u8 *q;

    var18 = 0;
    while (var18 < 0x34) {
        q = arg0 + var18 * 4;
        p = q + 0x14c0;
        temp = *(s32 *)(q + 0x14c0);
        if (temp != 0) {
            func_0046d280(temp);
            *(s32 *)p = 0;
        }
        var18++;
    }
    var17 = 0;
    while (var17 < *(s16 *)(arg0 + 0x48)) {
        func_00105780(*(s16 *)(arg0 + var17 * 2 + 0x38));
        var17++;
    }
    *(s32 *)(arg0 + 0x1c) = 0;
}
// FUN_00134B60
s32 func_00134b60(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xcac)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}
// FUN_00134BE0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00134be0);
// FUN_00134DA0
s32 func_00134da0(s32 arg0) {
    s32 result;

    if (arg0 & 0x81) {
        result = 7;
        goto done;
    }
    if (arg0 & 0x102) {
        result = 8;
        goto done;
    }
    if (arg0 & 0x204) {
        result = 9;
        goto done;
    }
    if (arg0 & 0x408) {
        result = 10;
        goto done;
    }
    if (arg0 & 0x810) {
        result = 11;
        goto done;
    }
    if (arg0 & 0x1020) {
        result = 12;
        goto done;
    }
    if (arg0 & 0x2040) {
        result = 13;
    }
done:
    return result;
}
// FUN_00134E50
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00134e50);
// FUN_00134F40
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00134f40);
// FUN_00135130
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00135130);
// FUN_00135520
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00135520);
// FUN_0013AD40
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ad40);
// FUN_0013B370
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b370);
// FUN_0013B420
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b420);
// FUN_0013B9F0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b9f0);
// FUN_0013BCF0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013bcf0);
// FUN_0013C5A0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013c5a0);
// FUN_0013C6D0
s32 func_0013c6d0(void) {
    return func_0010f540(*(u16 *)(func_00106820() + 0x24)) != 0;
}
// FUN_0013C700
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013c700);
// FUN_0013CA60
s32 func_0013ca60(s32 arg0, s32 arg1, s32 arg2) {
    s32 v = 0;

    if (func_0010f930(arg0, arg1, arg2, 1) == 0) {
        v = 1;
    }
    return v;
}
// FUN_0013CAA0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013caa0);
// FUN_0013D470
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013d470);
// FUN_0013D5D0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013d5d0);
// FUN_0013D7D0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013d7d0);
// FUN_0013D8B0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013d8b0);
// FUN_0013E7C0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013e7c0);
// FUN_0013E8E0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013e8e0);
// FUN_0013EA20
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ea20);
// FUN_0013F4D0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013f4d0);
// FUN_0013F620
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013f620);
// FUN_0013F720
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013f720);
// FUN_0013FB50
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013fb50);
// FUN_0013FF80
s32 func_0013ff80(u8 *arg0) {
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
// FUN_0013FFD0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ffd0);