
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "sdk_lbox_internal.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "h_cdvd_internal.h"
#include "Kosaka/k_clump_internal.h"
extern s32 D_00922984[];
extern s32 D_00922980[];
extern s32 D_00922988[];
extern s32 D_00922934[];
extern s32 D_00922930[];
extern s32 D_0092293C[];
/* Same RwV3d tag and fields as the ring provider and RenderWare. */
#include "rw_types_internal.h"
// Note: h_cdvd and code1_0045 declare movieResetSlotFlags with an s32 argument;
// this definition takes void. Extern types left as they are; verify decides.
// FUN_00468A10
void movieResetSlotFlags(void)
{
    D_00922984[0] = 0;
    D_00922980[0] = 0;
    D_00922988[0] = 0;
    D_00922934[0] = 0;
    D_00922930[0] = 0;
    D_0092293C[0] = 0;
}
