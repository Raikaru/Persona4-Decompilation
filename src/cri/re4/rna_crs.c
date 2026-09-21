/* CRI GameCube renderer critical section (rna_crs.c): AXRNA's lock around the AX/MIX voice calls,
 * mapped to the stream-joint lock (SJCRS). */
#include "cri_xpt.h"

extern void SJCRS_Lock(void);
extern void SJCRS_Unlock(void);

static Sint32 gcrna_cs_lvl;
static Sint32 gcrna_cs_msk;

// Leaves the renderer critical section.
void GCRNA_UnlockCs(void)
{
	SJCRS_Unlock();
}

// Enters the renderer critical section.
void GCRNA_LockCs(void)
{
	SJCRS_Lock();
}
