#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;


extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 value);


extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void PrimDrawRadialTriangle(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 0025c730-0025c730 */

// FUN_0025C730
s32 scrCommonCheckResSlot(void) {
    s32 temp_16;
    s32 temp_17;

    temp_16 = scrGetParamInt(0);
    temp_17 = scrGetParamInt(1);
    MT_Scene_SpawnResIconTask(((temp_16 & 0x3FF) | 0xC00) & 0xFFFF, temp_17 & 0xFF);
    return 1;
}

