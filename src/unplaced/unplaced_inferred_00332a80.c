/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00332a80-00332b60 */

#include "fcl_object_internal.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern u32 fclGetMoney(void);
extern void (*D_00887300[])(s32, s32);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
// Identical to fclMiscInitRenderStates (fclMisc_inferred_002be1e0.c).
// FUN_00332A80
void fclCombineInitRenderStates(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x7100D);
}

// FUN_00332B60
void fclCombineDrawMoney(u8 *arg0, u8 *arg1)
{
    shdDrawNumberText(*(Vec2f *)(arg1 + 0x1E0), 1.0f, 0xFF, fclGetMoney());
}
