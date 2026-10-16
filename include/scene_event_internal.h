#ifndef SCENE_EVENT_INTERNAL_H
#define SCENE_EVENT_INTERNAL_H

#include "type.h"

typedef struct SVec3 {
    f32 x, y, z;
} SVec3;

typedef struct EvtNode EvtNode;
typedef struct EvtEventTask EvtEventTask;
typedef struct EvtEventWork EvtEventWork;

/* Four colour bytes, copied as one word (evtNpcModelTaskUpdate). */
typedef struct EvtColor {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} EvtColor;

/* Event node (src/Event/evtMain.c, evtEvent.c). Only offsets the matched
   code reads are named; the rest is padding. */
struct EvtNode {
    u32 kind;                 /* +0x00: switched on by evtResetEventScene */
    u8 unk04[0x08];
    u16 flags;                /* +0x0C: resource id in the low 10 bits */
    u8 unk0E[0x26];
    void *res;                /* +0x34: scene resource (evtNodeSetRes) */
    u8 unk38[0x18];
    EvtColor color;           /* +0x50: colour copied in by evtNpcModelTaskUpdate */
    u32 resData;              /* +0x54: data offset read from the resource */
    u8 unk58[0x08];
    s32 timedFlag;            /* +0x60: 1 when the node is flagged for a duration */
    u8 unk64[0x2C];
    EvtNode *next;            /* +0x90: next node in the event's list */
    EvtNode *prev;            /* +0x94: previous node in the event's list */
};

/* Event task work block (0x60 bytes), stored by evtCreateEventTask. */
struct EvtEventTask {
    s32 state;                /* +0x00: 0 create, 3/4 run, 5 wait for mark, 6 done */
    u8 unk04[0x08];
    s32 eventTask;            /* +0x0C: handle returned by evtStart */
    u8 unk10[0x50];
};

/* Event work block: kwlnTaskGetWork of EvtEventTask.eventTask. */
struct EvtEventWork {
    s32 waitFlags;            /* +0x00: wait bits cleared by evtUpdateNodeWaitFlags */
    s32 hasMessage;           /* +0x04: nonzero while a message is attached */
    u8 unk08[0x08];
    s32 frameLimit;           /* +0x10 */
    s32 frame;                /* +0x14 */
    s32 lastFrame;            /* +0x18 */
    s32 resetRequested;       /* +0x1C */
    s32 resetFrame;           /* +0x20 */
    u8 unk24[0x24];
    s32 nodeCount;            /* +0x48 */
    EvtNode *nodeList;        /* +0x4C */
    EvtNode *nodeTail;        /* +0x50 */
    u8 unk54[0x580];
    s32 busy;                 /* +0x5D4: nonzero while the event is busy */
    u8 unk5D8[0xA0];
    u8 messageWindow[0x4C];   /* +0x678: message window, runs to at least +0x6C4 */
    s32 waitTask[3];          /* +0x6C4: tasks watched by the 0x200/0x400/0x800 waits */
    u8 unk6D0[0x8C];
    s32 linkedTask;           /* +0x75C: task watched by the 0x4000 wait */
    s32 scriptLoad;           /* +0x760: script load handle for the 0x80000 wait */
};

/* mt_misc scene source record: the arg0 block of mtMiscBuildScene and its
   collect helpers (src/Event/mt_misc_inferred_002962f0.c). Offsets are the
   ones the readers use; names follow the offsets until a role is proven. */
typedef struct MtMiscSceneHeader MtMiscSceneHeader;
typedef struct MtMiscSceneRecord16 MtMiscSceneRecord16;
typedef struct MtMiscSceneRecord60 MtMiscSceneRecord60;
typedef struct MtMiscSceneSource MtMiscSceneSource;

struct MtMiscSceneHeader
{
    u8 unk_00[0x14];
    s32 kind;                 /* 0x14. Kind 4 selects the 0x10-byte table at +0x94 */
};

