#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "sdk_snd_internal.h"
#include "datPersona_internal.h"
#include "btl_shuffle_result_internal.h"
#include "btl_shuffle_task_internal.h"

/* Payload at work + 0x18. The remaining bytes are cleared by persona setup,
   but are not accessed by this result state machine. */
typedef struct ShuffleResultState {
    s32 phase;
    u16 timer;
    u16 step;
    s32 spinsRemaining;
    u8 resultCard;
    u8 reserved0D[3];
    s32 isUpright;
    s32 uprightOverride;
    s32 secondaryResult;
} ShuffleResultState;

s32 btlShuffleResultMain(u8 *input);
extern s32 nmMesWindowResetCurrent(void);
extern void (*jtbl_008873EC[])(void *ptr);
extern void nmMesWindowStepCurrent(s32 a);
extern s32 nmMesWindowCurrentOpenState(void);
extern u32 nmMesWindowCloseCurrent(int value);
extern s32 nmMesWindowShowCurrentRecord(s32 input);
extern void *memset(void *dst, s32 value, size_t size);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void kAssertFail(void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064EB60[];
extern u8 D_0064EC70[];

extern s32 btlShuffleResultBonus(u8 *work, u8 *input, s32 value, u16 option, s32 extra);
extern s32 btlShuffleDrawTableLookup(s32 a, s32 b);
extern void btlShuffleCardUpdateState(u8 *input);
extern void *btlShuffleGetParentWork(void *input);
extern void btlShuffleResetSlot(u8 *input);
extern void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst);
extern void btlShuffleDrawMoveCard(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void btlShuffleDrawViewReset(u8 *a);
extern s32 btlShuffleDrawStateC(u8 *a);
extern void btlShuffleSeqUpdateMode(u8 *ctx, s32 a, u16 b, s32 c);
extern void btlShuffleDrawViewSetMenuBusy(u8 *a);
extern s32 btlShuffleDrawViewIsMenuReady(u8 *a);
extern void btlShuffleDrawViewEndMenu(u8 *a);
extern s32 btlShuffleDrawViewIsMenuIdle(u8 *a);
extern void btlShuffleDrawCardEndBands(u8 *a);
extern void btlShuffleEffEnd(u8 *a);
extern void btlShuffleEffUpdate(u8 *a);
extern void btlShuffleEffInitTrail(u8 *a, s32 b);
extern void btlShuffleEffSetup(u8 *a, s32 b);
extern s32 btlShuffleAddRosterMember(u8 *input, s32 value);
extern s32 btlShuffleResultOpen(u8 *input);
extern s32 btlShuffleResultRun(u8 *input);
extern s32 btlShuffleResultInit(u8 *input);
extern s32 btlShuffleResultLayout(u8 *input);
extern s32 btlShuffleResultMenu(u8 *input);
extern u8 *shdPersonaTaskCreate(s32 input, s32 value, s32 option, s32 extra, s32 flags);
extern void nmMesWindowSetCurrentString(s32 a, void *text);
extern s32 nmMesWindowSetCurrentParam(s32 input);
extern void nmMesWindowSetCurrentFlag(u8 value);
extern void nmMesWindowRequestRefresh(void);
extern s32 nmMesWindowCurrentAnimFlag(void);
extern void shdPersonaSetDisplayState(u8 *input, s32 value, u32 option, s8 extra);
extern void shdPersonaStartSlideIn(u8 *input);
extern void shdPersonaBeginClose(u8 *input);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *input, s32 value, s32 option, s8 extra);
extern void shdPersonaBeginDisplay(u8 *input, s32 value, s32 option, s8 extra);
extern void shdPersonaBeginSelection(u8 *input);
extern void shdPersonaEndSelection(u8 *input, s32 value);
extern void shdPersonaStepSelectionCursor(u8 *input);
extern void shdPersonaFinishPhase(u8 *input);
extern void sdkListStateConfigure(u8* input, s32 value, s32 option, s32 extra, s32 flags);
extern void sdkListStateSetSecondaryMasks(u8 *buf, s32 a, s32 b, s32 c, s32 d);
extern void sdkListStateSetPrimaryMasks(u8 *buf, s32 a, s32 b, s32 c, s32 d);
extern void sdkListStateSetActive(u8 *buf, s32 a);
extern s32 sdkListStateHandleInput(u8 *buf);
extern void btlShuffleDrawCardActivate(u8 *input);
extern void btlShuffleDrawCardSetDetail(u8 *input, s32 value);
extern void btlShuffleDrawCardEndDetail(u8 *input);
extern void btlShuffleDrawViewSetActive(u8 *input);
extern void btlShuffleDrawViewClearActive(u8 *input);
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 a);
extern s32 cmmCommunityValueForArcana(s32 a);
extern s32 FldStepBandFlagSet(void);
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void *btlShuffleGetDrawContext(void *a);
extern s32 btlShuffleDrawSpawn(u8 *parent, s32 cardIndex);
extern void btlShuffleDrawCardActivateRing(u8 *a);
extern u32 RpRandom(void);
extern s32 btlShuffleRollChance(u8 *a);
extern u8 D_0064E6E0[][2];
extern u8 D_0064E700[][2];
extern u8 iGpffffa9B8[5]; /* per-rate bonus thresholds: 5, 5, 5, 10, 10 */
extern u8 D_0064E72E[][2];
extern BtlShuffleVec3 D_0064EC88;
extern const char *iGpffffa9E0; /* "upright" */
extern const char *iGpffffa9E4; /* "reversed" */
extern void btlShuffleDrawSetPose(u8 *a, s32 b, u16 c, u16 d);
extern s32 btlShuffleDrawFlagA(u8 *task);
extern s32 btlShuffleDrawViewIsRunReady(u8 *a);
extern void btlShuffleDrawViewStartRun(u8 *a);
extern void btlShuffleDrawViewExpandRun(u8 *a);
extern void btlShuffleDrawViewStartDesaturation(u8 *a);
extern void btlShuffleDrawViewStartReveal(u8 *a);
extern s32 btlShuffleDrawViewIsRevealFinished(u8 *a);
extern void btlShuffleDrawViewEndReveal(u8 *a);
extern void btlShuffleSeqClearA(u8 *a, s32 b);
extern s32 btlShuffleSeqFlag(u8 *a);
extern s32 btlShuffleShowRosterMessage(u8 *a);
extern char *datCalcGetSlotRecord(s32 a);
extern char *strcpy(char *dst, const char *source);
struct KwlnTask;
extern s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *task);
extern void datSetFlag(s32 a, s32 b);



