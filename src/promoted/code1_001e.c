#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
typedef struct BtlPacket BtlPacket;
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
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void func_001bd780(void *out, const void *first,
                          const void *second, const void *up);
extern f32 func_003e4180(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *func_003dcb40(void *out, const void *in, s32 count, const void *rotation);
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
extern u16 func_00232290();
extern s32 datCalcGetSp();

extern s32 func_0023d8e0(u8 *unit, u16 skill);
extern u32 func_0023e130(u8 *arg0);
extern u8 *func_0023e140(u8 *unit);
extern s32 func_0023ddc0(u8 *unit, s32 skill);
extern s32 func_0023dfe0(u8 *unit);
extern s32 func_00242800(s32 arg0, s32 arg1);
extern u8 *func_001b1510(void);
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void func_00213b80(s32 task);
extern void func_00213b50(s32 task);
extern s32 func_001eb860(void);
extern void func_00212240(u8 *arg0, s32 arg1);
extern void func_00212210(s32 task);
extern s32 func_001ef9a0(void);
extern s32 D_00724504;
extern void func_001eb7f0(u8 *arg0);
extern s32 func_001eb860(void);
extern void func_001a03b0(s32 arg0);
extern BtlPacket *func_001d3700(u16 arg0, u16 arg1);
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
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


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
extern BtlPacket *func_002306d0(void);
extern u8 *func_001f81f0(s32 arg0, void *arg1);
extern void func_00442088(void *arg0, void *arg1, s64 arg2);
extern u8 D_00609E40[];
extern u32 func_00232710(s32 arg0, u32 arg1);
extern s32 func_00232c70(s32 arg0, s32 arg1);
extern s32 func_00231ed0(s32 arg0);
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_0019ef90(s32 arg0, s32 arg1);
extern s32 func_001b0c80(s32 arg0);
extern void func_001fae60(s32 initialize, s32 update, s32 packet);
extern void func_0022b120(u8 *action);
extern s32 func_0022b870(u8 *action);
extern void func_001debb0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 func_00452490(s32 arg0);
extern u8 *func_00194470(s32 arg0, s32 arg1);
extern u8 *func_0022ced0(s32 arg0);
extern s32 func_0029de20(s32 arg0, s32 arg1);
extern s32 func_001eba20(u8 *arg0);
extern u8 *iGpffffb428;
extern u16 func_00107ac0(s32 arg0);
extern void func_00106550(s32 arg0, s32 arg1);
extern s32 func_00243e30(u16 *arg0);
extern u16 func_00247cb0(s64 arg0);
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
/* SUPERSEDED, kept for history: "normalized_diff 1; the sole residual is the
   retail daddiu/addiu width at the count reset. Committed at nd 1." That width
   was believed unreachable. It is not - see the measured note below. */
/* measured: u16 var_17 reaches retail daddiu s1,zero,1; fused
   sp60[var_17++] produces addiu v0,s1,1 from the unmasked counter,
   avoiding reuse of the masked index. Object 364B/window 368B,
   normalized_diff 0. */
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
    u16 var_17;
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
                    sp60[var_17++] = temp_16;
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
/* FUN_001E9950: s32 func_001e9950(void), retail frame 0x1A0 (obj 0x180 here),
   175 instrs window 1488B. Outer skill loop over e130/e140 table with
   i==0 -> dfe0 else base[i-1] (sll/addu/lhu -2), slti 0x1B8 guard,
   d8e0 -> kind -> d6e0 &0x7E filter, mode 1/2 split via
   lq 0x100 bne/beq, df70/32710/ddc0 gates, 1d7f10 into tgt.entries[14]
   +count@0x38, two inner scorings (single-best vs accumulating) with
   negu/slt + cvt.s.w/div.s/add.s and c.lt.s/c.le.s/c.eq.s best update,
   dd90==2 + d9b0<bestCost tie-break, de640/1b0cc0/dbf20 tail, 29cf50 return 1.
   Neighbours (116 MATCH): 9350 for 0x1B8 + (s16)d8e0 idiom, 9240 for
   entries[14]+count@0x38 + &0xFFFF masking, datCalc d6e0(s16)/d8e0(u8*,u16)
   + d9b0/dd90/df70 signatures, 9770/9f20 for 29cc00/29cf50/1b0cc0 patterns.
   Levers top-down: skillStore >=0x1B8 keeps slti $at,0x1B8 + beqz (vs
   >0x1B7 which spills $v0 per playbook); (s32) outer/
   inner < keeps slt signed (vs neighbours sltu).
   Width pass (279w/178e -> 261w/128e, pairs 14 -> 8 = retail, size 373/372
   -> 370/371): the `s64 kind` chain emitted 48-shift quads where retail has
   16-shift pairs plus moves. `kind = (s16)func_0023d8e0(...)` reproduces
   retail's init pair; paramA/paramB `(s16)kind` reproduce the store pairs;
   the d6e0 call passes `(s32)kind` and the 242800 call passes `paramB`
   (same s16 value, already live), reproducing retail's two `move`s. The
   d6e0 callee is truly `s16` (datCalc MATCH); this TU declares it `s32`,
   which is ABI- and behavior-identical here because kind is s16-valued and
   the callee reads only the low 16 bits. Prior note's `(s16) collapses to
   seh` claim does not hold at these sites: (s16) emits dsll32/dsra32-16,
   matching retail.
   PINNED (do not "fix"): the zero-test keeps the `(s64)(kind<<0x30)>>0x30`
   quad. Spelling it `(s16)kind == 0` reproduces retail's pair locally but
   recolors the whole function (work $s5->$s1 and cascade, 280 -> 316 words);
   paramA/B recovery only reaches 300. Bisected: init+middle alone are
   word-neutral (279 -> 280); the test spelling is the trigger.
   WALL: saved-register rotation (kind $s6 vs retail $s3, unit/skill similar)
   plus spill slots (skillStore 0x110, outer 0x140, bestCost 0x150), frame
   0x180 vs 0x1A0, s128 lq/sq canonicalization floor, FPU reg choice. */
// FUN_001E9950 NONMATCHING
#ifdef NON_MATCHING
s32 func_001e9950(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern void func_0029cf50(s32 arg0);
    extern s32 func_0023d6e0(s32 arg0);
    extern s32 func_0023df70(s32 arg0);
    extern u32 func_0023d9b0(u8 *arg0, s32 arg1);
    extern u16 func_0023dd90(u8 *arg0, s32 arg1);
    extern s32 func_001db360(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 func_00235520(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    extern s32 func_00242800(s32 arg0, s32 arg1);
    extern u8 *func_001b0cc0(s32 arg0);
    extern void func_001dbf20(u8 *arg0, s32 arg1);
    extern s32 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, s32 arg3);
    u8 *work;
    u8 *unit;
    s32 bestSkill;
    s32 bestTarget;
    s32 bestCost;
    f32 curScore;
    f32 bestScore;
    f32 cur;
    u16 *table;
    s32 mode;
    s32 outerLimit;
    u16 outer;
    s32 outerCount;
    u16 skill;
    s32 skillStore;
    s64 kind;
    s32 paramA;
    s32 paramB;
    s32 innerBest;
    s32 idxA;
    s32 idxB;
    u8 *entryA;
    u8 *entryB;
    s32 dmg;
    s32 hp;
    s32 maxHp;
    s32 neg;
    s32 cost;
    struct {
        u8 *entries[14];
        u16 count;
    } tgt;
    work = func_0029d050();
    mode = func_0029cc00(0);
    unit = *(u8 **)(work + 0x30);
    bestTarget = 0;
    bestSkill = -1;
    bestCost = 0x3E7;
    bestScore = -1.0f;
    outerLimit = ((func_0023e130(*(u8 **)(unit + 0xA64)) & 0xFFFF) + 1) & 0xFFFF;
    table = (u16 *)func_0023e140(*(u8 **)(unit + 0xA64));
    outer = 0;
    outerCount = outerLimit & 0xFFFF;
    goto outer_test;
outer_body:
    if (outer == 0) {
        skill = (u16)(func_0023dfe0(*(u8 **)(unit + 0xA64)) & 0xFFFF);
    } else {
        skill = *(u16 *)((u8 *)table + (u32)outer * 2 - 2);
        if (skill == 0) {
            goto outer_next;
        }
    }
    skillStore = skill & 0xFFFF;
    if (skillStore >= 0x1B8) {
        goto outer_next;
    }
    kind = (s16)func_0023d8e0(*(u8 **)(unit + 0xA64), skill);
    if ((func_0023d6e0((s32)kind) & 0x7E) == 0) {
        goto outer_next;
    }
    if (((s64)(kind << 0x30) >> 0x30) == 0) {
        if (mode == 1) {
            goto outer_next;
        }
    } else {
        if (mode == 2) {
            goto outer_next;
        }
    }
    if (func_0023df70(skill & 0xFFFF) == 0) {
        if (func_00232710(*(s32 *)(*(u8 **)(unit + 0xA64)), 0x80008) != 0) {
            goto check_targets;
        }
        if (func_0023ddc0(*(u8 **)(unit + 0xA64), skill & 0xFFFF) != 0) {
            goto outer_next;
        }
    }
check_targets:
    innerBest = 0;
    if ((func_001d7f10(work, (u8 *)&tgt, skill, 0) & 0xFFFF) == 0) {
        curScore = 0.0f;
        idxA = 0;
        paramA = (s16)kind;
innerA_test:
        if ((idxA & 0xFFFF) >= (s32)(tgt.count & 0xFFFF)) {
            goto scored;
        }
        entryA = tgt.entries[(idxA & 0xFFFF)];
        if (func_001db360(entryA, paramA, 1) != 0) {
            dmg = func_00235520(skill & 0xFFFF, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entryA + 0x30) + 0xA64), 1, 1, 1, 0, 1);
            hp = func_00231ed0(*(s32 *)(*(u8 **)(entryA + 0x30) + 0xA64)) & 0xFFFF;
            maxHp = func_00231f80(*(s32 *)(*(u8 **)(entryA + 0x30) + 0xA64)) & 0xFFFF;
            neg = -dmg;
            if (hp < neg) {
                cur = (f32)hp / (f32)maxHp + 1.0f;
            } else {
                cur = (f32)neg / (f32)maxHp;
            }
            if (curScore < cur) {
                innerBest = *(s32 *)(entryA + 8);
                curScore = cur;
            }
        }
        idxA = (idxA + 1) & 0xFFFF;
        goto innerA_test;
    } else {
        curScore = 0.0f;
        idxB = 0;
        paramB = (s16)kind;
innerB_test:
        if ((idxB & 0xFFFF) >= (s32)(tgt.count & 0xFFFF)) {
            goto scored;
        }
        entryB = tgt.entries[(idxB & 0xFFFF)];
        if (func_001db360(entryB, paramB, 1) == 0) {
            if ((func_00242800(*(s32 *)(*(u8 **)(entryB + 0x30) + 0xA64), paramB) & 0x1000000) == 0) {
                curScore = 0.0f;
                goto scored;
            }
        } else {
            dmg = func_00235520(skill & 0xFFFF, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entryB + 0x30) + 0xA64), 1, 1, 1, 0, 1);
            hp = func_00231ed0(*(s32 *)(*(u8 **)(entryB + 0x30) + 0xA64)) & 0xFFFF;
            maxHp = func_00231f80(*(s32 *)(*(u8 **)(entryB + 0x30) + 0xA64)) & 0xFFFF;
            neg = -dmg;
            if (hp < neg) {
                curScore = curScore + (f32)hp / (f32)maxHp + 1.0f;
            } else {
                curScore += (f32)neg / (f32)maxHp;
            }
        }
        idxB = (idxB + 1) & 0xFFFF;
        goto innerB_test;
    }
