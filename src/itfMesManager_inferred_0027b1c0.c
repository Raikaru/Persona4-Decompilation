#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
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
extern void itfMesWindowStepState(u8 *window);
extern void itfMesWindowAdvanceRow(u8 *window);
extern void itfMesWindowCommitSelection(u8 *window);
extern void itfMesWindowStepTransition(u8 *window);
extern void itfMesWindowQueueCallback(s32 taskAddress);
extern s32 itfMesWindowSendRowTransitionEnter(s32 handle);
extern s32 itfMesWindowSendRowTransitionActive(s32 handle);
extern s32 itfMesWindowSendRowTransitionLeave(s32 handle);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027b1c0-0027b500 */

extern void itfMesWindowStepState(u8 *window);
extern void itfMesWindowAdvanceRow(u8 *window);
extern void itfMesWindowCommitSelection(u8 *window);
extern void itfMesWindowQueueCallback(s32 taskAddress);
extern s32 itfMesWindowSendDrawLists(s32 handle);
extern s32 itfMesWindowSendRowTransitionEnter(s32 handle);
extern s32 itfMesWindowSendRowTransitionActive(s32 handle);
extern s32 itfMesWindowSendRowTransitionLeave(s32 handle);
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
s32 itfMesWindowFindPressedEntry(s16 *selection)
{
    s32 i = 0;
    u16 mask;
    s32 count;
    s32 bit;
    s16 *p;

    mask = D_008C024E[0];
    count = ((ItfMesSelection *)(u8 *)selection)->bindingCount;
    for (; i < count; i++) {
        p = (s16 *)((u8 *)selection + i * 4 + 0x18);
        bit = *p;
        if ((1 << bit) & mask) {
            return ((ItfMesInputBinding *)(u8 *)p)->entry;
        }
    }
    return -1;
}

/* measured: opt_loop_invariants off */
// Intent: Advances a selection's transition state (waits on ops 0x10, 0x11, 0x12) [inferred]
// FUN_0027B230
void itfMesWindowStepTransition(u8 *window)
{
    s16 *state;
    u8 *node;
    s32 value;

    state = (s16 *)(window + 0x34);
    node = D_008817EC[0];
    goto node_check;
node_body:
    if (((ItfMesManagerEntry *)node)->object.bytes == window)
    {
        value = ((ItfMesManagerEntry *)node)->handle.value;
        goto node_done;
    }
    node = ((ItfMesManagerEntry *)node)->next.bytes;
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
        if (itfMesWindowSendRowTransitionEnter(value) != 0)
            *state = 2;
        break;
    case 2:
        itfMesWindowSendRowTransitionActive(value);
        break;
    case 3:
        if (itfMesWindowSendRowTransitionLeave(value) != 0)
            *state = 0;
        break;
    }
}

// Intent: Updates a window's three lists: draws them and advances the window's list state [inferred]
// FUN_0027B310
void itfMesWindowUpdateLists(u8 *window)
{
    extern s32 frFontDrawListDefault(s32 list);
    extern s32 frFontDrawListMode(s32 list, s32 mode);
    extern void itfMesWindowMarkRedraw(void);
    extern s32 itfMesWindowSendDrawLists(s32 handle);
    s32 flags;
    u32 mask;
    s32 value;
    u8 *node;

    flags = ((ItfMesWindow *)window)->flags.value;
    D_008817E8[0] &= 0xFFFD;
    itfMesWindowMarkRedraw();
    node = D_008817EC[0];
    goto node_check;
node_body:
    if (((ItfMesManagerEntry *)node)->object.bytes == window) {
        value = ((ItfMesManagerEntry *)node)->handle.value;
        goto node_done;
    }
    node = ((ItfMesManagerEntry *)node)->next.bytes;
node_check:
    if (node != NULL)
        goto node_body;
    value = -1;
node_done:
    itfMesWindowSendDrawLists(value);

    {
        s32 first;

        first = ((ItfMesWindow *)window)->label.list.value;
        if ((mask = flags & 0x20000) == 0 &&
            (u32)(flags & 7) >= 3U &&
            (flags & 0x10000) == 0 &&
            first != 0) {
            frFontDrawListDefault(first);
        }
    }
    {
        s32 second;

        second = ((ItfMesWindow *)window)->row.list.value;
        if (mask == 0 &&
            (u32)(flags & 7) >= 3U &&
            frFontDrawListDefault(second) > 0) {
            s32 current;

            current = ((ItfMesWindow *)window)->flags.value;
            if ((current & 7) != 4) {
                current &= ~7;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 4;
                ((ItfMesWindow *)window)->flags.value = current;
                ((ItfMesWindow *)window)->row.elapsed.value = 0;
            }
        }
    }
    {
        s32 third;

        third = ((ItfMesWindow *)window)->selection.list.value;
        if ((flags & 0x40000) == 0) {
            mask = flags & 0x38;
            if (mask >= 0x18U &&
                frFontDrawListMode(third, 1) > 0 &&
                mask == 0x18U) {
                u8 *state;
                s32 current;

                state = window + 0x3C;
                if (((ItfMesWindow *)window)->selection.cursor == -1) {
                    ((ItfMesSelection *)state)->cursor = 0;
                    ((ItfMesSelection *)state)->selected = 0;
                }
                current = ((ItfMesWindow *)window)->flags.value;
                current &= ~0x38;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 0x20;
                ((ItfMesWindow *)window)->flags.value = current;
            }
        }
    }
}

// Intent: Marks the window for redraw when it is visible and in an active state [inferred]
// FUN_0027B4C0
void itfMesWindowMarkRedraw(s32 *window)
{
    s32 windowObject;

    windowObject = *window;
    if (!(windowObject & 0x80000) && ((u32)(windowObject & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

// Intent: Per-frame task update: steps each window's state, row, selection and transition, then queues the callback [inferred]
// FUN_0027B500
s32 itfMesWindowTaskUpdate(u8 *sdkTaskBytes)
{
    s32 window = (s32)sdkTaskBytes;
    u8 *node;
    u8 *windowObject;

    node = D_008817EC[0];
    while (node != NULL)
    {
        windowObject = ((ItfMesManagerEntry *)node)->object.bytes;
        itfMesWindowStepState(windowObject);
        itfMesWindowAdvanceRow(windowObject);
        itfMesWindowCommitSelection(windowObject);
        itfMesWindowStepTransition(windowObject);
        node = ((ItfMesManagerEntry *)node)->next.bytes;
    }
    itfMesWindowQueueCallback(window);
    return 0;
}

