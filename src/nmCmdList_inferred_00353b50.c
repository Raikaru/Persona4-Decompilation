/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/battle.c; members 00353b50-0035c670 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "sdktask.h"
#include "rw_camera_internal.h"
#include "camp_menu_internal.h"
#include "sdk_ot_node.h"
extern void datCommunityEntryStep(u8 *);
extern void nmMesWindowDestroySlot(s8 );
extern void (*D_008873EC[])(void *);
extern void datTextSlotRelease();
extern s32 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s64 );
extern s32 datMemberIsUnlocked(s64 );
extern s32 datGetFlag(s32 );
extern u8 *kwlnTaskGetTaskByName(const void *);
extern u8 D_0064B320[];
extern void datMemberNoticeSetup(u8 *, s32 , s32 );
extern u8 D_0064B3B0[];
extern u8 D_0064B3D0[];
extern s32 datScreenWipeUpdate(u8 *);
extern void datScreenWipeDestroy(u8 *);
extern void strncpy(void *dst, const void *src, u32 size);
extern f32 RwV3dNormalize(void *out, const void *in);
extern void sdkSpriteFreeNode(void *node);
extern void kwlnTaskDestroyWithHierarchy(s32 );
extern void nmMesWindowReleaseHandle(s32 );
extern s32 cmmKindRecord(u16 );
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

typedef struct DatMemberNotice {
    u16 flags;
    u8 pad2[2];
    s32 state;
    s8 messageSlot;
    u8 pad9[7];
} DatMemberNotice;

typedef struct DatTextSlot {
    s32 state;
    s32 resource;
    RadarSprite request;
    RadarSprite result;
    u8 path[0x100];
} DatTextSlot;

/* The wipe constructor allocates 0x258 bytes, including its inline text slot. */
typedef struct DatScreenWipe {
    s32 unk0;
    s32 frame;
    u16 textureId;
    u8 alpha;
    u8 padB;
    MenuAnimValue color;
    Float2 position;
    Float2 start;
    Float2 target;
    Float2 offset;
    Float2 smoothed;
    MenuAnimValue scaleX;
    MenuAnimValue scaleY;
    s32 loaded;
    u8 pad44[0x100];
    DatTextSlot textSlot;
    void *module;
} DatScreenWipe;

typedef struct DatGridEffectCell {
    MenuAnimValue startX, startY;
    MenuAnimValue currentX, currentY;
    MenuAnimValue previousX, previousY;
    MenuAnimValue startFrame, endFrame;
} DatGridEffectCell;

typedef struct DatGridEffect {
    s16 style;
    u8 pad2[2];
    s32 kind;
    s32 flags;
    s16 duration;
    s16 tailDuration;
    s16 frame;
    s16 tailFrame;
    u8 color[4];
    DatGridEffectCell cells[15];
    OtPrimitiveNode drawNode;
    s32 priority;
} DatGridEffect;

typedef struct DatCommunityRow {
    MenuAnimAlpha arcana;
    u8 pad1;
    u16 communityId;
    u16 rank;
    u8 pad6[2];
    s32 mode;
} DatCommunityRow;

typedef struct DatPortraitLabel {
    Float2 position;
    Float2 start;
    Float2 target;
    Float2 smoothed;
    u16 id;
    s16 transitionFrame;
    s32 flags;
    s32 color;
    s32 loaded;
    DatTextSlot textSlot;
    void *module;
} DatPortraitLabel;

extern void datScreenWipeInit(u8 *, Float2 *, Float2 *);
extern void datScreenWipeSetScale(u8 *, u8 *);
extern void datScreenWipeSetTextureId(u8 *, u16 );
static inline void datPortraitAccumulateProjection(f32 *total, f32 weight, f32 projection)
{
    *total += weight * projection;
}

static inline u32 datCommunityAddOffset(u32 offset, u32 base)
{
    return offset + base;
}

