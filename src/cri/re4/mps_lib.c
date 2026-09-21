/* Sofdec MPEG system stream demultiplexer: handle management */
#include "cri_xpt.h"
#include "mps.h"

void UTY_MemsetDword(void *dst, Uint32 val, Sint32 ndword);
Sint32 MPSDEC_DecHdMpeg1();
void MPSDEC_Init(void);
void MPSDEC_Finish(void);
void MPSGET_Init(void);
void MPSGET_Finish(void);

const Char8 MPSLIB_version_str[] =
	"\nCRI MPS/GC Ver.1.924 Build:Sep 22 2004 10:34:52\n\0Append: MW2407 GC20Apr2004Patch1\n";

static MPS mpslib_hn_last;
static const Char8 *cri_verstr_ptr;
MPSLIB_WORK *MPSLIB_libwork;
/* unreferenced: MWCC still emits it, after the referenced statics (.bss 0x10, the target's fourth word) */
static Sint32 mpslib_init_cnt;

/* inlined copies; the public MPSLIB_CheckHn/MPSLIB_SetErr wrap them further down */
static Sint32 mpslib_CheckHn(MPS mps)
{
	mpslib_hn_last = mps;
	if (mps == NULL) {
		return -1;
	}
	if (mps->used == MPS_HN_FREE) {
		return -1;
	}
	return 0;
}

/* dead-stripped by the linker; puts cri_verstr_ptr before MPSLIB_libwork in .bss */
const Char8 *MPS_GetVerStr(void)
{
	cri_verstr_ptr = MPSLIB_version_str;
	return MPSLIB_version_str;
}

/* Library-level error (no handle): the callback gets the code as its second argument here (the
 * target materialises the code straight into r4 and keeps it live into the bctrl, which is what puts
 * the libwork pointer in r5 and lets the peephole fold `lwz r5, MPSLIB_libwork@l(r4)`); the public
 * MPSLIB_SetErr below passes the object only. */
typedef void (*MPSLIB_ERRFN2)(void *obj, Sint32 code);

// Library-level error: records the code and calls the library error callback with it.
static Sint32 mpslib_SetLibErr(Sint32 code)
{
	MPSLIB_WORK *lw;

	lw = MPSLIB_libwork;
	lw->errcode = code;
	if (code != 0 && lw->errfn != NULL) {
		((MPSLIB_ERRFN2)lw->errfn)(lw->errobj, code);
	}
	return code;
}

// Records an error code on the handle (or the library) and calls the matching error callback; the
// SFD demux driver's callback turns it into an SFD error.
static Sint32 mpslib_SetErr(MPS mps, Sint32 code)
{
	MPSLIB_WORK *lw;

	if (mps == NULL) {
		lw = MPSLIB_libwork;
		lw->errcode = code;
		if (code != 0 && lw->errfn != NULL) {
			lw->errfn(lw->errobj);
		}
	} else {
		mps->errcode = code;
		if (code != 0 && mps->errfn != NULL) {
			mps->errfn(mps->errobj);
		}
	}
	return code;
}

// Frees the parser handle.
Sint32 MPS_Destroy(MPS mps)
{
	if (mpslib_CheckHn(mps) != 0) {
		return mpslib_SetLibErr(0xFF020103);
	}
	mps->used = MPS_HN_FREE;
	return 0;
}

// First free handle of the library work, NULL when all are used.
static MPS mpslib_GetFreeHn(void)
{
	MPSLIB_WORK *lw;
	MPS mps;
	Sint32 i;

	lw = MPSLIB_libwork;
	mps = lw->hn;
	for (i = 0; i < lw->num_hn; i++) {
		if (mps->used == MPS_HN_FREE) {
			return mps;
		}
		mps++;
	}
	return NULL;
}

