/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2001,2002 CRI-MW
 *
 * Library  : MWSFD Library (CRI Sofdec)
 * Module   : Library User's Header
 * File     : crimwsfd.h
 * Date     : 2002-09-19
 * Version  : 2.27
 *
 ****************************************************************************/
#ifndef	INCLUDED_CRIMWSFD_H		/* Re-definition prevention */
#define	INCLUDED_CRIMWSFD_H

/*	Version No.	*/
#define	MWD_SFD_VER	"2.27"

/***************************************************************************
 *      Include file
 ***************************************************************************/
#include <cri_xpt.h>
#include <sj.h>

/***************************************************************************
 *      MACRO CONSTANT
 ***************************************************************************/
/* 垂直同期周波数  */
/* Vsync frequency */
#define MWSFD_VHZ_59_94		(59.94f)
#define MWSFD_VHZ_50_00		(50.00f)
#define MWSFD_VHZ_60_00		(60.00f)

/* ファイルタイプ		*/
/* File type			*/
#define	MWSFD_FTYPE_NON			(0)
#define	MWSFD_FTYPE_SFD			(1)
#define	MWSFD_FTYPE_MPV			(2)
#define MWSFD_FTYPE_VONLYSFD	(3)

/* 合成モード		*/
/* Composition Mode	*/
#define MWSFD_COMPO_AUTO		(0x00000000)	/* 自動						*/
												/* Auto						*/
#define MWSFD_COMPO_OPAQ		(0x00000011)	/* 不透明					*/
												/* opacity					*/
#define MWSFD_COMPO_ALPHFULL	(0x00000021)	/* フルAlpha合成			*/
												/* Full Alpha				*/
#define	MWSFD_COMPO_ALPHLUMI	(0x00000031)	/* ルミナンスキー合成 		*/
												/* Luminance key alpha		*/
#define	MWSFD_COMPO_ALPH3		(0x00000041)	/* 3値アルファ 				*/
												/* 3-value alpha			*/
#define MWSFD_COMPO_Z			(0x00000101)	/* Ｚ値						*/
												/* Z value					*/

/* 同期モード	*/
/* Sync Mode	*/
#define MWSFD_SYNCMODE_NONE		(0)		/* 無同期		*/ /* No sync		*/
#define MWSFD_SYNCMODE_VSYNC	(1)		/* V-Sync同期	*/ /* Sync Vint		*/
#define MWSFD_SYNCMODE_AUDIO	(2)		/* Audio 同期	*/ /* Sync Audio	*/

/* Audio Volume MAX, MIN */
#define	MWSFD_OUTVOL_MAX		(0)		/* MAX Volume */
#define	MWSFD_OUTVOL_MIN		(-960)	/* MIN Volume */

/* Audio Channel	*/
#define MWSFD_CH_L				(0)		/* Left		*/
#define MWSFD_CH_R				(1)		/* Right	*/

/*	Panpot Value				*/
#define	MWSFD_PAN_LEFT			(-15)
#define	MWSFD_PAN_CENTER		(0)
#define	MWSFD_PAN_RIGHT			(15)
#define	MWSFD_PAN_AUTO			(-128)

/* 出力バッファ幅のデフォルト値 	*/
/* Default value of out-buffer size	*/
#define MWSFD_DFL_OUTBUFSIZE		(0)

/* フレームパラメータのバッファ最大数	*/
/* Buffer max num of frame parameter	*/
#define MWSFD_FRMPRM_BUF_MAX		(4)


/* [for Compatibility] */
#define	MWD_PLY_FTYPE_NON		MWSFD_FTYPE_NON
#define	MWD_PLY_FTYPE_SFD		MWSFD_FTYPE_SFD
#define	MWD_PLY_FTYPE_MPV		MWSFD_FTYPE_MPV
#define MWD_PLY_COMPO_OPEQ		MWSFD_COMPO_OPAQ
#define MWD_PLY_SYNC_NONE		MWSFD_SYNCMODE_NONE
#define MWD_PLY_SYNC_VSYNC		MWSFD_SYNCMODE_VSYNC
#define MWD_PLY_SYNC_AUDIO		MWSFD_SYNCMODE_AUDIO
#define MWD_CH_L				MWSFD_CH_L
#define MWD_CH_R				MWSFD_CH_R
#define	MWD_PAN_LEFT			MWSFD_PAN_LEFT
#define	MWD_PAN_CENTER			MWSFD_PAN_CENTER
#define	MWD_PAN_RIGHT			MWSFD_PAN_RIGHT
#define	MWD_PAN_AUTO			MWSFD_PAN_AUTO

/***************************************************************************
 *      Process MACRO
 ***************************************************************************/
