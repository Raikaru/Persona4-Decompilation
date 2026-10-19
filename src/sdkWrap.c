/* Original translation unit sdkWrap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "h_cdvd_internal.h"
#include "sdktask.h"

/* Request offsets are shared by the polling loop and worker dispatch below.
 * The 0x80-byte path regions end at the next path/state field. */
typedef union SdkWrapDirectory {
    s32 handle;
    u8 *bytes;
    struct HCdvd *cdvd;
} SdkWrapDirectory;
typedef struct SdkWrapRequest {
    u8 *next;
    s32 unk4;
    s32 resourceId;
    s32 result;
    u8 *resource;
    s32 unk14, unk18, unk1C, unk20;
    u8 path[0x80];
    u8 directoryPath[0x80];
    u8 contextPath[0x80];
    s32 state;
    s32 directoryFlags;
    s32 operation;
    SdkWrapDirectory directory;
    s32 unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC;
    u8 *unk1D0;
    s16 waitFrames;
    u8 pad1D6[2];
} SdkWrapRequest;
typedef struct SdkWrapQueue {
    u8 *head;
    u8 pad4[0x1D4];
} SdkWrapQueue;
typedef struct SdkWrapWorker {
    s16 ready;
    u8 pad2[2];
    u8 *request;
} SdkWrapWorker;
typedef struct SdkWrapStreamWork {
    s32 handle;
    u8 *directory;
} SdkWrapStreamWork;

extern void (*jtbl_008873EC[])(void *);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_00712978[];
extern u8 D_007129E0[];
extern u8 D_00712A00[];
extern u8 D_007129A0[];
extern u8 D_007129C0[];
extern s32 sdkWrapStreamCloseUpdate(u8 *arg0);
extern s32 filerTakeCompletedRequest(s32 arg0, s32 *arg1, s32 options);
extern void func_003ef3a0(s32 arg0);
extern void sdkWrapPollRequests(void);
extern void sdkWrapWorkerThread(u8 *);

extern u8 D_008E4B50[];
extern s32 func_0042ba20(void);
extern s32 func_0042ba70(void);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void WakeupThread(s32 threadId);
extern u8 D_00712990[];
extern s32 D_00724BC8;
extern char iGpffffb010[6];
extern u8 iGpffffbae0[8];
extern f32 iGpffffbb24;

/* 540/544 bytes; twenty resolved relocations; four zero alignment bytes.
 * The pointer switch retains the retail null guard and separate backedge. */
