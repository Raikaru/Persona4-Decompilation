#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 lock;
    u8 pad[12];
    s32 arg6;
} Func004667d0Locals;
extern s32 iGpffffb034;
extern s32 iGpffffbaf8;
extern s32 iGpffffbab4;
extern s32 iGpffffbab0;
extern s32 D_008E4B30[];
extern s32 D_008E4B34[];
extern s32 D_008E4B38[];
extern u8 D_008E4800[];
extern u8 D_008E4B50[];
extern u8 D_008E4D30[];
static inline u8 *func_004667d0_entry(u8 *base, s32 index)
{
    return base + index * 0x1DC;
}
extern void func_0043a978(void);
extern void func_004316a8(s32 arg0);
extern s32 func_00431928(void *a, u8 *b);
extern s32 func_003e1220(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
extern s32 iGpffffba98;
extern s32 iGpffffba9c;
extern u8 D_008E43C0[];
extern u8 D_008E43E4[];
extern void func_003bff30(void *object, void *callback, void *userdata);
extern u8 *func_004632f0(u8 *a0, u8 *a1);
extern s32 D_00922984[];
extern s32 D_00922980[];
extern s32 D_00922988[];
extern s32 D_00922934[];
extern s32 D_00922930[];
extern s32 D_0092293C[];
extern u8 *(*D_008873F8[])(...);
extern void memset(void *dst, s32 value, s32 size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])(...);
extern void func_00452730(s32 arg0);

extern void (*jtbl_008873EC[])(...);
extern s32 iGpffffbae8;
extern s32 iGpffffbaec;
extern u8 D_0070B610[];
extern void func_0050ffc8(s32 arg0);
extern void func_005097e8(s32 arg0);
extern void func_003ec330(s32 arg0);
extern s32 func_003d5fb0(u8 *arg0);
extern void func_0046a340(u32 arg0);

extern s32 D_00724BEC;
extern s32 D_00724BF0;

extern void func_0046ab90(u8 *arg0);
extern u8 *D_00724C08;

