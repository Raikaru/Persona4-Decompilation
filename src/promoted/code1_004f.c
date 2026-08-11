#include "include_asm.h"
#include "type.h"


extern s32 D_00925BE0[];
extern s32 func_004e22f8(void);
extern s32 func_004e3448(void);
extern void func_004e2298(void);
extern void func_004e2690(void);
extern void func_004f14c8();
typedef void (*Code1Callback)(void *);
typedef struct {
    Code1Callback callback;
    void *arg;
} Code1CallbackRec;
extern Code1CallbackRec D_00925E80[];
typedef struct {
    u8 pad_0[0xC];
    void (*callback)(u8 *arg0);
} Code1Table;
extern Code1Table D_0075D650[];
extern u8 *D_00743A48[];
typedef void (*Code1IndexCallback)(s32 arg0, s32 arg1, s32 arg2);
extern Code1IndexCallback D_00743C40[];
extern void func_004f1e10(void);
extern Code1CallbackRec D_00925E88[];
extern s32 D_00925EA0[];
extern void func_004f1f80(s32 arg0);
extern void func_004f54a0(void);
extern u8 *D_00743A50;
extern s32 D_00743A54;
extern s32 D_00743B58;
extern void func_004e20a0(void);
extern void func_004e2750(void);
extern void func_004f9a70(void);
extern void func_004f26e8(s32 arg0, s32 arg1, s32 arg2);
extern void func_004e2170(void);
extern void func_004e2240(void);
extern void func_004e2108(s32 arg0);
extern void func_004f53c0(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4);
extern s32 D_0075D3E0[];
extern s32 D_0075D3F8[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */
// FUN_004F1350
#ifdef NON_MATCHING
/* measured: schedule on reproduces callback global staging and delay-slot order. */
#pragma schedule on
void func_004f1350(void) {
    Code1CallbackRec *rec;
    rec = D_00925E80;
    if (rec->callback != NULL) {
        rec->callback(rec->arg);
    }
}
/* measured: schedule off closes the isolated 004f1350 callback probe. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1350);
#endif
// FUN_004F1380
#ifdef NON_MATCHING
/* measured: schedule on reproduces callback global staging and delay-slot order. */
#pragma schedule on
void func_004f1380(void) {
    Code1CallbackRec *rec;
    rec = D_00925E88;
    if (rec->callback != NULL) {
        rec->callback(rec->arg);
    }
}
/* measured: schedule off closes the isolated 004f1380 callback probe. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1380);
#endif
// FUN_004F13B0
/* measured: schedule on fills the 004f13b0 return delay slot. */
#pragma schedule on
s32 *func_004f13b0(void) {
    return D_00925BE0;
}
/* measured: schedule off closes func_004f13b0's return-slot probe. */
#pragma schedule off


extern s32 D_0075D370[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F13C0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f13c0);
// FUN_004F1418
void func_004f1418(void) {
    func_004e20a0();
}
// FUN_004F1430
void func_004f1430(void) {
    func_004e2170();
}
// FUN_004F1448
void func_004f1448(void) {
    func_004e2240();
}
// FUN_004F1460
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1460);
// FUN_004F14B0
void func_004f14b0(void) {
    func_004e2690();
}
// FUN_004F14C8
void func_004f14c8(s32 unused) {
    func_004e2750();
}
// FUN_004F14E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f14e0);
// FUN_004F1518
void func_004f1518(void) {
    func_004e2298();
    func_004f9a70();
}
// FUN_004F1538
/* measured: schedule on fills the 004f1538 return delay slot. */
#pragma schedule on
s32 *func_004f1538(void) {
    return D_0075D370;
}
/* measured: schedule off closes func_004f1538's return-slot probe. */
#pragma schedule off


