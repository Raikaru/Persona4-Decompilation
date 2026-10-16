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
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027ae90-0027ae90 */

extern void itfMesWindowMoveSelection(u8 *arg0, s32 arg1);
extern s32 itfMesWindowFindPressedEntry(s16 *arg0);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Polls a window's selection: handles cursor input and returns 1 when a choice is confirmed [inferred]
// FUN_0027AE90
s32 itfMesWindowPollSelection(u8 *arg0)
{
    extern void itfMesWindowMoveSelection(u8 *arg0, s32 arg1);
    extern u16 D_008C0252[];
    extern u16 D_008C0274[];
    extern u16 D_008C027A[];
    extern s32 itfMesWindowFindPressedEntry(u8 *arg0);
    u8 *state;
    s32 result;

    state = arg0 + 0x3C;
    result = 0;
    if ((D_008C0252[0] & 0x1000) || (D_008C027A[0] & 0x1000)) {
        if (*(s16 *)(state + 0xE) == 0) {
            if ((D_008C024E[0] & 0x1000) || (D_008C0274[0] & 0x1000))
                result = -1;
        } else {
            result = -1;
        }
    } else if ((D_008C0252[0] & 0x4000) || (D_008C027A[0] & 0x4000)) {
        if (*(s16 *)(state + 0xE) == *(s16 *)(state + 0x12) - 1) {
            if ((D_008C024E[0] & 0x4000) || (D_008C0274[0] & 0x4000))
                result = 1;
        } else {
            result = 1;
        }
    }
    if (result != 0) {
        itfMesWindowMoveSelection(state, result);
        return 0;
    }
    if (D_008C024E[0] & 0x40) {
        s32 remaining;
        u32 bits;
        s32 i;

        sdkSndStartStream(0, 0, 0, 1);
        bits = *(u32 *)(state + 8);
        remaining = *(s16 *)(state + 0xE);
        i = 0;
        while (i < 0x20) {
            if ((bits & 1) == 0) {
                remaining -= 1;
                if (remaining < 0)
                    break;
            }
            i += 1;
            bits >>= 1;
        }
        *(s16 *)(state + 0x10) = (s16)i;
        return 1;
    }
    if (*(s16 *)(state + 0x16) > 0) {
        s32 selected;
        s32 remaining;
        u32 bits;
        s32 i;
        s32 count;

        selected = itfMesWindowFindPressedEntry(state);
        if (selected >= 0) {
            sdkSndStartStream(0, 0, 0, 2);
            bits = *(u32 *)(state + 8);
            remaining = selected;
            count = 0;
            i = 0;
            while (i < 0x20) {
                remaining -= 1;
                if (remaining < 0)
                    break;
                if ((bits & 1) == 0)
                    count += 1;
                i += 1;
                bits >>= 1;
            }
            if (bits & 1)
                count = -1;
            if (count != -1 && count != *(s16 *)(state + 0xE)) {
                *(s16 *)(state + 0xE) = (s16)count;
                *(s16 *)(state + 0x10) = (s16)selected;
            }
            return 1;
        }
    }
    return 0;
}

