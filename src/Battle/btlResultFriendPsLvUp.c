#include "byte_address_internal.h"
#include "include_asm.h"
#include "member_access.h"
/* Original translation unit btlResultFriendPsLvUp.c (from __FILE__ assert strings). */
#include "type.h"
#include "datPersona_internal.h"
#include "btl_result_ui_internal.h"

/* Level-up previews have a 0x88-byte stride; the first byte gates the skill list. */
typedef struct BtlResultPersonaPreview {
    u8 levels;
    u8 pad01;
    u16 skills[32];
    u8 pad42[0x46];
} BtlResultPersonaPreview;
void kAssertFail(void *file, s32 line);

extern u32 kwlnTaskGetWork(void *task);
extern void PrimAppendNode(u8 *list, u8 *node);
extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern u8 *shdPersonaTaskCreate(s32 parentTask, s32 priority, s32 state, s32 openDuration, s32 closeDuration);
extern void shdPersonaSetOrigin(u8 *task, f32 *position);
extern void shdPersonaStartSlideIn(u8 *task);
extern void shdPersonaSetPersonaId(u8 *task, s32 personaId);
extern u32 datGetFlag(s32 bit);
extern void datSetFlag(s32 flagId, s32 enabled);
/* This unit declares the display id as u16 (the definition uses s32); retail compiled units
 * separately and loads the id after the window pointer. */
extern void shdPersonaSetDisplayState(u8 *task, u16 inputCategory, u32 personaAddress, s8 cursor);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern u8 *shdPersonaLevelUpCreate(s32 inputParentTask, s32 personaTask, u8 *inputLearnList, s32 messageResource, s32 extraMessage, s32 *messages);
extern u32 datCalcRandomBelow(u32 limit);
extern void btlSoundStopBank3(void);
extern void btlVoicePlayIdCue(s32 context, s32 value);
extern void btlVoiceFadeOut(void);
extern void btlSoundPlayIndexed(s32 voiceIndex);
extern s32 nmMesWindowResetCurrent(void);
extern u32 shdPersonaLevelUpIsDone(u8 *task);
extern s32 shdPersonaDestroyTask(u8 *task);
extern s32 btlShuffleOverlayIdle(void);
extern u8 D_00795F20[];
extern u8 D_005E4810[];
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_00629720[];


/* Map supported party IDs to the base voice-cue group, asserting on an unsupported party ID. */
// FUN_002238F0
s32 btlResultFriendPsCheck(s64 partyId)
{
    s64 kind;

    kind = (s16)partyId;
    switch (kind) {
    case 2:
        return 0xE2;
    case 3:
        return 0x16C;
    case 4:
        return 0x1F3;
    case 6:
        return 0x27A;
    case 7:
        return 0x301;
    case 8:
        return 0x387;
    default:
        kAssertFail(D_00629720, 0x2C);
        return 0;
    }
}

/* The task allocates 0x4C bytes; the scan index stays in 0..4, and index and parent fields are re-
 * read across calls as retail does. */

/* Addresses in the target's 32-bit work allocation are computed as unsigned
 * byte offsets before conversion to a live record pointer. */


// FUN_002239A0
/* Apply friend-persona experience, expose learned-skill flags, and sequence the persona level-up
 * windows. Previews use a 0x88-byte stride. */
