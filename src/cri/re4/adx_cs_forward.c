/* ADX sound adapters: pass the four incoming ABI words unchanged to the underlying sound object. */
#include "cri_xpt.h"

extern Uint32 ACSSND_StartFname();
extern Uint32 ACSSND_StartAfs();
extern Uint32 ACSSND_StartMem();
extern Uint32 ACSSND_StartMemIdx();
extern Uint32 ACSSND_Stop();
extern Uint32 ACSSND_Pause();
extern Uint32 ACSSND_GetStatPause();
extern Uint32 ACSSND_GetStat();
extern Uint32 ACSSND_GetCprm();
extern void func_004beeb8(Uint32 object, Uint32 value);
extern Sint32 func_004beec0(Uint32 object);
extern Uint32 ACSSND_SetOutVol();
extern Uint32 func_004bf0e0(Uint32 object);
extern Uint32 ACSSND_SetTrackVol();
extern Uint32 func_004bf0e8();
extern Uint32 ACSSND_SetLpFlg();
extern void func_004bf1e8(Uint32 object, Uint32 value);
extern void func_004bf1f0(Uint32 object, Uint32 value);
extern void func_004bf1f8(Uint32 object, Uint32 value);
extern Uint32 func_004bf200(Uint32 object);
extern Uint32 func_004bf208(Uint32 object);
extern Uint32 func_004bf210(Uint32 object);
extern void func_004bf218(Uint32 object, Uint32 value);
extern Uint32 func_004bf220(Uint32 object);
extern void func_004bf228(Uint32 object, Uint32 value);
extern Uint32 func_004bf230(Uint32 object);

// FUN_004D8D30
Uint32 func_004d8d30(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_StartFname(a0, a1, a2, a3);
}

// FUN_004D8D48
Uint32 func_004d8d48(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_StartAfs(a0, a1, a2, a3);
}

// FUN_004D8D60
Uint32 func_004d8d60(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_StartMem(a0, a1, a2, a3);
}

// FUN_004D8D78
Uint32 func_004d8d78(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_StartMemIdx(a0, a1, a2, a3);
}

// FUN_004D8D90
Uint32 func_004d8d90(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_Stop(a0, a1, a2, a3);
}

// FUN_004D8DA8
Uint32 func_004d8da8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_Pause(a0, a1, a2, a3);
}

// FUN_004D8DC0
Uint32 func_004d8dc0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetStatPause(a0, a1, a2, a3);
}

// FUN_004D8DD8
Uint32 func_004d8dd8(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetStat(a0, a1, a2, a3);
}

// FUN_004D8DF0
Uint32 func_004d8df0(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_GetCprm(a0, a1, a2, a3);
}

// FUN_004D8E08
void func_004d8e08(Uint32 object, Uint32 value)
{
	func_004beeb8(object, value);
}

// FUN_004D8E20
Sint32 func_004d8e20(Uint32 object)
{
	return func_004beec0(object);
}

// FUN_004D8E38
Uint32 func_004d8e38(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_SetOutVol(a0, a1, a2, a3);
}

// FUN_004D8E50
Uint32 func_004d8e50(Uint32 object)
{
	return func_004bf0e0(object);
}

// FUN_004D8E68
Uint32 func_004d8e68(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_SetTrackVol(a0, a1, a2, a3);
}

// FUN_004D8E80
Uint32 func_004d8e80(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return func_004bf0e8(a0, a1, a2, a3);
}

// FUN_004D8E98
Uint32 func_004d8e98(Uint32 a0, Uint32 a1, Uint32 a2, Uint32 a3)
{
	return ACSSND_SetLpFlg(a0, a1, a2, a3);
}

// FUN_004D8EB0
void func_004d8eb0(Uint32 object, Uint32 value)
{
	func_004bf1e8(object, value);
}

// FUN_004D8EC8
void func_004d8ec8(Uint32 object, Uint32 value)
{
	func_004bf1f0(object, value);
}

// FUN_004D8EE0
void func_004d8ee0(Uint32 object, Uint32 value)
{
	func_004bf1f8(object, value);
}

// FUN_004D8EF8
Uint32 func_004d8ef8(Uint32 object)
{
	return func_004bf200(object);
}

// FUN_004D8F10
Uint32 func_004d8f10(Uint32 object)
{
	return func_004bf208(object);
}

// FUN_004D8F28
Uint32 func_004d8f28(Uint32 object)
{
	return func_004bf210(object);
}

// FUN_004D8F40
void func_004d8f40(Uint32 object, Uint32 value)
{
	func_004bf218(object, value);
}

// FUN_004D8F58
Uint32 func_004d8f58(Uint32 object)
{
	return func_004bf220(object);
}

// FUN_004D8F70
void func_004d8f70(Uint32 object, Uint32 value)
{
	func_004bf228(object, value);
}

// FUN_004D8F88
Uint32 func_004d8f88(Uint32 object)
{
	return func_004bf230(object);
}
