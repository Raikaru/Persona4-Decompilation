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
