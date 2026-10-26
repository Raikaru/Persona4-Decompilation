/* ADX stream-joint format accessors forward through the block decoder at offset 4. */
#include "adx_sjd_internal.h"

extern Uint32 func_004c3bc0();

// FUN_004CED78
Uint32 func_004ced78(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c3bc0(*(Uint32 *)((Uint8 *)a0 + 4), a1, a2, a3);
}

// Sampling rate in Hz of the current stream.
// FUN_004CED90
Sint32 ADXSJD_GetSfreq(ADXSJD sjd)
{
	return ADXB_GetSfreq(sjd->adxb);
}

// Output channel count, including the block decoder's mono upmix rule.
// FUN_004CEDA8
Sint32 ADXSJD_GetNumChan(ADXSJD sjd)
{
	return ADXB_GetNumChan(sjd->adxb);
}
