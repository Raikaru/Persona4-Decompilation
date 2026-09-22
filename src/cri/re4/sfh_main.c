/* CRI Sofdec file header analyser (sfh_main.c): validates the 0x800-byte SofdecStream header and
 * reads the pack/element/feature fields out of it.
 *
 * 36/36 functions identical. The seven big-endian 32-bit readers (SFH_AnlyElemSmpHz, MaxFrmNum,
 * MaxPlyLenVid/Aud, ByteRate, PackSiz, HdrSiz) keep the original's `rlwinm 8,8,15 / rlwimi 24,0,7 /
 * rlwimi 24,16,23 / rlwimi 8,24,31 / stw` only because their store sits in another basic block than
 * the swap chain (a dead conditional between them, COMPILER-DIFF M4, see SFH_AnlyElemSmpHz): our 2.4.7's
 * post-RA peephole folds a same-block byte-swap store into `stwbrx`. */
#include "cri_xpt.h"
#include "sfh.h"

extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern int memcmp(const void *, const void *, unsigned long);
extern char *strstr(const char *, const char *);

#define SFH_VER_STR "1.19"
#define SFH_VER_DATE "SFH_VER_DATE"

const Char8 ver_str[] = " SFH Version " SFH_VER_STR SFH_VER_DATE;
const Char8 cpy_str[] = "Copyright (c) 1999-2004 CRI-MW";
const Char8 SFH_sbver_str[] = "\nCRI SFH/GC Ver.1.19 Build:Sep 22 2004 10:35:19\n";

/* handle states */
#define SFH_STAT_INVALID (-1)
#define SFH_STAT_FREE 0
#define SFH_STAT_CREATED 1
#define SFH_STAT_VALID 2

#define SFH_HDR_MIN_SIZE 0x800
#define SFH_HDR_ID_OFS 0x20
#define SFH_HDR_ID_LEN 0x18
#define SFH_HDR_VER_MAJOR_OFS 0x38
#define SFH_HDR_VER_MINOR_OFS 0x39
#define SFH_HDR_TOOLSTR_OFS 0x60
#define SFH_HDR_TOOLSTR_LEN 0x20

#define SFH_HDR_SIZ_OFS 0x80
#define SFH_HDR_PACKTYPE_OFS 0x84
#define SFH_HDR_PKETSIZLEN_OFS 0x88
#define SFH_HDR_PACKSIZ_OFS 0x8C
#define SFH_HDR_NUMELEM_TOT_OFS 0xB0
#define SFH_HDR_NUMELEM_AUD_OFS 0xB1
#define SFH_HDR_NUMELEM_VID_OFS 0xB2
#define SFH_HDR_NUMELEM_PRV_OFS 0xB3
#define SFH_HDR_BYTERATE_OFS 0xB4
#define SFH_HDR_MAXPLYLEN_AUD_OFS 0xB8
#define SFH_HDR_MAXPLYLEN_VID_OFS 0xBC
#define SFH_HDR_MAXFRMNUM_OFS 0xC0
#define SFH_HDR_ELEM_OFS 0x180
#define SFH_HDR_ELEM_NUM 26
#define SFH_ELEM_SIZE 0x40

/* stream types */
#define SFH_STM_AUD 0xC0
#define SFH_STM_VID 0xE0
#define SFH_STM_PRV 0xBD

/* header tool versions (major * 100 + minor) */
#define SFH_VER_107 107
#define SFH_VER_110 110
#define SFH_VER_210 210

typedef struct SFH_OBJ {
	Sint32 stat;
	Uint8 *hdr;
	Sint32 size;
	Sint32 ver;
} SFH_OBJ;

/* one stream element record (0x40 bytes) */
typedef struct {
	Uint8 pad0[0x18];
	Uint8 id;
	Uint8 codec;
	Uint8 aud_layer;    /* video: bitrate (Sint16, big endian) */
	Uint8 aud_chnum;
	Uint8 aud_smphz[4]; /* video: picsz[3], picrate */
	Uint8 ftr_flag;
	Uint8 ftr_coltype;
	Uint8 ftr_pictype;
	Uint8 ftr_fixflg;
	Uint8 ftr_expand;
	Uint8 ftr_gopn;
	Uint8 ftr_gopm;
	Uint8 ftr_fxtype;
	Uint8 pad28[0x18];
} SFH_ELEM;

