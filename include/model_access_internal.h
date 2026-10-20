#ifndef MODEL_ACCESS_INTERNAL_H
#define MODEL_ACCESS_INTERNAL_H

#include "rw_types_internal.h"

/* mdlManager.c: the matrix is the model prefix; the clump is at 0xDC. */
typedef struct Model Model;
void *mdlGetMatrix(void *model);
void *mdlGetClump(void *model);
void mdlSetColor(Model *model, const RwRGBA *color);

#endif
