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
extern s32 func_0027bf10(s32 arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00107930(s64 arg0);
extern u8 *func_00246c20(s32 arg0);
extern s32 func_00108e10(void);
extern u8 *func_00246830(s32 arg0);
static inline s32 add_retail_ptr(s32 a, s32 b) {
    return a + b;
}
extern void func_0026bc10(s32 arg0, s32 arg1);

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
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270100);
// FUN_00270390
s32 func_00270390(void)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_002e0f20();
    return 0;
}

// FUN_002703D0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_002703d0);
// FUN_002704F0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_002704f0);
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
/* measured: candidate is byte-identical through its 0xE8-byte object;
   remaining residual is one commutative addu operand order and two retail
   tail padding words. Committed at nd 3. */
// FUN_00270780
#ifdef NON_MATCHING
s32 func_00270780(s32 arg0, u8 *arg1) {
    u8 sp30[0x20];
    s32 temp_17;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u32 low;
    s32 key;

    temp_3 = (u8 *)add_retail_ptr(*(s32 *)(arg1 + 0x10), *(s32 *)(arg1 + 0x18));
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
#else
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270780);
#endif
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
/* measured: candidate object is exact in size and differs only in one
   commutative addu operand order. Committed at nd 1. */
// FUN_00270A80
#ifdef NON_MATCHING
s32 func_00270a80(s32 arg0, u8 *arg1) {
    u8 sp30[0x40];
    s32 temp_4;
    s32 var_2;
    s64 temp_17;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *var_2_2;

    temp_3 = (u8 *)*(s32 *)(arg1 + 0x18);
    temp_3 += *(s32 *)(arg1 + 0x10);
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
#else
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270a80);
#endif
// FUN_00270B80
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270b80);
// FUN_00270CA0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270ca0);
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
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027a780);
// FUN_0027A970
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027a970);
// FUN_0027AC50
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027ac50);
// FUN_0027AE90
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027ae90);
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
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b310);
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