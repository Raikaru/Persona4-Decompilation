#ifndef H_SND_INTERNAL_H
#define H_SND_INTERNAL_H

#include "type.h"

/* Forward the incoming cue word; sdkSndPlayCue consumes its signed low halfword. */
u8 hsndQueueSound(s32 id, s32 unused);

#endif
