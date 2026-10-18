/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/battle.c; members 00353b50-0035c670 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
extern void datCommunityEntryStep(u8 *arg0);
extern void nmMesWindowDestroySlot(s8 arg0);
extern void (*D_008873EC[])(void *);
extern void datTextSlotRelease();
extern s32 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s64 arg0);
extern s32 datMemberIsUnlocked(s64 arg0);
extern s32 datGetFlag(s32 arg0);
extern u8 *kwlnTaskGetTaskByName(const void *arg0);
extern u8 D_0064B320[];
extern void datMemberNoticeSetup(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_0064B3B0[];
extern u8 D_0064B3D0[];
extern s32 datScreenWipeUpdate(u8 *arg0);
extern void datScreenWipeDestroy(u8 *arg0);
extern void strncpy(void *dst, const void *src, u32 size);
extern f32 RwV3dNormalize(void *out, const void *in);
extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void nmMesWindowReleaseHandle(s32 arg0);
extern s32 cmmKindRecord(u16 arg0);
extern void kAssertFail(const void *module, u32 line);
extern void sprintf(void *dst, const void *fmt, ...);
extern u8 D_0064CCF0[];
extern u8 D_0064CD10[];
extern u32 D_0064B310[];
extern u8 D_0064B3F0[];
extern u8 D_0064CC60[];
extern u8 D_0064CC70[];
extern u8 D_0064CC78[];
extern f32 D_00761260;
typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;

extern void datScreenWipeInit(u8 *arg0, Float2 *arg1, Float2 *arg2);
extern void datScreenWipeSetScale(u8 *arg0, u8 *arg1);
extern void datScreenWipeSetTextureId(u8 *arg0, u16 arg1);
static inline void interpolation_accumulate(f32 *total, f32 weight, f32 projection)
{
    *total += weight * projection;
}

static inline u32 add_offset_first(u32 offset, u32 base)
{
    return offset + base;
}

extern s32 nLineIsIdle(void);
extern u32 D_0064B1E0[];
extern void func_004672c0(s32 arg0, s32 arg1);
extern void H_Cdvd_Destroy(u8 *arg0);
extern void func_003ef3a0(void *arg0);
extern void memset(void *dst, s32 value, s32 size);
extern void datGridEffectSetLayout(u8 *arg0, s64 arg1);
extern void datGridEffectDraw(u8 *arg0, u8 *arg1);
extern void datPortraitSetValue(u8 *arg0, s8 arg1, s32 arg2);
extern void datPortraitSetLabel(s32 arg0, u16 arg1, s32 arg2);
extern void radarAnimateValue(void *arg0, s32 arg1, s32 arg2);
extern s32 datPortraitUpdate(u8 *arg0);
extern void datPortraitDestroy(u8 *arg0);
extern u8 D_0064CC98[];
extern u8 D_0064CD40[];
extern u8 D_0064CCB0[];
extern u8 D_0064CCD0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_00440b68();
extern s32 H_Cdvd_AcquireDirectory(u8 *arg0, s32 arg1);
extern s32 H_Cdvd_IsFileLoaded(s32 arg0);
extern s32 filerEnqueueRequest();
extern s32 filerTakeCompletedRequest(s32 arg0, void *arg1, s32 arg2);
extern u8 iGpffffa960;
extern u8 D_0064B360[];
extern u8 D_0064B380[];
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);
extern u8 D_0064B410[];
extern s32 datGridEffectUpdate(u8 *arg0);
extern void datGridEffectDestroy(u8 *arg0);
extern void datGridEffectInit(u8 *arg0, s64 arg1, s32 arg2);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern f32 iGpffff83d4;
extern f32 iGpffff8544;
extern f32 sinf(f32 arg0);
extern f32 fGpffff84a4;
extern void nmMesWindowStepCurrent(s32 arg0);
extern s32 nmMesWindowCurrentOpenState(void);
extern void nmMesWindowCloseCurrent(s32 arg0);
extern void nmMesWindowStepSlot(s32 arg0, s32 arg1);
extern s32 nmMesWindowSlotStatus(s8 arg0);
extern void nmMesWindowCloseSlot(s8 arg0, s32 arg1);
extern s32 nmMesWindowResetCurrent(void);
extern s32 fclMiscEnsureMesWindow(const void *arg0);
extern s32 fclMesWindowShowItemRecord(s32 arg0);
extern u8 D_0064A790[];
extern void resrcMngSetRenderSuppressed(s32 arg0);
extern s32 FldStepNotAtBoundary(void);
extern void nLineSetActive(s32 arg0);
extern s32 nLineGetCurrentSet(void);
extern s64 datGetPartyId(s32 arg0);
// Intent: Build the list of party member ids from the first three party slots, with the count in the first entry [inferred]
// FUN_00353B50
s16 datBuildPartyIdList(s16 *arg0)
{
    s16 len;
    s16 partyId;
    s32 i;

    len = 1;
    *arg0 = 1;
    for (i = 0; i < 3; i++) {
        partyId = datGetPartyId(i);
        if (partyId != 0) {
            ((s16 *)arg0)[len] = partyId;
            len++;
        }
    }
    if (len <= 4) {
        goto done;
    }
    kAssertFail(&D_0064B310, 0x259);
done:
    return len;
}

// Intent: Build the list of member ids from 2 to 8 that are unlocked, with the count in the first entry [inferred]
// FUN_00353C10
s16 datBuildMemberIdList(s16 *arg0)
{
    s16 len;
    s16 memberId;
    s32 i;

    len = 1;
    *arg0 = 1;
    for (i = 1; i < 8; i++) {
        memberId = (s16)(i + 1);
        if (datMemberIsUnlocked(memberId) != 0) {
            ((s16 *)arg0)[len] = memberId;
            len++;
        }
    }
    if (len <= 8) {
        goto done;
    }
    kAssertFail(&D_0064B310, 0x26F);
done:
    return len;
}

// Intent: Build the list of unlocked member ids from 2 to 8, leaving out member 5, with the count in the first entry [inferred]
// FUN_00353CE0
s16 datBuildMemberIdListExcluding5(s16 *arg0)
{
    s16 len;
    s16 memberId;
    s32 i;

    len = 1;
    *arg0 = 1;
    for (i = 1; i < 8; i++) {
        memberId = (s16)(i + 1);
        if (memberId == 5) {
            goto skip;
        }
        if (datMemberIsUnlocked(memberId) != 0) {
            ((s16 *)arg0)[len] = memberId;
            len++;
        }
skip:
        ;
    }
    if (len <= 8) {
        goto done;
    }
    kAssertFail(&D_0064B310, 0x286);
done:
    return len;
}

// Intent: Report whether a member id is unlocked by its story flag; member 1 is always unlocked [inferred]
// FUN_00353DC0
s32 datMemberIsUnlocked(s64 arg0)
{
    s64 value;
    s32 result;

    result = 0;
    value = (s16)arg0;
    if ((value <= 0) || (value >= 0xB)) {
        kAssertFail(&D_0064B310, 0x292);
    }
    switch (value) {
    case 1:
        result = 1;
        break;
    case 2:
        if (datGetFlag(0x30) != 0) {
            result = 1;
        }
        break;
    case 3:
        if (datGetFlag(0x31) != 0) {
            result = 1;
        }
        break;
    case 4:
        if (datGetFlag(0x32) != 0) {
            result = 1;
        }
        break;
    case 5:
        if (datGetFlag(0x34) != 0) {
            result = 1;
        }
        break;
    case 6:
        if (datGetFlag(0x33) != 0) {
            result = 1;
        }
        break;
    case 8:
        if (datGetFlag(0x35) != 0) {
            result = 1;
        }
        break;
    case 7:
        if (datGetFlag(0x36) != 0) {
            result = 1;
        }
        break;
    default:
        kAssertFail(&D_0064B310, 0x2B0);
        break;
    }
    return result;
}

// Intent: Member notice channel poll: prepare the channel and return 1 while it is busy; when it is idle, release it and return 0 [inferred]
// FUN_00353F50
s32 datMemberNoticeTryBegin(s32 arg0)
{
    nmMesWindowStepCurrent(arg0);
    if (nmMesWindowCurrentOpenState() == 0) {
        nmMesWindowCloseCurrent(arg0);
        return 0;
    }
    return 1;
}

// Intent: Unsuppress resource rendering [inferred]
// FUN_00353FB0
void resrcMngUnsuppressRender(void)
{
    resrcMngSetRenderSuppressed(0);
}

// Intent: Suppress resource rendering [inferred]
// FUN_00353FE0
void resrcMngSuppressRender(void)
{
    resrcMngSetRenderSuppressed(1);
}

// Intent: Return 0 when the current step value is a band boundary, otherwise 1 [inferred]
// FUN_00354010
s32 FldStepNotAtBoundaryQuery(void)
{
    return FldStepNotAtBoundary();
}

// Intent: Request leaving the community menu: queue the exit script op, clear the fade and render state, and return the exit result [inferred]
// FUN_00354030
s32 datCommunityRequestExit(void)
{
    sdkSndStartStream(0, 2, 0, 4);
    nLineSetActive(0);
    resrcMngSetRenderSuppressed(0);
    return nLineGetCurrentSet();
}

// Intent: Queue the cursor sound for a community menu move: indices 1 and 2 use one cue, 3 and 4 use another [inferred]
// FUN_00354080
void datCommunityCursorFeedback(s32 arg0)
{
    if ((u32)(arg0 - 1) < 2U) {
        sdkSndStartStream(0, 1, 0, 0);
        return;
    }
    if ((u32)(arg0 - 3) < 2U) {
        sdkSndStartStream(0, 1, 0, 5);
    }
}

// Intent: Member notice state step: advance the notice from its opening states to its ready states, and clear the channel once it closes [inferred]
// FUN_003540F0
s32 datMemberNoticeStep(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(work + 4);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = 1;
        break;
    case 1:
        nmMesWindowStepSlot(*(s8 *)(work + 8), 1);
        if (nmMesWindowSlotStatus(*(s8 *)(work + 8)) == 0) {
            nmMesWindowCloseSlot(*(s8 *)(work + 8), 1);
            if ((*(u16 *)work & 1) != 0) {
                fclMiscEnsureMesWindow(D_0064A790);
                fclMesWindowShowItemRecord(7);
                *(s32 *)(work + 4) = 2;
            } else {
                *(s32 *)(work + 4) = 3;
            }
        }
        break;
    case 2:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            nmMesWindowResetCurrent();
            *(s32 *)(work + 4) = 3;
        }
        break;
    case 3:
        break;
    default:
        kAssertFail(&D_0064B310, 0x34A);
        break;
    }
    return 0;
}

// Intent: Free the member notice work block and release its channel [inferred]
// FUN_00354230
void datMemberNoticeDestroy(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    nmMesWindowDestroySlot(*(s8 *)(work + 8));
    (*D_008873EC)(work);
}

// Intent: Set up the member notice: set the member's notice flags, pick the message, and show the label and sub-label [inferred]
// FUN_00354280
void datMemberNoticeSetup(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 label[0x40];
    u8 subLabel[0x40];
    s32 mode;
    s32 i;
    s32 msgId;
    s32 flagId;
    extern s8 nmMesWindowAcquire(void *arg0);
    extern void datSetFlag(s32 arg0, s32 arg1);
    extern void frFontExCopyString(void *src, void *dst, s32 maxlen);
    extern s32 nmMesWindowShowSlotRecord(s8 arg0, s32 arg1);
    extern void nmMesWindowSetSlotString(s8 arg0, s32 arg1, void *arg2);
    extern u8 sdkSndStartChannel(s16 channelIndex, const char *name);
    extern u8 D_0064B340[];
    extern char iGpffffa958;
    extern u32 datMemberNameLabel(s32 arg0);

    *(s8 *)(arg0 + 8) = nmMesWindowAcquire(D_0064A790);
    if (arg2 == 0) {
        flagId = arg1 + 0x100;
        if (datGetFlag(flagId) != 0)
            kAssertFail(&D_0064B310, 0x369);
        i = 0;
        while (i < 0x40) {
            datSetFlag(i + 0x180, 0);
            i++;
        }
        datSetFlag(arg1 + 0x180, 1);
        datSetFlag(flagId, 1);
        mode = 5;
        msgId = 0x2CF;
        if (datGetFlag(0xC3) == 0) {
            *(u16 *)arg0 = *(u16 *)arg0 | 1;
            datSetFlag(0xC3, 1);
        }
    } else {
        if (datGetFlag(arg1 + 0x100) == 0)
            kAssertFail(&D_0064B310, 0x37E);
        datSetFlag(arg1 + 0x180, 0);
        datSetFlag(arg1 + 0x140, 1);
        mode = 6;
        msgId = 0x2D0;
    }
    sprintf(label, &D_0064B340, msgId);
    sdkSndStartChannel(2, (const char *)label);
    frFontExCopyString((void *)(u32)datMemberNameLabel(arg1), label, 0x40);
    nmMesWindowSetSlotString(*(s8 *)(arg0 + 8), 0, label);
    sprintf(subLabel, &iGpffffa958, arg1 + 1);
    frFontExCopyString(subLabel, label, 0x40);
    nmMesWindowSetSlotString(*(s8 *)(arg0 + 8), 1, label);
    nmMesWindowShowSlotRecord(*(s8 *)(arg0 + 8), mode);
}

// Intent: Return the name label for a member id from the label table [inferred]
// FUN_00354490
u32 datMemberNameLabel(s32 arg0)
{
    if (!(arg0 < 0x40)) {
        kAssertFail(D_0064B310, 0x3D6);
    }
    return D_0064B1E0[arg0];
}

// FUN_003544F0
s32 func_003544f0(void)
{
    return 50;
}

// Intent: Script command: open the member notice for the slot argument, or close it and return 1 once its state reaches 3 [inferred]
// FUN_00354500
s32 datMemberNoticeScriptOpen(void) {
    s32 slot;
    s32 state;
    u8 *task;
    u8 *newTask;

    if ((task = kwlnTaskGetTaskByName(&D_0064B320)) != NULL) {
        state = *(s32 *)(*(u8 **)(task + 0x38) + 4);
        if (state == 3) {
            if (state != 3) {
                kAssertFail(&D_0064B310, 0x3CC);
            }
            kwlnTaskDestroyWithHierarchy((s32)(u32)task);
            return 1;
        }
        goto block_10;
    }
    slot = scrGetParamInt(0) - 1;
    chkmemAllocSiteTag(&D_0064B310, 0x3AB);
    newTask = D_008873F4[0](1, 0x10, 0x40000);
    if (newTask == NULL) {
        kAssertFail(&D_0064B310, 0x3AC);
    }
    if (kwlnTaskCreateChild((void *)(0), (const void *)(&D_0064B320), 0xF, 0, 0, datMemberNoticeStep, datMemberNoticeDestroy, (u8 *)(newTask)) == NULL) {
        kAssertFail(&D_0064B310, 0x3B5);
    }
    datMemberNoticeSetup(newTask, slot, 0);
block_10:
    return 0;
}

// Intent: Script command: as datMemberNoticeScriptOpen, but the notice is set up in the second mode [inferred]
// FUN_00354660
s32 datMemberNoticeScriptOpenAlt(void) {
    s32 slot;
    s32 state;
    u8 *task;
    u8 *work;

    if ((task = kwlnTaskGetTaskByName(&D_0064B320)) != NULL) {
        state = *(s32 *)(*(u8 **)(task + 0x38) + 4);
        if (state == 3) {
            if (state != 3) {
                kAssertFail(&D_0064B310, 0x3CC);
            }
            kwlnTaskDestroyWithHierarchy((s32)(u32)task);
            return 1;
        }
        goto block_10_2;
    }
    slot = scrGetParamInt(0) - 1;
    chkmemAllocSiteTag(&D_0064B310, 0x3AB);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064B310, 0x3AC);
    }
    if (kwlnTaskCreateChild((void *)(0), (const void *)(&D_0064B320), 0xF, 0, 0, datMemberNoticeStep, datMemberNoticeDestroy, (u8 *)(work)) == NULL) {
        kAssertFail(&D_0064B310, 0x3B5);
    }
    datMemberNoticeSetup(work, slot, 1);
block_10_2:
    return 0;
}

