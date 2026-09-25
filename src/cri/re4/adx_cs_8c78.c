/* ADX sound-server adapters: inject the shared server context before forwarding arguments. */
#include "cri_xpt.h"

extern volatile Uint32 D_00725290;
extern Uint32 D_00725294;

extern Sint32 ACSSVR_Init();
extern void ACSSVR_Finish();
extern Uint32 ACSSVR_CreatSnd();
extern void func_004c0a40();
extern Sint32 func_004c0ab8();

// FUN_004D8C78
Sint32 func_004d8c78(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	Uint32 server = D_00725294;
	/* Retail also reads this adjacent word, without using its value. */
	(void)D_00725290;
	return ACSSVR_Init(server, a1, a2, a3);
}

// FUN_004D8CA0
void func_004d8ca0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	ACSSVR_Finish(D_00725294, a1, a2, a3);
}

// FUN_004D8CC0
Uint32 func_004d8cc0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSVR_CreatSnd(D_00725294, a0, a1, a2);
}

// FUN_004D8CF0
void func_004d8cf0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	func_004c0a40(D_00725294, a0, a2, a3);
}

// FUN_004D8D10
Sint32 func_004d8d10(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004c0ab8(D_00725294, a0, a2, a3);
}
