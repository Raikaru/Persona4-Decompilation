#include "h_cdvd_internal.h"
#include "kwln_task_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "Kosaka/k_clump_internal.h"
#include "texture_callback_internal.h"

typedef struct ClumpWork
{
    u32 state;        /* 0x00 */
    s32 field_4;      /* 0x04 */
    u8  field_8[0x40]; /* 0x08 */
    char name[0x40];  /* 0x48 */
    u32 field_88[0x31]; /* 0x88 */
    s32 count;        /* 0x14C */
    u32 items[0x80];  /* 0x150 */
    char path[0x100]; /* 0x350 */
    u8 *field_450;    /* 0x450 */
} ClumpWork;

extern void *func_003e2f60(s32, s32, void *);
extern s32 func_003df3c0(void *, s32 *);
extern void *func_003e6a90(void *);
extern void func_003e6870(void *, void *);
extern void func_003ef1b0(void *);
extern void *func_003c0f20(void *);
extern s32 K_Clump_ClumpHasMatUsrData(void *clump, const char *name);
extern void func_003c0960(void *, void *);
extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const char *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
extern void func_003e2910(void *, void *, s32);
extern void func_003deff0(void *, s32, s32, s32, s32);
extern void func_003e2ab0(void *, void *, s32);
extern void K_Clump_FreeTextureNameList(void *listHead);
extern void func_003e2e40(void *, s32);
extern void *K_Clump_RenderAtomicCallBack(void *atomic, void *data);
extern void K_Clump_ReadChunks(u8 *directory, s32 *outputPath, u8 *workBytes);
extern s32 K_Clump_LoadDirUpdate(u8 *task);
extern void K_Clump_LoadDestroy(u8 *task);
extern char D_005F64C0[];
extern char D_005F64E0[];
extern char D_005F6500[];
extern s32 func_00428550(const char *);
extern s32 func_00428780(s32, void *);
extern s32 atoi(const char *);
extern void strcat(void *, const char *);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern void H_Cdvd_ReadSync(void *cdvd);
extern void func_003c0700(void *);

extern s32 func_00428618(s32);
extern char D_005F6520[];
extern char D_005F6550[];
extern char D_005F6570[];
extern char D_005F65A0[];
extern char iGpffffa06c;
extern char iGpffffa070;
extern char iGpffffa078;
extern char iGpffffa080;

/* Known difference: the argument setup order for the five-argument func_003deff0 call differs from
 * retail. */


/* Copy stream chunks to disk, rewriting texture dictionaries and clumps while retaining texture
 * names. */
// FUN_00191E90
void K_Clump_ReadChunks(u8 *directory, s32 *outputPath, u8 *workBytes)
{
    s32 streamContext[8];
    union { s32 s[4]; u32 u[4]; } chunkHeader;
    s32 i;
    void *inputStream;
    void *outputStream;
    void *chunkData;
    ClumpWork *work = (ClumpWork *)workBytes;

    streamContext[7] = 0;
    streamContext[4] = (s32)((HCdvd *)directory)->fileMemory;
    streamContext[5] = (s32)((HCdvd *)directory)->fileSize;
    inputStream = func_003e2f60(3, 1, &streamContext[4]);
    outputStream = func_003e2f60(2, 2, outputPath);
    work->count = 0;
    for (i = 0; i < 0x80; i++)
    {
        ((ClumpWork *)workBytes)->items[i] = 0;
    }
    if (inputStream != NULL && outputStream != NULL)
    {
        while (func_003df3c0(inputStream, &chunkHeader.s[0]) != 0)
        {
            switch (chunkHeader.s[0])
            {
            case 0x16:
                chunkData = func_003e6a90(inputStream);
                func_003e6870(chunkData, outputStream);
                func_003ef260((const struct RwTexDictionary *)chunkData, &K_Clump_AppendTextureName, &streamContext[7]);
                func_003ef1b0(chunkData);
                break;
            case 0x10:
                ((ClumpWork *)workBytes)->items[work->count] =
                    (s32)func_003c0f20(inputStream);
                if (K_Clump_ClumpHasMatUsrData((void *)((ClumpWork *)workBytes)->items[work->count],
                                  D_005F64C0) == 0 &&
                    K_Clump_ClumpHasMatUsrData((void *)((ClumpWork *)workBytes)->items[work->count],
                                  D_005F64E0) == 0)
                {
                    if (((ClumpWork *)workBytes)->count != 0)
                    {
                        RpClumpForAllAtomics((void *)((ClumpWork *)workBytes)->items[((ClumpWork *)workBytes)->count],
                                             K_Clump_RenderAtomicCallBack, NULL);
                    }
                }
                func_003c0960((void *)((ClumpWork *)workBytes)->items[work->count], outputStream);
                ((ClumpWork *)workBytes)->count = ((ClumpWork *)workBytes)->count + 1;
                break;
            case 0xF0F000E0:
                kAssertFail(D_005F6500, 0x93);
                break;
            default:
                chkmemAllocSiteTag(D_005F6500, 0x9A);
                chunkData = D_008873F4[0](1, chunkHeader.u[1], 0x40000);
                func_003e2910(inputStream, chunkData, chunkHeader.s[1]);
                func_003deff0((void *)outputStream, (u32)chunkHeader.s[0], (u32)chunkHeader.s[1], chunkHeader.s[2], chunkHeader.s[3]);
                func_003e2ab0(outputStream, chunkData, chunkHeader.s[1]);
                jtbl_008873EC[0](chunkData);
                break;
            }
        }
        if (streamContext[7] != 0)
        {
            K_Clump_FreeTextureNameList((void *)streamContext[7]);
        }
        func_003e2e40(inputStream, 0);
        func_003e2e40(outputStream, 0);
    }
}


