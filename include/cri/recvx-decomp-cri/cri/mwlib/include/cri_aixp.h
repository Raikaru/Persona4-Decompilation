#ifndef	_AIXP_H_INCLUDED
#define	_AIXP_H_INCLUDED
/****************************************************************************/
/*																			*/
/*			$title$  AIX 再生 ライブラリ									*/
/*																			*/
/*				2001.7.29		written M.Oshimi							*/
/*																			*/
/****************************************************************************/

/*	Version number of AIXP library 		*/
#define	AIXP_VER	"1.29"

#include "cri_xpt.h"
#include "sj.h"
#include "cri_adxt.h"

/*	ストリームコントローラ				*/
/*	Stream Controller					*/
#ifndef ADXSTM_DEFINED
#define ADXSTM_DEFINED
typedef	void	*ADXSTM;
#endif

/*	ストリームジョイントデコーダ		*/
/*	Stream Joint decoder				*/
#ifndef AIXSJD_DEFINED
#define AIXSJD_DEFINED
typedef void	*AIXSJD;
#endif

/*	オーディオレンダラ					*/
/*	Audio Renderer						*/
#ifndef ADXRNA_DEFINED
#define ADXRNA_DEFINED
typedef void	*ADXRNA;
#endif

/****************************************************************************/
/*		定数マクロ															*/
/*		MACRO CONSTANT														*/
/****************************************************************************/

/*	最大同時発音数						*/
/*	Maximum number of AIXP handle		*/
#define	AIXP_MAX_OBJ		(4)

/*	最大トラック数						*/
/*	Maximum number of AIXP handle		*/
#define	AIXP_MAX_TR			(32)

/*	最大フレーズ数						*/
/*	Maximum number of AIXP handle		*/
#define	AIXP_MAX_PH			(32)

/*	最大サンプリング周波数				*/
/*	Maximum sampling frequency			*/
#define	AIXP_MAX_SFREQ	(48000)

/*	$define$ AIX Talkの動作状態(AIXP_STAT_～)	*/
/*	Status of AIX Talk							*/
#define	AIXP_STAT_STOP		(0)		/*	停止中 								*/
									/*	During standstill					*/
#define AIXP_STAT_PREP		(1)		/*	再生準備中 							*/
									/*	During play preparation				*/
#define AIXP_STAT_PLAYING	(2)		/*	デコード＆再生中 					*/
									/*	During decode and play				*/
#define AIXP_STAT_PLAYEND	(3)		/*	再生終了 							*/
									/*	Play end							*/
#define AIXP_STAT_ERROR		(4)		/*	再生終了 							*/
									/*	Play end							*/

/*	最大再生チャンネル数				*/
/*	Maximum number of play channel		*/
#define	AIXP_MAX_NCH		(2)

/*	サーバ関数の呼び出される頻度の規定値　60（回/秒）				*/
/*	Default value of frequency called server function(times/sec)	*/
#define AIXP_DEF_SVRFREQ	(60)

/*	Default value of output volume(dB)	*/
#define	AIXP_DEF_OUTVOL		(0)

#define AIXP_CALC_WORK(nch, nstm, sfreq, ntr)	\
	((ADXT_CALC_IBUFSIZE(nch, nstm, sfreq) + ADXT_CALC_OBUFSIZE(nch)) * (ntr) + 64)

/*	入力バッファのエキストラ領域の大きさ	*/
/*	Size of Extra area in input buffer		*/
#define AIXP_IBUF_XLEN (8*1024)

/*	AIX Talk の出力バッファの大きさ　（サンプル単位）	*/
/*	Output buffer size of AIX Talk (unit:sample)		*/
#define	AIXP_OBUF_SIZE	(0x2000)
#define DECODE_AHX
#ifdef DECODE_AHX
#define	AIXP_OBUF_DIST	(0x2060)
#else
#define	AIXP_OBUF_DIST	(0x2020)
#endif

/*	入力バッファへの読み込み量						*/
/*	Number of sectors to read into the input buffer	*/
#define AIXP_MAX_CDBSCT		(75)
#define AIXP_MIN_CDBSCT		(65)
#define AIXP_PREP_RDSCT		(25)

