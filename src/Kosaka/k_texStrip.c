#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
#include "sdk_task_registration.h"
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "kwln_task_internal.h"
#include "h_cdvd_internal.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_00428618(s32 value);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void *func_003ef650(void *value, const char *other);
extern void func_003ef610(s32 value);
extern void func_003ef5b0(s32 value, s32 other);

extern s32 func_00468170(void *value, const char *other);
extern s32 sdkFilerPollResult(s32 value, void *other);
extern void K_Clump_LogCodeCounts(void *value);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern char D_005F6168[];
extern char D_005F6178[];
extern char D_005F6190[];
extern char D_005F61B0[];
extern char D_005F63E0[];
extern char D_005F6490[];
extern char D_005F64A8[];

extern s32 func_003e2f60(s32 a, s32 b, s32 *c);
extern s32 func_003df3c0(s32 a, s32 *b);
extern void func_003e2910(s32 a, void *b, s32 c);
extern void func_003deff0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_003e2ab0(s32 a, void *b, s32 c);
extern void func_003e2ce0(s32 a, s32 b);
extern void func_003e2e40(s32 a, s32 b);
extern s32 func_003e6a90(s32 a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 func_004288d8(void *a, void *b);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern void H_Cdvd_ReadSync(void *handle);
extern char *strcat(char *dst, const char *src);
extern void func_003ef1b0(s32 value);
extern void func_003ef260(s32 value, s32 (*other)(s32, s32), s32 flags);
extern void func_003e6870(void *value, void *other);
extern s32 K_TexStripNameInsert(s32 value, s32 other);
extern char D_005F63F0[];
extern char D_005F6430[];
extern char D_005F6450[];
extern char D_005F6470[];
extern char D_00763128;
extern char D_00763130;
extern char D_00763138;
extern char D_0076313C;
extern char D_00763140;
extern char D_00763148;
extern char D_00763150;
extern char D_00763158;
extern s32 D_00764498;

extern s32 func_00428550(const char *path);
extern s32 func_00428780(s32 handle, void *out);
extern s32 strcmp(const char *a, const char *b);
extern char *strcpy(char *dst, const char *src);
extern u8 *FldResource_Create(void *path);
extern s32 FldResource_IsFileLoaded(void *hdr);
extern void FldResource_ParseChunks(void *hdr);
extern s32 FldResource_PollLoads(void *hdr);
extern s32 K_Clump_CountIntUsrData(void *object, const char *name);
extern s32 func_00426cf0(void *path, s32 a, s32 b);
extern size_t strlen(const char *buf);
extern s32 func_00427338(s32 fd, void *buf, s32 n);
extern s32 func_004275a8(s32 fd, void *buf, s32 n);
extern void func_00426f80(s32 fd);
extern void func_00428f08(void *a, s32 b);
extern void FldResource_Destroy(void *hdr);
extern void K_Clump_FreeTextureNameList(void *a);
extern char D_005F61D0[];
extern char D_005F61F8[];
extern char D_005F6210[];
extern char D_005F6230[];
extern char D_005F6250[];
extern char D_005F6270[];
extern char D_005F62A0[];
extern char D_005F62B0[];
extern char D_005F62C0[];
extern char D_005F62D0[];
extern char D_005F6310[];
extern char D_005F6350[];
extern char D_005F6370[];
extern char D_005F63B0[];

s32 K_TexStripLoadRecords(u8 *value, void *other);
void K_TexStripApplyNames(u8 *value, void *other, u8 *flags);
s32 K_TexStripBuildUpdate(u8 *value);
s32 K_TexStripRecordCount(u8 *value, void *other);
s32 K_TexStripLoadUpdate(u8 *value);

/* Source unit: src/promoted/k_texStrip.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_texStrip.c; members 00190680-00191d90 */

// measured: nd 115 after 4 attempts (best). Spill-slot rule as K_TexStripRecordCount:
// func_003df3c0 writes four signed header words in spill.s. Switch `case 0x16 / case 0xF0F000E0 /
// default` compiles the dispatch comparison in the correct order (0xF0F000E0 first, then 0x16)
// and matches retail exactly. Residual nd 115 is dominated by register allocation: retail keeps
// sp60/sp64/sp68 (the 0x14-byte func_003e2910 buffer + sp64/sp68) on the STACK at 0x60/0x64/
// 0x68, but mwcc promotes sp64/sp68 to $s5/$s6 (sp68 folded with `sll $s6,2` / `addu $s0,$s6,$s6`)
// adding a 5th/6th saved reg, so the whole allocation shifts (retail wants var_16->$s0, arg1/
// temp_2->$s1, temp_18->$s2, temp_19->$s3, var_20->$s4). Making sp60/sp64/sp68 overlap via a
// 5-word array (nd 138) or a 3-field struct (nd 141) is worse. Core regs are otherwise right.
// QTEX lane: plain-C candidate object 668/window 672; baseline fndiff was nd 20
// (six differing instruction words plus one zero-padding tail word), with both
// func_003deff0 calls materializing move $a0 before the spill.s[0]/spill.s[1] loads.
// The targeted `(u32)` casts on spill.s[0] and spill.s[1] at both calls produce nd 0.
// s32 sp[2], the 16-byte spill union, and buffer[5] reproduce the 0xA0 frame and saved-register
// coloring. Shared-callee probe: retail func_003deff0 first-uses a0 as a forwarded
// pointer, saves a1/a2, and masks a3/t0, proving five args `(void *,s32,s32,s32,s32)`;
// existing calls already pass all five, so no prototype change was needed.
/* Both build/load creators allocate 0xe74 bytes. Directory reads start at
 * 0x08, their name at 0x48; the three 256-entry tables and counters below are
 * addressed by both update paths. Handles retain the existing 32-bit storage. */
typedef struct TexStripWork
{
    s32 state;
    s32 directory;
    u8 directoryStat[0x40];
    char fileName[0x100];
    u8 pad148[4];
    char resourcePath[0x100];
    s32 resource;
    s32 archive;
    s32 textureCount;
    s32 textureIds[0x100];
    s32 textureDictionaries[0x100];
    s32 fileCount;
    s32 fileIds[0x100];
    s32 textureIndex;
    s32 textureArchive;
    s32 sourceBytes;
    s32 outputBytes;
    s32 fieldId;
    s32 textureId;
} TexStripWork;
/* Resource header prefix plus its separately owned texture-name allocation. */
typedef struct FldResource
{
    u8 pad00[4];
    s16 fieldId;
    s16 roomId;
    u8 pad08[0x10];
    u32 clumpCount;
    s32 clumps[1]; /* first entry; remaining array span is opaque here */
    u8 pad20[0xA24];
    s32 textureNames;
} FldResource;
typedef struct FldResourceTextureNames
{
    u8 pad00[0x128];
    void *names;
} FldResourceTextureNames;
typedef struct TexStripCodeLogWork
{
    s32 state;
    s32 filerTask;
} TexStripCodeLogWork;

/* Copy the chunk stream, reading texture dictionaries and stripping QTEX prefixes. */
// FUN_00190680
s32 K_TexStripLoadRecords(u8 *input, void *outputPath) {
    s32 inputBuffer[2];
    union { s32 s[4]; u32 u[4]; } chunk;
    s32 buffer[5];
    s32 dictionary;
    s32 inputStream;
    s32 outputStream;
    u8 *textureBuffer;
    u8 *chunkBuffer;

    dictionary = 0;
    inputBuffer[0] = (s32)((HCdvd *)input)->fileMemory;
    inputBuffer[1] = (s32)((HCdvd *)input)->fileSize;
    inputStream = func_003e2f60(3, 1, &inputBuffer[0]);
    outputStream = func_003e2f60(2, 2, (s32 *)outputPath);
    if ((inputStream != 0) && (outputStream != 0)) {
        goto loop_check;
loop_body:
        switch (chunk.s[0]) {
        case 0x16:
            dictionary = func_003e6a90(inputStream);
            break;
        case 0xF0F000E0:
            func_003e2910(inputStream, &buffer[0], 0x14);
            func_003deff0(outputStream, (u32)chunk.s[0], (u32)chunk.s[1], chunk.s[2], chunk.s[3]);
            func_003e2ab0(outputStream, &buffer[0], 0x14);
            func_003e2ce0(inputStream, buffer[2]);
            chkmemAllocSiteTag(D_005F6168, 0xBB);
            textureBuffer = D_008873F4[0](1, buffer[1] + buffer[2], 0x40000);
            func_003e2910(inputStream, textureBuffer + buffer[2], buffer[1]);
            func_003e2ab0(outputStream, textureBuffer, buffer[1] + buffer[2]);
            jtbl_008873EC[0](textureBuffer);
            break;
        default:
            if (chunk.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0xCA);
                chunkBuffer = D_008873F4[0](1, chunk.u[1], 0x40000);
                func_003e2910(inputStream, chunkBuffer, chunk.s[1]);
            }
            func_003deff0(outputStream, (u32)chunk.s[0], (u32)chunk.s[1], chunk.s[2], chunk.s[3]);
            if (chunk.s[1] != 0) {
                func_003e2ab0(outputStream, chunkBuffer, chunk.s[1]);
                jtbl_008873EC[0](chunkBuffer);
            }
            break;
        }
loop_check:
        if (func_003df3c0(inputStream, &chunk.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(inputStream, 0);
        func_003e2e40(outputStream, 0);
    }
    return dictionary;
}

/* Look up the texture name, detach and insert it when absent, then report
   the lookup result. Pointer-typed lookup/print arguments and disabled CSE
   preserve retail's first-argument-before-name-address materialization.
   measured: object 196B/window 208B; exact instructions, 12B zero tail. */
/* measured: K_TexStripNameInsert MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_00190920
s32 K_TexStripNameInsert(s32 texture, s32 dictionary) {
    if (func_003ef650((void *)dictionary, (char *)texture + 0x10) == 0) {
        func_003ef610(texture);
        func_003ef5b0(dictionary, texture);
        func_00440b68(D_005F6178, (char *)texture + 0x10);
        if (func_003ef650((void *)dictionary, (char *)texture + 0x10) != 0) {
            func_00440b68(D_005F6190, (char *)texture + 0x10);
        }
    } else {
        func_00440b68(D_005F61B0, (char *)texture + 0x10);
    }
    return texture;
}

/* measured: restore CSE after the exact 00190920 call sequence. */
/* measured: K_TexStripApplyNames, K_TexStripBuildUpdate, K_TexStripRecordCount, K_TexStripLoadUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// measured: candidate frame, spill arrays, saved-register order, switch/goto layout, and
// shared-callee five-argument signature reached object 532/window 544 with normalized_diff 10.
// fndiff isolated the residual to func_003deff0 setup: retail loads spill.s[0] and spill.s[1]
// into $a1/$a2 before moving temp_19 into $a0, while b210 materializes the first argument
// first. Casting those two stack values to u32 reproduces the retail order and closes this
// function (normalized_diff 0).
/* Merge texture dictionaries into the resource stream while copying all other chunks. */
// FUN_001909F0
void K_TexStripApplyNames(u8 *input, void *outputPath, u8 *workData) {
    s32 inputBuffer[2];
    union { s32 s[4]; u32 u[4]; } chunk;
    s32 inputStream;
    s32 outputStream;
    s32 dictionary;
    s32 sourceDictionary;
    u32 textureIndex;
    u8 *chunkBuffer;

    inputBuffer[0] = (s32)((HCdvd *)input)->fileMemory;
    inputBuffer[1] = (s32)((HCdvd *)input)->fileSize;
    inputStream = func_003e2f60(3, 1, &inputBuffer[0]);
    outputStream = func_003e2f60(2, 2, (s32 *)outputPath);
    if ((inputStream != 0) && (outputStream != 0)) {
        goto loop_check;
loop_body:
        switch (chunk.s[0]) {
        case 0x16:
            dictionary = func_003e6a90(inputStream);
            textureIndex = 0;
            goto item_check;
item_body:
            sourceDictionary = ((TexStripWork *)workData)->textureDictionaries[textureIndex];
            if (sourceDictionary != 0) {
                func_003ef260(sourceDictionary, K_TexStripNameInsert, dictionary);
            }
            textureIndex++;
item_check:
            if (textureIndex < (u32)((TexStripWork *)workData)->textureCount) {
                goto item_body;
            }
            func_003e6870((void *)dictionary, (void *)outputStream);
            func_003ef1b0(dictionary);
            break;
        default:
            if (chunk.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0x141);
                chunkBuffer = D_008873F4[0](1, chunk.u[1], 0x40000);
                func_003e2910(inputStream, chunkBuffer, chunk.s[1]);
            }
            func_003deff0(outputStream, (u32)chunk.s[0], (u32)chunk.s[1], chunk.s[2], chunk.s[3]);
            if (chunk.s[1] != 0) {
                func_003e2ab0(outputStream, chunkBuffer, chunk.s[1]);
                jtbl_008873EC[0](chunkBuffer);
            }
            break;
        }
loop_check:
        if (func_003df3c0(inputStream, &chunk.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(inputStream, 0);
        func_003e2e40(outputStream, 0);
    }
}

/* measured: complete file-stat records, per-state loop lifetimes, and live
   resource reloads reproduce retail. See docs/probe_archive/
   TexStrip_00190c10_20261005.md for owner and relocation evidence. */
/* Enumerate resource files, collect texture/file IDs, and write stripped assets plus a manifest. */
// FUN_00190C10
#pragma push
/* measured: K_TexStripBuildUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 K_TexStripBuildUpdate(u8 *task)
{
    /* sceGetstat owns each complete 64-byte record. Only its size word is
       interpreted here; the other thirteen trailing words remain opaque. */
    typedef struct {
        u32 fields00[2];
        u32 size;
        u32 fields0C[13];
    } TexStripFileStat;
    TexStripFileStat fileStat;
    char sourcePath[0x100];
    char manifestLine[0x100];
    char targetPath[0x100];
    char modelPath[0x100];
    char texturePath[0x100];
    char resourcePath[0x100];
    TexStripFileStat copyStat;
    KClumpIntPropertyResult kindProperty;
    KClumpIntPropertyResult idProperty;
    TexStripWork *work;

    work = (TexStripWork *)((KwlnTask *)task)->work;
    switch (work->state) {
    case 0:
        work->directory = func_00428550(D_005F61D0);
        if (work->directory < 0) {
            return -1;
        }
        work->state++;
        break;
    case 1: {
        s32 tmp;
        char *p;
        tmp = func_00428780(work->directory, work->directoryStat);
        if (tmp > 0) {
            if (strcmp((void *)&work->fileName, &D_00763138) != 0 &&
                strcmp((void *)&work->fileName, &D_0076313C) != 0) {
                for (p = (char *)&work->fileName; *p != '.' && *p != 0; p++) {
                }
                if (strcmp(p, &D_00763140) == 0) {
                    strcpy((void *)&work->resourcePath, D_005F61F8);
                    strcat((void *)&work->resourcePath, (void *)&work->fileName);
                    work->resource = (s32)FldResource_Create((void *)&work->resourcePath);
                    func_00440b68(D_005F6210, &work->resourcePath);
                    work->state = 2;
                }
            }
        } else {
            work->state = 8;
        }
        break;
    }
    case 2:
        if (FldResource_IsFileLoaded((void *)work->resource) != 0) {
            FldResource_ParseChunks((void *)work->resource);
            work->state = 3;
        }
        break;
    case 3: {
        u32 resourceIndex;
        s32 propertyIndex;
        if (FldResource_PollLoads((void *)work->resource) != 0) {
            work->textureCount = 0;
            work->fileCount = 0;
            for (resourceIndex = 0; resourceIndex < ((FldResource *)work->resource)->clumpCount; resourceIndex++) {
                u32 resourceOffset = resourceIndex * 4;
                s32 propertyCount = K_Clump_CountIntUsrData((void *)((FldResource *)((u32)work->resource + resourceOffset))->clumps[0], D_005F6230);
                for (propertyIndex = 0; propertyIndex < propertyCount; propertyIndex++) {
                    K_Clump_GetIntUsrDataAt(&kindProperty, (void *)((FldResource *)(resourceOffset + (u32)work->resource))->clumps[0], D_005F6230, propertyIndex);
                    if (kindProperty.value == 0) {
                        K_Clump_GetIntUsrDataAt(&idProperty, (void *)((FldResource *)(resourceOffset + (u32)work->resource))->clumps[0], D_005F6250, propertyIndex);
                        work->textureIds[work->textureCount] = idProperty.value;
                        work->textureCount++;
                    } else if (kindProperty.value == 1) {
                        K_Clump_GetIntUsrDataAt(&idProperty, (void *)((FldResource *)(resourceOffset + (u32)work->resource))->clumps[0], D_005F6250, propertyIndex);
                        work->fileIds[work->fileCount] = idProperty.value;
                        work->fileCount++;
                    }
                }
            }
            work->state = 4;
        }
        break;
    }
    case 4: {
        char *p;
        char *q;
        u32 textureIndex;
        u32 fileIndex;
        s32 descriptor;
        strcpy(sourcePath, D_005F6270);
        for (p = (char *)&work->resourcePath; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(sourcePath, p + 1);
        for (q = (char *)sourcePath; *q != '.'; q++) {
        }
        strcpy(q, &D_00763148);
        D_00764498 = func_00426cf0(sourcePath, 0x603, 0x1FF);
        if (D_00764498 >= 0) {
            work->sourceBytes = 0;
            work->outputBytes = 0;
            sprintf(manifestLine, D_005F62A0, ((FldResource *)work->resource)->fieldId, ((FldResource *)work->resource)->roomId);
            func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
            for (textureIndex = 0; textureIndex < (u32)work->textureCount; textureIndex++) {
                if (work->textureIds[textureIndex] != 0) {
                    sprintf(manifestLine, D_005F62B0, ((FldResource *)work->resource)->fieldId, work->textureIds[textureIndex]);
                    func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
                }
            }
            for (fileIndex = 0; fileIndex < (u32)work->fileCount; fileIndex++) {
                u8 *copyBuffer;
                s32 *item = &work->fileIds[fileIndex];
                sprintf(manifestLine, D_005F62C0, ((FldResource *)work->resource)->fieldId, *item);
                func_004275a8(D_00764498, manifestLine, strlen(manifestLine));
                sprintf(sourcePath, D_005F62D0, ((FldResource *)work->resource)->fieldId, *item);
                func_004288d8(sourcePath, &fileStat);
                sprintf(targetPath, D_005F6310, ((FldResource *)work->resource)->fieldId, *item);
                func_004288d8(sourcePath, &copyStat);
                chkmemAllocSiteTag(D_005F6168, 0x166);
                copyBuffer = D_008873F4[0](1, copyStat.size, 0x40000);
                if (copyBuffer != 0) {
                    if ((descriptor = func_00426cf0(sourcePath, 1, 0x1FF)) >= 0) {
                        func_00427338(descriptor, (void *)copyBuffer, copyStat.size);
                        func_00426f80(descriptor);
                        func_00428f08(&D_00763130, 0);
                    }
                    if ((descriptor = func_00426cf0(targetPath, 0x603, 0x1FF)) >= 0) {
                        func_004275a8(descriptor, (void *)copyBuffer, copyStat.size);
                        func_00426f80(descriptor);
                        func_00428f08(&D_00763130, 0);
                    }
                    jtbl_008873EC[0]((void *)copyBuffer);
                }
            }
        }
        work->textureIndex = 0;
        work->state = 5;
        break;
    }
    case 5: {
        char *p;
        s32 *hdr;
        if ((u32)work->textureIndex < (u32)work->textureCount) {
            if (work->textureIds[work->textureIndex] != 0) {
                sprintf(modelPath, D_005F6350, ((FldResource *)work->resource)->fieldId, work->textureIds[work->textureIndex]);
                func_00440b68(&D_00763150, D_005F6168, 0x263);
                p = (char *)H_Cdvd_AcquireDirectory(modelPath, 0);
                work->textureArchive = (s32)p;
                H_Cdvd_ReadSync(p);
                work->state = 6;
            } else {
                work->textureIndex++;
            }
        } else {
            FldResource_Destroy((void *)work->resource);
            hdr = (s32 *)work->resource;
            hdr = (s32 *)((FldResource *)hdr)->textureNames;
            K_Clump_FreeTextureNameList((void *)((FldResourceTextureNames *)hdr)->names);
            hdr = (s32 *)work->resource;
            jtbl_008873EC[0]((void *)((FldResource *)hdr)->textureNames);
            hdr = (s32 *)work->resource;
            ((FldResource *)hdr)->textureNames = 0;
            work->resource = 0;
            work->state = 7;
        }
        break;
    }
    case 6: {
        s32 tmp;
        sprintf(texturePath, D_005F6370, ((FldResource *)work->resource)->fieldId, work->textureIds[work->textureIndex]);
        tmp = K_TexStripLoadRecords((u8 *)work->textureArchive, texturePath);
        work->textureDictionaries[work->textureIndex] = tmp;
        H_Cdvd_Destroy((void *)work->textureArchive);
        work->textureArchive = 0;
        work->textureIndex++;
        work->state = 5;
        break;
    }
    case 7: {
        char *p;
        u8 *resource;
        u32 cleanupIndex;
        func_00440b68(&D_00763150, D_005F6168, 0x2A0);
        resource = H_Cdvd_AcquireDirectory((void *)&work->resourcePath, 0);
        work->archive = (s32)resource;
        H_Cdvd_ReadSync(resource);
        strcpy(resourcePath, D_005F63B0);
        for (p = (char *)&work->resourcePath; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(resourcePath, p + 1);
        K_TexStripApplyNames((u8 *)work->archive, resourcePath, (u8 *)work);
        H_Cdvd_Destroy((void *)work->archive);
        strcpy(resourcePath, D_005F63B0);
        for (p = (char *)&work->resourcePath; *p != 0; p++) {
        }
        for (; *p != '/'; p--) {
        }
        strcat(resourcePath, p + 1);
        func_004288d8(resourcePath, &fileStat);
        work->outputBytes += fileStat.size;
        for (cleanupIndex = 0; cleanupIndex < (u32)work->textureCount; cleanupIndex++) {
            s32 *item = &work->textureDictionaries[cleanupIndex];
            if (*item != 0) {
                func_003ef1b0(*item);
                *item = 0;
            }
        }
        func_00426f80(D_00764498);
        work->state = 1;
        break;
    }
    case 8:
        return -1;
    }
    return 0;
}

#pragma pop
/* Close the directory iterator before releasing the build task work. */
// FUN_001915C0
/* TexStripWork stores the directory handle at offset 4. Typed task/work
 * access changed five instruction bytes; keep byte access and the final slot reload. */
void K_TexStripBuildTaskDestroy(u8 *task)
{
    s32 directory;

    directory = *(s32 *)(*(u8 **)(task + 0x38) + 4);
    if (directory >= 0)
    {
        func_00428618(directory);
    }
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

/* Allocate and start the resource texture-strip build task. */
// FUN_00191610
s32 K_TexStripBuildTaskCreate(void)
{
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x2ED);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F63E0), 0xF, 0, 0, K_TexStripBuildUpdate, K_TexStripBuildTaskDestroy, (u8 *)(mem));
}

// measured: MATCH (object 420/window 432). The four func_003df3c0 spill slots
// use a 16-byte union: producer &spill.s[0], signed reads spill.s[1..3],
// and unsigned allocation length spill.u[1]. The stack slots at 0x50-0x5C
// and retail saved-register allocation are unchanged.
// The `(u32)` casts on spill.s[0] and spill.s[1] in func_003deff0 reproduce retail's
// argument-materialization order (loads before the first-argument move).
/* Copy a resource stream and retain the texture dictionary chunk handle. */
// FUN_001916A0
s32 K_TexStripRecordCount(u8 *input, void *outputPath)
{
    s32 inputBuffer[2];
    union { s32 s[4]; u32 u[4]; } chunk;
    s32 dictionary;
    s32 inputStream;
    s32 outputStream;
    u8 *chunkBuffer;

    dictionary = 0;
    inputBuffer[0] = (s32)((HCdvd *)input)->fileMemory;
    inputBuffer[1] = (s32)((HCdvd *)input)->fileSize;
    inputStream = func_003e2f60(3, 1, &inputBuffer[0]);
    outputStream = func_003e2f60(2, 2, (s32 *)outputPath);
    if ((inputStream != 0) && (outputStream != 0)) {
        goto loop_check;
loop_body:
        switch (chunk.s[0]) {
        case 0x16:
            dictionary = func_003e6a90(inputStream);
            break;
        default:
            if (chunk.s[1] != 0) {
                chkmemAllocSiteTag(D_005F6168, 0x330);
                chunkBuffer = D_008873F4[0](1, chunk.u[1], 0x40000);
                func_003e2910(inputStream, chunkBuffer, chunk.s[1]);
            }
            func_003deff0(outputStream, (u32)chunk.s[0], (u32)chunk.s[1], chunk.s[2], chunk.s[3]);
            if (chunk.s[1] != 0) {
                func_003e2ab0(outputStream, chunkBuffer, chunk.s[1]);
                jtbl_008873EC[0](chunkBuffer);
            }
            break;
        }
loop_check:
        if (func_003df3c0(inputStream, &chunk.s[0]) != 0) {
            goto loop_body;
        }
        func_003e2e40(inputStream, 0);
        func_003e2e40(outputStream, 0);
    }
    return dictionary;
}

/* Load each field texture dictionary, merge names into its resource, and release handles. */
// FUN_00191850
s32 K_TexStripLoadUpdate(u8 *task)
{
    char fileStat[0x40];
    char texturePath[0x100];
    char resourcePath[0x100];
    TexStripWork *work;
    s32 textureIndex;
    u8 *textureArchive;
    u8 *resourceArchive;

    work = (TexStripWork *)((KwlnTask *)task)->work;
    switch (work->state)
    {
    case 0:
        work->textureId = 2;
        work->textureCount = 0;
        work->state = work->state + 1;
        /* fallthrough */
    case 1:
        sprintf((char *)&work->resourcePath, D_005F63F0, work->fieldId, work->textureId);
        if (func_004288d8(&work->resourcePath, fileStat) == 0)
        {
            sprintf((char *)&work->resourcePath, D_005F6430, work->fieldId, work->textureId);
            func_00440b68(&D_00763150, D_005F6168, 0x36E);
            textureArchive = (u8 *)H_Cdvd_AcquireDirectory(&work->resourcePath, 0);
            work->archive = (s32)textureArchive;
            H_Cdvd_ReadSync(textureArchive);
            work->state = 2;
            work->textureId = work->textureId + 1;
            func_00440b68(&D_00763128, &work->resourcePath);
        }
        else
        {
            work->textureId = work->textureId + 1;
            if (work->textureId > 0xF)
            {
                work->state = 3;
            }
        }
        break;
    case 2:
        sprintf(texturePath, D_005F6450);
        strcat(texturePath, (char *)&work->resourcePath);
        strcat(texturePath, &D_00763158);
        work->textureDictionaries[work->textureCount] = K_TexStripRecordCount((u8 *)work->archive, texturePath);
        H_Cdvd_Destroy((HCdvd *)work->archive);
        work->archive = 0;
        work->textureCount = work->textureCount + 1;
        work->state = 1;
        break;
    case 3:
        sprintf((char *)&work->resourcePath, D_005F6470, work->fieldId);
        func_00440b68(&D_00763150, D_005F6168, 0x39B);
        resourceArchive = (u8 *)H_Cdvd_AcquireDirectory(&work->resourcePath, 0);
        work->archive = (s32)resourceArchive;
        H_Cdvd_ReadSync(resourceArchive);
        sprintf(resourcePath, D_005F6450);
        strcat(resourcePath, (char *)&work->resourcePath);
        strcat(resourcePath, &D_00763158);
        K_TexStripApplyNames((u8 *)work->archive, resourcePath, (u8 *)work);
        for (textureIndex = 0; textureIndex < (u32)work->textureCount; textureIndex++)
        {
            s32 *dictionary = &work->textureDictionaries[textureIndex];
            if (*&work->textureDictionaries[textureIndex] != 0)
            {
                func_003ef1b0(*&work->textureDictionaries[textureIndex]);
                *dictionary = 0;
            }
        }
        H_Cdvd_Destroy((HCdvd *)work->archive);
        work->archive = 0;
        work->fieldId = work->fieldId + 1;
        if (work->fieldId > 0x30)
        {
            work->state = 4;
        }
        else
        {
            work->state = 0;
        }
        break;
    case 4:
        return -1;
    default:
        break;
    }
    return 0;
}

/* Close any directory handle before freeing load-task work. */
// FUN_00191B70
/* TexStripWork stores the directory handle at offset 4. Typed task/work
 * access changed five instruction bytes; keep byte access and the final slot reload. */
void K_TexStripLoadDestroy(u8 *task)
{
    s32 directory;

    directory = *(s32 *)(*(u8 **)(task + 0x38) + 4);
    if (directory >= 0)
    {
        func_00428618(directory);
    }
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}

/* Start texture loading at field ID 0x28 and texture ID one. */
// FUN_00191BC0
s32 K_TexStripLoadTaskCreate(void)
{
    s32 ret;
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x3D4);
    mem = D_008873F4[0](1, 0xE74, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F63E0), 0xF, 0, 0, K_TexStripLoadUpdate, K_TexStripLoadDestroy, (u8 *)(mem));
    ((TexStripWork *)mem)->fieldId = 0x28;
    ((TexStripWork *)mem)->textureId = 1;
    return ret;
}

