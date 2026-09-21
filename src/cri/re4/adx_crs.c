/* CRI ADX critical section (adx_crs.c): the ADX layer's lock/unlock, mapped onto the SVM lock
 * callbacks (which the game never installs, so these are no-ops at run time). */
#include "cri_xpt.h"

extern void SVM_Lock(void);
extern void SVM_Unlock(void);

Sint32 adxcrs_lvl;
static Sint32 adxcrs_msk;

// Leaves the ADX critical section (SVM_Unlock).
void ADXCRS_Unlock(void)
{
	SVM_Unlock();
}

// Enters the ADX critical section (SVM_Lock); guards handle state shared with the server callbacks.
void ADXCRS_Lock(void)
{
	SVM_Lock();
}

// Resets the nesting level.
void ADXCRS_Init(void)
{
	adxcrs_lvl = 0;
}
