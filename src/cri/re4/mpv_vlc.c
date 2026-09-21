/* CRI Sofdec MPEG video decoder: VLC lookup tables (mpv_vlc.c). The tables are generated at
 * MPVVLC_Init time into static .bss arrays; the run/level tables are then copied into the shared
 * table area (MPV_IXA vlc block) when one is given. Compiled with `-inline auto,deferred`: the
 * functions are emitted in reverse source order and the .bss order follows the reversed
 * code-generation order (see configure.py CRI_CFLAG_OVERRIDES).
 *
 * Entry formats (all Sint16 unless noted):
 *   run/level (Uint32):        (len << 16) | (run << 8) | level
 *   DC size (Sint8):           (size << 4) | len
 *   coded block pattern:       (cbp << 8) | len, bits 15/14 repeat the two chrominance bits
 *   motion code:               (len << 8) | (Uint8)code, 0x7F = invalid
 *   macroblock_type:           (type << 8) | len
 *   macroblock_address_inc:    (type << 10) | (inc << 4) | len (inc 34 stuffing, 35 escape, 36 error) */
#include "cri_xpt.h"

#define MPVVLC_VLC_AREA_SIZE 0x5B0

#define MBT_INTRA 0x01
#define MBT_PATTERN 0x02
#define MBT_BACKWARD 0x04
#define MBT_FORWARD 0x08
#define MBT_QUANT 0x10
#define MBT_FIXED 0x20

#define MBAI_STUFFING 34
#define MBAI_ESCAPE 35
#define MBAI_ERROR 36

#define RL(len, run, level) (((len) << 16) | ((run) << 8) | (level))
#define DCSIZ(size, len) (((size) << 4) | (len))
#define CBP(cbp, len) ((((cbp) & 3) << 14) | ((cbp) << 8) | (len))
#define MV(len, code) (((len) << 8) | (Uint8)(code))
#define MBTYPE(type, len) (((type) << 8) | (len))
#define MBAI(type, inc, len) (((type) << 10) | ((inc) << 4) | (len))

extern void UTY_MemcpyDword(void *dst, const void *src, Sint32 ndword);

/* run/level tables of the fixed-length code groups (rodata, copied into the VLC area) */
const Uint32 mpvvlt_run_level_0c[8] = {
	0x12011101, 0x10010F01, 0x03060210, 0x020F020E, 0x020D020C, 0x020B011F, 0x011E011D, 0x011C011B,
};
const Uint32 mpvvlt_run_level_0b[8] = {
	0x28002700, 0x26002500, 0x24002300, 0x22002100, 0x20000E01, 0x0D010C01, 0x0B010A01, 0x09010801,
};
const Uint32 mpvvlt_run_level_0a[8] = {
	0x1F001E00, 0x1D001C00, 0x1B001A00, 0x19001800, 0x17001600, 0x15001400, 0x13001200, 0x11001000,
};
const Uint32 mpvvlt_run_level_1[8] = {
	0x020A0209, 0x03050403, 0x05020701, 0x06010F00, 0x0E000D00, 0x0C00011A, 0x01190118, 0x01170116,
};
const Uint32 mpvvlt_run_level_2[8] = {
	0x0B000208, 0x03040A00, 0x04020207, 0x01150114, 0x09000113, 0x01120501, 0x03030800, 0x02060111,
};
const Uint32 mpvvlt_run_level_4[4] = {
	0x01100205, 0x07000302, 0x0401010F, 0x010E0204,
};

/* table pointers used by the decoders (point into the VLC area once MPVVLC_Init got one); under
 * `deferred` the .bss is laid out in reverse declaration order */
Sint16 *mpvvlc_mbai_i_0;
Sint16 *mpvvlc_mbai_i_1;
Sint16 *mpvvlc_mbai_p_0;
Sint16 *mpvvlc_mbai_p_1;
Sint16 *mpvvlc_mbai_b_0;
Sint16 *mpvvlc_mbai_b_1;
Sint16 *mpvvlc_p_mbtype;
Sint16 *mpvvlc_b_mbtype;
Sint16 *mpvvlc_motion_0;
Sint16 *mpvvlc_motion_1;
Sint16 *mpvvlc_cbp;
Sint8 *mpvvlc_y_dcsiz;
Sint8 *mpvvlc_c_dcsiz;
Sint8 *mpvvlc2_y_dcsiz;
Sint8 *mpvvlc2_c_dcsiz;
Uint32 *mpvvlc_run_level_0c;
Uint32 *mpvvlc_run_level_0b;
Uint32 *mpvvlc_run_level_0a;
Uint32 *mpvvlc_run_level_1;
Uint32 *mpvvlc_run_level_2;
Uint32 *mpvvlc_run_level_4;
Uint32 *mpvvlc_run_level_8;

