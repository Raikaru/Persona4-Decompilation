#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "sdk_snd_internal.h"

s32 btlShuffleResultMain(u8 *arg0);
extern s32 func_002bb4e0(void);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_002bb7c0(s32 a);
extern s32 nmMesWindowCurrentOpenState(void);
extern u32 nmMesWindowCloseCurrent(int param_1);
extern s32 nmMesWindowShowCurrentRecord(s32 arg0);
extern void *memset(void *dst, s32 value, size_t size);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void kAssertFail(void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064EB60[];
extern u8 D_0064EC70[];

extern s32 btlShuffleResultBonus(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3);
extern s32 btlShuffleDrawTableLookup(s32 a, s32 b);
extern void btlShuffleCardUpdateState(u8 *arg0);
extern void *func_0036e900(void *arg0);
extern void btlShuffleResetSlot(u8 *arg0);
extern void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst);
extern void btlShuffleDrawMoveCard(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void btlShuffleDrawViewReset(u8 *a);
extern s32 btlShuffleDrawStateC(u8 *a);
extern void btlShuffleSeqUpdateMode(u8 *ctx, s32 a, u16 b, s32 c);
extern void func_00388d60(u8 *a);
extern s32 func_00388de0(u8 *a);
extern void func_00388e00(u8 *a);
extern s32 func_00388e20(u8 *a);
extern void func_0038d310(u8 *a);
extern void btlShuffleEffEnd(u8 *a);
extern void btlShuffleEffUpdate(u8 *a);
extern void btlShuffleEffInitTrail(u8 *a, s32 b);
extern void btlShuffleEffSetup(u8 *a, s32 b);
extern s32 func_00380d80(u8 *arg0, s32 arg1);
extern s32 btlShuffleResultOpen(u8 *arg0);
extern s32 btlShuffleResultRun(u8 *arg0);
extern s32 btlShuffleResultInit(u8 *arg0);
extern s32 btlShuffleResultLayout(u8 *arg0);
extern s32 btlShuffleResultMenu(u8 *arg0);
extern u16 *datPersonaRosterSlot(s16 a);
extern void datPersonaInitRecord(u8 *dst, u16 id);
extern s32 datPersonaRosterCapacity(void);
extern u16 datPersonaLeadPersonaId(void);
extern u8 *shdPersonaTaskCreate(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8 *datPersonaGetRow(u16 id);
extern void nmMesWindowSetCurrentString(s32 a, void *text);
extern s32 nmMesWindowSetCurrentParam(s32 arg0);
extern void nmMesWindowSetCurrentFlag(u8 param_1);
extern void nmMesWindowRequestRefresh(void);
extern s32 nmMesWindowCurrentAnimFlag(void);
extern void shdPersonaSetDisplayState(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
extern void shdPersonaStartSlideIn(u8 *arg0);
extern void shdPersonaBeginClose(u8 *arg0);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern void shdPersonaBeginDisplay(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern void shdPersonaBeginSelection(u8 *arg0);
extern void shdPersonaEndSelection(u8 *arg0, s32 arg1);
extern void shdPersonaStepSelectionCursor(u8 *arg0);
extern void shdPersonaFinishPhase(u8 *arg0);
extern void sdkListStateConfigure(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetSecondaryMasks(u8 *buf, s32 a, s32 b, s32 c, s32 d);
extern void sdkListStateSetPrimaryMasks(u8 *buf, s32 a, s32 b, s32 c, s32 d);
extern void sdkListStateSetActive(u8 *buf, s32 a);
extern s32 sdkListStateHandleInput(u8 *buf);
extern void btlShuffleDrawCardActivate(u8 *arg0);
extern void func_0038d0d0(u8 *arg0, s32 arg1);
extern void func_0038d0a0(u8 *arg0);
extern void func_00388d20(u8 *arg0);
extern void func_00388d40(u8 *arg0);
extern s32 datPersonaRemoveRosterMemberById(s32 arg0);
extern u8 *datPersonaTryAddRosterMember(u16 personaId);
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 a);
extern s32 cmmCommunityValueForArcana(s32 a);
extern s32 FldStepBandFlagSet(void);
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void *func_0036e910(void *a);
extern s32 btlShuffleDrawSpawn(u8 *parent, s32 cardIndex);
extern void func_0038d2a0(u8 *a);
extern u32 RpRandom(void);
extern s32 func_00380bd0(u8 *a);
extern u8 D_0064E6E0[][2];
extern u8 D_0064E700[][2];
extern u8 iGpffffa9B8[5]; /* per-rate bonus thresholds: 5, 5, 5, 10, 10 */
extern u8 D_0064E72E[][2];
extern BtlShuffleVec3 D_0064EC88;
extern const char *iGpffffa9E0; /* "upright" */
extern const char *iGpffffa9E4; /* "reversed" */
extern void btlShuffleDrawSetPose(u8 *a, s32 b, u16 c, u16 d);
extern s32 btlShuffleDrawFlagA(u8 *task);
extern s32 func_00388ec0(u8 *a);
extern void func_00388e40(u8 *a);
extern void func_00388ee0(u8 *a);
extern void func_00388f00(u8 *a);
extern void func_003892e0(u8 *a);
extern s32 func_00389330(u8 *a);
extern void func_00389350(u8 *a);
extern void btlShuffleSeqClearA(u8 *a, s32 b);
extern s32 btlShuffleSeqFlag(u8 *a);
extern s32 func_00380980(u8 *a);
extern u16 datPersonaCountValidMembers(void);
extern u16 *datPersonaFindRosterRecordById(s32 a);
extern u8 *datPersonaAddRosterMember(u16 personaId);
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
s32 btlShuffleResultOpen(u8 *arg0)
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

    state = arg0 + 0x18;
    scroll = *(s32 *)(arg0 + 0x20);
    row = *(s32 *)(arg0 + 0x1C);
    sum = row + scroll;
    switch (*(s32 *)state) {
    case 0:
        datPersonaInitRecord(state + 0x1C, *(u16 *)(arg0 + 0x10));
        *(u8 **)(state + 0x4C) = state + 0x1C;
        cnt = (u16)datPersonaRosterCapacity();
        cur = (u16)datPersonaLeadPersonaId();
        i = 0;
        j = 1;
        for (; i < cnt; i++) {
            dst = (u16 **)(state + j * 4 + 0x4C);
            slotp = datPersonaRosterSlot((s16)i);
            *dst = slotp;
            if (*(u16 *)((u8 *)slotp + 2) != cur) {
                j++;
            }
        }
        res = (s32)shdPersonaTaskCreate(*(s32 *)(*(u8 **)arg0 + 0x1F290), 0x12, 2, 5, 5);
        *(s32 *)(state + 0x18) = res;
        *(s32 *)(state + 0x0C) = j;
        *(s32 *)state = 1;
        *(s32 *)(state + 0x10) = 0;
        *(s32 *)(state + 0x14) = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            *(s32 *)state = 2;
            {
                s32 v;
                v = *(s32 *)(*(u8 **)arg0 + 0x1F298);
                {
                    btlShuffleDrawCardActivate((u8 *)(v));
                    func_0038d0d0((u8 *)(v), 4);
                }
                func_00388d20((u8 *)(*(s32 *)(*(u8 **)arg0 + 0x1F294)));
            }
        }
        break;
    case 2:
        if (*(s32 *)(state + 0x14) == 0) {
            if (D_008C024E[0] & 0x40) {
                u8 *txt;
                txt = datPersonaGetRow(*(u16 *)(((u8 **)(state + 0x4C))[sum] + 2));
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                *(s32 *)state = 5;
                sdkSndStartStream(0, 4, 0, 1);
                sdkSndStartStream(0, 4, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                {
                    u8 **selected = (u8 **)(state + 0x4C) + sum;
                    u8 *display = *(u8 **)(state + 0x18);
                    s32 displayMode = 1;
                    shdPersonaSetDisplayState(display, displayMode, (u32)*selected, 0);
                }
                shdPersonaStartSlideIn((u8 *)(*(s32 *)(state + 0x18)));
                *(s32 *)state = 3;
            } else {
                sdkListStateConfigure((u8 *)(buf), 0xC, *(s32 *)(state + 0x0C), row, scroll);
                sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(buf) != 0) {
                    *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                    *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                    sdkSndStartStream(0, 4, 0, 0);
                }
            }
        }
        break;
    case 3:
        if (D_008C024E[0] & 0x40) {
            shdPersonaBeginClose((u8 *)(*(s32 *)(state + 0x18)));
            {
                u8 *txt;
                txt = datPersonaGetRow(*(u16 *)(((u8 **)(state + 0x4C))[*(s32 *)(state + 4) + *(s32 *)(state + 8)] + 2));
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                *(s32 *)state = 5;
                sdkSndStartStream(0, 4, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            shdPersonaBeginClose((u8 *)(*(s32 *)(state + 0x18)));
            *(s32 *)state = 2;
            sdkSndStartStream(0, 4, 0, 4);
        } else if (D_008C024E[0] & 0x80) {
            shdPersonaBeginSelection((u8 *)(*(s32 *)(state + 0x18)));
            *(s32 *)state = 4;
        } else {
            sdkListStateConfigure((u8 *)(buf), 0xC, *(s32 *)(state + 0x0C), row, scroll);
            sdkListStateSetPrimaryMasks(buf, 8, 4, 0, 0);
            sdkListStateSetActive(buf, 0);
            res = sdkListStateHandleInput(buf);
            if (res > 0) {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                idx = *(s32 *)(state + 4) + *(s32 *)(state + 8);
                if (res == 2) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = *(u8 **)(state + 0x18);
                        s32 displayMode = 1;
                        shdPersonaBeginDisplayAndEndSelection(display, displayMode, (s32)*selected, 0);
                    }
                } else if (res == 1) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = *(u8 **)(state + 0x18);
                        s32 displayMode = 1;
                        shdPersonaBeginDisplay(display, displayMode, (s32)*selected, 0);
                    }
                }
            }
        }
        break;
    case 4:
        if ((D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x20)) {
            shdPersonaEndSelection((u8 *)(*(s32 *)(state + 0x18)), 1);
            *(s32 *)state = 3;
        } else if (D_008C024E[0] & 0x40) {
            shdPersonaBeginClose((u8 *)(*(s32 *)(state + 0x18)));
            {
                u8 *txt;
                txt = datPersonaGetRow(*(u16 *)(((u8 **)(state + 0x4C))[*(s32 *)(state + 4) + *(s32 *)(state + 8)] + 2));
                nmMesWindowSetCurrentString(0, txt);
                nmMesWindowShowCurrentRecord(4);
                nmMesWindowSetCurrentParam(5);
                nmMesWindowSetCurrentFlag(1);
                nmMesWindowRequestRefresh();
                *(s32 *)state = 5;
                sdkSndStartStream(0, 4, 0, 1);
            }
        } else {
            sdkListStateConfigure((u8 *)(buf), 0xC, *(s32 *)(state + 0x0C), row, scroll);
            sdkListStateSetPrimaryMasks(buf, 8, 4, 0, 0);
            sdkListStateSetActive(buf, 0);
            res = sdkListStateHandleInput(buf);
            if (res > 0) {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                idx = *(s32 *)(state + 4) + *(s32 *)(state + 8);
                if (res == 2) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = *(u8 **)(state + 0x18);
                        s32 displayMode = 1;
                        shdPersonaBeginDisplayAndEndSelection(display, displayMode, (s32)*selected, 0);
                    }
                } else if (res == 1) {
                    {
                        u8 **selected = (u8 **)(state + 0x4C) + idx;
                        u8 *display = *(u8 **)(state + 0x18);
                        s32 displayMode = 1;
                        shdPersonaBeginDisplay(display, displayMode, (s32)*selected, 0);
                    }
                }
                *(s32 *)state = 3;
            } else {
                shdPersonaStepSelectionCursor((u8 *)(*(s32 *)(state + 0x18)));
            }
        }
        break;
    case 5:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            switch (nmMesWindowCurrentAnimFlag()) {
            case 0:
                shdPersonaFinishPhase((u8 *)(*(s32 *)(state + 0x18)));
                *(s32 *)(state + 0x18) = 0;
                func_0038d0a0((u8 *)(*(s32 *)(*(u8 **)arg0 + 0x1F298)));
                func_00388d40((u8 *)(*(s32 *)(*(u8 **)arg0 + 0x1F294)));
                {
                    u8 **slot;
                    u8 *txt;
                    slot = &((u8 **)(state + 0x4C))[sum];
                    txt = datPersonaGetRow(*(u16 *)(*slot + 2));
                    nmMesWindowSetCurrentString(0, txt);
                    nmMesWindowShowCurrentRecord(6);
                    *(s32 *)state = 6;
                    if (sum != 0) {
                        datPersonaRemoveRosterMemberById(*(u16 *)(*slot + 2));
                        datPersonaTryAddRosterMember(*(u16 *)(arg0 + 0x10));
                    }
                }
                break;
            case 1:
                nmMesWindowCloseCurrent(1);
                *(s32 *)state = 2;
                break;
            }
        }
        break;
    case 6:
        func_002bb7c0(1);
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

