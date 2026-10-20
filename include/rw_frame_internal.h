#ifndef RW_FRAME_INTERNAL_H
#define RW_FRAME_INTERNAL_H

#include "rw_camera_internal.h"

/* SDK baframe.h prefix through the modelling and world matrices.
 * Object lists, hierarchy links and plugins follow this prefix. */
typedef struct RwFrame {
    RwObject object;
    void *dirtyNext;
    void *dirtyPrevious;
    RwMatrixTag modelling;
    RwMatrixTag ltm;
} __attribute__((aligned(16))) RwFrame;

#endif