/* Repeatedly request a filename and log its clump code counts until an empty result. */
// FUN_00191C70
s32 K_TexStripCodeLogUpdate(u8 *task)
{
    TexStripCodeLogWork *work;
    char path[0x80];

    work = (TexStripCodeLogWork *)((KwlnTask *)task)->work;
    switch (work->state)
    {
    case 0:
        work->filerTask = func_00468170(task, D_005F6490);
        work->state = work->state + 1;
        break;
    case 1:
        if (sdkFilerPollResult(work->filerTask, path) == 1)
        {
            if (path[0] == 0)
            {
                work->state = 2;
            }
            else
            {
                K_Clump_LogCodeCounts(path);
            }
            kwlnTaskDestroyWithHierarchy(work->filerTask);
            work->state = 0;
        }
        break;
    case 2:
        return -1;
    }
    return 0;
}

// FUN_00191D60
void K_TexStripCodeLogDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Allocate the two-word code-log task state and start the filename requester. */
// FUN_00191D90
s32 K_TexStripCodeLogTaskCreate(void)
{
    void *mem;

    chkmemAllocSiteTag(D_005F6168, 0x435);
    mem = D_008873F4[0](1, 0x8, 0x40000);
    if (mem == NULL)
    {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005F64A8), 0xF, 0, 0, K_TexStripCodeLogUpdate, K_TexStripCodeLogDestroy, (u8 *)(mem));
}

