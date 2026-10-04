#ifndef FIELD_EVENT_INTERNAL_H
#define FIELD_EVENT_INTERNAL_H
#include "type.h"

/* Offsets and strides are recovered from the field/battle transition at
 * 0x00172e00. Unknown spans retain their measured extent, not assumed meaning.
 * The snapshot is seven aligned EE quadwords; field and color copies are
 * actual aggregates rather than adjacent independent scalar locals. */
typedef struct FldEventAttack {
    s16 animation;
    s16 unknown02;
    s16 initialFrame;
    s16 endFrame;
    u32 unknown08;
    u32 hitFrame;
    f32 fov;
    f32 distance;
    f32 advantageChance;
    u16 attackBlend;
    u16 idleBlend;
} FldEventAttack;

typedef struct FldEventUnit {
    u16 genus;
    u16 count;
    void *units;
    u16 encounterId;
    u16 flags;
} FldEventUnit;

typedef struct FldEventActor {
    u8 unknown00[0x40];
    u32 flags;
    u32 unknown44;
    FldEventUnit *unit;
    u8 *encounterData;
    u32 model;
    u32 active;
    u8 unknown58[0x170];
    u16 kind;
    u8 unknown1ca[0x55E];
    s16 partyId;
    u8 unknown72a[0x26];
} FldEventActor;

typedef struct FldEventBattle {
    u16 flags;
    u16 unknown02;
    FldEventUnit *party[4];
    FldEventUnit *enemies[3];
    u16 fieldId;
    u16 roomId;
    u8 unknown24[0x18];
} FldEventBattle;

typedef struct FldEventSnapshot { u32 words[28]; } __attribute__((aligned(16))) FldEventSnapshot;
typedef struct FldEventColor { u8 r, g, b, a; } FldEventColor;

typedef struct FldEventWork {
    s32 mode;
    s32 state;
    s32 eventPending;
    u32 unknown0c;
    s32 scriptTask;
    u32 unknown14;
    u8 *resource;
    u8 unknown1c[0x14];
    s32 modelFile;
    u32 unknown34;
    s32 attackIndex;
    s32 frameCounter;
    FldEventAttack *attack;
    FldEventActor *target;
    FldEventActor *nearby[2];
    FldEventBattle battle;
    u32 unknown8c;
    FldEventSnapshot snapshot;
    s32 battleTask;
    s32 fieldTask;
    s32 environmentTask;
    s32 returnMode;
    u32 unknown110[2];
    s16 battleFlags;
    s16 targetHasUnits;
    FldEventColor environmentColor;
    FldEventColor viewColor;
    f32 viewFog;
    f32 environmentFog;
    s32 unitState;
    u32 unknown130;
    s32 motionState;
    u32 unknown138;
    s32 fieldEffect;
} FldEventWork;

void func_0016f630(FldEventSnapshot *destination, u8 *cameraTask);

#endif
