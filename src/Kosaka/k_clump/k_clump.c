/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_004578B0)
/* Source unit: src/Kosaka/k_clump/k_clump_004578b0.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_004578B0
s32 func_004578b0(const RpMaterial* material, const char* name)
{
    s32 i;
    s32 value;
    RpUserDataArray* userData;

    value = 0;
    for (i = 0; i < func_003bcfb0(material); i++)
    {
        userData = func_003bd000(material, i);
        if (func_004426e8(func_003bd040(userData), name) == 0 &&
            func_003bd050(userData) == rpINTUSERDATA)
        {
            value = func_003bd070(userData, 0);
            break;
        }
    }
    return value;
}
#endif /* P4_UNIT_004578B0 */

#if defined(P4_UNIT_00457C90)
/* Source unit: src/Kosaka/k_clump/k_clump_00457c90.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00457C90
u32 func_00457c90(void* clump, const char* name)
{
    struct
    {
        u32 found;
        char copiedName[72];
    } context;

    context.found = 0;
    func_00442830(context.copiedName, name);
    func_003bff30(clump, (KClumpCallback)func_00457b60, &context);
    return context.found;
}
#endif /* P4_UNIT_00457C90 */

#if defined(P4_UNIT_00457E00)
/* Source unit: src/Kosaka/k_clump/k_clump_00457e00.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00457E00
void* func_00457e00(void* object, u32* context)
{
    s32 resourceIndex;
    s32 materialIndex;
    s32 elementIndex;
    void* material;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                userData = (RpUserDataArray*)material;
                if (func_003bd050(userData) == rpINTUSERDATA &&
                    func_003bd070(userData, elementIndex) == (s32)context[0x11])
                {
                    context[0x10] = (u32)object;
                    return NULL;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_00457e00, context);
    return object;
}
#endif /* P4_UNIT_00457E00 */

#if defined(P4_UNIT_00458090)
/* Source unit: src/Kosaka/k_clump/k_clump_00458090.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00458090
void* func_00458090(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context[0x10]++;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_00458090, context);
    return object;
}
#endif /* P4_UNIT_00458090 */

#if defined(P4_UNIT_004582C0)
/* Source unit: src/Kosaka/k_clump/k_clump_004582c0.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_004582C0
void* func_004582c0(void* object, u32* context)
{
    s32 resourceIndex;
    s32 elementIndex;
    void* material;

    if (context[0x12] == 1)
    {
        return NULL;
    }
    for (resourceIndex = 0; resourceIndex < func_003bcf10(object); resourceIndex++)
    {
        material = func_003bcf60(object, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), (const char*)context) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context[0x10] == context[0x11])
                    {
                        context[0x13] = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context[0x14] = (u32)object;
                        context[0x12] = 1;
                        return NULL;
                    }
                    context[0x11]++;
                }
            }
        }
    }
    func_003e9af0(object, (KClumpCallback)func_004582c0, context);
    return object;
}
#endif /* P4_UNIT_004582C0 */

#if defined(P4_UNIT_00462E80)
/* Source unit: src/Kosaka/k_clump/k_clump_00462e80.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00462E80
u32 func_00462e80(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    return state[8] != 0;
}
#endif /* P4_UNIT_00462E80 */
#if defined(P4_UNIT_00457A90)
/* Source unit: src/Kosaka/k_clump/k_clump_00457a90.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00457A90
u32 func_00457a90(const RpMaterial* material, const char* name)
{
    s32 i;
    u32 result;
    RpUserDataArray* userData;

    result = 0;
    for (i = 0; i < func_003bcfb0(material); i++)
    {
        userData = func_003bd000(material, i);
        /* The retail function performs the accessor twice. */
        func_003bd040(userData);
        if (func_004426e8(func_003bd040(userData), name) == 0)
        {
            result = 1;
            break;
        }
    }
    return result;
}
#endif /* P4_UNIT_00457A90 */

