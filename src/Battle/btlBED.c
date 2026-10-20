/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef struct BtlBedWork BtlBedWork;
struct BtlBedWork
{
    u8 pad[0x630];
    u16 flags;      // 0x630
    u16 count;      // 0x632
    u32 savedRecord;   // 0x634
};

typedef struct BtlBed BtlBed;
struct BtlBed
{
    BtlBedWork* work;   // 0x00
    s32 directoryHandle;        // 0x04
    u8* directoryName;        // 0x08
    u16 loadFlags;        // 0x0C
};

void btlFormationCopyRecord(BtlBedWork* destination, u32 source);
void btlFormationSetState(BtlBedWork* state);
void func_00440b68();
extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);
void H_Cdvd_Destroy(u8* cdvd);
s32 H_Cdvd_LookupRequest(u8* pathAddress, s32* slot);
s32 H_Cdvd_IsFileLoaded(u8* cdvd);
extern void (*jtbl_008873EC[])(void* ptr);
extern char iGpffffa288;
extern char D_00609538[];

/* Count the outstanding BED load, optionally copy its saved formation record,
 * and acquire the directory unless the descriptor requests deferred loading. */
// FUN_001D5CA0
void btlBedCopyRecord(BtlBed* bed)
{
    BtlBedWork* work = bed->work;

    work->count++;
    if ((work->flags & 8) && work->count == 2) {
        btlFormationCopyRecord(work, work->savedRecord);
    }
    if (!(bed->loadFlags & 1)) {
        func_00440b68(&iGpffffa288, D_00609538, 0x499);
        bed->directoryHandle = (s32)H_Cdvd_AcquireDirectory(bed->directoryName, 0);
    } else {
        bed->directoryHandle = 0;
    }
    work->flags |= 1;
}

/* Poll the directory, install its record, and release completed work when the
 * last outstanding load finishes. Returns one only after installation. */
// FUN_001D5D60
s32 btlBedLoad(BtlBed* bed)
{
    BtlBedWork* work = bed->work;
    s32 requestSize;

    if (bed->directoryHandle == 0) {
        func_00440b68(&iGpffffa288, D_00609538, 0x4B1);
        bed->directoryHandle = (s32)H_Cdvd_AcquireDirectory(bed->directoryName, 0);
    }
    if (H_Cdvd_IsFileLoaded((u8*)bed->directoryHandle) != 0) {
        btlFormationCopyRecord(work, H_Cdvd_LookupRequest(bed->directoryName, &requestSize));
        H_Cdvd_Destroy((u8*)bed->directoryHandle);
        work->flags &= 0xFFFE;
        work->flags |= 2;
        work->count--;
        if ((work->flags & 8) && work->count == 1) {
            btlFormationSetState(work);
        }
        if (work->count == 0) {
            if (work->flags & 2) {
                btlFormationSetState(work);
            }
            (*jtbl_008873EC)(work);
        }
        return 1;
    }
    return 0;
}
