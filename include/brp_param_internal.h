#ifndef BRP_PARAM_INTERNAL_H
#define BRP_PARAM_INTERNAL_H

#include "type.h"

/* Result-screen parameter helpers defined in brp_param.c. */
/* Releases a block through the battle heap free jump table. */
void brpParamFree(u8 *allocation);
/* Returns the entry at index from the table at work[2]. */
u32 brpParamGetEntry(const u32 *work, u32 index);
/* Returns the word at byte offset 0x10 of the work block. */
u32 brpParamReadWord4(const u32 *work);
/* Returns the word at byte offset 0x04 of the work block. */
u32 brpParamReadWord1(const u32 *work);
/* Makes arg0 the current result-parameter block and zeroes its first two words. */
void brpParamSetCurrent(u8 *work);

#endif
