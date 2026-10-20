#ifndef BTL_CAMERA_PRESET_INTERNAL_H
#define BTL_CAMERA_PRESET_INTERNAL_H

#include "rw_types_internal.h"

/* Camera pose-table consumers advance by 0x34 and divide the leading
 * duration by 30; each point/focus pair feeds btlCameraLookAtQuat. */
typedef struct BtlCameraPresetRecord {
    u16 durationFrames;
    u8 pad02[2];
    RwV3d firstPosition;     /* 0x04 */
    RwV3d firstFocus;        /* 0x10 */
    RwV3d secondPosition;    /* 0x1C */
    RwV3d secondFocus;       /* 0x28 */
} BtlCameraPresetRecord;

/* Fixed snapshots at table+0x6B4 and +0x6CC contain only these two points. */
typedef struct BtlCameraFixedPreset {
    RwV3d position;
    RwV3d focus;
} BtlCameraFixedPreset;

#endif
