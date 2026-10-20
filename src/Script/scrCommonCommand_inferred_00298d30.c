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
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00298d30-00298d70 */

extern void mtMiscCollectType1Records(u8 *eventWork);
extern void mtMiscCollectType2Records(u8 *eventWork);
/* measured probe: preserve local constant with opt_propagation off. */
/* measured probe: close opt_propagation bracket after func_00291530. */
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
/* measured: restore propagation for the rest of the unit. */
/* measured probe: preserve the retail type constant and close bracket below. */
/* measured probe: close opt_propagation bracket after func_00291810. */
/* measured: O1 float-local register mapping probe for func_00293710. */
/* measured: closes O1 float-local register mapping probe for func_00293710. */
/* Each filtered scan owns its resource and index. With opt_lifetimes on,
 * those local scopes reproduce all 6312 retail code bytes; the 6320-byte
 * function window ends in eight zero alignment bytes. */
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

