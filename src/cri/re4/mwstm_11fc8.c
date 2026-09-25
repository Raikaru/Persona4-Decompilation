/* CRI MWSTM stream positioning wrappers. */
#include "adx_stm.h"

extern Sint32 func_004d2038(ADXSTM stm, Sint32 nsct);
extern Sint32 func_004d20a0(ADXSTM stm);
extern Sint32 func_004d2cf8(ADXSTM stm);
extern Sint32 func_004d2128(ADXSTM stm);

// FUN_00511FC8 (MWSTM_SeekSct): origin 0 is absolute, 1 is current,
// and 2 is the file size in bytes rounded up to a sector, then offset.
Sint32 func_00511fc8(ADXSTM stm, Sint32 nsct, Sint32 origin)
{
	if (origin == 0) {
		func_004d2038(stm, nsct);
	} else if (origin == 1) {
		func_004d2038(stm, func_004d20a0(stm) + nsct);
	} else if (origin == 2) {
		Sint32 size = func_004d2cf8(stm);
		func_004d2038(stm, (size + 2047) / 2048 + nsct);
	}
	return 0;
}

// FUN_00512068: ADXSTM call's return value is discarded by this wrapper.
Sint32 func_00512068(ADXSTM stm)
{
	func_004d2128(stm);
	return 0;
}
