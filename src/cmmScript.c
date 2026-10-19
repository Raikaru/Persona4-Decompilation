/* Original translation unit cmmScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "evt_internal.h"
#include "cmm_internal.h"
#include "datPersona_internal.h"
#include "scr_internal.h"

extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern u32 kwlnTaskGetWork(void *task);
extern void func_004b1250(void *model, f32 *position);
extern s32 sdkSndStartChannel(s16 channel, const char *name);
extern s32 sdkSndStartStream(s16 channel, s16 stream, s16 thirdInput, s16 fourthInput);
extern void kAssertFail(void *file, s32 line);

u16 cmmTopReversedCommunity();

u16 cmmFindFreshReverseCandidate();

u16 cmmFindReverseCandidate();

extern s32 cmmCommunityFindActiveSlotInGroup(s32 input);
extern s32 cmmCommunityGetCurrentEntryValue(s32 input);
extern void cmmCommunityAddTotal(s32 input);

extern s32 cmmCommunityGetTotal(void);
extern void datResetTotalBtl(void);
extern void datAddMoney(s32 input);

extern s16 datGetDateIndex(void);
extern s32 cmmDateTableFindIndex(s32 input);
extern s32 cmmDateTableHasEntry(s32 input);
extern s32 cmmDateTableHasSpecialRecord(s32 input);
extern s32 cmmDateTableReadColumn(s32 input, s32 secondInput, s32 thirdInput);
extern s32 cmmDateTableApplyColumnDelta(s32 input, s32 secondInput);

extern u8* cmmCommunityGetCurrentWork(void);
extern s32 cmmCommunityGetCurrentId(void);
extern void cmmCommunityAdvanceForm(s32 input);
extern void cmmCommunitySetMarked(s32 input);
extern void datDestroyTaskByName(void);
extern void cmmCommunitySetCurrent(u16 input);
extern s16 cmmResolveCounterpart(s16 input);
extern s32 cmmDateTableAddCount(s32 input, s32 secondInput);
extern s16 cmmTopPersonaOfArcana(s16 input);
extern u8* cmmMsgStreamEntry(s32 input, u16 secondInput);
extern s32 cmmDateTableFindNthMatch(s32 input, s32 secondInput, s32 thirdInput);
extern void cmmRankUpSequenceStart(s32 input, s32 secondInput, s32 thirdInput, s32 fourthInput);
extern s32 K_Cmd_TASK_LOOKUP(void);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern s32 D_00635A78[];
extern s32 D_006359F0[];
extern s32 D_00635A20[];
extern s32 D_00635A00[];
extern s16 D_00635BB8[];
extern s32 D_00635B38[];
extern void sdkSndFadeOutChannelFrames(s32 input, s32 secondInput, s32 thirdInput);
extern s32 kwlnTaskIsLinked(s32 input);
extern void sdkSpriteRelease(u8* input);
extern void H_Cdvd_Destroy(u8* input);
extern u8* H_Cdvd_AcquireDirectory(void* input, s32 secondInput);
extern s32 H_Cdvd_IsFileLoaded(u8* input);
extern s32 H_Cdvd_LookupRequest(void* input, u32* secondInput);
extern s32 func_0046a750(s32 input);
extern void func_00440b68(void* input, void* secondInput, u32 thirdInput);
extern u8* cmmItemInfoRecord(s32 input);
extern void cmmAdvanceReverseProgress(s32 input);
extern void datPersonaCollectSkills(s32 input, void* secondInput, s32* thirdInput);
extern void func_001029a0(s32 input, void* secondInput, s32 thirdInput, s32 fourthInput);
extern s32 kwlnGetCurrentWorkValue(void);
extern s32 datPersonaDisplayName(s16 input);
extern s8 cmmCommunityEventValue(s32 input, s32 secondInput);
extern s32 cmmNameRecord(s32 input);
extern s64 cmmCommunityArcana(s32 input);
extern s32 func_002438b0(s32 input);
extern s32 cmmLabelRecord(s32 input);
extern s32 cmmCommunityRecordValue(s32 input);
extern s32 cmmNextUnlistedDate(s32 input);
extern s32 calGetWeekdayOfDay(s32 input, s32* secondInput, s32* thirdInput);
extern s32 cmmTextRecord(s32 input);
extern s32 datGetItemNameId(s32 input);
extern s32 cmmDateTableFindRecord(s32 input);
extern s32 cmmDateTableFindSpecialRecord(s32 input);
extern void itfMesWindowSetNumber(s32 input, s32 secondInput, s32 thirdInput);
extern s32 cmmItemDescRecordOrNull(s32 input);
extern s32 cmmItemExtraRecordOrNull(s32 input);
extern u8 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 input, u32 secondInput);
extern s32 datGetFlag(s32 input);
extern u32 RpRandom(void);


extern u8 D_00635A88[];
extern u8 D_00635AA0[];
extern u8 D_00635AC0[];
extern u8 D_00635AE0[];
extern u8 D_00635B00[];
extern u8 D_00635B20[];
extern u8 D_005DC7D0[];
extern s32 shdEffectTaskCreate(s32 input, s32 secondInput, s32 thirdInput, void *fourthInput);
extern s32 func_0025ff60(s32 input);
extern u8* cmmFishingEntryRecord(s32 input);
extern s32 cmmDateTableRollValue(s32 input);
extern void cmmDateTableRunEffect(s32 input);
extern void datEntryDrawGatedByFlag39(s32 input, s32 secondInput, s32 thirdInput, s32 fourthInput);
extern f32 sinf(f32 input);
extern void mdlEffectGetPackedColor(s32 input, void* secondInput);
extern void mdlEffectGetPosition(s32 input, void* secondInput);
extern void mdlEffectSetPackedColor(s32 input, void* secondInput);
extern u16 D_008C024E[];
extern u8 D_00635B50[];
extern u8 D_00635B90[];
typedef struct {
    f32 value[3];
} CmmFishingPosition;

/* Both retail origin objects begin on eight-byte boundaries. Only the
   three-coordinate value participates in the copied position. */
typedef union {
    CmmFishingPosition value;
    s64 alignment;
} CmmFishingOrigin;

extern CmmFishingOrigin D_00635B68;
extern CmmFishingOrigin D_00635B78;
extern f32 iGpffff8084;
extern f32 iGpffff8094;
extern u8 D_00794E70[];
extern s32 sdkSpriteDrawQueued(f32 floatInput, f32 secondFloatInput, f32 thirdFloatInput,
                         s32 input, u8 secondInput, s32 thirdInput, void* fourthInput,
                         s32 fifthInput, s16 sixthInput, s16 seventhInput,
                         f32 fourthFloatInput, f32 fifthFloatInput, f32 sixthFloatInput, void* eighthInput);
extern s32 func_00243840(s32 input);
extern void itfMesWindowFormatValue(s32 input, s32 secondInput, s32 thirdInput, u32 fourthInput);
extern void frFontExCopyString();
extern void itfMesWindowSetString();
extern s32 iGpffffa658;
extern s32 iGpffffa62c;
extern u8* iGpffffb3d4;
extern s32 D_00635A40[];
extern s32 D_00635A60[];
extern s32 D_00635BA8[];
extern u8* evtEnsureEventTask(void); /* lint: allow H011 -- caller stores the returned value; the definition is void */
extern void calSplitDayOfYear(s32 input, s32 *secondInput, s32 *thirdInput);
extern s32 cmmMonthProfileRecord(s32 input);
extern s32 datCalcGetLevelById(s32 input);
extern s32 cmmArcanaCandidateAt(s32 input, s32 secondInput, s32 thirdInput);

extern void chkmemAllocSiteTag(const void* input, s32 secondInput);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 cmmScriptStepFishingRound(u8* input);
extern s32 cmmScriptStepFishingAim(u8* input);
extern s32 cmmScriptLoadStep(u8 *task);
extern void cmmScriptTaskDestroy(u8 *task);
extern s32 cmmScriptStepWaveSprite(u8* input, u8* secondInput);
extern s32 cmmScriptStepPopupBanner(u8* input, u8* secondInput);
extern s32 cmmScriptStepScoreDisplay(u8* input, u8* secondInput);
typedef struct { f32 x, y, z, w; } Vec4f;

typedef int (*code)();
extern code DAT_008873ec_abs[];

typedef struct {
    u8 pad[0xC];
    s32 hi;
    s32 lo;
    u32 u;
} cmmMsgPack;

typedef struct cmmMsgState
{
    u16 unk00;   // 0x00, passed to cmmAdvanceReverseProgress
    u8 pad02[6];
    union
    {
        Vec4f vec; // 0x08, copied from the stream entry at cur
        struct
        {
            u8 pad08[2];
            u8 unk0A;  // 0x0A, passed to scrSetReturnInt
            u8 pad0B;
            s32 unk0C; // 0x0C, packed into pack.hi/lo
            u16 unk10; // 0x10, pack.u
            u8 pad12;
            u8 unk13;  // 0x13, nonzero selects the stream branch
            u8 pad14[4];
        } raw;
    } view;
    u8 *cur;     // 0x18, next stream entry
    s32 counter; // 0x1C, frames since the last send
} cmmMsgState;

typedef struct CmmWeatherRow { s8 weight[6]; } CmmWeatherRow;
typedef struct CmmMonthAttribute {
    u16 first;
    u16 second;
    s32 third;
    s32 fourth;
} CmmMonthAttribute;
typedef struct CmmMonthProfile {
    CmmWeatherRow weather[4];
    CmmMonthAttribute attributes[4];
} CmmMonthProfile;



// Message stream start: selects stream entry 'b' for script id 'a' and copies it into the message state.
/* script command 0x3009 (no p4flow name) */
// FUN_0024A200
s32 cmmMsgStreamStart(void)
{
    /* cmmMsgState proves the +8 vector/+0x18 stream offsets; typed access changed MWCC codegen. */
    s32 a;
    s32 b;
    u8* p;
    u8* q2;
    u8* q3;
    u8* q;

    a = scrGetParamInt(0);
    b = scrGetParamInt(1);
    cmmCommunitySetCurrent(b);
    p = cmmCommunityGetCurrentWork();
    if (p == 0) {
        kAssertFail(D_006359F0, 0xE7);
    }
    q = cmmMsgStreamEntry(a & 0xFFFF, b & 0xFFFF);
    *(u8**)(p + 0x18) = q;
    if (q == 0) {
        kAssertFail(D_006359F0, 0xE9);
    }
    *(Vec4f*)(p + 8) = *(Vec4f*)(*(u8**)(p + 0x18));
    return 1;
}


/* Script task user data. Offsets are shared by cmmScriptLoadStep (state
   machine), cmmScriptTaskDestroy (destroy) and cmmScriptTaskDestroyHandle (handle release). */
typedef struct CmmScriptTask
{
    u32 flags;      // 0x00, bit 0 set once the file is loaded
    s32 state;      // 0x04
    s32 cdvdHandle; // 0x08, H_Cdvd file handle
    s32 handles[5]; // 0x0C, released with kwlnTaskDestroyWithHierarchy
    s32 weatherChoice; // 0x20, category result written by cmmWeatherRoll
    s32 data;       // 0x24, buffer from sdkSpriteAdoptBlob, freed on destroy
} CmmScriptTask;

