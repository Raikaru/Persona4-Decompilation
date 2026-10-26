#include "kwln_draw_callbacks_internal.h"
#include "operand_order_internal.h"
#include "memcard_summary_internal.h"
#include "member_access.h"
#include "primitive_queue_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit mc.c (from __FILE__ assert strings). */
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
#include "h_cdvd.h"

/* Unit settings: independent variable-lifetime optimization enabled. */
#pragma opt_lifetimes on

/* The SDK getter requires the callback task and returns a packed address. */
extern u32 kwlnTaskGetWork(void *task);
extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern void PrimDrawFlatRectangle(void *, void *, f32, s32);
extern void sdkSpritePackDestroy(u32 pack);
extern s32 shdSpriteDrawNow(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
extern void mcQueueDrawJob(s32);
extern void mcIconWorkFree(void *allocation);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void kAssertFail(const void *file, u32 line);

extern void RpSkyRenderStateSet(s32, s32);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 sdkSpritePackCreate(const void *);
extern s32 shdSpriteEnsureLoaded(s32);
extern s32 H_Cdvd_AcquireDirectory(const char *path, s32 flags);
extern void func_00440b68(const void *, ...);
extern void H_Memcard_SetRecordTable(void *);
extern void shdWindowMarkDone(u8 *object);
extern s32 shdWindowTaskCreate(s32, s32, s32);
extern u8 *datSaveBuildImage(s32, s32 *, s32);
extern void memcpy(void *, void *, s32);
extern void H_Memcard_BeginLoad(s32, void *, s32);
extern void H_Memcard_SetSlot(s32);
extern char D_0063EB90[];
extern char D_0063EBB0[];
extern char D_0063EBD0[];
extern char D_0063EB20[];
extern char D_0063ED38[];
extern char D_00763900;
extern void resrcMngSetRenderSuppressed(s32);
extern s32 mcStepState(u8 *);
extern s32 mcAnimateTransition(s32);
extern s32 mcTableRandomize(s32, u8 *, u8 *, s32);
extern s32 mcRunScreenExitFrame(s32);
extern s32 mcDrawScreenSettled(s32);
extern void sdkListStateConfigure(void *, s32, s32, s32, s32);
extern void sdkListStateSetSecondaryMasks(void *, s32, s32, s32, s32);
extern void sdkListStateSetReservedRows(void *, s32);
extern void sdkListStateSetRefresh(void *, s32);
extern s32 sdkListStateHandleInput(void *);
extern void sdkListStateSetActive(void *, s32);
extern s32 sdkListStateGetCursor(void *);
extern s32 sdkListStateGetScroll(void *);
extern void *memset(void *dst, s32 value, u32 size);
extern char D_00796370[];
extern void (*D_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
typedef int (*RwRenderStateSetFunc)(s32, s32);
extern f32 D_00763910;
extern s32 D_00764634;
extern s32 D_00764638;
extern char D_007638F8;
extern char D_00763918;
typedef struct { u64 lo, hi; } Qword;
extern Qword D_0063ED70;
extern f32 D_00761184;
extern f32 D_00761174;
extern f32 iGpffff8214;
extern f32 iGpffff8218;
extern f32 iGpffff821c;
extern f32 iGpffff8030;
extern s32 func_0043c6a0(u32);
extern void mcDrawSlotDial(f32, f32, f32, s32, u8 *, s32, s32, f32, u8 *);
extern void mcScreenStep(f32, f32, f32, s32, u8 *, s32, s32, u8 *);
extern void mcDrawFadedColor(s32, s32, s32, void *);
extern void mcSeedEntryTable(s32, u8 *);
extern void mcDrawGlyph(s32, s32, s32, u8 *);
extern void mcAdvanceMeter(s32, s32, s32, u8 *);
extern void mcSetSkyRenderState(s32, s32, s32, s32, f32);
extern void mcDrawCardStatusPulse(s32, s32, s32, u8 *);
extern s32 D_0063ED80[];
extern f32 cosf(f32);
extern f32 sinf(f32);
extern f32 iGpffff81e0;
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern void PrimDrawPoints(void *, void *, f32, s32, s32, s32);
extern void mcDrawCircleFan(f32, f32, f32, s32, s32, f32, f32, s32);
extern void PrimDrawFlatTriangle(void *, void *, s32, f32);
typedef struct { s32 a, b, c, d; } Quad4;
typedef struct { s32 x, y, width, height; } McRect;
extern f32 iGpffffa818;
extern f32 iGpffffa81c;
extern McRect D_0063ED50;
extern McRect D_0063ED60;
extern RwRenderStateSetFunc D_00887300[4];
extern char D_0063EBF0[];
extern char D_0063EB50[];
extern char D_0063EB70[];
extern char D_0063EC10[];
extern char D_0063EC30[];
extern char D_0063EC50[];
extern char D_0063EC70[];
extern char D_0063EC90[];
extern char D_0063ECB0[];
extern char D_0063ECD0[];
extern char D_0063ECF0[];
extern char D_0063ED20[];
extern s32 H_Memcard_LoadStep(void);
extern s32 shdWindowQueryState(u8 *object);
extern void H_Memcard_SetAbort(void);
extern s32 H_Memcard_CheckCard(void);
extern s32 H_Memcard_ProbeCardStep(void);
extern s32 H_Memcard_PrepareSaveFileStep(void);
extern void H_Memcard_SetSeqMode9(void);
extern void H_Memcard_SetSeqMode4(void);
extern void H_Memcard_BeginSave(s32, s32, s32);
extern s32 H_Memcard_SaveStep(void);
extern void datSaveRestoreImage(s32, u8 *, s32);
extern s32 datSaveVerifyChecksum(s32, u8 *, s32);
extern u16 D_008C024E[];
extern s32 calGetWeekdayOfDay(s32);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
extern s32 calHasDayEntry(s32 day);
extern s32 shdSpriteEntryWidth(s32, s32, u8 *);
/* Location keys and text pointer occupy three 32-bit retail words. */
typedef struct McLocationNameEntry {
    s32 area;
    s32 room;
    const char *name;
} McLocationNameEntry;
extern McLocationNameEntry D_0063EA60[];
extern void sprintf(void *, void *, s32, ...);
typedef void (*McGlyphCallback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
extern void shdSpriteDrawNumberString(f32, f32, f32, s32, u8, void *, s32, void *, McGlyphCallback, u8 *);

extern s16 D_0063EB30[];
extern char iGpffffa824;
extern void yTimeDrawIndexedGlyph(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
extern void mcDrawLocationText(f32, f32, f32, s32, s32, u8 *, s32, u8 *);
extern void mcDrawDateAndLocation(f32, f32, f32, s32, s32, s32, u8 *, u8 *);
extern u32 RpRandom(void);
extern s32 D_0063EDB0[];
extern s32 D_0063EDD0[];
extern f32 D_00761300;

/* Each save-table entry holds two text strings followed by a location word. */

typedef struct McCircleEntry {
    u32 flags;
    s32 kind;
    union { f32 value; s32 bits; } x, y;
    s16 frame, delay;
} McCircleEntry;

/* Circle pool and its one-time initialization counter form one screen subobject. */
typedef struct McCirclePool {
    McCircleEntry entries[20];
    s32 seeded;
} McCirclePool;

typedef struct McSaveBuffer {
    s32 size;
    u8 *data;
} McSaveBuffer;
typedef struct McRecordTable {
    s32 states[16];
    McSaveRecord records[16];
} McRecordTable;


/* Card operations share the screen state's record table. */
typedef struct McScreenState {
    s16 phase;
    s16 interactionPhase;
    u32 flags;
    s32 operation;
    s32 operationState;
    s32 operationFlags;
    McRecordTable records;
    s32 window;
    s32 spritePack;
    s32 saveBuffer;
    s32 unk3A0;
    s32 directory;
    s32 delay;
    s32 slot;
    s32 scroll;
    s32 scrollPosition; /* 16.16 slot coordinate */
    s32 selectionPulse;
    s32 iconFade;
    s32 upperPulse;
    s32 lowerPulse;
    s32 upperFade;
    s32 lowerFade;
    s32 legendFade;
    McCircleEntry circles[20];
    s32 circlesSeeded;
    s32 frame;
} McScreenState;
typedef char McSaveRecordSizeCheck[sizeof(McSaveRecord) == 0x34 ? 1 : -1];
typedef char McCircleEntrySizeCheck[sizeof(McCircleEntry) == 0x14 ? 1 : -1];
typedef char McSaveBufferSizeCheck[sizeof(McSaveBuffer) == 8 ? 1 : -1];
typedef char McRecordTableSizeCheck[sizeof(McRecordTable) == 0x380 ? 1 : -1];
typedef char McScreenStateSizeCheck[sizeof(McScreenState) == 0x56C ? 1 : -1];

/* Enter a card operation, resetting its substate and replacing the status dialog. */
// FUN_002A2E50
void mcSetState(u8 *work, s32 state) {
    McScreenState *screenState = (McScreenState *)work;
    s32 currentState;
    s32 slot;
    u8 *image;
    s32 imageSize;
    u8 *buffer;
    s32 size;

    ((McScreenState *)work)->operation = state;
    ((McScreenState *)work)->operationState = 0;
    currentState = ((McScreenState *)work)->operation;
    switch (currentState) {
    case 0:
        memset(work + 0x14, 0, 0x380);
        H_Memcard_SetRecordTable(work + 0x14);
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            screenState->window = 0;
        }
        screenState->window = shdWindowTaskCreate(0, 0, 0xF);
        func_00440b68(&D_0063EB90);
        return;
    case 1:
        H_Memcard_SetSlot(((McScreenState *)work)->slot);
        screenState->operationState = 0;
        return;
    case 2:
        slot = ((McScreenState *)work)->slot;
        image = datSaveBuildImage(0, &size, 0);
        imageSize = size;
        chkmemAllocSiteTag(&D_007638F8, 0x16D);
        buffer = D_008873F4[0](1, 0x38008, 0x40000);
        ((McSaveBuffer *)buffer)->data = buffer + 8;
        if (image != NULL && imageSize != 0) {
            memcpy((void *)MEMBER(s32, buffer, McSaveBuffer, data), image, imageSize);
            ((McSaveBuffer *)buffer)->size = imageSize;
        }
        D_008873EC[0](image);
        H_Memcard_BeginLoad(slot, (void *)MEMBER(s32, buffer, McSaveBuffer, data), ((McSaveBuffer *)buffer)->size);
        ((McScreenState *)work)->saveBuffer = (s32)buffer;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            screenState->window = 0;
        }
        screenState->window = shdWindowTaskCreate(0, 0, 0xF);
        func_00440b68(&D_0063EBB0);
        screenState->operationState = 0;
        return;
    case 3:
        func_00440b68(&D_0063EBD0);
        screenState->operationState = 0x10;
        return;
    }
}

/* Advance loading and its error dialog; return the screen transition result. */
// FUN_002A3070
s32 mcLoadState(u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 state;
    s32 result;
    s32 dialogClosed;

    dialogClosed = 0;
    state = ((McScreenState *)work)->operationState;
    switch (state) {
    case 0:
        switch (result = H_Memcard_LoadStep()) {
        case 100:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            func_00440b68(&D_0063EBF0);
            return 1;
        case -2:
            screenState->operationState = 1;
            func_00440b68(&D_0063EC10);
            memset(work + 0x14, 0, 0x380);
            break;
        case -1:
        case -3:
        case -4:
        case -5:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            func_00440b68(&D_0063EC30, result);
            screenState->operationState = 0xA;
            break;
        default:
            break;
        }
        break;
    case 0xA:
        screenState->operationState = 0xB;
        H_Memcard_SetAbort();
        /* fallthrough */
    case 0xB:
        result = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (result != 0) {
            screenState->window = 0;
        }
        if (result != 0) {
            dialogClosed = 1;
        }
        result = H_Memcard_CheckCard();
        switch (result) {
        case -2:
        case 3:
            return 3;
        }
        if (dialogClosed != 0) {
            return 4;
        }
        break;
    case 1:
        screenState->operationState = 2;
        ((McScreenState *)work)->delay = 0;
        /* fallthrough */
    case 2:
        state = ((McScreenState *)work)->delay + 1;
        ((McScreenState *)work)->delay = state;
        if (state >= 0xF) {
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            return 1;
        }
        break;
    }
    return 0;
}


// Memory-card probe dialog: a ready card returns 1, an error opens a dialog and waits; later states
// wait for a second dialog and return 4 when it closes.
// FUN_002A32C0
s32 mcCardProbeStep(u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 state;
    s32 result;

    state = ((McScreenState *)work)->operationState;
    switch (state) {
    case 0:
        switch (result = H_Memcard_ProbeCardStep()) {
        case 100:
            func_00440b68(&D_0063EC50);
            return 1;
        case -6:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 6);
            func_00440b68(&D_0063EC70);
            screenState->operationState = 0xA;
            break;
        case -1:
        case -4:
        case -5:
        case -9:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            func_00440b68(&D_0063EC30, 0);
            screenState->operationState = 0xA;
            break;
        default:
            break;
        }
        break;
    case 0xA:
        screenState->operationState = 0xB;
        /* fallthrough */
    case 0xB:
        result = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (result != 0) {
            screenState->window = 0;
        }
        if (result != 0) {
            screenState->operationState = 0xC;
        }
        break;
    case 0xC:
        screenState->operationState = 0xD;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            screenState->window = 0;
        }
        screenState->window = shdWindowTaskCreate(0, 0, 8);
        /* fallthrough */
    case 0xD:
        result = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (result != 0) {
            screenState->window = 0;
        }
        if (result != 0) {
            return 4;
        }
        break;
    }
    return 0;
}