scored:
    if (bestScore <= curScore) {
        if (bestScore == curScore) {
            if ((func_0023dd90(*(u8 **)(unit + 0xA64), skill & 0xFFFF) & 0xFFFF) == 2) {
                cost = func_0023d9b0(*(u8 **)(unit + 0xA64), skill & 0xFFFF);
                if (cost < bestCost) {
                    bestSkill = skillStore;
                    bestTarget = innerBest;
                    bestScore = curScore;
                    bestCost = cost;
                }
            }
        } else {
            bestSkill = skillStore;
            bestTarget = innerBest;
            bestScore = curScore;
        }
    }
    goto outer_next;
outer_next:
    outer = (u16)(outer + 1);
outer_test:
    if ((s32)outer < (s32)outerCount) {
        goto outer_body;
    }
    if (bestSkill != -1) {
        if (bestSkill == 0) {
            func_001de640(work, work + 0x38, 0x8000);
        } else {
            func_001de640(work, work + 0x38, bestSkill & 0xFFFF);
        }
        if (bestTarget != 0) {
            *(u8 **)(work + 0x38) = func_001b0cc0(bestTarget);
            *(u16 *)(work + 0x6A) = 1;
        } else {
            func_001dbf20(work, 0);
        }
    }
    func_0029cf50(bestSkill);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001e9950);
#endif
// FUN_001E9F20
s32 func_001e9f20(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern s32 func_00231ed0(s32 arg0);
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
    func_001fae60((s32)func_0022b120, (s32)func_0022b870, temp_2_2);
done:
    return 1;
}
// FUN_001EA580
s32 func_001ea580(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
    func_00194590(func_001bc920(*(s32 *)(iGpffffb3ac + 0x170), 0x21), 0);
    return 1;
}

// FUN_001EA5F0
s32 func_001ea5f0(void)
{
    func_001a03b0(*(s32 *)(iGpffffb3ac + 0x170));
    func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
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
    func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
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
    func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
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
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 1);
    }
    return 1;
}

