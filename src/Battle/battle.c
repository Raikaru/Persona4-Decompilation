#include "mt_scene_internal.h"
/* Source unit: src/Battle/battle_00192560.c */
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "btl_effect_internal.h"

static u64 iGpffffa090 = 1;


static u16 iGpffffa098 = 0x100;

extern void btlPacketStepSide(u32 layer);
extern void btlMainDrawSkyOverlay(void);
extern void btlMainUpdate(void);
extern void btlActionListUpdate(void);
extern void btlActionUpdateQueue(void);
extern void btlMainSyncSceneDrawColors(void);
extern void btlCameraApplyView(void);
extern void btlUnitUpdateAll(void);
extern void btlSoundStepMessagePhase(void);
extern void func_001f9be0(void);
extern void btlSoundAdvanceSlotQueue(void);
extern void btlTargetUpdateDamagePhaseInput(void);
extern void btlDestroyTask(void);
extern s32 kwlnGetCamera(void);
extern s32 func_003e8120(s32 camera);
extern void btlUnitUpdateAllLookAtTargets(void);
extern void btlUnitQueueAllModelsForDraw(void);
extern void btlEffectUpdateFadeNodes(void);
extern void btlCameraDrawDebug(void);
extern void PrimAppendNode(void *list, void *node);
extern void func_003e8110(s32 camera);
extern u8 D_007940C0[];
extern u8 D_00794120[];

extern u32 mdlEffectReturnSuccess(void);

typedef BtlBattleState Battle;

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};
extern Battle* iGpffffb3ac;


extern BtlPacket* btlPacketAlloc(u32 type, u32 workSize);
extern u32 btlSetFlagsPacketUpdate(void* work);
extern u32 btlClearFlagsPacketUpdate(void* work);



/* Allocate a nonzero battle UID, wrapping before the reserved upper range. */
// FUN_00192560
u64 btlGetUID(void)
{
    iGpffffa090++;

    if (iGpffffa090 >= 0x3FFFFFFFFFFFFFFF)
    {
        iGpffffa090 = 1;
    }

    return iGpffffa090;
}



/* Find an unused character resource slot in the rotating 0x100..0x1FF range. */
// FUN_001925B0
u16 btlFindFreeCharResId(void)
{
    do
    {
        if (++iGpffffa098 >= 0x200)
        {
            iGpffffa098 = 0x100;
        }
    } while (MT_Scene_GetRes((iGpffffa098 & 0x3ff) | 0x400) != NULL);

    return iGpffffa098;
}



/* Advance battle systems between packet layers while the battle-active flag is set. */
// FUN_00192610
s32 btlUpdateTask(u8 *unusedTask)
{
    if (iGpffffb3ac->flags & 1) {
        btlPacketStepSide(0);
        btlMainUpdate();
        btlActionListUpdate();
        btlActionUpdateQueue();
        btlMainSyncSceneDrawColors();
        btlCameraApplyView();
        btlUnitUpdateAll();
        btlSoundStepMessagePhase();
        func_001f9be0();
        btlSoundAdvanceSlotQueue();
        btlPacketStepSide(1);
        btlTargetUpdateDamagePhaseInput();
    } else {
        btlDestroyTask();
    }
    return 0;
}
/* Draw the battle scene and enqueue the render-state and sky primitive callbacks. */
// FUN_001926C0
s32 btlUpdateDraw3DTask(u8 *unusedTask)
{
    if (func_003e8120(kwlnGetCamera()) != 0) {
        btlPacketStepSide(2);
        btlUnitUpdateAllLookAtTargets();
        btlUnitQueueAllModelsForDraw();
        btlEffectUpdateFadeNodes();
        btlCameraDrawDebug();
        iGpffffb3ac->renderStateNode.unk00 = 0;
        iGpffffb3ac->renderStateNode.unk04 = 0;
        PrimAppendNode(D_007940C0, &iGpffffb3ac->renderStateNode);
        iGpffffb3ac->skyNode.unk00 = 0;
        iGpffffb3ac->skyNode.unk04 = 0;
        PrimAppendNode(D_00794120, &iGpffffb3ac->skyNode);
        func_003e8110(kwlnGetCamera());
    }
    return 0;
}
/* Update callback of the retail "battle_draw_2d" task. */
// FUN_00192790
s32 btlUpdateDraw2DTask(u8 *task)
{
    btlPacketStepSide(3);
    btlMainDrawSkyOverlay();

    return 0;
}



// AI script command 0x20DF (AI command table entry, VA 0x0063DCD8). AI library name: AI_FUNCTION_00DF.
// FUN_001935F0
u32 btlScriptHasCmdTimer(void)
{
    if (scrGetCmdTimer() > 0)
    {
        return mdlEffectReturnSuccess() != 0;
    }

    return 0;
}



/* Apply a queued battle-flag mask and complete the packet. */
// FUN_00193750
u32 btlSetFlagsPacketUpdate(void* work)
{
    BtlBattleFlagPacket* packet;

    packet = (BtlBattleFlagPacket*)work;
    iGpffffb3ac->flags |= packet->flags;

    return 1;
}



/* Create a one-shot packet that sets battle runtime flags. */
// FUN_00193770
BtlPacket* btlCreateSetFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0xFF02, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = btlSetFlagsPacketUpdate;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}


/* measured: removing this pragma takes func_001937c0 nd 0 -> nd 13. */
#pragma optimization_level 1

/* Clear a queued battle-flag mask and complete the packet. */
// FUN_001937C0
u32 btlClearFlagsPacketUpdate(void* work)
{
    BtlBattleFlagPacket* packet;
    Battle* btl;

    btl = iGpffffb3ac;
    packet = (BtlBattleFlagPacket*)work;
    btl->flags &= ~packet->flags;

    return 1;
}
#pragma optimization_level 2



/* Create a one-shot packet that clears battle runtime flags. */
// FUN_001937F0
BtlPacket* btlCreateRemoveFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0xFF03, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = btlClearFlagsPacketUpdate;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}
