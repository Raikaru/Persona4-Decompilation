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
