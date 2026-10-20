#include "byte_address_internal.h"
#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void poolFree(s32 address);


extern s32 D_008815B0[];



extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern void itfMesWindowStepState(u8 *window);
extern void itfMesWindowAdvanceRow(u8 *window);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027a6f0-0027a970 */

extern void datSetIndexedWord(s32 index, s32 value);
extern s32 itfMesWindowSendOpeningStep(s32 handle);
extern s32 itfMesWindowSendActiveStep(s32 handle);
extern s32 itfMesWindowSendClosingStep(s32 handle);
extern s32 itfMesWindowSendChoiceOpeningStep(s32 handle);
extern s32 itfMesWindowSendChoiceActiveStep(s32 handle);
extern s32 itfMesWindowSendChoiceClosingStep(s32 handle);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Clears the 0xF00 state field (bits 8 to 11) of the word at value [inferred].
// FUN_0027A6F0
void itfMesWindowClearStateField(s32 *window)
{
    *window &= ~0xF00;
}

// Intent: Frees up to 32 non-null slot entries and clears them [inferred]
// FUN_0027A710
void itfMesWindowFreeSlots(s32 window) {
    s32 i;
    s32 *p;
    s32 v;

    for (i = 0; i < 0x20; i++) {
        p = (s32 *)(window + i * 4);
        v = *p;
        if (v != 0) {
            poolFree(v);
            *p = 0;
        }
    }
}

// Intent: Advances one list node's window state by calling its op handlers (ops 4, 5, 6, 0xA, 0xB, 0xC) [inferred]
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 1; retain their original address/alias expressions. */
// FUN_0027A780
void itfMesWindowStepState(u8 *window)
{
    extern s32 itfMesWindowSendOpeningStep(s32 handle);
    extern s32 itfMesWindowSendActiveStep(s32 handle);
    extern s32 itfMesWindowSendClosingStep(s32 handle);
    extern s32 itfMesWindowSendChoiceOpeningStep(s32 handle);
    extern s32 itfMesWindowSendChoiceActiveStep(s32 handle);
    extern s32 itfMesWindowSendChoiceClosingStep(s32 handle);
    extern void frFontRunCommand(s32 stream, s32 mode, s32 command);
    s32 value;
    u8 *node;

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
    switch (((ItfMesWindow *)window)->flags.value & 0x300)
    {
    case 0x100:
        if (itfMesWindowSendOpeningStep(value) != 0) {
            s16 index;
            s32 count;
            u8 *table;
            s32 selected;

            index = ((ItfMesWindow *)window)->row.index;
            table = ((ItfMesWindow *)window)->row.record.bytes;
            count = ((ItfMesTextRecord *)table)->count;
            if (index < 0 || index >= count)
                selected = 0;
            else
                selected = ((ItfMesTextRecord *)((u8 *)((u32)byteAddressAdd(((u32)(index * 4)), (u8 *)(u32)table))))->texts[0].value;
            frFontRunCommand(selected, 1, 0);
            ((ItfMesWindow *)window)->flags.value = ((ItfMesWindow *)window)->flags.value & ~0x307;
            ((ItfMesWindow *)window)->flags.value |= 0x203;
        }
        break;
    case 0x200:
        itfMesWindowSendActiveStep(value);
        break;
    case 0x300:
        if (itfMesWindowSendClosingStep(value) != 0)
            ((ItfMesWindow *)window)->flags.value &= ~0x300;
        break;
    }
    switch (((ItfMesWindow *)window)->flags.value & 0xC00)
    {
    case 0x400:
        if (itfMesWindowSendChoiceOpeningStep(value) != 0) {
            ((ItfMesWindow *)window)->flags.value = ((ItfMesWindow *)window)->flags.value & ~0xC07;
            ((ItfMesWindow *)window)->flags.value |= 0x803;
        }
        break;
    case 0x800:
        itfMesWindowSendChoiceActiveStep(value);
        break;
    case 0xC00:
        if (itfMesWindowSendChoiceClosingStep(value) != 0)
            ((ItfMesWindow *)window)->flags.value &= ~0xC00;
        break;
    }
}

