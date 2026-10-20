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
extern void evtPolygonMovieLerpPose(s32 enabled, f32 blend, f32 *fromPose, f32 *toPose,
                          f32 *outPose);
typedef signed __int128 s128;
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];


extern u8 iGpffffa790;

extern s32 D_008825F0[10];
extern u8 D_005EFA10[];
extern u8 D_005EFA20[];

// Add byteCount to the selected memory-accounting slot (negative to release).
// FUN_002852A0
void evtMemAccount(s32 slot, s32 byteCount) {
    s32 *counter;
    s32 *poolCounter;

    if ((slot < 0xD) && (slot >= 0)) {
        switch (slot) {
        case 0:
        case 4:
        case 5:
        case 6:
            poolCounter = &D_00882170[slot];
            *poolCounter += byteCount;
            break;
        default:
            counter = &D_00882170[slot];
            *counter += byteCount;
            break;
        }
    }
}

