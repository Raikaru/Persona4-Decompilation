#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];



extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 itfMesWindowProcedureForKind(s32 arg0);
static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027a5e0-0027a690 */

extern s32 itfMesWindowProcedureForKind(s32 arg0);
/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Clears a window's procedure block and stores the procedure for its kind [inferred]
// FUN_0027A5E0
void itfMesWindowSetProcedure(s32 *arg0, s32 arg1)
{
    memset(arg0, 0, 0x1C);
    *arg0 = itfMesWindowProcedureForKind(arg1);
}

// Intent: Resets a slot to empty (value 0, index 0xFFFF) [inferred]
// FUN_0027A630
void itfMesSlotReset(u8 *arg0)
{
    *(s32 *)arg0 = 0;
    *(u16 *)(arg0 + 4) = 0xFFFF;
}

// Intent: Zeroes a window record and sets its trailing byte to 0xFF [inferred]
// FUN_0027A650
void itfMesRecordReset(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 9) = 0;
    *(s16 *)(arg0 + 0xE) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s8 *)(arg0 + 0xA) = 0;
    *(s8 *)(arg0 + 0xB) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0xFF;
}

// Resets an entry: zeroes the words at +4 and +8, zeroes the halfwords at +0xC, +0x12, +0x14 and +0x16, and sets the halfwords at +0xE and +0x10 to -1 [inferred].
// FUN_0027A690
void itfMesEntryReset(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xC) = 0;
    *(s16 *)(arg0 + 0xE) = -1;
    *(s16 *)(arg0 + 0x10) = -1;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s16 *)(arg0 + 0x14) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}

