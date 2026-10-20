/* Original translation unit sdkCdvd.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 D_008C0680[];
extern u8 D_008C0780[];
extern u8 D_008C0880[];
extern u8 D_005BC790[];
void H_Cdvd_BuildPathUppercase(void* src, void* dst);
void H_Cdvd_SplitPath(void* path, void* fileNameDst, void* dirDst);
s32 func_004c74f8(void* a0, void* a1, void* a2, void* a3);
void memcpy(void* dst, void* src, u32 size);
/* Fixed stream device and 0x110-byte per-channel storage initialized below. */
typedef struct HCdvdStreamSlot {
    u8 pad00[0x50];
    u8 *device;
    u8 pad54[0x14];
    u8 *buffer;
    s32 bufferSize;
    u8 pad70[0xA0];
} HCdvdStreamSlot;

typedef struct HCdvdStreamDevice {
    u8 pad00[0x14];
    void *getSlot, *freeContext;
    u8 pad1C[0xC];
    void *attachCache, *close, *read;
    u8 pad34[4];
    void *seek;
    u8 pad3C[8];
    void *atEnd;
    u8 pad48[4];
    void *isCached;
    u8 pad50[8];
    u8 *slots;
} HCdvdStreamDevice;

typedef struct HCdvdArchiveHeader {
    u8 pad00[0xFC];
    s32 size;
} HCdvdArchiveHeader;

typedef void *ADXF;

typedef struct HCdvd {
    struct HCdvd *prev;          /* 0x000 */
    struct HCdvd *next;          /* 0x004 */
    s32 hasExternalMemory;       /* 0x008 */
    s32 readState;               /* 0x00C */
    char path[0x100];            /* 0x010 */
    void *fileMemory;            /* 0x110 */
    void *unalignedFileMemory;   /* 0x114 */
    s32 fileSize;                /* 0x118 */
    s32 unk11C;                  /* 0x11C */
    s32 unk120;                  /* 0x120 */
    s32 readByteSize;            /* 0x124 */
    u8 unk128[0x28];             /* 0x128 */
    s32 flags;                  /* 0x150 */
    ADXF adxf;                   /* 0x154 */
    char fileName[0x100];        /* 0x158 */
    u8 dir[0x102];               /* 0x258 */
    s16 refCount;                /* 0x35A */
    s16 pendingDestroyCount;     /* 0x35C */
    s16 readPollCount;           /* 0x35E */
    u16 unk360;
    s16 classes;                /* 0x362 */
} HCdvd;                         /* 0x364 allocation */

typedef struct HCdvdCache {
    s32 isValid;                 /* 0x00 */
    s32 *requestData;            /* 0x04 */
    u8 name[0x80];             /* 0x08 */
    s32 value;                 /* 0x88 */
    s32 slot;                  /* 0x8C */
    s32 unk90;                 /* 0x90 */
} HCdvdCache;                    /* 0x94 */

