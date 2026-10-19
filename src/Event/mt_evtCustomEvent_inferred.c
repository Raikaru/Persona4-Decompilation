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

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
extern s32 kwlnTaskGetTaskByName(void *path);
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00293710-00293710 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
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
/* measured: func_00293710 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// Queues motion for resource arg0 with a position (positionX/Y/Z) and angle. When
// the settings pointer is set, its four floats are stored and flag 0x2 is added.
// Creates the manager task on first use.
// FUN_00293710
void evtModelQueueMotionAt(u16 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, u8 *arg3)
{
    extern u8 *func_002e1db0();
    extern u8 *func_002e2170();
extern s32 evtModelUpdateTask(u8 *task);
extern void evtModelTaskDestroy(u8 *task);

    extern s32 kwlnTaskGetTaskByName(void *arg0);
    extern u8 **kwlnTaskGetWork(s32 arg0);
    extern void memcpy(void *arg0, void *arg1, s32 arg2);
    extern void memset(void *arg0, s32 arg1, s32 arg2);
    extern u8 D_0063C930[];
    extern u8 D_0063C958[];
    struct {
        s16 field_0;
        s16 field_2;
        s32 field_4;
        f32 field_8;
        f32 field_C;
        f32 field_10;
        f32 field_14;
        s32 field_18;
        f32 field_1C;
        f32 field_20;
        f32 field_24;
        f32 field_28;
    } data;
    f32 value_3;
    f32 value_2;
    f32 value_1;
    f32 value_0;
    s32 result;
    u8 *work;
    u8 **work_link;
    u8 *manager;
    u8 *list;
    u8 *record;

    result = kwlnTaskGetTaskByName(D_0063C958);
    if (result == 0) {
        work = func_002e1db0(4, 0, 0, 0);
        work_link = *(u8 ***)(work + 0x24);
        *work_link = work;
        result = (s32)kwlnTaskCreate((const void *)(D_0063C958), 15, 0, 0, evtModelUpdateTask, evtModelTaskDestroy, (u8 *)(work_link));
    }
    manager = (u8 *)kwlnTaskGetWork(result);
    memset(&data, 0, 0x2C);
    data.field_0 = arg0;
    data.field_4 = arg1;
    data.field_8 = fparg0;
    data.field_C = fparg1;
    data.field_10 = fparg2;
    data.field_14 = fparg3;
    data.field_18 = arg2;
    if (arg3 != NULL) {
        value_3 = *(f32 *)(arg3 + 0);
        value_2 = *(f32 *)(arg3 + 4);
        value_1 = *(f32 *)(arg3 + 8);
        value_0 = *(f32 *)(arg3 + 0xC);
        data.field_1C = value_3;
        data.field_20 = value_2;
        data.field_24 = value_1;
        data.field_28 = value_0;
    }
    list = *(u8 **)manager;
    record = func_002e2170(list, *(u16 *)(list + 0x10) + 1, 0x4C);
    manager = *(u8 **)(record + 0x14);
    memcpy(manager, &data, 0x2C);
    *(s32 *)(manager + 0x2C) =
        *(s32 *)(D_0063C930 + data.field_4 * 4);
    if (arg3 != NULL)
        *(s32 *)(manager + 0x44) |= 2;
}

