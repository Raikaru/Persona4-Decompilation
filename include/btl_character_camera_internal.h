#ifndef BTL_CHARACTER_CAMERA_INTERNAL_H
#define BTL_CHARACTER_CAMERA_INTERNAL_H

#include "type.h"

/* EndHomeInit selects a four-byte side record at character row +0x24.
 * The first halfword indexes the return-movement speed table. */
typedef struct BtlCharacterCameraSide {
    u16 returnSpeed;
    u16 unk02;
} BtlCharacterCameraSide;

/* Character IDs select 0xE8-byte rows. Close-camera eligibility reads +0x22;
 * the return movement selects the speed halfword at +0x24 or +0x28. */
typedef struct BtlCharacterCameraRow {
    u8 pad00[0x22];
    s16 closeCamera;
    BtlCharacterCameraSide sides[2];
    u8 pad2C[0xE8 - 0x2C];
} BtlCharacterCameraRow;

/* An interior column pointer advances by the complete character-row stride. */
typedef struct BtlCharacterCameraField {
    s16 value;
    u8 pad02[0xE8 - 2];
} BtlCharacterCameraField;

typedef char BtlCharacterCameraRowSizeCheck[sizeof(BtlCharacterCameraRow) == 0xE8 ? 1 : -1];
typedef char BtlCharacterCameraFieldSizeCheck[sizeof(BtlCharacterCameraField) == 0xE8 ? 1 : -1];

#endif