#define SFH_ELEM_BITRATE(e) (*(Uint16 *)&(e)->aud_layer)
#define SFH_ELEM_PICSZ(e) ((e)->aud_smphz)
#define SFH_ELEM_PICRATE(e) ((e)->aud_smphz[3])
#define SFH_ELEM_SMPHZ(e) (*(Uint32 *)(e)->aud_smphz)

typedef struct {
	Sint32 num;
	Sint32 used;
	SFH_OBJ *hn;
} SFH_OBJINF;

static Sint32 sfh_init_cont = 0;
static SFH_OBJINF sfh_objinf;
static const Char8 *sfhlib_version_dummy;

#define SWAP16(x) ((Uint16)((((x) & 0xFF) << 8) | (((x) >> 8) & 0xFF)))
#define SWAP32(x) (((x) << 24) | (((x) << 8) & 0x00FF0000) | (((x) >> 8) & 0x0000FF00) | (((x) >> 24) & 0xFF))

// Picture rate code (1..8) -> frame rate x1000 (23976 .. 60000); 0 for unknown.
// FUN_0052A300
Sint32 getPicRate(Uint32 code)
{
	switch (code) {
	case 1:
		return 23976;
	case 2:
		return 24000;
	case 3:
		return 25000;
	case 4:
		return 29970;
	case 5:
		return 30000;
	case 6:
		return 50000;
	case 7:
		return 59940;
	case 8:
		return 60000;
	default:
		return 0;
	}
}

// The handle has a validated header (SFH_IsSfdHeader succeeded).
static Bool sfh_IsValid(SFH sfh)
{
	Bool ret;

	switch (sfh->stat) {
	case SFH_STAT_INVALID:
	case SFH_STAT_FREE:
	case SFH_STAT_CREATED:
		ret = FALSE;
		break;
	default:
		ret = TRUE;
		break;
	}
	return ret;
}

// The handle slot is unused.
static Bool sfh_IsFree(SFH sfh)
{
	return (sfh->stat == SFH_STAT_FREE);
}

// Header tool version 1.07 or >= 1.10 can be analysed.
static Bool sfh_IsVerOk(SFH sfh)
{
	return (sfh->ver == SFH_VER_107 || sfh->ver >= SFH_VER_110);
}

// Valid handle with an analysable version.
static Bool sfh_IsAnlyOk(SFH sfh)
{
	if (!sfh_IsValid(sfh)) {
		return FALSE;
	}
	if (!sfh_IsVerOk(sfh)) {
		return FALSE;
	}
	return TRUE;
}

// The 0x40-byte element record of stream `id` among the 26 at offset 0x180, NULL if absent.
static SFH_ELEM *sfh_SearchElem(Uint8 *hdr, Uint32 id)
{
	Sint32 i;
	SFH_ELEM *p;
	SFH_ELEM *elem = NULL;

	for (i = 0; i < SFH_HDR_ELEM_NUM; i++) {
		p = (SFH_ELEM *)(hdr + SFH_HDR_ELEM_OFS + i * SFH_ELEM_SIZE);
		if (p->id == id) {
			elem = p;
			break;
		}
	}
	return elem;
}

// Element record of stream `id` after the handle checks.
// FUN_00529AF8
static SFH_ELEM *sfh_GetElem(SFH sfh, Uint32 id)
{
	Uint8 *hdr = sfh->hdr;

	if (!sfh_IsAnlyOk(sfh)) {
		return NULL;
	}
	return sfh_SearchElem(hdr, id);
}

// Stream id class: 0xC0..0xDF audio, 0xE0..0xEF video, 0xBD/0xBF private, else 0.
static Uint32 sfh_GetStmType(Uint32 id)
{
	Uint32 type = id;

	if (type >= 0xC0 && type <= 0xDF) {
		type = SFH_STM_AUD;
	} else if (type >= 0xE0 && type <= 0xEF) {
		type = SFH_STM_VID;
	} else if (type == 0xBD || type == 0xBF) {
		type = SFH_STM_PRV;
	} else {
		type = 0;
	}
	return type;
}

// The audio element carries a feature block (flag == 1).
// FUN_0052A370
static Bool sfh_IsEffFtrAud(Uint32 id, SFH_ELEM *elem)
{
	Uint32 flg;

	if (sfh_GetStmType(id) != SFH_STM_AUD) {
		return FALSE;
	}
	flg = elem->ftr_flag;
	if (flg > 1) {
		return FALSE;
	} else if (flg == 0) {
		return FALSE;
	}
	return TRUE;
}

