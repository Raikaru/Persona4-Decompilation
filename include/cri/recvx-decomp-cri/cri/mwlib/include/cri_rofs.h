/***********************************************************************
 *
 *  Software Library
 *  Copyright (c) 2001,2002 CRI-MW
 *
 *      Read Only File System
 *
 *  Module  : Library Header File
 *  File    : cri_rofs.h
 *  Author  : Nagayasu Takuya
 *  Modify  : Mikoshiba Kengo
 *  Date    : 2002-09-24
 *  Version : 1.230
 *  Notes   : 
 ***********************************************************************/

/*---------------------------------------------------------------------*/
#ifndef _CRI_ROFS_H_
#define _CRI_ROFS_H_

/*****************************************************************************
 *      インクルードファイル
 *****************************************************************************/

/*---------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <cri_xpt.h>

#ifndef CRI_XPT_H
	Please include "cri_xpt.h"		/* 予防策 : エラーを起こさせる */
#endif

/*****************************************************************************
 *      定数マクロ
 *****************************************************************************/

/* ROFS Version */
#define ROFS_VERSION_STR		"1.23"		/* Version number */

/* セクタ長 */
#define ROFS_SCT_LEN			(2048)

/* ファイル属性 */
#define ROFS_ATR_DIRECTORY		(0x02)	/* ディレクトリ */

/* 最大文字数 */
#define ROFS_VOLNAME_LEN		(8)		/* ボリューム名の文字列長 */
#define ROFS_VOLNAME_SIZ		(ROFS_VOLNAME_LEN + 1)	/* 文字列サイズ */

#define ROFS_FNAME_LEN			(31)	/* ファイル名の文字列長 */
#define ROFS_FNAME_SIZ			(ROFS_FNAME_LEN + 1)	/* 文字列サイズ */

#define ROFS_DIRNAME_LEN		(31)	/* ディレクトリ名の文字列長 */
#define RPFS_DIRNAME_SIZ		(ROFS_DIRNAME_LEN+1)	/* 文字列サイズ */

/*****************************************************************************
 *      列挙定数
 *****************************************************************************/

/* ファイルハンドル状態 */
typedef enum {
	ROFS_STAT_IDLE		= (0),			/* Idle status */
	ROFS_STAT_COMPLETE	= (1),			/* Tranfer complete status */
	ROFS_STAT_TRANS		= (2),			/* During transfer status */
	ROFS_STAT_ERR		= (3),			/* Error outbreak status */
	ROFS_STAT_NUM
} RofsStat;

/* シークモード */
typedef enum {
	ROFS_SEEK_SET		= (0),			/* Top of file */
	ROFS_SEEK_CUR		= (1),			/* Current position */
	ROFS_SEEK_END		= (2),			/* End of file */
	ROFS_SEEK_NUM
} RofsSeek;

/* エラーコード */
typedef enum {
	ROFS_ERR_OK			= (0),			/* 正常終了 */
	ROFS_ERR_NG			= (-1),			/* 失敗 */

	ROFS_ERR_PRM		= (-100),		/* パラメータの設定エラー */
	ROFS_ERR_ILLHDL		= (-101),		/* ファイルハンドルが不正 */
	ROFS_ERR_NOHNDL		= (-102),		/* ファイルハンドルに空きがない */
	ROFS_ERR_VOLNAME	= (-103),		/* 不正なボリューム名 */
	ROFS_ERR_REGVOLNAME	= (-104),		/* 登録済みのボリューム名 */
	ROFS_ERR_VOLUME		= (-105),		/* ボリュームの無効エラー */
	ROFS_ERR_NOTDIR		= (-106),		/* ディレクトリでないものを指定した */
	ROFS_ERR_NOTFOUND	= (-107),		/* 存在しないファイル */
	ROFS_ERR_ILLDIRBUF	= (-108),		/* 不正なディレクトリレコード */
	ROFS_ERR_DIROVER	= (-109),		/* ディレクトリエントリの最大数をオーバーした */

	ROFS_ERR_BUSY		= (-200),		/* 他のコマンドを実行中 */
	ROFS_ERR_TOUT		= (-201),		/* 内部処理でタイムアウトが発生した */
	ROFS_ERR_PRIMITIVE	= (-202),		/* プリミティブ関数エラー */
	ROFS_ERR_INIT		= (-203),		/* 初期化エラー */
	ROFS_ERR_REQRD		= (-204),		/* 読み込み要求エラー */
	ROFS_ERR_SEEK		= (-205),		/* シークエラー */
	ROFS_ERR_OPEN		= (-206),		/* ファイルオープンエラー */
	ROFS_ERR_READ		= (-207),		/* 読み込みエラー */

	ROFS_ERR_INTERNAL	= (-1000)		/* 内部エラー */
} RofsErr;

