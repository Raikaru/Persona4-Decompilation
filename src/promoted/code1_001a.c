#include "include_asm.h"
#include "type.h"

void btlActionSetState(u8 *arg0, u16 arg1);
u8 *func_00193bf0(u64 arg0, u64 arg1);
void func_001b0800();
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void func_001f6cd0(void);

void func_001f14f0(void *arg0);
void func_001eb3b0(u8 *arg0);
u8 func_001d7f10(void *arg0, u8 *arg1, u16 arg2, u32 arg3);
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
void func_001d8cb0(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void func_001a03b0(s64 *arg0);
void func_001dbf20(void *arg0, s32 arg1);
u8 *func_001d3700(u16 arg0, u16 arg1);
s64 func_00194590(u8 *arg0, u32 arg1);
extern u8 *D_0076449C;
extern u8 *func_0019b6a0(s32 arg0);
u8 *btlCameraCreateSetStatePacket(void *arg0, s32 arg1);
u32 func_001deeb0(void *arg0);
void func_001ded30();
u32 func_001deee0();
s16 func_0023dfe0(s32 arg0);
u32 func_001d8bc0(void *arg0);
void func_001d8be0(u8 *arg0, s32 arg1);
u8 *func_001f5f70(u8 *arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern u8 *iGpffffb3b8;
void func_001d8e50(u8 *arg0, u8 *arg1);
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
void func_00212010(s32 arg0);
void func_0019faf0(u8 *arg0);
s32 func_0023e1f0();
u8 *func_0019e550(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_001bc920(u8 *arg0, s32 arg1);
u8 *func_0019a0c0(u8 *arg0, s16 arg1);
u8 *func_0019e7c0(s32 arg0, s32 arg1);
u8 *func_001ba090(s32 arg0);
u8 *func_001d7a10(u16 arg0);
u8 *func_00201f20(void);
s32 func_002428f0(u8 *arg0, s32 arg1);
u8 *func_001fa720(u8 *arg0);
s32 func_001eb860(void);
void *func_00218420(void *arg0, void *arg1);
u8 *func_001fa8f0(void);
s32 func_002184a0(void *arg0);
s32 func_002184d0(void *arg0);
u8 *func_001faa60(void);
void func_00218500(void *arg0);
void func_00212240(s32 arg0, s32 arg1);
s32 func_0019ff60(u8 *arg0);
s64 *func_001b1540(void);
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
s32 func_001f01a0(u8 *arg0, s32 arg1);
s32 func_0023d8e0(u8 *arg0, s32 arg1);
u8 *func_001fa9c0(void);
s32 func_001db5e0(u8 *arg0, s64 arg1);
u32 func_00193cd0(u32 arg0);
u8 *func_001fa110(s16 *arg0);
u8 *func_00202850(void);
void func_002182c0(u8 *arg0, u8 *arg1);
u8 *func_00198300(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00194c90(s32 arg0, s32 arg1);
u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
s32 func_00218360(s32 arg0);
s32 func_00218390(s32 arg0);
u8 *func_001f99c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *func_001fa450(void);
u8 *func_002027e0(void);
u8 *func_001f3870(s64 *arg0, s8 arg1);
void func_002183c0(s32 arg0);
s64 func_001d15a0(s32 arg0);
void func_001eb7f0(void);
s32 func_001ef720(s32 arg0, s32 arg1);
s32 func_001fabe0(u8 *arg0);
void func_0022db90(u8 *arg0);
s32 func_00232710(u8 *arg0, s32 arg1);
s32 func_00232d80(u8 *arg0);
s64 func_00235320(u8 *arg0);
s32 func_00243e30(u16 *arg0);
s32 func_001f6770(u8 *arg0);
s32 func_001fac30(void);
s32 func_001a3de0(u8 *arg0);

void func_002022e0(u32 arg0, u16 arg1);
extern u8 *func_00199ee0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
s32 func_0010b300(s32 arg0);
extern void func_0019ef30(u8 *arg0, u16 arg1);
extern void func_0010b7f0(void);
extern s32 func_00106330(s32 arg0);
void func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
void func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;
s32 func_001fac80(u8 *arg0);
void func_001fad10(void);



// FUN_001A0140
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
#pragma opt_loop_invariants on
s32 func_001a0140(u8 *arg0)
{
    s32 i0;
    u8 temp_3;

    temp_3 = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (temp_3) {
    case 0:
    {
        s32 j0;
        s32 n0;
        s32 count0;
        s32 mask0;
        u8 *target0;

        i0 = 0;
        n0 = *(u16 *)(arg0 + 0x6A);
        mask0 = 0x100000;
        goto outer0_test;
outer0_body:
        target0 = *(u8 **)(arg0 + ((u16)i0 * 4) + 0x38);
        count0 = target0[0xD9];
        j0 = 0;
        goto inner0_test;
inner0_body:
        if ((*(s32 *)(target0 + ((u16)j0 << 5) + 0xF8) & mask0) != 0) {
            return 1;
        }
        j0 = (j0 + 1) & 0xFFFF;
inner0_test:
        if ((j0 & 0xFFFF) < count0) {
            goto inner0_body;
        }
        i0 = (i0 + 1) & 0xFFFF;
outer0_test:
        if ((i0 & 0xFFFF) >= n0) {
            goto block_20;
        }
        goto outer0_body;
    }
    case 1:
    {
        s32 i1;
        s32 j1;
        s32 n1;
        s32 count1;
        u8 *target1;

        i1 = 0;
        n1 = *(u16 *)(arg0 + 0x6A);
        goto outer1_test;
outer1_body:
        target1 = *(u8 **)(arg0 + ((u16)i1 * 4) + 0x38);
        count1 = target1[0xD9];
        j1 = 0;
        goto inner1_test;
inner1_body:
        if ((*(u16 *)(target1 + ((u16)j1 << 5) + 0x10E) & 4) != 0) {
            return 1;
        }
        j1 = (j1 + 1) & 0xFFFF;
inner1_test:
        if ((j1 & 0xFFFF) < count1) {
            goto inner1_body;
        }
        i1 = (i1 + 1) & 0xFFFF;
outer1_test:
        if ((i1 & 0xFFFF) < n1) {
            goto outer1_body;
        }
        goto block_20;
    }
    default:
        goto block_20;
    }
block_20:
    return 0;
}
/* measured: close loop-invariant probe for 001A0140. */
#pragma opt_loop_invariants off
// FUN_001A0290
void func_001a0290(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 temp_5;
    s32 temp_3;
    u8 *temp_4;

    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s16 *)arg2 = 0x24;
        *(s16 *)(arg2 + 2) = -1;
        return;
    }
    *(s16 *)arg2 = 0;
    *(s16 *)(arg2 + 2) = 3;
    temp_5 = (arg1 & 0xFFFF) * 0x28;
    if (*(u8 *)(iGpffffb3b8 + temp_5) & 2) {
        temp_4 = *(u8 **)(arg0 + 0x30);
        if (temp_4[0xA2] == 0) {
            temp_3 = func_0023e1f0(*(u8 **)(temp_4 + 0xA64), temp_5) & 0xFF;
            switch (temp_3) {
            case 0:
            case 1:
            case 6:
                *(s16 *)arg2 = 1;
                *(s16 *)(arg2 + 2) = 4;
                return;
            case 5:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                return;
            case 2:
            case 3:
            case 4:
                break;
            }
        } else {
            switch (*(u16 *)(temp_4 + 0xA4)) {
            case 0x109:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                break;
            }
        }
    }
}
// FUN_001A03B0
void func_001a03b0(s64 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *var_16;

    temp_5 = D_0076449C;
    if (*(s32 *)(temp_5 + 0xC) & 0x400000) {
        if (*(u16 *)(temp_5 + 0x18) & 0x20) {
            temp_2 = func_0019e7c0(0, 3);
            *(s64 *)(temp_2 + 0x60) = *arg0;
            func_00194590(temp_2, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 2) {
            temp_2_2 = func_001d3700(3, 0xFFF);
            *(s64 *)(temp_2_2 + 0x60) = *arg0;
            func_00194590(temp_2_2, 0);
        }
        temp_4 = D_0076449C;
        if (*(u16 *)(temp_4 + 0x18) & 1) {
            var_16 = *(u8 **)(temp_4 + 0x174);
            goto loop_test;
loop_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) &&
                func_002428f0(*(u8 **)(*(u8 **)(var_16 + 0x30) + 0xA64), 0) == 0) {
                temp_2_3 = func_0019a0c0(*(u8 **)(var_16 + 0x30), 0);
                *(s64 *)(temp_2_3 + 0x60) = *arg0;
                func_00194590(temp_2_3, 0);
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_test:
            if (var_16 != NULL) {
                goto loop_body;
            }
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x10) {
            temp_2_4 = func_001ba090(0);
            *(s64 *)(temp_2_4 + 0x60) = *arg0;
            func_00194590(temp_2_4, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 8) {
            temp_2_5 = func_001d7a10(5);
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 4) {
            temp_2_6 = func_001bc920((u8 *)arg0, 0x24);
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 0);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x40) {
            temp_2_7 = func_00201f20();
            *(s64 *)(temp_2_7 + 0x60) = *arg0;
            func_00194590(temp_2_7, 0);
        }
        *(u16 *)(D_0076449C + 0x18) = 0;
        temp_5_2 = D_0076449C;
        *(s32 *)(temp_5_2 + 0xC) &= 0xFFBFFFFF;
    }
}
// FUN_001A05F0
s32 func_001a05f0(u8 *arg0) {
    u16 temp_5;
    u8 *temp_3;

    temp_5 = *(u16 *)(arg0 + 0x1A);
    if (temp_5 & 1) {
        goto cont1;
    }
    return 0;
cont1:
    temp_3 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C);
    if (temp_5 & 0x10) {
        goto cont2;
    }
    return 0;
cont2:
    return (*(s32 *)(temp_3 + 0x98) & 2) != 0;
}



// FUN_001A0640
void func_001a0640(void)
{
}

// FUN_001A0650
void func_001a0650(void)
{
}

// FUN_001A0660
void func_001a0660(void)
{
}

// FUN_001A0670
void func_001a0670(u8 *arg0) {
    s32 temp_5;

    temp_5 = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C);
    if (temp_5 & 0x10) {
        *(s16 *)(arg0 + 0x430) = 1;
        btlActionSetState(arg0, 0x18);
        return;
    }
    if (temp_5 & 1) {
        btlActionSetState(arg0, 0x23);
    }
}



