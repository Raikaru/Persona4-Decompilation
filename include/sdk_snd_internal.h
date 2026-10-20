#ifndef SDK_SND_INTERNAL_H
#define SDK_SND_INTERNAL_H

#include "type.h"

void sdkSndLoadDecodeBuffers(s16 index, s16 fileIndex, void *data0, u32 data0Size,
                   void *data1, u32 data1Size, void *data2, u32 data2Size);
void sdkSndStopStreamSlot(s16 index, s16 stream);
void sdkSndStartStreamSlot(s16 index, s16 stream, s16 value, s16 flags);
s32 sdkSndStopStream(s16 index, s16 stream);
s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);

#endif
