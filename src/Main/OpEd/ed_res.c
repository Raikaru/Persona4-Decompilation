#include "include_asm.h"
/* Original translation unit ed_res.c (from __FILE__ assert strings). */
#include "type.h"
#include "ed_staff_internal.h"

/* GP-owned work record shared with the adjacent opening/ending TU. */
extern u32 *D_007246AC;
#define sOpTailC D_007246AC

extern char D_0064F250[];
extern char D_0064F260[];

extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const void *file, s32 line);
/* Defined below in this file; called at line 33, above its definition. */
extern void edResFreeText(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void frFontSlotLoadData(s32 slot, u8 *fontData);
extern void frFontSlotFree(s32 slot);

// Release the loaded resource and clear the work pointer.
// FUN_0038F620
void edResRelease(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    if ((sOpTailC[1] & 1) != 0) {
        edResFreeText();
    }
    sOpTailC = NULL;
}

// Finish a pending load: build the effect header, load the font slot data and free the file.
// FUN_0038F680
void edResLoadStep(void)
{
    u32 *work;
    s32 size;
    s32 i;
    void *data;
    void *copy;

    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((work[0] & 1) != 0 && H_Cdvd_IsFileLoaded((u8 *)(uintptr_t)work[2]) != 0) {
        for (i = 0; i < 2; i++) {
            data = H_Cdvd_GetArchiveEntry((u8 *)(uintptr_t)work[2], i, &size);
            switch (i) {
            case 0:
                work[3] = (u32)edResBuildEffectHeader((const u32 *)data);
                break;
            case 1:
                chkmemAllocSiteTag(D_0064F250, 0x56);
                copy = (*jtbl_008873E8)(size, 0x40000);
                memcpy(copy, data, size);
                frFontSlotLoadData(6, copy);
                break;
            }
        }
        work[1] |= 1;
        H_Cdvd_Destroy((u8 *)(uintptr_t)work[2]);
        work[0] &= ~1u;
    }
}

// Request the resource file for the roll and mark it pending.
// FUN_0038F7F0
void edResRequestLoad(void)
{
    u32 *work;

    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((~work[0] & 1) == 0) {
        kAssertFail(D_0064F250, 0x68);
    }
    work[2] = (u32)H_Cdvd_AcquireDirectory((u8 *)D_0064F260, 1);
    work[0] |= 1;
}

// Report whether a resource load is pending.
// FUN_0038F880
u32 edResIsPending(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    return sOpTailC[0] & 1;
}

// Free the parsed stream and the font slot used by the roll.
// FUN_0038F8D0
void edResFreeText(void)
{
    u32 *work;

    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    work = sOpTailC;
    if ((work[1] & 1) == 0) {
        kAssertFail(D_0064F250, 0x84);
    }
    brpParamFree((u8 *)(uintptr_t)work[3]);
    frFontSlotFree(6);
}

// Return the parsed stream pointer for the roll.
// FUN_0038F950
u32 edResGetStream(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    return sOpTailC[3];
}