// FUN_003816E0
s32 btlShuffleResultInit(u8 *arg0) {
    u8 *p = arg0 + 0x18;
    switch (*(s32 *)(arg0 + 0x18)) {
    case 0:
        *(s32 *)p = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (*(u16 *)(arg0 + 4) & 2) {
                memset(arg0 + 0x18, 0, 0xC);
                *(s32 *)(arg0 + 8) = 4;
            } else {
                nmMesWindowShowCurrentRecord(8);
                *(s32 *)p = 2;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (*(u16 *)(arg0 + 4) & 1) {
                memset(p, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
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
// FUN_00381830
s32 btlShuffleResultLayout(u8 *arg0)
{
    s32 *state = (s32 *)(arg0 + 0x18);
    s32 count;
    s32 i;
    u8 *base;
    s32 bumped;

    switch (*(s32 *)(arg0 + 0x18)) {
    case 0:
        *state = 1;
        /* fallthrough */
    case 1:
        if ((s32)*(u16 *)(arg0 + 6) < 0xA) {
            /* measured: the compound assignment's VALUE keeps the incremented
               counter in one register, so b210 emits the sh before the andi
               exactly as retail does; a separate `cnt = cnt + 1; store;` pair
               masks first. */
            bumped = (*(u16 *)(arg0 + 6) += 1);
            if ((bumped & 0xFFFF) == 0xA) {
                sdkSndStartStream(1, 1, 5, 0xC);
            }
        }
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (*(u16 *)(arg0 + 4) & 2) {
                memset(arg0 + 0x18, 0, 0xC);
                *(s32 *)(arg0 + 8) = 4;
            } else {
                base = *(u8 **)arg0;
                count = btlShuffleDrawTableLookup(*(s32 *)(base + 0x1F304),
                                      *(s32 *)(base + 0x1F2FC));
                for (i = 0; i < count; i++) {
                    if (i != *(s32 *)(base + 0x1F308)) {
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
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            btlShuffleResetSlot((u8 *)func_0036e900(*(void **)(*(u8 **)arg0 + 0x1F2A8)));
            return 1;
        }
        break;
    }
    return 0;
}

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

static inline void shuffleResultOpen(u8 *context)
{
    f32 screen[2];
    BtlShuffleVec3 position;
    *(f32 *)(context + 0x1F310) = 10.0f;
    btlShuffleDrawViewReset(context);
    screen[0] = 316.0f;
    screen[1] = 211.0f;
    btlShuffleCardScaleVec(context + *(s32 *)(context + 0x1F308) * 0xFB0, &screen[0], 160.0f, (f32 *)&position);
    btlShuffleDrawMoveCard(context, *(s32 *)(context + 0x1F308), 0.0f, 0.0f, (f32 *)&position, (f32 *)&position);
    btlShuffleEffUpdate(*(u8 **)(context + 0x1F29C));
    btlShuffleEffEnd(*(u8 **)(context + 0x1F29C));
    func_00388e40(*(u8 **)(context + 0x1F294));
    btlShuffleEffInitTrail(*(u8 **)(context + 0x1F29C), 6);

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
    kind = *(u8 *)(work + 0x12);
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
    persona = (u16)*(u16 *)(work + 0x10);
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

// FUN_00381A70
s32 btlShuffleResultRun(u8 *arg0)
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

    view.context = *(u8 **)arg0;
    view.state = (ShuffleResultState *)(arg0 + 0x18);
    switch (view.state->phase) {
    case 0:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            view.state->phase = 1;
        }
        break;
    case 1:
        shuffleResultOpen(view.context);
        view.state->phase = 2;
    case 2:
        result = btlShuffleDrawFlagA((u8 *)*(s32 *)(view.context + 0x1F2A0));
        if (result != 0) {
            result = func_00388ec0(*(u8 **)(view.context + 0x1F294));
            if (result != 0) {
                btlShuffleDrawSetPose(view.context, *(s32 *)(view.context + 0x1F308), 0, 0x14);
                *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 8);
                view.state->phase = 3;
                goto waitForCard;
            }
        }
        break;
    case 3:
    waitForCard:
        result = btlShuffleDrawStateC(view.context + *(s32 *)(view.context + 0x1F308) * 0xE8 + 0x1D6A0);
        if (result != 0) {
            *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) & 0xFFFB);
            result = datGetFlag(0x1434);
            if (result == 0) {
                func_002bb4e0();
                btlShuffleSeqClearA(view.context, 4);
                view.state->phase = 0x13;
            } else {
                view.state->phase = 4;
            }
        }
        break;
    case 4:
        nmMesWindowSetCurrentString(0, datCalcGetSlotRecord(*(u8 *)(arg0 + 0x12)));
        nmMesWindowShowCurrentRecord(0xC);
        nmMesWindowSetCurrentParam(0xD);
        nmMesWindowSetCurrentFlag(0);
        nmMesWindowRequestRefresh();
        view.state->phase = 5;
        break;
    case 5:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            result = nmMesWindowCurrentAnimFlag();
            switch (result) {
            case 0:
                view.state->timer = 0;
                switch (*(u8 *)(arg0 + 0x12)) {
                case 1:

                    view.state->phase = 10;
                    view.state->spinsRemaining = 0;
                    upright = shuffleResultRoll(*(u8 *)(arg0 + 0x12));
                    view.state->isUpright = upright;
                    randomBits = RpRandom() & 0xFFF;
                    randomValue = (f32)randomBits;
                    view.state->resultCard = (u8)(1.0f + (1.0f + 20.0f * (randomValue / 4096.0f)));
                    *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 0x20);
                    *(s32 *)(view.context + 0x1F2A4) = btlShuffleDrawSpawn(*(u8 **)(view.context + 0x1F2A8), (view.state->resultCard - 1) & 0xFF);
                    break;
                default:

                    view.state->phase = 7;
                    *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 0x10);
                    randomBits = RpRandom() & 0xFFF;
                    randomValue = (f32)randomBits;
                    view.state->spinsRemaining = ((s32)(3.0f * (randomValue / 4096.0f)) + 5) * 2;
                    upright = shuffleResultRoll(*(u8 *)(arg0 + 0x12));
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
                nmMesWindowShowCurrentRecord((*(u8 *)(arg0 + 0x12) - 1) * 4 + 0x15);
                view.state->phase = 6;
                break;
            }
        }
        break;
    case 6:
        func_002bb7c0(1);
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
            func_00388ee0(*(u8 **)(view.context + 0x1F294));
            goto advanceSpin;
        }
        break;
    case 8:
    advanceSpin:
        result = btlShuffleDrawStateC(view.context + *(s32 *)(view.context + 0x1F308) * 0xE8 + 0x1D6A0);
        if (result != 0) {
            rotation = D_0064EC88;
            btlShuffleDrawSetCurve(view.context, *(s32 *)(view.context + 0x1F308), 0, view.state->step, &rotation, 0.0f, 180.0f);
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
        result = btlShuffleDrawStateC(view.context + *(s32 *)(view.context + 0x1F308) * 0xE8 + 0x1D6A0);
        if (result != 0) {
            if (*(u16 *)(view.context + 0x1F2F4) & 0x10) {
                *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) & 0xFFEF);
                *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 0x100);
                *(u16 *)(view.context + 0x1F2F2) = 0;
            }
            if (view.state->isUpright != 0) {
                sdkSndStartStream(1, 3, 2, 1);
            } else {
                sdkSndStartStream(1, 3, 2, 2);
            }
            shuffleResultDescribe(arg0);
            view.state->phase = 0xD;
        }
        break;
    case 10:
        if (((view.state->timer += 1) & 0xFFFF) >= 10) {
            view.state->step = 5;
            view.state->phase = 0xB;
            func_00388ee0(*(u8 **)(view.context + 0x1F294));
            func_00388f00(*(u8 **)(view.context + 0x1F294));
            func_003892e0(*(u8 **)(view.context + 0x1F294));
        }
        break;
    case 11:
        if (((view.state->timer += 1) & 0xFFFF) >= 0x3C) {
            result = btlShuffleDrawFlagA((u8 *)*(s32 *)(view.context + 0x1F2A4));
            if (result != 0) {
                view.state->phase = 0xC;
                func_00389350(*(u8 **)(view.context + 0x1F294));
                goto finishReveal;
            }
        }
        break;
    case 12:
    finishReveal:
        result = func_00389330(*(u8 **)(view.context + 0x1F294));
        if (result != 0) {
            if (view.state->isUpright == 0) {
                *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 0x80);
            }
            *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) | 0x40);
            if (*(void **)(view.context + 0x1F2A0) != 0) {
                kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(view.context + 0x1F2A0));
                *(s32 *)(view.context + 0x1F2A0) = 0;
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
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            override = shuffleResultReverse(arg0);
            view.state->uprightOverride = override;
            if (override != 0) {
                view.state->phase = 0x10;
            } else {
                result = func_00380980(arg0);
                if (result == 0) {
                    return 1;
                }
                view.state->phase = 0xE;
            }
        }
        break;
    case 14:
        func_002bb7c0(1);
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
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            return 1;
        }
        break;
    case 16:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            if (view.state->uprightOverride == 1) {
                nmMesWindowShowCurrentRecord(0x11);
                view.state->phase = 0x11;
            } else {
                func_00380980(arg0);
                view.state->phase = 8;
            }
        }
        break;
    case 17:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            return 1;
        }
        break;
    case 18:
        result = btlShuffleDrawStateC(view.context + *(s32 *)(view.context + 0x1F308) * 0xE8 + 0x1D6A0);
        if (result != 0) {
            *(u16 *)(view.context + 0x1F2F4) = (u16)(*(u16 *)(view.context + 0x1F2F4) & 0xFFF7);
            if (*(void **)(view.context + 0x1F2A0) != 0) {
                kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(view.context + 0x1F2A0));
                *(s32 *)(view.context + 0x1F2A0) = 0;
            }
            result = shuffleResultPersonaState(arg0);
            *(s32 *)(arg0 + 8) = result;
        }
        break;
    case 19:
        result = btlShuffleSeqFlag(view.context);
        if (result != 0) {
            datSetFlag(0x1434, 1);
            nmMesWindowOpenCurrent((u8 *)(*(s32 *)(view.context + 0x1F2DC)));
            view.state->phase = 4;
        }
        break;
    }
    return 0;
}


