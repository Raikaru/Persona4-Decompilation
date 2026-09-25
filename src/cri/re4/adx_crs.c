/* CRI ADX critical section (adx_crs.c): level storage and initialization.
 * The contiguous SVM lock/unlock adapters live in adx_crs_lock.c. */
#include "cri_xpt.h"

Sint32 adxcrs_lvl;
static Sint32 adxcrs_msk;

// Resets the nesting level.
void ADXCRS_Init(void)
{
	adxcrs_lvl = 0;
}