/*****************************************************************************
 *      処理マクロ
 *****************************************************************************/
/* ライブラリ作業領域サイズ */
#define ROFS_GET_LIBWORK_SIZ(max_open, max_volume, max_dirent) \
	(sizeof(RofsWork)+((max_open)+1)*sizeof(RofsHandle)+\
	(ROFS_GET_DIRREC_SIZ(max_dirent)+sizeof(RofsVolume))*(max_volume)+8)

/* ディレクトリレコード領域サイズ */
#define ROFS_GET_DIRREC_SIZ(n_dirent) \
	(sizeof(RofsDirRec)-sizeof(RofsDirRecEnt)+(n_dirent)*sizeof(RofsDirRecEnt))

/* ディレクトリの判定 */
#define ROFS_IS_ATR_DIRECTORY(finf) \
	(((finf)->fatr & ROFS_ATR_DIRECTORY)?TRUE:FALSE)

/* ポインタを64byte境界に合わせる */
#define ROFS_ALIGN_64BYTE(ptr)		(((Sint32)(ptr)+63) & 0xffffffc0)

/*****************************************************************************
 *      データ型の定義
 *****************************************************************************/

/* ワーク領域 */
typedef struct RofsStWrok		RofsWork;

/* プリミティブ関数 */
typedef struct RofsPfsIfTbl		RofsPfsTbl;

/* デバイスコントロール関数 */
typedef struct RfpfsDevIfTbl	RofsDevTbl;

/* ライブラリインターフェース */
typedef struct RfmaiLibIfTbl	RofsLif;

/* ディレクトリレコードエントリ */
typedef struct {
	Uint32	fsize;						/* file size lower */
	Uint32	fsize_ex;					/* file size upper */
	Sint32	fad;						/* fad */
	Uint8	fatr;						/* file attribute */
	Uint8	sid;						/* filename search id */
	Char8	fname[ROFS_FNAME_SIZ];		/* filename */
	Uint8	pad[2];						/* align padding */
} RofsDirRecEnt;	/* 48 bytes */

/* ディレクトリレコード */
typedef struct {
	Sint32	dir_num;					/* number of record */
	Sint32	max_ent;					/* max entry of directory record */
	Sint32	dir_fad;					/* fad of directory record */
	Char8	volname[ROFS_VOLNAME_SIZ];	/* volume name */
	Uint8	pad[3];						/* align padding */
	RofsDirRecEnt	dirrec_tbl[1];		/* record table */
} RofsDirRec;		/* 24 bytes */
typedef RofsDirRec	*RofsDirRecBuf;

/* ボリューム管理構造体 */
typedef struct {
	void	*img_hn;					/* file handle of the CVM file */
	Sint32	zisb;						/* ZONE0イメージデータ開始位置(0の場合DVD-ROM直接読み) */
	Sint32	ptbl_cba;					/* cba of path table */
	Sint32	ptbl_size;					/* size of path table */
	RofsDirRecBuf	curdir;				/* current directory handle */
	Sint16	req_cnt;					/* request counter */
	Char8	volname[ROFS_VOLNAME_SIZ];	/* volume name */
	Uint8	pad[1];						/* align padding */
} RofsVolume;		/* 32 bytes */

