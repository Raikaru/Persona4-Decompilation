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

EffectStateHeader *edResBuildEffectHeader(const u32 *data);
void brpParamFree(u8 *allocation);
u32 brpParamGetEntry(const u32 *work, u32 index);
u32 brpParamReadWord4(const u32 *work);
u32 brpParamReadWord1(const u32 *work);

#endif
