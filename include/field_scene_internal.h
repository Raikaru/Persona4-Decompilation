#ifndef FIELD_SCENE_INTERNAL_H
#define FIELD_SCENE_INTERNAL_H

#include "type.h"

/* Scene load/unload write full IDs; resource opens consume their low halfword. */
typedef union FieldSceneId {
    s32 value;
    u16 half[2];
} FieldSceneId;

/* The field-board resource creator indexes sixteen template pointers at
 * 0x28. The step destructor clears all sixteen native words. Preserve both
 * pointer and integer address transports used by those consumers. */
typedef union FieldSceneTemplateResource {
    void *resource;
    u32 address;
    s32 signedAddress;
} FieldSceneTemplateResource;

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
    s32 templateCount;          /* 0x24: active board-template resources */
    FieldSceneTemplateResource templates[16]; /* 0x28 */
    void *primaryTasks[4];      /* 0x68 */
    void *secondaryTasks[4];    /* 0x78 */
    s32 sceneFlags;             /* 0x88: FldRootCreate input */
    u8 pad8c[4];
    s32 loadState;              /* 0x90 */
    s32 timer;
} FieldSceneState;

#endif
