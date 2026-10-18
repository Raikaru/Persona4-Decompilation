#ifndef FIELD_SCENE_INTERNAL_H
#define FIELD_SCENE_INTERNAL_H

#include "type.h"

/* Scene load/unload write full IDs; resource opens consume their low halfword. */
typedef union FieldSceneId {
    s32 value;
    u16 half[2];
} FieldSceneId;

typedef struct FieldSceneState {
    FieldSceneId field;
    FieldSceneId room;
    void *resourceManager;
    s32 flags;                 /* loaded=1, primary request=2, secondary request=4 */
    s16 primaryRoom;
    s16 secondaryRoom;
    s32 unk14;
    u8 pad18[4];
    void *sceneTask;
    void *filterTask;
    u8 pad24[0x44];
    void *primaryTasks[4];      /* 0x68 */
    void *secondaryTasks[4];    /* 0x78 */
    u8 pad88[8];
    s32 loadState;              /* 0x90 */
    s32 timer;
} FieldSceneState;

#endif
