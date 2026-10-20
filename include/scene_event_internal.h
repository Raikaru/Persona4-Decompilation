#ifndef SCENE_EVENT_INTERNAL_H
#define SCENE_EVENT_INTERNAL_H

#include "type.h"
#include "evt_record_collection_internal.h"

typedef struct SVec3 {
    f32 x, y, z;
} SVec3;

typedef struct EvtNode EvtNode;
typedef struct EvtEventTask EvtEventTask;
typedef struct EvtEventWork EvtEventWork;

/* Event node kinds (EvtNode::kind), with the handler each one dispatches to in
   D_0063C420 (evtDispatchNode). Only kinds with a named handler are listed;
   kinds 0, 2, 3, 8, 9, 11-18, 20-27, 29-32, 34, 35, 38-46 have no handler, and
   kinds 6, 10 and 36 are unnamed (func_0028A7C0, func_0028A850, func_0028A8E0).
   Dispatch order is D_0063C1D0 (evtKeyIndex). Kind 48 shares its handler with
   kind 1 [inferred: a second kind bound to the same routine]. Kinds 34 and 38 have no handler but are searched by kind (evtUpdateWaitState, evtSelectRangeChoice). */
typedef enum EvtNodeKind {
    EVT_NODE_RES_COMMAND = 1,          /* evtNodeResCommand */
    EVT_NODE_MESSAGE_SELECT = 4,       /* evtNodeMessageSelect */
    EVT_NODE_PLAY_CUE = 5,             /* evtCmdPlayCue */
    EVT_NODE_RANGE_FLAG = 7,           /* evtCmdRangeFlag */
    EVT_NODE_SOUND_CUE = 19,           /* evtNodeSoundCue */
    EVT_NODE_DRAW_OR_RUMBLE = 28,      /* evtNodeDrawOrRumble */
    EVT_NODE_CAMERA_MOVE = 33,         /* evtNodeCameraMove */
    EVT_NODE_WAIT_SEARCH = 34,        /* evtUpdateWaitState: no handler, looked up by kind */
    EVT_NODE_RES_PLACE = 37,           /* evtCmdResPlace */
    EVT_NODE_CHOICE_RANGE = 38,       /* evtSelectRangeChoice: no handler, looked up by kind */
    EVT_NODE_RES_DISPLAY = 47,         /* evtCmdResDisplay */
    EVT_NODE_RES_COMMAND_ALT = 48,     /* evtNodeResCommand [inferred] */
    EVT_NODE_RES_ENABLE = 49,          /* evtCmdResEnable */
    EVT_NODE_PLAY_STREAM = 50,         /* evtCmdPlayStream */
    EVT_NODE_LABEL_TEXT = 51,          /* evtCmdLabelText */
    EVT_NODE_TASK_SLOT = 52,           /* evtCmdTaskSlot */
    EVT_NODE_ENV_SLOT = 53,            /* evtCmdEnvSlot */
    EVT_NODE_SOUND_TRACK = 54,         /* evtNodeSoundTrack */
    EVT_NODE_SCREEN_COLOR = 55,        /* evtCmdScreenColor */
    EVT_NODE_TASK_HANDLE = 56,         /* evtCmdTaskHandle */
    EVT_NODE_CAM_POS = 57              /* evtCmdCamPos */
} EvtNodeKind;

/* Handler signature of D_0063C420 and D_00882204[0]: (mode, arg0, arg1, node, aux). */
typedef s32 (*EvtDispatchHandler)(s32, s32, s32, u8 *, u8 *);
/* Dispatch order: 58 s32 entries, a permutation of EvtNodeKind 0..57. evtKeyIndex inverts it. */
extern s32 D_0063C1D0[58];
/* Handler per EvtNodeKind, 58 entries, indexed by owner->kind in evtDispatchNode. */
extern EvtDispatchHandler D_0063C420[58];

/* Four colour bytes, copied as one word (evtNpcModelTaskUpdate). */
typedef struct EvtColor {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} EvtColor;

typedef struct EvtChildNode EvtChildNode;

/* Child node (0x54 bytes), created by evtNodeCreate from its parent's kind.
   The payload at +0x10 is typed per parent kind (union below). Only the
   offsets the matched code writes are named; unk_ fields have no proven role. */
