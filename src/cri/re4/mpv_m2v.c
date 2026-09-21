/* CRI Sofdec MPV MPEG-2 hooks (mpv_m2v.c): the MPEG-2 video decoder is not built into this
 * library; every MPVM2V_* entry is a stub that fails (-1) or does nothing, so an MPEG-2 stream cannot
 * be decoded (m2v_mode 2 paths in mpv_frm / mpv_hdec). */
#include "cri_xpt.h"

// No MPEG-2 decoder: -1.
Sint32 MPVM2V_DecodeFrm(void)
{
	return -1;
}

// No MPEG-2 decoder: -1.
Sint32 MPVM2V_DecodePicAtr(void)
{
	return -1;
}

// No-op.
void MPVM2V_SetCond(void)
{
}

// No-op.
void MPVM2V_Destroy(void)
{
}

// NULL: no MPEG-2 decoder object.
void *MPVM2V_Create(void)
{
	return NULL;
}

// No-op.
void MPVM2V_Finish(void)
{
}

// No-op.
void MPVM2V_Init(void)
{
}
