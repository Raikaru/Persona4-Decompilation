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