typedef struct EvtPayloadByte { u8 unk00; } EvtPayloadByte;
typedef struct EvtPayloadKind01 { u8 unk00; u8 pad01[5]; u8 unk06; u8 unk07; } EvtPayloadKind01;
typedef struct EvtPayloadKind02 { f32 unk00; } EvtPayloadKind02;
typedef struct EvtPayloadKind03 { s8 unk00; u8 pad01; s16 unk02; s8 unk04; s8 unk05; s16 unk06; s16 unk08; } EvtPayloadKind03;
typedef struct EvtPayloadKind06 { u16 unk00; s16 unk02; } EvtPayloadKind06;
typedef struct EvtPayloadKind09 { s16 unk00; s16 unk02; } EvtPayloadKind09;
typedef struct EvtPayloadKind0A { f32 unk00; f32 unk04; s16 unk08; } EvtPayloadKind0A;
typedef struct EvtPayloadKind0C { s16 unk00; s16 unk02; u32 unk04; } EvtPayloadKind0C;
typedef struct EvtPayloadKind14 { s8 unk00; s8 unk01; s16 unk02; s8 unk04; s8 unk05; s8 unk06; s8 unk07; s16 unk08; } EvtPayloadKind14;
typedef struct EvtPayloadKind16 { s16 unk00; } EvtPayloadKind16;
typedef struct EvtPayloadKind21 { s16 unk00; u8 pad02[6]; u32 unk08; u32 unk0C; u32 unk10; u32 unk14; u32 unk18; u32 unk1C; } EvtPayloadKind21;
typedef struct EvtPayloadKind23 { u8 pad00; u8 unk01; u8 pad02[2]; u16 unk04; } EvtPayloadKind23;
typedef struct EvtPayloadKind24 { u8 pad00; u8 unk01; } EvtPayloadKind24;
typedef struct EvtPayloadKind29 { s8 unk00; } EvtPayloadKind29;
typedef struct EvtPayloadKind34 { u8 pad00[2]; u8 unk02; } EvtPayloadKind34;
/* Kind 0x35: the environment slot (evtEnvSlotSave stores the light and camera state). */
typedef struct EvtEnvSlotPayload { u8 unk00; u8 pad01[3]; u8 unk04; u8 unk05; u8 unk06; u8 pad07; u8 unk08; u8 unk09; u8 unk0A; u8 pad0B; f32 unk0C; f32 unk10; } EvtEnvSlotPayload;

/* Per-kind payloads recovered by evtMain; all begin at child offset +0x10. */
typedef struct EvtMovieDefaultPayload {
    u8 unk00, unk01;
    u8 pad02[2];
    u16 unk04, unk06;
    u8 unk08, unk09, unk0A, unk0B;
    f32 unk0C, unk10;
    u8 unk14;
} EvtMovieDefaultPayload;
typedef struct EvtHalfwordPayload {
    union { u16 halfword; u8 byte; } value;
    s16 unk02;
} EvtHalfwordPayload;
typedef struct EvtDisplayPayload {
    s8 operation;
    u8 pad01;
    u16 resourceId;
    s8 motionGroup;
    s8 restartMode;
    s16 motionIndex;
    s16 startTime;
    s16 speedPercent;
} EvtDisplayPayload;
typedef struct EvtPlacementPayload {
    s8 operation;
    s8 slot;
    union { struct { s8 resource; s8 enabled; } spawn; s16 duration; u8 color; } value02;
    union { SVec3 position; s16 colorDuration; } value04;
    SVec3 angles;
} EvtPlacementPayload;
typedef struct EvtMessagePayload {
    u8 pad00[4];
    s8 waitMode;
    u8 pad05;
    s8 style;
} EvtMessagePayload;
typedef struct EvtLabelPayload {
    u8 pad00[4];
    s16 letter;
    s16 value;
} EvtLabelPayload;
typedef struct EvtTintPayload {
    u8 enabled;
    u8 pad01[3];
    u8 lightRed, lightGreen, lightBlue;
    u8 pad07;
    u8 ambientRed, ambientGreen, ambientBlue;
    u8 pad0B;
    f32 cameraValue;
    f32 value;
} EvtTintPayload;
typedef struct EvtScreenColorPayload {
    u8 red, green, filter, blue;
} EvtScreenColorPayload;
typedef struct EvtTogglePayload {
    u8 enabled;
} EvtTogglePayload;
typedef struct EvtCameraPositionPayload {
    f32 x, y;
} EvtCameraPositionPayload;
typedef struct EvtStreamPayload {
    s8 operation;
    s8 value01, value02, value03;
} EvtStreamPayload;
typedef struct EvtSoundCuePayload {
    s16 operation;
    s16 cue;
} EvtSoundCuePayload;
typedef struct EvtDrawPayload {
    s8 operation;
    u8 pad01[3];
    s16 firstValue, secondValue, thirdValue, fourthValue;
} EvtDrawPayload;
typedef struct EvtRangeChoicePayload {
    s16 destinationFrame;
    s16 length;
} EvtRangeChoicePayload;
typedef struct EvtLayerChoicePayload {
    s8 operation;
    u8 pad01[3];
    s8 layer;
    s8 motionGroup;
    s8 restartMode;
    s8 motionIndex;
    u8 pad08[8];
    s16 startTime;
    s8 recordMode;
    s8 enableRecord;
    s8 recordGroup;
    s8 recordDisabled;
    s16 recordIndex;
    s16 speedPercent;
    s16 recordSpeedPercent;
} EvtLayerChoicePayload;
typedef struct EvtWaitPayload {
    s8 operation;
} EvtWaitPayload;

