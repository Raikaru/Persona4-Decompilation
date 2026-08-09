#include "include_asm.h"
#include "type.h"
typedef struct {
    f32 x;
    f32 y;
} Vec2f;
void func_00113800(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4);
void func_001138c0(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4);
void func_00113e30(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4);
void func_0011fdf0(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
void func_001203a0(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3, s32 arg4_2);
extern s32 iGpffffb1b4;

extern s32 D_005E45E0[];
extern s8 D_005E3A02[];
extern s8 D_005E3A04[];
extern u8 D_00797B7C[];
extern s32 D_0079B40C[];

extern u8 D_0079B6D8[];

extern s8 D_005E3A00[];

s32 func_0029e970(void);
void func_0029e980(s32);

void func_00106390(s32, s32);
s32 func_001110e0(void);
void func_00111160(s32);
void func_001113b0(void);
void func_004534f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 iGpffffb1bc;
extern s32 iGpffffb19c;
extern void func_001104d0(s32 seed, s32 *month, s32 *day);
extern s32 iGpffffb1b8;
extern s32 iGpffffb1f0;
extern void (*jtbl_008873EC[])(u8 *);
extern u8 *func_0010d7c0(s32 a, s32 *b, s32 c);
extern u8 D_007BBF00[];
extern void func_0043f810(void *dst, void *src, s32 n);
extern s16 D_00797B7A[];

extern u8 D_0079BEF4[];
extern s32 D_005E4610[];
extern s32 func_00106330(s32 arg0);
extern void func_00453570(void);
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00452080(void);
extern s32 func_0010f560(s16 arg0, u16 arg1);
extern s32 func_0010f600(s16 arg0, u16 arg1);
extern void *func_00243840(u16 arg0);
extern void func_00274ed0(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6, s32 arg7, s32 arg8);
extern s8 D_005E47F0[];
static inline s32 p4_00113520_add(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 p4_00110850_add(s32 offset, s32 base)
{
    s32 temp;

    temp = offset;
    return base + temp;
}


// FUN_00110460
u32 func_00110460(void) {
    return *(u32 *)D_0079BEF4;
}
// FUN_001104A0
s32 func_001104a0(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}



// FUN_001104D0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001104d0);
// FUN_00110580
s32 func_00110580(s32 arg0) {
    return (((arg0 % 0x16D) % 7) + 5) % 7;
}
// FUN_001105B0
s32 func_001105b0(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_001104d0(arg0, &sp1C, &sp18);
    sp18 = (sp18 - 1) / 7;
    return sp18 + 1;
}

/* The month index is walked in the PARAMETER, not a fresh local: retail keeps
   it in $a0 for the whole loop, and any separate `cur` local rotates the three
   live values through $a3/$a2/$a0 instead (identical instruction sequence,
   11 differing words). */
// FUN_00110600
s32 func_00110600(s32 arg0, s32 arg1) {
    s32 sum = 0;
    s32 next;

    if (arg0 != 4) {
        arg0 = arg0 - 1;
        if (arg0 == 0) {
            arg0 = 12;
        }
        do {
            next = arg0 - 1;
            sum = sum + D_005E45E0[next % 12];
            if (arg0 == 4) {
                break;
            }
            arg0 = next;
            if (next == 0) {
                arg0 = 12;
            }
        } while (1);
    }
    return sum + (arg1 - 1);
}

// FUN_00110680
s32 func_00110680(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    s32 sp38;

    func_001104d0(D_00797B7A[0], &sp3C, &sp38);
    if (sp3C == arg1 && sp38 == arg2) {
        return 1;
    }
    return 0;
}

// FUN_001106F0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001106f0);
// FUN_00110810
void func_00110810(s32 arg0, s8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}



// FUN_00110850
s64 func_00110850(s32 arg0, u32 arg1)
{
    s32 temp_4;
    s32 temp_5;
    s32 temp_6;
    u32 var_5;

    var_5 = arg1;
    if ((arg0 == D_00797B7A[0]) && (var_5 == D_00797B7C[0])) {
        if (D_0079B40C[0] & 8) {
            return 0;
        }
        if (D_0079B40C[0] & 0x10) {
            return 1;
        }
        if (D_0079B40C[0] & 0x20) {
            return 2;
        }
        if (D_0079B40C[0] & 0x40) {
            return 3;
        }
        if (D_0079B40C[0] & 0x80) {
            return 4;
        }
        goto block_12;
    }
block_12:
    switch (var_5) {
    case 0:
    case 1:
        var_5 = 0;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        var_5 = 1;
        break;
    }
    temp_4 = arg0 * 6;
    temp_5 = p4_00110850_add(temp_4, (s32)&D_005E3A02);
    temp_6 = var_5 * 2;
    return (s64) ((s64) *((u8 *)(temp_6 + temp_5)) << 0x38) >> 0x38;
}
// FUN_00110960
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110960);
// FUN_00110A60
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00110a60);
// FUN_00110C50
s32 func_00110c50(s32 arg0, s32 arg1)
{
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_5;
    s32 temp_2;
    u16 temp_3;
    u16 temp_3_2;
    s32 var_2;
    s32 var_5;

    if ((arg1 + 3) < arg0) {
        temp_4 = arg0 * 6;
        temp_3 = *(u16 *)((s32)&D_005E3A02 + temp_4);
        if (temp_3 & 0x8000) {
            temp_5 = (u16)(temp_3 & 0x7F00) >> 8;
            var_5 = temp_5 & 0xFFFF;
        } else {
            var_5 = temp_3 & 0xFF;
        }
        temp_3_2 = *(u16 *)((s32)&D_005E3A04 + temp_4);
        if (temp_3_2 & 0x8000) {
            temp_2 = (u16)(temp_3_2 & 0x7F00) >> 8;
            var_2 = temp_2 & 0xFFFF;
        } else {
            var_2 = temp_3_2 & 0xFF;
        }
    } else {
        temp_3_3 = arg0 * 6;
        var_5 = *(u8 *)((s32)&D_005E3A02 + temp_3_3);
        var_2 = *(u8 *)((s32)&D_005E3A04 + temp_3_3);
    }
    return ((var_5 & 0xFFFF) + ((var_2 & 0xFFFF) * 0x10)) & 0xFFFF;
}
// FUN_00110D30
s32 func_00110d30(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}



