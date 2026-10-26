#ifndef K_TEXSTRIP_INTERNAL_H
#define K_TEXSTRIP_INTERNAL_H

#include "type.h"

/* Debug-menu commands supply a context word; these root-task constructors
 * do not consume it. */
s32 K_TexStripBuildTaskCreate(s32 unusedContext);
s32 K_TexStripCodeLogTaskCreate(s32 unusedContext);
s32 K_TexStripLoadTaskCreate(s32 unusedContext);

#endif
