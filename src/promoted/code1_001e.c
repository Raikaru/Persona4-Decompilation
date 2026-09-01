#include "include_asm.h"
#include "type.h"
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
extern f32 sqrtf(f32 arg0);
extern u8 *func_001b0cc0();
extern void *D_00609850[];
extern s32 func_00231f80();
extern s64 func_0029cc00();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 func_0029cc00_s32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();
extern s32 func_00232290();
extern s32 datCalcGetSp();

extern s64 func_0023d8e0();
extern s32 func_0023e130();
extern u8 *func_0023e140();
extern s32 func_00242800(s32 arg0, s32 arg1);
extern u8 *func_001b1510(void);
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3bc;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void func_00213b80(s32 arg0);
extern void func_00213b50(s32 arg0);
extern s32 func_001eb860(void);
extern void func_00212240();
extern void func_00212210();
extern void func_0045af60();
extern s32 func_001ef9a0(void);
extern s32 D_00724504;
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern void func_001a03b0(s32 arg0);
extern u8 *func_001d3700(s32 arg0, s32 arg1);
extern u8 *func_001bc920(s32 arg0, s32 arg1);
extern s32 func_001dbba0();
extern void func_001da2f0();
extern u32 func_00231d70(u32 arg0);
extern u8 *func_001d9280();
extern u8 *func_001d8c00();
extern u8 *func_001de370();
extern void func_001db580();
extern void func_001db8d0();
extern s32 func_001d7f10(u8 *arg0, s32 arg1, u16 arg2, s32 arg3);
extern s32 func_001dd570();
extern s32 func_001de000();
extern s32 func_001d9390();
extern s32 func_001dbb90(void);
extern void func_001da230();
extern void func_001da270();
extern void func_001da2b0();
extern void func_001db900();


extern void func_00194590(u8 *arg0, s32 arg1);
extern u8 *func_001f60c0(void);
extern u8 *func_001f6030(s32 arg0, s64 arg1);
extern s32 func_00193b70(s64 arg0, s64 arg1);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];


extern u8 *func_001b1560(void);
extern void func_001eb410(u8 *arg0);
extern u32 func_00231d70(u32 arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);



