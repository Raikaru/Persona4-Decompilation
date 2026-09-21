/* CRI Sofdec SFX picture user data (sfx_sud.c): keeps the "<SUDPS_>" record of the current frame
 * and answers the colour-space (C) and field-division (D) type flags read from it. */
#include "cri_xpt.h"

typedef struct {
	Uint8 pad[0x60];
	void *usrdat;
	Sint32 usrdat_size;
} SFX_OBJ;

extern Sint32 SUD_AnalyTypeCcs(void *dat, Sint32 size);
extern Sint32 SUD_AnalyTypeDivField(void *dat, Sint32 size);
extern void SUD_Init(void);

// Whether the current picture's user data asks for colour-space conversion ('C' at byte 0x13).
Sint32 SFX_GetTypeCcs(SFX_OBJ *sfx)
{
	return SUD_AnalyTypeCcs(sfx->usrdat, sfx->usrdat_size);
}

// Whether the current picture's user data marks the frame as two fields ('D' at byte 0x12).
Sint32 SFX_GetTypeDivField(SFX_OBJ *sfx)
{
	return SUD_AnalyTypeDivField(sfx->usrdat, sfx->usrdat_size);
}

// The current frame's user data record (from mwPlyGetCurFrm).
void SFX_SetPicUsrDat(SFX_OBJ *sfx, void *dat, Sint32 size)
{
	sfx->usrdat = dat;
	sfx->usrdat_size = size;
}

// SUD module init.
void SFXSUD_Init(void)
{
	SUD_Init();
}