// Takes a free handle: cleared, headers marked "not seen" (-1), MPEG-1 header decoder installed.
MPS MPS_Create(void)
{
	MPS mps;
	Sint32 i;

	mps = mpslib_GetFreeHn();
	if (mps == NULL) {
		return NULL;
	}
	UTY_MemsetDword(mps, 0, sizeof(MPS_OBJ) / 4);
	mps->used = MPS_HN_USED;
	mps->errfn = NULL;
	mps->errobj = NULL;
	mps->errcode = 0;
	mps->x10 = 2;
	mps->packhd.scr = -1;
	mps->packhd.rsv = -1;
	mps->packhd.mux_rate = -1;
	for (i = 0; i < 8; i++) {
		mps->last_syshd.raw[i] = -1;
	}
	/* three separate loops: a nested i/j form leaves the outer counter's dead `li i,0` in the
	 * block for the register allocator to delete, which dirties the block and lets the post-RA
	 * scheduler swap `li r4,-1` / `addi r0,..@l` */
	for (i = 0; i < 8; i++) {
		mps->syshd[0].raw[i] = -1;
	}
	for (i = 0; i < 8; i++) {
		mps->syshd[1].raw[i] = -1;
	}
	for (i = 0; i < 8; i++) {
		mps->syshd[2].raw[i] = -1;
	}
	mps->pkethd.pts = -1;
	mps->pkethd.dts = -1;
	for (i = 0; i < 6; i++) {
		mps->pkethd.raw[i] = -1;
	}
	mps->xd0 = 0;
	mps->dechd_func = MPSDEC_DecHdMpeg1;
	mps->xd8 = 0;
	mps->xdc = 0;
	mps->xe0 = 0;
	mps->sysfn = 0;
	mps->sysobj = 0;
	return mps;
}

// -1 for a NULL or free handle; records it in mpslib_hn_last.
Sint32 MPSLIB_CheckHn(MPS mps)
{
	mpslib_hn_last = mps;
	if (mps == NULL) {
		return -1;
	}
	if (mps->used == MPS_HN_FREE) {
		return -1;
	}
	return 0;
}

// Installs the error callback library-wide (mps NULL) or per handle.
Sint32 MPS_SetErrFn(MPS mps, void (*fn)(void *obj), void *obj)
{
	MPSLIB_WORK *lw;

	if (mps == NULL) {
		lw = MPSLIB_libwork;
		lw->errfn = fn;
		lw->errobj = obj;
	} else {
		if (mpslib_CheckHn(mps) != 0) {
			return mpslib_SetLibErr(0xFF020101);
		}
		mps->errfn = fn;
		mps->errobj = obj;
	}
	return 0;
}

// Public error report (mpslib_SetErr).
Sint32 MPSLIB_SetErr(MPS mps, Sint32 code)
{
	return mpslib_SetErr(mps, code);
}

// Destroys every used handle and finishes the sub-modules.
void MPS_Finish(void)
{
	MPSLIB_WORK *lw;
	MPS mps;
	Sint32 i;
	Sint32 num;

	lw = MPSLIB_libwork;
	num = lw->num_hn;
	mps = lw->hn;
	for (i = 0; i < num; i++) {
		if (mps->used != MPS_HN_FREE) {
			MPS_Destroy(mps);
		}
		mps++;
	}
	MPSDEC_Finish();
	MPSGET_Finish();
}

/* the handle clear loop as an inlined helper: its counter is a temporary that shares the zero
 * register of the three libwork clears (a caller-level `i` keeps its own `li`), and the handle
 * argument expression ranks above the unroller's temporaries (`addi r4, r3, 0x10`). It returns a
 * status that is always 0: the caller's `if (ret != 0) return ret;` survives the frontend and is
 * folded by the backend, leaving the target's dead `b .Lcalls; b .Lreturn` pair after the loop and
 * the `li r3, 0` at the head of the return block */
static Sint32 mpslib_ClrHn(MPS hn, Sint32 num)
{
	Sint32 i;

	for (i = 0; i < num; i++) {
		hn[i].used = MPS_HN_FREE;
	}
	return 0;
}

// Library init in the caller's work: endianness self-check (spins on little-endian), header +
// `num_hn` handles all free.
Sint32 MPS_Init(Sint32 num_hn, void *work)
{
	static const Uint32 test_wrok = 0x01020304;
	MPSLIB_WORK *lw;
	Sint32 ret;

	cri_verstr_ptr = MPSLIB_version_str;
	if (*(const Uint8 *)&test_wrok != 1) {
		for (;;) {
			((void (*)(void))-1)();
		}
	}
	MPSLIB_libwork = (MPSLIB_WORK *)work;
	UTY_MemsetDword(work, 0, (sizeof(MPSLIB_WORK) + (num_hn - 1) * sizeof(MPS_OBJ)) / 4);
	lw = MPSLIB_libwork;
	lw->errfn = NULL;
	lw->errobj = NULL;
	lw->errcode = 0;
	MPSLIB_libwork->num_hn = num_hn;
	ret = mpslib_ClrHn(MPSLIB_libwork->hn, num_hn);
	if (ret != 0) {
		return ret;
	}
	MPSDEC_Init();
	MPSGET_Init();
	return 0;
}
