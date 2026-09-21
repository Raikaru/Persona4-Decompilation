/* CRI Sofdec: file header (SFD header packet) analysis and storage (sfd_hds.c). The 0x800-byte raw
 * header handed in by the input driver is parsed through the SFH analyser into SFHDS_FHD. */
#include "cri_xpt.h"
#include "sfd.h"
#include "sfh.h"

extern void MEM_Copy(void *dst, const void *src, Uint32 nbytes);

#define SFHDS_SFH_NUM 0x20
#define SFHDS_SFH_WORK_SIZE 0x204

/* SFD condition ids */
#define SFD_COND_HDRCB_FN 0x4B
#define SFD_COND_HDRCB_OBJ 0x4C

typedef void (*SFHDS_HDRCB)(void *obj, Uint8 *data, Sint32 size);

static Uint8 sfhds_sfhlib_work[SFHDS_SFH_WORK_SIZE];

/* the seek work's copy of the file header, when the seek work is attached and no concatenation
 * is going on (a macro: `#pragma dont_inline` around sfhds_SetHdrRaw would keep a static helper
 * out of line there) */
#define SFHDS_GET_SEE_FHD(sfd) \
	((sfd)->see.wk == NULL ? NULL : SFMPS_GetConcatCnt(sfd) > 0 ? NULL : &(sfd)->see.wk->fhd)

// Colour type from the Sofdec header's video feature block (3 = needs colour-space conversion), -1
// when no header / no features.
// FUN_00517878
Sint32 SFHDS_GetColType(SFD sfd)
{
	SFHDS_FHD *fhd = &sfd->fhd;
	SFHDS_VID *vid = &fhd->vid;

	if (fhd->valid == 0) {
		return -1;
	}
	if (vid->ftr_eff != 0) {
		return vid->ftr_coltype;
	}
	return -1;
}

/* muxer tool version as one number (1.10 -> 110) */
static Sint32 sfhds_GetVerNum(SFHDS_FHD *fhd)
{
	return fhd->ver_major * 100 + fhd->ver_minor;
}

// Muxer tool version of the analysed header as major*100+minor, 0 when unknown.
Sint32 SFHDS_GetMuxVerNum(SFD sfd)
{
	if (sfd->fhd.valid != 0) {
		return sfhds_GetVerNum(&sfd->fhd);
	}
	return 0;
}

/* first stream id in [first, last] present in the header, 0 when none */
static Sint32 sfhds_SearchStmId(SFH sfh, Sint32 first, Sint32 last, Sint32 *exist)
{
	Sint32 id;

	for (id = first; id <= last; id++) {
		if (SFH_IsExistStmId(sfh, id, exist) && *exist != 0) {
			return id;
		}
	}
	return 0;
}

/* The vid-section results go through their own locals (v_*) instead of `?:`: the range-split copy of `id`
 * used there has 30 neighbours when the nine `?:` join values are frontend temporaries (created after
 * it, so scanned after it), which keeps it in the colouring level of fhd/sfh (r31); as own locals they
 * are removed first and `id` drops to the level of ver (r29), fhd r31 / sfh r30 as the target (CRI pass 13). */
