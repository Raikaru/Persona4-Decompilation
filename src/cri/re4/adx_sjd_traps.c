/* Trap-counter view of ADXSJD_OBJ; the three fields start at offsets 0x3c, 0x40 and 0x44. */
#include "cri_xpt.h"

typedef struct {
	Uint8 preceding[0x3c];
	Sint32 dtrpsmpl;
	Sint32 dtrpcnt;
	Sint32 dtrpdtlen;
} ADXSJD_TrapCounters;

// FUN_004CED48
void ADXSJD_SetTrapNumSmpl(ADXSJD_TrapCounters *sjd, Sint32 nsmpl)
{
	sjd->dtrpsmpl = nsmpl;
}

// FUN_004CED50
Sint32 func_004ced50(ADXSJD_TrapCounters *sjd)
{
	return sjd->dtrpsmpl;
}

// FUN_004CED58
void ADXSJD_SetTrapCnt(ADXSJD_TrapCounters *sjd, Sint32 cnt)
{
	sjd->dtrpcnt = cnt;
}

// FUN_004CED60
Sint32 func_004ced60(ADXSJD_TrapCounters *sjd)
{
	return sjd->dtrpcnt;
}

// FUN_004CED68
void ADXSJD_SetTrapDtLen(ADXSJD_TrapCounters *sjd, Sint32 len)
{
	sjd->dtrpdtlen = len;
}

// FUN_004CED70
Sint32 func_004ced70(ADXSJD_TrapCounters *sjd)
{
	return sjd->dtrpdtlen;
}
