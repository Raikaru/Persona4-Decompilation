#ifndef MODEL_CALLBACKS_INTERNAL_H
#define MODEL_CALLBACKS_INTERNAL_H

#include "type.h"

struct MdlAppObj;
typedef s32 (*MdlNameCallback)(s32 type, s32 id, char *output);
typedef u8 (*MdlTypeCallback)(u16 type);
typedef s32 (*MdlSetupCallback)(void *model);
typedef s32 (*MdlDataCallback)(struct MdlAppObj *model);

s32 func_0047d090(MdlNameCallback nameCallback, MdlTypeCallback typeCallback,
                 MdlNameCallback pathCallback, MdlSetupCallback setupCallback,
                 MdlDataCallback dataCallback);
void func_0047d140(void *model);

#endif
