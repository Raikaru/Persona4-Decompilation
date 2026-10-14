#ifndef MT_SCENE_INTERNAL_H
#define MT_SCENE_INTERNAL_H

#include "type.h"

/* Resource record for a type id. Owner: src/Scene/mt_scene.c. Retail callers index the result as a byte pointer. */
u8 *MT_Scene_GetRes(u16 resTypeId);

#endif