// Intent: Reset the text slot and copy the string argument into it; a null string sets the slot to its empty state [inferred]
// FUN_003547C0
void datTextSlotSetString(s32 *arg0, u8 *arg1)
{
    datTextSlotRelease();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    strncpy((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}

// Intent: Text slot loading state machine: request the file named in the slot, wait for it, then create its resource and wait for the resource to finish [inferred]
// FUN_00354830
s32 datTextSlotLoadStep(u8 *arg0) {
    s32 sp3C;
    s32 handle;
    s32 state;

    state = *(s32 *)(arg0 + 0);
    switch (state) {
    case 0:
        if (kwlnTaskGetTaskByName(&D_0064B360) != NULL) {
            func_00440b68(&D_0064B380);
        } else {
            func_00440b68(&iGpffffa960, &D_0064B310, 0x433);
            handle = H_Cdvd_AcquireDirectory(arg0 + 0x10, 0);
            *(s32 *)(arg0 + 8) = handle;
            if (handle == 0) {
                kAssertFail(&D_0064B310, 0x434);
            }
            *(s32 *)(arg0 + 0) = 1;
        }
        goto block_15;
    case 1:
        if (H_Cdvd_IsFileLoaded(*(s32 *)(arg0 + 8)) != 0) {
            *(s32 *)(arg0 + 4) =
                filerEnqueueRequest(0, arg0 + 0x10, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0) = 2;
        }
        goto block_15;
    case 2:
        *(s32 *)(arg0 + 0xC) =
            filerTakeCompletedRequest(*(s32 *)(arg0 + 4), &sp3C, 0);
        if (sp3C != 0) {
            *(s32 *)(arg0 + 4) = 0;
            H_Cdvd_Destroy(*(u8 **)(arg0 + 8));
            *(s32 *)(arg0 + 8) = 0;
            *(s32 *)(arg0 + 0) = 3;
        }
        goto block_15;
    case 3:
        return 1;
    default:
        break;
    }
block_15:
    return 0;
}

// Intent: Release the text slot's file handle and resource [inferred]
// FUN_003549D0
void datTextSlotRelease(u8 *arg0)
{
    s32 handle;

    handle = *(s32 *)(arg0 + 4);
    if (handle != 0) {
        func_004672c0(handle, *(s32 *)(arg0 + 8));
        *(s32 *)(arg0 + 4) = 0;
        *(s32 *)(arg0 + 8) = 0;
        *(s32 *)(arg0 + 0xC) = 0;
        return;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        H_Cdvd_Destroy(*(u8 **)(arg0 + 8));
        *(s32 *)(arg0 + 8) = 0;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        func_003ef3a0(*(u8 **)(arg0 + 0xC));
        *(s32 *)(arg0 + 0xC) = 0;
    }
}

// Intent: Create the screen wipe task with its update and destroy callbacks, set its positions and attach the target range [inferred]
// FUN_00354A50
u8 *datScreenWipeTaskCreate(s32 arg0, u16 arg1) {
    Float2 sp48;
    u8 *task;
    u8 *work;

    chkmemAllocSiteTag(&D_0064B310, 0x48C);
    work = D_008873F4[0](1, 0x258, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_0064B3D0), 0xC7, 0, 0, datScreenWipeUpdate, datScreenWipeDestroy, (u8 *)(work));
    if (task == NULL) {
        return NULL;
    }
    *(s16 *)(work + 8) = 0;
    *(u8 *)(work + 0xA) = 0xFF;
    *(s32 *)(work + 0xC) =
        *(u8 *)(work + 0xA) | 0x2D2D2D00;
    sp48.x = 640.0f;
    sp48.y = 640.0f;
    datScreenWipeInit(task, &sp48, &sp48);
    datScreenWipeSetScale(task, NULL);
    *(s32 *)(work + 0x150) = 0;
    *(s32 *)(work + 0x148) = 0;
    *(s32 *)(work + 0x14C) = 0;
    *(void **)(work + 0x254) = (void *)&D_0064B3B0;
    datScreenWipeSetTextureId(task, arg1);
    return task;
}

// Intent: Draw one step of the screen wipe: advance its blend toward the target, then draw its quad with the render state table [inferred]
// FUN_00354BA0
void datScreenWipeDraw(u8 *arg0) {
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern f32 D_00761470;
    extern void shdDrawColourQuad(f32 depth, s32 color, f32 x, f32 y, f32 sx, f32 sy, f32 w, f32 h, s32 *tex, s32 mode, s32 flag);
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern u8 D_00887300[];
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        s32 u;
        s32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Q40;
    Q40 qs[4];
    u8 *p;
    f32 z;
    f32 q;
    s32 cnt;
    f32 ft;
    f32 blend;
    f32 sx;
    f32 sy;
    u8 alpha;
    u32 col;
    u32 base;

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
    if ((*(s32 *)(p + 0x40) == 0) || (*(u16 *)(p + 8) == 0)) {
        return;
    }
    cnt = *(s32 *)(p + 4);
    if (cnt < 100) {
        *(s32 *)(p + 4) = cnt + 1;
    }
    ft = (f32)*(s32 *)(p + 4);
    if (ft < 10.0f) {
        blend = sinf(D_00761470 * (ft / 10.0f));
    } else {
        blend = 1.0f;
    }
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x18) + blend * (*(f32 *)(p + 0x20) - *(f32 *)(p + 0x18));
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x1C) + blend * (*(f32 *)(p + 0x24) - *(f32 *)(p + 0x1C));
    *(f32 *)(p + 0x30) += (*(f32 *)(p + 0x10) - *(f32 *)(p + 0x30)) / 3.0f;
    *(f32 *)(p + 0x34) += (*(f32 *)(p + 0x14) - *(f32 *)(p + 0x34)) / 3.0f;
    alpha = *(u8 *)(p + 0xA);
    sx = 256.0f * *(f32 *)(p + 0x38);
    sy = 512.0f * *(f32 *)(p + 0x3C);
    qs[0].x = *(f32 *)(p + 0x10);
    qs[0].y = *(f32 *)(p + 0x14);
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)(u32)alpha;
    qs[0].u = 0;
    qs[0].v = 0;
    qs[0].q = q;
    qs[1].x = *(f32 *)(p + 0x10) + sx;
    qs[1].y = *(f32 *)(p + 0x14);
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)(u32)alpha;
    qs[1].u = 0x3F800000;
    qs[1].v = 0;
    qs[1].q = q;
    qs[2].x = *(f32 *)(p + 0x10);
    qs[2].y = *(f32 *)(p + 0x14) + sy;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)(u32)alpha;
    qs[2].u = 0;
    qs[2].v = 0x3F800000;
    qs[2].q = q;
    qs[3].x = *(f32 *)(p + 0x10) + sx;
    qs[3].y = *(f32 *)(p + 0x14) + sy;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)(u32)alpha;
    qs[3].u = 0x3F800000;
    qs[3].v = 0x3F800000;
    qs[3].q = q;
    shdDrawColourQuad(0.0f, (*(u32 *)(p + 0xC) & ~0xFF) | (((((*(u32 *)(p + 0xC)) & 0xFF) * 0xFF) / *(u8 *)(p + 0xA)) & 0xFF), *(f32 *)(p + 0x28) + *(f32 *)(p + 0x30), *(f32 *)(p + 0x2C) + *(f32 *)(p + 0x34), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14), sx, sy, *(s32 **)(p + 0x150), 1, 0);
    base = (u32)D_00887300;
    ((void (*)(u32, u32))*(u32 *)base)(6, 0);
    ((void (*)(u32, u32))*(u32 *)base)(7, 2);
    ((void (*)(u32, u32))*(u32 *)base)(8, 0);
    ((void (*)(u32, u32))*(u32 *)base)(9, 2);
    ((void (*)(u32, u32))*(u32 *)base)(0xC, 1);
    ((void (*)(u32, u32))*(u32 *)base)(0xB, 6);
    ((void (*)(u32, u32))*(u32 *)base)(0xA, 5);
    ((void (*)(u32, u32))*(u32 *)base)(2, 4);
    ((void (*)(u32, u32))*(u32 *)base)(0xE, 0);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    ((void (*)(u32, u32))*(u32 *)base)(1, *(*(u32 **)(p + 0x150)));
    D_00887310[0](4, &qs[0], 4);
}

// Intent: Set the screen wipe's target range from the argument, or return it to the current position when the argument is null [inferred]
// FUN_00355070
void datScreenWipeSetTarget(u8 *arg0, u8 *arg1) {
    u8 *work;

    work = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(work + 0x18) = (f32) *(f32 *)(work + 0x10);
        *(f32 *)(work + 0x1C) = (f32) *(f32 *)(work + 0x14);
        *(f32 *)(work + 0x20) = (f32) *(f32 *)(arg1 + 0);
        *(f32 *)(work + 0x24) = (f32) *(f32 *)(arg1 + 4);
    } else {
        *(f32 *)(work + 0x10) = (f32) *(f32 *)(work + 0x18);
        *(f32 *)(work + 0x14) = (f32) *(f32 *)(work + 0x1C);
        *(f32 *)(work + 0x30) = (f32) *(f32 *)(work + 0x18);
        *(f32 *)(work + 0x34) = (f32) *(f32 *)(work + 0x1C);
    }
    *(s32 *)(work + 4) = 0;
}

// Intent: Initialise the screen wipe: set its current, start and end positions and reset its step counter [inferred]
// FUN_003550D0
void datScreenWipeInit(u8 *arg0, Float2 *arg1, Float2 *arg2)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        kAssertFail(&D_0064B310, 0x53A);
    }
    if (arg2 == NULL) {
        kAssertFail(&D_0064B310, 0x53B);
    }
    *(f32 *)(work + 0x18) = arg1->x;
    *(f32 *)(work + 0x1C) = arg1->y;
    *(f32 *)(work + 0x10) = arg1->x;
    *(f32 *)(work + 0x14) = arg1->y;
    *(f32 *)(work + 0x20) = arg2->x;
    *(f32 *)(work + 0x24) = arg2->y;
    *(f32 *)(work + 0x30) = arg1->x;
    *(f32 *)(work + 0x34) = arg1->y;
    *(s32 *)(work + 4) = 0;
}

// Intent: Set the screen wipe's texture from the member id and the day suffix, releasing the old text slot when the id changes [inferred]
// FUN_00355190
void datScreenWipeSetTextureId(u8 *arg0, u16 arg1)
{
    u8 sp50[0x100];
    s32 id;
    s8 suffix;
    u8 *work;
    u8 *reloadedWork;

    work = *(u8 **)(arg0 + 0x38);
    id = arg1 & 0xFFFF;
    if (*(u16 *)(work + 8) != id) {
        if (calGetDayWindowFlags((s64)(s16)datGetDateIndex()) & 1) {
            suffix = 0x61;
        } else {
            suffix = 0x62;
        }
        if (id == 0) {
            datTextSlotRelease(work + 0x144);
            *(s32 *)(work + 0x144) = 3;
        } else {
            sprintf(sp50, &D_0064B3F0, id, suffix);
            datTextSlotRelease(work + 0x144);
            if ((u8 *)sp50 == NULL) {
                *(s32 *)(work + 0x144) = 3;
            } else {
                strncpy(work + 0x154, sp50, 0x100);
                *(s32 *)(work + 0x144) = 0;
            }
        }
        *(u16 *)(work + 8) = arg1;
        *(s32 *)(work + 0x40) = 0;
        reloadedWork = *(u8 **)(arg0 + 0x38);
        *(f32 *)(reloadedWork + 0x10) = *(f32 *)(reloadedWork + 0x18);
        *(f32 *)(reloadedWork + 0x14) = *(f32 *)(reloadedWork + 0x1C);
        *(f32 *)(reloadedWork + 0x30) = *(f32 *)(reloadedWork + 0x18);
        *(f32 *)(reloadedWork + 0x34) = *(f32 *)(reloadedWork + 0x1C);
        *(s32 *)(reloadedWork + 4) = 0;
    }
}

// Intent: Set the screen wipe's offset from the argument point [inferred]
// FUN_003552D0
void datScreenWipeSetOffset(u8 *arg0, Float2 arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);

    b[0xA] = arg1.x;
    b[0xB] = arg1.y;
}

// Intent: Set the screen wipe's colour word [inferred]
// FUN_00355300
void datScreenWipeSetColor(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = arg1;
}

// Intent: Copy the screen wipe's start, current and end positions to the output points when they are non-null [inferred]
// FUN_00355310
void datScreenWipeGetPositions(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *work;

    work = (u8 *)(*(u8 **)(arg0 + 0x38));
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32) *(f32 *)(work + 0x18);
        *(f32 *)(arg1 + 4) = (f32) *(f32 *)(work + 0x1C);
    }
    if (arg2 != NULL) {
        *(f32 *)(arg2 + 0) = (f32) *(f32 *)(work + 0x10);
        *(f32 *)(arg2 + 4) = (f32) *(f32 *)(work + 0x14);
    }
    if (arg3 != NULL) {
        *(f32 *)(arg3 + 0) = (f32) *(f32 *)(work + 0x20);
        *(f32 *)(arg3 + 4) = (f32) *(f32 *)(work + 0x24);
    }
}

// Intent: Set the screen wipe's scale from the argument, or reset it to 1.0 when the argument is null [inferred]
// FUN_00355370
void datScreenWipeSetScale(u8 *arg0, u8 *arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(work + 0x38) = 0x3F800000;
        *(u32 *)(work + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(work + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(work + 0x3C) = *(f32 *)(arg1 + 4);
    }
}

// Intent: Copy the screen wipe's scale to the output pair [inferred]
// FUN_003553B0
void datScreenWipeGetScale(u8 *arg0, f32 *arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        kAssertFail(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(work + 0x38);
    arg1[1] = *(f32 *)(work + 0x3C);
}

// Intent: Set the screen wipe's alpha byte [inferred]
// FUN_00355410
/* The opacity component is a byte, as stored by the state and passed by every caller. */
void datScreenWipeSetAlpha(u8 *arg0, u8 arg1)
{
    u8 *work;

    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0xA) = arg1;
    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0xC) = ((s32 *)work)[3];
}

// Intent: Return the screen wipe's texture when its texture load has finished, otherwise 0 [inferred]
// FUN_00355430
s32 datScreenWipeTexture(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 0x40) != 0) {
        return *(s32 *)(work + 0x150);
    }
    return 0;
}

// Intent: Screen wipe task update: start the texture load when the id is set and the wipe is not loaded yet [inferred]
// FUN_00355460
s32 datScreenWipeUpdate(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[16] == 0) && (*(u16 *)(p + 8) != 0)) {
        *(s32 *)(p + 0x40) = datTextSlotLoadStep(p + 0x144);
    }
    return 0;
}

// Intent: Screen wipe task destroy: release the wipe's texture handles and the work block [inferred]
// FUN_003554B0
void datScreenWipeDestroy(u8 *arg0)
{
    s32 handle;
    s32 cdvdHandle;
    s32 loadResult;
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    handle = *(s32 *)(p + 0x148);
    if (handle != 0) {
        func_004672c0(handle, *(s32 *)(p + 0x14C));
        *(s32 *)(p + 0x148) = 0;
        *(s32 *)(p + 0x14C) = 0;
        *(s32 *)(p + 0x150) = 0;
    } else {
        cdvdHandle = *(s32 *)(p + 0x14C);
        if (cdvdHandle != 0) {
            H_Cdvd_Destroy((u8 *)cdvdHandle);
            *(s32 *)(p + 0x14C) = 0;
        }
        loadResult = *(s32 *)(p + 0x150);
        if (loadResult != 0) {
            func_003ef3a0((void *)loadResult);
            *(s32 *)(p + 0x150) = 0;
        }
    }
    (*D_008873EC)(p);
}

#pragma push
#pragma optimization_level 1
// Intent: Create the grid effect task with its update and destroy callbacks, store its kind, colour and offsets, and set its layout [inferred]
// FUN_00355550
s32 datGridEffectCreate(s16 arg0, s32 arg1, s16 arg2, s16 arg3,
                  s64 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    s32 result;
    u8 *work;
    chkmemAllocSiteTag(&D_0064B310, 0x63D);
    work = D_008873F4[0](1, 0x22C, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064B310, 0x63E);
    }
    result = (s32)kwlnTaskCreate((const void *)(&D_0064B410), arg6, 0, 0, datGridEffectUpdate, datGridEffectDestroy, (u8 *)(work));
    *(s16 *)(work + 0x0) = arg0;
    *(s32 *)(work + 0x4) = arg5;
    *(s16 *)(work + 0xC) = arg2;
    *(s16 *)(work + 0xE) = arg3;
    {
        u8 color_0 = ((u8 *)&arg1)[0];
        u8 color_1 = ((u8 *)&arg1)[1];
        u8 color_2 = ((u8 *)&arg1)[2];
        u8 color_3 = ((u8 *)&arg1)[3];
        *(u8 *)(work + 0x14) = color_0;
        *(u8 *)(work + 0x15) = color_1;
        *(u8 *)(work + 0x16) = color_2;
        *(u8 *)(work + 0x17) = color_3;
    }
    datGridEffectInit(work, arg4, arg7);
    return result;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Initialise the grid effect work block: clear its fifteen cell positions and set its update callback and state [inferred]
