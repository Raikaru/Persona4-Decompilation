/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00105EE0)
/* Source unit: src/g_data/g_data_00105ee0.c (1 function markers) */
#include "type.h"

typedef struct DatGlobal {
    u8 padding[0x4130];
    s16 partyIds[1];
} DatGlobal;

extern DatGlobal D_00797560;

// FUN_00105EE0
s16 datGetPartyId(s32 idx)
{
    return D_00797560.partyIds[idx];
}
#endif /* P4_UNIT_00105EE0 */

#if defined(P4_UNIT_00106000)
/* Source unit: src/g_data/g_data_00106000.c (1 function markers) */
#include "type.h"

typedef struct DatGlobal {
    u8 padding[0x4130];
    s16 partyIds[1];
} DatGlobal;

extern DatGlobal D_00797560;

// FUN_00106000
void datSetPartyId(s32 idx, s16 pcId)
{
    D_00797560.partyIds[idx] = pcId;
}
#endif /* P4_UNIT_00106000 */

#if defined(P4_UNIT_00106330)
/* Source unit: src/g_data/g_data_00106330.c (1 function markers) */
#include "type.h"

typedef struct DatGlobal {
    u8 padding[0x3c6c];
    u32 flags[1];
} DatGlobal;

extern DatGlobal D_00797560;

// FUN_00106330
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (D_00797560.flags[idx] & (1 << mask)) != 0;
}
#endif /* P4_UNIT_00106330 */

#if defined(P4_UNIT_001090F0)
/* Source unit: src/g_data/g_data_001090f0.c (1 function markers) */
#include "type.h"

extern u8 D_00797560[];

// FUN_001090F0
void func_001090f0(void)
{
    *(u32*)D_00797560 = 0;
}
#endif /* P4_UNIT_001090F0 */
