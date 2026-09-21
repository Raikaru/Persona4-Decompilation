/* CRI Sofdec MW player seek support stubs (mwsfdsee.c): the seek feature is not built into this
 * player, so the hooks the start/server paths call are empty. */
#include "cri_xpt.h"

// No-op (seek support absent).
void MWSFSEE_ChkSupply(void)
{
}

// No-op.
void MWSFSEE_StartFnameSub2(void)
{
}

// No-op.
void MWSFSEE_StartFnameSub1(void)
{
}
