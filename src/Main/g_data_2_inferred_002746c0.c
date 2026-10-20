/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Event/Fcl/fclBankManager.c; members 002746c0-002746c0 */

#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_008815B0[];
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// FUN_002746C0
void datSetIndexedWord(s32 index, s32 value)
{
    D_008815B0[index] = value;
}
#pragma pop