/* ROFS File Handle */
typedef struct {
	Uint32		fsize;					/* file size lower */
	Uint32		fsize_ex;				/* file size upper */
	RofsWork	*wk;					/* pointer of lib work */
	Sint32		fid;					/* file id */
	Sint32		fad;					/* fad */
	Sint32		ofs;					/* offset */
	Sint32		fsctsize;				/* sctor size of the file */
	RofsVolume	*vol;					/* image file volume */
	Sint32		rsize;					/* reading size */
	Sint32		trns_seg;				/* 転送済ブロック単位 */
	Sint32		trns_ofs;				/* 転送済バイト単位 */
	Sint32		trns_unit;				/* 転送単位(ブロック) */
	Uint8		*rdadr;					/* 読み込みアドレス */
	Sint16		used;					/* used flag */
	Sint16		act;					/* handle act */
	Sint16		stat;					/* handle status(RofsStat) */
	Sint16		err;					/* error status */
} RofsHandle;		/* 60 bytes */
typedef RofsHandle	*Rofs;

/* ROFS Work Area */
struct RofsStWrok {
	Bool			f_init;				/* 初期化フラグ */
	Sint32			max_open;			/* max open files */
	Sint32			max_volume;
	Sint32			max_dirent;
	Sint32			worksiz;
	Uint32			exec_server_cnt;	/* counter */
	Rofs			syshdl;				/* handle for system command */
	Rofs			hndtbl;				/* handle */
	RofsVolume		*vollist;			/* ボリューム情報リスト */
	RofsVolume		*curvol;			/* デフォルトボリューム情報 */
	RofsDirRecBuf	dirbuf;				/* ディレクトリレコードの開始位置 */
	RofsPfsTbl		*pfs;				/* プリミティブ関数 */
	RofsDevTbl		*dev;				/* デバイスコントロール関数 */
	RofsLif			*liftbl;			/* ライブラリインターフェース */
	void	(*g_errcb)(void *, Char8 *, Sint32);	/* error callback */
	void			*g_errcb_1st;		/* error callback 1st arg. */
	Uint32			*sctbuf;			/* sector buffer addres */
	Uint32	sct_load_buf[(ROFS_SCT_LEN * 2 + 64) / 4];	/* sector buffer */
	RofsHandle		hndlist[1];			/* handle table */
}; /* 68 + 4160 + (60 * (handle num + 1)) */

/* ライブラリ初期化情報  */
typedef struct {
	Sint32	max_open;					/* 同時にオープンできる最大ファイル数 */
	Sint32	max_volume;					/* 同時に登録できる最大ボリューム数 */
	Sint32	max_dirent;					/* ディレクトリに格納する最大ファイル数 */
	void	*rofs_work;					/* ライブラリ作業領域の先頭アドレス */
} RofsInitPara;

/* ファイル情報 */
typedef struct {
	Uint32	fsize;						/* file size lower */
	Uint32	fsize_ex;					/* file size upper */
	Char8	*fname;						/* ファイル名 */
	Uint8	fatr;						/* ファイル属性 */
	Uint8	pad[3];						/* align padding */
} RofsFileInf;		/* 16 bytes */

/* ボリューム情報 */
typedef struct {
	Char8	*volname;					/* ボリューム名 */
	void	*fhn;						/* ボリュームのファイルハンドル */
} RofsVolumeInf;

/* エラーコールバック関数 */
typedef void (*RofsErrFunc)(void *obj, Char8 *msg, Sint32 errcode);

