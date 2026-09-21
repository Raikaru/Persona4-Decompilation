/* CRI CVFS (virtual file system) device interface: the table a device returns from its
 * xxCiGetInterface (mfci, gcci). */
#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include "cri_xpt.h"

typedef void (*CVFS_ERRFUNC)(void *obj, const Char8 *msg, void *hn);

typedef struct {
	void (*ExecServer)(void);                                       /* 0x00 */
	void (*EntryErrFunc)(CVFS_ERRFUNC func, void *obj);             /* 0x04 */
	Sint32 (*GetFileSize)(const Char8 *fname);                      /* 0x08 */
	Sint32 (*GetFreeSize)(const Char8 *devname);                    /* 0x0C retail 004e262c lw $s0,0xc($s0) */
	void *(*Open)(const Char8 *fname, void *dir, Sint32 rw);        /* 0x10 */
	void (*Close)(void *hn);                                        /* 0x14 */
	Sint32 (*Seek)(void *hn, Sint32 pos, Sint32 type);              /* 0x18 */
	Sint32 (*Tell)(void *hn);                                       /* 0x1C */
	Sint32 (*ReqRd)(void *hn, Sint32 nsct, void *buf);              /* 0x20 */
	Sint32 (*ReqWr)(void *hn, Sint32 nsct, void *buf);              /* 0x24 retail 004e21d8 shape */
	void (*StopTr)(void *hn);                                       /* 0x28 */
	Sint32 (*GetStat)(void *hn);                                    /* 0x2C */
	Sint32 (*GetSctLen)(void *hn);                                  /* 0x30 */
	void (*SetSctLen)(void *hn, Sint32 sctlen);                     /* 0x34 */
	Sint32 (*GetNumTr)(void *hn);                                   /* 0x38 */
	Sint32 (*ChangeDir)(const Char8 *dirname);                      /* 0x3C */
	Sint32 (*IsExistFile)(const Char8 *fname);                      /* 0x40 retail 004e28d8 lw $v0,0x40($s0) */
	Sint32 (*GetNumFiles)(void);                                    /* 0x44 retail 004e29d8 lw $s0,0x44($s0) */
	Sint32 (*LoadDirInfo)(const Char8 *name, void *inf, Sint32 num);/* 0x48 retail 004e2a?? lw $v0,0x48($v0) */
	Sint32 (*GetMaxByteRate)(void *hn);                             /* 0x4C retail 004e2b2c lw $v0,0x4c($v0) */
	Sint32 (*MakeDir)(const Char8 *dirname);                        /* 0x50 */
	Sint32 (*RemoveDir)(const Char8 *dname);                        /* 0x54 */
	Sint32 (*DeleteFile)(const Char8 *fname);                       /* 0x58 */
	Sint32 (*GetFileSizeEx)(const Char8 *fname, void *size);        /* 0x5C retail 004e2494 lw $v0,0x5c($s0) */
	Sint32 (*OptFn)(void *hn, Sint32 fnid, Sint32 a, Sint32 b);     /* 0x60 retail 004e2e7c lw $v0,0x60($v1) */
	Sint32 (*OptFn2)(void *hn, Sint32 fnid, Sint32 a, Sint32 b);    /* 0x64 retail 004e2ee4 lw $v0,0x64($v0) */
} CVFS_IF;

#define CVFS_SEEK_SET 0
#define CVFS_SEEK_CUR 1
#define CVFS_SEEK_END 2

void SVM_Lock(void);
void SVM_Unlock(void);

#endif