void sfhds_DoProcessHdr(SFH sfh, SFHDS_FHD *fhd)
{
	Sint32 ver;
	Sint32 is_sfd;
	Sint32 rate;
	Sint32 major;
	Sint32 minor;
	Sint32 ex_prv1;
	Sint32 ex_prv2;
	Sint32 ex_aud;
	Sint32 ex_vid;
	Sint32 eff;
	Sint32 hdrsiz;
	Sint32 packtype;
	Sint32 pketsizlen;
	Sint32 packsiz;
	Sint32 numtot;
	Sint32 numaud;
	Sint32 numvid;
	Sint32 numprv;
	Sint32 maxplyaud;
	Sint32 maxplyvid;
	Sint32 maxfrm;
	Sint32 acodec;
	Sint32 layer;
	Sint32 chnum;
	Sint32 smphz;
	Sint32 vcodec;
	Sint32 bitrate;
	Sint32 picrate;
	Sint32 coltype;
	Sint32 pictype;
	Sint32 fixflg;
	Sint32 shcfixflg;
	Sint32 expand;
	Sint32 gopn;
	Sint32 gopm;
	Sint32 id;
	Sint32 v_vcodec;
	Sint32 v_bitrate;
	Sint32 v_picrate;
	Sint32 v_coltype;
	Sint32 v_pictype;
	Sint32 v_fixflg;
	Sint32 v_shcfixflg;
	Sint32 v_expand;
	Sint32 v_gopn;
	Sint32 v_gopm;

	if (SFH_IsSfdHeader(sfh, &is_sfd) == 0) {
		is_sfd = 0;
	}
	if (is_sfd == 0) {
		return;
	}

	if (SFH_AnlyHdrToolVer(sfh, &major, &minor) == 0) {
		major = 0;
		minor = 0;
	}
	fhd->ver_major = major;
	fhd->ver_minor = minor;
	ver = sfhds_GetVerNum(fhd);

	if (SFH_AnlyByteRate(sfh, &rate) == 0) {
		rate = 0;
	}
	if (ver < 110) {
		rate = -rate;
	}
	fhd->byterate = rate;

	fhd->hdrsiz = (SFH_AnlyHdrSiz(sfh, &hdrsiz) == 0) ? -1 : hdrsiz;
	fhd->packtype = (SFH_AnlyPackType(sfh, &packtype) == 0) ? -1 : packtype;
	fhd->pketsizlen = (SFH_AnlyPketSizLen(sfh, &pketsizlen) == 0) ? -1 : pketsizlen;
	if (fhd->pketsizlen == -1) {
		fhd->pketsizlen = 2;
	}
	fhd->packsiz = (SFH_AnlyPackSiz(sfh, &packsiz) == 0) ? -1 : packsiz;
	fhd->numelem_tot = (SFH_AnlyNumElemTot(sfh, &numtot) == 0) ? -1 : numtot;
	fhd->numelem_aud = (SFH_AnlyNumElemAud(sfh, &numaud) == 0) ? -1 : numaud;
	fhd->numelem_vid = (SFH_AnlyNumElemVid(sfh, &numvid) == 0) ? -1 : numvid;
	fhd->numelem_prv = (SFH_AnlyNumElemPrv(sfh, &numprv) == 0) ? -1 : numprv;
	fhd->maxplylen_aud = (SFH_AnlyMaxPlyLenAud(sfh, &maxplyaud) == 0) ? -1 : maxplyaud;
	fhd->maxplylen_vid = (SFH_AnlyMaxPlyLenVid(sfh, &maxplyvid) == 0) ? -1 : maxplyvid;
	fhd->maxfrmnum = (SFH_AnlyMaxFrmNum(sfh, &maxfrm) == 0) ? -1 : maxfrm;

	if (SFH_IsExistStmId(sfh, 0xBD, &ex_prv1) && ex_prv1 != 0) {
		id = 0xBD;
	} else {
		id = 0;
	}
	fhd->stmid_prv1 = id;
	if (SFH_IsExistStmId(sfh, 0xBF, &ex_prv2) && ex_prv2 != 0) {
		id = 0xBF;
	} else {
		id = 0;
	}
	fhd->stmid_prv2 = id;
	fhd->stmid_aud = sfhds_SearchStmId(sfh, 0xC0, 0xDF, &ex_aud);
	fhd->stmid_vid = sfhds_SearchStmId(sfh, 0xE0, 0xEF, &ex_vid);

	id = fhd->stmid_aud;
	if (id != 0) {
		fhd->aud.codec = (SFH_AnlyElemCodecAud(sfh, id, &acodec) == 0) ? -1 : acodec;
		fhd->aud.layer = (SFH_AnlyElemLayer(sfh, id, &layer) == 0) ? -1 : layer;
		fhd->aud.chnum = (SFH_AnlyElemChNum(sfh, id, &chnum) == 0) ? -1 : chnum;
		fhd->aud.smphz = (SFH_AnlyElemSmpHz(sfh, id, &smphz) == 0) ? -1 : smphz;
	}

	id = fhd->stmid_vid;
	if (SFH_AnlyElemCodecVid(sfh, id, &vcodec) == 0) {
		v_vcodec = -1;
	} else {
		v_vcodec = vcodec;
	}
	fhd->vid.codec = v_vcodec;
	if (SFH_AnlyElemBitRate(sfh, id, &bitrate) == 0) {
		v_bitrate = -1;
	} else {
		v_bitrate = bitrate;
	}
	fhd->vid.bitrate = v_bitrate;
	if (SFH_AnlyElemPicSz(sfh, id, &fhd->vid.picw, &fhd->vid.pich) == 0) {
		fhd->vid.picw = -1;
		fhd->vid.pich = -1;
	}
	if (SFH_AnlyElemPicRate(sfh, id, &picrate) == 0) {
		v_picrate = -1;
	} else {
		v_picrate = picrate;
	}
	fhd->vid.picrate = v_picrate;
	if (SFH_IsEffFtrInf(sfh, id, &eff) == 0) {
		eff = 0;
	}
	fhd->vid.ftr_eff = (eff != 0);
	if (eff != 0) {
		if (SFH_AnlyFtrColType(sfh, id, &coltype) == 0) {
			v_coltype = -1;
		} else {
			v_coltype = coltype;
		}
		fhd->vid.ftr_coltype = v_coltype;
		if (SFH_AnlyFtrPicType(sfh, id, &pictype) == 0) {
			v_pictype = -1;
		} else {
			v_pictype = pictype;
		}
		fhd->vid.ftr_pictype = v_pictype;
		if (SFH_AnlyFtrFixFlg(sfh, id, &fixflg) == 0) {
			v_fixflg = -1;
		} else {
			v_fixflg = fixflg;
		}
		fhd->vid.ftr_fixflg = v_fixflg;
		if (SFH_AnlyFtrShcFixFlg(sfh, id, &shcfixflg) == 0) {
			v_shcfixflg = -1;
		} else {
			v_shcfixflg = shcfixflg;
		}
		fhd->vid.ftr_shcfixflg = v_shcfixflg;
		if (SFH_AnlyFtrExpand(sfh, id, &expand) == 0) {
			v_expand = -1;
		} else {
			v_expand = expand;
		}
		fhd->vid.ftr_expand = v_expand;
		if (SFH_AnlyFtrGopN(sfh, id, &gopn) == 0) {
			v_gopn = -1;
		} else {
			v_gopn = gopn;
		}
		fhd->vid.ftr_gopn = v_gopn;
		if (SFH_AnlyFtrGopM(sfh, id, &gopm) == 0) {
			v_gopm = -1;
		} else {
			v_gopm = gopm;
		}
		fhd->vid.ftr_gopm = v_gopm;
	}
	fhd->valid = 1;
}