/*	パンポットの設定値		*/
/*	Panpot parameter		*/
#define	AIXP_PAN_LEFT		(-15)
#define	AIXP_PAN_CENTER		(0)
#define	AIXP_PAN_RIGHT		(15)
#define	AIXP_PAN_AUTO		(-128)	/*	MONO/STE によって自動的に切り替える	*/
									/*	Changes automatically by data		*/

/*	ステレオ再生時のチャンネル番号		*/
/*	Channel number playing stereo data	*/
/*	AIXP_CH_L:left, AIXP_CH_R:right		*/
#define	AIXP_CH_L			(0)
#define	AIXP_CH_R			(1)

/*	5.1ch再生時のスピーカ番号			*/
/*	Speaker number playing 5.1ch sound	*/
#define	AIXP_SPKID_FL		(0)		/* Front Left   */
#define	AIXP_SPKID_FR		(1)		/* Front Right  */
#define	AIXP_SPKID_BL		(2)		/* Back Left    */
#define	AIXP_SPKID_BR		(3)		/* Back Right   */
#define	AIXP_SPKID_FC		(4)		/* Front Center */
#define	AIXP_SPKID_LF		(5)		/* Low Freqency */
#define	AIXP_SPK_NUM		(6)
#define	AIXP_SPK_VOL_MAX	(0)
#define	AIXP_SPK_VOL_MIN	(-10000)

/****************************************************************************/
/*		データ型															*/
/*      Data type declaration												*/
/****************************************************************************/

/*	AIX Talk オブジェクト構造体		*/
/*	Structure of AIX Talk object	*/
typedef	struct _aix_ply {
	Sint8	used;						/*	使用中か否か					*/
	Sint8	stat;						/*	動作状態						*/
	Sint8	maxnch;						/*	最大再生チャンネル数			*/
	Sint8	maxntr;						/*	最大再生トラック数			*/
	AIXSJD	sjd;						/*	AIXストリームジョイントデコーダ	*/
	ADXSTM	stm;						/*	入力ストリームコントローラ		*/
	ADXT	adxt[AIXP_MAX_TR];			/*	ADXT再生器						*/
	SJ		sji;						/*	入力ストリームジョイント		*/
	SJ		sjo[AIXP_MAX_TR];			/*	出力ストリームジョイント		*/
	Sint8	*ibuf;						/*	入力バッファ					*/
	Sint32	ibufbsize;					/*	入力バッファサイズ（バイト単位)	*/
	Sint32	ibufxsize;					/*	入力バッファエクストラサイズ	*/
	Sint8	*obuf[AIXP_MAX_TR];			/*	出力バッファ					*/
	Sint32	obufbsize;					/*	出力バッファサイズ（バイト単位）*/
	Sint32	obufxsize;					/*	出力バッファサイズ（バイト単位）*/
	Sint32	pause_flag;					/*	ポーズフラグ					*/
	Sint8	lpsw;						/*	ループスイッチ					*/
	Sint8	lnksw;						/*	連結スイッチ					*/
	Sint16	rsv;						/*	ループスイッチ					*/
	Sint32	lpcnt;						/*	ループカウンタ					*/
	Sint32	curph;						/*	現在際背中のフレーズ番号		*/
	Sint32	stph;						/*	再生開始フレーズ番号			*/
	Sint32	lpsp;						/*	ループスタートフレーズ番号		*/
	Sint32	lpep;						/*	ループエンドフレーズ番号		*/
#ifdef	XPT_TGT_XB	/* M.W: 2001-09-01: DolbyDigital 5.1ch対応 */
	Sint32	spk_idx[AIXP_SPK_NUM];
#endif
} AIX_PLY;
typedef	AIX_PLY	*AIXP;

/****************************************************************************/
/*		関数の宣言															*/
/*      Function Declaration												*/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* $func$ AIX Talk の初期化
 * [書　式] void AIXP_Init(void);
 * [入　力] なし
 * [出　力] なし
 * [関数値] なし
 * [機　能] AIX Talk を初期化する。
 *			変数領域の初期化を行う。
 *  Initialization of AIX Talk
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Initializes AIX Talk. Initializes variable.
 */
