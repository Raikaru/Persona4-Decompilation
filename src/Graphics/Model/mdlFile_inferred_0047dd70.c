#include "mdl_file_internal.h"
#include "btl_action_internal.h"
#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];


struct MdlFlags78ec0;


extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;

/* Mark the attachment handle dirty when nonzero; the model argument is unused. */
// FUN_0047DD70
void mdlMarkSecondaryDirty(u8 *model, u8 *attachment)
{
    s32 handle;

    handle = (s32)((MdlFileAttachment *)attachment)->handle;
    if (handle != 0) {
        Vpad_MarkDirty(handle);
    }
}

