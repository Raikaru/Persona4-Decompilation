/* CRI RNA renderer ARAM resources (rna_res.c, RNARES): a 256 KiB ARAM block (ARAlloc at init) split
 * into 32 buffers of 0x2000 bytes, one per AX voice of the AXRNA renderer; the voices loop over
 * these buffers while the server DMAs decoded PCM into them. Addresses are kept in 16-bit sample units. */
#include "cri_xpt.h"
#include <string.h>
#include <dolphin/ar.h>

extern void RNAERR_CallErrFunc(Char8 *msg);

#define RNARES_MAX_OBJ 32
#define RNARES_DEF_ARAM_SIZE 0x40000
#define RNARES_BUF_SIZE 0x2000

typedef struct {
	Sint32 used;   /* 0x0 */
	Uint32 buf;    /* 0x4 ARAM address / 2 */
	Uint32 size;   /* 0x8 */
} RNARES_OBJ;

typedef RNARES_OBJ *RNARES;

static Uint32 rnares_init_cnt = 0;
Uint32 rnares_setup_fg = 0;
static Uint32 rnares_nbuf = 0;
Uint32 rnares_aram_size = 0;
Uint32 rnares_aram_ptr = 0;
static RNARES_OBJ rnares_obj[RNARES_MAX_OBJ];

// Size of the resource's ARAM buffer in 16-bit samples (0x1000).
Sint32 RNARES_GetBufSize(RNARES res)
{
	if (res == NULL) {
		return 0;
	}
	return res->size;
}

// ARAM address of the buffer in 16-bit units (AX voices address samples).
Uint32 RNARES_GetBuf(RNARES res)
{
	if (res == NULL) {
		return 0;
	}
	return res->buf;
}

// Returns the buffer to the pool.
void RNARES_Destroy(RNARES res)
{
	if (res != NULL) {
		res->used = 0;
	}
}

// Takes one of the 32 preallocated ARAM buffers; error E1070313 when none is free.
RNARES RNARES_Create(void)
{
	RNARES res;
	Sint32 i;

	for (i = 0; i < RNARES_MAX_OBJ; i++) {
		if (rnares_obj[i].used == 0) {
			break;
		}
	}
	if (i == RNARES_MAX_OBJ) {
		RNAERR_CallErrFunc("E1070313:Not enough RNARES handle.\n");
		return NULL;
	}
	res = &rnares_obj[i];
	res->used = 1;
	return res;
}

// Frees the handles and, when the pool was allocated here (no RNARES_Setup), returns the 256 KiB ARAM
// block with ARFree, checking that nothing else was allocated after it.
void RNARES_Finish(void)
{
	Sint32 i;
	Uint32 size;

	if (--rnares_init_cnt == 0) {
		for (i = 0; i < RNARES_MAX_OBJ; i++) {
			if (rnares_obj[i].used == 1) {
				RNARES_Destroy(&rnares_obj[i]);
			}
		}
		memset(rnares_obj, 0, sizeof(rnares_obj));
		if (rnares_setup_fg == 0) {
			ARFree(&size);
			if (size != rnares_aram_size) {
				RNAERR_CallErrFunc("E1090601:Free area other than ADX buffer.\n");
			}
			rnares_nbuf = 0;
			rnares_aram_size = 0;
			rnares_aram_ptr = 0;
		}
	}
}

/* dead-stripped by the linker */
void RNARES_Setup(Uint32 aram_ptr, Sint32 aram_size)
{
	if (aram_ptr == 0) {
		RNAERR_CallErrFunc("E1070310:Illigal parameter(aram_ptr=null).\n");
		return;
	}
	if (aram_size <= 0) {
		RNAERR_CallErrFunc("E1070311:Illigal parameter(aram_size<=0).\n");
		return;
	}
	if (aram_size < RNARES_BUF_SIZE) {
		RNAERR_CallErrFunc("E1070312:Not enough aram_size.\n");
		return;
	}
	rnares_setup_fg = 1;
	rnares_aram_ptr = aram_ptr;
	rnares_aram_size = aram_size;
	rnares_nbuf = aram_size / RNARES_BUF_SIZE;
	if (rnares_nbuf > RNARES_MAX_OBJ) {
		rnares_nbuf = RNARES_MAX_OBJ;
	}
}

// Allocates 256 KiB of ARAM (ARAlloc) unless set up externally and carves it into 32 buffers of
// 0x2000 bytes, recording each as address/2 (sample units) and 0x1000 samples.
void RNARES_Init(void)
{
	/* The target numbers the loop's volatiles ofs r4, 0x1000 r5, ptr+ofs r6, ptr r7, res r8. The sum is
	 * an own local (`sum = ptr + ofs` kept as a variable by the `ofs +=` redefinition before its use).
	 * The 0x1000 is the own local `half` declared between ofs and sum: the frontend's flow-sensitive
	 * constant propagation substitutes a constant def that reaches its use alone (the `li` then becomes
	 * a backend temp with a vid above every own local, coloured before ofs -> r4/r5 swapped), so the
	 * codeless self copy `` (deleted by the RA, CRI pass 66) is a second, opaque
	 * def that keeps `half` a variable; the `li half` stays a statement of the preheader block. */
	register Uint32 ofs;
	register Uint32 half;
	Uint32 sum;
	register Uint32 ptr;
	Uint32 i;
	Uint32 n;
	RNARES_OBJ *res;

	if (rnares_init_cnt == 0) {
		if (rnares_setup_fg == 0) {
			rnares_nbuf = RNARES_MAX_OBJ;
			rnares_aram_size = RNARES_DEF_ARAM_SIZE;
			rnares_aram_ptr = ARAlloc(RNARES_DEF_ARAM_SIZE);
		}
		memset(rnares_obj, 0, sizeof(rnares_obj));
		n = rnares_nbuf;
		res = rnares_obj;
		ptr = rnares_aram_ptr;
		ofs = 0;
		half = RNARES_BUF_SIZE / 2;
		 // codeless second def (self copy)
		for (i = 0; i < n; i++, res++) {
			sum = ptr + ofs;
			ofs += RNARES_BUF_SIZE;
			res->buf = sum >> 1;
			res->size = half;
		}
	}
	rnares_init_cnt++;
}
