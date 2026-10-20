#ifndef FCL_ROW_MODE_H
#define FCL_ROW_MODE_H

#include "fcl_row_draw.h"

/* All row-mode consumers test or forward the same signed byte. */
void fclCombineDrawStageBanner(u8 *task, s32 stage, s8 mode);

#endif