// FUN_001A06D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a06d0);
// FUN_001A0B00
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0b00);
// FUN_001A0F40
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a0f40);
// FUN_001A1450
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1450);
// FUN_001A17D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a17d0);
// FUN_001A1C80
void func_001a1c80(u8 *arg0)
{
    u8 *var_17;
    s32 var_16;
    u8 temp_3;
    u8 *temp_2;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 4:
        func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
        var_16 = func_001a_fix_var(*(u16 *)(arg0 + 0x6E));
        break;
    default:
        var_16 = *(u16 *)(arg0 + 0x6E);
        temp_3 = *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                               (u32)iGpffffb3b8) + 8);
        switch (temp_3) {
        case 1:
        case 2:
            {
                extern void func_001d7c60(
                    u8 *arg0, u8 *arg1, u8 arg2, u8 arg3, u32 arg4);
                func_001d7c60(
                    arg0,
                    arg0 + 0x98,
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 9),
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 0xA),
                    0);
            }
            break;
        default:
            func_001d7f10(arg0, arg0 + 0x98, var_16 & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    func_001d8cb0(arg0, arg0 + 0x98);
    temp_3 = *(u8 *)(func_001a_add_offset(
        *(u16 *)(arg0 + 0x6E) * 0x28, (u32)iGpffffb3b8) + 8);
    switch (temp_3) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    var_17 = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    func_001d8e50(arg0, arg0 + 0x98);
after_type_1c80:
    func_0020b6d0(
        *(s32 *)(D_0076449C + 0xDD4),
        arg0,
        arg0 + 0x98,
        (s64)(s16)var_16);
    temp_2 = func_001bc920(arg0, 0x22);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    func_00212010(*(s32 *)(D_0076449C + 0xDD4));
    func_0019faf0(arg0);
    if (var_17 != NULL) {
        temp_2 = func_0019e550(NULL, *(u8 **)(var_17 + 0x30), 1);
        func_00194590(temp_2, 1);
        temp_2 = func_0019e7c0(*(s32 *)(var_17 + 0x30), 0);
        func_00194590(temp_2, 1);
    }
}
// FUN_001A1EA0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a1ea0);
// FUN_001A24A0
void func_001a24a0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x41c) = 1;
}
// FUN_001A24B0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a24b0);
// FUN_001A2AD0
void func_001a2ad0(u8 *arg0) {
    func_001eb3b0(arg0 + 0x38);
    if ((*(s32 *)(D_0076449C + 0xC) & 0x1000) == 0) {
        return;
    }
    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return;
    }
    if (*(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return;
    }
    func_001b0800(arg0, 9);
}