/* Resource-command operands have different widths for each operation. */
typedef struct EvtResCommandPayload {
    s8 operation;
    u8 pad01[3];
    union {
        f32 yaw;
        s16 duration;
        u8 color;
        s8 argument;
        struct { s8 argument, mode; s16 speed; } move;
    } value04;
    union {
        SVec3 position;
        u16 duration;
        s32 attachment;
        struct { u8 color; s8 mode; } tint;
    } value08;
    union {
        struct { s8 loop, timed, rotate; u8 pad17; } path;
        s16 duration;
    } value14;
    f32 pitch;
    f32 yaw;
} EvtResCommandPayload;

typedef struct EvtCutinPayload {
    s8 operation;
    u8 pad01[3];
    s16 firstCode, secondCode;
    u8 pad08[4];
    s16 x, y;
    s8 noCodes;
} EvtCutinPayload;

typedef struct EvtChannelCuePayload { s16 cue; s8 operation; } EvtChannelCuePayload;
typedef struct EvtFadePayload { s16 operation, mode; s8 colorIndex; } EvtFadePayload;

typedef union EvtChildPayload {
    EvtResCommandPayload resCommand;
    EvtCutinPayload cutin;
    EvtChannelCuePayload channelCue;
    EvtFadePayload fade;
    EvtPayloadKind01 kind01;
    EvtPayloadKind02 kind02;
    EvtPayloadKind03 kind03;
    EvtPayloadKind03 kind1A;
    EvtPayloadKind06 kind06;
    EvtPayloadKind09 kind09;
    EvtPayloadKind0A kind0A;
    EvtPayloadKind0C kind0C;
    EvtPayloadKind14 kind14;
    EvtPayloadKind16 kind16;
    EvtPayloadKind21 kind21;
    EvtPayloadKind23 kind23;
    EvtPayloadKind24 kind24;
    EvtPayloadByte kind27;
    EvtPayloadKind29 kind29;
    EvtPayloadByte kind30;
    EvtPayloadKind34 kind34;
    EvtEnvSlotPayload envSlot;
    EvtMovieDefaultPayload movieDefaults;
    EvtHalfwordPayload halfword;
    EvtDisplayPayload display;
    EvtPlacementPayload placement;
    EvtMessagePayload message;
    EvtLabelPayload label;
    EvtTintPayload tint;
    EvtScreenColorPayload screenColor;
    EvtTogglePayload toggle;
    EvtCameraPositionPayload cameraPosition;
    EvtStreamPayload stream;
    EvtSoundCuePayload soundCue;
    EvtDrawPayload draw;
    EvtRangeChoicePayload rangeChoice;
    EvtLayerChoicePayload layerChoice;
    EvtWaitPayload wait;
} EvtChildPayload;

struct EvtChildNode {
    u16 start;                /* +0x00: sort key, compared by evtAppendNodeToList and evtFindBestChoice */
    u16 unk02;                /* +0x02: cleared by kind 0x35 */
    s32 unk04;                /* +0x04: -1 on create, 0 for kind 0x0A */
    u8 unk08[0x08];
    union {
        struct {
            EvtChildPayload payload;  /* +0x10..+0x2F: payload typed by the parent kind */
            u8 unk30;                 /* +0x30: kind 0x30 stores the parent's param04 here */
            u8 unk31[3];
            s16 scalePercent;         /* +0x34: resource-placement uniform scale */
            u8 pad36[2];
        };
        EvtRecordParameters recordPayload; /* +0x10..+0x37: serialized words before per-kind narrowing */
        struct {
            u8 pad10[0x20];
            s8 surface;
            u8 pad31[3];
            s8 flags, sound, period, delay;
        } motionSound;
    };
    u32 kind;                 /* +0x38: the parent's kind */
    u8 unk3C[0x04];
    u32 ownedBlock40;         /* +0x40: heap block freed with the child */
    u8 unk44[0x04];
    u32 ownedBlock48;         /* +0x48: heap block, freed unless the owner kind is 0x12 */
    EvtChildNode *childNext;  /* +0x4C: next sibling in the parent's child list */
    EvtChildNode *childPrev;  /* +0x50: previous sibling */
};

