#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "nmlist_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
extern s32 kwlnTaskGetTaskByName(void *name);
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32, f32, f32, f32,
                          f32, s32, s32);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00293710-00293710 */

extern void mtMiscCollectType1Records(u8 *);
extern void mtMiscCollectType2Records(u8 *);
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
// Queue motion for resourceId with positionX/Y/Z and angle. When
// the settings pointer is set, its four floats are stored and flag 0x2 is added.
// Creates the manager task on first use.
// FUN_00293710
void evtModelQueueMotionAt(u16 resourceId, s32 motion, f32 positionX, f32 positionY,
                   f32 positionZ, f32 angle, s32 flags, u8 *settings)
{
    extern u8 *nmListAllocManager();
    extern u8 *nmListAppendNode();
extern s32 evtModelUpdateTask(u8 *unusedTask);
extern void evtModelTaskDestroy(u8 *unusedTask);

    extern s32 kwlnTaskGetTaskByName(void *name);
    extern u8 **kwlnTaskGetWork(s32 task);
    extern void memcpy(void *resourceId, void *motion, s32 flags);
    extern void memset(void *resourceId, s32 motion, s32 flags);
    extern s32 D_0063C930[]; /* motion-indexed step callback addresses */
    extern u8 D_0063C958[];
    typedef struct EvtModelMotionParameters {
        s16 resourceId;
        s16 unk02;
        s32 motion;
        f32 positionX;
        f32 positionY;
        f32 positionZ;
        f32 angle;
        s32 flags;
        f32 settingFirst;
        f32 settingSecond;
        f32 settingThird;
        f32 settingFourth;
    } EvtModelMotionParameters;
    typedef struct EvtModelMotionRecord {
        EvtModelMotionParameters parameters;
        s32 stepAddress;
        u8 pad30[0x14];
        s32 flags;
        u8 pad48[4];
    } EvtModelMotionRecord;
    EvtModelMotionParameters data;
    f32 settingFirst;
    f32 settingSecond;
    f32 settingThird;
    f32 settingFourth;
    s32 result;
    u8 *work;
    u8 **workLink;
    u8 *manager;
    u8 *list;
    u8 *record;

    result = kwlnTaskGetTaskByName(D_0063C958);
    if (result == 0) {
        work = nmListAllocManager(4, 0, 0, 0);
        workLink = (u8 **)((NmlistManager *)work)->data;
        *workLink = work;
        result = (s32)kwlnTaskCreate((const void *)(D_0063C958), 15, 0, 0, evtModelUpdateTask, evtModelTaskDestroy, (u8 *)(workLink));
    }
    manager = (u8 *)kwlnTaskGetWork(result);
    memset(&data, 0, 0x2C);
    data.resourceId = resourceId;
    data.motion = motion;
    data.positionX = positionX;
    data.positionY = positionY;
    data.positionZ = positionZ;
    data.angle = angle;
    data.flags = flags;
    if (settings != NULL) {
        settingFirst = ((f32 *)settings)[0];
        settingSecond = ((f32 *)settings)[1];
        settingThird = ((f32 *)settings)[2];
        settingFourth = ((f32 *)settings)[3];
        data.settingFirst = settingFirst;
        data.settingSecond = settingSecond;
        data.settingThird = settingThird;
        data.settingFourth = settingFourth;
    }
    list = *(u8 **)manager;
    record = nmListAppendNode(list, ((NmlistManager *)list)->list.count + 1, 0x4C);
    manager = ((NmlistNode *)record)->data;
    memcpy(manager, &data, 0x2C);
    ((EvtModelMotionRecord *)manager)->stepAddress =
        D_0063C930[data.motion];
    if (settings != NULL)
        ((EvtModelMotionRecord *)manager)->flags |= 2;
}