// The video element carries a feature block (flag == 1).
// FUN_0052A3B0
static Bool sfh_IsEffFtrVid(Uint32 id, SFH_ELEM *elem)
{
	Uint32 flg;

	if (sfh_GetStmType(id) != SFH_STM_VID) {
		return FALSE;
	}
	flg = elem->ftr_flag;
	if (flg > 1) {
		return FALSE;
	} else if (flg == 0) {
		return FALSE;
	}
	return TRUE;
}

// ASCII digit test.
static Bool sfh_IsDigit(Sint32 c)
{
	return (c >= '0' && c <= '9');
}

// Copies the 32-character muxer tool string (offset 0x60) into a NUL-terminated buffer.
static Bool sfh_GetToolStr(SFH sfh, Uint8 *str, Char8 *buf)
{
	if (!sfh_IsValid(sfh)) {
		return FALSE;
	}
	memset(buf, 0, SFH_HDR_TOOLSTR_LEN + 1);
	memcpy(buf, str, SFH_HDR_TOOLSTR_LEN);
	return TRUE;
}

// Parses a decimal number up to '.', ' ' or NUL, advancing the pointer.
static Sint32 sfh_Atoi(const Char8 **pp)
{
	const Char8 *p = *pp;
	Sint32 c;
	Sint32 num = 0;

	for (;;) {
		c = *p;
		if (c == '.' || c == ' ' || c == '\0') {
			break;
		}
		if (!sfh_IsDigit(c)) {
			break;
		}
		num = num * 10 + c;
		num -= '0';
		p++;
	}
	*pp = p;
	return num;
}

// "Ver.M.m" out of the tool string.
static Bool sfh_GetStrVer(const Char8 *buf, Sint32 *major, Sint32 *minor)
{
	const Char8 *p;

	p = strstr(buf, "Ver.");
	if (p == NULL) {
		return FALSE;
	}
	p += 4;
	*major = sfh_Atoi(&p);
	p++;
	*minor = sfh_Atoi(&p);
	return TRUE;
}

/* feature (ftr) fields of a video element */

// FUN_0052A270
Bool SFH_AnlyFtrFxType(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	if (sfh->ver < SFH_VER_210) {
		return FALSE;
	}
	*val = elem->ftr_fxtype;
	return TRUE;
}

// Video feature: GOP M (P-picture spacing).
// FUN_0052A1E8
Bool SFH_AnlyFtrGopM(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_gopm;
	if (*val > 0x3F) {
		*val = -1;
	}
	return TRUE;
}

// Video feature: GOP N (GOP length).
// FUN_0052A160
Bool SFH_AnlyFtrGopN(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_gopn;
	if (*val > 0x3F) {
		*val = -1;
	}
	return TRUE;
}

// Video feature: expand flag.
// FUN_0052A0F0
Bool SFH_AnlyFtrExpand(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_expand;
	return TRUE;
}

// Video feature: sequence-header-code fixed flag.
// FUN_0052A078
Bool SFH_AnlyFtrShcFixFlg(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = (elem->ftr_fixflg & 0x10) >> 4;
	return TRUE;
}

// Video feature: fixed flag.
// FUN_0052A008
Bool SFH_AnlyFtrFixFlg(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_fixflg & 1;
	return TRUE;
}

// Video feature: picture type restriction.
// FUN_00529F98
Bool SFH_AnlyFtrPicType(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_pictype;
	return TRUE;
}

// Video feature: colour type (3 = colour-space conversion needed; drives the SFX colour adjustment).
// FUN_00529F28
Bool SFH_AnlyFtrColType(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (!sfh_IsEffFtrVid(id, elem)) {
		return FALSE;
	}
	*val = elem->ftr_coltype;
	return TRUE;
}

/* element fields */

// FUN_00529EB8
Bool SFH_AnlyElemPicRate(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_VID) {
		return FALSE;
	}
	*val = getPicRate(SFH_ELEM_PICRATE(elem));
	return TRUE;
}

// Video element: picture width and height (24-bit fields).
Bool SFH_AnlyElemPicSz(SFH sfh, Uint8 id, Sint32 *width, Sint32 *height)
{
	SFH_ELEM *elem;

	*width = 0;
	*height = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_VID) {
		return FALSE;
	}
	*width = SFH_ELEM_PICSZ(elem)[0];
	*width = (*width << 4) | ((SFH_ELEM_PICSZ(elem)[1] >> 4) & 0x0F);
	*width &= 0xFFF;
	*height = SFH_ELEM_PICSZ(elem)[1];
	*height = (*height << 8) | SFH_ELEM_PICSZ(elem)[2];
	*height &= 0xFFF;
	return TRUE;
}