// FUN_001A2B50
void func_001a2b50(u8 *arg0)
{
    s32 temp_3;

    if (func_001deeb0(arg0 + 0x38) == 0) {
        func_001ded30(arg0, arg0 + 0x38);
    }
    if (func_001deee0(arg0 + 0x38) != 0) {
        temp_3 = *(s32 *)(D_0076449C + 0xC);
        if ((temp_3 & 0x1000) &&
            (temp_3 & 0x04000000) &&
            (*(u8 **)(arg0 + 0x30))[0xA2] == 1) {
            *(u16 *)(arg0 + 0x18) |= 0x4000;
        }
        *(u16 *)(arg0 + 0x18) |= 2;
        func_001b0800(arg0, 0xF);
    }
}
// FUN_001A2C10
void func_001a2c10(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001d7f10(arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}



// FUN_001A2C70
void func_001a2c70(u8 *arg0)
{
    u8 *temp_3;

    *(s16 *)(arg0 + 0x6C) = 1;
    *(s16 *)(arg0 + 0x6E) =
        func_0023dfe0(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64));
    *(s32 *)(arg0 + 0x38) = func_001d8bc0(arg0 + 0x98);
    *(s16 *)(arg0 + 0x6A) = 1;
    func_001d8be0(arg0 + 0x98, *(s32 *)(arg0 + 0x38));
    temp_3 = *(u8 **)(arg0 + 0x30);
    if ((temp_3[0xA2] == 0) && (*(u16 *)(temp_3 + 0xA4) == 1)) {
        func_00194590(func_001f5f70(arg0, 1, 0, 0, 0), 1);
    }
    if (*(s32 *)(D_0076449C + 0xC) & 0x04000000) {
        *(u16 *)(arg0 + 0x18) |= 0x4000;
    }
    *(u16 *)(arg0 + 0x18) |= 2;
    func_001b0800(arg0, 0xF);
}
// FUN_001A2D60
void func_001a2d60(void)
{
}
// FUN_001A2D70
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a2d70);
// FUN_001A31A0
void func_001a31a0(u8 *arg0)
{
    func_001f6cd0();
    *(s32 *)(arg0 + 0x41C) = 1;
    *(s32 *)(arg0 + 0x420) = 0;
}
// FUN_001A31E0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a31e0);
// FUN_001A3840
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a3840);
// FUN_001A3D50
void func_001a3d50(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        *(s16 *)((u8 *)arg0 + 0x448) = -1;
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        func_001b0800(arg0, 0x20);
    }
}
// FUN_001A3DE0
s32 func_001a3de0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x420);
}

