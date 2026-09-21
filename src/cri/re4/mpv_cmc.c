#include "cri_xpt.h"

typedef struct {
	void *p;
	Sint32 n;
} MPVCMC_REF;

typedef struct {
	Sint32 ccnt;
	MPVCMC_REF rt[6];
} MPVCMC_OUTBLK;

typedef struct {
	Uint8 pad0[0xCC];
	Uint8 mc[0x120 - 0xCC]; /* 0xCC */
	MPVCMC_OUTBLK ob_rt;    /* 0x120 */
	MPVCMC_OUTBLK ob;       /* 0x154 */
	Uint8 pad188[0x1A4 - 0x188];
	Sint32 mcflag;          /* 0x1A4 */
	Uint8 pad1A8[0x280 - 0x1A8];
	Sint16 width;           /* 0x280 */
	Sint16 height;          /* 0x282 */
	Uint8 pad284[0xD00 - 0x284];
	Uint8 work[1];          /* 0xD00 */
} MPV_OBJ;

extern void MPVMC08_Init(void *mc);
extern void MPVMC16_Init(void *mc);
extern void MPVMC08_OneRef1p_TuneC(void);
extern void MPVMC08_OneRefH2_TuneC(void);
extern void MPVMC08_OneRefV2_TuneC(void);
extern void MPVMC08_OneRef4p_TuneC(void);

void (*mpvcmc_oneref[8])(void);

// Chroma block count for the output block tables: 4 when motion compensation writes chroma
// (mcflag), -1 otherwise.
void MPVCMC_SetCcnt(MPV_OBJ *mpv)
{
	Sint32 ccnt;

	if (mpv->mcflag == 0) {
		ccnt = -1;
	} else {
		ccnt = 4;
	}
	mpv->ob.ccnt = ccnt;
	mpv->ob_rt.ccnt = ccnt;
}

/* the block table is addressed through the output-block struct: `oi = ob->rt` is an addi off `ob`, and
 * add-propagation folds only `ob` (into the ccnt store), leaving `oi` as the stores' base register */
void MPVCMC_InitMcOiRt(MPV_OBJ *mpv)
{
	MPVCMC_OUTBLK *ob = &mpv->ob_rt;
	MPVCMC_REF *oi = ob->rt;
	Sint32 ccnt;
	Sint32 i;
	Sint32 w;
	Sint32 h;

	if (mpv->mcflag == 0) {
		ccnt = -1;
	} else {
		ccnt = 4;
	}
	ob->ccnt = ccnt;
	w = mpv->width;
	for (i = 0; i < 2; i++) {
		oi[i].n = w;
	}
	h = mpv->height;
	for (i = 2; i < 6; i++) {
		oi[i].n = h;
	}
}

// Per-handle motion-compensation setup: installs the 8x8 and 16x16 kernel tables, points the six
// output block descriptors at the work buffer with 8-pixel rows.
void MPVCMC_InitObj(MPV_OBJ *mpv)
{
	Uint8 *work;
	MPVCMC_OUTBLK *ob;
	MPVCMC_REF *oi;
	Sint32 ccnt;
	Sint32 i;

	MPVMC08_Init(mpv->mc);
	MPVMC16_Init(mpv->mc);
	ob = &mpv->ob;
	oi = ob->rt;
	work = mpv->work;
	if (mpv->mcflag == 0) {
		ccnt = -1;
	} else {
		ccnt = 4;
	}
	ob->ccnt = ccnt;
	for (i = 0; i < 6; i++) {
		oi[i].p = work;
	}
	for (i = 0; i < 6; i++) {
		oi[i].n = 8;
	}
}

// Library table of the 8x8 one-reference kernels by half-pel case (1p, H2, V2, 4p; repeated for
// the second reference).
void MPVCMC_Init(void)
{
	mpvcmc_oneref[0] = MPVMC08_OneRef1p_TuneC;
	mpvcmc_oneref[1] = MPVMC08_OneRefH2_TuneC;
	mpvcmc_oneref[2] = MPVMC08_OneRefV2_TuneC;
	mpvcmc_oneref[3] = MPVMC08_OneRef4p_TuneC;
	mpvcmc_oneref[4] = MPVMC08_OneRef1p_TuneC;
	mpvcmc_oneref[5] = MPVMC08_OneRefH2_TuneC;
	mpvcmc_oneref[6] = MPVMC08_OneRefV2_TuneC;
	mpvcmc_oneref[7] = MPVMC08_OneRefV2_TuneC;
}