// Video element: bit rate (big-endian 16-bit).
Bool SFH_AnlyElemBitRate(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;
	Sint32 rate, tmp;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_VID) {
		return FALSE;
	}
	/* 16-bit swap written with a (Uint8) cast: keeps srawi/clrlwi unmerged (the & 0xFF form of
	 * SWAP16 gives extrwi) */
	rate = (Sint16)(Uint16)(((SFH_ELEM_BITRATE(elem) & 0xFF) << 8) | (Uint8)(SFH_ELEM_BITRATE(elem) >> 8));
	tmp = rate;
	if (rate == 0xFFFF) {
		tmp = 0;
	}
	*val = tmp;
	return TRUE;
}

// Video element: codec id.
// FUN_00529D20
Bool SFH_AnlyElemCodecVid(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_VID) {
		return FALSE;
	}
	*val = elem->codec;
	return TRUE;
}

// Audio element: sampling rate (big-endian 32-bit).
Bool SFH_AnlyElemSmpHz(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;
	Uint32 w;
	Sint32 z;
	Bool ret;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_AUD) {
		return FALSE;
	}
	/* COMPILER-DIFF: M4 (dead conditional, CRI pass 77) -- the original keeps the rlwinm/rlwimi x3/stw
	 * chain because its store sits in another basic block than the chain: the post-RA peephole's
	 * stwbrx rule follows a per-block def table, so a block boundary between the value and the store
	 * is what stops the fold. The frontend keeps `z = 0; if (z != 0)` (it does not propagate own-local
	 * constants into relational compares), the post-RA peephole then folds `li; cmpi; bt` into the
	 * fall-through and deletes the unreachable arm. `ret = TRUE` before the compare puts `li r3,1`
	 * next to the load; the arm's read of `id` keeps r4 live across the load, so the word takes r6. */
	w = SWAP32(SFH_ELEM_SMPHZ(elem));
	ret = TRUE;
	z = 0;
	if (z != 0) {
		ret = id;
	}
	*val = w;
	return ret;
}

// Audio element: channel count.
// FUN_00529C40
Bool SFH_AnlyElemChNum(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_AUD) {
		return FALSE;
	}
	*val = elem->aud_chnum;
	return TRUE;
}

// Audio element: layer.
// FUN_00529BC0
Bool SFH_AnlyElemLayer(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = 0;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_AUD) {
		return FALSE;
	}
	if (elem->codec != 1) {
		return FALSE;
	}
	*val = elem->aud_layer;
	return TRUE;
}

// Audio element: codec id.
// FUN_00529B50
Bool SFH_AnlyElemCodecAud(SFH sfh, Uint8 id, Sint32 *val)
{
	SFH_ELEM *elem;

	*val = -1;
	elem = sfh_GetElem(sfh, id);
	if (elem == NULL) {
		return FALSE;
	}
	if (sfh_GetStmType(id) != SFH_STM_AUD) {
		return FALSE;
	}
	*val = elem->codec;
	return TRUE;
}

/* pack / file level fields: the public functions are wrappers around these readers, which gives
 * hdr the register below the IsValid flag (a caller-declared hdr gets the one above it). The two
 * 32-bit readers use the SFH_AnlyElemSmpHz dead-conditional form (COMPILER-DIFF M4): the block
 * boundary keeps the swap chain out of the stwbrx fold, and the arm's read of `hdr` keeps r5 live
 * across the load so the word takes r6. */

static Bool sfh_GetHdrU32(SFH sfh, Sint32 ofs, Sint32 *val)
{
	Uint8 *hdr = sfh->hdr;
	Uint32 w;
	Sint32 z;
	Bool ret;

	if (!sfh_IsAnlyOk(sfh)) {
		return FALSE;
	}
	w = SWAP32(*(Uint32 *)(hdr + ofs));
	ret = TRUE;
	z = 0;
	if (z != 0) {
		ret = (Sint32)hdr;
	}
	*val = w;
	return ret;
}

// Big-endian 16-bit header field after the handle checks.
static Bool sfh_GetHdrS16(SFH sfh, Sint32 ofs, Sint32 *val)
{
	Uint8 *hdr = sfh->hdr;

	if (!sfh_IsAnlyOk(sfh)) {
		return FALSE;
	}
	*val = (Sint16)SWAP16(*(Sint16 *)(hdr + ofs));
	return TRUE;
}

