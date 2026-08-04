#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultHeroLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct BtlResultWork BtlResultWork;
struct BtlResultWork
{
    u16 flags;          // 0x00
    u8 pad2[2];
    u32 state;          // 0x04
    s32 count;          // 0x08
    s32 field0C;        // 0x0C
    s32 field10;        // 0x10
    u8 pad14[0x28];
    u8* field3C;        // 0x3C
    u32 state40;        // 0x40
    s8 field44;         // 0x44
    u8 pad45[7];
    s32 field4C;        // 0x4C
    s32 slots50[2];     // 0x50
    u8 field58;         // 0x58
};

s16 func_00105ee0(s32 index);
s32 func_00105610(s16 param);
s32 func_00106330(s32 id);
void func_001f8690(u16 param);
void func_001f86d0(void);
void func_001f9a50(u16 param, s32 mode);
void func_001f9a90(void);
extern u32 func_00231d70(u32 max);
void func_0046d730(const char* file, s32 line);
extern char D_00629660[];
s32 func_00221970(u8* work);
void func_002baac0(s32 param);
void func_002bad10(s32 param);
void func_002bb4e0(void);
void func_002bbd20(s32 param, void* text);
s32 func_00353f50(s32 param);
void func_00442088(void* dst, void* fmt, s32 value);
s32 func_00455ea0(s32 param, s32 a, s32 b);
void func_0045af60(s32 a, s32 b, s32 c, s32 d);
s32 func_00104c70(s32 param);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern char iGpffffa5C8;
void func_003671d0(void* work);
void func_003672d0(void* work, s32 param);
s32 func_00354a50(u8* param, s32 mode);
void func_00142d80(s32 param, s32 a, s32 b, s32 c);
void func_00355300(s32 param, s32 mode);
s32 func_0021de60(void);
extern u8* func_00452560(u32 param);
void func_00460ac0(void* param, void* work);
s32 func_0046a770(u32 param);
extern u32 D_00795F20[];
extern s32 iGpffffa5C0;

// FUN_00221AB0
void func_00221ab0(void)
{
    s16 list[4];
    s32 i = 0;
    s32 count = 0;
    s32 val;

    for (; i < 4; i++) {
        s16 v = func_00105ee0(i);

        if (v != 0 && func_00105610(v) == 0) {
            list[count++] = v;
        }
    }
    if (count > 0 && func_00231d70(0x64) < 0x32) {
        s16 pick = list[func_00231d70(count)];

        switch (pick) {
        case 2:
            val = 0xE2;
            break;
        case 3:
            val = 0x16C;
            break;
        case 4:
            val = 0x1F3;
            break;
        case 6:
            val = 0x27A;
            break;
        case 7:
            val = 0x301;
            break;
        case 8:
            val = 0x387;
            break;
        default:
        case 0:
        case 1:
        case 5:
            func_0046d730(D_00629660, 0x98);
            val = 0;
            break;
        }
        {
            s16 sound = (s16)(val + 0x80 + func_00231d70(3));

            func_001f9a90();
            func_001f8690((u16)sound);
        }
        return;
    }
    {
        s16 v = (func_00106330(0x38) != 0) ? 5 : 8;

        switch (v) {
        case 5:
            val = 0x1D7;
            break;
        case 8:
            val = 0x192;
            break;
        default:
            func_0046d730(D_00629660, 0xAA);
            val = 0;
            break;
        }
    }
    {
        s16 sound = (s16)(val + func_00231d70(3));

        func_001f86d0();
        func_001f9a50((u16)sound, 3);
    }
}

// FUN_00221CF0
// SOLVED by tools/permute.py; this previously carried an nd-4 note calling the
// residual the $v0-vs-$at compare-temp floor. The permuter cracked it from the
// preserved body.
#pragma tailcall off
s32 func_00221cf0(BtlResultWork* work)
{
    BtlResultWork* work_p = work;
    u32 sp30[4];
    u32 sp20[4];

    switch (work_p->state40) {
    case 0:
        if ((work->flags & 8) || (D_008C024E[0] & 0x50) ||
            ((D_008C024C[0] & 0x10) && ((work->count = work_p->count + 1) > 4))) {
            func_002baac0(func_00455ea0(*(s32*)(work_p->field3C + 0x934), 0, 0));
            func_00442088(sp30, &iGpffffa5C8, func_00104c70(1) & 0xFF);
            func_002bbd20(0, sp30);
            func_002bad10(3);
            work->state40 = 1;
        }
        break;
    case 1:
        if (func_00353f50(1) == 0) {
            if (func_00221970((u8*)work_p) != 0) {
                func_002bad10(4);
                work_p->state40 = 2;
            } else {
                work->state40 = 4;
            }
        }
        break;
    case 2:
        if (func_00353f50(1) == 0) {
            func_0045af60(1, 0, 3, 0);
            func_00442088(sp20, &iGpffffa5C8, work->field44);
            func_002bbd20(0, sp20);
            func_002bad10(5);
            work->state40 = 3;
        }
        break;
    case 3:
        if (func_00353f50(1) == 0) {
            work->state40 = 4;
        }
        break;
    case 4:
        func_002bb4e0();
        work_p->count = 0;
        work->state40 = 5;
        /* fallthrough */
    case 5:
        if ((work->count = 1 + work_p->count) <= 4) {
            break;
        }
        return 1;
    default:
        func_0046d730(D_00629660, 0x12D);
        break;
    }
    return 0;
}
#pragma tailcall on

// FUN_00221F40
s32 func_00221f40(u8* arg0)
{
    BtlResultWork* work = (BtlResultWork*)func_00452560((u32)arg0);
    s32 i;

    work->field0C = 0;
    work->field10 = 0;
    func_00460ac0(D_00795F20, &work->field0C);
    switch (work->state) {
    case 0:
        func_003671d0(&work->field58);
        func_003672d0(&work->field58, 1);
        work->field4C = func_00354a50(arg0, 1);
        func_00142d80(work->field4C, 2, 1, 0);
        func_00355300(work->field4C, 0);
        work->flags |= 2;
        work->state = 1;
        /* fallthrough */
    case 1:
        for (i = 0; i < 2; i++) {
            s32* slot = &work->slots50[i];

            *slot = func_0046a770(*(u32*)((u8*)&iGpffffa5C0 + i * 4));
            if (*slot == 0) {
                func_0046d730(D_00629660, 0x52);
            }
        }
        func_00221ab0();
        work->state = 2;
        break;
    case 2:
        if (func_00221cf0(work) != 0) {
            s32 f = *(s32*)(work->field3C + 0x60);

            if (f & 8) {
                work->state = 3;
                func_002baac0(func_00455ea0(*(s32*)(work->field3C + 0x934), 0, 0));
                func_002bad10(1);
            } else if (f & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 6;
            } else {
                work->flags &= 0xFFFE;
                work->state = 6;
                work->flags |= 4;
            }
        }
        break;
    case 3:
        if (func_00353f50(1) == 0) {
            func_002bb4e0();
            work->flags &= 0xFFFE;
            work->state = 6;
        }
        break;
    case 4:
        if (func_0021de60() != 0) {
            work->state = 5;
        case 5:
            if ((work->flags & 4) || (++work->count >= 5)) {
                work->flags &= 0xFFFD;
                func_00142d80(work->field4C, 2, 0, 1);
                return -1;
            }
            break;
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