void AIXP_Init(void);

/* $func$ AIX Talkの終了
 * [書　式] void AIXP_Finish(void);
 * [入　力] なし
 * [出　力] なし
 * [関数値] なし
 * [機　能] AIX Talk の終了処理をする。
 *  Termination of AIX Talk
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Finalizes AIX Talk.
 */
void AIXP_Finish(void);

/*	$func$ AIXPハンドル の生成
 * [書　式] AIXP AIXP_Create(Sint32 maxnch, void *work, Sint32 worksize);
 * [入　力] maxntr	: 最大トラック数
 *			maxnch	: 最大再生チャンネル数（モノラルのみ１：ステレオ２）
 *			work	: ワーク領域
 *			worksize: ワーク領域のサイズ
 * [出　力] なし
 * [関数値] AIXPハンドル
 * [機　能] AIXPハンドルを生成する。
 *			work領域のサイズは、AIXP_CALC_WORKマクロによって求める。
 *  Creation of AIXP handle
 * [Inputs  ] maxntr  : Number of maximum tracks
 *			  maxnch  : Number of maximum channels(monoral:1, stereo:2)
 *			  work    : Working area
 *			  worksize: Size of working area(byte)
 * [Outputs ] None
 * [Return  ] AIXP handle
 * [Function] Creates AIXP handle.
 * [Remarks ] You calculate size of working area used 'AIXP_CALC_WORK' macro. 
 */
AIXP AIXP_Create(Sint32 maxntr, Sint32 maxnch, void *work, Sint32 worksize);

/* $func$ AIXPハンドル の消去
 * [書　式] void AIXP_Destroy(AIXP aixp);
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] なし
 * [機　能] 指定された AIXPハンドルを消去する。
 *  Destroy of AIXP handle
 * [Inputs  ] AIXP   : AIXP handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Destroys specified AIXP handle.
 */
void AIXP_Destroy(AIXP aixp);

/* $func$ ファイル名指定による再生の開始
 * [書　式] void AIXP_StartFname(AIXP aixp, Char8 *fname, void *atr);
 * [入　力] AIXP	: AIXPハンドル
 *			fname	: ファイル名
 *			atr		: ディレクトリ情報
 * [出　力] なし
 * [関数値] なし
 * [機　能] fname で指定されたＡＤＸファイルの再生を開始する。
 *  Play start of AIX data specified file name
 * [Inputs  ] AIXP	: AIXP handle
 *			  fname	: File name
 *			  atr	: Directry Information
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play AIX file when you specify file name.
 */
void AIXP_StartFname(AIXP aixp, Char8 *fname, void *atr);

#ifdef	XPT_TGT_XB	/* M.W: 2001-09-01: DolbyDigital 5.1ch対応 */
/* $func$ ファイル名指定による再生の開始(DolbyDigital 5.1ch用)
 * [書　式] void AIXP_StartFnameDolbyDigital(AIXP aixp, Sint8 *fname);
 * [入　力] AIXP	: AIXPハンドル
 *			fname	: ファイル名
 * [出　力] なし
 * [関数値] なし
 * [機　能] fname で指定されたＡＤＸファイルの再生を5.1ch出力で開始する。
 *  Play start of AIX data specified file name
 * [Inputs  ] AIXP	: AIXP handle
 *			  fname	: File name
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play AIX file when you specify file name with 5.1ch.
 */
void AIXP_StartFnameDolbyDigital(AIXP aixp, Char8 *fname, void *atr);

/* $func$ スピーカー別ボリューム指定(DolbyDigital 5.1ch用)
 * [書　式] void AIXP_SetOutVolDolbyDigital(AIXP aixp, Sint32 spkid, Sint32 vol);
 * [入　力] AIXP	: AIXPハンドル
 *			spkid	: スピーカーID
 *			vol		: ボリューム
 * [出　力] なし
 * [関数値] なし
 * [機　能] spkid で指定されたスピーカーのボリュームを設定する。
 *  Setting volumes to speaker(for DolbyDigital 5.1ch)
 * [Inputs  ] AIXP	: AIXP handle
 *			  spkid	: Speaker ID
 *			  vol	: Volume
 * [Outputs ] None
 * [Return  ] None
 * [Function] Setting volumes specified by spkid.
 */
