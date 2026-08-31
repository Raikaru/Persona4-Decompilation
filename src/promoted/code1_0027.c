#include "include_asm.h"
#include "type.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void func_0046a340(s32 arg0);
extern void func_0027a370();
extern void func_0027a400();

extern s32 func_002746a0(void);
extern void func_002e0f20(void);
extern s32 func_00277840();
extern void func_00273f70(u8 *arg0);
extern void func_00273cc0(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void func_00269a90(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 func_0027bf10(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00107930(s64 arg0);
extern u8 *func_00246c20(s32 arg0);
extern s32 func_00108e10(void);
extern u8 *func_00246830(s32 arg0);
static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}
extern void func_0026bc10(s32 arg0, s32 arg1);
extern s32 func_00110d60(s16 arg0);
extern s64 func_002e0da0(s64 arg0, s32 arg1, s64 arg2);
extern void func_002e0f90(void);

extern u16 D_008817E8[];
extern u8 *func_00276290();
extern u8 *func_002762f0();
extern void func_0027b5a0(s32 arg0);
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern void func_0027a780(u8 *arg0);
extern void func_0027a970(u8 *arg0);
extern void func_0027ac50(u8 *arg0);
extern void func_0027b230(u8 *arg0);
extern void func_0027b5d0(s32 arg0);
extern s32 func_0027bd40(s32 arg0);
extern s32 func_0027bda0(s32 arg0);
extern s32 func_0027be00(s32 arg0);
extern s64 func_001060b0(void);
extern void func_001104d0(s16 year, s32 *month, s32 *day);
extern s32 func_00442088(void *arg0, const void *arg1, s32 arg2);
extern u8 iGpffffa738;
extern s32 func_001105b0(s16 arg0);
extern void func_00275980(void *arg0, void *arg1, s32 arg2);
extern s8 D_0063BAB0[];
extern s32 func_00108e10(void);
extern s32 func_00278110(void);
extern void func_00278a70(s32 arg0);
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);



// FUN_00270100
s32 func_00270100(s32 arg0, u8 *arg1)
{
    u32 flags;
    s64 key_0;
    s16 key_state;
    s64 key_a;

    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        high = ((u8 *)base)[7];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_0 = (s64)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
    }
    flags = 0;
    if (func_002746a0() != 0) {
        return 0;
    }
    if (key_0 == 0) {
        flags |= 0x100U;
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        high = ((u8 *)base)[5];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_state = (s16)(((var & 0xFF) << 8) |
                          (low & 0xFF));
    }
    if (key_state == -1) {
        if ((func_00110d60((s16)func_001060b0()) & 1) != 0) {
            if ((func_00110d60((s16)func_001060b0()) & 2) != 0) {
                key_state = 4;
            } else {
                key_state = 3;
            }
        } else if ((func_00110d60((s16)func_001060b0()) & 2) != 0) {
            key_state = 2;
        } else {
            key_state = 1;
        }
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        high = ((u8 *)base)[1];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_a = (s64)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 low;
        u8 high;
        s32 var;
        s32 key_b;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        high = ((u8 *)base)[3];
        if (high == 0xFF) {
            var = 0;
        } else {
            var = (high - 1) & 0xFF;
        }
        key_b = (s32)(s16)(((var & 0xFF) << 8) |
                           (low & 0xFF));
        func_002e0da0(
            key_state |
            (((s64)((((s32)(s16)key_a) & 0xFF) << 0x10)) |
             ((key_b & 0xFF) << 8)),
            flags | 0x200,
            key_a);
    }
    func_002e0f90();
    return 0;
}
// FUN_00270390
s32 func_00270390(void)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_002e0f20();
    return 0;
}