// FUN_001A3DF0
void func_001a3df0(u8 *arg0)
{
    s32 status;
    u8 *iter;
    u8 *temp;
    s64 *current;

    iter = *(u8 **)(D_0076449C + 0x174);
    goto loop_test;
loop_body:
    if (func_001a05f0(iter) != 0) {
        temp = func_0019b6a0((s32)*(u8 **)(*(u8 **)(iter + 0x30) + 0xA0C));
        *(s64 *)(temp + 0x60) = *(s64 *)iter;
        func_00194590(temp, 1);
    }
    iter = *(u8 **)(iter + 0x450);
loop_test:
    if (iter != NULL) {
        goto loop_body;
    }
    status = 1;
    current = func_001b1540();
    if ((*(u16 *)((u8 *)current + 0x18) & 8) != 0 &&
        func_0019ff60((u8 *)current) != 0) {
        status = 0;
    }
    if (status == 1) {
        status = func_001d94d0(
            arg0,
            func_0023d8e0(
                *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64),
                func_001f01a0(arg0, *(s32 *)(arg0 + 0x90)) & 0xFFFF) & 0xFFFF,
            2, 0x80000, 2, func_001db5e0);
    }
    if (status == 0) {
        temp = func_001fa9c0();
        *(s64 *)(temp + 0x60) = *(s64 *)arg0;
        func_00194590(temp, 1);
        func_001b0800(arg0, 0x20);
        return;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(s32 *)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
    *(s32 *)(arg0 + 0x420) = 0;
}
// FUN_001A3F90
void func_001a3f90(u8 *arg0)
{
    u8 frame[0x10];
    struct {
        u8 pad[0x30];
        s32 field_30;
    } *temp_2;
    s64 *temp_2_4;
    u16 temp_3_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_3;

    if (*(s32 *)(arg0 + 0x41C) == 0) {
        if ((func_00193cd0(0xC00) == 0) && (func_00193cd0(0xC04) == 0)) {
            *(s16 *)(frame + 0) = 2;
            *(u16 *)(frame + 2) =
                *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
            func_00194590(func_001fa110((s16 *)frame), 1);
            func_001a03b0((s64 *)arg0);
            func_00194590(func_00202850(), 1);
            func_00194590(func_001fa8f0(), 1);
            func_002182c0(*(u8 **)(D_0076449C + 0xDD4), (u8 *)arg0);
            func_00194590(func_001d3700(3, 0xFFF), 0);
            temp_2 = (void *)func_001b1540();
            func_00194590(
                func_00198300((u8 *)temp_2->field_30,
                              *(u8 **)(arg0 + 0x30), 2),
                0);
            func_00194590(
                func_00198300(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 2),
                0);
            func_00194590(
                func_0019e7c0(temp_2->field_30, 0),
                1);
            func_00194590(
                func_0019e550(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 0),
                1);
            func_00194590(func_001bc920((u8 *)arg0, 0x30), 0);
            temp_2_2 = func_00194c90((s32)func_001a3de0, (s32)arg0);
            func_00194590(temp_2_2, 1);
            func_00194590(
                func_001d65d0(*(s32 *)(D_0076449C + 0xD90),
                              *(s32 *)(arg0 + 0x30), 0,
                              *(s64 *)(temp_2_2 + 0x58), 0xC000),
                2);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                func_00212240(*(s32 *)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    } else if (*(s32 *)(arg0 + 0x420) == 0) {
        if (func_00218360(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
                func_00194590(func_001f99c0((u8 *)arg0, 8, 0, 0, 0), 1);
                temp_2_3 = func_001fa450();
                *(s8 *)(temp_2_3 + 0) = 0xA;
                *(s16 *)(temp_2_3 + 8) = 0xC00;
                *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_3, 1);
                func_00194590(func_002027e0(), 1);
            }
            func_00194590(func_001faa60(), 1);
            *(s32 *)(arg0 + 0x420) = 1;
            *(u16 *)(arg0 + 0x424) = 6;
        }
    } else {
        temp_3_2 = *(u16 *)(arg0 + 0x424);
        if (temp_3_2 == 0) {
            func_00194590(func_0019e7c0(0, 3), 1);
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
                temp_2_4 = func_001b1540();
                func_00194590(func_001f3870(temp_2_4, 2), 1);
                *(u16 *)((u8 *)temp_2_4 + 0x18) |= 0x8000;
                func_001b0800((u8 *)arg0, 0xE);
            } else {
                func_001b0800((u8 *)arg0, 0x20);
            }
            func_002183c0(*(s32 *)(D_0076449C + 0xDD4));
            return;
        }
        *(u16 *)(arg0 + 0x424) = temp_3_2 - 1;
    }
}
// FUN_001A4390
void func_001a4390(void)
{
}