/* The list cursor uses the entry row and scroll values in states 2-4.
   Keep the selected slot, display and mode as separate call inputs; measured
   propagation-off code preserves the retail argument evaluation order. */
// FUN_00380EA0
#pragma push
#pragma opt_propagation off
s32 btlShuffleResultOpen(u8 *work)
{
    u8 *state;
    s32 sum;
    s32 row;
    s32 scroll;
    s32 cnt;
    s32 cur;
    s32 i;
    s32 j;
    u16 *slotp;
    u16 **dst;
    u8 buf[0x30];
    s32 res;
    s32 idx;

    state = work + 0x18;
    scroll = ((BtlShuffleResultRoster *)(work + 0x18))->scroll;
    row = ((BtlShuffleResultRoster *)(work + 0x18))->row;
    sum = row + scroll;
    switch (((BtlShuffleResultRoster *)state)->phase) {
    case 0:
        datPersonaInitRecord(state + 0x1C, ((BtlShuffleResultWork *)work)->personaId);
        *((BtlShuffleResultRoster *)state)->slots = state + 0x1C;
        cnt = (u16)datPersonaRosterCapacity();
        cur = (u16)datPersonaLeadPersonaId();
        i = 0;
        j = 1;
        for (; i < cnt; i++) {
            dst = (u16 **)(state + j * 4 + 0x4C);
            slotp = (u16 *)datPersonaRosterSlot((s16)i);
            *dst = slotp;
            if (((DatPersonaRecord *)(u8 *)slotp)->id != cur) {
                j++;
            }
        }
        res = (s32)shdPersonaTaskCreate(*(s32 *)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->rosterTask, 0x12, 2, 5, 5);
        *(s32 *)&((BtlShuffleResultRoster *)state)->display = res;
        ((BtlShuffleResultRoster *)state)->count = j;
        ((BtlShuffleResultRoster *)state)->phase = 1;
        ((BtlShuffleResultRoster *)state)->unk10 = 0;
        ((BtlShuffleResultRoster *)state)->mode = 1;
        /* fallthrough */
    case 1:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            ((BtlShuffleResultRoster *)state)->phase = 2;
            {
                s32 v;
                v = *(s32 *)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->cardTask;
                {
                    btlShuffleDrawCardActivate((u8 *)(v));
                    btlShuffleDrawCardSetDetail((u8 *)(v), 4);
                }
                btlShuffleDrawViewSetActive((u8 *)(*(s32 *)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->viewTask));
            }
        }
        break;
    case 2:
        if (((BtlShuffleResultRoster *)state)->mode == 0) {
            if (D_008C024E[0] & 0x40) {
                u8 *txt;
                /* measured: typed roster-slot indexing changes the offset-first address operands at each retained site. */
                txt = datPersonaGetRow(((DatPersonaRecord *)((u8 **)(state + 0x4C))[sum])->id);
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                ((BtlShuffleResultRoster *)state)->phase = 5;
                sdkSndStartStream(0, 4, 0, 1);
                sdkSndStartStream(0, 4, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                {
                    u8 **selected = (u8 **)(state + 0x4C) + sum;
                    /* measured: these display-pointer reloads change allocation when expressed through the roster member. */
                    u8 *display = *(u8 **)(state + 0x18);
                    s32 displayMode = 1;
                    shdPersonaSetDisplayState(display, displayMode, (u32)*selected, 0);
                }
                shdPersonaStartSlideIn((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
                ((BtlShuffleResultRoster *)state)->phase = 3;
            } else {
                sdkListStateConfigure((u8 *)(buf), 0xC, ((BtlShuffleResultRoster *)state)->count, row, scroll);
                sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(buf) != 0) {
                    ((BtlShuffleResultRoster *)state)->row = ((BtlShuffleResultCursor *)buf)->row;
                    ((BtlShuffleResultRoster *)state)->scroll = ((BtlShuffleResultCursor *)buf)->scroll;
                    sdkSndStartStream(0, 4, 0, 0);
                }
            }
        }
        break;
    case 3:
        if (D_008C024E[0] & 0x40) {
            shdPersonaBeginClose((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
            {
                u8 *txt;
                txt = datPersonaGetRow(((DatPersonaRecord *)((u8 **)(state + 0x4C))[((BtlShuffleResultRoster *)state)->row + ((BtlShuffleResultRoster *)state)->scroll])->id);
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                ((BtlShuffleResultRoster *)state)->phase = 5;
                sdkSndStartStream(0, 4, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            shdPersonaBeginClose((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
            ((BtlShuffleResultRoster *)state)->phase = 2;
            sdkSndStartStream(0, 4, 0, 4);
        } else if (D_008C024E[0] & 0x80) {
            shdPersonaBeginSelection((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
            ((BtlShuffleResultRoster *)state)->phase = 4;
        } else {
            sdkListStateConfigure((u8 *)(buf), 0xC, ((BtlShuffleResultRoster *)state)->count, row, scroll);
            sdkListStateSetPrimaryMasks(buf, 8, 4, 0, 0);
            sdkListStateSetActive(buf, 0);
            res = sdkListStateHandleInput(buf);
            if (res > 0) {
                ((BtlShuffleResultRoster *)state)->row = ((BtlShuffleResultCursor *)buf)->row;
                ((BtlShuffleResultRoster *)state)->scroll = ((BtlShuffleResultCursor *)buf)->scroll;
                idx = ((BtlShuffleResultRoster *)state)->row + ((BtlShuffleResultRoster *)state)->scroll;
                if (res == 2) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = ((BtlShuffleResultRoster *)state)->display;
                        s32 displayMode = 1;
                        shdPersonaBeginDisplayAndEndSelection(display, displayMode, (s32)*selected, 0);
                    }
                } else if (res == 1) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = ((BtlShuffleResultRoster *)state)->display;
                        s32 displayMode = 1;
                        shdPersonaBeginDisplay(display, displayMode, (s32)*selected, 0);
                    }
                }
            }
        }
        break;
    case 4:
        if ((D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x20)) {
            shdPersonaEndSelection((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display), 1);
            ((BtlShuffleResultRoster *)state)->phase = 3;
        } else if (D_008C024E[0] & 0x40) {
            shdPersonaBeginClose((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
            {
                u8 *txt;
                txt = datPersonaGetRow(((DatPersonaRecord *)((u8 **)(state + 0x4C))[((BtlShuffleResultRoster *)state)->row + ((BtlShuffleResultRoster *)state)->scroll])->id);
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                ((BtlShuffleResultRoster *)state)->phase = 5;
                sdkSndStartStream(0, 4, 0, 1);
            }
        } else {
            sdkListStateConfigure((u8 *)(buf), 0xC, ((BtlShuffleResultRoster *)state)->count, row, scroll);
            sdkListStateSetPrimaryMasks(buf, 8, 4, 0, 0);
            sdkListStateSetActive(buf, 0);
            res = sdkListStateHandleInput(buf);
            if (res > 0) {
                ((BtlShuffleResultRoster *)state)->row = ((BtlShuffleResultCursor *)buf)->row;
                ((BtlShuffleResultRoster *)state)->scroll = ((BtlShuffleResultCursor *)buf)->scroll;
                idx = ((BtlShuffleResultRoster *)state)->row + ((BtlShuffleResultRoster *)state)->scroll;
                if (res == 2) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = ((BtlShuffleResultRoster *)state)->display;
                        s32 displayMode = 1;
                        shdPersonaBeginDisplayAndEndSelection(display, displayMode, (s32)*selected, 0);
                    }
                } else if (res == 1) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = ((BtlShuffleResultRoster *)state)->display;
                        s32 displayMode = 1;
                        shdPersonaBeginDisplay(display, displayMode, (s32)*selected, 0);
                    }
                }
                ((BtlShuffleResultRoster *)state)->phase = 3;
            } else {
                shdPersonaStepSelectionCursor((u8 *)(*(s32 *)&((BtlShuffleResultRoster *)state)->display));
            }
        }
        break;
    case 5:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            switch (nmMesWindowCurrentAnimFlag()) {
            case 0:
                shdPersonaFinishPhase((u8 *)(*(s32 *)(state + 0x18)));
                *(s32 *)&((BtlShuffleResultRoster *)state)->display = 0;
                btlShuffleDrawCardEndDetail((u8 *)(*(s32 *)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->cardTask));
                btlShuffleDrawViewClearActive((u8 *)(*(s32 *)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->viewTask));
                {
                    u8 **slot;
                    u8 *txt;
                    slot = &((u8 **)(state + 0x4C))[sum];
                    txt = datPersonaGetRow(((DatPersonaRecord *)*slot)->id);
                    nmMesWindowSetCurrentString(0, txt);
                    nmMesWindowShowCurrentRecord(6);
                    ((BtlShuffleResultRoster *)state)->phase = 6;
                    if (sum != 0) {
                        datPersonaRemoveRosterMemberById(((DatPersonaRecord *)*slot)->id);
                        datPersonaTryAddRosterMember(((BtlShuffleResultWork *)work)->personaId);
                    }
                }
                break;
            case 1:
                nmMesWindowCloseCurrent(1);
                ((BtlShuffleResultRoster *)state)->phase = 2;
                break;
            }
        }
        break;
    case 6:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            return 1;
        }
        break;
    default:
        kAssertFail(D_0064EC70, 0x3F4);
        break;
    }
    return 0;
}

#pragma pop

/* Wait for the result message, then route to the bonus or ordinary completion phase. */
// FUN_003816E0
s32 btlShuffleResultInit(u8 *work) {
    u8 *p = work + 0x18;
    switch (((ShuffleResultState *)(work + 0x18))->phase) {
    case 0:
        *(s32 *)p = 1;
        /* fallthrough */
    case 1:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (((BtlShuffleResultWork *)work)->flags & 2) {
                memset(work + 0x18, 0, 0xC);
                ((BtlShuffleResultWork *)work)->phase = 4;
            } else {
                nmMesWindowShowCurrentRecord(8);
                *(s32 *)p = 2;
            }
        }
        break;
    case 2:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (((BtlShuffleResultWork *)work)->flags & 1) {
                memset(p, 0, 0x1C);
                ((BtlShuffleResultWork *)work)->phase = 1;
                nmMesWindowShowCurrentRecord(0xB);
            } else {
                return 1;
            }
        }
        break;
    }
    return 0;
}