#pragma opt_loop_invariants on
/* Poll queued directory requests and wake the resource worker once ready. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
// FUN_00466C60
void sdkWrapPollRequests(void)
{
    s16 queueIndex;
    u8 *request;
    s32 locked;

    for (queueIndex = 0; queueIndex <= 0; queueIndex++) {
        request = ((SdkWrapQueue *)D_008E4B50)[queueIndex].head;
        if (request != NULL) {
            for (;;) {
                switch (((SdkWrapRequest *)request)->state) {
                case 0:
                    if (*(s8 *)(request + 0xA4) != 0) {
                        locked = func_0042ba20();
                        func_00440b68(iGpffffb010, D_00712978, 0x233);
                        ((SdkWrapRequest *)request)->directory.bytes =
                            H_Cdvd_AcquireDirectory(((SdkWrapRequest *)request)->directoryPath, ((SdkWrapRequest *)request)->directoryFlags);
                        if (locked != 0) {
                            func_0042ba70();
                        }
                        *(s32 *)(request + 0x1A4) = 1;
                        goto next_queue;
                    }
                    ((SdkWrapRequest *)request)->directory.bytes = NULL;
                    locked = 0;
                    goto enqueue;
                case 1:
                    locked = func_0042ba20();
                    if (H_Cdvd_IsFileLoaded(((SdkWrapRequest *)request)->directory.cdvd) != 0) {
                        if (locked != 0) {
                            func_0042ba70();
                        }
                        locked = 0;
                enqueue:
                        *(s16 *)(iGpffffbae0 + queueIndex * 8) = 1;
                        *(u8 **)(iGpffffbae0 + queueIndex * 8 + 4) = request;
                        *(s32 *)(request + 0x1A4) = 2;
                        WakeupThread(*((s32 *)&D_00724BC8 + queueIndex));
                    }
                    if (locked != 0) {
                        func_0042ba70();
                    }
                    goto next_queue;
                case 2:
                    if (++((SdkWrapRequest *)request)->waitFrames > 5) {
                        func_00440b68((const char *)D_00712990, (s32)iGpffffbb24);
                    }
                    goto next_queue;
                case 3:
                    request = ((SdkWrapRequest *)request)->next;
                    if (request == NULL) {
                        return;
                    }
                    break;
                default:
                    goto next_queue;
                }
                switch ((uintptr_t)request) {
                case 0:
                    goto next_queue;
                }
            }
        }
next_queue:
        ;
    }
}
#pragma opt_loop_invariants reset
/* Resource worker loop: dispatch a ready request and release its directory. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
// FUN_00466E80
void sdkWrapWorkerThread(u8 *worker)
{
    extern void func_00421700(void);
    extern void func_003eaa80(u8 *worker);
    extern s32 func_003ef740(u8 *worker, s32 value);
    extern u8 iGpffffb01c;
    extern u8 *func_003be180(s32 worker);
    extern void func_003d60e0(u8 *worker, s32 value);
    extern u8 D_0070B610[];
    extern s32 func_003c0f20(s32 worker);
    extern s32 func_003d5330(u8 *worker);
    extern s32 func_003e2910(s32 worker, s32 value, s32 options);
    extern s32 func_00395290(s32 worker);
    extern s32 func_003bba90(u8 *worker);
    extern s32 func_003d6350(s32 worker, s32 value);
    extern u8 *func_003e6a90(s32 worker);
    extern s32 tmxUploadStream(s32 worker, s32 value);
    extern s32 func_003eaf60(u8 *worker);
    extern s32 func_003bb210(s32 worker);
    extern s32 func_0042ba20(void);
    extern s32 func_0042ba70(void);
    u8 *request;
    u8 *nextRequest;
    s32 locked;
    s16 ready;

wait_start:
    for (;;) {
        func_00421700();
        ready = ((SdkWrapWorker *)worker)->ready;
        switch (ready) {
        case 0:
            goto wait;
        case 1:
            goto process;
        default:
            goto wait;
        }
    wait:
        ;
    }
process:
    for (;;) {
        request = ((SdkWrapWorker *)worker)->request;
        switch (((SdkWrapRequest *)request)->operation) {
        case 0:
            if (*(s8 *)(request + 0x124) != 0) {
                func_003eaa80(((SdkWrapRequest *)request)->contextPath);
            }
            *(s32 *)(*(u8 **)(worker + 4) + 0x1B4) =
                func_003ef740(*(u8 **)(worker + 4) + 0x24, 0);
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 1:
            if (*(s8 *)(request + 0x124) != 0) {
                func_003eaa80(((SdkWrapRequest *)request)->contextPath);
            }
            *(u8 **)(*(u8 **)(worker + 4) + 0x10) =
                func_003be180(*(s32 *)(*(u8 **)(worker + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 2:
            if (*(s8 *)(request + 0x124) != 0) {
                func_003eaa80(((SdkWrapRequest *)request)->contextPath);
            }
            if (*(s32 *)(*(u8 **)(worker + 4) + 0x1CC) != 0) {
                func_003d60e0(D_0070B610, *(s32 *)(*(u8 **)(worker + 4) + 0x1CC));
            }
            *(s32 *)(*(u8 **)(worker + 4) + 0xC) =
                (s32)func_003c0f20(*(s32 *)(*(u8 **)(worker + 4) + 8));
            func_003eaa80((u8 *)&iGpffffb01c - 4);
            break;
        case 3:
            *(s32 *)(*(u8 **)(worker + 4) + 0x14) =
                func_003d5330(((SdkWrapRequest *)request)->path);
            break;
        case 4:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1BC) =
                func_003e2910(((SdkWrapRequest *)request)->resourceId,
                              ((SdkWrapRequest *)request)->unk1C4,
                              ((SdkWrapRequest *)request)->unk1C0);
        case 5:
            *(s32 *)(*(u8 **)(worker + 4) + 0x18) =
                (s32)func_00395290(*(s32 *)(*(u8 **)(worker + 4) + 8));
            break;
        case 6:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1C) =
                func_003bba90(((SdkWrapRequest *)request)->path);
            break;
        case 7:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1C8) =
                func_003d6350(((SdkWrapRequest *)request)->unk20, ((SdkWrapRequest *)request)->resourceId);
            break;
        case 8:
            *(u8 **)(*(u8 **)(worker + 4) + 0x1D0) =
                func_003e6a90(((SdkWrapRequest *)request)->resourceId);
            break;
        case 9:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1B8) =
                tmxUploadStream(((SdkWrapRequest *)request)->unk1C4, 0);
            break;
        case 10:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1C4) =
                func_003eaf60(((SdkWrapRequest *)request)->path);
            break;
        case 11:
            *(s32 *)(*(u8 **)(worker + 4) + 0x1C) =
                func_003bb210(((SdkWrapRequest *)request)->resourceId);
            break;
        }
        if (*(s32 *)(*(u8 **)(worker + 4) + 0x1B0) != 0) {
            locked = func_0042ba20();
            H_Cdvd_Destroy(*(struct HCdvd **)(*(u8 **)(worker + 4) + 0x1B0));
            *(s32 *)(*(u8 **)(worker + 4) + 0x1B0) = 0;
            if (locked != 0) {
                func_0042ba70();
            }
        }
        locked = func_0042ba20();
        *(s32 *)(*(u8 **)(worker + 4) + 0x1A4) = 3;
        request = *(u8 **)(worker + 4);
        if (((SdkWrapRequest *)request)->operation != 8 &&
            ((SdkWrapRequest *)request)->operation != 2) {
            nextRequest = ((SdkWrapRequest *)request)->next;
            if (nextRequest != NULL &&
                ((SdkWrapRequest *)nextRequest)->state == 0 &&
                *(s8 *)(nextRequest + 0xA4) == 0) {
                *(s32 *)(nextRequest + 0x1A4) = 2;
                *(u8 **)(worker + 4) = nextRequest;
                if (locked != 0) {
                    func_0042ba70();
                }
                continue;
            }
        }
        ((SdkWrapWorker *)worker)->ready = 0;
        if (locked == 0) {
            goto wait_start;
        }
        func_0042ba70();
        goto wait_start;
    }
}
/* The stream-close callback registered by func_004672c0. It sits inside the
   func_00466e80 verify window and is not in the retail function table, so its
   marker splits the window: 820B + padding, then this 200B callback. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
// FUN_004671C0
s32 sdkWrapStreamCloseUpdate(u8 *task)
{
    s32 completed;
    u8 *streamWork;
    s32 result;

    streamWork = ((SdkTask *)task)->work;
    result = filerTakeCompletedRequest(((SdkWrapStreamWork *)streamWork)->handle, &completed, 0);
    if (completed != 0) {
        if (((SdkWrapStreamWork *)streamWork)->directory != NULL) {
            func_00440b68((const char *)D_007129A0, ((SdkWrapStreamWork *)streamWork)->directory + 0x10);
        } else {
            func_00440b68((const char *)D_007129C0);
        }
        if (result != 0) {
            func_003ef3a0(result);
        }
        if (*(u8 **)(streamWork + 4) != NULL) {
            H_Cdvd_Destroy(*(struct HCdvd **)(streamWork + 4));
        }
        ((SdkWrapStreamWork *)streamWork)->handle = 0;
        *(u8 **)(streamWork + 4) = NULL;
        return -1;
    }
    return 0;
}




// FUN_00467290
void sdkWrapStreamCloseDestroy(u8 *task)
{
    jtbl_008873EC[0]((void *)((SdkTask *)task)->work);
}

/* measured: `handle` must be declared BEFORE `mem`. With `mem` first, b210
   colours mem into $s1 and handle into $s0 -- the exact mirror of retail --
   and every one of the 9 differing words is that swap. Declaration order is
   the whole fix here (9 -> 1, the remaining word being window padding). */
/* Create a deferred-close task holding the stream and its acquired directory. */
// FUN_004672C0
s32 sdkWrapStreamCloseCreate(s32 stream, u8 *directory)
{
    s32 taskHandle;
    u8 *work;

    chkmemAllocSiteTag(D_00712978, 0x3C4);
    work = D_008873F4[0](1, 8, 0x40000);
    if (work == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_007129E0), 0, 2, 2, sdkWrapStreamCloseUpdate, sdkWrapStreamCloseDestroy, (u8 *)(work));
    if (taskHandle == 0) {
        return 0;
    }
    if (directory != NULL) {
        func_00440b68((const char *)D_00712A00, directory + 0x10);
    }
    ((SdkWrapStreamWork *)work)->handle = stream;
    ((SdkWrapStreamWork *)work)->directory = directory;
    return taskHandle;
}

