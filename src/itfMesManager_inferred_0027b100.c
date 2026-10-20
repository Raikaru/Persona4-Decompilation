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
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027b100-0027b100 */

/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Moves the window's selection cursor one step (wrapping) in the given direction [inferred]
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 131; retain their original address/alias expressions. */
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