static Sint16 mpvvlt_mbai_i_0[0x100];
Sint16 mpvvlt_mbai_i_1[0x40];
static Sint16 mpvvlt_mbai_p_0[0x80];
static Sint16 mpvvlt_mbai_p_1[0x20];
static Sint16 mpvvlt_mbai_b_0[0x80];
Sint16 mpvvlt_mbai_b_1[0x20];
static Sint16 mpvvlt_p_mbtype[0x20];
static Sint16 mpvvlt_b_mbtype[0x40];
Sint16 mpvvlt_motion_0[0x80];
Sint16 mpvvlt_motion_1[0x20];
Sint16 mpvvlt_cbp[0x200];
static Sint8 mpvvlt_y_dcsiz[0x80];
static Sint8 mpvvlt_c_dcsiz[0x80];
static Sint8 mpvvlt2_y_dcsiz[0x400];
Sint8 mpvvlt2_c_dcsiz[0x400];
Uint32 mpvvlt_run_level_8[0x80];

static void mpvvlc_InitMbaiIpic(void);
void mpvvlc_InitMbaiPpic(void);
static void mpvvlc_InitMbaiBpic(void);
void mpvvlc_InitMbTypePpic(void);
void mpvvlc_InitMbTypeBpic(void);
static void mpvvlc_InitMotion(void);
Sint16 *mpvvlc_InitCbpSub1(Sint16 *p);
static Sint16 *mpvvlc_InitCbpSub2(Sint16 *p);
static void mpvvlc_InitCbp(void);
void mpvvlc_InitDcSizY(void);
static void mpvvlc_InitDcSizC(void);
void mpvvlc2_InitDcSizY(void);
void mpvvlc2_InitDcSizC(void);
void mpvvlc_InitIntRunLevel(void);

// Compile-time check that the run/level, DC size, motion and macroblock type tables fit the 0x5B0
// byte VLC area of the shared table block.
Sint32 MPVVLC_IsVlcSizErr(void)
{
	Sint32 siz;
	Sint32 sz = sizeof(Sint16);

	if (sz != 2) {
		return TRUE;
	}
	siz = MPVVLC_VLC_AREA_SIZE - (sizeof(mpvvlt_run_level_8) + sizeof(mpvvlt_run_level_4) +
				      sizeof(mpvvlt_run_level_2) + sizeof(mpvvlt_run_level_1) +
				      sizeof(mpvvlt_run_level_0a) + sizeof(mpvvlt_run_level_0b) +
				      sizeof(mpvvlt_run_level_0c) + sizeof(mpvvlt_y_dcsiz) +
				      sizeof(mpvvlt_c_dcsiz) + sizeof(mpvvlt_motion_0) + sizeof(mpvvlt_motion_1) +
				      sizeof(mpvvlt_p_mbtype) + sizeof(mpvvlt_b_mbtype));
	return siz < 0;
}

