#include "include_asm.h"
#include "type.h"
#include "cmm_internal.h"
#include "primitive_queue_internal.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern u32 kwlnTaskGetWork(void *task);
extern void sdkSpritePackDestroy(s32 pack);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;




extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *list, u8 *node);
extern s64 cmmCommunityArcana(s32 communityId);
extern s32 sdkSpritePackCreate(u8 *descriptor);
extern s32 shdSpriteEnsureLoaded(s32 pack);
extern s32 datPortraitTaskCreate(s32 parentAddress, s64 portraitId, s32 flags);
extern s32 datPortraitIsLoaded(s32 task);
extern s32 cmmRankUpCreate(s32 parentTask, s32 *context); /* lint: allow H011 -- caller stores the returned v0 at work[7] (retail keeps it); definition is void */
extern void cmmRankUpSetEntryHold(s32 taskHandle, s32 hold);
extern void cmmRankUpCopyState(s32 taskHandle, s32 kind, s32 stateIndex);
extern void kwlnTaskGetWorkCallback(s32 *input);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 002519e0-00251d30 */

// FUN_002519E0
/* Candidate reconstructed from retail dispatch and generated source. */
/* Load the rank-up card resources, wait for confirmation, then finish after the exit delay. */
s32 cmmRankUpCardTaskUpdate(u8 *sdkTaskBytes) {
    /* CmmRankUpCardTask proves these word slots; typed member access changed MWCC allocation. */
    s32 taskHandle = (s32)sdkTaskBytes;
    s32 introFrame;
    s32 holdFrame;
    s32 outroFrame;
    s32 *work;
    u8 *drawNode;

    work = (s32 *)kwlnTaskGetWork(sdkTaskBytes);
    switch (*work) {
    case 0:
        work[4] = sdkSpritePackCreate(D_00635BF0);
        work[0] = 2;
        work[5] = datPortraitTaskCreate(taskHandle, cmmCommunityArcana((u16)work[1]), 0);
        work[6] = datPortraitTaskCreate(taskHandle, -1, 0);
        work[7] = cmmRankUpCreate(taskHandle, work);
        goto block_15;
    case 1:
        return -1;
    case 2:
        if (shdSpriteEnsureLoaded(work[4]) == 0) {
            goto block_15;
        }
        if (datPortraitIsLoaded(work[5]) == 0) {
            goto block_15;
        }
        if (datPortraitIsLoaded(work[6]) == 0) {
            goto block_15;
        }
        work[0] = 3;
        cmmRankUpCopyState(work[7], 0, 4);
        cmmRankUpCopyState(work[7], 0, 5);
        cmmRankUpCopyState(work[7], 0, 6);
        cmmRankUpCopyState(work[7], 0, 7);
        cmmRankUpCopyState(work[7], 0, 8);
        cmmRankUpCopyState(work[7], 0, 9);
        cmmRankUpCopyState(work[7], 0, 0);
        cmmRankUpCopyState(work[7], 0, 1);
        cmmRankUpCopyState(work[7], 0, 2);
        cmmRankUpCopyState(work[7], 0, 3);
        cmmRankUpCopyState(work[7], 2, 0);
        cmmRankUpCopyState(work[7], 1, 0);
        goto block_15;
    case 3:
        introFrame = work[3] + 1;
        work[3] = introFrame;
        if (introFrame < 0x1E) {
            goto block_15;
        }
        work[3] = 0;
        work[0] = 4;
        cmmRankUpSetEntryHold(work[7], 1);
        goto block_15;
    case 4:
        holdFrame = work[3] + 1;
        work[3] = holdFrame;
        if (holdFrame <= 0x1E) {
            goto block_15;
        }
        if ((D_008C024E[0] & 0x40) == 0) {
            goto block_15;
        }
        cmmRankUpSetEntryHold(work[7], 0);
        work[3] = 0;
        work[0] = 5;
        goto block_15;
    case 5:
        outroFrame = work[3] + 1;
        work[3] = outroFrame;
        if (outroFrame < 0x28) {
            goto block_15;
        }
        work[0] = 1;
        goto block_15;
    default:
        goto block_15;
    }
block_15:
    drawNode = PrimAllocQueueNode();
    ((PrimQueueNode *)drawNode)->callback = (void *)kwlnTaskGetWorkCallback;
    ((PrimQueueNode *)drawNode)->argument.handle = taskHandle;
    PrimAppendNode(D_007963D0, drawNode);
    return 0;
}

// FUN_00251CE0
/* Destroy the card sprite pack, then free its task work. */
void cmmRankUpCardTaskDestroy(u8 *task)
{
    void *work;

    work = (s32 *)kwlnTaskGetWork(task);
    sdkSpritePackDestroy((s32)((CmmRankUpCardTask *)work)->slot10.sprites);
    (*jtbl_008873EC)(work);
}

// FUN_00251D30
/* Find the first inactive entry among sixteen 0x78-byte rank-up records. */
u8 *cmmRankUpFindFreeEntry(u8 *entries) {
    s32 entryIndex;
    CmmRankUpEntry *entry;

    entryIndex = 0;
    entry = (CmmRankUpEntry *)entries;
    goto loop_test;
loop_body:
    if ((entry->flags & 1) == 0) {
        return (u8 *)entry;
    }
    entry++;
    entryIndex += 1;
loop_test:
    if (entryIndex < 0x10) {
        goto loop_body;
    }
    return NULL;
}

