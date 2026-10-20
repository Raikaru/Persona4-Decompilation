#ifndef CALENDAR_FADE_INTERNAL_H
#define CALENDAR_FADE_INTERNAL_H

#include "type.h"

/* func_00122430 allocates 0x20 bytes. fade.c sets mode/duration and starts
 * the counter; fadeTaskStep owns the state, draw enable and child task. */
typedef struct CalendarFade {
    s32 state;              /* 0x00: transition state, 0..7 */
    s32 mode;               /* 0x04: rectangle, wipe, mesh or calendar change */
    s32 duration;           /* 0x08: counter limit */
    s32 counter;            /* 0x0C: advances/recedes once per task step */
    s32 drawEnabled;        /* 0x10: bit 0 enables the render callback */
    s32 changeRequested;    /* 0x14: request calendar synchronization */
    s32 specialRequested;   /* 0x18: one-shot mode-4 child request */
    s32 childTask;          /* 0x1C: polled until task state 3 */
} CalendarFade;

#endif