// Generates every VLC lookup table (macroblock address increment per picture type, macroblock type,
// motion codes, coded block pattern, DC sizes, run/level) and copies the run/level tables into the
// shared area `vlc` when one is given.
void MPVVLC_Init(Uint8 *vlc, void *ixa)
{
	mpvvlc_InitMbaiIpic();
	mpvvlc_InitMbaiPpic();
	mpvvlc_InitMbaiBpic();
	mpvvlc_InitMbTypePpic();
	mpvvlc_InitMbTypeBpic();
	mpvvlc_InitMotion();
	mpvvlc_InitCbp();
	mpvvlc_InitDcSizY();
	mpvvlc_InitDcSizC();
	mpvvlc2_InitDcSizY();
	mpvvlc2_InitDcSizC();
	mpvvlc_InitIntRunLevel();

	mpvvlc_mbai_i_0 = mpvvlt_mbai_i_0;
	mpvvlc_mbai_i_1 = mpvvlt_mbai_i_1;
	mpvvlc_mbai_p_0 = mpvvlt_mbai_p_0;
	mpvvlc_mbai_p_1 = mpvvlt_mbai_p_1;
	mpvvlc_mbai_b_0 = mpvvlt_mbai_b_0;
	mpvvlc_mbai_b_1 = mpvvlt_mbai_b_1;
	mpvvlc_p_mbtype = mpvvlt_p_mbtype;
	mpvvlc_b_mbtype = mpvvlt_b_mbtype;
	mpvvlc_motion_0 = mpvvlt_motion_0;
	mpvvlc_motion_1 = mpvvlt_motion_1;
	mpvvlc_cbp = mpvvlt_cbp;
	mpvvlc_y_dcsiz = mpvvlt_y_dcsiz;
	mpvvlc_c_dcsiz = mpvvlt_c_dcsiz;
	mpvvlc2_y_dcsiz = mpvvlt2_y_dcsiz;
	mpvvlc2_c_dcsiz = mpvvlt2_c_dcsiz;
	mpvvlc_run_level_0c = (Uint32 *)mpvvlt_run_level_0c;
	mpvvlc_run_level_0b = (Uint32 *)mpvvlt_run_level_0b;
	mpvvlc_run_level_0a = (Uint32 *)mpvvlt_run_level_0a;
	mpvvlc_run_level_1 = (Uint32 *)mpvvlt_run_level_1;
	mpvvlc_run_level_2 = (Uint32 *)mpvvlt_run_level_2;
	mpvvlc_run_level_4 = (Uint32 *)mpvvlt_run_level_4;
	mpvvlc_run_level_8 = mpvvlt_run_level_8;

	if (vlc != NULL) {
		Uint8 *p;
		Uint8 *rl;

		/* the run/level tables from the end of the area downwards */
		p = vlc + MPVVLC_VLC_AREA_SIZE;
		p -= sizeof(mpvvlt_run_level_8);
		mpvvlc_run_level_8 = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_8, sizeof(mpvvlt_run_level_8) / 4);
		p -= sizeof(mpvvlt_run_level_4);
		mpvvlc_run_level_4 = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_4, sizeof(mpvvlt_run_level_4) / 4);
		p -= sizeof(mpvvlt_run_level_2);
		mpvvlc_run_level_2 = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_2, sizeof(mpvvlt_run_level_2) / 4);
		p -= sizeof(mpvvlt_run_level_1);
		mpvvlc_run_level_1 = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_1, sizeof(mpvvlt_run_level_1) / 4);
		p -= sizeof(mpvvlt_run_level_0a);
		mpvvlc_run_level_0a = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_0a, sizeof(mpvvlt_run_level_0a) / 4);
		p -= sizeof(mpvvlt_run_level_0b);
		mpvvlc_run_level_0b = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_0b, sizeof(mpvvlt_run_level_0b) / 4);
		p -= sizeof(mpvvlt_run_level_0c);
		mpvvlc_run_level_0c = (Uint32 *)p;
		UTY_MemcpyDword(p, mpvvlt_run_level_0c, sizeof(mpvvlt_run_level_0c) / 4);
		/* the VLC tables below them (offsets from the run/level area) */
		rl = p;
		p -= sizeof(mpvvlt_y_dcsiz);
		mpvvlc_y_dcsiz = (Sint8 *)p;
		UTY_MemcpyDword(p, mpvvlt_y_dcsiz, sizeof(mpvvlt_y_dcsiz) / 4);
		p = rl - (sizeof(mpvvlt_y_dcsiz) + sizeof(mpvvlt_c_dcsiz));
		mpvvlc_c_dcsiz = (Sint8 *)p;
		UTY_MemcpyDword(p, mpvvlt_c_dcsiz, sizeof(mpvvlt_c_dcsiz) / 4);
		p = rl - (sizeof(mpvvlt_y_dcsiz) + sizeof(mpvvlt_c_dcsiz) + sizeof(mpvvlt_motion_0));
		mpvvlc_motion_0 = (Sint16 *)p;
		UTY_MemcpyDword(p, mpvvlt_motion_0, sizeof(mpvvlt_motion_0) / 4);
		p = rl - (sizeof(mpvvlt_y_dcsiz) + sizeof(mpvvlt_c_dcsiz) + sizeof(mpvvlt_motion_0) +
			  sizeof(mpvvlt_motion_1));
		mpvvlc_motion_1 = (Sint16 *)p;
		UTY_MemcpyDword(p, mpvvlt_motion_1, sizeof(mpvvlt_motion_1) / 4);
		p = rl - (sizeof(mpvvlt_y_dcsiz) + sizeof(mpvvlt_c_dcsiz) + sizeof(mpvvlt_motion_0) +
			  sizeof(mpvvlt_motion_1) + sizeof(mpvvlt_p_mbtype));
		mpvvlc_p_mbtype = (Sint16 *)p;
		UTY_MemcpyDword(p, mpvvlt_p_mbtype, sizeof(mpvvlt_p_mbtype) / 4);
		p = rl - (sizeof(mpvvlt_y_dcsiz) + sizeof(mpvvlt_c_dcsiz) + sizeof(mpvvlt_motion_0) +
			  sizeof(mpvvlt_motion_1) + sizeof(mpvvlt_p_mbtype) + sizeof(mpvvlt_b_mbtype));
		mpvvlc_b_mbtype = (Sint16 *)p;
		UTY_MemcpyDword(p, mpvvlt_b_mbtype, sizeof(mpvvlt_b_mbtype) / 4);
	}
}