/* Advance save-file preparation and confirmation/error dialogs. */
// FUN_002A34E0
s32 mcMemcardStep(u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 result;
    u8 *buffer;
    s32 state;
    s32 status;
    s32 slotOffset;

    state = ((McScreenState *)work)->operationState;
    switch (state) {
    case 0:
        buffer = (u8 *)((McScreenState *)work)->saveBuffer;
        switch (result = H_Memcard_PrepareSaveFileStep()) {
        case 100:
            D_008873EC[0](buffer);
            break;
        case 1:
            func_00440b68(&D_0063EB50);
            result = 1;
            break;
        case 2:
            func_00440b68(&D_0063EB70);
            result = 2;
            break;
        case -1:
        case -3:
        case -4:
        case -5:
        case -6:
        case -7:
            break;
        }
        switch (result) {
        case 100:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 9);
            func_00440b68(&D_0063EC90);
            screenState->operationState = 9;
            if (work == NULL) {
                kAssertFail(&D_007638F8, 0xE3);
            }
            D_00764638 = ((McScreenState *)work)->slot;
            break;
        case 1:
            screenState->operationState = 3;
            break;
        case 2:
            func_00440b68(&D_0063EC10);
            screenState->operationState = 5;
            break;
        case 4:
            func_00440b68(&D_0063ECB0);
            ((McScreenState *)work)->operationFlags &= ~1;
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 7);
            break;
        case 5:
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 7);
            break;
        case -5:
            func_00440b68(&D_0063EC30, result);
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            screenState->operationState = 0xA;
            break;
        case -3:
            func_00440b68(&D_0063EC30, result);
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            screenState->operationState = 0xA;
            break;
        case -6:
            func_00440b68(&D_0063EC30, result);
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 6);
            screenState->operationState = 0xA;
            break;
        case -4:
            slotOffset = ((McScreenState *)work)->slot * 4;
            ((McScreenState *)(slotOffset + (s32)work))->records.states[0] = 2;
            /* fallthrough */
        case -7:
            func_00440b68(&D_0063EC30, result);
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0x16);
            screenState->operationState = 0xA;
            break;
        case 0:
            break;
        }
        break;
    case 3:
        screenState->operationState = 4;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            screenState->window = 0;
        }
        screenState->window = shdWindowTaskCreate(0, 0, 4);
        H_Memcard_SetAbort();
        /* fallthrough */
    case 4:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            screenState->window = 0;
        }
        switch (status) {
        case 1:
            screenState->operationState = 0;
            if (screenState->window != 0) {
                shdWindowMarkDone((u8 *)(screenState->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 7);
            H_Memcard_SetSeqMode9();
            break;
        case 2:
            D_008873EC[0]((void *)((McScreenState *)work)->saveBuffer);
            return 2;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -5:
        case 3:
            func_00440b68(&D_0063EC30, status);
            if (screenState->window != 0) {
                shdWindowMarkDone((u8 *)(screenState->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            screenState->operationState = 0xA;
            break;
        }
        break;
    case 5:
        screenState->operationState = 6;
        ((McScreenState *)work)->operationFlags |= 1;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            screenState->window = 0;
        }
        screenState->window = shdWindowTaskCreate(0, 0, 1);
        H_Memcard_SetAbort();
        /* fallthrough */
    case 6:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            screenState->window = 0;
        }
        switch (status) {
        case 1:
            screenState->operationState = 0;
            if (screenState->window != 0) {
                shdWindowMarkDone((u8 *)(screenState->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 2);
            H_Memcard_SetSeqMode4();
            break;
        case 2:
            return 2;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -5:
        case 3:
            func_00440b68(&D_0063EC30, status);
            if (screenState->window != 0) {
                shdWindowMarkDone((u8 *)(screenState->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 0);
            screenState->operationState = 0xA;
            break;
        }
        break;
    case 9:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            screenState->window = 0;
        }
        if (status != 0) {
            return 1;
        }
        break;
    case 10:
        screenState->operationState = 0xB;
        H_Memcard_SetAbort();
        /* fallthrough */
    case 11:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            screenState->window = 0;
        }
        if (status != 0) {
            screenState->operationState = 0xC;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -2:
        case 3:
            screenState->operationState = 0xC;
            break;
        }
        break;
    case 12:
        screenState->operationState = 0xD;
        H_Memcard_SetAbort();
        if (((McScreenState *)work)->operationFlags & 1) {
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 3);
        } else {
            if (((McScreenState *)work)->window != 0) {
                shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
                screenState->window = 0;
            }
            screenState->window = shdWindowTaskCreate(0, 0, 8);
        }
        screenState->operationFlags &= ~1;
        D_008873EC[0]((void *)((McScreenState *)work)->saveBuffer);
        /* fallthrough */
    case 13:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            screenState->window = 0;
        }
        if (status != 0) {
            return 4;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -2:
        case 3:
            return 4;
        }
        break;
    }
    return 0;
}


/* Read the selected save image, verify its checksum, and apply valid data. Only the deallocator
 * slot address is cached, not its callback or work pointer. */
// FUN_002A3D80
s32 mcSaveState(s32 address) {
    u8 *work = (u8 *)address;
    s32 state;
    s32 status;
    s32 slot;
    u8 *buffer;
    s32 valid;
    s32 version;
    s32 imageSize;
    void *freeSlot;
    u8 *temporary;

    state = ((McScreenState *)work)->operationState;
    switch (state) {
    case 16:
        MEMBER(s32, work, McScreenState, operationState) = 0x11;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0xB);
        H_Memcard_SetAbort();
        /* fallthrough */
    case 17:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        switch (status) {
        case 1:
            if (MEMBER(s32, work, McScreenState, window) != 0) {
                shdWindowMarkDone((u8 *)(MEMBER(s32, work, McScreenState, window)));
                MEMBER(s32, work, McScreenState, window) = 0;
            }
            MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0xC);
            MEMBER(s32, work, McScreenState, operationState) = 0x12;
            break;
        case 2:
            return 2;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case 0:
            break;
        case -5:
        case 3:
            func_00440b68(D_0063EC30, status);
            return 4;
        }
        break;
    case 18:
        MEMBER(s32, work, McScreenState, operationState) = 0x13;
        slot = ((McScreenState *)work)->slot;
        chkmemAllocSiteTag(&D_007638F8, 0x16D);
        buffer = D_008873F4[0](1, 0x38008, 0x40000);
        ((McSaveBuffer *)buffer)->data = buffer + 8;
        H_Memcard_BeginSave(slot, MEMBER(s32, buffer, McSaveBuffer, data), (s32)buffer);
        ((McScreenState *)work)->saveBuffer = (s32)(buffer);
        /* fallthrough */
    case 19:
        status = H_Memcard_SaveStep();
        if (status == 0) {
            break;
        }
        if (status == -3 || status == -5) {
            goto read_failed;
        }
        switch (status) {
        case 100:
            buffer = (u8 *)((McScreenState *)work)->saveBuffer;
            version = 0;
            temporary = datSaveBuildImage(0, &imageSize, 0);
            freeSlot = D_008873EC;
            (*(void (**)(void *))freeSlot)(temporary);
            memcpy(&version, ((McSaveBuffer *)buffer)->data, 4);
            if (datSaveVerifyChecksum(version, MEMBER(u8 *, buffer, McSaveBuffer, data) + 4, ((McSaveBuffer *)buffer)->size - 4) == 0) {
                valid = 0;
            } else {
                datSaveRestoreImage(version, MEMBER(u8 *, buffer, McSaveBuffer, data) + 4, ((McSaveBuffer *)buffer)->size - 4);
                valid = 1;
            }
            (*(void (**)(void *))freeSlot)(MEMBER(void *, work, McScreenState, saveBuffer));
            if (valid != 0) {
                func_00440b68(D_0063ECD0);
                MEMBER(s32, work, McScreenState, operationState) = 0x14;
                if (work == NULL) {
                    kAssertFail(&D_007638F8, 0xE3);
                }
                D_00764638 = ((McScreenState *)work)->slot;
            } else {
                func_00440b68(D_0063ECF0);
                MEMBER(s32, work, McScreenState, operationState) = 0x16;
            }
            break;
        case -4:
            func_00440b68(D_0063ED20);
            MEMBER(s32, work, McScreenState, operationState) = 0xE;
            D_008873EC[0]((void *)((McScreenState *)work)->saveBuffer);
            break;
        default:
read_failed:
            func_00440b68(D_0063ED20);
            MEMBER(s32, work, McScreenState, operationState) = 0xC;
            D_008873EC[0]((void *)((McScreenState *)work)->saveBuffer);
            break;
        }
        break;
    case 20:
        MEMBER(s32, work, McScreenState, operationState) = 0x15;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0xD);
        /* fallthrough */
    case 21:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        if (status != 0) {
            return 1;
        }
        break;
    case 22:
        MEMBER(s32, work, McScreenState, operationState) = 0x17;
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0x14);
        H_Memcard_SetAbort();
        /* fallthrough */
    case 23:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        if (status != 0) {
            MEMBER(s32, work, McScreenState, operationState) = 0xC;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -2:
        case 3:
            MEMBER(s32, work, McScreenState, operationState) = 0xC;
            break;
        }
        break;
    case 12:
        MEMBER(s32, work, McScreenState, operationState) = 0xD;
        H_Memcard_SetAbort();
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0xE);
        /* fallthrough */
    case 13:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        if (status != 0) {
            return 4;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -2:
        case 3:
            func_00440b68(D_0063EC30, status);
            return 4;
        }
        break;
    case 14:
        MEMBER(s32, work, McScreenState, operationState) = 0xF;
        H_Memcard_SetAbort();
        if (((McScreenState *)work)->window != 0) {
            shdWindowMarkDone((u8 *)(((McScreenState *)work)->window));
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        MEMBER(s32, work, McScreenState, window) = shdWindowTaskCreate(0, 0, 0x16);
        /* fallthrough */
    case 15:
        status = shdWindowQueryState((u8 *)(((McScreenState *)work)->window));
        if (status != 0) {
            MEMBER(s32, work, McScreenState, window) = 0;
        }
        if (status != 0) {
            return 4;
        }
        status = H_Memcard_CheckCard();
        switch (status) {
        case -2:
        case 3:
            func_00440b68(D_0063EC30, status);
            return 4;
        }
        break;
    }
    return 0;
}

/* Update selection from list input, arm the movement pulse, and refresh end-of-list flags. */
// FUN_002A4390
s32 mcUpdateCardStatus(s32 workAddress) {
    u8 buf[0x30];
    McScreenState *work = (McScreenState *)workAddress;
    s32 inputResult;

    sdkListStateConfigure(buf, 0x10, 0x10, work->slot, work->scroll);
    sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
    sdkListStateSetReservedRows(buf, 0);
    sdkListStateSetRefresh(buf, 0);
    inputResult = sdkListStateHandleInput(buf);
    switch (inputResult) {
    case 1:
    case 3:
        work->flags |= 0x2000;
        work->selectionPulse = 0xA;
        sdkSndStartStream(0, 0, 0, 0);
        break;
    case 2:
    case 4:
        work->flags |= 0x1000;
        work->selectionPulse = 0xA;
        sdkSndStartStream(0, 0, 0, 0);
        break;
    default:
        sdkListStateSetActive(buf, 0);
        break;
    }
    work->slot = sdkListStateGetCursor(buf);
    work->scroll = sdkListStateGetScroll(buf);
    if (work->slot == 0) {
        work->flags &= ~0x4000;
    } else {
        work->flags |= 0x4000;
    }
    if (work->slot == 0xF) {
        work->flags &= ~0x8000;
    } else {
        work->flags |= 0x8000;
    }
    work->flags |= 0x80000;
    return 0;
}