// Message stream update: sends the next packet every 10 frames and finishes when the stream ends.
/* script command 0x300A (no p4flow name) */
// FUN_0024A2E0
s32 cmmMsgStreamUpdate(void)
{
    cmmMsgState *p;
    s32 x;
    u32 u16val;
    u32 lo;
    cmmMsgPack pack1;
    cmmMsgPack pack2;

    p = (cmmMsgState *)cmmCommunityGetCurrentWork();
    if (p == 0) {
        kAssertFail(D_006359F0, 0x109);
    }
    x = p->counter;
    if (x == 0) {
        u16val = p->view.raw.unk10;
        x = p->view.raw.unk0C;
        lo = x & 0xFFFF;
        pack1.hi = (u32)(x & 0xFFFF0000) >> 0x10;
        pack1.lo = lo;
        pack1.u = u16val;
        func_001029a0(0xA, &pack1, 0x1C, 2);
    } else if (x > 0xA) {
        u32 b;

        b = ~kwlnGetCurrentWorkValue() == 0;
        if (b) {
            if (p->view.raw.unk13 != 0) {
                u8* entry;

                entry = p->cur;
                p->cur = entry + 0x10;
                p->view.vec = ((Vec4f *)entry)[1];
                u16val = p->view.raw.unk10;
                x = p->view.raw.unk0C;
                lo = x & 0xFFFF;
                pack2.hi = (u32)(x & 0xFFFF0000) >> 0x10;
                pack2.lo = lo;
                pack2.u = u16val;
                func_001029a0(0xA, &pack2, 0x1C, 2);
                p->counter = 0;
            } else {
                datDestroyTaskByName();
                cmmAdvanceReverseProgress(p->unk00);
                return 1;
            }
        }
    }
    p->counter += 1;
    return 0;
}
// Message stream result: returns the result value stored in the message state.
/* script command 0x300B (no p4flow name) */
// FUN_0024A450
s32 cmmMsgStreamGetResult(void)
{
    cmmMsgState *p;

    p = (cmmMsgState *)cmmCommunityGetCurrentWork();
    if (p != 0) {
        scrSetReturnInt(p->view.raw.unk0A);
    }
    return 1;
}

/* measured: b210 at -O2 CSEs `a & 0xFFFF` across the 9 call sites into
   callee-saved copies (frame 0xF0, sq $18/$19); retail re-ANDIs into $a0
   per site with a 0xD0 frame. optimization_level 1 (scoped back to 2)
   restores the per-site andi, and then the s8 return of func_002487e0
   must be held in an s32 local (an s8/u8 local makes level-1 codegen
   emit a redundant `move` around the dsll32/dsra32 sign-extension). */
// Script persona detail show: resolves the persona id (0 = current) and fills message slots 0-7 with name, strings, and numbers.
/* script command 0x3013 (no p4flow name) */
// FUN_0024A490
#pragma optimization_level 1