// FUN_001A43A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a43a0);
// FUN_001A47F0
void func_001a47f0(void)
{
}

// FUN_001A4800
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4800);
// FUN_001A4C80
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a4c80);
// FUN_001A55A0
void func_001a55a0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



// FUN_001A5650
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a5650);
// FUN_001A58E0
void func_001a58e0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((u8 *)arg0, var_5);
    }
}



// FUN_001A5990
void func_001a5990(void)
{
}

// FUN_001A59A0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a59a0);
// FUN_001A7710
void func_001a7710(void)
{
}

// FUN_001A7720
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a7720);
// FUN_001ABBA0
void func_001abba0(void)
{
}
// FUN_001ABBB0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001abbb0);
// FUN_001AC500
void func_001ac500(s64 *arg0) {
    u8 *temp_2;
    u8 *temp_2_2;

    func_001a03b0(arg0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001dbf20(arg0, 0);
    func_001a03b0(arg0);
    temp_2 = func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = btlCameraCreateSetStatePacket(arg0, 0x2C);
    *(s64 *)(temp_2_2 + 0x60) = *arg0;
    func_00194590(temp_2_2, 0);
    *(u16 *)((u8 *)arg0 + 0x18) |= 2;
}



// FUN_001AC5B0
void func_001ac5b0(s64 *arg0) {
    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x800) == 0)) {
        *(u16 *)((u8 *)(arg0) + 0x18) = (u16) (*(u16 *)((u8 *)(arg0) + 0x18) | 0x100);
        func_001b0800(arg0, 0xFU);
    }
}

