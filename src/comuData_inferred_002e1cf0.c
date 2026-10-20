#include "btl_target_state_packet_internal.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_internal.h"
typedef FclVec2 f2;
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} u4;
extern u8 *iGpffffb588;
extern u8 *iGpffffb590;
extern u8 D_0063FB50[];
extern u8 D_0063FAA0[];
extern u8 D_0063FB90[];
extern u8 D_0063FC80[];
extern u8 D_0063FC90[];
extern void *(*D_008873F4[])(size_t numObj, size_t sizeObj, u32 hint);


extern u8 D_0063F560[];

/* measured: retail loads each pair before storing it, in source order. */
#pragma push
#pragma pop
/* Default list update callback: accept the operation without additional work. */
// FUN_002E1CF0
s32 comuDataUpdateNoop(void)
{
    return 0;
}

