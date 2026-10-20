#ifndef G_DATA_ENTRY_INTERNAL_H
#define G_DATA_ENTRY_INTERNAL_H

#include "type.h"

/* The item metadata table uses 0x44-byte records. */
typedef struct GDataEntry {
    u32 kind;
    u32 flags;
    u16 primaryValue;
    u16 secondaryValue;
    u8 unk0C;
    u8 unk0D;
    u8 property;
    u8 unk0F;
    u16 middleBandValue;
    u16 lastBandValue;
    u8 unk14[0x10];
    u32 grantedSkill;
    u16 value;
    u16 accessoryPercent;
    u16 element;
    u16 unk2E;
    u32 categoryMask;
    u32 price;
    s8 availableMonth;
    s8 availableDay;
    u8 unk3A;
    u8 unk3B;
    u32 firstMoonGate;
    u32 secondMoonGate;
} GDataEntry;

#endif
