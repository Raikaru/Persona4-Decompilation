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

extern void memset(void *value, s32 index, s32 count);
extern s32 itfMesWindowProcedureForKind(s32 kind);

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0027; members 0027a5e0-0027a690 */

extern s32 itfMesWindowProcedureForKind(s32 kind);
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
void itfMesWindowSetProcedure(s32 *record, s32 kind)
{
    memset(record, 0, 0x1C);
    *record = itfMesWindowProcedureForKind(kind);
}

// Intent: Resets a slot to empty (value 0, index 0xFFFF) [inferred]
// FUN_0027A630
void itfMesSlotReset(u8 *record)
{
    ((ItfMesLabel *)record)->list.value = 0;
    ((ItfMesLabel *)record)->index = 0xFFFF;
}

// Intent: Zeroes a window record and sets its trailing byte to 0xFF [inferred]
// FUN_0027A650
void itfMesRecordReset(u8 *record)
{
    ((ItfMesRow *)record)->record.value = 0;
    ((ItfMesRow *)record)->list.value = 0;
    ((ItfMesRow *)record)->state.value = 0;
    ((ItfMesRow *)record)->flags.value = 0;
    ((ItfMesRow *)record)->lineCount = 0;
    ((ItfMesRow *)record)->index = 0;
    ((ItfMesRow *)record)->count = 0;
    ((ItfMesRow *)record)->style.value = 0;
    ((ItfMesRow *)record)->palette.value = 0;
    ((ItfMesRow *)record)->effect.value = 0;
    ((ItfMesRow *)record)->intensity.bits = 0xFF;
}

// Resets an entry: zeroes the words at +4 and +8, zeroes the halfwords at +0xC, +0x12, +0x14 and +0x16, and sets the halfwords at +0xE and +0x10 to -1 [inferred].
// FUN_0027A690
void itfMesEntryReset(u8 *record)
{
    ((ItfMesSelection *)record)->list.value = 0;
    ((ItfMesSelection *)record)->hiddenMask.value = 0;
    ((ItfMesSelection *)record)->state = 0;
    ((ItfMesSelection *)record)->cursor = -1;
    ((ItfMesSelection *)record)->selected = -1;
    ((ItfMesSelection *)record)->count = 0;
    ((ItfMesSelection *)record)->alpha = 0;
    ((ItfMesSelection *)record)->bindingCount = 0;
}

