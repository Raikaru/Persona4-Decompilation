/* Source unit: sfd_trn.c */
#include "cri_xpt.h"

extern void func_005277a0(Sint32 object, Sint32 row, Sint32 slot, Sint32 value);
extern void sftrn_ConnBufTrn(Sint32 object, Sint32 row, Sint32 value);

// FUN_00527700
void sftrn_BuildUsr(Sint32 object)
{
	sftrn_ConnBufTrn(object, 7, 8);
}

// FUN_00527720
void func_00527720(Sint32 object, Sint32 row, Sint32 value)
{
	func_005277a0(object, row, 0, value);
}

// FUN_00527740
void func_00527740(Sint32 object, Sint32 row, Sint32 value)
{
	func_005277a0(object, row, 0, value);
}

// FUN_00527760
void sftrn_ConnTrnBufA(Sint32 object, Sint32 row, Sint32 value)
{
	func_005277a0(object, row, 1, value);
}

// FUN_00527780
void sftrn_ConnTrnBufU(Sint32 object, Sint32 row, Sint32 value)
{
	func_005277a0(object, row, 2, value);
}
