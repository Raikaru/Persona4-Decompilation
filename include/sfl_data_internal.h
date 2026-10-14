#ifndef SFL_DATA_INTERNAL_H
#define SFL_DATA_INTERNAL_H

#include "type.h"

/* Battle panel setup and work-clearing routines defined in sfl_data.c. */
/* Clears a panel work block and sets its default scale and colour. */
void sflDataInitPanel(u8 *work);
/* Initialises a type-0 panel and fills its full corner layout. */
void sflDataSetupLayoutPanel(void *work);
/* Initialises a type-1 panel and fills its outer, inner and centre corners. */
void sflDataSetupFramePanel(void *work);
/* Initialises a type-2 panel and fills its four corners. */
void sflDataSetupQuadPanel(void *work);

#endif
