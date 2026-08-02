/* Consolidated Persona 4 source units. */
/* Original translation unit sdkListState.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void func_0046d730(void* message, u32 code);
extern s32 func_00453eb0(u8* obj, s32 value);
extern void func_00453ce0(u8* arg0, s32 arg1);
extern void func_0043f9c8(void* dst, s32 value, u32 size);
extern void func_00453670(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00453760(u8* arg0, s32 arg1);
extern void func_004537e0(u8* arg0, s32 arg1);
extern void func_00454040(u8* arg0);
extern void func_00454090(u8* arg0);
extern s32 func_004540e0(u8* arg0);
extern s32 func_00454250(u8* arg0);
extern s32 func_004543d0(u8* arg0);
extern s32 func_00454460(u8* arg0);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern u16 D_008C0274[];
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u32 D_007105E8[];



// FUN_004535C0
void func_004535c0(u8* arg0, s32 arg1, s32 arg2)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x45);
    }
    if (arg1 <= 0) {
        func_0046d730(D_007105E8, 0x46);
    }
    func_0043f9c8(arg0, 0, 0x2C);
    func_00453670(arg0, arg1, arg2, 0, 0);
}

// FUN_00453670
void func_00453670(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x4F);
    }
    if (arg1 <= 0) {
        func_0046d730(D_007105E8, 0x50);
    }
    func_0043f9c8(arg0, 0, 0x2C);
    *(s32*)(arg0 + 0x14) = arg1;
    *(s32*)(arg0 + 0x18) = 2;
    *(s32*)(arg0 + 0x20) = arg2;
    *(s32*)(arg0 + 0x24) = arg3;
    *(s32*)(arg0 + 0x28) = arg4;
    *(s32*)(arg0 + 0x1C) = arg1;
    if (arg1 < 0) {
        *(s32*)(arg0 + 0x1C) = 0;
    }
    func_00453760(arg0, 1);
    func_004537e0(arg0, 1);
}

// FUN_00453760
void func_00453760(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x62);
    }
    if (arg1) {
        *(s32*)(arg0 + 0x0) |= 2;
    } else {
        *(s32*)(arg0 + 0x0) &= ~2;
    }
}

// FUN_004537E0
void func_004537e0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x6F);
    }
    if (arg1) {
        *(s32*)(arg0 + 0x0) |= 4;
    } else {
        *(s32*)(arg0 + 0x0) &= ~4;
    }
}

// FUN_00453860
void func_00453860(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x7A);
    }
    *(s16*)(arg0 + 0x4) = arg1;
    *(s16*)(arg0 + 0x6) = arg2;
    *(s16*)(arg0 + 0x8) = arg3;
    *(s16*)(arg0 + 0xA) = arg4;
}

// FUN_004538E0
void func_004538e0(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x85);
    }
    *(s16*)(arg0 + 0xC) = arg1;
    *(s16*)(arg0 + 0xE) = arg2;
    *(s16*)(arg0 + 0x10) = arg3;
    *(s16*)(arg0 + 0x12) = arg4;
}

// FUN_00453960
s32 func_00453960(u8* arg0)
{
    s32 result;
    s32 f4;
    s32 fC;
    s32 f6;
    s32 fE;
    s32 f8;
    s32 fA;
    result = 0;
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x91);
    }
    if (*(s32*)(arg0 + 0x0) & 2) {
        func_00454040(arg0);
    }
    f4 = *(u16*)(arg0 + 0x4);
    if ((D_008C024E[0] & f4) || (fC = *(u16*)(arg0 + 0xC), (D_008C0276[0] & fC) != 0)) {
        if ((*(s32*)(arg0 + 0x0) & 4) || (*(s32*)(arg0 + 0x20) - 1 != *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24))) {
            func_00454090(arg0);
        }
        if (func_004540e0(arg0) != 0) {
            result = 1;
        }
        goto done;
    }
    f6 = *(u16*)(arg0 + 0x6);
    if ((D_008C024E[0] & f6) || (fE = *(u16*)(arg0 + 0xE), (D_008C0276[0] & fE) != 0)) {
        if ((*(s32*)(arg0 + 0x0) & 4) || (*(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24) != 0)) {
            func_00454090(arg0);
        }
        if (func_00454250(arg0) != 0) {
            result = 2;
        }
        goto done;
    }
    f8 = *(u16*)(arg0 + 0x8);
    if ((D_008C024C[0] & f8) || (D_008C0274[0] & *(u16*)(arg0 + 0x10))) {
        if (((D_008C0252[0] & f8) || (D_008C027A[0] & *(u16*)(arg0 + 0x10))) && func_004543d0(arg0) != 0) {
            result = 3;
        }
        goto done;
    }
    fA = *(u16*)(arg0 + 0xA);
    if ((D_008C024C[0] & fA) || (D_008C0274[0] & *(u16*)(arg0 + 0x12))) {
        if (((D_008C0252[0] & fA) || (D_008C027A[0] & *(u16*)(arg0 + 0x12))) && func_00454460(arg0) != 0) {
            result = 4;
        }
        goto done;
    }
    if ((D_008C024C[0] & f4) || (D_008C0274[0] & fC)) {
        if (((D_008C0252[0] & f4) || (D_008C027A[0] & fC)) && func_004540e0(arg0) != 0) {
            result = 1;
        }
        goto done;
    }
    if ((D_008C024C[0] & f6) || (D_008C0274[0] & fE)) {
        if (((D_008C0252[0] & f6) || (D_008C027A[0] & fE)) && func_00454250(arg0) != 0) {
            result = 2;
        }
        goto done;
    }
    return 0;
done:
    return result;
}

// FUN_00453C80
void func_00453c80(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0xD7);
    }
    func_00453ce0(arg0, *(s32*)(arg0 + 0x20) + 1);
}
// FUN_00453CE0
void func_00453ce0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0xF4);
    }
    if (arg1 < *(s32*)(arg0 + 0x20)) {
        *(s32*)(arg0 + 0x20) = arg1;
        func_00453eb0(arg0, *(s32*)(arg0 + 0x28) + *(s32*)(arg0 + 0x24));
        return;
    }
    *(s32*)(arg0 + 0x20) = arg1;
}



// FUN_00453D70
s32 func_00453d70(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x101);
    }
    return *(s32*)(arg0 + 0x28);
}



// FUN_00453DC0
s32 func_00453dc0(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x108);
    }
    return *(s32*)(arg0 + 0x24);
}



// FUN_00453E10
s32 func_00453e10(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x10F);
    }
    return *(s32*)(arg0 + 0x20);
}



// FUN_00453E60
s32 func_00453e60(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x116);
    }
    return *(s32*)(arg0 + 0x14);
}

// FUN_00453EB0
s32 func_00453eb0(u8* arg0, s32 arg1)
{
    s32 hi;
    s32 diff;
    s32 v2;
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x125);
    }
    if (*(s32*)(arg0 + 0x20) == 0) {
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        return 1;
    }
    if (arg1 <= 0) {
        arg1 = 0;
    } else if (*(s32*)(arg0 + 0x20) < arg1) {
        arg1 = *(s32*)(arg0 + 0x20) - 1;
    }
    if (arg1 - *(s32*)(arg0 + 0x24) >= 0) {
        hi = *(s32*)(arg0 + 0x14);
        if (*(s32*)(arg0 + 0x20) < hi) {
            hi = *(s32*)(arg0 + 0x20);
        }
        diff = arg1 - *(s32*)(arg0 + 0x24);
        *(s32*)(arg0 + 0x28) = diff;
        v2 = *(s32*)(arg0 + 0x20) - hi;
        if (v2 < diff) {
            *(s32*)(arg0 + 0x28) = v2;
            *(s32*)(arg0 + 0x24) = arg1 - v2;
        }
    } else {
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = arg1;
    }
    return 1;
}

// FUN_00453FA0
void func_00453fa0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x144);
    }
    *(s32*)(arg0 + 0x14) = arg1;
}

// FUN_00453FF0
void func_00453ff0(u8* arg0, s32 arg1)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x14C);
    }
    *(s32*)(arg0 + 0x18) = arg1;
}

// FUN_00454040
void func_00454040(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x154);
    }
    *(s32*)(arg0 + 0x0) |= 1;
}

// FUN_00454090
void func_00454090(u8* arg0)
{
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x15B);
    }
    *(s32*)(arg0 + 0x0) &= ~1;
}

// FUN_004540E0
s32 func_004540e0(u8* arg0)
{
    s32 cur;
    s32 hi;
    s32 pos;
    s32 v2;
    s32 v4;
    s32 v3;
    s32 flag;
    cur = *(s32*)(arg0 + 0x20);
    if (cur < 2) {
        return 0;
    }
    hi = *(s32*)(arg0 + 0x14);
    v2 = hi - *(s32*)(arg0 + 0x18);
    if (v2 <= 0) {
        v2 = 1;
    }
    pos = *(s32*)(arg0 + 0x24);
    v4 = pos + 1;
    if (v4 < v2) {
        if (v4 < cur) {
            *(s32*)(arg0 + 0x24) = v4;
            goto done;
        }
        if (arg0 == NULL) {
            func_0046d730(D_007105E8, 0x163);
        }
        flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
        if (!flag) {
            *(s32*)(arg0 + 0x24) = 0;
            *(s32*)(arg0 + 0x28) = 0;
            goto done;
        }
        return 0;
    }
    v3 = *(s32*)(arg0 + 0x28);
    if (v3 + hi < cur) {
        *(s32*)(arg0 + 0x28) = v3 + 1;
        goto done;
    }
    if (v3 + pos < cur - 1) {
        *(s32*)(arg0 + 0x24) = v4;
        goto done;
    }
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x163);
    }
    flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
    if (!flag) {
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        goto done;
    }
    return 0;
done:
    return 1;
}
// FUN_00454250
s32 func_00454250(u8* arg0)
{
    s32 cur;
    s32 hi;
    s32 lo;
    s32 pos;
    s32 v4;
    s32 v3;
    s32 v31;
    s32 flag;
    cur = *(s32*)(arg0 + 0x20);
    if (cur < 2) {
        return 0;
    }
    hi = *(s32*)(arg0 + 0x14);
    if (cur < hi) {
        hi = cur;
    }
    lo = *(s32*)(arg0 + 0x18);
    if (lo <= 0) {
        lo = 0;
    }
    pos = *(s32*)(arg0 + 0x24);
    v4 = pos - 1;
    if (v4 >= lo) {
        if (pos > 0) {
            *(s32*)(arg0 + 0x24) = v4;
            goto ret1;
        }
        if (arg0 == NULL) {
            func_0046d730(D_007105E8, 0x163);
        }
        flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
        if (!flag) {
            *(s32*)(arg0 + 0x24) = hi - 1;
            *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x20) - hi;
            goto ret1;
        }
        return 0;
    }
    v3 = *(s32*)(arg0 + 0x28);
    v31 = v3 - 1;
    if (v31 >= 0) {
        *(s32*)(arg0 + 0x28) = v31;
        goto ret1;
    }
    if (v3 + pos > 0) {
        *(s32*)(arg0 + 0x24) = v4;
        goto ret1;
    }
    if (arg0 == NULL) {
        func_0046d730(D_007105E8, 0x163);
    }
    flag = (*(s32*)(arg0 + 0x0) & 1) != 0;
    if (!flag) {
        *(s32*)(arg0 + 0x24) = hi - 1;
        *(s32*)(arg0 + 0x28) = *(s32*)(arg0 + 0x20) - hi;
        goto ret1;
    }
    return 0;
ret1:
    return 1;
}

