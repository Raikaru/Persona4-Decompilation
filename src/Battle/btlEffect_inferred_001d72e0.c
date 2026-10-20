#include "btl_formation_attach_internal.h"
#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern void (*jtbl_008873EC[])(void *);
extern void btlFormationSetPlacement(s32 formation);
extern void btlEffectReleaseAllPlacements(u8 *unused);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
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

/* Map one supported status bit to its formation slot; unsupported values return -1. */
// FUN_001D72E0
s32 btlEffectFlagToSlotIndex(s32 flag)
{
    if (flag == 0) {
        return -1;
    }
    switch (flag) {
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

/* Write the RGBA colour for one status flag into color, using the configured default colour for
 * unknown flags. */
// FUN_001D7400
/* measured: without copy propagation off, retail's load/store order for the default color channels
 * is not reproduced. */
#pragma opt_propagation off
void btlEffectFlagToColor(s32 flag, u8 *color)
{
    u8 * output = color;
    s32 selectedFlag = flag;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;

    output[3] = 0xFF;
    switch (selectedFlag) {
    case 2:
        color[0] = 0xFF;
        output[1] = 0xB2;
        color[2] = 0x9E;
        break;
    case 4:
        output[0] = 0xB2;
        output[1] = 0xA8;
        color[2] = 0xFF;
        break;
    case 8:
        output[0] = 0xB2;
        color[1] = 0xFF;
        output[2] = 0xB2;
        break;
    case 0x10:
        output[0] = 0xEE;
        output[1] = 0x9B;
        color[2] = 0xDA;
        break;
    case 1:
        output[0] = 0xFF;
        output[1] = 0x94;
        color[2] = 0x76;
        break;
    case 0x20:
        output[0] = 0xBC;
        output[1] = 0xA8;
        output[2] = 0xFF;
        break;
    case 0x40:
        color[0] = 0x9E;
        color[1] = 0xE4;
        output[2] = 0xE1;
        break;
    case 0x80:
        output[0] = 0xCD;
        output[1] = 0xB9;
        output[2] = 0xD7;
        break;
    case 0x100:
        output[0] = 0x94;
        output[1] = 0x10;
        output[2] = 0x26;
        break;
    case 0x100000:
    case 0x80000:
    default:
        red = iGpffffa4d8;
        green = iGpffffa4d9;
        blue = iGpffffa4da;
        alpha = iGpffffa4db;
        color[0] = red;
        color[1] = green;
        color[2] = blue;
        color[3] = alpha;
        break;
    }
}

/* Release all formation slots and their mode-dependent backing storage, then clear the loaded-table
 * flag. */
// FUN_001D75D0
void btlEffectReleaseAllPlacements(u8 *unused)
{
    int formation = 0;
    u32 firstIndex = 0;
    u32 slotIndex = 0;
    int slotOffset = 0;
    u8 *state;

    if ((((BtlBattleState *)(iGpffffb3ac))->resourceFlags & 0x4000000) == 0) {
        for (firstIndex = 0; firstIndex < 0x30; firstIndex = firstIndex + 1) {
            state = iGpffffb3ac;
            if (*(int *)&((BtlBattleState *)(state + firstIndex * 4))->formations[0] != 0) {
                btlFormationSetPlacement(*(u32 *)&((BtlBattleState *)(state + firstIndex * 4))->formations[0]);
                *(u32 *)&((BtlBattleState *)(iGpffffb3ac + firstIndex * 4))->formations[0] = 0;
            }
        }
        if (*(int *)&((BtlBattleState *)(iGpffffb3ac))->formationHandle != 0) {
            H_Cdvd_Destroy((u8 *)(u32)*(u32 *)&((BtlBattleState *)(iGpffffb3ac))->formationHandle);
            *(u32 *)&((BtlBattleState *)(iGpffffb3ac))->formationHandle = 0;
        }
    }
    else {
        for (slotIndex = 0; slotIndex < 0x30; slotIndex = slotIndex + 1) {
            state = iGpffffb3ac;
            slotOffset = slotIndex * 4;
            formation = *(int *)&((BtlBattleState *)(state + slotOffset))->formations[0];
            if (formation != 0) {
                (*jtbl_008873EC)((u8 *)(u32)((BtlFormationState *)(formation))->value);
                btlFormationSetPlacement(*(u32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->formations[0]);
                *(u32 *)&((BtlBattleState *)(iGpffffb3ac + slotOffset))->formations[0] = 0;
            }
        }
    }
    ((BtlBattleState *)(iGpffffb3ac))->flags = ((BtlBattleState *)(iGpffffb3ac))->flags & 0xfffbffff;
}

/* Release the formation archive in its owning mode and clear the handle in either mode. */
// FUN_001D7700
void btlEffectReleaseCdvdHandle(void)
{
    u8 *handle;
    u8 *state;

    state = iGpffffb3ac;
    if ((*(s32 *)&((BtlBattleState *)(state))->resourceFlags & 0x4000000) == 0) {
        handle = ((BtlBattleState *)(state))->formationHandle;
        if (handle != NULL) {
            H_Cdvd_Destroy(handle);
        }
        ((BtlBattleState *)iGpffffb3ac)->formationHandle = NULL;
        return;
    }
    ((BtlBattleState *)(state))->formationHandle = NULL;
}

