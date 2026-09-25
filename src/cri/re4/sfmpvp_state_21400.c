/* Sofdec MPEG-player state address at retail 00521400. */
#include "cri_xpt.h"

// FUN_00521400
Uint8 *func_00521400(Uint8 *player)
{
	return *(Uint8 **)(player + 0x1fc0) + 0x1150;
}
