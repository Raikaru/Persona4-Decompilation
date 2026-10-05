#ifndef K_CLUMP_PROPERTY_INTERNAL_H
#define K_CLUMP_PROPERTY_INTERNAL_H

#include "type.h"

struct RwFrame;

/* The selected integer property and the frame that owns it. */
typedef struct KClumpIntPropertyResult
{
    s32 value;
    struct RwFrame *frame;
} KClumpIntPropertyResult;

typedef char KClumpIntPropertyResultSize[
    (sizeof(KClumpIntPropertyResult) == 8) ? 1 : -1];

void func_00458430(KClumpIntPropertyResult *result, void *object,
                   const char *name, s32 index);

#endif
