/* Sofdec MPEG video: block decoder tables (zigzag scan, default intra quantiser matrix, run/level
 * VLC table pointers) set up in the decoder object */
#include "cri_xpt.h"
#include "mpv.h"

/* run/level VLC table entry pointers (mpv_vlc.c) */
extern Uint32 *mpvvlc_run_level_4;
extern Uint32 *mpvvlc_run_level_2;
extern Uint32 *mpvvlc_run_level_1;
extern Uint32 *mpvvlc_run_level_0a;
extern Uint32 *mpvvlc_run_level_0b;
extern Uint32 *mpvvlc_run_level_0c;

void DCT_FsriInitScanTbl(Sint8 *seq, Sint8 *scan);
void UTY_MemcpyDword(void *dst, const void *src, Sint32 ndword);
void *memcpy(void *dst, const void *src, Uint32 n);

static const Uint16 mpvbdec_bitmsk[16] = {
	0xFFFF, 0x7FFF, 0x3FFF, 0x1FFF, 0x0FFF, 0x07FF, 0x03FF, 0x01FF,
	0x00FF, 0x007F, 0x003F, 0x001F, 0x000F, 0x0007, 0x0003, 0x0001,
};

static const Sint8 zigzag2seq[64] = {
	0,  1,  8,  16, 9,  2,  3,  10, 17, 24, 32, 25, 18, 11, 4,  5,
	12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6,  7,  14, 21, 28,
	35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51,
	58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63,
};

static const Uint8 org_iqm[64] = {
	8,  16, 19, 22, 26, 27, 29, 34, 16, 16, 22, 24, 27, 29, 34, 37,
	19, 22, 26, 27, 29, 34, 34, 38, 22, 22, 26, 27, 29, 34, 37, 40,
	22, 26, 27, 29, 32, 35, 40, 48, 26, 27, 29, 32, 35, 40, 48, 58,
	26, 27, 29, 34, 38, 46, 56, 69, 27, 29, 35, 38, 46, 56, 69, 83,
};

static const Uint8 group_tbl[32] = {
	5, 4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

Uint8 mpvbdec_dfl_iqm[64];
Sint8 mpvbdec_zigzag[64]; /* Bio4.sym says local, but mpv_hdec imports it */

/* dead-stripped by the linker; its reference puts mpvbdec_dfl_iqm first in .bss */
Uint8 *MPVBDEC_GetDflIqm(void)
{
	return mpvbdec_dfl_iqm;
}

// Per-handle block decoder tables: the default MPEG-1 intra quantiser matrix in zigzag order, the
// zigzag scan and the bit masks the coefficient decoder uses.
void MPVBDEC_Init(MPV mpv)
{
	Sint8 seq[64];
	Sint8 scan[64];
	Sint32 i;
	Uint8 *iqm;
	Sint8 *zigzag;
	Uint16 *bitmsk;

	for (i = 0; i < 64; i++) {
		seq[i] = i;
	}
	DCT_FsriInitScanTbl(seq, scan);
	for (i = 0; i < 64; i++) {
		mpvbdec_zigzag[i] = scan[zigzag2seq[i]];
		mpvbdec_dfl_iqm[scan[i]] = org_iqm[i];
	}
	zigzag = mpv->zigzag;
	if (zigzag != NULL) {
		UTY_MemcpyDword(zigzag, mpvbdec_zigzag, sizeof(mpvbdec_zigzag) / 4);
	}
	bitmsk = mpv->bitmsk;
	if (bitmsk != NULL) {
		UTY_MemcpyDword(bitmsk, mpvbdec_bitmsk, sizeof(mpvbdec_bitmsk) / 4);
	}
	memcpy(mpv->group_tbl, group_tbl, sizeof(group_tbl));
	mpv->rl[0].tbl = mpvvlc_run_level_4 - 4;
	mpv->rl[0].bits = 21;
	mpv->rl[1].tbl = mpvvlc_run_level_2 - 8;
	mpv->rl[1].bits = 19;
	mpv->rl[2].tbl = mpvvlc_run_level_1 - 8;
	mpv->rl[2].bits = 18;
	mpv->rl[3].tbl = mpvvlc_run_level_0a - 8;
	mpv->rl[3].bits = 17;
	mpv->rl[4].tbl = mpvvlc_run_level_0b - 8;
	mpv->rl[4].bits = 16;
	mpv->rl[5].tbl = mpvvlc_run_level_0c - 8;
	mpv->rl[5].bits = 15;
}
