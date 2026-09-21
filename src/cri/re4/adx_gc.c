/* CRI ADX GameCube extension (adx_gc.c): per-handle switch for the AX sampling-rate correction. */
#include "cri_xpt.h"

typedef struct {
	Uint8 pad[0xC];
	void *rna;
} ADXT_OBJ;

extern void ADXRNA_SetAdjsfreqFlg(void *rna, Sint32 flg);

// Enables (1) / disables the renderer's 32028.5 Hz DSP rate correction for this handle's voices.
// FUN_004CD5C0
void ADXGC_SetAdjsfreqFlg(ADXT_OBJ *adxt, Sint32 flg)
{
	ADXRNA_SetAdjsfreqFlg(adxt->rna, flg);
}