s32 cmmPersonaDetailShow(void)
{
    s32 id;
    s32 mesMgr;
    u8 buf[0x80];
    s32 tbl[7];
    s32 key;
    s32 idx;
    s32 i;
    s32 tmp;
    s32* src;
    s32* dst;

    id = scrGetParamInt(0);
    if (id == 0) {
        id = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    mesMgr = scrGetMessageManager();
    if (mesMgr < 0) {
        kAssertFail(D_006359F0, 0x140);
    }
    key = cmmCommunityEventValue(id & 0xFFFF, 0);
    if (key != 0) {
        itfMesWindowSetString(mesMgr, 0, datPersonaDisplayName((s16)key));
    }
    frFontExCopyString(cmmNameRecord(id & 0xFFFF), buf, 0x80);
    itfMesWindowSetString(mesMgr, 1, buf);
    itfMesWindowSetString(mesMgr, 2, func_002438b0((u8)cmmCommunityArcana(id & 0xFFFF)));
    frFontExCopyString(cmmLabelRecord((s8)cmmCommunityArcana(id & 0xFFFF)), buf, 0x80);
    itfMesWindowSetString(mesMgr, 3, buf);
    itfMesWindowFormatValue(mesMgr, 4, cmmCommunityRecordValue(id & 0xFFFF) & 0xFFFF, 0);
    key = cmmTopPersonaOfArcana((s16)id);
    if (key != 0) {
        itfMesWindowSetString(mesMgr, 5, datPersonaGetRow(key & 0xFFFF));
    }
    idx = cmmNextUnlistedDate(datGetDateIndex());
    if (idx != 0) {
        src = D_00635A00;
        dst = tbl;
        i = 7;
        do {
            tmp = *src++;
            i--;
            *dst++ = tmp;
        } while (i > 0);
        frFontExCopyString(tbl[calGetWeekdayOfDay(idx, dst, src)], buf, 0x80);
        itfMesWindowSetString(mesMgr, 6, buf);
    }
    frFontExCopyString(cmmTextRecord(id & 0xFFFF), buf, 0x80);
    itfMesWindowSetString(mesMgr, 7, buf);
    return 1;
}

/* Closes the measured optimization_level 1 scope opened above; -O2 is the
   baseline everywhere else in this translation unit. */
#pragma optimization_level 2
// Persona info lookup and show: resolves the persona entry from the script id, then fills the message slots.
/* script command 0x301C (no p4flow name) */
// FUN_0024A710
/* measured: -O2 CSEs `entry & 0xFFFF` into a callee-saved copy and sinks
   the iGpffffb3d4 base load past the multiply (nd 287, object 428 of 416);
   level 1 restores the per-site andi and retail's load-first order. Same
   recipe as cmmPersonaInfoShow below, including the integer-domain
   ((u32)off + (u32)base) add. */
#pragma optimization_level 1
s32 cmmPersonaInfoLookupShow(void)
{
    s32 count;
    u16 vals[0xE];
    s32 entry;
    s32 candidateIndex;
    s32 mesMgr;
    s32 i;
    s32 j;

    entry = scrGetParamInt(0);
    candidateIndex = scrGetParamInt(1);
    mesMgr = scrGetMessageManager();
    if (mesMgr < 0) {
        kAssertFail(&D_006359F0, 0x16D);
    }
    if (entry == 0) {
        entry = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    entry = cmmArcanaCandidateAt(entry & 0xFFFF, datCalcGetLevelById(1), candidateIndex);
    if (entry != 0) {
        u8 *base = iGpffffb3d4;
        s32 off = entry * 14;
        itfMesWindowFormatValue(mesMgr, 0, *(u8 *)((u32)off + (u32)base + 3), 0);
        itfMesWindowSetString(mesMgr, 1, datPersonaGetRow(entry & 0xFFFF));
        for (i = 0; i < 3; i++) {
            itfMesWindowSetString(mesMgr, i + 2, &iGpffffa62c);
        }
        datPersonaCollectSkills(entry & 0xFFFF, vals, &count);
        for (j = 0; j < count; j++) {
            itfMesWindowSetString(mesMgr, j + 2, func_00243840(vals[j]));
        }
    }
    scrSetReturnInt(entry);
    return 1;
}
/* measured: closes the level 1 scope above; -O2 is the baseline everywhere
   else in this translation unit. */
#pragma optimization_level 2

/* measured: -O2 CSEs `entry & 0xFFFF` into a callee-saved copy (andi $s0);
   level 1 restores the per-site andi. The base hoist (u8 *base = iGpffffb3d4)
   reproduces retail's load-first-into-$v1 and the integer-domain add
   ((u32)off + (u32)base) reproduces the index-first addu $v0,$v0,$v1. */
// Persona info show: fills the message slots (name row, stat strings) for the persona entry in arg 0.
/* script command 0x3021 (no p4flow name) */
// FUN_0024A8B0
#pragma optimization_level 1

s32 cmmPersonaInfoShow(void)
{
    s32 count;
    u16 vals[0xE];
    s32 entry;
    s32 mesMgr;
    s32 i;
    s32 j;

    entry = scrGetParamInt(0);
    mesMgr = scrGetMessageManager();
    if (mesMgr < 0) {
        kAssertFail(&D_006359F0, 0x190);
    }
    if (entry != 0) {
        u8 *base = iGpffffb3d4;
        s32 off = entry * 14;
        itfMesWindowFormatValue(mesMgr, 0, *(u8 *)((u32)off + (u32)base + 3), 0);
        itfMesWindowSetString(mesMgr, 1, datPersonaGetRow(entry & 0xFFFF));
        for (i = 0; i < 3; i++) {
            itfMesWindowSetString(mesMgr, i + 2, &iGpffffa62c);
        }
        datPersonaCollectSkills(entry & 0xFFFF, vals, &count);
        for (j = 0; j < count; j++) {
            itfMesWindowSetString(mesMgr, j + 2, func_00243840(vals[j]));
        }
    }
    scrSetReturnInt(entry);
    return 1;
}
#pragma optimization_level 2
// Script entry select: makes the entry in arg 0 the current one; 0 selects the current entry.
/* script command 0x3014 (no p4flow name) */
// FUN_0024AA10
s32 cmmScriptSelectEntry(void)
{
    s32 id;

    id = scrGetParamInt(0);
    if (id == 0) {
        id = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunityAdvanceForm(id & 0xFFFF);
    return 1;
}
// Script message-stream check: returns 1 when cmmMsgStreamEntry finds a record for kind arg 0 and community id arg 1 (0 uses the current community), else 0.
/* script command 0x3015 (no p4flow name) */
// FUN_0024AA60
s32 cmmScriptHasMsgStreamEntry(void)
{
    s32 kind;
    s32 communityId;

    kind = scrGetParamInt(0);
    communityId = scrGetParamInt(1);
    if (communityId == 0) {
        communityId = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    if (cmmMsgStreamEntry(kind & 0xFFFF, communityId & 0xFFFF) != 0) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}
// Script set current entry: sets the current entry to arg 0, or clears it when arg 0 is 0.
/* script command 0x3016 (no p4flow name) */
// FUN_0024AAF0
s32 cmmScriptSetCurrentEntry(void)
{
    s32 id;

    id = scrGetParamInt(0);
    if (id == 0) {
        datDestroyTaskByName();
    } else {
        cmmCommunitySetCurrent(id & 0xFFFF);
    }
    return 1;
}




// Script top reversed community: sets the script result to cmmTopReversedCommunity's id (0 when none is reversed and at rank).
/* script command 0x3017 (no p4flow name) */
// FUN_0024AB40
u32 cmmScriptTopReversedCommunity(void)
{
    u16 value;

    value = cmmTopReversedCommunity();
    scrSetReturnInt(value);
    return 1;
}

// Script top persona of arcana: sets the script result to cmmTopPersonaOfArcana for the given community id (the current community when 0).
/* script command 0x3019 (no p4flow name) */
// FUN_0024AB70
s32 cmmScriptTopPersonaOfArcana(void)
{
    s32 id;
    s32 result;

    id = scrGetParamInt(0);
    if (id == 0) {
        id = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    result = cmmTopPersonaOfArcana((s16)id);
    if (result != 0) {
        scrSetReturnInt(result);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}




// Script fresh reverse candidate: sets the script result to cmmFindFreshReverseCandidate's community id (0 when none).
/* script command 0x301A (no p4flow name) */
// FUN_0024ABF0
u32 cmmScriptFindFreshReverseCandidate(void)
{
    u16 value;

    value = cmmFindFreshReverseCandidate();
    scrSetReturnInt(value);
    return 1;
}



// Script reverse candidate: sets the script result to cmmFindReverseCandidate's community id (0 when none).
/* script command 0x3023 (no p4flow name) */
// FUN_0024AC20
u32 cmmScriptFindReverseCandidate(void)
{
    u16 value;

    value = cmmFindReverseCandidate();
    scrSetReturnInt(value);
    return 1;
}

// Marks the community named by arg 0, or the current community when arg 0 is 0.
/* script command 0x301D (no p4flow name) */
// FUN_0024AC50
s32 cmmScriptSetMarkedCommunity(void)
{
    s32 id;

    id = scrGetParamInt(0);
    if (id == 0) {
        id = cmmCommunityGetCurrentId() & 0xFFFF;
    }
    cmmCommunitySetMarked(id & 0xFFFF);
    return 1;
}
// Returns the counterpart id of the community named by arg 0.
/* script command 0x3022 (no p4flow name) */
// FUN_0024ACA0
s32 cmmScriptResolveCounterpart(void)
{
    scrSetReturnInt(cmmResolveCounterpart((s16)(scrGetParamInt(0) & 0xFFFF)));
    return 1;
}




// Script slot in group: for group 0 or 1, returns the first set entry of that group (1 or 2 for group 0, 3 or 4 for group 1), or 0 when none is set. Other groups return 1 with 0 as the result.
/* script command 0x302B (no p4flow name) */
// FUN_0024ACF0
s32 cmmScriptFindSlotInGroup(void)
{
    s32 group;

    group = scrGetParamInt(0);
    scrSetReturnInt(0);
    if ((group != 0) && (group != 1)) {
        return 1;
    }
    scrSetReturnInt(cmmCommunityFindActiveSlotInGroup(group));
    return 1;
}



// Script entry total: adds the value of the entry in arg 0 to the running total (D_00797560).
/* script command 0x301E (no p4flow name) */
// FUN_0024AD70
s32 cmmScriptAddEntryTotal(void)
{
    cmmCommunityAddTotal(cmmCommunityGetCurrentEntryValue(scrGetParamInt(0) & 0xFFFF));
    return 1;
}



// Script total take: returns the running total (D_00797560), resets it through datResetTotalBtl, and runs the total hook datAddMoney with the value.
/* script command 0x301F (no p4flow name) */
// FUN_0024ADB0
s32 cmmScriptTakeTotal(void)
{
    s32 value;

    value = cmmCommunityGetTotal();
    scrSetReturnInt(value);
    datResetTotalBtl();
    datAddMoney(value);
    return 1;
}



// Script entry lookup: returns the value stored for the current entry through cmmCommunityGetCurrentEntryValue. The script's argument 0 is passed on, but the definition takes no argument.
/* script command 0x3020 (no p4flow name) */
// FUN_0024AE00
s32 cmmScriptGetEntryIndex(void)
{
    scrSetReturnInt(cmmCommunityGetCurrentEntryValue(scrGetParamInt(0) & 0xFFFF));
    return 1;
}



// Returns the index of the current date in the date table.
/* script command 0x303C (no p4flow name) */
// FUN_0024AE40
s32 cmmScriptDateTableIndex(void)
{
    scrSetReturnInt(cmmDateTableFindIndex(datGetDateIndex()));
    return 1;
}



// Returns whether the current date has an entry in the date table.
/* script command 0x3026 (no p4flow name) */
// FUN_0024AE80
s32 cmmScriptDateTableHasEntry(void)
{
    scrSetReturnInt(cmmDateTableHasEntry(datGetDateIndex()) != 0);
    return 1;
}



// Returns whether the current date has a special record in the date table.
/* script command 0x3027 (no p4flow name) */
// FUN_0024AEC0
s32 cmmScriptDateTableHasSpecialRecord(void)
{
    scrSetReturnInt(cmmDateTableHasSpecialRecord(datGetDateIndex()) != 0);
    return 1;
}



// Reads a date-table column for the current date: arg 0 picks table 0 or 1, arg 1 picks the field (0 or 1); other values return 0.
/* script command 0x3028 (no p4flow name) */
// FUN_0024AF00
s32 cmmScriptDateTableReadColumn(void)
{
    s32 tableIndex;
    s32 column;

    tableIndex = scrGetParamInt(0);
    column = scrGetParamInt(1);
    scrSetReturnInt(0);
    if ((column != 0) && (column != 1)) {
        return 1;
    }
    if (tableIndex == 0) {
        scrSetReturnInt(cmmDateTableReadColumn(0, datGetDateIndex(), column));
    } else {
        scrSetReturnInt(cmmDateTableReadColumn(1, datGetDateIndex(), column));
    }
    return 1;
}



// Applies the column delta for arg 0 (0 or 1) to the current date's date-table entry.
/* script command 0x3029 (no p4flow name) */
// FUN_0024AFE0
s32 cmmScriptDateTableApplyColumnDelta(void)
{
    s32 column;

    column = scrGetParamInt(0);
    scrSetReturnInt(0);
    if ((column != 0) && (column != 1)) {
        return 1;
    }
    scrSetReturnInt(cmmDateTableApplyColumnDelta(datGetDateIndex(), column));
    return 1;
}

// Script item info show: fills the message window with the item record's names and numbers.
/* script command 0x302A (no p4flow name) */
// FUN_0024B070
s32 cmmItemInfoShow(void)
{
    /* The date record holds item/count pairs at +4/+8/+0x14/+0x18 and selectors at +0x10/+0x20; typed access changed MWCC codegen. */
    s32 rec;
    s32 mesMgr;
    s32 slot;
    u8 buf[0x80];
    u8* p;

    rec = scrGetParamInt(0);
    slot = datGetDateIndex();
    if (rec == 0) {
        rec = cmmDateTableFindRecord(slot);
    } else {
        rec = cmmDateTableFindSpecialRecord(slot);
    }
    if (rec == 0) {
        kAssertFail(D_006359F0, 0x27A);
    }
    mesMgr = scrGetMessageManager();
    if (mesMgr < 0) {
        kAssertFail(D_006359F0, 0x27D);
    }
    itfMesWindowSetString(mesMgr, 0, datGetItemNameId(*(s16*)(rec + 4)));
    itfMesWindowSetString(mesMgr, 2, datGetItemNameId(*(s16*)(rec + 8)));
    itfMesWindowSetString(mesMgr, 4, datGetItemNameId(*(s16*)(rec + 0x14)));
    itfMesWindowSetString(mesMgr, 6, datGetItemNameId(*(s16*)(rec + 0x18)));
    itfMesWindowSetNumber(mesMgr, 0xE, *(u16*)(rec + 4));
    itfMesWindowSetNumber(mesMgr, 0xF, *(u16*)(rec + 8));
    itfMesWindowSetNumber(mesMgr, 0x10, *(u16*)(rec + 0x14));
    itfMesWindowSetNumber(mesMgr, 0x11, *(u16*)(rec + 0x18));
    itfMesWindowFormatValue(mesMgr, 1, *(s16*)(rec + 6), 0);
    itfMesWindowFormatValue(mesMgr, 3, *(s16*)(rec + 0xA), 0);
    itfMesWindowFormatValue(mesMgr, 5, *(s16*)(rec + 0x16), 0);
    itfMesWindowFormatValue(mesMgr, 7, *(s16*)(rec + 0x1A), 0);
    itfMesWindowFormatValue(mesMgr, 8, *(u32*)(rec + 0xC), 0);
    itfMesWindowFormatValue(mesMgr, 9, *(u32*)(rec + 0x1C), 0);
    p = (u8*)cmmItemDescRecordOrNull(*(u16*)(rec + 0x12));
    if (p != 0) {
        frFontExCopyString(p, buf, 0x80);
        itfMesWindowSetString(mesMgr, 0xA, buf);
    }
    p = (u8*)cmmItemDescRecordOrNull(*(u16*)(rec + 0x22));
    if (p != 0) {
        frFontExCopyString(p, buf, 0x80);
        itfMesWindowSetString(mesMgr, 0xB, buf);
    }
    p = (u8*)cmmItemExtraRecordOrNull(*(u16*)(rec + 0x10));
    if (p != 0) {
        frFontExCopyString(p, buf, 0x80);
        itfMesWindowSetString(mesMgr, 0xC, buf);
    }
    p = (u8*)cmmItemExtraRecordOrNull(*(u16*)(rec + 0x20));
    if (p != 0) {
        frFontExCopyString(p, buf, 0x80);
        itfMesWindowSetString(mesMgr, 0xD, buf);
    }
    return 1;
}
// Starts the rank-up sequence (cmmRankUpSequenceStart) with the three script parameters when no command timer is running; returns 0 while the sequence is pending and 1 once the lookup task has finished [inferred].
/* script command 0x302C (p4flow CMM_RANKUP) */
// FUN_0024B380
s32 cmmScriptRankUp(void)
{
    s32 communityId;
    s32 rank;
    s32 resourceId;

    communityId = scrGetParamInt(0);
    rank = scrGetParamInt(1);
    resourceId = scrGetParamInt(2);
    if (scrGetCmdTimer() == 0) {
        cmmRankUpSequenceStart(0, communityId, rank, resourceId);
        goto block_4;
    }
    if (K_Cmd_TASK_LOOKUP() == 0) {
        return 1;
    }
block_4:
    return 0;
}
// Adds arg 1 to the date-table count selected by arg 0.
// FUN_0024B430
/* script command 0x302D (no p4flow name) */
s32 cmmScriptDateTableAddCount(void)
{
    s32 entryIndex;
    s32 delta;

    entryIndex = scrGetParamInt(0);
    delta = scrGetParamInt(1);
    scrSetReturnInt(cmmDateTableAddCount(entryIndex, delta));
    return 1;
}
/* measured: -O2 CSEs `id & 0xFFFF` into callee-saved copies (frame 0xF0);
   level 1 restores the per-site andi/0xD0 frame. Loop temps need decl
   order src, dst, i (first-declared -> $a1 at level 1) and the s8 loads
   need an s32 local (s8 adds a move + dsll32/dsra32 re-extension). */
// Script record info show: fills the message window slots for the record id with its name, the strings from D_00635A20, and its numbers.
/* script command 0x302E (no p4flow name) */
// FUN_0024B490
#pragma optimization_level 1

s32 cmmRecordInfoShow(void)
{
    s32 mesMgr;
    s32 id;
    u8 buf[0x80];
    s32 tbl[5];
    u8* q;
    s32* src;
    s32* dst;
    s32 i;
    s32 tmp;
    s32 tblIdx;

    id = scrGetParamInt(0);
    src = D_00635A20;
    dst = tbl;
    i = 5;
    do {
        tmp = *src++;
        i--;
        *dst++ = tmp;
    } while (i > 0);
    mesMgr = scrGetMessageManager();
    if (mesMgr < 0) {
        kAssertFail(D_006359F0, 0x2DC);
    }
    q = (u8*)cmmItemInfoRecord(id & 0xFFFF) + 0xC;
    if (q != 0) {
        frFontExCopyString(q, buf, 0x80);
        itfMesWindowSetString(mesMgr, 0, buf);
    }
    itfMesWindowFormatValue(mesMgr, 1, ((CmmItemInfoRecord *)cmmItemInfoRecord(id & 0xFFFF))->value, 0);
    q = (u8*)cmmItemInfoRecord(id & 0xFFFF) + 0x22;
    if (q != 0) {
        frFontExCopyString(q, buf, 0x80);
        itfMesWindowSetString(mesMgr, 2, buf);
    }
    tblIdx = ((CmmItemInfoRecord *)cmmItemInfoRecord(id & 0xFFFF))->tableIndexA;
    if (tblIdx != -1) {
        frFontExCopyString(tbl[tblIdx], buf, 0x80);
        itfMesWindowSetString(mesMgr, 3, buf);
    }
    itfMesWindowFormatValue(mesMgr, 4, ((CmmItemInfoRecord *)cmmItemInfoRecord(id & 0xFFFF))->valueB, 0);
    tblIdx = ((CmmItemInfoRecord *)cmmItemInfoRecord(id & 0xFFFF))->tableIndexB;
    if (tblIdx != -1) {
        frFontExCopyString(tbl[tblIdx], buf, 0x80);
        itfMesWindowSetString(mesMgr, 5, buf);
    }
    itfMesWindowFormatValue(mesMgr, 6, ((CmmItemInfoRecord *)cmmItemInfoRecord(id & 0xFFFF))->valueC, 0);
    return 1;
}
#pragma optimization_level 2
// Returns the index of the Nth matching date-table entry (arg 2) for args 0 and 1.
/* script command 0x302F (no p4flow name) */
// FUN_0024B6A0
s32 cmmScriptDateTableFindNthMatch(void)
{
    s32 kind;
    s32 value;
    s32 matchIndex;

    kind = scrGetParamInt(0);
    value = scrGetParamInt(1);
    matchIndex = scrGetParamInt(2);
    scrSetReturnInt(cmmDateTableFindNthMatch(kind, value, matchIndex));
    return 1;
}
// Script record field: returns one field of the record for the id (0 and 3 read 32-bit values, 1, 2, 4, and 5 read bytes; anything else asserts).
/* script command 0x3030 (no p4flow name) */
// FUN_0024B720
/* The shared CmmItemInfoRecord keeps its leading word byte-backed; read that opaque word without changing the shared header. */
s32 cmmRecordGetField(void)
{
    s32 id;
    s32 field;
    u8* rec;

    id = scrGetParamInt(0);
    field = scrGetParamInt(1);
    if (id == 0) {
        kAssertFail(D_006359F0, 0x30A);
    }
    rec = cmmItemInfoRecord(id & 0xFFFF);
    if (rec == 0) {
        kAssertFail(D_006359F0, 0x30C);
    }
    switch (field) {
    case 0:
        scrSetReturnInt(((CmmItemInfoRecord *)rec)->value);
        break;
    case 1:
        scrSetReturnInt(((CmmItemInfoRecord *)rec)->tableIndexA);
        break;
    case 2:
        scrSetReturnInt(((CmmItemInfoRecord *)rec)->tableIndexB);
        break;
    case 3:
        scrSetReturnInt(*(s32 *)((CmmItemInfoRecord *)rec)->unk_00);
        break;
    case 4:
        scrSetReturnInt(((CmmItemInfoRecord *)rec)->valueB);
        break;
    case 5:
        scrSetReturnInt(((CmmItemInfoRecord *)rec)->valueC);
        break;
    default:
        kAssertFail(D_006359F0, 0x321);
        break;
    }
    return 1;
}
// Script load step: state machine that starts the CDVD file load, waits for it, adopts the sprite blob, and waits for the blob to finish. State 5 is done.
// FUN_0024B870
s32 cmmScriptLoadStep(u8 *task)
{
    CmmScriptTask *t;
    s32 resourceSize;
    s32 loadId;
    s32 state;

    t = (CmmScriptTask *)(s32)kwlnTaskGetWork(task);
    state = t->state;
    switch (state) {
    case 0:
        t->state = 1;
    case 1:
        t->state = 2;
        func_00440b68(&iGpffffa658, D_006359F0, 0x35D);
        t->cdvdHandle = (s32)H_Cdvd_AcquireDirectory(D_00635A40, 1);
    case 2:
        if (H_Cdvd_IsFileLoaded((u8*)t->cdvdHandle) != 0) {
            t->state = 3;
            t->flags |= 1;
        }
        break;
    case 3:
        t->state = 4;
        loadId = H_Cdvd_LookupRequest(D_00635A60, (u32*)&resourceSize);
        if (loadId != 0) {
            t->data = (s32)sdkSpriteAdoptBlob((u32)loadId);
        }
    case 4:
        if (func_0046a750(t->data) != 0) {
            t->state = 5;
        }
        break;
    case 5:
        break;
    }
    return 0;
}
// Script task destroy: tears down the five slot handles, the loaded blob, and the CDVD handle, then calls the task-destroy hook.
// FUN_0024B990
void cmmScriptTaskDestroy(u8 *task)
{
    /* CmmScriptTask proves the five handles at +0xC; typed array indexing changed retail address addition. */
    CmmScriptTask *t;
    s32 h;
    s32 i;
    s32 x;

    t = (CmmScriptTask *)(s32)kwlnTaskGetWork(task);
    for (i = 0; i < 5; i++) {
        h = *(s32*)((u8*)t + i * 4 + 0xC);
        if (h != 0) {
            if (kwlnTaskIsLinked(h) != 0) {
                kwlnTaskDestroyWithHierarchy(h);
            }
        }
    }
    x = t->data;
    if (x != 0) {
        sdkSpriteRelease((u8*)x);
        t->data = 0;
    }
    H_Cdvd_Destroy((u8*)t->cdvdHandle);
    DAT_008873ec_abs[0]((u8*)t);
}
// Script handle clear: destroys the hierarchy in slot arg0 (0-4) and clears the slot.
// FUN_0024BA60
void cmmScriptTaskDestroyHandle(s32 slotIndex)
{
    s32 task;
    CmmScriptTask *t;

    task = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
    if (slotIndex < 0 || slotIndex >= 5) {
        kAssertFail(D_006359F0, 0x3B2);
    }
    if (task != 0) {
        t = (CmmScriptTask *)((int)(s32)kwlnTaskGetWork((void *)(u32)(task)));
        if (t->handles[slotIndex] != 0) {
            kwlnTaskDestroyWithHierarchy(t->handles[slotIndex]);
            t->handles[slotIndex] = 0;
        }
    }
}
// Script handle spawn: replaces the handle in slot arg0 (0-4) with a new sprite for that slot, placed at the stored origin (D_00635A88); slot 3 is raised by 10 units.
// FUN_0024BB00
/* measured: O1 probe for global-load scheduling; revert if it does not match. */
#pragma optimization_level 1
/* Retain the split-stack position transfer and index-first slot addressing used by this measured matching body. */
s32 cmmScriptSpawnHandle(s32 slotIndex) {
    extern s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask* task);
    extern s32 H_Cdvd_LookupRequest(s32 slotIndex, s32* secondInput);
    extern s32 func_0025ff60(s32 slotIndex);
    s64 pos;
    f32 originZ;
    s32 resourceSize;
    s32 task;
    s32 loadTask;
    s32* handleSlot;
    s32* slotBase;
    s32 firstEffect;
    s32 secondEffect;
    s32 thirdEffect;
    s32 fourthEffect;
    s32 fourthModel;
    s32 fifthEffect;
    s32 oldHandle;
    u8 loaded;
    s64 posXY;
    f32 posZ;
    task = (s32)(s32)kwlnTaskGetTaskByName((s8 *)((s8*)&D_00635A78));
    posXY = *(s64*)D_00635A88;
    posZ = *(f32*)(D_00635A88 + 8);
    pos = posXY;
    originZ = posZ;
    *(f32*)((u8*)&pos + 8) = originZ;
    loadTask = (s32)(s32)kwlnTaskGetTaskByName((s8 *)((s8*)&D_00635A78));
    if (loadTask == 0) {
        kAssertFail(&D_006359F0, 0x392);
    }
    loaded = (*(u32*)(s32)kwlnTaskGetWork((void *)(u32)((void*)loadTask)) & 1U) != 0;
    if (!loaded) {
        kAssertFail(&D_006359F0, 0x3CD);
    }
    handleSlot = (s32*)(s32)kwlnTaskGetWork((void *)(u32)((void*)task));
    if (slotIndex < 0 || slotIndex >= 5) {
        kAssertFail(&D_006359F0, 0x3CF);
    }
    slotBase = (s32*)((u32)(slotIndex << 2) + (u32)handleSlot);
    handleSlot = slotBase + 3;
    oldHandle = slotBase[3];
    if (oldHandle != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask*)(uintptr_t)oldHandle);
    }
    switch (slotIndex) {
    case 0:
        firstEffect = shdEffectTaskCreate(task, H_Cdvd_LookupRequest((s32)(uintptr_t)&D_00635AA0, &resourceSize), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(firstEffect)), (f32 *)((void*)&pos));
        *handleSlot = firstEffect;
        break;
    case 1:
        secondEffect = shdEffectTaskCreate(task, H_Cdvd_LookupRequest((s32)(uintptr_t)&D_00635AC0, &resourceSize), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(secondEffect)), (f32 *)((void*)&pos));
        *handleSlot = secondEffect;
        break;
    case 2:
        thirdEffect = shdEffectTaskCreate(task, H_Cdvd_LookupRequest((s32)(uintptr_t)&D_00635AE0, &resourceSize), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(thirdEffect)), (f32 *)((void*)&pos));
        *handleSlot = thirdEffect;
        break;
    case 3:
        fourthEffect = shdEffectTaskCreate(task, H_Cdvd_LookupRequest((s32)(uintptr_t)&D_00635B00, &resourceSize), 0, &D_005DC7D0);
        fourthModel = func_0025ff60(fourthEffect);
        (*(f32*)((u8*)&pos + 4)) -= 10.0f;
        func_004b1250((void *)(u32)(fourthModel), (f32 *)((void*)&pos));
        *handleSlot = fourthEffect;
        break;
    case 4:
        fifthEffect = shdEffectTaskCreate(task, H_Cdvd_LookupRequest((s32)(uintptr_t)&D_00635B20, &resourceSize), 0, &D_005DC7D0);
        func_004b1250((void *)(u32)(func_0025ff60(fifthEffect)), (f32 *)((void*)&pos));
        *handleSlot = fifthEffect;
        break;
    }
    return 0;
}
/* measured: restore the translation-unit optimization level after cmmScriptSpawnHandle. */
#pragma optimization_level 2
/* The month provider advances by 72 bytes: four rows of six signed weather
   weights precede four 12-byte attributes (also read by cmmScriptReadMonthProfile).
   The selection loop walks a `cursor` copy of the weather row. That copy use
   keeps `weights` a declared local instead of folding into its address
   temporary, so it takes retail's $s2; `cumulativeWeight` declared before
   `choiceIndex` gives the $s1/$s0 pair. */
