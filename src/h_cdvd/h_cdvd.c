/* Source unit: src/h_cdvd/h_cdvd_00454570.c (1 function markers) */
#include "include_asm.h"
#include "h_cdvd_internal.h"

/* Prototypes for helpers defined in this TU but called by units that do not
 * declare them (the internal header uses the func_0045xxxx names; the call
 * sites use these named forms). */
extern void H_Cdvd_BuildPathUppercase(const char* src, char* dst);
extern void H_Cdvd_NormalizePath(const char* src, char* dst);
extern u32 H_Cdvd_IsFileLoaded(HCdvd* cdvd);
extern void func_00454e10(const char* path, char* fileName, char* directory);
extern void func_00455230(const char* directory);

extern void strcpy(char* destination, const char* source);
extern u32 strlen(const char* text);

static const char* sCdvdVolumePrefix = "VOL:";
static const char* sCdvdBattlePrefix = "BTL:";

static const char* sCdvdBtlDirectories[] = {
    "\\",
    "\\BATTLE\\",
    "\\BATTLE\\CUTIN\\",
    "\\BATTLE\\CUTIN\\C71_C80_L_L_1\\",
    "\\BATTLE\\CUTIN\\C82_L_L_1\\",
    "\\BATTLE\\CUTIN\\C90_L_L_1\\",
    "\\BATTLE\\CUTIN\\C93_L_L_1\\",
    "\\BATTLE\\CUTIN\\EPL\\",
    "\\BATTLE\\CUTIN\\MIXRAID\\",
    "\\BATTLE\\EFFECT\\",
    "\\BATTLE\\PANEL\\",
    "\\BATTLE\\RESULT\\",
    "\\BATTLE\\SHUFFLE\\",
    "\\MODEL\\",
    "\\MODEL\\FACILITYP\\",
    "\\MODEL\\FIELD\\",
    "\\MODEL\\NPC\\",
    "\\MODEL\\PACK\\",
    "\\MODEL\\PERSONA\\",
    "\\MODEL\\SYMBOL\\",
    "\\MODEL\\WEAPON\\",
    "\\SKILL\\",
    "\\SND_BENC\\",
    "\\SND_BENC\\BOSS\\",
    "\\SND_BENC\\PANEL\\",
    ""
};

extern const char* D_007107b0[];
extern const char* D_00710800[];
extern const char* D_00711190[];
extern const char* D_007113e0[];
extern const char D_00711630[];
extern const char D_00711648[];
extern u32 D_00763e40;
extern u32 D_00763e44;

extern s32 func_004f2798(void* output, const void* source);

extern void memcpy(void* destination, const void* source, u32 size);

typedef struct HCdvdRequestView
{
    u32 hasExternalMemory;
    u32 readState;
    char path[0x100];
    u8* fileMemory;
    u8 reserved10c[0x10];
    u32 readByteSize;
    u8 reserved120[0x28];
    u32 fileMode;
    u8 reserved14c[0x204];
    s16 archiveFileCount;
} HCdvdRequestView;
extern char* strcat(char* destination, const char* source);
extern void func_00455d70(void* requestData, void* fileMemory, u32 fileSize,
                          const char* path);

typedef struct ArchiveEntryHeader
{
    char fileName[252];
    u32 fileSize;
} ArchiveEntryHeader;

extern void func_004d8d30(void* handle, const char* name);

extern const char D_00711748[];
extern s32 sceRead(s32 fd, void* dst, u32 size);

extern const char D_00711758[];
extern s32 sceWrite(s32 fd, void* dst, u32 size);

typedef struct HCdvdStreamPosition
{
    s64 position;
    u32 unused0;
    u32 unused1;
} HCdvdStreamPosition;

typedef int long128 __attribute__((mode(TI)));

extern s32 func_004270f8(s32 fd, s32 offset, s32 origin);

extern const char D_00711780[];



// FUN_00454570
u32 H_Cdvd_FileExists(const char* path)
{
    char unusedUppercasePath[256];
    char fileName[256];
    char directory[256];
    char uppercasePath[256];
    ADXF adxf;

    func_00440b68(" Exist %s\n", path);
    H_Cdvd_BuildPathUppercase(path, unusedUppercasePath);
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);

    adxf = func_004c85a0(fileName, 0);
    if (adxf == NULL)
    {
        func_00440b68(" FALSE \n");
        return false;
    }

    func_004c8a60(adxf);
    func_00440b68(" TRUE \n");
    return true;
}


/* Removing this loses FUN_00454BD0 (MATCH nd0 -> MISMATCH nd122) - measured W161. */
#pragma opt_loop_invariants on