/* Two levers, both recorded as impossible by the previous note: the counter
   store lands before the compare mask because the compound assignment's VALUE
   is used (see the measured comment at the site), and the single `return 0`
   after the switch gives retail's one shared zero-return block placed last,
   with the case bodies laid out in ascending declaration order. */
/* Play the delayed result cue and clear non-selected cards before the closing message. */
// FUN_00381830
s32 btlShuffleResultLayout(u8 *work)
{
    s32 *state = (s32 *)(work + 0x18);
    s32 count;
    s32 i;
    u8 *base;
    s32 bumped;

    switch (((ShuffleResultState *)(work + 0x18))->phase) {
    case 0:
        *state = 1;
        /* fallthrough */
    case 1:
        /* measured: the initial raw frame load preserves allocation; the later increment can use the typed member. */
        if ((s32)*(u16 *)(work + 6) < 0xA) {
            /* measured: the compound assignment's VALUE keeps the incremented
               counter in one register, so b210 emits the sh before the andi
               exactly as retail does; a separate `cnt = cnt + 1; store;` pair
               masks first. */
            bumped = (((BtlShuffleResultWork *)work)->frames += 1);
            if ((bumped & 0xFFFF) == 0xA) {
                sdkSndStartStream(1, 1, 5, 0xC);
            }
        }
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (((BtlShuffleResultWork *)work)->flags & 2) {
                memset(work + 0x18, 0, 0xC);
                ((BtlShuffleResultWork *)work)->phase = 4;
            } else {
                base = ((BtlShuffleResultWork *)work)->context;
                count = btlShuffleDrawTableLookup(((BtlShuffleContext *)base)->cardCount,
                                      ((BtlShuffleContext *)base)->pattern);
                for (i = 0; i < count; i++) {
                    if (i != ((BtlShuffleContext *)base)->revealCard) {
                        /* Card flags share the variant motion prefix; its union layout is not exposed by the partial pose type. */
                        if (*(u16 *)(base + (i * 0xE8) + 0x1D6A0) & 2) {
                            kAssertFail(D_0064EC70, 0x8C);
                        }
                        btlShuffleCardUpdateState(base + (i * 0xFB0));
                    }
                }
                nmMesWindowShowCurrentRecord(0xA);
                *state = 2;
            }
        }
        break;
    case 2:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            btlShuffleResetSlot((u8 *)btlShuffleGetParentWork(*(void **)&((BtlShuffleContext *)((BtlShuffleResultWork *)work)->context)->parentTask));
            return 1;
        }
        break;
    }
    return 0;
}