/* Convert mwGetTime()'s return-value to second	*/
#define	MWSFD_TIME2SEC(ncount, tscale)		((ncount) / (tscale))

/* Convert mwGetTime()'s return-value to milli-second	*/
#define	MWSFD_TIME2MSEC(ncount, tscale)	((1000 * (ncount)) / (tscale))

/* [for Compatibility] */
#define	MWD_PLY_TIME2SEC(ncount, tscale)	MWSFD_TIME2SEC((ncount), (tscale))
#define	MWD_PLY_TIME2MSEC(ncount, tscale)	MWSFD_TIME2MSEC((ncount), (tscale))

/***************************************************************************
 *      Enum declaration
 ***************************************************************************/
/*	Status of MWPLY handles		*/
typedef	enum {
	MWSFD_STAT_STOP			= 0,		/*	stoped						*/
	MWSFD_STAT_PREP			= 1,		/*	preparing					*/
	MWSFD_STAT_PLAYING		= 2,		/*	playing						*/
	MWSFD_STAT_PLAYEND		= 3,		/*	end of playing				*/
	MWSFD_STAT_ERROR		= 4,		/*	error was occured			*/

	/* [for Compatibility] */
	MWE_PLY_STAT_STOP		= 0,		/*	stoped						*/
	MWE_PLY_STAT_PREP		= 1,		/*	preparing					*/
	MWE_PLY_STAT_PLAYING	= 2,		/*	playing						*/
	MWE_PLY_STAT_PLAYEND	= 3,		/*	end of playing				*/
	MWE_PLY_STAT_ERROR		= 4,		/*	error was occured			*/

	MWSFD_STAT_END
} MwsfdStat, MWE_PLY_STAT;

/* デコードサーバ */
/* Decode Server  */
typedef enum {
	MWSFD_DEC_SVR_IDLE		= 0,	/* メインの余り時間でデコードする。 */
									/* Decode in idel thread            */
	MWSFD_DEC_SVR_MAIN		= 1,	/* メイン処理内でデコードする。		*/
									/* Decode in main thread            */

	MWSFD_DEC_SVR_END
} MwsfdDecSvr;

/* デコード結果バッファデータ形式	*/
/* Decoder's output buffer data format	*/
typedef enum {
    MWSFD_BUFFMT_DEFAULT		= 0,	/* Default format		*/
    MWSFD_BUFFMT_MB_YCC420		= 1,	/* YCC 4:2:0 Macroblock */
    MWSFD_BUFFMT_MB_ARGB8888	= 2,	/* RGB 32bit Macroblock */
    MWSFD_BUFFMT_PLN_YCC420		= 3,	/* YCC 4:2:0 Plane      */
	/* [for Compatibility] */
    MWE_PLY_BUFFMT_MB_YCC420    = 1,	/* YCC 4:2:0 Macroblock */
    MWE_PLY_BUFFMT_MB_ARGB8888  = 2,	/* RGB 32bit Macroblock */
    MWE_PLY_BUFFMT_PLN_YCC420   = 3,	/* YCC 4:2:0 Plane      */
    MWSFD_BUFFMT_END
} MwsfdBufFmt, MWE_PLY_BUFFMT;

/* ピクチャタイプ	*/
/* Picture type		*/
typedef enum {
    MWSFD_PTYPE_I			= 1,	/* I Picture */
    MWSFD_PTYPE_P			= 2,	/* P Picture */
    MWSFD_PTYPE_B			= 3,	/* B Picture */
    MWSFD_PTYPE_D			= 4,	/* D Picture */
	/* [for Compatibility] */
    MWE_PLY_PTYPE_I			= 1,	/* I Picture */
    MWE_PLY_PTYPE_P			= 2,	/* P Picture */
    MWE_PLY_PTYPE_B			= 3,	/* B Picture */
    MWE_PLY_PTYPE_D			= 4,	/* D Picture */
    MWSFD_PTYPE_END
} MwsfdPtype, MWE_PLY_PTYPE;

/* フレーム取得同期モード			*/
/* Sync mode of mwPlyGetCurFrm()	*/
typedef enum {
	MWSFD_FRMSYNC_TIME		= 0,	/* Sync with time	*/
	MWSFD_FRMSYNC_NONE		= 1,	/* No sync			*/

	MWSFD_FRMSYNC_END
} MwsfdFrmSync;

/* ルミナンス合成の透過キー				*/
/* Luminance alpha's transparence key	*/
typedef enum {
	MWSFD_LUMIKEY_BLACK		= 0,	/* Black key transparence */
	MWSFD_LUMIKEY_WHITE		= 1,	/* White key transparence */

	MWSFD_LUMIKEY_END
} MwsfdLumiKey;