// Parses the raw 0x800-byte header packet through the SFH analyser into the SFHDS_FHD fields
// (stream counts and ids, audio codec/rate/channels, video size/rate/bitrate, feature block).
// FUN_005171F0
void SFHDS_ProcessHdr(SFHDS_FHD *fhd)
{
	SFH sfh;

	sfh = SFH_Create(fhd->raw, fhd->rawsiz);
	if (sfh != NULL) {
		sfhds_DoProcessHdr(sfh, fhd);
		SFH_Destroy(sfh);
	}
}

// Re-parses the header kept in the seek work (after a reset) into the handle and refreshes the
// element counts.
void SFHDS_ReprocessHdr(SFD sfd)
{
	SFHDS_FHD *src;

	src = SFHDS_GET_SEE_FHD(sfd);
	if (src != NULL) {
		sfd->fhd = *src;
		SFHDS_ProcessHdr(&sfd->fhd);
		sfd->numelem_aud = sfd->fhd.numelem_aud;
		sfd->numelem_vid = sfd->fhd.numelem_vid;
		sfd->numelem_prv = sfd->fhd.numelem_prv;
	}
}

// A Sofdec header packet arrived from the demuxer: calls the header callback (cond 0x4B/0x4C: the
// MW player's mwsffrm_AnalySofdecHeader), and on the first header copies up to 0x800 bytes into the
// handle, parses it, publishes the element counts and mirrors it into the seek work. 1 = consumed.
Sint32 sfhds_SetHdrRaw(SFD sfd, Uint8 *data, Sint32 size)
{
	SFHDS_HDRCB cbfn;
	void *cbobj;
	Sint32 n;
	SFHDS_FHD *dst;

	cbfn = (SFHDS_HDRCB)SFSET_GetCond(sfd, SFD_COND_HDRCB_FN);
	cbobj = (void *)SFSET_GetCond(sfd, SFD_COND_HDRCB_OBJ);
	if (cbfn != NULL) {
		cbfn(cbobj, data, size);
	}
	if (sfd->fhd.valid != 0) {
		return 0;
	}
	n = SFHDS_RAW_SIZE;
	if (size < SFHDS_RAW_SIZE) {
		n = size;
	}
	MEM_Copy(sfd->fhd.raw, data, n);
	sfd->fhd.rawsiz = n;
	SFHDS_ProcessHdr(&sfd->fhd);
	sfd->numelem_aud = sfd->fhd.numelem_aud;
	sfd->numelem_vid = sfd->fhd.numelem_vid;
	sfd->numelem_prv = sfd->fhd.numelem_prv;
	dst = SFHDS_GET_SEE_FHD(sfd);
	if (dst != NULL) {
		*dst = sfd->fhd;
	}
	return 1;
}

