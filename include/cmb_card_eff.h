#ifndef CMB_CARD_EFF_H
#define CMB_CARD_EFF_H

#include "fcl_draw_types.h"
#include "fcl_color.h"

/* Starts a card effect's move toward a world position. The Vec3 is passed
   by value: the caller builds a copy and passes its address in $a1. */
void cmbCardEffSpawnSprite(u8 *task, FclVec3 position, f32 rotationX, f32 rotationY, f32 rotationZ, f32 scale,
                   FclDrawColor color, u16 duration, u32 lifetime);

#endif