/* フレームフォーマット	*/
/* Frame Format			*/
typedef enum {
	MWSFD_FRMFMT_I_YCC420PLN	= 1, 	/* YCC420 Plane	*/

	MWSFD_FRMFMT_O_ARGB8888		= 101,	/* ARGB8888 	*/
	MWSFD_FRMFMT_O_YCC422		= 102,	/* YCC422 		*/
	MWSFD_FRMFMT_O_Y84C44		= 103,	/* Y8x4, C4x4	*/

    MWSFD_FRMFMT_END
} MwsfdFrmFmt;

/***************************************************************************
 *      Data type declaration
 ***************************************************************************/
/*	MWPLY handle	*/
#ifndef MWPLY_DEFINED
#define MWPLY_DEFINED

/*	Virtual function table	*/
typedef struct {
	struct MwsfdIf *vtbl;
} MW_PLY_OBJ;
typedef MW_PLY_OBJ *MWPLY;
#endif

/*	MWPLY Interface function  	*/
typedef struct MwsfdIf{
	void (*QueryInterface)();		/*	for COM compatibility	*/
	void (*AddRef)();				/*	for COM compatibility	*/
	void (*Release)();				/*	for COM compatibility	*/
	/*== Functions of MWPLY	====================================*/ 
	/*	V-sync function 										*/
	/*	This function is called by user while v-sync interrupt.	*/
	void (*VsyncHndl)(MWPLY mwply);
	/*	execute decoding one frame								*/
	/*	This function is called by user from main-loop.			*/ 
	Bool (*ExecSvrHndl)(MWPLY mwply);
	/*	destroy MWPLY handle									*/
	void (*Destroy)(MWPLY mwply);
	/*	start playback by file name 							*/
	void (*StartFname)(MWPLY mwply, Char8 *fname);
	/*	stop playback  											*/
	void (*Stop)(MWPLY mwply);
	/*	get status of MWPLY handle								*/
	MwsfdStat (*GetStat)(MWPLY mwply);
	/*	get playing time										*/
	/*	if playing movie is 30 fps, *tscale is 30 and 			*/
	/*		*ncount is total number of displayed frames			*/ 
	void (*GetTime)(MWPLY mwply, Sint32 *ncount, Sint32 *tscale);
	/*	Set pause switch.  sw=0(Continue), 1(Pause)				*/
	void (*Pause)(MWPLY mwply, Sint32 sw);
	/*	Set Output Volume (vol= 0 to -960)						*/
	void (*SetOutVol)(MWPLY mwply, Sint32 vol);
	/*	Get Output Volume (return value= 0 to -960)				*/
	Sint32 (*GetOutVol)(MWPLY mwply);
	/*	Set output panpot chno=0(Mono/Left),1(Right)			*/
	/*	pan = +15(Right),0(Center),-15(Left),-128(Auto)			*/
	void (*SetOutPan)(MWPLY mwply, Sint32 chno, Sint32 pan);
	/*	Get output panpot chno=0(Mono/Left),1(Right)			*/
	Sint32 (*GetOutPan)(MWPLY mwply, Sint32 chno);
	/*	start playing by stream joint							*/
	void (*StartSj)(MWPLY mwply, SJ sji);
	/*	start playing by memory									*/
	void (*StartMem)(MWPLY mwply, void *addr, Sint32 len);
} MwsfdIf;

/* Sofdecの初期化パラメータ構造体							*/
/* Parameter structure of Sofdec initialization function	*/
typedef struct {
	Float32		vhz;			/* 垂直同期周波数[Hz]						*/
								/* Vsync frequency[Hz]						*/
	Sint32		disp_cycle;		/* 表示更新周期[v]				 			*/
								/* Display update cycle[v]					*/
	Sint32		disp_latency;	/* 表示レイテンシ[v]						*/
								/* Display latency[v]						*/
	MwsfdDecSvr	dec_svr;		/* デコードサーバ				 			*/
								/* Decode Server							*/
	Sint32		rsv[4];			/* 予約 (全て0を設定して下さい) 			*/
								/* Reserved(Please set 0 in all of area)	*/
} MwsfdInitPrm, MWS_PLY_INIT_SFD;

