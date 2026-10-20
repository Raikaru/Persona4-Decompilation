#ifndef FIELD_TRANSITION_INTERNAL_H
#define FIELD_TRANSITION_INTERNAL_H
#include "type.h"

/* Getters widen the stored unsigned-halfword values to the word return ABI.
 * Environment selection takes words; its provider explicitly narrows field
 * and room values before looking up the environment state. */
s32 FldLoadTaskFieldId(u8 *task);
s32 FldLoadTaskRoomId(u8 *task);
s32 FldLoadTaskMapState(u8 *task);
s32 FldEnvStateFromCalendar(s32 fieldKind, s32 baseState);
s32 FldEnvResolveState(s32 fieldKind, s32 baseState, s32 condition);

/* Field IDs travel as words; the file provider explicitly selects low 16 bits. */
u8 *FldHbnOpenTable(s32 fieldId, s32 roomId);

/* Creates the field-area task and returns the registration handle. */
s32 FldNoiseTaskCreate(u8 *task);
#endif
