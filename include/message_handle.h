#ifndef MESSAGE_HANDLE_H
#define MESSAGE_HANDLE_H

#include "type.h"

/* Message-manager entries are indexed by a signed handle, not an object
 * pointer. The selected row and choice count are signed halfword fields, returned
 * as sign-extended integers just like the flags getter. */
s32 func_00277070(s32 handle);
s32 func_00279010(s32 handle);
s32 func_00278110(s32 handle);
s32 func_0027bec0(s32 handle);

#endif
