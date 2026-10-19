#include "include_asm.h"
/* Original translation unit btlResultHeroLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_result_ui_internal.h"

typedef struct BtlResultHeroWork BtlResultHeroWork;
struct BtlResultHeroWork
{
    u16 flags;          // 0x00
    u8 pad2[2];
    u32 state;          // 0x04
    s32 count;          // 0x08
    s32 field0C;        // 0x0C
    s32 field10;        // 0x10
    u8 pad14[0x28];
    u8* field3C;        // 0x3C
    u32 state40;        // 0x40
    s8 field44;         // 0x44
    u8 pad45[7];
    s32 field4C;        // 0x4C
    s32 slots50[2];     // 0x50
    u8 field58;         // 0x58
};

s16 datGetPartyId(s32 index);
u32 datCalcIsDeadById(s16 param);
s32 datGetFlag(s32 id);
void btlSoundPlayIndexed(u16 param);
void btlSoundStopBank3(void);
void func_001f9a50(u16 param, s32 mode);
void func_001f9a90(void);
extern u32 datCalcRandomBelow(u32 max);
void kAssertFail(const char* file, s32 line);
extern char D_00629660[];
s32 btlLogoUnlockStage(u8* work);
extern u8 nmMesWindowOpenCurrent(u8 *message);
void nmMesWindowShowCurrentRecord(s32 param);
void nmMesWindowResetCurrent(void);
void nmMesWindowSetCurrentString(s32 param, void* text);
s32 datMemberNoticeTryBegin(s32 param);
void sprintf(void* dst, void* fmt, s32 value);
u8* H_Cdvd_GetArchiveEntry(u8* param, s32 a, s32* b);
s32 datCalcGetLevelById(s32 param);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern char iGpffffa5C8;
void sflDataResetPersonaState(void* work);
void sflDataLoadPersonaState(void* work, s16 pcId);
s32 datScreenWipeTaskCreate(u8* param, s32 mode);
void radarDrawEdge(s32 param, s32 a, s32 b, s32 c);
void datScreenWipeSetColor(s32 param, s32 mode);
s32 btlShuffleOverlayIdle(void);
extern u8* kwlnTaskGetWork(u32 param);
void PrimAppendNode(void* param, void* work);
s32 resourceFindByName(u32 param);
extern u32 D_00795F20[];
extern s32 iGpffffa5C0;

// FUN_00221AB0
/* Choose a living party member for a level-up voice cue, or use the protagonist fallback cue group. */
void btlResultHeroLvUpInit(void)
{
    s16 list[4];
    s32 i = 0;
    s32 count = 0;
    s32 val;

    for (; i < 4; i++) {
        s16 v = datGetPartyId(i);

        if (v != 0 && datCalcIsDeadById(v) == 0) {
            list[count++] = v;
        }
    }
    if (count > 0 && datCalcRandomBelow(0x64) < 0x32) {
        s16 pick = list[datCalcRandomBelow(count)];

        switch (pick) {
        case 2:
            val = 0xE2;
            break;
        case 3:
            val = 0x16C;
            break;
        case 4:
            val = 0x1F3;
            break;
        case 6:
            val = 0x27A;
            break;
        case 7:
            val = 0x301;
            break;
        case 8:
            val = 0x387;
            break;
        default:
        case 0:
        case 1:
        case 5:
            kAssertFail(D_00629660, 0x98);
            val = 0;
            break;
        }
        {
            s16 sound = (s16)(val + 0x80 + datCalcRandomBelow(3));

            func_001f9a90();
            btlSoundPlayIndexed((u16)sound);
        }
        return;
    }
    {
        s16 v = (datGetFlag(0x38) != 0) ? 5 : 8;

        switch (v) {
        case 5:
            val = 0x1D7;
            break;
        case 8:
            val = 0x192;
            break;
        default:
            kAssertFail(D_00629660, 0xAA);
            val = 0;
            break;
        }
    }
    {
        s16 sound = (s16)(val + datCalcRandomBelow(3));

        btlSoundStopBank3();
        func_001f9a50((u16)sound, 3);
    }
}

// FUN_00221CF0
// SOLVED by tools/permute.py; this previously carried an nd-4 note calling the
// residual the $v0-vs-$at compare-temp floor. The permuter cracked it from the
// preserved body.
#pragma tailcall off
/* Sequence the hero level and unlock messages, then delay before completion. The raw archive handle is
 * read from the shared result parent. */
