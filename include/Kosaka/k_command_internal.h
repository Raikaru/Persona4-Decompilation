#ifndef K_COMMAND_INTERNAL_H
#define K_COMMAND_INTERNAL_H

#include "type.h"
#define false 0
#define true 1


typedef struct Model Model;
extern u8 func_00106600(s16 value);
extern void func_0014a0f0(u16 resourceId, u32 value);
extern s32 func_0014b510(u32 type);
extern void func_00106550(s32 arg0, s32 arg1);
extern Model* func_00477e80(s32 type, u16 id, const char* path, s32 mode);
extern s32 func_00145ac0(u32 resourceId, Model* model);
extern Model* func_00478140(u16 type, u16 id, u32 mode);
extern u32 func_002bd360(s32 resourceId, s32 value);
extern s32 func_0029cc00(s32 index);
extern void func_0029cf50(s32 value);

#endif