/* measured: opt_propagation off probe for 002703d0 register setup. */
#pragma opt_propagation off
// FUN_002703D0
s32 func_002703d0(s32 arg0, u8 *arg1)
{
    u16 temp_16;
    s32 temp_4;

    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3_2;
        s32 low;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        temp_3_2 = ((u8 *)base)[1];
        if (temp_3_2 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3_2 - 1) & 0xFF;
        }
        temp_16 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                             (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2_2;
        u8 temp_3_4;
        s32 low;
        s32 key_2;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        temp_3_4 = ((u8 *)base)[3];
        if (temp_3_4 == 0xFF) {
            var_2_2 = 0;
        } else {
            var_2_2 = (temp_3_4 - 1) & 0xFF;
        }
        key_2 = (s32)(s16)(((var_2_2 & 0xFF) << 8) |
                           (low & 0xFF));
        temp_4 = key_2 & 0xFF;
    }
    if (func_002746a0() != 0) {
        return 0;
    }
    func_0026bc10(
        (((temp_16 & 0xFFFF) & 0x3FF) | 0xC00) & 0xFFFF,
        temp_4);
    return 0;
}
/* measured: closes opt_propagation off probe for 002703d0. */
#pragma opt_propagation on
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
#pragma opt_rebuildconditionals off
// FUN_002704F0
s32 func_002704f0(s32 arg0, u8 *arg1)
{
    s32 key_0;
    struct code1_record_view {
        u8 pad0[0x10];
        s32 offset;
        u8 pad14[4];
        u8 *base;
    };
    s16 key_1;
    s16 key_2;
    s16 key_3;
    s16 key_4;
    if (func_002746a0() != 0) {
        return 0;
    }

    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (((u8 *)base)[0] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[1];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_0 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[2] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[3];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_1 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = ((struct code1_record_view *)arg1)->base;
        offset = ((struct code1_record_view *)arg1)->offset;
        base += offset;
        low = (((u8 *)base)[4] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[5];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_2 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((const u8 *)arg1 + 0x18);
        offset = *(s32 *)((const u8 *)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[6] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[7];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_3 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 var_2;
        u8 temp_3;
        s32 low;
        base = *(u8 **)((u8 *)(u32)arg1 + 0x18);
        offset = *(s32 *)((u8 *)(u32)arg1 + 0x10);
        base += offset;
        low = (((u8 *)base)[8] - 1) & 0xFF;
        temp_3 = ((u8 *)base)[9];
        if (temp_3 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3 - 1) & 0xFF;
        }
        key_4 = (s32)(s16)(((var_2 & 0xFF) << 8) |
                           (low & 0xFF));
    }

    func_00269a90(key_0 & 0xFFFF, key_1, key_2, key_3, key_4);
    return 0;
}
/* measured: closes opt_rebuildconditionals off for 002704f0. */
#pragma opt_rebuildconditionals on
// FUN_002706F0
s32 func_002706f0(u8 *arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00273f70(arg1);
    func_00273cc0(NULL, arg1);
    return 0;
}



// FUN_00270750
s32 func_00270750(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off probe for 00270780 family add */
#pragma opt_propagation off
// FUN_00270780
s32 func_00270780(s32 arg0, u8 *arg1) {
    u8 sp30[0x20];
    s32 temp_17;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u32 low;
    s32 key;
    u32 base;
    u32 offset;

    base = *(u32 *)(arg1 + 0x18);
    offset = *(u32 *)(arg1 + 0x10);
    temp_3 = (u8 *)add_retail_ptr(offset, base);
    low = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    key = ((var_2 & 0xFF) << 8) | (low & 0xFF);
    temp_17 = func_00107930((s16)key);
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00273f70(arg1);
    func_00275980(func_00246c20(temp_17 & 0xFFFF), sp30, 0x20);
    func_00273cc0(sp30, arg1);
    return 0;
}
/* measured: close opt_propagation off probe for 00270780 family add */
#pragma opt_propagation on
// FUN_00270870
s32 func_00270870(s32 arg0, u8 *arg1)
{
    s32 sp2C = 0;
    s32 sp28 = 0;
    u8 sp20[8];

    if (func_002746a0() != 0)
        return 0;
    func_001104d0((s16)func_001060b0(), &sp2C, &sp28);
    func_00442088(sp20, &iGpffffa738, sp2C);
    func_00273f70(arg1);
    func_00273cc0(sp20, arg1);
    return 0;
}
// FUN_00270910
s32 func_00270910(s32 arg0, u8 *arg1)
{
    s32 sp2C = 0;
    s32 sp28 = 0;
    u8 sp20[8];

    if (func_002746a0() != 0)
        return 0;
    func_001104d0((s16)func_001060b0(), &sp2C, &sp28);
    func_00442088(sp20, &iGpffffa738, sp28);
    func_00273f70(arg1);
    func_00273cc0(sp20, arg1);
    return 0;
}
// FUN_002709B0
s32 func_002709b0(s32 arg0, u8 *arg1)
{
    struct {
        u8 sp20[0x20];
        s8 sp40[0x20];
        u8 pad[0x20];
    } work;
    s8 *src;
    s8 *dst;
    s32 count;
    s8 temp0;
    s8 temp1;

    src = D_0063BAB0;
    dst = work.sp40;
    count = 0x1C;
    do
    {
        temp0 = src[0];
        temp1 = src[1];
        src += 2;
        count -= 1;
        dst[0] = temp0;
        dst[1] = temp1;
        dst += 2;
    } while (count > 0);
    if (func_002746a0() != 0)
        return 0;
    func_00275980(work.sp40 + func_001105b0((s16)func_001060b0()) * 8,
                  work.sp20, 0x20);
    func_00273f70(arg1);
    func_00273cc0(work.sp20, arg1);
    return 0;
}
/* measured: opt_propagation off probe for 00270a80 addu order */
#pragma opt_propagation off
// FUN_00270A80
s32 func_00270a80(s32 arg0, u8 *arg1) {
    u8 sp30[0x40];
    s32 temp_4;
    s32 var_2;
    s64 temp_17;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *var_2_2;
    u32 base;
    u32 offset;

    base = *(u32 *)(arg1 + 0x18);
    offset = *(u32 *)(arg1 + 0x10);
    temp_3 = (u8 *)add_retail_ptr(offset, base);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_17 = (s64)(s16)(((var_2 & 0xFF) << 8) | (temp_4 & 0xFF));
    if (func_002746a0() != 0) {
        return 0;
    }
    if (temp_17 == 0) {
        var_2_2 = func_00246830(func_00108e10() & 0xFFFF);
    } else {
        var_2_2 = func_00246830((u16)temp_17);
    }
    func_00275980(var_2_2, sp30, 0x40);
    func_00273f70(arg1);
    func_00273cc0(sp30, arg1);
    return 0;
}
/* measured: close opt_propagation off probe for 00270a80 */
#pragma opt_propagation on
// FUN_00270B80
s32 func_00270b80(s32 arg0, u8 *arg1)
{
    s64 first;
    s64 second;

    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        first = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        second = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }

    if (func_002746a0() != 0)
        return 0;
    if (first == 0) {
        first = (u16)func_00108e10();
    }
    func_00108590(first & 0xFFFF, second & 0xFFFF, -1);
    return 0;
}
// FUN_00270CA0
s32 func_00270ca0(s32 arg0, u8 *arg1)
{
    extern s32 func_001077f0(u16 arg0);
    extern s32 func_00108590(s32 arg0, s32 arg1, s32 arg2);
    s32 second;
    s32 first;
    s32 third;

    {
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)(arg1 + 0x18);
        offset = *(s32 *)(arg1 + 0x10);
        base = (u8 *)add_retail_ptr((u32)offset, (u32)base);
        low = (base[0] - 1) & 0xFF;
        high = base[1];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        first = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        s32 offset;
        u8 *base;
        s32 high_dec;
        u8 high;
        s32 low;

        base = *(u8 **)((u8 *)arg1 + 0x18);
        offset = *(s32 *)((u8 *)arg1 + 0x10);
        base += offset;
        low = (base[2] - 1) & 0xFF;
        high = base[3];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        second = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    {
        struct KeyData {
            u8 pad0[0x10];
            s32 offset;
            u8 pad1[4];
            u8 *base;
        };
        u8 *base;
        s32 offset;
        s32 high_dec;
        u8 high;
        s32 low;

        base = ((struct KeyData *)arg1)->base;
        offset = ((struct KeyData *)arg1)->offset;
        base += offset;
        low = (base[4] - 1) & 0xFF;
        high = base[5];
        if (high == 0xFF)
            high_dec = 0;
        else
            high_dec = (high - 1) & 0xFF;
        third = (s64)(s16)(((high_dec & 0xFF) << 8) | (low & 0xFF));
    }
    if (func_002746a0() != 0)
        return 0;
    if (first == 0) {
        first = (u16)func_00108e10();
    }
    if (func_001077f0((u16)first) != 0)
        func_00108590((u16)first, (u16)second, third);
    return 0;
}
// FUN_00270E30
s32 func_00270e30(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107ce0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270E90
s32 func_00270e90(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107dc0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270EF0
s32 func_00270ef0(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107f00(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270F50
s32 func_00270f50(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107fe0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_002746C0
void func_002746c0(s32 arg0, s32 arg1)
{
    D_008815B0[arg0] = arg1;
}



// FUN_002761F0
u8 *func_002761f0(s32 arg0, u8 *arg1, s32 arg2)
{
    u8 *var_2;

    var_2 = func_00276290(arg0, arg2);
    if (var_2 == NULL) {
        var_2 = func_002762f0(arg0, arg1, arg2);
        if (var_2 == NULL)
            var_2 = NULL;
    }
    return var_2;
}

// FUN_0027A400
void func_0027a400(arg0, arg1, arg2, arg3)
u8 *arg0;
s32 arg1;
s32 arg2;
s32 arg3;
{
    u8 *cur;
    u8 *list;
    s32 count;
    s32 key;
    s32 temp;

    cur = arg0;
    count = (arg2 - arg1) - 1;
    key = *(s32 *)(cur + 8);
    goto outer_check;
outer_continue:
    cur = *(u8 **)(cur + 0x24);
    if (cur == NULL)
        goto done;
outer_body:
    temp = *(s32 *)(cur + 8);
    if (key != temp)
    {
        count -= 1;
        key = temp;
        goto outer_check;
    }
    goto outer_continue;
outer_check:
    if (count > 0)
        goto outer_body;
process:
    list = *(u8 **)(cur + 0x1C);
    goto list_check;
list_body:
    *(s32 *)(list + 0x10) = arg3;
    list = *(u8 **)(list + 0x28);
list_check:
    if (list != NULL)
        goto list_body;
    cur = *(u8 **)(cur + 0x24);
    if (cur == NULL)
        goto done;
    temp = *(s32 *)(cur + 8);
    if (key == temp)
        goto process;
done:
    return;
}
// FUN_0027A490
void func_0027a490(void)
{
    func_0027a370();
}

// FUN_0027A4B0
void func_0027a4b0(void)
{
    func_0027a400();
}

// FUN_0027A5E0
void func_0027a5e0(s32 *arg0, s32 arg1)
{
    memset(arg0, 0, 0x1C);
    *arg0 = func_0027bf10(arg1);
}



// FUN_0027A630
void func_0027a630(u8 *arg0)
{
    *(s32 *)arg0 = 0;
    *(u16 *)(arg0 + 4) = 0xFFFF;
}
// FUN_0027A650
void func_0027a650(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 9) = 0;
    *(s16 *)(arg0 + 0xE) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s8 *)(arg0 + 0xA) = 0;
    *(s8 *)(arg0 + 0xB) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0xFF;
}



// FUN_0027A690
void func_0027a690(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xC) = 0;
    *(s16 *)(arg0 + 0xE) = -1;
    *(s16 *)(arg0 + 0x10) = -1;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s16 *)(arg0 + 0x14) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
// FUN_0027A6F0
void func_0027a6f0(s32 *arg0)
{
    *arg0 &= ~0xF00;
}
// FUN_0027A710
void func_0027a710(s32 arg0) {
    s32 i;
    s32 *p;
    s32 v;

    for (i = 0; i < 0x20; i++) {
        p = (s32 *)(arg0 + i * 4);
        v = *p;
        if (v != 0) {
            func_0046a340(v);
            *p = 0;
        }
    }
}

// FUN_0027A780
void func_0027a780(u8 *arg0)
{
    extern s32 func_0027b980(s32 arg0);
    extern s32 func_0027b9e0(s32 arg0);
    extern s32 func_0027ba40(s32 arg0);
    extern s32 func_0027bc20(s32 arg0);
    extern s32 func_0027bc80(s32 arg0);
    extern s32 func_0027bce0(s32 arg0);
    extern void func_002748e0(s32 arg0, s32 arg1, s32 arg2);
    s32 value;
    u8 *node;

    node = D_008817EC[0];
    goto node_check;
node_body:
    if (*(u8 **)(node + 0xC) == arg0) {
        value = *(s32 *)(node + 8);
        goto node_done;
    }
    node = *(u8 **)(node + 4);
node_check:
    if (node != NULL)
        goto node_body;
    value = -1;
node_done:
    switch (*(s32 *)arg0 & 0x300)
    {
    case 0x100:
        if (func_0027b980(value) != 0) {
            s16 index;
            s32 count;
            u8 *table;
            s32 selected;

            index = *(s16 *)(arg0 + 0x2C);
            table = *(u8 **)(arg0 + 0x1C);
            count = *(s16 *)(table + 0x18);
            if (index < 0 || index >= count)
                selected = 0;
            else
                selected = *(s32 *)((u8 *)add_retail_ptr((u32)(index * 4), (u32)table) + 0x1C);
            func_002748e0(selected, 1, 0);
            *(s32 *)arg0 = *(s32 *)arg0 & ~0x307;
            *(s32 *)arg0 |= 0x203;
        }
        break;
    case 0x200:
        func_0027b9e0(value);
        break;
    case 0x300:
        if (func_0027ba40(value) != 0)
            *(s32 *)arg0 &= ~0x300;
        break;
    }
    switch (*(s32 *)arg0 & 0xC00)
    {
    case 0x400:
        if (func_0027bc20(value) != 0) {
            *(s32 *)arg0 = *(s32 *)arg0 & ~0xC07;
            *(s32 *)arg0 |= 0x803;
        }
        break;
    case 0x800:
        func_0027bc80(value);
        break;
    case 0xC00:
        if (func_0027bce0(value) != 0)
            *(s32 *)arg0 &= ~0xC00;
        break;
    }
}
// FUN_0027A970
void func_0027a970(u8 *arg0)
{
    extern void func_002727f0(u8 *arg0);
    extern s32 func_002734b0(u8 *arg0);
    extern void func_002738a0(s32 arg0);
    extern void func_002746c0(s32 arg0, s32 arg1);
    extern void func_00279780(u8 *arg0);
    extern void func_00440b68(void *arg0);
    extern void func_0045a9a0(s32 arg0, s32 arg1);
    extern u16 D_008C024C[];
    extern s32 iGpffffb4b0;
    extern u8 D_0063BF40[];
    u8 *state;
    s32 index;
    u8 *iter;
    u32 count;

    state = arg0 + 0x1C;
    if (*(s8 *)(arg0 + 0x24) == 1) {
        if ((*(s32 *)arg0 & 7) == 4) {
            *(s32 *)(state + 0x14) += 1;
            if (*(s32 *)arg0 & 0x800000) {
                *(s8 *)(state + 8) = -1;
                return;
            }
            if ((*(s32 *)arg0 & 0x100000) == 0 &&
                (*(s16 *)(state + 0x18) == 0 ||
                 *(s16 *)(state + 0x18) == 3)) {
                *(s16 *)(state + 0x18) = 1;
            }
            if ((*(s32 *)arg0 & 0x4000000) == 0) {
                if ((D_008C024E[0] & 0x40) != 0 ||
                    (D_008C024E[0] & 0x20) != 0) {
                    goto do_action;
                }
                if ((D_008C024C[0] & 0x10) == 0)
                    goto state_check;
                count = *(u32 *)(state + 0x14);
                if (count > 4U) {
                    if ((iGpffffb4b0 & 1) == 0)
                        goto do_action;
                } else {
                    goto state_check;
                }
            }
state_check:
            if (*(u8 *)(state + 9) != 0) {
                if ((*(s32 *)arg0 & 0x8000000) == 0)
                    return;
                if (func_002734b0(*(u8 **)(state + 4)) == 0)
                    return;
            }
do_action:
                func_00440b68(D_0063BF40);
                *(s16 *)(state + 0x18) = 3;
                *(s16 *)(state + 0x10) += 1;
                func_0045a9a0(1, 0);
                if (*(s16 *)(state + 0x10) >= *(s16 *)(state + 0x12)) {
                    *(s8 *)(state + 8) = -1;
                    return;
                }
                index = 0;
                while (index < 32) {
                    func_002746c0(index,
                        *(s32 *)(arg0 + index * 4 + 0x94));
                    index += 1;
                }
                if (*(s32 *)(arg0 + 8) != 0)
                    func_002738a0(*(s32 *)(arg0 + 8));
                func_00279780(arg0);
                *(s32 *)arg0 = *(s32 *)arg0 & ~7;
                *(s32 *)arg0 |= 3;
        } else {
            if ((*(s32 *)arg0 & 0x4000000) == 0 &&
                ((D_008C024E[0] & 0x40) != 0 ||
                 (D_008C024E[0] & 0x20) != 0 ||
                 ((D_008C024C[0] & 0x10) != 0 &&
                  (iGpffffb4b0 & 1) == 0)) &&
                (*(s32 *)arg0 & 0x400000) == 0 &&
                (*(s32 *)arg0 & 0x1000000) == 0) {
                iter = *(u8 **)(state + 4);
                while (iter != NULL) {
                    func_002727f0(iter);
                    iter = *(u8 **)(iter + 0x24);
                }
                if (*(u8 **)(arg0 + 0x14) != NULL)
                    func_002727f0(*(u8 **)(arg0 + 0x14));
            }
            *(s32 *)arg0 = *(s32 *)arg0 & 0xFEFFFFFF;
        }
    }
}
// FUN_0027AC50
void func_0027ac50(u8 *arg0)
{
    extern s32 func_00271b70(s32 arg0);
    extern void func_002748e0(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_0027a150();
    extern s32 func_0027ae90(u8 *arg0);
    u8 *state;
    s32 flags;
    s32 index;
    s32 count;
    s32 *cursor;
    s32 i;

    state = arg0 + 0x3C;
    flags = *(s32 *)arg0;
    switch (*(s16 *)(arg0 + 0x48))
    {
    case 1:
        switch (*(s32 *)(arg0 + 0x10))
        {
        case 0:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = flags & ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x18;
                *(s32 *)arg0 = current;
                *(s16 *)(state + 0xC) = 2;
            }
            break;
        case 1:
        case 2:
        default:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = *(s32 *)(u32)arg0;
                current &= ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x18;
                *(s32 *)arg0 = current;
                *(s16 *)(state + 0xC) = 2;
            }
            break;
        }
        /* fall through */
    case 2:
        if ((flags & 0x38) == 0x20 && func_0027ae90(arg0) == 1) {
            s16 call_arg1;
            s16 call_arg2;
            s32 call_arg0;
            u8 *entry;

            call_arg1 = *(s16 *)(state + 0xE);
            call_arg2 = *(s16 *)(state + 0x12);
            call_arg0 = *(s32 *)(state + 4);
            *(s32 *)(state + 4) = func_0027a150(
                call_arg0, call_arg1, call_arg2);
            entry = *(u8 **)(arg0 + 4);
            entry = *(u8 **)((u8 *)add_retail_ptr(
                (u32)(*(s32 *)state * 8), (u32)entry) + 0x24);
            index = *(s16 *)(state + 0xE);
            count = *(s16 *)(entry + 0x1A);
            cursor = (s32 *)(entry + 0x20);
            i = 0;
            while (i < count) {
                if (i == index)
                    func_002748e0(*cursor, 3, 0);
                i += 1;
                cursor += 1;
            }
            if ((flags & 0xC00) == 0x800) {
                s32 current;

                current = *(s32 *)arg0;
                current &= ~0xC00;
                *(s32 *)arg0 = current;
                current |= 0xC00;
                *(s32 *)arg0 = current;
            }
            *(s16 *)(state + 0x16) = 0;
            {
                s32 current;

                current = *(s32 *)arg0;
                current &= ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x28;
                *(s32 *)arg0 = current;
            }
            *(s16 *)(state + 0x14) = 0x80;
            *(s16 *)(state + 0xC) = 3;
        }
        break;
    case 3:
        if ((flags & 0xC00) == 0) {
            if (*(s32 *)(state + 4) != 0) {
                func_00271b70(*(s32 *)(state + 4));
                *(s32 *)(state + 4) = 0;
            }
            *(s16 *)(state + 0xC) = -1;
        }
        break;
    }
}
// FUN_0027AE90
s32 func_0027ae90(u8 *arg0)
{
    extern void func_0027b100(u8 *arg0, s32 arg1);
    extern u16 D_008C0252[];
    extern u16 D_008C0274[];
    extern u16 D_008C027A[];
    extern s32 func_0027b1c0(u8 *arg0);
    u8 *state;
    s32 result;

    state = arg0 + 0x3C;
    result = 0;
    if ((D_008C0252[0] & 0x1000) || (D_008C027A[0] & 0x1000)) {
        if (*(s16 *)(state + 0xE) == 0) {
            if ((D_008C024E[0] & 0x1000) || (D_008C0274[0] & 0x1000))
                result = -1;
        } else {
            result = -1;
        }
    } else if ((D_008C0252[0] & 0x4000) || (D_008C027A[0] & 0x4000)) {
        if (*(s16 *)(state + 0xE) == *(s16 *)(state + 0x12) - 1) {
            if ((D_008C024E[0] & 0x4000) || (D_008C0274[0] & 0x4000))
                result = 1;
        } else {
            result = 1;
        }
    }
    if (result != 0) {
        func_0027b100(state, result);
        return 0;
    }
    if (D_008C024E[0] & 0x40) {
        s32 remaining;
        u32 bits;
        s32 i;

        func_0045af60(0, 0, 0, 1);
        bits = *(u32 *)(state + 8);
        remaining = *(s16 *)(state + 0xE);
        i = 0;
        while (i < 0x20) {
            if ((bits & 1) == 0) {
                remaining -= 1;
                if (remaining < 0)
                    break;
            }
            i += 1;
            bits >>= 1;
        }
        *(s16 *)(state + 0x10) = (s16)i;
        return 1;
    }
    if (*(s16 *)(state + 0x16) > 0) {
        s32 selected;
        s32 remaining;
        u32 bits;
        s32 i;
        s32 count;

        selected = func_0027b1c0(state);
        if (selected >= 0) {
            func_0045af60(0, 0, 0, 2);
            bits = *(u32 *)(state + 8);
            remaining = selected;
            count = 0;
            i = 0;
            while (i < 0x20) {
                remaining -= 1;
                if (remaining < 0)
                    break;
                if ((bits & 1) == 0)
                    count += 1;
                i += 1;
                bits >>= 1;
            }
            if (bits & 1)
                count = -1;
            if (count != -1 && count != *(s16 *)(state + 0xE)) {
                *(s16 *)(state + 0xE) = (s16)count;
                *(s16 *)(state + 0x10) = (s16)selected;
            }
            return 1;
        }
    }
    return 0;
}
// FUN_0027B100
void func_0027b100(u8 *arg0, s32 arg1) {
    s32 temp_2;
    s32 var_6;
    u32 var_5;
    s32 var_3;

    temp_2 = (s32)*(s16 *)(arg0 + 0xE);
    if (arg1 < 0) {
        var_6 = temp_2 - 1;
        if (var_6 < 0) {
            var_6 = (s32)*(s16 *)(arg0 + 0x12) - 1;
        }
    } else {
        var_6 = temp_2 + 1;
        if (var_6 >= (s32)*(s16 *)(arg0 + 0x12)) {
            var_6 = 0;
        }
    }
    *(s16 *)(arg0 + 0xE) = (s16)var_6;
    var_5 = *(u32 *)(arg0 + 8);
    var_3 = 0;
    goto loop_test;
loop_body:
    if ((var_5 & 1) == 0) {
        var_6 -= 1;
        if (var_6 < 0) {
            goto loop_exit;
        }
    }
    var_3 += 1;
    var_5 >>= 1;
loop_test:
    if (var_3 < 0x20) {
        goto loop_body;
    }
loop_exit:
    *(s16 *)(arg0 + 0x10) = (s16)var_3;
    func_0045af60(0, 0, 0, 0);
}
// FUN_0027B1C0
/* measured: opt_loop_invariants hoists mask/count/const-1 into preheader */
#pragma opt_loop_invariants on
s32 func_0027b1c0(s16 *arg0)
{
    s32 i = 0;
    u16 mask;
    s32 count;
    s32 bit;
    s16 *p;

    mask = D_008C024E[0];
    count = *(s16 *)((u8 *)arg0 + 0x16);
    for (; i < count; i++) {
        p = (s16 *)((u8 *)arg0 + i * 4 + 0x18);
        bit = *p;
        if ((1 << bit) & mask) {
            return *(s16 *)((u8 *)p + 2);
        }
    }
    return -1;
}
/* measured: opt_loop_invariants off */
#pragma opt_loop_invariants off

// FUN_0027B230
void func_0027b230(u8 *arg0)
{
    s16 *state;
    u8 *node;
    s32 value;

    state = (s16 *)(arg0 + 0x34);
    node = D_008817EC[0];
    goto node_check;
node_body:
    if (*(u8 **)(node + 0xC) == arg0)
    {
        value = *(s32 *)(node + 8);
        goto node_done;
    }
    node = *(u8 **)(node + 4);
node_check:
    if (node != NULL)
        goto node_body;
    value = -1;
node_done:
    switch (*state)
    {
    case 0:
        break;
    case 1:
        if (func_0027bd40(value) != 0)
            *state = 2;
        break;
    case 2:
        func_0027bda0(value);
        break;
    case 3:
        if (func_0027be00(value) != 0)
            *state = 0;
        break;
    }
}
// FUN_0027B310
void func_0027b310(u8 *arg0)
{
    extern s32 func_00273110(s32 arg0);
    extern s32 func_00273140(s32 arg0, s32 arg1);
    extern void func_0027b4c0(void);
    extern s32 func_0027b910(s32 arg0);
    s32 flags;
    u32 mask;
    s32 value;
    u8 *node;

    flags = *(s32 *)arg0;
    D_008817E8[0] &= 0xFFFD;
    func_0027b4c0();
    node = D_008817EC[0];
    goto node_check;
node_body:
    if (*(u8 **)(node + 0xC) == arg0) {
        value = *(s32 *)(node + 8);
        goto node_done;
    }
    node = *(u8 **)(node + 4);
node_check:
    if (node != NULL)
        goto node_body;
    value = -1;
node_done:
    func_0027b910(value);

    {
        s32 first;

        first = *(s32 *)(arg0 + 0x14);
        if ((mask = flags & 0x20000) == 0 &&
            (u32)(flags & 7) >= 3U &&
            (flags & 0x10000) == 0 &&
            first != 0) {
            func_00273110(first);
        }
    }
    {
        s32 second;

        second = *(s32 *)(arg0 + 0x20);
        if (mask == 0 &&
            (u32)(flags & 7) >= 3U &&
            func_00273110(second) > 0) {
            s32 current;

            current = *(s32 *)arg0;
            if ((current & 7) != 4) {
                current &= ~7;
                *(s32 *)arg0 = current;
                current |= 4;
                *(s32 *)arg0 = current;
                *(s32 *)(arg0 + 0x30) = 0;
            }
        }
    }
    {
        s32 third;

        third = *(s32 *)(arg0 + 0x40);
        if ((flags & 0x40000) == 0) {
            mask = flags & 0x38;
            if (mask >= 0x18U &&
                func_00273140(third, 1) > 0 &&
                mask == 0x18U) {
                u8 *state;
                s32 current;

                state = arg0 + 0x3C;
                if (*(s16 *)(arg0 + 0x4A) == -1) {
                    *(s16 *)(state + 0xE) = 0;
                    *(s16 *)(state + 0x10) = 0;
                }
                current = *(s32 *)arg0;
                current &= ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x20;
                *(s32 *)arg0 = current;
            }
        }
    }
}
// FUN_0027B4C0
void func_0027b4c0(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

// FUN_0027B500
s32 func_0027b500(s32 arg0)
{
    u8 *node;
    u8 *temp;

    node = D_008817EC[0];
    while (node != NULL)
    {
        temp = *(u8 **)(node + 0xC);
        func_0027a780(temp);
        func_0027a970(temp);
        func_0027ac50(temp);
        func_0027b230(temp);
        node = *(u8 **)(node + 4);
    }
    func_0027b5d0(arg0);
    return 0;
}
// FUN_0027B5D0
void func_0027b5d0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32))(temp_2 + 8) = func_0027b5a0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0(D_007964C0, temp_2);
}
// FUN_0027B690
void func_0027b690(void)
{
    u8 *temp_16;
    u8 *var_3;

    var_3 = *(u8 **)DAT_008817EC_abs;
    while (var_3 != NULL) {
        temp_16 = *(u8 **)(var_3 + 4);
        func_00278a70(*(s32 *)(var_3 + 8));
        var_3 = temp_16;
    }
}
// FUN_0027B7C0
s32 func_0027b7c0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    *(s32 *)(func_00277840() + 0x14) = 0;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0);
    }
    return 1;
}
// FUN_0027B830
s32 func_0027b830(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 1;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 1);
    }
    return 1;
}
// FUN_0027B8A0
s32 func_0027b8a0(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 2;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 2);
    }
    return 1;
}
// FUN_0027B910
s32 func_0027b910(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 3;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 3);
    }
    return 1;
}
// FUN_0027B980
s32 func_0027b980(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 4);
    }
    return 1;
}
// FUN_0027B9E0
s32 func_0027b9e0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 5);
    }
    return 1;
}
// FUN_0027BA40
s32 func_0027ba40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 6);
    }
    return 1;
}
// FUN_0027BAA0
s32 func_0027baa0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 7);
    }
    return 1;
}
// FUN_0027BB00
s32 func_0027bb00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 8);
    }
    return 1;
}
// FUN_0027BB60
s32 func_0027bb60(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 9);
    }
    return 1;
}
// FUN_0027BBC0
s32 func_0027bbc0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xA);
    }
    return 1;
}
// FUN_0027BC20
s32 func_0027bc20(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xB);
    }
    return 1;
}
// FUN_0027BC80
s32 func_0027bc80(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xC);
    }
    return 1;
}
// FUN_0027BCE0
s32 func_0027bce0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xD);
    }
    return 1;
}
// FUN_0027BD40
s32 func_0027bd40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x10);
    }
    return 1;
}
// FUN_0027BDA0
s32 func_0027bda0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x11);
    }
    return 1;
}
// FUN_0027BE00
s32 func_0027be00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x12);
    }
    return 1;
}
// FUN_0027BEC0
s32 func_0027bec0(void)
{
    s32 temp_2;

    temp_2 = func_00278110();
    if (!(temp_2 & 0x80000) || ((temp_2 & 0x300) < 0x100)) {
        return 1;
    }
    return 0;
}
// FUN_0027BF10
s32 func_0027bf10(s32 arg0)
{
    return D_0063BF80[arg0];
}
// FUN_0027BF30
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027bf30);