// FUN_001EAB60
s32 func_001eab60(void) {
    func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
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
    extern s32 func_001d3d50(u32 arg0);
    extern void func_001d3ea0(u8 *arg0, u8 *arg1);
    extern BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
    extern void func_001d3e00(u8 *arg0);
    extern s32 func_00243ce0(s32 arg0);
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_2;
    u8 *temp_16;
    s32 temp_4;
    u16 temp_3_2;

    temp_16 = (u8 *)func_001d3d50(0);
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
    temp_2 = (u8 *)func_001d6240((u32)temp_16, (u32)temp_18, (u32)var_17, 0, 0x200);
    func_00194590(temp_2, 2);
    *(s64 *)(iGpffffb3ac + 0xBD0) = *(s64 *)(temp_2 + 0x58);
    var_17 = (u8 *)func_001d6240((u32)temp_16, (u32)temp_18, (u32)var_17, 1, 0x200);
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
    o = (u8 *)func_001d3700(3, 0xFFF);
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
        temp_2_2 = (u8 *)func_002306d0();
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
/* measured: u16 state selects the narrow daddiu constants at 0x001eb598 and
   0x001eb5c0; the table-entry scan preserves the retail register-width masks. */
void func_001eb4a0(u8 *arg0, u8 *arg1, s64 arg2) {
    extern s32 func_00105ed0();
    extern void func_001de640(u8 *arg0, u8 *arg1, u16 arg2);
    extern s32 func_00231d70(u32 arg0);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    extern void *D_006098BC[];
    extern void *D_00609934[];
    extern u8 D_00609E50[];
    extern u8 D_00609EF0[];
    extern u8 D_00609F90[];
    extern u8 D_0060A030[];
    extern u8 *iGpffffb3c4;
    extern u8 iGpffffa4d8;
    u8 *table;
    u32 actionWord;
    s32 threshold;
    u16 state;
    s32 index;
    s32 sum;
    s32 cumulative;
    s32 scanIndex;
    u64 mode;
    u8 *current;
    u8 *entry;
    u8 weight;
    u8 *row;
    u8 *unitData;
    u8 *unit;
    s32 (*callback)(u8 *, s64);

    *(u16 *)(arg1 + 0x32) = 0;
    *(u16 *)(arg1 + 0x36) = 0;
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x34) = 0;
    *(u32 *)(arg1 + 0x50) = 0;
    *(u32 *)(arg1 + 0x54) = 0;
    *(u32 *)(arg1 + 0x58) = 0;
    func_0043f9c8(arg1 + 0x3E, 0, 6);
    table = NULL;
    entry = NULL;
    mode = ((u64)arg2 << 44) >> 44;
    switch (mode) {
    case 0x10:
        unit = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unit + 0xA2) == 1) {
            if ((*(u16 *)(iGpffffb3c4 + *(u16 *)(unit + 0xA4) * 0x3C) & 0x2000) == 0 &&
                (*(u16 *)(arg0 + 0x1A) & 0x4000) == 0) {
                state = 0;
            } else {
                state = 2;
            }
        } else if (func_00105ed0() != 0) {
            state = 0;
        } else {
            state = 2;
        }
        if (((s32 (*)(u8 *, s32))D_006098BC[0])(arg0, 1) != 0)
            state++;
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0)
            table = D_00609E50;
        else
            table = D_00609EF0;
        break;
    case 4:
        unitData = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unitData + 0xA2) == 0 && *(u16 *)(unitData + 0xA4) == 1) {
            state = 1;
        } else {
            state = (u16)(((s32 (*)(u8 *, s32))D_00609934[0])(arg0, 0) != 1);
        }
        table = D_00609F90;
        break;
    case 2:
        entry = (u8 *)&iGpffffa4d8 - 8;
        break;
    case 0x100:
        state = 0;
        table = D_0060A030;
        break;
    }
    if (table != NULL) {
        sum = 0;
        index = 0;
        row = table + (state & 0xFFFF) * 0x28;
        goto eb4a0_sum_test;
eb4a0_sum_body:
        sum = (sum + *(u8 *)(row + ((u16)index * 8))) & 0xFFFF;
        index = (index + 1) & 0xFFFF;
eb4a0_sum_test:
        if ((index & 0xFFFF) < 5)
            goto eb4a0_sum_body;
        entry = NULL;
        threshold = (s32)(func_00231d70(sum & 0xFFFF) & 0xFFFF);
        cumulative = 0;
        for (scanIndex = 0; (scanIndex & 0xFFFF) < 5;
             scanIndex = (scanIndex + 1) & 0xFFFF) {
            current = row + ((u16)scanIndex * 8);
            weight = *(u8 *)current;
            cumulative = (cumulative + weight) & 0xFFFF;
            if (threshold <= cumulative && weight > 0) {
                entry = current;
                break;
            }
        }
    }
    func_001de640(arg0, arg1, *(u16 *)(entry + 2));
    actionWord = *(u32 *)(entry + 4);
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 +
                                      (((actionWord & 0xFF000000) >> 24) * 8));
    if (callback(arg0, (s64)((u64)actionWord << 40 >> 40)) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(arg0, 0);
}
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
        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));
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
    extern void func_002121b0(s32 task);
    extern void func_00212210(s32 task);
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
                func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));
                func_0045af60(1, 0xF, 2, 0x13);
            }
        } else if ((D_008C024E[0] & 0x10) && (temp_5 == 0)) {
            *(s32 *)temp_6 = flags | 0x1000;
            func_002121b0(*(s32 *)(iGpffffb3ac + 0xDD4));
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
u8 *func_001ebb00(s32 arg0, s32 arg1, u8 *arg2) {
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
        *(s32 *)(temp_16 + 0xC) = (s32)func_0022ced0(0);
        break;
    }
    *(s32 *)(temp_16 + 0x0) = arg0;
    *(s32 *)(temp_16 + 0x4) = func_0029de20(*(s32 *)(temp_16 + 0xC), (s32)arg2);
    *(s32 *)(temp_16 + 0x8) = 0;
    return temp_2;
}
// FUN_001EBC00
/* 1468/1472 bytes; all four call relocations resolve exactly. */
#pragma opt_common_subs off
void func_001ebc00(u8 *action, u8 *command)
{
    u16 choices[8];
    u16 *skills;
    s32 index;
    s32 count;
    u32 skill;
    u32 available;

    skills = (u16 *)func_0023e140(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    count = 0;
    index = 0;
    while ((index & 0xFFFF) < 8) {
        skill = skills[index & 0xFFFF];
        if (skill != 0) {
            switch (skill) {
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x21:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA8:
            case 0xA9:
            case 0xAB:
            case 0xAC:
            case 0xAD:
                if (func_0023ddc0(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), skill) == 0) {
                    choices[count & 0xFFFF] = skill;
                    count = (count + 1) & 0xFFFF;
                }
                break;
            }
        }
        index = (index + 1) & 0xFFFF;
    }
    available = count & 0xFFFF;
    if (available == 0) {
        *(u16 *)(command + 0x34) = 1;
        *(u16 *)(command + 0x36) = func_0023dfe0(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    } else {
        *(u16 *)(command + 0x34) = 2;
        *(u16 *)(command + 0x36) = choices[func_00231d70(available)];
    }
}
#pragma opt_common_subs on
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
typedef struct P4NeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    u8 rest[0x114];
} P4NeighborNode;
typedef struct P4NeighborGroup {
    s32 unknown0;
    s32 unknown4;
    P4NeighborNode nodes[4];
    struct P4NeighborGroup *previous;
    struct P4NeighborGroup *next;
} P4NeighborGroup;
extern s32 func_001eca10(u8 *first, u8 *second);
extern f32 func_003e41b0(f32 *vector);
typedef struct P4NeighborWorld {
    u8 prefix[0x318];
    P4NeighborGroup *groups;
    P4NeighborNode nodes[4];
    P4NeighborNode start;
    P4NeighborNode goal;
} P4NeighborWorld;

// FUN_001ED3A0
/* 852/864 bytes; all eighteen relocations resolve exactly.
   Array types preserve halfword indexing; local order preserves lifetimes. */