static inline void shuffleResultOpen(u8 *context)
{
    f32 screen[2];
    BtlShuffleVec3 position;
    ((BtlShuffleTaskWork *)(context - 0x70))->fieldOfView = 10.0f;
    btlShuffleDrawViewReset(context);
    screen[0] = 316.0f;
    screen[1] = 211.0f;
    /* measured: the remaining context access changes allocation or CSE when typed alone; neighboring safe accesses are typed. */
    btlShuffleCardScaleVec(context + *(s32 *)(context + 0x1F308) * 0xFB0, &screen[0], 160.0f, (f32 *)&position);
    btlShuffleDrawMoveCard(context, ((BtlShuffleContext *)context)->revealCard, 0.0f, 0.0f, (f32 *)&position, (f32 *)&position);
    btlShuffleEffUpdate(*(u8 **)(context + 0x1F29C));
    btlShuffleEffEnd(*(u8 **)(context + 0x1F29C));
    btlShuffleDrawViewStartRun(((BtlShuffleContext *)context)->viewTask);
    btlShuffleEffInitTrail(((BtlShuffleContext *)context)->trailTask, 6);

}

static inline s32 shuffleResultRoll(u8 kind)
{
    u8 reversedChance;
    s32 columnValue;
    u32 randomBits;
    f32 randomValue;
    if (datGetFlag(0x1437) == 0) {
        datSetFlag(0x1437, 1);
        return 1;
    }
    if (datGetFlag(0x1403) != 0 && datGetFlag(0x140F) != 0) {
        reversedChance = 0x3C;
    } else {
        columnValue = FldStepBandFlagSet();
        reversedChance = *(D_0064E72E[kind] + (u8)(columnValue ? 1 : 0));
    }
    randomBits = RpRandom() & 0xFFF;
    randomValue = (f32)randomBits;
    if (100.0f * (randomValue / 4096.0f) < (f32)reversedChance) {
        return 0;
    }
    return 1;
}

static inline void shuffleResultDescribe(u8 *work)
{
    u8 text[64];
    s32 kind;
    ShuffleResultState *state = (ShuffleResultState *)(work + 0x18);
    kind = ((BtlShuffleResultWork *)work)->bonusKind;
    if (kind == 1) {
        kind = state->resultCard;
    }
    if (state->isUpright != 0) {
        strcpy((char *)text, iGpffffa9E0);
    } else {
        strcpy((char *)text, iGpffffa9E4);
    }
    nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(kind));
    nmMesWindowSetCurrentString(1, text);
    nmMesWindowShowCurrentRecord(0xE);

}

static inline s32 shuffleResultReverse(u8 *work)
{
    ShuffleResultState *state = (ShuffleResultState *)(work + 0x18);
    u8 text[64];
    if (datGetFlag(0x1403) != 0 && datGetFlag(0x140E) != 0 && state->isUpright == 0) {
        state->isUpright = 1;
        strcpy((char *)text, iGpffffa9E0);
        nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(6));
        nmMesWindowSetCurrentString(1, text);
        nmMesWindowShowCurrentRecord(0xF);
        return 1;
    }
    return 0;
}

static inline void shuffleResultDescribePacked(s32 packed)
{
    u8 text[64];
    if ((packed & 0xFFFF) != 0) {
        strcpy((char *)text, iGpffffa9E0);
    } else {
        strcpy((char *)text, iGpffffa9E4);
    }
    nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(((packed & 0xFFFF0000) >> 16) & 0xFF));
    nmMesWindowSetCurrentString(1, text);
    nmMesWindowShowCurrentRecord(0x10);

}

static inline s32 shuffleResultPersonaState(u8 *work)
{
    s32 persona;
    u16 capacity;
    u16 count;
    s32 result;
    persona = (u16)((BtlShuffleResultWork *)work)->personaId;
    capacity = datPersonaCountValidMembers();
    count = (u16)datPersonaRosterCapacity();
    result = (s32)datPersonaFindRosterRecordById((u16)persona);
    if (result != 0) {
        nmMesWindowShowCurrentRecord(2);
        result = 6;
    } else {
        if (capacity == count) {
            memset(work + 0x18, 0, 0x7C);
            nmMesWindowSetCurrentString(0, datPersonaGetRow((u16)persona));
            nmMesWindowShowCurrentRecord(3);
            result = 7;
        } else {
            datPersonaAddRosterMember((u16)persona);
            nmMesWindowSetCurrentString(0, datPersonaGetRow((u16)persona));
            nmMesWindowShowCurrentRecord(1);
            result = 5;
        }
    }
    return result;
}

