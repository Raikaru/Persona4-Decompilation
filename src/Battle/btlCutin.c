#include "h_cdvd_request_internal.h"
#include "btl_effect_internal.h"
/* Original translation unit btlCutin.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
/* Ten-byte request copied by btlCutinCreatePacket; case 0 uses all three
 * signed resource IDs, while the other cases use ids[0]. */
typedef struct BtlCutinRequest {
    u16 kind;
    s16 ids[3];
    s16 count;
} BtlCutinRequest;

extern u8 *iGpffffb3ac;
extern void mdlEffectDestroyWithNodes();
extern u8 *btlPacketAlloc();
extern s32 btlCutinPoll();
extern void memcpy();
extern void btlCutinLoad(u8 *request);
extern s32 btlCutinLoadStatus();
extern s32 H_Cdvd_IsFileLoaded();
extern void H_Cdvd_Destroy();
extern s32 mdlEffectIsFinished();
extern void mdlEffectCommitTreeFrame();
extern void mdlEffectFlushTreeFrame();
extern void *TnGetTableBase();
extern void TnSetTableBase();
extern u8 D_005DC8CC[];
extern char D_00625190[];
extern char D_00625090[];
extern char D_006251C0[];
extern char iGpffffa528[8];
extern const char *iGpffffa530[2];
extern s16 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 day);
extern u32 datGetFlag(s32 bit);
extern s32 cutinDrawTaskCreate();
extern s32 sprintf(char *dst, const char *format, ...);
extern s32 func_00440b68(const char *format, ...);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern const char *iGpffffa520[2];
extern const char *D_00625050[3];
extern char D_00625060[];
extern char D_006250A0[];
extern char D_006250D0[];
extern char D_00625100[];
extern char D_00625130[];
extern char D_00625160[];


/* Exact under MWCC b210/O2: evaluate the case-0 count first, use the
   table element directly for the first format call, then retain the
   table-element address for the loop. */