#if defined(P4_UNIT_00457B60)
/* Source unit: src/Kosaka/k_clump/k_clump_00457b60.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

typedef struct KClumpResourceList
{
    u8 reserved[0x20];
    void** materials;
    u32 count;
} KClumpResourceList;

// FUN_00457B60
void* func_00457b60(void* geometry, void* data)
{
    KClumpResourceList* resourceList;
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 found;
    RpUserDataArray* userData;

    resourceList = *(KClumpResourceList**)((u8*)geometry + 0x18);
    for (resourceIndex = 0; resourceIndex < (s32)resourceList->count; resourceIndex++)
    {
        material = resourceList->materials[resourceIndex];
        found = 0;
        for (materialIndex = 0; materialIndex < func_003bcfb0((RpMaterial*)material); materialIndex++)
        {
            userData = func_003bd000((RpMaterial*)material, materialIndex);
            func_003bd040(userData);
            if (func_004426e8(func_003bd040(userData), (const char*)((const char**)data + 1)) == 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            *(u32*)data = 1;
            return NULL;
        }
    }
    return geometry;
}
#endif /* P4_UNIT_00457B60 */

#if defined(P4_UNIT_00457CE0)
/* Source unit: src/Kosaka/k_clump/k_clump_00457ce0.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00457CE0
u32 func_00457ce0(void* geometry, const char* name)
{
    s32 resourceIndex;
    void* material;
    s32 materialIndex;
    u32 result;
    RpUserDataArray* userData;

    for (resourceIndex = 0; resourceIndex < (s32)*(u32*)((u8*)geometry + 0x14); resourceIndex++)
    {
        material = *(void**)(*(u32*)((u8*)geometry + 0x10) + resourceIndex * 4);
        result = 0;
        for (materialIndex = 0; materialIndex < func_003bcfb0((RpMaterial*)material); materialIndex++)
        {
            userData = func_003bd000((RpMaterial*)material, materialIndex);
            func_003bd040(userData);
            if (func_004426e8(func_003bd040(userData), name) == 0)
            {
                result = 1;
                break;
            }
        }
        if (result == 1)
        {
            return 1;
        }
    }
    return 0;
}
#endif /* P4_UNIT_00457CE0 */

#if defined(P4_UNIT_00457F40)
/* Source unit: src/Kosaka/k_clump/k_clump_00457f40.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

// FUN_00457F40
void* func_00457f40(void* object, const char* name, s32 value)
{
    struct
    {
        char nameCopy[0x40];
        void* result;
        s32 inputValue;
    } context;
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
    void* material;

    geometry = *(void**)((u8*)object + 4);
    func_00442830(context.nameCopy, name);
    context.result = NULL;
    context.inputValue = value;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(geometry); resourceIndex++)
    {
        material = func_003bcf60(geometry, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA &&
                    func_003bd070((RpUserDataArray*)material, elementIndex) == context.inputValue)
                {
                    context.result = geometry;
                    return context.result;
                }
            }
        }
    }
    func_003e9af0(geometry, (KClumpCallback)func_00457e00, context.nameCopy);
    return context.result;
}
#endif /* P4_UNIT_00457F40 */

#if defined(P4_UNIT_004581A0)
/* Source unit: src/Kosaka/k_clump/k_clump_004581a0.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

typedef struct KClumpUserDataContext
{
    char name[0x40];
    u32 count;
} KClumpUserDataContext;

// FUN_004581A0
s32 func_004581a0(void* object, const char* name)
{
    KClumpUserDataContext context;
    s32 resourceIndex;
    s32 elementIndex;
    void* clump;
    void* material;

    clump = *(void**)((u8*)object + 4);
    func_00442830(context.name, name);
    context.count = 0;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(clump); resourceIndex++)
    {
        material = func_003bcf60(clump, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), context.name) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    context.count++;
                }
            }
        }
    }
    func_003e9af0(clump, (KClumpCallback)func_00458090, &context);
    return (s32)context.count;
}
#endif /* P4_UNIT_004581A0 */