// Byte header field after the handle checks.
static Bool sfh_GetHdrU8(SFH sfh, Sint32 ofs, Sint32 *val)
{
	Uint8 *hdr = sfh->hdr;

	if (!sfh_IsAnlyOk(sfh)) {
		return FALSE;
	}
	*val = hdr[ofs];
	return TRUE;
}

// Big-endian 32-bit header field, only for tool versions >= `ver`.
static Bool sfh_GetHdrU32Ver(SFH sfh, Sint32 ofs, Sint32 ver, Sint32 *val)
{
	Uint8 *hdr = sfh->hdr;
	Uint32 w;
	Sint32 z;
	Bool ret;

	if (!sfh_IsAnlyOk(sfh)) {
		return FALSE;
	}
	if (sfh->ver < ver) {
		return FALSE;
	}
	w = SWAP32(*(Uint32 *)(hdr + ofs));
	ret = TRUE;
	z = 0;
	if (z != 0) {
		ret = (Sint32)hdr;
	}
	*val = w;
	return ret;
}

// Total video frame count (offset 0xC0; what mwPlyGetHdrInf reports as maxfrm).
Bool SFH_AnlyMaxFrmNum(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32(sfh, SFH_HDR_MAXFRMNUM_OFS, val);
}

// Maximum video packet payload length (0xBC).
Bool SFH_AnlyMaxPlyLenVid(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32(sfh, SFH_HDR_MAXPLYLEN_VID_OFS, val);
}

// Maximum audio packet payload length (0xB8).
Bool SFH_AnlyMaxPlyLenAud(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32(sfh, SFH_HDR_MAXPLYLEN_AUD_OFS, val);
}

// Byte rate (0xB4; versions before 1.10 report it negative).
Bool SFH_AnlyByteRate(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32Ver(sfh, SFH_HDR_BYTERATE_OFS, SFH_VER_110, val);
}

// Number of private elements (0xB3).
Bool SFH_AnlyNumElemPrv(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU8(sfh, SFH_HDR_NUMELEM_PRV_OFS, val);
}

// Number of video elements (0xB2).
Bool SFH_AnlyNumElemVid(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU8(sfh, SFH_HDR_NUMELEM_VID_OFS, val);
}

// Number of audio elements (0xB1).
Bool SFH_AnlyNumElemAud(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU8(sfh, SFH_HDR_NUMELEM_AUD_OFS, val);
}

// Total element count (0xB0).
Bool SFH_AnlyNumElemTot(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU8(sfh, SFH_HDR_NUMELEM_TOT_OFS, val);
}

// Pack size (0x8C; 0x800 for GameCube movies).
Bool SFH_AnlyPackSiz(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32(sfh, SFH_HDR_PACKSIZ_OFS, val);
}

// Packet size field length (0x88).
Bool SFH_AnlyPketSizLen(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrS16(sfh, SFH_HDR_PKETSIZLEN_OFS, val);
}

// Pack type (0x84).
Bool SFH_AnlyPackType(SFH sfh, Sint32 *val)
{
	*val = -1;
	return sfh_GetHdrU8(sfh, SFH_HDR_PACKTYPE_OFS, val);
}

// Header size (0x80).
Bool SFH_AnlyHdrSiz(SFH sfh, Sint32 *val)
{
	*val = 0;
	return sfh_GetHdrU32(sfh, SFH_HDR_SIZ_OFS, val);
}

// Muxer tool version: the larger of the binary version bytes (0x38/0x39) and the "Ver.M.m" parsed
// from the tool string.
Bool SFH_AnlyHdrToolVer(SFH sfh, Sint32 *major, Sint32 *minor)
{
	Char8 buf[SFH_HDR_TOOLSTR_LEN + 1];
	Uint8 *hdr;
	Uint8 *str;
	Sint32 smajor, sminor;
	Sint32 hmajor, hminor;

	*major = 0;
	*minor = 0;
	hdr = sfh->hdr;
	str = hdr + SFH_HDR_TOOLSTR_OFS;
	buf[0] = '\0';
	if (!sfh_GetToolStr(sfh, str, buf)) {
		return FALSE;
	}
	hmajor = hdr[SFH_HDR_VER_MAJOR_OFS];
	hminor = hdr[SFH_HDR_VER_MINOR_OFS];
	if (!sfh_GetStrVer(buf, &smajor, &sminor)) {
		return FALSE;
	}
	if (hmajor * 100 + hminor >= smajor * 100 + sminor) {
		*major = hmajor;
		*minor = hminor;
	} else {
		*major = smajor;
		*minor = sminor;
	}
	return TRUE;
}

