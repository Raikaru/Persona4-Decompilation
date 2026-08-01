/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0027BE60)
/* Source unit: src/Yajima/y_misc_0027be60.c */
#include "type.h"

extern int func_00277840(void);

#pragma push

// FUN_0027BE60
u32 func_0027BE60(void)

{

  int iVar1;

  

  iVar1 = func_00277840();

  return *(u32 *)(iVar1 + 0x18);

}

#pragma pop
#endif /* P4_UNIT_0027BE60 */

#if defined(P4_UNIT_002B1100)
/* Source unit: src/Yajima/y_misc_002b1100.c */
#include "type.h"

typedef struct YVec3f { f32 x, y, z; } YVec3f;

#pragma push

// FUN_002B1100
void func_002B1100(void *param_1,u32 param_2,u32 param_3)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 1200.0f * (float)param_2;
  vector.z = 1200.0f * (float)param_3;
  *(YVec3f *)param_1 = vector;
}

#pragma pop
#endif /* P4_UNIT_002B1100 */

#if defined(P4_UNIT_002B11C0)
/* Source unit: src/Yajima/y_misc_002b11c0.c */
#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

#pragma push

// FUN_002B11C0
int func_002B11C0(RwV3d param_1)

{
  return (int)((param_1.x + 600.0f) / 1200.0f);
}

#pragma pop
#endif /* P4_UNIT_002B11C0 */

#if defined(P4_UNIT_002B1210)
/* Source unit: src/Yajima/y_misc_002b1210.c */
#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

#pragma push

// FUN_002B1210
int func_002B1210(RwV3d param_1)

{
  return (int)((param_1.z + 600.0f) / 1200.0f);
}

#pragma pop
#endif /* P4_UNIT_002B1210 */
