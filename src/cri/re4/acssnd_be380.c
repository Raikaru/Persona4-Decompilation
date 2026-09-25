/* ACSS sound channel query and clamped channel gain control. */
#include "cri_xpt.h"

extern Uint32 func_004deec0(Uint32 handle, Uint32 channel);
extern Uint32 func_004d51c0(Uint32 handle);
extern Uint32 func_004dfd78(Uint32 handle, Sint32 channel, Sint32 gain);

// FUN_004BE380
Uint32 func_004be380(Uint32 *object)
{
	return func_004d51c0(func_004deec0(object[1], 0));
}

// FUN_004BE3A8
Uint32 func_004be3a8(Uint32 *object, Sint32 channel, Sint32 gain)
{
	if (gain < -960) {
		gain = -960;
	}
	return func_004dfd78(object[1], channel, gain);
}
