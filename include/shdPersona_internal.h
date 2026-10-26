#ifndef SHDPERSONA_INTERNAL_H
#define SHDPERSONA_INTERNAL_H

#include "type.h"

/* Persona block writers defined in src/shdPersona.c. `task` is the owning
 * SdkTask; the value lands in the persona block at +0x44 (handle value) or
 * +0x4C4 (extra value). */
void shdPersonaSetHandleValue(int task, u32 value);
void shdPersonaSetExtraValue(int task, u32 value);
/* Primitive queue dispatch supplies the node, then its Persona work argument. */
void shdPersonaDrawPanels(u8 *node, u8 *work);

/* Work block of the level-up child task (shdPersonaLevelUpCreate, 0x58 bytes). */
typedef struct ShdPersonaLevelUpWork ShdPersonaLevelUpWork;
struct ShdPersonaLevelUpWork {
    u8 reserved_00[2];
    u16 cursor;             /* +0x02 */
    u16 frame;              /* +0x04 */
    u16 previousSkill;      /* +0x06 */
    u16 replacement;        /* +0x08 */
    u8 reserved_0a[2];
    s32 field0C;            /* +0x0C */
    s32 index;              /* +0x10: row of the learn list being shown */
    s32 state;              /* +0x14: 0xE once the level-up has finished */
    u8 *messageTask;        /* +0x18: child message task, destroyed with the block */
    struct SdkTask *parentTask; /* +0x1C: task that owns the persona block */
    u8 *learnList;          /* +0x20: level-learn table read by personaLevelRow */
    s32 parameter3;         /* +0x24 */
    s32 parameter4;         /* +0x28 */
    s32 messages[0xB];      /* +0x2C: message ids copied from the caller */
};

/* Work block of the skill-replace child task (shdPersonaSkillReplaceCreate, 0x44 bytes). */
typedef struct ShdPersonaSkillReplaceWork ShdPersonaSkillReplaceWork;
struct ShdPersonaSkillReplaceWork {
    u16 counter;            /* +0x00: frame counter for the confirmation delay */
    u16 field02;            /* +0x02 */
    u16 original;           /* +0x04: skill being replaced */
    u16 replacement;        /* +0x06: skill that takes its slot */
    s32 state;              /* +0x08 */
    u8 *parent;             /* +0x0C: parent task work block */
    u8 reserved_10[4];
    s32 messageHandle;      /* +0x14 */
    s32 messages[0xB];      /* +0x18: message ids copied from the caller */
};

#endif