/* Top-level event node (0x98 bytes), in EvtEventWork.nodeList. Only offsets the
   matched code reads are named; the rest is padding. */
struct EvtNode {
    u32 kind;                 /* +0x00: switched on by evtResetEventScene */
    s32 param04;              /* +0x04: per-kind argument read by evtNodeCreate */
    s32 unk08;                /* +0x08: initialized to -1 */
    u16 flags;                /* +0x0C: resource id in the low 10 bits */
    u8 pad0E[0x0E];
    s16 frameOffset;          /* +0x1C: key-selection frame offset */
    s8 lightMode;             /* +0x1E: light-pose binding mode */
    u8 pad1F;
    u16 lightResource;        /* +0x20: mode-3 light resource id */
    u8 pad22[0x12];
    void *res;                /* +0x34: scene resource (evtNodeSetRes) */
    u8 unk38[0x18];
    EvtColor color;           /* +0x50: colour copied in by evtNpcModelTaskUpdate */
    u32 resData;              /* +0x54: data offset read from the resource */
    u8 unk58[0x08];
    s32 timedFlag;            /* +0x60: 1 when the node is flagged for a duration */
    s32 childCount;           /* +0x64 */
    EvtChildNode *childHead;  /* +0x68 */
    EvtChildNode *childTail;  /* +0x6C */
    u8 *layerChoice[4];       /* +0x70: cached layer-choice keys */
    u8 pad80[0x10];
    EvtNode *next;            /* +0x90: next node in the event's list */
    EvtNode *prev;            /* +0x94: previous node in the event's list */
};

/* Event task work block (0x60 bytes), stored by evtCreateEventTask. */
struct EvtEventTask {
    s32 state;                /* +0x00: 0 create, 3/4 run, 5 wait for loader idle (evtLoaderIsIdle), 6 done */
    u8 unk04[0x08];
    s32 eventTask;            /* +0x0C: handle returned by evtStart */
    u8 unk10[0x50];
};

/* Saved light/camera state, 0x14 bytes per event environment slot. */
typedef struct EvtEnvironmentSlot {
    u32 flags;
    u32 lightColor;
    u32 ambientColor;
    f32 cameraValue;
    f32 value;
} EvtEnvironmentSlot;

/* Channel ids occupy the low halfword of four-byte event resource entries.
 * The partial array describes its first record; release iterates the stored count. */
typedef struct EvtSoundChannel { s16 id; u8 pad02[2]; } EvtSoundChannel;
typedef struct EvtSoundChannels { s32 count; EvtSoundChannel entries[1]; } EvtSoundChannels;

