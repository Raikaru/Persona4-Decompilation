#include "byte_address_internal.h"
#include "member_access.h"
#include "btl_target_state_packet_internal.h"
#include "datPersona_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "camp_menu_internal.h"
#include "cmp_skill_internal.h"

extern u32 datCalcGetHpById(s16 unitId);
extern u32 datCalcGetSpById(s16 unitId);
extern s32 cmpSkillApplySelected(s16 casterId, s16 targetId, s32 skillIndex, u8 *menu);
struct GDataEntry;
extern s32 datCalcSkillEffectFlagsById(s16 sourceId, s16 targetId, u32 skillId, u32 flags);
extern void radarDrawFrame(u8 *work);
extern void radarResetEntries(u8 *work);
extern void radarAnimateValue(void *work, s32 frame, s32 mode);
extern s32 datIsSkillAvailable(s32 skillId);
extern void func_0010b3b0(s16 work);
extern s32 datCalcThresholdTriggerById(s16 unitId, u32 skillId);
extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth,
                          s32 color, s32 font, s32 mode, s32 item);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
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
extern void *memset(void *work, s32, u32);
extern s16 datBuildMemberIdList(s16 *ids);
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


/* measured: retail hoists loop invariants into the preheader, and loads the last sprite pointer
 * before the alpha conversion, which needs opt_propagation off. */
#pragma push
#pragma pop
/* measured: radarDrawSpritePair and radarResetLayout need opt_propagation off to keep retail's load
 * order and floating-zero constant materialization. */
#pragma push
#pragma pop
/* measured: modeled on radarDrawEntryRow with opt_propagation off; the selected entry is a local so
 * the compare keeps retail's operand order. */
#pragma push
#pragma pop
/* The call consumes a complete position and RGBA packet; explicit views of their argument storage
 * keep the Y load from being hoisted before the RGB snapshots. */
// FUN_0013F720
/* Apply the selected skill to one/all targets, deduct costs and restore persona
 * context. Return 0 for failure, 1/2 for application outcomes, or 3 for skill 0xF6. */
