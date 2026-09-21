/* CRI Sofdec condition table (sfd_set.c): the 100 Sint32 "conditions" of a handle (cond[] with the
 * defaults cond_def[]) are the decoder's settings and hooks: 5 video on, 6 audio on, 9 sync mode,
 * 15 clock source, 0x19 termination mode, 0x24/0x25 picture hooks, 0x4B/0x4C header callback, ...
 * Also the raw player information copy and the handle state query. */
#include "cri_xpt.h"
#include "sfd.h"

// Driver `strm`'s handle (e.g. 3 -> the ADXT audio driver work), NULL when the driver is not set up.
Sint32 SFD_GetTrHn(SFD sfd, Sint32 strm, void **hn)
{
	void **trhn;

	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000117);
	}
	trhn = sfd->tr[strm].hn;
	if (trhn == NULL) {
		*hn = NULL;
	} else {
		*hn = *trhn;
	}
	return 0;
}

// Copy of the player information block (decoded/skipped picture counts, 64-bit stream counters).
Sint32 SFD_GetPlyInf(SFD sfd, SFD_PLYINF *inf)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		return SFLIB_SetErr(NULL, 0xFF000119);
	}
	*inf = sfd->plyinf;
	return 0;
}

// Raw condition read (no handle check).
Sint32 SFSET_GetCond(SFD sfd, Sint32 id)
{
	return sfd->cond[id];
}

// Condition `id` of the handle, or the library default when sfd is NULL.
Sint32 SFD_GetCond(SFD sfd, Sint32 id, Sint32 *val)
{
	if (sfd == NULL) {
		*val = SFLIB_libwork.cond[id];
	} else {
		if (SFLIB_CheckHn(sfd) != 0) {
			return SFLIB_SetErr(NULL, 0xFF000113);
		}
		*val = sfd->cond[id];
	}
	return 0;
}

// Video (5) / audio (6) cannot be enabled on a handle whose video (tr 2) / audio (tr 3) driver is absent.
static Sint32 sfset_IsSettable(SFD sfd, Sint32 id, Sint32 val)
{
	Sint32 ok;

	if (id == 6 && val == 1 && SFTRN_IsSetup(sfd, 3) == 0) {
		ok = 0;
	} else if (id == 5 && val == 1 && SFTRN_IsSetup(sfd, 2) == 0) {
		ok = 0;
	} else {
		ok = 1;
	}
	return ok;
}

// Sets a condition of the handle if allowed.
void SFSET_SetCond(SFD sfd, Sint32 id, Sint32 val)
{
	if (sfset_IsSettable(sfd, id, val)) {
		sfd->cond[id] = val;
	}
}

// Sets the handle's default value of a condition (restored by a reset).
static void sfset_SetCondDef(SFD sfd, Sint32 id, Sint32 val)
{
	if (sfset_IsSettable(sfd, id, val)) {
		sfd->cond_def[id] = val;
	}
}

/* The byte offset id*4 is an own local declared last (coloured after hn/i/p, so it takes the dead
 * sfd register r28); spelled `id << 2` it stays an arithmetic-defined variable that the frontend CSE
 * reuses for the inlined SFSET_SetCond index, where `id * 4` becomes a hoisted temporary (r31). */
Sint32 SFD_SetCond(SFD sfd, Sint32 id, Sint32 val)
{
	SFD hn;
	Sint32 i;
	SFD *p;
	Sint32 ofs;

	if (sfd == NULL) {
		p = SFLIB_libwork.hn;
		ofs = id << 2;
		for (i = 0; i < 8; i++, p++) {
			hn = *p;
			if (SFLIB_CheckHn(hn) == 0) {
				SFSET_SetCond(hn, id, val);
			}
		}
		*(Sint32 *)((Uint8 *)SFLIB_libwork.cond + ofs) = val; /* SFLIB_libwork.cond[id] = val */
	} else {
		if (SFLIB_CheckHn(sfd) != 0) {
			return SFLIB_SetErr(NULL, 0xFF000112);
		}
		SFSET_SetCond(sfd, id, val);
		sfset_SetCondDef(sfd, id, val);
	}
	return 0;
}

// Handle state: 1 stop, 2 prep, 3 standby, 4 playing, 6 playend, negative after an error.
// FUN_00524D50
Sint32 SFD_GetHnStat(SFD sfd)
{
	if (SFLIB_CheckHn(sfd) != 0) {
		SFLIB_SetErr(NULL, 0xFF000111);
	}
	return sfd->stat;
}
