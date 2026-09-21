/* CRI Sofdec SFX alpha tables (sfx_alp.c, SFXA): per-converter alpha ramp settings (three fixed
 * alpha levels or a luma-driven ramp between lumi_min/lumi_max) and the calls that build the
 * ARGB8888 conversion tables from them (cftyp422_ppc.c). Used for the alpha component layouts
 * (0x31/0x41/0x51/0x61); the game's movies are plain YCC 4:2:0. */
#include "cri_xpt.h"
#include <string.h>

typedef struct {
	Sint32 used;         /* 0x00 */
	Sint32 need_update;  /* 0x04 */
	Sint32 lumi_min;     /* 0x08 */
	Sint32 lumi_max;     /* 0x0C */
	Sint32 lumi_rate;    /* 0x10 */
	Uint8 alp0;          /* 0x14 */
	Uint8 alp1;          /* 0x15 */
	Uint8 alp2;          /* 0x16 */
	Uint8 pad17;
} SFXA_OBJ;

typedef struct {
	Sint32 cnt;
	Sint32 nobj;
	SFXA_OBJ obj[8];
} SFXA_WORK;

extern void CFT_MakeArgb8888Alp3211Tbl(void *tbl, Uint8 a0, Uint8 a1, Uint8 a2);
extern void CFT_MakeArgb8888Alp3110Tbl(void *tbl, Uint8 a0, Uint8 a1, Uint8 a2);
extern void CFT_MakeArgb8888AlpLumiTbl(Sint32 min, Sint32 max, Sint32 rate, void *tbl);

SFXA_WORK sfxa_work;

// Whether the luma-alpha settings changed since the table was last built.
Sint32 SFXA_IsNeedUpdateLumiTbl(SFXA_OBJ *sfxa)
{
	return sfxa->need_update;
}

// Builds the ARGB table with the "3211" three-level alpha ramp (alp0/alp1/alp2).
void SFXA_MakeAlp3211Tbl(SFXA_OBJ *sfxa, void *frm, void *tbl)
{
	CFT_MakeArgb8888Alp3211Tbl(tbl, sfxa->alp0, sfxa->alp1, sfxa->alp2);
}

// Builds the ARGB table with the "3110" three-level alpha ramp.
void SFXA_MakeAlp3110Tbl(SFXA_OBJ *sfxa, void *frm, void *tbl)
{
	CFT_MakeArgb8888Alp3110Tbl(tbl, sfxa->alp0, sfxa->alp1, sfxa->alp2);
}

// Builds the ARGB table with alpha following the luma (lumi_min..lumi_max, rate); clears the update flag.
void SFXA_MakeAlpLumiTbl(SFXA_OBJ *sfxa, void *frm, void *tbl)
{
	CFT_MakeArgb8888AlpLumiTbl(sfxa->lumi_min, sfxa->lumi_max, sfxa->lumi_rate, tbl);
	sfxa->need_update = 0;
}

// Frees the object.
void SFXA_Destroy(SFXA_OBJ *sfxa)
{
	if (sfxa == NULL) {
		return;
	}
	sfxa->used = 0;
	sfxa_work.cnt--;
}

// First unused of the 8 objects, NULL when none.
static SFXA_OBJ *sfxa_search_free(void)
{
	SFXA_OBJ *sfxa;
	Sint32 i;

	sfxa = sfxa_work.obj;
	for (i = 0; i < sfxa_work.nobj; i++) {
		if (sfxa->used == 0) {
			return sfxa;
		}
		sfxa++;
	}
	return NULL;
}

/* The original numbers its constants zero r8, 0x1F r5, 100 r0, 1 r7, 0x7F r6, 0xFF r0 and the
 * sfxa_work address r4/r5. The colouring needs `li 0xFF` issued AFTER `stw 100` in the pre-RA
 * schedule (100 and 0xFF share r0), which plain constants never do (`li 0xFF` wins the slot on
 * height): 100 and 0xFF are the two defs of ONE variable `k`, so the second `li k` has a WAR edge
 * on the first store. The frontend range-splits a redefined local into a new web unless the local
 * is referenced in asm, and substitutes every constant def, so `k` is seeded with the codeless
 * self copy `` after each def (deleted by the backend before scheduling); the
 * other constants are `addi` derivations of k with two uses each (kept as own locals, folded to
 * `li` by backend constant propagation) declared in the target's colouring order. */
SFXA_OBJ *SFXA_Create(void)
{
	SFXA_OBJ *sfxa;
	register Sint32 k; /* 100, then 0xFF */
	Sint32 k7f;
	Sint32 one;
	Sint32 k1f;
	Sint32 zero;

	sfxa = sfxa_search_free();
	if (sfxa == NULL) {
		return sfxa;
	}
	k = 100;
	
	k7f = k + (0x7F - 100);
	k1f = k7f - (0x7F - 0x1F);
	zero = k1f - 0x1F;
	sfxa->lumi_min = zero;
	sfxa->lumi_max = k1f;
	sfxa->lumi_rate = k;
	k += 0xFF - 100;
	
	one = k - 0xFE;
	sfxa->need_update = one;
	sfxa->alp0 = zero;
	sfxa->alp1 = k7f;
	sfxa->alp2 = k;
	sfxa_work.cnt++;
	sfxa->used = one;
	return sfxa;
}

// Clears the object table (8 objects).
void SFXA_Init(void)
{
	memset(&sfxa_work, 0, sizeof(sfxa_work));
	sfxa_work.nobj = 8;
}