// FUN_00382BA0
s32 btlShuffleResultMenu(u8 *arg0) {
    f32 pos[2];
    struct {
        u8 pad[8];
        u8 out[16];
    } outBuf;
    s32 stage;
    u8 *phaseState;
    u8 *work;

    phaseState = arg0 + 0x18;
    work = *(u8 **)arg0;
    stage = *(s32 *)phaseState;
    switch (stage) {
    case 0:
        *(f32 *)(work + 0x1F310) = 10.0f;
        btlShuffleDrawViewReset(work);
        pos[0] = 316.0f;
        pos[1] = 211.0f;
        btlShuffleCardScaleVec(work + *(s32 *)(work + 0x1F308) * 0xFB0, &pos[0], 160.0f, (f32 *)&outBuf.out[0]);
        btlShuffleDrawMoveCard(work, *(s32 *)(work + 0x1F308), 0.0f, 0.0f, (f32 *)&outBuf.out[0], (f32 *)&outBuf.out[0]);
        btlShuffleEffUpdate(*(u8 **)(work + 0x1F29C));
        btlShuffleEffEnd(*(u8 **)(work + 0x1F29C));
        func_00388d60(*(u8 **)(work + 0x1F294));
        btlShuffleEffInitTrail(*(u8 **)(work + 0x1F29C), 7);
        *(s32 *)(work + 0x1F30C) = 1;
        *(s32 *)phaseState = 1;
    case 1:
        if (((*(u16 *)(phaseState + 4) += 1) & 0xFFFF) >= 0xA && func_00388de0(*(u8 **)(work + 0x1F294)) != 0) {
            nmMesWindowShowCurrentRecord(0x12);
            *(s32 *)phaseState = 2;
        case 2:
            func_002bb7c0(1);
            if (nmMesWindowCurrentOpenState() == 0) {
                nmMesWindowCloseCurrent(1);
                *(s32 *)phaseState = 3;
                btlShuffleSeqUpdateMode(work, *(s32 *)(work + 0x1F308), 0xA, 1);
                func_00388e00(*(u8 **)(work + 0x1F294));
                btlShuffleEffSetup(*(u8 **)(work + 0x1F29C), 7);
                func_0038d310(*(u8 **)(work + 0x1F298));
            }
        }
        goto block_17;
    case 3:
        if (btlShuffleDrawStateC(work + *(s32 *)(work + 0x1F308) * 0xE8 + 0x1D6A0) != 0) {
            *(u16 *)(work + 0x1F2F4) = (u16)(*(u16 *)(work + 0x1F2F4) & 0xFFFB);
            *(s32 *)phaseState = 4;
        case 4:
            if (func_00388e20(*(u8 **)(work + 0x1F294)) != 0) {
                *(s32 *)(phaseState + 8) = 2;
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
    if (*(u8 *)(work + 0x12) == 0) {
        thresh = (u8)(D_0064E6E0[0][flag] + iGpffffa9B8[rate]);
    } else {
        thresh = (u8)(D_0064E6E0[(u8)cmmCommunityValueForArcana(*(u8 *)(work + 0x12))][flag] + iGpffffa9B8[rate]);
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

// FUN_00382EA0
s32 btlShuffleResultBonus(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3)
{
    u8 *unit;
    s32 count;
    s32 i;
    u8 *u;

    unit = func_0036e910(arg0);
    *(u8 **)work = unit;
    *(s32 *)(work + 0xC) = arg1;
    *(u16 *)(work + 0x10) = arg2;
    nmMesWindowOpenCurrent((u8 *)(*(s32 *)(unit + 0x1F2DC)));
    switch (*(s32 *)(work + 0xC)) {
    case -1:
        nmMesWindowShowCurrentRecord(8);
        *(s32 *)(work + 8) = 8;
        return 0;
    case 0:
        if (shuffleBonusRoll(work, arg3) != 0) {
            *(u8 *)(work + 0x12) = shuffleBonusPick() + 1;
            *(u16 *)(work + 4) |= 1;
            *(s32 *)(unit + 0x1F2A0) = btlShuffleDrawSpawn(*(u8 **)(unit + 0x1F2A8), (u8)(*(u8 *)(work + 0x12) - 1));
        }
        *(u16 *)(work + 6) = 0;
        nmMesWindowSetCurrentString(0, datPersonaGetRow(arg2));
        nmMesWindowShowCurrentRecord(0);
        func_0038d2a0(*(u8 **)(unit + 0x1F298));
        *(s32 *)(work + 8) = 0;
        break;
    case 2:
        if (shuffleBonusRoll(work, arg3) != 0) {
            *(u8 *)(work + 0x12) = shuffleBonusPick() + 1;
            *(u16 *)(work + 4) |= 1;
            *(s32 *)(unit + 0x1F2A0) = btlShuffleDrawSpawn(*(u8 **)(unit + 0x1F2A8), (u8)(*(u8 *)(work + 0x12) - 1));
        } else if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) |= 2;
        }
        nmMesWindowShowCurrentRecord(7);
        func_0038d2a0(*(u8 **)(unit + 0x1F298));
        *(s32 *)(work + 8) = 2;
        break;
    case 3:
        if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) |= 2;
        }
        *(u16 *)(work + 6) = 0;
        nmMesWindowShowCurrentRecord(9);
        func_0038d2a0(*(u8 **)(unit + 0x1F298));
        *(s32 *)(work + 8) = 3;
        break;
    default:
        kAssertFail(D_0064EC70, 0x6C7);
        break;
    }
    if ((*(u16 *)(work + 4) & 2) == 0) {
        u = *(u8 **)work;
        count = btlShuffleDrawTableLookup(*(s32 *)(u + 0x1F304), *(s32 *)(u + 0x1F2FC));
        for (i = 0; i < count; i++) {
            if (i != *(s32 *)(u + 0x1F308)) {
                if (*(u16 *)(u + i * 0xE8 + 0x1D6A0) & 2) {
                    kAssertFail(D_0064EC70, 0x8C);
                }
                btlShuffleCardUpdateState(u + i * 0xFB0);
            }
        }
    }
    return 0;
}

// FUN_00383720
s32 btlShuffleResultMain(u8 *arg0) {
    s32 btlShuffleResultRun(u8 *arg0);
    s32 btlShuffleResultInit(u8 *arg0);
    s32 btlShuffleResultLayout(u8 *arg0);
    s32 btlShuffleResultMenu(u8 *arg0);
    s32 btlShuffleResultOpen(u8 *arg0);
    s32 flag5;
    s32 flag6;
    s32 flag8;
    u16 count;
    u32 stage;

    stage = (u32)*(s32 *)(arg0 + 8);
    switch (stage) {
    case 0:
        count = *(u16 *)(arg0 + 6);
        if ((s32)count < 0xA) {
            if (((*(u16 *)(arg0 + 6) += 1) & 0xFFFF) == 0xA) {
                sdkSndStartStream(1, 1, 5, 0xA);
            }
        }
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            *(s32 *)(arg0 + 8) = func_00380d80(arg0, *(u16 *)(arg0 + 0x10));
        }
        goto block_39;
    case 1:
        if (btlShuffleResultRun(arg0) != 0) return 1;
        goto block_39;
    case 2:
        if (btlShuffleResultInit(arg0) != 0) return 1;
        goto block_39;
    case 3:
        if (btlShuffleResultLayout(arg0) != 0) return 1;
        goto block_39;
    case 4:
        if (btlShuffleResultMenu(arg0) != 0) return *(s32 *)(arg0 + 0x20);
        goto block_39;
    case 5:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            flag5 = 1;
        } else {
            flag5 = 0;
        }
        if (flag5 != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                memset(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 6:
        func_002bb7c0(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            flag6 = 1;
        } else {
            flag6 = 0;
        }
        if (flag6 != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                memset(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 7:
        if (btlShuffleResultOpen(arg0) != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                memset(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                nmMesWindowShowCurrentRecord(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 8:
        func_002bb7c0(1);
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

// FUN_00383A40
s32 btlShuffleResultEnd(u8 *arg0) {
    u8 *state;

    state = *(u8 **)(arg0 + 0x38);
    if (*(u16 *)(state + 4) & 4) {
        return -1;
    }
    if (*(s32 *)(state + 0x14) == 0) {
        *(s32 *)(state + 0x14) = btlShuffleResultMain(state);
    }
    return 0;
}

// FUN_00383AA0
void btlShuffleResultFree(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002bb4e0();
    jtbl_008873EC[0](work);
}

// FUN_00383AE0
s32 btlShuffleResultSpawn(u8 *arg0, s32 arg1, u16 arg2, s32 arg3) {
    u8 *work;
    s32 ret;

    chkmemAllocSiteTag(&D_0064EC70, 0x757);
    work = D_008873F4[0](1, 0x94, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064EC70, 0x758);
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064EB60), 0x12, 0, 0, btlShuffleResultEnd, btlShuffleResultFree, (u8 *)(work));
    if (ret == 0) {
        kAssertFail(&D_0064EC70, 0x762);
    }
    btlShuffleResultBonus(work, arg0, arg1, arg2, arg3);
    return ret;
}