void AIXP_SetOutVolDolbyDigital(AIXP aixp, Sint32 spkid, Sint32 vol);
#endif

/* $func$ FID 指定による再生の開始
 * [書　式] void AIXP_StartAfs(AIXP aixp, Sint32 patid, Sint32 fid);
 * [入　力] AIXP	: AIXPハンドル
 *			patid	: パーティション識別子
 *			fid		: ファイル識別子
 * [出　力] なし
 * [関数値] なし
 * [機　能] パーティション識別子とファイル識別子で指定されたＡＤＸファイルの
 *			再生を開始する。
 *  Play start of AIX data by specified file ID
 * [Inputs  ] AIXP	: AIXP handl
 *			  patid	: Partition ID
 *			  fid	: File ID
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play AIX file when you specify partition ID and file ID.
 */
void AIXP_StartAfs(AIXP aixp, Sint32 patid, Sint32 fid);

/* $func$ ストリームジョイントによる再生の開始
 * [書　式] void AIXP_StartSj(AIXP aixp, SJ sj);
 * [入　力] AIXP	: AIXPハンドル
 *			sj		: ストリームジョイント
 * [出　力] なし
 * [関数値] なし
 * [機　能] ストリームジョイントから得られるデータを再生する。
 *  Play start of AIX data from Stream Joint
 * [Inputs  ] AIXP	: AIXP handle
 *			  sj	: Stream Joint
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play AIX file when you specify Stream Joint.
 */
void AIXP_StartSj(AIXP aixp, SJ sj);

/* $func$ メモリ指定による再生の開始
 * [書　式] void AIXP_StartMem(AIXP aixp, void *aixdat, Sint32 datlen);
 * [入　力] AIXP	: AIXPハンドル
 *			aixdat	: ＡＤＸデータのアドレス
 *			datlen	: ＡＤＸデータの大きさ
 * [出　力] なし
 * [関数値] なし
 * [機　能] aixdata で指定されたＡＤＸデータを再生する。
 *  Play start of AIX data on memory
 * [Inputs  ] AIXP	: AIXP handle
 *			  aixdat: Address of AIX data
 *			  datlen: Length of playing AIX data
 * [Outputs ] None
 * [Return  ] None
 * [Function] Starts to play AIX data on memory. Plays to specified length.
 */
void AIXP_StartMem(AIXP aixp, void *aixdat, Sint32 datlen);

/* $func$ 再生の停止
 * [書　式] void AIXP_Stop(AIXP aixp);
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] なし
 * [機　能] ＡＤＸの再生を停止する。
 *  Play stop
 * [Inputs  ] AIXP	: AIXP handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Stops to play AIX data.
 */
void AIXP_Stop(AIXP aixp);

/* $func$ 状態の取得
 * [書　式] Sint32 AIXP_GetStat( AIXP aixp );
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] 現在の AIXPハンドルの状態を表す定数
 * 				AIXP_STAT_STOP	 :	停止中
 *				AIXP_STAT_DECINFO:	ＡＤＸ のヘッダ情報取得中
 *				AIXP_STAT_PREP	 :	再生準備中
 *				AIXP_STAT_PLAYING:	デコード＆再生中
 *				AIXP_STAT_DECEND :	デコード終了
 *				AIXP_STAT_PLAYEND:	再生終了
 * [機　能] 現在のAIXPハンドルの状態を取得する。
 *  Get status
 * [Inputs  ] AIXP	: AIXP handle
 * [Outputs ] None
 * [Return  ] Status of AIXP handle
 * [Function] Obtains status of AIXP handle.
 */
Sint32 AIXP_GetStat(AIXP aixp);

/* $func$ ADXTハンドルの取得
 * [書　式] ADXT AIXP_GetAdxt(AIXP aixp, Sint32 trno);
 * [入　力] AIXP	: AIXPハンドル
 *			trno	: トラック番号
 * [出　力] なし
 * [関数値] adxt	: ADXTハンドル
 * [機　能] ADXTハンドルを取得する。
 *  Getting a ADXT handle of specified track
 * [Inputs  ] AIXP	: AIXP handle
 *			  trno	: Track No.
 * [Outputs ] None
 * [Return  ] ADXT handle
 * [Function] Obtains a ADXT handle of specified track.
 */
