
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_008815B0[];
// FUN_002746C0
void datSetIndexedWord(s32 index, s32 value)
{
    D_008815B0[index] = value;
}
