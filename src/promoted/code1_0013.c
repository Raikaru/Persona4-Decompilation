#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"

extern u32 datCalcGetHpById(s16 unitId);
extern u32 datCalcGetSpById(s16 unitId);
extern s32 radarSkillEffectMissing(s16 source, s16 recipient, s32 effect);
extern s32 cmpSkillApplySelected(s16 casterId, s16 targetId, s32 skillIndex, u8 *menu);
extern u32 RpRandom(void);
extern s32 nLineIsIdle(void);
struct GDataEntry;
extern struct GDataEntry *datEntryAt(s16 itemId);
extern u32 datEntryGetFlags(s16 itemId);
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 datCalcSkillEffectFlagsById(s16 sourceId, s16 targetId, u32 skillId, u32 flags);
extern void sdkSpriteFreeNode(void *node);
extern void radarDrawFrame(u8 *work);
extern void radarResetEntries(u8 *work);
extern void radarAnimateValue(void *work, s32 frame, s32 mode);
extern void datClampUnitHpSp(s16 unitId);
extern u16 datGetSkillPropertyByte(s32 skillId);
extern s32 titleSetMenuLayout(u8 *menu, u32 layout);
extern s32 nLineSelectSet(s32 setIndex);
extern s32 radarEntryTypeIsActive(s16 item);
extern s32 datIsSkillAvailable(s32 skillId);
extern void shdPersonaSetFlags(u8 *task, s32 inputFlags);
extern void shdPersonaClearFlags(u8 *task, s32 inputFlags);
extern void shdPersonaRefreshDispCtlPosition(u8 *task, u8 *position);
extern void shdPersonaSetChildDispCtlHandleAndColor(u8 *task, s32 handle, s32 color);
extern void sdkListStateConfigure(u8 *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern void sdkListStateSetActive(void *state, s32 value);
extern void sdkListStateSetSecondaryMasks(u8 *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern s32 sdkListStateHandleInput(u8 *state);
extern void cmpPersonaSetSelection(u8 *work, s32 slotIndex, s32 selection);
extern void shdPersonaBeginDisplay(u8 *task, s32 category, s32 personaAddress, s8 cursor);
extern void datPersonaSetLeadSlot(s16 slotIndex);
extern s32 datCalcThresholdTriggerById(s16 unitId, u32 skillId);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *task, s32 category, s32 personaAddress, s8 cursor);
extern s32 radarEntryIsAllowed(s16 character, s32 skillIndex, u8 *work);
extern s32 cmpSkillSetSelection(s16 *work, s32 slotIndex, s32 selection);
extern s32 cmpSkillSetMode(u8 *work, s32 mode);
extern void cmpSkillSetScrollCursorMotion(u8 *work);
extern void cmpEquipSetSelection(u8 *workArea, s32 slotIndex, s32 selection);
extern void cmpEquipBuildItemList(u8 *workArea);
extern void cmpEquipSetMode(u8 *workArea, s32 mode);
extern void radarBeginSlideOut(u8 *work);
extern void radarBeginSlideIn(u8 *work);
extern s16 datGetEquippedItemByUnit(s16 unitId, s16 slotIndex);
extern s32 datItemCount(s16 itemId);
extern void datAssignEquippedItem(s16 unitId, s16 slotIndex, s16 itemId);
extern void radarResetAndSetIndices(u8 *work, s16 sourceIndex, s16 targetIndex);
extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void radarDrawHeaderFrame(u8 *work, PackedVec2f position, u8 alpha, u16 flags);
extern void datEntryDrawRow(Vec2f position, f32 inputDepth, u8 opacity, u8 *inputEntry);
extern void datPanelResetCursor(u8 *entry);
extern s32 datCalcGetLevelById(s32 unitId);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void datEntryDrawByKind(Vec2f position, u8 opacity, void *entry, s32 flags, f32 depth);
extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                          s32 color, s32 font, s32 mode, s32 item);
extern void titleStateInit(u8 *menu);
extern s32 titleAdvanceWait(u8 *menu);
extern s32 radarPushHistoryValue(s32 menuAddress, s32 selectionIndex, s32 selection);
extern void resrcMngUnsuppressRender(void);
extern void resrcMngSuppressRender(void);
extern s32 datCommunityRequestExit(void);
extern void datCommunityCursorFeedback(s32 direction);
extern s32 nLineSelectSetImmediate(s32 setIndex);
extern s32 radarAdvanceGroupSelection(u8 *work);
extern s32 radarApplyItemStep(s16 source, s16 recipientId, u8 *work);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern void radarHandleEntrySelect(s32 *state, u8 *work);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2F4[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
extern u8 D_0064B30C[];
typedef signed __int128 code13S128;
extern void datSetUnitHp(s16 unitId, s16 hp);
extern void datSetUnitSp(s16 unitId, s16 sp);
extern void datSetFlag(s32 flagId, s32 enabled);
extern void datCalcApplySkillEffectById(s16 sourceId, s16 targetId, u32 skillId, u32 flags);
extern s32 FldStepNotAtBoundaryQuery(void);
extern void cmpSkillRandomizeCellMotions(u8 *work);
extern void *memset(void *, s32, u32);
extern s16 datBuildMemberIdList(s16 *ids);
extern s16 datBuildPartyIdList(s16 *ids);
extern s32 FldUnit_SpawnPartyTask(u8 *requests);
extern u8 *datScreenWipeTaskCreate(s32 parentAddress, u16 textureId);
extern u8 *resourceFindByName(char *name);
extern s32 radarSetMode(u8 *work, s32 value);
extern u8 D_005E57F0[];
extern u8 D_005E5810[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005EDEA0[];
extern u8 D_005EDA00[];
extern u8 D_005EF6C8[];
extern u8 D_005ED9E0[];
extern u8 D_005ED9F0[];
typedef struct {
    s32 first;
    s32 second;
} code13Pair;


/* measured: optimization level 1 reproduces the extra pointer that retail saves across the
 * function. */
#pragma optimization_level 1
#pragma optimization_level 2
/* measured: retail hoists loop-invariant loads out of this function's loop, so loop-invariant
 * motion is enabled here. */
#pragma push
/* measured: the baseline setting does not hoist invariants and comes out larger than retail, so
 * hoisting is turned on here. */
#pragma opt_loop_invariants on
/* This party-change snapshot is distinct from RadarMenu: IDs begin at 0x38,
 * the count follows eight halfword slots at 0x48, and each snapshot is three
 * halfwords. The intervening state is not read by this callback. */
typedef struct RadarPartyChanges {
    u8 pad00[0x38];
    s16 partyIds[8];
    s16 partyCount;
    u8 pad4A[0xC48 - 0x4A];
    s16 stats[8][3];
    u8 padC78[0x1594 - 0xC78];
    s32 partyTask;
} RadarPartyChanges;

// Collects party members' stat changes, records each changed stat, and spawns the party task if any
// stat changed.
// FUN_00134BE0
s32 radarCollectPartyChanges(u8 *state) {
    struct ChangeRecord {
        s32 id;
        s16 before;
        s16 after;
    };
    s16 party[4];
    struct ChangeRecord changes[4];
    s16 member;
    s32 count;
    s16 id, stat, search;
    s16 partyCount, value;
    s16 *old;
    struct ChangeRecord *change;

    count = 0;
    memset(changes, 0, sizeof(changes));
    partyCount = datBuildPartyIdList(party);
    for (member = 0; member < ((RadarPartyChanges *)state)->partyCount; member++) {
        id = ((RadarPartyChanges *)state)->partyIds[member];
        for (search = 0; search < partyCount && id != party[search]; search++) {}
        if (search != partyCount) {
            for (stat = 0; stat < 3; stat++) {
                value = datGetEquippedItemByUnit(id, stat);
                old = &((RadarPartyChanges *)state)->stats[member][stat];
                if (*old != value && stat == 0) {
                    change = &changes[count];
                    change->id = id;
                    change->before = *old;
                    change->after = value;
                    count++;
                }
            }
        }
    }
    if (count > 0) ((RadarPartyChanges *)state)->partyTask = FldUnit_SpawnPartyTask((u8 *)changes);
    return count > 0;
}
#pragma pop
