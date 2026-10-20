#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 btlEffectStepFormationPlacement(u8 *work);
extern void btlEffectResetEntry(u8 *node);
extern void (*jtbl_008873EC[])(void *);
extern void btlEffectReleaseNode(u8 *node);
extern void btlEffectReleaseAllPlacements(u8 *unused);
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern void memset(u8 *input, s32 value, s32 options);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d6a60-001d6c10 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: restore optimization_level 2 after func_001d5990. */
/* measured: opt_propagation off probe for btlEffectStepFormationPlacement argument setup and register coloring. */
#pragma push
/* measured: restore pragma state after btlEffectStepFormationPlacement. */
#pragma pop
/* Empty retail lifecycle hook invoked by battle initialization; no state is modified. */
// FUN_001D6A60
void btlEffectInitializeNodeSystem(void)
{
}

/* Save each next link before destroying the current node, then release the formation placements. */
// FUN_001D6A70
void btlEffectFreeAllNodes(void)
{
    u8 *next;
    u8 *node;

    node = (u8 *)((BtlBattleState *)iGpffffb3ac)->effectNodes;
    while (node != NULL) {
        next = (u8 *)((BtlEffectNode *)node)->next;
        btlEffectReleaseNode(node);
        node = next;
    }
    btlEffectReleaseAllPlacements(node);
}

/* Allocate a 48-slot pool and 0x24-byte nodes, linking each initialized node into the global fade-node list.
 * Raw offsets retained: Member access changes MWCC code generation; retain the proven offsets and original access types. */
// FUN_001D6AD0
u8 *btlEffectAllocNodePool(void)
{
    u8 *array;
    u32 i;
    u8 *node;
    u8 *head;
    u32 table;
    chkmemAllocSiteTag(D_00609558, 0x51);
    table = (u32)jtbl_008873E8;
    array = (u8 *)((u8 *(*)(s32, s32))*(u32 *)table)(0xC8, 0x40000);
    memset(array, 0, 0xC8);
    i = 0;
    while (i < 0x30) {
        chkmemAllocSiteTag(D_00609558, 0x51);
        node = (u8 *)((u8 *(*)(s32, s32))*(u32 *)table)(0x24, 0x40000);
        memset(node, 0, 0x24);
        *(s32 *)&((BtlEffectNode *)node)->color = -1;
        ((BtlEffectNode *)node)->fadeStep = 0x14;
        *(s32 *)&((BtlEffectNode *)node)->counter = 0;
        ((BtlEffectNode *)node)->flags = 0x200;
        *(s32 *)&((BtlEffectNode *)node)->previous = 0;
        head = (u8 *)((BtlBattleState *)iGpffffb3ac)->effectNodes;
        if (head != NULL) {
            *(u8 **)&((BtlEffectNode *)head)->previous = node;
            head = (u8 *)((BtlBattleState *)iGpffffb3ac)->effectNodes;
            *(u8 **)&((BtlEffectNode *)node)->next = head;
        } else {
            *(u8 **)&((BtlEffectNode *)node)->next = NULL;
        }
        *(u8 **)&((BtlBattleState *)iGpffffb3ac)->effectNodes = node;
        *(u8 **)(array + i * 4) = node;
        i++;
    }
    return array;
}

/* Reset and unlink every pool node before freeing it, then release the pool allocation.
 * Raw offsets retained: Typed members change MWCC instruction selection/allocation; retain the proven byte offsets for the match. */
// FUN_001D6C10
void btlEffectFreeNodePool(u8 *pool)
{
    u32 i;
    u8 *entry;
    u8 *next;
    u8 *prev;

    i = 0;
    while (i < 0x30U) {
        entry = *(u8 **)(pool + (i * 4));
        btlEffectResetEntry(entry);
        next = *(u8 **)(entry + 0x20);
        if (next != NULL) {
            *(u8 **)(next + 0x1C) = *(u8 **)(entry + 0x1C);
        }
        prev = *(u8 **)(entry + 0x1C);
        if (prev != NULL) {
            *(u8 **)(prev + 0x20) = *(u8 **)(entry + 0x20);
        } else {
            *(u8 **)(iGpffffb3ac + 0x1B8) = *(u8 **)(entry + 0x20);
        }
        (*jtbl_008873EC)(entry);
        i++;
    }
    (*jtbl_008873EC)(pool);
}

