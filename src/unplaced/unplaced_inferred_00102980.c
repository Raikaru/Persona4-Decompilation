/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00102980-00102980 */

#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"
#include "sdktask.h"

/* Only the two-word prefix is known here; the second word is read below. */
typedef struct SceneTaskHeader {
    s32 unk0;
    s32 unk4;
} SceneTaskHeader;
extern u8 *D_00764298;
#pragma push
#pragma tailcall off
/* Return the second word of the active scene task's work header. */
// FUN_00102980
s32 kwlnGetCurrentWorkValue(void)
{
    return ((SceneTaskHeader *)((SdkTask *)D_00764298)->work)->unk4;
}
#pragma pop