// FUN_00454BD0
u32 H_Cdvd_Destroy(HCdvd* cdvd)
{
    HCdvd* prev;
    HCdvd* next;
    s32 i;

    if (cdvd->readState != 0)
    {
        cdvd->pendingDestroyCount++;
        return true;
    }

    cdvd->refCount--;
    if (cdvd->refCount > 0)
    {
        return true;
    }

    prev = cdvd->prev;
    next = cdvd->next;
    prev->next = next;
    if (next != NULL)
    {
        next->prev = prev;
    }

    if (cdvd->fileMemory != NULL && cdvd->hasExternalMemory == false)
    {
        HCDVD_FREE(cdvd->unalignedFileMemory);
        cdvd->fileMemory = NULL;
        cdvd->unalignedFileMemory = NULL;
    }

    for (i = 0; i < 256; i++)
    {
        if (D_008c8780[i].isValid &&
            D_008c8780[i].requestData == &cdvd->hasExternalMemory)
        {
            D_008c8780[i].isValid = false;
        }
    }

    if (cdvd->adxf != NULL)
    {
        func_004c8a60(cdvd->adxf);
        cdvd->adxf = NULL;
    }

    HCDVD_FREE(cdvd);
    return true;
}


#pragma opt_loop_invariants off
/* Removing this loses FUN_00454D20 (MATCH nd0 -> MISMATCH nd58) - measured W161. */

#pragma opt_loop_invariants on
// FUN_00454D20
void H_Cdvd_BuildPathUppercase(const char* src, char* dst)
{
    char currChar;
    char* pathBase;
    size_t basePathLen;
    u32 i;
    char* dstPtr;
    s32 slash;
    s32 backslash;

    pathBase = "VOL:\\";
    strcpy(dst, pathBase);
    basePathLen = strlen(pathBase);
    i = 0;
    dstPtr = dst + basePathLen;
    slash = 0x2f;
    backslash = 0x5c;

    while (i < 0xff)
    {
        currChar = src[i];
        if (currChar == '\0')
        {
            dst[i + basePathLen] = '\0';
            return;
        }

        if (currChar == slash)
        {
            dstPtr[i] = backslash;
        }
        else if (currChar >= 'a' && currChar <= 'z')
        {
            dstPtr[i] = currChar - 0x20;
        }
        else
        {
            dstPtr[i] = currChar;
        }

        i++;
    }
}


#pragma opt_loop_invariants off
/* Removing this loses FUN_00454E10 (MATCH nd0 -> MISMATCH nd29) - measured W161. */

#pragma opt_loop_invariants on
// FUN_00454E10
void func_00454e10(const char* path, char* fileNameDst, char* dirDst)
{
    char reversedName[256];
    u32 pathLength;
    u32 nameLength;
    u32 reverseIndex;
    u32 outputIndex;
    char current;

    strcpy(fileNameDst, sCdvdVolumePrefix);
    strcpy(dirDst, path);
    pathLength = strlen(dirDst);
    for (reverseIndex = 1; reverseIndex < pathLength; reverseIndex++)
    {
        current = dirDst[pathLength - reverseIndex];
        if (current == '\\')
        {
            dirDst[pathLength - (reverseIndex - 1)] = '\0';
            reversedName[reverseIndex - 1] = '\0';
            break;
        }
        reversedName[reverseIndex - 1] = current;
    }

    nameLength = strlen(reversedName);
    for (outputIndex = 0; outputIndex < nameLength; outputIndex++)
    {
        fileNameDst[strlen(sCdvdVolumePrefix) + nameLength - outputIndex - 1] =
            reversedName[outputIndex];
    }
    fileNameDst[strlen(sCdvdVolumePrefix) + nameLength] = '\0';
}


#pragma opt_loop_invariants off
/* Removing this loses FUN_00454F50 (MATCH nd0 -> MISMATCH nd29) - measured W161. */

