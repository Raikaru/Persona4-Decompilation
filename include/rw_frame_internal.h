#ifndef RW_FRAME_INTERNAL_H
#define RW_FRAME_INTERNAL_H

#include "rw_camera_internal.h"

/* SDK baframe.h prefix through modelling (0x10); field code never sizes a frame.
 * The world matrix, object list, hierarchy links and plugins follow this prefix. */
typedef struct RwFrame {
    RwObject object;
    void *dirtyNext;
    void *dirtyPrevious;
    RwMatrixTag modelling;
} __attribute__((aligned(16))) RwFrame;

#endif
