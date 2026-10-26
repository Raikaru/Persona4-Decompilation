#ifndef CRI_VOICE_INTERNAL_H
#define CRI_VOICE_INTERNAL_H

#include "type.h"

/* PS2RNA voice counts, not the unrelated SVM flag test-and-set interface. */
void criConfigureVoiceCounts(s32 stereoVoices, s32 monoVoices);
void criSetVoiceCounts(s32 stereoVoices, s32 monoVoices);

#endif
