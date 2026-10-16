#ifndef SHDPERSONA_INTERNAL_H
#define SHDPERSONA_INTERNAL_H

#include "type.h"

/* Persona block writers defined in src/shdPersona.c. `task` is the owning
 * SdkTask; the value lands in the persona block at +0x44 (handle value) or
 * +0x4C4 (extra value). */
void shdPersonaSetHandleValue(int task, u32 value);
void shdPersonaSetExtraValue(int task, u32 value);

#endif
