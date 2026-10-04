#ifndef FIELD_TRANSITION_INTERNAL_H
#define FIELD_TRANSITION_INTERNAL_H
#include "type.h"

/* Getters widen the stored unsigned-halfword values to the word return ABI.
 * Environment selection takes words; its provider explicitly narrows field
 * and room values before looking up the environment state. */
s32 func_00156170(u8 *task);
s32 func_00156180(u8 *task);
s32 func_00156190(u8 *task);
s32 func_001546a0(s32 field, s32 room);
s32 func_00154720(s32 field, s32 room, s32 condition);

/* Field IDs travel as words; the file provider explicitly selects low 16 bits. */
u8 *func_0015ff20(s32 fieldId, s32 roomId);

/* Creates the field-area task and returns the registration handle. */
s32 func_00186640(u8 *parent);
#endif