#pragma opt_loop_invariants on
// FUN_00454F50
s32 H_Cdvd_BuildVolumePaths(const char* path, char* fileNameDst, char* dirDst)
{
    char reverseFileName[256];
    char normalizedDir[256];
    u32 pathLength;
    u32 fileNameLength;
    u32 reverseIndex;
    u32 directoryIndex;
    u32 outputIndex;
    char current;

    strcpy(dirDst, path);
    pathLength = strlen(dirDst);
    for (reverseIndex = 1; reverseIndex < pathLength; reverseIndex++)
    {
        current = dirDst[pathLength - reverseIndex];
        if (current == '\\')
        {
            dirDst[pathLength - (reverseIndex - 1)] = '\0';
            reverseFileName[reverseIndex - 1] = '\0';
            break;
        }
        reverseFileName[reverseIndex - 1] = current;
    }

    H_Cdvd_NormalizePath(dirDst, normalizedDir);
    strcpy(fileNameDst, sCdvdVolumePrefix);
    for (directoryIndex = 0; directoryIndex < 0xc8; directoryIndex++)
    {
        if (sCdvdBtlDirectories[directoryIndex][0] == '\0')
        {
            break;
        }
        if (strcmp(sCdvdBtlDirectories[directoryIndex], &normalizedDir[4]) == 0)
        {
            strcpy(fileNameDst, sCdvdBattlePrefix);
        }
    }

    fileNameLength = strlen(reverseFileName);
    for (outputIndex = 0; outputIndex < fileNameLength; outputIndex++)
    {
        fileNameDst[strlen(sCdvdVolumePrefix) + fileNameLength - outputIndex - 1] =
            reverseFileName[outputIndex];
    }
    fileNameDst[strlen(sCdvdVolumePrefix) + fileNameLength] = '\0';
    return 0;
}


#pragma opt_loop_invariants off
/* Removing this loses FUN_00455100 (MATCH nd0 -> MISMATCH nd216) - measured W161. */

#pragma opt_loop_invariants on
// FUN_00455100
void H_Cdvd_NormalizePath(const char* src, char* dst)
{
    s32 scanIndex;
    s32 readIndex;
    s32 writeIndex;
    const char* sourcePtr;
    s32 currChar;

    writeIndex = 0;
    readIndex = 0;
    while (readIndex < 0xfd)
    {
        sourcePtr = src + readIndex;
        currChar = sourcePtr[0];
        if (currChar == '\0')
        {
            dst[writeIndex] = '\0';
            return;
        }

        if (currChar == '.' && sourcePtr[1] == '.' &&
            sourcePtr[2] == '\\')
        {
            goto removeParent;
        }
        if (currChar != '.' || sourcePtr[1] != '.' ||
            sourcePtr[2] != '/')
        {
            goto checkSingle;
        }

removeParent:
        readIndex += 2;
        if (writeIndex > 2)
        {
            for (scanIndex = writeIndex - 2; scanIndex >= 0; scanIndex--)
            {
                if (dst[scanIndex] == '\\' || dst[scanIndex] == '/')
                {
                    writeIndex = scanIndex + 1;
                    break;
                }
            }
        }
        goto advance;

checkSingle:
        if (currChar == '.' && sourcePtr[1] == '\\')
        {
            goto incrementRead;
        }
        if (currChar != '.' || sourcePtr[1] != '/')
        {
            goto writeCharacter;
        }
incrementRead:
        readIndex++;
        goto advance;

writeCharacter:
        dst[writeIndex] = currChar;
        writeIndex++;

advance:
        readIndex++;
    }
}
#pragma opt_loop_invariants off



// FUN_00455230
void func_00455230(const char* dir)
{
    char normalized[256];
    s16 i;
    const char* source;
    const char** command;

    H_Cdvd_NormalizePath(dir, normalized);
    i = 0;
    while (i < 300)
    {
        source = D_007107b0[i];
        if (source[0] == '\0')
        {
            goto secondTable;
        }
        if (strcmp(source, normalized + 4) == 0)
        {
            command = &D_00710800[i];
            do
            {
            } while (func_004f2798(&D_00763e40, *command) != 0);
            return;
        }
        i++;
    }

secondTable:
    i = 0;
    while (i < 300)
    {
        source = D_00711190[i];
        if (source[0] == '\0')
        {
            func_00440b68(D_00711630, normalized + 4);
            return;
        }
        if (strcmp(source, normalized + 4) == 0)
        {
            command = &D_007113e0[i];
            while (true)
            {
                s32 result = func_004f2798(&D_00763e44, *command);
                if (result == 0)
                {
                    return;
                }
                func_00440b68(D_00711648, result);
            }
        }
        i++;
    }
}



// FUN_004553C0
u32 H_Cdvd_IsFileLoaded(HCdvd* cdvd)
{
    return cdvd->readState == 4;
}



