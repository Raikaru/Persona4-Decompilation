/* CRI Sofdec MW player resource save/restore hooks (mwsfdrsc.c): called around the wait for the
 * decode-server border; empty on GameCube. */
#include "cri_xpt.h"

// No-op on GameCube.
void mwPlyRestoreRsc(void)
{
}

// No-op on GameCube.
void mwPlySaveRsc(void)
{
}
