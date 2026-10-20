/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00349340-00349380 */

#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "rw/plcore/barenderstate.h"
extern void (*jtbl_008873EC[])(void *);
/* Clears the callback scratch bytes and returns success without drawing. */
// FUN_00349340
s32 debugModelDrawClearScratch(u8 *unusedTask)
{
    s8 buf[0xC];
    s8 *p;
    s32 count;

    p = buf;
    count = 0xC;
    if (p != NULL)
    {
        do
        {
            *p = 0;
            p += 1;
            count -= 1;
        } while (count != 0);
    }
    return 0;
}

// FUN_00349380
void debugModelDrawDestroy(u8 *task) {
    jtbl_008873EC[0]((((struct KwlnTask *)task)->work));
}