extern HCdvdCache D_008C8780[];
extern u8 D_008C8784[];
extern u8 D_008C8808[];
extern u8 D_008C880C[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_00710870[];
void kAssertFailAt(const void* msg, const void* file, u32 line);
void chkmemAllocSiteTag(const void* file, s32 line);
void H_Cdvd_NormalizePath(void* src, void* dst);
s32 strcmp(void* a0, void* a1);
void H_Dbprt_FmtLog(void* a0, void* a1);
void func_00440b68();
s16 chkmemGetClasses(void);
void H_Cdvd_BuildVolumePaths(void* path, void* fileNameDst, void* dirDst);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_008D1B80[];
extern u8* D_008D1B84[];
extern char D_00710900[];
extern char D_00710910[];

/* Measured: 1052/1056 bytes, 46 resolved relocations, four zero tail bytes.
 * Typed cache indexing gives the retail request/base hoist order; an explicit
 * base initializer leaves three words different. The compound refCount -=
 * preserves the RHS-first loads and store before the signed comparison. */
// Intent: per-frame step of the CD request list. Advances each node's read state (open, read blocks, parse the archive) and destroys nodes whose reference count drops to zero.
// FUN_00454640
#pragma push
#pragma opt_loop_invariants on
void H_Cdvd_UpdateRequests(void)
{
    extern void sdkPakUpdateDirectoryLoads(void);
    extern void movieLoadStep(void);
    extern void H_Cdvd_SelectDirectory(void *dir);
    extern void H_Cdvd_ParseArchive(void *requestData);
    extern ADXF func_004c85a0(void *name, s32 mode);
    extern void func_004c8a60(ADXF handle);
    extern s32 func_004c9010(ADXF handle, s32 count, void *buffer);
    extern s32 func_004c95f8(ADXF handle);
    extern s32 func_004c9670(ADXF handle);
    extern s32 func_004c9820(ADXF handle);
    extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
    extern void (*jtbl_008873EC[])(void *ptr);
    extern char D_00710880[];
    extern char D_007108A0[];
    extern char D_007108C0[];
    extern char D_007108E0[];
    HCdvd *node;
    HCdvd *next;
    HCdvd *prev;
    HCdvd *link;
    HCdvdCache *slot;
    ADXF handle;
    s32 offset;
    s32 buffer;
    s32 blocks;
    s32 aligned;
    s32 spare;
    s32 state;
    s16 i;

    sdkPakUpdateDirectoryLoads();
    movieLoadStep();
    node = (HCdvd *)D_008D1B84[0];
    if (node == NULL) {
        return;
    }
loop:
    if (node->readState != 4) {
        switch (node->readState) {
        case 0:
            node->readPollCount = 0;
            H_Cdvd_SelectDirectory(node->dir);
            node->adxf = func_004c85a0(node->fileName, 0);
            handle = node->adxf;
            if (handle == NULL) {
                goto tail;
            }
            offset = func_004c9670(handle);
            node->readByteSize = offset;
            node->fileSize = offset;
            node->readState = 1;
        case 1:
            if (node->fileMemory == NULL) {
                chkmemAllocSiteTag(D_00710870, 0xFA);
                buffer = (s32)(*jtbl_008873E8)(
                    ((u32)func_004c95f8(node->adxf) << 0xB) + 0x40U, 0x40000);
                node->unalignedFileMemory = (void *)buffer;
                if (buffer == 0) {
                    kAssertFailAt(D_00710880, D_00710870, 0xFF);
                    return;
                }
                aligned = buffer / 0x40 * 0x40;
                spare = buffer % 0x40;
                if (spare != 0) {
                    aligned = (s32)((u32)aligned + 0x40U);
                }
                node->fileMemory = (void *)aligned;
            }
            blocks = func_004c9010(node->adxf,
                                   func_004c95f8(node->adxf),
                                   node->fileMemory);
            if (blocks != func_004c95f8(node->adxf)) {
                func_004c8a60(node->adxf);
                node->adxf = NULL;
                if (node->hasExternalMemory == 0) {
                    (*jtbl_008873EC)(node->unalignedFileMemory);
                    node->fileMemory = NULL;
                    node->unalignedFileMemory = NULL;
                }
                node->readState = 0;
                goto tail;
            }
            node->readState = 2;
        case 2:
            node->readPollCount = (s16)(node->readPollCount + 1);
            state = func_004c9820(node->adxf);
            if (state == 3) {
                node->readState = 3;
                goto do_state3;
            }
            {
                if (state == 4) {
                    func_00440b68(D_007108A0);
                    func_004c8a60(node->adxf);
                    node->adxf = NULL;
                    node->readState = 0;
                    if (node->hasExternalMemory == 0) {
                        (*jtbl_008873EC)(node->unalignedFileMemory);
                        node->fileMemory = NULL;
                        node->unalignedFileMemory = NULL;
                    }
                    return;
                }
                goto tail;
            }
do_state3:
        case 3:
            H_Cdvd_ParseArchive(&node->hasExternalMemory);
            node->readState = 4;
            func_004c8a60(node->adxf);
            node->adxf = NULL;
            func_00440b68(D_007108C0, node->path);
            goto tail;
        }
        goto tail;
    }
tail:
    if (node->readState == 4) {
        next = node->next;
        node->refCount -= node->pendingDestroyCount;
        if (node->refCount < 0) {
            func_00440b68(D_007108E0);
        }
        node->pendingDestroyCount = 0;
        if (node->refCount <= 0) {
            prev = node->prev;
            link = node->next;
            prev->next = link;
            if (link != NULL) {
                link->prev = prev;
            }
            if (node->fileMemory != NULL && node->hasExternalMemory == 0) {
                (*jtbl_008873EC)(node->unalignedFileMemory);
                node->fileMemory = NULL;
                node->unalignedFileMemory = NULL;
            }
            for (i = 0; i < 0x100; i++) {
                slot = &D_008C8780[i];
                if (slot->isValid != 0 && slot->requestData == &node->hasExternalMemory) {
                    slot->isValid = 0;
                }
            }
            handle = node->adxf;
            if (handle != NULL) {
                func_004c8a60(handle);
                node->adxf = NULL;
            }
            (*jtbl_008873EC)(node);
        }
        node = next;
        if (next != NULL) {
            goto loop;
        }
    }
}
#pragma pop

// Intent: returns the directory node for `arg0`, creating it when needed, and takes a reference on it.
/* HCdvd proves these request links and path buffers; retain byte accesses
 * because the typed pointer rewrite changed the measured matching codegen. */
// FUN_00454A60
u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags) {
    u8 normalizedPath[0x100];
    u8* node;
    u8* newNode;

    H_Dbprt_FmtLog(D_00710900, path);
    node = D_008D1B80;
    H_Cdvd_BuildPathUppercase(path, normalizedPath);
    func_00440b68(D_00710910, path);
    if (D_008D1B84[0] != NULL) {
        while (1) {
            if (strcmp(normalizedPath, node + 0x10) == 0) {
                ((HCdvd *)node)->refCount = (s16)(((HCdvd *)node)->refCount + 1);
                return node;
            }
            if (*(u8**)(node + 4) == NULL) {
                break;
            }
            node = *(u8**)(node + 4);
        }
    }
    chkmemAllocSiteTag(D_00710870, 0x198);
    newNode = D_008873F4[0](1, 0x364, 0x40000);
    H_Cdvd_BuildPathUppercase(path, newNode + 0x10);
    H_Cdvd_BuildVolumePaths(newNode + 0x10, newNode + 0x158, newNode + 0x258);
    ((HCdvd *)newNode)->readState = 0;
    *(u8**)(node + 4) = newNode;
    *(u8**)(newNode + 0) = node;
    *(s32*)(newNode + 4) = 0;
    *(s32*)(newNode + 0x110) = 0;
    ((HCdvd *)newNode)->hasExternalMemory = 0;
    ((HCdvd *)newNode)->flags = flags;
    ((HCdvd *)newNode)->refCount = 1;
    *(s32*)(newNode + 0x154) = 0;
    ((HCdvd *)newNode)->classes = chkmemGetClasses();
    return newNode;
}