extern s32 nLineIsIdle(void);
extern u32 D_0064B1E0[];
extern void sdkWrapStreamCloseCreate(s32 , s32 );
extern void H_Cdvd_Destroy(u8 *);
extern void func_003ef3a0(void *);
extern void memset(void *dst, s32 value, s32 size);
extern void datGridEffectSetLayout(u8 *, s64 );
extern void datGridEffectDraw(u8 *, u8 *);
extern void datPortraitSetValue(u8 *, s8 , s32 );
extern void datPortraitSetLabel(s32 , u16 , s32 );
extern void radarAnimateValue(void *, s32 , s32 );
extern s32 datPortraitUpdate(u8 *);
extern void datPortraitDestroy(u8 *);
extern u8 D_0064CC98[];
extern u8 D_0064CD40[];
extern u8 D_0064CCB0[];
extern u8 D_0064CCD0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_00440b68();
extern s32 H_Cdvd_AcquireDirectory(u8 *, s32 );
extern s32 H_Cdvd_IsFileLoaded(s32 );
extern s32 filerEnqueueRequest();
extern s32 filerTakeCompletedRequest(s32 , void *, s32 );
extern u8 iGpffffa960;
extern u8 D_0064B360[];
extern u8 D_0064B380[];
extern void chkmemAllocSiteTag(const void *, s32 );
extern u8 D_0064B410[];
extern s32 datGridEffectUpdate(u8 *);
extern void datGridEffectDestroy(u8 *);
extern void datGridEffectInit(u8 *, s64 , s32 );
extern void PrimAppendNode(u8 *, u8 *);
extern u8 D_00793E80[];
extern f32 iGpffff83d4;
extern f32 iGpffff8544;
extern f32 sinf(f32 );
extern f32 fGpffff84a4;
extern void nmMesWindowStepCurrent(s32 );
extern s32 nmMesWindowCurrentOpenState(void);
extern void nmMesWindowCloseCurrent(s32 );
extern void nmMesWindowStepSlot(s32 , s32 );
extern s32 nmMesWindowSlotStatus(s8 );
extern void nmMesWindowCloseSlot(s8 , s32 );
extern s32 nmMesWindowResetCurrent(void);
extern s32 fclMiscEnsureMesWindow(const void *);
extern s32 fclMesWindowShowItemRecord(s32 );
extern u8 D_0064A790[];
extern void resrcMngSetRenderSuppressed(s32 );
extern s32 FldStepNotAtBoundary(void);
extern void nLineSetActive(s32 );
extern s32 nLineGetCurrentSet(void);
extern s64 datGetPartyId(s32 );
typedef struct {
    u8 opacity;
    u8 unknown0001[0x3];
    Vec2f origin;
    u8 unknown000C[0x4];
    s32 background;
    s32 stage;
    s32 tableMode;
    s32 flags;
    s16 frame;
    s16 angle;
    s16 selection[3];
    s16 previousSelection[3];
    f32 rotation;
    f32 zoom;
    DatCommunityRow rows[21];
    s16 rowCount;
    s16 detailIds[9];
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
} CommunityMenu;
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
// Intent: Build the list of party member ids from the first three party slots, with the count in the first entry [inferred]
// FUN_00353B50
s16 datBuildPartyIdList(s16 *ids)
{
    s16 len;
    s16 partyId;
    s32 i;

    len = 1;
    *ids = 1;
    for (i = 0; i < 3; i++) {
        partyId = datGetPartyId(i);
        if (partyId != 0) {
            ((s16 *)ids)[len] = partyId;
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
s16 datBuildMemberIdList(s16 *ids)
{
    s16 len;
    s16 memberId;
    s32 i;

    len = 1;
    *ids = 1;
    for (i = 1; i < 8; i++) {
        memberId = (s16)(i + 1);
        if (datMemberIsUnlocked(memberId) != 0) {
            ((s16 *)ids)[len] = memberId;
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
s16 datBuildMemberIdListExcluding5(s16 *ids)
{
    s16 len;
    s16 memberId;
    s32 i;

    len = 1;
    *ids = 1;
    for (i = 1; i < 8; i++) {
        memberId = (s16)(i + 1);
        if (memberId == 5) {
            goto skip;
        }
        if (datMemberIsUnlocked(memberId) != 0) {
            ((s16 *)ids)[len] = memberId;
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
s32 datMemberIsUnlocked(s64 memberId)
{
    s64 value;
    s32 result;

    result = 0;
    value = (s16)memberId;
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
s32 datMemberNoticeTryBegin(s32 stepMode)
{
    nmMesWindowStepCurrent(stepMode);
    if (nmMesWindowCurrentOpenState() == 0) {
        nmMesWindowCloseCurrent(stepMode);
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
void datCommunityCursorFeedback(s32 direction)
{
    if ((u32)(direction - 1) < 2U) {
        sdkSndStartStream(0, 1, 0, 0);
        return;
    }
    if ((u32)(direction - 3) < 2U) {
        sdkSndStartStream(0, 1, 0, 5);
    }
}

// Intent: Member notice state step: advance the notice from its opening states to its ready states, and clear the channel once it closes [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_003540F0
s32 datMemberNoticeStep(u8 *task)
{
    u8 *work;
    s32 state;

    work = ((SdkTask *)task)->work;
    state = ((DatMemberNotice *)work)->state;
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = 1;
        break;
    case 1:
        nmMesWindowStepSlot(((DatMemberNotice *)work)->messageSlot, 1);
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
void datMemberNoticeDestroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    nmMesWindowDestroySlot(((DatMemberNotice *)work)->messageSlot);
    (*D_008873EC)(work);
}

// Intent: Set up the member notice: set the member's notice flags, pick the message, and show the label and sub-label [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00354280
void datMemberNoticeSetup(u8 *notice, s32 memberId, s32 modeFlags)
{
    u8 label[0x40];
    u8 subLabel[0x40];
    s32 mode;
    s32 i;
    s32 msgId;
    s32 flagId;
    extern s8 nmMesWindowAcquire(void *);
    extern void datSetFlag(s32, s32);
    extern void frFontExCopyString(void *, void *, s32);
    extern s32 nmMesWindowShowSlotRecord(s8, s32);
    extern void nmMesWindowSetSlotString(s8, s32, void *);
    extern u8 sdkSndStartChannel(s16, const char *);
    extern u8 D_0064B340[];
    extern char iGpffffa958;
    extern u32 datMemberNameLabel(s32);

    ((DatMemberNotice *)notice)->messageSlot = nmMesWindowAcquire(D_0064A790);
    if (modeFlags == 0) {
        flagId = memberId + 0x100;
        if (datGetFlag(flagId) != 0)
            kAssertFail(&D_0064B310, 0x369);
        i = 0;
        while (i < 0x40) {
            datSetFlag(i + 0x180, 0);
            i++;
        }
        datSetFlag(memberId + 0x180, 1);
        datSetFlag(flagId, 1);
        mode = 5;
        msgId = 0x2CF;
        if (datGetFlag(0xC3) == 0) {
            *(u16 *)notice = *(u16 *)notice | 1;
            datSetFlag(0xC3, 1);
        }
    } else {
        if (datGetFlag(memberId + 0x100) == 0)
            kAssertFail(&D_0064B310, 0x37E);
        datSetFlag(memberId + 0x180, 0);
        datSetFlag(memberId + 0x140, 1);
        mode = 6;
        msgId = 0x2D0;
    }
    sprintf(label, &D_0064B340, msgId);
    sdkSndStartChannel(2, (const char *)label);
    frFontExCopyString((void *)(u32)datMemberNameLabel(memberId), label, 0x40);
    nmMesWindowSetSlotString(*(s8 *)(notice + 8), 0, label);
    sprintf(subLabel, &iGpffffa958, memberId + 1);
    frFontExCopyString(subLabel, label, 0x40);
    nmMesWindowSetSlotString(*(s8 *)(notice + 8), 1, label);
    nmMesWindowShowSlotRecord(*(s8 *)(notice + 8), mode);
}

// Intent: Return the name label for a member id from the label table [inferred]
// FUN_00354490
u32 datMemberNameLabel(s32 memberId)
{
    if (!(memberId < 0x40)) {
        kAssertFail(D_0064B310, 0x3D6);
    }
    return D_0064B1E0[memberId];
}

/* Returns the fixed value 50 used by cmpSystem initialization. */
// FUN_003544F0
s32 datCommunityDefaultSetting(void)
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
        state = ((DatMemberNotice *)((SdkTask *)task)->work)->state;
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
        state = ((DatMemberNotice *)((SdkTask *)task)->work)->state;
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
void datTextSlotSetString(s32 *slotWords, u8 *text)
{
    datTextSlotRelease();
    if (text == NULL) {
        *slotWords = 3;
        return;
    }
    strncpy((u8 *)slotWords + 0x10, text, 0x100);
    *slotWords = 0;
}

// Intent: Text slot loading state machine: request the file named in the slot, wait for it, then create its resource and wait for the resource to finish [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00354830
s32 datTextSlotLoadStep(u8 *slot) {
    s32 completed;
    s32 handle;
    s32 state;

    state = ((DatTextSlot *)slot)->state;
    switch (state) {
    case 0:
        if (kwlnTaskGetTaskByName(&D_0064B360) != NULL) {
            func_00440b68(&D_0064B380);
        } else {
            func_00440b68(&iGpffffa960, &D_0064B310, 0x433);
            handle = H_Cdvd_AcquireDirectory(slot + 0x10, 0);
            ((DatTextSlot *)slot)->request.handle = handle;
            if (handle == 0) {
                kAssertFail(&D_0064B310, 0x434);
            }
            ((DatTextSlot *)slot)->state = 1;
        }
        goto block_15;
    case 1:
        if (H_Cdvd_IsFileLoaded(((DatTextSlot *)slot)->request.handle) != 0) {
            ((DatTextSlot *)slot)->resource =
                filerEnqueueRequest(0, slot + 0x10, 0, 0, 0, 0, 0, 0, 0, 0);
            ((DatTextSlot *)slot)->state = 2;
        }
        goto block_15;
    case 2:
        ((DatTextSlot *)slot)->result.handle =
            filerTakeCompletedRequest(((DatTextSlot *)slot)->resource, &completed, 0);
        if (completed != 0) {
            *(s32 *)(slot + 4) = 0;
            H_Cdvd_Destroy(((DatTextSlot *)slot)->request.node);
            *(s32 *)(slot + 8) = 0;
            ((DatTextSlot *)slot)->state = 3;
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_003549D0
void datTextSlotRelease(u8 *slot)
{
    s32 handle;

    handle = ((DatTextSlot *)slot)->resource;
    if (handle != 0) {
        sdkWrapStreamCloseCreate(handle, ((DatTextSlot *)slot)->request.handle);
        *(s32 *)(slot + 4) = 0;
        *(s32 *)(slot + 8) = 0;
        ((DatTextSlot *)slot)->result.handle = 0;
        return;
    }
    if (((DatTextSlot *)slot)->request.handle != 0) {
        H_Cdvd_Destroy(((DatTextSlot *)slot)->request.node);
        *(s32 *)(slot + 8) = 0;
    }
    if (((DatTextSlot *)slot)->result.handle != 0) {
        func_003ef3a0(((DatTextSlot *)slot)->result.node);
        *(s32 *)(slot + 0xC) = 0;
    }
}

// Intent: Create the screen wipe task with its update and destroy callbacks, set its positions and attach the target range [inferred]
// FUN_00354A50
u8 *datScreenWipeTaskCreate(s32 parentAddress, u16 textureId) {
    Float2 initialPosition;
    u8 *task;
    u8 *work;

    chkmemAllocSiteTag(&D_0064B310, 0x48C);
    work = D_008873F4[0](1, 0x258, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreateChild((void *)(parentAddress), (const void *)(&D_0064B3D0), 0xC7, 0, 0, datScreenWipeUpdate, datScreenWipeDestroy, (u8 *)(work));
    if (task == NULL) {
        return NULL;
    }
    *(s16 *)&((DatScreenWipe *)work)->textureId = 0;
    ((DatScreenWipe *)work)->alpha = 0xFF;
    ((DatScreenWipe *)work)->color.s =
        ((DatScreenWipe *)work)->alpha | 0x2D2D2D00;
    initialPosition.x = 640.0f;
    initialPosition.y = 640.0f;
    datScreenWipeInit(task, &initialPosition, &initialPosition);
    datScreenWipeSetScale(task, NULL);
    ((DatScreenWipe *)work)->textSlot.result.handle = 0;
    ((DatScreenWipe *)work)->textSlot.resource = 0;
    ((DatScreenWipe *)work)->textSlot.request.handle = 0;
    ((DatScreenWipe *)work)->module = (void *)&D_0064B3B0;
    datScreenWipeSetTextureId(task, textureId);
    return task;
}

// Intent: Draw one step of the screen wipe: advance its blend toward the target, then draw its quad with the render state table [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00354BA0
void datScreenWipeDraw(u8 *task) {
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern f32 D_00761470;
    extern void shdDrawColourQuad(f32, s32, f32, f32, f32, f32, f32, f32, s32 *, s32, s32);
    extern void RpSkyRenderStateSet(s32, s32);
    extern u8 D_00887300[];
    extern void (*D_00887310[])(s32, void *, s32);
    typedef struct {
        f32 x;
        f32 y;
        f32 depth;
        s32 _c;
        s32 u;
        s32 v;
        f32 reciprocalDepth;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } WipeVertex;
    WipeVertex vertices[4];
    u8 *wipe;
    f32 depth;
    f32 reciprocalDepth;
    s32 frame;
    f32 frameValue;
    f32 blend;
    f32 width;
    f32 height;
    u8 alpha;
    u32 color;
    u32 base;

    wipe = ((SdkTask *)task)->work;
    depth = D_008872F8[0];
    reciprocalDepth = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    if ((((DatScreenWipe *)wipe)->loaded == 0) || (((DatScreenWipe *)wipe)->textureId == 0)) {
        return;
    }
    frame = ((DatScreenWipe *)wipe)->frame;
    if (frame < 100) {
        *(s32 *)(wipe + 4) = frame + 1;
    }
    frameValue = (f32)*(s32 *)(wipe + 4);
    if (frameValue < 10.0f) {
        blend = sinf(D_00761470 * (frameValue / 10.0f));
    } else {
        blend = 1.0f;
    }
    ((DatScreenWipe *)wipe)->position.x = ((DatScreenWipe *)wipe)->start.x + blend * (((DatScreenWipe *)wipe)->target.x - ((DatScreenWipe *)wipe)->start.x);
    ((DatScreenWipe *)wipe)->position.y = ((DatScreenWipe *)wipe)->start.y + blend * (((DatScreenWipe *)wipe)->target.y - ((DatScreenWipe *)wipe)->start.y);
    ((DatScreenWipe *)wipe)->smoothed.x += (((DatScreenWipe *)wipe)->position.x - ((DatScreenWipe *)wipe)->smoothed.x) / 3.0f;
    ((DatScreenWipe *)wipe)->smoothed.y += (((DatScreenWipe *)wipe)->position.y - ((DatScreenWipe *)wipe)->smoothed.y) / 3.0f;
    alpha = ((DatScreenWipe *)wipe)->alpha;
    width = 256.0f * ((DatScreenWipe *)wipe)->scaleX.f;
    height = 512.0f * ((DatScreenWipe *)wipe)->scaleY.f;
    vertices[0].x = ((DatScreenWipe *)wipe)->position.x;
    vertices[0].y = ((DatScreenWipe *)wipe)->position.y;
    vertices[0].depth = depth;
    vertices[0].r = 0x437F0000;
    vertices[0].g = 0x437F0000;
    vertices[0].b = 0x437F0000;
    vertices[0].a = (f32)(u32)alpha;
    vertices[0].u = 0;
    vertices[0].v = 0;
    vertices[0].reciprocalDepth = reciprocalDepth;
    vertices[1].x = *(f32 *)(wipe + 0x10) + width;
    vertices[1].y = *(f32 *)(wipe + 0x14);
    vertices[1].depth = depth;
    vertices[1].r = 0x437F0000;
    vertices[1].g = 0x437F0000;
    vertices[1].b = 0x437F0000;
    vertices[1].a = (f32)(u32)alpha;
    vertices[1].u = 0x3F800000;
    vertices[1].v = 0;
    vertices[1].reciprocalDepth = reciprocalDepth;
    vertices[2].x = *(f32 *)(wipe + 0x10);
    vertices[2].y = *(f32 *)(wipe + 0x14) + height;
    vertices[2].depth = depth;
    vertices[2].r = 0x437F0000;
    vertices[2].g = 0x437F0000;
    vertices[2].b = 0x437F0000;
    vertices[2].a = (f32)(u32)alpha;
    vertices[2].u = 0;
    vertices[2].v = 0x3F800000;
    vertices[2].reciprocalDepth = reciprocalDepth;
    vertices[3].x = *(f32 *)(wipe + 0x10) + width;
    vertices[3].y = *(f32 *)(wipe + 0x14) + height;
    vertices[3].depth = depth;
    vertices[3].r = 0x437F0000;
    vertices[3].g = 0x437F0000;
    vertices[3].b = 0x437F0000;
    vertices[3].a = (f32)(u32)alpha;
    vertices[3].u = 0x3F800000;
    vertices[3].v = 0x3F800000;
    vertices[3].reciprocalDepth = reciprocalDepth;
    shdDrawColourQuad(0.0f, (*(u32 *)(wipe + 0xC) & ~0xFF) | (((((*(u32 *)(wipe + 0xC)) & 0xFF) * 0xFF) / *(u8 *)(wipe + 0xA)) & 0xFF), ((DatScreenWipe *)wipe)->offset.x + *(f32 *)(wipe + 0x30), ((DatScreenWipe *)wipe)->offset.y + *(f32 *)(wipe + 0x34), *(f32 *)(wipe + 0x10), *(f32 *)(wipe + 0x14), width, height, *(s32 **)(wipe + 0x150), 1, 0);
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
    ((void (*)(u32, u32))*(u32 *)base)(1, *(*(u32* *)&((DatScreenWipe *)wipe)->textSlot.result));
    D_00887310[0](4, &vertices[0], 4);
}

// Intent: Set the screen wipe's target range from the argument, or return it to the current position when the argument is null [inferred]
// FUN_00355070
void datScreenWipeSetTarget(u8 *task, u8 *target) {
    u8 *work;

    work = (u8 *)(((SdkTask *)task)->work);
    if (target != NULL) {
        ((DatScreenWipe *)work)->start.x = (f32) ((DatScreenWipe *)work)->position.x;
        ((DatScreenWipe *)work)->start.y = (f32) ((DatScreenWipe *)work)->position.y;
        ((DatScreenWipe *)work)->target.x = (f32) ((Float2 *)target)->x;
        ((DatScreenWipe *)work)->target.y = (f32) ((Float2 *)target)->y;
    } else {
        ((DatScreenWipe *)work)->position.x = (f32) ((DatScreenWipe *)work)->start.x;
        ((DatScreenWipe *)work)->position.y = (f32) ((DatScreenWipe *)work)->start.y;
        ((DatScreenWipe *)work)->smoothed.x = (f32) ((DatScreenWipe *)work)->start.x;
        ((DatScreenWipe *)work)->smoothed.y = (f32) ((DatScreenWipe *)work)->start.y;
    }
    ((DatScreenWipe *)work)->frame = 0;
}

// Intent: Initialise the screen wipe: set its current, start and end positions and reset its step counter [inferred]
// FUN_003550D0
void datScreenWipeInit(u8 *task, Float2 *start, Float2 *target)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (start == NULL) {
        kAssertFail(&D_0064B310, 0x53A);
    }
    if (target == NULL) {
        kAssertFail(&D_0064B310, 0x53B);
    }
    ((DatScreenWipe *)work)->start.x = start->x;
    ((DatScreenWipe *)work)->start.y = start->y;
    ((DatScreenWipe *)work)->position.x = start->x;
    ((DatScreenWipe *)work)->position.y = start->y;
    ((DatScreenWipe *)work)->target.x = target->x;
    ((DatScreenWipe *)work)->target.y = target->y;
    ((DatScreenWipe *)work)->smoothed.x = start->x;
    ((DatScreenWipe *)work)->smoothed.y = start->y;
    ((DatScreenWipe *)work)->frame = 0;
}

// Intent: Set the screen wipe's texture from the member id and the day suffix, releasing the old text slot when the id changes [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00355190
void datScreenWipeSetTextureId(u8 *task, u16 textureId)
{
    u8 path[0x100];
    s32 id;
    s8 suffix;
    u8 *work;
    u8 *reloadedWork;

    work = ((SdkTask *)task)->work;
    id = textureId & 0xFFFF;
    if (((DatScreenWipe *)work)->textureId != id) {
        if (calGetDayWindowFlags((s64)(s16)datGetDateIndex()) & 1) {
            suffix = 0x61;
        } else {
            suffix = 0x62;
        }
        if (id == 0) {
            datTextSlotRelease(work + 0x144);
            ((DatScreenWipe *)work)->textSlot.state = 3;
        } else {
            sprintf(path, &D_0064B3F0, id, suffix);
            datTextSlotRelease(work + 0x144);
            if ((u8 *)path == NULL) {
                ((DatScreenWipe *)work)->textSlot.state = 3;
            } else {
                strncpy(work + 0x154, path, 0x100);
                ((DatScreenWipe *)work)->textSlot.state = 0;
            }
        }
        *(u16 *)(work + 8) = textureId;
        ((DatScreenWipe *)work)->loaded = 0;
        reloadedWork = *(u8 **)(task + 0x38);
        ((DatScreenWipe *)reloadedWork)->position.x = ((DatScreenWipe *)reloadedWork)->start.x;
        ((DatScreenWipe *)reloadedWork)->position.y = ((DatScreenWipe *)reloadedWork)->start.y;
        ((DatScreenWipe *)reloadedWork)->smoothed.x = ((DatScreenWipe *)reloadedWork)->start.x;
        ((DatScreenWipe *)reloadedWork)->smoothed.y = ((DatScreenWipe *)reloadedWork)->start.y;
        ((DatScreenWipe *)reloadedWork)->frame = 0;
    }
}

// Intent: Set the screen wipe's offset from the argument point [inferred]
// FUN_003552D0
void datScreenWipeSetOffset(u8 *task, Float2 offset)
{
    f32 *b = *(f32* *)&((SdkTask *)task)->work;

    b[0xA] = offset.x;
    b[0xB] = offset.y;
}

// Intent: Set the screen wipe's colour word [inferred]
// FUN_00355300
void datScreenWipeSetColor(u8 *task, s32 color)
{
    ((DatScreenWipe *)((SdkTask *)task)->work)->color.s = color;
}

// Intent: Copy the screen wipe's start, current and end positions to the output points when they are non-null [inferred]
// FUN_00355310
void datScreenWipeGetPositions(u8 *task, u8 *start, u8 *position, u8 *target) {
    u8 *work;

    work = (u8 *)(((SdkTask *)task)->work);
    if (start != NULL) {
        ((Float2 *)start)->x = (f32) ((DatScreenWipe *)work)->start.x;
        ((Float2 *)start)->y = (f32) ((DatScreenWipe *)work)->start.y;
    }
    if (position != NULL) {
        ((Float2 *)position)->x = (f32) ((DatScreenWipe *)work)->position.x;
        ((Float2 *)position)->y = (f32) ((DatScreenWipe *)work)->position.y;
    }
    if (target != NULL) {
        ((Float2 *)target)->x = (f32) ((DatScreenWipe *)work)->target.x;
        ((Float2 *)target)->y = (f32) ((DatScreenWipe *)work)->target.y;
    }
}

// Intent: Set the screen wipe's scale from the argument, or reset it to 1.0 when the argument is null [inferred]
// FUN_00355370
void datScreenWipeSetScale(u8 *task, u8 *scale)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (scale == NULL) {
        ((DatScreenWipe *)work)->scaleX.u = 0x3F800000;
        ((DatScreenWipe *)work)->scaleY.u = 0x3F800000;
    } else {
        ((DatScreenWipe *)work)->scaleX.f = ((Float2 *)scale)->x;
        ((DatScreenWipe *)work)->scaleY.f = ((Float2 *)scale)->y;
    }
}

// Intent: Copy the screen wipe's scale to the output pair [inferred]
// FUN_003553B0
void datScreenWipeGetScale(u8 *task, f32 *scale)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (scale == NULL) {
        kAssertFail(D_0064B310, 0x5CD);
    }
    scale[0] = ((DatScreenWipe *)work)->scaleX.f;
    scale[1] = ((DatScreenWipe *)work)->scaleY.f;
}

// Intent: Set the screen wipe's alpha byte [inferred]
// FUN_00355410
/* The opacity component is a byte, as stored by the state and passed by every caller. */
void datScreenWipeSetAlpha(u8 *task, u8 alpha)
{
    u8 *work;

    ((DatScreenWipe *)((SdkTask *)task)->work)->alpha = alpha;
    work = ((SdkTask *)task)->work;
    ((DatScreenWipe *)work)->color.s = ((s32 *)work)[3];
}

// Intent: Return the screen wipe's texture when its texture load has finished, otherwise 0 [inferred]
// FUN_00355430
s32 datScreenWipeTexture(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (((DatScreenWipe *)work)->loaded != 0) {
        return ((DatScreenWipe *)work)->textSlot.result.handle;
    }
    return 0;
}

// Intent: Screen wipe task update: start the texture load when the id is set and the wipe is not loaded yet [inferred]
// FUN_00355460
s32 datScreenWipeUpdate(u8 *task)
{
    u8 *wipe;

    wipe = ((SdkTask *)task)->work;
    if ((((s32 *)wipe)[16] == 0) && (((DatScreenWipe *)wipe)->textureId != 0)) {
        ((DatScreenWipe *)wipe)->loaded = datTextSlotLoadStep(wipe + 0x144);
    }
    return 0;
}

// Intent: Screen wipe task destroy: release the wipe's texture handles and the work block [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_003554B0
void datScreenWipeDestroy(u8 *task)
{
    s32 handle;
    s32 cdvdHandle;
    s32 loadResult;
    u8 *wipe;

    wipe = ((SdkTask *)task)->work;
    handle = ((DatScreenWipe *)wipe)->textSlot.resource;
    if (handle != 0) {
        sdkWrapStreamCloseCreate(handle, ((DatScreenWipe *)wipe)->textSlot.request.handle);
        *(s32 *)(wipe + 0x148) = 0;
        *(s32 *)(wipe + 0x14C) = 0;
        ((DatScreenWipe *)wipe)->textSlot.result.handle = 0;
    } else {
        cdvdHandle = ((DatScreenWipe *)wipe)->textSlot.request.handle;
        if (cdvdHandle != 0) {
            H_Cdvd_Destroy((u8 *)cdvdHandle);
            *(s32 *)(wipe + 0x14C) = 0;
        }
        loadResult = ((DatScreenWipe *)wipe)->textSlot.result.handle;
        if (loadResult != 0) {
            func_003ef3a0((void *)loadResult);
            *(s32 *)(wipe + 0x150) = 0;
        }
    }
    (*D_008873EC)(wipe);
}

#pragma push
#pragma optimization_level 1
// Intent: Create the grid effect task with its update and destroy callbacks, store its kind, colour and offsets, and set its layout [inferred]
// FUN_00355550
s32 datGridEffectCreate(s16 style, s32 color, s16 duration, s16 tailDuration,
                  s64 layout, s32 kind, s32 priority, s32 drawPriority)
{
    s32 result;
    u8 *work;
    chkmemAllocSiteTag(&D_0064B310, 0x63D);
    work = D_008873F4[0](1, 0x22C, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064B310, 0x63E);
    }
    result = (s32)kwlnTaskCreate((const void *)(&D_0064B410), priority, 0, 0, datGridEffectUpdate, datGridEffectDestroy, (u8 *)(work));
    ((DatGridEffect *)work)->style = style;
    ((DatGridEffect *)work)->kind = kind;
    ((DatGridEffect *)work)->duration = duration;
    ((DatGridEffect *)work)->tailDuration = tailDuration;
    {
        u8 color_0 = ((u8 *)&color)[0];
        u8 color_1 = ((u8 *)&color)[1];
        u8 color_2 = ((u8 *)&color)[2];
        u8 color_3 = ((u8 *)&color)[3];
        ((DatGridEffect *)work)->color[0] = color_0;
        ((DatGridEffect *)work)->color[1] = color_1;
        ((DatGridEffect *)work)->color[2] = color_2;
        ((DatGridEffect *)work)->color[3] = color_3;
    }
    datGridEffectInit(work, layout, drawPriority);
    return result;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Initialise the grid effect work block: clear its fifteen cell positions and set its update callback and state [inferred]
// FUN_003556A0
void datGridEffectInit(u8 *effect, s64 layout, s32 priority)
{
    s32 i;
    u8 *cellCursor;

    ((DatGridEffect *)effect)->flags = 1;
    i = 0;
    while (i < 0xF) {
        cellCursor = effect + (i << 5);
        ((DatGridEffectCell *)(cellCursor + 0x18))->currentX.s = 0;
        ((DatGridEffectCell *)(cellCursor + 0x18))->currentY.s = 0;
        i += 1;
    }
    datGridEffectSetLayout(effect, (s16)layout);
    memset(effect + 0x1F8, 0, 0x30);
    *(s32 *)&((DatGridEffect *)effect)->drawNode.callback = (s32)datGridEffectDraw;
    *(s32 *)&((DatGridEffect *)effect)->drawNode.callbackData = (s32)effect;
    ((DatGridEffect *)effect)->priority = priority;
}
#pragma pop

#pragma push
#pragma optimization_level 1
// Intent: Set the grid effect's cell positions for its layout: layout 0 places every cell at the origin, layout 1 spreads them in a diamond around the centre [inferred]
// FUN_00355740
void datGridEffectSetLayout(u8 *effect, s64 layout)
{
    f32 step;
    f32 scale;
    f32 temp;
    f32 threeQuarters;
    s32 x;
    s32 y;
    s32 i;
    s32 i2;
    s32 j;
    s32 divisor;
    u8 *cellCursor;
    u8 *resetCell;
    u8 *layoutCell;
    extern f32 fGpffff83d0;

    i = 0;
    while (i < 0xF) {
        cellCursor = effect + (i << 5);
        ((DatGridEffectCell *)(cellCursor + 0x18))->previousX.f = ((DatGridEffectCell *)(cellCursor + 0x18))->currentX.f;
        ((DatGridEffectCell *)(cellCursor + 0x18))->previousY.f = ((DatGridEffectCell *)(cellCursor + 0x18))->currentY.f;
        i += 1;
    }
    switch (layout) {
    case 0:
        i2 = 0;
        while (i2 < 0xF) {
            resetCell = effect + (i2 << 5);
            ((DatGridEffectCell *)(resetCell + 0x18))->startX.s = 0;
            ((DatGridEffectCell *)(resetCell + 0x18))->startY.s = 0;
            ((DatGridEffectCell *)(resetCell + 0x18))->startFrame.s = 0;
            ((DatGridEffectCell *)(resetCell + 0x18))->endFrame.f = (f32)((DatGridEffect *)effect)->duration;
            i2 += 1;
        }
        break;
    case 1:
        j = 0;
        divisor = 5;
        step = fGpffff83d0;
        threeQuarters = 0.75f;
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
            layoutCell = effect + (j << 5);
            ((DatGridEffectCell *)(layoutCell + 0x18))->startX.s = 0;
            ((DatGridEffectCell *)(layoutCell + 0x18))->startY.s = 0;
            ((DatGridEffectCell *)(layoutCell + 0x18))->startFrame.f = (f32)((DatGridEffect *)effect)->duration * scale;
            temp = (f32)((DatGridEffect *)effect)->duration;
            ((DatGridEffectCell *)(layoutCell + 0x18))->endFrame.f = temp * (threeQuarters + scale);
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
s32 datGridEffectUpdate(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    *(s32 *)&((DatGridEffect *)work)->drawNode.next = 0;
    *(s32 *)&((DatGridEffect *)work)->drawNode.tail = 0;
    PrimAppendNode((u8 *)&D_00793E80 + (((DatGridEffect *)work)->priority * 0x30), work + 0x1F8);
    if (!(((DatGridEffect *)work)->flags & 4)) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}
#pragma pop

/* Whether the frame counter at +0x10 has passed the style's threshold of the
   duration at +0xC (3/4 for style 0, 1/2 for style 1). */
/* measured: typing the frame/duration reads changes the inlined draw instructions; style remains typed. */
static inline s32 datGridEffectPastThreshold(u8 *p)
{
    switch (((DatGridEffect *)p)->style) {
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00355920
void datGridEffectDraw(u8 *node, u8 *effect) {
    extern u8 D_00887300[];
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern void RpSkyRenderStateSet(s32, s32);
    extern void effMiscDrawScreenColor(u8 *, s32);
    extern f32 cosf(f32);
    extern void datGridEffectDrawStrip(s64, f32, f32, s32, f32, s32, s32);
    extern void datGridEffectDrawCell(Vec2f, s32, f32, f32, f32, s32);
    extern f32 fGpffff8504;
    extern f32 fGpffff8540;
    extern f32 fGpffff8548;
    u8 *grid;
    s32 isZero;
    u8 alpha;
    void (**tbl)(u32, u32);
    s32 i;
    f32 shapeBlend;
    f32 easedSize;
    union { s64 bits; Vec2f vec; } xy;
    union { s32 w; u8 b[4]; } col;
    (void)node;
    grid = effect;
    alpha = 0xFF;
    isZero = (((DatGridEffect *)grid)->kind == 0);
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
    if ((((DatGridEffect *)grid)->flags & 2) != 0) {
        ((DatGridEffect *)grid)->tailFrame += 1;
        switch (*(s32 *)(grid + 4)) {
        case 0: {
            s16 limit = ((DatGridEffect *)grid)->tailDuration;
            s16 cnt = *(s16 *)(grid + 0x12);
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
                shapeBlend = fGpffff84a4 * ((fcnt - start * flimit) / (fGpffff8540 * flimit));
                easedSize = iGpffff8544 * (1.0f - cosf(shapeBlend));
                s = 800.0f * sinf(shapeBlend);
                switch (*(s16 *)grid) {
                case 0:
                    datGridEffectDrawStrip(xy.bits, 0.0f, s, col.w, 0.0f, 0x30, 0);
                    break;
                case 1:
                    datGridEffectDrawCell(xy.vec, col.w, 0.0f, s, easedSize, 0);
                    break;
                }
            } else {
                *(s32 *)(grid + 8) |= 4;
            }
            break;
        }
        case 1:
            if (*(s16 *)(grid + 0x12) >= ((DatGridEffect *)grid)->tailDuration) {
                *(s32 *)(grid + 8) |= 4;
            }
            break;
        case 2: {
            s16 limit = ((DatGridEffect *)grid)->tailDuration;
            s16 cnt = *(s16 *)(grid + 0x12);
            if (cnt < limit) {
                alpha = (u8)(255.0f * (1.0f - (f32)cnt / (f32)limit));
            } else {
                *(s32 *)(grid + 8) |= 4;
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
    if ((*(s32 *)(grid + 8) & 1) != 0) {
        ((DatGridEffect *)grid)->frame += 1;
        if (*(s16 *)(grid + 0x10) <= *(s16 *)(grid + 0xC)) {
            switch (*(s32 *)(grid + 4)) {
            case 0:
                if ((*(s32 *)(grid + 8) & 2) == 0 && ((DatGridEffect *)grid)->duration / 3 < *(s16 *)(grid + 0x10)) {
                    *(s32 *)(grid + 8) |= 2;
                }
                break;
            case 1:
            case 2:
                if ((*(s32 *)(grid + 8) & 2) == 0) {
                    if (datGridEffectPastThreshold(grid) != 0) {
                        *(s32 *)(grid + 8) |= 2;
                    }
                }
                break;
            default:
                kAssertFail(D_0064B310, 0x73A);
                break;
            }
        } else {
            *(s32 *)(grid + 8) &= ~1;
            *(s32 *)(grid + 8) |= 2;
        }
    }
    if ((*(s32 *)(grid + 8) & 4) != 0) {
        return;
    }
    col.b[0] = ((DatGridEffect *)grid)->color[0];
    col.b[1] = ((DatGridEffect *)grid)->color[1];
    col.b[2] = ((DatGridEffect *)grid)->color[2];
    col.b[3] = alpha;
    if (datGridEffectPastThreshold(grid) != 0) {
        effMiscDrawScreenColor(col.b, 0);
        return;
    }
    for (i = 0; i < 0xF; i++) {
        f32 startFrame;
        f32 endFrame;
        f32 frameValue;
        u8 *cellCursor;
        f32 radius;
        xy.vec.x = 320.0f + 160.0f * (f32)(i % 5 - 2);
        xy.vec.y = 224.0f + 160.0f * (f32)(i / 5 - 1);
        cellCursor = grid + (i << 5);
        startFrame = ((DatGridEffectCell *)(cellCursor + 0x18))->startFrame.f;
        frameValue = (f32)((DatGridEffect *)grid)->frame;
        radius = 0.0f;
        if (frameValue < startFrame) {
            shapeBlend = radius;
        } else {
            endFrame = ((DatGridEffectCell *)(cellCursor + 0x18))->endFrame.f;
            if (frameValue < endFrame) {
                shapeBlend = iGpffff8544;
                radius = 280.0f * (1.0f - cosf((fGpffff84a4 * (frameValue - startFrame)) / (endFrame - startFrame)));
            } else {
                shapeBlend = fGpffff8548;
                radius = 280.0f;
            }
        }
        switch (*(s16 *)grid) {
        case 0:
            datGridEffectDrawCell(xy.vec, col.w, 0.0f, radius, shapeBlend, 1);
            break;
        case 1:
            datGridEffectDrawStrip(xy.bits, 0.0f, radius, col.w, 0.0f, 0x30, 1);
            break;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Grid effect task destroy: free the work block [inferred]
// FUN_00356140
void datGridEffectDestroy(u8 *task)
{
    (*D_008873EC)(((SdkTask *)task)->work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Draw a grid effect strip at the packed position with the given opacity and size [inferred]
/* measured: replacing the stack color-word alias with savedColor[0] loses whole-owner MATCH under the scoped propagation setting. */
// FUN_00356170
void datGridEffectDrawStrip(s64 positionBits, f32 depth, f32 radius, s32 color,
                   f32 rotation, s32 segments, s32 masked)
{
    union { s64 bits; Vec2f position; } savedPosition[1];
    s32 savedColor[1];
    s32 useMask;
    s32 segmentCount;
    u8 alpha;

    savedPosition[0].bits = positionBits;
    savedColor[0] = color;
    segmentCount = segments;
    useMask = masked;
    alpha = ((u8 *)savedColor)[3];
    if (alpha != 0xFF) {
        useMask = 0;
    }
    shdDrawRadialFan(savedPosition[0].position, depth,
                  *(s32 *)((u8 *)savedColor), savedColor[0],
                  radius, rotation, segmentCount, 1.0f, 1.0f, useMask);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
// Intent: Draw a grid effect cell at the given position with the given opacity and size [inferred]
// FUN_003561D0
void datGridEffectDrawCell(Vec2f position, s32 color, f32 dummy,
                   f32 radius, f32 rotation, s32 masked)
{
    struct Frame {
        union { s32 bits; f32 value; } savedColor;
        union { f32 value; u8 bytes[4]; } temp;
    } frame;
    s32 useMask;
    u8 alpha;
    f32 scaled;
    f32 one;
    f32 shifted;
    f32 drawDepth;
    f32 drawRadius;
    f32 drawRotation;
    f32 drawScaleX;
    s32 drawMask;
    f32 drawScaleY;

    frame.savedColor.bits = color;
    scaled = radius / iGpffff83d4;
    shifted = iGpffff8544 + rotation;
    useMask = masked;
    frame.temp.value = frame.savedColor.value;
    alpha = frame.temp.bytes[3];
    if (alpha != 0xFF) {
        useMask = 0;
    }
    one = 1.0f;
    drawDepth = dummy;
    drawRadius = scaled;
    drawRotation = shifted;
    drawScaleX = one;
    drawMask = useMask;
    drawScaleY = one;
    shdDrawRadialFan(position, drawDepth, frame.savedColor.bits, frame.savedColor.bits,
                  drawRadius, drawRotation, 4,
                  drawScaleX, drawScaleY, drawMask);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
// FUN_00356250
#pragma opt_loop_invariants on
void datCommunityMenuInit(u8 *menuWork)
{
    extern u8 D_0064BDA0[];
    extern u8 D_0064CBE0[];
    extern u8 D_0064CC98[];
    extern char D_005E57F0[];
    extern char D_005E5810[];
    extern char D_005E5830[];
    extern char D_005E5850[];
    extern s32 cmmCommunityFindByKind(s16);
    extern s64 cmmCommunityArcana(s32);
    extern u16 cmmCommunityRecordValue(s32);
    extern s32 cmmCommunityTestBroken(s32);
    extern s32 cmmCommunityTestReversed(s32);
    extern u8 *resourceFindByName(char *);
    extern u8 *sdkSpriteNewNode(u32, u32);
    extern void kAssertFail(const void *, u32);
    extern s32 cmmAuxTable(void);
    extern void nmMesWindowInstallHandle(s32, u8 *);
    extern u8 *datPortraitTaskCreate(s32, s64, s32);
    extern u8 *datPortraitTextTaskCreate(s32, u16, s32);
    s16 i;
    s16 j;
    s16 k;
    u8 *src;
    u8 *dst;
    u8 *layoutTable;
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
    u8 *entryCursor;

    ((CommunityMenu *)menuWork)->origin.x = 0.0f;
    ((CommunityMenu *)menuWork)->origin.y = 0.0f;
    ((CommunityMenu *)menuWork)->opacity = 0xFF;
    ((CommunityMenu *)menuWork)->tableMode = -1;
    ((CommunityMenu *)menuWork)->stage = 0;
    for (i = 0; i < 3; i++) {
        ((CommunityMenu *)menuWork)->selection[i] = 0;
    }
    j = 0;
    layoutTable = D_0064BDA0;
    while (j < 0x2B) {
        src = layoutTable + j * 0x1C;
        dst = menuWork + j * 0x30;
        ((MenuSlotAnimation *)(dst + 0x150))->currentX.f = ((CampSlotLayout *)src)->x;
        ((MenuSlotAnimation *)(dst + 0x150))->currentY.f = ((CampSlotLayout *)src)->y;
        ((MenuSlotAnimation *)(dst + 0x150))->currentScaleX = (u16)((CampSlotLayout *)src)->scaleX;
        ((MenuSlotAnimation *)(dst + 0x150))->currentScaleY = (u16)((CampSlotLayout *)src)->scaleY;
        ((MenuSlotAnimation *)(dst + 0x150))->currentAlpha = ((CampSlotLayout *)src)->alpha;
        j++;
    }
    for (k = 0; k < 0x6C; k++) {
        entryCursor = menuWork + k * 0x14;
        ((CampGridEntry *)(entryCursor + 0x960))->column = k % 9;
        ((CampGridEntry *)(entryCursor + 0x960))->columns = 9;
        ((CampGridEntry *)(entryCursor + 0x960))->row = k / 9;
        ((CampGridEntry *)(entryCursor + 0x960))->rows = 0xC;
    }
    m = 0;
    n = 0;
    while (m < 0x15) {
        id = cmmCommunityFindByKind(m) & 0xFFFF;
        if (id > 0) {
            entryCursor = menuWork + n * 0xC;
            ((DatCommunityRow *)(entryCursor + 0x38))->arcana.s = cmmCommunityArcana(id);
            *(s16 *)&((DatCommunityRow *)(entryCursor + 0x38))->communityId = id;
            kind = (u16 *)(entryCursor + 0x3C);
            *kind = cmmCommunityRecordValue(id);
            if (*kind == 0xA) {
                ((DatCommunityRow *)(entryCursor + 0x38))->mode = 1;
            } else if (cmmCommunityTestBroken(id) != 0) {
                ((DatCommunityRow *)(entryCursor + 0x38))->mode = 3;
            } else if (cmmCommunityTestReversed(id) != 0) {
                ((DatCommunityRow *)(entryCursor + 0x38))->mode = 2;
            } else {
                ((DatCommunityRow *)(entryCursor + 0x38))->mode = 0;
            }
            n++;
        }
        m++;
    }
    ((CommunityMenu *)menuWork)->rowCount = n;
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
    *(u8* *)&((CommunityMenu *)menuWork)->resource1304 = h3 = resourceFindByName(D_005E57F0);
    if (h3 == NULL) {
        kAssertFail(D_0064CC98, 0x1EC);
    }
    for (q = 0; q < 0x4D; q++) {
        if (q < 2) {
            slot = (u8 **)(menuWork + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h0, D_0064CBE0[q]);
        } else if (q < 0x33) {
            slot = (u8 **)(menuWork + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h1, D_0064CBE0[q]);
        } else if (q < 0x34) {
            slot = (u8 **)(menuWork + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h3, D_0064CBE0[q]);
        } else {
            slot = (u8 **)(menuWork + q * 4 + 0x11D0);
            *slot = sdkSpriteNewNode((u32)h2, D_0064CBE0[q]);
        }
        if (*slot == NULL) {
            kAssertFail(D_0064CC98, 0x1FC);
        }
    }
    datCommunitySetTableMode(menuWork, 0);
    nmMesWindowInstallHandle(0xB, (u8 *)cmmAuxTable());
    ((CommunityMenu *)menuWork)->resource1308 = datScreenWipeTaskCreate(0, 1);
    ((CommunityMenu *)menuWork)->resource130C = datPortraitTaskCreate(0, 0, 0);
    ((CommunityMenu *)menuWork)->resource1310 = datPortraitTextTaskCreate(0, 0, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community panel open step: move the panel from its closed state to open and report it as ready [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00356820
s32 datCommunityPanelOpenStep(u8 *menuWork) {
    s32 v = ((CommunityMenu *)menuWork)->stage;

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(menuWork + 0x14) = v;
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00356870
s32 datCommunityPanelUpdate(u8 *menuWork)
{
    s16 counter;
    s32 index;
    s32 result;
    u8 *slot;
    extern void datCommunityListDraw(u8 *);
    extern void datCommunityEntriesStep(u8 *);
    extern void datCommunityBounceStep(u8 *);

    result = 1;
    counter = ((CommunityMenu *)menuWork)->frame;
    if (counter < 0x64) {
        *(s16 *)(menuWork + 0x20) = counter + 1;
    }
    index = 0;
    goto loop_test;
loop_body:
    if (((index >= 0x12) && (index <= 0x1B)) ||
        ((index > 0) && (index <= 5)) ||
        ((index >= 0x27) && (index <= 0x28))) {
        slot = menuWork + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(menuWork + 0x20), 1);
    } else if (index == 0x26) {
        slot = menuWork + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(menuWork + 0x20), 2);
    } else {
        slot = menuWork + (index * 0x30);
        radarAnimateValue(slot + 0x150, *(s16 *)(menuWork + 0x20), 0);
    }
    if (((MenuSlotAnimation *)(slot + 0x150))->currentAlpha != 0) {
        result = 0;
    }
    index += 1;
loop_test:
    if (index < 0x2B) {
        goto loop_body;
    }
    ((CommunityMenu *)menuWork)->angle = ((CommunityMenu *)menuWork)->angle + 1;
    if (*(s16 *)(menuWork + 0x22) > 0x168) {
        *(s16 *)(menuWork + 0x22) = *(s16 *)(menuWork + 0x22) - 0x168;
    }
    datCommunityEntriesStep(menuWork);
    datCommunityBounceStep(menuWork);
    datCommunityListDraw(menuWork);
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
 * The partial community layout preserves observed offsets without allocating data.
 * See docs/probe_archive/Community_menu_renderer_00356a10_20260930.md. */
// Intent: Draw the community list: the entry layout, badges and text for the community menu [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00356A10
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
void datCommunityListDraw(u8 *work) {
    CommunityMenu *menu;
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
    u8 *gridCell;

    /* Entries are initialized by datCommunityMenuInit with display modes 0 through 3. */
    menu = (CommunityMenu *)work;
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
                position.x = originX + ((MenuSlotAnimation *)(separatorAnimation + 0x690))->currentX.f;
                position.y = 64.0f * (f32)separatorIndex + (77.0f + (originY + ((MenuSlotAnimation *)(separatorAnimation + 0x690))->currentY.f));
                separatorAlpha = (u8)(((MenuSlotAnimation *)(separatorAnimation + 0x690))->currentAlpha);
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
            if (menu->rowCount > (visibleIndex + menu->selection[1])) {
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
            scrollThumbOffset = (6.0f + (f32) ((s32) (menu->selection[1] * 0x64) / scrollRange));
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
        selectedIndex = (s32)(menu->selection[0] + menu->selection[1]);
        if ((selectedIndex < 0) || (selectedIndex >= 0x15)) {
            kAssertFail(&D_0064CC98, 0x2DD);
        }
        selectedEntry = (u8 *)datCommunityAddOffset((u32)selectedIndex * 12, (u32)work);
        selectedCount = ((DatCommunityRow *)(selectedEntry + 0x38))->rank;
        categoryIndex = (s32)((*(u8 *)&((DatCommunityRow *)(selectedEntry + 0x38))->arcana.s - 1) & 0xFF);
        selectedMode = (s32)(((DatCommunityRow *)(selectedEntry + 0x38))->mode);
        tileTexture = (u8 *)(menu->resource11D4);
        position.x = ((2.0f + (originX + menu->gridOffset.x)) - 36.0f);
        position.y = (2.0f + (originY + menu->gridOffset.y));
        gridAlpha = (u8)(menu->gridOpacity);
        gridAlphaFloat = (f32)gridAlpha;
        gridBaseOpacityProduct = gridAlphaFloat * globalOpacity;
        gridQuantized = (u8)gridBaseOpacityProduct;
        gridOpacity = gridQuantized & 0xFF;
        for (cellIndex = 0; cellIndex < 0x6C; cellIndex++) {
            gridCell = (u8 *)(work + (cellIndex * 0x14));
            if (*( s16 *)((u8 *)(gridCell) + (0x960)) >= 0) {
                cellX = (position.x + (f32) ((((CampGridEntry *)(gridCell + 0x960))->columns - ((CampGridEntry *)(gridCell + 0x960))->column) * 0x2C));
                cellY = (position.y + (f32) ((((CampGridEntry *)(gridCell + 0x960))->rows - ((CampGridEntry *)(gridCell + 0x960))->row) * 0x25));
                cellBlend = (cmpGridCellFade(gridCell + 0x960, 0.5f, 0.5f, 1.0f));
                cellPaletteBytes = (u8 *)((s32)&D_0064CC48 + (*( s16 *)((u8 *)(gridCell) + (0x960)) * 4));
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
        categoryTexture = ((u8 **)((u8 *)datCommunityAddOffset((u32)(categoryIndex & 0xFF) * 4, (u32)work) + 0x12A4))[0];
        sdkSpriteDrawAt(categoryTexture, position.x - (sdkSpriteScaledWidth(categoryTexture) / 2.0f), position.y, 0xDDU, 0x74U, 0U, titleOpacity);
        position.x = (245.0f + (originX + menu->titleOffset.x));
        position.y = (19.0f + (originY + menu->titleOffset.y));
        rankColor = titleOpacity & 0xFF;
        nameColor = rankColor | ~0x7EFF;
        nameId = (u16 *)((u8 *)datCommunityAddOffset((u32)(selectedIndex * 12), (u32)work) + 0x3A);
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
        fclMesWindowDrawItem(position.x, position.y, 0.0f, rankColor, 1, 6, 7, ((s16 *)rankNames)[rankIndex & 0xFFFF]);
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
            sprite = ((u8 **)((u8 *)datCommunityAddOffset((u32)(u16)selectedCount * 4, (u32)work) + 0x11EC))[0];
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
            if (detailIndex == menu->selection[2]) {
                palette = (MenuColor *)D_0064B2E8;
                rowFontMode = 8;
            } else {
                palette = (MenuColor *)D_0064B2E0;
                rowFontMode = 6;
            }
            rowAnimation = (u8 *)(work + (detailIndex * 0x30));
            position.x = 15.0f + (originX + ((MenuSlotAnimation *)(rowAnimation + 0x2A0))->currentX.f);
            position.y = 28.0f * (f32)detailIndex + (178.0f + (originY + ((MenuSlotAnimation *)(rowAnimation + 0x2A0))->currentY.f));
            rowAlpha = (u8)(((MenuSlotAnimation *)(rowAnimation + 0x2A0))->currentAlpha);
            rowAlphaFloat = (f32)rowAlpha;
            rowOpacityProduct = rowAlphaFloat * globalOpacity;
            rowQuantized = (u8)rowOpacityProduct;
            rowOpacity = rowQuantized & 0xFF;
            rowColor = rowOpacity | ~0xFF;
            sprite = menu->resource125C;
            sdkSpriteDrawAt(sprite, position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            sprite = menu->resource1260;
            sdkSpriteDrawAt(sprite, 172.0f + position.x, position.y, palette->r, palette->g, palette->b, rowOpacity);
            frFontExDrawTextOutB(91.0f + position.x, position.y, 0.0f, rowColor, rowFontMode, 2, (const char *)datPersonaDisplayName(((CommunityMenu *)work)->detailIds[detailIndex]), 8, 0x18, -1);
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
            detailId = *(u16 *)((u8 *)datCommunityAddOffset((u32)(menu->selection[2] * 2), (u32)work) + 0x136);
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
            detailValue = *(s16 *)((u8 *)datCommunityAddOffset((u32)(currentRank & 0xFFFF) * 2, (u32)detailValues) - 2);
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
void datCommunityEntriesStep(u8 *menuWork) {
    s32 i;

    for (i = 0; i < 0x6C; i++) {
        datCommunityEntryStep(menuWork + i * 0x14 + 0x960);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Bounce step: halve the community menu's vertical velocity and reverse its direction [inferred]
// FUN_003593B0
void datCommunityBounceStep(u8 *menuWork)
{
    ((CommunityMenu *)menuWork)->zoom *= 0.5f;
    ((CommunityMenu *)menuWork)->rotation *= -0.5f;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Push a value into a community history slot: move the current value to the previous one and store the new value [inferred]
/* measured: replacing the two-array byte cursor with direct selection/history indexing loses whole-owner MATCH. */
// FUN_003593E0
s32 datCommunityPushValue(s32 menuAddress, s32 selectionIndex, s16 value)
{
    s32 off = selectionIndex * 2;
    u8 *p = (u8 *)(off + (s32)menuAddress);

    *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x24);
    *(s16 *)(p + 0x24) = value;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants on
// Intent: Select the community table for a mode: fill its 43 entries and the table's count and width; returns 0 when the mode is already set [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00359400
s32 datCommunitySetTableMode(u8 *menuWork, s32 mode)
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

    if (mode == ((CommunityMenu *)menuWork)->tableMode) {
        return 0;
    }
    for (i = 0; i < 43; i++) {
        off = i * 0x30;
        dst = menuWork + off;
        ((MenuSlotAnimation *)(dst + 0x150))->startX.f = ((MenuSlotAnimation *)(dst + 0x150))->currentX.f;
        ((MenuSlotAnimation *)(dst + 0x150))->startY.f = ((MenuSlotAnimation *)(dst + 0x150))->currentY.f;
        ((MenuSlotAnimation *)(dst + 0x150))->startScaleX = ((MenuSlotAnimation *)(dst + 0x150))->currentScaleX;
        ((MenuSlotAnimation *)(dst + 0x150))->startScaleY = ((MenuSlotAnimation *)(dst + 0x150))->currentScaleY;
        ((MenuSlotAnimation *)(dst + 0x150))->startAlpha.u = ((MenuSlotAnimation *)(dst + 0x150))->currentAlpha;
    }
    switch (mode) {
    case 0:
        table = D_0064B420;
        ((CommunityMenu *)menuWork)->flags = 53;
        ((CommunityMenu *)menuWork)->footerId = 16;
        break;
    case 1:
        table = D_0064BDA0;
        ((CommunityMenu *)menuWork)->footerId = 16;
        break;
    case 2:
        table = D_0064C260;
        ((CommunityMenu *)menuWork)->flags = 55;
        break;
    case 3:
        table = D_0064C720;
        ((CommunityMenu *)menuWork)->flags = 70;
        ((CommunityMenu *)menuWork)->footerId = 17;
        break;
    case 4:
        table = D_0064B8E0;
        ((CommunityMenu *)menuWork)->flags = 53;
        ((CommunityMenu *)menuWork)->footerId = 16;
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
        dst = menuWork + j * 0x30;
        ((MenuSlotAnimation *)(dst + 0x150))->targetX.f = ((CampSlotLayout *)src)->x;
        ((MenuSlotAnimation *)(dst + 0x150))->targetY.f = ((CampSlotLayout *)src)->y;
        value1 = ((CampSlotLayout *)src)->scaleX;
        ((MenuSlotAnimation *)(dst + 0x150))->targetScaleX = (u16)value1;
        value2 = ((CampSlotLayout *)src)->scaleY;
        ((MenuSlotAnimation *)(dst + 0x150))->targetScaleY = (u16)value2;
        ((MenuSlotAnimation *)(dst + 0x150))->targetAlpha = ((CampSlotLayout *)src)->alpha;
        ((MenuSlotAnimation *)(dst + 0x150))->startFrame.s = ((CampSlotLayout *)src)->startFrame;
        ((MenuSlotAnimation *)(dst + 0x150))->endFrame.s = ((CampSlotLayout *)src)->endFrame;
        j += 1;
table_loop_test:
        if (j < 43) {
            goto table_loop_body;
        }
    }
    *(s32 *)(menuWork + 0x18) = mode;
    ((CommunityMenu *)menuWork)->frame = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Report whether every community entry's threshold is met and the external check passes; returns 1 when the community list is ready [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_003596A0
s32 datCommunityIsReady(u8 *menuWork) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = ((CommunityMenu *)menuWork)->frame;

    while (i < 43) {
        if (v < *(s32 *)(menuWork + i * 48 + 0x17C)) {
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_00359720
void datCommunityMenuRelease(u8 *menuWork)
{
    s32 handle;
    s32 wipeTask;
    s32 portraitTask;
    s32 labelTask;
    s32 index;
    u8 *slot;

    index = 0;
    goto loop_test;
loop_body:
    slot = menuWork + (index * 4) + 0x11D0;
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
    wipeTask = *(s32 *)&((CommunityMenu *)menuWork)->resource1308;
    if (wipeTask != 0) {
        kwlnTaskDestroyWithHierarchy(wipeTask);
        *(s32 *)(menuWork + 0x1308) = 0;
    }
    portraitTask = *(s32 *)&((CommunityMenu *)menuWork)->resource130C;
    if (portraitTask != 0) {
        kwlnTaskDestroyWithHierarchy(portraitTask);
        *(s32 *)(menuWork + 0x130C) = 0;
    }
    labelTask = *(s32 *)&((CommunityMenu *)menuWork)->resource1310;
    if (labelTask != 0) {
        kwlnTaskDestroyWithHierarchy(labelTask);
        *(s32 *)(menuWork + 0x1310) = 0;
    }
    ((CommunityMenu *)menuWork)->flags = 0;
    nmMesWindowReleaseHandle(0xB);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Fill the community menu's visible record list from the kind table, keeping entries with a value and a passing flag [inferred]
/* The kind-record tail is consumed here as eight flag/value pairs; its wider record variant is not established. Retain that tail cursor; typed output indexing was measured separately. */
// FUN_003597F0
void datCommunityFillVisibleRecords(u8 *menuWork)
{
    s32 table;
    s32 flagId;
    s32 index;
    s32 count;
    u8 *entry;
    u8 *valuePtr;

    table = cmmKindRecord(
        *(u16 *)((u8 *)datCommunityAddOffset(
            (s32)(((CommunityMenu *)menuWork)->selection[0] + ((CommunityMenu *)menuWork)->selection[1]) * 0xC,
            (u32)menuWork) + 0x3A));
    index = 0;
    count = 0;
    goto loop_test;
loop_body:
    entry = (u8 *)(table + (index * 8));
    valuePtr = entry + 0x28;
    if ((*(s32 *)valuePtr != 0) &&
        ((flagId = *(s32 *)(entry + 0x24), flagId == 0) ||
         (datGetFlag(flagId) != 0))) {
        ((CommunityMenu *)menuWork)->detailIds[count] = *(s32 *)valuePtr;
        count += 1;
    }
    index += 1;
loop_test:
    if (index < 8) {
        goto loop_body;
    }
    ((CommunityMenu *)menuWork)->detailCount = count;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants on
// Intent: Set the five community slot positions: the active slots move to the off-screen start and the current slot to its resting position [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_003598D0
void datCommunitySetSlotLayout(u8 *menuWork)
{
    s32 activeCount;
    s32 index;
    f32 offscreenBelow;
    f32 offscreenAbove;
    f32 restingY;
    s32 startFrame;
    f32 restingX;

    activeCount = ((CommunityMenu *)menuWork)->selection[0];
    index = 0;
    offscreenBelow = 800.0f;
    offscreenAbove = -400.0f;
    restingY = 29.5f;
    startFrame = 1;
    restingX = 22.0f;
    goto loop_test;
loop_body:
    if (index != activeCount) {
        if (index < activeCount) {
            *(f32 *)(menuWork + (index * 0x30) + 0x5AC) = offscreenAbove;
            ((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x30))->targetY.f = offscreenAbove;
        } else {
            *(f32 *)(menuWork + (index * 0x30) + 0x5AC) = offscreenBelow;
            ((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x30))->targetY.f = offscreenBelow;
        }
        *(f32 *)(menuWork + (index * 0x30) + 0x4B8) = restingX;
        *(s16 *)(menuWork + (index * 0x30) + 0x4CE) = startFrame;
    } else {
        *(f32 *)(menuWork + (index * 0x30) + 0x5AC) = restingY;
        *(s16 *)&((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x450))->targetScaleY = startFrame;
        ((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x30))->targetY.f = restingY;
        *(s16 *)&((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x30))->targetScaleY = startFrame;
        ((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x360))->targetY.f = restingY;
        *(s16 *)&((MenuSlotAnimation *)((u8 *)(menuWork + 0x150) + index * 0x30 + 0x360))->targetScaleY = startFrame;
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
void datCommunityResetOffset(u8 *menuWork)
{
    *(u32 *)&((CommunityMenu *)menuWork)->rotation = 0x42700000;
    ((CommunityMenu *)menuWork)->zoom = D_00761260;
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
   table go through datCommunityIndexedAddress (offset + base). The panel width
   reads are spelled index-first, because retail recomputes index + arg1 for
   each width read; the heights use the panel structure. */
static inline u8 *datCommunityIndexedAddress(u32 offset, u8 *base)
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
void datPartyHudDraw(s32 rowIndex, u8 *menuWork)
{
    extern void sdkSpriteDrawSized(u8 *, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    extern void PrimDrawFlatRectangle(u8 *, u8 *, f32, s32);
    /* H011: the callee masks its argument with 0xFFFF. */
    /* H011: the u16 parameter is measured; the u32 definition (cmmMisc.c)
       mismatches the name-sprite call. */
    extern u8 *cmmNameRecord(u16);
    extern s32 frFontExDrawTextWithCharWidth(f32, f32, f32, s32, s32, s32, u8 *, s32, s32);
    extern f32 sdkSpriteScaledWidth(u8 *);
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
    x0 = ((CommunityMenu *)menuWork)->origin.x;
    y0 = ((CommunityMenu *)menuWork)->origin.y;
    fade = (f32)menuWork[0] / 255.0f;
    {
        s32 off = (((CommunityMenu *)menuWork)->selection[1] + rowIndex) * 12;

        kind = ((DatCommunityRow *)((u8 *)((u32)off + (u32)menuWork) + 0x38))->arcana.u;
        name = ((DatCommunityRow *)((u8 *)((u32)off + (u32)menuWork) + 0x38))->communityId;
        count = ((DatCommunityRow *)((u8 *)((u32)off + (u32)menuWork) + 0x38))->rank;
        if (kind >= 0x20) {
            kAssertFail(D_0064CC98, 0x5D5);
        }
        isSelf = (rowIndex == ((CommunityMenu *)menuWork)->selection[0]);
        mode = ((DatCommunityRow *)((u8 *)(off + (s32)menuWork) + 0x38))->mode;
    }
    x = x0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x5A0))->currentX.f;
    rowY = 64.0f * (f32)rowIndex;
    y = 81.0f + (rowY + (y0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x5A0))->currentY.f));
    scale = (f32)datCommunityIndexedAddress(rowIndex * 48, menuWork)[0x5BA];
    alpha = scale * fade;
    w = (f32)((MenuSlotAnimation *)((u8 *)((u8 *)(rowIndex * 48) + (u32)menuWork) + 0x5A0))->currentScaleX;
    h = (f32)((HudPanel_0035 *)(menuWork + 0x5B0))[rowIndex].h;
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
    x2 = 5.0f + (x0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x180))->currentX.f);
    y2 = 78.0f + (rowY + (y0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x180))->currentY.f));
    scale = (f32)datCommunityIndexedAddress(rowIndex * 48, menuWork)[0x19A];
    alpha = scale * fade;
    w2 = (f32)((MenuSlotAnimation *)((u8 *)((u8 *)(u32)(rowIndex * 48) + (u32)menuWork) + 0x180))->currentScaleX;
    h2 = (f32)((HudPanel_0035 *)(menuWork + 0x190))[rowIndex].h;
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
        spr = ((CommunityMenu *)menuWork)->resource11E8;
        sdkSpriteDrawSized(spr, px, py, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
        px = 124.0f + x2;
        py = y2 + 14.0f * scale;
        spr = ((u8 **)(datCommunityIndexedAddress((count & 0xFFFF) * 4, menuWork) + 0x11EC))[0];
        sdkSpriteDrawSized(spr, px, py, 0.0f,
                      ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    }
    px = 59.0f + x2;
    scale = h2 / 4096.0f;
    py = y2 + 32.0f * scale;
    spr = ((CommunityMenu *)menuWork)->resource1214;
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    spr = ((CommunityMenu *)menuWork)->resource1218;
    sdkSpriteDrawSized(spr, 88.0f + px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    px = 105.0f + x2;
    py = y2 + 33.0f * scale;
    spr = ((u8 **)(datCommunityIndexedAddress(kind * 4, menuWork) + 0x12A0))[0];
    sdkSpriteDrawSized(spr, px - sdkSpriteScaledWidth(spr) / 2.0f, py, 0.0f,
                  ctab[0], ctab[1], ctab[2], alpha, w2, h2, 0, 0.0f, 0);
    px = 156.0f + x2;
    py = y2 + 18.0f * scale;
    spr = ((CommunityMenu *)menuWork)->resource122C;
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    spr = ((CommunityMenu *)menuWork)->resource1230;
    sdkSpriteDrawSized(spr, 214.0f + px, py, 0.0f,
                  ptab[0], ptab[1], ptab[2], alpha, w2, h2, 0, 0.0f, 0);
    switch (mode) {
    case 0:
    case 1:
        px = 4.0f + (157.0f + x2);
        py = y2 + 20.0f * scale;
        ptab = ((CommunityMenu *)menuWork)->resource1234;
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
        sdkSpriteDrawSized(isSelf ? ((CommunityMenu *)menuWork)->resource1240 : ((CommunityMenu *)menuWork)->resource1244, px, py, 0.0f,
                      0xFF, 0xFF, 0xFF, alpha, w2, h2, 0, 0.0f, 0);
        break;
    case 3:
        px = 204.0f + x2;
        py = y2 + 14.0f * scale;
        sdkSpriteDrawSized(isSelf ? ((CommunityMenu *)menuWork)->resource1238 : ((CommunityMenu *)menuWork)->resource123C, px, py, 0.0f,
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
    x3 = 5.0f + (x0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x4B0))->currentX.f);
    y3 = 78.0f + (rowY + (y0 + ((MenuSlotAnimation *)(datCommunityIndexedAddress(rowIndex * 48, menuWork) + 0x4B0))->currentY.f));
    scale = (f32)datCommunityIndexedAddress(rowIndex * 48, menuWork)[0x4CA];
    kind = scale * fade;
    w3 = (f32)((MenuSlotAnimation *)((u8 *)((u8 *)(u32)(rowIndex * 48) + (s32)menuWork) + 0x4B0))->currentScaleX;
    h3 = (f32)((HudPanel_0035 *)(menuWork + 0x4C0))[rowIndex].h;
    px = 15.0f + x3;
    py = 2.0f + y3;
    spr = ((u8 **)(datCommunityIndexedAddress(mode * 4, menuWork) + 0x121C))[0];
    sdkSpriteDrawSized(spr, px, py, 0.0f,
                  0xFF, 0xFF, 0xFF, kind, w3, h3, 0, 0.0f, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set up a screen wipe slot from one of the two slot entries: initialise its positions or move it to its target, then set its offset and colour [inferred]
/* measured: the typed 0x1C-byte start/target/offset/color record changes address materialization; retain the color-table alias. */
// FUN_0035AC60
void datScreenWipeSetupSlot(u8 *task, s32 slotIndex, s32 initialize, s32 reverse)
{
    Float2 pair;
    s32 value;
    u8 *pairSrc;
    u8 *posA;
    u8 *posB;

    if ((slotIndex < 0) || (slotIndex >= 2)) {
        kAssertFail(&D_0064CC98, 0x6B8);
    }
    if (task == NULL) {
        kAssertFail(&D_0064CC98, 0x6B9);
    }
    if (reverse != 0) {
        posB = D_0064CC60 + (slotIndex * 0x1C);
        posA = posB + 8;
    } else {
        posA = D_0064CC60 + (slotIndex * 0x1C);
        posB = posA + 8;
    }
    pairSrc = D_0064CC70 + (slotIndex * 0x1C);
    pair = *(Float2 *)pairSrc;
    value = *(s32 *)(D_0064CC78 + (slotIndex * 0x1C));
    if (initialize != 0) {
        datScreenWipeInit(task, (Float2 *)posA, (Float2 *)posB);
    } else {
        datScreenWipeSetTarget(task, posB);
    }
    datScreenWipeSetOffset(task, pair);
    datScreenWipeSetColor(task, value);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Create the portrait task with its update and destroy callbacks and set up its first slot [inferred]
// FUN_0035ADC0
u8 *datPortraitTaskCreate(s32 parentAddress, s64 portraitId, s32 flags)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(&D_0064CC98, 0x6ED);
    work = D_008873F4[0](1, 0x144, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064CC98, 0x6EE);
    }
    task = kwlnTaskCreateChild((void *)(parentAddress), (const void *)(&D_0064CCD0), 0xC7, 0, 0, datPortraitUpdate, datPortraitDestroy, (u8 *)(work));
    ((CommunityPortrait *)work)->portraitId = 0;
    ((CommunityPortrait *)work)->loaded = 0;
    *(u8* *)&((CommunityPortrait *)work)->module = D_0064CCB0;
    {
        extern void datPortraitSetValue();
        datPortraitSetValue((s32)task, portraitId, flags);
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
s32 datPortraitUpdate(u8 *task)
{
    u8 *portraitWork;

    portraitWork = ((SdkTask *)task)->work;
    if ((((s32 *)portraitWork)[11] == 0) && (((CommunityPortrait *)portraitWork)->portraitId != 0)) {
        ((CommunityPortrait *)portraitWork)->loaded = datTextSlotLoadStep(portraitWork + 0x30);
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
void datPortraitDestroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
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
s32 datPortraitIsLoaded(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if ((((CommunityPortrait *)work)->loaded == 0) || (((CommunityPortrait *)work)->portraitId == 0)) {
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
s32 datPortraitValue(u8 *task) {
    s32 ready;
    u8 *work;

    work = (u8 *)(((SdkTask *)task)->work);
    if ((((CommunityPortrait *)work)->loaded == 0) || (((CommunityPortrait *)work)->portraitId == 0)) {
        ready = 0;
    } else {
        ready = 1;
    }
    if (ready != 0) {
        return (s32)(**(s32* *)&((CommunityPortrait *)work)->texture);
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035AFF0
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
f32 datCommunityPortraitDraw(u8 *task, u8 opacity)
{
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern f32 datPortraitMoveStep(u8 *);
    extern void sdkRenderStateSetDefault(void);
    extern s32 (*D_00887300[])(s32, void *);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern s32 (*D_00887314[])(s32, void *, s32, void *, s32);
    extern s32 RpSkyRenderStateSet(s32, void *);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern f32 cosf(f32);
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
    portrait = (CommunityPortrait *)*(u8 **)(task + 0x38);
    z = D_008872F8[0];
    q = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    {
        CommunityPortrait *t = (CommunityPortrait *)((SdkTask *)task)->work;
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
    qs[0].alpha = (f32)opacity;
    qs[0].u = u0;
    qs[0].v = v0;
    qs[0].reciprocalZ = q;
    qs[1].x = portrait->position.x + sx;
    qs[1].y = portrait->position.y - sy;
    qs[1].z = z;
    qs[1].red = 255.0f;
    qs[1].green = 255.0f;
    qs[1].blue = 255.0f;
    qs[1].alpha = (f32)opacity;
    qs[1].u = u0 + u1;
    qs[1].v = v0;
    qs[1].reciprocalZ = q;
    qs[2].x = portrait->position.x - sx;
    qs[2].y = portrait->position.y + sy;
    qs[2].z = z;
    qs[2].red = 255.0f;
    qs[2].green = 255.0f;
    qs[2].blue = 255.0f;
    qs[2].alpha = (f32)opacity;
    qs[2].u = u0;
    qs[2].v = v0 + v1;
    qs[2].reciprocalZ = q;
    qs[3].x = portrait->position.x + sx;
    qs[3].y = portrait->position.y + sy;
    qs[3].z = z;
    qs[3].red = 255.0f;
    qs[3].green = 255.0f;
    qs[3].blue = 255.0f;
    qs[3].alpha = (f32)opacity;
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
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035BAD0
f32 datPortraitMoveStep(u8 *portraitWork)
{
    f32 ratio;
    f32 angle;
    f32 fromX;
    f32 fromY;
    s16 step;

    ((CommunityPortrait *)portraitWork)->effectFrame = ((CommunityPortrait *)portraitWork)->effectFrame + 1;
    if (((CommunityPortrait *)portraitWork)->effectFrame >= 0x64) {
        *(s16 *)(portraitWork + 0x24) = 0;
    }
    step = ((CommunityPortrait *)portraitWork)->transitionFrame;
    if (step < 0xA) {
        *(s16 *)(portraitWork + 0x22) = (s16)(step + 1);
    }
    ratio = (f32)*(s16 *)(portraitWork + 0x22) / 10.0f;
    if ((ratio < 0.0f) || (ratio > 1.0f)) {
        kAssertFail(&D_0064CC98, 0x881);
    }
    angle = fGpffff84a4 * ratio;
    fromX = ((CommunityPortrait *)portraitWork)->startScale.x;
    ((CommunityPortrait *)portraitWork)->scale.x = fromX + ((((CommunityPortrait *)portraitWork)->targetScale.x - fromX) * sinf(angle));
    fromY = ((CommunityPortrait *)portraitWork)->startScale.y;
    ((CommunityPortrait *)portraitWork)->scale.y = fromY + ((((CommunityPortrait *)portraitWork)->targetScale.y - fromY) * sinf(angle));
    return ratio;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set the portrait's text value: reset its position and step, and write its text slot as a placeholder, a blank, or a numbered label when the value changes [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035BC10
void datPortraitSetValue(u8 *task, s8 portraitId, s32 flags)
{
    u8 *portraitWork;
    s8 previousPortraitId;
    u8 buf[0x100];

    portraitWork = ((SdkTask *)task)->work;
    ((CommunityPortrait *)portraitWork)->transitionFrame = 0;
    ((CommunityPortrait *)portraitWork)->position.x = 71.5f;
    ((CommunityPortrait *)portraitWork)->position.y = 106.0f;
    ((CommunityPortrait *)portraitWork)->targetScale.x = 1.0f;
    *(s32 *)&((CommunityPortrait *)portraitWork)->startScale.x = 0;
    ((CommunityPortrait *)portraitWork)->startScale.y = 1.0f;
    ((CommunityPortrait *)portraitWork)->targetScale.y = 1.0f;
    previousPortraitId = ((CommunityPortrait *)portraitWork)->portraitId;
    if (previousPortraitId == portraitId) {
        goto unchanged;
    }
    switch (portraitId) {
    case -1:
        goto minus_one_case;
    case 0:
        goto zero_case;
    default:
        goto other_case;
    }
minus_one_case:
    sprintf(buf, D_0064CCF0);
    datTextSlotSetString((s32 *)(portraitWork + 0x30), buf);
    goto done;
zero_case:
    datTextSlotSetString((s32 *)(portraitWork + 0x30), NULL);
    goto done;
other_case:
    sprintf(buf, D_0064CD10, (s32)portraitId - 1);
    datTextSlotSetString((s32 *)(portraitWork + 0x30), buf);
done:
    *(s8 *)(portraitWork + 0x20) = portraitId;
    ((CommunityPortrait *)portraitWork)->flags = flags;
    ((CommunityPortrait *)portraitWork)->loaded = 0;
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
    datPortraitAccumulateProjection(&total, 1.0f, projection);
    direction.xy.x = second.x - origin.x;
    direction.xy.y = second.y - origin.y;
    direction.z = 20.0f;
    RwV3dNormalize(&direction, &direction);
    projection = direction.xy.x * normal.xy.x + direction.xy.y * normal.xy.y + direction.z * normal.z;
    datPortraitAccumulateProjection(&total, 1.0f, projection);
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
s32 datPortraitTextLoadUpdate(u8 *task)
{
    u8 *labelWork;

    labelWork = ((SdkTask *)task)->work;
    if ((((s32 *)labelWork)[11] == 0) && (((DatPortraitLabel *)labelWork)->id != 0)) {
        ((DatPortraitLabel *)labelWork)->loaded = datTextSlotLoadStep(labelWork + 0x30);
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
void datPortraitTextDestroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    datTextSlotRelease(work + 0x30);
    (*D_008873EC)(work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Create the portrait text task with its update and destroy callbacks and place it at its start position [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035BF10
u8 *datPortraitTextTaskCreate(s32 parentAddress, u16 labelId, s32 flags)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(&D_0064CC98, 0x905);
    work = D_008873F4[0](1, 0x144, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_0064CC98, 0x906);
    }
    task = kwlnTaskCreateChild((void *)(parentAddress), (const void *)(&D_0064CD40), 0xC7, 0, 0, datPortraitTextLoadUpdate, datPortraitTextDestroy, (u8 *)(work));
    *(s16 *)&((DatPortraitLabel *)work)->id = 0;
    ((DatPortraitLabel *)work)->loaded = 0;
    ((DatPortraitLabel *)work)->target.x = 353.0f;
    *(s32 *)&((DatPortraitLabel *)work)->target.y = 0x42BC0000;
    ((DatPortraitLabel *)work)->start.x = 300.0f + *(f32 *)(work + 0x10);
    ((DatPortraitLabel *)work)->start.y = ((DatPortraitLabel *)work)->target.y;
    datPortraitSetLabel((s32)task, labelId, flags);
    return task;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Draw the portrait text: its sprite pass with the portrait's colour, offset and opacity [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035C040
f32 datPortraitTextDraw(u8 *task, u8 opacity)
{
    f32 tx;
    f32 ty;
    extern u8 *kwlnGetCamera(void);
    extern f32 D_008872F8[];
    extern void shdDrawColourQuad(f32, s32, f32, f32, f32, f32, f32, f32, s32 *, s32, s32);
    extern void sdkRenderStateSetDefault(void);
    extern s32 (*D_00887300[])(s32, s32);
    extern void (*D_00887310[])(s32, void *, s32);
    typedef struct {
        f32 x;
        f32 y;
        f32 depth;
        s32 _c;
        s32 u;
        s32 transitionFrame;
        f32 reciprocalDepth;
        s32 _1c;
        s32 r;
        s32 g;
        s32 b;
        f32 a;
        s32 _pad[4];
    } LabelVertex;
    u8 *labelWork;
    f32 depth;
    f32 reciprocalDepth;
    f32 blend;
    s16 transitionFrame;
    LabelVertex vertices[4];

    labelWork = ((SdkTask *)task)->work;
    depth = D_008872F8[0];
    reciprocalDepth = 1.0f / ((RwCamera *)kwlnGetCamera())->nearPlane;
    {
        u8 *visibilityWork = *(u8 **)(task + 0x38);
        s32 flag;
        if ((((DatPortraitLabel *)visibilityWork)->loaded == 0) || (((DatPortraitLabel *)visibilityWork)->id == 0)) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag == 0) {
            return 0.0f;
        }
    }
    transitionFrame = ((DatPortraitLabel *)labelWork)->transitionFrame;
    if (transitionFrame <= 9) {
        *(s16 *)(labelWork + 0x22) = transitionFrame + 1;
    }
    blend = sinf(fGpffff84a4 * ((f32)*(s16 *)(labelWork + 0x22) / 10.0f));
    if ((blend < 0.0f) || (blend > 1.0f)) {
        kAssertFail(&D_0064CC98, 0x936);
    }
    *(f32 *)labelWork = ((DatPortraitLabel *)labelWork)->start.x + blend * (((DatPortraitLabel *)labelWork)->target.x - ((DatPortraitLabel *)labelWork)->start.x);
    ((DatPortraitLabel *)labelWork)->position.y = ((DatPortraitLabel *)labelWork)->start.y + blend * (((DatPortraitLabel *)labelWork)->target.y - ((DatPortraitLabel *)labelWork)->start.y);
    ((DatPortraitLabel *)labelWork)->smoothed.x = ((DatPortraitLabel *)labelWork)->smoothed.x + 0.25f * (*(f32 *)labelWork - ((DatPortraitLabel *)labelWork)->smoothed.x);
    ((DatPortraitLabel *)labelWork)->smoothed.y = ((DatPortraitLabel *)labelWork)->smoothed.y + 0.25f * (((DatPortraitLabel *)labelWork)->position.y - ((DatPortraitLabel *)labelWork)->smoothed.y);
    vertices[0].x = *(f32 *)labelWork;
    vertices[0].y = ((DatPortraitLabel *)labelWork)->position.y;
    vertices[0].depth = depth;
    vertices[0].r = 0x437F0000;
    vertices[0].g = 0x437F0000;
    vertices[0].b = 0x437F0000;
    vertices[0].a = (f32)opacity;
    vertices[0].u = 0;
    vertices[0].transitionFrame = 0;
    vertices[0].reciprocalDepth = reciprocalDepth;
    tx = *(f32 *)labelWork;
    tx = tx + 256.0f;
    vertices[1].x = tx;
    vertices[1].y = *(f32 *)(labelWork + 4);
    vertices[1].depth = depth;
    vertices[1].r = 0x437F0000;
    vertices[1].g = 0x437F0000;
    vertices[1].b = 0x437F0000;
    vertices[1].a = (f32)opacity;
    vertices[1].u = 0x3F800000;
    vertices[1].transitionFrame = 0;
    vertices[1].reciprocalDepth = reciprocalDepth;
    vertices[2].x = *(f32 *)labelWork;
    ty = *(f32 *)(labelWork + 4);
    ty = ty + 256.0f;
    vertices[2].y = ty;
    vertices[2].depth = depth;
    vertices[2].r = 0x437F0000;
    vertices[2].g = 0x437F0000;
    vertices[2].b = 0x437F0000;
    vertices[2].a = (f32)opacity;
    vertices[2].u = 0;
    vertices[2].transitionFrame = 0x3F800000;
    vertices[2].reciprocalDepth = reciprocalDepth;
    tx = *(f32 *)labelWork;
    tx = tx + 256.0f;
    vertices[3].x = tx;
    ty = *(f32 *)(labelWork + 4);
    ty = ty + 256.0f;
    vertices[3].y = ty;
    vertices[3].depth = depth;
    vertices[3].r = 0x437F0000;
    vertices[3].g = 0x437F0000;
    vertices[3].b = 0x437F0000;
    vertices[3].a = (f32)opacity;
    vertices[3].u = 0x3F800000;
    vertices[3].transitionFrame = 0x3F800000;
    vertices[3].reciprocalDepth = reciprocalDepth;
    shdDrawColourQuad(0.0f, ((DatPortraitLabel *)labelWork)->color | (opacity & 0xFF), *(f32 *)(labelWork + 0x18) + -30.0f, *(f32 *)(labelWork + 0x1C), *(f32 *)labelWork, *(f32 *)(labelWork + 4), 256.0f, 256.0f, *(s32 **)(labelWork + 0x3C), 1, 0);
    sdkRenderStateSetDefault();
    D_00887300[0](1, *(s32 *)((DatPortraitLabel *)labelWork)->textSlot.result.node);
    D_00887310[0](4, &vertices[0], 4);
    return blend;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_loop_invariants off
// Intent: Set the portrait label for an id and flag set: choose the colour and suffix from the flags and write the label text, blank for ids without a day label [inferred]
/* measured: typing the remaining byte-offset accesses changes whole-owner instructions; retain their original pointer/access shape beside the proven layout. */
// FUN_0035C480
void datPortraitSetLabel(s32 taskAddress, u16 labelId, s32 flags)
{
    s8 daySuffix[8];
    u8 labelPath[0x100];
    f32 x;
    f32 y;
    s64 suffix;
    u32 id;
    u8 *work;
    extern u8 iGpffffa968;
    extern u8 iGpffffa96c;
    extern u8 D_0064CD60[];

    work = ((SdkTask *)taskAddress)->work;
    ((DatPortraitLabel *)work)->transitionFrame = 0;
    x = ((DatPortraitLabel *)work)->start.x;
    y = ((DatPortraitLabel *)work)->start.y;
    ((DatPortraitLabel *)work)->smoothed.x = x;
    ((DatPortraitLabel *)work)->smoothed.y = y;
    x = ((DatPortraitLabel *)work)->start.x;
    y = ((DatPortraitLabel *)work)->start.y;
    ((DatPortraitLabel *)work)->position.x = x;
    ((DatPortraitLabel *)work)->position.y = y;
    id = labelId & 0xFFFF;
    if ((((DatPortraitLabel *)work)->id != id) ||
        (((DatPortraitLabel *)work)->flags != flags)) {
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
        if (flags & 1) {
            ((DatPortraitLabel *)work)->color = 0xF6001600;
            suffix = 0x62;
        } else if (flags & 2) {
            ((DatPortraitLabel *)work)->color = 0xF600B000;
            suffix = 0x63;
        } else {
            ((DatPortraitLabel *)work)->color = 0xFFD13400;
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
                sprintf(daySuffix, &iGpffffa968);
            } else {
                sprintf(daySuffix, &iGpffffa96c);
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
            daySuffix[0] = 0;
            break;
        default:
            kAssertFail(&D_0064CC98, 0xA05);
            break;
        }
        sprintf(labelPath, D_0064CD60, id, (s8)suffix, daySuffix);
        datTextSlotSetString((s32 *)(work + 0x30), labelPath);
        goto done;
done:
        *(u16 *)(work + 0x20) = labelId;
        ((DatPortraitLabel *)work)->flags = flags;
        ((DatPortraitLabel *)work)->loaded = 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Copy the portrait's stored position into the caller's vector [inferred]
/* Float2 work and the Vec2f output have the same packed two-float representation; keep the aggregate copy ABI. */
// FUN_0035C670
void datPortraitGetPosition(u8 *task, Vec2f *position)
{
    *position = *(Vec2f *)(((SdkTask *)task)->work);
}
#pragma pop

/* Close the original outer renderer scopes after their final consumers. */
#pragma pop
#pragma pop