/* ハンドル生成パラメータ構造体				*/
/* Parameter structure of handle creation	*/
typedef struct {
	Sint32	ftype;				/* 再生するストリームの種別 				*/
								/* File type								*/
	Sint32	max_bps;			/* 最大のビットストリーム量　(bit/sec)		*/
								/* Maximum number of bit per second			*/
	Sint32	max_width;			/* 再生画像サイズの最大幅					*/
								/* Maximum width of video stream			*/
	Sint32	max_height;			/* 再生画像サイズの最大高さ					*/
								/* Maximum height of video stream			*/
	Sint32	nfrm_pool_wk;		/* システム領域のフレームプール数（通常3)	*/
								/* フレーム落ちが発生した場合は、この値を	*/
								/* 増やしてください。						*/
								/* Number of frame pools in system memory.	*/
								/* Normaly this number is 3. If frame is 	*/
								/* droped,you have to increase this number.*/
	Sint32	max_stm;			/* 同時読み込みストリーム数(ADX含む)		*/
								/* 値が0の場合はデフォルト値(1)とみなす。	*/
								/* The number of maximum streams playing 	*/
								/* at the same time. 						*/
								/* This number include ADXT/ADXF streams.	*/
								/* If the value is zero then assume 1.		*/
	Sint8	*work;				/* ワーク領域								*/
								/* Address of working area					*/
	Sint32	wksize;				/* ワーク領域サイズ							*/
								/* Size of working area						*/
	Sint32  compo_mode;			/* 合成モード								*/
								/* Composition mode							*/
	MwsfdBufFmt		buffmt;		/* デコード出力フレームバッファデータ形式	*/
								/* 値が0の場合はデフォルト形式とみなす。	*/
								/* Buffer format of decoder	output			*/
								/* If the value is 0 then assume defualt.	*/
	Sint32	rsv[2];				/* 予約 (全て0を設定して下さい) 			*/
								/* Reserved(Please set 0 in all of area)	*/
} MwsfdCrePrm, MWS_PLY_CPRM_SFD;

/* フレーム情報構造体 */
/* Frame Information  */
typedef struct {
	Uint8			*bufadr;			/* デコード結果バッファアドレス		*/
										/* Decoder's output buffer address	*/
	MwsfdBufFmt		buffmt;				/* デコード結果バッファデータ形式	*/
										/* Decoder's output buffer format	*/
	Sint32			width;				/* 横ピクセル数						*/
										/* Width by the pixel				*/
	Sint32			height;				/* 縦ピクセル数						*/
										/* Height by the pixel				*/
	Sint32			x_mb;				/* 横マクロブロック数				*/
										/* Width by the macroblock			*/
	Sint32			y_mb;				/* 縦マクロブロック数				*/
										/* Height by the macroblock			*/
	MwsfdPtype		ptype;				/* ピクチャタイプ					*/
										/* Picture type						*/
	Sint32			fps;				/* フレームレート[fps * 1000]		*/
										/* Frame rate [fps * 1000]			*/
	Sint32			fno;				/* フレーム番号						*/
										/* Count of frames					*/
	Sint32			time;				/* 表示時刻							*/
										/* Time of disp						*/
	Sint32			tunit;				/* 表示時刻単位						*/
										/* Unit of display time				*/
	Sint32			concat_cnt;			/* 連結処理回数						*/
										/* Count of concatenation			*/
	Sint32			fno_per_file;		/* ファイル毎のフレーム番号			*/
										/* Count of frames per file			*/
	Sint32			time_per_file;		/* ファイル毎の再生時刻				*/
										/* Playtime per file				*/
	Sint32			errcnt;				/* データエラー発生回数				*/
										/* Count of data error				*/
	Sint32			rcvcnt;				/* データエラー回復回数				*/
										/* Count of error recovery			*/
} MwsfdFrmObj, MWS_PLY_FRM;

/* 再生情報構造体 		*/
/* Playback information	*/
typedef struct {
	Sint32	drop_frm_cnt;		/* Count of drop frame 						*/
	Sint32	skip_dec_cnt;		/* Count of skip decode						*/
	Sint32	skip_disp_cnt;		/* Count of skip frame was not obtatined	*/
	Sint32	skip_emptyb_cnt;	/* Count of skip empty-Bpicture 			*/
	Sint32	no_supply_cnt;		/* Count of data supply shortage			*/
} MwsfdPlyInf;

/* ファイルヘッダ情報		*/
/* File header information	*/
typedef struct {
	Bool		playable;		/* TRUE: playable, FALSE: not playable	*/
	Sint32		ftype;			/* File type (MWSFD_FTYPE_ )			*/
	Sint32		width;			/* Width by the pixel					*/
	Sint32		height;			/* Height by the pixel					*/
	Sint32		fps;			/* Frame rate [fps * 1000]				*/
	Sint32		a_sfreq;		/* Audio: sampling freqency 			*/
	Sint32		a_nch;			/* Audio: number of channel 			*/
	Sint32		frmnum;			/* Total video frames					*/
} MwsfdHdrInf;