// Intent: stream close callback. Nothing to release.
// FUN_00455510
void H_Cdvd_StreamCloseNoop(void) {
}

/* measured: long128 local with s64 position; reload the just-stored s32
   fileOffset into out.position so the compiler's lw sign-extend feeds the
   sd/lq/sq without a separate dsll32/dsrl32 pair. u32 arithmetic for sltu. */
// Intent: stream seek by mode. Modes 1 and 2 move forward from the current offset; mode 3 seeks from the end. Writes the new position to `resultData`.
// FUN_004555D0
void H_Cdvd_StreamSeek(void* resultData, void* slotData, s32 amount, s32 mode)
{
    typedef signed __int128 long128;
    struct HCdvdStreamData
    {
        u8 reserved[0x88];
        u8* fileMemory;
        s32 fileSize;
        s32 fileOffset;
    } *data;
    struct HCdvdStreamPosition
    {
        s64 position;
        u32 unused0;
        u32 unused1;
    } out;

    data = (struct HCdvdStreamData*)((u8*)slotData + 0x70);
    if (mode == 1) {
        u32 newOffset;
        newOffset = (u32)data->fileOffset + (u32)amount;
        if ((u32)data->fileSize < newOffset) {
            newOffset = (u32)data->fileSize;
        }
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else if (mode == 2) {
        u32 newOffset;
        if ((u32)data->fileSize < (u32)amount) {
            amount = data->fileSize;
        }
        newOffset = (u32)data->fileOffset + (u32)amount;
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else if (mode == 3) {
        u32 newOffset;
        newOffset = (u32)data->fileSize + (u32)amount;
        if ((u32)data->fileSize < newOffset) {
            newOffset = (u32)data->fileSize - 1;
        }
        data->fileOffset = newOffset;
        out.position = data->fileOffset;
        *(long128*)resultData = *(long128*)&out;
    } else {
        out.position = 1;
        *(long128*)resultData = *(long128*)&out;
    }
}

s32 func_003dd900(s32 a0);
void chkmemAllocSiteTag(const void* file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void H_Cdvd_StreamGetSlot(void);
extern void H_Cdvd_StreamContextFree(void);
extern void H_Cdvd_StreamAttachCacheEntry(void);
extern void H_Cdvd_StreamReadChunk(void);
extern void H_Cdvd_StreamAtEnd(void);
extern void H_Cdvd_IsCached(void);
extern char D_00711658[];
s32 func_003dd290(void* a0, s32 a1, s32 a2, s32 a3);
void func_003dd760(s32 a0);
void* func_003dea20(s32 a0, void* a1, s32 a2, void* a3, void* a4);
s32 func_003dd830(void* a0);
void func_003ddde0(void* a0);
void* H_Cdvd_CreateFileDevice(s32 slotCount, void* buffer, s32 bufferSize, void* deviceFlags, void* deviceId);
extern void (*D_008873AC[])(void*, void*);
extern char D_00711670[];
extern char D_00711690[];
extern char D_007116B0[];
extern u8 D_008C5F80[];
extern u8 D_008C3780[];
extern u8 D_008C0F80[];
extern u8 iGpffffba40;
extern u8 iGpffffba38;
extern u8 iGpffffad60;
extern u8 iGpffffad58;
extern u8 iGpffffad68;
extern u8 iGpffffad70;
extern u8 iGpffffad78;
extern u8 iGpffffad80;
extern s32 iGpffffbaa0;

// Intent: creates a stream device with `arg0` entries of `arg2` bytes each, starting at `arg1`, and registers its callbacks. Returns the device record.
// FUN_004557E0
/* measured: D_008873F4 is a function-pointer table; retail hoists the TABLE
   ADDRESS into $s0 (lui/addiu) and loads the function pointer per call
   (lw $v0,($s0); jalr $v0). Achieved with an integer-cast base local
   (u32 base = (u32)D_008873F4), and context/owner declared s32 (not u8*) — the
   pointer arg types mis-coloured device/owner ($s1/$s2 swap, nd 8). */
u8* H_Cdvd_CreateStreamDevice(s32 slotCount, u8* buffer, s32 slotSize, s32 context, s32 owner) {
    u8* device;
    u32 base;
    u8* slots;
    s32 i;

    if (func_003dd900(owner) != 0) {
        return NULL;
    }
    chkmemAllocSiteTag(D_00710870, 0x425);
    base = (u32)D_008873F4;
    device = ((u8* (*)(s32, s32, s32))*(u32*)base)(1, 0x5C, 0x40000);
    ((HCdvdStreamDevice *)device)->getSlot = &H_Cdvd_StreamGetSlot;
    ((HCdvdStreamDevice *)device)->freeContext = &H_Cdvd_StreamContextFree;
    ((HCdvdStreamDevice *)device)->attachCache = &H_Cdvd_StreamAttachCacheEntry;
    ((HCdvdStreamDevice *)device)->close = &H_Cdvd_StreamCloseNoop;
    ((HCdvdStreamDevice *)device)->read = &H_Cdvd_StreamReadChunk;
    ((HCdvdStreamDevice *)device)->atEnd = &H_Cdvd_StreamAtEnd;
    ((HCdvdStreamDevice *)device)->seek = &H_Cdvd_StreamSeek;
    ((HCdvdStreamDevice *)device)->isCached = &H_Cdvd_IsCached;
    chkmemAllocSiteTag(D_00710870, 0x430);
    slots = ((u8* (*)(s32, s32, s32))*(u32*)base)(slotCount, 0x110, 0x40000);
    ((HCdvdStreamDevice *)device)->slots = slots;
    for (i = 0; i < slotCount; i++) {
        ((HCdvdStreamSlot *)slots)[i].device = device;
        ((HCdvdStreamSlot *)slots)[i].buffer = buffer + i * slotSize;
        ((HCdvdStreamSlot *)slots)[i].bufferSize = slotSize;
    }
    if (func_003dd290(device, slotCount, owner, context) != 1) {
        kAssertFailAt(D_00711658, D_00710870, 0x441);
    }
    return device;
}

/* measured: opt_propagation off keeps the D_008873AC table address hoisted in
   $s0 across the first four calls and the final pair after $s0 is reused for
   the func_004557e0 result; the outer NULL check is written as an
   assignment-in-condition with an explicit `else { return; }` to place the
   shared return block at .L00455A4C; a block-scope extern of func_004557e0
   with u8* 4th/5th parameters makes the call materialise a0,a1,a2,a3,t0
   left-to-right, while the function still sees the address bits as s32. */
#pragma opt_propagation off
// Intent: initialises the CD devices (the file device, the stream device and the sound slots), then sets the ready flag.
// FUN_004559B0
void H_Cdvd_InitDevices(void) {
    void (**base)(void*, void*);
    u8* fileDevice;
    u8* streamDevice;

    func_003dd760(-1);
    base = D_008873AC;
    base[0](&iGpffffba40, &iGpffffad60);
    base[0](&iGpffffba38, &iGpffffad68);
    if ((fileDevice = func_003dea20(5, D_008C5F80, 0x800, &iGpffffba40, &iGpffffba38)) != NULL) {
        if (func_003dd830(fileDevice) == 0) {
            func_00440b68(D_00711670);
            return;
        }
    } else {
        return;
    }
    base[0](&iGpffffba40, &iGpffffad58);
    base[0](&iGpffffba38, &iGpffffad70);
    {
        extern u8* H_Cdvd_CreateStreamDevice(s32, u8*, s32, u8*, u8*);
        streamDevice = H_Cdvd_CreateStreamDevice(5, D_008C3780, 0x800, &iGpffffba40, &iGpffffba38);
    }
    if (func_003dd830(streamDevice) == 0) {
        func_00440b68(D_00711690);
    } else {
        func_003ddde0(streamDevice);
    }
    base = D_008873AC;
    base[0](&iGpffffba40, &iGpffffad78);
    base[0](&iGpffffba38, &iGpffffad80);
    if (func_003dd830(H_Cdvd_CreateFileDevice(5, D_008C0F80, 0x800, &iGpffffba40, &iGpffffba38)) == 0) {
        func_00440b68(D_007116B0);
    }
    iGpffffbaa0 = 1;
}
/* measured: restores default propagation after func_004559b0. */
#pragma opt_propagation on

extern u8 D_008C8784[];
extern u8 D_008C8810[];
extern char D_007116D0[];
extern char D_007116F0[];
extern char D_00710870[];
void kAssertFailAt(const void* msg, const void* file, u32 line);

// Intent: stores a request record (three words and a 0x80-byte name) in the first free request slot. Asserts when the table is full.
// FUN_00455D70
void H_Cdvd_RegisterRequest(u8* request, u8* value, u8* slot, u8* name) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_008C8780[i].isValid == 0) {
            D_008C8780[i].isValid = 1;
            D_008C8780[i].requestData = (s32 *)request;
            D_008C8780[i].value = (s32)value;
            D_008C8780[i].slot = (s32)slot;
            D_008C8780[i].unk90 = 0;
            memcpy(D_008C8780[i].name, name, 0x80);
            return;
        }
        if (i == 0xFF) {
            kAssertFailAt(D_007116D0, D_00710870, 0x4E7);
        }
    }
}

