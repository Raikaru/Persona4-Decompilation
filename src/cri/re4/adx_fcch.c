/* CRI ADXF cache control (adx_fcch.c): the data-cache invalidate the file layer applies to a buffer
 * before the DVD DMA writes into it. */
#include "cri_xpt.h"

extern void DCInvalidateRange(void *addr, Uint32 nbytes);

// Invalidates the data cache over the DMA target range (DCInvalidateRange).
void ADXF_Ocbi(void *addr, Uint32 nbytes)
{
	DCInvalidateRange(addr, nbytes);
}