extern void func_0019ef30(u8 *arg0, u64 arg1);
extern void func_001de640(u8 *arg0, u8 *arg1, u16 arg2);
extern s32 func_001de800(u8 *arg0);
extern u8 *func_001dea90(u8 *arg0, u32 arg1);
extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 func_0029cd50(s32 arg0);
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 *func_001bcb50(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7);
extern u8 *func_002306d0(void);
extern u8 *func_001f81f0(s32 arg0, void *arg1);
extern void func_00442088(void *arg0, void *arg1, s64 arg2);
extern u8 D_00609E40[];
extern s32 func_00232710(s32 arg0, s32 arg1);
extern s32 func_00232c70(s32 arg0, s32 arg1);
extern s32 func_00231ed0(s32 arg0);
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_0019ef90(s32 arg0, s32 arg1);
extern s32 func_001b0c80(s32 arg0);
extern void func_001fae60(void (*arg0)(void), void (*arg1)(void), s32 arg2);
extern void func_0022b120(void);
extern void func_0022b870(void);
extern void func_001debb0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 func_00452490(s32 arg0);
extern u8 *func_00194470(s32 arg0, s32 arg1);
extern s32 func_0022ced0(s32 arg0);
extern s32 func_0029de20(s32 arg0, s32 arg1);
extern s32 func_001eba20(u8 *arg0);
extern u8 *iGpffffb428;
extern s32 func_00107ac0(s32 arg0);
extern void func_00106550(s32 arg0, s32 arg1);
extern s32 func_00243e30(s32 arg0);
extern s32 func_00247cb0(s16 arg0);
extern u8 *iGpffffb42c;
// FUN_001E6B90
s32 func_001e6b90(void) {
    u32 a = func_0029cc00_s32(0);
    u32 b = func_0029cc00_s32(1);
    u8 *p = func_001b0cc0(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x48000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x48000000) & 0xFFFFFF;
    s32 x;

    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    func_0029cf50(x != 0);
    return 1;
}
// FUN_001E6C60
s32 func_001e6c60(void) {
    u8 *temp_2;
    u32 index;

    temp_2 = func_0029d050();
    if ((func_001d7f10(temp_2, 0, *(u16 *)(temp_2 + 0x6E), 0) & 0xFFFF) == 0) {
        index = func_0029cc00_s32(0);
        *(u8 **)(temp_2 + 0x38) = func_001b0cc0(index & 0xFFFFFFF);
        *(s16 *)(temp_2 + 0x6A) = 1;
    } else if (((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0) == 0) {
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    }
    return 1;
}
// FUN_001E6D20
s32 func_001e6d20(void) {
    s32 first;
    s32 second;
    s32 kind;
    u8 *result;

    first = func_0029cc00_s32(0) & 0xFFFF;
    second = func_0029cc00_s32(1) & 0xFFFF;
    result = 0;
    kind = first & 0xFFFF;
    switch (kind) {
    case 0:
        result = func_001d9280(second, 1, 0);
        break;
    case 1:
        result = func_001d9280(second, 2, 0x80000);
        break;
    }
    func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
    return 1;
}

// FUN_001E6DC0
s32 func_001e6dc0(void) {
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 1 &&
                func_002428f0(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = func_00231ed0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    func_0029cf50(*(s32 *)(best + 8) | 0x80000000);
    return 1;
}
// FUN_001E6EA0
s32 func_001e6ea0(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E6FA0
s32 func_001e6fa0(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2E, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7080
s32 func_001e7080(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2F, 0, &func_001da2f0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7160
s32 func_001e7160(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7240
s32 func_001e7240(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2C, 0, &func_001db580) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7320
s32 func_001e7320(void)
{
    int count;
    u8 *work;
    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2D, 0, &func_001db580) == 1)
    {
        count = *(u16 *)(work + 0x6A);
        if (count == 1)
        {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        }
        else
        {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    }
    else
    {
        func_0029cf50(-1);
    }
    return 1;
}
/* measured: object 264B vs window 272B, normalized_diff 10; remaining differences are register colouring. Committed at nd 10. */
// FUN_001E7400
s32 func_001e7400(void) {
    extern s32 func_001d9390();
    extern u32 func_00231d70(u32 arg0);
    extern s32 func_0029cc00(s32 arg0);
    extern void func_0029cf50(s32 arg0);
    extern u8 *func_0029d050(void);
    extern void func_001db8d0();
    u8 *formation;
    u16 count;
    int selected;
    u32 unit;
    u32 selector;
    u16 index;
    int candidates[12];

    unit = (u32)func_0029d050();
    selector = (u32)func_0029cc00(0);
    count = func_001d9390(unit, selector, 0x80000, 1, 1,
                          &func_001db8d0, candidates);
    if (count > 0) {
        index = 0;
        formation = iGpffffb3ac;
        while (index < count) {
            if (*(s32 *)(formation + 0x170) == candidates[index]) {
                break;
            }
            index++;
        }
        if (index == count) {
            selected = candidates[func_00231d70(count)];
        } else {
            selected = *(s32 *)(formation + 0x170);
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E7510
s32 func_001e7510(void) {
    extern s32 func_001d9390();
    extern s32 func_00231d70();
    extern s32 func_00231e20();
    extern s64 func_0029cc00();
    extern void func_0029cf50();
    extern u8 *func_0029d050();
    extern void func_001db8d0();
    u8 *var_19;
    s32 var_18;
    s32 temp_17;
    u8 *temp_16;
    u8 *temp_2;
    u8 *sp50[12];

    temp_16 = func_0029d050();
    temp_17 = func_001d9390(temp_16, func_0029cc00(0), 0x80000, 2, 1, &func_001db8d0, sp50) & 0xFFFF;
    if (temp_17 > 0) {
        var_19 = NULL;
        var_18 = 0;
        goto loop_test;
loop_body:
        temp_2 = (u8 *)&sp50[(u16)var_18];
        if ((func_00231e20(*(s32 *)(*(u8 **)(*(u8 **)temp_2 + 0x30) + 0xA64)) & 0xFF) > 0) {
            var_19 = *(u8 **)temp_2;
        }
        var_18 = (var_18 + 1) & 0xFFFF;
loop_test:
        if ((var_18 & 0xFFFF) < temp_17)
            goto loop_body;
        if (var_19 == NULL)
            var_19 = sp50[func_00231d70(temp_17 & 0xFFFF)];
        func_0029cf50(*(s32 *)(var_19 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
#pragma push
#pragma opt_rebuildconditionals off
static inline u16 p4_formation_get_opposing_genus(u32 unit)
{
    u32 side;
    if (*(u8 *)(*(s32 *)(unit + 0x30) + 0xA2) != 0)
        goto nonzero;
    side = 1;
    goto done;
nonzero:
    side = 0;
done:
    return side;
}
// FUN_001E7640
s32 func_001e7640(void)
{
    extern s32 func_001d7c60(u32, void *, s32, s32, s32);
    extern u8 *func_0029d050(void);
    extern u32 func_00231d70(u32);
    extern s32 func_00231e20(u8 *);
    extern s32 func_002428f0(s32, s32);
    extern void func_0029cf50(s32);
    struct {
        s32 entries[14];
        u16 count;
        u16 selected;
    } candidates;
    s32 selected[12];
    u8 *unit;
    u16 desired;
    u32 highest;
    u16 index;
    u16 selectedCount;
    s32 candidate;
    u32 value;
    u32 desiredValue;

    unit = func_0029d050();
    desired = p4_formation_get_opposing_genus((u32)unit);
    func_001d7c60((u32)unit, &candidates, 2, 0, 0);
    highest = 0;
    selectedCount = 0;
    index = 0;
    desiredValue = desired;
    while (index < candidates.count) {
        candidate = candidates.entries[index];
        if (((*(u16 *)(candidate + 0x1A) & 1) != 0) &&
            ((*(u16 *)(candidate + 0x1A) & 8) != 0) &&
            (*(u8 *)(*(s32 *)(candidate + 0x30) + 0xA2) == desiredValue) &&
            (func_002428f0(*(s32 *)(*(s32 *)(candidate + 0x30) + 0xA64), 0) == 0)) {
            value = (u32)(func_00231e20((u8 *)*(s32 *)(*(s32 *)(candidate + 0x30) + 0xA64)) & 0xFF);
            if (value == highest) {
                selected[selectedCount] = candidate;
                selectedCount++;
            } else if (highest < value) {
                highest = value;
                selected[0] = candidate;
                selectedCount = 1;
            }
        }
        index++;
    }
    if (selectedCount > 0) {
        value = func_00231d70(selectedCount);
        func_0029cf50(*(s32 *)(selected[value] + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
#pragma pop
// FUN_001E77F0
s32 func_001e77f0(void) {
    extern s32 func_00231e20();
    u8 *temp_21;
    u32 temp_2;
    u8 *temp_20;
    u8 *var_19;
    u32 var_18;
    u32 temp_17;
    u32 var_16;
    u32 var_22;

    temp_21 = func_0029d050();
    if (func_001dbba0(temp_21, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        if (*(u16 *)(temp_21 + 0x6A) == 1) {
            var_19 = *(u8 **)(temp_21 + 0x38);
        } else {
            var_19 = NULL;
            var_22 = 0;
            var_16 = 0;
            var_18 = 0;
            goto loop_test;
loop_body:
            temp_20 = *(u8 **)(temp_21 + var_18 * 4 + 0x38);
            temp_17 = func_00231e20(*(s32 *)(*(u8 **)(temp_20 + 0x30) + 0xA64)) & 0xFF;
            if (temp_17 >= var_22) {
                temp_2 = func_00231ed0(*(s32 *)(*(u8 **)(temp_20 + 0x30) + 0xA64)) & 0xFFFF;
                if (var_16 < temp_2) {
                    var_19 = temp_20;
                    var_16 = temp_2;
                }
                var_22 = temp_17;
            }
            var_18 += 1;
loop_test:
            if (var_18 < *(u16 *)(temp_21 + 0x6A))
                goto loop_body;
        }
        func_0029cf50(*(s32 *)(var_19 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return -1;
}
// FUN_001E7950
s32 func_001e7950(void) {
    extern s32 func_002326c0();
    u8 *temp_19;
    s32 var_18;
    s32 var_17;
    u16 temp_4;
    u8 *temp_16;
    u8 *sp50[12];

    temp_19 = func_0029d050();
    if (func_001dbba0(temp_19, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        var_17 = 0;
        var_18 = 0;
        goto loop_test;
loop_body:
        temp_16 = *(u8 **)(temp_19 + (u16)var_18 * 4 + 0x38);
        if (!(func_002326c0(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFFEFFFFF)) {
            sp50[var_17 & 0xFFFF] = temp_16;
            var_17 = (var_17 + 1) & 0xFFFF;
        }
        var_18 = (var_18 + 1) & 0xFFFF;
loop_test:
        if ((var_18 & 0xFFFF) < (s32)*(u16 *)(temp_19 + 0x6A))
            goto loop_body;
        temp_4 = var_17 & 0xFFFF;
        if (temp_4 == 0) {
            func_0029cf50(-1);
        } else {
            func_0029cf50(*(s32 *)(sp50[func_00231d70(temp_4)] + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return -1;
}
/* measured: object 364B vs window 368B, normalized_diff 1; the sole residual is the retail daddiu/addiu width at the count reset. Committed at nd 1. */
// FUN_001E7AB0
s32 func_001e7ab0(void) {
    extern s32 func_001dbba0();
    extern void func_001db5b0();
    extern s32 func_00231d70();
    extern s32 func_00231e20();
    extern s64 func_0029cc00();
    extern void func_0029cf50();
    extern u8 *func_0029d050();
    u8 *temp_20;
    u32 var_19;
    u32 var_18;
    s32 var_17;
    u8 *temp_16;
    u32 temp_3;
    u8 *sp60[12];
    u8 *var_2;

    temp_20 = func_0029d050();
    if (func_001dbba0(temp_20, func_0029cc00(0), 0, 0x2C, 1, &func_001db5b0) == 1) {
        if (*(u16 *)(temp_20 + 0x6A) == 1) {
            var_2 = *(u8 **)(temp_20 + 0x38);
        } else {
            var_17 = 0;
            var_18 = 0;
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_16 = *(u8 **)(temp_20 + var_19 * 4 + 0x38);
            temp_3 = (u32)(func_00231e20(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFF);
            if (temp_3 >= var_18) {
                if (temp_3 == var_18) {
                    sp60[var_17 & 0xFFFF] = temp_16;
                    var_17 = (var_17 + 1) & 0xFFFF;
                } else {
                    var_18 = temp_3;
                    sp60[0] = temp_16;
                    var_17 = 1;
                }
            }
            var_19 += 1;
loop_test:
            if (var_19 < *(u16 *)(temp_20 + 0x6A))
                goto loop_body;
            var_2 = sp60[func_00231d70(var_17 & 0xFFFF)];
        }
        func_0029cf50(*(s32 *)(var_2 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return -1;
}
// FUN_001E7C20
s32 func_001e7c20(void) {
    extern s32 func_001dbba0();
    extern s32 func_002326c0();
    extern s64 func_0029cc00();
    extern void func_0029cf50();
    extern u8 *func_0029d050();
    extern void func_001db580();
    u8 *temp_18;
    s32 var_17;
    s32 var_16;

    temp_18 = func_0029d050();
    if (func_001dbba0(temp_18, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        var_16 = 0;
        var_17 = 0;
        goto loop_test;
loop_body:
        if (!(func_002326c0(*(s32 *)(*(u8 **)(*(u8 **)(temp_18 + (u16)var_17 * 4 + 0x38) + 0x30) + 0xA64)) & 0xFFEFFFFF)) {
            var_16 = (var_16 + 1) & 0xFFFF;
        }
        var_17 = (var_17 + 1) & 0xFFFF;
loop_test:
        if ((var_17 & 0xFFFF) < (s32)*(u16 *)(temp_18 + 0x6A))
            goto loop_body;
        func_0029cf50(var_16 & 0xFFFF);
    } else {
        func_0029cf50(0);
    }
    return -1;
}
// FUN_001E7D30
s32 func_001e7d30(void) {
    u8 *temp;

    temp = func_0029d050();
    func_0029cf50(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}
// FUN_001E7D70
s32 func_001e7d70(void) {
    func_0029cf50(func_00231f80(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7DD0
s32 func_001e7dd0(void) {
    func_0029cf50(datCalcGetHp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7E30
s32 func_001e7e30(void) {
    u8 *temp;

    temp = func_001b1560();
    func_0029cf50(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}
// FUN_001E7E70
// measured: the status byte/halfword gates the signed-byte payload; the
// payload is read only when neither gate is active.
s32 func_001e7e70(void)
{
    u8 *base;
    u8 *payload;
    s32 value;

    base = *(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30);
    if (*(u8 *)(base + 0xA2) == 0 && *(u16 *)(base + 0xA4) != 1) {
        payload = *(u8 **)(base + 0xA64);
        value = *(s8 *)(payload + 0x10);
    } else {
        value = -1;
    }
    func_0029cf50(value);
    return 1;
}

// FUN_001E7EF0
s32 func_001e7ef0(void) {
    func_0029cf50(func_00232290(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7F50
s32 func_001e7f50(void) {
    func_0029cf50(datCalcGetSp(*(s32 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}



// FUN_001E7FB0
s32 func_001e7fb0(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2E, 0, &func_001db8d0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            func_0029cf50(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8090
s32 func_001e8090(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da230) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8190
s32 func_001e8190(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da270) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8290
s32 func_001e8290(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001da2b0) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8390
s32 func_001e8390(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = func_0029d050();
    flags = func_0029cc00(0);
    if (func_001dbba0(work, flags, 0, 0x2E, 0, &func_001db900) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            func_0029cf50(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = func_001de370(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)func_00231d70(count) * 4, work) + 0x38);
            }
            func_0029cf50(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8490
s32 func_001e8490(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2E, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E85C0
s32 func_001e85c0(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2E, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E86F0
s32 func_001e86f0(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2F, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8820
s32 func_001e8820(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2E, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8950
s32 func_001e8950(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2E, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8A80
s32 func_001e8a80(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2F, 0, &func_001da2f0) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8BB0
s32 func_001e8bb0(void) {
    u64 temp_16;
    u64 temp_17;
    u8 *temp_19;
    u64 temp_18;

    temp_19 = func_0029d050();
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_18 = func_0029cc00(2);
    func_0029cf50(func_001de000(temp_19, func_001b0cc0((u64)(temp_17 << 0x24) >> 0x24), (s16)temp_16, temp_18));
    return 1;
}
// FUN_001E8C60
s32 func_001e8c60(void) {
    u64 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_0029cc00(2);
    func_001b0cc0((u64) (temp_16 << 0x24) >> 0x24);
    func_0029cf50(-1);
    return 1;
}

// FUN_001E8CD0
s32 func_001e8cd0(void) {
    u64 temp_16;
    u8 *temp_19;
    u64 temp_18;
    u64 temp_17;

    temp_19 = func_0029d050();
    temp_16 = func_0029cc00(0);
    temp_18 = func_0029cc00(1);
    temp_17 = func_0029cc00(2);
    func_0029cf50(func_001dd570(temp_19, func_001b0cc0((u64)(temp_16 << 0x24) >> 0x24), temp_18, temp_17));
    return 1;
}
// FUN_001E8D80
s32 func_001e8d80(void) {
    func_0029cf50((s16) func_0023d8e0(*(u8 **)(*(u8 **)(func_0029d050() + 0x30) + 0xA64), 0U));
    return 1;
}



// FUN_001E8DD0
s32 func_001e8dd0(void) {
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 0 &&
                func_002428f0(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = func_00231ed0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    func_0029cf50(*(s32 *)(best + 8) | 0x80000000);
    return 1;
}
// FUN_001E8EB0
s32 func_001e8eb0(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2C, 0, &func_001db580) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E8FE0
s32 func_001e8fe0(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0x100000, 0x2C, 0, &func_001db580) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E9110
s32 func_001e9110(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (func_001dbba0(work, func_0029cc00(0), 0, 0x2D, 0, &func_001db580) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = func_00231ed0(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E9240
s32 func_001e9240(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    selected = func_001d8c00(func_0029d050() + 0x98);
    if (selected == NULL || *(u8 *)(*(u8 **)(selected + 0x30) + 0xA2) != 1) {
        count = 0;
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            flags = *(u16 *)(current + 0x1A);
            if ((flags & 1) && (flags & 8)) {
                entry = *(u8 **)(current + 0x30);
                if (*(u8 *)(entry + 0xA2) == 1) {
                    data = *(u8 **)(entry + 0xA64);
                    if (data == NULL || func_002428f0((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
        selected = stack[func_00231d70(count & 0xFFFF)];
    }
    func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    return 1;
}
// FUN_001E9350
s32 func_001e9350(void) {
    u64 command;
    u16 skill;
    u32 index;
    u8 *result;
    u8 *entry;
    u32 count;
    u8 *base;
    u8 *work_or_id;

    work_or_id = func_0029d050();
    command = func_0029cc00(0);
    result = func_001b0cc0((u64)(command << 0x24) >> 0x24);
    entry = *(u8 **)((u8 *)work_or_id + 0x30);
    work_or_id = (u8 *)(s16)func_0023d8e0(*(u8 **)(entry + 0xA64), 0);
    if (func_00242800(*(s32 *)(*(u8 **)(result + 0x30) + 0xA64), (s32)work_or_id) & 0x08000000) {
        func_0029cf50((s16)work_or_id);
        return 1;
    }
    count = func_0023e130(*(u8 **)(entry + 0xA64)) & 0xFFFF;
    base = func_0023e140(*(u8 **)(entry + 0xA64));
    index = 0;
    while (index < count) {
        skill = *(u16 *)(base + index * 2);
        if (skill != 0 && skill < 0x1B8) {
            work_or_id = (u8 *)(s16)func_0023d8e0(*(u8 **)(entry + 0xA64), skill);
            if (func_00242800(*(s32 *)(*(u8 **)(result + 0x30) + 0xA64), (s32)work_or_id) & 0x08000000) {
                func_0029cf50((s16)work_or_id);
                return 1;
            }
        }
        index++;
    }
    func_0029cf50(-1);
    return 1;
}
// FUN_001E94E0
s32 func_001e94e0(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    func_0029d050();
    selected = func_001d8c00(*(u8 **)(iGpffffb3ac + 0x170) + 0x98);
    if (selected == NULL || *(u8 *)(*(u8 **)(selected + 0x30) + 0xA2) != 1) {
        count = 0;
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            flags = *(u16 *)(current + 0x1A);
            if ((flags & 1) && (flags & 8)) {
                entry = *(u8 **)(current + 0x30);
                if (*(u8 *)(entry + 0xA2) == 1) {
                    data = *(u8 **)(entry + 0xA64);
                    if (data == NULL || func_002428f0((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
        selected = stack[func_00231d70(count & 0xFFFF)];
    }
    func_0029cf50(*(s32 *)(selected + 8) | 0x80000000);
    return 1;
}
// FUN_001E9600
s32 func_001e9600(void) {
    u8 *work;
    u8 *current;
    u8 *best_fallback;
    u8 *best_eligible;
    u32 min_fallback;
    u32 min_eligible;
    u16 flags;
    u8 *entry;
    u32 value;

    work = func_0029d050();
    best_fallback = NULL;
    min_fallback = 0x0FFFFFFF;
    best_eligible = NULL;
    min_eligible = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 1 &&
                func_002428f0(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = func_00231ed0(*(s32 *)(entry + 0xA64)) & 0xFFFF;
                if (value < min_eligible &&
                    func_001dd570(work, current, 0, 0) >= 0) {
                    best_eligible = current;
                    min_eligible = value;
                }
                if (value < min_fallback) {
                    best_fallback = current;
                    min_fallback = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best_eligible != NULL) {
        func_0029cf50(*(s32 *)(best_eligible + 8) | 0x80000000);
    } else {
        func_0029cf50(*(s32 *)(best_fallback + 8) | 0x80000000);
    }
    return 1;
}
// FUN_001E9770
s32 func_001e9770(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern void func_0029cf50(s32 arg0);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00231f80(s32 arg0);
    extern s32 func_00232710(s32 arg0, s32 arg1);
    u32 temp_16;
    u32 temp_2;
    s32 temp_30;
    s32 temp_23;
    u8 *var_21;
    u8 *var_20;
    u32 temp_19;
    u32 var_18;
    s32 temp_17;
    u16 temp_3;
    u8 *temp_4;
    s32 temp_22;
    temp_23 = func_0029cc00(0);
    temp_30 = func_0029cc00(1);
    temp_17 = func_0029cc00(2);
    var_20 = NULL;
    var_18 = 0x0FFFFFFF;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    temp_22 = temp_17 & 0x80000;
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) == 0)
        goto loop_next;
    if ((temp_3 & 8) == 0)
        goto loop_next;
    if (*(u8 *)(*(u8 **)(var_21 + 0x30) + 0xA2) != 0)
        goto loop_next;
    if ((temp_22 == 0) &&
        (func_002428f0(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), 0) != 0))
        goto loop_next;
    temp_19 = func_00231ed0(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64)) & 0xFFFF;
    if ((u32)temp_23 > temp_19)
        goto loop_next;
    temp_4 = *(u8 **)(*(u8 **)(var_21 + 0x30) + 0xA64);
    temp_16 = *(u16 *)(temp_4 + 8);
    temp_2 = (u32)(func_00231f80((s32)temp_4) & 0xFFFF);
    if ((u32)temp_16 * 0x64 > temp_2 * (u32)temp_30)
        goto loop_next;
    if ((temp_17 != 0) &&
        (func_00232710(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), temp_17) == 0))
        goto loop_next;
    if (temp_19 >= var_18)
        goto loop_next;
    var_20 = var_21;
    var_18 = temp_19;
loop_next:
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    if (var_20 != NULL) {
        func_0029cf50(*(s32 *)(var_20 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001E9950
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9950);
// FUN_001E9F20
s32 func_001e9f20(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00232710(s32 arg0, s32 arg1);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern void func_0029cf50(s32 arg0);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 best_value;
    s32 random;

    random = func_0029cc00(0);
    best = NULL;
    best_value = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            if ((*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 1) &&
                (func_00232710(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), random) != 0) &&
                (func_002428f0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), 0) == 0)) {
                value = (u32)(func_00231ed0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF);
                if (best_value < value) {
                    best = current;
                    best_value = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best != NULL) {
        func_0029cf50(*(s32 *)(best + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001EA050
s32 func_001ea050(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00232710(s32 arg0, s32 arg1);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern void func_0029cf50(s32 arg0);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 best_value;
    s32 random;

    random = func_0029cc00(0);
    best = NULL;
    best_value = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            if ((*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 1) &&
                (func_00232710(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), random) != 0) &&
                (func_002428f0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), 0) == 0)) {
                value = (u32)(func_00231ed0(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF);
                if (value < best_value) {
                    best = current;
                    best_value = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best != NULL) {
        func_0029cf50(*(s32 *)(best + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001EA180
s32 func_001ea180(void) {
    u8 *sp10[12];
    s32 temp_4;

    temp_4 = (s32)(func_001d9390(func_0029d050(), 0, 0x80000, 2, 0, &func_001dbb90, &sp10) & 0xFFFF);
    if (temp_4 > 0) {
        func_0029cf50(*(s32 *)(sp10[func_00231d70(temp_4)] + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
// FUN_001EA220
s32 func_001ea220(void) {
    u8 *temp_16;

    temp_16 = func_0029d050();
    *(s16 *)(temp_16 + 0x6E) = func_0029cc00(0);
    *(s16 *)(temp_16 + 0x6C) = 9;
    *(s16 *)(temp_16 + 0x76) = func_0029cc00(1);
    *(s16 *)(temp_16 + 0x78) = func_0029cc00(2);
    *(s16 *)(temp_16 + 0x7A) = func_0029cc00(3);
    if (((s32 (*)(u8 *, s32))D_00609D20[0])(temp_16, 0) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_16, 0);
    return 1;
}
// FUN_001EA2D0
s32 func_001ea2d0(void) {
    u64 temp_16;
    u8 *temp_18;
    u64 temp_17;

    temp_18 = func_0029d050();
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_0019ef30(*(u8 **)(temp_18 + 0x30), temp_17);
    func_001de640(temp_18, temp_18 + 0x38, temp_16 & 0xFFFF);
    return 1;
}
// FUN_001EA360
s32 func_001ea360(void) {
    u8 *temp;

    temp = func_0029d050();
    *(s16 *)(temp + 0x6C) = 5;
    return 1;
}
// FUN_001EA390
s32 func_001ea390(void)
{
    u8 *work;
    s32 index;

    work = func_0029d050();
    index = func_0029cc00_s32(0);
    if ((iGpffffb3b8[index * 0x28] & 2) == 0) {
        func_0046d730(D_00609E30, 5711);
    }
    *(u16 *)(work + 0x6C) = 1;
    *(u16 *)(work + 0x6E) = index;
    return 1;
}
// FUN_001EA420
s32 func_001ea420(void)
{
    func_0029cf50(((*(u32 *)(D_00724504 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18))) & 0x20) != 0);
    return 1;
}

// FUN_001EA470
s32 func_001ea470(void) {
    func_0029cf50(*(s16 *)(iGpffffb3ac + 0xC34));
    return 1;
}

// FUN_001EA4A0
s32 func_001ea4a0(void) {
    s32 temp_2;
    s32 temp_2_2;

    if (func_001ef9a0() != 0x20B)
        goto set_flag;
    if (func_00106330(0x15FF) != 1)
        goto body;
set_flag:
    *(s32 *)(iGpffffb3ac + 0x10) |= 0x10000000;
    goto done;
body:
    if (*(void **)(iGpffffb3ac + 0xB40) == (void *)func_0022b120)
        goto done;
    if (*(void **)(iGpffffb3ac + 0xB44) == (void *)func_0022b870)
        goto done;
    temp_2 = func_0019ef90(1, 0x10B);
    if (temp_2 == 0)
        goto done;
    temp_2_2 = func_001b0c80(temp_2);
    if (temp_2_2 == 0)
        goto done;
    func_001fae60(func_0022b120, func_0022b870, temp_2_2);
done:
    return 1;
}
// FUN_001EA580
s32 func_001ea580(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bc920(*(s32 *)(iGpffffb3ac + 0x170), 0x21), 0);
    return 1;
}

// FUN_001EA5F0
s32 func_001ea5f0(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bc920(*(s32 *)(iGpffffb3ac + 0x170), 0x2C), 0);
    return 1;
}


// FUN_001EA660
s32 func_001ea660(void)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 first_copy;
    struct Vec3 second;
    struct Vec3 second_copy;
    f32 value;

    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    first.x = func_0029cd50(0);
    first.y = func_0029cd50(1);
    first.z = func_0029cd50(2);
    second.x = func_0029cd50(3);
    second.y = func_0029cd50(4);
    second.z = func_0029cd50(5);
    value = func_0029cd50(6);
    first_copy = first;
    second_copy = second;
    func_00194590(func_001bcb50(
        *(s32 *)(iGpffffb3ac + 0x170),
        (f32 *)&first,
        (f32 *)&second,
        value,
        (f32 *)&first_copy,
        (f32 *)&second_copy,
        value,
        1.0f), 0);
    return 1;
}
// FUN_001EA780
s32 func_001ea780(void) {
    D_00881420[0] = func_0029cd50(0);
    D_00881424[0] = func_0029cd50(1);
    D_00881428[0] = func_0029cd50(2);
    D_00881400[0] = func_0029cd50(3);
    D_00881404[0] = func_0029cd50(4);
    D_00881408[0] = func_0029cd50(5);
    fGpffffb458 = func_0029cd50(6);
    return 1;
}
// FUN_001EA830
s32 func_001ea830(void) {
    D_00881410[0] = func_0029cd50(0);
    D_00881414[0] = func_0029cd50(1);
    D_00881418[0] = func_0029cd50(2);
    D_008813F0[0] = func_0029cd50(3);
    D_008813F4[0] = func_0029cd50(4);
    D_008813F8[0] = func_0029cd50(5);
    fGpffffb454 = func_0029cd50(6);
    return 1;
}
// FUN_001EA8E0
s32 func_001ea8e0(void) {
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590(func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bcb50(
        *(s32 *)(iGpffffb3ac + 0x170),
        &D_00881420[0],
        &D_00881400[0],
        fGpffffb458,
        &D_00881410[0],
        &D_008813F0[0],
        fGpffffb454,
        (f32)func_0029cc00_s32(0) / 30.0f), 0);
    return 1;
}
// FUN_001EA9A0
s32 func_001ea9a0(void) {
    s64 temp_16;
    s64 temp_17;
    u8 *temp_2;
    u8 *temp_2_2;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    temp_2 = func_001f60c0();
    *(s16 *)(temp_2 + 0x48) = (s16)temp_16;
    func_00194590(temp_2, 1);
    temp_2_2 = func_001f6030(0x20, temp_17);
    *(s16 *)(temp_2_2 + 0x48) = (s16)temp_16;
    func_00194590(temp_2_2, 1);
    return 1;
}
// FUN_001EAA30
s32 func_001eaa30(void)
{
    s32 temp_16;
    u8 *temp_2;

    temp_16 = func_0029cc00_s32(0);
    temp_2 = func_001f60c0();
    *(s16 *)(temp_2 + 0x48) = (s16)temp_16;
    func_00194590(temp_2, 1);
    return 1;
}

// FUN_001EAA80
s32 func_001eaa80(void) {
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    }
    return 1;
}
// FUN_001EAAC0
s32 func_001eaac0(void)
{
    u8 *temp_4;

    if (func_001eb860() == 1) {
        temp_4 = iGpffffb3ac;
        *(s32 *)(temp_4 + 0xC) = *(s32 *)(temp_4 + 0xC) & ~0x2000;
        func_001eb7f0(temp_4);
    }
    return 1;
}

// FUN_001EAB10
s32 func_001eab10(void) {
    func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(s32 *)(iGpffffb3ac + 0xDD4), 1);
    }
    return 1;
}

// FUN_001EAB60
s32 func_001eab60(void) {
    func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(s32 *)(iGpffffb3ac + 0xDD4), 0);
    }
    return 1;
}

// FUN_001EABC0
s32 func_001eabc0(void) {
    u8 *p = func_001b1510();
    u32 a = func_0029cc00_s32(0) & 0xFFFF;
    u32 b = func_0029cc00_s32(1) & 0xFFFF;
    u32 flag = 1;

    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    func_0029cf50(flag != 0);
    return 1;
}
// FUN_001EACA0
/* measured probe: preserve the retail filter branch chain */
#pragma push
#pragma opt_rebuildconditionals off
s32 func_001eaca0(void) {
    extern u8 *func_001d3d50(s32 arg0);
    extern u8 *func_0022ced0(s32 arg0);
    extern void func_001d3ea0(u8 *arg0, u8 *arg1);
    extern u8 *func_001d6240(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4);
    extern void func_001d3e00(u8 *arg0);
    extern s32 func_00243ce0(s32 arg0);
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_2;
    u8 *temp_16;
    s32 temp_4;
    u16 temp_3_2;

    temp_16 = func_001d3d50(0);
    temp_4 = func_0029cc00_s32(0) & 0xFFFF;
    temp_4 = temp_4 + 1;
    func_001d3ea0(temp_16, func_0022ced0(temp_4 & 0xFFFF));
    temp_18 = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_17 = *(u8 **)(iGpffffb3ac + 0x180);
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(var_17 + 0xA64);
    if (temp_4 == 0)
        goto loop_advance;
    if (func_00243ce0(temp_4) == 0)
        goto loop_advance;
    temp_3_2 = *(u16 *)(var_17 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x10F:
    case 0x110:
    case 0x111:
        goto loop_advance;
    default:
        goto selected;
    }
loop_advance:
    var_17 = *(u8 **)(var_17 + 0xA6C);
loop_test:
    if (var_17 != NULL)
        goto loop_body;
selected:
    if (var_17 == NULL)
        var_17 = temp_18;
    temp_2 = func_001d6240(temp_16, temp_18, var_17, 0, 0x200);
    func_00194590(temp_2, 2);
    *(s64 *)(iGpffffb3ac + 0xBD0) = *(s64 *)(temp_2 + 0x58);
    var_17 = func_001d6240(temp_16, temp_18, var_17, 1, 0x200);
    func_00194590(var_17, 2);
    *(s64 *)(iGpffffb3ac + 0xBD8) = *(s64 *)(var_17 + 0x58);
    func_001d3e00(temp_16);
    return 1;
}
/* measured probe: close the filter branch chain */
#pragma pop
// FUN_001EAE30
s32 func_001eae30(void) {
    s64 mask;
    s32 hit;

    mask = 0x3FFFFFFFFFFFFFFFLL;
    if (func_00193b70(*(s64 *)(iGpffffb3ac + 0xBD0), mask) != 0)
        return 0;
    hit = func_00193b70(*(s64 *)(iGpffffb3ac + 0xBD8), mask) != 0;
    return hit ^ 1;
}
// FUN_001EAEC0
s32 func_001eaec0(void)
{
    extern u8 *func_001d9280(s64 arg0, s32 arg1, s32 arg2);
    extern void func_00198920(s32 arg0, s64 arg1, s64 arg2, f32 arg3,
                               s64 arg4);
    s64 temp_20;
    s64 temp_19;
    s64 temp_18;
    s64 temp_17;
    s64 temp_16;
    s32 var_2;
    u8 *temp_2;

    temp_20 = func_0029cc00(0);
    temp_19 = func_0029cc00(1);
    temp_18 = func_0029cc00(2);
    temp_17 = func_0029cc00(3);
    temp_16 = func_0029cc00(4);
    if (temp_20 == 0) {
        var_2 = 1;
    } else {
        var_2 = 2;
    }
    temp_2 = func_001d9280(temp_19 & 0xFFFF, var_2 & 0xFFFF, 0x80000);
    if (temp_2 != NULL) {
        func_00198920(*(s32 *)(temp_2 + 0x30), (s16)temp_18,
                      temp_17 & 0xFFFF, 1.0f, temp_16 & 0xFFFF);
    }
    return 1;
}
// FUN_001EAFB0
/* measured probe: preserve retail conditional branch shape */
#pragma push
#pragma opt_rebuildconditionals off
s32 func_001eafb0(void) {
    extern void func_001ec6d0();
    extern void func_00194ee0();
    extern s64 func_0029cc00();
    extern f32 func_0029cd50();
    f32 sp30[3];
    s32 temp_16;
    s32 temp_17;
    s32 var_2;
    s32 var_4;
    u8 *var_17;

    temp_17 = func_0029cc00_s32(0);
    temp_16 = func_0029cc00_s32(1);
    sp30[0] = func_0029cd50(2);
    sp30[1] = func_0029cd50(3);
    sp30[2] = func_0029cd50(4);
    var_4 = 0;
    if (temp_17 != 0)
        goto set_one;
    var_2 = 0;
    goto select_table;
set_one:
    var_2 = 1;
select_table:
    var_17 = *(u8 **)(p4_slot_001eb320((u32)(var_2 * 8), iGpffffb3ac) + 0x17C);
    goto loop_test;
loop_body:
    if (temp_16 == var_4) {
        func_001ec6d0(var_17 + 0x94, var_17 + 0x96, &sp30[0]);
        func_00194ee0(var_17, &sp30[0]);
        goto done;
    }
    var_4 += 1;
    var_17 = (u8 *)(*(u8 **)(var_17 + 0xA68));
loop_test:
    if (var_17 != NULL)
        goto loop_body;
done:
    return 1;
}
/* measured probe: close conditional branch shape */
#pragma pop
// FUN_001EB0B0
s32 func_001eb0b0(void) {
    u8 *o;

    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    o = func_001d3700(3, 0xFFF);
    *(s16 *)(o + 0x48) = 3;
    func_00194590(o, 0);
    return 1;
}

/* measured: the typed call view removes the dead s64 narrowing pair; the
   volatile gp load and offset helper reproduce retail's load/shift/addu order. */

// FUN_001EB110
s32 func_001eb110(void) {
    u8 sp20[0x200];
    s64 temp_16;
    s64 temp_2;
    u8 *temp_2_2;

    temp_16 = func_0029cc00(0);
    temp_2 = func_0029cc00(1);
    switch (temp_2) {
    case 0:
        temp_2_2 = func_002306d0();
        *(s16 *)(temp_2_2 + 0x48) = 2;
        func_00194590(temp_2_2, 1);
        break;
    case 1:
        func_00442088(&sp20[0], &D_00609E40[0], temp_16);
        func_00194590(func_001f81f0(2, &sp20[0]), 1);
        break;
    }
    return 1;
}

// FUN_001EB1D0
s32 func_001eb1d0(void) {
    s32 temp_3;
    u32 index;
    u8 *temp_2;
    u8 *temp_2_2;
    s32 (*callback)(u8 *, s64);

    temp_2 = func_0029d050();
    temp_2_2 = func_001dea90(temp_2, (u32)func_001de800(temp_2) & 0xFFFF);
    func_001de640(temp_2, temp_2 + 0x38, *(u16 *)(temp_2_2 + 2));
    temp_3 = *(s32 *)(temp_2_2 + 4);
    index = ((u32)temp_3 & 0xFF000000) >> 24;
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 + index * 8);
    if (callback(temp_2, ((u64)temp_3 << 40) >> 40) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    return 1;
}
// FUN_001EB2A0
s32 func_001eb2a0(void) {
    s32 temp;

    temp = func_0029cc00_s32(0);
    temp = func_00231d70(temp);
    func_0029cf50(temp);
    return 1;
}

/* measured: optimization_level 1 probe for retail GP-load scheduling. */
#pragma optimization_level 1
// FUN_001EB2E0
s32 func_001eb2e0(void) {
    s32 index;
    u8 *slot;

    index = func_0029cc00_s32(0);
    slot = p4_slot_001eb320((u32)index * 4, iGpffffb3ac);
    func_0029cf50(*(s32 *)(slot + 0xDD8));
    return 1;
}
/* measured: close optimization_level 1 probe for func_001eb2e0. */
#pragma optimization_level 2
/* measured: opt_propagation off probe for e320 GP-load order. */
#pragma opt_propagation off
// FUN_001EB320
s32 func_001eb320(void)
{
    s32 idx;
    s32 value;

    idx = func_0029cc00_s32(0);
    value = func_0029cc00_s32(1);
    *(s32 *)(p4_slot_001eb320((u32)idx * 4, iGpffffb3ac) + 0xDD8) = value;
    return 1;
}
/* measured: closes opt_propagation probe for func_001eb320. */
#pragma opt_propagation on

// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}

// FUN_001EB3B0
void func_001eb3b0(u8 *arg0) {
    u8 *temp;

    temp = arg0;
    func_001eb410(temp);
    *(s16 *)(temp + 0x36) = 0;
    *(s16 *)(temp + 0x38) = 0;
    *(s16 *)(temp + 0x34) = 0;
    *(s32 *)(temp + 0x50) = 0;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    func_0043f9c8(temp + 0x3E, 0, 6);
}
// FUN_001EB410
void func_001eb410(u8 *arg0) {
    *(s16 *)(arg0 + 0x32) = 0;
}
// FUN_001EB4A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eb4a0);
// FUN_001EB7F0
void func_001eb7f0(u8 *arg0) {
    s32 temp_4;
    u8 *temp_3;
    u8 *temp_5;

    temp_3 = iGpffffb3ac;
    temp_5 = temp_3 + 0xC;
    temp_4 = *(s32 *)(temp_3 + 0xC);
    if (temp_4 & 0x1000) {
        *(s32 *)temp_5 = temp_4 & ~0x1000;
        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4), temp_5);
        func_0045af60(1, 0xF, 2, 0x13);
    }
}
// FUN_001EB860
s32 func_001eb860(void) {
    u8 *temp_3;
    s32 result;

    temp_3 = iGpffffb3ac;
    if (*(s32 *)(temp_3 + 0xC) & 0x80) {
        result = 0;
        goto done;
    }
    if (*(s32 *)(temp_3 + 0xC68) != 0) {
        if (func_001ef9a0() == 0x215) {
            result = 0;
            goto done;
        }
    }
    result = 1;
done:
    return result;
}
// FUN_001EB8D0
void func_001eb8d0(void) {
    extern void func_002121b0();
    extern void func_00212210();
    extern void func_0045af60();
    extern u16 D_008C024E[];
    s32 flags;
    s32 temp_5;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x80) {
        var_3 = 0;
    } else if ((*(s32 *)(temp_4 + 0xC68) != 0) &&
               (func_001ef9a0() == 0x215)) {
        var_3 = 0;
    } else {
        var_3 = 1;
    }
    if ((var_3 != 0) &&
        (temp_3 = iGpffffb3ac,
         temp_6 = temp_3 + 0xC,
         flags = *(s32 *)(temp_3 + 0xC),
         ((flags & 0x2000) != 0))) {
        temp_5 = flags & 0x1000;
        if (temp_5 != 0) {
            if (((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20)) &&
                (temp_5 != 0)) {
                *(s32 *)temp_6 = *(s32 *)temp_6 & ~0x1000;
                func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4), temp_5, temp_6);
                func_0045af60(1, 0xF, 2, 0x13);
            }
        } else if ((D_008C024E[0] & 0x10) && (temp_5 == 0)) {
            *(s32 *)temp_6 = flags | 0x1000;
            func_002121b0(*(s32 *)(iGpffffb3ac + 0xDD4), temp_5, temp_6);
            func_0045af60(1, 0xF, 2, 0x12);
        }
    }
}
// FUN_001EBA20
s32 func_001eba20(u8 *arg0) {
    s32 result;
    u8 *temp_16;

    if (*(s32 *)(arg0 + 8) == 0) {
        func_001debb0(*(u8 **)arg0, *(u8 **)arg0 + 0x38,
                     *(s32 *)(arg0 + 0xC), *(s32 *)(arg0 + 4));
        *(u8 *)(*(u8 **)arg0 + 0x68) = 1;
        *(s32 *)(arg0 + 8) = 1;
        goto zero_path;
    }
    temp_16 = *(u8 **)arg0 + 0x38;
    if (*(u8 *)(*(u8 **)arg0 + 0x68) != 0)
        goto check_flags;
    result = 1;
    goto common;
check_flags:
    if (*(s32 *)(temp_16 + 0x4C) != 0)
        goto check_call;
    result = 1;
    goto common;
check_call:
    if (func_00452490(*(s32 *)(temp_16 + 0x4C)) != 0)
        goto result_zero;
    *(s8 *)(temp_16 + 0x30) = 0;
    *(s32 *)(temp_16 + 0x4C) = 0;
    result = 1;
    goto common;
result_zero:
    result = 0;
common:
    if (result == 0)
        goto zero_path;
    result = 1;
    goto done;
zero_path:
    result = 0;
done:
    return result;
}
// FUN_001EBB00
u8 *func_001ebb00(s32 arg0, s32 arg1, s32 arg2) {
    s32 kind;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = func_00194470(0xD00, 0x10);
    *(u8 *)(temp_2 + 0x47) &= 0xEE;
    *(s32 *)(temp_2 + 0x6C) = (s32)func_001eba20;
    temp_16 = *(u8 **)(temp_2 + 0x78);
    kind = arg1 & 0xFFFF;
    switch (kind) {
    case 1:
        *(s32 *)(temp_16 + 0xC) = (s32)iGpffffb428;
        break;
    case 2:
        *(s32 *)(temp_16 + 0xC) = (s32)iGpffffb42c;
        break;
    case 3:
        *(s32 *)(temp_16 + 0xC) = func_0022ced0(0);
        break;
    }
    *(s32 *)(temp_16 + 0x0) = arg0;
    *(s32 *)(temp_16 + 0x4) = func_0029de20(*(s32 *)(temp_16 + 0xC), arg2);
    *(s32 *)(temp_16 + 0x8) = 0;
    return temp_2;
}
// FUN_001EBC00
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ebc00);
// FUN_001EC1C0
void func_001ec1c0(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f12;
    f32 temp_f13;
    f32 var_f0;

    temp_f12 = *(f32 *)(arg2 + 0) - *(f32 *)(arg1 + 0);
    temp_f13 = *(f32 *)(arg2 + 8) - *(f32 *)(arg1 + 8);
    var_f0 = 0.0f;
    if ((temp_f12 != 0.0f) || (temp_f13 != 0.0f))
        var_f0 = fGpffff8048 * func_0044b950(temp_f12, temp_f13);
    func_003dc740(arg0, D_0060A0E0, var_f0, 0);
}
/* measured: opt_propagation off probe for ec2b0 load ordering. */
#pragma opt_propagation off
// FUN_001EC2B0
f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left)
{
    extern f32 func_0044b920(f32 arg0);
    f32 dot;

    dot = right->quat.x * left->quat.x +
          right->quat.y * left->quat.y +
          right->quat.z * left->quat.z;
    dot += right->quat.w * left->quat.w;
    if (dot < 0.0f) {
        dot = right->quat.x * -left->quat.x +
              right->quat.y * -left->quat.y +
              right->quat.z * -left->quat.z;
        dot += right->quat.w * -left->quat.w;
    }
    return 2.0f * func_0044b920(dot);
}
/* measured: close opt_propagation probe for func_001ec2b0. */
#pragma opt_propagation on
// FUN_001EC350
f32 func_001ec350(f32 *arg0, f32 *arg1)
{
    f32 zero;
    f32 length;

    zero = 0.0f;
    length = sqrtf(
        arg0[0] * arg0[0] +
        arg0[1] * arg0[1] +
        arg0[2] * arg0[2] +
        arg0[3] * arg0[3]);
    if (zero != length) {
        arg1[0] = arg0[0] / length;
        arg1[1] = arg0[1] / length;
        arg1[2] = arg0[2] / length;
        arg1[3] = arg0[3] / length;
    }
    return length;
}
// FUN_001EC3D0
f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 fabsf(f32 arg0);
    f32 delta[2];
    f32 vx;
    f32 vy;
    f32 cross;

    delta[0] = *(f32 *)(arg0 + 0) - *(f32 *)(arg1 + 0);
    delta[1] = *(f32 *)(arg0 + 4) - *(f32 *)(arg1 + 4);
    func_003e41e0(delta, delta);
    vx = *(f32 *)(arg2 + 0) - *(f32 *)(arg0 + 0);
    vy = *(f32 *)(arg2 + 4) - *(f32 *)(arg0 + 4);
    cross = (vx * delta[1]) + (vy * -delta[0]);
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = *(f32 *)(arg2 + 0) - cross * delta[1];
        *(f32 *)(arg3 + 4) = *(f32 *)(arg2 + 4) - cross * -delta[0];
    }
    return fabsf(cross);
}
// FUN_001EC4A0
s32 func_001ec4a0(s32 arg0, u8 *arg1)
{
    extern void func_003e42a0();
    extern u8 *func_00457120();
    f32 sp40[3];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    u8 *camera;

    camera = func_00457120() + 0x20;
    func_003e42a0(sp40, arg0, camera);
    temp_f20 = *(f32 *)(func_00457120() + 0x80);
    temp_f0 = *(f32 *)(func_00457120() + 0x84);
    if ((sp40[2] <= temp_f20) || !(sp40[2] < temp_f0)) {
        return 0;
    }
    temp_f2 = 640.0f * (sp40[0] / sp40[2]);
    temp_f1 = 448.0f * (sp40[1] / sp40[2]);
    if ((temp_f2 < -640.0f) || !(temp_f2 <= 1280.0f) ||
        (temp_f1 < -448.0f) || !(temp_f1 <= 896.0f)) {
        return 0;
    }
    *(f32 *)(arg1 + 0) = temp_f2;
    *(f32 *)(arg1 + 4) = temp_f1;
    return 1;
}
/* measured: third 001ec5e0 probe tests opt_propagation off for FPU-zero placement. */
#pragma opt_propagation off
// FUN_001EC5E0
void func_001ec5e0(u8 *arg0, f32 arg1)
{
    f32 zero;

    *(f32 *)arg0 = arg1;
    *(f32 *)(arg0 + 4) = arg1;
    zero = 0.0f;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    if (zero != arg1) {
        *(f32 *)(arg0 + 8) = 1.0f / ((arg1 * arg1) / 4.0f);
    }
}
/* measured: closes opt_propagation probe for func_001ec5e0. */
#pragma opt_propagation on
// FUN_001ECE50
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ece50);
// FUN_001ED060
int func_001ed060(float *param_1, float *param_2)
{
    u8 *node;
    int i;

    if (*(u8 **)((u8 *)param_2 + 0x10) == (u8 *)param_1)
    {
        return 1;
    }

    for (node = *(u8 **)(iGpffffb3ac + 0x318); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            int wrap = (i + 1) & 3;
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next;

            if ((edge == param_1) || (edge == param_2))
            {
                continue;
            }
            next = (float *)(node + wrap * 0x130 + 0x08);
            if ((next == param_1) || (next == param_2))
            {
                continue;
            }
            else
            {
                int intersects;
                int side_a = func_001ed330(edge, next, param_1);
                int side_b = func_001ed330(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = func_001ed330(param_1, param_2, edge);
                    side_b = func_001ed330(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }

    {
        u8 *record;
        float *next;
        float *edge;
        u8 *node2;
        int j;
        for (node2 = *(u8 **)(iGpffffb3ac + 0x318); node2 != NULL; node2 = *(u8 **)(node2 + 0x4cc))
        for (j = 0; j < 4; ++j)
        {
            record = node2 + j * 0x130;
            edge = (float *)(record + 0x08);

            if (edge == param_1)
            {
                return 0;
            }
            if (*(float *)(record + 0x1c) <= 0.0f)
            {
                continue;
            }
            next = *(float **)(record + 0x18);
            if (next != NULL)
            {
                int intersects;
                int side_a = func_001ed330(edge, next, param_1);
                int side_b = func_001ed330(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = func_001ed330(param_1, param_2, edge);
                    side_b = func_001ed330(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
// FUN_001ED3A0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed3a0);
// FUN_001ED700
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed700);
// FUN_001EE1C0
void func_001ee1c0(void) {
    f32 temp_f0;
    f32 temp_f1;

    *(s32 *)(iGpffffb3ac + 0x318) = 0;
    *(s32 *)(iGpffffb3ac + 0x7F0) = 0xBF800000;
    *(s32 *)(iGpffffb3ac + 0x920) = 0xBF800000;
    temp_f1 = (f32)(-0x6D6);
    *(f32 *)(iGpffffb3ac + 0x31C) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x320) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x44C) = temp_f1;
    temp_f0 = (f32)0x6D6;
    *(f32 *)(iGpffffb3ac + 0x450) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x57C) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x580) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x6AC) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x6B0) = temp_f0;
}
// FUN_001EE250
void func_001ee250(u8 *arg0, u8 *arg1)
{
    extern void func_001ec790(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;
    u8 *work;

    func_00195850(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    x = (s32)((f32)0x6D6 + coords[0]);
    y = (s32)((f32)0x6D6 + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12)
        rounded_x = (s64)(s16)(rounded_x + 1);
    if ((y % 25) > 12)
        rounded_y = (s64)(s16)(rounded_y + 1);
    if (&out_x != NULL)
        out_x = rounded_x;
    if (&out_y != NULL)
        out_y = rounded_y;
    work = arg0;
    func_001ec790(work, out_x, out_y, scale);
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32)(out_x * 25 - 0x6D6);
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)(out_y * 25 - 0x6D6);
    }
    *(s16 *)(arg0 + 0x508) = out_x;
    *(s16 *)(arg0 + 0x50A) = out_y;
    *(f32 *)(arg0 + 0x50C) = scale;
    *(s32 *)(arg0 + 0x9C) |= 4;
    *(s32 *)(arg0 + 0x9D0) = 0;
    if (*(u8 **)(iGpffffb3ac + 0x318) == NULL)
        goto ee250_no_head;
    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x318) + 0x4C8) =
        arg0 + 0x508;
    *(u8 **)(arg0 + 0x9D4) =
        *(u8 **)(iGpffffb3ac + 0x318);
    goto ee250_link_done;
ee250_no_head:
    *(u8 **)(arg0 + 0x9D4) = NULL;
ee250_link_done:
    *(u8 **)(iGpffffb3ac + 0x318) = arg0 + 0x508;
}
// FUN_001EE430
void func_001ee430(u8 *arg0) {
    s32 temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;

    temp_5 = *(s32 *)(arg0 + 0x9C);
    if (temp_5 & 4) {
        *(s32 *)(arg0 + 0x9C) = temp_5 & ~4;
        temp_5_2 = *(u8 **)(arg0 + 0x9D4);
        if (temp_5_2 != 0) {
            *(u8 **)(temp_5_2 + 0x4C8) = *(u8 **)(arg0 + 0x9D0);
        }
        temp_5_3 = *(u8 **)(arg0 + 0x9D0);
        if (temp_5_3 != 0) {
            *(u8 **)(temp_5_3 + 0x4CC) = *(u8 **)(arg0 + 0x9D4);
            return;
        }
        *(u8 **)(iGpffffb3ac + 0x318) = *(u8 **)(arg0 + 0x9D4);
    }
}
// FUN_001EE490
s32 func_001ee490(u8 *arg0) {
    extern void func_001ec790(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    extern void func_00195850(u8 *arg0, f32 *arg1);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    f32 base;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;

    if ((*(s32 *)(arg0 + 0x9C) & 4) == 0) {
        return 0;
    }
    func_00195850(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    base = (f32)1750;
    x = (s32)(base + coords[0]);
    y = (s32)(base + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12) {
        rounded_x = (s64)(s16)(rounded_x + 1);
    }
    if ((y % 25) > 12) {
        rounded_y = (s64)(s16)(rounded_y + 1);
    }
    if (&out_x != NULL) {
        out_x = (s16)rounded_x;
    }
    if (&out_y != NULL) {
        out_y = (s16)rounded_y;
    }
    if (*(s16 *)(arg0 + 0x508) != out_x ||
        *(s16 *)(arg0 + 0x50A) != out_y ||
        *(f32 *)(arg0 + 0x50C) != scale) {
        func_001ec790(arg0, out_x, out_y, scale);
        *(s16 *)(arg0 + 0x508) = out_x;
        *(s16 *)(arg0 + 0x50A) = out_y;
        *(f32 *)(arg0 + 0x50C) = scale;
        return 1;
    }
    return 0;
}
// FUN_001EE610
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee610);
/* measured: object 172B vs window 176B, normalized_diff 2; the remaining
   residual is the best-node register assignment. Committed at nd 2. */
// FUN_001EEC60
u8 *func_001eec60(void) {
    f32 value;
    f32 max;
    u8 *best;
    u8 *base;
    u8 **headp;
    u8 *scan;
    u8 *current;
    max = (f32)(s32)0x55730;
    base = iGpffffb3ac;
    headp = (u8 **)(base + 0xA3C);
    current = *headp;
    scan = current;
    goto scan_test;
scan_body:
    value = *(f32 *)(scan + 0x20);
    if (max <= value)
        goto scan_next;
    best = (u8 *)scan;
    max = value;
scan_next:
    scan = *(u8 **)(scan + 0x24);
scan_test:
    if (scan != 0)
        goto scan_body;
    scan = 0;
    goto unlink_test;
unlink_body:
    if (current == best)
        goto unlink_done;
    scan = current;
    current = *(u8 **)(current + 0x24);
unlink_test:
    if (current != 0)
        goto unlink_body;
unlink_done:
    if (current == 0)
        goto return_best;
    if (scan != 0) {
        *(u8 **)(scan + 0x24) = *(u8 **)(current + 0x24);
        goto return_best;
    }
    *headp = *(u8 **)(current + 0x24);
return_best:
    return best;
}
// FUN_001EED10
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eed10);
// FUN_001EF110
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef110);
// FUN_001EF4A0
s32 func_001ef4a0(s32 arg0)
{
    s32 value;

    value = iGpffffb3bc[(arg0 & 0xFFFF) * 4];
    if (value == 0)
    {
        value = 1;
    }
    return value;
}
// FUN_001EF4D0
/* measured: preserve retail count-result branch shape while probing ef4d0. */
#pragma opt_common_subs off
s32 func_001ef4d0(s32 arg0, s32 arg1)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg1 == 0) ||
                    (func_00232710(*(s32 *)(entry + 0xA64), arg1) == 0)) {
                    total = (total +
                             (func_00231e20(*(s32 *)(entry + 0xA64)) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}
/* measured: close ef4d0 branch-shape probe. */
#pragma opt_common_subs on
// FUN_001EF5F0
/* measured: preserve retail count-result branch shape while probing ef5f0. */
#pragma opt_common_subs off
s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg2 == 0) ||
                    (func_00232710(*(s32 *)(entry + 0xA64), arg2) == 0)) {
                    total = (total +
                             (func_00232c70(*(s32 *)(entry + 0xA64), arg1) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}
/* measured: close ef5f0 branch-shape probe. */
#pragma opt_common_subs on
// FUN_001EF720
s32 func_001ef720(s32 arg0, s32 arg1)
{
    u8 *current;
    s32 count;
    u8 *entry;
    s32 mask;

    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL)
    {
        if ((*(u16 *)(current + 0x1A) & 1) && (*(u16 *)(current + 0x1A) & 8))
        {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) && (func_00232710(*(s32 *)(entry + 0xA64), arg1) == 0))
            {
                count = (count + 1) & 0xFFFF;
            }
        }
        current = *(u8 **)(current + 0x450);
    }

    return count;
}
// FUN_001EF7E0
s32 func_001ef7e0(void)
{
    s32 *temp_3;
    s32 temp_3_2;
    s32 var_3;
    u16 temp_16;

    temp_3 = (s32 *)((s32)gEncountTbl + func_001ef9a0() * 24);
    if (*(u16 *)(iGpffffb3ac + 0xC5A) == 0) {
        return 0;
    }
    temp_3_2 = *temp_3;
    if ((temp_3_2 & 2) != 0) {
        return 0;
    }
    if ((temp_3_2 & 4) != 0) {
        return 1;
    }
    if (*(u32 *)(iGpffffb3ac + 0x20) == 0) {
        var_3 = 0;
    } else if (*(u32 *)(iGpffffb3ac + 0x20) > 5) {
        var_3 = 4;
    } else {
        var_3 = *(u32 *)(iGpffffb3ac + 0x20) - 1;
    }
    temp_16 = *(&iGpffffa9b0 + var_3);
    return (u32)func_00231d70(100) < (u32)temp_16;
}
// FUN_001EF8C0
s32 func_001ef8c0(void)
{
    u8 *base;
    u8 *table;
    u16 index;
    s32 flags;
    s64 result;
    u16 flags2;

    base = iGpffffb3ac;
    index = *(u16 *)(*(u8 **)(base + 0xC68) + 8);
    table = iGpffffb414 + index * 0x18;
    if (*(s32 *)(base + 0xC) & 0x20000000)
        return 0;
    flags = *(s32 *)table;
    if (flags & 8)
        return 0;
    if (flags & 0x10)
        return 2;
    if (flags & 0x800)
        return 1;
    flags2 = *(u16 *)(base + 0xC70);
    if (flags2 & 4)
        return 0;
    if (flags2 & 1)
        return 2;
    result = (flags2 & 0x10) != 0;
    return (u16)result;
}
// FUN_001EF9A0
s32 func_001ef9a0(void) {
    return *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
}
// FUN_001EF9C0
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ef9c0);
// FUN_001EFD50
u8 *func_001efd50(u8 *arg0)
{
    s16 temp_3;
    u8 *var_19;
    s32 var_18;
    s32 var_17;
    u16 temp_3_2;
    u8 *temp_16;
    s32 candidates[4];

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return NULL;
    }
    var_17 = 0;
    temp_3 = *(s16 *)(arg0 + 0x6E);
    if ((temp_3 < 0x1B8) &&
        ((*(u8 *)(iGpffffb3b8 + (temp_3 * 0x28)) & 0x80) != 0)) {
        var_17 = 1;
    }
    if ((var_17 == 0) &&
        (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
         (*(u16 *)(arg0 + 0x14) == 9))) {
        return NULL;
    }
    var_18 = 0;
    var_19 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_19 != NULL) {
        temp_3_2 = *(u16 *)(var_19 + 0x1A);
        if (((temp_3_2 & 1) != 0) &&
            ((temp_3_2 & 8) != 0) &&
            ((var_17 != 0) || ((temp_3_2 & 0x80) == 0)) &&
            (var_19 != arg0)) {
            temp_16 = *(u8 **)(var_19 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                ((var_17 != 0) ||
                 (func_00232710(*(s32 *)(temp_16 + 0xA64), 0x1001FF) == 0)) &&
                (func_002428f0(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                ((var_17 != 0) ||
                 ((func_00107ac0((func_00247cb0(*(s16 *)(temp_16 + 0xA4)) &
                                   0xFFFF)) &
                   0xFFFF) > 0))) {
                candidates[var_18] = (s32)var_19;
                var_18 += 1;
            }
        }
        var_19 = *(u8 **)(var_19 + 0x450);
    }
    if (var_18 == 0) {
        return NULL;
    }
    return (u8 *)candidates[func_00231d70(var_18)];
}
// FUN_001EFF50
s32 func_001eff50(u8 *arg0)
{
    s32 temp_16_2;
    s32 temp_5;
    u8 *var_18;
    s32 var_17;
    u16 temp_3;
    u8 *temp_16;
    s32 candidates[4];

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
        (*(u16 *)(arg0 + 0x14) == 9)) {
        return 0;
    }
    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x100117) != 0) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x28) < 2) {
        temp_5 = func_001064f0(0x79) -
                 (*(u8 *)(arg0 + 0x28) + 1);
        if (temp_5 > 0) {
            func_00106550(0x79, temp_5);
            return 0;
        }
    }
    var_17 = 0;
    var_18 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_18 != NULL) {
        temp_3 = *(u16 *)(var_18 + 0x1A);
        if (((temp_3 & 1) != 0) &&
            ((temp_3 & 8) != 0) &&
            (var_18 != arg0)) {
            temp_16 = *(u8 **)(var_18 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                (func_00232710(*(s32 *)(temp_16 + 0xA64),
                                0x1001FF) == 0) &&
                (func_002428f0(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                (func_00243e30(*(s32 *)(temp_16 + 0xA64)) == 0) &&
                ((func_00107ac0((func_00247cb0(
                                    *(s16 *)(temp_16 + 0xA4)) &
                                  0xFFFF)) &
                  0xFFFF) >= 3)) {
                temp_16_2 =
                    (func_00232950(*(s32 *)(temp_16 + 0xA64), 0x88) &
                     0xFFFF) *
                    10;
                temp_5 = func_00231d70(0x64);
                if ((u32)temp_5 > (u32)(temp_16_2 + 0x3C)) {
                } else {
                    candidates[var_17] = (s32)var_18;
                    var_17 += 1;
                }
            }
        }
        var_18 = *(u8 **)(var_18 + 0x450);
    }
    if (var_17 == 0) {
        return 0;
    }
    func_00106550(0x79, func_00231d70(3) + 3);
    return candidates[func_00231d70(var_17)];
}