/* 0x10-byte record, the table at +0x94 when the header kind is 4. */
struct MtMiscSceneRecord16
{
    u16 type;                 /* 0x00. Compared with 4 */
    u16 id;                   /* 0x02 */
    u16 unk_04;               /* 0x04 */
    u8 unk_06[2];
    s16 unk_08;               /* 0x08 */
    s16 unk_0a;               /* 0x0A */
    s8 unk_0c;                /* 0x0C */
    s8 unk_0d;                /* 0x0D */
    s8 unk_0e;                /* 0x0E */
    u8 unk_0f;
};

/* 0x3C-byte record, the tables at +0x98 and +0xA4. */
struct MtMiscSceneRecord60
{
    u16 type;                 /* 0x00. Compared with 5, 0x13 and 4 */
    u16 id;                   /* 0x02 */
    u16 unk_04;               /* 0x04 */
    u8 unk_06[6];
    s16 position[4];          /* 0x0C. Four halfwords copied into the scene node */
    s16 unk_14;               /* 0x14 */
    union {
        s16 word;             /* 0x16. Read as a halfword by types 4 and 19 */
        s8 byte;              /* 0x16. Read as a byte by type 5 */
    } unk_16;
    s8 unk_18[3];             /* 0x18 */
    u8 unk_1b[0x21];
};

/* Scene source block passed as arg0 to the mt_misc scene collectors. */
struct MtMiscSceneSource
{
    u8 unk_00[0x58];
    s32 count58;              /* 0x58. Node count for the first loop */
    u8 unk_5c[0x24];
    MtMiscSceneHeader *header;        /* 0x80. Kind is read through this */
    u8 unk_84[0x0C];
    s32 *headerWords;         /* 0x90. Nine words copied into the scene */
    MtMiscSceneRecord16 *records94;   /* 0x94 */
    MtMiscSceneRecord60 *records98;   /* 0x98 */
    u8 unk_9c[0x08];          /* 0x9C */
    MtMiscSceneRecord60 *recordsA4;   /* 0xA4 */
    s32 countA8;              /* 0xA8. Count when the header kind is 6 or more */
    s32 countAC;              /* 0xAC. Count when the header kind is below 6 */
};

/* Scene node written by mtMiscBuildSceneNodes (src/Event/mt_misc_inferred_00294280.c).
   Two vectors at +0x38 and +0x44 and four bytes at +0x50; names follow the offsets. */
typedef struct MtMiscSceneNode MtMiscSceneNode;
struct MtMiscSceneNode
{
    u8 unk_00[0x08];
    s32 unk_08;               /* 0x08. Set to -1 when the node is created */
    u8 unk_0c[0x2C];
    SVec3 unk_38;             /* 0x38 */
    SVec3 unk_44;             /* 0x44 */
    u8 unk_50[4];             /* 0x50 */
};

/* Transform pointers address three consecutive floats; NULL leaves that
   transform unchanged. Resource IDs contain the packed 16-bit type/index. */
void MT_Scene_SetResPlacement(u16 resourceId, u8 *position, u8 *angles);
void MT_Scene_SetResAngles(u16 resourceId, u8 *scale);

s32 MT_Scene_BeginResTimedMove(u32 resourceId, SVec3 *position, u32 duration, s8 easing);
s32 MT_Scene_SetResCurveParamsById(u32 resourceId, u8 *fromPosition, u8 *toPosition,
                  f32 fromYaw, f32 toYaw, f32 fromPitch, f32 toPitch,
                  f32 fromDistance, f32 toDistance, s32 duration, s8 easing);
s32 MT_Scene_BeginResRotation(u32 resourceId, SVec3 *angles, u32 duration, u8 easing);
s32 MT_Scene_BeginResFovChange(u32 resourceId, f32 fieldOfView, s32 duration);
s32 MT_Scene_ResetResMotion(u32 resourceId);
void MT_Scene_ClearResState(u32 resourceId);