/* プリミティブ関数テーブル */
struct RofsPfsIfTbl {
	void		(*pfs_execserver)(void);
	void		(*pfs_reserve01)(RofsErrFunc, void *);
	Sint32		(*pfs_reserve02)(Sint8 *);
	Sint32		(*pfs_reserve03)(void);
	void		*(*pfs_reserve04)(Sint8 *, void *, Sint32);
	void		(*pfs_reserve05)(void *);
	Sint32		(*pfs_seek)(void *, Sint32, RofsSeek);
	Sint32		(*pfs_tell)(void *);
	Sint32		(*pfs_reqrd)(void *, Sint32, void *);
	Sint32		(*pfs_reserve07)(void *, Sint32, void *);
	void		(*pfs_stoptr)(void *);
	Sint32		(*pfs_getstat)(void *);
	Sint32		(*pfs_getsctlen)(void *);
	void		(*pfs_reserve08)(void *, Sint32);
	Sint32		(*pfs_getnumtr)(void *);
	Sint32		(*pfs_reserve09)(Sint8 *);
	Sint32		(*pfs_reserve10)(Sint8 *);
	Sint32		(*pfs_reserve11)(void);
	Sint32		(*pfs_reserve12)(Sint8 *, void *, Sint32);
	Sint32		(*pfs_reserve13)(void *);
	Sint32		(*pfs_reserve14)(Sint8 *);
	Sint32		(*pfs_reserve15)(Sint8 *);
	Sint32		(*pfs_reserve16)(Sint8 *);
	Sint32		(*pfs_reserve17)(Sint8 *, void *);
	Sint32		(*pfs_reserve18)(void *, Sint32, Sint32, Sint32);
	Sint32		(*pfs_reserve19)(void *, Sint32, Sint32, Sint32);
	/* 2002-09-11 Ver.1.22a miko { : 64bit対応 */
	Sint64		(*pfs_getnumtr64)(void *);
	/* } miko */
};

/*****************************************************************************
 *      変数宣言
 *****************************************************************************/

/*****************************************************************************
 *      関数宣言
 *****************************************************************************/

/*============================================================================
 *      ライブラリ初期化／終了
 *===========================================================================*/
/* ファイルシステムの初期化
 * [入　力] init_para	: ライブラリ初期化パラメータ
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 
 * (a) ライブラリ作業領域は ROFS_GET_LIBWORK_SIZマクロ で求めること。
 * (b) init_para.max_dirent は、"."と".."の２つ分を加算すること。			*/
RofsErr		ROFS_Init(RofsInitPara *init_para);

/* ファイルシステムの終了
 * [入　力] なし
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
void		ROFS_Finish(void);

/* プリミティブ関数の登録
 * [入　力] pfs_tbl		: プリミティブ関数テーブル
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 
 * (a) デフォルトではCRI-MW標準の関数が登録されている。						*/
RofsErr		ROFS_SetPfsFuncTbl(RofsPfsTbl *pfs_tbl);

/*============================================================================
 *      ボリューム操作
 *===========================================================================*/
/* ボリュームの追加
 * [入　力] volname		: ボリューム名
 *			img_hn		: オープン済みボリュームのハンドル（ファイルハンドル）
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 
 * (a) ボリューム名"ROFS"はライブラリ予約なので使用不可。					*/
RofsErr		ROFS_AddVolume(Char8 *volname, void *img_hn);

/* ボリュームの削除
 * [入　力] volname		: ボリューム名
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_DelVolume(Char8 *volname);

/* デフォルトボリュームの設定
 * [入　力] volname		: ボリューム名
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_SetDefVolume(Char8 *volname);

/* デフォルトボリュームの取得
 * [入　力] なし
 * [出　力] なし
 * [関数値] ボリューム名
 * [備　考] 																*/
Char8		*ROFS_GetDefVolume(void);

/* ボリュームハンドルの切り替え
 * [入　力] volname		: ボリューム名
 *			img_hn		: オープン済みボリュームのハンドル（ファイルハンドル）
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_SwitchImgHn(Char8 *volname, void *img_hn);

/*============================================================================
 *      ファイル操作
 *===========================================================================*/
