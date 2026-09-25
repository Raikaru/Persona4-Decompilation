/* CRI MWSTM read-sector setter. */
#include "adx_stm.h"

extern Sint32 func_004d2c98(ADXSTM stm, Sint32 nsct);

// FUN_00511F98 (MWSTM_SetRdSct): null handle skips the underlying setter.
Sint32 func_00511f98(ADXSTM stm, Sint32 nsct)
{
	if (stm == NULL)
		return 0;
	func_004d2c98(stm, nsct);
	return 0;
}