/* YCbCrプレーン情報構造体 */
/* YCbCr Plane Information */
typedef struct {
	Uint8 		*y_ptr;		/* Y  Buffer Pointer */
	Uint8 		*cb_ptr;	/* Cb Buffer Pointer */
	Uint8 		*cr_ptr;	/* Cr Buffer Pointer */
	Sint32		y_width;	/* Y  Buffer width   */
	Sint32		cb_width;	/* Cb Buffer width   */
	Sint32		cr_width;	/* Cr Buffer width   */
} MwsfdYccPlane, MWS_PLY_YCC_PLANE;

/* フレームパラメータ構造体		*/
/* Frame Parameter structure 	*/
typedef struct {
	MwsfdFrmFmt	frmfmt;						/* Frame format		*/
	Sint32		width;						/* Buffer width 	*/
	Sint32		height;						/* Buffer height 	*/
	Sint32		rsv;						/* Reserved			*/
	Uint8		*buf[MWSFD_FRMPRM_BUF_MAX];	/* Buffer address 	*/
} MwsfdFrmPrm;

/*	Malloc Function	*/
typedef void *(*MwsfdMallocFn)(void *obj, Uint32 size);

/*	Free Function	*/
typedef void (*MwsfdFreeFn)(void *obj, void *ptr);

/***************************************************************************
 *      Function Declaration
 ***************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=========================================================================*
 *		基本再生処理
 *      Basic functions
 *=========================================================================*/
/* MWSFD(Sofdec)ライブラリの初期化	*/
/* Initialization of Sofdec library	*/
void mwPlyInitSfdFx(MwsfdInitPrm *iprm);

/* MWSFD(Sofdec)ライブラリの終了	*/
/* Termination of Sofdec library 	*/
void mwPlyFinishSfdFx(void);

/* 作業領域サイズの計算										*/
/* Calculation of working area size from create parameter	*/
Sint32 mwPlyCalcWorkCprmSfd(MwsfdCrePrm *cprm);

/* MWSFDハンドルの生成				*/
/* Create MWPLY handle for Sofdec	*/
MWPLY mwPlyCreateSofdec(MwsfdCrePrm *cprm);

/* 再生ハンドルの消去						*/
/* Destroy MWPLY handle						*/
/* [MwsfdIf] void mwPlyDestroy(MWPLY mwply); */
#define mwPlyDestroy(mwply)		(*(mwply)->vtbl->Destroy)((mwply))

/* 再生開始（ファイルからの再生）								*/
/* Start playing by file name 									*/
/* [MwsfdIf] void mwPlyStartFname(MWPLY mwply, Char8 *fname);	*/
#define mwPlyStartFname(mwply, fname)	(*(mwply)->vtbl->StartFname)((mwply), (fname))

/* 再生停止									*/
/* Stop playing  							*/
/* [MwsfdIf] void mwPlyStop(MWPLY mwply);	*/
#define mwPlyStop(mwply)	(*(mwply)->vtbl->Stop)((mwply))

/* ポーズ／ポーズ解除									*/
/* Set pause switch.  sw=0(Continue), 1(Pause)			*/
/* [MwsfdIf] void mwPlyPause(MWPLY mwply, Sint32 sw);	*/
#define	mwPlyPause(mwply, sw)	(*(mwply)->vtbl->Pause)((mwply), (sw))

/* ハンドル状態の取得								*/
/* Get status of MWPLY handle						*/
/* [MwsfdIf] MwsfdStat mwPlyGetStat(MWPLY mwply);	*/
#define mwPlyGetStat(mwply)		(*(mwply)->vtbl->GetStat)((mwply))

/* 再生サンプル数の取得														*/
/* Get playing time															*/
/* If playing movie is 30 fps, *tscale is 30 and *ncount is total number of */
/*  displayed frames														*/
/* [MwsfdIf] void mwPlyGetTime(MWPLY mwply, Sint32 *ncount, Sint32 *tscale);	*/
#define mwPlyGetTime(mwply, ncount, tscale)	\
							(*(mwply)->vtbl->GetTime)((mwply), (ncount), (tscale))

/* フレームの取得           */
/* Get frame buffer pointer */
void mwPlyGetCurFrm(MWPLY mwply, MwsfdFrmObj *frm);

/* フレームの解放 			*/
/* Release frame buffer		*/
void mwPlyRelCurFrm(MWPLY mwply);

/* アイドルスレッドへの切替 	*/
/* Switch to Idle Thread 		*/
void mwPlySwitchToIdle(void);

/*=========================================================================*
 *		オーディオ設定
 *      Set audio option
 *=========================================================================*/
/* オーディオストリームチャネルの設定	*/
/* Set audio stream channel 			*/
void mwPlySetAudioCh(MWPLY mwply, Sint32 ch);

