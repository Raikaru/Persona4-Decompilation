/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldData.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "h_cdvd_internal.h"

extern void (*DAT_008873EC[])(void *);

extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern char D_005F0A88[];
extern char D_005F0A70[];
extern char D_005F0AA0[];
extern char D_005F0AC0[];
extern char D_005F0AE0[];
extern char D_005F0AF8[];
extern char D_005F0B10[];
extern char D_005F0B30[];
extern char D_005F0B50[];
extern char D_005F0B70[];
extern char D_005F0B90[];
extern char D_005F0BB0[];
extern char D_005F0BD0[];
extern char D_005F0BF0[];
extern char D_005F0C10[];
extern char D_005F0C30[];
extern char D_005F0C50[];
extern char D_005F0C70[];
extern char D_005F0C90[];
extern char D_005F0CB0[];
extern char D_005F0CD0[];
extern char D_005F0CF0[];
extern char D_005F0D10[];
extern char D_005F0D30[];
extern char D_005F0D50[];
extern char D_005F0D70[];
extern char D_005F0D90[];
extern char D_005F0DB0[];
extern char D_005F0DD0[];
extern char D_005F0DF0[];
extern char D_005F0E10[];
extern char D_005F0E30[];
extern char D_005F0E50[];
extern char D_005F0E70[];
extern char D_005F0E90[];
extern char D_005F0EB0[];
extern char D_005F0ED0[];
extern char D_005F0EF0[];
extern char D_005F0F10[];
extern char D_005F0F30[];
extern char D_005F0F50[];
extern char D_005F0F70[];
extern char D_005F0F90[];
extern char D_005F0FB0[];
extern char D_005F0FD0[];
extern char D_005F0FF0[];
extern char D_005F1010[];
extern char D_005F1030[];
extern u8 D_005F1050[];

extern u8 *func_00454a60(u8 *path, s32 mode);
extern void H_Cdvd_ReadSync(HCdvd *file);
extern void *func_00477f10(void *kind, void *id, s32 memory, s32 size, u32 flags);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 func_0015cf70(void);
extern s32 func_00161510(void);
extern s32 func_004782b0(u8 *model);

extern void *memcpy(void *destination, const void *source, u32 size);
extern u32 H_Cdvd_Destroy(HCdvd *file);
extern s32 func_0015d000(u8 *arg0);
extern s32 func_001615a0(u8 *file);
extern s32 func_0045b1c0(void *parent, s32 kind, s32 buffer, void *name);
extern s32 func_0045b170(void *request);
extern u8 *func_004667d0(s32 kind, const char *name, const char *path, s32 flags, s32 source, s32 buffer, s32 size, const char *cacheName, s32 resultKind, s32 memoryKind);
extern u8 *func_004669d0(u8 *request, s32 *ready, s32 *source);
extern s32 func_0018c580(u8 *arg0);
extern s32 func_00452490(void *task);
extern void func_0046d730(const void *msg, s32 id);
extern s32 D_007E3710[];
extern s32 D_007E3714[];
extern s32 D_007E3718[];
extern u8 D_007E3720[];
extern char D_00762FC8;
extern s32 D_00764364;
extern s32 iGpffffb26c;
extern u16 *uGpffffb270;
extern s32 iGpffffb278;
extern s32 iGpffffb27c;
extern s32 iGpffffb280;
extern s32 iGpffffb284;
extern s32 func_0015d730(u8 *arg0);



/* Measured with configured MWCCPS2 b210 -O2: 4196 executable bytes,
 * followed by twelve zero alignment bytes. Independent allocation/copy size
 * snapshots preserve the resource extent through each native call boundary. */
#pragma push
#pragma opt_propagation off
typedef struct FldDataLoadWork {
    s32 state;
    s32 reserved04;
    HCdvd *mapFile;
    u32 reserved0c;
    HCdvd *fieldScript;
    HCdvd *dungeonTable;
    HCdvd *npcTable;
    HCdvd *unitTable;
    HCdvd *rainModels[2];
    u32 reserved28[2];
    HCdvd *televisionModels[2];
    HCdvd *supportScript;
    u8 *mapTextures[30];
    u32 reservedb4[9];
    u8 *rainTextures[2];
    u32 reservede0[2];
    u8 *televisionTextures[2];
    s32 mipmapTask;
} FldDataLoadWork;
typedef char FldDataLoadWorkSizeCheck[sizeof(FldDataLoadWork) == 0xF4 ? 1 : -1];

