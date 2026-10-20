#include "Kosaka/k_command_internal.h"
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
extern s32 kwlnTaskIsLinked(s32 target);
extern char D_0063CB30[];
extern char D_0063D050[];
extern void kwlnTaskDestroyWithHierarchy(s32 task);


extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
// lint: allow H011 -- measured: a u16 prototype breaks func_00291a60, which passes wide id
// arguments.
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
/* measured: with opt_propagation off, retail keeps the weapon address in a local between the index
 * shift and the base add. */
#pragma push
#pragma pop
// Script command: destroys the task (with its children) whose id is parameter 0,
// if it is still linked. Returns 1 either way.
// FUN_00299560
s32 scrDestroyTaskById(void) {
    s32 v;

    v = scrGetParamInt(0);
    if (kwlnTaskIsLinked(v) == 0) {
        return 1;
    }
    kwlnTaskDestroyWithHierarchy(v);
    return 1;
}

