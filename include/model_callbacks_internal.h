#ifndef MODEL_CALLBACKS_INTERNAL_H
#define MODEL_CALLBACKS_INTERNAL_H

#include "type.h"

struct MdlAppObj;
typedef s32 (*MdlNameCallback)(u32 type, u16 id, char *output);
typedef s32 (*MdlTypeCallback)(u32 type, u16 id);
typedef s32 (*MdlSetupCallback)(void *model);
typedef s32 (*MdlDataCallback)(struct MdlAppObj *model);

s32 mdlSetModelCallbacks(MdlNameCallback nameCallback, MdlTypeCallback typeCallback,
                 MdlNameCallback pathCallback, MdlSetupCallback setupCallback,
                 MdlDataCallback dataCallback);
s32 mdlGetModelNameForId(u32 type, u16 id, char *output);
s32 mdlQueryModelType(u32 type, u16 id);
s32 mdlBuildModelPath(u32 type, u16 id, char *output);
void mdlRunSetupCallback(void *model);

/* Actor registration stores a 16-bit resource ID and a 16-bit mode. */
s32 MT_Scene_CreateModelCharRes(u16 id, void *model);
s32 MT_Scene_CreateModelCharShadowRes(u16 id, u16 mode, void *model);
s32 MT_Scene_CreateModelNpcShadowRes(u16 id, u16 mode, s32 model);
void *FldShadow_CreateCaster(u8 *parent, u16 id, u16 mode);

#endif
