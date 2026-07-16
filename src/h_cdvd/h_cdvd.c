/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00454570)
/* Source unit: src/h_cdvd/h_cdvd_00454570.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_00454570
u32 func_00454570(const char* path)
{
    char unusedUppercasePath[256];
    char fileName[256];
    char directory[256];
    char uppercasePath[256];
    ADXF adxf;

    func_00440b68(" Exist %s\n", path);
    func_00454d20(path, unusedUppercasePath);
    func_00454d20(path, uppercasePath);
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
#endif /* P4_UNIT_00454570 */

#if defined(P4_UNIT_004553C0)
/* Source unit: src/h_cdvd/h_cdvd_004553c0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_004553C0
u32 func_004553c0(HCdvd* cdvd)
{
    return cdvd->readState == 4;
}
#endif /* P4_UNIT_004553C0 */

#if defined(P4_UNIT_00455520)
/* Source unit: src/h_cdvd/h_cdvd_00455520.c (1 function markers) */
#include "h_cdvd_internal.h"

extern void func_0043f810(void* destination, const void* source, u32 size);

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
    func_0043f810(dst, data->fileMemory + data->fileOffset, amount);
    data->fileOffset += amount;
    return amount;
}
#endif /* P4_UNIT_00455520 */

#if defined(P4_UNIT_004555B0)
/* Source unit: src/h_cdvd/h_cdvd_004555b0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_004555B0
u32 func_004555b0(void* slotData)
{
    u8* data = (u8*)slotData + 0x70;
    return -(*(s32*)(data + 0x8c) <= *(s32*)(data + 0x90));
}
#endif /* P4_UNIT_004555B0 */

#if defined(P4_UNIT_004556F0)
/* Source unit: src/h_cdvd/h_cdvd_004556f0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_004556F0
void func_004556f0(void* contextData)
{
    HCdvdStreamContext* context = (HCdvdStreamContext*)contextData;
    HCDVD_FREE(context->slots);
}
#endif /* P4_UNIT_004556F0 */

#if defined(P4_UNIT_00455720)
/* Source unit: src/h_cdvd/h_cdvd_00455720.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_00455720
s32 func_00455720(void* unused, const char* path)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;

    (void)unused;
    func_00454d20(path, uppercasePath);
    func_00455100(uppercasePath, normalizedPath);
    for (i = 0; i < 256; i++)
    {
        if (D_008c8780[i].isValid)
        {
            func_00455100(D_008c8780[i].path, cachePath);
            if (func_004426e8(cachePath, normalizedPath) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
#endif /* P4_UNIT_00455720 */

#if defined(P4_UNIT_00456150)
/* Source unit: src/h_cdvd/h_cdvd_00456150.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_00456150
void func_00456150(HCdvd* cdvd)
{
    while (true)
    {
        if (!func_004553c0(cdvd))
        {
            func_00454640();
        }
        else
        {
            break;
        }
    }
}
#endif /* P4_UNIT_00456150 */

#if defined(P4_UNIT_004561A0)
/* Source unit: src/h_cdvd/h_cdvd_004561a0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_004561A0
void func_004561a0(void* handle, const char* path, s32 synchronous)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    func_00454d20(path, uppercasePath);
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
#endif /* P4_UNIT_004561A0 */

#if defined(P4_UNIT_004562E0)
/* Source unit: src/h_cdvd/h_cdvd_004562e0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_004562E0
void func_004562e0(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];
    void* stream;

    stream = func_004d9020();
    func_00454d20(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    func_004d6f78(stream, fileName);
    (void)handle;
}
#endif /* P4_UNIT_004562E0 */

#if defined(P4_UNIT_004568A0)
/* Source unit: src/h_cdvd/h_cdvd_004568a0.c (1 function markers) */
#include "h_cdvd_internal.h"

extern const char D_00711748[];
extern s32 sceRead(s32 fd, void* dst, u32 size);

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
#endif /* P4_UNIT_004568A0 */

#if defined(P4_UNIT_00456930)
/* Source unit: src/h_cdvd/h_cdvd_00456930.c (1 function markers) */
#include "h_cdvd_internal.h"

extern const char D_00711758[];
extern s32 sceWrite(s32 fd, void* dst, u32 size);

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
#endif /* P4_UNIT_00456930 */

#if defined(P4_UNIT_00456B70)
/* Source unit: src/h_cdvd/h_cdvd_00456b70.c (1 function markers) */
#include "h_cdvd_internal.h"

extern const char D_00711780[];

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
#endif /* P4_UNIT_00456B70 */

#if defined(P4_UNIT_00456BE0)
/* Source unit: src/h_cdvd/h_cdvd_00456be0.c (1 function markers) */
#include "h_cdvd_internal.h"

// FUN_00456BE0
void func_00456be0(void* contextData)
{
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;
    func_004244c8(D_007117a0);
    HCDVD_FREE(context->slots);
}
#endif /* P4_UNIT_00456BE0 */