// FUN_001AC620
void func_001ac620(void) {
    u8 *p = *(u8 **)(D_0076449C + 0x174);
    u8 *o;

    while (p != NULL) {
        if (func_001a05f0(p) != 0) {
            o = func_0019b6a0(*(s32 *)(*(u8 **)(p + 0x30) + 0xA0C));
            *(s64 *)(o + 0x60) = *(s64 *)p;
            func_00194590(o, 1);
        }
        p = *(u8 **)(p + 0x450);
    }
}

// FUN_001AC6A0
void func_001ac6a0(u8 *arg0) {
    if ((*(s32 (**)(void))(arg0 + 0x440))() == 0) {
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x43C));
    }
}

// FUN_001AC6F0
void func_001ac6f0(void)
{
}
// FUN_001AC700
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ac700);
// FUN_001ACB10
void func_001acb10(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_5_4;

    temp_5 = *(u16 *)(arg0 + 0x3F4);
    switch (temp_5) {
    case 0x20F:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x400;
        break;
    case 0x210:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x800;
        break;
    }
    if (*(u16 *)(arg0 + 0x3F4) == 0) {
        temp_5_4 = *(u8 **)(arg0 + 0x30);
        *(s32 *)(temp_5_4 + 0x9C) = *(s32 *)(temp_5_4 + 0x9C) & ~0x10;
        func_001b0800(arg0, *(u16 *)(arg0 + 0x430));
    }
}
// FUN_001ACBB0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acbb0);
// FUN_001ACF40
void func_001acf40(void)
{
}
// FUN_001ACF50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001acf50);
// FUN_001AD280
void func_001ad280(u8 *arg0)
{
    s16 sp20[8];
    u8 *temp_2;

    func_001a03b0((s64 *)arg0);
    temp_2 = func_0019e550(
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        *(u8 **)(arg0 + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    temp_2 = func_0019e550(
        *(u8 **)(arg0 + 0x30),
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    *(u16 *)(arg0 + 0x18) |= 0x200;
    temp_2 = func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    temp_2 = func_001bc920(arg0, 9);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    sp20[0] = 5;
    temp_2 = func_001fa720((u8 *)&sp20[0]);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(s32 *)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
}
// FUN_001AD3E0
void func_001ad3e0(u8 *arg0)
{
    u8 *temp;

    if (*(s32 *)(arg0 + 0x41C) != 0) {
        goto common;
    }
    if (func_00193bf0(*(s64 *)arg0, 0x3FFFFFFFFFFFFFFFLL) != 0) {
        goto done;
    }
    func_00218420(*(u8 **)(D_0076449C + 0xDD4), arg0);
    temp = func_001fa8f0();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    *(s32 *)(arg0 + 0x41C) = 1;
common:
    if (func_002184a0(*(u8 **)(D_0076449C + 0xDD4)) == 0) {
        goto done;
    }
    if (func_001eb860() != 1) {
        goto after_flag;
    }
    *(s32 *)(D_0076449C + 0xC) |= 0x2000;
    func_00212240(*(s32 *)(D_0076449C + 0xDD4), 1);
after_flag:
    if (func_002184d0(*(u8 **)(D_0076449C + 0xDD4)) != 0) {
        goto alternate;
    }
    func_001b0800(arg0, 0x1D);
    goto after_state;
alternate:
    func_001b0800(arg0, 0x20);
after_state:
    temp = func_001faa60();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    func_00218500(*(u8 **)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001AD540
void func_001ad540(void)
{
}
// FUN_001AD550
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ad550);
// FUN_001ADB80
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001adb80);
// FUN_001ADE10
void func_001ade10(s64 *arg0)
{
    void func_001b0800(u8 *arg0, u16 arg1);

    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
            *(u16 *)((u8 *)arg0 + 0x18) &= 0xFBFF;
        }
        func_001b0800((u8 *)arg0, *(u16 *)((u8 *)arg0 + 0x14));
    }
}
// FUN_001ADE90
void func_001ade90(void)
{
}
// FUN_001ADEA0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001adea0);
// FUN_001AE3C0
s32 func_001ae3c0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x428);
}
// FUN_001AE3D0
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae3d0);
// FUN_001AE800
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001ae800);
// FUN_001AEC20
void func_001aec20(u8 *arg0)
{
    s32 temp_3_3;
    s32 var_4;
    s32 var_6;
    s32 var_5;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_3_2;

    func_001eb3b0(arg0 + 0x38);
    func_001d7f10(arg0, arg0 + 0x98, 0x100, 0);
    var_4 = 0;
    goto loop_2_test;
loop_2_body:
    temp_3_2 = arg0 + ((u16)var_4 * 4);
    *(s32 *)(temp_3_2 + 0x38) = *(s32 *)(temp_3_2 + 0x98);
    var_4 = (var_4 + 1) & 0xFFFF;
loop_2_test:
    temp_3 = *(u16 *)(arg0 + 0xD0);
    if ((var_4 & 0xFFFF) < temp_3) {
        goto loop_2_body;
    }
    *(u16 *)(arg0 + 0x6A) = temp_3;
    *(s16 *)(arg0 + 0x6C) = 2;
    *(s16 *)(arg0 + 0x6E) = 0x100;
    func_001f14f0(arg0);
    var_6 = 0;
    var_5 = 0;
    temp_4 = *(u16 *)(arg0 + 0x6A);
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)var_5 * 4) + 0x38) + 0xE0) != 0) {
        var_6 = (var_6 + 1) & 0xFFFF;
    }
    var_5 = (var_5 + 1) & 0xFFFF;