// FUN_003556A0
void datGridEffectInit(u8 *arg0, s64 arg1, s32 arg2)
{
    s32 i;
    u8 *p;

    *(s32 *)(arg0 + 8) = 1;
    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(s32 *)(p + 0x20) = 0;
        *(s32 *)(p + 0x24) = 0;
        i += 1;
    }
    datGridEffectSetLayout(arg0, (s16)arg1);
    memset(arg0 + 0x1F8, 0, 0x30);
    *(s32 *)(arg0 + 0x200) = (s32)datGridEffectDraw;
    *(s32 *)(arg0 + 0x208) = (s32)arg0;
    *(s32 *)(arg0 + 0x228) = arg2;
}
#pragma pop

#pragma push
#pragma optimization_level 1
// Intent: Set the grid effect's cell positions for its layout: layout 0 places every cell at the origin, layout 1 spreads them in a diamond around the centre [inferred]
// FUN_00355740
void datGridEffectSetLayout(u8 *arg0, s64 arg1)
{
    f32 step;
    f32 scale;
    f32 temp;
    f32 three_quarters;
    s32 x;
    s32 y;
    s32 i;
    s32 i2;
    s32 j;
    s32 divisor;
    u8 *p;
    u8 *q;
    u8 *r;
    extern f32 fGpffff83d0;

    i = 0;
    while (i < 0xF) {
        p = arg0 + (i << 5);
        *(f32 *)(p + 0x28) = *(f32 *)(p + 0x20);
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x24);
        i += 1;
    }
    switch (arg1) {
    case 0:
        i2 = 0;
        while (i2 < 0xF) {
            q = arg0 + (i2 << 5);
            *(s32 *)(q + 0x18) = 0;
            *(s32 *)(q + 0x1C) = 0;
            *(s32 *)(q + 0x30) = 0;
            *(f32 *)(q + 0x34) = (f32)*(s16 *)(arg0 + 0xC);
            i2 += 1;
        }
        break;
    case 1:
        j = 0;
        divisor = 5;
        step = fGpffff83d0;
        three_quarters = 0.75f;
        while (j < 0xF) {
            x = (j % divisor) - 2;
            if (x < 0) {
                x = -x;
            }
            y = (j / divisor) - 1;
            if (y < 0) {
                y = -y;
            }
            scale = step * (f32)(x + y);
            r = arg0 + (j << 5);
            *(s32 *)(r + 0x18) = 0;
            *(s32 *)(r + 0x1C) = 0;
            *(f32 *)(r + 0x30) = (f32)*(s16 *)(arg0 + 0xC) * scale;
            temp = (f32)*(s16 *)(arg0 + 0xC);
            *(f32 *)(r + 0x34) = temp * (three_quarters + scale);
            j += 1;
        }
        break;
    default:
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Grid effect task update: refresh the cell lookup and return -1 when the effect is marked done [inferred]
// FUN_003558A0
s32 datGridEffectUpdate(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0x1F8) = 0;
    *(s32 *)(work + 0x1FC) = 0;
    PrimAppendNode((u8 *)&D_00793E80 + (*(s32 *)(work + 0x228) * 0x30), work + 0x1F8);
    if (!(*(s32 *)(work + 8) & 4)) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}
#pragma pop

/* Whether the frame counter at +0x10 has passed the style's threshold of the
   duration at +0xC (3/4 for style 0, 1/2 for style 1). */
static inline s32 effect_timer_past_threshold(u8 *p)
{
    switch (*(s16 *)p) {
    case 1:
        if (*(s16 *)(p + 0x10) > *(s16 *)(p + 0xC) / 2) {
            return 1;
        }
        break;
    case 0:
        if (*(s16 *)(p + 0x10) > *(s16 *)(p + 0xC) * 3 / 4) {
            return 1;
        }
        break;
    }
    return 0;
}

#pragma push
#pragma optimization_level 2
// Intent: Draw the grid effect's fifteen cells, each one fading in by its timer and drawn as a cell or a strip by its kind [inferred]
// FUN_00355920
void datGridEffectDraw(u8 *arg0, u8 *arg1) {
    extern u8 D_00887300[];
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void effMiscDrawScreenColor(u8 *arg0, s32 arg1);
    extern f32 cosf(f32 arg0);
    extern void datGridEffectDrawStrip(s64 arg0, f32 f0, f32 f1, s32 arg1, f32 f2, s32 arg2, s32 arg3);
    extern void datGridEffectDrawCell(Vec2f arg0, s32 arg1, f32 dummy, f32 f0, f32 f1, s32 arg2);
    extern f32 fGpffff8504;
    extern f32 fGpffff8540;
    extern f32 fGpffff8548;
    u8 *p;
    s32 isZero;
    u8 alpha;
    void (**tbl)(u32, u32);
    s32 i;
    f32 f20;
    f32 f21;
    union { s64 bits; Vec2f vec; } xy;
    union { s32 w; u8 b[4]; } col;
    (void)arg0;
    p = arg1;
    alpha = 0xFF;
    isZero = (*(s32 *)(p + 4) == 0);
    tbl = (void (**)(u32, u32))D_00887300;
    tbl[0](7, 2);
    tbl[0](6, 0);
    tbl[0](8, 0);
    tbl[0](0xE, 0);
    tbl[0](9, 2);
    tbl[0](0xC, 1);
    tbl[0](1, 0);
    if (isZero != 0) {
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31801);
        col.b[0] = 0xFF;
        col.b[1] = 0xFF;
        col.b[2] = 0xFF;
        col.b[3] = 0;
        effMiscDrawScreenColor(col.b, 0);
    }
    if ((*(s32 *)(p + 8) & 2) != 0) {
        *(s16 *)(p + 0x12) += 1;
        switch (*(s32 *)(p + 4)) {
        case 0: {
            s16 limit = *(s16 *)(p + 0xE);
            s16 cnt = *(s16 *)(p + 0x12);
            f32 fcnt = (f32)cnt;
            f32 flimit = (f32)limit;
            f32 start = fGpffff8504;

            if (fcnt < fGpffff8504 * flimit) {
                break;
            }
            if (cnt <= limit) {
                f32 s;

                xy.vec.x = 320.0f;
                xy.vec.y = 224.0f;
                col.b[3] = 0xFF;
                f20 = fGpffff84a4 * ((fcnt - start * flimit) / (fGpffff8540 * flimit));
                f21 = iGpffff8544 * (1.0f - cosf(f20));
                s = 800.0f * sinf(f20);
                switch (*(s16 *)p) {
                case 0:
                    datGridEffectDrawStrip(xy.bits, 0.0f, s, col.w, 0.0f, 0x30, 0);
                    break;
                case 1:
                    datGridEffectDrawCell(xy.vec, col.w, 0.0f, s, f21, 0);
                    break;
                }
            } else {
                *(s32 *)(p + 8) |= 4;
            }
            break;
        }
        case 1:
            if (*(s16 *)(p + 0x12) >= *(s16 *)(p + 0xE)) {
                *(s32 *)(p + 8) |= 4;
            }
            break;
        case 2: {
            s16 limit = *(s16 *)(p + 0xE);
            s16 cnt = *(s16 *)(p + 0x12);
            if (cnt < limit) {
                alpha = (u8)(255.0f * (1.0f - (f32)cnt / (f32)limit));
            } else {
                *(s32 *)(p + 8) |= 4;
            }
            break;
        }
        default:
            kAssertFail(D_0064B310, 0x712);
            break;
        }
    }
    if (isZero != 0) {
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(3, 0x35801);
        RpSkyRenderStateSet(2, 0x44);
    } else {
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
    if ((*(s32 *)(p + 8) & 1) != 0) {
        *(s16 *)(p + 0x10) += 1;
        if (*(s16 *)(p + 0x10) <= *(s16 *)(p + 0xC)) {
            switch (*(s32 *)(p + 4)) {
            case 0:
                if ((*(s32 *)(p + 8) & 2) == 0 && *(s16 *)(p + 0xC) / 3 < *(s16 *)(p + 0x10)) {
                    *(s32 *)(p + 8) |= 2;
                }
                break;
            case 1:
            case 2:
                if ((*(s32 *)(p + 8) & 2) == 0) {
                    if (effect_timer_past_threshold(p) != 0) {
                        *(s32 *)(p + 8) |= 2;
                    }
                }
                break;
            default:
                kAssertFail(D_0064B310, 0x73A);
                break;
            }
        } else {
            *(s32 *)(p + 8) &= ~1;
            *(s32 *)(p + 8) |= 2;
        }
    }
    if ((*(s32 *)(p + 8) & 4) != 0) {
        return;
    }
    col.b[0] = *(u8 *)(p + 0x14);
    col.b[1] = *(u8 *)(p + 0x15);
    col.b[2] = *(u8 *)(p + 0x16);
    col.b[3] = alpha;
    if (effect_timer_past_threshold(p) != 0) {
        effMiscDrawScreenColor(col.b, 0);
        return;
    }
    for (i = 0; i < 0xF; i++) {
        f32 e30;
        f32 e34;
        f32 ctr;
        u8 *e;
        f32 f13;
        xy.vec.x = 320.0f + 160.0f * (f32)(i % 5 - 2);
        xy.vec.y = 224.0f + 160.0f * (f32)(i / 5 - 1);
        e = p + (i << 5);
        e30 = *(f32 *)(e + 0x30);
        ctr = (f32)*(s16 *)(p + 0x10);
        f13 = 0.0f;
        if (ctr < e30) {
            f20 = f13;
        } else {
            e34 = *(f32 *)(e + 0x34);
            if (ctr < e34) {
                f20 = iGpffff8544;
                f13 = 280.0f * (1.0f - cosf((fGpffff84a4 * (ctr - e30)) / (e34 - e30)));
            } else {
                f20 = fGpffff8548;
                f13 = 280.0f;
            }
        }
        switch (*(s16 *)p) {
        case 0:
            datGridEffectDrawCell(xy.vec, col.w, 0.0f, f13, f20, 1);
            break;
        case 1:
            datGridEffectDrawStrip(xy.bits, 0.0f, f13, col.w, 0.0f, 0x30, 1);
            break;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Grid effect task destroy: free the work block [inferred]
// FUN_00356140
void datGridEffectDestroy(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Draw a grid effect strip at the packed position with the given opacity and size [inferred]
// FUN_00356170
void datGridEffectDrawStrip(s64 arg0, f32 f0, f32 f1, s32 arg1,
                   f32 f2, s32 arg2, s32 arg3)
{
    union { s64 bits; Vec2f position; } saved0[1];
    s32 saved1[1];
    s32 var8;
    s32 tmp2;
    u8 sel;

    saved0[0].bits = arg0;
    saved1[0] = arg1;
    tmp2 = arg2;
    var8 = arg3;
    sel = ((u8 *)saved1)[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    shdDrawRadialFan(saved0[0].position, f0,
                  *(s32 *)((u8 *)saved1), saved1[0],
                  f1, f2, tmp2, 1.0f, 1.0f, var8);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Draw a grid effect cell at the given position with the given opacity and size [inferred]
// FUN_003561D0
void datGridEffectDrawCell(Vec2f arg0, s32 arg1, f32 dummy,
                   f32 f0, f32 f1, s32 arg2)
{
    struct Frame {
        union { s32 bits; f32 value; } saved1;
        union { f32 value; u8 bytes[4]; } temp;
    } frame;
    s32 var8;
    u8 sel;
    f32 scaled;
    f32 one;
    f32 shifted;
    f32 call_f0;
    f32 call_f1;
    f32 call_f2;
    f32 call_f3;
    s32 call_arg4;
    f32 call_f4;

    frame.saved1.bits = arg1;
    scaled = f0 / iGpffff83d4;
    shifted = iGpffff8544 + f1;
    var8 = arg2;
    frame.temp.value = frame.saved1.value;
    sel = frame.temp.bytes[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    one = 1.0f;
    call_f0 = dummy;
    call_f1 = scaled;
    call_f2 = shifted;
    call_f3 = one;
    call_arg4 = var8;
    call_f4 = one;
    shdDrawRadialFan(arg0, call_f0, frame.saved1.bits, frame.saved1.bits,
                  call_f1, call_f2, 4,
                  call_f3, call_f4, call_arg4);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
// FUN_00356250
#pragma opt_loop_invariants on
void datCommunityMenuInit(u8 *arg0)
{
    extern u8 D_0064BDA0[];
    extern u8 D_0064CBE0[];
    extern u8 D_0064CC98[];
    extern char D_005E57F0[];
    extern char D_005E5810[];
    extern char D_005E5830[];
    extern char D_005E5850[];
    extern s32 cmmCommunityFindByKind(s16 arg0);
    extern s64 cmmCommunityArcana(s32 arg0);
    extern u16 cmmCommunityRecordValue(s32 arg0);
    extern s32 cmmCommunityTestBroken(s32 arg0);
    extern s32 cmmCommunityTestReversed(s32 arg0);
    extern u8 *resourceFindByName(char *arg0);
    extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
    extern void kAssertFail(const void *arg0, u32 arg1);
    extern s32 cmmAuxTable(void);
    extern void nmMesWindowInstallHandle(s32 arg0, u8 *arg1);
    extern u8 *datPortraitTaskCreate(s32 arg0, s64 arg1, s32 arg2);
    extern u8 *datPortraitTextTaskCreate(s32 arg0, u16 arg1, s32 arg2);
    s16 i;
    s16 j;
    s16 k;
    u8 *src;
    u8 *dst;
    u8 *bdabase;
    u8 *h0;
    u8 *h1;
    u8 *h3;
    u8 *h2;
    u8 **slot;
    s16 q;
    u16 *kind;
    s32 id;
    s16 n;
    s16 m;
    u8 *p;

    *(f32 *)(arg0 + 4) = 0.0f;
    *(f32 *)(arg0 + 8) = 0.0f;
    *(u8 *)(arg0 + 0) = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x14) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(arg0 + i * 2 + 0x24) = 0;
    }
    j = 0;
    bdabase = D_0064BDA0;
    while (j < 0x2B) {
        src = bdabase + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x160) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x164) = *(f32 *)(src + 4);
        *(u16 *)(dst + 0x170) = (u16)*(f32 *)(src + 8);
        *(u16 *)(dst + 0x176) = (u16)*(f32 *)(src + 0xC);
        *(u8 *)(dst + 0x16A) = *(u8 *)(src + 0x10);
        j++;
    }
    for (k = 0; k < 0x6C; k++) {
        p = arg0 + k * 0x14;
        *(s32 *)(p + 0x964) = k % 9;
        *(s32 *)(p + 0x96C) = 9;
        *(s32 *)(p + 0x968) = k / 9;
        *(s32 *)(p + 0x970) = 0xC;
    }
    m = 0;
    n = 0;
    while (m < 0x15) {
        id = cmmCommunityFindByKind(m) & 0xFFFF;
        if (id > 0) {
            p = arg0 + n * 0xC;
            *(s8 *)(p + 0x38) = cmmCommunityArcana(id);
            *(s16 *)(p + 0x3A) = id;
            kind = (u16 *)(p + 0x3C);
            *kind = cmmCommunityRecordValue(id);
            if (*kind == 0xA) {
                *(s32 *)(p + 0x40) = 1;
            } else if (cmmCommunityTestBroken(id) != 0) {
                *(s32 *)(p + 0x40) = 3;
            } else if (cmmCommunityTestReversed(id) != 0) {
                *(s32 *)(p + 0x40) = 2;
            } else {
                *(s32 *)(p + 0x40) = 0;
            }
            n++;
        }
        m++;
    }
    *(s16 *)(arg0 + 0x134) = n;
    if (n > 0x15) {
        kAssertFail(D_0064CC98, 0x1E2);
    }
    h0 = resourceFindByName(D_005E5830);
    if (h0 == NULL) {
        kAssertFail(D_0064CC98, 0x1E6);
    }
    h1 = resourceFindByName(D_005E5850);
    if (h1 == NULL) {
        kAssertFail(D_0064CC98, 0x1E8);
    }
    h2 = resourceFindByName(D_005E5810);
    if (h2 == NULL) {
        kAssertFail(D_0064CC98, 0x1EA);
    }
    *(u8 **)(arg0 + 0x1304) = h3 = resourceFindByName(D_005E57F0);
    if (h3 == NULL) {
        kAssertFail(D_0064CC98, 0x1EC);
    }
    for (q = 0; q < 0x4D; q++) {
        if (q < 2) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h0, D_0064CBE0[q]);
        } else if (q < 0x33) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h1, D_0064CBE0[q]);
        } else if (q < 0x34) {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h3, D_0064CBE0[q]);
        } else {
            slot = (u8 **)(arg0 + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h2, D_0064CBE0[q]);
        }
        if (*slot == NULL) {
            kAssertFail(D_0064CC98, 0x1FC);
        }
    }
    datCommunitySetTableMode(arg0, 0);
    nmMesWindowInstallHandle(0xB, (u8 *)cmmAuxTable());
    *(u8 **)(arg0 + 0x1308) = datScreenWipeTaskCreate(0, 1);
    *(u8 **)(arg0 + 0x130C) = datPortraitTaskCreate(0, 0, 0);
    *(u8 **)(arg0 + 0x1310) = datPortraitTextTaskCreate(0, 0, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community panel open step: move the panel from its closed state to open and report it as ready [inferred]
// FUN_00356820
s32 datCommunityPanelOpenStep(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community panel update: animate the panel's radar values, advance its rotation, update its helpers and draw the community list; returns 0 while any entry is still animating [inferred]
// FUN_00356870
s32 datCommunityPanelUpdate(u8 *arg0)
{
    s16 counter;
    s32 index;
    s32 result;
    u8 *slot;
    extern void datCommunityListDraw(u8 *arg0);
    extern void datCommunityEntriesStep(u8 *arg0);
    extern void datCommunityBounceStep(u8 *arg0);

    result = 1;
    counter = *(s16 *)(arg0 + 0x20);
    if (counter < 0x64) {
        *(s16 *)(arg0 + 0x20) = counter + 1;
    }
    index = 0;
    goto loop_test;
loop_body:
    if (((index >= 0x12) && (index <= 0x1B)) ||
        ((index > 0) && (index <= 5)) ||
        ((index >= 0x27) && (index <= 0x28))) {
        slot = arg0 + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(arg0 + 0x20), 1);
    } else if (index == 0x26) {
        slot = arg0 + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(arg0 + 0x20), 2);
    } else {
        slot = arg0 + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(arg0 + 0x20), 0);
    }
    if (*(u8 *)(slot + 0x16A) != 0) {
        result = 0;
    }
    index += 1;
