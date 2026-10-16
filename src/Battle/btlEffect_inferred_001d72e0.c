#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern void (*jtbl_008873EC[])(void *);
extern void btlFormationSetPlacement(s32 arg0);
extern void func_001d75d0(u8 *arg0);
extern void H_Cdvd_Destroy(u8 *arg0);
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d72e0-001d7700 */

/* measured: opt_propagation off probe for func_001d14b0 loop masks. */
/* measured: close opt_propagation after func_001d14b0 probe. */
#pragma push
#pragma pop
/* measured: optimization_level 1 probe for func_001d5990 stack reload scheduling. */
/* measured: restore optimization_level 2 after func_001d5990. */
#pragma push
#pragma pop
// FUN_001D72E0
s32 func_001d72e0(s32 arg0)
{
    if (arg0 == 0) {
        return -1;
    }
    switch (arg0) {
    case 2:
        return 0x12;
    case 4:
        return 0x13;
    case 8:
        return 0x14;
    case 0x10:
        return 0x15;
    case 1:
        return 0x16;
    case 0x20:
        return 0x17;
    case 0x40:
        return 0x18;
    case 0x80:
        return 0x19;
    case 0x100:
        return 0x1A;
    case 0x80000:
    case 0x100000:
    default:
        return -1;
    }
}

/* measured: opt_propagation off plus ascending default loads reproduces retail exactly (object 452B/window 464B, normalized_diff 0). */
// FUN_001D7400
/* measured: opt_propagation off is required for the default GP load/store register order. */
/* measured: func_001d7400 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void func_001d7400(s32 arg0, u8 *arg1)
{
    u8 * arg1_p = arg1;
    s32 arg0_p = arg0;
    u8 temp_0;
    u8 temp_1;
    u8 temp_2;
    u8 temp_3;

    *(u8 *)(arg1_p + 3) = 0xFF;
    switch (arg0_p) {
    case 2:
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(1 + arg1_p) = 0xB2;
        *(u8 *)(arg1 + 2) = 0x9E;
        break;
    case 4:
        *(u8 *)(arg1_p + 0) = 0xB2;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(arg1 + 2) = 0xFF;
        break;
    case 8:
        *(u8 *)(arg1_p + 0) = 0xB2;
        *(u8 *)(arg1 + 1) = 0xFF;
        *(u8 *)(2 + arg1_p) = 0xB2;
        break;
    case 0x10:
        *(u8 *)(arg1_p + 0) = 0xEE;
        *(u8 *)(arg1_p + 1) = 0x9B;
        *(u8 *)(arg1 + 2) = 0xDA;
        break;
    case 1:
        *(u8 *)(arg1_p + 0) = 0xFF;
        *(u8 *)(arg1_p + 1) = 0x94;
        *(u8 *)(arg1 + 2) = 0x76;
        break;
    case 0x20:
        *(u8 *)(0 + arg1_p) = 0xBC;
        *(u8 *)(arg1_p + 1) = 0xA8;
        *(u8 *)(arg1_p + 2) = 0xFF;
        break;
    case 0x40:
        *(u8 *)(arg1 + 0) = 0x9E;
        *(u8 *)(arg1 + 1) = 0xE4;
        *(u8 *)(arg1_p + 2) = 0xE1;
        break;
    case 0x80:
        *(u8 *)(0 + arg1_p) = 0xCD;
        *(u8 *)(arg1_p + 1) = 0xB9;
        *(u8 *)(arg1_p + 2) = 0xD7;
        break;
    case 0x100:
        *(u8 *)(0 + arg1_p) = 0x94;
        *(u8 *)(arg1_p + 1) = 0x10;
        *(u8 *)(arg1_p + 2) = 0x26;
        break;
    case 0x100000:
    case 0x80000:
    default:
        temp_0 = iGpffffa4d8;
        temp_1 = iGpffffa4d9;
        temp_2 = iGpffffa4da;
        temp_3 = iGpffffa4db;
        *(u8 *)(arg1 + 0) = temp_0;
        *(u8 *)(arg1 + 1) = temp_1;
        *(u8 *)(arg1 + 2) = temp_2;
        *(u8 *)(arg1 + 3) = temp_3;
        break;
    }
}

/* measured: close opt_propagation after func_001d7400. */
// FUN_001D75D0
void func_001d75d0(u8 *arg0)
{
    int iVar1 = 0;
    u32 firstIndex = 0;
    u32 uVar2 = 0;
    int iVar3 = 0;
    u8 *state;

    if ((*(u32 *)(iGpffffb3ac + 0x14) & 0x4000000) == 0) {
        for (firstIndex = 0; firstIndex < 0x30; firstIndex = firstIndex + 1) {
            state = iGpffffb3ac;
            if (*(int *)(state + firstIndex * 4 + 0xD04) != 0) {
                btlFormationSetPlacement(*(u32 *)(state + firstIndex * 4 + 0xD04));
                *(u32 *)(iGpffffb3ac + firstIndex * 4 + 0xD04) = 0;
            }
        }
        if (*(int *)(iGpffffb3ac + 0xDC4) != 0) {
            H_Cdvd_Destroy((u8 *)(u32)*(u32 *)(iGpffffb3ac + 0xDC4));
            *(u32 *)(iGpffffb3ac + 0xDC4) = 0;
        }
    }
    else {
        for (uVar2 = 0; uVar2 < 0x30; uVar2 = uVar2 + 1) {
            state = iGpffffb3ac;
            iVar3 = uVar2 * 4;
            iVar1 = *(int *)(state + iVar3 + 0xD04);
            if (iVar1 != 0) {
                (*jtbl_008873EC)((u8 *)(u32)*(u32 *)(iVar1 + 0x634));
                btlFormationSetPlacement(*(u32 *)(iGpffffb3ac + iVar3 + 0xD04));
                *(u32 *)(iGpffffb3ac + iVar3 + 0xD04) = 0;
            }
        }
    }
    *(u32 *)(iGpffffb3ac + 0xC) = *(u32 *)(iGpffffb3ac + 0xC) & 0xfffbffff;
}

// FUN_001D7700
void func_001d7700(void)
{
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffffb3ac;
    if ((*(s32 *)(temp_5 + 0x14) & 0x4000000) == 0) {
        temp_4 = *(u8 **)(temp_5 + 0xDC4);
        if (temp_4 != NULL) {
            H_Cdvd_Destroy(temp_4);
        }
        *(u8 **)(iGpffffb3ac + 0xDC4) = NULL;
        return;
    }
    *(u8 **)(temp_5 + 0xDC4) = NULL;
}

