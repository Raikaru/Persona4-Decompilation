/* CRI CVFS (virtual file system) front end (cri_cvfs.c, "CVFS/GC Ver.2.37"): a table of named
 * devices (their xxCiGetInterface tables), a default device, file handles pairing a device table
 * with the device's handle, and the "DEV:path" name split. Most of the API (volumes, directories,
 * write, option functions, ...) was dead-stripped by the linker; the strings remain in .rodata. */
#include "cri_xpt.h"
#include <string.h>
#include <stdio.h>
#include "cvfs.h"

#define CVFS_MAX_DEV 32
#define CVFS_MAX_HN 40
#define CVFS_NAME_LEN 0x129
#define CVFS_DEVNAME_LEN 12

typedef void (*CVFS_USRERRFN)(void *obj, const Char8 *msg, void *hn);
typedef CVFS_IF *(*CVFS_GETIFFN)(void);

/* device interface table (CVFS_IF) with its option function slot */
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
	void *x3c[9];                                                   /* 0x3C */
	Sint32 (*OptFn)(void *hn, Sint32 fnid, Sint32 a, Sint32 b);     /* 0x60 */
	void *x64;
} CVFS_DEVIF;

typedef struct {
	CVFS_DEVIF *vtbl;          /* 0x00 */
	Char8 name[CVFS_DEVNAME_LEN]; /* 0x04 */
} CVFS_DEV;

typedef struct {
	CVFS_DEVIF *vtbl;          /* 0x00 */
	void *hn;                  /* 0x04 the device's handle */
} CVFS_OBJ;

CVFS_USRERRFN cvfs_errfn;
static void *cvfs_errobj;
Sint32 cvfs_init_cnt;
Char8 add_dev_tmp[CVFS_NAME_LEN];
Char8 cvfs_defdev[9];
static CVFS_DEV cvfs_tbl[CVFS_MAX_DEV];
CVFS_OBJ cvfs_obj[CVFS_MAX_HN];

static const Char8 *const volatile cvfs_build = "\nCVFS/GC Ver.2.37 Build:Oct  8 2004 13:31:51\n";

void cvFsCallUsrErrFn(void *obj, const Char8 *msg, void *hn);

/* dead */
void cvFsInit(void)
{
	cvfs_build;
	cvfs_errfn = NULL;
	cvfs_errobj = NULL;
	if (cvfs_init_cnt == 0) {
		add_dev_tmp[0] = '\0';
		cvfs_defdev[0] = '\0';
		memset(cvfs_tbl, 0, sizeof(cvfs_tbl));
		memset(cvfs_obj, 0, sizeof(cvfs_obj));
	}
	cvfs_init_cnt++;
}

/* dead */
void cvFsFinish(void)
{
	cvfs_init_cnt--;
}

/* the user error callback */
static void cvfs_Error(const Char8 *msg)
{
	if (cvfs_errfn != NULL) {
		cvfs_errfn(cvfs_errobj, msg, NULL);
	}
}

/* upper-case a name (in place) */
static void cvfs_StrUpr(Char8 *s)
{
	Uint32 i;
	Uint32 n;
	Char8 *p;

	n = strlen(s) + 1;
	p = s;
	for (i = 0; i < n; i++) {
		if (*p >= 'a' && *p <= 'z') {
			*p = *p - 0x20;
		}
		p++;
	}
}

/* is the name a registered device (its first `len` characters) */
static Sint32 cvfs_IsExistDev(const Char8 *name, Sint32 len)
{
	Sint32 i;
	CVFS_DEV *dev;

	for (i = 0; i < CVFS_MAX_DEV; i++) {
		dev = &cvfs_tbl[i];
		if (strncmp(name, dev->name, len) == 0) {
			return 1;
		}
	}
	return 0;
}

