/* CRI SFA (streamed file archive) module stub (adx_sfa.c): only the reference counter survives. */
#include "cri_xpt.h"

static Sint32 sfa_init_cnt;
static Sint32 sfa_work;

// Decrements the SFA user count.
void SFA_Finish(void)
{
	sfa_init_cnt--;
}

// Increments the SFA user count.
void SFA_Init(void)
{
	sfa_init_cnt++;
}