/* measured: opt_rebuildconditionals off preserves the direct range guards. */
#pragma opt_rebuildconditionals off
// FUN_00110D60
s32 func_00110d60(s32 arg0)
{
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_16;
    s32 var_2;
    s32 var_2_2;

    var_16 = 0;
    temp_18 = func_00110600(4, 1);
    temp_2 = func_00110600(6, 0xC);
    if ((arg0 >= temp_18) && (arg0 <= temp_2)) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if (var_2 == 0) {
        temp_2_2 = func_00110600(0xA, 0xA);
        temp_2_3 = temp_2_2 + 0x16C;
        if ((arg0 >= temp_2_2) && (arg0 <= temp_2_3)) {
            var_2_2 = 1;
        } else {
            var_2_2 = 0;
        }
        if (var_2_2 != 0) {
            goto block_10;
        }
    } else {
block_10:
        var_16 |= 1;
    }
    if (D_005E3A00[D_00797B7A[0] * 6] != 0) {
        var_16 |= 2;
    }
    return var_16;
}
/* measured: restore opt_rebuildconditionals on after func_00110d60. */
#pragma opt_rebuildconditionals on
// FUN_00110E70
void func_00110e70(s32 arg0)
{
    iGpffffb1b4 = arg0;
}

// FUN_00110E80
void func_00110e80(void) {
    s32 sp3C;
    u8 *p;
    s32 n;

    p = func_0010d7c0(0, &sp3C, 1);
    n = sp3C;
    func_0043f810(D_007BBF00, p, n);
    iGpffffb1b8 = n;
    jtbl_008873EC[0](p);
    iGpffffb1b4 = 1;
}