s32 func_001ed3a0(u8 *node, f32 threshold)
{
    f32 linkedDelta[2];
    f32 fixedDelta[2];
    f32 startDelta[2];
    f32 goalDelta[2];
    f32 distance;
    P4NeighborGroup *group;
    s32 count;
    u16 index;
    u8 *neighbor;

    count = 0;
    group = *(P4NeighborGroup **)(iGpffffb3ac + 0x318);
    while (group != 0) {
        for (index = 0; index < 4; index++) {
            neighbor = (u8 *)&group->nodes[index];
            if (neighbor == node)
                continue;
            if (group->nodes[index].active <= 0.0f)
                continue;
            if (group->nodes[index].clearance < threshold)
                continue;
            if (func_001eca10(node, neighbor) != 0)
                continue;
            linkedDelta[0] = *(f32 *)(node + 8) - *(f32 *)((u8 *)group + index * 0x130 + 0x10);
            linkedDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)((u8 *)group + index * 0x130 + 0x14);
            distance = func_003e41b0(linkedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
            *(u8 **)(node + (u16)count * 4 + 0x30) = neighbor;
            count = (u16)(count + 1);
        }
        group = group->next;
    }
    for (index = 0; index < 4; index++) {
        if ((u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index] == node)
            continue;
        if (((P4NeighborWorld *)iGpffffb3ac)->nodes[index].active <= 0.0f)
            continue;
        if (func_001eca10(node, (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index]) != 0)
            continue;
        fixedDelta[0] = *(f32 *)(node + 8) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].x;
        fixedDelta[1] = *(f32 *)(node + 0xC) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].z;
        distance = func_003e41b0(fixedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
        *(u8 **)(node + (u16)count * 4 + 0x30) = (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index];
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x7DC != node && func_001eca10(node, iGpffffb3ac + 0x7DC) == 0) {
        startDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x7E4);
        startDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x7E8);
        distance = func_003e41b0(startDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x7DC;
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x90C != node && func_001eca10(node, iGpffffb3ac + 0x90C) == 0) {
        goalDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x914);
        goalDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x918);
        distance = func_003e41b0(goalDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x90C;
        count = (u16)(count + 1);
    }
    *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = 0;
    return count;
}
/* measured: object 2744B vs window 2752B (object 686 vs retail 687 instrs),
 * probe 632 words; frame 0xF0 vs retail 0x100; saves f20-f27 (8) vs retail
 * f20-f26 (7). Retail recomputes group+i*0x130 inline; prior cached-pointer
 * body was 642. Remaining classes: branch polarity (beq/bne, bc1t/bc1f,
 * c.ole/c.olt), ld/sd 64-bit copies (3 vs 1), scheduling (lwc1 +3, addiu +2,
 * lui -3, move -2, sll -2). Banked at 0.15% under the 3% gate; production
 * stays ASM. Prior exclusions: per-lane 25 mul.s/add.s each side, equal jal
 * 11 == 11, matching case counts, romwright recovered 72B frame identical to
 * own layout. New exclusions: pointer caching 642 -> 686 via inline
 * group+i*0x130 (partial 679 +19, full +44; v11 addu +14/sll +9/lw +7 vs
 * full addu -3/sll -2/lw 0); quantize retail[105:112] 7 vs object 1 excluded
 * as inlined helper (hoisted-locals c_hoist.c still 686/1-vs-7,
 * opt_loop_invariants on 679, func_001ee250 is >12/1750 round-nearest vs
 * here ceil !=0/500/25); romwright if-else 3,2,1,0 already adopted over m2c
 * switch 0,1,2,3 (CONCAT44/u64 ld/sd kept separate: c_s64.c 682; separate
 * s16 +9 v1 660 vs v2 651 but dsll 41 vs 21, lh/sh 8/0 vs 24/16; struct
 * gives dsll 22 vs 21, lh/sh match); residual 1 instr + 0x10 frame + 1 float
 * reg is polarity/ld-sd/scheduling only. Candidate
 * /var/tmp/cold1ed700b/c_struct_full.c. Do not re-litigate without new
 * evidence.
 */
/* measured 001ed700 (owner, 2026-09-19): 687/688 with 887 fnalign edits, and
   `block_move_scan` calls the largest pair IN-PLACE at ratio 0.827 - retail[334:460]
   (126 instructions at 0x001EDC38) against object[323:451] (128).  Same code, different
   registers, diverging where it stands, so there is no block to move.
   Reading the two side by side: retail carries the record pointer in $s4 and the loop
   counter in $s3; the object uses $s3 and $s0.  The float colouring shifts with it -
   retail's `lwc1 $f25, 4($s4)` is the object's `lwc1 $f21, 4($s3)` - and the object saves
   a spare $f27 for a frame of 0xF0 against retail's 0x100.  One float local too many is
   held across the loop; the candidates are bestX, bestZ, bestH and dist, one of which
   retail recomputes at its use.
   Do not re-test declaration order: on func_001b11c0, the same class of transposition,
   four declaration orders measured 12, 12, 5 and 12 against a baseline of 5, so MWCC is
   not colouring by declaration. */
