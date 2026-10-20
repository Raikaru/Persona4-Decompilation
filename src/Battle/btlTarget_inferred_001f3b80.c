#include "byte_address_internal.h"
#include "btl_target_message_internal.h"
#include "btl_sound_internal.h"
#include "h_cdvd_request_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
#include "datPersona_internal.h"
/* Force the offset operand into the first addu slot. */


/* Force the base operand into the first addu slot. */


extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];



extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];







extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f3b80-001f3f60 */

extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetGroupStateMatches(u8 *context);
#pragma push
#pragma pop
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
/* measured: loop-invariant probe for func_001f0c50's shared true value. */
/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
/* measured: close opt_loop_invariants after func_001f0dd0. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
/* measured: opt_loop_invariants on preserves target loop preheaders and state materialisation. */
/* measured: close opt_loop_invariants after btlTargetGroupStateMatches probe. */
#pragma push
/* measured: normalized result/record snapshots need invariant motion for the retail 0x310 frame. */
#pragma pop
/* measured: opt_propagation off keeps the iGpffffb3b8 base load ahead of the
   index arithmetic and the 0x70 field load in a temporary before its saved copy. */
/* measured: restore propagation for the rest of the unit. */
/* Resolve a message id through the loaded twelve-byte relative-offset table. */
/* Directory entry offsets are relative to the beginning of the loaded message payload. */
// FUN_001F3B80
s32 btlTargetGetMessageRecord(s32 messageId) {
    s32 messageTable;
    s32 value;

    messageTable = ((s32)(((HCdvdRequest *)(((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle))->data));
    value = (((BtlTargetMessageEntry *)((u8 *)(u32)byteAddressAdd((u32)((messageId & 0xFFFF) * 0xC), (u8 *)((u32)messageTable))))->offset);
    return (s32)(((u32)messageTable) + ((u32)value));
}

/* Native b210 -O2 recovery: 932 bytes plus 12 zero tail bytes.
   Keep both message results at function scope. One native word holds the
   first pass's element index, then the second pass's node address; each
   phase initializes it before use. The first head survives the flags scan,
   while the second head is reloaded after the first pass's query callbacks.
   The four unused arguments retain D_0060AB20's callback contract.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
/* Select an encounter message using enemy flags, affinity scans, and relative party level. */
/* Enemy metadata uses the shared 0x3C-byte status row and its leading flags. */
// FUN_001F3BB0
s32 btlTargetPickAffinityMessage(s32 context, s32 value, s32 option, s32 extra)
{
    extern s32 datCalcGetLevel(u8 *unit);
    extern s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex);
    typedef struct ResistanceScanNode {
        u8 reserved000[0xA4];
        u16 id;
        u8 reserved0A6[0x9BE];
        u8 *data;
        u8 reservedA68[4];
        struct ResistanceScanNode *next;
    } ResistanceScanNode;
    s32 secondaryMessage;
    s32 primaryMessage;
    s32 enemyCount;
    s32 actorId;
    s32 hasSkill;
    s32 averageLevel;
    s32 referenceLevel;
    s32 levelAdvantage;
    ResistanceScanNode *firstNode;
    ResistanceScanNode *flagNode;
    u8 *metadata;
    u32 flags;

    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    if (enemyCount > 5) {
        return -1;
    }

    if (datGetFlag(0x38) != 0) {
        actorId = 5;
    } else {
        actorId = 8;
    }
    hasSkill = datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(actorId & 0xFFFF), 0x10D) != -1;

    averageLevel = func_001ef4d0(2, 0x80000) & 0xFFFF;
    referenceLevel = datCalcGetLevel(((u8 *)(((BtlUnit *)(((u8 *)(((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit))))->datUnit))) & 0xFF;
    levelAdvantage = (averageLevel - referenceLevel) >= 4;

    firstNode = ((ResistanceScanNode *)(((BtlBattleState *)(iGpffffb3ac))->unitLists[2]));
    flagNode = firstNode;
    metadata = iGpffffb3c4;
    for (; flagNode != NULL; flagNode = flagNode->next) {
        flags = (((BtlSoundEnemyStatusRow *)(metadata))[flagNode->id].flags);
        if ((flags & 0x40) != 0) {
            return 1;
        }
        if ((flags & 0x80) != 0) {
            return 0;
        }
    }

    if (hasSkill) {
        /* The first pass uses an element index; the second uses a node address. */
        uintptr_t scanPosition;

        secondaryMessage = -1;
        primaryMessage = secondaryMessage;

        {
            for (; firstNode != NULL; firstNode = firstNode->next) {
                for (scanPosition = 0; (s32)scanPosition < 8; scanPosition++) {
                    if ((datCalcGetElementAffinity(firstNode->data, (s16)scanPosition) & 0x07000000) != 0) {
                        switch (scanPosition) {
                        case 0:
                            primaryMessage = 0x17;
                            break;
                        case 1:
                            primaryMessage = 0x18;
                            break;
                        case 2:
                            primaryMessage = 0x19;
                            break;
                        case 3:
                            primaryMessage = 0x1B;
                            break;
                        case 4:
                            primaryMessage = 0x1A;
                            break;
                        case 6:
                            primaryMessage = 0x1C;
                            break;
                        case 7:
                            primaryMessage = 0x1D;
                            break;
                        }
                    }
                }
            }
        }

        {
            s32 secondElement;

            for (scanPosition = (uintptr_t)((ResistanceScanNode *)(((BtlBattleState *)(iGpffffb3ac))->unitLists[2]));
                 scanPosition != 0;
                 scanPosition = (uintptr_t)((ResistanceScanNode *)scanPosition)->next) {
                for (secondElement = 0; secondElement < 8; secondElement++) {
                    if ((datCalcGetElementAffinity(((ResistanceScanNode *)scanPosition)->data, (s16)secondElement) & 0x08000000) != 0) {
                        switch (secondElement) {
                        case 0:
                            secondaryMessage = 0x1E;
                            break;
                        case 1:
                            secondaryMessage = 0x1F;
                            break;
                        case 2:
                            secondaryMessage = 0x20;
                            break;
                        case 3:
                            secondaryMessage = 0x22;
                            break;
                        case 4:
                            secondaryMessage = 0x21;
                            break;
                        case 6:
                            secondaryMessage = 0x23;
                            break;
                        case 7:
                            secondaryMessage = 0x24;
                            break;
                        }
                    }
                }
            }
        }

        if (primaryMessage != -1) {
            return primaryMessage;
        }
        if (secondaryMessage != -1) {
            return secondaryMessage;
        }
    }

    if (levelAdvantage) {
        return 2;
    }

    switch (((BtlBattleState *)iGpffffb3ac)->openingSide) {
    case 0:
        return enemyCount + 2;
    case 1:
        return enemyCount + 7;
    case 2:
        return enemyCount + 12;
    default:
        return -1;
    }
}

/* Offer the multi-member party message unless it was the previous message. */
// FUN_001F3F60
s32 btlTargetPickPartyCountMessage(void)
{
    s32 state;

    state = ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->currentId;
    if (state == 0xFC) {
        return -1;
    }
    if ((func_001ef720(1, 0x80000) & 0xFFFF) < 2) {
        return -1;
    }
    return 0xFC;
}

