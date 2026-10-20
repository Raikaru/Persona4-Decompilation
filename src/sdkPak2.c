#include "include_asm.h"
/* Persona 4 USA decompilation - sdkPak2.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
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

/* Advances linked package directory requests through open, header, allocation and read states. */
/* measured: remaining field accesses retain alias-dependent retail instructions. Sector-directory and destination-slot cursors preserve the measured index-first address arithmetic. */
// FUN_00468A50
/* Case values decoded from jtbl_007566D0 with tools/jtbl.py: a 0..6 state
   machine where 1->2->3->5->6 fall through and case 4 plus the out-of-range
   default just re-run the loop test. Three things were needed on top of the
   case order: a do/while (retail knows D_00922980 is non-NULL and enters at
   the top), gotos so each failure path's `p = NULL` lands out of line after
   its own case body as retail places it, and NOT naming the
   *(*(p+0x21C)+4) load in a local -- retail reloads it for the size
   computation after storing it to +0xC, and a named temp CSEs the two. */
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

/* measured: keeping `idx = base + count; idx = idx * 4;` followed by the
   explicit `idxp = (u8 *)idx` forces b210 to emit the retail shift before
   the table loads and preserves the retail addu order. The candidate is
   byte-exact (object/window 288B); prior declaration-order, integer-cast,
   address-taken-index, table-declaration, and pragma probes were ruled out. */
/* Uses adjacent sector offsets to allocate and start the next package-entry read. */
/* measured: remaining field accesses retain alias-dependent retail instructions. Sector-directory and destination-slot cursors preserve the measured index-first address arithmetic. */
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

