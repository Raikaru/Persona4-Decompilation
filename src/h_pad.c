/* Source unit: src/h_pad_00453570.c */
#include "type.h"

typedef enum
{
    HPAD_PORT_1,
    HPAD_PORT_2,
    HPAD_PORT_MAX
} HPadPort;

typedef enum
{
    HPAD_STATE_INITIALIZING,
    HPAD_STATE_WAITING_FOR_MODE,
    HPAD_STATE_MODE_REQUESTED,
    HPAD_STATE_CONFIGURING_ACTUATORS,
    HPAD_STATE_WAITING_FOR_ACTUATORS,
    HPAD_STATE_READY
} HPadState;

typedef struct HPadButtons
{
    u16 pressed;
    u16 justPressed;
    u16 previousPressed;
    u16 repeated;
} HPadButtons;

/* H_Pad_Init clears two 0x4a-byte records at 0x008c02e0. The polling
 * and repeat handlers use the same stride and the field offsets below. */
typedef struct HPad
{
    u16 mainMode;              // 0x00
    u16 state;                 // 0x02
    u16 requestedMainMode;     // 0x04
    u16 unknown06;             // 0x06
    u16 port;                  // 0x08
    u16 slot;                  // 0x0a
    HPadButtons raw;           // 0x0c
    u16 unknown14;             // 0x14
    u16 analogPressed;         // 0x16
    u16 analogJustPressed;     // 0x18
    u16 analogPreviousPressed; // 0x1a
    u8 lstickX;                // 0x1c
    u8 lstickY;                // 0x1d
    u8 rstickX;                // 0x1e
    u8 rstickY;                // 0x1f
    u8 repeatTimer[12];        // 0x20
    u16 actuator0;             // 0x2c
    u16 actuator1;             // 0x2e
    u16 appliedActuator0;      // 0x30
    u16 appliedActuator1;      // 0x32
    HPadButtons combined;      // 0x34
    u16 unknown3c;             // 0x3c
    u8 combinedRepeatTimer[12];// 0x3e
} HPad;

typedef char HPadSizeCheck[(sizeof(HPad) == 0x4a) ? 1 : -1];
HPad gWorkPads[HPAD_PORT_MAX]; // 008c02e0

/* The retail small-data slots are four-byte aligned, including halfwords. */
static s16 sRumbleDuration __attribute__((aligned(4)));  // 00764b24
static s16 sRumbleCadence __attribute__((aligned(4)));   // 00764b20
static s16 sRumbleOnFrames __attribute__((aligned(4)));  // 00764b1c
static s16 sRumbleOffFrames __attribute__((aligned(4))); // 00764b18
static s16 sRumblePhase __attribute__((aligned(4)));    // 00764b14
static union
{
    u16 h;
    u8 b;
} sRumbleIntensity; // 00764b10
static s16 sRumbleState __attribute__((aligned(4)));    // 00764b0c

// FUN_00453570
void H_Pad_StopRumble(void)
{
    sRumbleDuration = 0;
    sRumbleCadence = 0;
    sRumbleOnFrames = 0;
    sRumbleOffFrames = 0;
    sRumbleIntensity.h = 0;
    sRumbleState = HPAD_STATE_WAITING_FOR_MODE;
    sRumblePhase = 0;
    gWorkPads[HPAD_PORT_1].actuator0 = 0;
    gWorkPads[HPAD_PORT_1].actuator1 = 0;
}
