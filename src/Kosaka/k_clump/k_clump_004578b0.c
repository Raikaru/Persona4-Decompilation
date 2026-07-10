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