// FUN_004553E0
s32 func_004553e0(void* unused, void* slotData, uintptr_t pathOrMode)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;

    (void)unused;
    if (pathOrMode == 1)
    {
        return 2;
    }

    H_Cdvd_BuildPathUppercase((const char*)pathOrMode, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);
    for (i = 0; i < 256; i++)
    {
        if (!D_008c8780[i].isValid)
        {
            continue;
        }
        H_Cdvd_NormalizePath(D_008c8780[i].path, cachePath);
        if (strcmp(cachePath, normalizedPath) == 0)
        {
            memcpy((u8*)slotData + 0x70, &D_008c8780[i], sizeof(HCdvdCache));
            *(u32*)((u8*)slotData + 0x100) = 0;
            *(u64*)((u8*)slotData + 0x00) = *(s32*)((u8*)slotData + 0xfc);
            *(u64*)((u8*)slotData + 0x20) = 0;
            *(u64*)((u8*)slotData + 0x10) = 0;
            *(u32*)((u8*)slotData + 0x30) = 0;
            *(u32*)((u8*)slotData + 0x38) = 2;
            *(u32*)((u8*)slotData + 0x3c) = 1;
            return 1;
        }
    }
    return 2;
}



// FUN_00455520
u32 func_00455520(void* slotData, void* dst, u32 size)
{
    struct HCdvdStreamData
    {
        u8 reserved[0x88];
        u8* fileMemory;
        s32 fileSize;
        s32 fileOffset;
    } *data;
    u32 available;
    u32 amount;

    data = (struct HCdvdStreamData*)((u8*)slotData + 0x70);
    if (data->fileSize > data->fileOffset)
    {
        goto read_file;
    }
    return 0;

read_file:
    available = data->fileSize - data->fileOffset;
    amount = size;
    if (available < amount)
    {
        amount = available;
    }
    memcpy(dst, data->fileMemory + data->fileOffset, amount);
    data->fileOffset += amount;
    return amount;
}



// FUN_004555B0
u32 func_004555b0(void* slotData)
{
    u8* data = (u8*)slotData + 0x70;
    return -(*(s32*)(data + 0x8c) <= *(s32*)(data + 0x90));
}



// FUN_004556F0
void func_004556f0(void* contextData)
{
    HCdvdStreamContext* context = (HCdvdStreamContext*)contextData;
    HCDVD_FREE(context->slots);
}



// FUN_00455720
s32 func_00455720(void* unused, const char* path)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;

    (void)unused;
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);
    for (i = 0; i < 256; i++)
    {
        if (D_008c8780[i].isValid)
        {
            H_Cdvd_NormalizePath(D_008c8780[i].path, cachePath);
            if (strcmp(cachePath, normalizedPath) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}


/* opt_loop_invariants required: normalized_diff 121 without pragma, 0 with;\r\n   volatile readByteSize also required (nd4 without) - measured W121. */
#pragma opt_loop_invariants on

// FUN_00455B70
void func_00455b70(void* requestData)
{
    struct
    {
        char directory[256];
        char fileName[256];
        char entryPath[256];
    } work;
    u32 fileSize;
    u32 offset;
    u32 entryOffset;
    s32 i;
    s32 scan;
    char* cursor;
    char c;
    s32 backslash = '\\';
    s32 slash;
    HCdvdRequestView* request = (HCdvdRequestView*)requestData;

    if (request->fileMode == 0)
    {
        u32 readByteSize;
        u8* fileMemory;

        fileMemory = request->fileMemory;
        readByteSize = *(volatile u32*)&request->readByteSize;
        func_00455d70(requestData, fileMemory, readByteSize, request->path);
        request->archiveFileCount = 1;
        return;
    }

    i = 0;
    goto outer_check;
outer_body:
    c = request->path[i];
    if (c != '\0')
    {
        work.entryPath[i] = c;
    }
    else
    {
        scan = i - 1;
scan_separator:
        cursor = &work.entryPath[scan];
        if (cursor[-1] != backslash)
        {
            goto scan_previous;
        }
        *cursor = '\0';
        goto outer_continue;
scan_previous:
        scan--;
        goto scan_separator;
    }
outer_continue:
    i++;
outer_check:
    if (i < 0x100)
    {
        goto outer_body;
    }
    request->archiveFileCount = 0;
    offset = 0;
    while (true)
    {
        memcpy(work.directory, work.entryPath, 0xfc);
        memcpy(work.fileName, (u8*)request->fileMemory + offset, 0xfc);
        if (work.fileName[0] == '\0')
        {
            return;
        }
        request->archiveFileCount++;
        entryOffset = offset + 0xfc;
        memcpy(&fileSize, (u8*)request->fileMemory + entryOffset, 4);
        offset += 0x100;
        strcat(work.directory, work.fileName);
        {
            char d;
            char* cursor2;
            s32 backslash2;
            s32 slash2;
            s32 j;

            j = 0;
            backslash2 = '\\';
            slash2 = '/';
            while (j < 0xff)
            {
                cursor2 = &work.directory[j];
                d = *cursor2;
                if (d >= 'a' && d <= 'z')
                {
                    *cursor2 = d - 0x20;
                }
                d = *cursor2;
                if (d == '\0')
                {
                    break;
                }
                if (d == slash2)
                {
                    *cursor2 = backslash2;
                }
                j++;
            }
        }
        func_00455d70(requestData, (u8*)request->fileMemory + offset,
                      fileSize, work.directory);
        fileSize = ((s32)(fileSize + 0x3f) / 0x40) * 0x40;
        offset += fileSize;
    }
}
#pragma opt_loop_invariants off



// FUN_00456090
const char* func_00456090(HCdvd* cdvd, s32 entryIndex)
{
    s32 i;
    u8* entry;
    ArchiveEntryHeader header;

    entry = (u8*)cdvd->fileMemory;
    for (i = 0; i < entryIndex; i++)
    {
        memcpy(&header, entry, sizeof(header));
        if (header.fileName[0] == '\0')
        {
            return NULL;
        }
        entry += sizeof(header);
        entry += ((((s32)header.fileSize + 0x3f) / 0x40) * 0x40);
    }
    if (*(char*)entry == '\0')
    {
        return NULL;
    }
    return (const char*)entry;
}



// FUN_00456150
void H_Cdvd_ReadSync(HCdvd* cdvd)
{
    while (true)
    {
        if (!H_Cdvd_IsFileLoaded(cdvd))
        {
            func_00454640();
        }
        else
        {
            break;
        }
    }
}



// FUN_004561A0
void func_004561a0(void* handle, const char* path, s32 synchronous)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    if (synchronous)
    {
        func_0050ff20(handle, fileName);
    }
    else
    {
        func_0050c008(handle, fileName);
    }
}



// FUN_004562E0
void func_004562e0(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];
    void* stream;

    stream = func_004d9020();
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    func_004d6f78(stream, fileName);
    (void)handle;
}



