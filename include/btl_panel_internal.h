#ifndef BTL_PANEL_INTERNAL_H
#define BTL_PANEL_INTERNAL_H

#include "type.h"

// Intent: draw a battle sprite with per-channel colour and fade parameters. [inferred]
void btlUiDrawSpriteFaded(u8 *work, s32 slot, s32 segment, f32 x, f32 y,
                   u8 red, u8 green, u8 blue, u8 opacity);
// Intent: return the scaled sprite width for a UI component slot. [inferred]
f32 btlUiSpriteWidth(u8 *work, s32 slot, s32 segment);
// Intent: return the scaled sprite height for a UI component slot. [inferred]
f32 btlUiSpriteHeight(u8 *work, s32 slot, s32 segment);
// Intent: read the selection input and return the action code (1 to 4) or 0. [inferred]
s32 btlSelectionReadInput(u8 *input);
void btlEncounterEntrySetActive(u8 *view);
void btlEncounterEntryClearActive(u8 *view);

void btlGaugeDrawUnit(s32 task, u8 *unit, f32 x, f32 y, s32 visible, f32 hpRatio);

#endif
