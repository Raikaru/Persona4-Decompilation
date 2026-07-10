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
