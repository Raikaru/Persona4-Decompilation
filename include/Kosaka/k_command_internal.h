#ifndef K_COMMAND_INTERNAL_H
#define K_COMMAND_INTERNAL_H

#include "type.h"
#include "Kosaka/k_model_internal.h"
#define false 0
#define true 1


typedef struct Model Model;
extern s32 datItemCount(s16 id);
extern void SceneDraw_SetResVisible(u16 resourceId, u32 value);
extern u16 MT_Scene_FindFreeResId(s32 type);
extern void func_00106550(s32 arg0, s32 arg1);
extern void* mdlCreateModelObjectFromData(u32 type, u16 id, void* path, u32 mode);
extern s32 MT_Scene_CreateModelFldRes(u16 resourceId, s32 model);
extern u32 fclMiscHasEntry(s32 resourceId, s32 value);
extern s32 scrGetParamInt(s32 index);
extern void scrSetReturnInt(s32 value);

#endif