/* Event work block (0x7B0 bytes): kwlnTaskGetWork of EvtEventTask.eventTask. */
struct EvtEventWork {
    s32 waitFlags;            /* +0x00: wait bits cleared by evtUpdateNodeWaitFlags */
    u8 *sceneSource;          /* +0x04: scene source block (evtPolygonMovieAlloc); nonzero while a message is attached */
    u32 frameCount;           /* +0x08 */
    s32 startFrame;           /* +0x0C */
    s32 frameLimit;           /* +0x10 */
    s32 frame;                /* +0x14 */
    s32 lastFrame;            /* +0x18 */
    s32 resetRequested;       /* +0x1C */
    s32 resetFrame;           /* +0x20 */
    u8 unk24[0x20];
    s8 flags44;               /* +0x44: bit 2 set by fade mode 7 */
    u8 pad45[3];
    s32 nodeCount;            /* +0x48 */
    EvtNode *nodeList;        /* +0x4C */
    EvtNode *nodeTail;        /* +0x50 */
    u32 initialized;          /* +0x54 */
    u8 pad58[0x10];
    EvtEnvironmentSlot environment[2]; /* +0x68 */
    u8 pad90[8];
    f32 savedCamera[2];       /* +0x98: camera x/y */
    u8 padA0[0x1A];
    s16 resultSlot;           /* +0xBA: message selection result slot */
    u8 padBC[0xD4 - 0xBC];
    EvtSoundChannels sound;   /* +0xD4: channel-resource list released with the event */
    u8 padDC[0x12C - 0xDC];
    u8 *cameraResource;       /* +0x12C: camera record owner used by evtNodeLoadCameraRecords */
    u8 pad130[0x524 - 0x130];
    s32 exclusiveKind;        /* +0x524: kind 0/1 selects exclusive scene resource */
    u8 pad528[0x5D0 - 0x528];
    s32 effectTable;          /* +0x5D0: effect table handle */
    s32 busy;                 /* +0x5D4: nonzero while the event is busy */
    u8 unk5D8[0xA0];
    union {
        u8 messageWindow[0x4C]; /* +0x678: original byte-addressed window API */
        struct {
            u8 pad00[8];
            s32 manager;        /* +0x680: itfMes manager handle */
            u8 pad0C[0x10];
            s32 unk694;         /* +0x694: base preceding the kind-indexed resource slots */
            s32 slots[5];       /* +0x698: EVT_FUNCTION_000C substitution values */
            u8 pad34[0x18];
        } messageControl;
    };
    s32 waitTask[3];          /* +0x6C4: tasks watched by the 0x200/0x400/0x800 waits */
    s32 taskSlots[3];         /* +0x6D0: filter child tasks */
    u8 pad6DC[0x74];
    f32 fov;                  /* +0x750: field of view (K_View_GetFov) */
    u8 unk754[4];
    s32 fadeActive;           /* +0x758 */
    s32 linkedTask;           /* +0x75C: task watched by the 0x4000 wait */
    s32 scriptLoad;           /* +0x760: script load handle for the 0x80000 wait */
    u8 unk764[4];
    u32 noiseTask;            /* +0x768 */
    s32 loadState;            /* +0x76C: script loader state (0..14); state 14 resets to 0 */
    s32 loadFlags;            /* +0x770: 0x1 load requested (evtRequestLoad), 0x2 loader idle */
    u32 pending;             /* +0x774 */
    u8 unk778[4];
    s32 readerHandle;         /* +0x77C: PM file reader handle (evtPMFileReaderCreate) */
    s32 streamTask;           /* +0x780: sound stream task (sdkSndCreateStreamTask) */
    u8 unk784[0x04];
    s32 readerMode;           /* +0x788: table-allocation mode passed to evtPMFileReaderCreate */
    s32 eventId[3];           /* +0x78C..+0x794: event id words (evtSetId) */
    u8 unk798[8];
    s32 handleCount;          /* +0x7A0 */
    union {
        s32 address;
        s32 *words;
        u8 **blocks;
        u8 *bytes;
    } handles;               /* +0x7A4: resource copies released by evtClearHandles */
    u8 pad7A8[8];
};

/* mt_misc scene source record: the arg0 block of mtMiscBuildScene and its
   collect helpers (src/Event/mt_misc_inferred_002962f0.c). Offsets are the
   ones the readers use; names follow the offsets until a role is proven. */
typedef struct MtMiscSceneHeader MtMiscSceneHeader;
typedef struct MtMiscSceneRecord16 MtMiscSceneRecord16;
typedef struct EvtSceneRecord EvtSceneRecord;
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
    union { u8 unk_06[2]; s16 value06; };
    s16 unk_08;               /* 0x08 */
    s16 unk_0a;               /* 0x0A */
    s8 unk_0c;                /* 0x0C */
    s8 unk_0d;                /* 0x0D */
    s8 unk_0e;                /* 0x0E */
    u8 unk_0f;
};

/* 0x3C-byte record of the scene event table at +0x98 (and +0xA4). Read by the
   mt_misc collectors (src/Event/mt_misc_inferred_002962f0.c) and by the event
   record loader (src/Event/evtLoadSave.c). Coordinates sit at +0x0C; payload
   from +0x14 is read per kind. */
struct EvtSceneRecord
{
    u16 type;                 /* 0x00. Compared with 5, 0x13 and 4 */
    u16 id;                   /* 0x02 */
    u16 unk_04;               /* 0x04 */
    union {
        u8 unk_06[6];
        struct { s16 value06; u16 count08; s16 value0A; };
    };
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
    EvtSceneRecord *records98;   /* 0x98 */
    u8 unk_9c[0x08];          /* 0x9C */
    EvtSceneRecord *recordsA4;   /* 0xA4 */
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
