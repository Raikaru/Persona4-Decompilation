#ifndef MESSAGE_PROCEDURE_API_H
#define MESSAGE_PROCEDURE_API_H

#include "type.h"

/* Message handles select present manager entries at indices 0..63. The work
 * getter retains its existing address-word return contract in this interface. */
s32 itfMesWindowGetSubTable(s32 handle);

/* Window procedure op numbers with one meaning in every window kind. Ops 4-7,
 * 9 and 11-18 differ by kind and are not listed. */
typedef enum ItfMesWindowOp {
    ITF_MES_WINDOW_OP_LAYOUT_LISTS = 8
} ItfMesWindowOp;

/* Opaque userdata at procedure work+0x18, plus its optional first-word writer. */
void *func_0027BE60(s32 handle);
void fclMesWindowSetUserData(s32 handle, void *userdata);
void msgWinStoreSlot(s32 handle, s32 value);

#endif
