#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "fr_font_internal.h"
extern void (*jtbl_008873EC[])(void *input);
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
/* Rebuild requests carry signed kind/order bytes and two word filters. */
typedef struct ComuListRebuild {
    s8 pending;
    s8 kind;
    u8 pad02[2];
    s32 filterA;
    s32 filterB;
    s8 order;
} ComuListRebuild;

/* Consume one pending list-rebuild request and clear its pending byte. */
// FUN_002E23B0
s32 comuDataApplyListRebuild(u8 *task)
{
    ComuListRebuild *request;

    request = (ComuListRebuild *)((struct KwlnTask *)task)->work;
    if (request->pending == 0) {
        return 0;
    }
    yListRebuild(request->filterA, request->filterB, request->kind, (s32)request->order);
    request->pending = 0;
    return 0;
}

/* Rebuild the task-owned list from a pending request and acknowledge it. */
// FUN_002E2410
s32 comuDataApplyOwnedListRebuild(u8 *task)
{
    ComuListRebuild *request;

    request = (ComuListRebuild *)((struct KwlnTask *)task)->work;
    if (request->pending == 0) {
        return 0;
    }
    yListRebuildFor(task, request->filterA, request->filterB, request->kind, request->order);
    request->pending = 0;
    return 0;
}

/* Free the list task request block. */
// FUN_002E2470
void comuDataDestroyListRequest(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}