ADXT AIXP_GetAdxt(AIXP aixp, Sint32 trno);

/*	$func$ 再読み込み開始時間の設定
 * [書　式] void AIXP_SetReloadTime(AIXP aixp,float time,Sint32 nch,Sint32 sfreq);
 * [入　力] AIXP	: AIXPハンドル
 *			time	: 再読み込み開始時間
 *			nch		: チャンネル数
 *			sfreq	: サンプリング周波数
 * [出　力] なし
 * [関数値] なし
 * [機　能] 入力バッファへの再読み込み開始時間を設定する。
 *			ＣＤバッファ内の量が time 秒より少なくなるとＣＤから
 *			データを読み込む。
 *  Set the time of start sector to reload
 * [Inputs  ] AIXP	: AIXP handle
 *			  time  : start remain time
 *			  nch   : number of channel
 *			  sfreq : sampling frequency
 * [Outputs ] None
 * [Return  ] None
 * [Function] Sets of the time of start sector to reload into input buffer.
 *			 Reads data from CD-ROM when a quantity of data in the input 
 *			 buffer becomes less than 'time' [second].
 */
void AIXP_SetReloadTime(AIXP aixp, float time, Sint32 nch, Sint32 sfreq);

/*	$func$ 入力バッファ内再生時間
 * [書　式] float AIXP_GetIbufRemainTime(AIXP aixp);
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] 再生可能時間　(単位：秒)
 * [機　能] 入力バッファにあるデータで再生可能な時間を取得する。
 *			AIXデータのみ対応。
 * [Inputs  ] AIXP	: AIXP handle
 * [Outputs ] None
 * [Return  ] Playable time (sec)
 * [Function] Obtains playable time using only data in input buffer.
 *			  You can use this function only playing AIX data.
 */
float AIXP_GetIbufRemainTime(AIXP aixp);

/*	$func$ 各ハンドルのサーバ関数　（内部状態の更新)
 * [書　式] Sint32 AIXP_ExecHndl(AIXP aixp);
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] なし
 * [機　能] 各ハンドルの内部状態を更新する。
 *			AIXP_ExecServer内から呼び出される。
 *  Server function of each handle
 * [Inputs  ] AIXP	: AIXP handle
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status.
 *			  This function is called from 'AIXP_ExecServer' function.
 */
void AIXP_ExecHndl(AIXP aixp);

/*	$func$ サーバ関数　（内部状態の更新)
 * [書　式] Sint32 AIXP_ExecServer(void);
 * [入　力] なし
 * [出　力] なし
 * [関数値] なし
 * [機　能] ライブラリの内部状態を更新する。
 *			V-Sync 毎に呼び出さなければならない。
 *  Server function
 * [Inputs  ] None
 * [Outputs ] None
 * [Return  ] None
 * [Function] Update the inside status of library.
 */
void AIXP_ExecServer(void);

/*	$func$ ループした回数の取得
 * [書　式] Sint32 AIXP_GetLpCnt(AIXP aixp);
 * [入　力] AIXP	: AIXPハンドル
 * [出　力] なし
 * [関数値] ループした回数
 * [機　能] ループした回数を取得する。
 *  Get the number of times played a loop
 * [Inputs  ] AIXP	: AIXP handle
 * [Outputs ] None
 * [Return  ] Number of times played a loop
 * [Function] Obtains the number of times that played a loop.
 */
Sint32 AIXP_GetLpCnt(AIXP aixp);

/*	$func$ ループスイッチの設定
 * [書　式] void AIXP_SetLpSw(AIXP aixp, Sint32 flg);
 * [入　力] aixp	: AIXPハンドル
 *			flg		: 1=ループする、0=ループしない
 * [出　力] なし
 * [関数値] なし
 * [機　能] ループするか否かを設定する。
 */
void AIXP_SetLpSw(AIXP aixp, Sint32 sw);

