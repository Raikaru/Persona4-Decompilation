#include "btl_target_state_packet_internal.h"
#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"

extern s32 D_0063C368[];


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
extern void evtPolygonMovieLerpPose(s32 arg0, f32 arg1, f32 *arg2, f32 *arg3,
                          f32 *arg4);
typedef signed __int128 s128;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];



static inline s32 func_0028_sum(u16 arg0, s16 arg1) {
    return (s32)arg0 + arg1;
}

extern u8 iGpffffa790;

extern s32 D_008825F0[10];
extern u8 D_005EFA10[];
extern u8 D_005EFA20[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0028; members 002852a0-002852a0 */

// Event memory accounting: adds 'arg1' bytes to counter slot 'arg0' (negative to release).
// FUN_002852A0
void evtMemAccount(s32 arg0, s32 arg1) {
    s32 *temp_4;
    s32 *temp_4_2;

    if ((arg0 < 0xD) && (arg0 >= 0)) {
        switch (arg0) {
        case 0:
        case 4:
        case 5:
        case 6:
            temp_4_2 = &D_00882170[arg0];
            *temp_4_2 += arg1;
            break;
        default:
            temp_4 = &D_00882170[arg0];
            *temp_4 += arg1;
            break;
        }
    }
}

