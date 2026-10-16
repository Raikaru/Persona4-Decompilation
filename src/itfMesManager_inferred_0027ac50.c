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
extern void itfMesWindowCommitSelection(u8 *arg0);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027ac50-0027ac50 */

extern s32 itfMesWindowPollSelection(u8 *arg0);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Runs the selected entry's command and releases its tag run when the selection commits [inferred]
// FUN_0027AC50
void itfMesWindowCommitSelection(u8 *arg0)
{
    extern s32 frFontListKeepOrRelease(s32 arg0);
    extern void frFontRunCommand(s32 arg0, s32 arg1, s32 arg2);
    extern s32 itfMesReleaseTagRun();
    extern s32 itfMesWindowPollSelection(u8 *arg0);
    u8 *state;
    s32 flags;
    s32 index;
    s32 count;
    s32 *cursor;
    s32 i;

    state = arg0 + 0x3C;
    flags = *(s32 *)arg0;
    switch (*(s16 *)(arg0 + 0x48))
    {
    case 1:
        switch (*(s32 *)(arg0 + 0x10))
        {
        case 0:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = flags & ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x18;
                *(s32 *)arg0 = current;
                *(s16 *)(state + 0xC) = 2;
            }
            break;
        case 1:
        case 2:
        default:
            if ((flags & 0xC00) != 0x400) {
                s32 current;

                current = *(s32 *)(u32)arg0;
                current &= ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x18;
                *(s32 *)arg0 = current;
                *(s16 *)(state + 0xC) = 2;
            }
            break;
        }
        /* fall through */
    case 2:
        if ((flags & 0x38) == 0x20 && itfMesWindowPollSelection(arg0) == 1) {
            s16 call_arg1;
            s16 call_arg2;
            s32 call_arg0;
            u8 *entry;

            call_arg1 = *(s16 *)(state + 0xE);
            call_arg2 = *(s16 *)(state + 0x12);
            call_arg0 = *(s32 *)(state + 4);
            *(s32 *)(state + 4) = itfMesReleaseTagRun(
                call_arg0, call_arg1, call_arg2);
            entry = *(u8 **)(arg0 + 4);
            entry = *(u8 **)((u8 *)add_retail_ptr(
                (u32)(*(s32 *)state * 8), (u32)entry) + 0x24);
            index = *(s16 *)(state + 0xE);
            count = *(s16 *)(entry + 0x1A);
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

                current = *(s32 *)arg0;
                current &= ~0xC00;
                *(s32 *)arg0 = current;
                current |= 0xC00;
                *(s32 *)arg0 = current;
            }
            *(s16 *)(state + 0x16) = 0;
            {
                s32 current;

                current = *(s32 *)arg0;
                current &= ~0x38;
                *(s32 *)arg0 = current;
                current |= 0x28;
                *(s32 *)arg0 = current;
            }
            *(s16 *)(state + 0x14) = 0x80;
            *(s16 *)(state + 0xC) = 3;
        }
        break;
    case 3:
        if ((flags & 0xC00) == 0) {
            if (*(s32 *)(state + 4) != 0) {
                frFontListKeepOrRelease(*(s32 *)(state + 4));
                *(s32 *)(state + 4) = 0;
            }
            *(s16 *)(state + 0xC) = -1;
        }
        break;
    }
}

