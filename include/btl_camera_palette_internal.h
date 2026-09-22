#ifndef BTL_CAMERA_PALETTE_INTERNAL_H
#define BTL_CAMERA_PALETTE_INTERNAL_H

#include "type.h"

/* The four-byte RenderWare color layout shared by the camera and panel. */
typedef struct RwRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} BtlCameraPalette;

extern BtlCameraPalette D_007635C8;
extern BtlCameraPalette iGpffffb45c;

#endif