/* I picture: the increments of one code length `len`; `n` entries per macroblock_type ('1' intra,
 * '01' intra+quant) */
#define MPVVLC_SET_MBAI_I(kmax, kmin, len, n)                                                  \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		Sint16 v;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			v = MBAI(MBT_INTRA | MBT_QUANT, k, (len) + 2);                         \
			for (i = 0; i < (n); i++) *p++ = v;                                    \
			v = MBAI(MBT_INTRA, k, (len) + 1);                                     \
			for (i = 0; i < (n); i++) *p++ = v;                                    \
		}                                                                              \
	}

// macroblock_address_increment table for I pictures (type fixed to intra): 12-bit and 8-bit halves.
static void mpvvlc_InitMbaiIpic(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_mbai_i_0;
	for (i = 0; i < 16; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	for (i = 0; i < 2; i++) *p++ = MBAI(0, MBAI_ESCAPE, 11);
	for (i = 0; i < 12; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	for (i = 0; i < 2; i++) *p++ = MBAI(0, MBAI_STUFFING, 11);
	for (i = 0; i < 16; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_I(33, 22, 11, 1);
	MPVVLC_SET_MBAI_I(21, 16, 10, 2);
	MPVVLC_SET_MBAI_I(15, 10, 8, 8);
	MPVVLC_SET_MBAI_I(9, 8, 7, 16);

	p = mpvvlt_mbai_i_1;
	for (i = 0; i < 4; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_I(7, 6, 5, 1);
	MPVVLC_SET_MBAI_I(5, 4, 4, 2);
	MPVVLC_SET_MBAI_I(3, 2, 3, 4);
	MPVVLC_SET_MBAI_I(1, 1, 1, 16);
}

#define MBT_P_MC (MBT_FIXED | MBT_FORWARD)
#define MBT_P_PAT (MBT_FIXED | MBT_PATTERN)
#define MBT_P_MCPAT (MBT_FIXED | MBT_FORWARD | MBT_PATTERN)

/* P picture: the increments of one code length `len` with 0..4 bits of the macroblock_type
 * ('1' mc+pattern, '01' pattern, '001' mc) in the look-ahead */
#define MPVVLC_SET_MBAI_P0(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			*p++ = MBAI(0, k, (len));                                              \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_P1(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			*p++ = MBAI(0, k, (len));                                              \
			*p++ = MBAI(MBT_P_MCPAT, k, (len) + 1);                                \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_P2(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			*p++ = MBAI(0, k, (len));                                              \
			*p++ = MBAI(MBT_P_PAT, k, (len) + 2);                                  \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_P_MCPAT, k, (len) + 1);        \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_P3(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			*p++ = MBAI(0, k, (len));                                              \
			*p++ = MBAI(MBT_P_MC, k, (len) + 3);                                   \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_P_PAT, k, (len) + 2);          \
			for (i = 0; i < 4; i++) *p++ = MBAI(MBT_P_MCPAT, k, (len) + 1);        \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_P4(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			for (i = 0; i < 2; i++) *p++ = MBAI(0, k, (len));                      \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_P_MC, k, (len) + 3);           \
			for (i = 0; i < 4; i++) *p++ = MBAI(MBT_P_PAT, k, (len) + 2);          \
			for (i = 0; i < 8; i++) *p++ = MBAI(MBT_P_MCPAT, k, (len) + 1);        \
		}                                                                              \
	}

// macroblock_address_increment table for P pictures.
void mpvvlc_InitMbaiPpic(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_mbai_p_0;
	for (i = 0; i < 8; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	*p++ = MBAI(0, MBAI_ESCAPE, 11);
	for (i = 0; i < 6; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	*p++ = MBAI(0, MBAI_STUFFING, 11);
	for (i = 0; i < 8; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_P0(33, 22, 11);
	MPVVLC_SET_MBAI_P1(21, 16, 10);
	MPVVLC_SET_MBAI_P3(15, 10, 8);
	MPVVLC_SET_MBAI_P4(9, 8, 7);

	p = mpvvlt_mbai_p_1;
	for (i = 0; i < 2; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_P0(7, 6, 5);
	MPVVLC_SET_MBAI_P1(5, 4, 4);
	MPVVLC_SET_MBAI_P2(3, 2, 3);
	MPVVLC_SET_MBAI_P4(1, 1, 1);
}

#define MBT_B_FWD (MBT_FIXED | MBT_FORWARD)
#define MBT_B_FWDPAT (MBT_FIXED | MBT_FORWARD | MBT_PATTERN)
#define MBT_B_BWD (MBT_FIXED | MBT_BACKWARD)
#define MBT_B_BWDPAT (MBT_FIXED | MBT_BACKWARD | MBT_PATTERN)
#define MBT_B_BI (MBT_FIXED | MBT_FORWARD | MBT_BACKWARD)
#define MBT_B_BIPAT (MBT_FIXED | MBT_FORWARD | MBT_BACKWARD | MBT_PATTERN)

/* B picture: the increments of one code length `len` with 0..4 bits of the macroblock_type
 * ('10' fwd+bwd, '11' fwd+bwd+pattern, '010' bwd, '011' bwd+pattern, '0010' fwd, '0011'
 * fwd+pattern) in the look-ahead */
#define MPVVLC_SET_MBAI_B0(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			*p++ = MBAI(0, k, (len));                                              \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_B1(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			for (i = 0; i < 2; i++) *p++ = MBAI(0, k, (len));                      \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_B2(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			for (i = 0; i < 2; i++) *p++ = MBAI(0, k, (len));                      \
			*p++ = MBAI(MBT_B_BI, k, (len) + 2);                                   \
			*p++ = MBAI(MBT_B_BIPAT, k, (len) + 2);                                \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_B3(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			for (i = 0; i < 2; i++) *p++ = MBAI(0, k, (len));                      \
			*p++ = MBAI(MBT_B_BWD, k, (len) + 3);                                  \
			*p++ = MBAI(MBT_B_BWDPAT, k, (len) + 3);                               \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_B_BI, k, (len) + 2);           \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_B_BIPAT, k, (len) + 2);        \
		}                                                                              \
	}
#define MPVVLC_SET_MBAI_B4(kmax, kmin, len)                                                    \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			for (i = 0; i < 2; i++) *p++ = MBAI(0, k, (len));                      \
			*p++ = MBAI(MBT_B_FWD, k, (len) + 4);                                  \
			*p++ = MBAI(MBT_B_FWDPAT, k, (len) + 4);                               \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_B_BWD, k, (len) + 3);          \
			for (i = 0; i < 2; i++) *p++ = MBAI(MBT_B_BWDPAT, k, (len) + 3);       \
			for (i = 0; i < 4; i++) *p++ = MBAI(MBT_B_BI, k, (len) + 2);           \
			for (i = 0; i < 4; i++) *p++ = MBAI(MBT_B_BIPAT, k, (len) + 2);        \
		}                                                                              \
	}

