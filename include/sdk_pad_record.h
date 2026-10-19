#ifndef SDK_PAD_RECORD_H
#define SDK_PAD_RECORD_H

#include "type.h"

/* Two 0x4A-byte records: sdkPadInit initializes port/slot, sdkPadUpdateRecord
 * fills hardware input, and the cooking/dispatch stages derive edge masks. */
typedef struct SdkPadRecord {
    u16 mode;
    u16 state;
    u16 requestedMode;
    u16 unk06;
    u16 port;
    u16 slot;
    u16 buttons;
    u16 pressed;
    u16 previousButtons;
    u16 repeat;
    u16 unk14;
    u16 directions;
    u16 directionPressed;
    u16 previousDirections;
    u8 leftX, leftY, rightX, rightY;
    u8 repeatTimers[12];
    u16 actuatorSmall, actuatorLarge;
    u16 previousActuatorSmall, previousActuatorLarge;
    u16 held;
    u16 heldPressed;
    u16 previousHeld;
    u16 heldRepeat;
    u16 unk3C;
    u8 heldRepeatTimers[12];
} SdkPadRecord;

#endif
