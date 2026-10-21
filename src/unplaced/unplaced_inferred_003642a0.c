
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
#include "rw_types_internal.h"
#include "kwln_task_internal.h"
extern void MT_Scene_SetWorkPresentFlag(u8 *task, void *presentWork);
/* Clear the present bit and mark the scene work released with bit 1. */
// FUN_003642A0
void MT_Scene_ReleaseWork(u8 *task)
{
    u16 *flags = (u16 *)((KwlnTask *)task)->work;

    MT_Scene_SetWorkPresentFlag(task, NULL);
    *flags |= 2;
}

// Set the work block's present flag (bit 0 of the flags halfword) when the pointer is non-null,
// otherwise clear it.
// FUN_003642E0
void MT_Scene_SetWorkPresentFlag(u8 *task, void *presentWork)
{
    u16 *flags;

    flags = (u16 *)((KwlnTask *)task)->work;
    if (presentWork != NULL) {
        *flags |= 1;
    } else {
        *flags &= (u16)~1;
    }
}
