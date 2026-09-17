#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern u8 *func_001094d0(void);
extern s32 func_00109510(s32 arg0, void *arg1, void *arg2);
extern void func_0010e710(s32, u8 *, s32);
typedef struct {
    f32 x;
    f32 y;
} Vec2f;
void func_00113800(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void func_001138c0(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void func_00113e30(Vec2f arg0, f32 fparg0, u8 arg1, void *arg2, s32 arg3);
void func_0011fdf0(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
void func_001203a0(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3, s32 arg4_2);
extern s32 iGpffffb1b4;
extern u8 iGpffff9bb8[8]; /* Default surname at gp - 0x6448. */
extern u8 iGpffff9bc0[8]; /* Default given name at gp - 0x6440. */

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
extern void (*jtbl_008873EC[])(void *);
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
extern u32 func_0010f600(s16 arg0, s32 arg1);
extern void *func_00243840(u16 arg0);

extern void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, f32 z, s32 arg4);
extern void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern u32 func_00106880(s16 arg0);
extern s32 func_0046a770(void *param);
extern s32 func_001068b0(s16 arg0);
extern s32 func_00106940(s16 arg0);
extern s32 func_00106970(s16 arg0);
extern s32 func_00106c30(s16 arg0, s16 arg1);
extern s32 func_00106c80(s16 arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern u8 *func_0010d620(s16 arg0);
extern s8 func_00123ae0(void);
extern s16 func_00123b10(void);
extern s16 func_00123b40(void);
extern u8 D_005E4F70[];
extern s8 D_005E47F0[];
static inline s64 p4_0011_signext16(s16 arg0)
{
    return (s64)arg0;
}
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
static inline s32 p4_0011_add_left(s32 left, s32 right)
{
    return left + right;
}
static inline s64 p4_0011_load_s8(s8 *ptr)
{
    s64 temp;

    temp = *ptr;
    return temp;
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



 
/* measured: opt_loop_invariants on hoists the divisor and table base into the loop preheader. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off preserves the retail duplicate table loads and local colouring. */
#pragma opt_propagation off
// FUN_001104D0
void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2)
{
    s32 temp_8;
    s32 temp_9;
    s32 var_12;
    s32 var_11;
    s32 var_10;

    var_11 = arg0 % 0x16D;
    var_12 = 3;
    var_10 = 0;
    goto loop_test;
loop_body:
    temp_9 = var_12 + 1;
    temp_8 = temp_9 - 1;
    if (var_11 < D_005E45E0[(temp_9 - 1) % 0xC]) {
        goto done;
    }
    var_11 = var_11 - D_005E45E0[temp_8 % 0xC];
    var_12 = temp_9;
    if (temp_9 < 0xC) {
        goto loop_increment;
    }
    var_12 = 0;
loop_increment:
    var_10 = var_10 + 1;
loop_test:
    if (var_10 < 0xC) {
        goto loop_body;
    }
done:
    *arg1 = var_12 + 1;
    *arg2 = var_11 + 1;
}
/* measured: restore opt_propagation after func_001104d0. */
#pragma opt_propagation on
#pragma opt_loop_invariants off
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
s32 func_001106f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_6;
    s32 var_11;
    s32 var_10;
    s32 var_10_2;
    s32 temp_9;
    s32 var_7;
    s32 lower;
    s32 upper;

    var_10 = 0;
    if (arg1 != 4) {
        var_11 = arg1 - 1;
        if (var_11 == 0) {
            var_11 = 0xC;
        }
loop_3:
        temp_9 = var_11 - 1;
        var_10 += D_005E45E0[temp_9 % 12];
        if (var_11 != 4) {
            var_11 = temp_9;
            if (temp_9 == 0) {
                var_11 = 0xC;
            }
            goto loop_3;
        }
    }
    lower = var_10 + (arg2 - 1);
    var_10_2 = 0;
    if (arg3 != 4) {
        var_7 = arg3 - 1;
        if (var_7 == 0) {
            var_7 = 0xC;
        }
loop_9:
        temp_6 = var_7 - 1;
        var_10_2 += D_005E45E0[temp_6 % 12];
        if (var_7 != 4) {
            var_7 = temp_6;
            if (temp_6 == 0) {
                var_7 = 0xC;
            }
            goto loop_9;
        }
    }
    upper = var_10_2 + (arg4 - 1);
    if (arg0 < lower) {
        goto fail;
    }
    if (arg0 > upper) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}
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
/* measured: opt_propagation off retains the retail byte-load staging. */
#pragma opt_propagation off
/* measured probe: opt_common_subs off preserves the retail fallback loads. */
#pragma opt_common_subs off
// FUN_00110960
s64 func_00110960(s32 arg0, u32 arg1)
{
    s32 loaded;
    s32 value;
    s64 result;
    s32 selection;

    result = -1;
    if ((arg0 == (s16)func_00123b10()) &&
        (arg1 == (s16)func_00123b40())) {
        result = (s8)func_00123ae0();
    }
    if ((s8)result == -1) {
        switch (arg1) {
        case 0:
        case 1:
            selection = 0;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            selection = 1;
            break;
        }
        value = arg0 * 6;
        value = p4_00110850_add(value, (s32)&D_005E3A02);
        selection *= 2;
        value = p4_0011_add_left(selection, value);
        loaded = p4_0011_load_s8((s8 *)value);
        result = loaded;
    }
    return result;
}
/* measured: restore opt_propagation after func_00110960. */
#pragma opt_propagation on
/* measured probe: restore opt_common_subs after func_00110960. */
#pragma opt_common_subs on
static inline s64 calendarOverrideValue(s32 date, s32 phase)
{
    s64 result;
    s32 address;
    s32 loaded;

    result = -1;
    if (date == (s16)func_00123b10() && (s16)func_00123b40() == phase)
        result = (s8)func_00123ae0();
    if ((s8)result == -1) {
        address = p4_00110850_add(date * 6, (s32)D_005E3A02);
        loaded = p4_0011_load_s8((s8 *)address + 2);
        result = loaded;
    }
    return result;
}

/* Measured: keep the shared month divisor live through December wrapping,
   and retain the signed override staging in both inlined phase branches. */
#pragma opt_propagation off
#pragma opt_common_subs off
// FUN_00110A60
s64 func_00110a60(s32 month, s32 day)
{
    extern s32 func_00110d30(s32 date);
    s32 previous;
    s32 total;
    s32 next;
    s32 divisor;

    total = 0;
    if (month != 4) {
        previous = month - 1;
        if (previous == 0) previous = 12;
        do {
            next = previous - 1;
            divisor = 12;
            total += D_005E45E0[next % divisor];
            if (previous == 4) break;
            previous = next;
            if (next == 0) previous = divisor;
        } while (1);
    }
    if (func_00110d30(total + (day - 1)) == 1)
        return calendarOverrideValue(func_00110600(month, day), 3);
    return calendarOverrideValue(func_00110600(month, day), 4);
}
#pragma opt_common_subs on
#pragma opt_propagation on
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
        func_0010e710(zero, (u8 *)buffer, temp_18);
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
/* Measured: 1032 bytes, 58 resolved relocations, eight zero alignment bytes.
 * Default names are separate eight-byte objects. Keep each table's base
 * with the trailing halfword offsets and reload maxima after Persona setup. */
// FUN_001113B0
void func_001113b0(void)
{
    s32 j;
    s32 i;
    u8 *p;
    u8 *q;
    u16 func_00104dc0(s16);
    u16 func_00104e30(s16);
    void func_001051a0(s16, s16, s16);
    void func_001055a0(s16);
    void func_00105690(s16, u8);
    void func_001056e0(s16, s16);
    void func_00105730(s16, s16);
    void func_00105990(s16, u32);
    void func_00105c90(s16, s16);
    void func_00105ce0(s16, s16);
    void func_00105dc0(s16, s16, s16);
    void func_00105fa0(u32);
    void func_00106000(s32, s16);
    void func_00106100(s16);
    void func_001062f0(u8);
    void func_00106300(s16);
    void func_00106310(u8);
    void func_00106320(u32);
    void func_00106480(void);
    void func_001064c0(void);
    void func_001065c0(void);
    void func_00106620(s32, s32);
    void func_00106d40(s16, s16, s16);
    void func_001070b0(void);
    s32 func_0010b9a0(s32, u16);
    void func_0010bd90(s16);
    void func_0010d490(u8 *, u8 *);
    void func_0010f390(void);
    void func_0010f4c0(void);
    void func_0010fc80(void);
    void func_00155250(void);
    void func_0015a630(void);
    void func_00162120(void);
    extern u16 D_005E4630[];
    extern s16 D_005E4650[];

    func_00110e70(0);
    func_00106320(0);
    func_0010d490(iGpffff9bb8, iGpffff9bc0);
    func_00105fa0(0);
    func_0010fc80();

    i = 1;
    goto loop_1_check;
loop_1:
    func_001055a0((s16)i);
    if (i == 1) {
        func_00105690((s16)i, 1);
        func_00105990((s16)i, 0);
    }
    func_001056e0((s16)i, 1);
    func_00105730((s16)i, 1);
    j = 0;
    goto loop_2_check;
loop_2:
    func_001051a0((s16)i, (s16)j, 0);
    j++;
loop_2_check:
    if (j < 5) {
        goto loop_2;
    }
    func_00105c90((s16)i, 0);
    func_00105ce0((s16)i, 0);
    func_00105dc0((s16)i, 0, -1);
    func_00105dc0((s16)i, 1, -1);
    func_00105dc0((s16)i, 2, -1);
    func_0010bd90((s16)i);
    q = (u8 *)D_005E4630 + i * 2;
    func_0010b9a0(i & 0xFFFF, *(u16 *)(q - 2));
    func_001056e0((s16)i, (s16)func_00104dc0((s16)i));
    func_00105730((s16)i, (s16)func_00104e30((s16)i));
    i++;
loop_1_check:
    if (i < 11) {
        goto loop_1;
    }

    func_00106480();
    func_001065c0();
    func_001064c0();
    func_001062f0(5);
    func_00106100(9);
    func_00106310(5);
    func_00106300(9);
    i = 0;
    goto loop_3_check;
loop_3:
    func_00106620((s16)i, 0);
    i++;
loop_3_check:
    if (i < 1536) {
        goto loop_3;
    }

    i = 1;
    goto loop_4_check;
loop_4:
    p = (u8 *)D_005E4650 + i * 6;
    func_00106d40((s16)i, 0, *(s16 *)(p - 6));
    func_00106d40((s16)i, 1, *(s16 *)(p - 4));
    func_00106d40((s16)i, 2, *(s16 *)(p - 2));
    i++;
loop_4_check:
    if (i < 11) {
        goto loop_4;
    }

    func_00106000(0, 0);
    func_00106000(1, 0);
    func_00106000(2, 0);
    func_00106000(3, 0);
    func_00155250();
    func_00162120();
    func_0015a630();
    func_0010f390();
    func_0010f4c0();
    func_001070b0();

    i = 0;
    goto loop_5_check;
loop_5:
    func_00110810(i, 0);
    i++;
loop_5_check:
    if (i < 1536) {
        goto loop_5;
    }
    iGpffffb1f0 = 0;
    iGpffffb19c = 0;
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
}
// FUN_00111BC0
#pragma opt_propagation off
void func_00111bc0(void)
{
    s32 saved;
    s32 value;
    s32 end_date;
    s32 result;
    s32 count;
    s8 flag;
    s32 i;
    s32 buf[344];
    s32 func_001064f0(s32);
    void func_00106550(s32, u32);
    s32 func_00106600(s16);
    s32 func_00106330(s32);
    void func_00106390(s32, s32);
    s16 func_00104ea0(s16, s16);
    u32 func_00105ed0(void);
    void func_00105fa0(u32);
    void func_00106620(s32, s32);
    void func_001051a0(s16, s16, s16);
    u32 func_00110460(void);
    void func_00110470(u32);
    void func_00310700(void);
    void func_00310850(void);
    extern float D_005E4700[4];
    typedef struct { float a; float b; float c; float d; } Vec4;
    saved = iGpffffb19c;
    count = 0;
    flag = 0;
    *(Vec4 *)buf = *(Vec4 *)D_005E4700;
    value = func_001064f0(0x7C);
    end_date = (s32)func_00110460() + 1;
    if ((func_00106600(0x4A0) & 0xFF) > 0) {
        buf[4] = 0x4A0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A4) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A5) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A6) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A7) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A8) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A9) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AA) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AB) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AC) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AD) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AE) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AF) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B0) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x418) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x418;
        count = (count + 1) & 0xFF;
    }
    if (func_00106330(0x2F) != 0) {
        flag = 1;
    }
    if (func_00106330(0x1DD) != 0) {
        flag = 1;
    }
    i = 0;
    goto loop1_check;
