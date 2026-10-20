#ifndef DAT_SKILL_ENTRY_INTERNAL_H
#define DAT_SKILL_ENTRY_INTERNAL_H

#include "type.h"

/* One row of the skill table (iGpffffb3b8), stride 0x28, indexed by skill id. The
   table is read as u8 bytes in datCalc.c. Offsets are named by the
   code that reads them; roles marked [inferred] are not yet pinned. Typed access
   moves codegen where the constant offset folds (datCalc.c), so most sites stay raw. */
typedef struct DatSkillEntry
{
    u8 flags00;         // 0x00. Bit 0x2 (skill is used), bit 0x40 (not applied to a target).
    u8 flags01;         // 0x01. Bit 0x2.
    u8 damageClass;     // 0x02. 1 physical, 2 magic; selects the datScriptRunCalc formula (datCalcSkillAmount, datCalcHitResult).
    u8 kind03;          // 0x03. Switch selector for the skill effect kind.
    u8 unknown04[0x0A]; // 0x04..0x0D
    u8 accuracy;        // 0x0E. Tested against 0 and 100 [inferred].
    u8 unknown0F[2];    // 0x0F..0x10
    u8 effectKind;      // 0x11. HP effect kind (datCalcSkillAmount). Tested against 0x10 and 8 [inferred].
    s16 power;          // 0x12. HP power (datCalcSkillAmount).
    u8 spEffectKind;    // 0x14. SP effect kind (datCalcSkillAmount).
    u8 unknown15;       // 0x15
    s16 spPower;        // 0x16. SP power (datCalcSkillAmount).
    u8 mode18;          // 0x18. Mode tested against 1, 2 and 3 [inferred].
    u8 field19;         // 0x19. Compared with 100 (0x64) [inferred].
    u8 unknown1A[0x0A]; // 0x1A..0x23
    u8 kind24;          // 0x24. Switch selector and compared with 3, 6, 0xD, 0xE.
    u8 critRate;        // 0x25. 0 means never critical, 0x64 means always; datCalcHitResult rolls against it.
    u8 field26;         // 0x26
    u8 unknown27;       // 0x27
} DatSkillEntry;

#endif