s32 cmpSkillApplySelected(s16 casterId, s16 targetId, s32 skillIndex, u8 *menu) {
    u8 *skillIdField;
    u8 *personaIdField;
    u8 *targetIdField;
    s32 result;
    s16 previousPersona;
    s32 skillId;
    s16 personaId;
    s32 hpCost;
    s32 spCost;
    s32 appliedCount;
    s32 targetIndex;
    s32 thresholdPassed;
    s32 resultCode;
    s32 remainingHp;
    s32 remainingSp;
    s32 soundResult;
    s16 thresholdPreviousPersona;
    s16 thresholdPersonaId;
    s32 thresholdSkillId;
    u8 *skillEntry;
    u8 *targetEntry;

    result = 1;
    previousPersona = -1;
    skillEntry = byteAddressAdd((u32)(skillIndex * 0xC), menu);
    skillIdField = skillEntry + 0x102;
    skillId = ((CmpSkillEntry *)(skillEntry + 0x100))->skillId;
    personaIdField = skillEntry + 0x100;
    personaId = ((CmpSkillEntry *)(skillEntry + 0x100))->personaId;
    hpCost = ((CmpSkillEntry *)(skillEntry + 0x100))->hpCost;
    spCost = ((CmpSkillEntry *)(skillEntry + 0x100))->spCost;
    if (personaId != -1) {
        previousPersona = (s16)func_0010b510();
        func_0010b3b0(personaId);
    }
    if ((skillId & 0xFFFF) == 0xF6) {
        if (FldStepNotAtBoundaryQuery() != 0) {
            result = 3;
        } else {
            result = 0;
        }
    } else if ((s16)targetId == -1) {
        appliedCount = 0;
        targetIndex = 0;
        while (targetIndex < ((CmpSkillMenu *)menu)->targetCount) {
            targetEntry = menu + targetIndex * 2;
            targetIdField = targetEntry + 0xF4;
            if (datCalcSkillEffectFlagsById(casterId, ((CmpSkillMenu *)targetEntry)->targetIds[0], skillId, 0) == 0) {
                datCalcApplySkillEffectById(casterId, *(s16 *)targetIdField, skillId, 0);
                appliedCount += 1;
            }
            targetIndex += 1;
        }
        if (appliedCount == 0) {
            result = 0;
        }
    } else if (datCalcSkillEffectFlagsById(casterId, targetId, skillId, 0) == 0) {
        datCalcApplySkillEffectById(casterId, targetId, skillId, 0);
    } else {
        result = 0;
    }
    resultCode = (s8)result;
    if (resultCode > 0) {
        if (hpCost > 0) {
            remainingHp = (datCalcGetHpById(casterId) & 0xFFFF) - hpCost;
            if (remainingHp <= 0) {
                kAssertFail(D_005ED9F0, 0x25B);
            }
            datSetUnitHp(casterId, (s16)remainingHp);
        }
        if (spCost > 0) {
            remainingSp = (datCalcGetSpById(casterId) & 0xFFFF) - spCost;
            if (remainingSp < 0) {
                kAssertFail(D_005ED9F0, 0x261);
            }
            datSetUnitSp(casterId, (s16)remainingSp);
        }
        if (resultCode == 3) {
            datSetFlag(0x1401, 1);
        } else {
            thresholdPassed = 1;
            thresholdPreviousPersona = -1;
            thresholdSkillId = *(u16 *)skillIdField;
            thresholdPersonaId = *(s16 *)personaIdField;
            if (datIsSkillAvailable(thresholdSkillId) == 0) {
                thresholdPassed = 0;
            } else {
                if (thresholdPersonaId != -1) {
                    thresholdPreviousPersona = (s16)func_0010b510();
                    func_0010b3b0(thresholdPersonaId);
                }
                if (datCalcThresholdTriggerById(casterId, thresholdSkillId) != 0) {
                    thresholdPassed = 0;
                }
                if (thresholdPreviousPersona != -1) {
                    func_0010b3b0(thresholdPreviousPersona);
                }
            }
            if (thresholdPassed == 0) {
                result = 2;
            } else {
                cmpSkillRandomizeCellMotions(menu);
            }
        }
    }
    if (previousPersona != -1) {
        func_0010b3b0(previousPersona);
    }
    soundResult = (s8)result;
    switch (soundResult) {
    case 0:
        sdkSndStartStream(0, 0, 0, 8);
        break;
    case 1:
    case 2:
        sdkSndStartStream(1, 3, 2, 0x16);
        break;
    case 3:
        break;
    default:
        kAssertFail(D_005ED9F0, 0x28C);
        break;
    }
    return result;
}

/* Zeroes and initialises the 0x18B0-byte radar state block; called from radarUpdateState. */
// FUN_0013FB50
#pragma push
/* measured: retail hoists loop-invariant address computations out of the initialization loops;
 * without this setting they are recomputed each iteration. */
