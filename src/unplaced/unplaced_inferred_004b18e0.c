
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
#include "mdl_effect_drawable_internal.h"
extern void mdlEffectReleaseTrackInstance(s32 instance);
extern void TlpRelease(s32 work);
extern void (*jtbl_008873EC[])(void *);
/* Release optional TLP and track resources, geometry and the screen-sprite allocation. */
// FUN_004B18E0
/* Release both optional resources and the geometry before freeing the screen sprite. */
void mdlEffectScreenSpriteRelease(u8 *sprite)
{
    s32 handle;

    handle = ((MdlEffectScreenSprite *)sprite)->tlp;
    if (handle != 0) {
        TlpRelease(handle);
    }
    handle = ((MdlEffectScreenSprite *)sprite)->tracks;
    if (handle != 0) {
        mdlEffectReleaseTrackInstance(handle);
    }
    GeometryBlockDestroy((s32)((MdlEffectScreenSprite *)sprite)->geometry);
    (*jtbl_008873EC)(sprite);
}