// Intent: Advances a window's row state: counts frames, runs the row action when ready, copies slots and builds the row [inferred]
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 443, 495, 536; retain their original address/alias expressions. */
// FUN_0027A970
void itfMesWindowAdvanceRow(u8 *window)
{
    ItfMesRow *transitionFields;
    ItfMesRow *elapsedBitsFields;
    ItfMesRow *indexFields;

    extern void frFontEnableList(u8 *node);
    extern s32 frFontMeasureList(u8 *list);
    extern void frFontLoadSystemSlot(u8 *fontData);
    extern void datSetIndexedWord(s32 index, s32 value);
    extern void itfMesWindowBuildRow(u8 *window);
    extern void func_00440b68(void *window);
    extern void sdkSndResetChannel(s32 window, s32 value);
    extern u16 D_008C024C[];
    extern s32 iGpffffb4d0;
    extern u8 D_0063BF40[];
    u8 *state;
    s32 index;
    u8 *iter;
    u32 count;

    state = window + 0x1C;
    if (((ItfMesWindow *)window)->row.state.value == 1) {
        if ((((ItfMesWindow *)window)->flags.value & 7) == 4) {
            ((ItfMesRow *)state)->elapsed.value += 1;
            if (((ItfMesWindow *)window)->flags.value & 0x800000) {
                ((ItfMesRow *)state)->state.value = -1;
                return;
            }
            if ((((ItfMesWindow *)window)->flags.value & 0x100000) == 0 &&
                (((ItfMesRow *)state)->transition == 0 ||
                 ((ItfMesRow *)state)->transition == 3)) {
                (transitionFields = (ItfMesRow *)(state), transitionFields)->transition = 1;
            }
            if ((((ItfMesWindow *)window)->flags.value & 0x4000000) == 0) {
                if ((D_008C024E[0] & 0x40) != 0 ||
                    (D_008C024E[0] & 0x20) != 0) {
                    goto do_action;
                }
                if ((D_008C024C[0] & 0x10) == 0)
                    goto state_check;
                count = (elapsedBitsFields = (ItfMesRow *)(state), elapsedBitsFields)->elapsed.bits;
                if (count > 4U) {
                    if ((iGpffffb4d0 & 1) == 0)
                        goto do_action;
                } else {
                    goto state_check;
                }
            }
state_check:
            if (((ItfMesRow *)state)->flags.bits != 0) {
                if ((((ItfMesWindow *)window)->flags.value & 0x8000000) == 0)
                    return;
                if (frFontMeasureList(((ItfMesRow *)state)->list.bytes) == 0)
                    return;
            }
do_action:
                func_00440b68(D_0063BF40);
                ((ItfMesRow *)state)->transition = 3;
                ((ItfMesRow *)state)->index += 1;
                sdkSndResetChannel(1, 0);
                if ((indexFields = (ItfMesRow *)(state), indexFields)->index >= ((ItfMesRow *)state)->count) {
                    ((ItfMesRow *)state)->state.value = -1;
                    return;
                }
                index = 0;
                while (index < 32) {
                    datSetIndexedWord(index,
                        ((ItfMesWindow *)window)->slots[index].value);
                    index += 1;
                }
                if (((ItfMesWindow *)window)->font.value != 0)
                    frFontLoadSystemSlot((u8 *)((ItfMesWindow *)window)->font.value);
                itfMesWindowBuildRow(window);
                ((ItfMesWindow *)window)->flags.value = ((ItfMesWindow *)window)->flags.value & ~7;
                ((ItfMesWindow *)window)->flags.value |= 3;
        } else {
            if ((((ItfMesWindow *)window)->flags.value & 0x4000000) == 0 &&
                ((D_008C024E[0] & 0x40) != 0 ||
                 (D_008C024E[0] & 0x20) != 0 ||
                 ((D_008C024C[0] & 0x10) != 0 &&
                  (iGpffffb4d0 & 1) == 0)) &&
                (((ItfMesWindow *)window)->flags.value & 0x400000) == 0 &&
                (((ItfMesWindow *)window)->flags.value & 0x1000000) == 0) {
                iter = ((ItfMesRow *)state)->list.bytes;
                while (iter != NULL) {
                    frFontEnableList(iter);
                    iter = *(u8 **)&((FrFontTextRun *)iter)->previous;
                }
                if (((ItfMesWindow *)window)->label.list.bytes != NULL)
                    frFontEnableList(((ItfMesWindow *)window)->label.list.bytes);
            }
            ((ItfMesWindow *)window)->flags.value = ((ItfMesWindow *)window)->flags.value & 0xFEFFFFFF;
        }
    }
}

