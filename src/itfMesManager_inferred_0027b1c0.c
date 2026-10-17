#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];



extern s32 D_008815B0[];

static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern void itfMesWindowStepState(u8 *arg0);
extern void itfMesWindowAdvanceRow(u8 *arg0);
extern void itfMesWindowCommitSelection(u8 *arg0);
extern void itfMesWindowStepTransition(u8 *arg0);
extern void itfMesWindowQueueCallback(s32 arg0);
extern s32 func_0027bd40(s32 arg0);
extern s32 func_0027bda0(s32 arg0);
extern s32 func_0027be00(s32 arg0);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027b1c0-0027b500 */

extern void itfMesWindowStepState(u8 *arg0);
extern void itfMesWindowAdvanceRow(u8 *arg0);
extern void itfMesWindowCommitSelection(u8 *arg0);
extern void itfMesWindowQueueCallback(s32 arg0);
extern s32 func_0027b910(s32 arg0);
extern s32 func_0027bd40(s32 arg0);
extern s32 func_0027bda0(s32 arg0);
extern s32 func_0027be00(s32 arg0);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Returns the entry value whose bit is set in the pressed-input mask, or -1 [inferred]
// FUN_0027B1C0
/* measured: opt_loop_invariants hoists mask/count/const-1 into preheader */
/* measured: itfMesWindowFindPressedEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 itfMesWindowFindPressedEntry(s16 *arg0)
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
// Intent: Advances a window's transition state (waits on ops 0x10, 0x11, 0x12) [inferred]
// FUN_0027B230
void itfMesWindowStepTransition(u8 *arg0)
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

// Intent: Updates a window's three lists: draws them and advances the window's list state [inferred]
// FUN_0027B310
void itfMesWindowUpdateLists(u8 *arg0)
{
    extern s32 frFontDrawListDefault(s32 arg0);
    extern s32 frFontDrawListMode(s32 arg0, s32 arg1);
    extern void itfMesWindowMarkRedraw(void);
    extern s32 func_0027b910(s32 arg0);
    s32 flags;
    u32 mask;
    s32 value;
    u8 *node;

    flags = *(s32 *)arg0;
    D_008817E8[0] &= 0xFFFD;
    itfMesWindowMarkRedraw();
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
            frFontDrawListDefault(first);
        }
    }
    {
        s32 second;

        second = *(s32 *)(arg0 + 0x20);
        if (mask == 0 &&
            (u32)(flags & 7) >= 3U &&
            frFontDrawListDefault(second) > 0) {
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
                frFontDrawListMode(third, 1) > 0 &&
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

// Intent: Marks the window for redraw when it is visible and in an active state [inferred]
// FUN_0027B4C0
void itfMesWindowMarkRedraw(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

// Intent: Per-frame task update: steps each window's state, row, selection and transition, then queues the callback [inferred]
// FUN_0027B500
s32 itfMesWindowTaskUpdate(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    u8 *node;
    u8 *temp;

    node = D_008817EC[0];
    while (node != NULL)
    {
        temp = *(u8 **)(node + 0xC);
        itfMesWindowStepState(temp);
        itfMesWindowAdvanceRow(temp);
        itfMesWindowCommitSelection(temp);
        itfMesWindowStepTransition(temp);
        node = *(u8 **)(node + 4);
    }
    itfMesWindowQueueCallback(arg0);
    return 0;
}

