/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef struct BtlBedWork BtlBedWork;
struct BtlBedWork
{
    u8 pad[0x630];
    u16 flags;      // 0x630
    u16 count;      // 0x632
    u32 field634;   // 0x634
};

typedef struct BtlBed BtlBed;
struct BtlBed
{
    BtlBedWork* work;   // 0x00
    s32 field04;        // 0x04
    u8* field08;        // 0x08
    u16 field0C;        // 0x0C
};

void func_001d3ea0(BtlBedWork* work, u32 param);
void func_001d3ff0(BtlBedWork* work);
void func_00440b68();
extern u8* func_00454a60(u8* param, s32 mode);
void func_00454bd0(u8* ptr);
s32 func_00455f70(u8* param, s32* out);
s32 func_004553c0(u8* ptr);
extern void (*jtbl_008873EC[])(void* ptr);
extern char iGpffffa288;
extern char D_00609538[];

// FUN_001D5CA0
void func_001d5ca0(BtlBed* bed)
{
    BtlBedWork* work = bed->work;

    work->count++;
    if ((work->flags & 8) && work->count == 2) {
        func_001d3ea0(work, work->field634);
    }
    if (!(bed->field0C & 1)) {
        func_00440b68(&iGpffffa288, D_00609538, 0x499);
        bed->field04 = (s32)func_00454a60(bed->field08, 0);
    } else {
        bed->field04 = 0;
    }
    work->flags |= 1;
}

// FUN_001D5D60
s32 func_001d5d60(BtlBed* bed)
{
    BtlBedWork* work = bed->work;
    s32 sp3C;

    if (bed->field04 == 0) {
        func_00440b68(&iGpffffa288, D_00609538, 0x4B1);
        bed->field04 = (s32)func_00454a60(bed->field08, 0);
    }
    if (func_004553c0((u8*)bed->field04) != 0) {
        func_001d3ea0(work, func_00455f70(bed->field08, &sp3C));
        func_00454bd0((u8*)bed->field04);
        work->flags &= 0xFFFE;
        work->flags |= 2;
        work->count--;
        if ((work->flags & 8) && work->count == 1) {
            func_001d3ff0(work);
        }
        if (work->count == 0) {
            if (work->flags & 2) {
                func_001d3ff0(work);
            }
            (*jtbl_008873EC)(work);
        }
        return 1;
    }
    return 0;
}