/* The matrix output is sixteen words; both input vectors contain three floats. */
void MT_Scene_BuildResMatrix(u32 *matrix, const void *position, u32 *angles);

/* The path address refers to a complete 304-byte count/flags/vector record. */
u32 MT_Scene_BeginResPathAnimById(u32 resourceId, u32 pathAddress, f32 speed, u32 loop);
s32 MT_Scene_SetResSoundRange(u32 resourceId, s32 motion, u8 sound, s16 start, s16 end, s16 flags);
void evtModelQueueMotion(u16 resourceId, s32 motion, f32 speed);
void evtModelQueueTimedMotion(u16 resourceId, u16 duration, s32 motion, f32 speed);
void evtModelQueueMotionAt(u16 resourceId, s32 motion, f32 positionX, f32 positionY,
                  f32 positionZ, f32 angle, s32 flags, u8 *settings);

/* Queued animation records store signed 32-bit motion and frame values.
   The model provider narrows them to the signed/unsigned 16-bit model API. */
u32 MT_Scene_SetResMotion(u16 *resource, s32 layer, s32 animation, s32 frame,
                  s32 flags, s32 blend, f32 speed);

/* Path sampling keeps elapsed and total distances together before outputs. */
f32 MT_Scene_SamplePath(s8 *path, f32 distance, f32 total,
                  f32 *position, f32 *rotation);

extern s32 D_00882170[];

/* Event TU prototypes: functions defined in src/Event and the scene-event bucket. */
void evtMenuClearSlots(void);
void evtSetNodeResourcesEnabled();
s32 evtFindTask(void);
void evtDestroyEventScene(u8 *arg0, s32 arg1);
void evtEnvSlotRestore(int, int);
void evtCamPosRestore(int);
u64 mtMiscStopSoundChannel(s16 param_1, int param_2);
void evtUpdateCutin(u8 *, u8 *, u8 *, s32, u8 *);
void evtSelectRangeChoice();
void sceneLightSlotsReset(void);
void evtSyncResManagerNodes();
void evtStepLayerByChoice();
void evtModelDestroy(void);
void evtSetKindExclusiveRes();
void evtResetPendingState(int param_1);
void fclBankCancelPending(void);
void evtReleaseRes(u8 *arg0);
void evtMessageWindowResetTyped(u32 *param_1);
void evtCustomEventReleaseRes(void);
void evtEffectTableDestroy(u8 *arg0);
void evtPolygonMovieFree(s32 *arg0, u32 *arg1);
void mtMiscClearAllSlotRes();
void mtMiscSetSlotRes();
void mtMiscClearSlotRes();
s32 evtDecodeNodeKey(s32, u8 *, s32 *, s32 *);
void evtMessageWindowRequest(s32 *, s32, s32, s32, s32);
s32 evtMessageWindowEntryValue(u8 *, s32);
void evtMemAccount(s32 arg0, s32 arg1);
s32 evtSlotTableIdle(void);
s32 evtCheckCondition(u8 *arg0);
void evtListInsertSorted(u32 *, u32 *);
s32 evtKeyIndex(s32 arg0);
extern void *evtEnvSlot(int arg0, int arg1);
void evtPolygonMovieLerpPose(s32 arg0, f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3);
void sceneLightSlotSet(s32 slot, s32 mode, s32 modeValue, f32 *arg3, f32 *arg4, f32 *arg5);
f32 evtCommandParamF32(s32 param);
void evtMainSetFlag(int param_1);
void evtFindNodeRange(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3);
void evtInterpolateNodeMatrices(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, f32 *arg4, f32 *arg5);
void evtAppendNodeToList(u8 *arg0, u8 *arg1);
s32 mtMiscGetSlotRes(int param_1, int param_2);
u32 evtMessageWindowIsOpen(u32 *object);
s32 evtMessageWindowIsDone(void *object);
void evtMessageWindowClose(u32 *param_1);

#endif