// Script weather roll: picks the day's weather from the month's weighted weather row (a day-of-week-5 slot and a holiday each move the row by one), stores it in the task, and returns the chosen index. Entry 0 counts only while flag 2703 is set.
// FUN_0024BE40
s32 cmmWeatherRoll(void)
{

    s32 month;
    s32 result;
    CmmScriptTask *task;
    s32 weightIndex;
    f32 randomValue;
    CmmWeatherRow *weights;
    s32 isHoliday;
    s8 *cursor;
    s32 day;
    f32 threshold;
    s32 category;
    CmmMonthProfile *profile;
    s32 cumulativeWeight;
    s32 choiceIndex;
    f32 totalWeight;

    isHoliday = 0;
    category = 0;
    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    profile = (CmmMonthProfile *)cmmMonthProfileRecord((u16)month);
    if ((datGetTimeSlot() & 0xFF) == 5) {
        category = 2;
    }
    if ((s8)calGetDayEntryByPhase(datGetDateIndex(), datGetTimeSlot() & 0xFF) == 1) {
        isHoliday = 1;
    }
    category = category + isHoliday;
    result = 0;
    weightIndex = 0;
    {
        weights = &profile->weather[category];
        while (weightIndex < 6) {
            if ((weightIndex != 0) || (datGetFlag(2703) != 0)) {
                result += weights->weight[weightIndex];
            }
            weightIndex++;
        }
        randomValue = (f32)(u32)RpRandom();
        randomValue /= 2147483648.0f;
        totalWeight = (f32)(u32)result;
        threshold = totalWeight * randomValue;
        result = (u32)threshold;
        cumulativeWeight = 0;
        cursor = (s8 *)weights;
        choiceIndex = 0;
        while (choiceIndex < 6) {
            if ((choiceIndex != 0) || (datGetFlag(2703) != 0)) {
                cumulativeWeight += cursor[choiceIndex];
                if ((s32)result < (s32)cumulativeWeight) {
                    result = choiceIndex;
                    break;
                }
            }
            choiceIndex++;
        }
    }
    task = (CmmScriptTask *)kwlnTaskGetWork(kwlnTaskGetTaskByName((s8 *)D_00635A78));
    if (task == 0) {
        kAssertFail(D_006359F0, 1041);
    }
    task->weatherChoice = result;
    return result;
}
typedef struct cmmScriptEntry {
    u32 flags;                 /* 0x00 */
    u32 state;                 /* 0x04: task state */
    union { u32 word; s32 frame; } timer; /* 0x08: animation counter */
    union { u16 word; s16 frame; } popupTimer; /* 0x0C */
    s16 pulseFrame;             /* 0x0E */
    union { u32 word; s32 value; } selection; /* 0x10 */
    s32 (*func)(u8*, u8*);    /* 0x14 */
} cmmScriptEntry;