extern void func_0046d730(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;
extern void func_00451de0(u8 *name, s32 prio, s32 a2, s32 a3, void *entry, s32 a5, s32 a6);
extern s32 func_004633f0(void);
extern void func_00468ff0(void);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00460ac0(char *name, u8 *task);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern s32 func_004426e8(char *a, char *b);
extern s32 uGpffffb230;
extern s32 D_00724BC8;
extern s32 func_0042ba70();
extern s32 func_0042ba20();
extern void func_004216e0(s32 handle, s32 *out);
extern void func_00421770(s32 handle);
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void (*D_00887304[])(s32 arg0, s32 *arg1);
extern u8 D_008872E0[];
extern s32 iGpffffaf60;
extern void func_003c21e0(s32 arg0, s32 (*callback)(u8 *, s32 *), s32 *result);
extern u8 *func_003bfae0(s32 arg0);
extern s32 func_003e8200(s32 arg0, u8 *arg1);
extern void func_00477400(s32 arg0, s32 arg1);
extern void func_00476c70(u8 *arg0);
extern void func_00479910(s32 arg0);
extern void func_00461560(u8 *arg0);
extern void func_00461a40(u8 *arg0);
extern void func_00461be0(u8 *arg0);
extern u8 *func_0046a6f0(s32 arg0, s32 arg1);
extern s32 func_00451fc0(s32 arg0, s32 name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern s32 func_00468fa0(u8 *arg0);
extern void func_0046a020(u8 *arg0);
extern u32 iGpffffbb14;
extern u32 iGpffffbb10;
extern u32 iGpffffbb0c;
extern u32 iGpffffbb04;
extern s32 func_00432ec0(void);
extern s32 iGpffffba8c;
extern s32 iGpffffb198;
extern s32 iGpffffb194;
extern f32 iGpffffbb20;
extern f32 iGpffffbb1c;
extern f32 iGpffffbb24;
extern void func_0044f720(void);
extern s32 func_003e23e0(void);
extern void func_003e82e0();
extern void func_003e5510(s32 arg0);
extern s32 func_00457120(void);
extern void func_00466c60(void);
extern void func_0050cd80(void);
extern void func_00466600(void);





// FUN_004601C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004601c0);
// FUN_004604D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004604d0);
// FUN_00460910
void func_00460910(s32 arg0, s32 arg1)
{
    iGpffffba98 = func_003e1220(0x30, arg0, 4, 1, D_008E43C0, 0x41002);
    iGpffffba9c = func_003e1220(0x30, arg1, 4, 1, D_008E43E4, 0x41003);
}
// FUN_00460990
u8 *func_00460990(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B88, 0x41002);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_004609F0
u8 *func_004609f0(void)
{
    u8 *temp_2 = D_008873F8[0](D_00724B8C, 0x41003);

    memset(temp_2, 0, 0x30);
    return temp_2;
}



// FUN_00460A50
void func_00460a50(s32 arg0)
{
    jtbl_008873FC[0](D_00724B8C, arg0);
}



// FUN_00460A80
void func_00460a80(s32 arg0, s32 arg1)
{
    memset((void *)arg0, 0, arg1 * 0x30);
    func_00452730(D_00724B88);
}



// FUN_004614B0
void func_004614b0(void) {
    void (**tbl)(s32, s32) = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
}

// FUN_00461530
s32 func_00461530(u8 *arg0, s32 *arg1)
{
    if (*(u8 *)(arg0 + 7) == 0xFF) {
        *arg1 = 1;
    }
    return (s32)arg0;
}
// FUN_00461560
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461560);
// measured: opt_propagation off retains the initial D_00887300 callback table and the 0x40-byte frame in func_00461a40.
#pragma opt_propagation off
// FUN_00461A40
void func_00461a40(u8 *arg0)
{
    s32 sp3C;
    s32 sp38;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_4_2;
    u8 *var_16;
    void (**table)(s32, s32);

    temp_16 = *(u8 **)(arg0 + 0x1C);
    if (temp_16 != NULL) {
        if ((*(u16 *)(arg0 + 0x1A) & 2) == 0) {
            table = D_00887300;
            table[0](6, 1);
            table[0](8, 0);
        }
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        var_16 = *(u8 **)(temp_16 + 0x20);
        goto loop_00461A40_test;
loop_00461A40_body:
        sp38 = 0;
        temp_4 = *(s32 *)(*(u8 **)(var_16 + 0) + 0x18);
        if (temp_4 != 0) {
            func_003c21e0(temp_4, func_00461530, &sp38);
            if ((sp38 != 1) &&
                (func_003e8200(*(s32 *)D_008872E0,
                               func_003bfae0(*(s32 *)(var_16 + 0))) != 0)) {
                if (*(s32 *)(var_16 + 4) == 1) {
                    D_00887304[0](0xE, &sp3C);
                    D_00887300[0](0xE, 0);
                }
                if (iGpffffaf60 == 1) {
                    temp_4_2 = *(u8 **)(var_16 + 0);
                    ((void (*)(u8 *))(*(void **)(temp_4_2 + 0x48)))(temp_4_2);
                }
                if (*(s32 *)(var_16 + 4) == 1) {
                    D_00887300[0](0xE, sp3C);
                }
            }
        }
        var_16 = *(u8 **)(var_16 + 0x24);
loop_00461A40_test:
        if (var_16 != NULL) {
            goto loop_00461A40_body;
        }
    }
}
// measured: closes opt_propagation around func_00461a40.
#pragma opt_propagation on
// FUN_00461BE0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00461be0);
// measured: opt_propagation off preserves the callback table pointer across jal calls while probing func_00462230.
#pragma opt_propagation off
// FUN_00462230
void func_00462230(u8 *arg0)
{
    u8 *self;
    u8 *work;
    void (**table)(s32, s32);

    self = arg0;
    work = *(u8 **)(self + 0x1C);
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        func_00477400(*(s32 *)(work + 0xDC), 1);
    }
    func_00476c70(work);
    if ((*(s32 *)(work + 0xE0) == 0) ||
        ((*(s32 *)(work + 0xD8) & 0x800) != 0)) {
        func_003f6440(2, *(s32 *)(work + 0xE4));
        func_003f6440(3, *(s32 *)(work + 0xE8));
        self = (u8 *)D_00887300;
        ((void (**)(s32, s32))self)[0](6, 1);
        ((void (**)(s32, s32))self)[0](8, 0);
        func_00479910(*(s32 *)(work + 0xDC));
    } else {
        table = D_00887300;
        table[0](6, 1);
        table[0](8, 0);
        *(u16 *)(self + 0x1A) |= 2;
        *(s32 *)(self + 0x1C) = *(s32 *)(work + 0xE0);
        func_00461560(self);
        func_00461a40(self);
        func_00461be0(self);
    }
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        func_00477400(*(s32 *)(work + 0xDC), 0);
    }
}
// measured: closes opt_propagation around func_00462230.
#pragma opt_propagation on
// FUN_004623A0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004623a0);
// FUN_00462BF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00462bf0);
// FUN_00462DF0
s32 func_00462df0(u8 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if ((*(s32 *)(arg0 + 0) == 0) ||
        ((*(s32 *)(arg0 + 0x10) == 0) &&
         (*(s32 *)(arg0 + 0xC) == 0) &&
         (*(s32 *)(arg0 + 0x14) == 0) &&
         (*(s32 *)(arg0 + 0x18) == 0) &&
         (*(s32 *)(arg0 + 0x1C) == 0) &&
         (*(s32 *)(arg0 + 0x24) == 0) &&
         (*(s32 *)(arg0 + 0x28) == 0))) {
        return 0;
    }
    return 1;
}
// FUN_004633C0
void func_004633c0(void *arg0, void *arg1)
{
    func_003bff30(arg0, func_004632f0, arg1);
}
/* measured: object 296B/window 304B; residual is two retail OR destination
   colouring words and an all-zero tail. Committed at nd 4. */
