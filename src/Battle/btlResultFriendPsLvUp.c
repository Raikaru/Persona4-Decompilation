#include "include_asm.h"
/* Original translation unit btlResultFriendPsLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "datPersona_internal.h"
#include "btl_result_ui_internal.h"

void kAssertFail(void *arg0, s32 arg1);

extern u32 kwlnTaskGetWork(void *task);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern u8 *shdPersonaTaskCreate(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void shdPersonaSetOrigin(u8 *task, f32 *position);
extern void shdPersonaStartSlideIn(u8 *task);
extern void shdPersonaSetPersonaId(u8 *task, s32 a1);
extern u32 datGetFlag(s32 arg0);
extern void datSetFlag(s32 arg0, s32 arg1);
/* This unit's view of the window helper takes the 16-bit display id as u16.
   The definition (shdPersona.c) and its other callers use s32; retail
   compiled each unit separately, and only a u16 parameter here emits the id
   load after the window-pointer argument, as at 00223b5c. A conversion
   argument is always evaluated first (docs/matching.md). */
extern void shdPersonaSetDisplayState(u8 *arg0, u16 arg1, u32 arg2, s8 arg3);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *archive, s32 index, s32 *size);
extern u8 *shdPersonaLevelUpCreate(s32 a0, s32 a1, u8 *a2, s32 a3, s32 a4, s32 *a5);
extern u32 datCalcRandomBelow(u32 max);
extern void btlSoundStopBank3(void);
extern void func_001f9a50(s32 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void btlSoundPlayIndexed(s32 arg0);
extern s32 nmMesWindowResetCurrent(void);
extern u32 shdPersonaLevelUpIsDone(u8 *task);
extern s32 shdPersonaDestroyTask(u8 *task);
extern s32 btlShuffleOverlayIdle(void);
extern u8 D_00795F20[];
extern u8 D_005E4810[];
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_00629720[];



// FUN_002238F0
/* Map supported party IDs to the base voice-cue group, asserting on an unsupported party ID. */
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

/* Defined guarded recovery: 1320 executable bytes and eight zero alignment
 * bytes. The current C candidate retains 53 instruction-word differences;
 * production remains ASM. Contracts, lifecycle and complete-owner receipts:
 * build/cos20814/resume-results19/REPORT.md.
 * The task constructor allocates 0x4C bytes. Its scan index stays in 0..4;
 * reaching the selected path assigns the persona pointer during this call.
 * Re-read index and parent fields across calls as the retail body does. */

/* Addresses in the target's 32-bit work allocation are computed as unsigned
 * byte offsets before conversion to a live record pointer. */
static inline u32 friendResultAddress(u32 offset, u32 base)
{
    return offset + base;
}

/* r and base are declared after the loop counter. The first two stores
   through r in the opening state form the address as (u32)r + offset. That
   repeated conversion is copied from r inside the switch, which keeps r a
   local at its declared number (docs/matching.md, "Keep a load local
   alive"). The (u32)base argument of friendResultAddress keeps base alive
   the same way, giving retail's $s3/$s2 for r/base. */
// FUN_002239A0
/* Apply friend-persona experience, expose learned-skill flags, and sequence the persona level-up
 * windows. Measured: typed summary index/state/window reloads change MATCH; raw preview rows retain
 * their canonical 0x88-byte byte-buffer layout. */
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

    work = (u8 *)kwlnTaskGetWork(sdkTaskBytes);
    parentWork = *(u8 * *)(work + 60);
    *(s32 *)(work + 8) = 0;
    *(s32 *)(work + 12) = 0;
    PrimAppendNode(D_00795F20, work + 8);
    state = *(u32 *)(work + 4);
    switch (state) {
    case 0:
        *(s32 *)((u32)work + 56) = 0;
        value = (s32)kwlnTaskGetTaskByName((s8 *)D_005E4810);
        *(s32 *)((u32)work + 68) = value;
        if (value == 0) {
            value = (s32)shdPersonaTaskCreate(0, 15, 4, 5, 0);
            *(s32 *)(work + 68) = value;
            if (value == 0) {
                kAssertFail(D_00629720, 116);
            }
            origin[0] = 0.0f;
            origin[1] = 19.0f;
            shdPersonaSetOrigin(*(u8 * *)(work + 68), origin);
            shdPersonaStartSlideIn(*(u8 * *)(work + 68));
        }
        shdPersonaSetPersonaId(*(u8 * *)(work + 68), 174);
        *(u32 *)(work + 4) = 2;
        /* fallthrough */
    case 1:
        awards = parentWork + 96;
        while ((index = *(s32 *)(work + 56)) < 4) {
            id = ((BtlXpAwards *)awards)->partyIds[index];
            if (id != 0) {
                persona = (u8 *)datPersonaGetRecord(id);
                value = ((BtlXpAwards *)awards)->partyExp[*(s32 *)(work + 56)];
                *(u32 *)&((DatPersonaRecord *)persona)->exp = *(u32 *)&((DatPersonaRecord *)persona)->exp + (u32)value;
                index = *(s32 *)(work + 56);
                if ((s32)*(u8 *)(awards + index * 136 + 0x6B4) > 0) {
                    break;
                }
            }
            *(s32 *)(work + 56) = *(s32 *)(work + 56) + 1;
        }
        if (index != 4) {
            for (skillIndex = 0; skillIndex < 32 && (skillId = *(u16 *)(awards + *(s32 *)(work + 56) * 136 + skillIndex * 2 + 0x6B6)) != 0; skillIndex++) {
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
            shdPersonaSetDisplayState(*(u8 * *)(work + 68), *(u16 *)(friendResultAddress((u32)*(s32 *)(work + 56) * 2, (u32)awards) + 0x69A), (u32)persona, 0);
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
                parentWork = *(u8 * *)(work + 60);
                a = (s32)H_Cdvd_GetArchiveEntry((u8 *)((BtlResultWork *)parentWork)->file, 0, 0);
                parentWork = *(u8 * *)(work + 60);
                b = (s32)H_Cdvd_GetArchiveEntry((u8 *)((BtlResultWork *)parentWork)->file, 1, 0);
                *(u8 **)(work + 72) = shdPersonaLevelUpCreate(taskAddress, *(s32 *)(work + 68), awards + *(s32 *)(work + 56) * 136 + 0x6B4, a, b, menuIds);
            }
            if (*(s16 *)(friendResultAddress((u32)*(s32 *)(work + 56) * 2, (u32)awards) + 0x69A) == 5) {
                s16 t = (s16)(datCalcRandomBelow(3) + 468);
                btlSoundStopBank3();
                func_001f9a50((u16)t, 3);
            } else {
                s32 stmp = btlResultFriendPsCheck(*(s16 *)(friendResultAddress((u32)*(s32 *)(work + 56) * 2, (u32)awards) + 0x69A)) + 125;
                s16 u = (s16)(stmp + datCalcRandomBelow(3));
                func_001f9a90();
                btlSoundPlayIndexed((u16)u);
            }
            *(u16 *)work = *(u16 *)work | 2;
            *(u32 *)(work + 4) = 2;
        } else {
            *(u16 *)work = *(u16 *)work & 0xFFFE;
            *(u32 *)(work + 4) = 7;
            nmMesWindowResetCurrent();
        }
        break;
    case 2:
        *(u32 *)(work + 4) = 3;
        /* fallthrough */
    case 3:
        if (shdPersonaLevelUpIsDone(*(u8 **)(work + 72)) == 0) {
            break;
        }
        shdPersonaDestroyTask(((BtlResultSummaryWork *)work)->levelUpTask);
        *(u32 *)(work + 4) = 4;
        *(u16 *)(work + 64) = 0;
        /* fallthrough */
    case 4:
        if ((++*(u16 *)(work + 64) >= 45) || ((D_008C024E[0] & 0x50) != 0) || (((D_008C024C[0] & 0x10) != 0) && (*(u16 *)(work + 64) >= 4))) {
            *(u32 *)(work + 4) = 1;
            *(s32 *)(work + 56) = *(s32 *)(work + 56) + 1;
        }
        break;
    case 5:
        if (btlShuffleOverlayIdle() != 0) {
            *(u32 *)(work + 4) = 6;
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
