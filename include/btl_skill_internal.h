#ifndef BTL_SKILL_INTERNAL_H
#define BTL_SKILL_INTERNAL_H

#include "type.h"

/* Four-byte skill records; the flags occupy the upper halfword. */
typedef struct BtlSkillFlags {
    u16 info;
    u16 flags;
} BtlSkillFlags;

extern BtlSkillFlags *iGpffffb3bc;

#endif
