#ifndef MESSAGE_HANDLE_H
#define MESSAGE_HANDLE_H

#include "type.h"

/* Message-manager entries are indexed by a signed handle, not an object
 * pointer. The selected row and choice count are signed halfword fields, returned
 * as sign-extended integers just like the flags getter. */
s32 itfMesWindowGetAnimAux(s32 handle);
s32 itfMesWindowGetChoiceCount(s32 handle);
s32 itfMesWindowGetFlags(s32 handle);
s32 itfMsgWindowCanDraw(s32 handle);

#endif