s32 btlResultHeroLvUpStep(BtlResultHeroWork* work)
{
    BtlResultHeroWork* result = work;
    u32 levelText[4];
    u32 unlockText[4];

    switch (result->state40) {
    case 0:
        if ((work->flags & 8) || (D_008C024E[0] & 0x50) ||
            ((D_008C024C[0] & 0x10) && ((work->count = result->count + 1) > 4))) {
            nmMesWindowOpenCurrent((u8 *)((s32)H_Cdvd_GetArchiveEntry(*(u8 **)&((BtlResultWork *)result->field3C)->file, 0, 0)));
            sprintf(levelText, &iGpffffa5C8, datCalcGetLevelById(1) & 0xFF);
            nmMesWindowSetCurrentString(0, levelText);
            nmMesWindowShowCurrentRecord(3);
            work->state40 = 1;
        }
        break;
    case 1:
        if (datMemberNoticeTryBegin(1) == 0) {
            if (btlLogoUnlockStage((u8*)result) != 0) {
                nmMesWindowShowCurrentRecord(4);
                result->state40 = 2;
            } else {
                work->state40 = 4;
            }
        }
        break;
    case 2:
        if (datMemberNoticeTryBegin(1) == 0) {
            sdkSndStartStream(1, 0, 3, 0);
            sprintf(unlockText, &iGpffffa5C8, work->field44);
            nmMesWindowSetCurrentString(0, unlockText);
            nmMesWindowShowCurrentRecord(5);
            work->state40 = 3;
        }
        break;
    case 3:
        if (datMemberNoticeTryBegin(1) == 0) {
            work->state40 = 4;
        }
        break;
    case 4:
        nmMesWindowResetCurrent();
        result->count = 0;
        work->state40 = 5;
        /* fallthrough */
    case 5:
        if ((work->count = 1 + result->count) <= 4) {
            break;
        }
        return 1;
    default:
        kAssertFail(D_00629660, 0x12D);
        break;
    }
    return 0;
}
#pragma tailcall on

// FUN_00221F40
/* Drive the hero result task, wipe, persona descriptor and message lifecycle until teardown. Raw
 * parent archive/flags and adjacent sprite symbols retain their established external storage. */
s32 btlResultHeroLvUpRun(u8* task)
{
    BtlResultHeroWork* work = (BtlResultHeroWork*)kwlnTaskGetWork((u32)task);
    s32 i;

    work->field0C = 0;
    work->field10 = 0;
    PrimAppendNode(D_00795F20, &work->field0C);
    switch (work->state) {
    case 0:
        sflDataResetPersonaState(&work->field58);
        sflDataLoadPersonaState(&work->field58, 1);
        work->field4C = datScreenWipeTaskCreate(task, 1);
        radarDrawEdge(work->field4C, 2, 1, 0);
        datScreenWipeSetColor(work->field4C, 0);
        work->flags |= 2;
        work->state = 1;
        /* fallthrough */
    case 1:
        for (i = 0; i < 2; i++) {
            s32* slot = &work->slots50[i];

            *slot = resourceFindByName(*(u32*)((u8*)&iGpffffa5C0 + i * 4));
            if (*slot == 0) {
                kAssertFail(D_00629660, 0x52);
            }
        }
        btlResultHeroLvUpInit();
        work->state = 2;
        break;
    case 2:
        if (btlResultHeroLvUpStep(work) != 0) {
            s32 f = *(s32 *)&((BtlResultWork *)work->field3C)->awards.flags;

            if (f & 8) {
                work->state = 3;
                nmMesWindowOpenCurrent((u8 *)((s32)H_Cdvd_GetArchiveEntry(*(u8 **)&((BtlResultWork *)work->field3C)->file, 0, 0)));
                nmMesWindowShowCurrentRecord(1);
            } else if (f & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 6;
            } else {
                work->flags &= 0xFFFE;
                work->state = 6;
                work->flags |= 4;
            }
        }
        break;
    case 3:
        if (datMemberNoticeTryBegin(1) == 0) {
            nmMesWindowResetCurrent();
            work->flags &= 0xFFFE;
            work->state = 6;
        }
        break;
    case 4:
        if (btlShuffleOverlayIdle() != 0) {
            work->state = 5;
        case 5:
            if ((work->flags & 4) || (++work->count >= 5)) {
                work->flags &= 0xFFFD;
                radarDrawEdge(work->field4C, 2, 0, 1);
                return -1;
            }
            break;
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
