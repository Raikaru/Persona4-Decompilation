/* CRI MWSTM wrappers for the ADX stream controller. */
#include "cri_xpt.h"
#include "adx_stm.h"

extern Sint32 func_004d2c30(ADXSTM stm, Sint32 min_nsct, Sint32 max_nsct);
extern Sint32 func_004d2b80(ADXSTM stm, Sint32 *min_nsct, Sint32 *max_nsct);
extern Sint32 func_004d2cf8(ADXSTM stm);
extern Sint32 func_004d31e8(ADXSTM stm);

// FUN_005120B0
void func_005120b0(void)
{
}

// FUN_005120B8
void func_005120b8(ADXSTM stm, Sint32 min_nsct, Sint32 max_nsct)
{
	if (stm != NULL) {
		func_004d2c30(stm, min_nsct, max_nsct);
	}
}

// FUN_005120E0
Sint32 func_005120e0(ADXSTM stm, Sint32 *min_nsct, Sint32 *max_nsct)
{
	return func_004d2b80(stm, min_nsct, max_nsct);
}

// FUN_005120F8
void func_005120f8(ADXSTM stm, Sint32 *size)
{
	*size = func_004d2cf8(stm);
}

// FUN_00512120
Sint32 func_00512120(ADXSTM stm)
{
	return func_004d31e8(stm);
}
