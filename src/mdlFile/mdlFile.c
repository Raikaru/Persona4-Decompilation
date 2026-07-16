/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001FC2C0)
/* Source unit: src/mdlFile/mdlFile_001fc2c0.c (1 function markers) */
#include "type.h"

#pragma alias DAT_00881440_abs DAT_00881440
#pragma alias DAT_00881444_abs DAT_00881444
extern u32 DAT_00881440_abs[];
extern u32 DAT_00881444_abs[];

#pragma schedule off
// FUN_001FC2C0
void func_001fc2c0(u32 first, u32 second)
{
    DAT_00881440_abs[0] = first;
    DAT_00881444_abs[0] = second;
}
#endif /* P4_UNIT_001FC2C0 */

#if defined(P4_UNIT_001FC2E0)
/* Source unit: src/mdlFile/mdlFile_001fc2e0.c (1 function markers) */
#include "type.h"

#pragma alias DAT_00881448_abs DAT_00881448
#pragma alias DAT_0088144c_abs DAT_0088144c
#pragma alias DAT_00881450_abs DAT_00881450
extern u32 DAT_00881448_abs[];
extern u32 DAT_0088144c_abs[];
extern u32 DAT_00881450_abs[];

#pragma schedule off
// FUN_001FC2E0
void func_001fc2e0(u32 first, u32 second, u32 third)
{
    DAT_00881448_abs[0] = first;
    DAT_0088144c_abs[0] = second;
    DAT_00881450_abs[0] = third;
}
#endif /* P4_UNIT_001FC2E0 */

#if defined(P4_UNIT_0047DE90)
/* Source unit: src/mdlFile/mdlFile_0047de90.c (1 function markers) */
#include "type.h"

// FUN_0047DE90
u32 func_0047de90(u32* resource)
{
    return *(u32*)*resource;
}
#endif /* P4_UNIT_0047DE90 */

#if defined(P4_UNIT_004866E0)
/* Source unit: src/mdlFile/mdlFile_004866e0.c (1 function markers) */
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

// FUN_004866E0
u_long128 func_004866e0(int object, u32 *output)
{
    u_long128 value = *(u_long128 *)(object + 0x40);
    *(u_long128 *)output = value;
    return value;
}
#endif /* P4_UNIT_004866E0 */

#if defined(P4_UNIT_004866F0)
/* Source unit: src/mdlFile/mdlFile_004866f0.c (1 function markers) */
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

// FUN_004866F0
u_long128 func_004866f0(int object, u32 *output)
{
    u_long128 value = *(u_long128 *)(object + 0x50);
    *(u_long128 *)output = value;
    return value;
}
#endif /* P4_UNIT_004866F0 */

#if defined(P4_UNIT_00486700)
/* Source unit: src/mdlFile/mdlFile_00486700.c (1 function markers) */
#include "type.h"

// FUN_00486700
u32 func_00486700(void* object)
{
    return *(u32*)((u8*)object + 0x64);
}
#endif /* P4_UNIT_00486700 */

#if defined(P4_UNIT_00489F40)
/* Source unit: src/mdlFile/mdlFile_00489f40.c (1 function markers) */
#include "type.h"

// FUN_00489F40
void func_00489f40(void* object, u32 value)
{
    *(u32*)((u8*)object + 4) = value;
}
#endif /* P4_UNIT_00489F40 */

#if defined(P4_UNIT_00498C50)
/* Source unit: src/mdlFile/mdlFile_00498c50.c (1 function markers) */
#include "type.h"

typedef int (*MdlCallback)(...);

typedef struct MdlStridedCallback24 {
    MdlCallback callback;
    u8 next[0x14];
} MdlStridedCallback24;

extern MdlStridedCallback24 D_00713e7c[];
extern MdlStridedCallback24 D_00713e80[];

// FUN_00498C50
void func_00498c50(int object)
{
    int count;
    int address;

    address = object;
    D_00713e7c[*(int *)(address + 0x2c)].callback();
    count = *(int *)(address + 0x28) + 1;
    *(int *)(address + 0x28) = count;
    if (count > 0)
    {
        D_00713e80[*(int *)(address + 0x2c)].callback(object);
    }
}
#endif /* P4_UNIT_00498C50 */

#if defined(P4_UNIT_0049A710)
/* Source unit: src/mdlFile/mdlFile_0049a710.c (1 function markers) */
#include "type.h"

typedef int (*MdlCallback)(...);

typedef struct MdlStridedCallback24 {
    MdlCallback callback;
    u8 next[0x14];
} MdlStridedCallback24;

extern MdlStridedCallback24 D_00713f1c[];
extern MdlStridedCallback24 D_00713f20[];

// FUN_0049A710
void func_0049a710(int object)
{
    int count;
    int address;

    address = object;
    D_00713f1c[*(int *)(address + 0x38)].callback();
    count = *(int *)(address + 0x34) + 1;
    *(int *)(address + 0x34) = count;
    if (count > 0)
    {
        D_00713f20[*(int *)(address + 0x38)].callback(object);
    }
}
#endif /* P4_UNIT_0049A710 */
