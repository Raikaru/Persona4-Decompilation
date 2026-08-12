#include "include_asm.h"
#include "type.h"
extern u32 func_003b7060(void);
extern s32 func_0034c210(void);
extern u8 *func_00106820();
extern s32 func_0010f930(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
static inline f32 code13Add(f32 left, f32 right) {
    return left + right;
}
extern void func_0046d280(s32 arg0);
extern void func_001400f0(u8 *arg0);
extern void func_00141d10(u8 *arg0);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_00105780(s16 arg0);
extern s32 func_0010f8c0(s32 arg0);
extern void func_0012ff60(u8 *arg0, s32 arg1);
extern s32 func_0034bb20(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0013c6d0(s16 arg0);
extern s32 func_0010f540(s32 arg0);
extern void func_0011d080(u8 *arg0, s32 arg1);
extern void func_0011d0a0(u8 *arg0, s32 arg1);
extern void func_0011d0d0(u8 *arg0, void *arg1);
extern void func_0011d170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00453670();
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void func_00136fa0(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0010ace0(s16 arg0);
extern s32 func_0010a900(s32 arg0);
extern void func_0011c2c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0010b510(void);
extern void func_0010b3b0(s16 arg0);
extern s32 func_0010f6a0(s16 arg0, s32 arg1);
extern void func_0011c180(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0013f620(s16 arg0, s32 arg1, u8 *arg2);
extern void func_0013a040(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0013a530(u8 *arg0, s32 arg1);
extern void func_0013aa00(u8 *arg0);
extern void func_001344b0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00131730(u8 *arg0);
extern void func_00134560(u8 *arg0, s32 arg1);
extern void func_00134a50(u8 *arg0);
extern void func_001349f0(u8 *arg0);
extern s32 func_00106cd0(s16 arg0, s16 arg1);
extern s32 func_00106600(s16 arg0);
extern void func_00106620(s16 arg0, s32 arg1);
extern void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
extern void func_00134990(u8 *arg0, s16 arg1, s16 arg2);
extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u8 arg4);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
typedef struct {
    s32 first;
    s32 second;
} code13Pair;

 

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
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
// FUN_00130430
void func_00130430(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0xC; i++) {
        if (func_003b7060() & 3) {
            p = arg0 + i * 0x30;
            val = (func_003b7060() % 6U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x1880) = f;
            *(f32 *)(p + 0x1878) = f;
            *(u32 *)(p + 0x187C) = 0x43FA0000;
            *(f32 *)(p + 0x188C) = *(f32 *)(p + 0x187C);
            *(s32 *)(p + 0x1884) = 0xC2C80000;
            q = (u32 *)(p + 0x18A0);
            random = func_003b7060() % 10U;
            *q = random;
            *(s32 *)(p + 0x18A4) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x187C) = *(f32 *)(p + 0x1884);
        }
    }
    *(s16 *)(arg0 + 0x1E) = 0;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2
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
/* measured: opt_propagation off probe for func_00130c30 ordering. */
#pragma opt_propagation off
void func_00130c30(u8 *arg0, s64 arg1, s32 arg2)
{
    f32 c0;
    s32 p;
    u8 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1b60);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    func_0034f2e0((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    func_0034f2e0(*(void **)(arg0 + 0x1b64),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
/* measured: close opt_propagation for func_00130c30 probe. */
#pragma opt_propagation on
// FUN_00130CE0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130ce0);
/* measured: second 00134890 probe preserves the retail floating zero and constant materialization. */
#pragma opt_propagation off
// FUN_00134890
void func_00134890(u8 *arg0)
{
    f32 temp_f1;
    f32 temp_f0;

    temp_f1 = 0.0f;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xFF;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    temp_f0 = 122.0f;
    *(s32 *)(arg0 + 0x1430) = 0x42F40000;
    *(s32 *)(arg0 + 0x1438) = 0x42F40000;
    *(s32 *)(arg0 + 0x1440) = 0x42F40000;
    *(u8 *)(arg0 + 0x1448) = 0xFF;
    *(u8 *)(arg0 + 0x144A) = 0xFF;
    *(s8 *)(arg0 + 0x1449) = 0;
    *(s32 *)(arg0 + 0x1490) = 0;
    *(s32 *)(arg0 + 0x1498) = 0;
    *(s32 *)(arg0 + 0x14A0) = 0;
    *(u8 *)(arg0 + 0x14A8) = 0xFF;
    *(u8 *)(arg0 + 0x14AA) = 0xFF;
    *(s8 *)(arg0 + 0x14A9) = 0;
    *(s32 *)(arg0 + 0x146C) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x34)) {
        *(s32 *)(arg0 + 0x1444) = 0x43090000;
        *(s32 *)(arg0 + 0x1434) = 0x43090000;
        *(f32 *)(arg0 + 0x143C) = temp_f0;
        *(f32 *)(arg0 + 0x14A4) = temp_f1;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0xC1A80000;
        *(s32 *)(arg0 + 0x1464) = 0xC1200000;
    } else {
        temp_f0 = (f32)0x111;
        *(f32 *)(arg0 + 0x1444) = temp_f0;
        *(f32 *)(arg0 + 0x1434) = temp_f0;
        *(s32 *)(arg0 + 0x143C) = 0x43950000;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0x41A80000;
        *(f32 *)(arg0 + 0x143C) = 10.0f + *(f32 *)(arg0 + 0x1444);
        *(s32 *)(arg0 + 0x1464) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x24) = 0;
}
/* measured: close opt_propagation for func_00134890. */
#pragma opt_propagation on
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
/* measured: reconstructing the mixed-ABI palette draw pair from the matching 00130C30 shape. */
#pragma opt_propagation off
void func_00134e50(u8 *arg0, s64 arg1, s64 arg2, u8 arg3)
{
    f32 temp_f20;
    s32 p;
    s32 p2;
    u8 *color;

    p = *(s32 *)(arg0 + 0x1580);
    p2 = *(s32 *)(arg0 + 0x1584);
    switch ((s16)arg2) {
    case 0:
        color = D_0064B2E0;
        break;
    case 1:
        color = D_0064B2E8;
        break;
    }
    temp_f20 = ((f32 *)&arg1)[1] - 3.0f;
    func_0034f2e0((void *)p, ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
    func_0034f2e0((void *)p2, 241.0f + ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
}
/* measured: close mixed-ABI palette draw pair pragma. */
#pragma opt_propagation on
// FUN_00134F40
/* measured: transfer the neighboring mixed-ABI palette branch shape. */
#pragma opt_propagation off
void func_00134f40(u8 *arg0, s64 arg1, s64 arg2, u8 arg3)
{
    f32 temp_f20;
    s32 p;
    u8 *color;

    switch ((s16)arg2) {
    case 0:
        p = *(s32 *)(arg0 + 0x14C8);
        temp_f20 = ((f32 *)&arg1)[1];
        func_0034f2e0((void *)p,
                      ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1508);
        func_0034f2e0((void *)p,
                      36.0f + ((f32 *)&arg1)[0], 24.0f + temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1500);
        temp_f20 = code13Add(9.0f, temp_f20);
        func_0034f2e0((void *)p,
                      419.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1504);
        func_0034f2e0((void *)p,
                      473.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        break;
    case 1:
        color = D_0064B2E8;
        p = *(s32 *)(arg0 + 0x155C);
        temp_f20 = ((f32 *)&arg1)[1];
        func_0034f2e0((void *)p,
                      2.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
        p = *(s32 *)(arg0 + 0x1560);
        func_0034f2e0((void *)p,
                      474.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
        break;
    }
}
/* measured: close neighboring mixed-ABI palette branch pragma. */
#pragma opt_propagation on
// FUN_00135130
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00135130);
// FUN_00135520
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00135520);
// FUN_0013AD40
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ad40);
// FUN_0013B370
/* measured: family substitution reuses the exact 176-byte byte-color shape. */
#pragma opt_propagation off
void func_0013b370(u8 *arg0, s64 arg1, s32 arg2)
{
    f32 c0;
    s32 p;
    u8 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1288);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    func_0034f2e0((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    func_0034f2e0(*(void **)(arg0 + 0x128c),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
/* measured: close family opt_propagation bracket. */
#pragma opt_propagation on
// FUN_0013B420
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b420);
// FUN_0013B9F0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b9f0);
// FUN_0013BCF0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013bcf0);
// FUN_0013C5A0
void func_0013c5a0(s32 *arg0, u8 *arg1) {
    u8 *entry;
    s16 type;

    entry = code13AddOff((*(s16 *)(arg1 + 0x24) + *(s16 *)(arg1 + 0x22)) * 4,
                         arg1) + 0x3E;
    if (func_0013c6d0(*(s16 *)entry) == 0) {
        func_0045af60(0, 0, 0, 8);
        return;
    }
    type = (s16)func_0010f8c0(*(u16 *)(func_00106820(*(s16 *)entry) + 0x24));
    if (type == 0) {
        func_0012ff60(arg1, 4);
        func_001302d0(arg1);
        *arg0 = 7;
    } else {
        if ((type == 2) || (type == 1)) {
            func_0012ff60(arg1, 5);
            *arg0 = 9;
        }
    }
    func_0034bb20(0xC);
    func_0045af60(0, 0, 0, 1);
}
// FUN_0013C6D0
s32 func_0013c6d0(s16 arg0) {
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
s32 func_0013d470(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    func_00453670(sp40, 8, *(s16 *)(arg0 + 0x48), *(s16 *)(arg0 + 0x28), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_001344b0(arg0, 0, *(s32 *)(sp40 + 0x24));
        func_001344b0(arg0, 3, 0);
        func_001344b0(arg0, 2, 0);
        func_00131730(arg0);
        func_00134560(arg0, 7);
        *arg1 = 0xA;
        if (temp_2 == 1) {
            func_00134a50(arg0);
        } else if (temp_2 == 2) {
            func_001349f0(arg0);
        }
        func_0045af60(0, 1, 0, 5);
        return 1;
    }
    return 0;
}
// FUN_0013D5D0
s32 func_0013d5d0(u8 *arg0) {
    struct {
        s16 value;
    } temp_16;
    s16 temp_19;
    s16 temp_18;
    s16 temp_2;
    s32 temp_6;
    s32 temp_6_2;
    s16 temp_17;

    temp_18 = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x28) * 2, arg0) + 0x38);
    temp_19 = *(s16 *)(code13AddOff((*(s16 *)(arg0 + 0x2C) +
                                     *(s16 *)(arg0 + 0x2E)) * 4, arg0) + 0x4A);
    temp_16.value = *(s16 *)(arg0 + 0x2A);
    temp_17 = (s16)func_00106cd0(temp_18, temp_16.value);
    if (temp_19 == temp_17) {
        func_0045af60(0, 0, 0, 8);
        return 0;
    }
    func_00134560(arg0, 7);
    func_00134990(arg0, temp_17, temp_19);
    if ((func_00106600(temp_17) & 0xFF) != 0x63) {
        func_00106620(temp_17, ((func_00106600(temp_17) & 0xFF) + 1) & 0xFF);
    }
    func_00106d40(temp_18, temp_16.value, temp_19);
    func_00106620(temp_19, ((func_00106600(temp_19) & 0xFF) - 1) & 0xFF);
    func_00131730(arg0);
    temp_2 = *(s16 *)(arg0 + 0xC46);
    if (temp_2 < 5) {
        func_001344b0(arg0, 2, 0);
        temp_6 = *(s16 *)(arg0 + 0xC46) - 1;
        if (temp_6 < *(s16 *)(arg0 + 0x2E)) {
            func_001344b0(arg0, 3, temp_6);
        }
    } else {
        temp_6_2 = temp_2 - 5;
        if (temp_6_2 < *(s16 *)(arg0 + 0x2C)) {
            func_001344b0(arg0, 2, temp_6_2);
        }
    }
    func_0045af60(0, 3, 0, 7);
    return 1;
}
// FUN_0013D7D0
void func_0013d7d0(u8 *arg0, s32 arg1) {
    code13Pair sp0;
    code13Pair sp1;

    switch (arg1) {
    case 0:
        sp0.first = 0x43030000;
        sp0.second = 0xC26C0000;
        func_0011d080(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        func_0011d0d0(*(u8 **)(arg0 + 0x1CB4), &sp0);
        func_0011d170(*(u8 **)(arg0 + 0x1CB4), -1, -0x7F00);
        return;
    case 1:
        sp1.first = 0x43030000;
        sp1.second = 0xC2600000;
        func_0011d0a0(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        func_0011d0d0(*(u8 **)(arg0 + 0x1CB4), &sp1);
        func_0011d170(*(u8 **)(arg0 + 0x1CB4), -1, 0xFFE92C00);
        return;
    }
}
// FUN_0013D8B0
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013d8b0);
// FUN_0013E7C0
void func_0013e7c0(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    func_00453670(sp40, 0xC, *(s16 *)(arg0 + 0x4E), *(s16 *)(arg0 + 0x52), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_00136fa0(arg0, 1, *(s32 *)(sp40 + 0x24));
        *arg1 = 8;
        if (temp_2 == 1) {
            func_0011c2c0(*(s32 *)(arg0 + 0x1CB4), 1, func_0010ace0(*(s16 *)(arg0 + 0x52)), 0);
            return;
        }
        if (temp_2 == 2) {
            func_0011c180(*(s32 *)(arg0 + 0x1CB4), 1, func_0010ace0(*(s16 *)(arg0 + 0x52)), 0);
        }
    }
}
// FUN_0013E8E0
s32 func_0013e8e0(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;
    s32 temp_18;

    func_00453670(sp40, 8, *(s16 *)(arg0 + 0x34), *(s16 *)(arg0 + 0x50), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_00136fa0(arg0, 0, *(s32 *)(sp40 + 0x24));
        *arg1 = 0xB;
        temp_18 = *(u16 *)(code13AddOff(*(s32 *)(sp40 + 0x24) * 2, arg0) + 0x24);
        if (temp_2 == 1) {
            func_0011c2c0(*(s32 *)(arg0 + 0x1CB4), temp_18, func_0010a900(temp_18), 0);
        } else if (temp_2 == 2) {
            func_0011c180(*(s32 *)(arg0 + 0x1CB4), temp_18, func_0010a900(temp_18), 0);
        }
        return 1;
    }
    return 0;
}
// FUN_0013EA20
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ea20);
// FUN_0013F4D0
void func_0013f4d0(s32 *arg0, s16 arg1, s32 arg2, u8 *arg3) {
    s32 temp_18;
    u16 temp_3;

    temp_18 = *(s16 *)(arg3 + 0x60) + *(s16 *)(arg3 + 0x5E);
    if (func_0013f620(arg1, temp_18, arg3) == 0) {
        func_0045af60(0, 0, 0, 8);
        return;
    }
    temp_3 = func_0010f8c0(*(u16 *)(code13AddOff(temp_18 * 0xC, arg3) + 0x102)) & 0xFFFF;
    if (temp_3 == 0) {
        func_0013a040(arg3, 3, 0);
        func_0013a530(arg3, 5);
        func_0013aa00(arg3);
        if (arg0 != 0) {
            *arg0 = 7;
        }
    } else {
        if ((temp_3 == 2) || (temp_3 == 1)) {
            func_0013a530(arg3, 7);
            if (arg0 != 0) {
                *arg0 = 9;
            }
        }
    }
    func_0034bb20(9);
    func_0045af60(0, 0, 0, 1);
}
// FUN_0013F620
s32 func_0013f620(s16 arg0, s32 arg1, u8 *arg2) {
    s32 var_19;
    s16 var_18;
    s16 temp_17;
    u16 temp_16;
    u8 *temp_2;

    var_19 = 1;
    var_18 = -1;
    temp_2 = code13AddOff(arg1 * 0xC, arg2);
    temp_16 = *(u16 *)(temp_2 + 0x102);
    temp_17 = *(s16 *)(temp_2 + 0x100);
    if (func_0010f540(temp_16) == 0) {
        return 0;
    }
    if (temp_17 != -1) {
        var_18 = (s16)func_0010b510();
        func_0010b3b0(temp_17);
    }
    if (func_0010f6a0(arg0, temp_16) != 0) {
        var_19 = 0;
    }
    if (var_18 != -1) {
        func_0010b3b0(var_18);
    }
    return var_19;
}
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
s32 func_0013ffd0(u8 *arg0) {
    s16 temp;
    s32 i;
    s32 result;
    u8 *p;

    result = 1;
    temp = *(s16 *)(arg0 + 0x20);
    if (temp < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp + 1;
    }
    i = 0;
    goto loop_test;
loop_body:
    if ((i >= 0x1C) || ((i >= 9) && (i < 0x10))) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0x40, *(s16 *)(arg0 + 0x20), 1);
    } else {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0x40, *(s16 *)(arg0 + 0x20), 0);
    }
    if (*(u8 *)(p + 0x5A) != 0) {
        result = 0;
    }
    i++;
loop_test:
    if (i < 0x29) {
        goto loop_body;
    }
    func_00141d10(arg0);
    func_001400f0(arg0);
    return result;
}