/* measured 001ed700 (owner, 2026-09-19): fnalign **887 -> 871 edits**, count
   686 -> 684 against retail 687, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
/* measured 001ed700 (owner, 2026-09-19): fnalign **871 -> 782 edits**, count
   684 -> 682 against retail 687, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
// FUN_001ED700 NONMATCHING
#ifdef NON_MATCHING
void func_001ed700(f32 radius)
{
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_003e41b0(f32 *vec);
    extern f32 D_0060A120[];
    extern f32 fGpffff8330;
    struct { s16 x; s16 y; } corners[4];
    f32 bounds[4];
    f32 curX;
    f32 curZ;
    f32 delta[2];
    f32 norm[2];
    f32 bestDir[2];
    f32 wpos[2];
    u8 *node;
    u8 *group;
    u8 *other;
    u8 *best;
    s32 i;
    s32 j;
    s32 t;
    s16 tx;
    s16 ty;
    s16 q;
    f32 dist;
    f32 bestDist;
    f32 bestX;
    f32 bestZ;
    f32 bestH;
    s32 first;
    f32 f0;

    first = 0;
    for (node = *(u8 **)(iGpffffb3ac + 0x318); node != NULL; node = *(u8 **)(node + 0x4CC)) {
        if (first == 0) {
            corners[0].x = *(s16 *)(node + 0);
            corners[1].x = corners[0].x;
            corners[2].x = corners[0].x;
            corners[3].x = corners[0].x;
            corners[0].y = *(s16 *)(node + 2);
            corners[1].y = corners[0].y;
            corners[2].y = corners[0].y;
            corners[3].y = corners[0].y;
            f0 = *(f32 *)(node + 4);
            bounds[0] = f0;
            bounds[1] = f0;
            bounds[2] = f0;
            bounds[3] = f0;
            first = 1;
        } else {
            tx = *(s16 *)(node + 0);
            ty = *(s16 *)(node + 2);
            if ((corners[0].x >= tx) && (corners[0].y >= ty)) {
                corners[0].x = tx;
                corners[0].y = ty;
                bounds[0] = *(f32 *)(node + 4);
            }
            if ((tx >= corners[1].x) && (corners[1].y >= ty)) {
                corners[1].x = tx;
                corners[1].y = ty;
                bounds[1] = *(f32 *)(node + 4);
            }
            if ((tx >= corners[2].x) && (ty >= corners[2].y)) {
                corners[2].x = tx;
                corners[2].y = ty;
                bounds[2] = *(f32 *)(node + 4);
            }
            if ((corners[3].x >= tx) && (ty >= corners[3].y)) {
                corners[3].x = tx;
                corners[3].y = ty;
                bounds[3] = *(f32 *)(node + 4);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        t = (s32)(bounds[i] + 500.0f);
        q = (s16)(t / 25);
        if (t % 25 != 0) {
            q = (s16)(q + 1);
        }
        if (i == 3) {
            tx = (s16)(corners[i].x - q);
            ty = (s16)(q + corners[i].y);
            if (tx < 0) {
                tx = 0;
            }
        } else if (i == 2) {
            tx = (s16)(q + corners[i].x);
            ty = (s16)(q + corners[i].y);
        } else if (i == 1) {
            tx = (s16)(q + corners[i].x);
            ty = (s16)(corners[i].y - q);
            if (ty < 0) {
                ty = 0;
            }
        } else {
            tx = (s16)(corners[i].x - q);
            ty = (s16)(corners[i].y - q);
            if (tx < 0) {
                tx = 0;
            }
            if (ty < 0) {
                ty = 0;
            }
        }
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x31C) = (f32)(tx * 25 - 1750);
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x320) = (f32)(ty * 25 - 1750);
    }
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            best = NULL;
            bestDist = 7000.0f;
            curX = *(f32 *)(group + i * 0x130 + 8);
            curZ = *(f32 *)(group + i * 0x130 + 12);
            for (other = *(u8 **)(iGpffffb3ac + 0x318); other != NULL; other = *(u8 **)(other + 0x4CC)) {
                if (group != other) {
                    for (j = 0; j < 4; j++) {
                        delta[0] = *(f32 *)(other + j * 0x130 + 8) - curX;
                        delta[1] = *(f32 *)(other + j * 0x130 + 12) - curZ;
                        dist = func_003e41e0(norm, delta);
                        if ((fGpffff8330 < norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1]) && (dist < bestDist)) {
                            if (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(other + j * 0x130 + 8)) == 0) {
                                bestDir[0] = norm[0];
                                bestDir[1] = norm[1];
                                best = other + j * 0x130 + 8;
                                bestDist = dist;
                                bestX = (f32)(*(s16 *)(other + 0) * 25 - 1750);
                                bestZ = (f32)(*(s16 *)(other + 2) * 25 - 1750);
                                bestH = *(f32 *)(other + 4);
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 4; j++) {
                delta[0] = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x31C) - curX;
                delta[1] = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x320) - curZ;
                dist = func_003e41e0(norm, delta);
                if (((fGpffff8330 < norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1]) && (dist < bestDist)) && (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(iGpffffb3ac + j * 0x130 + 0x31C)) == 0)) {
                    bestDir[0] = norm[0];
                    bestDir[1] = norm[1];
                    best = iGpffffb3ac + j * 0x130 + 0x31C;
                    bestDist = dist;
                    bestX = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x31C);
                    bestZ = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x320);
                    bestH = 0.0f;
                }
            }
            if (best != NULL) {
                f32 half;
                f32 dx;
                f32 dz;
                half = 0.5f * bestDist;
                dx = bestDir[0] * half;
                bestDir[0] = dx;
                dz = bestDir[1] * half;
                bestDir[1] = dz;
                *(f32 *)(group + i * 0x130 + 0x10) = curX + dx;
                *(f32 *)(group + i * 0x130 + 0x14) = curZ + dz;
                *(u8 **)(group + i * 0x130 + 0x18) = best;
                *(f32 *)(group + i * 0x130 + 0x1C) = bestDist;
                dx = (f32)(*(s16 *)(group + 0) * 25 - 1750);
                dz = (f32)(*(s16 *)(group + 2) * 25 - 1750);
                delta[0] = dx - bestX;
                delta[1] = dz - bestZ;
                *(f32 *)(group + i * 0x130 + 0x20) = func_003e41b0(delta) - (*(f32 *)(group + 4) + bestH);
            } else {
                *(f32 *)(group + i * 0x130 + 0x1C) = -1.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        wpos[0] = *(f32 *)(iGpffffb3ac + i * 0x130 + 0x31C);
        wpos[1] = *(f32 *)(iGpffffb3ac + i * 0x130 + 0x320);
        best = NULL;
        bestDist = 7000.0f;
        for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
            j = 0;
            do {
                delta[0] = *(f32 *)(group + j * 0x130 + 8) - wpos[0];
                delta[1] = *(f32 *)(group + j * 0x130 + 12) - wpos[1];
                dist = func_003e41b0(delta);
                if (dist < bestDist) {
                    func_003e41e0(bestDir, delta);
                    best = group + j * 0x130 + 8;
                    bestDist = dist;
                }
                j++;
            } while (j < 4);
        }
        if (best == NULL) {
            *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
        } else {
            if (*(u8 **)(best + 0x10) == iGpffffb3ac + i * 0x130 + 0x31C) {
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
            } else {
                f32 half;
                half = 0.5f * bestDist;
                bestDir[0] = bestDir[0] * half;
                bestDir[1] = bestDir[1] * half;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x324) = wpos[0] + bestDir[0];
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x328) = wpos[1] + bestDir[1];
                *(u8 **)(iGpffffb3ac + i * 0x130 + 0x32C) = best;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = bestDist;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x334) = 500.0f;
            }
        }
    }
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        i = 0;
        do {
            if ((*(f32 *)(group + i * 0x130 + 0x1C) <= 0.0f) || (*(f32 *)(group + i * 0x130 + 0x20) < radius)) {
                *(s32 *)(group + i * 0x130 + 0x38) = 0;
            } else {
                func_001ed3a0(group + i * 0x130 + 8, radius);
            }
            i++;
        } while (i < 4);
    }
    for (i = 0; i < 4; i++) {
        if (0.0f < *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330)) {
            func_001ed3a0(iGpffffb3ac + i * 0x130 + 0x31C, radius);
        } else {
            *(s32 *)(iGpffffb3ac + i * 0x130 + 0x34C) = 0;
        }
    }
    func_001ed3a0(iGpffffb3ac + 0x7DC, radius);
    func_001ed3a0(iGpffffb3ac + 0x90C, radius);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ed700);
#endif
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
/* measured 001ee610: heaviest MAC (1600B window, 429-line asm, 7 mula + 12 madda + 7 madd = 26 MAC words in 7 groups: 1x2-term dot + 6x4-term dots).
   First probe via fnalign --candidate: object 383 vs retail 398 instrs, frame 0x4C0 vs 0x4E0 (32B shortfall),
   s-reg rotation (arg0 s3 vs retail s4), stack pts 0xC0 vs 0x80. MAC reassociation per matching.md
   (madd.s follows source multiply order; b210 starts accumulator with SECOND addend): 2-term dot as
   tmp8*tmp10 + tmp9*tmp11 (mula=second) and 4-term dots as c0+c1+c2+c3 where c1=mula, c3=madd
   (retail order c1,c0,c2,c3). Swapped order (c1+c0+c2+c3) same earliest hunks, confirming earliest
   frame/s-reg floor hides MACs. Open: frame, s-reg rotation, scheduler ordering (cf. 001eed10 floor).
   Committed as NONMATCHING; production remains ASM (1024B? no, 1600B window). See P023 doc. */
/* measured: object 387 against retail 398, -2.76% - INSIDE the +-3% band
   (a 398-instruction function gets 12 instructions of slack; the deficit is
   11).  Was 383 / -3.8% OUTSIDE with 380 edits; now 371 edits.
   The fix was UNFUSING two multiply-accumulates, and the evidence for it was
   the opcode delta rather than any run: retail had 18 more `swc1`, 8 more
   `mul.s` and 8 more `add.s` against a deficit of only 15, which means the
   object was FUSING work retail kept separate rather than omitting it.  All
   three retail-only runs were longer than the deficit - 37 at 0x001EEA78, 29
   at 0x001EE7F0, 23 at 0x001EE870 - so every one was a CROSS and writing new
   statements would have made the floor worse.
   Retail at 0x001EEA78 stores each intermediate back before using it:
     lwc1 $f0,0x4C0($29) / mul.s $f2,$f0,$f1 / swc1 $f2,0x4C0($29)
     lwc1 $f0,0x4C4($29) / mul.s $f1,$f0,$f1 / swc1 $f1,0x4C4($29)
     lwc1 $f0,0x80($29)  / add.s $f0,$f2,$f0 / swc1 $f0,0x4C0($29)
     add.s $f0,$f1,$f20  / swc1 $f0,0x4C4($29)
     lwc1 $f1,0x4C0($29) / lwc1 $f0,0x4C4($29)
     swc1 $f1,0x498($29) / swc1 $f0,0x49C($29)
   That is `t *= s; t += p; out = t;` as separate statements on an
   address-taken pair, not `out = t * s + p;`.  Both the 300.0f and the
   500.0f blocks were written fused and are now separate.
   STILL OPEN, and the next thing to attack: the prologue.  Retail opens
   `addiu $sp,$sp,-0x4e0` / `sd $ra,0x70($sp)` / `sq $s5,0x60($sp)` /
   `sq $s4,0x50($sp)` where the object has `addiu $sp,$sp,-0x4c0` /
   `sd $ra,0x50($sp)`.  Retail's frame is 32 bytes bigger, its save area
   starts 32 bytes higher, and it holds one more pointer live - `$s4` against
   the object's `$s3`.  A frame-size and saved-register-count difference is a
   source defect: the body does not keep as many values live across calls as
   retail's did.  (Visible only since tools/eedis.py taught fnalign to decode
   `lq`/`sq`; both rows previously read `??` and compared equal.) */