/* measured: retail hoists the '.' and '/' loop constants out of the scan loop. */
#pragma opt_loop_invariants on
/* Enumerate candidate model files, rewrite their streams, then destroy the temporary clumps. */
// FUN_001921A0
s32 K_Clump_LoadDirUpdate(u8 *task)
{
    ClumpWork *work;
    char *extension;
    char *fileName;
    s32 i;
    s32 result;
    struct Local {
        char buffer[0x100];
        char suffix[4];
        char pad[0x30];
    } local;

    work = (ClumpWork *)((KwlnTask *)task)->work;
    switch (work->state)
    {
    case 0:
        result = func_00428550(D_005F6520);
        work->field_4 = result;
        if (result < 0)
        {
            return -1;
        }
        work->state++;
        break;
    case 1:
        result = func_00428780(work->field_4, work->field_8);
        if (result > 0)
        {
            if (strcmp(work->name, &iGpffffa06c) != 0 &&
                strcmp(work->name, &iGpffffa070) != 0)
            {
                extension = work->name;
                while (*extension != '.' && *extension != '\0')
                {
                    extension++;
                }
                if (strcmp(extension, &iGpffffa078) == 0)
                {
                    local.suffix[0] = work->name[1];
                    local.suffix[1] = work->name[2];
                    local.suffix[2] = work->name[3];
                    local.suffix[3] = '\0';
                    if (atoi(local.suffix) < 0x14)
                    {
                        strcpy(work->path, D_005F6550);
                        strcat(work->path, work->name);
                        work->state = 2;
                    }
                }
            }
        }
        else
        {
            work->state = 6;
        }
        break;
    case 2:
        func_00440b68(&iGpffffa080, D_005F6500, 0xEB);
        work->field_450 = H_Cdvd_AcquireDirectory(work->path, 0);
        H_Cdvd_ReadSync(work->field_450);
        strcpy(local.buffer, D_005F6570);
        fileName = work->path;
        while (*fileName != '\0')
        {
            fileName++;
        }
        for (; *fileName != '/'; fileName--)
        {
        }
        strcat(local.buffer, fileName + 1);
        K_Clump_ReadChunks(work->field_450, (s32 *)local.buffer, (u8 *)work);
        H_Cdvd_Destroy((HCdvd *)work->field_450);
        work->state = 3;
        break;
    case 3:
    case 4:
        work->state++;
        break;
    case 5:
        for (i = 0; i < work->count; i++)
        {
            if ((s32)work->items[i] != 0)
            {
                func_003c0700((void *)(s32)work->items[i]);
            }
        }
        work->state = 1;
        break;
    case 6:
        return -1;
    }
    return 0;
}
/* measured: restores the unit setting after K_Clump_LoadDirUpdate. */
#pragma opt_loop_invariants off


/* Close the directory enumeration handle and release task work. */
// FUN_00192480
void K_Clump_LoadDestroy(u8 *task)
{
    s32 handle;

    handle = ((ClumpWork *)MEMBER(u8 *, task, KwlnTask, work))->field_4;
    if (handle >= 0)
    {
        func_00428618(handle);
    }
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}


/* Create the directory-rewrite task with its 0x454-byte work block. */
// FUN_001924D0
s32 K_Clump_CreateLoadTask(void)
{
    void *mem;

    chkmemAllocSiteTag(D_005F6500, 0x126);
    mem = D_008873F4[0](1, 0x454, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F65A0), 0xF, 0, 0, K_Clump_LoadDirUpdate, K_Clump_LoadDestroy, (u8 *)(mem));
}