/* the device of a name (NULL: the default device) */
static CVFS_DEVIF *cvFsGetDevIf(CVFS_DEV *tbl, const Char8 *name)
{
	Uint32 i;
	Sint32 len;
	CVFS_DEV *dev;

	if (name == NULL) {
		name = cvfs_defdev;
	}
	len = strlen(name);
	dev = tbl;
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (strncmp(name, dev->name, len) == 0) {
			return cvfs_tbl[i].vtbl;
		}
		dev++;
	}
	return NULL;
}

/* the second and third searches of cvfs_ResolveDev are INDEX loops (CRI pass 35): the stepping
 * pointer is then the frontend's strength-reduced IV temporary, copied from `tbl` in the loop
 * preheader (after the strlen) with a late id between the first and second strlen @ret copies
 * (target dev2 r20 below len1, above len2); the third copy coalesces with the dying `tbl`. A
 * pointer local `dev = tbl` is an early clone local (above the strlen copies: dev2 r22). */
static CVFS_DEVIF *cvfs_SearchDev(CVFS_DEV *tbl, const Char8 *name)
{
	Uint32 i;
	Sint32 len;

	len = strlen(name);
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (strncmp(name, tbl[i].name, len) == 0) {
			return cvfs_tbl[i].vtbl;
		}
	}
	return NULL;
}

/* the device's option function (fnid 100: the device wants the "DEV:path" form) */
static Sint32 cvfs_OptFn(CVFS_DEVIF *vtbl, void *hn, Sint32 fnid, Sint32 a, Sint32 b)
{
	Sint32 ret;

	if (vtbl == NULL) {
		ret = 0;
	} else if (vtbl->OptFn != NULL) {
		ret = vtbl->OptFn(hn, fnid, a, b);
	} else {
		ret = 0;
	}
	return ret;
}

/* "DEV:path" -> upper-cased device name and path (a one-character device is a drive letter and
 * stays in the path; no ':' means no device) */
static inline void cvfs_SplitFname(const Char8 *fname, Char8 *dev, Char8 *path)
{
	Sint32 i;
	Sint32 j;
	Sint32 n;

	if (fname == NULL) {
		return;
	}
	for (i = 0; i < CVFS_NAME_LEN; i++) {
		if (fname[i] == ':' || fname[i] == '\0') {
			break;
		}
		dev[i] = fname[i];
	}
	if (fname[i] == '\0') {
		dev[i] = '\0';
		memcpy(path, dev, strlen(dev) + 1);
		dev[0] = '\0';
		return;
	}
	dev[i] = '\0';
	i++;
	if (i == 2) {
		i = 0;
		dev[0] = '\0';
	}
	n = i;
	for (j = i; j < CVFS_NAME_LEN; j++) {
		if (fname[j] == '\0') {
			break;
		}
		path[n++ - i] = fname[j];
	}
	path[n - i] = '\0';
	cvfs_StrUpr(dev);
}

/* the default device name into dev (empty when none) */
static void cvfs_GetDefDev(Char8 *dev)
{
	Sint32 len;

	len = strlen(cvfs_defdev);
	if (cvfs_defdev[0] == '\0') {
		dev[0] = '\0';
	} else {
		memcpy(dev, cvfs_defdev, len + 1);
	}
}

/* the search loop of cvFsGetDevIf with the length computed by the caller (CRI pass 28: the
 * table base `tbl` is materialised AFTER the first strlen, so the name check + strlen belong
 * to cvfs_ResolveDev's own body and `tbl = cvfs_tbl` follows them) */
static CVFS_DEVIF *cvfs_FindDev(CVFS_DEV *tbl, const Char8 *name, Sint32 len)
{
	CVFS_DEV *dev;
	Uint32 i;

	dev = tbl;
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (strncmp(name, dev->name, len) == 0) {
			return cvfs_tbl[i].vtbl;
		}
		dev++;
	}
	return NULL;
}

/* the device of a split name: the name's device, else the default device (the path is then the
 * whole name); a device asking for it gets the "DEV:path" form. (Register ranking closed in CRI
 * pass 35: the second/third searches are index loops, see cvfs_SearchDev.) */