// FUN_001EE610 NONMATCHING
#ifdef NON_MATCHING
s32 func_001ee610(u8 *arg0, f32 arg1) {
    extern s32 func_001ece50(f32 *a0, f32 *a1, f32 f);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 fGpffff8334;
    extern f32 fGpffff8338;
    extern f32 fGpffff80fc;
    extern f32 fGpffff833c;
    f32 pts[256];
    f32 tmp[24];
    u8 *var_16;
    u8 *var_17;
    s32 var_18;
    s32 var_19;
    s32 var_18_2;
    s32 var_17_2;
    u8 *base;
    f32 half;
    base = iGpffffb3ac;
    var_16 = base + 0x90C;
    half = 0.5f * arg1;
    var_18 = 0;
    tmp[10] = 0.0f;
    tmp[11] = 0.0f;
    tmp[22] = 0.0f;
    tmp[23] = 0.0f;
    if (func_001ece50((f32 *)(base + 0x7E4), (f32 *)(base + 0x914), half) == 0) {
        base = iGpffffb3ac;
        pts[0] = *(f32 *)(base + 0x914);
        pts[1] = *(f32 *)(base + 0x918);
        pts[2] = *(f32 *)(base + 0x7E4);
        pts[3] = *(f32 *)(base + 0x7E8);
        var_18 = 2;
        goto tail_check;
    }
    goto outer_test;
outer_body:
    if (var_18 > 0) {
        var_17 = var_16;
inner_test:
        if (var_16 != 0) {
            if (func_001ece50(&tmp[18], (f32 *)(var_16 + 8), half) == 0) {
                var_17 = var_16;
                var_16 = *(u8 **)(var_16 + 0x2C);
                goto inner_test;
            }
        }
        var_16 = var_17;
        tmp[18] = *(f32 *)(var_17 + 8);
        tmp[19] = *(f32 *)(var_17 + 0xC);
    } else {
        tmp[18] = *(f32 *)(var_16 + 8);
        tmp[19] = *(f32 *)(var_16 + 0xC);
    }
    tmp[8] = tmp[10];
    tmp[9] = tmp[11];
    tmp[10] = tmp[18] - tmp[22];
    tmp[11] = tmp[19] - tmp[23];
    {
        f32 dot = tmp[8] * tmp[10] + tmp[9] * tmp[11];
        if (var_18 >= 2 && dot <= fGpffff8334) {
            f32 f21;
            f32 f02;
            f21 = func_003e41e0(&tmp[12], &tmp[10]);
            f02 = func_003e41e0(&tmp[14], &tmp[8]);
            if (f21 < 250.0f && f02 < 250.0f) {
                var_18_2 = var_18 - 1;
            } else {
                f32 f2 = fGpffff8338 * f21;
                tmp[20] = tmp[12] * f2 + pts[var_18 * 2 - 2];
                tmp[21] = tmp[13] * f2 + pts[var_18 * 2 - 1];
                pts[var_18 * 2] = tmp[20];
                pts[var_18 * 2 + 1] = tmp[21];
                {
                    f32 g1 = fGpffff80fc * f02;
                    tmp[20] = tmp[14] * g1 + pts[var_18 * 2 - 4];
                    tmp[21] = tmp[15] * g1 + pts[var_18 * 2 - 3];
                    pts[var_18 * 2 - 2] = tmp[20];
                    pts[var_18 * 2 - 1] = tmp[21];
                }
                var_18_2 = var_18 + 1;
            }
            pts[var_18_2 * 2] = tmp[18];
            pts[var_18_2 * 2 + 1] = tmp[19];
            var_18 = var_18_2 + 1;
        } else {
            pts[var_18 * 2] = tmp[18];
            pts[var_18 * 2 + 1] = tmp[19];
            var_18 += 1;
        }
    }
    tmp[22] = pts[var_18 * 2 - 4];
    tmp[23] = pts[var_18 * 2 - 3];
    var_16 = *(u8 **)(var_16 + 0x2C);
outer_test:
    if (var_16 != 0) goto outer_body;
tail_check:
    if (var_18 < 2) return 0;
    if (var_18 < 3) {
        *(f32 *)(arg0 + 0) = pts[2];
        *(f32 *)(arg0 + 4) = pts[3];
        *(f32 *)(arg0 + 8) = pts[0];
        *(f32 *)(arg0 + 0xC) = pts[1];
        *(s16 *)(arg0 + 0x400) = 2;
        return 1;
    }
    {
        var_17_2 = 0;
        var_19 = var_18 - 1;
        do {
            u8 *out;
            tmp[0] = pts[var_19 * 2];
            tmp[1] = pts[var_19 * 2 + 1];
            if ((var_19 + 1) >= var_18) {
                tmp[2] = pts[var_18 * 2 - 2];
                tmp[3] = pts[var_18 * 2 - 1];
            } else {
                tmp[2] = pts[var_19 * 2 + 4];
                tmp[3] = pts[var_19 * 2 + 5];
            }
            if ((var_19 - 1) < 0) {
                tmp[16] = pts[0] - tmp[0];
                tmp[17] = pts[1] - tmp[1];
                func_003e41e0(&tmp[16], &tmp[16]);
                tmp[16] = tmp[16] * 300.0f;
                tmp[17] = tmp[17] * 300.0f;
                tmp[16] = tmp[16] + pts[0];
                tmp[17] = tmp[17] + pts[1];
                tmp[4] = tmp[16];
                tmp[5] = tmp[17];
            } else {
                tmp[4] = pts[var_19 * 2 - 2];
                tmp[5] = pts[var_19 * 2 - 1];
            }
            if ((var_19 - 2) < 0) {
                tmp[16] = pts[0] - tmp[0];
                tmp[17] = pts[1] - tmp[1];
                func_003e41e0(&tmp[16], &tmp[16]);
                tmp[16] = tmp[16] * 500.0f;
                tmp[17] = tmp[17] * 500.0f;
                tmp[16] = tmp[16] + pts[0];
                tmp[17] = tmp[17] + pts[1];
                tmp[6] = tmp[16];
                tmp[7] = tmp[17];
            } else {
                tmp[6] = pts[var_19 * 2 - 4];
                tmp[7] = pts[var_19 * 2 - 3];
            }
            out = arg0 + var_17_2 * 8;
            *(f32 *)(out + 0) = tmp[0];
            *(f32 *)(out + 4) = tmp[1];
            *(f32 *)(out + 8) = -0.0703125f * tmp[2] + 0.8671875f * tmp[0] + 0.2265625f * tmp[4] + -0.0234375f * tmp[6];
            *(f32 *)(out + 0xC) = -0.0703125f * tmp[3] + 0.8671875f * tmp[1] + 0.2265625f * tmp[5] + -0.0234375f * tmp[7];
            *(f32 *)(out + 0x10) = -0.0625f * tmp[2] + 0.5625f * tmp[0] + 0.5625f * tmp[4] + -0.0625f * tmp[6];
            *(f32 *)(out + 0x14) = -0.0625f * tmp[3] + 0.5625f * tmp[1] + 0.5625f * tmp[5] + -0.0625f * tmp[7];
            *(f32 *)(out + 0x18) = -0.0234375f * tmp[2] + fGpffff833c * tmp[0] + 0.8671875f * tmp[4] + -0.0703125f * tmp[6];
            *(f32 *)(out + 0x1C) = -0.0234375f * tmp[3] + fGpffff833c * tmp[1] + 0.8671875f * tmp[5] + -0.0703125f * tmp[7];
            var_17_2 += 4;
            var_19 -= 1;
        } while (var_19 > 0);
        *(f32 *)(arg0 + var_17_2 * 8 + 0) = pts[0];
        *(f32 *)(arg0 + var_17_2 * 8 + 4) = pts[1];
        *(s16 *)(arg0 + 0x400) = (s16)(var_17_2 + 1);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001ee610);
#endif
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
/* Route-search floor (1024B window). First probe nd 132 (frame/prologue
   verified); structure and callee conventions per archived notes. Open:
   s-reg rotation and scheduler ordering. See P023 doc. */
// FUN_001EED10 NONMATCHING
#ifdef NON_MATCHING
/* measured 001eed10: `opt_propagation off` inside the guard is worth 1 word (132 -> 131). */
#pragma opt_propagation off
/* P023: retained route-search investigation, 2026-09-08.
 * Production remains ASM: 001EED10..001EF10F, 1024-byte window.
 * Preferred full-owner candidate: 1000/1024 bytes, nd364, 24 relocations.
 * Frame is the retail 0xB0, but 24 executable bytes are missing. This is
 * not a register-only floor, exact recovery, or impossibility claim.
 *
 * Initial typed-provider flat candidate: 992/716, frame0xA0. Typed edge
 * condition preserves two distinct live edge pointers: 1016/430. Matching
 * the open/closed membership loop exits reaches the preferred 1000/364.
 * CSE-off flat source:1080/695; propagation/loop profiles do not close it.
 * Typed cost field:1000/438; integer insertion address:1012/742;
 * float-array cost:1004/431; array insertion:1016/762. These pairs list
 * emitted bytes / normalized byte differences. Literal final addresses
 * were resolved for inspection, not treated as arbitrary relocations.
 *
 * Remaining source-shape differences: cost-address scheduling, membership
 * register lifetimes, recomputation of update/insertion index projections,
 * global/neighbor reload ordering and closed-unlink loop alignment.
 *
 * Input ABI: route a0, start/end two-float arrays a1/a2, radius f12.
 * Collision test receives half radius. Direct path stages each endpoint's
 * two loads, writes two points/count2/mode2, returns1. Obstructed path
 * clears count, stages global endpoints, builds adjacency. Missing start
 * or goal adjacency returns0/mode3 before list initialization.
 *
 * Search clears open/closed heads, start g/parent; start f is distance to
 * goal. The exact 001EEC60 provider removes the best open node. A neighbor
 * is reopened only when absent from both lists or !(current.g<=newCost).
 * This compares CURRENT g, not neighbor g: do not fix the retail algorithm.
 * Reopening updates g/f/parent, unlinks the closed node and inserts it in
 * open when absent. NaN behavior follows the ordered comparison literally.
 * Goal selection invokes 001EE610 and returns1/mode2 regardless of that
 * provider's return; exhausted open returns0/mode3.
 *
 * External contracts still govern provider inputs/results. In particular,
 * 001EEC60 needs a nonempty open list with a selectable score below 350000
 * (or an unordered score); its source leaves best unwritten otherwise.
 * This investigation proves no game-data bound excluding that provider
 * path, and makes no native/gameplay validation claim for this candidate.
 *
 * To reproduce: start from current full owner, replace NNode's
 * opaque rest[0x114] with the fields below, add these provider declarations,
 * replace only target INCLUDE_ASM with this body. All other source remains.
 * Standalone archive declarations are not a production ABI migration.
 */
#include "type.h"
extern u8 *iGpffffb3ac;
extern u8 *func_001eec60(void);
extern void func_001ed700(f32 radius);
extern s32 func_001ee610(u8 *route, f32 radius);
extern s32 func_001ece50(f32 *start, f32 *end, f32 radius);
s32 func_001eed10(u8 *route, f32 *start, f32 *end, f32 radius)
{
typedef struct NNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    f32 pathCost;
    f32 estimatedCost;
    struct NNode *openNext;
    struct NNode *closedNext;
    struct NNode *parent;
    struct NNode *neighbors[32];
    f32 distances[32];
} NNode;
typedef struct NGroup {
    s32 unknown0;
    s32 unknown4;
    NNode nodes[4];
    struct NGroup *previous;
    struct NGroup *next;
} NGroup;
typedef struct NWorld {
    u8 prefix[0x318];
    NGroup *groups;
    NNode nodes[4];
    NNode start;
    NNode goal;
} NWorld;

    f32 initialDelta[2];
    f32 goalDelta[2];
    f32 x;
    f32 z;
    f32 oldCost;
    f32 newCost;
    f32 distance;
    u8 *base;
    u8 *current;
    u8 *neighbor;
    u8 **edge;
    u8 **updateEdge;
    u8 *scan;
    u8 *previous;
    u8 **closedHead;
    u8 *remove;
    s32 found;
    s32 inOpen;
    s32 inClosed;
    u16 index;

    *(u8 *)(route + 0x404) = 1;
    if (func_001ece50(start, end, 0.5f * radius) == 0) {
        x = start[0];
        z = start[1];
        *(f32 *)(route + 0) = x;
        *(f32 *)(route + 4) = z;
        x = end[0];
        z = end[1];
        *(f32 *)(route + 8) = x;
        *(f32 *)(route + 0xC) = z;
        *(u16 *)(route + 0x400) = 2;
        *(u8 *)(route + 0x404) = 2;
        return 1;
    }
    *(u16 *)(route + 0x400) = 0;
    base = iGpffffb3ac;
    x = start[0];
    z = start[1];
    *(f32 *)(base + 0x7E4) = x;
    *(f32 *)(base + 0x7E8) = z;
    x = end[0];
    z = end[1];
    *(f32 *)(base + 0x914) = x;
    *(f32 *)(base + 0x918) = z;
    func_001ed700(radius);
    base = iGpffffb3ac;
    if (*(s32 *)(base + 0x80C) == 0 || *(s32 *)(base + 0x93C) == 0) {
        *(u8 *)(route + 0x404) = 3;
        return 0;
    }
    *(u8 **)(base + 0xA3C) = 0;
    *(u8 **)(iGpffffb3ac + 0xA40) = 0;
    *(s32 *)(iGpffffb3ac + 0x7F8) = 0;
    base = iGpffffb3ac;
    initialDelta[0] = *(f32 *)(base + 0x7E4) - *(f32 *)(base + 0x914);
    initialDelta[1] = *(f32 *)(base + 0x7E8) - *(f32 *)(base + 0x918);
    distance = func_003e41b0(initialDelta);
    *(f32 *)(iGpffffb3ac + 0x7FC) = distance;
    *(s32 *)(iGpffffb3ac + 0x808) = 0;
    base = iGpffffb3ac;
    *(u8 **)(base + 0x800) = *(u8 **)(base + 0xA3C);
    base = iGpffffb3ac;
    *(u8 **)(base + 0xA3C) = base + 0x7DC;
    found = 0;
    while (*(u8 **)(iGpffffb3ac + 0xA3C) != 0) {
        current = func_001eec60();
        if (current == iGpffffb3ac + 0x90C) {
            found = 1;
            break;
        }
        for (index = 0; (neighbor = *(edge = (u8 **)&((NNode *)current)->neighbors[index])) != 0; index++) {
            oldCost = *(f32 *)(current + 0x1C);
            newCost = oldCost + *(f32 *)(current + index * 4 + 0xB0);
            base = iGpffffb3ac;
            scan = *(u8 **)(base + 0xA3C);
            while (scan != 0) {
                if (scan == neighbor) { inOpen = 1; goto open_done; }
                scan = *(u8 **)(scan + 0x24);
            }
            inOpen = 0;
open_done:
            scan = *(u8 **)(base + 0xA40);
            while (scan != 0) {
                if (scan == neighbor) { inClosed = 1; goto closed_done; }
                scan = *(u8 **)(scan + 0x28);
            }
            inClosed = 0;
closed_done:
            if ((inOpen != 0 || inClosed != 0) && oldCost <= newCost)
                continue;
            updateEdge = (u8 **)(current + index * 4 + 0x30);
            *(f32 *)(neighbor + 0x1C) = newCost;
            *(f32 *)(*updateEdge + 0x20) = newCost;
            base = iGpffffb3ac;
            neighbor = *updateEdge;
            goalDelta[0] = *(f32 *)(neighbor + 8) - *(f32 *)(base + 0x914);
            goalDelta[1] = *(f32 *)(neighbor + 0xC) - *(f32 *)(base + 0x918);
            distance = func_003e41b0(goalDelta);
            *(f32 *)(*updateEdge + 0x20) = *(f32 *)(*updateEdge + 0x20) + distance;
            *(u8 **)(*updateEdge + 0x2C) = current;
            if (inClosed != 0) {
                remove = *edge;
                previous = 0;
                closedHead = (u8 **)(iGpffffb3ac + 0xA40);
                scan = *closedHead;
                while (scan != 0) {
                    if (scan == remove) break;
                    previous = scan;
                    scan = *(u8 **)(scan + 0x28);
                }
                if (scan != 0) {
                    if (previous != 0)
                        *(u8 **)(previous + 0x28) = *(u8 **)(scan + 0x28);
                    else
                        *closedHead = *(u8 **)(scan + 0x28);
                }
            }
            if (inOpen == 0) {
                updateEdge = (u8 **)(current + index * 4 + 0x30);
                *(u8 **)(*updateEdge + 0x24) = *(u8 **)(iGpffffb3ac + 0xA3C);
                *(u8 **)(iGpffffb3ac + 0xA3C) = *updateEdge;
            }
        }
        *(u8 **)(current + 0x28) = *(u8 **)(iGpffffb3ac + 0xA40);
        *(u8 **)(iGpffffb3ac + 0xA40) = current;
    }
    if (found != 0) {
        func_001ee610(route, radius);
        *(u8 *)(route + 0x404) = 2;
    } else {
        *(u8 *)(route + 0x404) = 3;
    }
    return found;
}
/* measured: closes the opt_propagation bracket opened above. */
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_001e", func_001eed10);
#endif
// FUN_001EF110
/* 904/912 bytes; all eighteen relocations resolve exactly.
   Stage both endpoint loads before either store to preserve overlap. */
