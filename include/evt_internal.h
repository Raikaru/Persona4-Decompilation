#ifndef EVT_INTERNAL_H
#define EVT_INTERNAL_H

#include "type.h"

/* Retail float globals used as multipliers across Event, Kernel and Battle
   TUs. Names are the retail symbols; no further evidence yet. */
extern f32 iGpffff809c;
extern f32 iGpffff8218;


/* Existing callers supply these inputs; unused inputs are retained explicitly. */
s32 evtCreateEventTask(s32 majorId, s32 minorId, s32 unusedSubId);
s32 mtMiscRequestSoundTrack(s32 unused, s32 trackId, s32 unusedChannel);
s32 mtMiscFadeOutSoundChannel(s64 channel, s32 unusedCue);

#endif
