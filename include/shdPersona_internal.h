#ifndef SHDPERSONA_INTERNAL_H
#define SHDPERSONA_INTERNAL_H

#include "type.h"

/* Footstep state writers defined in src/shdPersona.c. `task` is the owning
 * SdkTask; the value lands in the per-task work block. */
void func_0011b9e0(int task, u32 value);
void func_0011b9f0(int task, u32 value);

#endif