loop_7_test:
    if ((var_5 & 0xFFFF) < temp_4) {
        goto loop_7_body;
    }
    temp_3_3 = var_6 & 0xFFFF;
    if (temp_4 == temp_3_3) {
        *(s16 *)(arg0 + 0x6E) = 0x102;
        return;
    }
    if (temp_3_3 != 0) {
        *(s16 *)(arg0 + 0x6E) = 0x100;
        return;
    }
    *(s16 *)(arg0 + 0x6E) = 0x101;
}
// FUN_001AED50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001aed50);
// FUN_001AF9D0
void func_001af9d0(void)
{
}
// FUN_001AF9E0
void func_001af9e0(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        func_001b0800(arg0, 0x21U);
    }
}
// FUN_001AFA50
void func_001afa50(u8 *arg0)
{
    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 6;
        *(u16 *)(arg0 + 0x18) &= 0xBFFF;
    }
    *(u16 *)(arg0 + 0x18) &= 0xFEFF;
    if (*(u16 *)(arg0 + 0x18) & 0x200) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 0x20;
        *(u16 *)(arg0 + 0x18) &= 0xFDFF;
    }
    if (func_001fac80(arg0) != 0) {
        *(void (**)(void))(arg0 + 0x440) = func_001fad10;
        *(s16 *)(arg0 + 0x43C) = 0x21;
        func_001b0800(arg0, 0x16);
        return;
    }
    *(u16 *)(arg0 + 0x18) &= 0xC7FF;
}
// FUN_001AFB50
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001afb50);