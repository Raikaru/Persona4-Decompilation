#ifndef MODEL_CALLBACKS_INTERNAL_H
#define MODEL_CALLBACKS_INTERNAL_H

#include "type.h"

struct MdlAppObj;
typedef s32 (*MdlNameCallback)(u32 type, u16 id, char *output);
typedef s32 (*MdlTypeCallback)(u32 type, u16 id);
typedef s32 (*MdlSetupCallback)(void *model);
typedef s32 (*MdlDataCallback)(struct MdlAppObj *model);

s32 func_0047d090(MdlNameCallback nameCallback, MdlTypeCallback typeCallback,
                 MdlNameCallback pathCallback, MdlSetupCallback setupCallback,
                 MdlDataCallback dataCallback);
s32 func_0047d0b0(u32 type, u16 id, char *output);
s32 func_0047d0e0(u32 type, u16 id);
s32 func_0047d110(u32 type, u16 id, char *output);
void func_0047d140(void *model);

#endif