/* Drive card operations and user selection, returning nonzero when the screen exits. */
// FUN_002A4570
s32 mcStepState(u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 value;
    s32 result;

    result = 0;
    switch (((McScreenState *)work)->interactionPhase) {
    case 1:
        ((McScreenState *)work)->flags |= 0x40000;
        result = 1;
        goto return_result;
    case 0:
        screenState->interactionPhase = 2;
        goto return_zero;
    case 2:
        screenState->interactionPhase = 3;
        mcSetState(work, 0);
        /* fallthrough */
    case 3:
        result = 0;
        value = ((McScreenState *)work)->operation;
        switch (value) {
        case 0:
            result = mcLoadState(work);
            break;
        case 1:
            result = mcCardProbeStep(work);
            break;
        case 2:
            result = mcMemcardStep(work);
            break;
        case 3:
            result = mcSaveState((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            screenState->interactionPhase = 4;
            break;
        case 3:
            screenState->interactionPhase = 2;
            break;
        case 4:
            screenState->interactionPhase = 1;
            break;
        default:
            break;
        }
        goto return_zero;
    case 4:
        screenState->interactionPhase = 5;
        /* fallthrough */
    case 5:
        screenState->interactionPhase = 6;
        H_Memcard_SetAbort();
        /* fallthrough */
    case 6:
        mcUpdateCardStatus((s32)work);
        if (D_008C024E[0] & 0x40) {
            if (((McScreenState *)work)->flags & 2) {
                screenState->interactionPhase = 7;
                sdkSndStartStream(0, 0, 0, 1);
            } else if (mcCurrentSlotValue(work) == 1) {
                screenState->interactionPhase = 0xC;
                sdkSndStartStream(0, 0, 0, 1);
            } else {
                sdkSndStartStream(0, 0, 0, 8);
            }
        } else if (D_008C024E[0] & 0x20) {
            screenState->interactionPhase = 1;
            sdkSndStartStream(0, 0, 0, 2);
            goto return_zero;
        }
        value = H_Memcard_CheckCard();
        switch (value) {
        case 100:
        case -1:
        case -2:
            break;
        case 3:
        case -4:
        case -5:
            screenState->interactionPhase = 2;
            break;
        }
        goto return_zero;
    case 7:
        screenState->interactionPhase = 8;
        mcSetState(work, 1);
        /* fallthrough */
    case 8:
        result = 0;
        value = ((McScreenState *)work)->operation;
        switch (value) {
        case 0:
            result = mcLoadState(work);
            break;
        case 1:
            result = mcCardProbeStep(work);
            break;
        case 2:
            result = mcMemcardStep(work);
            break;
        case 3:
            result = mcSaveState((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            screenState->interactionPhase = 9;
            break;
        case 4:
            screenState->interactionPhase = 2;
            break;
        }
        goto return_zero;
    case 9:
        screenState->interactionPhase = 0xB;
        mcSetState(work, 2);
        /* fallthrough */
    case 0xB:
        result = 0;
        value = ((McScreenState *)work)->operation;
        switch (value) {
        case 0:
            result = mcLoadState(work);
            break;
        case 1:
            result = mcCardProbeStep(work);
            break;
        case 2:
            result = mcMemcardStep(work);
            break;
        case 3:
            result = mcSaveState((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            D_00764634 = 1;
            screenState->interactionPhase = 1;
            ((McScreenState *)work)->flags |= 8;
            break;
        case 2:
            screenState->interactionPhase = 5;
            break;
        case 4:
            screenState->interactionPhase = 2;
            break;
        default:
            break;
        }
        goto return_zero;
    case 0xC:
        screenState->interactionPhase = 0xD;
        mcSetState(work, 3);
        /* fallthrough */
    case 0xD:
        result = 0;
        value = ((McScreenState *)work)->operation;
        switch (value) {
        case 0:
            result = mcLoadState(work);
            break;
        case 1:
            result = mcCardProbeStep(work);
            break;
        case 2:
            result = mcMemcardStep(work);
            break;
        case 3:
            result = mcSaveState((s32)work);
            break;
        default:
            break;
        }
        switch (result) {
        case 1:
            D_00764634 = 1;
            screenState->interactionPhase = 1;
            break;
        case 2:
            screenState->interactionPhase = 5;
            break;
        case 4:
            screenState->interactionPhase = 2;
            break;
        default:
            break;
        }
        goto return_zero;
    default:
        goto return_zero;
    }
return_zero:
    result = 0;
return_result:
    return result;
}
/* Load screen resources, run card interaction, and enqueue drawing until teardown. */
// FUN_002A4B10
s32 mcIconTaskUpdate(u8 *sdkTaskBytes) {
    s32 taskAddress = (s32)sdkTaskBytes;
    u8 *work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);

    switch (((McScreenState *)work)->phase) {
    case 0:
        ((McScreenState *)work)->phase = 3;
        /* fallthrough */
    case 3:
        ((McScreenState *)work)->phase = 4;
        ((McScreenState *)work)->spritePack = sdkSpritePackCreate(D_0063EB20);
        func_00440b68(&D_00763900, &D_007638F8, 0x47E);
        ((McScreenState *)work)->directory = H_Cdvd_AcquireDirectory(D_0063ED38, 1);
        ((McScreenState *)work)->frame = 0;
        ((McScreenState *)work)->flags |= 0x400;
        /* fallthrough */
    case 4:
        if (shdSpriteEnsureLoaded(((McScreenState *)work)->spritePack) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded((struct HCdvd *)((McScreenState *)work)->directory) == 0) {
            break;
        }
        ((McScreenState *)work)->phase = 5;
        ((McScreenState *)work)->flags |= 1;
        break;
    case 5:
        if (((McScreenState *)work)->flags & 0x400) {
            break;
        }
        resrcMngSetRenderSuppressed(1);
        ((McScreenState *)work)->phase = 6;
        /* fallthrough */
    case 6:
        if (mcStepState(work) == 0) {
            break;
        }
        resrcMngSetRenderSuppressed(0);
        ((McScreenState *)work)->phase = 7;
        break;
    case 7:
        if (((McScreenState *)work)->flags & 0x40000) {
            break;
        }
        ((McScreenState *)work)->phase = 8;
        /* fallthrough */
    case 8:
        return -1;
    }
    mcQueueDrawJob(taskAddress);
    return 0;
}

/* The teardown callback receives the task, not its work allocation. */
// FUN_002A4CB0
void mcIconTaskDestroy(u8 *sdkTaskBytes) {
    s32 taskAddress = (s32)sdkTaskBytes;
    u8 *work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);
    s32 directory = ((McScreenState *)work)->directory;
    if (directory != 0) {
        H_Cdvd_Destroy((struct HCdvd *)directory);
        MEMBER(s32, work, McScreenState, directory) = 0;
    }
    sdkSpritePackDestroy(((McScreenState *)work)->spritePack);
    mcIconWorkFree(work);
}

/* Animate the two opening rectangles over twenty frames. The one-field ColorValue locals hold the
 * two source colors and their shared output. */
// FUN_002A4D10
s32 mcAnimateTransition(s32 task) {
    typedef struct { f32 value; } ColorValue;
    u8 *work;
    s32 frame;
    f32 eased;
    ColorValue outputColor;
    ColorValue firstColor;
    ColorValue secondColor;
    McRect rectangle;
    McRect first;
    McRect second;

    work = (u8 *)kwlnTaskGetWork((void *)task);
    frame = ((McScreenState *)work)->frame;
    if (frame > 20) frame = 20;
    eased = sinf((D_00761184 * (f32)frame) / 20.0f);
    firstColor.value = iGpffffa818;
    outputColor = firstColor;
    first = D_0063ED50;
    first.y = (s32)(178.0f * (1.0f - eased));
    first.height = (s32)(448.0f * eased);
    rectangle = first;
    PrimDrawFlatRectangle(&outputColor.value, &rectangle, 0.0f, 1);
    frame = MEMBER(s32, work, McScreenState, frame);
    if (frame > 5) {
        frame -= 5;
        if (frame > 15) frame = 15;
        eased = sinf((D_00761184 * (f32)frame) / 15.0f);
        secondColor.value = iGpffffa81c;
        outputColor = secondColor;
        second = D_0063ED60;
        second.y = (s32)(178.0f - (94.0f * eased) / 2.0f);
        second.height = (s32)(94.0f * eased);
        rectangle = second;
        PrimDrawFlatRectangle(&outputColor.value, &rectangle, 0.0f, 1);
    }
    frame = ++MEMBER(s32, work, McScreenState, frame);
    if (frame >= 20) {
        MEMBER(s32, work, McScreenState, frame) = 0;
        return 1;
    }
    return 0;
}

/* Slide and fade the slot list in while interpolating its 16.16 scroll position. Each slide keeps
 * its own remaining-progress value, and the pulse multiply stays separate from scale. */
// FUN_002A4F20
s32 mcRunScreenFrame(s32 taskAddress)
{
    extern f32 iGpffff8084;
    u8 *work;
    s32 alpha;
    s32 row;
    s32 idx;
    s32 slot;
    s32 base;
    s32 target;
    s32 diff;
    s32 rest;
    s32 frame;
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 wave;
    f32 slide;
    f32 scale;
    f32 ramp;
    f32 pulse;
    f32 fdiff;
    f32 half;

    work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);
    mcDrawFadedColor(0, 0, 255, work);
    mcSeedEntryTable(255, work);
    frame = ((McScreenState *)work)->frame;
    if (frame < 10) {
        ramp = (f32)frame / 10.0f;
    } else {
        ramp = 1.0f;
    }
    alpha = (s32)(255.0f * ramp);
    mcDrawGlyph(0, 0, alpha, work);
    mcAdvanceMeter(0, 0, alpha, work);
    wave = sinf((D_00761184 * (f32)MEMBER(s32, work, McScreenState, frame)) / 30.0f);
    target = (s32)((u32)((McScreenState *)work)->slot << 16);
    if (((McScreenState *)work)->scrollPosition != target) {
        diff = target - ((McScreenState *)work)->scrollPosition;
        if ((f32)func_0043c6a0(diff) <= iGpffff8214 * (f32)target) {
            MEMBER(s32, work, McScreenState, scrollPosition) = target;
        } else {
            fdiff = (f32)diff;
            if (iGpffff8218 * fdiff < iGpffff821c) {
                half = 0.5f;
                rest = (s32)(fdiff * half);
            } else {
                rest = (s32)(iGpffff8218 * fdiff);
            }
            MEMBER(s32, work, McScreenState, scrollPosition) = MEMBER(s32, work, McScreenState, scrollPosition) + rest;
        }
    }
    base = MEMBER(s32, work, McScreenState, scrollPosition) >> 16;
    idx = 0;
    row = (s32)((u32)base << 16);
    {
        f32 remaining = 1.0f;
        remaining -= wave;
        slide = 350.0f * remaining;
    }
    while (idx < 7) {
        slot = base + idx - 3;
        if (slot >= 0 && slot < 16 && ((idx != 0 && idx != 6) || (u16)MEMBER(s32, work, McScreenState, scrollPosition) != 0)) {
            mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 5.0f);
            mcSetSkyRenderState(0, 0, 0x280, 0x2D, 0.0f);
            mcSetSkyRenderState(0, 0x195, 0x280, 0x30, 0.0f);
            diff = row - MEMBER(s32, work, McScreenState, scrollPosition);
            x = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
            y = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
            mcDrawSlotDial(x - slide, y, 0.0f, 0xFF, work + 0x14, slot, 0, 1.0f, work);
            mcScreenStep(x, y, 5.0f, alpha, work + 0x14, slot, 0, work);
        }
        idx++;
    }
    shdSpriteDrawNow(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, (u8 *)((McScreenState *)work)->spritePack, 1);
    idx = 0;
    while (idx < 7) {
        slot = base + idx - 3;
        if (slot >= 0 && slot < 16) {
            diff = row - MEMBER(s32, work, McScreenState, scrollPosition);
            x2 = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
            y2 = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
            if (slot == base || slot == base + 1) {
                mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
                mcSetSkyRenderState(0, 0x83, 0x280, 0x5E, 10.0f);
                mcScreenStep(x2, y2, 5.0f, alpha, work + 0x14, slot, 1, work);
            }
        }
        idx++;
    }
    if (MEMBER(s32, work, McScreenState, slot) + 1 != 0) {
        mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
        diff = ((McScreenState *)work)->selectionPulse;
        if (diff > 0) {
            MEMBER(s32, work, McScreenState, selectionPulse) = diff - 1;
        }
        pulse = iGpffff8030 * sinf(iGpffff8084 * (f32)MEMBER(s32, work, McScreenState, selectionPulse) / 10.0f);
        scale = 1.0f + pulse;
        {
            f32 remaining = 1.0f;
            remaining -= wave;
            slide = 400.0f * remaining;
        }
        mcDrawCircleFan(72.0f - slide, 179.0f, 0.0f, 0x2D2D2D, 0xFF, 124.0f * scale, 116.0f * scale, 1);
        mcDrawSlotDial(19.0f - slide, 130.0f, 0.0f, 0xFF, work + 0x14, MEMBER(s32, work, McScreenState, slot), 1, scale, work);
    }
    frame = MEMBER(s32, work, McScreenState, frame) + 1;
    MEMBER(s32, work, McScreenState, frame) = frame;
    if (frame >= 30) {
        MEMBER(s32, work, McScreenState, frame) = 0;
        return 1;
    }
    return 0;
}

/* Fade screen components out and slide the selected slot offscreen. Each ramp phase keeps its own
 * float local, and fade (phase-3 alpha) stays separate from alpha (phase-5 value) to keep retail's
 * register allocation. */
// FUN_002A5630
s32 mcRunScreenExitFrame(s32 taskAddress)
{
    extern f32 iGpffff8084;
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    u8 *work;
    s32 alpha;
    s32 row;
    s32 idx;
    s32 slot;
    s32 base;
    s32 fade;
    s32 target;
    s32 diff;
    s32 rest;
    s32 frame;
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 wave;
    f32 slide;
    f32 scale;
    f32 ramp;
    f32 ramp1;
    f32 ramp2;
    f32 ramp3;
    f32 pulse;
    f32 fdiff;
    f32 half;

    work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);
    frame = ((McScreenState *)work)->frame;
    if (frame > 10) {
        if (frame < 30) {
            ramp1 = (f32)(frame - 10) / 20.0f;
        } else {
            ramp1 = 1.0f;
        }
    } else {
        ramp1 = 0.0f;
    }
    mcDrawFadedColor(0, 0, (s32)(255.0f * (1.0f - ramp1)), work);
    frame = MEMBER(s32, work, McScreenState, frame);
    if (frame < 10) {
        ramp2 = (f32)frame / 10.0f;
    } else {
        ramp2 = 1.0f;
    }
    mcSeedEntryTable((s32)(255.0f * (1.0f - ramp2)), work);
    frame = MEMBER(s32, work, McScreenState, frame);
    if (frame < 10) {
        ramp3 = (f32)frame / 10.0f;
    } else {
        ramp3 = 1.0f;
    }
    fade = (s32)(255.0f * (1.0f - ramp3));
    mcDrawGlyph(0, 0, fade, work);
    mcAdvanceMeter(0, 0, fade, work);
    frame = MEMBER(s32, work, McScreenState, frame);
    if (frame < 10) {
        ramp = (f32)frame / 10.0f;
    } else {
        ramp = 1.0f;
    }
    wave = sinf(D_00761184 * ramp);
    frame = MEMBER(s32, work, McScreenState, frame);
    if (frame < 2) {
        alpha = (s32)(255.0f * (1.0f - sinf(D_00761184 * ((f32)frame / 2.0f))));
    } else {
        alpha = 0;
    }
    if (ramp < 1.0f) {
        target = ((McScreenState *)work)->slot << 16;
        if (((McScreenState *)work)->scrollPosition != target) {
            diff = target - ((McScreenState *)work)->scrollPosition;
            if ((f32)func_0043c6a0(diff) <= iGpffff8214 * (f32)target) {
                MEMBER(s32, work, McScreenState, scrollPosition) = target;
            } else {
                fdiff = (f32)diff;
                if (iGpffff8218 * fdiff < iGpffff821c) {
                    half = 0.5f;
                    rest = (s32)(fdiff * half);
                } else {
                    rest = (s32)(iGpffff8218 * fdiff);
                }
                MEMBER(s32, work, McScreenState, scrollPosition) = MEMBER(s32, work, McScreenState, scrollPosition) + rest;
            }
        }
        base = MEMBER(s32, work, McScreenState, scrollPosition) >> 16;
        idx = 0;
        row = base << 16;
        slide = 400.0f * wave;
        while (idx < 7) {
            slot = base + idx - 3;
            if (slot >= 0 && slot < 16 && ((idx != 0 && idx != 6) || (u16)MEMBER(s32, work, McScreenState, scrollPosition) != 0)) {
                mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 5.0f);
                mcSetSkyRenderState(0, 0, 0x280, 0x2D, 0.0f);
                mcSetSkyRenderState(0, 0x195, 0x280, 0x30, 0.0f);
                diff = row - MEMBER(s32, work, McScreenState, scrollPosition);
                x = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
                y = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
                mcDrawSlotDial(x - slide, y, 0.0f, 0xFF, work + 0x14, slot, 0, 1.0f, work);
                mcScreenStep(x, y, 5.0f, alpha, work + 0x14, slot, 0, work);
            }
            idx++;
        }
        shdSpriteDrawNowEx(0.0f, 131.0f + 47.0f * wave, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, (u8 *)((McScreenState *)work)->spritePack, 1, 0, 0, 0.0f, 1.0f, 1.0f - wave);
        idx = 0;
        while (idx < 6) {
            slot = base + idx - 3;
            if (slot >= 0 && slot < 16) {
                diff = row - MEMBER(s32, work, McScreenState, scrollPosition);
                x2 = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
                y2 = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
                if (slot == base || slot == base + 1) {
                    mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
                    mcSetSkyRenderState(0, 0x83, 0x280, 0x5E, 10.0f);
                    mcScreenStep(x2, y2, 5.0f, alpha, work + 0x14, slot, 1, work);
                }
            }
            idx++;
        }
        if (MEMBER(s32, work, McScreenState, slot) + 1 != 0) {
            mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
            diff = ((McScreenState *)work)->selectionPulse;
            if (diff > 0) {
                MEMBER(s32, work, McScreenState, selectionPulse) = diff - 1;
            }
            pulse = iGpffff8030 * sinf(iGpffff8084 * (f32)MEMBER(s32, work, McScreenState, selectionPulse) / 10.0f);
            scale = 1.0f + pulse;
            slide = 350.0f * wave;
            mcDrawCircleFan(72.0f - slide, 179.0f, 0.0f, 0x2D2D2D, 0xFF, 124.0f * scale, 116.0f * scale, 1);
            mcDrawSlotDial(19.0f - slide, 130.0f, 0.0f, 0xFF, work + 0x14, MEMBER(s32, work, McScreenState, slot), 1, scale, work);
        }
    }
    frame = MEMBER(s32, work, McScreenState, frame) + 1;
    MEMBER(s32, work, McScreenState, frame) = frame;
    if (frame >= 30) {
        MEMBER(s32, work, McScreenState, frame) = 0;
        return 1;
    }
    return 0;
}