// FUN_00456370
void func_00456370(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    func_004d9020();
    H_Cdvd_BuildPathUppercase(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    func_004d8d30(handle, fileName);
}



// FUN_004568A0
s32 func_004568a0(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_004244c8(D_00711748);
    amount = sceRead(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(u32*)((u8*)slot + 0x38) = 3;
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}



// FUN_00456930
s32 func_00456930(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_004244c8(D_00711758);
    amount = sceWrite(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}



// FUN_004569C0
void func_004569c0(void* resultData, void* slot, s32 amount, s32 mode)
{
    typedef struct
    {
        u8 reserved00[0x10];
        HCdvdStreamPosition position;
    } HCdvdSeekSlot;
    HCdvdStreamPosition* result = (HCdvdStreamPosition*)resultData;
    HCdvdSeekSlot* seekSlot = (HCdvdSeekSlot*)slot;

    func_004244c8("CDVD seek");
    if (mode == 3)
    {
        goto mode3;
    }
    if (mode == 2)
    {
        goto mode2;
    }
    switch (mode)
    {
    case 1:
        goto mode1;
    default:
        goto invalid;
    }

mode1:
    seekSlot->position.position = amount;
    goto common;
mode2:
    seekSlot->position.position += amount;
    goto common;
mode3:
    seekSlot->position.position -= amount;
    goto common;
invalid:
    seekSlot->position.position = -1;
    *(long128*)resultData = *(long128*)&seekSlot->position;
    return;

common:
    if (seekSlot->position.position < 0)
    {
        seekSlot->position.position = 0;
    }
    {
        s32 offset;
        s32 fd;
        func_004270f8(
            (offset = *(s32*)((u8*)slot + 0x10),
             fd = *(s32*)((u8*)slot + 0x74), fd),
            offset, 0);
    }
    *(long128*)resultData = *(long128*)&seekSlot->position;
}



// FUN_00456AE0
INCLUDE_ASM("asm/nonmatchings/h_cdvd", func_00456ae0);
// FUN_00456b70
void* func_00456b70(void* contextData, u32 index)
{
    s32 i = index;
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;

    func_004244c8(D_00711780);
    if (i < context->count)
    {
        return context->slots + i * 0x90;
    }
    return NULL;
}



// FUN_00456BE0
void func_00456be0(void* contextData)
{
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;
    func_004244c8(D_007117a0);
    HCDVD_FREE(context->slots);
}
