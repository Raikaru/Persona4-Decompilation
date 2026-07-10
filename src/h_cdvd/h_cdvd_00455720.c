#include "h_cdvd_internal.h"

// FUN_00455720
s32 func_00455720(void* unused, const char* path)
{
    char uppercasePath[256];
    char normalizedPath[256];
    char cachePath[256];
    s32 i;

    (void)unused;
    func_00454d20(path, uppercasePath);
    func_00455100(uppercasePath, normalizedPath);
    for (i = 0; i < 256; i++)
    {
        if (D_008c8780[i].isValid)
        {
            func_00455100(D_008c8780[i].path, cachePath);
            if (func_004426e8(cachePath, normalizedPath) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
