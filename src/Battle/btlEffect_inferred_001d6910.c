#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 btlEffectStepFormationPlacement(u8 *work);
extern void btlFormationResetState(s32 work);
extern void mdlEffectDestroyWithNodes(s32 effect);
extern void mdlDestroyModelObject(s32 model);
extern void (*jtbl_008873EC[])(void *);
extern void btlEffectReleaseNode(u8 *node);
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();


typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

#pragma push
#pragma pop
/* measured: func_001d5990 needs optimization level 1 to reproduce retail's stack reload scheduling.
 * measured: btlEffectStepFormationPlacement needs opt_propagation off to reproduce retail's
 * argument setup and register use. */
#pragma push
#pragma pop
/* Release node resources, unlink both neighbours, repair the global head if needed, and free the node. */
// FUN_001D6910
void btlEffectReleaseNode(u8 *node)
{
    BtlEffectNode *nodeState = (BtlEffectNode *)(node);
    if (*(s32 *)&((BtlEffectNode *)(node))->formation != 0) {
        btlFormationResetState(*(s32 *)&((BtlEffectNode *)(node))->formation);
        *(s32 *)&nodeState->formation = 0;
    }
    if (*(s32 *)&((BtlEffectNode *)(node))->effect != 0) {
        mdlEffectDestroyWithNodes(*(s32 *)&((BtlEffectNode *)(node))->effect);
        *(s32 *)&nodeState->effect = 0;
    }
    if (*(s32 *)&((BtlEffectNode *)(node))->model != 0) {
        mdlDestroyModelObject(*(s32 *)&((BtlEffectNode *)(node))->model);
        *(s32 *)&nodeState->model = 0;
    }
    *(s32 *)&((BtlEffectNode *)(node))->color = -1;
    ((BtlEffectNode *)(node))->fadeStep = 0x14;
    *(s32 *)&((BtlEffectNode *)(node))->counter = 0;
    ((BtlEffectNode *)(node))->flags = 0x200;
    if (*(u8 * *)&((BtlEffectNode *)(node))->next != NULL) {
        *(u8 * *)&((BtlEffectNode *)(*(u8 * *)&((BtlEffectNode *)(node))->next))->previous = *(u8 * *)&((BtlEffectNode *)(node))->previous;
    }
    if (*(u8 * *)&((BtlEffectNode *)(node))->previous != NULL) {
        *(u8 * *)&((BtlEffectNode *)(*(u8 * *)&((BtlEffectNode *)(node))->previous))->next = *(u8 * *)&nodeState->next;
    } else {
        *(u8 * *)&((BtlBattleState *)(iGpffffb3ac))->effectNodes = *(u8 * *)&nodeState->next;
    }
    (*jtbl_008873EC)(node);
}

