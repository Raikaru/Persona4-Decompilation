#include "kwln_draw_callbacks_internal.h"
#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
#include "primitive_queue_internal.h"
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
extern void itfMesWindowQueueCallback(s32 taskAddress);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *list, u8 *node);

/* Queues the window task's deferred callback with the task address as its argument. */
// FUN_0027B5D0
void itfMesWindowQueueCallback(s32 taskAddress)
{
    u8 *node;

    node = PrimAllocQueueNode();
    ((PrimQueueNode *)node)->callback = (void *)itfMesFlushPendingCallback;
    ((PrimQueueNode *)node)->argument.handle = taskAddress;
    PrimAppendNode(D_007964C0, node);
}

