/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2001 CRI-MW
 *
 * Library : UT Library
 * Module  : Library header
 * File    : cri_ut.h
 * Date    : 2000-10-31
 *
 ****************************************************************************/

#ifndef INCLUDED_CRI_UT_H		/* Re-definition prevention */
#define INCLUDED_CRI_UT_H
/*******************************************************************
 *      Include file
 *******************************************************************/
/*--- CRI-MW header ---*/
#include	<cri_xpt.h>

#ifdef  __cplusplus
extern "C" {					/* __cplusplus */
#endif
/*******************************************************************
 *      Macro constant
 *******************************************************************/
#define CRIUT_VER	"1.24"	/* Version string */

/*--- UTPAD ---*/
#define	UTPAD_PORT1			(0)
#define	UTPAD_PORT2			(1)
#define	UTPAD_PORT3			(2)
#define	UTPAD_PORT4			(3)
#define	UTPAD_PORT_MAX		(4)
#define UTPAD_UP			(0x0001)
#define UTPAD_DOWN			(0x0002)
#define UTPAD_LEFT			(0x0004)
#define UTPAD_RIGHT			(0x0008)
#define UTPAD_BUTTON1		(0x0010)
#define UTPAD_BUTTON2		(0x0020)
#define UTPAD_BUTTON3		(0x0040)
#define UTPAD_BUTTON4		(0x0080)
#define UTPAD_L				(0x0100)
#define UTPAD_R				(0x0200)
#define UTPAD_START			(0x0400)

/*--- UTSPR ---*/
/* バッファサイズ取得マクロ */
#define UTSPR_CALCBUFSIZE(max_id)		(sizeof(UTSPR)*(max_id))

/*******************************************************************
 *      Enumarate constant
 *******************************************************************/

/*******************************************************************
 *      Process macro
 *******************************************************************/

/*******************************************************************
 *      Data type declaration
 *******************************************************************/
/*--- UTPAD ---*/
/* Peripheral Data type declaration */
typedef struct { 
	Uint32	on;
	Uint32	press;
	Float32	x;
	Float32	y;
	Uint32	last_on;
} UTPAD_PERIPHERAL;

/*--- UTSPR ---*/
typedef struct {
	Sint32		width, height;
	Sint32		tex_width, tex_height;
	void		*tex;
} UTSPR;

typedef struct {
	Sint32		left;
	Sint32		top;
	Sint32		right;
	Sint32		bottom;
} UTSPRRECT;

/*******************************************************************
 *      Function macro
 *******************************************************************/

/*******************************************************************
 *      Variable declaration
 *******************************************************************/

/*******************************************************************
 *      External Function declaration
 *******************************************************************/

/*******************************************************************
 *      Function declaration
 *******************************************************************/
/*--- UTLIB ---*/
const char *UTLIB_GetVer(void);

/*--- UTPAD ---*/
void UTPAD_Init(void);
void UTPAD_Finish(void);
const UTPAD_PERIPHERAL *UTPAD_GetPeripheral(Uint32 port);

/*--- UTPRT ---*/
Bool UTPRT_Init(void *p);
void UTPRT_Finish(void);
void UTPRT_Draw(void);
void UTPRT_Clear(void);
void UTPRT_SetColor(Uint8 r, Uint8 g, Uint8 b);
void UTPRT_Print(Uint32 x, Uint32 y, const char *fmt, ...);

/*--- UTSPR ---*/
Bool UTSPR_Init(void *obj);
void UTSPR_Finish(void);
Bool UTSPR_Create(UTSPR *sprite, const char *fname);
Bool UTSPR_CreateMem(UTSPR *sprite, const void *buf, Sint32 size);
void UTSPR_Destroy(UTSPR *sprite);
void UTSPR_Draw(UTSPR *sprite, Float32 x, Float32 y, Float32 z, const UTSPRRECT *srcrect);
void UTSPR_SetBuf(void *buf, Uint32 max_id);
Bool UTSPR_LoadID(Uint32 id, const Char8 *fname);
void UTSPR_DrawID(Uint32 id, Float32 x, Float32 y, Float32 z, const UTSPRRECT *srcrect);
void UTSPR_GetSizeID(Uint32 id, Uint32 *width, Uint32 *height);

/*--- UTTMR ---*/
void UTTMR_Init(void);
void UTTMR_Finish(void);
Uint32 UTTMR_GetCount(void);
Uint32 UTTMR_DiffCount(Uint32 count1, Uint32 count2);
Uint32 UTTMR_CountToMicro(Uint32 count);

#ifdef	__cplusplus
}								/* __cplusplus */
#endif

#endif							/* Re-definition prevention */

/* end of file */
