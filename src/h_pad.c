/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00453570)
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
    u16 pressed;      // 0x00
    u16 justPressed;  // 0x02
    u16 released;     // 0x04
    u16 justReleased; // 0x06
} HPadButtons;

typedef struct HPad
{
    u16 mainMode;               // 0x00
    u16 state;                  // 0x02
    u16 requestedMainMode;      // 0x04
    u16 unknown06;              // 0x06
    u16 port;                   // 0x08
    u16 slot;                   // 0x0a
    HPadButtons btn[2];         // 0x0c
    u16 virtualPreviousPressed; // 0x1c
    s8 lstickX;                 // 0x1e
    s8 lstickY;                 // 0x1f
    s8 rstickX;                 // 0x20
    s8 rstickY;                 // 0x21
    u8 repeatTimer[12];         // 0x22
    u16 actuator0;              // 0x2e
    u16 actuator1;              // 0x30
    u16 appliedActuator0;       // 0x32
    u16 appliedActuator1;       // 0x34
} HPad;

HPad gWorkPads[HPAD_PORT_MAX]; // 008c02de

static s16 sRumbleState; // 00764b24
static union
{
    u16 h;
    u8 b;
} sRumbleIntensity; // 00764b20
static s16 sRumblePhase;     // 00764b1c
static s16 sRumbleOffFrames; // 00764b18
static s16 sRumbleOnFrames;  // 00764b14
static s16 sRumbleCadence;   // 00764b10
static s16 sRumbleDuration;  // 00764b0c

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
#endif /* P4_UNIT_00453570 */
