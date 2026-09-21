/* CRI LSC critical section (lsc_crs.c): the scheduler's lock, mapped to the stream-joint lock
 * (interrupts off); the mask argument is unused on GameCube. */
#include "cri_xpt.h"

extern void SJCRS_Lock(void);
extern void SJCRS_Unlock(void);

// Leaves the scheduler critical section.
void LSC_UnlockCrs(Sint32 *msk)
{
	SJCRS_Unlock();
}

// Enters the scheduler critical section.
void LSC_LockCrs(Sint32 *msk)
{
	Sint32 tmp; /* retail 0x429E08 prologue 27bdfff0 addiu sp,-16 + sd ra + jal 0x429D90 + ld ra (28B + 4B padding =32B window); prevents tail-call like libadxe lsc_crs.c */
	SJCRS_Lock();
	tmp = 0;
}
