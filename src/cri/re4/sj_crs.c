/* CRI stream-joint critical section (sj_crs.c, SJCRS): the real lock of the CRI stack on GameCube.
 * Disables interrupts on the first nesting level (OSDisableInterrupts) and restores them on the last
 * unlock; every stream-joint operation, the renderer's AX calls and the load scheduler run inside it. */
#include "cri_xpt.h"

extern Bool OSDisableInterrupts(void);
extern Bool OSRestoreInterrupts(Bool level);

volatile Sint32 sjcrs_lvl = 0;
static Sint32 sjcrs_msk = 0;

// Leaves one nesting level; restores the interrupt state saved by the outermost lock.
void SJCRS_Unlock(void)
{
	sjcrs_lvl--;
	if (sjcrs_lvl == 0) {
		OSRestoreInterrupts(sjcrs_msk);
	}
}

// Enters one nesting level; disables interrupts on the outermost lock.
void SJCRS_Lock(void)
{
	if (sjcrs_lvl == 0) {
		sjcrs_msk = OSDisableInterrupts();
	}
	sjcrs_lvl++;
}
