#ifndef SHD_SKILL_INTERNAL_H
#define SHD_SKILL_INTERNAL_H

#include "type.h"

/* Skill rows are copied as three floats; ID/cost consumers establish the
 * alternate interpretation of those same twelve bytes. */
typedef struct ShdSkillVector { f32 x, y, z; } ShdSkillVector;
typedef union ShdSkillEntry {
    ShdSkillVector vector;
    struct { u16 tag, id; u32 first, second; } fields;
} ShdSkillEntry;
typedef struct ShdSkillDescriptor {
    s16 kind, style, flags;
    ShdSkillEntry data;
} ShdSkillDescriptor;

/* Active rows occupy 8*12 bytes. Pool deletion shifts at most 32 rows and
 * their parallel halfword values; counts are at +0x60 and +0x224. */
typedef struct ShdSkillPool {
    ShdSkillEntry active[8];
    u16 activeCount;
    s8 markedSlots;
    u8 unk63;
    ShdSkillEntry pending[32];
    u16 values[32];
    u16 pendingCount;
    u8 pad226[6];
} ShdSkillPool;
typedef struct ShdSkillState {
    u8 pad0[4];
    s8 cursor;
    s8 previousCursor;
    u8 pad6[2];
    ShdSkillPool pool;
} ShdSkillState;

#endif
