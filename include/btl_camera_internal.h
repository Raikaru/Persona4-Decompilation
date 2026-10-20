#ifndef BTL_CAMERA_INTERNAL_H
#define BTL_CAMERA_INTERNAL_H

#include "type.h"

typedef struct BtlAction BtlAction;

/* Storage records deliberately do not define RenderWare tags: older effect
 * owners declare those tags privately while sharing the battle-state header. */
typedef struct BtlCameraPosition {
    f32 x, y, z;
} BtlCameraPosition;
typedef struct BtlCameraQuaternion {
    BtlCameraPosition imag;
    f32 real;
} BtlCameraQuaternion;

/* A pose is seven contiguous floats: position followed by all quaternion lanes. */
typedef struct BtlCameraPose {
    BtlCameraPosition pos;
    BtlCameraQuaternion rot;
} BtlCameraPose;

/* Four-byte header precedes the variable-length 0x3C-byte script rows. */
typedef struct BtlCameraScript {
    u8 count;
    u8 flags;
    s16 curveMode;
} BtlCameraScript;

/* Script rows start four bytes after the table header and have a 0x3C stride. */
typedef struct BtlCameraScriptEntry {
    s16 duration;
    u16 positionSource;
    BtlCameraPosition firstPosition;
    BtlCameraPosition secondPosition;
    u16 focusSource;
    u16 unk1E;
    BtlCameraPosition firstFocus;
    BtlCameraPosition secondFocus;
    f32 roll;
} BtlCameraScriptEntry;

/* Reset clears 0x14 bytes; InitWork writes these exact words/halfwords. */
typedef struct BtlCameraScriptWork {
    s32 firstAction;
    s32 secondAction;
    u16 elapsed;
    s16 index;
    u16 entryElapsed;
    u16 flags;
    u8 *script;
} BtlCameraScriptWork;

/* Camera subobject starts at battle+0x24. InitSystem, SetState, pose copies,
 * and the effect-script readers/writers establish the fields used here. */
typedef struct BtlCamera {
    u16 curveFlags;                  /* 0x00 */
    u8 pad02[2];
    BtlCameraPose curveKeys[4];      /* 0x04: four-entry ring, 0x1C-byte poses */
    union { s16 curveIndex; u16 keyReadIndex; }; /* 0x74 */
    union { s16 curveNext; u16 keyCount; };      /* 0x76 */
    union { s16 curveCount; u16 keyWriteIndex; };/* 0x78 */
    u8 pad7A[2];
    union { s32 unk7C; f32 keyTime; };
    union { s32 unk80; f32 transitionTime; };
    f32 curveDuration;               /* 0x84 */
    f32 springElapsed;              /* 0x88: midpoint test in UpdateTransition */
    u8 pad8C[8];
    f32 curveStep;                   /* 0x94 */
    s32 workList;                    /* 0x98 */
    BtlCameraPose pose;              /* 0x9C */
    f32 fovRad;                      /* 0xB8 */
    u8 padBC[0x14];
    u16 state;                      /* 0xD0 */
    u8 padD2[2];
    u32 flags;                      /* 0xD4: 1 suppress callback, 2 update range flags */
    s32 frame;                      /* 0xD8 */
    s32 delay;                      /* 0xDC */
    BtlAction *action;               /* 0xE0 */
    u16 stateHistory[3];             /* 0xE4 */
    u16 repeatedStateCount;          /* 0xEA */
    BtlCameraScriptWork scriptWork;  /* 0xEC */
    /* Camera modes reuse this storage; the original scalar names remain aliases. */
    union {
        struct {
            s32 presetTarget;                /* 0x100 */
            u8 pad104[4];
            s32 presetAlternate;             /* 0x108 */
            u16 presetUseCount;              /* 0x10C */
            u16 presetRepeatCount;           /* 0x10E */
            u16 frameMode;                   /* 0x110 */
            u8 pad112[2];
            s32 frameBlocked;               /* 0x114: UpdateMode blocks further framing */
            u8 pad118[0x14];
            u32 animationUnit;               /* 0x12C */
            u16 animationValue;              /* 0x130 */
            u8 pad132[2];
            u8 *effectTarget;                /* 0x134 */
            s32 effectMode;                  /* 0x138 */
            s32 effectInterrupted;           /* 0x13C */
            u16 effectTargetCount;           /* 0x140 */
            u16 effectFlags;                 /* 0x142 */
            s32 effectScriptActive;          /* 0x144: ChooseActionStyle selects the effect updater */
            s32 forceTransition;             /* 0x148 */
        };
        struct {
            f32 yaw;
            BtlCameraPosition focus;
            BtlCameraPosition direction;
            f32 radius;
            s32 refreshBounds;
        } orbit;
        struct {
            u8 *action;
            u16 genusMask;
            u16 groupMode;
        } status;
    };
} BtlCamera;

/* Packet 0x201 allocates this complete 0x44-byte work record. */
typedef struct BtlCameraPoseSequence {
    s32 action;
    BtlCameraPosition firstPosition;
    BtlCameraPosition firstFocus;
    BtlCameraPosition secondPosition;
    BtlCameraPosition secondFocus;
    f32 firstValue;
    f32 secondValue;
    f32 duration;
    s32 useCurrentPose;
} BtlCameraPoseSequence;

/* Encounter camera table rows have a 0x14-byte stride. SetState reads the
 * initializer and flags; ApplyView calls the update slot. */
typedef struct BtlCameraStateRecord {
    void (*initialize)(u8 *camera);
    void (*update)(u8 *camera);
    s32 forceReset;
    s32 updateRange;
    s32 unk10;
} BtlCameraStateRecord;

/* Packet 0x202 forwards these four values to its external command handler. */
typedef struct BtlCameraCommand {
    s32 value;
    s16 option;
    u8 pad06[2];
    s32 first;
    s32 second;
} BtlCameraCommand;

typedef char BtlCameraScriptSizeCheck[sizeof(BtlCameraScript) == 4 ? 1 : -1];
typedef char BtlCameraOrbitFocusOffsetCheck[(u32)&((BtlCamera *)0)->orbit.focus == 0x104 ? 1 : -1];
typedef char BtlCameraStatusGroupOffsetCheck[(u32)&((BtlCamera *)0)->status.groupMode == 0x106 ? 1 : -1];
typedef char BtlCameraBlockedOffsetCheck[(u32)&((BtlCamera *)0)->frameBlocked == 0x114 ? 1 : -1];
typedef char BtlCameraEffectUpdaterOffsetCheck[(u32)&((BtlCamera *)0)->effectScriptActive == 0x144 ? 1 : -1];
typedef char BtlCameraScriptEntrySizeCheck[sizeof(BtlCameraScriptEntry) == 0x3C ? 1 : -1];
typedef char BtlCameraScriptWorkSizeCheck[sizeof(BtlCameraScriptWork) == 0x14 ? 1 : -1];
typedef char BtlCameraSizeCheck[sizeof(BtlCamera) == 0x14C ? 1 : -1];
typedef char BtlCameraPoseSequenceSizeCheck[sizeof(BtlCameraPoseSequence) == 0x44 ? 1 : -1];
typedef char BtlCameraCommandSizeCheck[sizeof(BtlCameraCommand) == 0x10 ? 1 : -1];

#endif
