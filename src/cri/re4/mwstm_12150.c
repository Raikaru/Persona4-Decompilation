/* CRI MWSTM stream destruction and filename binding. */
#include "adx_stm.h"

extern void func_004d1ce8(ADXSTM stm);
extern void func_004d1f00(ADXSTM stm);
extern void func_004d1d70(ADXSTM stm, const Char8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
extern void func_004d23a8(ADXSTM stm, Sint32 nsct);

// FUN_00512150: passes a0 unchanged to the ADXSTM destruction wrapper.
void func_00512150(ADXSTM stm)
{
	func_004d1ce8(stm);
}

// FUN_00512168 (MWSTM_SetFname): request non-blocking file release, bind from
// sector zero without a directory, then set the end-of-stream sector count.
// The bind's fifth argument (0xFFFFF sectors) is passed in the EE ABI's t0.
void func_00512168(ADXSTM stm, const Char8 *fname)
{
	func_004d1f00(stm);
	func_004d1d70(stm, fname, NULL, 0, 0xFFFFF);
	func_004d23a8(stm, 0xFFFFF);
}
