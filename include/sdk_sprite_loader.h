#ifndef SDK_SPRITE_LOADER_H
#define SDK_SPRITE_LOADER_H

#include "type.h"

/* Register the in-memory sprite data and return its allocated loader node. */
u8 *sdkSpriteAdoptBlob(u32 blobAddress);

#endif
