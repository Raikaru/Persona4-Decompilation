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
extern void (*jtbl_008873EC[])(void *arg0);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002e; members 002e23b0-002e2470 */

/* measured: retain pair loads before stores and retail's written load order. */
#pragma push
#pragma pop
// FUN_002E23B0
s32 func_002e23b0(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    yListRebuild(*(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), (s32)*(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}

// FUN_002E2410
s32 func_002e2410(u8 *arg0)
{
    u8 *temp16;

    temp16 = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)temp16 == 0) {
        return 0;
    }
    yListRebuildFor(arg0, *(s32 *)(temp16 + 4), *(s32 *)(temp16 + 8), *(s8 *)(temp16 + 1), *(s8 *)(temp16 + 0xC));
    *(s8 *)temp16 = 0;
    return 0;
}

// FUN_002E2470
void func_002e2470(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

