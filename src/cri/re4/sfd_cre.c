/* CRI Sofdec: creation information analysis (sfd_cre.c). Scans the head of a file for the MPEG
 * system / video / ADX / MPEG audio headers to pick the transfer drivers and the stream parameters. */
#include "cri_xpt.h"
#include "sfd.h"
#include "mps.h"
#include "mpv.h"
#include <string.h>

extern void MEM_Copy(void *dst, const void *src, Uint32 nbytes);
extern Bool SFADXT_IsHeader(Uint8 *data, Sint32 size, Sint32 *hdrsiz);

extern const SFD_TR_IF SFD_tr_sd_mps;
extern const SFD_TR_IF SFD_tr_vd_mpv;
extern const SFD_TR_IF SFD_tr_ad_adxt;

#define SFCRE_TMPBUF_SIZE 0x800

/* MPEG audio (AAU) header fields */
typedef struct {
	Uint8 layer;       /* 0x0 */
	Uint8 protect;     /* 0x1 */
	Uint8 bitrate;     /* 0x2 */
	Uint8 sfreq;       /* 0x3 */
	Uint8 padding;     /* 0x4 */
	Uint8 prv;         /* 0x5 */
	Uint8 mode;        /* 0x6 */
	Uint8 mode_ext;    /* 0x7 */
	Uint8 copyright;   /* 0x8 */
	Uint8 original;    /* 0x9 */
	Uint8 emphasis;    /* 0xA */
} SFCRE_AAUHDR;

