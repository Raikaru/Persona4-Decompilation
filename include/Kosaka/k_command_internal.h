#ifndef K_COMMAND_INTERNAL_H
#define K_COMMAND_INTERNAL_H

#include "type.h"
#include "Kosaka/k_model_internal.h"
#define false 0
#define true 1


typedef struct Model Model;
extern s32 datItemCount(s16 itemId);
extern void SceneDraw_SetResVisible(u16 resTypeId, u32 visible);
extern u16 MT_Scene_FindFreeResId(s32 resourceType);
extern void datSetScriptValue(s32 index, s32 value);
extern void* mdlCreateModelObjectFromData(u32 type, u16 id, void* resource, u32 flags);
extern s32 MT_Scene_CreateModelFldRes(u16 resourceId, s32 model);
extern u32 fclMiscHasEntry(s32 slotIndex, s32 record);
extern s32 scrGetParamInt(s32 paramIdx);
extern void scrSetReturnInt(s32 retVal);

#endif
