/* ACSSND status queries and the parameter block at offset 0x78. */
#include "cri_xpt.h"

extern Char8 D_00756EB0[];
extern Char8 D_00756EE8[];
extern Char8 D_00756F18[];
extern void func_004bd6a0(const void *message);

typedef Uint32 (*ACSSND_StatusOperation)(Uint32 handle);

// FUN_004BEDF0
Uint32 ACSSND_GetStatPause(Uint32 *object)
{
	Uint32 handle;

	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756EB0);
		return 4;
	}
	handle = object[0x08 / 4];
	return (*(ACSSND_StatusOperation *)(*(Uint32 *)handle + 0x20))(handle);
}

// FUN_004BEE38
Uint32 ACSSND_GetStat(Uint32 *object)
{
	Uint32 handle;

	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756EE8);
		return 4;
	}
	handle = object[0x08 / 4];
	return (*(ACSSND_StatusOperation *)(*(Uint32 *)handle + 0x24))(handle);
}

// FUN_004BEE80
Uint32 *ACSSND_GetCprm(Uint32 *object)
{
	if (object[0x50 / 4] == 0) {
		func_004bd6a0(D_00756F18);
		return NULL;
	}
	return object + 0x78 / 4;
}