/* the first search one inlining level deeper than the two SearchDev copies (CRI pass 32): cloned
 * after them, its i/dev get the lowest ids and the second copy's `i` takes r26 like the target */
static Sint32 cvfs_WantsDevForm(CVFS_DEV *tbl, const Char8 *name, Sint32 len)
{
	return cvfs_OptFn(cvfs_FindDev(tbl, name, len), NULL, 100, 0, 0) == 1;
}

// Finds the device table for a split file name: an empty device part takes the default device; a
// device that asked for it (option 100) gets the "DEV:path" form back in `path`; an unknown device
// name falls back to the default device with the whole original name as the path.
static CVFS_DEVIF *cvfs_ResolveDev(const Char8 *fname, Char8 *dev, Char8 *path)
{
	CVFS_DEVIF *vtbl;
	CVFS_DEV *tbl;
	const Char8 *name;
	Sint32 len;

	if (dev[0] == '\0') {
		cvfs_GetDefDev(dev);
		if (dev[0] == '\0') {
			return NULL;
		}
	}
	name = dev;
	if (name == NULL) {
		name = cvfs_defdev;
	}
	len = strlen(name);
	tbl = cvfs_tbl;
	if (cvfs_WantsDevForm(tbl, name, len)) {
		strcpy(add_dev_tmp, path);
		sprintf(path, "%s:%s", name, add_dev_tmp); /* the target passes the checked `name` (r26), not `dev` */
	}
	vtbl = cvfs_SearchDev(tbl, dev);
	if (vtbl == NULL) {
		cvfs_GetDefDev(dev);
		vtbl = cvfs_SearchDev(tbl, dev);
		if (vtbl == NULL) {
			vtbl = NULL;
		} else {
			strcpy(path, fname);
		}
	}
	return vtbl;
}

/* dead */
void cvFsSetDefVol(const Char8 *devname, const Char8 *volname)
{
	CVFS_DEVIF *vtbl;

	if (devname == NULL) {
		cvfs_Error("cvFsSetDefVol #1:illegal device name");
		return;
	}
	if (volname == NULL) {
		cvfs_Error("cvFsSetDefVol #2:illegal volume name");
		return;
	}
	vtbl = cvfs_SearchDev(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsSetDefVol #3:device not found");
		return;
	}
	cvfs_OptFn(vtbl, NULL, 1, (Sint32)volname, 0);
}

