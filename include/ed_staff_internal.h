#ifndef ED_STAFF_INTERNAL_H
#define ED_STAFF_INTERNAL_H

#include "type.h"

typedef struct {
    u32 id;
    u32 count;
    u32 entries;
    u32 strings;
    u32 data;
} EffectStateHeader;

EffectStateHeader *func_0038f400(const u32 *data);
void func_0038f590(u8 *allocation);
u32 func_0038f5c0(const u32 *work, u32 index);
u32 func_0038f5e0(const u32 *work);
u32 func_0038f5f0(const u32 *work);

#endif