extern s32 D_0075D620[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */
// FUN_004F1548
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1548);
// FUN_004F1600
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1600);
// FUN_004F16B0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f16b0);
// FUN_004F1708
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1708);
// FUN_004F1750
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1750);
// FUN_004F1820
void func_004f1820(s32 arg0) {
    func_004f54a0();
    func_004f26e8(arg0, 0, 0);
}
// FUN_004F1850
#ifdef NON_MATCHING
void func_004f1850(u8 *arg0) {
    if ((arg0 != NULL) && (*(s16 *)(arg0 + 0x34) != 0)) {
        if (*(s16 *)(arg0 + 0x38) == 2) {
            func_004f1e10();
        }
        *(s16 *)(arg0 + 0x36) = 0;
        *(s16 *)(arg0 + 0x34) = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1850);
#endif
// FUN_004F1F80
#ifdef NON_MATCHING
void func_004f1f80(s32 unused) {
    Code1Table *table;
    table = D_0075D650;
    D_00743A48[0] = (u8 *)table;
    table->callback((u8 *)table);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1f80);
#endif
// FUN_004F1FB0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f1fb0);
// FUN_004F2BC0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2bc0);
// FUN_004F2C08
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2c08);
// FUN_004F2E18
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2e18);
// FUN_004F2E80
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2e80);
// FUN_004F2F58
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f2f58);
// FUN_004F30C0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f30c0);
// FUN_004F3108
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3108);
// FUN_004F3150
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3150);
// FUN_004F3258
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3258);
// FUN_004F3340
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3340);
// FUN_004F33E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f33e0);
// FUN_004F34A0
/* measured: schedule on fills the 004f34a0 return delay slot. */
#pragma schedule on
s32 *func_004f34a0(void) {
    return D_0075D620;
}
/* measured: schedule off closes func_004f34a0's return-slot probe. */
#pragma schedule off


/* measured: the segment-return form (CRI ADX "set param" family) is
   load-bearing: retail's sw $zero uses $v0 as base because the segment
   address is the live return value; a void store compiles to a $v1 base.
   The schedule-on pragma fills the jr $ra delay slot (nd 6 -> 0). */

// FUN_004F34B0
#ifdef NON_MATCHING
/* measured: tailcall on preserves the retail framed jump after the setup calls. */
#pragma tailcall on
void func_004f34b0(s32 arg0) {
    s32 value;
    value = (s32)func_004f34a0();
    D_00925EA0[0] = value;
    func_004f54a0();
    func_004f1f80(arg0);
}
/* measured: tailcall off closes the isolated 004f34b0 probe. */
#pragma tailcall off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f34b0);
#endif
// FUN_004F34E8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f34e8);
// FUN_004F3780
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f3780);
#pragma schedule on
// FUN_004F54A0
void func_004f54a0(void) {
    D_00743A54 = 0;
}
/* measured: D_00743A54 global store shape produces normalized_diff 0. */
#pragma schedule off




/* measured: scalar D_00743A50 declaration and field store produce normalized_diff 0. */
// FUN_004F5BD0
void func_004f5bd0(s32 arg0) {
    if (D_00743A50 != NULL) {
        *(s32 *)(D_00743A50 + 0x1C) = arg0 * 0x2710;
    }
}
// FUN_004F5BF0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5bf0);
// FUN_004F5CD0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5cd0);
// FUN_004F5D38
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5d38);
// FUN_004F5FD8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f5fd8);
// FUN_004F60F8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f60f8);
// FUN_004F6188
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6188);
// FUN_004F6870
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6870);
// FUN_004F6888
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6888);
// FUN_004F68A0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f68a0);
// FUN_004F68B8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f68b8);
// FUN_004F6948
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f6948);
#pragma schedule on
// FUN_004F69B8
void func_004f69b8(u32 value) {
    D_00743B58 = value;
}
/* measured: D_00743B58 global store shape produces normalized_diff 0. */
#pragma schedule off


extern s32 D_0075D9E8[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F69C8
/* measured: schedule on fills the 004f69c8 return delay slot. */
#pragma schedule on
s32 *func_004f69c8(void) {
    return D_0075D9E8;
}
/* measured: schedule off closes func_004f69c8's return-slot probe. */
#pragma schedule off


extern s32 D_0075DB88[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F7940
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f7940);
// FUN_004F8478
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8478);
// FUN_004F8508
/* measured: schedule on fills the 004f8508 return delay slot. */
#pragma schedule on
s32 *func_004f8508(void) {
    return D_0075DB88;
}
/* measured: schedule off closes func_004f8508's return-slot probe. */
#pragma schedule off


