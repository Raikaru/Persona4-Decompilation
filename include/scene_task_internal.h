#ifndef SCENE_TASK_INTERNAL_H
#define SCENE_TASK_INTERNAL_H

#include "type.h"

/* MT_Scene_SpawnIconTask allocates eight bytes. Its update counts down two
 * frames before destroying the effect; its destructor also handles early exit. */
typedef struct SceneIconWork {
    s32 remainingFrames;
    union { s32 handle; u8 *effect; } value;
} SceneIconWork;

/* Prefix read by the scene wrappers. The manager is the 22-entry list table;
 * the two sort switches are tested independently by resrcMngRenderTask. */
typedef struct SceneContext {
    s32 majorId;
    s32 minorId;
    union { s32 handle; u8 *pointer; } manager;
    u8 pad0C[8];
    s32 sortCharacters;
    s32 sortNpcs;
    u8 pad1C[4];
    s32 environment;
} SceneContext;

/* cldTimeChangeCreate allocates 0x18 bytes; update and draw share this block. */
typedef struct CldTimeChangeWork {
    s32 state;
    union { s32 handle; u8 *pointer; } sprites;
    s32 drawQueue;
    s32 firstPeriod;
    s32 secondPeriod;
    s32 elapsedFrames;
} CldTimeChangeWork;

/* Partial day-change work: request and completion callbacks prove this prefix. */
typedef struct CldDayChangeRequest {
    s32 state;
    s32 flags;
    u8 pad08[8];
    s32 currentDay;
    s32 requestedDay;
} CldDayChangeRequest;

/* Shape payload read by cldShapeDraw; the list allocator owns the prefix. */
typedef struct CldShapeEntry {
    u8 pad00[4];
    s32 tableIndex;
    u8 pad08[0x20];
    f32 position[4];
} CldShapeEntry;

typedef struct CldShapeNode {
    u8 pad00[0xC];
    struct CldShapeNode *link0C;
    u8 pad10[4];
    CldShapeEntry *entry;
} CldShapeNode;

typedef struct CldShapeList {
    u8 pad00[8];
    CldShapeNode *head;
    u8 pad0C[4];
    u16 count;
} CldShapeList;

typedef struct CldShapeWork {
    CldShapeList *list;
    f32 elapsed;
    f32 scale;
    s32 alpha;
} CldShapeWork;

#endif
