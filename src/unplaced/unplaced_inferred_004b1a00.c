/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 004b1a00-004b1a00 */

#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source);
extern s32 mdlEffectShareTrackInstance(s32 destination);
extern void mdlEffectReleaseTrackInstance(s32 destination);
extern void TlpRelease(s32 destination);
extern s32 TlpAddRef(s32 destination);
/* Replace the screen sprite track resource, or reference the source TLP when no track is present. */
/* measured: individual source/destination track and TLP typing changes resource-transfer scheduling (normalized_diff 102..106); retain their byte-base accesses. */
// FUN_004B1A00
/* Replace the screen sprite's track resource, or share its TLP when no track is present. */
void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source) {
    s32 previousTracks;
    s32 previousTlp;

    /* measured: typed resource fields change reload scheduling (nd 72 whole-layout,
     * nd 61 destination-only); retain byte-base aliasing for this resource transfer. */
    if (*(s32 *)(source + 0xAC) != 0) {
        previousTracks = *(s32 *)(destination + 0xAC);
        if (previousTracks != 0) {
            mdlEffectReleaseTrackInstance(previousTracks);
        }
        *(s32 *)(destination + 0xAC) = mdlEffectShareTrackInstance(*(s32 *)(source + 0xAC));
        return;
    }
    if (*(s32 *)(source + 0xA8) != 0) {
        previousTlp = *(s32 *)(destination + 0xA8);
        if (previousTlp != 0) {
            TlpRelease(previousTlp);
        }
        *(s32 *)(destination + 0xA8) = TlpAddRef(*(s32 *)(source + 0xA8));
    }
}
