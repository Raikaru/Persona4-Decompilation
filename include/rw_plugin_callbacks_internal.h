#ifndef RW_PLUGIN_CALLBACKS_INTERNAL_H
#define RW_PLUGIN_CALLBACKS_INTERNAL_H

#include "type.h"

/* Identity callbacks retain the pointer and the complete registered interface. */
void *func_003b7a80(void *destination, const void *source, s32 offset, s32 size);
void *func_003cad80(void *destination, const void *source, s32 offset, s32 size);
void *func_003bf1c0(void *object, s32 offset, s32 size);
void *func_003bf1f0(void *object, s32 offset, s32 size);
void *func_003caee0(void *object, s32 offset, s32 size);
void *func_003b82b0(void *stream, s32 binaryLength, const void *object, s32 offset, s32 size);

#endif