/* Run the bonus-card reveal, upright/reversed roll and reward-message state machine. */
// FUN_00381A70
s32 btlShuffleResultRun(u8 *work)
{
    /* Capture the context and payload bases once. This local view scalarizes
       to the retail saved-pointer lifetimes; it is not an external layout. */
    struct {
        u8 *context;
        ShuffleResultState *state;
    } view;

    BtlShuffleVec3 rotation;
    s32 result;
    s32 override;
    u32 randomBits;
    f32 randomValue;
    s32 upright;

    view.context = *(u8 **)work;
    view.state = (ShuffleResultState *)(work + 0x18);
    switch (view.state->phase) {
    case 0:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            view.state->phase = 1;
        }
        break;
    case 1:
        shuffleResultOpen(view.context);
        view.state->phase = 2;
    case 2:
        result = btlShuffleDrawFlagA((u8 *)*(s32 *)&((BtlShuffleContext *)view.context)->frontCardTask);
        if (result != 0) {
            result = btlShuffleDrawViewIsRunReady(((BtlShuffleContext *)view.context)->viewTask);
            if (result != 0) {
                btlShuffleDrawSetPose(view.context, ((BtlShuffleContext *)view.context)->revealCard, 0, 0x14);
                /* measured: the remaining context access changes allocation or CSE when typed alone; neighboring safe accesses are typed. */
                *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 8);
                view.state->phase = 3;
                goto waitForCard;
            }
        }
        break;
    case 3:
    waitForCard:
        result = btlShuffleDrawStateC(view.context + ((BtlShuffleContext *)view.context)->revealCard * 0xE8 + 0x1D6A0);
        if (result != 0) {
            *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags & 0xFFFB);
            result = datGetFlag(0x1434);
            if (result == 0) {
                nmMesWindowResetCurrent();
                btlShuffleSeqClearA(view.context, 4);
                view.state->phase = 0x13;
            } else {
                view.state->phase = 4;
            }
        }
        break;
    case 4:
        nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(((BtlShuffleResultWork *)work)->bonusKind));
        nmMesWindowShowCurrentRecord(0xC);
        nmMesWindowSetCurrentParam(0xD);
        nmMesWindowSetCurrentFlag(0);
        nmMesWindowRequestRefresh();
        view.state->phase = 5;
        break;
    case 5:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            result = nmMesWindowCurrentAnimFlag();
            switch (result) {
            case 0:
                view.state->timer = 0;
                switch (*(u8 *)(work + 0x12)) {
                case 1:

                    view.state->phase = 10;
                    view.state->spinsRemaining = 0;
                    upright = shuffleResultRoll(((BtlShuffleResultWork *)work)->bonusKind);
                    view.state->isUpright = upright;
                    randomBits = RpRandom() & 0xFFF;
                    randomValue = (f32)randomBits;
                    view.state->resultCard = (u8)(1.0f + (1.0f + 20.0f * (randomValue / 4096.0f)));
                    *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 0x20);
                    *(s32 *)&((BtlShuffleContext *)view.context)->alternateCardTask = btlShuffleDrawSpawn(*(u8 * *)&((BtlShuffleContext *)view.context)->parentTask, (view.state->resultCard - 1) & 0xFF);
                    break;
                default:

                    view.state->phase = 7;
                    *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 0x10);
                    randomBits = RpRandom() & 0xFFF;
                    randomValue = (f32)randomBits;
                    view.state->spinsRemaining = ((s32)(3.0f * (randomValue / 4096.0f)) + 5) * 2;
                    upright = shuffleResultRoll(((BtlShuffleResultWork *)work)->bonusKind);
                    view.state->isUpright = upright;
                    if (upright == 0) {
                        view.state->spinsRemaining = view.state->spinsRemaining + 1;
                    }
                    break;
                }
                break;
            case 1:
                return 1;
            case 2:
                nmMesWindowShowCurrentRecord((((BtlShuffleResultWork *)work)->bonusKind - 1) * 4 + 0x15);
                view.state->phase = 6;
                break;
            }
        }
        break;
    case 6:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            nmMesWindowShowCurrentRecord(0xC);
            nmMesWindowSetCurrentParam(0xD);
            view.state->phase = 5;
        }
        break;
    case 7:
        if (((view.state->timer += 1) & 0xFFFF) >= 10) {
            view.state->step = 1;
            view.state->phase = 8;
            btlShuffleDrawViewExpandRun(((BtlShuffleContext *)view.context)->viewTask);
            goto advanceSpin;
        }
        break;
    case 8:
    advanceSpin:
        result = btlShuffleDrawStateC(view.context + *(s32 *)(view.context + 0x1F308) * 0xE8 + 0x1D6A0);
        if (result != 0) {
            rotation = D_0064EC88;
            btlShuffleDrawSetCurve(view.context, ((BtlShuffleContext *)view.context)->revealCard, 0, view.state->step, &rotation, 0.0f, 180.0f);
            if (view.state->step < 10) {
                view.state->step = (u16)(view.state->step + 1);
            }
            result = view.state->spinsRemaining;
            view.state->spinsRemaining = result - 1;
            if (result - 1 < 1) {
                view.state->phase = 9;
            }
        }
        break;
    case 9:
        result = btlShuffleDrawStateC(view.context + ((BtlShuffleContext *)view.context)->revealCard * 0xE8 + 0x1D6A0);
        if (result != 0) {
            if (*(u16 *)(view.context + 0x1F2F4) & 0x10) {
                *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) & 0xFFEF);
                *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 0x100);
                ((BtlShuffleContext *)view.context)->pulse = 0;
            }
            if (view.state->isUpright != 0) {
                sdkSndStartStream(1, 3, 2, 1);
            } else {
                sdkSndStartStream(1, 3, 2, 2);
            }
            shuffleResultDescribe(work);
            view.state->phase = 0xD;
        }
        break;
    case 10:
        if (((view.state->timer += 1) & 0xFFFF) >= 10) {
            view.state->step = 5;
            view.state->phase = 0xB;
            btlShuffleDrawViewExpandRun(*(u8 **)(view.context + 0x1F294));
            btlShuffleDrawViewStartDesaturation(*(u8 **)(view.context + 0x1F294));
            btlShuffleDrawViewStartReveal(((BtlShuffleContext *)view.context)->viewTask);
        }
        break;
    case 11:
        if (((view.state->timer += 1) & 0xFFFF) >= 0x3C) {
            result = btlShuffleDrawFlagA((u8 *)*(s32 *)&((BtlShuffleContext *)view.context)->alternateCardTask);
            if (result != 0) {
                view.state->phase = 0xC;
                btlShuffleDrawViewEndReveal(((BtlShuffleContext *)view.context)->viewTask);
                goto finishReveal;
            }
        }
        break;
    case 12:
    finishReveal:
        result = btlShuffleDrawViewIsRevealFinished(((BtlShuffleContext *)view.context)->viewTask);
        if (result != 0) {
            if (view.state->isUpright == 0) {
                *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 0x80);
            }
            *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags | 0x40);
            if (*(void **)(view.context + 0x1F2A0) != 0) {
                kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(view.context + 0x1F2A0));
                *(s32 *)&((BtlShuffleContext *)view.context)->frontCardTask = 0;
            }
            if (view.state->isUpright != 0) {
                sdkSndStartStream(1, 3, 2, 1);
            } else {
                sdkSndStartStream(1, 3, 2, 2);
            }
            result = (view.state->isUpright != 0 ? 1 : 2) + 0x15;
            nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(view.state->resultCard));
            nmMesWindowShowCurrentRecord(result);
            view.state->phase = 0xD;
        }
        break;
    case 13:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            override = shuffleResultReverse(work);
            view.state->uprightOverride = override;
            if (override != 0) {
                view.state->phase = 0x10;
            } else {
                result = btlShuffleShowRosterMessage(work);
                if (result == 0) {
                    return 1;
                }
                view.state->phase = 0xE;
            }
        }
        break;
    case 14:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            result = view.state->secondaryResult;
            if (result != 0) {
                shuffleResultDescribePacked(result);
                view.state->phase = 0xF;
            } else {
                return 1;
            }
        }
        break;
    case 15:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            return 1;
        }
        break;
    case 16:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (view.state->uprightOverride == 1) {
                nmMesWindowShowCurrentRecord(0x11);
                view.state->phase = 0x11;
            } else {
                btlShuffleShowRosterMessage(work);
                view.state->phase = 8;
            }
        }
        break;
    case 17:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            return 1;
        }
        break;
    case 18:
        result = btlShuffleDrawStateC(view.context + ((BtlShuffleContext *)view.context)->revealCard * 0xE8 + 0x1D6A0);
        if (result != 0) {
            *(u16 *)(view.context + 0x1F2F4) = (u16)(((BtlShuffleContext *)view.context)->flags & 0xFFF7);
            if (*(void **)(view.context + 0x1F2A0) != 0) {
                kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(view.context + 0x1F2A0));
                *(s32 *)&((BtlShuffleContext *)view.context)->frontCardTask = 0;
            }
            result = shuffleResultPersonaState(work);
            ((BtlShuffleResultWork *)work)->phase = result;
        }
        break;
    case 19:
        result = btlShuffleSeqFlag(view.context);
        if (result != 0) {
            datSetFlag(0x1434, 1);
            /* measured: a typed message-resource load changes the argument-register choice by one instruction byte. */
            nmMesWindowOpenCurrent((u8 *)(*(s32 *)(view.context + 0x1F2DC)));
            view.state->phase = 4;
        }
        break;
    }
    return 0;
}


