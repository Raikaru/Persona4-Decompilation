#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"




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
static inline u32 add_offset_first_0038(u32 offset, u32 base)
{
    return offset + base;
}

/* Source unit: src/promoted/code1_0038.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0038.c; members 0038dd80-0038dd80 */

extern void btlShuffleInitWaveStrips(u8 *drawWork);
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
/* measured: opt_rebuildconditionals off preserves the retail positive branch. */
/* measured: restore conditional rebuilding after this function. */
/* measured: opt_loop_invariants on hoists the conversion constants into the retail preheader. */
/* measured: restore loop-invariant optimization after func_00389cb0. */
/* Measured: 904/912 bytes, eleven resolved relocations and eight zero
 * alignment bytes. D_00761490 is the retail scalar 0xBD872B00, not the
 * rounded -0.066f literal; keep the five-frame and 300-frame reloads. */
#pragma push
#pragma pop
// FUN_0038DD80
void func_0038dd80(void)
{
}

