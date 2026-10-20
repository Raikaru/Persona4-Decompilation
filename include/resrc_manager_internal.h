#ifndef RESRC_MANAGER_INTERNAL_H
#define RESRC_MANAGER_INTERNAL_H

#include "type.h"

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

/* Resource record as the per-type delete path reads it. Only offsets used by
 * MT_Scene_DestroyRes are named; the remaining bytes are padding. A few offsets
 * hold different handles per type, so each name is the first user's role. */
struct ResrcRecord
{
    u16 resTypeId;          /* 0x00. bits 0-9 = id, bits 10-15 = ResrcType */
    u8 unk02[0x1a];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u32 unk28;              /* +0x28: copied to EvtNode.resData */
    u8 pad2C[0x2C];
    void *ownedData;        /* 0x58 */
    u8 unk5C[0xdc];
    ResrcRecord *next;      /* 0x138 */
    ResrcRecord *prev;      /* 0x13c */
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
            u8 unk1A4[0x7c];
            s32 handle220;          /* 0x220 */
            s32 handle224;          /* 0x224 */
            void *handle228;        /* 0x228 */
            void *handle22C;        /* 0x22c */
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