/* ファイルのオープン
 * [入　力] fname		: ファイル名
 *			dir_buf		: ディレクトリレコード
 * [出　力] なし
 * [関数値] ROFSハンドル
 * [備　考] 
 * (a) dir_buf が NULL の場合は、カレントディレクトリレコードを参照する。	*/
Rofs		ROFS_Open(Char8 *fname, void *dir_buf);

/* セクタ指定によるファイルのオープン
 * [入　力] volname		: ボリューム名
 *			stsct		: 先頭セクタ番号
 *			nsct		: セクタ数
 * [出　力] なし
 * [関数値] ROFSハンドル
 * [備　考] 																*/
Rofs		ROFS_OpenRange(Char8 *volname, Sint32 stsct, Sint32 nsct);

/* ファイルのクローズ
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] なし
 * [備　考] 																*/
void		ROFS_Close(Rofs rofs);

/* ファイル現在位置の移動
 * [入　力] rofs		: ROFSハンドル
 *			nsct		: シーク開始位置からの移動セクタ数
 *			sk_mode		: シークモード
 * [出　力] なし
 * [関数値] なし
 * [備　考] 																*/
Sint32		ROFS_Seek(Rofs rofs, Sint32 nsct, RofsSeek sk_mode);

/* ファイル現在位置の取得
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] ファイル先頭からのセクタ数
 * [備　考] 																*/
Sint32		ROFS_Tell(Rofs rofs);

/* 読み込みの要求
 * [入　力] rofs		: ROFSハンドル
 *			nsct		: セクタ数
 * [出　力] buf			: 読み込み先バッファ
 * [関数値] 要求を受け付けたセクタ数
 * [備　考] 
 * (a) buf の先頭を64byte境界に揃えておくこと。								*/
Sint32		ROFS_ReqRd(Rofs rofs, Sint32 nsct, void *buf);

/* 転送の停止
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] なし
 * [備　考] 																*/
void		ROFS_StopTr(Rofs rofs);

/* サーバ処理の実行
 * [入　力] なし
 * [出　力] なし
 * [関数値] なし
 * [備　考] 
 * (a) ADXのADXF_SetupRofs関数を使っている場合は、本関数を使わないこと。
 *	   ※現在はADXとの併用必須。単体では動作しないので、本関数は使わない。	*/
void		ROFS_ExecServer(void);

/*============================================================================
 *      情報の取得
 *===========================================================================*/
/* ファイルハンドル状態の取得
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] ステータス
 * [備　考] 																*/
RofsStat	ROFS_GetStat(Rofs rofs);

/* ファイルサイズの取得
 * [入　力] fname		: ファイル名
 * [出　力] なし
 * [関数値] ファイルサイズ（バイト数）
 * [備　考] 
 * (a) 負値の場合はサイズでは無く、エラーを示す。
 * (b) ファイルサイズが2GB以上の場合 0x7fffffff を返す。					*/
Sint32		ROFS_GetFileSiz(Char8 *fname);

/* セクタ長の取得
 * [入　力] なし
 * [出　力] なし
 * [関数値] セクタ長（バイト数）
 * [備　考] 																*/
Sint32		ROFS_GetSctLen(void);

/* 転送済みサイズの取得
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] 転送済みデータサイズ（バイト数）
 * [備　考] 																*/
Sint32		ROFS_GetNumTr(Rofs rofs);

/* ボリューム情報の取得
 * [入　力] volname		: ボリューム名
 * [出　力] volinf		: ボリューム情報
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_GetVolumeInf(Char8 *volname, RofsVolumeInf *volinf);

/*============================================================================
 *      ディレクトリ操作
 *===========================================================================*/
