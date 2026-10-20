#include "btl_target_state_packet_internal.h"
#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"

s32 kwlnTaskGetTaskByName(void *name);
extern s32 D_0063C368[];


extern void kAssertFail(void *file, s32 line);
extern s32 D_0063C1D0[];
extern u8 D_0063C2B8[];
extern f32 D_00882214[];
extern f32 D_00882218[];
extern f32 D_0088221C[];
extern f32 D_00882220[];
extern f32 D_00882224[];
extern f32 D_00882228[];
extern f32 D_0088222C[];
extern f32 D_00882230[];
extern f32 D_00882234[];
extern f32 D_00882238[];
extern f32 D_0088223C[];
extern f32 D_00882240[];
extern f32 D_00882244[];
extern u8 D_0063C310[];

typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;



extern u8 *evtPolygonMovieBind(u8 *messageContext, u8 *work, u8 *primary,
                         u8 *secondary, u8 *overlay);
extern char D_0063C340[];
extern char D_0063C380[];
extern char D_0063C350[];
extern void evtPolygonMovieLerpPose(s32 enabled, f32 blend, f32 *fromPose, f32 *toPose,
                          f32 *outPose);
typedef signed __int128 s128;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];




extern u8 iGpffffa790;

extern s32 D_008825F0[10];
extern u8 D_005EFA10[];
extern u8 D_005EFA20[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0028; members 002853b0-002853f0 */

/* Empty event callback; the caller receives success. */
// FUN_002853B0
s32 evtNoopCallback(void) {
    return 0;
}

/* Perform the event task lookup; this callback does not consume its result. */
// FUN_002853C0
void evtLookupTask(void) {
    kwlnTaskGetTaskByName(&iGpffffa790);
}

/* measured: retail hoists the lookup table address before the search loop. */
/* measured: evtKeyIndex MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Event key table: index of 'arg0' in the 58-entry key table, 0 when absent.
// FUN_002853F0
s32 evtKeyIndex(s32 key) {
    s32 i;

    if (key >= 0x3A) {
        kAssertFail(D_0063C2B8, 0x1E6);
    }
    i = 0;
    while (i < 0x3A) {
        if (key == D_0063C1D0[i]) {
            return i;
        }
        i++;
    }
    return 0;
}