/* dead */
Sint32 cvFsGetVolumeInfo(const Char8 *devname, const Char8 *volname, void *inf)
{
	CVFS_DEVIF *vtbl;

	if (devname == NULL) {
		cvfs_Error("cvFsGetVolumeInfo #1:illegal device name");
		return 0;
	}
	if (volname == NULL) {
		cvfs_Error("cvFsGetVolumeInfo #2:illegal volume name");
		return 0;
	}
	vtbl = cvfs_SearchDev(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsGetVolumeInfo #3:device not found");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 2, (Sint32)volname, (Sint32)inf);
}

/* dead */
void cvFsDelVolume(const Char8 *devname, const Char8 *volname)
{
	CVFS_DEVIF *vtbl;

	if (devname == NULL) {
		cvfs_Error("cvFsDelVolume #1:illegal device name");
		return;
	}
	if (volname == NULL) {
		cvfs_Error("cvFsDelVolume #2:illegal volume name");
		return;
	}
	vtbl = cvfs_SearchDev(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsDelVolume #3:device not found");
		return;
	}
	cvfs_OptFn(vtbl, NULL, 3, (Sint32)volname, 0);
}

/* dead */
void cvFsAddVolumeEx(const Char8 *devname, const Char8 *volname, void *img)
{
	CVFS_DEVIF *vtbl;

	if (devname == NULL) {
		cvfs_Error("cvFsAddVolumeEx #1:illegal device name");
		return;
	}
	if (volname == NULL) {
		cvfs_Error("cvFsAddVolumeEx #2:illegal volume name");
		return;
	}
	if (img == NULL) {
		cvfs_Error("cvFsAddVolumeEx #3:illegal image handle");
		return;
	}
	vtbl = cvfs_SearchDev(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsAddVolumeEx #3:device not found");
		return;
	}
	cvfs_OptFn(vtbl, NULL, 4, (Sint32)volname, (Sint32)img);
}

/* dead */
void cvFsSetCurVolume(const Char8 *devname, void *img)
{
	CVFS_DEVIF *vtbl;

	if (devname == NULL) {
		cvfs_Error("cvFsSetCurVolume #1:illegal device name");
		return;
	}
	if (img == NULL) {
		cvfs_Error("cvFsSetCurVolume #2:illegal image handle");
		return;
	}
	vtbl = cvfs_SearchDev(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsSetCurVolume #3:device not found");
		return;
	}
	cvfs_OptFn(vtbl, NULL, 5, (Sint32)img, 0);
}

/* dead */
Sint32 cvFsOptFn2(CVFS_OBJ *obj, Sint32 fnid, Sint32 a, Sint32 b)
{
	if (obj == NULL) {
		cvfs_Error("cvFsOptFn2 #1:handle error");
		return 0;
	}
	if (obj->vtbl->OptFn == NULL) {
		cvfs_Error("cvFsOptFn2 #2:vtbl error");
		return 0;
	}
	return obj->vtbl->OptFn(obj->hn, fnid, a, b);
}

/* dead */
Sint32 cvFsOptFn1(CVFS_OBJ *obj, Sint32 fnid, Sint32 a)
{
	if (obj == NULL) {
		cvfs_Error("cvFsOptFn1 #1:handle error");
		return 0;
	}
	if (obj->vtbl->OptFn == NULL) {
		cvfs_Error("cvFsOptFn1 #2:vtbl error");
		return 0;
	}
	return obj->vtbl->OptFn(obj->hn, fnid, a, 0);
}

/* dead */
const Char8 *cvFsGetDevName(CVFS_OBJ *obj)
{
	Sint32 i;

	if (obj == NULL || obj->vtbl == NULL) {
		cvfs_Error("cvFsGetDevName #1:vtbl error");
		return NULL;
	}
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (cvfs_tbl[i].vtbl == obj->vtbl) {
			return cvfs_tbl[i].name;
		}
	}
	return NULL;
}

