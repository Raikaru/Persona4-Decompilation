#include "Kosaka/k_command_internal.h"
#include "g_data_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 resourceId);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];
extern void kwlnTaskDestroyWithHierarchy(s32 task);


extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
extern s32 kwlnTaskGetTaskByName(void *name);
// lint: allow H011 -- a u16 prototype changes code for func_00291a60's wide id arguments.
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32 farg0, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 image, f32 x, f32 y, f32 scaleX,
                          f32 scaleY, s32 alphaSubtract, s32 centered);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

extern void mtMiscCollectType1Records(u8 *eventWork);
extern void mtMiscCollectType2Records(u8 *eventWork);
/* measured: opt_propagation off keeps the weapon address materialised between the index shift and
 * base add, as retail does; index locals stay literal to avoid a sixth saved register. */
#pragma push
#pragma pop
// Destroys the task (with its children) whose name is D_0063CFA0. Returns 1.
// FUN_00298D30
s32 scrDestroyTaskByName(void) {
    s32 task;

    task = kwlnTaskGetTaskByName(D_0063CFA0);
    if (task != 0) {
        kwlnTaskDestroyWithHierarchy(task);
    }
    return 1;
}

// Script command: pushes the data flag named by parameter 0 as the return value.
// Returns 1.
// FUN_00298D70
s32 scrGetFlag(void) {
    scrSetReturnInt(datGetFlag(scrGetParamInt(0)));
    return 1;
}

