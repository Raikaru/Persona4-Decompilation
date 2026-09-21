/* CRI CVFS (virtual file system) device interface: the table a device returns from its
 * xxCiGetInterface (mfci, gcci); the four unused slots are NULL. */
#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include "cri_xpt.h"

typedef void (*CVFS_ERRFUNC)(void *obj, const Char8 *msg, void *hn);

typedef struct {
	void (*ExecServer)(void);                                       /* 0x00 */
	void (*EntryErrFunc)(CVFS_ERRFUNC func, void *obj);             /* 0x04 */
	Sint32 (*GetFileSize)(const Char8 *fname);                      /* 0x08 */
	void *x0c;
	void *(*Open)(const Char8 *fname, void *dir, Sint32 rw);        /* 0x10 */
	void (*Close)(void *hn);                                        /* 0x14 */
	Sint32 (*Seek)(void *hn, Sint32 pos, Sint32 type);              /* 0x18 */
	Sint32 (*Tell)(void *hn);                                       /* 0x1C */
	Sint32 (*ReqRd)(void *hn, Sint32 nsct, void *buf);              /* 0x20 */
	void *x24;
	void (*StopTr)(void *hn);                                       /* 0x28 */
	Sint32 (*GetStat)(void *hn);                                    /* 0x2C */
	Sint32 (*GetSctLen)(void *hn);                                  /* 0x30 */
	void (*SetSctLen)(void *hn, Sint32 sctlen);                     /* 0x34 */
	Sint32 (*GetNumTr)(void *hn);                                   /* 0x38 */
	void *x3c[11];                                                  /* 0x3C */
} CVFS_IF;

#define CVFS_SEEK_SET 0
#define CVFS_SEEK_CUR 1
#define CVFS_SEEK_END 2

void SVM_Lock(void);
void SVM_Unlock(void);

#endif
