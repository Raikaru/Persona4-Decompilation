#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void itfMesListSetColor();
extern void itfMesListSetRangeFlag();


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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027a400-0027a4b0 */

/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Sets the given flag on list entries whose key falls in a run from arg1 to arg2 [inferred]
// FUN_0027A400
void itfMesListSetRangeFlag(arg0, arg1, arg2, arg3)
u8 *arg0;
s32 arg1;
s32 arg2;
s32 arg3;
{
    u8 *cur;
    u8 *list;
    s32 count;
    s32 key;
    s32 temp;

    cur = arg0;
    count = (arg2 - arg1) - 1;
    key = *(s32 *)(cur + 8);
    goto outer_check;
outer_continue:
    cur = *(u8 **)(cur + 0x24);
    if (cur == NULL)
        goto done;
outer_body:
    temp = *(s32 *)(cur + 8);
    if (key != temp)
    {
        count -= 1;
        key = temp;
        goto outer_check;
    }
    goto outer_continue;
outer_check:
    if (count > 0)
        goto outer_body;
process:
    list = *(u8 **)(cur + 0x1C);
    goto list_check;
list_body:
    *(s32 *)(list + 0x10) = arg3;
    list = *(u8 **)(list + 0x28);
list_check:
    if (list != NULL)
        goto list_body;
    cur = *(u8 **)(cur + 0x24);
    if (cur == NULL)
        goto done;
    temp = *(s32 *)(cur + 8);
    if (key == temp)
        goto process;
done:
    return;
}

// Forwards to itfMesListSetColor; entry used by the window procedure [inferred].
// FUN_0027A490
void itfMesListSetColorEntry(void)
{
    itfMesListSetColor();
}

// Forwards to itfMesListSetRangeFlag; entry used by the window procedure [inferred].
// FUN_0027A4B0
void itfMesListSetRangeFlagEntry(void)
{
    itfMesListSetRangeFlag();
}

