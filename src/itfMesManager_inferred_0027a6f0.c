#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void poolFree(s32 arg0);


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
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027a6f0-0027a970 */

extern void func_002746c0(s32 arg0, s32 arg1);
extern s32 func_0027b980(s32 arg0);
extern s32 func_0027b9e0(s32 arg0);
extern s32 func_0027ba40(s32 arg0);
extern s32 func_0027bc20(s32 arg0);
extern s32 func_0027bc80(s32 arg0);
extern s32 func_0027bce0(s32 arg0);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Clears the 0xF00 state field (bits 8 to 11) of the word at arg0 [inferred].
// FUN_0027A6F0
void itfMesWindowClearStateField(s32 *arg0)
{
    *arg0 &= ~0xF00;
}

// Intent: Frees up to 32 non-null slot entries and clears them [inferred]
// FUN_0027A710
void itfMesWindowFreeSlots(s32 arg0) {
    s32 i;
    s32 *p;
    s32 v;

    for (i = 0; i < 0x20; i++) {
        p = (s32 *)(arg0 + i * 4);
        v = *p;
        if (v != 0) {
            poolFree(v);
            *p = 0;
        }
    }
}

// Intent: Advances one list node's window state by calling its op handlers (ops 4, 5, 6, 0xA, 0xB, 0xC) [inferred]
// FUN_0027A780
void itfMesWindowStepState(u8 *arg0)
{
    extern s32 func_0027b980(s32 arg0);
    extern s32 func_0027b9e0(s32 arg0);
    extern s32 func_0027ba40(s32 arg0);
    extern s32 func_0027bc20(s32 arg0);
    extern s32 func_0027bc80(s32 arg0);
    extern s32 func_0027bce0(s32 arg0);
    extern void frFontRunCommand(s32 arg0, s32 arg1, s32 arg2);
    s32 value;
    u8 *node;

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
    switch (*(s32 *)arg0 & 0x300)
    {
    case 0x100:
        if (func_0027b980(value) != 0) {
            s16 index;
            s32 count;
            u8 *table;
            s32 selected;

            index = *(s16 *)(arg0 + 0x2C);
            table = *(u8 **)(arg0 + 0x1C);
            count = *(s16 *)(table + 0x18);
            if (index < 0 || index >= count)
                selected = 0;
            else
                selected = *(s32 *)((u8 *)add_retail_ptr((u32)(index * 4), (u32)table) + 0x1C);
            frFontRunCommand(selected, 1, 0);
            *(s32 *)arg0 = *(s32 *)arg0 & ~0x307;
            *(s32 *)arg0 |= 0x203;
        }
        break;
    case 0x200:
        func_0027b9e0(value);
        break;
    case 0x300:
        if (func_0027ba40(value) != 0)
            *(s32 *)arg0 &= ~0x300;
        break;
    }
    switch (*(s32 *)arg0 & 0xC00)
    {
    case 0x400:
        if (func_0027bc20(value) != 0) {
            *(s32 *)arg0 = *(s32 *)arg0 & ~0xC07;
            *(s32 *)arg0 |= 0x803;
        }
        break;
    case 0x800:
        func_0027bc80(value);
        break;
    case 0xC00:
        if (func_0027bce0(value) != 0)
            *(s32 *)arg0 &= ~0xC00;
        break;
    }
}

// Intent: Advances a window's row state: counts frames, runs the row action when ready, copies slots and builds the row [inferred]
// FUN_0027A970
void itfMesWindowAdvanceRow(u8 *arg0)
{
    extern void frFontEnableList(u8 *arg0);
    extern s32 frFontMeasureList(u8 *arg0);
    extern void frFontLoadSystemSlot(u8 *arg0);
    extern void func_002746c0(s32 arg0, s32 arg1);
    extern void itfMesWindowBuildRow(u8 *arg0);
    extern void func_00440b68(void *arg0);
    extern void sdkSndResetChannel(s32 arg0, s32 arg1);
    extern u16 D_008C024C[];
    extern s32 iGpffffb4d0;
    extern u8 D_0063BF40[];
    u8 *state;
    s32 index;
    u8 *iter;
    u32 count;

    state = arg0 + 0x1C;
    if (*(s8 *)(arg0 + 0x24) == 1) {
        if ((*(s32 *)arg0 & 7) == 4) {
            *(s32 *)(state + 0x14) += 1;
            if (*(s32 *)arg0 & 0x800000) {
                *(s8 *)(state + 8) = -1;
                return;
            }
            if ((*(s32 *)arg0 & 0x100000) == 0 &&
                (*(s16 *)(state + 0x18) == 0 ||
                 *(s16 *)(state + 0x18) == 3)) {
                *(s16 *)(state + 0x18) = 1;
            }
            if ((*(s32 *)arg0 & 0x4000000) == 0) {
                if ((D_008C024E[0] & 0x40) != 0 ||
                    (D_008C024E[0] & 0x20) != 0) {
                    goto do_action;
                }
                if ((D_008C024C[0] & 0x10) == 0)
                    goto state_check;
                count = *(u32 *)(state + 0x14);
                if (count > 4U) {
                    if ((iGpffffb4d0 & 1) == 0)
                        goto do_action;
                } else {
                    goto state_check;
                }
            }
state_check:
            if (*(u8 *)(state + 9) != 0) {
                if ((*(s32 *)arg0 & 0x8000000) == 0)
                    return;
                if (frFontMeasureList(*(u8 **)(state + 4)) == 0)
                    return;
            }
do_action:
                func_00440b68(D_0063BF40);
                *(s16 *)(state + 0x18) = 3;
                *(s16 *)(state + 0x10) += 1;
                sdkSndResetChannel(1, 0);
                if (*(s16 *)(state + 0x10) >= *(s16 *)(state + 0x12)) {
                    *(s8 *)(state + 8) = -1;
                    return;
                }
                index = 0;
                while (index < 32) {
                    func_002746c0(index,
                        *(s32 *)(arg0 + index * 4 + 0x94));
                    index += 1;
                }
                if (*(s32 *)(arg0 + 8) != 0)
                    frFontLoadSystemSlot((u8 *)*(s32 *)(arg0 + 8));
                itfMesWindowBuildRow(arg0);
                *(s32 *)arg0 = *(s32 *)arg0 & ~7;
                *(s32 *)arg0 |= 3;
        } else {
            if ((*(s32 *)arg0 & 0x4000000) == 0 &&
                ((D_008C024E[0] & 0x40) != 0 ||
                 (D_008C024E[0] & 0x20) != 0 ||
                 ((D_008C024C[0] & 0x10) != 0 &&
                  (iGpffffb4d0 & 1) == 0)) &&
                (*(s32 *)arg0 & 0x400000) == 0 &&
                (*(s32 *)arg0 & 0x1000000) == 0) {
                iter = *(u8 **)(state + 4);
                while (iter != NULL) {
                    frFontEnableList(iter);
                    iter = *(u8 **)(iter + 0x24);
                }
                if (*(u8 **)(arg0 + 0x14) != NULL)
                    frFontEnableList(*(u8 **)(arg0 + 0x14));
            }
            *(s32 *)arg0 = *(s32 *)arg0 & 0xFEFFFFFF;
        }
    }
}

