/* CRI Sofdec SFX stream info (sfx_inf.c): the component layout lookup. The tag parser was reduced to
 * a constant in this build: every stream is YCC 4:2:0 planar (0x11). */
#include "cri_xpt.h"

// Component layout of the stream: always SFX_COMPO_YCC420PLN (0x11).
Sint32 SFXINF_GetStmInf(void)
{
	return 0x11;
}
