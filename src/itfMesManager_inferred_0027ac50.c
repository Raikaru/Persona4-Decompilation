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
extern void itfMesWindowCommitSelection(u8 *window);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027ac50-0027ac50 */

extern s32 itfMesWindowPollSelection(u8 *window);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Runs the selected entry's command and releases its tag run when the selection commits [inferred]
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 1, 54, 219, 221; retain their original address/alias expressions. */
// FUN_0027AC50
void itfMesWindowCommitSelection(u8 *window)
{
    extern s32 frFontListKeepOrRelease(s32 list);
    extern void frFontRunCommand(s32 stream, s32 mode, s32 command);
    extern s32 itfMesReleaseTagRun();
    extern s32 itfMesWindowPollSelection(u8 *window);
    u8 *state;
    s32 flags;
    s32 index;
    s32 count;
    s32 *cursor;
    s32 i;

    state = window + 0x3C;
    flags = ((ItfMesWindow *)window)->flags.value;
    switch (((ItfMesWindow *)window)->selection.state)
    {
    case 1:
        switch (((ItfMesWindow *)window)->kind.value)
        {
        case 0:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = flags & ~0x38;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 0x18;
                ((ItfMesWindow *)window)->flags.value = current;
                ((ItfMesSelection *)state)->state = 2;
            }
            break;
        case 1:
        case 2:
        default:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = ((ItfMesWindow *)(u32)window)->flags.value;
                current &= ~0x38;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 0x18;
                ((ItfMesWindow *)window)->flags.value = current;
                ((ItfMesSelection *)state)->state = 2;
            }
            break;
        }
        /* fall through */
    case 2:
        if ((flags & 0x38) == 0x20 && itfMesWindowPollSelection(window) == 1) {
            s16 cursorIndex;
            s16 choiceCount;
            s32 listHandle;
            u8 *entry;

            cursorIndex = ((ItfMesSelection *)state)->cursor;
            choiceCount = ((ItfMesSelection *)state)->count;
            listHandle = ((ItfMesSelection *)state)->list.value;
            *(s32 *)(state + 4) = itfMesReleaseTagRun(
                listHandle, cursorIndex, choiceCount);
            entry = ((ItfMesWindow *)window)->record.bytes;
            entry = *(u8 **)((u8 *)add_retail_ptr(
                (u32)(((ItfMesSelection *)state)->recordIndex.value * 8), (u32)entry) + 0x24);
            index = *(s16 *)(state + 0xE);
            count = ((ItfMesChoiceRecord *)entry)->count;
            cursor = (s32 *)(entry + 0x20);
            i = 0;
            while (i < count) {
                if (i == index)
                    frFontRunCommand(*cursor, 3, 0);
                i += 1;
                cursor += 1;
            }
            if ((flags & 0xC00) == 0x800) {
                s32 current;

                current = ((ItfMesWindow *)window)->flags.value;
                current &= ~0xC00;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 0xC00;
                ((ItfMesWindow *)window)->flags.value = current;
            }
            ((ItfMesSelection *)state)->bindingCount = 0;
            {
                s32 current;

                current = ((ItfMesWindow *)window)->flags.value;
                current &= ~0x38;
                ((ItfMesWindow *)window)->flags.value = current;
                current |= 0x28;
                ((ItfMesWindow *)window)->flags.value = current;
            }
            ((ItfMesSelection *)state)->alpha = 0x80;
            ((ItfMesSelection *)state)->state = 3;
        }
        break;
    case 3:
        if ((flags & 0xC00) == 0) {
            if (((ItfMesSelection *)state)->list.value != 0) {
                frFontListKeepOrRelease(((ItfMesSelection *)state)->list.value);
                *(s32 *)(state + 4) = 0;
            }
            ((ItfMesSelection *)state)->state = -1;
        }
        break;
    }
}