#pragma push

/* Displacement from the whole row to the animated 16.16 scroll position. */

/* measured: loop-invariant extraction hoists the drawing loops' shared row origin; pulse stays
 * separate from scale so the multiply rounds before the add. */
#pragma opt_loop_invariants on
/* Draw the settled slot list and pulse the selection while smoothing scroll. */
// FUN_002A5F00
s32 mcDrawScreenSettled(s32 taskAddress)
{
    extern f32 iGpffff8084;
    u8 *work;
    s32 idx;
    s32 slot;
    s32 base;
    s32 target;
    s32 diff;
    s32 rest;
    f32 x;
    f32 y;
    f32 scale;
    f32 pulse;
    f32 fdiff;
    f32 half;

    work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);
    mcDrawFadedColor(0, 0, 255, work);
    mcSeedEntryTable(255, work);
    mcDrawGlyph(0, 0, 255, work);
    mcAdvanceMeter(0, 0, 255, work);
    target = (s32)((u32)((McScreenState *)work)->slot << 16);
    if (((McScreenState *)work)->scrollPosition != target) {
        diff = target - ((McScreenState *)work)->scrollPosition;
        if ((f32)func_0043c6a0(diff) <= iGpffff8214 * (f32)target) {
            MEMBER(s32, work, McScreenState, scrollPosition) = target;
        } else {
            fdiff = (f32)diff;
            if (iGpffff8218 * fdiff < iGpffff821c) {
                half = 0.5f;
                rest = (s32)(fdiff * half);
            } else {
                rest = (s32)(iGpffff8218 * fdiff);
            }
            MEMBER(s32, work, McScreenState, scrollPosition) = MEMBER(s32, work, McScreenState, scrollPosition) + rest;
        }
    }
    base = MEMBER(s32, work, McScreenState, scrollPosition) >> 16;
    idx = 0;
    while (idx < 7) {
        slot = base + idx - 3;
        if (slot >= 0 && slot < 16 && ((idx != 0 && idx != 6) || (u16)MEMBER(s32, work, McScreenState, scrollPosition) != 0)) {
            mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 5.0f);
            mcSetSkyRenderState(0, 0, 0x280, 0x2D, 0.0f);
            mcSetSkyRenderState(0, 0x195, 0x280, 0x30, 0.0f);
            diff = ((s32)((u32)(base) << 16) - (MEMBER(s32, work, McScreenState, scrollPosition)));
            x = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
            y = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
            mcDrawSlotDial(x, y, 0.0f, 0xFF, work + 0x14, slot, 0, 1.0f, work);
            mcScreenStep(x, y, 5.0f, 0xFF, work + 0x14, slot, 0, work);
        }
        idx++;
    }
    shdSpriteDrawNow(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, (u8 *)((McScreenState *)work)->spritePack, 1);
    idx = 0;
    while (idx < 7) {
        slot = base + idx - 3;
        if (slot >= 0 && slot < 16) {
            diff = ((s32)((u32)(base) << 16) - (MEMBER(s32, work, McScreenState, scrollPosition)));
            x = -59.0f + (f32)(idx * 26) + (f32)(diff * 26) / 65536.0f;
            y = -152.0f + (f32)(idx * 94) + (f32)(diff * 94) / 65536.0f;
            if (slot == base || slot == base + 1) {
                mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
                mcSetSkyRenderState(0, 0x83, 0x280, 0x5E, 10.0f);
                mcScreenStep(x, y, 5.0f, 0xFF, work + 0x14, slot, 1, work);
            }
        }
        idx++;
    }
    if (MEMBER(s32, work, McScreenState, slot) + 1 != 0) {
        mcSetSkyRenderState(0, 0, 0x280, 0x1C0, 0.0f);
        diff = ((McScreenState *)work)->selectionPulse;
        if (diff > 0) {
            MEMBER(s32, work, McScreenState, selectionPulse) = diff - 1;
        }
        pulse = iGpffff8030 * sinf(iGpffff8084 * (f32)MEMBER(s32, work, McScreenState, selectionPulse) / 10.0f);
        scale = 1.0f + pulse;
        mcDrawCircleFan(72.0f, 179.0f, 0.0f, 0x2D2D2D, 0xFF, 124.0f * scale, 116.0f * scale, 1);
        mcDrawSlotDial(19.0f, 130.0f, 0.0f, 0xFF, work + 0x14, MEMBER(s32, work, McScreenState, slot), 1, scale, work);
    }
    mcDrawCardStatusPulse(5, -5, 0xFF, work);
    return 1;
}
#pragma pop

/* Select opening, steady, or closing drawing from the screen flags. */
// FUN_002A6510
s32 mcDrawDispatch(s32 taskAddress) {
    u8 *work = (u8 *)(uintptr_t)kwlnTaskGetWork((void *)(uintptr_t)(u32)taskAddress);
    s32 flags = ((McScreenState *)work)->flags;

    if (!(flags & 1)) {
        return 0;
    }
    if (flags & 0x400) {
        if (mcAnimateTransition(taskAddress) != 0) {
            ((McScreenState *)work)->flags &= ~0x400;
            ((McScreenState *)work)->flags |= 0x20000;
        }
        return 0;
    }
    if (flags & 0x20000) {
        if (mcRunScreenFrame(taskAddress) != 0) {
            MEMBER(u32, work, McScreenState, flags) &= ~0x20000;
        }
        return 0;
    }
    if (flags & 0x40000) {
        if (mcRunScreenExitFrame(taskAddress) != 0) {
            MEMBER(u32, work, McScreenState, flags) &= ~0x40000;
        }
        return 0;
    }
    mcDrawScreenSettled(taskAddress);
    return 0;
}

/* Queue the draw callback with the owning task as its payload. */
// FUN_002A6680
void mcQueueDrawJob(s32 taskAddress) {
    u8 *work = PrimAllocQueueNode();
    ((PrimQueueNode *)work)->callback = mcDrawDispatchCallback;
    ((PrimQueueNode *)work)->argument.data = (u8 *)taskAddress;
    PrimAppendNode(&D_00796370, work);
}

