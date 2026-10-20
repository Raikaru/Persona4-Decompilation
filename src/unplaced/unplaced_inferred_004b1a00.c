
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "mdl_effect_drawable_internal.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source);
extern s32 mdlEffectShareTrackInstance(s32 source);
extern void mdlEffectReleaseTrackInstance(s32 instance);
extern void TlpRelease(s32 work);
extern s32 TlpAddRef(s32 work);
/* Replace the screen sprite track resource, or reference the source TLP when no track is present.
 * The typed alias locals keep retail's reload order. */
// FUN_004B1A00
void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source) {
    MdlEffectScreenSprite *destinationFields = (MdlEffectScreenSprite *)(destination);
    MdlEffectScreenSprite *sourceFields = (MdlEffectScreenSprite *)(source);
    s32 previousTracks;
    s32 previousTlp;

    if (((MdlEffectScreenSprite *)(source))->tracks != 0) {
        previousTracks = ((MdlEffectScreenSprite *)(destination))->tracks;
        if (previousTracks != 0) {
            mdlEffectReleaseTrackInstance(previousTracks);
        }
        destinationFields->tracks = mdlEffectShareTrackInstance(sourceFields->tracks);
        return;
    }
    if (((MdlEffectScreenSprite *)(source))->tlp != 0) {
        previousTlp = ((MdlEffectScreenSprite *)(destination))->tlp;
        if (previousTlp != 0) {
            TlpRelease(previousTlp);
        }
        destinationFields->tlp = TlpAddRef(sourceFields->tlp);
    }
}
