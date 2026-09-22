/* CRI Sofdec MPEG video: 8x8 inverse DCT of the six blocks of a macroblock ("fsri": paired-single
 * separable IDCT with the row pass into the work buffer and the column pass written as 16-bit
 * pixels through GQR7). DC-only blocks are filled directly. The index helper interleaves two rows
 * of a block into one 16-entry row (the layout of the paired-single tables). */
#include "cri_xpt.h"
#include "mpv.h"

extern const Char8 *DCT_GetVerStr(void);
extern void DCT_AcInit(void);
extern void DCT_AcIdctDouble(Float64 *in, Float64 *out);
extern void *memset(void *dst, int c, Uint32 n);

/* DCT parameter block (MPV_OBJ + 0x78) */
typedef struct {
	Sint8 cbp[6];                   /* 0x00 block coded flags (0: DC only) */
	Uint8 pad06[0x18 - 0x06];
	Sint32 cnt0;                    /* 0x18 */
	Sint32 cnt1;                    /* 0x1C */
	Uint8 pad20[0x28 - 0x20];
	Sint32 cbp_msk;                 /* 0x28 coded block pattern, MSB first */
	Float32 *blk;                   /* 0x2C six 8x8 coefficient blocks */
	Sint16 **tbl;                   /* 0x30 output block pointers */
	Uint8 pad34[0x48 - 0x34];
	Uint8 *work;                    /* 0x48 row pass work buffer */
	Uint8 pad4C[0x54 - 0x4C];
} DCT_PA;

/* paired-single constants: C4 (x2), C6/C2 ... and the +-0.5 rounding pair for ps_sel */
Float32 B0TableOrg[12] = {
	1.4142135381698608f, 1.4142135381698608f, 2.613126039505005f, 2.613126039505005f,
	1.0823922157287598f, 1.0823922157287598f, 0.7653668522834778f, 0.7653668522834778f,
	0.5f, 0.5f, -0.5f, -0.5f,
};

Float32 PreIDCT[64][64];
Float64 sfsd_scale_tbl[64];
const Char8 *dctfsri_version_dummy;

static const Float64 scale8[8] = {
	0.3535533905932738, 0.4903926402016152, 0.46193976625564337, 0.4157348061512726,
	0.3535533905932738, 0.2777851165098011, 0.1913417161825449, 0.09754516100806414,
};

// IDCT of the macroblock's six blocks selected by `cbp` (bit per block, -1 = all): DC-only blocks
// are filled with their DC value, the others go through the paired-single row pass (via the
// PreIDCT tables) and column pass, written as 16-bit pixels through GQR7 into the output block
// pointers of the DCT parameter block.
void DCT_FsriTransCore(DCT_PA *pa, Sint32 cbp)
{
	register Sint8 *flg = pa->cbp;
	register Float32 *blk;
	register Sint16 **tbl;
	register Uint8 *work;
	register Float32 *src;
	register Uint8 *dst;
	register Sint32 cnt;
	register Sint16 *o;
	register Float32 *p;
	Sint32 i;
	int k;
	Float32 dc;
	Sint32 n;
	Uint32 *out;

	work = pa->work;
	p = B0TableOrg;
	
	blk = pa->blk;
	tbl = pa->tbl;
	for (i = 0; i < 6; i++) {
		if (cbp < 0) {
			if (flg[0] == 0) {
				dc = blk[0];
				out = (Uint32 *)tbl[0];
				if (dc < 0.0) {
					n = (Sint16)(dc - 0.5f);
				} else {
					n = (Sint16)(0.5f + dc);
				}
				n = (n << 16) | (Uint16)n;
				out += 32;
				for (k = 0; k < 32; k++) {
					*--out = n;
				}
			} else {
				o = tbl[0];
				
			}
		}
		cbp <<= 1;
		blk += 64;
		tbl++;
		flg++;
	}
}

/* interleaved position of coefficient i: two 8-entry rows become one 16-entry row */
static inline int dctfsri_Idx(int i)
{
	int q = i / 8;
	int r = i % 8;
	int n;

	if (q % 2 == 0) {
		r *= 2;
	} else {
		q--;
		r = r * 2 + 1;
	}
	n = r + q * 8;
	if (n < 0 || n >= 256) {
		for (;;) {
		}
	}
	return n;
}

// Stores one entry of the PreIDCT table at the paired-single interleaved row index.
static inline void dctfsri_SetPreIdct(int n, int k, const Float64 *v)
{
	PreIDCT[dctfsri_Idx(n)][k] = (Float32)*v;
}

// Converts a zigzag scan sequence into the interleaved table index order.
void DCT_FsriInitScanTbl(const Sint8 *seq, Sint8 *scan)
{
	int i;

	for (i = 0; i < 64; i++) {
		scan[i] = (Sint8)dctfsri_Idx(seq[i]);
	}
}

// IDCT of the blocks flagged in the coded block pattern (non-intra macroblocks).
void DCT_FsriTransCbp(DCT_PA *pa)
{
	DCT_FsriTransCore(pa, pa->cbp_msk);
}

// IDCT of all six blocks (intra macroblocks).
void DCT_FsriTrans6Blk(DCT_PA *pa)
{
	DCT_FsriTransCore(pa, -1);
}

// Programs GQR7 for the 16-bit pixel stores of the column pass (before each frame decode).
void DCT_FsriSetGqr(void)
{
	
}

/* the scan row is recomputed for every coefficient store */
#pragma opt_loop_invariants off
// Builds PreIDCT: the inverse DCT response of each single scaled coefficient (through the
// double-precision reference IDCT), so the row pass is a table lookup per coefficient.
void initSparseTbl(void)
{
	Float64 in[64];
	Float64 out[64];
	int n;

	memset(PreIDCT, 0, sizeof(PreIDCT));
	DCT_AcInit();
	for (n = 0; n < 64; n++) {
		int k;
		for (k = 0; k < 64; k++) {
			if (k == n) {
				in[k] = 1.0 / sfsd_scale_tbl[k];
			} else {
				in[k] = 0.0;
			}
		}
		DCT_AcIdctDouble(in, out);
		for (k = 0; k < 64; k++) {
			dctfsri_SetPreIdct(n, k, &out[k]);
		}
	}
}
#pragma opt_loop_invariants on

// Clears a DCT parameter block.
void DCT_FsriInitPa(DCT_PA *pa)
{
	memset(pa, 0, sizeof(DCT_PA));
}

// The per-coefficient dequantisation scale table in interleaved order.
void DCT_FsriInitScaleTbl(Float32 *tbl)
{
	int i;

	for (i = 0; i < 64; i++) {
		tbl[dctfsri_Idx(i)] = (Float32)sfsd_scale_tbl[i];
	}
}

// Library init: the 8x8 separable scale table (scale8 outer product) and the PreIDCT tables.
void DCT_FsriInit(void)
{
	Sint32 i;
	Sint32 j;

	dctfsri_version_dummy = DCT_GetVerStr();
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			sfsd_scale_tbl[i * 8 + j] = scale8[i] * scale8[j];
		}
	}
	initSparseTbl();
}
