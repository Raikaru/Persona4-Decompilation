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
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
static inline f32 code13Add(f32 left, f32 right) {
    return left + right;
}
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
extern void shdPersonaRefreshDispCtlPosition(u8 *, void *);
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
extern void sdkSpriteDrawAt(void *sprite, f32 fparg0, f32 fparg1,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawSized(u8 *sprite, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 fparg3, s16 arg_sp0);
extern void radarDrawHeaderFrame(u8 *work, PackedVec2f position, u8 alpha, u16 flags);
extern void datEntryDrawRow(Vec2f position, f32 fparg0, u8 opacity, u8 *inputEntry);
extern void datPanelResetCursor(u8 *entry);
extern void datPanelDrawByKind(Vec2f origin, f32 depth, s32 opacity, u8 *entry, s32 fullName);
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
extern u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
extern void kAssertFail(void *file, s32 line);
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

 

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* measured: donor loop shape requires invariant hoisting for the retail preheader and loop register coloring. */
#pragma opt_loop_invariants on
/* measured: close the donor loop's invariant-hoisting bracket. */
#pragma opt_loop_invariants off
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
/* measured: closing O1 probe. */
#pragma optimization_level 2
/* measured: 1448B in the 1456B window.  The slot x/y reads are f32-array views
   (retail adds the row before arg0), and the last sprite pointer is a local
   loaded ahead of the alpha conversion, which needs opt_propagation off. */
#pragma push
#pragma opt_propagation off
#pragma pop
/* measured: close opt_propagation for radarDrawSpritePair probe. */
#pragma opt_propagation on
/* measured: second 00134890 probe preserves the retail floating zero and constant materialization. */
#pragma opt_propagation off
/* measured: close opt_propagation for radarResetLayout. */
#pragma opt_propagation on
/* measured: loop-invariant hoisting gives 444B / 448B with only zero tail padding. */
#pragma push
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

// Intent: Collect the stat changes of party members, record each changed stat, and spawn the party task when any changed [inferred]
// Kept in bucket: diff 262 when moved; cause not diagnosed.
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
/* measured: close mixed-ABI palette draw pair pragma. */
#pragma opt_propagation on
/* measured: close neighboring mixed-ABI palette branch pragma. */
#pragma opt_propagation on
/* measured: the 130.0f sum is assigned to a different (dead) variable, so mwcc
   emits the constant as the first add.s operand like retail; `temp_f21 +=
   130.0f` keeps the variable first. The 467.0f sum is recomputed for the last
   call, as retail does. */
/* measured: 1580B in the 1584B window.  Built from the matched twin
   radarDrawEntryRow (same slot views, same sprite-pointer local under
   opt_propagation off); the selected entry is a local so the compare keeps
   retail's operand order. */
#pragma push
#pragma opt_propagation off
#pragma pop
/* measured: close family opt_propagation bracket. */
#pragma opt_propagation on
static inline s32 code13GroupBefore(u8 *arg0, s32 index)
{
    u32 selected;
    selected = datEntryGetFlags(*(s16 *)(code13AddOff((index - 1) * 4, arg0) + 0x3E));
    index = index - 1;
    while (index > 0) {
        if (datEntryGetFlags(*(s16 *)(arg0 + index * 4 + 0x3A)) != selected) break;
        index--;
    }
    return index;
}
static inline s32 code13GroupBeforeOrSame(u8 *arg0, s32 total)
{
    if (total == 0) {
        return total;
    } else {
        return code13GroupBefore(arg0, total);
    }
}
static inline s32 code13GroupAfter(u8 *arg0, s32 total, s32 count, s32 wrap)
{
    s32 index;
    u32 selected;
    selected = datEntryGetFlags(*(s16 *)(code13AddOff(total * 4, arg0) + 0x3E));
    index = total + 1;
    while (index < count) {
        if (datEntryGetFlags(*(s16 *)(arg0 + index * 4 + 0x3E)) != selected) break;
        index++;
    }
    if (index >= count) index = wrap;
    return index;
}
/* The sum's inline boundary preserves the retail column-before-row loads. */
#pragma opt_propagation off
static inline s32 code13SelectionSum(s32 row, s32 column)
{
    return row + column;
}
#pragma opt_propagation on
/* Matched.  Same menu-state-machine family as radarTransferMenuUpdate, radarPersonaMenuUpdate
   and radarUpdateState: `*arg1 = (var_2 = 1)`, a switch on *arg0 whose arms
   break to a shared `return 0`, the fade arm returning 2, and a 0x30-byte
   query buffer.  Cases are written in retail layout order
   0,1,2,3,4,7,8,9,10,5,6,11; numeric order costs 82 words.  The s32 third
   parameter for func_0012ff40 gives retail's word loads (217 -> 2).  The
   party-slot address `(u8 *)((u8 *)(*(s16 *)(arg2 + 0x26) * 2) +
   (u32)arg2) + 0x34` gives retail's index-then-base addu.  The last two
   words were the argument setup order at the radarApplyItemStep call: with an
   s32 second parameter MWCC schedules the `lh` before the `move`, with
   s16 it emits retail's move-then-load, so the declaration above is
   load-bearing. */
/* MATCHED: the same menu state machine as radarPersonaMenuUpdate beside it.  Nine of
   m2c's call arguments are stale registers - func_001312b0, func_001318c0,
   radarWideEntriesCoverValue, radarCollectPartyChanges, radarTransferSelectedUnit, radarBeginPickList,
   func_00452490 and two func_00134560 sites all take one fewer.  The two
   pick-list tests are `if ((n = sdkListStateHandleInput(buf)) > 0)`: assigning in
   the condition keeps the count in $v0 for the `blez`, where a separate
   statement moves it to a saved register first. */
/* The original row survives item application; recipient traversal and the
   post-removal selection have separate lifetimes. Item accessors and
   inventory writes share the same signed halfword ID. */
/* MATCHED: the same menu state machine as func_0035e8b0, func_0035f0c0 and
   func_003627b0 - `*arg1 = (var_2 = 1);`, a switch on *arg0 whose arms break
   to a shared `return 0`, the fade arm returning 2, and a 0x30-byte query
   buffer whose result is read at +0x24.  Two spellings did the rest: the
   party-slot address is `(u8 *)(index * 2) + (u32)arg2`, which gives
   retail's index-then-base `addu`, and the two func_002bb140 switches are
   written `case 0:` before `case 1:` so their compare chains come out
   1-then-0.  m2c's `&jtbl_00746A80` arguments to func_0010b7f0 and
   datCommunityRequestExit are stale registers; both take none. */
/* The selected recipient has both a signed-halfword skill API value and a
   promoted menu-helper value. Query results are tested before their later
   uses, and controller masks retain C integer promotion. */
#pragma push
#pragma opt_loop_invariants on
#pragma pop