/* ディレクトリレコードの読み込み
 * [入　力] dirname		: ディレクトリ名
 *			n_dirent	: レコード数の上限
 * [出　力] dir_buf		: ディレクトリレコード
 * [関数値] エラー
 * [備　考] 
 * (a) 完了復帰。
 * (b) n_dirent が実際のレコード数未満の場合は、ROFS_ERR_DIROVER が返る。	*/
RofsErr		ROFS_LoadDir(Char8 *dirname, void *dir_buf, Sint32 n_dirent);

/* カレントディレクトリの設定
 * [入　力] volname		: ボリューム名
 *			dir_buf		: ディレクトリレコード
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_SetDir(Char8 *volname, void *dir_buf);

/* カレントディレクトリの設定(ISO9660ディレクトリレコード) 
 * [入　力] volname		: ボリューム名
 *			dir_buf		: ディレクトリレコード
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 
 * (a) サンプルプログラム参照												*/
RofsErr		ROFS_SetIsoDir(Char8 *volname, void *dir_buf);

/* カレントディレクトリの変更
 * [入　力] dirname		: ディレクトリ名
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 
 * (a) 完了復帰。
 * (b) n_dirent が実際のレコード数未満の場合は、ROFS_ERR_DIROVER が返る。	*/
RofsErr		ROFS_ChangeDir(Char8 *dirname);

/* ファイルの存在判定
 * [入　力] fname		: ファイル名
 * [出　力] なし
 * [関数値] 有無（TRUE = 有 , FALSE = 無）
 * [備　考] 																*/
Bool		ROFS_IsExistFile(Char8 *fname);

/* ファイル数の取得
 * [入　力] volname		: ボリューム名
 * [出　力] なし
 * [関数値] ファイル数（"."と".."を除くディレクトリの数を含む）
 * [備　考] 																*/
Sint32		ROFS_GetNumFiles(Char8 *volname);

/* ディレクトリ情報の取得
 * [入　力] volname		: ボリューム名
 *			num			: レコード数の上限
 * [出　力] flist		: ファイル情報（レコード数分の配列）
 * [関数値] レコード数
 * [備　考] 																*/
Sint32		ROFS_GetDirInf(Char8 *volname, RofsFileInf *flist, Sint32 num);

/*============================================================================
 *      エラー処理
 *===========================================================================*/
/* エラーコールバック関数の登録
 * [入　力] errfunc		: エラーコールバック関数
 *			obj			: エラーオブジェクト
 * [出　力] なし
 * [関数値] なし
 * [備　考] 																*/
void		ROFS_EntryErrFunc(RofsErrFunc errfunc, void *obj);

/* 最後に発生したエラーを取得する
 * [入　力] なし
 * [出　力] なし
 * [関数値] エラー
 * [備　考] 																*/
RofsErr		ROFS_GetLastError(void);

/*============================================================================
 *      64bit対応
 *===========================================================================*/
/* 転送済みサイズの取得 / 64bit版
 * [入　力] rofs		: ROFSハンドル
 * [出　力] なし
 * [関数値] 転送済みデータサイズ（バイト数）
 * [備　考] 																*/
Sint64		ROFS_GetNumTr64(Rofs rofs);

/* ファイルサイズの取得 / 64bit版 / PS2版のみ
 * [入　力] fname		: ファイル名
 * [出　力] なし
 * [関数値] ファイルサイズ（バイト数）
 * (a) 負値の場合はサイズでは無く、エラーを示す。
 * (c) PS2以外の機種では0x7fffffffより大きなサイズは返せない。
 * (b) ファイルサイズが2GB以上の場合 0x7fffffffffffffff を返す。			*/
Sint64		ROFS_GetFileSiz64(Char8 *fname);

/*============================================================================
 *      その他
 *===========================================================================*/
/* バージョン文字列の取得 */
const Char8	*ROFS_GetVersionStr(void);

/*****************************************************************************
 *      変数定義
 *****************************************************************************/

/*****************************************************************************
 *      関数定義
 *****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CRI_ROFS_H_ */

/* end of file */