loop_test:
    if (index < 0x2B) {
        goto loop_body;
    }
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) + 1;
    if (*(s16 *)(arg0 + 0x22) > 0x168) {
        *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x22) - 0x168;
    }
    datCommunityEntriesStep(arg0);
    datCommunityBounceStep(arg0);
    datCommunityListDraw(arg0);
    return result;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
/* Community-list renderer: 10536/10544 bytes, all 115 relocations exact.
 * Native byte-opacity contracts, the Vec2f output, and real RGBA/rectangle
 * objects replace the former decompiler carriers and expanded conversions.
 * Measured: lifetime analysis retains the phased register roles; disabling
 * propagation keeps packed text colors captured before callbacks, while
 * disabling literal extraction avoids extra call-crossing float constants.
 * The sparse context view preserves observed offsets without allocating data.
 * See docs/probe_archive/Community_menu_renderer_00356a10_20260930.md. */
// Intent: Draw the community list: the entry layout, badges and text for the community menu [inferred]
// FUN_00356A10
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
void datCommunityListDraw(u8 *work) {
    typedef struct {
        u8 opacity;
        u8 unknown0001[0x3];
        Vec2f origin;
        u8 unknown000C[0x4];
        s32 background;
        u8 unknown0014[0x8];
        s32 flags;
        u8 unknown0020[0x2];
        s16 angle;
        s16 selectedRow;
        s16 firstRow;
        s16 selectedDetail;
        u8 unknown002A[0x6];
        f32 rotation;
        f32 zoom;
        u8 unknown0038[0xFC];
        s16 rowCount;
        u8 unknown0136[0x12];
        s32 detailCount;
        s16 footerId;
        u8 unknown014E[0x12];
        Vec2f markerOffset;
        u8 unknown0168[0x2];
        u8 markerOpacity;
        u8 unknown016B[0x2C5];
        Vec2f footerOffset;
        u8 unknown0438[0x2];
        u8 footerOpacity;
        u8 unknown043B[0x25];
        Vec2f backEmblemOffset;
        u8 unknown0468[0x2];
        u8 backEmblemOpacity;
        u8 unknown046B[0x5];
        u16 backEmblemScaleX;
        u8 unknown0472[0x1E];
        Vec2f frontEmblemOffset;
        u8 unknown0498[0x2];
        u8 frontEmblemOpacity;
        u8 unknown049B[0x5];
        u16 frontEmblemScaleX;
        u8 unknown04A2[0x31E];
        Vec2f leftHintOffset;
        u8 unknown07C8[0x2];
        u8 leftHintOpacity;
        u8 unknown07CB[0x25];
        Vec2f rightHintOffset;
        u8 unknown07F8[0x2];
        u8 rightHintOpacity;
        u8 unknown07FB[0x25];
        Vec2f scrollOffset;
        u8 unknown0828[0x2];
        u8 scrollOpacity;
        u8 unknown082B[0x25];
        Vec2f titleOffset;
        u8 unknown0858[0x2];
        u8 titleOpacity;
        u8 unknown085B[0x25];
        Vec2f detailFooterOffset;
        u8 unknown0888[0x2];
        u8 detailFooterOpacity;
        u8 unknown088B[0x25];
        Vec2f portraitOffset;
        u8 unknown08B8[0x2];
        u8 portraitOpacity;
        u8 unknown08BB[0x25];
        Vec2f panelOffset;
        u8 unknown08E8[0x2];
        u8 panelOpacity;
        u8 unknown08EB[0x5];
        u16 panelScaleX;
        u8 unknown08F2[0x4];
        u16 panelScaleY;
        u8 unknown08F8[0x18];
        Vec2f gridOffset;
        u8 unknown0918[0x2];
        u8 gridOpacity;
        u8 unknown091B[0x25];
        Vec2f detailOffset;
        u8 unknown0948[0x2];
        u8 detailOpacity;
        u8 unknown094B[0x885];
        u8 * resource11D0;
        u8 * resource11D4;
        u8 * resource11D8;
        u8 * resource11DC;
        u8 * resource11E0;
        u8 * resource11E4;
        u8 * resource11E8;
        u8 * resource11EC;
        u8 * resource11F0;
        u8 * resource11F4;
        u8 * resource11F8;
        u8 * resource11FC;
        u8 * resource1200;
        u8 * resource1204;
        u8 * resource1208;
        u8 * resource120C;
        u8 * resource1210;
        u8 * resource1214;
        u8 * resource1218;
        u8 * resource121C;
        u8 * resource1220;
        u8 * resource1224;
        u8 * resource1228;
        u8 * resource122C;
        u8 * resource1230;
        u8 * resource1234;
        u8 * resource1238;
        u8 * resource123C;
        u8 * resource1240;
        u8 * resource1244;
        u8 * resource1248;
        u8 * resource124C;
        u8 * resource1250;
        u8 * resource1254;
        u8 * resource1258;
        u8 * resource125C;
        u8 * resource1260;
        u8 * resource1264;
        u8 * resource1268;
        u8 * resource126C;
        u8 * resource1270;
        u8 * resource1274;
        u8 * resource1278;
        u8 * resource127C;
        u8 * resource1280;
        u8 * resource1284;
        u8 * resource1288;
        u8 * resource128C;
        u8 * resource1290;
        u8 * resource1294;
        u8 * resource1298;
        u8 * resource129C;
        u8 * resource12A0;
        u8 * resource12A4;
        u8 * resource12A8;
        u8 * resource12AC;
        u8 * resource12B0;
        u8 * resource12B4;
        u8 * resource12B8;
        u8 unknown12BC[0x48];
        s32 resource1304;
        u8 * resource1308;
        u8 * resource130C;
        u8 * resource1310;
    } CommunityMenuView;
    CommunityMenuView *menu;
    extern void sdkRenderStateSetDefault(void);
    extern s32 frFontExDrawTextOutB(f32, f32, f32, s32, s8, s32, const char *, s32, s32, s32);
    extern void nLineDrawSet(Vec2f, s32, s32, f32);
    extern void PrimDrawFlatRectangle(u8 *, f32 *, f32, s32);
    extern void datPartyHudDraw(s32, u8 *);
    extern void datScreenWipeSetAlpha(u8 *, u8);
    extern void datScreenWipeDraw(u8 *);
    extern void sdkSpriteDrawAt(void *, f32, f32, u8, u8, u8, u8);
    extern void sdkSpriteDrawSized(u8 *, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    extern f32 sdkSpriteScaledWidth(u8 *);
    extern f32 sdkSpriteScaledHeight(u8 *);
    extern void kAssertFail(const void *, u32);
    extern f32 cmpGridCellFade(u8 *, f32, f32, f32);
    extern s32 frFontExDrawTextWithCharWidth(f32, f32, f32, s32, s8, s32, const char *, s32, s32);
    extern u8 *cmmNameRecord(u32);
    extern u8 *cmmRankNameRecord(s16);
    extern u8 *cmmDetailRecord(s16);
    extern void fclMesWindowDrawItem(f32, f32, f32, u32, u32, u32, s32, s32);
    extern f32 datCommunityPortraitDraw(u8 *, u8);
    extern f32 datPortraitTextDraw(u8 *, u8);
    extern void datPortraitGetPosition(u8 *, Vec2f *);
    extern u16 cmmCommunityRecordValue(s32);
    extern u32 datPersonaDisplayName(s16);
    extern void sdkSpriteDrawFooter(Vec2f, f32, u8, s32, s32);
    extern s32 (*D_00887300[])(s32, void *);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064CC30[];
    extern u8 D_0064CC48[];
    extern u8 D_0064CC98[];
    typedef struct { u8 r, g, b, a; } MenuColor;
    MenuColor color;
    Vec2f position;
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    s16 backPivotX;
    u8 frontEmblemOpacity;
    u8 *emblemTexture;
    u8 backEmblemOpacity;
    s16 frontPivotX;
    s16 emblemAngle;
    u8 portraitOpacity;
    u8 *portraitTexture;
    s16 portraitPivotX;
    u16 selectedCount;
    s8 rowFontMode;
    f32 globalOpacity;
    f32 originX;
    f32 originY;
    f32 panelScaleY;
    f32 panelX;
    f32 panelY;
    f32 panelScaleX;
    f32 cellBlend;
    f32 lockedHeaderX;
    f32 specialHeaderX;
    f32 lockedHeaderY;
    f32 specialHeaderY;
    f32 backgroundOpacityProduct;
    f32 titleOpacityProduct;
    f32 panelOpacityProduct;
    f32 portraitOpacityProduct;
    f32 rowOpacityProduct;
    f32 detailOpacityProduct;
    f32 footerOpacityProduct;
    f32 numberOpacityProduct;
    f32 leftHintOpacityProduct;
    f32 rightHintOpacityProduct;
    f32 cursorOpacityProduct;
    f32 separatorOpacityProduct;
    f32 menuOpacityProduct;
    f32 scrollOpacityProduct;
    f32 backEmblemOpacityProduct;
    f32 frontEmblemOpacityProduct;
    f32 markerOpacityProduct;
    f32 gridBaseOpacityProduct;
    f32 cellOpacityProduct;
    f32 cellX;
    f32 cellY;
    f32 zoomRatio;
    f32 portraitScale;
    f32 separatorAlphaFloat;
    f32 rowAlphaFloat;
    f32 detailAlphaFloat;
    f32 footerAlphaFloat;
    f32 numberAlphaFloat;
    f32 leftHintAlphaFloat;
    f32 rightHintAlphaFloat;
    f32 cursorAlphaFloat;
    f32 scrollAlphaFloat;
    f32 backEmblemAlphaFloat;
    f32 frontEmblemAlphaFloat;
    f32 markerAlphaFloat;
    f32 gridAlphaFloat;
    f32 titleAlphaFloat;
    f32 panelAlphaFloat;
    f32 portraitAlphaFloat;
    f32 globalAlphaFloat;
    f32 scrollThumbOffset;
    f32 gridOpacityFloat;
    f32 backEmblemScale;
    f32 frontEmblemScale;
    s16 detailValue;
    u32 gridOpacity;
    u32 numberOpacity;
    u32 numberColor;
    s32 selectedMode;
    s32 currentRank;
    s32 selectedIndex;
    u8 *rankNames;
    u8 *categoryTexture;
    u32 rankColor;
    s32 nameColor;
    s32 rowColor;
    u8 *tileTexture;
    u8 *detailValues;
    s32 categoryIndex;
    s32 scrollRange;
    s32 separatorIndex;
    s32 visibleIndex;
    u16 rankIndex;
    s32 cellIndex;
    s32 detailIndex;
    s32 backgroundOpacity;
    s32 footerQuantized;
    s32 leftHintOpacity;
    s32 rightHintOpacity;
    s32 cursorOpacity;
    s32 scrollQuantized;
    s32 markerOpacity;
    s32 gridQuantized;
    s32 titleQuantized;
    s32 panelQuantized;
    s32 rowQuantized;
    s32 numberQuantized;
    s16 backPivotY;
    s16 frontPivotY;
    u16 detailId;
    u16 panelScaleXBits;
    u16 panelScaleYBits;
    u16 backScaleBits;
    u16 frontScaleBits;
    MenuColor *palette;
    u8 scrollOpacity;
    u8 titleOpacity;
    u8 footerOpacity;
    u8 detailOpacity;
    u8 panelOpacity;
    u8 rowOpacity;
    u8 globalAlpha;
    u8 gridAlpha;
    u8 titleAlpha;
    u8 panelAlpha;
    u8 rowAlpha;
    u8 footerAlpha;
    u8 leftHintAlpha;
    u8 rightHintAlpha;
    u8 cursorAlpha;
    u8 separatorAlpha;
    u8 scrollAlpha;
    u8 backEmblemAlpha;
    u8 frontEmblemAlpha;
    u8 markerAlpha;
    u8 numberAlpha;
    u8 separatorOpacity;
    u8 *cellPaletteBytes;
    u16 *nameId;
    u8 *separatorAnimation;
    u8 *selectedEntry;
    u8 *rowAnimation;
    u8 *sprite;
    u8 *cell;

    /* Entries are initialized by datCommunityMenuInit with display modes 0 through 3. */
    menu = (CommunityMenuView *)work;
    sdkRenderStateSetDefault();
    originX = (menu->origin.x);
    originY = (menu->origin.y);
    globalAlpha = (u8)(menu->opacity);
    globalAlphaFloat = (f32)globalAlpha;
    globalOpacity = globalAlphaFloat / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        backgroundOpacityProduct = 255.0f * globalOpacity;
        backgroundOpacity = (u8)backgroundOpacityProduct;
        nLineDrawSet(position, backgroundOpacity & 0xFF, menu->background, 0);
    }
    if (menu->flags & 1) {
        for (separatorIndex = 0; separatorIndex < 6; separatorIndex++) {
                separatorAnimation = (u8 *)(work + (separatorIndex * 0x30));
                position.x = originX + *(f32 *)(separatorAnimation + 0x6A0);
                position.y = 64.0f * (f32)separatorIndex + (77.0f + (originY + *(f32 *)(separatorAnimation + 0x6A4)));
                separatorAlpha = (u8)(*( u8 *)((u8 *)(separatorAnimation) + (0x6AA)));
                separatorAlphaFloat = (f32)separatorAlpha;
                separatorOpacityProduct = separatorAlphaFloat * globalOpacity;
                separatorOpacity = (u8)separatorOpacityProduct;
                color = ((MenuColor *)D_0064CC30)[separatorIndex];
                color.a = separatorOpacity;
                rectangle.integer[0] = (s32)position.x;
                rectangle.integer[1] = (s32)position.y;
                rectangle.integer[2] = 0x280;
                rectangle.integer[3] = 3;
                D_00887300[0](1, 0);
                PrimDrawFlatRectangle((u8 *)&color, rectangle.transport, 0.0f, (s64)0);
        }
        for (visibleIndex = 0; visibleIndex < 5; visibleIndex++) {
            if (menu->rowCount > (visibleIndex + menu->firstRow)) {
                datPartyHudDraw(visibleIndex, work);
            }
        }
        menuOpacityProduct = 255.0f * globalOpacity;

        datScreenWipeSetAlpha(menu->resource1308, (u8)menuOpacityProduct);
        datScreenWipeDraw(menu->resource1308);
        position.x = (f32) 0x25F + (originX + menu->scrollOffset.x);
        position.y = (f32) 0x107 + (originY + menu->scrollOffset.y);
        scrollAlpha = (u8)(menu->scrollOpacity);
        scrollAlphaFloat = (f32)scrollAlpha;
        scrollOpacityProduct = scrollAlphaFloat * globalOpacity;
        scrollQuantized = (u8)scrollOpacityProduct;
        scrollOpacity = scrollQuantized & 0xFF;
        sprite = menu->resource11DC;
        sdkSpriteDrawAt(sprite, position.x, position.y, 0xFAU, 0xA1U, 0U, scrollOpacity);
        sprite = menu->resource11E0;
        sdkSpriteDrawAt(sprite, position.x, 135.0f + position.y, 0xFAU, 0xA1U, 0U, scrollOpacity);
        sprite = menu->resource11D0;
        scrollThumbOffset = 6.0f;
        scrollRange = (s32)(menu->rowCount - 5);
        if (scrollRange > 0) {
            scrollThumbOffset = (6.0f + (f32) ((s32) (menu->firstRow * 0x64) / scrollRange));
        }
        sdkSpriteDrawAt(sprite, position.x, position.y + scrollThumbOffset, 0xFAU, 0xA1U, 0U, scrollOpacity);
    }
    if (menu->flags & 4) {
        emblemTexture = (u8 *)(menu->resource11D8);
        emblemAngle = (s16)(menu->angle);
        position.x = (f32) 0x20F + (originX + menu->backEmblemOffset.x);
        position.y = ((originY + menu->backEmblemOffset.y) - 3.0f);
        backEmblemAlpha = (u8)(menu->backEmblemOpacity);
        backEmblemAlphaFloat = (f32)backEmblemAlpha;
        backEmblemOpacityProduct = backEmblemAlphaFloat * globalOpacity;
        backEmblemOpacity = (u8)backEmblemOpacityProduct;
        backScaleBits = (u16)(menu->backEmblemScaleX);
        backEmblemScale = (f32)backScaleBits;
        backPivotX = (s16)(sdkSpriteScaledWidth(emblemTexture) / 2.0f);
        backPivotY = (s16)(sdkSpriteScaledHeight(emblemTexture) / 2.0f);
        sdkSpriteDrawSized(emblemTexture, position.x, position.y, 0.0f, 0xFFU, 0xD1U, 0x34U, backEmblemOpacity, (u16)backEmblemScale, (u16)backEmblemScale, backPivotX, (f32) emblemAngle, backPivotY);
        position.x = (f32) 0x221 + (originX + menu->frontEmblemOffset.x);
        position.y = ((originY + menu->frontEmblemOffset.y) - 6.0f);
        frontEmblemAlpha = (u8)(menu->frontEmblemOpacity);
        frontEmblemAlphaFloat = (f32)frontEmblemAlpha;
        frontEmblemOpacityProduct = frontEmblemAlphaFloat * globalOpacity;
        frontEmblemOpacity = (u8)frontEmblemOpacityProduct;
        frontScaleBits = (u16)(menu->frontEmblemScaleX);
        frontEmblemScale = (f32)frontScaleBits;
        frontPivotX = (s16)(sdkSpriteScaledWidth(emblemTexture) / 2.0f);
        frontPivotY = (s16)(sdkSpriteScaledHeight(emblemTexture) / 2.0f);
        sdkSpriteDrawSized(emblemTexture, position.x, position.y, 0.0f, 0xFFU, 0xFFU, 0x81U, frontEmblemOpacity, (u16)frontEmblemScale, (u16)frontEmblemScale, frontPivotX, (f32) emblemAngle, frontPivotY);
    }
    if (menu->flags & 0x10) {
        position.x = (f32) 0x175 + (originX + menu->markerOffset.x);
        position.y = ((25.0f + (originY + menu->markerOffset.y)) - 1.0f);
        markerAlpha = (u8)(menu->markerOpacity);
        markerAlphaFloat = (f32)markerAlpha;
        markerOpacityProduct = markerAlphaFloat * globalOpacity;
        markerOpacity = (u8)markerOpacityProduct;
        sdkSpriteDrawAt(menu->resource129C, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, markerOpacity & 0xFF);
    }
    if (menu->flags & 2) {
        selectedIndex = (s32)(menu->selectedRow + menu->firstRow);
        if ((selectedIndex < 0) || (selectedIndex >= 0x15)) {
            kAssertFail(&D_0064CC98, 0x2DD);
        }
        selectedEntry = (u8 *)add_offset_first((u32)selectedIndex * 12, (u32)work);
        selectedCount = *( u16 *)((u8 *)(selectedEntry) + (0x3C));
        categoryIndex = (s32)((*( u8 *)((u8 *)(selectedEntry) + (0x38)) - 1) & 0xFF);
        selectedMode = (s32)(*( s32 *)((u8 *)(selectedEntry) + (0x40)));
        tileTexture = (u8 *)(menu->resource11D4);
        position.x = ((2.0f + (originX + menu->gridOffset.x)) - 36.0f);
        position.y = (2.0f + (originY + menu->gridOffset.y));
        gridAlpha = (u8)(menu->gridOpacity);
        gridAlphaFloat = (f32)gridAlpha;
        gridBaseOpacityProduct = gridAlphaFloat * globalOpacity;
        gridQuantized = (u8)gridBaseOpacityProduct;
        gridOpacity = gridQuantized & 0xFF;
        for (cellIndex = 0; cellIndex < 0x6C; cellIndex++) {
            cell = (u8 *)(work + (cellIndex * 0x14));
            if (*( s16 *)((u8 *)(cell) + (0x960)) >= 0) {
                cellX = (position.x + (f32) ((*( s32 *)((u8 *)(cell) + (0x96C)) - *( s32 *)((u8 *)(cell) + (0x964))) * 0x2C));
                cellY = (position.y + (f32) ((*( s32 *)((u8 *)(cell) + (0x970)) - *( s32 *)((u8 *)(cell) + (0x968))) * 0x25));
                cellBlend = (cmpGridCellFade(cell + 0x960, 0.5f, 0.5f, 1.0f));
                cellPaletteBytes = (u8 *)((s32)&D_0064CC48 + (*( s16 *)((u8 *)(cell) + (0x960)) * 4));
                color = *(MenuColor *)cellPaletteBytes;
                gridOpacityFloat = (f32)gridOpacity;
                cellOpacityProduct = gridOpacityFloat * cellBlend;
                sdkSpriteDrawAt(tileTexture, cellX, cellY, color.r, color.g, color.b, (u8)cellOpacityProduct);
            }
        }
        titleAlpha = (u8)(menu->titleOpacity);
        titleAlphaFloat = (f32)titleAlpha;
        titleOpacityProduct = titleAlphaFloat * globalOpacity;
        titleQuantized = (u8)titleOpacityProduct;
        titleOpacity = titleQuantized & 0xFF;
        position.x = (127.0f + (originX + menu->titleOffset.x));
        position.y = (17.0f + (originY + menu->titleOffset.y));
        sprite = menu->resource1254;
        sdkSpriteDrawAt(sprite, position.x, position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        sprite = menu->resource1258;
        sdkSpriteDrawAt(sprite, (f32) 0x179 + position.x, position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        position.x = (135.0f + (originX + menu->titleOffset.x));
        position.y = (21.0f + (originY + menu->titleOffset.y));
        sprite = menu->resource1298;
        sdkSpriteDrawAt(sprite, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], titleOpacity);
        sprite = menu->resource1218;
        sdkSpriteDrawAt(sprite, 88.0f + position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], titleOpacity);
        position.x = (183.0f + (originX + menu->titleOffset.x));
        position.y = (22.0f + (originY + menu->titleOffset.y));
        categoryTexture = *(u8 **)((u8 *)add_offset_first((u32)(categoryIndex & 0xFF) * 4, (u32)work) + 0x12A4);
        sdkSpriteDrawAt(categoryTexture, position.x - (sdkSpriteScaledWidth(categoryTexture) / 2.0f), position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        position.x = (245.0f + (originX + menu->titleOffset.x));
        position.y = (19.0f + (originY + menu->titleOffset.y));
        rankColor = titleOpacity & 0xFF;
        nameColor = rankColor | ~0x7EFF;
        nameId = (u16 *)((u8 *)add_offset_first((u32)(selectedIndex * 12), (u32)work) + 0x3A);
        frFontExDrawTextWithCharWidth(position.x, position.y, 0.0f, nameColor, 0, 1, (const char *)cmmNameRecord(*nameId), 0, -2);
        rankNames = cmmRankNameRecord((s16)*nameId);
        position.x = (130.0f + (originX + menu->titleOffset.x));
        position.y = (46.0f + (originY + menu->titleOffset.y));
        rankColor |= ~0xFF;
        switch (selectedMode) {
        case 0:
        case 1:
            rankIndex = (cmmCommunityRecordValue(*nameId) - 1) & 0xFFFF;
            break;
        case 3:
            rankIndex = 11;
            break;
        case 2:
            rankIndex = 10;
            break;
        }
        fclMesWindowDrawItem(position.x, position.y, 0.0f, rankColor, 1, 6, 7, *(s16 *)(rankNames + ((rankIndex & 0xFFFF) * 2)));
        panelX = (15.0f + (originX + menu->panelOffset.x));
        panelY = (17.0f + (originY + menu->panelOffset.y));
        panelAlpha = (u8)(menu->panelOpacity);
        panelAlphaFloat = (f32)panelAlpha;
        panelOpacityProduct = panelAlphaFloat * globalOpacity;
        panelQuantized = (u8)panelOpacityProduct;
        panelOpacity = panelQuantized & 0xFF;
        panelScaleXBits = (u16)(menu->panelScaleX);
        panelScaleX = (f32)panelScaleXBits;
        panelScaleYBits = (u16)(menu->panelScaleY);
        panelScaleY = (f32)panelScaleYBits;
        position.x = panelX;
        position.y = panelY;
        sprite = menu->resource1248;
        sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        sprite = menu->resource124C;
        sdkSpriteDrawSized(sprite, position.x, 153.0f + position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
        switch (selectedMode) {
        case 2:
        case 3:
            position.x = panelX + ((4.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((23.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource1284;
            sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, 0x18U, 0U, 8U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            sprite = menu->resource1288;
            sdkSpriteDrawSized(sprite, position.x, 124.0f + position.y, 0.0f, 0x18U, 0U, 8U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
            break;
        case 1:
            position.x = panelX + ((4.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((4.0f * panelScaleY) / 4096.0f);
            palette = (MenuColor *)D_0064B2EC;
            sprite = menu->resource1290;
            sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, palette->r, palette->g, palette->b, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            sprite = menu->resource1288;
            sdkSpriteDrawSized(sprite, position.x, 143.0f + position.y, 0.0f, palette->r, palette->g, palette->b, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, 0, 0.0f, (s64)0);
            break;
        }
        position.x = panelX + ((6.0f * panelScaleX) / 4096.0f);
        position.y = panelY + ((25.0f * panelScaleY) / 4096.0f);
        sprite = menu->resource1250;
        sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, 0xFFU, 0xEBU, 0x3DU, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        if (selectedMode == 1) {
            position.x = panelX + ((19.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((6.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource128C;
            sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, 0xDDU, 0x74U, 0U, panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        } else {
            position.x = panelX + ((15.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((7.0f * panelScaleY) / 4096.0f);
            sprite = menu->resource11E8;
            sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
            position.x = panelX + ((79.0f * panelScaleX) / 4096.0f);
            position.y = panelY + ((4.0f * panelScaleY) / 4096.0f);
            sprite = *(u8 **)((u8 *)add_offset_first((u32)(u16)selectedCount * 4, (u32)work) + 0x11EC);
        sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], panelOpacity, (u16)panelScaleX, (u16)panelScaleY, (s64)0, 0.0f, (s64)0);
        }
        portraitOpacity = (u8)(menu->portraitOpacity);
        if (portraitOpacity > 0) {
            portraitAlphaFloat = (f32)portraitOpacity;
            portraitOpacityProduct = portraitAlphaFloat * globalOpacity;

            datCommunityPortraitDraw(menu->resource130C, (u8)portraitOpacityProduct);
        }
        switch (selectedMode) {
        case 1:
            break;
        case 2:
            lockedHeaderX = 69.0f + originX;
            position.x = lockedHeaderX;
            lockedHeaderY = 133.0f + originY;
            position.y = lockedHeaderY;
            sprite = menu->resource1278;
            sdkSpriteDrawAt(sprite, lockedHeaderX, lockedHeaderY, 0xFFU, 0xFFU, 0xFFU, portraitOpacity);
            position.x = 21.5f + originX;
            position.y = 42.0f + originY;
            portraitTexture = (u8 *)(menu->resource127C);
            portraitPivotX = (s16)(sdkSpriteScaledWidth(portraitTexture) / 2.0f);
            sdkSpriteDrawSized(portraitTexture, position.x, position.y, 0.0f, 0x18U, 0U, 8U, portraitOpacity, 0x1000, 0x1000, portraitPivotX, menu->rotation, (s16)(sdkSpriteScaledHeight(portraitTexture) / 2.0f));
            break;
        case 3:
            specialHeaderX = 79.0f + originX;
            position.x = specialHeaderX;
            specialHeaderY = 133.0f + originY;
            position.y = specialHeaderY;
            sprite = menu->resource1270;
            sdkSpriteDrawAt(sprite, specialHeaderX, specialHeaderY, 0xFFU, 0xFFU, 0xFFU, portraitOpacity);
            position.x = 21.5f + originX;
            position.y = 42.0f + originY;
            sprite = menu->resource1274;
            zoomRatio = 1.0f + menu->zoom;
            portraitScale = 4096.0f * zoomRatio;
            position.x = (21.5f + originX) - (100.0f * menu->zoom);
            sdkSpriteDrawSized(sprite, position.x, position.y, 0.0f, 0x18U, 0U, 8U, portraitOpacity, (u16)portraitScale, (u16)portraitScale, (s64)0, 0.0f, (s64)0);
            break;
        }
        for (detailIndex = 0; detailIndex < menu->detailCount; detailIndex++) {
            if (detailIndex == menu->selectedDetail) {
                palette = (MenuColor *)D_0064B2E8;
                rowFontMode = 8;
            } else {
                palette = (MenuColor *)D_0064B2E0;
                rowFontMode = 6;
            }
            rowAnimation = (u8 *)(work + (detailIndex * 0x30));
            position.x = 15.0f + (originX + *(f32 *)(rowAnimation + 0x2B0));
            position.y = 28.0f * (f32)detailIndex + (178.0f + (originY + *(f32 *)(rowAnimation + 0x2B4)));
            rowAlpha = (u8)(*( u8 *)((u8 *)(rowAnimation) + (0x2BA)));
            rowAlphaFloat = (f32)rowAlpha;
            rowOpacityProduct = rowAlphaFloat * globalOpacity;
            rowQuantized = (u8)rowOpacityProduct;
            rowOpacity = rowQuantized & 0xFF;
            rowColor = rowOpacity | ~0xFF;
            sprite = menu->resource125C;
            sdkSpriteDrawAt(sprite, position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            sprite = menu->resource1260;
            sdkSpriteDrawAt(sprite, 172.0f + position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            frFontExDrawTextOutB(91.0f + position.x, position.y, 0.0f, rowColor, rowFontMode, 2, (const char *)datPersonaDisplayName(*(s16 *)(work + detailIndex * 2 + 0x136)), 8, 0x18, -1);
        }
        detailOpacity = (u8)(menu->detailOpacity);
        if (detailOpacity > 0) {
            detailAlphaFloat = (f32)detailOpacity;
            detailOpacityProduct = detailAlphaFloat * globalOpacity;

            datPortraitTextDraw(menu->resource1310, (u8)detailOpacityProduct);
            switch (selectedMode) {
            case 0:
            case 1:
                break;
            case 2:
                datPortraitGetPosition(menu->resource1310, &position);
                position.x += 162.0f;
                position.y += 7.0f;
                sprite = menu->resource1280;
                sdkSpriteDrawAt(sprite, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, detailOpacity);
                break;
            case 3:
                datPortraitGetPosition(menu->resource1310, &position);
                position.x += 162.0f;
                position.y += 7.0f;
                sprite = menu->resource1294;
                sdkSpriteDrawAt(sprite, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, detailOpacity);
                break;
            default:
                kAssertFail(&D_0064CC98, 0x455);
                break;
            }
        }
        footerAlpha = (u8)(menu->detailFooterOpacity);
        footerAlphaFloat = (f32)footerAlpha;
        footerOpacityProduct = footerAlphaFloat * globalOpacity;
        footerQuantized = (u8)footerOpacityProduct;
        footerOpacity = footerQuantized & 0xFF;
        position.x = (227.0f + (originX + menu->detailFooterOffset.x));
        position.y = (f32) 0x13D + (originY + menu->detailFooterOffset.y);
        sprite = menu->resource126C;
        sdkSpriteDrawAt(sprite, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], footerOpacity);
        position.x = (234.0f + (originX + menu->detailFooterOffset.x));
        position.y = (320.0f + (originY + menu->detailFooterOffset.y));
        palette = (MenuColor *)D_0064B2E8;
        sprite = menu->resource1264;
        sdkSpriteDrawAt(sprite, position.x, position.y, palette->r, palette->g, palette->b, footerOpacity);
        sprite = menu->resource1268;
        sdkSpriteDrawAt(sprite, (f32) 0x173 + position.x, position.y, palette->r, palette->g, palette->b, footerOpacity);
        if (menu->detailCount > 0) {
            detailId = *(u16 *)((u8 *)add_offset_first((u32)(menu->selectedDetail * 2), (u32)work) + 0x136);
            currentRank = (s32)(cmmCommunityRecordValue(*nameId) & 0xFFFF);
            detailValues = cmmDetailRecord((s16)detailId);
            position.x = (244.0f + (originX + menu->detailFooterOffset.x));
            position.y = (320.0f + (originY + menu->detailFooterOffset.y));
            numberAlpha = (u8)(menu->detailFooterOpacity);
            numberAlphaFloat = (f32)numberAlpha;
            numberOpacityProduct = numberAlphaFloat * globalOpacity;
            numberQuantized = (u8)numberOpacityProduct;
            numberOpacity = numberQuantized & 0xFF;
            numberColor = numberOpacity | ~0x7EFF;
            detailValue = *(s16 *)((u8 *)add_offset_first((u32)(currentRank & 0xFFFF) * 2, (u32)detailValues) - 2);
            fclMesWindowDrawItem(position.x, position.y, 0.0f, numberColor, 1, 8, 7, detailValue - 1);
            numberColor = numberOpacity | ~0xFF;
            fclMesWindowDrawItem(position.x, 28.0f + position.y, 0.0f, numberColor, 1, 6, 7, detailValue);
        }
    }
    if (menu->flags & 0x20) {
        position.x = (18.0f + (originX + menu->leftHintOffset.x));
        position.y = (f32) 0x197 + (originY + menu->leftHintOffset.y);
        leftHintAlpha = (u8)(menu->leftHintOpacity);
        leftHintAlphaFloat = (f32)leftHintAlpha;
        leftHintOpacityProduct = leftHintAlphaFloat * globalOpacity;
        leftHintOpacity = (u8)leftHintOpacityProduct;
        sdkSpriteDrawAt(menu->resource11E4, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, leftHintOpacity & 0xFF);
    }
    if (menu->flags & 0x40) {
        position.x = (18.0f + (originX + menu->rightHintOffset.x));
        position.y = (f32) 0x197 + (originY + menu->rightHintOffset.y);
        rightHintAlpha = (u8)(menu->rightHintOpacity);
        rightHintAlphaFloat = (f32)rightHintAlpha;
        rightHintOpacityProduct = rightHintAlphaFloat * globalOpacity;
        rightHintOpacity = (u8)rightHintOpacityProduct;
        sdkSpriteDrawAt(menu->resource12A0, position.x, position.y, 0xFFU, 0xFFU, 0xFFU, rightHintOpacity & 0xFF);
    }
    position.x = (640.0f + (originX + menu->footerOffset.x));
    position.y = (400.0f + (originY + menu->footerOffset.y));
    cursorAlpha = (u8)(menu->footerOpacity);
    cursorAlphaFloat = (f32)cursorAlpha;
    cursorOpacityProduct = cursorAlphaFloat * globalOpacity;
    cursorOpacity = (u8)cursorOpacityProduct;
    sdkSpriteDrawFooter(position, 0.0f, (u8)(cursorOpacity & 0xFF), menu->footerId, menu->resource1304);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Step each of the community menu's 108 entries once through their update function [inferred]
// FUN_00359340
void datCommunityEntriesStep(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        datCommunityEntryStep(arg0 + i * 0x14 + 0x960);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Bounce step: halve the community menu's vertical velocity and reverse its direction [inferred]
// FUN_003593B0
void datCommunityBounceStep(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Push a value into a community history slot: move the current value to the previous one and store the new value [inferred]
// FUN_003593E0
s32 datCommunityPushValue(s32 arg0, s32 arg1, s16 arg2)
{
    s32 off = arg1 * 2;
    u8 *p = (u8 *)(off + (s32)arg0);

    *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x24);
    *(s16 *)(p + 0x24) = arg2;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants on
// Intent: Select the community table for a mode: fill its 43 entries and the table's count and width; returns 0 when the mode is already set [inferred]
// FUN_00359400
s32 datCommunitySetTableMode(u8 *arg0, s32 arg1)
{
    extern u8 D_0064B420[];
    extern u8 D_0064B8E0[];
    extern u8 D_0064BDA0[];
    extern u8 D_0064C260[];
    extern u8 D_0064C720[];
    u8 *table;
    f32 value1;
    f32 value2;
    s32 i;
    s32 j;
    s32 off;
    u8 *dst;
    u8 *src;

    if (arg1 == *(s32 *)(arg0 + 0x18)) {
        return 0;
    }
    for (i = 0; i < 43; i++) {
        off = i * 0x30;
        dst = arg0 + off;
        *(f32 *)(dst + 0x150) = *(f32 *)(dst + 0x160);
        *(f32 *)(dst + 0x154) = *(f32 *)(dst + 0x164);
        *(u16 *)(dst + 0x16C) = *(u16 *)(dst + 0x170);
        *(u16 *)(dst + 0x172) = *(u16 *)(dst + 0x176);
        *(u8 *)(dst + 0x168) = *(u8 *)(dst + 0x16A);
    }
    switch (arg1) {
    case 0:
        table = D_0064B420;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 1:
        table = D_0064BDA0;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    case 2:
        table = D_0064C260;
        *(s32 *)(arg0 + 0x1C) = 55;
        break;
    case 3:
        table = D_0064C720;
        *(s32 *)(arg0 + 0x1C) = 70;
        *(s16 *)(arg0 + 0x14C) = 17;
        break;
    case 4:
        table = D_0064B8E0;
        *(s32 *)(arg0 + 0x1C) = 53;
        *(s16 *)(arg0 + 0x14C) = 16;
        break;
    default:
        kAssertFail(&D_0064CC98, 0x51F);
        break;
    }
    if (table != NULL) {
        j = 0;
        goto table_loop_test;
table_loop_body:
        off = j * 0x1C;
        src = table + off;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x158) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x15C) = *(f32 *)(src + 4);
        value1 = *(f32 *)(src + 8);
        *(u16 *)(dst + 0x16E) = (u16)value1;
        value2 = *(f32 *)(src + 0xC);
        *(u16 *)(dst + 0x174) = (u16)value2;
        *(u8 *)(dst + 0x169) = *(u8 *)(src + 0x10);
        *(s32 *)(dst + 0x178) = *(s32 *)(src + 0x14);
        *(s32 *)(dst + 0x17C) = *(s32 *)(src + 0x18);
        j += 1;
table_loop_test:
        if (j < 43) {
            goto table_loop_body;
        }
    }
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 0x20) = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Report whether every community entry's threshold is met and the external check passes; returns 1 when the community list is ready [inferred]
// FUN_003596A0
s32 datCommunityIsReady(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 43) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x17C)) {
            flag = 0;
        }
        i++;
    }
    return flag & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Release the community menu: free its sprite nodes, destroy its wipe and helper tasks, and reset its count [inferred]
// FUN_00359720
void datCommunityMenuRelease(u8 *arg0)
{
    s32 handle;
    s32 handle1308;
    s32 handle130C;
    s32 handle1310;
    s32 index;
    u8 *slot;

    index = 0;
    goto loop_test;
loop_body:
    slot = arg0 + (index * 4) + 0x11D0;
    handle = *(s32 *)slot;
    if (handle != 0) {
        sdkSpriteFreeNode((void *)handle);
        *(s32 *)slot = 0;
    }
    index += 1;
loop_test:
    if (index < 0x4D) {
        goto loop_body;
    }
    handle1308 = *(s32 *)(arg0 + 0x1308);
    if (handle1308 != 0) {
        kwlnTaskDestroyWithHierarchy(handle1308);
        *(s32 *)(arg0 + 0x1308) = 0;
    }
    handle130C = *(s32 *)(arg0 + 0x130C);
    if (handle130C != 0) {
        kwlnTaskDestroyWithHierarchy(handle130C);
        *(s32 *)(arg0 + 0x130C) = 0;
    }
    handle1310 = *(s32 *)(arg0 + 0x1310);
    if (handle1310 != 0) {
        kwlnTaskDestroyWithHierarchy(handle1310);
        *(s32 *)(arg0 + 0x1310) = 0;
    }
    *(s32 *)(arg0 + 0x1C) = 0;
    nmMesWindowReleaseHandle(0xB);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Fill the community menu's visible record list from the kind table, keeping entries with a value and a passing flag [inferred]
// FUN_003597F0
void datCommunityFillVisibleRecords(u8 *arg0)
{
    s32 table;
    s32 flagId;
    s32 index;
    s32 count;
    u8 *entry;
    u8 *valuePtr;

    table = cmmKindRecord(
        *(u16 *)((u8 *)add_offset_first(
            (s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC,
            (u32)arg0) + 0x3A));
    index = 0;
    count = 0;
    goto loop_test;
loop_body:
    entry = (u8 *)(table + (index * 8));
    valuePtr = entry + 0x28;
    if ((*(s32 *)valuePtr != 0) &&
        ((flagId = *(s32 *)(entry + 0x24), flagId == 0) ||
         (datGetFlag(flagId) != 0))) {
        *(s16 *)(arg0 + (count * 2) + 0x136) = *(s32 *)valuePtr;
        count += 1;
    }
    index += 1;
loop_test:
    if (index < 8) {
        goto loop_body;
    }
    *(s32 *)(arg0 + 0x148) = count;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants on
// Intent: Set the five community slot positions: the active slots move to the off-screen start and the current slot to its resting position [inferred]
// FUN_003598D0
void datCommunitySetSlotLayout(u8 *arg0)
{
    s32 activeCount;
    s32 index;
    f32 value_1;
    f32 value_2;
    f32 value_3;
    s32 value_4;
    f32 value_5;

    activeCount = *(s16 *)(arg0 + 0x24);
    index = 0;
    value_1 = 800.0f;
    value_2 = -400.0f;
    value_3 = 29.5f;
    value_4 = 1;
    value_5 = 22.0f;
    goto loop_test;
loop_body:
    if (index != activeCount) {
        if (index < activeCount) {
            *(f32 *)(arg0 + (index * 0x30) + 0x5AC) = value_2;
            *(f32 *)(arg0 + (index * 0x30) + 0x18C) = value_2;
        } else {
            *(f32 *)(arg0 + (index * 0x30) + 0x5AC) = value_1;
            *(f32 *)(arg0 + (index * 0x30) + 0x18C) = value_1;
        }
        *(f32 *)(arg0 + (index * 0x30) + 0x4B8) = value_5;
        *(s16 *)(arg0 + (index * 0x30) + 0x4CE) = value_4;
    } else {
        *(f32 *)(arg0 + (index * 0x30) + 0x5AC) = value_3;
        *(s16 *)(arg0 + (index * 0x30) + 0x5C4) = value_4;
        *(f32 *)(arg0 + (index * 0x30) + 0x18C) = value_3;
        *(s16 *)(arg0 + (index * 0x30) + 0x1A4) = value_4;
        *(f32 *)(arg0 + (index * 0x30) + 0x4BC) = value_3;
        *(s16 *)(arg0 + (index * 0x30) + 0x4D4) = value_4;
    }
    index += 1;
loop_test:
    if (index < 5) {
        goto loop_body;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Reset the community entry's vertical offset and its target to fixed values [inferred]
// FUN_003599A0
void datCommunityResetOffset(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}
#pragma pop

/* measured 003599c0: object 1173 instrs against retail 1190 stripped (1192 raw; -17, -1.4%; band
   1156-1228) via `python3 tools/fnalign.py src/promoted/code1_0035.c func_003599c0 --candidate
   /tmp/3599c0_fix6.c`, 853 edits (+2 reloc-only). Frame object 0x130 vs retail 0x120
   (long-lived u16 spills quad, not half); calls 17/17 (11x0034f320 + 0046d730/0046b260/
   0045d6e0/00275020/00246830 + D_00887300 jalr); lwc1 20/20, swc1 12/12. Float landmarks exact
   (f25/f24/f26/f21/f22/f23/f28/f27/f20/f29/f30, shared madd products per 7r, descending float decls);
   residual is int-color allocation (params stuck $s0/$s1), v30 stack spill, and CSE-held o-base
   recomputes (first-3 via b, last-2 via o but CSE to b) plus conversion scheduling (object converts
   before lui/lw, retail after). Fixes: e0=(s128)*(u16*)(e+0x3C) quad plus f0v direct (was missing
   0x3C load, w3A word intermediate removed) for lhu/sh/sq; b-split f3/f2/f28/f27/f4b/f1c via o
   to keep o live (addu +9 residual); f20 inside if(mode!=1) for second div (lui/mtc1 +1 each);
   switch(mode) case1/case0 fallthrough shared (was (mode==1)||(mode==0) sltiu, now beq 3,2,1,0
   with bodies loop,2,3 per M2C order 1/0,2,3); unsigned av for divu. Honest: slti for retail
   slti, sltiu only where retail sltiu (isSelf ==), u8/u16 casts, s128 quad, indirect D_00887300[0];
   prototypes per recon (0034f320 x13, 0045d6e0 x4, 00246830 returns u8 *). No sltiu-for-slti,
   no s64 flat, no opt_propagation, no volatile, no asm.
   Deficit-vs-composition (2026-09-20): deficit is 17; `deficit_scan` classes the large runs CROSS
   (125 at 0x35a02c, 96 at 0x359cfc paired 2/92 nearby, 60 at 0x35a400), so the composition
   223 missing / 212 extra (7 deletes, 11 inserts, 74 replaces with 71 <=13) is alignment artefact
   of the repeated (u16) clamp + 0034f320 idiom, not unwritten code. Counterparts: obj 92
   (164:256) against ret 96 (207:303) col[3]/rc/o2 block; obj 79+42 (383:462, 337:379) against
   ret 125 (411:536) 0x11ec block; obj 21 (632:653) against ret 60 (656:716) 0x122c block.
   Probes: f3 via b1 1173/854/223/212 unchanged; f0v load late 1175/852/223/212 (adds lq, worse).
   No mass apply; body left unchanged, in band near finished.
   2026-10-08: opt_propagation off lowers fnalign from 672 to 598 edits. */
/* Party HUD panel draw. Each of the three panel groups has its own x/y/w/h
   locals (separate live ranges, as retail). Panel x/y/alpha and the sprite
   table go through hudOffsetPtr_003599c0 (offset + base). The panel width
   reads are spelled index-first, because retail recomputes index + arg1 for
   each width read; the heights use the struct view. */
static inline u8 *hudOffsetPtr_003599c0(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

typedef struct {
    f32 x;
    f32 y;
    u8 pad8[2];
    u8 alpha;
    u8 padB[5];
    u16 w;
    u8 pad12[4];
    u16 h;
    u8 pad18[0x18];
} HudPanel_0035;

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_pulloutconstants off
#pragma opt_lifetimes on
// Intent: Draw the party HUD panel: the three panel groups with their names, counts and modes, using the HUD sprite table [inferred]
// FUN_003599C0
void datPartyHudDraw(s32 arg0, u8 *arg1)
{
    extern void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5, u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
    extern void PrimDrawFlatRectangle(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2);
    /* H011: the callee masks its argument with 0xFFFF. */
    /* H011: the u16 parameter is measured; the u32 definition (cmmMisc.c)
       mismatches the name-sprite call. */
    extern u8 *cmmNameRecord(u16 arg0);
    extern s32 frFontExDrawTextWithCharWidth(f32 arg0, f32 fparg0, f32 fparg1, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5, s32 arg6);
    extern f32 sdkSpriteScaledWidth(u8 *arg0);
    extern s32 (*D_00887300[])(s32, s32);
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E9[];
    extern u8 D_0064B2EA[];
    extern u8 D_0064B2EB[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2F8[];
    u8 col[4];
    s32 rc[4];
    u16 name;
    s32 count;
    f32 w2;
    f32 h2;
    f32 fade;
    f32 x0;
    f32 y0;
    f32 x2;
    f32 y2;
    f32 rowY;
    f32 px;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 scale;
    f32 py;
    f32 w3;
    f32 h3;
    f32 x3;
    f32 y3;
    u8 kind;
    s32 isSelf;
    s32 mode;
    u8 alpha;
    u8 *ptab;
    u8 *ctab;
    s32 nameColor;
    u8 *spr;
    s32 i;
    s32 limit;
    s32 nameAlpha;
    x0 = *(f32 *)(arg1 + 4);
    y0 = *(f32 *)(arg1 + 8);
    fade = (f32)arg1[0] / 255.0f;
    {
        s32 off = (*(s16 *)(arg1 + 0x26) + arg0) * 12;

        kind = *(u8 *)((u32)off + (u32)arg1 + 0x38);
        name = *(u16 *)((u32)off + (u32)arg1 + 0x3A);
        count = *(u16 *)((u32)off + (u32)arg1 + 0x3C);
        if (kind >= 0x20) {
            kAssertFail(D_0064CC98, 0x5D5);
        }
        isSelf = (arg0 == *(s16 *)(arg1 + 0x24));
        mode = *(s32 *)(off + (s32)arg1 + 0x40);
    }
    x = x0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x5B0);
    rowY = 64.0f * (f32)arg0;
    y = 81.0f + (rowY + (y0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x5B4)));
    scale = (f32)hudOffsetPtr_003599c0(arg0 * 48, arg1)[0x5BA];
    alpha = scale * fade;
    w = (f32)*(u16 *)((u8 *)(arg0 * 48) + (u32)arg1 + 0x5c0);
    h = (f32)((HudPanel_0035 *)(arg1 + 0x5B0))[arg0].h;
    if (isSelf) {
        u8 r = D_0064B2E8[0];
        u8 g = D_0064B2E9[0];
        u8 b = D_0064B2EA[0];
        u8 aa = D_0064B2EB[0];

        col[0] = r;
        col[1] = g;
        col[2] = b;
        col[3] = aa;
    } else {
        *(f32 *)col = *(f32 *)D_0064B2E0;
    }
    col[3] = (f32)alpha * fade;
    rc[0] = x;
    rc[1] = y;
    rc[2] = 640.0f * w / 4096.0f;
    rc[3] = 59.0f * h / 4096.0f;
    D_00887300[0](1, 0);
    PrimDrawFlatRectangle(col, (u8 *)rc, 0.0f, 0);
    x2 = 5.0f + (x0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x190));
    y2 = 78.0f + (rowY + (y0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x194)));
    scale = (f32)hudOffsetPtr_003599c0(arg0 * 48, arg1)[0x19A];
    alpha = scale * fade;
    w2 = (f32)*(u16 *)((u8 *)(u32)(arg0 * 48) + (u32)arg1 + 0x1a0);
    h2 = (f32)((HudPanel_0035 *)(arg1 + 0x190))[arg0].h;
    if (isSelf) {
        ptab = D_0064B2EC;
        ctab = D_0064B2E8;
        nameColor = 8;
    } else {
        ptab = D_0064B2F8;
        ctab = D_0064B2E0;
        nameColor = 6;
    }
    if (mode != 1) {
        px = 60.0f + x2;
        scale = h2 / 4096.0f;
        py = y2 + 16.0f * scale;
        spr = *(u8 **)(arg1 + 0x11E8);
        sdkSpriteDrawSized(spr, px, py, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
        px = 124.0f + x2;
        py = y2 + 14.0f * scale;
        spr = *(u8 **)(hudOffsetPtr_003599c0((count & 0xFFFF) * 4, arg1) + 0x11EC);
        sdkSpriteDrawSized(spr, px, py, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    }
    px = 59.0f + x2;
    scale = h2 / 4096.0f;
    py = y2 + 32.0f * scale;
    spr = *(u8 **)(arg1 + 0x1214);
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    spr = *(u8 **)(arg1 + 0x1218);
    sdkSpriteDrawSized(spr, 88.0f + px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    px = 105.0f + x2;
    py = y2 + 33.0f * scale;
    spr = *(u8 **)(hudOffsetPtr_003599c0(kind * 4, arg1) + 0x12A0);
    sdkSpriteDrawSized(spr, px - sdkSpriteScaledWidth(spr) / 2.0f, py, 0.0f,
                  ctab[0], ctab[1], ctab[2], alpha, w2, h2, 0, 0.0f, 0);
    px = 156.0f + x2;
    py = y2 + 18.0f * scale;
    spr = *(u8 **)(arg1 + 0x122C);
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    spr = *(u8 **)(arg1 + 0x1230);
    sdkSpriteDrawSized(spr, 214.0f + px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    switch (mode) {
    case 0:
    case 1:
        px = 4.0f + (157.0f + x2);
        py = y2 + 20.0f * scale;
        ptab = *(u8 **)(arg1 + 0x1234);
        i = 0;
        limit = count & 0xFFFF;
        for (; i < 10 && i < limit; i++) {
            sdkSpriteDrawSized(ptab, px + (f32)(i * 21), py, 0.0f,
                          ctab[0], ctab[1], ctab[2], alpha, w2, h2, 0, 0.0f, 0);
        }
        break;
    case 2:
        px = 198.0f + x2;
        py = y2 + 14.0f * scale;
        sdkSpriteDrawSized(isSelf ? *(u8 **)(arg1 + 0x1240) : *(u8 **)(arg1 + 0x1244), px, py, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, w2, h2, 0, 0.0f, 0);
        break;
    case 3:
        px = 204.0f + x2;
        py = y2 + 14.0f * scale;
        sdkSpriteDrawSized(isSelf ? *(u8 **)(arg1 + 0x1238) : *(u8 **)(arg1 + 0x123C), px, py, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, w2, h2, 0, 0.0f, 0);
        break;
    }
    if (h2 == 4096.0f) {
        px = 157.0f + x2;
        scale = y2 + 30.0f * scale;
        nameAlpha = (alpha * 0xFF) / 0xFFU;
        spr = cmmNameRecord(name);
        frFontExDrawTextWithCharWidth(px, scale, 0.0f, -0x100 | nameAlpha, nameColor, 1, spr, 0, -1);
    }
    x3 = 5.0f + (x0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x4C0));
    y3 = 78.0f + (rowY + (y0 + *(f32 *)(hudOffsetPtr_003599c0(arg0 * 48, arg1) + 0x4C4)));
    scale = (f32)hudOffsetPtr_003599c0(arg0 * 48, arg1)[0x4CA];
    kind = scale * fade;
    w3 = (f32)*(u16 *)((u8 *)(u32)(arg0 * 48) + (s32)arg1 + 0x4d0);
    h3 = (f32)((HudPanel_0035 *)(arg1 + 0x4C0))[arg0].h;
    px = 15.0f + x3;
    py = 2.0f + y3;
    spr = *(u8 **)(hudOffsetPtr_003599c0(mode * 4, arg1) + 0x121C);
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  0xFF, 0xFF, 0xFF, kind, w3, h3, 0, 0.0f, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set up a screen wipe slot from one of the two slot entries: initialise its positions or move it to its target, then set its offset and colour [inferred]
// FUN_0035AC60
void datScreenWipeSetupSlot(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    Float2 pair;
    s32 value;
    u8 *pairSrc;
    u8 *posA;
    u8 *posB;

    if ((arg1 < 0) || (arg1 >= 2)) {
        kAssertFail(&D_0064CC98, 0x6B8);
    }
    if (arg0 == NULL) {
        kAssertFail(&D_0064CC98, 0x6B9);
    }
    if (arg3 != 0) {
        posB = D_0064CC60 + (arg1 * 0x1C);
        posA = posB + 8;
    } else {
        posA = D_0064CC60 + (arg1 * 0x1C);
        posB = posA + 8;
    }
    pairSrc = D_0064CC70 + (arg1 * 0x1C);
    pair = *(Float2 *)pairSrc;
    value = *(s32 *)(D_0064CC78 + (arg1 * 0x1C));
    if (arg2 != 0) {
        datScreenWipeInit(arg0, (Float2 *)posA, (Float2 *)posB);
    } else {
        datScreenWipeSetTarget(arg0, posB);
    }
    datScreenWipeSetOffset(arg0, pair);
    datScreenWipeSetColor(arg0, value);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Create the portrait task with its update and destroy callbacks and set up its first slot [inferred]
// FUN_0035ADC0
u8 *datPortraitTaskCreate(s32 arg0, s64 arg1, s32 arg2)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(&D_0064CC98, 0x6ED);
    work = D_008873F4[0](1, 0x144, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064CC98, 0x6EE);
    }
    task = kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_0064CCD0), 0xC7, 0, 0, datPortraitUpdate, datPortraitDestroy, (u8 *)(work));
    *(s8 *)(work + 0x20) = 0;
    *(s32 *)(work + 0x2C) = 0;
    *(u8 **)(work + 0x140) = D_0064CCB0;
    {
        extern void datPortraitSetValue();
        datPortraitSetValue((s32)task, arg1, arg2);
    }
    return task;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Portrait task update: start the portrait's text load when the portrait is active and not yet loaded [inferred]
// FUN_0035AEC0
s32 datPortraitUpdate(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(s8 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = datTextSlotLoadStep(p + 0x30);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Portrait task destroy: release the portrait's text slot and the work block [inferred]
// FUN_0035AF10
void datPortraitDestroy(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    datTextSlotRelease(work + 0x30);
    (*D_008873EC)(work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Report whether the portrait is loaded and active [inferred]
// FUN_0035AF60
s32 datPortraitIsLoaded(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(work + 0x2C) == 0) || (*(s8 *)(work + 0x20) == 0)) {
        return 0;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Return the portrait's value once it is loaded and active, otherwise 0 [inferred]
// FUN_0035AFA0
s32 datPortraitValue(u8 *arg0) {
    s32 ready;
    u8 *work;

    work = (u8 *)(*(u8 **)(arg0 + 0x38));
    if ((*(s32 *)(work + 0x2C) == 0) || (*(s8 *)(work + 0x20) == 0)) {
        ready = 0;
    } else {
        ready = 1;
    }
    if (ready != 0) {
        return (s32)(**(s32 **)(work + 0x3C));
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
/* Community portrait and selected-state passes. Measured whole-owner MATCH:
 * 2772 bytes plus twelve retail zero bytes; byte-opacity/RGBA and the complete
 * Sky2 vertex layout retain the actual ABI. The work pointer is captured on
 * entry, visibility is re-read after the camera query, and texture and mode
 * are loaded after their rendering callbacks. Keep the table addresses while
 * reloading their callback slots. Loop invariants and scoped lifetimes retain
 * the retail color conversions and row/index bases without synthetic padding.
 * See docs/probe_archive/Community_portrait_0035aff0_20260930.md. */
// Intent: Draw the community portrait: its sprite and rendering passes for the selected state [inferred]
// FUN_0035AFF0
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
f32 datCommunityPortraitDraw(u8 *arg0, u8 arg1)
{
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern f32 datPortraitMoveStep(u8 *arg0);
    extern void sdkRenderStateSetDefault(void);
    extern s32 (*D_00887300[])(s32, void *);
    extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    extern s32 (*D_00887314[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
    extern s32 RpSkyRenderStateSet(s32 arg0, void *arg1);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern f32 cosf(f32 arg0);
    extern f32 datPortraitDirectionBlend(Float2 first, Float2 second, Float2 origin);
    extern f32 fGpffff81e0;
    extern f32 fGpffff82fc;
    /* Full Sky2 layout from rw/sky2/rwplcore.h. The strip backends copy all
     * 64 bytes. This renderer initializes only position, UV/reciprocal depth
     * and RGBA; fog is disabled and the SDK declares normals unused. */
    typedef struct {
        f32 x, y, z, cameraZ;
        f32 u, v, reciprocalZ, fogPadding;
        f32 red, green, blue, alpha;
        f32 normalX, normalY, normalZ, alignmentPadding;
    } CommunityVertex;
    typedef struct { u8 red, green, blue, alpha; } CommunityColor;
    typedef struct { void *raster; } CommunityTexture;
    typedef struct {
        Float2 position;
        Float2 scale;
        Float2 targetScale;
        Float2 startScale;
        s8 portraitId;
        u8 unknown0021;
        s16 transitionFrame;
        s16 effectFrame;
        u8 unknown0026[2];
        s32 flags;
        s32 loaded;
        u8 unknown0030[12];
        CommunityTexture *texture;
        u8 unknown0040[0x100];
        const char *module;
    } CommunityPortrait;
    typedef struct {
        u8 unknown0000[0x38];
        u8 *work;
    } CommunityPortraitTask;
    typedef struct {
        u8 unknown0000[0x80];
        f32 nearClip;
    } CommunityCameraView;
    CommunityVertex qs[4];
    Float2 cur;
    Float2 ptA;
    Float2 ptB;
    CommunityVertex verts[35];
    struct IndexPair { s16 top, bottom; } idx[32];
    CommunityPortrait *portrait;
    f32 sx;
    f32 sy;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    f32 blend;
    f32 z;
    f32 q;
    f32 ang1;
    f32 ang2;
    f32 s1;
    f32 c1;
    f32 s2;
    f32 c2;
    s32 mode;
    s32 j;
    s32 vtx;
    s32 i;
    s32 ii;
    s32 jj;
    CommunityColor color;
    s32 (**stateSet)(s32, void *);

    /* The SDK task transports its work as u8 *; the captured value and the
     * post-camera visibility view deliberately have separate lifetimes. */
    portrait = (CommunityPortrait *)*(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / ((CommunityCameraView *)kwlnGetCamera())->nearClip;
    {
        CommunityPortrait *t = (CommunityPortrait *)((CommunityPortraitTask *)arg0)->work;
        s32 flag;
        if ((t->loaded == 0) || (t->portraitId == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    blend = datPortraitMoveStep((u8 *)portrait);
    sx = 50.0f * portrait->scale.x;
    sy = 64.0f * portrait->scale.y;
    if (portrait->flags & 1) {
        u0 = 0.78125f;
        v0 = 1.0f;
        u1 = -0.78125f;
        v1 = -1.0f;
    } else {
        u0 = 0.0f;
        v0 = 0.0f;
        u1 = 0.78125f;
        v1 = 1.0f;
    }
    qs[0].x = portrait->position.x - sx;
    qs[0].y = portrait->position.y - sy;
    qs[0].z = z;
    qs[0].red = 255.0f;
    qs[0].green = 255.0f;
    qs[0].blue = 255.0f;
    qs[0].alpha = (f32)arg1;
    qs[0].u = u0;
    qs[0].v = v0;
    qs[0].reciprocalZ = q;
    qs[1].x = portrait->position.x + sx;
    qs[1].y = portrait->position.y - sy;
    qs[1].z = z;
    qs[1].red = 255.0f;
    qs[1].green = 255.0f;
    qs[1].blue = 255.0f;
    qs[1].alpha = (f32)arg1;
    qs[1].u = u0 + u1;
    qs[1].v = v0;
    qs[1].reciprocalZ = q;
    qs[2].x = portrait->position.x - sx;
    qs[2].y = portrait->position.y + sy;
    qs[2].z = z;
    qs[2].red = 255.0f;
    qs[2].green = 255.0f;
    qs[2].blue = 255.0f;
    qs[2].alpha = (f32)arg1;
    qs[2].u = u0;
    qs[2].v = v0 + v1;
    qs[2].reciprocalZ = q;
    qs[3].x = portrait->position.x + sx;
    qs[3].y = portrait->position.y + sy;
    qs[3].z = z;
    qs[3].red = 255.0f;
    qs[3].green = 255.0f;
    qs[3].blue = 255.0f;
    qs[3].alpha = (f32)arg1;
    qs[3].u = u0 + u1;
    qs[3].v = v0 + v1;
    qs[3].reciprocalZ = q;
    {
        s32 (**drawFirst)(s32, void *, s32);
        sdkRenderStateSetDefault();
        stateSet = D_00887300;
        stateSet[0](1, portrait->texture->raster);
        drawFirst = D_00887310;
        drawFirst[0](4, &qs[0], 4);
    }
    mode = portrait->flags;
    if (((mode & 1) != 0) || ((mode & 2) != 0)) {
        {
            s32 k;
            if ((mode & 1) != 0) {
                color.red = 0xF2;
                color.green = 0x15;
                color.blue = 0;
                color.alpha = 0xFF;
            } else {
                color.red = 0xF2;
                color.green = 0;
                color.blue = 0xBA;
                color.alpha = 0xFF;
            }
            for (k = 0; k < 4; k++) {
                CommunityVertex *vertex = &qs[k];
                vertex->red = (f32)color.red;
                vertex->green = (f32)color.green;
                vertex->blue = (f32)color.blue;
                vertex->alpha = (f32)color.alpha;
            }
        }
        {
            s32 (**drawPrimitive)(s32, void *, s32);
            mdlEffectEmitMaskedTagPair();
            RpSkyRenderStateSet(3, (void *)0x31801);
            drawPrimitive = D_00887310;
            drawPrimitive[0](4, &qs[0], 4);
            mdlEffectEmitTagPair();
            stateSet[0](1, 0);
            RpSkyRenderStateSet(3, (void *)0x31801);
            RpSkyRenderStateSet(2, (void *)0x58);
            drawPrimitive[0](4, &qs[0], 4);
            RpSkyRenderStateSet(3, (void *)0x717FB);
            RpSkyRenderStateSet(2, (void *)0x44);
        }
    } else if (mode & 4) {
        f32 f;
        f = (f32)portrait->effectFrame / 100.0f;
        ang1 = fGpffff81e0 * f;
        ang2 = fGpffff82fc + ang1;
        s1 = sinf(ang1);
        c1 = cosf(ang1);
        s2 = sinf(ang2);
        c2 = cosf(ang2);
        ptA.x = portrait->position.x + 0.78125f * (64.0f * s1);
        ptA.y = portrait->position.y - 64.0f * c1;
        ptB.x = portrait->position.x + 0.78125f * (64.0f * s2);
        ptB.y = portrait->position.y - 64.0f * c2;
        i = 0;
        vtx = 0;
        while (i < 7) {
            f32 rowDY;
            f32 rowV;
            j = 0;
            rowDY = 2.0f * (sy * ((f32)i / 6.0f - 0.5f));
            rowV = v0 + v1 * ((f32)i / 6.0f);
            while (j < 5) {
                f32 grey;
                u8 g8;
                cur.x = portrait->position.x + 2.0f * (sx * ((f32)j / 4.0f - 0.5f));
                cur.y = portrait->position.y + rowDY;
                verts[vtx].x = cur.x;
                verts[vtx].y = cur.y;
                verts[vtx].z = z;
                verts[vtx].u = u0 + u1 * ((f32)j / 4.0f);
                verts[vtx].v = rowV;
                verts[vtx].reciprocalZ = q;
                grey = 255.0f * datPortraitDirectionBlend(ptA, ptB, cur);
                g8 = (u8)grey;
                verts[vtx].red = (f32)g8;
                verts[vtx].green = (f32)g8;
                verts[vtx].blue = (f32)g8;
                verts[vtx].alpha = (f32)g8;
                vtx++;
                j++;
            }
            i++;
        }
        if (vtx > 35) {
            kAssertFail(&D_0064CC98, 0x835);
        }
        for (ii = 0; ii < 6; ii++) {
            for (jj = 0; jj < 5; jj++) {
                idx[ii * 5 + jj].top = (s16)(jj + ii * 5);
                idx[ii * 5 + jj].bottom = (s16)(jj + (ii + 1) * 5);
            }
        }
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(3, (void *)0x31801);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 5], 10);
        }
        mdlEffectEmitTagPair();
        stateSet[0](1, 0);
        RpSkyRenderStateSet(3, (void *)0x31801);
        RpSkyRenderStateSet(2, (void *)0x58);
        for (i = 0; i < 6; i++) {
            D_00887314[0](4, &verts[0], 0x23, &idx[i * 5], 10);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    return blend;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Advance the portrait's move step: count its timer, step its interpolation ratio to a maximum of 1 and move its position along an arc to the target [inferred]
// FUN_0035BAD0
f32 datPortraitMoveStep(u8 *arg0)
{
    f32 ratio;
    f32 angle;
    f32 fromX;
    f32 fromY;
    s16 step;

    *(s16 *)(arg0 + 0x24) = *(s16 *)(arg0 + 0x24) + 1;
    if (*(s16 *)(arg0 + 0x24) >= 0x64) {
        *(s16 *)(arg0 + 0x24) = 0;
    }
    step = *(s16 *)(arg0 + 0x22);
    if (step < 0xA) {
        *(s16 *)(arg0 + 0x22) = (s16)(step + 1);
    }
    ratio = (f32)*(s16 *)(arg0 + 0x22) / 10.0f;
    if ((ratio < 0.0f) || (ratio > 1.0f)) {
        kAssertFail(&D_0064CC98, 0x881);
    }
    angle = fGpffff84a4 * ratio;
    fromX = *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 8) = fromX + ((*(f32 *)(arg0 + 0x10) - fromX) * sinf(angle));
    fromY = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0xC) = fromY + ((*(f32 *)(arg0 + 0x14) - fromY) * sinf(angle));
    return ratio;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set the portrait's text value: reset its position and step, and write its text slot as a placeholder, a blank, or a numbered label when the value changes [inferred]
// FUN_0035BC10
void datPortraitSetValue(u8 *arg0, s8 arg1, s32 arg2)
{
    u8 *base;
    s8 old;
    u8 buf[0x100];

    base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x22) = 0;
    *(f32 *)(base + 0x0) = 71.5f;
    *(f32 *)(base + 0x4) = 106.0f;
    *(f32 *)(base + 0x10) = 1.0f;
    *(s32 *)(base + 0x18) = 0;
    *(f32 *)(base + 0x1C) = 1.0f;
    *(f32 *)(base + 0x14) = 1.0f;
    old = *(s8 *)(base + 0x20);
    if (old == arg1) {
        goto unchanged;
    }
    switch (arg1) {
    case -1:
        goto minus_one_case;
    case 0:
        goto zero_case;
    default:
        goto other_case;
    }
minus_one_case:
    sprintf(buf, D_0064CCF0);
    datTextSlotSetString((s32 *)(base + 0x30), buf);
    goto done;
zero_case:
    datTextSlotSetString((s32 *)(base + 0x30), NULL);
    goto done;
other_case:
    sprintf(buf, D_0064CD10, (s32)arg1 - 1);
    datTextSlotSetString((s32 *)(base + 0x30), buf);
done:
    *(s8 *)(base + 0x20) = arg1;
    *(s32 *)(base + 0x28) = arg2;
    *(s32 *)(base + 0x2C) = 0;
unchanged: ;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Blend the direction of two portrait points against a fixed normal, returning the clamped weighted projection [inferred]
// FUN_0035BD20
// MATCH: 332B/336B; retail ends with four zero bytes.
// IDA-backed Float2 values and in-place weighted COP1 accumulation.
f32 datPortraitDirectionBlend(Float2 first, Float2 second, Float2 origin)
{
    struct Vector3 { Float2 xy; f32 z; } normal, direction;
    extern struct Vector3 D_0064CD30;
    f32 total;
    f32 projection;

    normal = D_0064CD30;
    total = 0.0f;
    direction.xy.x = first.x - origin.x;
    direction.xy.y = first.y - origin.y;
    direction.z = 20.0f;
    RwV3dNormalize(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    interpolation_accumulate(&total, 1.0f, projection);
    direction.xy.x = second.x - origin.x;
    direction.xy.y = second.y - origin.y;
    direction.z = 20.0f;
    RwV3dNormalize(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    interpolation_accumulate(&total, 1.0f, projection);
    if (!(total <= 1.0f)) total = 1.0f;
    return total;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Portrait text task update: start the text load once the portrait is active and not yet loaded [inferred]
// FUN_0035BE70
s32 datPortraitTextLoadUpdate(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if ((((s32 *)p)[11] == 0) && (*(u16 *)(p + 0x20) != 0)) {
        *(s32 *)(p + 0x2C) = datTextSlotLoadStep(p + 0x30);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Portrait text task destroy: release the text slot and the work block [inferred]
// FUN_0035BEC0
void datPortraitTextDestroy(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    datTextSlotRelease(work + 0x30);
    (*D_008873EC)(work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Create the portrait text task with its update and destroy callbacks and place it at its start position [inferred]
// FUN_0035BF10
u8 *datPortraitTextTaskCreate(s32 arg0, u16 arg1, s32 arg2)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(&D_0064CC98, 0x905);
    work = D_008873F4[0](1, 0x144, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064CC98, 0x906);
    }
    task = kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_0064CD40), 0xC7, 0, 0, datPortraitTextLoadUpdate, datPortraitTextDestroy, (u8 *)(work));
    *(s16 *)(work + 0x20) = 0;
    *(s32 *)(work + 0x2C) = 0;
    *(f32 *)(work + 0x10) = 353.0f;
    *(s32 *)(work + 0x14) = 0x42BC0000;
    *(f32 *)(work + 8) = 300.0f + *(f32 *)(work + 0x10);
    *(f32 *)(work + 0xC) = *(f32 *)(work + 0x14);
    datPortraitSetLabel((s32)task, arg1, arg2);
    return task;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Draw the portrait text: its sprite pass with the portrait's colour, offset and opacity [inferred]
// FUN_0035C040
f32 datPortraitTextDraw(u8 *arg0, u8 arg1)
{
    f32 tx;
    f32 ty;
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern void shdDrawColourQuad(f32 depth, s32 color, f32 x, f32 y, f32 sx, f32 sy, f32 w, f32 h, s32 *tex, s32 mode, s32 flag);
    extern void sdkRenderStateSetDefault(void);
    extern s32 (*D_00887300[])(s32, s32);
    extern void (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        s32 _c;
        s32 u;
        s32 v;
        f32 q;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } Q40;
    u8 *p;
    f32 z;
    f32 q;
    f32 ret;
    s16 v;
    Q40 qs[4];

    p = *(u8 **)(arg0 + 0x38);
    z = D_008872F8[0];
    q = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
    {
        u8 *t = *(u8 **)(arg0 + 0x38);
        s32 flag;
        if ((*(s32 *)(t + 0x2C) == 0) || (*(u16 *)(t + 0x20) == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    v = *(s16 *)(p + 0x22);
    if (v <= 9) {
        *(s16 *)(p + 0x22) = v + 1;
    }
    ret = sinf(fGpffff84a4 * ((f32)*(s16 *)(p + 0x22) / 10.0f));
    if ((ret < 0.0f) || (ret > 1.0f)) {
        kAssertFail(&D_0064CC98, 0x936);
    }
    *(f32 *)p = *(f32 *)(p + 8) + ret * (*(f32 *)(p + 0x10) - *(f32 *)(p + 8));
    *(f32 *)(p + 4) = *(f32 *)(p + 0xC) + ret * (*(f32 *)(p + 0x14) - *(f32 *)(p + 0xC));
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + 0.25f * (*(f32 *)p - *(f32 *)(p + 0x18));
    *(f32 *)(p + 0x1C) = *(f32 *)(p + 0x1C) + 0.25f * (*(f32 *)(p + 4) - *(f32 *)(p + 0x1C));
    qs[0].x = *(f32 *)p;
    qs[0].y = *(f32 *)(p + 4);
    qs[0].z = z;
    qs[0].r = 0x437F0000;
    qs[0].g = 0x437F0000;
    qs[0].b = 0x437F0000;
    qs[0].a = (f32)arg1;
    qs[0].u = 0;
    qs[0].v = 0;
    qs[0].q = q;
    tx = *(f32 *)p;
    tx = tx + 256.0f;
    qs[1].x = tx;
    qs[1].y = *(f32 *)(p + 4);
    qs[1].z = z;
    qs[1].r = 0x437F0000;
    qs[1].g = 0x437F0000;
    qs[1].b = 0x437F0000;
    qs[1].a = (f32)arg1;
    qs[1].u = 0x3F800000;
    qs[1].v = 0;
    qs[1].q = q;
    qs[2].x = *(f32 *)p;
    ty = *(f32 *)(p + 4);
    ty = ty + 256.0f;
    qs[2].y = ty;
    qs[2].z = z;
    qs[2].r = 0x437F0000;
    qs[2].g = 0x437F0000;
    qs[2].b = 0x437F0000;
    qs[2].a = (f32)arg1;
    qs[2].u = 0;
    qs[2].v = 0x3F800000;
    qs[2].q = q;
    tx = *(f32 *)p;
    tx = tx + 256.0f;
    qs[3].x = tx;
    ty = *(f32 *)(p + 4);
    ty = ty + 256.0f;
    qs[3].y = ty;
    qs[3].z = z;
    qs[3].r = 0x437F0000;
    qs[3].g = 0x437F0000;
    qs[3].b = 0x437F0000;
    qs[3].a = (f32)arg1;
    qs[3].u = 0x3F800000;
    qs[3].v = 0x3F800000;
    qs[3].q = q;
    shdDrawColourQuad(0.0f, *(s32 *)(p + 0x28) | (arg1 & 0xFF), *(f32 *)(p + 0x18) + -30.0f, *(f32 *)(p + 0x1C), *(f32 *)p, *(f32 *)(p + 4), 256.0f, 256.0f, *(s32 **)(p + 0x3C), 1, 0);
    sdkRenderStateSetDefault();
    D_00887300[0](1, **(s32 **)(p + 0x3C));
    D_00887310[0](4, &qs[0], 4);
    return ret;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_loop_invariants off
// Intent: Set the portrait label for an id and flag set: choose the colour and suffix from the flags and write the label text, blank for ids without a day label [inferred]
// FUN_0035C480
void datPortraitSetLabel(s32 arg0, u16 arg1, s32 arg2)
{
    s8 sp168[8];
    u8 sp60[0x100];
    f32 x;
    f32 y;
    s64 suffix;
    u32 id;
    u8 *work;
    extern u8 iGpffffa968;
    extern u8 iGpffffa96c;
    extern u8 D_0064CD60[];

    work = *(u8 **)(arg0 + 0x38);
    *(s16 *)(work + 0x22) = 0;
    x = *(f32 *)(work + 8);
    y = *(f32 *)(work + 0xC);
    *(f32 *)(work + 0x18) = x;
    *(f32 *)(work + 0x1C) = y;
    x = *(f32 *)(work + 8);
    y = *(f32 *)(work + 0xC);
    *(f32 *)(work + 0) = x;
    *(f32 *)(work + 4) = y;
    id = arg1 & 0xFFFF;
    if ((*(u16 *)(work + 0x20) != id) ||
        (*(s32 *)(work + 0x24) != arg2)) {
        switch (id) {
        case 0:
            goto zero_case;
        default:
            goto nonzero_case;
        }
zero_case:
        datTextSlotSetString((s32 *)(work + 0x30), NULL);
        goto done;
nonzero_case:
        if (arg2 & 1) {
            *(s32 *)(work + 0x28) = 0xF6001600;
            suffix = 0x62;
        } else if (arg2 & 2) {
            *(s32 *)(work + 0x28) = 0xF600B000;
            suffix = 0x63;
        } else {
            *(s32 *)(work + 0x28) = 0xFFD13400;
            suffix = 0x61;
        }
        switch (id) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 19:
        case 21:
        case 24:
        case 26:
        case 27:
        case 29:
            if (calGetDayWindowFlags((s64)(s16)datGetDateIndex()) & 1) {
                sprintf(sp168, &iGpffffa968);
            } else {
                sprintf(sp168, &iGpffffa96c);
            }
            break;
        case 8:
        case 16:
        case 17:
        case 18:
        case 20:
        case 22:
        case 23:
        case 25:
        case 28:
        case 30:
            sp168[0] = 0;
            break;
        default:
            kAssertFail(&D_0064CC98, 0xA05);
            break;
        }
        sprintf(sp60, D_0064CD60, id, (s8)suffix, sp168);
        datTextSlotSetString((s32 *)(work + 0x30), sp60);
        goto done;
done:
        *(u16 *)(work + 0x20) = arg1;
        *(s32 *)(work + 0x24) = arg2;
        *(s32 *)(work + 0x2C) = 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Copy the portrait's stored position into the caller's vector [inferred]
// FUN_0035C670
void datPortraitGetPosition(u8 *arg0, Vec2f *position)
{
    *position = *(Vec2f *)(*(u8 **)(arg0 + 0x38));
}
#pragma pop