// Whether the bytes are a Sofdec header packet (SFH_IsSfdHeader on a temporary analyser).
// FUN_00516F08
Bool SFHDS_IsSfdHeader(void *data, Sint32 size)
{
	SFH sfh;
	Sint32 flag;

	sfh = SFH_Create(data, size);
	if (sfh == NULL) {
		return 0;
	}
	if (SFH_IsSfdHeader(sfh, &flag) == 0) {
		flag = 0;
	}
	SFH_Destroy(sfh);
	return flag;
}

#define SFHDS_STARTCODE_PRV2 0x1BF

/* big-endian 32-bit start code at p */
// FUN_00516ED8
static Sint32 sfhds_GetStartCode(Uint8 *p)
{
	Sint32 code;

	code = (p[0] << 8) | p[1];
	code <<= 8;
	code |= p[2];
	code <<= 8;
	code |= p[3];
	return code;
}

/* set the header from the private stream 2 packet whose start code is at p */
static Bool sfhds_SetHdrPkt(SFD sfd, Uint8 *p, Sint32 len, Sint32 *result)
{
	if (SFHDS_IsSfdHeader(p - 12, len + 12) == 0) {
		return 0;
	}
	*result = sfhds_SetHdrRaw(sfd, p - 12, len + 12);
	return 1;
}

/* the file header travels in a private stream 2 packet: `data` points at its payload */
/* COMPILER-DIFF: M1 (codeless neighbour pin) - the target keeps a copy of `result` (`mr r30, r7`) as the
 * first own local (r30 above len r29 / p r28 / sfd r27). `result` only feeds stores, so a plain typed copy
 * is removed by the backend copy propagation (CRI pass 12); the pin's `mr r11, res` is a register move
 * that cannot collapse, which keeps the copy, and both `mr`s of the pin are deleted by the RA (pass 40) */
Bool SFHDS_SetHdr(SFD sfd, Sint32 type, Uint8 *data, Sint32 size, Sint32 *result)
{
	register Sint32 *res;
	Sint32 len;
	Uint8 *p;

	res = (Sint32 *)(void *)result;
	 // COMPILER-DIFF: M1 (codeless neighbour pin)
	*res = 0;
	if (type != 2) {
		return 0;
	}
	p = data - 6;
	len = size + 6;
	if (sfhds_GetStartCode(p) != SFHDS_STARTCODE_PRV2) {
		p -= 2;
		len += 2;
		if (sfhds_GetStartCode(p) != SFHDS_STARTCODE_PRV2) {
			return 0;
		}
	}
	return sfhds_SetHdrPkt(sfd, p, len, res);
}

// Invalidates the header analysis (handle reset).
void SFHDS_FinishFhd(SFHDS_FHD *fhd)
{
	fhd->valid = 0;
	fhd->byterate = 0;
	fhd->rawsiz = 0;
}

// Clears the header analysis (handle creation).
void SFHDS_InitFhd(SFHDS_FHD *fhd)
{
	fhd->valid = 0;
	fhd->ver_major = 0;
	fhd->ver_minor = 0;
	fhd->byterate = 0;
	fhd->rawsiz = 0;
}

// Library init: gives the SFH analyser its 32 objects' work.
// FUN_00516D98
void SFHDS_Init(void)
{
	SFH_Init(SFHDS_SFH_NUM, sfhds_sfhlib_work);
}