s32 btlResultFriendPsUpdate(u8 *sdkTaskBytes)
{
    s32 taskAddress = (s32)sdkTaskBytes;
    /* The menu consumes eleven IDs. The position provider reads two floats.
     * Both complete objects occupy their original retail stack locations. */
    u8 *persona;
    u8 *parentWork;
    u32 state;
    s32 value;
    s32 skillIndex;
    u8 *work;
    u8 *awards;
    s32 index;
    u16 id;
    u32 skillId;
    s32 menuIds[11];
    f32 origin[2];
    BtlResultSummaryWork *summary;

    work = (u8 *)kwlnTaskGetWork(sdkTaskBytes);
    summary = (BtlResultSummaryWork *)work;
    parentWork = summary->parentWork;
    *(s32 *)&summary->drawNode[0] = 0;
    *(s32 *)&summary->drawNode[4] = 0;
    PrimAppendNode(D_00795F20, work + 8);
    state = *(u32 *)&summary->state;
    switch (state) {
    case 0:
        ((BtlResultSummaryWork *)(u32)work)->partyIndex = 0;
        value = (s32)kwlnTaskGetTaskByName((s8 *)D_005E4810);
        *(s32 *)&((BtlResultSummaryWork *)(u32)work)->personaWindow = value;
        if (value == 0) {
            value = (s32)shdPersonaTaskCreate(0, 15, 4, 5, 0);
            *(s32 *)&summary->personaWindow = value;
            if (value == 0) {
                kAssertFail(D_00629720, 116);
            }
            origin[0] = 0.0f;
            origin[1] = 19.0f;
            shdPersonaSetOrigin(summary->personaWindow, origin);
            shdPersonaStartSlideIn(summary->personaWindow);
        }
        shdPersonaSetPersonaId(summary->personaWindow, 174);
        *(u32 *)&summary->state = 2;
        /* fallthrough */
    case 1:
        awards = parentWork + 96;
        while ((index = summary->partyIndex) < 4) {
            id = ((BtlXpAwards *)awards)->partyIds[index];
            if (id != 0) {
                persona = (u8 *)datPersonaGetRecord(id);
                value = ((BtlXpAwards *)awards)->partyExp[summary->partyIndex];
                *(u32 *)&((DatPersonaRecord *)persona)->exp = *(u32 *)&((DatPersonaRecord *)persona)->exp + (u32)value;
                index = summary->partyIndex;
                if ((s32)((BtlResultPersonaPreview *)((BtlXpAwards *)awards)->partyPreviews[index])->levels > 0) {
                    break;
                }
            }
            summary->partyIndex = summary->partyIndex + 1;
        }
        if (index != 4) {
            for (skillIndex = 0; skillIndex < 32 && (skillId = MEMBER(u16, awards + summary->partyIndex * 136 + skillIndex * 2, BtlXpAwards, partyPreviews[0][2])) != 0; skillIndex++) {
                switch (skillId) {
                case 0x112:
                    if (datGetFlag(0x1012) != 0) {
                        kAssertFail(D_00629720, 158);
                    }
                    datSetFlag(0x1012, 1);
                    break;
                case 0x113:
                    if (datGetFlag(0x1013) != 0) {
                        kAssertFail(D_00629720, 163);
                    }
                    datSetFlag(0x1013, 1);
                    break;
                }
            }
            shdPersonaSetDisplayState(summary->personaWindow, ((BtlXpAwards *)(u32)byteAddressAdd((u32)summary->partyIndex * 2, (u8 *)((u32)awards)))->partyIds[0], (u32)persona, 0);
            menuIds[0] = 27;
            menuIds[1] = 25;
            menuIds[2] = 6;
            menuIds[3] = 9;
            menuIds[4] = 10;
            menuIds[5] = 26;
            menuIds[6] = 13;
            menuIds[7] = 14;
            menuIds[8] = -1;
            menuIds[9] = -1;
            menuIds[10] = -1;
            {
                s32 a;
                s32 b;
                parentWork = summary->parentWork;
                a = (s32)H_Cdvd_GetArchiveEntry((u8 *)((BtlResultWork *)parentWork)->file, 0, 0);
                parentWork = summary->parentWork;
                b = (s32)H_Cdvd_GetArchiveEntry((u8 *)((BtlResultWork *)parentWork)->file, 1, 0);
                summary->levelUpTask = shdPersonaLevelUpCreate(taskAddress, *(s32 *)&summary->personaWindow, awards + summary->partyIndex * 136 + 0x6B4, a, b, menuIds);
            }
            if (*(s16 *)&((BtlXpAwards *)(u32)byteAddressAdd((u32)summary->partyIndex * 2, (u8 *)((u32)awards)))->partyIds[0] == 5) {
                s16 t = (s16)(datCalcRandomBelow(3) + 468);
                btlSoundStopBank3();
                btlVoicePlayIdCue((u16)t, 3);
            } else {
                s32 stmp = btlResultFriendPsCheck(*(s16 *)&((BtlXpAwards *)(((u32)summary->partyIndex * 2) + ((u32)awards)))->partyIds[0]) + 125;
                s16 u = (s16)(stmp + datCalcRandomBelow(3));
                btlVoiceFadeOut();
                btlSoundPlayIndexed((u16)u);
            }
            *(u16 *)work = *(u16 *)work | 2;
            *(u32 *)&summary->state = 2;
        } else {
            *(u16 *)work = *(u16 *)work & 0xFFFE;
            *(u32 *)&summary->state = 7;
            nmMesWindowResetCurrent();
        }
        break;
    case 2:
        *(u32 *)&summary->state = 3;
        /* fallthrough */
    case 3:
        if (shdPersonaLevelUpIsDone(summary->levelUpTask) == 0) {
            break;
        }
        shdPersonaDestroyTask(((BtlResultSummaryWork *)work)->levelUpTask);
        *(u32 *)&summary->state = 4;
        summary->waitFrame = 0;
        /* fallthrough */
    case 4:
        if ((++summary->waitFrame >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (summary->waitFrame >= 4))) {
            *(u32 *)&summary->state = 1;
            summary->partyIndex = summary->partyIndex + 1;
        }
        break;
    case 5:
        if (btlShuffleOverlayIdle() != 0) {
            *(u32 *)&summary->state = 6;
            /* fallthrough */
        case 6:
            *(u16 *)work = *(u16 *)work & 0xFFFD;
            return -1;
        }
        break;
    case 7:
    default:
        break;
    }
    return 0;
}
