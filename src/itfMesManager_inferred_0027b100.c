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

/* Moves the window's selection cursor one step in the given direction, wrapping around. */
// FUN_0027B100
void itfMesWindowMoveSelection(u8 *selection, s32 direction) {
    ItfMesSelection *cursorFields;

    s32 oldCursor;
    s32 remaining;
    u32 hiddenMask;
    s32 entryIndex;

    oldCursor = (s32)((ItfMesSelection *)selection)->cursor;
    if (direction < 0) {
        remaining = oldCursor - 1;
        if (remaining < 0) {
            remaining = (s32)((ItfMesSelection *)selection)->count - 1;
        }
    } else {
        remaining = oldCursor + 1;
        if (remaining >= (s32)((ItfMesSelection *)selection)->count) {
            remaining = 0;
        }
    }
    (cursorFields = (ItfMesSelection *)(selection), cursorFields)->cursor = (s16)remaining;
    hiddenMask = ((ItfMesSelection *)selection)->hiddenMask.bits;
    entryIndex = 0;
    goto loop_test;
loop_body:
    if ((hiddenMask & 1) == 0) {
        remaining -= 1;
        if (remaining < 0) {
            goto loop_exit;
        }
    }
    entryIndex += 1;
    hiddenMask >>= 1;
loop_test:
    if (entryIndex < 0x20) {
        goto loop_body;
    }
loop_exit:
    ((ItfMesSelection *)selection)->selected = (s16)entryIndex;
    sdkSndStartStream(0, 0, 0, 0);
}

