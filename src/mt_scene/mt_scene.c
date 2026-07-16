/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00145260)
/* Source unit: src/mt_scene/mt_scene_00145260.c (1 function markers) */
#include "type.h"

extern u8* PTR_DAT_00762ea0;

// FUN_00145260
u32 func_00145260(void)
{
    return *(u32*)(PTR_DAT_00762ea0 + 8);
}
#endif /* P4_UNIT_00145260 */

#if defined(P4_UNIT_00146E60)
/* Source unit: src/mt_scene/mt_scene_00146e60.c (1 function markers) */
#include "type.h"

extern u8* PTR_DAT_00762ea0;
extern s32 func_00147530(s32 resourceManager, u64 resourceId);
extern void func_00146a10(s32 resource, u64 position, u64 angles, s32 flags);

// FUN_00146E60
void func_00146e60(u64 resourceId, u64 position, u64 angles)
{
    s32 resource;

    if (*(s32*)(PTR_DAT_00762ea0 + 8) == 0)
    {
        resource = 0;
    }
    else
    {
        resource = func_00147530(*(s32*)(PTR_DAT_00762ea0 + 8), resourceId);
    }

    if (resource != 0)
    {
        (func_00146a10)(resource, position, angles, 0);
    }
}
#endif /* P4_UNIT_00146E60 */

#if defined(P4_UNIT_00146EE0)
/* Source unit: src/mt_scene/mt_scene_00146ee0.c (1 function markers) */
#include "type.h"

extern u8* PTR_DAT_00762ea0;
extern s32 func_00147530(s32 resourceManager, u64 resourceId);
extern void func_00146a10(s32 resource, s32 position, s32 angles, u64 flags);

// FUN_00146EE0
void func_00146ee0(u64 resourceId, u64 angles)
{
    s32 resource;

    if (*(s32*)(PTR_DAT_00762ea0 + 8) == 0)
    {
        resource = 0;
    }
    else
    {
        resource = func_00147530(*(s32*)(PTR_DAT_00762ea0 + 8), resourceId);
    }

    if (resource != 0)
    {
        (func_00146a10)(resource, 0, 0, angles);
    }
}
#endif /* P4_UNIT_00146EE0 */

#if defined(P4_UNIT_00268BD0)
/* Source unit: src/mt_scene/mt_scene_00268bd0.c (1 function markers) */
#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

// FUN_00268BD0
u32 func_00268bd0(Resrc* resource, s32 enabled)
{
    if (resource == NULL)
    {
        return 0;
    }

    if (enabled == 1)
    {
        resource->flags |= 8;
    }
    else
    {
        resource->flags &= ~8;
    }

    return 1;
}
#endif /* P4_UNIT_00268BD0 */

#if defined(P4_UNIT_00268C20)
/* Source unit: src/mt_scene/mt_scene_00268c20.c (1 function markers) */
#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

extern Resrc* func_00145270(u16 resTypeId);

// FUN_00268C20
u32 func_00268c20(u16 resTypeId, s32 enabled)
{
    Resrc* res;

    res = func_00145270(resTypeId);
    if (res == NULL)
    {
        return 0;
    }
    else if (res == NULL)
    {
        return 0;
    }
    else
    {
        if (enabled == 1)
        {
            res->flags |= 8;
        }
        else
        {
            res->flags &= ~8;
        }

        return 1;
    }
}
#endif /* P4_UNIT_00268C20 */

#if defined(P4_UNIT_00268E30)
/* Source unit: src/mt_scene/mt_scene_00268e30.c (1 function markers) */
#include "type.h"

u32 func_00268ce0(float* first, float* second, float* output, float* third);

// FUN_00268E30
u32 func_00268e30(float* first, float* second, float* third)
{
    float output[4];

    return func_00268ce0(first, second, output, third);
}
#endif /* P4_UNIT_00268E30 */

#if defined(P4_UNIT_00269BD0)
/* Source unit: src/mt_scene/mt_scene_00269bd0.c (1 function markers) */
#include "type.h"

// FUN_00269BD0
u32 func_00269bd0(void* resource, s32 enabled)
{
    u32 result;
    s32 address;

    address = (s32)resource;
    if (resource == NULL)
    {
        result = 0;
    }
    else
    {
        if (enabled == 1)
        {
            *(u32*)(address + 0x28) |= 2;
        }
        else
        {
            *(u32*)(address + 0x28) &= 0xfffffffd;
        }
        result = 1;
    }

    return result;
}
#endif /* P4_UNIT_00269BD0 */

#if defined(P4_UNIT_0026C740)
/* Source unit: src/mt_scene/mt_scene_0026c740.c (1 function markers) */
#include "type.h"

extern void func_0026c680(float* value);

// FUN_0026C740
void func_0026c740(s32 object)
{
    (func_0026c680)((float*)(object + 0x10));
}
#endif /* P4_UNIT_0026C740 */

#if defined(P4_UNIT_0026D400)
/* Source unit: src/mt_scene/mt_scene_0026d400.c (1 function markers) */
#include "type.h"

extern u32 D_00764580;

#pragma optimization_level 1
// FUN_0026D400
u8 func_0026d400(float* param_1)
{
    if (*(u16*)&D_00764580 == 0)
    {
        return 0;
    }

    param_1[0] = *(volatile float*)(uintptr_t)0x00881500;
    param_1[1] = *(volatile float*)(uintptr_t)0x00881504;
    return 1;
}
#pragma optimization_level 2
#endif /* P4_UNIT_0026D400 */

#if defined(P4_UNIT_0026D780)
/* Source unit: src/mt_scene/mt_scene_0026d780.c (1 function markers) */
#include "type.h"

extern u32 D_00764580;
extern u32 D_00764584;
extern u32 D_00764588;
extern u32 D_0076458C;
extern void func_004b1590();

// FUN_0026D780
void func_0026d780(s32 first, s32 second)
{
    if (second == 0)
    {
        *(u16*)&D_00764580 = 0;
    }
    else
    {
        *(u16*)&D_00764580 = 1;
        if (first == 0)
        {
            *(s16*)&D_00764584 = -1;
        }
        else
        {
            *(u16*)&D_00764584 = (s16)first;
        }
        *(u16*)&D_0076458C = second * 10;
        *(u16*)&D_00764588 = (*(u16*)&D_0076458C << 2) / 10;
        func_004b1590(first, (s16)second);
    }
}
#endif /* P4_UNIT_0026D780 */