// Draws a ring of 40 segments around a centre as a fan, or a 40-point strip when bit 4 of the flags
// is set.
// FUN_002A66D0
void mcDrawCircleFan(f32 centerX, f32 centerY, f32 depth, s32 rgb, s32 alpha,
                   f32 width, f32 height, s32 flags) {
    typedef struct { f32 a, b; } V2;
    void *setState;
    V2 points[0x29];
    u8 colors[0x29][4];
    s32 i;
    s32 rgba;
    s32 red, green, blue, opacity;
    f32 radiusX, radiusY;
    f32 angle;
    f32 *slot;
    u8 *col;

    points[0].a = centerX;
    points[0].b = centerY;
    rgba = (rgb << 8) | alpha;
    red = (rgba >> 24) & 0xFF;
    colors[0][0] = rgba >> 24;
    green = (rgba >> 16) & 0xFF;
    colors[0][1] = rgba >> 16;
    blue = (rgba >> 8) & 0xFF;
    colors[0][2] = rgba >> 8;
    opacity = rgba & 0xFF;
    colors[0][3] = rgba;
    i = 1;
    radiusX = width / 2.0f;
    radiusY = height / 2.0f;
    while (i < 0x28) {
        angle = iGpffff81e0 * (f32)(i - 1) / 39.0f;
        slot = &points[i].a;
        slot[0] = centerX + radiusX * cosf(angle);
        slot[1] = centerY + radiusY * -sinf(angle);
        col = &colors[i][0];
        col[0] = red;
        col[1] = green;
        col[2] = blue;
        col[3] = opacity;
        i++;
    }
    points[i] = points[1];
    colors[i][0] = red;
    colors[i][1] = green;
    colors[i][2] = blue;
    colors[i][3] = opacity;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(1, 0);
    if (alpha == 0xFF && !(flags & 2)) {
        shdEnableBlendFlag();
    }
    if (!(flags & 4)) {
        PrimDrawPoints(&colors[0][0], &points[0].a, depth, 0x29, 5, flags & 1);
    } else {
        PrimDrawPoints(&colors[1][0], &points[1].a, depth, 0x28, 2, flags & 1);
    }
    if (alpha == 0xFF && !(flags & 2)) {
        shdDisableBlendFlag();
    }
}

/* Draw the rectangular mask with Sky state and paired effect tags. */
// FUN_002A6960
void mcSetSkyRenderState(s32 x, s32 y, s32 width, s32 height, f32 depth) {
    void *setState;
    f32 color;
    f32 clearColor;
    Quad4 rectangle;
    Quad4 bounds;
    u8 *p;
    s32 n;
    u8 *p2;
    s32 n2;

    p = (u8 *)&clearColor;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    color = clearColor;
    p2 = (u8 *)&bounds;
    n2 = 0x10;
    if (p2 != NULL) {
        do {
            *p2 = 0;
            p2++;
            n2--;
        } while (n2 != 0);
    }
    bounds.a = x;
    bounds.b = y;
    bounds.c = width;
    bounds.d = height;
    rectangle = bounds;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(0xE, 0);
    (*(void (**)(u32, u32))setState)(0xC, 1);
    (*(void (**)(u32, u32))setState)(7, 2);
    (*(void (**)(u32, u32))setState)(9, 1);
    (*(void (**)(u32, u32))setState)(0x14, 1);
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&color, &rectangle, depth, 0);
    mdlEffectEmitTagPair();
}

// FUN_002A6AF0
s32 mcCurrentSlotValue(u8 *work) {
    s32 idx = ((McScreenState *)work)->slot * 4;
    return ((McScreenState *)(idx + (s32)work))->records.states[0];
}

// Sets the colour with the given alpha and draws it through PrimDrawFlatRectangle only when alpha
// is nonzero.
// FUN_002A6B10
void mcDrawFadedColor(s32 x, s32 y, s32 alpha, void *work) {
    typedef union { f32 f; u8 b[4]; } U4;
    U4 u;
    Qword q;
    U4 *pu = &u;

    pu->f = D_00763910;
    pu->b[3] = (u8)alpha;
    q = D_0063ED70;
    if (alpha != 0) {
        PrimDrawFlatRectangle(pu, &q, 0.0f, 1);
    }
}

/* Draw the mode-specific heading glyph when the screen is visible. */
// FUN_002A6B60
void mcDrawGlyph(s32 x, s32 y, s32 alpha, u8 *work) {
    if (alpha != 0) {
        if (((McScreenState *)work)->flags & 2) {
            shdSpriteDrawNow((f32)(x + 0x1C0), (f32)(y + 0xC), 0.0f, 0xFFFFFF, alpha & 0xFF, 0x3D, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
        } else {
            shdSpriteDrawNow((f32)(x + 0x19A), (f32)(y + 0xC), 0.0f, 0xFFFFFF, alpha & 0xFF, 0x39, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
        }
    }
}

/* Fade the control legends toward the refresh flag and consume that flag. */
// FUN_002A6C30
void mcAdvanceMeter(s32 x, s32 y, s32 alpha, u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 frameOrAlpha;
    f32 opacity;

    if (alpha != 0) {
        if (screenState->flags & 0x80000) {
            frameOrAlpha = screenState->legendFade;
            if (frameOrAlpha < 5) {
                ((McScreenState *)work)->legendFade = frameOrAlpha + 1;
            }
        } else {
            frameOrAlpha = screenState->legendFade;
            if (frameOrAlpha > 0) {
                ((McScreenState *)work)->legendFade = frameOrAlpha - 1;
            }
        }
        opacity = ((f32)((McScreenState *)work)->legendFade / 5.0f) * (f32)alpha;
        frameOrAlpha = (s32)opacity;
        shdSpriteDrawNow((f32)(x + 0x1F5), (f32)(y + 0x19B), 0.0f, 0xFFFFFF, frameOrAlpha, 0x24, 0, (u8 *)(screenState->spritePack), 1);
        shdSpriteDrawNow((f32)(x + 0x207), (f32)(y + 0x19D), 0.0f, 0xFFFFFF, frameOrAlpha, 0x27, 0, (u8 *)(screenState->spritePack), 1);
        shdSpriteDrawNow((f32)(x + 0x22C), (f32)(y + 0x19B), 0.0f, 0xFFFFFF, frameOrAlpha, 0x25, 0, (u8 *)(screenState->spritePack), 1);
        shdSpriteDrawNow((f32)(x + 0x23E), (f32)(y + 0x19D), 0.0f, 0xFFFFFF, frameOrAlpha, 0x28, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
        ((McScreenState *)work)->flags &= 0xFFF7FFFF;
    }
}

// Draws the card-status pulse overlay; flag 0x4000 selects the pulsing layout. The caller passes
// (5, -5, 0xFF, screen state).
// FUN_002A6E30
void mcDrawCardStatusPulse(s32 x, s32 y, s32 alpha, u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    typedef struct { s32 a, b; } I8;
    f32 remainingOrY, originX;
    f32 upperPulse, lowerPulse, lowerEaseOrX, upperEaseOrY, upperOffsetX;
    s32 v;
    s32 i;
    I8 *p6;
    I8 *p5;
    s32 n;
    f32 *q;
    f32 points[0xC];
    u8 color[4];

    if (screenState->flags & 0x4000) {
        v = screenState->upperFade;
        if (v < 0xA) {
            ((McScreenState *)work)->upperFade = v + 1;
        }
    } else {
        v = screenState->upperFade;
        if (v > 0) {
            ((McScreenState *)work)->upperFade = v - 1;
        }
    }
    if (screenState->flags & 0x8000) {
        v = screenState->lowerFade;
        if (v < 0xA) {
            ((McScreenState *)work)->lowerFade = v + 1;
        }
    } else {
        v = screenState->lowerFade;
        if (v > 0) {
            ((McScreenState *)work)->lowerFade = v - 1;
        }
    }
    upperEaseOrY = sinf(D_00761184 * (f32)((McScreenState *)work)->upperFade / 10.0f);
    lowerEaseOrX = sinf(D_00761184 * (f32)((McScreenState *)work)->lowerFade / 10.0f);
    if (screenState->flags & 0x1000) {
        ((McScreenState *)work)->upperPulse = 0xA;
        ((McScreenState *)work)->flags &= ~0x1000;
    }
    if (screenState->flags & 0x2000) {
        ((McScreenState *)work)->lowerPulse = 0xA;
        ((McScreenState *)work)->flags &= ~0x2000;
    }
    upperPulse = sinf(D_00761174 * (f32)screenState->upperPulse / 10.0f);
    lowerPulse = sinf(D_00761174 * (f32)screenState->lowerPulse / 10.0f);
    v = screenState->upperPulse;
    if (v > 0) {
        ((McScreenState *)work)->upperPulse = v - 1;
    }
    v = screenState->lowerPulse;
    if (v > 0) {
        ((McScreenState *)work)->lowerPulse = v - 1;
    }
    p6 = (I8 *)D_0063ED80;
    p5 = (I8 *)points;
    n = 6;
    do {
        v = p6->a;
        i = p6->b;
        p6++;
        n--;
        p5->a = v;
        p5->b = i;
        p5++;
    } while (n > 0);
    remainingOrY = 1.0f - upperEaseOrY;
    upperEaseOrY = -70.0f * remainingOrY;
    upperOffsetX = -30.0f * remainingOrY;
    mcDrawCircleFan((f32)(x + 0x15) + upperOffsetX, (f32)(y - 4) + upperEaseOrY, 0.0f, 0xFFAE20, alpha, 108.0f, 100.0f, 1);
    i = 0;
    originX = (f32)(x + 0xB) + upperOffsetX;
    remainingOrY = upperEaseOrY + ((f32)(y + 0x14) - 3.0f * upperPulse);
    for (; i < 3; i++) {
        q = points + i * 2;
        q[0] += originX;
        q[1] += remainingOrY;
    }
    color[0] = 0xFF;
    color[1] = 0xF2;
    color[2] = 0x3D;
    color[3] = (u8)alpha;
    PrimDrawFlatTriangle(color, points, 1, 0.0f);
    remainingOrY = 1.0f - lowerEaseOrX;
    upperEaseOrY = 70.0f * remainingOrY;
    lowerEaseOrX = 30.0f * remainingOrY;
    mcDrawCircleFan((f32)(x + 0x95) + lowerEaseOrX, (f32)(y + 0x1D1) + upperEaseOrY, 0.0f, 0xFFAE20, alpha, 108.0f, 100.0f, 1);
    i = 0;
    originX = (f32)(x + 0x83) + lowerEaseOrX;
    remainingOrY = upperEaseOrY + ((f32)(y + 0x1AB) + 3.0f * lowerPulse);
    for (; i < 3; i++) {
        q = points + i * 2;
        q[6] += originX;
        q[7] += remainingOrY;
    }
    color[0] = 0xFF;
    color[1] = 0xF2;
    color[2] = 0x3D;
    color[3] = (u8)alpha;
    PrimDrawFlatTriangle(color, &points[6], 1, 0.0f);
}

/* Claim and clear the first inactive entry in the twenty-entry effect table. */
// FUN_002A7330
s32 mcTableClear(u8 *entries) {
    s32 i = 0;
    while (i < 0x14) {
        if (!(((McCircleEntry *)entries)->flags & 1)) {
            memset(entries, 0, 0x14);
            ((McCircleEntry *)entries)->flags |= 1;
            return (s32)entries;
        }
        entries += 0x14;
        i++;
    }
    return 0;
}

/* Select the signed word indexed by a circle entry from its local lookup table. measured: retail
 * computes the table address separately from the index load at all three sites. */
static inline const s32 *mcTableAt(s32 index, const s32 *base)
{
    return base + index;
}

/* Advance a drifting circle, fading its ends and spawning a delayed successor. */
// FUN_002A73C0
s32 mcTableRandomize(s32 screenAddress, u8 *entries, u8 *entry, s32 alpha) {
    typedef struct { s32 a, b; } I8;
    s32 widths[8];
    s32 durations[8];
    u8 *work;
    u8 *rec;
    I8 *src;
    I8 *dst;
    s32 n;
    s32 v;
    s32 i;
    s32 scale;
    s32 total;
    s16 step;
    f32 rate;
    f32 w;
    f32 fx;
    f32 fy;
    s32 ns;
    u32 r;
    f32 rf;
    s32 tail;
    s32 idx;
    f32 cx;
    f32 cy;
    u8 *nw;

    work = entries;
    rec = entry;
    src = (I8 *)D_0063EDB0;
    dst = (I8 *)widths;
    n = 4;
    do {
        v = src->a;
        i = src->b;
        src++;
        n--;
        dst->a = v;
        dst->b = i;
        dst++;
    } while (n > 0);
    src = (I8 *)D_0063EDD0;
    dst = (I8 *)durations;
    n = 4;
    do {
        v = src->a;
        i = src->b;
        src++;
        n--;
        dst->a = v;
        dst->b = i;
        dst++;
    } while (n > 0);
    if (((McCircleEntry *)rec)->delay > 0) {
        MEMBER(s16, rec, McCircleEntry, delay) -= 1;
        return 0;
    }
    scale = (s32)((f32)(s32)((u32)alpha * 255U) / 255.0f);
    total = *mcTableAt(((McCircleEntry *)rec)->kind, durations);
    step = ((McCircleEntry *)rec)->frame;
    rate = (f32)step / (f32)total;
    if (step < 30) {
        scale = (s32)(((f32)step / 30.0f) * (f32)scale);
    } else if (total - 30 < step) {
        scale = (s32)((f32)scale * ((f32)(total - step) / 30.0f));
    }
    v = *mcTableAt(((s32 *)rec)[1], widths);
    w = 2.0f * (f32)v;
    fx = ((McCircleEntry *)rec)->x.value - 512.0f * rate;
    fy = ((McCircleEntry *)rec)->y.value + 512.0f * rate;
    mcDrawCircleFan(fx, fy, 0.0f, 0xFFF267, scale, D_00761300 * w, w, 1);
    MEMBER(s16, rec, McCircleEntry, frame) += 1;
    total = *mcTableAt(MEMBER(s32, rec, McCircleEntry, kind), durations);
    ns = MEMBER(s16, rec, McCircleEntry, frame);
    if (ns >= total) {
        MEMBER(s16, rec, McCircleEntry, frame) = 0;
        return 1;
    }
    if ((s32)ns == (total >> 2) * 3) {
        r = RpRandom();
        rf = (f32)r;
        rf = 10.0f * (rf / 2147483648.0f);
        tail = (s32)(u32)rf + 30;
        idx = MEMBER(s32, rec, McCircleEntry, kind);
        cy = MEMBER(f32, rec, McCircleEntry, y.value);
        cx = MEMBER(f32, rec, McCircleEntry, x.value);
        nw = (u8 *)mcTableClear(work);
        if (nw != 0) {
            ((McCircleEntry *)nw)->kind = idx;
            ((McCircleEntry *)nw)->x.value = cx;
            ((McCircleEntry *)nw)->y.value = cy;
            ((McCircleEntry *)nw)->delay = (s16)tail;
        }
    }
    return 0;
}
/* Advance visible circle effects and seed six fixed kinds when the pool is empty. */
// FUN_002A7710
void mcSeedEntryTable(s32 alpha, u8 *screen) {
    s32 i;
    u8 *work;
    u8 *p;
    u8 *q;

    work = screen + 0x3D4;
    if (alpha != 0) {
        p = work;
        for (i = 0; i < 0x14; i++) {
            if ((((McCircleEntry *)p)->flags & 1) && mcTableRandomize((s32)screen, work, p, alpha) != 0) {
                memset(p, 0, 0x14);
            }
            p += 0x14;
        }
        if (MEMBER(u32, work, McCirclePool, seeded) == 0) {
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 0;
                ((McCircleEntry *)q)->x.value = (f32)0x329;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 5;
            }
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 1;
                ((McCircleEntry *)q)->x.value = (f32)0x265;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 0x64;
            }
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 2;
                ((McCircleEntry *)q)->x.bits = 0x440E0000;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 0x96;
            }
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 4;
                ((McCircleEntry *)q)->x.bits = 0x43B40000;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 0x82;
            }
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 6;
                ((McCircleEntry *)q)->x.bits = 0x43360000;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 0x50;
            }
            q = (u8 *)mcTableClear(work);
            if (q != NULL) {
                ((McCircleEntry *)q)->kind = 7;
                ((McCircleEntry *)q)->x.bits = 0x42FC0000;
                ((McCircleEntry *)q)->y.bits = 0;
                ((McCircleEntry *)q)->delay = 0;
            }
            ((McCirclePool *)work)->seeded += 1;
        }
    }
}

