#ifndef RESRC_MANAGER_INTERNAL_H
#define RESRC_MANAGER_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"

#define RESRC_ID_MASK   0x3ff
#define RESRC_TYPE_MASK 0xffc00
#define RESRC_GET_ID(resTypeId)   ((resTypeId) & RESRC_ID_MASK)
#define RESRC_GET_TYPE(resTypeId) (((resTypeId) & RESRC_TYPE_MASK) >> 10)

/* Values match the P3FES include/Scene/resrcManager.h enum. */
typedef enum
{
    RESRC_TYPE_MODELCHAR = 1,
    RESRC_TYPE_MODELUNK,
    RESRC_TYPE_MODELNPC,
    RESRC_TYPE_LIGHTCHAR,
    RESRC_TYPE_LIGHTNPC,
    RESRC_TYPE_06,
    RESRC_TYPE_07,
    RESRC_TYPE_08,
    RESRC_TYPE_09,
    RESRC_TYPE_MODELFLD,
    RESRC_TYPE_11,
    RESRC_TYPE_FLD,
    RESRC_TYPE_FLDHIT,
    RESRC_TYPE_14,
    RESRC_TYPE_15,
    RESRC_TYPE_16,
    RESRC_TYPE_17,
    RESRC_TYPE_18,
    RESRC_TYPE_19,
    RESRC_TYPE_20,
    RESRC_TYPE_21,
    RESRC_TYPE_MAX
} ResrcType;

typedef struct ResrcRecord ResrcRecord;

/* Shared 0x140 resource prefix; the update and render paths use the same object. */
typedef struct SceneScaleUpdate {
    RwV3d start, end;
    u32 duration, elapsed;
} SceneScaleUpdate;
typedef struct SceneFootstepUpdate {
    u8 mode, sequence, surface, sound;
    u16 elapsed, period, delay, unknown0a;
} SceneFootstepUpdate;
typedef union SceneMoveTime { u32 frame; f32 distance; } SceneMoveTime;
typedef struct ResrcHeader {
    union { u16 resTypeId; u16 id; };
    u16 unknown02;
    RwV3d position, rotation;
    union { RwV3d scale; struct { f32 unk1C, unk20, unk24; }; };
    union { u32 flags; u32 unk28; };
    u8 moveEase, unknown2d[3];
    RwV3d moveStart, moveEnd;
    u8 unknown48[12];
    u8 moveKind, unknown55[3];
    union { s8 *path; void *ownedData; };
    f32 moveSpeed;
    SceneMoveTime moveElapsed, moveDuration;
    RwV3d rotationStart, rotationEnd;
    u8 unknown80, rotationEase;
    u16 unknown82;
    u32 rotationDuration, rotationElapsed;
    u8 orbitEase, unknown8d[3];
    RwV3d orbitStart, orbitEnd;
    f32 yawStart, yawEnd, pitchStart, pitchEnd, distanceStart, distanceEnd;
    u32 orbitDuration, orbitElapsed;
    SceneScaleUpdate scaleUpdate;
    SceneFootstepUpdate footsteps;
    u8 alphaStart, alphaEnd;
    u16 unknownf6;
    u32 alphaDuration, alphaElapsed;
    s8 alphaBlend;
    u8 unknown101[3];
    f32 fovStart, fovEnd;
    s32 fovDuration, fovElapsed;
    u8 unknown114[0x20];
    s32 forcedFrames;
    ResrcRecord *next;
    union { ResrcRecord *prev; ResrcRecord *previous; };
} ResrcHeader;

/* Kind-specific interpretations share the header but have different extents. */
struct ResrcRecord
{
    ResrcHeader;
    union {
        struct {
            union {
                struct {
                    union {
                        void *slotHandle[2]; /* 0x140. [1] is 0x144 in the per-type cases */
                        s32 slotHandleValue[2]; /* Native signed-word API transport, same handles. */
                        f32 fieldOfView;     /* 0x140. Camera-resource interpretation */
                    };
                    s32 cameraRes[2];       /* 0x148. Camera resources (RESRC_TYPE_20) */
                };
                struct {
                    f32 placement[3];      /* 0x140. Placement-resource position */
                    f32 heading;           /* 0x14c. Rotation about the vertical axis */
                };
            };
            union {
                u8 unk150[0x8];
                struct { s32 value150, unk154; };
            };
            void *modelHandle158;   /* 0x158. Model data (RESRC_TYPE_MODELUNK) */
            u8 unk15C[0x8];
            union {
                void *modelHandle164; /* 0x164. Model data (RESRC_TYPE_MODELCHAR/NPC) */
                s32 modelHandle164Value;
            };
            u8 unk168[0x4];
            void *handle16C;        /* 0x16c. Effect handle (RESRC_TYPE_MODELFLD) */
            u8 unk170[0x30];
            s32 handle1A0;          /* 0x1a0. RESRC_TYPE_FLD */
            u8 unk1A4[0x6c];
            s32 objectDrawSet;      /* 0x210. RESRC_TYPE_MODELUNK draw queue */
            u8 unk214[0xc];
            s32 handle220;          /* 0x220 */
            s32 handle224;          /* 0x224 */
            void *handle228;        /* 0x228 */
            union {
                void *handle22C;        /* 0x22c. NPC attached model */
                s32 characterDrawSet;   /* 0x22c. Character draw queue */
            };
            s32 handle230;          /* 0x230 */
            u8 unk234[0x54];
            s32 handle288;          /* 0x288. Freed through jtbl_008873EC[0] */
            u8 unk28C[0x4];
            void *handle290;        /* 0x290 */
            s32 handle294;          /* 0x294 */
            u8 unk298[0xc8];
            s32 handle360;          /* 0x360 */
        };
        struct {
            s32 cameraCurve; /* 0x140 */
            f32 cameraFov;
            s32 cameraMatrix;
            s32 cameraSlotMatrix;
            f32 cameraViewOffset[3];
            f32 cameraViewDistance;
            f32 cameraFollowHeight;
            s8 cameraSlotEnabled[32];
            f32 cameraSlotVectors[32][3];
        };
        struct {
            f32 lightColor[4];       /* 0x140 */
            f32 lightTarget[4];      /* 0x150 */
            f32 lightTransform[16];  /* 0x160 */
            f32 lightValue[4];       /* 0x1A0 */
            f32 lightMatrix[16];     /* 0x1B0 */
            f32 lightScale[3];       /* 0x1F0 */
        };
    };
};

#endif
