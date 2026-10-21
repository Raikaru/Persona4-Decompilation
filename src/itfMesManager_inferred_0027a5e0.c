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

extern s32 itfMesWindowProcedureForKind(s32 kind);
/* Clears a window's procedure block and stores the procedure for its kind. */
// FUN_0027A5E0
void itfMesWindowSetProcedure(s32 *record, s32 kind)
{
    memset(record, 0, 0x1C);
    *record = itfMesWindowProcedureForKind(kind);
}

// Resets a slot to empty (value 0, index 0xFFFF).
// FUN_0027A630
void itfMesSlotReset(u8 *record)
{
    ((ItfMesLabel *)record)->list.value = 0;
    ((ItfMesLabel *)record)->index = 0xFFFF;
}

// Zeroes a window record and sets its trailing intensity byte to 0xFF.
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

// Resets a selection entry: zeroes list, hiddenMask, state, count and alpha, and sets cursor and
// selected to -1.
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