/* object_size=296; window=304; normalized_diff=4; differing offsets=112,116,172,176; probes exhausted: func_003e82e0 declaration variants, local declaration order/types, compound/transposed/raw OR forms, block locals, condition/goto forms, optimization_level 1, opt_propagation, inline OR helpers and typed helpers, direct OR expression, result assigned to temp_5, and doubled-arithmetic spelling; all retained nd=4 or grew the object. */
// FUN_004633F0 NONMATCHING
#ifdef NON_MATCHING
s32 func_004633f0(void) {
    f32 var_f0_2;
    f32 var_f0;
    s32 temp_2;
    s32 temp_4;
    s32 temp_6;
    s32 temp_5;

    func_0044f720();
    iGpffffba8c = func_003e23e0();
    func_003e82e0(func_00457120(), 0, 0);
    temp_4 = *(s32 *)0x10000000;
    iGpffffb198 = temp_4;
    temp_2 = temp_4 - iGpffffb194;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        temp_6 = (s32)((u32)temp_2 >> 1);
        temp_5 = temp_2 & 1;
        temp_6 = temp_6 | temp_5;
        var_f0 = (f32)temp_6 + (f32)temp_6;
    }
    iGpffffbb20 = var_f0;
    if (temp_4 >= 0) {
        var_f0_2 = (f32)temp_4;
    } else {
        temp_6 = (s32)((u32)temp_4 >> 1);
        temp_5 = temp_4 & 1;
        temp_6 = temp_6 | temp_5;
        var_f0_2 = (f32)temp_6 + (f32)temp_6;
    }
    iGpffffbb1c = var_f0_2;
    iGpffffbb24 = 100.0f * ((*(f32 *)&iGpffffbb20) / 520.0f);
    *(s32 *)0x10000000 = 0;
    func_003e5510(0);
    func_00466600();
    func_00466c60();
    func_0050cd80();
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004633f0);
#endif

// FUN_00463520
void func_00463520(void) {
    func_00451de0(D_00712670, 0x12C, 0, 0, (void *)func_004633f0, 0, 0);
}

// FUN_00463930
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00463930);
// FUN_004645E0
void func_004645e0(void) {
    func_0043a978();
    func_004316a8(0);
    D_008E4B30[0] = 2;
    D_008E4B34[0] = 2;
    D_008E4B38[0] = 0;
    iGpffffbab4 = func_00431928(D_008E4B30, D_008E4800);
    iGpffffbab0 = 0;
}