/* dead */
Sint32 cvFsDeleteFile(const Char8 *fname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	if (fname == NULL) {
		cvfs_Error("cvFsDeleteFile #1:illegal file name");
		return 0;
	}
	cvfs_SplitFname(fname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsDeleteFile #2:illegal device name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(fname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsDeleteFile #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsDeleteFile #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 10, (Sint32)path, 0);
}

/* dead */
Sint32 cvFsRemoveDir(const Char8 *dname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	if (dname == NULL) {
		cvfs_Error("cvFsRemoveDir #1:illegal directory name");
		return 0;
	}
	cvfs_SplitFname(dname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsRemoveDir #2:illegal device name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(dname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsRemoveDir #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsRemoveDir #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 11, (Sint32)path, 0);
}

/* dead */
Sint32 cvFsMakeDir(const Char8 *dname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	if (dname == NULL) {
		cvfs_Error("cvFsMakeDir #1:illegal directory name");
		return 0;
	}
	cvfs_SplitFname(dname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsMakeDir #2:illegal device name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(dname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsMakeDir #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsMakeDir #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 12, (Sint32)path, 0);
}

/* dead */
Sint32 cvFsGetMaxByteRate(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsGetMaxByteRate #1:handle error");
		return 0;
	}
	if (obj->vtbl->OptFn == NULL) {
		cvfs_Error("cvFsGetMaxByteRate #2:vtbl error");
		return 0;
	}
	return obj->vtbl->OptFn(obj->hn, 13, 0, 0);
}

/* dead */
Sint32 cvFsIsExistFile(const Char8 *fname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	cvfs_SplitFname(fname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsIsExistFile #2:illegal device name");
		return 0;
	}
	if (fname == NULL) {
		cvfs_Error("cvFsIsExistFile #1:illegal file name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(fname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsIsExistFile #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsIsExistFile #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 14, (Sint32)path, 0);
}

/* dead */
Sint32 cvFsChangeDir(const Char8 *dname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	if (dname == NULL) {
		cvfs_Error("cvFsChangeDir #1:illegal directory name");
		return 0;
	}
	cvfs_SplitFname(dname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsChangeDir #2:illegal device name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(dname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsChangeDir #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsChangeDir #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 15, (Sint32)path, 0);
}

/* dead */
Sint32 cvFsGetNumTr(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsGetNumTr #1:handle error");
		return 0;
	}
	if (obj->vtbl->GetNumTr == NULL) {
		cvfs_Error("cvFsGetNumTr #2:vtbl error");
		return 0;
	}
	return obj->vtbl->GetNumTr(obj->hn);
}

/* dead */
void cvFsSetSctLen(CVFS_OBJ *obj, Sint32 sctlen)
{
	if (obj == NULL) {
		cvfs_Error("cvFsSetSctLen #3:handle error");
		return;
	}
	if (obj->vtbl->SetSctLen == NULL) {
		cvfs_Error("cvFsSetSctLen #4:vtbl error");
		return;
	}
	obj->vtbl->SetSctLen(obj->hn, sctlen);
}

/* dead */
Sint32 cvFsGetSctLen(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsGetSctLen #1:handle error");
		return 0;
	}
	if (obj->vtbl->GetSctLen == NULL) {
		cvfs_Error("cvFsGetSctLen #2:vtbl error");
		return 0;
	}
	return obj->vtbl->GetSctLen(obj->hn);
}

/* dead */
Sint32 cvFsGetFreeSize(const Char8 *devname)
{
	CVFS_DEVIF *vtbl;

	vtbl = cvFsGetDevIf(cvfs_tbl, devname);
	if (vtbl == NULL) {
		cvfs_Error("cvFsGetFreeSize #5:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsGetFreeSize #6:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 16, 0, 0);
}

/* dead */
Sint32 cvFsGetFileSizeByHndl(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsGetFileSizeByHndl #1:illegal file handle");
		return 0;
	}
	return cvfs_OptFn(obj->vtbl, obj->hn, 17, 0, 0);
}

/* dead */
Sint32 cvFsGetFileSizeEx(const Char8 *fname, Sint32 *size)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	CVFS_DEVIF *vtbl;

	if (fname == NULL) {
		cvfs_Error("cvFsGetFileSizeEx #1:illegal file name");
		return 0;
	}
	cvfs_SplitFname(fname, dev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsGetFileSizeEx #2:illegal device name");
		return 0;
	}
	vtbl = cvfs_ResolveDev(fname, dev, path);
	if (vtbl == NULL) {
		cvfs_Error("cvFsGetFileSizeEx #3:device not found");
		return 0;
	}
	if (vtbl->x64 == NULL) {
		cvfs_Error("cvFsGetFileSizeEx #4:vtbl error");
		return 0;
	}
	return cvfs_OptFn(vtbl, NULL, 18, (Sint32)path, (Sint32)size);
}

// Installs the user error callback (func(obj, msg, hn)); ADXGC_SetupDvdFs installs adxgc_err_dvd.
// FUN_004E2E28
void cvFsEntryErrFunc(CVFS_USRERRFN func, void *obj)
{
	if (func == NULL) {
		cvfs_errfn = NULL;
		cvfs_errobj = NULL;
	} else {
		cvfs_errfn = func;
		cvfs_errobj = obj;
	}
}

/* CRI pass 40: the target colours fname r29 > pdev r28 > tbl r27; ours removed pdev (28 neighbours) with
 * tbl in the same Chaitin iteration and coloured it after tbl. The pin to r11 - a register no value of this
 * function ever takes - is a codeless level-shifter: the physical neighbour holds pdev in the graph one
 * iteration longer, so it is coloured before tbl, and nothing else moves (a callee-saved pin reserves the
 * register and shifts the ResolveDev locals down one, pass 35's 20w). */
Sint32 cvFsGetFileSize(const Char8 *fname)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	register Char8 *pdev;
	CVFS_DEVIF *vtbl;

	if (fname == NULL) {
		cvfs_Error("cvFsGetFileSize #1:illegal file name");
		return 0;
	}
	cvfs_SplitFname(fname, dev, path);
	if (path[0] == '\0') {
		cvfs_Error("cvFsGetFileSize #1:illegal file name");
		return 0;
	}
	pdev = dev;
	 // COMPILER-DIFF: M1 (level-shifter, no code)
	vtbl = cvfs_ResolveDev(fname, pdev, path);
	if (dev == NULL) {
		cvfs_Error("cvFsGetFileSize #2:illegal device name");
	}
	if (vtbl == NULL) {
		cvfs_Error("cvFsGetFileSize #3:device not found");
	}
	if (vtbl->GetFileSize != NULL) {
		return vtbl->GetFileSize(path);
	}
	cvfs_Error("cvFsGetFileSize #4:vtbl error");
	return 0;
}

// Transfer state of a file handle from its device: 1 complete, 2 reading, 3 error (also for a bad
// handle).
Sint32 cvFsGetStat(CVFS_OBJ *obj)
{
	Sint32 stat = 3;

	if (obj == NULL) {
		cvfs_Error("cvFsGetStat #1:handle error");
		return 3;
	}
	if (obj->vtbl->GetStat != NULL) {
		stat = obj->vtbl->GetStat(obj->hn);
	} else {
		cvfs_Error("cvFsGetStat #2:vtbl error");
	}
	return stat;
}

// Runs every registered device's server (gcCiExecServer completes the DVD reads). Called twice per
// ADXT_ExecFsSvr.
void cvFsExecServer(void)
{
	Sint32 i;
	CVFS_DEV *dev;

	for (i = 0; i < CVFS_MAX_DEV; i++) {
		dev = &cvfs_tbl[i];
		if (dev->vtbl != NULL && dev->vtbl->ExecServer != NULL) {
			dev->vtbl->ExecServer();
		}
	}
}

// Cancels the handle's transfer on its device (DVDCancel for GCD).
void cvFsStopTr(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsStopTr #1:handle error");
		return;
	}
	if (obj->vtbl->StopTr != NULL) {
		obj->vtbl->StopTr(obj->hn);
	} else {
		cvfs_Error("cvFsStopTr #2:vtbl error");
	}
}

/* dead */
Sint32 cvFsReqWr(CVFS_OBJ *obj, Sint32 nsct, void *buf)
{
	Sint32 ret;

	if (obj == NULL) {
		cvfs_Error("cvFsReqWr #1:handle error");
		return 0;
	}
	if (obj->vtbl->x64 != NULL) {
		ret = obj->vtbl->OptFn(obj->hn, 20, nsct, (Sint32)buf);
	} else {
		ret = 0;
		cvfs_Error("cvFsReqWr #2:vtbl error");
	}
	return ret;
}

// Requests `nsct` sectors into `buf` from the device; returns the sectors accepted (0 = busy/refused).
// FUN_004E2170
Sint32 cvFsReqRd(CVFS_OBJ *obj, Sint32 nsct, void *buf)
{
	Sint32 ret;

	if (obj == NULL) {
		cvfs_Error("cvFsReqRd #1:handle error");
		return 0;
	}
	if (obj->vtbl->ReqRd != NULL) {
		ret = obj->vtbl->ReqRd(obj->hn, nsct, buf);
	} else {
		ret = 0;
		cvfs_Error("cvFsReqRd #2:vtbl error");
	}
	return ret;
}

// Seeks in sectors (type 0 set, 1 cur, 2 end); returns the new position.
// FUN_004E2108
Sint32 cvFsSeek(CVFS_OBJ *obj, Sint32 pos, Sint32 type)
{
	Sint32 ret;

	if (obj == NULL) {
		cvfs_Error("cvFsSeek #1:handle error");
		return 0;
	}
	if (obj->vtbl->Seek != NULL) {
		ret = obj->vtbl->Seek(obj->hn, pos, type);
	} else {
		ret = 0;
		cvfs_Error("cvFsSeek #2:vtbl error");
	}
	return ret;
}

// Current position in sectors.
// FUN_004E20A0
Sint32 cvFsTell(CVFS_OBJ *obj)
{
	Sint32 ret;

	if (obj == NULL) {
		cvfs_Error("cvFsTell #1:handle error");
		return 0;
	}
	if (obj->vtbl->Tell != NULL) {
		ret = obj->vtbl->Tell(obj->hn);
	} else {
		ret = 0;
		cvfs_Error("cvFsTell #2:vtbl error");
	}
	return ret;
}

// Closes the device handle and frees the CVFS slot.
void cvFsClose(CVFS_OBJ *obj)
{
	if (obj == NULL) {
		cvfs_Error("cvFsClose #1:handle error");
		return;
	}
	if (obj->vtbl->Close != NULL) {
		obj->vtbl->Close(obj->hn);
		obj->hn = NULL;
		obj->vtbl = NULL;
	} else {
		cvfs_Error("cvFsClose #2:vtbl error");
	}
}

/* a free handle slot */
static CVFS_OBJ *cvfs_AllocObj(void)
{
	CVFS_OBJ *obj; /* declared before i: the later-declared helper local ranks higher -> i r3, obj r4 */
	Sint32 i;

	obj = cvfs_obj;
	for (i = 0; i < CVFS_MAX_HN; i++) {
		if (obj->hn == NULL) {
			break;
		}
		obj++;
	}
	obj = &cvfs_obj[i];
	if (i == CVFS_MAX_HN) {
		obj = NULL;
	}
	return obj;
}

/* byte-identical since CRI pass 35 (the index-loop cvfs_SearchDev); pure C */
CVFS_OBJ *cvFsOpen(const Char8 *fname, void *dir, Sint32 rw)
{
	Char8 dev[CVFS_NAME_LEN];
	Char8 path[CVFS_NAME_LEN];
	Char8 *pdev;
	CVFS_OBJ *obj;
	CVFS_DEVIF *vtbl;
	void *hn;

	if (fname == NULL) {
		cvfs_Error("cvFsOpen #1:illegal file name");
		return NULL;
	}
	cvfs_SplitFname(fname, dev, path);
	if (path[0] == '\0') {
		cvfs_Error("cvFsOpen #1:illegal file name");
		return NULL;
	}
	hn = cvfs_AllocObj(); /* `void *` + typed kept copy: the inlined @ret stays in r3 and `mr r30, r3` survives (CRI pass 28, +4 bytes) */
	obj = hn;
	if (obj == NULL) {
		cvfs_Error("cvFsOpen #3:failed handle alloced");
		return NULL;
	}
	pdev = dev;
	vtbl = cvfs_ResolveDev(fname, pdev, path);
	obj->vtbl = vtbl;
	if (dev == NULL) {
		obj->hn = NULL;
		obj->vtbl = NULL;
		cvfs_Error("cvFsOpen #2:illegal device name");
		return NULL;
	}
	if (obj->vtbl == NULL) {
		obj->hn = NULL;
		obj->vtbl = NULL;
		cvfs_Error("cvFsOpen #4:device not found");
		return NULL;
	}
	if (obj->vtbl->Open != NULL) { /* the target reloads obj->vtbl (r3) for the Open call, not `vtbl` */
		obj->hn = obj->vtbl->Open(path, dir, rw);
	} else {
		obj->hn = NULL;
		obj->vtbl = NULL;
		cvfs_Error("cvFsOpen #5:vtbl error");
		return NULL;
	}
	if (obj->hn == NULL) {
		obj->hn = NULL;
		obj->vtbl = NULL;
		cvfs_Error("cvFsOpen #6:open failed");
		return NULL;
	}
	return obj;
}

// Sets the device used for names without a "DEV:" prefix (upper-cased, must be registered); "GCD"
// in this game.
void cvFsSetDefDev(Char8 *devname)
{
	Sint32 len;

	if (devname == NULL) {
		cvfs_Error("cvFsSetDefDev #1:illegal device name");
		return;
	}
	len = strlen(devname);
	if (len == 0) {
		cvfs_defdev[0] = '\0';
		return;
	}
	cvfs_StrUpr(devname);
	if (cvfs_IsExistDev(devname, len) == 1) {
		memcpy(cvfs_defdev, devname, len + 1);
	} else {
		cvfs_Error("cvFsSetDefDev #2:unknown device name");
	}
}

/* dead */
void cvFsDelDev(const Char8 *devname)
{
	Sint32 i;

	if (devname == NULL) {
		cvfs_Error("cvFsDelDev #1:illegal device name");
		return;
	}
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (strcmp(devname, cvfs_tbl[i].name) == 0) {
			cvfs_tbl[i].vtbl = NULL;
			cvfs_tbl[i].name[0] = '\0';
		}
	}
}

