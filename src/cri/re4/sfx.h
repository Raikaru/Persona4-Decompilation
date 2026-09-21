/* CRI Sofdec SFX (frame conversion / effects) object layout, from the field offsets used by the
 * DOL. The matched sfx_set/sfx_cnv_to_* units carry their own partial copies of this struct. */
#ifndef CRI_SFX_H
#define CRI_SFX_H

#include "cri_xpt.h"

/* SFX_OBJ.compo: colour component layout ids */
#define SFX_COMPO_YCC420PLN 0x11
#define SFX_COMPO_YCC420PLN_UPHALF 0x21
#define SFX_COMPO_0x31 0x31
#define SFX_COMPO_0x41 0x41
#define SFX_COMPO_0x51 0x51
#define SFX_COMPO_0x61 0x61
#define SFX_COMPO_0x71 0x71
#define SFX_COMPO_0xF1 0xF1
#define SFX_COMPO_0x101 0x101
#define SFX_COMPO_0x111 0x111
#define SFX_COMPO_0x1001 0x1001

typedef struct SFXZ_OBJ SFXZ_OBJ;
typedef struct SFXA_OBJ SFXA_OBJ;

/* SFX handle (0x78 bytes, sfx_libwork.hn[]) */
typedef struct SFX_OBJ {
	Sint32 used;               /* 0x00 */
	Sint32 compo;              /* 0x04 stream component layout (0 = not read yet) */
	Sint32 fxtype;             /* 0x08 output layout (SFX_COMPO_YCC420PLN) */
	Sint32 outbuf_width;       /* 0x0C */
	Sint32 outbuf_height;      /* 0x10 */
	Sint32 unit_width;         /* 0x14 */
	Sint32 taginf_flg;         /* 0x18 */
	Sint32 tag_a;              /* 0x1C */
	Sint32 tag_b;              /* 0x20 */
	Sint32 pad24;              /* 0x24 */
	SFXZ_OBJ *sfxz;            /* 0x28 */
	Sint32 x2c;                /* 0x2C (1) */
	Sint32 x30;                /* 0x30 */
	SFXA_OBJ *sfxa;            /* 0x34 */
	void *coladj;              /* 0x38 */
	Sint32 tbl_type;           /* 0x3C type of the conversion table in buf[0] */
	Uint8 *buf[4];             /* 0x40 four 0x400-byte buffers carved from the work (buf[0] = table) */
	Sint32 pad50[2];           /* 0x50 */
	void *work;                /* 0x58 */
	Sint32 wsize;              /* 0x5C */
	Sint32 pad60[2];           /* 0x60 */
	Sint32 x68;                /* 0x68 (-1) */
	Sint32 pad6c[2];           /* 0x6C */
	Sint32 x74;                /* 0x74 */
} SFX_OBJ;

#define SFX_MAX_HN 8
#define SFX_BUF_SIZE 0x400
#define SFX_WORK_SIZE (0x3000 + 0x1F)

/* library-wide work (sfx_lib.c, 0x3E8 bytes) */
typedef struct {
	Sint32 hn_cnt;                            /* 0x00 created handles */
	Sint32 max_hn;                            /* 0x04 */
	void (*errfn)(void *obj, const Char8 *msg); /* 0x08 */
	void *errobj;                             /* 0x0C */
	Sint32 err_cnt;                           /* 0x10 */
	Sint32 ccir_fx;                           /* 0x14 */
	SFX_OBJ hn[SFX_MAX_HN];                   /* 0x18 */
	Sint32 pad3d8[4];                         /* 0x3D8 */
} SFX_LIBWORK;

extern SFX_LIBWORK sfx_libwork;
extern Sint32 sfxcnv_forcesplit;

SFXZ_OBJ *SFXZ_Create(void);
void SFXZ_Destroy(SFXZ_OBJ *sfxz);
void SFXZ_Init(void);
SFXA_OBJ *SFXA_Create(void);
void SFXA_Destroy(SFXA_OBJ *sfxa);
void SFXA_Init(void);
void SFXSUD_Init(void);
void CFT_Ycc420plnToArgb8888Init(void);
Sint32 SFX_GetFxType(SFX_OBJ *sfx);
Sint32 SFXA_IsNeedUpdateLumiTbl(SFXA_OBJ *sfxa);
void SFXA_MakeAlpLumiTbl(SFXA_OBJ *sfxa, void *src, void *tbl);
void SFXA_MakeAlp3110Tbl(SFXA_OBJ *sfxa, void *src, void *tbl);
void SFXA_MakeAlp3211Tbl(SFXA_OBJ *sfxa, void *src, void *tbl);
void SFXZ_MakeCnvZTbl(SFXZ_OBJ *sfxz, void *src, void *tbl);
void CFT_MakeArgb8888ColAdjTbl(void *tbl);
void CFT_MakeYcc422ColAdjTbl(void *tbl);

/* SFX_MakeTable table types */
#define SFX_TBL_LUMI 1
#define SFX_TBL_ALP_LUMI 2
#define SFX_TBL_ALP3110 4
#define SFX_TBL_ALP3211 5
#define SFX_TBL_Z32 0x0B
#define SFX_TBL_Z16 0x0D
#define SFX_TBL_ARGB8888_COLADJ 0x15
#define SFX_TBL_YCC422_COLADJ 0x16
#define SFX_TBL_NONE 0x64

/* one colour plane of a decoded frame */
typedef struct {
	Uint8 *buf;                /* 0x00 */
	Sint32 width;              /* 0x04 */
	Sint32 height;             /* 0x08 */
	Sint32 pitch;              /* 0x0C line stride (negative for bottom-up) */
} SFX_PLN;

/* frame description (0x88 bytes), filled by MWSFSFX_CnvFrmInfToSfx */
typedef struct {
	Sint32 frmfmt;             /* 0x00 */
	SFX_PLN pln[3];            /* 0x04 Y, Cb, Cr */
	Uint8 pad34[0x44 - 0x34];
	Sint32 width;              /* 0x44 */
	Sint32 height;             /* 0x48 */
	void *tblsrc;              /* 0x4C source data of the alpha/z conversion tables */
	Sint32 tag_a;              /* 0x50 */
	Sint32 tag_b;              /* 0x54 */
	Sint32 x58;
	Sint32 x5c;
	Sint32 pic_struct;         /* 0x60 */
	Sint32 chroma_format;      /* 0x64 */
	Sint32 x68;
	Sint32 x6c;
	Sint32 x70;
	Sint32 chromapos_h;        /* 0x74 */
	Sint32 chromapos_v;        /* 0x78 */
	Uint8 pad7c[0x88 - 0x7C];
} SFX_FRM;

/* CFT (colour format transform) planar source description */
typedef struct {
	void *y;                   /* 0x00 */
	void *cb;                  /* 0x04 */
	void *cr;                  /* 0x08 */
	Sint32 ywidth;             /* 0x0C */
	Sint32 cbwidth;            /* 0x10 */
	Sint32 crwidth;            /* 0x14 */
	Sint32 pad18[4];           /* 0x18 (frame size only) */
} CFT_YCC420PLN;

Sint32 sfxcnv_IsCnvUpHalf(SFX_OBJ *sfx);
void SFXLIB_Error(SFX_OBJ *sfx, SFX_FRM *frm, const Char8 *msg);
Sint32 SFXINF_GetStmInf(SFX_FRM *frm, const Char8 *tag);
void CFT_Ycc420plnToY84C44(const CFT_YCC420PLN *src, void *ybuf, void *cbuf, Sint32 width, Sint32 height);

#endif