/* 音声出力スイッチの設定			*/
/* Set audio output switch			*/
void mwPlySetAudioSw(MWPLY mwply, Sint32 sw);

/* オーディオ出力ボリュームの設定							*/
/* Set Output Volume (vol= 0 to -960)						*/
/* [MwsfdIf] void mwPlySetOutVol(MWPLY mwply, Sint32 vol);	*/
#define mwPlySetOutVol(mwply, vol)		(*(mwply)->vtbl->SetOutVol)((mwply), (vol))

/* オーディオ出力ボリュームの取得				*/
/* Get Output Volume (return value= 0 to -960)	*/
/* [MwsfdIf] Sint32 mwPlyGetOutVol(MWPLY mwply);	*/
#define mwPlyGetOutVol(mwply)			(*(mwply)->vtbl->GetOutVol)((mwply))

/* オーディオ出力パンポットの設定										*/
/* Set output panpot c=0(Mono/Left),1(Right)							*/
/* p = +15(Right),0(Center),-15(Left),-128(Auto)						*/
/* [MwsfdIf] void mwPlySetOutPan(MWPLY mwply, Sint32 chno, Sint32 pan);	*/
#define mwPlySetOutPan(mwply, c, p)		(*(mwply)->vtbl->SetOutPan)((mwply), (c), (p))

/* オーディオ出力パンポットの取得								*/
/* Get output panpot c=0(Mono/Left),1(Right)					*/
/* [MwsfdIf] Sint32 mwPlyGetOutPan(MWPLY mwply, Sint32 chno);	*/
#define mwPlyGetOutPan(mwply, c)		(*(mwply)->vtbl->GetOutPan)((mwply), (c))

/*=========================================================================*
 *		情報取得
 *		Information
 *=========================================================================*/
/* 総フレーム数の取得 				*/
/* Get the number of movie frame	*/
Sint32 mwPlyGetTotalFrmNum(MWPLY mwply);

/* 次フレーム取得可能問い合わせ				*/
/* Determine whether next frame is ready	*/
Bool mwPlyIsNextFrmReady(MWPLY mwply);

/* 同期モードの取得			*/
/* Get synchronization mode	*/
Sint32 mwPlyGetSyncMode(MWPLY mwply);

/* フレーム取得同期モードの取得				*/
/* Get frame obtain synchronization mode	*/
MwsfdFrmSync mwPlyGetFrmSync(MWPLY mwply);

/* ポーズ状態の取得 */
/* Get pause ON/OFF	*/
Bool mwPlyIsPause(MWPLY mwply);

/* 再生情報の取得 			*/
/* Get playback information	*/
void mwPlyGetPlyInf(MWPLY mwply, MwsfdPlyInf *plyinf);

/* コマ落ちしたフレーム数の取得	*/
/* Get number of droped frame	*/
Sint32 mwPlyGetNumDropFrm(MWPLY mwply);

/* デコード落ちしたフレーム数の取得				*/
/* Get number of frames was skipped to decode	*/
Sint32 mwPlyGetNumSkipDec(MWPLY mwply);

/* 表示段のスキップ回数の取得					*/
/* Get number of frames was skipped to obtain	*/
Sint32 mwPlyGetNumSkipDisp(MWPLY mwply);

/* スキップしたエンプティBピクチャ枚数の取得	*/
/* Get the number of skipped empty-B picture	*/
Sint32 mwPlyGetNumSkipEmptyB(MWPLY mwply);

/* デコードした全ピクチャ数の取得	*/
/* Get Number of Decoded Frames 	*/
Sint32 mwPlyGetNumTotalDec(MWPLY mwply);

/* デコード済み保持フレーム数の取得	*/
/* Get Number of Pooled Frames 		*/
Sint32 mwPlyGetNumDecPool(MWPLY mwply);

/* サーバ区切り問い合わせ							*/
/* Determine whether process is in server border	*/
Bool mwPlyIsSvrBdr(void);

/* ファイル情報の取得			*/
/* Get file header information	*/
void mwPlyGetHdrInf(Sint8 *buf, Sint32 bsize, MwsfdHdrInf *hdrinf);

/* オーディオストリームチャネル数の取得		*/
/* Get the number of audio channel streams	*/
Sint32 mwPlyGetNumAudioCh(MWPLY mwply);

/* ビデオストリームチャネル数の取得			*/
/* Get the number of video channel streams	*/
Sint32 mwPlyGetNumVideoCh(MWPLY mwply);

/*=========================================================================*
 *		追加設定
 *		Additional setting
 *=========================================================================*/
