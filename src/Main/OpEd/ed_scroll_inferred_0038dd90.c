#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
#include "ed_scroll_internal.h"


extern u8 *D_007246AC;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void btlShuffleInitWaveStrips(u8 *drawWork);

extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];

extern f32 D_00761470;
extern f32 D_008872F8[];
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y,
                          f32 depth, u8 red, u8 green, u8 blue, u8 alpha,
                          u16 scaleX, u16 scaleY, f32 angle, s16 pivotX,
                          s16 pivotY);

extern void btlShuffleInitWaveStrips(u8 *drawWork);
/* D_00761490 holds the exact retail scalar 0xBD872B00, not the rounded -0.066f literal. */
#pragma push
#pragma pop
// Initialise the scroll work block: clear the records, set the colour to white and publish the work
// pointer.
// FUN_0038DD90
void edScrollWorkInit(u8 *work) {
    s32 i;

    *(s32 *)work = 0;
    work[0x122C] = 0xFF;
    work[0x122D] = 0xFF;
    work[0x122E] = 0xFF;
    work[0x122F] = 0xFF;
    for (i = 0; i < 0x20; i++) {
        *(s32 *)&((EdScrollWork *)work)->records[i].flags = 0;
    }
    iGpffffb5b0 = work;
}

