#include "include_asm.h"
/* Original translation unit sdkPak2.c (from __FILE__ assert strings). */
#include "type.h"
#include "member_access.h"
/* The loader reads a count from header +4, then a sector-offset directory.
 * The path span ends at the handle at +0x218. Unknown words retain offsets. */
typedef struct SdkPakHeader {
    s32 unk0;
    s32 entryCount;
} SdkPakHeader;

typedef struct SdkPakRequest {
    u8 *unk0;
    u8 *next;
    s32 state;
    s32 entryCount;
    s32 directoryAddress;
    s32 unk14;
    u8 path[0x200];
    s32 handle;
    s32 headerAddress;
} SdkPakRequest;

typedef struct SdkPakReader {
    u8 pad0[8];
    u8 *package;
    u8 padC[4];
    s32 handles[10];
    u8 *buffers;
    s32 firstEntry;
    s32 lastEntry;
    s32 nextEntry;
} SdkPakReader;

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern s32 func_004c8708(u8 *, s32 , s32 , s32 );
extern s32 chkmemAllocAligned(s32 size, s32 alignment, s32 flags);
extern void func_004c9010(s32 , s32 , s32 );
extern s32 func_004c85a0(u8 *, s32 );
extern s32 func_004c9820(s32 );
extern void func_004c8a60(s32 );
extern u8 D_00922980[];
extern u8 D_00712AC0[];

/* Advances linked package directory requests through open, header, allocation and read states.
 * measured: retail keeps alias-dependent field reloads and index-first address arithmetic for the
 * sector-directory and destination-slot cursors. */
// FUN_00468A50
/* State machine 0..6: states 1->2->3->5->6 fall through, and state 4 and out-of-range values just
 * re-test the loop. The +0x21C entry-count load is reloaded, not cached. */
void sdkPakUpdateDirectoryLoads(void) {
    u8 *request;
    s32 sectorCount;

    request = D_00922980;
    do {
        switch ((u32)((SdkPakRequest *)request)->state) {
        case 0:
            request = ((SdkPakRequest *)request)->next;
            break;
        case 1:
            ((SdkPakRequest *)request)->handle = func_004c85a0(request + 0x18, 0);
            MEMBER(s32, request, SdkPakRequest, state) = 2;
        case 2:
            func_004c9010(((SdkPakRequest *)request)->handle, 1, ((SdkPakRequest *)request)->headerAddress);
            MEMBER(s32, request, SdkPakRequest, state) = 3;
        case 3:
            if (func_004c9820(((SdkPakRequest *)request)->handle) != 3) {
                goto fail3;
            }
            ((SdkPakRequest *)request)->entryCount = ((SdkPakHeader *)((SdkPakRequest *)request)->headerAddress)->entryCount;
            sectorCount = (((SdkPakHeader *)((SdkPakRequest *)request)->headerAddress)->entryCount * 4 + 0x7FF) / 0x800;
            chkmemAllocSiteTag(D_00712AC0, 0x63);
            ((SdkPakRequest *)request)->directoryAddress = chkmemAllocAligned(sectorCount << 11, 0x40, 0x40000);
            func_004c9010(MEMBER(s32, request, SdkPakRequest, handle), sectorCount, MEMBER(s32, request, SdkPakRequest, directoryAddress));
            MEMBER(s32, request, SdkPakRequest, state) = 5;
            goto case5;
fail3:
            request = NULL;
            break;
case5:
        case 5:
            if (func_004c9820(((SdkPakRequest *)request)->handle) != 3) {
                goto fail5;
            }
            func_004c8a60(MEMBER(s32, request, SdkPakRequest, handle));
            MEMBER(s32, request, SdkPakRequest, handle) = 0;
            MEMBER(s32, request, SdkPakRequest, state) = 6;
            goto case6;
fail5:
            request = NULL;
            break;
case6:
        case 6:
            request = ((SdkPakRequest *)request)->next;
            if (request == NULL) {
                return;
            }
            break;
        case 4:
            break;
        }
    } while (request != NULL);
}

/* Computing idx = base + count, scaling by 4, then casting to a pointer keeps retail's shift-
 * before-load and add order. */
// FUN_00468BF0
s32 sdkPakStartEntryLoad(u8 *reader, s32 handleIndex)
{
    SdkPakReader *typedReader = (SdkPakReader *)reader;
    s32 firstEntry;
    s32 entryIndex;
    s32 sectorCount;
    s32 directoryOffset;
    u8 *handleSlot;
    u8 *package;
    u8 *directoryCursor;

    firstEntry = ((SdkPakReader *)reader)->firstEntry;
    entryIndex = ((SdkPakReader *)reader)->nextEntry;
    if (entryIndex < ((SdkPakReader *)reader)->lastEntry - firstEntry + 1) {
        directoryOffset = firstEntry + entryIndex;
        directoryOffset = directoryOffset * 4;
        directoryCursor = (u8 *)directoryOffset;
        package = ((SdkPakReader *)reader)->package;
        sectorCount = ((s32 *)(directoryCursor + (u32)(u8 *)((SdkPakRequest *)package)->directoryAddress))[2] -
              ((s32 *)(directoryCursor + (u32)*(u8* *)&((SdkPakRequest *)package)->directoryAddress))[1];
        if (sectorCount != 0) {
            handleSlot = (u8 *)(handleIndex * 4) + (u32)reader + 0x10;
            *(s32 *)handleSlot = func_004c8708(
                package + 0x18, 0,
                ((s32 *)(directoryCursor + (u32)(u8 *)((SdkPakRequest *)package)->directoryAddress))[1], sectorCount);
            chkmemAllocSiteTag(D_00712AC0, 0xC7);
            ((s32 *)typedReader->buffers)[typedReader->nextEntry] =
                chkmemAllocAligned(sectorCount << 11, 0x40, 0x40000);
            func_004c9010(*(s32 *)handleSlot, sectorCount,
                          ((s32 *)((SdkPakReader *)reader)->buffers)[typedReader->nextEntry]);
        }
        typedReader->nextEntry = typedReader->nextEntry + 1;
        return 1;
    }
    return 0;
}

