/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00109390)
/* Source unit: src/datPersona/datPersona_00109390.c (1 function markers) */
#include "type.h"

// FUN_00109390
u8 func_00109390(int persona)
{
    return *(u8*)(persona + 4);
}
#endif /* P4_UNIT_00109390 */

#if defined(P4_UNIT_00109400)
/* Source unit: src/datPersona/datPersona_00109400.c (1 function markers) */
#include "type.h"

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
} PersonaWork;

extern PersonaWork* func_0010a900(u16 pcId);

// FUN_00109400
u8 func_00109400(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);
    return persona->level;
}
#endif /* P4_UNIT_00109400 */

#if defined(P4_UNIT_00109430)
/* Source unit: src/datPersona/datPersona_00109430.c (1 function markers) */
#include "type.h"

// FUN_00109430
u32 func_00109430(int persona)
{
    return *(u32*)(persona + 8);
}
#endif /* P4_UNIT_00109430 */

#if defined(P4_UNIT_00109440)
/* Source unit: src/datPersona/datPersona_00109440.c (1 function markers) */
#include "type.h"

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
} PersonaWork;

extern u32 func_0010c750(PersonaWork* persona, u16 level);

// FUN_00109440
void func_00109440(PersonaWork* persona)
{
    func_0010c750(persona, (u16)(persona->level + 1));
}
#endif /* P4_UNIT_00109440 */

#if defined(P4_UNIT_001094D0)
/* Source unit: src/datPersona/datPersona_001094d0.c (1 function markers) */
#include "type.h"

// FUN_001094D0
u16* func_001094d0(int persona)
{
    return (u16*)(persona + 0xc);
}
#endif /* P4_UNIT_001094D0 */

#if defined(P4_UNIT_001094E0)
/* Source unit: src/datPersona/datPersona_001094e0.c (1 function markers) */
#include "type.h"

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
    u16 skills[8];
} PersonaWork;

extern PersonaWork* func_0010a900(u16 pcId);

// FUN_001094E0
u16* func_001094e0(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);

    return persona->skills;
}
#endif /* P4_UNIT_001094E0 */

#if defined(P4_UNIT_00109D80)
/* Source unit: src/datPersona/datPersona_00109d80.c (1 function markers) */
#include "type.h"

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
    u16 skills[8];
    u8 naturalStats[5];
    u8 bonusStats[5];
} PersonaWork;

extern PersonaWork* func_0010a900(u16 pcId);

// FUN_00109D80
void func_00109d80(u16 pcId, u16 statId, s8 amount)
{
    PersonaWork* persona = func_0010a900(pcId);

    persona->bonusStats[statId] += amount;
}
#endif /* P4_UNIT_00109D80 */

#if defined(P4_UNIT_0010C6F0)
/* Source unit: src/datPersona/datPersona_0010c6f0.c (1 function markers) */
#include "type.h"

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
} PersonaWork;

extern u32 func_0010c750(PersonaWork* persona, u16 level);

// FUN_0010C6F0
u8 func_0010c6f0(PersonaWork* persona)
{
    if (persona->level >= 99) {
        return 0;
    }
    return func_0010c750(persona, persona->level + 1) <= persona->nextExp;
}
#endif /* P4_UNIT_0010C6F0 */
