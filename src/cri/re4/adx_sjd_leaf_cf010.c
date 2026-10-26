/* Adjacent retail stream-joint header/format metadata accessors. */
#include "adx_sjd_internal.h"

// Header byte count retained by the stream-joint decoder.
// FUN_004CF010
Sint32 ADXSJD_GetHdrLen(ADXSJD sjd)
{
	return sjd->hdrlen;
}

// Decoder format bits per sample.
// FUN_004CF018
Sint32 ADXSJD_GetFmtBps(ADXSJD sjd)
{
	return ADXB_GetFmtBps(sjd->adxb);
}