/* Present the special result menu and return when its card and view transitions finish. */
// FUN_00382BA0
s32 btlShuffleResultMenu(u8 *work) {
    f32 pos[2];
    struct {
        u8 pad[8];
        u8 out[16];
    } outBuf;
    s32 stage;
    u8 *phaseState;
    u8 *context;

    phaseState = work + 0x18;
    context = ((BtlShuffleResultWork *)work)->context;
    stage = ((BtlShuffleResultMenu *)phaseState)->phase;
    switch (stage) {
    case 0:
        ((BtlShuffleTaskWork *)(context - 0x70))->fieldOfView = 10.0f;
        btlShuffleDrawViewReset(context);
        pos[0] = 316.0f;
        pos[1] = 211.0f;
        /* measured: the remaining context access changes allocation or CSE when typed alone; neighboring safe accesses are typed. */
        btlShuffleCardScaleVec(context + *(s32 *)(context + 0x1F308) * 0xFB0, &pos[0], 160.0f, (f32 *)&outBuf.out[0]);
        btlShuffleDrawMoveCard(context, ((BtlShuffleContext *)context)->revealCard, 0.0f, 0.0f, (f32 *)&outBuf.out[0], (f32 *)&outBuf.out[0]);
        btlShuffleEffUpdate(*(u8 **)(context + 0x1F29C));
        btlShuffleEffEnd(*(u8 **)(context + 0x1F29C));
        btlShuffleDrawViewSetMenuBusy(((BtlShuffleContext *)context)->viewTask);
        btlShuffleEffInitTrail(((BtlShuffleContext *)context)->trailTask, 7);
        ((BtlShuffleContext *)context)->unk1F30C = 1;
        ((BtlShuffleResultMenu *)phaseState)->phase = 1;
    case 1:
        if (((((BtlShuffleResultMenu *)phaseState)->frames += 1) & 0xFFFF) >= 0xA && btlShuffleDrawViewIsMenuReady(((BtlShuffleContext *)context)->viewTask) != 0) {
            nmMesWindowShowCurrentRecord(0x12);
            ((BtlShuffleResultMenu *)phaseState)->phase = 2;
        case 2:
            nmMesWindowStepCurrent(1);
            if (nmMesWindowCurrentOpenState() == 0) {
                nmMesWindowCloseCurrent(1);
                ((BtlShuffleResultMenu *)phaseState)->phase = 3;
                btlShuffleSeqUpdateMode(context, ((BtlShuffleContext *)context)->revealCard, 0xA, 1);
                btlShuffleDrawViewEndMenu(((BtlShuffleContext *)context)->viewTask);
                btlShuffleEffSetup(((BtlShuffleContext *)context)->trailTask, 7);
                btlShuffleDrawCardEndBands(((BtlShuffleContext *)context)->cardTask);
            }
        }
        goto block_17;
    case 3:
        if (btlShuffleDrawStateC(context + ((BtlShuffleContext *)context)->revealCard * 0xE8 + 0x1D6A0) != 0) {
            *(u16 *)(context + 0x1F2F4) = (u16)(((BtlShuffleContext *)context)->flags & 0xFFFB);
            ((BtlShuffleResultMenu *)phaseState)->phase = 4;
        case 4:
            if (btlShuffleDrawViewIsMenuIdle(((BtlShuffleContext *)context)->viewTask) != 0) {
                ((BtlShuffleResultMenu *)phaseState)->result = 2;
                return 1;
            }
            goto block_17;
        }
        goto block_17;
    default:
        kAssertFail(&D_0064EC70, 0x64E);
        goto block_17;
    }
block_17:
    return 0;
}


