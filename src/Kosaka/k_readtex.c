#include "kwln_task_internal.h"
/* Original translation unit k_readtex.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005F60B8[];
extern u8 D_005F6040[];
extern u8 D_005F6060[];
extern u8 D_005F6080[];
extern u8 D_005F60A0[];
extern u8 D_005F60D0[];
extern u8 D_005F60F0[];
extern u8 D_005F6110[];
extern u8 D_005F6130[];
extern u8 D_005F6150[];
extern s32 K_ReadTexUpdate(u8 *task);
extern void K_ReadTexDestroy(u8 *task);
extern void func_003ef3a0(void *handle);
extern s32 func_003ef6d0(void);
extern void *func_003ef650(s32 owner, const void *name);
extern void func_00440b68(const void *file, const void *message, s32 line);
extern void *H_Cdvd_AcquireDirectory(const char *path, s32 flags);
extern void H_Cdvd_Destroy(void *cdvd);
extern s32 filerEnqueueRequest(s32, const void *, s32, s32, s32, s32, s32, s32, s64, s64);
extern void filerTakeCompletedRequest(s32 request, s32 *completed, s32 resultValue);
extern s32 iGpffffa030;

/* Source unit: src/promoted/k_readtex.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_readtex.c; members 001901d0-00190600 */

/* Load four texture archives, wait for their consumer tasks, then release the archive handles. */
// FUN_001901D0
s32 K_ReadTexUpdate(u8 *task)
{
    typedef struct {
        s32 state;
        void *handles[4];
        s32 tasks[4];
        u8 pad24[0x14];
        s32 *owner;
    } ReadTexState;
    ReadTexState *state;
    void *handle;
    s32 i;
    s32 *slot;
    s32 result;

    state = (ReadTexState *)((KwlnTask *)task)->work;
    switch (state->state) {
    case 0:
        handle = func_003ef650(func_003ef6d0(), D_005F6040);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F6060);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F6080);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        handle = func_003ef650(func_003ef6d0(), D_005F60A0);
        if (handle != NULL) {
            func_003ef3a0(handle);
        }
        func_00440b68(&iGpffffa030, D_005F60B8, 0x54);
        state->handles[0] = H_Cdvd_AcquireDirectory((const char *)D_005F60D0, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x55);
        state->handles[1] = H_Cdvd_AcquireDirectory((const char *)D_005F60F0, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x56);
        state->handles[2] = H_Cdvd_AcquireDirectory((const char *)D_005F6110, 0);
        func_00440b68(&iGpffffa030, D_005F60B8, 0x57);
        state->handles[3] = H_Cdvd_AcquireDirectory((const char *)D_005F6130, 0);
        state->state += 1;
        /* fall through */
    case 1:
        if (H_Cdvd_IsFileLoaded(state->handles[0]) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(state->handles[1]) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(state->handles[2]) == 0) {
            return 0;
        }
        if (H_Cdvd_IsFileLoaded(state->handles[3]) == 0) {
            return 0;
        }
        state->tasks[0] = filerEnqueueRequest(0, D_005F6040, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[1] = filerEnqueueRequest(0, D_005F6060, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[2] = filerEnqueueRequest(0, D_005F6080, 0, 0, 0, 0, 0, 0, 0, 0);
        state->tasks[3] = filerEnqueueRequest(0, D_005F60A0, 0, 0, 0, 0, 0, 0, 0, 0);
        state->state += 1;
        /* fall through */
    case 2:
        for (i = 0; i < 4; i++) {
            slot = &state->tasks[i];
            if (*slot != 0) {
                filerTakeCompletedRequest(*slot, &result, 0);
                if (result != 0) {
                    *slot = 0;
                    continue;
                }
                return 0;
            }
        }
        H_Cdvd_Destroy(state->handles[0]);
        H_Cdvd_Destroy(state->handles[1]);
        H_Cdvd_Destroy(state->handles[2]);
        H_Cdvd_Destroy(state->handles[3]);
        return -1;
    default:
        return 0;
    }
}

// FUN_001905D0
void K_ReadTexDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Allocate the four-archive texture-loading state and create its scheduler task. */
// FUN_00190600
void K_ReadTexTaskCreate(void)
{
    u8 *mem;

    chkmemAllocSiteTag(D_005F60B8, 0x91);
    mem = D_008873F4[0](1, 0x24, 0x40000);
    if (mem != NULL) {
        (s32)kwlnTaskCreate((const void *)(D_005F6150), 0xF, 0, 0, K_ReadTexUpdate, K_ReadTexDestroy, (u8 *)(mem));
    }
}

