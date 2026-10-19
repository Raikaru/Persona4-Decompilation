#ifndef K_MISC_WORK_INTERNAL_H
#define K_MISC_WORK_INTERNAL_H

#include "type.h"

typedef struct Model Model;

/* KMisc_CreateDelayMdlFree allocates 12 bytes; the update callback reads all three words. */
typedef struct DelayMdlFreeWork
{
    s32 state;
    s32 countdown;
    Model *mdl;
} DelayMdlFreeWork;

/* KMisc_CreateRmdFade allocates 0x14 bytes; state one denotes completion. */
typedef struct RmdFadeWork {
    s32 state;
    Model *mdl;
    f32 targetAlpha, currentAlpha;
    s32 framesRemaining;
} RmdFadeWork;

#endif