/* Column (0/1) of the two-column bonus tables D_0064E6E0 and D_0064E700. */
static inline u8 shuffleBonusColumn(void)
{
    return FldStepBandFlagSet() ? 1 : 0;
}

/* Roll for the shuffle bonus: nonzero when enabled and a 0-99 roll falls
   under the table threshold for the current bonus level and rate. */
static inline s32 shuffleBonusRoll(u8 *work, s32 rate)
{
    u8 flag;
    s32 thresh;
    s32 chance;

    if (datGetFlag(0x1430) == 0 || datGetFlag(0x11) == 0) {
        return 0;
    }
    flag = shuffleBonusColumn();
    if (((BtlShuffleResultWork *)work)->bonusKind == 0) {
        thresh = (u8)(D_0064E6E0[0][flag] + iGpffffa9B8[rate]);
    } else {
        thresh = (u8)(D_0064E6E0[(u8)cmmCommunityValueForArcana(((BtlShuffleResultWork *)work)->bonusKind)][flag] + iGpffffa9B8[rate]);
    }
    chance = (u8)(100.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
    if ((u8)chance < (u8)thresh) {
        return 1;
    }
    return 0;
}

/* Pick the bonus level (0-based) from the cumulative D_0064E700 weights. */
static inline s32 shuffleBonusPick(void)
{
    u8 flag;
    s32 chance;
    s32 sum;
    s32 i;
    u8 *weights;

    flag = shuffleBonusColumn();
    chance = (u8)(100.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
    sum = 0;
    i = 0;
    weights = &D_0064E700[0][flag];
    for (; i < 0x15; i++) {
        sum = (u8)(sum + weights[i * 2]);
        if (chance < sum) {
            break;
        }
    }
    return i;
}

/* Initialize the selected card reward, roll any bonus and dismiss the other cards. */
// FUN_00382EA0
s32 btlShuffleResultBonus(u8 *work, u8 *parentTask, s32 cardKind, u16 personaId, s32 rate)
{
    u8 *unit;
    s32 count;
    s32 i;
    u8 *u;

    unit = btlShuffleGetDrawContext(parentTask);
    *(u8 **)work = unit;
    /* measured: typing this initial kind store grows Bonus from 2172 to 2184 bytes. */
    *(s32 *)(work + 0xC) = cardKind;
    ((BtlShuffleResultWork *)work)->personaId = personaId;
    /* measured: a typed message-resource load changes the argument-register choice by one instruction byte. */
    nmMesWindowOpenCurrent((u8 *)(*(s32 *)(unit + 0x1F2DC)));
    switch (((BtlShuffleResultWork *)work)->cardKind) {
    case -1:
        nmMesWindowShowCurrentRecord(8);
        ((BtlShuffleResultWork *)work)->phase = 8;
        return 0;
    case 0:
        if (shuffleBonusRoll(work, rate) != 0) {
            ((BtlShuffleResultWork *)work)->bonusKind = shuffleBonusPick() + 1;
            ((BtlShuffleResultWork *)work)->flags |= 1;
            *(s32 *)&((BtlShuffleContext *)unit)->frontCardTask = btlShuffleDrawSpawn(*(u8 * *)&((BtlShuffleContext *)unit)->parentTask, (u8)(((BtlShuffleResultWork *)work)->bonusKind - 1));
        }
        ((BtlShuffleResultWork *)work)->frames = 0;
        nmMesWindowSetCurrentString(0, datPersonaGetRow(personaId));
        nmMesWindowShowCurrentRecord(0);
        btlShuffleDrawCardActivateRing(((BtlShuffleContext *)unit)->cardTask);
        ((BtlShuffleResultWork *)work)->phase = 0;
        break;
    case 2:
        if (shuffleBonusRoll(work, rate) != 0) {
            ((BtlShuffleResultWork *)work)->bonusKind = shuffleBonusPick() + 1;
            ((BtlShuffleResultWork *)work)->flags |= 1;
            *(s32 *)&((BtlShuffleContext *)unit)->frontCardTask = btlShuffleDrawSpawn(*(u8 * *)&((BtlShuffleContext *)unit)->parentTask, (u8)(((BtlShuffleResultWork *)work)->bonusKind - 1));
        } else if (btlShuffleRollChance(work) != 0) {
            ((BtlShuffleResultWork *)work)->flags |= 2;
        }
        nmMesWindowShowCurrentRecord(7);
        btlShuffleDrawCardActivateRing(((BtlShuffleContext *)unit)->cardTask);
        ((BtlShuffleResultWork *)work)->phase = 2;
        break;
    case 3:
        if (btlShuffleRollChance(work) != 0) {
            ((BtlShuffleResultWork *)work)->flags |= 2;
        }
        ((BtlShuffleResultWork *)work)->frames = 0;
        nmMesWindowShowCurrentRecord(9);
        btlShuffleDrawCardActivateRing(((BtlShuffleContext *)unit)->cardTask);
        ((BtlShuffleResultWork *)work)->phase = 3;
        break;
    default:
        kAssertFail(D_0064EC70, 0x6C7);
        break;
    }
    if ((((BtlShuffleResultWork *)work)->flags & 2) == 0) {
        u = *(u8 **)work;
        count = btlShuffleDrawTableLookup(((BtlShuffleContext *)u)->cardCount, ((BtlShuffleContext *)u)->pattern);
        for (i = 0; i < count; i++) {
            if (i != ((BtlShuffleContext *)u)->revealCard) {
                /* Card flags share the variant motion prefix; its union layout is not exposed by the partial pose type. */
                if (*(u16 *)(u + i * 0xE8 + 0x1D6A0) & 2) {
                    kAssertFail(D_0064EC70, 0x8C);
                }
                btlShuffleCardUpdateState(u + i * 0xFB0);
            }
        }
    }
    return 0;
}

/* Dispatch result phases until the roster, bonus and message work completes. */
// FUN_00383720
s32 btlShuffleResultMain(u8 *work) {
    s32 btlShuffleResultRun(u8 *work);
    s32 btlShuffleResultInit(u8 *work);
    s32 btlShuffleResultLayout(u8 *work);
    s32 btlShuffleResultMenu(u8 *work);
    s32 btlShuffleResultOpen(u8 *work);
    s32 flag5;
    s32 flag6;
    s32 flag8;
    u16 count;
    u32 stage;

    /* measured: typing the dispatch load grows Main to 804 bytes; its phase stores remain typed. */
    stage = (u32)*(s32 *)(work + 8);
    switch (stage) {
    case 0:
        /* measured: the initial raw frame load preserves allocation; the later increment can use the typed member. */
        count = *(u16 *)(work + 6);
        if ((s32)count < 0xA) {
            if (((((BtlShuffleResultWork *)work)->frames += 1) & 0xFFFF) == 0xA) {
                sdkSndStartStream(1, 1, 5, 0xA);
            }
        }
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            ((BtlShuffleResultWork *)work)->phase = btlShuffleAddRosterMember(work, ((BtlShuffleResultWork *)work)->personaId);
        }
        goto block_39;
    case 1:
        if (btlShuffleResultRun(work) != 0) return 1;
        goto block_39;
    case 2:
        if (btlShuffleResultInit(work) != 0) return 1;
        goto block_39;
    case 3:
        if (btlShuffleResultLayout(work) != 0) return 1;
        goto block_39;
    case 4:
        if (btlShuffleResultMenu(work) != 0) return ((BtlShuffleResultMenu *)(work + 0x18))->result;
        goto block_39;
    case 5:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            flag5 = 1;
        } else {
            flag5 = 0;
        }
        if (flag5 != 0) {
            if (((BtlShuffleResultWork *)work)->flags & 1) {
                memset(work + 0x18, 0, 0x1C);
                ((BtlShuffleResultWork *)work)->phase = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 6:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            flag6 = 1;
        } else {
            flag6 = 0;
        }
        if (flag6 != 0) {
            if (((BtlShuffleResultWork *)work)->flags & 1) {
                memset(work + 0x18, 0, 0x1C);
                ((BtlShuffleResultWork *)work)->phase = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 7:
        if (btlShuffleResultOpen(work) != 0) {
            if (((BtlShuffleResultWork *)work)->flags & 1) {
                memset(work + 0x18, 0, 0x1C);
                ((BtlShuffleResultWork *)work)->phase = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 8:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            flag8 = 1;
        } else {
            flag8 = 0;
        }
        if (flag8 != 0) return 1;
        goto block_39;
    default:
        kAssertFail(&D_0064EC70, 0x72B);
        goto block_39;
    }
block_39:
    return 0;
}

/* Advance the result task until completion or a cancellation flag requests destruction. */
// FUN_00383A40
s32 btlShuffleResultEnd(u8 *task) {
    u8 *state;

    state = ((struct KwlnTask *)task)->work;
    if (((BtlShuffleResultWork *)state)->flags & 4) {
        return -1;
    }
    /* measured: the result test must retain its byte-pointer alias; the result store can remain typed. */
    if (*(s32 *)(state + 0x14) == 0) {
        ((BtlShuffleResultWork *)state)->result = btlShuffleResultMain(state);
    }
    return 0;
}

/* Reset the shared message window and free this result task allocation. */
// FUN_00383AA0
void btlShuffleResultFree(u8 *task) {
    u8 *work = ((struct KwlnTask *)task)->work;

    nmMesWindowResetCurrent();
    jtbl_008873EC[0](work);
}

/* Create a result child task and initialize its card reward and bonus state. */
// FUN_00383AE0
s32 btlShuffleResultSpawn(u8 *parentTask, s32 cardKind, u16 personaId, s32 rate) {
    u8 *work;
    s32 ret;

    chkmemAllocSiteTag(&D_0064EC70, 0x757);
    work = D_008873F4[0](1, 0x94, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064EC70, 0x758);
    }
    ret = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064EB60), 0x12, 0, 0, btlShuffleResultEnd, btlShuffleResultFree, (u8 *)(work));
    if (ret == 0) {
        kAssertFail(&D_0064EC70, 0x762);
    }
    btlShuffleResultBonus(work, parentTask, cardKind, personaId, rate);
    return ret;
}