/*	$func$ フレーズリンクスイッチの設定
 * [書　式] void AIXP_SetLpSw(AIXP aixp, Sint32 flg);
 * [入　力] aixp	: AIXPハンドル
 *			flg		: 1=連結する、0=連結しない
 * [出　力] なし
 * [関数値] なし
 * [機　能] フレーズを連続再生するか否かを設定する。
 */
void AIXP_SetLnkSw(AIXP aixp, Sint32 sw);

/*	$func$ 再生開始フレーズ番号の設定
 * [書　式] void AIXP_SetPhraseNo(AIXP aixp, Sint32 phno);
 * [入　力] aixp	: AIXPハンドル
 *			phno	: フレーズ番号
 * [出　力] なし
 * [関数値] なし
 * [機　能] 再生開始フレーズ番号を設定する。
 */
void AIXP_SetStartPh(AIXP aixp, Sint32 phno);

/*	$func$ 再生開始フレーズ番号の取得
 * [書　式] Sint32 AIXP_GetStartPh(AIXP aixp)
 * [入　力] aixp	: AIXPハンドル
 * [出　力] なし
 * [関数値] フレーズ番号
 * [機　能] 再生開始フレーズ番号を取得する。
 */
Sint32 AIXP_GetStartPho(AIXP aixp);

/*	$func$ ループ開始フレーズ番号の設定
 * [書　式] void AIXP_SetPhraseNo(AIXP aixp, Sint32 phno);
 * [入　力] aixp	: AIXPハンドル
 *			phno	: フレーズ番号
 * [出　力] なし
 * [関数値] なし
 * [機　能] ループ時の開始フレーズ番号を設定する。
 */
void AIXP_SetLpStartPh(AIXP aixp, Sint32 phno);

/*	$func$ ループスタートフレーズ番号の取得
 * [書　式] Sint32 AIXP_GetStartPh(AIXP aixp)
 * [入　力] aixp	: AIXPハンドル
 * [出　力] なし
 * [関数値] フレーズ番号
 * [機　能] ループスタートフレーズ番号を取得する。
 */
Sint32 AIXP_GetLpStartPho(AIXP aixp);

/*	$func$ ループエンドフレーズ番号の設定
 * [書　式] void AIXP_SetPhraseNo(AIXP aixp, Sint32 phno);
 * [入　力] aixp	: AIXPハンドル
 *			phno	: フレーズ番号
 * [出　力] なし
 * [関数値] なし
 * [機　能] ループエンドフレーズ番号を設定する。
 */
void AIXP_SetLpEndPh(AIXP aixp, Sint32 phno);

/*	$func$ ループエンドフレーズ番号の取得
 * [書　式] Sint32 AIXP_GetStartPh(AIXP aixp)
 * [入　力] aixp	: AIXPハンドル
 * [出　力] なし
 * [関数値] フレーズ番号
 * [機　能] ループエンドフレーズ番号を取得する。
 */
Sint32 AIXP_GetLpEndPho(AIXP aixp);

/*	$func$ 一時停止の設定
 * [書　式] void AIXP_Pause(AIXP aixp, Sint32 sw);
 * [入　力] AIXP	: AIXPハンドル
 *			sw		: 1=一時停止、0=再開
 * [出　力] なし
 * [関数値] なし
 * [機　能] 一時停止するか否かを設定する。
 *  Pause/Continue
 * [Inputs  ] AIXP	: AIXP handle
 *			  sw	: 1=pause, 0=continue
 * [Outputs ] None
 * [Return  ] None
 * [Function] Stops temporarily by a specified switch and release temporary 
 *			  standstill.
 */
void AIXP_Pause(AIXP aixp, Sint32 sw);

/*			強制モノラル出力スイッチの設定	
[書  式]	void AIXP_SetOutoputMono(Sint32 flag);
[引  数]	Sint32 flag		強制モノラル出力フラグ(OFF:0, ON:1)
[戻り値]	なし					
[機  能]	ステレオデータを強制的にモノラルデータとして出力する。
[備　考]	
*/
void AIXP_SetOutputMono(Sint32 flag);

#ifdef __cplusplus
}
#endif

#endif

/* end of file */
