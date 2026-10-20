#include "btl_formation_attach_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern void btlEffectFreeEntry(s32 pool, s32 entry);
extern s32 btlEffectStepFormationPlacement(u8 *work);
extern void btlFormationSetPlacement(s32 formation);
extern u32 iGpffffb3b8;

extern void mdlEffectFlushTreeFrame(s32 effect);
extern void TnSetTableBase(s32 table);
extern void mdlSetColor(u8 *model, u32 *color);
extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
extern void mdlAdvanceModelFromFlags(s32 model);
extern void mdlEffectCommitTreeFrame(u8 *effect);
extern void btlFormationUpdateAttachments(s32 work);
extern void mdlQueueModelForDraw(s32 queue, u8 *model);
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







extern void *btlPacketAlloc();


extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d6300-001d6680 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: restore optimization_level 2 after func_001d5990. */
/* Reset elapsed time, copy formation defaults, hold the unit pending count, and reserve an effect node. */
// FUN_001D6300
void btlEffectPrepareFormationStep(u8 *work) {
    u8 *unit;

    ((BtlEffectFormationStep *)work)->elapsed = 0;
    btlFormationCopyDefault(((BtlEffectFormationStep *)work)->formation);
    unit = (u8 *)(((BtlEffectFormationStep *)work)->unit);
    ((BtlUnit *)(unit))->pendingPacketCount = (u16) (((BtlUnit *)(unit))->pendingPacketCount + 1);
    *(s32 *)&((BtlEffectFormationStep *)work)->node = btlEffectAllocEntry(*(s32 *)&((BtlUnit *)((u8 *)(((BtlEffectFormationStep *)work)->unit)))->effectNodePool);
}

/* measured: opt_propagation off probe for btlEffectStepFormationPlacement argument setup and register coloring. */
#pragma push
/* measured: btlEffectStepFormationPlacement MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Create the formation entry on the first step, drive node fade flags, and abort at duration, UID, or index limits. */
// FUN_001D6360
s32 btlEffectStepFormationPlacement(u8 *work)
{
    BtlEffectFormationStep *formationStep = (BtlEffectFormationStep *)(work);
    BtlEffectNode *fadeNode;
    extern s32 btlUnitRecordFindByUID(s64 uid, s64 mask);
    extern u32 btlFormationGetCount(void *formation);
    extern s32 btlFormationGetIndex(s32 formation, s32 side);
    extern s32 btlFormationAllocEntry(s32 table, s32 tableIndex, s32 unit, s32 target, s32 flags);
    s32 count;
    s32 value;
    s32 unit;
    s32 index;
    s32 indexLimit;
    s64 key;
    u8 *packet;
    u8 *abortNode;
    s32 options;
    if (btlFormationGetCount(((BtlEffectFormationStep *)(work))->formation) == 0)
        return 0;
    packet = *(u8 * *)&((BtlEffectFormationStep *)(work))->node;
    fadeNode = (BtlEffectNode *)(packet);
    if ((*(s32 *)&((BtlEffectNode *)(packet))->color & 0xFF000000) == 0)
        return 1;
    if ((((BtlEffectNode *)(packet))->flags & 0x40) == 0) {
        if ((*(s32 *)&((BtlEffectFormationStep *)(work))->flags & 0x4000) == 0) {
            indexLimit = btlFormationGetIndex(*(s32 *)&((BtlEffectFormationStep *)(work))->formation, 0) * 2;
            index = indexLimit;
        } else {
            indexLimit = ((BtlEffectFormationStep *)(work))->elapsed + 1;
            index = indexLimit;
        }
        count = ((BtlEffectFormationStep *)(work))->duration;
        if ((count != 0 && ((BtlEffectFormationStep *)(work))->elapsed >= count * 2 - 13) ||
            ((key = ((BtlEffectFormationStep *)(work))->key) != 0 &&
             btlUnitRecordFindByUID(key, (s64)0x3FFFFFFFFFFFFFFF) == 0) ||
            (index != 0 && ((BtlEffectFormationStep *)(work))->elapsed >= index)) {
            if ((*(s32 *)&formationStep->flags & 0x2000) != 0)
                *(s8 *)&((BtlEffectNode *)(*(u8 * *)&formationStep->node))->fadeStep = 7;
            abortNode = *(u8 * *)&formationStep->node;
            ((BtlEffectNode *)(abortNode))->flags |= 0x100;
            return 0;
        } else {
            value = ((BtlEffectFormationStep *)(work))->elapsed;
            if (value == 0) {
                unit = *(s32 *)&((BtlEffectFormationStep *)(work))->unit;
                options = *(s32 *)&formationStep->flags;
                *(s32 *)&((BtlEffectNode *)(packet))->formation =
                    btlFormationAllocEntry(*(s32 *)&((BtlEffectFormationStep *)(work))->formation, 0, unit, unit, options);
            } else if (value == 2) {
                if ((*(s32 *)&formationStep->flags & 0x10000) == 0) {
                    ((BtlEffectNode *)(packet))->flags |= 0xB0;
                    *(s32 *)&((BtlEffectNode *)(packet))->color =
                        ((BtlEffectNode *)(packet))->color & 0x00FFFFFF;
                } else {
                    ((BtlEffectNode *)(packet))->flags |= 0x30;
                    *(s32 *)&fadeNode->color = -1;
                }
            }
            formationStep->elapsed = formationStep->elapsed + 2;
        }
    }
    return 0;
}