loop1:
    buf[332 + i] = func_00106330(i + 0x39);
    i++;
loop1_check:
    if (i < 7) {
        goto loop1;
    }
    result = 0;
    goto loop2_check;
loop2:
    {
        s32 *p = &buf[result];
        s32 v = *p;
        if (v == 0) {
            goto loop2_done;
        }
        buf[132 + result] = func_00106330(v);
        result++;
    }
loop2_check:
    if (result < 200) {
        goto loop2;
    }
loop2_done:
    func_00310700();
    i = 0;
    goto loop3_check;
loop3:
    ((s16 *)buf)[680 + i] = func_00104ea0(1, (s16)i);
    i++;
loop3_check:
    if (i < 5) {
        goto loop3;
    }
    result = (s32)func_00105ed0();
    func_001113b0();
    i = 0;
    goto loop4_check;
loop4:
    func_00106390(i + 0x39, buf[332 + i]);
    i++;
loop4_check:
    if (i < 7) {
        goto loop4;
    }
    i = 0;
    goto loop5_check;
loop5:
    {
        s32 *p = &buf[i];
        s32 v = *p;
        if (v == 0) {
            goto loop5_done;
        }
        func_00106390(v, buf[132 + i]);
        i++;
    }
loop5_check:
    if (i < 200) {
        goto loop5;
    }