// FUN_00464670
s32 func_00464670(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;

    temp_2 = func_00432ec0();
    switch (temp_2) {
    case -1:
        return -1;
    case 0:
        return 0;
    case 1:
        temp_3 = *arg0;
        switch (temp_3) {
        case 5:
        case 6:
            if (*arg1 < 0) {
                *arg2 = 0;
                temp_2_3 = *arg1;
                if (temp_2_3 < 0) {
                    *arg1 = temp_2_3 & 0xFFFF;
                }
            } else {
                *arg2 = 1;
            }
            break;
        default:
            if (*arg1 == 0) {
                *arg2 = 1;
            } else {
                *arg2 = 0;
            }
            temp_2_2 = *arg1;
            if (temp_2_2 < 0) {
                *arg1 = temp_2_2 & 0xFFFF;
            }
            break;
        }
        return 1;
    default:
        return -1;
    }
}
// FUN_00466280
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00466280);
// FUN_00466600
void func_00466600(void) {
    s32 sp20[12];
    s32 r;

    r = func_0042ba70();
    if (uGpffffb230 != 0) {
        func_004216e0(D_00724BC8, sp20);
        if (sp20[0] == 0xC) {
            goto call;
        }
        if (sp20[0] != 8) {
            goto skip;
        }
call:
        func_00421770(D_00724BC8);
    }
skip:
    if (r == 0) {
        func_0042ba20();
    }
}

// FUN_004667D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004667d0);
// FUN_004669D0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004669d0);
// FUN_004673C0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_004673c0);
// FUN_00467880
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467880);
// FUN_00467BD0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00467bd0);
// FUN_004680C0
void func_004680c0(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}



// FUN_004680F0
s32 func_004680f0(u8 *arg0, s8 *arg1) {
    u8 *temp_6;

    temp_6 = (u8 *)(*(u8 **)(arg0 + 0x38));
    *arg1 = 0;
    if (*(s16 *)(temp_6 + 0x80F80) == 3) {
        if (*(s32 *)(temp_6 + 0x80F88) != 0) {
            func_00442830(arg1, temp_6 + 0x80F90, temp_6);
        }
        return 1;
    }
    return 0;
}

// FUN_00468A10
void func_00468a10(void)
{
    D_00922984[0] = 0;
    D_00922980[0] = 0;
    D_00922988[0] = 0;
    D_00922934[0] = 0;
    D_00922930[0] = 0;
    D_0092293C[0] = 0;
}
// FUN_00468D10
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468d10);
// FUN_00468FA0
s32 func_00468fa0(u8 *arg0) {
    u8 *ctx;
    u8 *task;

    ctx = *(u8 **)(arg0 + 0x38);
    task = func_00460990();
    *(void **)(task + 8) = (void *)func_00468ff0;
    *(u8 **)(task + 0x10) = ctx;
    func_00460ac0(*(char **)(ctx + 0x218), task);
    return 0;
}