extern s32 D_0075DBC8[];

/* measured: without #pragma schedule on, MWCC emits lui/addiu/jr/nop with
   the jr $ra delay slot unfilled; retail fills the delay slot with the
   final addiu (nd 6 -> 0). */

// FUN_004F8518
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8518);
// FUN_004F8ED8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8ed8);
// FUN_004F8F60
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8f60);
// FUN_004F8FE8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f8fe8);
// FUN_004F9040
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9040);
/* measured: schedule on tested for return-zero epilogue order. */
#pragma schedule on
// FUN_004F9130
s32 func_004f9130(void)
{
    func_004f8f60();
    return 0;
}
/* measured: restore schedule off after func_004f9130. */
#pragma schedule off
// FUN_004F9150
#ifdef NON_MATCHING
s32 func_004f9150(s32 arg0, s32 arg1, u32 index, s32 arg3) {
    s32 result;
    u32 offset;

    offset = index * 4;
    result = -1000;
    if (index < 9U) {
        ((Code1IndexCallback *)((u8 *)D_00743C40 + offset))[0](arg0, arg1, arg3);
        result = 0;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9150);
#endif
// FUN_004F9198
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9198);
// FUN_004F9350
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9350);
// FUN_004F9368
/* measured: schedule on fills the 004f9368 return delay slot. */
#pragma schedule on
s32 *func_004f9368(void) {
    return D_0075DBC8;
}
/* measured: schedule off closes func_004f9368's return-slot probe. */
#pragma schedule off

