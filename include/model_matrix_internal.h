#ifndef MODEL_MATRIX_INTERNAL_H
#define MODEL_MATRIX_INTERNAL_H

#include "type.h"

/* The model wrapper forwards these storage addresses to the native matrix API. */
void mdlRotateMatrix(void *matrix, const void *axis, f32 angle, s32 combineOp);

#endif