// FUN_00468FF0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_00468ff0);
// FUN_0046A020
void func_0046a020(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) != 0) {
        if (*(s32 *)(work + 0xD8) != 0) {
            func_0050ffc8(*(s32 *)(work + 4));
        }
        func_005097e8(*(s32 *)(work + 4));
        *(s32 *)(work + 4) = 0;
    }
    if (*(s32 *)(work + 0x1E0) != 0) {
        jtbl_008873EC[0](*(s32 *)(work + 0x1E0));
        *(s32 *)(work + 0x1E0) = 0;
    }
    if (*(s32 *)(work + 0x200) != 0) {
        jtbl_008873EC[0](*(s32 *)(work + 0x200));
        *(s32 *)(work + 0x200) = 0;
        iGpffffbae8 = 0;
    }
    if (*(s32 *)(work + 0xD0) != 0) {
        func_003ec330(*(s32 *)(work + 0xD0));
        *(s32 *)(work + 0xD0) = 0;
    }
    if (*(s32 *)(work + 0x1F4) == 0) {
        iGpffffbaec = 0;
    }
    if (*(s32 *)(work + 0x1FC) != 0) {
        *(s32 *)(work + 0x1FC) = 0;
        func_003d5fb0(D_0070B610);
    }
    func_0046a340((u32)work);
}
// FUN_0046A110
s32 func_0046a110(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = func_0046a6f0(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = func_00451fc0(arg0, iGpffffb034, 0xC6, 0, 0,
                           (void (*)(u8 *))func_00468fa0,
                           (void (*)(u8 *))func_0046a020, work);
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A1E0
s32 func_0046a1e0(void)
{
    return iGpffffb034;
}

// FUN_0046A1F0
s32 func_0046a1f0(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = func_0046a6f0(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = func_00451fc0(arg0, iGpffffb034, 0xC6, 0, 0,
                           (void (*)(u8 *))func_00468fa0,
                           (void (*)(u8 *))func_0046a020, work);
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x1FC) = 0;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A2C0
s32 func_0046a2c0(void)
{
    return iGpffffbaf8;
}

// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}



// FUN_0046A2E0
void func_0046a2e0(u8 *arg0, s32 arg1) {
    u32 i;

    D_00724C04 = arg0;
    D_00724C00 = arg0 + arg1;
    D_00724BFC = 0x1F4;
    i = 0;
    while (i < D_00724BFC) {
        *(s32 *)(arg0 + i * 8) = 0;
        *(s32 *)(arg0 + i * 8 + 4) = 0;
        i++;
    }
    D_00724BF8 = 0;
    D_00724BF4 = 0;
}

// FUN_0046A340
void func_0046a340(u32 arg0) {
    s32 temp_2;
    u32 var_4;
    u32 var_7;
    u8 *temp_5;
    u8 *entry;

    if (arg0 < iGpffffbb14) {
        (*jtbl_008873EC)();
        return;
    }
    if (iGpffffbb10 < arg0) {
        (*jtbl_008873EC)();
        return;
    }
    temp_2 = func_0042ba20();
    temp_5 = (u8 *)iGpffffbb14;
    var_7 = 0;
    var_4 = iGpffffbb0c;
    goto loop_test;
loop_body:
    entry = temp_5 + (var_7 * 8);
    if (arg0 == *(s32 *)(entry + 0)) {
        var_4 = iGpffffbb04;
        iGpffffbb04 = var_4 - *(s32 *)(entry + 4);
        *(s32 *)(entry + 0) = 0;
        *(s32 *)(entry + 4) = 0;
        goto loop_done;
    }
    var_7 += 1;
loop_test:
    if (var_7 < var_4) {
        goto loop_body;
    }
loop_done:
    if (temp_2 != 0) {
        func_0042ba70(var_4);
    }
}
// FUN_0046A430
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a430);
// FUN_0046A770
/* The list walk is written with an explicit goto loop: retail tests the
   cursor at the TOP of the loop and both early exits are out of line, which
   the natural `while (p != NULL)` form does not reproduce (nd 57). */
u8 *func_0046a770(char *arg0) {
    u8 *p;

    p = D_00724C08;
loop:
    if (p == NULL) {
        return NULL;
    }
    if (func_004426e8((char *)(p + 2), arg0) == 0) {
        return p;
    }
    p = *(u8 **)(p + 0x238);
    goto loop;
}

// FUN_0046A7F0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046a7f0);
// FUN_0046AB40
void func_0046ab40(void)
{
    u8 *var_16 = D_00724C08;

loop_1:
    if (var_16 != NULL) {
        func_0046ab90(var_16);
        var_16 = *(u8 **)(var_16 + 0x238);
        goto loop_1;
    }
}



// FUN_0046D6B0
void func_0046d6b0(s32 arg0)
{
    if (arg0 == 0) {
        func_0046d730(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}

// FUN_0046D700
void func_0046d700(const char *file, s32 line, const char *msg, ...)
{
}
// FUN_0046D730
void func_0046d730(void *arg0, s32 arg1) {}
// FUN_0046D740
void func_0046d740(void) {}
// FUN_0046D750
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046d750);
// FUN_0046E7F0
void func_0046e7f0(u8 *arg0)
{
    void (**tbl)(u8 *) = (void (**)(u8 *))jtbl_008873EC;
    u8 *work = *(u8 **)(arg0 + 0x38);

    tbl[0](*(u8 **)(work + 0x48));
    tbl[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0046E850
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046e850);
// FUN_0046EA10
s32 func_0046ea10(u8 *arg0)
{
    s32 value = *(s32 *)(*(u8 **)(arg0 + 0x38));

    if ((value == 6) || (value == 8)) {
        return 0;
    }
    return 1;
}
// FUN_0046EA50
void func_0046ea50(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0046EA60
void func_0046ea60(u8 *arg0, u8 *arg1)
{
    struct FInput {
        f32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    };
    union Input {
        struct {
            s32 sp0;
            s32 sp4;
            s32 sp8;
            s32 spC;
        } i;
        struct FInput f;
    } input;
#define sp0 input.i.sp0
#define sp4 input.i.sp4
#define sp8 input.i.sp8
#define spC input.i.spC
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_4;
    s32 temp_5;
    u8 *temp_3;

    input = *(union Input *)arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_3 + 0) == 6) {
        *(struct FInput *)(temp_3 + 0xC) = input.f;
        temp_f4 = (f32)sp0;
        *(f32 *)(temp_3 + 0x60) = temp_f4;
        temp_f3 = (f32)sp4;
        *(f32 *)(temp_3 + 0x64) = temp_f3;
        temp_5 = sp0 + sp8;
        temp_f2 = (f32)temp_5;
        *(f32 *)(temp_3 + 0xA0) = temp_f2;
        *(f32 *)(temp_3 + 0xA4) = temp_f3;
        *(f32 *)(temp_3 + 0xE0) = temp_f4;
        temp_f0 = (f32)(sp4 + 2);
        *(f32 *)(temp_3 + 0xE4) = temp_f0;
        *(f32 *)(temp_3 + 0x120) = temp_f2;
        *(f32 *)(temp_3 + 0x124) = temp_f0;
        temp_f0_2 = (f32)(temp_5 - 2);
        *(f32 *)(temp_3 + 0x160) = temp_f0_2;
        *(f32 *)(temp_3 + 0x164) = temp_f3;
        *(f32 *)(temp_3 + 0x1A0) = temp_f2;
        *(f32 *)(temp_3 + 0x1A4) = temp_f3;
        *(f32 *)(temp_3 + 0x1E0) = temp_f0_2;
        temp_4 = sp4 + spC;
        temp_f1 = (f32)temp_4;
        *(f32 *)(temp_3 + 0x1E4) = temp_f1;
        *(f32 *)(temp_3 + 0x220) = temp_f2;
        *(f32 *)(temp_3 + 0x224) = temp_f1;
        *(f32 *)(temp_3 + 0x260) = temp_f4;
        temp_f0_3 = (f32)(temp_4 - 2);
        *(f32 *)(temp_3 + 0x264) = temp_f0_3;
        *(f32 *)(temp_3 + 0x2A0) = temp_f2;
        *(f32 *)(temp_3 + 0x2A4) = temp_f0_3;
        *(f32 *)(temp_3 + 0x2E0) = temp_f4;
        *(f32 *)(temp_3 + 0x2E4) = temp_f1;
        *(f32 *)(temp_3 + 0x320) = temp_f2;
        *(f32 *)(temp_3 + 0x324) = temp_f1;
        *(f32 *)(temp_3 + 0x360) = temp_f4;
        *(f32 *)(temp_3 + 0x364) = temp_f3;
        temp_f0_4 = (f32)(sp0 + 2);
        *(f32 *)(temp_3 + 0x3A0) = temp_f0_4;
        *(f32 *)(temp_3 + 0x3A4) = temp_f3;
        *(f32 *)(temp_3 + 0x3E0) = temp_f4;
        *(f32 *)(temp_3 + 0x3E4) = temp_f1;
        *(f32 *)(temp_3 + 0x420) = temp_f0_4;
        *(f32 *)(temp_3 + 0x424) = temp_f1;
        *(f32 *)(temp_3 + 0x460) = (f32)*(s32 *)(temp_3 + 0xC);
        *(f32 *)(temp_3 + 0x464) = (f32)*(s32 *)(temp_3 + 0x10);
        temp_5 = *(s32 *)(temp_3 + 0xC) + *(s32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x4A0) = (f32)temp_5;
        *(f32 *)(temp_3 + 0x4A4) = (f32)*(s32 *)(temp_3 + 0x10);
        *(f32 *)(temp_3 + 0x4E0) = (f32)*(s32 *)(temp_3 + 0xC);
        temp_5 = *(s32 *)(temp_3 + 0x10) + *(s32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x4E4) = (f32)temp_5;
        temp_5 = *(s32 *)(temp_3 + 0xC) + *(s32 *)(temp_3 + 0x14);
        *(f32 *)(temp_3 + 0x520) = (f32)temp_5;
        temp_5 = *(s32 *)(temp_3 + 0x10) + *(s32 *)(temp_3 + 0x18);
        *(f32 *)(temp_3 + 0x524) = (f32)temp_5;
    }
}
#undef sp0
#undef sp4
#undef sp8
#undef spC
// FUN_0046EC70
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046ec70);
// FUN_0046F2B0
INCLUDE_ASM("asm/nonmatchings/code1_0046", func_0046f2b0);