/* 同期モードの設定			*/
/* Set synchronization mode	*/
void mwPlySetSyncMode(MWPLY mwply, Sint32 mode);

/* フレーム取得同期モードの設定				*/
/* Set frame obtain synchronization mode	*/
void mwPlySetFrmSync(MWPLY mwply, MwsfdFrmSync frmsync);

/* B-Pictureデコードのスキップ設定 	*/
/* Set B-Picture skip decode 		*/
void mwPlySetBpicSkip(MWPLY mwply, Bool sw);

/* エンプティBピクチャのデコードスキップ設定 	*/
/* Set empty-B picture skip decode				*/
void mwPlySetEmptyBpicSkip(MWPLY mwply, Bool sw);

/* 再生時間上限の設定（デフォルトは 9時間57分 0秒）			*/
/* Set playback limit time (default = 09-57-00(HH-MM-SS))	*/
void mwPlySetLimitTime(MWPLY mwply, Sint32 sec);

/* ビデオストリームチャネルの設定	*/
/* Set video stream channel 		*/
void mwPlySetVideoCh(MWPLY mwply, Sint32 ch);

/*=========================================================================*
 *		シームレスループ再生
 *      Seamless loop playback
 *=========================================================================*/
/* シームレスループ再生の開始	*/
/* Start semaless loop playback	*/
void mwPlyStartFnameLp(MWPLY mwply, Char8 *fname);

/* シームレスループ再生の解除		*/
/* Release semaless loop playback	*/
void mwPlyReleaseLp(MWPLY mwply);

/* FID 指定によるシームレスループ再生の開始	  			*/
/* Start semaless loop playback by specified file ID	*/
void mwPlyStartAfsLp(MWPLY mwply, Sint32 patid, Sint32 fid);

/*=========================================================================*
 *		シームレス連続再生
 *      Seamless continuous playback
 *=========================================================================*/
/* シームレス連続再生ファイルの登録				*/
/* Entry file of Seamless continuous playback	*/
void mwPlyEntryFname(MWPLY mwply, Char8 *fname);

/* シームレス連続再生の開始				*/
/* Start seamless continuous playback	*/
void mwPlyStartSeamless(MWPLY mwply);

/* シームレス連続再生の解除				*/
/* Release seamless continuous playback	*/
void mwPlyReleaseSeamless(MWPLY mwply);

/*	シームレスループ再生の設定	*/
/*	Set semaless loop play   	*/
void mwPlySetSeamlessLp(MWPLY mwply, Sint32 flg);

/* シームレス連続再生ファイルの登録 (AFS)			*/
/* Entry file of Seamless continuous playback (AFS)	*/
void mwPlyEntryAfs(MWPLY mwply, Sint32 patid, Sint32 fid);

/* 現在登録されているファイル数の取得			*/
/* Get number of file entried seamless loop 	*/
Sint32 mwPlyGetNumSlFiles(MWPLY mwply);

/* シームレス連続再生に登録してあるファイル名の取得	*/
/* Get file name of entried seamless				*/
Char8 *mwPlyGetSlFname(MWPLY mwply, Sint32 stm_no);

/*=========================================================================*
 *		その他の再生処理
 *      Other playback functions
 *=========================================================================*/
/* FID 指定による再生の開始 				*/
/* Start AFS palyback by specified file ID	*/
void mwPlyStartAfs(MWPLY mwply, Sint32 patid, Sint32 fid);

/* SJによる再生の開始								*/
/* Start playing by stream joint					*/
/* [MwsfdIf] void mwPlyStartSj(MWPLY mwply, SJ sji);	*/
#define mwPlyStartSj(mwply, sji)     (*(mwply)->vtbl->StartSj)((mwply), (sji))

/* アドレス指定メモリによる再生開始										*/
/* Start playing by memory												*/
/* [MwsfdIf] void mwPlyStartMem(MWPLY mwply, void *addr, Sint32 len);	*/
#define	mwPlyStartMem(mwply, addr, len)		\
								   (*(mwply)->vtbl->StartMem)((mwply), (addr), (len))

/*=========================================================================*
 *		Sofdec F/X機能（フレーム変換／合成）
 *      Sofdec F/X related (Frame conversion / Composition mode)
 *=========================================================================*/
/* ARGB8888フォーマットへの変換	*/
/* Convert to ARGB8888 			*/
void mwPlyFxCnvFrmARGB8888(MWPLY mwply, MwsfdFrmObj *frm, Uint8 *out);
/* YUV422フォーマット変換	*/
/* Convert to YUV422 		*/
void mwPlyFxCnvFrmYUV422(MWPLY mwply, MwsfdFrmObj *frm, Uint8 *out);
/* Y84C44フォーマット変換	*/
/* Convert to Y84C44 		*/
void mwPlyFxCnvFrmY84C44(MWPLY mwply, MwsfdFrmObj *frm, Uint8 *yout, Uint8 *cout);

