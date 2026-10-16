#include "btl_action_internal.h"
#include "list_item_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_draw_task.h"
#include "fcl_bounds_packet.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "message_handle.h"
#include "shd_misc_internal.h"
static inline s32 p4_pack_or(s32 left, s32 right)
{
    return left | right;
}
static inline f32 p4_mul_left(f32 left, f32 right)
{
    return right * left;
}



extern s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 *D_0072466C;
extern s32 D_0063F2C8[];
extern s32 D_00882F60[];
extern void kAssertFail(const void *arg0, s32 arg1);
extern char D_0063F2A0[];
extern char D_007488E8[];


extern u8 *D_00882F40[];
extern s32 D_0063F2B0[];
extern u8 D_00793E80[];
extern u8 D_0063F1F0[];
extern s8 D_007488F8[];
extern s8 D_00764670;
extern s8 iGpffffb580;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s8 iGpffffb578;
extern s32 iGpffffb55c;
extern s32 iGpffffb57c;
extern void itfMesWindowDrawEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 itfMesWindowQueueEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6);
extern u32 datEntryGetFlags(s16 item);
extern u8 *func_002e2170(u8 *arg0, s32 arg1, s32 arg2);
extern void sprintf();
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 arg0);
extern s32 sdkSpriteRequestLoad(void *arg0);
extern s32 func_0046a750(s32 arg0);
extern void sdkSpriteRelease(void *arg0);
extern void func_002e2240(void *arg0, void *arg1, void *arg2);
extern char D_0063F340[];
extern char D_0063F360[];
extern char D_0063F380[];
extern f32 iGpffff82fc;
extern u8 D_0063F3B0[];



extern u32 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 *D_0063F110[];
extern s8 D_007488C0[];



/* Retail digit RGBA occupies the four bytes at draw+0x75.
   MWCC requires packed after the typedef name. These guarded
   storage views preserve the native FclDrawColor call interface.
   See docs/probe_archive/Fcl_digit_packed_storage_ui_20261006. */
#ifdef NON_MATCHING
typedef union {
    FclDrawColor channels;
    u32 word;
} FclDigitColorStorage;
typedef struct {
    u32 word;
} FclDigitStoredWord __attribute__((packed));
typedef struct {
    u8 prefix;
    FclDigitStoredWord storage;
} FclDigitStoredWordAlignment;
typedef char FclDigitStoredWordSize[(sizeof(FclDigitStoredWord) == 4) ? 1 : -1];
typedef char FclDigitStoredWordByteAligned[(sizeof(FclDigitStoredWordAlignment) == 5) ? 1 : -1];
typedef char FclDigitColorStorageSize[(sizeof(FclDigitColorStorage) == 4) ? 1 : -1];
#endif

/* Source unit: src/promoted/code1_002b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002b.c; members 002bc0b0-002bcbc0 */

extern void func_002b5120(s32 arg0, u8 *arg1);
/* measured: opt_rebuildconditionals off probe for min/max */
/* measured: close opt_rebuildconditionals after min/max */
/* measured: opt_loop_invariants on adds retail's second divide hazard nop. */
/* measured: close opt_loop_invariants after 3170. */
/* measured: opt_loop_invariants on hoists the tag constants out of the loop. */
/* measured: closes the loop-invariant bracket; the unit default is off. */
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
/* measured: restores opt_propagation after func_002b5120. */
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma pop
/* Row and value are signed halfwords; retail discards incoming row high bits.
   Rewritten on the matched func_002ba5d0 pattern. Retail passes both colours
   as words (the parameter home reloaded with lw, the stored digit colour with
   lwl/lwr), so the block-scope callee declaration takes u32 colours; the two
   copies are spelled differently so only post-colouring CSE shares them.
   The redraw positions are named locals, which puts their frame slots above
   secondPosition as in retail. Depth precedes layer, as in func_002ba5d0:
   retail copies $f12 before $t3 in the prologue, and both callers still
   match. opt_dead_assignments off reproduces retail's late argument loads. */
#pragma push
#pragma pop
/* Keep the two positions, colors, and character-representation bounds
   snapshots separate across writes to the draw slots. The depth precedes
   the layer in the recovered signature. See the worker3 digit-pair archive. */
#pragma push
#pragma pop
/* Preserve the RGBA snapshot and later alpha reload across byte stores.
   Measured: object 168B/window 176B, no instruction differences; 8B zero tail. */
// FUN_002BC0B0
void func_002bc0b0(f32 x, f32 y, f32 depth, u32 color, u32 font, u32 mode,
                   s32 table, s32 item)
{
    func_002bc0e0(x, y, depth, color, font, mode, 1, table, item);
}