/* measured: opt_propagation off is required to preserve retail GP-load argument materialization order. */
#pragma opt_propagation off
// FUN_00110F00
s32 func_00110f00(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 buffer;
    s32 zero;
    s32 var_2;

    var_2 = 0;
    temp_16 = iGpffffb19c;
    if (iGpffffb1b4 != 0) {
        func_00260560();
        func_00122520(1, 1);
        temp_17 = func_001110e0();
        func_001113b0();
        iGpffffb1f0 = 1;
        buffer = (s32)&D_007BBF00;
        temp_18 = iGpffffb1b8;
        zero = 0;
        buffer += 4;
        func_0010e710(zero, buffer, temp_18);
        func_00111160(temp_17);
        iGpffffb19c = temp_16;
        func_001029a0(0x1A, 0, 0, 0);
        var_2 = 1;
    }
    return var_2;
}
/* measured: restore opt_propagation after func_00110f00. */
#pragma opt_propagation on
// FUN_00110FC0
void func_00110fc0(void) {
    func_00260560();
    func_00122520(1, 1);
    func_001029a0(0x1B, 0, 0, 8);
}

// FUN_00111010
void func_00111010(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}



// FUN_00111050
void func_00111050(s32 arg0)
{
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
    if (arg0 != 0) {
        iGpffffb1bc = 0;
    }
}