#pragma push
#pragma opt_propagation off
s32 func_001ef110(u8 *route, const f32 *startXZ,
                  const f32 *endXZ, const f32 *centerXZ)
{
    P4RouteSlerp_001EF110 interpolation;
    P4Vec4_001EC2B0 rotation;
    P4Vec4_001EC2B0 startRotation;
    P4Vec4_001EC2B0 endRotation;
    f32 center[3];
    f32 endpoint[3];
    f32 direction[3];
    f32 startLength;
    f32 blend;
    f32 lengthDelta;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 square;
    f32 polynomial;
    f32 finalPolynomial;
    f32 length;
    s32 index;

    *(u16 *)(route + 0x400) = 0;
    endpoint[1] = 0.0f;
    center[0] = centerXZ[0];
    center[1] = 0.0f;
    center[2] = centerXZ[1];
    endpoint[0] = startXZ[0];
    endpoint[2] = startXZ[1];
    func_001bd780(&startRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    startLength = func_003e4180(direction);

    endpoint[0] = endXZ[0];
    endpoint[2] = endXZ[1];
    func_001bd780(&endRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    lengthDelta = func_003e4180(direction);
    blend = 0.0f;
    func_003dcc70(&startRotation, &endRotation, &interpolation);
    index = 0;
    lengthDelta = lengthDelta - startLength;
    while (index < 7)
    {
        if (blend <= 0.0f)
        {
            rotation = startRotation;
        }
        else if (1.0f <= blend)
        {
            rotation = endRotation;
        }
        else
        {
            firstWeight = 1.0f - blend;
            secondWeight = blend;
            if (interpolation.mode == 0)
            {
                angle = firstWeight * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                firstWeight = polynomial * finalPolynomial + angle;

                angle = blend * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                secondWeight = polynomial * finalPolynomial + angle;
            }
            rotation.x = interpolation.first.x * firstWeight;
            rotation.y = interpolation.first.y * firstWeight;
            rotation.z = interpolation.first.z * firstWeight;
            rotation.x = interpolation.second.x * secondWeight +
                         (0.0f + rotation.x);
            rotation.y = interpolation.second.y * secondWeight +
                         (0.0f + rotation.y);
            rotation.z = interpolation.second.z * secondWeight +
                         (0.0f + rotation.z);
            rotation.w = interpolation.first.w * firstWeight +
                         interpolation.second.w * secondWeight;
        }
        func_003dcb40(direction, D_0060A0F0, 1, &rotation);
        length = blend * lengthDelta + (0.0f + startLength);
        direction[0] = direction[0] * length;
        direction[1] = direction[1] * length;
        direction[2] = direction[2] * length;
        *(f32 *)(route + index * 8) = center[0] + direction[0];
        *(f32 *)(route + index * 8 + 4) = center[2] + direction[2];
        blend = blend + 0.125f;
        index = index + 1;
    }
    {
        f32 endX = endXZ[0];
        f32 endZ = endXZ[1];
        *(f32 *)(route + 0x38) = endX;
        *(f32 *)(route + 0x3C) = endZ;
    }
    *(u16 *)(route + 0x400) = 8;
    *(u8 *)(route + 0x404) = 2;
    return 1;
}

#pragma pop
// FUN_001EF4A0
s32 func_001ef4a0(s32 arg0)
{
    s32 value;

    value = ((u8 *)iGpffffb3bc)[(arg0 & 0xFFFF) * 4];
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
/* measured: object 224B / window 224B / normalized_diff 0; direct pointer/index locals reproduce retail order. */
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
/* 904/912 bytes; all fifteen relocations resolve exactly. */
s32 func_001ef9c0(u8 *action)
{
    s32 rank;
    u8 *status1Targets[4];
    u8 *status100000Targets[4];
    u8 *status1eTargets[4];
    u8 *node;
    s32 count1;
    s32 count100000;
    s32 count1e;
    u8 *preferred1;
    u8 *preferred100000;
    u8 *preferred1e;
    u8 *actor;
    u16 flags;

    *(s16 *)(action + 0x448) = -1;
    *(u8 **)(action + 0x444) = NULL;
    actor = *(u8 **)(action + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) {
        return 0;
    }
    if (*(u16 *)(actor + 0xA4) == 1) {
        return 0;
    }
    if (func_00232710(*(s32 *)(actor + 0xA64), 0x1001FF) != 0) {
        return 0;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x1000) ||
        *(u16 *)(action + 0x14) == 9) {
        return 0;
    }
    if (func_00243e30(*(u16 **)(*(u8 **)(action + 0x30) + 0xA64)) != 0) {
        return 0;
    }
    rank = func_00107ac0(func_00247cb0(
        *(s16 *)(*(u8 **)(action + 0x30) + 0xA4)) & 0xFFFF) & 0xFFFF;
    count1 = 0;
    count100000 = 0;
    count1e = 0;
    preferred1 = NULL;
    preferred100000 = NULL;
    preferred1e = NULL;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    flags = *(u16 *)(node + 0x1A);
    if ((flags & 1) == 0) goto next;
    if ((flags & 8) == 0) goto next;
    if (node == action) goto next;
    actor = *(u8 **)(node + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) goto next;
    if (rank >= 5) {
        if (func_00232710(*(s32 *)(actor + 0xA64), 1) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1 = node;
            }
            status1Targets[count1] = node;
            count1++;
        } else if (func_00232710(*(s32 *)(actor + 0xA64), 0x100000) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred100000 = node;
            }
            status100000Targets[count100000] = node;
            count100000++;
        }
    }
    if (rank >= 7) {
        if (func_00232710(*(s32 *)(actor + 0xA64), 0x1E) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1e = node;
            }
            status1eTargets[count1e] = node;
            count1e++;
        }
    }
next:
    node = *(u8 **)(node + 0x450);
check:
    if (node != NULL) goto loop;
    if (count100000 == 0 && count1e == 0 && count1 == 0) {
        return 0;
    }
    if (count1 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred1 = preferred1 != NULL ? preferred1 :
            status1Targets[func_00231d70(count1)];
        *(u8 **)(action + 0x444) = preferred1;
        return 1;
    }
    if (count100000 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred100000 = preferred100000 != NULL ? preferred100000 :
            status100000Targets[func_00231d70(count100000)];
        *(u8 **)(action + 0x444) = preferred100000;
        return 1;
    }
    if (count1e != 0) {
        *(s16 *)(action + 0x448) = 0;
        preferred1e = preferred1e != NULL ? preferred1e :
            status1eTargets[func_00231d70(count1e)];
        *(u8 **)(action + 0x444) = preferred1e;
        return 1;
    }
    return 0;
}
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
                (func_00243e30(*(u16 **)(temp_16 + 0xA64)) == 0) &&
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