#if defined(P4_UNIT_00458430)
/* Source unit: src/Kosaka/k_clump/k_clump_00458430.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

typedef struct
{
    f32 x;
    f32 y;
} RwV2d;

extern void func_0043f9c8(void* destination, s32 value, u32 size);

// FUN_00458430
void func_00458430(f32* result, void* object, const char* name, s32 index)
{
    struct
    {
        char nameCopy[0x40];
        s32 targetIndex;
        s32 currentIndex;
        s32 unused0;
        s32 resultValue;
        void* resultMaterial;
    } context;
    s32 resourceIndex;
    s32 elementIndex;
    void* geometry;
    void* material;

    geometry = *(void**)((u8*)object + 4);
    func_0043f9c8(&context, 0, 0x54);
    func_00442830(context.nameCopy, name);
    context.targetIndex = index;
    for (resourceIndex = 0; resourceIndex < func_003bcf10(geometry); resourceIndex++)
    {
        material = func_003bcf60(geometry, resourceIndex);
        if (func_004426e8(func_003bd040((RpUserDataArray*)material), context.nameCopy) == 0)
        {
            for (elementIndex = 0; elementIndex < func_003bd060(material); elementIndex++)
            {
                if (func_003bd050((RpUserDataArray*)material) == rpINTUSERDATA)
                {
                    if (context.targetIndex == context.currentIndex)
                    {
                        context.resultValue = func_003bd070((RpUserDataArray*)material, elementIndex);
                        context.resultMaterial = geometry;
                        *(RwV2d*)result = *(RwV2d*)&context.resultValue;
                        return;
                    }
                    context.currentIndex++;
                }
            }
        }
    }
    func_003e9af0(geometry, (KClumpCallback)func_004582c0, &context);
    *(RwV2d*)result = *(RwV2d*)&context.resultValue;
}
#endif /* P4_UNIT_00458430 */

#if defined(P4_UNIT_00462170)
/* Source unit: src/Kosaka/k_clump/k_clump_00462170.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
} RwSphere;

extern void* func_003bfae0(void* object);
extern s32 func_003e8200(void* camera, void* sphere);
extern void* D_008872E0[];
extern u32 D_00764068;
extern f32 D_00764b80;
extern void func_004601c0(void* center, f32 radius, void* color, u32 saveAndRestoreRenderState);

// FUN_00462170
void* func_00462170(void* item)
{
    RwSphere* sphere;

    if ((*(u8*)((u8*)item + 2) & 4) != 0)
    {
        goto process;
    }
    return item;
process:
    if (*(u32*)((u8*)item + 0x18) != 0)
    {
        sphere = func_003bfae0(item);
        if (func_003e8200(*(void**)D_008872E0, sphere) != 0)
        {
            (*(void (**)(void*))((u8*)item + 0x48))(item);
            if (D_00764068 == 1)
            {
                f32 debugValue;
                RwSphere* sphere2;

                debugValue = D_00764b80;
                sphere2 = func_003bfae0(item);
                func_004601c0(sphere2, sphere2->radius, &debugValue, 0);
            }
        }
    }
    return item;
}
#endif /* P4_UNIT_00462170 */

#if defined(P4_UNIT_004632F0)
/* Source unit: src/Kosaka/k_clump/k_clump_004632f0.c (1 function markers) */
#include "Kosaka/k_clump_internal.h"

extern s32 func_003b83f0(void* object);
extern s32 func_003b85b0(void* object);
extern void func_003b8520(void* object, u32 mode);
extern void func_003b83d0(void* object, void* data);
extern void func_00397390(void* data);

// FUN_004632F0
void* func_004632f0(void* object, void* data)
{
    s32 state;

    if (func_003b83f0(*(void**)((u8*)object + 0x18)) == 0)
    {
        goto fail;
    }
    state = func_003b85b0(object);
    if (state == 0)
    {
        goto normal;
    }
    if (state == 3)
    {
        goto normal;
    }
    switch (state)
    {
    case 1:
        goto normal;
    case 2:
        goto state2;
    default:
        goto default_state;
    }
state2:
    func_003b8520(object, 2);
    goto normal;
default_state:
    func_003b8520(object, 2);
    goto normal;
normal:
    func_003b83d0(object, data);
    goto done;
fail:
    func_00397390(data);
done:
    return object;
}
#endif /* P4_UNIT_004632F0 */
