/* Promoted exact recovery: object 640B / window 640B, normalized_diff=0.
 * All 44 jump-table targets also match. Installed consumer smoke: 118720
 * pair checks and 28 real qsort batches under Clang ASan/UBSan.
 * Canonical implementation: src/Yajima/y_list.c. Retain this C recovery. */
#include "type.h"

/* Active list roots and 14-byte persona metadata, as declared in y_list.c. */
extern u8 *D_00882F70[];
static u8 *iGpffffb3d4;

/* Owner-context MWCC b210 -O2 measurement: 640B/640B, zero relocation-masked
 * differing executable bytes/words, no tail padding. The expanded accessor
 * keeps signed16 index multiplication live across each repeated selector pair.
 * optimization_level 1 follows the neighboring comparator's established mode.
 */
// FUN_002E6630
#pragma optimization_level 1
s32 func_002e6630(s16 *arg0, s16 *arg1) {
    s16 ia = *arg0;
    s16 ib = *arg1;
    u8 *base = *(u8 **)(D_00882F70[0] + 0x38);
    u8 *pa;
    u8 *qa;
    u8 *pb;
    u8 *qb;
    s32 offset_a;
    s32 offset_b;
    u8 *metadata;
    u16 va;
    s32 vb;
    s32 va_mask;
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0xA4;
        break;
    default:
        offset_a = (ia * 3) * 0x10;
        pa = base + offset_a + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qa = base + offset_a + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qa = base + offset_a + 0xA4;
        break;
    default:
        qa = base + offset_a + 0x14;
        break;
    }
    metadata = iGpffffb3d4 + 2;
    va = pa[4] + 100 * metadata[14 * *(u16 *)(qa + 2)];
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0xA4;
        break;
    default:
        offset_b = (ib * 3) * 0x10;
        pb = base + offset_b + 0x14;
        break;
    }
    switch (*(u32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        qb = base + offset_b + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        qb = base + offset_b + 0xA4;
        break;
    default:
        qb = base + offset_b + 0x14;
        break;
    }
    vb = (u16)(pb[4] + 100 * metadata[14 * *(u16 *)(qb + 2)]);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma optimization_level 2