/* register the device in the table unless its name is already there; NULL when the table is full.
 * The `return vtbl` on the found path is the target's `beq add; b check` exit, the `void *` interface
 * pointer converted to the typed table entry is the kept copy that takes getif's result directly
 * (`mr r28, r3`; a fresh `vtbl = getif()` in the caller bounces through r0); CRI pass 13 */
static CVFS_DEVIF *cvfs_AddDevTbl(Char8 *devname, void *vt)
{
	CVFS_DEV *dev;
	Sint32 i;
	CVFS_DEVIF *vtbl = vt;

	if (cvfs_SearchDev(cvfs_tbl, devname) != NULL) {
		return vtbl;
	}
	dev = cvfs_tbl;
	for (i = 0; i < CVFS_MAX_DEV; i++) {
		if (dev->name[0] == '\0') {
			break;
		}
		dev++;
	}
	if (i == CVFS_MAX_DEV) {
		return NULL;
	}
	dev = &cvfs_tbl[i];
	dev->vtbl = vtbl;
	memcpy(dev->name, devname, strlen(devname) + 1);
	return vtbl;
}

// Registers a device by name (upper-cased) with its xxCiGetInterface function, and points the
// device's error callback at cvFsCallUsrErrFn. Called for "MFS" and "GCD" by ADXGC_SetupDvdFs.
void cvFsAddDev(Char8 *devname, CVFS_GETIFFN getif)
{
	Char8 *name;
	CVFS_DEVIF *vtbl;
	CVFS_GETIFFN fn;

	cvfs_build;
	/* kept copies (explicit casts, CRI pass 12 rule): devname r29 above the table entry r28, and the
	 * getif copy orders the two pool `lis` (rodata, then bss after `addi r30`) */
	name = (Char8 *)(void *)devname;
	fn = (CVFS_GETIFFN)(void *)getif;
	if (name == NULL) {
		cvfs_Error("cvFsAddDev #1:illegal device name");
		return;
	}
	if (fn == NULL) {
		cvfs_Error("cvFsAddDev #2:illegal I/F func name");
		return;
	}
	cvfs_StrUpr(name);
	vtbl = cvfs_AddDevTbl(name, fn());
	if (vtbl == NULL) {
		cvfs_Error("cvFsAddDev #3:failed added a device");
		return;
	}
	if (vtbl->EntryErrFunc != NULL) {
		vtbl->EntryErrFunc(cvFsCallUsrErrFn, NULL);
	}
}

/* the devices' error callback: forwards to the user's */
void cvFsCallUsrErrFn(void *obj, const Char8 *msg, void *hn)
{
	if (cvfs_errfn != NULL) {
		cvfs_errfn(cvfs_errobj, msg, hn);
	}
}