// Script wave sprite step: draws the wave sprite at (512, 418) for the flags in arg1 (2 slides it in, 4 fades it out) and clears the flag after ten frames. Returns 1 when the fade-out finishes.
// FUN_0024C0E0
s32 cmmScriptStepWaveSprite(u8 *unusedParent, u8 *work)
{
    /* CmmScriptEntry fields and atlas +0x24 are proven; typed members changed MWCC allocation. */
    f32 angle;
    f32 wave;
    s32 loadTask;
    s32 task;
    s32 data;
    s32 flags;
    s32 frameOrLoaded;
    s32 nextSlideFrame;
    s32 fadeFrame;
    s32 nextFadeFrame;

    task = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
    loadTask = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
    if (loadTask == 0) {
        kAssertFail(D_006359F0, 0x392);
    }
    frameOrLoaded = (*(s32 *)(s32)kwlnTaskGetWork((void *)(u32)(loadTask)) & 1) != 0;
    if (frameOrLoaded != 0) {
        goto block_1;
    }
    kAssertFail(D_006359F0, 0x39D);
block_1:
    data = *(s32 *)((u8 *)(s32)kwlnTaskGetWork((void *)(u32)(task)) + 0x24);
    flags = *(s32 *)work;
    if (flags & 2) {
        frameOrLoaded = *(s32 *)(work + 8);
        if (frameOrLoaded < 10) {
            angle = (f32)frameOrLoaded;
            angle = (iGpffff8094 * angle) / 10.0f;
            wave = sinf(angle);
        } else {
            wave = 1.0f;
        }
        sdkSpriteDrawQueued(512.0f,
                      418.0f + 200.0f * (1.0f - wave), 0.0f,
                      0xFFFFFF, 0xFF, 0, (void *)(uintptr_t)data, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
        nextSlideFrame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = nextSlideFrame;
        if (nextSlideFrame >= 10) {
            *(s32 *)work &= ~2;
            *(s32 *)(work + 8) = 0;
        }
        goto block_20;
    }
    if (flags & 4) {
        fadeFrame = *(s32 *)(work + 8);
        if (fadeFrame < 10) {
            angle = (f32)fadeFrame;
            angle = (iGpffff8094 * angle) / 10.0f;
            wave = sinf(angle);
        } else {
            wave = 1.0f;
        }
        sdkSpriteDrawQueued(512.0f, 418.0f, 0.0f,
                      0xFFFFFF,
                      (u8)(255.0f * (1.0f - wave)),
                      0, (void *)(uintptr_t)data, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
        nextFadeFrame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = nextFadeFrame;
        if (nextFadeFrame >= 10) {
            *(s32 *)work &= ~4;
            *(s32 *)(work + 8) = 0;
            return 1;
        }
    } else {
        sdkSpriteDrawQueued(512.0f, 418.0f, 0.0f,
                      0xFFFFFF, 0xFF, 0, (void *)(uintptr_t)data, 1, 0, 0,
                      -30.0f, 1.0f, 1.0f, D_00794E70);
    }
block_20:
    return 0;
}
/* Native b210 -O2 recovery: 3,464 emitted bytes in the 3,472-byte retail
   window. Full proof and callback behavior evidence are retained in
   docs/probe_archive/Community_script_recovery_20260922.md. */
// Popup banner step: when flag 2 is set, fades and scales the banner sprites in over five frames, then clears the flag.
// FUN_0024C460
s32 cmmScriptStepPopupBanner(u8 *unusedParent, u8 *work)
{
    /* CmmScriptEntry fields and atlas +0x24 are proven; typed members changed MWCC allocation. */
    u8 *task;
    u8 *loadTask;
    void *atlas;
    s32 loaded;
    s32 flags;
    s32 frame;
    s32 alpha;
    s32 sprite;
    s32 pulse;
    f32 sine;
    f32 scale;
    f32 y;

    task = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    loadTask = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    if (loadTask == 0) {
        kAssertFail(D_006359F0, 0x392);
    }
    loaded = (*(u32 *)kwlnTaskGetWork(loadTask) & 1) != 0;
    if (loaded == 0) {
        kAssertFail(D_006359F0, 0x39D);
    }
    atlas = *(void **)(kwlnTaskGetWork(task) + 0x24);
    flags = *(s32 *)work;
    if ((flags & 2) != 0) {
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            sine = 1.0f;
        }
        alpha = (s32)(255.0f * sine);
        scale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        sdkSpriteDrawQueued(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(433.0f, 139.0f - 5.0f * sine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        y = 24.0f * scale;
        y = 177.0f - y;
        sdkSpriteDrawQueued(443.0f - 60.0f * scale, y, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, y, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        y = 28.0f * scale;
        y = 177.0f - y;
        sdkSpriteDrawQueued(443.0f - 51.0f * scale, y, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, y, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)work &= ~2;
            *(s32 *)(work + 8) = 0;
        }
        goto done;
    }
    if ((flags & 4) != 0) {
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            sine = 1.0f;
        }
        alpha = (s32)(255.0f * (1.0f - sine));
        scale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        sdkSpriteDrawQueued(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(433.0f, 139.0f - 5.0f * sine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        y = 24.0f * scale;
        y = 177.0f - y;
        sdkSpriteDrawQueued(443.0f - 60.0f * scale, y, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, y, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        y = 28.0f * scale;
        y = 177.0f - y;
        sdkSpriteDrawQueued(443.0f - 51.0f * scale, y, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, y, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, scale, scale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)work &= ~4;
            *(s32 *)(work + 8) = 0;
            return 1;
        }
        goto done;
    }
    {
        f32 steadySine;
        f32 steadyScale;
        f32 steadyY;
        frame = *(s32 *)(work + 8);
        if (frame < 5) {
            steadySine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
        } else {
            steadySine = 1.0f;
        }
        alpha = 255;
        steadyScale = 1.0f + (0.5f * (f32)*(s32 *)(work + 8)) / 5.0f;
        sdkSpriteDrawQueued(433.0f, 163.0f, 0.0f, 0xFFFFFF, alpha, 1, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(433.0f, 139.0f - 5.0f * steadySine, 0.0f, 0xFFFFFF, alpha, 2, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        steadyY = 24.0f * steadyScale;
        steadyY = 177.0f - steadyY;
        sdkSpriteDrawQueued(443.0f - 60.0f * steadyScale, steadyY, 0.0f, 0xF27400, alpha, 0xC, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, steadyY, 0.0f, 0xF27400, alpha, 0xD, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        steadyY = 28.0f * steadyScale;
        steadyY = 177.0f - steadyY;
        sdkSpriteDrawQueued(443.0f - 51.0f * steadyScale, steadyY, 0.0f, 0xECF54D, alpha, 0xA, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        sdkSpriteDrawQueued(453.0f, steadyY, 0.0f, 0xECF54D, alpha, 0xB, atlas,
                       1, 0, 0, 0.0f, steadyScale, steadyScale, D_00794E70);
        frame = *(s32 *)(work + 8) + 1;
        *(s32 *)(work + 8) = frame;
        if (frame >= 5) {
            *(s32 *)(work + 8) = 0;
        }
    }
    if (*(s32 *)(work + 0x10) > 0) {
        frame = *(s16 *)(work + 0xC);
        if (frame < 5) {
            sine = sinf((iGpffff8094 * (f32)frame) / 5.0f);
            alpha = (s32)(255.0f * sine);
        } else if (frame < 20) {
            alpha = 255;
        } else if (frame < 30) {
            frame -= 20;
            sine = (f32)frame;
            sine = sinf(iGpffff8094 + (iGpffff8094 * sine) / 10.0f);
            alpha = (s32)(255.0f * sine);
        }
        sprite = *(s32 *)(work + 0x10) + 0xD;
        sdkSpriteDrawQueued(416.0f, 148.0f, 0.0f, 0xFFFFFF, alpha, sprite, atlas,
                       1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        if ((*(s32 *)work & 0x10) != 0) {
            f32 pulseScale;
            pulse = *(s16 *)(work + 0xE);
            pulseScale = 1.0f + (iGpffff809c * (f32)pulse) / 10.0f;
            sprite = *(s32 *)(work + 0x10) + 0x10;
            sine = sinf(iGpffff8094 + (iGpffff8094 * (f32)pulse) / 10.0f);
            alpha = (s32)(127.5f * sine);
            sdkSpriteDrawQueued(448.0f - 32.0f * pulseScale, 177.0f - 29.0f * pulseScale, 0.0f,
                           0xFFFFFF, alpha, sprite, atlas, 1, 0, 0, 0.0f, pulseScale, pulseScale, D_00794E70);
            *(s16 *)(work + 0xE) += 1;
            if (*(s16 *)(work + 0xE) >= 10) {
                *(s16 *)(work + 0xE) = 0;
                *(s32 *)work &= ~0x10;
            }
        }
        *(s16 *)(work + 0xC) += 1;
        if (*(s16 *)(work + 0xC) >= 30) {
            *(s16 *)(work + 0xC) = 0;
            *(s32 *)(work + 0x10) = 0;
            *(s32 *)work &= ~0x10;
        }
    }
done:
    return 0;
}
/* Keep the displacement product separate from the anchor addition. The
   retail steady animation rounds this multiplication before adding the
   sprite baseline, while its bounce expressions use the accumulator. */
static inline f32 cmmScoreProduct(f32 phase, f32 scale)
{
    f32 value;
    value = scale * phase;
    return value;
}

static inline void *cmmScoreAtlas(void)
{
    u8 *task;
    u8 *loadTask;
    s32 loaded;
    task = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    loadTask = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    if (loadTask == NULL) {
        kAssertFail(D_006359F0, 0x392);
    }
    loaded = (*(u32 *)kwlnTaskGetWork(loadTask) & 1) != 0;
    if (loaded == 0) {
        kAssertFail(D_006359F0, 0x39D);
    }
    return *(void **)(kwlnTaskGetWork(task) + 0x24);
}

static inline s32 cmmScoreClamp(s32 value, s32 first, s32 limit)
{
    if (value < first) {
        return 0;
    }
    if (value < limit) {
        return value;
    }
    return limit;
}

static inline f32 cmmScoreBounce(f32 phase, f32 extent, f32 baseline)
{
    if (phase > 0.0f) {
        return -baseline + extent * (1.0f - phase);
    }
    return phase * 10.0f + 10.0f;
}

static inline f32 cmmScoreDisplacement(f32 phase, f32 negative, f32 positive)
{
    if (phase < 0.0f) {
        return negative * phase;
    }
    return positive * phase;
}

// Score display step: animates the score digits with the cmmScoreBounce and cmmScoreDisplacement motion.
// FUN_0024D1F0
s32 cmmScriptStepScoreDisplay(u8 *parent, u8 *work)
{
    /* CmmScriptEntry timer/flags are proven; typed members changed MWCC allocation. */
    extern f32 sinf(f32);
    extern u8 *resourceFindByName(char *name);
    extern s32 datItemCount(s16);
    extern u8 D_005E5850[];
    extern f32 iGpffff81dc;
    extern f32 iGpffff81e0;
    void *atlas;
    void *digitsAtlas;
    f32 fadePhase;
    f32 bounceHeight;
    s32 fade;
    s32 frame;
    s32 phaseFrame;
    s32 score;

    atlas = cmmScoreAtlas();
    digitsAtlas = resourceFindByName((char *)D_005E5850);
    if ((*(u32 *)work & 2) != 0) {
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 60.0f, 50.0f);
        sdkSpriteDrawQueued(44.0f, bounceHeight + 10.0f, 0.0f, 0x6EB3, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        sdkSpriteDrawQueued(26.0f, bounceHeight + 135.0f, 0.0f, 0x50B6, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 10);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        sdkSpriteDrawQueued(15.0f, bounceHeight + 199.0f, 0.0f, 0x63B3, fade, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0xF) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 10;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 10.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        sdkSpriteDrawQueued(132.0f, bounceHeight + 12.0f, 0.0f, 0x6CB3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(91.0f, bounceHeight + 32.0f, 0.0f, 0x57B3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(34.0f, bounceHeight + 161.0f, 0.0f, 0x2BB3, fade, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0x14);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 20.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        sdkSpriteDrawQueued(11.0f, bounceHeight + 27.0f, 0.0f, 0x6AB3, fade, 7, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 5) {
            phaseFrame = 0;
        } else if (frame < 0x14) {
            phaseFrame = frame - 5;
        } else {
            phaseFrame = 0xF;
        }
        fadePhase = sinf((iGpffff8094 * (f32)phaseFrame) / 15.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 30.0f, 20.0f);
        sdkSpriteDrawQueued(67.0f, bounceHeight + 11.0f, 0.0f, 0x2078, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0xF);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 15.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 20.0f, 10.0f);
        sdkSpriteDrawQueued(8.0f, bounceHeight + 52.0f, 0.0f, 0x2346, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 3, 0x11);
        fadePhase = sinf((iGpffff8094 * (f32)frame) / 17.0f);
        fade = (s32)(fadePhase * 255.0f);
        bounceHeight = sinf(iGpffff8084 * fadePhase + iGpffff8094);
        bounceHeight = cmmScoreBounce(bounceHeight, 40.0f, 30.0f);
        sdkSpriteDrawQueued(59.0f, bounceHeight + 121.0f, 0.0f, 0xC52, fade, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = 0.0f;
        } else if (frame < 0xF) {
            fadePhase = sinf((iGpffff8094 * ((f32)frame - 10.0f)) / 5.0f);
        } else {
            fadePhase = 1.0f;
        }
        sdkSpriteDrawQueued(30.0f, (1.0f - fadePhase) * 27.5f + 66.0f, 0.0f, 0x7AFEFF, 0xFF, 5, atlas, 1, 0, 0, 0.0f, 1.0f, fadePhase, D_00794E70);
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = 0.0f;
        } else {
            fadePhase = sinf((iGpffff8094 * (f32)(frame - 10)) / 10.0f);
        }
        fade = (s32)(fadePhase * 255.0f);
        score = datItemCount(0x3F8) & 0xFF;
        if (score < 10) {
            sdkSpriteDrawQueued(47.0f, 83.0f, 0.0f, 0, fade, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            sdkSpriteDrawQueued(37.0f, 83.0f, 0.0f, 0, fade, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            sdkSpriteDrawQueued(59.0f, 83.0f, 0.0f, 0, fade, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        sdkSpriteDrawQueued(70.0f, 55.0f, 0.0f, 0x7AFEFF, fade, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        frame = cmmScoreClamp(frame, 0, 0x14);
        {
            f32 result;

            fadePhase = sinf(iGpffff8094 + (iGpffff8084 * (f32)frame) / 20.0f);
            if (fadePhase > 0.0f) {
                result = -150.0f + 170.0f * (1.0f - fadePhase);
            } else {
                bounceHeight = sinf(iGpffff8084 * -fadePhase + iGpffff8094);
                if (bounceHeight > 0.0f) {
                    result = 20.0f - (1.0f - bounceHeight) * 24.0f;
                } else {
                    result = -4.0f - bounceHeight * 4.0f;
                }
            }
            sdkSpriteDrawQueued(13.0f, result - 2.0f, 0.0f, 0, 0xFF, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        frame = *(u32 *)(work + 8) + 1;
        *(u32 *)(work + 8) = frame;
        if (frame >= 20) {
            *(u32 *)work &= ~2;
            *(u32 *)(work + 8) = 0;
        }
    } else if ((*(u32 *)work & 4) != 0) {
        frame = *(u32 *)(work + 8);
        if (frame < 10) {
            fadePhase = sinf((iGpffff8094 * (f32)frame) / 10.0f);
        } else {
            fadePhase = 1.0f;
        }
        fade = (s32)((1.0f - fadePhase) * 255.0f);
        sdkSpriteDrawQueued(30.0f, 66.0f, 0.0f, 0x7AFEFF, fade, 5, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        score = datItemCount(0x3F8) & 0xFF;
        if (score < 10) {
            sdkSpriteDrawQueued(47.0f, 83.0f, 0.0f, 0, fade, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            sdkSpriteDrawQueued(37.0f, 83.0f, 0.0f, 0, fade, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            sdkSpriteDrawQueued(59.0f, 83.0f, 0.0f, 0, fade, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        sdkSpriteDrawQueued(70.0f, 55.0f, 0.0f, 0x7AFEFF, fade, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(13.0f, -2.0f, 0.0f, 0, fade, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8) + 1;
        *(u32 *)(work + 8) = frame;
        if (frame >= 10) {
            *(u32 *)work &= ~4;
            *(u32 *)(work + 8) = 0;
            return 1;
        }
    } else {
        f32 phase;
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 60)) / 60.0f);
        phase = (phase + 1.0f) / 2.0f;
        sdkSpriteDrawQueued(44.0f, 10.0f + cmmScoreDisplacement(phase, 2.0f, 5.0f), 0.0f, 0x6EB3, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(26.0f, 135.0f + cmmScoreProduct(phase, 5.0f), 0.0f, 0x50B6, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(15.0f, 199.0f + cmmScoreDisplacement(phase, 6.0f, 3.0f), 0.0f, 0x63B3, 0xFF, 9, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 80)) / 80.0f);
        phase = (phase + 1.0f) / 2.0f;
        sdkSpriteDrawQueued(132.0f, 12.0f + cmmScoreDisplacement(phase, 5.0f, 3.0f), 0.0f, 0x6CB3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(91.0f, 32.0f + cmmScoreDisplacement(phase, 2.0f, 5.0f), 0.0f, 0x57B3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(34.0f, 161.0f + cmmScoreDisplacement(phase, 4.0f, 2.0f), 0.0f, 0x2BB3, 0xFF, 8, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 100)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        sdkSpriteDrawQueued(11.0f, 27.0f + cmmScoreDisplacement(phase, 4.0f, 10.0f), 0.0f, 0x6AB3, 0xFF, 7, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 100)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        sdkSpriteDrawQueued(67.0f, 11.0f + cmmScoreDisplacement(phase, 10.0f, 4.0f), 0.0f, 0x2078, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        phase = sinf(iGpffff81dc + (iGpffff81e0 * (f32)(*(s32 *)(work + 8) % 120)) / 100.0f);
        phase = (phase + 1.0f) / 2.0f;
        sdkSpriteDrawQueued(8.0f, 52.0f + cmmScoreDisplacement(phase, 8.0f, 2.0f), 0.0f, 0x2346, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(59.0f, 121.0f + cmmScoreDisplacement(phase, 10.0f, 6.0f), 0.0f, 0xC52, 0xFF, 6, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(30.0f, 66.0f, 0.0f, 0x7AFEFF, 0xFF, 5, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        score = datItemCount(0x3F8) & 0xFF;
        if (score < 10) {
            sdkSpriteDrawQueued(47.0f, 83.0f, 0.0f, 0, 0xFF, score + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        } else {
            sdkSpriteDrawQueued(37.0f, 83.0f, 0.0f, 0, 0xFF, score / 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
            sdkSpriteDrawQueued(59.0f, 83.0f, 0.0f, 0, 0xFF, score % 10 + 0x1D, digitsAtlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        }
        sdkSpriteDrawQueued(70.0f, 55.0f, 0.0f, 0x7AFEFF, 0xFF, 4, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued(13.0f, -2.0f, 0.0f, 0, 0xFF, 3, atlas, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        frame = *(u32 *)(work + 8);
        *(u32 *)(work + 8) = frame + 1;
        if ((s32)(frame + 1) >= 0x7FFFFFFF) {
            *(u32 *)(work + 8) = 0;
        }
    }
    return 0;
}


// Script entry run: calls the callback of each of the three entries whose active flag (bit 0) is set, and clears that flag when the callback returns nonzero.
// FUN_0024EFA0
s32 cmmScriptRunEntries(u8 *task)
{
    cmmScriptEntry* entries;
    cmmScriptEntry* entry;
    s32 i;

    entries = (cmmScriptEntry*)(s32)kwlnTaskGetWork(task);
    entry = entries;
    i = 0;
    while (i < 3) {
        if ((entry->flags & 1) != 0) {
            if (entry->func((u8 *)entries, (u8 *)entry) != 0) {
                entry->flags = entry->flags & ~1;
            }
        }
        entry++;
        i++;
    }
    return 0;
}




// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).

// Script entries destroy: frees the three-entry work block of the entries task.
// FUN_0024F040
void cmmScriptEntriesDestroy(u8 *task)
{
    int record;

    record = (s32)kwlnTaskGetWork(task);
    DAT_008873ec_abs[0](record);
}

// Script entry arm: sets the active flag on entry arg0 and resets its counters. arg1 == 0 selects flag 4, otherwise flag 2 (the two modes that cmmScriptEntryUpdate reads).
// FUN_0024F080
void cmmScriptArmEntry(s32 entryIndex, s32 show)
{
    cmmScriptEntry* e;
    s32 p;

    p = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635B38));
    if (p == 0) {
        kAssertFail(D_006359F0, 0x67E);
    }
    e = (cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(p)) + entryIndex;
    e->flags |= 1;
    e->timer.word = 0;
    e->state = 0;
    e->popupTimer.word = 0;
    e->selection.word = 0;
    if (show == 0) {
        e->flags = e->flags & ~2;
        e->flags = e->flags | 4;
    } else {
        e->flags = e->flags & ~4;
        e->flags = e->flags | 2;
    }
}
// Fishing round step: state 0 resets the round (clears the bite flags, spawns handles, arms entries 2 and 0, rolls the weather and date values); later steps count the catch timer and, after the third bite, a random roll or the tenth bite sets flag 0x40 to start the bite sequence.
// FUN_0024F160
s32 cmmScriptStepFishingRound(u8 *work)
{
    /* The 0x24-byte work has word flags/state and halfword bite timers at +0xC..0x12; typed access changed MWCC codegen. */
    s32 result;
    s32 i;
    s32 id;
    s32 task;
    s32 loadTask;
    s32 rec;
    s32 state;
    s32 resource;
    s32 signal;
    s32 loaded;
    u32 random;
    f32 value;
    u8 color[4];
    u8 pos[12];
    u8 *entry;

    result = 0;
    switch (*(s32 *)(work + 8)) {
    case 0:
        *(s32 *)(work + 8) = 1;
        *(s32 *)work &= ~4;
        *(s32 *)work &= ~0x10;
        *(s32 *)work &= ~0x20;
        *(s32 *)work &= ~0x40;
        for (i = 0; i < 5; i++) {
            cmmScriptTaskDestroyHandle(i);
        }
        cmmScriptSpawnHandle(3);
        cmmScriptSpawnHandle(1);
        cmmScriptArmEntry(2, 1);
        cmmScriptArmEntry(0, 1);
        id = cmmWeatherRoll();
        cmmFishingEntryRecord((u16)id);
        *(s16 *)(work + 0xE) = cmmDateTableRollValue(id);
    case 1:
        break;
    default:
        goto done;
    }

    rec = (s32)kwlnTaskGetWork((void *)(u32)((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78))));
    if (rec == 0) {
        kAssertFail(D_006359F0, 0x41B);
    }
    id = *(s32 *)(rec + 0x20);
    entry = cmmFishingEntryRecord((u16)id);
    *(s16 *)(work + 0xC) += 1;
    if (*(s16 *)(work + 0xC) >= *(s16 *)(work + 0xE)) {
        *(s16 *)(work + 0xC) = 0;
        *(s16 *)(work + 0xE) = cmmDateTableRollValue(id);
        cmmScriptSpawnHandle(4);
        *(s16 *)(work + 0x10) += 1;
        cmmDateTableRunEffect(id);
        state = *(s16 *)(work + 0x10);
        if (state >= 3) {
            if (state >= 10 ||
                (random = (u32)RpRandom(),
                 (f32)random / 2147483648.0f > iGpffff809c)) {
                *(s32 *)work |= 0x40;
                *(s16 *)(work + 0x12) = 0;
            }
        }
    }

    signal = 0;
    if ((*(s32 *)work & 0x40) != 0) {
        *(s16 *)(work + 0x12) += 1;
        state = *(s16 *)(work + 0x12);
        if (state == 1) {
            datEntryDrawGatedByFlag39(5, 61, 10, 0);
            sdkSndStartChannel((s16)(2), (const char *)(D_00635B50));
        }

        task = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
        loadTask = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
        if (loadTask == 0) {
            kAssertFail(D_006359F0, 0x392);
        }
        loaded = (*(s32 *)(s32)kwlnTaskGetWork((void *)(u32)(loadTask)) & 1) != 0;
        if (loaded == 0) {
            kAssertFail(D_006359F0, 0x3A6);
        }
        rec = (s32)kwlnTaskGetWork((void *)(u32)(task));
        if (*(s32 *)(rec + 0x18) != 0) {
            resource = func_0025ff60(*(s32 *)(rec + 0x18));
        } else {
            resource = 0;
        }
        if (resource != 0) {
            mdlEffectGetPackedColor(resource, color);
            mdlEffectGetPosition(resource, pos);
            value = sinf((iGpffff8084 * (f32)state) /
                                  (f32)*(s16 *)(entry + 4));
            *(f32 *)(pos + 4) = -55.0f - (20.0f * value);
            color[3] = (u8)(255.0f * (1.0f - value));
            mdlEffectSetPackedColor(resource, color);
            func_004b1250((void *)(u32)(resource), (f32 *)(pos));
        }
        if (state <= *(s16 *)(entry + 4)) {
            signal = 1;
        } else {
            signal = 2;
        }
    }

    if (signal == 2 || (D_008C024E[0] & 0x20) != 0) {
        if (signal == 0) {
            result = 3;
        } else {
            result = signal;
        }
    }
    if (result == 0) {
        goto done;
    }

    if ((rec = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78))) != 0) {
        rec = (s32)kwlnTaskGetWork((void *)(u32)(rec));
        if (*(s32 *)(rec + 0x10) != 0) {
            kwlnTaskDestroyWithHierarchy(*(s32 *)(rec + 0x10));
            *(s32 *)(rec + 0x10) = 0;
        }
    }
    if ((rec = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78))) != 0) {
        rec = (s32)kwlnTaskGetWork((void *)(u32)(rec));
        if (*(s32 *)(rec + 0x18) != 0) {
            kwlnTaskDestroyWithHierarchy(*(s32 *)(rec + 0x18));
            *(s32 *)(rec + 0x18) = 0;
        }
    }
    cmmScriptSpawnHandle(2);
    cmmScriptArmEntry(0, 0);

    switch (result) {
    case 0:
        break;
    case 1:
        datEntryDrawGatedByFlag39(10, 101, 10, 0);
        *(s32 *)work |= 0x10;
        break;
    case 2:
        datEntryDrawGatedByFlag39(3, 120, 1, 0);
        break;
    case 3:
        *(s32 *)work |= 0x20;
        break;
    }
    *(s32 *)work |= 4;
    return 1;

done:
    return 0;
}
static inline f32 cmmFishingBlend(f32 delta, f32 ratio, f32 origin)
{
    return 0.0f + origin + delta * ratio;
}

// Fishing aim step: state 0 clears the catch flags, spawns the handles, arms entry 1, and picks a random 90-to-449-frame countdown to the next direction prompt; later steps update progress from direction input.
// FUN_0024F790
s32 cmmScriptStepFishingAim(u8 *work)
{
    /* The 0x24-byte work has progress at +0x14 and halfword direction timers at +0x1C..0x22; typed access changed MWCC codegen. */
    s32 i;
    u8 *task;
    u8 *loadTask;
    u8 *fishingData;
    s32 flags;
    s32 model;
    s32 direction;
    s16 currentDirection;
    s16 frameCount;
    s32 loaded;
    s32 directionPressed;
    u32 random;
    f32 randomFloat;
    f32 scaledRandom;
    u32 scaledCount;
    f32 ratio;
    CmmFishingPosition start;
    CmmFishingPosition finish;
    CmmFishingPosition result;
    u8 *fishEntry;

    switch (*(s32 *)(work + 8)) {
    case 0:
        *(s32 *)(work + 8) = 1;
        *(s32 *)work &= ~8;
        *(s32 *)work &= ~0x80;
        for (i = 0; i < 5; i++) {
            cmmScriptTaskDestroyHandle(i);
        }
        cmmScriptSpawnHandle(0);
        cmmScriptArmEntry(1, 1);
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 360.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1C) = (s16)(scaledCount + 90);
    case 1:
        break;
    default:
        goto done;
    }

    fishingData = (u8 *)kwlnTaskGetWork(kwlnTaskGetTaskByName((s8 *)D_00635A78));
    if (fishingData == 0) {
        kAssertFail(D_006359F0, 0x41B);
    }
    fishEntry = cmmFishingEntryRecord(*(u16 *)(fishingData + 0x20));
    if ((*(s16 *)(work + 0xC) % 60) == 0) {
        sdkSndStartChannel(2, (const char *)D_00635B90);
    }
    *(s16 *)(work + 0xC) += 1;
    if ((*(s16 *)(work + 0xC) % 20) == 0) {
        datEntryDrawGatedByFlag39(1, 0x50, 1, 0);
    }
    if (*(s16 *)(work + 0x1C) == 0) {
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 360.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1C) = (s16)(scaledCount + 90);
        random = RpRandom();
        randomFloat = (f32)random;
        scaledRandom = 3.0f * (randomFloat / 2147483648.0f);
        scaledCount = (u32)scaledRandom;
        *(s16 *)(work + 0x1E) = (s16)(scaledCount + 1);
        direction = *(s16 *)(work + 0x1E);
        {
            u8 *directionTask;

            directionTask = kwlnTaskGetTaskByName((s8 *)D_00635B38);
            if (directionTask == 0) {
                kAssertFail(D_006359F0, 0x696);
            }
            *(s32 *)(kwlnTaskGetWork(directionTask) + 0x28) = direction;
        }
        *(s32 *)work |= 0x10;
        *(s16 *)(work + 0x22) = 0x19;
    } else {
        *(s16 *)(work + 0x1C) = *(s16 *)(work + 0x1C) - 1;
    }
    if ((*(s32 *)work & 0x10) != 0) {
        directionPressed = 0;
        currentDirection = *(s16 *)(work + 0x1E);
        switch (currentDirection) {
        case 1:
            if ((D_008C024E[0] & 0x10) != 0) {
                directionPressed = 1;
            }
            break;
        case 2:
            if ((D_008C024E[0] & 0x80) != 0) {
                directionPressed = 1;
            }
            break;
        case 3:
            if ((D_008C024E[0] & 0x40) != 0) {
                directionPressed = 1;
            }
            break;
        }
        if (directionPressed != 0) {
            sdkSndStartStream(0, 0, 4, 3);
            task = kwlnTaskGetTaskByName((s8 *)D_00635B38);
            if (task == 0) {
                kAssertFail(D_006359F0, 0x6A2);
            }
            *(s32 *)(kwlnTaskGetWork(task) + 0x18) |= 0x10;
            flags = *(s32 *)work & ~0x10;
            *(s32 *)work = flags;
            *(s32 *)work = flags | 0x20;
            *(s16 *)(work + 0x20) = 0;
            *(s16 *)(work + 0x22) = 0;
        } else {
            *(s16 *)(work + 0x22) = *(s16 *)(work + 0x22) - 1;
        }
        if (*(s16 *)(work + 0x22) <= 0) {
            *(s32 *)work &= ~0x10;
        }
    }
    if ((*(s32 *)work & 0x20) != 0) {
        *(s16 *)(work + 0x20) += 1;
        if (*(s16 *)(work + 0x20) >= 10) {
            *(s32 *)work &= ~0x20;
            *(s16 *)(work + 0x20) = 0;
        }
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 2;
    }
    start = D_00635B68.value;
    finish = D_00635B78.value;
    ratio = (f32)*(s32 *)(work + 0x14) / (f32)*(s16 *)(fishEntry + 8);
    {
        f32 delta = finish.value[0] - start.value[0];
        f32 origin = start.value[0];
        result.value[0] = cmmFishingBlend(delta, ratio, origin);
    }
    {
        f32 delta = finish.value[1] - start.value[1];
        f32 origin = start.value[1];
        result.value[1] = cmmFishingBlend(delta, ratio, origin);
    }
    {
        f32 delta = finish.value[2] - start.value[2];
        f32 origin = start.value[2];
        result.value[2] = cmmFishingBlend(delta, ratio, origin);
    }
    task = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    loadTask = kwlnTaskGetTaskByName((s8 *)D_00635A78);
    if (loadTask == 0) {
        kAssertFail(D_006359F0, 0x392);
    }
    loaded = (*(s32 *)kwlnTaskGetWork(loadTask) & 1) != 0;
    if (loaded == 0) {
        kAssertFail(D_006359F0, 0x3A6);
    }
    fishingData = (u8 *)kwlnTaskGetWork(task);
    if (*(s32 *)(fishingData + 0xC) != 0) {
        model = func_0025ff60(*(s32 *)(fishingData + 0xC));
    } else {
        model = 0;
    }
    func_004b1250((void *)(u32)model, result.value);
    if ((D_008C024E[0] & 0x20) != 0) {
        datEntryDrawGatedByFlag39(3, 0x79, 3, 0);
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
    }
    if ((*(s16 *)(work + 0xC) % *(s16 *)(fishEntry + 0xA)) == 0) {
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) - 1;
    }
    frameCount = *(s16 *)(work + 0xC);
    if (frameCount >= 0x1E && *(s32 *)(work + 0x14) >= *(s16 *)(fishEntry + 8)) {
        datEntryDrawGatedByFlag39(5, 0xC9, 5, 0);
        *(s32 *)(work + 4) = 2;
        flags = *(s32 *)work | 8;
        *(s32 *)work = flags;
        *(s32 *)work = flags | 0x80;
        cmmScriptArmEntry(1, 0);
    } else if (frameCount >= *(s16 *)(fishEntry + 0xC) || *(s32 *)(work + 0x14) < -10) {
        *(s32 *)(work + 4) = 2;
        *(s32 *)work |= 8;
        cmmScriptArmEntry(1, 0);
    }
done:
    return 0;
}
// Script entry update: state machine for one entry. Waits for the script task's loaded flag, then runs the step routine cmmScriptStepFishingRound (state 5) or cmmScriptStepFishingAim (state 7) until it returns nonzero.
// FUN_0024FF60
s32 cmmScriptEntryUpdate(u8 *task)
{
    cmmScriptEntry* e;
    s32 loadTask;
    s32 st;

    e = (cmmScriptEntry*)(s32)kwlnTaskGetWork(task);
    switch (e->state) {
    case 0:
        e->state = 1;
    case 1:
        e->state = 2;
    case 2:
        loadTask = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
        if (loadTask == 0) {
            kAssertFail(D_006359F0, 0x392);
        }
        st = (((cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(loadTask)))->flags & 1) != 0;
        if (st) {
            e->state = 3;
        }
        break;
    case 3:
        st = e->flags;
        if (st & 1) {
            e->flags = st & ~1;
            e->state = 4;
        } else if (st & 2) {
            e->flags = st & ~2;
            e->state = 6;
        }
        break;
    case 4:
        e->state = 5;
        e->timer.word = 0;
    case 5:
        if (cmmScriptStepFishingRound((u8*)e) != 0) {
            e->state = 3;
        }
        break;
    case 6:
        e->state = 7;
        e->timer.word = 0;
    case 7:
        if (cmmScriptStepFishingAim((u8*)e) != 0) {
            e->state = 3;
        }
        break;
    }
    return 0;
}

// Script entry destroy: frees the entry work block of the entry task.
// FUN_002500E0
void cmmScriptEntryDestroy(u8 *task)
{
    int record;

    record = (s32)kwlnTaskGetWork(task);
    DAT_008873ec_abs[0](record);
}

// Starts the entry tasks: creates the load task and the entry runner, sets the step callbacks, and destroys any stale entry-task handles.
/* script command 0x3036 (no p4flow name) */
// FUN_00250120
s32 cmmScriptStartEntries(void)
{
    s32 i;
    s32 handle;
    u8* parent;
    u8* e;

    handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8));
    if (handle != 0) {
        kwlnTaskDestroyWithHierarchy(handle);
    }
    if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
        parent = evtEnsureEventTask();
        if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
            chkmemAllocSiteTag(D_006359F0, 0x402);
            e = D_008873F4[0](1, 0x28, 0x40000);
            ((CmmScriptTask *)e)->state = 0;
            (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635A78), 0xF, 0, 0, cmmScriptLoadStep, cmmScriptTaskDestroy, (u8 *)(e));
        }
    }
    parent = evtEnsureEventTask();
    handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635B38));
    if (handle != 0) {
        kwlnTaskDestroyWithHierarchy(handle);
    }
    chkmemAllocSiteTag(D_006359F0, 0x66C);
    e = D_008873F4[0](1, 0x5C, 0x40000);
    ((cmmScriptEntry *)e)[0].func = cmmScriptStepWaveSprite;
    ((cmmScriptEntry *)e)[1].func = cmmScriptStepPopupBanner;
    ((cmmScriptEntry *)e)[2].func = cmmScriptStepScoreDisplay;
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635B38), 0xF, 0, 0, cmmScriptRunEntries, cmmScriptEntriesDestroy, (u8 *)(e));
    for (i = 0; i < 5; i++) {
        cmmScriptTaskDestroyHandle(i);
    }
    return 1;
}

// Entry choice: the first call arms the entry (flag 1) and waits; once status bit 4 is set it returns 0, 1 (bit 0x10), or 2 (bit 0x20) and destroys the entry task.
/* script command 0x3034 (no p4flow name) */
// FUN_002502F0
s32 cmmScriptPollEntryChoice(void)
{
    u8* parent;
    cmmScriptEntry* e;
    s32 handle;
    s32 st;
    s32 ret;

    if (scrGetCmdTimer() == 0) {
        parent = evtEnsureEventTask();
        if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8)) == 0) {
            if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
                if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
                    chkmemAllocSiteTag(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->state = 0;
                    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635A78), 0xF, 0, 0, cmmScriptLoadStep, cmmScriptTaskDestroy, (u8 *)(e));
                }
            }
            chkmemAllocSiteTag(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->state = 0;
            (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635BA8), 0xF, 0, 0, cmmScriptEntryUpdate, cmmScriptEntryDestroy, (u8 *)(e));
        }
        handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8));
        if (handle == 0) {
            kAssertFail(D_006359F0, 0x82A);
        }
        e = (cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(handle));
        e->flags |= 1;
    } else {
        handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8));
        if (handle == 0) {
            kAssertFail(D_006359F0, 0x83E);
        }
        e = (cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(handle));
        st = e->flags;
        if (st & 4) {
            if (st & 0x10) {
                ret = 2;
            } else if (st & 0x20) {
                ret = 3;
            } else {
                ret = 1;
            }
        } else {
            ret = 0;
        }
        if (ret != 0) {
            scrSetReturnInt(ret - 1);
            kwlnTaskDestroyWithHierarchy((s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8)));
            return 1;
        }
    }
    return 0;
}
// Entry confirm: the first call arms the entry (flag 2) and waits; once status bit 8 is set it returns 1 if bit 0x80 is also set (0 otherwise) and destroys the entry task.
/* script command 0x3035 (no p4flow name) */
// FUN_00250560
s32 cmmScriptPollEntryConfirm(void)
{
    u8* parent;
    cmmScriptEntry* e;
    s32 handle;
    s32 st;
    s32 ret;

    if (scrGetCmdTimer() == 0) {
        parent = evtEnsureEventTask();
        if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8)) == 0) {
            if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
                if ((s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78)) == 0) {
                    chkmemAllocSiteTag(D_006359F0, 0x402);
                    e = (cmmScriptEntry*)D_008873F4[0](1, 0x28, 0x40000);
                    e->state = 0;
                    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635A78), 0xF, 0, 0, cmmScriptLoadStep, cmmScriptTaskDestroy, (u8 *)(e));
                }
            }
            chkmemAllocSiteTag(D_006359F0, 0x81D);
            e = (cmmScriptEntry*)D_008873F4[0](1, 0x24, 0x40000);
            e->state = 0;
            (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00635BA8), 0xF, 0, 0, cmmScriptEntryUpdate, cmmScriptEntryDestroy, (u8 *)(e));
        }
        handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8));
        if (handle == 0) {
            kAssertFail(D_006359F0, 0x834);
        }
        e = (cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(handle));
        e->flags |= 2;
    } else {
        handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8));
        if (handle == 0) {
            kAssertFail(D_006359F0, 0x84E);
        }
        e = (cmmScriptEntry*)(s32)kwlnTaskGetWork((void *)(u32)(handle));
        st = e->flags;
        if (st & 8) {
            if (st & 0x80) {
                ret = 2;
            } else {
                ret = 1;
            }
        } else {
            ret = 0;
        }
        if (ret != 0) {
            scrSetReturnInt(ret - 1);
            kwlnTaskDestroyWithHierarchy((s32)kwlnTaskGetTaskByName((s8 *)(D_00635BA8)));
            return 1;
        }
    }
    return 0;
}
// Closes the entry channel: on the first call arms entry 2 and destroys the entry tasks; once the entry timer reaches 30 frames it fades channel 2 out over 30 frames and returns 1.
/* script command 0x3037 (no p4flow name) */
// FUN_002507C0
s32 cmmScriptStopEntries(void)
{
    s32 i;

    if (scrGetCmdTimer() == 0) {
        cmmScriptArmEntry(2, 0);
        for (i = 0; i < 5; i++) {
            cmmScriptTaskDestroyHandle(i);
        }
        goto ret0;
    }
    if (scrGetCmdTimer() < 30) {
        goto ret0;
    }
    sdkSndFadeOutChannelFrames(2, 0, 0x1E);
    return 1;
ret0:
    return 0;
}
// Returns the six-entry table value (table copied from D_00635BB8) selected by the index at +0x20 of the entry record.
/* script command 0x3038 (no p4flow name) */
// FUN_00250870
s32 cmmScriptReadIndexedValue(void)
{
    s16 buf[6];
    s16* s;
    s16* d;
    s32 i;
    s32 handle;
    u8* rec;
    s32 idx;

    s = D_00635BB8;
    d = buf;
    i = 3;
    do {
        s16 a = s[0];
        s16 b = s[1];
        s += 2;
        i--;
        d[0] = a;
        d[1] = b;
        d += 2;
    } while (i > 0);
    handle = (s32)kwlnTaskGetTaskByName((s8 *)(D_00635A78));
    rec = (u8*)(s32)kwlnTaskGetWork((void *)(u32)(handle));
    if (rec == 0) {
        kAssertFail(D_006359F0, 0x41B);
    }
    idx = ((CmmScriptTask *)rec)->weatherChoice;
    if (idx >= 6) {
        kAssertFail(D_006359F0, 0x8A9);
    }
    scrSetReturnInt(buf[idx]);
    return 1;
}
// Returns field arg 1 of row arg 0 in the month-profile record for the current date: 0 and 1 are u16 values at +0x18 and +0x1A, 2 and 3 are s32 values at +0x1C and +0x20; rows are 12 bytes.
/* script command 0x303B (no p4flow name) */
// FUN_00250940
s32 cmmScriptReadMonthProfile(void)
{
    /* CmmMonthProfile rows are proven; typed indexing changed retail index-first address addition. */
    s32 field;
    s32 row;
    u8* table;
    s32 out1;
    s32 out2;

    row = scrGetParamInt(0);
    field = scrGetParamInt(1);
    calSplitDayOfYear(datGetDateIndex(), &out1, &out2);
    table = (u8 *)cmmMonthProfileRecord((u16)out1);
    if (table == 0) {
        kAssertFail(D_006359F0, 0x8B8);
    }
    if (field < 0 || !(field <= 3)) {
        kAssertFail(D_006359F0, 0x8B9);
    }
    switch (field) {
    case 0: {
        s32 idx = row * 12;
        scrSetReturnInt(*(u16*)(idx + (s32)table + 0x18));
        break;
    }
    case 1: {
        s32 idx = row * 12;
        scrSetReturnInt(*(u16*)(idx + (s32)table + 0x1A));
        break;
    }
    case 2: {
        s32 idx = row * 12;
        scrSetReturnInt(*(s32*)(idx + (s32)table + 0x1C));
        break;
    }
    case 3: {
        s32 idx = row * 12;
        scrSetReturnInt(*(s32*)(idx + (s32)table + 0x20));
        break;
    }
    }
    return 1;
}