// FUN_002BC0E0
 s32 func_002bc0e0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    extern s32 func_00106600(s16 id);
    extern u32 datEntryGetFlags(s16 arg0);
    extern s32 itfMesWindowRecordCount(s32 arg0);
    extern s32 itfMesWindowDrawEntry(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    extern s32 itfMesWindowDrawPair(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);
    extern s32 D_0063F2F0[];
    extern s32 D_0063F310[];
    extern s32 D_0063F2C0[];
    s32 spC0[6];
    s32 sp90[9];
    s32 *src;
    s32 *dst;
    u32 temp_22;
    s32 *src2;
    s32 *dst2;
    s32 loop;
    s32 loop2;
    s32 temp_1;
    s32 temp_2;
    s32 temp_index;
    s32 temp_item_index;
    s32 temp_item;
    s32 temp_level;
    u32 temp_index_2;
    s32 temp_count;

    src = D_0063F2F0;
    dst = spC0;
    loop = 3;
    do {
        temp_1 = src[0];
        temp_2 = src[1];
        src += 2;
        loop -= 1;
        dst[0] = temp_1;
        dst[1] = temp_2;
        dst += 2;
    } while (loop > 0);
    src2 = D_0063F310;
    dst2 = sp90;
    loop2 = 9;
    do {
        temp_1 = *src2;
        src2 += 1;
        loop2 -= 1;
        *dst2 = temp_1;
        dst2 += 1;
    } while (loop2 > 0);
    switch (arg4) {
    case 0:
        if (arg5 >= 0x400) {
            temp_index = 5;
        } else {
            temp_index = (s32)datEntryGetFlags((s16)arg5);
        }
        temp_item_index = spC0[temp_index];
        arg5 = (s16)func_00106b80((s16)arg5);
        goto block_23;
    case 1:
        temp_index_2 = arg5 & 0xFFFF;
        temp_item_index = spC0[datEntryGetFlags((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)itfMesWindowRecordCount(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_level = arg5 >> 16;
        if ((u32)itfMesWindowRecordCount(D_0063F2C0[0]) < (u32)temp_level) {
            return 0;
        }
        itfMesWindowDrawPair(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], temp_level);
        return 0;
    case 2:
        temp_index_2 = func_00106600((s16)arg5) & 0xFF;
        temp_item_index = spC0[datEntryGetFlags((s16)temp_index_2)];
        temp_item = D_0063F2B0[temp_item_index];
        temp_count = (s16)func_00106b80((s16)temp_index_2);
        if ((u32)itfMesWindowRecordCount(temp_item) < (u32)temp_count) {
            return 0;
        }
        temp_22 = itfMesWindowRecordCount(D_0063F2C0[0]);
        if (temp_22 < (u32)(func_00106600((s16)arg5) & 0xFF)) {
            return 0;
        }
        itfMesWindowDrawPair(fparg0, fparg1, fparg2,
                      arg0, arg1, arg2, 1, temp_item, temp_count,
                      D_0063F2C0[0], func_00106600((s16)arg5) & 0xFF);
        return 0;
    default:
        temp_item_index = sp90[arg4];
        goto block_23;
    }
block_23:
    temp_item = D_0063F2B0[temp_item_index];
    if ((u32)itfMesWindowRecordCount(temp_item) < (u32)arg5) {
        return 0;
    }
    itfMesWindowDrawEntry(fparg0, fparg1, fparg2,
                  arg0, arg1, arg2, arg3, temp_item, arg5);
    return 0;
}

/* Both metadata queries share the signed halfword item ID. Capture the
 * remaining inputs before those calls; scoped propagation preserves their
 * retail entry order, all 740 code bytes, and the six-way table. */
#pragma push
/* measured: func_002bc4b0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_002BC4B0
void func_002bc4b0(f32 inputDepth, s16 arg0, s32 arg1, s32 arg2,
                    s32 inputArg3, s32 inputArg4, s32 inputArg5)
{
    extern s32 itfMesWindowDrawEntry(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    u32 temp_2;
    f32 fparg0;
    s32 arg3;
    s32 arg4;
    s32 arg5;

    fparg0 = inputDepth;
    arg3 = inputArg3;
    arg4 = inputArg4;
    arg5 = inputArg5;
    temp_2 = func_00106850(arg0);
    switch (temp_2) {
    case 0:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[0],
                      (s16)func_00106b80(arg0));
        return;
    case 1:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[1],
                      (s16)func_00106b80(arg0));
        return;
    case 2:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[2],
                      (s16)func_00106b80(arg0));
        return;
    case 3:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[4],
                      (s16)func_00106b80(arg0));
        return;
    case 4:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[5],
                      (s16)func_00106b80(arg0));
        return;
    case 5:
        itfMesWindowDrawEntry((f32)arg1, (f32)arg2, fparg0,
                      arg3, arg4, arg5, 1, D_0063F2B0[7],
                      (s16)func_00106b80(arg0));
    default:
        return;
    }
}

#pragma pop
// FUN_002BC7A0
void func_002bc7a0(s32 item, f32 x, f32 y, f32 depth,
                    s32 color, s32 font, s32 mode, s32 table)
{
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 depth, s32 color, s32 font,
                            s32 mode, s32 flags, s32 table, s32 item);
    itfMesWindowDrawEntry(x, y, depth, color, font, mode, 1, D_0063F2B0[(s8)table], item);
}

// FUN_002BC7F0
void func_002bc7f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0, f32 fparg1, f32 fparg2) {
    itfMesWindowQueueEntry(fparg0, fparg1, fparg2, arg1, arg2, arg3, 1, D_0063F2B0[(s8)arg4], arg0, &D_00793E80[arg5 * 0x30]);
}

// FUN_002BC860
void func_002bc860(f32 x, f32 y, f32 depth,
                    s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 depth, s32 arg0, s32 arg1,
                            s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    itfMesWindowDrawEntry(x, y, depth, arg0, arg1, arg2, 1, D_0063F2C8[0], arg3);
}

// FUN_002BC890
s32 func_002bc890(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *owner;
    u8 *var_4;
    u8 *var_5;

    if (arg0 == NULL) kAssertFail(&D_0063F2A0, 0x541);
    if (arg1 < 0) goto invalid_arg;
    if (arg1 > 0xB) goto invalid_arg;
    goto valid_arg;
invalid_arg:
    kAssertFail(&D_0063F2A0, 0x542);
valid_arg:
    temp_2 = arg0 + (arg1 * 0xC);
    temp_16 = temp_2 + 0x1C;
    temp_3 = *(s32 *)temp_16;
    if (!(temp_3 & 2)) {
        var_4 = *(u8 **)(*(u8 **)(arg0 + 0x18) + 4);
        goto loop_test;
loop_body:
        var_5 = *(u8 **)(var_4 + 0x14);
        if (*(s32 *)(var_5 + 4) == arg1) {
            owner = var_5;
        } else {
            var_4 = *(u8 **)(var_4 + 0x10);
loop_test:
            if (var_4 != NULL) {
                goto loop_body;
            }
            owner = NULL;
        }
        goto loop_done;
loop_done:
        if (owner == NULL) {
            *(s32 *)(temp_16 + 4) = arg1;
            temp_4 = *(u8 **)(arg0 + 0x18);
            temp_2_2 = func_002e2170(temp_4, *(u16 *)(temp_4 + 0x10) + 1, 0);
            if (temp_2_2 == NULL) kAssertFail(&D_007488E8, 0x52);
            *(u8 **)(temp_2_2 + 0x14) = temp_16;
            return 1;
        }
    }
    if (temp_3 & 4) *(s32 *)temp_16 = temp_3 & ~4;
    return 0;
}

// FUN_002BC9E0
s32 func_002bc9e0(u8 *arg0)
{
    u8 sp40[0x20];
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_4_3;
    s32 var_17;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_4_2;
    u8 *var_16;

    if (arg0 == NULL) {
        kAssertFail(&D_0063F2A0, 0x558);
    }
    temp_18 = *(u8 **)(*(u8 **)(arg0 + 0x18) + 4);
    if (temp_18 != NULL) {
        temp_17 = *(u8 **)(temp_18 + 0x14);
        temp_4 = *(s32 *)(temp_17 + 8);
        if (temp_4 == 0) {
            if (*(s32 *)(temp_17 + 4) == 0) {
                sprintf(sp40, &D_0063F340);
            } else if ((func_00110d60((s16)func_001060b0()) & 1) != 0) {
                sprintf(sp40, &D_0063F360, *(s32 *)(temp_17 + 4));
            } else {
                sprintf(sp40, &D_0063F380, *(s32 *)(temp_17 + 4));
            }
            *(s32 *)(temp_17 + 8) = sdkSpriteRequestLoad(sp40);
        } else if (func_0046a750(temp_4) != 0) {
            *(s32 *)(temp_17 + 0) = *(s32 *)(temp_17 + 0) | 2;
            temp_4_2 = *(u8 **)(arg0 + 0x18);
            func_002e2240(temp_4_2, temp_4_2 + 4, temp_18);
        }
    }
    var_16 = arg0 + 0x1C;
    var_17 = 0;
    goto loop_19;
loop_20:
    temp_3 = *(s32 *)var_16;
    if (temp_3 & 4) {
        temp_4_3 = *(s32 *)(var_16 + 8);
        if (temp_4_3 != 0) {
            if (func_0046a750(temp_4_3) != 0) {
                temp_3_2 = *(s32 *)var_16 & ~4;
                *(s32 *)var_16 = temp_3_2;
                *(s32 *)var_16 = temp_3_2 & ~2;
                sdkSpriteRelease(*(void **)(var_16 + 8));
                *(s32 *)(var_16 + 8) = 0;
            }
        } else {
            temp_3_3 = temp_3 & ~4;
            *(s32 *)var_16 = temp_3_3;
            *(s32 *)var_16 = temp_3_3 & ~2;
        }
    }
    var_16 += 0xC;
    var_17 += 1;
loop_19:
    if (var_17 < 0xB) {
        goto loop_20;
    }
    return 0;
}

// FUN_002BCBC0
s32 func_002bcbc0(u8 *arg0, s32 arg1)
{
    u8 *temp_3;

    if (arg0 == 0) {
        kAssertFail(D_0063F2A0, 0x58F);
    }
    if (arg1 < 0) {
        goto error;
    }
    if (arg1 <= 0xB) {
        goto done;
    }
error:
    kAssertFail(D_0063F2A0, 0x590);
done:
    temp_3 = arg0 + arg1 * 0xC;
    *(s32 *)(temp_3 + 0x1C) |= 4;
    return 0;
}