// macroblock_address_increment table for B pictures.
static void mpvvlc_InitMbaiBpic(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_mbai_b_0;
	for (i = 0; i < 8; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	*p++ = MBAI(0, MBAI_ESCAPE, 11);
	for (i = 0; i < 6; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	*p++ = MBAI(0, MBAI_STUFFING, 11);
	for (i = 0; i < 8; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_B0(33, 22, 11);
	MPVVLC_SET_MBAI_B1(21, 16, 10);
	MPVVLC_SET_MBAI_B3(15, 10, 8);
	MPVVLC_SET_MBAI_B4(9, 8, 7);

	p = mpvvlt_mbai_b_1;
	for (i = 0; i < 2; i++) *p++ = MBAI(0, MBAI_ERROR, 0);
	MPVVLC_SET_MBAI_B0(7, 6, 5);
	MPVVLC_SET_MBAI_B1(5, 4, 4);
	MPVVLC_SET_MBAI_B2(3, 2, 3);
	MPVVLC_SET_MBAI_B4(1, 1, 1);
}

/* P picture macroblock_type, 5-bit look-ahead (small enough for the auto-inliner, called) */
// macroblock_type table for P pictures (B.2b).
void mpvvlc_InitMbTypePpic(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_p_mbtype;
	*p++ = MBTYPE(MBT_INTRA | MBT_QUANT, 6);
	*p++ = MBTYPE(MBT_PATTERN | MBT_QUANT, 5);
	*p++ = MBTYPE(MBT_FORWARD | MBT_PATTERN | MBT_QUANT, 5);
	*p++ = MBTYPE(MBT_INTRA, 5);
	for (i = 0; i < 4; i++) *p++ = MBTYPE(MBT_FORWARD, 3);
	for (i = 0; i < 8; i++) *p++ = MBTYPE(MBT_PATTERN, 2);
	for (i = 0; i < 16; i++) *p++ = MBTYPE(MBT_FORWARD | MBT_PATTERN, 1);
}

/* B picture macroblock_type, 6-bit look-ahead */
void mpvvlc_InitMbTypeBpic(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_b_mbtype;
	*p++ = MBTYPE(0x1F, 0);
	*p++ = MBTYPE(MBT_INTRA | MBT_QUANT, 6);
	*p++ = MBTYPE(MBT_BACKWARD | MBT_PATTERN | MBT_QUANT, 6);
	*p++ = MBTYPE(MBT_FORWARD | MBT_PATTERN | MBT_QUANT, 6);
	for (i = 0; i < 2; i++) *p++ = MBTYPE(MBT_FORWARD | MBT_BACKWARD | MBT_PATTERN | MBT_QUANT, 5);
	for (i = 0; i < 2; i++) *p++ = MBTYPE(MBT_INTRA, 5);
	for (i = 0; i < 4; i++) *p++ = MBTYPE(MBT_FORWARD, 4);
	for (i = 0; i < 4; i++) *p++ = MBTYPE(MBT_FORWARD | MBT_PATTERN, 4);
	for (i = 0; i < 8; i++) *p++ = MBTYPE(MBT_BACKWARD, 3);
	for (i = 0; i < 8; i++) *p++ = MBTYPE(MBT_BACKWARD | MBT_PATTERN, 3);
	for (i = 0; i < 16; i++) *p++ = MBTYPE(MBT_FORWARD | MBT_BACKWARD, 2);
	for (i = 0; i < 16; i++) *p++ = MBTYPE(MBT_FORWARD | MBT_BACKWARD | MBT_PATTERN, 2);
}

/* the +-code pairs of one motion_code length: n entries each */
#define MPVVLC_SET_MOTION(len, kmax, kmin, n)                                                  \
	{                                                                                      \
		Sint32 k;                                                                      \
		Sint32 i;                                                                      \
		Sint16 v;                                                                      \
		for (k = (kmax); k >= (kmin); k--) {                                           \
			v = MV(len, k);                                                        \
			for (i = 0; i < (n); i++) *p++ = v;                                    \
			v = MV(len, -k);                                                       \
			for (i = 0; i < (n); i++) *p++ = v;                                    \
		}                                                                              \
	}

/* motion_code: 11-bit look-ahead, table 0 for codes with four leading zeros */
static void mpvvlc_InitMotion(void)
{
	Sint16 *p;
	Sint32 i;

	p = mpvvlt_motion_0;
	for (i = 0; i < 24; i++) *p++ = 0x7F;
	MPVVLC_SET_MOTION(11, 16, 11, 1);
	MPVVLC_SET_MOTION(10, 10, 8, 2);
	MPVVLC_SET_MOTION(8, 7, 5, 8);
	MPVVLC_SET_MOTION(7, 4, 4, 16);

	p = mpvvlt_motion_1;
	for (i = 0; i < 2; i++) *p++ = 0x7F;
	MPVVLC_SET_MOTION(5, 3, 3, 1);
	MPVVLC_SET_MOTION(4, 2, 2, 2);
	MPVVLC_SET_MOTION(3, 1, 1, 4);
	{
		Sint32 k;
		Sint32 i;
		Sint16 v;
		for (k = 0; k >= 0; k--) {
			v = MV(1, k);
			for (i = 0; i < 16; i++) *p++ = v;
		}
	}
}

/* coded_block_pattern, 9-bit look-ahead: the 64 entries of the codes with three leading zeros */
Sint16 *mpvvlc_InitCbpSub1(Sint16 *p)
{
	Sint32 i;

	for (i = 0; i < 2; i++) *p++ = CBP(0, 0);
	*p++ = CBP(39, 9);
	*p++ = CBP(27, 9);
	*p++ = CBP(59, 9);
	*p++ = CBP(55, 9);
	*p++ = CBP(47, 9);
	*p++ = CBP(31, 9);
	for (i = 0; i < 2; i++) *p++ = CBP(58, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(54, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(46, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(30, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(57, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(53, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(45, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(29, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(38, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(26, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(37, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(25, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(43, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(23, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(51, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(15, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(42, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(22, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(50, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(14, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(41, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(21, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(49, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(13, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(35, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(19, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(11, 8);
	for (i = 0; i < 2; i++) *p++ = CBP(7, 8);
	return p;
}

/* the remaining 448 entries (codes 001... to 111...) */
static Sint16 *mpvvlc_InitCbpSub2(Sint16 *p)
{
	Sint32 i;

	for (i = 0; i < 4; i++) *p++ = CBP(34, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(18, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(10, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(6, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(33, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(17, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(9, 7);
	for (i = 0; i < 4; i++) *p++ = CBP(5, 7);
	for (i = 0; i < 8; i++) *p++ = CBP(63, 6);
	for (i = 0; i < 8; i++) *p++ = CBP(3, 6);
	for (i = 0; i < 8; i++) *p++ = CBP(36, 6);
	for (i = 0; i < 8; i++) *p++ = CBP(24, 6);
	for (i = 0; i < 16; i++) *p++ = CBP(62, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(2, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(61, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(1, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(56, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(52, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(44, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(28, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(40, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(20, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(48, 5);
	for (i = 0; i < 16; i++) *p++ = CBP(12, 5);
	for (i = 0; i < 32; i++) *p++ = CBP(32, 4);
	for (i = 0; i < 32; i++) *p++ = CBP(16, 4);
	for (i = 0; i < 32; i++) *p++ = CBP(8, 4);
	for (i = 0; i < 32; i++) *p++ = CBP(4, 4);
	for (i = 0; i < 64; i++) *p++ = CBP(60, 3);
	return p;
}

// coded_block_pattern table (B.3) with the two chrominance bits repeated in bits 15/14.
static void mpvvlc_InitCbp(void)
{
	Sint16 *p;

	p = mpvvlc_InitCbpSub1(mpvvlt_cbp);
	mpvvlc_InitCbpSub2(p);
}

/* dct_dc_size_luminance, 7-bit look-ahead */
void mpvvlc_InitDcSizY(void)
{
	Sint8 *p;
	Sint32 i;

	p = mpvvlt_y_dcsiz;
	for (i = 0; i < 32; i++) *p++ = DCSIZ(1, 2);
	for (i = 0; i < 32; i++) *p++ = DCSIZ(2, 2);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(0, 3);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(3, 3);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(4, 3);
	for (i = 0; i < 8; i++) *p++ = DCSIZ(5, 4);
	for (i = 0; i < 4; i++) *p++ = DCSIZ(6, 5);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(7, 6);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(8, 7);
}

/* dct_dc_size_chrominance, 7-bit look-ahead */
static void mpvvlc_InitDcSizC(void)
{
	Sint8 *p;
	Sint32 i;

	p = mpvvlt_c_dcsiz;
	for (i = 0; i < 32; i++) *p++ = DCSIZ(0, 2);
	for (i = 0; i < 32; i++) *p++ = DCSIZ(1, 2);
	for (i = 0; i < 32; i++) *p++ = DCSIZ(2, 2);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(3, 3);
	for (i = 0; i < 8; i++) *p++ = DCSIZ(4, 4);
	for (i = 0; i < 4; i++) *p++ = DCSIZ(5, 5);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(6, 6);
	*p++ = DCSIZ(7, 7);
	*p++ = DCSIZ(8, 8);
}

/* MPEG-2 dct_dc_size_luminance, 10-bit look-ahead (sizes up to 11) */
void mpvvlc2_InitDcSizY(void)
{
	Sint8 *p;
	Sint32 i;

	p = mpvvlt2_y_dcsiz;
	for (i = 0; i < 256; i++) *p++ = DCSIZ(1, 2);
	for (i = 0; i < 256; i++) *p++ = DCSIZ(2, 2);
	for (i = 0; i < 128; i++) *p++ = DCSIZ(0, 3);
	for (i = 0; i < 128; i++) *p++ = DCSIZ(3, 3);
	for (i = 0; i < 128; i++) *p++ = DCSIZ(4, 3);
	for (i = 0; i < 64; i++) *p++ = DCSIZ(5, 4);
	for (i = 0; i < 32; i++) *p++ = DCSIZ(6, 5);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(7, 6);
	for (i = 0; i < 8; i++) *p++ = DCSIZ(8, 7);
	for (i = 0; i < 4; i++) *p++ = DCSIZ(9, 8);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(10, 9);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(11, 9);
}

/* MPEG-2 dct_dc_size_chrominance, 10-bit look-ahead */
void mpvvlc2_InitDcSizC(void)
{
	Sint8 *p;
	Sint32 i;

	p = mpvvlt2_c_dcsiz;
	for (i = 0; i < 256; i++) *p++ = DCSIZ(0, 2);
	for (i = 0; i < 256; i++) *p++ = DCSIZ(1, 2);
	for (i = 0; i < 256; i++) *p++ = DCSIZ(2, 2);
	for (i = 0; i < 128; i++) *p++ = DCSIZ(3, 3);
	for (i = 0; i < 64; i++) *p++ = DCSIZ(4, 4);
	for (i = 0; i < 32; i++) *p++ = DCSIZ(5, 5);
	for (i = 0; i < 16; i++) *p++ = DCSIZ(6, 6);
	for (i = 0; i < 8; i++) *p++ = DCSIZ(7, 7);
	for (i = 0; i < 4; i++) *p++ = DCSIZ(8, 8);
	for (i = 0; i < 2; i++) *p++ = DCSIZ(9, 9);
	*p++ = DCSIZ(10, 10);
	*p++ = DCSIZ(11, 10);
}

/* dct_coefficient run/level codes up to 8 bits (8-bit look-ahead; 0x4040 = escape) */
void mpvvlc_InitIntRunLevel(void)
{
	Uint32 *p;
	Sint32 i;

	p = mpvvlt_run_level_8;
	for (i = 0; i < 4; i++) *p++ = RL(0, 0, 0);
	for (i = 0; i < 4; i++) *p++ = RL(6, 0x40, 0x40);
	for (i = 0; i < 2; i++) *p++ = RL(8, 2, 2);
	for (i = 0; i < 2; i++) *p++ = RL(8, 1, 9);
	for (i = 0; i < 2; i++) *p++ = RL(8, 4, 0);
	for (i = 0; i < 2; i++) *p++ = RL(8, 1, 8);
	for (i = 0; i < 4; i++) *p++ = RL(7, 1, 7);
	for (i = 0; i < 4; i++) *p++ = RL(7, 1, 6);
	for (i = 0; i < 4; i++) *p++ = RL(7, 2, 1);
	for (i = 0; i < 4; i++) *p++ = RL(7, 1, 5);
	*p++ = RL(9, 1, 13);
	*p++ = RL(9, 6, 0);
	*p++ = RL(9, 1, 12);
	*p++ = RL(9, 1, 11);
	*p++ = RL(9, 2, 3);
	*p++ = RL(9, 3, 1);
	*p++ = RL(9, 5, 0);
	*p++ = RL(9, 1, 10);
	for (i = 0; i < 8; i++) *p++ = RL(6, 3, 0);
	for (i = 0; i < 8; i++) *p++ = RL(6, 1, 4);
	for (i = 0; i < 8; i++) *p++ = RL(6, 1, 3);
	for (i = 0; i < 16; i++) *p++ = RL(5, 2, 0);
	for (i = 0; i < 16; i++) *p++ = RL(5, 1, 2);
	for (i = 0; i < 32; i++) *p++ = RL(4, 1, 1);
}