// Whether stream `id` (audio or video) carries a feature block (tool version >= 1.10).
// FUN_005290A0
Bool SFH_IsEffFtrInf(SFH sfh, Uint8 id, Sint32 *flag)
{
	SFH_ELEM *elem;
	Sint32 ver = sfh->ver; /* a local copy: the inlined sfh_IsVerOk reloads sfh->ver */
	Uint32 sid;

	if (ver < SFH_VER_110) {
		return FALSE;
	}
	sid = id; /* one zero-extension (r0) shared by the switch, the search and the type check */
	switch (sfh_GetStmType(sid)) {
	case SFH_STM_AUD:
		elem = sfh_GetElem(sfh, sid);
		if (elem == NULL) {
			return FALSE;
		}
		*flag = sfh_IsEffFtrAud(sid, elem);
		break;
	case SFH_STM_VID:
		elem = sfh_GetElem(sfh, sid);
		if (elem == NULL) {
			return FALSE;
		}
		*flag = sfh_IsEffFtrVid(sid, elem);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

// Whether an element record for stream `id` exists.
// FUN_00529030
Bool SFH_IsExistStmId(SFH sfh, Uint8 id, Sint32 *flag)
{
	Uint8 *hdr;

	*flag = 0;
	hdr = sfh->hdr;
	if (!sfh_IsAnlyOk(sfh)) {
		return FALSE;
	}
	if (sfh_SearchElem(hdr, id) != NULL) {
		*flag = 1;
	} else {
		*flag = 0;
	}
	return TRUE;
}

// Validates the header: >= 0x800 bytes and the "SofdecStream" id at 0x20; records the tool version.
// FUN_00528F40
Bool SFH_IsSfdHeader(SFH sfh, Sint32 *flag)
{
	Uint8 *idstr;
	Sint32 major, minor;

	*flag = 0;
	idstr = sfh->hdr + SFH_HDR_ID_OFS;
	if (sfh_IsFree(sfh) == TRUE) {
		return FALSE;
	}
	if ((Uint32)sfh->size < SFH_HDR_MIN_SIZE) {
		sfh->stat = SFH_STAT_INVALID;
		return FALSE;
	}
	if (memcmp(idstr, "SofdecStream            ", SFH_HDR_ID_LEN) != 0) {
		sfh->stat = SFH_STAT_INVALID;
		return FALSE;
	}
	sfh->stat = SFH_STAT_VALID;
	if (!SFH_AnlyHdrToolVer(sfh, &major, &minor)) {
		return FALSE;
	}
	sfh->ver = major * 100 + minor;
	*flag = 1;
	return TRUE;
}

// Frees the analyser handle.
void SFH_Destroy(SFH sfh)
{
	sfh->stat = SFH_STAT_FREE;
	sfh->hdr = NULL;
	sfh->size = 0;
	sfh->ver = 0;
	sfh_objinf.used--;
}

// Takes a free analyser handle over the header bytes (state CREATED until validated).
SFH SFH_Create(void *hdr, Sint32 size)
{
	Sint32 num = sfh_objinf.num;
	SFH_OBJ *hn = sfh_objinf.hn;
	SFH sfh = NULL;
	Sint32 i;

	if (sfh_objinf.used >= num) {
		return NULL;
	}
	for (i = 0; i < num; i++) {
		sfh = &hn[i];
		if (sfh->stat == SFH_STAT_FREE) {
			break;
		}
	}
	sfh->stat = SFH_STAT_CREATED;
	sfh->hdr = hdr;
	sfh->size = size;
	sfh_objinf.used++;
	return sfh;
}

// Clears the handle table.
static void sfh_ClearHn(SFH_OBJ *hn, Sint32 num)
{
	Sint32 i;

	for (i = 0; i < num; i++) {
		hn[i].stat = 0;
		hn[i].hdr = NULL;
		hn[i].size = 0;
		hn[i].ver = 0;
	}
}

// Library init (once): handle table in the caller's work.
void SFH_Init(Sint32 num, void *work)
{
	if (sfh_init_cont > 0) {
		return;
	}
	sfh_init_cont++;
	sfhlib_version_dummy = SFH_sbver_str;
	sfh_ClearHn(work, num);
	sfh_objinf.num = num;
	sfh_objinf.used = 0;
	sfh_objinf.hn = work;
}