#pragma opt_loop_invariants on
void radarInitState(u8 *work) {
    /* Grid/sprite cursors retain their original store order; their complete
     * strides and offsets are documented by CampMenu/CampGridEntry. */
    s16 i;
    s16 j;
    s16 n;
    s32 value;
    f32 f;
    u8 *resource0;
    u8 *resource1;
    u8 *resource2;
    s32 *slot;
    u8 *src;
    u8 *dst;

    memset(work, 0, 0x18B0);
    ((CampMenu *)work)->x.s = 0;
    ((CampMenu *)work)->y.s = 0;
    ((CampMenu *)work)->opacity = 0xFF;
    ((CampMenu *)work)->stage = 0;
    ((CampMenu *)work)->mode = -1;

    i = 0;
    while (i <= 0) {
        ((CampMenu *)work)->selection[i] = 0;
        i++;
    }

    j = 0;
    while (j < 0x29) {
        src = D_005EDEA0 + j * 0x1C;
        dst = work + j * 0x30;
        ((MenuSlotAnimation *)(dst + 0x40))->currentX.f = ((CampSlotLayout *)src)->x;
        ((MenuSlotAnimation *)(dst + 0x40))->currentY.f = ((CampSlotLayout *)src)->y;
        f = ((CampSlotLayout *)src)->scaleX;
        value = (u16)f;
        ((MenuSlotAnimation *)(dst + 0x40))->currentScaleX = value;
        f = ((CampSlotLayout *)src)->scaleY;
        value = (u16)f;
        ((MenuSlotAnimation *)(dst + 0x40))->currentScaleY = value;
        ((MenuSlotAnimation *)(dst + 0x40))->currentAlpha = ((CampSlotLayout *)src)->alpha;
        j++;
    }

    n = 0;
    while (n < 0x6C) {
        slot = (s32 *)(work + n * 0x14 + 0xFA4);
        *slot = n % 9;
        ((CampMenu *)work)->grid[n].columns = 9;
        ((CampMenu *)work)->grid[n].row = n / 9;
        ((CampMenu *)work)->grid[n].rows = 0xC;
        n++;
    }

    ((CampMenu *)work)->partyCount = datBuildMemberIdList((s16 *)(work + 0x22));
    resource0 = resourceFindByName((char *)D_005E5830);
    if (resource0 == 0) {
        kAssertFail(D_005EF6C8, 0x1EB);
    }
    resource1 = resourceFindByName((char *)D_005E5850);
    if (resource1 == 0) {
        kAssertFail(D_005EF6C8, 0x1ED);
    }
    ((CampMenu *)work)->spritePack = resource2 = resourceFindByName((char *)D_005E57F0);
    if (resource2 == 0) {
        kAssertFail(D_005EF6C8, 0x1EF);
    }
    if (resourceFindByName((char *)D_005E5810) == 0) {
        kAssertFail(D_005EF6C8, 0x1F1);
    }

    {
        s16 k;
        k = 0;
        while (k < 0x19) {
            if (k < 3) {
                slot = (s32 *)(work + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource0, D_005EDA00[k]);
            } else if (k < 0x18) {
                slot = (s32 *)(work + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource1, D_005EDA00[k]);
            } else {
                slot = (s32 *)(work + k * 4 + 0x1810);
                *slot = (s32)sdkSpriteNewNode((u32)resource2, D_005EDA00[k]);
            }
            if (*slot == 0) {
                kAssertFail(D_005EF6C8, 0x1FD);
            }
            k++;
        }
    }
    ((CampMenu *)work)->wipeTask.node = datScreenWipeTaskCreate(0, 1);
    radarSetMode(work, 0);
}

#pragma pop
// Advances the radar stage from 0 to 1; returns 1 once the stage is 1 or after advancing, 0
// otherwise.
// FUN_0013FF80
s32 radarAdvanceStage(u8 *work) {
    s32 v = MEMBER(s32, work, CampMenu, stage);

    switch (v) {
    case 0:
        v += 1;
        ((CampMenu *)work)->stage = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// Animates radar entries toward the current counter, then resets and draws the frame; returns 0
// while any entry is still busy.
// FUN_0013FFD0
s32 radarUpdateFrame(u8 *work) {
    s16 frame;
    s32 i;
    s32 result;
    u8 *p;

    result = 1;
    frame = MEMBER(s16, work, CampMenu, frame);
    if (frame < 0x64) {
        ((CampMenu *)work)->frame = frame + 1;
    }
    i = 0;
    goto loop_test;
loop_body:
    if ((i >= 0x1C) || ((i >= 9) && (i < 0x10))) {
        p = work + i * 0x30;
        radarAnimateValue(p + 0x40, ((CampMenu *)work)->frame, 1);
    } else {
        p = work + i * 0x30;
        radarAnimateValue(p + 0x40, ((CampMenu *)work)->frame, 0);
    }
    if (((CampMenu *)p)->entries[0].currentAlpha != 0) {
        result = 0;
    }
    i++;
loop_test:
    if (i < 0x29) {
        goto loop_body;
    }
    radarResetEntries(work);
    radarDrawFrame(work);
    return result;
}

