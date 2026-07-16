/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003BCFA0)
/* Source unit: src/rw/rpusrdat_003bcfa0.c (1 function markers) */
#include "type.h"
#pragma optimization_level 3

typedef struct RpMaterial RpMaterial;
static u32 iGpffffb680;
extern s32 func_003bc9c0(void* object, char* name, s32 format, s32 numElements);

// FUN_003BCFA0
s32 func_003bcfa0(RpMaterial* material, char* name, s32 format, s32 numElements)
{
    return func_003bc9c0((u8*)material + iGpffffb680, name, format, numElements);
}
#pragma optimization_level 2
#endif /* P4_UNIT_003BCFA0 */