/* measured: restore pragma state after btlEffectStepFormationPlacement. */
#pragma pop
/* Return the effect node, release the formation placement, and drop the unit pending-packet count. */
// FUN_001D6570
void btlEffectFinishFormationStep(u8 *work)
{
    BtlEffectFormationStep *formationStep = (BtlEffectFormationStep *)(work);
    btlEffectFreeEntry(*(s32 *)&((BtlUnit *)(((BtlEffectFormationStep *)(work))->unit))->effectNodePool, *(s32 *)&((BtlEffectFormationStep *)(work))->node);
    btlFormationSetPlacement(*(s32 *)work);
    ((BtlUnit *)(formationStep->unit))->pendingPacketCount =
        ((BtlUnit *)(formationStep->unit))->pendingPacketCount - 1;
}

/* Allocate packet 0x302 with formation, unit, duration, UID and flags in its 0x28-byte work area. */
// FUN_001D65D0
u8 *btlEffectCreateFormationPacket(s32 formation, s32 unit, s32 duration, s64 key, s32 flags)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x302, 0x28);
    ((BtlPacket *)packet)->flags &= 0xEF;
    *(void (**)(u8 *))(packet + 0x68) = btlEffectPrepareFormationStep;
    *(s32 (**)(u8 *))(packet + 0x6C) = btlEffectStepFormationPlacement;
    *(void (**)(u8 *))(packet + 0x70) = btlEffectFinishFormationStep;
    work = (u8 *)((BtlPacket *)packet)->workData;
    *(s32 *)&((BtlEffectFormationStep *)work)->formation = formation;
    *(s32 *)&((BtlEffectFormationStep *)work)->unit = unit;
    ((BtlEffectFormationStep *)work)->duration = duration;
    ((BtlEffectFormationStep *)work)->key = key;
    *(s32 *)&((BtlEffectFormationStep *)work)->flags = flags;
    return packet;
}

/* The 0x24-byte records built by btlEffectAllocNodePool store packed RGBA at +4
 * and a wrapping frame counter at +0xC. Fade-out wins over fade-in;
 * bit 0x40 freezes update/cleanup, not drawing.
 * Retail: 504/512B, 14 resolved relocations, eight zero tail bytes. */
// FUN_001D6680
void btlEffectUpdateFadeNodes(void)
{
    BtlEffectNode *node;
    u32 color;
    u16 flags;
    u32 step;
    u32 arg;

    TnSetTableBase((s32)D_005DC7D0);
    node = (BtlEffectNode *)((BtlBattleState *)iGpffffb3ac)->effectNodes;
    while (node != NULL) {
        color = node->color;
        flags = node->flags;
        if ((flags & 0x40) == 0) {
            if ((flags & 0x100) != 0) {
                step = (u32)node->fadeStep << 24;
                if (step < (color & 0xFF000000)) {
                    color = color - step;
                } else {
                    color = color & 0x00FFFFFF;
                    node->flags = flags & 0xFE7F;
                }
            } else if ((flags & 0x80) != 0) {
                step = (u32)node->fadeStep << 24;
                if (step < (u32)(0xFF000000 - (color & 0xFF000000))) {
                    color = color + step;
                } else {
                    color = color & 0x00FFFFFF;
                    color = color | 0xFF000000;
                    node->flags = flags & 0xFE7F;
                }
            }
            if ((node->flags & 0x220) == 0x220) {
                if (node->model != NULL) {
                    mdlAdvanceModelFromFlags((s32)node->model);
                }
                if (node->effect != NULL) {
                    mdlEffectCommitTreeFrame(node->effect);
                }
                if (node->formation != NULL) {
                    btlFormationUpdateAttachments((s32)node->formation);
                }
            }
        }
        if ((node->flags & 0x210) == 0x210 && (color & 0xFF000000) != 0) {
            if (node->model != NULL) {
                arg = color;
                mdlSetColor(node->model, &arg);
                mdlQueueModelForDraw((s32)D_00794150, node->model);
            }
            if (node->effect != NULL) {
                mdlEffectApplyPackedColor(node->effect, (s32)color);
                mdlEffectFlushTreeFrame((s32)node->effect);
            }
            if (node->formation != NULL) {
                ((BtlAttachWork *)(node->formation))->color = color;
                btlFormationCameraTaskStart(node->formation);
            }
        }
        node->color = color;
        node->counter = node->counter + 1;
        node = (BtlEffectNode *)node->next;
    }
}