loop5_done:
    i = 0;
    count &= 0xFF;
    goto loop6_check;
loop6:
    func_00106620(((s16 *)buf)[8 + i * 2], 1);
    i++;
loop6_check:
    if (i < count) {
        goto loop6;
    }
    if (flag == 1) {
        func_00106390(0x1DD, 1);
    }
    func_00310850();
    func_00106390(0x1210, 1);
    func_00106550(0x7C, (u32)value);
    func_00110470((u32)end_date);
    i = 0;
    goto loop7_check;
loop7:
    func_001051a0(1, (s16)i, ((s16 *)buf)[680 + i]);
    i++;
loop7_check:
    if (i < 5) {
        goto loop7;
    }
    func_00105fa0((u32)result);
    func_00106390(0x800, 1);
    iGpffffb19c = saved;
}
#pragma opt_propagation on
// FUN_00112300
void func_00112300(s64 arg0, f32 fparg0, u8 arg1, u8 *arg2)
{
    u8 buf[256];
    s32 temp16;
    s32 temp19;
    union {
        s64 whole;
        f32 values[2];
        Vec2f position;
    } xy;
    f32 temp_1;
    s32 temp_2;
    
    s32 func_00106a90(s16);
    void func_00442088(void *, void *, s32);
    s32 func_0046a770(void *);
    void func_0046d730(void *, s32);
    void func_00112610(s64, f32, u8, u8 *, s32, s32);
    void func_00112830(s64, f32, u8, u8 *, s32);
    void func_001130c0(Vec2f, f32, u8, u8 *, s32);
    extern f32 D_005E4790[];
    extern f32 D_005E4794[];
    extern f32 D_005E479C[];
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 iGpffff9be0;
    extern u8 iGpffff9bd8;
    extern u8 iGpffff9be8;

    temp16 = func_0046a770(D_005E5830);
    temp19 = func_0046a770(D_005E5850);
    if (temp16 == 0) {
        func_0046d730(&iGpffff9be0, 0x93);
    }
    if (temp19 == 0) {
        func_0046d730(&iGpffff9be0, 0x94);
    }
    if (*(u16 *)(arg2 + 0x14) != 0) {
        func_00112610(arg0, fparg0, arg1, arg2, temp16, temp19);
        *(f32 *)&arg0 = *(f32 *)&arg0 + 45.0f;
    }
    if (*(s32 *)(arg2 + 0xC) != 0) {
        temp19 = arg1 & 0xFF;
        temp_2 = (s32)func_001067f0(*(s16 *)arg2);
        func_00275020(
            *(f32 *)&arg0,
            *(f32 *)((u8 *)&arg0 + 4),
            fparg0,
            temp19 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
            1,
            (const char *)temp_2,
            0,
            -1);
    }
    if (*(s32 *)(arg2 + 0x10) != 0) {
        xy.values[0] = *(f32 *)&arg0 +
                       D_005E4790[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 9.0f;
        temp_1 += *(f32 *)((u8 *)&arg0 + 4);
        xy.values[1] = temp_1;
        func_00112830(xy.whole, fparg0, arg1, arg2, temp16);
    }
    if (*(s16 *)(arg2 + 2) != -1) {
        xy.position.x = *(f32 *)&arg0 +
                        D_005E4794[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 12.0f;
        temp_1 += *(f32 *)((u8 *)&arg0 + 4);
        xy.position.y = temp_1;
        func_001130c0(xy.position, fparg0, arg1, arg2, temp16);
    }
    if (*(s32 *)(arg2 + 8) != -1) {
        xy.values[0] = *(f32 *)&arg0 +
                       D_005E479C[*(s16 *)(arg2 + 0x18) * 4];
        xy.values[1] = *(f32 *)((u8 *)&arg0 + 4);
        temp16 = ((arg1 & 0xFF) * 0xFF) / 255U;
        func_00442088(buf, &iGpffff9be8,
                      func_00106a90(*(s16 *)arg2));
        func_00274ed0(
            (f32)(s32)xy.values[0],
            (f32)(s32)xy.values[1],
            fparg0,
            temp16 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
            0,
            (void *)buf,
            0,
            0);
    }
}
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
void func_00112610(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    typedef struct {
        u8 b[4];
    } Color4;
    extern u8 D_005E4710[];
    extern u8 D_005E4730[];
    void func_00113280(s64, f32, Color4, s16, s32, s32);
    Color4 color_a;
    Color4 color_b;
    Vec2f pos;
    s32 flags;
    s32 mode;
    s32 selected;
    u8 *table;
    s32 alpha;

    flags = func_00106880(*(s16 *)(arg2 + 0));
    if (*(u16 *)(arg2 + 0x14) & 2) {
        table = &D_005E4710[(*(s16 *)(arg2 + 0x16)) * 4];
        color_a = *(Color4 *)table;
        mode = -1;
        if (flags & 0x3FFF) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0xC000) {
            mode = 3;
            selected = arg3;
        } else if (flags & 0x10000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x20000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x40000) {
            mode = 2;
            selected = arg3;
        }
        if (mode != -1) {
            alpha = 255;
            alpha -= arg1 & 0xFF;
            func_0046d4c0(0, selected, mode, arg0.x, arg0.y,
                          alpha & 0xFF,
                          color_a.b[0], color_a.b[1], color_a.b[2],
                          fparg0, 0);
        }
    }
    if (*(u16 *)(arg2 + 0x14) & 1) {
        table = &D_005E4730[(*(s16 *)(arg2 + 0x16)) * 4];
        color_b = *(Color4 *)table;
        color_b.b[3] = arg1;
        pos.x = arg0.x + 3.0f;
        pos.y = arg0.y + 2.0f;
        func_00113280(*(s64 *)&pos, fparg0, color_b,
                      *(s16 *)(arg2 + 0), arg3, arg4);
    }
}
/* measured 00112830 2026-09-17 via `python3 tools/measure_guarded.py src/promoted/code1_0011.c func_00112830`: 494wd before and after (obj 2040B/window 2192B); `value / 100` -> `value / 100U` (4 sites) clears division defect (opclass div +4/divu -4 -> 0/0, score 42 -> 34; fnalign 540 -> 540, no regression; u32 value alone flips to div -8/divu +8 with sltu +8/slt -8, so divisor widening not operand widening is correct). Remaining lbu -28/move +16 is spill not signedness: retail has 39 lbu/0 lb (all unsigned); s8 colors probe worsens 540 -> 550 edits, so byte-signedness reading disproved. */
// FUN_00112830 NONMATCHING
#ifdef NON_MATCHING
void func_00112830(s64 arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    extern u8 D_005E4750[];

    u8 *table;
    s32 current;
    s32 mode_a;
    s32 mode_b;
    u8 color_b;
    u8 color_g;
    s32 alpha;
    f32 x;
    f32 y;
    s32 kind;
    s32 value;
    s32 digit;
    s32 i;
    s64 positions[9];
    u8 colors[9][4];

    positions[0] = arg0;
    table = D_005E4750 + (*(s16 *)(arg2 + 0x16) * 4);
    colors[8][0] = table[0];
    colors[8][1] = table[1];
    colors[8][2] = table[2];
    colors[8][3] = table[3];
    colors[8][3] = arg1;
    kind = func_00106c80(*(s16 *)arg2);
    switch (kind) {
    case 0:
        value = func_001068b0(*(s16 *)arg2) & 0xFFFF;
        positions[8] = positions[0];
        if (value / 100U != 0) {
            x = 30.0f + *(f32 *)&positions[8];
        } else {
            x = 22.0f + *(f32 *)&positions[8];
        }
        y = *(f32 *)((u8 *)&positions[8] + 4);
        current = value;
        color_b = colors[7][2];
        color_g = colors[7][1];
        colors[7][3] = colors[8][3];
        colors[7][0] = colors[8][0];
        colors[7][1] = colors[8][1];
        colors[7][2] = colors[8][2];
        alpha = 0xFF - colors[8][3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, x, y, (u8)alpha,
                          colors[8][0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_001068b0(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[7] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_a = 40;
                } else if (current < value) {
                    mode_a = 41;
                }
                y = *(f32 *)((u8 *)&positions[7] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_a, *(f32 *)&positions[7], y, (u8)alpha,
                              colors[8][0], color_g, color_b, fparg0, 0);
            }
        }
        *(f32 *)&positions[0] += 42.0f;
        value = func_001068e0(*(s16 *)arg2) & 0xFFFF;
        positions[6] = positions[0];
        if (value / 100U != 0) {
            x = 30.0f + *(f32 *)&positions[6];
        } else {
            x = 22.0f + *(f32 *)&positions[6];
        }
        y = *(f32 *)((u8 *)&positions[6] + 4);
        current = value;
        color_b = colors[6][2];
        color_g = colors[6][1];
        colors[6][3] = colors[8][3];
        colors[6][0] = colors[8][0];
        colors[6][1] = colors[8][1];
        colors[6][2] = colors[8][2];
        alpha = 0xFF - colors[8][3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, x, y, (u8)alpha,
                          colors[8][0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_001068e0(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[5] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_b = 40;
                } else if (current < value) {
                    mode_b = 41;
                }
                y = *(f32 *)((u8 *)&positions[5] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_b, *(f32 *)&positions[5], y, (u8)alpha,
                              colors[8][0], color_g, color_b, fparg0, 0);
            }
        }
        break;
    case 1:
        value = func_00106940(*(s16 *)arg2) & 0xFFFF;
        positions[4] = positions[0];
        if (value / 100U != 0) {
            x = 30.0f + *(f32 *)&positions[4];
        } else {
            x = 22.0f + *(f32 *)&positions[4];
        }
        y = *(f32 *)((u8 *)&positions[4] + 4);
        current = value;
        color_b = colors[5][2];
        color_g = colors[5][1];
        colors[5][3] = colors[8][3];
        colors[5][0] = colors[8][0];
        colors[5][1] = colors[8][1];
        colors[5][2] = colors[8][2];
        alpha = 0xFF - colors[8][3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, x, y, (u8)alpha,
                          colors[8][0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_00106940(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[3] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_a = 40;
                } else if (current < value) {
                    mode_a = 41;
                }
                y = *(f32 *)((u8 *)&positions[3] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_a, *(f32 *)&positions[3], y, (u8)alpha,
                              colors[8][0], color_g, color_b, fparg0, 0);
            }
        }
        *(f32 *)&positions[0] += 42.0f;
        value = func_00106970(*(s16 *)arg2) & 0xFFFF;
        positions[2] = positions[0];
        if (value / 100U != 0) {
            x = 30.0f + *(f32 *)&positions[2];
        } else {
            x = 22.0f + *(f32 *)&positions[2];
        }
        y = *(f32 *)((u8 *)&positions[2] + 4);
        current = value;
        color_b = colors[4][2];
        color_g = colors[4][1];
        colors[4][3] = colors[8][3];
        colors[4][0] = colors[8][0];
        colors[4][1] = colors[8][1];
        colors[4][2] = colors[8][2];
        alpha = 0xFF - colors[8][3];
        do {
            digit = ((current & 0xFFFF) % 10) + 0x1E;
            func_0046d4c0(0, arg3, digit, x, y, (u8)alpha,
                          colors[8][0], color_g, color_b, fparg0, 0);
            x -= 15.0f;
            current = (current / 10) & 0xFFFF;
        } while (current > 0);
        *(f32 *)&positions[0] += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            value = func_00106970(*(s16 *)(arg2 + 6)) & 0xFFFF;
            positions[1] = positions[0];
            if (value != current) {
                if (value < current) {
                    mode_b = 40;
                } else if (current < value) {
                    mode_b = 41;
                }
                y = *(f32 *)((u8 *)&positions[1] + 4) - 1.0f;
                func_0046d4c0(0, arg3, mode_b, *(f32 *)&positions[1], y, (u8)alpha,
                              colors[8][0], color_g, color_b, fparg0, 0);
            }
        }
        break;
    case 2:
        *(f32 *)&positions[0] += 35.0f;
        *(f32 *)((u8 *)&positions[0] + 4) += 4.0f;
        current = 0;
        color_b = colors[8][2];
        color_g = colors[8][1];
        alpha = 0xFF - (arg1 & 0xFF);
        for (i = 0; i < 4; i++) {
            func_0046d4c0(0, arg3, 60,
                          *(f32 *)&positions[0],
                          *(f32 *)((u8 *)&positions[0] + 4), (u8)alpha,
                          colors[8][0], color_g, color_b, fparg0, 0);
            *(f32 *)&positions[0] += 34.0f;
            current++;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_00112830);
#endif
/* Floor (re-measured 2026-09-17): probe_variants 5 reloc-masked differing */
/* words; fnalign retail 110 instrs / object 110 instrs, 4 edits plus 5 */
/* reloc-only (110*4 = 440B in the 448B window; the 2-word suffix is retail */
/* zero-tail nop/nop). Registers, frame, both calls and the whole loop match */
/* retail; the only residual is a scheduling group swap - retail emits the */
/* two colour read-backs (lbu 0xde/0xdd(sp)) before the alpha arithmetic, */
/* this build emits them after. */
/*   WINS: writing the alpha as `255 - (arg1 & 0xFF)` on a u8 parameter */
/*   makes MWCC evaluate the masked operand first (andi, then the 0xFF */
/*   constant, then `subu $s2,$v0,$v1`), which is retail's operand order; */
/*   the bare `255 - arg1` form materialises the constant first and */
/*   reverses the subu operands. Keeping alpha_byte assigned before the */
/*   two colour locals preserves retail's $s2/$s1/$s0 assignment, which */
/*   follows definition order here (declaration order is inert in this */
/*   function; six permutations measured). */
/*   Width audit 2026-09-17 (tools/wscan_pairs): object dsll32/dsra32 pairs */
/*   1 = retail 1, the shared legitimate (s16)temp_21 sign-extension before */
/*   the sprintf call; the u8 arg1 carries no extension cost and the andi */
/*   count is 5 = 5, so u8 stands. s32-with-mask and u8-bare both score 5 */
/*   words but 6 fnalign edits (reversed subu) against this shape's 4. */
/*   WALL: moving the colour reads above the alpha statement makes the */
/*   instruction stream exact - an instruction-level alignment then */
/*   reports no inserts, deletes or reordering - but rotates the same */
/*   three registers ($s2/$s1/$s0 against retail's $s1/$s0/$s2), scoring */
/*   11 words against this shape's 5.  Measured inert on that variant: */
/*   400 declaration permutations, every colour/alpha type combination */
/*   in {u8,u16,s16,u32,s32}, and the pragmas opt_dead_assignments, */
/*   opt_lifetimes, optimize_for_size and opt_strength_reduction. */
/*   Sweep complete 2026-09-17: `opt_common_subs off` and */
/*   `opt_loop_invariants on` are neutral (5 words / 4 edits, identical */
/*   stream); `#pragma schedule on` (105) and `opt_propagation off` (78) */
/*   are worse still. Pairs 2026-09-17 (`tools/pragma_sweep.py --pairs`, */
/*   8 singles + 28 pairs, banked 5): ties at 5 among cse_off/loopinv/ */
/*   strength_off/unroll_off + 8 pairs among them; dead 58, prop 75, */
/*   sched 102, peephole 105, all sched/peephole pairs 100-109. No pair */
/*   beats the singles; floor stands at 5. Opclass 2026-09-17 (tools/opclass.py on this owner): */
/*   this floor carries no opcode-class surplus - both sides emit the lbu */
/*   pair, so the residual is genuinely scheduling, not an lb/lbu fix. */
// FUN_001130C0 NONMATCHING
#ifdef NON_MATCHING
void func_001130c0(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    typedef struct { u8 r, g, b, a; } Color;
    struct {
        s8 text[0x4C];
        Color color;
    } stack;
    s16 temp_21;
    u32 color2;
    u32 color1;
    s32 alpha_byte;
    s32 var_20;
    u8 loop_color2;
    u8 loop_color1;
    u8 *temp_2;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;
    extern s32 func_00442088(void *, const void *, ...);
    extern s32 func_00442948(const void *);

    temp_21 = *(s16 *)(arg2 + 2);
    temp_2 = D_005E4770 + (*(s16 *)(arg2 + 0x16) * 4);
    stack.color = *(Color *)temp_2;
    alpha_byte = 255 - (arg1 & 0xFF);
    color2 = stack.color.b;
    color1 = stack.color.g;
    func_0046d4c0(0, arg3, 0x47, arg0.x, 2.0f + arg0.y,
                  alpha_byte, stack.color.r, color1, color2,
                  fparg0, 0);
    func_00442088(stack.text, &iGpffff9bec, (s16)temp_21);
    arg0.x = arg0.x + (14.0f +
        *(f32 *)(D_005E4798 + (*(s16 *)(arg2 + 0x18) * 0x10)));
    var_20 = func_00442948(stack.text) - 1;
    loop_color2 = color2;
    loop_color1 = color1;
    while (var_20 >= 0) {
        func_0046d4c0(0, arg3, stack.text[var_20] - 0x27,
                      arg0.x, arg0.y, alpha_byte,
                      stack.color.r, loop_color1, loop_color2, fparg0, 0);
        arg0.x -= 14.0f;
        var_20--;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0011", func_001130c0);
#endif
// FUN_00113280
void func_00113280(Vec2f arg0, f32 fparg0, s32 arg1, s16 arg2, s32 arg3,
                   s32 arg4)
{
    f32 scale;
    s32 flags;
    s32 mode;
    s32 id;
    s32 alpha;

    scale = fparg0;
    flags = func_00106880(arg2);
    mode = -1;
    if (flags & 0x81) {
        mode = 0x14;
        id = arg3;
    } else if (flags & 0x102) {
        mode = 0x15;
        id = arg3;
    } else if (flags & 0x204) {
        mode = 0x16;
        id = arg3;
    } else if (flags & 0x408) {
        mode = 0x17;
        id = arg3;
    } else if (flags & 0x810) {
        mode = 0x18;
        id = arg3;
    } else if (flags & 0x1020) {
        mode = 0x19;
        id = arg3;
    } else if (flags & 0x2040) {
        mode = 0x1A;
        id = arg3;
    } else if (flags & 0x4000) {
        mode = 0x1B;
        id = arg3;
    } else if (flags & 0x8000) {
        mode = 0x1C;
        id = arg3;
    } else if (flags & 0x10000) {
        mode = 0x1B;
        id = arg4;
    } else if (flags & 0x20000) {
        mode = 0x1C;
        id = arg4;
    } else if (flags & 0x40000) {
        mode = 0x1A;
        id = arg4;
    }
    if (mode != -1) {
        alpha = 0xFF;
        alpha -= ((u8 *)&arg1)[3];
        func_0046d4c0(0, id, mode, arg0.x, arg0.y,
                      alpha & 0xFF,
                      ((u8 *)&arg1)[0], ((u8 *)&arg1)[1],
                      ((u8 *)&arg1)[2], scale, 0);
    }
}
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
void func_00113610(s32 arg0, u8 *arg1)
{
    u8 sp70[0x40];
    u8 sp30[0x40];
    u8 *table;
    u8 *entry;
    s16 i;
    s16 j;
    s32 count;
    s32 index;
    u16 value;

    table = func_001094d0();
    i = 0;
    while (i < 8) {
        index = (s32)i * 0xC;
        entry = arg1 + index;
        *(s32 *)(entry + 4) = 0;
        *(s32 *)(entry + 8) = 0;
        value = *(u16 *)(table + ((s32)i * 2));
        if (value == 0) {
            break;
        }
        *(u16 *)(entry + 2) = value;
        i++;
    }
    *(s16 *)(arg1 + 0x60) = i;
    count = (s16)func_00109510(arg0, sp70, sp30);
    j = 0;
    while (j < count) {
        index = (s32)j * 0xC;
        entry = arg1 + index;
        *(s32 *)(entry + 0x68) = 0;
        *(s32 *)(entry + 0x6C) = 0;
        *(u16 *)(entry + 0x66) = *(u16 *)(sp70 + ((s32)j * 2));
        *(u16 *)(arg1 + ((s32)j * 2) + 0x1E4) = *(u16 *)(sp30 + ((s32)j * 2));
        j++;
    }
    *(s16 *)(arg1 + 0x224) = count;
}
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
        func_00113800(arg0, arg4, arg1, arg2, arg3);
        return;
    case 1:
        func_001138c0(arg0, arg4, arg1, arg2, arg3);
        return;
    case 2:
        func_00113e30(arg0, arg4, arg1, arg2, arg3);
        return;
    }
}
/* measured: declaring the f32 parameter immediately after the Vec2f aggregate
   reproduces retail's FP-first prologue save order. Probe object 184B/window
   192B; the only two fndiff residual words are zero-padding tail bytes.
   The plain-char table read preserves lb before the final f14 move with
   the shared signed-byte font API; an s8 read swaps those two words. */
// FUN_00113800
void func_00113800(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3)
{
    f32 scale;
    s32 color;
    char index;
    void *temp;

    scale = arg4;

    temp = func_00243840(*(u16 *)((u8 *)arg2 + 0xA));
    color = -0x100 | (((arg1 & 0xFF) * 0xFF) / 255U);
    index = *(char *)((s32)D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2));
    func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, index, 1, temp, 0, 0);
}
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
void func_0011fdf0(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s16 temp_17;
    s32 temp_2;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 alpha;
    s32 mode;

    temp_2 = func_0046a770(D_005E4F70);
    temp_17 = *(s16 *)(arg2 + 4);
    if (temp_2 == 0) {
        temp_2 = arg1 & 0xFF;
        func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, arg4,
                      temp_2 | -0x100, 0, 4,
                      (const char *)func_0010d620(*(s16 *)arg2), 0, 0);
        return;
    }
    if (p4_0011_signext16(temp_17) == -1) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    if (func_00106c30(temp_17, *(s16 *)arg2) == 0) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    mode = func_00106c80(temp_17);
    switch (mode) {
    case 0:
        temp_20 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_20 == (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_2 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_17_2 >= (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 1:
        temp_20_2 = func_00106940(temp_17) & 0xFFFF;
        if (temp_20_2 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_3 = func_00106940(temp_17) & 0xFFFF;
        if (temp_17_3 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 2:
        temp_20_3 = func_00106970(temp_17) & 0xFFFF;
        if (temp_20_3 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_4 = func_00106970(temp_17) & 0xFFFF;
        if (temp_17_4 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            func_0046d3b0(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 3:
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        func_0046d3b0(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
}