/* measured: the rounded advance is a signed `/ 64 * 64` (retail sra + bgez
   fix-up), and it must be a SECOND `+=` after `entry += 0x100`: one combined
   expression colours the base into $v1 and the fix-up into $v0, the split
   keeps entry+0x100 in $a0 and size+0x3f in $v1 as retail. */
// Intent: returns the data of archive entry `arg1` and writes its length to `arg2`, or to a local when `arg2` is null.
// FUN_00455EA0
u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size) {
    u8 header[0x100];
    s32 localSize;
    s32 i;
    u8 *entry;

    if (size == NULL) {
        size = &localSize;
    }
    entry = (u8 *)((HCdvd *)request)->fileMemory;
    for (i = 0; i < entryIndex; i++) {
        memcpy(header, entry, 0x100);
        entry += 0x100;
        entry += ((((HCdvdArchiveHeader *)header)->size + 0x3F) / 64) * 64;
    }
    memcpy(header, entry, 0x100);
    *size = ((HCdvdArchiveHeader *)header)->size;
    return entry + 0x100;
}
// Intent: finds the registered request whose normalised path matches `arg0`. Writes its slot to `arg1` and returns its value, or 0 when none matches.
// FUN_00455F70
s32 H_Cdvd_LookupRequest(s32 pathAddress, s32* slot) {
    u8 uppercasePath[0x100];
    u8 normalizedPath[0x100];
    u8 normalizedEntry[0x100];
    s32 localSlot;
    s32 i;

    if (slot == NULL) {
        slot = &localSlot;
    }
    if (pathAddress == 1) {
        return 0;
    }
    H_Cdvd_BuildPathUppercase((void*)pathAddress, uppercasePath);
    H_Cdvd_NormalizePath(uppercasePath, normalizedPath);
    for (i = 0; i < 0x100; i++) {
        if (D_008C8780[i].isValid != 0) {
            H_Cdvd_NormalizePath(D_008C8780[i].name, normalizedEntry);
            if (strcmp(normalizedEntry, normalizedPath) == 0) {
                *slot = D_008C8780[i].slot;
                return D_008C8780[i].value;
            }
        }
    }
    return 0;
}

// Intent: starts a stream load of path `arg1` on channel `arg0`, reporting completion through `arg3`. Returns 0.
// FUN_00456250
s32 H_Cdvd_StartStreamLoad(s32 channel, void* path, s32 flags, void* completion) {
    H_Cdvd_BuildPathUppercase(path, D_008C0680);
    H_Cdvd_SplitPath(D_008C0680, D_008C0780, D_008C0880);
    func_004c74f8((void*)channel, D_008C0780, D_005BC790, completion);
    return 0;
}

// Intent: stores an archive entry record (three words and a 0x80-byte name) in the first free request slot. Asserts when the table is full.
// FUN_00456400
void H_Cdvd_RegisterArchiveEntry(s32 requestAddress, s32 value, s32 slot, u8* name) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        if (D_008C8780[i].isValid == 0) {
            D_008C8780[i].isValid = 1;
            D_008C8780[i].requestData = (s32 *)requestAddress;
            D_008C8780[i].value = value;
            D_008C8780[i].slot = slot;
            D_008C8780[i].unk90 = 0;
            memcpy(D_008C8780[i].name, name, 0x80);
            return;
        }
        if (i == 0xFF) {
            kAssertFailAt(D_007116F0, D_00710870, 0x5FF);
        }
    }
}