// FUN_004F9378
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9378);
// FUN_004F93D0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f93d0);
// FUN_004F9410
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9410);
// FUN_004F94B8
/* measured: schedule on tested for the retail constant-before-save order. */
#pragma schedule on
s32 func_004f94b8(s32 unused, s32 arg1)
{
    s32 value;

    value = -0x64;
    if (arg1 != 0) {
        value = func_004f9130();
    }
    return value;
}
/* measured: restore schedule off after func_004f94b8. */
#pragma schedule off
// FUN_004F94E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f94e0);
// FUN_004F9528
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9528);
// FUN_004F9590
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9590);
// FUN_004F95F8
#ifdef NON_MATCHING
s32 func_004f95f8(u8 *arg0, s32 arg1) {
    s32 result;
    s32 index;
    u8 *entry;

    index = 0;
    if (arg1 > 0) {
        entry = arg0;
loop_004f95f8:
        index += 1;
        result = 0;
        if (*entry == 0) {
            if (index < arg1) {
                entry = arg0 + index;
                goto loop_004f95f8;
            }
            goto done_004f95f8;
        }
    } else {
done_004f95f8:
        result = 1;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f95f8);
#endif
// FUN_004F9638 NONMATCHING
#ifdef NON_MATCHING
/* measured: optimization-level one reproduces the retail straight-line shape. */
#pragma optimization_level 1
/* measured: scheduling fills the final return delay slot. */
#pragma schedule on
u32 func_004f9638(u8 *a0, u8 *a1, u8 *a2)
{
    u32 x;
    u32 y;
    u32 result;

    x = a1[0];
    y = a0[3];
    result = y ^ x;
    a2[0] = result;
    x = a0[0];
    a2[1] = x;
    x = a1[3];
    y = a0[7];
    result = y ^ x;
    a2[2] = result;
    x = a0[4];
    a2[3] = x;
    x = a0[1];
    a2[4] = x;
    x = a1[2];
    y = a0[6];
    result = y ^ x;
    a2[5] = result;
    x = a0[2];
    a2[6] = x;
    y = a0[5];
    x = a1[1];
    result = y ^ x;
    a2[7] = result;
    return result;
}
/* measured: close the scheduling scope. */
#pragma schedule off
/* measured: restore optimization level two. */
#pragma optimization_level 2

#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9638);
#endif
/* measured: split-u32 candidate; the single copy-load residual was
   MWCCPS2's. Under ee-gcc 2.96 it measures nd 26. Committed at nd 26. */
// FUN_004F96A0 NONMATCHING
#ifdef NON_MATCHING
/* measured: optimization-level one reproduces the retail straight-line shape. */
#pragma optimization_level 1
/* measured: scheduling fills the final return delay slot. */
#pragma schedule on
u32 func_004f96a0(u8 *a0, u8 *a1, u8 *a2)
{
    u32 x;
    u32 y;
    u32 result;

    x = a1[1];
    y = a0[2];
    result = y ^ x;
    a2[0] = result;
    x = a0[7];
    a2[1] = x;
    x = a0[5];
    a2[2] = x;
    x = a1[2];
    y = a0[3];
    result = y ^ x;
    a2[3] = result;
    y = a1[0];
    x = a0[0];
    x = x ^ y;
    a2[4] = x;
    y = a0[6];
    a2[5] = y;
    x = a0[4];
    a2[6] = x;
    y = a0[1];
    x = a1[3];
    result = y ^ x;
    a2[7] = result;
    return result;
}
/* measured: close the scheduling scope. */
#pragma schedule off
/* measured: restore optimization level two. */
#pragma optimization_level 2

#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f96a0);
#endif
/* measured: this member uses the same split u32 temporary shape as the
   measured leader, with its own byte permutation order. */
#pragma optimization_level 1
#pragma schedule on
// FUN_004F9708
u32 func_004f9708(u8 *a0, u8 *a1, u8 *a2)
{
    u32 x;
    u32 y;
    u32 result;

    x = a0[1];
    a2[0] = x;
    x = a1[2];
    y = a0[7];
    result = y ^ x;
    a2[1] = result;
    x = a0[6];
    a2[2] = x;
    x = a1[1];
    y = a0[2];
    result = y ^ x;
    a2[3] = result;
    y = a1[3];
    x = a0[5];
    x = x ^ y;
    a2[4] = x;
    y = a0[3];
    a2[5] = y;
    x = a1[0];
    y = a0[0];
    result = y ^ x;
    a2[6] = result;
    x = a0[4];
    a2[7] = x;
    return result;
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2

/* Parked candidate: the adjacent-X donor shape leaves only the copy-load
   register residual at nd 2; measured in-place and copy variants.
   Committed at nd 2. */
// FUN_004F9770
#ifdef NON_MATCHING
/* measured: optimization level 1 and schedule on reproduce this member's
   straight-line order and filled jr delay slot. */
#pragma optimization_level 1
#pragma schedule on
u32 func_004f9770(u8 *a0, u8 *a1, u8 *a2)
{
    u32 x;
    u32 y;
    u32 result;

    x = a1[2];
    y = a0[3];
    result = y + x;
    a2[0] = result;
    x = a0[6];
    a2[1] = x;
    y = a0[0];
    a2[2] = y;
    x = a0[2];
    a2[3] = x;
    x = a1[0];
    y = a0[4];
    result = y + x;
    a2[4] = result;
    y = a1[1];
    x = a0[1];
    x = x + y;
    a2[5] = x;
    y = a0[7];
    a2[6] = y;
    y = a0[5];
    x = a1[3];
    result = y + x;
    a2[7] = result;
    return result;
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9770);
#endif

/* measured: this member uses the same split u32 temporary shape as the
   measured leader, with its own byte permutation order. */
#pragma optimization_level 1
#pragma schedule on
// FUN_004F97D8
void func_004f97d8(u8 *a0, u8 *a1, u8 *a2) {
    *(u8 *)(a2 + 0) = (u8)*(u8 *)(a0 + 7);
    *(s8 *)(a2 + 1) = (s8)(*(u8 *)(a0 + 0) + *(u8 *)(a1 + 3));
    *(s8 *)(a2 + 2) = (s8)(*(u8 *)(a0 + 2) + *(u8 *)(a1 + 0));
    *(s8 *)(a2 + 3) = (s8)(*(u8 *)(a0 + 6) + *(u8 *)(a1 + 1));
    *(u8 *)(a2 + 4) = (u8)*(u8 *)(a0 + 4);
    *(u8 *)(a2 + 5) = (u8)*(u8 *)(a0 + 3);
    *(u8 *)(a2 + 6) = (u8)*(u8 *)(a0 + 5);
    *(s8 *)(a2 + 7) = (s8)(*(u8 *)(a0 + 1) + *(u8 *)(a1 + 2));
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2

/* measured: this member uses the same split u32 temporary shape as the
   measured leader, with its own byte permutation order. */
#pragma optimization_level 1
#pragma schedule on
// FUN_004F9840
void func_004f9840(u8 *a0, u8 *a1, u8 *a2) {
    *(u8 *)(a2 + 0) = (u8)*(u8 *)(a0 + 2);
    *(s8 *)(a2 + 1) = (s8)(*(u8 *)(a0 + 3) + *(u8 *)(a1 + 2));
    *(u8 *)(a2 + 2) = (u8)*(u8 *)(a0 + 6);
    *(s8 *)(a2 + 3) = (s8)(*(u8 *)(a0 + 7) + *(u8 *)(a1 + 0));
    *(u8 *)(a2 + 4) = (u8)*(u8 *)(a0 + 0);
    *(s8 *)(a2 + 5) = (s8)(*(u8 *)(a0 + 1) + *(u8 *)(a1 + 1));
    *(u8 *)(a2 + 6) = (u8)*(u8 *)(a0 + 4);
    *(s8 *)(a2 + 7) = (s8)(*(u8 *)(a0 + 5) + *(u8 *)(a1 + 3));
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2

/* Parked candidate: the same XCXCCXCX donor shape leaves only the copy-load
   and tail register residuals under MWCCPS2; measured tail and copy
   spellings. Under ee-gcc 2.96 it measures nd 26. Committed at nd 26. */
// FUN_004F98A8
#ifdef NON_MATCHING
/* measured: optimization level 1 and schedule on reproduce this member's
   straight-line order and filled jr delay slot. */
#pragma optimization_level 1
#pragma schedule on
u32 func_004f98a8(u8 *a0, u8 *a1, u8 *a2)
{
    u32 x;
    u32 y;
    u32 result;

    x = a1[0];
    y = a0[3];
    result = y + x;
    a2[0] = result;
    x = a0[7];
    a2[1] = x;
    x = a1[1];
    y = a0[2];
    result = y ^ x;
    a2[2] = result;
    x = a0[6];
    a2[3] = x;
    x = a0[1];
    a2[4] = x;
    x = a1[2];
    y = a0[5];
    result = y ^ x;
    a2[5] = result;
    x = a0[0];
    a2[6] = x;
    y = a0[4];
    x = a1[3];
    result = y + x;
    a2[7] = result;
    return result;
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f98a8);
#endif

/* Parked candidate: the split u32 donor shape leaves the copy-load and tail
   register residuals at nd 4; measured middle, typed-copy, and tail variants.
   Committed at nd 4. */
// FUN_004F9910
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9910);

/* measured: this member uses the same split u32 temporary shape as the
   measured leader, with its own byte permutation order. */
#pragma optimization_level 1
#pragma schedule on
// FUN_004F9978
void func_004f9978(u8 *a0, u8 *a1, u8 *a2) {
    *(u8 *)(a2 + 0) = (u8)*(u8 *)(a0 + 3);
    *(s8 *)(a2 + 1) = (s8)(*(u8 *)(a0 + 0) ^ *(u8 *)(a1 + 1));
    *(u8 *)(a2 + 2) = (u8)*(u8 *)(a0 + 6);
    *(s8 *)(a2 + 3) = (s8)(*(u8 *)(a0 + 4) + *(u8 *)(a1 + 0));
    *(s8 *)(a2 + 4) = (s8)(*(u8 *)(a0 + 2) ^ *(u8 *)(a1 + 3));
    *(u8 *)(a2 + 5) = (u8)*(u8 *)(a0 + 7);
    *(u8 *)(a2 + 6) = (u8)*(u8 *)(a0 + 1);
    *(s8 *)(a2 + 7) = (s8)(*(u8 *)(a0 + 5) + *(u8 *)(a1 + 2));
}
/* measured: restore the file's optimization and schedule states. */
#pragma schedule off
/* measured: restore optimization level 2 after the isolated function. */
#pragma optimization_level 2
// FUN_004F99E0
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f99e0);
// FUN_004F99F8
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f99f8);
// FUN_004F9A10
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a10);
// FUN_004F9A58
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a58);
// FUN_004F9A70
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f9a70);