/* Build cut-in resource paths from the request and day window, then start the required asynchronous loads. */
// FUN_001F9CF0
void btlCutinLoad(u8 *request) {
    s32 slotOffset;
    s32 dayWindow;
    s32 slotIndex;
    char path[0x100];

    dayWindow = (calGetDayWindowFlags(datGetDateIndex()) & 1) != 0;
    switch (*(u16 *)request) {
    case 0: {
        const char **suffix;
        s32 count;
        count = ((BtlCutinRequest *)(request))->count;
        sprintf(path, D_00625060, count + 1, count + 1, iGpffffa520[dayWindow]);
        suffix = &iGpffffa520[dayWindow];
        func_00440b68(iGpffffa528, D_00625090, 0x26);
        *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinHandles[0] = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        slotIndex = 0;
        while (slotIndex < count) {
            slotOffset = slotIndex * 4;
            sprintf(path, D_006250A0, count + 1, count + 1,
                          D_00625050[slotIndex],
                          ((BtlCutinRequest *)(request))->ids[slotIndex], *suffix);
            func_00440b68(iGpffffa528, D_00625090, 0x2C);
            *(s32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinHandles[1] = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
            slotIndex++;
        }
        sprintf(path, D_006250D0, count + 1, count + 1);
        func_00440b68(iGpffffa528, D_00625090, 0x2F);
        *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        break;
    }
    case 2:
        sprintf(path, D_00625100, ((BtlCutinRequest *)(request))->ids[0], iGpffffa520[dayWindow]);
        func_00440b68(iGpffffa528, D_00625090, 0x35);
        *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        break;
    case 4:
        if (((BtlCutinRequest *)(request))->ids[0] < 0xB) sprintf(path, D_00625130, ((BtlCutinRequest *)(request))->ids[0]);
        else sprintf(path, D_00625160, ((BtlCutinRequest *)(request))->ids[0]);
        func_00440b68(iGpffffa528, D_00625090, 0x40);
        *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        break;
    }
    ((BtlBattleState *)(iGpffffb3ac))->cutinKind = *(u16 *)request;
}



/* Poll all pending resource handles; build loaded effects unless cancellation is pending, and release each loaded handle. */
// FUN_001F9FA0
s32 btlCutinLoadStatus(void) {
    s32 slotIndex;
    s32 allLoaded;
    s32 slotOffset;

    allLoaded = 1;
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        u8 *handle = ((BtlBattleState *)((u32)slotIndex * 4 + (u32)iGpffffb3ac))->cutinHandles[0];
        if (handle != NULL) {
            if (H_Cdvd_IsFileLoaded(handle) != 0) {
                if (!(*(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinFlags & 1)) {
                    slotOffset = slotIndex * 4;
                    ((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinEffects[0] = mdlEffectBuildFromResource(*(u8 * *)&((HCdvdRequest *)(((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinHandles[0]))->data);
                }
                slotOffset = slotIndex * 4;
                H_Cdvd_Destroy(((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinHandles[0]);
                ((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinHandles[0] = 0;
            } else {
                allLoaded = 0;
            }
        }
    }
    if (allLoaded != 0 && H_Cdvd_IsFileLoaded(((BtlBattleState *)(iGpffffb3ac))->cutinHandle) != 0) {
        s32 flags = *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinFlags;
        if (!(flags & 1)) {
            ((BtlBattleState *)(iGpffffb3ac))->cutinEffect = mdlEffectBuildFromResource(*(u8 * *)&((HCdvdRequest *)(((BtlBattleState *)(iGpffffb3ac))->cutinHandle))->data);
        } else {
            *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinFlags = flags & ~1;
        }
        H_Cdvd_Destroy(((BtlBattleState *)(iGpffffb3ac))->cutinHandle);
        ((BtlBattleState *)(iGpffffb3ac))->cutinHandle = 0;
        return 1;
    }
    return 0;
}

/* Copy the ten-byte cut-in request into a load packet; the packet polls until every resource is ready. */
// FUN_001FA110
u8 *btlCutinCreatePacket(u8 *request) {
    u8 *p = btlPacketAlloc(0xC00, 0xA);

    ((BtlPacket *)p)->flags &= 0xEE;
    *(void **)&((BtlPacket *)p)->initFunc = (void *)btlCutinLoad;
    *(void **)&((BtlPacket *)p)->updateFunc = (void *)btlCutinLoadStatus;
    memcpy((s32 *)((BtlPacket *)p)->workData, request, 0xA);
    return p;
}

/* Advance and draw unfinished cut-in effects, destroy completed ones, and report when all are finished. */
// FUN_001FA190
s32 btlCutinUpdate(s32 *elapsed) {
    u8 *savedTable;
    s32 slotOffset;
    s32 effect;
    s32 mainEffect;
    s32 slotIndex;
    s32 allFinished;

    allFinished = 1;
    savedTable = TnGetTableBase();
    TnSetTableBase(&D_005DC8CC);
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        effect = *(s32 *)&((BtlBattleState *)((u32)slotIndex * 4 + (u32)iGpffffb3ac))->cutinEffects[0];
        if (effect != 0) {
            if (mdlEffectIsFinished(effect) == 0) {
                slotOffset = slotIndex * 4;
                mdlEffectCommitTreeFrame(*(s32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinEffects[0]);
                mdlEffectFlushTreeFrame(*(s32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinEffects[0]);
                allFinished = 0;
            } else {
                slotOffset = slotIndex * 4;
                mdlEffectDestroyWithNodes(*(s32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinEffects[0]);
                *(s32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->cutinEffects[0] = 0;
            }
        }
    }
    mainEffect = *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect;
    if (mainEffect != 0) {
        if (mdlEffectIsFinished(mainEffect) == 0) {
            mdlEffectCommitTreeFrame(*(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect);
            mdlEffectFlushTreeFrame(*(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect);
            allFinished = 0;
        } else {
            mdlEffectDestroyWithNodes(*(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect);
            *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect = 0;
        }
    }
    TnSetTableBase(savedTable);
    *elapsed += 1;
    return allFinished;
}

/* Create a polling packet with a zeroed elapsed counter for completion of the active cut-in effects. */
// FUN_001FA320
u8 *btlCutinCreateEndPacket(void) {
    u8 *p = btlPacketAlloc(0xC01, 4);

    ((BtlPacket *)p)->flags &= 0xEE;
    *(void **)&((BtlPacket *)p)->updateFunc = (void *)btlCutinUpdate;
    **(s32 **)&((BtlPacket *)p)->workData = 0;
    return p;
}

/* Cancel unfinished loads or destroy loaded cut-in effects; pending loads are marked for discard when they complete. */
// FUN_001FA370
s32 btlCutinPoll(void) {
    s32 i;
    s32 off;
    u8 *base;
    u8 *p;
    s32 h;

    for (i = 0; i < 4; i++) {
        base = iGpffffb3ac;
        off = i * 4;
        p = base + off;
        if (*(s32 *)&((BtlBattleState *)(p))->cutinHandles[0] != 0) {
            *(s32 *)&((BtlBattleState *)(base))->cutinFlags |= 1;
        } else {
            h = *(s32 *)&((BtlBattleState *)(p))->cutinEffects[0];
            if (h != 0) {
                mdlEffectDestroyWithNodes(h);
                *(s32 *)&((BtlBattleState *)(iGpffffb3ac + off))->cutinEffects[0] = 0;
            }
        }
    }
    base = iGpffffb3ac;
    if (*(s32 *)&((BtlBattleState *)(base))->cutinHandle != 0) {
        *(s32 *)&((BtlBattleState *)(base))->cutinFlags |= 1;
    } else {
        h = *(s32 *)&((BtlBattleState *)(base))->cutinEffect;
        if (h != 0) {
            mdlEffectDestroyWithNodes(h);
            *(s32 *)&((BtlBattleState *)(iGpffffb3ac))->cutinEffect = 0;
        }
    }
    return 1;
}

/* Queue the cut-in cancellation callback in a zero-work packet. */
// FUN_001FA450
void btlCutinCreateStartPacket(void) {
    u8 *p = btlPacketAlloc(0xC02, 0);

    ((BtlPacket *)p)->flags &= 0xEE;
    *(void **)&((BtlPacket *)p)->updateFunc = (void *)btlCutinPoll;
}

/* Load the requested cut-in name resource, or create the special draw task from date and flag-dependent parameters. */
// FUN_001FA490
void btlCutinSetupName(u8 *request) {
    struct { s16 a; s16 b; } drawParams;
    char path[0x10C];
    s32 dayWindow;
    u16 kind;

    dayWindow = (calGetDayWindowFlags(datGetDateIndex()) & 1) != 0;
    kind = ((BtlCutinRequest *)request)->kind;
    switch (kind) {
    case 1:
        sprintf(path, D_00625190, ((BtlCutinRequest *)request)->ids[0], iGpffffa530[dayWindow]);
        func_00440b68(iGpffffa528, D_00625090, 0x152);
        *(s32 *)&((BtlBattleState *)iGpffffb3ac)->cutinNameHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        break;
    case 3:
        sprintf(path, D_006251C0, ((BtlCutinRequest *)request)->ids[0], iGpffffa530[dayWindow]);
        func_00440b68(iGpffffa528, D_00625090, 0x158);
        *(s32 *)&((BtlBattleState *)iGpffffb3ac)->cutinNameHandle = (u32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
        break;
    case 5:
        if (datGetFlag(0x38) != 0) {
            drawParams.a = 5;
            if (calGetDayWindowFlags(datGetDateIndex()) & 1) {
                drawParams.b = 0x1E;
            } else {
                drawParams.b = 0x14;
            }
        } else {
            drawParams.a = 8;
            drawParams.b = 0x1E;
        }
        ((BtlBattleState *)iGpffffb3ac)->cutinNameTask = cutinDrawTaskCreate(((BtlBattleState *)iGpffffb3ac)->cutinTaskParent, *(s32 *)&drawParams);
        break;
    }
    ((BtlBattleState *)iGpffffb3ac)->cutinNameKind = ((BtlCutinRequest *)request)->kind;
}
