/* Original translation unit k_fldData.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "h_cdvd_internal.h"

extern void (*DAT_008873EC[])(void *);

extern void chkmemAllocSiteTag(const void *msg, s32 id);
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
extern void *mdlCreateModelObjectFromMemory(u32 kind, u16 id, void *memory, u32 size, u32 flags);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 NpcTable_RequestFixedTable(void);
extern s32 FldEnemyOpenTable(void);
extern s32 mdlPrepareModel(u8 *model);

extern void *memcpy(void *destination, const void *source, u32 size);
extern u32 H_Cdvd_Destroy(HCdvd *file);
extern s32 NpcTable_InstallFixedTable(u8 *arg0);
extern s32 FldEnemyLoadTable(u8 *file);
extern s32 sdkSndCreateStreamTask(void *parent, s32 kind, s32 buffer, void *name);
extern s32 sdkSndStreamTaskReap(void *request);
extern u8 *func_004667d0(s32 kind, const char *name, const char *path, s32 flags, s32 source, s32 buffer, s32 size, const char *cacheName, s32 resultKind, s32 memoryKind);
extern u8 *func_004669d0(u8 *request, s32 *ready, s32 *source);
extern s32 FldMipmapLoadTaskCreate(u8 *arg0);
extern s32 kwlnTaskIsLinked(void *task);
extern void kAssertFail(const void *msg, s32 id);
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
extern s32 FldStartupDataUpdate(u8 *arg0);



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
    return mdlPrepareModel((u8 *)D_00764364) != 0;
}


#pragma pop

