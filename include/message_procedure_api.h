#ifndef MESSAGE_PROCEDURE_API_H
#define MESSAGE_PROCEDURE_API_H

#include "type.h"

/* Message handles select present manager entries at indices 0..63. The work
 * getter retains its existing address-word return contract in this interface. */
s32 func_00277840(s32 handle);

/* Opaque userdata at procedure work+0x18, plus its optional first-word writer. */
void *func_0027BE60(s32 handle);
void func_0027be90(s32 handle, void *userdata);
void func_002818a0(s32 handle, s32 value);

#endif