/* 出力バッファサイズの設定 */
/* Set size of out buffer 	*/
void mwPlyFxSetOutBufSize(MWPLY mwply, Sint32 width, Sint32 height);
/* 出力バッファサイズの取得 */
/* Get size of out buffer 	*/
void mwPlyFxGetOutBufSize(MWPLY mwply, Sint32 *width, Sint32 *height);

/* 合成モードの設定 	*/
/* Set composition mode	*/
void mwPlyFxSetCompoMode(MWPLY mwply, Sint32 mode);
/* 合成モードの取得 */
/* Get composition mode	*/
Sint32 mwPlyFxGetCompoMode(MWPLY mwply);

/* ルミナンスキーパラメータの設定		*/
/* Set luminance key alpha parameter	*/
void mwPlyFxSetLumiPrm(MWPLY mwply, Sint32 in_th, Sint32 out_th, MwsfdLumiKey key);
/* ルミナンスキーパラメータの取得 		*/
/* Get luminance key alpha parameter	*/
void mwPlyFxGetLumiPrm(MWPLY mwply, Sint32 *in_th, Sint32 *out_th, MwsfdLumiKey *key);

/* 16bit-Ｚバッファへの変換 		*/
/* Convert to 16bit depth Z-value	*/
void mwPlyFxCnvFrmZ16(MWPLY mwply, MwsfdFrmObj *frm, Uint8 *zout);
/* 32bit-Ｚバッファへの変換 					*/
/* Convert to 32bit depth Z-value	*/
void mwPlyFxCnvFrmZ32(MWPLY mwply, MwsfdFrmObj *frm, Uint8 *zout);

/* Ｚクリップの設定 */
/* Set Z-clip		*/
void mwPlyFxSetZclip(MWPLY mwply, Float32 znear, Float32 zfar);
/* Ｚクリップの取得 */
/* Get Z-clip		*/
void mwPlyFxGetZclip(MWPLY mwply, Float32 *znear, Float32 *zfar);

/*=========================================================================*
 *		その他
 *      Other functions
 *=========================================================================*/
/* YCbCrプレーンの計算        */
/* Calculation of YCbCr plane */
void mwPlyCalcYccPlane(Uint8 *bufptr, Sint32 width, Sint32 height, 
						MwsfdYccPlane *ycc);

/* ADXTハンドルの取得	*/
/* Get ADXT handle		*/
ADXT mwPlyGetAdxtHn(MWPLY mwply);

/* 入力ストリームジョイントの取得	*/
/* Get SJ of Input          		*/
SJ mwPlyGetInputSj(MWPLY mwply);

/* ビデオデコーダハンドルの取得	*/
/* Get Video decoder handle		*/
void *mwPlyGetSfdHn(MWPLY mwply);

/* Malloc／Free 関数の登録 */
void mwPlySetMallocFn(MwsfdMallocFn mallocfn, MwsfdFreeFn freefn, void *obj);

/* ハンドル毎のVsync処理 									*/
/* V-sync function 											*/
/* This function is called by user while v-sync interrupt.	*/
/* [MwsfdIf] void mwPlyVsyncHndl(MWPLY mwply);				*/
#define mwPlyVsyncHndl(mwply)			(*(mwply)->vtbl->VsyncHndl)((mwply))

/* ハンドル毎のサーバ処理 							*/
/* Execute decoding one frame						*/
/* This function is called by user from main-loop.	*/
/* [MwsfdIf] Bool mwPlyExecSvrHndl(MWPLY mwply);		*/
#define mwPlyExecSvrHndl(mwply)			(*(mwply)->vtbl->ExecSvrHndl)((mwply))

/*=========================================================================*
 *		削除されたフレーム変換関数
 *      Deleted frame conversion functions
 *-------------------------------------------------------------------------*
 *	Please use mwPlyFxCnvFrm***** functions.
 *=========================================================================*/
/*
void mwPlyInitYcc420plnToArgb8888(void);
void mwPlyCnvFrm(MwsfdFrmPrm *in, MwsfdFrmPrm *out);
void mwPlyYcc420plnToArgb8888(Uint8 *frm, Uint8 *prgb, Uint32 width, 
								Uint32 height, Uint32 pitch);
void mwPlyYcc420plnToYcc422pix2(Uint8 *frm, Uint8 *pycc, Uint32 width, 
								Uint32 height, Uint32 pitch);
 */


#ifdef __cplusplus
}
#endif

#endif	/* INCLUDED_CRIMWSFD_H */