// FUN_001110E0
s32 func_001110e0(void) {
    u32 var_17;
    s32 var_16;

    var_16 = 0;
    for (var_17 = 0; var_17 < 6U; var_17++) {
        if (func_00106330(D_005E4610[var_17]) != 0) {
            var_16 |= 1 << var_17;
        }
    }
    return var_16;
}
// FUN_00111160
void func_00111160(s32 arg0)
{
    u32 var_16;
    var_16 = 0;
    for (var_16 = 0; var_16 < 6U; var_16++) {
        if (arg0 & (1 << var_16)) {
            func_00106390(D_005E4610[var_16], 1);
        } else {
            func_00106390(D_005E4610[var_16], 0);
        }
    }
}
// FUN_00111200
s32 func_00111200(void)
{
    u32 var_17;
    s32 var_16;
    s32 result;

    var_16 = 0;
    for (var_17 = 0; var_17 < 6U; var_17++) {
        if (func_00106330(D_005E4610[var_17]) != 0) {
            var_16 |= 1 << var_17;
        }
    }
    result = var_16 | 0x80000000;
    iGpffffb1bc = result;
    return result;
}
// FUN_00111290
void func_00111290(void)
{
    s32 temp_16;
    u32 var_17;

    temp_16 = iGpffffb1bc;
    if (temp_16 & 0x80000000) {
        for (var_17 = 0; var_17 < 6U; var_17++) {
            if (temp_16 & (1 << var_17)) {
                func_00106390(D_005E4610[var_17], 1);
            } else {
                func_00106390(D_005E4610[var_17], 0);
            }
        }
    } else {
        func_00106390(0x39, 1);
        func_00106390(0x3A, 1);
        func_00106390(0x3B, 0);
        func_00106390(0x3C, 1);
        func_00106390(0x3D, 1);
        func_00106390(0x3E, 0);
    }
    iGpffffb1bc = 0;
}
// FUN_001113B0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001113b0);
// FUN_00111BC0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00111bc0);
// FUN_00112300
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112300);
// FUN_001125D0
void func_001125d0(u8 *arg0) {
    s32 temp_1;
    s32 temp_m1;

    temp_1 = 1;
    *(s16 *)(arg0 + 0) = temp_1;
    temp_m1 = -1;
    *(s16 *)(arg0 + 2) = temp_m1;
    *(s16 *)(arg0 + 6) = temp_m1;
    *(s32 *)(arg0 + 8) = temp_m1;
    *(s32 *)(arg0 + 0xC) = temp_1;
    *(s32 *)(arg0 + 0x10) = 0;
    temp_m1 = 3;
    *(s16 *)(arg0 + 0x14) = temp_m1;
    *(s16 *)(arg0 + 0x18) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
// FUN_00112610
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112610);
// FUN_00112830
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112830);
// FUN_001130C0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001130c0);
// FUN_00113280
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113280);
// FUN_00113480
void func_00113480(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (func_00106330(0x39) != 0) {
        func_004534f0(arg0, arg1, arg2, arg3);
    }
}
// FUN_00113500
void func_00113500(void) {
    func_00453570();
}
// FUN_00113520
s32 func_00113520(s32 arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    s32 temp_3;
    u16 temp_2;
    u16 temp_5;

    *(u16 *)(arg3 + 2) = 0;
    *(s32 *)(arg3 + 4) = 0;
    *(s32 *)(arg3 + 8) = 0;
    temp_2 = *(u16 *)(p4_00113520_add(arg2 * 2, arg1) + 0xC);
    if (temp_2 != 0) {
        *(u16 *)(arg3 + 2) = temp_2;
        if (arg0 != 0) {
            temp_5 = *(u16 *)(arg3 + 2);
            if ((s32)temp_5 < 0x1B8) {
                temp_3 = func_0010f560((s16)arg0, temp_5) & 0xFFFF;
                switch (temp_3) {
                case 1:
                    *(s32 *)(arg3 + 4) = func_0010f600((s16)arg0, *(u16 *)(arg3 + 2));
                    break;
                case 2:
                    *(s32 *)(arg3 + 8) = func_0010f600((s16)arg0, *(u16 *)(arg3 + 2));
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}
// FUN_00113610
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113610);
// FUN_00113730
void func_00113730(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}
// FUN_00113750
void func_00113750(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 2) = 0;
    *(s8 *)(arg0 + 4) = -1;
    *(s8 *)(arg0 + 5) = -1;
    func_0043f9c8(arg0 + 8, 0, 0x22C);
}
// FUN_00113790
void func_00113790(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4)
{
    s16 temp_8;

    temp_8 = *(s16 *)arg2;
    switch (temp_8) {
    case 0:
        func_00113800(arg0, arg1, arg2, arg3, arg4);
        return;
    case 1:
        func_001138c0(arg0, arg1, arg2, arg3, arg4);
        return;
    case 2:
        func_00113e30(arg0, arg1, arg2, arg3, arg4);
        return;
    }
}
/* measured: retail places the incoming float save before the two GP callee-save
   moves; b210 keeps the identical 184B body but emits those three prologue
   moves in GP-then-FP order. Declaration, scheduling, and O1 probes retained
   the nd 10 residual. Committed at nd 10. */
// FUN_00113800 NONMATCHING
#ifdef NON_MATCHING
void func_00113800(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4)
{
    f32 scale;
    s32 color;
    s8 index;
    void *temp;

    scale = arg4;

    temp = func_00243840(*(u16 *)((u8 *)arg2 + 0xA));
    color = -0x100 | (((arg1 & 0xFF) * 0xFF) / 255U);
    index = *(s8 *)((s32)D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2));
    func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, index, 1, temp, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00113800);
#endif
// FUN_00115830
void func_00115830(u8 *arg0) {
    func_0043f9c8(arg0 + 8, 0, 0x3C);
    func_0043f9c8(arg0 + 0x44, 0, 0x3C);
    *(s16 *)(arg0 + 0) = 1;
    *(s16 *)(arg0 + 2) = 0;
    *(s32 *)(arg0 + 4) = 0;
}
// FUN_0011FCF0
s32 func_0011fcf0(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 8) == 8;
}
// FUN_0011FD10
void func_0011fd10(void) {
    func_00452080();
}
// FUN_0011FD30
void func_0011fd30(u8 *arg0) {
    *(s16 *)(arg0 + 4) = -1;
    *(s16 *)(arg0 + 6) = 0;
}
// FUN_0011FD50
void func_0011fd50(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s32 temp_7;

    temp_7 = *(s32 *)(arg2 + 8);
    switch (temp_7) {
    case 0:
        func_0011fdf0(arg0, arg4, arg1, arg2, temp_7);
        return;
    case 1:
        func_001203a0(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 2:
        func_001203a0(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 3:
        func_001203a0(arg0, arg4, arg1, arg2, 1, arg3);
        return;
    }
}
// FUN_0011FDF0
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_0011fdf0);