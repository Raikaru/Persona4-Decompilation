#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;


extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 icon);


extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);







/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 0025c730-0025c730 */

// FUN_0025C730
s32 scrCommonCheckResSlot(void) {
    s32 resourceId;
    s32 iconId;

    resourceId = scrGetParamInt(0);
    iconId = scrGetParamInt(1);
    MT_Scene_SpawnResIconTask(((resourceId & 0x3FF) | 0xC00) & 0xFFFF, iconId & 0xFF);
    return 1;
}

