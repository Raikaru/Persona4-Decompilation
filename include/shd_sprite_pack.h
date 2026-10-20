#ifndef SHD_SPRITE_PACK_H
#define SHD_SPRITE_PACK_H

#include "type.h"

/* sdkSpritePackCreate in shdSprite.c allocates this 0x14-byte prefix before
 * its copied descriptor, names, sprite pointers and optional remap records.
 * This is the wrapper pack, not the 0x240-byte SDK sprite container. */
typedef struct ShdSpriteDescriptor ShdSpriteDescriptor;
typedef struct ShdSpriteRemap ShdSpriteRemap;
typedef struct ShdSpritePack {
    s32 loadIndex;
    ShdSpriteDescriptor *descriptor;
    u8 **sprites;
    ShdSpriteRemap *remap;
    s32 remapCount;
} ShdSpritePack;

typedef char ShdSpritePackSize[sizeof(ShdSpritePack) == 0x14 ? 1 : -1];

#endif
