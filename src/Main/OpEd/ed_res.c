#include "include_asm.h"
/* Persona 4 USA decompilation - ed_res.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "ed_staff_internal.h"

/* GP-owned work record shared with the adjacent opening/ending TU. */
extern u32 *D_007246AC;
#define sOpTailC D_007246AC

extern char D_0064F250[];
extern char D_0064F260[];

extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
/* Defined below in this file; called at line 33, above its definition. */
extern void func_0038f8d0(void);
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 H_Cdvd_IsFileLoaded(u8 *ptr);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *resource, s32 index, s32 *size);
extern void H_Cdvd_Destroy(u8 *ptr);
extern u8 *H_Cdvd_AcquireDirectory(u8 *param, s32 mode);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void frFontSlotLoadData(s32 slot, u8 *data);
extern void frFontSlotFree(s32 slot);

// FUN_0038F620
void func_0038f620(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    if ((sOpTailC[1] & 1) != 0) {
        func_0038f8d0();
    }
    sOpTailC = NULL;
}

// FUN_0038F680
void func_0038f680(void)
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
                work[3] = (u32)func_0038f400((const u32 *)data);
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

// FUN_0038F7F0
void func_0038f7f0(void)
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

// FUN_0038F880
u32 func_0038f880(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    return sOpTailC[0] & 1;
}

// FUN_0038F8D0
void func_0038f8d0(void)
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

// FUN_0038F950
u32 func_0038f950(void)
{
    if (sOpTailC == NULL) {
        kAssertFail(D_0064F250, 0x28);
    }
    return sOpTailC[3];
}