static inline u8 fldDataModelReady(void)
{
    return func_004782b0((u8 *)D_00764364) != 0;
}

// FUN_0015D730
s32 func_0015d730(u8 *task)
{
    s32 textureReady;
    u32 scriptAllocationSize;
    u32 scriptCopySize;
    u32 dungeonCopySize;
    u32 supportAllocationSize;
    u32 supportCopySize;
    char mapPath[0x80];
    char scriptPath[0x80];
    char dungeonPath[0x80];
    s32 state;
    void *baseModelKind;
    void *baseModelId;
    s32 soundRequest;
    u8 *televisionRequest;
    u8 *rainRequest;
    u8 *mapRequest;
    s32 mapTextureIndex;
    s32 rainTextureIndex;
    s32 televisionTextureIndex;
    s32 scriptReady;
    s32 dungeonReady;
    s32 soundReady;
    u16 *soundMemory;
    u16 *scriptMemory;
    u16 *supportMemory;
    FldDataLoadWork *work;
    HCdvd *scriptFile;
    HCdvd *dungeonFile;
    HCdvd *baseModelFile;
    HCdvd *supportFile;
    u8 *requestSlot;

    work = (FldDataLoadWork *)((SdkTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
        func_00440b68(&D_00762FC8, D_005F0A88, 0xE6);
        baseModelFile = (HCdvd *)func_00454a60((u8 *)D_005F0AF8, 0);
        H_Cdvd_ReadSync(baseModelFile);
        baseModelKind = (void *)4;
        baseModelId = (void *)0x7D0;
        D_00764364 = (s32)func_00477f10(baseModelKind, baseModelId,
                                      (s32)baseModelFile->fileMemory, (s32)baseModelFile->fileSize, 0);
        sprintf(mapPath, D_005F0A70);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x6B);
        work->mapFile = (HCdvd *)func_00454a60((u8 *)mapPath, 1);
        sprintf(scriptPath, D_005F0AA0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x89);
        work->fieldScript = (HCdvd *)func_00454a60((u8 *)scriptPath, 0);
        sprintf(dungeonPath, D_005F0AC0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0xA9);
        work->dungeonTable = (HCdvd *)func_00454a60((u8 *)dungeonPath, 0);
        work->npcTable = (HCdvd *)func_0015cf70();
        work->unitTable = (HCdvd *)func_00161510();
        func_00440b68(&D_00762FC8, D_005F0A88, 0x124);
        work->rainModels[0] = (HCdvd *)func_00454a60((u8 *)D_005F0B10, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x125);
        work->rainModels[1] = (HCdvd *)func_00454a60((u8 *)D_005F0B30, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x128);
        work->televisionModels[0] = (HCdvd *)func_00454a60((u8 *)D_005F0B50, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x129);
        work->televisionModels[1] = (HCdvd *)func_00454a60((u8 *)D_005F0B70, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12A);
        work->supportScript = (HCdvd *)func_00454a60((u8 *)D_005F0B90, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12B);
        D_007E3710[0] = (s32)func_00454a60((u8 *)D_005F0BB0, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12C);
        D_007E3714[0] = (s32)func_00454a60((u8 *)D_005F0BD0, 0);
        func_00440b68(&D_00762FC8, D_005F0A88, 0x12D);
        D_007E3718[0] = (s32)func_00454a60((u8 *)D_005F0BF0, 0);
        func_0044ea90(D_005F0A88, 0xC5);
        soundMemory = (u16 *)D_008873F4[0](1, 0x414, 0x40000);
        uGpffffb270 = soundMemory;
        iGpffffb26c = func_0045b1c0(task, 6, (s32)soundMemory, D_005F0AE0);
        work->state = work->state + 1;
        /* Start polling after queuing the first-stage resources. */
    case 1:
        if (fldDataModelReady()) {
            if (H_Cdvd_IsFileLoaded(work->mapFile) == 0) {
                return 0;
            }
            scriptFile = work->fieldScript;
            if (scriptFile == NULL) {
                scriptReady = 1;
            } else if (H_Cdvd_IsFileLoaded(scriptFile) != 0) {
                func_0044ea90(D_005F0A88, 0x94);
                scriptAllocationSize = scriptFile->fileSize;
                scriptMemory = (u16 *)D_008873F4[0](1, scriptAllocationSize, 0x40000);
                iGpffffb284 = (s32)scriptMemory;
                iGpffffb280 = (s32)scriptFile->fileSize;
                scriptCopySize = scriptFile->fileSize;
                memcpy(scriptMemory, scriptFile->fileMemory, scriptCopySize);
                H_Cdvd_Destroy(scriptFile);
                scriptReady = 1;
            } else {
                scriptReady = 0;
            }
            if (scriptReady == 0) {
                return 0;
            }
            work->fieldScript = NULL;
            dungeonFile = work->dungeonTable;
            if (dungeonFile == NULL) {
                dungeonReady = 1;
            } else if (H_Cdvd_IsFileLoaded(dungeonFile) == 0) {
                dungeonReady = 0;
            } else {
                if (dungeonFile->fileSize >= 0xC00U) {
                    func_0046d730(D_005F0A88, 0xB3);
                }
                dungeonCopySize = dungeonFile->fileSize;
                memcpy(D_007E3720, dungeonFile->fileMemory, dungeonCopySize);
                H_Cdvd_Destroy(dungeonFile);
                dungeonReady = 1;
            }
            if (dungeonReady == 0) {
                return 0;
            }
            work->dungeonTable = NULL;
            if (func_0015d000((u8 *)work->npcTable) == 0) {
                return 0;
            }
            work->npcTable = NULL;
            if (func_001615a0((u8 *)work->unitTable) == 0) {
                return 0;
            }
            work->unitTable = NULL;
            if (H_Cdvd_IsFileLoaded(work->rainModels[0]) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded(work->rainModels[1]) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded(work->televisionModels[0]) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded(work->televisionModels[1]) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded(work->supportScript) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded((HCdvd *)((u8 *)D_007E3710[0])) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded((HCdvd *)((u8 *)D_007E3714[0])) == 0) {
                return 0;
            }
            if (H_Cdvd_IsFileLoaded((HCdvd *)((u8 *)D_007E3718[0])) == 0) {
                return 0;
            }
            soundRequest = iGpffffb26c;
            if (soundRequest == 0) {
                soundReady = 1;
            } else if (func_0045b170((void *)(soundRequest)) == 0) {
                soundReady = 0;
            } else {
                iGpffffb26c = 0;
                soundReady = 1;
            }
            if (soundReady == 0) {
                return 0;
            }
            work->mapTextures[0] = func_004667d0(0, D_005F0C10, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[1] = func_004667d0(0, D_005F0C30, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[28] = func_004667d0(0, D_005F0C50, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[29] = func_004667d0(0, D_005F0C70, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[2] = func_004667d0(0, D_005F0C90, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[3] = func_004667d0(0, D_005F0CB0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[4] = func_004667d0(0, D_005F0CD0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[5] = func_004667d0(0, D_005F0CF0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[6] = func_004667d0(0, D_005F0D10, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[7] = func_004667d0(0, D_005F0D30, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[8] = func_004667d0(0, D_005F0D50, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[9] = func_004667d0(0, D_005F0D70, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[10] = func_004667d0(0, D_005F0D90, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[11] = func_004667d0(0, D_005F0DB0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[12] = func_004667d0(0, D_005F0DD0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[13] = func_004667d0(0, D_005F0DF0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[14] = func_004667d0(0, D_005F0E10, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[15] = func_004667d0(0, D_005F0E30, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[16] = func_004667d0(0, D_005F0E50, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[17] = func_004667d0(0, D_005F0E70, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[18] = func_004667d0(0, D_005F0E90, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[19] = func_004667d0(0, D_005F0EB0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[20] = func_004667d0(0, D_005F0ED0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[21] = func_004667d0(0, D_005F0EF0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[22] = func_004667d0(0, D_005F0F10, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[23] = func_004667d0(0, D_005F0F30, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[24] = func_004667d0(0, D_005F0F50, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[25] = func_004667d0(0, D_005F0F70, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[26] = func_004667d0(0, D_005F0F90, 0, 0, 0, 0, 0, 0, 0, 0);
            work->mapTextures[27] = func_004667d0(0, D_005F0FB0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->rainTextures[0] = func_004667d0(0, D_005F0FD0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->rainTextures[1] = func_004667d0(0, D_005F0FF0, 0, 0, 0, 0, 0, 0, 0, 0);
            work->televisionTextures[0] = func_004667d0(0, D_005F1010, 0, 0, 0, 0, 0, 0, 0, 0);
            work->televisionTextures[1] = func_004667d0(0, D_005F1030, 0, 0, 0, 0, 0, 0, 0, 0);
            work->state = work->state + 1;
        } else {
            break;
        }
        /* First-stage files are complete; begin polling texture requests. */
    case 2:
        mapTextureIndex = 0;
        goto map_texture_test;
map_texture_body:
        requestSlot = (u8 *)&work->mapTextures[mapTextureIndex];
        mapRequest = work->mapTextures[mapTextureIndex];
        if (mapRequest != 0) {
            func_004669d0(mapRequest, &textureReady, 0);
            if (textureReady != 0) {
                *(u8 **)requestSlot = NULL;
            } else {
                return 0;
            }
        }
        mapTextureIndex += 1;
map_texture_test:
        if (mapTextureIndex < 0x1E) {
            goto map_texture_body;
        }
        rainTextureIndex = 0;
        goto rain_texture_test;
rain_texture_body:
        requestSlot = (u8 *)&work->rainTextures[rainTextureIndex];
        rainRequest = work->rainTextures[rainTextureIndex];
        if (rainRequest != 0) {
            func_004669d0(rainRequest, &textureReady, 0);
            if (textureReady != 0) {
                *(u8 **)requestSlot = NULL;
            } else {
                return 0;
            }
        }
        rainTextureIndex += 1;
rain_texture_test:
        if (rainTextureIndex < 2) {
            goto rain_texture_body;
        }
        televisionTextureIndex = 0;
        goto television_texture_test;
television_texture_body:
        requestSlot = (u8 *)&work->televisionTextures[televisionTextureIndex];
        televisionRequest = work->televisionTextures[televisionTextureIndex];
        if (televisionRequest != 0) {
            func_004669d0(televisionRequest, &textureReady, 0);
            if (textureReady != 0) {
                *(u8 **)requestSlot = NULL;
            } else {
                return 0;
            }
        }
        televisionTextureIndex += 1;
television_texture_test:
        if (televisionTextureIndex < 2) {
            goto television_texture_body;
        }
        func_0044ea90(D_005F0A88, 0x1BB);
        supportAllocationSize = work->supportScript->fileSize;
        supportMemory = (u16 *)D_008873F4[0](1, supportAllocationSize, 0x40000);
        iGpffffb27c = (s32)supportMemory;
        supportFile = work->supportScript;
        supportCopySize = supportFile->fileSize;
        memcpy(supportMemory, supportFile->fileMemory, supportCopySize);
        iGpffffb278 = (s32)work->supportScript->fileSize;
        H_Cdvd_Destroy(work->mapFile);
        H_Cdvd_Destroy(work->rainModels[0]);
        H_Cdvd_Destroy(work->rainModels[1]);
        H_Cdvd_Destroy(work->televisionModels[0]);
        H_Cdvd_Destroy(work->televisionModels[1]);
        H_Cdvd_Destroy(work->supportScript);
        work->mipmapTask = func_0018c580(task);
        work->state = work->state + 1;
        break;
    default:
        break;
    case 3:
        if (func_00452490((void *)(work->mipmapTask)) != 1) {
            return -1;
        }
        break;
    }
    return 0;
}

#pragma pop
// FUN_0015E7A0
void func_0015e7a0(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
// FUN_0015E7D0
s32 func_0015e7d0(void)
{
    u8 *mem;
    s32 result;

    func_0044ea90(D_005F0A88, 0x1ED);
    mem = D_008873F4[0](1, 0xF4, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    result = (s32)func_00451de0((const void *)(D_005F1050), 0xF, 0, 0, func_0015d730, func_0015e7a0, (u8 *)(mem));
    *(s32 *)(mem + 4) = 0;
    return result;
}

