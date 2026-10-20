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


extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

extern void itfMesWindowMoveSelection(u8 *selection, s32 direction);
extern s32 itfMesWindowFindPressedEntry(s16 *selection);
/* Polls a window's selection: handles cursor input and returns 1 when a choice is confirmed.
 * Remaining raw address accesses are kept because typed forms change the output. */
// FUN_0027AE90
s32 itfMesWindowPollSelection(u8 *window)
{
    ItfMesSelection *cursorFields;

    extern void itfMesWindowMoveSelection(u8 *selection, s32 direction);
    extern u16 D_008C0252[];
    extern u16 D_008C0274[];
    extern u16 D_008C027A[];
    extern s32 itfMesWindowFindPressedEntry(u8 *selection);
    u8 *state;
    s32 result;

    state = window + 0x3C;
    result = 0;
    if ((D_008C0252[0] & 0x1000) || (D_008C027A[0] & 0x1000)) {
        if (((ItfMesSelection *)state)->cursor == 0) {
            if ((D_008C024E[0] & 0x1000) || (D_008C0274[0] & 0x1000))
                result = -1;
        } else {
            result = -1;
        }
    } else if ((D_008C0252[0] & 0x4000) || (D_008C027A[0] & 0x4000)) {
        if (((ItfMesSelection *)state)->cursor == ((ItfMesSelection *)state)->count - 1) {
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
        bits = ((ItfMesSelection *)state)->hiddenMask.bits;
        remaining = ((ItfMesSelection *)state)->cursor;
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
        ((ItfMesSelection *)state)->selected = (s16)i;
        return 1;
    }
    if (((ItfMesSelection *)state)->bindingCount > 0) {
        s32 selected;
        s32 remaining;
        u32 bits;
        s32 i;
        s32 count;

        selected = itfMesWindowFindPressedEntry(state);
        if (selected >= 0) {
            sdkSndStartStream(0, 0, 0, 2);
            bits = ((ItfMesSelection *)state)->hiddenMask.bits;
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
            if (count != -1 && count != ((ItfMesSelection *)state)->cursor) {
                (cursorFields = (ItfMesSelection *)(state), cursorFields)->cursor = (s16)count;
                ((ItfMesSelection *)state)->selected = (s16)selected;
            }
            return 1;
        }
    }
    return 0;
}

