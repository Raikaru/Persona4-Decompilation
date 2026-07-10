#ifndef H_CDVD_INTERNAL_H
#define H_CDVD_INTERNAL_H

#include "Utils.h"

typedef void* ADXF;

typedef struct HCdvd
{
    struct HCdvd* prev;
    struct HCdvd* next;
    u32 hasExternalMemory;
    u32 readState;
    char path[256];
    void* fileMemory;
    void* unalignedFileMemory;
    u32 fileSize;
    u8 unk_11c[8];
    u32 readByteSize;
    u8 unk_128[0x28];
    u32 fileMode;
    ADXF adxf;
    char fileName[256];
    char dir[256];
    s16 archiveFileCount;
    s16 refCount;
    s16 pendingDestroyCount;
    s16 readPollCount;
    u8 unk_360[4];
} HCdvd;

typedef struct HCdvdCache
{
    u32 isValid;
    void* requestData;
    char path[128];
    void* fileMemory;
    u32 fileSize;
    u32 unk_90;
} HCdvdCache;

typedef struct HCdvdStreamContext
{
    u32 reserved00;
    u32 count;
    u8 reserved08[0x0c];
    void* callback14;
    void* callback18;
    u8 reserved1c[0x0c];
    void* callback28;
    void* callback2c;
    void* callback30;
    void* callback34;
    void* callback38;
    u8 reserved3c[8];
    void* callback44;
    u8 reserved48[4];
    void* callback4c;
    u8 reserved50[8];
    void* slots;
} HCdvdStreamContext;

typedef struct HCdvdFileContext
{
    u32 reserved00;
    u32 count;
    u8 reserved08[0x0c];
    void* callback14;
    void* callback18;
    u8 reserved1c[0x0c];
    void* callback28;
    void* callback2c;
    void* callback30;
    void* callback34;
    void* callback38;
    u8 reserved3c[8];
    void* callback44;
    u8 reserved48[4];
    void* callback4c;
    u8 reserved50[8];
    u8* slots;
} HCdvdFileContext;

extern const char D_007117a0[];
extern HCdvdCache D_008c8780[];
extern u32 D_008873ec[];
#define HCDVD_FREE(memory) (*(void (**)(void*))D_008873ec)(memory)

extern void func_004244c8(const char* message, ...);
extern s32 func_00440b68(const char* message, ...);
extern s32 func_004426e8(const char* left, const char* right);
extern void func_00454640(void);
extern void func_00454d20(const char* source, char* destination);
extern void func_00454e10(const char* path, char* fileName, char* directory);
extern void func_00455100(const char* source, char* destination);
extern void func_00455230(const char* directory);
extern u32 func_004553c0(HCdvd* cdvd);
extern ADXF func_004c85a0(const char* path, s32 mode);
extern void func_004c8a60(ADXF adxf);
extern void func_004d6f78(void* stream, const char* fileName);
extern void* func_004d9020(void);
extern void func_0050c008(void* handle, const char* fileName);
extern void func_0050ff20(void* handle, const char* fileName);

#endif