const Sint32 sfcre_mpv_picrate[9] = {
	0, 23976, 24000, 25000, 29970, 30000, 50000, 59940, 60000,
};
const Sint32 sfcre_aau_ch[4] = { 2, 2, 2, 1 };
const Sint32 sfcre_aau_freq[4] = { 44100, 48000, 32000, 0 };
const Sint32 sfcre_aau_bitrate[4][16] = {
	{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
	{ -1, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, -1 },
	{ -1, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, -1 },
	{ -1, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, -1 },
};
const Sint32 sfcre_aau_const_siz[4] = { -1, 1152, 1152, 384 };

SFCRE_AAUHDR sfcre_aauhdr;
SFHDS_FHD sfcre_fhd;
Uint8 sfcre_tmpbuf[SFCRE_TMPBUF_SIZE];

/* first MPEG system start code of kind `code` (MPS_CheckDelim class) */
// FUN_005166B0
static Uint8 *sfcre_SearchDelim(Uint8 *p, Sint32 n, Uint32 code)
{
	while (n >= 4) {
		if (MPS_CheckDelim(p) == code) {
			return p;
		}
		p++;
		n--;
	}
	return NULL;
}

/* first valid MPEG audio frame header */
static Uint8 *sfcre_SearchAauHdr(Uint8 *p, Sint32 n, SFCRE_AAUHDR *hdr)
{
	while (n >= 4) {
		if (p[0] == 0xFF && (p[1] & 0xF8) == 0xF8) {
			hdr->layer = (p[1] >> 1) & 3;
			hdr->protect = p[1] & 1;
			hdr->bitrate = (p[2] >> 4) & 0xF;
			hdr->sfreq = (p[2] >> 2) & 3;
			hdr->padding = (p[2] >> 1) & 1;
			hdr->prv = p[2] & 1;
			hdr->mode = (p[3] >> 6) & 3;
			hdr->mode_ext = (p[3] >> 4) & 3;
			hdr->copyright = (p[3] >> 3) & 1;
			hdr->original = (p[3] >> 2) & 1;
			hdr->emphasis = p[3] & 3;
			if (hdr->layer != 0 && hdr->bitrate != 0xF && hdr->sfreq != 3) {
				return p;
			}
		}
		p++;
		n--;
	}
	return NULL;
}

// Looks for an MPEG audio frame header in the data: on success selects the ADX audio driver slot
// with the AAU's channel count / rate (audio-only MPEG file). 1 when found.
static Bool sfcre_AnalyAau(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	SFCRE_AAUHDR hdr;
	Uint8 *p;

	p = sfcre_SearchAauHdr(data, size, &hdr);
	if (p != NULL) {
		inf->atrif = NULL;
		inf->ach = sfcre_aau_ch[hdr.mode];
		inf->afreq = sfcre_aau_freq[hdr.sfreq];
		sfcre_aauhdr = hdr;
		return 1;
	}
	return 0;
}

/* header fields of a valid Sofdec file header into inf */
static void sfcre_SetSfdHdrInf(SFHDS_FHD *fhd, SFD_CREINF *inf)
{
	if (fhd->valid != 0) {
		if (fhd->byterate > 0) {
			inf->bitrate = fhd->byterate;
		}
		if (fhd->vid.picw > 0) {
			inf->picw = fhd->vid.picw;
		}
		if (fhd->vid.pich > 0) {
			inf->pich = fhd->vid.pich;
		}
		if (fhd->vid.picrate > 0) {
			inf->picrate = fhd->vid.picrate;
			inf->vtrif = &SFD_tr_vd_mpv;
		}
	}
}

/* the Sofdec file header packet in the first four packs. The search loop and the header copy are
 * one helper inlined straight from sfcre_AnalyMps: MWCC inlines breadth-first, so this helper's
 * locals (i, ps, fhd, len) are numbered before the nested pack-start searches of sfcre_AnalyPackSiz
 * and are coloured before their temporaries (i r27, ps r28, p r29, n r30; fhd r28, len r27). The
 * field stores are a further helper so the body stays under the auto-inline size. */
static void sfcre_AnalySfdHdr(Uint8 *p, Sint32 n, SFD_CREINF *inf)
{
	Sint32 ps;
	Sint32 i;
	SFHDS_FHD *fhd;
	Sint32 len;

	i = 0;
	ps = inf->packsiz;
	for (;;) {
		if (SFHDS_IsSfdHeader(p, n)) {
			break;
		}
		p += ps;
		n -= ps;
		if (i >= 3) {
			return;
		}
		if (n <= 0) {
			return;
		}
		i++;
	}
	fhd = &sfcre_fhd;
	fhd->valid = 0;
	len = SFHDS_RAW_SIZE;
	if (n < SFHDS_RAW_SIZE) {
		len = n;
	}
	MEM_Copy(fhd->raw, p, len);
	fhd->rawsiz = len;
	SFHDS_ProcessHdr(fhd);
	sfcre_SetSfdHdrInf(fhd, inf);
}

/* mux_rate from the pack header of the first pack (a helper so that mps is numbered after the
 * three pack-start searches: r22 after p3) */
// FUN_005163D0
static void sfcre_MpsMuxRate(Uint8 *p, Sint32 n, Sint32 *mux_rate)
{
	MPS mps;
	Sint32 len;
	Sint32 flags;
	MPS_PACKHD packhd;

	mps = MPS_Create();
	if (mps != NULL) {
		MPS_DecHd(mps, p, n, &len, &flags);
		if (flags & 0x10000) {
			MPS_GetPackHd(mps, &packhd);
			MPS_Destroy(mps);
			*mux_rate = packhd.mux_rate;
		}
	}
}

/* pack size from the distance of three consecutive pack start codes: 0 none, -1 irregular.
 * `p1 - data` and `size - (p1 - data)` are written as expressions: the frontend CSE temporaries
 * rank below the search pointer (p1 r30, ofs r29, n r28), where locals would rank above it. */
static Sint32 sfcre_AnalyPackSiz(Uint8 *data, Sint32 size, Sint32 *mux_rate)
{
	Uint8 *p1;
	Uint8 *p2;
	Uint8 *p3;
	Sint32 packsiz;

	p1 = sfcre_SearchDelim(data, size, 0x10000);
	if (p1 == NULL) {
		return 0;
	}
	p2 = sfcre_SearchDelim(p1 + 1, (size - (p1 - data)) - 1, 0x10000);
	if (p2 == NULL) {
		return 0;
	}
	p3 = sfcre_SearchDelim(p2 + 1, size - (p2 - data) - 1, 0x10000);
	if (p3 == NULL) {
		return 0;
	}
	packsiz = p2 - p1;
	if (packsiz != p3 - p2) {
		return -1;
	}
	if ((p1 - data) % packsiz != 0) {
		return -1;
	}
	sfcre_MpsMuxRate(p1, size - (p1 - data), mux_rate);
	return packsiz;
}

/* Byte-identical since CRI pass 60 (pure C): the `ofs + 1` temp's fresh r0 and the byte numbering
 * b4 r4, b7 r5, ofs r6, b6 r7, b5 r6 follow from the mask-then-shift test below and b7's
 * declaration/second def. */
Sint32 sfcre_AnalyMpv(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	Uint8 *p;
	Uint8 b4;
	Uint8 b7;
	Sint32 ofs;
	Uint8 b5;
	Uint8 b6;
	Uint8 b8;
	Uint8 b9;
	Uint8 b10;
	Uint8 b11;

	while (size > 0) {
		p = (Uint8 *)MPV_SearchDelim((Sint8 *)data, size, 0x40);
		if (p == NULL) {
			return 0;
		}
		b4 = p[4];
		b5 = p[5];
		b6 = p[6];
		b7 = p[7];
		b8 = p[8];
		b9 = p[9];
		b10 = p[10];
		b11 = p[11];
		ofs = p - data;
		data = (Uint8 *)((Uint32)ofs + (Uint32)data);
		data++;
		size -= ofs + 1;
		/* mask-then-shift: the codegen emits `andi` + `srwi`, peephole-forward folds them into one
		 * `rlwinm` and leaves the dead mask def in the block until the RA deletes it; that extra node
		 * delays `ofs + 1` past the compare in the pre-RA schedule (CRI pass 60). b7 stays an own
		 * local (second def below) with its vid between b4 and ofs. */
		if (((b7 & 0xF0) >> 4) == 0) {
			continue;
		}
		b7 &= 0xF;
		if (b7 < 1 || b7 > 8) {
			continue;
		}
		if (((b10 >> 5) & 1) == 0) {
			continue;
		}
		inf->picw = (b4 << 4) | ((b5 >> 4) & 0xF);
		inf->pich = ((b5 & 0xF) << 8) | b6;
		if (inf->bitrate == 0) {
			inf->bitrate = ((b8 << 10) | (b9 << 2) | ((b10 >> 6) & 3)) * 50;
		}
		inf->picrate = sfcre_mpv_picrate[b7];
		inf->vbvsiz = (((b10 & 0x1F) << 5) | ((b11 >> 3) & 0x1F)) << 11;
		inf->vtrif = &SFD_tr_vd_mpv;
		break;
	}
	return 1;
}

/* ADX header at a 4-byte phase of the data copied to the temporary buffer */
static Bool sfcre_AnalyAdxSub(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	Sint32 n;
	Uint8 *p;
	Sint32 hdrsiz;

	n = SFCRE_TMPBUF_SIZE;
	if (size < SFCRE_TMPBUF_SIZE) {
		n = size;
	}
	memcpy(sfcre_tmpbuf, data, n);
	for (p = sfcre_tmpbuf; n > 0; p += 4, n -= 4) {
		if (SFADXT_IsHeader(p, n, &hdrsiz)) {
			inf->atrif = &SFD_tr_ad_adxt;
			inf->ach = p[7];
			inf->afreq = (p[8] << 24) | (p[9] << 16) | (p[10] << 8) | p[11];
			return 1;
		}
	}
	return 0;
}

// Looks for an ADX header at the four byte alignments of the data (raw ADX audio-only file).
Sint32 sfcre_AnalyAdx(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	if (sfcre_AnalyAdxSub(data, size, inf)) {
		return 1;
	}
	if (sfcre_AnalyAdxSub(data + 2, size - 2, inf)) {
		return 1;
	}
	if (sfcre_AnalyAdxSub(data + 1, size - 1, inf)) {
		return 1;
	}
	if (sfcre_AnalyAdxSub(data + 3, size - 3, inf)) {
		return 1;
	}
	return 0;
}

/* min helper: the result local ranks above the `a` parameter, so `end - p` takes r3 and the
 * result r0 (an open-coded diamond ranks the sub temporary first) */
static Sint32 sfcre_MinLe(Sint32 a, Sint32 b)
{
	Sint32 r = b;
	if (a <= b) {
		r = a;
	}
	return r;
}

/* payload start of the packet at p: after the decoded packet header, or after the 6-byte minimum
 * when no MPS handle is available. A pointer-returning helper makes q a frontend temporary that is
 * coalesced with the inlined AAU search pointer (39 neighbours, level 2, r30 right after p). */
static Uint8 *sfcre_SkipPketHd(Uint8 *p, Uint8 *end)
{
	MPS mps;
	Sint32 n;
	Sint32 len;
	Sint32 flags;

	mps = MPS_Create();
	if (mps == NULL) {
		n = sfcre_MinLe(end - p, 6);
		return p + n;
	}
	MPS_DecHd(mps, p, end - p, &len, &flags);
	MPS_Destroy(mps);
	return p + len;
}

/* audio: the payload of the first audio packet (stream id 0xC0..0xDF). `n` holds the stream id
 * first and the packet length second: the second web is a range-split temporary that carries the
 * inlined AAU search counter (level 2, r29 shared with the search count and mps). */
void sfcre_AnalyAudio(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	Uint8 *end;
	Sint32 packsiz;
	Uint8 *p;
	Uint8 *q;
	Sint32 n;
	Sint32 ofs;

	end = data + size;
	packsiz = inf->packsiz;
	while (size > 0) {
		p = sfcre_SearchDelim(data, size, 0x40000);
		if (p == NULL) {
			return;
		}
		n = p[3];
		if ((Uint8)n >= 0xC0 && (Uint8)n <= 0xDF) {
			q = sfcre_SkipPketHd(p, end);
			n = packsiz;
			if (end - q < packsiz) {
				n = end - q;
			}
			if (sfcre_AnalyAdx(q, n, inf) != 0) {
				return;
			}
			if (sfcre_AnalyAau(q, n, inf) != 0) {
				return;
			}
		}
		ofs = p - data;
		data = (Uint8 *)((Uint32)ofs + (Uint32)data);
		data++;
		size -= ofs + 1;
	}
}

// MPEG program stream test: finds the pack size (and mux rate -> bit rate); selects the MPS system
// driver and analyses the Sofdec header, the audio and the video elementary headers inside it.
// packsiz -1 = irregular pack size (creatable but not playable here).
Sint32 sfcre_AnalyMps(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	Sint32 mux_rate = 0;
	Sint32 packsiz;

	packsiz = sfcre_AnalyPackSiz(data, size, &mux_rate);
	if (packsiz == 0) {
		return 0;
	}
	inf->packsiz = packsiz;
	if (packsiz == -1) {
		return 1;
	}
	if (mux_rate != -1 && mux_rate > 0) {
		inf->bitrate = mux_rate * 50;
	}
	inf->strif = &SFD_tr_sd_mps;
	sfcre_AnalySfdHdr(data, size, inf);
	sfcre_AnalyAudio(data, size, inf);
	sfcre_AnalyMpv(data, size, inf);
	return 1;
}

// Clears the result and tries the containers in order: program stream, raw MPEG video, raw ADX, raw
// MPEG audio.
void sfcre_AnalyCreInf(Uint8 *data, Sint32 size, SFD_CREINF *inf)
{
	memset(inf, 0, sizeof(SFD_CREINF));
	inf->creatable = 0;
	inf->avail = 0;
	inf->strif = NULL;
	inf->vtrif = NULL;
	inf->atrif = NULL;
	inf->packsiz = 0;
	inf->picw = 0;
	inf->pich = 0;
	inf->bitrate = 0;
	inf->picrate = 0;
	inf->vbvsiz = 0;
	inf->ach = 0;
	inf->afreq = 0;
	if (sfcre_AnalyMps(data, size, inf) != 0) {
		return;
	}
	if (sfcre_AnalyMpv(data, size, inf) != 0) {
		return;
	}
	if (sfcre_AnalyAdx(data, size, inf) != 0) {
		return;
	}
	if (sfcre_AnalyAau(data, size, inf) != 0) {
		return;
	}
}

// Public entry (mwPlyGetHdrInf / handle creation): analyses the file head under the lock; creatable
// = a video or audio driver was selected or the pack size is irregular, avail = a driver was selected.
// FUN_00516078
void SFD_AnalyCreInf(void *data, Sint32 size, SFD_CREINF *inf)
{
	Sint32 cs;

	SFLIB_LockCs(&cs);
	sfcre_AnalyCreInf(data, size, inf);
	if (inf->vtrif != NULL || inf->atrif != NULL || inf->packsiz == -1) {
		inf->creatable = 1;
	}
	if (inf->vtrif != NULL || inf->atrif != NULL) {
		inf->avail = 1;
	}
	SFLIB_UnlockCs(&cs);
}
