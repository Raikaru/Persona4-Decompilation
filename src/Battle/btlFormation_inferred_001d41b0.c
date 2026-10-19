#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_formation_attach_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void chkmemAllocSiteTag(u8 *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern s8 datCalcRandomBelow(s32 arg0);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();









typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d41b0-001d41b0 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* Allocate the attachment work prefix followed by one handle per table entry. */
// FUN_001D41B0
/* Allocate the 0x68-byte attachment prefix and one handle per selected table entry. The raw count
 * reload retains the measured three-word table-address alias behavior. */
u8 *btlFormationAllocEntry(u8 *table, s32 tableIndex, u32 unit, s32 target, s32 flags)
{
    u32 unitAddress;
    u32 offset;
    u32 base;
    u8 *result;
    u32 size;

    unitAddress = unit;
    offset = (u16)tableIndex * 0x314;
    base = (u32)table;
    /* The table consists of 0x314-byte records; only its count is known here. */
    size = *(u16 *)((u8 *)p4_001d7f10_add((s32)offset, (s32)base) + 0x10) * 4 + 0x68;
    chkmemAllocSiteTag(D_00609498, 0x51);
    result = jtbl_008873E8[0](size, 0x40000);
    memset(result, 0, size);
    ((BtlAttachWork *)result)->owner = table;
    ((BtlAttachWork *)result)->table = table + offset + 8;
    /* measured: typed table reload folds the +8 into +0x10 and changes three words. */
    ((BtlAttachWork *)result)->count = *(u16 *)(*(u8 **)(result + 4) + 8);
    ((BtlAttachWork *)result)->handles = (u8 **)(result + 0x68);
    ((BtlAttachWork *)result)->color = -1;
    ((BtlAttachWork *)result)->unit = (u8 *)unitAddress;
    ((BtlAttachWork *)result)->target = (u8 *)target;
    ((BtlAttachWork *)result)->flags = flags;
    if ((tableIndex & 0xFFFF) == 1) {
        ((BtlAttachWork *)result)->level = datCalcRandomBelow(0x64);
    }
    return result;
}