/* measured: extracts unsigned RGB from the slot color by dropping the low alpha byte; inlining it
 * at the call sites changes retail load order. */
static inline u32 mcUnsignedColorRgb(const u32 *rgba)
{
    return *rgba >> 8;
}
/* Draws one card-slot dial; when active is set it draws the slot-index digit glyphs and the card
 * status. The number and optional icon have separate coordinates and RGB values. Border alpha is
 * full-width, but sprite interfaces use only its low byte. */
// FUN_002A7920
void mcDrawSlotDial(f32 x, f32 y, f32 depth, s32 alpha, u8 *records, s32 slotIndex, s32 active, f32 scale, u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    extern f32 D_00761184;
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    struct { u8 r, g, b, glyphOrRgb; } color;
    Quad4 rectangle;
    f32 borderDepth;
    f32 centerY;
    f32 centerX;
    f32 fillDepth;
    f32 heightOrY;
    f32 widthOrX;
    f32 narrowDigitDepth;
    f32 wideDigitDepth;
    f32 inactiveNarrowDepth;
    f32 inactiveWideDepth;
    f32 ret;
    f32 tmp;
    s32 dialWidth;
    s32 dialHeight;
    u8 c0;
    u8 c1;
    u32 col;
    u32 colHi;
    s32 slotNumber;
    s32 glyphOrRgb;
    u8 *record;
    u8 *p;
    s32 n;
    void *setState;
    s32 t;

    if (((McRecordTable *)records)->states[slotIndex] == 1) {
        record = (u8 *)(records + (slotIndex * 0x34) + 0x40);
    } else {
        record = NULL;
    }
    if (active != 0) {
        if ((record != NULL) && (((McSaveRecord *)record)->special != 0)) {
            ((McScreenState *)work)->flags |= 0x10000;
        } else {
            ((McScreenState *)work)->flags &= 0xFFFEFFFF;
        }
        dialWidth = 0x7E;
        dialHeight = 0x76;
        if ((s32)(screenState->flags) & 0x10000) {
            t = ((McScreenState *)work)->iconFade;
            if (t < 5) {
                screenState->iconFade = t + 1;
            }
        } else {
            t = ((McScreenState *)work)->iconFade;
            if (t > 0) {
                screenState->iconFade = t - 1;
            }
        }
        ret = sinf((D_00761184 * (f32) screenState->iconFade) / 5.0f);
        tmp = 0.0f + 1.0f * 233.0f + -76.0f * ret;
        c0 = (u8)tmp;
        colHi = ((c0 & 0xFF) << 0x10) | 0xFF000000;
        tmp = 0.0f + 1.0f * 44.0f + 113.0f * ret;
        c1 = (u8)tmp;
        col = ((u8)alpha & 0xFF) | (colHi | ((c1 & 0xFF) << 8));
    } else {
        col = ((u8)alpha & 0xFF) | 0xFFAE2000;
        dialWidth = 0x6A;
        dialHeight = 0x62;
    }
    mdlEffectEmitMaskedTagPair();
    setState = (void *)D_00887300;
    (*(void (**)(s32, s32))setState)(6, 0);
    (*(void (**)(s32, s32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x5000D);
    RpSkyRenderStateSet(2, 0x44);
    heightOrY = (f32) dialHeight * scale;
    widthOrX = (f32) dialWidth * scale;
    borderDepth = 9.0f + depth;
    centerY = 49.0f + y;
    centerX = 53.0f + x;
    mcDrawCircleFan(centerX, centerY, borderDepth, 0xFFFFFF, 1, 2.0f + widthOrX, 2.0f + heightOrY, 2);
    mcDrawCircleFan(centerX, centerY, borderDepth, 0xFFFFFF, alpha, widthOrX, heightOrY, 4);
    fillDepth = 10.0f + depth;
    mcDrawCircleFan(centerX, centerY, fillDepth, 0xFFFFFF, alpha, widthOrX, heightOrY, 2);
    if (active != 0) {
        (*(void (**)(s32, s32))setState)(7, 2);
        (*(void (**)(s32, s32))setState)(9, 2);
        (*(void (**)(s32, s32))setState)(6, 1);
        (*(void (**)(s32, s32))setState)(8, 1);
        (*(void (**)(s32, s32))setState)(0xC, 1);
        (*(void (**)(s32, s32))setState)(0xB, 6);
        (*(void (**)(s32, s32))setState)(0xA, 5);
        (*(void (**)(s32, s32))setState)(2, 4);
        (*(void (**)(s32, s32))setState)(0xE, 0);
        RpSkyRenderStateSet(3, 0x50009);
        RpSkyRenderStateSet(2, 0x44);
        slotNumber = slotIndex + 1;
        if (slotNumber < 0xA) {
            if (slotNumber < 0xA) {
                shdSpriteDrawNowEx(0.0f + 1.0f * centerX - 53.0f * scale, 0.0f + 1.0f * centerY - 21.0f * scale, borderDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
            } else if (slotNumber < 0x14) {
                u32 digitRgb;
                glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
                digitRgb = (*(&col) >> 8);
                narrowDigitDepth = operandOrderAddLoaded(&depth, 9.0f);
                tmp = 21.0f * scale;
                heightOrY = operandOrderAddLoaded(&y, 49.0f);
                heightOrY -= tmp;
                tmp = 53.0f * scale;
                widthOrX = operandOrderAddLoaded(&x, 53.0f);
                widthOrX -= tmp;
                shdSpriteDrawNowEx(widthOrX, heightOrY, narrowDigitDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
                tmp = 40.0f * scale;
                shdSpriteDrawNowEx(widthOrX + tmp, heightOrY, narrowDigitDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, (s16)operandOrderSubtract(0.0f, tmp), 0, 30.0f, scale, scale);
            }
        } else if (slotNumber < 0xA) {
            shdSpriteDrawNowEx(0.0f + 1.0f * centerX - 70.0f * scale, 0.0f + 1.0f * centerY - 32.0f * scale, borderDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
        } else if (slotNumber < 0x14) {
            u32 digitRgb;
            glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
            digitRgb = (*(&col) >> 8);
            wideDigitDepth = operandOrderAddLoaded(&depth, 9.0f);
            tmp = 32.0f * scale;
            heightOrY = operandOrderAddLoaded(&y, 49.0f);
            heightOrY -= tmp;
            tmp = 70.0f * scale;
            widthOrX = operandOrderAddLoaded(&x, 53.0f);
            widthOrX -= tmp;
            shdSpriteDrawNowEx(widthOrX, heightOrY, wideDigitDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
            tmp = 40.0f * scale;
            shdSpriteDrawNowEx(widthOrX + tmp, heightOrY, wideDigitDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, (s16)operandOrderSubtract(0.0f, tmp), 0, 30.0f, scale, scale);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        slotNumber = slotIndex + 1;
        if (slotNumber < 0xA) {
            if (slotNumber < 0xA) {
                shdSpriteDrawNowEx(0.0f + 1.0f * centerX - 53.0f * scale, 0.0f + 1.0f * centerY - 21.0f * scale, fillDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
            } else if (slotNumber < 0x14) {
                u32 digitRgb;
                glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
                digitRgb = (*(&col) >> 8);
                narrowDigitDepth = operandOrderAddLoaded(&depth, 10.0f);
                tmp = 21.0f * scale;
                heightOrY = operandOrderAddLoaded(&y, 49.0f);
                heightOrY -= tmp;
                tmp = 53.0f * scale;
                widthOrX = operandOrderAddLoaded(&x, 53.0f);
                widthOrX -= tmp;
                shdSpriteDrawNowEx(widthOrX, heightOrY, narrowDigitDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
                tmp = 40.0f * scale;
                shdSpriteDrawNowEx(widthOrX + tmp, heightOrY, narrowDigitDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, (s16)operandOrderSubtract(0.0f, tmp), 0, 30.0f, scale, scale);
            }
        } else if (slotNumber < 0xA) {
            shdSpriteDrawNowEx(0.0f + 1.0f * centerX - 70.0f * scale, 0.0f + 1.0f * centerY - 32.0f * scale, fillDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
        } else if (slotNumber < 0x14) {
            u32 digitRgb;
            glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
            digitRgb = (*(&col) >> 8);
            wideDigitDepth = operandOrderAddLoaded(&depth, 10.0f);
            tmp = 32.0f * scale;
            heightOrY = operandOrderAddLoaded(&y, 49.0f);
            heightOrY -= tmp;
            tmp = 70.0f * scale;
            widthOrX = operandOrderAddLoaded(&x, 53.0f);
            widthOrX -= tmp;
            shdSpriteDrawNowEx(widthOrX, heightOrY, wideDigitDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, scale, scale);
            tmp = 40.0f * scale;
            shdSpriteDrawNowEx(widthOrX + tmp, heightOrY, wideDigitDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, (s16)operandOrderSubtract(0.0f, tmp), 0, 30.0f, scale, scale);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        glyphOrRgb = mcUnsignedColorRgb(&col);
        shdSpriteDrawNowEx(0.0f + 1.0f * centerX - 51.0f * scale, 0.0f + 1.0f * centerY - 35.0f * scale, borderDepth, glyphOrRgb, alpha, 0x20, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 0.0f, scale, scale);
        if ((record != NULL) && (((McSaveRecord *)record)->special != 0)) {
            u32 iconRgb;
            f32 iconY;
            f32 iconX;
            RpSkyRenderStateSet(3, 0x50009);
            RpSkyRenderStateSet(2, 0x44);
            iconRgb = col >> 8;
            tmp = 53.0f * scale;
            iconY = operandOrderAddLoaded(&y, 49.0f);
            iconY -= tmp;
            tmp = 11.0f * scale;
            iconX = operandOrderAddLoaded(&x, 53.0f);
            iconX -= tmp;
            shdSpriteDrawNowEx(iconX, iconY, borderDepth, iconRgb, alpha, 0x3E, 0, (u8 *)(screenState->spritePack), 0, 0, 0, 0.0f, scale, scale);
            RpSkyRenderStateSet(3, 0x50805);
            RpSkyRenderStateSet(2, 0x44);
            shdSpriteDrawNowEx(iconX, iconY, fillDepth, iconRgb, alpha, 0x3E, 0, (u8 *)(screenState->spritePack), 0, 0, 0, 0.0f, scale, scale);
        }
    } else {
        (*(void (**)(s32, s32))setState)(7, 2);
        (*(void (**)(s32, s32))setState)(9, 2);
        (*(void (**)(s32, s32))setState)(6, 1);
        (*(void (**)(s32, s32))setState)(8, 1);
        (*(void (**)(s32, s32))setState)(0xC, 1);
        (*(void (**)(s32, s32))setState)(0xB, 6);
        (*(void (**)(s32, s32))setState)(0xA, 5);
        (*(void (**)(s32, s32))setState)(2, 4);
        (*(void (**)(s32, s32))setState)(0xE, 0);
        RpSkyRenderStateSet(3, 0x50009);
        RpSkyRenderStateSet(2, 0x44);
        slotNumber = slotIndex + 1;
        if (slotNumber < 0xA) {
            if (slotNumber < 0xA) {
                shdSpriteDrawNowEx(14.0f + x, 33.0f + y, borderDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
            } else if (slotNumber < 0x14) {
                u32 digitRgb;
                glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
                digitRgb = (*(&col) >> 8);
                inactiveNarrowDepth = operandOrderAddLoaded(&depth, 9.0f);
                centerY = 33.0f + y;
                centerX = 14.0f + x;
                shdSpriteDrawNowEx(centerX, centerY, inactiveNarrowDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
                shdSpriteDrawNowEx(operandOrderAddFloat(centerX, 40.0f), centerY, inactiveNarrowDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
            }
        } else if (slotNumber < 0xA) {
            shdSpriteDrawNowEx(x - 5.0f, 22.0f + y, borderDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
        } else if (slotNumber < 0x14) {
            u32 digitRgb;
            glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
            digitRgb = (*(&col) >> 8);
            inactiveWideDepth = operandOrderAddLoaded(&depth, 9.0f);
            centerY = 22.0f + y;
            shdSpriteDrawNowEx((*(&x) - (5.0f)), centerY, inactiveWideDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
            shdSpriteDrawNowEx(operandOrderAddFloat((*(&x) - (5.0f)), 40.0f), centerY, inactiveWideDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
        }
        RpSkyRenderStateSet(3, 0x50805);
        RpSkyRenderStateSet(2, 0x44);
        slotNumber = slotIndex + 1;
        if (slotNumber < 0xA) {
            if (slotNumber < 0xA) {
                shdSpriteDrawNowEx(14.0f + x, 33.0f + y, fillDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
            } else if (slotNumber < 0x14) {
                u32 digitRgb;
                glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
                digitRgb = (*(&col) >> 8);
                inactiveNarrowDepth = operandOrderAddLoaded(&depth, 10.0f);
                centerY = 33.0f + y;
                centerX = 14.0f + x;
                shdSpriteDrawNowEx(centerX, centerY, inactiveNarrowDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
                shdSpriteDrawNowEx(operandOrderAddFloat(centerX, 40.0f), centerY, inactiveNarrowDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
            }
        } else if (slotNumber < 0xA) {
            shdSpriteDrawNowEx(x - 5.0f, 22.0f + y, fillDepth, (*(&col) >> 8), alpha, (slotNumber == 0 ? 0xA : slotNumber) + 0x2D, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
        } else if (slotNumber < 0x14) {
            u32 digitRgb;
            glyphOrRgb = (slotNumber == 0xA) ? 0xA : slotIndex - 9;
            digitRgb = (*(&col) >> 8);
            inactiveWideDepth = operandOrderAddLoaded(&depth, 10.0f);
            centerY = 22.0f + y;
            shdSpriteDrawNowEx((*(&x) - (5.0f)), centerY, inactiveWideDepth, digitRgb, alpha, 0x2E, 0, (u8 *)((McScreenState *)work)->spritePack, 0, 0, 0, 30.0f, 1.0f, 1.0f);
            shdSpriteDrawNowEx(operandOrderAddFloat((*(&x) - (5.0f)), 40.0f), centerY, inactiveWideDepth, digitRgb, alpha, glyphOrRgb + 0x2D, 0, (u8 *)(screenState->spritePack), 0, -0x28, 0, 30.0f, 1.0f, 1.0f);
        }
        glyphOrRgb = mcUnsignedColorRgb(&col);
        shdSpriteDrawNow((3.0f + ((4.0f + x) - 5.0f)) - 2.0f, 20.0f + y, borderDepth, glyphOrRgb, alpha, 0x20, 0, (u8 *)(((McScreenState *)work)->spritePack), 0);
        if ((record != NULL) && (((McSaveRecord *)record)->special != 0)) {
            u32 iconRgb;
            f32 iconY;
            f32 iconX;
            RpSkyRenderStateSet(3, 0x50009);
            RpSkyRenderStateSet(2, 0x44);
            iconRgb = col >> 8;
            iconY = 2.0f + y;
            iconX = 42.0f + x;
            shdSpriteDrawNow(iconX, iconY, borderDepth, iconRgb, alpha, 0x3E, 0, (u8 *)(screenState->spritePack), 0);
            RpSkyRenderStateSet(3, 0x50805);
            RpSkyRenderStateSet(2, 0x44);
            shdSpriteDrawNow(iconX, iconY, fillDepth, iconRgb, alpha, 0x3E, 0, (u8 *)(screenState->spritePack), 0);
        }
    }
    mdlEffectEmitTagPair();
    p = (u8 *)(&rectangle);
    n = 0x10;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            n -= 1;
        } while (n != 0);
    }
    tmp = 1.0f - scale;
    tmp = operandOrderMultiply(160.0f, tmp);
    tmp = operandOrderMultiply(0.5f, tmp);
    rectangle.a = (s32)((x - 16.0f) + tmp);
    rectangle.b = (s32)((y - 16.0f) + tmp);
    tmp = 160.0f * scale;
    rectangle.c = (s32)tmp;
    rectangle.d = (s32)tmp;
    setState = (void *)D_00887300;
    (*(void (**)(s32, s32))setState)(0xE, 0);
    (*(void (**)(s32, s32))setState)(0xC, 1);
    (*(void (**)(s32, s32))setState)(7, 2);
    (*(void (**)(s32, s32))setState)(6, 1);
    (*(void (**)(s32, s32))setState)(8, 0);
    RpSkyRenderStateSet(3, 0x3100C);
    RpSkyRenderStateSet(2, 0x54);
    color.r = (u8) (col >> 0x18);
    color.g = (s8) (col >> 0x10);
    color.b = (u8)glyphOrRgb;
    color.glyphOrRgb = (u8) col;
    PrimDrawFlatRectangle(&color, &rectangle, depth, 0);
}


/* measured: retail keeps a separate packed color local, so the common-subexpression setting below
 * is needed. */
#pragma opt_common_subs off
/* measured: retail keeps the color in a saved register and repeats the color shift instead of
 * reusing it. Draws level, character name, and hours/minutes from a selected save record. */
/* Draw a save record's level, character name and play time in hours and minutes at the given
 * position, using the given color and alpha. */
// FUN_002A9100
void mcDrawLocationText(f32 x, f32 y, f32 depth,
                   s32 rgb, s32 alpha, u8 *records, s32 slotIndex, u8 *work) {
    u8 textWork[0x60];
    s16 *levelSource;
    s16 *hourSource;
    s16 *minuteSource;
    s16 *levelDigits;
    s16 *hourDigits;
    s16 *minuteDigits;
    f32 timeY;
    f32 nameY;
    f32 nameX;
    s16 levelRight;
    s16 hourRight;
    s16 minuteRight;
    s16 levelLeft;
    s16 hourLeft;
    s16 minuteLeft;
    u8 *record;
    s32 timeRgb;
    s32 nameRgba;
    s32 levelRgb;
    s32 levelPairs;
    s32 hourPairs;
    s32 minutePairs;
    u32 hours;
    u32 minutes;
    u32 playFrames;
    u8 *spritePack;

    record = (u8 *)(records + (slotIndex * 0x34) + 0x40);
    calGetWeekdayOfDay(((McSaveRecord *)record)->day);
    playFrames = ((McSaveRecord *)record)->playFrames;
    hours = playFrames / 108000U;
    minutes = (playFrames / 1800U) % 60U;
    rgb = (rgb << 8) | alpha;
    levelRgb = rgb >> 8;
    shdSpriteDrawNow(10.0f + x, 31.0f + y, depth, levelRgb, (u8)alpha, 0x18, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
    sprintf(textWork + 0x58, &iGpffffa824, ((McSaveRecord *)record)->level);
    spritePack = (u8 *)((McScreenState *)work)->spritePack;
    levelSource = D_0063EB30;
    levelDigits = (s16 *)(textWork + 0x40);
    levelPairs = 6;
    do {
        levelLeft = levelSource[0];
        levelRight = levelSource[1];
        levelSource += 2;
        levelPairs -= 1;
        levelDigits[0] = levelLeft;
        levelDigits[1] = levelRight;
        levelDigits += 2;
    } while (levelPairs > 0);
    shdSpriteDrawNumberString(46.0f + x, 26.0f + y, depth,
                  levelRgb, (u8)alpha, textWork + 0x58, 0, textWork + 0x40,
                  yTimeDrawIndexedGlyph, spritePack);
    if ((((McRecordTable *)records)->states[slotIndex] == 1) &&
        (((McSaveRecord *)record)->special == 0 ||
         ((McSaveRecord *)record)->day != 9 ||
         ((McSaveRecord *)record)->unk02 != 5)) {
        nameRgba = rgb | alpha;
        nameY = (24.0f + y) - 6.0f;
        nameX = 99.0f + x;
        frFontExDrawTextWithCharWidth(
            5.0f + (nameX + (f32)frFontExDrawTextWithCharWidth(
                nameX, nameY, depth, nameRgba, 0, 0,
                (const char *)(record + 0x1E), 1, -1)),
            nameY, depth, nameRgba, 0, 0, (const char *)(record + 0xC), 0, -1);
    }
    timeRgb = rgb >> 8;
    shdSpriteDrawNow(16.0f + x, 53.0f + y, depth, timeRgb, (u8)alpha, 0x19, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
    sprintf(textWork + 0x58, &iGpffffa824, (s32)hours);
    spritePack = (u8 *)((McScreenState *)work)->spritePack;
    hourSource = D_0063EB30;
    hourDigits = (s16 *)(textWork + 0x20);
    hourPairs = 6;
    do {
        hourLeft = hourSource[0];
        hourRight = hourSource[1];
        hourSource += 2;
        hourPairs -= 1;
        hourDigits[0] = hourLeft;
        hourDigits[1] = hourRight;
        hourDigits += 2;
    } while (hourPairs > 0);
    timeY = 48.0f + y;
    shdSpriteDrawNumberString(36.0f + (109.0f + x), timeY, depth,
                  timeRgb, (u8)alpha, textWork + 0x58, 2, textWork + 0x20,
                  yTimeDrawIndexedGlyph, spritePack);
    shdSpriteDrawNow(177.0f + x, timeY, depth, timeRgb, (u8)alpha, 0xB, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
    sprintf(textWork + 0x58, &iGpffffa824, (s32)minutes);
    spritePack = (u8 *)((McScreenState *)work)->spritePack;
    minuteSource = D_0063EB30;
    minuteDigits = (s16 *)(textWork + 0x00);
    minutePairs = 6;
    do {
        minuteLeft = minuteSource[0];
        minuteRight = minuteSource[1];
        minuteSource += 2;
        minutePairs -= 1;
        minuteDigits[0] = minuteLeft;
        minuteDigits[1] = minuteRight;
        minuteDigits += 2;
    } while (minutePairs > 0);
    shdSpriteDrawNumberString(24.5f + (205.0f + x), timeY, depth,
                  timeRgb, (u8)alpha, textWork + 0x58, 2, textWork + 0x00,
                  yTimeDrawIndexedGlyph, spritePack);
    shdSpriteDrawNow(250.0f + x, timeY, depth, timeRgb, (u8)alpha, 0xC, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
}
#pragma opt_common_subs on

/* Packed RGBA word used by the font and sprite drawing interfaces. */
typedef struct McColorWord {
    s32 rgba;
} McColorWord;
/* measured: extracts signed RGB by dropping the low alpha byte; reading the member directly changes
 * register use in the date/header draw code. */
static inline s32 mcColorRgb(const McColorWord *color)
{
    return color->rgba >> 8;
}

/* Find the matching area and room name, falling back to the first table entry. */
static inline const char *mcLocationName(s32 area, s32 room)
{
    s32 i;
    McLocationNameEntry *table;
    i = 1;
    table = D_0063EA60;
    for (; i < 13; ++i) {
        s32 field = table[i].area;
        if (field == area) {
            field = table[i].room;
            if (field == room) {
                return table[i].name;
            }
        }
    }
    return D_0063EA60[0].name;
}
/* Draws the date (month and day, formatted with sprintf) and the current location name in the
 * header. The date record, weekday texture, and packed color are kept as separate objects. */
// FUN_002A95C0
void mcDrawDateAndLocation(f32 x, f32 y, f32 depth, s32 alpha, s32 recordAddress, s32 slotIndex, u8 *active, u8 *work)
{
    McScreenState *screenState = (McScreenState *)work;
    u8 text[8];
    s16 monthDigits[12];
    s16 dayDigits[12];
    s16 *monthSource;
    s16 *daySource;
    s16 *monthDestination;
    s16 *dayDestination;
    s16 t3a;
    s16 t2a;
    s16 t3b;
    s16 t2b;
    s32 month;
    s32 day;
    s32 weekday;
    McColorWord colorWord;
    s32 holidayColor;
    s32 colMid;
    s32 dateRgb;
    s32 detailRgb;
    s32 monthPairs;
    s32 dayPairs;
    s32 baseSpill;
    f32 tmpY2;
    f32 tmpX2;
    u8 *recordBase;
    u8 *record;
    u8 *str;
    u8 *handle;
    u8 *weekdayHandle;
    u8 mode;
    struct { u8 red, green, blue, alpha; } singleCopy, single;
    McRect rectCopy;
    McRect rect;
    u8 *p;
    s32 n;
    u8 *p2;
    s32 n2;
    void *setState;
    baseSpill = recordAddress;
    recordBase = (u8 *)(recordAddress + slotIndex * 0x34);
    record = recordBase + 0x40;
    calSplitDayOfYear(((McSaveRecord *)(recordBase + 0x40))->day, &month, &day);
    weekday = calGetWeekdayOfDay(((McSaveRecord *)record)->day);
    if (weekday < 0) {
        weekday = 6;
    }
    if (active != NULL) {
        colorWord.rgba = (alpha & 0xFF) | 0xFFE92C00;
    } else {
        colorWord.rgba = (alpha & 0xFF) | 0xFFAE2000;
    }
    if (active != NULL) {
        colMid = (alpha & 0xFF) | 0x52BDFF00;
    } else {
        colMid = (alpha & 0xFF) | 0x6984A300;
    }
    if (active != NULL) {
        holidayColor = (alpha & 0xFF) | 0xFF74AC00;
    } else {
        holidayColor = (alpha & 0xFF) | 0xDE6D9D00;
    }
    x += 107.0f;
    y += 17.0f;
    sprintf(text, &iGpffffa824, month);
    handle = (u8 *)(screenState->spritePack);
    monthSource = D_0063EB30;
    monthDestination = monthDigits;
    monthPairs = 6;
    do {
        t3a = monthSource[0];
        t2a = monthSource[1];
        monthSource += 2;
        monthPairs -= 1;
        monthDestination[0] = t3a;
        monthDestination[1] = t2a;
        monthDestination += 2;
    } while (monthPairs > 0);
    dateRgb = colorWord.rgba >> 8;
    shdSpriteDrawNumberString((x + 23.0f) - 2.0f, y - 1.0f, depth, dateRgb, (u8)alpha, text, 2, monthDigits, yTimeDrawIndexedGlyph, handle);
    shdSpriteDrawNow(x + 45.0f, y - 2.0f, depth, dateRgb, (u8)alpha, 0x4B, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
    sprintf(text, &iGpffffa824, day);
    handle = (u8 *)(screenState->spritePack);
    daySource = D_0063EB30;
    dayDestination = dayDigits;
    dayPairs = 6;
    do {
        t3b = daySource[0];
        t2b = daySource[1];
        daySource += 2;
        dayPairs -= 1;
        dayDestination[0] = t3b;
        dayDestination[1] = t2b;
        dayDestination += 2;
    } while (dayPairs > 0);
    shdSpriteDrawNumberString((x + 61.0f + 24.0f) - 2.0f, (y + 1.0f) - 2.0f, depth, dateRgb, (u8)alpha, text, 2, dayDigits, yTimeDrawIndexedGlyph, handle);
    shdSpriteDrawNow(x + 109.0f, y - 2.0f, depth, dateRgb, (u8)alpha, 0x15, 0, (u8 *)(screenState->spritePack), 1);
    if ((weekday == 0) || (calHasDayEntry(((McSaveRecord *)record)->day) != 0)) {
        weekdayHandle = (u8 *)(screenState->spritePack);
        shdSpriteDrawNow((x + 129.0f) - (f32)shdSpriteEntryWidth(0xE, weekday, weekdayHandle) / 2.0f, y - 2.0f, depth, holidayColor >> 8, (u8)alpha, 0xE, weekday, weekdayHandle, 1);
    } else if (weekday == 6) {
        weekdayHandle = (u8 *)(screenState->spritePack);
        shdSpriteDrawNow((x + 129.0f) - (f32)shdSpriteEntryWidth(0xE, weekday, weekdayHandle) / 2.0f, y - 2.0f, depth, colMid >> 8, (u8)alpha, 0xE, weekday, weekdayHandle, 1);
    } else {
        weekdayHandle = (u8 *)(screenState->spritePack);
        shdSpriteDrawNow((x + 129.0f) - (f32)shdSpriteEntryWidth(0xE, weekday, weekdayHandle) / 2.0f, y - 2.0f, depth, dateRgb, (u8)alpha, 0xE, weekday, weekdayHandle, 1);
    }
    shdSpriteDrawNow(x + 136.0f, y - 2.0f, depth, dateRgb, (u8)alpha, 0x16, 0, (u8 *)(screenState->spritePack), 1);
    str = (u8 *)mcLocationName(((McSaveRecord *)record)->area, ((McSaveRecord *)record)->room);
    frFontExDrawTextWithCharWidth(x + 151.0f, ((y - 2.0f) - 6.0f) + 2.0f, depth, colorWord.rgba | alpha, 0, 1, (const char *)str, 0, -1);
    detailRgb = mcColorRgb(&colorWord);
    mcDrawLocationText(x, y, depth, detailRgb, alpha, (u8 *)baseSpill, slotIndex, work);
    p = (u8 *)&single;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    singleCopy = single;
    p2 = (u8 *)&rect;
    n2 = 0x10;
    if (p2 != NULL) {
        do {
            *p2 = 0;
            p2++;
            n2--;
        } while (n2 != 0);
    }
    rect.x = (s32)(x - 16.0f);
    rect.y = (s32)(y - 16.0f);
    rect.width = 0x20;
    rect.height = 0x80;
    rectCopy = rect;
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(0xE, 0);
    (*(void (**)(u32, u32))setState)(0xC, 1);
    (*(void (**)(u32, u32))setState)(7, 2);
    (*(void (**)(u32, u32))setState)(9, 1);
    (*(void (**)(u32, u32))setState)(0x14, 1);
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x31003);
    RpSkyRenderStateSet(2, 0x44);
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&singleCopy, &rectCopy, 0.0f, 0);
    mdlEffectEmitTagPair();
    mdlEffectEmitMaskedTagPair();
    tmpY2 = y + 48.0f;
    tmpX2 = (f32)0x129 + x;
    shdSpriteDrawNow(tmpX2, tmpY2, depth, detailRgb, (u8)alpha, 0x1E, 0, (u8 *)(screenState->spritePack), 1);
    mode = ((McSaveRecord *)record)->mode;
    switch (mode) {
    case 0:
        shdSpriteDrawNow(tmpX2 + 11.0f, tmpY2 + 4.0f, depth, dateRgb, (u8)alpha, 0x1B, 0, (u8 *)(screenState->spritePack), 1);
        break;
    case 1:
        shdSpriteDrawNow(tmpX2 + 17.0f, tmpY2 + 4.0f, depth, dateRgb, (u8)alpha, 0x1C, 0, (u8 *)(screenState->spritePack), 1);
        break;
    default:
        shdSpriteDrawNow(tmpX2 + 21.0f, tmpY2 + 3.0f, depth, dateRgb, (u8)alpha, 0x1D, 0, (u8 *)(screenState->spritePack), 1);
        break;
    }
    mdlEffectEmitTagPair();
    setState = (void *)D_00887300;
    (*(void (**)(u32, u32))setState)(6, 0);
    (*(void (**)(u32, u32))setState)(8, 1);
    RpSkyRenderStateSet(3, 0x30003);
    RpSkyRenderStateSet(2, 0x54);
    shdSpriteDrawNow(tmpX2, tmpY2, depth, dateRgb, (u8)alpha, 0x1E, 0, (u8 *)(screenState->spritePack), 0);
}


/* Draw a valid save summary or the invalid/empty slot label. Float parameters come first so
 * retail's FP move order is reproduced; the saved-register assignment still differs from retail. */
// FUN_002A9F50
void mcScreenStep(f32 x, f32 y, f32 depth, s32 alpha, u8 *records, s32 slotIndex, s32 active, u8 *work) {
    McScreenState *screenState = (McScreenState *)work;
    s32 specialRgb;
    s32 invalidRgb;
    s32 emptyRgb;
    s32 status;
    s32 specialColor;
    s32 invalidColor;
    s32 emptyColor;
    u8 *recordBase;
    u8 *record;

    recordBase = records + (slotIndex * 0x34);
    record = recordBase + 0x40;
    status = ((McRecordTable *)records)->states[slotIndex];
    if (status == 1) {
        if (((McSaveRecord *)record)->special != 0 && ((McSaveRecord *)record)->day == 9 && ((McSaveRecord *)record)->unk02 == 5) {
            if (active != 0) {
                specialColor = (alpha & 0xFF) | 0xFFE92C00;
            } else {
                specialColor = (alpha & 0xFF) | 0xFFAE2000;
            }
            specialRgb = specialColor >> 8;
            shdSpriteDrawNow(5.0f + (113.0f + x), 10.0f + y, depth, specialRgb, (u8)alpha, 0x43, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
            mcDrawLocationText(operandOrderAddFloat(x, 107.0f), operandOrderAddFloat(y, 17.0f), depth,
                          specialRgb, alpha, (u8 *)records, slotIndex, work);
            return;
        }
        mcDrawDateAndLocation(x, y, depth, alpha, (s32)records, slotIndex, (u8 *)active, work);
        return;
    }
    if (status == 2) {
        if (active != 0) {
            invalidColor = (alpha & 0xFF) | 0xFFE92C00;
        } else {
            invalidColor = (alpha & 0xFF) | 0xFFAE2000;
        }
        invalidRgb = invalidColor >> 8;
        shdSpriteDrawNow(113.0f + x, 34.0f + y, depth, invalidRgb, (u8)alpha, 0x46, 0, (u8 *)(screenState->spritePack), 1);
        shdSpriteDrawNow(122.0f + x, 35.0f + y, depth, invalidRgb, (u8)alpha, 0x45, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
        return;
    }
    if (active != 0) {
        emptyColor = (alpha & 0xFF) | 0xFFE92C00;
    } else {
        emptyColor = (alpha & 0xFF) | 0xFFAE2000;
    }
    emptyRgb = emptyColor >> 8;
    shdSpriteDrawNow(122.0f + x, 35.0f + y, depth, emptyRgb, (u8)alpha, 0x44, 0, (u8 *)(screenState->spritePack), 1);
    shdSpriteDrawNow(184.0f + x, 36.0f + y, depth, emptyRgb, (u8)alpha, 0x45, 0, (u8 *)(((McScreenState *)work)->spritePack), 1);
}
/* Release the screen directory reference, clear its handle, then free screen work. */
// FUN_002AA2B0
void mcIconWorkFree(void *allocation) {
    McScreenState *work = allocation;
    if (work->directory != 0) {
        H_Cdvd_Destroy((struct HCdvd *)work->directory);
        work->directory = 0;
    }
    D_008873EC[0](work);
}
/* Allocate screen work, restore the remembered slot and register its update/destructor task. */
// FUN_002AA300
/* The caller retains the task handle returned by registration. */
s32 mcIconTaskCreate(u8 *parent, s32 mode) {
    u8 *work;

    D_00764634 = 0;
    chkmemAllocSiteTag(&D_007638F8, 0x8FF);
    work = D_008873F4[0](1, 0x56C, 0x40000);
    if (work == NULL) {
        kAssertFail(&D_007638F8, 0xE8);
    }
    ((McScreenState *)work)->slot = D_00764638;
    ((McScreenState *)work)->scrollPosition = D_00764638 << 16;
    ((McScreenState *)work)->phase = 0;
    ((McScreenState *)work)->interactionPhase = 0;
    if (mode == 1) {
        ((McScreenState *)work)->flags |= 2;
    }
    return (s32)kwlnTaskCreateChild(parent, (const void *)(&D_00763918), 0xF, 0, 0, mcIconTaskUpdate, mcIconTaskDestroy, work);
}
